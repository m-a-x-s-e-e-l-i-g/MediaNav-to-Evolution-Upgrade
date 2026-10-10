# USB-metadata, albumhoezen en DirectShow-afhandeling

Nieuwste implementatie: [WMA/ASF](wma-shuffle-development.md) is begrensd op header/child/field, vereist exacte reads/seekreturns en kopieert geen lange descriptornaam. 241 parsercases plus vier exceptionmapchecks; bestaande30-unitlimit/frame/context behouden. Development-02 bevat gecorrigeerde C++IP-map. Native decoder/unwind blijft open.

Nieuwste implementatie: [APIC/PIC-bounds en hoesverwerking](artwork-playlist-development.md) in complete ontwikkeling: beschrijvingterminators per encoding, capaciteit en echte decoderlengte, correcte rijpadding en directe pixelstores; 3.652-byte metadata-copy vervalt. 157 cover-, 137 bitmap- en drie rendercases. Onderstaande oorspronkelijke analyse blijft historisch; WMA/ASF en native codec/display/timing blijven open.

Nieuwste vervolg: [encoding/BOM en cachelengte](usb-reliability-development.md) geïmplementeerd in volledige ontwikkeling: gedeclareerde ID3v2-encoding, begrensde decode, provenance per rawslot en correcte V1-/genrefallback bij taalwissels. 197 nieuwe encoding/cache/parsercases; artwork/ASF en native codepages/fonts blijven open. Onderstaande oorspronkelijke analyse en eerdere ontwikkelstatus blijven als historisch bewijs behouden.

Ontwikkelvervolg: [hele-unit statuskopieën en ID3-framelengte/-grensreparaties](usb-input-safety-development.md) zijn geïmplementeerd in volledige cumulative staging. Encodingconverter/BOM, artwork, ASF en native verificatie blijven open. Onderstaande analyse beschrijft de oorspronkelijke code.

Deze analyse volgt de oorspronkelijke `MgrUSB.exe` uit 7.0.5.MD en verbindt de albumhoesroute met ROM-module `imaging.dll`. Er zijn concrete parser- en tekstkopieerfouten, een breedteafhankelijke fout in de bitmapbewerking en beperkte foutafhandeling in de afspeelmanager. Dit is statisch bewijs van codepaden; effecten op een draaiende unit en exploitbaarheid zijn niet getest.

Bronnen en reproduceerbaarheid:

- MgrUSB SHA-256: `bb435bc428664845a21ffe7bce7a813db06b7e7f92408d297dbbeade94507cd2`.
- Imaging SHA-256: `f7592cc3360d97674a189c60b7d56e75a15ad2bceafe5eef6da47e8f20b70908`.
- [Ruwe ranges, tabellen, GUIDs en begrensde modellen](firmware/usb-metadata-contracts.json): 40 ranges, inclusief .pdata-functies en expliciet begrensde leaf/data-ranges.
- `py tools/inspect_usb_metadata.py` regenereert de evidence en controles.
- `py tools/parse_usb_tags.py --self-test` test de afzonderlijke offline referentieparser; `py tools/parse_usb_tags.py <lokaal-bestand>` leest uitsluitend een lokale kopie.
- De referentieparser ondersteunt de gewone ID3/ASF-kernstructuren. Compressie, grouping, per-frame unsynchronisation, CRC en footervalidatie zijn niet geïmplementeerd; tekst uit geflagde frames wordt niet gedecodeerd. Het is geen volledige conformiteitsvalidator of emulatie van de native parser.

Dit rapport vervolgt [catalogus/repeat/shuffle/COM-creatie](usb-playlist-contracts.md), [playlistinvoer/resume](usb-media-input-contracts.md) en [GUI/USB-interactie](appmain-interaction-contracts.md).

## Metadata-object en levensduur

`17468` initialiseert `0xe44` bytes en bewaart een afzonderlijke 8-MiB-imageallocatie op objectoffset `e44`. Hieronder staan offsets ten opzichte van het CID3Tag-object. CPlayControl bevat dit object vanaf `+4`.

| Offset | Veld |
|---|---|
| `000`, `208`, `410`, `618` | artiest, album, titel, genre: vier UTF-16-buffers van 260 units |
| `820`, `924`, `a28`, `b2c` | vier oorspronkelijke bytebuffers voor dezelfde tekstvelden |
| `c30`, `c34` | hoesformaat en aantal hoesbytes |
| `c38` | gecachet pad, UTF-16[260] |
| `e40`, `e44` | flags en pointer naar de imagebuffer |

Flags `1/2/4/8/10` betekenen titel/album/artiest/hoes/genre. Bit `80` wordt ook op een normaal eindpad gezet en mag niet als een exclusieve foutindicator worden geïnterpreteerd.

`19254` vergelijkt het pad tot 260 units. Bij hetzelfde MP3-pad kan hij de bewaarde tekstbytes opnieuw converteren; bij een nieuw pad wist hij de velden, kiest MP3-parser `18f84` of WMA-parser `182dc` en cachet het pad. Zijn returnwaarde is steeds nul; de resultaten staan in het object. Dit maakt resultaatflags en ingevulde velden belangrijker dan de returnwaarde.

De leaf-destructor `174f8` bestaat uitsluitend uit `jr ra; nop`. De gevolgde CPlayControl-destructor `19508` verwijdert wel de HBITMAP. Het [vervolgonderzoek naar imaging en ownership](imaging-factory-contracts.md) koppelt de 8-MiB-buffer inmiddels aan MgrUSB's globale allocatielijst: allocator `12844`, poolcleanup `129c8` en WinMain-exit `24a90`. De lege tag-destructor bewijst daarmee geen permanent lek.

## Tekstkopieën naar afspeelstatus

`19d3c` maakt de statusbuffers voor titel (`+1ce6`), artiest (`+1eee`) en album (`+20f6`) leeg en kopieert vervolgens telkens **129 bytes**, niet 129 UTF-16-units. De resumevariant `1a0d4` doet hetzelfde. Het normale bestandstitel-fallbackpad gebruikt **259 bytes**.

Assembly `19f98..19fa4` zet `a2=0x81` vóór `memcpy`; `19f48..19f54` zet `a2=0x103`. Het betreft dus geen onzekerheid in de typering van de decompiler.

Bij 129 bytes blijven 64 volledige units over, plus alleen de lage byte van de 65e unit. De hoge byte blijft nul door de voorafgaande bufferinitialisatie. Voorbeeld: 64 maal `x` gevolgd door `日` (`U+65E5`) wordt 64 maal `x` gevolgd door `å` (`U+00E5`). Een teken waarvan de lage byte nul is kan de tekst daar afbreken; een surrogate-paar kan ongeldig eindigen. De 259-byte-kopie heeft dezelfde fout op unit 129.

De acht offline kopieergevallen omvatten ASCII, `U+65E5`, `U+0100` en een surrogate-paar bij beide grenzen. Ze reproduceren de bytekopie, niet de latere rendering op het apparaat. Zonder metadata gebruikt de code `No Album` en `No Artist`; de titel wordt uit het pad/bestand gehaald.

## MP3/ID3-parser

`18f84` opent het bestand voor lezen, leest de tienbyteheader en vraagt `177c0` om de taglengte. Die helper controleert `ID3`, geen `ff` als major/revision en zevenbit-sizebytes. Hij berekent de synchsafe taglengte plus header en eventueel footer. De latere parser accepteert major 2, 3 en 4.

De loader gebruikt de lage DWORD van de bestandsgrootte. Verschillende ReadFile-calls controleren BOOL, zonder de werkelijk gelezen lengte te eisen. Bij `filesize <= totaleTaglengte` slaat hij ID3v2 over; een bestand dat uitsluitend uit die tag bestaat bereikt dit parsepad daardoor niet. Hij probeert vervolgens ook de laatste 128 bytes als ID3v1 te lezen, met daar wel een exacte readcountcheck.

`17500` vult ontbrekende/lege v2-tekst aan uit de 30-byte ID3v1-velden. De genrebyte wordt boven 148 naar 148 begrensd en via tabel `2f1ec` vertaald. De concrete genrestrings zijn in deze pass niet afzonderlijk geëxporteerd.

De twee native frame-dispatchtabellen zijn volledig bewaard:

| Versie | Herkende IDs | Werkelijke opslag |
|---|---|---|
| 2.2 | TT2, TP1, TAL, TRK, TYE, TCO, COM, PIC | titel, artiest, album, genre, hoes |
| 2.3/2.4 | TIT2, TPE1, TPE2, TPE3, TOPE, TALB, TRCK, TYER, TCON, COMM, APIC | titel, artiest, album, genre, hoes |

Tracknummer, jaar en commentaar hebben wel dispatchrecords maar geen opslagcase in de gevolgde switch. Bij meerdere artiestframes wint de eerste niet-lege artiest; titel en album kunnen later overschreven worden.

`178bc` bevat meerdere aantoonbare afwijkingen:

1. **ID3v2.4-framegrootte:** hij leest de vier sizebytes als gewone big-endian integer, net als bij 2.3. Een correcte v2.4-grootte 128 (`00 00 01 00`) wordt 256. De [ID3v2.4-structuurspecificatie](https://id3.org/id3v2.4.0-structure) schrijft synchsafe framegroottes voor. Alle 4.097 groottes 0..4.096 zijn gemodelleerd: alleen 0..127 komen overeen.
2. **Extended header:** de parser leest bij 2.4 wel een synchsafe headergrootte, maar schuift vervolgens `size+4` bytes op. De v2.4-size omvat die vier bytes al; de native code slaat dus vier bytes extra over. De v2.3-telling heeft een andere definitie. [ID3v2.4, extended header](https://id3.org/id3v2.4.0-structure).
3. **Framegrens:** de sizecheck vergelijkt N met de resterende bytes R vóór aftrek van de 6- of 10-byte frameheader. Hij accepteert dus ook `R-H < N <= R`, waarna de unsigned restlengte kan onderlopen. De begrensde matrix bevat 7.296 gevallen en 904 van zulke foutieve acceptaties.
4. **Laatste frame:** de dispatchhandler wordt alleen bezocht als de resterende lengte ná header en payload niet nul is. Een frame dat exact op het einde van de tag eindigt wordt overgeslagen. Padding achter het frame verandert dit gedrag; 112 exacte eindgrenzen zijn gemodelleerd.
5. **Tekstencoding:** de handlers slaan het encodingbyte over maar gebruiken de waarde ervan niet om de converter te kiezen. Daardoor volgt de interpretatie inhoud/language-index, in plaats van betrouwbaar het opgegeven encodingtype.
6. **Compressie:** `17e88..17eac` alloceert de opgegeven gedecomprimeerde lengte en vervangt de payloadpointer. Tussen allocatie en dispatch staat geen decompressie of vullende kopie. De handler kan zo ongevulde allocatiebytes interpreteren. Het exacte allocatiegedrag en effect zijn nog niet runtimegetest.

Voor v2/v3 wordt tag-unsynchronisation (`ff 00` → `ff`) gevolgd. Bij v4 is er een aparte per-frameflag; grouping/compression/data-length veranderen eveneens de pointer- en sizeberekening. Het veilige model projecteert de grensfouten uitsluitend voor **ongeflagde** frames en probeert geen onbegrensde onderloop of native overread uit te voeren.

## Converter en codepages

`24e04` behandelt een eerste payloadbyte `ff` **of** `ef` als speciaal UTF-16-achtig pad, zonder de volledige BOM te controleren. Hij slaat twee bytes over. Daardoor krijgt ook een UTF-8-BOM (`ef bb bf`) die branch, terwijl UTF-16BE (`fe ff`) hem niet krijgt.

Voor lengtes tot 200 kopieert hij vanaf `payload+2` nog steeds de oorspronkelijke lengte N: dat leest twee bytes voorbij het opgegeven bytebereik. De uiteindelijke WCHAR-count is `(N-2)/2`. De voorafgaande native buffer kan extra bytes bevatten; deze analyse noemt het een bereikafwijking en veronderstelt niet automatisch dat de onderliggende allocatie daar eindigt.

Zonder deze branch probeert hij doorgaans UTF-8 (`65001`, flags 8), daarna een language-afhankelijke codepage. Voor LANG_INDEX 2 en 28 bestaat een CP949/DBCS-voorrangspad. De fallbacks van `24cf8` zijn:

| LANG_INDEX | Codepage |
|---|---|
| 0, 31 | 1256 |
| 7, 20, 22, 23 | 1251 |
| 9, 11, 15, 16, 17, 18, 19 | 1250 |
| 10 / 13 / 14 / 21 | 1254 / 932 / 1253 / 1255 |
| overige | 1252 |

`24ca4` leest `HKLM\LGE\SystemInfo\LANG_INDEX`, default nul. Terminatorindex en conversiecapaciteit zijn mede op de oorspronkelijke bytecount gebaseerd. De exacte Windows CE-conversieregels en alle callers buiten metadata blijven open.

## APIC/PIC en albumhoesbytes

Het native hoespad zoekt vanaf payload+1 een NUL-beëindigde MIME-string met `strlen`, zonder een framebegrensde terminatorzoekactie. Hij vereist prefix `image`, en herkent subtype `jpg/jpeg/png/bmp/gif` met formaatcodes `10/12/17/15/16`.

De kopie begint op `MIMEstart + strlen(MIME) + 3` en telt `N - strlen(MIME) - 3` bytes. Dat veronderstelt een picture-typebyte en een lege beschrijving met één NUL-byte. Een niet-lege beschrijving wordt zo onderdeel van de beeldbytes; encoding en beschrijvingslengte worden niet afzonderlijk verwerkt. ID3v2.2-PIC met een normale driebyte-formaataanduiding gaat eveneens door deze MIME-georiënteerde handler.

De imagebuffer is 8 MiB, maar deze kopie heeft geen zichtbare clamp naar 8 MiB. MIME-size/offset kunnen bovendien onderlopen bij ongeldige invoer. Dit zijn statisch gevonden controlehiaten; er zijn geen native payloads uitgevoerd.

## WMA/ASF

`182dc` gebruikt drie GUIDs op `2884c/2885c/2886c`: Header `75b22630-668e-11cf-a6d9-00aa0062ce6c`, Extended Content Description `d2d0a440-e307-11d2-97f0-00a0c95ea850` en Content Description `75b22633-668e-11cf-a6d9-00aa0062ce6c`.

Hij accepteert 1..16 child objects. Objectgroottes moeten een nul high-DWORD hebben, minstens 25 zijn en kleiner dan de hele bestandsgrootte. Deze vergelijking bewijst geen containment binnen het huidige object of de resterende header. ReadFile-BOOL wordt veelvuldig gebruikt zonder exacte bytecountcheck.

Content Description levert titel/artiest; Extended Content Description zoekt case-insensitive `WM/ALBUMTITLE`, type 0. De uiteindelijke veldkopie is maximaal **60 bytes**, dus 30 UTF-16-units, met een terminator op unit 30. De doorleeslimiet voor die velden kan groter zijn dan de kopie.

Voor descriptornaam N leest de parser maximaal 100 bytes en seek-skipt de rest, maar vervolgens kopieert hij de **oorspronkelijke N** naar een 256-byte lokale naamarray. Assembly `18880..18924` bevestigt de onafhankelijke readlimiet en ongeclampte `memcpy`-lengte. Bij N>256 overschrijdt de kopie de bestemmingsarray; zonder aangetoonde terminator is ook de daaropvolgende stringvergelijking onvoldoende begrensd. Een veilig, synthetisch ASF-geval met een naam van 262 bytes wordt door de referentieparser gelezen en uitsluitend als native-overrunrisico gemarkeerd.

## Albumhoes → imaging.dll → HBITMAP

`1a318` maakt de factory met CLSID `327abda8-072b-11d3-9d7b-0000f81ef32e` en IID `327abda7-072b-11d3-9d7b-0000f81ef32e`. De ROM-registry koppelt deze klasse aan `imaging.dll`; ROM-QI `40486d98` en twee ROM-IID-records bevestigen dezelfde interface-identiteit.

De factorycall op vtableslot `+14` krijgt de imagebufferpointer, **altijd 8 MiB** als size, disposalflag 0 en een output-IImage. De native code controleert vooraf wel of het opgeslagen aantal hoesbytes niet nul is, maar geeft dat werkelijke aantal niet als de size door. De image-info- en Draw-calls zitten op `+10` en `+18`; hun HRESULTs worden hier niet als noodzakelijke succesvoorwaarden gebruikt.

De bitmap is 24-bpp, met breedte/hoogte uit `ALBUMART_WIDTH/HEIGHT`, default 278. Na het tekenen zet de code pixels met B=8..15, G<4, R<8 zwart. Bij elke pixel schuift hij drie bytes, bij iedere rij **altijd twee extra bytes** (`1a51c..1a53c`).

De normale 24-bpp-DIB-stride is `(3*width+3)&~3`. De native loop gebruikt `3*width+2`. Dat klopt alleen als `width % 4 == 2`, waaronder default 278. Voor de overige breedtes verschuiven rijgrenzen; sommige combinaties kunnen voorbij de bitmapallocatie lezen/schrijven. De modellen controleren alle breedtes 1..800 en vier hoogtes zonder pixelbuffers aan te spreken. Slechts 200 breedtes hebben de juiste stride.

De vorige HBITMAP wordt verwijderd en de nieuwe wordt in CPlayControl `+2926` opgeslagen. Shared memory en AppMain-commando `67` worden bijgewerkt. De [factory- en streamanalyse](imaging-factory-contracts.md) volgt inmiddels bronbufferownership, IImage-lifetime en de vier ingebouwde decoders. Hun pixelinternals en exacte bronbufferconsumptie blijven open.

## Einde-track, fouten en vrijgave

WndProc `245f0` stuurt message `8001` door naar `11ab0`. Die routine haalt events met timeout nul op en roept voor ieder succesvol verkregen event `FreeEventParams` aan. De extra argumenten die Ghidra bij sommige indirecte calls toont, zijn hier niet zelfstandig interfacebewijs; de assembly-callsite bepaalt de echte argumenten.

`EC_COMPLETE` (code 1) wordt alleen actief verwerkt als graphflag `+28` gezet is, eventparam2 nul is en de unsigned tijd sinds `+2c` minstens 300 ms bedraagt. Param1 wordt gelogd; hij kiest hier geen branch op een daarin opgeslagen HRESULT. De [officiële EC_COMPLETE-beschrijving](https://learn.microsoft.com/en-us/windows/win32/directshow/ec-complete) beschrijft param1 als HRESULT en param2 als ongebruikt.

Op het normale pad werkt hij de positie bij, slaapt 100 ms, leest opnieuw, zet zo nodig de positie op de duur en stuurt **5→5 command `6c`** voor automatische trackafhandeling. Tijdens resume kiest hij seek naar nul. De modelmatrix bevat 384 gevallen inclusief de 299/300-ms-grens; een afzonderlijke controle bevestigt de unsigned tick-wrap.

`EC_USERABORT`, `EC_ERRORABORT`, `EC_STREAM_ERROR_STOPPED`, `EC_STREAM_ERROR_STILLPLAYING`, video-events en onbekende events worden in deze handler alleen gelogd. Hij heeft voor die codes geen eigen stop/reload/herstelbranch. Dat zegt niet dat geen enkel filter of andere manager ooit herstelt; daarvoor moeten de overige paden worden gevolgd.

`11e7c` stopt eerst en released vervolgens BasicAudio, Seeking, Event, Control, Position en Graph, met nulzetten van de pointers en wissen van de graphflag. De gevolgde routine bevat geen SetNotifyWindow(NULL). Een latere message wordt bij een nul Event-pointer genegeerd; concurrentie tijdens teardown is nog niet opgelost in de analyse.

Graphcreatie `11f78` doet RenderFile en haalt vijf interfaces op. Niet ieder QI-/notify-foutpad ruimt meteen op; de volgende render of USB-verwijdering kan de gedeeltelijke graph vrijgeven. De graphflag wordt al tijdens creatie gezet, vóór bewezen succesvolle RenderFile. Dit bewijst tijdelijke gedeeltelijke objectstaat, geen onbeperkte lekduur.

## Run, Stop en twee Pause-varianten

`114a0` geeft BasicAudio volume 0, roept Run aan en cachet running als state 2 bij succes.

Stop `11568`, RealPause `11790` en Pause `11918` dempen naar -10000 en pollen `IMediaControl::GetState` met **INFINITE**. De HRESULT van GetState wordt in de gevolgde loops niet gebruikt. De 5-ms-sleeps en maximaal 1.001 iteraties geven daarom geen vaste vijfseconden-timeout: iedere GetState-call kan zelf blokkeren.

| Routine | Als running (2) | Als paused (1) | Als stopped (0) | Iteratielimiet |
|---|---|---|---|---|
| Stop | Pause | Stop | klaar | kan toch succes en cached state 3 teruggeven |
| RealPause | Pause | klaar | klaar | failure zonder observed target |
| Pause | Pause | Stop | klaar | failure zonder observed target |

De gewone Pause-variant wacht dus feitelijk op stopped; RealPause accepteert paused. Vijftien traces toetsen deze verschillen voor geldige stateoutputs. HRESULT-fouten, null-pointerbranches en schedulerverloop worden niet door die pure modellen gesimuleerd.

De RenderFile-caller `12264` accepteert zijn pathguard als **bestand bestaat OF padlengte <261**. Dat laat een kort ontbrekend pad toch een laadpoging doen en laat een bestaand lang pad langs deze ene guard. Het exists-helperpad `24b90` inspecteert bovendien `path[length-1]` zonder eigen lege-stringcheck. Of elke caller lege paden voorkomt, blijft te volgen.

## Nog te onderzoeken

- Pixeldecoders en runtime-shutdownvolgorde; factory/stream/ownership zijn verder uitgewerkt in het gekoppelde vervolgonderzoek.
- MP3/WMA-decoderfilters in de graph, decoderfouten, andere herstelhandlers en alle notification-/teardownraces.
- Alle native encoding-/flagcombinaties, locale-sortering, genrestrings en gedrag bij partial I/O.
- Installed-state/devicebewijs voor actuele registryafmetingen, gebruikte audiobestanden en daadwerkelijke symptomen.

De 40 behouden ranges en geslaagde modellen betekenen dat deze onderdelen controleerbaar zijn uitgewerkt. Ze betekenen niet dat MgrUSB, imaging.dll of de totale firmware volledig semantisch gereconstrueerd zijn.
