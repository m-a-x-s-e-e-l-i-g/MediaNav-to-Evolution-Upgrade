# Vervolgonderzoek: alle modules, firmwarelagen en Bluetooth

Onderzoeksdatum: 8 oktober 2026. Dit is een updatebestandencorpus voor de opgegeven MediaNav 7.0.5.MD. De daadwerkelijke inhoud van de fysieke unit is nog niet met een volledige backup vergeleken.

## Volledige statische inventaris

Alle **256 herkende PE-bestanden** zijn geïnventariseerd en gedisassembleerd:

| Herkomst | PE-bestanden |
| --- | ---: |
| Hoofd-update 7.0.5.MD | 49 |
| Gereconstrueerde Windows CE-ROM | 166 |
| Remove-MD/downgrade | 40 |
| Aparte navigatiefix | 1 |

Imports, exports, secties, hashes, entrypoints, versiemetadata, resources en strings zijn per module vastgelegd. De originele MIPS `.pdata` levert **91.257 functiekandidaten** op. Leaf-functies, indirecte calls en ROM-reconstructie kunnen aanvullende functies of afwijkingen bevatten. `kernel.dll` heeft een afwijkende exception-directory; `nk.exe` heeft ongeldige gereconstrueerde table entries. Hun grenzen worden niet blind als betrouwbaar gebruikt.

Voor hoofd-update, ROM en navigatie zijn alle statische importproviders en ordinals binnen het corpus te koppelen. Dit bewijst geen beschikbaarheid van dynamisch geladen DLLs, bestanden of apparaten op de unit.

De volledige gegevensbestandeninventaris bevat **3.176 bestanden**: 1.917 uit de hoofd-update, 1.043 uit de downgrade, één navigatie-executable en 215 bestanden in de gereconstrueerde Windows-directory. Headerherkenning vindt 2.116 BMP-bestanden, 742 PNGs, 18 RIFF-bestanden en vijf fontsignaturen. Dat zijn tellingen over meerdere versies; duplicaten staan afzonderlijk in de inventaris. Zeven bestanden hebben geen bekende header in deze generieke inventaris. Inmiddels zijn de radiostationrecords en de transferindeling van radio-/Arkamys-parameters [apart gevolgd](radio-audio-formats.md), en alle [FDF-registryrecords](boot-registry.md) strikt gedecodeerd met gecorrigeerde rootkeys. PCM-ringtone, NLS-database en de inhoudelijke betekenis van kalibratiecoëfficiënten blijven open.

Zie [de dekking per module](research-status.md), [PE-catalogus](corpus/index.md), [bestandenmanifest](corpus/data-files.csv) en [gegevensformaten](corpus/data-summary.json). De dekking is nadrukkelijk geen percentage begrepen gedrag.

De [ROM-byteverificatie](rom-verification.md) is uitgebreid: 287 gecomprimeerde modulesecties en 29 gecomprimeerde losse files komen overeen met een onafhankelijke Windows-LZX-decoder. Ook de vier gedeelde-RVA-records van nk.exe/kernel.dll, 20 ruwe ROM-files en de bewaarde TOC-metadata van alle 164 ROM-modules zijn gecontroleerd. Runtimeplaatsing blijft apart onderzoek.

## Firmware heeft meerdere onafhankelijke lagen

| Laag | Aangetroffen versie/identiteit | Waar gevonden |
| --- | --- | --- |
| Applicatiepakket | `7.0.5.MD` | `Version_Info.txt` hoofd-update |
| Windows CE-kernelbuild | `2.0.0.2013` | ROM-defaultregistry, LGE/SystemInfo |
| MICOM-image | `4.0.6.0413(C2)` en `SK0RT03N200GV101` | 256-KiB-image uit firmware.hex |
| Navigatie-engine | `9.4.6.398870`, NNG | Versieresource aparte nngnavi.exe |
| QtCore | `4.8.5.0` | Versieresource QtCore4.dll |
| Bluetooth-bootstrap | 21 build-selecties, meerdere PSR-blokken | Tabel en literals in Blue.exe |

Een MICOM-string `4.0.6` betekent dus niet dat de hoofdinterface ook 4.0.6 is. Het hoofd-CPU-programma is MIPS; de microcontroller-image bevat een andere instructieset.

## Kleine modules concreet gevolgd

`glnavi.exe` is een launcher. Het haalt een desktop-DC op, roept `ExtEscape` met code `0x229c7c` en een vier-byte TRUE-waarde aan en logt `setOSOverlayActivate`. Vervolgens voegt het de commandoregelargumenten samen en start `\\Storage Card4\\NNG\\nngnavi.exe` met `ShellExecuteEx`. Dit gedrag staat in `0x11000–0x1116b`. De [ROM-displayhandler](display-overlay.md) koppelt die escape aan de interne OpenGL-vrijgaveflag; werkelijk inschakelen van window 2 loopt via een ander commando. De argv-samenvoeging gebruikt wcscat zonder een zichtbare lengtegrens in deze functie.

`RVD.dll` is een kleine adapter met vijf exports bovenop RVC: tekenen, versie ophalen, venster instellen, starten en stoppen. `StartRVD` zet het venster op **800×480**, toont het en roept StartRVC aan; StopRVD stopt RVC en verbergt het venster. De echte camera-, I2C- en overlaylogica zit grotendeels in RVC en ROM-drivers. Inmiddels zijn [RVC-configuratie, capture-IOCTLs en een verkeerde capture-fouttest](camera-contracts.md) aan beide kanten gevolgd.

De **31 LangDll-bestanden** hebben dezelfde `.text`-codehash en elk 380 RT_STRING-entries. Hun verschil zit voornamelijk in vertaalresources. De teksten zijn met hun resource-ID's en taal-ID's uitgelezen; zo kunnen toekomstige tekstwijzigingen aan echte IDs worden gekoppeld.

AppMain importeert QtCore4. Dat bewijst QtCore-gebruik, maar geen volledige Qt Widgets-interface: QtGui staat niet tussen zijn statische imports. Het bevat bovendien eigen GUI-klassen en Windows CE-aanroepen. De renderingarchitectuur wordt afzonderlijk gevolgd.

## USB en Bluetooth leveren bruikbare interfacecontracten

De [USB-statusmapping](usb-status-layout.md) is gedeeltelijk gereconstrueerd: tijden, titel, artiest, album, map, bestandsnaam, index, shuffle/repeat/status en coverhandle. De twee overige 520-byte regio's en één DWORD blijven onbekend. Een [offline parser](../tools/parse_usb_status.py) bewaart die onzekerheid.

Bij Bluetooth zijn **BlueEarth** en **BlueEarthBrowse** aan beide kanten gevonden. BlueEarth is 1.300.000 bytes groot. Een metadatablock van 260 bytes op mappingoffset `0xcf0e8` bevat minimaal titel, album en artiest, elk een 50-byte **UTF-8**-buffer. AppMain leest die drie velden en converteert ze naar WCHAR. De USB-structuur gebruikt grotere UTF-16-buffers en heeft een andere volgorde.

De [Bluetooth-layout](bluetooth-layout.md) bevat adressen en de gevonden verschillen in het browse-aanmaakpad. Ook hiervoor bestaat een [offline parser](../tools/parse_bt_status.py), gecontroleerd met synthetische UTF-8-gegevens. Dat is nog geen validatie met een gekoppelde telefoon.

## MICOM: checksums, ISA-kandidaten en decodercontrole

Alle Intel HEX-recordchecksums zijn geldig. De data vullen adressen `0x00000–0x3ffff` zonder gaten, met precies **262.144 bytes**. Het gereconstrueerde image heeft SHA-256 `4c5a45266f11cbd2a408c3b9880008a819091e61c61a7283f51949244bd76512`.

De resetvector wijst naar `0x3c7`. Startup en interruptcode passen bij de **78K0R/RL78-familie**; het exacte chipmodel is niet geïdentificeerd. Een Python-decoder volgt vanaf vectoren en CALLT-roots 49 functiekandidaten, 2.524 instructies en 4.962 afzonderlijke bytes. Dat is een klein deel van de 256 KiB. Indirecte transfers en data/functionpointertabellen begrenzen deze dekking.

Een onafhankelijke Ghidra-uitbreiding bleek fouten te hebben: displacementbytes werden soms niet geconsumeerd, SFR-offsets waren signed, word-adressen werden op vier in plaats van twee bytes beperkt en twee CMPW-opcodes waren verkeerd. De gerichte lokale decoderreparaties zijn getoetst aan de [Renesas-instructiehandleiding](https://www.renesas.com/en/document/mas/78k0r-microcontrollers-users-manual-instructions), tabellen op pagina's 63–66 en het SFR-adresbereik. Upstream bronnen blijven behouden; de [lokale patch](firmware/rl78-local-decoder.patch) is apart vastgelegd.

Na die reparaties geven beide decoders op **alle 2.524 bekende kandidaatinstructies dezelfde instructielengte**. Ghidra is daarvoor op de bekende kandidaatadressen gestart: dit bevestigt de plaatselijke decoding, niet onafhankelijke reachability of de CPU-identiteit. Call/return-pcode, stackmodel, short addressing en registeroperanden in de uitbreiding bevatten nog problemen. Zijn microcontroller-pseudocode wordt daarom niet als bewezen semantiek gebruikt.

Het [MICOM-wireformaat](micom-protocol.md) is rechtstreeks uit de MIPS-manager gevolgd: AA-header, manager/type-nibbles, commandobyte, lengtedeclaratie, payload en XOR-checksum. AB en A6 hebben aparte ontvangstpaden. De [captureparser](../tools/micom_protocol.py) is uitsluitend offline.

## Bluetooth-bootstrapdata in de executable

Een andere firmware/configuratielaag zit ingebouwd in Blue.exe. Op `0x103a14` staat een tabel van **21 entries met stride 12**. De bootstrapselector `0x7c1a8–0x7c3ef` vergelijkt een buildwaarde, kiest een literal PSR-block en geeft dat aan parserhelper `0x7ae94` door. Er is ook een bijzondere route voor selector `0x1d86` onder een tweede conditie en er worden algemene configuratieblokken toegevoegd.

De [bootstrapinventaris](firmware/bt-bootstrap.json) beschrijft 20 aangeroepen literal blocks en 325 sleutelrecords, zonder onbegrepen regels binnen deze geselecteerde blokken. Elke sleutel heeft een lijst 16-bit hexwoorden. De betekenis van alle PS-keys, de ISA van eventuele codepayloads, het transport en welke build jouw unit gebruikt zijn nog open. Een bootstrapblock is niet automatisch een complete Bluetooth-firmware-image.

## Decompilatie en vervolgstappen

Portable Ghidra 12.1.4 en een lokaal JDK 21 zijn met checksums vastgelegd in [toolchainmetadata](re-toolchain.json). Er is geen globale Java/PATH-installatie gedaan. De eigen seedscript koppelt ordinals aan de exports uit dit corpus en voert de gecontroleerde MIPS-functiegrenzen in; de PE-loader ondersteunt die functietabel zelf niet.

De brede decompilatie van hoofd-update, ROM, downgrade en navigatiefix loopt per module in geïsoleerde projecten. [Research-status](research-status.md) houdt geslaagde exports en analyzertime-outs apart bij. Pseudocode blijft zoek- en reviewmateriaal. De hervatte AppMain-analyse is zonder analyzertime-out voltooid en heeft 2.948 functiekandidaten geëxporteerd. Dit betekent dat de automatische analyse is afgerond, niet dat alle UI-/applicatiefuncties begrepen zijn.

De volgende inhoudelijke stappen zijn de resterende Bluetooth-/USB-state machines, AppMain-rendering, radio/DSP-bestandsformaten, camera/ROM-driver-IOCTLs en het volledige MICOM-updatepad. Voor de originele navigatiepatch ontbreekt nog een ongemodificeerde executable van dezelfde versie. Voor conclusies over bootloader, persistente configuratie en de actieve hardwarevariant ontbreekt nog een unitbackup.
