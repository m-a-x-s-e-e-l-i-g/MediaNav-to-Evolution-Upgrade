# Bluetoothmuziek herstellen bij een mislukte eerste audiostart

Max meldt een zeldzaam echt probleem: direct na automatisch verbinden loopt het nummer op de telefoon door, maar blijft de MediaNav stil. Herverbinden of herstarten helpt. De [gerichte audit](bt-connected-no-audio.md) reproduceert een passend softwarefoutpad: een mislukte audio-opening wordt lokaal toch als gestart behandeld. De concrete oorzaak op zijn unit is nog niet vastgesteld.

De reparatie staat in [complete development-02](../build/bt-startup-audio-development-02/README.md). Dit is de nieuwe ontwikkelbasis, met alle 1.918 bestanden en vorige verbeteringen. Alleen Blue.exe verandert; AppMain en de overige 1.917 bestanden blijven exact gelijk. Geen LGU, versieaanpassing, release of GitHub-publicatie.

## Wat verandert

- Een mislukte `CreateThread` krijgt één herpoging na 25 ms. Er bestaat dan nog geen worker; een aanwezige worker blokkeert nieuwe allocatie.
- Een geweigerde `waveOutOpen` krijgt één herpoging na 25 ms, met dezelfde afspeelthread, thread-ID en PCM-instellingen. Alleen een nulhandle laat de herpoging toe. Een onverwacht aanwezige handle na de wachttijd wordt behouden.
- Na maximaal twee pogingen per API stopt die opening. Blijvende fouten, een ontbrekende thread-ID, een mislukte semaphorecall of gedeeltelijke headerpreparatie worden niet als gereed behandeld.
- Een ontbrekende of onvolledig geopende audio-uitgang geeft bij starten nu nul terug. `FiltersRun(START)` zet de betreffende filter alleen na succes op gestart. Een mislukte PCM-reconfiguratie wordt ook doorgegeven.
- De oorspronkelijke Bluetooth-/bronkeuze, binnenkomende startrespons en AppMain-notificaties blijven gelijk. Die beschrijven de stream/bronintentie; daadwerkelijke lokale gereedheid zit in de WinPlay- en filterstatus. Gesprekken, pairings en playcommando's worden niet automatisch opnieuw gestart.

Een normale geslaagde opening krijgt geen extra Sleep. Beide tijdelijke fouten samen kunnen twee nominale Sleeps van 25 ms toevoegen. Dit is geen deadline voor de volledige functie: de bestaande API-wachttijden blijven bestaan. De wave-herpoging houdt de bestaande semaphore vast en geeft die na de laatste poging éénmaal vrij; er komt geen nieuwe algemene retryloop bij.

## Eigenaarschap en foutgrenzen

Een blijvende audio-openfailure kan zijn ene reeds gemaakte worker behouden voor de bestaande Close-route. Een volgende Open mag die worker niet overschrijven of een tweede maken. Een onduidelijke API-failure met niet-nul wavehandle en gedeeltelijk voorbereide output behouden hun handles; er wordt geen automatische close/open-keten toegevoegd. Hierdoor kan een fout geen toestemming geven om mogelijk nog gebruikte driverdata te vervangen.

De bestaande Close-/threadtermination-foutafhandeling, `waveOutPause`-foutafhandeling, callbackgeneraties en globale concurrency blijven buiten deze reparatie. De gekoppelde herstelproeven bieden succesvolle cleanup als expliciete fixture aan. Native driverownership en scheduling zijn nog niet getest.

## Lokale controles

[Development-02-evidence](firmware/bt-startup-audio-development-v2.json) en het [manifest](../build/bt-startup-audio-development-02/manifest.json) pinnen bestanden, tools, voorafgaande manifest/proof en de actieve editrecipe.

- **42 nieuwe reeksen** controleren echte native-instructies van StartInd/StartCfm, filterdispatch, Open/Start/Close en PCM-verwerking: normale start, tijdelijke/blijvende thread- en wavefouten, onduidelijke handles, gedeeltelijke voorbereiding, latere heropening en een bewust niet-geselecteerde bron. Eén- en drie-filterketens worden gevolgd; SBC/sink-lifecyclecallbacks zijn fixtures.
- **96 eerdere herpogings-/gereedheidschecks** worden via exacte code-identiteit en de gehashte development-01-proof behouden. Dit omvat alle 25 prepare-failureposities, formats, semaphorefouten, nulargumenten/eigenaarschap, PlayReq en PCM-reconfiguratie. De 16 oude handlercases met de vervangen routingverwachting zijn uitgesloten; handlers worden nieuw gecontroleerd.
- **Zes behouden playbackscenario's**, met 64 pakketten en 221.184 exact vergeleken outputbytes, slagen: twee-blokstart, restartfailureherstel, wachtrijlimiet, dubbele callbacks en stop/start. De bestaande audiodelay-/PCM-/callbackcode blijft byte-identiek.
- **824 bestaande pairing/delete/GUI/ACK/HFP/copy-checks** slagen opnieuw op de daadwerkelijk geschreven Blue/AppMain-combinatie.
- PE-headers, secties, imports, niet-textdata, oorspronkelijke stackframes/prologen/epilogen en `.pdata` blijven behouden. Iedere invocation controleert stack/callee-saved-registers; hooks overschrijven caller-saved-registers. De actieve editrecipe draait exact terug naar de voorafgaande USB-option-Blue. De oorspronkelijke directe controlflow bevat geen externe ingang naar vervangen binnenbereiken; indirecte verwijzingen en native loaderwerking blijven onbewezen.

Dit zijn begrensde MIPS-interpreterproeven. OS/thread/semaphore/driver- en phone-delivery-uitkomsten zijn fixtures. Ze tonen herstel van het geïnjecteerde foutpad; ze bewijzen geen herstel van Max' fysieke incident of native timings.

## Artefacten

| Bestand | Bytes | SHA-256 |
| --- | ---: | --- |
| [Blue.exe](../build/bt-startup-audio-development-02/payload/upgrade/Storage%20Card/System/Blue.exe) | 1.149.952 | `2b1eb3adee76a7867d1fd9d0a6c376f41d2b7a42cf4b54834e9ebc153854ed51` |
| AppMain.exe, behouden | 2.010.112 | `53dad71c39ec89fcc3cda17825eb48b8ce67b23563ab50c51f9fb77279acb835` |
| MgrUSB.exe, behouden | 249.344 | `cac3d40f5d54de681b1aad8c99fe79df5b430d3ee3d668616b63970f02ca1a2c` |

De actieve vier editspans liggen binnen bestaande Blue-functies: Open `266c4..26a64`, Start `26c78..26d14`, Start-return `26d20`, en FiltersRun-START `25db8..25e04`. Geen nieuwe uitvoerbare sectie, heapallocatie of import. De Open-body gebruikt de bestaande 0x58-byte frame en dezelfde 25 headers/640.000-byte PCM-pool. HI/LO-instructies hebben expliciete afstandslots; native uitvoering is niet gemeten.

Development-01 blijft als afgerond bewijs bewaard en is **vervangen door development-02**. De eerste kandidaat zette bij een lokale startfailure ook een bronroutingvlag nul. Een extra gekoppelde proef toonde dat een latere geslaagde heropening dan nog stil kon blijven. Development-02 herstelt daarom de oorspronkelijke volledige StartInd-handler. De herpoging en correcte lokale gereedheidsstatus blijven behouden; de before/after-reeks staat in de nieuwe proof.

De eerder uitgesloten brede controller-/power-/timeoutonderzoeken zijn niet hervat. De publieke MAX03-LGU en guide blijven ongewijzigd. Alle releases blijven volledige opvolgers; deze lokale staging is geen patch-LGU of nieuwe release.
