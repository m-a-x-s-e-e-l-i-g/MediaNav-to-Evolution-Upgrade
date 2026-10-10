# Afzonderlijke lijstbevestiging voor acht apparaten

De [IPC/HFP-analyse](bt-ipc-roundtrip-draft.md) toont dat een geslaagde OS-send na een mislukte database-read toch de oude actieve record en het verkeerde telefoonboek kan gebruiken. De afzonderlijke prototypevariant in `tools/draft_bt_list_ack.py` bewaart nu de read-uitkomst tot de HFP-consumer. Zij bestaat uitsluitend in interpretergeheugen, bovenop de gepinde acht-recordbasis; er is geen executable of LGU geschreven. MAX02 bevat deze wijziging niet.

Reproduceren: `py tools/verify_bt_list_ack.py`. De [evidence](firmware/bt-list-ack-draft/contracts.json) bewaart originele instructiebereiken, preimages, wijzigingsbytes, script-hashes en traces. De bestaande elf suites blijven bewijs voor de eerdere basisvariant. Deze twaalfde suite onderzoekt de afzonderlijke ACK-variant; die verschillen mogen niet als één gevalideerde release worden samengevoegd.

## Protocol en Blue-ontvangst

Alleen de geslaagde Blue-lijstaanvraag `1010702` geeft `0x4c530000 | count` terug, met count nul tot acht. Nul betekent geen geslaagde reload. De twee bestaande `4010702`-meldingen blijven; een transportfout bij een melding wist de geslaagde read-bevestiging niet.

De geïnterpreteerde route is `8070`-WndProc `33d34` → module-dispatch `31634` → GUI-dispatch `30f08` → lijstaanvraag `2fec4` → reload `3307c`. Native database-I/O, shared-copy en meldingswrappers worden uitgevoerd met expliciete OS-/bestandsfixtures. Het count wordt na de geslaagde reload via getter `3184c` gelezen en in een bewaard register over de buitenste melding heen gehouden. De ACK bereikt LRESULT via aparte epiloogentries; gewone module-/GUI-routes behouden hun nulreturn.

Andere ordinary message-ID's binnen het private bereik blijven nul; `8082` gebruikt de bestaande native Micom-dispatch die nul retourneert. De default-windowprocedure behoudt haar eigen resultaat. WM_COPYDATA houdt nul en eventuele payload-free, ook als zijn commandobody een ACK oplevert. Geselecteerde commandobody's, decoder, free en default OS-handler zijn hooks; dit bewijst de dispatch-/returnroutes, geen volledige commandosemantiek.

## Wrapper en HFP-consumer

De bestaande wrapper `11b464` negeerde zijn tweede argument. Alle 152 geïnventariseerde oorspronkelijke decompiler-calls geven één door; de oorspronkelijke directe JAL-inventarisatie blijft apart bewaard. De proef gebruikt twee uitsluitend bij de HFP-lijstaanvraag. Bij andere waarden blijft nul OS-succes en −1 failure; bij twee geeft OS-succes het receiverresultaat terug. Het outveld wordt vóór de eerste poging en opnieuw vóór retry gewist. Een ACK die een mislukte eerste poging achterlaat, kan daardoor niet worden hergebruikt als de succesvolle retry zijn outveld niet schrijft.

De HFP-handler valideert de exacte hoge 16 bits en count ≤ acht. Bij geldige ACK wordt count vóór native copy/rescan/PB-read in `CBtData+26c` gezet, ook wanneer alle countmeldingen mislukken. De eerdere Sleep van 300 ms vervalt in deze proef; dit is geen reparatie of meting van A2DP-playbacklatency.

Bij ontbrekende/ongeldige ACK of transportfailure worden actieve index, shared-recordpointer en PB-status ongeldig gemaakt, zonder oud telefoonboek te openen. Bevestigd HFP blijft intact, behalve waar de bestaande native list-endcallback bij count nul zelf HFP-state wist. Een lege lijst mét callback en dezelfde lijst zonder afgeleverde callback geven daarom verschillende HFP-state-uitkomsten. Dat verschil is vastgelegd en nog niet gerepareerd.

Tijdelijke status/count gebruiken `sp+44` en `sp+48`. De vier oorspronkelijke accesses gebruiken die velden pas vanaf `11fcb4`, na de nieuwe copy/PB-gate; zij staan in de evidence. Prologen, frames, saved-registerplaatsen en `.pdata` blijven gelijk. Dat is geen native unwindbewijs of bewijs over indirecte wrappercallers.

## Actieve scan binnen count

Native helper `111d84` zocht in de acht-recordbasis altijd acht shared slots, zonder count te lezen. De baseline kiest slot zeven bij count één wanneer alleen dat oude slot een actieve vlag heeft. Ook een lege lijst kon naar een achtergebleven record wijzen.

De ACK-proef accepteert count één tot acht, controleert de shared-base, zoekt alleen die slots en wist index/pointer wanneer geen actieve record bestaat. Een halfwordtest behoudt HFP óf media nonzero; bij meerdere actieve records wint de eerste. De inlined pointerberekening vervangt de gevolgde pure getter. NULL wordt in deze scan geweigerd, maar de voorafgaande native copy kan een nonempty NULL-bank nog derefereren: dit is geen volledige NULL-reparatie van de HFP-keten.

## Offline verificatie

| Controle | Cases en betekenis |
| --- | --- |
| Opt-in wrapper | 30 traces: nonzero OS-success, raw LRESULT, failure, retry met/zonder out, gesloten gate, andere modes en register-clobberende debugcommand |
| Bestaande wrappersemantiek | 40 gelijke basis/prototypeparen voor kinds en transport-/window-/invalid-commandpaden |
| Blue → HFP bij geldige read | 222 traces: count nul tot acht, iedere selectie, gewone/call-popup-entry en geslaagde/mislukte/herstelde countmeldingen |
| Databasefouten | 72 gekoppelde traces: header-BOOL, false/full bulk, incomplete bulk en seek; geen stale PB-read |
| Ongeldige ACK | 14 traces: zero/legacy return, verkeerde signature, −1 en count boven acht |
| Buitenste transport | 30 traces: error, tweemaal timeout, retry, succesvolle retry zonder geschreven out en disabled gate |
| Begrensde scan | 180 traces: empty, iedere actieve positie, HFP/media, geen/meerdere actieve records, invalid count en NULL |
| Overige ontvangende routes | 61 traces: commands/ID's, gesloten receiver, alle 16 modules plus buitenbereik, native Micom-default en WM_COPYDATA-cleanup |

Geneste AppMain-listcallbacks hebben een aparte interpreterstack en delen alleen de expliciete RAM-fixture met de onderbroken HFP-handler. Register-/stackherstel worden gecontroleerd; firmware wordt niet native uitgevoerd. Phonebookbestanden zijn missing-fixtures, drawing/getters/debug hebben geselecteerde hooks en de extra profile-queryreceiver is niet uitgevoerd.

## Grenzen en releasevoorwaarden

Een ACK bevestigt een voltooide read/publicatie, maar beschermt geen immutable snapshot en bevat geen generatie. Een counterexamplefixture geeft een welgevormde ACK met acht oude records: AppMain accepteert hem en opent het oude PB-pad. Een signature is dus geen algemeen freshnessbewijs. Gelijktijdige shared-bankwrites, CE-reentrancy/thread-ordering, complete CSR-entry, radio-/sleutelcapaciteit voor acht, allocatie/unwind/lifetime en alle cache-aliases blijven releasevoorwaarden. Atomische DB-write/recovery en andere actieve profielwissels blijven open.

De bronfirmware blijft gepind:

- Blue origineel `5e659f513327c84964a929ea9b9e3192384b3031fa6e6ffb6ad76b02af1b7c7b`; basis `0b995d157cc7e48bb1a74ecab8bc307f37c8f54a7cc5f686231e7237b0148f45`; ACK-proef `ddeca3721a3efdd908fac58ef5072071bd8c3bbbe3b9da5715ee16e985cda2e2`.
- AppMain origineel `6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8`; basis `7a44ab13a6a1ce38bf7565d6c22d6a62dd41b2b95713e2578bbc3df2527276ea`; ACK-proef `c89f3b16c2f3a62b12e66501966957d38c4a0c4a04088f37b5596ae67d306d4a`.

De [native object-/mappinganalyse](bt-data-cache-lifecycle.md) reproduceert inmiddels de nonempty NULL-copy na een mappingfailurefixture, zowel oorspronkelijk als in de basis/ACK-proef. Ook allocatie- en destructorproblemen zijn gevolgd. Die gaten zijn nog niet in de ACK-proef gerepareerd.

De basis is nog niet met MAX02-playback/nav gecombineerd. Deze aparte ACK-proef is evenmin gekoppeld aan de LGU-builder; `build_allowed` blijft false.

Een [afzonderlijke safe-copy-proef](bt-safe-copy-draft.md) controleert nu NULL/ongeldige count vóór de kopie, wist stale actieve/PB-verwijzingen en volgt beide overige directe caller-suffixes. Ook de rendererstore met index −1 en het profielzoeken met een oude managercount zijn gereproduceerd en in die afzonderlijke variant afgevangen. De hierboven gepinde ACK-variant blijft onveranderd; haar NULL-beperking en snapshotvoorwaarden blijven gelden.
