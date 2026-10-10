# Bluetooth-lijst: echte IPC-routering en verloren database-status

Uitvoeren: `py tools/verify_bt_ipc_roundtrip.py`. [Evidence](firmware/bt-ipc-roundtrip-draft/contracts.json) bevat bronbereiken/hashes, actuele patchhashes, 15 constructor/request/receivertraces en 80 HFP-snapshottraces. Er is geen nieuwe firmwarepatch toegevoegd: de bestaande acht-slotvarianten worden in byte-interpreters uitgevoerd. Geen executable, LGU, CE-proces of radio is uitgevoerd of geschreven.

## Constructor en receiver

De oorspronkelijke AppMain-getter/constructor `11b39c` alloceert 48 hex bytes, initialiseert het managerobject en zet diens `+14` op **twee**. `11b464` kiest daarom `8070` als Windows-bericht-ID. De native windowhelper zoekt class `BLUE`; allocatie, HWND en OS-transport blijven hooks. Blue's oorspronkelijke `33d34` decodeert `8070` naar de vijfwoord-envelope, `31634` kiest module één en `30f08` dispatcht `1010702` naar `2fec4`. Die route is nu daadwerkelijk geïnterpreteerd, inclusief de geladen jump-tablebytes.

De eerdere gewone reconnect/HFP/bevestigingsfixtures gebruikten kind één als synthetische uitgangswaarde. Zij gebruikten dus `8065`; dat was geen bewijs van de normale constructorroute. De gewone fixtures gebruiken nu constructorwaarde twee/`8070`. Andere kinds blijven expliciete routingfixtures. De oorspronkelijke retry van `11b464` valt alsnog terug op `8065`; de bestaande draft-wrapperreparatie bewaart `8070`. De reconnect-baseline herkent beide daadwerkelijke originele routes. Een afzonderlijke native Blue-WndProc-proef laat zien dat `8065` met `1010702` zonder GUI/list-hooks wordt genegeerd en nul retourneert. Hiermee is de praktische betekenis van het verkeerde retry-ID concreter bewezen.

Blue's eigen verzendmodus één is anders: WM_CREATE roept `3337c` met index één aan; die schrijft zijn mode op `110cf0`. Daardoor ontvangen bestemming twee en drie respectievelijk `8066` en `8067`. AppMain-managerkind en Blue-bestemmingsindex zijn verschillende waarden.

## Nul onderscheidt logisch succes en failure niet

| Punt | Huidig gevolgde gedrag |
| --- | --- |
| Blue `3307c` | Eén bij volledige reload/publicatie; nul bij herkende DB-fout |
| Blue `2fec4` | De bestaande draft-guard onderdrukt oude countmelding bij reloadfailure; succesvol vervolg eindigt via verzendhelper met nul |
| Blue `30f08` | Epiloog `311b4` maakt v0 nul |
| Blue `31634` | Epiloog `3170c` maakt v0 nul |
| Blue `33d34` | Normale ontvangen berichten eindigen via `33f68` met nul |
| AppMain `11b464` | Bewaart receiver-LRESULT op `sp+20`, maar gebruikt het niet; OS-transport-succes wordt nul |

De 15 traces combineren databases nul/vijf/acht met success, headerfailure, API-BOOL false bij volledige bulktransfer, een gedeeltelijke bulkread en seek-failure. Alle OS-aanvragen kunnen succesvol terugkeren met receiver-LRESULT nul en wrapperstatus nul. Alleen de daadwerkelijk gepubliceerde records/notificaties maken in de proef zichtbaar of de database is vernieuwd. LRESULT alleen doorgeven zonder de ontvangende keten te wijzigen lost dit dus niet op.

## Gevolg in de HFP-callback

80 gekoppelde traces combineren acht gekozen adressen, gewone/alternatieve HFP-copy-entry en vijf database-uitkomsten. De Blue-database begint met het gekozen adres vooraan: dat is een expliciete fixture voor de reeds elders geïnterpreteerde reorder, geen uitvoering van de volledige CSR-HFP-handler in deze proef.

Bij de 16 geldige cases publiceert de native Blue-keten records vóór beide lijstmeldingen. Iedere fixturemelding voert AppMain's native `121630`, recordcopy en actieve-pointerselectie uit in een tweede interpreter met gedeelde geheugenbytes en een afzonderlijke fixturestack. De onderbroken HFP-interpreter behoudt zijn eigen registers/frame/bericht. Daarna maken de native HFP- en phonebookhelpers het juiste bestandsadres, ook voor oorspronkelijk apparaat acht. Sleep verzint hierbij geen publicatie.

Bij 64 interne DB-failurecases verstuurt Blue dankzij de vorige guard geen lijstmelding en blijft de shared-bank oud. Het OS meldt echter succesvolle requestafhandeling. De HFP-callback wacht 300 ms, kopieert de oude actieve record en opent het oude telefoonboekpad `1200-40-000001.pbd`. De fysieke HFP-status blijft één. De huidige transportguard in de callback herkent deze **logische** failure niet. Dit is nu gekoppelde, reproduceerbare evidence voor de resterende freshnessfout.

Het veld `STATE+628` is geen zelfstandig freshnessbewijs. De oorspronkelijke `4010504`-dispatcher zet het bij parameter nul ook op één, zonder lijstpublicatie. Die volledige dispatcher-entry is afzonderlijk geïnterpreteerd. Alleen dat veld voor de aanvraag wissen en daarna lezen kan daarom een onterechte bevestiging geven.

De OS-aanvraag en geneste callbacks zijn expliciete synchrone transportfixtures. Dit bewijst geen CE-scheduler, thread-ordering, reentrancy, locking of snapshotlifetime. Redraw, bepaalde getters/debug, ontbrekende phonebookbestanden en de extra `1041401`-profile-query blijven API/receiverhooks. De complete CSR-entry en radio zijn niet uitgevoerd.

## Vereisten voor de volgende reparatie

De lijstaanvraag heeft een herkenbare bevestiging van een geslaagde DB-read/publicatie nodig, inclusief het actuele aantal records nul tot acht. Die informatie moet behouden blijven tot de HFP-callback. Het aantal is nodig omdat lijstnotificaties zelf kunnen mislukken; alleen een BOOL-ack kan dan naast een nieuwe shared-bank nog een oude AppMain-count laten staan. Alle normale andere berichtreturns moeten hun bestaande gedrag houden, en OS-timeout/retry mag niet als bewijs van niet-afgeleverde request worden gebruikt.

Een [afzonderlijke interpreterproef](bt-list-ack-draft.md) implementeert inmiddels een uitsluitend voor `1010702` gedefinieerde LRESULT-signature met count, door Blue's ontvangende keten en een opt-inargument van de AppMain-wrapper verwerkt. Zij controleert normale commandoretours, countvalidatie, lege lijst, notificatiefailure, verkeerde message-ID, gesloten gate en ontbrekende/ongeldige acknowledgement. De hierboven beschreven basisvariant en haar traces blijven ongewijzigd. Een welgevormde stale ACK wordt ook in de nieuwe proef geaccepteerd: generatie, snapshotlocking en CE-scheduling zijn niet bewezen. Dit vervangt evenmin atomische databasewrites. Naamcache-aliases en live-unitvalidatie blijven releasevoorwaarden; de proef schrijft geen executable of LGU.
