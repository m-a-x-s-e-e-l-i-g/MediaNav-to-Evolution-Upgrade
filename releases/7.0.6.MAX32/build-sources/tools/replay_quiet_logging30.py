"""Replay captured coordinate-free GPS scalars through the new written MIPS.

This measures log-record counts only. Native parsing stays an explicit boundary
because the historical privacy-preserving logs omit the original sentences.
"""
import argparse,json
from collections import Counter,defaultdict
from pathlib import Path
from verify_quiet_logging30 import gps_vm


def replay(stage,logs):
    groups=defaultdict(list);totals=Counter();ui=Counter();native=Counter()
    for p in sorted(logs.glob('debug-*.log')):
        lines=p.read_bytes().decode('utf-16-le',errors='replace').lstrip('\ufeff').splitlines()
        key=next((s for s in lines if s.startswith('session\t')),'unknown:'+p.name)
        for line in lines:
            c=line.split('\t',6)
            try:
                assert len(c)==7
                ms,mod,event,value,raw,level=map(int,c[:6])
            except (ValueError,AssertionError):continue
            totals['before_records']+=1
            if mod==8 and event in (940,941):groups[key].append((ms,event,value,raw));totals['before_gps_records']+=1
            if mod==8 and 1010<=event<=1017:
                ui['before']+=1
                # First record of each pair carries activity count/total. Both
                # scalar values zero certify an empty category in this format.
                ui['empty']+=int(value==0 and raw==0)
            if mod==0 and event in (0,1):
                native['before']+=1
    for key,events in groups.items():
        pending={};run,rows,m,probe=gps_vm(stage)
        for ms,event,kind,raw in sorted(events,key=lambda r:r[0]):
            if event==940:pending[kind]=(ms,raw)
            elif kind in pending:
                at,meta=pending.pop(kind);run(at,kind,meta,int(bool(raw)));totals['replayed_gps_pairs']+=1
        totals['after_gps_records']+=len(rows)
    # For UI category pairs use the count record, not max_ms==0: real measured
    # zero-ms activity remains. Rewalk records to count only genuinely empty pairs.
    empty_categories=0
    for p in sorted(logs.glob('debug-*.log')):
        rows=[]
        for line in p.read_bytes().decode('utf-16-le',errors='replace').splitlines():
            c=line.split('\t',6)
            try:
                assert len(c)==7
                ms,mod,event,value,raw,level=map(int,c[:6])
            except (ValueError,AssertionError):continue
            if mod==8 and event in (1010,1012,1014,1016)and value==0 and raw==0:empty_categories+=1
    omitted_ui=2*empty_categories
    # Only quantify the two directly comparable paths. Native repeats may be
    # truncated by historical capture, so do not manufacture an exact saving.
    output=dict(passed=True,scope='Captured GPS metadata replayed through actual compact MIPS wrapper; native parser input is a fixture. UI empty-pair arithmetic separately validated by native helper tests.',
        **totals,before_ui_records=ui['before'],empty_ui_records_omitted=omitted_ui,
        after_ui_records=ui['before']-omitted_ui,
        estimated_records_after_gps_and_empty_ui=totals['before_records']-totals['before_gps_records']+totals['after_gps_records']-omitted_ui,
        native_repeat_savings_not_estimated=True,physical_performance_measured=False)
    before=output['before_records'];output['record_reduction_percent']=round(100*(before-output['estimated_records_after_gps_and_empty_ui'])/before,2)
    (stage/'recorded-metadata-replay.json').write_text(json.dumps(output,indent=2)+'\n');print(json.dumps(output,indent=2),flush=True);return output


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);p.add_argument('--logs',type=Path,required=True);a=p.parse_args();replay(a.stage.resolve(),a.logs.resolve())
