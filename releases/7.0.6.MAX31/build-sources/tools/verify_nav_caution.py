"""Exercise actual Nav caution constructor/launch/reset bytes with API fixtures."""
import json
import pefile
from patch_nav_caution import ROOT, BASE, OUT, APP, PIN, RESETS, patch
from build_home_theme import sha
from verify_ui_english import UiVM
from verify_usb_input_safety import relocated
from inspect_wave_queue import STOP

STACK, OBJECT, MANAGER, HOME = 0x68000000, 0x61000000, 0x62000000, 0x63000000


def construct(raw, delta, existing=False, fail=False):
    vm = UiVM(pefile.PE(data=raw), [(0x12fd4 + delta, 0x13098 + delta)])
    singleton = 0x188244 + delta
    vm.write(singleton, OBJECT if existing else 0)
    vm.reg[29], vm.reg[31] = STACK, STOP
    saved = {r: 0x12340000 + r for r in (16, 17)}
    for r, value in saved.items(): vm.reg[r] = value
    events = []

    def allocate(m):
        assert m.reg[4] == 0x166c
        events.append('allocate')
        if fail: return 0
        for at in range(0x166c): m.write(OBJECT + at, 0xa5, 1)
        return OBJECT

    def initialize(m):
        events.append(hex(m.reg[4] - OBJECT)); return 0

    vm.hooks = {0x1402f0 + delta: allocate}
    for va in (0x134a70,0x139458,0x13e1d4,0x13ea5c,0x1386e8): vm.hooks[va + delta] = initialize
    if existing:
        for off, value in ((0x165c,1),(0x1660,7),(0x1664,3),(0x1668,9),(0x2c0,0x55)):
            vm.write(OBJECT + off, value)
    vm.run(0x12fd4 + delta, {STOP})
    assert vm.reg[29] == STACK and vm.reg[31] == STOP
    assert all(vm.reg[r] == value for r, value in saved.items())
    assert vm.reg[2] == (0 if fail else OBJECT) and vm.read(singleton) == (0 if fail else OBJECT)
    if fail:
        assert events == ['allocate'] and not any(OBJECT <= at < OBJECT + 0x166c for at in vm.mem)
    elif existing:
        assert not events
        assert [vm.read(OBJECT + off) for off in (0x165c,0x1660,0x1664,0x1668,0x2c0)] == [1,7,3,9,0x55]
    else:
        assert len(events) == 10
        assert [vm.read(OBJECT + off) for off in (0x165c,0x1660,0x1664,0x1668,0x2c0)] == [1,0,0,0,0x55]
    vm.pe.close()
    return dict(existing=existing, allocation_failed=fail, accepted=not fail, abi_preserved=True)


def launch(raw, delta, accepted, map_button):
    begin, end = (0x22fb8,0x23060) if map_button else (0x22ed0,0x22f78)
    vm = UiVM(pefile.PE(data=raw), [(begin + delta, end + delta)])
    vm.reg[29], vm.reg[17] = STACK, HOME
    vm.write(OBJECT + 0x165c, accepted)
    vm.write(0x187b38 + delta, MANAGER)
    vm.write(HOME + 0x50, 0x1111)
    vm.write(HOME + (0x1e4c if map_button else 0x18dc) + 0x34, 0)
    events = []
    def show(m):
        events.append('caution'); assert m.reg[4] == OBJECT; return 1
    def enter(m):
        events.append('map' if map_button else 'navigation')
        assert m.reg[4] == MANAGER + 0xc4; return 1
    vm.hooks = {0x12fd4 + delta: lambda m: OBJECT, 0x136494 + delta: show,
        (0xe4ee0 if map_button else 0xe4fa8) + delta: enter}
    for va in (0x139020,0x140c44,0x13fef8,0x13ff08): vm.hooks[va + delta] = lambda m: 1
    vm.run(begin + delta, {0x231d4 + delta})
    assert events == (['map' if map_button else 'navigation'] if accepted else ['caution'])
    vm.pe.close()
    return dict(button='map' if map_button else 'navigation', accepted=bool(accepted), events=events)


def verify():
    before = (BASE / APP).read_bytes()
    after = (OUT / 'payload' / APP).read_bytes()
    expected, recipe = patch(before)
    assert after == expected and sha(before) == PIN
    rows = []
    for delta in (0,0x10000,0x123000):
        a, b = (relocated(raw, delta) if delta else raw for raw in (before, after))
        constructors = [construct(b,delta),construct(b,delta,existing=True),construct(b,delta,fail=True)]
        gates = []
        for map_button in (False,True):
            # Reproduce the original warning, then follow the unchanged accepted path.
            gates += [launch(a,delta,0,map_button), launch(b,delta,1,map_button)]
        resets = []
        for va in RESETS:
            for raw, value in ((a,0),(b,1)):
                vm = UiVM(pefile.PE(data=raw), [(va + delta, va + delta + 4)])
                vm.reg[2] = OBJECT
                vm.write(OBJECT + 0x165c,1)
                vm.run(va + delta,{va + delta + 4})
                assert vm.read(OBJECT + 0x165c) == value
                vm.pe.close()
            resets.append(dict(address=hex(va + delta), baseline_clears=True, candidate_retains=True))
        rows.append(dict(rebase=hex(delta), constructors=constructors, launch_paths=gates, resets=resets))
    assert sha((BASE / APP).read_bytes()) == PIN
    proof = dict(passed=True, input_sha256=PIN, output_sha256=sha(after), nine_instructions_only=True,
        imports_unwind_relocations_sections_unchanged=True, prior_Bluetooth_helpers_and_UI_exact=True,
        constructors_allocation_failure_and_existing_object_passed=True, rebases=rows,
        normal_navigation_and_map_launch_paths_retained=True, four_stop_reset_sites_checked=True,
        nav_executable_skin_licenses_unchanged=True, native_executed=False, hardware_tested=False,
        limitations='Actual MIPS byte interpretation with allocation/control/OS/Nav API fixtures. Car launch, cold boot and guidance need testing.')
    (OUT / 'verification.json').write_text(json.dumps(proof,indent=2) + '\n')
    return proof


if __name__ == '__main__':
    print(json.dumps(verify(),indent=2))
