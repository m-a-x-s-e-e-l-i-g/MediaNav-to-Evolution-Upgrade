# MICOM: seriële framing in 7.0.5.MD

Dit document beschrijft de Windows CE-kant in `MicomManager.exe`. De firmware van de aparte microcontroller is een andere architectuur. Geen verbinding met de unit is geopend.

## COM2 en normale frames

De manager opent `COM2:` en stelt de baudrate op **300.000** in (`0x28254–0x282e4`), met 8 databits, geen parity en één stopbit. De exacte fysieke verbinding en chip moeten nog met unitgegevens worden bevestigd.

`CProtocol` bouwt op `0x28588–0x2863b` een packed header. De parameters na `this` zijn manager, type, commando, payloadpointer en lengte. De bitbewerkingen leveren:

```text
byte 0     0xAA
byte 1     (manager << 4) | (type & 0x0F)
byte 2     command
byte 3     payload length
byte 4...  payload
last byte  XOR of every preceding byte, including 0xAA
```

Manager wordt beperkt tot zijn lage nibble; het commando is acht bits. De lengte wordt als byte doorgegeven. Op `0x284e8–0x28587` berekent de code de XOR en schrijft zij `length + 5` bytes met `WriteFile`. Een geslaagde WriteFile-aanroep wordt teruggegeven; het werkelijk geschreven byteaantal wordt in deze functie niet met de verwachte lengte vergeleken.

De Windows-kant gebruikt veel kleinere vaste buffers dan het theoretische bytebereik van de lengtedeclaratie. Een parser die 255 payloadbytes kan lezen bewijst dus niet dat zulke pakketten naar deze implementatie veilig zijn.

## Ontvangst

`CProtocol::ReadCommand`, `0x2863c–0x288e3`, onderscheidt:

| Header | Framing | Bewezen behandeling |
| --- | --- | --- |
| `AA` | Header van vier bytes, payload volgens byte 3, één XOR-byte | Exacte readlengtes en XOR worden gecontroleerd |
| `AB` | Twee bytes | Tweede byte gelezen maar niet doorgestuurd; aanwezige retrylogica verwacht status `21/22` |
| `A6` | Eén byte | Normale MCU-ack; type 2/6 test geen handlerresultaat, type 1 accepteert C=0/1; geen bewijs van flashsucces |

Een onbekende eerste byte geeft een fout. De leestime-outs worden per fase ingesteld. De ontvangende thread (`0x25cac–0x25e1b`) zet bij `A6` een event. Bij een normaal `AA`-bericht met **type-nibble `0xD`** wordt de read-resultcache ingevuld en hetzelfde event gezet. Andere normale frames gaan via een queue en vensterbericht `0x401`; `AB` leidt tot vensterbericht `0x402` met `wParam = 0xAB`. De tweede AB-byte wordt daar niet als wParam doorgegeven. De betekenis van dat vensterbericht moet verder worden gevolgd.

`CProtocol::SetReadData`, `0x288e4–0x28993`, bewaart header en payload in een cache van 0x8c bytes en beperkt de payload tot **0x88 = 136 bytes**. Die beperking geldt na de eerste ontvangst, niet als algemene limiet van het wire-formaat.

## Gevolgde commandotypes

- `CCmd::SendReadCmd`, `0x153dc–0x15603`: type **5**, commandobyte is de gevraagde lengte; de payload bevat een 32-bit adres in little-endian volgorde. De responsecache levert de feitelijke response-lengte terug. Timeoutpaden kunnen tot drie pogingen doen.
- `CCmd::SendWriteCmd`, `0x14db0–0x14f8b`: type **6**, commandobyte is de datalengte; payload bestaat uit vier little-endian adresbytes gevolgd door data. De aanroep naar de packetbuilder staat op `0x14edc`. [Radio-/Arkamys-transfers](radio-audio-formats.md) leveren concrete aanroepvoorbeelden.
- `CCmd::SendCommandEx`, `0x15158–0x152c7`: critical section, event reset, maximaal drie send/wait-pogingen en timeoutargument plus 50 ms. Het wacht-event bewijst geen volledige inhoudelijke responsevalidatie.

De manager-ID's en gewone commandonummers moeten per service worden gekoppeld aan hun handler. De [MCU-flashmarkeranalyse](micom-flash-marker-contracts.md) verbindt manager 1/commando 0 met de CE-opstarttimer en een markerwrite, en commando 7 met property 42 en mogelijke markererase. Ze volgt tevens de A6-eventketen: een eventwait kan geen geslaagde flashoperatie bewijzen. De 42 CmnDll-routing-ID's zijn een apart IPC-systeem; die nummers mogen niet zonder bewijs als seriële manager-ID's worden gebruikt.

## Firmware-loader

`0x1ef7c–0x1f2c3` alloceert **0x40000 bytes**, vult ze met `FF`, leest Intel HEX-regels in tekstmodus met een 64-byte buffer en controleert de additieve recordchecksum. Type 0 schrijft data, type 1 meldt succes, type 2 stelt een segmentwaarde in. Types 4/5 worden overgeslagen. De verwerking van type 3 lijkt een extra adresbasis te lezen en verdient nadere vergelijking met de Intel HEX-specificatie; in het aanwezige bestand is die waarde nul.

De voorliggende firmware bevat 262.144 aaneengesloten databytes en geldige recordchecksums. Dat bevestigt het bestand, geen recovery- of flashgedrag.

Op `0x22cfc–0x22e63` worden timers gestopt en deze loader aangeroepen. Beide uitkomsten sturen vervolgens dezelfde gewone opdracht `(manager=1, type=1, command=5, payload length=0)`; het vervolgpad en de returnwaarde verschillen. De vervolgtransfer gebruikt [ULC-frames met 1024-byte blokken](micom-update-transport.md). De Windows-blokselectie en foutpaden zijn gevolgd; MCU-flashadressen en inhoudelijke voltooiing blijven open.

## Offline hulpmiddel

[micom_protocol.py](../tools/micom_protocol.py) leest uitsluitend een lokaal bestand met capturebytes. Het bewaart checksumfouten, onbekende bytes en afgebroken frames expliciet. Synthetische verificatie dekt 0/1/8/255 payloadbytes, beschadigde checksums, controles, ruis en truncatie. Er is nog geen echte seriële capture om hiermee te vergelijken.

Evidence: [MIPS-disassembly](disassembly/MicomManager.exe.asm), [Ghidra-pseudocode](decompiled/705md/MicomManager.exe/decompiled.c), [HEX-checks](705md-firmware-hex.json).
