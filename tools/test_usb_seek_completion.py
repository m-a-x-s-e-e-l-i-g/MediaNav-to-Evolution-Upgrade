"""Builder refusal/preservation and packed MIPS instruction encoding checks."""
from pathlib import Path
import struct
import tempfile
import unittest

from build_usb_seek_completion_development import build
from patch_usb_seek_completion import patch, assemble


class RefusalTests(unittest.TestCase):
    def test_wrong_input_refused(self):
        with self.assertRaisesRegex(ValueError, 'exact PR-28'):
            patch(b'not the checked timing input')

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

    def test_packed_load_store_architectural_encodings(self):
        raw, _, relocations = assemble('lwl a1, 3(s3)\nlwr a1, 0(s3)\nswl v0, 3(s3)\nswr v0, 0(s3)',
                                      0x40300, 16)
        self.assertEqual(struct.unpack('<4I', raw), (0x8A650003, 0x9A650000, 0xAA620003, 0xBA620000))
        self.assertEqual(relocations, [])


if __name__ == '__main__': unittest.main()
