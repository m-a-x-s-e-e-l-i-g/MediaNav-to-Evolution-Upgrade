# BT8T01: uitvoerbare acht-apparaten-testset

Op 9 oktober 2026 vraagt Max expliciet om nieuwe executables om op de unit te testen. Daarom zijn nu **Blue.exe en AppMain.exe als bij elkaar horende testset geschreven**, plus originele pakketkopieën, instructies, manifest en offline traces. Dit is een experimentele applicatiebuild; native unitwerking is nog niet getest.

[ZIP](../build/bt-eight-test-BT8T01.zip), [Blue.exe](../build/bt-eight-test-BT8T01/Test/Blue.exe), [AppMain.exe](../build/bt-eight-test-BT8T01/Test/AppMain.exe), [instructies](../build/bt-eight-test-BT8T01/READ-ME-FIRST.txt), [manifest](../build/bt-eight-test-BT8T01/manifest.json). Reproduceerbaar met [builder](../tools/build_bt_eight_test.py); een afgeronde genummerde build wordt nooit overschreven.

## Inhoud en samenstelling

Blue gebruikt de bestaande acht-record-/I/O-basis, count-ACK en de [nieuwe delete-statusguard](bt-delete-status-draft.md). Iedere volledige deletepatch-preimage moet nog identiek aanwezig zijn in de ACK-variant; conflicterende wijzigingen worden geweigerd. AppMain gebruikt de bijbehorende ACK-/[safe-copyvariant](bt-safe-copy-draft.md), met acht raw records en twee pagina's. Bestaande connect-/reconnectguards uit die basis blijven aanwezig.

Deze build bevat geen extra iterator-/transportcleanup-, H4-, playbackbuffer- of navigatiepatch. Version_Info, OS, bootloader en MICOM veranderen niet. De eerdere volledige controller/cache/scheduler/playback-integratie en H4-timeout-/poweronderzoek blijven overgeslagen. De gerichte bestand-/paarcontroles zijn wel uitgevoerd om de nu expliciet gevraagde executables te controleren. Oudere `build_allowed=false`-velden beschrijven de afzonderlijke historische proeven; het nieuwe manifest legt de daadwerkelijke testbuild vast.

| Bestand | Bytes | SHA-256 |
| --- | ---: | --- |
| Test/Blue.exe | 1.149.952 | `fc7b8a01d087a7cf583e7c105b745f32bfe3d37f97a9b6810029ad7fef69524d` |
| Test/AppMain.exe | 1.756.160 | `0c35803e2cd3ad28aa4c0cb21de76f9d9dd62e88eda9dbb534bd0adcaa848845` |
| ZIP | Zie lokaal bestand | `a6b60af387d04aee84babfac6a34ef24758768ef212a40413c78b107271ff73c` |

De PE-headers, sectie-indeling en alle niet-`.text`-secties, inclusief `.pdata`, zijn byte-identiek aan de oorspronkelijke executables. Blue verandert 1.498 bestandbytes, AppMain 1.578. De bronbestanden zijn na de build opnieuw bytegewijs vergeleken en ongewijzigd. De ZIP is teruggelezen; ieder member is exact gelijk aan het lokale bestand.

## Gerichte controle van de geschreven bestanden

Alle onderstaande traces interpreteren bytes die opnieuw uit **Test/Blue.exe en Test/AppMain.exe** zijn gelezen, dus niet alleen de losse prototypevarianten.

| Controle | Cases |
| --- | ---: |
| Geldige compactie/adres-delete | 72 |
| Delete-helperfailure | 152 |
| Geldige GUI-delete | 72 |
| GUI-deletefailure, inclusief actieve profielen | 160 |
| Gekoppelde list-ACK/HFP voor nul tot acht records en transportretry | 222 |
| Gekoppelde DB/listfailure | 8 |
| NULL-lijst bij HFP-consumer | 18 |
| Begrensde raw-recordcopy | 48 |
| Beide UI-pagina's, connect-/deleteklik voor iedere selectie | 72 |
| **Totaal** | **824** |

De fixtureketen controleert echte instructies, records, adressen, namen, frames en registers. Bestands-API's, widgets, telefoonboekfile-open, profieldisconnect en CSR-queue blijven expliciete hooks. Er is geen native CE-, radio-, controller- of voertuigtest uitgevoerd.

## Gebruik en terugzetten

Gebruik beide Test-executables samen op de bestaande locaties `\Storage Card\System\Blue.exe` en `\Storage Card\System\AppMain.exe`. De bijgevoegde instructies beschrijven backup, vervangen met gestopte applicaties, bekende normale herstart, fysieke testvolgorde en terugzetten. Er is geen installer, launcher, LGU of autorun gemaakt en geen unit benaderd. De oorspronkelijke startup/singleton-/CE-terugkeerroute is nog niet zelfstandig op de unit bewezen.

De Original-map bevat ongewijzigde **7.0.5.MD-pakketbestanden**, geen actuele unitbackup. Bewaar beide huidige unit-executables en de pre-test `\Storage Card2\DATA\BLUE\sc_db.db`; terugkeer naar oude vijf-slotcode kan anders testkoppelingen verliezen. De backup vormt geen boot/flash/MCU-herstelbewijs.

Partial-writeherstel, snapshot/cache/lifetimevragen, AppMain-deletefailurefeedback en native profielgedrag blijven open. Deze concrete testset maakt hardwaretests mogelijk; zij voltooit de [releasevoorwaarden](release-requirements.md) nog niet.
