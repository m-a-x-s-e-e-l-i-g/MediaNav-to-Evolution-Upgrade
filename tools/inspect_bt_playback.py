"""Preserve A2DP playback evidence; model queued PCM duration without audio/device calls."""
import csv
import hashlib
import json
import struct
from fractions import Fraction
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]
BLUE_HASH="5e659f513327c84964a929ea9b9e3192384b3031fa6e6ffb6ad76b02af1b7c7b"


def source(module,addresses,leaves):
    raw=(ROOT/module["path"]).read_bytes();assert hashlib.sha256(raw).hexdigest()==module["sha256"]
    pe=pefile.PE(data=raw);base=pe.OPTIONAL_HEADER.ImageBase
    functions=json.loads((ROOT/f"analysis/functions/{module['origin']}/{module['name']}.json").read_text(encoding="utf-8"))["functions"]
    sizes={int(f["begin_va"],16):f["bytes"] for f in functions};ranges=[]
    for va in addresses:
        n=sizes[va] if va in sizes else leaves[va];data=pe.get_data(va-base,n);assert len(data)==n
        ranges.append(dict(va=hex(va),bytes=n,boundary="pdata" if va in sizes else "reviewed leaf",
            raw_hex=data.hex(),sha256=hashlib.sha256(data).hexdigest()))
    return dict(module=module["name"],origin=module["origin"],path=module["path"],sha256=module["sha256"],ranges=ranges),pe


def prefill(incoming_bytes,submit_minimum,start_count,rate,channels=2,bits=16):
    """Successful writes, paused output and constant decoded packet size; no callback until restart."""
    assert 0<incoming_bytes<=8192 and 0<start_count<=25
    pending=0;acc=0;total=0;packets=0;submissions=[]
    while pending<start_count:
        acc+=incoming_bytes;total+=incoming_bytes;packets+=1
        if acc>=submit_minimum:
            pending+=1;submissions.append(acc);acc=0
    denominator=rate*channels*(bits//8)
    duration=Fraction(total,denominator)
    return dict(incoming_pcm_bytes=incoming_bytes,rate=rate,channels=channels,bits=bits,
        submit_minimum_bytes=submit_minimum,start_count=start_count,packets=packets,
        queued_buffers=submissions,total_pcm_bytes=total,queued_duration_ms=float(duration*1000),
        exceeds_nominal_slot_stride=any(n>25600 for n in submissions),
        scope="PCM duration, not wall-clock delay; successful writes and no paused callbacks")


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    blue=next(m for m in modules if m["origin"]=="705md" and m["name"]=="Blue.exe")
    old=next(m for m in modules if m["origin"]=="remove-md" and m["name"]=="Blue.exe")
    updater=next(m for m in modules if m["origin"]=="705md" and m["name"]=="UpgradeManager.exe")
    assert blue["sha256"]==BLUE_HASH
    addresses=[0x193b4,0x193e0,0x24840,0x247d0,0x24b20,0x24e64,0x25144,0x25458,
        0x25794,0x25fc8,0x2639c,0x26400,0x26550,0x266a4,0x26a8c,0x26c68,0x26d2c,
        0x26e14,0x183a8,0x1c45c]
    current,pe=source(blue,addresses,{0x193b4:0x2c,0x193e0:0x20})
    older,old_pe=source(old,[0x4fbfc,0x50110,0x507a0],{})
    installer,installer_pe=source(updater,[0x14eb0,0x17964,0x181b4],{})
    base=pe.OPTIONAL_HEADER.ImageBase
    words={va:struct.unpack("<I",pe.get_data(va-base,4))[0] for va in [0x26f58,0x26f68,0x27010]}
    assert words=={0x26f58:0x2d295001,0x26f68:0x2d4b0019,0x27010:0x2d2a000b}
    old_base=old_pe.OPTIONAL_HEADER.ImageBase
    assert struct.unpack("<I",old_pe.get_data(0x508e8-old_base,4))[0]==0x2d083c00
    assert struct.unpack("<I",old_pe.get_data(0x50b04-old_base,4))[0]==0x29080002
    patch_va=0x27010;before=words[patch_va];after=(before&0xffff0000)|3
    assert before>>26==0xb and after>>26==0xb and (before>>16)==(after>>16)
    # Memory-only draft with an exact preimage, no binary written or executed.
    original=(ROOT/blue["path"]).read_bytes();draft=bytearray(original)
    at=pe.get_offset_from_rva(patch_va-base)
    assert draft[at:at+4]==struct.pack("<I",before)
    draft[at:at+4]=struct.pack("<I",after)
    differences=[i for i,(a,b) in enumerate(zip(original,draft)) if a!=b]
    assert differences==[at] and len(draft)==len(original)
    draft_pe=pefile.PE(data=bytes(draft));assert draft_pe.FILE_HEADER.Machine==pe.FILE_HEADER.Machine
    traces=[]
    for rate in [16000,32000,44100,48000]:
        for channels in [1,2]:
            for incoming in [512,1024,2048,4096,8192]:
                native=prefill(incoming,0x5001,11,rate,channels)
                candidate=prefill(incoming,0x5001,3,rate,channels)
                comparison=prefill(incoming,0x3c00,2,rate,channels)
                assert candidate["total_pcm_bytes"]*11==native["total_pcm_bytes"]*3
                traces.append(dict(native=native,candidate=candidate,old_early_restart=comparison,
                    old_scope="Early restart condition only; special hold/overflow branches remain separate"))
    # Independent integer oracle for accumulation/first-threshold crossing.
    checks=0;overlap_inputs=[]
    for incoming in range(4,8193,4):
        for minimum in [0x5001,0x3c00]:
            expected=((minimum+incoming-1)//incoming)*incoming
            for count in [2,3,11]:
                result=prefill(incoming,minimum,count,48000)
                assert result["total_pcm_bytes"]==expected*count;checks+=1
                if minimum==0x5001 and count==11 and result["exceeds_nominal_slot_stride"]:
                    overlap_inputs.append(dict(incoming_pcm_bytes=incoming,submitted_bytes=expected))
    # Plan a union from checked local extracts. This is not a newly built LGU.
    inventories=[]
    for origin in ["705md","corruption-fix"]:
        with (ROOT/f"analysis/{origin}-inventory.csv").open(encoding="utf-8",newline="") as stream:
            records=list(csv.DictReader(stream))
        for record in records:
            path=ROOT/"extracted"/origin/record["path"]
            raw=path.read_bytes();assert len(raw)==int(record["size"])
            assert hashlib.sha256(raw).hexdigest()==record["sha256"]
            inventories.append(dict(origin=origin,path=record["path"],bytes=len(raw),sha256=record["sha256"]))
    assert len({r["path"].casefold() for r in inventories})==len(inventories)==1918
    nav=next(r for r in inventories if r["origin"]=="corruption-fix")
    assert nav["path"]=="upgrade/Storage Card4/NNG/nngnavi.exe"
    candidate=dict(binary_written=False,native_tested=False,source_sha256=BLUE_HASH,va=hex(patch_va),
        file_offset=hex(at),before_hex=struct.pack("<I",before).hex(),after_hex=struct.pack("<I",after).hex(),
        instruction_before="sltiu t2,t1,11",instruction_after="sltiu t2,t1,3",
        bytes_changed=len(differences),draft_sha256=hashlib.sha256(draft).hexdigest(),
        meaning="Restart at three pending headers instead of eleven; payload/ring/callback code unchanged",
        limitations=["Not a tested fix or selected final buffer target","Driver queue, packet jitter, phone codec and A/V sync require measurement",
            "No native execution, binary output or flashable LGU was produced"])
    evidence=dict(binary_execution=False,sources=[current,older,installer],checks=dict(original_ranges=26,
        exact_instruction_preimages=5,prefill_comparison_cases=len(traces),accumulation_oracle_cases=checks,
        package_union_files=len(inventories),memory_only_patch_changed_bytes=len(differences)),
        native=dict(header_count=25,header_capacity_bytes=25600,total_buffer_bytes=640000,
            submit_minimum_bytes=20481,restart_pending_headers=11,pcm_bits=16,pcm_sample_rates=[16000,32000,44100,48000],
            fields=dict(state="+4",pending="+5",producer_index="+6",current_buffer="+330",accumulated="+334",
                restarted="+338",channels="+339",bits="+33a",rate="+33c")),
        lower_bound_stereo_48k_ms=11*20481/192000*1000,
        lower_bound_stereo_44100_ms=11*20481/176400*1000,traces=traces,candidate_patch=candidate,
        nominal_slot_overlap_inputs=overlap_inputs,
        combined_payload_plan=dict(package_built=False,user_observation="Main update completes; navigation subsequently reports corruption",
            scope="This producer checks the source union; separate candidate builds are recorded in build manifests",
            local_build_report="analysis/review-update-contracts.md",
            original_files=1917,added_files=1,nav_payload=nav,files=inventories,
            install_path="Storage Card3/upgrade/Storage Card4/NNG/nngnavi.exe -> Storage Card4/NNG/nngnavi.exe",
            open_items=["Native unit package acceptance, copy/readback and recovery",
                "Existing nav engine byte-level patch versus same-version original remains unknown",
                "Installer copy/readback/recovery and actual unit hashes/version"]),
        limitations=["End-to-end latency has not been measured on a phone/unit",
            "PCM duration assumes the stated negotiated format and successful paused queueing",
            "Downgrade corpus identifies itself as 4.0.6, not 4.1.0 or every legacy build",
            "Old early restart model omits its special hold/overflow/runtime branches",
            "NAV executable is reused unchanged; its internal corruption-check changes remain unknown"])
    (ROOT/"analysis/firmware/bt-playback-contracts.json").write_text(json.dumps(evidence,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**evidence["checks"],lower_bound_stereo_48k_ms=evidence["lower_bound_stereo_48k_ms"],
        lower_bound_stereo_44100_ms=evidence["lower_bound_stereo_44100_ms"],candidate_patch=candidate),indent=2))


if __name__=="__main__":main()
