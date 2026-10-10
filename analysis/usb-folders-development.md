# USB next/previous folder traversal

The verified [full development payload](../build/usb-folders-development-01/README.md) carries all 1,918 previous paths and every earlier improvement. Only MgrUSB changes versus usb-sorting-development-01; the other 1,917 files are identical. No LGU, version change, release or native execution.

The intended benefit is quicker switching between USB music folders, plus bounded behavior for empty or inconsistent lists. The linear order-table lookup remains; it no longer requests a timed wait for every entry.

## Confirmed defects and behavior

The original next/previous functions at `14720` and `14884` read the signed order-table count at CFileMgr+2750. Their count<=0 branch skips the first scan but still enters candidate selection and reads a table slot. The original-byte fixture detects that read with a zero-length table. The replacement returns zero before reading table entries for an empty/invalid catalog.

The backwards function compares the **requested folder ID with a table index**, rather than the candidate folder ID. With order `[7,9]` and no tracks, current folder 7 can loop indefinitely. With order `[8,7,1]`, only folder 8 playable and current folder 1, it stops at index 1 and returns folder 1 without reaching folder 8. Both defects are reproduced on the old bytes. The replacement compares IDs and bounds candidate selection to one full cycle.

The original forward function can also keep circling when the requested ID is absent and no folder is playable. The new search is bounded whether the current ID exists or not. It retains the existing unknown-current starting position zero and the original direction/wraparound. When no playable folder is found it returns the requested current ID; cancellation or invalid catalog state returns zero, preserving the existing cancellation ABI.

IDs 0..4999 are bounded before record access. The original -1-to-record-zero convention is retained; other negative or oversized IDs are skipped. A playable folder must have 1..5000 tracks. Null buffers and the original dummy-buffer pointer are rejected. This does not repair every other legacy folder getter.

## Yielding and catalog checks

The iterator uses the retained yield helper: Sleep(1) once per 32 visited entries, Sleep(0) otherwise. Its tick count is local to each call and spans both lookup and candidate-selection phases. Cancellation is checked before and after every yield; count and buffer pointer must still match their initial snapshot before a table read proceeds.

| 5,000-folder fixture, same selected folder | Old timed waits | New timed waits | New Sleep(0) calls |
| --- | ---: | ---: | ---: |
| Next, current 4999, first playable 1 | 5,002 | 157 | 4,845 |
| Previous, current 4999, first playable 1 | 9,998 | 313 | 9,685 |

These are about 97% fewer **requested timed waits**, not measured milliseconds or a device speedup. Added bounds and cancellation/snapshot checks increase interpreted instruction work: next 80,093->350,226; previous 229,966->804,860. Folder records inspected remain two and 4,998 respectively. This change trades extra checks for far fewer deliberate timed waits, rather than removing the linear scan.

An absent current ID with 5,000 nonplayable entries is bounded to 10,000 visits: one lookup phase and one selection phase. Native CE scheduling, responsiveness and wall-clock timing still need testing.

Checks around yields reject count/pointer changes and observed cancellation. They do not lock the catalog or guarantee a coherent snapshot if contents change while those two values stay equal, or between a final check and a read. No general concurrency or lifetime safety claim.

## Written-byte verification

**1,224 new + 4,972 retained cases pass.** The [proof](firmware/usb-folders-development.json) and [manifest](../build/usb-folders-development-01/manifest.json) record exact changes, input/tool/proof hashes, all output member hashes and fixture results. MgrUSB SHA256: `f57cbfa38453cfac5c25a0d8db4376da5fa46a9ed838caa05985f5840512a6ba`.

The new checks comprise 1,113 traversal/parity cases, 90 cancellation/invalid-input cases, three original-defect reproductions, five caller integrations, 12 maximum-size/relocation cases and one combined structural check. Previous sorting checks rerun current behavior using the recorded original baseline; the other retained suites execute on the written output.

Two helpers occupy previously zero code at `3ca00` (440 bytes) and `3cd00` (168 bytes), before the retained ASF helper at `3ce00`. Both original entries tail-redirect without creating their former stack frames. Sections, imports and entry point stay unchanged; combined pdata/relocations retain earlier entries and add both new helper rows. Three alternate load addresses and all exception rows are checked.

Fixtures cover cyclic order, noncontiguous IDs, duplicate IDs, root convention, unknown current, all-empty folders, missing/oversized/null catalogs, invalid IDs/counts, cancellation at every check and catalog replacement at each yield. They execute the original previous-track selector, the next-track call site and the rewritten complete shuffle builder through the actual new iterator, including cancellation propagation.

The retained sorting tests rerun ordering, table parsing and catalog integration, assert all sort code unchanged, and rerun the current 256-song workload against its verified previous result. Its original baseline is carried from the hash-pinned previous manifest. WMA, shuffle, artwork, playlists, encodings, storage and resume suites run again on the written executable.

Build tools: `tools/patch_usb_folders.py`, `tools/verify_usb_folders.py`, `tools/build_usb_folders_development.py`. The builder preserves old staging and the public guide/LGU, verifies previous tool/proof/member hashes and reads back every output member. Device loading/unwind, scheduling, real storage/installation and timing remain unverified.

Next bounded reliability candidate: validate saved repeat/shuffle values before restoring playback settings. Save-error feedback and shared playback-status snapshot ownership remain separate open work.
