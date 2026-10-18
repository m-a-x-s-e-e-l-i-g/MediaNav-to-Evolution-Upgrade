"""Strict, offline NNG RL bitmap reader and palette-only recoloring.

Format 0/1 layout reference: BGRABitmap bgrareadbmpmiomap.pas (LGPL).
https://github.com/bgrabitmap/bgrabitmap/blob/master/bgrabitmap/bgrareadbmpmiomap.pas
This independent implementation does not contain that library's source.
Format bit 2's per-chunk palette reset is inferred from the supplied 4.1.0
archive: all 1,053 RL images decode with exact pixel counts and valid indices.
Recoloring preserves every header, alpha byte, chunk length and RLE opcode.
"""
from dataclasses import dataclass
import struct


def rgb565(value):
    return ((value >> 11) * 255 // 31,
            ((value >> 5) & 63) * 255 // 63,
            (value & 31) * 255 // 31)


def pack565(rgb):
    r, g, b = rgb
    return ((r * 31 + 127) // 255 << 11) | ((g * 63 + 127) // 255 << 5) | ((b * 31 + 127) // 255)


@dataclass
class Bitmap:
    raw: bytes
    flags: int
    width: int
    height: int
    palette: list
    alpha: bytes
    indices: list
    chunks: list

    def image(self):
        from PIL import Image
        colors = [(*rgb565(c), 0 if c == 0xf81f else
                   (self.alpha[i] * 255 // 32 if self.flags & 1 else 255))
                  for i, c in enumerate(self.palette)]
        image = Image.new('RGBA', (self.width, self.height))
        image.putdata([colors[i] for i in self.indices])
        return image

    def recolor(self, transform):
        """Transform palette RGB only. Transparent keys stay exact."""
        output = bytearray(self.raw)
        for i, color in enumerate(self.palette):
            if color == 0xf81f:
                continue
            target = pack565(transform(rgb565(color), i))
            if target == 0xf81f:
                raise ValueError('Recoloring would introduce a transparent key')
            struct.pack_into('<H', output, 12 + 2 * i, target)
        result = decode(bytes(output))
        assert result.indices == self.indices and result.alpha == self.alpha
        assert result.raw[:12] == self.raw[:12]
        assert result.raw[12 + 2 * len(self.palette):] == self.raw[12 + 2 * len(self.palette):]
        assert result.image().getchannel('A').tobytes() == self.image().getchannel('A').tobytes()
        return bytes(output)


def decode(raw):
    if len(raw) < 12 or raw[:2] != b'RL':
        raise ValueError('Not an RL bitmap')
    flags, width, height, count, chunks = struct.unpack_from('<5H', raw, 2)
    if flags not in range(4) or not width or not height or not count or not chunks:
        raise ValueError('Invalid RL header')
    position = 12 + count * 2
    if position > len(raw):
        raise ValueError('Truncated palette')
    palette = list(struct.unpack_from(f'<{count}H', raw, 12))
    alpha = raw[position:position + count] if flags & 1 else b''
    if flags & 1:
        if len(alpha) != count or any(a > 32 for a in alpha):
            raise ValueError('Invalid RL alpha palette')
        position += count
    lengths = []
    for _ in range(chunks):
        if position >= len(raw):
            raise ValueError('Truncated chunk table')
        size = raw[position]
        position += 1
        if size == 255:
            if position + 2 > len(raw):
                raise ValueError('Truncated extended chunk length')
            size = int.from_bytes(raw[position:position + 2], 'big')
            position += 2
        lengths.append(size)
    if position + sum(lengths) != len(raw):
        raise ValueError('Chunk table does not cover exact file')
    indices = []
    offset = 0
    decoded_chunks = []
    for length in lengths:
        end = position + length
        start_pixels = len(indices)
        if flags & 2:
            offset = 0
        while position < end:
            code = raw[position]
            position += 1
            repeat = 1
            if code == 253:
                if position + 2 > end:
                    raise ValueError('Truncated palette offset')
                offset = int.from_bytes(raw[position:position + 2], 'little')
                position += 2
                continue
            if code == 254:
                if position + 2 > end:
                    raise ValueError('Truncated repeat')
                index, repeat = raw[position] + offset, raw[position + 1]
                position += 2
            elif code == 255:
                if position >= end:
                    raise ValueError('Truncated zero repeat')
                index, repeat = 0, raw[position]
                position += 1
            else:
                index = 0 if code == 0 else code + offset
            if index >= count or not repeat or len(indices) + repeat > width * height:
                raise ValueError('Invalid palette index or pixel count')
            indices.extend([index] * repeat)
        decoded_chunks.append(len(indices) - start_pixels)
    if len(indices) != width * height:
        raise ValueError('Incorrect decoded pixel count')
    return Bitmap(raw, flags, width, height, palette, alpha, indices, decoded_chunks)


def encode_like(source, image):
    """Encode RGB565/alpha with the original flags, size and chunk pixel spans.

    Palette and run bytes may change; the original format, transparent pixel
    coverage and native strip geometry must remain exact.
    """
    if image.mode != 'RGBA' or image.size != (source.width, source.height):
        raise ValueError('Image geometry/mode changed')
    if image.getchannel('A').tobytes() != source.image().getchannel('A').tobytes():
        raise ValueError('Original pixel transparency must be preserved')
    keys = []
    lookup = {}
    indices = []
    for r, g, b, a in image.get_flattened_data():
        color = 0xf81f if a == 0 else pack565((r, g, b))
        if color == 0xf81f and a:
            raise ValueError('Opaque transparent-key color')
        alpha = (a * 32 + 127) // 255 if source.flags & 1 else 32
        if source.flags & 1 and alpha * 255 // 32 != a:
            raise ValueError('Unrepresentable alpha')
        key = (color, alpha)
        if key not in lookup:
            lookup[key] = len(keys)
            keys.append(key)
        indices.append(lookup[key])
    if len(keys) > 65535:
        raise ValueError('Palette exceeds RL header capacity')
    chunks = []
    offset = 0
    position = 0
    for span in source.chunks:
        end = position + span
        if source.flags & 2:
            offset = 0
        encoded = bytearray()
        while position < end:
            index = indices[position]
            run = 1
            while run < 255 and position + run < end and indices[position + run] == index:
                run += 1
            if index == 0:
                encoded.extend((255, run) if run >= 2 else (0,))
            else:
                relative = index - offset
                if not 1 <= relative <= 252:
                    offset = index - 1
                    encoded.extend((253, offset & 255, offset >> 8))
                    relative = 1
                if run >= 3:
                    encoded.extend((254, relative, run))
                else:
                    encoded.extend([relative] * run)
            position += run
        if len(encoded) > 65535:
            raise ValueError('RL chunk exceeds length capacity')
        chunks.append(bytes(encoded))
    header = b'RL' + struct.pack('<5H', source.flags, source.width, source.height, len(keys), len(chunks))
    palette = b''.join(struct.pack('<H', k[0]) for k in keys)
    alpha = bytes(k[1] for k in keys) if source.flags & 1 else b''
    sizes = b''.join(bytes([len(c)]) if len(c) < 255 else b'\xff' + len(c).to_bytes(2, 'big') for c in chunks)
    result = header + palette + alpha + sizes + b''.join(chunks)
    written = decode(result)
    assert written.flags == source.flags and written.chunks == source.chunks
    assert written.image().getchannel('A').tobytes() == image.getchannel('A').tobytes()
    return result
