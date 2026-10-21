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

## Historical MAX10 release

The [MAX10 release notes](../releases/7.0.6.MAX10/README.md) preserve the original failed artwork test, owner feedback and cumulative code snapshots. Run `python tools/check_max10_release.py`, then use `python tools/release_max10_payload.py --prepare-input .inputs/max10-baseline` and `python tools/release_max10_payload.py --baseline .inputs/max10-baseline --out build/max10-reproduced` for full payload reproduction from the pinned historical MAX04 input. MAX04 sources and evidence remain preserved.

## Historical MAX15 release

[The MAX15 notes](../releases/7.0.6.MAX15/README.md) describe owner-confirmed Bluetooth artwork, cumulative Settings/light-theme/player changes and the [test device](test-device.md). Run `python tools/check_max15_release.py`, then `python tools/release_max15_payload.py --prepare-input .inputs/max15-baseline` and `python tools/release_max15_payload.py --baseline .inputs/max15-baseline --out build/max15-reproduced`. The plan reproduces all 1,918 payload files from the pinned historical MAX04 input; exact patch constructors and dependencies are preserved in the release source manifest. MAX04/MAX10 records remain historical.

## Historical MAX32 release

[MAX32](../releases/7.0.6.MAX32/README.md) integrates PR60's iPhone final-packet
fix into the full prior payload. Run `python tools/check_max32_release.py` for
release inventory/source/proof checks, optionally with `--lgu path/to/upgrade.lgu`.
The complete builder is `tools/build_max32.py`; public baseline and pinned Windows
PC packing tools are required. Contributor car feedback and complete-release
physical testing remain separate.

## Historical MAX31 release

[MAX31](../releases/7.0.6.MAX31/README.md) corrects intentional DBoot/CE entry
being mistaken for startup failure, with native desktop initialization in the
recovery path. Publication was authorized on 20 October 2026; physical MAX31
testing, including the quick CE reboot, remains pending. It retains all 1,920
MAX30 paths and the inherited application features. Run
`python tools/check_max31_release.py` to check the full inventory, 115 frozen
source pins and recorded proof/status; add `--lgu path/to/upgrade.lgu` to check
the downloaded artifact. Cumulative build recipes require their pinned inputs
and are documented in the release notes.

## Historical MAX18 release

[MAX18](../releases/7.0.6.MAX18/README.md) carries forward the tested Bluetooth
album art and redesigns Nav and the volume popup, with direct navigation launch.
The owner tested MAX18 in the car and approved publication on 13 October 2026.
Source checks use Python 3.12 or newer. For exact MAX18 navigation archive
reproduction, use **Windows Python 3.14.2** with zlib runtime
**1.3.1.zlib-ng**. Different deflaters can preserve skin contents while changing
ZIP bytes, so the reproduction tool verifies the runtime and refuses substitutions.
Run `python tools/check_max18_release.py`, then:

```powershell
python tools/release_max18_payload.py --prepare-input .inputs/max18-baseline
python tools/release_max18_payload.py --prepare-nav .inputs/max18-navigation.zip
python tools/release_max18_payload.py --baseline .inputs/max18-baseline --navigation .inputs/max18-navigation.zip --out build/max18-reproduced
```

The baseline is reproduced from pinned Git history through the existing MAX15
recipe. Navigation input is extracted from the hash-pinned public 4.1.0 backup;
the private device backup is not required. All 1,919 output hashes and the full
navigation archive are checked. GitHub Actions runs this reproduction on
Windows with the pinned Python version, alongside the Linux source checks.

## Current MAX33 release

[MAX33 release notes](../releases/7.0.6.MAX33/README.md) describe resumable
application copying and explicit repair after an ambiguous settings checkpoint.
The owner authorized MAX33 as the main normal release on 22 October 2026.
Physical validation remains unconfirmed. See [the transaction design](installer-resume33.md) for its boundaries.

Run `python tools/check_max33_release.py`, optionally with `--lgu path/to/upgrade.lgu`,
to verify the complete inventory, frozen sources and recorded fixture evidence.
Builders/verifiers are frozen in `releases/7.0.6.MAX33/build-sources/tools/` and
retain their original workspace input paths, like earlier development snapshots.
They need the pinned complete MAX32 extracted stage, prior native updater recipe,
ROM ordinal reference, pinned Zig 0.13 and Windows/WSL MIPS linker toolchain.
They are not firmware-free rebuild commands for a fresh checkout.
