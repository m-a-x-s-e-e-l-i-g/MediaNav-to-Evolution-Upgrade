# Bluetooth-statusmapping: BlueEarth

Statisch onderzoek van `Blue.exe` en `AppMain.exe` uit de 7.0.5.MD-update. Geen live Bluetooth-capture, shared-memorydump of native test.

## Mappings aan beide kanten

| Mapping | Blue.exe | AppMain.exe | Omvang |
| --- | --- | --- | ---: |
| `BlueEarth` | Aanmaak `0x33f20–0x33f38`; helper `0x34414` | Aanmaak `0x110400–0x110418`; helper `0x11b06c` | `0x13d620` = 1.300.000 bytes |
| `BlueEarthBrowse` | Aanmaak `0x33f3c–0x33f54`; helper `0x34a84` | Helper `0x11b1c0` | `0x27cb88` = 2.608.008 bytes gevraagd bij MapViewOfFile |

Voor `BlueEarth` vraagt de schrijver mappingaccess `0xf001f` en AppMain access 4. AppMain bewaart de mappingview op shared-memoryobject +8. De maker probeert eerst CreateFileMapping met lengte nul en maakt bij mislukking een mapping met de vaste omvang.

Bij `BlueEarthBrowse` maakt Blue een nieuwe mapping met de volledige omvang. AppMain gebruikt in het fallback-aanmaakpad **0x400** bytes, terwijl het later een view van **0x27cb88** bytes vraagt. Dat verschil is werkelijk in de assembly aanwezig. Het effect bij ontbrekende mapping en een andere startvolgorde is nog niet getest.

Blue heeft bovendien SPP-mappings `SppDataInFileMapName` en `SppDataOutFileMapName`, elk **0x7dfa8 bytes**, met afzonderlijke mutexnamen. Inmiddels zijn [500-slot-ringbuffer en B6 B6-pakketframing](spp-protocol.md) gevolgd; de volledige synchronisatie, notificaties en commandobetekenissen blijven open.

## Drie metadata-velden bewezen

`Blue.exe` schrijft een block van **0x104 = 260 bytes** vanuit zijn AVRCP-object naar `BlueEarth + 0xcf0e8`. Callsite `0x1ec60–0x1ec74` gebruikt index 1, lengte 0x104 en helper `CBlueShmem::setMediaMetaData` op `0x348d4`. Die helper berekent `(index - 1) * length + 0xcf0e8`; de memcpy staat in `0x34310`.

AppMain leest precies die mappingoffset op `0x113810–0x11381c`. In `0x1137d0–0x11391f` worden drie buffers met codepage **65001 / UTF-8** naar WCHAR geconverteerd. De bijbehorende logs heten `Song (%s)`, `Album (%s)` en `Artist (%s)`.

| Mappingoffset | Bytes | Betekenis | AppMain-lezer |
| --- | ---: | --- | --- |
| `0xcf0e8` | 50 | Titel, UTF-8 | `0x113830–0x113848`, log `Song` |
| `0xcf11a` | 50 | Album, UTF-8 | `0x11387c–0x113894`, log `Album` |
| `0xcf14c` | 50 | Artiest, UTF-8 | `0x1138c4–0x1138dc`, log `Artist` |
| `0xcf17e` | 110 | Overige metadata; indeling open | Nog verder volgen |

Deze gegevens zijn dus anders ingedeeld en gecodeerd dan de USB-mapping. Een gemeenschappelijke UI moet per bron het echte formaat lezen.

## Overige voorlopige regio's

De CBlueShmem-methoden geven de volgende grenzen: device lists vanaf 0 / 0x280, search-regio vanaf 0x500, een grotere regio vanaf 0x900, en grenzen 0xc4120, 0xc7bb8, 0xcb650, 0xcf0e8 en 0xcf8b8. Sommige methoden geven pointer/offsets terug, andere kopiëren callerafhankelijke records. Recordgroottes en namen mogen daarom nog niet uitsluitend uit deze grenzen worden afgeleid.

Voor browsing berekent een AppMain-folderlezer `index * 0x10c + 0xc`, met index kleiner dan 1000 (`0x1139b0–0x1139dc`). Dat bevestigt een stride en naamoffset voor die leesroute; het volledige browseformaat en zijn andere lijsttypen zijn nog open.

## Offline parser

[parse_bt_status.py](../tools/parse_bt_status.py) leest uitsluitend de drie bewezen tekstvelden uit een volledige BlueEarth-dump van exact 1.300.000 bytes. De onbekende rest van het metadatablock blijft als hex behouden. De parser is met een synthetische UTF-8-fixture en verkeerde dumpgroottes gecontroleerd. Geen gegevens van gekoppelde telefoons zijn uitgelezen.

Evidence: [Blue-disassembly](disassembly/Blue.exe.asm), [AppMain-disassembly](disassembly/AppMain.exe.asm), [Blue-pseudocode](decompiled/705md/Blue.exe/decompiled.c).
