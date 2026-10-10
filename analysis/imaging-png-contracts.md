# PNG-chunks, decompressie, scanlijnen en foutpropagatie

De PNG-route is gevolgd van de gekopieerde bronstream tot IDAT-decompressie, scanlijnfilters, Adam7-bufferindeling en de overdracht aan de imaging-sink. De opvallendste foutketen: een ontbrekende rijstaart wordt met nullen aangevuld en als parserfout gemarkeerd, maar de gevolgde rij- en EndDecode-wrappers testen die vlag niet. Daarmee kan deze keten een rij doorgeven zonder die decompressiefout als HRESULT te melden. Dit is statische code-evidence; er is geen beschadigd beeld op de unit uitgevoerd.

Bronnen zijn ROM `imaging.dll` (SHA-256 `f7592cc3360d97674a189c60b7d56e75a15ad2bceafe5eef6da47e8f20b70908`) en ROM `zlib.dll` (`1b3ef3cb314b72f188fadfb19cffe961b028d20d3fefc5350a3221e9879d43e8`). `py tools/inspect_imaging_png.py` bewaart oorspronkelijke bytes, hashes, rekenmodellen en assetvergelijkingen in [de evidence-JSON](firmware/imaging-png-contracts.json). De eerdere [factoryanalyse](imaging-factory-contracts.md) beschrijft streamownership; de [BMP-analyse](imaging-bmp-contracts.md) bevat de codec-vtables en PNG-formatmapper.

## Gevolgde code

| Functie | Gedrag |
|---|---|
| `404a4a3c` / `404a643c` | Parserobject en basisvelden initialiseren |
| `404a6a18` / `404a63ec` | Signature en latere dimensie-/depthchecks |
| `404a655c` / `404a5248` | Bronkopie, chunkselectie en metadatahandler |
| `404979c8` / `404a5f98` | BeginDecode en scanlijnbufferallocatie |
| `404a5c70` / `404a6f68` | Inflater initialiseren |
| `404a6cb0` / `404a6e9c` | IDAT-invoer, zlib-output en ontbrekende bytes |
| `404a70ec` | Scanlijnfilters |
| `404a5abc` / `404a5cf8` | Eerste zes Adam7-passes: sizes, decompressie en filters |
| `404a87b4` / `404a89b8` | Adam7-dispatch voor samengestelde even rijen |
| `404a6118` / `404991cc` | Rijpointer leveren en sinkrijen invullen/committen |
| `404993f4` / `40497ad8` | Decode-formatkeuze en EndDecode-status |
| `404a6f3c` / `404a5cc8` | inflateEnd en rijbufferstate beëindigen |

## Kopie en chunks vóór de pixellimiet

`404a6a18` alloceert eerst acht signaturebytes. De readhelperstatus wordt getest, maar hier wordt niet afzonderlijk geëist dat daadwerkelijk acht bytes zijn gelezen. `404a655c` scant vervolgens chunkheaders, telt nominale bestandsbytes op en alloceert een kopie van die omvang. De allocatiehelper gebruikt HeapAlloc-flags nul; de buffer wordt hier niet automatisch geïnitialiseerd.

Chunklengtes boven `7fffffff` worden in de eerste scan afgewezen. De size-accumulatie en offsets gebruiken 32-bit arithmetic. Een niet-nul headerreadcount houdt de scan gaande; de routine eist hier niet steeds count=8. Bij de complete bronread wordt HRESULT getest, maar de nominale buffersize blijft bewaard zonder vergelijking met de werkelijk gelezen count. De gevolgen hangen mede af van de eerdere streamimplementatie en seekgrenzen. Alle malformed-offsetcombinaties en eventuele upstream-afwijzing zijn nog niet bewezen.

Pas na deze kopie controleert `404a6a18` breedte en hoogte tegen 65.535 en het product tegen 67.108.864 pixels. De scanlijnbuffer wordt later aangemaakt. Deze dimensiegrens beschermt dus niet de eerdere gecomprimeerde bronallocatie. De gevolgde guard is ook geen volledige PNG-IHDR-validator: onder meer alle nulafmetingen, illegale color/depth-combinaties en eerdere metadata-afwijzingen vragen aparte reconstructie.

De chunkscan bewaart de eerste IHDR met payloadlengte groter dan twaalf en de eerste niet-lege IDAT. PLTE bewaart een pointer en `length//3`; in deze routine staat geen clamp tot 256 records. Dat bewijst op zichzelf geen bufferoverschrijding in latere paletconversie. tRNS wordt in de metadatahandler wel tot 256 bytes begrensd. Niet-herkende critical chunks roepen de warningcallback met argument nul aan en leiden daardoor tot de rejectvlag `+7f`.

De gelezen chunk-CRC wordt op parseroffset `+8` opgeslagen. In de gevolgde chunkscan en metadatahandler is geen berekening of vergelijking met die CRC gevonden. Een afgebroken IDAT kan in de tweede scan worden geclamped en krijgt CRC-veld nul; afgebroken andere chunks stoppen de scan. Dit is bewust een claim over deze routines, geen volledige uitspraak over iedere imaging-ingang.

De officiële [PNG-specificatie](https://www.w3.org/TR/png-3/) beschrijft CRC over chunktype plus payload, vijf scanlijnfilters en zeven Adam7-passes. De lokale referentieparser controleert deze structuur strenger dan de gevolgde firmwareparser.

## Decompressieprovider en twee soorten integriteitscontrole

Imaging importeert `inflate`, `inflateEnd` en `inflateInit2_` uit ZLIB.dll. Initialisatie geeft versionstring `1.1.4`, streamsize `38` hex en windowBits afgeleid van de eerste gecomprimeerde byte. De export `zlibVersion` op `40145b94` wijst daadwerkelijk naar string `1.1.4` op `4014104c`.

`inflateInit2_` (`40145110`) controleert de major-versionchar en streamsize, accepteert windowBits 8..15 en koppelt bij positieve windowBits een Adler-functie. `inflate` (`401452a8`) controleert methode 8, windowgrootte, header modulo 31 en de uiteindelijke Adler-waarde; mismatch wordt `incorrect data check` en return `fffffffd`. De provider rapporteert dus een decompressiefout, ook al kan de imaging-wrapper die later onvoldoende doorgeven. Een PNG-chunk-CRC en deze zlib-checksum hebben verschillende invoer en codepaden.

`404a6cb0` roept inflate aan met flushargument 1, verwerkt geproduceerde bytes en zoekt bij uitgeputte invoer de volgende IDAT. Return 1 markeert stream-einde `+7d`. Negatieve zlibstatus wordt via `404a8a6c` aan de warninginterface doorgegeven. De volledige DEFLATE-blockdecoder, Huffmantabellen, afstandskopieën en dictionarypaden zijn hiermee nog niet gereconstrueerd. De versionstring bewijst ook niet dat ieder providerbyte identiek is aan een upstream-release.

## Filters en Adam7

`404a70ec` implementeert None, Sub, Up, Average en Paeth. De byteafstand is afgeronde bits-per-pixel gedeeld door acht, waardoor packed samples een afstand van één byte krijgen. De eerste rij gebruikt een nul-previousrij. De Paeth-keuze en tievolgorde zijn voor alle **16.777.216** triples van drie bytes met de referentieformule vergeleken.

Een onbekende filterbyte valt uit de routine zonder de rij te wijzigen en zonder foutvlag te zetten. De begrensde referentieparser wijst dezelfde byte af. Dit verschil is vastgesteld in de filterroutine; volledige succesvolle native verwerking van ieder beschadigd bestand wordt niet geclaimd.

Niet-interlaced verwerking gebruikt twee afwisselende, aligned scanlijnbuffers. Interlaced verwerking reserveert daarnaast de filtered data van de eerste zes Adam7-passes. `404a5abc` berekent prefixsizes; argument 7 omvat zes passes, niet zeven. De geometrie voor alle breedtes/hoogtes 1..64 en negen bits-per-pixelwaarden is tegen de standaardpassindeling gecontroleerd: 4.096 dimensieparen en 221.184 prefixsizegevallen.

`404a5cf8` decompresseert en unfiltert de eerste zes passes vooraf, met een nieuwe previousrij per pass. `404a89b8` kiest voor even outputrijen welke passes moeten worden samengevoegd; `404a87b4` dispatcht op bitdiepte en pass naar pixel-scatterhelpers. De zevende pass, de oneven volle rijen, wordt daarna uit de inflater gelezen. De [pixelanalyse](png-pixel-contracts.md) volgt inmiddels alle 54 individuele scatterhelpers en hun packed-lookuptabellen.

## Ontbrekende bytes en de statusketen

`404a6e9c` vraagt zlib-output totdat de rij compleet is, een fout is gemarkeerd of het einde is bereikt. Blijven bytes ontbreken, dan zet hij `+7e=1` en vult hij uitsluitend het restant met nullen. Bijvoorbeeld drie aanwezige bytes van vijf worden `00 01 02 00 00`. Dit voorbeeld is een lokaal rekenmodel van de helper, geen native uitvoering.

`404a6118` kijkt vóór een nieuwe rij naar inflateractive, buffer, rijgrens en continuecallback. Hij test daar niet `+7e`. Na de fillhelper volgt filterverwerking en een bruikbare rijpointer, zonder nieuwe errorcheck. De warning-vtable `4048401c` bevat een continuecallback die altijd 1 retourneert (`404a13f4`) en een warningcallback die haar tweede argument teruggeeft (`404aa1a4`). Gewone foutmeldingen annuleren de rijloop dus niet via deze callbacks.

`404991cc` faalt bij een null-rijpointer of sinkfout, maar commit een niet-null rij en retourneert nul zodra alle gevraagde rijen doorlopen zijn. EndDecode `40497ad8` geeft de ontvangen decode-status door aan de sink, voert inflateEnd uit en test de parserfoutvlag eveneens niet. Daarmee is de niet-doorgegeven fout over deze concrete wrappers herleidbaar. Sinkvalidatie, andere decode-ingangen en runtimeweergave blijven afzonderlijke vragen.

De sinkroute wisselt bij truecolor RGB8 expliciet RGB naar BGR. Indexed formats kunnen packed bytes kopiëren; ARGB gebruikt een converter. De decode-formatkeuze kan 48-bit RGB en 64-bit RGBA tot ARGB32 omzetten, hoewel de eerdere ImageInfo-mapper die hogere formats kan adverteren. De [pixelanalyse](png-pixel-contracts.md) volgt inmiddels de vijf PNG-colorconverters en twee extended-routines, inclusief twee transparantieafwijkingen; algemene sinkconversie blijft open.

## Onafhankelijke referentiecontrole

`tools/parse_png_image.py` leest uitsluitend begrensde lokale kopieën: maximaal 32 MiB invoer/output en 4.194.304 pixels. Hij controleert chunkbounds en CRC, zlib-einde en exacte outputsize, palettes/transparantie, alle vijf filters en Adam7. APNG wordt expliciet geweigerd; color management en tekstmetadata worden niet geïnterpreteerd. 16-bit samples zijn wel als scanlijnen beschikbaar, maar vallen buiten zijn RGBA-converter.

De fixturecontrole vergelijkt **80** synthetische beelden met Pillow: vijf filters, beide interlacemodi en acht color/depth-combinaties, waaronder indexed 1/2/4/8. Vijf ongeldige inputs worden geweigerd. De producer vergelijkt daarnaast alle **377** echte PNG-assets volledig naar RGBA; hun bronhashes, chunktabellen en pixelhashes staan in de JSON. De assetset bevat 364 RGB8, twaalf RGBA8 en één indexed8, allemaal niet-interlaced. Exacte referentieovereenkomst bewijst de formaatinterpretatie, niet de pixeloutput van de ROM op het apparaat.

Open blijven onder meer alle malformed chunk arithmetic en korte reads, ongeldige color/depth-dispatch en totale interlaced-allocation arithmetic, textchunks en color management, de volledige zlib-provider en sink-/factoryfoutpropagatie. GIF/JPEG, overige firmwaremodules en een vergelijking met de geïnstalleerde unit blijven eveneens open.
