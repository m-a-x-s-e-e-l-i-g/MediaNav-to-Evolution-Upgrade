# Unitfeedback en eerste discoverycontrole, 9 oktober 2026

Max meldt dat de audiovertraging weg is, maar zoeken naar nieuwe Bluetoothapparaten geen resultaten geeft. Dit is gebruikersfeedback, geen gekwantificeerde latency-/radiometing. De daadwerkelijk geïnstalleerde build en vervanging van beide executables zijn nog uitgevraagd.

## Aanvullende unitgegevens en verklaring

Max bevestigt beide executables vervangen. De telefoon ziet MediaNav, terwijl de unit zoekt en met een lege lijst eindigt. Daarna verduidelijkt hij: hij zocht zijn **laptop**. De eerdere klacht is daarmee geen aangetoonde mislukking bij een nieuwe telefoon.

De oorspronkelijke handler past `31f64` toe op de inkomende Class of Device. Die native functie accepteert `(class & 0200) != 0` en `(class & 0020) == 0`. De gebruikelijke laptopklasse `010c` wordt geweigerd. Computer en telefoon zijn aparte Bluetooth-major device classes; zie de [Bluetooth SIG assigned numbers](https://www.bluetooth.com/wp-content/uploads/Files/Specification/HTML/Assigned_Numbers/out/en/index-en.html). SIG-mode heeft een expliciete bypass, maar is niet aangezet of gepatcht.

Zes byte-interpreterchecks voeren `31f64..31f88` uit op originele Blue en de bestaande BT8T03-output. Per versie: `010c` (laptop) geeft nul, `020c` (smartphone) geeft één, `0404` (audio/video) geeft nul. Stack en callee-saved registers blijven behouden via de bestaande ABI-check. Dit gebruikt synthetische class-inputs: de echte laptopklasse, werkelijke radio-inquiry en volledige GUI-delivery zijn niet gemeten.

De laptopfiltering is daarom een waarschijnlijke verklaring met oorspronkelijke-codebewijs, geen aangetoonde acht-slotregressie. Volgende unitcontrole: een nog niet opgeslagen telefoon in discoverable/pairingmodus zoeken. Er is geen nieuwe executable gebouwd en geen pairing/database verwijderd.

## Controle van de bestaande BT8T03-output

PE-ranges zijn direct bytegewijs vergeleken met `extracted/705md/upgrade/Storage Card/System`. Alle onderstaande ranges zijn identiek in `build/bt-menu-audio-test-BT8T03/Test`:

| Module | Range, einde exclusief | Pad |
| --- | --- | --- |
| Blue | `2fa08..2fb74` | Inquiry-start |
| Blue | `23700..239a4` | Resultaat-handler |
| Blue | `239a4..23ac4` | Search completion |
| Blue | `319d0..31a90` | Reeds gekoppeld adres herkennen |
| Blue | `31f64..31fa0` | Telefoonklassefilter |
| Blue | `34650..34750` | Shared-search-publicatie |
| AppMain | `11f2f0..11f7d4` | Completion en kopiëren van resultaten |

Dit is alleen byte-identiteit: de gewijzigde code elders kan alsnog invloed hebben op gedeelde state, IPC, timing of filters. Er is nog geen oorzaak aangetoond en geen nieuwe patch gebouwd.

## Wat de oorspronkelijke handler doet

`Blue:23700` verwerkt resultaten uitsluitend bij search-state één. `319d0` vergelijkt het inkomende adres met de huidige shared paired-list. Een reeds gekoppeld adres wordt expliciet uitgesloten en gelogd als `This device already paired`. Nieuwe adressen moeten bovendien het class-filter doorstaan, tenzij SIG-mode aanstaat. De handler publiceert dan een record en count-notificatie. `239a4` voltooit of annuleert afhankelijk van de search-state.

Eerst ontbrekende unitgegevens verzamelen: exact build/beide vervangen files; start/timeout van zoeken; werkelijk nieuw apparaat met discoverability aan; ziet een zoekende telefoon de MediaNav? Niet bestaande pairings verwijderen of de database resetten voor deze eerste controle. De eerder uitgesloten brede H4-/controllerfixture wordt hiermee niet hervat.
