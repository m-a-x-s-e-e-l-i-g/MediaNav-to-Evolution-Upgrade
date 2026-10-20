"""Verify the full iPhone candidate and execute its actual active GET bytes.

python tools/verify_cover_patches.py MAX31.lgu CANDIDATE.lgu [--version LABEL]
The optional version must match the patch command. Container hashes may vary
with compression; every payload member must match its expected size and hash.
"""
import argparse
import hashlib
import io
import json
from pathlib import Path
import struct
import sys
import urllib.request
import zipfile
import pefile
import lgu_repack as L
import patch_cover_final_packet as patch

ROOT = Path(__file__).resolve().parents[1]
MODEL = ROOT / 'releases/7.0.6.MAX10/build-sources'
sys.path[:0] = [str(ROOT/'tools'), str(MODEL/'model-tools'), str(MODEL/'workspace-tools')]
import bt_cover_art_responses as native
import bt_cover_art_client as host
import verify_bt_cover_responses as fixtures
from verify_media_responsiveness import call
from verify_usb_input_safety import relocated

BASE_URL = 'https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/download/7.0.6.MAX31/upgrade.lgu'
ACTIVE_GET = 0x31f600


def verify_blue(before, after):
    expected = patch.patch_blue(before)
    if after != expected:
        raise ValueError('Blue.exe differs from the exact six-instruction patch and checksum')
    for shift in (0, patch.COPY_SHIFT):
        for offset, _, _ in patch.EDITS:
            if after[offset+shift:offset+shift+4] != patch.NOP:
                raise ValueError('Missing validator instruction replacement')
    pe = pefile.PE(data=after)
    if pe.generate_checksum() != pe.OPTIONAL_HEADER.CheckSum:
        raise ValueError('Blue.exe PE checksum mismatch')


def verify_missing_edits(before, after):
    """A missing edit in either copy must fail even with a valid PE checksum."""
    cases = 0
    for shift in (0, patch.COPY_SHIFT):
        for offset, _, _ in patch.EDITS:
            at = offset+shift
            mutant = bytearray(after)
            mutant[at:at+4] = before[at:at+4]
            patch.fix_checksum(mutant)
            try:
                verify_blue(before, bytes(mutant))
            except ValueError:
                cases += 1
            else:
                raise AssertionError('Verifier accepted an omitted validator edit')
    return cases


def fixture_packets(before, after):
    """Execute preferred-base PE bytes; never assemble a replacement GET model."""
    f = fixtures
    img = bytes(range(256))*6
    first = f.packet(0x90, f.fixed(0xcb,f.CID)+f.fixed(0xc3,len(img))+f.sequence(0x48,img[:1000]))
    bad = 0xffffffff
    cases = [
        ('valid final', [first,f.packet(0xa0,f.sequence(0x49,img[1000:]))], [1,2],[1,2]),
        ('Body final', [first,f.packet(0xa0,f.sequence(0x48,img[1000:]))], [1,bad],[1,2]),
        ('declared size differs', [f.packet(0x90,f.fixed(0xcb,f.CID)+f.fixed(0xc3,len(img)+37)+f.sequence(0x48,img[:1000])),
            f.packet(0xa0,f.sequence(0x49,img[1000:]))], [1,bad],[1,2]),
        ('repeated length differs', [first,f.packet(0xa0,f.fixed(0xc3,len(img)+5)+f.sequence(0x49,img[1000:]))], [1,bad],[1,2]),
        ('wrong connection', [f.packet(0x90,f.fixed(0xcb,f.CID+1)+f.sequence(0x48,img[:1000]))], [bad],[bad]),
        ('error opcode', [f.packet(0xc4)], [bad],[bad]),
        ('oversize packet', [f.packet(0xa0,f.sequence(0x49,bytes(1025)))], [bad],[bad]),
        ('empty body', [f.packet(0xa0,f.sequence(0x49,b''))], [bad],[bad]),
        ('truncated header', [f.packet(0xa0,b'\x49\x00')], [bad],[bad]),
        ('oversize declaration', [f.packet(0x90,f.fixed(0xc3,host.MAX_IMAGE+1))], [bad],[bad]),
    ]
    traces = []
    saved_helpers = f.helpers
    try:
        for label,image in [('MAX31',before),('candidate',after)]:
            base = pefile.PE(data=image).OPTIONAL_HEADER.ImageBase
            for delta in (0,):
                pe = pefile.PE(data=relocated(image,delta) if delta else image)
                rows = [dict(address=va+delta,raw=pe.get_data(va-base,size))
                        for va,size in [(native.HEADER,0x400),(ACTIVE_GET,0x400)]]
                f.helpers = lambda: rows
                for name,packets,strict,patched in cases:
                    state = [f.BODY,host.MAX_IMAGE,0,0,0,0,f.CID,0]
                    body = b''
                    got = []
                    for packet in packets:
                        vm = f.VM(packet,state,body)
                        owned = vm.owned()
                        status = call(vm,ACTIVE_GET+delta,[f.OUTPUT,f.INPUT,len(packet)],limit=200000)
                        got.append(status)
                        vm.guards()
                        if status not in (1,2):
                            assert vm.owned()==owned, 'Rejected packet mutated context/body'
                            break
                        state = [f.BODY,host.MAX_IMAGE]+[vm.read(f.OUTPUT+o) for o in (8,12,16,20,24,28)]
                        body = f.data(vm,f.BODY,state[2])
                    assert got==(strict if label=='MAX31' else patched), (label,delta,name,got)
                    traces.append(dict(image=label,delta=hex(delta),case=name,statuses=got))
    finally:
        f.helpers = saved_helpers
    return traces


def verify_relocation_preservation(before, after):
    """The six relative-branch edits must not change any other rebased bytes.

    This is equivalence, not proof that the inherited image loads correctly at
    every base. MAX31's active clone retains an unrelocated HEADER call.
    """
    checksum = pefile.PE(data=before).OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    cases = 0
    for delta in (0,0x10000,0x120000):
        a = bytearray(relocated(before,delta) if delta else before)
        b = bytearray(relocated(after,delta) if delta else after)
        a[checksum:checksum+4] = b[checksum:checksum+4] = bytes(4)
        for shift in (0,patch.COPY_SHIFT):
            for offset,_,_ in patch.EDITS:
                at = offset+shift
                assert b[at:at+4]==patch.NOP
                b[at:at+4] = a[at:at+4]
        assert a==b, 'Unexpected change under the inherited base relocation table'
        cases += 1
    return cases


def verify(published, candidate, version=None):
    if patch.sha(published)!=patch.BASE_SHA:
        raise ValueError('Source is not the exact published MAX31 LGU')
    if version is not None:
        L.version_bytes(version)
    with zipfile.ZipFile(io.BytesIO(L.unpack(published))) as baseline:
        before = L.read_member(baseline,patch.BLUE)
    manifest = json.loads((ROOT/'releases/7.0.6.MAX31/build-manifest.json').read_bytes())
    assert manifest['container_verification']['lgu_sha256']==patch.BASE_SHA
    expected = {r['path']:(r['bytes'],r['sha256']) for r in manifest['container_verification']['members']}
    assert len(expected)==1920
    expected[patch.BLUE] = (len(before),patch.PATCHED_BLUE_SHA)
    if version is not None:
        data = L.version_bytes(version)
        expected[patch.VER] = (len(data),patch.sha(data))
    label = candidate[0x2dc:0x304].decode('utf-16le').split('\0')[0]
    if label!=(version or patch.BASE_VERSION):
        raise ValueError('Candidate version label differs from requested version')
    header = bytearray(published[:1024])
    header[12:20] = candidate[12:20]
    header[24:28] = candidate[24:28]
    if version is not None:
        header[0x2dc:0x304] = (version.encode('utf-16le')+b'\0\0').ljust(0x28,b'\xfe')
    if bytes(header)!=candidate[:1024]:
        raise ValueError('Unexpected LGU header changes')
    with zipfile.ZipFile(io.BytesIO(L.unpack(candidate))) as archive:
        members = L.zip_index(archive)
        if set(members)!=set(expected):
            raise ValueError('Candidate does not retain the complete MAX31 payload')
        after = b''
        for count,(name,info) in enumerate(members.items(),1):
            digest = hashlib.sha256()
            size = 0
            chunks = []
            with archive.open(info,pwd=L.PW) as source:
                while block:=source.read(1024*1024):
                    size += len(block)
                    digest.update(block)
                    if name==patch.BLUE:
                        chunks.append(block)
            if (size,digest.hexdigest())!=expected[name]:
                raise ValueError(f'Unexpected payload bytes: {name}')
            if name==patch.BLUE:
                after = b''.join(chunks)
            if count%250==0:
                print(f'Checked {count}/1920 payload members',flush=True)
    verify_blue(before,after)
    traces = fixture_packets(before,after)
    return dict(passed=True,members=1920,changed_members=[patch.BLUE]+([patch.VER] if version else []),
                base_sha256=patch.BASE_SHA,candidate_sha256=patch.sha(candidate),blue_sha256=patch.sha(after),
                missing_edit_negative_cases=verify_missing_edits(before,after),
                actual_written_packet_cases=len(traces),packet_traces=traces,
                relocation_preservation_cases=verify_relocation_preservation(before,after),
                full_rebased_execution_verified=False,
                inherited_limit='MAX31 active GET clone has an unrelocated HEADER call; unchanged by this patch.',
                physical_test=False,firmware_executed=False)


def prepare_input(path):
    if path.exists():
        if patch.sha(path.read_bytes())!=patch.BASE_SHA:
            raise ValueError('Existing baseline differs; it was not overwritten')
        return
    path.parent.mkdir(parents=True,exist_ok=True)
    with urllib.request.urlopen(BASE_URL,timeout=60) as response:
        raw = response.read()
    if patch.sha(raw)!=patch.BASE_SHA:
        raise ValueError('Downloaded baseline hash mismatch')
    with path.open('xb') as output:
        output.write(raw)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('published',type=Path,nargs='?')
    parser.add_argument('candidate',type=Path,nargs='?')
    parser.add_argument('--prepare-input',type=Path)
    parser.add_argument('--version')
    parser.add_argument('--report',type=Path)
    args = parser.parse_args()
    if args.prepare_input:
        prepare_input(args.prepare_input)
        return
    if not args.published or not args.candidate:
        parser.error('Provide the published and candidate LGU paths')
    result = verify(args.published.read_bytes(),args.candidate.read_bytes(),args.version)
    if args.report:
        args.report.parent.mkdir(parents=True,exist_ok=True)
        with args.report.open('x',encoding='utf-8') as output:
            json.dump(result,output,indent=2)
            output.write('\n')
    print(json.dumps({k:v for k,v in result.items() if k!='packet_traces'},indent=2))


if __name__=='__main__':
    main()
