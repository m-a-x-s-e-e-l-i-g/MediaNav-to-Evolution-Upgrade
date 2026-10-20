"""Summarize MAX19 USB logs without interpreting raw function returns as success."""
import argparse,json,statistics
from collections import Counter,defaultdict
from pathlib import Path

EVENTS={99:'AppMain lifetime',100:'Media manager startup',101:'Source switch request',
    102:'Overlay source restoration',103:'Navigation launch',104:'Slow screen paint',
    110:'Settings construction',111:'Settings initialization',112:'Settings page change',
    200:'USB scan',201:'USB sort',202:'USB file rendering',203:'Next USB folder',
    300:'Bluetooth audio start request',301:'Artwork publication',310:'Artwork decoding',
    900:'OS memory sample',901:'Dropped-record count'}


def analyze(paths):
    sessions=defaultdict(lambda:dict(files=[],events=[],invalid_lines=0))
    for path in paths:
        raw=path.read_bytes()
        text=raw.decode('utf-16-le',errors='replace').lstrip('\ufeff')
        lines=text.splitlines();session='unknown:'+path.name
        for line in lines:
            if line.startswith('session\t'):session=line;break
        group=sessions[session];group['files'].append(path.name)
        for line in lines:
            if not line or line.startswith(('MAXmade ','ms\t','session\t')):continue
            cols=line.split('\t',6)
            try:
                assert len(cols)==7
                nums=[int(c) for c in cols[:6]]
                assert all(0<=c<=0xffffffff for c in nums)
            except (ValueError,AssertionError):group['invalid_lines']+=1;continue
            group['events'].append(dict(ms=nums[0],module=nums[1],event=nums[2],duration_ms=nums[3],raw_result=nums[4],level=nums[5],message=cols[6]))
    output=[]
    for session,group in sessions.items():
        spans=defaultdict(list);begin=Counter();end=Counter();messages=[];ram=[];drops=[]
        for e in group['events']:
            event=e['event']
            if event&0x80000000:begin[event&0x7fffffff]+=1
            elif 1<event<900:
                spans[event].append(e['duration_ms']);end[event]+=1
            elif event==900:ram.append(dict(ms=e['ms'],free_bytes=e['duration_ms'],os_memory_load=e['raw_result']))
            elif event==901:drops.append(e['raw_result'])
            elif e['message']:messages.append(e)
        durations=[]
        for event,values in spans.items():
            ordered=sorted(values)
            durations.append(dict(event=event,name=EVENTS.get(event,str(event)),count=len(values),
                median_ms=statistics.median(values),p95_ms=ordered[max(0,(len(ordered)*95+99)//100-1)],max_ms=max(values)))
        output.append(dict(session=session,files=group['files'],records=len(group['events']),
            invalid_or_partial_lines=group['invalid_lines'],timings=sorted(durations,key=lambda e:e['max_ms'],reverse=True),
            begins_without_matching_end_count={EVENTS.get(e,str(e)):max(0,n-end[e]) for e,n in begin.items() if n>end[e]},
            memory_samples=ram,dropped_records_latest=max(drops) if drops else None,
            native_messages=messages,notes=['Durations include a small instrumentation cost and use the device millisecond clock.',
                'A begin without an end can also result from rotation, dropped records or abrupt power loss.',
                'Raw function results and IPC delivery do not prove completed hardware transitions.',
                'Device calendar time may be unset; the session also contains a boot-relative start tick.']))
    return dict(sessions=output)


def main():
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--output',type=Path);a=p.parse_args()
    result=analyze(sorted(a.directory.glob('debug-*.log')))
    text=json.dumps(result,indent=2,ensure_ascii=False)
    if a.output:a.output.write_text(text+'\n',encoding='utf-8')
    else:print(text)

if __name__=='__main__':main()
