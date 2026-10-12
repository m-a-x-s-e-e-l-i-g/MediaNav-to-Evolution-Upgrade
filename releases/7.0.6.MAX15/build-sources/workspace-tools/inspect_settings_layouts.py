"""Recover Settings constructor geometry using explicit offline call fixtures."""
import json
from types import FunctionType
from inspect_av_layouts import LayoutVM, trace as av_trace, ROOT, SYSTEM, STOP
from verify_ui_english import strings

ENTRIES = {
    0xae4dc: 'Pairing code keyboard',
    0xb2238: 'Remote engine start', 0xb4628: 'Departure time',
    0xb69a0: 'Audio settings', 0xb87e0: 'Bluetooth settings',
    0xbabc8: 'Display settings', 0xbe2ec: 'Factory reset',
    0xbfab4: 'Sound volumes', 0xc2ac4: 'Language',
    0xc3f7c: 'Open source licenses', 0xc49ec: 'Balance and fader',
    0xc6988: 'System settings', 0xc8cd8: 'Units',
    0xca600: 'System version', 0xcbe48: 'Time settings',
    0xce680: 'Paired Bluetooth devices',
}


class SettingsVM(LayoutVM):
    def __init__(self, *args):
        super().__init__(*args)
        self.language = strings(SYSTEM / 'data/LangDllEng.dll')

    def read(self, at, size=4):
        # Factory-reset constructor scans a localized UTF-16 warning string.
        # Materialize only the language fixture already used by the AV tracer.
        if 0x50000000 <= at < 0x51000000:
            ident, offset = divmod(at - 0x50000000, 0x400)
            encoded = (self.language.get(ident, '') + '\0').encode('utf-16-le')
            assert offset + size <= 0x400
            return int.from_bytes(encoded[offset:offset + size].ljust(size, b'\0'), 'little')
        return super().read(at, size)

    def run(self, start, stops, **kwargs):
        virtual = self.hooks[0]
        def external_virtual(m):
            # Explicit factory-reset text redraw, not an image constructor.
            if m.pc in (0xbe808, 0xbe8c4, 0xbe980, 0xbe9fc):
                assert m.reg[6] == 0
                return 0
            return virtual(m)
        self.hooks[0] = external_virtual
        # Display's final controls belong to an inactive conditional branch;
        # its M1 constructor returns before that branch's snapshot boundary.
        return super().run(start, set(stops) | {STOP}, **kwargs)


trace = FunctionType(av_trace.__code__, dict(av_trace.__globals__, LayoutVM=SettingsVM),
                     av_trace.__name__, av_trace.__defaults__)


def layouts(raw, ui=1):
    cases = []
    for entry, name in ENTRIES.items():
        case = trace(entry, 'setting', raw, ui)
        case['name'] = name
        cases.append(case)
    return dict(scenarios=cases, failures=[], native_execution=False,
                limits=['Explicit external-call and language fixtures',
                        'Later runtime visibility, dynamic lists and native font metrics are untested'])


if __name__ == '__main__':
    raw = (ROOT / 'sources/MediaNav-usb-seek-timing/build/maxmade-7.0.6.MAX11-local-01/payload/'
           'upgrade/Storage Card/System/AppMain.exe').read_bytes()
    result = layouts(raw)
    out = ROOT / 'build/settings-nav-design/layouts.json'
    out.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    print([(c['name'], len(c['controls'])) for c in result['scenarios']])
