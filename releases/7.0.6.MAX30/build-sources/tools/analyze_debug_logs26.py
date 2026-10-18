"""Navigation metrics with scalar RAM/accounting kept separate from timings."""
import argparse,json,statistics
from pathlib import Path
import analyze_debug_logs25 as previous
ACTIONS={1000:(0x417df4,'route recalculation request handler'),
         1001:(0x417ecc,'abort calculation request handler'),
         1002:(0x418b70,'refresh navigated route parameters handler')}
CATEGORIES=['paint window handler','other window handler',
            'message preprocessing','repaint request / synchronous UpdateWindow']


def analyze(paths):
    result=previous.analyze(paths);groups={s['session']:s for s in result['sessions']}
    events={k:[] for k in groups}
    for p in paths:
        lines=p.read_bytes().decode('utf-16-le',errors='replace').lstrip('\ufeff').splitlines()
        key=next((s for s in lines if s.startswith('session\t')),'unknown:'+p.name)
        for line in lines:
            c=line.split('\t',6)
            try:
                assert len(c)==7
                ms,module,event,value,raw,level=map(int,c[:6])
                assert all(0<=v<=0xffffffff for v in (ms,module,event,value,raw,level))
            except (ValueError,AssertionError):continue
            if module==8 and (event&0x7fffffff)>=1000:events[key].append((ms,event,value,raw))
    for key,s in groups.items():
        s['begins_without_matching_end_count']={k:v for k,v in s['begins_without_matching_end_count'].items() if k not in map(str,ACTIONS)}
        nav=dict(actions=[],action_timings=[],ui_intervals=[],global_ram=[],action_ram=[],
                 latest_observed_gtmc=[],gtmc_availability=[],snapshot_context=[])
        counts={e:[0,0,[]] for e in ACTIONS}
        for ms,event,value,raw in sorted(events[key],key=lambda r:r[0]):
            base=event&0x7fffffff
            if base in ACTIONS:
                begin=bool(event&0x80000000);counts[base][0 if begin else 1]+=1
                if not begin:counts[base][2].append(value)
                nav['actions'].append(dict(ms=ms,event=base,name=ACTIONS[base][1],phase='begin' if begin else 'end',
                                           duration_ms=None if begin else value))
            elif 1010<=event<=1017:
                category=(event-1010)//2
                row=dict(ms=ms,category=CATEGORIES[category])
                if event%2==0:row.update(count=value,total_handler_ms=raw,mean_handler_ms=raw/value if value else None)
                else:row.update(max_handler_ms=value,calls_at_least_50ms=raw)
                nav['ui_intervals'].append(row)
            elif event==1020:nav['global_ram'].append(dict(ms=ms,available_physical_bytes=value,total_physical_bytes=raw))
            elif event==1021:nav['global_ram'].append(dict(ms=ms,os_memory_load_percent=value))
            elif event==1022:nav['latest_observed_gtmc'].append(dict(ms=ms,pages_in_use=value,page_bytes=4096,
                accounted_bytes=value*4096,cached_bytes=raw,repeated_latest_observation=True))
            elif event==1023:nav['gtmc_availability'].append(dict(ms=ms,available=bool(raw),observed_peak_pages=value if raw else None))
            elif event in (1040,1041):nav['action_ram'].append(dict(ms=ms,event=value,name=ACTIONS.get(value,(0,'unknown'))[1],
                phase='before' if event==1040 else 'after',available_physical_bytes=raw))
            elif event==1024:nav['snapshot_context'].append(dict(ms=ms,action=value or None,phase_event=raw))
        for e,(begins,ends,values) in counts.items():
            if not begins and not ends:continue
            ordered=sorted(values)
            nav['action_timings'].append(dict(event=e,name=ACTIONS[e][1],begins=begins,ends=ends,
                unmatched_begin_count=max(0,begins-ends),median_ms=statistics.median(values) if values else None,
                p95_ms=ordered[max(0,(len(ordered)*95+99)//100-1)] if values else None,
                max_ms=max(values) if values else None))
        nav['notes']=['Action durations measure synchronous request handlers, not completed asynchronous route calculations.',
            'Navigation display exit, abort calculation and route deletion are different actions.',
            'Global physical RAM belongs to the whole system, not NNG alone.',
            'GTMC values repeat the latest synchronous allocator observation; unavailable means unknown, not zero.',
            'GTMC pages and cache bytes are native accounting, not process working set or all engine allocations.',
            'Peak is an observed lower bound; disabled intervals and nonblocking contention can omit observations.',
            'UI interval totals include nested synchronous work; categories must not be added as CPU time.',
            'UI handlers are not frame rate or end-to-end touch latency. Mean is computed only for nonzero count.',
            'Sampling occurs at existing reactor returns, at most every five seconds, and can be delayed.',
            'Records use boot-relative milliseconds within each session; calendar time is not ordering evidence.',
            'Individual records are coherent; adjacent records are not an atomic cross-thread snapshot.',
            'Unmatched begins may reflect power loss, rotation or dropped logs and do not prove a crash.']
        s['navigation_measurements']=nav
    return result


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--output',type=Path)
    a=p.parse_args();text=json.dumps(analyze(sorted(a.directory.glob('debug-*.log'))),indent=2,ensure_ascii=False)
    if a.output:a.output.write_text(text+'\n',encoding='utf-8')
    else:print(text)
