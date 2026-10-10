# Audio-driverlifetime: initfouten, schijnbaar succesvolle retry en beperkte deinit

De oorspronkelijke buitenste init-/deinitcode van beide I2S-drivers is nu aan hun DMA- en interruptinit gekoppeld. Zij bevestigt drie lokale problemen: genegeerde foutreturns bij interruptconnect/initialize, een retry die na een mislukte eerste init meteen succes retourneert zolang de global nonzero is, en een WAV_Deinit die alleen een interrupt-chain-handler verwijdert maar de driverstate en overige resources lokaal behoudt. Bij mislukte DMA-channelallocatie loopt de oorspronkelijke IRQ-numberhelper bovendien door naar een read van **0x0c**.

Dit zijn codepaden onder expliciete fixtures. Er is geen native driver, IRQ-thread, OS-unload of hardware uitgevoerd. Dat deze paden op Max' unit optreden, de frequentie van deinit/initfouten en hun hoorbare impact zijn niet vastgesteld. MAX01 en originele modules zijn ongewijzigd.

`py tools/inspect_wave_lifetime.py` bewaart [20 oorspronkelijke codebereiken en alle traces](firmware/wave-lifetime/contracts.json), [assembly](firmware/wave-lifetime/reviewed-paths.asm) en de complete directe PE-importtabellen van beide drivers. Hun bronnen en de twee DDK-varianten hebben dezelfde gepinde hashes als het [DDMA-HAL-onderzoek](dma-hal-contracts.md). Producer en vier gebruikte helpers zijn afzonderlijk gehasht.

## Controlebereik en fixtures

| Oorspronkelijke instructietraces | Aantal |
| --- | ---: |
| Device-init → DMA-initwrapper → IRQ-number → connect → event/threadinit | 768 |
| WAV_Deinit met initialized/chain/free-returnvarianten | 16 |
| Eerste WAV_Init → tweede WAV_Init, met verschillende eerste fouten | 10 |
| Geslaagde WAV_Init → WAV_Deinit → WAV_Init | 2 |
| IRQ-numberleaf, 16 slots in user-/kernel-DDK binnen beide driverfixtures | 64 |

De interpreter voert de oorspronkelijke init, singletonfactory, exportwrappers, DMA-initwrapper, IRQ-connectwrapper, event-/threadsetup, deinit en vaste returnhelper uit. De gekoppelde IRQ-numberleaf gebruikt in de drivertraces expliciet de kernel-DDK-bytes; de user-DDK-leaf is daarnaast op dezelfde zestien slots gecontroleerd. Dit is een fixturebinding, geen gemeten runtime-importbinding.

PSC-setup, constructor, registrylookup/write, sample-ratevtablecalls en de afsluitende setuphelper zijn fixtures. HalAllocateDMAChannel en HalInitDmaChannel krijgen expliciete returns; hun interne fouten zijn apart in [DDMA-HAL](dma-hal-contracts.md) en [mapping](dma-mapping-contracts.md) onderzocht. Event/thread/interrupt/priority/handler-API's zijn gemockt. De fixture start geen thread en kent geen kernel- of driver-manager-unload. Bij een laag leesadres stopt de interpreter op de eerste readpoging.

## Concrete codeketens

| Stap | I2S | I2S2 |
| --- | --- | --- |
| WAV_Init-export | c09420ac | c095210c |
| Global-objectfactory | c0948128 | c0958224 |
| Device-init | c0947f78 | c0958074 |
| DMA-initwrapper | c09483c0 | c09584ac |
| IRQ-connectwrapper | c0948340 | c095842c |
| Event-/threadsetup | c0947ec4 | c0957fc0 |
| WAV_Deinit-export | c09420c8 | c0952128 |
| Device-deinit | c0947630 | c095772c |
| Vaste returnhelper, 8 bytes | c09481a4 | c0958600 |
| Global devicepointer | c094a140 | c095a13c |

Het globale object wordt toegewezen en gepubliceerd **vóór** device-init. De I2S-objectallocatie vraagt ec bytes; I2S2 vraagt e8. De device-init heeft een eigen initialized-veld op object+18. Output-/inputchannelpointers staan op +e0/+e4 voor I2S en +dc/+e0 voor I2S2; event/thread staan in beide op +b4/+b8, SYSINTR op +ac en chain-handler op +b0.

## Mislukte channelallocatie wordt vóór IRQ-lookup niet afgevangen

De [eerder gevolgde DMA-initwrapper](dma-hal-contracts.md) retourneert nul als de eerste of tweede HalAllocateDMAChannel nul geeft. De buitenste device-init test die return niet en roept daarna de IRQ-connectwrapper aan. Deze vraagt eerst het input-, daarna outputkanaal aan de IRQ-numberhelper.

`HalGetDMAHwIntr 40234198` / `c0424198` leest channel+0c, telt a0 op en maskeert op één byte. Voor echte fixture-slots 0..15 geeft hij a0..af. Hij heeft geen nullcheck. Als een kanaal ontbreekt, stopt de gekoppelde trace bij de oorspronkelijke **readpoging op adres 0x0c**, voordat InterruptConnect wordt aangeroepen. De trace pretendeert geen succesvolle verdere init of native faultafhandeling.

Dit is concreter dan een abstract genegeerde initreturn: een nul channelallocatie bereikt via de oorspronkelijke caller- en leaf-instructies een laag adres. De actuele OS-behandeling van dat adres en de incidentfrequentie blijven onbekend. Fysieke allocatiefailure binnen een nonzero channelobject is een ander, afzonderlijk gevolgd pad.

## Interruptconnect, initialize en priorityreturns verdwijnen

Bij twee nonzero channels legt de IRQ-wrapper de return van InterruptConnect op object+ac vast en retourneert false bij nul. De buitenste init test die wrapperreturn niet en gaat door naar event-/threadsetup.

Die setup vraagt een auto-reset, initieel niet-gesignaleerd, onbenoemd event aan. Als CreateEvent nul geeft, retourneert zij nul. Anders roept zij InterruptInitialize(SYSINTR,event,0,0) aan en **negeert de return**. Vervolgens vraagt zij een thread aan. Alleen de CreateThread-return bepaalt of dit pad verdergaat; CeSetThreadPriority-return wordt eveneens genegeerd.

De 768 combinaties leggen kanaalallocatie, beide DMA-initreturns, connectreturn, eventreturn, InterruptInitialize-return, threadreturn en priorityreturn vast. Wanneer twee channelobjecten en event/thread bestaan, kan de originele device-init **1 teruggeven en initialized=1 zetten bij connectreturn nul of InterruptInitialize-return nul**. Bij connectreturn nul is de gevolgde InterruptInitialize-call dus SYSINTR=0. Dit bewijst de lokale afhandeling met geïnjecteerde OS-uitkomsten, geen geldige/live interruptbinding.

Bij eventfailure blijft device-init nul; er is in dit bereik geen vrijgave van de reeds opgeslagen DMA-channels. Bij threadfailure blijft het aangemaakte event bewaard terwijl device-init nul blijft. Dit lokale bereik doet geen CloseHandle, interruptdisable of DMA-unwind. Abstracte false HalInitDmaChannel-returns worden eveneens genegeerd; normale vaste selectors zijn geldig, dus die injectie alleen bewijst geen bereikbare positieve-selectorfailure op de unit.

## Retry controleert alleen of de global bestaat

De objectfactory controleert als eerste uitsluitend de globale devicepointer. Als die nonzero is, retourneert zij **1**, zonder device-init opnieuw te roepen of initialized te lezen. Bij de eerste poging publiceert zij een nieuw object vóór de initcall en verwijdert de global niet bij een false initreturn.

De twee drivers zijn elk met vijf gekoppelde eerste-/tweede-callsequenties gecontroleerd:

| Eerste geïnjecteerde uitkomst | Eerste WAV_Init | Tweede WAV_Init | Extra werk tijdens retry |
| --- | ---: | ---: | --- |
| PSC-setup faalt na objectconstructie | 0 | 1 | Geen; initialized blijft 0 |
| CreateEvent faalt | 0 | 1 | Geen; initialized blijft 0 |
| CreateThread faalt | 0 | 1 | Geen; initialized blijft 0 en event blijft bestaan |
| Alle gevolgde stappen slagen | 1 | 1 | Geen |
| Eerste objectallocatie faalt | 0 | 0 | Nieuwe objectallocatiepoging, opnieuw geïnjecteerd nul |

De constructor is een fixture die een vooraf opgesteld object oplevert; de global-publicatie, initreturn, retrybranch en onveranderde state zijn oorspronkelijke instructies. Driver-managerbeleid over opnieuw aanroepen/unload is niet door deze sequenties bewezen.

## WAV_Deinit bewaart de driverresources lokaal

WAV_Deinit leest de global devicepointer en roept device-deinit aan. Device-deinit doet alleen:

1. Als object+ b0 nonzero is: FreeIntChainHandler(handle), zonder de return te testen, en daarna +b0=0.
2. De vaste helper aanroepen; diens twee instructies retourneren altijd 1.
3. Bool-success teruggeven.

De zestien deinitcases variëren initialized, aanwezige chain-handler en de geïnjecteerde FreeIntChainHandler-return. Ze bevestigen dat **global devicepointer, initialized, DMA-channelpointers, SYSINTR, event en thread onveranderd blijven**. Binnen deze oorspronkelijke keten is geen DMA-stop/free, event-/threadclose, threadjoin, SYSINTR-vrijgave, PCM-/descriptorrelease of reset van de global aanwezig. De kernelsemantiek van FreeIntChainHandler en eventuele externe unloadcleanup zijn niet geïnterpreteerd.

De directe PE-importtabellen bevatten geen HalFreeDMAChannel-import. Dat ondersteunt de gevonden lokale keten, maar bewijst op zichzelf niet dat nergens een indirecte resolutie kan bestaan. In het begrensd uitgevoerde deinitpad zijn alle calls wel expliciet gevolgd: de handler-API en de vaste returnhelper.

De twee gekoppelde success-init → deinit → reinit-traces behouden dezelfde resources en initialized=1 na deinit, afgezien van chain=0. Reinit retourneert vervolgens 1 zonder extra setupcalls. De eerder gevolgde [interruptloop](wave-dma-contracts.md) heeft in zijn lokale code geen shutdown-exit; een werkelijk veilige unload vraagt daarom aanvullend bewijs van driver-manager-/thread-/hardwaregedrag. Dit rapport stelt niet dat die thread op de unit na iedere deinit daadwerkelijk blijft draaien.

## Reparatievereisten en lokaal vervolg

Init moet failures van DMA-channelallocatie/init en interruptconnect/initialize doorgeven vóór verdere pointergebruik/setup, met gecontroleerde unwind van wat reeds bestaat. De global moet een expliciete init-/failed-/closing-status hebben en retry mag alleen succes geven voor een geldige, volledig geïnitialiseerde state. Deinit moet teardown, thread-/callbackafhandeling, DMA/hardwareownership, paired releases en global-reset coherent uitvoeren; alleen extra frees toevoegen is niet veilig terwijl een thread of DMA nog bezit heeft.

Deze voorwaarden staan in het [gecombineerde reparatieplan](update-repair-plan.md). Nog open: de echte constructors/PSCsetup/finalizer, alle power-/device-managercallers, interruptconnect/kernel/unload, shutdownprotocol, mixer/renderownership en unitmetingen. De oorspronkelijke negatieve codepaden zijn bewezen; de native reparaties zijn nog niet in MAX01 geïmplementeerd.
