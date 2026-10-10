"""Preserve original updater recovery evidence and offline failure/cut traces; no device I/O."""
import json
import hashlib
import struct
from pathlib import Path
from inspect_bt_playback import source
from updater_recovery_models import explore
from parse_micom_flash import encode_frame

ROOT=Path(__file__).resolve().parents[1]
HASH="4d6ffa36bc0e42945ba1ebce79de48d82030894e0e1f9c9e05165d3c33735f87"


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module=next(m for m in modules if m["origin"]=="705md" and m["name"]=="UpgradeManager.exe")
    assert module["sha256"]==HASH
    addresses=[0x12d80,0x14eb0,0x17530,0x17964,0x17dd4,0x17fe0,0x181b4,0x18460,0x18698,0x197a8]
    evidence,pe=source(module,addresses,{})
    preimages={0x14f38:0x14570124,0x15304:0x0c00606d,0x153d0:0x0c005ff8,
        0x1837c:0x0100f809,0x1839c:0x0140f809,0x183a0:0xae09061c,
        0x15198:0x0c006118,0x151a8:0x0c0068e9,0x151b8:0x0c0061a6}
    for va,word in preimages.items():assert struct.unpack("<I",pe.get_data(va-pe.OPTIONAL_HEADER.ImageBase,4))[0]==word
    models=explore()
    micom=next(m for m in modules if m["origin"]=="705md" and m["name"]=="MicomManager.exe")
    assert micom["sha256"]=="c56e8e08600cd69a656ec487779d3dbb0cea672ae2c5cb2da685b9217e6f8824"
    micom_evidence,micom_pe=source(micom,[0x23308,0x22cfc,0x1ef7c,0x1d750,0x283b0,0x19f4c],{})
    micom_preimages={0x1d81c:0x24060008,0x1d820:0x24050001,0x22e40:0x0c0075d4}
    for va,word in micom_preimages.items():
        assert struct.unpack("<I",micom_pe.get_data(va-micom_pe.OPTIONAL_HEADER.ImageBase,4))[0]==word
    fallback=encode_frame(1,8,bytes(1024))
    assert len(fallback)==1030 and fallback[:5]==b"ULC\xa1\x08" and fallback[-1]==0xa9
    packages=[]
    for folder in ["review-max01","review-apps-max01"]:
        manifest=ROOT/"build"/folder/"build-manifest.json"
        if not manifest.exists():continue
        record=json.loads(manifest.read_text(encoding="utf-8"))
        raw=(manifest.parent/"research-candidate.lgu").read_bytes()
        assert hashlib.sha256(raw).hexdigest()==record["verification"]["lgu_sha256"]
        paths={m["path"] for m in record["verification"]["members"]}
        packages.append(dict(scope=record["scope"],path=str(manifest.parent.relative_to(ROOT)),
            lgu_sha256=record["verification"]["lgu_sha256"],members=len(paths),
            firmware_hex_member="upgrade/firmware.hex" in paths))
    result=dict(binary_execution=False,binary_changed=False,sources=[evidence,micom_evidence],
        checks=dict(original_ranges=len(addresses)+6,exact_instruction_preimages=len(preimages)+3),models=models,
        local_packages=packages,
        missing_micom_image=dict(command="WM 0x8064 / wParam 0xc70300 / lParam 0x1234",
            updater_presence_gate=False,selected_path="Storage Card3/upgrade/firmware.hex",
            load_error_return=0,call_result_checked_by_message_handler=False,
            load_error_actions=["Kill four timers","Clear image holder; set update flag and counter to 1",
                "Queue ordinary AA command 5","Display progress value 1000","Call OnRequest 0x20"],
            fallback_frame=dict(bytes=len(fallback),prefix_hex=fallback[:5].hex(),payload_bytes=1024,
                payload_value=0,checksum=hex(fallback[-1]),sha256=hashlib.sha256(fallback).hexdigest(),raw_hex=fallback.hex()),
            meaning="CE attempts a control/load-error transfer even without firmware.hex; MCU meaning and restart are open"),
        contracts=dict(extraction_marker="Storage Card3/upgrade/filecopy_success.bin",
            marker_means="Extraction completion, not installed-file readback",
            marker_generic_move="Processed as an ordinary root file by recursive move; no filename exemption",
            final_delete="0x153d0 calls recursive deletion regardless of copy results or missing extraction marker",
            final_copy="0x1837c CopyFile; 0x183a0 progress store in DeleteFile delay slot; no CopyFile BOOL gate",
            recursive_status="No usable success/failure propagated through the reviewed void recursion/caller chain",
            config_preformat_backup="0x15198 backup then 0x151a8 format, with no backup-status gate",
            startup_launch="0x12d80 launches MicomManager after staging function without a result gate",
            firmware_self_update="0x17530 calls two MoveFile operations without checking either result"),
        limitations=["All control-flow claims apply to the pinned updater; current unit hashes remain unknown",
            "Dictionary models are counterexamples under stated assumptions, not CE/NAND/TFAT emulation",
            "Actual enumeration order, free space, sharing locks, driver errors and write durability remain unmeasured",
            "Repair requirements are a local design; no installer-reliability patch has been built or flashed"])
    (ROOT/"analysis/firmware/updater-recovery-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**result["checks"],models=models["stats"]),indent=2))


if __name__=="__main__":main()
