# DBOOT, desktopmenu, reboothelper en opslag-standby

Dit rapport volgt de aanwezige `dboot.exe`, `dmenu.exe`, `cereboot.exe`, ROM `USB_PHY_enable.exe` en één SDMemory-driverpad. [inspect_boot_helpers.py](../tools/inspect_boot_helpers.py) bewaart hun gecontroleerde hashes, originele instructies en twee statische AA-framemodellen in [JSON](firmware/boot-helper-contracts.json). Geen van deze binaries is uitgevoerd. Applicatiepaden zijn handmatig gevolgd; generieke CRT-/exceptioncode en het werkelijke MCU-/hardware-effect blijven afzonderlijk te beoordelen.

## DBOOT en de eenmalige desktopkeuze

DBOOT WinMain `0x17998` schrijft HKCU `ControlPanel\Comm` Cnct=`\`Default USB\`` en AutoCnct=1, en geeft MGR1 code 2 de inputbytes `00 01` (volgens de [driver](mgr-driver-contracts.md): GPIO-pin 0 HIGH). De betekenis van de fysieke pin is niet uit deze call vastgesteld.

Zonder `\Storage Card3\StartWinCE` probeert DBOOT UpgradeManager te starten. Met die marker, **of wanneer de updater niet gestart kan worden**, gaat het naar `0x113d4`. Dat pad verwijdert de marker, maakt desktopshortcuts **Redemarrer.lnk** → cereboot en **Redemarrer WinCE.lnk** → dmenu, en start `\Windows\explorer.exe`. Shortcuthelper `0x11240` schrijft ASCII `<lengte+2>#"<programmapad>"` via OPEN_ALWAYS; individuele write-bytes worden niet gecontroleerd en een bestaande langere shortcut wordt niet expliciet getrunceerd. De marker is dus een eenmalige bootkeuze; volgende boots kiezen normaal weer de updater als die startbaar is.

DBOOT WndProc `0x175b8` onthoudt bij mouse-down de x-positie. Een mouse-move met horizontale afstand **>300 pixels**, zolang de window nog niet verborgen is, start dmenu. Mouse-up wist de dragflag. Dit volgt werkelijk uit de code; er is geen aannname over een bepaalde zichtbare touchscreenknop gemaakt.

## dmenu.exe

Het menu maakt een topmost 800×480-window en laadt `System\Img\DMENU\bg.bmp` en `btn.bmp`. Het gebruikt twee hitrectangles afgeleid van de bitmapafmetingen, met tekst OK/Annuler, en toont een vraag over Windows CE. WM_ACTIVATE probeert bij focusverlies terug op de voorgrond te komen, behalve zolang het CodeChecker-window bestaat.

OK mouse-up binnen de eerder ingedrukte OK-rectangle maakt een worker `0x11c28`: OPEN_ALWAYS/GENERIC_WRITE voor `\Storage Card3\StartWinCE`, sluit een geslaagde handle en gaat **ook bij een openfout** verder met rebootfunctie `0x11928`. Annuler post PostQuitMessage en maakt geen marker. De workerhandle wordt niet bewaard/gesloten; de message-loop cleanup verwijdert alleen de laatst bewaarde fonthandle. De paintcode maakt meer fonts zonder de eerdere handles daar te verwijderen. Dit zijn lokale lifecyclebevindingen; de omvang van een werkelijk resourcetekort is niet gemeten.

## cereboot.exe en de gedeelde rebootvolgorde

cereboot roept vanuit zijn CRT rechtstreeks applicatiefunctie `0x11120` aan. De Franse MessageBox heeft Yes/No-flags; alleen return **7** verlaat het pad. Andere returns gaan verder. cereboot maakt zelf geen StartWinCE-marker. dmenu volgt dezelfde verdere reeks na zijn eigen markerworker:

1. Zoek de windowclasses UpgradeManager, MGRMCM, AppMain, CodeChecker, MgrUsb, MgrIpod, MgrDab, BLUE en NAVI. Haal de PID op, enumereer zijn windows en post WM_CLOSE. Wacht per gevonden/openbaar proces maximaal **10 seconden**; elke niet-nulle waitstatus leidt tot TerminateProcess. De helper roept ook CloseHandle op de gevonden HWND, een afwijkend handlegebruik waarvan het runtime-effect niet bewezen is.
2. Open COM2 op **300000 baud**, acht bits, parity/stopbits nul. GetCommState-BOOL wordt niet als stop gebruikt. Timeoutstruct is `[2,1,6,0,0]`. Bij SetCommState/Timeouts-fout wordt de handle gesloten zonder hem hier op INVALID_HANDLE_VALUE te zetten.
3. Als de serial-openhelper succes gaf: geef memory-write groep 1, address DWORD 1, payload WORD `0x17`. Het berekende frame is `aa 16 02 06 01 00 00 00 17 00 ae`.
4. Open MGR1 en geef IOCTL 2 input `00 01`; open/dismount DSK1 als storage store. Returns van DeviceIoControl/DismountStore worden niet als stop gebruikt.
5. Als serial init gelukt was: stuur normale AA groep 0, command 1, lege payload: `aa 01 01 00 aa`. Sluit de serialcontext.
6. Open DSK1 als device met GENERIC_WRITE, share 2 en flags `40000080`; geef IOCTL **`0x71f84`**, input DWORD 0, outputruimte vier bytes. Sluit de handle.
7. Roep SetSystemPowerState met **NULL, `0x200000`, `0x1000`**. De derde parameter staat in de oorspronkelijke assembly, maar ontbreekt in de geëxporteerde pseudocode. De daadwerkelijke reset-/poweruitkomst na de MCU-memorywrite is nog niet op hardware vastgesteld.

De COM-senders schrijven een XOR-checksum en beperken transmitlengte/checksumlus via een 8-bit mask. De gevolgd gebruikte korte frames vallen binnen die grens. Ze creëren een response-readerthread, wachten 500 ms, sluiten de threadhandle en gaan verder zonder een timeoutthread te termineren of definitief te joinen. De reader verzamelt tot 256 bytes, gebruikt XOR over de verzamelde bytes en heeft een alternatieve afsluitende `a6`-behandeling. Hij valideert in dit pad niet eerst AA, het gedeclareerde frame-aantal of elk afzonderlijk frame. WriteFile-bytes en inhoudelijke antwoorden worden niet als rebootvoorwaarde getoetst. Die lifecycle en readcontrole bewijzen geen bepaalde MCU-respons.

## SDMemory's disk-sleep-contract

De bootregistry koppelt MMC_Class aan `SDMemory.dll`, Profile MMC en Prefix DSK. Dit maakt de driver een kandidaat voor DSK1; de dynamische devicevolgorde en echte unitmapping ontbreken nog.

DSK_IOControl `0xc07218f8` herkent `0x71f84` en logt **IOCTL_DISK_SLEEP**. Hij vereist een niet-nulle outputpointer met minimaal vier bytes, doet CeSafeCopyMemory van vier inputbytes en roept `0xc0722f98` aan. De helper stuurt via de busfunctiontable command 7 met argument 0 en responseparameter 2. Bij input 0 bevraagt hij daarna selector 6 en accepteert statusmask `(status & 0x1e00)==0x600`, met log Card now in Standby. Er zijn maximaal drie command-/statuspogingen; negatieve busstatus keert meteen terug.

De IOCTL zet een negatieve helperreturn om naar **output-DWORD 0**. Als de memory-copies slagen, blijft zijn eigen errorstatus nul en retourneert hij **TRUE**, ook na een mislukte standby-helper. Beide reboothelpers gebruiken de BOOL en dat output-DWORD niet als beslisvoorwaarde. Busfunctiontableherkomst, volledige SD/MMC-init, cache-/transfergedrag, fysieke standby en opslagintegriteit na power-off blijven open.

## USB_PHY_enable.exe

De applicatieroutine `0x11074` opent MGR1, geeft code 3 met één byte 1, sluit de handle en retourneert 0. Hij toetst alleen de openhandle tegen `ffffffff`; IOCTL-succes wordt niet verwerkt. Zijn CRT roept precies deze routine aan. De [MGR-driveranalyse](mgr-driver-contracts.md) koppelt code 3 aan de USB-PHY-helper. In de gevalideerde bootregistry is geen launchwaarde met deze executable gevonden; aanwezigheid in ROM bewijst niet wanneer hij werkelijk wordt gestart.
