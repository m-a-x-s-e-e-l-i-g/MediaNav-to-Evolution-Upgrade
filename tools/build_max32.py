"""Build a complete MAX32 from public MAX31 with pinned Windows PC LGU tools."""
import argparse
import hashlib
import json
from pathlib import Path
import platform
import shutil
import struct
import subprocess
import sys
import time
from types import FunctionType
import pefile
import build_review_update as container
import lgu_repack
import patch_cover_final_packet as patch
import verify_cover_patches as cover

ROOT = Path(__file__).resolve().parents[1]
PRIOR = ROOT/'releases/7.0.6.MAX31'
REVISION = '7.0.6.MAX32'
CMN = 'upgrade/Storage Card/System/CmnDll.dll'


def sha(data):
    return hashlib.sha256(data).hexdigest()


def write(path, value):
    path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')


def tree(folder, expected):
    paths = {p.relative_to(folder).as_posix():p for p in folder.rglob('*') if p.is_file()}
    if set(paths)!=set(expected):
        raise ValueError('Full payload paths differ')
    for name,path in paths.items():
        raw = path.read_bytes()
        if (len(raw),sha(raw))!=(expected[name]['bytes'],expected[name]['sha256']):
            raise ValueError(f'Payload hash differs: {name}')


def pc(tool, args, log):
    start = time.monotonic()
    with log.open('xb') as output:
        result = subprocess.run([str(tool),*map(str,args)],cwd=ROOT,stdout=output,stderr=subprocess.STDOUT,
                                timeout=300,creationflags=getattr(subprocess,'CREATE_NO_WINDOW',0))
    if result.returncode:
        raise ValueError(f'PC tool failed: {log}')
    return dict(tool=tool.name,sha256=sha(tool.read_bytes()),arguments=list(map(str,args)),
                returncode=result.returncode,duration_seconds=round(time.monotonic()-start,3))


def diagnostic_revision(raw, runtime):
    pe = pefile.PE(data=raw)
    offset = pe.get_offset_from_rva(runtime['strings']['header']-pe.OPTIONAL_HEADER.ImageBase)
    before = '\ufeffMAXmade 7.0.6.MAX31 diagnostics'.encode('utf-16le')
    after = '\ufeffMAXmade 7.0.6.MAX32 diagnostics'.encode('utf-16le')
    if raw[offset:offset+len(before)]!=before or len(before)!=len(after):
        raise ValueError('Unexpected diagnostic revision header')
    new = bytearray(raw)
    new[offset:offset+len(after)] = after
    checksum = pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    struct.pack_into('<I',new,checksum,0)
    struct.pack_into('<I',new,checksum,pefile.PE(data=bytes(new)).generate_checksum())
    assert len(new)==len(raw)
    assert all(a==b or offset<=i<offset+len(before) or checksum<=i<checksum+4
               for i,(a,b) in enumerate(zip(raw,new)))
    assert pefile.PE(data=bytes(new)).verify_checksum()
    return bytes(new),dict(before_sha256=sha(raw),output_sha256=sha(new),
                           revision_only_from_MAX31=True,header_offset=offset,checksum_offset=checksum,
                           header_bytes=len(before))


def source_snapshots(out, prior):
    files = {}
    for name,digest in prior['source_pins'].items():
        source = PRIOR/'build-sources'/name
        assert sha(source.read_bytes())==digest,name
        files[name] = source
    current = {Path(__file__).resolve(),ROOT/'src/container/lgu0.json',
               ROOT/'tools/test_cover_package.py',ROOT/'tools/requirements-cover.txt',
               PRIOR/'build-manifest.json',PRIOR/'runtime.json',PRIOR/'boot-recovery-verification.json'}
    for module in tuple(sys.modules.values()):
        name = getattr(module,'__file__',None)
        if name:
            source = Path(name).resolve()
            if source.is_relative_to(ROOT) and source.suffix=='.py':
                current.add(source)
    overrides = []
    for source in current:
        name = source.relative_to(ROOT).as_posix()
        if name in files and sha(files[name].read_bytes())!=sha(source.read_bytes()):
            overrides.append(name)
        files[name] = source
    pins = {}
    for name,source in sorted(files.items()):
        target = out/'build-sources'/name
        target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(source,target)
        pins[name] = sha(target.read_bytes())
    return pins,sorted(overrides)


def build(baseline, tools, out):
    if out.exists():
        raise ValueError('Output already exists; choose a fresh build directory')
    if sha(baseline.read_bytes())!=patch.BASE_SHA:
        raise ValueError('Input is not the exact published MAX31 LGU')
    writer,extractor = (tools/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    if sha(writer.read_bytes())!=container.WRITER_HASH or sha(extractor.read_bytes())!=container.EXTRACTOR_HASH:
        raise ValueError('PC packing tools do not match their pinned hashes')
    prior = json.loads((PRIOR/'build-manifest.json').read_bytes())
    expected = {r['path']:dict(bytes=r['bytes'],sha256=r['sha256']) for r in prior['container_verification']['members']}
    before = dict(expected)
    assert len(before)==1920
    out.mkdir(parents=True)
    payload = out/'payload'
    extraction = pc(extractor,[baseline,payload],out/'baseline-extraction.log')
    tree(payload,before)
    print('Verified all 1,920 public MAX31 input members',flush=True)
    original_blue = (payload/patch.BLUE).read_bytes()
    blue = patch.patch_blue(original_blue)
    cover.verify_blue(original_blue,blue)
    runtime = json.loads((PRIOR/'runtime.json').read_bytes())
    cmn,cmn_record = diagnostic_revision((payload/CMN).read_bytes(),runtime)
    changed = {patch.BLUE:blue,CMN:cmn,patch.VER:REVISION.encode('ascii')}
    for name,raw in changed.items():
        (payload/name).write_bytes(raw)
        expected[name] = dict(bytes=len(raw),sha256=sha(raw))
    tree(payload,expected)
    traces = cover.fixture_packets(original_blue,blue)
    proof = dict(passed=True,actual_written_packet_cases=len(traces),packet_traces=traces,
                 missing_edit_negative_cases=cover.verify_missing_edits(original_blue,blue),
                 relocation_preservation_cases=cover.verify_relocation_preservation(original_blue,blue),
                 full_rebased_execution_verified=False,
                 inherited_limit='MAX31 active GET clone has an unrelocated HEADER call; unchanged.',
                 prior_payload_paths_retained=1920,exact_previous_members=1917,
                 unchanged_boot_updater_MCU_and_navigation=True,diagnostic_behavior_unchanged=True,
                 physical_test=False,firmware_executed=False)
    assert proof['actual_written_packet_cases']==20 and proof['missing_edit_negative_cases']==6
    assert proof['relocation_preservation_cases']==3
    write(out/'verification.json',proof)
    write(out/'CmnDll.dll.json',cmn_record)
    runtime['measurements_revision'] = 32
    write(out/'runtime.json',runtime)
    write(out/'member-plan.json',dict(member_count=1920,prior_paths_retained=1920,retained_members=1917,
          changed_members=sorted(changed),added_members=[],missing_members=[],
          members=[dict(path=n,before=before[n],after=expected[n]) for n in sorted(expected)]))
    writer_record = pc(writer,['-p','m1',REVISION,payload,out/'upgrade.lgu'],out/'dir2lgu.log')
    independent = FunctionType(container.verify_package.__code__,
                               dict(container.verify_package.__globals__,xor_key=lambda:lgu_repack.KEY))
    result = independent(out/'upgrade.lgu',expected,REVISION)
    extractor_record = pc(extractor,[out/'upgrade.lgu',out/'roundtrip'],out/'lgu2dir.log')
    tree(out/'roundtrip',expected)
    pins,overrides = source_snapshots(out,prior)
    manifest = dict(revision=REVISION,baseline_lgu_sha256=patch.BASE_SHA,previous_paths_retained=1920,
                    exact_previous_members=1917,changed_members=sorted(changed),added_members=[],missing_members=[],
                    baseline_extraction=extraction,writer=writer_record,extractor=extractor_record,
                    container_verification=result,byte_verification=proof,source_pins=pins,
                    inherited_source_overrides=overrides,car_tested=False,published=False,
                    runtime=dict(python=sys.version,platform=platform.platform()),
                    contributor_car_report='emstoica reports iPhone Spotify and Apple Music artwork working with the exact patched Blue.exe.',
                    complete_MAX32_car_test=False)
    write(out/'build-manifest.json',manifest)
    summary = dict(passed=True,revision=REVISION,lgu_bytes=result['bytes'],lgu_sha256=result['lgu_sha256'],
                   member_count=1920,exact_previous_members=1917,changed_members=sorted(changed),
                   source_pins=len(pins),independent_LGU_decode=True,independent_PC_roundtrip=True,
                   physical_test_pending=True)
    write(out/'package-verification.json',summary)
    print(json.dumps(summary,indent=2),flush=True)


if __name__=='__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline',type=Path,required=True)
    parser.add_argument('--tools-dir',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args = parser.parse_args()
    build(args.baseline.resolve(),args.tools_dir.resolve(),args.output.resolve())
