"""Bind MAX07 device feedback to current PE bytes and fixture coverage limits.

Read-only firmware inspection. Writes investigation evidence, never an EXE/LGU.
Class identity comes from constructor/vtable/initializer instructions together;
the adjacent class-name string alone is not sufficient evidence.
"""
import hashlib
import json
import struct
from datetime import datetime, timezone
from pathlib import Path

import pefile

ROOT = Path(__file__).resolve().parents[1]
REPO = ROOT / 'sources/MediaNav-usb-seek-timing'
SYSTEM = Path('upgrade/Storage Card/System')
PATHS = {
    '7.0.5MD': ROOT / 'extracted/705md',
    'MAX05': REPO / 'build/maxmade-7.0.6.MAX05-local/payload',
    'MAX06': REPO / 'build/maxmade-7.0.6.MAX06-artwork-text-local-01/payload',
    'MAX07': REPO / 'build/maxmade-7.0.6.MAX07-local-01/roundtrip',
}
PINS = {
    ('MAX07', 'AppMain.exe'): '28290d357badd7b8c0765d4bd5645946eff81a37a8cec2979cb031f01f97dad7',
    ('MAX07', 'Blue.exe'): '8a0d0273ad65cd3e3f0eea55821bd1ab4456740f7026040b5e354cfd38a3b091',
}


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def audit():
    modules, images = {}, {}
    for revision, payload in PATHS.items():
        for name in ('AppMain.exe', 'Blue.exe'):
            raw = (payload / SYSTEM / name).read_bytes()
            pin = PINS.get((revision, name))
            if pin:
                assert sha(raw) == pin
            pe = pefile.PE(data=raw)
            assert pe.OPTIONAL_HEADER.ImageBase == 0x10000
            images[revision, name] = pe
            modules[revision + '/' + name] = dict(path=str(payload / SYSTEM / name), sha256=sha(raw))
    app = images['MAX07', 'AppMain.exe']

    def read(pe, at, size):
        data = pe.get_data(at - 0x10000, size)
        assert len(data) == size
        return data

    def word(pe, at):
        return struct.unpack('<I', read(pe, at, 4))[0]

    # Constructor stores 0x150c20 as its vtable. That table's initializer
    # identifies CBTMainDlg, whereas the following string describes the next
    # class. The previously alleged Options binding is explicitly ruled out.
    assert word(app, 0x3af74) == 0x3c040015
    assert word(app, 0x3af78) == 0x24880c20
    assert word(app, 0x3af84) == 0xae280000
    assert word(app, 0x150c40) == 0x3b8e8
    assert word(app, 0x3b928) == 0x3c090015
    assert word(app, 0x3b930) == 0x25340b68
    assert read(app, 0x150b68, 24).split(b'\0')[0] == b'CBTMainDlg::initControls'
    assert read(app, 0x150c8c, 27).split(b'\0')[0] == b'CBTOptionDlg::initControls'
    assert word(app, 0x150c44) == 0x235000
    assert word(app, 0x150c5c) == 0x3c7e8
    assert word(app, 0x3c820) == 0x8d248270  # LW a0,-0x7d90(t1)
    high, low = word(app, 0x3c81c), word(app, 0x3c824)
    callback = (((high & 0xffff) << 16) + struct.unpack('<h', struct.pack('<H', low & 0xffff))[0]) & 0xffffffff
    assert callback == 0x23a000
    assert word(app, 0x3c918) == 0x3c080019
    assert word(app, 0x3c924) == 0x8d048270
    class_binding = dict(constructor='0x3af58', vtable='0x150c20',
                         initializer='0x3b8e8', initializer_name='CBTMainDlg::initControls',
                         draw_slot='0x150c44', draw_target='0x235000',
                         window_creator='0x3c7e8', callback=hex(callback),
                         dialog_global='0x188270', options_misbinding_hypothesis='ruled_out')

    # Verify API identities against the current import table and shipped ROM.
    core = pefile.PE(str(ROOT / 'extracted/705md-rom/fs/Windows/coredll.dll'))
    exports = {s.ordinal: s.name.decode('ascii') for s in core.DIRECTORY_ENTRY_EXPORT.symbols if s.name}
    expected = {0x1850dc: 'GetStockObject', 0x1850f0: 'FillRect', 0x185240: 'SetTextColor',
                0x185284: 'SetBkMode', 0x18509c: 'DrawTextW'}
    imports = {s.address: (d.dll, s.ordinal) for d in app.DIRECTORY_ENTRY_IMPORT for s in d.imports}
    api_bindings = []
    for at, name in expected.items():
        dll, ordinal = imports[at]
        assert dll.lower() == b'coredll.dll' and exports[ordinal] == name
        api_bindings.append(dict(iat=hex(at), ordinal=ordinal, function=name))

    spans = {
        'Blue.exe': [(0x1d3c4, 0x1d47c, 'native current-track request'),
                     (0x1eb50, 0x1eca8, 'native metadata publication'),
                     (0x1fa44, 0x1ff40, 'native metadata handlers'),
                     (0x20c68, 0x20ec4, 'application metadata dispatch'),
                     (0x53728, 0x5382c, 'request and confirmation factory')],
        'AppMain.exe': [(0x1137d0, 0x113920, 'shared UTF8 metadata reader'),
                        (0x3c2e0, 0x3c544, 'player metadata controls'),
                        (0x3c7e8, 0x3c934, 'player window creation and thunk')],
    }
    comparisons = []
    for name, ranges in spans.items():
        for start, end, role in ranges:
            versions = {r: read(images[r, name], start, end - start) for r in PATHS}
            comparisons.append(dict(module=name, start=hex(start), end=hex(end), role=role,
                                    sha256={r: sha(v) for r, v in versions.items()},
                                    changed_from_MAX05={r: sum(a != b for a, b in zip(versions['MAX05'], versions[r]))
                                                       for r in ('MAX06', 'MAX07')},
                                    changed_from_MD={r: sum(a != b for a, b in zip(versions['7.0.5MD'], versions[r]))
                                                     for r in ('MAX05', 'MAX06', 'MAX07')}))
    report = dict(generated_utc=datetime.now(timezone.utc).isoformat(), modules=modules,
                  user_feedback=dict(installed_revision='7.0.6.MAX07', installation_user_reported=True,
                                     buttons='looks good on the car', titles='always No title, including skips, other Android apps and reconnect',
                                     artwork='whole expected area blank, no placeholder or cover',
                                     stuttering='gone so far; longer playback not yet established',
                                     prior_title_frequency='7.0.5MD: sporadic failure, approximately once in 100'),
                  player_binding=class_binding, placeholder_imports=api_bindings,
                  native_path_comparisons=comparisons,
                  test_limits=['Artwork fixture supplies dialog, window/DC state, background/child rendering and generic message dispatch',
                               'Title receiver fixture replaces native publication at 0x1eb50; fixture field success is not shared-memory/UI success',
                               'MAX07 poll fixture supplies source activity at 0x274800 instead of following its live native predicate',
                               'No phone traffic, installed PE byte readback, actual dialog state or shared metadata snapshot is available'],
                  root_cause_confirmed=False, firmware_changed=False, successor_built=False,
                  next_evidence=['Use user-confirmed 7.0.5MD as the mostly working title reference while preserving complete MAX07 for any successor',
                                 'Compare real native source/request/response/publication/GUI state against the newly added ownership filters',
                                 'Verify actual player creation/draw/DC/popup/copy state; missing placeholder cannot be explained by missing phone cover support alone'])
    out = ROOT / 'analysis/firmware/max07-device-regression-audit.json'
    out.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    return dict(output=str(out), player_binding=class_binding,
                comparisons=[dict(module=r['module'], role=r['role'], changed_from_MAX05=r['changed_from_MAX05']) for r in comparisons],
                root_cause_confirmed=False, firmware_changed=False)


if __name__ == '__main__':
    print(json.dumps(audit(), indent=2))
