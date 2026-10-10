# DDMA-mapping: allocatie, failure-unwind en herhaalde kanaalallocatie

De oorspronkelijke mapper is nu in beide DDK-varianten begrensd geïnterpreteerd en aan de DMA-configinitializer/channelallocator gekoppeld. Iedere kanaalallocatie vraagt opnieuw een virtuele mapping van dezelfde registerregio. De allocator overschrijft daarbij de global met de nieuwste pointer; channel-free bevat geen bijbehorende unmap. Zelfs een daaropvolgende mislukte LocalAlloc laat de reeds verkregen mapping behouden in de fixture.

Dit is een bewezen lokaal resourcecontract. De bijgehouden virtuele reservations zijn OS-fixtures, geen gemeten unitgeheugenlek of incidentfrequentie. Een mapping reserveert adresruimte en mapmetadata; deze analyse stelt niet dat iedere mapping nieuwe fysieke registerpagina's of PCM-geheugen alloceert. Process-/module-unload, kernelgeheugenbeheer en de volledige driverdeinitketen blijven verder te volgen.

`py tools/inspect_dma_mapping.py` bewaart [11 oorspronkelijke codebereiken en alle traces](firmware/dma-mapping/contracts.json) plus [assembly](firmware/dma-mapping/reviewed-paths.asm). De tool interpreteert oorspronkelijke MIPS-instructies met delay slots en voegt alleen NOR aan de eerdere begrensde interpreter toe. VirtualAlloc, VirtualCopy, VirtualFree, pagesize, mutexen en portcalls zijn expliciete fixtures. Originele binaries, MAX01 en de unit blijven ongewijzigd.

## Bronnen en controlebereik

De oorspronkelijke hashes zijn identiek aan de [DDMA-HAL-bronnen](dma-hal-contracts.md): ceddk.dll `9db6404163f5280080d8bfe50b1f7d413de189de0536e7dd79b403f1cab50731`, k.ceddk.dll `ccbbe9983bca33cb3d2b548fda266168fb6c3164039a5f9a82417aa9398b2aff` en coredll.dll `1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c`. Producer en vier interpreter/helper-dependencies zijn afzonderlijk gehasht.

| Oorspronkelijke instructietraces | Aantal |
| --- | ---: |
| Mapper: pagesize/phys-low/phys-high/length/cache/alloc-/copy-/release-uitkomst | 3600 |
| Unmap: pagesize/pointeroffset/release-uitkomst | 40 |
| Config → mapper → channelalloc → channel-free, inclusief fouten | 14 |

Pagesizes 4096/65536 zijn fixtures; de tool meet de actuele unitwaarde niet. De synthetische nul-/overflow-/phys-high-cases toetsen de gevormde API-argumenten. Een succesvol gemockte OS-call bij zo'n randcase bewijst geen OS-acceptatie van dat verzoek.

## MmMapIoSpace rondt af en geeft de oorspronkelijke offset terug

`40232360` / `c0422360`, 228 bytes, leest pagesize uit adres `5b04`. Voor 32-bit low en high van het fysieke adres voert hij uit:

1. Aligned low = low AND NOT(page−1); offset = low−aligned low.
2. Mappingsize = (page+offset+requested−1) AND NOT(page−1), met oorspronkelijke 32-bit arithmetic.
3. VirtualAlloc(0, mappingsize, 2000, 1).
4. Bij nonzero reserve-resultaat: VirtualCopy(base, (high<<24) OR (aligned low>>8), mappingsize, cache?404:604).
5. Bij copy-success: return base+offset. Bij copy-failure: VirtualFree(base,0,8000), vervolgens return nul ongeacht de releasereturn.

Een mislukte VirtualAlloc leidt direct naar nulreturn zonder VirtualCopy/VirtualFree. Mislukte VirtualCopy probeert de oorspronkelijke reservation-base vrij te geven. Als de geïnjecteerde release faalt, verdwijnt die fout uit de mapperreturn en blijft de reservation behouden in de fixture. Er is geen lokale overflow-/nulgrootte-/phys-high-validatie vóór deze API-calls; geldigheid van echte callers en OS-precondities moet afzonderlijk worden vastgesteld.

Voor de echte gevolgde DDMA-configargumenten `14002000, high=0, bytes=1010, cache=0` produceert een **4096-byte pagesizefixture** een reservation van `2000` bytes, source `140020` en flags `604`. Twee verschillende mappingreturns vertegenwoordigen dus twee virtuele views van dezelfde fysieke regio.

## MmUnmapIoSpace release't de page-aligned base

`40232444` / `c0422444`, 52 bytes, maskeert de lage pagesizebits van de pointer en roept VirtualFree(aligned pointer,0,8000) aan. Het tweede argument, dat callers als lengte meegeven, beïnvloedt dit bereik niet. Alle veertig cases controleren de exacte calls; een geïnjecteerde releasefailure wordt niet gelogd of hersteld binnen dit bereik.

Dit sluit aan op de [eerder gevolgde FreePhysMem/VirtualFree-ABI](dma-hal-contracts.md). Het laat ook zien dat een willekeurig deeladres door deze unmap niet vanzelf in de oorspronkelijke reservation-base verandert: alleen de lage **page**-offset wordt gewist. De fixture gebruikt voor de unmapcases expliciet een bijpassende reservation-base; zij bewijst geen release van een andere gereserveerde regio.

## Configinitializer maakt bij elke kanaalallocatie een nieuwe mapping

`HalAllocateDMAChannel 402335d8` / `c04235d8` roept onvoorwaardelijk config `4023326c` / `c042326c` aan. Die config roept de hiervoor geïnterpreteerde mapper aan en bewaart de return op global `4023845c` / `c042845c`. Daarna schrijft de return-delay-slot 7 naar pointer+1000. Er is geen bestaande-mappingcheck of unmap vóór overschrijven in deze keten.

De gekoppelde traces gebruiken achtereenvolgens 1, 2 of 16 succesvolle channelallocaties en geven daarna alle verkregen **nog niet fysiek geïnitialiseerde** channelobjecten via de oorspronkelijke HalFreeDMAChannel vrij. LocalAlloc geeft verschillende zero-init dummyobjects terug; mutexwait/portcalls zijn fixtures. Na iedere allocator/free-sequentie blijven respectievelijk 1, 2 of 16 mappingreservations in de fixture behouden. Channel-free doet geen VirtualFree/MmUnmapIoSpace voor deze global. De laatste pointer blijft in de global; de eerdere pointers worden daar overschreven.

Een aparte heapfailurecase laat eerst een succesvolle registermapping zien, daarna LocalAlloc-return nul en channelalloc-return nul. De mapping blijft behouden. Er is dus ook op dit lokale failurepad geen mapping-unwind. Dit volgt de volgorde van de oorspronkelijke instructies, geen aangenomen failurepad.

Bij de tweede mappercall zijn daarnaast drie foutcases gevolgd:

| Geïnjecteerde fout | Bewezen lokale keten |
| --- | --- |
| Tweede VirtualAlloc faalt | Mapper geeft nul; configglobal wordt nul; eerste nieuwe poging is store naar `1000`; eerdere mapping blijft behouden |
| Tweede VirtualCopy faalt, VirtualFree slaagt | Tweede reservation wordt vrijgegeven; configglobal nul; eerste storepoging naar `1000`; eerste mapping blijft behouden |
| Tweede VirtualCopy faalt, VirtualFree faalt | Beide reservations behouden in fixture; configglobal nul; eerste storepoging naar `1000` |

De interpreter stopt op die eerste lage storepoging. Hij stelt niet dat de native unit daarna een channelobject retourneert. De eerdere, succesvolle channelallocatie wordt in deze fixture afzonderlijk vrijgegeven, zonder de eerdere registermapping te releasen.

## Gevolg voor de reparatie en vervolg

De mapping moet een expliciete levensduur krijgen: eenmaal per geschikte module/device-context met gecontroleerde initialisatie, óf een werkelijk gepaarde mapping/unmapping met ownership. Dat ontwerp moet user-/kernel-DDK-contexten, gelijktijdige callers, unload en hardwaregebruik volgen; een onbeveiligde nonzero-globalcheck alleen is onvoldoende onder concurrency. Iedere failure moet vóór de configstore stoppen en gedeeltelijke reservations aantoonbaar opruimen of herstelbaar bijhouden. Een mislukte VirtualFree mag niet stil uit de foutboekhouding verdwijnen.

Deze punten worden opgenomen in het [gecombineerde reparatieplan](update-repair-plan.md). Het [driverlifetimevervolg](wave-lifetime-contracts.md) volgt inmiddels buitenste init/deinit/retry en interruptsetup. Nog open: kernel VirtualAlloc/Copy/Free-implementatie, module-/process-unload, volledig audio-driverownership, alle DMA-callers en concurrente initializergebruikers. Geen van deze nieuwe fixes is geïntegreerd in MAX01 of op de unit getest.
