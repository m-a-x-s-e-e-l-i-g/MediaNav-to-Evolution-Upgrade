"""Preserve persistent/non-overwriting MAX21 logger; notify without erasure."""
from debug_runtime20 import build_core as previous


def build_core(i):
    runtime=previous(i);at=runtime['strings']['header']-i.text
    old='\ufeffMAXmade 7.0.6.MAX20 diagnostics';new=old.replace('MAX20','MAX22')
    a=old.encode('utf-16-le');b=new.encode('utf-16-le')
    assert i.body[at:at+len(a)]==a;i.body[at:at+len(b)]=b
    address=runtime['addresses']['status'];r=next(r for r in i.routines if r['address']==address)
    # Invalidate(FALSE) is the native cached-surface notification. Settings draws
    # its controls explicitly after that paint, clearing only the status row.
    before=r['assembly'];needle="addiu a2, zero, 1\n"+i.api('invalidate')
    assert needle in before
    after=before.replace(needle,"move a2, zero\n"+i.api('invalidate'))
    i.routines=[r for r in i.routines if r['address']!=address]
    i.rows=[r for r in i.rows if r[0]!=address]
    i.reloc=[r for r in i.reloc if not address-i.base<=r[0]<address-i.base+0x400]
    i.routine_at(address,after,0x400,0x20,['s0'])
    runtime['measurements_revision']=22;runtime['settings_status_erases_whole_window']=False
    return runtime
