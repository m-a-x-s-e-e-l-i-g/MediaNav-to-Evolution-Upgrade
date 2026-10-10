# MgrUSB muzieklijst, shuffle, repeat en DirectShow

Nieuwste implementatie: [saved repeat/shuffle-validatie](usb-resume-modes-development.md) houdt repeat 0–3 en shuffle 0–1 exact gelijk; andere DWORDs worden off bij publicatie naar playback/shared velden. Alle vorige 1.918 paths en fixes behouden. 66.190 nieuwe + 6.196 behouden bytechecks slagen. Saved blob/checksum/filebytes gelijk; overige IPC-setters en threadsnapshot blijven aparte routes. Geen release; onderstaande analyse beschrijft de oorspronkelijke code.

Nieuwste implementatie: [next/previous folder](usb-folders-development.md) in volledige usb-folders-development-01. Lege table-read en verkeerde backwardsID/index-stop gerepareerd; boundedcycle, gewoneorder/rootfallback en cancellation behouden. Sleep1 iedere32entries/Sleep0anders; grotere veiligheidscheckkosten, circa97% minder timedwaits in5000-folderfixture. 1.224 nieuwe +4.972 behouden cases; actualprevious-trackselector, next-callsite en native-iterator-shufflebuilder gecontroleerd. Alle vorige fixes behouden; geen native snelheidclaim of release.

Nieuwste implementatie: [USB filename sorting](usb-sorting-development.md) in volledige usb-sorting-development-01. Oorspronkelijke sortdispatch, recordmaten en bookkeeping behouden; comparator verwerkt alleen tot eerste verschil. Echte mapper/raw-tiebreak/signedtable gelijk, geen persistent cache. 3.484 nieuwe +1.488 behouden bytecases; 256-songfixture 138.964->2.836 weightcalls met gelijke order. Native snelheid/qsort/scheduling open; alle eerdere fixes behouden, geen release.

Nieuwste implementatie: [shuffle cancellation en wachten](wma-shuffle-development.md) in volledige development-02. Poolfailure wordt doorgegeven, gedeeltelijke lijst gewist, ranges/anker begrensd en vijf consumers vereisen complete lijst. 104 shufflecases+35selectiecases; Sleep1 iedere32iteraties/Sleep0anders. Originele randomorder/foldergroepen behouden; native timing/concurrency open.

Vervolganalyse: [playlistreaders en resume-input](usb-media-input-contracts.md) werkt inmiddels M3U/PLS/WPL en USBMusicResume.dat uit, inclusief een tweede route die shuffle zonder normalisatie herstelt.

De beschikbare 7.0.5.MD-versie van MgrUSB gebruikt een begrensde muzieklijst, shuffle per map en de DirectShow Filter Graph Manager uit de ROM. [Het bewijsbestand](firmware/usb-playlist-contracts.json) bewaart twee bronhashes, 54 originele bytebereiken, zeven COM-GUIDs en offline controles. Er is geen native executable uitgevoerd.

## Recordstructuren en scan

`CFileMgr`-constructor `14b00` maakt de songcatalogus via `12aa4`: allocatie `0x284880 = 5000 * 528` bytes. Beide mapbuffers zijn `0x298100 = 5000 * 544` bytes. Muziekrecordgetters controleren zowel de onder- als bovengrens; verschillende mapgetters controleren alleen `index < 5000`.

| Muziekrecord, 528 bytes | Type | Betekenis |
| --- | --- | --- |
| `000..207` | UTF16[260] | Naam of playlistpad |
| `208` | signed int16 | Map-ID |
| `20a` | unaligned uint32 | Absoluut-padflag; nul betekent opbouwen via mapouders |
| `20e` | signed int16 | Mediatype: scanner gebruikt 1 MP3, 2 WMA |

De onuitgelijnde DWORD op `20a` is bevestigd door setter `12c30` en getter `12c68`. Het mediatype staat dus op `20e`, niet op `20a`. Parentsetter/getter zijn `12ba8`/`12cfc`; mediatypesetter/getter `12bec`/`12cac`.

| Maprecord, 544 bytes | Type | Betekenis uit gevolgd gebruik |
| --- | --- | --- |
| `000..207` | UTF16[260] | Naam |
| `208` | uint32 | 0 gewone map, 1 playlist als virtuele map |
| `20c` | signed int16 | Werkelijke oudermap; root wordt -1 |
| `20e`, `210` | signed int16 | Eerste childrecord en aantal children |
| `212`, `214` | signed int16 | Eerste trackindex en aantal tracks |
| `216`, `218` | signed int16 | Ouder/groepering en index voor de weergegeven mappenlijst |
| `21a` | signed int16 | Map-ID na sorteren; gebruikt in de afspeelvolgordetabel |
| `21c` | uint32 | Contentclassificatie; 2 zodra muziek is toegevoegd |

`13d88` sorteert map- en trackblokken met comparator `135f0` en schrijft bovenstaande start-/aantalvelden. De comparator bouwt in `173d8`/`172c0` een andere representatie van namen; de volledige locale-/naamnormalisatie blijft open. `14390` bouwt de mapvolgordetabel op `CFileMgr+40`, met int16-count op `+2750`. Bij diepte 3 worden verdere submappen verzameld en gesorteerd; dit is een flattening van de weergegeven structuur, geen bewezen scanlimiet van drie niveaus. `14720` loopt de tabel cyclisch door en slaat mappen zonder tracks over. `146ec` geeft de laatste map-ID uit de tabel terug.

Scanner `13894` stopt bij 5000 tracks. De gevolgde gewone bestandenroute accepteert `.MP3` en `.WMA`; `.M3U`, `.PLS` en `.WPL` worden als playlists toegevoegd met types 7, 8 en 9. Het bewijst geen ondersteuning van andere muziekformaten via een andere route. Visible directories met HIDDEN of SYSTEM worden niet als gewone directory toegevoegd; de gewone directoryroute sluit `.`, `..`, `Recycled`, `System Volume Information` en `.Trashes` exact uit. In de andere route worden attribuutwaarde `0x26` en HIDDEN overgeslagen; SYSTEM op zichzelf wordt daar niet afgewezen.

**Grensafwijkingen:** de suffixcheck berekent `filename_length - 4` zonder voorafgaande minimumlengtecheck. Een naam korter dan vier UTF16-eenheden kan vóór de lokale naamkopie worden gelezen. Mapgetters `12ed8`/`12f10`/`12f48` begrenzen negatieve indices niet. In padbouwer `13350` wordt de oorspronkelijke songnaamlengte bij meerdere ouderprefixen niet cumulatief bijgewerkt; de afzonderlijke stringcalls hebben wel eigen capaciteitsgrenzen. Bereikbaarheid en zichtbaar gedrag zijn niet op de unit vastgesteld.

## Shuffle en asynchrone opbouw

Extern shufflecommando `6a` wordt door `21d00` als vier payloadbytes doorgestuurd naar intern `66`. `20eac` roept wrapper `1ddb0` aan: `19ae0` normaliseert **ieder niet-nul DWORD naar 1**. Daarna wekt `22f54` de worker, die via `22a8c` → `1dd94` → `1b5b0` de lijst opbouwt. De worker zelf begrenst alleen waarden groter dan 1, maar negatieve waarden bereiken hem niet via deze genormaliseerde IPC-route. Andere schrijvers en races zijn nog niet volledig onderzocht.

`19af8` begint met de map van de huidige track, loopt daarna cyclisch door `14720` en concateneert voor iedere map het resultaat van `198e4`. Alleen in de eerste map wordt de huidige track als anker meegegeven. Resultaat: de huidige track staat vooraan en iedere map blijft een aaneengesloten groep; dit is geen globale shuffle van alle tracks tegelijk.

`198e4` vult een tijdelijk array met aaneengesloten trackindices. Bij elke keuze leest hij een random DWORD, neemt `random % remaining`, schrijft de gekozen track naar de uitvoer en vervangt zijn tijdelijke slot door de laatste resterende track. De laatste overgebleven track wordt direct geschreven. Assembly bevestigt een bufferstart op `sp+20` en voldoende slots voor 5000 DWORDs; Ghidra's lokale `[5001]`-weergave is geen afzonderlijk bewezen 5001-track-capaciteit. De functie heeft zelf geen check op meer dan 5000 tracks. Met een niet-negatief anker buiten het opgegeven bereik blijft de ankerindex -1 en wordt op `sp+1c`, vóór de buffer, gelezen. Geldige callerdata voorkomt dat pad.

De randomcall is ROM-export **COREDLL ordinal 2655, `rand_s` op `4007d638`**. Die zet het output-DWORD eerst op nul en roept `CeGenRandom(4, pointer)` aan. `CeGenRandom` op `400346c8` geeft pointer/lengte in omgekeerde argumentvolgorde aan systeemcall `fffe6aa6`; de returnwaarde blijft in MIPS `v0`, hoewel Ghidra hem ten onrechte als `void` presenteert. `rand_s` geeft 0 bij succes en `0x16` bij mislukking. MgrUSB negeert die status. Bij een generatorfout zonder outputwrite kiest hij daarom slot nul; gedeeltelijke outputwrites bij een kernelgeneratorfout zijn nog open. Zelfs succesvolle 32-bit randomwaarden hebben bij `% remaining` een kleine verdelingsafwijking wanneer `remaining` geen deler van 2^32 is; geen conclusie over de kwaliteit van de onderliggende generator.

**Annulering:** de poolworker controleert USB-verwijdering en shuffle-uit zowel tijdens vullen als tijdens selectie en retourneert dan -1. De builder `19af8` verhoogt daarna toch zijn interne trackcount met het volledige mapaantal; hij controleert de foutstatus niet vóór de volgende map. `1b5b0` negeert ook het builderresultaat. Of een gedeeltelijke lijst bij een concrete race werkelijk wordt gebruikt, hangt af van de overige threads en toestand; dat is nog open.

## Repeat en einde van een track

Repeatcommando extern `6b` wordt intern `67` en loopt via `1ddcc` naar `1b544`. Waarden groter dan 3 worden nul; negatieve DWORDs worden als signed waarden behouden. De auto-next-handler `1d23c` behandelt iedere waarde behalve 1, 2 en 3 als off.

| Waarde | Gedrag bij normale geldige catalogus |
| --- | --- |
| 0 | Volgende track/map; stopt na de laatste track van de verzameling |
| 1 | Speelt dezelfde track opnieuw af |
| 2 | Loopt binnen de huidige map rond |
| 3 | Loopt de volledige verzameling rond |

Zonder shuffle gebruikt repeat-folder de velden `212/214`; aan het einde wordt rechtstreeks de eerste track van die map afgespeeld. Met shuffle vergelijkt de handler de map-ID van de huidige en volgende array-entry. Verlaat de volgende entry de map, dan wordt `cursor - folder_count + 1` berekend en bij negatieve uitkomst naar nul begrensd. Hij speelt zo het begin van dezelfde shuffled mapgroep opnieuw af. De code vertrouwt daarbij op consistente mapaantallen en de aaneengesloten groepen die de builder produceert.

Repeat-off stopt bij shuffle wanneer `cursor >= count-1`. Zonder shuffle vergelijkt hij de map-ID op `21a` met de laatste map in `146ec`. Stop meldt UI-commando `66`; in het sequentiële eindpad wordt ook `65` verstuurd voor de tijd/statusupdate. Volledige COM-/fout-/pause-afhandeling blijft apart te reconstrueren.

Tracksetter `19c94` kijkt naar `HKLM\LGE\SystemStatus\BTCall\CallState`. Bij waarde 1 vervangt een geldige manager-`+74` de aangevraagde trackindex en verstuurt hij UI-commando 100. Het offline repeatmodel veronderstelt daarom geen actieve BT-oproep. De [eerdere seekanalyse](appmain-interaction-contracts.md) behandelt de aparte hold/seek-timers.

## DirectShow in ROM

`11000` initialiseert COM met `CoInitializeEx(NULL, 0)`. `11054` maakt `CLSID_FilterGraph` met `IID_IGraphBuilder`, in-process context 1. De bootregistry koppelt die class aan **quartz.dll**. `11f78` roept vtable-slot `34` aan als `IGraphBuilder::RenderFile(path, NULL)`, vraagt daarna vijf interfaces op en registreert `IMediaEventEx::SetNotifyWindow` met message `8001`.

| GUID | Geïdentificeerde interface | Objectslot |
| --- | --- | --- |
| `56a868a9-0ad4-11ce-b03a-0020af0ba770` | IGraphBuilder | `+10` |
| `56a868b1-0ad4-11ce-b03a-0020af0ba770` | IMediaControl | `+4` |
| `56a868c0-0ad4-11ce-b03a-0020af0ba770` | IMediaEventEx | `+8` |
| `36b73880-c2c8-11cf-8b46-00805f6cef60` | IMediaSeeking | `+c` |
| `56a868b3-0ad4-11ce-b03a-0020af0ba770` | IBasicAudio | `+14` |
| `56a868b2-0ad4-11ce-b03a-0020af0ba770` | IMediaPosition | `+18` |

`1111c` gebruikt IMediaSeeking-slot `38` voor `SetPositions`, current absolute flag 1, geen stoppointer en stopflags 0. De eerder afgeleide eenheid 10.000.000 per seconde klopt met [Microsofts SetPositions-contract](https://learn.microsoft.com/en-us/windows/win32/api/strmif/nf-strmif-imediaseeking-setpositions). GUIDs en interfacevolgorde zijn vergeleken met Microsofts [strmif.h](https://raw.githubusercontent.com/microsoft/win32metadata/main/generation/WinSDK/RecompiledIdlHeaders/um/strmif.h) en [control.h](https://raw.githubusercontent.com/microsoft/win32metadata/main/generation/WinSDK/RecompiledIdlHeaders/um/control.h).

Loader `12264` accepteert in deze route mediatype 1 of 2 en vereist een ingeplugde USB-mass-storage-status in de registry. De graphbuilder kiest de filterketen via RenderFile; een daadwerkelijk geselecteerde MP3/WMA-decoder is hiermee nog niet vastgesteld. De ROM-registry wijst WMA-extensionhandling naar de ASF Reader-class, eveneens quartz.dll. Andere geregistreerde formats betekenen niet automatisch dat MgrUSB ze scant of afspeelt.

`11054` vereist HRESULT exact nul voor zijn createpad; diverse andere calls gebruiken de gewone niet-negatieve succescheck. Een mislukte QueryInterface in `11f78` retourneert een HRESULT na gedeeltelijke interfaceopbouw zonder cleanup op dat punt. Complete callercleanup, graph-lifetime, events en foutrecovery blijven open.

## Reproduceerbare controles en vervolg

`py tools/inspect_usb_playlist.py` verifieert alle 54 bytebereiken en zeven GUIDs tegen de twee bronhashes. Het selectiemodel dekt **11.826** mogelijke permutaties voor 1..7 tracks, met en zonder ieder geldig anker, tegenover onafhankelijk gegenereerde permutaties. Daarnaast worden 72 repeatgevallen, een gepakt UTF16-record en zes expliciet afgewezen ongeldige record-/poolinputs gecontroleerd. Dit bewijst de eigenschappen van de statisch afgeleide modellen, niet native timing of playback op hardware.

Open voor verder lokaal onderzoek: M3U/PLS/WPL-parsers, metadata, USBMusicResume.dat, volledige graph-events en release/errorstates, sorteerrepresentatie, kernelgenerator achter CeGenRandom, gelijktijdige scan/annulering en alle overige modules in [de onderzoekstatus](research-status.md). Er is nog geen volledige dump van de geïnstalleerde unit beschikbaar.
