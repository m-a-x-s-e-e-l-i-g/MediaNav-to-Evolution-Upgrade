# Field-sized USB metadata snapshots

- **Efficiency:** normal and resume paths copy the required flag or text field, instead of the entire 3,652-byte tag object.
- **Compatibility:** title, artist, album, fallback names, logs, parser calls and snapshot order are retained.
- **Scope:** complete MAX04-based development payload; only MgrUSB changes. Device speed is not measured.

## Change

The native metadata owners at `19d3c` and `1a0d4` each contain seven whole-object copy sites. A site is used to read one DWORD of flags, one UTF-16 text field, or the title shown in a log. Copying the raw text caches, cached path and other unused fields adds work without contributing to those consumers.

[Patch](../tools/patch_usb_metadata_copies.py) changes 14 existing 16-byte argument-setup blocks. Each call still uses the same `memcpy`, at the same point in the control flow. Its destination and source select the consumed field; its length is four bytes for flags or 520 bytes for a complete text slot. Subsequent status copies keep their existing 518-byte lengths and final terminators.

The title log gets its own snapshot as before. Flags are read separately at their original points. This preserves updates between snapshots; it does not replace the sequence with a single cached tag.

| Path, in either owner | Previous snapshot bytes | New snapshot bytes |
| --- | ---: | ---: |
| Title, album and artist present | 25,564 | 2,092 |
| All three absent | 10,956 | 12 |

These counts cover metadata snapshots only. Status copies, file parsing, logging and buffer clearing remain separate work. The all-present path copies **23,472 fewer bytes**; this is not a measured timing improvement.

Call instructions and their existing MIPS relocation entries are unchanged. Stack frames, imports, sections, exception records, buffer capacities and artwork allocation are unchanged. Undoing the declared edits reproduces the exact previous candidate.

## Verification

- [Focused verifier](../tools/verify_usb_metadata_copies.py): **681 checks** execute the full normal/resume owners at four load addresses.
- All flag combinations, empty/long/Unicode text, filename fallbacks, supported/unsupported media types and poisoned stack fixtures are covered.
- Outputs have independent expected-value checks and are compared with the previous candidate. Logs, parser arguments, return values, tag contents, saved registers and stack canaries are checked.
- An explicit logger fixture changes metadata after logging; later snapshots must observe those changes in both candidates.
- [Complete builder](../tools/build_usb_metadata_copies_development.py) retains all **1,918 MAX04 members**, checks every written path/hash and reruns preceding playback/artwork checks.
- [Historical runner](../tools/verify_usb_metadata_copies_retained.py) preserves the original source/input pins and isolated graphics-entry adaptations.
- [Refusal tests](../tools/test_usb_metadata_copies.py) cover the wrong input, incomplete/extra members, directory overlap and existing output.
- Published results: [cumulative evidence](firmware/usb-metadata-copies-development.json), [complete member manifest](firmware/usb-metadata-copies-members.json), [historical checks](firmware/usb-metadata-copies-retained.json).
- **6,293 cumulative checks** and **72,212 historical checks** passed on the exact written candidate.
- Input MgrUSB SHA256: `f947c2d231b255019b95f17f57299dcaa6159bee0dd6242ecec52475258370b9`.
- Candidate MgrUSB SHA256: `7c1af7ce3d3a4c75dab75f4df7eb6fe1b5b016034f61f083678382b702ec0a71`.

## Limits

The parser, file manager, CRT string/copy functions and logger are explicit fixtures. Native Windows CE timing, scheduling, loader/unwind and device behavior remain unverified. Stack reservation and the 8-MiB artwork buffer are retained. No LGU or version bump is included.
