"""Internal MIPS prototype for post-restart copy safety. Never execute firmware.

Retain staging/backup, verify copied bytes, publish version last, fail closed on
ambiguous prior settings scan. This is not a transactional OS/MCU flash repair.
"""
import hashlib
import struct
import pefile
from draft_bt_database_io import assemble_io

BASE = 0x10000
TEXT, TEXT_BYTES, DATA, DATA_BYTES = 0x3d000, 0x3000, 0x41000, 0x5000
COPY, TREE, ERROR, STOP = 0x3d000, 0x3d800, 0x3e200, 0x3e400
STAGE, BACKUP, RESTORE, AMBIGUOUS = 0x3e700, 0x3ea00, 0x3ec00, 0x3ee00
PAINT, STARTUP, DIRECTORY = 0x3ef00, 0x3f200, 0x3f500
MOUNT, FORMAT = 0x3f800, 0x3fa00
CODE, PATH, BODY = DATA, DATA + 4, DATA + 0x400
STRINGS = {
    "version_source": "\\Storage Card3\\upgrade\\Storage Card\\System\\Version_Info.txt",
    "version_target": "\\Storage Card\\System\\Version_Info.txt",
    "marker_name": "filecopy_success.bin", "version_name": "Version_Info.txt",
    "stage": "\\Storage Card3\\upgrade", "receipt": "\\Storage Card3\\upgrade\\filecopy_success.bin",
    "scan": "\\Storage Card2\\scan_done_flag.bin", "backup": "\\Storage Card3\\TFAT",
    "card1": "\\Storage Card", "card2": "\\Storage Card2", "card4": "\\Storage Card4",
    "card3": "\\Storage Card3", "format_error": "Installation stopped (error %u).\nFiles retained.\n%s",
    "title": "Installation stopped", "body": "Files retained for recovery.\nError %u\n%s",
}


def ptr(reg, address):
    return f"lui {reg}, {address >> 16}\nori {reg}, {reg}, {address & 65535}"


def api(name, delay="nop"):
    iat = {"copy": 0x370dc, "open": 0x3704c, "read": 0x37054, "size": 0x37050,
           "close": 0x37028, "attrs": 0x3705c, "last": 0x37008,
           "first": 0x3716c, "next": 0x37178, "find_close": 0x37170,
           "mkdir": 0x3717c, "exit": 0x37020}[name]
    return f"{ptr('t8', iat)}\nlw t9, 0(t8)\njalr t9\n{delay}"


def frame(n, regs):
    return "\n".join([f"addiu sp, sp, -{n}", f"sw ra, {n-4}(sp)"] +
                     [f"sw {r}, {n-8-4*i}(sp)" for i, r in enumerate(regs)])


def end(n, regs):
    return "\n".join([f"lw {r}, {n-8-4*i}(sp)" for i, r in enumerate(regs)] +
                     [f"lw ra, {n-4}(sp)", "jr ra", f"addiu sp, sp, {n}"])


def routines(s):
    regs = ["s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7"]
    copy = f"""
{frame(0x2060, regs)}
move s0, a0
move s1, a1
addiu s2, zero, -1
addiu s3, zero, -1
move s7, zero
addiu a2, zero, 0
{api('copy')}
beqz v0, api_failed
nop
move a0, s0
lui a1, 0x8000
addiu a2, zero, 1
addiu a3, zero, 0
addiu t0, zero, 3
sw t0, 0x10(sp)
addiu t0, zero, 0x80
sw t0, 0x14(sp)
sw zero, 0x18(sp)
{api('open')}
move s2, v0
addiu t0, zero, -1
beq s2, t0, api_failed
nop
move a0, s1
lui a1, 0x8000
addiu a2, zero, 1
addiu a3, zero, 0
addiu t0, zero, 3
sw t0, 0x10(sp)
addiu t0, zero, 0x80
sw t0, 0x14(sp)
sw zero, 0x18(sp)
{api('open')}
move s3, v0
addiu t0, zero, -1
beq s3, t0, api_failed
nop
move a0, s2
sw zero, 0x20(sp)
addiu a1, sp, 0x20
{api('size')}
move s4, v0
lw t0, 0x20(sp)
bnez t0, mismatch
nop
addiu t0, zero, -1
beq s4, t0, api_failed
nop
move a0, s3
sw zero, 0x20(sp)
addiu a1, sp, 0x20
{api('size')}
bne v0, s4, mismatch
nop
lw t0, 0x20(sp)
bnez t0, mismatch
nop
move s5, s4
read_block:
move a0, s2
addiu a1, sp, 0x30
addiu a2, zero, 0x1000
addiu a3, sp, 0x20
sw zero, 0x20(sp)
sw zero, 0x10(sp)
{api('read')}
beqz v0, api_failed
nop
lw s6, 0x20(sp)
sltiu t0, s6, 0x1001
beqz t0, mismatch
nop
move a0, s3
addiu a1, sp, 0x1030
addiu a2, zero, 0x1000
addiu a3, sp, 0x24
sw zero, 0x24(sp)
sw zero, 0x10(sp)
{api('read')}
beqz v0, api_failed
nop
lw t0, 0x24(sp)
bne t0, s6, mismatch
nop
beqz s6, eof
nop
sltu t0, s5, s6
bnez t0, mismatch
nop
subu s5, s5, s6
addiu t0, sp, 0x30
addiu t1, sp, 0x1030
compare_bytes:
lbu t2, 0(t0)
lbu t3, 0(t1)
bne t2, t3, mismatch
nop
addiu t0, t0, 1
addiu t1, t1, 1
addiu s6, s6, -1
bnez s6, compare_bytes
nop
b read_block
nop
eof:
bnez s5, mismatch
nop
addiu s7, zero, 1
b close_source
nop
mismatch:
addiu a0, zero, 23
b record
move a1, s0
api_failed:
{api('last')}
move a0, v0
move a1, s0
record:
jal {ERROR}
nop
close_source:
addiu t0, zero, -1
beq s2, t0, close_target
nop
move a0, s2
{api('close')}
bnez v0, close_target
nop
move s7, zero
{api('last')}
move a0, v0
jal {ERROR}
move a1, s0
close_target:
addiu t0, zero, -1
beq s3, t0, done
nop
move a0, s3
{api('close')}
bnez v0, done
nop
move s7, zero
{api('last')}
move a0, v0
jal {ERROR}
move a1, s1
done:
move v0, s7
move v1, s4
{end(0x2060, regs)}
""".replace("\\+", "")
    # CE's inspected find-data has filename +0x28 and sizes +0x1c/+0x20.
    tree = f"""
{frame(0x890, regs)}
move s0, a0
move s1, a1
move s6, a2
move s7, a3
move s5, zero
sltiu t0, s7, 16
beqz t0, depth_failed
nop
move a0, s1
jal {DIRECTORY}
nop
beqz v0, done
nop
addiu a0, sp, 0x660
addiu a1, zero, 260
{ptr('a2', 0x337d0)}
jal 0x2a86c
move a3, s0
# Negative swprintf_s is detected with bit 31, not unsigned less than zero.
srl t0, v0, 31
bnez t0, path_failed
nop
addiu a0, sp, 0x660
addiu a1, sp, 0x20
{api('first')}
move s2, v0
addiu t0, zero, -1
bne s2, t0, item
nop
{api('last')}
addiu t0, zero, 2
beq v0, t0, empty
nop
move a0, v0
jal {ERROR}
move a1, s0
b done
nop
empty:
addiu s5, zero, 1
b done
nop
item:
addiu s3, sp, 0x48
lhu t0, 0(s3)
addiu t1, zero, 46
bne t0, t1, paths
nop
lhu t0, 2(s3)
beqz t0, next
nop
bne t0, t1, paths
nop
lhu t0, 4(s3)
beqz t0, next
nop
paths:
addiu a0, sp, 0x250
addiu a1, zero, 260
{ptr('a2', 0x337fc)}
move a3, s0
jal 0x2a86c
sw s3, 0x10(sp)
srl t0, v0, 31
bnez t0, path_close_failed
nop
addiu a0, sp, 0x458
addiu a1, zero, 260
{ptr('a2', 0x337fc)}
move a3, s1
jal 0x2a86c
sw s3, 0x10(sp)
srl t0, v0, 31
bnez t0, path_close_failed
nop
lw t0, 0x20(sp)
andi t0, t0, 0x10
bnez t0, recurse
nop
beqz s6, copy_file
nop
move a0, s3
{ptr('a1', s['marker_name'])}
jal 0x2a87c
nop
beqz v0, next
nop
move a0, s3
{ptr('a1', s['version_name'])}
jal 0x2a87c
nop
beqz v0, next
nop
copy_file:
addiu a0, sp, 0x250
addiu a1, sp, 0x458
jal {COPY}
nop
beqz v0, close_find
nop
beqz s6, next
nop
# Count only verified bytes, with bounded 0..9 progress before version commit.
{ptr('t0', 0x38f18)}
lw t0, 0(t0)
beqz t0, next
nop
lw t1, 0x61c(t0)
addu t1, t1, v1
sw t1, 0x61c(t0)
lw t2, 0x624(t0)
beqz t2, next
nop
addiu t3, zero, 10
multu t1, t3
mflo t1
divu t1, t2
mflo t1
sltiu t2, t1, 10
bnez t2, progress
nop
addiu t1, zero, 9
progress:
sw t1, 0x620(t0)
jal 0x19714
move a0, t0
b next
nop
recurse:
addiu a0, sp, 0x250
addiu a1, sp, 0x458
move a2, s6
jal {TREE}
addiu a3, s7, 1
beqz v0, close_find
nop
next:
move a0, s2
addiu a1, sp, 0x20
{api('next')}
bnez v0, item
nop
{api('last')}
addiu t0, zero, 18
beq v0, t0, enumerated
nop
move a0, v0
jal {ERROR}
move a1, s0
b close_find
nop
enumerated:
addiu s5, zero, 1
close_find:
move a0, s2
{api('find_close')}
bnez v0, done
nop
move s5, zero
{api('last')}
move a0, v0
jal {ERROR}
move a1, s0
b done
nop
path_close_failed:
addiu a0, zero, 111
jal {ERROR}
move a1, s0
b close_find
nop
path_failed:
addiu a0, zero, 111
jal {ERROR}
move a1, s0
b done
nop
depth_failed:
addiu a0, zero, 111
jal {ERROR}
move a1, s0
done:
move v0, s5
{end(0x890, regs)}
"""
    error = f"""
{ptr('t0', CODE)}
lw t1, 0(t0)
bnez t1, done
nop
bnez a0, nonzero
nop
addiu a0, zero, 31
nonzero:
sw a0, 0(t0)
{ptr('t0', PATH)}
addiu t2, zero, 259
copy_path:
lhu t1, 0(a1)
sb t1, 0(t0)
srl t3, t1, 8
sb t3, 1(t0)
beqz t1, done
nop
addiu t0, t0, 2
addiu a1, a1, 2
addiu t2, t2, -1
bnez t2, copy_path
nop
sb zero, 0(t0)
sb zero, 1(t0)
done:
jr ra
move v0, zero
"""
    directory = f"""
{frame(0x28, ['s0'])}
move s0, a0
lhu t0, 0(s0)
beqz t0, success
nop
addiu a1, zero, 0
{api('mkdir')}
bnez v0, success
nop
move a0, s0
{api('attrs')}
addiu t0, zero, -1
beq v0, t0, failed
nop
andi t0, v0, 0x10
bnez t0, success
nop
failed:
{api('last')}
move a0, v0
jal {ERROR}
move a1, s0
b done
nop
success:
addiu v0, zero, 1
done:
{end(0x28, ['s0'])}
"""
    # Exit only the installer worker. Its original monitor may release COM2
    # after its existing five-minute timeout. Normal managers are not launched.
    stop = f"""
{frame(0x30, ['s0'])}
{ptr('t0',0x3784c)}
addiu t1, zero, 3007
sw t1, 0(t0)
# An error before copying must not leave phase 3000's hidden Start/Cancel
# touch targets active beneath the new error screen.
{ptr('t0', 0x38f18)}
lw s0, 0(t0)
beqz s0, exit
nop
addiu t0, zero, 2
sw t0, 0x628(s0)
move a0, s0
jal 0x19714
nop
lw a0, 0x630(s0)
addiu a1, zero, -1
move a2, zero
move a3, zero
addiu t0, zero, 800
sw t0, 0x10(sp)
addiu t0, zero, 480
sw t0, 0x14(sp)
addiu t0, zero, 0x40
sw t0, 0x18(sp)
jal 0x2a1c0
nop
lw a0, 0x630(s0)
jal 0x2a2c0
addiu a1, zero, 5
exit:
{ptr('t0', CODE)}
lw a0, 0(t0)
{api('exit')}
# ExitThread is nonreturning. Fail closed if a fixture/API violates that.
park:
b park
nop
"""
    stage = f"""
{frame(0x38, ['s0','s1','s2'])}
move s0, a0
move s1, a1
move s2, a2
{ptr('a0', s['card1'])}
jal {MOUNT}
nop
beqz v0, failed
nop
{ptr('a0', s['card4'])}
jal {MOUNT}
nop
beqz v0, failed
nop
move a0, s1
move a1, s2
addiu a2, zero, 1
jal {TREE}
move a3, zero
beqz v0, failed
nop
{ptr('a0', s['version_source'])}
{ptr('a1', s['version_target'])}
jal {COPY}
nop
beqz v0, failed
nop
lw t0, 0x61c(s0)
addu t0, t0, v1
sw t0, 0x61c(s0)
addiu t0, zero, 10
sw t0, 0x620(s0)
jal 0x19714
move a0, s0
addiu v0, zero, 1
{end(0x38, ['s0','s1','s2'])}
failed:
jal {STOP}
nop
"""
    # Both directions retain all source files. Backup/restore failure exits
    # before formatting/cleanup/manager launch in the original caller.
    wrappers = {}
    for label in ('backup', 'restore'):
        wrappers[label] = f"""
{frame(0x30, ['s0','s1'])}
move s0, a1
move s1, a2
{ptr('a0', s['card2'])}
jal {MOUNT}
nop
beqz v0, failed
nop
{ptr('a0', s['card3'])}
jal {MOUNT}
nop
beqz v0, failed
nop
move a0, s0
move a1, s1
move a2, zero
jal {TREE}
move a3, zero
beqz v0, failed
nop
{end(0x30, ['s0','s1'])}
failed:
jal {STOP}
nop
"""
    ambiguous = f"""
{frame(0x28, [])}
addiu a0, zero, 5001
{ptr('a1', s['scan'])}
jal {ERROR}
nop
jal {STOP}
nop
"""
    startup = f"""
{frame(0x28, [])}
# A missing mount must not be confused with absent pending staging.
{ptr('a0', s['card3'])}
{api('attrs')}
addiu t0, zero, -1
beq v0, t0, failed_api
nop
andi t0, v0, 0x10
beqz t0, failed_api
nop
{ptr('a0', s['stage'])}
{api('attrs')}
addiu t0, zero, -1
bne v0, t0, pending
nop
{api('last')}
addiu t0, zero, 2
beq v0, t0, original
nop
addiu t0, zero, 3
beq v0, t0, original
nop
b failed_api
nop
pending:
andi t0, v0, 0x10
beqz t0, incomplete
nop
{ptr('a0', s['receipt'])}
{api('attrs')}
addiu t0, zero, -1
beq v0, t0, incomplete
nop
andi t0, v0, 0x10
bnez t0, incomplete
nop
original:
jal 0x14eb0
nop
{end(0x28, [])}
incomplete:
addiu a0, zero, 5002
b failed_record
nop
failed_api:
{api('last')}
move a0, v0
failed_record:
{ptr('a1', s['stage'])}
jal {ERROR}
nop
jal {STOP}
nop
"""
    paint = f"""
{frame(0xa0, ['s0', 's1'])}
move s0, a1
{ptr('t0', CODE)}
lw t0, 0(t0)
bnez t0, failed
nop
jal 0x18e88
nop
b done
nop
failed:
# Plain black background uses no external image or language DLL.
sw zero, 0x20(sp)
sw zero, 0x24(sp)
addiu t0, zero, 800
sw t0, 0x28(sp)
addiu t0, zero, 480
sw t0, 0x2c(sp)
jal 0x2a1e0
addiu a0, zero, 4
move a2, v0
move a0, s0
jal 0x2a200
addiu a1, sp, 0x20
move a0, s0
jal 0x2a3d0
addiu a1, zero, 1
move a0, s0
lui a1, 0xff
jal 0x2a3e0
ori a1, a1, 0xffff
addiu a0, sp, 0x30
move a1, zero
jal 0x2b68c
addiu a2, zero, 92
addiu t0, zero, 32
sw t0, 0x30(sp)
addiu t0, zero, 700
sw t0, 0x40(sp)
jal 0x2a1f0
addiu a0, sp, 0x30
move s1, v0
move a0, s0
jal 0x2a380
move a1, s1
sw v0, 0x1c(sp)
{ptr('a0', BODY)}
addiu a1, zero, 512
{ptr('a2', s['body'])}
{ptr('t0', CODE)}
lw a3, 0(t0)
{ptr('t0', PATH)}
jal 0x2a86c
sw t0, 0x10(sp)
addiu t0, zero, 24
sw t0, 0x20(sp)
addiu t0, zero, 90
sw t0, 0x24(sp)
addiu t0, zero, 776
sw t0, 0x28(sp)
addiu t0, zero, 470
sw t0, 0x2c(sp)
move a0, s0
{ptr('a1', BODY)}
addiu a2, zero, -1
addiu a3, sp, 0x20
addiu t0, zero, 17
jal 0x2a400
sw t0, 0x10(sp)
move a0, s0
jal 0x2a380
lw a1, 0x1c(sp)
jal 0x2a1d0
move a0, s1
done:
{end(0xa0, ['s0', 's1'])}
"""
    mount = f"""
{frame(0x28,['s0'])}
move s0, a0
{api('attrs')}
addiu t0, zero, -1
beq v0, t0, failed
nop
andi t0, v0, 0x10
bnez t0, success
nop
failed:
{api('last')}
move a0, v0
jal {ERROR}
move a1, s0
b done
nop
success:
addiu v0, zero, 1
done:
{end(0x28,['s0'])}
"""
    format_guard = f"""
{frame(0x28,[])}
jal 0x1a3a4
nop
beqz v0, failed
nop
{ptr('a0',s['card2'])}
jal {MOUNT}
nop
beqz v0, stop
nop
{end(0x28,[])}
failed:
addiu a0, zero, 5003
{ptr('a1',s['card2'])}
jal {ERROR}
nop
stop:
jal {STOP}
nop
"""
    return [
        (COPY, 0x800, copy, 0x2060, regs), (TREE, 0xa00, tree, 0x890, regs),
        (ERROR, 0x200, error, 0, []), (STOP, 0x300, stop, 0x30, ['s0']),
        (STAGE, 0x300, stage, 0x38, ['s0','s1','s2']), (BACKUP, 0x200, wrappers['backup'], 0x30, ['s0','s1']),
        (RESTORE, 0x200, wrappers['restore'], 0x30, ['s0','s1']), (AMBIGUOUS, 0x100, ambiguous, 0x28, []),
        (PAINT, 0x300, paint, 0xa0, ['s0', 's1']), (STARTUP, 0x300, startup, 0x28, []),
        (DIRECTORY, 0x200, directory, 0x28, ['s0']),
        (MOUNT,0x200,mount,0x28,['s0']), (FORMAT,0x200,format_guard,0x28,[]),
    ]


def patch(raw):
    assert hashlib.sha256(raw).hexdigest() == 'bb6989e2446e95c6d93500ba27d1df7c3450697146c181afe581521dbad17676', 'Expected pinned English updater'
    pe = pefile.PE(data=raw)
    assert pe.FILE_HEADER.Machine == 0x166 and pe.OPTIONAL_HEADER.ImageBase == BASE
    assert pe.FILE_HEADER.Characteristics & 1, "Prototype requires the pinned fixed-base EXE"
    assert pe.FILE_HEADER.NumberOfSections == 5
    original = bytes(raw)
    out = bytearray(raw)
    data = bytearray(DATA_BYTES)
    strings, cursor = {}, 0x800
    for name, text in STRINGS.items():
        encoded = (text + '\0').encode('utf-16-le')
        strings[name] = DATA + cursor
        data[cursor:cursor+len(encoded)] = encoded
        cursor += len(encoded)
    assert cursor < 0x2000
    text = bytearray(TEXT_BYTES)
    recipes, pdata = [], []
    for at, capacity, code, stack, saved in routines(strings):
        code = code.replace('\\+', '')
        assembled, recipe = assemble_io(code, at, at + capacity)
        text[at-TEXT:at-TEXT+capacity] = assembled
        recipes.append(recipe)
        prolog = at + (2+len(saved))*4 if stack else at
        pdata.append((at, at+recipe['used_bytes'], 0, 0, prolog))
    # Existing call sites retain their stack and delay slot. Ambiguous checkpoint
    # transfers directly to a nonreturning failure path before any formatting.
    edits = []
    def edit(at, before, after, role):
        off = pe.get_offset_from_rva(at-BASE)
        assert struct.unpack_from('<I', original, off)[0] == before, hex(at)
        struct.pack_into('<I', out, off, after)
        edits.append(dict(va=hex(at), before=hex(before), after=hex(after), role=role))
    for at, old, new, role in [
        (0x12e4c, 0x14eb0, STARTUP, 'Validate pending staging before original startup'),
        (0x15198, 0x18460, BACKUP, 'Verified nondeleting backup; stop before format on failure'),
        (0x151a8, 0x1a3a4, FORMAT, 'Reject reported format failure or absent settings volume'),
        (0x151b8, 0x18698, RESTORE, 'Verified nondeleting restore; keep backup on failure'),
        (0x15304, 0x181b4, STAGE, 'Verified retained staging; version last; stop before caller cleanup'),
        *[(at, 0x18e88, PAINT, 'Persistent error screen without external bitmaps')
          for at in (0x1433c, 0x1a234, 0x1a27c, 0x1a318)],
    ]:
        edit(at, (3<<26)|(old>>2), (3<<26)|(new>>2), role)
    edit(0x150ec, 0x24060000, (2<<26)|(AMBIGUOUS>>2), 'Preserve ambiguous scan checkpoint and backup')
    edit(0x150f0, 0x24050000, 0, 'Delay slot for nonreturning checkpoint branch')
    # Preserve the current navigation assets until a verified overwrite succeeds.
    for at, old in [(0x15018, 0x0c005ff8), (0x1504c, 0x0100f809),
                    (0x15080, 0x0100f809), (0x150b4, 0x0100f809)]:
        edit(at, old, 0, 'Remove destructive pre-copy navigation deletion')
    # The original final-copy draw loop paints count+1 filled boxes and a total
    # of eleven. Use exactly ten cells: zero is empty, ten is complete. The tree
    # caps at nine until the version file has also passed readback.
    progress_code = """
move s4, zero
addiu s5, zero, 216
addiu s0, zero, 18
cell:
lw t0, 0x620(s6)
sltu t0, s4, t0
beqz t0, empty
move t1, zero
addiu t1, zero, 36
empty:
move a0, s2
move a1, s5
addiu a2, zero, 296
addiu a3, zero, 36
sw s0, 0x10(sp)
sw s1, 0x14(sp)
sw t1, 0x18(sp)
sw zero, 0x1c(sp)
jal 0x2a3a0
sw s7, 0x20(sp)
addiu s4, s4, 1
sltiu t0, s4, 10
bnez t0, cell
addiu s5, s5, 37
b 0x19664
nop
"""
    progress_bytes, progress_recipe=assemble_io(progress_code,0x192a0,0x1933c)
    progress_offset=pe.get_offset_from_rva(0x192a0-BASE)
    progress_recipe['before_hex']=original[progress_offset:progress_offset+len(progress_bytes)].hex()
    progress_recipe['role']='Exactly ten final-copy cells; full only after verified version commit'
    out[progress_offset:progress_offset+len(progress_bytes)]=progress_bytes
    recipes.append(progress_recipe)
    # Missing extraction receipts fail in STARTUP, before original cleanup.
    # Replace exception-directory pointer with an ordered combined function table.
    d = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    old_table = pe.get_data(d.VirtualAddress, d.Size)
    rows = [struct.unpack_from('<5I', old_table, i) for i in range(0,len(old_table),20)]
    rows += pdata
    rows.sort()
    assert all(a[1] <= b[0] for a,b in zip(rows, rows[1:]))
    combined = b''.join(struct.pack('<5I', *row) for row in rows)
    data[0x2000:0x2000+len(combined)] = combined
    assert 0x2000+len(combined) <= DATA_BYTES
    struct.pack_into('<II', out, d.get_file_offset(), DATA-BASE+0x2000, len(combined))
    # No relocation directory: all original and added addresses share the pinned
    # fixed ImageBase. Two extra section headers fit in existing header padding.
    header = pe.sections[-1].get_file_offset()+40
    assert header+80 <= pe.OPTIONAL_HEADER.SizeOfHeaders
    assert not any(original[header:header+80])
    alignment = pe.OPTIONAL_HEADER.FileAlignment
    raw_offset = (len(out)+alignment-1)//alignment*alignment
    out.extend(bytes(raw_offset-len(out)))
    for index, (name, va, contents, flags) in enumerate([
        (b'.maxfix', TEXT, text, 0x60000020),
        (b'.maxdata', DATA, data, 0xc0000040),
    ]):
        struct.pack_into('<8s8I',out,header+40*index,name,len(contents),va-BASE,
                         len(contents),raw_offset,0,0,0,flags)
        out.extend(contents)
        raw_offset += len(contents)
    struct.pack_into('<H',out,pe.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),7)
    struct.pack_into('<I',out,pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfImage'),DATA+DATA_BYTES-BASE)
    struct.pack_into('<I',out,pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfCode'),pe.OPTIONAL_HEADER.SizeOfCode+TEXT_BYTES)
    struct.pack_into('<I',out,pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfInitializedData'),pe.OPTIONAL_HEADER.SizeOfInitializedData+DATA_BYTES)
    result=bytes(out)
    checked=pefile.PE(data=result)
    assert checked.FILE_HEADER.NumberOfSections==7
    assert checked.OPTIONAL_HEADER.ImageBase==BASE and checked.OPTIONAL_HEADER.AddressOfEntryPoint==pe.OPTIONAL_HEADER.AddressOfEntryPoint
    return result, dict(kind='Internal post-restart copy safety prototype, not a release',
                        input_sha256=hashlib.sha256(raw).hexdigest(),sha256=hashlib.sha256(result).hexdigest(),
                        edits=edits,routines=recipes,strings=strings,added_function_rows=len(pdata),
                        native_executed=False,installation_ready=False,
                        limits=['Not a proven fix for GitHub 7/15','OS/MCU flash paths retain original behavior',
                                'Ambiguous settings checkpoint pauses for recovery, not automatic retry',
                                'Byte readback does not prove NAND durability or transactional rollback',
                                'CE loader/unwind/display and physical retry still require unit testing'])
