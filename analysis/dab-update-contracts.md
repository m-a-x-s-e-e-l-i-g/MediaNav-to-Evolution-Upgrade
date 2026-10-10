# DAB-firmware, hostprotocol en SPI-transport

Bron: `MgrDAB.exe` uit de 7.0.5.MD-update, SHA-256 `375e9ff4da532c5e4090e3beaad28c894772bc1a6fb6f5174fb1afee1bde4e27`. De 892 .pdata-functies zijn niet allemaal semantisch onderzocht. Dit rapport volgt de firmware-update, de bijbehorende antwoorden en het transport. De ruwe adresbereiken staan in [dab-update-contracts.json](firmware/dab-update-contracts.json), reproduceerbaar met [inspect_dab_update.py](../tools/inspect_dab_update.py). Geen firmwarecode of apparaat is uitgevoerd.

## BC/UC-images en CRC

De worker `0x1895c–0x18be3` zoekt onder `\Storage Card3\upgrade` naar **beide** `ulc_dab_bc*.bin` en `ulc_dab_uc*.bin`. Zonder beide bestanden roept hij de flashroutine niet aan. Deze images ontbreken in de beschikbare updatepakketten; hun versie, normale lengte en inhoud zijn onbekend.

De flashroutine `0x15d44–0x16b43` leest de bestandsgroottes met de 32-bit `GetFileSize`-uitkomst. Er is geen aangetroffen overflowcheck voor de daaropvolgende allocaties. Een mislukte `ReadFile` wordt gelogd; de ontvangen byteaantallen worden niet tegen de gevraagde lengtes getoetst en de code gaat verder.

| Buffer | Layout |
| --- | --- |
| BC | Vier bytes big-endian `bc_size - 1`, daarna BC-payload |
| UC | Vier bytes big-endian UC-CRC, vier bytes big-endian `uc_size - 1`, daarna UC-payload |
| Gecombineerd | BC-buffer op offset 0; UC-buffer op offset `0x40000`; allocatie en checksum over `bc_size + uc_size + 0x4000c` bytes |

De checksumfunctie **`0x15cf4–0x15d43`** wordt door Ghidra verkeerd als een vrijwel lege lus weergegeven. De oorspronkelijke MIPS-instructies lezen iedere byte, XORen die met het hoge CRC-byte en gebruiken de 256 DWORDs op VA **`0x67070`**. Alle tabelwaarden passen exact bij polynoom **`0x04c11db7`**, MSB-first, beginwaarde `0xffffffff`, zonder reflectie of final-XOR. De onafhankelijke bitimplementatie geeft `0376e6e7` voor `123456789`: het CRC-32/MPEG-2 algoritme. Die naam beschrijft het algoritme, niet de inhoud van het firmwarebestand.

Een concrete initialisatiefout staat op **`0x160cc–0x160d8`**: `memset(combined, 0, 4)`. Daarna overschrijft de BC-kopie ook die vier bytes. De ruimte tussen de twee images en de extra staart worden niet gevuld voordat de CRC en overdracht over de volledige allocatie plaatsvinden. Bijvoorbeeld bij BC 128 KiB en UC 1 MiB blijven **262.144 bytes** ongeschreven. Welke bytes de allocator daar werkelijk oplevert is runtime-afhankelijk. Ook de BC-grens vóór `0x40000` wordt niet expliciet gecontroleerd: een te grote BC-buffer overlapt de UC-locatie. De inspectietool beschrijft deze intervallen zonder onbekende bytes te verzinnen.

## Updatehandshake

Objectoffsets hieronder zijn ten opzichte van de manager; de transportstructuur ligt op manager `+0x14`. De antwoorddecoder `0x34d34` gebruikt daarom telkens offsets die `0x14` lager liggen.

| Verstuurd | Antwoord | Gevolgd gedrag |
| --- | --- | --- |
| `2f02` | `4f02` | Bootcode-running WORD uit antwoordoffset `+8` naar manager `+0x16c` |
| `2f03` | `4f03` | Twee WORDs `+8/+10` vormen het SDRAM-adres op manager `+0x178` |
| `2f10` | `4f10` / `4f13` | Erase/CRC-route; resultaat-WORD naar `+0x170`, sector-WORDs naar `+0x174/+0x176` |
| `2f11` | `4f11` | Programroute; antwoord signaleert het gezamenlijke event |
| `2f01` | Geen door deze routine afgewacht eindantwoord | Finishcommando na de programwacht |

`0x34e50` wacht maximaal circa 6 seconden op register 1, schrijft **altijd 16 parameter-WORDs** naar register 2, reset beide antwoordevents en schrijft daarna het commando naar register 0. Het aangeleverde lengtetal wordt dus door deze routine op 16 gezet. De antwoorddecoder signaleert één gezamenlijk event voor meerdere bekende antwoorden; `4f13` gebruikt een afzonderlijk voortgangsevent. Een onbekend antwoord wordt gelogd.

De host probeert boot-running maximaal 100 keer. Als dat niet lukt volgt een recoverypad: hardware-registerwrites via `0x34c38/0x34c80`, BC upload naar SDRAM-adres 0, readback van die BC en vergelijking van beide CRCs, daarna startwrites via `0x34cd8` en opnieuw boot-running proberen. De exact gecontroleerde adressen zijn in de bewaarde functiebytes zichtbaar; het chipmodel is hiermee nog niet bewezen.

Na een SDRAM-adresantwoord accepteert de routine alleen adressen **≤ `0x100000`**. De volledige gecombineerde buffer gaat naar dat adres. Eraseparameters bevatten lengte, SDRAM-adres en totale CRC, telkens gesplitst in hoog/laag WORD. De sectorvoortgang wordt gevolgd totdat actuele en totale sectorwaarde gelijk zijn. Een nul CRC-resultaat wordt expliciet afgewezen. Voor program bevat het verzoek SDRAM-adres en lengte; daarna volgt een eventwacht van 60 seconden en het finishcommando.

Alleen `WAIT_TIMEOUT` (`0x102`) krijgt op deze plaatsen de specifieke timeoutbehandeling. Andere wachtuitkomsten worden als voortgang verwerkt. De routine controleert na het programantwoord geen apart programmeersuccesveld en retourneert **altijd 0**, ook na de gelogde finish. De wrapper gebruikt die returnwaarde niet en verstuurt **WM `0x8064`, wParam `0x900`, lParam 0** aan UpgradeManager ook wanneer bestanden ontbreken of de verbindingstest faalt. Dit is dus een worker-completionmelding, geen bevestigd flashresultaat.

## SPI en SDRAM-FIFO

`0x38a24` opent **`SPI1:`**, gewenste toegang `0x04040270`, share 0, OPEN_EXISTING, vlag `0x80`. De handle en critical section zijn globals `0x127c7c` en `0x127c68`. Alle hier gevolgde transfers gebruiken IOCTL **`0x80002000`**, dezelfde buffer voor input/output.

| Helper | SPI-request |
| --- | --- |
| `0x38584` registerread | Acht bytes: `01`, register, zes dummybytes `01`; resultaat big-endian uit offsets 3 en 4 |
| `0x38b34` registerwrite | Acht bytes: `00`, register, waarde hoog/laag, vier dummybytes `01` |
| `0x386a4` burstread | `15`, register, hoog/laag van `(payload_bytes / 2) - 1`, daarna ontvangstruimte |
| `0x38850` burstwrite | `14`, register, hoog/laag van `(rounded_payload_bytes / 2) - 1`, daarna payload |

Registerread toetst de IOCTL-BOOL en logt een afwijkend ontvangen byteaantal, maar gebruikt ook bij een korte succesvolle transfer de buffer. Burstread kopieert alleen bij een succesvolle IOCTL; een afwijkend byteaantal geeft slechts een logmelding. De toegestane readlengte is 1..252, zonder expliciete evenheidstest. De writehelper vereist positieve even lengte, rondt naar een veelvoud van vier af en accepteert maximaal 252 payloadbytes. Bij een lengte van 2 modulo 4 worden de extra twee bytes niet geïnitialiseerd. Write-BOOL en werkelijk byteaantal worden niet doorgegeven aan de caller.

SDRAMread `0x3487c` zet het adres in registers `0x30/0x31`, readmode 3 in `0x32`, leest maximaal 128 bytes per burst van `0x33`, zet mode 2 en wacht op het verdwijnen van bit 0. Write `0x349c0` kiest mode 1, wacht op FIFO-ruimte via `0x34`, schrijft maximaal 128 bytes per burst naar `0x33`, kiest mode 0 en wacht eveneens op bit 0. Deze FIFO- en eindlussen hebben geen gevonden deadline. De outer helpers `0x35034/0x35150` behandelen oneven adressen en restbytes met een twee-byte read/modify/write respectievelijk deelread. De high-level calls leveren geen transportstatus op.

Er staat geen SPI-registratie in de gevalideerde defaultregistry en geen DLL met SPI in de naam in deze gereconstrueerde ROM. Alleen MgrDAB bevat het onderzochte `SPI1:`-literal. Dit sluit een driver met een andere naam, dynamische registratie of een extra bestand op een DAB-unit niet uit. De provider achter deze handle blijft een concreet ontbrekend onderzoeksstuk.

## Normale DAB-hostframes

Mode 0, encoder `0x355c4`, checksum `0x34704` en decoder `0x358e4`:

```
55 aa | sequence:u8 | command:u8 | segment:u8 | payload_len:u8 | payload | sum:u16be
```

De checksum is de 16-bit bytesom van sequence tot en met de payload; syncbytes tellen niet mee. Ongefragmenteerd uitgaand verkeer krijgt segment `c1`. De decoder leest de lage zes segmentbits als nummer; hogere bits markeren het begin/einde van een fragmentketen. Een checksumfout breekt de verwerking af. Een sequence-afwijking wordt gelogd waarna de verwachte sequence wordt aangepast, dus niet automatisch verworpen. Fragmentketens gebruiken slots met bufferlengte- en volgordechecks. De volledige fragment-/commandstate-machine is nog niet gereconstrueerd.

Mode 1 gebruikt een afzonderlijk acht-byte frame met XOR over offsets 2..6; het is niet hetzelfde framingcontract. [parse_dab_frames.py](../tools/parse_dab_frames.py) leest uitsluitend lokale mode-0-captures. Het bewaart noise, checksumfouten en truncatie en behandelt een `55 aa` binnen een geldige payload als data. Voor lengtes ≥250 markeert het de checksum-indexwrap in de firmware; het simuleert zulke foutgevallen niet als betrouwbaar runtimegedrag.

GetSdkVersion, volume/EQ, DAB-configuratie, scan/tune/stop, kanaal-/ensemblelabels, serviceselectie, signaalinformatie en DAB/FM-service-following zijn zichtbaar in de commandnaam-dispatch `0x36bc4`. De namen bewijzen de bedoelde API; payloads, tunerstate, UI-routing en alle fouten zijn nog open.

## Verificatie en resterende vragen

De CRC-tabel is geheel tegen onafhankelijk berekende waarden gecontroleerd. De checksumfunctie en de vier-byte initialisatie zijn tegen de oorspronkelijke MIPS-instructies gelezen. Offline fixtures controleren CRC-vector, lege input, syncbytes in payload, checksumcorruptie, afgekorte header/frame en de ongevulde/overlappende bufferintervallen. De tools wijzigen geen firmwarebestand.

Nog nodig: werkelijke BC/UC-images; SPI-driver en unitregistry; exact DAB-chipmodel; bootcode/flash-layout; volledige tuner-, service-, preset- en configuratiecode; alle IPC-calls en timing op de echte unit. Er is geen claim dat het apparaat deze update ooit succesvol heeft uitgevoerd.
