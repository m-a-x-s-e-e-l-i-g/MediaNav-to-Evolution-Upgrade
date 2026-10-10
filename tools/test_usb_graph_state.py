"""Refusal checks for wrong firmware, existing outputs and incomplete payloads."""
from pathlib import Path
import tempfile
import unittest

from build_usb_graph_state_development import build
from patch_usb_graph_state import patch


class RefusalTests(unittest.TestCase):
    def test_wrong_firmware_is_refused(self):
        with self.assertRaisesRegex(ValueError, "exact MAX04"):
            patch(b"not the pinned firmware")

    def test_existing_output_is_preserved(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            output = root/"previous-candidate"
            output.mkdir()
            sentinel = output/"keep.txt"
            sentinel.write_bytes(b"previous verified work")
            with self.assertRaisesRegex(ValueError, "never overwritten"):
                build(root/"missing-input", output)
            self.assertEqual(sentinel.read_bytes(), b"previous verified work")
            self.assertEqual(list(output.iterdir()), [sentinel])

    def test_missing_or_extra_members_create_no_output(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            baseline = root/"incomplete"
            baseline.mkdir()
            for extra in (False, True):
                if extra:
                    (baseline/"unexpected.exe").write_bytes(b"unexpected")
                with self.assertRaisesRegex(ValueError, "missing/extra"):
                    build(baseline, root/"candidate")
                self.assertFalse((root/"candidate").exists())

    def test_input_output_overlap_is_refused(self):
        with tempfile.TemporaryDirectory() as folder:
            baseline = Path(folder)
            with self.assertRaisesRegex(ValueError, "separate directories"):
                build(baseline, baseline/"candidate")


if __name__ == "__main__":
    unittest.main()
