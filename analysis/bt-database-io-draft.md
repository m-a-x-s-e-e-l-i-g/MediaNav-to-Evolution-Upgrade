# Bluetooth-database: bytecount en API-status samen controleren

De acht-apparatenvariant bevat nu **concrete reparaties voor bulk-I/O, scannen, lookup, recordwriter en hoger verwijderen**, uitsluitend in interpretergeheugen. De gewijzigde MIPS-instructies zijn gekoppeld gevolgd naar de headercontrole, fread/fwrite en gestubde bestands-API's. Er is geen executable of LGU geschreven en niets op de unit uitgevoerd.

## Gerepareerde contracten

De oorspronkelijke wrappers `860f8` en `860ac` geven alleen de bytecount terug. De variant behoudt die bestaande returnwaarde in `v0` en geeft daarnaast de werkelijke `ReadFile`-/`WriteFile`-BOOL in `v1`. De bestaande argumenten, stackframes en callee-saved registers blijven behouden. Dit voorkomt een algemene wijziging van de betekenis van de bytecount voor andere oorspronkelijke callers.

Blue `7a8a8` accepteert nu uitsluitend een succesvolle read met maximaal het gevraagde aantal bytes en een veelvoud van 104 bytes. Een geldig oud bestand met vijf volledige records blijft dus bruikbaar bij een aanvraag voor acht. Een succesvolle EOF-read van nul bytes betekent een lege recordlijst; een mislukte read met nul bytes wordt geweigerd. De reloadbank is vóór lezen volledig leeggemaakt, zodat een korte oude database geen eerdere tailrecords behoudt.

Blue `7a974` vereist een succesvolle write van exact alle gevraagde bytes. Nul, te weinig, te veel of een mislukte API-call geeft geen succes meer. De status wordt opgeslagen voordat `CloseHandle` wordt aangeroepen; de fixture clobbert `v1` bij close om die afhankelijkheid te controleren.

De interne writerparameter bevat nu het aantal records in de lage byte en de beginindex in de hogere bits. De twee oorspronkelijke directe aanroepers (`3307c` en `7aa40`) gebruiken acht records vanaf index nul. De nieuwe recordwriter geeft één record met een gecontroleerde index nul tot zeven door. Die concrete profielen zijn gecontroleerd; dit is geen algemene boundscheck voor willekeurige parametertokens of een bewijs dat er geen indirecte aanroepers bestaan.

Scanner `7a4d0` onderscheidt een succesvolle EOF-read van nul bytes van API-fouten en gedeeltelijke records. Toevoegen mag pas na een volledige scan een leeg slot of de appendpositie gebruiken. Recordwriter `7a738` wijst een foutresultaat en index acht of hoger af. De oorspronkelijke terugval naar slot nul na een mislukte scan vervalt. Lookup `7a63c` accepteert alleen een volledig record na een succesvolle API-read. De oorspronkelijke BDADDR-vergelijker `3ac90` is daadwerkelijk geïnterpreteerd: byte vijf is padding en telt niet mee als adres.

Het hogere verwijderpad `7ab4c` doet geen voorafgaande write van een leeg record meer. Het zoekt een geldig adres en roept daarna de gecontroleerde compactor aan. Voor ieder bestaand record bij één tot acht apparaten resulteert dit in één write van de compacte bank van 832 bytes. Als de tweede, grotere read faalt, volgt geen write. Er is geen rollback bij fouten tijdens die ene write.

De magiccontrole `7a3d8` accepteert een bestaande header alleen na een succesvolle API-read. Bij een mislukte header-read, ook als de API een bytecount van vier rapporteert, sluit de variant de handle en keert met fout terug. Zij probeert dan niet de header opnieuw te schrijven. Initialisatie na een succesvolle korte/ongeldige header behoudt het oorspronkelijke gedrag: een nieuwe header proberen te schrijven en voor die eerste call nog nul retourneren.

De verbindingscaller `2f5f0` controleert in de variant het lookupresultaat vóór de HFP-verbindingsaanroep `16f68`. Oorspronkelijk gaat hij ook na een readfout door met oude gegevens in de link-keybuffer. De nieuwe guard op `2f728..2f7a4` behoudt de oorspronkelijke failure-reset en berichten `4010507`/`4010504`. Een eerder security-bericht in state vier blijft bestaan; [het commando- en receiveronderzoek](bt-pairing-command-draft.md) beschrijft die beperking.

De code past binnen de bestaande functiegebieden. Prologen en de oorspronkelijke `.pdata` blijven behouden. De Blue-variant omvat samen met de acht-recordopslag, verbindingsguard en [lijstnotificatieguard](bt-list-publication-draft.md) momenteel **385 gewijzigde instructieposities en 1274 gewijzigde bestandbytes**. Dit is nog geen bewijs van volledige native I/O-, unwind-, concurrency- of unitwerking.

## Gekoppelde verificatie

Uitvoeren: `py tools/verify_bt_database_io.py`. [De evidence](firmware/bt-database-io-draft/contracts.json) bevat gepinde bronbereiken, de volledige variant-hash, afhankelijke script-hashes, alle cases en directe aanroepers.

| Controle | Gecontroleerde gevallen |
| --- | ---: |
| Bestaande wrapper-ABI: elementgrootte × aantal en aparte BOOL | 16 |
| Werkelijk gekoppeld reloadpad met nul tot acht fysieke records | 9 |
| Bulk-read: BOOL, EOF, gedeeltelijke records, bovengrens en DWORD-max | 24 |
| Bulk-write: BOOL en exacte lengte | 18 |
| Deletebody weigert ongeldige read vóór schrijven | 6 |
| Deletebody via originele I/O-wrappers: ieder van acht indices | 8 |
| Mislukte header-read herschrijft niets | 2 |
| Bulk-open-/seekfouten | 4 |
| Adres zoeken/lookup: iedere positie, padding, EOF en ontbrekend adres | 51 |
| Eerste lege slot vinden | 8 |
| Recordpaden weigeren header-, open-, seek-, scan- en truncated-tailfouten | 36 |
| Recordwriter: iedere updatepositie, append/capaciteit, lege database en hergebruik van gaten | 26 |
| Recordwriter: BOOL en exacte lengte | 12 |
| Hoger verwijderen: iedere positie bij één tot acht records, één write | 36 |
| Hoger verwijderen: bulk-readfailure en ontbrekend adres, geen write | 6 |
| Oorspronkelijke CSR-caller met gerepareerde databaseketen | 5 |
| **Totaal** | **267** |

De checks volgen zowel `7aa40` als het hogere pad `7ab4c`, inclusief de daadwerkelijke helper-/wrapperketen. Bestands-API's zijn expliciete fixtures met een bestand in geheugen. De geïnterpreteerde routines herstellen hun stack en callee-saved registers en laten geen door de fixture geopende handles achter. Er worden geen echte Windows CE-calls gedaan.

## CSR-persistentie en service discovery

De oorspronkelijke security-caller `c26cc` bouwt een record met BDADDR op `+0`, flags op `+8/+9`, een 16-byte link key op `+a`, naam op `+1a`, device class op `+50` en flags op `+64/+65`. Hij roept `7998c` aan voordat `7a738` schrijft. Dit is met oorspronkelijke callerbytes en de gerepareerde databaseketen gevolgd, inclusief een mislukte write, een korte write en een volle bank.

Dit bericht is **service-discoveryregistratie, geen bewezen GUI-succesmelding**. `8a230` registreert de ontvangende queue als `CSR_BT_SD`; `7998c` verzendt klasse `11e`, type `11`. De oorspronkelijke dispatchtabel op `10e480` verwijst voor alle vier toestanden naar `bdaa0`, die device-liststatus bijwerkt. Tabelbytes en bronbereiken zijn gepind. Het asynchrone receiverpad is niet geïnterpreteerd.

Het record wordt geregistreerd vóór de write en de caller controleert het nieuwe persistence-resultaat niet. De acht-slotwriter voorkomt een negende recordwrite, maar daarmee is de bredere radio-/security-/GUI-afhandeling van een vol of beschadigd bestand niet automatisch opgelost. Er is daarom nog geen nieuwe update gebouwd.

## Wat nog niet opgelost is

Herkennen van een onvolledige write maakt het schrijven niet atomisch. Een API kan eerst een prefix van het bestaande bestand wijzigen en daarna een fout of korte bytecount teruggeven. De variant rapporteert dat nu correct, maar heeft geen vervanging via tijdelijk bestand, rollback, flush-/renamecontract of herstel na stroomverlies. De writertraces beweren daarom expliciet geen rollback.

De gerepareerde recordwriter geeft een persistence-status terug, maar oorspronkelijke callers in GUI-/CSR-paden verwerken die nog niet. Hoger verwijderen blijft een voidpad. Cold database-initialisatie behoudt het oorspronkelijke magic-helpergedrag; atomische headercreatie is niet geïmplementeerd. De volledige terugkoppeling, herstel- en notificatiepaden moeten nog worden gevolgd.

De evidence bevat **41 met oorspronkelijke bytes bevestigde directe JAL-edges** naar de read/writewrappers, lookup-/scanhelpers, recordwriter, deleteadresfunctie en bulkwriter. Die lijst helpt de resterende callers af te werken; zij bewijst geen volledige semantiek of afwezigheid van indirecte callers.

De overige pairingwerkpunten blijven bestaan: indirecte naamcachelezers, daadwerkelijke popupcreatie, volledige reconnect-/verbonden-profilepaden, verloren verzendstatus, allocatie/lifetime, radio-capaciteit en unitvalidatie. Lijstweergave, paginaknoppen en de bevestigingsketen voor inactieve profielen hebben inmiddels concrete gekoppelde fixtures. De variant is uitgesloten van de LGU-builder. MAX02 is de bestaande aparte kandidaat met playback- en navigatiefix.
