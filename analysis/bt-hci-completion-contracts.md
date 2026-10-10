# Bluetooth-controllerantwoorden en commandolifetime

Het vervolg op de transportproef volgt de **oorspronkelijk geregistreerde ontvangcallback**, native mblk-buffers, DM_HCI-dispatcher en afhandeling van sleutelcommandobevestigingen. De uitstaande commandolijst is dynamisch. De gevolgde code bevat hier geen vaste grens van vier/vijf opgeslagen apparaten. Dat ondersteunt het acht-apparatenvoorstel, maar bewijst geen succesvolle pairing op de fysieke controller.

Uitvoeren: `py tools/verify_bt_hci_completion.py`. [Evidence](firmware/bt-hci-completion/contracts.json) bewaart oorspronkelijke functies/leaves/tabellen, bronhashes, synthetische berichten, alloc/free-traces, decoderfouten en interpreter-ABI-controles. Native firmware wordt niet uitgevoerd; er wordt geen executable of LGU geschreven. `build_allowed` blijft false en MAX02 blijft ongewijzigd.

## Native ontvangroute

De oorspronkelijke transportconstructor schrijft `e8f14` naar objectoffset `10`. De proef gebruikt die daadwerkelijke geregistreerde pointer. Het aangeboden transportdescriptor bevat payloadpointer op `+0`, lengte op `+4` en channel vijf op `+c`. De transportparser/stagingdescriptor en controllerbytes zijn fixtures; UART-/BCSP-/H4-framing is niet onderdeel van deze ontvangstproef.

`e8f14` maakt via `824a0/82378` een mblk, kopieert de aangeboden bytes en roept `e8c0c` aan met contextglobal `2172b0`. Native `ead88` consumeert de eventcode. De functietabel op `10c904` verwijst naar oorspronkelijke consume-, copy- en destroyhelpers `82530`, `82630` en `824e8`. Ook deze instructies worden geïnterpreteerd. `81df0/81c7c` bepalen en kopiëren de resterende eventbytes; `819ac/81940` ruimen de mblk en diens payload op.

Normale events gaan via `e8708` naar een acht-byte envelope: primitive `8007`, bytecount op `+2`, raw-eventpointer op `+4`, schedulerklasse `600`. De HCI-contextbestemming en queue-ID `218640` zijn expliciete schedulerfixtures. Opcode nul heeft een aparte route via `e8aac`; die route valt buiten deze proef.

DM_HCI-handler `9197c` roept converter `b44bc` aan. Die reserveert en wist 56 bytes en gebruikt de 43-entry eventtabel op `10da98`:

| Event | Converter | Dispatch via `10d338` | Resultaatvelden |
| --- | --- | --- | --- |
| `0e` Command Complete | `b917c` | `907a0` | credits `+2`, opcode `+4`, status `+6`, returnbuffer `+8` |
| `0f` Command Status | leaf `b924c` | `90838` | status `+2`, credits `+3`, opcode `+4` |

De packetvorm en commandocredits zijn afzonderlijk vergeleken met de [Bluetooth SIG HCI-specificatie](https://www.bluetooth.com/wp-content/uploads/Files/Specification/HTML/Core-54/out/en/host-controller-interface/host-controller-interface-functional-specification.html). De nieuwere specificatie bewijst geen ondersteunde Core-versie of werkelijk controllergedrag van deze unit.

## Bevestiging, status en geheugen

SC/CM/DM leveren de eerder gevolgde positieve `040b` of negatieve `040c` Link Key Request Reply. De H4-native pomp verstuurt eerst alle synthetische pakketten en bevrijdt transmitpayloads/descriptors. De DM-commandostructuren en acht-byte uitstaande nodes blijven bestaan tot het controllerantwoord.

`907a0/90838` schrijven de aangeboden commandocredits naar halfword `110eac`. `8f99c` zoekt vervolgens de **eerste overeenkomende opcode** in lijst `217228`, verwijdert de node en retourneert het bijbehorende commando. Er is bij dit matchen geen apparaatadresvergelijking. De gevolgde sleutelcommando's hebben flags vier: de interne `b3ce8`-route behandelt hun Command Complete zonder een aparte appstatus-enqueue. De bestaande sleutelcache blijft staan; vervolgauthenticatie/profile-status is nog niet gevolgd.

Command Complete bevrijdt commandostructuur en 36-byte returnbuffer, roept de commandopomp `9040c` aan en keert terug. De buitenste handler bevrijdt de 56-byte decoded event, raw-eventpayload en envelope. Command Status volgt andere succes/foutbranches; voor de aangeboden sleutelopcodes wordt de node niet naar lijst `21722c` voor later asynchroon completion verplaatst. Foutstatus één/`11` volgt de native foutdispatch zonder nieuwe sleutelcacheverwijdering. Deze Status-injecties controleren instructiegedrag; ze zijn geen claim dat zulke sleutelopcodes normaal dit event van de controller krijgen.

Een extra antwoord bij een lege uitstaande lijst veroorzaakt geen tweede free van een commandostructuur. Dit is een beperkte idempotentie-eigenschap. Bij twee uitstaande commando's met dezelfde opcode kan een dubbel of omgekeerd geadresseerd synthetisch antwoord het volgende commando matchen: opcodecorrelatie alleen kan die gevallen niet onderscheiden. Zonder bewezen controller-/transportvolgorde is dat geen afgeronde lifetimegarantie.

## Grenzen van de parser en allocatie

De decoder krijgt van `9197c` uitsluitend de raw-eventpointer; de envelopebytecount wordt daar niet meegegeven. `b44bc` gebruikt parameterlength-byte één vooral als nul/non-nulselectie. De gevolgde Complete/Status-converters lezen vaste offsets zonder die offsets zelf tegen de ontvangen bytecount te controleren. De proef gebruikt readguards na de werkelijk aangeleverde payload. Een out-of-bounds-witness betekent een concrete oorspronkelijke instructieread bij een afgekorte injectie, zonder claim dat die injectie de echte frameparser passeert of via radio exploiteerbaar is.

De allocatieproef weigert afzonderlijk de RX-payload, mblk, herbouwde eventpayload, scheduler-envelope, decoded event en returnbuffer. Deze native paden hebben geen volledige foutpropagatie: de volgende copy/memset/store kan een NULL-pointer gebruiken. De witnesses beschrijven de concrete callargumenten/instructies; werkelijk Windows CE-heap- of crashgedrag is niet gemeten.

## Nog vereist voor acht apparaten

De matrix bevat 216 normale completion/status-traces: origineel/cleanupvariant, één/acht/zestien records, positief/negatief sleutelantwoord, status nul/één/`11`, commandocredits nul/één/vier. Tien aanvullende malformed-cases reproduceren zeven concrete readwitnesses. Een volle fixture met declared length nul laat het commando uitstaan; dezelfde ontvangen bytes met declared length `ff` worden alsnog als completion verwerkt. Zes afzonderlijke allocationfaults en vier mixed-/same-opcodecorrelatietraces zijn apart vastgelegd. Normale calls controleren stack en callee-saved registers; faultwitnesses zijn geen geslaagde ABI-return.

De native completionproef sluit één deel van de eerdere lifetimevraag af. Open blijven volledige frame-/ACK-/serial-parsercontrole, opcode-nul/overige events, controllerauthenticatie/security/profile-status, gelijktijdige callbacks, heapfailureherstel, cache-aliases/snapshotgeneratie en gezamenlijke App-/Blue-/playbackintegratie. De hostfixture met zestien sleutelrecords is extra stackonderzoek en geen voorstel om de vaste opslag meteen naar zestien te verhogen. Het huidige gebruikersdoel blijft **acht opgeslagen koppelingen**.

Het hervatte [RX-frameonderzoek](bt-rx-frame-contracts.md) volgt inmiddels de oorspronkelijke BCSP- en H4-eventparsers tot deze decoder. Slechte outer BCSP-frames worden geweigerd; een inner event van drie bytes bereikt via beide parsers de read op `b919c`. Normale acht-recordontvangst, herstelde fragmenten en BCSP-sequenceduplicaten zijn gekoppeld gecontroleerd. Volledige serial-/power-/timer-/ACK-reachability en andere eventtypen blijven open.

Er is nog geen gecombineerde acht-apparaten-LGU. De beschikbare update bevat de eerdere playback-/navigatiepatch, terwijl pairingvoorstellen afzonderlijke interpretervarianten zijn. Booten, het achtste echte apparaat toevoegen, herstarten, herverbinden en apparaten verwijderen moeten later op de unit worden gecontroleerd.
