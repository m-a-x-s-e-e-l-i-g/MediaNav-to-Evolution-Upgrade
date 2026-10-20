"""Retain MAX21 metrics and expose the nested Bluetooth/fade waits."""
from debug_metrics21 import app_metrics as prior,patch_call,timed_call,poll_wrapper,sample_call


def app_metrics(i,dbg,tick,hooks):
    metrics=prior(i,dbg,tick,hooks)
    for site,event,label,arg in [(0x11531c,133,'bluetooth_navigation_play_wait',True),
                                 (0x115718,134,'bluetooth_play_settle_wait',True),
                                 (0xd4e50,135,'media_fade_settle_wait',True),
                                 (0xd4e74,136,'media_fade_ipc',False)]:
        import struct
        assert i.p.get_data(site-i.base,4)==struct.pack('<I',0x0100f809)
        row=timed_call(i,dbg,tick,None,1,event,label,register='t0',result_argument=arg)
        row.update(original_site=site,site=site);patch_call(i,site,row['wrapper'])
        metrics['calls'].append(row)
    assert i.code_cursor<=0x18000
    return metrics
