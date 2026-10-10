# USB playlists en USBMusicResume.dat

Nieuwste implementatie: [save-failure diagnostics](usb-save-feedback-development.md) meldt failure via debuglogger en slaat SAVE na failedLOAD in de mode-resetroute over. De oude checksumguard voorkwam al een legeblobwrite; dispatcherreturn is message-handled, niet save-success. Originele active-modesreset/recoveryformat/playback/removal behouden. 111 nieuwe + 72.386 behouden bytechecks en negen aanvullende notification-statecases slagen. Geen release; native readiness na failed reset blijft te testen.

Nieuwste implementatie: [saved repeat/shuffle-validatie](usb-resume-modes-development.md) vervangt publicatiehelper 1abac in volledige ontwikkeling. Geldige repeat 0–3/shuffle 0–1 blijven gelijk, andere DWORDs worden off. Geen wijziging van blob/checksum/filebytes; primary/backup-load en failed-load-gedrag behouden. 66.190 nieuwe + 6.196 behouden bytechecks slagen. Geen release; onderstaande enumbevinding betreft de oorspronkelijke bytes, niet deze ontwikkeling.

Nieuwste implementatie: [playlistregels en UTF8-BOM](artwork-playlist-development.md) in complete ontwikkeling. Alle zes linecalls vervangen; oversizedphysical-line wordt volledig overgeslagen, full-bufferEOF/LF/CRLF behouden, readerror apart en UTF8-BOM verwijderd. 73 line-/fault-/relocationcases + zes echte M3U/PLS/WPL-readertraces; native CRT en embeddedNUL blijven open. Onderstaande analyse bewaart de oorspronkelijke code.

Nieuwste vervolg: [herstelbare resume-opslag](usb-reliability-development.md) in complete ontwikkeling: `.new` write/flush/close/readback/exactcompare, bestaande validprimary naar `.bak`, loaderfallback en mutex. 112 actual-byte failure/interruption/boundscases. Geen fysieke power-cut-/native timingclaim; enumchecks, save-errorfeedback en threadsnapshot blijven open. De analyse hieronder beschrijft de oorspronkelijke bytes en historische ontwikkelstappen.

Nieuw vervolg: [save/load- en playlistreparaties](usb-input-safety-development.md) zijn geïmplementeerd in volledige cumulative ontwikkeling. Exacte savecounts/closechecks, eenmalige loaderclose, tekstterminators en attribuutfouten, begrensde paden en correcte bestand-/directorychecks. 417 nieuwe bytecases inclusief 30 echte readerfuncties; transactionele opslag en native verificatie blijven open. Onderstaande analyse beschrijft de oorspronkelijke code.

Ontwikkelvervolg: [USB-resume-reparatie](media-responsiveness-development.md) verwijdert uitsluitend de vrije-ruimtevoorwaarde in de volledige cumulative MAX03-staging. 25 actual-byte resume/rematchcases slagen; oorspronkelijke analyse hieronder blijft behouden. Geen native test of nieuwe release.

Dit vervolg op [catalogus/shuffle/DirectShow](usb-playlist-contracts.md) volgt de drie playlistreaders, hun pad-/attribuutchecks en de hervatdata. [De evidence](firmware/usb-media-input-contracts.json) bewaart 37 originele bereiken uit MgrUSB SHA256 `bb435bc428664845a21ffe7bce7a813db06b7e7f92408d297dbbeade94507cd2`. Native code en hardware zijn niet uitgevoerd.

## Drie playlistreaders

Scanner `13894` registreert maximaal 1000 playlistcatalogusrecords van `0x11b8 = 4536` bytes via `1311c`. Naam staat op `0`, catalogusindex op `208`, type op `20a`, parent op `20c`, een nul-DWORD op `210`. De getraceerde importer `152a4` matcht playlists aan virtuele maprecords en dispatcht types 7/8/9. De gewone recursive mapscan breekt bij `param_6 > 19`; dit is een afzonderlijke scanlimiet, terwijl de eerder beschreven flattening bij diepte 3 alleen de weergegeven structuur betreft.

| Type | Importwrapper | Reader-vtable | Reader |
| --- | --- | --- | --- |
| 7, M3U | `14e4c` | `27bfc` | `15c00` |
| 8, PLS | `14fb8` | `27c20` | `165e8` |
| 9, WPL | `15124` | `27c34` | `16910` |

De gedeelde loader `15ba0` → `164c0` opent `_wfopen(path, L"rt")`. `15e4c` gebruikt `fgets` met een **260-byte** buffer, forceert byte 259 naar NUL en stript maximaal twee terminale CR/LF-bytes. Lange regels worden dus via meerdere fgets-chunks gelezen; er is geen aangetoonde regel-overslaanroute die alle resterende bytes van een lange regel consumeert. Exacte CE-CRT-tekstvertaling blijft apart open.

Iedere reader decodeert met `MultiByteToWideChar(codepage=65001, flags=8)`: UTF-8 met invalid-sequence-check, geen aangetoonde ANSI- of UTF16-fallback. De UTF16-outputbuffer heeft 260 eenheden. Een UTF-8-BOM wordt niet expliciet overgeslagen. De readerobjecten hebben een 1000-record werkbuffer (`0x80e80 = 1000 * 528`), maar appendhelper `16104` accepteert alleen `old_count+1 < 1000`: effectief **999 entries per playlist**. Daarna wordt ieder kandidaatpad met absolute-padflag 1 in de globale 5000-trackcatalogus gekopieerd. Die appenders hebben een andere metadata-indeling dan het uiteindelijke songrecord: de tijdelijke mediatype-DWORD op `20c` wordt door de wrapper naar het songrecord-int16 op `20e` vertaald.

`152a4` sorteert geïmporteerde songrecords met `qsort(..., 528, 135f0)` als er meer dan één entry is. De oorspronkelijke playlistvolgorde wordt daardoor niet als afspeelvolgorde bewaard; de volledige sorteerrepresentatie/locale-semantiek is nog open. Er is in deze parsers geen duplicate-eliminatie aangetroffen.

### M3U

`15c00` neemt iedere niet-lege UTF16-regel waarvan het **eerste teken** geen `#` is. Hij trimt geen leading spaces, leest geen EXTINF-metadata en verwijdert geen BOM. Het kandidaatpad gaat via de gedeelde padbouwer, suffixcheck en attribuutcheck. Een regel ` #comment.mp3` wordt dus als padkandidaat behandeld, niet als commentaar.

### PLS

`165e8` vereist `_wcsnicmp(line, L"File", 4)==0`, zoekt daarna de eerste `=` en neemt de substring erachter wanneer dat teken na de vier prefixtekens staat. Een verplicht decimaal tracknummer is niet aangetoond: zowel `File=song.mp3` als `FileXYZ=song.mp3` voldoen. Headers, Titles, Lengths en NumberOfEntries worden niet via deze route gevalideerd. Leading spaces vóór `File` voorkomen herkenning.

### WPL

`16910` scant iedere regel naar een case-insensitieve exacte prefix `<media src`, zoekt daarna `=` en de eerste twee **dubbele** quotes. Het is een regelscanner, geen XML-parser. Single quotes of een regelbreuk tussen `media` en `src` worden niet herkend; er wordt maximaal één pad per aangeleverde regel/chunk genomen. Hij vervangt daarna case-sensitieve `&apos;`-sequenties door een apostrof. Algemene XML-entiteiten zoals `&amp;` en `&quot;` worden niet in de gevolgde code gedecodeerd.

## Padnormalisatie en foutchecks

Helper `161b4` gebruikt een gedeelde 520-byte UTF16-buffer en **onbegrensde `swprintf`**, ook als een lange basemap en een lange maar afzonderlijk geldige inputregel samen meer dan 259 eenheden bevatten. Het offline model produceert alleen strings; het reproduceert die bufferoverschrijding niet.

| Inputpad | Gevolgde omzetting |
| --- | --- |
| `song.mp3`, basemap `MD\Music` | `\MD\Music\song.mp3` |
| `\other\song.mp3` | `\MD\other\song.mp3` |
| `\MDfoo\song.mp3` | Ongewijzigd: check bekijkt alleen de eerste drie tekens |
| `C:\song.mp3` | `\MD\C:\song.mp3`: driveprefix wordt niet verwijderd |
| `http://a/song.mp3`, basemap `MD` | `\MD\http://a/song.mp3` |
| `../song.mp3`, basemap `MD\Music` | `\MD\Music\../song.mp3` |

Relatieve `..`, forward slashes, URL's en UNC-paden worden niet via een volledige canonicalizer verwerkt. Paden korter dan drie tekens worden direct teruggegeven; suffixhelper `16340` trekt bij iedere niet-lege string vier van de lengte af zonder minimumlengtecheck. Daarmee bestaat ook hier een vóór-buffer-leespad voor korte namen.

**Attribuutfout bevestigd in assembly `16150`:** `GetFileAttributesW(path)` wordt uitsluitend vergeleken met exact `0x10` (DIRECTORY). `INVALID_FILE_ATTRIBUTES = 0xffffffff` wordt niet afgewezen, evenmin een directory met extra attribuutbits. M3U/PLS kunnen daardoor ontbrekende `.mp3`/`.wma`-paden toevoegen. WPL roept aanvullend `1618c` aan en vereist `(attributes & HIDDEN)==0`; de foutwaarde heeft dat bit gezet en wordt daar wel afgewezen. Ook WPL controleert niet algemeen `attributes & DIRECTORY`, dus bijvoorbeeld directorywaarde `0x14` passeert beide helpers als zijn naam een muzieksuffix heeft. Het uiteindelijke afspelen kan zulke entries alsnog afwijzen; dit bewijst importgedrag, niet succesvol playback.

## Hervatbestand: 3180 bytes

Het lokale pad is `\Storage Card2\USBMusicResume.dat`. Het opgeslagen blok ligt op `CPlayControl+e64` en is **`0xc6c = 3180` bytes** lang. Save `1c17c` berekent byte 0 als `sum(bytes[1:3180]) % 256`. Verifier `1ab50` vereist daarnaast dat de volledige niet-modulaire body-som niet nul is. Een volledig nulblok is dus ongeldig; een niet-nul body met som 256 en checksum nul is geldig. Deze controle is geen CRC en twee compenserende bytewijzigingen houden de checksum gelijk.

| Bestandsoffset | Type | Veld uit gevolgd gebruik |
| --- | --- | --- |
| `000` | uint8 | Byte-somchecksum |
| `001..003` | bytes | Niet semantisch vastgesteld |
| `004` | uint32 | Aantal directoryrecords |
| `008` | uint32 | Resultaat directory-parentlookup met de trackindex; betekenis nog onzeker |
| `00c` | uint32 | Aantal tracks |
| `010` | uint32 | Trackindex |
| `014` | uint32 | Mediatype |
| `018` | uint32 | Afgespeelde seconden |
| `01c` | UTF16[260] | Bestandsnaam |
| `224` | UTF16[260] | Volledig pad |
| `42c` | UTF16[260] | Titel |
| `634` | UTF16[260] | Album |
| `83c` | UTF16[260] | Artiest |
| `a44` | UTF16[260] | Map/padveld uit shared-memorymetadata |
| `c4c` | uint32 | Repeat |
| `c50` | uint32 | Shuffle |
| `c54` | uint64 | Vrije schijfbytes |
| `c5c` | uint64 | Totale schijfbytes |
| `c64` | uint32 | Lage DWORD van bestandsgrootte |
| `c68` | uint32 | Volumeserienummer |

Builder `1a7d0` schrijft dit blok. Voor offset `008` roept hij `132a0(filemgr, track_index)` aan, terwijl die helper een directoryrecord-index verwacht en het parentveld op `20c` leest. Daarom is dat veld bewust niet als bewezen huidige map-ID benoemd. Na een geslaagde position-read zet timerhelper `1b3b0` offset `018` op afgeronde seconden; seekhelper `1b484` kan hem ook wijzigen.

De zes tekstslots zijn gekoppeld aan kopieën uit de eerder gereconstrueerde [statusmapping](usb-status-layout.md). De twee nog onbekende statusregio's blijven onbekend; ze worden hierdoor niet als metadata bestempeld.

## Laden, bewaren en hervatten

Loader `1be50` opent OPEN_EXISTING (3), leest precies 3180 bytes en controleert ReadFile-succes, gerapporteerde leeslengte en checksum. Hij controleert niet de volledige file size: trailing bytes na het eerste blok worden niet gelezen. Na de checksum forceert hij uitsluitend de laatste UTF16-eenheid van het full-pathveld naar nul. Vervolgens controleert hij het bestandspad en ouderprefixen op HIDDEN, en vereist een bestaande `a44`-padwaarde.

Gevolgde afwijkingen:

- Hij sluit de filehandle na ReadFile en bij geslaagde checksum nogmaals; beide CloseHandle-calls staan in de oorspronkelijke assembly.
- De returnwaarde van `GetFileAttributesExW` in de hidden-check wordt niet gecontroleerd. Bij mislukking gebruikt hij de lokale outputstruct toch; die is niet vóór de eerste call geïnitialiseerd. Werkelijk resultaat hangt af van de API en stackinhoud.
- Een ontbrekend resume-bestand laat via de handlefout de bestaande blob ongemoeid. Read-/lengte-/checksumfouten wissen het blok. Een mislukte uiteindelijke `a44`-padcheck retourneert 0 zonder het blok te wissen.
- Normale save `1c17c` gebruikt OPEN_ALWAYS (4) en truncate-save `1c2e8` gebruikt CREATE_ALWAYS (2). De laatste functie heet in logs `deletesaveResumeData`, maar schrijft gewoon opnieuw het huidige blok. OPEN_ALWAYS verwijdert eventuele trailing bytes niet.
- Beide schrijvers retourneren alleen WriteFile's BOOL; zij vergelijken het aantal geschreven bytes niet met 3180. Er is in deze functies geen FlushFileBuffers of atomische rename aangetroffen.

Attach-handler `1eac4` en boot-resume-thread `1fd6c` laden het blok en roepen `1abac` aan. **Deze helper kopieert repeat en shuffle rechtstreeks naar de actieve/shared velden zonder enum- of booleannormalisatie.** Dat is een andere schrijversroute dan de veilige IPC-shuffle-normalisatie. Welke inconsistente resume-enums na alle scan-/restorethreads werkelijk een arraydereference veroorzaken, is nog open; er is geen crash op hardware geclaimd.

`resumePlay` op `1ba3c` vergelijkt via `CompareFileTime` twee DWORDs die `1a69c` juist uit **bestandsgrootte-low en volumeserienummer** haalt. De API-naam is hier dus misleidend: er wordt geen wijzigingstijd vergeleken. Vervolgens moeten zowel de opgeslagen totale schijfbytes als de vrije schijfbytes exact gelijk zijn aan `GetDiskFreeSpaceExW(L"MD")`. Een wijziging van vrije ruimte kan daardoor resume blokkeren ook als de beoogde track ongewijzigd is. Een succesvolle graphload via `12264` herstelt metadata en seekpositie; volledige playback-/audiofocus-/errorstate blijft open.

## Offline parser en verificatie

`py tools/parse_usb_resume.py <lokale-kopie>` leest alleen een bestand en geeft de bewezen velden plus terminationdiagnostiek weer. Default vereist exact 3180 bytes. `--allow-trailing` modelleert de native prefixread en meldt extra bytes. Hij voert geen bestandspaden uit de blob uit en schrijft niets terug.

`py tools/inspect_usb_media_inputs.py` bewaart 37 bytebereiken en drie vtables, controleert acht padgevallen, tien regelgevallen, 21 attribuutgevallen en de 999-entrylimiet. `py tools/parse_usb_resume.py --self-test` controleert 3180 enkelvoudige bytemutaties, drie ongeldige inputs, trailing-prefixgedrag, modulo-wrap, een checksumcollision en de geforceerde full-pathterminator. Alle lokale fixtures zijn synthetisch; er is nog geen echte resume-kopie of volledige stickinhoud beschikbaar.

Volgende lokaal onderzoekbare punten: graph-events en lifetime/errorrecovery, ID3-/WMA-metadata, naamnormalisatie/sortering, scan/restorethread-interactie en ROM-filterimplementaties.
