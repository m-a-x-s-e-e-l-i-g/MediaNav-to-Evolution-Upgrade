# AppMain: verzendfout en verkeerd bericht-ID bij retry

De acht-apparatenvariant bevat nu een concrete reparatie voor de native verzendwrapper `11b464`. Mislukte OS-verzendingen geven `ffffffff` terug; succesvolle verzendingen blijven nul retourneren. Een timeoutretry behoudt het bericht-ID van de eerste poging. Dit zijn wijzigingen in interpretergeheugen, geen nieuw executablebestand, firmwarepakket of unituitvoering.

Uitvoeren: `py tools/verify_bt_send_status.py`. [Evidence](firmware/bt-send-status-draft/contracts.json) bevat oorspronkelijke bytes, patchhash, 40 oorspronkelijke/gewijzigde traceparen en 152 met bronwoorden gecontroleerde directe JAL-edges naar de wrapper.

## Oorspronkelijke fouten en reparatie

Bij een positieve commandcode en een actieve gate kiest de oorspronkelijke wrapper voor managerkind één bericht-ID `8065`. Voor andere waarden gebruikt hij `kind + 806e`. Als `SendMessageTimeout` nul geeft, leest hij de OS-fout. Alleen bij `578` volgt windowlookup en een tweede poging. Die tweede poging gebruikt oorspronkelijk altijd `8065`, ongeacht het eerste ID.

Daarnaast retourneert de oorspronkelijke wrapper nul na iedere bereikte OS-verzendpoging, ook bij een andere fout dan timeout en bij twee mislukte pogingen. Alleen een ongeldige commandcode of gesloten verzendgate geeft oorspronkelijk `ffffffff`.

De variant bewaart het gekozen bericht-ID in het oorspronkelijk opgeslagen callee-saved register `s4`. Ook de retry gebruikt dat ID. Een niet-timeoutfout en een mislukte tweede poging verlaten de wrapper met `ffffffff`. Een willekeurige niet-nul-OS-returnwaarde geldt als transport-succes en leidt tot de bestaande returnwaarde nul. De oorspronkelijke gate, timeout van 1500 ms, command-/parameterwaarden, stackframe, proloog, epiloog en `.pdata` blijven behouden. De overbodige tweede GetLastError-read na een failed retry vervalt.

Nul betekent hier alleen dat de OS-verzendcall slaagde. Het zegt niets over het uitvoeren van het commando door Blue, CSR of de radio. De receiver-LRESULT uit de outpointer wordt niet doorgegeven. De latere [constructor/receiver-roundtrip](bt-ipc-roundtrip-draft.md) volgt nu de gewone kind-twee/`8070`-route en bevestigt dat Blue bij logische databasefailure eveneens nul retourneert; alleen LRESULT bewaren is daarom nog onvoldoende.

## Concrete verificatie

De 40 traceparen combineren managerkindwaarden nul, één, twee en drie met OS-succeswaarden één, twee en `ffffffff`; gewone fout; dubbele timeout; succes bij de retry; gesloten gate; ontbrekend venster; en commandcode nul. De alternatieve managerkindwaarden zijn synthetische wrapperfixtures, geen bewezen inventarisatie van fysieke rollen op de unit.

De originele windowhelper `1144b4` wordt geïnterpreteerd. FindWindowW, SendMessageTimeout en GetLastError zijn expliciete hooks. Zij overschrijven alle caller-saved registers om afhankelijkheid van onbewaarde waarden te controleren. De receiver-outwaarde krijgt bewust `aabbccdd`; die bepaalt de transportstatus niet. Iedere routine herstelt frame en callee-saved registers. Oorspronkelijke foutreturns en de oorspronkelijke gewijzigde retryroute blijven als baselines zichtbaar.

De [gekoppelde popup-/managerproef](bt-pairing-confirmation-draft.md) controleert daarnaast 144 gewone bevestigingspaden, 40 verzendfoutpaden met 40 baselines en 216 routing-/retrytraces tot het OS-punt. De eerdere key-resethelper `11a8f4` wordt daarin met oorspronkelijke bytes uitgevoerd: een verbindingsactie verstuurt eerst `1030403` met de recordkey in de hoge 16 bits, en daarna `1010804` met de one-based deviceindex.

## Verbindingscaller gerepareerd; overige callers open

De variant controleert nu beide returns binnen het disconnected-connectpad van `11589c`. Een failed key-reset stopt vóór de voortgangspopup en de connect-aanvraag en wist `+5fc` en `+624`. Na een failed connect-send worden `+17c`, `+5a8`, `+5ac`, `+5fc` en `+698` gewist. De bestaande timer-417-stop blijft vóór het verzenden staan. De oorspronkelijke statusvolgorde vóór beide OS-calls blijft behouden; twee debugprints vervallen om de guards binnen de bestaande codebereiken te laten passen. Proloog, epiloog en `.pdata` veranderen niet.

Bij de latere fout roept de variant de oorspronkelijke progress-getter `12c10` en close-methode `130a70` aan. Die methode is afgeleid van de echte progress-vtable `17b12c+40`. Dit is een andere klasse/singleton dan het bevestigingsvenster. De gekoppelde interpreter volgt de bestaande getter met een geïnitialiseerde singleton, stopt popup-timer `43b`, ruimt GDI-handles en venster op, wist de parent-popupverwijzing en activeert de parent opnieuw. Popupcreatie, GUI-callbacks en OS-calls blijven fixtures; nested-popup-, redraw- en allocatiefoutpaden zijn niet bewezen.

40 traceparen vergelijken dezelfde acht-slotvariant vóór en na alleen deze twee callerblocks: uitgeschakelde gate, dubbele reset-timeout, reset-error, succesvolle reset met dubbele connect-timeout en succesvolle reset met connect-error, voor iedere index. Alle OS-transporthooks overschrijven caller-saved registers. Transportfailure bewijst geen radio-nonexecution: een timeout kan volgen op een al geleverd commando. Deze reparatie herstelt UI/pending-state, geen radio-rollback.

De 152 directe edges zijn een broninventarisatie; zij bewijzen geen volledige return-valueflow, indirecte callers of asynchrone uitvoering. Overige callers en verbonden-profile-switches blijven open. De [reconnectproef](bt-reconnect-draft.md) heeft inmiddels de oorspronkelijke timers 416/417 geïnterpreteerd en gerepareerd: acht posities, begrensde terugval, statuscontrole en stoppen bij mislukte timerstart. Native FAIL_IND-routing is daaraan gekoppeld. Volledige succes-/profile-/scheduler- en GUI-lifetimepaden blijven open. Geen van deze wijzigingen is aan de LGU-builder toegevoegd; MAX02 blijft ongewijzigd.
