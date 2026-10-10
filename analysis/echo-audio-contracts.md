# Handsfree-audio: EchoCanceller, MicomManager en SSE

Dit rapport volgt de zeven exports van `EchoCanceller.dll`, de audio-open/buffer/processing/stopketen, de debugsocket en de aanroepen van `sse_int.dll`. Het beschrijft de wrapper en enkele SSE-contracten, niet alle 470 functiekandidaten van het DSP. Bronhashes, instructies en alle 382 parametertabelrecords staan in [echo-audio-contracts.json](firmware/echo-audio-contracts.json), reproduceerbaar met [inspect_echo_audio.py](../tools/inspect_echo_audio.py). Geen DLL of firmwarecode is uitgevoerd.

## Eigenaar en starten

De directe importer is **MicomManager**, niet Blue. Audio-overlayfunctie **`0x11904–0x11cdb`** roept afhankelijk van overlayselectie en lokale flags `StartEC(0,1)`, `StartEC(1,1)` en `EndEC()` aan. Selectie 0 gebruikt de normale route, selectie 4 de door de wrapper `SiriOn` genoemde route. De volledige audiofocus-/overlayprioriteit is nog open.

`StartEC`, **`0x10005320–0x100055bf`**, wacht 100 ms, reserveert `0x14a54` bytes en zeroet die zonder de malloc-uitkomst eerst te controleren. Een al bestaande context levert uitsluitend een logmelding en return op. Hij bereidt SSE voor, maakt vier events, opent vier wave-handles, bereidt buffers en start twee capturethreads met prioriteit `0x66`, quantum 2. Threadhandles worden na resume gesloten; loopflags/eventwakes worden voor stoppen gebruikt. Device-open-failure laat de gereserveerde context staan tot het stop-/cleanup-pad.

## PCM-contract

Openhelper **`0x100032c4`** maakt de volgende WAVEFORMATEX-contracten:

| Route | Device-index | In/out | PCM |
| --- | ---: | --- | --- |
| BT | 1 | `waveIn` + `waveOut` | Mono, signed 16-bit, 8000 Hz, block-align 2, 16000 B/s |
| HF | 0 | `waveIn` + `waveOut` | Mono, signed 16-bit, 48000 Hz, block-align 2, 96000 B/s |

Dit zijn de geprogrammeerde wave-API-indexen. De inmiddels gevolgde [ROM-wave-driverketen](wave-driver-contracts.md) koppelt twee drivers aan PSC2/PSC0 en hun hardware-ratehelpers. De koppeling HF→PSC2 en BT→PSC0 past bij registryvolgorde en 48-/8-kHz-contract, maar de werkelijke API-ID-volgorde en fysieke bedrading zijn nog niet op de unit bevestigd.

Headerinit **`0x100034b8`** maakt vier buffers per stream. BT-headerpayload is `0x400`/1024 bytes; HF-headerpayload `0x1800`/6144 bytes. Beide bevatten **64 ms** PCM. HF-output heeft een allocatiestride van `0x3020`, maar de gebruikte payloadlengte blijft `0x1800`; een grotere stride bewijst dus geen ander audioformaat.

Callbacks **`0x1000325c/0x10003290`** signaleren het betreffende inputevent bij wavebericht `0x3c0`. Capturethreads wachten eerst INFINITE en vervolgens per buffer `0x500`/1280 ms. Een niet-nul wachtuitkomst zet de gezamenlijke runflag op nul. De BT-thread bewaart bij zijn eerste buffer een aparte `0x400`-byte kopie; de verdere processing gebruikt de ringbuffers.

## Samplepad en SSE

Processingthread **`0x10002874–0x1000325b`** neemt uit iedere HF-inputbuffer 512 samples, telkens met stride zes 16-bit samples. In deze wrapper staat vóór die selectie geen low-passfilter. Dat zegt nog niets over filtering in de wave-driver of de daaropvolgende DSP.

Per frame volgen vier **`sseProcess`**-calls met pointerstappen van `0x100` bytes/128 samples: microfooninput, twee BT-input-/referentieposities, BT-output en verwerkt receive-output. De precieze betekenis van beide BT-inputpointers vereist nog de SSE-processorroute. De zes-DWORD debugstruct wordt als zevende argument meegegeven en na iedere call zeroed.

Het verwerkte receive-signaal wordt terug naar 48 kHz gebracht met zes waarden tussen opeenvolgende 8-kHz-samples. Met `avg` als signed gemiddelde naar nul afgerond:

```
m = avg(a,b); q = avg(m,a); e = avg(q,a)
r = avg(b,m); s = avg(r,m)
output = [a,e,q,m,s,r]
```

Dit is de werkelijk gevolgde reeks, geen ideale lineaire zesvoudige interpolatie. Het eind van een blok gebruikt ook het eerste sample van het volgende ringblok. De inspectietool modelleert de signed gemiddeldes zonder audio naar een apparaat te sturen.

SSE-failure wordt gelogd en zet een processingflag op nul; de wave-output-/bufferrequeuecalls blijven in de omringende loop aanwezig. De terugkerende waveOutWrite-/waveInAddBuffer-uitkomsten worden in deze loop niet gevalideerd.

## Configuratie en versies

De twee padpointers op **`0x10009148`** zijn:

- `\Storage Card\system\EC_config.bsd`
- `\Storage Card\system\VR_config.bsd`

Prepare **`0x10005000`** kiest index 0/1 uit zijn eerste argument. Alleen waarden >1 worden naar 0 teruggezet; een negatief argument heeft geen eigen ondergrenscheck. De gevolgde MicomManager-calls gebruiken 0 of 1. Configloader **`0x10004c70`** leest een positieve ftell-lengte volledig in een buffer en bouwt een 28-byte descriptor. Ontbrekende/lege/afgekorte config wordt gelogd en vrijgegeven; vervolgens blijft de descriptor NULL en de voorbereidingsroute gaat door. Geen `.bsd`-bestand is aanwezig in de beschikbare extracties.

Wrapper `GetECVersion` **`0x10003bf4`** retourneert `5.1.6.2014` en schrijft ook een leeg markerbestand met naam `\EchoCanceller_2015-12-24_17022`. Het is dus geen zuivere leesfunctie. De geïmporteerde SSE-versie is uit de functie en tabel bevestigd als **3.15.0.20004**, beschrijving `SSE (Integer)`, buildnaam `LGe_Renault_ULC2`, toolchain `msevc9`.

Prepare maakt SSE en zet parameter-ID's **3, 31, 30, 9, 10, 12, 4 en 39**. ID 31 is `sse_SampleRate=8000`, uit WORD op `0x10006088`; ID 30 is `sse_FrameShift=128`, uit WORD op `0x10006084`. Het kanaalargument wordt als signed WORD gebruikt voor ID 3 `sse_MicInCnt` en ID 4 `sse_RecvInCnt`. De switches ID 9 `sse_NRSwitch`, 10 `sse_AECSwitch`, 12 `sse_RAESwitch` en 39 `sse_RECVAgcSwitch` krijgen DWORD 2. De enumconversie op `0x10023f48` en `0x10024b24` benoemt **1=sseOff, 2=sseOn, 3=sseDisabled**. Switchhelper `0x10017928` behandelt 2 als actief: een overgang vanaf 2 naar 1/3 zet state 3 en meldt deactivatie; een overgang naar 2 meldt activatie en controleert module-/dependencyvoorwaarden. Bij de created-context schrijft de helper de waarde direct.

De SSE-parametertabel begint op **`0x100660b0`**, met **382 records**, stride **44**: 32 bytes inline ASCII-naam op +0, ID-DWORD op +32, datatype-DWORD op +36, count-WORD op +40 en metadata-/accessbytes op +42/+43. Lookup **`0x100235f8`** leest de ID's vanaf `0x100660d0`, dus 32 bytes binnen het eerste record; de recordcount wordt geladen vanaf `0x1006a258`. Alle ID's zijn uniek. Een eerdere parser begon bij die eerste ID en koppelde daardoor iedere ID aan de naam van het volgende record. De parser is gecorrigeerd en controleert nu ook acht concrete ID/naam-paren tegen de gevolgde setters. De oude aanduidingen AllSubBandCnt/MIXSwitch/RECVBweSwitch voor de wrappercalls waren dus onjuist.

Datatypehelper `0x10023528` leest de breedte uit 35 WORDs op `0x1006a2f0`. De gebruikte datatype 3 is 2 bytes en 19 is 4 bytes. Voor setteraccess geldt: mode 0 geweigerd (`0x108`); mode 1 uitsluitend vóór initialisatie (`0x10a` bij initialized); mode 2/4 uitsluitend na initialisatie (`0x109` bij created); mode 3 in beide fasen. De getter weigert mode 4 apart en heeft aanvullende module-/contextvoorwaarden. Created-magic is `0xa96709`, succesvolle initialized-magic `0xe6702f`; een initializefout zet `0x14fe042`. `sseInitialize` verwerkt een niet-lege BSD-descriptor, valideert modules en maakt FFT-/processingstate. De volledige BSD- en DSP-algoritmes blijven open.

De buitenstructuur en moduleverdeling van BSD zijn inmiddels apart gevolgd in [sse-bsd-contracts.md](sse-bsd-contracts.md). `sseProcess`, `0x10021340`, behandelt het debugargument vóór het audiopad. De gebruikelijke processingroute loopt via `0x1001f040` voor analyse/inputstate en `0x100205a4` voor output/synthese. Een apart modeveld op context +0xe0 kan processing overslaan of aanvullend de kopiehelper `0x100179e4` activeren. Deze helper kopieert mic/receive-inputs naar de overeenkomstige outputs met de geconfigureerde frameshift. Mode 4 met status `0x10d` heeft eveneens expliciete fallback-/mute-/fadepaden. Dat bewijst aanwezigheid van passthroughpaden, niet dat de MicomManager-start ze op de unit selecteert. DSP-kernelmathematica en de volledige betekenis van beide modevelden blijven open.

## Debugtransport en opnameexports

Na audio-start roept de wrapper `WSAStartup(0x202)`, `socket(AF_INET, SOCK_STREAM,0)` en bind aan **0.0.0.0:2012** aan. Deze initialisatiereturns worden door de startwrapper niet gebruikt om de daaropvolgende threadcreatie tegen te houden. Acceptfunctie **`0x10004e00`** doet `listen(...,5)` en één `accept`; daarna twee threads voor receive/transmit. Er is geen accept-retrylus in deze functie.

Receive **`0x10004110`** leest maximaal 256 bytes per `recv` en stopt alleen op -1 of externe flags. Een nette EOF-uitkomst 0 wordt ook als queue-item verwerkt. De tien-slotring heeft 256 payloadbytes plus lengte-DWORD per slot. Er is hier geen TCP-framing voor volledige logische requests; de ontvangen chunks worden aan SSE-debugverwerking aangeboden.

Transmit **`0x100042bc`** gebruikt een semaphore en tien slots van 1024 bytes plus lengte-DWORD. Na een niet-negatieve `send` wordt het ringitem afgeboekt, ook als minder bytes zijn verzonden dan gevraagd. De SSE-debuginhoud zelf is nog niet volledig gedecodeerd. Een geprogrammeerde luistersocket bewijst niet dat het echte apparaat netwerkconnectiviteit heeft of bereikbaar is.

Vier opnameexports toggelen lokale flags, events en writerthreads voor `MicInSignal.wav`, `MicOutSignal.wav`, `RecvInSignal.wav` en `RecvOutSignal.wav` op Storage Card3. MicomManager importeert MicIn, MicOut en RecvIn; de vierde export bestaat wel maar is niet via die statische import gekoppeld.

De vier writers **`0x100011c4/0x10001770/0x10001d1c/0x100022c8`** schrijven steeds `0x400` bytes van respectievelijk de SSE-microfooninput, BT-output, receive-input en verwerkte receive-output. Alle bestanden gebruiken 8000-Hz mono 16-bit PCM, met een 46-byte WAV-header: RIFF, een 18-byte `fmt ` inclusief nul-cbSize en `data`. Aanvankelijk is data-lengte nul. Bij de gewone tweede toggle zet de export een finalizeflag, wist de recordingflag en wekt de writer; deze zoekt naar offset 0, schrijft data-lengte `successful_block_count*1024` en RIFF-lengte `data_length+38`, daarna sluit hij het bestand. WriteFile-BOOL telt als een heel blok zonder controle van werkelijk geschreven bytes. De signalen worden uit gedeelde processingpointers gelezen, zonder een afzonderlijke snapshotkopie in de writer.

De stopfunctie voor EC zelf doet geen equivalent finalize/join/wake-pad voor deze vier recordingthreads. De betrokken events en headerglobals zijn gedeeld tussen writers. Of een opname bij call-stop blijft wachten, een foutheader krijgt of met hergebruikte buffers samenloopt, vraagt runtimevalidatie. Het offline headermodel is met een onafhankelijke WAV-reader gecontroleerd.

## Stop- en foutpaden

`EndEC`, **`0x10004460`**, zet de gezamenlijke runflag nul en wacht met 16-ms eventwakes op twee actieve-threadflags, zonder gevonden einddeadline. Daarna termineert hij de TCP-transmitthread, sluit netwerkstate, reset/unprepare/closes de vier wave-handles, vernietigt SSE/config en sluit events/context. Als de runflag al nul was, wordt de eerste threadflag-wacht overgeslagen; de gevolgen bij gelijktijdige cleanup vragen runtimeonderzoek.

Een concreet verkeerd eventveld is zowel in decompiler als raw code bevestigd: de HF-processingthread wist zijn actieve flag op context `+0x28`, maar sluit en zeroet **`+0x20`**, het BT-event. Hij gebruikt voor wachten juist `+0x2c`. De BT-thread sluit ook `+0x20`. Dit creëert overlappende eventcleanup; welke race werkelijk optreedt is nog niet gemeten.

De start-, stop- en samplecontracten zijn aan oorspronkelijke instructies gekoppeld. SSE-versietabel en alle parametertabelbytes zijn gelezen, niet alleen symbolen. Open blijven: volledige DSP/BSD-semantiek, echte configbestanden, ROM-wave-driver, opnamepaden, threadraces en de audiokwaliteit op de unit.
