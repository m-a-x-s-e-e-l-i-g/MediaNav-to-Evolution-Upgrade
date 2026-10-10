# USB scan coordination

- **Finding:** a repeated attach can reset shared catalog state and start normal scanning while boot scanning remains active in a controlled instruction schedule.
- **Status:** reproduced on both MAX04 and the PR #40 candidate; their observed traces match. This is research evidence, not a scheduling fix.
- **Scope:** application workers and their activation/reset paths. No device execution, LGU or release change.

## Worker and reset paths

- Normal worker `22b40` waits on event `34f3c`, then calls `1ef48(USB, 1, 0)`.
- Boot worker `22bd8` waits on a separate event `34f44`, then calls boot controller `1fd6c(USB, resume)`.
- Message caller `229b8` forwards device message `8002` to attach handler `20a38`.
- First attach with manager `+10 == 0` signals boot work through `22fac` and sets `+10` to 1.
- A subsequent attach with `+10 != 0` and cancellation `+18 == 0` calls USB reset `1db80`, catalog reset `12e80`, then arms attach timer `3eb` for 1,000 ms through `1fc8c`.
- Attach timer `1eac4` resets the catalog again and signals normal work through `22f80`.

The traced attach branches do not wait for the boot worker before these resets. Each worker uses the same manager/catalog pointers. A flag check alone would not make those operations atomic.

## Reproducer

[Verifier](../tools/verify_usb_scan_coordination.py) uses separate register and stack contexts sharing one memory image. It executes the workers, message caller, attach handler, boot controller, catalog resets, scan readiness/root insertion and cleanup as MIPS instructions.

1. Deliver the first attach through the original message caller. Only the signaled boot event can wake its worker.
2. Pause boot scanning at `1f02c`, just before enumeration. Busy is 1, directory count is 1 and the root parent is `ffff`.
3. Deliver a second attach. The native resets change busy, directory count and the root parent to 0 while the boot context stays paused. Cancellation remains 0.
4. Deliver the timer that this attach actually armed. It signals the separate normal event; normal scanning enters the same enumeration call while boot scanning remains paused there.
5. Complete normal scanning. Its native cleanup clears busy to 0 while the boot context remains paused.
6. Resume boot scanning and complete its controller. Both workers reach the explicit ExitThread fixture.

Boot-only and sequential boot-then-normal controls also finish. These controls distinguish the overlap schedule from ordinary serial scanning.

## Boot status flag

The boot controller stores 1 at `USB+9a358` at `1fd9c`. Its subsequent call at `1fdc0` enters `1db80`, whose delay-slot store at `1dbb4` clears the same field. Both tested binaries therefore have boot-active 0 when boot enumeration is reached, even without a second attach.

This makes the field unsuitable as an ownership guard in its current lifecycle. Restoring the bit after reset alone would also require checking every boot exit: the missing-media branch skips the existing success-path clear at `2031c`.

## Verification and limits

- **48 cases passed:** two pinned binaries, four load addresses, both boot resume request modes, and boot-only/overlapping/sequential schedules.
- MAX04 SHA256: `cac3d40f5d54de681b1aad8c99fe79df5b430d3ee3d668616b63970f02ca1a2c`.
- PR #40 SHA256: `a9f0bf2266932d5574abd67c0a6444a27ada6e80064d6ee334db93e14e6d7ec8`.
- [Evidence](firmware/usb-scan-coordination.json) records state changes, signaled/consumed events, timer arguments and clear calls. Inputs remain byte-identical after verification.
- Returning message/timer calls preserve saved registers and their stack; worker stack canaries survive. Thread termination is an explicit fixture, not a returning CE thread test.

Events, timers, files, enumeration, postprocessing, notifications, artwork reset and cookie checks are fixtures. Full large-clear arguments are checked; only buffer prefixes are materialized. Timer delivery and preemption are controlled inputs, not elapsed-time measurements or an observed Windows CE schedule. These cases prove that the traced code admits the stated overlap; its frequency and full filesystem/UI consequences on the unit remain unmeasured.

## Next implementation requirements

- Give scans and catalog resets one shared lifecycle owner, including boot work and repeated attach/detach.
- Ensure an old scan cannot publish results or clear status belonging to a newer media generation.
- Preserve cancellation, boot request modes and existing completion/unavailable-media responses.
- Defer conflicting work without blocking the UI/message handler on a long scan.
- Cover recovery-buffer allocation under the same ownership rule. PR #40's sequential retry/tracking guards are not synchronization.
- Test both worker completion orders, repeated notifications, cancellation and every boot exit before native validation.
