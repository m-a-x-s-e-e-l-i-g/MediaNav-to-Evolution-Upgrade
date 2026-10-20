"""Build an offline USB-boot recovery candidate, without flashing any device.

Only redirect the existing ROM launcher strings to Explorer. This is not an
LGU, bootloader installer, clean install, or proof of compatible USB boot.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

SOURCE_SHA = '8b2bd9944565f2b9ec2af6e2e1f0aa8620db9456c4b36329a140f70835db6de1'
TARGET = r'\Windows\explorer.exe'
OLD_PATHS = (r'\Storage Card\System\dboot.exe',
             r'\Storage Card\System\UpgradeManager.exe')


def parse(data):
    if data[:7] != b'B000FF\n' or len(data) < 27:
        raise ValueError('Not a CE B000FF image')
    start, size = struct.unpack_from('<II', data, 7)
    pos, rows = 15, []
    while pos + 12 <= len(data):
        header = pos
        address, length, checksum = struct.unpack_from('<III', data, pos)
        pos += 12
        if address == 0:
            if pos != len(data) or checksum != 0 or not rows:
                raise ValueError('Unexpected terminal or trailing bytes')
            return dict(start=start, size=size, launch=length, records=rows)
        if not length or pos + length > len(data):
            raise ValueError('Invalid record length')
        if sum(data[pos:pos + length]) & 0xffffffff != checksum:
            raise ValueError('Invalid record checksum')
        if not start <= address < address + length <= start + size:
            raise ValueError('Record outside declared image')
        if any(address < r['address'] + r['length'] and r['address'] < address + length for r in rows):
            raise ValueError('Overlapping image records')
        rows.append(dict(header=header, offset=pos, address=address, length=length))
        pos += length
    raise ValueError('Missing terminal')


def read_va(data, image, address, size):
    for r in image['records']:
        if r['address'] <= address <= address + size <= r['address'] + r['length']:
            off = r['offset'] + address - r['address']
            return data[off:off + size]
    raise ValueError('Read crosses an absent record')


def launcher_objects(data, image):
    header = struct.unpack('<I', read_va(data, image, image['start'] + 0x44, 4))[0]
    rom = struct.unpack('<17I2HI2I', read_va(data, image, header, 84))
    names = []
    for n in range(rom[4]):
        toc = struct.unpack('<8I', read_va(data, image, header + 84 + n * 32, 32))
        name_bytes = bytearray()
        for k in range(256):
            value = read_va(data, image, toc[4] + k, 1)
            if value == b'\0':
                break
            name_bytes.extend(value)
        else:
            raise ValueError('Unterminated ROM module name')
        name = name_bytes.decode('ascii')
        names.append(name)
        if name.lower() == 'ulc_launcher.exe':
            count = struct.unpack('<H', read_va(data, image, toc[5], 2))[0]
            objects = [struct.unpack('<6I', read_va(data, image, toc[6] + j * 24, 24)) for j in range(count)]
            result = objects
    if names.count('ULC_launcher.exe') != 1 or not any(x.lower() == 'explorer.exe' for x in names):
        raise ValueError('Missing unique launcher or ROM Explorer')
    return result


def build(data):
    if hashlib.sha256(data).hexdigest() != SOURCE_SHA:
        raise ValueError('Unrecognized source NK; no patch applied')
    image = parse(data)
    objects = launcher_objects(data, image)
    out, edits, changed = bytearray(data), [], set()
    for path in OLD_PATHS:
        old = (path + '\0').encode('utf-16-le')
        if data.count(old) != 1:
            raise ValueError('Expected exactly one original launcher path')
        off = data.index(old)
        r = next(r for r in image['records'] if r['offset'] <= off < off + len(old) <= r['offset'] + r['length'])
        va = r['address'] + off - r['offset']
        matches = [o for o in objects if o[3] <= va < va + len(old) <= o[3] + o[2] and not o[5] & 0x2000]
        if len(matches) != 1:
            raise ValueError('Path is not in unique uncompressed ROM launcher object')
        replacement = (TARGET + '\0').encode('utf-16-le')
        if len(replacement) > len(old):
            raise ValueError('Replacement exceeds original storage')
        out[off:off + len(old)] = replacement.ljust(len(old), b'\0')
        changed.add(r['header'])
        edits.append(dict(offset=off, rom_va=hex(va), before=path, after=TARGET, capacity=len(old)))
    for r in image['records']:
        if r['header'] in changed:
            checksum = sum(out[r['offset']:r['offset'] + r['length']]) & 0xffffffff
            struct.pack_into('<I', out, r['header'] + 8, checksum)
    assert parse(out) == image
    allowed = {i for e in edits for i in range(e['offset'], e['offset'] + e['capacity'])}
    allowed |= {h + j for h in changed for j in range(8, 12)}
    assert all(a == b or i in allowed for i, (a, b) in enumerate(zip(data, out)))
    return bytes(out), dict(source_sha256=SOURCE_SHA, output_sha256=hashlib.sha256(out).hexdigest(),
                           bytes=len(out), records=len(image['records']), edits=edits,
                           changed_record_headers=sorted(changed), image_layout_unchanged=True,
                           source_unchanged=True, native_device_tested=False)


def main():
    p = argparse.ArgumentParser()
    p.add_argument('source', type=Path)
    p.add_argument('output', type=Path)
    a = p.parse_args()
    data, manifest = build(a.source.read_bytes())
    a.output.mkdir(parents=True, exist_ok=False)
    (a.output / 'NK.bin').write_bytes(data)
    (a.output / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    print(json.dumps(manifest, indent=2))


if __name__ == '__main__':
    main()
