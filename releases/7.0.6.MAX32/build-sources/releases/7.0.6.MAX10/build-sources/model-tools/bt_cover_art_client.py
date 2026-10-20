"""Transport-independent cover-art prototype. Not wired into Windows CE or AppMain.

One serialized event owner must supply discovered capabilities, ordered packets,
monotonic time and actual channel-close acknowledgement. No Bluetooth APIs run here.
"""
from dataclasses import dataclass
from io import BytesIO
import struct

TARGET = bytes.fromhex('7163dd544a7e11e2b47c0050c2490048')
MAX_IMAGE = 128*1024
MAX_PACKET = 1024


class ArtworkError(ValueError):
    """Fail only the artwork channel; caller retains audio and text metadata."""


class ReconnectRequired(ArtworkError):
    pass


@dataclass(frozen=True)
class Ticket:
    session: int
    request: int
    track: int


@dataclass(frozen=True)
class Request:
    ticket: Ticket
    packet: bytes


@dataclass(frozen=True)
class Received:
    next_request: Request | None = None
    cover: bytes | None = None
    stale: bool = False


def valid_handle(handle):
    return isinstance(handle, str) and len(handle) == 7 and all('0' <= c <= '9' for c in handle)


def parse_cover_attribute(parameters):
    """Parse reassembled GetElementAttributes response parameters, not CSR message structs."""
    if not parameters:
        raise ArtworkError('Missing attribute count')
    offset, handle, seen = 1, None, set()
    for _ in range(parameters[0]):
        if offset+8 > len(parameters):
            raise ArtworkError('Truncated attribute header')
        attribute, charset, length = struct.unpack_from('>IHH', parameters, offset)
        offset += 8
        if attribute in seen or offset+length > len(parameters):
            raise ArtworkError('Duplicate or truncated attribute')
        seen.add(attribute)
        raw = parameters[offset:offset+length]
        offset += length
        if attribute == 8:
            # BIP handles are ASCII digits; accept ASCII and UTF-8 character sets.
            if charset not in (3, 106) or len(raw) != 7 or any(c < 48 or c > 57 for c in raw):
                raise ArtworkError('Invalid cover handle or character set')
            handle = raw.decode('ascii')
    if offset != len(parameters):
        raise ArtworkError('Unexpected trailing attribute data')
    return handle


def cover_attribute_request():
    """GetElementAttributes parameters for the current element and attribute 8 only."""
    return bytes(8)+b'\x01'+struct.pack('>I', 8)


def _sequence(header, raw):
    return bytes([header])+struct.pack('>H', len(raw)+3)+raw


def _packet(opcode, raw):
    return bytes([opcode])+struct.pack('>H', len(raw)+3)+raw


def connect_request():
    return _packet(0x80, b'\x15\x00'+struct.pack('>H', MAX_PACKET)+_sequence(0x46, TARGET))


def thumbnail_request(connection_id, handle, peer_mtu):
    if not valid_handle(handle):
        raise ArtworkError('Invalid image handle')
    raw = (b'\xcb'+struct.pack('>I', connection_id)+_sequence(0x42, b'x-bt/img-thm\0')
           +_sequence(0x30, (handle+'\0').encode('utf-16-be')))
    packet = _packet(0x83, raw)
    if len(packet) > peer_mtu:
        raise ArtworkError('Request exceeds peer packet limit')
    return packet


def headers(packet, prefix=3):
    if len(packet) < prefix or len(packet) > MAX_PACKET or int.from_bytes(packet[1:3], 'big') != len(packet):
        raise ArtworkError('Invalid OBEX packet size')
    result, offset = [], prefix
    while offset < len(packet):
        header = packet[offset]
        kind = header >> 6
        if kind < 2:
            if offset+3 > len(packet):
                raise ArtworkError('Truncated OBEX header')
            size = int.from_bytes(packet[offset+1:offset+3], 'big')
            if size < 3 or offset+size > len(packet):
                raise ArtworkError('Invalid OBEX header size')
            value = packet[offset+3:offset+size]
            if kind == 0 and value and (len(value)&1 or value[-2:] != b'\0\0'):
                raise ArtworkError('Invalid Unicode header')
        else:
            size = 2 if kind == 2 else 5
            if offset+size > len(packet):
                raise ArtworkError('Truncated fixed OBEX header')
            value = packet[offset+1:offset+size]
        result.append((header, value))
        offset += size
    return result


def decode_thumbnail(raw):
    """Host decoder check only. Native integration must decode before publication too."""
    from PIL import Image
    with Image.open(BytesIO(raw)) as image:
        if image.format != 'JPEG' or image.size != (200, 200) or image.info.get('progressive'):
            raise ArtworkError('Expected a baseline 200x200 JPEG thumbnail')
        image.verify()
    with Image.open(BytesIO(raw)) as image:
        image.load()


class CoverArtClient:
    def __init__(self, decoder=decode_thumbnail):
        self.decoder = decoder
        self.session = 0
        self.state = 'off'
        self.needs_transport_close = False
        self.cover = None
        self.active = None
        self.identity = None
        self.request = self.track = 0
        self.body = bytearray()
        self.frames = 0
        self.declared_size = None
        self.deadline = 0

    def disconnect(self):
        self.needs_transport_close |= self.state != 'off'
        self.session += 1
        self.state, self.active, self.identity, self.cover = 'off', None, None, None
        self.body.clear()
        self.request = self.track = self.frames = 0
        self.declared_size = None

    def transport_closed(self):
        if self.state != 'off':
            self.disconnect()
        self.needs_transport_close = False

    def invalidate_uids(self):
        self.disconnect()

    def connect(self, version, features, psm, now):
        if self.state != 'off' or self.needs_transport_close:
            raise ReconnectRequired('Close the old artwork transport before reconnecting')
        if version < 0x106 or not features & 0x100 or not 0 < psm <= 0xffff or psm & 0x101 != 1:
            raise ArtworkError('Remote cover-art service not supported or PSM invalid')
        self.session += 1
        self.request += 1
        self.active = Ticket(self.session, self.request, 0)
        self.state, self.deadline = 'connect', now+2
        return Request(self.active, connect_request())

    def select_track(self, uid, uid_counter, handle, now):
        identity = (uid, uid_counter, handle)
        if not isinstance(uid, bytes) or len(uid) != 8 or uid == bytes([255])*8 or not 0 <= uid_counter <= 0xffff or not valid_handle(handle):
            self.disconnect()
            raise ArtworkError('Unavailable or invalid track artwork identity')
        if identity == self.identity:
            return None
        self.cover = None
        if self.identity is not None and uid_counter != self.identity[1]:
            self.disconnect()
            raise ReconnectRequired('UID generation changed; refresh the artwork session and metadata')
        if self.state != 'ready':
            self.disconnect()
            raise ReconnectRequired('Cancel the old artwork channel before requesting a new track')
        self.identity = identity
        self.track += 1
        self.request += 1
        self.active = Ticket(self.session, self.request, self.track)
        self.body.clear()
        self.declared_size, self.frames = None, 0
        self.state, self.deadline = 'get', now+10
        return Request(self.active, thumbnail_request(self.connection_id, handle, self.peer_mtu))

    def expire(self, now):
        if self.active is not None and now >= self.deadline:
            self.disconnect()
            return True
        return False

    def receive(self, ticket, packet, now):
        if not isinstance(ticket, Ticket) or self.active is None or ticket != self.active or ticket.session != self.session:
            return Received(stale=True)
        try:
            if self.expire(now):
                raise ArtworkError('Artwork request expired')
            if self.state == 'connect':
                rows = headers(packet, 7)
                if packet[0] != 0xa0 or packet[3] < 0x15 or packet[4] != 0:
                    raise ArtworkError('OBEX connection refused or unsupported')
                self.peer_mtu = int.from_bytes(packet[5:7], 'big')
                if self.peer_mtu < 255:
                    raise ArtworkError('OBEX peer packet limit too small')
                ids, who = [v for h, v in rows if h == 0xcb], [v for h, v in rows if h == 0x4a]
                if len(ids) != 1 or len(who) > 1 or who and who[0] != TARGET:
                    raise ArtworkError('Invalid artwork connection identity')
                self.connection_id = int.from_bytes(ids[0], 'big')
                self.active, self.state = None, 'ready'
                return Received()
            rows = headers(packet)
            if self.state != 'get' or packet[0] not in (0x90, 0xa0):
                raise ArtworkError('Artwork GET failed')
            self.frames += 1
            if self.frames > 1024:
                raise ArtworkError('Artwork response budget exceeded')
            chunks, ended = [], False
            if sum(h == 0xcb for h, _ in rows) > 1:
                raise ArtworkError('Duplicate artwork connection ID')
            for header, value in rows:
                if header == 0xcb and int.from_bytes(value, 'big') != self.connection_id:
                    raise ArtworkError('Artwork connection ID changed')
                if header == 0xc3:
                    length = int.from_bytes(value, 'big')
                    if length > MAX_IMAGE or self.declared_size is not None and length != self.declared_size:
                        raise ArtworkError('Invalid artwork length')
                    self.declared_size = length
                if header in (0x48, 0x49):
                    if ended:
                        raise ArtworkError('Body after EndOfBody')
                    ended = header == 0x49
                    chunks.append(value)
            if ended != (packet[0] == 0xa0):
                raise ArtworkError('Missing or premature EndOfBody')
            if len(self.body)+sum(map(len, chunks)) > MAX_IMAGE:
                raise ArtworkError('Artwork exceeds memory limit')
            for chunk in chunks:
                self.body.extend(chunk)
            if packet[0] == 0x90:
                return Received(next_request=Request(self.active, _packet(0x83, b'\xcb'+struct.pack('>I', self.connection_id))))
            raw = bytes(self.body)
            if not raw or self.declared_size is not None and len(raw) != self.declared_size:
                raise ArtworkError('Incomplete artwork')
            self.decoder(raw)
            self.body.clear()
            self.cover, self.active, self.state = raw, None, 'ready'
            return Received(cover=raw)
        except Exception as error:
            self.disconnect()
            if isinstance(error, ArtworkError):
                raise
            raise ArtworkError('Artwork decode failed') from error
