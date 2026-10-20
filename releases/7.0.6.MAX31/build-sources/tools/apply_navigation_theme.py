"""Apply the authored Nav resources to a compatible installed ZIP backup.

Writes a separate full archive. Checks every skin script/style/sprite declaration
and every touched source asset before writing anything. Never changes the input.
"""
import argparse
import json
import zipfile
from pathlib import Path
from build_navigation_reference_theme import sha, write_archive


def apply(installed, development, output):
    manifest = json.loads((development / 'manifest.json').read_text(encoding='utf-8'))
    if output.exists() or output.resolve() == installed.resolve():
        raise ValueError('Use a separate fresh output path')
    with zipfile.ZipFile(installed) as archive:
        if archive.testzip() is not None:
            raise ValueError('Corrupt installed archive')
        names = archive.namelist()
        if len({n.casefold() for n in names}) != len(names):
            raise ValueError('Duplicate member names')
        missing = [name for name in manifest['dependencies'] if name not in names]
        mismatches = [name for name, expected in manifest['dependencies'].items()
                      if name in names and sha(archive.read(name)) != expected]
        extra = [name for name in names if name.startswith('ui_lg_renault/')
                 and name.endswith(('.ui', '.css', '.lua', '.spr'))
                 and name not in manifest['dependencies']]
        if missing or mismatches or extra:
            raise ValueError(json.dumps(dict(message='Installed skin contracts differ; adaptation required',
                                           missing=missing, changed=mismatches, added_contracts=extra), indent=2))
    edits = {}
    for contract in manifest['changes']:
        raw = (development / 'overlay' / contract['path']).read_bytes()
        if sha(raw) != contract['after']:
            raise ValueError(f'Authored overlay changed: {contract["path"]}')
        edits[contract['path']] = raw
    output.parent.mkdir(parents=True, exist_ok=True)
    write_archive(installed, output, edits)
    return dict(complete_archive=True, source_sha256=sha(installed.read_bytes()),
                output_sha256=sha(output.read_bytes()), changed_members=len(edits),
                untouched_members_exact=True, installed_on_device=False)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--installed', type=Path, required=True)
    parser.add_argument('--development', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    print(json.dumps(apply(args.installed, args.development, args.out), indent=2))
