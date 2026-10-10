# BT8T02: acht apparaten en audiodelay samen testen

Op 9 oktober 2026 is **BT8T02** gebouwd: de acht-apparatenfix, inclusief ACK/safe-copy/deleteguard, plus de volledige vier playbackpatchbereiken van MAX02. Max bevestigt dat meerdere features in één testsessie mogen worden getest; aparte feature-installaties zijn niet vereist.

[Download ZIP](../build/bt-eight-audio-test-BT8T02.zip), [Blue.exe](../build/bt-eight-audio-test-BT8T02/Test/Blue.exe), [AppMain.exe](../build/bt-eight-audio-test-BT8T02/Test/AppMain.exe), [instructies](../build/bt-eight-audio-test-BT8T02/READ-ME-FIRST.txt), [audiotest](../build/bt-eight-audio-test-BT8T02/TEST-AUDIO-DELAY.txt), [manifest](../build/bt-eight-audio-test-BT8T02/manifest.json), [builder](../tools/build_bt_audio_test.py).

## Concrete bestanden

| Bestand | Bytes | SHA-256 |
| --- | ---: | --- |
| Blue.exe | 1.149.952 | `86db75416ce9196412a3c46c1036da3aa151eacc409f7c22db3461e81fe3308a` |
| AppMain.exe | 1.756.160 | `0c35803e2cd3ad28aa4c0cb21de76f9d9dd62e88eda9dbb534bd0adcaa848845` |
| ZIP | Zie lokaal bestand | `20bf09ebb3835d6c0936d23fff4a650cbdc9960e5fd862cf419dae35a4d6ae44` |

AppMain is exact hetzelfde bestand als in BT8T01. Blue voegt de MAX02-audiobufferreparatie toe. De volledige audio-preimages moeten nog ongewijzigd in de acht-apparatenvariant aanwezig zijn voordat de builder deze edits toepast. De losse playbackvariant is bytegewijs gelijk aan de bestaande MAX02-Blue. Alle PE-headers, sectie-indeling, niet-textsecties en `.pdata` blijven behouden.

## Controle van de daadwerkelijke output

Op de opnieuw ingelezen BT8T02-bestanden slagen dezelfde **824 gerichte opslag/delete/GUI/ACK/HFP/copy-cases** als bij BT8T01. Daarnaast volgen playbackchecks 64 gevarieerde inputpackets met 233.472 exact gecontroleerde outputbytes, gedeeltelijke blokken, producerwrap en dubbele completions. Start na twee blokken, acht saturationpackets zonder overschrijven, stop/start en herstel na failed restart zijn gecontroleerd. API's zijn fixtures; dit is geen native audio- of radio-executie.

Bronbestanden blijven ongewijzigd. Iedere ZIP-member is teruggelezen en bytegewijs met het lokale outputbestand vergeleken. Er is geen LGU, installer, autostart, OS-, MCU- of navigatiebestand opgenomen en geen apparaat gewijzigd.

## Eén gecombineerde testsessie

Gebruik beide executables als paar op de bestaande System-locaties. Als BT8T01 al correct draait, hoeft alleen Blue.exe te worden vervangen omdat AppMain identiek is. Bewaar de huidige bestanden en sc_db.db en gebruik de bestaande CE-vervang-/herstartprocedure met gestopte applicaties.

Test acht koppelingen, beide pagina's, selectie, verwijderen/herverbinden, bellen en muziek in dezelfde sessie. Voor hoorbare delay: speel op dezelfde telefoon/player een video met zichtbare klappen of gesynchroniseerde beeld-/geluidsmarkers af en luister naar de autospeakers. Herhaal driemaal. Voor een vóór/na-vergelijking kan BT8T01 als controle dienen; deze vergelijking is optioneel en geen vereiste om alle features samen te proberen. Met een tweede telefoon kunnen scherm en autospeakergeluid samen worden opgenomen.

Test ook pause/resume, trackwissel, reconnect, normale herstart en circa vijftien minuten muziek met navigatie actief. Noteer delay én klikken/haperingen/stilte. De patch richt zich op A2DP-muziekbuffering; handsfreemicrofoondelay wordt hiermee niet gerepareerd.

De fysieke delay/stabiliteit blijven ongemeten. De kleinere queue kan bij overbelasting inkomende audio overslaan. Partial-writeherstel, snapshot/cache/lifetime en overige controller-/profielvragen blijven open. BT8T02 is een experimentele applicatietest, geen bewezen eindrelease of herstelmechanisme.
