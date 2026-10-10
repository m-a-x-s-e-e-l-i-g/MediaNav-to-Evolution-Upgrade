"""Compare actual old/new MIPS snapshot bytes, strict bounds and ABI fixtures."""
import hashlib
import struct
from verify_usb_status_consumers import Fixture,call
from verify_usb_input_safety import relocated
from inspect_bt_pairing import put,data
from patch_shared_mapping_checks import reloc_records

AREA=0x4c000000

def copy_case(raw,recipe,delta,n,src_align=0,dst_align=0,overlap=None,create=True,wait=0,null=False):
    f=Fixture(raw,recipe,delta,create_ok=create,wait_result=wait);m=f.m
    src=AREA+0x100+src_align;dst=AREA+0x10000+dst_align if overlap is None else src+overlap
    regions=[(min(src,dst)-8,max(src+n,dst+n)+8)] if overlap is not None else [(src-8,src+n+8),(dst-8,dst+n+8)]
    expected={}
    for low,high in regions:
        initial=bytes((at*37+11)&255 for at in range(low,high))
        put(m,low,initial);expected.update(zip(range(low,high),initial))
    success=not null and create and wait in (0,0x80)
    if success:
        for i in range(n):expected[dst+i]=expected[src+i]
    old_read,old_write=m.read,m.write;reads=[];writes=[]
    def read(at,size=4):
        if AREA-0x1000<=at<AREA+0x20000:
            assert success and f.owned and src<=at and at+size<=src+n,(hex(at),size,n)
            reads.append((at,size))
        return old_read(at,size)
    def write(at,value,size=4):
        if AREA-0x1000<=at<AREA+0x20000:
            assert success and f.owned and dst<=at and at+size<=dst+n,(hex(at),size,n)
            writes.append((at,size))
        return old_write(at,value,size)
    m.read,m.write=read,write
    result=call(m,recipe['code_va']+0x200+delta,[dst,0 if null else src,n],limit=100000)
    steps=m.steps
    m.read,m.write=old_read,old_write
    f.complete()
    assert result==int(success)
    actual=b''.join(data(m,low,high-low) for low,high in regions)
    oracle=bytes(expected[at] for low,high in regions for at in range(low,high))
    assert actual==oracle,'Copy or buffer guard mismatch'
    if success:
        assert f.events==['create','wait','release','close']
        assert {at+i for at,size in reads for i in range(size)}==set(range(src,src+n))
        assert {at+i for at,size in writes for i in range(size)}==set(range(dst,dst+n))
    elif null:assert not f.events
    elif not create:assert f.events==['create']
    else:assert f.events==['create','wait','close']
    return dict(instructions=steps,result=result,events=f.events,sha256=hashlib.sha256(actual).hexdigest(),
        source_byte_reads=sum(size for _,size in reads),destination_byte_writes=sum(size for _,size in writes))

def verify(before,after,old_recipe,new_recipe):
    traces=[];bench=[]
    counts=(*range(18),31,32,33,127,128,129,259,260,261,519,520,521,3669,3670,3671,3672,4095,4096)
    for delta in (0,0x10000,0x120000,0x500000):
        a=before if not delta else relocated(before,delta)
        b=after if not delta else relocated(after,delta)
        for n in counts if not delta else (520,3670):
            for sa in range(4):
                for da in range(4):
                    old=copy_case(a,old_recipe,delta,n,sa,da)
                    new=copy_case(b,new_recipe,delta,n,sa,da)
                    assert old['sha256']==new['sha256'] and old['events']==new['events']
                    traces.append(dict(name='all alignments, exact bounded copy',delta=delta,count=n,source_alignment=sa,
                        destination_alignment=da,old_instructions=old['instructions'],new_instructions=new['instructions']))
                    if not delta and (n,sa,da) in ((520,2,0),(3670,0,0)):
                        assert new['instructions']<old['instructions']
                        bench.append(dict(bytes=n,source_alignment=sa,destination_alignment=da,before=old,after=new,
                            instruction_reduction_percent=100*(1-new['instructions']/old['instructions'])))
        for shift in range(-7,8):
            for n in (1,2,3,4,5,7,8,9,15,16,17,31,32,33,64,520):
                old=copy_case(a,old_recipe,delta,n,overlap=shift)
                new=copy_case(b,new_recipe,delta,n,overlap=shift)
                assert old['sha256']==new['sha256'] and old['events']==new['events']
                traces.append(dict(name='retain forward-copy overlap behavior',delta=delta,shift=shift,count=n))
        for create,wait,null in ((True,0,True),(True,0x80,False),(False,0,False),
                                 (True,0x102,False),(True,0xffffffff,False)):
            for n in (0,1,3,4,520,3670):
                old=copy_case(a,old_recipe,delta,n,create=create,wait=wait,null=null)
                new=copy_case(b,new_recipe,delta,n,create=create,wait=wait,null=null)
                assert old['sha256']==new['sha256'] and old['events']==new['events'] and old['result']==new['result']
                traces.append(dict(name='NULL, zero, abandoned, create/wait failure',delta=delta,count=n,create=create,wait=wait,null=null))
    return dict(cases=len(traces),traces=traces,benchmarks=bench,actual_mips_interpreted=True,
        strict_architectural_source_and_destination_bounds=True,mutex_and_scheduler_are_fixtures=True,
        native_timing_measured=False,native_executed=False)

def structure(before,after,r):
    from verify_media_responsiveness import parsed
    assert len(before)==len(after)
    restored=bytearray(after)
    for e in reversed(r['edits']):
        off=e['offset'];n=e['bytes']
        assert restored[off:off+n]==bytes.fromhex(e['after_hex'])
        restored[off:off+n]=bytes.fromhex(e['before_hex'])
    assert bytes(restored)==before,'Undeclared byte change'
    a,b=parsed(before),parsed(after);start=r['start']
    assert a.FILE_HEADER.__pack__()==b.FILE_HEADER.__pack__()
    assert a.OPTIONAL_HEADER.__pack__()==b.OPTIONAL_HEADER.__pack__()
    assert [s.__pack__() for s in a.sections]==[s.__pack__() for s in b.sections]
    assert [(d.dll,[(s.address,s.ordinal,s.name) for s in d.imports]) for d in a.DIRECTORY_ENTRY_IMPORT]==[
        (d.dll,[(s.address,s.ordinal,s.name) for s in d.imports]) for d in b.DIRECTORY_ENTRY_IMPORT]
    for index in (3,5):
        ad,bd=a.OPTIONAL_HEADER.DATA_DIRECTORY[index],b.OPTIONAL_HEADER.DATA_DIRECTORY[index]
        assert (ad.VirtualAddress,ad.Size)==(bd.VirtualAddress,bd.Size)
    d=a.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    rows_a=[struct.unpack_from('<5I',a.get_data(d.VirtualAddress,d.Size),i) for i in range(0,d.Size,20)]
    rows_b=[struct.unpack_from('<5I',b.get_data(d.VirtualAddress,d.Size),i) for i in range(0,d.Size,20)]
    expected=[(x[0],start+r['used_bytes'],*x[2:]) if x[0]==start else x for x in rows_a]
    assert expected==rows_b and all(x[1]<=y[0] for x,y in zip(rows_b,rows_b[1:]))
    old=set(reloc_records(a));new=set(reloc_records(b));inside=lambda row:start-0x10000<=row[0]<start-0x10000+r['capacity']
    assert {row for row in old if not inside(row)}=={row for row in new if not inside(row)}
    assert {row for row in new if inside(row)}=={tuple(row) for row in r['relocations_added']}
    return dict(cases=1,exact_reversible_edits=True,sections_imports_directories_unchanged=True,
        other_pdata_and_relocations_unchanged=True,same_frame_and_prolog=True,helper_used_bytes=r['used_bytes'])
