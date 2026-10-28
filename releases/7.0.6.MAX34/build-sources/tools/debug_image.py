"""Guarded MIPS PE extension for MAX19. Never run firmware on the host."""
import hashlib
import re
import struct
import pefile
from patch_usb_reliability import assemble
from patch_shared_mapping_checks import reloc_records
from patch_bt_playback import REGS


def align(n, a=4096): return (n+a-1)&~(a-1)
def sha(b): return hashlib.sha256(b).hexdigest()


class Image:
    def __init__(self, raw, pin, writable=True):
        assert sha(raw)==pin
        self.raw=raw; self.p=pefile.PE(data=raw); self.base=self.p.OPTIONAL_HEADER.ImageBase
        self.out=bytearray(raw); self.text=self.base+align(self.p.OPTIONAL_HEADER.SizeOfImage)
        self.rw=self.text+0xc0000; self.body=bytearray(0xc0000); self.state=bytearray(0x4000)
        self.writable=writable; self.edits=[]; self.routines=[]; self.rows=[]
        self.reloc=reloc_records(self.p); self.imports=[]; self.str_cursor=0x18000
        self.code_cursor=0; self.import_cursor=0x2000; self.exports={}
    def string(self, text, wide=True):
        value=(text+'\0').encode('utf-16-le' if wide else 'ascii')
        at=self.text+self.str_cursor; self.body[self.str_cursor:self.str_cursor+len(value)]=value
        self.str_cursor=align(self.str_cursor+len(value),4); assert self.str_cursor<0x20000
        return at
    def import_at(self, name):
        return next(i.address for d in self.p.DIRECTORY_ENTRY_IMPORT for i in d.imports
                    if i.ordinal==name or (i.name and i.name.decode()==name))
    def api(self,name,delay='nop'):
        return f'la t8, {hex(self.apis[name])}\nlw t9, 0(t8)\njalr t9\n{delay}'
    def edit(self,va,value,reason):
        off=self.p.get_offset_from_rva(va-self.base); self.file_edit(off,value,reason,va)
    def file_edit(self,off,value,reason,va=None):
        self.edits.append(dict(offset=off,va=va,before_hex=bytes(self.out[off:off+len(value)]).hex(),after_hex=value.hex(),reason=reason))
        self.out[off:off+len(value)]=value
    def routine(self, code, capacity=0x1000, frame_bytes=0, regs=()):
        at=self.text+self.code_cursor; self.code_cursor+=capacity; assert self.code_cursor<=0x18000
        return self.routine_at(at,code,capacity,frame_bytes,regs)
    def routine_at(self,at,code,capacity,frame_bytes=0,regs=()):
        lines=[]; custom=[]; pc=at
        for line in code.splitlines():
            line=line.split('#',1)[0].strip()
            if not line: continue
            if line.endswith(':'): lines.append(line); continue
            op=line.split()[0]
            if op in ('j','lwl','lwr','swl','swr','blez','bgez','sync','xori'):
                custom.append((pc,line)); lines.append('nop')
            else: lines.append(line)
            pc+=8 if op=='la' else 4
        raw,recipe,rel=assemble('\n'.join(lines),at,capacity); raw=bytearray(raw)
        rel=[(a+0x10000-self.base,k,c) for a,k,c in rel]
        for pc,line in custom:
            args=[x for x in re.split(r'[\s,()]+',line) if x]; op=args[0]
            if op=='j':
                word=(2<<26)|((int(args[1],0)>>2)&0x3ffffff); rel.append((pc-self.base,5,None))
            elif op=='sync': word=15
            elif op=='xori': word=(14<<26)|(REGS[args[2]]<<21)|(REGS[args[1]]<<16)|(int(args[3],0)&65535)
            elif op in ('blez','bgez'):
                dst=int(recipe['labels'].get(args[2],args[2]),16)
                word=((6 if op=='blez' else 1)<<26)|(REGS[args[1]]<<21)|((1<<16) if op=='bgez' else 0)|(((dst-pc-4)//4)&65535)
            else:
                word=({'lwl':34,'lwr':38,'swl':42,'swr':46}[op]<<26)|(REGS[args[3]]<<21)|(REGS[args[1]]<<16)|(int(args[2],0)&65535)
            struct.pack_into('<I',raw,pc-at,word)
        self.body[at-self.text:at-self.text+capacity]=raw; self.reloc+=rel
        prolog=at+(8+len(regs)*4 if frame_bytes else 0)
        self.rows.append((at,at+recipe['used_bytes'],0,0,prolog))
        self.routines.append(dict(address=at,bytes=recipe['used_bytes'],capacity=capacity,frame_bytes=frame_bytes,registers=list(regs),assembly=code))
        return at
    def hook(self,at,target,call=False):
        size=4 if call else 8
        word=((3 if call else 2)<<26)|((target>>2)&0x3ffffff)
        self.edit(at,struct.pack('<I',word)+(b'\0'*4 if not call else b''),'Reviewed debug hook')
        self.reloc=[r for r in self.reloc if not at-self.base<=r[0]<at-self.base+size]
        self.reloc.append((at-self.base,5,None))
    def clone(self,start):
        d=self.p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        rows=[struct.unpack_from('<5I',self.p.get_data(d.VirtualAddress,d.Size),x) for x in range(0,d.Size,20)]
        row=next(r for r in rows if r[0]==start); length=align(row[1]-start,4)
        target=self.text+self.code_cursor; self.code_cursor+=align(length,0x100)
        value=bytearray(self.p.get_data(start-self.base,length)); shift=target-start
        old_records=reloc_records(self.p);companions={};rewritten=[]
        kinds={a:k for a,k,c in old_records}
        for a,k,c in old_records:
            if k!=4 or not start-self.base<=a<row[1]-self.base:continue
            high=int.from_bytes(self.p.get_data(a,4),'little')
            signed=c if c<32768 else c-65536
            address=(((high&65535)<<16)+signed)&0xffffffff
            if not start<address<row[1]:continue
            low=int.from_bytes(self.p.get_data(a+4,4),'little')
            assert kinds.get(a+4)==2 and high>>26==15 and low>>26==9
            assert (high>>16)&31==(low>>21)&31
            moved=address+shift;off=a+self.base-start
            struct.pack_into('<I',value,off,(high&0xffff0000)|(((moved+0x8000)>>16)&65535))
            struct.pack_into('<I',value,off+4,(low&0xffff0000)|(moved&65535))
            companions[a]=moved&65535
            rewritten.append(dict(original_address=address,new_address=moved,high_instruction=a+self.base))
        for x in range(0,length,4):
            w=struct.unpack_from('<I',value,x)[0]; op=w>>26
            if op in (2,3):
                dst=((start+x+4)&0xf0000000)|((w&0x3ffffff)<<2)
                if start<=dst<row[1]: struct.pack_into('<I',value,x,(op<<26)|((dst+shift)>>2&0x3ffffff))
            elif op in (1,4,5,6,7):
                delta=w&65535; delta=delta if delta<32768 else delta-65536
                dst=start+x+4+delta*4
                if not start<=dst<row[1]:
                    delta=(dst-(target+x+4))//4; assert -32768<=delta<=32767
                    struct.pack_into('<I',value,x,(w&0xffff0000)|(delta&65535))
        self.body[target-self.text:target-self.text+length]=value
        for a,k,c in old_records:
            if start-self.base<=a<row[1]-self.base:self.reloc.append((a+shift,k,companions.get(a,c)))
        self.rows.append((target,target+length,row[2],row[3],target+row[4]-start))
        if not hasattr(self,'clone_evidence'):self.clone_evidence=[]
        self.clone_evidence.append(dict(original=start,clone=target,bytes=length,intra_function_address_rewrites=rewritten))
        return target,row
    def add_import(self,dll,symbol,iat=None):
        if iat is None:
            assert self.writable
            iat=self.rw+self.import_cursor; self.import_cursor+=4
        self.imports.append((dll,symbol,iat)); return iat
    def finish(self):
        p=self.p; base=self.base; body=self.body
        # Import descriptors use copied lookup arrays and the original IAT addresses.
        descriptors=[]; cursor=0x24000
        replacements=getattr(self,'replace_imports',{})
        def descriptor(dll,entries,iat):
            nonlocal cursor
            lookup=self.text+cursor
            vals=[]
            for sym in entries:
                if isinstance(sym,int): vals.append(0x80000000|sym)
                else:
                    name=self.string(sym,False); nameoff=name-self.text
                    # IMAGE_IMPORT_BY_NAME includes a two-byte zero hint.
                    body[nameoff:nameoff+len(sym)+3]=b'\0\0'+sym.encode()+b'\0'
                    self.str_cursor=max(self.str_cursor,align(nameoff+len(sym)+3,4))
                    vals.append(name-base)
            raw=struct.pack('<'+'I'*(len(vals)+1),*vals,0)
            body[cursor:cursor+len(raw)]=raw; cursor+=align(len(raw),4)
            name=self.string(dll,False)
            descriptors.append(struct.pack('<5I',lookup-base,0,0,name-base,iat-base))
        for dll in p.DIRECTORY_ENTRY_IMPORT:
            segment=[]; begin=None; active=dll.dll.decode()
            for entry in dll.imports:
                sym=entry.ordinal if entry.ordinal is not None else entry.name.decode()
                dest,symbol=replacements.get((dll.dll.lower(),sym),(dll.dll.decode(),sym))
                if segment and dest!=active:
                    descriptor(active,segment,begin);segment=[]
                if not segment: begin=entry.address;active=dest
                segment.append(symbol)
            if segment: descriptor(active,segment,begin)
        segment=[]; active=None;begin=None
        for dll,symbol,iat in self.imports:
            if segment and (dll!=active or iat!=begin+len(segment)*4):
                descriptor(active,segment,begin);segment=[]
            if not segment:active=dll;begin=iat
            segment.append(symbol)
        if segment:descriptor(active,segment,begin)
        desc_at=align(cursor,16); raw=b''.join(descriptors)+bytes(20)
        body[desc_at:desc_at+len(raw)]=raw
        directory=p.OPTIONAL_HEADER.DATA_DIRECTORY[1]
        self.file_edit(directory.get_file_offset(),struct.pack('<II',self.text-base+desc_at,len(raw)),'Preserved IATs with debug interception/imports')
        # Keep old exports/ordinals and add the explicitly named debug adapters.
        if self.exports:
            orig=p.DIRECTORY_ENTRY_EXPORT; funcs=list(orig.symbols)
            low=orig.struct.Base; count=orig.struct.NumberOfFunctions
            eat=[0]*count; names={}
            for sym in funcs:
                assert not sym.forwarder
                eat[sym.ordinal-low]=sym.address
                if sym.name:names[sym.name.decode()]=sym.ordinal-low
            for name,at in self.exports.items(): names[name]=len(eat);eat.append(at-base)
            off=align(desc_at+len(raw),16); eat_at=off+40; name_at=eat_at+len(eat)*4; ord_at=name_at+len(names)*4
            blob=bytearray(40+len(eat)*4+len(names)*6)
            struct.pack_into('<'+'I'*len(eat),blob,40,*eat)
            for j,(name,ordinal) in enumerate(sorted(names.items())):
                nameva=self.string(name,False)
                struct.pack_into('<I',blob,name_at-off+j*4,nameva-base)
                struct.pack_into('<H',blob,ord_at-off+j*2,ordinal)
            struct.pack_into('<IIHH7I',blob,0,0,0,0,0,self.string('CmnDll.dll',False)-base,low,len(eat),len(names),self.text-base+eat_at,self.text-base+name_at,self.text-base+ord_at)
            body[off:off+len(blob)]=blob
            directory=p.OPTIONAL_HEADER.DATA_DIRECTORY[0]
            self.file_edit(directory.get_file_offset(),struct.pack('<II',self.text-base+off,len(blob)),'Original export ordinals and debug adapters')
        # Original rows stay byte-exact; add leaf metadata for redirected entries.
        directory=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        original=[struct.unpack_from('<5I',p.get_data(directory.VirtualAddress,directory.Size),x) for x in range(0,directory.Size,20)]
        redirected={e['va'] for e in self.edits if e['va'] is not None and len(bytes.fromhex(e['after_hex']))==8 and int.from_bytes(bytes.fromhex(e['after_hex'])[:4],'little')>>26==2}
        rows=sorted([(a,b,0,0,a) if a in redirected else (a,b,c,d,e) for a,b,c,d,e in original]+self.rows)
        assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
        pd_at=0x30000; pd=b''.join(struct.pack('<5I',*r) for r in rows);body[pd_at:pd_at+len(pd)]=pd
        for j,row in enumerate(rows):
            for k,v in enumerate(row):
                if v:self.reloc.append((self.text-base+pd_at+j*20+k*4,3,None))
        self.file_edit(directory.get_file_offset(),struct.pack('<II',self.text-base+pd_at,len(pd)),'Cumulative function metadata')
        # The IAT directory is optional; old contiguous ranges no longer cover additions.
        self.file_edit(p.OPTIONAL_HEADER.DATA_DIRECTORY[12].get_file_offset(),bytes(8),'Descriptors define original and added IATs')
        records=sorted(self.reloc); assert len({x[0] for x in records})==len(records)
        pages={}
        for at,kind,comp in records:
            page=at&~4095;pages.setdefault(page,[]).append(kind<<12|at-page)
            if kind==4:pages[page].append(comp)
        relocation=bytearray()
        for page,vals in sorted(pages.items()):
            if len(vals)%2:vals.append(0)
            relocation+=struct.pack('<II',page,8+len(vals)*2)+struct.pack('<'+'H'*len(vals),*vals)
        reloc_at=align(pd_at+len(pd));assert reloc_at+len(relocation)<len(body)
        body[reloc_at:reloc_at+len(relocation)]=relocation
        directory=p.OPTIONAL_HEADER.DATA_DIRECTORY[5]
        self.file_edit(directory.get_file_offset(),struct.pack('<II',self.text-base+reloc_at,len(relocation)),'Cumulative relocation records')
        body=body[:align(reloc_at+len(relocation))]
        header=p.sections[-1].get_file_offset()+40; num=2 if self.writable else 1
        assert header+num*40<=p.OPTIONAL_HEADER.SizeOfHeaders and not any(self.raw[header:header+num*40])
        off=align(len(self.out),512); self.out+=bytes(off-len(self.out))+body
        secs=[(b'.mxdebug',len(body),self.text-base,len(body),off,0x60000020)]
        if self.writable:
            self.out+=self.state;secs.append((b'.mxdbgst',len(self.state),self.rw-base,len(self.state),off+len(body),0xc0000040))
        for j,(name,vs,rva,size,ptr,flags) in enumerate(secs):self.file_edit(header+j*40,struct.pack('<8s8I',name,vs,rva,size,ptr,0,0,0,flags),'Debug code or private state')
        self.file_edit(p.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),struct.pack('<H',len(p.sections)+num),'Section count')
        for key,v in [('SizeOfImage',(self.rw+len(self.state) if self.writable else self.text+len(body))-base),('SizeOfCode',p.OPTIONAL_HEADER.SizeOfCode+len(body)),('SizeOfInitializedData',p.OPTIONAL_HEADER.SizeOfInitializedData+(len(self.state) if self.writable else 0))]:
            self.file_edit(p.OPTIONAL_HEADER.get_field_absolute_offset(key),struct.pack('<I',v),key)
        cs=p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum');struct.pack_into('<I',self.out,cs,0)
        final=pefile.PE(data=bytes(self.out));struct.pack_into('<I',self.out,cs,final.generate_checksum());final.close()
        result=bytes(self.out)
        return result,dict(input_sha256=sha(self.raw),output_sha256=sha(result),code_va=self.text,state_va=self.rw if self.writable else None,edits=self.edits,routines=self.routines,helper_rows=self.rows,clones=getattr(self,'clone_evidence',[]),relocations=records,native_executed=False)
