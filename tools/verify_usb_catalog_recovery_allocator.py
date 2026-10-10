"""Execute the recovery helper through the original allocation/accounting code."""
import argparse
import hashlib
import itertools
import json
from pathlib import Path

from inspect_bt_pairing import put
from patch_usb_catalog_recovery import ALLOCATE, COUNTERS
from verify_media_responsiveness import call
from verify_usb_catalog_recovery import Scan
from verify_usb_input_safety import relocated

SHA = 'a9f0bf2266932d5574abd67c0a6444a27ada6e80064d6ee334db93e14e6d7ec8'


def verify(raw):
    assert hashlib.sha256(raw).hexdigest() == SHA
    traces = []
    for delta, count, ok, external in itertools.product((0, 0x1000, 0x10000, 0x123000), (6, 99, 100), (False, True), (False, True)):
        loaded = relocated(raw, delta) if delta else raw
        s = Scan(loaded, delta, missing=1, tracking=count)
        m = s.m
        m.ranges.append((0x12844+delta, 0x129c8+delta))
        del m.hooks[0x12844+delta]
        calls = []
        pointer, slot, size = s.addresses[0], s.slots[0], s.sizes[0]
        m.write(0x2f1e8+delta, 0x7777); m.write(0x2f03c+delta, 0xf0030000)

        def ioctl(v):
            assert v.reg[4:6] == [0x7777, 0x15] and v.read(v.reg[6]) == size
            assert v.reg[7] == 4 and v.read(v.reg[29]+0x14) == 16
            dest = v.read(v.reg[29]+0x10)
            value = pointer if ok and external else 0
            v.write(dest, value); v.write(dest+4, value)
            calls.append('ioctl')
            s.clobber(v)
            return int(bool(value))

        def heap(v):
            assert v.reg[4] == size and not (ok and external)
            calls.append('heap')
            s.clobber(v)
            return pointer if ok else 0

        def zero(v):
            at, n = v.reg[4], v.reg[6]
            assert v.reg[5] == 0 and n in (12, size)
            if n == size:
                assert at == pointer and m.read(slot) == 0
                s.clears.append(dict(bytes=n, pointer=at))
                put(v, at, bytes(0x440))
            else:
                put(v, at, bytes(12))
            s.clobber(v)
            return at

        m.hooks.update({0xf0030000: ioctl, 0x2538c+delta: heap,
                        0x253dc+delta: zero, 0x12540+delta: s.log})
        result = call(m, ALLOCATE+delta, [slot, size, COUNTERS+delta])
        attempted = count < 100
        assert result == (pointer if attempted and ok else 0)
        assert m.read(slot) == result
        assert m.read(COUNTERS+delta) == int(attempted)
        assert m.read(0x2fe98+delta) == count+int(attempted)
        assert len(s.clears) == int(attempted and ok)
        assert calls == ([] if not attempted else ['ioctl'] if ok and external else ['ioctl', 'heap'])
        if attempted:
            at = 0x2fb78+delta+count*8
            assert m.read(at) == result and m.read(at+4) == int(ok and external)
        traces.append(dict(delta=hex(delta), initial_count=count, allocation_ok=ok,
                           external=external, calls=calls, result=result,
                           tracking_count=m.read(0x2fe98+delta), clears=s.clears))
    return dict(candidate_sha256=SHA, cases=len(traces), traces=traces,
                native_executed=False, hardware_tested=False,
                limits=['Actual recovery helper and original allocator/accounting instructions; driver, heap allocation and logging fixtures',
                        'External output address and returned writable alias are equal in fixtures; driver alias contract not proved',
                        'Large memset arguments checked; only record prefix materialized',
                        'Sequential execution only; no native allocation/concurrency or loader testing'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--candidate', required=True, type=Path)
    parser.add_argument('--report', required=True, type=Path)
    args = parser.parse_args()
    raw = args.candidate.read_bytes()
    result = verify(raw)
    assert args.candidate.read_bytes() == raw
    result['verifier_sha256'] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'], sha256=SHA)))
