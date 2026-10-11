"""Replay captured SDP fields through installed native discovery/cover pipeline.

Only SDP values are captured; handle/OBEX/CE/GDI success remains fixture-driven.
"""
import json
import struct
import sys
import patch_max10_artwork as p
sys.path.insert(0,str(p.REPO/'tools'))
import pefile
from verify_max09_artwork import DiscoveryBlue, CONFIG, LIST, RECORD
from verify_max08_successor import PopupApp, NativeText, consume, BANK
from verify_bt_cover_install import World
from inspect_bt_pairing import put, data
from verify_media_responsiveness import call
from verify_bt_cover_discovery import uint,seq,protocols
from verify_bt_cover_metadata import reply
from verify_bt_text_metadata_receive import attribute,reply as text_reply
from verify_bt_cover_controller import jpeg
import bt_cover_art_peer_identity as identity
import bt_cover_art_controller as controller
import bt_cover_art_worker as worker

def element(raw,pos=0):
    tag=raw[pos];pos+=1;kind=tag>>3;size=tag&7
    if size<5:width=1<<size
    else:
        n=1<<(size-5);width=int.from_bytes(raw[pos:pos+n],'big');pos+=n
    end=pos+width;assert end<=len(raw)
    if kind in (6,7):
        value=[]
        while pos<end:
            child,pos=element(raw,pos);value.append(child)
    else:
        value=int.from_bytes(raw[pos:end],'big') if kind in (1,3) else raw[pos:end];pos=end
    return (kind,value),end

def observed():
    trace=json.loads((p.ROOT/'analysis/firmware/max09-full-phone-protocols-local.json').read_bytes())
    assert trace['inventory']['source_sha256']=='6c453b495e560f939aa3bb4160ace91e93a1cc40eb51d95c6d9d592e861e7884'
    assert not trace['reassembly_errors'] and not trace['unfinished'] and trace['inventory']['acl_truncated']==0
    by_packet={r['packet']:r for r in trace['sdp']}
    attrs={}
    for reqno,rspno,aid in ((1237,1238,9),(1246,1247,0x311),(1256,1257,13)):
        req,rsp=by_packet[reqno],by_packet[rspno]
        assert req['type']==4 and req['direction']==1 and rsp['type']==5 and rsp['direction']==0
        assert req['transaction']==rsp['transaction']
        query=bytes.fromhex(req['parameters_hex'])
        assert query[:4]==bytes.fromhex('00010006') and query[6:-1]==seq(uint(aid))
        raw=bytes.fromhex(rsp['parameters_hex']);n=int.from_bytes(raw[:2],'big')
        assert len(raw)==n+3 and raw[-1]==0
        root,end=element(raw[2:2+n]);assert end==n and root[0]==6 and root[1][0]==(1,aid)
        attrs[aid]=root[1][1]
    version=attrs[9][1][0][1][1][1]
    features=attrs[0x311][1]
    # Extract the exact returned value after attr ID, preserving both browsing/OBEX lists.
    raw=bytes.fromhex(by_packet[1257]['parameters_hex'])
    cap=raw[7:-1]
    assert cap.hex()=='35213510350619010009001b3506190017090104350d35061901000910013503190008'
    assert version==0x104 and features==0x1d1
    requests=[]
    for row in trace['avrcp']:
        if row.get('pdu')==32 and row['direction']==1:
            b=bytes.fromhex(row['parameters_hex']);assert b[:8]==bytes(8) and len(b)==9+4*b[8]
            requests.append([int.from_bytes(b[i:i+4],'big') for i in range(9,len(b),4)])
    assert len(requests)==13 and all(set(a)==set(range(1,8)) for a in requests)
    assert not any(r.get('psm')==0x1001 and r['code']==2 for r in trace['connections'])
    return dict(version=version,features=features,psm=0x1001,protocol_value=cap,
                source_sha256=trace['inventory']['source_sha256'],metadata_requests=13,attribute8_requests=0,
                cover_channel_open_requests=0,sdp_packets=[1238,1247,1257])

class CapturedBlue(DiscoveryBlue):
    def discover_value(self,version,features,value,policy):
        self.map(CONFIG,bytes(0xb0));self.write(self.peer+0x11c,CONFIG);self.write(CONFIG+0x9a,policy,2)
        self.write(self.peer+0xc8,version,2);self.write(self.peer+0xca,features,2)
        for off in (0x124,0x128,0x12c):self.write(self.peer+off,0)
        body=bytes(10)+uint(13)+value;node=bytearray(struct.pack('<H',len(body))+body)
        struct.pack_into('<H',node,4,13);record=bytearray(0x1a)+node;struct.pack_into('<HH',record,0x12,1,2)
        self.map(RECORD,record,True);self.map(LIST,struct.pack('<IHHI',RECORD,len(record),0,0),True)
        self.enter_queue(12);return call(self,identity.CAPTURE,[LIST,0,self.peer],limit=30000)

def verify():
    evidence=observed();cap=evidence.pop('protocol_value')
    raw=(p.NATIVE/p.SYSTEM/'Blue.exe').read_bytes();before=(p.PREVIOUS/p.SYSTEM/'Blue.exe').read_bytes()
    blue=(p.OUT/'Blue.exe').read_bytes();assert p.blue(before)[0]==blue
    app=(p.OUT/'AppMain.exe').read_bytes();assert app==(p.PREVIOUS/p.SYSTEM/'AppMain.exe').read_bytes()
    app_raw=(p.NATIVE/p.SYSTEM/'AppMain.exe').read_bytes()
    recipe=json.loads((p.ROOT/'build/max08-native-development-02/recipe.json').read_bytes())['AppMain.exe']
    cases=[]
    for revision,candidate,version,features,value,policy,eligible in (
        ('MAX09',before,0x104,0x1d1,cap,0,False),
        ('MAX10',blue,0x104,0x1d1,cap,0,True),
        ('MAX10',blue,0x104,0x1d1,cap,0x80,True),
        ('MAX10',blue,0x106,0x1d1,cap,0,True),
        ('MAX10',blue,0x104,0xd1,cap,0,False),
        ('MAX10',blue,0x103,0x1d1,cap,0,False),
        ('MAX10',blue,0x104,0x1d1,seq(protocols(0x1b,transport=0x17)),0,False)):
        w=World();b=CapturedBlue(pefile.PE(data=raw),candidate,w);a=PopupApp(app_raw,app,w,recipe)
        b.start();assert a.start()==1
        assert bool(b.discover_value(version,features,value,policy))==eligible
        b.select_native()
        while b.messages:b.handle()
        opened=[r for r in b.requests if r['kind']=='open'];assert bool(opened)==eligible
        if eligible:
            assert opened[-1]['remote']==0x1001 and opened[-1]['security']==policy
            b.connect_native();b.response(reply(ctype=12));assert b.phase==controller.GET
            b.body_pointer=b.field(64);b.finish_image(jpeg());assert b.phase==controller.READY
            b.deliver_window();assert a.run_worker()==0 and a.window(worker.MESSAGE)==0
            assert a.screen.getpixel((88,180)) not in ((0,0,0),(8,12,14))
            a.screen.save(p.OUT/f'cover-{version:04x}-{policy:02x}-fixture.png')
        else:assert not b.metadata_requests
        cases.append(dict(revision=revision,version=version,features=features,policy=policy,
                          protocol_value_hex=value.hex(),connection_opened=bool(opened),cover_painted=eligible,
                          steps=b.steps+a.steps))
        a.finish();b.stop();b.deliver_window();assert not w.handles and not w.views and w.shared is None
    titles=[];m=NativeText(raw,blue)
    for uid,title in ((bytes(8),b'Initial track'),(b'12345678',b'Skipped track')):
        m.live(uid);m.queue_ordinary();m.profile();parent=m.serialized[-1]['confirmation']
        row=m.respond(parent,text_reply(body=attribute(1,title)+attribute(2,b'')+attribute(3,b''),count=3,ctype=12))
        assert m.deliver(row)==1 and consume(app,data(m,BANK+0xcf0e8,260))[0]==[title.decode(),'','']
        titles.append(dict(title=title.decode(),native_shared_map_GUI_reader_passed=True))
    assert not m.pending and not m.profile_requests and not m.nodes();m.conclude()
    report=dict(blue_sha256=p.sha(blue),app_sha256=p.sha(app),native_text=titles,artwork=cases,trace_evidence=evidence,
                audio_title_UI_bytes_equal_MAX09=True,hardware_tested=False,
                limits=['SDP values captured from actual phone; cover handle/OBEX image and CE/GDI success are fixtures',
                        'Trace establishes version gate before acquisition; does not establish later interoperability',
                        'MAX10 physical cover arrival remains untested'])
    (p.OUT/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    return dict(artwork_cases=len(cases),native_title_cases=len(titles),captured_SDP_replayed=True)
if __name__=='__main__':print(json.dumps(verify(),indent=2))
