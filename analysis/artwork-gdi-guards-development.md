# Album-art graphics guards

- **Stability:** skip bitmap allocation/drawing after failed context creation; skip drawing after failed initial bitmap selection.
- **Cleanup:** when bitmap restoration fails, delete the drawing context before disposing of the unpublished bitmap.
- **Compatibility:** retain successful rendering, the existing no-artwork fallback and every preceding development repair.

## Native findings

The renderer at `1a318..1a60c` does not check CreateCompatibleDC or its initial SelectObject result. It can call Draw with no context or draw into the context's original bitmap while later publishing the unselected new bitmap.

The preceding draw-failure candidate also assumes that restoring the previous bitmap succeeds. On a failed Draw followed by a failed restore, it attempts DeleteObject while the temporary bitmap remains selected. The fixture reproduces the unsuccessful deletion, later DC cleanup and an unpublished live bitmap.

Microsoft's Windows CE 5.0 documentation defines null as failure for [CreateCompatibleDC](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms908166(v=msdn.10)) and bitmap [SelectObject](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms932715(v=msdn.10)). [DeleteObject](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452933(v=msdn.10)) refuses an object still selected into a context. These contracts inform explicit fixtures; they do not prove on-unit behavior or reproduce an observed device incident.

## Change

[Patch](../tools/patch_artwork_gdi_guards.py) checks `s4` before DIB setup and `s0` before SetRect/Draw. It preserves the original GetImageInfo call. A failed initial selection deletes the unpublished bitmap and follows original DC/image/factory cleanup.

After Draw, the owner checks SelectObject's restore result before interpreting Draw's HRESULT. A failed restore deletes the DC first, then attempts bitmap deletion and joins the original image/factory cleanup. Other failed draws retain the preceding fallback. Both SelectObject checks use zero testing: valid handles with the high bit set remain accepted.

Two dispatch blocks use existing instruction space inside the original renderer and its existing stack frame. Its stack-cookie handler `254e4` and cookie slot at frame-relative `-0x28` remain unchanged. The original exception table, imports, section sizes, publication wrappers, previous-cover deletion and command `67` notification remain unchanged.

## Verification

- [Focused verifier](../tools/verify_artwork_gdi_guards.py): **1,538 checks**, with actual renderer/publication/deletion instructions and stateful GDI fixtures.
- The matrix covers four load addresses; null/valid contexts and DIBs; initial and restoring selection failures; positive/negative Draw HRESULT boundaries; ordinary/high-bit handles; and empty/existing artwork.
- Checks include bitmap ownership, cleanup order, unchanged bytes on rejected renders, successful-path parity, ABI and canaries.
- Sixteen older null-context/initial-selection fixture cases are replaced by the fuller ownership matrix. The remaining draw cases are retained.
- **5,548 cumulative checks** and **72,212 historical checks** passed on the written candidate. [Evidence](firmware/artwork-gdi-guards-development.json), [all members](firmware/artwork-gdi-guards-members.json), [historical checks](firmware/artwork-gdi-guards-retained.json).
- [Complete builder](../tools/build_artwork_gdi_guards_development.py) starts from all **1,918 MAX04 members**, reconstructs preceding candidates and verifies written files.
- [Historical runner](../tools/verify_artwork_gdi_guards_retained.py) preserves pinned sources and cases. It adapts only the candidate pixel-comparison entry and the two native dispatch entry ranges in isolated functions.
- [Refusal tests](../tools/test_artwork_gdi_guards.py) cover wrong binary, incomplete/extra members, input/output overlap and existing output.
- Input MgrUSB SHA256: `17429970a90f6286b5850cbb9cb61b6e07d219c003beb748f70f5d4ee5cf4fa4`.
- Candidate MgrUSB SHA256: `63ed1347b94e101bfd90d2fc37e7dbc4cb8ed5d5f8dce04715e9e56592048a32`.

## Limits

Mutex acquisition and DC deletion succeed in the fixtures. Native GDI cleanup failures, decoder execution/pending polling, shared readers, concurrency, hardware rendering and performance remain unverified. A cleanup attempt is not proof of successful native resource release. No LGU, version bump or measured speed improvement is included.
