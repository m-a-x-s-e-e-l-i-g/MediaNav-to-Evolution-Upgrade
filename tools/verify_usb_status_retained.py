"""Adapt prior USB API fixtures for the added status mutex, without editing old tools."""
from contextlib import contextmanager
from verify_media_responsiveness import VM
from inspect_bt_pairing import data

@contextmanager
def mutex_fixtures():
    old_run=VM.run
    def run(m,*args,**kwargs):
        state=next((s for s in m.pe.sections if s.Name.rstrip(b'\0')==b'.mxstate'),None)
        # AppMain has its own explicitly checked fixture. Only extend MgrUSB suites.
        if state and m.pe.OPTIONAL_HEADER.SizeOfImage<0x100000 and not getattr(m,'status_mutex_installed',False):
            m.status_mutex_installed=True
            delta=m.pe.OPTIONAL_HEADER.ImageBase-0x10000
            rw=m.pe.OPTIONAL_HEADER.ImageBase+state.VirtualAddress;text=rw-0x50000
            m.ranges.extend([(text+n,text+n+cap) for n,cap in ((0,0x100),(0x100,0x100),(0x300,0x200),
                            (0x500,0x200),(0x700,0x1c),(0x800,0x200))])
            m.ranges.append((0x23c44+delta,0x23ce0+delta))
            handle=0xfa090001;owned=False;opened=False
            def clobber():
                for r in (*range(3,16),24,25):m.reg[r]=0xdead0000+r
            def create(v):
                nonlocal opened
                assert v.reg[4:6]==[0,0] and v.text(v.reg[6])=='MAXmade_USB_Status_v1'
                assert not opened;opened=True;clobber();return handle
            def release(v):
                nonlocal owned
                assert v.reg[4]==handle and owned;owned=False;clobber();return 1
            def install_dispatch(iat,token,fn):
                before=m.read(iat);old=m.hooks.get(before)
                def dispatch(v):
                    if v.reg[4]==handle:return fn(v)
                    assert old is not None,hex(iat)
                    return old(v)
                m.write(iat,token);m.hooks[token]=dispatch
            def wait(v):
                nonlocal owned
                assert opened and v.reg[5]==0xffffffff
                owned=True;clobber();return 0
            def close(v):
                nonlocal opened
                assert opened and not owned;opened=False;clobber();return 1
            close_iat=next(s.address for d in m.pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.ordinal==553)
            install_dispatch(close_iat,0xfa090010,close)
            install_dispatch(0x2f048+delta,0xfa090014,wait)
            m.write(rw+0x100,0xfa090018);m.hooks[0xfa090018]=create
            m.write(rw+0x104,0xfa09001c);m.hooks[0xfa09001c]=release
        return old_run(m,*args,**kwargs)
    VM.run=run
    try:yield
    finally:VM.run=old_run

def verify(raw):
    from verify_usb_save_feedback import verify as saves
    from verify_usb_resume_modes import verify as modes
    from verify_usb_folders import verify as folders,retained_sorting
    from verify_wma_shuffle_v2 import verify as wma
    from verify_artwork_playlist import verify as artwork,regressions
    with mutex_fixtures():
        results={}
        for name,fn in [('saves',saves),('modes',modes),('folders',folders),('sorting',retained_sorting),
                        ('wma',wma),('artwork',artwork),('earlier',regressions)]:
            print('Retained USB '+name,flush=True);results[name]=fn(raw)
    return results
