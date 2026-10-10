"""Execute written MIPS comparisons; CE qsort/API calls are explicit fixtures."""
import hashlib
import random
import struct
from functools import cmp_to_key
from pathlib import Path
from patch_usb_sorting import COMPARE,BASE_SHA
from verify_media_responsiveness import VM,parsed
from verify_usb_input_safety import common,relocated
from verify_wma_shuffle import invoke
from inspect_bt_pairing import put,data

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'build/wma-shuffle-development-02/payload/upgrade/Storage Card/System/MgrUSB.exe'
TABLE=ROOT/'build/wma-shuffle-development-02/payload/upgrade/Storage Card/System/data/LatinSortData.txt'
CTX,LEFT,RIGHT,OBJ,FOLDERS,SONGS,PARENT=0x41000000,0x42000000,0x43000000,0x44000000,0x45000000,0x46000000,0x47000000
PAIRS=[tuple(int(v,16) for v in line.split(',')) for line in TABLE.read_text().splitlines() if line.strip()]

def signed16(n):return n if n<32768 else n-65536
def units(s):
    if s is None:return []
    b=s.encode('utf-16-le',errors='surrogatepass')
    return list(struct.unpack('<'+'H'*(len(b)//2),b))

def weight(u,enabled=True,extra=(0,0)):
    if not enabled:return u
    low,high=0,len(PAIRS);a=signed16(u);rows=PAIRS+[extra]
    while low<=high:
        mid=(low+high)//2;k,w=rows[mid];k=signed16(k)
        if k<a:low=mid+1
        elif a<k:high=mid-1
        else:return signed16(w)
    return a

def key(s,enabled=True,extra=(0,0)):
    out=[]
    for u in units(s)[:260]:
        if not u:break
        out.append(((weight(u,enabled,extra)<<16)|u)&0xffffffff)
    return out

class SortVM(VM):
    def plain(self,word):
        if word>>26==0 and word&63==3:
            rt,rd,shift=(word>>16)&31,(word>>11)&31,(word>>6)&31
            value=self.reg[rt];value=value if value<0x80000000 else value-0x100000000
            self.reg[rd]=(value>>shift)&0xffffffff;self.reg[0]=0
        else:super().plain(word)
    def __init__(self,raw,enabled=True,delta=0,extra=(0,0)):
        spans=[(0x135f0,0x13630),(0x13d88,0x13f10),(0x16cd8,0x16ce8),
               (0x16e20,0x16eb0),(0x17208,0x172c0),(0x172c0,0x1738c),
               (0x173d8,0x17468),(COMPARE,COMPARE+0x1f0)]
        super().__init__(parsed(raw),[(a+delta,b+delta) for a,b in spans])
        common(self)
        if delta:self.hooks={a+delta:h for a,h in self.hooks.items()}
        self.delta=delta;self.mapper_calls=0;self.flag_calls=0;self.zero_bytes=0;self.name_reads=0
        self.code_words={} # Immutable executable bytes; counters still count every fetch.
        zero=self.hooks[0x253dc+delta]
        def counted(m):self.zero_bytes+=m.reg[6];return zero(m)
        self.hooks[0x253dc+delta]=counted
        self.hooks[0x17150+delta]=lambda m:CTX # Existing loaded singleton fixture.
        put(self,CTX,bytes(0xba0));self.write(CTX+8,int(enabled));self.write(CTX+12,len(PAIRS))
        for i,(k,w) in enumerate(PAIRS+[extra]):
            self.write(CTX+16+4*i,w,2);self.write(CTX+18+4*i,k,2)
    def word(self,pc):
        self.mapper_calls+=int(pc==0x16e20+self.delta)
        self.flag_calls+=int(pc==0x16cd8+self.delta)
        if pc not in self.code_words:self.code_words[pc]=super().word(pc)
        return self.code_words[pc]
    def read(self,at,size=4):
        if LEFT<=at<LEFT+520 or RIGHT<=at<RIGHT+520:self.name_reads+=1
        return super().read(at,size)
    def compare(self,left,right,callback=False):
        for at,s in ((LEFT,left),(RIGHT,right)):
            b=b'' if s is None else s.encode('utf-16-le',errors='surrogatepass')
            assert len(b)<=518
            put(self,at,b+bytes(520-len(b)));self.write(at-4,0xa55aa55a);self.write(at+520,0xa55aa55a)
        lp=LEFT if left is not None else 0;rp=RIGHT if right is not None else 0
        result=invoke(self,(0x135f0 if callback else 0x173d8)+self.delta,
                      [lp,rp] if callback else [CTX,lp,rp])
        assert result in (0,1,0xffffffff)
        assert all(self.read(at-4)==self.read(at+520)==0xa55aa55a for at in (LEFT,RIGHT))
        return -1 if result==0xffffffff else result

def equivalence(raw):
    previous=SOURCE.read_bytes();assert hashlib.sha256(previous).hexdigest()==BASE_SHA
    names=[None,'','a','A','aa','a.mp3','A.mp3','a\0ignored','ä','Ä','á','À','Å','Æ','ø','ß',
           'Björk.mp3','École','Cafe','Café','日本語','한글','موسيقى','Привет','😀','😇',
           '\u7fff','\u8000','\uffff','\ud800','\udfff','x'*259,'x'*258+'a','x'*258+'b']
    rng=random.Random(705);alphabet='Aa09éä中م한😀\u7fff\u8000\uffff'
    pairs=[(a,b) for a in names for b in names if rng.randrange(5)==0]
    pairs += [(s,s) for s in names]
    pairs += [(''.join(rng.choices(alphabet,k=rng.randrange(1,30))),
               ''.join(rng.choices(alphabet,k=rng.randrange(1,30)))) for _ in range(128)]
    # Every deployed mapping entry, including those unreachable by its signed search.
    pairs += [(chr(k)+'tail',chr(w)+'tail') for k,w in PAIRS]
    cases=0
    for enabled,extra in [(False,(0,0)),(True,(0,0)),(True,(0xffff,0x1234))]:
        old=SortVM(previous,enabled,extra=extra);new=SortVM(raw,enabled,extra=extra)
        for a,b in pairs:
            ka,kb=key(a,enabled,extra),key(b,enabled,extra);expected=(ka>kb)-(ka<kb)
            assert old.compare(a,b)==expected,('Original versus oracle',repr(a),repr(b))
            assert new.compare(a,b)==expected,('New versus original',repr(a),repr(b));cases+=1
        assert new.zero_bytes==new.flag_calls==0
    for delta in (0x1000,0x10000,0x123000):
        moved=SortVM(relocated(raw,delta),delta=delta)
        for a,b in [('Äpfel.mp3','Björk.mp3'),('中','😀'),('same','same'),('a'*258+'a','a'*258+'b')]:
            assert moved.compare(a,b,callback=True)==(key(a)>key(b))-(key(a)<key(b));cases+=1
    # Invalid unterminated slots: bounded new behavior, not old equivalence.
    m=SortVM(raw);put(m,LEFT,b'x\0'*260);put(m,RIGHT,b'x\0'*260)
    assert invoke(m,0x173d8,[CTX,LEFT,RIGHT])==0;cases+=1
    return dict(cases=cases,deployed_table_entries=len(PAIRS),real_original_mapper_executed=True,
                signed_search_and_raw_tiebreak_retained=True,relocated_bases=3,
                disabled_and_enabled_mapping=True,invalid_260_unit_slots_bounded=True)

def table_parser(raw):
    m=SortVM(raw);m.ranges.append((0x16ce8,0x16e20));cases=0
    for i in (0,25,26,100,200,400,600,734):
        k,w=PAIRS[i];put(m,LEFT,(f'{k:04X},{w:04X}\0').encode('utf-16-le'))
        invoke(m,0x16ce8,[CTX+4,i,LEFT])
        assert m.read(CTX+16+i*4,2)==w and m.read(CTX+18+i*4,2)==k;cases+=1
    return dict(cases=cases,original_text_parser_confirms_fixture_layout=True,
                deployed_table_sha256=hashlib.sha256(TABLE.read_bytes()).hexdigest())

def catalog(raw,names,folder_start=2):
    """Native sort dispatch and record bookkeeping; stable host sort API fixture."""
    m=SortVM(raw);c=SortVM(raw);calls=[]
    put(m,OBJ,bytes(80));put(m,PARENT,bytes(544));m.write(OBJ+0x38,FOLDERS)
    folders=['untouched before 0','untouched before 1',*names,'untouched after']
    for base,size,rows in ((FOLDERS,544,folders),(SONGS,528,names)):
        for i,s in enumerate(rows):
            b=bytearray([0xa5]*size);text=(s+'\0').encode('utf-16-le');b[:520]=bytes(520);b[:len(text)]=text
            struct.pack_into('<I',b,520,i);put(m,base+i*size,b)
    m.hooks[0x12d5c]=lambda v:SONGS;m.hooks[0x12d4c]=lambda v:len(names)
    def sort(v):
        start,n,size,callback=v.reg[4:8];assert callback==0x135f0 and size in (544,528)
        calls.append((start,n,size,callback));rows=[data(v,start+i*size,size) for i in range(n)]
        def compare(a,b):
            put(c,LEFT,a[:520]);put(c,RIGHT,b[:520])
            r=invoke(c,callback,[LEFT,RIGHT]);return -1 if r==0xffffffff else r
        rows.sort(key=cmp_to_key(compare))
        for i,b in enumerate(rows):put(v,start+i*size,b)
        return 0
    m.hooks[0x255c8]=sort
    invoke(m,0x13d88,[OBJ,len(names),folder_start,len(names)],[0,PARENT])
    assert len(calls)==(2 if len(names)>1 else 0)
    expected=sorted(range(len(names)),key=lambda i:key(names[i]))
    for base,size,offset in ((FOLDERS,544,folder_start),(SONGS,528,0)):
        for i,original in enumerate(expected):
            at=base+(offset+i)*size
            assert m.text(at)==names[original] and m.read(at+520)==offset+original
            if size==544:assert m.read(at+0x21a,2)==offset+i
    assert m.text(FOLDERS)=='untouched before 0'
    assert m.text(FOLDERS+544*(len(names)+2))=='untouched after'
    assert [m.read(PARENT+o,2) for o in (0x20e,0x210,0x212,0x214)]==[
        folder_start,len(names),0 if names else 65535,len(names)]
    return data(m,FOLDERS,544*len(folders)),data(m,SONGS,528*len(names)),data(m,PARENT,544),calls

def integration(raw):
    previous=SOURCE.read_bytes();rng=random.Random(705)
    names=['Zebra','a.mp3','A.mp3','École','日本語','😀 music','same','same','a'*258+'b','a'*258+'a']
    cases=0
    for count in (0,1,2,10,64):
        rows=names[:count] if count<=10 else [f'{rng.choice(names[:8])}_{i:03}.mp3' for i in range(count)]
        assert catalog(previous,rows)==catalog(raw,rows);cases+=1
    return dict(cases=cases,native_dispatch_and_record_bookkeeping_executed=True,
                qsort_algorithm_is_host_fixture=True,folder_and_song_sizes=[544,528],
                untouched_records_preserved=True,duplicate_record_order_matches_fixture=True)

def performance(raw):
    rng=random.Random(705);names=[f'{rng.choice(["Björk","Album","Music","Track","Radio"])} {i:03} '+
                               'long filename with artist and title.mp3' for i in range(256)]
    result={};orders=[]
    for label,b in [('previous',SOURCE.read_bytes()),('new',raw)]:
        m=SortVM(b);comparisons=0
        def cmp(a,b):
            nonlocal comparisons
            comparisons+=1;return m.compare(a,b,callback=True)
        orders.append(sorted(names,key=cmp_to_key(cmp)))
        result[label]=dict(comparisons=comparisons,interpreted_steps=m.steps,mapper_calls=m.mapper_calls,
                           memset_bytes=m.zero_bytes,name_unit_reads=m.name_reads)
    assert orders[0]==orders[1] and result['previous']['comparisons']==result['new']['comparisons']
    assert result['new']['mapper_calls']<result['previous']['mapper_calls'] and result['new']['memset_bytes']==0
    return dict(cases=1,tracks=256,**result,native_timing_measured=False,sort_algorithm_is_host_fixture=True,
                old_stack_frame_bytes=2112,new_stack_frame_bytes=80)

def structure(raw,recipe):
    old=SOURCE.read_bytes();a=parsed(old);b=parsed(raw)
    for start,end in [(0x135f0,0x13630),(0x13d88,0x13f10),(0x16cd8,0x173d8),(0x173e8,0x17468)]:
        assert a.get_data(start-0x10000,end-start)==b.get_data(start-0x10000,end-start)
    rows=b.get_data(b.OPTIONAL_HEADER.DATA_DIRECTORY[3].VirtualAddress,b.OPTIONAL_HEADER.DATA_DIRECTORY[3].Size)
    rows=[struct.unpack_from('<5I',rows,i) for i in range(0,len(rows),20)]
    assert next(r for r in rows if r[0]==COMPARE)==(COMPARE,COMPARE+312,0,0,COMPARE+40)
    assert next(r for r in rows if r[0]==0x173d8)[4]==0x173d8
    # No changes outside declared code/table/header edits.
    allowed=[(int(e['offset'],16),int(e['offset'],16)+e['bytes']) for e in recipe['edits']]
    allowed += [(a.OPTIONAL_HEADER.DATA_DIRECTORY[i].get_file_offset()+4,
                 a.OPTIONAL_HEADER.DATA_DIRECTORY[i].get_file_offset()+8) for i in (3,5)]
    assert len(old)==len(raw)
    assert all(x==y or any(lo<=i<hi for lo,hi in allowed) for i,(x,y) in enumerate(zip(old,raw)))
    return dict(cases=1,only_declared_bytes_changed=True,mapper_generator_qsort_dispatch_unchanged=True,
                sorted_nonoverlapping_pdata=True,new_helper_used_bytes=312)

def verify(raw):return dict(table_parser=table_parser(raw),equivalence=equivalence(raw),integration=integration(raw),performance=performance(raw))
