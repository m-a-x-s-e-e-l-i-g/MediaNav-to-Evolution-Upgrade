# PNG-metadata, propertylijsten en bufferownership

De gevolgde ROM-code bevat drie afzonderlijke metadata-afwijkingen: een afsluitende nulbyte buiten de aangevraagde buffer bij precies passende gecomprimeerde tekst, een verkeerde foutcode voor buffergroei, en gedeeltelijke propertylijsten die bij allocatiefouten niet worden teruggedraaid of opgeruimd. Dit zijn statisch bevestigde branches met begrensde lokale modellen; de firmware en fysieke unit zijn niet uitgevoerd.

Bronnen: ROM `imaging.dll`, SHA-256 `f7592cc3360d97674a189c60b7d56e75a15ad2bceafe5eef6da47e8f20b70908`; ROM `zlib.dll`, SHA-256 `1b3ef3cb314b72f188fadfb19cffe961b028d20d3fefc5350a3221e9879d43e8`. `py tools/inspect_png_metadata.py` bewaart [32 originele bytebereiken en resultaten](firmware/png-metadata-contracts.json), leest alle 377 echte PNG-assets opnieuw en toetst tien referentie-fixtures. Zeven metadatawaarden komen onafhankelijk overeen met Pillow; achttien ongeldige of te grote referentiecases worden afgewezen.

De eerdere rapporten volgen [chunk-/scanlijnverwerking](imaging-png-contracts.md) en [pixels/Adam7/transparantie](png-pixel-contracts.md). `tools/parse_png_metadata.py` is een afzonderlijke offline metadatareader: maximaal 32 MiB bron, 1 MiB per tekst/profile en 8 MiB totale tekst/profile. Hij controleert CRC, velden en begrensde decompressie, maar is geen volledige PNG-conformancevalidator. IDAT, ICC-internals, XMP-semantiek en kleurbeheer vallen buiten deze reader.

## Wat werkelijk in het pakket voorkomt

| Metadata | Aantal chunks | Waarde/gedrag |
| --- | ---: | --- |
| iTXt | 372 | Keyword `XML:com.adobe.xmp`; native chunkhandler heeft geen iTXt-branch |
| tEXt | 8 | `Software` = `Adobe ImageReady`; native tekstveld +1fc/+200 |
| pHYs | 364 | 3780×3780 pixels/meter → 96,012 DPI |
| pHYs | 5 | 2835×2835 pixels/meter → 72,009 DPI |
| cHRM | 369 | `[31269,32899,63999,33001,30000,60000,15000,5999]` |
| gAMA | 5 | 45454 |

In deze 377 assets komen geen zTXt, iCCP, tIME, hIST, sBIT of sRGB voor. De bevindingen over die routes zijn gebaseerd op originele code en synthetische inputs. XMP wordt door onze reader als UTF-8-tekst opgeslagen; XML wordt niet uitgevoerd of semantisch geïnterpreteerd. De native handler `404a5248` accepteert onbekende ancillary chunks via zijn default-return, maar maakt voor iTXt geen properties aan.

## Tekstclassificatie en propertymapping

Parser-vtable `40485034` heeft twee pointers: destructor `404a4c60` en chunkhandler `404a5248`. Tekstclassifier `404a4f28` kopieert het keyword naar 80 stackbytes. Zijn grenscheck accepteert maximaal **78** bytes. Er wordt geen nulterminator aan die stackkopie toegevoegd. De classificatie gebruikt vaste `memcmp`-lengtes en controleert niet of het volledige keyword dezelfde lengte heeft.

`TitleSuffix` wordt daarom als Title behandeld. `CreationTime` zonder spatie wordt herkend; `Creation Time` wordt niet herkend. Bij een keyword dat een kort prefix van een vergeleken literal vormt, hangt de uitkomst mede af van ongeïnitialiseerde stackbytes. Het model markeert dit als onbepaald, niet als gegarandeerd genegeerd.

| Native keyword | Parser pointer/count | Property ID | Native type |
| --- | --- | --- | --- |
| Title | 1d4 / 1d8 | 0320 | ASCII, 2 |
| Author | 1dc / 1e0 | 013b | ASCII, 2 |
| Copyright | 1e4 / 1e8 | 8298 | ASCII, 2 |
| Description | 1ec / 1f0 | 010e | ASCII, 2 |
| CreationTime | 1f4 / 1f8 | 9003 | ASCII, 2 |
| Software | 1fc / 200 | 0131 | ASCII, 2 |
| Source | 204 / 208 | 0110 | ASCII, 2 |
| Comment, Disclaimer, Warning | 20c / 210 | 9286 | ASCII, 2 |

Deze IDs zijn aan de originele propertybuilder gekoppeld. Volgens [Microsofts property-ID-tabel](https://learn.microsoft.com/en-us/windows/win32/gdiplus/-gdiplus-constant-property-tags-in-numerical-order) betekent 0110 EquipModel; de firmware exporteert zijn Source-tekst dus onder de model-tag. De drie commentkeywords delen één buffer en worden bij succesvolle herhaling met een spatie samengevoegd.

De [PNG-specificatie](https://www.w3.org/TR/png-3/#11text) laat keywords van 1–79 bytes en lege tekst toe; zTXt gebruikt compression-method 0 en iTXt UTF-8. De native plain-textbranch negeert lege tekst. De zTXt-branch slaat de compression-methodbyte over zonder hem te controleren. De outer chunkhandler negeert de status van de teksthelper en retourneert zelf 1.

## Gecomprimeerde tekst: ruimte en foutcodes

Storagehelper `404a4cac` reserveert bij de eerste plain tekst `L+1` bytes en schrijft de terminator op offset L. Voor de eerste gecomprimeerde tekst reserveert hij **4×C** bytes, waarbij C de compressed streamlengte is. Er is geen extra byte voor de terminator. De eerste vermenigvuldiging heeft een wide overflowcheck; de compressed-appendbranch gebruikt uitsluitend een 32-bit shift.

Een geldige zTXt-fixture bevat 48 ASCII A's, gecomprimeerd tot twaalf bytes. De aangevraagde native buffer is 48 bytes, de outputlengte ook 48. Bij succes schrijft instructie `404a4f14` de nulbyte op offset **48**: één byte buiten de aangevraagde grootte. Het model registreert deze write, maar voert hem niet uit. Heapafronding, bereikbaarheid vanuit een concrete applicatie en schade op de unit zijn niet vastgesteld.

De growth-loop vergroot alleen bij return **−4**. ROM-provider `40145ae8` roept `inflate(...,4)` aan; stream-end wordt succes, anders wordt een nulstatus naar **−5** omgezet en worden overige errors doorgegeven. Bij onvoldoende outputruimte retourneert de gevolgde FINISH-route −5. `destLen` wordt alleen bij succes bijgewerkt. Een gewone te kleine buffer activeert daardoor niet de growth-loop.

De lokale fixture met 4096 A's past niet in 4×zijn compressed lengte. De begrensde hostdecompressor valideert de stream; het native branchmodel projecteert vervolgens status −5. Dit is geen uitvoering of complete emulatie van ROM-inflate.

Append overschrijft eerst de oude nulbyte met een spatie (`404a4e10`). Daarna pas volgen tijdelijke allocatie, decompressie en reallocatie. Bij een nonzero decompressiefout anders dan −4 retourneert de helper 0 zonder de tijdelijke buffer vrij te geven. De oude count blijft gelijk, terwijl de oude buffer nu op een spatie eindigt. Bij reallocatiefailure blijft een reeds gevulde tijdelijke buffer eveneens zonder cleanup. De parserdestructor bezit deze verloren tijdelijke pointer niet; latere private-heap/process-cleanup is niet hiermee onderzocht.

## ICC, kleurdata en resolutie

iCCP slaat profielnaam op in +21c/+220 en profielbytes in +214/+218. Het gebruikt dezelfde 4×C-capaciteit en −4-growthtest. Bij −5 worden profielbuffer en count gewist en retourneert de chunkhandler alsnog 1: het profiel wordt stil overgeslagen. Er is hier geen interne ICC-validatie. De test gebruikt alleen een syntactisch correct compressed profile-envelope, geen gevalideerd ICC-profiel.

Bij een tweede iCCP vervangt de code eerst de naam en stopt daarna wanneer een oud profiel al aanwezig is. Zo kan een nieuwe naam bij oude profielbytes blijven staan. Bij een naam zonder separator wordt na het uitputten van de payload toch `naamlen+1` gekopieerd: één byte voorbij de chunkpayload, normaal de eerste CRC-byte. Dat is een chunkgrensafwijking; een heapgrensoverschrijding wordt voor die case niet geclaimd.

cHRM van exact 32 bytes zet flag +1d3 en acht BE-waarden zolang sRGB-intent nog ff is. gAMA van vier bytes vult +bc onder dezelfde voorwaarde. sRGB van één byte en het private srGB-format van 22 bytes zetten intent en standaardwaarden, waaronder gamma 45455. Deze branches zetten **niet** de cHRM-exportflag +1d3. De propertybuilder exporteert white point/primaries daarom alleen wanneer die flag eerder gezet is en de benodigde waarden positief zijn.

Gamma wordt geëxporteerd als RATIONAL `(100000, gAMA)`. Dat sluit aan op [Microsofts propertybeschrijving](https://learn.microsoft.com/en-us/windows/win32/gdiplus/-gdiplus-constant-property-item-descriptions#propertytaggamma); de omkering is op zichzelf geen fout. De profielnaam wordt ASCII property 0302, profielbytes BYTE 8773, intent BYTE 0303; white point 013e en primaries 013f zijn RATIONALs.

pHYs moet native negen bytes zijn, maar unit wordt niet tot 0/1 begrensd. `40498c10` berekent voor unit 1 `x/y × 254.0 / 10000.0`, met flags 53000. Andere units gebruiken display-GetDeviceCaps 88/90, met 96.0-fallback en flags 52000. De propertybuilder exporteert unit 5110, x 5111 en y 5112 alleen wanneer beide dimensiewaarden nonzero zijn. Dit zegt niets over automatische UI-schaling.

sBIT kopieert hoogstens vier bytes zonder kanaal-/bitrangevalidatie. sPLT en private sPAL bewaren uitsluitend de naam in +22c/+230; entries/sampledepth worden hier niet verwerkt. De builder exporteert beide niet. Private msOC met lengte acht en prefix `MSO aac` schrijft de laatste byte naar +1d2; verdere consumers blijven open.

## Tijd, histogram en cleanup

tIME heeft native geen lengte- of veldrangecheck. Assembly `404a572c..404a574c` leest met unaligned DWORD-loads **acht** bytes; de formatter gebruikt alleen de eerste zeven. Een reguliere zeven-byte payload leest daardoor één CRC-byte mee die verder niet wordt gebruikt. Korte payloads laten formattervelden uit volgende bytes komen; volledige malformed-framing en terminal-buffergrenzen blijven open.

De code vraagt twintig bytes aan en bouwt `YYYY:MM:DD HH:MM:SS\0`. Het eerste jaarteken is `(year//1000)+48`, zonder beperking tot vier decimalen. Jaar 10000 wordt `:000`; 65535 wordt `q535`; een veldbyte 255 wordt `I5`. Alle 65.536 jaren en 256 mogelijke veldbytes zijn in het lokale formattermodel getoetst. De [tIME-specificatie](https://www.w3.org/TR/png-3/#11tIME) definieert zeven bytes, maand/dag/tijdgrenzen en seconde 60 als schrikkelseconde. Onze reader controleert die veldranges, maar geen volledige kalendergeldigheid.

hIST zet +238 al op palette-count vóór de lengtecheck, vraagt daarna 2×count bytes aan en bewaart de pointer in +234. Een herhaalde geldige hIST overschrijft de vorige pointer zonder free. De destructor kan alleen de laatste allocatie vrijgeven. Property 5113 gebruikt SHORTs en 2×count bytes.

Parserdestructor `404a4b28` volgt dertien pointer/countparen: acht tekstvelden plus profiel, profielnaam, tijd, sPLT-naam en histogram. Hij frees ieder veld wanneer zijn count nonzero is. Base cleanup `404a64ec` beëindigt inflate, ruimt rij-/bronbuffers op en released een eventueel nog behouden stream. `40497fac` verzorgt decoder-, stream- en sinkbuffercleanup en roept vervolgens propertycleanup aan.

## Propertylayout en gedeeltelijke opbouw

Interne listhelper `404904d0` vraagt een **24-byte node** plus een afzonderlijke payloadkopie aan. Nodevelden zijn next +0, previous +4, ID +8, length +c, type WORD +10 en payloadpointer +14. De parsermetadata blijft bestaan naast deze kopieën. Publiek PropertyItem is **16 bytes**: ID +0, length +4, type WORD +8, pointer +c; de waarden worden achter de structs gekopieerd.

Lazy builder `40496bd4` verhoogt count +7c en payloadsum +78 **vóór** iedere helperallocatie. Bij helperfailure gaat hij naar `40496c0c`, dat return 0 geeft. De flag +44 blijft nul; reeds gemaakte nodes en verhoogde counts worden niet teruggedraaid. Een volgende call begint dezelfde build opnieuw. Een failure van voorafgaand ImageInfo kan wel een negatieve status retourneren; niet alle failures worden gemaskeerd.

Het lokale faultmodel gebruikt twee properties van zes en achttien bytes en laat steeds de tweede insert mislukken. Na twee calls zijn count/sum 4/48, terwijl slechts twee nodes met twaalf payloadbytes bestaan. `40497938` betreedt cleanup alleen als +44 gelijk is aan 1; in deze trace blijft die flag nul. De twee nodes en kopieën, 60 aangevraagde bytes, worden daardoor niet door deze cleanupfunctie vrijgegeven. Dit is een logische failuretrace, geen native heapfaultinjectie.

| Interface-routine | VA | Gevolgd contract |
| --- | --- | --- |
| Count / IDs | 4049729c / 40497300 | Count en exact count voor ID-list |
| ItemSize / Item | 404973c8 / 40497480 | 16+payloadsize, exacte caller-size en ID |
| AllSizes / AllItems | 40497594 / 40497620 | 16×count+payloadsum; AllItems test size/count vóór lazy init |
| Remove / Set | 40497730 / 404977f8 | Remove unlink/free/counterupdates; Set kan counters vóór allocatie wijzigen |
| Sinkproperties | 40497eb0 | Doorvoer via sink-vtable-slots 2c/34/38 |
| Cleanup | 40497938 | Alleen bij initialized-flag 1 |

Volledige SetProperty-faultsemantiek, afwijkende count/list-traversal, downstream kleurbeheer en concurrency zijn nog niet afgedekt. Er is geen devicecrash, misbruikbaarheid, CVE-identiteit of werkende firmwarepatch bewezen.
