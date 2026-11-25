"""Pack the complete issue #74 system and compare both extraction paths."""
import argparse
import json
from pathlib import Path

import pefile

import build_review_update as container
from build_max35 import BASE, BASE_SHA, REVISION, ROOT
from package_max16 import tree, write
from patch_issue74 import PATCHES, patch
from verify_issue74 import verify


def package(stage):
    baseline = BASE / 'payload'
    assert container.sha((BASE / 'upgrade.lgu').read_bytes()) == BASE_SHA
    before = {r['path']: r['after'] for r in json.loads((BASE / 'member-plan.json').read_bytes())['members']}
    plan = json.loads((stage / 'member-plan.json').read_bytes())
    after = {r['path']: r['after'] for r in plan['members']}
    system = 'upgrade/Storage Card/System'
    expected_changed = {
        'upgrade/Storage Card/Recovery.exe', 'upgrade/Storage Card/InstallResume.exe',
        *(f'{system}/{name}' for name in (
            'UpgradeManager.exe', 'CmnDll.dll', 'Version_Info.txt', 'MicomManager.exe', 'Blue.exe'
        )),
    }
    assert len(after) == 1921 and before.keys() == after.keys()
    assert {path for path in after if before[path] != after[path]} == expected_changed
    tree(baseline, before)
    tree(stage / 'payload', after)
    verify(baseline / system)
    for mode, (name, _, _) in PATCHES.items():
        assert (stage / 'payload' / system / name).read_bytes() == patch(
            (baseline / system / name).read_bytes(), mode
        )
    for path in expected_changed - {f'{system}/Version_Info.txt'}:
        image = pefile.PE(str(stage / 'payload' / path))
        assert image.FILE_HEADER.Machine == 0x166 and image.OPTIONAL_HEADER.Subsystem == 9
        assert image.verify_checksum(), path
    assert (stage / 'payload' / system / 'Version_Info.txt').read_bytes() == REVISION.encode()
    writer, extractor = (ROOT / 'tools/vendor/lgu-favremod' / name for name in ('dir2lgu.exe', 'lgu2dir.exe'))
    assert container.sha(writer.read_bytes()) == container.WRITER_HASH
    assert container.sha(extractor.read_bytes()) == container.EXTRACTOR_HASH
    lgu = stage / 'upgrade.lgu'
    assert not lgu.exists()
    container.run_pc_tool(writer, ['-p', 'm1', REVISION, stage / 'payload', lgu], stage / 'dir2lgu.log')
    container.run_pc_tool(extractor, [lgu, stage / 'roundtrip'], stage / 'lgu2dir.log')
    tree(stage / 'roundtrip', after)
    key = ROOT / 'sources/MediaNav-usb-seek-timing/src/container/lgu0.json'
    container.xor_key = lambda: bytes.fromhex(json.loads(key.read_bytes())['xor_hex'])
    result = container.verify_package(lgu, after, REVISION)
    assert len(result.pop('members')) == len(after)
    summary = dict(
        passed=True, revision=REVISION, baseline_revision='7.0.6.MAX33',
        baseline_lgu_sha256=BASE_SHA, members=len(after), exact_previous_members=len(after)-len(expected_changed),
        changed_members=sorted(expected_changed), missing_members=[], added_members=[],
        native_extraction_verified=True, issue74_mips_verified=True, car_tested=False, **result
    )
    write(stage / 'package-verification.json', summary)
    print(json.dumps(summary, indent=2), flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--stage', type=Path, required=True)
    package(parser.parse_args().stage.resolve())
