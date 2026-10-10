"""Check original cover callers, strict title bounds and unlocked other widgets."""
import hashlib
import json
from pathlib import Path
from verify_usb_status_consumers import Fixture,call,MAP,OBJ,SOURCE,DIALOG,OWNER,OLD,NEW,DEFAULT
from verify_usb_input_safety import relocated
from inspect_bt_pairing import put,data

ROOT=Path(__file__).resolve().parents[1]
BUILD=ROOT/'build/usb-status-consumers-development-01'

def verify(app,usb,ar,ur):
    traces=[]
    for delta in (0,0x10000,0x120000,0x500000):
        ai=app if not delta else relocated(app,delta);ui=usb if not delta else relocated(usb,delta)
        for start,end in ((0x19508,0x19564),(0x1a60c,0x1a69c),(0x1ad84,0x1ae54)):
            f=Fixture(ui,ur,delta);owner=SOURCE-0x1ad8;put(f.m,owner,bytes(0x2a00))
            put(f.m,SOURCE+0xe4e,OLD.to_bytes(4,'little'))
            f.m.ranges.append((start+delta,end+delta))
            f.m.hooks.update({0x174f8+delta:lambda m:0,0x23580+delta:lambda m:0,0x253dc+delta:f.memset})
            call(f.m,start+delta,[owner]);f.complete()
            assert OLD not in f.alive and data(f.m,MAP+0xe4e,4)==data(f.m,SOURCE+0xe4e,4)==bytes(4)
            traces.append(dict(name='complete original destructor/clear/reset caller',start=hex(start),delta=delta,events=f.events))
        f=Fixture(ui,ur,delta);owner=SOURCE-0x1ad8;put(f.m,owner,bytes(0x2a00));put(f.m,SOURCE+0xe4e,OLD.to_bytes(4,'little'))
        f.m.ranges.append((0x1a574+delta,0x1a5c4+delta));f.m.reg[18]=owner;f.m.reg[21]=NEW
        f.m.run(0x1a574+delta,{0x1a5c4+delta});f.complete()
        assert OLD not in f.alive and data(f.m,MAP+0xe4e,4)==data(f.m,SOURCE+0xe4e,4)==NEW.to_bytes(4,'little')
        traces.append(dict(name='original artwork replacement/install/publication tail',delta=delta,events=f.events))
        f=Fixture(ui,ur,delta)
        def failed_delete(m):
            assert f.owned and m.reg[4]==OLD and data(m,MAP+0xe4e,4)==data(m,SOURCE+0xe4e,4)==bytes(4)
            f.clobber();return 0
        f.m.hooks[0x2516c+delta]=failed_delete
        assert call(f.m,ur['code_va']+0x500+delta,[OLD,SOURCE+0xe4e])==0
        f.complete();assert OLD in f.alive
        traces.append(dict(name='DeleteObject failure leaves OS handle alive but unpublished',delta=delta))
        f=Fixture(ai,ar,delta);put(f.m,MAP+0x20e,('X'*260).encode('utf-16-le'));reads=[];original=f.m.read
        def bounded(at,size=4):
            if MAP<=at<MAP+0xe56:
                assert MAP+0x20e<=at and at+size<=MAP+0x416
                reads.append(at-MAP)
            return original(at,size)
        f.m.read=bounded;call(f.m,0x1def8+delta,[]);f.complete()
        assert f.shown==[('standard','X'*259)] and max(reads)==0x415
        traces.append(dict(name='unterminated title has exact source read bounds',delta=delta,last_byte_offset=hex(max(reads))))
        f=Fixture(ai,ar,delta);f.m.write(OBJ+0xc4,0)
        call(f.m,0x1def8+delta,[]);call(f.m,0x4dcc8+delta,[DIALOG,0,1]);f.complete()
        assert not f.shown and not f.texts
        traces.append(dict(name='NULL source skips text update without dereference',delta=delta))
        f=Fixture(ai,ar,delta);widget=DIALOG+0x8e0;f.m.write(widget+0x3c,DEFAULT)
        for entry in (0x138860,0x138ba4):call(f.m,entry+delta,[widget,0,OWNER+0x10])
        f.complete();assert f.draws==[DEFAULT,DEFAULT] and not f.events
        traces.append(dict(name='untracked widget keeps original drawing without mutex APIs',delta=delta))
    return dict(cases=len(traces),traces=traces,actual_original_callers=True,
                mutex_gdi_and_scheduler_are_fixtures=True,native_executed=False,hardware_tested=False)

def main():
    manifest=json.loads((BUILD/'manifest.json').read_bytes())
    app=(BUILD/'payload/upgrade/Storage Card/System/AppMain.exe').read_bytes()
    usb=(BUILD/'payload/upgrade/Storage Card/System/MgrUSB.exe').read_bytes()
    for name,raw in [('AppMain',app),('MgrUSB',usb)]:
        assert hashlib.sha256(raw).hexdigest()==next(r['sha256'] for r in manifest['members'] if r['path'].endswith('/'+name+'.exe'))
    proof=verify(app,usb,manifest['recipes']['app'],manifest['recipes']['usb'])
    proof.update(app_sha256=hashlib.sha256(app).hexdigest(),usb_sha256=hashlib.sha256(usb).hexdigest(),
                 tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    path=ROOT/'analysis/firmware/usb-cover-callers-audit.json';assert not path.exists()
    path.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8');print(json.dumps(dict(cases=proof['cases'])))

if __name__=='__main__':main()
