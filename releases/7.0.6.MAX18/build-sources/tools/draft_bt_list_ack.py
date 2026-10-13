"""Separate in-memory list-refresh acknowledgement prototype.

Layers over the pinned eight-slot draft; never writes a PE or enables packaging.
Mode two opts into raw receiver-LRESULT; all inventoried callers used mode one.
"""
import hashlib
import pefile
from draft_bt_pairing_storage import draft_blue_storage, draft_app_pairing
from draft_bt_database_io import assemble_io

ACK = 0x4c530000
BASE_BLUE = "0b995d157cc7e48bb1a74ecab8bc307f37c8f54a7cc5f686231e7237b0148f45"
BASE_APP = "7a44ab13a6a1ce38bf7565d6c22d6a62dd41b2b95713e2578bbc3df2527276ea"


def apply_blocks(raw, base, blocks, expected):
    assert hashlib.sha256(base).hexdigest() == expected
    pe = pefile.PE(data=base); out = bytearray(base); edits = []
    for start, end, code, reason in blocks:
        replacement, assembly = assemble_io(code, start, end)
        at = pe.get_offset_from_rva(start - pe.OPTIONAL_HEADER.ImageBase)
        out[at:at + len(replacement)] = replacement
        edits.append(dict(va=hex(start), offset=hex(at), bytes=len(replacement),
                          before_hex=base[at:at + len(replacement)].hex(), after_hex=replacement.hex(),
                          original_hex=raw[at:at + len(replacement)].hex(), reason=reason, assembly=assembly))
    spans = sorted((int(e["offset"], 16), int(e["offset"], 16) + e["bytes"]) for e in edits)
    assert all(b <= c for (a, b), (c, d) in zip(spans, spans[1:]))
    assert len(out) == len(base)
    other = pefile.PE(data=bytes(out))
    assert [s.get_data() for s in pe.sections if s.Name.rstrip(b"\0") == b".pdata"] == [
        s.get_data() for s in other.sections if s.Name.rstrip(b"\0") == b".pdata"]
    return bytes(out), dict(source_sha256=hashlib.sha256(raw).hexdigest(), base_sha256=expected,
                           draft_sha256=hashlib.sha256(out).hexdigest(), edits=edits,
                           native_execution=False, executable_written=False, build_allowed=False)


def blue_ack(raw):
    base, _ = draft_blue_storage(raw)
    return apply_blocks(raw, base, [
        (0x2fee8, 0x2ff1c, """
            beqz v0, 0x2ff1c
            lw a0, -0x1e18(s1)
            jal 0x3184c
            addiu a0, a0, 0x10
            move s0, v0
            lui a1, 0x401
            ori a1, a1, 0x702
            move a2, s0
            addiu a0, zero, 2
            jal 0x337dc
            move a3, s0
            lui v0, 0x4c53
            or v0, v0, s0
        """, "Return signed list-count acknowledgement only after successful reload; notification failure does not erase read status"),
        (0x311a8, 0x311c0, """
            move v0, zero
            lw s1, 0x10(sp)
            lw s0, 0x14(sp)
            lw ra, 0x18(sp)
            jr ra
            addiu sp, sp, 0x20
        """, "Normal GUI dispatcher paths still return zero; special list exit skips that normalization"),
        (0x30fa4, 0x30fac, "b 0x311ac\nnop", "Preserve list acknowledgement through GUI dispatch"),
        (0x31708, 0x31718, """
            move v0, zero
            lw ra, 0x10(sp)
            jr ra
            addiu sp, sp, 0x18
        """, "Normalize other module returns; module-one exit preserves reviewed GUI-dispatch status"),
        (0x31698, 0x316a0, "b 0x3170c\nnop", "Preserve module-one return without changing frame or saved RA"),
        (0x33de8, 0x33dec, "move v0, zero", "Unhandled ordinary packet IDs retain zero return"),
        (0x33e10, 0x33e18, "beqz a0, 0x33f6c\nnop", "Payload-free ordinary packet preserves dispatcher status; payload cleanup path retains zero")
    ], BASE_BLUE)


def app_ack(raw):
    base, _ = draft_app_pairing(raw)
    blocks = [
        (0x11b4bc, 0x11b4c0, "sw a1, 0x24(sp)", "Capture explicit opt-in mode in an unused local; inventoried legacy callers all pass one"),
        (0x11b4e4, 0x11b5a8, """
            addiu s3, s1, 4
            sw zero, 0x20(sp)
            move a0, s3
            jal 0x1144b4
            addiu a1, zero, 1
            lw a0, 0(v0)
            lw t0, 0x14(s1)
            addiu t1, t0, -1
            beqz t1, send_first
            ori a1, zero, 0x8065
            ori t1, zero, 0x806e
            addu a1, t0, t1
        send_first:
            move s4, a1
            addiu t2, zero, 0x5dc
            sw t2, 0x14(sp)
            addiu t2, sp, 0x20
            sw t2, 0x18(sp)
            sw zero, 0x10(sp)
            move a2, s0
            jal 0x1400a8
            move a3, s2
            bnez v0, success
            lui t0, 0x18
            lw t0, 0x5020(t0)
            jalr t0
            nop
            addiu t1, zero, 0x578
            bne v0, t1, failed
            sw zero, 0x20(sp)
            sw zero, 4(s3)
            move a0, s3
            jal 0x1144b4
            addiu a1, zero, 1
            lw a0, 0(v0)
            move a1, s4
            move a2, s0
            jal 0x1400a8
            move a3, s2
            beqz v0, failed
            nop
        success:
            lw t0, 0x24(sp)
            addiu t1, zero, 2
            bne t0, t1, success_other
            lw v0, 0x20(sp)
            b 0x11b5a8
            nop
        success_other:
            b 0x11b5a8
            move v0, zero
        failed:
            addiu v0, zero, -1
        """, "Opt-in mode two returns actual LRESULT; normal mode retains zero-success/-1-failure and retry-ID semantics"),
        (0x11f9a4, 0x11f9a8, "addiu a1, zero, 2", "Only HFP list request opts into receiver acknowledgement"),
        (0x11f9b0, 0x11f9d8, """
            addiu t2, zero, -1
            sw t2, 0x44(sp)
            srl t0, v0, 16
            addiu t1, zero, 0x4c53
            bne t0, t1, 0x11f9d8
            andi t0, v0, 0xffff
            sltiu t1, t0, 9
            beqz t1, 0x11f9d8
            sw t0, 0x48(sp)
            sw zero, 0x44(sp)
        """, "Validate signature and count zero through eight; no Sleep after synchronous completed acknowledgement"),
        (0x11fa60, 0x11fb0c, """
            lw s0, 0x7be4(s6)
            lw t0, 0xa8(s0)
            sw s2, 0x4c(t0)
            lw t0, 0x7b38(s7)
            sw zero, 0x22e0(t0)
            lui a0, 0x8000
            lui t0, 0x17
            move a3, zero
            addiu a2, t0, 0x4be4
            addiu a1, t0, 0x4bf8
            jal 0x137d84
            ori a0, a0, 2
            lw t0, 0xa8(s0)
            sw zero, 0x180(t0)
        hf_copy_gate:
            lw s0, 0x7be4(s6)
            lw t0, 0x44(sp)
            bnez t0, hf_list_failed
            lw t0, 0xa0(s0)
            lw t1, 0x48(sp)
            sw t1, 0x26c(t0)
            jal 0x110708
            lw a0, 0xa0(s0)
            jal 0x111d84
            lw a0, 0xa0(s0)
            jal 0x111364
            lw a0, 0xa0(s0)
            lw t0, 0xa0(s0)
            lw t1, 0x5ac(t0)
            lw t0, 0xa8(s0)
            sltu t1, zero, t1
            b 0x11fb0c
            sw t1, 0x664(t0)
        hf_list_failed:
            addiu t1, zero, -1
            sw t1, 0x5a4(t0)
            sw zero, 0x5c0(t0)
            sw zero, 0x5ac(t0)
            lw t0, 0xa8(s0)
            b 0x11fb0c
            sw zero, 0x664(t0)
        hf_existing_entry:
            b hf_copy_gate
            nop
        """, "Apply acknowledged count before native copy/phonebook; logical failure keeps HFP but invalidates stale active/PB references"),
        (0x111d98, 0x111df0, """
            move s1, a0
            move s0, zero
            lw s2, 0x26c(s1)
            addiu t0, s2, -1
            sltiu t0, t0, 8
            beqz t0, scan_failed
            lw t2, 0xc(s1)
            beqz t2, scan_failed
            sll t0, s0, 6
        scan_loop:
            addu v0, t2, t0
            lhu t0, 0(v0)
            bnez t0, scan_found
            addiu s0, s0, 1
            bne s0, s2, scan_loop
            sll t0, s0, 6
        scan_failed:
            addiu t0, zero, -1
            sw t0, 0x5a4(s1)
            b 0x111df0
            sw zero, 0x5c0(s1)
        scan_found:
            addiu s0, s0, -1
            sw v0, 0x5c0(s1)
            sw s0, 0x5a4(s1)
        """, "Bound active scan to count one through eight; clear stale pointers on empty/invalid/NULL or no active record")
    ]
    result, metadata = apply_blocks(raw, base, blocks, BASE_APP)
    entry = next(e for e in metadata["edits"] if e["va"] == "0x11fa60")
    assert entry["assembly"]["labels"]["hf_existing_entry"] == "0x11fafc"
    return result, metadata
