# MCU: herstelde skip-paden en normale berichtontvangst

Dit onderzoek gebruikt de ongewijzigde 262.144-byte `micom-image.bin`, SHA256 `4c5a45266f11cbd2a408c3b9880008a819091e61c61a7283f51949244bd76512`. De architectuur blijft een 78K0R/RL78-familiekandidaat; exact onderdeel, hardwaregedrag en runtimebereik zijn onbekend. Geen firmware is uitgevoerd of verbinding geopend.

## Fout in de eerdere traversal

De externe Pythondecoder herkent zes conditionele skips, maar `_succ()` volgt alleen de volgende instructie. Wanneer die instructie onvoorwaardelijk springt, ontbreekt het pad na die sprong. Onze eigen wrapper volgt nu beide paden met de volledige gedecodeerde instructielengte, inclusief een eventuele ES-prefix. Dit sluit aan bij de [Renesas-instructiehandleiding, hoofdstuk 6.11, pagina 174–179](https://www.renesas.com/en/document/mas/78k0r-microcontrollers-users-manual-instructions).

Concreet: `14e30: 61 f8` is `SKNZ`; `14e32: ee 8f 00` is een drie-byte `BR`. Het ontbrekende doel is `14e35`, met verdere ontvangsttoestandchecks. Het oude rapport met nul onopgeloste directe edges onderzocht een onvolledige graaf.

De externe decoder en oorspronkelijke exports blijven behouden. De permissieve variant bewaart bestaand fallthroughgedrag; de conservatieve variant stopt bij BRK1, HALT en onbekende decoderingen. Hier leveren beide hetzelfde resultaat op.

| Analyse | Instructiekandidaten | Afgedekte bytes | Nieuwe kandidaten | Onafhankelijke Ghidra-lengtes |
| --- | ---: | ---: | ---: | --- |
| Oorspronkelijke vector-/CALLT-roots | 2.524 | 4.962 | — | Eerder gecontroleerd |
| Dezelfde roots, volledige skip-edges | 3.886 | 7.759 | 1.362 | Alle 3.886 gelijk |
| Aanvullend zeven expliciete callbackslots | 5.747 | 11.614 | 1.861 t.o.v. vorige rij | Alle 5.747 gelijk |

Geen eerdere instructie verdwijnt of verandert van bytes. De tweede analyse bevat 42 skips; 36 hebben een doel dat de oorspronkelijke lijst miste. Geen overlappende instructiebytes of ontbrekende directe doelen binnen de image. Negen indirecte calls blijven open: `11d1`, `11fd`, `7c95`, `7ca0`, `7ec5`, `8da2`, `8ecc`, `b99c`, `27d7f`.

Ghidra gebruikt afzonderlijke projecten/outputmappen. Overeenkomst bewijst alleen instructiegrenzen onder de kandidaat-ISA. Bekende SLEIGH-pcode-, stack- en registerweergavefouten zijn hiermee niet opgelost. Aantallen zijn geen percentage begrepen firmware.

## Callbackslots als afzonderlijke hypothese

Bij `8da2` wordt een far-pointer uit ROM `64ee + index*4` geladen: laag woord naar DE, byte `+2` naar CS, vervolgens `CALL DE`. Zes expliciete niet-nulslots worden apart onderzocht:

| ROM-slot | Vier oorspronkelijke bytes | Kandidaatdoel |
| --- | --- | --- |
| `64ee` | `5c 78 02 00` | `2785c` |
| `64f2` | `82 78 02 00` | `27882` |
| `64f6` | `b1 78 02 00` | `278b1` |
| `64fa` | `cf 79 02 00` | `279cf` |
| `64fe` | `33 7a 02 00` | `27a33` |
| `6502` | `ed d5 00 00` | `0d5ed` |

Dezelfde pointeropbouw bij `8ecc` gebruikt `64b6 + index*4`; expliciete slot `64b6: d7 dc 00 00` wijst naar `0dcd7`. Totale tabelgrenzen, indexwaarden en feitelijke selectie blijven open. Geen blinde ROM-pointersearch; indirecte callsites blijven als open grenzen geregistreerd.

## Kandidaatontvangstparser voor gewone AA-frames

Interruptroots `e8c` en `ed4` lezen respectievelijk `fff46` en `fff4a` en roepen `14db6` aan met index nul/één. Precieze UART-/SFR-namen hangen af van het onbekende chipmodel.

De routine selecteert een context via helper `473` en constante `244`, met kandidaatbasis `fdd62`. Helper `473` schrijft AX en de tweede operand naar SFR-woorden `ffff0/ffff2`, leest `ffff6`, en bewaart/herstelt PSW. Interpretatie als indexberekening en RAM-layout moeten tegen het exacte onderdeel worden bevestigd.

| Toestand | Gevolgd bytegedrag |
| --- | --- |
| 0 | Wacht op `AA`. Index 0 gaat naar 1; index 1 zet headerbyte 0 op nul en gaat naar 2. |
| 1 | Bewaar eerste headerbyte; ga naar 2. |
| 2 | Bewaar commandobyte; ga naar 3. |
| 3 | Bewaar lengte. Niet nul gaat naar 4; nul naar 5. |
| 4 | Schrijf één payloadbyte, behandel pointerwrap/collision, verlaag resterende lengte; nul gaat naar 5. |
| 5 | Vergelijk huidige byte met XOR van `AA`, drie headerbytes en payload. Publiceer bij overeenkomst een record met payloadpointer; behandel headerwrap/collision. |
| 6 | Zet toestand op nul; verwerk deze byte verder niet. |

Na toestand 5 gaat index 0 naar nul en index 1 naar 6, ook bij verkeerde checksum. Index 1 heeft dus een korter wire-headerformaat en verbruikt daarna een extra byte. De functie van die tweede verbinding is nog onbekend.

Bij niet-nultoestand wordt het 16-bit verschil tussen teller `fe3d2` en de vorige byte getoetst aan `0x65`. Vanaf 101 tellerstappen wordt toestand nul voordat de huidige byte verwerkt wordt. Ook een resetflag zet vooraf toestand nul. Dit is geen bewezen timeout van 101 ms; tijdseenheid onbekend.

Index 0 past bij de [WinCE-zender](micom-protocol.md): `AA`, routebyte, commandobyte, lengtebyte, payload, XOR. Het gewone updatecontrolframe `(manager=1,type=1,command=5,len=0)` is `aa110500be` en past door deze framingprojectie. Commandhandler en overgang naar boot-/flashcode zijn daarmee niet aangetoond.

### Ringbufferkandidaten

Resethelper `14ce2` initialiseert pointers/toestand. Offsets vanaf de geselecteerde context:

| Offset | Kandidaatbetekenis |
| --- | --- |
| `0` / `2` | Parsertoestand / teller bij vorige byte |
| `4` / `6` | Payloadwerkpointer / resterende lengte |
| `8..37` | 48-byte headergebied; publicatie schuift zes bytes op |
| `38` / `3a` / `3c` | Headereinde / tegenoverliggende pointer / producer |
| `3e..23d` | 512-byte payloadgebied |
| `23e` / `240` / `242` | Payloadeinde / collisiongrens / volgende payloadstart |

Toestand 4 vergelijkt werkpointer en payloadcollisiongrens en roept bij gelijkheid resethelper `14ce2` aan. Na checksumacceptatie vergelijkt de headerproducer zich met de tegenoverliggende pointer en schuift die zo nodig zes bytes op. Consumersemantiek, ownership en interruptinterleavings blijven open. De offline framingprojectie gebruikt onbeperkte hypothetische opslag en simuleert ringfoutpaden niet.

## Verificatie en resterend updatepad

`inspect_micom_flow.py` controleert 24 skip-lengtefixtures: alle zes opcodes met één-, drie-, vier-byte en ES-geprefixte vervolgopdrachten. Hij reproduceert eerst exact de oorspronkelijke instructielijst en bewaart gaps/overlaps in afzonderlijke exports.

`inspect_micom_rx.py` bewaart vijf originele bytebereiken en elf preimages. De toestandprojectie vergelijkt alle 256 payloadlengtes met de onafhankelijke hostparser, wijst 256 gewijzigde checksums af, en controleert 256 index-1-frames plus acht randgevallen: opvolgende frames, discardbyte, timeoutgrens, tellerwrap, truncatie en reset. Modelchecks zijn geen native MCU-uitvoeringen.

Bij afzonderlijke lokale kandidaatdecodering vanaf de proloog `14303` valt de raw `4c a1`-hit bij `1430b` midden in `1430a: ac 4c` (`MOVW AX,[HL+4c]`); `a1` bij `1430c` wordt `INCW AX`. Dit pad is niet vanaf onze roots bereikt of met Ghidra geëxporteerd. De raw hit is dus geen bewijs voor een vergelijking met updatecommand A1. Nog geen bewezen ULC/A1-handler gevonden. Het [ontbrekende-HEX-pad aan WinCE-zijde](updater-recovery-contracts.md) blijft zonder vastgesteld MCU-effect. Geen installatiereparatie of firmwarepayload gewijzigd door dit onderzoek.

Reproduceerbaar:

```powershell
py tools/inspect_micom_flow.py
py tools/run_micom_ghidra.py --flow-expanded
py tools/run_micom_ghidra.py --flow-tables
py tools/inspect_micom_rx.py
```

Evidence: [uitgebreide graaf](firmware/flow-expanded/micom-cpu-candidates.json), [instructies](firmware/flow-expanded/rl78-flow.asm), [eerste lengtevergelijking](firmware/flow-expanded/decoder-comparison.json), [callbackgraaf](firmware/flow-tables/micom-cpu-candidates.json), [tweede lengtevergelijking](firmware/flow-tables/decoder-comparison.json), [ontvangstcontracten en bewijsbytes](firmware/micom-rx-contracts.json).
