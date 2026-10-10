# Twee LGU-kandidaten: BT8T03 en originele applicaties

Max vraagt op 9 oktober 2026 om LGUs voor de testversie en terugkeer naar originele AppMain/Blue, zodat dagelijks CE-handmatig kopiëren niet nodig is. De containers zijn gebouwd; de **installatieroute is nog niet gevalideerd en deze kandidaten zijn niet klaar voor installatie**.

[Reviewbundle](../build/bt-app-lgu-pair-BT8T03.zip), [test-LGU](../build/bt-app-lgu-pair-BT8T03/Test-BT8T03/BT8T03-apps.candidate.lgu), [originele-applicaties-LGU](../build/bt-app-lgu-pair-BT8T03/Restore-705MD/restore705-apps.candidate.lgu), [instructies/beperking](../build/bt-app-lgu-pair-BT8T03/READ-ME-FIRST.txt), [manifest](../build/bt-app-lgu-pair-BT8T03/manifest.json), [builder](../tools/build_bt_app_lgu_pair.py).

## Exacte inhoud en verificatie

Iedere LGU bevat uitsluitend:

- `upgrade/Storage Card/System/AppMain.exe`
- `upgrade/Storage Card/System/Blue.exe`

De testbytes zijn exact die van [BT8T03](bt-menu-audio-test-build.md), met acht opgeslagen apparaten, de audiobufferpatch en labeloptimalisatie. De restorebytes zijn exact de originele bestanden uit de 7.0.5.MD-bron. Die originele bestanden zijn geen backup van de actuele unit.

| Pakket | Headerlabel | Bytes | SHA-256 |
| --- | --- | ---: | --- |
| Test | `7.0.5.MD.T03` | 1.066.124 | `c734078288e1529df7c6ed450fcba9cc3446e81206ffa31d209d5e1854cf7a22` |
| Originele apps | `7.0.5.MD.Z03` | 1.066.122 | `46ea8df2498656eeb5b774c194e256e4bcecd9ed70ecc5b9f877326b4e549896` |

Bundlehash: `ccca6ba9ce18571009b89fb86d3bcc1f28fb6b9eafb8b8bc72667fbc4ae41a6b`.

De builder controleert de bestaande BT8T03-manifest-/tool-/sourcehashes en label-evidence. De gepinde x86-PC-writer maakt LGU0; onafhankelijke Python-verificatie controleert header, totale grootte, label, XOR, container-CRC, cryptheaders en iedere membergrootte/CRC/SHA. De afzonderlijke x86-PC-extractor levert exact dezelfde twee paden en bytes. Alle sources en ZIP-bundlemembers zijn opnieuw gecontroleerd. Er is geen MIPS-/firmware-executable gestart of unitactie uitgevoerd. De al geslaagde BT8T03-instructiechecks worden via exacte byte-identiteit hergebruikt.

Version_Info.txt wordt niet vervangen. De headerlabels dienen voor herkenning, terwijl de geïnstalleerde versie behouden blijft. Het lexicale model controleert test → restore → test voor huidige labels `7.0.5.MD`, `7.0.5.MD.MAX01` en `7.0.5.MD.MAX02`: beide aangeboden labels zijn steeds groter dan het ongewijzigde huidige label. Er zijn negen modelstappen; dit is geen uitgevoerd USB-installatiebewijs. Andere actieve labels moeten afzonderlijk worden gecontroleerd. Dezelfde aangesloten USB kan dezelfde update opnieuw aanbieden.

Geen database, settings, nav, NK, booter, firmware.hex, updater of autorun is opgenomen. Restore herstelt uitsluitend originele applicatiecode; voor exact oude pairings zijn de opgeslagen pre-test sc_db.db en eventueel actuele eigen executablebackups nodig. De originele apps ondersteunen vijf opgeslagen apparaten. Deze LGUs zijn geen herstel voor een unit zonder werkende update-interface.

## Concrete installerbeperking

Het bestaande [updater-herstelonderzoek](updater-recovery-contracts.md) en [MCU-updatepad](micom-mcu-update-chain.md) zijn live tegen de lokale 7.0.5.MD-decompilatie gecontroleerd:

- `15660` extractie wordt gevolgd door `15880` → `17530` bij extractiesucces.
- `17530` post de MICOM-upgradeaanvraag ook zonder firmware.hex.
- De ontbrekende-imagebranch bouwt A1/tag08 met 1024 nulbytes. Onder de bewaarde initializer-/ISA-aanname volgt MCU-code dezelfde programmeerwrapper vóór zijn eind-/resetpad; er is geen aangetoonde reboot-only-bypass.
- Rootmodus is geen simpele omweg: herkenning verwacht het speciale `nng_content`-label en de gevolgde completion blijft dezelfde firmwarefunctie gebruiken. Zij is niet als apps-installatiemethode geselecteerd.
- De stock updater heeft bovendien reeds vastgelegde copy-/marker-/configbackupfouten. Een correcte container repareert die niet.

De kandidaten dragen daarom expliciet `installation_ready=false` en hebben geen direct aangeboden `upgrade.lgu`-naam. **Niet installeren of naar upgrade.lgu hernoemen voordat een apps-specifieke installatiestop/restart-/readbackroute is gevalideerd.** Volgende noodzakelijke stap voor de gewenste dagelijkse LGU-workflow is die updaterroute oplossen en toetsen; een verpakking van twee apps alleen is daarvoor onvoldoende. Er is geen volledige firmware-/MCU-payload toegevoegd als verborgen workaround.
