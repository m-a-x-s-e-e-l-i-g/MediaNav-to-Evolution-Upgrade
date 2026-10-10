# Bluetooth-transportkeuze, pakketownership en cleanup

Vervolg: het [controllerantwoordonderzoek](bt-hci-completion-contracts.md) volgt inmiddels de geregistreerde RX-callback en oorspronkelijke mblk-/DM_HCI-/key-command-completionroute. Frameparsing, overige events, volledige profile-status en controller/unit blijven open.

Het vervolg koppelt de synthetische sleutelantwoorden aan **de oorspronkelijke transportobjecten en hun echte callbacks**. Het bestanddefault kiest BCSP; de onderzochte H4DS-variant wordt door selector zeven gekozen. Beide routes verwerken acht afzonderlijke HCI-commandopakketten. Twee oorspronkelijke cleanupfouten zijn gereproduceerd en in een afzonderlijke interpretervariant gerepareerd: H4DS kan de globale queuehead proberen te free'en, en BCSP kan payloads bij herhaalde cleanup opnieuw free'en.

Uitvoeren: `py tools/verify_bt_transport.py`. [Evidence](firmware/bt-transport/contracts.json) bewaart oorspronkelijke bytes en tabeldata, registraties, synthetische pakketten, write-/ACK-/free-traces, fouten, toolhashes en de [afzonderlijke cleanupvariant](../tools/draft_bt_transport_cleanup.py). Geen firmware is native uitgevoerd, geen executable/LGU is geschreven en `build_allowed` blijft false. Originele bestanden, de eerdere pairingvarianten en MAX02 zijn ongewijzigd.

## Oorspronkelijke keuze en registratie

Getter `83980` leest een halfword op `110e80`; de originele filebytes zijn `01 00`. Opstartroutine `244c8` kiest constructor `7cb40` bij één en `7e980` bij zeven, en schrijft die naar `21721c`. Schedulerregistratie `8a470` gebruikt deze pointer voor **CSR_TM_BLUECORE**, queueglobal `218644`, handler `eae48`.

Twaalf cases volgen de native opstart-/registratiebytes bij filedefault, één, zeven, nul, twee en `ff`, telkens met een vorige constructorpointer nul of `7cb40`. Andere selectorwaarden laten de vorige pointer staan. Dat toont geen automatische fallback of nieuwe transportinstantie; een cold-fixture kan zo initpointer nul registreren. De werkelijke commandline/config van de unit en alle parserbranches blijven open. Het filedefault is geen meting van de draaiende autoradio.

Beide constructors roepen `830f0` aan. Die maakt een TM-context van 52 bytes, voert oorspronkelijke init-leaf `8145c` uit en registreert via `e8fa8/83444` de ontvangcallback `e8f14` op objectoffset `10`. Het globale transportobject `2172b4` en TM-contextveld `20` krijgen dezelfde oorspronkelijke pointer:

| Object | BCSP `110e28` | H4DS `110e54` |
| --- | --- | --- |
| Start `00` | `7c9f4` | `7e7b8` |
| Stop `04` | `7ca24` | `7e870` |
| Readiness `08` | `24768`, retourneert één | `7e8a8` |
| Verzendcallback `0c` | `7ca5c` | `7e8b0` |
| Ontvangcallback `10` | Oorspronkelijk nul, native registratie zet `e8f14` | Idem |
| Extra callback `14` | `7ca88` | `7e8dc` |
| Overige callbackvelden | Bronbytes gepind, volledige semantiek open | Idem |

De proef vervangt de verzendcallback uit het eerdere sleutelstackrapport dus met de oorspronkelijke codepointer. Config-toepassing, achtergrond-/timerregistratie en de fysieke seriële write blijven expliciete fixtures. Dit is nog geen complete stackboot.

## BCSP: vier pakketten tegelijk, meer opgeslagen apparaten

Callback `7ca5c` linkt de 24-byte transmitdescriptor via native `829fc` aan FIFO-head `20e314` en roept `7d74c` aan. Dat geeft descriptorveld `+4` met channel/reliability `5/1` door aan `7ccb0`.

De reliable ring heeft acht sequenceposities en een **venster van vier onbevestigde berichten**: `(newest - oldest) & 7 < 4`. Elke entry gebruikt 24 bytes en bewaart de oorspronkelijke payloadpointer/lengte/offsetvelden. Een geaccepteerde descriptor wordt uit de buitenste FIFO gehaald en bevrijd; de payload blijft eigendom van de reliable ring tot ACK of afsluiten. Een vol venster laat de descriptor in de buitenste FIFO staan. Dit is transportbackpressure, geen pairingcapaciteit van vier.

24 traces gebruiken één/vier/acht/zestien records, sequence-start nul of zes, en origineel/iterator/cleanupvariant. De payloadbytes en de volgorde blijven exact gelijk aan de HCI-serializeruitvoer. Native `7d070` verwerkt een expliciet aangeleverde parsed-ACK-waarde op `218537`, schuift oldest door en roept `7dabc` aan om de bevestigde payloads te bevrijden. Daarna worden de wachtende descriptors opnieuw via de native pomp toegelaten. Acht/zestien berichten gaan in meerdere vensters door; sequencewrap is opgenomen. Een herhaald laatste ACK bevrijdt niets opnieuw.

De ACK-parser, echte wireframes/CRC, retransmit-/timeoutbeleid en fysieke ontvangst/schedulerinterleaving worden hier nog niet uitgevoerd. De proef mag niet als een volledige BCSP-implementatie of controllerauthenticatie worden gelezen.

## H4DS: commandotype, partial writes en zero-progress

Callback `7e8b0` → `7ee48` linkt commandodescriptors aan FIFO-head `218564` en activeert de achtergrondpomp via `7f230/80704`. Native `7ef18` haalt een descriptor uit de FIFO, zet hem als actief op context `218560+8` en verstuurt eerst één H4-typebyte `01`. Daarna verstuurt hij de oorspronkelijke commandobytes via sendboundary `805e4`.

48 traces bevatten positieve en negatieve HCI-antwoorden in drie varianten. De positieve matrix gebruikt één/acht records, volledige writes of maxima één/zeven bytes per call, en een aanvankelijke zero-progresscall of normale voortgang. Twaalf aanvullende negatieve traces gebruiken één/acht records met volledige/zeven-byte writes. Bij partial writes verhoogt native code descriptoroffset `+c`; er volgt geen tweede typebyte. Bij een geweigerde eerste write blijft de descriptor actief en wordt hij later met dezelfde bytes hervat. Zodra alle bytes zijn overgedragen, bevrijdt de oorspronkelijke code eerst de payload en dan de descriptor.

De samengevoegde bytes zijn voor ieder apparaat exact `01` plus het eerder geverifieerde HCI-pakket. Het aantal werkelijk geschreven bytes en de power-/backoffgrens zijn fixtures. Wire-timing, driver-I/O, overrunclaims en complete H4DS-powerhandshake blijven open.

## Twee oorspronkelijke cleanupfouten

H4DS-cleanup `7eb5c` roept, bij een niet-lege queue, `829d8` aan met `a0=&218564` en stack-outparameters. Die helper verwacht in zijn gevolgde body een objectpointer: hij leest `a0+14` en geeft `a0` zelf aan `85bb8` door. De concrete free-aanroep komt daardoor met **globaal adres `218564`** bij de allocatorboundary aan, terwijl dit geen gealloceerde descriptor is. De strict-heapfixture stopt op PC `829ec`. Bij een uitsluitend actieve descriptor en lege FIFO verloopt die eerste cleanup juist normaal; de fout is afhankelijk van de resterende queue.

BCSP-cleanup `7cbf4` bevrijdt alle reliable payloads tussen oldest en newest, maar schrijft de bijgehouden loopindex oorspronkelijk niet terug naar oldest `2174b8`. Een tweede cleanup volgt dezelfde slots en geeft een reeds bevrijde payload aan `7dabc/85bb8`; de witness staat op PC `7dac8`. De voorafgaande native timer-/link-stophelpers zijn nu ook geïnterpreteerd: die wissen hun timerhandles maar herstellen de ringindex niet.

Dit zijn concrete native callargs en ownershipfouten onder de opgegeven toestanden. Het exacte gedrag van de Windows CE-heap bij deze frees en de bereikbaarheid van iedere interleaving op de unit zijn niet gemeten.

## Afzonderlijke reparatie zonder nieuwe frames

De variant ligt bovenop de bestaande iteratorbasis, SHA `5b2d11baa5788e548b7cf0fb07fbfdf81f3d718de7c27680097577e106cc9ddd`, en maakt vier gepinde edits:

| Bereik | Wijziging |
| --- | --- |
| `7d6f4..7d72f` | De bestaande descriptor-drain neemt nu een queueheadpointer, unlinkt iedere descriptor en bevrijdt payload → descriptor; telt de verwijderde berichten |
| `7d6ac..7d6cb` | De enige geïnventariseerde directe BCSP-caller geeft head `20e314` expliciet door; behoudt daarna ringcleanup en stagingbuffer-free/clear |
| `7ebe8` | H4DS-caller gebruikt deze drain met zijn bestaande headargument in de ongewijzigde delay slot |
| `7cc50` | BCSP-ringcleanup schrijft de voortschrijdende oldest terug, inclusief de uiteindelijke lege toestand |

De drainproloog/epiloog, stackgrootte, saved-registerplaatsen en oorspronkelijke countreturn blijven behouden. Ook de callerframes en alle `.pdata`-bytes blijven gelijk; er komt geen nieuw uitvoerbaar bereik of code cave bij. De queue-drain heeft oorspronkelijk één directe caller (`7d674`), de verkeerde helpercall eveneens één (`7eb5c`). Deze direct-callinventaris is gepind; onbekende berekende/indirecte entry en concurrency zijn geen bewezen afwezigheid.

De nieuwe Blue-SHA is `542744d707d208b84c1cdba1cb3a61c7934864ff87d9ed18d53b02dcbb571b9a`. De bron-/basis-/uitkomstbytes en de assembled bodies staan in de evidence. De reparatie bestaat uitsluitend in interpretergeheugen.

## Controles en resterend werk

| Controle | Cases |
| --- | ---: |
| Selectie/registratie/constructors | Twaalf |
| BCSP reliable vensters/ACK/sequencewrap | 24 |
| H4 command-FIFO/bytes/partial write/stall | 48 |
| Cleanup/repeat, plus H4 actief met resterende queue | 36 |

De cleanupmatrix gebruikt nul/één/vier/acht/zestien pakketten, beide protocollen en drie varianten. De zes extra H4-cases sluiten na een partial write met één/acht apparaten af. Normale afgewerkte calls controleren stack en callee-saved registers. De gerepareerde variant bevrijdt alle toegewezen transmitpayloads/descriptors en heeft bij herhaalde cleanup geen duplicate free. Cacheobjecten, TM-context en DM-command/outstanding-objects vallen buiten deze transportcleanup.

Nog open: volledige commandline/start-/stopregistratie en serial driver, frame-/ACK-parser en retransmits, H4DS-power-/overruncases, echte command-completion/security-profiles, scheduler-/timer-/heap-lifetime en concurrency, fysieke controller/radio/boot, App-cachealiases en de gezamenlijke pairing-/playback-/navigatie-/updaterintegratie. De volledige onderzoeksdoelstelling blijft actief; deze voortgang is geen claim dat alle firmware nu begrepen of gerepareerd is.
