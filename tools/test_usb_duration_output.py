"""Refuse unsafe/mismatched development inputs and preserve existing output."""
from pathlib import Path
import tempfile
import unittest

from build_usb_duration_output_development import build
from patch_usb_duration_output import patch


class RefusalTests(unittest.TestCase):
    def test_wrong_input_refused(self):
        with self.assertRaisesRegex(ValueError, 'exact PR-31'): patch(b'not the checked completion input')

    def test_existing_output_preserved(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory); output = root/'previous'; output.mkdir()
            sentinel = output/'keep.txt'; sentinel.write_bytes(b'previous verified work')
            with self.assertRaisesRegex(ValueError, 'never overwritten'): build(root/'missing', output)
            self.assertEqual(sentinel.read_bytes(), b'previous verified work')
            self.assertEqual(list(output.iterdir()), [sentinel])

    def test_missing_extra_members_no_output(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory); baseline = root/'input'; baseline.mkdir()
            for extra in (False, True):
                if extra: (baseline/'unexpected.exe').write_bytes(b'unexpected')
                with self.assertRaisesRegex(ValueError, 'missing/extra'): build(baseline, root/'output')
                self.assertFalse((root/'output').exists())

    def test_input_output_overlap_refused(self):
        with tempfile.TemporaryDirectory() as directory:
            baseline = Path(directory)
            with self.assertRaisesRegex(ValueError, 'separate directories'): build(baseline, baseline/'output')


if __name__ == '__main__': unittest.main()
