# iPhone Bluetooth cover-art final-packet fix

This is an **unreleased patch recipe**, contributed by
[Emanuel / emstoica](https://github.com/emstoica) in
[PR #60](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/pull/60).
His original implementation and reverse engineering were AI-assisted (Claude
Code); his Spotify/Apple Music results were reported from a human test in a car.
Maintainer changes make the recipe portable and verify the actual patched PE
bytes. These are separate evidence sources, not a new maintainer car test.

The public MAX31 download is unchanged. This PR adds no firmware binary and
does not create a release. A later release still follows the maintainer's
[complete-package checklist](releases.md).

## Input and output pins

The recipe accepts only the exact published **7.0.6.MAX31** upgrade.lgu:
52,310,420 bytes, SHA-256
`521e9192c1dea4ae4d64d5346db0cc441c638e6156b7227af8a64eac162979b3`.

| Module | Bytes | SHA-256 |
| --- | --- | --- |
| Original Blue.exe | 1,963,008 | `8dfb6f7c3be0bdf2c2f6e15f19e5cd44712ca508d1f01d43b0fb4d5829b492a0` |
| Patched Blue.exe | 1,963,008 | `e6d63ab65a0c06a2da0a14cfec60f9e98cd2db134b9dd84c2d7942bfbf0890db` |

All **1,920 members** are retained. Only Blue.exe changes, plus Version_Info.txt
if an explicit new label is supplied. AppMain, native display layout, decoder
size, retry scheduling, boot/recovery, updater, MCU and navigation are unchanged.

## Cause and exact native change

The contributor reports that iPhone transfers completed their handshake and
first packet, but the final smaller packet was rejected. The GET validator
insisted on an End-of-Body header and exact/repeated declared-Length agreement.
The recipe replaces three rejecting branches with NOPs in both copies:

| First / active instrumented copy VA | Original branch | Relaxed requirement |
| --- | --- | --- |
| `0x24a2b4` / `0x31f8b4` | `bne t0,s5` | Repeated Length must equal the first |
| `0x24a2e4` / `0x31f8e4` | `beqz t0` | Final response must contain End-of-Body (`0x49`) |
| `0x24a2fc` / `0x31f8fc` | `bne s4,s5` | Collected bytes must exactly equal declared Length |

The original instruction words and input/output module hashes are checked.
Only these six words and the PE checksum change. No new instructions containing
absolute addresses, imports, allocation or code caves are added; existing base
relocations and unwind metadata remain byte-identical.

Packet/header bounds, connection identity, accepted response opcodes, buffer
capacity, nonempty result and the existing image decoder remain in place.
This is tolerant final-packet handling, not a change to the image size requested
from the phone. The fixture packet variations are synthetic; they do not by
themselves establish which exact variation appeared in each real iPhone log.

## Reproduce and verify

Use Python 3.12 or newer. From any checkout path, including Windows:

```console
python -m pip install -r tools/requirements-cover.txt
python -m unittest discover -s tools -p test_cover_package.py
python tools/verify_cover_patches.py --prepare-input .inputs/cover/MAX31.lgu
python tools/patch_cover_final_packet.py .inputs/cover/MAX31.lgu build/cover/candidate.lgu --version 7.0.6.COVERTEST
python tools/verify_cover_patches.py .inputs/cover/MAX31.lgu build/cover/candidate.lgu --version 7.0.6.COVERTEST --report build/cover/verification.json
```

`--prepare-input` downloads only the pinned public MAX31 file and checks its
hash. Existing differing inputs and output files are preserved. `COVERTEST` is
an offline verification label, **not a published release or installation
recommendation**. Maintainers choose a proper new version when building a release.
If `--version` is omitted from both commands, the original MAX31 label is kept.

ZIP names are compared using canonical separators while their raw stored names
and unchanged compressed/encrypted members are retained during repacking.
Compression may differ across Python/zlib platforms; verification checks every
member's expected size/hash and ZIP CRC, the LGU header and payload CRC, not an
intermediate platform-specific container hash. The official baseline and the
patched module are still checked against exact immutable hashes.

## Verification and remaining device work

- Nine portability/input-guard tests cover Windows/raw ZIP spellings, exact
  retention of untouched encrypted members, absent replacements, duplicate or
  unsafe names, CRC corruption, label limits and existing-output preservation.
- All 1,920 candidate members must match the MAX31 manifest, with only the
  documented Blue.exe/new-label changes permitted. LGU/ZIP integrity and the
  exact PE output/checksum are checked.
- Six negative mutations independently omit each instruction replacement;
  the verifier must reject each even after recalculating its PE checksum.
- **20 packet cases** execute actual bytes from the baseline and patched active
  GET clone at its preferred base. They cover accepted
  final-packet variations and retained identity, opcode, malformed-header,
  empty-result and size rejection, with context/body guards and ABI checks.
  No replacement GET assembly is generated by the verifier.
- Three relocation-preservation checks compare the baseline and candidate at
  the preferred and two alternate bases: only the same six words/checksum may
  differ. This is equivalence, **not complete rebased execution proof**.
- CI runs the complete recipe/verifier on Linux Python 3.12 and Windows Python
  3.14.2, in addition to existing repository/release checks.

The contributor reports iPhone covers working with Spotify and Apple Music.
The intermittent missing cover after skipping a track remains **unresolved**.
Other iPhones/apps and the maintainer's car need testing; offline native-byte
execution does not run Windows CE, its loader, radio or Bluetooth hardware.

The expanded review found that MAX31's existing active GET clone has an
unrelocated call to its HEADER helper. Whole-clone execution at an alternate
base therefore remains unverified/unsupported by these fixtures for both the
baseline and candidate. This inherited limitation is unchanged and requires a
separate native relocation fix; it is not hidden by claiming alternate-base
packet tests passed.

## Deferred display/retry experiment

The original PR also tested rounded corners, a 278x278 decoded bitmap and a
retry. The contributor reported working corners, no visible sharpness gain,
and no solution to intermittent missing covers from the retry. These changes
are omitted from the focused merge. The original commit
[`b4b55fc`](https://github.com/emstoica/MediaNav-to-Evolution-Upgrade/commit/b4b55fc04e6a2e37b9469623a17f8729c49bf6a0)
preserves that research. Any later display/retry PR must add appropriate native
relocations/unwind records and test actual written/rebased bytes separately.
