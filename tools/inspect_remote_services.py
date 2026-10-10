"""Offline RAS/autoconnect/RAPI evidence and original 86-slot command-table extraction."""
import hashlib
import json
import re
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
SOURCES = {
    "autoras.dll":"94789e86d4809a8dca2780753fc1331896c839f99fd6512040c9be4e0829651e",
    "repllog.exe":"a55db9b6524d7c67684c42892095d6ced0877b85c97a156a00e9138d3c298d13",
    "rnaapp.exe":"2b1a69e221430e4aa1dec420f6d20bad6809e7fdcbd3be4dd1471c5580baf31e",
    "rapisrv.exe":"61232adab45502317123d0a842797accea1974d5201073b73190abb7dabd07ca",
    "ppp.dll":"b5f6bd4f0d8295e9203b3f92bd23a2920ecc086804f76caadb2e18d9e6d05df5",
    "afd.dll":"a4ef9dada55b14fd066e9c6723829effa28bbd53a021b2b34557d8df0de89399",
    "udp2tcp.exe":"360c9630c25c686d69460c1e6ad3ec63d26c3f58d07047663823697b835cc9e2",
}
FUNCTIONS = {
    "autoras.dll":[0xc0591160,0xc0591310,0xc0591480,0xc059164c,0xc0591730,
        0xc0591808,0xc0591980,0xc0591a3c,0xc0591b28,0xc0591bec,0xc0591c0c,
        0xc0591c2c,0xc0591d18,0xc0591df8],
    "repllog.exe":[0x131c4,0x133e4,0x14490,0x14804,0x17044,0x17e88,0x1adb4,
        0x1b568,0x1b640,0x1b93c,0x1bb40,0x1bc58,0x1bffc],
    "rnaapp.exe":[0x12280,0x12c60],
    "rapisrv.exe":[0x11a60,0x11c44,0x11d20,0x11da8,0x11f78,0x12040,
        0x12910,0x12aa4,0x12bec,0x12e30,0x132e0,0x13360,0x1343c,0x135c8,
        0x1c100,0x1c250,0x1c660,0x1c900,0x1cb2c,0x1cc40],
    "ppp.dll":[0xc0434af4,0xc0435398,0xc0435cc0,0xc0435dec],
    "afd.dll":[0xc0514ba0,0xc051a698],
    "udp2tcp.exe":[0x117ec,0x119e8,0x11c8c,0x11ce4,0x11f10,0x12020,0x1249c,0x125c8],
}


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    pes={};sources=[];commands=[]
    for name,digest in SOURCES.items():
        module=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        path=ROOT/module["path"]
        assert hashlib.sha256(path.read_bytes()).hexdigest()==digest,"Source changed"
        pe=pefile.PE(str(path));pes[name]=pe
        index=json.loads((ROOT/"analysis/functions/rom"/(name+".json")).read_text(encoding="utf-8"))
        funcs={int(f["begin_va"],16):f for f in index["functions"]}
        addresses=set(FUNCTIONS[name]);ranges=[]
        if name=="rapisrv.exe":
            raw=pe.get_data(0x110f8-pe.OPTIONAL_HEADER.ImageBase,86*4)
            table=struct.unpack("<86I",raw)
            assert table[5]==0x16c68 and table[0x19]==0x13acc and table[0x27]==0x1508c
            assert table[0x45]==0x1a60c and table[0x55]==0x179e0
            addresses.update(table);ranges.append((0x110f8,len(raw),"Original 86-slot RAPI command table"))
            text=(ROOT/"analysis/decompiled/rom/rapisrv.exe/decompiled.c").read_text(encoding="utf-8")
            blocks={int(b[3:11],16):b for b in re.split(r"(?=/\* [0-9a-f]{8} )",text)
                    if re.match(r"/\* [0-9a-f]{8} ",b)}
            for i,va in enumerate(table):
                block=blocks.get(va,"")
                calls=sorted(set(re.findall(r"\b([A-Z][A-Za-z0-9_]+)\(",block)))
                calls=[c for c in calls if not c.startswith(("FUN_","CONCAT","SUB_"))]
                commands.append(dict(slot=i,slot_hex=hex(i),target_va=hex(va),
                    api_call_candidates_from_pseudocode=calls,
                    caveat="Calls are evidence pointers, not a fully reviewed payload schema"))
        for va in sorted(addresses):
            assert va in funcs,hex(va)+" has no original boundary"
            ranges.append((va,int(funcs[va]["end_va"],16)-va,"Original .pdata function"))
        evidence=[]
        for va,size,role in ranges:
            raw=pe.get_data(va-pe.OPTIONAL_HEADER.ImageBase,size)
            assert len(raw)==size
            evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),
                                 sha256=hashlib.sha256(raw).hexdigest()))
        sources.append(dict(name=name,sha256=digest,evidence=evidence))
    reg=(ROOT/"analysis/firmware/boot-registry/default.validated.reg").read_text(encoding="utf-16")
    blocks=re.split(r"(?=\[HKEY)",reg)
    autoras=next(b for b in blocks if b.startswith("[HKEY_LOCAL_MACHINE\\Comm\\Autoras]"))
    assert '"Dialer"="rnaapp.exe"' in autoras and '"RasEntry"=' not in autoras
    frames=[dict(declared_length=n,payload_length=(n-4)&0xffffffff,
                 branch="reject" if n==0 else "read extra DWORD" if n==3 else "length minus four")
            for n in (0,1,2,3,4,8,1024)]
    auth=[]
    for chunks in ((2,),(1,1)):
        total=0;accepted=False
        for got in chunks:
            total+=got
            if got==2:accepted=True;break
        if not accepted:assert total==2
        auth.append(dict(recv_chunks=list(chunks),bytes_received=total,
                         length_loop_finishes=accepted,next_request_length=0 if total==2 and not accepted else None))
    udp_lengths=[dict(total=n,payload=(n-8)&0xffff,accepted_by_1024byte_receive_buffer=((n-8)&0xffff)+8<=1024)
                 for n in (0,1,7,8,9,1024,1025,65535)]
    assert [x["total"] for x in udp_lengths if x["accepted_by_1024byte_receive_buffer"]]==[8,9,1024]
    udp_config=[b for b in blocks if b.startswith("[HKEY_LOCAL_MACHINE\\Comm\\UDP2TCP")]
    assert len(udp_config)==2 and '"Port"=dword:00001d0e' in udp_config[0]
    result=dict(binary_execution=False,sources=sources,rapi_command_table_va="0x110f8",
        rapi_commands=commands,listener_port=990,address_filter_update=dict(message=0x4a,copydata_id=0x1f5,
            max_bytes_exclusive=33,resolver_service="5679"),
        autoras_registry=autoras,autoras_configured_entry_in_boot_registry=False,
        autoras_ioctl=dict(asynchronous=0x120800,synchronous=0x120804),
        autoras_message_bytes=8,message_types={"1":"dialer active","2":"dialer exited",
            "3":"disconnect/cancel timestamp","4":"notification event"},
        frame_length_models=frames,password_length_recv_models=auth,
        peer_binding=dict(producer="repllog.exe 0x1b568",authenticated_handshake="0x1bc58",
            default_name="ppp_peer",handshake_port=5679,ppp_registry="HKLM Comm\\Tcpip\\Hosts\\ppp_peer ipaddr REG_BINARY 4",
            ppp_ip_byte_swap=True),
        udp_proxy=dict(registry_blocks=udp_config,peer="ppp_peer",tcp_port=0x1d0e,udp_ports=[53],
            header_bytes=8,header_fields=["source port BE16","destination port BE16","total bytes BE16","two unwritten bytes"],
            max_udp_payload=1016,receive_ring_capacity=4096,reply_address="127.0.0.1",
            length_models=udp_lengths),
        unknown=["Actual repllog launch trigger on unit", "PPP and Unimodem negotiation", "Active host binding",
                 "Full schema for all 86 RAPI slots", "Runtime exposure and consequences of malformed lengths"])
    (ROOT/"analysis/firmware/remote-service-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    lines=["# RAPI-commandotabel uit de oorspronkelijke ROM","",
        "86 pointers vanaf VA 0x110f8 in rapisrv.exe. Alleen statische analyse.","",
        "De API-kolom bevat automatisch uit pseudocode verzamelde directe calls. Dat geeft onderzoekspointers; de complete payloadvoorwaarden en alle helpercalls zijn nog niet per slot beoordeeld. Speciale dispatch voor 45/46/47/48 staat in remote-service-contracts.md.","",
        "| Slot | Originele target-VA | Directe API-callkandidaten |","| --- | --- | --- |"]
    for command in commands:
        calls=[c for c in command["api_call_candidates_from_pseudocode"] if c not in ("GetLastError","SetLastError","LocalAlloc","LocalFree")]
        lines.append("| "+command["slot_hex"]+" | "+command["target_va"]+" | "+", ".join(calls)+" |")
    lines += ["", "Bronhash en oorspronkelijke bytes: [remote-service-contracts.json](firmware/remote-service-contracts.json). Reproduceer met `py tools/inspect_remote_services.py`."]
    (ROOT/"analysis/rapi-command-table.md").write_text("\n".join(lines)+"\n",encoding="utf-8")
    print(json.dumps(dict(source_modules=len(sources),evidence_ranges=sum(len(s["evidence"]) for s in sources),
        rapi_slots=len(commands),frame_models=len(frames),auth_models=len(auth)),indent=2))


if __name__=="__main__":main()
