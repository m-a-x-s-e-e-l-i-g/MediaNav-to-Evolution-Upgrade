"""Replay actual phone CONNECT replies through installed MAX10/MAX11 bytes."""
import json
import struct
import sys
import patch_max11_artwork as p
sys.path.insert(0,str(p.REPO/'tools'))
import pefile
from verify_max10_artwork import CapturedBlue
from verify_max08_successor import PopupApp, NativeText, consume, BANK
from verify_bt_cover_install import World
from verify_bt_cover_controller import jpeg
from verify_bt_cover_responses import packet,sequence,fixed
from verify_bt_cover_metadata import reply
from verify_bt_text_metadata_receive import attribute,reply as text_reply
from inspect_bt_pairing import data
import bt_cover_art_controller as controller
import bt_cover_art_worker as worker

def captured():
    trace=json.loads((p.ROOT/'analysis/firmware/max10-full-phone-protocols-local.json').read_bytes())
    inventory=trace['inventory']
    assert inventory['source_sha256']=='6b2044a2b98e0b8312bbde414db1422b84aad4de9049296fbcb76230df280266'
    assert not trace['reassembly_errors'] and not trace['unfinished'] and not inventory['acl_truncated']
    rows=[r for r in trace['dynamic_psm_pdus'] if r['handle'] in (7,8) and r['direction']==0]
    assert len(rows)==12
    replies=[]
    for row in rows:
        frame=bytes.fromhex(row['body_hex']);control=int.from_bytes(frame[:2],'little')
        # Every response is one unsegmented ERTM I-frame. Strip its two-byte
        # control and trailing FCS; the native CSR socket supplies the OBEX SDU.
        assert control==0x100 and len(frame)==35
        obex=frame[2:-2];assert int.from_bytes(obex[1:3],'big')==len(obex)==31
        replies.append(obex)
    assert len(set(replies))==1
    response=replies[0]
    assert response.hex()=='a0001f10000400cb000000014a00137163dd544a7e11e2b47c0050c2490048'
    cap=next(r for r in trace['sdp'] if r['packet']==5973)
    assert cap['direction']==0 and cap['handle']==7 and cap['type']==5
    value=bytes.fromhex(cap['parameters_hex'])[7:-1]
    requests=[r for r in trace['avrcp'] if r['handle'] in (7,8) and r['direction']==1 and r.get('pdu')==32]
    assert len(requests)==19
    for row in requests:
        b=bytes.fromhex(row['parameters_hex'])
        assert set(int.from_bytes(b[i:i+4],'big') for i in range(9,len(b),4))==set(range(1,8))
    return response,value,dict(source_sha256=inventory['source_sha256'],records=inventory['records'],
            acl_packets=inventory['acl_packets'],acl_truncated=0,l2cap_pdus=trace['l2cap_pdus'],
            image_connect_successes=12,image_connect_response_packets=[r['packet'] for r in rows],
            obex_response_hex=response.hex(),obex_version=0x10,connection_id=1,peer_mtu=1024,
            newer_session_metadata_requests=19,attribute8_requests=0)

def edit(raw,index,value):
    out=bytearray(raw);out[index]=value;return bytes(out)

def verify():
    response,value,evidence=captured()
    raw=(p.NATIVE/p.SYSTEM/'Blue.exe').read_bytes();old=(p.PREVIOUS/p.SYSTEM/'Blue.exe').read_bytes()
    blue=(p.OUT/'Blue.exe').read_bytes();assert blue==p.blue(old)[0]
    app=(p.OUT/'AppMain.exe').read_bytes();assert app==(p.PREVIOUS/p.SYSTEM/'AppMain.exe').read_bytes()
    app_raw=(p.NATIVE/p.SYSTEM/'AppMain.exe').read_bytes()
    app_recipe=json.loads((p.ROOT/'build/max08-native-development-02/recipe.json').read_bytes())['AppMain.exe']
    without_cid=packet(0xa0,response[3:7]+response[12:])
    duplicate_cid=packet(0xa0,response[3:]+fixed(0xcb,1))
    cases=[]
    matrix=(('MAX10',old,'captured_1.0',response,False),
            ('MAX11',blue,'captured_1.0',response,True),
            ('MAX11',blue,'existing_1.5',edit(response,3,0x15),True),
            ('MAX11',blue,'invalid_0.15',edit(response,3,0x0f),False),
            ('MAX11',blue,'server_error',edit(response,0,0xc0),False),
            ('MAX11',blue,'invalid_flags',edit(response,4,1),False),
            ('MAX11',blue,'small_mtu',edit(edit(response,5,0),6,254),False),
            ('MAX11',blue,'wrong_WHO',edit(response,15,response[15]^1),False),
            ('MAX11',blue,'missing_CID',without_cid,False),
            ('MAX11',blue,'duplicate_CID',duplicate_cid,False),
            ('MAX11',blue,'length_mismatch',edit(response,2,30),False))
    for revision,candidate,name,wire,eligible in matrix:
        w=World();b=CapturedBlue(pefile.PE(data=raw),candidate,w);a=PopupApp(app_raw,app,w,app_recipe)
        b.start();assert a.start()==1
        assert b.discover_value(0x104,0x1d1,value,0)==1
        b.select_native()
        while b.messages:b.handle()
        assert b.requests[-1]['remote']==0x1005
        b.connected();assert b.phase==controller.CONNECT
        b.receive(wire)
        assert b.phase==(controller.META if eligible else controller.FAILED)
        if eligible:
            assert b.field(40)==1 and b.field(44)==1024 and b.metadata_requests
            b.credit();b.profile();assert len(b.pending)==1
            b.response(reply(ctype=12));assert b.phase==controller.GET
            b.body_pointer=b.field(64);image=jpeg();chunks=[image[i:i+900] for i in range(0,len(image),900)]
            for i,chunk in enumerate(chunks):
                final=i==len(chunks)-1
                b.receive(packet(0xa0 if final else 0x90,(fixed(0xc3,len(image)) if i==0 else b'')
                                 +sequence(0x49 if final else 0x48,chunk)))
                if not final:
                    assert b.phase==controller.GET and b.field(28)==8
                    b.credit();assert b.requests[-1]['bytes_hex']==(b'\x83\0\x08'+fixed(0xcb,1)).hex()
            assert b.phase==controller.READY
            b.deliver_window();assert a.run_worker()==0 and a.window(worker.MESSAGE)==0
            assert a.screen.getpixel((88,180)) not in ((0,0,0),(8,12,14))
            a.screen.save(p.OUT/f'cover-{name}-fixture.png')
        else:assert not b.metadata_requests
        cases.append(dict(revision=revision,case=name,reply_hex=wire.hex(),handshake_accepted=eligible,
                          cover_handle_requested=bool(b.metadata_requests),fixture_cover_painted=eligible,
                          steps=b.steps+a.steps))
        a.finish();b.stop();b.deliver_window();assert not w.handles and not w.views and w.shared is None
    m=NativeText(raw,blue);titles=[]
    for uid,title in ((bytes(8),b'Initial track'),(b'12345678',b'Skipped track')):
        m.live(uid);m.queue_ordinary();m.profile();parent=m.serialized[-1]['confirmation']
        row=m.respond(parent,text_reply(body=attribute(1,title)+attribute(2,b'')+attribute(3,b''),count=3,ctype=12))
        assert m.deliver(row)==1 and consume(app,data(m,BANK+0xcf0e8,260))[0]==[title.decode(),'','']
        titles.append(dict(title=title.decode(),native_shared_map_GUI_reader_passed=True))
    assert not m.pending and not m.profile_requests and not m.nodes();m.conclude()
    report=dict(blue_sha256=p.sha(blue),app_sha256=p.sha(app),artwork=cases,native_text=titles,trace_evidence=evidence,
                audio_title_UI_bytes_equal_MAX10=True,hardware_tested=False,
                limits=['SDP and OBEX CONNECT reply are actual phone bytes; handle/image replies and CE/GDI remain fixtures',
                        'Installed MAX10 refuses captured 1.0 reply; this does not exclude later interoperability failures',
                        'MAX11 actual cover display still requires car test'])
    (p.OUT/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    return dict(artwork_cases=len(cases),native_title_cases=len(titles),captured_CONNECT_replayed=True)

if __name__=='__main__':print(json.dumps(verify(),indent=2))
