"""Separate service actions and coordinate-free GPS markers from elapsed times."""
import argparse,json
from pathlib import Path
import analyze_debug_logs22 as previous

NAMES={400:'Service tool entry',401:'Service power-state request',402:'DSI CAN configuration request',
       403:'RVC configuration write',404:'GPS fitted configuration write',
       405:'Service tool window creation',406:'Micom test window creation'}
previous.previous.NAMES.update(NAMES)


def ascii_bytes(value,count):
    return bytes((value>>(8*j))&255 for j in range(count-1,-1,-1)).decode('ascii',errors='replace')


def analyze(paths):
    result=previous.analyze(paths);groups={s['session']:s for s in result['sessions']}
    pending={key:{} for key in groups};latest={key:{} for key in groups}
    for s in groups.values():
        s.update(service_actions=[],gps_observations=[])
        s['notes']+=['GPS observations contain raw sentence markers, not independently validated checksums or coordinates.',
                     'Native parser acceptance is separate from a valid navigation position fix.',
                     'Repeated unchanged GPS markers are sampled per bucket every five seconds; changes emit sooner.',
                     'Service entry 3746 and 3748 follow different native paths; power-state timing is retained.',
                     'A configuration-write acknowledgement does not alone prove retention after restart.']
    records={key:[] for key in groups}
    for path in paths:
        lines=path.read_bytes().decode('utf-16-le',errors='replace').lstrip('\ufeff').splitlines()
        key=next((s for s in lines if s.startswith('session\t')),'unknown:'+path.name)
        for line in lines:
            c=line.split('\t',6)
            try:
                assert len(c)==7
                ms,module,event,value,raw,level=map(int,c[:6])
            except (ValueError,AssertionError):continue
            records[key].append((ms,module,event,value,raw))
    for key,events in records.items():
        s=groups[key]
        for ms,module,event,value,raw in sorted(events,key=lambda x:x[0]):
            base=event&0x7fffffff
            if module==4 and base in NAMES:
                stack=pending[key].setdefault(base,[])
                if event&0x80000000:
                    row=dict(event=base,name=NAMES[base],start_ms=ms,end_ms=None,raw_begin_value=value)
                    if base==401:row['requested_power_state']=value
                    if base in (403,404):
                        row.update(requested_configuration_bits=value,test_write_blocked=bool(raw))
                        row['requested_enabled']=bool(value&(0x400 if base==403 else 0x800))
                    s['service_actions'].append(row);stack.append(row)
                else:
                    row=stack.pop()if stack else dict(event=base,name=NAMES[base],start_ms=None)
                    if row.get('start_ms')is None:s['service_actions'].append(row)
                    row.update(end_ms=ms,duration_ms=value,raw_result=raw)
                    if base in (403,404):row['write_acknowledged']=bool(raw)
            elif module==8 and event==940:
                kind=ascii_bytes(value,3);talker=ascii_bytes(raw>>16,2)
                marker=(raw>>8)&255;sats=raw&255
                row=dict(ms=ms,sentence=kind,talker=talker,raw_status=None if marker==255 else chr(marker),
                         native_parser_accepted=None)
                if kind=='GGA':row['satellites_used_reported']=None if sats==255 else sats
                elif kind=='GSV':row['satellites_visible_reported']=None if sats==255 else sats
                s['gps_observations'].append(row);latest[key][value]=row
            elif module==8 and event==941:
                row=latest[key].get(value)
                if row:row['native_parser_accepted']=bool(raw)
    return result


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--output',type=Path)
    a=p.parse_args();text=json.dumps(analyze(sorted(a.directory.glob('debug-*.log'))),indent=2,ensure_ascii=False)
    if a.output:a.output.write_text(text+'\n',encoding='utf-8')
    else:print(text)
