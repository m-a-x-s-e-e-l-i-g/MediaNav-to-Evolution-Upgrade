"""Preserve GUI hold/popup contracts and the USB seek chain; never execute native code."""
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
APP_HASH = "6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8"
USB_HASH = "bb435bc428664845a21ffe7bce7a813db06b7e7f92408d297dbbeade94507cd2"
TABLES = {0x17cba8:"plain label",0x17cbe4:"substring-highlight label",
          0x17cc20:"bitmap-insertion label",0x17cc60:"offscreen label",
          0x17cdd8:"basic button",0x17ce10:"button with text",
          0x17ce4c:"derived text button",0x17ce88:"alternate bitmap button",0x17cec4:"slider"}


class Hold:
    def __init__(self, repeat=True):
        self.repeat = repeat; self.pressed = False; self.selected = False
        self.repeated = False; self.timers = set(); self.actions = []

    def down(self):
        self.pressed = self.selected = True; self.repeated = False
        if self.repeat: self.timers.add(0x3f6)

    def timer(self, ident):
        # Delivery is separate from scheduling, so queued messages can be modeled.
        if ident == 0x3f6:
            self.timers.discard(ident)
            if self.selected and self.repeat:
                self.actions.append(3); self.repeated = True; self.timers.add(0x3f7)
        elif ident == 0x3f7:
            if self.selected and self.repeat: self.actions.append(4)
            else: self.timers.discard(ident); self.repeated = False

    def cancel(self):
        self.selected = False; self.repeated = False
        if self.repeat: self.timers -= {0x3f6,0x3f7}

    def move_out(self):
        if self.pressed:
            self.pressed = False
            if self.repeat and self.repeated: self.actions.append(5)
            self.cancel()

    def up(self, inside=True):
        if self.pressed:
            self.pressed = False
            if inside:
                self.actions.append(5 if self.repeat and self.repeated else 2)
                self.cancel()


def usb_command(event, action):
    return {0x3ea:{2:100,3:0x68,5:0x69},0x3ec:{2:0x65,3:0x66,5:0x67}}.get(event,{}).get(action)


def seek_step(position, duration, direction, multiplier):
    step = 3 if multiplier == 0 else multiplier * 3
    target = position + (step if direction == 1 else -step)
    if direction == 1 and target >= duration:
        return duration,0,0,"auto-next"
    if direction == 2 and target < 0:
        return 0,2,0,"publish"
    return target,direction,multiplier,"publish"


def seek_units(target_seconds, duration_units):
    requested = target_seconds * 10_000_000
    if duration_units is not None and duration_units-requested < 1_500_000:
        return duration_units-1_500_000
    return requested


def position_seconds(position_units, duration_units):
    # Mirrors the integer-millisecond rounding/clamp in 11230 for nonnegative inputs.
    minimum_ms = min(position_units,duration_units)//10_000
    rounded = minimum_ms//1000 + (minimum_ms%1000 > 849)
    return min(rounded,duration_units//10_000//1000)


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources=[];tables=[]
    specs=[("AppMain.exe",APP_HASH,[0x134a70,0x134ed0,0x135778,0x135aec,0x135bcc,
            0x135c58,0x13cf30,0x13e554,0x13e620,0x13e6f8,0x4c26c,0x4d00c,
            0x13a0d4,0x13c0f4,0x13c204,0x13c3cc,0x13cbc4]),
           ("MgrUSB.exe",USB_HASH,[0x21d00,0x20eac,0x1de20,0x1de3c,0x1b374,
            0x1b300,0x1d1b0,0x20340,0x1d880,0x1b3b0,0x1111c,0x11230,0x1137c,
            0x11790,0x11918,0x1d23c])]
    for name,expected,addresses in specs:
        m=next(m for m in modules if m["origin"]=="705md" and m["name"]==name)
        p=ROOT/m["path"];assert hashlib.sha256(p.read_bytes()).hexdigest()==expected
        pe=pefile.PE(str(p));base=pe.OPTIONAL_HEADER.ImageBase
        functions=json.loads((ROOT/f"analysis/functions/705md/{name}.json").read_text(encoding="utf-8"))["functions"]
        ranges=[(va,next(f["bytes"] for f in functions if int(f["begin_va"],16)==va)) for va in addresses]
        if name=="AppMain.exe":
            ranges += [(va,60) for va in TABLES]
            ranges += [(0x13e1d4,0xb4)]
            for va,label in TABLES.items():
                targets=struct.unpack("<15I",pe.get_data(va-base,60))
                tables.append(dict(va=hex(va),meaning=label,
                    slots=[dict(offset=hex(i*4),target=hex(v)) for i,v in enumerate(targets)]))
        evidence=[]
        for va,size in ranges:
            raw=pe.get_data(va-base,size);assert len(raw)==size
            evidence.append(dict(va=hex(va),size=size,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
        sources.append(dict(module=name,path=m["path"],sha256=expected,evidence=evidence))
    scenarios=[("tap",["down","up"],[2]),
        ("hold",["down",0x3f6,0x3f7,0x3f7,"up"],[3,4,4,5]),
        ("cancel before hold",["down","move","up"],[]),
        ("cancel after hold",["down",0x3f6,0x3f7,"move","up"],[3,4,5]),
        ("queued first timer after cancel",["down","move",0x3f6],[]),
        ("queued repeat after release",["down",0x3f6,"up",0x3f7],[3,5])]
    traces=[]
    for label,events,expected in scenarios:
        h=Hold()
        for event in events:
            if event=="down":h.down()
            elif event=="up":h.up()
            elif event=="move":h.move_out()
            else:h.timer(event)
        assert h.actions==expected and not h.timers
        traces.append(dict(name=label,events=events,actions=h.actions,
            usb_prev=[usb_command(0x3ea,a) for a in h.actions],
            usb_next=[usb_command(0x3ec,a) for a in h.actions]))
    # Both orderings at the hold boundary are possible without assuming OS timer precision.
    h=Hold();h.down();h.up();h.timer(0x3f6);assert h.actions==[2]
    h=Hold();h.down();h.timer(0x3f6);h.up();assert h.actions==[3,5]
    h=Hold(False);h.down();h.up();assert h.actions==[2] and not h.timers
    h=Hold();h.down();h.up(inside=False)
    assert not h.pressed and h.selected and h.timers=={0x3f6}
    h.timer(0x3f6);h.timer(0x3f7)
    assert h.actions==[3,4] and h.timers=={0x3f7}
    outside_without_move=dict(actions=h.actions,pressed=h.pressed,selected=h.selected,
                              active_timers=sorted(h.timers))
    seek_cases=0
    for duration in (0,1,2,3,10,100):
        for position in range(duration+1):
            for direction in (1,2):
                for multiplier in (0,4):
                    actual=seek_step(position,duration,direction,multiplier)
                    delta=3 if multiplier==0 else 12
                    if direction==1:
                        target=min(duration,position+delta)
                        assert actual[0]==target
                        assert actual[1]==(0 if position+delta>=duration else 1)
                    else:
                        assert actual[0]==max(0,position-delta) and actual[1]==2
                    seek_cases+=1
    boundaries=[(0,10_000_000,0),(1,11_499_999,9_999_999),
        (1,11_500_000,10_000_000),(1,10_000_000,8_500_000),
        (0,1_000_000,-500_000),(1,None,10_000_000)]
    for target,duration,expected in boundaries:assert seek_units(target,duration)==expected
    rounding_cases=0
    for millis in range(4000):
        expected=millis//1000+(millis%1000>=850)
        assert position_seconds(millis*10_000,100_000_000)==expected
        rounding_cases+=1
    assert position_seconds(39_000_000,39_000_000)==3
    result=dict(binary_execution=False,sources=sources,vtables=tables,
        hold=dict(delay_ms=700,repeat_ms=200,timers={"first":"0x3f6","repeat":"0x3f7"},
            callback_slot="0x44",actions={"2":"tap","3":"hold start","4":"repeat","5":"hold end"},traces=traces),
        outside_release_without_move=outside_without_move,
        popup=dict(parent_reenable_timer="0x40c",parent_disabled_ms=2000,
            foreground_timer="0x43b",foreground_interval_ms=150,foreground_deliveries=5),
        usb=dict(app_sender=21,receiver=5,prev_event="0x3ea",next_event="0x3ec",
            external_to_internal_track_commands={"100":101,"101":100},
            start_directions={"0x66":1,"0x68":2},stop_commands=["0x67","0x69"],
            direction_offset="play control +0x2930",multiplier_offset="play control +0xe60",
            step_timer="0x3e9",step_ms=300,initial_step_seconds=3,
            acceleration_timer="0x3ea",acceleration_ms=5000,multiplier_after_delay=4,
            accelerated_step_seconds=12,seek_end_margin_units=1500000,time_units_per_second=10000000,
            rewind_zero_keeps_direction=True),
        checks=dict(preserved_ranges=sum(len(s["evidence"]) for s in sources),vtables=len(tables),
            lifecycle_scenarios=len(scenarios),threshold_orderings=2,nonrepeat_cases=1,outside_release_cases=1,
            seek_steps=seek_cases,seek_unit_boundaries=len(boundaries),rounding_cases=rounding_cases),
        limitations=["Models omit native scheduler timing, concurrent IPC and COM failures",
            "Autofit screen reachability and marquee/list scrolling remain open",
            "DirectShow interface identity and full media/repeat/shuffle pipeline remain open"])
    (ROOT/"analysis/firmware/appmain-interaction-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**result["checks"]),indent=2))


if __name__=="__main__":main()
