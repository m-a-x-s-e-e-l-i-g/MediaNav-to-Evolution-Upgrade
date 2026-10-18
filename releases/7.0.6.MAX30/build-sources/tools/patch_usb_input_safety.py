"""Pinned in-place USB input fixes, preserving PE layout and pdata.

Development only. Checks failed saves; does not make writes transactional.
"""
import hashlib
import re
import struct
import pefile
from draft_bt_database_io import assemble_io
from patch_bt_playback import REGS

BASE_SHA = '408783c05921a92d885c63f9ccecee0c18c5e1725790cb623f8fa124ddb8085e'


def encode(code, start, end):
    # Local SH support; keep older repair tooling unchanged.
    lines, custom, pc = [], [], start
    for line in code.splitlines():
        line = line.split('#', 1)[0].strip()
        if not line: continue
        if line.endswith(':'):
            lines.append(line); continue
        if line.startswith('sh '):
            custom.append((pc, line)); lines.append('nop')
        else: lines.append(line)
        pc += 4
    raw, recipe = assemble_io('\n'.join(lines), start, end)
    out = bytearray(raw)
    for pc, line in custom:
        _, rt, imm, rs = re.split(r'[\s,()]+', line.strip())[:4]
        value = int(imm, 0); assert -32768 <= value <= 32767
        word = (0x29 << 26) | (REGS[rs] << 21) | (REGS[rt] << 16) | (value & 65535)
        struct.pack_into('<I', out, pc-start, word)
    recipe['assembly'] = code
    return bytes(out), recipe


PATH = '''
    lui t0, 3
    addiu s1, t0, -0x104
    move s0, zero
    move t4, s1
    addiu t5, s1, 0x206
    sh zero, 0(s1)
    beqz a1, failed
    move t2, a1
    lhu t0, 0(t2)
    beqz t0, failed
    addiu t7, zero, 0x5c
    bne t0, t7, relative
    nop
    lhu t0, 2(t2)
    ori t0, t0, 0x20
    addiu t1, zero, 0x6d
    bne t0, t1, absolute
    nop
    lhu t0, 4(t2)
    ori t0, t0, 0x20
    addiu t1, zero, 0x64
    bne t0, t1, absolute
    nop
    lhu t0, 6(t2)
    beq t0, t7, input
    nop
    beqz t0, input
    nop
absolute:
    sh t7, 0(t4)
    addiu t0, zero, 0x4d
    sh t0, 2(t4)
    addiu t0, zero, 0x44
    sh t0, 4(t4)
    b input
    addiu t4, t4, 6
relative:
    beqz a2, input
    nop
    lhu t0, 0(a2)
    beq t0, t7, base
    move t3, a2
    sh t7, 0(t4)
    addiu t4, t4, 2
base:
    lhu t0, 0(t3)
    beqz t0, separator
    nop
    beq t4, t5, failed
    nop
    sh t0, 0(t4)
    addiu t4, t4, 2
    b base
    addiu t3, t3, 2
separator:
    beq t4, t5, failed
    nop
    sh t7, 0(t4)
    addiu t4, t4, 2
input:
    lhu t0, 0(t2)
    beqz t0, done
    nop
    beq t4, t5, failed
    nop
    sh t0, 0(t4)
    addiu t4, t4, 2
    b input
    addiu t2, t2, 2
done:
    sh zero, 0(t4)
    b 0x16324
    move s0, s1
failed:
    move t4, s1
    addiu t5, s1, 0x208
clear:
    sh zero, 0(t4)
    addiu t4, t4, 2
    bne t4, t5, clear
    nop
    b 0x16324
    move s0, s1
'''


def patch(raw):
    assert hashlib.sha256(raw).hexdigest() == BASE_SHA
    pe = pefile.PE(data=raw); out = bytearray(raw); edits = []
    def block(start, end, code, reason):
        new, recipe = encode(code, start, end)
        at = pe.get_offset_from_rva(start-pe.OPTIONAL_HEADER.ImageBase)
        assert any(s.Name.rstrip(b'\0') == b'.text' and
                   s.PointerToRawData <= at < at+len(new) <= s.PointerToRawData+s.SizeOfRawData
                   for s in pe.sections)
        out[at:at+len(new)] = new
        edits.append(dict(va=hex(start),offset=hex(at),bytes=len(new),before_hex=raw[at:at+len(new)].hex(),
                          after_hex=new.hex(),reason=reason,assembly=recipe))

    block(0x161c8,0x16324,PATH,'Bound concatenated playlist paths to 259 UTF16 units; require an MD root boundary')
    block(0x16168,0x16180,'''andi t0, v0, 0x10
        sltiu v0, t0, 1
        b 0x16180
        nop
    ''','Reject INVALID_FILE_ATTRIBUTES and every DIRECTORY bit combination')
    block(0x16380,0x1639c,'''jal 0x253bc
        move a0, s0
        sltiu t0, v0, 4
        bnez t0, 0x16364
        nop
    ''','Check suffix minimum length before subtracting four; wcscpy_s supplies local termination')
    block(0x1bf78,0x1bfa8,'''sh zero, 0x1086(s4)
        sh zero, 0x128e(s4)
        sh zero, 0x1496(s4)
        sh zero, 0x169e(s4)
        sh zero, 0x18a6(s4)
        sh zero, 0x1aae(s4)
        b 0x1bfa8
        nop
    ''','Terminate all six resume text slots and remove the second handle close and redundant success log')
    block(0x1bfe0,0x1bfe4,'sw zero, 0x28(sp)','Initialize the attribute word read in the conditional-branch delay slot')
    block(0x1c02c,0x1c054,'''lw t0, -0xf6c(s7)
        addiu a2, sp, 0x28
        move a1, zero
        jalr t0
        addiu a0, sp, 0x50
        beqz v0, 0x1c130
        lw t0, 0x28(sp)
        andi t0, t0, 2
        bnez t0, 0x1c098
        addiu s0, s0, -1
    ''','Failed attribute calls clear resume data instead of consuming stale output')
    block(0x1c074,0x1c078,'beq v0, a0, 0x1c130','Missing saved folder clears invalid resume data too')
    for init, end, check, finish in ((0x1c21c,0x1c23c,0x1c270,0x1c2c4),
                                     (0x1c388,0x1c3a8,0x1c3dc,0x1c430)):
        block(init,end,f'sw zero, 0x20(sp)\nb {hex(end)}\nnop','Initialize resume write byte count; omit redundant WRITE log')
        block(check,check+0x20,f'''sltu t1, zero, v0
            lw t0, 0x20(sp)
            addiu t0, t0, -0xc6c
            sltiu t0, t0, 1
            and s3, s3, t0
            and s3, s3, t1
            b {hex(finish)}
            nop
        ''','Save succeeds only when WriteFile, exact 3180-byte count and CloseHandle all succeed')
    for at in (0x19ea4,0x19f48,0x19f9c,0x1a034,0x1a090,0x1a1a0,0x1a1f0,0x1a288,0x1a2e4):
        block(at,at+4,'addiu a2, zero, 0x206','Copy 259 complete UTF16 units into pre-cleared 260-unit status buffers')

    # Unflagged frame correctness. Unsupported flagged-frame paths retain their
    # old behavior except compressed frames, which must never read unfilled memory.
    block(0x17b28,0x17b90,'''lbu t0, 4(s3)
        lbu t1, 5(s3)
        lbu t2, 6(s3)
        lbu t3, 7(s3)
        or t4, t0, t1
        or t4, t4, t2
        or t4, t4, t3
        andi t4, t4, 0x80
        bnez t4, 0x18264
        sll t0, t0, 21
        sll t1, t1, 14
        sll t2, t2, 7
        or s4, t0, t1
        or s4, s4, t2
        or s4, s4, t3
        addiu t1, a3, 0x48
        sltu t0, s2, s4
        bnez t0, 0x18264
        sw t1, 0x10(fp)
        lbu t0, 8(s3)
        lbu t1, 9(s3)
        sll t3, t0, 8
        or t3, t3, t1
    ''','Decode v2.4 synchsafe frame lengths, reject high bits and verify payload containment')
    for at,h,late in ((0x17af4,10,0x17b9c),(0x17c50,10,0x17cf8),(0x17d70,6,0x17dec)):
        block(at,at+12,f'''sltiu t0, s2, {h}
            bnez t0, 0x18264
            addiu s2, s2, -{h}
        ''','Check header containment, then compare size against payload remaining bytes')
        block(late,late+4,'nop','Header bytes were already subtracted before the size check')
    block(0x17cb8,0x17cbc,'bnez t0, 0x18264','Stop on an oversized v2.3 frame')
    block(0x17dd8,0x17de4,'b 0x18264\nnop\nnop','Stop on an oversized v2.2 frame')
    block(0x17c40,0x17c48,'nop\nnop','Dispatch the final frame even when it exactly fills the tag')
    block(0x17d00,0x17d70,'''andi t0, t4, 0xff
        beqz t0, 0x17c2c
        nop
        b 0x17c2c
        move v1, zero
    ''','Skip unsupported v2.3 frame transforms without changing the frame cursor or reading an unfilled decompression buffer')
    block(0x17ba4,0x17c2c,'''andi t0, t3, 0xfd
        beqz t0, unsync
        nop
        b 0x17c2c
        move v1, zero
    unsync:
        andi v0, t3, 2
        b 0x17c2c
        nop
    ''','Keep supported v2.4 per-frame unsynchronisation; skip unsupported transforms using the declared payload length')
    # Checked version-dependent extended-header consumption fits within the old
    # two integer decoder loops plus their pointer update.
    block(0x17a08,0x17a8c,'''addiu t1, zero, 2
        beq t7, t1, 0x18264
        sltiu t1, s2, 4
        bnez t1, 0x18264
        move t4, zero
        move t5, zero
        sltiu t6, t7, 4
        addiu t3, zero, 4
    ext:
        addu t0, s3, t5
        lbu t1, 0(t0)
        beqz t6, v4ext
        nop
        sll t4, t4, 8
        b extjoin
        nop
    v4ext:
        andi t2, t1, 0x80
        bnez t2, 0x18264
        nop
        sll t4, t4, 7
    extjoin:
        or t4, t4, t1
        addiu t5, t5, 1
        bne t5, t3, ext
        nop
        beqz t6, extbound
        nop
        addiu t4, t4, 4
    extbound:
        sltiu t0, t4, 6
        bnez t0, 0x18264
        sltu t1, s2, t4
        bnez t1, 0x18264
        nop
        addu s3, s3, t4
        subu s2, s2, t4
    ''','Check extended header length; v2.4 size includes its own size field')
    # The encoder checks every fixed range before any file write.
    block(0x17e88,0x17eb0,'''bnez s1, 0x18218
        nop
        b 0x17eb0
        nop
    ''','Skip unsupported compressed frames instead of interpreting an unfilled allocation')
    spans=sorted((int(e['offset'],16),int(e['offset'],16)+e['bytes']) for e in edits)
    assert all(b<=c for (_,b),(c,_) in zip(spans,spans[1:]))
    # MIPS HIGHADJ consumes a second raw word, not a second relocation. Remove
    # relocations for deleted instructions; move the suffix WCSLEN JAL entry.
    # Keep block sizes and the original section layout, padding with ABSOLUTE.
    d=pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    rel_at=pe.get_offset_from_rva(d.VirtualAddress)
    pos=0; removed=[]; moved=[]
    while pos<d.Size:
        page,n=struct.unpack_from('<II',raw,rel_at+pos)
        assert n>=8 and n%2==0
        vals=list(struct.unpack_from('<'+str((n-8)//2)+'H',raw,rel_at+pos+8))
        i=0
        while i<len(vals):
            value=vals[i];kind=value>>12;at=page+(value&4095)
            length=2 if kind==4 else 1
            assert i+length<=len(vals)
            if kind and any(a<=pe.get_offset_from_rva(at)<b for a,b in spans):
                offset=pe.get_offset_from_rva(at)
                if at+0x10000==0x1638c:
                    assert kind==5
                    vals[i]=(5<<12)|((0x16380-0x10000)-page)
                    moved.append(dict(before='0x1638c',after='0x16380',type=5))
                elif raw[offset:offset+4]!=out[offset:offset+4]:
                    removed.append(dict(va=hex(at+0x10000),type=kind))
                    vals[i:i+length]=[0]*length
            i+=length
        struct.pack_into('<'+str(len(vals))+'H',out,rel_at+pos+8,*vals)
        pos+=n
    assert pos==d.Size
    result=bytes(out); other=pefile.PE(data=result)
    assert len(result)==len(raw) and result[:pe.OPTIONAL_HEADER.SizeOfHeaders]==raw[:pe.OPTIONAL_HEADER.SizeOfHeaders]
    assert all(a.__pack__()==b.__pack__() and (a.Name.rstrip(b'\0') in (b'.text',b'.reloc') or a.get_data()==b.get_data())
               for a,b in zip(pe.sections,other.sections))
    return result,dict(base_sha256=BASE_SHA,sha256=hashlib.sha256(result).hexdigest(),edits=edits,
                      relocations=dict(removed=removed,moved=moved,offset=hex(rel_at),bytes=d.Size,
                                       before_hex=raw[rel_at:rel_at+d.Size].hex(),after_hex=result[rel_at:rel_at+d.Size].hex()),
                      native_executed=False,new_sections=False,transactional_saves=False)
