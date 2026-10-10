# MediaNav MAXmade — 7.0.6.MAX03

Max kiest op 9 oktober 2026 **7.0.6.MAX03**, met dezelfde revisie in LGU-header en weergegeven systeemversie. Deze revisie sorteert boven de bestaande 7.0.5.MD-/MAX-labels. De naam verwijst naar een MAXmade-build op de oorspronkelijke 7.0.5.MD-basis, geen officiële nieuwe Renault-softwarebasis.

## Gebouwd

[Volledige LGU](../build/maxmade-7.0.6.MAX03/upgrade.lgu), [ZIP met guide/manifest/checksum](../build/maxmade-7.0.6.MAX03.zip), [manifest](../build/maxmade-7.0.6.MAX03/build-manifest.json), [builder](../tools/build_maxmade_update.py).

- 38.352.671 bytes, SHA-256 `6b00c5a0807f1b6f6ad7f211a5a65fdc416232d8176bdcdb93227acf21122145`.
- Alle 1.917 oorspronkelijke hoofd-updatepaden behouden; 1.914 oorspronkelijke members byte-identiek.
- Drie vervangers: Blue.exe en AppMain.exe exact uit BT8T03, Version_Info.txt exact ASCII `7.0.6.MAX03` zonder newline.
- Eén toegevoegd bestand: de ongewijzigde bekende corruption-fix nngnavi.exe, 10.364.952 bytes, SHA-256 `d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9`.
- Totaal 1.918 members. Originele OS/boot/MICOM/firmware.hex-payloads behouden. Geen eigen unitdatabase of 4.1.0-referentie opgenomen.

## Controle en beperkingen

Beide originele bron-LGUs zijn onafhankelijk ontsleuteld en tegen alle inventarispaden/groottes/CRC's/hashes gecontroleerd. De builder controleert bronhashes en exacte BT8T03-output/tool-/evidencehashes. De reeds geslaagde 824 pairing-/GUI-/ACK-checks, 64 playbackpacketchecks en labelchecks worden via byte-identiteit hergebruikt; ze zijn niet opnieuw als native unitproef uitgevoerd.

De nieuwe LGU-header, totale grootte, XOR/ZIP-container-CRC, encrypted ZIP-headers en alle 1.918 membergroottes/CRC's/SHA's slagen. De afzonderlijke gepinde x86-PC-extractor levert exact dezelfde 1.918 bestanden. De uitgeronde versiefile matcht de header; alle oorspronkelijke sources zijn daarna opnieuw gelijk gecontroleerd. Deliverable-ZIP is volledig teruggelezen. Geen firmware uitgevoerd of unit geflasht.

Dit volledige pakket bevat het oorspronkelijke firmware.hex en heeft daarom niet het specifiek ontbrekende-imageprobleem van de apps-only-kandidaten. Het behoudt wel de originele volledige OS/MCU-updatewerking en bekende updater-copy-/cleanup-/settingsbackupzwakten. Er is geen nieuwe installerreparatie geclaimd. Het oorspronkelijke pakket bevat settings/resources die bij volledige installatie kunnen worden overschreven.

Max meldt de audiovertraging opgelost na CE-vervanging van beide apps. De volledige LGU-installatie/reboot, acht opgeslagen pairings, navigatie met actuele content, settings en voertuigfuncties zijn nog niet als hardwaretests voltooid. De publicatie wordt daarom als **experimentele release** gepresenteerd, met oorspronkelijke credits en MAXmade-veranderingen apart. Oude packages blijven behouden.

## Guide-publicatie

[Draft PR #22](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/pull/22) bevat de LGU, guide, volledige manifest/checksum en het nieuwe hoofd-README-blok. Commit `067cf455e98cc23f3740864eb18248ae19eb794f`, branch `codex/maxmade-706-max03`, mergeable; niet gemerged naar main. Remote LGU-blob `da8faa46bc1b21433e979306c1170448c59e3e9a` en grootte matchen lokaal. Repo-checkout schoon. Diffcheck en workspace-audit (550 lokale links, 43 sources, 872 digests) slagen.

Op verzoek aangepast in commit `662e76a7947a71069e098d826d72457296b51de2`, gepusht naar dezelfde PR: folder **Upgrade_706MAX03_MAXmade**, nieuwe rootguide volledig voor 7.0.6.MAX03, oorspronkelijke main-README bewaard onder Upgrade_705MD_FavreMod met uitsluitend radio-code-links relatief aangepast. Twintig lokale documentlinks en checksums gecontroleerd. De oorspronkelijke Markdown-whitespace is in de oude guide behouden. LGU, manifest en checksum zijn bij rename byte-identiek en remote op het nieuwe pad bevestigd. PR-body herschreven voor de definitieve documentstructuur; full hardwaretests blijven open.
