"""Original CBtData singleton/cache initialization and failure-path byte traces.

Memory/OS/heap are explicit fixtures. Recursion and low-address access stop at
bounded witnesses; no native executable, unit interaction or patch is emitted.
"""
import hashlib
import json
import re
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import OBJECT, STACK, abi, put, data
from inspect_wave_queue import STOP
from verify_bt_pairing_ui import UIVM
from verify_bt_pairing_confirmation import pe_string
from draft_bt_pairing_storage import draft_app_pairing
from draft_bt_list_ack import app_ack

RANGES = [(0x110010, 0x110240), (0x1102a8, 0x1102f4), (0x1103a4, 0x110448),
          (0x110478, 0x11057c), (0x113d40, 0x113dac), (0x113dac, 0x113ec4),
          (0x11b06c, 0x11b144), (0x110708, 0x1108f0), (0x11afcc, 0x11b044)]
MAP_API, CLOSE_API, CONVERT_API = 0xf00a0010, 0xf00a0020, 0xf00a0030
MAPPING, BANK = 0x63000000, 0x64000000
APP_CONTEXT = 0x65000000
MEMSET = 0x4007be0c
MEMSET_END = 0x4007bfa4


def clobber(vm):
    for reg in (*range(2, 16), 24, 25): vm.reg[reg] = 0xcafe0000 + reg


class Witness(Exception):
    def __init__(self, event): self.event = event


class LifeVM(UIVM):
    def __init__(self, pe):
        super().__init__(pe, RANGES)
        self.native_access = False
        self.entries, self.stop_recursion = [], False
    def read(self, at, size=4):
        if self.native_access and at < 0x10000:
            raise Witness(dict(kind="low-read", pc=hex(self.pc), address=hex(at), bytes=size))
        return super().read(at, size)
    def write(self, at, value, size=4):
        if self.native_access and at < 0x10000:
            raise Witness(dict(kind="low-write", pc=hex(self.pc), address=hex(at), bytes=size, value=hex(value & 0xffffffff)))
        return super().write(at, value, size)
    def word(self, pc):
        if self.stop_recursion and pc in (0x1102a8, 0x110478):
            event = dict(entry=hex(pc), stack=hex(self.reg[29]), singleton=hex(self.read(0x186560)))
            self.entries.append(event)
            if sum(e["entry"] == "0x110478" for e in self.entries) == 4:
                raise Witness(dict(kind="fourth-destructor-entry", **event))
        return super().word(pc)


class Life:
    core_pe = None
    def __init__(self, pe, allocation=True, mapping=True, view=True, heap=True):
        self.pe, self.allocation, self.mapping, self.view, self.heap = pe, allocation, mapping, view, heap
        self.heap_failure = "all" if heap is False else heap if isinstance(heap, str) else None
        self.vm = LifeVM(pe); self.events = []
        vm = self.vm
        for at, val in [(0x185024, MAP_API), (0x185028, CLOSE_API), (0x185088, CONVERT_API),
                        (0x187b38, APP_CONTEXT), (APP_CONTEXT + 0x2368, 0x42)]: vm.write(at, val)
        put(vm, 0x176b18, pe.get_data(0x176b18 - pe.OPTIONAL_HEADER.ImageBase, 4))
        assert vm.read(0x176b18) == 0x1102a8
        vm.hooks.update({0x1402f0: self.allocate, 0x138518: self.heap_allocate,
                         0x140de4: self.memset, MAP_API: self.create_mapping,
                         0x13ff18: self.map_view, CLOSE_API: self.close,
                         0x13ff28: self.unmap, 0x1402e0: self.free})
    def allocate(self, vm):
        assert vm.reg[4] == 0x15947c
        self.events.append(dict(kind="object-allocation", bytes=vm.reg[4], success=self.allocation))
        clobber(vm); return OBJECT if self.allocation else 0
    def heap_allocate(self, vm):
        index = sum(e["kind"] == "heap-allocation" for e in self.events)
        assert vm.reg[4] == (0xb8920, 0x42680, 4000)[index]
        failed = self.heap_failure in ("all", ("first", "second", "third")[index])
        pointer = 0 if failed else 0x66000000 + index * 0x100000
        self.events.append(dict(kind="heap-allocation", bytes=vm.reg[4], returned_pointer=hex(pointer)))
        clobber(vm); return pointer
    def memset(self, vm):
        at, value, count = vm.reg[4:7]
        assert value == 0, (hex(at), hex(value), count, hex(vm.pc))
        if at == 0:
            assert self.core_pe is not None
            core = LifeVM(self.core_pe); core.ranges = [(MEMSET, MEMSET_END)]
            core.mem = vm.mem; core.native_access = True
            core.reg[4:7] = [at, value, count]
            core.reg[29] = STACK - 0x10000; core.reg[31] = STOP
            try: core.run(MEMSET, {STOP})
            except Witness as e:
                raise Witness(dict(**e.event, module="coredll.dll", caller_pc=hex(vm.pc), requested_bytes=count))
            raise AssertionError("NULL memset unexpectedly completed")
        within_object = OBJECT <= at and at + count <= OBJECT + 0x15947c
        heap_events = [e for e in self.events if e["kind"] == "heap-allocation"]
        within_heap = any(int(e["returned_pointer"], 16) <= at and at + count <= int(e["returned_pointer"], 16) + e["bytes"] for e in heap_events)
        assert within_object or within_heap, (hex(at), count, hex(vm.pc))
        self.events.append(dict(kind="zero-call", object_offset=hex(at - OBJECT) if within_object else None,
                                heap_pointer=None if within_object else hex(at), bytes=count))
        # Actual byte fixture for the affected initial record/cache region;
        # large phonebook/media zeros are interval events, not expanded RAM.
        if within_object and at < OBJECT + 0x600: put(vm, at, bytes(count))
        clobber(vm); return at
    def create_mapping(self, vm):
        assert vm.reg[4:8] == [0xffffffff, 0, 4, 0]
        name = vm.read(vm.reg[29] + 0x14)
        assert pe_string(self.pe, name) == "BlueEarth"
        size = vm.read(vm.reg[29] + 0x10)
        assert size in (0, 0x13d620)
        self.events.append(dict(kind="create-mapping", name="BlueEarth", bytes=size, success=self.mapping))
        clobber(vm); return MAPPING if self.mapping else 0
    def map_view(self, vm):
        assert vm.reg[4:8] == [MAPPING, 4, 0, 0] and vm.read(vm.reg[29] + 0x10) == 0
        self.events.append(dict(kind="map-view", success=self.view)); clobber(vm)
        return BANK if self.view else 0
    def close(self, vm):
        self.events.append(dict(kind="close", handle=hex(vm.reg[4]))); clobber(vm); return 1
    def unmap(self, vm):
        self.events.append(dict(kind="unmap", pointer=hex(vm.reg[4]))); clobber(vm); return 1
    def free(self, vm):
        self.events.append(dict(kind="free", pointer=hex(vm.reg[4]))); clobber(vm); return 0
    def call(self, entry, arg):
        self.vm.native_access = True
        try: abi(self.vm, entry, arg)
        finally: self.vm.native_access = False


def singleton_case(pe, allocation=True, mapping=True, view=True, heap=True):
    f = Life(pe, allocation, mapping, view, heap)
    vm = f.vm; vm.write(0x186560, 0)
    put(vm, OBJECT + 0x270, bytes([0xa5]) * 0x334)
    fault, retry = None, None
    try: f.call(0x1103a4, 0)
    except Witness as e: fault = e.event
    if not allocation:
        assert fault and fault["kind"] == "low-write" and fault["address"] == "0x8"
        assert vm.read(0x186560) == 0
        assert [e["kind"] for e in f.events] == ["object-allocation", "create-mapping"]
        assert fault["pc"] == "0x11b0b4"
    elif heap is False or heap in ("first", "second"):
        assert fault and fault["kind"] == "low-write" and fault["module"] == "coredll.dll"
        assert fault["requested_bytes"] == (0x42680 if heap == "second" else 0xb8920) and fault["address"] == "0x0"
        assert vm.read(0x186560) == OBJECT
        n = len(f.events); f.call(0x1103a4, 0)
        assert vm.reg[2] == OBJECT and len(f.events) == n
        retry = dict(returned_pointer=hex(vm.reg[2]), new_initialization_events=0,
                     scope="Fresh fixture invocation after stopped native fault, not proven CE exception recovery")
    else:
        assert fault is None and vm.reg[2] == OBJECT and vm.read(0x186560) == OBJECT
        assert data(vm, OBJECT + 0x270, 0x334) == bytes(0x334)
        assert vm.read(OBJECT + 0x5a4) == 0xffffffff and vm.read(OBJECT + 0x26c) == 0
        assert vm.read(OBJECT + 0xc) == (BANK if mapping and view else 0)
        assert vm.read(OBJECT + 8) == (MAPPING if mapping and view else 0)
        expected_heap = [int(e["returned_pointer"], 16) for e in f.events if e["kind"] == "heap-allocation"]
        assert [vm.read(OBJECT + off) for off in (0x5b8, 0x5bc, 0x5c4)] == expected_heap
        # Already-initialized singleton path performs no work.
        n = len(f.events); f.call(0x1103a4, 0); assert vm.reg[2] == OBJECT and len(f.events) == n
    return dict(object_allocation=allocation, mapping=mapping, view=view, heap_allocations=heap,
                events=f.events, witness=fault, returned_object=None if fault else hex(vm.reg[2]),
                shared_pointer=hex(vm.read(OBJECT + 0xc)), abi_preserved=fault is None,
                retry_after_stopped_initialization=retry,
                finding="Allocation failure still reaches shared-map store on address eight" if not allocation else
                        "Failed auxiliary allocation reaches coredll memset store at NULL; registered singleton makes fixture retry skip initialization" if heap is False or heap in ("first", "second") else
                        "Singleton returned despite absent shared mapping or absent heap buffers" if not mapping or not view or heap == "third" else
                        "Native constructor/reset clear original record/cache span and return initialized singleton")


def destructor(pe, singleton, deleting=1):
    f = Life(pe); vm = f.vm
    vm.write(0x186560, OBJECT if singleton else 0); vm.write(0x186564, 0)
    vm.write(OBJECT, 0x176b18)
    for off, val in ((8, 0x701), (0xc, 0x702), (0x14, 0x703), (0x1c, 0x704)): vm.write(OBJECT + off, val)
    vm.stop_recursion = singleton; vm.reg[5] = deleting
    witness = None
    try: f.call(0x1102a8, OBJECT)
    except Witness as e: witness = e.event
    if singleton:
        assert witness and witness["kind"] == "fourth-destructor-entry"
        assert vm.read(0x186560) == OBJECT and not f.events
        assert [e["entry"] for e in vm.entries] == ["0x1102a8", "0x110478"] * 4
        stacks = [int(e["stack"], 16) for e in vm.entries if e["entry"] == "0x110478"]
        assert all(a - b == 0x40 for a, b in zip(stacks, stacks[1:]))
    else:
        assert witness is None
        expected = [dict(kind="unmap", pointer="0x704"), dict(kind="close", handle="0x703"),
                    dict(kind="unmap", pointer="0x702"), dict(kind="close", handle="0x701")]
        if deleting & 1: expected.append(dict(kind="free", pointer=hex(OBJECT)))
        assert f.events == expected
    return dict(singleton_still_registered=singleton, deleting_flag=deleting, entries=vm.entries,
                events=f.events, witness=witness, abi_preserved=not singleton,
                finding="Native self-singleton vtable route re-enters destructor before clearing global or cleanup" if singleton else
                        "Cleanup/free returns when singleton was already cleared before entry")


def missing_shared_copy(pe, producer_failure):
    # First produce the missing pointer through the real singleton/mapping path.
    f = Life(pe, mapping=producer_failure != "mapping", view=producer_failure != "view")
    vm = f.vm; vm.write(0x186560, 0)
    f.call(0x1103a4, 0)
    assert vm.read(OBJECT + 0xc) == 0
    vm.write(OBJECT + 0x26c, 1)
    witness = None
    try: f.call(0x110708, OBJECT)
    except Witness as e: witness = e.event
    assert witness and witness["kind"] == "low-read" and witness["address"] == "0x0"
    return dict(producer_failure=producer_failure, events=f.events, consumer_count=1, witness=witness,
                finding="Native mapping failure returns nonzero object; later nonempty copy reads address zero",
                scope="Injected later count; actual producer/CE timing not executed; consumer original/variant bytes interpreted")


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "AppMain.exe")
    core = next(m for m in modules if m["origin"] == "rom" and m["name"] == "coredll.dll")
    core_source, core_pe = source(core, [MEMSET], {MEMSET: MEMSET_END - MEMSET})
    symbol = next(s for s in core_pe.DIRECTORY_ENTRY_EXPORT.symbols if s.ordinal == 1047)
    assert symbol.name == b"memset" and core_pe.OPTIONAL_HEADER.ImageBase + symbol.address == MEMSET
    Life.core_pe = core_pe
    memset_cases = []
    for alignment in range(4):
        for n in (0, 1, 2, 3, 4, 31, 32, 33, 64, 65):
            for value in (0, 0x5a, 0xff, 0x123):
                vm = LifeVM(core_pe); vm.ranges = [(MEMSET, MEMSET_END)]
                at = 0x70000004 + alignment
                put(vm, 0x70000000, bytes([0xa5]) * 76)
                vm.reg[5:7] = [value, n]
                abi(vm, MEMSET, at)
                assert vm.reg[2] == at and data(vm, at, n) == bytes([value & 255]) * n
                assert data(vm, 0x70000000, at - 0x70000000) == bytes([0xa5]) * (at - 0x70000000)
                assert data(vm, at + n, 0x70000000 + 76 - at - n) == bytes([0xa5]) * (0x70000000 + 76 - at - n)
                memset_cases.append(dict(alignment=alignment, count=n, value=value, returned_pointer=hex(at), guards_preserved=True, abi_preserved=True))
    src, original = source(module, [a for a, _ in RANGES], {})
    raw = (ROOT / module["path"]).read_bytes()
    bb, bp = draft_app_pairing(raw); ab, ap = app_ack(raw)
    variants = {"original": original, "eight_record_base": pefile.PE(data=bb), "count_ack": pefile.PE(data=ab)}
    constructors = [dict(variant=label, trace=singleton_case(pe, allocation, mapping, view, heap))
                    for label, pe in variants.items()
                    for allocation, mapping, view, heap in ((True, True, True, True), (False, True, True, True),
                                                          (True, False, True, True), (True, True, False, True),
                                                          (True, True, True, False), (True, True, True, "first"),
                                                          (True, True, True, "second"), (True, True, True, "third"))]
    destructors = [dict(variant=label, trace=destructor(pe, singleton, deleting))
                   for label, pe in variants.items() for singleton in (False, True) for deleting in (0, 1)]
    consumers = [dict(variant=label, trace=missing_shared_copy(pe, failure))
                 for label, pe in variants.items() for failure in ("mapping", "view")]
    asm = (ROOT / "analysis/disassembly/AppMain.exe.asm").read_text(encoding="utf-8")
    edges = [line for line in asm.splitlines() if re.match(r"[0-9a-f]{8}\s+jal\s+0x(?:110478|1102a8|1103a4)\b", line)]
    table = original.get_data(0x176b18 - original.OPTIONAL_HEADER.ImageBase, 4)
    result = dict(status="CBtData original allocation/mapping and destructor fault paths reproduced; live reachability open",
                  native_execution=False, executable_written=False, unit_tested=False, build_allowed=False,
                  sources=src, core_source=core_source, core_memset_cases=memset_cases,
                  vtable=dict(va="0x176b18", bytes_hex=table.hex(), target="0x1102a8"),
                  constructor_cases=constructors, destructor_cases=destructors, missing_shared_copy_cases=consumers,
                  original_direct_edges=edges, base_variant_sha256=bp["draft_sha256"], ack_variant_sha256=ap["draft_sha256"],
                  limitations=["Heap, mapping and close/free are fixtures; no CE, physical memory exhaustion or unit execution",
                               "Large successful memset calls logged as intervals; record/cache span written in fixture RAM; NULL memset executes pinned ROM bytes up to first store",
                               "Recursive path stops at fourth destructor entry; no claim of completed unwind or actual stack exhaustion",
                               "No live destructor caller reachability or shutdown frequency proven; original table/indirect self route interpreted",
                               "Nonempty copy count is injected after native mapping failure; actual later IPC producer/scheduling remain open",
                               "Other objects, failed heap consumers, mapping retry/recovery and complete allocation lifetime remain open"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in
                                ("verify_bt_data_lifecycle.py", "verify_bt_pairing_ui.py", "verify_bt_database_io.py",
                                 "verify_bt_pairing_storage.py", "verify_bt_pairing_confirmation.py", "draft_bt_pairing_storage.py",
                                 "draft_bt_list_ack.py", "draft_bt_database_io.py", "inspect_bt_pairing.py", "inspect_bt_playback.py",
                                 "inspect_wave_queue.py", "inspect_bt_lifecycle.py", "patch_bt_playback.py")})
    out = ROOT / "analysis/firmware/bt-data-lifecycle"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(constructors=len(constructors), destructors=len(destructors), missing_shared_consumers=len(consumers), core_memset_cases=len(memset_cases),
                         direct_edges=len(edges), status=result["status"]), indent=2))


if __name__ == "__main__": main()
