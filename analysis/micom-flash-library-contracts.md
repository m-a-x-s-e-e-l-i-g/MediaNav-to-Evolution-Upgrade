# MICOM: flashadres, chip-ROM en bootwisseling

Statische vervolganalyse van [AA5 → ULC](micom-mcu-update-chain.md), dezelfde imagehash `4c5a45266f11cbd2a408c3b9880008a819091e61c61a7283f51949244bd76512`. Geen firmware uitgevoerd, COM-poort geopend of updatepakket veranderd. De exacte MCU en geïnstalleerde boot-/beschermingsstatus blijven onbekend.

## Welke chipfamilie past bij de code?

De officiële [78K0R/Fx3-hardwarehandleiding](https://www.renesas.com/en/document/mah/78k0rfx3-users-manual-hardware), `R01UH0007EJ0600 Rev6`, beschrijft 1 KiB-flashblokken (p.128), bootclusters van 8 KiB (p.1176–1177) en BECTL op `FFFBEH`, bit 7 voor FLMD0 pull-up (p.1159). Bootcluster 0 ligt op `0000–1fff`, cluster 1 op `2000–3fff`. Flash shield windows en bootclusterbescherming kunnen writes verhinderen (p.1173/1178). Dit past bij onze code, maar identificeert geen exact onderdeel. De handleiding verwijst voor de Type2-library naar `U19193E` (p.1174); die libraryversie is nog niet vastgesteld.

De oudere [Kx3-self-programming application note](https://www.renesas.com/en/document/apn/78k0rkx3-flash-memory-self-programming) beschrijft andere blok-/bootgroottes: 2 KiB en 4 KiB. Zijn functionamen helpen als structurele vergelijking, maar zijn adreskaart wordt hier niet toegepast.

Het officiële Fx3-PDF is lokaal bewaard met SHA256 `5fea7faf79e9aa3dbf2d5fde05635a330692ba8ddd07cf80de0569d9f224a80a`. Tekstselecties bevatten paginanummers.

## Type03-ABI als sterkere vergelijking

De openbare [Type03 application note](https://www.renesas.com/ja/document/apn/78k0r-microcontrollers-flash-programming-library-type03-application-note), `R01AN0005JJ0100`, documenteert retourregister C, schrijfadres AX/BC en woordtelling via de stack (p.35–47). Blankcheck-status `1b` betekent niet-blank; `1f` betekent onderbroken verwerking (p.41). `InvertBootFlag` verandert de selectie na reset, `SwapBootCluster` wisselt direct en springt naar de resetvector, `SwapActiveBootCluster` combineert flagwijziging en directe wissel (p.59–64). Dit past bij respectievelijk `284`, `2e1` en `3a3`; de functietoewijzing blijft een inferentie. De [Renesas-supportlijst](https://www.renesas.com/en/document/mat/self-programming-library-japanese-release-and-supported-mcus) uit 2019 noemt Type03 voor Fx3. De oudere Type2-verwijzing bewijst dus geen libraryidentiteit. Exacte revision/ROM ontbreekt. PDF-hash: `d388a78e7c096800fdf1cb6705bb014552508827b78d146035a659a7a4f22827`.

## Logische adressen uit de firmware

Bij `15c5–15d8` wordt de requesttag naar een 32-bit scratchwaarde gekopieerd en met helper `671` tien plaatsen links geschoven. De schrijfadresargumenten naar `351` zijn **tag × 1024**, gevolgd door de chunkoffset. Helper `671` schuift het lage woord en draagt via `ROLWC` door naar het hoge woord; `68c` doet het omgekeerde voor bloktelling en woordtelling.

Dit verbindt de [Windows-blokselectie](micom-update-transport.md) met de MCU-libraryargumenten:

| Bron in HEX | Wire-tag | Logisch libraryadres |
| --- | --- | --- |
| `0000–1fff` | 8–15 | `2000–3fff`, tweede bootvenster |
| `2000–3fff` | Geen | Overgeslagen |
| `4000–37bff` | 16–222 | Zelfde adresbereik |
| `37c00–37fff` | 223, A4 | Zelfde adresbereik, daarna eindhelper |

Een libraryadres identificeert niet de fysieke flashhelft achter een al gewisselde bootmapping. Er is geen actuele bootflag-/shield-window-readback.

`da/de/e2` zetten command 8/3/6; volgorde en retourtakken passen bij blankcheck/erase/internal-verify. `351` zet command 4, verlangt een vierbyte-uitgelijnd adres en 1–64 vierbytewoorden. Het einde wordt vergeleken met chip-ROM-metadata op `effd0/effd1`; blokgrenzen met `effe4`. De centrale dispatcher roept **`efff8`** aan. Dat adres en deze metadata staan buiten de beschikbare 256 KiB-image. Functionamen blijven structurele FSL-matches; deze chip-ROM is niet gereconstrueerd.

## Buffergrens

`151b` verhoogt H tijdelijk; `151c` schrijft daardoor capaciteit `0100` op **frameoffset `+114`**. `151e` herstelt H. Daarna wordt bij `151f–1523` **frameoffset `+14`** als initbuffer aangeboden. `1ad` schrijft ROM-byte `d8 = 18` naar deze initbuffer, niet naar het capaciteitswoord. `161d–1620` leest opnieuw het afzonderlijke capaciteitswoord op `+114`.

De scratchbuffer beslaat `[+14,+114)`; het capaciteitswoord begint precies erna. Voor een normaal ULC-blok van 1024 bytes biedt het lokale pad dus **vier chunks van 256 bytes / 64 vierbytewoorden** aan, bij oplopende adressen. Status `1f` kan een schrijfcall herhalen; een eerdere fout kan het pad afbreken. Dit bewijst geen vier succesvolle fysieke writes.

Correctie op de vorige analyse: de initbuffer en het capaciteitswoord waren ten onrechte als hetzelfde adres behandeld. `buffer_layout()` bewaart beide decodeerreeksen en projecteert de tijdelijke H-wijziging op zeven expliciete framebases, inclusief 16-bit wrap. Een klokbyte-write en een volledige bufferfill raken het capaciteitswoord niet. Chip-ROM moet wel het aangeboden buffercontract respecteren; zijn interne writes zijn niet beschikbaar.

Het chunkmodel gebruikt nu de uit deze caller gereconstrueerde capaciteit 256, bewaart FF-padding tot een veelvoud van vier en controleert alle payloadlengtes 1–1024. Het valideert arithmetic, geen actuele ROM-retourwaarden of flashwrites.

## A1 versus A4

A1/tag8 met nulbytes komt via de gewone programmeerwrapper bij logisch adres **`2000`**. Alleen na succesvolle programmeerstatus volgt de eindtak naar FF bij `283`. Er is geen reboot-only bypass gevonden. Het pad kan de tweede bootregio wijzigen als de chip-ROM de operatie accepteert; geïnstalleerde mapping, bescherming en status blijven onbekend.

A4 volgt na programmeren helper `284` en pas bij nulstatus dezelfde FF-route. `284` haalt informatie op via command 9/subselector 3 en 7, wijzigt bufferbits met masker FE en roept command A aan. De Type03-vergelijking versterkt de kandidaat-bootflaginversie; exacte ROM-bitbetekenis en persistentie zijn nog niet bewezen. A1 slaat deze helper over.

Helper `2e1` kopieert **61 bytes uit `314–350`** naar de door `f0804` aangewezen buffer, zet CS op F en doet `CALL AX`. Het template bevat 23 kandidaat-instructies. Zijn relatieve tak blijft binnen de kopie; absolute calls blijven naar `212`, `efff8` en `238` wijzen.

Na de ROM-call kiest B=0 het eindpad: beveiligde writes `fffc0=a5`, `fffc4=0c/f3/0c`, BECTL bit7 clear, registerbank 0, ES=0, lees woord op adres 0, CS=0, **BR AX**. De andere tak herstelt interruptmaskers/PSW en retourneert status. Dit ondersteunt een RAM-uitgevoerde bootwissel/jumphelper. Flags 5/6 gebruiken hem; A4 roept hem niet direct aan. Registerbits en ROM-contracten vereisen verder onderzoek.

## Herhaalbare evidence

`inspect_micom_flash_library.py` controleert 37 exacte bytepreimages en bewaart vier oorspronkelijke codebereiken. Het valideert 256 tagadressen, 1024 payloadlengtes, vijf schrijfgrenzen, zeven bufferlayoutprojecties en template-relocatie op vier expliciete model-RAM-adressen. Die fixtureadressen zijn geen waargenomen unitstack. Ghidra bevestigt **alle 23 template-instructielengtes** en de **11 bufferlayout-instructiegrenzen** in de bestaande update-export, zonder ontbrekende of afwijkende grenzen. Lengtes bewijzen geen volledige instructiesemantiek of chipidentiteit; Ghidra's tekstweergave voor INC/DEC heeft ontbrekende registerlabels.

```powershell
py tools/inspect_micom_flash_library.py
py tools/run_micom_ghidra.py --flash-library
```

Evidence: [contracten en bytes](firmware/flash-library/contracts.json), [RAM-template](firmware/flash-library/ram-template.asm), [onafhankelijke lengtes](firmware/flash-library/decoder-comparison.json). Volgende stap: exacte library/hidden-ROM-grens en persistent bootflaggedrag; transportretry en unitvalidatie blijven nodig voor de gecombineerde update.
