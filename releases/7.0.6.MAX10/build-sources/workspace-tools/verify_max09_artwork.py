"""Execute installed discovery capture, native selection and image/UI pipeline.

SDP records and Bluetooth responses come from bounded fixtures, not a phone.
MAX08 must refuse the zero-policy selection; MAX09 must transfer and paint.
"""
import json
import struct
from functools import lru_cache
import sys
import patch_max09_artwork as patcher
sys.path.insert(0,str(patcher.REPO/'tools'))
import pefile
import layout_bt_cover_native as layout
layout.plan = lru_cache(maxsize=4)(layout.plan)
from verify_bt_text_recovery_install import ArtworkBlue
from verify_bt_cover_install import World
from verify_max08_successor import PopupApp, NativeText, consume, BANK
from verify_bt_text_metadata_receive import attribute, reply as text_reply
from verify_bt_cover_discovery import protocols, uint, seq
from verify_bt_cover_metadata import reply
from verify_bt_cover_controller import jpeg
from verify_bt_cover_responses import handshake
from verify_media_responsiveness import call
from inspect_bt_pairing import data, put
import bt_cover_art_peer_identity as identity
import bt_cover_art_controller as controller
import bt_cover_art_worker as worker

CONFIG = 0x4a001000
LIST, RECORD = 0x4a002000, 0x4a003000

class DiscoveryBlue(ArtworkBlue):
    def map(self,at,raw,readonly=False):
        self.allowed.append((at,at+len(raw)))
        put(self,at,raw)

    def discover(self,policy=0,version=0x106,features=0x100):
        self.map(CONFIG,bytes(0xb0))
        self.write(self.peer+0x11c,CONFIG)
        self.write(CONFIG+0x9a,policy,2)
        self.write(self.peer+0xc8,version,2)
        self.write(self.peer+0xca,features,2)
        self.write(self.peer+0x12c,0)
        self.write(self.peer+0x124,0)
        self.write(self.peer+0x128,0)
        body=bytes(10)+uint(13)+seq(protocols(0x1003))
        node=bytearray(struct.pack('<H',len(body))+body)
        struct.pack_into('<H',node,4,13)
        record=bytearray(0x1a)+node
        struct.pack_into('<HH',record,0x12,1,2)
        self.map(RECORD,record,True)
        self.map(LIST,struct.pack('<IHHI',RECORD,len(record),0,0),True)
        self.enter_queue(12)
        result=call(self,identity.CAPTURE,[LIST,0,self.peer],limit=30000)
        if result:
            assert self.read(self.peer+0x124,2)==0x1003
            assert self.read(self.peer+0x126,2)==policy
        return result

def verify():
    raw=(patcher.NATIVE/patcher.SYSTEM/'Blue.exe').read_bytes()
    previous=(patcher.PREVIOUS/patcher.SYSTEM/'Blue.exe').read_bytes()
    blue=(patcher.OUT/'Blue.exe').read_bytes()
    assert blue==patcher.blue(previous)[0]
    app=(patcher.OUT/'AppMain.exe').read_bytes()
    assert app==(patcher.PREVIOUS/patcher.SYSTEM/'AppMain.exe').read_bytes()
    app_raw=(patcher.NATIVE/patcher.SYSTEM/'AppMain.exe').read_bytes()
    app_recipe=json.loads((patcher.ROOT/'build/max08-native-development-02/recipe.json').read_bytes())['AppMain.exe']
    cases=[]
    for revision,candidate,policy,version,features in (
        ('MAX08',previous,0,0x106,0x100),
        ('MAX09',blue,0,0x106,0x100),
        ('MAX09',blue,0x80,0x106,0x100),
        ('MAX09',blue,0,0x105,0x100),
        ('MAX09',blue,0,0x106,0)):
        w=World(); b=DiscoveryBlue(pefile.PE(data=raw),candidate,w)
        a=PopupApp(app_raw,app,w,app_recipe)
        b.start(); assert a.start()==1
        assert b.discover(policy,version,features)==int(version>=0x106 and bool(features&0x100))
        b.select_native()
        while b.messages: b.handle()
        opened=[r for r in b.requests if r['kind']=='open']
        eligible=(revision=='MAX09' and version>=0x106 and bool(features&0x100))
        assert bool(opened)==eligible
        if eligible:
            assert opened[-1]['security']==policy and opened[-1]['remote']==0x1003
            b.connect_native();b.response(reply())
            assert b.phase==controller.GET, dict(phase=b.phase,fields=[b.field(i) for i in range(0,80,4)],requests=b.metadata_requests)
            b.body_pointer=b.field(64);b.finish_image(jpeg())
            assert b.phase==controller.READY
            b.deliver_window(); assert a.run_worker()==0
            assert a.window(worker.MESSAGE)==0
            assert a.screen.getpixel((88,180)) not in ((0,0,0),(8,12,14))
            a.screen.save(patcher.OUT/f'cover-policy-{policy:02x}-fixture.png')
        else:
            assert not b.metadata_requests
        cases.append(dict(revision=revision,policy=policy,version=version,features=features,
                          connection_opened=bool(opened),cover_painted=eligible,
                          steps=b.steps+a.steps,native_reads=b.installed_reads+a.installed_reads))
        a.finish();b.stop();b.deliver_window()
        assert not w.handles and not w.views and w.shared is None
    # Execute the retained native title producer/response/shared-map/GUI reader.
    titles=[]
    m=NativeText(raw,blue)
    for uid,title in ((bytes(8),b'Initial track'),(b'12345678',b'Skipped track')):
        m.live(uid);m.queue_ordinary();m.profile()
        parent=m.serialized[-1]['confirmation']
        row=m.respond(parent,text_reply(body=attribute(1,title)+attribute(2,b'')+attribute(3,b''),count=3))
        assert m.deliver(row)==1
        assert consume(app,data(m,BANK+0xcf0e8,260))[0]==[title.decode(),'','']
        titles.append(dict(title=title.decode(),native_shared_map_GUI_reader_passed=True))
    assert not m.pending and not m.profile_requests and not m.nodes()
    m.conclude()
    report=dict(blue_sha256=patcher.sha(blue),app_sha256=patcher.sha(app),native_text=titles,
                artwork=cases,audio_title_UI_bytes_equal_MAX08=True,hardware_tested=False,
                limits=['SDP capability values and Bluetooth/OBEX responses are fixtures',
                        'No Nothing phone trace or physical artwork success yet',
                        'Phone must advertise AVRCP 1.6 cover-art support and a valid BIP PSM'])
    (patcher.OUT/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    return dict(artwork_cases=len(cases),baseline_zero_policy_refusal_reproduced=True)

if __name__=='__main__': print(json.dumps(verify(),indent=2))
