"""Preserve static AppMain startup, launch gates, diagnostic codes and resource catalog."""
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
APP = "bd9r2a@_4G2g=J2tq7X@app"
MID = "er10q4c$=4G2g-H2tq9X@mid"
HASHES = {
    "AppMain.exe": "6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8",
    "Blue.exe": "5e659f513327c84964a929ea9b9e3192384b3031fa6e6ffb6ad76b02af1b7c7b",
    "MgrIpod.exe": "2b4665529cfcc7ec696f53ff3ac6fb8f14fd63412722130a912d369ce68009f0",
    "MgrUSB.exe": "bb435bc428664845a21ffe7bce7a813db06b7e7f92408d297dbbeade94507cd2",
    "MgrDAB.exe": "375e9ff4da532c5e4090e3beaad28c894772bc1a6fb6f5174fb1afee1bde4e27",
    "MicomManager.exe": "c56e8e08600cd69a656ec487779d3dbb0cea672ae2c5cb2da685b9217e6f8824",
}
FUNCTIONS = {
    "AppMain.exe": [0x1407f8, 0x140724, 0x134948, 0x13487c, 0x13120c, 0x130e50,
        0x13107c, 0x13d28, 0xd9114, 0xd5c98, 0xd5dcc, 0xd5eec, 0xd602c, 0xd6270,
        0x13766c, 0x1fb58, 0x1fbfc, 0x13dcac, 0x13da74, 0x13dbbc, 0x13dde0,
        0x13e020, 0x1ff54, 0x1ffbc, 0x27710, 0x28218, 0x28f30, 0x26adc, 0x270f8,
        0x27154, 0x274f8, 0x2815c, 0x28d20, 0x1f1dc, 0xca600, 0xcab14,
        0xcacbc, 0x135454, 0x136494, 0x13d488, 0x135548, 0x28e14],
    "Blue.exe": [0x34118], "MgrIpod.exe": [0x181c8],
    "MgrUSB.exe": [0x24480], "MgrDAB.exe": [0x39330],
    "MicomManager.exe": [0x1f444],
}


def utf16_units(value):
    value = value.split("\0", 1)[0]
    raw = value.encode("utf-16le")
    return list(struct.unpack(f"<{len(raw)//2}H", raw))


def prefix_gate(command, expected):
    if command is None:
        return False
    return utf16_units(command)[:len(utf16_units(expected))] == utf16_units(expected)


def usb_gate(command):
    # wcstok delimiter is a literal space, not generic whitespace.
    parts = [p for p in command.split("\0", 1)[0].split(" ") if p]
    return dict(accepted=len(parts) >= 2 and parts[1] == APP,
                resume=bool(parts and parts[0] == "1"))


def decimal_code(text):
    units = utf16_units(text)
    if len(units) != 4:
        return None
    return ((units[0]*10 + units[1])*10 + units[2])*10 + units[3] - 0xd050


def gesture_model(events):
    state, opens = 0, 0
    for event in events:
        if 1001 <= event <= 1005:
            if state == event-1001:
                if event == 1005:
                    opens += 1
                    state = 0
                else:
                    state += 1
            else:
                state = 0
    return dict(state=state, opens=opens)


def self_test():
    cases = []
    for token in [APP, MID, "Resume"]:
        checks = [(None, False), ("", False), (token, True), (token+"suffix", True),
                  (" "+token, False), (token+"\0suffix", True)]
        checks.extend((token[:i], False) for i in range(len(token)))
        checks.extend((token[:i]+"?"+token[i+1:], False) for i in range(len(token)))
        for command, expected in checks:
            assert prefix_gate(command, token) == expected
            cases.append(dict(command=command, expected=expected, token=token))
    usb = [("1 "+APP, True, True), ("0 "+APP, True, False),
           ("garbage "+APP, True, False), ("  1   "+APP+" extra", True, True),
           ("1 "+APP+"suffix", False, True), ("1\t"+APP, False, False),
           (APP, False, False), ("", False, False)]
    for command, accepted, resume in usb:
        assert usb_gate(command) == dict(accepted=accepted, resume=resume)
    for i in range(10000):
        assert decimal_code(f"{i:04}") == i
    assert decimal_code("111") is None and decimal_code("11111") is None
    gestures = [([1001,1002,1003,1004,1005], dict(state=0,opens=1)),
                ([1001,1003,1002,1003,1004,1005], dict(state=0,opens=0)),
                ([1001,1006,1002,1003,1004,1005], dict(state=0,opens=1)),
                ([1001,1001,1002], dict(state=0,opens=0)),
                ([1001,1002,1003,1004], dict(state=4,opens=0))]
    for events, expected in gestures:
        assert gesture_model(events) == expected
    return dict(prefix_cases=len(cases), usb_cases=len(usb), digit_cases=10000,
                gesture_cases=len(gestures), prefix_case_results=cases, usb_case_results=usb,
                gesture_case_results=gestures)


def main():
    modules = json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources, evidence, pes = [], [], {}
    for name, digest in HASHES.items():
        m = next(m for m in modules if m["origin"] == "705md" and m["name"] == name)
        path = ROOT/m["path"]
        assert hashlib.sha256(path.read_bytes()).hexdigest() == digest
        pe = pefile.PE(str(path)); pes[name] = pe
        sources.append(dict(module=name, path=m["path"], sha256=digest))
        functions = json.loads((ROOT/"analysis/functions/705md"/(name+".json")).read_text(encoding="utf-8"))["functions"]
        for va in FUNCTIONS[name]:
            f = next(f for f in functions if int(f["begin_va"], 16) == va)
            size = f["bytes"]
            raw = pe.get_data(va-pe.OPTIONAL_HEADER.ImageBase, size)
            assert len(raw) == size
            evidence.append(dict(module=name, va=hex(va), size=size, raw_hex=raw.hex(),
                                 sha256=hashlib.sha256(raw).hexdigest()))
    pe = pes["AppMain.exe"]; base = pe.OPTIONAL_HEADER.ImageBase

    def raw_evidence(va, size, role):
        raw = pe.get_data(va-base, size); assert len(raw) == size
        evidence.append(dict(module="AppMain.exe", va=hex(va), size=size, role=role,
                             raw_hex=raw.hex(), sha256=hashlib.sha256(raw).hexdigest()))
        return raw

    def wide(va):
        raw = pe.get_data(va-base, 1024)
        end = next(i for i in range(0, len(raw)-1, 2) if raw[i:i+2] == b"\0\0")
        return raw[:end].decode("utf-16le")

    assert wide(0x1707c0) == APP
    raw_evidence(0x1707c0, (len(APP)+1)*2, "AppMain/USB launch token")
    date, build = wide(0x14fbd0), wide(0x14fbe8)
    raw_evidence(0x14fbd0,(len(date)+1)*2,"AppMain embedded date")
    raw_evidence(0x14fbe8,(len(build)+1)*2,"AppMain embedded build")
    app_version = date[5:7]+"."+date[8:]+"."+build
    assert app_version == "02.16.17195"
    raw_evidence(0x1ff48, 12, "Resource image prefix leaf without .pdata entry")
    keypad_table = struct.unpack("<18I", raw_evidence(0x14ff40,72,"Keypad virtual-method table"))
    version_table = struct.unpack("<18I", raw_evidence(0x16facc,72,"System-version virtual-method table"))
    assert keypad_table[8] == 0x2815c and keypad_table[17] == 0x28218
    assert version_table[7] == 0xca600 and version_table[8] == 0xcab14 and version_table[17] == 0xcacbc
    themes = [wide(p) for p in struct.unpack("<4I", raw_evidence(0x1858f0, 16, "Four theme pointers"))]
    assert themes == ["M0", "M1", "M0_INV", "M1_INV"]
    pointers = struct.unpack("<461I", raw_evidence(0x185980, 461*4, "461 image filename pointers"))
    system = ROOT/next(s["path"] for s in sources if s["module"] == "AppMain.exe")
    system = system.parent
    resources = []
    for i, pointer in enumerate(pointers):
        filename = wide(pointer)
        raw_evidence(pointer, (len(filename)+1)*2, f"Image name {i}")
        variants = []
        for theme in themes:
            path = system/"Img"/theme/filename.replace("\\", "/")
            present = path.is_file()
            record = dict(theme=theme, present=present)
            if present:
                data = path.read_bytes()
                record.update(path=str(path.relative_to(ROOT)), bytes=len(data), sha256=hashlib.sha256(data).hexdigest())
                if data[:2] == b"BM" and len(data) >= 54:
                    width, height = struct.unpack_from("<ii", data, 18)
                    record.update(width=width, height=height, bit_depth=struct.unpack_from("<H", data, 28)[0],
                                  compression=struct.unpack_from("<I", data, 30)[0])
            variants.append(record)
        resources.append(dict(id=i, pointer=hex(pointer), filename=filename, variants=variants))
    # Values are checked against addiu/sw pairs in the original constructor.
    code_values = {0x5d4c:1111, 0x5d50:1119, 0x5d54:6971, 0x5d58:3740,
                   0x5d5c:3749, 0x5d60:362, 0x5d64:9999, 0x5d68:7777, 0x5d6c:2222}
    native = pe.get_data(0x277b0-base, 0x6c)
    registers, stores = {0:0}, {}
    for word in struct.unpack(f"<{len(native)//4}I", native):
        op, rs, rt = word >> 26, (word >> 21) & 31, (word >> 16) & 31
        immediate = word & 0xffff
        signed = immediate if immediate < 0x8000 else immediate-0x10000
        if op == 9 and rs in registers:
            registers[rt] = registers[rs]+signed
        elif op == 0x2b and rs == 16 and rt in registers:
            stores[signed] = registers[rt]
    assert all(stores[k] == v for k,v in code_values.items())
    checks = self_test()
    result = dict(binary_execution=False, sources=sources, evidence=evidence,
        launch_tokens=dict(app=APP, manager=MID), checks=checks,
        main_window=dict(width=800, height=480, style="0x92000000", extended_style="0x04000000", wndproc="0x13120c"),
        diagnostics=dict(constructor="0x27710", handler="0x28218", fields={hex(k):v for k,v in code_values.items()},
                         test_mode_initial_object_value=0, init_controls="0x2815c",
                         test_mode_restored_from_registry_on_init=True, ui_digits_only=True,
                         entry_screen=dict(id="0x4d",debug_class="CSystemVerDlg",handler="0xcacbc",state_offset="0x24e4",
                             areas=[dict(event=1001,x=0,y=0,width=200,height=150),
                                    dict(event=1002,x=110,y=330,width=200,height=150),
                                    dict(event=1003,x=600,y=0,width=200,height=150),
                                    dict(event=1004,x=300,y=0,width=200,height=150),
                                    dict(event=1005,x=600,y=330,width=200,height=150)]),
                         info_screen=dict(id="0x58",populate="0x27154",app_version=app_version,
                             registry_fields=["VerMicomFW","Bootversion","OSVersion2","VerBlue","NaviVersion",
                                              "DAB Mgr Version","DAB FW Version"]),
                         unused_in_handler=[7777], runtime_reachability="Not tested"),
        themes=themes, resources=resources,
        limitations=["Static code and synthetic commandline models; no MIPS execution",
                     "Image absence applies only to extracted update, not physical-unit filesystem",
                     "Caller-to-window reachability and full screen/event/audio behavior remain open"])
    (ROOT/"analysis/firmware/appmain-startup-contracts.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(json.dumps(dict(status="passed", source_modules=len(sources), preserved_ranges=len(evidence),
        image_ids=len(resources), image_files_by_theme={t:sum(v["present"] for r in resources for v in r["variants"] if v["theme"]==t) for t in themes},
        **{k:v for k,v in checks.items() if isinstance(v,int)}), indent=2))


if __name__ == "__main__":
    main()
