# MediaNav ACT3/RAC3-fontcontainer

Dit onderzoek decodeert de twee RAC3-blokken uit het meegeleverde font volledig. De bitmaptabel en drie cmap-tabellen voldoen aan hun oorspronkelijke SFNT-checksums. De glyph-transformatie is nog niet teruggedraaid; het resultaat is een onderzoeksbestand, geen installeerbaar TrueType-font. Er zijn geen firmwareprogramma's uitgevoerd.

## Bron en formaat

Bron: `extracted/705md/upgrade/Storage Card/System/font/msgothic.ac3`, 4.862.120 bytes, SHA256 `56a074a4678998d626f930e1a1728af11a34a06fdbe507ae3478291fd14e5eb9`.

De `ttcf`-header bevat versie `0x10000` en drie faces. Hun Engelse naamrecords zijn MS Gothic, MS PGothic en MS UI Gothic, op offsets `0x18`, `0xb8618` en `0xc67c0`. De bitmap- en glyphdata worden gedeeld.

De identificatie en decoder volgen de ACT3/RAC3-beschrijving in [ISO/IEC 14496-18:2004, sectie 4.2](https://cdn.standards.iteh.ai/samples/40151/04f0c05be08843ff900b9140921f643e/ISO-IEC-14496-18-2004.pdf). Het formaat gebruikt een tabel met fysieke/virtuele blokposities, een tokendictionary, Huffmancodes en random-access-markers. Dit pakket gebruikt dictionarytokens van 1–64 bytes en indexpunten per 128 uitgepakte bytes. De standaard beschrijft daarnaast een afzonderlijke glyph-transformatie. Deze eigenschappen zijn waar mogelijk rechtstreeks tegen de bronbytes gecontroleerd.

## Blokken en controle

De descriptor staat op `0x4a3068`, is werkelijk 64 bytes en heeft drie records. De `act3`-directoryentry van de eerste face vermeldt daarentegen lengte `0x407724`; die lengte is dus geen geldige fysieke descriptorlengte.

| Blok | Fysieke start | Virtuele start | Uitgepakte bytes | RAC3-bytes | Tokens | Gecontroleerde indexpunten |
| --- | --- | --- | ---: | ---: | ---: | ---: |
| Ongecomprimeerde tabellen | 0 | 0 | 850.356 | — | — | — |
| EBDT | `0xcf9b4` | `0xcf9b4` | 2.310.192 | 1.381.877 | 25.324 | 18.049 |
| Glyphrepresentatie | `0x220fac` | `0x3039e4` | 4.224.804 | 2.629.819 | 37.368 | 33.007 |

De decoder leest codes met de hoogste bit eerst en koppelt iedere code aan een dictionarytoken. Alle 51.056 native indexpunten komen exact overeen met tokenbeginposities uit de volledige sequentiële decode. Ook de gedeclareerde outputlengtes worden exact bereikt. Er zijn drie paddingbytes na het eerste RAC3-blok en één na het tweede.

`EBDT` checksum `0x2f8a69a8` klopt. Alle drie cmap-checksums en de gedeelde loca-checksum `0x9a0d2cf8` kloppen. De uitgepakte glyphrepresentatie heeft checksum `0xf57e79af`, tegenover directorywaarde `0x387594cd`. Dit ondersteunt dat een volgende transformatie nog nodig is; het bewijst niet dat het originele font corrupt is.

De descriptor vermeldt uitgepakte bestandsgrootte 7.385.336, maar het laatste blok en GlyfEnd eindigen op 7.385.352. Dit verschil van 16 bytes is behouden en nog niet verklaard. De parser schrijft geen gecorrigeerde waarden in het origineel.

## Fontloading in de ROM

De bootregistry registreert `.ttf` en `.ttc` onder `System\GDI\FontFiles\TrueType`, driver `\windows\mgtt_o.dll`, en fontdirectory `\Storage Card\System\Font`. Tahoma en Arial Narrow linken naar `msgothic.ttc,MS Gothic`. Het updatepakket bevat `msgothic.ac3`.

In `gwes.dll` leest `c016e724` de extensies; `c0173808` gebruikt FontPath; `c01735d8` scant de bestanden en valt bij een ontbrekende match terug op Windows. `c017dbac` herkent een `.ac3`-suffix en geeft de gemapte gegevens aan de fontdriver. De mappinghelpers `c01caa40`, `c01ca86c` en `c01ca968` volgen filemappingpaden; in deze gevolgde paden is geen ACT3-decode aangetroffen.

In `mgtt_o.dll` leidt `FntDrvLoadFontFile c0261ab8` naar TTC-load `c026e150`, face-load `c026dc4c`, validatie `c026d9dc` en directorycontrole `c026a788`. De laatste controleert ieder offset/lengtepaar tegen de opgegeven bestandslengte, vóór herkenning van het tabletag. Met het ongewijzigde AC3-bestand faalt de eerste face op `act3` en alle faces op het bereik van `glyf`.

**Bewezen:** ongewijzigde pakketbytes voldoen niet aan de gevolgde directoryvalidator. **Open:** welke bytes en naam werkelijk op de geïnstalleerde unit staan, eventuele installatieconversie, aanvullende fontdrivers en runtimefallback. De aanwezigheid van een `.ac3`-naamcheck in GWES bewijst geen werkende ACT3-decoder in deze driver.

## Reproduceren

`py tools/parse_ac3_font.py --self-test` controleert één geldig synthetisch RAC3-blok en vijf ongeldige gevallen. `py tools/parse_ac3_font.py --output analysis/firmware/ac3-font` decodeert het echte pakket, controleert alle indexpunten en schrijft de drie blokken, `virtual-font.bin` en [manifest](firmware/ac3-font/manifest.json). Dit model voert geen MIPS- of Windows CE-code uit.

Open vervolg: CTF-glyphtransformatie, een zelfstandig tweede decodepad, interpretatie van het 16-byte verschil en het daadwerkelijke installatie-/fontloadpad.
