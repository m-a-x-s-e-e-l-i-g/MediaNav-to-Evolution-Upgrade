# AppMain: startup, managerlaunches, verborgen paneel en beeldresources

Ontwikkelvervolg: [menuverwerking en performanceonderzoek](media-responsiveness-development.md) voegt een gelijkwaardige one-pass Hebrew scan toe en controleert startupvolgorde met 48 actual-byte fixtures. Startup/source-switch waits zijn ongewijzigd; native timing/readiness blijft open. De oorspronkelijke analyse hieronder blijft behouden.

Statisch gevolgd in de aanwezige 7.0.5.MD-bestanden. Geen firmwarecode uitgevoerd en geen apparaat geopend. `tools/inspect_appmain_startup.py` controleert zes bronhashes, bewaart de originele code-/tabel-/stringbytes en schrijft `analysis/firmware/appmain-startup-contracts.json`. De synthetische commandoregelmodellen zijn geen uitvoering van MIPS-code.

## Hoofdapp en vensters

`AppMain.exe` heeft SHA256 `6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8`. PE-entry `0x1407f8` gaat via CRT `0x140724` naar WinMain `0x134948`. De oorspronkelijke instructies bewaren hInstance uit a0, commandoregel uit a2 en nCmdShow uit a3. De extra `double`-parameter in sommige Ghidra-vensterhandlers is een type-artifact: WndProc `0x13120c` bewaart a0/a1/a2/a3 als HWND/message/wParam/lParam.

WinMain registreert klasse/titel `AppMain`, style 3, WndProc `0x13120c`. Een NULL-commandoregel of afwijkende eerste 23 UTF16-code-eenheden beëindigt startup. De vaste vergelijkingstekst is `bd9r2a@_4G2g=J2tq7X@app`; na 23 gelijke tekens stopt de lus zonder terminator te vergelijken. Extra suffixtekst passeert deze lokale check.

InitInstance `0x13487c` initialiseert de fonts en maakt een venster op (0,0), **800×480**, style `0x92000000`, extended style `0x04000000`, zonder parent/menu. Daarna ShowWindow(1), UpdateWindow en de TranslateMessage/DispatchMessage-lus. GetMessage wordt uitsluitend op nul getest; een eventuele -1 is niet afzonderlijk afgehandeld in deze lus.

De GUI heeft eigen `CGUI...`-klassen en GDI-bitmap/fontgebruik. Helper `0x13766c` registreert per object een klasse `CGUIEmptyDlg %p`, met WNDCLASS op object+0x8c, naam op +0xb4 en registratievlag +0x5c. Dit volgt uit raw MIPS; de Ghidra-CONCAT22 rond RegisterClassW is geen extra native voorwaarde. De aanwezigheid van QtCore4 betekent op zichzelf niet dat deze schermen Qt-widgets zijn.

## WM_CREATE en hoofdmanager

Het WM_CREATE-pad in `0x13120c`:

1. Leest/vergelijkt/schrijft `HKLM\LGE\SystemInfo\VerAppmain`; ingebouwde datum `2016-02-16` en buildtekst `17195` gaan in de formattering. WM_CREATE `0x131484..0x1314d8` en het informatiepaneel gebruiken dezelfde maand-/dag-subvelden: `02.16.17195`.
2. Schrijft ALBUMART_WIDTH en ALBUMART_HEIGHT op 278; bewaart het hoofdvenster/hInstance en volgt illumination naar `0xd64a0`.
3. Als CodeChecker niet als venster aanwezig is: timer 0x3fa met 5000 ms. De timer maakt via `0x1145e4/0x114680` een afzonderlijk object/venster; diens volledige betekenis blijft open.
4. Maakt het hoofdmanager-venster via `0xd4a68/0xd56ac`; stuurt IPC 21→3 commands 0x89 en 0xba, telkens vier bytes uit systeemstatus.
5. Start navigatie via `0xd6270` en managers via `0x130e50`; zet timer 0x3eb op 1000 ms.
6. Controleert `/Storage Card2/DATA/BLUE/conn_phone.db` en zet een aanwezigheidsveld als het bestand bestaat.

`0x130e50` maakt/initieert meerdere GUI-/controllerobjecten, leest source-history/resumestatus, bewaart taal-LCID, start USB/iPod via `0xd9114`, wacht 600 ms, start Blue, zet bootstatus en stuurt IPC 21→3 command 0xb7. Bij systeemobject+0x245c != 0 start het ook MgrDAB. De verdere virtuele callbacks en betekenis van alle controllerobjecten blijven open.

MicomManager `0x1f444` bevat daarnaast een pad dat eerst `blue.exe` en daarna `AppMain.exe` start. De dubbele Blue-launch hoeft geen tweede manager op te leveren: Blue controleert mutex `BLUE` en stopt bij ERROR_ALREADY_EXISTS (183). De volledige MICOM-branchvoorwaarden zijn nog niet af.

## Launchmatrix en ontvangende checks

Managerpaden ontstaan via `0x13d28`: GetModuleFileNameW van AppMain, terugzoeken naar backslash en afsluiten ná die backslash; fallback `\`. De vier launches gebruiken `%s%s`, dus normaal bestanden naast AppMain. Succesvolle CreateProcess-calls sluiten beide geretourneerde handles; het sluiten beëindigt het childproces niet.

| Proces | AppMain-launcher | Commandoregel | Ontvangend pad |
| --- | --- | --- | --- |
| Blue.exe | 0xd5c98 | `er10q4c$=4G2g-H2tq9X@mid` | 0x34118: wcsncmp 24 tekens; prefix/suffix geaccepteerd; mutex BLUE vóór tokencheck |
| MgrIpod.exe | 0xd5dcc | zelfde managertekst, of `Resume` bij argument != 0 | 0x181c8: managerprefix 24 of Resumeprefix 6; resumevlag 1; mutex via IPC-processnaam 6 |
| MgrUSB.exe | 0xd5eec | `%d bd9r2a@_4G2g=J2tq7X@app` | 0x24480: wcstok met alleen spatie; eerste token `1` zet resume, alle andere waarden zetten 0; tweede token exact; extra derde tokens genegeerd |
| MgrDAB.exe | 0xd602c | managertekst | 0x39330: prefix 24; mutex MGRDAB; init en message-loop |
| glnavi.exe | 0xd6270 | ` -LCID:%d -Product:kk9r2a@=4F2g-J2tw6X@navi` | vast pad `/Storage Card/System/glnavi.exe`; launcher apart gevolgd in research-03/display-overlay |

Bij `0xd9114` is iPod-resume afhankelijk van registry Inserted, positieve historycount en laatste source-id 3. Anders mass-storage-resume bij Inserted/source-id 2. Zonder passende history worden beide zonder resume gestart, daarna `0xd925c`. De managertekst is een ingebouwde launchcheck; deze analyse bewijst geen andere toegangscontrole.

Navigatielaunch schrijft OSVersion, leest MAPCODE met default `NO MAP` en start alleen als het resultaat hiervan afwijkt. LCID komt uit de DWORD-tabel op 0x185498, geïndexeerd met systeemobject+0x236c. Deze launchroutine controleert de index niet zelf; de validatie van alle writers blijft open.

## Verborgen toetsenpaneel

Constructor `0x27710`, eventhandler `0x28218`, object-id 0x59. Event 1000 verwerkt precies vier UTF16-code-eenheden vóór NUL. De berekening is gewogen UTF16-waarden minus 0xd050; de normale toetsen-events 1001..1010 voegen uitsluitend cijfers toe, tot vier tekens. Event 1011 wist één teken, event 1012 sluit het paneel. Een afzonderlijke digitcheck in de submitbranch ontbreekt, maar de normale keypad-route levert cijfers.

| Vier cijfers | Voorwaarde | Bewezen actie |
| --- | --- | --- |
| 1111 | altijd | opent object uit 0x28f30, id 0x58, met zeven versietekstvelden; populatie 0x27154 hieronder |
| 1119 | altijd | zoekt `\Storage Card\ULC2_Trigger.exe`; start indien bestand aanwezig en venstertitel ULC2_Trigger nog niet bestaat |
| 0362 | altijd | leest HKLM SystemInfo TEST_MODE en wisselt 0→1, elke andere waarde→0; bewaart dezelfde waarde in dit paneelobject |
| 6971 | object TEST_MODE == 1 | calls 0xd7218/0xd7e60, WM_CLOSE naar hoofdapp, CreateProcess `\Windows\explorer.exe` |
| 3740..3749 | object TEST_MODE == 1 | IPC 21→3 command 0xc6 met DWORD 0..9; exacte MICOM-handler/effect nog open |
| 9999 | object TEST_MODE == 1 | wisselt HKCU ControlPanel\Comm AutoCnct; bij inschakelen ook Cnct naar de tekst `` `Default USB` ``; wist codebuffer |
| 4444 | object TEST_MODE == 1 | Bluetoothwrapper 0x11b464: command 0x1060901 |
| 4445 | object TEST_MODE == 1 | Bluetoothwrapper 0x11b5c8: command 0x1060301, `com.ahamobile.shoutapp.e` + NUL, 25 bytes |
| 4446 | object TEST_MODE == 1 | dezelfde wrapper/command, ingebouwde tekst `LL29PAF236` + NUL, 11 bytes |
| 2222, daarna 2223 | object TEST_MODE == 1 | wisselt ResourceManager-profiel naar 1 respectievelijk 0; verwijdert/herlaadt reeds gecachete bitmaps en roept 0xe1758 aan |

De constructor zet de lokale TEST_MODE-vlag op 0, maar **initControls 0x2815c leest vervolgens de registrywaarde en bewaart die op object+0x5d70**. De virtuele methode op +0x20 wijst naar deze initializer en wordt door `0x135454` bij dialoginitialisatie aangeroepen. Het submitpad gebruikt deze herstelde lokale vlag. Code 0362 leest en wisselt zowel registry als lokale vlag. Constructorveld 7777 wordt geïnitialiseerd maar niet gebruikt in deze handler. Gedrag op de echte unit is niet getest.

### Toegang vanuit systeemversie

Singleton `0x1f1dc` maakt object-id 0x4d met vtable 0x16facc. Debugtekst in `0xcab14` noemt `CSystemVerDlg::initControls`; de callback op vtable+0x44 is `0xcacbc`. Constructor `0xca600` maakt vijf gebieden via `0x13d488`, die het eventnummer in control+0x48 zet. De gebruikte vier-DWORD-layout wordt behandeld als x/y/breedte/hoogte:

| Volgorde | Event | x | y | breedte | hoogte |
| --- | ---: | ---: | ---: | ---: | ---: |
| 1 | 1001 | 0 | 0 | 200 | 150 |
| 2 | 1002 | 110 | 330 | 200 | 150 |
| 3 | 1003 | 600 | 0 | 200 | 150 |
| 4 | 1004 | 300 | 0 | 200 | 150 |
| 5 | 1005 | 600 | 330 | 200 | 150 |

De volgorde staat als state 0..4 op object+0x24e4. Een verkeerde van deze vijf events zet state terug op 0. Het vijfde correcte event maakt/activeert het toetsenpaneel via `0x136494` en reset state. InitControls reset state eveneens. Andere default-events resetten deze state niet; dit is dus geen bewezen tijdbegrensde of strikt opeenvolgende touchdetectie. De gedeelde touch-to-event/hittestketen is inmiddels gevolgd in [het GUI-vervolg](appmain-gui-contracts.md); deze tabel is statische geometrie, geen op de unit getest bedieningsrecept.

### Versiepaneel achter 1111

`0x270c8` roept styling `0x274f8` en populatie `0x27154` aan. De tekstvelden tonen `F/W Ver` uit VerMicomFW, `B/L Ver` uit DWORD Bootversion, `S/W Ver: 02.16.17195` uit de ingebouwde datum/build, `OS Ver` uit OSVersion2, `Blue Ver` uit VerBlue en `Navi Ver` uit NaviVersion. Bij DAB-aanwezigheid toont de zevende regel `DAB Ver: <DAB Mgr Version>(<DAB FW Version>)`. Registryroots zijn HKLM LGE\SystemInfo. De AppMain-versietekst is nadrukkelijk niet hetzelfde als de algemene firmwarepakketversie 7.0.5.MD.

## Beeldresources en fonts

ResourceManager `0x1fbfc` leest UI_TYPE default 0 en UI_INVERSE default 0. Alleen UI_TYPE 1 met UI_INVERSE 1 wordt profiel 3; type buiten 0..3 wordt 0. Vier originele labels: **M0, M1, M0_INV, M1_INV**. Het resourcepad is AppMain-directory + `img/<profiel>\`; fontpad is + `font/`. `0x13dbbc` verandert het huidige pad via vtable+4 (`0x1ff54`), verwijdert/herlaadt alle gecachete HBITMAPs. In dit gevolgde pad wordt UI_TYPE niet teruggeschreven.

Op 0x185980 staan **461 image-id/pointerrecords**. Getimage `0x13dde0` cachet per id, vraagt het pad via vtable+0xc (`0x1ffbc`), en roept SHLoadDIBitmap aan. De lowercase suffix `png` volgt een aparte branch die uitsluitend logt en de handle op nul zet. Alle catalogusnamen zijn als originele UTF16-bytes bewaard. Sommige namen bevatten `..\COMMON\...`, dus verwijzen naar de gedeelde map naast de profielen.

| Profiel | Catalogusverwijzingen met bestand in uitgepakte update |
| --- | ---: |
| M0 | 459/461 |
| M1 | 459/461 |
| M0_INV | 44/461 |
| M1_INV | 459/461 |

De 44 M0_INV-hits zijn verwijzingen naar de gedeelde COMMON-map. M0/M1/M1_INV missen in deze update `home\home_4wd_btn.bmp` en `common\compass_bg.bmp`. Er is in de gevolgde resourcepad-/loadhelpers geen alternatief profiel bij laadfout. Dit is een pakketvergelijking: bestaande bestanden op de unit en werkelijke profielkeuze kunnen anders zijn. JSON bevat per id vier aanwezigheidrecords, bestandshash, grootte en bij BMP de originele headerdimensies/bitdiepte/compressie.

`0x13107c` maakt 22 fonts via `0x13dcac`: hoogtes 16,18,20,21,22,23,24,25,26,28,29,30,32,34,36,39,40,42,45,50,60,65. LOGFONT gebruikt `tahoma`, negatieve hoogte, gewicht 400, quality 4 en berekende breedte. Op het fontobject staan 22 handles en 22 bijbehorende hoogtes. Volledige textdraw/antialiasing-/resamplingroutes blijven open.

## Afzonderlijke grensbevindingen

WM_COPYDATA met wParam 0xd13 en dwData 1: `0x131728` wist een lokale buffer van 0x20a bytes; `0x131748..0x131754` voert memcpy uit met cbData rechtstreeks uit lParam+4 en bron uit lParam+8. Er staat tussen de branch en copy geen bovengrenscheck voor cbData. Daarna volgt kopiëren van metadata en een bounded-stringpad. Dit is een statisch ontbrekende lokale lengtegrens, geen aangetoonde crash of aanval op de unit.

De bitmapgetter controleert signed id < count en id != -1, zonder algemene id >= 0-check. Andere negatieve ids zouden binnen deze routine vóór de handle-array kunnen indexeren. Welke callers zulke ids werkelijk kunnen leveren is nog open.

## Reproductie en resterend werk

`py tools/inspect_appmain_startup.py`: zes originele bronhashes, 516 bewijsbereiken inclusief twee virtuele methodetabellen, 461 beeldrecords × vier profielen; 124 prefixgevallen, acht USB-tokengevallen, vijf gesturefixtures en alle 10.000 normale viercijferwaarden. De constructorconstanten worden rechtstreeks uit addiu/sw-paren afgeleid en tegen de veldmapping gecontroleerd. `py -m py_compile tools/inspect_appmain_startup.py` controleert het hulpmiddel.

Open: overige schermconstructors/paint/events; fysiek touchgedrag van paneel 0x59; MICOM 0xc6 en Bluetooth 4444..4446; taal-/sourcevalidatie; volledige shutdown/audiofocus; echte profielbestanden/registry/unitgedrag. Startup en resources zijn nu gedeeltelijk bewezen; AppMain als geheel is nog niet volledig begrepen.
