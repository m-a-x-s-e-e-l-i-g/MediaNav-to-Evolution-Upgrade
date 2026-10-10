# Failed USB graph initialization — development candidate

Based on the complete **7.0.6.MAX04** payload and [PR #26](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/pull/26). This is a review candidate, not a new release.

## Problem

- `RenderFile` (`0x11f78`) creates a graph, renders the file, acquires five interfaces and sets the event notification window.
- Seven post-creation failure exits return without releasing the references already acquired. The graph-present flag remains set until another teardown attempt.
- `LoadFile` reports failure and clears readiness, but retains those resources. Unsupported files or failed initialization can therefore keep a partial graph alive between attempts.
- The verifier reproduces all seven exits using the original graph-state candidate's instructions. Actual memory consumption, failure frequency and codec behavior have not been measured.

## Changes

- Record successful new graph creation in an unused local stack slot. A refused replacement of an existing graph is a different case.
- Route the original result through one cleanup helper. Success keeps the original graph, interfaces and return value.
- After failed new acquisition, use PR #26's guarded teardown. Release partial interfaces immediately when there is no control interface; otherwise require a confirmed stop before releasing them.
- Preserve the original return value, including the original zero result for creation/render failures and HRESULT for later setup failures.
- Retain resources when stopping cannot be confirmed, allowing a later retry through the existing replacement guard.
- A refused replacement does not run teardown a second time from the failure epilogue.
- Keep the original acquisition sequence, logging, notification setup and `LoadFile` status/lock handling.

API context: [IGraphBuilder::RenderFile](https://learn.microsoft.com/en-us/windows/win32/api/strmif/nf-strmif-igraphbuilder-renderfile), [IUnknown::Release](https://learn.microsoft.com/en-us/windows/win32/api/unknwn/nf-unknwn-iunknown-release). These describe COM ownership; the instruction fixtures remain separate from actual CE behavior.

## Evidence

- [Instruction report](firmware/usb-graph-init-development.json): **360 initialization cases** and **386 retained graph-state cases**, executed against the written candidate.
- Covers three failure HRESULTs, all initialization stages, retry after failure, failed/pending cleanup, successful no-op cleanup, shared interface identities, 32 consecutive failures, `LoadFile` error/readiness handling and three alternate load addresses.
- Reference fixtures count each acquired reference separately, even when several interface pointers share an identity. Calls preserve stack, return address and callee-saved registers with adversarial API clobbers.
- [Retained USB checks](firmware/usb-graph-init-retained.json): **72,212 passing cases** for save/resume, folders, sorting, WMA/shuffle, artwork, playlists and earlier input/encoding behavior. All 224 legacy Python snapshots and eight historical inputs match their recorded hashes.
- [Complete member manifest](firmware/usb-graph-init-members.json): **1,918 files**, **1,917 unchanged** from MAX04. Only `MgrUSB.exe` changes; PR #26's improvements are retained.
- Two original instructions change; one helper and its exception row use checked existing space. Sections, imports, entry point, previous helper code and function rows are preserved. Every new edit reverses exactly to the checked PR #26 input.

## Reproduce

Install the [research dependencies](../docs/development.md#research-dependencies), then run from the repository root:

```powershell
python tools/release_payload.py --prepare-input .inputs/max04-baseline
python tools/release_payload.py --baseline .inputs/max04-baseline --out build/max04-reproduced
python tools/build_usb_graph_init_development.py --baseline build/max04-reproduced/payload --out build/usb-graph-init-development
python -m unittest discover -s tools -p test_usb_graph_init.py
```

- The builder verifies the complete MAX04 input, applies the two pinned stages, reads back every member and tests the written executable before writing completion metadata.
- Refuses wrong input bytes, missing/extra members, overlapping directories and existing outputs.
- GitHub Actions reproduces MAX04 and runs the 746 combined graph checks. The full historical USB suite uses recorded local stage inputs and is not claimed to run in CI.
- No LGU, version bump or published-release replacement.

## Device validation still needed

- Real CE loading/unwind, reference lifetimes, codecs, concurrency, memory use and timing are unverified. Individual COM calls can still block internally.
- Failed cleanup deliberately retains resources. It cannot guarantee recovery or memory reclamation when a graph will not stop.
- Test a valid file after unsupported/corrupt media, repeated failures, source switches and USB removal/reinsertion. Check ordinary playback, seeking and event notifications still work.
- Compare to MAX04 on the unit; fixture success is not a hardware stability or performance claim.
