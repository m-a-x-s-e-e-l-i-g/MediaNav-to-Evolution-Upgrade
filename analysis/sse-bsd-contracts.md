# SSE BSD-configcontainer en moduleverdeling

Dit rapport volgt de BSD-descriptor, bestandsreader en dispatch in `sse_int.dll` 3.15.0.20004. Bronhash en originele bytebereiken staan in [echo-audio-contracts.json](firmware/echo-audio-contracts.json). De [offline parser](../tools/parse_sse_bsd.py) leest uitsluitend bestanden en heeft synthetische little-/big-endian fixtures voor primitieve en structrecords. Geen firmwarecode is uitgevoerd. Er is nog geen echte `.bsd` beschikbaar om deze reconstructie aan unitdata te toetsen.

## Descriptor en passes

Descriptorinit `0x10025460` accepteert maximaal drie bronnen, met pointers op +4/+8/+12 en lengtes op +16/+20/+24; de eerste WORD bevat het aantal. Alle gebruikte pointers/lengtes moeten niet nul zijn. Hij maakt een genormaliseerde context met een nulgesloten pointerlijst, lengtes en de gedeelde reader. EchoCanceller levert één bron, type/aantal 1, met het hele geladen bestand.

`sseInitialize` doet twee passes. De eerste, `0x10026ecc`, behandelt `SSE_MAIN_`-records en telt ruimte voor `SSE_PHONE_Config`/`SSE_PHONE_SendEQ`. De tweede, `0x10027280`, verdeelt overige `SSE_`-records over modules. Een onbekend of voor een uitgeschakelde module bestemd record wordt geteld en via de skiphelper overgeslagen; onbekend betekent hier niet automatisch een defect bestand. Een uitgelezen structversie/-inhoud met een foutstatus stopt de pass. De geconfigureerde callbacks en aanwezigheid van een naam bewijzen nog niet dat de bijbehorende module op het apparaat actief is.

## Bestandsheader en endianness

Open `0x100298f0` en headerreader `0x100296e8` gebruiken **84 bytes**: vijf DWORDs gevolgd door 64 naambytes. Vier beginbytepatronen zijn toegestaan: `00 01 02 03`, `00 01 22 03` voor de native little-endian route; `03 02 01 00`, `03 22 01 00` voor de byteswaproute. Alleen DWORD +8 wordt in deze headerreader na de keuze naar de readercontext gekopieerd en eventueel geswapt. De overige headerfields zijn nog niet volledig semantisch benoemd.

`0x10029850` vereist dat de hoogste byte van de waarde op +8 groter dan 1 is. Vervolgens volgen twee tags: DWORD `0x02000000`, DWORD `0`. Taghelper `0x10029678` scheidt de bovenste byte van de onderste 24 bits. De primitieve WORD-/DWORD-readers doen byte-swaps afhankelijk van de gekozen readerflag; ruwe namen blijven bytes.

## Recordheader

Reader `0x10027cb4` neemt de volgende delen, zonder gevonden alignment-padding:

| Bestandspositie relatief aan record | Inhoud |
| --- | --- |
| +0 | DWORD marker `0x0a0d0a00` |
| +4 | DWORD naamlengte |
| +8 | DWORD dat deze reader overslaat |
| +12 | Zeven DWORDs metadata |
| +40 | DWORD payloadlengte |
| +44 | DWORD headerchecksum |
| +48 | Naambytes, exact naamlengte |
| Daarna | Eventuele structdescriptor, payload en trailer |

De zeven metadatawoorden zijn genormaliseerd op readercontext +0xc..+0x24. Metadata[0] is de structversie, [1] het BSD-datatype, [4..6] zijn dimensies. Metadata[2..3] zijn nog niet volledig benoemd. De gevolgde caller biedt `0xab` bytes naamruimte; de reader accepteert alleen naamlengte <171 en voegt zelf NUL toe. Dit is een reader-/callercontract, geen algemene aanname voor andere BSD-implementaties.

De headerchecksum is een DWORD-som modulo 2^32: **numerieke marker + numerieke payloadlengte + alle bytes van een native 36-byte struct + naambytes**. Die struct bevat naamlengte, nul als naam-pointerplaceholder en de zeven metadataDWORDs. Het overgeslagen DWORD op bestandspositie +8 wordt niet meegenomen. Dit is geen CRC. De checksum is in de raw loop `0x10027e08..` gecontroleerd.

## Datatypes, structdescriptor en trailer

Breedtehelper `0x10028000` geeft 8 bytes voor BSD-type 1; 4 voor 2/3/4/12/13/14; 2 voor 5/6/15/16; 1 voor 7/8/9/11/17/18. Deze enum is een andere tabel dan de 35 SSE-API-datatypes in de parametermetadata. Type 10 wordt door skiphelper `0x1002910c` expliciet geweigerd; zijn formaat is hier niet ingevuld.

De primitieve typed readers controleren dimensies × elementbreedte tegen payloadlengte via `0x10028414`. Hun trailer is marker `0x0a0d0a00` plus een DWORD byte-som van de payload (`0x10028098`). Een geswapt DWORD/WORD behoudt dezelfde byte-som. De skiphelper controleert wel de marker, maar leest de tweede trailerDWORD zonder vergelijking. Een overgeslagen record wordt dus minder diep gecontroleerd dan een daadwerkelijk gebruikte moduleconfig.

BSD-type 11 is een struct: vóór de payload staat een DWORD schema-lengte, zoveel schema-bytes en één checksumbyte. `0x100287a0` vergelijkt het schema met het door de module gevraagde schema en controleert de checksumbyte tegen een byte-som modulo 256. Schema 9 en 12..18 gebruiken nog een volgende signed byte voor arraylengte; de typed structreader `0x100289dc` accepteert de gevolgd uitgewerkte arrays met omvang 1..127. Sommige scalar sentinelwaarden betekenen dat een destinationfield ongemoeid blijft, maar tellen wel mee voor de data-checksum. De structtrailerchecksum begint bij de schema-checksumbyte en telt de werkelijk gelezen payloadbytes op. De offline parser controleert deze buitenste som, zonder destinationstructs of DSP-instellingen te construeren.

## Module-dispatch

De tweede pass verwijdert eerst `SSE_` en vergelijkt vervolgens naam-prefixen. Onderstaande tabel komt uit `0x10027280`; callbacks zijn parserfuncties, niet automatisch processingkernels.

| Prefix na SSE_ | Parsercallback | Gevolgde aanduiding |
| --- | --- | --- |
| ANAL_Mic / ANAL_Ref | `0x1000f984` | Microfoon-/referentieanalyse |
| SYNTH_ | `0x10010fb8` | Synthese |
| POWER_ | `0x10042400` | Power-/signaalstatistiekconfig |
| SPEC_ | `0x1004ea74` | Spectrumconfig |
| NOISE_ | `0x10031924` | Noise-moduleconfig |
| TSINFO_Ref | `0x100517e4` | Referentie-tijdsignaalinfo |
| AEC_ | `0x100013e8` | Echo-cancellerconfig |
| NR_ | `0x100339d0` | Noise-reductionconfig |
| PEST_ | `0x10041f84` | PEST, volledige semantiek open |
| AGC_ | `0x1000d2e4` | Gain-controlconfig |
| RECV_ / TSINFO_Recv | `0x10042b44` | Receiveconfig |
| HFEF_ | `0x1002f320` | HFEF, volledige semantiek open |
| PHONE_ | `0x10026b7c` | Phone-/send-EQconfig |

De MAIN-pass herkent Config, SparseProcConfig, PrototypeFilterInt16, AnalysisFilterInt16, MicAnalysisFilterInt16, RefAnalysisFilterInt16, SynthesisFilterInt16, InputFilterInt16 en OutputFilterInt16. De schema's van andere modules en de DSP-kernels blijven open.

## Dertien MAIN_Config-schema's

De [template-extractor](../tools/inspect_sse_templates.py) volgt begrensd de constanten in de twee inline jump-tabellen op `0x10025e50` en `0x10025eec`, inclusief branch-delay-slots. Hij voert geen SSE-code uit. De [JSON-evidence](firmware/sse-main-config-templates.json) bevat per versie het BSD-datatype, de bytebreedte, destinationoffset, oorspronkelijke store-adressen en bronbytes/hash. De automatisch geëxporteerde pseudocode mist delen na deze indirecte sprongen; de oorspronkelijke instructies zijn leidend.

| Structversie | Velden/schema-bytes | Payloadbytes |
| --- | ---: | ---: |
| 1 | 29 | 102 |
| 2 | 36 | 132 |
| 3 | 37 | 138 |
| 4 | 38 | 142 |
| 5 | 41 | 154 |
| 6 | 46 | 174 |
| 7 | 50 | 186 |
| 8 | 51 | 190 |
| 9 | 52 | 192 |
| 10 | 53 | 196 |
| 11 | 54 | 200 |
| 12 | 56 | 208 |
| 13 | 57 | 212 |

Dit zijn scalar-schema's met types 3/4 (4 bytes) en 6 (2 bytes). Versie 1 heeft vijf destinationoffsets `-1`; versie 2 heeft er één. Deze velden worden gelezen en tellen mee voor de checksum, maar schrijven geen destinationfield. Vanaf versie 3 verdwijnt dat oude tweebyte dummyveld en komen twee DWORDs erbij: daarom groeit versie 2→3 met zes bytes. Versie 3 is vervolgens de gemeenschappelijke prefix van versies 4..13.

De destination is eerst een **tijdelijke 0x170-byte configstruct** op stack +0x118. Na parsing vergelijkt `0x10025be8` OperationMode (+0x38), SpeechSampleRate (+0x28), FrameShift (+0x2a), MicInChannelCount (+0x22) en, alleen bij beide explicit-referenceflags +0x150=1, RefInCnt (+0x14e) met de callerconfig. Conflicten geven `0x307`. Deze offsets zijn relatief aan de configstruct; ze mogen niet zonder de extra +4 worden verward met de volledige SSE-context.

De merge vanaf `0x10026518` kopieert de gevolgde scalarwaarden alleen als ze niet nul zijn. De typed reader `0x100289dc` slaat daarnaast individuele maximum-sentinels over (type 3: `0x7fffffff`, type 4: `0xffffffff`, type 6: `0xffff`). Versie ≥7 weigert de oude niet-nulle velden op +0x30 en +0x24 met `0x304`; een versie buiten 1..13 krijgt `0x302`. De volledige vervolgmapping en de betekenis van alle overige destinationfields blijven apart te volgen. Er is geen echte BSD waaruit de gekozen structversie of concrete instellingen van deze unit afgeleid kan worden.
