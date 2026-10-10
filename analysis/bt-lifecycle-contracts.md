# Bluetooth: bufferownership, callbacks en afsluiten

De elf-bufferreserve verklaart veel van de statisch aanwezige [startvertraging](bt-playback-contracts.md). Deze verdere analyse vindt afzonderlijke fouten in het volle-wachtrijpad, audiocall-foutafhandeling en de afsluitlus. De bestaande MAX01-kandidaat bevat uitsluitend de eerdere 11→3-wijziging en de navigatiefix; de hier beschreven reparaties zitten daar nog niet in. Geen apparaat is getest of geflasht.

**Implementatievervolg:** de nieuwe [MAX02-build](bt-patch-contracts.md) repareert inmiddels de afgebakende PCM-selectie/ownership/lengte/write/restart/completion/unprepare/partial-stoproutes met een kleinere reserve. Het oorspronkelijke bewijs en de bredere lifetime-/kernelonzekerheden hieronder blijven relevant; MAX01 is ongewijzigd.

`py tools/inspect_bt_lifecycle.py` bewaart [35 oorspronkelijke codebereiken, tabellen en begrensde instructiemodellen](firmware/bt-lifecycle/contracts.json), plus [de bijbehorende assembly](firmware/bt-lifecycle/reviewed-paths.asm). Blue-bronhash is `5e659f513327c84964a929ea9b9e3192384b3031fa6e6ffb6ad76b02af1b7c7b`; ROM-coredll is `1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c`.

De modellen interpreteren de oorspronkelijke little-endian MIPS-instructies met delay slots binnen expliciete codegrenzen. OS-calls zijn stubs, PCM-kopieën zijn geheugenintervallen en de callbackvolgorde is een opgegeven fixture. Onbekende instructies/calls en te lange loops stoppen de controle. Dit is geen native firmware-uitvoering of volledige driver-/scheduleremulatie. Zeven filterpointers en zeventien exacte instructie-preimages worden afzonderlijk gecontroleerd.

## De echte filterketen en twee statuslagen

Helper `25a30` registreert SBC-decoder → WinPlay → sink-terminator. De WinPlay-tabel op `110330` heeft:

| Tabelslot | Functie | Betekenis |
| --- | --- | --- |
| +0c | 26550 | Context/PCM/critical-section initialiseren |
| +10 | 26628 | PCM/context vrijgeven, global wissen |
| +14 | 266a4 | Wave/thread openen, 25 headers voorbereiden |
| +18 | 26a8c | Wave/thread afsluiten |
| +1c | 26c68 | Start; output eerst pauzeren |
| +20 | 26d2c | Stop; reset en pause |
| +24 | 26e14 | PCM verwerken |
| +38 | 37140 | QoS: alleen `jr ra; nop` |

`FiltersRun` op `25a5c` beheert een andere statusbyte, tabel +7: 0 niet geïnitialiseerd, 1 geïnitialiseerd, 2 open, 3 gestart. Opcodes 0/1/2/3/4/5 betekenen init/deinit/open/close/start/stop. Close stopt eerst als de tabelstatus 3 is, en roept vervolgens de close-slot aan. Die eerste stopreturn wordt in dat closepad niet als resultaat gebruikt.

WinPlayProcess controleert wavehandle +8 en de twee gedeelde AV-vlaggen +11c/+11d via `18220`/`18260`. Hij controleert daar **niet** zijn eigen contextstate +4 of de filtertabelstatus. Vlaggen, tabelstatus, OS-handle en queueownership moeten daarom samen coherent blijven.

Binnenkomende `HandleAvStartInd` op `1ace4` zet de gedeelde +11d-vlag nul en doet stop → close → open → start, waarna de vlag weer één wordt. `HandleAvReconfigureInd` op `1b87c` zet eveneens de vlag nul, doet opcode **3/close** en daarna open, en herstelt de vlag. Het log noemt de eerste stap daar STOP, maar de dispatch en tabel bewijzen dat hij ook afsluit. Alleen logteksten volgen zou het verschil missen.

Andere gevolgde callers zijn CloseInd `1b1dc`, Streaming_Navi_StartReq `1cb6c`, AVRCP_PauseReq `1ef64` en AVRCP_PlayReq `207f4`. De laatste drie kunnen open/start aanvragen zonder zelf de complete binnenkomende StartInd-reeks te volgen. Niet alle AV-/audiofocuscallers of races zijn hiermee afgewerkt.

## Volle ring: tellen, kiezen en kopiëren raken uit elkaar

Iedere header heeft een eigen PCM-pointer op 25.600-byte afstand. Blue gebruikt **dwUser** op header +0c als eigen bezetmarkering. Dit is iets anders dan de OS-flags op header +10. De [Windows CE WAVEHDR-layout](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452420(v=msdn.10)) bevestigt die twee aparte velden.

Selector `2639c` leest de producerindex. Alleen als de gekozen header-dwUser nul is, schrijft hij de current-bufferpointer +330 en wist hij accumulated +334. Bij een bezette header geeft hij geen foutstatus door en laat hij de oude pointer staan. Process kopieert daarna gewoon naar die pointer. De bovengrenscheck gebruikt het **einde van de gehele allocatie**, niet het einde van het gekozen slot.

De volgende fixture is bij vijf packetgroottes en zowel de originele elf-buffergrens als de drie-bufferkandidaat met de oorspronkelijke instructies gereproduceerd:

1. Er worden 25 headers succesvol aangeboden voordat Blue een WOM_DONE verwerkt. Restart wordt wel aangeroepen; de fixture veronderstelt uitgestelde completionverwerking, geen blijvend gepauzeerde driver.
2. Pending is 25, producer is 0, current wijst nog naar slot 24 en accumulated is nul.
3. Een volgend pakket van vier bytes laat selector 2639c op de bezette header 0 stranden. De kopie overschrijft het begin van nog gequeued slot 24.
4. Process zet pending op **nul** bij `27084`, zonder daarmee gequeued headers of hun dwUser-markeringen vrij te geven.
5. De completion van header 0 verlaagt die byte via `264b0/264bc` van 0 naar **255**.
6. Met alleen die ene completion en drie nieuwe 8192-byte pakketten komt een nieuwe submit voor header 0, lengte 24.580. De nieuwe PCM is echter naar slot 24 geschreven; de aangeboden header wijst naar slot 0. De kopiepointer en de submitpointer komen dus niet overeen.

Alle kopieën in deze fixture blijven binnen de 640.000-byte allocatie. Dit bewijst queued-data-overwrite en verkeerde buffertoewijzing onder de genoemde voorwaarden, geen write buiten de totale allocatie. De modellen bewijzen ook niet dat deze burst-/callbackvolgorde op Max' unit voorkomt. Een onderflow- of volleringfix mag de counter niet simpel nul maken, en mag een mislukte bufferselectie niet behandelen alsof hij een vrije buffer opleverde.

## Mislukte write en restart

Process zet dwUser=1 en verhoogt pending **vóór** waveOutWrite. Een nonzero return leidt tot een log, waarna de gewone restart-/producerbranches doorgaan. Er is geen rollback van pending/dwUser. In een fixture met mislukte writes zonder callback zijn de echte gequeued headers nul, terwijl pending de startgrens bereikt en restart wordt geprobeerd. Dit is voor zowel grens 11 als grens 3 gereproduceerd.

De restarted-vlag wordt in de delay slot van de waveOutRestart-call, `27044`, al op één gezet. De return wordt niet gecontroleerd. Een nonzero restartreturn zonder callback laat daardoor de vlag één staan; de twee volgende succesvolle submits veroorzaken geen nieuwe restartpoging. Het model bewijst die controlflow, niet welke fysieke driverfout op de unit ontstaat.

Een apart 6656-byte-inputvoorbeeld levert een submit van 26.624 bytes voor een header die oorspronkelijk voor 25.600 is voorbereid. Die kopie blijft bij het eerste slot binnen de grote allocatie, maar overschrijdt de voorbereide headerlengte en de slotafstand. Windows CE staat een wijziging van dwBufferLength tussen prepare en write toe binnen de oorspronkelijke voorbereiding; dit voorbeeld overschrijdt die grens. Zie [waveOutPrepareHeader](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452457(v=msdn.10)). Het [vervolg in de lokale wave-manager](wave-queue-contracts.md) bevestigt met gekoppelde oorspronkelijke instructies dat WAM dit blok vóór de driver met `0xb` weigert; Blue houdt toch pending=1 en dwUser=1. Dit specifieke voorbeeld bewijst dus geen oversized driverread. Of de onderhandelde SBC-/transportcombinatie precies zulke decoded pakketten levert, blijft open.

## Afsluiten stopt bij de eerste geslaagde unprepare

Open bereidt bij succes alle 25 headers voor. Close begint met index 0 en status 1. Na iedere unprepare wordt de API-return de nieuwe status. Branch `26ad4` verlaat de loop wanneer die status **nul** is: dus na de eerste succesvolle call. Zijn alle calls succesvol, dan wordt alleen header 0 aangeboden en worden headers 1..24 overgeslagen.

De 26 relevante returnklassen zijn gecontroleerd: eerste succes op index 0..24, of geen succes. De code probeert precies de headers tot en met het eerste succes. De [Windows CE unprepare-documentatie](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452465(v=msdn.10)) geeft nul als succes en vereist cleanup na drivergebruik en vóór buffervrijgave. Deze analyse bewijst welke cleanupcalls ontbreken; hij meet geen concrete geheugenlek of drivercorruptie.

**Nadere lokale manageranalyse corrigeert de impact:** WAM-close ruimt bij de gewone devicefixture alle overgebleven voorbereide proxies automatisch op wanneer niets queued is. Na één expliciete Blue-unprepare worden de resterende 24 dus bij een geslaagde close alsnog verwijderd. De vroege loop-exit bewijst geen onvermijdelijk bufferlek bij normaal afsluiten. Queued headers blokkeren manager-close; driverfouten en cleanup daarna hebben afzonderlijke ownershipvragen. Zie het [instructiebewijs en de 26 closepreflightcases](wave-queue-contracts.md).

Een **memory-only** reparatieproef vervangt de branch op VA `26ad4`, file-offset `15ed4`, van `0d 00 00 12` naar `00 00 00 00`. Daarmee worden alle 25 headers eenmaal geprobeerd, ook bij eerdere errors. Dezelfde 26 returnklassen bevestigen dit. Het resultaat zou bronhash `e751ac9eef00fef3709c67b859c893653c29612fcf4627c64ebc92e49e153e77` hebben en verandert twee bestandbytes. Er is geen executable weggeschreven en MAX01 is niet veranderd. Dit is een afgebakende reparatie van de premature loop-exit; failed-unprepare/retry, close, threadstop en ownership blijven afzonderlijk nodig.

Close wist de wavehandle bij `26b6c` ongeacht waveOutClose-return. Het nonzero-resultaatvoorbeeld bevestigt dat verlies van de lokale handle. Hij haalt daarna de thread-exitcode op, roept bij succesvolle query **TerminateThread** aan zonder STILL_ACTIVE als eigen conditie te testen, sluit de threadhandle en wist alle PCM via de werkelijk bevestigde memset-wrapper `3a750`.

De callback heeft een critical section rond dwUser, flags, pending en de mogelijke waveOutPause-call. Close heeft na zijn eigen LeaveCriticalSection nog Sleep(0) en threadtermination. Er is geen expliciete join van de Blue-callbackthread vóór PCM-clear. Microsoft beschrijft dat [TerminateThread op CE](https://learn.microsoft.com/en-us/previous-versions/ms913243(v=msdn.10)) een critical section kan achterlaten wanneer de gestopte thread die bezit. Een echte deadlockinterleaving, threadprioriteiten en alle driverlocks zijn hiermee nog niet bewezen.

## De meegeleverde CE-runtime heeft eigen callbackwachten

ROM-coredll `4009e854` gebruikt voor CALLBACK_THREAD `20000` daadwerkelijk **PostThreadMessageW**. Blue ontvangt daarom geposte MM_WOM-berichten met GetMessageW; de function-callbackrestricties mogen hier niet klakkeloos op worden toegepast.

waveOutWrite en unprepare gaan via wrapper `4007f774` naar DeviceIoControl `260054` en `260050`. Reset `4007fe84` gebruikt `26003c`. Als die drivercall succes oplevert, zoekt hij de runtime-stream op en gebruikt hij helper `4009e7c4` met timeout **100**. Dit is geen onbeperkte wait op Blue's eigen handler. Een aanvullende lookup-/waitfailure kan de resetreturn veranderen nadat de driverreset al heeft plaatsgevonden.

Close `4007fcfc` doet iets vergelijkbaars na `260008`: aanvullende lookup/wait en daarna een gepost MM_WOM_CLOSE. Een nonzero uiteindelijke close-return bewijst daarom **niet altijd** dat de onderliggende driver nog open is. Een reparatie mag niet blind iedere nonzero close behandelen als een intact, opnieuw bruikbaar handle. Volgens het algemene [CE-closecontract](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452443(v=msdn.10)) kunnen queued buffers een close weigeren; de gevolgde lokale wrapper heeft daarnaast deze latere foutmogelijkheden.

De [CE-resetbeschrijving](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452459(v=msdn.10)) retourneert pending buffers als klaar. Het [queuevervolg](wave-queue-contracts.md) bevestigt inmiddels een runtimeproxyqueue plus een tweede Blue-threadqueue en een barrier van 100 ms die geen Blue-acknowledgment is. Het reproduceert ook misclassificatie van WAIT_FAILED, een late marker die een volgende wait voldoet en de twee completion-postfoutpaden onder expliciete fixtures. Reset-return, gepost bericht en door Blue afgewerkte completion zijn afzonderlijke gebeurtenissen. OEM-reset/DMA, volledige objectlifetime en werkelijk unitgedrag blijven verder te volgen.

## Stop/start en QoS: bewezen beperking van eerdere aannames

Een geïsoleerde WinPlayStop → WinPlayStart bij ongewijzigd PCM-format bewaart 8192 nog niet aangeboden PCM-bytes. Het volgende 24.576-byte-submit bevat die oude 8192 bytes. De instructiefixture bevestigt dat Stop en Start zelf accumulated niet wissen. De normale binnenkomende StartInd doet echter ook close/open; daarom wordt deze fixture **niet** als bewezen stale-audiofout bij telefoon-hervatten gepresenteerd.

QoS-handler `183a8` geeft het WORD-bufferlevel door aan `25fc8`, die filter-slot +38 aanroept. WinPlay en de sink hebben daar de lege returnroutine `37140`: deze route verandert geen WinPlay-prefill of slotgrootte. SBC-slot `2574c` verandert veld +10 met `(oud − level + 4) modulo 256`, vervolgens boven-/ondergrens +12/+11 voor geldige min≤max. Er zijn 1024 instructiecases en 65.536 WORD-periodiciteitscases gecontroleerd. Bij onderflow kan wrap de waarde naar de bovengrens sturen. De daadwerkelijke consumptie van dit veld in de onderhandelde decoder is nog niet gevolgd; dit is geen bewezen correctie of oorzaak van hoorbare latency.

## Vereisten voor verdere reparatie

De nieuwe bevindingen vragen om succesvolle-submitboekhouding, vrije-slotselectie vóór iedere PCM-kopie, grenzen per voorbereide header, foutstatus na restart, en volledige cleanup met afgeronde callbackownership. Een lagere startgrens alleen voldoet daar niet aan. Het ontwerp moet ook onderscheid maken tussen een geweigerde drivercall en een late runtime-waitfout na een reeds uitgevoerde operatie.

Lokaal onderzoek blijft beschikbaar: alle filter-/AV-callers, codecgranulariteit, verdere wave-manager/mixer-/objectlifetimepaden, OEM-drivercompletion, locking en power-/reconnectroutes. Unitmetingen van negotiated format, jitter, daadwerkelijke API-errors en A/V-latency ontbreken nog. Zie ook het [gecombineerde update-reparatieplan](update-repair-plan.md).
