"""Integrated host session adapter: SDP -> channel -> current metadata -> JPEG.

Actions are explicit adapter boundaries, not native CSR or AppMain calls. All
methods and final publication checks require one serialized event owner.
"""
from dataclasses import dataclass

from bt_cover_art_client import ArtworkError, CoverArtClient, MAX_PACKET, cover_attribute_request, parse_cover_attribute


@dataclass(frozen=True)
class Capabilities:
    version: int
    features: int
    psm: int


@dataclass(frozen=True)
class Element:
    kind: int
    width: int
    value: object


def parse_service(raw):
    """One reassembled SDP attribute-list Data Element for the selected remote TG.

    Not a CSR linked-list node or complete SDP PDU; the native adapter must extract
    this bounded record before its original discovery callback frees the result.
    """
    if not raw or len(raw) > 4096:
        raise ArtworkError('SDP record size invalid')
    budget = [512]

    def element(offset, end, depth=0):
        budget[0] -= 1
        if depth > 8 or budget[0] < 0 or offset >= end:
            raise ArtworkError('SDP nesting, node count or header invalid')
        tag = raw[offset]
        offset += 1
        kind, size = tag >> 3, tag & 7
        if kind > 8 or kind == 0 and size != 0:
            raise ArtworkError('SDP type invalid')
        if kind == 0:
            return Element(0, 0, None), offset
        if size < 5:
            width = 1 << size
        else:
            n = 1 << (size-5)
            if offset+n > end:
                raise ArtworkError('SDP truncated length')
            width = int.from_bytes(raw[offset:offset+n], 'big')
            offset += n
        if offset+width > end:
            raise ArtworkError('SDP truncated value')
        if (kind in (1, 2) and size > 4 or kind == 3 and size not in (1, 2, 4)
                or kind == 5 and size != 0 or kind in (4, 6, 7, 8) and size < 5):
            raise ArtworkError('SDP type/width invalid')
        if kind in (6, 7):
            values, limit = [], offset+width
            while offset < limit:
                value, offset = element(offset, limit, depth+1)
                values.append(value)
            return Element(kind, width, tuple(values)), offset
        value = raw[offset:offset+width]
        if kind == 1:
            value = int.from_bytes(value, 'big')
        if kind == 3:
            if width != 16:
                value = int.from_bytes(value, 'big')
            elif value[4:] == bytes.fromhex('00001000800000805f9b34fb'):
                value = int.from_bytes(value[:4], 'big')
        return Element(kind, width, value), offset+width

    root, offset = element(0, len(raw))
    if offset != len(raw) or root.kind != 6 or len(root.value) & 1:
        raise ArtworkError('SDP attribute list malformed')
    attributes = {}
    for index in range(0, len(root.value), 2):
        aid, value = root.value[index:index+2]
        if aid.kind != 1 or aid.width != 2 or aid.value in attributes:
            raise ArtworkError('SDP duplicate or invalid attribute ID')
        attributes[aid.value] = value

    def sequence(value):
        if value is None or value.kind != 6:
            raise ArtworkError('SDP expected sequence')
        return value.value

    services = sequence(attributes.get(1))
    if not any(v.kind == 3 and v.value == 0x110c for v in services):
        return None
    versions = []
    for profile in sequence(attributes.get(9)):
        rows = sequence(profile)
        if len(rows) == 2 and rows[0].kind == 3 and rows[0].value == 0x110e:
            if rows[1].kind != 1 or rows[1].width != 2:
                raise ArtworkError('SDP profile version malformed')
            versions.append(rows[1].value)
    if len(versions) != 1:
        raise ArtworkError('SDP missing or ambiguous AVRCP profile')
    feature = attributes.get(0x311)
    if feature is None or feature.kind != 1 or feature.width != 2:
        raise ArtworkError('SDP supported features malformed')
    if versions[0] < 0x106 or not feature.value & 0x100:
        return None
    candidates = []
    for protocol_list in sequence(attributes.get(13)):
        rows = [sequence(v) for v in sequence(protocol_list)]
        if len(rows) != 2 or not rows[0] or not rows[1]:
            continue
        if rows[0][0].kind != 3 or rows[0][0].value != 0x100 or rows[1][0].kind != 3 or rows[1][0].value != 8:
            continue  # Browsing AVCTP is not the artwork OBEX channel.
        if len(rows[0]) != 2 or len(rows[1]) != 1 or rows[0][1].kind != 1 or rows[0][1].width != 2:
            raise ArtworkError('SDP cover-art protocol descriptor malformed')
        psm = rows[0][1].value
        if not 0x1001 <= psm <= 0xffff or psm & 0x101 != 1:
            raise ArtworkError('SDP cover-art PSM invalid')
        candidates.append(psm)
    if len(candidates) != 1:
        raise ArtworkError('SDP missing or ambiguous cover-art channel')
    return Capabilities(versions[0], feature.value, candidates[0])


class Framer:
    """At most one bounded OBEX frame retained between receive callbacks."""
    def __init__(self):
        self.buffer = bytearray()

    def feed(self, chunk):
        if len(chunk) > 8192:
            self.buffer.clear()
            raise ArtworkError('Receive callback budget exceeded')
        offset, frames = 0, 0
        while offset < len(chunk):
            if len(self.buffer) < 3:
                n = min(3-len(self.buffer), len(chunk)-offset)
                self.buffer.extend(chunk[offset:offset+n])
                offset += n
                if len(self.buffer) < 3:
                    return
            size = int.from_bytes(self.buffer[1:3], 'big')
            if not 3 <= size <= MAX_PACKET:
                self.buffer.clear()
                raise ArtworkError('OBEX frame length invalid')
            n = min(size-len(self.buffer), len(chunk)-offset)
            self.buffer.extend(chunk[offset:offset+n])
            offset += n
            if len(self.buffer) == size:
                frames += 1
                if frames > 8:
                    self.buffer.clear()
                    raise ArtworkError('Receive frame budget exceeded')
                packet = bytes(self.buffer)
                self.buffer.clear()
                yield packet


@dataclass(frozen=True)
class Channel:
    link: int
    sequence: int


@dataclass(frozen=True)
class Metadata:
    channel: Channel
    track: int
    sequence: int


@dataclass(frozen=True)
class Action:
    kind: str
    token: object
    value: object = None


class Session:
    def __init__(self):
        self.link = self.track = self.sequence = 0
        self.device = self.capabilities = self.current = None
        self.channel = self.closing = self.pending = None
        self.disabled = False
        self.attempts = 0
        self.discovery_done = False
        self.client = CoverArtClient()
        self.framer = Framer()

    def _clear(self):
        self.client.cover = None
        return Action('clear', (self.link, self.track))

    def _close(self):
        self.pending = None
        self.client.disconnect()
        self.framer = Framer()
        if self.channel is None:
            return []
        self.closing, self.channel = self.channel, None
        return [Action('close', self.closing)]

    def _fail(self, reason):
        self.disabled = True
        return [self._clear(), *self._close(), Action('error', (self.link, self.track), str(reason))]

    def connect(self, device):
        actions = self._close()
        self.link += 1
        self.track += 1
        self.device, self.capabilities, self.current = device, None, None
        self.disabled, self.attempts = False, 0
        self.discovery_done = False
        return [*actions, self._clear(), Action('discover', self.link, (0x110c, (1, 9, 13, 0x311)))]

    def disconnect(self):
        actions = self._close()
        self.link += 1
        self.track += 1
        self.device = self.capabilities = self.current = None
        return [*actions, self._clear()]

    def discovered(self, link, raw, now):
        if link != self.link or self.device is None or self.discovery_done:
            return []
        self.discovery_done = True
        try:
            self.capabilities = parse_service(raw)
            if self.capabilities is None:
                self.disabled = True
                return []
            return self._open(now)
        except ArtworkError as error:
            return self._fail(error)

    def _open(self, now):
        if (self.device is None or self.capabilities is None or self.current is None or self.disabled
                or self.channel is not None or self.closing is not None or self.attempts >= 2):
            return []
        self.sequence += 1
        self.attempts += 1
        self.channel = Channel(self.link, self.sequence)
        self.open_deadline = now+2
        self.client, self.framer = CoverArtClient(), Framer()
        return [Action('open', self.channel, self.capabilities.psm)]

    def selected(self, uid, counter, now, *, invalidate=False):
        if self.device is None:
            return []
        if not isinstance(uid, bytes) or len(uid) != 8 or uid == b'\xff'*8 or not 0 <= counter <= 0xffff:
            self.current = None
            self.track += 1
            return [self._clear(), *self._close()]
        if (uid, counter) == self.current and not invalidate:
            return []
        previous = self.current
        self.current = (uid, counter)
        self.track += 1
        self.pending = None
        self.disabled, self.attempts = False, 0
        actions = [self._clear()]
        if invalidate or previous is not None and counter != previous[1] or self.client.state == 'get':
            actions += self._close()
        if self.channel is not None and self.client.state == 'ready':
            actions += self._metadata(now)
        else:
            actions += self._open(now)
        return actions

    def opened(self, channel, success, now):
        if not isinstance(channel, Channel):
            return []
        if channel == self.closing:
            return [Action('close', channel)] if success else self.closed(channel, now)
        if channel != self.channel:
            return []
        if self.client.state != 'off':
            return []  # One native open result may arrive through more than one adapter notification.
        if not success or now >= self.open_deadline:
            return self._fail('Artwork channel open failed or expired')
        try:
            cap = self.capabilities
            request = self.client.connect(cap.version, cap.features, cap.psm, now)
            return [Action('send', channel, request.packet)]
        except ArtworkError as error:
            return self._fail(error)

    def closed(self, channel, now):
        if not isinstance(channel, Channel):
            return []
        if channel == self.channel:
            actions = self._fail('Artwork channel closed unexpectedly')
            self.closing = None  # This event itself confirms the channel has closed.
            return [a for a in actions if a.kind != 'close']
        if channel != self.closing:
            return []
        self.closing = None
        self.client.transport_closed()
        return self._open(now)

    def _metadata(self, now):
        if self.pending is not None or self.current is None or self.client.state != 'ready':
            return []
        self.sequence += 1
        self.pending = Metadata(self.channel, self.track, self.sequence)
        self.metadata_deadline = now+3
        return [Action('metadata', self.pending, cover_attribute_request())]

    def metadata(self, ticket, parameters, now):
        if ticket != self.pending or ticket is None or ticket.channel != self.channel or ticket.track != self.track:
            return []
        self.pending = None
        try:
            if now >= self.metadata_deadline:
                raise ArtworkError('Metadata request expired')
            handle = parse_cover_attribute(parameters)
            if handle is None:
                self.disabled = True
                return [self._clear()]
            request = self.client.select_track(*self.current, handle, now)
            return [] if request is None else [Action('send', self.channel, request.packet)]
        except ArtworkError as error:
            return self._fail(error)

    def received(self, channel, chunk, now):
        if channel != self.channel or channel is None:
            return []
        actions = []
        try:
            for packet in self.framer.feed(chunk):
                if self.client.active is None:
                    raise ArtworkError('Unsolicited OBEX response')
                was_connecting = self.client.state == 'connect'
                result = self.client.receive(self.client.active, packet, now)
                if result.next_request is not None:
                    actions.append(Action('send', channel, result.next_request.packet))
                if result.cover is not None:
                    actions.append(Action('image', (channel, self.track), result.cover))
                if was_connecting:
                    actions += self._metadata(now)
            return actions
        except ArtworkError as error:
            return self._fail(error)

    def can_publish(self, token):
        return token == (self.channel, self.track) and self.channel is not None and self.client.cover is not None

    def tick(self, now):
        if self.channel is None:
            return []
        if (self.client.state == 'off' and now >= self.open_deadline or
                self.pending is not None and now >= self.metadata_deadline or self.client.expire(now)):
            return self._fail('Artwork operation timed out')
        return []
