# Updater — kopieerfouten, onderbreking en herstel

Vervolg op 9 oktober 2026: [copy-safety development](updater-copy-safety-development.md) bevat een concrete, afzonderlijke native-codeproef tegen de hieronder beschreven kopieer-/cleanup-/markerfouten. Onderstaande evidence blijft het oorspronkelijke gedrag vastleggen. De proef is niet in een LGU gepubliceerd of op CE uitgevoerd; volledige transactie-/formatter-/flashreparatie blijft open.

Onderzocht zijn de originele 7.0.5.MD-Updater (`4d6ffa36bc0e42945ba1ebce79de48d82030894e0e1f9c9e05165d3c33735f87`) en MicomManager (`c56e8e08600cd69a656ec487779d3dbb0cea672ae2c5cb2da685b9217e6f8824`). Geen firmwarecode is uitgevoerd. De [lokale LGU-kandidaten](review-update-contracts.md) zijn niet met een installer-reparatie uitgebreid.

## Een CopyFile-guard alleen is onvoldoende

De final-copyhelper `0x181b4` roept op `0x1837c` CopyFileW aan en verwerkt zijn BOOL niet. Het staged-bestandsbyteaantal wordt aan objectveld +61c toegevoegd; op `0x1839c` wordt DeleteFileW aangeroepen, met de voortgangsstore in zijn delay slot `0x183a0`. De GUI telt dus **pogingen**, niet gecontroleerd geïnstalleerde bytes. Ook CreateDirectory/recursieresultaten en het onderscheid tussen einde-enumeratie en enumeratiefout worden niet als installatiesucces doorgegeven.

Na deze helper op `0x15304` volgt geen readback of returntest. De controller toont/logt voltooiing en roept op `0x153d0` alsnog `0x17fe0` aan om de volledige stagingdirectory recursief te verwijderen. Die cleanup loopt ook wanneer de extractiemarker ontbreekt. Een per-file patch die uitsluitend DeleteFile na CopyFile-failure overslaat, bewaart daardoor de bron tot deze **volgende cleanup**; zij repareert de controller niet.

De nav-voorbereiding verwijdert het bestaande nngnavi.exe al op `0x15080` als er een staged vervanger bestaat. Een kopieerfout kan dus het oude doel én de nieuwe bron verliezen. De startupthread `0x12d80` lanceert MicomManager vervolgens zonder statusgate op het resultaat van de stagingroutine.

## De succesmarker is geen installatiebewijs en wordt zelf verplaatst

`0x197a8` maakt na extractiesucces `Storage Card3/upgrade/filecopy_success.bin` aan. Dit is een **nulbytebestand voor extractievoltooiing**; er is geen geïnstalleerde inhoudsmanifest in dit bestand. De CreateFile-return wordt niet gecontroleerd voordat CloseHandle en de succesreturn volgen.

De gewone movehelper doorloopt alle bestanden onder `upgrade`, zonder uitzondering voor `filecopy_success.bin`. Hij kan de marker daarom naar de actieve root kopiëren en uit staging verwijderen. De doelroot-string is leeg; `%s\\%s` levert voor dit rootbestand `\\filecopy_success.bin`. Welke root-directory-entry de CE-unit eerst enumereert, is niet gemeten.

Een concreet onderbrekingsscenario: oude navigatie wordt verwijderd; daarna wordt de marker verplaatst; vóór de overige kopieën valt de uitvoering weg. De volgende startup vindt de stagingdirectory maar geen extractiemarker, slaat installatie over en verwijdert de resterende payload. Dit tegenvoorbeeld heeft geen mislukte CopyFile nodig. Het veronderstelt coherente filesystemoperaties op de gekozen grens; het bewijst geen daadwerkelijke stroomuitval of schrijfvolgorde op Max' unit.

## Version_Info kan vooruitlopen op de werkelijke installatie

Version_Info.txt is een gewone member. Er is geen expliciete "versie als laatste"-regel in de recursieve copyhelper. Als dit bestand lukt en een ander vereist bestand faalt, kan de actuele versie al de nieuwe revisie bevatten. De [lexicale versiecheck](review-update-contracts.md) biedt hetzelfde pakket dan normaal niet opnieuw aan. Een nieuwe revisie voorkomt de gelijkheidscheck bij de eerste installatie; zij is geen vervanging voor een duurzame herstelstatus.

## Configuratiebackup is geen transactie

In de staged-updatebranch wordt eerst `Storage Card2/scan_done_flag.bin` aangemaakt, dan gescand, dan `0x18460` voor backup aangeroepen. Op `0x151a8` wordt PART01 vervolgens geformatteerd zonder de backupkopieën te controleren. Restore `0x18698` kopieert en verwijdert ook zonder CopyFile-resultaatgate.

Bestaat de scanmarker bij deze staged startup al, dan kiest het pad `0x150ec..0x15108` format Card2 en delete de TFAT-backup. Een onderbreking **na een goede backup maar vóór format** kan dus de nog aanwezige marker laten staan; dezelfde update-startupbranch kan daarna zowel de oude settings als de backup verwijderen. Dit is een control-flowtegenvoorbeeld voor die specifieke branch, niet voor iedere boot: zonder staged upgrade gelden de aparte powercountervoorwaarden.

## Een apps-pakket slaat het MICOM-protocol niet automatisch over

De firmwarefase `0x17530` post aan het aanwezige MgrMcm-venster altijd `WM 0x8064 / wParam 0xc70300 / lParam 0x1234`, ook als de payload geen firmware.hex bevat. De 3-member apps-kandidaat bevat inderdaad geen HEX; de full-kandidaat bevat die wel. Beide actuele containerhashes zijn opnieuw gecontroleerd. Ook het oorspronkelijke one-member navigatiefixpakket heeft geen HEX.

MicomManager `0x23308`, command c7/marker 1234, kiest de staged HEX-path en roept `0x22cfc` aan zonder zijn return te verwerken. Bij ontbrekende/onleesbare HEX retourneert loader `0x1ef7c` nul. De update-entry stopt vier timers, wist de imagehouder, zet updateflag en teller op 1, queue't gewone AA-command 5, toont progresswaarde 1000 en roept OnRequest(20) aan.

OnRequest `0x1d750` ziet de ontbrekende imagehouder en bouwt **ULC A1/tag08 met 1024 nulbytes**. Framegrootte 1030, prefix `55 4c 43 a1 08`, checksum `a9`, offline framehash `6f673833b0b17a8f395e041f6a8dd4637ee6e09501537ed5ea9f9181ab52d07e`. De CE-code probeert vier writes; volledige overdracht wordt niet geverifieerd. Het [vervolgonderzoek aan MCU-zijde](micom-mcu-update-chain.md) volgt A1 door de programmeerwrapper vóór zijn eind-/resetroute, onder een initial-RAM-/ISA-aanname. Succesvolle fysieke writes, blokmapping en werkelijke reset blijven open. De kleinere payload is daarmee wel kleiner, maar geen aangetoonde omzeiling van het MCU-update-/herstartprotocol.

## Offline tegenvoorbeelden en bewijsgrenzen

`py tools/inspect_updater_recovery.py` bewaart **16 originele functiebereiken en 12 exacte instruction-preimages** in [updater-recovery-contracts.json](firmware/updater-recovery-contracts.json). `updater_recovery_models.py` vergelijkt de oorspronkelijke flow met een uitsluitend hypothetische CopyFile-deleteguard.

Per variant zijn 12 geldige depth-first orders van twee directorygroepen en de marker gecombineerd met acht copy-outcomes: **96 cases**, waarvan bewust zeven van de acht foutcombinaties. Beide varianten eindigen in 84 incomplete cases; in 36 cases staat Version_Info toch op nieuw. Dit zijn geen failurepercentages voor echte hardware. Alle deletes slagen in dit model; mislukte copies veranderen het doel niet; gedeeltelijke writes, locks, NAND en flushgedrag worden niet geëmuleerd.

Alle coherente operatiegrenzen zijn daarna met één reboot en nu succesvolle copies doorgelopen: 1632 oorspronkelijke en 1488 guard-variant cut/rebootcases. De expliciete traces tonen onder andere markerverlies, voortijdige versiepublicatie en de latere cleanup die een behouden bron alsnog verwijdert. De modellen schrijven uitsluitend onderzoeks-JSON, geen firmware of unitbestanden.

Een echte reparatie moet daarom op **helper, caller, markers, configbackup én startup** worden beoordeeld. De concrete vereisten staan in [update-repair-plan.md](update-repair-plan.md). De bestaande Bluetooth/nav-kandidaten blijven onderzoekskandidaten; hun pakketvalidatie is geen bewijs van foutbestendige installatie.
