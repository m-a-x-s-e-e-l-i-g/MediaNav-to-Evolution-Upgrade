# USB catalog allocation failures

- **Finding:** the scan dispatcher can enter enumeration with a partial catalog. Required storage is not checked before the first directory write.
- **Recovery constraint:** the singleton caches partial objects, and unsuccessful allocation attempts still consume tracking entries.
- **Scope:** reproducible investigation on the PR38 candidate. No executable, release or README changes.

## Storage requirements

| Buffer | Location | Bytes | Observed failure path |
| --- | --- | ---: | --- |
| Songs | CFileMgr + `18` | 2,640,000 | Song-parent setter `12ba8` writes to `208` when the base is null. |
| Directories | CFileMgr + `38` | 2,720,000 | Root insertion `131c8` passes null to the CRT, then writes to `20c`. |
| Temporary directories | Global `2fea0` | 2,720,000 | Flattening `14390`, at depth 3, passes null to memcpy, then writes to `208`. |
| Playlists | CFileMgr + `3c` | 4,536,000 | Insertion `1311c` already returns zero without copying when absent. Treat separately from required scan storage. |

Songs and both directory buffers are required for general USB scanning. The temporary buffer is not touched by the shallow-folder fixture. Disabling all scanning solely for a playlist allocation failure would discard an existing guarded path; full playlist behavior still needs validation before declaring this buffer optional everywhere. Event-handle failure is outside this investigation.

## Executed paths

- **Dispatcher `1ef48`:** 16 allocation masks, cancellation on/off and manager readiness on/off, at four relocated load addresses. Root insertion occurs before the first cancellation read. A missing directory buffer reaches the same invalid store even when cancellation is set or readiness is zero.
- **Dispatch without missing directories:** enumeration and postprocessing are called even when song, playlist or temporary storage is absent. These two routines are fixtures here; their dispatch does not prove successful indexing.
- **Existing completion:** normal and canceled returns clear the USB busy field and preserve the calling convention. Three empty-media request modes emit the existing command `9` flags (`2013` or `2033`); the no-device path returns without that notification.
- **Storage primitives:** actual playlist insertion, song-parent assignment and shallow/deep flattening execute separately, with present/missing buffers.
- **Singleton `14db0`:** three lookups allocate/construct a partial catalog only once. Failure to allocate the outer object is retried, but a nonnull partial object is cached. The inner constructor is a fixture; [PR38](usb-catalog-initialization-development.md) executes the real constructor for all allocation masks.
- **Allocator `12844` and cleanup `129c8`:** two failed attempts followed by one successful heap/external allocation leave three tracking records. Cleanup frees the successful buffer once and resets the count. Repeated retries cannot assume failed attempts cost nothing.

## Reproduce

[Verifier](../tools/verify_usb_catalog_readiness.py) and [324-case report](firmware/usb-catalog-readiness.json). Build the complete [catalog initialization candidate](../tools/build_usb_catalog_initialization_development.py) first, then run:

```powershell
python tools/verify_usb_catalog_readiness.py --candidate "build/usb-catalog-initialization-development/payload/upgrade/Storage Card/System/MgrUSB.exe" --report build/usb-catalog-readiness.json
```

- Candidate SHA256: `5f34249de2ec66a9cc3f22a6dc35e063eefc885faee58b3b12d8a5e56a29c234`.
- **324 checks:** 272 dispatcher, 8 playlist, 8 song, 16 flattening, 8 singleton, 8 allocator/cleanup and 4 arithmetic-shift checks.
- Invalid stores are expected findings in this report, not repaired behavior. Unknown instructions/calls and unexpected writes fail the verifier.
- CRT, driver, allocation, registry, enumeration, postprocessing, logging and cookie checks use explicit fixtures. Null CRT returns EINVAL; null memcpy is suppressed to expose the subsequent store. Neither demonstrates native Windows CE exception behavior.
- No scheduler, concurrency, driver-contract completeness, incident-frequency, speed or RAM measurements. No device execution or LGU.

## Next implementation

- Establish readiness before root insertion, enumeration or early playback; cover cancellation and the existing busy-field cleanup.
- Recover missing required buffers with bounded attempts, preserving successful allocations and their tracking records. Avoid reconstructing the cached object or repeatedly allocating all buffers.
- Keep playlist failure distinct, retain existing capacities and handle a second scan after recovery.
- Verify the GUI error/completion response before reusing an empty-media notification for allocation failure.
- Exercise retry success/failure, partially allocated catalogs, deep folders, repeated requests and cancellation; then validate the candidate on the unit.
