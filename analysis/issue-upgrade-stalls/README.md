# Updater diagnostic evidence

Supporting reports for the [upgrade-stall investigation](../upgrade-stall-investigation.md), recorded on 2026-10-09.

## Progress-screen traces

- [Report](progress-screen-traces.json): 210 cases covering three themes, seven phases, English/Arabic and five graphics success/failure scenarios.
- Executes the original updater's MIPS drawing instructions with simulated API responses. Missing bitmap handles and failed copies still reach text drawing and final screen-copy attempts.
- Records the updater and verifier SHA256 hashes, case parameters and API events.
- Does not render Windows CE pixels, reproduce either reported stall or test storage, flashing or device recovery.
- With the original files at the recorded input paths and the [research dependencies](../../docs/development.md#research-dependencies) installed, regenerate from the repository root:

```powershell
python tools/verify_upgrade_progress_screen.py
```

## Recovery-DLL inspection

- [Metadata](recovery-uiodrv-static.json): binary hash/size, MIPS machine type, sections, imports, exports and extracted strings.
- Static inspection identifies hardware-access driver interfaces. It does not establish a universal update-recovery mechanism.
- The DLL was not executed. The binary, downloaded issue snapshots and photographs are not included here.

Both JSON files retain their original bytes and are hash-checked by `python tools/check_repository.py`. Publishing this evidence changes no firmware or release assets.
