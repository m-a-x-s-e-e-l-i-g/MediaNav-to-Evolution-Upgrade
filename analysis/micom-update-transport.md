# MICOM-update: ULC-frames en blokselectie

Dit rapport bewaart de Windows CE-kant van `MicomManager.exe` uit 7.0.5.MD, SHA-256 `c56e8e08600cd69a656ec487779d3dbb0cea672ae2c5cb2da685b9217e6f8824`. Er is geen COM-poort geopend en geen firmware uitgevoerd. Het [vervolgonderzoek aan MCU-zijde](micom-mcu-update-chain.md) verbindt AA5 met de ULC-ontvanger en programmeerwrapper onder een initial-RAM-/ISA-aanname; exacte chip, fysieke flashmapping en unitgedrag blijven open.

## Overdracht

De update-entry `0x22cfc–0x22e63` stopt timers en laadt Intel HEX naar een buffer van 256 KiB. Zij zet objectveld `+0x18` op 1, stuurt de gewone AA-opdracht `(manager=1, type=1, command=5, length=0)`, zet de teller op 1 en roept `OnRequest(0x20)` aan. Na een laadfout wordt de imagehouder verwijderd; dezelfde AA-opdracht volgt, waarna een apart ULC-frame met type `A1`, tag `08` en 1024 nulbytes wordt geschreven. De gevolgde MCU-kandidaatketen geeft dat frame door aan de programmeerwrapper vóór zijn eind-/resetroute; een reboot-only bypass is niet aangetoond. Fysieke writes, block-/bootswap en daadwerkelijke reset zijn nog niet geverifieerd.

`0x283b0–0x284e7` bouwt het volgende formaat:

| Offset | Bytes | Betekenis aan Windows-zijde |
| --- | ---: | --- |
| 0 | 3 | `55 4C 43`, ASCII `ULC` |
| 3 | 1 | `A0 OR flags`: gewone transfer `A0`, laadfout `A1`, laatste geselecteerde blok `A4` |
| 4 | 1 | Bloktag |
| 5 | 1024 | Payload |
| 1029 | 1 | Som van type, tag en payload modulo 256; ULC-prefix telt niet mee |

Een frame is dus **1030 bytes**. Dit is een ander checksumformaat dan de XOR van gewone AA-frames. De functie doet vier afzonderlijke `WriteFile`-calls, van 3, 2, 1024 en 1 byte. Alleen de BOOL van de laatste call wordt teruggegeven; eerdere BOOL-resultaten en alle werkelijk geschreven byteaantallen blijven ongecontroleerd. `OnRequest` gebruikt ook die laatste BOOL niet. Een lokale succesvolle call bewijst daardoor geen volledige overdracht of flashverificatie.

## Eerste pass door het firmwarebeeld

`OnRequest`, `0x1d750–0x1d91b`, doet alleen werk als veld `+0x18 == 1`; zij wacht 50 ms. De bronindex is `min((counter - 1) & 255, 223)`. De teller start op 1.

| Bronblok in image | Bestandsoffset | Wire-tag | Flags |
| --- | --- | --- | --- |
| 0–7 | `00000–01FFF` | 8–15 | 0 |
| 8–15 | `02000–03FFF` | Geen | Overgeslagen |
| 16–222 | `04000–37BFF` | 16–222 | 0 |
| 223 | `37C00–37FFF` | 223 | 4 |
| 224–255 | `38000–3FFFF` | Geen | Overgeslagen |

Na bronblok 7 springt de teller van 8 naar 17. De eerste pass omvat **216 frames**, **221.184 payloadbytes**, **222.480 wirebytes**. De acht lage overgeslagen blokken zijn volledig `FF`. De hogere overgeslagen regio bevat **1874 niet-FF-bytes**: 1010 in blok 224, 176 in 225, 688 in 226. De rest is `FF`. Het hogere gebied mag dus niet als louter lege opvulling worden behandeld. Beschermde data of een aparte flashregio is een mogelijke verklaring, nog geen bewezen betekenis.

De [MCU-flashlibrary-analyse](micom-flash-library-contracts.md) verbindt tags met logische libraryadressen: tag × 1024. De eerste acht bronblokken worden dus naar `2000–3fff` aangeboden, passend bij het tweede Fx3-bootvenster. De fysieke flashhelft achter een bestaande bootmapping en daadwerkelijke ROM-write blijven onbekend.

De routine wist de updatevlag niet na `A4`. Een volgende aanvraag herhaalt bronblok 223; de teller blijft stijgen en de selectie heeft uiteindelijk een 8-bit wrap. De voortgangsweergave gebruikt de teller vóór het verzenden: het eerste `A4` verschijnt bij 100%. Dat is een tellerwaarde en geen flash-readback. Er is in deze gevolgde keten nog geen expliciete inhoudelijke MCU-succesbevestiging gevonden.

## AB-status raakt verloren

`ReadCommand` leest een AB-reactie als twee bytes. De ontvangende thread `0x25cac–0x25e1b` laadt het eerste DWORD, herkent de lage byte `AB`, en gebruikt bij `0x25d58` opnieuw `AND 0xFF`. Daardoor stuurt `PostMessageW(..., 0x402, 0xAB, 0)` de marker door, zonder de tweede statusbyte. `WndProc`, rond `0x27a98`, geeft die lage wParam-byte aan `OnRequest`.

`OnRequest` heeft aparte fouttakken voor `0x21` (log: checksum fail) en `0x22` (flash write fail). Beide verlagen de teller zodat een blok wordt herhaald. Deze takken zijn **niet bereikbaar via de gevolgde AB-ontvangstketen**: de handler ontvangt daar `0xAB`. De andere gevonden directe caller geeft `0x20` door. Dit is een concrete afwijking tussen ontvangstcode en aanwezige retrylogica; de gevolgen op een fysieke unit vereisen een echte capture en MCU-code.

Een extra randgeval: als de retrylogica wél status `21/22` krijgt onmiddellijk na de sprong bij bronblok 7, wordt teller 17 naar 16 verlaagd en selecteert zij bronblok 15. Dat is niet een herhaling van bronblok 7. Ook deze tak is aan Windows-zijde reproduceerbaar, maar wordt niet door de huidige AB-route geactiveerd.

## Object en overige berichten

De CMicom-vtable staat op **absolute VA `0x528e8`**, dus PE-RVA `0x428e8` bij imagebase `0x10000`. Haar vier entries zijn `0x1f3ec`, `0x23fb8`, `0x23308`, `0x21748`. De gewone AA-queue roept de vierde entry aan. `0x21748` verwerkt type-nibbles 2, 3 en 8, waaronder ACC/IGN, temperatuur, toetsen en configuratie. Type 2/commando 0 kan bij powerstate 0 de bootstrap `0x1f444` uitvoeren. Die grote bootstrap is geen bewezen flash-completionhandler en zet de updatevlag niet terug.

## Reproduceerbare evidence

- [inspect_micom_update.py](../tools/inspect_micom_update.py) bewaart bronhashes, ruwe functieranges, blokvolgorde, payload- en framehashes en niet-FF-bytecounts in [micom-update-contracts.json](firmware/micom-update-contracts.json).
- [parse_micom_flash.py](../tools/parse_micom_flash.py) decodeert uitsluitend lokale ULC-captures. Ruis, checksumfouten, afgebroken prefix/frames en onbekende typebytes blijven zichtbaar. Een ULC-prefix binnen de payload verandert de vaste framegrens niet.
- Synthetische verificatie: framing/checksum, beschadigde checksum, embedded prefix, ruis, truncatie, blokskip, A4 en gewone retry. Er is geen echte seriële capture beschikbaar.
- [Disassembly](disassembly/MicomManager.exe.asm), [pseudocode](decompiled/705md/MicomManager.exe/decompiled.c), [normale AA/AB/A6-framing](micom-protocol.md), [boot-/updateketen](boot-update-contracts.md).
