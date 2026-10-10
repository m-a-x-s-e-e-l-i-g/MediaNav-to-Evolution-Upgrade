"""Check the report inventory and its preserved source hashes; no firmware execution.

Only writes analysis/firmware/detail-report-audit.json after all checks pass.
Does not rerun model suites, follow firmware callers, or build update payloads.
"""
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ANALYSIS = ROOT / "analysis"
LINK = re.compile(r"\[[^\]]*\]\(([^)]+)\)")
DIGEST = re.compile(r"[0-9a-f]{64}\Z")


def main():
    catalog = ANALYSIS / "bug-keuzes.md"
    audit = ANALYSIS / "detail-report-audit.md"
    ids = re.findall(r"^\| ([A-Z]+-\d+) \|", catalog.read_text(encoding="utf-8"), re.M)
    if len(ids) != len(set(ids)):
        raise ValueError("Duplicate finding IDs")
    # Only the report-coverage table defines the completed review scope.
    table = audit.read_text(encoding="utf-8").split("## Rapportdekking en samenvoeging", 1)[1]
    table = table.split("## Kandidaten", 1)[0]
    reports = sorted({ANALYSIS / target for target in LINK.findall(table) if target.endswith(".md")})
    changed_docs = [catalog, audit, ANALYSIS / "resume-checkpoint.md", ROOT / "README.md",
                    ANALYSIS / "release-requirements.md"]
    evidence_paths = set()
    link_count = 0
    for document in sorted(set(reports + changed_docs)):
        for target in LINK.findall(document.read_text(encoding="utf-8")):
            if "://" in target or target.startswith("#"):
                continue
            path = (document.parent / target.split("#", 1)[0]).resolve()
            if not path.is_file() and path != ANALYSIS / "firmware/detail-report-audit.json":
                raise ValueError(f"Missing link in {document.name}: {target}")
            link_count += 1
            if document in reports and path.suffix == ".json":
                evidence_paths.add(path)

    modules = json.loads((ANALYSIS / "corpus/modules.json").read_text(encoding="utf-8"))
    by_digest = {}
    for module in modules:
        by_digest.setdefault(module["sha256"], []).append(ROOT / module["path"])
    micom = ANALYSIS / "firmware/micom-image.bin"
    by_digest.setdefault(hashlib.sha256(micom.read_bytes()).hexdigest(), []).append(micom)
    checked = {}
    source_refs = []
    range_count = 0

    def verify_source(digest, artifact, label, source_path=None):
        if not isinstance(digest, str) or not DIGEST.fullmatch(digest):
            raise ValueError(f"Invalid source digest: {artifact.name}/{label}")
        candidates = [ROOT / source_path] if source_path else by_digest.get(digest, [])
        if not candidates:
            raise ValueError(f"Source cannot be resolved: {artifact.name}/{label}")
        for source in candidates:
            actual = checked.setdefault(str(source), hashlib.sha256(source.read_bytes()).hexdigest())
            if actual != digest:
                raise ValueError(f"Source changed: {source}")
        source_refs.append({"artifact": str(artifact.relative_to(ROOT)), "label": label,
                            "sha256": digest,
                            "paths": [str(p.relative_to(ROOT)) for p in candidates]})

    def walk(node, artifact):
        nonlocal range_count
        if isinstance(node, list):
            for item in node:
                walk(item, artifact)
        elif isinstance(node, dict):
            if isinstance(node.get("raw_hex"), str) and "sha256" in node:
                raw = bytes.fromhex(node["raw_hex"])
                if hashlib.sha256(raw).hexdigest() != node["sha256"]:
                    raise ValueError(f"Preserved-byte digest mismatch: {artifact}")
                range_count += 1
            for key, value in node.items():
                if key == "source_hashes":
                    for name, digest in value.items():
                        verify_source(digest, artifact, name)
                elif key in ("sources", "modules") and isinstance(value, list):
                    for source in value:
                        if not isinstance(source, dict):
                            continue
                        digest = source.get("sha256", source.get("source_sha256"))
                        if digest:
                            verify_source(digest, artifact, source.get("name", source.get("module", key)),
                                          source.get("path", source.get("source_path")))
                walk(value, artifact)

    for artifact in sorted(evidence_paths):
        data = json.loads(artifact.read_text(encoding="utf-8"))
        for key in ("source_sha256", "driver_sha256", "updater_sha256", "image_sha256", "flat_sha256"):
            if isinstance(data.get(key), str):
                verify_source(data[key], artifact, key, data.get("source_path"))
        if "module" in data and "sha256" in data:
            verify_source(data["sha256"], artifact, data["module"])
        walk(data, artifact)

    output = {
        "date": "2026-10-08", "producer_sha256": hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        "binary_execution": False, "model_suites_rerun": False,
        "update_payload_written": False, "unit_access": False,
        "scope": "Existing detail-report inventory, links, source hashes and embedded raw-byte digests",
        "skipped_checkpoint_steps": [1, 2], "catalog_ids": ids,
        "catalog_count": len(ids), "previous_count": 51, "added_count": len(ids) - 51,
        "reviewed_reports": [str(p.relative_to(ROOT)) for p in reports],
        "reviewed_report_count": len(reports), "checked_local_links": link_count,
        "evidence_artifacts": [str(p.relative_to(ROOT)) for p in sorted(evidence_paths)],
        "checked_source_files": len(checked), "source_references": source_refs,
        "checked_embedded_raw_byte_digests": range_count,
        "document_sha256": {str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest()
                            for p in sorted(set(reports + changed_docs))},
        "limitations": ["Does not verify fixture outcomes or firmware semantics",
                        "Embedded byte digests are integrity checks, not independent address-mapping proofs",
                        "Unresolved callers, native hardware behavior and complete module coverage remain open"],
    }
    destination = ANALYSIS / "firmware/detail-report-audit.json"
    destination.write_text(json.dumps(output, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(json.dumps({key: output[key] for key in ("catalog_count", "added_count", "reviewed_report_count",
                     "checked_local_links", "checked_source_files", "checked_embedded_raw_byte_digests")},
                     ensure_ascii=False))


if __name__ == "__main__":
    main()
