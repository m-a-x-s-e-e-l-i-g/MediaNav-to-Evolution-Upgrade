"""Retain full byte suites; also verify relocated WMA unwind-state metadata."""
import struct
from verify_wma_shuffle import verify as first_verify,structure as first_structure,SOURCE
from verify_media_responsiveness import parsed
from verify_usb_input_safety import relocated

def exception_mapping(raw):
    cases=0
    for delta in (0,0x1000,0x10000,0x123000):
        p=parsed(relocated(raw,delta) if delta else raw)
        info=struct.unpack('<10I',p.get_data(0x28b88-0x10000,40))
        assert info==(0x19930522,1,0x28b80+delta,0,0,2,0x28bb0+delta,0,1,0xffffffd0)
        assert p.get_data(0x28b80-0x10000,8)==struct.pack('<2I',0xffffffff,0x18f54+delta)
        assert p.get_data(0x28bb0-0x10000,16)==struct.pack('<4I',0x18328+delta,0,0x18f0c+delta,0xffffffff)
        assert not any(p.get_data(0x28bc0-0x10000,54*8-16))
        cases+=1
    return dict(cases=cases,cleanup_state_ranges_correct=True,relocated_bases=3,native_unwind_executed=False)

def verify(raw):
    checks=first_verify(raw);checks['exception_mapping']=exception_mapping(raw);return checks

def structure(raw,recipe):return first_structure(raw,recipe)
