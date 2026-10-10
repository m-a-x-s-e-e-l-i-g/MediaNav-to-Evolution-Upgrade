"""Check complete-copy behavior and refusal of unsafe or mismatched build inputs."""
import json
from pathlib import Path
import tempfile
import unittest
from release_payload import member, plan_at, reproduce, sha


class ReleasePayloadTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.baseline = self.root / "baseline"
        self.baseline.mkdir()
        self.output = self.root / "output"
        self.original = b"original-app"
        self.updated = b"ORIGINAL-app-tail"
        (self.baseline / "app").write_bytes(self.original)
        (self.baseline / "boot").write_bytes(b"retained-boot")
        self.plan = {"revision": "test", "members": [
            self.row("app", self.original, self.updated),
            self.row("boot", b"retained-boot", b"retained-boot")],
            "changes": [{"path": "app", "edits": [
                {"offset": 0, "before": b"original".hex(), "after": b"ORIGINAL".hex()},
                {"offset": len(self.original), "before": "", "after": b"-tail".hex()}]}]}

    def row(self, name, before, after):
        return {"path": name, "before_bytes": len(before), "before_sha256": sha(before),
                "after_bytes": len(after), "after_sha256": sha(after)}

    def test_complete_copy_and_appended_code(self):
        result = reproduce(self.plan, self.baseline, self.output)
        self.assertEqual((self.output / "payload/app").read_bytes(), self.updated)
        self.assertEqual((self.output / "payload/boot").read_bytes(), b"retained-boot")
        self.assertEqual(result["unchanged_members"], 1)

    def test_wrong_input_is_refused_without_publishing_output(self):
        (self.baseline / "app").write_bytes(b"changed-app!")
        with self.assertRaisesRegex(ValueError, "Baseline bytes changed"):
            reproduce(self.plan, self.baseline, self.output)
        self.assertFalse(self.output.exists())

    def test_missing_or_extra_members_are_refused(self):
        (self.baseline / "boot").unlink()
        with self.assertRaisesRegex(ValueError, "inventory changed"):
            reproduce(self.plan, self.baseline, self.output)
        (self.baseline / "boot").write_bytes(b"retained-boot")
        (self.baseline / "extra").write_bytes(b"unexpected")
        with self.assertRaisesRegex(ValueError, "inventory changed"):
            reproduce(self.plan, self.baseline, self.output)

    def test_wrong_edit_precondition_is_refused(self):
        self.plan["changes"][0]["edits"][0]["before"] = b"different".hex()
        with self.assertRaisesRegex(ValueError, "Edit precondition failed"):
            reproduce(self.plan, self.baseline, self.output)
        self.assertFalse(self.output.exists())

    def test_existing_output_is_never_replaced(self):
        self.output.mkdir()
        (self.output / "keep").write_bytes(b"existing")
        with self.assertRaises(FileExistsError):
            reproduce(self.plan, self.baseline, self.output)
        self.assertEqual((self.output / "keep").read_bytes(), b"existing")

    def test_unsafe_and_duplicate_paths_are_refused(self):
        for name in ("../outside", "/absolute", "a/../outside", "a\\outside", "C:/outside"):
            with self.subTest(name=name), self.assertRaises(ValueError):
                member(name)
        self.plan["format"] = 1
        self.plan["members"].append(self.row("APP", self.original, self.updated))
        path = self.root / "plan.json"
        path.write_text(json.dumps(self.plan))
        with self.assertRaisesRegex(ValueError, "Duplicate"):
            plan_at(path)


if __name__ == "__main__":
    unittest.main()
