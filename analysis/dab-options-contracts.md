# DAB-instellingen: bestand, IPC, shared memory en moduleconfig

Dit contract volgt `DABinfo.cfg`, de optie- en announcementdialogen in AppMain en de DAB-configencoder. De bronnen en oorspronkelijke instructiebytes staan in [dab-options-contracts.json](firmware/dab-options-contracts.json). [inspect_dab_options.py](../tools/inspect_dab_options.py) reproduceert de evidence en kan een lokale configuratiekopie lezen. Het wijzigt geen instellingen of firmware.

## Bestand en validatie

MgrDAB bewaart **48 bytes / twaalf little-endian signed DWORDs** in `\Storage Card2\DABinfo.cfg`. De configuratieclass begint op manager `+0xd1adc`; het bestand bevat class `+4..+0x33`. Constructor **`0x1ea40`** initialiseert alle twaalf DWORDs op nul voordat de loader **`0x1e820`** wordt aangeroepen. De loader vereist een succesvolle `ReadFile` met precies 48 gelezen bytes. Er is geen totale-bestandsgroottecheck: eventuele bytes na de eerste 48 worden niet gecontroleerd.

Voor ieder veld geldt een signed test: **waarde >1 →0**. De `slti ...,2` instructies bevestigen dat negatieve waarden blijven staan. Dit is geen volledige 0/1-validatie. Latere configbouw behandelt nonzero als aan, zodat een behouden negatieve waarde de betreffende vlag ook activeert.

De resetfunctie **`0x1e4ec`** zet alleen de eerste elf DWORDs op nul. De laatste blijft behouden; bij een verse constructor was hij al nul, maar een gedeeltelijke mislukte read of latere reset kan een eerder aanwezige waarde behouden. Reset publiceert de opties en schrijft ze naar disk. De writer **`0x1e41c`** opent met CREATE_ALWAYS, schrijft 48 bytes, logt WriteFile-BOOL, maar controleert het geschreven byteaantal niet. Er is geen tijdelijke-bestand/rename-commit. `CloseHandle` wordt ook na een mislukte open aangeroepen.

## UI naar persistent veld

AppMain is IPC-ID `0x15`, MgrDAB ID 9. Iedere optiewijziging heeft vier payloadbytes, de gewenste DWORD. Dispatcher **`0x1d548`** routeert de onderstaande commando's via `0x123f4` naar setter **`0x1e654`** en vervolgens `ApplyDABConfig`. De decompiler verliest de doorgegeven a1/a2-argumenten van de korte wrapper; de oorspronkelijke MIPS-instructies bewaren ze.

| File-offset | UI-label / functie | AppMain → MgrDAB | Vlag in moduleconfig |
| --- | --- | --- | --- |
| `00` | DLS | `6b` | Byte 0 OR `18` |
| `04` | Transport | `6d` | WORD bit `0004` |
| `08` | Warning | `6e` | `0008` |
| `0c` | News | `6f` | `0010` |
| `10` | Weather | `70` | `0020` |
| `14` | Event | `71` | `0040` |
| `18` | Special Event | `72` | `0080` |
| `1c` | Program Info | `73` | `0100` |
| `20` | Sport | `74` | `0200` |
| `24` | Financial | `75` | `0400` |
| `28` | TA | `6c` | `0002` |
| `2c` | Betekenis nog onbekend | Geen setter in deze route | Niet gebruikt in gevolgde configbouw |

De labels zijn gekoppeld via AppMain-dialogbuilder **`0x908d8`**, init **`0x92018`**, announcement-clickhandler **`0x92358`** en de echte Engelse RT_STRING-resources `bbb..bc3`. De DAB-optiepagina **`0x99f04`** gebruikt `456=TA`, `bba=DLS`, `581=Off`, `582=On`. Init **`0x9ac38`** leest TA op mappingoffset `0x28` en DLS op offset 0; clickhandler **`0x9ae3c`** en TA-helper **`0x9b528`** sturen de corresponderende IPC-commando's. Daarmee is het veldverband meer dan een stringassociatie.

Setter `0x1e654` publiceert gewijzigde velden in shared memory en schrijft het configuratiebestand ook wanneer de aangeleverde waarde gelijk blijft. Type 10 gebruikt DLS-setter `0x1e574`, die bij uitzetten ook twee lokale functies aanroept en AppMain met commando `6d` informeert. Die uitgaande `6d` heeft een andere richting en betekenis dan het inkomende Transport-commando.

## Shared memory

Producer **`0x26620`** maakt mappings met bijbehorende `ShmMx...` mutexclasses. De optiepublisher **`0x2697c`** schrijft dezelfde 48 bytes met `MSHM_Dll_Write`. AppMain opent `ShmFmMgrDABOption` en bewaart de mapped pointer op zijn shared-context `+0xec`; de gevolgde UI leest direct uit die mapping.

| Mapping | Bytes |
| --- | ---: |
| `ShmFmMgrDABCurrentStation` | 1644 / `0x66c` |
| `ShmFmMgrDABPresetList` | 19732 / `0x4d14` |
| `ShmFmMgrDABScanList` | 29004 / `0x714c` |
| `ShmFmMgrDABOption` | 48 / `0x30` |
| `ShmFmMgrDABEPG` | 6604 / `0x19cc` |
| `ShmFmMgrDABAnnInfo` | 40 / `0x28` |
| `ShmFmMgrDABDsiInfo` | 28 / `0x1c` |

De presetlijst bevat twaalf records van `0x66c`, plus vier bytes. AppMain initialiseert de presetrecords op veld `+0x664` en de DWORD na de twaalf records op `ffffffff`. Vervolgonderzoek heeft de scanlijst als 250 compacte records gevolgd; de bijbehorende velden en de presetfallback staan in [dab-shared-contracts.md](dab-shared-contracts.md). De grootte alleen bewijst geen volledige structlayout.

## Config naar DAB-module

`ApplyDABConfig` **`0x119ec`** begint met een lokale tien-byte structuur. Hij bouwt een basismasker `0x2001`, voegt TA en de negen announcementbits toe, en kiest regio-byte 1 tenzij het bestand `\Storage Card\dab_korea_ini.dat` aanwezig is; dan wordt dat byte 4 en volgt de logtekst `KOREA DMB`. Dit betreft een bestand-aanwezigheidstest, geen inhoudelijke configuratieparse.

De encoder **`0x2a834`** stuurt commando `40` met **negen payloadbytes**: byte 0, 1, 2, het WORD op structuur `+4` big-endian, en bytes 6..9. Structuurbyte 3 wordt niet verzonden. Basisbytes zonder opties:

```
02 c8 01 20 01 01 01 02 00
```

Alle elf gevolgde opties aan:

```
1a c8 01 27 ff 01 01 02 00
```

Daarna publiceert Apply de optie-DWORDs, bewaart de lokale configkopie en doet een vervolgaanroep `0x2a57c`. Payloadfieldnamen buiten de aan de UI gekoppelde bits zijn nog niet als volledig SDK-contract vastgesteld. Deze bytes beschrijven codegedrag en vormen geen voorstel om instellingen te wijzigen.

## Verificatie en open onderzoek

Bronhashes worden tegen de corpusinventaris getoetst. Signed checks, het ontbrekende twaalfde resetveld, leaf getters en doorgegeven wrapperargumenten zijn in ruwe instructies bevestigd. Offline fixtures controleren korte records, negatieve/high waarden, alle afzonderlijke bitvelden, TA, DLS en de regiokeuze.

Nog open: het twaalfde DWORD; audio-prioriteiten van announcements; volledige station-/preset-/scan-/EPG-/DSI-layout; ontvangst- en refreshpad; mutex- en foutgedrag van alle consumers; daadwerkelijke unitconfiguratie. De firmware-/SPI-keten staat afzonderlijk in [dab-update-contracts.md](dab-update-contracts.md).
