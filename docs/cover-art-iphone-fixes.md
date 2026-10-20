# Bluetooth cover art: iPhone fix and display polish

Research note for two patch scripts that work on the published `upgrade.lgu`. This is not a release. A release is still packed by the maintainer with the pinned tools in [releases.md](releases.md). The scripts exist so the changes can be reproduced and reviewed.

Written with AI assistance (Claude, via Claude Code). Device results come from a human test in a car.

## Original modules

| Module | Bytes | SHA-256 (published package) |
| --- | --- | --- |
| `Blue.exe` | 1,963,008 | `8dfb6f7c3be0bdf2c2f6e15f19e5cd44712ca508d1f01d43b0fb4d5829b492a0` |
| `AppMain.exe` | 3,151,360 | `f42977f84a3f38fb020e85779504bd3e3b78b3ce387a03c0032e99cb4a305d0b` |

The published package is the 52,310,420-byte `upgrade.lgu` with SHA-256 `521e9192c1dea4ae4d64d5346db0cc441c638e6156b7227af8a64eac162979b3`.

| Step | `Blue.exe` SHA-256 | `AppMain.exe` SHA-256 |
| --- | --- | --- |
| After `patch_cover_final_packet.py` | `e6d63ab65a0c06a2da0a14cfec60f9e98cd2db134b9dd84c2d7942bfbf0890db` | unchanged |
| After `patch_cover_retry_and_corners.py` | `f46fd97342baf973c316f90be94643db6a4f17761649e49b71094a09d46babc0` | `2b7dee26f1dcd2636abab1cccc5153eb085963e0929e73f67395d8672b59c607` |

All other members are byte-identical to the published package. Addresses are virtual addresses in the module.

## 1. Final cover-art packet (`Blue.exe`)

**Reason.** Debug logs from an iPhone showed the OBEX handshake, cover handle and first 1,024-byte packet accepted, then every final packet rejected by the GET validator (`bt_cover_art_responses.py`, `GET_CODE`). No image was ever completed.

**Change.** Three branch-to-failed instructions become no-ops, in both copies of the validator (second copy is the debug-instrumented clone). Each address is hash-guarded on its original instruction word.

| Address (1st copy / 2nd copy) | Original | Meaning |
| --- | --- | --- |
| `0x24a2b4` / `0x31f8b4` | `bne t0,s5` | a repeated Length header must equal the first |
| `0x24a2e4` / `0x31f8e4` | `beqz t0` | a final packet must carry End-of-Body (`0x49`) |
| `0x24a2fc` / `0x31f8fc` | `bne s4,s5` | collected bytes must equal the declared Length |

Packet size, Connection ID, opcode, capacity and empty-body checks are unchanged.

## 2. Retry (`Blue.exe`)

**Reason.** The binding action tries each track selection once. If the transfer failed, or the phone reported no cover for a fresh track, the cover stayed missing.

**Change.** Two hooks in the action at `0x273400`, with code in the free gap at `0x273690`.

| Address | Original | Now |
| --- | --- | --- |
| `0x273574` | `beq t0,s4,refused` | `j` to retry case A (channel idle or failed, same selection) |
| `0x2734dc` | `beqz t0,accepted` | `j` to retry case B (covered, controller READY, nothing published) |

Each selection gets at most 3 retries, 1.5 s apart, using the tick clock stub at `0x25a000`. Counters use the unused binding words at `0x300324` (stamp), `0x300328` (retries) and `0x30032c` (selection tag). The retry reuses the existing refresh and reopen paths.

## 3. Rounded corners and 278×278 cover (`AppMain.exe`)

**Reason.** The cover slot is 278×278 at (27,98), but the 200×200 thumbnail was stretched with a plain GDI stretch.

| Address | Change |
| --- | --- |
| `0x387ec0`, `0x387f60` | decoder (live clone): DIB size and draw rectangle 200 → 278 |
| `0x2221c0`, `0x222260` | same edit in the unused original decoder |
| `0x23515c` | paint: source size 200 → 278 |
| `0x235168`, `0x23516c` | paint: ROP replaced by key color `0x00FF00FF` |
| `0x235178` | paint: `StretchBlt` import (`0x185250`) → `TransparentImage` (`0x18524c`) |
| `0x388268` | decoder wrapper: `move s6,v0` → `jal` to the corner-mask routine |
| `0x388d10`.. | new code: `post`, `mask`, `maskbits` and a 16-entry width table |

The source JPEG check stays 200×200. `mask` calls `GetObjectW` (IAT `0x185078`), requires a 278×278, 24-bit DIB section, then paints the corner quarter-discs with the key color. `TransparentImage` skips them, so the active theme's background shows through.

## Evidence

| Claim | Level |
| --- | --- |
| The iPhone's final packet was rejected by the three checks above | Confirmed static behavior plus device logs |
| Relaxing them lets iPhone covers load (Spotify, Apple Music) | Device test |
| Patched validator accepts iPhone-style final packets and still rejects wrong IDs and error opcodes | Fixture results |
| Retry decisions (first failure, too soon, due, budget spent, new track reset) | Fixture results on the written bytes |
| Corner mask changes exactly 212 pixels per cover and nothing else | Fixture results on the written bytes |
| `TransparentImage` accepts a memory DC as source | Inferred from existing app calls (decompiler reading), not yet a device test |
| Why a cover is missing after a skip | Guess; no log of the failure was available |
| Retry, corners and 278×278 display on a car | Pending device test |

## Reproduce and verify

```
python3 tools/patch_cover_final_packet.py upgrade.lgu step1.lgu
python3 tools/patch_cover_retry_and_corners.py step1.lgu step2.lgu
python3 tools/verify_cover_patches.py upgrade.lgu step1.lgu step2.lgu
```

`verify_cover_patches.py` checks the written bytes: only the listed members change, every changed byte lies in a reviewed range, PE checksums, and the fixtures above in the repo's MIPS interpreter. The scripts need `pefile` and `capstone`. Use `--version` on either patch script to relabel a test build.

## Not included

A larger cover image requested from the phone (`GetImage` with an image descriptor). The unit asks for the 200×200 linked thumbnail. What the iPhone accepts is unknown, so it needs a log of the phone's image properties first.
