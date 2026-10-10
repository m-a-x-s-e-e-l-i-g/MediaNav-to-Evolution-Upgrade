"""Execute candidate MIPS instructions against explicit file/GDI API fixtures.

This verifies native-code control flow, not Windows CE/NAND/MCU behavior.
"""
import copy
import hashlib
import json
import re
from pathlib import Path

import pefile
from inspect_wave_queue import STOP as RETURN
from inspect_bt_pairing import put, data
from verify_ui_english import UiVM
import patch_updater_copy_safety as patcher

ROOT=Path(__file__).resolve().parents[1]
STACK, OBJECT, INPUT, DEST = 0x68000000, 0x46000000, 0x47000000, 0x47001000
STAGING='\\Storage Card3\\upgrade'
VERSION='\\Storage Card\\System\\Version_Info.txt'
RECEIPT=STAGING+'\\filecopy_success.bin'


class WorkerStopped(Exception):
    pass


def norm(path):
    return '\\'+ '\\'.join(p for p in re.split(r'\\+',path) if p).lower() if path else ''


class Fixture:
    def __init__(self, raw, files=None, dirs=None, fault=None, reverse=False):
        starts=sorted([patcher.COPY,patcher.TREE,patcher.ERROR,patcher.STOP,
                       patcher.STAGE,patcher.BACKUP,patcher.RESTORE,patcher.AMBIGUOUS,
                       patcher.PAINT,patcher.STARTUP,patcher.DIRECTORY,patcher.MOUNT,patcher.FORMAT])
        self.vm=UiVM(pefile.PE(data=raw),list(zip(starts,starts[1:]+[patcher.TEXT+patcher.TEXT_BYTES])))
        self.files={norm(p):bytes(b) for p,b in (files or {}).items()}
        self.dirs={norm(p) for p in (dirs or ['\\Storage Card','\\Storage Card2','\\Storage Card3','\\Storage Card4'])}
        for p in self.files:
            parent=p.rsplit('\\',1)[0]
            while parent:
                self.dirs.add(parent);parent=parent.rsplit('\\',1)[0]
        self.dirs.add('')
        self.fault=fault or {};self.reverse=reverse
        self.handles={};self.finds={};self.next_handle=0x5000
        self.events=[];self.error=0;self.stopped=False;self.original_called=False
        self.original_cleanup=False;self.original_format=False
        self.vm.write(0x38f18,OBJECT)
        for off,value in [(0x61c,0),(0x620,0),(0x624,100000),(0x628,0),(0x630,0x5555)]:
            self.vm.write(OBJECT+off,value)
        self.before=copy.deepcopy(self.files)
        api_names=['copy','open','read','size','close','attrs','last','first','next','find_close','mkdir','exit']
        iats=[0x370dc,0x3704c,0x37054,0x37050,0x37028,0x3705c,0x37008,0x3716c,0x37178,0x37170,0x3717c,0x37020]
        for i,(name,iat) in enumerate(zip(api_names,iats)):
            address=0xf1000000+4*i
            self.vm.write(iat,address)
            self.vm.hooks[address]=getattr(self,'api_'+name)
        self.vm.hooks.update({0x2a86c:self.format,0x2a87c:self.icmp,
                              0x19714:self.progress,0x2a1c0:self.gdi,0x2a2c0:self.gdi,
                              0x14eb0:self.original,0x2a1e0:self.gdi,0x2a200:self.gdi,
                              0x2a3d0:self.gdi,0x2a3e0:self.gdi,0x2b68c:self.zero,
                              0x2a1f0:self.gdi,0x2a380:self.gdi,0x2a400:self.draw,
                              0x2a1d0:self.gdi,0x18e88:self.old_paint,0x1a3a4:self.format_volume})

    def fail(self, api, path=None):
        if self.fault.get('api')!=api:return False
        return not self.fault.get('path') or norm(path or '')==norm(self.fault['path'])

    def new_handle(self):
        self.next_handle+=1;return self.next_handle

    def log(self,api,**fields):
        self.events.append(dict(api=api,**fields))

    def api_copy(self,m):
        src,dst=norm(m.text(m.reg[4])),norm(m.text(m.reg[5]))
        assert m.reg[6]==0
        self.log('copy',source=src,target=dst)
        if src not in self.files:self.error=2;return 0
        if dst.rsplit('\\',1)[0] not in self.dirs:self.error=3;return 0
        b=self.files[src]
        if self.fail('copy',src):
            if self.fault.get('partial'):self.files[dst]=b[:len(b)//2]
            self.error=112;return 0
        if self.fail('corrupt',src) and b:b=b[:len(b)//2]+bytes([b[len(b)//2]^1])+b[len(b)//2+1:]
        if self.fail('truncate',src):b=b[:-1]
        self.files[dst]=b;return 1

    def api_open(self,m):
        path=norm(m.text(m.reg[4]));self.log('open',path=path)
        assert m.reg[5:8]==[0x80000000,1,0]
        assert [m.read(m.reg[29]+i) for i in (0x10,0x14,0x18)]==[3,0x80,0]
        if path not in self.files or self.fail('open',path):self.error=5;return 0xffffffff
        h=self.new_handle();self.handles[h]=dict(path=path,pos=0);return h

    def api_size(self,m):
        h=self.handles[m.reg[4]]
        self.log('size',path=h['path'])
        m.write(m.reg[5],0)
        if self.fail('size',h['path']):self.error=5;return 0xffffffff
        if self.fail('high_size',h['path']):m.write(m.reg[5],1)
        return len(self.files[h['path']])

    def api_read(self,m):
        h=self.handles[m.reg[4]];path=h['path'];requested=m.reg[6]
        assert requested==4096 and m.read(m.reg[29]+0x10)==0
        self.log('read',path=path,position=h['pos'])
        if self.fail('read',path):m.write(m.reg[7],0);self.error=5;return 0
        b=self.files[path][h['pos']:h['pos']+requested]
        if self.fail('early_eof',path):b=b''
        if self.fail('short_read',path):b=b[:max(1,len(b)//2)]
        put(m,m.reg[5],b);m.write(m.reg[7],len(b));h['pos']+=len(b)
        return 1

    def api_close(self,m):
        h=self.handles.pop(m.reg[4]);self.log('close',path=h['path'])
        if self.fail('close',h['path']):self.error=5;return 0
        return 1

    def api_attrs(self,m):
        p=norm(m.text(m.reg[4]));self.log('attrs',path=p)
        if self.fail('attrs',p):self.error=5;return 0xffffffff
        if p in self.dirs:return 0x10
        if p in self.files:return 0x80
        self.error=2;return 0xffffffff

    def api_last(self,m):return self.error

    def api_mkdir(self,m):
        p=norm(m.text(m.reg[4]));self.log('mkdir',path=p)
        if self.fail('mkdir',p):self.error=5;return 0
        if p in self.files or p in self.dirs:self.error=183;return 0
        if p.rsplit('\\',1)[0] not in self.dirs:self.error=3;return 0
        self.dirs.add(p);return 1

    def find_record(self,m,address,path):
        put(m,address,bytes(0x230))
        m.write(address,0x10 if path in self.dirs else 0x80)
        m.write(address+0x1c,0)
        m.write(address+0x20,len(self.files.get(path,b'')))
        put(m,address+0x28,(path.rsplit('\\',1)[-1]+'\0').encode('utf-16-le'))

    def api_first(self,m):
        p=norm(m.text(m.reg[4]));parent=p.rsplit('\\',1)[0];self.log('find_first',path=parent)
        if self.fail('find_first',parent):self.error=5;return 0xffffffff
        if parent not in self.dirs:self.error=3;return 0xffffffff
        children=sorted([p for p in self.dirs|set(self.files) if p and p.rsplit('\\',1)[0]==parent],reverse=self.reverse)
        if not children:self.error=2;return 0xffffffff
        children=[parent+'\\.',parent+'\\..']+children
        h=self.new_handle();self.finds[h]=dict(parent=parent,children=children,pos=0)
        self.find_record(m,m.reg[5],children[0]);return h

    def api_next(self,m):
        f=self.finds[m.reg[4]];self.log('find_next',path=f['parent'])
        if self.fail('find_next',f['parent']):self.error=5;return 0
        f['pos']+=1
        if f['pos']==len(f['children']):self.error=18;return 0
        self.find_record(m,m.reg[5],f['children'][f['pos']]);return 1

    def api_find_close(self,m):
        f=self.finds.pop(m.reg[4]);self.log('find_close',path=f['parent'])
        if self.fail('find_close',f['parent']):self.error=5;return 0
        return 1

    def api_exit(self,m):
        self.log('ExitThread',code=m.reg[4]);self.stopped=True
        assert m.read(0x3784c)==3007
        raise WorkerStopped()

    def format(self,m):
        fmt=m.text(m.reg[6]);capacity=m.reg[5];arg=m.reg[7]
        if fmt=='%s\\*.*':text=m.text(arg)+'\\*.*'
        elif fmt=='%s\\%s':text=m.text(arg)+'\\'+m.text(m.read(m.reg[29]+0x10))
        elif fmt in (patcher.STRINGS['body'],patcher.STRINGS['format_error']):
            text=fmt.replace('%u',str(arg)).replace('%s',m.text(m.read(m.reg[29]+0x10)))
        else:raise AssertionError(fmt)
        if len(text)>=capacity:return 0xffffffff
        put(m,m.reg[4],(text+'\0').encode('utf-16-le'));return len(text)

    def icmp(self,m):return int(m.text(m.reg[4]).casefold()!=m.text(m.reg[5]).casefold())
    def progress(self,m):self.log('progress',step=m.read(OBJECT+0x620));return 1
    def gdi(self,m):self.log('gdi');return 0x7777
    def draw(self,m):self.log('DrawTextW',text=m.text(m.reg[5]),flags=m.read(m.reg[29]+0x10));return 1
    def zero(self,m):put(m,m.reg[4],bytes(m.reg[6]));return m.reg[4]
    def original(self,m):self.original_called=True;self.log('original_startup');return 1
    def old_paint(self,m):self.log('original_paint');return 1
    def format_volume(self,m):
        assert m.reg[4:7]==[1,0,0]
        self.original_format=True;self.log('format_volume')
        if self.fault.get('api')=='format':return 0
        self.files={p:b for p,b in self.files.items() if not p.startswith(norm('\\Storage Card2')+'\\')}
        self.dirs={p for p in self.dirs if not p.startswith(norm('\\Storage Card2')+'\\')}
        if self.fault.get('api')=='format_mount':self.dirs.discard(norm('\\Storage Card2'))
        return 1

    def run(self,entry,args):
        put(self.vm,INPUT,(args[0]+'\0').encode('utf-16-le')) if args and isinstance(args[0],str) else None
        values=[]
        for i,a in enumerate(args):
            if isinstance(a,str):
                at=INPUT+i*0x1000;put(self.vm,at,(a+'\0').encode('utf-16-le'));values.append(at)
            else:values.append(a)
        saved={r:0x12340000+r for r in (*range(16,24),30)}
        for r,v in saved.items():self.vm.reg[r]=v
        self.vm.reg[29],self.vm.reg[31]=STACK,RETURN
        for i,v in enumerate(values):self.vm.reg[4+i]=v
        try:self.vm.run(entry,{RETURN},limit=2000000)
        except WorkerStopped:pass
        if not self.stopped:
            assert self.vm.reg[29]==STACK
            assert all(self.vm.reg[r]==v for r,v in saved.items()),'Callee-saved register changed'
        assert not self.handles and not self.finds,'File/enumeration handle leak'
        for p,b in self.before.items():
            if p.startswith(norm(STAGING)+'\\') or p.startswith(norm('\\Storage Card3\\TFAT')+'\\'):
                assert self.files[p]==b,'Recovery source lost or changed'
        return self.vm.reg[2]


def verify(raw):
    cases=[]
    def save(name,f):
        cases.append(dict(name=name,stopped=f.stopped,error=f.vm.read(patcher.CODE),events=f.events))
    # Copy/readback: boundary sizes and every fault direction, including partial
    # mutation on CopyFile(FALSE) and success with wrong bytes.
    source='\\Storage Card3\\upgrade\\a.bin';target='\\Storage Card\\a.bin'
    for n in (0,1,4095,4096,4097,8192):
        f=Fixture(raw,{source:bytes((i%251 for i in range(n)))})
        assert f.run(patcher.COPY,[source,target])==1
        assert f.files[norm(source)]==f.files[norm(target)]
        save(f'copy-{n}',f)
    for api in ('copy','corrupt','truncate','open','size','high_size','read','early_eof','short_read','close'):
        for path in ([source,target] if api in ('open','size','high_size','read','early_eof','short_read','close') else [source]):
            f=Fixture(raw,{source:b'A'*4097},fault=dict(api=api,path=path,partial=True))
            assert f.run(patcher.COPY,[source,target])==0
            assert f.vm.read(patcher.CODE)!=0
            save(f'copy-fault-{api}-{path}',f)
    files={STAGING+'\\Storage Card\\System\\Blue.exe':b'blue-new',
           STAGING+VERSION:b'7.0.7.DEV\r\n',
           STAGING+'\\Storage Card4\\NNG\\nngnavi.exe':b'nav-new',
           RECEIPT:b'',VERSION:b'old',
           '\\Storage Card4\\NNG\\nngnavi.exe':b'nav-old'}
    for reverse in (False,True):
        f=Fixture(raw,files,reverse=reverse)
        assert f.run(patcher.STAGE,[OBJECT,STAGING,''])==1
        copies=[e for e in f.events if e['api']=='copy']
        assert copies[-1]['target']==norm(VERSION)
        assert not any(e['source']==norm(RECEIPT) for e in copies)
        assert f.files[norm(VERSION)]==b'7.0.7.DEV\r\n'
        save(f'stage-success-reverse-{reverse}',f)
    for api in ('copy','corrupt','truncate','open','read','close','find_first','find_next','find_close','mkdir'):
        fault=dict(api=api,path=STAGING+'\\Storage Card\\System\\Blue.exe')
        if api in ('find_first','find_next','find_close'):fault['path']=STAGING
        if api=='mkdir':
            fault['path']='\\Storage Card\\System'
            # Unlike already-existing directory fallback, create really fails.
            modified={k:v for k,v in files.items() if norm(k)!=norm(VERSION)}
        else:modified=files
        if api in ('open','read','close'):fault['path']='\\Storage Card\\System\\Blue.exe'
        f=Fixture(raw,modified,fault=fault)
        f.run(patcher.STAGE,[OBJECT,STAGING,''])
        assert f.stopped and f.vm.read(patcher.CODE)!=0
        assert f.files.get(norm(VERSION),b'old')==b'old'
        assert not any(e['api']=='progress' and e['step']==10 for e in f.events)
        save(f'stage-failure-{api}',f)
        # A fresh process after the fault clears repeats the copy from retained
        # staging, including a destination partially changed by CopyFile(FALSE).
        reboot=Fixture(raw,f.files,reverse=True)
        assert reboot.run(patcher.STAGE,[OBJECT,STAGING,''])==1
        assert reboot.files[norm(VERSION)]==b'7.0.7.DEV\r\n'
        save(f'stage-reboot-after-{api}',reboot)
    # Execute the patched call inside the original controller, through its
    # original cleanup call. Failures must never reach that call.
    for api in (None,'copy','corrupt','find_next'):
        f=Fixture(raw,files,fault=dict(api=api,path=STAGING if api=='find_next' else STAGING+'\\Storage Card\\System\\Blue.exe'))
        f.vm.ranges.append((0x152fc,0x153dc))
        f.vm.reg[29],f.vm.reg[31]=STACK,RETURN
        f.vm.reg[16],f.vm.reg[21],f.vm.reg[22],f.vm.reg[23]=0x40000,INPUT,0x30000,1
        put(f.vm,INPUT,(STAGING+'\0').encode('utf-16-le'));put(f.vm,STACK+0x28,b'\0\0')
        f.vm.write(0x38f14,0)
        f.vm.hooks[0x2a0d0]=lambda m: 0
        def cleanup(m):
            assert norm(m.text(m.reg[5]))==norm(STAGING)
            assert f.vm.read(patcher.CODE)==0
            for name in ('\\Storage Card\\System\\Blue.exe','\\Storage Card4\\NNG\\nngnavi.exe',VERSION):
                assert f.files[norm(name)]==f.files[norm(STAGING+name)]
            assert norm(RECEIPT) in f.files
            f.original_cleanup=True;f.log('caller_cleanup')
            f.files={p:b for p,b in f.files.items() if not p.startswith(norm(STAGING)+'\\')}
            return 1
        f.vm.hooks[0x17fe0]=cleanup
        try:f.vm.run(0x152fc,{0x153d8},limit=2000000)
        except WorkerStopped:pass
        assert f.stopped==(api is not None)
        assert f.original_cleanup==(api is None)
        if api is not None:
            assert f.files[norm(VERSION)]==b'old' and norm(RECEIPT) in f.files
        assert not f.handles and not f.finds
        save(f'original-stage-caller-{api}',f)
    for entry,src,dst in [(patcher.BACKUP,'\\Storage Card2','\\Storage Card3\\TFAT'),
                          (patcher.RESTORE,'\\Storage Card3\\TFAT','\\Storage Card2')]:
        for api in (None,'copy','corrupt','find_next'):
            p=src+'\\MgrSys.cfg'
            f=Fixture(raw,{p:b'unique-setting'},fault=dict(api=api,path=src if api=='find_next' else p))
            f.run(entry,[OBJECT,src,dst])
            assert f.stopped==(api is not None)
            assert f.files[norm(p)]==b'unique-setting'
            save(f'settings-{hex(entry)}-{api}',f)
    for fault in (None,'backup_copy','restore_copy','format','format_mount'):
        config='\\Storage Card2\\MgrSys.cfg';saved='\\Storage Card3\\TFAT\\MgrSys.cfg'
        actual={'api':'copy','path':config if fault=='backup_copy' else saved} if fault in ('backup_copy','restore_copy') else {'api':fault}
        f=Fixture(raw,{config:b'unique-setting','\\Storage Card2\\scan_done_flag.bin':b''},fault=actual)
        f.vm.ranges.append((0x15180,0x151c0))
        f.vm.reg[29],f.vm.reg[31]=STACK,RETURN
        f.vm.reg[22]=0x40000
        try:f.vm.run(0x15180,{0x151c0},limit=2000000)
        except WorkerStopped:pass
        assert f.stopped==(fault is not None)
        assert f.original_format!=(fault=='backup_copy')
        if fault!='backup_copy':assert f.files[norm(saved)]==b'unique-setting'
        if fault is None:assert f.files[norm(config)]==b'unique-setting'
        assert not f.handles and not f.finds
        save(f'original-backup-format-restore-caller-{fault}',f)
    for pending in ('none','valid','no_receipt','stage_access','missing_mount'):
        f=Fixture(raw,files if pending=='valid' else {})
        if pending=='no_receipt':f.dirs.add(norm(STAGING))
        if pending=='stage_access':f.fault=dict(api='attrs',path=STAGING)
        if pending=='missing_mount':f.dirs.discard(norm('\\Storage Card3'))
        f.run(patcher.STARTUP,[])
        assert f.original_called==(pending in ('none','valid'))
        assert f.stopped==(pending not in ('none','valid'))
        save(f'startup-{pending}',f)
    for entry,volume,args in [(patcher.STAGE,'\\Storage Card',[OBJECT,STAGING,'']),
                              (patcher.STAGE,'\\Storage Card4',[OBJECT,STAGING,'']),
                              (patcher.BACKUP,'\\Storage Card2',[OBJECT,'\\Storage Card2','\\Storage Card3\\TFAT']),
                              (patcher.RESTORE,'\\Storage Card2',[OBJECT,'\\Storage Card3\\TFAT','\\Storage Card2'])]:
        f=Fixture(raw,files);f.dirs.discard(norm(volume))
        f.run(entry,args)
        assert f.stopped and not any(e['api']=='copy' for e in f.events)
        assert norm(volume) not in f.dirs
        save(f'missing-volume-{hex(entry)}-{volume}',f)
    for fault in (None,'format','format_mount'):
        f=Fixture(raw,fault=dict(api=fault))
        f.run(patcher.FORMAT,[1,0,0])
        assert f.stopped==(fault is not None)
        save(f'format-guard-{fault}',f)
    f=Fixture(raw,{'\\Storage Card3\\TFAT\\MgrSys.cfg':b'backup',
                   '\\Storage Card2\\scan_done_flag.bin':b''})
    f.run(patcher.AMBIGUOUS,[])
    assert f.stopped and f.vm.read(patcher.CODE)==5001
    assert not any(e['api'] in ('copy','mkdir') for e in f.events)
    save('ambiguous-checkpoint-preserves-backup',f)
    # Error screen is independent from bitmap/language loading; repaint repeats
    # the same durable in-process error state. Healthy paints delegate unchanged.
    for error in (0,112,5001,5002):
        f=Fixture(raw)
        f.vm.write(patcher.CODE,error)
        put(f.vm,patcher.PATH,'\\Storage Card3\\upgrade\\Blue.exe\0'.encode('utf-16-le'))
        f.run(patcher.PAINT,[OBJECT,0x5555])
        draws=[e for e in f.events if e['api']=='DrawTextW']
        assert bool(draws)==bool(error)
        if error:assert f'Error {error}' in draws[0]['text'] and draws[0]['flags']==17
        save(f'paint-{error}',f)
    # Execute the existing hit-test bytes: former Start/Cancel coordinates must
    # be inactive on the dedicated stopped-installation phase.
    for x,y in [(50,440),(500,440),(400,200)]:
        f=Fixture(raw);f.vm.ranges.append((0x16300,0x16394))
        f.vm.write(0x3784c,3007)
        assert f.run(0x16300,[x,y])==0xffffffff
        save(f'error-screen-disabled-buttons-{x}-{y}',f)
    for count in (0,1,5,9,10,11,0xffffffff):
        f=Fixture(raw)
        f.vm.ranges.append((0x192a0,0x1933c))
        f.vm.reg[29]=STACK;f.vm.reg[22]=OBJECT
        f.vm.reg[17],f.vm.reg[18],f.vm.reg[23]=0x1111,0x2222,0xcc0020
        f.vm.write(OBJECT+0x620,count)
        cells=[]
        def blit(m):
            cells.append((m.reg[5],m.read(m.reg[29]+0x18)))
            assert m.reg[6:8]==[296,36]
            assert m.read(m.reg[29]+0x10)==18
            return 1
        f.vm.hooks[0x2a3a0]=blit
        f.vm.run(0x192a0,{0x19664})
        assert [x for x,_ in cells]==[216+37*i for i in range(10)]
        assert [sx for _,sx in cells]==[36 if i<count else 0 for i in range(10)]
        save(f'verified-copy-progress-{count}',f)
    for source_path in [STAGING+'\\'+('x'*240)+'\\file.bin',
                        STAGING+'\\'+'\\'.join(['a']*17)+'\\file.bin']:
        f=Fixture(raw,{source_path:b'data'})
        assert f.run(patcher.TREE,[STAGING,'',1,0])==0
        assert f.vm.read(patcher.CODE)==111
        save(f'bounded-recursion-or-path-{len(source_path)}',f)
    unicode_source=STAGING+'\\maps\\caf\u00e9.bin'
    f=Fixture(raw,{unicode_source:b'unicode-name'})
    assert f.run(patcher.TREE,[STAGING,'',0,0])==1
    assert f.files[norm('\\maps\\caf\u00e9.bin')]==b'unicode-name'
    save('unicode-path',f)
    # Smoke every real previous-release pathname with tiny representative
    # content. This covers traversal/layout, not those files' full contents.
    manifest=json.loads((ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade/build-manifest.json').read_text(encoding='utf-8'))
    samples={STAGING+'\\'+row['path'].removeprefix('upgrade/').replace('/','\\'):
             hashlib.sha256(row['path'].encode()).digest() for row in manifest['verification']['members']}
    samples[STAGING+VERSION]=b'7.0.7.DEV\r\n';samples[RECEIPT]=b''
    f=Fixture(raw,samples,reverse=True)
    assert f.run(patcher.STAGE,[OBJECT,STAGING,''])==1
    copies=[e for e in f.events if e['api']=='copy']
    assert len(copies)==1918 and copies[-1]['target']==norm(VERSION)
    for row in manifest['verification']['members']:
        target='\\'+row['path'].removeprefix('upgrade/').replace('/','\\')
        assert f.files[norm(target)]==samples[STAGING+target]
    save('all-1918-release-paths-representative-bytes',f)
    return dict(cases=len(cases),traces=cases,
                limits='Actual MIPS instructions, explicit CE/file/GDI fixtures; no CE renderer, NAND durability or flash test.')


def main():
    original=(ROOT/'build/ui-english-development-01/payload/upgrade/Storage Card/System/UpgradeManager.exe').read_bytes()
    candidate,recipe=patcher.patch(original)
    report=verify(candidate)
    report.update(sha256=hashlib.sha256(candidate).hexdigest(),recipe=recipe,
                  tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    out=ROOT/'analysis/firmware/updater-copy-safety-prototype.json'
    out.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(f"PASS: {report['cases']} original/candidate instruction cases; internal prototype only.")


if __name__=='__main__':main()
