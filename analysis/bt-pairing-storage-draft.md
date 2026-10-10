# Acht koppelingen: opslag- en UI-prototype in interpretergeheugen

De uitbreiding is verder dan een limieteninventarisatie: er zijn nu **concrete, gepinde wijzigingen voor Blue en AppMain**, met offline traces over de gewijzigde instructies. De bytes bestaan uitsluitend in Python-/interpretergeheugen. Er is geen executable of nieuwe LGU geschreven en deze variant is niet gekoppeld aan de updatebuilder. **Dit is nog geen complete of op de unit geteste acht-apparatenupdate.**

## Wat de variant verandert

De Blue-databasebank verhuist naar `CDeviceManager+300..+640`, met acht records van 104 bytes. De twee gevonden allocatiepaden krijgen respectievelijk `0x640` bytes voor de losse manager en `0x650` voor de parent met de manager op `+10`. De oude statusvelden blijven op hun bestaande offsets. Initialiseren, herladen en vooraan zetten gebruiken de nieuwe bank.

De deletebuffer past in een vergroot stackframe van `0x3d0`. De stackcookie en opgeslagen registers houden hun oorspronkelijke offsets ten opzichte van de caller-SP. De oorspronkelijke `.pdata` blijft byte-identiek; de oorspronkelijke GS-helper is geïnterpreteerd met de cookie op de oude en nieuwe framelocatie. Dit bewijst de cookie-adressering in de bekeken helper; kernelunwind en native exceptionafhandeling zijn niet uitgevoerd.

Het deletepad controleert nu het bulk-readresultaat en weigert indices buiten nul tot zeven voordat het de compacte lijst terugschrijft. Het reloadpad maakt alle acht slots leeg vóór lezen, zodat een bestaande kortere database geen oude tailrecords overhoudt. Het controleert ook het geretourneerde resultaat van de reorder-write. De I/O-, scanner-, lookup-, recordwriter- en hogere deletepaden hebben inmiddels een [gekoppeld gecontroleerde reparatie](bt-database-io-draft.md); callerstatuspropagatie en atomisch herstel blijven open.

Het gedeelde mediarecord voor one-based index acht eindigt exact op offset `0x500`, vóór de zoekbank. De strikte vergelijking wordt in de variant aangepast zodat die complete laatste slot mag worden geschreven; index negen blijft buiten de bank.

De AppMain-variant kopieert acht records en laat de overlappende cacheconversie weg. De records lopen dan tot `+470`; velden vanaf `+5a4` behouden hun bestaande adressen. De native weergavehelpers die tot nu toe gevolgd zijn, lezen de UTF-8-namen rechtstreeks uit de records. Het onderzoek naar directe `+3b0`-adresvormen vindt binnen de dataklasse alleen constructor-zero, cacheconversiedestination en reset-zero. De [uitgebreide provenance-/lifetimeanalyse](bt-data-cache-lifecycle.md) volgt 2.910 bereikentries en zeven exacte cache-events, maar houdt 291 onbekende-offsetevents en computed-call/jumpgaten open. **Dat is nog geen bewijs dat alle indirecte naamcachelezers ontbreken.** Daarom mag de cachevariant nog niet in een pakket komen. Het vervolg reproduceert ook hoofd-/bufferallocatiefouten, ontbrekende shared-bank en destructorherintreding met oorspronkelijke bytes.

Toevoeg-/volmeldinggrenzen en gevonden checks van de actieve index worden op acht afgestemd. De [reconnectvariant](bt-reconnect-draft.md) verwerkt inmiddels beide timers: de algemene pogingsteller bereikt acht, het aparte terugvalpad probeert ieder ander opgeslagen apparaat eenmaal, en transport-/timerfouten stoppen de poging. Ook de aparte actieve-recordscan `111d84`, die oorspronkelijk na vijf shared records stopt, zoekt nu acht slots. De vier fysieke schermregels en het resetten van de pagina onder vijf records blijven behouden. De totale lijst bevat maximaal acht records, over twee pagina's.

## Concrete offline resultaten

Uitvoeren: `py tools/verify_bt_pairing_storage.py`. Bronhashes, originele bereiken, patchpreimages, afhankelijke script-hashes en alle traces staan in [de evidence](firmware/bt-pairing-storage-draft/contracts.json).

| Controle | Resultaat en bereik |
| --- | --- |
| Herladen, vooraan zetten, verwijderen en opnieuw herladen | 81 traces; aantallen nul tot acht, iedere geldige selectie/verwijdering, volledige 104-byte payloads behouden |
| Open-/seekachtige readfailure en ongeldige deleteindex | Zeven traces; geen write, stackcookie gecontroleerd, frame/registers hersteld |
| Leegmaken van nieuwe Blue-bank | Alle 832 bytes nul, aangrenzende sentinel intact |
| UI-kopie en actieve koppeling | 45 traces; iedere actieve index bij nul tot acht records, exacte UTF-8-recordbytes inclusief diverse schriftsoorten |
| UI-paginatotaal | 20 traces; nul tot negen ontvangen records, twee initiële paginawaarden, maximaal acht records en vier regels per pagina |
| Oude/korte database na eerder acht records | Vier traces: nul, één, vijf of zeven fysieke records; oude tail gewist en correct nieuw totaal |
| Oorspronkelijke bulk-I/O-status | 14 traces reproduceren foutief succes bij nul, incomplete en volledige transferlengtes |
| Gekoppelde copy → lijstweergave, klik en pagina | 242 traces; namen, actieve indices, draw=1/reload, selectie-/deletepopups en paginaknoppen |
| Aparte actieve-recordscan | Negen oorspronkelijke/gewijzigde traceparen; oorspronkelijke vijf-slotgrens en juiste pointer/index voor slots vijf tot zeven aangetoond |
| Blue selecteren/verwijderen vanaf GUI-commando | 72 geldige commando's, 40 readfouten, acht oorspronkelijke foutbaselines, acht HFP-failures en 16 state-4-traces; zie [commando-evidence](bt-pairing-command-draft.md) |

De Blue-variant wijzigt inclusief de I/O-reparatie, connect-lookupguard en [lijstnotificatieguard](bt-list-publication-draft.md) 385 instructieposities en 1274 bestandbytes, uitsluitend binnen gepinde codebereiken. AppMain wijzigt inclusief de [adreshelperreparatie](bt-pairing-confirmation-draft.md), [verzendwrapperreparatie en connectcaller-guards](bt-send-status-draft.md), [reconnecttimers](bt-reconnect-draft.md) en [HFP-lijstaanvraagguard](bt-connection-success-draft.md) 345 instructieposities en 1113 bestandbytes. Bestandlengtes, oorspronkelijke `.pdata` en bronbestanden blijven gelijk. De Blue- en AppMain-varianten zijn nog niet gecombineerd met MAX02; alleen hun afzonderlijke offline werking is bekeken.

### Gekoppelde namen- en paginaverificatie

Uitvoeren: `py tools/verify_bt_pairing_ui.py`. [De evidence](firmware/bt-pairing-ui-draft/contracts.json) volgt de gewijzigde `110708` en vervolgens de oorspronkelijke volledige lijstweergaveroutine `cfcb8`, inclusief diens gewijzigde active-indexgrenzen. De Unicodeconverter, widgets en drawing-API's zijn expliciete fixtures; de instructies voor recordindex, paginabereik en tekstbron worden geïnterpreteerd.

74 traces behandelen één tot acht records, iedere bestaande pagina en iedere actieve index of geen actieve koppeling. De renderer geeft de exacte UTF-8-bronnen en correcte namen door aan vier vaste labelposities. Op pagina twee komen de records vijf tot en met acht aan bod; accenten, Grieks, Japans en Cyrillisch blijven in de fixtures behouden. 48 extra traces volgen `draw=1` bij acht records, beide pagina's, iedere actieve index en status 0/4/7. Daarbij wordt de recordbank opnieuw gekopieerd en herstelt de routine de actieve status zonder andere recordbytes te veranderen.

72 extra traces volgen de oorspronkelijke saved-listklikhandler `cf77c` naar connect- of deletepopup voor iedere geldige index bij één tot acht records. De connectpopup draagt de juiste one-based index, terwijl de selectiestate de zero-based index bewaart. 48 traces volgen vorige/volgende pagina, wrap en een genegeerd knopargument. De oorspronkelijke `d08b0` verzorgt paginatotaal en zichtbaarheidsbits; de formatfixture controleert de oorspronkelijke PE-formatstrings `%d/%d` en `%s` vóór formatteren. De shared-pointerhelper `11afcc` wordt geïnterpreteerd, met een geldige gemapte bank.

Negen traceparen volgen `111d84`: oorspronkelijk blijven actieve slots vijf tot zeven ongevonden; de basisvariant geeft de juiste recordpointer en index. Zonder actieve record blijft ook in de basisvariant de eerdere pointer staan. De [afzonderlijke ACK-proef](bt-list-ack-draft.md) begrenst deze scan inmiddels tot het actuele aantal en wist ontbrekende/ongeldige actieve verwijzingen; die wijziging is niet in de hierboven beschreven basisvariant geïntegreerd.

De [popupbevestigingsproef](bt-pairing-confirmation-draft.md) voegt 144 gekoppelde klik-/init-/bevestiging-/verzendtraces toe, inclusief identieke namen. De gerepareerde naam-/adreshelper heeft 288 oorspronkelijke/gewijzigde traceparen, ook met lege namen. 40 verzendfouttraces met 40 callerbaselines bevestigen nu afbreken na resetfailure en opruimen na connectfailure in het disconnected-connectpad.

De [HFP-succesproef](bt-connection-success-draft.md) volgt inmiddels ook de dispatcher, actieve-recordselectie, adresgebonden phonebook-read en native progress-cleanup voor alle acht posities. Een failed lijstaanvraag wist daar oude actieve/PB-verwijzingen in plaats van de oude snapshot te lezen; latere snapshotfreshness en herstel blijven open.

Dit is geen pixelrendering of native Windows CE-test. Het bewijst de gevolgde concrete copy-/lijst-/klik-/bevestigings-/HFP-paden, niet alle UI- of cachelezers. Lege namen in de volledige keten, verbonden-profile-switches, volledige reconnect/scheduler, NULL shared pointer, lifetime en echte Unicode-API-uitkomsten blijven open.

## Nieuw gevonden I/O-probleem

Blue `7a8a8` en `7a974` rapporteren één zodra openen en seek lukken. Zij negeren de werkelijke bytecount uit `860f8` respectievelijk `860ac`. Die wrappers geven de `ReadFile`-/`WriteFile`-bytecount terug en negeren zelf de BOOL-uitkomst. De oorspronkelijke hogere helper meldt daardoor succes voor bijvoorbeeld nul, één of 831 bytes bij een verzoek van 832 bytes.

Dit gedrag is met oorspronkelijke bytes gereproduceerd. De huidige variant bewaart nu ook de API-BOOL en controleert recordlengtes, scans en schrijftokens; 267 gekoppelde checks slagen. Hoger verwijderen schrijft nog maar één keer; een scanerror kan niet meer tot overschrijven van slot nul leiden. De oorspronkelijke fouttraces blijven als baseline behouden. Callerstatuspropagatie en herstel van reeds gedeeltelijk geschreven bestanden zijn nog niet afgerond. Er is niets naar een echte database geschreven.

Voor correcte migratie moet een geldig bestand met minder dan acht volledige records kunnen blijven werken. De variant accepteert nu volledige korte recordreeksen na een succesvolle read-BOOL, wijst gedeeltelijke records af en vereist bij write de volledige lengte. Ook de magiccheck weigert een mislukte header-read. De resterende callers die read/writefouten verliezen moeten verder gevolgd worden. Atomisch schrijven/herstel na stroomverlies blijft apart open.

## Nog nodig vóór een gecombineerde kandidaat

1. De hogere pairing-/deletecallers op het nieuwe persistence-resultaat laten reageren; opslag, scan en verwijderen zijn nu offline gekoppeld gecontroleerd. Atomische write/recovery blijft nodig.
2. De naamcache-aliases, lege namen in de volledige keten, verbonden-profiledelete en volledige reconnectpaden voor apparaat acht controleren. De AppMain-verzendstatus ook door overige callers laten verwerken; reset/connectfailure in het disconnected-connectpad is inmiddels offline gerepareerd.
3. Beide allocatie-/lifetimepaden, stackunwind en radio/stack-capaciteit verder toetsen; native unitvalidatie blijft benodigd.
4. De pairingvariant met de playbackpatch samenstellen, gezamenlijke regressies uitvoeren en daarna een nieuwe LGU bouwen en onafhankelijk uitpakken.

MAX02 en de bekende navigatiefix blijven de bestaande artefacten. Er is nog geen MAX03 of flashactie.
