"""Change only the home constructor's pressed/selected text-color stores.

No branches, calls, register values, file sections or control/event geometry change.
This is an offline development patch, not a unit-tested or install-ready update.
The shared home color array affects M0, M1 and inverse home profiles.
"""
import hashlib
import pefile
from inspect_home_layout import APP_SHA, trace

PATCHES = [(0x21d10, 0xafa0004c, 0xafa8004c),
           (0x21d18, 0xafa00054, 0xafa80054)]


def patch(original):
    assert hashlib.sha256(original).hexdigest() == APP_SHA
    pe = pefile.PE(data=original)
    base = pe.OPTIONAL_HEADER.ImageBase
    # $t0 contains 0x00ffffff throughout both stores. Check the exact surrounding
    # instruction sequence rather than matching these stores elsewhere in the file.
    context = [0x3c0800ff, 0x3508ffff, 0x0040b025, 0x240a004e,
               0xafa0004c, 0x24140001, 0xafa00054]
    assert pe.get_data(0x21d00-base,28) == b''.join(w.to_bytes(4,'little') for w in context)
    output = bytearray(original)
    records = []
    allowed = set()
    for address,before,after in PATCHES:
        offset = pe.get_offset_from_rva(address-base)
        assert output[offset:offset+4] == before.to_bytes(4,'little')
        output[offset:offset+4] = after.to_bytes(4,'little')
        allowed.add(offset+2)
        records.append(dict(address=hex(address),offset=offset,
                            before=hex(before),after=hex(after),
                            meaning='Store existing white color instead of zero in home label array'))
    result = bytes(output)
    assert len(original)==len(result)
    assert {i for i,(a,b) in enumerate(zip(original,result)) if a!=b} == allowed
    scenarios=[]
    for ui,profile in [(0,0),(1,1),(1,3)]:
        for eco in (0,1):
            for layout in (0,1):
                for smart in (False,True):
                    before = trace(ui,eco,layout,profile,smart)
                    after = trace(ui,eco,layout,profile,smart,raw=result)
                    expected = before.copy()
                    expected['controls'] = [dict(r) for r in before['controls']]
                    for r in expected['controls']:
                        if r.get('event') in (1001,1002,1003,1004,1005,1006,1008):
                            r['colors'] = [r['colors'][0],0xffffff,r['colors'][2],0xffffff]
                    assert after == expected, 'Unexpected home behavior difference'
                    scenarios.append(after)
    return result,dict(instructions=records,changed_bytes=2,
                       bounded_layout_cases_verified=24,scenarios=scenarios,
                       normal_and_disabled_colors_preserved=True,
                       all_control_geometry_events_fonts_labels_preserved=True,
                       affects_all_home_profiles=True,native_execution=False,
                       hardware_tested=False)
