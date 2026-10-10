"""Preserve iPod/UWD contracts from original binaries; no firmware execution or USB I/O."""
import hashlib
import json
import re
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
SOURCES = {
    ("705md", "MgrIpod.exe"): "2b4665529cfcc7ec696f53ff3ac6fb8f14fd63412722130a912d369ce68009f0",
    ("rom", "USBware.dll"): "85dd9e9a711d356111fc592072fd7507205d18e0a56b0ec5d5396509384d0ef2",
    ("705md", "AppMain.exe"): "6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8",
}
RANGES = {
    ("705md", "MgrIpod.exe"): [
        (0x1136c, "Status initialization"), (0x1168c, "Milliseconds display conversion"),
        (0x124cc, "First categorized-record request"), (0x127ec, "Subsequent record batches"),
        (0x12a48, "Connection and remote UI initialization"),
        (0x12e2c, "Artwork request sequence"), (0x13078, "RGB565 DIB creation"),
        (0x13fac, "Prepare digital audio"), (0x14050, "Start digital audio/open wave device"),
        (0x146b8, "Hardware attachment notification"), (0x149fc, "Detach cleanup"),
        (0x14d9c, "Record callback and 5000/259-byte bounds"),
        (0x15f14, "Player status and duration callback"), (0x16344, "Current track index"),
        (0x1679c, "Track title callback"), (0x16904, "Artist2 metadata callback"),
        (0x16bb4, "Artwork chunk accumulation"), (0x16dd4, "Artwork times"),
        (0x16ea4, "Artwork format selection"), (0x16f50, "Driver/callback/event startup"),
        (0x17700, "Shared mapping allocation"), (0x17aec, "Mapping cleanup"),
        (0x17bcc, "Window IPC dispatch and timers"), (0x1842c, "AppMain command dispatcher"),
        (0x193d0, "System shutdown/audio focus"), (0x1995c, "Self-message dispatcher"),
        (0x1a92c, "Command and callback-cookie initialization"),
        (0x1a9f0, "User context and UWD subscription"),
        (0x1ab68, "Callback packet reassembly and dispatch"),
        (0x1c9d0, "Command segmentation"), (0x20744, "User mode entry"),
        (0x21280, "UWD1 open and exact version check"), (0x215cc, "Blocking callback receive"),
        (0x216c0, "Cancel/join/close driver context"), (0x217d4, "IOCTL return envelope"),
    ],
    ("rom", "USBware.dll"): [
        (0xc09f3050, "UWD_Open"), (0xc09f3084, "UWD_Close"),
        (0xc09f3120, "UWD_IOControl BOOLEAN wrapper"),
        (0xc09f36fc, "All five UWD IOCTL branches"),
        (0xc09f74fc, "Audio context allocation"), (0xc09f76cc, "Wave open and ten buffers"),
        (0xc09f79cc, "Stereo S16 PCM and buffer-size calculation"),
        (0xc09f7bf0, "Wave write"), (0xc09f7c9c, "Buffer rotation/pause/restart"),
        (0xc0a03904, "USB audio consumption to wave output"),
        (0xc0a05d60, "Sample-rate/default and audio-read start"),
        (0xc0a0779c, "Segment reassembly and iPod command dispatch"),
        (0xc0a088cc, "Attachment audio-rate candidates and initialization"),
    ],
    ("705md", "AppMain.exe"): [
        (0x13234, "Matching shared-mapping consumer"),
        (0x41508, "Track UID/name comparison and current-list index"),
    ],
}
COMMAND_NAMES = {10: "audio device open", 11: "audio device close", 12: "prepare digital audio",
                 13: "start digital audio read", 14: "stop digital audio read",
                 0x3e: "categorized records", 0x41: "artwork formats",
                 0x42: "artwork data", 0x43: "artwork times",
                 0x6c: "subscribe user callbacks", 0x6d: "unsubscribe user callbacks"}


def segments(extra_bytes):
    """Literal lengths in 1c9d0, including the fixed 48-byte command payload."""
    remaining = extra_bytes + 0x48
    result = []
    while remaining > 0x18:
        length = min(remaining, 0x1000)
        payload = length - 0x18
        result.append(dict(index=len(result),input_bytes=length,payload_bytes=payload))
        remaining -= payload
    return result


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources = []
    texts = {}
    for (origin, name), digest in SOURCES.items():
        module = next(m for m in modules if m["origin"] == origin and m["name"] == name)
        path = ROOT / module["path"]
        if hashlib.sha256(path.read_bytes()).hexdigest() != digest:
            raise ValueError(f"Source changed: {origin}/{name}")
        pe = pefile.PE(str(path))
        index = json.loads((ROOT / "analysis/functions" / origin / (name + ".json")).read_text(encoding="utf-8"))
        functions = {int(f["begin_va"], 16): f for f in index["functions"]}
        evidence = []
        for va, role in RANGES[(origin, name)]:
            # 1168c is an original leaf not described by .pdata.
            size = 0x94 if va == 0x1168c else int(functions[va]["end_va"],16) - va
            raw = pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, size)
            if len(raw) != size:
                raise ValueError("Truncated original evidence")
            evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
        texts[(origin, name)] = (ROOT / "analysis/decompiled" / origin / name / "decompiled.c").read_text(encoding="utf-8")
        sources.append(dict(origin=origin,name=name,sha256=digest,evidence=evidence))
    wrappers = []
    for block in re.split(r"(?=/\* [0-9a-f]{8} )", texts[("705md","MgrIpod.exe")]):
        marker = re.match(r"/\* ([0-9a-f]{8})", block)
        if not marker or marker[1] == "0001a92c":
            continue
        for match in re.finditer(r"FUN_0001a92c\([^,]+,(0x[0-9a-f]+|[0-9]+),",block):
            command = int(match[1],0)
            wrappers.append(dict(wrapper_va="0x"+marker[1],command=command,
                                 followed_meaning=COMMAND_NAMES.get(command),
                                 scope="Constant from pseudocode; original wrapper .pdata/bytes available"))
    checks=[]
    for extra in [0,1,4023,4024,4047,4048,4096,10000,1000000]:
        parts=segments(extra)
        assert sum(p["payload_bytes"] for p in parts)==extra+48
        assert all(24<p["input_bytes"]<=4096 for p in parts)
        checks.append(dict(extra_bytes=extra,chunks=len(parts),first=parts[0],last=parts[-1]))
    models=[]
    for rate in [32000,44100,48000]:
        size=((rate*4+4)*100+999)//1000
        size=(size+3)&~3
        models.append(dict(sample_rate=rate,period_argument_ms=100,channels=2,bits=16,buffer_bytes=size,buffers=10))
    registry=(ROOT/"analysis/firmware/boot-registry/default.validated.reg").read_text(encoding="utf-16")
    key=re.search(r"\[HKEY_LOCAL_MACHINE\\Drivers\\BuiltIn\\UWD\]\s*(.*?)(?=\n\[)",registry,re.S)[1].strip()
    result=dict(binary_execution=False,sources=sources,uwd_registry=key,
        ioctl_codes={"0x81002040":"blocking receive","0x81002044":"cancel receive / drain queue",
                     "0x81002048":"iPod command envelope","0x8100204c":"second backend command envelope",
                     "0x81002050":"exact version string including NUL"},
        wrappers=wrappers,segmentation_model_checks=checks,audio_buffer_models=models,
        shared_mappings=[dict(name="ShmFmMgrIpodAppMain",bytes=0xc5c),
                         dict(name="ShmFmMgrIpodAppMainList",bytes=0x13d628,header_bytes=8,records=5000,record_bytes=260),
                         dict(name="ShmFmMgrIpodAppMainListUID",bytes=0x9c54)],
        caveat="Static contracts only; wrapper candidates are not complete iAP semantics or a device trace")
    (ROOT/"analysis/firmware/ipod-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(source_modules=len(sources),evidence_ranges=sum(len(s["evidence"]) for s in sources),
                         wrapper_candidates=len(wrappers),segmentation_models=len(checks),audio_buffer_models=models),indent=2))


if __name__ == "__main__":
    main()
