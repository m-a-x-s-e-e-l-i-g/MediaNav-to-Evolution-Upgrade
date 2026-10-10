# RAS, Unimodem en AsyncMac: van connection-entry naar seriële frames

Dit vervolgt de [USB-seriële driverketen](usb-serial-contracts.md) en de [remote services](remote-service-contracts.md). Alle conclusies betreffen de lokaal gereconstrueerde ROM. Er is geen firmwarecode uitgevoerd. Originele bytebereiken en hashes staan in [ppp-transport-contracts.json](firmware/ppp-transport-contracts.json); reproduceer met `py tools/inspect_ppp_transport.py`.

## Gevolgde keten

`rnaapp → RasDial → ppp.dll → WAN/TAPI OIDs → asyncmac.dll → Unimodem → seriële HANDLE → COM-driver → USB-callbacks`.

De onderdelen en interfaces van deze keten zijn gevolgd. De actieve device-registration, de uiteindelijke TAPI-device-ID en de persistent gewijzigde entry op de echte unit zijn nog niet waargenomen. De bootregistry koppelt `jacmdev` aan COM-index 5 en FriendlyName `uwserial`; `jacminit` maakt een direct-RAS-entry voor `uwserial`. Dit is dus een onderbouwd statisch pad, geen bewijs van een geslaagde verbinding op Max' unit.

## PPP-devicekeuze en sessie

| Functie | Gevolgd gedrag |
| --- | --- |
| `ppp!c0443e08` AfdRasDial | Laadt entry/devconfig, maakt sessie, start connectie en levert sessiereferentie terug |
| `ppp!c0433b14` | Eigen heap, initiële omvang `0x19000`, maximum `0x32000`; sessierecord `0xdf4`; locks, events en timers |
| `ppp!c044603c` | Linkrecord `0x230`, devicenaam/type kopiëren, device zoeken, WAN-info opvragen met OID `0x04010107`, packetpool maken |
| `ppp!c0447b8c/c0447ab8` | Enumeratie van geregistreerde adapterrecords en 12-byte devicegegevens, met referenties en lockvrij callbackmoment |
| `ppp!c0447c6c` | Devicenaam vergelijken met `wcsncmp(...,128)` en type met `wcscmp`; eerste match vasthouden |
| `ppp!c0447cf8` | Matchresultaat en device-index teruggeven; foutstandaard `0x293`. Assembly bevestigt een returnwaarde in `v0`; pseudocode toont ten onrechte `void` |
| `ppp!c043422c/c0433764` | Connectieworker, statewijzigingen, events. Zonder callback wacht de caller tot connected/failure-state |
| `ppp!c0445bd0/c0448c34` | TAPI-call/devconfigpad, wachten op linkevent, `ndis`-deviceklasse opvragen via OID `0x07030113` |

`c0439fb8` registreert protocol `0xc021` en maakt een LCP-context. De complete LCP/IPCP/authentication-machines worden apart gevolgd; deze notitie bewijst de transportlaag.

## Unimodem en de seriële HANDLE

`unimodem!c06952d8` maakt een nulgevuld `0x754`-record. De poortnaam komt uit een meegegeven string of registrywaarde `Port`. `FriendlyName` valt terug op de poortnaam. `DeviceType` heeft standaardwaarde 0; devicecfg staat op `+0x220`.

`c0695a60` opent dezelfde poort tweemaal met OPEN_EXISTING en share=0: eerst GENERIC_READ|GENERIC_WRITE, daarna access=0 voor statusbewaking. De eerste HANDLE gaat naar `+0x4e8`, de tweede naar `+0x4f4`. `GetCommState → c06958d4 → SetCommState` stelt baudrate, byte-size, stopbits, parity en handshakeflags uit devconfig in. De baudrate kan dus door configuratie veranderen; de JACM-driver heeft bovendien een baudratecallback die geen hardwarewijziging uitvoert.

`c0695998` gebruikt read-interval en read-constant 50 ms, write-multiplier 5 en write-constant 500. Read-multipliers: 110→109, 300→41, 600→21, 1200→10, 4800→6, 9600→3, overig→1. Deze initiële waarden worden later door AsyncMac overschreven.

De leaf `TSPI_lineGetProcTable c0693fa8` vult eerst 101 procedureslots met een stub en zet geselecteerde handlers. Slot `+0x114` verwijst naar `c0693a04`, die het device-initialisatiepad aanroept. Volledige TAPI-registration en alle TSPI-slots blijven open.

## AsyncMac-configuratie en callbacks

`DriverEntry c0462ce8` registreert een NDIS-miniport met versie 4.0 en onder meer initialize `1330`, halt `12ac`, query `23d8`, set `1d54`, WanSend `1af0`. `c0461330` accepteert mediumwaarde 3 en maximaal één adapter.

| Registryconfiguratie | Default |
| --- | ---: |
| MaxFrameSize | 1502 |
| MaxSendFrameSize | MaxFrameSize |
| MaxRecvFrameSize | MaxFrameSize |
| ReceiveBufferSize | 2000 |
| ReceiveThreadPriority256 | 130 |
| TransmitThreadPriority256 | 130 |
| MaxTxPackets | 16 |

WAN-info bevat framegrootte 1502, TX-count 16, headerpadding 1504, tailpadding 5. De grote headerpadding is ruimte vóór de oorspronkelijke packetbytes voor framing/escaping. Dit is geen 1504-byte header op de draad.

TAPI-workitem `c0463308` wacht op API-readiness en roept `lineInitialize` aan met naam `ASYNCMAC` en callback `c0462fd4`. Bij callstatewaarde `0x100` vraagt die callback met `c0462e00` een serial HANDLE op via `lineGetID(...,"comm/datamodem")`, zet deze op linkoffset `+0x40`, vraagt de verbindingssnelheid en meldt line-up aan NDIS met `0x40010008`.

Query OID `0x07030113` heeft voor deviceklasse `ndis` een speciaal pad: `c04622d8` start de RX/TX-workers en stelt hun prioriteit in. Set OID `0x04010108` kopieert 44-byte linkinfo, waaronder TX/RX-framingflags op `+0x7c/+0x80` en TX-ACCM op `+0x8c`. Bit `0x100` kiest PPP; zonder deze bit wordt SLIP gebruikt.

## PPP-encoder, CRC en buffers

`c046345c` schrijft beginflag `7e`, payload en twee FCS-bytes, vervolgens eindflag `7e`. FCS is de complementwaarde van CRC16 en gaat low byte eerst. Bytes `7d/7e` en controlbytes die in TX-ACCM staan, worden `7d` gevolgd door byte XOR `20`.

CRC-leaf `c0463c04` begint met `ffff` en gebruikt de oorspronkelijke tabel op `c0465240`: `crc = table[(byte XOR crc) & ff] XOR (crc >> 8)`. Alle 256 tabelwaarden zijn gelijk aan een onafhankelijk bitmodel met reflected polynomial `8408`. Checkwaarde voor ASCII `123456789`: intern `6f91`, verzonden FCS `6e 90`; CRC over payload plus FCS geeft `f0b8`. Dit komt overeen met de 16-bit FCS-methode in [RFC 1662, appendix C.2](https://www.rfc-editor.org/rfc/rfc1662.html#appendix-C.2). De decompiler verloor de returnwaarde; originele assembly is hier beslissend.

`ppp!c04474e8` bewaakt maxframe≤131072 en header/tail≤65536, kapt TX-count op 500 en reserveert count+1 records. Per packet is de dataruimte:

`stride = ((((maxframe * 9 + 7) >> 3) + header + tail + 12) & ~3)`.

Default: stride **3208**, 17 records van stride+56 = **55.488 bytes**. Packet-input begint headerpadding bytes na het begin van de dataruimte; `c04476cc` stelt de inputpointer en capaciteit in. Zelfs als alle 1502 payloadbytes plus beide FCS-bytes escaping nodig hebben, is de wire-bound **3010 bytes**, passend in 3208. Een apart model controleert dat het schrijven vóór de inputpointer nog niet gelezen payloadbytes niet overschrijft. Dit geldt voor de gevolgde defaultwaarden; afwijkende registry/devicewaarden vereisen dezelfde controle opnieuw.

## Ontvangst, partial I/O en afwijkende frames

RX-worker `c04638c4` gebruikt mask `0x20a1`, ReadIntervalTimeout=FFFFFFFF, read-total 0/0 en write-total 2/500. Hij verwerkt de feitelijk gelezen bytes, houdt pending escape en framestate over readgrenzen vast, en gebruikt een decodebuffer van MaxRecvFrameSize+54 bytes. Voor de eerste flag worden gegevens niet afgeleverd. Een oversize-frame wordt tot de volgende flag weggegooid; counter `+0xbc` stijgt eenmaal voor die frame.

`c0463584` accepteert PPP vanaf drie gedecodeerde bytes: minimaal één byte plus FCS. Hij vergelijkt CRC van payload met complement van de laatste little-endian WORD, verhoogt accepted-counter `+0xa4` of bad-CRC-counter `+0xa8`, en levert geldige payload aan NDIS af. De verdere PPP-protocolparser kan zulke korte payloads alsnog verwerpen.

Een statische afwijking: het flagpad test **niet** of een escape openstaat. Een verder CRC-geldig frame met extra `7d` direct vóór closing `7e` wordt daardoor op deze laag alsnog afgeleverd. Ook de minimumlengte 3 verschilt van RFC-minimum 4; de gevolgde parser verwijdert geen ongeëscapete controlbytes volgens een RX-ACCM. [RFC 1662 §4.2–4.3](https://www.rfc-editor.org/rfc/rfc1662.html#section-4.3) schrijft deze controles anders voor. Dit is een bewezen verschil in parsergedrag, geen bewijs van een exploiteerbaar probleem of een storing op de unit.

De offline modellen toetsen alle splitsingsgrenzen van meerdere payloads/ACCMs, reads van één byte, maximale escaping, CRC-fouten, oversize-herstel en het dangling-escapegeval. SLIP-encoder `c04633e4` gebruikt `c0`-flags, `db dd` voor `db`, `db dc` voor `c0`, zonder FCS; een 256-byte model toetst elke bytewaarde.

TX-worker `c04620f4` schrijft herhaaldelijk totdat het hele geframede packet is verzonden. Een mislukte WriteFile of nul geschreven bytes geeft failure; succesvolle partial writes schuiven pointer en remaining length op. Dit onderdeel verwerkt partial I/O daadwerkelijk.

## Nog te onderzoeken

- Complete PPP-protocolregistratie, LCP/IPCP/EAP/PAP/CHAP, opties, timers en retransmits.
- Exacte bron van geregistreerde devicelijsten en de volledige TAPI/TSPI-deviceketen.
- Alle WAN-OID-structuren, refcount-, cleanup-, power- en errorpaden.
- Feitelijke negotiated flags/ACCM en registry/deviceconfig op de originele unit.
