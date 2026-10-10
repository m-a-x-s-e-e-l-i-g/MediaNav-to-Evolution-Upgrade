"""Preserve original MPPC code/table and verify offline token models."""
import hashlib
import json
import struct
from pathlib import Path
import pefile
from parse_mppc import self_test

ROOT=Path(__file__).resolve().parents[1]
HASH="b5f6bd4f0d8295e9203b3f92bd23a2920ecc086804f76caadb2e18d9e6d05df5"


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module=next(m for m in modules if m["origin"]=="rom" and m["name"]=="ppp.dll")
    path=ROOT/module["path"]; assert hashlib.sha256(path.read_bytes()).hexdigest()==HASH
    pe=pefile.PE(str(path)); base=pe.OPTIONAL_HEADER.ImageBase
    ranges=[(0xc044065c,0xa7c,"MPPC compressor"),(0xc04410d8,0x48,"Compressor reset"),
            (0xc0441120,0x24,"Decompressor reset"),(0xc0441144,0x798,"MPPC decompressor"),
            (0xc0431f50,1024,"256-DWORD three-byte hash table")]
    evidence=[]
    for va,size,role in ranges:
        raw=pe.get_data(va-base,size); assert len(raw)==size
        evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    table=struct.unpack("<256I",pe.get_data(0xc0431f50-base,1024))
    assert all(value==i*0x9ccf93 for i,value in enumerate(table))
    checks=self_test()
    result=dict(binary_execution=False,module=module["path"],sha256=HASH,evidence=evidence,
        reference="https://www.rfc-editor.org/rfc/rfc2118.html",checks=checks,
        hash_table_multiplier=hex(0x9ccf93),history_bytes=8192,
        limits=dict(standard_match_max=8191,vendor_decoder_match_max=2047,source_wrap="initial pointer masked; copy then linear",
                    tuple_output_guard="end strictly below history+8192",literal_output_guard="none observed in original decoder"),
        original_findings=["Decoder preloads two bytes with no local input minimum",
                           "Token-refill reads occur before the outer consumed-length check",
                           "Vendor compressor emits long length prefixes absent from vendor decoder",
                           "Original literal path has no history-end guard; safe offline parser adds one"],
        limitations=["Token model, not exact emulation of compressor hash-match choices or decoder bit-refill behavior",
                     "No unit capture and no execution of native MIPS instructions"])
    (ROOT/"analysis/firmware/mppc-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",preserved_ranges=len(evidence),hash_entries=len(table),**{k:v for k,v in checks.items() if isinstance(v,int)}),indent=2))


if __name__=="__main__": main()
