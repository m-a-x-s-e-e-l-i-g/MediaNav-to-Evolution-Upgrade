# Acht Bluetooth-apparaten: selectiecommando's en fouten bij verbinden

De acht-apparatenvariant bereikt offline alle acht juiste adressen via de oorspronkelijke Blue GUI-dispatcher. Er is ook een concrete lookupguard toegevoegd: een mislukte database-read mag de HFP-verbindingsaanroep niet bereiken met oude sleutelgegevens. Alle bytes blijven in interpretergeheugen; er is geen executable, nieuwe LGU of unitmeting.

## Blue-commando's

Uitvoeren: `py tools/verify_bt_pairing_commands.py`. [Evidence](firmware/bt-pairing-command-draft/contracts.json) bevat bronbytes, hashes, patchhash en traces.

De oorspronkelijke `30f08` dispatcht `1010804` naar verbinden (`2f5f0`) en `1010701` naar verwijderen (`2ff30`). De shared-pointerhelper, one-based recordkeuze, beide adressetters, failure-reset en security-messageconstructie worden geïnterpreteerd. De databaseketen gebruikt de gepatchte scanner, lookup, compactor en bestandswrappers. HFP-connect, CSR-enqueue en OS-API's zijn expliciete fixtures.

| Controle | Gevallen |
| --- | ---: |
| Verbinden en verwijderen, elke geldige index bij één tot acht records | 72 |
| Header-, read-BOOL-, incomplete-readfouten, inclusief alle acht deleteindices | 40 |
| Oorspronkelijke connectcaller negeert mislukte lookup | 8 |
| Lookup slaagt, HFP-connect faalt: oorspronkelijke reset/berichten behouden | 8 |
| State vier: security-request vóór lookup, met/zonder readfout | 16 |

De acht oorspronkelijke fouttraces herstellen alleen de oude connectcaller in de variant. Zij zijn dus een baseline van die caller met de gerepareerde databasehelpers, geen uitvoering van de volledige oorspronkelijke Blue.

Bij succes ontvangen beide native adresvelden het gekozen acht-byte BDADDR en bevat de sleutelbuffer exact het juiste 104-byte record. Bij lookupfouten blokkeert de guard HFP-connect; de bestaande failure-reset en beide meldingen blijven behouden. Bij een HFP-failure na een geldige lookup worden diezelfde foutmeldingen verstuurd.

Succesvol verwijderen schrijft eenmaal de volledige compacte bank van 832 bytes. Bij een readfout verandert het bestand niet. **De hogere deletecaller verstuurt ook dan nog SC primitive `2` en past de verbindingsstate aan.** Statuspropagatie van persistence naar radio/GUI is daarmee nog niet opgelost. Fixtures gebruiken inactieve HFP/A2DP-profielen; delete terwijl een profiel verbonden is blijft open.

## Het eerdere security-bericht in state vier

Voor lookup verstuurt `2f5f0` in state vier een SC-bericht met type `c`, geselecteerd BDADDR, destination uit `218638` en byte `+c=0`. De lookupguard staat na deze stap. Hij voorkomt de HFP-aanroep bij een fout, maar maakt het eerdere bericht niet ongedaan.

Uitvoeren: `py tools/verify_bt_security_cancel.py`. [Receiver-evidence](firmware/bt-security-cancel-draft/contracts.json) volgt 48 concrete cases en acht persistence-failures. De oorspronkelijke signed-halfwordtabel `bb84c` stuurt type `c` naar `bbbe4`. SC-state twee kiest `c53f0`; andere states kiezen `c4924`.

`c53f0` vergelijkt het adres, de destination en fasebyte `+13d=1`. Als alle drie overeenkomen, bouwt `c4870` een bericht `218` met hetzelfde adres, zet twee contextbytes op nul en fase `+13d` op twee, en roept cleanup-/responsehelpers aan. Hun interne gedrag is hier niet geïnterpreteerd.

Anders doorloopt `c4924` de pending queue. Met een bijpassend klasse-`102`/type-`1`-bericht wordt dat bericht vrijgegeven. Daarna roept de routine service-discoveryregistratie, response en cleanup aan, en verwijdert het actieve contextadres via `7ab4c`. De fixture volgt die delete met de gepatchte databaseketen voor alle acht indices. Ook als de deletescanner faalt, zijn de eerdere helperaanroepen al uitgevoerd. Een lege pending queue geeft geen databasewrite.

Dit past bij een conditioneel annuleringspad, maar een radio-uitkomst is niet bewezen. Queue-operaties en de genoemde profile-/responsehelpers zijn expliciete hooks. Receiverfixtures staan los van de senderfixtures; er is geen asynchrone scheduler, gecombineerde race- of end-to-endverbindingstest. Andere pending messageklassen, niet-matching requests en de volledige helperimplementaties blijven open.

## Resterende integratie

De [AppMain-bevestigingsketen](bt-pairing-confirmation-draft.md) is inmiddels gevolgd tot het OS-verzendpunt voor alle acht indices, ook bij identieke namen. Dat onderzoek repareert een adresfout in telefoonboekopruiming bij het laatste apparaat en reproduceert verloren verzendstatus. Verbonden-profile-switches, reconnect, naamcache-aliases, persistence-foutmelding, atomisch schrijven en native lifetime moeten verder worden gecontroleerd. De storage-, UI- en commandoproeven bewijzen elk hun concrete pad; zij maken samen nog geen op de unit geteste acht-apparatenupdate. Deze variant zit niet in MAX02.
