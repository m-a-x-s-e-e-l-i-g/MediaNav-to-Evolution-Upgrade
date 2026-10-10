# Wave-manager: headergrenzen, twee callbackqueues en afsluiten

Het verdere Bluetoothonderzoek volgt de oorspronkelijke Blue-instructies tot in de meegeleverde `waveapi.dll` en `coredll.dll`. De manager weigert een submit boven de voorbereide capaciteit voordat hij de driver aanroept. Blue telt die geweigerde submit vervolgens toch als bezet. Bij normaal afsluiten compenseert de manager juist de te korte expliciete unpreparelus van Blue. De runtime-wacht bevestigt alleen verwerking in zijn eigen proxyqueue; Blue heeft zijn completion dan nog niet noodzakelijk verwerkt.

Dit corrigeert de mogelijke impact van de [eerdere lifecyclebevinding](bt-lifecycle-contracts.md), zonder de bewezen branchfout te ontkennen. MAX01 bevat nog dezelfde 11→3-startgrens en bestaande navigatiefix. Geen firmware is native uitgevoerd, geen apparaat is getest of geflasht en geen firmwarebestand is gewijzigd.

`py tools/inspect_wave_queue.py` bewaart [de oorspronkelijke codebereiken, exacte instructies en controles](firmware/wave-queue/contracts.json) en [de bijbehorende assembly](firmware/wave-queue/reviewed-paths.asm). De controles interpreteren begrensde little-endian MIPS-instructies met delay slots. OS, device-vtable, handlelookup en table-iteratie zijn expliciete fixtures. Aligned LWL/LWR/SWL/SWR-paren worden gecontroleerd; andere alignment wordt geweigerd. PCM-kopieën worden door intervalmodellen vertegenwoordigd. Onbekende instructies, calls of code buiten de gekozen grenzen stoppen de controle.

## Bronnen en reproduceerbare dekking

| Module | SHA-256 van de oorspronkelijke bron |
| --- | --- |
| Blue.exe, 7.0.5.MD | `5e659f513327c84964a929ea9b9e3192384b3031fa6e6ffb6ad76b02af1b7c7b` |
| ROM waveapi.dll | `75dda3a4642c385b50c71e262c0676e61d7ee28e736d2093270dbabcf8fbc975` |
| ROM coredll.dll | `1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c` |
| ROM audevman.dll | `9991a8b5f195c29aff63fee1c5fd034e1295b84cef43a37463f93863dfdd3d65` |

De producer verifieert alle vier bronhashes en 14 exacte instructie-preimages, bewaart 40 oorspronkelijke functie-/leafbereiken en zijn eigen hash plus die van de gedeelde interpreter. Bewaarde code is niet automatisch geïnterpreteerde code: open/prepare, tablebeheer, audevman en sommige runtime-lifetimeroutines zijn statisch gevolgd en gepind; de uitvoertraces beperken zich tot de expliciet beschreven slices.

| Controle | Aantal |
| --- | ---: |
| Lengte × originele header/PCM-identiteit | 36 |
| Headerflags × driver-write-return | 64 |
| Positie van queued header / geen queued header bij close | 26 |
| Unprepare-driverreturns | 4 |
| Gekoppelde Blue→WAM-lengteweigering | 1 |
| Driverqueue→runtimeproxy→Bluequeue met barrier | 1 |
| Geïnjecteerde waitreturns | 4 |
| Async-buffer geeft oorspronkelijke PCM-pointer terug | 1 |
| Verlies bij runtimepost en bij Blue-post | 2 |
| Late marker van eerdere timeout voldoet volgende wait | 1 |

## Prepare bewaart een eigen capaciteit en identiteit

WAM-dispatcher `c03f3410` koppelt close/write/prepare/unprepare/reset aan `260008`, `260054`, `260038`, `260050`, `26003c`. Type 2 is output. De streamlookup controleert een ownergebonden handle; de modellen leveren een vooraf geregistreerde stream en type-5-headerentries als fixture.

Prepare `c03f97f0` maakt een **48-byte private headerproxy**. Original WAVEHDR is 32 bytes; original +1c krijgt een geregistreerd token naar deze proxy. Belangrijke proxyvelden zijn:

| Offset | Betekenis |
| --- | --- |
| +00 | Asynchrone PCM-pointer |
| +04 | Actuele submitlengte |
| +08 | bytesRecorded |
| +0c | Kopie van original dwUser |
| +10 | Private WAVEHDR-flags |
| +14 | dwLoops |
| +20 | Streamtoken |
| +24 | Pointer naar oorspronkelijke caller-WAVEHDR |
| +28 | Oorspronkelijke caller-PCM-pointer |
| +2c | Oorspronkelijk voorbereide capaciteit |

Prepare controleert alignment en blockalign. Voor output vraagt hij `CeAllocAsynchronousBuffer` met descriptor `80000004`. Driverbericht 7 bereidt de proxy voor; return 8 wordt hier als ondersteunde fallback naar nul genormaliseerd. Bij succes krijgen zowel original als proxy PREPARED-bit 2. De lokale prepare-route weigert al prepared/inqueue headers met `0xb`; een algemeen API-contract vervangt deze lokale controlflow niet.

Validator `c03f2aa4` controleert token/type/owner, original-headeridentiteit, original-PCM-identiteit en **requested length ≤ proxy +2c**. De lengtevergelijking is unsigned. De oorspronkelijke capaciteit blijft dus apart bewaard wanneer Blue original dwBufferLength verandert.

## De oversized Blue-submit bereikt de driver niet

Write `c03fa2f0` weigert een header zonder PREPARED met `0x22`, of met INQUEUE met `0x21`. Daarna zet hij original INQUEUE, valideert de proxy, kopieert de actuele lengte/loopgegevens en biedt driverbericht 9 aan. Bij een validatiefout geeft hij `0xb` terug en wist original INQUEUE. Bij een driverfout draait hij ook zijn eigen pendingtoename terug. Blue's dwUser is geen managerownershipveld en wordt daarbij niet hersteld.

Het gekoppelde instructiemodel deelt callergeheugen tussen de echte Blue-processslice en de echte WAM-write-/validatorslices:

1. Vier binnenkomende PCM-blokken van 6656 bytes laten Blue een header met lengte **26.624** aanbieden.
2. De proxycapaciteit is **25.600**.
3. WAM geeft **`0xb`** terug en doet **geen driver-write**.
4. Blue houdt pending=1 en dwUser=1, terwijl original WHDR_INQUEUE nul is.

Dit bewijst een concrete lokale route naar foutieve submitboekhouding. Het bewijst niet dat de onderhandelde SBC-transportconfiguratie op Max' unit precies 6656 decoded bytes aanlevert. De PCM-kopie overschrijdt de slotafstand binnen de grote Blue-allocatie; een te lange driverread uit dit geweigerde blok volgt hier **niet** uit. Andere writefouten en de eerder bewezen volle-ringoverschrijving blijven afzonderlijke routes.

## Geslaagde manager-close ruimt resterende voorbereide headers op

Close `c03f88d4` gebruikt voor de gewone devicefixture eerst helper `c03f86bc`. Die scant geregistreerde type-5-proxies voor het betreffende streamtoken in twee passes:

1. Iedere nog queued proxy blokkeert close. Eerder tijdelijk gereserveerde flags worden hersteld; de helper geeft nul terug en close geeft `0x21`. Er is dan geen driver-close.
2. Als niets queued is, worden de matching headers tijdelijk INQUEUE gemarkeerd om writes te blokkeren. De tweede pass roept `c03f85bc` met force=1 aan voor alle matching headers.

Unpreparehelper `c03f85bc` haalt die tijdelijke reservering weg, roept voor PREPARED-proxies driverbericht 8 aan en gebruikt cleanup `c03f852c` om de registratie, asyncbuffer en private proxy te verwijderen. Die private cleanup gebeurt ook bij een nonzero driver-unprepare-resultaat; de automatische closepass gebruikt de individuele returns niet om te stoppen. Daarna volgt driver-closebericht 6; diens resultaat bepaalt verdere streamverwijdering.

Alle 25 queued-posities plus het geval zonder queued header zijn met oorspronkelijke instructies gecontroleerd. In de geslaagde fixture wordt na **één expliciete Blue-unprepare** de resterende **24 proxies automatisch** door manager-close opgeruimd. De vroege Blue-loop-exit bewijst daarom geen onvermijdelijk bufferlek bij een geslaagde normale close. De memory-only branchproef blijft een mogelijke verbetering van Blue's expliciete lus, geen zelfstandige volledige lifecyclefix.

De cleanup kan bij een driver-unpreparefout zijn private proxy al verwijderen. Welke eigendom een concrete driver dan nog heeft, is niet volledig gevolgd. De managerhelper werkt ook niet zelf de originele callerheader bij zoals het individuele unpreparepad doet. Closefouten na deze cleanup, stale callerflags/reserved tokens en de speciale softwaremixerroute moeten verder worden onderzocht; de success-fixture bewijst geen correcte fout-/raceafhandeling voor al die gevallen.

## De lokale async-bufferhelper kopieert output-PCM niet

In deze ROM valideert `CeAllocAsynchronousBuffer` op `40031e5c` outputpointer, sourcepointer en de descriptor-/lengtehelper `40031960`. Vervolgens schrijft hij de **oorspronkelijke sourcepointer ongewijzigd** naar de output. Voor descriptor 4/8/c accepteert die helper de opgegeven nonzero lengte rechtstreeks. De gemodelleerde outputdescriptor `80000004` levert precies Blue's PCM-pointer op; er ontstaat hier geen voorbereidingstijdsnapshot van de audio.

`CeFreeAsynchronousBuffer` op `40031ecc` controleert in deze leaf beide pointers en geeft nul terug, zonder allocatie vrij te geven. De private WAM-proxy heeft wel een afzonderlijke allocatie die wordt verwijderd. Dit onderscheid voorkomt dat proxycleanup en PCM-bufferownership worden verward. De fysieke driver-/DMA-/mixerconsumptie blijft open, maar deze runtimehelper beschermt queued audio niet met een private kopie tegen Blue's volle-ringoverwrite.

## Een completion gaat door twee aparte queues

Open `c03f9428` registreert drivercallback `c03f10b0` en forceert richting driver CALLBACK_FUNCTION `30000`. Blue's oorspronkelijke CALLBACK_THREAD-keuze wordt later door de runtimeproxy verwerkt.

Callback `c03f10b0` verlaagt voor de gewone devicefixture WAM-pending en post via `c03f1000` een **20-byte record**: message, runtime-clientobject, oorspronkelijke callerheader, callbackparameter, bytesRecorded. WOM_DONE is `3bd`. Deze eerste queue is een Windows CE messagequeue, niet Blue's GetMessage-queue.

Runtimeproxy `4009ea98` leest dat record, wist op de original callerheader INQUEUE en zet DONE. Daarna geeft `4009e854` het door. Bij CALLBACK_THREAD `20000` gebruikt hij **PostThreadMessageW** naar Blue's thread. Blue verwerkt later dat tweede bericht en wist daarbij zijn eigen dwUser/verlaagt pending. [Microsofts CE-contract](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms911939(v=msdn.10)) bevestigt dat PostThreadMessage terugkeert zonder op verwerking door de ontvangende thread te wachten.

Deze stappen zijn dus afzonderlijk: driver geeft de proxy terug → WAM verlaagt eigen pending → runtime werkt original flags bij → bericht staat bij Blue → Blue werkt eigen boekhouding bij. Een latere stap kan uitblijven terwijl een eerdere al geslaagd is.

## De 100-ms-barrier bewijst geen Blue-acknowledgment

Runtimehelper `4009e7c4` post een sentinelrecord met message `ffffffff` en hetzelfde runtimeobject. De overige drie DWORDs worden door deze slice niet geïnitialiseerd en worden bij sentinelverwerking niet gebruikt. Proxy `4009e854` zet voor die marker het event op object +10. Reset/closecallers vragen een wait van **100 ms**. De eenheid en betekenis van WAIT_FAILED volgen het [CE-waitcontract](https://learn.microsoft.com/en-us/previous-versions/ms915517(v=msdn.10)).

De begrensde instructietrace verwerkt eerst een WOM_DONE en dan de sentinel. De wait retourneert succes, original WHDR_DONE is gezet en INQUEUE gewist, maar **Blue's WOM_DONE staat nog onverwerkt in zijn tweede queue**. Deze barrier levert dus geen bewijs dat Blue pending/dwUser coherent is of zijn thread al veilig kan worden gestopt.

Er zijn twee aanvullende lokale beperkingen:

- De helper behandelt alleen `WAIT_TIMEOUT (102)` als waitfailure. Bij een geïnjecteerde `WAIT_FAILED (ffffffff)` blijft de eerdere succesvolle queuepost als succesreturn staan. De daadwerkelijke oorzaak/frequentie van een ongeldige eventhandle is niet vastgesteld. Ook `80` is als returnclassificatie getest; het model claimt niet dat WAIT_ABANDONED normaal op dit event kan voorkomen.
- Het event wordt als auto-reset-event gemaakt door `4009e6c0`. De barrier heeft geen sequence-ID of eigen ResetEvent. In een fixture retourneert wait 1 timeout, wordt zijn marker later verwerkt, en vindt wait 2 vervolgens het reeds gesignaleerde event. Wait 2 retourneert succes terwijl zijn **eigen marker nog queued** is. Dit vereist dezelfde object/event en de opgegeven late verwerking; werkelijke scheduling is niet gemeten.

Een aanroep vanuit de proxythread zelf retourneert nul zonder marker te posten om geen eigen queue af te wachten. De open runtime-objectlifetimevraag blijft: welke referenties garanderen geldigheid van queued objectpointers na close/timeout? De bewaarde constructor/lookup/unlink/destructorranges zijn startpunten; er is nog geen complete driver-/kernel-lifetimetrace.

## Postfouten kunnen de ownershiplagen verder uit elkaar trekken

Twee afzonderlijke foutinjecties gebruiken de oorspronkelijke completion-, proxy- en barrierslices:

| Geïnjecteerde fout | WAM-pending | Original INQUEUE | Blue pending/dwUser | Latere barrier |
| --- | ---: | --- | --- | --- |
| WriteMsgQueue van completion retourneert FALSE | 0 | Blijft gezet | Blijven 1/1 | Succes na alleen sentinel |
| PostThreadMessage naar Blue retourneert FALSE | 0 | Gewist; DONE gezet | Blijven 1/1 | Succes |

De eerste posthelper vraagt GetLastError op, maar de gevolgde WAM-callbackroute heeft geen retry/herstelbranch op die mislukte post. Bij de tweede route retourneert `4009e854` zelf **1**, doordat zijn oorspronkelijke succesvariabele niet wordt vervangen door PostThreadMessage's FALSE. Er is geen Blue-completion in de fixtures. Dit toont de foutcontrolflow en de ontbrekende acknowledgment, geen gemeten queueverlies of permanent defect op de unit; latere herstelroutes zijn niet gemodelleerd.

## Verder te volgen

`audevman`-methode `c0412900` verpakt driverberichten in de eerder beschreven vijf-DWORD-envelope en gebruikt DeviceIoControl `1d000c`. Een FALSE API-return wordt MMRESULT 6; anders wordt de afzonderlijke driver-MMRESULT teruggegeven. Dat verbindt WAM aan de [OEM-I2S-driverketen](wave-driver-contracts.md). Het [concrete streamvervolg](wave-stream-contracts.md) bevestigt inmiddels beide PCM-vtableketens, driverlistownership vóór WOM_DONE en reset/close met oorspronkelijke instructies en een gekoppelde OEM→WAM→coredll-trace. Alle mixer/resampler-, driverlock- en DMA-bufferconsumptiepaden zijn daarmee nog niet afgewerkt.

Een volledige Bluetoothreparatie vraagt succesvolle-submitboekhouding, vrije-slotselectie vóór kopiëren, grenzen per voorbereide header, gecontroleerde restart, afgeronde Blue-callbackownership en een shutdown die daadwerkelijke verwerking bevestigt. Een gezonde manager-close compenseert de korte unpreparelus; API-errors, timeout/late markers, postfouten en objectlifetime vragen eigen behandeling. Het [reparatieplan](update-repair-plan.md) blijft breder dan de huidige MAX01-kandidaat. Unitformat, packetgranulariteit, jitter, reconnect en daadwerkelijke A/V-latency blijven te meten.
