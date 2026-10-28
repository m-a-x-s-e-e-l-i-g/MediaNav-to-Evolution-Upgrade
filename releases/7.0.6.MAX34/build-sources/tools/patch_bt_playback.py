"""Pinned, in-place MIPS playback repair for the exact original 7.0.5.MD Blue.

Preserves PE layout, Process entry/epilogue and original stack/register ABI.
No code caves, new sections, native execution, or on-unit write operations.
"""
import hashlib
import re
import struct
import pefile
from inspect_bt_playback import BLUE_HASH

BLOCK_BYTES=4096
START_BUFFERS=2
QUEUE_LIMIT=4
REGS={name:i for i,name in enumerate(
    'zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra'.split())}


def assemble(text,start,end):
    lines=[];labels={};pc=start
    for line in text.splitlines():
        line=line.split('#',1)[0].strip()
        if not line:continue
        if line.endswith(':'):labels[line[:-1]]=pc;continue
        lines.append((pc,line));pc+=4
    assert pc<=end, f'Patch exceeds pinned range by {pc-end} bytes'
    def number(value):return labels[value] if value in labels else int(value,0)
    def r(value):return REGS[value]
    words=[]
    for pc,line in lines:
        parts=[p for p in re.split(r'[\s,()]+',line) if p];op,args=parts[0],parts[1:]
        if op=='nop':word=0
        elif op=='move':word=(r(args[1])<<21)|(r(args[0])<<11)|0x25
        elif op in ('addu','subu','and','sltu'):
            word=(r(args[1])<<21)|(r(args[2])<<16)|(r(args[0])<<11)|{'addu':0x21,'subu':0x23,'and':0x24,'sltu':0x2b}[op]
        elif op=='sll':word=(r(args[1])<<16)|(r(args[0])<<11)|(number(args[2])<<6)
        elif op in ('addiu','andi','ori','sltiu'):
            imm=number(args[2]);assert -32768<=imm<=65535
            word=({'addiu':9,'andi':12,'ori':13,'sltiu':11}[op]<<26)|(r(args[1])<<21)|(r(args[0])<<16)|(imm&65535)
        elif op=='lui':word=(15<<26)|(r(args[0])<<16)|number(args[1])
        elif op in ('lw','sw','lbu','sb'):
            imm=number(args[1]);assert -32768<=imm<=32767
            word=({'lw':35,'sw':43,'lbu':36,'sb':40}[op]<<26)|(r(args[2])<<21)|(r(args[0])<<16)|(imm&65535)
        elif op in ('beqz','bnez','b'):
            reg=0 if op=='b' else r(args[0]);dest=number(args[-1]);delta=(dest-pc-4)//4
            assert dest%4==0 and -32768<=delta<=32767
            word=((5 if op=='bnez' else 4)<<26)|(reg<<21)|(delta&65535)
        elif op=='jal':
            target=number(args[0]);assert target%4==0 and target>>28==(pc+4)>>28
            word=(3<<26)|((target>>2)&0x3ffffff)
        else:raise ValueError(line)
        words.append(word)
    raw=b''.join(struct.pack('<I',w) for w in words)
    return raw+bytes(end-start-len(raw)),dict(start=hex(start),end=hex(end),used_bytes=len(raw),labels={k:hex(v) for k,v in labels.items()},assembly=text)


PROCESS='''
    sw s2, 0x14(sp)             # Preserve original input pointer for original epilogue/free.
    lw s1, 0x50(sp)             # Incoming PCM bytes, original fifth argument.
    beqz s2, restore_input
    nop
    beqz s1, restore_input
    nop
    lui t0, 1
    sltu t1, t0, s1             # Bound one call to <=64 KiB, reject wrapped/negative sizes.
    bnez t1, restore_input
    nop
    lui s4, 0x11
    addiu s4, s4, 0xf84
    jal 0x8a820
    move a0, s4
loop:
    lbu t0, 4(s0)
    addiu t1, zero, 2
    subu t0, t0, t1
    bnez t0, unlock             # Only started WinPlay contexts accept new PCM.
    nop
    lbu t0, 0x338(s0)
    bnez t0, choose
    nop
    lbu t0, 5(s0)
    sltiu t1, t0, 2
    bnez t1, choose
    nop
    jal 0x8a8d0
    lw a0, 8(s0)
    bnez v0, unlock             # Keep flag clear; next call retries, including when queue is full.
    nop
    addiu t0, zero, 1
    sb t0, 0x338(s0)
choose:
    beqz s1, unlock
    nop
    lbu t0, 5(s0)
    sltiu t1, t0, 4
    beqz t1, unlock             # Drop excess incoming PCM, never overwrite owned data.
    nop
    lbu t0, 6(s0)
    sltiu t1, t0, 25
    beqz t1, unlock
    nop
    sll t0, t0, 5
    addu t0, t0, s0
    addiu t0, t0, 0x10
    sw t0, 0x10(sp)
    lw t1, 0xc(t0)
    bnez t1, unlock             # No copying unless this precise header is free.
    nop
    lw t1, 0x10(t0)
    andi t1, t1, 0x12
    addiu t1, t1, -2            # Require PREPARED and reject OS-owned INQUEUE too.
    bnez t1, unlock
    nop
    lw t2, 0x334(s0)
    sltiu t1, t2, 4096
    beqz t1, unlock
    nop
    lw t1, 0(t0)
    beqz t1, unlock
    nop
    sw t1, 0x330(s0)
    addu a0, t1, t2
    addiu t1, zero, 4096
    subu s3, t1, t2
    sltu t0, s1, s3
    beqz t0, copy
    nop
    move s3, s1
copy:
    move a1, s2
    jal 0x85758
    move a2, s3
    beqz v0, unlock
    nop
    addu s2, s2, s3
    subu s1, s1, s3
    lw t0, 0x334(s0)
    addu t0, t0, s3
    sw t0, 0x334(s0)
    sltiu t1, t0, 4096
    bnez t1, unlock
    nop
    lw a1, 0x10(sp)
    sw t0, 4(a1)
    addiu t0, zero, 1
    sw t0, 0xc(a1)
    lbu t0, 5(s0)
    addiu t0, t0, 1
    sb t0, 5(s0)
    lw a0, 8(s0)
    jal 0x8a8e0
    addiu a2, zero, 32
    sw zero, 0x334(s0)
    move s3, v0
    beqz v0, submitted
    nop
    lw t0, 0x10(sp)
    lw t1, 0x10(t0)
    andi t1, t1, 0x10
    bnez t1, submitted          # Ambiguous failure with INQUEUE retains ownership until completion/reset.
    nop
    sw zero, 0xc(t0)            # Rejected write: restore ownership/counter, don't advance producer.
    lbu t0, 5(s0)
    addiu t0, t0, -1
    b unlock
    sb t0, 5(s0)
submitted:
    lbu t0, 6(s0)
    addiu t0, t0, 1
    sltiu t1, t0, 25
    bnez t1, advanced
    nop
    move t0, zero
advanced:
    sb t0, 6(s0)
    bnez s3, unlock
    nop
    b loop
    nop
unlock:
    jal 0x8a810
    move a0, s4
restore_input:
    lw s2, 0x14(sp)
    b 0x27088
    nop
'''

CALLBACK='''
    lw a0, 0x1c(sp)
    lw t0, 0xc(a0)
    beqz t0, 0x264e8           # Duplicate/unowned completion cannot decrement pending.
    nop
    sw zero, 0xc(a0)
    lw t0, 0x10(a0)
    addiu t1, zero, -2
    and t0, t0, t1
    sw t0, 0x10(a0)
    lw t3, 0xf9c(s4)
    beqz t3, 0x264e8
    nop
    lbu t1, 5(t3)
    beqz t1, 0x264e8
    nop
    addiu t1, t1, -1
    sb t1, 5(t3)
    bnez t1, 0x264e8
    nop
    sb zero, 0x338(t3)
    jal 0x8a830
    lw a0, 8(t3)
'''


def patch_blue(raw):
    assert hashlib.sha256(raw).hexdigest()==BLUE_HASH,'Unexpected original Blue'
    pe=pefile.PE(data=raw);base=pe.OPTIONAL_HEADER.ImageBase
    assert pe.FILE_HEADER.Machine==0x166 and pe.OPTIONAL_HEADER.CheckSum==0
    assert pe.OPTIONAL_HEADER.DATA_DIRECTORY[4].Size==0
    process,process_meta=assemble(PROCESS,0x26e98,0x27088)
    callback,callback_meta=assemble(CALLBACK,0x26484,0x264e8)
    patches=[(0x26e98,process,'bounded PCM split/ownership/write/restart'),
        (0x26484,callback,'completion ownership and underflow guard'),
        (0x26ad4,bytes(4),'attempt all 25 unprepare calls'),
        (0x26d64,struct.pack('<I',0xae000334),'discard partial PCM on stop/reset')]
    output=bytearray(raw);records=[]
    for va,data,reason in patches:
        offset=pe.get_offset_from_rva(va-base);before=raw[offset:offset+len(data)]
        assert len(before)==len(data)
        if va==0x26ad4:assert before==struct.pack('<I',0x1200000d)
        if va==0x26d64:assert before==bytes(4)
        output[offset:offset+len(data)]=data
        records.append(dict(va=hex(va),file_offset=hex(offset),bytes=len(data),reason=reason,
            before_hex=before.hex(),after_hex=data.hex(),before_sha256=hashlib.sha256(before).hexdigest(),
            after_sha256=hashlib.sha256(data).hexdigest()))
    result=bytes(output);after_pe=pefile.PE(data=result)
    assert len(result)==len(raw) and after_pe.OPTIONAL_HEADER.CheckSum==0
    for section in pe.sections:
        other=next(s for s in after_pe.sections if s.Name==section.Name)
        assert section.__pack__()==other.__pack__()
    # Preserve both ABI framing and the original unwind table byte-for-byte.
    for lo,hi in [(0x26e14,0x26e98),(0x27088,0x270f4)]:
        offset=pe.get_offset_from_rva(lo-base);assert result[offset:offset+hi-lo]==raw[offset:offset+hi-lo]
    for section in pe.sections:
        if section.Name.rstrip(b'\0')==b'.pdata':
            assert result[section.PointerToRawData:section.PointerToRawData+section.SizeOfRawData]==section.get_data()
    changed=sum(a!=b for a,b in zip(raw,result))
    return result,dict(profile='BT02',source_sha256=BLUE_HASH,output_sha256=hashlib.sha256(result).hexdigest(),
        block_bytes=BLOCK_BYTES,restart_buffers=START_BUFFERS,maximum_queued_buffers=QUEUE_LIMIT,
        changed_bytes=changed,pe_layout_preserved=True,process_stack_and_unwind_preserved=True,
        patch_ranges=records,assembled=[process_meta,callback_meta],native_execution=False)
