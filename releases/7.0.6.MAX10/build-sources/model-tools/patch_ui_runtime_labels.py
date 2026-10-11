"""Keep active Home/Radio/Media labels white when the M1 theme refreshes.

Equal-size, guarded MIPS edits on the exact complete MAX05 AppMain baseline.
Other resource profiles, normal/disabled colors and control positions stay equal.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

import pefile

BASE_SHA = 'b34676225ad428426b417cec33c30f7e18e56aeeb6e438900c01dc022225fcd9'


def move(rd, rs):
    return rs << 21 | rd << 11 | 0x25


def sw(rt, offset):
    return 0xae000000 | rt << 16 | offset


# Screen, function bounds, resource-profile cache and affected color arrays.
SCREENS = {
    'home': (0x24c98, 0x24e84, 0x186144,
             [0x868, 0xdd8, 0x1348, 0x18b8, 0x1e28, 0x2398, 0x2908, 0x2e78, 0x3708]),
    'media-source': (0x48e00, 0x48f40, 0x186198,
                     [0xf20, 0x1490, 0x1a00, 0x1f70, 0x24e0]),
    'radio-source': (0xaaecc, 0xaafdc, 0x186250, [0xf20, 0x1490, 0x1a00]),
    'radio-presets': (0x99adc, 0x99c94, 0x186234, [0x2a90]),
    'radio-options': (0x9ba64, 0x9bc2c, 0x186238,
                      [0x1a80, 0x1ff0, 0x2560, 0x2ad0, 0x3040]),
}


def edits():
    out = []
    def add(screen, site, before, after, purpose):
        out.append(dict(screen=screen, address=site, before=before, after=after, purpose=purpose))
    for site, reg in [(0x24d74,12),(0x24d78,13),(0x24d7c,15),
                      (0x24d84,25),(0x24d88,8),(0x24d94,9)]:
        add('home',site,move(reg,0),move(reg,11),'M1 active label uses existing white normal color')
    # a1 is caller-saved and unused on these successful refresh paths. Branch
    # delay slots select a mask; existing redundant aliases combine it with the
    # normal color. M0, M1_INV and unknown profiles still store the original zero.
    specs = [
        ('media-source',0x48e50,0x48e64,0x48e70,0x48ecc,move(9,8),10,0x48ed0,sw(9,0x8ec),sw(8,0x8ec),
         [0x48ee0,0x48ee8,0x48ef0,0x48ef8,0x48f00,0x48f08,0x48f10,0x48f18,0x48f20,0x48f28]),
        ('radio-source',0xaaf1c,0xaaf30,0xaaf3c,0xaaf80,move(9,8),10,0xaaf8c,sw(9,0x8ec),sw(8,0x8ec),
         [0xaaf9c,0xaafa4,0xaafac,0xaafb4,0xaafbc,0xaafc4]),
        ('radio-presets',0x99b2c,0x99b40,0x99b4c,0x99bfc,move(3,8),8,0x99c60,sw(3,0x2a90),sw(8,0x2a90),
         [0x99c64,0x99c6c]),
        ('radio-options',0x9bab4,0x9bac8,0x9bad4,0x9bb64,move(3,8),8,0x9bb74,sw(3,0x820),sw(8,0x820),
         [0x9bbc0,0x9bbc8,0x9bbd0,0x9bbd8,0x9bbe4,0x9bbec,0x9bbf8,0x9bc00,0x9bc08,0x9bc10]),
    ]
    for name,clear,set_mask,reset,combine,before,normal,store,old_store,new_store,active in specs:
        add(name,clear,0,move(5,0),'Clear active-color mask before cached-profile check')
        add(name,set_mask,0,0x2405ffff,'M1 branch delay slot selects full color mask')
        add(name,reset,0,move(5,0),'Non-M1 branch delay slot clears mask')
        add(name,combine,before,5<<21|normal<<16|5<<11|0x24,'Mask the existing normal color for active states')
        add(name,store,old_store,new_store,'Store unchanged normal/header color without redundant alias')
        for site in active:
            # Exact expected words are generated from the independently listed
            # active color offsets, not read from arbitrary input instructions.
            index=active.index(site)
            offset=SCREENS[name][3][index//2]+(4 if index%2==0 else 12)
            # Radio options stores the second and third arrays before the first.
            if name=='radio-options':
                order=[0x1ff0,0x2560,0x1a80,0x2ad0,0x3040]
                offset=order[index//2]+(4 if index%2==0 else 12)
            add(name,site,sw(0,offset),sw(5,offset),'Refresh pressed/selected color from the M1 mask')
    return out


def patch(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:
        raise ValueError('Expected exact complete MAX05 AppMain.exe')
    pe=pefile.PE(data=raw);out=bytearray(raw);records=[]
    for e in edits():
        at=pe.get_offset_from_rva(e['address']-pe.OPTIONAL_HEADER.ImageBase)
        before,after=(struct.pack('<I',e[k]) for k in ('before','after'))
        assert raw[at:at+4]==before,(hex(e['address']),raw[at:at+4].hex(),before.hex())
        out[at:at+4]=after
        records.append(dict(screen=e['screen'],address=hex(e['address']),offset=at,
                            before_hex=before.hex(),after_hex=after.hex(),purpose=e['purpose']))
    out=bytes(out)
    assert len(out)==len(raw)
    return out,dict(schema=1,before_sha256=BASE_SHA,after_sha256=hashlib.sha256(out).hexdigest(),
                    edits=records,changed_bytes=sum(a!=b for a,b in zip(raw,out)),
                    file_size_preserved=True,branches_calls_headers_relocations_unchanged=True,
                    hardware_tested=False,lgu_built=False)


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for field in ('input','output','recipe'):p.add_argument('--'+field,type=Path,required=True)
    a=p.parse_args()
    if a.output.exists() or a.recipe.exists():raise FileExistsError('Use fresh output paths')
    out,recipe=patch(a.input.read_bytes())
    for path in (a.output,a.recipe):path.parent.mkdir(parents=True,exist_ok=True)
    a.output.write_bytes(out);a.recipe.write_bytes((json.dumps(recipe,indent=2)+'\n').encode())
    print(json.dumps(dict(edits=len(recipe['edits']),changed_bytes=recipe['changed_bytes'],lgu_ready=False)))
