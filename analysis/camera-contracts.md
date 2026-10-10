# RVC en camera.dll: instellingen, capture en drivercontract

De camera-interface zit in RVC.dll; RVD.dll levert vijf kleine wrapperexports. Dit document volgt de pakketcode en gereconstrueerde ROM-driver. De fysieke cameravariant en actieve registry/configuratie zijn niet uit een unitdump bevestigd.

## Capturepad aan beide kanten

RVC opent `CAM1:` op `0x10006900`. De ROM-defaultregistry koppelt prefix CAM aan `camera.dll`. Configure-helper `0x1000697c–0x10006a8b` gebruikt:

| IOCTL | Applicatiebuffer | Gevolgd drivergedrag |
| --- | --- | --- |
| `0x101a004` | Vier inputbytes: mode-ID | Zoek in 18 entries; sla geselecteerde mode op en configureer registers |
| `0x1012000` | 80 outputbytes | Geselecteerde mode-ID, 64 bytes modevelden, breedte, hoogte, DMA-channelcount |
| `0x101a008` | Frame-outputbuffer | Configureer DMA-bufferadressen, wacht op capture-event en toets status |

De ROM-handler staat op `0xc0972f4c–0xc097335b`. `CAM_Init`, `0xc097335c–0xc097344f`, mapt **0x14004000, lengte 0xd4**, maakt een event en koppelt interruptnummer `0x60`. Dit zijn de constanten uit deze driver; de precieze registerlabels moeten nog aan hardwaredocumentatie worden gekoppeld.

De modetabel begint op **`0xc097101c`**, stride **396 bytes**, met 18 entries. De ID staat op entryoffset `0x8c`; width/height op +0/+4. [camera-modes.json](firmware/camera-modes.json) bewaart de volledige entries en hashes. De tabel noemt resoluties tot 1280×960; dat bewijst geen geïnstalleerde sensor of werkende externe camera bij iedere mode.

`StartRVC` kiest **mode `0x1c`** via `0x10007224`. Die mode is **720×480**, met twee DMA-kanalen. RVC zet het uitvoervenster op **800×480** en gebruikt twee afwisselende framebuffers van **`0xa8c00` = 691.200 bytes**. Dat komt overeen met 720×480×2. De overlaydescriptor bevat FourCC **UYVY** (`0x59565955`). De precieze schaal-/overlayverwerking is nog niet volledig gevolgd.

## Aangetoonde verkeerde capture-foutcontrole

De capture-thread `0x100070e4–0x10007223` roept DeviceIoControl aan op `0x1000719c` en vergelijkt zijn returnwaarde op `0x100071a4–0x100071a8` met **`0x5b4` (1460)**. Alleen gelijkheid kiest de tak `FAILED TO CAPTURE FRAME`; alle andere waarden zetten het frame-event en verhogen de bufferindex.

De camera-driver zet op timeout wél foutcode `0x5b4`, maar geeft via zijn gemeenschappelijke epiloog **0 op fout en 1 op succes** terug. Op `0xc097331c` gaat de foutcode naar SetLastError; op `0xc0973328` wordt de aparte boolean teruggegeven. De [Windows CE-documentatie voor DeviceIoControl](https://learn.microsoft.com/en-us/previous-versions/ms960189%28v%3Dmsdn.10%29) bevestigt het boolean-/GetLastError-contract. De capture-thread test hier dus de verkeerde waarde: een driverfout met return 0 loopt eveneens door naar framebeschikbaarheid. De zichtbare gevolgen op de unit zijn nog niet gemeten.

## RVC_CFG_PARAM.DAT: acht little-endian DWORDs

Loader `0x10002bcc–0x100030ab` leest **32 bytes** van `\Storage Card2\RVC_CFG_PARAM.DAT` naar `0x1000eb20`. Hij controleert ReadFile en exact 32 gelezen bytes. Bij ontbrekend/ongeldig bestand gebruikt hij defaults. De saver `0x100030ac–0x10003243` vergelijkt met de bestaande bytes en schrijft alleen bij verschil; hij controleert WriteFile en byteaantal.

| Fileoffset | Betekenis uit gevolgde gebruikersinterface | Loadercontrole / default |
| --- | --- | --- |
| `0x00` | Guideline-flag | Signed waarde ≥2 wordt 0; negatieve waarden worden hier niet afgewezen |
| `0x04` | Brightness-index | Unsigned >14 wordt 7 |
| `0x08` | Contrast-index | Unsigned >14 wordt 7 |
| `0x0c` | Guideline-rotatie | Buiten −45..45 wordt 0 |
| `0x10` | Eerste horizontale guideline-adjustment | Buiten −31..69 wordt 19 |
| `0x14` | Eerste verticale adjustment | Buiten −21..179 wordt 79 |
| `0x18` | Tweede horizontale adjustment | Buiten −31..69 wordt 19 |
| `0x1c` | Tweede verticale adjustment | Buiten −21..179 wordt 79 |

De exacte geometrische eenheden van de adjustments zijn nog open. Brightness/contrast defaults worden uit registrywaarden omgerekend als **14 minus de registry-index**, met registrywaarden boven 14 eerst vervangen door 7 (`0x10002b50`).

Als het nieuwe bestand ontbreekt, kan de loader oude bestanden migreren: **RvcData.bin** levert drie DWORDs, **GuideData.bin** vier geometrie-DWORDs plus rotatie. Na inlezen worden de oude bestanden verwijderd. Die legacy-readpaden controleren de afzonderlijke ReadFile-resultaten niet zoals het nieuwe 32-byte pad. De oude en nieuwe configbestanden zitten niet in dit updatepakket; hun formaat is uit de reader gereconstrueerd.

## I2C-video-decoder en overlay

De helper opent **SMB1:**, gebruikt een named mutex `MUTEXI2C` en IOCTLs `0x80002001` (write) / `0x80002002` (read). De bytebuffer bevat op +0 een adresbyte, op +4 een lengte-DWORD en op +8 een registerbyte/databegin. De [driverketen-analyse](camera-driver-chain.md) matcht dit met **psc_smbus.dll** en bevestigt ook de beperktere transferlengtes en timeoutpaden.

Helper `0x100076ac` schrijft één byte via adresselectie **0x44 of 0x45**, met debuglabel `TW9900Write`. Brightness, contrast en hue gaan naar registervelden **0x10, 0x11, 0x15**; saturation U/V naar **0x13/0x14**. De primaire [TW9900-productdocumentatie](https://www.renesas.com/en/products/tw9900) beschrijft een analoge video-decoder met zulke instelbare beeldparameters. Dit ondersteunt de driverinterpretatie; chipmarkeringen op deze unit zijn nog niet gelezen.

RVC gebruikt daarnaast ExtEscape **0x229c44/48/4c/50/74/78**, MEM1:-IOCTLs **0x220404/408** en ITE1:-IOCTL **0x232008**. De [display-handleranalyse](display-overlay.md) bevestigt enable/disable, configure, clear en bufferwisseling aan beide kanten; de [driverketen](camera-driver-chain.md) bevestigt allocatie, field-interleaving en ITE-transactions. De MIPS-disassembly bewaart stackargumenten die sommige Ghidra-prototypes missen. Volledige registerbetekenissen en runtimegedrag blijven open.

## Offline hulpmiddel

[inspect_camera_data.py](../tools/inspect_camera_data.py) exporteert de modetabel. Met `--config <lokaal bestand>` decodeert het een 32-byte config en meldt welke velden door de geobserveerde loaderchecks zouden worden vervangen. Het wijzigt geen config en opent geen apparaat.

Evidence: [RVC-disassembly](disassembly/RVC.dll.asm), [RVC-pseudocode](decompiled/705md/RVC.dll/decompiled.c), [camera-driver-disassembly](disassembly/rom/camera.dll.asm), [camera-pseudocode](decompiled/rom/camera.dll/decompiled.c).
