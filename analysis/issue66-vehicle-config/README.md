# Issue 66 vehicle configuration evidence

See [findings, capture and reproduction](../../docs/issue66-vehicle-config.md).

- `vehicle-config-paths.json`: 14 actual unchanged MICOM cases: caller buffer
  initialization, failed/short fallback reads, cached profiles and conversions.
- `vehicle-config-probe-verification.json`: 21 collector MIPS cases: internal
  files unchanged, fresh USB output, version guards and IO failure handling.
- `build.json`, `probe_pin.h`, `probe_sha.h`: executable/source hashes, symbols
  and exact generated headers. The executable stays outside Git in the local kit.
- `source-manifest.json`: new source, documentation and evidence hashes.

The reporter's dump is not available. No private backup data, actual car capture,
prescribed vehicle profile, firmware change or hardware resolution is included.
