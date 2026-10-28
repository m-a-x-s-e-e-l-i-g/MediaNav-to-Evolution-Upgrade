# Issue 66: temperature and theme capture

The [report](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/66)
describes -37 C followed by dashes, then a stock-looking interface without theme
selection. The seven attached logs omit vehicle configuration and raw outside
temperature bytes. The reporter's four-card dump is not available locally.

**Both symptoms remain unresolved on hardware.** A startup failure path is now
reproduced with shipped MIPS instructions. A separate, experimental collector
captures missing evidence without installing firmware or changing configuration.
This work does not produce MAX35 temperature/theme firmware.

## Confirmed instructions and uncertainty

| Path | Observed behavior | Interpretation |
| --- | --- | --- |
| MICOM startup `0x1f444`, loader call `0x1f630` | Clears its 36-byte DSI buffer before the call. | Actual caller prefix executed from a poisoned stack; failure can leave zero configuration. |
| DSI loader `0x1ee1c` | Uses a validated cache, otherwise requires 12 bytes from manager 13/F1 and 20 from F2. A failed/short read leaves output untouched. | Failed-read fixtures retain profile 0. This does not prove this car's reads failed. |
| MICOM startup | `UI_TYPE` comes from configuration byte 7 bits 6-7. Separately, an HMI byte supplies `HMI_TEMP_CNF` from bits 3-4; its read result is unchecked after zero initialization. | A common configuration problem is plausible. The full HMI failure/persistence path has static evidence, not an end-to-end fixture. |
| AppMain `0x1fbfc`, `0xbabc8`, `0xbc684` | Uses `UI_TYPE`/`UI_INVERSE` for resources and theme-control availability. Profile 0 selects M0. | Fits the appearance/control symptoms. Profile 0 is also a legitimate factory selection and must not automatically be treated as corruption. |
| MICOM `0x14090` | Celsius raw 3 becomes -37; raw 59 becomes 19; raw 255 becomes invalid sentinel 418. | Explains the displays if these bytes reached conversion. Original received bytes are missing. |
| MICOM `0x4753c` | ULC_TEMP uses a separate manager-9/address-6 board reading. | It does not establish that vehicle outside temperature is valid. |

Inspected temperature, DSI validation, resource and settings ranges are exact
MAX18 to MAX33. The caller/loader fixtures pin unchanged MAX33/MAX34 MICOM SHA256
`b93cb55a66c843e1bb5ea34fd58642e451e6b07afcf9f8ccd1fbc762d627e629`.
They do not distinguish an inherited conversion incompatibility, intermittent
communication failure, or legitimate vehicle profile on the reported unit.

The logs contain 2,372 DSI synchronization messages. Their handler writes the
DSI cache, clears two auxiliary caches and requests CAN configuration. The missing
payloads prevent establishing the cause or 2,372 successful durable writes.
Enabling debugging is not established as the cause.

## Capture on the unit

`MAXConfigProbe.exe` is a **Windows CE/MIPS** program, not a Windows PC program.
It has offline fixture coverage only; physical CE execution remains untested.
The local capture ZIP contains this standalone program, instructions and an
optional Python analyzer. It contains no firmware update.

1. Extract the kit to FAT32 USB. Put `MAXConfigProbe.exe` on the stick; do not
   add an `upgrade.lgu` for this diagnostic.
2. While stationary, use the existing CE file manager, browse **My Device > MD**,
   open the program, wait about ten seconds, and dismiss its result message.
   The [DBoot instructions](../README.md#access-windows-ce-with-dboot) explain CE access.
3. Copy the new `MAXmade/vehicle-config-<tick>-<attempt>/` folder from USB.
   Preserve a partial folder if the program reports a USB failure.
4. Record whether this was a separate CE desktop boot or MediaNav was running,
   the temperature shown beforehand, approximate real temperature, and whether
   theme selection was available. Keep separate captures around observed changes.

DBoot can start a separate CE session without MICOM/MediaNav running. Saved files
and available registry values can still be captured, while RAM sampling is skipped.
Do not manually start MICOM or restore another unit's configuration to get a
sample. Missing RAM is not a faulty-MCU diagnosis.

Only four existing files are read:

- `\Storage Card\System\DSI_config.bsd`, maximum 36 bytes;
- `\Storage Card2\EcoDrive.cfg`, maximum 9 bytes;
- `\Storage Card2\MgrSys.cfg`, maximum 128 bytes;
- `\Storage Card\System\Version_Info.txt`, maximum 64 bytes.

The collector queries explicit theme/temperature capability DWORDs in
`HKLM\LGE\SystemInfo` at start/end, without enumerating arbitrary registry data.
If the MICOM file hash, process base and in-memory function signature match, it
uses read-only process access for 20 current/target temperature, units and enabled
state samples. Pointer/read-size checks skip unavailable or mismatched versions.
These are processed state observations, not original packet bytes. Values can
change concurrently with sampling.

All output uses fresh `CREATE_NEW` files under
`\MD\MAXmade\vehicle-config-...`. Internal files open read-only. There are no
registry-write, serial/MCU-command, delete, rename, termination, reboot or flasher
imports. USB errors stop capture without modifying internal files.

Alternatively, manually copy just the three configuration files from the unit or
an existing backup. The analyzer accepts those files or the four-card layout.
Keep captures private until reviewed; they include vehicle configuration bytes.

## Analysis and reproduction

The analyzer uses standard Python and never changes a capture:

```powershell
python tools/inspect_vehicle_config.py path/to/vehicle-config-folder
python -m unittest discover -s tools -p test_vehicle_config.py
```

It checks sizes, DSI CRC/header bounds, EcoDrive XOR, inverse preference, registry
types and available samples. A later snapshot cannot prove a previous boot's read
failures. A valid profile 0 must not be replaced just to obtain a different theme.

Execute the 14 original-instruction cases on a fresh checkout:

```powershell
python -m pip install -r tools/requirements-vehicle-config.txt
python tools/prepare_vehicle_config_input.py --lgu .inputs/usb/MAX33.lgu --output .inputs/vehicle/MicomManager.exe
python tools/verify_vehicle_config_paths.py --module .inputs/vehicle/MicomManager.exe --output .inputs/vehicle/native-paths.json
python tools/check_vehicle_config.py
```

Collector building reuses the pinned MAX34 compiler/converter and SHA primitives
in `releases/7.0.6.MAX34/build-sources/tools/`. Local workspace prerequisites:
pinned Zig 0.13.0, WSL Ubuntu with `mipsel-linux-gnu-ld`, extracted CE ROM DLLs,
and full MAX33 stage at `build/max33-resumable-installer-development-05`.
Choose a new output directory. No CE binary is executed on the PC.

```powershell
python tools/build_vehicle_config_probe.py --output build/vehicle-probe --micom .inputs/vehicle/MicomManager.exe
python tools/verify_vehicle_config_probe.py --build build/vehicle-probe --micom .inputs/vehicle/MicomManager.exe --output build/vehicle-probe/verification.json
```

[Evidence](../analysis/issue66-vehicle-config/README.md) records 14 original MIPS
cases, 21 collector MIPS cases and six analyzer tests. Collector fixtures mock CE
files, registry, enumeration and RAM; one executes the real file/SHA pin and the
others accelerate that comparison. These checks do not emulate the CE loader or
confirm vehicle behavior.
