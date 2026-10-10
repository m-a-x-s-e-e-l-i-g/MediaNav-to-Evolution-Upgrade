# Gecombineerde update — lokale onderzoekskandidaat

Dit rapport bewaart de eerdere MAX01-build. De nieuwere [MAX02 Bluetooth-playbackreparatie](bt-patch-contracts.md) heeft kleinere PCM-blokken/startreserve en aanvullende buffer-/foutafhandeling; zij is afzonderlijk gebouwd en gecontroleerd.

De hoofd-update voltooit volgens Max; navigatie geeft daarna een corruptiefout. De hoofd-LGU heeft geen `nngnavi.exe`, terwijl de bestaande losse fix uitsluitend die executable levert. Opnemen in één pakket is lokaal gelukt. Waarom de oorspronkelijke maker de pakketten scheidde, is niet vastgesteld. De precieze oorzaak van de fout op de unit en de interne verandering in de navigatiefix zijn nog niet bewezen.

## Gebouwd en gecontroleerd

`build/review-max01/research-candidate.lgu` is een **ongeteste lokale onderzoekskandidaat**, revisie `7.0.5.MD.MAX01`, met 1918 bestanden. Het pakket is 38.352.672 bytes, SHA-256 `93ff7f69602fd30567657e80e2560dcc22fe4f1faeae96d61cb95bee305390b0`. Alle originele bestanden blijven ongewijzigd.

De payload bestaat uit de 1917 gecontroleerde hoofd-updatebestanden plus het ongewijzigde `upgrade/Storage Card4/NNG/nngnavi.exe` uit de losse fix. Twee bestaande members zijn gewijzigd:

| Bestand | Wijziging |
| --- | --- |
| Blue.exe | Alleen byte op offset `0x16410`: `0b` → `03`; VA `0x27010`, `sltiu t2,t1,11` → `sltiu t2,t1,3` |
| Version_Info.txt | Exacte ASCII-tekst `7.0.5.MD` → `7.0.5.MD.MAX01`, zonder newline |

Blue-outputhash: `282bb99f116773c9c3b091ea2db4eeeae0004e5298ac3d95bd03a695a177cab6`. Navigatiehash: `d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9`, 10.364.952 bytes. Blue's oorspronkelijke nul-PE-checksum is behouden; er is geen PE-securitydirectory. Acceptatie door de specifieke CE-loader wordt daarmee niet als getest geclaimd.

De builder controleert LGU0, header-versie 7, 1024-byte header, totale bestandsgrootte, MEDIA-NAV-label en contentrevisie. Na onafhankelijke XOR-decodering zijn ZIP-container-CRC, alle lokale/centrale membergroottes, compressietypes, encryptionflags en 1918 cipher-headercheckbytes gecontroleerd. Python ZIP-decryptie controleert vervolgens iedere member-CRC, grootte en SHA-256. Daarna pakt de afzonderlijke PC-`lgu2dir.exe` het bestand uit: alle 1918 paden en hashes zijn gelijk. Tot slot zijn alle oorspronkelijke sourcehashes opnieuw gecontroleerd.

Volledige memberrecords, wijzigingen, toolhashes, exacte commando's en logs staan in [build-manifest.json](../build/review-max01/build-manifest.json). De gebruikte PC-writer heeft SHA-256 `d8424c16f6832a4f7b1e474e815fee5120cf5041d2d498dbafb030272ec1c9b0`, gelijk aan de writer in de lokale FavreMod-v3.03-release. De extractor heeft SHA-256 `89e1731808f3912bcfd40f0ef0dafddf1c04cdb16fc3cb4e7e6be44a0c16f54f`. Alleen deze x86-PC-tools zijn uitgevoerd; geen MIPS-/firmware-executable.

## Waarom een eigen revisie nodig is

UpgradeManager-routine `0x17964..0x17dd3` leest het actieve `Version_Info.txt`, controleert de LGU-header en kopieert 40 bytes van het UTF-16-contentveld naar een vooraf gewiste buffer. Op `0x17c44` vergelijkt hij nieuw en huidig via `wcscmp`; gelijk slaat de new-versionflag over. Op `0x17d20` worden alleen positief vergelijkende gewone revisies als nieuw gemarkeerd. Dit is lexicale vergelijking, geen numerieke versievergelijking.

De builder begrenst de revisie tot 19 ASCII-tekens zodat de nulterminator in het 40-byte leesveld past. Header en payload-versietekst zijn gelijk. `7.0.5.MD.MAX01` sorteert boven `7.0.5.MD`; dit past bij deze onderzochte versiecheck, maar bewijst niet dat een unit met een andere actuele updater/revisie het pakket accepteert. Restore-/rootpaden hebben aparte voorwaarden.

De bronbytes van deze routine zijn vastgelegd door `inspect_bt_playback.py`, naast de bestaande staging- en copyroutines. De nav-stagingroute `0x14eb0` ondersteunt de vervanger in dezelfde upgrade-directory. De copyhelper `0x181b4` controleert kopieersucces niet voordat hij de bron verwijdert. Die installerzwakte is in deze kandidaat nog niet gepatcht.

## Bluetooth-effect en resterende fouten

De wijziging verlaagt de reserve bij starten/herbufferen van elf naar drie pending headers. Bij dezelfde packetgroottes is de berekende PCM-reserve exact 3/11 van de oorspronkelijke reserve. Bijvoorbeeld bij 44,1 kHz stereo en 1024-byte decoded packets: 1341 ms → 366 ms. Dit zijn PCM-duurmodellen; telefoontiming, driverqueue en hoorbare vertraging zijn niet gemeten. Zie [A2DP-evidence](bt-playback-contracts.md).

Submitgrootte, 25-bufferpool en callbackcode zijn ongewijzigd. De eerder gevonden write-failurecounter, nominale slotoverlap en callback-races blijven open. Een nieuw gevolgd closepad stopt bovendien de unprepare-loop zodra een header succesvol wordt vrijgegeven (`0x26ad4..0x26b08`); dat is niet een loop die alle 25 headers altijd vrijgeeft. Bij closefailure wordt de wavehandle toch gewist (`0x26b6c`), en het PCM-pool wordt daarna alsnog nul gemaakt. De native consequenties hangen af van de driver en callbacks; dit zijn geen bevestigde klachten op Max' unit.

Deze full-scope-kandidaat bevat ook de **ongewijzigde oorspronkelijke OS/NOR/MICOM-updatepayloads**. De builder ondersteunt daarnaast `--scope apps` voor uitsluitend Blue, Version_Info en nngnavi; de updater- en herstelwerking daarvan moet afzonderlijk op de unit worden gevalideerd.

Ook de apps-scope is lokaal gebouwd en onafhankelijk geverifieerd: `build/review-apps-max01/research-candidate.lgu`, 3 members, 4.586.928 bytes, SHA-256 `72daa909c57acc1684efa3b1ed670cc1b6719703888b1140c701cb814e5d62dc`. De drie memberhashes zijn identiek aan dezelfde members in de full-scope. Het [apps-manifest](../build/review-apps-max01/build-manifest.json) registreert deze afzonderlijke build. Dezelfde revisietekst in beide kandidaten betekent dat een reeds geïnstalleerde kandidaat de andere niet vanzelf opnieuw als nieuw aanbiedt.

**Aanvullende installatie-evidence:** ook zonder firmware.hex activeert de oorspronkelijke updater de MICOM-route. De laadfout leidt aan CE-zijde tot AA-command 5 en een ULC A1/tag08-controlframe; zijn MCU-/herstartbetekenis is open. Daarnaast kunnen de verplaatste extractiemarker en onvoorwaardelijke stagingcleanup herstel verhinderen. Zie [updater-recovery-contracts.md](updater-recovery-contracts.md). Beide kandidaten bevatten nog deze oorspronkelijke installatielogica.

Het [vervolgonderzoek naar navigatiecontent](navigation-content-contracts.md) identificeert de normale corruption-return als een lege geaccepteerde kaartenlijst en volgt discovery/cache/formaat/distributor. Dit verduidelijkt de foutmelding; het bewijst nog niet welke input op de unit de leegte veroorzaakt of welke check de bestaande fix verandert.

## Reproduceren en valideren

Gebruik altijd een nieuwe uitvoerdirectory; bestaande kandidaten worden geweigerd:

```powershell
py tools/build_review_update.py --output-dir build/review-next --scope full --revision 7.0.5.MD.MAX01 --restart-buffers 3
```

Dezelfde payloadbytes zijn reproduceerbaar uit de gecontroleerde sources. ZIP-timestamps en traditionele cipher-randombytes kunnen de uiteindelijke LGU-hash laten verschillen.

Voor een unitproef ontbreken nog actuele modulehashes/opslagstatus en een gecontroleerd herstelpad. Nodige gedragsmetingen: navigatie na koude start, kaart/configcompatibiliteit, Bluetooth-start en pauze/hervatten, reconnect, hoorbare A/V-marker en haperingen onder packetjitter. De onderzoekskandidaat is nog geen gevalideerde installatie-update. Er is niets geflasht.
