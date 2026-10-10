# USB text and album-cover consumers

The [complete development payload](../build/usb-status-consumers-development-01/README.md) retains all 1,918 files and previous fixes from startup-failure-development-01. AppMain and MgrUSB change together. No LGU, version bump or release is created.

## Resulting behavior

The two identified USB title consumers now work from terminated local copies. The top-level title display copies its 260-WCHAR slot and terminates position 259 before scanning or removing `.MP3`/`.WMA`. The USB dialog's existing title/artist formatter receives a full 3,670-byte local status copy, with its title/artist buffers terminated at their last WCHAR. The other five regions of the same size are also terminated only in that private copy; two remain unidentified and are unused by this formatter. Normal title formatting, extension handling, artist formatting and display-mode selection are preserved. Failed lock acquisition or a NULL source skips that update.

Cover access is coordinated with the named mutex `MAXmade_USB_Status_v1` in both executables:

- The existing MgrUSB publication wrapper locks around the original shared-memory write.
- Each of the four original cover-deletion callers passes its real local cover-field address. While holding the lock, deletion clears the matching local and published handle before calling DeleteObject. Redundant unlocked clearing stores are removed.
- Installation of a replacement cover also locks around both packed stores, including the original store pair that straddled a function call.
- AppMain acquires the cover and queries/assigns its widget under the same lock. The resource-manager failure path clears the widget without showing a modal warning while holding the lock.
- Both widget paint paths lock for the tracked USB cover, verify the cached handle against the current published/default handle, and check GetObject again before drawing. A stale or invalid handle is skipped. The lock remains held until the original drawing routine restores its selected GDI object and leaves its existing DC critical section.

This prevents the reproduced mixed packed handle and the demonstrated use of a deleted cached cover in these paths. It does not transfer bitmap ownership to AppMain or allocate bitmap clones. Other widgets use a short leaf dispatch to their original drawing implementation, without mutex APIs. Widget construction clears tracking if its address is reused. The original USB dialog constructor call sites all publish through the same AppMain singleton, `188294`.

UI acquisition uses a zero-duration wait, so a busy publisher causes a skipped UI update instead of a timed wait. MgrUSB requests an indefinite wait while publishing, installing or deleting. Abandoned-mutex acquisition is accepted as ownership. Failed creation/acquisition prevents the protected operation. A failed DeleteObject leaves the OS handle alive but unpublished; native teardown and allocation-failure leak behavior remain to be tested.

## Binary changes

AppMain SHA256: `a3be9c0512fc883c22868da0aa62fba48c0c095e9cef2a2c66279043bbf228b7`, 2,010,112 bytes.

MgrUSB SHA256: `cac3d40f5d54de681b1aad8c99fe79df5b430d3ee3d668616b63970f02ca1a2c`, 249,344 bytes.

Each executable gains an RX code/metadata section and an RW import/state section. Existing imports/IAT addresses, section headers, entry point, resources and original data bytes are preserved. A further COREDLL descriptor imports CreateMutexW/ReleaseMutex, ordinals 555/556 verified against the extracted CE ROM. Original headers point to cumulative exception and relocation tables in the new section.

AppMain redirects `1def8`, `4dcc8`, `138860`, `138ba4` and the leaf widget constructor `1386e8`. The cover-update block `4e268..4e2e8` calls the new protected setter. The original dialog formatter and drawing routines are copied with their existing instructions and relocations; intra-function absolute jumps follow the copies. The formatter retains its original GS-cookie handler/data because its stack layout and cookie offsets are unchanged. The paint dispatch and its framed protected path have separate exception rows.

MgrUSB redirects `24094`, changes the four deletion calls `19538`, `1a588`, `1a634`, `1adac` and their delay slots, removes six redundant packed zero stores and replaces the installation sequence `1a590..1a59c`. Existing unrelated code remains exact. Every edit in the original file prefix is reversible to its exact input.

## Verification

377 new behavior/structure checks cover original display parity, every title length 0–259, missing terminators, title/artist formatting, mutex success/abandonment/failure, acquisition interleaving, both paint paths, invalid/dead handles, missing resources, default covers, widget reuse and delete/install/publication. Preferred and three aligned alternate load bases are checked. The actual new helpers, original formatter, copied drawing routines and original publication code execute as MIPS instructions; CE/GDI calls and scheduling use explicit fixtures.

An [additional 32-case caller audit](firmware/usb-cover-callers-audit.json) checks the complete original destructor/clear/reset functions, the original artwork replacement/publication tail, DeleteObject failure, strict title-source read bounds, NULL sources and both unlocked non-USB drawing paths. It pins [its tool](../tools/audit_usb_cover_callers.py) and both output hashes separately.

The build reruns 72,494 earlier USB behavior checks covering save, repeat/shuffle, folders, sorting, WMA, artwork, playlist, encoding and persistence. Earlier API fixtures are extended for the new mutex without editing the hash-pinned old tools. Three previous build-specific structural checks are replaced by this build's structural validation. AppMain startup (157), mapping (124), relocated copy/text (96), separate relocation instruction checks (1,872), IPC (96), Bluetooth pairing (824), touch (117), Hebrew mixed text (140) and Arabic mixed text (172 plus two NULL cases/benchmarks) are also rerun. The manifest and [main proof](firmware/usb-status-consumers-development.json) record exact results and tool/member hashes.

## Limits and continuation

This is development evidence, not a native CE/GDI/loader or hardware test. GDI process-handle semantics, real scheduling, process teardown, loader/unwind behavior, stack headroom and device timing remain unverified. No native speed improvement is claimed. The dialog formatter uses about 6.3 KiB of combined snapshot/formatter frames, without heap allocation.

Other direct scalar/status readers still read the shared mapping without this lock. Local producer metadata is still assembled outside the publication lock; this work does not make every field mutation or all USB state globally atomic. The source text copy is bounded but copies entire slots; reducing that work is a separate optimization after the ownership behavior is validated. The shared-memory layout, message IDs, notification flow and 500ms status timer remain unchanged.

All older staging, proofs and tools remain available. The published MAX03 LGU and public guide are unchanged.
