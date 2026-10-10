# Tools

## Release

- [release_payload.py](release_payload.py): recover the pinned baseline and reproduce the complete MAX04 payload.
- [check_repository.py](check_repository.py): source/evidence integrity, syntax, recipe and documentation checks.
- `build_*_development.py`: original cumulative stage builders.
- `patch_*.py`: bounded, hash-guarded edits to existing native binaries.
- `verify_*.py`, `audit_*.py`: instruction fixtures, structural checks and retained behavior audits.

## Reverse engineering

- [decompiled_view.py](decompiled_view.py): stream an address-linked C function from the published exports.
- [function_view.py](function_view.py): inspect generated assembly/function boundaries.
- [corpus_catalog.py](corpus_catalog.py), [function_index.py](function_index.py): module and function maps.
- [disassemble_corpus.py](disassemble_corpus.py): regenerate full assembly locally.
- [run_ghidra.py](run_ghidra.py), [ghidra/](ghidra): headless analysis, seeding and export scripts.
- `inspect_*.py`: application, Bluetooth, USB, updater, kernel, driver and protocol contracts.

## UI

- [build_home_theme.py](build_home_theme.py), [build_av_theme.py](build_av_theme.py): native resource authoring.
- [integrate_approved_skin.py](integrate_approved_skin.py): combine color edits with the cumulative application fixes.
- [build_ui_theme_preview.py](build_ui_theme_preview.py): browser asset workbench.
- [home_theme_preview.js](home_theme_preview.js), [av_theme_preview.js](av_theme_preview.js): scenario renderers.

See [development setup and original-stage dependencies](../docs/development.md). Downloaded runtimes, firmware inputs and build outputs stay outside Git.
