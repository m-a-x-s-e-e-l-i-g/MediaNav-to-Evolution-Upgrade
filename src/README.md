# Release implementation

## MAX04

- [patches/max04.json](patches/max04.json): complete 1,918-member inventory; binary edits include before/after bytes, file offsets and hashes.
- [ui/M1/](ui/M1): 271 approved native BMP assets, preserving the firmware's image contracts.
- [container/lgu0.json](container/lgu0.json): upstream LGU0 XOR table and source attribution.
- [tools/](../tools/README.md): readable Python patch recipes, resource generators and verification models.

## Decompiled code

- [Source index](../docs/source-index.md): 256 address-linked C exports, with module origins and metadata.
- Decompiled output remains under `analysis/decompiled/` so existing inspectors and hash-pinned evidence keep their original paths.
- These are analysis candidates; the firmware is modified with verified binary edits, not compiled from this C.

Follow the [development guide](../docs/development.md) to reproduce the complete MAX04 payload.
