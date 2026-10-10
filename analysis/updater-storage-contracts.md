# UpgradeManager: LGU-herkenning, staging en opslagformattering

Statische analyse van de 7.0.5.MD-updater, SHA-256 `4d6ffa36bc0e42945ba1ebce79de48d82030894e0e1f9c9e05165d3c33735f87`. De functies hieronder zijn gelezen, niet uitgevoerd. Werkelijke partitiegroottes en aanwezige bestanden op de unit ontbreken.

## Vier interne volumes

De acht pointers op VA `0x377e8` koppelen `DSK1:` aan:

| Index | Partition | Verwachte volumenaam | Default clusterverzoek |
| --- | --- | --- | ---: |
| 0 | PART00 | Storage Card | 512 bytes |
| 1 | PART01 | Storage Card2 | 512 bytes |
| 2 | PART02 | Storage Card3 | 512 bytes |
| 3 | PART03 | Storage Card4 | 8192 bytes |

Dit zijn naam- en formatteringscontracten; de formatter kan gevraagde geometrie aanpassen. De tabel bewijst geen unitcapaciteit.

Boothelper `0x16b6c–0x170fb` wordt voor indices 1 en 2 gebruikt. Zij gaat pas naar delete/create/format als GetPartitionInfo slaagt en de huidige volumenaam leeg is. Een niet-lege afwijkende naam alleen activeert deze herstelroute niet. Bij format van lagere indices worden PART02/PART03 tijdelijk gedismount en later weer gemount. De BOOLs van DeletePartition/CreatePartition worden in dit pad niet als harde stop gebruikt.

## Modi en fasevolgorde

De UI-startfunctie `0x16394` maakt een event en twee threads. Worker `0x15660` formatteert afhankelijk van de detectiemodus, roept ExtractUpdateFile `0x197a8` aan en zet het event. De tweede thread `0x15880` wacht zonder deadline; bij een niet-nul extractieresultaat volgt [de firmwarefase](boot-update-contracts.md) `0x17530`.

| Detectiemodus | Bestandsnaam onder MD | Format vóór extractie |
| --- | --- | --- |
| -1 | upgrade.lgu | PART02 / Storage Card3 |
| 0 | upgrade_root.lgu | Geen |
| 1 | navigation_restore.lgu | PART03, daarna PART01 |
| 2 | navigation_restore_fat32.lgu | PART03, daarna PART01 |
| 3 | navigation_restore_tfat.lgu | PART03 met flags `12` hex, daarna PART01 met flags 0 |
| 4–7 | navigation_restore_weu/eeu/amr/oth.lgu | PART03, daarna PART01 |
| 8–12 | navigation_content_license[regio].lgu | Geen; bestaande NNG/license-directory verwijderen indien aanwezig |

De formatreturns worden door deze worker niet gebruikt als voorwaarde om door te gaan. Navigatieherstel sluit eerst het NAVI-venster en wacht 2500 ms. Root/contentmodus gebruikt een andere extractiedoelroot dan de gewone stagingmodus; alle uitzonderingsvoorwaarden in de bestandsdetectie moeten samen met de betreffende modus worden gelezen.

De gewone LGU wordt naar `\Storage Card3\` uitgepakt. Na succesvolle extractie wordt `\Storage Card3\upgrade\filecopy_success.bin` aangemaakt. De markerhandle wordt zonder expliciete CreateFile-succescheck gesloten. Dit bewijst een extractorstatus, geen gecontroleerde uiteindelijke installatie.

Een apart vervolgpad `0x14eb0` verwerkt een aanwezige staged upgrade-directory. Met de marker worden nieuwe NNG/synctool, data.zip, nngnavi.exe en sys.txt behandeld door de bestaande doelen eerst te verwijderen, als hun staged vervanger bestaat. De resterende staged directory wordt uiteindelijk naar de actieve root gekopieerd. De aangetoonde caller is startupthread `0x12d80`, gemaakt door WndProc `0x13db8` tijdens WM_CREATE. Die startupthread behandelt staging **voordat hij MicomManager.exe start**. De firmwarefase `0x17530` roept deze final-copyfunctie niet direct aan: hij behandelt NOR, NK, de updater-executable en DAB, en vraagt daarna MICOM-upgrade aan. Het nieuwe boot-/restartpad na die aanvraag en alle recoveryvarianten blijven apart te volgen.

## FAT, exFAT en transactional flags

De vijf DWORDs voor FormatVolume zijn clusterbytes, rootentries, FAT-versie, aantal FATs en flags; dit sluit aan op de [Microsoft FORMAT_OPTIONS-definitie](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms890413%28v%3Dmsdn.10%29). De [gedocumenteerde FormatVolume-return](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms890458%28v%3Dmsdn.10%29) is nul bij succes.

Normaal vraagt `0x1a3a4` `[512 of 8192, 512, 32, 1, 0]`. Zijn tweede parameter selecteert versie 64 en flag `0x10`; zijn derde parameter voegt flag 2 toe en vraagt twee FATs. De restoremodus 3 geeft beide parameters 1 voor PART03.

In de **daadwerkelijke ROM-fatutil.dll** stuurt FormatVolume `0x40104248` flag `0x10` naar `0x401097e8`. Deze functie schrijft de bootsectoridentificatie **EXFAT**. De gewone route `0x401033ac` maakt FAT12/16/32-geometrie; flag 2 kiest twee FATs en TFAT-identificatie. De exFAT-route gebruikt flag 2 eveneens om twee FATs te kiezen. Daarom is de bestandsnaam `navigation_restore_tfat.lgu` geen bewijs dat deze modus in dit corpus gewone TFAT32 schrijft: het gevolgde pad is exFAT met de transactional flag.

In `0x1a3a4` worden de eerste OpenStore/OpenPartition-resultaten alleen met nul vergeleken; in de heropen- en boothelperpaden gebruikt de code `FFFFFFFF`. Deze inconsistentie staat ook in de ruwe assembly (`0x1a40c`, `0x1a440`).

Bij een FormatVolume-fout sluit `0x1a3a4` de partition, verwijdert en herschept haar, opent opnieuw, dismount, FormatPartition en nogmaals FormatVolume. Vervolgens probeert zij MountPartition maximaal tweemaal. Na de poging wordt de functie-return **1**, ook als de tweede FormatVolume of MountPartition faalt. De boothelper zet ook 1 na een geslaagde FormatPartition zonder het uiteindelijke FormatVolume-/mountresultaat te verwerken. Succes in de caller is hier dus geen bewijs van een correct gemount filesystem.

## Configuratiepreservatie en automatische scan

In `0x14eb0` leidt een bestaande `Storage Card2\scan_done_flag.bin` tot format PART01 en verwijdering van de oude stagingbackup `Storage Card3\TFAT`. Zonder marker maakt de updater die marker eerst aan, scant PART01, kopieert Card2 naar de TFAT-directory, formatteert PART01, kopieert de backup terug en verwijdert de marker indien aanwezig.

Scanfunctie `0x170fc` kiest uitsluitend PART01, probeert ScanVolume en anders ScanVolumeEx, dismount/scant/mount en wacht 100 ms. De scannerreturn wordt gelogd; mountsucces en backupkopieën zijn geen harde transacties. Backuphelper `0x18460` en restorehelper `0x18698` controleren de individuele CopyFile-returns niet.

Ook zonder staged upgrade kan dit onderhoudspad actief worden: `GetOnOffCount` `0x13b20` leest exact één little-endian DWORD uit `Storage Card2\pwr_count.bin`; boven **175** voert `0x14eb0` scan/backup/format/restore uit en verwijdert de powercounter. De reader accepteert een ReadFile-resultaat alleen met exact vier bytes.

De writer is **MicomManager SavePwrCount `0x1dbb0`**, aangeroepen vanuit `CMicom::PowerOff` `0x22e64` op `0x23010`. Hij leest vier bytes en schrijft de bestaande waarde +1 terug; bij een ontbrekend bestand of ReadFile-fout schrijft hij 0. De eerste call na verwijdering begint dus op 0. Anders dan de updaterreader toetst hij bij BOOL-succes het read-byteaantal niet; een korte succesvolle read kan onvolledig geïnitialiseerde stackbytes meenemen. Ook de write-bytes worden niet gecontroleerd. Het gevolgde resetpad `0x2113c` verwijdert de teller. Dit koppelt de teller aan gevolgde shutdowncalls; het bewijst niet dat elke fysieke aan-/uitcyclus exact één call doet.

De definitieve staged-filehelper `0x181b4` doet **CopyFileW, voortgang bijwerken, DeleteFileW**, zonder de CopyFile-BOOL te toetsen. Een mislukte kopie kan daardoor gevolgd worden door verwijderen van de bron. Er is geen atomaire overgang of complete installatiereadback in deze helper.

Het [vervolgonderzoek naar herstel](updater-recovery-contracts.md) volgt nu ook de onvoorwaardelijke caller-cleanup, de marker die zelf wordt verplaatst, voortijdige versiepublicatie en configbackup-/onderbrekingsscenario's. Het onderbouwt waarom alleen een CopyFile-deleteguard de volledige installatie niet repareert.

## LGU-header en checks

`SearchUpgradeFiles` `0x17964` leest tot 2040 bytes en toetst UTF-16 `*MEDIA-NAV*`, magic `LGU0`, versie 7 en headerlengte 1024. De actuele en nieuwe versies worden met **wcscmp** vergeleken. Dit is lexicografisch, niet semantisch opgesplitst naar versienummers. Een ontbrekende actuele Version_Info.txt zet een afwijkend pad; korte ReadFile-resultaten worden in deze herkenningsroutine niet expliciet volledig gecontroleerd.

De echte openvalidatie `0x1aa94` leest 1024 bytes en controleert magic, versie, headerlengte en de 64-bit totale bestandsgrootte uit DWORDs 3/4. Het ReadFile-byteaantal wordt daarbij niet met 1024 vergeleken. Alle drie aanwezige pakketten voldoen aan de groottevelden.

OpenLGU `0x1189c` berekent bovendien CRC32 over het bestand vanaf offset 1024 via `0x11c50`, maar vergelijkt de lokale CRC in deze routine nergens met een verwachte waarde. De [afzonderlijk gevolgde ZIP-route](updater-zip-contracts.md) controleert wel member-CRC's; daarnaast bestaat post-extractiecontrole in `0x12014`. De voorlopige CRC-helper gebruikt de standaard gereflecteerde CRC32-tabel; een ReadFile-failure beëindigt zijn leeslus terwijl de helper na een succesvolle open nog steeds 1 teruggeeft.

De daadwerkelijke updater bevat **dezelfde 1024-byte LGU0-XOR-tabel** als de upstream lgutool, byte voor byte, en het ZIP-wachtwoord `I_LOVE_LG^^`. Dit koppelt de gebruikte offline extractor aan de aangeleverde 7.0.5.MD-binary. Er is geen veronderstelling gemaakt dat dezelfde key voor alle firmwarefamilies geldt.

`ExtractUpdateFile` herhaalt open/extractiepogingen na veel extractiefouten zonder vaste retrylimiet. Abortflag `DAT_00037850` kan de lus verlaten. De worker publiceert voortgang en foutstatus via critical-section-beschermde data; een succesvolle status leidt naar de marker en daarna de firmwarethread. ZIP64, volledige directoryparsing en malformed-inputgedrag blijven onderzoekswerk; cipher, stored/deflate-dispatch, namechecks, CRC en outputstream zijn inmiddels afzonderlijk gevolgd.

## Evidence

[inspect_updater_storage.py](../tools/inspect_updater_storage.py) bewaart bronbytes, pointertabellen, formatopties per modus, headerwaarden, CRC's en de vergelijking van de echte XOR-key in [updater-storage-contracts.json](firmware/updater-storage-contracts.json). [Assembly](disassembly/UpgradeManager.exe.asm) en [pseudocode](decompiled/705md/UpgradeManager.exe/decompiled.c) bevatten de gekoppelde functies. De firmwarebestanden zijn ongewijzigd.
