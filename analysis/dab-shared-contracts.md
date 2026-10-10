# DAB-station, presets, scanlijst en EPG: gedeeltelijke layouts

De producent is MgrDAB; de consument AppMain. Onderstaande velden zijn uit producerwrites en, waar beschreven, consumerreads afgeleid. Ze zijn geen complete SDK-structdefinities. [inspect_dab_shared.py](../tools/inspect_dab_shared.py) bewaart sourcehashes en oorspronkelijke bytes in [dab-shared-contracts.json](firmware/dab-shared-contracts.json). [parse_dab_shared.py](../tools/parse_dab_shared.py) leest uitsluitend offline snapshots, controleert recordgroottes en houdt ruwe bytes beschikbaar.

## Huidig station en presets

`UpdateCurrentChannel`, **`0x1925c–0x197c7`**, vult een globaal stationrecord op VA `0x7b2b4` uit de interne kanaal-/ensemble-/frequentiegegevens. Zijn logstrings benoemen ensemblelabel, stationlabel, frequency-ID, EID, PTY, SID, SubChID en kanaalindex. Helpers `0x2784c/0x2792c` initialiseren een record van `0x66c` bytes en zetten kanaalindex `+0x664` op -1. Publicatie gaat via `0x29000 → 0x27908 → 0x268bc` naar `ShmFmMgrDABCurrentStation`.

| Offset | Gevolgd veld |
| --- | --- |
| `000` | Ensemblelabel, kopie 34 bytes UTF-16 |
| `024` | Stationlabel, kopie 34 bytes UTF-16 |
| `22c` | PTY DWORD |
| `230` | Frequency-ID string, kopie 10 bytes UTF-16 |
| `244` | DLS-textbuffer, `0x102` bytes |
| `654` | EID WORD |
| `658` | SID DWORD |
| `65c` | Frequentiewaarde DWORD, eenheid nog niet bevestigd |
| `660` | Subchannel-ID byte |
| `664` | Kanaalindex DWORD, -1 ongeldig/onbekend |
| `668` | Overige status/componentbyte, nog niet volledig benoemd |

DLS-helper **`0x278c8`** kopieert `0x102` bytes of maakt bij NULL alleen het eerste WCHAR nul. Het is geen volledige bufferzeroing. AppMain leest deze buffer als tekst op mapping `+0x244`. De offline decoder begrenst de tekst en geeft aan wanneer een terminator of geldige UTF-16 ontbreekt.

Presetmapping **`0x4d14`** bevat twaalf volledige `0x66c`-records, gevolgd door signed selectie-DWORD op **`0x4d10`**. Reset `0x27ef4` maakt alle records nul, zet ieder kanaalindexveld op -1 en de selectie op 0. Andere routes zetten die selectie op -1. AppMain **`0x99678`** gebruikt bij selectie -1 en zijn overeenkomstige statusflag een fallback: de twaalf presetkanaalindices vergelijken met het actuele kanaal en de eerste match teruggeven, anders -1.

Preset-infohandler **`0x27fd0`** vereist een non-NULL payload, selectie >-2 en payloadbyte 0 <12. Hij zet kanaalindex uit payloadbyte 2, SubChID uit byte `0x10`, SID uit DWORD `0x0c` en EID uit WORD 8. De gelogde frequentie uit payload DWORD 4 wordt in deze handler niet naar het frequentieveld gekopieerd. Labelhandler **`0x280a0`** kopieert 34 bytes van payload `+4` naar stationlabel. De gevolgde handlers hebben geen ontvangen-payloadlengteargument; de volledige caller-validatie is nog niet aangetoond.

De interne presetkopiehelper **`0x28154`** doet `memcpy(base + index*0x66c, source, 0x66c)` zonder eigen indexgrenscheck, schrijft de geselecteerde index en publiceert alles. Caller **`0x2901c`** geeft hem een kopie van het huidige station. Dit bewijst een lokaal ontbrekende guard, niet dat een normale UI-call een ongeldige index levert.

## Scanlijst

Producer **`0x285b4–0x287bf`** reserveert en zeroet `0x714c` bytes. Hij loopt interne pointertriples af en neemt uitsluitend kanaalrecords waarvan sourcebyte `+0x0d` gelijk is aan 0, 1 of 2. De teller wordt vóór toevoeging begrensd op **250**. De outputstride is **`0x74` /116 bytes**, met count-DWORD op **`0x7148` /29000**; totale mapping 29004 bytes. AppMain **`0x96184`** leest die teller en normaliseert waarden buiten 0..250 naar nul. De clickhandler **`0x96428`** gebruikt dezelfde stride en stuurt kanaalbyte `+0x64` van het gekozen record als DWORD via AppMain→MgrDAB commando `68`.

| Offset in compact record | Herkomst / bekend veld |
| --- | --- |
| `00` | Source WORD `+5c`: EID |
| `04` | Source DWORD `+04`: SID |
| `08` | Source byte `+08`: SubChID |
| `0a` | Source `+66`, 34 bytes stationlabel |
| `2c` | Tweede pointer in triple, 34 bytes ensemblelabel, bij NULL eerste WCHAR nul |
| `50` | Source DWORD `+10`: PTY |
| `54` | Derde pointer, 10 bytes frequency-ID, bij NULL eerste WCHAR nul |
| `60` | Source DWORD `+60`: frequentiewaarde |
| `64` | Source byte `+01`: kanaalindex |
| `65..69` | Sourcebytes `+09,+0b,+03,+0d,+0e`, betekenis deels open |
| `6c` | Nogmaals source DWORD `+10` |
| `70` | Source byte `+14`, betekenis open |

De ontbrekende/paddingbytes blijven door de volledige beginzeroing nul. Een NULL lijst maakt de hele mapping nul. De decoder weigert een negatieve count of count >250 en kan het aantal getoonde records begrenzen zonder de oorspronkelijke count te veranderen.

## EPG

EPG-mapping **`0x19cc` /6604 bytes** bevat maximaal **100 records** van **`0x42` /66 bytes**, met count op **`0x19c8` /6600**. Appender **`0x27d84`** controleert alleen `count <100`, berekent de bestemming en schrijft WORDs op offsets 0, 2, 6, 8 en 10 uit aangeleverde velden. De tekstkopie op offset 16 is 50 bytes, gevolgd door een nul-WORD op offset 64. Die terminator overschrijft dus de laatste twee bytes van de gekopieerde tekstbuffer: maximaal 24 UTF-16-codeunits plus NUL.

De offline decoder benoemt deze vijf WORDs voorlopig niet als datum/tijd of event-ID. Dit voorkomt dat een plausibele kalenderinterpretatie als bewezen contract wordt gepresenteerd. De appender heeft geen eigen negatieve-counttest en zijn tekstbronlengte wordt in deze functie niet gecontroleerd. Reset **`0x27e24/0x27e58`** zeroet de mapping; aanvullende classvelden buiten de mapping worden afzonderlijk ingesteld. Er bestaat daarnaast een interne collectie van 24 records met stride `0x6c4`; dat is een andere indeling en geen directe kopie van de EPG-shared-memoryrecords.

## Status van het onderzoek

De scanstride, 250-grens, veldkopieën en tellerlocatie zijn tegen oorspronkelijke MIPS-instructies gecontroleerd. Presetfallback en signed selectie zijn uit AppMain gevolgd. Offline fixtures controleren alle vier snapshotgroottes, maximum-/negatieve counts, labels, kanaalindex, selectie en behoud van onbekende bytes. De bronhash en codebytes zijn reproduceerbaar; een echte unitcapture ontbreekt.

Nog open: volledige stationstatusvelden; labelcodering vóór de UTF-16-kopie; EPG-WORD-betekenis; producer-/consumerlocking; exacte bronpayloadgrenzen; alle ontvangst- en refresh-events. [dab-options-contracts.md](dab-options-contracts.md) beschrijft de aparte optiestructuur en [dab-update-contracts.md](dab-update-contracts.md) de firmwareketen.
