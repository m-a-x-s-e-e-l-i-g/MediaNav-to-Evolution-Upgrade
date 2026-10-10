# Development

## Repository layout

| Path | Contents |
| --- | --- |
| [tools/](../tools/README.md) | Python patchers, verifiers, inspectors, Ghidra scripts and browser preview code |
| [src/](../src/README.md) | Checked release edit plan, approved native UI assets and LGU decoding data |
| [analysis/](../analysis/README.md) | Decompiled C, function maps, module inventories, contract notes and evidence |
| [releases/7.0.6.MAX04/](../releases/7.0.6.MAX04/README.md) | Release notes, hashes, manifests, completed-stage records and integration proof |
| [assets/ui/max04/](../assets/ui/max04) | Before/after screenshots used by the guide |

The editable implementation is Python patch code and native artwork. Decompiled C is address-linked pseudocode, not the original vendor source or a rebuildable firmware project.

## Read and check

Use Python 3.12 or newer from the repository root:

```powershell
python tools/check_repository.py
python tools/decompiled_view.py AppMain.exe 0x11000 --max-lines 40
```

- These commands work without downloading firmware or installing Ghidra.
- The repository check verifies published source/evidence hashes, Python syntax, artwork, release inventory and active documentation links.
- GitHub Actions runs the repository check, refusal tests and complete payload reproduction on pushes and pull requests.

## Reproduce the MAX04 payload

The published plan contains all 1,918 member hashes and 279 changes. The historical baseline is a build input, not a recommended update.

```powershell
git fetch origin
python tools/release_payload.py --prepare-input .inputs/max04-baseline
python tools/release_payload.py --baseline .inputs/max04-baseline --out build/max04-reproduced
```

- Input preparation reads a pinned LGU from this repository's Git history, checks its SHA256 and independently decodes every member.
- Reproduction refuses missing files, extra files, changed baseline bytes and incorrect edit preconditions.
- It writes the complete payload to a fresh directory and checks every output hash against the published MAX04 manifest.
- `build/max04-reproduced/reproduction.json` records the result. This reproduces the payload; it does not rebuild the applications from C or prove device behavior.
- A shallow clone may need `git fetch --unshallow` before recovering the historical input.

## Research dependencies

```powershell
python -m venv .venv
.venv/Scripts/python -m pip install -r tools/requirements.txt
```

- Optional cryptographic fixtures: [requirements-crypto-models.txt](../tools/requirements-crypto-models.txt).
- Ghidra and JDK versions/hashes: [re-toolchain.json](../analysis/re-toolchain.json). `python tools/setup_pinned_re_tools.py` downloads those exact portable tools locally.
- Original extracted binaries belong in ignored `extracted/` paths recorded in [modules.json](../analysis/corpus/modules.json).
- Upstream tools and baseline origins are listed in [provenance](provenance.md).
- Full assembly dumps and Ghidra databases are generated locally. With original inputs available: `python tools/disassemble_corpus.py 705md rom corruption-fix remove-md`.

## Original development builders

- All patchers and fixture models are published byte-for-byte to preserve their recorded hash pins.
- Original `build_*_development.py` scripts use the historical `build/`, `extracted/` and `sources/` workspace paths embedded in their code. They require the preceding stage's complete payload and manifest.
- Completed cumulative manifests are in [release development records](../releases/7.0.6.MAX04/development). Detailed contracts describe each stage and its checks.
- The original cumulative builder and integration proof are retained for audit. The compact release plan above provides a payload reproduction route without recreating every intermediate workspace.
- `refresh_max04_docs.py` is a historical publication helper with a workspace-specific target; it is not the current release workflow.
- New fixes should have new patch recipes and evidence. Preserve historical source snapshots when changing code referenced by an existing proof.

## Preview and package

- [UI workflow](ui.md): render actual assets and compare native layout fixtures.
- [Release workflow](releases.md): pack, independently decode, round-trip and publish a complete LGU.
