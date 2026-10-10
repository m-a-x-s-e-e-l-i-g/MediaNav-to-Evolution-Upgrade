# Navigatie — contentinitialisatie en corruptiemelding

De foutmelding is verder gevolgd in de beschikbare navigatiefix `nngnavi.exe`, versie 9.4.6.398870. SHA-256 `d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9`. Dit is niet een dump van het navigatiebestand dat Max vóór de losse fix gebruikte; dezelfde tekst op die unit bewijst daarom nog niet dezelfde codeflow.

## Wat de beschikbare executable controleert

Caller `0x4f8e48` leest `interface/bilang_city` en roept routine `0x4fae54` aan. Bij nulresultaat toont hij op `0x4f8ec4` de tekst `File corruption detected, Navigation stops.` en vraagt via `0x6f9c58(1)` afsluiten aan. Een niet-nulresultaat slaat dit foutpad over.

De normale nulreturn van `0x4fae54` is nu exact geïdentificeerd: de objectpointer op globaal adres `0x984374` heeft **gelijke begin-/eindpointers op offsets +18/+1c**. De assembly op `0x4faeac..0x4faeb8` vergelijkt ze en springt rechtstreeks naar de epiloog met `$v0=0`. Het volledige niet-lege pad eindigt op `0x4fb908` met `$v0=1`. Dit is dus een leegtecheck van een geaccepteerde contentlijst, niet op deze plaats een CRC van de gehele executable. Interne faults/excepties vallen buiten deze normale returnanalyse.

Het niet-lege pad verwerkt 68-byte contentrecords, maakt mapobjecten, laadt hun headers, verwijdert mislukte/oudere records en sorteert de resterende lijst. Individuele latere loadfailures veranderen zijn eindreturn niet naar nul. Zelfs nul resterende mapobjecten volgt hier nog de normale successreturn; de oorspronkelijke managerlijst en de gebouwde mapobjectlijst zijn verschillende structuren.

## Waar de lijst vandaan komt

Constructor `0x3a48f4` initialiseert zes accepted-contentvectors en zes rejected-contentvectors en bewaart zichzelf in de global. Hij vraagt zes benoemde licentiedistributors op en registreert drie callbacks. `0x3a61a8` scant via de `folders`-config zes oorspronkelijke UTF-16-patterns:

| Categorie | Pattern | Header-magic (DWORD) | Geaccepteerde formaatversie |
| --- | --- | --- | --- |
| 0 | *.fbl | 07067619 | 700–900 |
| 1 | *.fjv | a618ab04 | 1–200 |
| 2 | *.fpa | 4536abc6 | 1–200 |
| 3 | *.fsp | d6d3bb98 | 1–200 |
| 4 | *.ftr | d6c3abb1 | 1–200 |
| 5 | *.fda | 26b3afb1 | 1–200 |

Dit zijn interne **formaatversies**, geen kalenderjaren of MediaNav-firmwareversies. De gegevens komen uit drie zes-DWORD-tabellen op `0x900638`, `0x900650` en `0x900668`. De patterns staan via pointertabel `0x96b3a0` vastgelegd.

De scanner probeert eerst de persistente cache `mapmanagerizr` via `0x3a4570/0x3a3cc8`. De cache wordt vergeleken met de actuele filelijst/metadata en distributorbeslissingen. Bij een mislukte cachevalidatie worden gedeeltelijke vectors leeggemaakt en volgt de filescan. Het bestaan van dit pad bewijst geen corrupte cache op de unit; er is geen actuele cachekopie beschikbaar.

Reader `0x3a5904` vraagt maximaal 2048 headerbytes op, ondersteunt een `SET`-envelop met sectie-offsets en controleert section/filegroottes. De gewone header heeft magic op offset 0 en formaatversie op offset 4. Een categorie-mismatch voegt geen accepted record toe. De formaatversie moet binnen de inclusieve grenzen vallen; daarna bepaalt de distributor-call via vtable-slot +1c of append wordt geprobeerd. `0x3a6844` houdt ook rekening met bestaande versies/suppliers en voegt uiteindelijk toe aan de categorievector. Dit onderzoek verandert geen licentiecontrole.

## Een preciezere foutmelding bestaat al

Callback `0x3a4f38` controleert dezelfde lege categorie-0-vector. Hij onderscheidt:

- teller +c0 niet nul: `Cannot open the available map files with your license`;
- anders teller +a8 niet nul: `Your map files are outdated, please visit your distributor`;
- anders: `Couldn't find any map files`.

De algemene corruptiemelding verbergt daardoor verschillende mogelijke inputproblemen. Welke van deze toestanden Max werkelijk heeft, is nog niet bekend. De updatepakketten bevatten **nul bestanden van deze zes contenttypen**; zij leveren geen actuele kaarten, contentmetadata of license-state voor vergelijking.

## Evidence en vervolg

`py tools/inspect_navigation_content.py` controleert de originele modulehash, bewaart negen volledige pdata-functiebereiken, vijf exacte instruction-preimages, alle vier tabellen en zes patternstrings. Uitvoer: [navigation-content-contracts.json](firmware/navigation-content-contracts.json). Geen firmwarecode is uitgevoerd of gepatcht.

De eerstvolgende diagnostische vergelijking betreft de geïnstalleerde executable, `folders`-paden, headers van beschikbare `.fbl`-bestanden en de actuele cache. Dat kan aantonen of de leegte uit file discovery, formaatversie, distributorbeslissing of cacheherstel komt. Volledige cache-/SET-serialisatie, streamownership, distributorimplementaties en callbackvolgorde blijven lokaal onderzoekbaar. Zonder een ongemodificeerd origineel van dezelfde executableversie blijft de interne patch van de bestaande losse fix onbekend.
