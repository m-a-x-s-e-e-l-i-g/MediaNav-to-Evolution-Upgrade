from debug_runtime25 import build_core as prior


def build_core(i):
    runtime=prior(i);at=runtime['strings']['header']-i.text
    old='\ufeffMAXmade 7.0.6.MAX25 diagnostics'.encode('utf-16-le')
    new='\ufeffMAXmade 7.0.6.MAX26 diagnostics'.encode('utf-16-le')
    assert i.body[at:at+len(old)]==old
    i.body[at:at+len(new)]=new
    runtime['measurements_revision']=26
    return runtime
