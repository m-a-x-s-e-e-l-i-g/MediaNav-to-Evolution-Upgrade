# Provenance and credits

## Project history

- This repository began as a guide and archive for a first-generation MediaNav-to-Evolution conversion.
- MAXmade adds researched application fixes, native UI artwork, patch code and offline verification.
- The old conversion, removal and separate navigation-fix folders are retired from the active tree. Their original files remain in Git history.
- The current complete release includes the existing navigation corruption fix; it needs no separate fix download.

## Credits

- Original **7.0.5.MD / FavreMod** conversion and included DBoot components.
- Original navigation corruption-fix contributors; that executable remains unchanged in MAX04.
- [KwidTechsolutions](https://www.youtube.com/@KwidTechsolutions1), credited by the original guide.
- [MediaNavMods](https://github.com/yosicovich/MediaNavMods), including the LGU XOR table used by the independent decoder.
- [LGU-file-tools](https://github.com/m-a-x-s-e-e-l-i-g/LGU-file-tools), PC-side packing/extraction.
- Ghidra, Capstone, pefile, Pillow, the Windows CE ROM extractor and RL78 research tools.

## Source records

- Upstream repositories, commits and extraction hashes: [provenance.json](../analysis/provenance.json).
- Ghidra/JDK package hashes: [re-toolchain.json](../analysis/re-toolchain.json).
- Imported tools, exported research, native artwork and stage evidence: [publication-manifest.json](publication-manifest.json).
- Firmware module origins and hashes: [modules.json](../analysis/corpus/modules.json).
- Original archive state: [commit d20347b](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/tree/d20347b8faebd1d54fea403a1ad36af462d67ee0).

## Source meaning

- Python tooling and new artwork are the editable MAXmade implementation.
- Decompiled C is generated from existing binaries and retains their original provenance. It is not original vendor source and does not establish complete behavioral understanding.
- The repository's [GPL-3.0 license](../LICENSE) does not replace the ownership or licenses of third-party firmware and components.
- Existing research notes retain their original wording and evidence pins. Older notes can describe drafts or publication states superseded by the current release records.
