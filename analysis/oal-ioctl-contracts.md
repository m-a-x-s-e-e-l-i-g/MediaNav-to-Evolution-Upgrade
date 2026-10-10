# NK/OAL-dispatch en oalioctl-filter

De NK-dispatcher **0x801058e0–0x80105b23** zoekt in de tabel **0x80101150** naar een code, met records van 12 bytes: code, flags, handlerpointer. Er zijn **34 records**, gevolgd door drie nul-DWORDs. Alle onderzochte flags zijn nul. Na initialisatie gebruikt de dispatcher voor handlers waarvan flags bit 0 niet gezet is een critical section. Bij een ontbrekende code stelt hij fout **0x32** en retourneert hij 0. Hij geeft zes IOCTL-argumenten door; er is op dit algemene niveau geen controle van de buffers. [Alle tabelrecords en bytes](firmware/gpio-kernel-contracts.json).

Het NK-bestand bevat in CE 6 de OEM Adaptation Layer; de OS-kernel staat afzonderlijk in kernel.dll. Windows CE gebruikt oalioctl.dll om de user-mode route naar OEMIoControl te filteren. Deze architectuur staat beschreven in [Microsofts CE 6-overzicht](https://learn.microsoft.com/en-us/archive/msdn-magazine/2006/december/mobilize-explore-the-new-features-in-windows-embedded-ce-6-0) en het [CE 6 BSP-hoofdstuk](https://download.microsoft.com/download/c/1/3/c13c9ce9-fe7e-491a-a0bc-4632e085bcb0/Chapter%205%20-%20Customizing%20a%20Board%20Support.pdf). De hieronder genoemde codevergelijkingen zijn rechtstreeks uit dit ROM gevolgd.

## Eigen NK-commando's

| Code | Handler | Gevolgd contract |
| --- | --- | --- |
| `0x01032cab` | `0x80105e00` | Input-DWORD selector 0..7 geeft vaste DWORD; selector >=8 geeft FALSE en byteaantal 0 |
| `0x01032c83` | `0x80105ed8` | 48-byte CPU-/registerinfo; bij onvoldoende output byteaantal 0 maar return TRUE |
| `0x01032c87` | `0x80107424` | [GPIO-contract](gpio-kernel-contracts.md) |
| `0x01032c93` | `0x80105ffc` | CEDDK GetCPUCoreSpeed: DWORD klokfrequentie |
| `0x01032c97` | `0x80106034` | CEDDK GetPBUSSpeed: DWORD klokfrequentie |
| `0x01032c9b` | `0x8010606c` | CEDDK HalAddWiredTLB: vier input-DWORDs naar CP0/TLBWI; output oude Wired-index |
| `0x01032c9f` | `0x801060dc` | Inputrecord 16 bytes: blokindex +0 en enable +4; writes naar `0xb1003000 + index*12` |
| `0x01032ca3` | `0x8010626c` | Vier DWORDs per call toevoegen aan tracebuffer: 64-bit counter, input-DWORD en low-level read |
| `0x01032ca7` | `0x80106390` | Volledige 4MiB-tracebuffer kopiëren naar output; pdwActualOut krijgt de schrijfindex |

De vaste waarden van 0x01032cab zijn, in selectorvolgorde: `0x0a070004, 0x08070004, 0x4f54271a, 0xa0ef002b, 0x228cd050, 0x05f60ce8, 0x13f08030, 0x05030776`. Hun inhoudelijke betekenis is niet bewezen. Bij NULL-input of NULL-output blijft de return hier TRUE; pdwActualOut is vooraf op 4 gezet.

De CPU-info-handler schrijft CP0-register 15 naar output+0 en CP0-register 22 naar +40. Hij wist output+8..39 en vult daarna +8/+12/+16 uit MMIO 0xb0002000/+4/+8. **Output+4 en +44 worden niet geschreven**, hoewel het gerapporteerde formaat 48 bytes is. Deze beschrijving benoemt de CP0-nummers; implementation-specific registernamen zijn niet aangenomen.

GetCPUCoreSpeed berekent `(*(0xb0900060) & 0x7f) * 12000000`. GetPBUSSpeed deelt dat door `(*(0xb090003c) & 3) + 2`. Dit is de firmwareformule; een concrete actuele frequentie volgt pas uit registerwaarden op de unit. Beide CEDDK-wrappers negeren de IOCTL-BOOL en retourneren hun lokale output-DWORD. Dat is van belang bij een route die de IOCTL weigert.

HalAddWiredTLB schakelt interrupts tijdelijk uit via helpers 0x8010b2f0/0x8010b308, laadt vier input-DWORDs en roept 0x8010b4e4 aan. Die helper verhoogt CP0 Wired, schrijft EntryHi/EntryLo0/EntryLo1/PageMask/Index en voert **TLBWI** uit. Buffer- en lengtegrenzen ontbreken in deze handler. De CEDDK-export op RVA 0x24dc koppelt deze naam rechtstreeks aan code 0x01032c9b; dezelfde wrapper staat in k.ceddk.dll.

De enable/disable-handler 0x01032c9f controleert input != NULL en lengte >=16, maar geen blokindex. Bij enable schrijft hij een vaste reeks controlwaarden 3, 0x1fffffe, 1/3/7/f, 0x1ffffff, 2, 0x1f naar de drie registers; bij disable schrijft hij f, 0, 2/1, 0. Deze writes zijn afgewisseld met SYNC. Beide paden gebeuren met tijdelijk uitgeschakelde interrupts. pdwActualOut mag hier NULL zijn, anders wordt er 0 geschreven. Bij ongeldige input retourneert de handler alsnog TRUE.

Een aangetoonde caller in **mae_mpe.dll** gebruikt blok **0**; **mae_bsa.dll** gebruikt blok **1**. **MaliDrv.dll** gebruikt blokken **2 en 3**, met enable/disable-paden op 0xc0991c3c/0xc0991cfc. Dat ondersteunt een hardwareblokbesturing, zonder dat iedere registerbit al inhoudelijk is benoemd. De naam van een enkele caller maakt de rest van het record nog niet bekend.

De tracebuffer begint op realaddr **0x8112ca40**, de DWORD-schrijfindex op **0x8152ca40**. De writer vergelijkt twee counterlezingen, bewaart één paar, voegt input+0 en een read via helper 0x801058b0 toe en laat de index bij >=0x100000 teruglopen naar 0. De reader kopieert altijd **0x400000 bytes** vanaf de buffer, zonder outputlengtecontrole. pdwActualOut bevat de actuele DWORD-index, geen byteaantal van de kopie. Er is hiermee nog geen complete trace-recordbetekenis of geïdentificeerde applicatiecaller bewezen.

## User-mode filter in oalioctl.dll

Export **IOControl 0xc00114d0–0xc0011613** heeft drie routes:

- Doorgestuurd: `0x01010034/54/64/108` en `0x01032c83/87/93/97/9f/a3/a7`.
- Lokaal: `0x01010004`, `0x01012068`, `0x0101206c`.
- Alle andere codes: SetLastError(0x32), return 0.

De doorstuurpointer op 0xc0012048 wordt bij process-attach uit het derde DllMain-argument opgeslagen. Het filter test dus expliciet welke commando's via deze route beschikbaar zijn. **0x01032c9b** (Wired TLB) en **0x01032cab** (vaste waarden) zitten wel in NK maar niet in deze whitelist. Dit onderscheid mag niet worden genegeerd bij het beoordelen van een CEDDK-caller. Kernel-mode toegang en de feitelijke laadcontext van een driver moeten afzonderlijk worden gevolgd.

Lokale helper **0xc001136c** handelt 0x01012068/6c af via HKLM\LGE\SystemInfo, waarde **DEVCODE/MAPCODE**. De call geeft een vijfde stackargument **0x20** aan registryhelper 0xc00112ac; de automatische pseudocode liet dat argument weg. RegQueryValueExW mag dus maximaal 32 bytes vullen. De caller kopieert daarna **64 bytes** uit een lokale buffer, ook wanneer de query faalt, zonder dat de volle buffer eerst wordt gewist. In dit pad wordt pdwActualOut niet ingesteld en outputlengte niet getoetst. Het gemelde succes volgt wel de registry-returnwaarde.

Voor 0x01010004 kiest een input-DWORD uit 0x101..0x108 een lokale tak. Selector **0x104** schrijft DWORD **0x00434c55**, de bytes `ULC\0`, en actualOut=4. Selectors **0x102/105** retourneren TRUE zonder outputwrite. Selector **0x107** leest UUID: de helper vraagt 16 registrybytes en schrijft een GUID-achtige layout van **16 bytes** naar output, maar de caller meldt **actualOut=4**. Ook dit pad test de outputlengte niet. Er is geen actuele unit-UUID uitgelezen.

Bron/evidence: [NK-disassembly](disassembly/rom/nk.exe.asm), [oalioctl-disassembly](disassembly/rom/oalioctl.dll.asm), [oalioctl-pseudocode](decompiled/rom/oalioctl.dll/decompiled.c), [CEDDK-disassembly](disassembly/rom/ceddk.dll.asm), [Mali-disassembly](disassembly/rom/MaliDrv.dll.asm), [BSA](disassembly/rom/mae_bsa.dll.asm), [MPE](disassembly/rom/mae_mpe.dll.asm). Alle bevindingen zijn statisch; de onderzochte binaries zijn ongewijzigd.
