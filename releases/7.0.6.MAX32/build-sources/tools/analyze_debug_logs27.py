"""Distinguish source advertisement, decode, handoff and GUI ownership."""
import argparse,json
from pathlib import Path
import analyze_debug_logs26 as previous


def analyze(paths):
    result=previous.analyze(paths);groups={s['session']:s for s in result['sessions']}
    versions={k:set()for k in groups}
    for s in groups.values():s.update(artwork_delivery=[],local_cover_advertisement=[])
    for p in paths:
        lines=p.read_bytes().decode('utf-16-le',errors='replace').lstrip('\ufeff').splitlines()
        key=next((s for s in lines if s.startswith('session\t')),'unknown:'+p.name)
        versions[key].update(line for line in lines[:2]if line.startswith('MAXmade '))
        for line in lines:
            c=line.split('\t',6)
            try:
                assert len(c)==7
                ms,module,event,value,raw,level=map(int,c[:6])
            except (ValueError,AssertionError):continue
            s=groups[key]
            if module==1 and event in (350,351):
                row=dict(ms=ms,event=event,duration_ms=value)
                if event==350:row.update(stage='worker handoff',pending_submitted=raw==1)
                else:row.update(stage='GUI bitmap change',owns_current_bitmap=bool(raw&1),
                    pending=bool(raw&2),worker_alive=bool(raw&4))
                s['artwork_delivery'].append(row)
            elif module==3 and event==967:
                s['local_cover_advertisement'].append(dict(ms=ms,patch_applied=raw==1,
                    requested_profile_version_hex=f'{value>>16:04x}',controller_feature_added_hex=f'{value&65535:04x}'))
    for key,s in groups.items():
        s['recorded_versions']=sorted(versions[key])
        bad_cache=any('MAX26 'in h for h in versions[key])
        if bad_cache:
            for r in s['navigation_measurements']['latest_observed_gtmc']:
                r['cached_bytes']=None;r['cache_bytes_valid']=False
            s['navigation_measurements']['notes'].append('MAX26 cache bytes are invalid: disabled native cache leaves the sampled field uninitialized. Page accounting remains separate and valid. MAX27 gates this field by cache mode.')
        s['notes']+=['A historical Cover decoded (D9) caption does not certify a current GUI-owned bitmap or iPhone image transfer.',
            'Local controller advertisement event 967 does not force remote phone support or prove interoperability.',
            'Worker handoff and GUI ownership are distinct from successful screen presentation.']
        s['artwork_delivery'].sort(key=lambda r:r['ms'])
    return result


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--output',type=Path)
    a=p.parse_args();text=json.dumps(analyze(sorted(a.directory.glob('debug-*.log'))),indent=2,ensure_ascii=False)
    if a.output:a.output.write_text(text+'\n',encoding='utf-8')
    else:print(text)
