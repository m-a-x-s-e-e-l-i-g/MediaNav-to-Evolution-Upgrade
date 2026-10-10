"""Complete cumulative development, with mapping checks and AppMain relocations."""
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path
from patch_shared_mapping_checks import patch
from verify_shared_mapping_checks import verify, structure, relocation_contracts
from verify_media_responsiveness import verify_touch, verify_performance
from verify_appmain_label_scan import verify as verify_arabic
from build_bt_eight_test import verify as verify_pairing

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / 'build/usb-save-feedback-development-01'
OUT = ROOT / 'build/shared-mapping-development-01'
RELEASE = ROOT / 'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
PROOF = ROOT / 'analysis/firmware/shared-mapping-development.json'
APP = 'upgrade/Storage Card/System/AppMain.exe'
BLUE = 'upgrade/Storage Card/System/Blue.exe'
USB = 'upgrade/Storage Card/System/MgrUSB.exe'


def sha(raw): return hashlib.sha256(raw).hexdigest()


def main():
    assert not OUT.exists(), 'Previous development builds are never overwritten'
    previous_bytes = (BASE / 'manifest.json').read_bytes()
    previous = json.loads(previous_bytes)
    for name, digest in previous['tools'].items():
        assert sha((ROOT / 'tools' / name).read_bytes()) == digest
    assert sha((ROOT / previous['proof']['path']).read_bytes()) == previous['proof']['sha256']
    state_path = ROOT / 'analysis/firmware/usb-save-notification-state-audit.json'
    state_bytes = state_path.read_bytes(); state = json.loads(state_bytes)
    assert sha((ROOT / 'tools/audit_usb_save_notification_state.py').read_bytes()) == state['tool_sha256']
    released_manifest = json.loads((RELEASE / 'build-manifest.json').read_bytes())
    released = {r['path']:r for r in released_manifest['verification']['members']}
    lgu_sha = sha((RELEASE / 'upgrade.lgu').read_bytes())
    assert lgu_sha == released_manifest['verification']['lgu_sha256']
    before = {}
    for row in previous['members']:
        name = row['path']; assert name.startswith('upgrade/') and '..' not in Path(name).parts
        raw = (BASE / 'payload' / name).read_bytes()
        assert len(raw) == row['bytes'] and sha(raw) == row['sha256']
        before[name] = raw
    assert len(before) == 1918 and set(before) == set(released)
    assert sha(before[USB]) == state['output_sha256']
    after = before.copy(); after[APP], recipe = patch(before[APP])
    for name, raw in after.items():
        target = OUT / 'payload' / name
        target.parent.mkdir(parents=True, exist_ok=True); target.write_bytes(raw)
    readback = {p.relative_to(OUT / 'payload').as_posix():p.read_bytes()
                for p in (OUT / 'payload').rglob('*') if p.is_file()}
    assert readback == after
    print('All 1,918 files read back; testing mapping failures and alternate bases', flush=True)
    checks = dict(initializer=verify(before[APP], readback[APP]),
                  structure=structure(before[APP], readback[APP], recipe),
                  relocation=relocation_contracts(readback[APP]))
    print('Mapping and relocation checks passed; testing retained Bluetooth/UI behavior', flush=True)
    pairing = verify_pairing(readback[BLUE], readback[APP])
    old_app = (ROOT / 'build/updater-copy-safety-development-02/payload' / APP).read_bytes()
    original = (ROOT / 'extracted/705md' / APP).read_bytes()
    retained = dict(pairing=pairing, touch=verify_touch(old_app, readback[APP]),
                    hebrew=verify_performance(old_app, readback[APP], exhaustive=False),
                    arabic=verify_arabic(original, readback[APP], exhaustive=False))
    new_cases = checks['initializer']['cases'] + checks['structure']['cases'] + checks['relocation']['execution_cases']
    assert new_cases == 221 and checks['relocation']['instruction_cases'] == 1872
    # USB is exactly identical, so its full hash-pinned proofs remain applicable.
    # Do not report the earlier 72,497 cases as rerun in this build.
    unchanged_proofs = dict(usb_sha256=sha(readback[USB]),
        previous_proof=previous['proof'], previous_main_cases=previous['new_cases'] + previous['retained_cases'],
        additional_state_proof=dict(path=str(state_path.relative_to(ROOT)), sha256=sha(state_bytes), cases=state['cases']),
        unchanged_usb_proofs_rerun=False)
    proof = dict(recipe=recipe, checks=checks, retained_readback_checks=retained,
                 unchanged_usb_evidence=unchanged_proofs, native_executed=False, hardware_tested=False)
    PROOF.write_text(json.dumps(proof, indent=2) + '\n', encoding='utf-8')
    changed = [p for p in before if before[p] != readback[p]]; assert changed == [APP]
    modified = [p for p in readback if sha(readback[p]) != released[p]['sha256']]
    assert len(modified) == 6
    result = dict(generated_utc=datetime.now(timezone.utc).isoformat(),
        kind='Full cumulative development; not an installable update or release',
        previous_release='7.0.6.MAX03', previous_lgu_sha256=lgu_sha,
        carried_forward_manifest_sha256=sha(previous_bytes), previous_development=BASE.name,
        previous_members=1918, output_members=1918, missing_members=[], added_members=[],
        changed_from_development=changed, unchanged_from_development=1917,
        modified_from_published_release=modified, unchanged_from_published_release=1912,
        recipe=recipe, readback_checks=checks, retained_readback_checks=retained,
        new_behavior_cases=new_cases, new_relocation_instruction_checks=1872,
        retained_pairing_cases=sum(len(v) for v in pairing.values()),
        unchanged_usb_evidence=unchanged_proofs,
        proof=dict(path=str(PROOF.relative_to(ROOT)), sha256=sha(PROOF.read_bytes())),
        tools={n:sha((ROOT/'tools'/n).read_bytes()) for n in
            ('patch_shared_mapping_checks.py','verify_shared_mapping_checks.py','build_shared_mapping_development.py')},
        native_executed=False, hardware_tested=False, installation_ready=False,
        release_built=False, version_bumped=False, native_loader_tested=False,
        concurrency_fixed=False, end_to_end_startup_recovery_fixed=False,
        members=[dict(path=p, bytes=len(readback[p]), sha256=sha(readback[p]),
            previous_release_sha256=released[p]['sha256'], previous_development_sha256=sha(before[p]))
            for p in sorted(readback)])
    (OUT/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (OUT/'README.md').write_text(
        '# Shared-mapping checks and AppMain loading development\n\n'
        'Full cumulative payload with all 1,918 previous files and improvements. '
        'Only AppMain changes. USB status and DAB EPG view failures now take the existing '
        'warning/cleanup path. Relocation metadata is rebuilt for earlier Bluetooth and UI edits, '
        'preserving their preferred-address instructions.\n\n'
        '221 new behavior/structure cases and 1,872 relocation instruction checks pass, '
        'along with retained Bluetooth/UI checks. The unchanged MgrUSB executable retains '
        'its exact hash-pinned 72,497-case proof and nine state cases; these were not rerun.\n\n'
        'No LGU, version bump or release. Native CE loading, unit behavior and installation '
        'remain unverified. The outer initializer still ignores failures; full startup recovery '
        'and coherent cross-thread status snapshots remain separate work. '
        'See analysis/shared-mapping-development.md and manifest.json.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes()) == lgu_sha
    assert all((BASE/'payload'/p).read_bytes() == b for p,b in before.items())
    print(json.dumps(dict(output=str(OUT), members=1918, app_sha256=sha(readback[APP]),
        new_behavior_cases=new_cases, relocation_instruction_checks=1872,
        retained_pairing_cases=result['retained_pairing_cases'],
        retained_touch_cases=retained['touch']['cases'], retained_hebrew_cases=retained['hebrew']['mixed_cases'],
        retained_arabic_cases=retained['arabic']['multi_unit_cases'], release_built=False),indent=2),flush=True)


if __name__ == '__main__': main()
