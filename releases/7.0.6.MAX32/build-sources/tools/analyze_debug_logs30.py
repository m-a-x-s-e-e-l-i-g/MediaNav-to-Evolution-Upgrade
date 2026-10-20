"""Retain MAX27 interpretation and distinguish filtered repeats from lost logs."""
import argparse,json
from pathlib import Path
from analyze_debug_logs27 import analyze as previous


def analyze(paths):
    paths=list(paths);result=previous(paths);groups={s['session']:s for s in result['sessions']}
    for s in groups.values():
        s['logging_suppression']=[]
        s['notes']+=['MAX30 omits empty navigation UI categories; missing categories are not a recorded zero interval.',
            'MAX30 compact GPS emits fix/acceptance changes and 30-second per-kind heartbeats; GGA count-only and GSV nonzero-count/acceptance changes can wait for that heartbeat.',
            'Event 906 is the saturating cumulative count of deliberately suppressed native repetitions, separate from dropped-record event 901.']
    for path in paths:
        lines=path.read_bytes().decode('utf-16-le',errors='replace').lstrip('\ufeff').splitlines()
        key=next((s for s in lines if s.startswith('session\t')),'unknown:'+path.name)
        for line in lines:
            c=line.split('\t',6)
            try:
                assert len(c)==7
                ms,module,event,value,raw,level=map(int,c[:6])
            except (ValueError,AssertionError):continue
            if module==1 and event==906:groups[key]['logging_suppression'].append(dict(ms=ms,suppressed_native_repeats_total=value))
    for s in groups.values():s['logging_suppression'].sort(key=lambda r:r['ms'])
    return result


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--output',type=Path);a=p.parse_args()
    text=json.dumps(analyze(sorted(a.directory.glob('debug-*.log'))),indent=2,ensure_ascii=False)+'\n'
    if a.output:a.output.write_text(text,encoding='utf-8')
    else:print(text)
