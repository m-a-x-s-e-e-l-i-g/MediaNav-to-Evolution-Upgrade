# MediaNav 4.1.0: referentie voor bestanden en mappen

Max levert op 9 oktober 2026 `C:/Users/maxom/Desktop/upgrade.lgu` aan als extra context: bewaren om bestandslocaties en versies te vergelijken, zonder reverse-engineering. De LGU-header bevat `*MEDIA-NAV*` en versie **4.1.0**.

Ook `Storage Card/System/Version_Info.txt` bevat exact `4.1.0`. Het pakket bevat **1.163 bestanden**: 1.044 onder Storage Card, 117 onder Storage Card4 en daarnaast booter_standalone.bin en firmware.hex. De bewaarde LGU is 69.792.744 bytes, SHA-256 `435776c3305b344431ad294c25edcb3ca23c70d033d6e18464e9fc1c2bab3f3c`.

Voorbeelden van concrete locaties binnen `upgrade/`:

| Bestand | Locatie |
| --- | --- |
| Blue.exe en AppMain.exe | Storage Card/System/ |
| NK.bin | Storage Card/ |
| LangDllFre.dll | Storage Card/System/data/ |
| nngnavi.exe | Storage Card4/NNG/ |

De exacte-padvergelijking met het 7.0.5.MD-hoofdpakket vindt 17 byte-identieke bestanden, 422 gewijzigde bestanden op hetzelfde pad, 724 paden uitsluitend in 4.1.0 en 1.478 uitsluitend in 7.0.5.MD. Dit zijn pakketverschillen; verplaatste bestanden worden hierbij als afzonderlijke paden geteld.

- Origineel: `C:/Users/maxom/Desktop/upgrade.lgu`, ongewijzigd.
- Bewaarde lokale kopie: [sources/reference-410/upgrade.lgu](../sources/reference-410/upgrade.lgu).
- Uitgepakte bestandsreferentie: `extracted/reference-410/upgrade/`.
- [Bestandsinventaris](reference-410/inventory.csv): paden, groottes en SHA-256.
- [Manifest en vergelijking met 7.0.5.MD](reference-410/manifest.json): identieke bytes, gewijzigde bestanden op hetzelfde pad en bestanden die maar in één pakket staan.
- [Reproduceerbare inventaristool](../tools/keep_reference_410.py).

De container en de afzonderlijke bestandslengtes/CRC's zijn gecontroleerd bij uitpakken. De tool bewaart ook welk payloadbereik de LGU-headerchecksum dekt. Het oorspronkelijke Desktop-bestand en de lokale kopie zijn na uitpakken opnieuw op SHA-256 gecontroleerd.

De vergelijking beschrijft wat **in deze updatepakketten** staat. Dat geeft geen volledige inventaris van een geïnstalleerde unit: bestaande bestanden kunnen door een update behouden blijven. Bestandsverschillen zeggen op zichzelf niets over gedrag of uitwisselbaarheid van executables.

Deze referentie is buiten de inputs van `corpus_catalog.py` gehouden. Geen firmware uitgevoerd, geen ROM uitgepakt, geen disassembly/decompilatie gestart en geen code naar BT8T01/BT8T02 of MAX02 overgenomen. Eventueel later codeonderzoek is een nieuwe, afzonderlijke opdracht.
