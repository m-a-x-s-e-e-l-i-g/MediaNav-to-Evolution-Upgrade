"""Refuse mismatched inputs, incomplete payloads and existing output."""
from pathlib import Path
import tempfile
import unittest

from build_artwork_gdi_guards_development import build
from patch_artwork_gdi_guards import patch


class RefusalTests(unittest.TestCase):
    def test_wrong_input(self):
        with self.assertRaisesRegex(ValueError, 'exact PR34'):
            patch(b'not the reviewed cumulative input')

    def test_existing_output_preserved(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            out = root/'old'
            out.mkdir()
            marker = out/'keep'
            marker.write_bytes(b'previous work')
            with self.assertRaisesRegex(ValueError, 'never overwritten'):
                build(root/'missing', out)
            self.assertEqual(marker.read_bytes(), b'previous work')
            self.assertEqual(list(out.iterdir()), [marker])

    def test_missing_extra_members(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            baseline = root/'input'
            baseline.mkdir()
            for extra in (False, True):
                if extra:
                    (baseline/'extra').write_bytes(b'extra')
                with self.assertRaisesRegex(ValueError, 'missing/extra'):
                    build(baseline, root/'out')
                self.assertFalse((root/'out').exists())

    def test_overlap(self):
        with tempfile.TemporaryDirectory() as directory:
            baseline = Path(directory)
            with self.assertRaisesRegex(ValueError, 'separate directories'):
                build(baseline, baseline/'out')


if __name__ == '__main__':
    unittest.main()
