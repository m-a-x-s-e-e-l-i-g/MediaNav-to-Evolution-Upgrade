# Eerste analyse — MediaNav 7.0.5.MD

Uitgangspunt uit de vorige chat: originele hardware, werkende Windows CE-desktop, huidige versie 7.0.5.MD, en streven naar nul functieverlies. Onderzocht op 8 oktober 2026. Alleen lokale extractie en statische analyse; geen verbinding met of wijziging van de unit.

Dit document bewaart de eerste inventarisatie. Het [vervolgonderzoek](research-02.md) vult de oorspronkelijke open punten aan: ROM-extractie, opstartcode, MICOM-updatepad, gecombineerde payloads en versiegebonden IPC/USB-commando's zijn inmiddels onderzocht.

## Wat vaststaat uit de bestanden

De hoofd-update bevat `upgrade/Storage Card/System/Version_Info.txt` met `7.0.5.MD`, een CE-image `upgrade/Storage Card/NK.bin`, `firmware.hex` en applicatiebestanden. Dat is voldoende om nu applicaties en communicatie te onderzoeken. Het is geen aangetoonde volledige NAND-back-up of bewezen herstelprocedure.

| Bestand | Directe bevinding | Betekenis voor onderzoek |
| --- | --- | --- |
| `AppMain.exe` | Importeert `COREDLL.dll`, `ole32.dll`, `CmnDll.dll`, `QtCore4.dll` | Eerste kandidaat voor analyse van de hoofdinterface en communicatie met managers |
| `CmnDll.dll` | 35 benoemde exports, waaronder `IpcPostMsg`, `IpcSendMsg`, `IpcGetMsg` en gedeeld-geheugenfuncties | Concrete bestaande communicatiegrens om te reverse-engineeren |
| `Blue.exe` | Bluetooth-debugstrings en import van `CmnDll.dll` | Bluetooth-component; actieve functies en protocol nog te onderzoeken |
| `MgrUSB.exe` | Strings `ShmMxMgrUsbAppMain` en `ShmFmMgrUsbAppMain` | Mutex/geheugen-kandidaten voor USB-status; layout nog te verifiëren |
| `MicomManager.exe` | Strings over GPS, ECU-configuratie en `MgrMcmShm`; importeert `RVD.dll` en `EchoCanceller.dll` | Waarschijnlijk meerdere hardwaretaken; precieze verantwoordelijkheden nog niet vastgesteld |
| `dboot.exe` | Strings `DBOOT 2.0 - 2017`, explorer, dmenu, `dboot.ini`, `Storage Card3/StartWinCE` | Meegeleverde desktop/bootmodificatie; strings bewijzen nog niet de opstartvolgorde |
| `NK.bin` | CE `B000FF`-formaat, 114 records met geldige optelchecksums, geen trailing bytes | Geldige recordstructuur; inhoud van ROM/kernel/drivers nog apart uit te pakken |
| `firmware.hex` | Aanwezig als aparte payload | Doelcomponent nog onbekend; niet als bootloader of MICOM-firmware benoemen zonder bewijs |

Alle 49 PE-bestanden in de hoofd-update melden machine `0x0166` (`IMAGE_FILE_MACHINE_R4000`) en Windows CE GUI-subsystem. Een debugpad in DBOOT vermeldt `SDK_md (MIPSII)`. Dit geeft MIPS als analyse-/compileerrichting; de exacte CPU, RAM en flashcapaciteit zijn hiermee niet vastgesteld. Een ARM-build past niet bij deze binaries.

`NK.bin` meldt image-start `0x80100000`, image-lengte `16951196` en launch-address `0x80100004`. Dit zijn velden uit het CE-containerformaat, geen rechtstreeks afgeleide NAND-partitieadressen. Zie `705md-nk.json`.

## Het pakket is niet het hele draaiende systeem

De hoofd-update heeft geen `Storage Card4`-payload en bevat geen `nngnavi.exe`. Het corruption-fixpakket bevat uitsluitend `upgrade/Storage Card4/NNG/nngnavi.exe` (10.364.952 bytes). Het remove-md-pakket heeft versiebestand `4.0.6` en oudere applicaties; het is bruikbaar als vergelijking, niet als 7.0.5.MD-baseline.

Kaarten, licenties, persoonlijke configuratie, werkelijke registry, actieve processen, bootloader en fysieke partitie-indeling zijn met deze drie pakketten niet volledig aangetoond. Voor onderzoek aan de interface en applicaties is nu geen unit-dump nodig. Voor claimen van identieke software, volledig herstel en nul functieverlies blijft onderzoek aan de unit nodig.

Meegeleverde DAB- en iPod-componenten en graphics voor meerdere modellen betekenen niet dat die functies/hardware op jouw unit beschikbaar zijn. De functiebaseline moet uit de werkelijk aanwezige opties komen.

## Concrete eerste communicatiegrens

`AppMain.exe` importeert uit `CmnDll.dll`: `IpcPostMsg`, `DbgDebugPrint`, `IpcGetMsg`, `IpcSendMsg`. Het meegeleverde `CmnDll.dll` exporteert onder andere:

| Functie | Ordinal | RVA |
| --- | ---: | --- |
| `IpcGetMsg` | 12 | `0x32b8` |
| `IpcPostMsg` | 16 | `0x2d60` |
| `IpcSendMsg` | 17 | `0x2fec` |
| `IpcSetProcessHandle` | 18 | `0x2c4c` |
| `MSHM_Dll_MakeMappingReadOnly` | 32 | `0x3910` |
| `MSHM_Dll_Read` | 34 | `0x3948` |

RVA's zijn relatief aan de DLL-imagebase, geen bestandsoffsets. De stringsrapporten gebruiken juist bestandsoffsets. Imports, exports, imagebases en secties staan in `705md-pe.json`.

De externe `MediaNavMods`-broncode beschrijft ook USB shared memory, een IPC-structuur en commando's voor next/previous/play. Dezelfde geheugennaam staat in onze binaries. Dat is een bruikbare hypothese, geen bevestiging dat message-ID's, struct-layouts of hook-adressen identiek zijn. Die broncode richt zich expliciet op Evolution **9.1.3**, met versiegebonden binary patches. Zijn SDK en absolute adressen niet rechtstreeks op MN1 7.0.5.MD toepassen.

## Eerstvolgende onderzoek

1. Analyseer de kleine `CmnDll.dll` op MIPS little-endian: reconstrueer IPC-argumenten, registratietabel, berichtcodering en ontvangende processen vanaf bovenstaande exports.
2. Volg in `AppMain.exe` de aanroepen van `IpcPostMsg`/`IpcSendMsg`; leg doel, commando, payload en UI-trigger vast voor USB en daarna Bluetooth/radio. Bevestig ieder ID in deze versie.
3. Reconstrueer shared-memory layouts met de code die ze schrijft en leest. Gebruik broncode van 9.1.3 uitsluitend als zoekhulp.
4. Pak ROM-modules en registry uit `NK.bin`, documenteer bootketen en drivers; stel apart vast wat `firmware.hex` bevat.
5. Vergelijk later de bestanden op de unit met de baselinehashes en registreer processen/registry plus aanwezige functies. Maak pas daarna een USB-testapp die eerst alleen status leest.
6. Wijzig pas een component wanneer radio/RDS, audio/volume/mute, Bluetooth-muziek/bellen, microfoon, USB, navigatie/GPS, stuurbediening, camera indien aanwezig, instellingen en slaap/wake/startgedrag een toetsbare nulmeting hebben.

De eerste verbetering kiezen op basis van deze analyse en metingen. Nul functieverlies is een acceptatiecriterium, geen reeds bewezen eigenschap.

## Grenzen van de parser

`pefile` geeft onder meer relocation-waarschuwingen bij MIPS-binaries en resource-waarschuwingen voor `cereboot.exe`. Ze staan ongewijzigd in de PE-rapporten. De PE's zijn te inventariseren; zulke waarschuwingen zijn zonder verdere analyse geen bewijs voor beschadigde extractie of correct runtimegedrag. Container-CRC's en hashes worden apart gecontroleerd.

## Uitgevoerde verificatie

`py tools/analyze_firmware.py --verify-lgu` is succesvol uitgevoerd. Alle archief-CRC's, bestandssets en SHA-256-vergelijkingen kloppen voor alle drie de pakketten. Alle 114 NK-recordchecksums kloppen.

| Pakket | Uitgepakte bestanden | Uitgepakte bytes | PE-bestanden |
| --- | ---: | ---: | ---: |
| 7.0.5.MD hoofd-update | 1.917 | 115.395.580 | 49 |
| Corruption-fix | 1 | 10.364.952 | 1 |
| Remove MD / 4.0.6 | 1.043 | 60.618.903 | 40 |

Pakkethashes en verificatieresultaten staan in `summary.json`. Originele payloads zijn ongewijzigd gebleven. Inmiddels zijn ROM-modules uitgepakt en delen van de MIPS-code gedisassembleerd; zie het vervolgonderzoek voor verificatie en conclusies. Er is nog geen Ghidra-project, volledige decompilatie, unit-dump of runtime-test.

## Bronnen

- [Jouw upgradepakketten en handleiding](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade).
- [Jouw LGU-tools, v3.03 FavreMod](https://github.com/m-a-x-s-e-e-l-i-g/LGU-file-tools).
- [Gepubliceerde LGU-decoder](https://github.com/yosicovich/MediaNavMods/blob/master/pc/lgutool/lgu2dir/lgu2dir.cpp): 1024-byte header, herhalende XOR-tabel en ZIP-payload met een vaste containerpassword.
- [Externe MediaNavMods-broncode](https://github.com/yosicovich/MediaNavMods), uitsluitend als versiegebonden onderzoeksreferentie.
