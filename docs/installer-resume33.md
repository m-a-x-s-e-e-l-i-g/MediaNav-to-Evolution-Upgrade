# MAX33 application installation transaction

Candidate only. MAX32 remains the published release. No physical car testing,
CE loader validation or storage/power durability guarantee is claimed.

## Entry and ownership

The native updater prelude bootstraps the independent worker and recovery menu
from a matching extracted MAX33 stage before entering native settings handling.
The original verified temporary/backup/rename helper retains source copies.
Healthy settings migration stays native; only the application-copy call delegates.
An ambiguous settings checkpoint remains stopped until explicit Repair is selected.

The running updater is recognized by its full pinned file hash and remote state:
error 6001, phase 3008, firmware busy zero means a held delegated parent. It is
never terminated. A nonzero error, phase 3007, busy zero permits quiescing the
known stopped updater for explicit repair or an owned transaction resume. Other
application/firmware states block writes. This depends on the pinned original
module's addresses and does not generalize to other updater versions.

## Durable states

| State | Evidence | Next action |
| --- | --- | --- |
| Extracted, no own receipt | Version and extraction receipt; boot components pinned | Native healthy settings path, or explicit ambiguous-state repair |
| Copying | Immutable package receipt plus checked alternating journal | Continue 256 KiB blocks in checked temporaries |
| Verifying | Same receipt, pass 1 journal | Verify final targets block by block; failure schedules recopy |
| All applications verified | Pass 2 journal, retained sources | Rename stage to owned quarantine, clear scan, install version last |
| Committed | Completion receipt and target version; own receipt still present | Remove only known public source files and empty directories |
| Cleanup interrupted | Own receipt, pass 2, completion, version; no original stage | Resume cleanup even when source files are gone |
| Handoff | Own receipt removed; completion and version checked | Return success to held parent or start native updater |
| Normal startup ready | Existing native readiness guard | Clear boot-attempt marker |

Journal checks cover sequence, package, phase, member/block bounds and SHA256.
Two slots preserve the previous valid cursor while the next is written, flushed
and read back. Source and temporary blocks are checked against compiled hashes;
live targets are replaced only after their temporary blocks verify. Delete then
rename is replayable, not an atomic filesystem transaction. A separate final
verification pass precedes version publication. The package identity includes
payload rows, worker source and builder source so code variants cannot share a
pending receipt accidentally. The worker compares itself with the retained
staged copy; active kernel/updater/recovery bytes have independent pinned hashes.

The worker excludes itself from its compiled payload manifest to avoid a self
hash cycle. It also does not replace running recovery/updater/kernel or flash
firmware.hex. Its own bootstrap is checked byte for byte by the native updater.

## Recovery and normal behavior

Two native error-screen controls remain independent: Repair / resume update,
and Open recovery desktop. Healthy repaint/touch behavior is retained.
Recovery auto-resumes an existing own receipt once on a fresh boot. Software
failures launch it with -MAX33NoAuto, preventing an immediate retry loop.
A malformed receipt is rejected by the worker, with Windows CE still offered.
The desktop route retains MAX31's DBoot initialization and ROM Explorer fallback.

A native parent accepts completion only after the child exits successfully,
matching completion/version bytes are read, and both original stage and pending
receipt are absent. The worker keeps MAXboot.flag until native readiness; it
removes the stale legacy maintenance power counter only after verified commit.
Known public sources may be cleaned; unknown extras and TFAT settings backups
are preserved. Cleanup errors can leave sources behind without blocking startup.

## Limits and verification

The first installation of these components still passes through legacy extraction,
first-stage kernel/self replacement and MCU handling. Those phases, healthy native
settings migration and other native maintenance/wait behavior are not made into
transactions here. The delegated parent waits for the worker to exit; journaling
does not resolve a permanently hung CE API. Real storage corruption, physical
power management, MCU behavior and flash durability remain separate risks.
Explicit repair preserves current settings rather than proving an interrupted
migration completed. This cannot promise that nobody can ever be locked out.

The frozen evidence executes written MIPS with explicit CE APIs: native bootstrap,
success/failure gates, repair/desktop touch and paint, menu choices, process state,
full payload hashes, block resume, publication/cleanup interruption, native SHA
boundaries and relocated worker execution. Bulk hashing uses hashlib acceleration;
separate checks execute native SHA and a real file chunk. Byte-identical baseline
helpers retain their recorded tests. None of this is hardware emulation.

Do not provoke failures by disconnecting power in the daily car. Use a recoverable
bench unit for interrupted-install acceptance. The separate issue59 MAX30 completion
kit and its guide are unchanged; this candidate is not a replacement repair kit.
