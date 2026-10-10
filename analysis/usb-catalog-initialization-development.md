# Initialize the catalog pointer before reset

- **Stability:** initialize the directory-buffer pointer before the constructor's first reset.
- **Compatibility:** constructor outputs and API calls match the previous candidate when storage is initially zero; reused storage produces those same outputs.
- **Scope:** one instruction in MgrUSB, inside a complete MAX04-based development payload. Native heap behavior remains unverified.

## Defect and change

`CFileMgr` constructor `14b00` calls reset `12e1c` before assigning its directory-buffer pointer at object offset `38`. Reset reads that field and, if nonzero, passes it to `memset` with length **2,720,000 bytes**. Reused object storage can therefore direct the clear to memory that does not belong to this new catalog.

The ROM's operator-new export, ordinal 1095 at `40019304`, calls allocation helper `400739cc` with flags zero. [Two actual-instruction allocator traces](firmware/usb-catalog-allocator-contract.json) preserve this call path. [Windows CE LocalAlloc](https://learn.microsoft.com/en-us/previous-versions/ms911540%28v%3Dmsdn.10%29) documents zero as fixed-memory allocation; zero initialization requires `LMEM_ZEROINIT`. The constructor must initialize its pointer rather than depend on fresh heap contents.

[Patch](../tools/patch_usb_catalog_initialization.py) replaces the `nop` at `14b50`, the reset call's delay slot, with `sw zero, 38(s2)`. The store executes before entering reset. The later allocation still assigns the real directory-buffer pointer.

No call, branch, stack frame, import, relocation, buffer capacity or exception record changes. Undoing the single four-byte edit restores the exact previous candidate.

## Verification

- [Focused verifier](../tools/verify_usb_catalog_initialization.py): **261 checks**, including the reproduced foreign-pointer clear at four load addresses.
- All 16 combinations of four catalog allocations succeeding/failing, successful/failed event creation and ordinary/high-bit pointers are covered.
- Actual constructor, song-catalog constructor and reset instructions execute. Object contents, allocation sizes/order, diagnostics, event creation, saved registers, return values and stack/object canaries are checked.
- A separate ROM allocator check executes operator-new and its allocation-argument helper for success/failure. LocalAlloc and the new-handler remain fixtures.
- Large clear arguments are checked; object storage and a 32-byte foreign-buffer prefix are materialized. The fixture demonstrates the foreign destination without claiming a native memory-corruption incident.
- [Complete builder](../tools/build_usb_catalog_initialization_development.py) retains all **1,918 MAX04 members** and preceding candidates, verifies every written path/hash and reruns cumulative checks.
- [Historical runner](../tools/verify_usb_catalog_initialization_retained.py) preserves original source/input pins and prior graphics-entry adaptations.
- [Refusal tests](../tools/test_usb_catalog_initialization.py) cover wrong input, incomplete/extra members, directory overlap and existing output.
- Published results: [cumulative evidence](firmware/usb-catalog-initialization-development.json), [complete member manifest](firmware/usb-catalog-initialization-members.json), [historical checks](firmware/usb-catalog-initialization-retained.json).
- **6,565 cumulative checks** and **72,212 historical checks** passed on the exact written candidate; two additional ROM allocator traces passed locally.
- Input MgrUSB SHA256: `7c1af7ce3d3a4c75dab75f4df7eb6fe1b5b016034f61f083678382b702ec0a71`.
- Candidate MgrUSB SHA256: `5f34249de2ec66a9cc3f22a6dc35e063eefc885faee58b3b12d8a5e56a29c234`.

## Remaining work

Failed allocations still leave a partial catalog. Its later scan/readiness and recovery paths are unresolved; this patch repairs initialization only. Native heap reuse, scheduling, loader/unwind and device incident frequency remain unverified. No LGU or version bump is included.
