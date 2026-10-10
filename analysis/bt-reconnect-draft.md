# Bluetooth: acht reconnectposities en begrensde terugval

De geheugenvariant verwerkt nu ook de twee reconnect-timers van AppMain. De volledige native `WndProc`-entry `13120c`, timerdispatch, gevolgde helperfuncties en oorspronkelijke epiloog worden in de interpreter uitgevoerd. Er is geen CE-executable gestart, uitvoerbestand geschreven of LGU gebouwd. Radio, OS/timers en delen van de GUI blijven expliciete fixtures.

Uitvoeren: `py tools/verify_bt_reconnect.py`. [Evidence](firmware/bt-reconnect-draft/contracts.json) bevat oorspronkelijke functies/bytes, de actuele AppMain-variant-hash, traces en afhankelijke toolhashes.

## Oorspronkelijke grenzen en fouten

Timer `416` verhoogt `STATE+5a4`, verzendt `1010804` met die one-based index en plant opnieuw na 25 seconden. De oorspronkelijke grens is vijf. Na OS-verzendfalen plant hij toch opnieuw. Ook een mislukte `SetTimer` wordt niet afgehandeld. De afloop wist autoconnectstatus via `127654` en gebruikt een parent-dialogcallback wanneer diens popup de progress-singleton is.

Timer `417` is een ander pad: na een mislukte handmatig gekozen verbinding probeert hij alternatieven. `+5a8` bewaart het oorspronkelijk gekozen apparaat; `+5ac` bewaart de terugvalfase. Bij twee records probeert hij het andere record. Bij drie of meer records bestaan alleen deze reeksen:

| Oorspronkelijk gekozen index | Oorspronkelijke terugval |
| --- | --- |
| 1 | 2, 3 |
| 2 | 3, 1 |
| 3 of hoger | 1, 2 |

Apparaten vier tot acht worden daardoor nooit als alternatief geprobeerd. Bovendien plant de oorspronkelijke tak voor gekozen index twee na de laatste aanvraag naar index één geen volgende timer; de pending-state blijft dan staan. De andere terminale takken wissen slechts `+17c`, `+5a8` en `+5ac`.

`CBlueMsgManager::postMsgFromSelfByBlue`, entry `11cb00`, ontvangt `4010507` (`LGEBT_AUTOCONNECT_FAIL_IND`). Voor het initiële automatische pad plant hij timer `416` na 10 ms. Voor het initiële handmatige terugvalpad plant hij `417` na 1000 ms, alleen wanneer Blue ready is, er geen verbinding is, `+17c=1` en `+5ac=0`. Latere terugvalfases krijgen geen extra timer van deze callback; de timerhandler zelf moet die plannen. De native callback blijft zo functioneren voor fasewaarden vier tot acht.

Er bestaat daarnaast een stopwaarde zes: bij een initiële autoconnectfailure met een actieve GUI-vlag op `APP_CONTEXT+e8` zet de callback `+5a4=6` en plant discovery/reset-timer `41a`. Een losse uitbreiding van de pogingsteller tot acht zou deze stopwaarde opnieuw als geldige teller behandelen.

## Reparatie in de variant

De `416`-body op `132b7c..132c3c` controleert teller en recordcount met unsigned grenzen. Alleen geldige one-based indices één tot acht worden verzonden. Een bestaande verbinding, uitgeputte lijst, ongeldige teller/count, verzendfout of mislukte timerstart stopt het pad. De oorspronkelijke parent-dialogregisterwaarde blijft behouden, zodat ook de afloop na een late verzendfout het bestaande dialogpad kan bereiken. De stopwaarde in `11e0cc` wordt negen. De afloop bereikt nu ook bij een reeds verbonden apparaat de bestaande GUI-vlag-/parent-opruimtak; die parent-methode is in deze proef een hook.

De `417`-body op `132d38..132ec8` probeert alle overige indices cyclisch na het gekozen apparaat. Bijvoorbeeld: acht records, gekozen index zes geeft **7, 8, 1, 2, 3, 4, 5**. Ieder alternatief komt precies één keer aan bod. Het gekozen apparaat wordt niet nogmaals geprobeerd. `+5ac` is de laatst aangevraagde index; `+5a8` blijft de oorspronkelijke keuze. Na iedere geslaagde transportcall wordt opnieuw 25 seconden gepland, ook na het laatste alternatief, zodat de volgende tick de afloop uitvoert.

De handler stopt bij een verbinding, volledige cyclus, ongeldige count/index/fase, verzendfout of timerstartfailure. Hij wist `+17c`, `+5a8`, `+5ac`, `+5fc` en `+698` en sluit de bestaande progress-singleton via `130a70`. Die native cleanup wist de parent-popupverwijzing, ruimt venster/GDI op en activeert de parent. Bij `+17c != 1` stopt alleen de ontvangen timer; de overige state blijft gelijk.

Beide wijzigingen passen in oorspronkelijke codebereiken. Er zijn geen extra secties of gewijzigde stackframes; bestandlengte en `.pdata` blijven gelijk. De status vóór de transportcalls wordt door de native instructies gezet en bij het OS-punt in de traces vastgelegd. Alle transport-/timer-/GDI-hooks overschrijven caller-saved registers.

## Gecontroleerde reeksen

| Controle | Concrete evidence |
| --- | --- |
| Timer 416 origineel versus variant | 18 reeksen per versie: nul tot acht records, eerdere teller nul of één; oorspronkelijk maximaal vijf, variant maximaal acht |
| Timer 417 origineel versus variant | 36 reeksen per versie: iedere keuze bij één tot acht records; oude vaste reeksen en nieuwe complete cyclus |
| Verzendfout, dubbele timeout, uitgeschakelde gate en herstelde retry | 64 variantreeksen over beide timers en acht beginposities |
| `SetTimer` geeft nul | 16 variantreeksen: één poging, directe afloop en geen vervolg |
| Ongeldige count, index, fase of teller | 15 cases: geen verzending of vervolgplanning |
| Verbonden of niet-actief | Zes cases; inclusief behoud van state bij niet-actieve timer 417 |
| Native FAIL_IND gekoppeld aan timer 417 | 36 reeksen: eerste callback plant 1000 ms, latere callbacks voegen geen timer toe; volledige cyclus en afloop |
| Ready/connected/active/fase-gates in FAIL_IND | 72 native callbackcases, fases nul tot acht |
| Automatische start versus GUI-stopwaarde | Twee originele/variantparen, met daarna een native timer-416-tick; stopwaardes zes/negen stoppen beide hun eigen versie |

Succes betekent hier OS-transportstatus, geen radiobevestiging. De FAIL_IND is een synthetisch aangeboden bericht aan de oorspronkelijke dispatcher. Dit bewijst geen live scheduler of radio-verbinding. Een timeout kan volgen op een al geleverd commando; UI-opruimen is geen radio-rollback.

De [HFP-succesproef](bt-connection-success-draft.md) volgt inmiddels de oorspronkelijke dispatcher, actieve record, phonebookpad en progress-cleanup voor acht posities. Zij repareert ook een verloren status bij de lijstaanvraag en inventariseert een oudere autoconnecthelper. Overige profielen, gewijzigde recordvolgorde tijdens wachten, gelijktijdige timers, het werkelijk aanmaken van vensters, backing surfaces, nested popups en parent redraw blijven open. De `416`-afloop gebruikt in deze verifier een parent-vtablehook; diens volledige GUI-opruimketen is nog niet gekoppeld. Naamcache-aliases, snapshotfreshness en atomische databasepersistentie blijven aparte releaseblokkades. De variant is niet aan de updatebuilder verbonden; originele executables en MAX02 zijn ongewijzigd.
