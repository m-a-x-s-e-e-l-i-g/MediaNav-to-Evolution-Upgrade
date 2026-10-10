# Bluetooth: HFP-succes, actieve record en mislukte lijstaanvraag

De acht-slotvariant is nu gevolgd door AppMain's native handsfree-succespad. Een bijkomende reparatie voorkomt in die callback dat een mislukte apparatenlijstaanvraag wordt gevolgd door het lezen van een oude actieve record en diens telefoonboek. Deze wijziging bestaat uitsluitend in interpretergeheugen. Er is geen executable geschreven, CE/radio uitgevoerd of LGU gebouwd.

Uitvoeren: `py tools/verify_bt_connection_success.py`. [Evidence](firmware/bt-connection-success-draft/contracts.json) bevat oorspronkelijke functies en hashes, patchhash, gekoppelde traces, baselines vóór uitsluitend de nieuwe guards en toolhashes.

## De twee succesmeldingen

Blue's oorspronkelijke confirmed-successblok `1734c..17380` verstuurt `3040101` met parameter nul naar bestemming drie, vervolgens hetzelfde bericht naar bestemming twee en daarna `4010506` naar bestemming twee via `332b0`. De oorspronkelijke instructies en de statushelper worden in deze begrensde proef uitgevoerd; `33390` is de expliciete emitterhook. Dit bewijst de verzendvolgorde binnen dat blok, niet de entryvoorwaarden van de volledige CSR-handler of de OS-aflevervolgorde.

AppMain entry `11cb00` verwerkt `3040101` als `LGEBT_HF_SERVICE_CONNECT_IND`. Parameter nul betekent het gevolgde handsfree-succespad. Die dispatcher stopt timers 416/41a, zet de lokale ready/profielstatus en roept `11f7d4` (`BT_Device_HF_Conn_End`) aan. De callback zet HFP-connected/ready, wist busy-status, vraagt met `1010702` de apparatenlijst op, wacht oorspronkelijk 300 ms, kopieert records, zoekt de actieve pointer en leest diens telefoonboek.

De proef laat de gedeelde recordbank tijdens de Sleep-hook als synthetische Blue-publicatie verversen. De daadwerkelijke `110708`, `111d84`, `11afcc` en `111364` volgen daarna die bytes. De laatste helper maakt de adresgebonden telefoonboekpaden; de filesystemhooks melden ontbrekende bestanden. Voor alle acht posities zijn actieve index, shared-pointer en bestandsnaam juist. Dat bewijst geen echte publicatietiming: transport-succes en 300 ms wachten garanderen op zichzelf geen nieuwe snapshot. De latere [native publicatieproef](bt-list-publication-draft.md) bevestigt dat Blue alleen zijn eerste record met de actuele profielstatus markeert. Zij koppelt ook de reload/reorder, volledige recordpersistentie en AppMain-list-end voor ieder gekozen apparaat; de complete CSR/HFP-handler en koppeling aan de Sleep-timing zijn nog niet uitgevoerd.

Het progress-object gebruikt zijn echte vtable, inclusief de slot-68-method `12ce18`. Het oorspronkelijke succespad roept die methode en vervolgens `130a70`/de native GUI-cleanup aan. Venster, GDI-handles en parent-popupverwijzing worden in de interpreter opgeruimd. De nav-notificatiehelpers `1143a0` en `114400` zijn native: een ready navigatiemanager ontvangt events `7dc`, `7dd` en `7e2` met parameters nul, nul en één. OS/GDI, navigatie-PostMessage, registry, getters en bepaalde render-/surfacecallbacks blijven hooks.

De aparte `4010506`-dispatcher wist de algemene pogingstatus en roept `1276b0` aan. Bij diens normale lege coördinatorteller verstuurt hij geen nieuwe connect-aanvraag, ook wanneer de succesmelding synthetisch vóór HFP wordt aangeboden.

## Gerepareerde statusverliesfout

Oorspronkelijk negeert `11f7d4` de return van de `1010702`-aanvraag. Zelfs na fout, dubbele timeout of uitgeschakelde gate wacht hij, kopieert een oude snapshot, selecteert de daarin gemarkeerde actieve record en bereikt diens telefoonboekbestand. De baselines herstellen alleen de twee nieuwe callbackblocks; alle andere acht-slot- en verzendwrapperreparaties blijven daarin aanwezig.

De variant bewaart het transportresultaat op `sp+44`, een bestaande descriptorlocal die later voor ander gebruik opnieuw wordt ingevuld. Bij failure wordt niet gewacht en worden copy/actieve scan/phonebook-read overgeslagen. `CBtData+5a4` wordt `ffffffff`; de actieve pointer `+5c0`, phonebookstatus `+5ac` en bijbehorende `STATE+664` worden nul. De bevestigde fysieke HFP-status en profielbit blijven gezet. De zichtbare recordbank wordt in dit foutpad behouden; zij is geen bewezen actuele snapshot.

De oorspronkelijke alternatieve ingang op `11fafc` blijft via een trampoline op diezelfde adrespositie naar de guard gaan. Daardoor krijgt ook het bijzondere call-popup-pad dezelfde controle. Calling-status/registrygedrag op de gewone ingang blijft behouden; twee debugprints vervallen. De bestanden en `.pdata` blijven gelijk en de native routines herstellen frame en opgeslagen registers.

Deze reparatie voorkomt het onjuiste telefoonboekgebruik bij herkende transportfailure in deze callback. Zij introduceert nog geen algemene freshness-versie of herstelprotocol voor latere redraws/list-indications. Een volgende copy van een nog oude shared-bank kan opnieuw een oude actieve record aanwijzen. De latere [IPC/HFP-roundtrip](bt-ipc-roundtrip-draft.md) bevestigt bovendien 64 gekoppelde cases waarin Blue intern de DB-read afwijst, maar OS/wrapper-succes alsnog leidt tot het oude telefoonboekpad. De gewone fixturekind is nu constructorwaarde twee/`8070`; de oorspronkelijke kind-één-cases waren synthetisch. Een transporttimeout bewijst bovendien geen niet-afgeleverd commando.

## Concrete controles

| Controle | Omvang |
| --- | --- |
| HFP-succes → actieve index/pointer/PB-pad → autoconnect-succes | 16 traces: acht posities, navigatie ready/niet-ready |
| Alternatieve copy-ingang met afzonderlijke call-popup | 16 traces: dezelfde indices en nav-varianten |
| Error/dubbele timeout/gesloten gate | 48 voor/na-traceparen: acht posities, beide copy-ingangen, drie foutsoorten; geen PB-read in de variant |
| Timeout gevolgd door geslaagde retry | 16 traces: beide copy-ingangen, alle indices; geldige snapshot wordt wel gekopieerd |
| Synthetisch omgekeerde meldingsvolgorde, lege coördinatorteller | Acht traces: autoconnect-succes vóór HFP, correcte actieve record na HFP |
| Oude helper met niet-lege coördinatorteller | 12 fixtures: counts twee/drie/acht, teller nul tot drie |

Alle OS-transport-/Sleep-/filesystem-/GDI-/PostMessage-hooks overschrijven caller-saved registers. De originele MIPS-instructies verwerken de register- en stackuitkomsten.

## Nog open: oudere autoconnecthelper

`1276b0` wordt in de gevonden directe callgraph alleen vanuit `4010506` aangeroepen. Wanneer HFP-status nog niet één is en `coordinator+18` één of twee bevat, verhoogt hij die teller en kan hij `1010804` met nog één extra indexstap verzenden. Hij vergelijkt de verhoogde teller met `count`, terwijl de uitgezonden index één groter is. De synthetische cases count twee/teller één en count drie/teller twee bereiken zo respectievelijk index drie en vier, buiten de lijst.

De tellerproducer, zijn precieze indexconventie en live bereikbaarheid van die combinatie zijn nog niet vastgesteld. De confirmed-success-emissie in Blue stuurt HFP vóór autoconnect-succes; OS-ordering en andere producers zijn niet bewezen. Daarom is deze oudere helper hier geïnventariseerd en niet blind aangepast. Ook andere profielen, verbonden-profile-switches, volledige phonebookfilesystempaden, simultane meldingen en cachelezers blijven open. De variant is niet verbonden aan de updatebuilder; MAX02 en bronexecutables blijven ongewijzigd.
