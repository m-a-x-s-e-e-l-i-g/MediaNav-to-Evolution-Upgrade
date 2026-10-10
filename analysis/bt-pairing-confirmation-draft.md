# Bluetooth-popupbevestiging en adresfout bij het laatste apparaat

De acht-apparatenvariant is nu offline gevolgd vanaf saved-listklik, via native popup-initialisatie en bevestiging, naar AppMain's manager en verzendwrapper. Een bestaande fout in de adreshelper is gerepareerd in interpretergeheugen. Er is geen executable of LGU geschreven en geen Windows CE-, radio- of filesystemactie uitgevoerd.

Uitvoeren: `py tools/verify_bt_pairing_confirmation.py`. [Evidence](firmware/bt-pairing-confirmation-draft/contracts.json) bevat gepinde oorspronkelijke functies, de AppMain-variant-hash, vijf oorspronkelijke directe helpercallers en de traces.

## De bestaande indexfout

`1109d4` heeft twee gebruiksprofielen. Mode nul geeft de zichtbare naam, met een zero-based recordindex. Mode één maakt een adres met streepjes voor de telefoonboekbestandsnaam. De enige gevonden directe mode-één-caller, `12ddf0`, geeft een one-based deleteindex door. Vier andere directe callers gebruiken mode nul; hun mode-instructies en JAL-woorden zijn met de originele bytes gecontroleerd.

Oorspronkelijk gebruikt de helper voor beide profielen de grens `index < count`. In mode één leest hij vervolgens het adres één record terug. Voor de laatste deleteindex, gelijk aan het aantal records, geeft hij daarom **Empty** terug. Bij vijf records raakt dit apparaat vijf; bij acht records raakt het apparaat acht. De Bluetooth-deleteparameter blijft wel de juiste one-based index. De fout zit in de adreswaarde voor telefoonboekopruiming. Bij slechts één apparaat gebruikt de bevestigingshandler een apart all-deletepad en bereikt hij deze helper niet.

De variant normaliseert een mode-één-index eerst naar nul, controleert de grens en leest vervolgens het adres uit dat record. Index nul in mode één wordt geweigerd. Mode nul behoudt zijn bestaande indexconventie. Mode één scant geen naam uit het volgende record meer. De oorspronkelijke proloog, epiloog, stackcookie en `.pdata` blijven behouden.

288 oorspronkelijke/gewijzigde helpertraceparen behandelen nul tot acht records, namen of lege namen, beide modes, grensindices en twee grote DWORD-indices. De oorspronkelijke helper wijkt in 32 cases af van dit contract; de variant heeft nul afwijkingen. De UTF-8-converter en adresformatter zijn expliciete fixtures die de originele formatstrings en alle adresargumenten controleren. Dit bewijst geen algemene malformed-inputveiligheid: onder meer een naam zonder terminator en willekeurige recordcounts blijven buiten deze contracten.

## Bevestiging en verzenden

144 traces behandelen alle geldige indices bij één tot acht apparaten, zowel verbinden als verwijderen, met diverse namen én met acht identieke namen. Zij hergebruiken de descriptor die de oorspronkelijke list-clickroutine aanbiedt. De oorspronkelijke popup-initializer `12db94` zet die velden zelf op de offsets die `12ddf0` bij bevestiging leest; deze mapping wordt niet door Python vervangen.

Voor verbinden worden `11589c`, de key-resethelper `11a8f4`, de naam-/adreshelper, copy, actieve scan, phonebookroutine en `11b464` gevolgd. De key-reset verstuurt eerst `1030403` met de recordkey in de hoge 16 bits. De phonebookfixture heeft geen actieve recordpointer, waardoor de oorspronkelijke reader zijn lege pad neemt. De naamvergelijking onderzoekt de records tot de geselecteerde index; een identieke naam op een andere index leidt niet tot het verkeerde commandoparameter. Het latere `1010804` draagt steeds de juiste one-based index. De manager maakt vooraf een voortgangspopup met pagecode `1010804`, geen positieve actiecommand, en timeout 45 seconden.

Voor verwijderen bij twee of meer apparaten bereiken het juiste adres en de bestandsnaam `\Storage Card2\PB\<adres-met-streepjes>.pbd` de native cleanup-routine `111a30`. De `FindFirstFileW`-fixture meldt dat het bestand ontbreekt; daadwerkelijk verwijderen en de success-branch zijn hier niet uitgevoerd. Daarna volgt `1010701` met de juiste index. Bij één apparaat voert de native `11679c` zijn all-deletepad uit en verzendt `1010704` met parameter nul. Disconnect en complete phonebookopruiming in dat pad zijn expliciete hooks.

De native verzendwrapper `11b464` en windowhelper `1144b4` worden geïnterpreteerd. `SendMessageTimeout`, windowlookup, timers, tekstconversie, popupcreatie en widgets zijn fixtures. Dit is een concrete softwareketen tot aan het OS-verzendpunt, geen op de unit gemeten Bluetooth-verbinding.

## Wrapper en disconnected-connectcaller gerepareerd

40 extra verbindingstraces behandelen voor alle acht indices een uitgeschakelde verzendgate, twee reset-timeouts achter elkaar, een andere reset-verzendfout, en afzonderlijk een succesvolle reset met twee connect-timeouts of een connect-error. De wrapper wordt daarna rechtstreeks herhaald om zijn eigen returnwaarde te controleren. 40 baselines herstellen uitsluitend de oorspronkelijke callerblocks in dezelfde acht-slotvariant, zodat de reparatie los van de overige wijzigingen wordt vergeleken.

De oorspronkelijke wrapper retourneerde nul na beide OS-foutsoorten. De [verzendwrapperreparatie](bt-send-status-draft.md) geeft nu `ffffffff` na fouten en behoudt het eerste bericht-ID tijdens retry. Dat wordt afzonderlijk met 40 oorspronkelijke/gewijzigde traceparen gecontroleerd. De gekoppelde managerproef voegt 216 routing-/retrycases toe met synthetische managerkindwaarden en meerdere niet-nul-OS-succeswaarden.

Bij gate `STATE+6d4=0` wordt niets verzonden. Bij een OS-timeout volgt windowlookup en één retry. Bij een andere OS-fout volgt geen retry. De gewijzigde verbindingscaller stopt nu na een failed key-reset, zonder voortgangspopup of latere connect-aanvraag. Mislukt alleen het connectcommando, dan wist hij de pending-state en sluit hij het voortgangsvenster via de oorspronkelijke `130a70`. De statuswrites vóór beide OS-calls behouden hun bestaande volgorde. Alle transporthooks overschrijven caller-saved registers.

De fixture gebruikt nu afzonderlijke confirmation- en progress-objecten. De daadwerkelijke progress-vtable `17b12c`, singleton-getter `12c10` op het reeds geïnitialiseerde pad, close `130a70`, cleanup `1362c4`/`1356a8`, basiscallback `134c50` en post-close `12d294` worden gevolgd. De native cleanup stopt timer `43b`, geeft GDI-handles vrij, vernietigt het venster, wist de parent-popupverwijzing en activeert de parent. OS/GDI, surface-cleanup, parent-callbacks en popupcreatie blijven expliciete hooks. De echte constructor, nested popups en parent-redrawtak zijn niet uitgevoerd. Een OS-timeout betekent bovendien niet dat de radio het commando niet al ontving; deze wijziging bewijst geen radio-rollback.

Verbonden-profile-switches/disconnect, volledige reconnect, daadwerkelijke popupcreatie, OS/radio-uitkomsten, lege namen in de volledige klik-/bevestigingsketen, indirecte cachelezers en atomische Bluetooth-databasepersistentie blijven open. De helperreparatie is onderdeel van de geheugenvariant; MAX02 en de originele executables blijven ongewijzigd.
