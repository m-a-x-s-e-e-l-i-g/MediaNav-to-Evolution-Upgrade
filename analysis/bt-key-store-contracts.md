# Bluetooth-sleutelopslag, hostcapaciteit en database-iterator

Het verdere onderzoek bevestigt **acht afzonderlijke hostrecords met sleutels**: de native SC-persistencecaller schrijft ze in de offline proef, en een vers interpretergeheugen met alleen de opgeslagen bestandbytes kan iedere sleutel via de native SC-respons teruggeven aan het juiste adres. Dit is geen hardwareherstart, geslaagde radio-authenticatie of bewijs van de controllercapaciteit.

Uitvoeren: `py tools/verify_bt_key_store.py`. De [evidence](firmware/bt-key-store/contracts.json) bewaart originele bereikbytes, bron-/patch-/toolhashes, synthetische recordgegevens en native traces. [De afzonderlijke iteratorreparatie](../tools/draft_bt_key_iterator.py) bestaat alleen in interpretergeheugen bovenop de count-ACK-Blue. Er is geen executable/LGU geschreven; `build_allowed` blijft false. De bestaande basis, ACK, AppMain safe-copy en MAX02 zijn niet aangepast.

## Record en echte sleutelrespons

De database `\Storage Card2\DATA\BLUE\sc_db.db` begint met magic `02 00 ff ff`, gevolgd door records van 104 bytes. De gevolgde native constructors/readers gebruiken deze velden:

| Offset | Gevolgde betekenis |
| --- | --- |
| `00..07` | BDADDR: low word op nul, byte op vier, halfword op zes; paddingbyte vijf wordt niet door de adresvergelijker gebruikt |
| `08` | Marker die SC-persistencecaller `c26cc` op één zet |
| `09` | Door die caller geschreven sleutellengte zestien |
| `0a..19` | Zestien sleutelbytes uit SC-context `+110` |
| `1a..4c` | Naamruimte van 51 bytes, laatste byte getrimd op nul door de naamhelperfixture |
| `50..53` | Class/device-waarde uit context `+40` |
| `54..63` | Vier extra 32-bit velden, behouden door lookup/update en metadata-export; volledige semantiek open |
| `64` | Byte uit context `+81`, ook opgenomen in metadata-export |
| `65` | Byte uit context `+120`, door native sleutelrespons als type doorgegeven |

`c5c48` zoekt het aangevraagde adres op via `7a63c`, controleert requestpolicy met native leaf `c2604`, dupliceert zestien bytes via `857bc` en bouwt met `cd07c`/`cd000` primitive `205`. Adapter `782a8` geeft dat bericht als klasse `104` door aan queueglobal `21862e`, geregistreerd als **CSR_BT_CM**. De eerdere DM-toeschrijving was onjuist; het verdere [sleutelstackonderzoek](bt-key-stack-contracts.md) bevestigt de CM-registratie en volgt de omzetting naar de echte DM-queue. De constructor zet adres op `+4/+8`, type op `+c`, lengte op `+d`, sleutelpointer op `+10` en een nulbyte op `+14`. De negatieve helper `cd0a4` gebruikt type `fe`, lengte nul en pointer nul. Dit rapport stopt bij de CM-schedulerboundary; het vervolgrapport interpreteert CM, DM, HCI-serialisatie en transportadapter met expliciete scheduler-/verzendfixtures.

De native policy accepteert requestbyte nul; byte één vereist recordtype vijf; andere waarden worden geweigerd. Deze reader controleert marker `08` en lengte `09` niet. Een gematchte synthetische record met beide nul en zestien nulsleutelbytes levert toch een positieve respons van zestien bytes op. De betekenis/invarianten van alle recordwriters moeten verder gevolgd worden voordat dit als oorzaak van een echte pairingfout of als reparatievoorwaarde kan gelden.

## Opslaan en een vers geheugenscenario

De proef roept `c26cc` negen keer met verschillende synthetische adressen/namen/sleutels aan, gekoppeld aan de bestaande gerepareerde scanner en recordwriter. Acht records worden exact opgeslagen. Nummer negen wordt door de bestaande acht-slotwriter geweigerd. De SC-caller heeft zijn SD-registratiebericht dan al verstuurd en verwerkt het persistence-resultaat niet: dat eerder gevonden statusgat blijft bestaan.

27 traces gebruiken voor ieder van de drie varianten een nieuw interpretergeheugen en alleen de opgeslagen acht-recordbestandbytes. Alle acht juiste sleutels worden teruggegeven; een ontbrekend negende adres geeft een negatieve respons. Zes aanvullende hostlookups vinden in aangeleverde databases met negen of zestien records ook de laatste record. De gevolgde hostlookup heeft dus geen vijf-/acht-indexgrens; de toevoeglimiet in de proef zit in de hogere writer/GUI-paden. Dit bewijst alleen deze hostcodepaden, geen algemene radio- of controllercapaciteit.

Acht originele/reparatieparen verbinden een `ReadFile=FALSE` met toch 104 gemelde bytes aan de echte sleutelrespons: origineel kan het gelezen record alsnog als sleutelrespons worden verzonden. De reeds bestaande basisreparatie in `7a63c` weigert die read en stuurt de negatieve respons. Dat is geen nieuwe wijziging van de iteratorproef.

## Native SC-enumeratie in porties

De oorspronkelijke SC-dispatcher `bb80c` routeert requesttype `a` via de signed-halfwordtabel `bb84c` naar `c3bbc`. De proef voert die dispatcher, tabel, database-iterator, metadata-conversie `c2638` en scheduleradapter `cd1f8` uit.

De requestbudgetwaarde op `+4` bepaalt `max(1, floor(bytes/84))` records per portie. Elke volle portie wordt primitive `8007` met count op `+4` en arraypointer op `+8`. De laatste `8008` bevat totaal op `+4`, resterend aantal op `+8` en resterende arraypointer op `+c`. Bij een exact volle laatste portie volgt nog een eindbericht met nul resterende records. De extra velden op `+10/+14` worden door deze constructor nul gemaakt; hun formele schema en foutcodes zijn niet vastgesteld. Een gerichte externe zoekactie naar SC-headernamen leverde geen primaire bron op.

Iedere metadatarecord is 84 bytes: adres op nul, naam op acht, class op `3c`, de vier extra words op `40..4c` en byte op `50`. **Dit is metadata-export, geen export van de zestien sleutelbytes.** Padding/reserved bytes worden door de gevolgde converter niet allemaal geschreven; de verificatie vergelijkt uitsluitend de native gedefinieerde velden.

216 traces volgen originele, ACK- en iteratorvarianten voor nul/één/vijf/acht/negen/zestien records, zes requestbudgetwaarden en normale/sparse databases. Lege adressen worden door de iterator overgeslagen; het speciale adres `ffffff:ff:ffff` wordt door de hogere enumerator uitgesloten. Alle geldige records bereiken de juiste porties zonder een vijf-recordcap in deze gevolgde route. Twaalf extra native traces volgen Blue's eigen SC-apphandler `2320c`: zijn `8007/8008`-cases springen via de originele tabel direct naar de epiloog, doen geen API-call en laten de payload ongemoeid. Dit is dus geen bewijs dat deze route de GUI-lijst vult.

## Gevonden cursorfouten en afzonderlijke reparatie

Het globale cursorveld is `20e304`. Het ligt in de virtuele tail van `.data`, buiten de 4096 fysieke sectiebytes; er zijn geen vier oorspronkelijke filebytes op dat adres. Initwaarde nul wordt in de interpreter expliciet als loaderfixture gezet.

De oorspronkelijke `7a7f8` accepteert een read zodra bytecount 104 is en negeert de API-BOOL. Na EOF sluit hij de handle en zet het cursorveld op nul, maar zijn volgende entry weigert alleen `ffffffff`. De native cleanup `c2810` kan vervolgens opnieuw `ReadFile` met handle nul aanroepen. De witness stopt bij die concrete API-aanroep; dat is geen claim dat Windows CE daardoor een exception geeft.

De afzonderlijke body op `7a810..7a88c` vereist API-BOOL en exact 104 bytes, behoudt het overslaan van lege adressen, sluit eenmaal bij EOF/readfout en weigert zowel nul als `ffffffff` vóór I/O. De BOOL komt uit de reeds gerepareerde lage readwrapper `860f8`.

Ook `7ac28` verliest oorspronkelijk een vorige actieve cursorhandle bij restart, en laat na een mislukte seek de nieuwe handle open totdat een latere drain hem sluit. De nieuwe body op `7ac38..7ac9c` gebruikt de bestaande `c2810` om een vorige sessie eerst uit te lezen en te sluiten. Bij seekfailure sluit en wist hij de nieuwe handle direct. Magiccheck, opencheck, oorspronkelijke proloog/epiloog, stackframe en saved-registerplaatsen blijven behouden. De drain herstelt het in zijn delay-slot bewaarde outputargument in `s0`; de gevolgde helpers bewaren dat register.

Dit veronderstelt geserialiseerd ownership van de oorspronkelijke globale cursor. Concurrerende owners, blocking/cancellation en volledige CE-lifetime zijn niet bewezen. Een openfailure mag de herkenbare invalid-handlewaarde `ffffffff` achterlaten; beide nieuwe cursorentries handelen die af zonder nieuwe read.

## Wat nog fout gaat

Twaalf readfailureparen tonen dat de nieuwe iterator op de eerste fout stopt en sluit. De hogere enumerator stuurt daarna nog steeds een normaal `8008`-eindbericht met het gedeeltelijke totaal. Readfailure en clean EOF worden dus nog niet door het volledige berichtcontract onderscheiden. Bij de oorspronkelijke/ACK-iterator kan FALSE/met-104-bytes juist de volledige lijst publiceren. Een passende foutmelding vereist het verdere schema-/receiveronderzoek; er is geen gegokte foutcode toegevoegd.

Ook de enumerator controleert zijn allocaties niet. Een fixture die de eerste volle-portieberichtallocatie laat falen, bereikt de native halfword-store op adres nul bij `c3c9c`; de open cursor en eerdere data-allocation worden dan niet afgerond. Object-/heapfailure, atomiciteit en statuspropagatie blijven releasevoorwaarden.

## Reproduceerbare controles

| Controle | Cases |
| --- | --- |
| Native SC-persistencecaller | Acht geslaagde writes en één geweigerde negende; SD-registratie vóór write blijft zichtbaar |
| Verse keylookups | 27: acht bestaande en één ontbrekend adres, drie varianten |
| Sleutelpolicy | 32: acht types/adressen, vier requestpolicywaarden |
| Failed/incomplete keyreads | Acht negatieve responschecks plus acht oorspronkelijke/geguardde FALSE/full-paren |
| Grotere hostdatabase | Zes native laatste-recordlookups bij negen/zestien records |
| SC-dispatch → porties | 216: drie varianten, zes aantallen, zes budgets, normale/sparse input |
| Enumerator-readfailure | Twaalf oorspronkelijke/reparatieparen, fouten op eerste/vierde/achtste record |
| Cursor/cleanup | Vijftien traces: empty/open/header/seek/restart, drie varianten |
| Restart/drain | 24 traces bij één/vijf/acht records, gedeeltelijk/volledig gelezen, vier drain-uitkomsten; oude handle gesloten, eerste record opnieuw geladen en herhaalde cleanup zonder I/O |
| Eigen SC-apphandler | Twaalf native table/epiloogtraces negeren `8007/8008`, met/zonder receiverflag, in drie varianten |
| Allocation/recordmarkers | Eén native NULL-storewitness en één gematchte marker/lengte-nul-sleutelrespons |

File-, allocator-, naam- en scheduler-API's zijn expliciete fixtures; de MIPS-construction/dispatch/lookup/iterator/copybytes worden geïnterpreteerd. Volledige terugkeer controleert frame en callee-saved registers; de gestopte allocationfault claimt geen ABI-herstel.

De iteratorproef gebruikt ACK-basis SHA `ddeca3721a3efdd908fac58ef5072071bd8c3bbbe3b9da5715ee16e985cda2e2` en geeft Blue SHA `5b2d11baa5788e548b7cf0fb07fbfdf81f3d718de7c27680097577e106cc9ddd`. De [AppMain safe-copy](bt-safe-copy-draft.md) is nog een aparte variant. Gecombineerde regressies, snapshots/locking, key-allocationcleanup, werkelijke boot/controller/radiotests en verdere updaterreparaties blijven nodig vóór een nieuwe gecombineerde LGU.
