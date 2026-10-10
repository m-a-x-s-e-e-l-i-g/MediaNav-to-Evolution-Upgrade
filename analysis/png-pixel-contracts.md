# PNG-pixelconversie, transparantie en alle 54 Adam7-scatterhelpers

De resterende PNG-pixelhelpers zijn aan concrete bronbytes gekoppeld. Twee afwijkingen zijn in assembly bevestigd: de 1-bit grayscale-tRNS-route vergelijkt een bitmasker met een genormaliseerde transparantiewaarde, en de 16-bit grayscale/RGB-route vergelijkt uitsluitend de hoge samplebytes. De oorspronkelijke firmware is niet uitgevoerd; kleine lokale PNG-fixtures en expliciete rekenmodellen tonen het verschil met exacte transparantievergelijking.

Bron: ROM `imaging.dll`, SHA-256 `f7592cc3360d97674a189c60b7d56e75a15ad2bceafe5eef6da47e8f20b70908`. [Het eerdere PNG-rapport](imaging-png-contracts.md) volgt chunks, decompressie, filters, rijbuffers en statuspropagatie. `py tools/inspect_png_pixels.py` bewaart [69 oorspronkelijke bewijsbereiken, dispatch, fixtures en resultaten](firmware/png-pixel-contracts.json). De handmatige modellen staan in `tools/png_pixel_models.py`.

## Conversieroutes naar BGRA

`404990c8` kiest de converter op IHDR-color-type. De outputbytes worden geschreven in volgorde **B, G, R, A**. Dat is de little-endian representatie van de door imaging gebruikte ARGB-formatcode. De converters schrijven de kleurwaarden rechtstreeks; binnen deze functies wordt niet met alpha vermenigvuldigd. Latere sinkconversie en compositing kunnen afzonderlijk gedrag hebben.

| Color type | Routine | Gevolgde bitdieptes | Gedrag |
|---|---|---|---|
| 0: grayscale | `404981f8` | 1/2/4/8/16 | Packed sample naar grijs; bij 16 bit hoge byte gebruiken; eventuele tRNS-alpha |
| 2: RGB | `404984bc` | 8/16 | RGB naar BGR; bij 16 bit hoge bytes; eventuele tRNS-alpha |
| 3: indexed | `40498628` | 1/2/4/8 | Palette-index uitpakken; RGB-palet naar BGR; alpha uit tRNS-table |
| 4: gray+alpha | `404989b4` | 8/16 | Gray naar drie kanalen; alpha overnemen; bij 16 bit beide hoge bytes |
| 6: RGBA | `40498a78` | 8/16 | R/B omwisselen; alpha behouden; bij 16 bit vier hoge bytes |

Gray 1/2/4 wordt respectievelijk naar 0/255, veelvouden van 85 en veelvouden van 17 uitgebreid. Indexed samples worden eerst naar 0..1, 0..3, 0..15 of 0..255 genormaliseerd. Een geldige palette-index zonder bijbehorende tRNS-entry krijgt alpha ff. Een index buiten de beschikbare paletcount krijgt in deze converter opaque zwart; de strenge referentieroute wijst die af.

De converters retourneren E_FAIL bij een niet-ondersteunde bitdiepte of color type. De ARGB-branch van `404991cc` roept `404990c8` aan zonder zijn returnwaarde te testen. Of iedere ongeldige combinatie eerder wordt afgewezen is nog niet volledig vastgesteld; een succesvolle malformed decode wordt hiermee niet geclaimd.

De twintig gewone converterfixtures omvatten grayscale 1/2/4/8, RGB8, indexed 1/2/4/8, gray+alpha8 en RGBA8, met tRNS waar van toepassing. Native rekenprojectie, strenge referentieroute en Pillow komen voor deze geldige controlecases exact overeen. De afwijkende transparantiegevallen worden afzonderlijk gehouden.

## 1-bit transparantie: masker versus samplewaarde

Assembly `40498448..40498484` maakt `1 << (7-position)` en ANDt dat met de bronbyte. Het resultaat wordt voor grijs juist als zero/nonzero gebruikt, maar voor alpha rechtstreeks vergeleken met `tRNS-lowbyte & 1`. Het resultaat wordt daar niet teruggeschoven naar nul of één.

Bij transparantiewaarde 0 werken alle zwarte pixels correct. Bij transparantiewaarde 1 heeft een witte pixel in de eerste zeven posities van iedere bronbyte echter waarde 128/64/32/16/8/4/2. Alleen positie zeven levert waarde 1.

Een valide 8×1 grayscale-PNG met depth 1, bronbyte ff en tRNS `00 01` toont de rekenkundige afwijking:

| Alpha van pixel 0..7 | Waarden |
|---|---|
| Exacte transparantie | `00 00 00 00 00 00 00 00` |
| Gevolgde native converter | `ff ff ff ff ff ff ff 00` |

Voor beide transparantiewaarden, alle 256 bronbytes en alle acht pixelposities zijn 4.096 alpha-uitkomsten vergeleken. Daarvan wijken er **896** af. De evidence bevat de volledige kleine PNG als hex, de native BGRA-projectie en de correcte BGRA-output. Het is een fixture voor analyse, geen aangepaste firmware of flashpakket.

## 16-bit transparantie: lage bytes worden niet vergeleken

Gray16 assembly `40498270..404982b4` leest uitsluitend bronbyte nul en tRNS-byte `+cc`, vergelijkt die voor alpha en loopt daarna twee bronbytes verder. RGB16 assembly `40498510..40498594` vergelijkt bronbytes 0/2/4 met tRNS-bytes `+cc/+ce/+d0`. De lage bytes 1/3/5 worden dus niet betrokken in de transparantietest.

De [PNG-specificatie, tRNS en sample-depth-rescaling](https://www.w3.org/TR/png-3/#11tRNS) vereist vergelijking van de volledige oorspronkelijke samples voordat hun precisie wordt verminderd. Hoge bytes gebruiken voor de zichtbare 8-bit kleur is op zichzelf een mogelijke reductie; die gereduceerde waarde gebruiken voor tRNS kan verschillende bronkleuren transparant maken.

Twee concrete geldige inputs:

| Input | Transparante kleur | Exacte alpha | Native alpha-projectie |
|---|---|---|---|
| Gray16 `1234`, `1235` | `1234` | `00 ff` | `00 00` |
| RGB16 `(1234,4567,89ab)`, `(1235,4567,89ab)` | `(1234,4567,89ab)` | `00 ff` | `00 00` |

Voor zes graykeys zijn alle 65.536 samplewaarden vergeleken: 393.216 sample/key-paren, met **1.530** onterecht transparante uitkomsten. Voor één RGB-key zijn de 256 mogelijke lage bytes van elk kanaal afzonderlijk gevarieerd: 768 cases, waarvan **765** onterecht transparant worden. Dit is geen exhaustieve vergelijking van alle RGB16-kleuren.

De fixtures passeren de strenge lokale chunk-, CRC- en scanlijnparser. Voor de 16-bit afwijkingen wordt de exacte oorspronkelijke samplevergelijking als oracle gebruikt; Pillow wordt voor die alpha-cases niet als norm aangemerkt. Native unitweergave en andere applicatie-ingangen blijven ongeverifieerd.

## Extended RGB/RGBA-output

De aparte routines `40497c2c` en `40497d44` schrijven zes respectievelijk acht bytes per pixel. Ze lezen 16-bit big-endian samples en berekenen voor ieder kanaal:

`scaled = (sample * 8192 + 32767) // 65535`

Output is B/G/R en eventueel A als little-endian woorden. Deze numerieke mapping naar 0..8192, inclusief rounding, komt voor alle 65.536 invoerwaarden overeen met exacte rational rounding. Voor samples 0/32768/65535 komt RGB-output bijvoorbeeld neer op B=8192, G=4096, R=0.

Dit beschrijft de native extended-formatconversie, niet de vereiste waarden van een algemene 16-bit PNG-export. De betekenis van die extended sinkkanalen en hun verdere verwerking blijft apart te onderzoeken. De gewone Decode-formatkeuze `404993f4` kan bovendien 48-bit RGB en 64-bit RGBA op ARGB32 terugzetten; de aanwezigheid van deze functies bewijst dus niet dat iedere PNG ze tijdens tekenen gebruikt.

## Alle 54 Adam7-scatterhelpers

De echte pointertabel begint op **`404850d8`**, met negen bit-per-pixelgroepen maal zes passes. `404850d4` behoort nog tot het eind van de versionstring/alignment en is geen eerste scatterpointer. De dispatchuitdrukking vanaf dat adres gebruikt een passnummer vanaf één, waardoor hij wel de juiste eerste pointer bereikt.

| Bits per pixel | Pass 1 | Pass 2 | Pass 3 | Pass 4 | Pass 5 | Pass 6 |
|---|---|---|---|---|---|---|
| 1 | `404a73e8` | `404a7458` | `404a74e4` | `404a755c` | `404a7608` | `404a7668` |
| 2 | `404a76dc` | `404a774c` | `404a77d8` | `404a7850` | `404a78fc` | `404a795c` |
| 4 | `404a79d0` | `404a7a18` | `404a7a64` | `404a7aac` | `404a7af8` | `404a7b40` |
| 8 | `404a7b9c` | `404a7d94` | `404a7fa4` | `404a819c` | `404a83ac` | `404a85a4` |
| 16 | `404a7bd0` | `404a7dcc` | `404a7fd8` | `404a81d4` | `404a83e0` | `404a85dc` |
| 24 | `404a7c1c` | `404a7e1c` | `404a8024` | `404a8224` | `404a842c` | `404a862c` |
| 32 | `404a7c70` | `404a7e74` | `404a8078` | `404a827c` | `404a8480` | `404a8684` |
| 48 | `404a7cac` | `404a7eb4` | `404a80b4` | `404a82bc` | `404a84bc` | `404a86c4` |
| 64 | `404a7d48` | `404a7f54` | `404a8150` | `404a835c` | `404a8558` | `404a8764` |

Dit zijn leafroutines; iedere behouden range eindigt op `jr ra` plus delay slot. Ze vallen niet allemaal onder de eerder gebruikte .pdata-/Ghidra-functiecatalogus. De pointertabel en originele bytes leveren hier onafhankelijke bereik-evidence.

Voor 8..64 bits kopiëren ze complete pixels op starts 0/4/0/2/0/1 en stappen 8/8/4/4/2/2. De 16/48-bit bytecombinaties lijken in assembly op endianconversie, maar schrijven uiteindelijk de oorspronkelijke bytes in dezelfde volgorde terug. De 32/64-bit routines gebruiken unaligned wordloads/stores; zij interpreteren de kleurkanalen niet.

Voor packed 1/2-bit pixels gebruiken twaalf nibble-lookuptabellen op `404851b0..4048536f` vier-, twee- of éénbyte entries. Pass 1/3/5 schrijft de uitgezette bits; pass 2/4/6 ORt de tussenliggende bits erbij. Alle **192** oorspronkelijke table-entries zijn met de afzonderlijke bitposities vergeleken.

De 4-bit helpers zetten hoge nibbles op de passlocaties. Pass 6 schuift de samples naar lage nibbles en ORt ze met de eerder ingevulde hoge nibbles. Bronpadding kan ook voorbij de laatste geldige pixel worden uitgezet. Voor alle positieve breedtes 1..65.535, alle negen bitdieptes en zes passes zijn **3.538.890** arithmetic writebounds gecontroleerd: maximaal zeven bytes voorbij de geldige rijbytes, steeds binnen de gevolgde aligned rijallocatie. Er zijn hierbij geen grote buffers aangemaakt. Deze check bewijst geen volledige veiligheid van ongeldige headers of van de totale interlaced-imageallocatie.

De rijdispatch gebruikt voor `y mod 8`:

- 0: passes 1, 2, 4, 6.
- 4: passes 3, 4, 6.
- 2 of 6: passes 5, 6.
- Oneven rij: pass 7 rechtstreeks uit de inflater, zoals in het eerdere rapport gevolgd.

Voor breedtes 1..128 zijn 6.912 individuele scattercases en 4.608 complete even-rijcases gecontroleerd. De volledige rijcontrole begint met niet-nul sentinelbytes en bewijst dat de gevolgde samenvoegvolgorde alle geldige pixels invult. Alleen de zichtbare pixelbits worden vergeleken; ongebruikte rijpadding hoeft niet gelijk te zijn.

## Resterende grenzen

De concrete converters, palette-fallback, extended schaalformule en alle scatterhelpers zijn nu gekoppeld en met lokale rekenmodellen getoetst. Open blijven ongeldige color/depth-dispatch, extreme interlaced-allocation arithmetic, metadata-/color-managementroutes, algemene sinkconversie en compositing, runtimeownership en de volledige zlib-provider. De fysieke unit en zijn geïnstalleerde configuratie zijn niet onderzocht. GIF/JPEG en de overige firmwaremodules blijven deel van het actieve onderzoek.
