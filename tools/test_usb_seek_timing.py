"""Builder refusal/preservation and signed MIPS arithmetic fixture checks."""
from pathlib import Path
import tempfile
import unittest

from build_usb_seek_timing_development import build
from patch_usb_seek_timing import patch
from verify_usb_seek_timing import TimingVM


class RefusalTests(unittest.TestCase):
    def test_wrong_input_refused(self):
        with self.assertRaisesRegex(ValueError, 'exact PR-27'):
            patch(b'not the checked initialization input')

    def test_existing_output_preserved(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory); output = root/'previous'; output.mkdir()
            sentinel = output/'keep.txt'; sentinel.write_bytes(b'previous verified work')
            with self.assertRaisesRegex(ValueError, 'never overwritten'):
                build(root/'missing', output)
            self.assertEqual(sentinel.read_bytes(), b'previous verified work')
            self.assertEqual(list(output.iterdir()), [sentinel])

    def test_incomplete_and_extra_members_no_output(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory); baseline = root/'input'; baseline.mkdir()
            for extra in (False, True):
                if extra: (baseline/'unexpected.exe').write_bytes(b'unexpected')
                with self.assertRaisesRegex(ValueError, 'missing/extra'):
                    build(baseline, root/'output')
                self.assertFalse((root/'output').exists())

    def test_input_output_overlap_refused(self):
        with tempfile.TemporaryDirectory() as directory:
            baseline = Path(directory)
            with self.assertRaisesRegex(ValueError, 'separate directories'):
                build(baseline, baseline/'output')

    def test_signed_division_truncates_towards_zero(self):
        # Architectural constants independent of the timing patch's decisions.
        m = object.__new__(TimingVM); m.reg = [0]*32
        word = (4 << 21) | (5 << 16) | 0x1A
        for a, b, q, r in ((7, 3, 2, 1), (-7, 3, -2, -1), (7, -3, -2, 1), (-7, -3, 2, -1)):
            m.reg[4], m.reg[5] = a & 0xFFFFFFFF, b & 0xFFFFFFFF
            m.plain(word)
            self.assertEqual((m.lo, m.hi), (q & 0xFFFFFFFF, r & 0xFFFFFFFF))


if __name__ == '__main__': unittest.main()
