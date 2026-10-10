# OEM-wave-streams: directe PCM-pointers, queue en completion

De twee meegeleverde I2S-drivers gebruiken voor gewone PCM-output dezelfde queue-/completionlogica. De aangeboden **private WAM-headerproxy** blijft in de driverlijst staan terwijl de driver diens PCM-pointer gebruikt. De completionroute verplaatst de lijst/currentpointer en wist proxy INQUEUE voordat zij WOM_DONE naar WAM roept. WAM en coredll zetten die gebeurtenis daarna om naar de twee eerder beschreven [callbackqueues](wave-queue-contracts.md).

`py tools/inspect_wave_streams.py` bewaart [48 oorspronkelijke functie-/leafbereiken, 18 tabelblokken en controles](firmware/wave-streams/contracts.json), plus [de bijbehorende assembly](firmware/wave-streams/reviewed-paths.asm). Het model interpreteert oorspronkelijke MIPS-instructies met delay slots en expliciete codegrenzen; allocatie, DMA-start en de consumptietrigger zijn fixtures. Geen firmware wordt native uitgevoerd. De concrete hardwaredevicekeuze, elektrische bedrading, scheduler en hoorbare latency zijn hiermee niet gemeten. MAX01 en de oorspronkelijke firmwarebestanden zijn niet gewijzigd.

| Module | Oorspronkelijke SHA-256 |
| --- | --- |
| ROM wavedev2_i2s.dll | `fec5ab038cf274c4cf74a6553f9a81328bba7100c8ec9b17438658a7fae9d67c` |
| ROM wavedev2_i2s2.dll | `eb9b1d5625e0be967f139a4fe1d3e67799bd71d0af1e5bdf7c55b6d1f347a009` |

De gekoppelde trace pint ook de oorspronkelijke waveapi/coredll-hashes uit het [manageronderzoek](wave-queue-contracts.md). Het artifact bewaart producer-, interpreter- en wave-queue-helperhashes. Bewaarde code omvat ook statisch gevolgde render/open/dispatchroutines; niet ieder bewaard bereik wordt geïnterpreteerd.

## De concrete output-vtables

Outputdevicevtable `c0941ca8` / `c0951d9c` bevat in slot +14 de factory `c09433d4` / `c09534e0`. De factory kiest voor gewone PCM een 148-byte object met deze streamvtable:

| PCM | I2S-tabel | I2S2-tabel | Render-slot +40 |
| --- | --- | --- | --- |
| 8-bit mono | c0941268 | c095135c | c0944630 / c095473c |
| 8-bit stereo | c09412ac | c09513a0 | c09449cc / c0954ad8 |
| 16-bit mono | c09412f0 | c09513e4 | c0944800 / c095490c |
| 16-bit stereo | c0941334 | c0951428 | c0944be4 / c0954cf0 |

Andere gevolgde keuzes zijn format-tag `164` (tabel c0941224/c0951318, 148 bytes), tag `3000` (c0941194/c0951194, 1684 bytes) en de input-/basetabellen. De interne betekenis van die speciale formats blijft afzonderlijk te volgen. De producer bewaart 16 streamtableblokken en twee outputdevicetableblokken. Bij de special-/basetabel stoppen de gevolgde slots op +38; daaropvolgende data wordt niet als functiepointer behandeld.

108 factory-instructiecases controleren tags 1/164/3000 × kanalen 1/2/3 × bits 8/16/24 × allocatiesucces/failure voor beide modules. De normale PCM-route weigert in de factory unsupported bitdiepte/kanalen; de twee speciale tags kiezen hun eigen object zonder daar diezelfde PCM-check te gebruiken. Dit is factoryselectie, geen vervanging voor de upstream formatvalidator of werkelijke hardware-open. Allocatiefailure retourneert nul vóór verdere objectinitialisatie.

Voor gewone PCM hebben alle vier outputtabellen dezelfde functies voor queue, completion, pause/restart, reset en close:

| Functie | I2S | I2S2 |
| --- | --- | --- |
| Queue, vtable +30 | c09438e4 | c09539f0 |
| Current-header advance/completion | c09439b0 | c0953abc |
| WOM_DONE-callback, vtable +24 | c0943630 | c095373c |
| Restart, vtable +10 | c0943e44 | c0953f50 |
| Pause, vtable +14 | c0943e88 | c0953f94 |
| PCM reset-wrapper, vtable +18 | c09445d8 | c09546e4 |
| Gemeenschappelijke reset | c0943e94 | c0953fa0 |
| Close, vtable +08 | c0944234 | c0954340 |

Dispatcher `c0942138` / `c0952198` koppelt outputmessage 9/c/6 aan queue/reset/close. Zoals het [driveronderzoek](wave-driver-contracts.md) al vastlegde, houdt de dispatcher daarbij de driver-critical-section vast en schrijft hij de MMRESULT apart van zijn TRUE API-return. Niet alle render-/interrupt-/powerlocks zijn hiermee gevolgd.

## Wat daadwerkelijk in de driverqueue zit

De queuefunctie controleert PREPARED-bit 2. Daarna gebruikt zij **de aangeboden proxy zelf** als linked-listnode, wist diens lpNext op +18 en bytesRecorded op +08, wist DONE en zet INQUEUE. Zij kopieert de PCM niet in deze routine. Belangrijke streamvelden:

| Offset | Betekenis |
| --- | --- |
| +0c | Objectrefcount |
| +10 | Running/pause-vlag |
| +18 / +1c / +20 | Callbackcontext / callbackfunctie / user |
| +38 | Eerste nog owned queueheader |
| +3c | Current renderheader |
| +40 | Queuetail |
| +44 / +48 | Current PCM-readpointer / endpointer |
| +4c | Geconsumeerde positieboekhouding |
| +50 | Devicecontext |
| +54 | Loopcounter |

Wanneer er nog geen current header is, komen +44/+48 direct uit de proxy-lpData en lpData+dwBufferLength. Wanneer running is gezet, vraagt queue de device-startfunctie aan. Anders blijft het blok queued zonder die aanvraag. De 64 flagcases (32 per DLL) bevestigen de PREPARED-controle en flag-/pointermutaties. De OEM-routine heeft zelf geen afzonderlijke INQUEUE-weigering; de eerder gevolgde WAM-writeguard blokkeert heraanbieding in het gewone API-pad. De flagcases gebruiken steeds een verse lijst en bewijzen geen veilige dubbele enqueue.

Twee verdere instructietraces controleren queue tijdens pause → restart → pause → volgende enqueue. De eerste gepauzeerde queue doet geen device-start, restart met actuele PCM doet één aanvraag, en de volgende gepauzeerde queue geen extra aanvraag. De hardware-startfunctie is gestubd; een aanvraag is geen bewijs van gestart of hoorbaar DMA-geluid.

## Directe PCM-consumptie en het moment van completion

Renderdispatch `c0943ff0` / `c09540fc` verwerkt alleen een running stream met een current PCM-pointer. Wanneer die pointer de endpointer bereikt, gebruikt hij de advance/completionfunctie totdat er weer bytes beschikbaar zijn of de queue leeg is. De concrete renderkernel komt uit vtable +40.

De statisch gevolgde 16-bit-stereokernel `c0944be4` / `c0954cf0` leest twee signed 16-bit samples rechtstreeks via stream +44 en schuift die bronpointer per stereoframe vier bytes op. Hij bewaart interpolatie-/samplegeschiedenis, rate-/phasevelden, vermenigvuldigt kanaalwaarden met gains en clipt bij optellen in reeds gemixte destinationdata. Deze DSP-loop is gepind en statisch gelezen, maar niet instructie-geïnterpreteerd of op hardware gevalideerd. Samen met de lokale CeAllocAsynchronousBuffer-pointeralias bevestigt dit een directe route van Blue-PCM naar de renderreadpointer; er is in deze gevolgde keten geen preparation-time PCM-snapshot.

In het gewone nonlooping advancepad gebeurt vóór de callback:

1. Current wordt naar lpNext verplaatst; de owned queuehead volgt die nieuwe header.
2. Bij een lege lijst worden tail en current PCM-pointers nul. Anders komen read-/endpointer uit de volgende proxy.
3. De oude proxy krijgt INQUEUE gewist en DONE gezet.
4. Vtable +24 meldt **WOM_DONE 3bd**, met de oude proxy als callbackparameter.

De acht drain-/closecases gebruiken per DLL 0, 1, 2 en 25 headers. De eventtraces bevestigen callbackvolgorde, flags en de al gewijzigde head/currentpointer. Na volledige drain is close toegestaan. De consumptietrigger is expliciet opgegeven door het model; de normale renderdispatch-preconditie en de daadwerkelijke tijd om samples te verwerken worden niet geëmuleerd.

Loopheaders hebben andere ownership. Zes instructiecases gebruiken BEGINLOOP+ENDLOOP met dwLoops 2, 3 en ffffffff. Bij de eerste advance blijft de proxy INQUEUE en volgt geen completion; de current PCM gaat terug naar de loophead. Een eindige teller daalt, ffffffff blijft onveranderd. Andere multiheader-/breakloopcombinaties zijn nog open. Een pointer die het blok één keer heeft doorlopen betekent daarom niet voor iedere header meteen vrijgave.

Een WOM_DONE hier markeert dat de streamheader is teruggegeven. Deze analyse bewijst **niet** dat de bijbehorende samples op dat moment al fysiek uit de luidspreker kwamen: renderdestination, DMA-fragmenten en hardwarepipeline kunnen nog audio bevatten. Dat is een apart onderdeel van de latencyanalyse.

## Reset geeft de drivernodes terug; Blue loopt achter

Gemeenschappelijke reset verhoogt tijdelijk de objectrefcount, pauzeert via de vtable, wist current/read/end/position/loopvelden en haalt de complete owned lijst leeg. Voor iedere node wordt de nextpointer opgeslagen en de head verplaatst voordat INQUEUE wordt gewist en DONE wordt gezet en de callback volgt. De laatste node wist de tail. Daarna daalt de tijdelijke referentie.

De PCM-resetwrapper roept bij succesvolle reset de restartfunctie aan. In alle acht resetcases (0/1/2/25 headers per DLL) staan head/current daarna nul, refcount weer 1 en de running-vlag **1**. Er wordt geen device-start aangevraagd voor de lege PCM-queue. Reset is hier dus geen blijvende pause; Blue's WinPlayStop gebruikt later nog een afzonderlijke pause-call.

Het callbackresultaat wordt in deze normale resetloop niet als reden gebruikt om nodes terug in de queue te plaatsen. De driver kan al zijn ownership vrijgeven terwijl WAM-runtimepost of de latere Blue-post faalt. De in het [manageronderzoek](wave-queue-contracts.md) bewezen postfouttraces en Blue's ontbrekende acknowledgment blijven daardoor relevant.

Close test op owned queuehead +38: zolang die niet nul is, geeft hij `0x21` zonder closecallback. Bij een lege lijst geeft hij WOM_CLOSE 3bc door en retourneert nul; de dispatcher laat de streamreferentie vallen. De WAM-private headers hoeven voor deze twee concrete drivers niet afzonderlijk native voorbereid/ontvoorbereid te worden: messages 7/8 hebben hier geen eigen dispatcherbranch en vallen terug op unsupported 8, dat WAM bij prepare/unprepare naar succes normaliseert. Dit volgt voor deze lokale dispatchers; het is geen algemeen contract voor iedere mogelijke externe driver/mixer.

## Gekoppelde oorspronkelijke OEM→WAM→coredll-trace

De producer deelt hetzelfde caller-/proxygeheugen tussen de oorspronkelijke I2S-queueslice, oorspronkelijke WAM-write-/completion-/postbytes en oorspronkelijke coredll-proxy-/threadcallbackbytes:

1. Twee WAM-proxies worden werkelijk door de OEM-queueslice gelinkt.
2. Advance van de eerste proxy meldt WOM_DONE nadat die proxy uit de owned head is gehaald en INQUEUE is gewist.
3. WAM verlaagt zijn pending van 2 naar 1 en post de oorspronkelijke caller-WAVEHDR-pointer in zijn runtimequeue.
4. Coredll verwerkt die queue, zet original DONE/wist INQUEUE en post naar Blue's threadqueue.
5. De tweede proxy blijft current in de OEM-stream. Blue's eerste completion is nog niet verwerkt.

Dit verbindt nu de concrete OEM-private proxy met de oorspronkelijke Blue-header over drie modules. De trace plant één consumptionadvance expliciet; hardware/DMA en Blue's uiteindelijke GetMessage-verwerking zijn geen verborgen uitgevoerde stappen.

## Resterend lokaal werk

Het [DMA-vervolg](wave-dma-contracts.md) bevestigt inmiddels de twee startup-pumps en vensters van 4096/256 bytes en volgt HAL-descriptorhelpers en de interrupt-critical-section statisch. Te volgen blijven daadwerkelijke WAM-device/mixerselectie voor Blue, alle rate/interpolatiekernels en multistreammixing, renderdestination en begrensde DMA/MMIO-/allocatiefouttraces, volledige driverthread/interruptlocking, reset/close/powerinterleavings en objectlifetime bij runtimequeue-timeout of postverlies. De [reparatievereisten](update-repair-plan.md) blijven daarom succesvolle-submitboekhouding, vrije-slotselectie, headergrenzen en afgeronde Blue-callbackownership omvatten. Unitmetingen blijven nodig om de afzonderlijke statische bufferinglagen aan Max' hoorbare vertraging te koppelen.
