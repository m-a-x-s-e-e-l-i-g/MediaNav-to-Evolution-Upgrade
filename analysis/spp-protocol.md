# Bluetooth-SPP: ringbuffers en B6 B6-pakketten

Statische reconstructie van Blue.exe en AppMain.exe. AppMain bevat debuglabels `[aha]` rond de hogere applicatiecode. De naam Aha is context uit de executable; er is geen telefoon/capture gebruikt en het hele serviceprotocol is nog niet benoemd.

## Shared-memorytransport

Blue maakt twee mappings, **SppDataInFileMapName** en **SppDataOutFileMapName**, elk **0x7dfa8 = 516.008 bytes**, via CmnDll-MSHM-helpers. De mutexnamen zijn SppDataInMutexName / SppDataOutMutexName. Initialisatie staat op `0x2bbc4`, aanmaak op `0x2c97c`.

De indeling volgt uit Blue-writer `0x2bcd4–0x2be6f`, Blue-reader `0x2be70–0x2c05f` en AppMain-reader `0xeaed8–0xeb347`:

| Offset | Omvang | Veld |
| --- | --- | --- |
| `index * 0x408 + 0` | DWORD | Service-ID; Blue-reader vergelijkt met zijn verwachte service |
| `index * 0x408 + 4` | DWORD | Lengte van dit chunk |
| `index * 0x408 + 8` | 1.024 bytes slotcapaciteit | Chunkdata |
| `0x7dfa0` | WORD | Read-index |
| `0x7dfa2` | WORD | Write-index |
| `0x7dfa4` | WORD | Teller, in Blue-writer op 500 teruggezet naar 0 |
| `0x7dfa6` | WORD | Nog onbenoemd |

Er zijn **500 slots van 1.032 bytes**. Indices lopen 0..499. Een teller van nul of twee gelijke indices bewijzen zonder verdere context geen lege buffer. AppMain kiest bij read-index ≥ write-index het wrap-pad en leest tot slot 499 en daarna tot write-index. Bij gelijkheid kan die branch dus 500 slots verwerken; de notificatie-/volheidsvoorwaarden en de synchronisatie zijn nog niet volledig gevolgd.

AppMain voegt chunks toe aan een QByteArray en zet read-index gelijk aan write-index. In deze leesfunctie toetst hij de chunklengte niet zichtbaar aan 1.024. Dat zegt niets over mogelijke limieten bij eerdere schrijvers/callers; die worden nog gevolgd.

## Frameheader en checksum

AppMain zoekt in de samengestelde byte-array naar **`B6 B6`**. De helpers op `0xf2c08`, `0xf2cc8` en `0xf2d88` lezen 2/4/8 bytes little-endian vanaf een **extra indexargument in `$a1`**. De automatische pseudocode laat dat argument bij sommige calls weg; onderstaande offsets zijn daarom rechtstreeks in MIPS gecontroleerd.

| Frameoffset | Omvang | Betekenis uit parser |
| --- | --- | --- |
| `0` | WORD | `0xb6b6` |
| `2` | WORD | Totale framelengte, inclusief header |
| `4` | WORD | Response-/sequenceveld |
| `6` | WORD | Command-ID |
| `8` | WORD | Checksum |
| `10` | Variabel | Resterende packetdata; command-specifieke indeling open |

Reader `0xeb0f0–0xeb1d8` toetst framelengte **≤50.000**, command-ID **<267**, aanwezigheid van alle gedeclareerde bytes en checksum. Een mislukte header-/checksumtest verschuift de zoekpositie één byte. Een onvolledig frame wordt voor verdere chunks bewaard. Het hier getoonde tien-byte minimum wordt door de offline parser expliciet getoetst; de firmwarereader heeft in deze route niet dezelfde zichtbare minimumtest.

Checksumhelper `0xf2e4c–0xf2f5b` leest de totale lengte op +2, telt little-endian WORDs vanaf offset 0 op, **slaat de checksum-WORD op +8 over**, telt bij een oneven lengte de laatste byte als unsigned byte mee en neemt de negatieve som modulo 65.536. De header- en lengtesommen tellen dus mee. Het resultaat wordt vergeleken met +8.

Responsehelper `0xffd2c–0xffe93` kijkt naar bit **0x8000** van het veld op +4. Als die bit staat, zoekt hij met de lage 15 bits een entry in een requestlijst en haalt bijbehorende context op. Zonder die bit neemt hij het command-ID rechtstreeks uit +6. Alle commands, requeststructuren, replies en foutstatussen moeten nog worden gekoppeld.

Op `0xeb0a0` leest AppMain de QByteArray-lengte met **lhu op objectdata +8**, dus alleen de lage 16 bits van het lengteslot. Dezelfde container wordt door chunkappend vergroot. Gevolgen bij een opgebouwde stream boven 65.535 bytes zijn een open foutpad; er is nog geen runtimebewijs dat zo'n toestand op de unit voorkomt.

## Afbeeldingen en Qt-gebruik

In dit hogere telefoonpad gebruikt AppMain QString, QByteArray en QDataStream. De image-cache op `0xea250/0xea2f8/0xea698` houdt records met 260 naambytes plus een HBITMAP bij (stride 264), en begint vanaf 100 entries oude handles te vervangen.

De decodehelper `0x1029b4–0x102d27` gebruikt CoCreateInstance, een afbeeldingsinterface en CreateDIBSection. De image-signaturehelper `0x102d98–0x102e6b` herkent de acht PNG-signaturebytes en geeft dan interne formatcode `0x17`, anders `0x10`. De decodehelper neemt voor dit pad alleen afbeeldingen waarvan zowel breedte als hoogte **<313** zijn. Dat is een grens in deze helper, geen algemene schermresolutie of decoderlimiet.

Dit verklaart concreet QtCore-gebruik in AppMain. De eigen GUI-schermen met CreateWindowEx, GDI en CGUI-klassen worden apart gevolgd.

## Offline parser

[parse_spp_data.py](../tools/parse_spp_data.py) leest een lokaal streambestand, rapporteert frames/checksumfouten/ruis/truncatie, of met `--ring` alle niet-lege slotrecords uit een mappingkopie. Ringrecords kunnen stale zijn; de parser noemt ze niet automatisch actief. Hij opent geen Bluetooth-verbinding.

Evidence: [Blue-disassembly](disassembly/Blue.exe.asm), [AppMain-disassembly](disassembly/AppMain.exe.asm), [Bluetooth-basislayout](bluetooth-layout.md).
