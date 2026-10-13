"""MAX19-21 log analysis, with counter records separated from elapsed timings."""
import argparse,json
from pathlib import Path
import analyze_debug_logs_legacy as old

NAMES={120:'Source wait A',121:'Source wait B',122:'Source wait C',
       130:'Source synchronous IPC send',131:'Source IPC get',132:'Source IPC post',
       320:'Artwork JPEG validation',321:'Artwork factory creation',322:'Artwork image from buffer',
       323:'Artwork image information',324:'Artwork bitmap creation',325:'Artwork image drawing',
       326:'Artwork COM release',327:'Artwork bitmap deletion'}


def analyze(paths):
    old.EVENTS.update(NAMES)
    result=old.analyze(paths);by_session={s['session']:s for s in result['sessions']}
    for s in result['sessions']:
        s['timings']=[e for e in s['timings'] if e['event']!=302]
        s.update(artwork_poll_summaries=[],artwork_memory_snapshots=[],artwork_bitmap_counters=[],
                 artwork_bitmap_create_failures=[],artwork_bitmap_delete_failures=[])
        s['notes']+=['Event 302 stores interval poll count and maximum poll duration, not a timed operation.',
                     'Artwork RAM snapshots are global OS free memory, not per-process ownership.',
                     'Bitmap counters track successful instrumented artwork operations while debugging is enabled; pre-existing handles and disabled intervals are not inventoried.']
    for path in paths:
        lines=path.read_bytes().decode('utf-16-le',errors='replace').lstrip('\ufeff').splitlines()
        session=next((line for line in lines if line.startswith('session\t')),'unknown:'+path.name)
        s=by_session[session]
        for line in lines:
            cols=line.split('\t',6)
            try:
                assert len(cols)==7
                ms,module,event,value,result_code,level=map(int,cols[:6])
            except (ValueError,AssertionError):continue
            if event==302:s['artwork_poll_summaries'].append(dict(ms=ms,poll_count=value,max_duration_ms=result_code))
            elif event in [902,903]:s['artwork_memory_snapshots'].append(dict(ms=ms,phase='before' if event==902 else 'after',free_bytes=value,os_memory_load=result_code))
            elif event==904:s['artwork_bitmap_counters'].append(dict(ms=ms,created=value,deleted=result_code))
            elif event==324 and result_code==0:s['artwork_bitmap_create_failures'].append(dict(ms=ms,duration_ms=value))
            elif event==327 and result_code==0:s['artwork_bitmap_delete_failures'].append(dict(ms=ms,duration_ms=value))
    return result


def main():
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--output',type=Path);a=p.parse_args()
    text=json.dumps(analyze(sorted(a.directory.glob('debug-*.log'))),indent=2,ensure_ascii=False)
    if a.output:a.output.write_text(text+'\n',encoding='utf-8')
    else:print(text)


if __name__=='__main__':main()
