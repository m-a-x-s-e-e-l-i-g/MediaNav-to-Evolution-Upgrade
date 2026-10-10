# BMP-pixelroute en ingebouwde decoderinterfaces

De BMP-route is nu van factory tot header, palet, rijadres, conversie en cleanup gevolgd. Daarbij zijn echte firmwareassets onafhankelijk gedecodeerd. PNG/GIF/JPEG zijn aan hun concrete decoder-vtables en informatiepaden gekoppeld; hun volledige pixelalgoritmen zijn nog niet gereconstrueerd.

Bron: ROM `imaging.dll`, SHA-256 `f7592cc3360d97674a189c60b7d56e75a15ad2bceafe5eef6da47e8f20b70908`. Het [factory-/streamrapport](imaging-factory-contracts.md) beschrijft de eerdere object- en bronbufferkoppeling.

`py tools/inspect_imaging_bmp.py` bewaart [35 ranges, vier vtable-excerpts en alle 1.480 BMP-layouts](firmware/imaging-bmp-contracts.json). `py tools/parse_bmp_image.py --self-test` vergelijkt 17 RGB-fixtures met Pillow. De parser leest uitsluitend lokale kopieën, heeft byte-/pixellimieten en is strenger dan de firmware. Geen firmwaredecoder of GDI-call wordt uitgevoerd.

## Vier decoderobjecten

| Codec | Objectbytes | Constructor | Concrete vtable | Init / Decode / ImageInfo |
|---|---|---|---|---|
| BMP | `4f8` | `404a2028` | `40484d88` | `404a2400` / `404a3ac4` / `404a33fc` |
| PNG | `190` | `4049654c` | `40484038` | `40496ab0` / `404993f4` / `40498c10` |
| GIF | `cc0` | `40499734` | `404849dc` | `40499c38` / `4049ac3c` / `4049a634` |
| JPEG | `700` | `4049d1dc` | `40484bcc` | `404a0b84` / `4049e26c` / `404a1a14` |

De behouden excerpts omvatten elk de eerste 17 slots, niet de volledige vtables. Init bewaart de stream met AddRef; de uiteindelijke pixelverwerking gebeurt na BeginDecode met de door imaging aangeleverde sink.

## BMP-header en kleurenpalet

`404a3234` leest 14 bytes BITMAPFILEHEADER en daarna de DIB-header. De returnwaarde van de eerste read wordt niet getest; de volgende reads worden wel gecontroleerd. De readhelper `404a23a4` eist zowel een niet-negatieve status als exact het gevraagde aantal bytes.

De parser accepteert uitsluitend headergrootte **12** (CORE) of **40** (INFO). Andere groottes geven E_FAIL en objectmagic `FAIL`. CORE leest unsigned 16-bit width/height; INFO bewaart signed 32-bit width/height. Negatieve INFO-height wordt als top-down gemarkeerd.

De parser heeft hier geen aparte check op positieve breedte, niet-nul hoogte, planes=1 of bekende bitdiepte. ImageInfo kan de velden doorgeven voordat de latere pixelroute of GDI een fout ontdekt. Dat betekent niet dat iedere ongeldige combinatie succesvol rendert. De factory controleert vooraf wel de `BM`-signature via zijn decoderselectie.

Headergroottes, positieve/negatieve hoogte, planes en rijstride zijn beschreven in de officiële [BITMAPCOREHEADER](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapcoreheader) en [BITMAPINFOHEADER](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader). De referentieparser eist planes=1, geldige afmetingen en ondersteunde formaatcombinaties.

`404a2478` bepaalt het aantal kleurrecords:

- Bij BITFIELDS (compression=3), 16/32 bpp: drie DWORD-masks.
- Bij 1/4/8 bpp: maximaal respectievelijk 2/16/256 records; zero of te grote biClrUsed wordt vervangen door dat maximum.
- Overige gevallen: nul records.

De INFO-route leest vierbyte records rechtstreeks in het object vanaf `+58`. De CORE-route leest driebyte BGR-entries in een 768-byte lokale buffer en maakt er vierbyte records van. Er is dus een concrete paletgrens, geen onbeperkte biClrUsed-kopie. Alle 2.600 gemodelleerde combinaties blijven binnen maximaal 256 records.

`404a2500` maakt voor geïndexeerde beelden een aparte paletallocatie van `(count+3)*4`, converteert BGR naar ARGB met alpha ff en geeft die aan de sink. EndDecode `404a2918` geeft deze allocatie weer vrij.

## RGB-rijen en oriëntatie

`404a2608` kiest de pixel-formatcode: 1→`30101`, 4→`30402`, 8→`30803`, 16→`21005`, 24→`21808`, 32→`22009`, 64→`34400d`. Andere ongecomprimeerde bitdieptes geven nul. Niet-nul compression kiest `22009`, maar de latere rijdispatch bepaalt of verwerking werkelijk wordt ondersteund. De 64-bpp-case is behouden als native mapping; hij valt buiten de huidige referentieparser en assetset.

Bij compression 0 alloceert `404a3888` één rijbuffer met DWORD-aligned stride. `404a29dc` seeks voor iedere outputrij vanaf `bfOffBits`: top-down gebruikt `row*stride`; bottom-up `(height-1-row)*stride`. Assembly `404a2a18..404a2a94` bevestigt beide offsets en de oorspronkelijke 32-bit vermenigvuldigingen. Hij leest alleen de daadwerkelijke rijbytes, niet de padding.

De sink krijgt één rij via slots `+18` en `+1c`. Bij hetzelfde pixelformaat volgt memcpy; anders converteert `40494f0c` met het eventueel gemaakte palet. Het conversie-algoritme in die algemene routine is nog niet volledig gevolgd.

Voor gewone positieve afmetingen komt de stride overeen met `((width*bpp+31)//32)*4`. Er zijn 7.168 width/bitdepth-combinaties en 43.008 rijvolgordegevallen gecontroleerd. De native rowallocatie gebruikt het lage resultaat van een 32-bit multiply. Vier extreme, uitsluitend rekenkundige voorbeelden geven daardoor rijallocatie nul waar de mathematische stride 536.870.912 bytes is. Er is geen eigen overflowcheck in deze rowberekening; eventuele eerdere sink-/GDI-afwijzing en het concrete runtime-effect blijven open. Er zijn geen enorme buffers aangemaakt.

## BITFIELDS via GDI en de 8-MiB-stream

`404a3760` dispatcht compression 0 naar de RGB-rijreader en compression 3 naar `404a3614`. Andere compressiewaarden geven E_FAIL. RLE4/RLE8 kunnen daardoor de headerfase passeren maar hebben in deze pixelroute geen werkende rijhandler.

BITFIELDS maakt bij de eerste rij via `404a2b2c` een complete tijdelijke bitmap. De routine vraagt IStream::Stat op, vergelijkt size met bfOffBits en berekent de beschikbare bronbytes als **streamsize - bfOffBits**. Het memory-stream-Statpad `4048fac8` rapporteert precies de eerder aangeleverde buffersize.

Voor normale positieve 16/32-bit afmetingen gebruikt dit pad een bredere productberekening voor een benodigde bron-sizecheck. Dat bewijst geen volledige validatie van negatieve/extreme afmetingen of maskinhoud. Daarna alloceert het alle beschikbare bytes, seeks naar bfOffBits en leest die bytes. De routine maakt een 32-bpp-DIB, kopieert header en masks naar BITMAPINFO en laat **SetDIBitsToDevice** de conversie uitvoeren. Vervolgens levert `404a3614` per rij `width*4` bytes uit de tijdelijke DIB.

Omdat MgrUSB altijd 8 MiB als streamsize geeft, kan een kleine BITFIELDS-hoes bijna 8 MiB scratchruimte vragen. Een synthetische 2×2 RGB565-BMP is 74 bytes met bfOffBits=66 en acht echte pixelbytes; de native route berekent bij dezelfde reported streamsize een scratchallocatie van **8.388.542 bytes**. Daarnaast bestaan de oorspronkelijke 8-MiB-bronbuffer en de DIB. Dit is een gekoppelde allocatieberekening uit de code; er is geen native geheugenprofiel gemeten.

De bulkread loopt tot de gerapporteerde streamgrens, dus ook voorbij de echte APIC-payload wanneer die kleiner is. Welke ongebruikte bytes daadwerkelijk in GDI-verwerking belanden hangt van header, masks en dimensies af. De algemene geheugen-/bronbufferbevindingen staan in het [metadata-rapport](usb-metadata-contracts.md).

EndDecode verwijdert het tijdelijke HBITMAP, nulzet pointers en released de sink. Terminate `404a2840` released de stream en verwijdert een eventuele nog aanwezige bitmap. Niet alle foutpad- en teardown-interleavings zijn hiermee bewezen.

## Echte assets en onafhankelijke RGB-controle

Alle **1.480** gevonden BMPs in de 7.0.5.MD-extractie hebben header 40, compression 0 en positieve hoogte. Ze verdelen zich over 1.446 × 8 bpp, 33 × 16 bpp en 1 × 24 bpp. Hun bytehashes, dimensies, palet- en pixelbereiken staan in de JSON. De begrensde layoutparser accepteert alle bestanden.

Per gebruikte bitdiepte is één echte asset volledig met de eigen referentieroute én Pillow naar RGB gedecodeerd. De bytes komen exact overeen: `caution_bg_dark.bmp` (800×480, 8 bpp), `fmradio_bg.bmp` (800×480, 16 bpp) en `fmradio_control_prev_btn.bmp` (496×83, 24 bpp). Dit toetst de onafhankelijke formaatinterpretatie; het bewijst niet dat de ROM-decoder of het display exact dezelfde pixels produceert.

Daarnaast komen 17 synthetische RGB-fixtures overeen met Pillow: 1/4/8/16/24/32 bpp in beide oriëntaties, vier CORE-cases en één RGB565-BITFIELDS-case. Zeven ongeldige inputs worden geweigerd, waaronder CORE met 16/32 bpp. De referentieroute ondersteunt uitsluitend begrensde CORE/INFO-BMPs, RGB en geldige 16/32-bpp masks; geen RLE, nieuwere headers, native GDI of onbegrensde overflowpaden.

## PNG/GIF/JPEG-informatie: gekoppelde vervolgpaden

PNG ImageInfo `40498c10` maakt een eigen parserobject (`23c` bytes), gebruikt eventueel een extra streaminterface en haalt afmetingen uit big-endian IHDR-velden. Headerverwerking `404a6a18` markeert breedte of hoogte boven 65.535 en het product boven 67.108.864 pixels ongeldig. Negen grensgevallen zijn gemodelleerd; de volledige eerdere chunk-/headeracceptatie, waaronder nulafmetingen en alle color/depth-combinaties, blijft te volgen.

Mapper `404980a0` kiest afhankelijk van color type, bitdepth en transparantie. Voor truecolor 8/16 bpp kiest hij `21808`/`10300c`; RGBA 16 bpp krijgt `34400d`; geïndexeerd 1/4/8 bpp krijgt de overeenkomstige indexed formats, terwijl 2 bpp op `26200a` uitkomt. De tRNS-case in metadatahandler `404a5248` begrenst de count tot 256 en bewaart die op parseroffset `c8`. Bij een count groter dan nul wordt de outputformatcode `26200a`. Vijftig mappergevallen zijn opgeslagen; PNG-pixeldecodering blijft open.

GIF ImageInfo `4049a634` hangt van framecatalogus en compositingflags af. Het framecountpad `4049ae18` scant images, kan meerdere frames als één samengesteld image rapporteren en kiest bij die branches `26200a` in plaats van indexed `30803`. Volledige GIF-subblocks, LZW en frame-disposal volgen nog.

JPEG Init `404a0b84` koppelt een parserstate, een `102c`-byte sourceobject en APP1/APP13-callbacks. ImageInfo `404a1a14` volgt header- en metadatacalls, afmetingen, pixel-formatkeuze en DPI. De JPEG-markerparser, Huffman-/IDCT-/progressiveverwerking en APP-metadata worden hiermee nog niet als begrepen aangemerkt.

Open blijven: algemene pixelconversie en sinkvalidatie, alle extreme dimensies, BMP-GDI-internals, volledige PNG/GIF/JPEG-codecs en gelijktijdige cleanup. De BMP-keten en real-assetchecks maken de eerdere factoryanalyse concreter zonder volledige decoderdekking te claimen.
