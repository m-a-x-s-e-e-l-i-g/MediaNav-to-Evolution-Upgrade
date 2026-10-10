# Radio- en Arkamys-bestanden in 7.0.5.MD

Dit onderzoek volgt pakketbytes en code in MicomManager.exe. De ontvangen hardware-uitwerking en de betekenis van individuele DSP-/tunercöefficiënten zijn nog niet vastgesteld. Er is geen verbinding met de unit gemaakt.

## psnlist.dbf: PI naar acht stationnaambytes

De naam suggereert DBF, maar loader `0x311ec–0x31343` leest zonder DBF-header steeds **10 bytes**: een little-endian 16-bit ID en acht stationnaambytes. Hij vergelijkt het ID met zijn tweede argument, kopieert de eerste match en stopt. Vooraf wordt de acht-byte uitvoer gewist. Er is dus geen Unicode- of nulterminatorveld in dit record.

Het ID is te volgen naar het veld dat `CRadio::StartSubModeTune`, `0x29ad4–0x29d9b`, als **CurPI** logt: objectoffset `0x1cc`. Dit veld gaat via `0x31860`, vervolgens `0x31788`, naar de lookup. Dat ondersteunt de betekenis **RDS PI**. De naambytes houden hun oorspronkelijke encoding; een ASCII-preview is geen volledige RDS-tekendecoder.

Het bestand bevat **2.312 records en 2.310 unieke IDs**, totaal 23.120 bytes. Twee IDs komen dubbel voor:

| PI | Eerste naam | Latere naam | Gevolg van lineaire lookup |
| --- | --- | --- | --- |
| `0xd7a4` | `SWR4 KL ` | `SWR4 KL ` | Zelfde naam |
| `0xfe52` | `ENGHIEN ` | `RL.89.4 ` | `ENGHIEN ` wint |

De stationcache gebruikt records van **44 bytes** en maximaal **128 slots**. Op `0x31788` zoekt de code een slot waarvan PI op offset 8 nul is. Als alles bezet is, gebruikt hij de byte op cacheobjectoffset `0x87` als slotindex. Het nieuwe record wordt gewist, krijgt PI op +8, byte 1 op +10 en een frequentiecode `frequency / 100 + 0x95` op +11; de naam komt op +0. De overige cachevelden en de begrenzing van de vervangingsindex moeten nog worden gevolgd.

De [volledige stationlijst](firmware/radio-station-names.json) bewaart fileoffsets, PI en oorspronkelijke naambytes. Dit bestand ontbreekt in de uitgepakte downgrade; dat betekent niet dat het op een oudere fysieke unit afwezig was.

## Arkamys: 917 bytes, acht transferblokken

`arkamys_default.dat` bevat **1.834 aaneengesloten ASCII-hextekens**, zonder extra header. Het decodeert naar **917 bytes (`0x395`)**. De loader ondersteunt zowel die ASCII-vorm (`0x72a` filebytes) als 917 ruwe bytes.

De debuginterface in `0x3cbbc`, case 1 vanaf `0x3cc64`, probeert eerst `.\MD\arkamys_eol.dat`, daarna `.\Storage Card\system\arkamys_default.dat`. De aparte updaterfunctie `0x11fac–0x1221b` leest `.\Storage Card\system\arkamys_update.dat`. Die drie namen geven een voorkeur-/updatepad, geen bewijs dat de ontbrekende EOL-file daadwerkelijk op deze unit staat.

Beide paden wissen vooraf een buffer van **1.024 bytes**, laden de 917 bytes en sturen de buffer als acht stukken van 128 bytes:

| Veld | Waarde |
| --- | --- |
| Seriële manager | `0xf` |
| Write-type | `6` |
| Write-commandobyte | `0x80` (128 databytes) |
| Logisch adresveld | `0x21` t/m `0x28`, little-endian DWORD |
| Payload per frame | Vier adresbytes + 128 databytes = 132 bytes |
| Timeoutargument | 300 ms per schrijfaanroep |
| Daarna | Normaal commando `(manager=5, type=1, command=0x60)`, geen payload, timeoutargument 200 ms |

De laatste **107 bytes zijn nulpadding**. De adressen zijn velden van het seriële protocol; zonder ontvangende handler worden ze niet als fysieke MCU-geheugenadressen uitgelegd. De betekenis van command `0x60` blijft open.

De Arkamys-defaults zijn byte-identiek aan het downgradebestand. Dit zegt niets over EOL-kalibratie of de werkelijk actieve DSP-instellingen.

## radparam.bin: 1.024 bytes naar manager 3

`radparam.bin` heeft **1.024 ruwe bytes**, byte-identiek in hoofd-update en downgrade. De updatefunctie `0x2b338–0x2b46f` leest `.\Storage Card\system\radparam_update.bin` en verstuurt acht stukken van 128 bytes met hetzelfde write-type 6, nu naar **manager 3, adresvelden `0xe0` t/m `0xe7`**.

Daarna volgen normale commands **`0xe1`, `0xe0`, `0xe2`** naar manager 3 met type 1, zonder payload en timeoutargumenten 1.000, 1.000 en 100 ms. De debugroutes vanaf `0x3bb98` en `0x46938` kunnen ook `.\Storage Card\system\radparam.bin` of `.\Storage Card\ULC_RAD_PARAM.bin` gebruiken; vervolgcommands en timeouts verschillen per route. Betekenissen van de 1.024 bytes en deze commands zijn nog open.

De radio-updater wordt vanuit `CRadio::OnCommand` bij `CMD_APP_BOOT_STAT_NOTI` aangeroepen. De Arkamys-updater wordt vanuit `0x1358c` na filtering op type 2 en command 0 aangeroepen. Het volledige centrale dispatchpad wordt nog gevolgd.

## Concrete onvolledige foutcontrole

In beide updatefuncties worden **fread-resultaten, de afzonderlijke write-resultaten en de afsluitende command-resultaten niet gecontroleerd voordat het updatebestand wordt verwijderd**. Dat is zichtbaar in assembly: calls naar `0x14db0` en `0x15158` worden gevolgd door volgende acties zonder een conditie op hun returnwaarde, daarna `DeleteFileW` op `0x121f4` respectievelijk `0x2b448`.

Bij Arkamys leidt zelfs een andere bestandsgrootte dan de twee ondersteunde groottes naar de transfer van de vooraf gewiste buffer. Bij de radiofile wordt de stackbuffer voor fread in deze functie niet eerst gewist: een te kort bestand kan daardoor ook bytes buiten de daadwerkelijk gelezen data doorgeven. De aanwezige pakketbestanden hebben de verwachte omvang. Dit zijn statisch aangetoonde zwakke foutpaden, geen bewijs van een opgetreden storing op jouw unit.

## Reproduceerbare lokale inspectie

[inspect_radio_audio_data.py](../tools/inspect_radio_audio_data.py) leest de pakketbestanden, decodeert de stationrecords en Arkamys-hexparen, vergelijkt de downgrade en legt alle blokbytes en hashes vast in [radio-audio-blocks.json](firmware/radio-audio-blocks.json). Het maakt geen flashbaar pakket.

Evidence: [MicomManager-disassembly](disassembly/MicomManager.exe.asm), [pseudocode](decompiled/705md/MicomManager.exe/decompiled.c), [wire-framing](micom-protocol.md).
