# Acht Bluetooth-apparaten: deletefailure niet als geslaagde actie behandelen

Op 9 oktober 2026 is een **afzonderlijke interpretervariant** toegevoegd die het werkelijke verwijderresultaat tot de GUI-caller bewaart. De eerdere uitgesloten gezamenlijke Bluetoothfixture en H4-timeout-/powervervolg zijn niet uitgevoerd. Geen executable/LGU is geschreven en niets is op de unit gestart.

Uitvoeren in PowerShell: `$env:PYTHONPATH = 'tools/python-libs'; py tools/verify_bt_delete_status.py`. [Patchhelper](../tools/draft_bt_delete_status.py), [verifier](../tools/verify_bt_delete_status.py) en [evidence](firmware/bt-delete-status-draft/contracts.json) bevatten de gewijzigde instructies, oorspronkelijke bronbereiken, toolhashes en traces.

## Probleem en reparatie

De bestaande acht-record-/I/O-variant weigert een failed read of onvolledige write. Compactor `7aa40` verliest die status bij de stackcookiecall. Adres-delete `7ab4c` levert vervolgens geen bruikbare status aan GUI-delete `2ff30`. Die GUI-caller gaat ook bij een niet-uitgevoerde delete verder met profielafsluiting of SC-cancel, delete-pending en verbindingsstate elf. De nieuwe baselineparen reproduceren dat bij scan-/bulk-readfailure en korte writes.

De nieuwe compactor bewaart de bestaande recordverplaatsing: na de geselecteerde positie worden records tot het eerste lege adres of de acht-slotgrens doorgeschoven; de laatste overgebleven positie wordt gewist. De bank blijft 832 bytes en wordt vóór read volledig gewist. Ongeldige DWORD-indices worden vóór bank-I/O afgewezen. De write-BOOL wordt in een reeds opgeslagen register bewaard tot na de cookiecheck.

Zowel compactor als adres-delete geven de nieuwe BOOL in **`v1`** terug. De oorspronkelijke `v0`-uitkomst van de cookiecall blijft behouden voor overige callers, inclusief een caller die rechtstreeks terugkeert na delete. De verifier laat de cookiehelper `v0` en `v1` overschrijven en controleert afzonderlijk de behouden `v0` en herstelde `v1`. De adreshelper weigert ontbrekende adressen, scanfouten en indices buiten nul tot zeven voordat hij compacteert.

GUI-delete gebruikt `v1` en gaat bij nul rechtstreeks naar zijn oorspronkelijke epiloog. Daardoor veranderen in deze failuretraces de bestaande state en delete-pending niet; profiel-disconnect en de latere SC-cancel worden niet aangeroepen. Een geslaagde delete behoudt beide bestaande routes: gewone/inactieve selectie via SC-cancel en state elf; eerste actieve selectie via de bestaande profielafsluitcalls en delete-pending één. De profielhandler en CSR-queue zelf zijn hooks, geen volledig uitgevoerde radioprotocolpaden.

De bestaande stackframes, saved-registeropslag, cookieposities, epilogen, bestandlengte en `.pdata` blijven gelijk. De succesvolle GUI-selectiebranch voert de bestaande A2DP-indexread nu in zijn delay slot uit; bij failure wordt deze read overgeslagen. De overige acht directe adres-deletecallers blijven qua instructies ongewijzigd. Zij verwerken de nieuwe `v1` niet.

## Verificatie

| Controle | Cases |
| --- | ---: |
| Geldige compactie en adres-delete, ieder slot bij één tot acht records | 72 |
| Header/scan/bulk/open/seek en failed/short/zero/overreported writes | 152 |
| Ontbrekend adres bij één tot acht records | 8 |
| Ongeldige index acht/zestien/DWORD-high/max | 4 |
| GUI-delete voor iedere geldige selectie, met/zonder actieve profielen | 72 |
| GUI-failures voor alle acht selecties, met/zonder actieve profielen | 160 |
| Eerdere variant: ongewenste state-/cancel-/disconnectmutaties bij failure | 12 |
| **Totaal** | **480** |

De geldige traces controleren exacte volledige recordbytes, één write van 832 bytes en vrijgave van geopende handles. Volledige interpreted calls controleren stack en callee-saved registers. Bronbytes en tien oorspronkelijke directe delete-edges worden vastgelegd. De kandidaat-SHA-256 is `67cf826fe263b94d7d960a8404e2766ce75b5ccb5670114519b7340be558c064`.

## Grenzen

Een korte of mislukte write kan al bestandbytes veranderen. De nieuwe status voorkomt latere GUI-acties, maar **herstelt die bytes niet**. Atomische persistentie/stroomverliesherstel blijven open. De GUI-failure krijgt hier geen nieuwe error-notificatie en er is geen bewijs dat AppMain-progress zonder afzonderlijk timeoutpad wordt opgeruimd. Ook de andere deletecallers verwerken persistencefailure nog niet.

Dit blijft een aparte variant boven [de acht-recordopslag](bt-pairing-storage-draft.md), niet boven ACK/safe-copy/key-iterator/transport/playback. Geen nieuwe pairingpayload is vrijgegeven. Cache-aliases, snapshotgeneratie/locking, controller-/profielgedrag en native unitvalidatie blijven open; [releasevoorwaarden](release-requirements.md) gelden onverminderd.
