# Album artwork and playlist loading: fixes and less work

9 October 2026. Max asks for more fixes and performance improvements. This continuation repairs album-art handling and playlist line loading, retaining all earlier work in [full development staging](../build/artwork-playlist-development-01/README.md). No LGU, release, version bump, GitHub publication or native firmware execution.

**All 1,918 previous paths remain present.** Only MgrUSB changes versus usb-reliability-development-01; the other 1,917 files are byte-identical. Previous Bluetooth/audio/navigation, English UI, installer, touch, menu, resume, metadata and playlist repairs remain included. Older builds and published MAX03 remain unchanged.

## Improvements

| Area | Result in development |
| --- | --- |
| Embedded album covers | MIME and description searches stay inside the ID3 frame; real picture bytes are copied, excluding encoded descriptions. Ordinary APIC and older PIC layouts are handled separately. |
| Corrupt or oversized cover tags | Missing terminators, invalid encodings/types, absent image buffers, empty images and payloads larger than the existing 8 MiB image buffer are rejected. A later invalid frame does not overwrite previously accepted artwork. |
| Image decoder input | Uses the actual image length, instead of exposing the entire 8 MiB allocation as stream data. |
| Bitmap cleanup | Correct row padding for the 24-bpp DIB; three-byte changes are stored directly instead of calling memset for each matching pixel. |
| Repeated metadata work | Removes a 3,652-byte metadata copy made solely to read the artwork length. |
| Long playlist lines | Consume and skip an oversized physical line; its later chunks cannot become independent song paths. |
| UTF8 playlists | A leading complete UTF8 BOM is removed before the existing UTF8 conversion and M3U/PLS/WPL parsing. |

## Artwork parsing

The old `17ef4..18038` path used unbounded strlen for MIME, assumed an empty single-byte description, and copied the remaining count without checking the 8 MiB destination capacity. New helper `3d800` accepts the existing output tag object, frame bytes, frame length, version and original source tag object's image allocation. The buffer-owner pointer is retained from the original caller, rather than inferred from the output object.

APIC consumes the encoding byte, bounded MIME, picture-type byte and a complete description terminator. Latin1/UTF8 use a one-byte terminator; UTF16/UTF16BE scan aligned two-byte units. PIC consumes its three-byte format field separately. Known format codes match previous jpg/jpeg/png/bmp/gif values. Unknown image MIME/PIC types retain code zero so registered native signature decoders can still inspect them. External linked-picture forms are skipped. The helper publishes format, byte count and artwork flag only after a valid bounded copy.

Frame flag/decompression exclusions from earlier work remain. The helper is a contained frame parser, not a full validator of encoded descriptions or compressed image contents. Format references: [ID3v2.4 APIC](https://id3.org/id3v2.4.0-frames) and [ID3v2.2 PIC](https://id3.org/id3v2-00).

At `1a38c`, direct access to CPlayControl's artwork count replaces copying all `0xe44 = 3,652` metadata bytes onto the stack. Zero or oversized counts skip decoder creation. `1a3bc` keeps this validated count as CreateImageFromBuffer's byte length. This does not shrink or remove the existing pool allocation; factory lifetime and decoder selection remain native.

## Bitmap correctness and performance

The old loop advanced `3*width+2` bytes per row. It matched the DIB layout only when width modulo four was two. The replacement at `3c800` computes padding as `(-3*width)&3`, leaving padding bytes untouched and retaining the original B=8..15, G<4, R<8 blackening rule. The 24-bpp row layout follows [Microsoft's DWORD-aligned RGB stride formula](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader#calculating-surface-stride).

The replacement caches width and padding, uses direct byte stores and does not call memset per pixel. A before/after test of identical **278 × 3** pixel bytes produces exactly the same result:

| Offline measure | Before | After |
| --- | ---: | ---: |
| Interpreted MIPS instructions | 14,204 | 10,995 |
| Per-pixel memset calls | 239 | 0 |

That is about **23% fewer interpreted instructions in this test loop**. It is not a 23% native speed claim: timings of the CRT, CPU, imaging decoder, UI and full track change have not been measured. The removed 3,652-byte copy is checked through the actual whole rendering function with explicit GDI/COM fixtures.

## Playlist line handling

All six direct calls to `15e4c` are inventoried and redirected to `3ea00`, covering the initial and next-line paths in M3U, PLS and WPL. Capacity is checked at 2..260 bytes. The existing caller buffer remains bounded; no unbounded line allocation is added.

A full buffer without LF uses a two-byte lookahead to preserve a valid 259-byte line followed by EOF, LF or CRLF. If more content follows, the reader drains the rest of that physical line in bounded chunks and continues with the next line. A CRT read error clears the result instead of pretending it was EOF. The existing COREDLL import descriptor gains **feof ordinal 1125 and ferror ordinal 1126**, verified against the extracted ROM exports. Invalid capacity never reaches fgets.

Terminal CR/LF trimming and the existing UTF8/path/suffix/attribute rules remain. Complete UTF8 BOMs at the beginning of returned lines are removed; no per-file first-line state is introduced. Playlist sorting, duplicate policy, 999-entry limit, UTF16/ANSI fallback and XML/entity support are unchanged. Embedded NULs and native CE CRT text-mode translation remain outside the fixture proof. Draining a very large line still requires reading it; no native cancellation or elapsed-time bound is claimed.

## Verification and cumulative build

- Input MgrUSB SHA256: `9b2a87dbbef6e9e6d11fa66bd92a687331e7b5fd51104e5588dad157cf623518`.
- Output MgrUSB SHA256: `491c49894eb6f49e0f4dda55c588203d957f1746809a726de368af2d52cdebf9`.
- [Written-byte evidence](firmware/artwork-playlist-development.json), [full manifest](../build/artwork-playlist-development-01/manifest.json).
- [Construction](../tools/patch_artwork_playlist.py), [verifier](../tools/verify_artwork_playlist.py), [full builder](../tools/build_artwork_playlist_development.py).

**376 new written-byte cases:** 157 cover/frame cases, 137 bitmap cases, 73 line/capacity/error/relocation cases, six whole-stream parser cases and three rendering cases. Bitmap fixtures cover all padding classes, widths up to 800, multiple rows, unchanged padding and guard bytes. Artwork includes encoded descriptions, malformed prefixes and real ID3v2.2/2.3/2.4 dispatch followed by title decoding. Actual M3U/PLS/WPL readers each accept the normal and Unicode tracks around a rejected oversized line, with and without BOM.

**728 retained cases** rerun encoding/cache/parser, persistence/interruption, frame bounds, paths, attributes, suffixes, copies, prior playlist-parser fixtures, relocation and resume/rematch on the written cumulative executable. Structural checks are additional. Native codecs, COM and filesystems are replaced by declared fixtures; the image bytes are synthetic, not native-decoded photographs.

No extra PE sections or changed entry point. Three exception rows use previously verified zero code space; earlier helper instructions remain byte-identical. Updated exception/import/relocation tables are checked at three alternate bases. Undoing all reviewed code/data edits and two directory-size fields restores the exact input file. Full payload readback checks every path, size and hash and verifies previous tool/proof hashes and the unchanged published LGU.

## Next useful work

WMA/ASF descriptor bounds and exact read counts remain concrete bugs to fix. Shuffle cancellation can publish an incomplete list and needs caller propagation checks. For wider performance gains, trace repeated directory scans, sorting and playback-status updates before changing them; boot/source-switch sleeps still need native readiness/timing evidence. Native CE loader, CRT EOF/text behavior, imaging/display, storage recovery and the carried-forward installer remain required before a release.
