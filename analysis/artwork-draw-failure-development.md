# Album-art draw failure

- **Stability:** failed image draws use the existing no-artwork fallback.
- **Cleanup:** restore the previous selected object, delete the unpublished temporary bitmap, then run the original DC and COM cleanup.
- **Scope:** complete MAX04-based development payload; only MgrUSB changes. No LGU or version bump.

## Native defect

`CPlayControl`'s renderer at `1a318..1a60c` calls IImage's Draw slot at `1a498`. The original owner discards its signed HRESULT, restores the selected object, runs pixel cleanup and publishes the new bitmap. A failed decoder can therefore replace an existing cover with a bitmap containing no successfully drawn image.

[Read-only diagnosis](../tools/inspect_artwork_render_failures.py) executes the actual renderer, pixel helper, bitmap deletion wrapper and publication wrapper. It reproduces this behavior in both [MAX04](firmware/artwork-render-failures-max04.json) and the [PR33 candidate](firmware/artwork-render-failures-pr33.json): 80 cases each, four load addresses and both empty/existing artwork state. Factory, image, DC, DIB, selection, information and Draw responses are explicit fixtures.

## Change

[Patch](../tools/patch_artwork_draw_failure.py) changes only `1a4a0..1a540` and the existing relocation records. It retains Draw's result in the already-saved `s3` register across SelectObject. Negative results skip pixel processing and delete the temporary bitmap; `s5=0` then reaches the original no-artwork publication path. Nonnegative results follow the existing renderer behavior.

The original frame, exception table, imports, section sizes, image/factory releases, previous-artwork deletion, shared-state publication and command `67` notification remain in place. There is no new allocation, decoder retry, wait, interface or exception row.

## Verification

- [Focused verifier](../tools/verify_artwork_draw_failure.py): 129 written-instruction cases, including signed HRESULT boundaries, normal-path parity, four load addresses, old-cover replacement, ABI and buffer canaries.
- **4,018 cumulative checks** and **72,212 historical checks** passed on the exact candidate. [Written-byte evidence](firmware/artwork-draw-failure-development.json), [complete member manifest](firmware/artwork-draw-failure-members.json), [historical evidence](firmware/artwork-draw-failure-retained.json).
- [Complete builder](../tools/build_artwork_draw_failure_development.py): reconstructs every preceding candidate from the full MAX04 payload and verifies all 1,918 written members.
- [Input refusal tests](../tools/test_artwork_draw_failure.py): mismatched binary, missing/extra members, directory overlap and existing output.
- Input MgrUSB SHA256: `390c9858832add05a16b3a0760383080f1ce9bfc34359c8538ddb9f7d00557c8`.
- Candidate MgrUSB SHA256: `17429970a90f6286b5850cbb9cb61b6e07d219c003beb748f70f5d4ee5cf4fa4`.

## Limits and next work

COM/GDI calls and decoder pixels are fixtures. Native decoding, graphics resource exhaustion, DeleteObject failure, mutex contention, shared readers and on-unit rendering remain unverified. No speed improvement is claimed.

The diagnosis also shows unchecked compatible-DC and bitmap-selection failures. These remain separate follow-up work. The unused GetImageInfo result is not removed: decoder side effects need inspection before treating that query as redundant. Native Draw pending polling is unchanged.
