# ROM-imaging: factory, bronbuffer en decoderkeuze

De ROM-module `imaging.dll` bevat de factoryroute die MgrUSB voor albumhoezen gebruikt. De factory verpakt de aangeleverde bytes in een IStream, houdt dat streamobject via IImage vast en selecteert een decoder via gemaskeerde bestandsignatures. Bij disposalflag 0 blijft de bronbuffer eigendom van de caller. De memory-stream negeert bij SEEK_END de displacement; decoderpolling heeft geen eigen deadline.

Dit vervolgt [USB-metadata en hoesbewerking](usb-metadata-contracts.md). Module-SHA-256: `f7592cc3360d97674a189c60b7d56e75a15ad2bceafe5eef6da47e8f20b70908`.

`py tools/inspect_imaging_factory.py` bewaart [54 bewijsbereiken, vier resourceblokken en drie vtables](firmware/imaging-factory-contracts.json). De controles omvatten 6.144 signaturemutaties, 20.196 begrensde reads en 154.836 seekgevallen. Geen COM-object, firmwaremodule of beelddecoder wordt uitgevoerd.

## Factoryroute en echte vtables

`DllGetClassObject` op `40487070` maakt een classfactory; CreateInstance `40486fb8` weigert aggregatie en maakt het achtbyte factoryobject met vtable `404810e0`. De interface-IID is `327abda7-072b-11d3-9d7b-0000f81ef32e`; MgrUSB gebruikt CLSID `327abda8-072b-11d3-9d7b-0000f81ef32e`.

| Object | Vtable | Relevante slots |
|---|---|---|
| Imaging factory | `404810e0` | `+14`: CreateImageFromBuffer → `40487c08` |
| Memory IStream | `40481170` | `+c`: Read → `4048f8d0`; `+14`: Seek → `4048f9b0`; `+38`: destructor → `40487bbc` |
| IImage | `40481664` | `+10`: GetImageInfo → `4048b6f0`; `+14`: flags → `4048a864`; `+18`: Draw → `4048b798`; `+24`: destructor → `4048b58c` |

IStream-QI accepteert de standaard-IID `0000000c-0000-0000-c000-000000000046` uit record `40481160`. De drie vtables zijn uit oorspronkelijke PE-bytes gelezen. De alternatieve vtable `4048108c` heeft stubmethoden; de concrete factory krijgt `404810e0`.

## Bronbuffer: referenties en vrijgave

`40487c08` controleert met IsBadReadPtr de eerste vier bytes van de bronpointer en met IsBadWritePtr de outputpointer. Hij maakt een 36-byte memory-stream met refcount 1, busyguard -1, pointer op `+c`, size op `+10`, positie op `+14` en disposalactie op `+18`.

| Publieke disposalwaarde | Interne actie |
|---|---|
| 0 | 0: bronbuffer niet vrijgeven |
| 1 | 1: LocalFree |
| 2 | 3: CoTaskMemFree |
| 3 | 4: UnmapViewOfFile |
| andere | E_INVALIDARG |

Streamdestructor `40487ad8` kent ook interne actie 2 (VirtualFree), maar deze factorymethod geeft die niet door via bovenstaande mapping. Een bewaard mappinghandle en de eigen hulpallocatie worden afzonderlijk opgeruimd.

IImage-constructor `4048b998` houdt de stream op `+14` en roept AddRef aan. Hij kiest/initieert meteen een decoder via `4048a094`; succes krijgt magic `49654431`, mislukking `4c494146`. De factory released haar tijdelijke streamreferentie; IImage houdt de stream in leven. Pixeldecodering volgt later via Draw.

IImage-destructor `4048a7a0` released de gecachete bitmap, termineert/releases de decoder en released de stream. Met MgrUSB's disposalwaarde nul blijft de bronbuffer daarna bestaan.

Aan MgrUSB-zijde vraagt CID3Tag-constructor `17468` 8 MiB aan allocator `12844`. Die registreert elke pointer en external/heap-flag in de globale lijst vanaf `2fb78`. Het [MGR1-drivercontract](mgr-driver-contracts.md) bevestigt de heapfallback wanneer IOCTL `15` geen externe pointer oplevert. Poolcleanup `129c8` gebruikt operator delete voor heapentries, of IOCTL `16` voor externe entries, wist de lijst en sluit het allocatorhandle. WinMain `24a90` roept die cleanup bij normale message-loop-exit en verschillende vroege returnpaden aan.

Dit is poolownership tot procesafsluiting; de lege tag-destructor bewijst geen permanent lek. Gedwongen procesbeëindiging, gewijzigde drivers en runtime-shutdownvolgordes zijn niet getest. De drie MgrUSB-ranges zijn toegevoegd aan de metadata-evidence.

## Vier ingebouwde codecs

`40488000` vraagt zes getterposities op. Vier geven descriptorpointers terug; twee zijn nulstubs. Ghidra typeert getters deels als `void`, maar de assembly retourneert hun descriptoradres in `v0`. Descriptorvelden en originele RT_STRING-resources bevestigen de identiteit.

| Codec | Descriptor | Signatures | Count × bytes | Factory |
|---|---|---|---|---|
| PNG | `404bd1a4` | `89 50 4e 47 0d 0a 1a 0a` | 1 × 8 | `4049675c` |
| GIF | `404bd1d8` | `GIF89a`, `GIF87a` | 2 × 6 | `404998d0` |
| JPEG | `404bd20c` | `ff d8` | 1 × 2 | `4049d3c4` |
| BMP | `404bd240` | `42 4d` | 1 × 2 | `404a22b4` |

Alle signaturemasks zijn `ff`. De resourcevelden bevatten codecnaam, formaatnaam, extensies en MIME-type. De getter voegt bit 2 toe aan stored flags 4; catalogusbouw voegt builtin-bit `10000` toe. Effectieve flags zijn `10006`.

De initloop bezoekt de array achterstevoren en voegt elke codec aan de head toe. De resulterende builtin-volgorde is **PNG, JPEG, GIF, BMP**. De signatures overlappen niet. De 6.144 mutaties valideren uitsluitend classificatie; GIF's 7/9-variatie blijft terecht geldig. Ze bewijzen niet dat een volledig beeld geldig is of correct decodeert.

## Selectie en externe registratie

`4048887c` initialiseert de builtin-lijst en scant, wanneer de relevante global nul is, HKLM en HKCU `Software\Microsoft\Imaging\Codecs`. Een bestaande catalogus wordt na minstens 30.000 ms opnieuw gescand. Een unit kan door registrycodecs een andere lijst hebben dan de vier ingebouwde records.

`4048a094` gebruikt de maximale signaturelengte uit de catalogus, leest de bytes en seeks terug. Voor alleen de vier builtins bedraagt dat acht bytes. `40488f6c` eist decoderflag 2 en vergelijkt volgens `(input & mask) == pattern`. Een builtinrecord geeft een factorypointer op `+58`; een registryrecord kan via een DLL-pad geladen worden. De decoder ontvangt de stream bij initialisatie.

De MIME-/formatcode uit APIC kiest dus niet rechtstreeks de decoder: de bronbytes bepalen de match. MgrUSB geeft steeds 8 MiB als streamsize door. De memory-stream ziet daardoor niet de echte APIC-framegrens als EOF, ook bij een veel kleinere hoes. Welke decoder bytes voorbij de eigenlijke beeldpayload gebruikt, blijft per decoder te volgen; de beschikbare buffer blijft 8 MiB.

## Memory-stream: Read en Seek

`4048f8d0` kopieert onder de busyguard `min(requested, size-position)` bytes, verhoogt de positie en schrijft readcount indien de outputpointer aanwezig is. Ook een short read of EOF retourneert S_OK zolang de guard beschikbaar is. De [officiële Read-documentatie](https://learn.microsoft.com/en-us/windows/win32/api/objidl/nf-objidl-isequentialstream-read) beschrijft short-readstatus en waarschuwt callers tevens S_OK bij EOF te verwerken; readcount blijft noodzakelijk.

`4048f9b0` accepteert alleen posities tussen nul en size met nul high-DWORD. SET gebruikt de offset; CUR telt positie en offset inclusief carry op. **END vervangt de hele offset door size.** Ongeldige origin of buitenbereik levert `80070057` op.

Assembly `4048fa28..4048fa3c` laadt bij END size in het low-word en zet het high-word op nul. Bij size 100 geeft END,-1 dus positie 100, terwijl end-relative -1 positie 99 betekent volgens [IStream::Seek](https://learn.microsoft.com/en-us/windows/win32/api/objidl/nf-objidl-istream-seek).

De modellen toetsen sizes 0..32, geldige posities, offsets -34..34 en vier origins. END negeert in 38.148 gevallen een niet-nul offset. Alle 64-bit-wrapgevallen vallen buiten dit model. De guard is geen slaaplock: gelijktijdige entree krijgt `887b0001` en herstelt de teller.

## Draw, caching en polling

`4048b798` maakt zo nodig een tijdelijke bitmap, vult die via `4048a928` en tekent via haar IImage-interface. Zonder flag `20000` wordt de bitmap na Draw gereleased. Het oorspronkelijke IImage start met flag `10000`; MgrUSB zet in dit pad geen extra cacheflag.

`4048a928` configureert de decoder, roept processing-slot `+18` aan en herhaalt bij HRESULT `8000000a`, met Sleep(0). De loop heeft geen iteratie- of tijdslimiet. Zodra de status verandert volgt slot `+1c`. Een decoder die permanent pending blijft kan dit pad onbeperkt laten wachten; dat gedrag is voor de concrete builtins nog niet bewezen.

GetImageInfo `4048b6f0` haalt informatie via de decoder op en combineert imageflags. Verdere pixel-/bitmap-/GDI-routines zijn nog niet volledig gereconstrueerd. MgrUSB's [breedteafhankelijke hoesbewerking](usb-metadata-contracts.md) gebeurt na deze ROM-Draw-call.

Factory, interfaces, bronbufferownership en vier builtin-dispatchrecords zijn nu gekoppeld. Het [vervolgonderzoek naar BMP en decoderinterfaces](imaging-bmp-contracts.md) volgt inmiddels BMP-headers/paletten/rijen/BITFIELDS, tijdelijke allocaties en PNG-dimensie-/formatkeuze. Volledige codecs/GDI, animatieframes, registrycodecparsing, overige streammethoden en volledige concurrency/shutdown blijven onderzoekbaar open.
