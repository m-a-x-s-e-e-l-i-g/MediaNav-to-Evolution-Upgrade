# DDMA-HAL: runtimeconfig, descriptorovergangen en allocatie/cleanupfouten

De verdere analyse interpreteert nu de oorspronkelijke DMA-config-, select-, activate-, IRQ-, ack-, stop-, allocatie- en cleanupinstructies in **zowel ceddk.dll als k.ceddk.dll**. Zij bevestigt twee concrete geheugenbeheerproblemen: fysieke allocatieresultaten worden vóór descriptorprogrammering niet gecontroleerd, en channelcleanup geeft het tweede PCM-deeladres vrij terwijl de afzonderlijke descriptorallocatie niet wordt aangeboden. Daarnaast zijn een unchecked mappingstore, genegeerde mutexwait-return, signed-selectorgrens en een stoplus zonder lokale deadline gevolgd.

Dit zijn lokale code-/ABI-bevindingen met expliciete fout-/registerfixtures. Ze bewijzen geen gemeten geheugenlek, OOM, vastgelopen DMA of oorzaak van Bluetoothlatency op Max' unit. De oorspronkelijke firmware en MAX01 blijven ongewijzigd; er is geen firmware, MMIO of DMA native uitgevoerd.

`py tools/inspect_dma_hal.py` bewaart [27 oorspronkelijke codebereiken en instructietraces](firmware/dma-hal/contracts.json) en [de oorspronkelijke assembly](firmware/dma-hal/reviewed-paths.asm). Onbekende instructies/calls en code buiten de gekozen grenzen stoppen het model. De kleine MIPS-interpreter is uitgebreid met signed SLT/SLTI en SRL binnen deze tool. OS-allocatie, mutex/mapping, registerreads/-writes en cachecalls zijn fixtures. Bij een door allocatiefailure veroorzaakt laag virtueel target stopt het model op de **eerste poging**; het presenteert vervolg na een mogelijke fault niet als succesvol firmwaregedrag.

## Bronnen en controles

| Module | SHA-256 |
| --- | --- |
| ROM ceddk.dll | `9db6404163f5280080d8bfe50b1f7d413de189de0536e7dd79b403f1cab50731` |
| ROM k.ceddk.dll | `ccbbe9983bca33cb3d2b548fda266168fb6c3164039a5f9a82417aa9398b2aff` |
| ROM coredll.dll | `1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c` |
| ROM wavedev2_i2s.dll | `fec5ab038cf274c4cf74a6553f9a81328bba7100c8ec9b17438658a7fae9d67c` |
| ROM wavedev2_i2s2.dll | `eb9b1d5625e0be967f139a4fe1d3e67799bd71d0af1e5bdf7c55b6d1f347a009` |

| Controle met oorspronkelijke instructies | Aantal |
| --- | ---: |
| Runtimeconfig-initializers | 2 |
| Bufferkeuze: selector/cached/live/status/beide descriptorbits | 576 |
| Activation: bufferidentiteit/lengte/bestaande bit 31 | 72 |
| IRQ-check: status/descriptorbits/softwaremarkeringen | 144 |
| Ack: reden/cached descriptor | 30 |
| Stop: finite statusseries / blijvend nul | 10 |
| Init: selectors −1..25, twee quantums en beide allocatiefouten | 432 |
| Channel-free: quantum/mutexwait-return | 16 |
| Channelallocatie: bezet/heap-/mutex-/mapping-/waitfout | 16 |
| Twee audio-DMA-initwrappers met allocatie-/initreturns | 24 |
| Prime→activate→getnext→IRQ/ack→getnext | 2 |
| FreePhysMem en VirtualFree: identieke release-syscall | 2 |

De artifacthashes pinnen producer, gedeelde interpreter, queuehelper en DMA-helper. Begrensde interpretatie van oorspronkelijke instructies is geen emulatie van fysieke hardware of de volledige kernel.

## De bestandstabel is leeg; runtimecode vult hem

Confighelper `4023326c` / `c042326c` vult de 25×32-byte tabel op `4023813c` / `c042813c`. Die tabel is in de gereconstrueerde PE **nul**. Rechtstreeks die bestandsdata als runtimeconfig gebruiken zou onterecht alle selectors ongeldig verklaren. De tool interpreteert daarom eerst de oorspronkelijke initialisatie-instructies en mockt alleen de afsluitende mappingcall.

Na die initialisatie zijn selectors **0, 1, 4, 5, 12, 13, 14, 15, 18, 19, 20, 21, 23, 24** enabled. De oorspronkelijke writes koppelen:

| Selectors | Runtime-labels | FIFO-adres |
| --- | --- | --- |
| 0/1 | UART0 TX/RX | 10100004 / 10100000 |
| 4/5 | AC97 TX/RX | 10a0101c |
| 12/13 | I2S TX/RX | 10a0201c |
| 14/15 | SDIO0 TX/RX | 10600000 / 10600004 |
| 18/19 | I2S2 TX/RX | 10a0001c |
| 20/21 | IDE TX/RX | 18800000 |
| 23/24 | NAND TX/RX | 20000020 / 20000000 |

De I2S-selectors passen daarmee bij de eerder bewezen [PSC-/driverketen](wave-driver-contracts.md). Dit koppelt lokale softwareconfig aan geprogrammeerde adressen, zonder elektrische codec-/Bluetoothbedrading of actuele unitdevice-ID's te bewijzen. De UART/SPI-stringidentiteitsbranches in getnext zijn ook gevolgd; SPI-labels worden door deze gevolgde initializer niet als enabled tabelrij gevuld.

De confighelper vraagt mapping van `14002000`, lengte `1010`, en bewaart de return op een global. In de return-delay-slot schrijft hij vervolgens **7 naar mapping+1000 zonder nullcheck**. Met een geïnjecteerde mappingreturn nul stopt de instructiefixture op target **1000**. Wat een echte unit bij zo'n low-addressstore doet en hoe vaak die mapping faalt, is niet vastgesteld. Het [mappingvervolg](dma-mapping-contracts.md) interpreteert nu de oorspronkelijke mapper en gekoppelde herhaalde allocator/free-calls; kernel-/modulelifetime blijft open.

## Getnext geeft een geselecteerde regio, geen exclusieve ownershipgarantie

`HalGetNextDMABuffer 40233c98` / `c0423c98` kiest alleen buffer A (+28) of B (+2c). Hij gebruikt cached descriptor +84, behalve voor de vier exacte UART0/SPI-labelpointers, waar register +4 leidend is. Een onbekende descriptoridentiteit leidt naar log/diagnosticdump en buffer A. Het gekozen softwareveld +58/+5c wordt nul, ook wanneer de bijbehorende descriptorbit 31 nog gezet is.

Voor een bekende current descriptor bepaalt statusbit 0 samen met de tabelrichtingswaarde +18 en beide descriptorbits de keuze. Alle 576 combinaties controleren die originele branches voor UART0 TX/RX en I2S TX/RX, inclusief een cached/live mismatch en onbekende identiteit. Geen van deze getnext-slices wacht tot beide descriptorbits een vrije regio aantonen.

De sequentietrace begint met lege descriptorbits, current=A en de opgegeven statusfixture:

1. Getnext geeft A; activate zet A-bit 31 en zijn softwaremarkering.
2. Getnext geeft B; activate zet B-bit 31 en zijn softwaremarkering.
3. Zonder hardware-/descriptoradvance geeft een **derde getnext opnieuw B**, met B-bit 31 nog gezet.
4. De fixture wist A-bit 31 en zet de status naar de IRQ-checkfase. Check geeft 1, ack verplaatst cached current naar B, en getnext kiest A.

De echte startupcaller uit het [DMA-vervolg](wave-dma-contracts.md) pumpt tweemaal; een derde ongeconditioneerde call is hier een API-preconditiewitness, geen bewezen normale driveroverwrite. Dit laat zien waarom getnextreturn, softwaremarkering, hardwarestatus en ack samen moeten worden beoordeeld. Bit 31 is hier de door activation gebruikte descriptorbit; fysieke transactie-/hardwaretijden worden niet ingevuld door de fixture.

## Activation en IRQ-status zijn aparte stappen

`HalActivateDMABuffer 40233e68` / `c0423e68` weigert een adres dat niet precies A of B is. Voor een geldig adres schrijft hij de opgegeven lengte, zet descriptorbit 31, zet softwaremarkering 1 en schrijft de kanaal-doorbell. De 72 cases bevestigen dat de routine **geen eigen capaciteitcheck** gebruikt: ook 4097/ffffffff worden bij een geldig bufferadres als lengte geschreven. Een al gezette descriptorbit blokkeert evenmin activation.

Dat is een lokaal low-level callercontract, geen bewijs dat de normale audio-pump te lange DMA-transfers aanbiedt. Die biedt volgens de gevolgde mixer-/pumpgrens maximaal 4096 of 256 bytes aan. Een eventuele DMA-reparatie mag die upstream grenzen en descriptorstatus niet vervangen door de aanname dat activation zelf alles valideert.

`HalCheckForDMAInterrupt 40234058` / `c0424058` geeft nul wanneer statusbit 0 gezet is. Anders rapporteert hij een descriptor uitsluitend wanneer **softwaremarkering precies 1** en descriptorbit 31 nul zijn. Descriptor A geeft bit 1, B bit 2; beide geven 3. Markering 0 of 2 levert op zichzelf geen nieuw completionbit. De 144 cases controleren alle drie softwarewaarden en beide descriptorbits.

`HalAckDMAInterrupt 402340fc` / `c04240fc` is een 88-byte leaf. Reden 1 zet marker A=2 en cached current=B. Reden 2 zet marker B=2 en cached current=A. Reden 3 en andere waarden toggelen alleen cached current; ze zetten niet beide markeringen 2. De 30 cases bewaren die concrete controlflow. De driver geeft de checkreturn door naar deze ackhelper; alle dubbele-completion- en render-interleavings blijven verder te volgen.

## Fysieke allocaties worden vóór programmering niet gecontroleerd

`HalInitDmaChannel 40233a2c` / `c0423a2c` vraagt twee fysieke allocaties:

- Eén PCM-blok van **2×quantum**, waarvan A de base is en B=base+quantum.
- Eén descriptorblok van **128 bytes**, waarvan descriptor A de base is en B=base+64.

Na beide calls gebruikt hij de returns en fysieke outputvelden zonder een failurebranch. De 432 cases combineren alle selectors −1..25, quantums 256/4096 en afzonderlijke/both allocatiefailures:

| Geïnjecteerde fout bij een valid audioselector | Bewezen vervolg |
| --- | --- |
| PCM-allocatie retourneert nul; descriptorallocatie slaagt | Buffer A=0, B=quantum; de descriptors krijgen ongeldige/unowned fysieke PCM-outputwaarden uit deze fixture; helper retourneert **1** |
| Descriptorallocatie retourneert nul | De eerste descriptor-portwrite richt zich op **08** (RX) of **10** (TX); fixture stopt daar |
| Beide allocaties mislukken | Zelfde eerste low-descriptorwrite; geen claim dat de echte firmware daarna doorloopt |

De PCM-failurecase heeft geen verborgen native DMA-transactie: registerwrites worden alleen vastgelegd. Dat de code een mislukt allocatieresultaat als bufferconfig gebruikt is bewezen; fysieke gevolgen en foutfrequentie zijn niet gemeten. Bij descriptorfailure blijft eventueel al verkregen PCM-geheugen in de fixture behouden tot de eerste low-targetpoging; er is geen lokale voorafgaande unwind.

De selectorcheck is **signed SLTI(selector,25)** zonder ondergrens. Selector **−1** passeert daarom en indexeert 32 bytes vóór de tabel. De oorspronkelijke voorafgaande bytes bevatten niet-nuldata, die als enabled config wordt geaccepteerd. Dit is met beide oorspronkelijke modules gereproduceerd. De normale I2S-wrappers geven vaste positieve selectors 12/13/18/19; er is geen bewijs dat de unit via die route −1 aanbiedt. Unsupported positieve selectors en selector 25 retourneren nul vóór allocatie.

## Channelallocatie negeert een mislukte mutexwait

`HalAllocateDMAChannel 402335d8` / `c04235d8` roept eerst de configinitializer aan, vraagt een zero-init 136-byte LocalAlloc-object, en zoekt maximaal 16 named mutexslots. Bestaande mutexhandles worden gesloten voordat het volgende slot wordt geprobeerd. Bij uitputting of createfailure volgt LocalFree en nulreturn.

Wanneer een slot is gevonden, wacht de routine onbeperkt op zijn mutex, maar **controleert de waitreturn niet**. Een geïnjecteerde WAIT_FAILED leidt nog steeds tot kanaalregisterberekening, een controlwrite en return van het channelobject. De 16 allocatiecases bevatten ook heapfailure, eerste/latere mutexfailure, 15 bezette slots, alle 16 bezet en mappingfailure. Dit bewijst de lokale returnafhandeling, niet dat een normaal geldig unitmutexhandle werkelijk faalt.

De confighelper wordt hierbij iedere aanroep opnieuw uitgevoerd. Het [mappingvervolg](dma-mapping-contracts.md) bevestigt nieuwe reservations en overschrijven van de global buiten channelcleanup. Volledige kernel-/modulelifetime blijft open. Dat is afzonderlijk van de PCM-/descriptorallocaties per channel.

## Cleanup gebruikt het verkeerde tweede adres

`HalFreeDMAChannel 40233778` / `c0423778` doet eerst een mutexwait met timeout nul en gaat alleen bij WAIT_OBJECT_0 verder. Dan wist hij channel-control en geeft, indien nonzero, achtereenvolgens **channel +28 en +2c** aan FreePhysMem. Daarna releaset/sluit hij de mutex en LocalFree't hij het channelobject. Hij biedt in deze routine **channel +40, de descriptorallocatiebase, niet aan**.

De twee oorspronkelijke allocaties waren PCM-base en descriptor-base; +2c is het tweede **deeladres binnen de eerste allocatie**. De 16 cleanupcases controleren de twee echte quantums en waitreturns 0/102/ffffffff/80. Alleen bij nul volgen de twee FreePhysMem-calls; nonzero waits laten de cleanup uitblijven. De returns van FreePhysMem worden niet gebruikt om de objectfree te stoppen of herstel te vragen.

De meegeleverde coredll maakt het ABI concreet: `FreePhysMem 4002afd0` gebruikt exact dezelfde syscall en argumenten als `VirtualFree 4002ae6c` met `(address,0,8000)`. Twee raw-instructietraces bevestigen dezelfde argumenten en returnpropagatie. Het [Microsoft CE VirtualFree-contract](https://learn.microsoft.com/en-us/previous-versions/ms913491(v=msdn.10)) vereist bij MEM_RELEASE de oorspronkelijke regio-base en size nul. De tweede halfbufferpointer voldoet niet aan die basevoorwaarde.

De cleanupfixture houdt twee oorspronkelijke allocatiebases bij: de eerste PCM-release slaagt, de tweede deeladresrelease faalt, en de descriptorallocatie blijft behouden terwijl het channelobject wordt verwijderd. Deze ledger modelleert de gedocumenteerde basevoorwaarde; de complete kernelreleasecode is nog niet geïnterpreteerd. **Verkeerd free-adres en ontbrekende descriptor-free zijn bewezen**, een unitgemeten lek of de frequentie van channel-destroy niet. De buitenste drivercleanup-/deinitcallers kunnen aanvullende paden hebben die nog gevolgd moeten worden.

## Beide audio-DMA-initwrappers negeren initreturns

`c09483c0` en `c09584ac` testen of output- en inputchannelallocatie nonzero zijn, maar gebruiken de afzonderlijke HalInitDmaChannel-returns niet. Alle 24 wrappercases bevestigen dat twee verkregen channelobjecten tot return 1 leiden, ook bij geïnjecteerde initreturn nul. Mislukte tweede channelallocatie geeft return nul terwijl de eerste channelpointer opgeslagen blijft; dit lokale bereik heeft geen releasecall daarvoor. Het volledige buitenste init-/error-unwindpad is niet met deze wrappercases afgedekt.

De gewone selectors zijn geldig na de hiervoor bewezen runtimeinitialisatie. Een abstract geïnjecteerde initreturn nul is daarom geen bewijs van een normale positieve-selectorfailure op de unit. De unchecked fysieke allocaties en mapping zijn concrete verdere paden binnen de onderliggende initcode, die apart moeten worden gerepareerd en door de wrappers heen moeten worden afgehandeld.

## Stop heeft geen lokale deadline

`HalStopDMA 40233f84` / `c0423f84` wist control-enable en pollt register +14 tot het **nonzero** is. De tien traces gebruiken 0/1/4/32 nulreads gevolgd door 1, of blijvend nul. De finite cases stoppen en wissen beide descriptorbits/softwaremarkers. De blijvend-nulfixture bereikt alleen de **externe interpreterstaplimiet**, met descriptorbits en markeringen nog behouden. Dat is geen timeout die de firmware zelf afhandelt.

De eerder gevolgde [audio-interruptloop](wave-dma-contracts.md) kan DMA-stop aanroepen terwijl de driver-device-critical-section vastgehouden wordt. Een register dat op de echte unit blijvend nul is, zou dit pad daarom kunnen vasthouden; de werkelijke hardwarepreconditie/incidentie en alle andere stopcallers zijn nog niet vastgesteld. De modellen meten geen CPU-/wall-clockdeadline en doen geen echte portreads.

## Vervolg en reparatievereisten

Nieuwe bewezen reparatiepunten zijn: mapping-/fysieke allocatiereturns vóór pointergebruik valideren, volledige unwind van gedeeltelijke allocatie, cleanup van **PCM-base én descriptor-base**, propagatie door audio-initwrappers en controle van mutexwait. Signed-selectorbounds moeten het expliciete lokale 0..24-contract volgen. Een stopdeadline/aanpak vereist eerst hardware-/outer-lock-/recoveryprecondities; blind descriptorownership wissen bij een nog actieve DMA is geen bewezen veilige oplossing.

Het [mappingvervolg](dma-mapping-contracts.md) voegt oorspronkelijke mapper/unmapinstructies en herhaalde allocator/free-traces toe. Het [driverlifetimevervolg](wave-lifetime-contracts.md) koppelt buitenste init/deinit/retry en interruptsetup. Lokaal vervolgwerk blijft volledige kernelrelease-/allocation-/unloadpaden, driver-/stopownership, dubbele IRQ/ackvolgorde, render/DMA-koppeling, concrete WAM-mixerselectie en unitmetingen. Het [gecombineerde reparatieplan](update-repair-plan.md) neemt deze driver-/DDK-bevindingen mee; ze zitten nog niet in de huidige MAX01-LGU.
