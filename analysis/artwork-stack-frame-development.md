# Compact album-art stack frame

- **Memory efficiency:** renderer stack reservation falls from **3,864 to 216 bytes**, removing **3,648 bytes** per invocation.
- **Compatibility:** rendering, graphics failure guards, ImageInfo, saved registers and stack-cookie protection are retained.
- **Scope:** full MAX04-based development payload; only MgrUSB changes. No measured process-RAM or speed claim.

## Why this space is unused

An earlier [artwork change](artwork-playlist-development.md) removed the 3,652-byte metadata copy that existed only to obtain the artwork length. Its large stack frame remained. The current renderer's complete stack-reference inventory shows a large unused gap between its small working buffers and ImageInfo/saved-register area.

[Patch](../tools/patch_artwork_stack_frame.py) changes **19 instruction immediates**: frame allocation/release, ImageInfo's stack offset, saved-register slots and the cookie load/store. It changes no opcode, branch, call target, section, import, relocation or exception-table entry. Input hash and the complete large-offset inventory are checked before editing.

The saved slots and ImageInfo retain their exact addresses relative to the caller's stack. ImageInfo remains eight-byte aligned and has 64 reserved bytes, including tail padding; this retains the [Windows CE ImageInfo layout](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452243(v=msdn.10)). Its end is the cookie slot, just as before.

| Live region | New stack offset | Bytes |
| --- | ---: | ---: |
| Outgoing arguments and interface/bitmap outputs | `00..27` | 40 |
| BITMAPINFOHEADER | `28..4f` | 40 |
| Rectangle | `58..67` | 16 |
| ImageInfo, with alignment/padding | `70..af` | 64 |
| Cookie | `b0..b3` | 4 |
| Saved registers and return address | `b8..d3` | 28 |

The original GS handler at `254e4`, handler-data cookie offset `-0x28`, prologue boundary and saved return-address location are unchanged. Neither the stack-frame change nor these tests prove native Windows CE unwinding.

## Verification

- [Focused verifier](../tools/verify_artwork_stack_frame.py): **45 checks** for full 64-byte ImageInfo writes, frame bounds, cookie adjacency, successful/failing APIs, four load addresses and the actual GS handler instructions.
- The GS checks accept a valid cookie and reach the actual failure branch for invalid values. They use a valid 16-bit fixture cookie; older equality-only cookie fixtures remain historical evidence.
- The previous stateful graphics matrix runs on the candidate with strict owner-frame bounds. Earlier playback and artwork cases are retained through isolated verifier functions.
- **5,602 cumulative checks** and **72,212 historical checks** passed on the exact written candidate. [Evidence](firmware/artwork-stack-frame-development.json), [complete member manifest](firmware/artwork-stack-frame-members.json), [historical checks](firmware/artwork-stack-frame-retained.json).
- [Complete builder](../tools/build_artwork_stack_frame_development.py): reconstruct preceding candidates from all **1,918 MAX04 members** and verify every written path/hash.
- [Historical runner](../tools/verify_artwork_stack_frame_retained.py) preserves previous source/input pins and the isolated graphics-entry adaptations.
- [Refusal tests](../tools/test_artwork_stack_frame.py): wrong binary, incomplete/extra members, directory overlap and existing output.
- Input MgrUSB SHA256: `63ed1347b94e101bfd90d2fc37e7dbc4cb8ed5d5f8dce04715e9e56592048a32`.
- Candidate MgrUSB SHA256: `f947c2d231b255019b95f17f57299dcaa6159bee0dd6242ecec52475258370b9`.

## Limits

Native loader/unwind, graphics/decoder behavior, hardware rendering and measured process memory remain unverified. COM/GDI outputs are explicit fixtures; actual GS instructions do not emulate the full OS exception dispatcher. The frame reserves fewer bytes, but committed stack pages, RAM usage, latency and stack-overflow incidents have not been measured. No LGU or version bump is included.
