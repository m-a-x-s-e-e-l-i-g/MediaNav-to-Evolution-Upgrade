# MAX02: Bluetooth-playbackreparatie en kleinere audiowachtrij

De lokale gecombineerde **7.0.5.MD.MAX02** bevat nu een daadwerkelijke Blue.exe-playbackreparatie. PCM wordt in blokken van **4096 bytes** aangeboden, gestart na **twee** geaccepteerde blokken en begrensd op **vier** owned blokken. Dit verwijdert de grote, eerder gevonden softwarestartreserve. Vrije buffers, voorbereide lengte, OS-ownership, write-/restartfouten, completioncounter en gedeeltelijke PCM bij stop zijn eveneens gerepareerd.

De build en regressiechecks slagen; **totale Bluetoothlatency en hoorbare stabiliteit zijn nog niet op de unit gemeten**. Het pakket bevat ook de ongewijzigde bekende navigatiefix. Er is niets geflasht. MAX01 blijft als eerdere kandidaat behouden.

## Concrete artefacten

- [Gecombineerde LGU, aflevernaam upgrade.lgu](../build/review-max02/upgrade.lgu)
- [Gebouwde research-candidate.lgu, identieke bytes](../build/review-max02/research-candidate.lgu)
- [Buildmanifest met alle 1918 memberhashes en extractorresultaten](../build/review-max02/build-manifest.json)
- [Regressie-evidence en exacte patchpreimages](firmware/bt-patch/contracts.json)
- [Disassembly van de gewijzigde bereiken](firmware/bt-patch/patched-paths.asm)
- [Patcher](../tools/patch_bt_playback.py) en [regressieproducer](../tools/verify_bt_patch.py)

| Artefact | SHA-256 |
| --- | --- |
| Beide LGU-bestanden, 38.352.670 bytes | `20dd0b29a1e235eebe51e7f35a6580f284c3d957d828ebef2ff6ed55f4f48ab4` |
| Originele Blue.exe, 1.149.952 bytes | `5e659f513327c84964a929ea9b9e3192384b3031fa6e6ffb6ad76b02af1b7c7b` |
| Gerepareerde Blue.exe, dezelfde grootte | `2d67083c0f2f4ed3d29fdfdc8450c80aa78ff808c2618d3b8a69061739f93273` |
| Ongewijzigde bekende navigatiefix | `d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9` |

Er veranderen **514 bytes in Blue**, verspreid over vier gepinde bereiken. Version_Info wordt exact `7.0.5.MD.MAX02`, zonder newline. De overige oorspronkelijke hoofd-updatebestanden blijven gelijk; de losse nngnavi.exe is in dezelfde payload toegevoegd. Het volledige pakket bevat de bestaande OS/NOR/MICOM-payloads. Er is geen nieuwe apps-only variant gebouwd; het eerder gevolgde MICOM-controlpad daarvan is nog niet afgerond.

## Wat er in de audiocode is veranderd

| Bereik in oorspronkelijke Blue-VA's | Reparatie |
| --- | --- |
| 26e98..27087, binnen WinPlayProcess | Bounded split/copy/submit-loop; oorspronkelijke functie-entry en epilogue behouden |
| 26484..264e7, binnen callbackthread | Ownership controleren en pending zonder underflow afbouwen; dubbele completions hebben geen tweede decrement |
| 26ad4, vier bytes | Premature unprepare-exit verwijderen; alle 25 headers eenmaal proberen |
| 26d64, vier bytes | Gedeeltelijke, nog niet aangeboden PCM bij stop/reset wissen |

WinPlayProcess gebruikt dezelfde oorspronkelijke context, headers, PCM-pool, wavehandle en callbackthread. De 25 headers houden hun oorspronkelijke **25.600-byte slotafstand en voorbereide capaciteit**; de nieuwe aangeboden lengte is 4096. Er zijn geen extra heapallocaties of nieuwe uitvoerbare PE-secties nodig. De PE-grootte, sectieheaders, stackprologue, callee-saved-registers, oorspronkelijke epilogue en .pdata-unwindbytes blijven behouden. Het oorspronkelijke executable heeft ImageBase 10000 en geen baserelocationdirectory; de patch gebruikt dezelfde oorspronkelijke absolute thunks/globaladressen. De nul-PE-checksum en ontbrekende securitydirectory zijn behouden.

De nieuwe loop houdt de bestaande Blue-critical-section vast tijdens ownershipcontrole, kopiëren en aanbieden. Hij kopieert uitsluitend als zowel **dwUser=0** als **PREPARED=1/INQUEUE=0**. Pointer en aangeboden header komen steeds van dezelfde header. Een packet dat meerdere blokken vult, wordt gesplitst; accumulated blijft kleiner dan 4096. Iedere aangeboden lengte is 4096 en blijft binnen de oorspronkelijke voorbereiding. Invoer boven 64 KiB wordt afgewezen; de oorspronkelijke inputvrijgave/volgende-filtercall blijven plaatsvinden.

Bij een volle wachtrij of owned geselecteerde header wordt nieuwe inkomende PCM overgeslagen. Queued data wordt niet overschreven en pending wordt niet kunstmatig nul gezet. Dit kiest een begrensde wachtrij: onder overbelasting kan audio worden overgeslagen. Werkelijke jittertolerantie en hoorbare kwaliteit moeten daarom op hardware worden beoordeeld.

Pending/dwUser worden onder dezelfde lock vóór de write vastgelegd. Bij een nonzero waveOutWrite-return zonder INQUEUE volgt rollback, zonder produceradvance. Een nonzero return mét INQUEUE wordt voorzichtig als onopgeloste ownership behandeld: pointer/counter blijven owned en de producer gaat verder; de call kopieert daarna geen verdere PCM. Zo kan een dubbelzinnige fout geen toestemming worden om driverdata te overschrijven. Alleen callback/reset/lifetimeafhandeling kan dat bezit vrijgeven.

De restarted-vlag wordt pas na een **geslaagde** waveOutRestart gezet. Een mislukte restart houdt de vlag nul; een volgende packetcall probeert opnieuw voordat hij nieuwe PCM kopieert. Dit werkt ook bij de ingestelde queuegrens. Dubbele WOM_DONE-calls veranderen de pendingcounter niet opnieuw. Stop maakt partial PCM leeg en de nieuwe processcode accepteert alleen contextstate 2; hervatten bouwt dus opnieuw vanaf verse PCM.

## Verwachte reductie van de softwarebufferreserve

Voor stereo/16-bit en een constante 8192-byte decoded-packetfixture:

| PCM-rate | Originele 11-bufferstart | MAX02-start, 8192 bytes | MAX02 maximale queued PCM, 16384 bytes |
| --- | ---: | ---: | ---: |
| 44,1 kHz | 1533 ms | 46,4 ms | 92,9 ms |
| 48 kHz | 1408 ms | 42,7 ms | 85,3 ms |

De originele reserve varieert met packetgranulariteit. De nieuwe submitblokken zijn vast, waardoor de getoonde PCM-reserve voor hetzelfde negotiated format niet meer meegroeit tot drie grote packets per header. Dit is **queued PCM-duur**, geen stopwatchmeting. Telefoon/player, A2DP-transport, SBC, scheduling, resampling en fysieke DMA-uitvoer kunnen aanvullende latency leveren. Startreserve en end-to-end vertraging zijn afzonderlijke grootheden.

## Uitgevoerde regressiechecks

`py tools/verify_bt_patch.py` interpreteert de **werkelijk gepatchte MIPS-bytes**, niet een losse herschrijving van het algoritme. memcpy-fixtures verplaatsen echte payloadbytes; OS-/lock-/write-/restartuitkomsten blijven expliciet gemockt. Onbekende calls/instructies, te lange loops, queued-overwrite en overschrijding van de eigen blokgrens stoppen de controles.

| Controle | Resultaat |
| --- | --- |
| 400 packets met gevarieerde lengtes, partial appends, splits en producerwrap | 1.212.416 aangeboden PCM-bytes exact gelijk aan invoer; 11 produceromlopen |
| 100 packets na volledige vier-blokwachtrij | Geen nieuwe kopieën of wijziging van de vier owned payloads |
| PREPARED/INQUEUE × dwUser | 14 cases geslaagd |
| Write-errors met en zonder blijvende INQUEUE, daarna herstel | 10 cases geslaagd |
| Twee mislukte restartpogingen gevolgd door succes | Vlag blijft nul tot succes; daarna gewone submit hervat |
| Invoergrenzen nul..64 KiB en 64 KiB+1 | 10 cases geslaagd; input één keer vrijgegeven |
| AV-gate en partial stop/start | 2 sequenties geslaagd; oude partial PCM komt niet in verse submit |
| Unprepare-returns, eerste succes op 0..24 of overal error | Alle 26 klassen proberen precies 25 headers |
| Patched Blue → oorspronkelijke WAM → coredll → patched callback | 5 driver-returncases; 4096-byte submissions geaccepteerd en concrete completion verwerkt |
| Proces-ABI | Stack en alle oorspronkelijke callee-saved-registers bij iedere packetcall behouden |

De gekoppelde WAM-test gebruikt de oorspronkelijke ROM-bytes en capaciteit-/pointer-/flagchecks. Driverreturn 0 levert twee 4096-byte headers; een echte oorspronkelijke proxy-/runtimequeue-trace verlaagt daarna Blue-pending van 2 naar 1. Driverreturns 1/6/8/33 leiden tot rollback zonder valse pendingheaders. Deze koppeling neemt native driver-/OS-scheduling niet over.

De builder accepteert BT02 alleen met een **actuele, geslaagde** evidencefile waarvan output-, producer-, patcher- en dependencyhashes overeenkomen. De LGU heeft daarnaast onafhankelijke LGU-header/XOR/ZIP/CRC/size/memberhashchecks en een aparte PC-extractor-roundtrip voor alle 1918 bestanden doorstaan. Alle oorspronkelijke sourcehashes zijn daarna opnieuw gecontroleerd.

## Reproduceren

Gebruik een nieuwe outputdirectory; bestaande kandidaten worden niet overschreven:

```powershell
py tools/verify_bt_patch.py
py tools/build_review_update.py --output-dir build/review-max02-new --revision 7.0.5.MD.MAX02 --restart-buffers 2 --bluetooth-fixes
```

De Blue-/payloadbytes zijn reproduceerbaar. ZIP-timestamps en de containercipher kunnen een andere LGU-hash opleveren. De aflevernaam upgrade.lgu is een identieke kopie van de onafhankelijk geverifieerde research-candidate.lgu.

## Wat nog nodig is op de unit

Een test moet de daadwerkelijke moduleversies/hashes aan de gebruikte 7.0.5.MD-bronnen koppelen en een concreet herstelpad hebben; de bestaande updater-/kopieer-/recoveryzwakten zijn niet in MAX02 gewijzigd. Meet met dezelfde telefoon, player en source vóór/na: video-lip-sync of een zichtbare/audio-marker, start, play/pause, trackwissel, reconnect/koude start en langere playback met navigatie. Noteer vertraging én haperingen; voer dezelfde meting meerdere keren uit. Tot die metingen bestaan, staat `unit_tested=false` en is geen claim van verdwenen fysieke playbackdelay gemaakt.

Er blijven bekende, afzonderlijke open punten: completion-postverlies in WAM/coredll, callbackgeneraties bij sluiten/heropenen, Blue's threadtermination/closefailure, driver-/DDK-init/deinit/allocatie/stop en fysieke codec-/DMA-timing. Deze build repareert de hierboven afgebakende A2DP-bufferfouten; handsfree, pairing en overige Bluetoothfuncties zijn niet gewijzigd. Het [brede reparatieplan](update-repair-plan.md) blijft deze resterende zaken volgen.
