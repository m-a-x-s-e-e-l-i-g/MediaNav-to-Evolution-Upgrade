"""Decode scalar artwork checkpoints separately from elapsed-time metrics."""
import argparse,json
from pathlib import Path
import analyze_debug_logs24 as previous

NAMES={950:'discovery',951:'SDP record extraction',952:'cover endpoint parsing',
       953:'selected peer resolution',954:'owner/controller state',955:'cover channel open',
       956:'cover channel opened',957:'OBEX CONNECT parsing',958:'cover handle request',
       959:'cover handle parsing',960:'image request encoding',961:'image response parsing',
       962:'controller response',963:'controller cancellation',964:'controller deadline check',
       965:'cover task initialization',966:'legacy track request',979:'artwork snapshot availability'}
PHASES={0:'off',1:'opening',2:'OBEX connect',3:'cover handle',4:'image transfer',5:'ready',6:'failed'}
REASONS={0:'accepted',1:'no peer',2:'no peer lifetime',3:'profile version below 1.4',
         4:'cover feature absent',5:'browsing context absent',6:'cover task queue unregistered',
         7:'SDP/endpoint extraction or optional message allocation failed'}


def analyze(paths):
    result=previous.analyze(paths);groups={s['session']:s for s in result['sessions']}
    for s in groups.values():
        s['artwork_acquisition']=[]
        s['notes']+=['Artwork checkpoints are latest scalar observations, not durations.',
            'Periodic snapshots repeat prior observations; their outer time is the snapshot time.',
            'Availability bits mean observed since process start while debugging; absent is unknown.',
            'Different slots are not an atomic cross-operation or per-peer snapshot.',
            'A parsed image completion does not prove current-track GUI display.']
    for p in paths:
        lines=p.read_bytes().decode('utf-16-le',errors='replace').lstrip('\ufeff').splitlines()
        key=next((s for s in lines if s.startswith('session\t')),'unknown:'+p.name)
        for line in lines:
            c=line.split('\t',6)
            try:
                assert len(c)==7
                ms,module,event,value,raw,level=map(int,c[:6])
            except (AssertionError,ValueError):continue
            original_event=event
            repeated=980<=event<=996
            if repeated:event-=30
            if module!=3 or event not in NAMES:continue
            row=dict(ms=ms,event=original_event,checkpoint=event,name=NAMES[event],value=value,
                     raw_result=raw,repeated_snapshot=repeated)
            if event==950:row.update(version_hex=f'{value>>16:04x}',features_hex=f'{value&65535:04x}',reason=REASONS.get(raw,'unknown'))
            elif event==954:row.update(owner_phase=value&255,registration=(value>>8)&255,controller_phase=PHASES.get((value>>16)&255,'unknown'))
            elif event==957:row.update(response_code=value&255,obex_version=(value>>8)&255,response_bytes_mod65536=value>>16,accepted=raw==1)
            elif event==959:row['handle_result']={0:'no cover',1:'valid cover handle',0xffffffff:'invalid'}.get(raw,'unknown')
            elif event==961:row['image_result']={1:'continue',2:'complete',0xffffffff:'invalid'}.get(raw,'unknown')
            elif event==962:row.update(phase_before=PHASES.get(value>>16,'unknown'),phase_after=PHASES.get(value&65535,'unknown'))
            elif event in (956,963,964):row['phase_before']=PHASES.get(value,'unknown')
            elif event==979:row['available_events']=[950+n for n in range(17) if value&(1<<n)]
            groups[key]['artwork_acquisition'].append(row)
    for s in groups.values():s['artwork_acquisition'].sort(key=lambda r:r['ms'])
    return result


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--output',type=Path)
    a=p.parse_args();text=json.dumps(analyze(sorted(a.directory.glob('debug-*.log'))),indent=2,ensure_ascii=False)
    if a.output:a.output.write_text(text+'\n',encoding='utf-8')
    else:print(text)
