# Bluetooth-sleutels van hostdatabase tot transportcallback

De oorspronkelijke Blue-code verwerkt in de interpreter **acht verschillende opgeslagen adressen en sleutels tot afzonderlijke HCI-commandobytes**. Een aanvullende proef doet hetzelfde voor zestien aangeleverde hostrecords. De gevolgde DM-sleutelcache is een dynamische lijst; hier is geen vaste grens van vijf gevonden. Dit bewijst de onderzochte hostroute. Controllercapaciteit, echte radio-authenticatie en herstart op de autoradio blijven ongevalideerd.

Uitvoeren: `py tools/verify_bt_key_stack.py`. [Machineleesbare evidence](firmware/bt-key-stack/contracts.json) bevat oorspronkelijke functie-/leafbytes, pointertabellen, bron-/toolhashes, synthetische sleutels, berichtbytes, ownershipcontroles en foutwitnesses. Firmwarecode wordt uitsluitend geïnterpreteerd. File-API's, schedulerregistratie/-delivery, heapprimitieven, diagnostiek en de laatste verzendcallback zijn fixtures. Er is geen executable of LGU geschreven; `build_allowed` blijft false.

## Gevolgde route

| Stap | Oorspronkelijke code en bericht |
| --- | --- |
| Hostlookup | SC `c5c48` → `7a63c`, bestaande recordpolicy en constructors `cd000/cd07c/cd0a4` |
| SC → CM | Adapter `782a8`: queueglobal `21862e`, klasse `104`, primitive `205` |
| CM-dispatch | Handler `bcf14` → `ca440`, oorspronkelijke tabel `10e87c`, entry `205` op `10e890` → `ce478` |
| CM → DM | `ce478` → `efd2c` → `f26d4`: queueglobal `218642`, klasse `4`, primitive `388` |
| DM-dispatch | Handler `91bd4` → `91acc`, oorspronkelijke tabel `10d4b4`, entry acht op `10d4d4` → `ac9a4` |
| Sleutelcache en keuze | `ac9a4` → `bd738`, `b4ee0/b4728/b46bc`, `b4910/b47c8`; type-/authenticatieregels bepalen positief of negatief |
| HCI-commandowachtrij | `911a4` → `9040c/8f804` → `91820`; native outstanding-/creditboekhouding |
| Serialisatie | `b4594` vult parameterlengte uit tabel `10dbf0`; `b443c` zoekt oorspronkelijke tabel `10d7f8`: `40b` → `ba49c`, `40c` → `ba670` |
| DM → CSR_HCI | `e98ac`: primitive `7`, lengte op `+2`, bufferpointer op `+4`; queueglobal `218654`, klasse `600` |
| HCI-receiver | `e96f4`, oorspronkelijke twee-state-tabel `10efb8`; state nul bewaart via `e887c/82a50`, state één verzendt via `e91ec` |
| Transportadapter | `e91ec` → `e8b9c` → `833e4`: descriptor van 24 bytes, payload op `+4`, lengte op `+8`, velden `+14/+15` gelijk aan `5/1`, dispatch naar transportobjectcallback `+c` |

Registratiecalls `8a230/8a470` worden eveneens uit oorspronkelijke bytes geïnterpreteerd. Hun fixture capture bewaart namen, oorspronkelijke naambytes, init/deinit/handler en queueglobals. `21862e` is **CSR_BT_CM**, `218642` is **CSR_BT_DM**, `218654` is **CSR_HCI**. De eerdere sleutelopslagbeschrijving noemde de eerste bestemming DM; die toeschrijving is gecorrigeerd. De schedulerfixture gebruikt afzonderlijke IDs `323/324/325`; dit zijn geen gemeten runtime-tasknummers.

## Commandobytes, cache en ownership

Een positief antwoord bevat opcodebytes `0b 04`, parameterlengte 22, zes adresbytes en zestien sleutelbytes: totaal 25 bytes. Een negatief antwoord heeft `0c 04`, parameterlengte zes en uitsluitend het adres: totaal negen bytes. De adresserialisatie gebruikt drie lage adresbytes, de byte op BDADDR-offset vier en het halfword op zes. Padding is geen adresdata. De proef vergelijkt het volledige commandopakket met de synthetische recordgegevens; geen sleutel wordt uit een echte unit gelezen.

CM dupliceert de SC-sleutel naar een 18-byte object met typehalfword en zestien sleutelbytes. De native DM-constructor maakt een 28-byte `388`-bericht. Nadat de omzetting klaar is, bevrijdt CM de oorspronkelijke sleutel, wist SC-responspointer `+10` en bevrijdt de response. DM kopieert de sleutel naar zijn eigen dynamische cache/commandostructuren, bevrijdt het 18-byte object en vervolgens het `388`-bericht. De interpreter bewaakt gelezen/geschreven freed-ranges en weigert dubbele/ongeldige frees.

`b4728` maakt per nieuw adres een dynamisch, nulgevuld cacheobject van 52 bytes en linkt het aan head `2172bc`. Een bestaande entry wordt via typed-adresvergelijking teruggevonden. Vier serieproeven gebruiken acht/zestien records in origineel en iteratorvariant, eerst vooruit en daarna achteruit: de native cache blijft acht/zestien entries tellen en ieder antwoord bevat de juiste sleutel. Controlleropslag en het aantal gelijktijdige verbindingen volgen hier niet uit.

De HCI-commandostructuur, outstanding-list en uiteindelijke transmitdescriptor/-buffer blijven aan het eind van deze proef bestaan. De werkelijke completion- en shutdownroute wordt hier niet uitgevoerd; die retentie wordt niet als een bewezen leak of afgeronde lifetime aangemerkt.

## Policy en gerepareerde readfailure

De SC-recordpolicy en DM-authenticatieregels zijn verschillende beslissingen. De SC-caller kan een matched record accepteren terwijl DM later een negatief controllerantwoord maakt. De proef gebruikt een lege ACL-list en expliciete globale securitymode/flags op `217284`.

- Types `3/4/5` geven in deze fixtures een positief antwoord.
- Type nul geeft dat ook, behalve bij mode vier met flags `2400`.
- Types `1/2/7/fe` geven in de gecontroleerde cold-fixtures een negatief antwoord.
- Type zes zonder vorige bruikbare cachetype geeft hier een negatief antwoord. Bij vervanging van een gecachte sleutel met type `0/3/4/5` behoudt native `b4ee0` dat vorige type en verstuurt hij de nieuwe sleutelbytes positief. Vier traces volgen dat onderscheid.

Dit zijn concrete native branches in de onderzochte toestanden, geen volledige Bluetooth-policybeschrijving of gemeten configuratie van de unit.

Acht oorspronkelijke/reparatieparen volgen `ReadFile=FALSE` met 104 gemelde bytes vanaf de eerste recordread door de volledige SC/CM/DM-serialisatie. Origineel kan alsnog een positief `40b`-pakket met de gelezen sleutel maken. De bestaande lookupreparatie weigert de fout en maakt een negatief `40c`-pakket voor hetzelfde doeladres. Er is hiervoor geen nieuwe binarypatch toegevoegd.

## HCI klaar worden en transportgrens

Zestien receivertraces gebruiken origineel en iteratorvariant: **twaalf positieve traces** bij één/acht/zestien records, telkens direct-ready of eerst deferred, plus **vier negatieve traces** met één record, telkens direct/deferred.

In deferred state nul bewaart `82a50` de envelopes in dynamische blokken van tien entries. Zestien records gebruiken dus twee blokken. Native activatiehelper `e88b0` zet state één, markeert drain en enqueue't een wakebericht. `e96f4/82b44` haalt de oude envelopes FIFO op, bevrijdt lege queueblokken en geeft alle identieke pakketten aan de transportcallbackfixture door. Daarna zijn deferred head en drainflag nul. De eigen HCI-envelope wordt eenmaal bevrijd; transmitdescriptor en payload worden aan de callback overgedragen.

Twee extra traces maken de transportcallbackpointer nul. Native `833e4` keert dan stil terug: geen callback, wel een aangemaakt descriptor en behouden payload. De caller heeft hier geen verzendstatus. Of die toestand op de unit bereikbaar is en hoe transportregistratie/-lifetime dit voorkomt of herstelt, blijft open.

## Allocatieproblemen en verificatie

Elf SC/CM/DM-allocationfaults stoppen bij een concrete ongecontroleerde toegang: acht native stores op adres nul/nul-plus-offset en drie NULL-bestemmingen bij de memcpy/memset-API-fixture. De native store-PC's zijn `cd034`, `efd94`, `f271c`, `b4fa4`, `aca28`, `911e4`, `904ac` en `e98cc`. API-witnesses zijn expliciet een stop vóór de externe copy/zero-call, geen claim over het exacte gedrag van de CE-runtime.

Twee aanvullende HCI-allocationfaults volgen de ready/deferred routes tot een native lage store na een geweigerde transmitdescriptor-/deferredblokallocatie. Gestopte faults claimen geen ABI-terugkeer of afgeronde cleanup.

| Controle | Aantal |
| --- | ---: |
| Verse SC → CM → DM → HCI-antwoorden | 18, acht bestaande en één ontbrekend adres, twee varianten |
| Dynamische cache, vooruit/achteruit | Vier series, acht/zestien records, twee varianten |
| DM-keytype/securitymode/flags | 27 |
| Type-zes vervangt bestaande type | Vier |
| SC/CM/DM-allocationfaults | Elf |
| HCI-receiver/activatie/FIFO/transportadapter | Zestien |
| Ontbrekende transportcallback | Twee |
| HCI-allocationfaults | Twee |
| FALSE/full-record tot controllercommandobytes | Acht oorspronkelijke/reparatieparen |

Alle afgeronde routinecalls controleren stack en callee-saved registers. Gepinde oorspronkelijke tableentries selecteren de receivers/serializers; de fixture vervangt geen keytypekeuze of pakketserialisatie.

De iteratorvariant houdt SHA `5b2d11baa5788e548b7cf0fb07fbfdf81f3d718de7c27680097577e106cc9ddd`. Originele binaries en MAX02 blijven ongewijzigd. Volledige stackinit, native heapfailureherstel, scheduler-/cache-/snapshotlocking, fysieke transportdriver/controllercompletion, radio-authenticatie, unitboot, App-cachealiases en integratie met de App-safe-copy blijven nodig voor een complete acht-apparatenupdate.

Het [transportvervolg](bt-transport-contracts.md) vervangt de verzendcallbackfixture met de oorspronkelijke BCSP/H4DS-objectregistratie en callbacks. Reliable-window/ACK-payloadcleanup en H4 partial-write/free worden daar gevolgd; de fysieke seriële boundary blijft een fixture. Een afzonderlijke variant repareert twee aangetoonde cleanupfouten. De pointertabellen en packagebytes in dit eerdere rapport blijven ongewijzigd.
