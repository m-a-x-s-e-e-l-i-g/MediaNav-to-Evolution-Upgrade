# Bootloader, NK, DAB en MICOM: afzonderlijke update- en herstelpaden

UpgradeManager **0x17530–0x17963** sluit Blue en NAVI, toont de upgrade-interface en behandelt vervolgens bootloader, NK, zichzelf, DAB en MICOM. De hier gevolgde fase is geen volledige reconstructie van de ZIP-uitpak- en opslagformatfase die eraan voorafgaan.

[inspect_boot_update.py](../tools/inspect_boot_update.py) bewaart de relevante bronbytes met hashes en controleert welke firmwarebestanden werkelijk in de drie uitgepakte pakketten staan. [JSON-evidence](firmware/boot-update-contracts.json).

| Firmwarelaag | Hoofd-update 7.0.5.MD | Downgrade / navigatiefix |
| --- | --- | --- |
| NK.bin | aanwezig | afwezig |
| firmware.hex (MICOM) | aanwezig | afwezig |
| booter_standalone.bin | afwezig | afwezig |
| ulc_dab_bc_LGe.bin / ulc_dab_uc_LGe.bin | afwezig | afwezig |

Een codepad voor bootloader- of DAB-updates bewijst dus niet dat dit pakket die laag daadwerkelijk bijwerkt. Het bootloader-image zelf ontbreekt; zijn interne boot-/fallbacklogica kan hiermee nog niet worden gereconstrueerd.

## NOR-bootloaderpad

Als staged `\Storage Card3\upgrade\booter_standalone.bin` bestaat, roept 0x17530 de wrapper **0x1a14c** aan. Die opent **PHM1:**; de gevalideerde bootregistry koppelt dat aan **Physical_Manager.dll**. De filewriter **0x19d78** accepteert een niet-lege file tot en met **0x3e0000 bytes**, alloceert één **64KiB-buffer**, rondt het aantal transferblokken naar boven af en vraagt een erase vanaf **0xbfc00000** voor het afgeronde bereik. Er zijn maximaal **zes erasecalls** en maximaal **elf volledige writerpogingen**. De exacte counters en delay slots zijn aan de assembly getoetst.

Na de erasepogingen gaat de filewriter ook bij aanhoudende erase-failure naar het schrijfpad. Hij wist zijn RAM-buffer met nul, leest tot 64KiB en vraagt PHM-IOCTL 1 met record `[bufferpointer, flashadres, aantalbytes]`. Het flashadres stijgt per blok met 64KiB. Een ReadFile-failure geeft 0 terug; ReadFile-succes met nul bytes geldt als voltooid. Bij een writefailure keert de functie direct terug, voorbij de normale free/CloseHandle-cleanup. Er is in dit pad **geen vergelijking van de geschreven bytes met het bronbestand**. De hoofdcall op 0x17530 controleert de uiteindelijke writerreturn niet voordat hij de tekst “BootLoader Upgrade Done” logt.

Dit beschrijft uitvoerende updatercode. Er is geen NOR-apparaat geopend en geen flashbewerking uitgevoerd.

## Volledig PHM_IOControl-contract

Handler **0xc09e239c–0xc09e244b** kent vier codes. De 12-byte inputrecord bestaat uit pointer +0, flashadres +4 en lengte/count +8. Inputpointer, inputlengte, geneste bufferpointer, flashadres en bereik worden hier niet gevalideerd. De standaard outputbuffer en pdwActualOut worden niet gebruikt.

| Code | Gedrag |
| --- | --- |
| `0` | Erase vanaf input+4 voor input+8 bytes; input+0 ongebruikt |
| `1` | Write vanaf bufferpointer input+0 naar input+4, voor input+8 bytes |
| `2` | Read vanaf input+4 naar pointer input+0, voor input+8 **DWORDs** |
| `3` | Erase 64KiB vanaf 0xbfc00000, driverlabel “delete touch calibration data in NOR” |
| andere | SetLastError(0x78), return 0 |

Voor code 2 is +8 dus geen byteaantal: de helper **0xc09e22fc** kopieert één DWORD per iteratie. Een geneste pointer is onderdeel van dit eigen contract; de feitelijke calleradresmapping moet bij runtimeonderzoek nog worden bevestigd. De aanwezigheid van code 3 en zijn debuglabel identificeert niet zelfstandig de locatie/inhoud van alle touchkalibratiegegevens of de indeling van het ontbrekende bootloader-image.

De flashhelpers gebruiken een **4MiB-bankstride** en **32KiB-sectorstride**, met basis 0xbfc00000. De commandowrites zijn 16-bit en bevatten:

- Reset/read-mode: `0xf0` op bankbasis.
- Unlock: `0xaa` op bankbasis+0xaaa, `0x55` op +0x554.
- Erase: unlock, `0x80` op +0xaaa, unlock, `0x30` op sectorbasis.
- Halfword-program: unlock, `0xa0` op +0xaaa, daarna de halfword op het doeladres.
- Buffer-programhelper: `0x25`, count, datahalfwords, `0x29`.

Dit lijkt op een AMD/Spansion-achtig NOR-commandoprotocol; het exacte flashchipmodel is niet vastgesteld. De main writehelper **0xc09e2118** rondt byteaantallen naar vier af, controleert eerst of alle doelbytes 0xff zijn en schrijft ieder DWORD via twee halfword-programcycli. De aanwezige buffer-programtak volgt in deze functie pas nadat de succesflag nul is geworden; een eerdere failure vertrekt al naar de foutreturn. Daarom is het bestaan van de bufferhelper geen bewijs dat de normale updaterroute hem benut.

Statushelper **0xc09e1adc** leest herhaaldelijk 16-bit flashwaarden, toetst toggling van bit 0x40 en statusbit 0x20. Ready wordt **100**, blijvende fout **102**, met flashreset op de fouttak. Er is geen tijdkloklimiet in de poll. De DWORD-programhelper **0xc09e1e8c** blijft status opvragen tot 100 en retourneert daarna 1; een 102-resultaat wordt niet rechtstreeks naar de caller doorgegeven. Erase-range **0xc09e1fcc** negeert de individuele sectorerase-BOOLs en toetst na de hele lus nog eenmaal de status op het eindadres. Dit zijn beperkte foutcontracten; daadwerkelijke hardwarefouten zijn niet opgewekt.

## NK-bestandskopie en herstel

Als staged `\Storage Card3\upgrade\Storage Card\NK.bin` bestaat, kopieert 0x17530 een bestaande `\Storage Card\NK.bin` eerst naar **NA.bin**. Een failure daarbij wordt gelogd, maar stopt de nieuwe NK-kopie niet. De staged NK wordt daarna naar de actieve NK-bestandsnaam gekopieerd; uitsluitend als deze CopyFileW exact 1 retourneert wordt de staged bron verwijderd. Er is hier geen bytevergelijking of atomaire bestandswisseling. **Dit is een bestandenkopie, geen PHM/NOR-write.**

De updater behandelt zijn eigen executable afzonderlijk: een bestaande UpgradeManager.exe wordt naar OLD_UpgradeManager.exe verplaatst, daarna de staged executable naar de actieve naam. De twee MoveFileW-returns worden hier niet getoetst.

Een herstelpad staat in MicomManager **PowerOff-helper 0x22e64–0x23307**. Het leest HKLM\LGE\SystemInfo\BootSequence:

| BootSequence | Gevolgd gedrag in PowerOff |
| --- | --- |
| `0` | Logt kernel-loading OK; geen NK-kopie |
| `1` | Kopieert NA.bin naar NK.bin |
| `2` | Kopieert NB.bin naar NK.bin, daarna NB.bin naar NA.bin |
| `3` | Logt “NC Kernel loading”; geen NK-kopie |
| andere / ontbrekend | Logt onbekende waarde; geen NK-kopie |

De CopyFileW-returns worden niet getoetst. Daarna volgen power-/MICOM-calls en SetSystemPowerState. Deze helper bewijst een **herstelbeslissing op basis van een registrywaarde**, niet hoe de bootloader de waarde vaststelt, of dat herstel bij iedere interruptie tijdig loopt. De maker/inhoud van NB.bin en de volledige bootfallbackvolgorde blijven open.

## DAB- en MICOM-overdracht

Voor één of beide staged DAB-images zoekt 0x17530 het venster MgrDab, maakt een event, post `WM 0x8064 / wParam 0x1100` en wacht **900000 ms**. Alleen WAIT_TIMEOUT wordt als timeoutfailure gelogd; andere waitresultaten gaan naar de Done-tekst. De DAB-imagebestanden ontbreken in dit corpus. DAB's eigen flashtransport moet nog worden gevolgd.

Vervolgens zoekt UpgradeManager **MgrMcm** en post `WM 0x8064 / wParam 0xc70300 / lParam 0x1234`. MicomManager's OnMessage **0x23308–0x23fb7** behandelt command **0xc7**: marker **0x1234** kiest staged `\Storage Card3\upgrade\firmware.hex`; **0x1235** kiest `\MD\firmware.hex`; **0x1236** kiest `\MD\a.hex`. Het kiest de route dus via lParam, ondanks de nul in het lage sizeveld van deze speciale post.

De gekozen path gaat naar **0x22cfc**, die timers stopt, de [HEX-loader](micom-protocol.md) aanroept en zowel bij loadsucces als bij loadfailure manager 1/type 1/command 5 verstuurt. De exacte boot-/flashtransportfase na dat commando blijft open. Deze voorbereiding is geen aangetoonde voltooide MICOM-upgrade.

Evidence: [updater-disassembly](disassembly/UpgradeManager.exe.asm), [updater-pseudocode](decompiled/705md/UpgradeManager.exe/decompiled.c), [PHM-disassembly](disassembly/rom/Physical_Manager.dll.asm), [PHM-pseudocode](decompiled/rom/Physical_Manager.dll/decompiled.c), [MICOM-disassembly](disassembly/MicomManager.exe.asm), [gevalideerde bootregistry](boot-registry.md).
