# Audio-DMA: twee primingcalls, fragmentgroottes en descriptorgrenzen

Na de [OEM-streamqueue](wave-stream-contracts.md) is nu ook de outputstart-/pumpcontrolflow met oorspronkelijke instructies gecontroleerd. I2S biedt de mixer een venster van **4096 bytes** per pump; I2S2 **256 bytes**. De starthelper probeert tweemaal te pumpen voordat hij hardwarestart aanvraagt. Die twee calls zijn geen bewijs dat beide buffers vol zijn, geen algemene twee-buffer-prefilleis en geen gemeten hoorbare latency.

`py tools/inspect_wave_dma.py` bewaart [28 oorspronkelijke codebereiken en 130 primingtraces](firmware/wave-dma/contracts.json) en [de oorspronkelijke assembly](firmware/wave-dma/reviewed-paths.asm). De start-, pump- en kanaalwrapperinstructies worden begrensd geïnterpreteerd; mixer/render, HAL-nextbuffer, HAL-activation en hardwarestart zijn fixtures. HAL-init/getnext/activate/start/stop/diagnosticdump en de interruptloop zijn statisch gelezen en gepind, **niet** hardware- of schedulergeëmuleerd. MAX01, de oorspronkelijke modules en de unit zijn niet gewijzigd.

## Bronnen

| Module | SHA-256 |
| --- | --- |
| ROM wavedev2_i2s.dll | `fec5ab038cf274c4cf74a6553f9a81328bba7100c8ec9b17438658a7fae9d67c` |
| ROM wavedev2_i2s2.dll | `eb9b1d5625e0be967f139a4fe1d3e67799bd71d0af1e5bdf7c55b6d1f347a009` |
| ROM ceddk.dll | `9db6404163f5280080d8bfe50b1f7d413de189de0536e7dd79b403f1cab50731` |
| ROM k.ceddk.dll | `ccbbe9983bca33cb3d2b548fda266168fb6c3164039a5f9a82417aa9398b2aff` |

De producer verifieert deze hashes en bewaart ook producer-, interpreter-, queuehelper- en streamhelperhashes. De zes HAL-codebereiken worden in user- en kernel-DDK elk op hun eigen adressen gepind; automatische naamgelijkheid vervangt geen vergelijking met de oorspronkelijke bytes.

## Output-pump en start

| Pad | I2S | I2S2 |
| --- | --- | --- |
| Outputstart | c0947e50 | c0957f4c |
| Outputpump | c094791c | c0957a18 |
| Streammixer | c0942ae0 | c0952b48 |
| Get-next-buffer-wrapper | c0948554 | c0958608 |
| Activation-wrapper | c09485a0 | c0958654 |
| Hardwarestart-wrapper | c0948440 | c095852c |
| Interruptloop | c0947a28 | c0957b24 |
| DMA-init-wrapper | c09483c0 | c09584ac |

Outputstart gebruikt device +84 als active-vlag. Als die al gezet is, retourneert hij 1 zonder nieuwe pump. Anders zet hij active, voert **twee pumps** uit en telt hun rendered-byte-returns op. Alleen wanneer de som nul is, wist hij active weer. Bij een nonzero som roept hij hardwarestart met richting 2 aan. Zijn eigen return is altijd 1 in deze gevolgde helper.

Een pump vraagt HAL om de volgende buffer voor het outputkanaal. Hij geeft de mixer startpointer, start+4096 (I2S) of start+256 (I2S2) en een zero-init bookkeepingrecord. De mixer doorloopt geregistreerde streamobjects, houdt tijdelijke streamreferenties vast, roept hun render-slot +1c aan en bewaart de grootste eindpointer. Zo ontstaat de daadwerkelijk gevulde lengte, niet noodzakelijk de volledige quantum. De pump activeert alleen een nonzero rendered bereik en retourneert die rendered lengte.

De 130 begrensde cases bestaan uit, voor beide DLLs, twee rendered lengtes uit 0/4/halfquantum/fullquantum, geïnjecteerde activate-return 0/1, geïnjecteerde hardwarestart-return 0/1, plus het al-actieve geval. Ze bevestigen:

- Beide pumps worden geprobeerd, ook wanneer de eerste nul bytes levert.
- Eén gedeeltelijk gevuld blok is al voldoende voor een hardwarestartaanvraag.
- Twee lege pumps laten active nul, terwijl de helper toch 1 retourneert.
- De activation-return verandert de pump-byte-return niet. De hardwarestart-return verandert de outer succesreturn/active-vlag niet.

De FALSE-returns zijn **API-foutinjecties** om lokale returnafhandeling te onderzoeken. In de hieronder gevolgde lokale HAL retourneert activation bij een geldige eigen buffer 1, en hardwarestart retourneert 1 na registerwrites. Dit model bewijst geen normaal bereikbare FALSE-activation, geen stilvallende DMA op Max' unit en geen hoorbare fout. Ook de definitieve mixer-/devicekeuze voor Blue blijft open.

## Hoeveel PCM vertegenwoordigen twee volle fragmenten?

Voor gewone stereo/16-bit destination-PCM is de rekenduur `bytes / (rate × 4)`. De fragmentgrootte komt uit de oorspronkelijke pumpinstructies; de samplefrequenties hieronder zijn scenario's uit de eerder gevolgde ratehelpers.

| Driver/rate-scenario | Eén vol fragment | Twee volle fragmenten |
| --- | ---: | ---: |
| I2S, 44.100 Hz | 23,22 ms | 46,44 ms |
| I2S, 48.000 Hz | 21,33 ms | 42,67 ms |
| I2S2, 8000 Hz | 8,00 ms | 16,00 ms |

Dit zijn PCM-duren, geen stopwatchmeting en geen gegarandeerde hoeveelheid vooraf gequeued audio. Eerste/laatste fragments kunnen gedeeltelijk gevuld zijn. Hardware-FIFO, seriële samplepacking, extra mixerbuffers, resampling, transport, scheduler en telefoonbuffers zijn niet in die getallen verwerkt. Ze mogen niet bij elkaar opgeteld worden alsof daarmee Max' totale A/V-delay gemeten is.

De [Blue-elf-bufferreserve](bt-playback-contracts.md) vertegenwoordigt in de eerder gecontroleerde stereo/44.1-kHz-cases ongeveer 1,31..1,53 seconde PCM. In deze specifieke fragment-scenario's is DMA-priming een veel kleinere statische laag. Dat ondersteunt Blue-startbuffering als belangrijk reparatiepunt; het bewijst niet dat de feitelijke wachttijd uitsluitend daar ontstaat.

## De lokale HAL heeft twee buffer-/descriptorparen

User-DDK `HalInitDmaChannel 40233a2c` configureert twee PCM-regio's op channel +28/+2c, met de tweede op base+fragmentlengte. Het descriptorblok heeft 128 bytes met descriptors op +40/+44 van het channelobject, 64 bytes uit elkaar; fysieke descriptoradressen staan op +48/+50. De descriptorlinks wijzen naar elkaar. Die twee lokale regio's sluiten aan bij de twee startup-pumpcalls, maar volledige hardwareownership/overrunprecondities zijn nog niet begrensd gemodelleerd.

Driver-DMA-init gebruikt selector 12/13 voor I2S output/input, of 18/19 voor I2S2. De buffersizes komen uit de eerder initgezette drivercontextvelden, 4096 of 256. De wrapper test of channelallocatie nonzero is, maar gebruikt de afzonderlijke `HalInitDmaChannel`-return niet om te stoppen. De volledige allocatie-/registerfoutafhandeling moet verder worden onderzocht.

`HalGetNextDMABuffer 40233c98` gebruikt actieve descriptoridentiteit, registerstatus en descriptorbit 31 om één van de twee eigen buffers te kiezen. Voor UART/SPI gebruikt hij een live registerpointer; voor de gewone overige selectors het cached veld +84. Hij wist de bijbehorende softwaremarkering +58/+5c vóór teruggeven. Een onbekende descriptoridentiteit leidt naar log en diagnostic-dumphelper `40233994` en een bufferfallback; die helper print channel/descriptor-/bufferregisters, zonder een reset te bewijzen. Deze selector- en registerbranches zijn statisch gevolgd; de fysieke betekenis en alle tegelijk-actieve-descriptorgevallen blijven te toetsen.

`HalActivateDMABuffer 40233e68` accepteert uitsluitend een adres gelijk aan channel +28 of +2c. Bij een ander adres logt hij en retourneert nul. Bij een geldig adres kiest hij de bijbehorende descriptor, zet +58 of +5c op 1, schrijft de lengte naar descriptor +4, zet descriptorbit 31 en schrijft 1 naar kanaalregister +0c. Hij retourneert 1 zonder aparte MMIO-foutreturn. Dit koppelt de driver-pump-bytecount aan een daadwerkelijke lokale descriptorlength; het model heeft die registerwrites nog niet uitgevoerd.

`HalStartDMA 40233f24` schrijft kanaalregisters, zet bit 0 van control, gebruikt CacheSync(4) en doet een verdere registerwrite. Daarna geeft hij 1 terug. Hardwarestart-wrapper I2S schrijft eerst PSC-register +10 met 1 en vraagt **Sleep(1)** vóór HalStartDMA; I2S2 heeft in die outputbranch geen Sleep-call. Een gevraagde Sleep(1) is hier een statisch API-verzoek, geen gemeten één milliseconde fysiek tijdsverschil.

De corresponderende kernel-DDK-functies zijn `c0423a2c`, `c0423c98`, `c0423e68`, `c0423f24`; hun oorspronkelijke bytes zijn afzonderlijk opgenomen. Er is geen native gebruik van deze helpers, MMIO of DMA.

## Interrupt, underrun en stop

Beide driverinterruptloops doen InterruptDone → onbeperkte eventwait → EnterCriticalSection op device +4 → HAL-interruptcheck/ack → pump → eventuele stop → LeaveCriticalSection. Daarmee gebruikt deze render-/pumpcaller dezelfde device-critical-section als de eerder gevolgde wave-IOCTL-dispatcher. Dit voltooit niet alle power-/callback-/interruptlocks en races.

Bij een outputinterrupt waarvan de nieuwe pump nul bytes levert en active nog gezet is, vraagt de loop DMA-stop aan en wist active. De twee startupcalls en de interrupt-pump zijn dus verschillende schedulingfasen. De loops testen de eventwait-return niet als aparte exit/failure; ze hebben in dit gevolgde bereik geen normale shutdownbranch.

`HalStopDMA 40233f84` wist de control-enablebit en **pollt register +14 totdat de waarde nonzero is**, zonder lokale deadline in dat bereik. Daarna wist hij descriptorbit 31 en softwaremarkeringen voor beide regio's en bewaart hij opnieuw de actuele descriptorpointer. De kernelvariant `c0423f84` heeft hetzelfde gevolgde pad. Een echte stuck-register-/deadlockconditie of apparaatimpact is niet bewezen; lokale bounded MMIO-returnfixtures en alle stopcallers moeten nog worden uitgewerkt.

## Verder onderzoek en reparatiegrenzen

Het [DDMA-HAL-vervolg](dma-hal-contracts.md) interpreteert inmiddels de oorspronkelijke getnext/activate/IRQ/ack/stop/allocatie/cleanupinstructies met expliciete descriptor-/registerfixtures. Het [mappingvervolg](dma-mapping-contracts.md) koppelt mapper/unmap en herhaalde channelalloc/free. Het [driverlifetimevervolg](wave-lifetime-contracts.md) interpreteert buitenste init/deinit/retry en interruptsetup. De beperkingen hierboven beschrijven het bereik van deze oorspronkelijke pump-producer; de nieuwe producers bewaren afzonderlijke evidence. Nog open: volledige kernel-/driverlifetime, de renderer/interpolatiekernels koppelen aan werkelijke bufferconsumptie, WAM-softwaremixerselectie en Blue's concrete device-ID.

Een drivercompletion bewijst nog steeds headerteruggave vóór verwerking door Blue, en geen fysiek einde van audio. Een latency-/shutdownreparatie moet daarom de bewezen Blue-boekhoudfouten en callbackownership oplossen zonder de voorbereide-capaciteits-, driverlist- en DMA-grenzen te vermengen. De huidige [gecombineerde onderzoeksbuild](review-update-contracts.md) blijft een offline kandidaat, geen gevalideerde volledige firmwarefix.
