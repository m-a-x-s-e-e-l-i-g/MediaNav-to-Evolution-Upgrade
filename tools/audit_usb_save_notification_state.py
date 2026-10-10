"""Audit the legacy notification flag removed with a redundant failed save."""
import hashlib
import json
from pathlib import Path
from verify_usb_save_feedback import vm,Files,SOURCE,PATH,OBJ,INPUT,DIALOG,invoke,saved_blob,modes_off,data

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'build/usb-save-feedback-development-01'

def main():
    manifest=json.loads((OUT/'manifest.json').read_bytes())
    raw=(OUT/'payload/upgrade/Storage Card/System/MgrUSB.exe').read_bytes()
    digest=hashlib.sha256(raw).hexdigest()
    assert digest==next(r['sha256'] for r in manifest['members'] if r['path'].endswith('/MgrUSB.exe'))
    traces=[]
    for attached in (0,1):
        for initial_flag in (0,1):
            for valid_file in (False,True):
                initial={PATH:saved_blob(3,1)} if valid_file else {}
                states=[];flags=[]
                for code in (SOURCE.read_bytes(),raw):
                    fs=Files(initial);m,logs=vm(code,fs,attached=attached);m.write(DIALOG+0x1c,initial_flag)
                    invoke(m,0x1e9fc,[OBJ-8]);modes_off(m)
                    states.append(data(m,DIALOG,0x100));flags.append(m.read(DIALOG+0x1c))
                expected_old=initial_flag if attached else 1
                expected_new=1 if not attached and valid_file else initial_flag
                assert flags==[expected_old,expected_new]
                assert all(a==b or 0x1c<=i<0x20 for i,(a,b) in enumerate(zip(*states)))
                traces.append(dict(attached=attached,initial_flag=initial_flag,valid_file=valid_file,
                                   previous_flag=flags[0],new_flag=flags[1]))
    # A later ready event uses the original callback and still announces once.
    m,logs=vm(raw,Files({}),attached=0);m.write(DIALOG+0x1c,0)
    invoke(m,0x1e9fc,[OBJ-8]);assert m.read(DIALOG+0x1c)==0
    m.write(DIALOG+0x38,1);m.write(DIALOG+0x74,0xffffffff);m.write(INPUT,0)
    notifications=[]
    def send(v):
        assert v.reg[4:8]==[5,0x15,0x6f,0] and v.read(v.reg[29]+0x10)==0
        notifications.append(0x6f);return 1
    m.hooks[0x23580]=send
    assert invoke(m,0x21d00,[OBJ-8,0x15,0x7a,4],[INPUT])==1
    assert m.read(DIALOG+0x1c)==1 and notifications==[0x6f]
    assert invoke(m,0x21d00,[OBJ-8,0x15,0x7a,4],[INPUT])==1 and notifications==[0x6f]
    proof=dict(cases=9,output_sha256=digest,traces=traces,
        only_notification_flag_differs_in_dialog=True,native_constructor_initial_flag_is_one=True,
        failed_load_does_not_incidentally_set_notification_flag=True,
        subsequent_existing_ready_handler_notifies_once=True,
        attachment_and_audio_payload_are_fixtures=True,full_native_source_switch_tested=False,
        tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    (ROOT/'analysis/firmware/usb-save-notification-state-audit.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(proof,indent=2))

if __name__=='__main__':main()
