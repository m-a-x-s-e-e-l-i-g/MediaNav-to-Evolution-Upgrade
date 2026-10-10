# MPPC-compressie, tokenformaat en decodergrenzen

Originele ROM-ppp.dll SHA-256 `b5f6bd4f0d8295e9203b3f92bd23a2920ecc086804f76caadb2e18d9e6d05df5`. [JSON-evidence](firmware/mppc-contracts.json) bewaart beide volledige routines, resets en de 256-DWORD hashtabel. Reproduceer met `py tools/inspect_mppc.py`; de [begrensde offline parser](../tools/parse_mppc.py) ondersteunt lokale payloadbestanden en `--hex`. Geen firmwarecode is uitgevoerd.

## Originele functies en state

| Adres | Omvang | Gevolgd gedrag |
| --- | ---: | --- |
| c044065c | 2684 bytes | Compressor, hashlookup, literals/copy-tuples, expansionfallback |
| c04410d8 | 72 bytes | Reset compressorhistory en matchtabel |
| c0441120 | 36 bytes | Reset decoderhistory en cursor |
| c0441144 | 1944 bytes | Decoder, literals/copy-tuples, historyoutput |
| c0431f50 | 1024 bytes | 256-DWORD three-byte hashwaarden |

De 8192-byte history ligt aan het begin van de state. Compressor `+2004` is een offset en `+2008` een hoogste historypointer; de matchtabel van 4096 WORDs ligt op `+264c`. De decoder gebruikt `+2004` als absolute cursor. Beide resethelpers nulmaken `2001` bytes history; de compressor reset bovendien de `2000`-byte matchtabel.

Alle 256 hashwaarden zijn exact `bytewaarde * 009ccf93`. De compressor combineert drie waarden met twee vermenigvuldigingen met 256, reduceert de 32-bit som en neemt bits12..23 als tabelindex. De tabel bewaart een historypositie als WORD. Dit stelt de hashkeuze vast; het offline tokenmodel beweert geen exacte emulatie van alle matchkeuzes.

Bij nulhistory of onvoldoende ruimte (cursor + input > `1ffd`) verplaatst de compressor de cursor naar nul en retourneert hij de at-front-flag `4000`. Historyinhoud hoeft daarbij niet gewist te worden. Als compressie meer bytes oplevert dan de oorspronkelijke input, reset hij history/matchtabel, zet cursor `2001` en retourneert `8000` voor ongecomprimeerde fallback. De originele inputlengte blijft dan staan. Bij succes zet hij `2000`, bewaart de gecomprimeerde omvang en de nieuwe cursor. De caller kiest/verwisselt vervolgens buffers zoals beschreven in [CCP-contracten](ppp-ccp-contracts.md).

## Wiretokens

De bitstream is MSB-first. Literals onder 128 gebruiken hun acht bits; hogere literals gebruiken prefix10 met zeven databits. Copyoffsets gebruiken drie prefixklassen: onder64, 64..319 en 320..8191. De matchlengte gebruikt een oplopende prefix met de bijbehorende lengtebits. Dit komt overeen met [RFC 2118, sectie 4](https://www.rfc-editor.org/rfc/rfc2118.html#section-4).

De offline parser controleert alle 256 literals, alle 8191 positieve offsets en alle 8189 standaardmatchlengtes. Het openbare tekst-/tuplevoorbeeld uit de RFC decodeert exact naar zijn oorspronkelijke bytes. De parser biedt `--standard` voor het grotere standaardformaat; standaard volgt hij de waargenomen lengteprefixtabel van deze vendor-decoder.

```powershell
py tools/parse_mppc.py --self-test
py tools/parse_mppc.py --hex 414243
py tools/parse_mppc.py <lokaal-gecomprimeerd-payloadbestand>
```

Deze invoer is uitsluitend de MPPC-payload. PPP/CCP-headers zitten hier niet bij. De losse CLI-aanroep begint met een lege history; gebruik van eerdere packets vereist een behouden Decoder-object en correcte flush/at-front-flags. Na een parsefout moet de caller zijn history resetten. De parser opent geen apparaat of netwerkverbinding.

## Asymmetrische maximale matchlengte

De encoder heeft branches voor lengtes 2048..4095 (`c0440c58..c0440d08`) en 4096..8191 (`c0440d0c..c0440e08`). De decoder stopt na de lengteklasse1024..2047. Een langere prefix bereikt `c0441794` en retourneert nul via `c04418d4`; de klassen2048..8191 ontbreken daar.

Dit is een concrete asymmetrie tussen encoder en decoder. De normale onderzochte framegrootte1502 plus ingesloten protocol blijft onder2048, waardoor die lange matches op dat defaultpad niet nodig zijn. Grotere MRU-/frameconfiguraties en interoperabiliteit met een peer die langere matches stuurt moeten apart worden gevolgd. De offline `--standard`-modus is geen voorspelling dat de firmware zulke streams accepteert.

## Input- en historygrenzen

Assembly bevestigt meerdere afwijkingen:

- `c0441158/c0441164` lezen twee inputbytes voordat enige vergelijking met inputomvang gebeurt. De CCP-caller kan een header van twee bytes verwijderen en vervolgens met een kortere resterende payload de decoder aanroepen.
- Binnen tokens zijn refill-reads (`lbu` na cursorincrement) niet vooraf tegen packetend bewaakt. De outer-loopvergelijking op `c0441878` gebeurt pas nadat een token verwerkt is. Hierdoor kan korte of afgekapt aangeboden input bytes buiten de opgegeven payload gebruiken; daadwerkelijk fysieke leesbaarheid hangt af van de packetallocatie.
- Een copy-tuple wordt geweigerd wanneer de output-endpointer **groter dan of gelijk aan** history+8192 is (`c0441834..1838`). De letterlijke byte-store en de uiteindelijke één-byte tail-store hebben geen overeenkomstige history-endcheck in deze routine. Voldoende opeenvolgende literals kunnen dus de opgegeven historygrens overschrijden voordat de caller zijn uiteindelijke outputlengte vergelijkt.
- De copysource-start wordt gemaskeerd met `1fff`, waarna de kopieerloop zijn sourcepointer lineair verhoogt. Binnen die loop is geen tweede modulo- of source-endcheck zichtbaar. Een synthetische tuple kan daardoor na de history in statevelden lezen; de precieze bereikbaarheid met echte peerdata is niet dynamisch getoetst.

De decoder accepteert de lange offsetprefix als 13 bits +320 en valideert het resultaat niet expliciet tegen8191. De source-mask reduceert ook grotere resultaten. De eigen parser weigert offsets0 en >8191 en bewaakt input/output/copysource vóór gebruik. Hij reproduceert dus **het gedocumenteerde tokenformaat met expliciete grenzen**, niet de onbegrensde refill-/literalpaden van de firmware.

Een parsefout of output boven de ontvangende MRU-buffer veroorzaakt in CCP een drop/reset of drop, maar die controle gebeurt na decompression. Dat is geen bescherming van alle interne historywrites.

## Bewijsgrenzen en vervolg

De vier negatieve parserfixtures controleren truncated literals/prefixes, offset0 en literaloutput buiten history. Het gecontroleerde standaardformaat, de ontbrekende decoderlengteklassen en de genoemde oorspronkelijke guards zijn nu reproduceerbaar vastgelegd.

Open blijven de exacte compressor-matchkeuzes over meerdere packets, alle bit-refillrandgevallen van de originele decoder, allocation/padding/lifetime, effectieve MRU op de USB-verbinding en fysieke unitcaptures. Geen van deze statische afwijkingen is gepresenteerd als een waargenomen crash of werkende aanval op de MediaNav.
