"""Read-only completion audit of the delivered MAX07 and its scoped evidence.

Confirm current artifacts, inventories, source/evidence hashes and actual PE
instructions. Do not treat fixture cases as physical defect resolution. No
firmware is executed or repackaged; only an audit report is written.
"""
from collections import Counter
from datetime import datetime,timezone
import hashlib
import json
from pathlib import Path
import struct
import zipfile
import pefile
import audit_selected_label_paths as labels

ROOT=Path(__file__).resolve().parents[1]
REPO=ROOT/'sources/MediaNav-usb-seek-timing'
DELIVERED=ROOT/'build/maxmade-7.0.6.MAX07'
BUILD=REPO/'build/maxmade-7.0.6.MAX07-local-01'
PREVIOUS=REPO/'build/maxmade-7.0.6.MAX06-artwork-text-local-01'
APP='upgrade/Storage Card/System/AppMain.exe'
BLUE='upgrade/Storage Card/System/Blue.exe'
VERSION='upgrade/Storage Card/System/Version_Info.txt'


def sha(raw):return hashlib.sha256(raw).hexdigest()
def read(path):return json.loads(path.read_bytes())
def pinned(path,row):
    raw=path.read_bytes()
    assert (len(raw),sha(raw))==(row['bytes'],row['sha256']),str(path)
    return raw


def audit():
    manifest=read(DELIVERED/'build-manifest.json')
    assert manifest==read(BUILD/'build-manifest.json')
    assert manifest['revision']=='7.0.6.MAX07' and manifest['baseline_revision']=='7.0.6.MAX06'
    lgu=pinned(DELIVERED/'upgrade.lgu',dict(bytes=manifest['verification']['bytes'],sha256=manifest['verification']['lgu_sha256']))
    assert (BUILD/'upgrade.lgu').read_bytes()==lgu
    assert lgu[:4]==b'LGU0'
    assert lgu[0x2dc:0x304].decode('utf-16-le').split('\0')[0]=='7.0.6.MAX07'
    assert sha((PREVIOUS/'upgrade.lgu').read_bytes())==manifest['baseline_lgu_sha256']
    for name,pin in dict(manifest['source_pins'],**manifest['evidence_sha256']).items():
        assert sha((ROOT/name).read_bytes())==pin,name
    archive=ROOT/'build/maxmade-7.0.6.MAX07.zip'
    with zipfile.ZipFile(archive) as z:
        assert z.testzip() is None
        assert z.read('7.0.6.MAX07/upgrade.lgu')==lgu
        for name in ('build-manifest.json','member-plan.json','native-recipes.json',
                     'labels-verification.json','bluetooth-verification.json','artwork-verification.json'):
            assert z.read('7.0.6.MAX07/'+name)==(DELIVERED/name).read_bytes(),name

    plan=read(DELIVERED/'member-plan.json')
    previous={r['path']:r['after'] for r in read(PREVIOUS/'member-plan.json')['members']}
    after={r['path']:r['after'] for r in plan['members']}
    assert len(previous)==len(after)==len(plan['members'])==1918 and set(previous)==set(after)
    inventory=lambda folder:{p.relative_to(folder).as_posix() for p in folder.rglob('*') if p.is_file()}
    for directory in (PREVIOUS/'payload',BUILD/'payload',BUILD/'roundtrip'):
        assert inventory(directory)==set(after),str(directory)
    changed=[];unchanged=0
    for row in plan['members']:
        assert row['before']==previous[row['path']]
        old=pinned(PREVIOUS/'payload'/row['path'],row['before'])
        new=pinned(BUILD/'payload'/row['path'],row['after'])
        assert pinned(BUILD/'roundtrip'/row['path'],row['after'])==new
        if new==old:unchanged+=1
        else:changed.append(row['path'])
    assert sorted(changed)==sorted((APP,BLUE,VERSION)) and unchanged==1915
    assert (BUILD/'payload'/VERSION).read_bytes()==b'7.0.6.MAX07'
    assert {r['path']:dict(bytes=r['bytes'],sha256=r['sha256']) for r in manifest['verification']['members']}==after

    app=(BUILD/'roundtrip'/APP).read_bytes();blue=(BUILD/'roundtrip'/BLUE).read_bytes()
    ap,bp=pefile.PE(data=app),pefile.PE(data=blue)
    for p in (ap,bp):
        assert p.OPTIONAL_HEADER.CheckSum==p.generate_checksum()
        assert p.FILE_HEADER.Machine==0x166 and p.get_overlay_data_start_offset() is None
        assert all(not(s.Characteristics&0x20000000 and s.Characteristics&0x80000000) for s in p.sections)
    recipes=read(DELIVERED/'native-recipes.json')
    assert recipes['AppMain']['input_sha256']==previous[APP]['sha256']
    assert recipes['AppMain']['sha256']==sha(app)
    assert recipes['Blue']['input_sha256']==previous[BLUE]['sha256'] and recipes['Blue']['sha256']==sha(blue)
    # Every recorded native Blue edit is present in the actually extracted PE.
    for edit in recipes['Blue']['edits']:
        encoded=bytes.fromhex(edit['after_hex'])
        assert bp.get_data(int(edit['address'],16)-0x10000,len(encoded))==encoded
    original=(PREVIOUS/'payload'/APP).read_bytes();rollback=bytearray(app[:len(original)])
    for edit in reversed(recipes['AppMain']['edits']):
        old=bytes.fromhex(edit['before_hex']);at=edit['offset'];rollback[at:at+len(old)]=old
    assert bytes(rollback)==original

    lp=read(DELIVERED/'labels-verification.json');tp=read(DELIVERED/'bluetooth-verification.json');ip=read(DELIVERED/'artwork-verification.json')
    assert lp['candidate_sha256']==ip['app_sha256']==sha(app)
    assert tp['candidate_sha256']==ip['blue_sha256']==sha(blue)
    assert tp['receiver']['executed_candidate_sha256']==sha(blue)
    assert not any(p['hardware_tested'] for p in (manifest,lp,tp,ip))
    assert tp['cases']==len(tp['poll_and_retry_traces'])+tp['receiver']['cases']+tp['shutdown']['cases']+len(tp['transport'])+tp['audio']['cases']==120
    assert ip['cases']==len(ip['traces'])==8
    assert sum(lp[k] for k in ('resource_profile_state_painter_cases','semantic_layout_boundary_cases',
                             'leaf_register_cases','relocated_painter_cases'))==20722
    # Refresh the catalog/vtable scope against MAX07's PE. Catalog resources
    # come from the original theme and must match actual retained MAX07 assets.
    scope=labels.audit(app)
    checked=0;families=Counter()
    for row in scope['catalog']:
        families[row['family']]+=1
        if row['present']:
            name='upgrade/Storage Card/System/Img/M1/'+row['filename'].replace('\\','/')
            actual=next(n for n in after if n.casefold()==name.casefold())
            assert after[actual]['sha256']==row['sha256'],actual
            checked+=1
    assert len(scope['catalog'])==461
    assert sum(r['dark_active_label_correction'] for r in scope['catalog'])==196
    assert {r['painter'] for r in scope['text_painter_vtables']}=={'0x13ecec','0x13f258','0x13f378'}
    # Freshness-independent literal evidence of the actual visible frame/text.
    art=recipes['AppMain']['artwork']
    assert art['rectangle']==ip['rectangle']==[24,116,128,128]
    assert ap.get_data(art['text_va']-0x10000,20)=='Album art\0'.encode('utf-16-le')
    for site in art['sites']:
        assert struct.unpack('<I',ap.get_data(site-0x10000,4))[0]==((3<<26)|(art['address']>>2))

    def requirement(name,evidence,missing):
        return dict(requirement=name,status='unverified_on_device',offline_evidence=evidence,
                    required_to_complete=missing)
    rows=[
        dict(requirement='Use latest MAX06 rather than old MAX04 executable',status='verified',
             evidence=dict(baseline_lgu_sha256=manifest['baseline_lgu_sha256'],AppMain_input_sha256=previous[APP]['sha256'],Blue_input_sha256=previous[BLUE]['sha256'])),
        requirement('Bluetooth titles display and update after track skips',
                    'Current extracted PE matches 120-case suite; polling, receiver, retry and shutdown paths checked with supplied wire/CE/source fixtures',
                    'MAX07 installation and actual Nothing Phone/Spotify titles after skips/reconnect'),
        requirement('Selected text remains visible throughout the system, including BT Options and Radio Options/Presets',
                    dict(shared_AppMain_painters=scope['scope'],catalog_ids=461,themed_buttons=196,behavior_cases=20722,retained_catalog_assets_checked=checked,families=dict(families)),
                    'Check affected screens on MAX07; broad physical-system GUI coverage is not established by shared painter fixtures'),
        requirement('Resolve Bluetooth-only stuttering regression versus 7.0.5MD',
                    '17 actual PCM instruction/payload/ownership cases; 22-slot bounded queue, initial2 and adaptive2/4/6/8 reserve',
                    'Audible MAX07 playback/reconnect/source-switch comparison; real decoder/scheduling cause remains unmeasured'),
        requirement('Artwork appears in the Bluetooth Player and its position is clear',
                    'Actual 128px placeholder and retained fresh-cover overlay;8 installed-path fixture cases; native zero-policy open verified',
                    'Physical placeholder rendering and actual phone cover delivery; a fixture cover is not proof that this phone supplies artwork'),
        dict(requirement='Deliver a complete MAX07 LGU with all prior files and improvements retained',status='verified_for_artifact_and_guarded_inheritance',
             evidence=dict(path=str(DELIVERED/'upgrade.lgu'),sha256=sha(lgu),members=1918,unchanged_from_MAX06=1915,changed_members=changed,
                           readback_files_rehashed=1918,AppMain_exact_rollback=True,Blue_guarded_edits_present=True,zip_integrity=True))]
    return dict(generated_utc=datetime.now(timezone.utc).isoformat(),objective_scope_unchanged=True,
                full_goal_complete=False,requirements=rows,
                blocker='No MAX07 physical test results or live unit/phone runtime evidence have been supplied',
                next_action='Await the requested MAX07 device results; do not replace this candidate speculatively',
                previous_goal_turn_classification='progress: delivered complete cumulative LGU and evidence',
                candidate_lgu_sha256=sha(lgu),no_firmware_changes=True,no_native_execution=True,
                evidence_scopes_confirmed_from_current_verifier_sources=True,
                source_sha256=sha(Path(__file__).read_bytes()))


if __name__=='__main__':
    result=audit();path=ROOT/'analysis/firmware/max07-completion-audit.json'
    path.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(full_goal_complete=result['full_goal_complete'],lgu_sha256=result['candidate_lgu_sha256'],
                          requirements=[dict(requirement=r['requirement'],status=r['status']) for r in result['requirements']],
                          blocker=result['blocker']),indent=2))
