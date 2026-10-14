# MAX22: owner-reported Settings repaint regression and new capture analysis

The supplied MAX21 captures are privately snapshotted under
`build/usb-log-analysis-20261014-01`, with input hashes, decoded records,
summary and findings. Raw owner logs are excluded from source/releases.

## Regression and correction

The owner observes absent/stale Settings options until opening Version Info
and returning. MAX20/21 removed explicit child drawing and relied on whole-
window invalidation with erase. That assumption conflicts with the native
cached drawing path: 0x134d28 does not always traverse/render children.

MAX22 restores immediate native control draw (0x139020). The status label uses
the existing native 0x400 flag: label renderer 0x139b94 restores its parent's
background via 0x13d098 before drawing text. This clears only the row, using
native theme resources. Both control rectangles are then presented through
0x13d220 with its ordinary visibility/parent guards, covering cached mode too.
Native window paint completes before the added rows are drawn/presented.
Toggle no longer invalidates the whole window. Writer status notifications use
InvalidateRect(FALSE), retaining native cached surfaces rather than erasing them.

The actual native label-renderer and rectangle-present instructions run in the
fixture, with explicit background/text/BitBlt GDI boundaries. Transparent status
reproduces stale suffixes; opaque restore yields exactly the new text. Cases
cover normal/cached modes, Eco/no-Eco status positions, themes, first row draw,
toggle, hidden pages, paint ordering, return registers and LastError. This is
stronger evidence than the former API-stub-only redraw checks, but the real
screen still needs the owner's car test.

## New findings

Three files contain 1,435 valid records across two sessions, with no partial
lines. The restart capture logs AppMain/managers before manual interaction,
supporting restore of the enabled setting. Unique chunks from the earlier
session are preserved. Main capture reports zero dropped records. The warm
session has 18 drops already in its first surviving sample, with no increase.

All 11 tracked bitmap creations have successful deletion records. During
playback, the create/delete difference represents the displayed bitmap and
returns to balance on retirement. No failed creation/deletion is visible.
These short sessions do not establish or rule out other retained resources or
a broader memory leak. Main RAM settles around 94–95 MiB free after startup;
large early changes occur while native media managers allocate their pools.
No speculative memory-lifetime changes are made.

The 11 decode calls range up to 114 ms; native image drawing dominates at up
to 68 ms. JPEG validation peaks at 25 ms in one warm-session sample. The work
remains on its existing artwork worker; bounds, image dimensions and quality
are retained. No benefit from changing decoder format or dropping validation
is established by these captures.

Source switches reach 906 ms. On the observed FM-to-Bluetooth path, static
native code has 200 ms source settling, 50 ms navigation/audio settling,
200 ms playback settling and a further 200 ms before media-fade IPC: 650 ms of
deliberate waits. The previous trace measured only source wait C (about 201 ms).
IPC calls are mostly 10–30 ms. MAX22 records the nested waits (events 133–135)
and fade IPC (136), keeping original values/order. A valid native readiness
condition is required before replacing waits; IPC delivery alone is not one.
No faster source switching is claimed.

Native Navigation Not ready messages occur during startup; DAB IPC destination
failures follow ACC OFF. There is no observed active-session failure storm.
Mixed narrow/wide Micom prefixes remain a logging readability issue. Original
native debug/error output remains enabled and is not suppressed.

## Delivery and reproduction

Full MAX21 successor: all 1,919 payload paths retained, 1,916 byte-exact.
Only AppMain, CmnDll and version change. Blue/poll optimization, artwork
ownership, saved config, non-overwriting log files, assets, navigation, DBoot,
kernel and MCU input remain. Earlier packages and the four-card backup are intact.

```powershell
$env:PYTHONPATH="$PWD/tools/python-libs;$PWD/tools"
python tools/prepare_debug22.py
python tools/prepare_verify22.py
python tools/prepare_package22.py
python tools/build_max22.py --output build/max22-settings-development-FRESH
python tools/verify_max22.py --build build/max22-settings-development-FRESH
python tools/package_max22.py --stage build/max22-settings-development-FRESH
```

Car check: open Settings directly, change values/toggle Debugging, switch pages
and both themes, then verify Version Info/return and USB status transitions.
Controls must appear/update without the Version Info workaround and without
overlap. Retest source/media/artwork/navigation; collect longer continuous
same-track versus track-change captures and several FM/Bluetooth switches.

Final stage `build/max22-settings-development-03`: 265 written-byte checks pass.
Independent full LGU decode, separate pinned PC extraction, all payload hashes,
ZIP CRCs and 59 frozen source pins pass. The delivered analyzer smoke validates
new wait names and counter separation. LGU 52,145,536 bytes, SHA256
`ea25d06a022d349767c5c34cda28aefdcd60d549a28443c887fc6183e25a42d1`.
Full deliveries are `build/maxmade-7.0.6.MAX22/upgrade.lgu` and
`build/maxmade-7.0.6.MAX22.zip`. No device flash or public release was performed.
