# Bluetooth-audiovertraging en een gecombineerd updatepayload

Max meldt twee concrete problemen: grote Bluetooth-audiovertraging, en een geslaagde hoofd-update waarna navigatie `File corruption detected, Navigation stops` meldt. Voor beide is inmiddels een [lokale gecombineerde LGU-onderzoekskandidaat](review-update-contracts.md) gebouwd en volledig uitgepakt en vergeleken: minder startbuffering in `Blue.exe`, met de bestaande losse navigatie-executable in dezelfde payload. Er is geen apparaat getest of geflasht.

`py tools/inspect_bt_playback.py` bewaart [25 originele codebereiken, vergelijking met 4.0.6, PCM-modellen en de payload-unie](firmware/bt-playback-contracts.json). Het controleert vijf instructie-preimages, veertig format-/packetcases, 12.288 accumulationcases en de SHA-256/grootte van alle 1.918 voorgestelde bestanden. Bron-Blue.exe: `5e659f513327c84964a929ea9b9e3192384b3031fa6e6ffb6ad76b02af1b7c7b`.

## A2DP-muziekpad en PCM

Dit is de A2DP/SBC-muziekroute in Blue, afzonderlijk van de [8-kHz handsfree/EchoCanceller-route](echo-audio-contracts.md). `SbcProcessDecode` op `24e64` slaat dertien transportbytes over, decodeert SBC-frames via `891a0/894a4`, bouwt maximaal 8192 PCM-bytes en geeft ze door via de volgende filter-vtable-slot +24. De volledige SBC-decoder en malformed transportgrenzen blijven open.

Configparser `24840` kiest samplefrequentie 16000/32000/44100/48000 en één of twee kanalen uit de ontvangen SBC-bits. Hij schrijft die via `193e0` naar de AV-context: channels +db, rate WORD +dc en bits +de = **16**. Getter `193b4` geeft dezelfde velden door aan de WinPlay-openroutine. De werkelijk onderhandelde frequentie op Max' telefoon is nog niet gemeten.

WinPlay-init `26550` maakt een 0x340-byte context en vraagt **640.000 bytes** audiogeheugen aan. Open `266a4` bouwt 25 WAVEHDRs van 32 bytes, met pointers op onderlinge afstand **0x6400 / 25.600 bytes**. PCM-open vraagt `waveOutOpen` met device `ffffffff`, CALLBACK_THREAD `20000`, de onderhandelde kanalen/rate en 16-bit samples. De totale reservatie alleen is geen aanwezige playbackvertraging.

Start `26c68` zet state +4=2, restarted +338=0 en roept **waveOutPause** aan. Open/prepare en de callbackthread krijgen afzonderlijke statuspaden. De [Microsoft-documentatie voor waveOutPause](https://learn.microsoft.com/en-us/windows/win32/api/mmeapi/nf-mmeapi-waveoutpause) en [waveOutRestart](https://learn.microsoft.com/en-us/windows/win32/api/mmeapi/nf-mmeapi-waveoutrestart) beschrijft pauzeren en hervatten; deze documentatie is geen bewijs dat de specifieke ROM-driver iedere call succesvol uitvoert.

## De werkelijk aanwezige buffering

WinPlayProcess `26e14` accumuleert PCM op context +334. Assembly `26f58` bevat `sltiu t1,t1,5001`: pas bij **meer dan 20.480 bytes** wordt een header aangeboden aan waveOutWrite. De pendingcounter op +5 wordt vooraf verhoogd. De producerindex +6 gaat modulo 25 vooruit.

Na die write test `27010` met `sltiu t2,t1,000b` of pending kleiner is dan elf. Pas bij **pending ≥11** en restarted=0 volgt waveOutRestart op `27040`, en wordt restarted=1 gezet. De callback `26400` verlaagt pending bij WOM_DONE `3bd`; wanneer die count nul wordt, zet hij restarted=0 en pauzeert opnieuw. Onder deze voorwaarden bouwt de volgende start dus opnieuw dezelfde reserve op.

Bij succesvolle writes en daadwerkelijk gepauzeerde output is de minimaal aangeboden PCM vóór restart:

`11 × 20.481 = 225.291 bytes`.

| Onderhandeld PCM | Ondergrens audio-inhoud vóór restart |
| --- | ---: |
| Stereo, 16-bit, 48 kHz | 1.173,39 ms |
| Stereo, 16-bit, 44,1 kHz | 1.277,16 ms |
| Mono, 16-bit, 48 kHz | 2.346,78 ms |

Dit zijn PCM-duurondergrenzen, geen gemeten wall-clock vertraging. Packetdelivery kan burstgewijs zijn; telefoonbuffering, transportjitter, driver/DMA, audiofocus en bestaande timestampcompensatie komen daar afzonderlijk bij. Een mislukte Pause/Write/Restart-call kan het gevolgde normale model eveneens veranderen.

De concrete modellen geven bij stereo 44,1 kHz:

| PCM per decode-aanroep | Bufferlengte bij submit | Elf buffers | Drie buffers, kandidaat |
| --- | ---: | ---: | ---: |
| 512 bytes | 20.992 | 1.309,02 ms | 357,01 ms |
| 1024 bytes | 21.504 | 1.340,95 ms | 365,71 ms |
| 2048 bytes | 22.528 | 1.404,81 ms | 383,13 ms |
| 4096/8192 bytes | 24.576 | 1.532,52 ms | 417,96 ms |

Het model verandert alleen de restartcount; de PCM-duren schalen exact met **3/11**. De blockgrootte is dus een tweede, afzonderlijke bron van resterende reserve. Een definitieve lage latency vereist keuzes voor zowel submitgrootte als startreserve, plus een onderflowtest onder echte packetjitter.

## Vergelijking met het beschikbare 4.0.6-pakket

De beschikbare downgrade identificeert zich als 4.0.6; hij bewijst niets over alle oude releases. Zijn WinPlayProcess `507a0` submit bij accumulated ≥**15360** en heeft een vroege waveOutRestart bij pending ≥**2**. Een simpele normale-routeprojectie geeft bij stereo 44,1 kHz en packets 512..4096 bytes ongeveer **174..186 ms**, tegenover 1,31..1,53 seconde in de gevolgde 7.0.5.MD-cases.

4.0.6 heeft ook speciale hold-/overflowbranches, verschillende tellers en eigen resets. De modelsheet houdt zijn vroege restartcondition afzonderlijk; hij emuleert niet alle legacy-toestanden. De hele oude Blue.exe terugplaatsen is daarom geen onderbouwde fix. De waargenomen overstap van een kleinere reserve naar elf grotere buffers is wel een concrete statische verklaring voor extra vertraging in het nieuwere muziekpad.

## Exact patchpunt, nog geen gekozen of geteste fix

Een minimale onderzoekskandidaat wijzigt uitsluitend de restartvergelijking:

| Eigenschap | Waarde |
| --- | --- |
| Module / VA | Blue.exe / 00027010 |
| Bestandsoffset | 00016410 |
| Originele bytes | `0b 00 2a 2d` |
| Kandidaatbytes | `03 00 2a 2d` |
| Voor / na | `sltiu t2,t1,11` → `sltiu t2,t1,3` |
| Veranderde bytes | 1 |

De producer maakt alleen een **memory-only kopie**, controleert SHA-256 en instruction-preimage, wijzigt het immediate en controleert dat alle overige bytes gelijk blijven. Er wordt geen aangepaste executable weggeschreven. Deze kandidaat is geen definitief gekozen threshold en geen gemeten oplossing. Nieuwe bronhash, eventuele PE-checksum-/loadervereisten, correcte patchmanifesten en LGU-roundtrip moeten bij een daadwerkelijke build opnieuw worden gecontroleerd.

Voor een gerichte meting zijn ten minste nodig: negotiated PCM-format, tijd/size van decoded packets, header-submitcount/bytes, WOM_DONE, Pause/Restart-status en een hoorbare A/V-marker. Zo kan startupbuffering worden gescheiden van latere drift of herhaald onderflow-rebufferen. Een recorder/instrumentatiepatch wordt hiermee nog niet als geplaatst geclaimd.

## Aanvullende foutpaden

waveOutWrite-failure wordt gelogd, maar pending is dan al verhoogd en wordt niet teruggedraaid. Een ontbrekende callback voor de mislukte header kan daardoor een phantom pending-entry achterlaten. Bij pending ≥25 wordt de counter in de processbranch nul gemaakt zonder dat daarmee alle headers zijn vrijgegeven. Volledige scheduling/failuretraces blijven onderzoekbaar; deze zijn geen waargenomen unitfouten.

De arithmetic-verificatie vond tevens decoded packetgroottes waarbij de accumulatie over de nominale 25.600-byte slotafstand heen kan komen vóór submit. Dat bewijst een overlapmogelijkheid binnen de grote aaneengesloten buffer; het is niet automatisch een write buiten de totale 640.000-byte allocatie. Werkelijke SBC packetgranulariteit, wrapslot en queued-data-overwrite moeten apart worden onderzocht voordat dit wordt gepatcht.

Het [vervolgonderzoek naar lifecycle en ownership](bt-lifecycle-contracts.md) reproduceert de vollering-overwrite, counterwrap, ontbrekende write-rollback en foutieve restartvlag met begrensde oorspronkelijke instructies. Het bevestigt ook dat de close-unpreparelus bij het eerste succes stopt. De [lokale manageranalyse](wave-queue-contracts.md) toont dat een geslaagde normale WAM-close de resterende voorbereide proxies automatisch opruimt; de lus bewijst dus geen onvermijdelijk lek. Die analyse volgt bovendien concrete lengteweigering vóór de driver, twee completionqueues, postfouten en de beperkte 100-ms-barrier. De aanvullende reparaties en memory-only branchproef zitten nog niet in MAX01.

QoS-handler `183a8` logt bufferlevel en stuurt het naar filter-slot +38 via `25fc8`. De gevolgde WinPlay-/sink-slots doen niets; SBC wijzigt veld +10 met byte-wrap en clamping. De daadwerkelijke decoderconsumptie blijft open. AV-primitive-dispatch `1c45c` heeft een Delay Report-log die een WORD door tien deelt voor milliseconden. De aanwezigheid van die log bewijst geen actieve timingcompensatie in onze WinPlay-route.

## Corruption fix in dezelfde update

De user heeft bevestigd dat **de hoofd-update voltooit en de navigatie daarna faalt**. Dit is dus geen bewezen failure van LGU-extractie of firmware-installatie. De meegeleverde README beschrijft eveneens een aparte navi-fix na de hoofd-update.

De oorspronkelijke hoofdpayload heeft **1917 bestanden** en bevat geen `upgrade/Storage Card4/NNG/nngnavi.exe`. De losse fix bevat precies dat ene bestand: **10.364.952 bytes**, SHA-256 `d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9`, versie `9.4.6.398870`. De gecontroleerde unie heeft **1918 unieke, casefold-gecontroleerde paden**. Het bestaande bestand wordt ongewijzigd hergebruikt in dit plan.

Updaterroutine `14eb0` herkent het staged navigatiepad en verwijdert bij een aanwezige staged vervanger het bestaande doel. De gewone staged-copyketen kan het bestand daarna overdragen. Zie [opslag-/stagingcontracten](updater-storage-contracts.md) en [eerder navigatiefixonderzoek](research-02.md). Dit maakt opnemen in dezelfde payload technisch ondersteund; waarom de oorspronkelijke maker twee pakketten publiceerde is niet vastgesteld.

De latere copyhelper `181b4` controleert CopyFile-succes niet voordat de bron wordt verwijderd. Een samengesteld pakket alleen repareert die updaterzwakte niet. Ook version-eligibility, vrije ruimte, restartvolgorde, bestand-readback en herstel blijven bij de echte build te controleren.

Voor de interne navigatiepatch ontbreekt een ongemodificeerd origineel van **dezelfde navigatieversie**. De fixbinary bevat nog een corruption-errorpad; we weten dus niet exact welke oorspronkelijke check veranderd is. Dat staat los van het kunnen opnemen van het reeds beschikbare fixbestand in één pakket. Compatibiliteit met de actuele kaarten/config op de fysieke unit is nog niet geverifieerd.

Die lokale implementatie staat nu in `tools/build_review_update.py`, met revisie `7.0.5.MD.MAX01`, een buildmanifest en volledige archive-roundtrip. Zie [buildresultaat en versiecontrole](review-update-contracts.md). `inspect_bt_playback.py` zelf bewaart nog steeds uitsluitend de oorspronkelijke evidence en een memory-only patchmodel. De build bevestigt pakketbytes en payloadsamenstelling; acceptatie en gedrag op de unit blijven open.
