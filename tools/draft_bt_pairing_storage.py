"""Memory-only eight-record storage draft for pinned original Blue.exe.

This is deliberately not connected to the LGU builder. UI and full stack paths
still need validation. No output executable, native call or device write.
"""
import hashlib
import struct

import pefile
from inspect_bt_playback import BLUE_HASH
from patch_bt_playback import assemble
from draft_bt_database_io import apply_database_io, assemble_io

BANK = 0x300
PAIRS = 8
RECORD_BYTES = 104
SINGLE_BYTES = BANK + PAIRS * RECORD_BYTES
MANAGER_BYTES = SINGLE_BYTES + 0x10
DELETE_FRAME = 0x3d0
APP_HASH = "6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8"

RELOAD = """
    move s2, a0
    addiu a0, sp, 0x18
    jal 0x3ac50
    move s1, a1
    addiu s0, s2, 0x300
    move a0, s0
    addiu a1, zero, 0
    jal 0x3a750
    addiu a2, zero, 0x340
    move a0, s0
    jal 0x7a8a8
    addiu a1, zero, 8
    beqz v0, failed
    nop
    beqz s1, begin_list
    nop
    move a0, s1
    jal 0x3ac90
    addiu a1, sp, 0x18
    bnez v0, begin_list
    move a0, s2
    jal 0x31c84
    move a1, s1
    beqz v0, failed
    move a0, s0
    jal 0x7a974
    addiu a1, zero, 8
    beqz v0, failed
    nop
begin_list:
    move s1, zero
next_record:
    move a0, s0
    jal 0x3ac90
    addiu a1, sp, 0x18
    bnez v0, publish_count
    nop
    addiu s1, s1, 1
    move a0, s2
    move a1, s1
    move a2, s0
    addiu a3, s0, 0x1a
    lw t0, 0x50(s0)
    jal 0x32f00
    sw t0, 0x10(sp)
    sltiu t0, s1, 8
    bnez t0, next_record
    addiu s0, s0, 0x68
publish_count:
    lui t0, 0x21
    lw t0, -0x1e18(t0)
    sb s1, 0x14(t0)
    sb s1, 0x15(t0)
    addiu a0, zero, 2
    lui a1, 0x401
    ori a1, a1, 0x702
    move a2, s1
    jal 0x337dc
    move a3, s1
    b 0x3317c
    addiu v0, zero, 1
failed:
    move v0, zero
"""


def draft_blue_storage(raw):
    assert hashlib.sha256(raw).hexdigest() == BLUE_HASH
    pe = pefile.PE(data=raw)
    out = bytearray(raw)
    edits = []

    def immediate(va, old, new, op, reason):
        offset = pe.get_offset_from_rva(va - pe.OPTIONAL_HEADER.ImageBase)
        before = struct.unpack_from("<I", raw, offset)[0]
        assert before >> 26 == op and before & 0xffff == old & 0xffff, hex(va)
        assert -32768 <= new <= 65535
        after = (before & 0xffff0000) | (new & 0xffff)
        struct.pack_into("<I", out, offset, after)
        edits.append(dict(va=hex(va), offset=hex(offset), before_hex=struct.pack("<I", before).hex(),
                          after_hex=struct.pack("<I", after).hex(), reason=reason))

    # A new bank at the allocation tail leaves all original member offsets intact.
    for va, old, new in [(0x2e710, 0x2e8, MANAGER_BYTES), (0x2e714, 0x2e8, MANAGER_BYTES),
                         (0x32eb4, 0x250, SINGLE_BYTES), (0x317ac, 0x20, BANK),
                         (0x317b0, 0x208, PAIRS * RECORD_BYTES)]:
        immediate(va, old, new, 9, "Expand both allocation paths and initialize relocated database bank")
    for va in (0x31cd0, 0x31d1c, 0x31d64):
        immediate(va, 0x20, BANK, 9, "Use relocated bank in reload and move-to-front")
    immediate(0x31cf0, 4, 7, 0xa, "Search first seven slots; fallback shifts at most seven predecessors")
    replacement, _ = assemble(RELOAD, 0x33090, 0x3317c)
    offset = pe.get_offset_from_rva(0x33090 - pe.OPTIONAL_HEADER.ImageBase)
    out[offset:offset + len(replacement)] = replacement
    edits.append(dict(va="0x33090", offset=hex(offset), before_hex=raw[offset:offset + len(replacement)].hex(),
                      after_hex=replacement.hex(), bytes=len(replacement),
                      reason="Clear eight-record bank before reload; preserve old short databases and check reorder write status"))

    # Preserve every saved register and the GS cookie at its old caller-SP offset.
    delta = DELETE_FRAME - 0x298
    immediate(0x7aa40, -0x298, -DELETE_FRAME, 9, "Larger delete frame for eight records")
    immediate(0x7ab48, 0x298, DELETE_FRAME, 9, "Restore matching caller stack")
    for va, old, op in [(0x7aa44, 0x294, 43), (0x7aa48, 0x288, 43),
                        (0x7aa4c, 0x28c, 43), (0x7aa50, 0x290, 43),
                        (0x7aa60, 0x280, 43), (0x7ab30, 0x280, 35),
                        (0x7ab34, 0x288, 35), (0x7ab38, 0x28c, 35),
                        (0x7ab3c, 0x290, 35), (0x7ab40, 0x294, 35)]:
        immediate(va, old, old + delta, op, "Keep caller-SP-relative GS cookie and saved-register positions")
    # Replace the initialization/read block in-place. Its old 104-byte empty
    # address temporary only needs its first eight BDADDR bytes initialized.
    # The freed instructions permit a read-result and index check before writes.
    start, end = 0x7aa64, 0x7aa98
    replacement, _ = assemble("""
        sw zero, 0x10(sp)
        sw zero, 0x14(sp)
        addiu a0, sp, 0x78
        addiu a1, zero, 0
        jal 0x3a750
        addiu a2, zero, 0x340
        addiu a0, sp, 0x78
        jal 0x7a8a8
        addiu a1, zero, 8
        beqz v0, 0x7ab2c
        sltiu t0, s0, 8
        beqz t0, 0x7ab2c
        nop
    """, start, end)
    offset = pe.get_offset_from_rva(start - pe.OPTIONAL_HEADER.ImageBase)
    out[offset:offset + len(replacement)] = replacement
    edits.append(dict(va=hex(start), offset=hex(offset), before_hex=raw[offset:offset + len(replacement)].hex(),
                      after_hex=replacement.hex(), bytes=len(replacement),
                      reason="Zero enlarged delete buffer; skip write on failed read or out-of-range index"))
    immediate(0x7ab20, 5, PAIRS, 9, "Write eight records during deletion")
    immediate(0x7aa98, 4, 7, 9, "Recognize last slot index seven")
    immediate(0x7aaa8, 0x218, 0x78 + 7 * RECORD_BYTES, 9, "Clear last record inside enlarged frame")
    for va in (0x7aab0, 0x7aaf4):
        immediate(va, 5, PAIRS, 0xa, "Compact through eight slots")
    # Media slot eight ends exactly at 0x500, before the search bank starts.
    immediate(0x345c0, 0x500, 0x501, 0xa, "Accept complete final media slot, retain exclusion of slot nine")
    # A failed reload must not be followed by a second notification claiming
    # that the old count/shared bank is a refreshed list. Retain both count
    # getter calls; the reviewed leaf only modifies v0, keeping a0/a3 valid.
    start, end = 0x2fee8, 0x2ff1c
    replacement, _ = assemble("""
        beqz v0, 0x2ff1c
        lui t0, 0x21
        lw a0, -0x1e18(t0)
        jal 0x3184c
        addiu a0, a0, 0x10
        move a3, v0
        jal 0x3184c
        nop
        move a2, v0
        lui a1, 0x401
        ori a1, a1, 0x702
        jal 0x337dc
        addiu a0, zero, 2
    """, start, end)
    offset = pe.get_offset_from_rva(start - pe.OPTIONAL_HEADER.ImageBase)
    out[offset:offset + len(replacement)] = replacement
    edits.append(dict(va=hex(start), offset=hex(offset), before_hex=raw[offset:offset + len(replacement)].hex(),
                      after_hex=replacement.hex(), bytes=len(replacement),
                      reason="Skip stale list-count notification after failed database reload; preserve valid-list notifications"))
    apply_database_io(raw, pe, out, edits)

    assert len(out) == len(raw) and len({e["va"] for e in edits}) == len(edits)
    changed = [i for i, (a, b) in enumerate(zip(raw, out)) if a != b]
    assert all(any(int(e["offset"], 16) <= i < int(e["offset"], 16) + e.get("bytes", 4) for e in edits) for i in changed)
    patched_pe = pefile.PE(data=bytes(out))
    assert patched_pe.FILE_HEADER.Machine == pe.FILE_HEADER.Machine == 0x166
    assert [s.get_data() for s in patched_pe.sections if s.Name.rstrip(b"\0") == b".pdata"] == [
        s.get_data() for s in pe.sections if s.Name.rstrip(b"\0") == b".pdata"]
    return bytes(out), dict(status="memory-only storage draft; not approved for LGU builder",
        source_sha256=BLUE_HASH, draft_sha256=hashlib.sha256(out).hexdigest(),
        executable_written=False, native_execution=False, build_allowed=False,
        edits=edits, changed_bytes=len(changed),
        changed_instruction_words=sum(raw[i:i + 4] != out[i:i + 4] for i in range(0, len(raw), 4)), bank_offset=hex(BANK),
        record_bytes=RECORD_BYTES, slots=PAIRS, singleton_allocation=SINGLE_BYTES,
        manager_allocation=MANAGER_BYTES, delete_frame=DELETE_FRAME,
        limitations=["AppMain record/name banks and UI limits remain unchanged",
                     "Physical radio capacity, locks, file APIs and atomic/interrupted-write recovery not verified",
                     "No composed playback/pairing update has been built"])


def draft_app_pairing(raw):
    """Explore reuse of the apparently write-only name cache for three records.

    Direct-reference audit and copy fixtures do not prove absence of indirect
    cache readers. This draft remains excluded from packaging for that reason.
    """
    assert hashlib.sha256(raw).hexdigest() == APP_HASH
    pe = pefile.PE(data=raw)
    out, edits = bytearray(raw), []

    def instruction(va, old_imm, new_imm, reason):
        at = pe.get_offset_from_rva(va - pe.OPTIONAL_HEADER.ImageBase)
        before = struct.unpack_from("<I", raw, at)[0]
        assert before >> 26 in (9, 10, 11) and before & 65535 == old_imm
        after = (before & 0xffff0000) | new_imm
        struct.pack_into("<I", out, at, after)
        edits.append(dict(va=hex(va), offset=hex(at), before_hex=struct.pack("<I", before).hex(),
                          after_hex=struct.pack("<I", after).hex(), reason=reason))

    for va, reason in [
        (0x20618, "Active-record index bound"), (0x20650, "Active-record index bound"),
        (0x2077c, "Add-device full-list gate"), (0xb9634, "Active-record index bound"),
        (0xb966c, "Active-record index bound"), (0xb9754, "Add-device full-list gate"),
        (0xb9c78, "Pairing entry full-list gate"), (0xd064c, "Rendered active-record status bound"),
        (0xd06b8, "Rendered active-record status bound"), (0xd07c8, "Displayed total clamp comparison"),
        (0xd07dc, "Displayed total clamp value"), (0xd28f0, "Full-list duplicate-selection gate"),
        (0xd2970, "Check all eight saved names before full-list selection"),
        (0xd2eb0, "Add-device full-list gate"), (0xd2ee0, "Full-list warning gate"),
        (0x1108ac, "Copy/clear eight records"),
        (0x111dd4, "Search all eight shared records for the active device"),
    ]:
        instruction(va, 5, PAIRS, reason)
    instruction(0x11e0cc, 6, PAIRS + 1, "Keep the autoconnect-abort sentinel outside the expanded attempt bank")
    for va, expected in [(0x110820, 0x0100f809), (0x110824, 0xafb50010)]:
        at = pe.get_offset_from_rva(va - pe.OPTIONAL_HEADER.ImageBase)
        assert struct.unpack_from("<I", raw, at)[0] == expected
        out[at:at + 4] = bytes(4)
        edits.append(dict(va=hex(va), offset=hex(at), before_hex=raw[at:at + 4].hex(),
                          after_hex="00000000", reason="Omit unused cached-name conversion that overlaps enlarged record bank"))
    # Mode zero uses zero-based display indices; the only direct mode-one caller
    # uses one-based delete indices. Normalize before checking the record bound.
    start, end = 0x1109fc, 0x110b14
    replacement, manifest = assemble_io("""
        lw t1, 0x26c(a0)
        beqz s2, bounds
        nop
        addiu a1, a1, -1
    bounds:
        sltu t2, a1, t1
        beqz t2, 0x110b14
        nop
        sll t0, a1, 6
        addu s1, t0, a0
        bnez s2, address
        addiu a2, s1, 0x27c
        move t3, a2
    scan:
        lbu t1, 0(t3)
        bnez t1, scan
        addiu t3, t3, 1
        subu t0, t3, a2
        addiu t2, t0, -1
        beqz t2, address
        nop
        b convert
        nop
    address:
        addiu a2, zero, 0x31
        move a1, zero
        addiu a0, sp, 0x19
        jal 0x140de4
        sb zero, 0x18(sp)
        lhu a3, 0x27a(s1)
        lbu t1, 0x278(s1)
        lw t0, 0x274(s1)
        lui a2, 0x17
        addiu a2, a2, 0x6828
        beqz s2, format
        nop
        addiu a2, a2, 0x10
    format:
        addiu a1, zero, 0x32
        addiu a0, sp, 0x18
        sw t0, 0x14(sp)
        jal 0x1406d4
        sw t1, 0x10(sp)
        addiu a2, sp, 0x18
    convert:
        lui t0, 0x18
        lw t0, 0x5088(t0)
        addiu t1, zero, 0x32
        addiu a3, zero, 0x32
        addiu a1, zero, 8
        ori a0, zero, 0xfde9
        sw t1, 0x14(sp)
        jalr t0
        sw s0, 0x10(sp)
        b 0x110b30
        nop
    """, start, end)
    at = pe.get_offset_from_rva(start - pe.OPTIONAL_HEADER.ImageBase)
    out[at:at + len(replacement)] = replacement
    edits.append(dict(va=hex(start), offset=hex(at), bytes=len(replacement),
                      before_hex=raw[at:at + len(replacement)].hex(), after_hex=replacement.hex(),
                      reason="Normalize one-based delete address indices before bounds check; do not scan the next record name", assembly=manifest))
    # Preserve zero-success / -1-failure ABI, while retaining the first message
    # ID for retries. Do not equate an OS transport success with radio success.
    start, end = 0x11b4e4, 0x11b5a8
    replacement, manifest = assemble_io("""
        addiu s3, s1, 4
        move a0, s3
        jal 0x1144b4
        addiu a1, zero, 1
        lw a0, 0(v0)
        lw t0, 0x14(s1)
        addiu t1, zero, 1
        bne t0, t1, other_id
        sw zero, 0x20(sp)
        b send_first
        ori a1, zero, 0x8065
    other_id:
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
        nop
        lui t0, 0x18
        lw t0, 0x5020(t0)
        jalr t0
        nop
        addiu t1, zero, 0x578
        bne v0, t1, failed
        nop
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
        b 0x11b5a8
        move v0, zero
    failed:
        addiu v0, zero, -1
    """, start, end)
    at = pe.get_offset_from_rva(start - pe.OPTIONAL_HEADER.ImageBase)
    out[at:at + len(replacement)] = replacement
    edits.append(dict(va=hex(start), offset=hex(at), bytes=len(replacement),
                      before_hex=raw[at:at + len(replacement)].hex(), after_hex=replacement.hex(),
                      reason="Return -1 on failed OS sends; retain the selected message ID on the timeout retry", assembly=manifest))
    # Keep state ordering before the synchronous transport call. On failure,
    # stop before creating a progress popup or issuing the connect command.
    caller_blocks = [(0x115988, 0x1159c8, """
        lw t0, 0xa8(s2)
        move a0, s2
        jal 0x11a8f4
        sw s6, 0x5fc(t0)
        bnez v0, reset_failed
        lw t0, 0xa8(s2)
        sw zero, 0x90(s2)
        sw zero, 0x650(t0)
        b 0x1159c8
        nop
    reset_failed:
        sw zero, 0x5fc(t0)
        sw zero, 0x624(t0)
        b 0x115ed0
        nop
    """, "Stop after failed key-reset transport; clear pending selection without creating progress UI"),
    (0x115e60, 0x115ed0, """
        lui t1, 0x18
        lw t0, 0x6ce8(t1)
        lw a0, 4(t0)
        jal 0x13fef8
        addiu a1, zero, 0x417
        lw t0, 0xa8(s2)
        addiu s0, s0, 1
        addiu t1, zero, 1
        sw t1, 0x17c(t0)
        sw zero, 0x5ac(t0)
        sw s0, 0x5a8(t0)
        lw a0, 0xa4(s2)
        lui a2, 0x101
        ori a2, a2, 0x804
        move a3, s0
        jal 0x11b464
        addiu a1, zero, 1
        beqz v0, 0x115ed0
        lw t0, 0xa8(s2)
        sw zero, 0x17c(t0)
        sw zero, 0x5a8(t0)
        sw zero, 0x5ac(t0)
        sw zero, 0x5fc(t0)
        sw zero, 0x698(t0)
        jal 0x12c10
        nop
        jal 0x130a70
        move a0, v0
    """, "On failed connect transport clear pending state and invoke the progress popup's original close method"),
    (0x132b7c, 0x132c3c, """
        lui s0, 0x18
        lw t0, 0x7be4(s0)
        lw t1, 0xa8(t0)
        lw s1, 0x5a4(t1)
        sltiu t2, s1, 8
        beqz t2, auto_done
        lw t3, 0xa0(t0)
        lw t3, 0x26c(t3)
        sltiu t2, t3, 9
        beqz t2, auto_done
        addiu s1, s1, 1
        sltu t2, t3, s1
        bnez t2, auto_done
        sw s1, 0x5a4(t1)
        lw t2, 0x618(t1)
        addiu t3, zero, 1
        beq t2, t3, auto_done
        nop
        lw t0, 0x6ce8(s0)
        lw a0, 4(t0)
        jal 0x13fef8
        addiu a1, zero, 0x416
        lw t0, 0x7be4(s0)
        lw a0, 0xa4(t0)
        lui a2, 0x101
        ori a2, a2, 0x804
        move a3, s1
        jal 0x11b464
        addiu a1, zero, 1
        bnez v0, auto_done
        lw t0, 0x6ce8(s0)
        lw a0, 4(t0)
        addiu a2, zero, 0x61a8
        move a3, zero
        jal 0x13ff08
        addiu a1, zero, 0x416
        bnez v0, 0x1347ac
        nop
    auto_done:
        lw t0, 0x6ce8(s0)
        lw a0, 4(t0)
        jal 0x13fef8
        addiu a1, zero, 0x416
        lw t0, 0x7be4(s0)
        lw a0, 0xa4(t0)
        jal 0x127654
        move a1, zero
        b 0x132c3c
        nop
    """, "Bound timer-416 attempts to eight records; stop on failed send or timer creation and preserve the dialog-list register"),
    (0x132d38, 0x132ec8, """
        lw t6, 0x5a8(t5)
        lw t0, 0x618(t5)
        addiu t1, zero, 1
        beq t0, t1, fallback_done
        lw t4, 0x5ac(t5)
        lw t0, 0xa0(t3)
        lw t7, 0x26c(t0)
        addiu t0, t7, -1
        sltiu t0, t0, 8
        beqz t0, fallback_done
        nop
        addiu t0, t6, -1
        sltu t0, t0, t7
        beqz t0, fallback_done
        nop
        sltu t0, t7, t4
        bnez t0, fallback_done
        nop
        beq t4, t6, fallback_done
        nop
        bnez t4, fallback_next
        move s1, t4
        move s1, t6
    fallback_next:
        addiu s1, s1, 1
        sltu t0, t7, s1
        beqz t0, fallback_check
        nop
        addiu s1, zero, 1
    fallback_check:
        beq s1, t6, fallback_done
        nop
        sw s1, 0x5ac(t5)
        lw a0, 0xa4(t3)
        lui a2, 0x101
        ori a2, a2, 0x804
        move a3, s1
        jal 0x11b464
        addiu a1, zero, 1
        bnez v0, fallback_done
        nop
        lw t0, 0x6ce8(s2)
        lw a0, 4(t0)
        addiu a2, zero, 0x61a8
        move a3, zero
        jal 0x13ff08
        addiu a1, zero, 0x417
        bnez v0, 0x1347ac
        nop
    fallback_done:
        lw t0, 0x7be4(s3)
        lw a0, 0xa4(t0)
        jal 0x127654
        move a1, zero
        lw t0, 0x7be4(s3)
        lw t0, 0xa8(t0)
        sw zero, 0x17c(t0)
        sw zero, 0x5a8(t0)
        sw zero, 0x5ac(t0)
        sw zero, 0x5fc(t0)
        sw zero, 0x698(t0)
        jal 0x12c10
        nop
        jal 0x130a70
        move a0, v0
        b 0x1347ac
        nop
    """, "Timer-417 cyclically attempts every other saved index once, then clears progress; stop on failed send or timer creation"),
    (0x11f9b0, 0x11f9d8, """
        sw v0, 0x44(sp)
        bnez v0, 0x11f9d8
        nop
        lui t0, 0x18
        lw t0, 0x503c(t0)
        jalr t0
        addiu a0, zero, 0x12c
        b 0x11f9d8
        nop
    """, "Preserve the HF-success list-request transport result in the existing descriptor local; skip waiting after failure"),
    (0x11fa60, 0x11fb0c, """
        lw s0, 0x7be4(s6)
        lw t0, 0xa8(s0)
        sw s2, 0x4c(t0)
        lw t0, 0x7b38(s7)
        sw zero, 0x22e0(t0)
        lui a0, 0x8000
        lui t0, 0x17
        lui t1, 0x17
        move a3, zero
        addiu a2, t0, 0x4be4
        addiu a1, t1, 0x4bf8
        jal 0x137d84
        ori a0, a0, 2
        lw t0, 0xa8(s0)
        sw zero, 0x180(t0)
    hf_copy_gate:
        lw s0, 0x7be4(s6)
        lw t0, 0x44(sp)
        bnez t0, hf_list_failed
        nop
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
        lw t0, 0xa0(s0)
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
    """, "Keep HFP connected on list-request failure but invalidate stale active/phonebook references; retain the existing alternate copy entry")]
    for start, end, code, reason in caller_blocks:
        replacement, manifest = assemble_io(code, start, end)
        if start == 0x11fa60:
            assert manifest["labels"]["hf_existing_entry"] == "0x11fafc"
        at = pe.get_offset_from_rva(start - pe.OPTIONAL_HEADER.ImageBase)
        out[at:at + len(replacement)] = replacement
        edits.append(dict(va=hex(start), offset=hex(at), bytes=len(replacement),
                          before_hex=raw[at:at + len(replacement)].hex(), after_hex=replacement.hex(),
                          reason=reason, assembly=manifest))
    assert len(out) == len(raw) and len({e["va"] for e in edits}) == len(edits)
    changed = [i for i, (a, b) in enumerate(zip(raw, out)) if a != b]
    assert all(any(int(e["offset"], 16) <= i < int(e["offset"], 16) + e.get("bytes", 4) for e in edits) for i in changed)
    patched_pe = pefile.PE(data=bytes(out))
    assert [s.get_data() for s in patched_pe.sections if s.Name.rstrip(b"\0") == b".pdata"] == [
        s.get_data() for s in pe.sections if s.Name.rstrip(b"\0") == b".pdata"]
    return bytes(out), dict(status="memory-only UI draft; indirect cache readers still require audit",
        source_sha256=APP_HASH, draft_sha256=hashlib.sha256(out).hexdigest(), edits=edits,
        build_allowed=False, executable_written=False, native_execution=False,
        changed_bytes=sum(a != b for a, b in zip(raw, out)),
        changed_instruction_words=sum(raw[i:i + 4] != out[i:i + 4] for i in range(0, len(raw), 4)),
        record_bank_start="0x270", record_bank_end="0x470",
        preserved=["Original object allocation and fields from +5a4 onward", "Four physical rows and page reset below five"],
        limitations=["No proof yet that converted-name cache lacks indirect readers",
                     "Paired copy/list/page clicks and popup parameters covered; confirmation and full reconnect paths remain open",
                     "No unit or native tests; not connected to LGU builder"])
