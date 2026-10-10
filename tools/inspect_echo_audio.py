"""Inspect static echo-canceller audio contracts and SSE parameter metadata."""
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]


def trunc_average(a,b):
    total=a+b
    return (total+(1 if total<0 else 0))>>1


def interpolate_six(a,b):
    middle=trunc_average(a,b)
    quarter=trunc_average(middle,a)
    eighth=trunc_average(quarter,a)
    three_quarter=trunc_average(b,middle)
    five_eighth=trunc_average(three_quarter,middle)
    return [a,eighth,quarter,middle,five_eighth,three_quarter]


def recording_header(blocks):
    """Offline model of the 46-byte, 18-byte-fmt WAV header; no file writes."""
    size=(blocks*0x400)&0xffffffff
    fmt=struct.pack("<HHIIHHH",1,1,8000,16000,2,16,0)
    return b"RIFF"+struct.pack("<I",(size+0x26)&0xffffffff)+b"WAVEfmt "+struct.pack("<I",18)+fmt+b"data"+struct.pack("<I",size)


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    evidence=[]
    sources={}
    pes={}
    for name,ranges in [
        ("EchoCanceller.dll",[(0x10001000,0x10002874),(0x10002874,0x1000325c),
                              (0x1000325c,0x10003bf4),(0x10003bf4,0x100055c0),
                              (0x10006084,0x1000608c),
                              (0x10009148,0x10009150)]),
        ("sse_int.dll",[(0x1001618c,0x100161d4),(0x10022554,0x100226bc),
                        (0x10017928,0x100179e4),(0x10021340,0x100219f8),(0x100228a8,0x10022ee8),
                        (0x10023f48,0x10023fa0),(0x10024b24,0x10024b88),
                        (0x10025460,0x100256cc),(0x10025d7c,0x10026b7c),
                        (0x10026ecc,0x10027a9c),(0x10027b34,0x10028ef4),
                        (0x1002910c,0x100292ac),(0x100293c0,0x1002999c),
                        (0x10023528,0x100236b8),(0x100638a0,0x100638b0),(0x1006a2f0,0x1006a336),
                        (0x100660b0,0x100660b0+382*44)]),
        ("MicomManager.exe",[(0x11904,0x11cdc)])]:
        m=next(x for x in modules if x["origin"]=="705md" and x["name"]==name)
        path=ROOT/m["path"]
        digest=hashlib.sha256(path.read_bytes()).hexdigest()
        if digest!=m["sha256"]:
            raise ValueError("Source changed from inventory")
        sources[name]=digest
        pe=pefile.PE(str(path));pes[name]=pe
        for start,end in ranges:
            raw=pe.get_data(start-pe.OPTIONAL_HEADER.ImageBase,end-start)
            if len(raw)!=end-start:
                raise ValueError("Incomplete evidence range")
            evidence.append(dict(module=name,start_va=hex(start),end_va_exclusive=hex(end),
                                 raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    pe=pes["sse_int.dll"];base=pe.OPTIONAL_HEADER.ImageBase
    # Lookup reads IDs at +32 of each record, not the beginning of a record.
    # Starting at 0x660d0 pairs an ID with the *following* record's name.
    raw=pe.get_data(0x100660b0-base,382*44)
    type_widths=struct.unpack("<35H",pe.get_data(0x1006a2f0-base,70))
    parameters=[]
    for i in range(382):
        record=raw[i*44:(i+1)*44]
        id_,datatype=struct.unpack_from("<2I",record,32)
        name=record[:32].split(b"\0")[0].decode("ascii")
        if datatype>=len(type_widths):
            raise ValueError("Unexpected parameter datatype")
        parameters.append(dict(index=i,id=hex(id_),datatype_raw=datatype,
                               type_width_bytes=type_widths[datatype],
                               count_word=struct.unpack_from("<H",record,40)[0],
                               byte_42=record[42],access_mode_byte_43=record[43],name=name,
                               raw_hex=record.hex()))
    if len({x["id"]for x in parameters})!=382:
        raise ValueError("Unexpected duplicate parameter IDs")
    expected={3:"sse_MicInCnt",4:"sse_RecvInCnt",9:"sse_NRSwitch",10:"sse_AECSwitch",
              12:"sse_RAESwitch",30:"sse_FrameShift",31:"sse_SampleRate",39:"sse_RECVAgcSwitch"}
    for id_,name in expected.items():
        if next(x["name"]for x in parameters if int(x["id"],16)==id_)!=name:
            raise ValueError("Parameter ID/name alignment mismatch")
    ep=pes["EchoCanceller.dll"];eb=ep.OPTIONAL_HEADER.ImageBase
    pointers=struct.unpack("<2I",ep.get_data(0x10009148-eb,8))
    config_paths=[ep.get_data(p-eb,160).split(b"\0")[0].decode("ascii")for p in pointers]
    result=dict(source_hashes=sources,evidence=evidence,
                wrapper_version="5.1.6.2014",sse_version=struct.unpack("<4I",pe.get_data(0x100638a0-base,16)),
                config_paths=config_paths,available_bsd_files=[str(p.relative_to(ROOT))for p in (ROOT/"extracted").rglob("*.bsd")],
                formats=dict(bt=dict(device_id=1,channels=1,rate_hz=8000,bits=16,block_bytes=1024),
                             hf=dict(device_id=0,channels=1,rate_hz=48000,bits=16,block_bytes=6144)),
                buffer_count_per_stream=4,frame_duration_ms=64,sse_calls_per_frame=4,
                recording=dict(rate_hz=8000,bits=16,channels=1,block_bytes=1024,header_bytes=46,
                               empty_header_hex=recording_header(0).hex()),
                debug_listener=dict(socket_type="TCP/IPv4",bind_address="0.0.0.0",port=2012,listen_backlog=5,
                                    input_slots=10,input_slot_capacity=256,output_slots=10,output_slot_capacity=1024),
                parameter_table_va="0x100660b0",parameter_record_stride=44,
                parameter_record_layout=dict(name_ascii=[0,32],id_dword=32,datatype_dword=36,
                                             count_word=40,metadata_byte=42,access_mode_byte=43),
                datatype_widths_bytes=type_widths,parameters=parameters,
                switch_values={"1":"sseOff","2":"sseOn","3":"sseDisabled"},
                wrapper_parameters=[dict(id=id_,name=expected[id_],value=(128 if id_==30 else 8000 if id_==31 else 2 if id_ in (9,10,12,39) else "signed-short channel argument"))for id_ in expected],
                wrapper_parameter_ids=[3,4,9,10,12,30,31,39],
                open_points=["All SSE DSP routines and BSD parser semantics", "ROM wave-driver and hardware endpoint mapping",
                             "Actual BSD configs/unit audio measurements", "All recording thread shutdown and refresh races",
                             "Network availability and lifetime on the actual unit"])
    (ROOT/"analysis/firmware/echo-audio-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps({k:result[k]for k in ("config_paths","available_bsd_files","formats","sse_version","debug_listener")},indent=2))
    print(json.dumps([x for x in parameters if int(x["id"],16)in result["wrapper_parameter_ids"]],indent=2))


if __name__=="__main__":main()
