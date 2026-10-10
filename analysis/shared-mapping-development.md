# Shared-memory initialization and AppMain loading

The [complete development build](../build/shared-mapping-development-01/README.md) retains all 1,918 previous paths and improvements. Only AppMain changes versus usb-save-feedback-development-01. It corrects two shared-mapping failure checks and rebuilds relocation entries for the earlier Bluetooth/UI edits. No LGU, version bump, release or publication.

## Mapping failures

AppMain's complete initializer is `13234..13d28`. After opening the USB status view, instruction `135e4` loads the iPod pointer at object `+ac` and tests that instead of the USB result. The earlier iPod mapping has already succeeded on this path. A failed USB view is therefore accepted, its handle stays open, the USB pointer remains zero, and initialization continues.

Instruction `135e4` now copies the actual `MapViewOfFile` result from `v0` into `t0`. The existing branch and delay-slot store publish the pointer at `+c4`; a zero result takes the original warning, closes the USB handle, clears it and returns failure. Healthy behavior remains identical.

The same function has a second defect for the DAB EPG view: `13b3c` checks its nonzero mapping handle at `+f8`, rather than the view result. Its otherwise unreachable cleanup at `13b54` also passes zero to `CloseHandle`. These instructions now check the result and load the real handle. Both fixes retain existing English warnings and failure-return conventions. A fixture cleanup failure cannot turn the failed mapping into a successful return; there is no new cleanup retry or durability claim.

**The outer startup caller at `14111c` ignores the initializer's return.** It still publishes the object and continues. This work repairs error detection, immediate handle cleanup and reporting inside the initializer; it does not make every failed-startup path safe, provide automatic recovery or prove prevention of a unit crash. USB title/status consumers still dereference the shared pointer directly. Complete startup failure handling remains an important next task.

## Inherited relocation defect

The alternate-address test initially rejected AppMain's existing relocation table: 28 jump relocation entries point at replacement instructions that are no longer jumps. Nineteen HIGHADJ entries inside prior replacement spans likewise point at instructions that are no longer `lui`. Other entries refer to removed/replaced address loads, and new calls/address loads have no corresponding entries. The untouched 7.0.5.MD reference has neither of the first two invalid-entry classes.

This defect was already present in the previous development AppMain, including earlier Bluetooth replacements and both text scans. At the preferred image base these instructions remain as intended. When a loader applies a nonzero relocation delta, obsolete entries can corrupt a branch, object offset, constant or register operation. This is a byte-level defect reproduction, not an observed explanation for any reported vehicle failure.

The reviewed replacement spans are reconstructed from the earlier pairing, ACK, safe-copy, Arabic-scan and media-responsiveness recipes. Inside those 36 spans, 99 inherited relocation records are replaced with 50 appropriate records: 26 direct-call relocations, six HIGHADJ records with correct companions and 18 low-address records. All records outside these spans are retained exactly. Relocation blocks are rebuilt within their existing space, with only the directory size updated. No section, import, resource, exception row or entry point changes. Apart from the three mapping-check/cleanup instructions, **every existing code byte is unchanged**.

Image references are distinguished from protocol values such as `0x1010804`, registry roots, record offsets and loop limits. Multiple low references sharing one high register are validated at 64KiB-aligned alternate image bases. Arbitrary unaligned rebasing of those earlier instruction sequences is not supported or claimed. The mapping initializer also receives its own additional `+1000` fixture, independently of the patched Bluetooth paths.

Input AppMain SHA256: `236ef346d273b3529a3318b17219b8135eb8bb5184bd34178337e8a72df5902c`.

Written output SHA256: `1ff9fd6c5d4029745182da69af453eef43d27b94565ca3fa567021055a49c589`.

## Verification

The [main proof](firmware/shared-mapping-development.json) and [manifest](../build/shared-mapping-development-01/manifest.json) record 221 behavior/structure cases and 1,872 relocation instruction checks:

- 124 initializer cases execute the complete actual MIPS function, including both original failure reproductions, create/view failure at all 14 mappings, healthy parity with low/high fixture pointers, API clobbering, ABI/stack guards, four load addresses and cleanup-error return preservation.
- 96 cases execute the actual eight-record copy and Arabic/Hebrew text helpers at the preferred base and three aligned alternate bases: `+10000`, `+120000` and `+500000`.
- One structural check reverses the exact recipe to recover every input byte, checks metadata retention and verifies relocation preservation outside prior edits.
- 1,872 checks compare every instruction in the reviewed spans after three aligned rebases: calls and image addresses move correctly; unrelated instructions remain unchanged.

An additional [96-case IPC audit](firmware/appmain-relocation-runtime-audit.json), produced by [this tool](../tools/audit_appmain_relocation_runtime.py), executes the full AppMain send wrapper at those four bases. It covers normal sends, OS failure, timeout, successful retry, disabled state and invalid commands, for both message-ID kinds and both return modes. Global/import address rebasing, caller-saved clobbering, unchanged retry IDs, receiver ACK propagation and register/stack preservation pass. The window lookup and OS sends are explicit fixtures. The audit pins the written AppMain hash and its own tool hash.

Retained checks run against the written files: 824 matched Bluetooth cases, 117 touch/seek cases, 140 mixed Hebrew cases and 172 mixed Arabic cases, plus existing NULL/benchmark checks. MgrUSB is byte-identical to the preceding build; its hash-pinned 72,497-case proof and nine state cases remain applicable and were **not rerun**. All 1,917 other payload files are byte-identical, including Blue, navigation, updater, DBoot and version info. The previous staging/tools/proofs and public MAX03 LGU are unchanged.

Native Windows CE loading, physical handle failure behavior, hardware playback and full installation remain unverified. Relocation interpretation is not a substitute for a native loader test.

## Shared-status ownership remains open

The investigation also follows the 3,670-byte USB status mapping through MgrUSB's embedded writer (`24094 -> 23c44`) to AppMain's direct title/status readers (`1df24..1df38`, `4cfa4..4cfb4`). The writer copies the entire structure without acquiring the creation mutex; the readers do not acquire that mutex around these reads. Merely locking the writer would not make those consumers read coherent snapshots.

No new writer lock, cache, generation field or status ABI change is introduced. A coordinated snapshot solution must include the readers, notification order and album-cover handle lifetime. This build does not claim to repair that concurrency problem or shorten the 500ms update timer. First resolve the outer initialization-failure policy, then continue with coherent snapshots and cover ownership.

Build tools: `tools/patch_shared_mapping_checks.py`, `tools/verify_shared_mapping_checks.py`, `tools/build_shared_mapping_development.py`. The separate runtime audit does not overwrite the main build proof.
