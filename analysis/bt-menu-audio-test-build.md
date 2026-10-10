# BT8T03: menuwerk verminderen, Bluetooth/audio behouden

Max kiest op 9 oktober 2026 **menu's/opstart en Bluetooth/bronwissels** (opties 1 en 3). BT8T03 voegt een AppMain-optimalisatie toe aan BT8T02. Acht opgeslagen apparaten en de MAX02-audiopatch blijven samen beschikbaar; USB-artwork heeft nu geen prioriteit.

[ZIP](../build/bt-menu-audio-test-BT8T03.zip), [AppMain.exe](../build/bt-menu-audio-test-BT8T03/Test/AppMain.exe), [Blue.exe](../build/bt-menu-audio-test-BT8T03/Test/Blue.exe), [vervang-/herstelguide](../build/bt-menu-audio-test-BT8T03/READ-ME-FIRST.txt), [prestatietest](../build/bt-menu-audio-test-BT8T03/TEST-PERFORMANCE.txt), [manifest](../build/bt-menu-audio-test-BT8T03/manifest.json), [builder](../tools/build_bt_menu_test.py).

## Concrete wijziging

Unitfeedback op 9 oktober 2026: Max meldt dat de audiovertraging weg is. Er is nog geen gekwantificeerde latency-/stabiliteitsmeting of bevestiging van de geïnstalleerde bestandhashes. Zoeken naar nieuwe Bluetoothapparaten geeft volgens Max geen resultaten; [gerichte discovery-triage](bt-discovery-unit-triage.md) loopt. Deze melding geldt niet als geslaagde volledige pairingtest.

De [AppMain-tekstcontracten](appmain-text-contracts.md) tonen dat Arabischdetectie `139918` bij ieder niet-gematcht teken de hele tekst opnieuw scant. Alle 32 tabelletters vallen binnen `0600..06ff`; een enkele scan naar die reeks heeft dezelfde booleanuitkomst voor NUL-beëindigde UTF16-tekst. De ongebruikte lokale kopieën zijn verwijderd.

[Patcher](../tools/patch_appmain_label_scan.py) vervangt alleen `139964..139a33`. Prologue, NULL-pad, cookiecheck, return, epilogue, functieframe, `.pdata`, headers en niet-textsecties blijven gelijk. De Hebreeuwsdetectie en toegestane Unicode-reeksen blijven behouden. Acht directe calls uit vijf geïnventariseerde tekenroutines gebruiken de helper. Controle van de originele textsectie vond geen externe directe branch/call naar het vervangen binnenbereik; indirecte sprongen zijn daarmee niet uitgesloten.

| Bestand | Bytes | SHA-256 |
| --- | ---: | --- |
| AppMain.exe | 1.756.160 | `bddf03995a63b41a1d6cc180be03e8b56b882d0989a5a73c60ed974f9790a4e3` |
| Blue.exe | 1.149.952 | `86db75416ce9196412a3c46c1036da3aa151eacc409f7c22db3461e81fe3308a` |
| ZIP | Zie lokaal bestand | `2b9d5d635c90ca69dfc9c0536971ac779d660e8d7f1fe39433df72be88ded1d7` |

Blue is byte-identiek aan BT8T02. Vanaf een werkende BT8T02-installatie verandert alleen AppMain. Vanaf de oorspronkelijke 7.0.5.MD gebruik je beide Test-bestanden als paar. Eerdere builds blijven behouden.

## Lokale meting en controles

[Byte-interpreter](../tools/verify_appmain_label_scan.py) vergelijkt de originele en gewijzigde functie-instructies. Alle **65.536 UTF16-waarden** leveren hetzelfde resultaat (256 positieve Arabische waarden); **172 gemengde/lange gevallen** en twee NULL-pointercases slagen. Cases bevatten eerste/middelste/laatste Arabische tekens, NUL met niet-nul opslag erachter, grenswaarden, surrogates, willekeurige tekst en 400 Latin units. Sourcereads voorbij de eerste NUL worden geweigerd. Cookie, callee-saved registers, callerstack en writes binnen het private frame worden gecontroleerd. CRT-/cookiecalls zijn hooks; GDI en firmware draaien niet natively.

Deze aantallen gelden voor één helperaanroep met alleen Latin `A`-units. Interne CRT-hookinstructies/-reads zijn niet meegeteld; er is geen scherm-, opstart- of wall-clockmeting.

| Tekstlengte | Originele instructies | Nieuwe instructies | Originele tekstreads | Nieuwe tekstreads |
| ---: | ---: | ---: | ---: | ---: |
| 8 | 2.937 | 88 | 153 | 9 |
| 32 | 21.561 | 256 | 2.145 | 33 |
| 128 | 245.817 | 928 | 33.153 | 129 |
| 270 | 1.016.877 | 1.922 | 146.611 | 271 |

De oorspronkelijke 400-unitcase overschreed de eerste interpreterlimiet van twee miljoen instructies. De limiet is naar vier miljoen verhoogd; de finale suite slaagt. Dit is een begrensde analysetest en geen bewezen unitvastloper.

[Exhaustieve evidence](firmware/appmain-label-scan/contracts.json) bewaart source-/patchhashes, bytes en metingen. De builder eist dezelfde patchrecipe en dezelfde functiebytes; niet-textdata blijft gelijk. Op de geschreven, opnieuw ingelezen gecombineerde AppMain slagen de 172 gemengde cases, NULL-/ABI-/stack-/NUL-grenzen en helpermetingen opnieuw. De 65.536-waardenrun wordt via byte-identiteit hergebruikt, niet als tweede run geteld.

De opnieuw ingelezen pair doorstaat daarnaast **824 pairing/delete/GUI/ACK/HFP/copy-cases** en de BT8T02-playbackchecks: 64 payloadpackets met 233.472 exacte outputbytes, twee-blokstart, saturation, dubbele completions, stop/start en restartfailureherstel. ZIP-members zijn afzonderlijk teruggelezen en vergeleken. Dit vervangt geen controller-/scheduler-/unitbewijs en hervat niet de eerder overgeslagen Bluetooth-vervolgstappen.

## Samen testen en volgende prioriteiten

Gebruik de bestaande CE-vervang-/normale-herstartprocedure met gestopte apps en je actuele executable-/sc_db.db-backup. De pakketguide bevat locaties en terugzetinstructies. Test menu's, lange namen, tekst/font/richting, beide Bluetoothpagina's, acht apparaten, bellen, radio/Bluetooth-bronwissels, reconnect en audiovertraging samen. Vergelijk dezelfde schermen/acties met BT8T02; meet opstart afzonderlijk. De behouden audiotest noemt BT8T02 omdat de audiobytes identiek zijn.

Deze versie wijzigt geen startupwait en geen transportcleanup. Het pakket bevat geen LGU, launcher, autorun, navigatie-, OS- of MCU-bestand. De 4.1.0-referentie blijft buiten de reverse-engineeringcorpus.

De volgende Bluetoothkandidaten zijn [queue-cleanupreparaties BT-08/09](bt-transport-contracts.md), voor correct opruimen bij stop/herstart; bereikbaarheid en winst bij bronwissels moeten nog worden gecontroleerd. Bij opstart is een vaste 600-ms-wacht aangetoond in [AppMain](appmain-startup-contracts.md). Eerst manager-readiness/volgorde volgen en meten: verkorten kan initialisatieraces introduceren. Algemene menusnelheid, totale bootduur en audiodelay blijven op hardware ongemeten.
