# Sporadisch verbonden via Bluetooth, maar muziek speelt niet

**Implementatievervolg:** [startup audio development-02](bt-startup-audio-development.md) bevat nu één begrensde herpoging binnen de eerste audio-opening en correcte lokale gereedheid. De oorspronkelijke bronrouting en peer-notificaties blijven behouden. Alle 1.918 vorige bestanden/fixes meegenomen; geen LGU/release. De onderstaande audits blijven het oorspronkelijke foutpad beschrijven.

Max meldt op 10 oktober 2026 dat Bluetooth heel soms verbonden is terwijl muziek niet afspeelt. Het nummer op de telefoon loopt dan door. Verbreken/herverbinden of een herstart helpt. Het gebeurt meteen na starten/automatisch verbinden, niet pas na bellen of een bronwissel. Dit wordt de eerstvolgende gerichte Bluetoothprioriteit. De eerdere audiodelaywijziging werkte volgens zijn autotest. Het nieuwe incident is nog niet op een unit gereproduceerd.

## Gecontroleerd foutpad

`python tools/audit_bt_stream_start.py` interpreteert de volledige oorspronkelijke MIPS-handler `HandleAvStartInd`, `1ace4..1b088`, inclusief proloog/epiloog. Filterresultaten, allocatie, logging en transport zijn expliciete fixtures; er draait geen native firmware. [Evidence](firmware/bt-stream-start-audit.json) bevat 21 cases over origineel, gepubliceerde MAX03 en de huidige complete ontwikkelbasis. Callee-saved-registers en stack worden gecontroleerd; hooks overschrijven caller-saved-registers.

De handlerbytes zijn in alle drie binaries exact gelijk. Bij geldige streamstate en aangevraagde audio voert de handler stop, close, open en start uit. Een nulreturn van open of start bereikt alleen een debuglog. Ook wanneer beide falen:

- wordt de outputvlag `AV+11d` weer één;
- wordt een succesvolle startrespons verzonden;
- wordt de AV-streamstate drie;
- ontvangt AppMain de meldingen `3070801/0` en `3071101/1`.

Succes, stopfailure, closefailure, open/startfailure, alleen startfailure, niet-aangevraagde audio en ongeldige streamstate zijn gecontroleerd. Bij ongeldige state werkt de bestaande afwijzing wel. Niet-aangevraagde audio mag een geldig protocol-startpad volgen zonder lokale audio: dat is geen bewezen fout.

Dit bevestigt dat een mislukte lokale audiostart als gestart kan worden gemeld. Het bewijst niet dat zo'n failure op Max' unit optreedt, hoe vaak dit gebeurt, of dat dit zijn incident verklaart. De `FiltersRun`-internals en concrete wave-driverfailure zijn in deze nieuwe proef niet uitgevoerd. Geen retry, profielreconnect of firmwarewijziging toegevoegd.

## Eerst onderscheiden

1. Nummer loopt door op de telefoon, maar unit blijft stil: volg A2DP-streamstatus, lokale output/open/start en bron/mute.
2. Nummer begint ook op de telefoon niet: volg het playcommando, telefoon/playerstatus en AVRCP-verbinding.
3. Verbreken/herverbinden helpt: controleer welke profiel- en lokale filterstate hierdoor herstelt. Alleen herstel door herstart vraagt afzonderlijke vergelijking van reset/close/open.

Max heeft tak één en herstel door herverbinden/herstart bevestigd, met timing direct na automatisch verbinden. Focus daarom op de eerste lokale audio-opening en herstel van die toestand. De telefoon/player-playcommandotak heeft lagere prioriteit. De oorzaak van het hardwareincident blijft onbekend. Geen algemene automatische reconnect toevoegen: die kan gesprekken of een bewust gepauzeerde speler verstoren.

## Gekoppelde reproduceerbare startfout

`python tools/audit_bt_startup_silence.py` voert de echte MIPS-bytes uit van FiltersRun, WinPlayOpen, WinPlayStart, WinPlayClose en WinPlayProcess (inclusief de oorspronkelijke bufferselector waar gebruikt). Dit is een geïsoleerde WinPlay-filterfixture; de SBC/sink-filterlifecycle, volledige Bluetooth-profielreconnecthandler, OS/thread scheduling en driver blijven buiten deze proef. De API-uitkomsten en threadownership zijn expliciete fixtures. [Nieuw bewijs](firmware/bt-startup-silence-audit.json) bevat negen reeksen: normale start, eerste waveOutOpen-fout en eerste CreateThread-fout, ieder op origineel/MAX03/current development.

Concrete keten bij de twee aangeleverde startfouten:

1. WinPlayOpen geeft nul terug, contextstate wordt nul en wavehandle blijft nul.
2. FiltersRun zet zijn tabelstate ondanks de openfailure op twee.
3. WinPlayStart geeft bij een nulhandle toch één terug. FiltersRun zet de tabel op drie (gestart).
4. Een volgende open/start-aanvraag geeft weer één terug maar roept geen nieuwe audio-API aan: de tabel geldt al als gestart.
5. WinPlayProcess met echte 4096-byte inputlengte bereikt de nulhandle-uitgang, biedt geen audio aan en roept geen PCM-copy aan.
6. Een expliciete native filter-close/open/start werkt wanneer de API-fixtures vervolgens succes geven. Bij de wave-openfailure wordt de eerder gemaakte thread via de bestaande closecode opgeruimd; een succesvolle nieuwe opening bereidt 25 headers voor. Het volgende PCM-pakket bereikt de copy en de huidige versie biedt één 4096-byte blok aan.

De normale start blijft als controle werken. Iedere volledige invocation controleert stack en callee-saved-registers; API-hooks overschrijven caller-saved-registers. Dit bevestigt het blijvende stille pad ná de geïnjecteerde startfailure, ook in de huidige gepubliceerde binary. Het bevestigt niet dat waveOutOpen/CreateThread op Max' auto werkelijk faalt. De expliciete close/reopen-proef is ook geen simulatie van zijn volledige telefoonherverbinding.

Een reparatie moet de eerste failure correct herkennen, de tabelstate aan echte outputreadiness koppelen, en tijdelijke fouten begrensd kunnen herstellen. Een failure opnieuw laten openen zonder thread/handle-cleanup kan bestaande ownershipproblemen verergeren. De bestaande closecode negeert enkele API-failures; de proef biedt daar alleen succesvolle cleanup aan. Daarom is op grond van deze audit nog geen automatische close/reopen-loop of uitvoerbare patch gebouwd. Volgende gerichte stap: begrensde retry binnen dezelfde opening beoordelen, met nulhandle/ownershipguards en blijvende API-failure als stopconditie.

## Basis behouden

Huidige complete staging blijft `build/usb-option-snapshot-development-01`, met alle 1.918 bestanden. Blue-hash in gepubliceerde MAX03 en deze staging is `86db75416ce9196412a3c46c1036da3aa151eacc409f7c22db3461e81fe3308a`. Er is geen executable, LGU, versie, release of publicatie gewijzigd. Eerder uitgesloten breed controller/power/timeoutonderzoek is niet hervat.
