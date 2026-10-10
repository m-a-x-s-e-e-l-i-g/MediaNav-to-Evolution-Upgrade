# Bluetooth: meer dan vijf opgeslagen apparaten

**Acht opgeslagen koppelingen is een concrete kandidaat voor uitbreiding.** De oorspronkelijke 7.0.5.MD bevat twee pairing-/passkeygrenzen van acht, maar andere onderdelen zijn op vijf ingericht. Dat bevestigt geen volledige ondersteuning voor acht apparaten door de radio/stack. Er is inmiddels een [concrete opslag-/UI-variant in interpretergeheugen](bt-pairing-storage-draft.md), met gecontroleerde recordverplaatsingen en oude korte databases. De complete uitbreiding is nog niet gebouwd of op de unit getest. MAX02 bevat alleen de eerder beschreven playbackreparatie en navigatiefix.

De vier regels op het scherm zijn de paginagrootte. Acht opgeslagen apparaten kunnen met dezelfde bediening over twee pagina's verschijnen. Opgeslagen koppelingen en gelijktijdig actieve verbindingen zijn verschillende beperkingen; deze uitbreiding betreft alleen de opgeslagen lijst.

## Grenzen in de originele bytes

| Onderdeel | Functie / instructie | Bevestigde grens |
| --- | --- | --- |
| Beginnen met pairing | Blue `303b8`, vergelijking `30568` | Nieuwe pairing zolang count < 8 |
| Passkey accepteren | Blue `318d4`, vergelijking `318e4` | Count < 8, plus toegestane verbindingsstatus |
| Terugladen uit database | Blue `3307c` | Leest vijf records, publiceert maximaal vijf |
| Private databasebuffer | Blue `31768` | `+20..+228`: 520 bytes = vijf records van 104 bytes |
| Bestaande koppeling vooraan zetten | Blue `31c84` | Doorloopt vier posities en verschuift binnen de bestaande bank |
| Verwijderen en compact maken | Blue `7aa40`, aangeroepen vanuit `7ab4c` | Leest/schrijft vijf records; lokale stackbuffer heeft dezelfde capaciteit |
| Lijst kopiëren naar UI | AppMain `110708` | Vijf records van 64 bytes en vijf namen van 100 bytes |
| Getoond totaal | AppMain `d0794` | Clampt totaal op vijf, berekent pagina's met vier regels |
| Pair/full-listbediening | AppMain `204dc`, `b9570`, `b9c1c`, `d2738`, `d3dc0` | Mix van vijf en acht; elke branch moet apart worden aangepast |
| Automatisch verbinden | AppMain `13120c` | Onderzochte pogingsteller bevat een grens van vijf |
| Gedeelde medialijst | Blue `3459c` | Strikte eindvergelijking weigert one-based index acht; callerbetekenis verder volgen |

De database heet `\\Storage Card2\\DATA\\BLUE\\sc_db.db`. De lage opslaghelpers `7a4d0`, `7a738`, `7a7f8`, `7a8a8` en `7a974` kunnen records scannen of een aangevraagd aantal lezen/schrijven. De hogere reload-, reorder- en deletepaden kiezen vijf. Alleen een grotere pairinggrens lost de herstart- en verwijderproblemen dus niet op.

## Waarom alleen vijf naar acht wijzigen faalt

AppMain gebruikt records op `object+270..+3b0`, direct gevolgd door geconverteerde namen op `+3b0..+5a4`. Daarna staan onder andere de actieve index, telefoonboekstatus en pointers. Acht records zouden tot `+470` lopen en acht namen tot `+6d0`: de bestaande banken overlappen, en de naamconversie overschrijft echte velden.

De interpreter heeft de originele kopieerroutine uitgevoerd voor ontvangen aantallen nul tot negen. Met de oorspronkelijke loop blijven de omliggende velden intact. In drie uitsluitend in interpretergeheugen gewijzigde varianten met loopgrens acht en aantallen zes, zeven en acht worden velden vanaf `+5a8` overschreven. Het oorspronkelijke programma en de LGU zijn niet gewijzigd. Dit is een aangetoonde reden om geen losse constantepatch uit te leveren.

Blue heeft een tweede probleem: de private recordbank van vijf eindigt op `+228`. Acht records zouden eindigen op `+360`, over de aansluitende managerstatus en parentvelden heen. Bij verwijderen ligt de recordbuffer op `sp+78`. Acht records zouden tot `sp+3b8` lopen, voorbij stackcookie `sp+280`, opgeslagen returnadres `sp+294` en het volledige frame van `0x298` bytes. Een grotere stack vereist passende unwindmetadata, of een andere bufferstrategie die het bestaande frame behoudt.

## Reproduceerbare verificatie

Uitvoeren: `py tools/inspect_bt_pairing.py`.

- 35 oorspronkelijke functiegebieden uit Blue en AppMain met volledige bron- en bereikhashes.
- Negen exacte instructieguards voor pairing, passkey, reload, delete, UI-copy, totaal en medialijst.
- Tien oorspronkelijke UI-copytraces, inclusief actieve-indexselectie en behoud van omliggende velden.
- Negen oorspronkelijke reloadtraces: databases met nul tot acht aaneengesloten niet-lege adresrecords publiceren maximaal vijf koppelingen.
- Zeventig oorspronkelijke passkeytraces: count nul tot negen met zeven statuswaarden bevestigen de grens van acht en de statuscontrole.
- Drie traces die schade door de onvolledige acht-loopvariant reproduceren.
- De geïnterpreteerde routines behouden hun stack en callee-saved registers.

[Machineleesbare evidence](firmware/bt-pairing/contracts.json) bevat bronbytes, fixture-uitkomsten en aanvullende callerkandidaten. OS-/databasecalls zijn expliciete hooks. Er is geen native MIPS-code uitgevoerd en geen gedrag op de autoradio gemeten.

## Vereiste implementatie

De uitbreiding moet de Blue-recordbank, reload/reorder/delete en de AppMain-record-/naamopslag samen aanpassen. Daarna moeten alle toevoeg-, selecteer-, volmelding-, pagineer- en reconnectpaden op acht worden afgestemd. Vier schermregels blijven een paginagrootte; grenzen van vier mogen niet overal door acht worden vervangen. Voor de naamcache kan eerst onderzocht worden of callers uitsluitend uit de UTF-8-recordnamen lezen, zodat een overbodige cache kan vervallen; dat is nog geen bewezen veilige wijziging.

Een bruikbare gecombineerde kandidaat vereist byte-level regressies voor acht verschillende adressen/namen, herladen, vooraan zetten, verwijderen van eerste/middelste/laatste koppeling, reconnect van nummer acht en een negende pairing weigeren. Op de unit moeten dezelfde acties, een volledige herstart en audio/telefonie met het achtste apparaat worden gecontroleerd. Daarna kan een nieuw LGU met playback- en navigatiefix worden gebouwd en onafhankelijk uitgepakt. **Er is nog geen MAX03 of acht-apparatenupdate.**

Het [verdere sleutelopslagonderzoek](bt-key-store-contracts.md) volgt inmiddels acht native SC-writes en de exacte sleutelrespons per adres in vers interpretergeheugen. Hostlookup en de gevolgde SC-enumerator kunnen ook aangeleverde databases met negen/zestien records verwerken; dat bevestigt geen radio/controllercapaciteit. De native iterator negeerde API-BOOL en hergebruikte een afgesloten cursor; een afzonderlijke interpretervariant vangt die fouten en seek/restart-cleanup af. Partial-resultstatus, allocatie en unitvalidatie blijven open.

Het [sleutelstackvervolg](bt-key-stack-contracts.md) volgt die response verder door oorspronkelijke CM/DM-tabellen, dynamische DM-cache, controllercommandoserialisatie en HCI ready/deferred FIFO tot de transportcallbackfixture. Acht/zestien hostrecords hebben daar ieder een eigen juiste sleutel; typepolicy, ontbrekende transportcallback en dertien allocationfaults zijn apart vastgelegd. Dit onderbouwt acht opgeslagen koppelingen verder, maar bevat nog geen fysieke controllerauthenticatie of nieuwe LGU.
