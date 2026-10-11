"""Stage and round-trip a full local MAX05 candidate; never publish or flash."""
import argparse
from datetime import datetime, timezone
from hashlib import sha256
import json
from pathlib import Path
from types import FunctionType
import tempfile

import pefile
import build_review_update as container
from build_maxmade_update import version_model
import release_payload

ROOT = release_payload.ROOT
USB = 'upgrade/Storage Card/System/MgrUSB.exe'
VERSION = container.VERSION_PATH
REVISION = '7.0.6.MAX05'
RUNTIME_SHA = 'a9f0bf2266932d5574abd67c0a6444a27ada6e80064d6ee334db93e14e6d7ec8'
RUNTIME_PRS = [*range(26, 39), 40]
RESEARCH_PRS = [39, *range(41, 47)]


def digest(raw):
    return sha256(raw).hexdigest()


def write_json(path, value):
    path.write_text(json.dumps(value, indent=2)+'\n', encoding='utf-8')


def tree(directory, expected):
    actual = {p.relative_to(directory).as_posix() for p in directory.rglob('*') if p.is_file()}
    if actual != set(expected):
        raise ValueError('Complete member inventory required; missing/extra files refused')
    for name, row in expected.items():
        release_payload.member(name)
        raw = (directory/name).read_bytes()
        if (len(raw), digest(raw)) != (row['bytes'], row['sha256']):
            raise ValueError(f'Member bytes changed: {name}')


def edits(before, after):
    if len(before) != len(after):
        raise ValueError('This candidate only permits equal-size guarded edits')
    result, at = [], 0
    while at < len(before):
        if before[at] == after[at]:
            at += 1
            continue
        start = at
        while at < len(before) and before[at] != after[at]:
            at += 1
        result.append(dict(offset=start, before=before[start:at].hex(), after=after[start:at].hex()))
    return result


def inputs(baseline, development):
    published = ROOT/'analysis/firmware/usb-catalog-recovery-members.json'
    published_proof = ROOT/'analysis/firmware/usb-catalog-recovery-development.json'
    raw = (development/'manifest.json').read_bytes()
    proof = (development/'evidence.json').read_bytes()
    if raw != published.read_bytes() or proof != published_proof.read_bytes():
        raise ValueError('Development manifest/evidence must match the reviewed PR-40 records')
    manifest = json.loads(raw)
    if digest(proof) != manifest['proof']['sha256']:
        raise ValueError('Development proof checksum changed')
    if manifest['recipe']['sha256'] != RUNTIME_SHA:
        raise ValueError('Only the completed runtime candidate is permitted; prototypes excluded')
    if digest(release_payload.PLAN.read_bytes()) != manifest['source_plan_sha256']:
        raise ValueError('MAX04 source plan changed')
    for name, pin in manifest['tools'].items():
        if digest((ROOT/'tools'/name).read_bytes()) != pin:
            raise ValueError(f'Frozen runtime source changed: {name}')
    max04 = release_payload.plan_at(release_payload.PLAN)
    original = {r['path']: dict(bytes=r['after_bytes'], sha256=r['after_sha256']) for r in max04['members']}
    candidate = {r['path']: dict(bytes=r['bytes'], sha256=r['sha256']) for r in manifest['members']}
    if len(original) != 1918 or set(original) != set(candidate):
        raise ValueError('All 1,918 MAX04 members must be retained')
    if [n for n in original if original[n] != candidate[n]] != [USB]:
        raise ValueError('The reviewed development payload must change only MgrUSB')
    tree(baseline, original)
    tree(development/'payload', candidate)
    if (baseline/VERSION).read_bytes() != b'7.0.6.MAX04' or candidate[USB]['sha256'] != RUNTIME_SHA:
        raise ValueError('Unexpected baseline version or runtime binary')
    return original, candidate, manifest


def stage(baseline, development, output):
    baseline, development, output = (p.resolve() for p in (baseline, development, output))
    if output.exists():
        raise FileExistsError('Use a fresh output; previous candidates are never overwritten')
    if not output.is_relative_to(ROOT/'build'):
        raise ValueError('Candidate output must be inside the ignored build directory')
    for source in (baseline, development):
        if output.is_relative_to(source) or source.is_relative_to(output):
            raise ValueError('Inputs and output must be separate directories')
    original, candidate, manifest = inputs(baseline, development)
    rows, changes = [], []
    for name in sorted(original):
        before = (baseline/name).read_bytes()
        after = REVISION.encode('ascii') if name == VERSION else (development/'payload'/name).read_bytes()
        rows.append(dict(path=name, before_bytes=len(before), before_sha256=digest(before),
                         after_bytes=len(after), after_sha256=digest(after)))
        if before != after:
            changes.append(dict(path=name, edits=edits(before, after)))
    if {r['path'] for r in changes} != {USB, VERSION}:
        raise ValueError('Only MgrUSB and displayed version may change from MAX04')
    plan = dict(format=1, revision=REVISION, previous_release='7.0.6.MAX04',
                baseline_lgu_sha256=manifest['previous_lgu_sha256'],
                max04_plan_sha256=manifest['source_plan_sha256'], runtime_prs=RUNTIME_PRS,
                research_only_prs=RESEARCH_PRS, members=rows, changes=changes)
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix='max05-plan-', dir=output.parent) as temporary:
        source = Path(temporary)/'edit-plan.json'
        write_json(source, plan)
        checked = release_payload.plan_at(source)
        reproduce = FunctionType(release_payload.reproduce.__code__,
                                 dict(release_payload.reproduce.__globals__, PLAN=source))
        reproduction = reproduce(checked, baseline, output)
        reproduction['payload_matches_published_release'] = False
        reproduction['payload_matches_reviewed_plan'] = True
        write_json(output/'reproduction.json', reproduction)
        (output/'edit-plan.json').write_bytes(source.read_bytes())
    expected = {r['path']: dict(bytes=r['after_bytes'], sha256=r['after_sha256']) for r in rows}
    tree(output/'payload', expected)
    return original, candidate, manifest, expected


def package(baseline, development, output, pc_tools):
    output = output.resolve()
    # Refuse unpinned tools before staging or starting a process.
    writer, extractor = (pc_tools.resolve()/name for name in ('dir2lgu.exe', 'lgu2dir.exe'))
    for tool, pin in ((writer, container.WRITER_HASH), (extractor, container.EXTRACTOR_HASH)):
        if digest(tool.read_bytes()) != pin or pefile.PE(str(tool)).FILE_HEADER.Machine != 0x14c:
            raise ValueError(f'Unpinned Windows PC container tool: {tool.name}')
    recognition = version_model(REVISION)
    recognition.append(dict(current='7.0.6.MAX04', offered=REVISION,
                            ordinary_update_offered=REVISION > '7.0.6.MAX04', native_installation_tested=False))
    if not all(r['ordinary_update_offered'] for r in recognition):
        raise ValueError('Candidate must sort after the known installed versions')
    original, candidate, development_manifest, expected = stage(baseline, development, output)
    runs = [container.run_pc_tool(writer, ['-p', 'm1', REVISION, output/'payload', output/'upgrade.lgu'],
                                  output/'dir2lgu.log')]
    key_raw = (ROOT/'src/container/lgu0.json').read_bytes()
    key = bytes.fromhex(json.loads(key_raw)['xor_hex'])
    if len(key) != 1024:
        raise ValueError('Invalid published XOR key')
    verify = FunctionType(container.verify_package.__code__,
                          dict(container.verify_package.__globals__, xor_key=lambda: key))
    verification = verify(output/'upgrade.lgu', expected, REVISION)
    runs.append(container.run_pc_tool(extractor, [output/'upgrade.lgu', output/'roundtrip'],
                                      output/'lgu2dir.log'))
    tree(output/'roundtrip', expected)
    tree(output/'payload', expected)
    tree(baseline, original)
    tree(development/'payload', candidate)
    for run in runs:
        run.pop('command', None)
    evidence = ('usb-catalog-recovery-members.json', 'usb-catalog-recovery-development.json',
                'usb-catalog-recovery-retained.json', 'usb-catalog-recovery-allocator.json')
    evidence_pins = {f'analysis/firmware/{n}': digest((ROOT/'analysis/firmware'/n).read_bytes()) for n in evidence}
    sources = ('tools/build_max05_candidate.py', 'tools/release_payload.py', 'tools/build_review_update.py',
               'tools/build_maxmade_update.py', 'tools/inspect_updater_zip.py', 'src/container/lgu0.json')
    result = dict(generated_utc=datetime.now(timezone.utc).isoformat(), revision=REVISION,
        candidate_kind='LOCAL FULL RELEASE CANDIDATE', published=False, flashed=False,
        installation_tested=False, hardware_tested=False, native_executed=False,
        recommended_public_update=False, previous_release='7.0.6.MAX04',
        previous_lgu_sha256=development_manifest['previous_lgu_sha256'],
        runtime_prs=RUNTIME_PRS, research_only_prs=RESEARCH_PRS, prototype_helpers_in_lgu=False,
        output_members=1918, changed_from_max04=[USB, VERSION], unchanged_from_max04=1916,
        missing_members=[], added_members=[], os_boot_mcu_navigation_settings_unchanged_from_max04=True,
        edit_plan_sha256=digest((output/'edit-plan.json').read_bytes()),
        source_pins={n: digest((ROOT/n).read_bytes()) for n in sources}, evidence_pins=evidence_pins,
        retained_evidence=dict(cumulative_cases=development_manifest['cases'],
                               reused_by_exact_binary_and_source_hashes=True, rerun_during_packaging=False),
        version_recognition_model=recognition, header_and_displayed_version_match=True,
        writer=runs[0], extractor=runs[1], verification=verification, pc_extractor_matches=1918,
        limitations=['Container/member checks do not prove device installation, runtime or rollback',
                     'Existing boot/attach/shuffle/reset overlap remains unresolved in the runtime binary',
                     'Native allocation synchronization, memory pressure and loader/unwind remain untested',
                     'Full package retains original OS/boot/MCU update files and can replace settings',
                     'Only original MediaNav with the supported conversion; not factory Evolution',
                     'Static copy/stack savings are not measured device performance gains'])
    write_json(output/'build-manifest.json', result)
    (output/'SHA256SUMS.txt').write_text(f"{verification['lgu_sha256']}  upgrade.lgu\n", encoding='ascii')
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', type=Path, required=True, help='Complete verified MAX04 payload')
    parser.add_argument('--development', type=Path, required=True, help='Reviewed complete PR-40 output')
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--pc-tools', type=Path, help='Pinned Windows PC packer/extractor directory')
    parser.add_argument('--stage-only', action='store_true', help='Portable payload check; no LGU tools run')
    args = parser.parse_args()
    if args.stage_only:
        _, _, _, expected = stage(args.baseline, args.development, args.out)
        print(json.dumps(dict(revision=REVISION, members=len(expected),
                              changed_from_max04=[USB, VERSION], lgu_built=False), indent=2))
    else:
        if args.pc_tools is None:
            parser.error('--pc-tools is required to package the LGU')
        result = package(args.baseline, args.development, args.out, args.pc_tools)
        print(json.dumps(dict(revision=result['revision'], members=result['output_members'],
                              changed_from_max04=result['changed_from_max04'],
                              lgu_sha256=result['verification']['lgu_sha256'],
                              lgu_bytes=result['verification']['bytes'], installation_tested=False), indent=2))
