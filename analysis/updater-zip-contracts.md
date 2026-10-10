# Updater ZIP: versleuteling, CRC, naamgeving en output

Statische analyse van UpgradeManager SHA-256 `4d6ffa36bc0e42945ba1ebce79de48d82030894e0e1f9c9e05165d3c33735f87`. [inspect_updater_zip.py](../tools/inspect_updater_zip.py) bewaart originele instructies in [JSON](firmware/updater-zip-contracts.json) en toetst onafhankelijke modellen tegen lokale LGUs. De firmware is niet uitgevoerd en er worden geen ZIP-members naar disk uitgepakt.

## De gevolgde archive-callketen

De LGU-wrapper gaat via `0x1d57c` naar archive-vtable +0x18. Constructor `0x1ff3c` kiest de concrete ZIP-vtable `0x34aac`. Slots +0x18/+0x14 zijn `0x26210` (alle indices samenstellen) en `0x262cc` (extractlist). Die laatste maakt een pad, opent de outputstream en roept `0x266c4`. Via vtable +0x4c komt de concrete reader op `0x21de0`: method 0 naar stored-copy `0x25ac0`; method 8 naar deflate `0x25dd4`; een andere methode geeft status `0x19`.

De memberstruct heeft compressed-size DWORDs +0x10/+0x14, uncompressed-size +0x18/+0x1c, encryptiesoort +0x20, attributes +0x24, CRC +0x28 en methode +0x2c. Parser `0x208dc` leest de ZIP-local-header na signature `0x04034b50`. Afhankelijk van flag bit 3 gebruikt hij als cryptcheck-byte de hoge byte van DOS modification time of de hoge byte van member-CRC. De complete central-directory-/ZIP64-parsing blijft open.

## Versleuteling en waargenomen pakketten

`0x26894` behandelt encryptiesoort 0 of 1; type 1 vereist een wachtwoord, leest twaalf cryptheaderbytes en trekt twaalf van compressed-size af. Een ander type geeft `0x46`; leeg wachtwoord `0x20`; een niet-passende check-byte `0x21`. `0x26a70` begint met keys `12345678`, `23456789`, `34567890`, verwerkt passwordbytes en gebruikt multiplier `08088405`. `0x269b8` decrypt elk byte en werkt de keys met het **plaintextbyte** bij. De byte-keuze uit het product is in de originele `mult/mflo/sra/andi`-instructies gecontroleerd. De interne CRC-step gebruikt tabel `0x2c198` zonder externe complementstap. Dit is onafhankelijk van de buitenste 1024-byte LGU-XOR-laag.

| Pakket | ZIP-members | Method/flags | Gecontroleerde cryptheaders | Volledige kleine payloadsamples |
| --- | ---: | --- | ---: | ---: |
| 7.0.5.MD | 1917 | Alle method 8 / flags 1 | 1917 | 8 |
| Navigatiefix | 1 | Method 8 / flags 1 | 1 | 0 |
| Remove MD | 1043 | Alle method 8 / flags 1 | 1043 | 8 |

Het onafhankelijke ciphermodel accepteert **alle 2961 check-bytes**. De zestien kleine samples zijn onafhankelijk gedecrypt, als raw deflate gedecomprimeerd en gecontroleerd op grootte, updater-CRC, Python ZIP-output en eerder uitgepakte bytes. De grote navigatie-executable is geen nieuwe payloadsample. Eerdere corpusverificatie controleerde alle ZIP-CRC's en extractiehashes; deze nieuwe toets bevestigt vooral de koppeling met de gereconstrueerde cipher. Een headercheck-byte alleen bewijst geen volledige payloadintegriteit.

## Deflate en CRC

Stored-copy gebruikt maximaal 8192 bytes per chunk. Deflate gebruikt 4096-byte input en 4096-byte output, decrypt vóór inflate en accumuleert CRC over **gedecomprimeerde output**. De call op `0x25edc` houdt `a1=-15`, versiestring `1.2.3` en structgrootte `0x38` vast. De geëxporteerde pseudocode toont minder argumenten; de oorspronkelijke registerwaarden zijn bewaard. De geanalyseerde initializer `0x273e0`/reset `0x27364` zet een raw stream zonder wrapperheader en een 32768-byte window. Het volledige inflate-stateapparaat en alle ongeldige Huffman-/distancepaden zijn nog niet individueel gevolgd.

CRC `0x26ecc` complementeert zijn inkomende accumulator, verwerkt bytes/woorden via vier tabellen op `0x2c198..0x2cd98` en complementeert aan het eind. Het instructiemodel is met zlib gekruist voor 100 lengtes en twee seeds. Beide readers vergelijken de member-CRC, **behalve wanneer de verwachte CRC nul is**; mismatch geeft `0x18`. Stored/deflate vereisen daarnaast een toegestane decryptstatus (0/1/5 in de eindcheck). Annulering en callbacks blijven onderdeel van de callerstatus, dus een CRC-check alleen beschrijft niet de volledige extract-return.

## Membernamen en bestemming

Namehelper `0x1fc10` weigert lege namen en substrings `../` en `..\`, zet `/` om naar `\`, verwijdert afsluitende CR/LF en converteert met MultiByteToWideChar. De UTF-8-flag kiest codepage 65001 wanneer de ingestelde codepage nul is. Bij conversiefout wordt de wide naam `?`; memory-allocationfouten zijn niet overal volledig afgehandeld.

Root/name-join `0x247a0` kopieert de root, zorgt voor een afsluitende backslash en appendt de membernaam. Het `sltiu ... 0x208`-contract vereist **lengte inclusief NUL <520**, dus maximaal 518 UTF-16-code-units vóór de NUL. De extractlist heeft een 520-WCHAR buffer en normaliseert haar niet-lege root vooraf; het initiële kopiëren van de root is niet afzonderlijk begrensd. Er is geen gevonden algemene canonicalization/rootcontainment-check in deze join. De aanvullende naamvervanging `0x24324` verandert `<`, `*`, `>`, `?`, `|` en sommige colons in `_`; `0x2414c` behandelt whitespace rond backslashcomponenten. Werkelijke filesystemnormalisatie van alle bijzondere namen blijft apart te toetsen; het rapport schrijft daar geen gedrag bij.

## Asynchrone bestandsuitvoer

De outputstream gebruikt vtable `0x349a8`; `0x1e044` allocates 0x58 bytes en start via `0x1e2d4`/`0x1e7c4` een writerthread. Open gebruikt CREATE_ALWAYS, GENERIC_WRITE en flags `0x20`; bij openfout probeert hij via DeleteFile/MoveFile een alternatieve naam en opent opnieuw. De queue heeft een beginbuffer van 64 KiB en kan groeien. Enqueue `0x1e4f0` wacht maximaal 300×10 ms als de queue boven 512 KiB komt.

Writer `0x1e854` schrijft in blokken tot 64 KiB en controleert **zowel WriteFile-BOOL als exact bytesWritten**. Fout zet streamflag +0x48=1; alleen een exacte geslaagde write verhoogt de 64-bit teller op +0x28. Close `0x1e618` vraagt drain/stop en wacht zonder deadline op de thread. `0x266c4` gebruikt de close-status en vergelijkt daarna de geschreven teller met de opgegeven uncompressed-size; mismatch geeft `0x43`. Uitzonderingen zijn archive-mode 12/13 en beide size-DWORDs `ffffffff`. Bij extractiefout wordt het doel alleen via de gevolgde helper verwijderd als zijn geschreven teller nul is; een gedeeltelijk bestand kan blijven staan.

Deze bytecountcontrole hoort bij de **extractiestroom**. De latere [staging-copyhelper](updater-storage-contracts.md) gebruikt CopyFile/DeleteFile zonder deze controle; het ene pad bewijst geen verificatie van het andere.

## SyncTool-monitor

`0x15dbc` start SyncTool, sluit vervolgens beide PROCESS_INFORMATION-handles en maakt daarna thread `0x12b50` met een pointer naar zijn eigen stackstruct. Die thread kopieert de struct, wacht op de reeds gesloten proceshandle, negeert de waitstatus en sluit de handles nogmaals. De stackpointer kan bovendien na return ongeldig zijn. Dit is een aangetoond handle-/lifetimeprobleem; het exacte runtime-effect hangt af van scheduling en handlehergebruik. De logtekst dat SyncTool beëindigd is, bewijst daarom geen succesvolle process-wait.
