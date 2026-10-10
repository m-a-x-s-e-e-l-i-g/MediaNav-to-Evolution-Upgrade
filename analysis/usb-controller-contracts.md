# USB-host, USB-device en verwisselbare opslag

Statische analyse van USBware.dll en USBware2.dll in de gereconstrueerde 7.0.5.MD-ROM. [De evidence-export](firmware/usb-controller-contracts.json) bewaart 42 oorspronkelijke bereiken, beide bronhashes, controllerresources en de selectie uit de gevalideerde bootregistry. Geen driver is uitgevoerd of apparaat benaderd.

## Twee aparte controllerrollen

USBware.dll heeft UWD-exports voor de user-mode-verbinding van onder meer MgrIpod en RMD-exports voor verwisselbare diskdrivers. De hostcontrollers komen uit een **vaste tabel** op c0a34248, niet uit de vijf UDD-controllerkeys. `c09fad98` retourneert exact twee entries en `c09f8c18` registreert ze.

| Hosttype | MMIO physical | Aanwezige virtualwaarde | Lengte | IRQ |
| --- | --- | --- | ---: | ---: |
| 0x1004, EHCI | 0x14020000 | 0xb4020000 | 0x100 | 0x5a |
| 0x1005, OHCI | 0x14020800 | 0xb4020800 | 0x70 | 0x5a |

De resourcearrays bevatten per controller een memory-resource type 2 en interrupt-resource type 1. Hun fysieke adres/virtualwaarde/lengte/IRQ zijn rechtstreeks uit de oorspronkelijke data gelezen. `c0a10ac4` en `c0a10e4c` matchen de typewaarden in hun probehelpers. De namen EHCI/OHCI worden bovendien ondersteund door de overeenkomstige bootregistrybeschrijvingen; alle controllerregisters en porttopologie zijn nog niet benoemd.

Hostinitialisatie `c09facf4` wijzigt b0201118 en b4021000/1004/101c/102c/1034. Dit overlapt met USBware2-init op dezelfde USB-controlregio. Het betekent niet dat beide rollen op de unit tegelijk actief zijn: hun opstartvolgorde, enables en fysieke poorten blijven te onderzoeken.

USBware2.dll registreert de driver met de string **syn_hsfc** via `c08308e8`. `UDD_Init c08220d0` controleert `Drivers\BuiltIn\UDD\EnableStack`: alleen een succesvol gelezen waarde nul stopt init en retourneert nul. De aanwezige bootregistry bevat die value niet. Bij ontbreken gaat init verder. De externe inithelperstatus wordt in deze export niet gebruikt om het geretourneerde contextadres te bepalen.

`c0823844` loopt alle vijf UDD-controllerkeys af; `c0823ab0` vraagt eerst Type op en gebruikt de whitelist `c0823e90`. De oorspronkelijke twee-DWORD tabel op c08390d0 is **[0x2012, 0]**. De lus doorloopt beide waarden, dus ook nul vergelijkt positief; van de vijf werkelijk geconfigureerde typen matcht uitsluitend Controller1.

| UDD-registryindex | Type/beschrijving | Physical | Lengte | Geselecteerd door deze binary |
| --- | --- | --- | ---: | --- |
| 0 | 0x4005 synopsys_ocd | 0x14022000 | 0x100 | Nee |
| 1 | 0x2012 synopsys_dcd | 0x14022000 | 0x100 | Ja |
| 2 | 0x100a synopsys_hcd | 0x14022000 | 0x100 | Nee |
| 3 | 0x1004 ehci_local | 0x14020000 | 0x100 | Nee |
| 4 | 0x1005 ohci_local | 0x14020800 | 0x70 | Nee |

Alle vijf hebben IRQ 0x5a. Niet-geselecteerde keys worden met status 0 overgeslagen, zonder memorymapping. Daarom mogen vijf registryrecords niet als vijf actieve controllers worden geteld. Voor de geselecteerde key leest de code BaseAddress, MemLength en IRQ, mapt de regio via MmMapIoSpace en maakt memory-/interruptresources aan.

`c082273c` doet voor type 0x2012 de pre-init `c08224d0`: b4021000 bit 0 clear/set, b4021020 0x10004→4 met Sleep(2), b4021004 OR 8, b402101c OR 0x10003 en Sleep(25). Andere pre-initbranches bestaan maar worden niet via de huidige registry-whitelist bereikt. De hardwarebetekenis van elke bit is nog open.

UDD_Open/Close/PowerUp/PowerDown zijn kleine context-/logstubs. **UDD_IOControl c08222f8 logt en retourneert altijd 1**, zonder de code of buffers te verwerken. Deze export is dus geen equivalente user-commandoroute aan UWD_IOControl.

## USB-device identiteit en interruptpad

`c0822b58` leest vendor/product/release uit de device-registry en schrijft de WORDs op configuratie+6/+8/+10 voor iedere deviceconfig. Bootwaarden zijn **vendor 0x045e, product 0x00ce, release 0**. `c0837664` verwerkt een device-descriptorrequest en kopieert die waarden naar de 18-byte descriptor-template op c0839214, plus andere dynamische class/packet/stringsvelden. De identiteit is dus niet alleen de onveranderde template op disk.

De defaultstack kiest mode 2 en één deviceconfig. De functionconfig heeft type 6 met callback c082c81c. Vervolgonderzoek heeft deze functie gekoppeld aan JACMDEV.DLL/COM5: één vendor-specifieke interface FF/FF/FF met twee bulk-endpoints. De CDC-requestcode is aanwezig, terwijl de defaultconfig geen CDC-functionaldescriptors of interrupt-endpoint maakt. Zie [USB-seriële contracten](usb-serial-contracts.md) voor de codeketen, RAS-startup en resterende runtimevragen.

`c0822e18` vraagt een SYSINTR via KernelIoControl 0x1010098 aan, zet twee events op, doet InterruptInitialize en maakt een interruptthread met priority 5. `c082327c` laadt giisr.dll/ISRHandler voor IRQ&0xff en geeft via KernelLibIoControl 0x100 een 32-byte configuratie door.

De ISR-confighelper `c0822320` kiest registerparen op basis van controllertype: EHCI +4/+8, OHCI +0xc/+0x10 en Synopsys +0x14/+0x18. Hij vult DWORD-brede accesses in. Het exacte giisr-filter en de ISR/service-racevoorwaarden zijn nog open.

De setupdispatcher `c0836900` leest acht requestbytes (bmRequestType, bRequest en drie WORDs) en heeft branches voor status, feature clear/set, address, descriptor, configuration en interface. Niet-geïmplementeerde branches geven status 0xb. `c08374ac` verdeelt descriptorrequests op hun typebyte, onder meer de 18-byte device-template. Alle USB-controlrequestvoorwaarden en endpoints blijven te volgen.

## RMD: opslagadapter in USBware.dll

De RMD-exports zijn een Windows CE-blockdeviceadapter. `c09f41c4` maakt dynamisch `Drivers\USB\MassStorage\BD<index>` aan met Prefix **RMD**, Dll USBware.dll, FriendlyName Windows CE USB Disk Driver, IClass `{A4E7EDDA-E575-4252-9D6B-4195D48BB865}`, Profile, Order 0, Ioctl 4 en Index. De decompiler toont de UTF16-prefix foutief als een ASCII-string `R`; de oorspronkelijke acht bytes op c09f1830 zijn `RMD` inclusief NUL.

`c09f44c0` kiest op media-kind 0/1/2 UWHD_Profile/UWCD_Profile/UWFD_Profile en activeert het gemaakte device. De suffix en Folder komen uit de oorspronkelijke tweepointertabel c0a34268: beide wijzen naar UTF16 **MD** op c09f1e34. De gegenereerde profielnamen zijn dus UWHD_Profile_MD, UWCD_Profile_MD en UWFD_Profile_MD.

`c09f3fdc`/`c09f3be8` maken StorageManager-profielen dynamisch. CD/DVD krijgt DefaultFileSystem MSIFS_CD en PartitionDriver CDRom.DLL, floppy FATFS en een lege partitiondriver, harddisk laat deze expliciete values weg. Alle krijgen Folder MD. Dit beschrijft registryconstructie; de uiteindelijke mountnaam, partitionselectie en StorageManager-defaults zijn nog niet volledig gekoppeld.

`RMD_Init c09f46f0` leest ClientInfo uit de active-devicekey, zoekt daarmee een object en maakt een handlemapping. `RMD_IOControl c09f5690` zoekt het object op en verhoogt een in-flight-counter tijdens de call; Close/Deinit en detach moeten voor de complete levensduur nog worden gevolgd.

| RMD-code | Gevolgde branch |
| --- | --- |
| 1 | Kopieert 24-byte diskinformatie naar de inputbuffer, vereist inputlen >=24. |
| 0x71c00 | Zelfde informatie naar de outputbuffer, vereist outputlen >=24. |
| 2 / 0x75c08 | Scatter/gather read, device→caller-memory. |
| 3 / 0x79c0c | Scatter/gather write, caller-memory→device. |
| 4 | Retourneert succes zonder verdere operatie in deze dispatcher. |
| 0x71800 | Vult een profiel/info-record, minimaal 80 inputbytes. |
| 0x4d004 | SCSI-packet met data/offsets binnen de inputbuffer. |
| 0x4d014 | SCSI-packetvariant met caller-dataadres en pointerchecks. |
| Overig | FALSE. |

Read versus write is bevestigd in `c09f49e8`: selector 1 leest via de USB-backend en kopieert vervolgens naar caller-memory, selector 0 kopieert eerst callerdata naar een DMA-buffer en schrijft daarna. Het zijn niet slechts namen ontleend aan de numerieke codes.

De SG-helper `c09f53cc` vereist voldoende bytes voor `20 + 8*sg_count`, daarna loopt `c09f4f60` elk pointer/lengtepaar door. Bij nul entries blijft een foutstatus staan. `c09f4d80` deelt transfers op in maximaal **2 MiB**, of **128 KiB** wanneer de gevolgde deviceflag bit 0x4000 gezet is. Hij rekent sectorcount als chunkbytes / bytes-per-sector. Sector-/bufferalignmentvoorwaarden vóór deze helper en de betekenis van die deviceflag zijn nog niet volledig bewezen.

Bij bufferadres niet uitgelijnd op 512 gebruikt hij een tijdelijke DMA-buffer en CeSafeCopyMemory. Bij uitlijning gebruikt `c09f4b88` LockPages, CacheRangeFlush, een page-/scatterbeschrijving en UnlockPages. SCSI-packets `c09f50c4` controleren de 44-byte header, CDB-lengte <=16, callerbuffer en in de offsetvariant de buffer-/sensegrenzen; devicecommands worden via de USB-backend uitgevoerd.

## Open vervolg

- Gehele EHCI/OHCI/Synopsys-register-, descriptor- en IRQ/DMAketen.
- Volledige endpoint-/request-lifetime en de actieve externe COM5/RAS-verbinding; de defaultfunction is gevolgd in [USB-seriële contracten](usb-serial-contracts.md).
- De relatie tussen USB-port reset, MGR1 PHY-enable, overcurrent en attach/detach.
- UWD/RMD locking, lifetime en storage-notificatie naar MgrUSB/AppMain.
- USB mass-storage BOT/SCSI packetframing en foutrecovery.
- Werkelijke mounts, Windows CE defaults, actieve registry en apparaatcaptures.

`py tools/inspect_usb_controllers.py` reproduceert de code-/data-evidence en verifieert dat van de vijf aanwezige UDD-configuraties alleen index 1 wordt geselecteerd door de oorspronkelijke whitelist.
