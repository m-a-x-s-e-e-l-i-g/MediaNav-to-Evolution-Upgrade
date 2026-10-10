# Eindvoorwaarden voor de nieuwe MediaNav-versie

Dit document bewaart het volledige gebruikersdoel: alle beschikbare executables/firmware/updatepaden onderzoeken, gevonden bugs en inefficiënties ter keuze voorleggen, geselecteerde fixes combineren en één nieuwe versie leveren met eenvoudige uitleg en updatebestanden. **Alle bestaande functionaliteiten blijven werkend.** Deze voorwaarden zijn nog niet allemaal gehaald.

## Vaste afspraak voor elke volgende release

Max heeft op 9 oktober 2026 expliciet vastgelegd: **alleen volledige releases, geen losse patches**. Elke nieuwe LGU begint bij de complete vorige MAXmade-release, behoudt alle bestandspaden en neemt eerdere verbeteringen over. Bestanden mogen worden vervangen door hun nieuwe versie; overige bestanden blijven byte-identiek. Controleer voor iedere release de volledige vorige memberlijst tegen de nieuwe memberlijst en verklaar elke gewijzigde hash. De publieke basis is **7.0.6.MAX03**, met **1.918 members**, gepubliceerd op `main` via PR #22. De nieuwste complete lokale opvolger is [**7.0.6.MAX04**](maxmade-max04-full-update.md), eveneens met 1.918 members en alle eerdere bestanden/fixes; de publieke MAX03 is behouden.

De volgende release mag dus niet opnieuw alleen van het oude FavreMod-pakket vertrekken en daardoor eerdere MAXmade-bestanden of verbeteringen verliezen.

## Deliverables en bewijs

| Vereiste | Wat voltooiing bewijst | Actuele stand |
| --- | --- | --- |
| Onderzoek naar alle beschikbare modules en firmwarelagen | Per module herleidbare contracten plus expliciete afhandeling van lokaal onderzoekbare gaten | Corpus/disassembly/decompilatie breed beschikbaar; handmatig begrip en veel contracten nog onvolledig |
| Alle gevonden bugs/inefficiënties kiezen | Centrale inventaris met root cause, evidence, impact/beperking, keuze en fixstatus | [Centraal overzicht](bug-keuzes.md): 112 IDs; [detailrapportaudit](detail-report-audit.md) bewaart onverklaarde verschillen/regressievragen; extra fixes nog niet geselecteerd, overige modulesemantiek open |
| Bluetoothvertraging verbeteren | Gecombineerde patch, regressie-evidence, gemeten playbackdelay/stabiliteit op de unit | [BT8T03](bt-menu-audio-test-build.md) behoudt BT8T02 acht-slotcode en MAX02-bufferpatch en voegt labeloptimalisatie toe; end-to-endmeting ontbreekt |
| Corruption-fix in hoofd-update | Eén payload met gecontroleerde nav-executable, werkende navigatie na installatie | In lokale MAX02 opgenomen; actuele kaarten/licenties en unitvalidatie ontbreken |
| Acht opgeslagen Bluetoothapparaten | Gezamenlijk Blue/App-pakket; toevoegen/herstart/herverbinden/selecteren/verwijderen op alle acht posities | [BT8T01](bt-eight-test-build.md): matched Blue/AppMain-testexecutables, 824 gerichte offline cases; opgenomen in volledige MAX04-LGU; native unitvalidatie blijft open |
| Nieuwe versie/updatefiles | Manifest/revisie, precieze modulehashes, complete containercontrole en onafhankelijke extractie | [Volledige MAX04](maxmade-max04-full-update.md): goedgekeurde skin plus alle cumulatieve fixes, 1.918 paden; gecombineerde checks, LGU-decode en onafhankelijke uitpakcontrole geslaagd. Installatie/unitbewijs open |
| Eenvoudige ELI5-updateguide | Exacte bruikbare bestanden, USB-voorbereiding, herkenbare schermstappen, succescontrole en werkelijk getoetst herstel | [MAX04-README](../build/maxmade-7.0.6.MAX04/README.md) beschrijft bestanden, wijzigingen, hardwaregrenzen en status; bewezen native installatie-/herstelstappen blijven open |
| Alle huidige functies behouden | Baseline van Max' unit, vóór/na-matrix en geen onverklaarde regressie | Unitbaseline en native vóór/na-resultaten ontbreken |

## Functiebehoud bij de eindcontrole

| Functiegroep | Minimale vóór/na-controle | Ontbrekend bewijs |
| --- | --- | --- |
| Starten, uitschakelen, slaap/herstart en voeding | Normale boot, herhaald powercycle, resume, geen blijvende foutstatus | Werkelijke unit/bootstate en timing |
| Bluetooth bellen | Pairing, verbinden, opnemen/ophangen, microfoon, handsfreeaudio, gesprek tijdens andere bron | Fysieke telefoon/controller/audio |
| Bluetooth muziek | Play/pause/track/metadata, wisselen van apparaat/bron, reconnect, stabiele audio/latency | End-to-endmetingen en verbindingen |
| Opgeslagen Bluetoothlijst | Oude vijf-recorddatabase behouden, acht toevoegen, alle pagina's/selecties/verwijderen, opnieuw starten | Gecombineerde update en echte persistentie |
| Telefoonboek en contacten | Lezen/synchroniseren en juiste gegevens bij juiste apparaat | Profile-/contactbaseline en echte telefoons |
| Navigatie | Start, kaarten/licenties, route, GPS, spraak, terugkeer uit andere schermen | Geïnstalleerde content en unit |
| Radio en overige aanwezige mediabronnen | Zenders/presets/bediening, USB/audioformaten, iPod/DAB waar daadwerkelijk aanwezig | Hardware-/functiebaseline; corpusmodule is geen bewijs dat optie aanwezig is |
| Scherm en bediening | Touch, knoppen/stuurbediening, talen, helderheid, volume en settingsbehoud | Werkelijke voertuigconfiguratie |
| Camera/voertuigfuncties waar aanwezig | Reversebeeld, bron-/focusovergangen en voertuigmeldingen | Voertuig/hardwarebaseline |
| Update en herstel | Correcte installatie, hashes/version, behoud settings en getest herstel bij gekozen failuregrenzen | Installerreparatie/readback en herstelbewijs |

De releaseguide moet normale instructies in eenvoudige taal geven; onderzoekstooling en interne adressen horen in de technische evidence. De guide mag een ongeteste kandidaat niet presenteren als een bewezen veilige eindupdate. Een groene offline fixture of correct LGU-archief bewijst geen behouden voertuigfunctie.

## Nog niet definitief

Welke extra gevonden bugs in de uiteindelijke release meegaan blijft een gebruikerskeuze. Op zichzelf gevonden mogelijkheden zoals meer dan acht slots, grotere transportvensters of nieuwe codecs zijn niet automatisch geselecteerd. De oorspronkelijke onderzoeksbreedte blijft behouden; de drie aangevraagde verbeteringen beperken de module-/firmwareaudit niet.
