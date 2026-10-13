"""Retain MAX20 runtime exactly; identify the successor in each log header."""
from debug_runtime20 import build_core as previous


def build_core(i):
    runtime=previous(i)
    at=runtime['strings']['header']-i.text
    old='\ufeffMAXmade 7.0.6.MAX20 diagnostics';new=old.replace('MAX20','MAX21')
    a=old.encode('utf-16-le');b=new.encode('utf-16-le')
    assert i.body[at:at+len(a)]==a and len(a)==len(b)
    i.body[at:at+len(b)]=b
    runtime['measurements_revision']=21
    runtime['poll_summary_interval_ms']=10000
    return runtime
