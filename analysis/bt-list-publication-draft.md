# Bluetooth-apparatenlijst: publicatie naar AppMain

`py tools/verify_bt_list_publication.py` koppelt twee byte-interpreters via een expliciete shared-memory- en berichtenfixture. De Blue-variant verwerkt een lijstaanvraag met de echte `2fec4`, database-readketen, `3307c`, recordopbouw `32f00`, gedeelde copy `344f4`/`34310` en verzendhelpers `337dc`/`33538`. AppMain verwerkt iedere succesvol afgeleverde fixturemelding met zijn echte `121630`, `110708` en shared-pointergetter. [Evidence](firmware/bt-list-publication-draft/contracts.json) bevat bronbereiken, hashes, patchhashes en traces.

Er is geen firmware natively uitgevoerd of executable/LGU geschreven. Bestands-API's, naamresolver/stringcopy, HWND-lookup, OS-transport en AppMain-redraw/getters/debug zijn hooks. De fixture voert AppMain uit tijdens de Blue-verzendhook; dit bewijst geen echte scheduler, timing, reentrancy of OS-aflevering.

## Bevestigde volgorde en capaciteit

De gewone `1010702`-receiver roept `2fec4` aan. Die roept eerst `3307c` aan met een nuladres: een databaseherlaad zonder optionele reorder. Per record bouwt `32f00` een record van 64 bytes met profielstatus, adres en naam. De aangepaste grens in `344f4` laat ook record acht door; `34310` kopieert op `(index-1)*64` in de gedeelde bank.

Na alle records zet de herlaad de countbytes en verstuurt `4010702`. De count staat zowel in de lage als hoge 16 bits van de berichtparameter. De buitenste `2fec4` verstuurt vervolgens dezelfde count nogmaals. Bij een geslaagde read komen dus twee lijstmeldingen na de recordcopies. Dit dubbele bericht is bestaand gedrag; de verifier verandert het niet.

36 traces controleren counts nul tot acht met alle vier combinaties van HFP/media-status. Adres, naam, recordvolgorde, count en gekopieerde AppMain-bank komen overeen. Voor een lege lijst wist de native AppMain-callback ook HFP-ready/connected, pogingstatus en actieve pointer. Bij de geldige records is alleen record **een** door Blue met de huidige HFP/media-status gemarkeerd. De eerder geteste willekeurige actieve AppMain-posities waren synthetische gedeelde banks; ze bewijzen niet dat Blue de actieve record op die posities publiceert.

## Geselecteerd apparaat naar de eerste record

36 extra traces voeren `3307c` met ieder bestaand adres uit bij counts één tot acht. Deze entry komt overeen met de reload/reorder-aanroep in het onderzochte HFP-succespad; de complete CSR-handler wordt niet uitgevoerd. `31c84` zoekt/verplaatst de databaserecord, de echte writeketen schrijft de acht-recordbank, waarna de native publicatiehelpers en AppMain-list-end de nieuwe volgorde volgen.

Het gekozen apparaat staat daarna vooraan; alle overige records behouden hun onderlinge volgorde en **alle 104 bytes per record**, inclusief sleutel-/payloadbytes. De gepubliceerde eerste record bevat het gekozen adres en de bijbehorende naam met HFP-active. AppMain selecteert index nul en de eerste shared-pointer. Daarmee is ook de keuze van apparaat acht gevolgd tot persistentie, gedeelde publicatie en actieve UI-record. Dit is een koppeling van het native reorderdeel; entryvoorwaarden, compleet HFP-succes, radio en scheduler blijven open.

24 extra traces injecteren drie bulkwritefouten voor ieder van de acht gekozen indices: API-BOOL false ondanks volledige transfer, een 831-byte partial write en false met nul bytes. De reload retourneert nul, publiceert geen records/notificatie en houdt shared-bank/count behouden. Het exacte reeds geschreven bestandprefix wordt gecontroleerd. Dit bevestigt ook de resterende beperking: de herkenning van writefailure herstelt een al gewijzigd bestand niet atomisch.

## Gerepareerd statusverlies bij herladen

De oorspronkelijke caller `2fec4` negeert de return van `3307c`, leest de bestaande count en verstuurt ook na reloadfailure `4010702`. Met een vooraf gevulde acht-recordbank/count krijgt AppMain dus een lijstmelding voor acht oude records. Zijn native callback kopieert die bytes en zet de lijst-ready-status.

De in-memory variant vervangt nu `2fee8..2ff1c` door een guard op de reloadstatus en behoudt beide countgettercalls en de geldige notificatie. Bij failure gaat hij naar de oorspronkelijke epiloog: geen countmelding, geen nieuwe AppMain-copy en geen fysieke disconnect door een verzonnen lege lijst. Countbytes en oude shared-bank blijven behouden. Het frame, de opgeslagen registers en `.pdata` blijven gelijk. De countgetter `3184c` is een oorspronkelijke leaf die alleen v0 wijzigt; deze concrete eigenschap wordt gebruikt om beide argumenten binnen het bestaande codebereik te zetten.

36 normale vóór/na-paren controleren counts nul tot acht en alle HFP/media-combinaties: uitkomsten en beide notificaties blijven gelijk. 36 failureparen controleren oude counts bij databases nul/vijf/acht, headerfailure, API-BOOL false met volledige bytecount, onvolledige bulkread en seek-failure, ieder met succesvolle notificatie, dubbele timeout of herstelde retry. De oude caller verstuurt een stalenotificatie; de variant verstuurt niets en behoudt shared-bank/count. Negen extra geldige transportcases maken samen 45 huidige fault-/transporttraces. Beide gevonden directe callers zijn gepind: GUI-lijstrequest op `30f9c` en factory-reset op `313bc`; de volledige factory-resetketen is hier niet uitgevoerd.

Dit repareert concreet statusverlies in de buitenste Blue-caller, los van de 300-ms Sleep in de HFP-callback. De foutproef begint bewust met oude count acht en een gemarkeerde bank; de unitfrequentie is niet gemeten. Een OS-aanvraag kan echter nog steeds succesvol terugkeren nadat de receiver intern geen lijst heeft vernieuwd. De HFP-callback kan daardoor alsnog na zijn Sleep oude shared-bytes kopiëren. Er is nog geen gekoppeld freshness-/herstelprotocol, receiver-LRESULT wordt niet als database-success doorgegeven en timeout kan levering niet uitsluiten.

De latere [IPC-roundtrip](bt-ipc-roundtrip-draft.md) volgt de echte constructorroute en Blue-WndProc plus de HFP-callback: een interne DB-failure kan nog OS/wrapper-succes en het oude phonebookpad geven. Snapshotfreshness, mislukte notificaties, gedeelde-bufferlifetime/locking, volledige CSR/HFP-entryvoorwaarden, atomisch schrijfherstel, indirecte naamcachelezers en radio-/unitgedrag blijven open. De huidige acht-slotvariant blijft buiten de updatebuilder.
