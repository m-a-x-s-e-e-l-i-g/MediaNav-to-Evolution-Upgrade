# Bluetooth-ontvangstframes: BCSP en H4 tot commandocleanup

Het onderbroken onderzoek is hervat op 8 oktober 2026. De oorspronkelijke BCSP- en H4-ontvangstcode is nu gekoppeld aan de geregistreerde RX-callback, mblk, DM_HCI-decoder en sleutelcommandocleanup. Geldige antwoorden voor acht opgeslagen adressen behouden hun inhoud en worden afgehandeld. Een korte HCI-eventbody kan echter **door beide oorspronkelijke frameparsers heen** de eerder gevonden decoderread buiten het ontvangen bereik bereiken.

Uitvoeren: `py tools/verify_bt_rx_frames.py`. [Evidence](firmware/bt-rx-frames/contracts.json) bewaart bronhash, oorspronkelijke functies/leaves/tabellen, parserinvoer, schedulerberichten, allocaties, recoverytraces en vastgezette foutuitkomsten. Native firmware wordt niet uitgevoerd. Er wordt geen executable of LGU geschreven; dit onderzoek verandert MAX02 niet.

## Scope en grensvoorwaarden

De proef interpreteert oorspronkelijke MIPS-instructies binnen bewaarde bereiken. Er zijn twee executablevarianten in interpretergeheugen: origineel en de eerder onderzochte [transportcleanupvariant](bt-transport-contracts.md). Dezelfde geldige RX-matrix en herstelcases worden op beide gecontroleerd. De dertien afzonderlijke foutprobes gebruiken de originele variant.

SC/CM/DM-sleutelantwoorden, transportregistratie, native frameparsers, geregistreerde ontvangcallback en commandocleanup zijn gekoppeld. De scheduler, file-/heap-API's en seriële readgrens zijn expliciete fixtures. BCSP begint met een gekozen verwachte sequence; H4 begint met een ready link. Boot, poweronderhandeling, interrupts, echte controller en radio worden niet nagebootst. De peer-ACK's waarmee de oorspronkelijke BCSP-TX-ring wordt leeggepompt zijn ingegeven fixtures; dit is geen volledige RX/TX-ACK- of retransmitproef.

Geheugengrensen gebruiken de aangevraagde heapgrootte. Windows CE-heapafronding of gevolgen van een fysieke overread zijn hiermee niet vastgesteld. Een faulttrace stopt op de eerste afwijking en geldt niet als een succesvolle ABI-return.

## Oorspronkelijke ontvangroutes

| Route | Behouden code | Gevolgd gedrag |
| --- | --- | --- |
| BCSP SLIP | `7e4d0`, leaves `7e0e8/7e138` | C0-framing, DB/DC- en DB/DD-escaping, fragmenten en begrensde decodebuffer |
| BCSP packet | `7e208` | Vierbyteheader, checksum, payloadlengte, optionele CRC en reliable sequence |
| CRC | `7e1d4`, tabel `10c62c` | Alle 256 tabelentries komen overeen met een onafhankelijke bitgewijze reflected-CRC-berekening |
| Transportdoorvoer | `83414` | Descriptor naar de daadwerkelijk geregistreerde callback `e8f14` |
| H4 serial RX | `7f598/7f39c`, RX-context `2185e0` | Packetindicator, headerlengte, dynamische payloadbuffer en gedeeltelijke reads |
| H4-doorvoer | `809f0/8079c/8139c`, leaves `7f950/80c34` | HCI-event naar dezelfde callback; ready-/powerstate zijn fixtures |
| Event en commandocleanup | [HCI-completionrapport](bt-hci-completion-contracts.md) | mblk, envelope `8007`, decoder en verwijdering van uitstaande sleutelcommando's |

De H4-RX-context verschilt van TX-context `218560`. De H4-fixture biedt eventindicator `04` aan en leest de HCI-lengthbyte. Dit sluit aan op het [UART-transportcontract van de Bluetooth SIG](https://www.bluetooth.com/wp-content/uploads/Files/Specification/HTML/Core-54/out/en/host-controller-interface/uart-transport-layer.html). De BCSP-proef gebruikt SLIP-escaping, een vierbyteheader en sequence modulo acht, vergeleken met de [Three-wire UART-beschrijving](https://www.bluetooth.com/wp-content/uploads/Files/Specification/HTML/Core-54/out/en/host-controller-interface/three-wire-uart-transport-layer.html). Deze nieuwere documentatie bevestigt formaatbegrippen; zij identificeert geen ondersteunde Core-versie of hardwarevariant van de unit.

## Geldige antwoorden en herstel

De **60 normale traces** bestaan uit 48 BCSP-cases en twaalf H4-cases: origineel/cleanupvariant, één/acht records, volledige/éénbyte/zevenbyte reads. BCSP controleert daarnaast CRC aan/uit en sequence-start nul/zes, inclusief wrap. De synthetische apparaatadressen bevatten C0 en DB om beide escapevormen door de oorspronkelijke parser te volgen.

Iedere trace controleert exact de ontvangen eventbytes, het aantal events, een lege uitstaande commandolijst en vrijgave van alle tijdens ontvangst aangevraagde heapallocaties. Normale calls controleren stack en callee-saved registers.

**30 hersteltraces** volgen dezelfde parserinstance na een fout of onderbreking. Bij 24 BCSP-traces volgt een geldig sequence-nulframe na slechte checksum/CRC/lengte, verkeerde sequence of ongeldige escape, met volledige/éénbyte feeds en beide varianten. Alleen het geldige frame wordt gepubliceerd en het commando wordt afgerond. Zes H4-traces pauzeren halverwege de body; de later aangeboden rest wordt zonder reset samengevoegd, verwerkt en vrijgegeven.

**Vier BCSP-duplicaattraces** houden twee commando's met dezelfde opcode uitstaand. Het eerste sequence-nulframe rondt één commando af. De herhaalde sequence nul wordt niet opnieuw doorgegeven en veroorzaakt geen extra free of verwijdering van het tweede commando. Sequence één rondt het tweede commando af. Dit legt een concrete transportgrens naast de eerdere opcodecorrelatiebevinding: een herhaalde BCSP-sequence wordt tegengehouden; H4-duplicaten of een nieuw sequenceframe met herhaalde eventinhoud vallen buiten deze garantie.

## Vastgezette foutuitkomsten

| Oorspronkelijke invoer | Uitkomst in gekoppelde proef |
| --- | --- |
| BCSP: slechte headerchecksum of CRC | Geen HCI-event; commandolijst en verwachte sequence behouden |
| BCSP: outer lengte één te groot/klein | Geen HCI-event; geen decoderread |
| BCSP: onverwachte reliable sequence of ongeldige SLIP-escape | Geen HCI-event; aansluitend geldig frame werkt in recoverymatrix |
| BCSP: geldige outer framing/CRC, slechts drie HCI-bytes `0e 0a 01` | Event gepubliceerd; decoder `b919c` leest byteoffset vier buiten de driebyteallocatie |
| BCSP: twaalf HCI-bytes, inner declared length `ff` | Event gepubliceerd en commando verwijderd ondanks inner/outer-lengtemismatch |
| BCSP: volledige bytes, inner declared length nul | Event gepubliceerd; decoder rondt het commando niet af |
| H4: `04 0e 01 01` | H4 accepteert de gedeclareerde body van één byte; dezelfde decoderread op offset vier overschrijdt de driebyte-eventallocatie |
| H4: gewone body afgekort | Geen event; buffer blijft beschikbaar voor de later aangeboden rest; recoverymatrix bevestigt hervatten |
| H4: declared length `ff` met slechts gewone korte body | Geen event binnen deze feed; parser blijft op body wachten |
| H4: length nul gevolgd door een geldig packet | Geen event in deze bounded ready-statefixture; parser houdt een payloadbuffer in bodystate vast |

De dertien probes hebben nu expliciete assertions op deze uitkomsten. Een onverwacht event, verdwenen commando of veranderde fault-PC maakt de verifier rood. De laatste H4-case bewijst **geen permanente deadlock op hardware**: eventuele timeout-/power-/resetcallbacks worden niet uitgevoerd. Die verdere route moet worden gevolgd voordat een herstelpatch wordt gekozen.

BCSP valideert de outer transportlengte, maar niet het HCI-schema binnen die payload. H4 verzamelt exact de aangeboden HCI-lengthbody, maar toetst daarbij niet de minimumlengte voor Command Complete. De decoder krijgt bovendien geen envelopecount doorgegeven. De korte-eventbevinding is daarom lokaal via beide oorspronkelijke frameparsers onderbouwd; radio-/telefoonbereikbaarheid en praktische incidentfrequentie zijn niet bewezen.

## Vervolg voor de gezamenlijke release

Een eventuele decoderreparatie moet de werkelijk ontvangen lengte en het eventschema controleren vóór de converters lezen, met correcte vrijgave en scheduler-/creditgedrag bij weigering. Die extra fix blijft een releasekeuze; dit rapport voegt haar niet toe aan het pakket.

Open blijven ACL/SCO/andere events, volledige serialdriver, power-/timeout-/resendpaden, controllerauthenticatie/profielstatus, concurrency, allocationfailureherstel, cache-aliases en snapshotgeneratie. Daarna moeten de afzonderlijke acht-record-, database-, UI-, IPC-, sleutel- en playbackvoorstellen samen worden gevalideerd. De oorspronkelijke fysieke functiebaseline en vóór/na-unitmetingen blijven vereist door de [releasevoorwaarden](release-requirements.md).
