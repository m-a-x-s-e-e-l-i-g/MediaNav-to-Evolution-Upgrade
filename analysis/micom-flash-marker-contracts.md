# MICOM: flashmarker op 3f400

Statische analyse van de oorspronkelijke MCU-image met SHA256 `4c5a45266f11cbd2a408c3b9880008a819091e61c61a7283f51949244bd76512`. Geen MCU-code uitgevoerd of flash benaderd. Deze MCU-marker is onderscheiden van de Windows CE-stagingmarkers. Een verband met de navigatiecorruptiemelding is niet aangetoond.

## Update-entry en normale toestand

ULC-entry `1993` leest bij `199e` één byte op `ES=3:f400`. Als deze byte niet `FF` is, vraagt `19af–19b5` helper `135b` om het blok op adres `3f400` te wissen. Deze helper rekent adres >> 10 en komt uit op blok **253 / FD**. Direct na de call volgt `19b9: CALL 1873`: de caller test het teruggegeven wisresultaat niet. Het updatepad kan dus doorgaan nadat een init-/wisfout is teruggegeven. De hele opgeslagen referentie-image heeft hier een FF-blok; dat bewijst geen actuele apparaatinhoud.

Initialisatie `190c9`, selector 1, wist RAM-bit `fe830.7`. Alleen als flashbyte `3f400 == FF` is, zet `19154–1915b` dat bit opnieuw. Ze registreert callback `18bd0` met intervalargument **30000**. De tijdseenheid is hier niet vastgesteld.

Callback `18bd0` stopt bij een bepaalde poortbittoestand. Anders leest hij dezelfde flashbyte. Bij `FF` verhoogt hij een objectteller en laat de timer doorgaan zolang de teller kleiner dan zes is. Een andere bytewaarde of het bereiken van zes leidt naar een indirecte actie via het initiële object uit `fe400`, veld `+c`, met AX=1 en stackwoord 0. Het initializerdoel is `19193`, selector 1; de fysieke betekenis van deze actie is nog niet benoemd. De callback wist daarna timer-ID `fe835` en retourneert BC=0.

## Schrijven via parameter FE

De aparte commandhandler **`19474`**, selector **6**, annuleert de timer en leest `3f400`. Bij byte `00` slaat hij de write over. Bij iedere andere byte schrijft hij een lokale payloadbyte `00`, wist alvast `fe830.7` en vraagt via het object uit `fe41e`, veld `+10`, een write aan met **32-bit parameter FE, lengte 1**.

De initializer legt `fe41e=e9ac` vast. Het vierbyte-functieveld ligt op ROM-offset `74ac` en bevat **`67 e8 01 00`**, dus doel **`1e867`**. De segmentbyte 01 is essentieel; `e867` is andere code. Dit is een initializerbinding, geen actuele RAM-observatie.

`1e867` verlangt een nul hoogwoord en dispatcht met een keten van subtract/skip/branch-instructies. De gereconstrueerde tabel bevat 39 selectorwaarden. FE bereikt **`1ed78`**; FF bereikt de aparte route `1ed9b`. De FE-route neemt de oorspronkelijke payloadpointer en lengte over, kiest tag **FD**, flags **0** en roept `191f` aan. Die bouwt een request voor programmeerwrapper `14f5`.

Daarmee volgt de markerwrite dezelfde [flashlibrary-route](micom-flash-library-contracts.md): **FD × 1024 = 3f400**. Lengte 1 levert een vierbyte-uitgelijnde chunk **`00 ff ff ff`**. Blankcheck/erase/write/verify en hidden chip-ROM kunnen de operatie nog afwijzen; dit is geen waargenomen fysieke write.

De parameterdienst verwerkt het succesresultaat van `191f`, maar de aanroepende commandhandler doet dat niet: na `196a0: CALL DE` volgen stackcleanup en **`196a4: ONEW BC`**. Hij retourneert dus 1 onafhankelijk van dit schrijfresultaat. Ook het RAM-bit is al gewist voordat het resultaat bekend is. Bij een mislukte write kunnen RAM-status en flashbyte daardoor uiteenlopen. De betekenis van status 1 voor bovenliggende callers en hun eventuele readback blijven open.

| Flashbyte | ULC vraagt erase aan | Command 6 vraagt write aan | Init zet bit 7 | Timer gebruikt teller |
| --- | --- | --- | --- | --- |
| FF | Nee | Ja | Ja | Ja |
| 00 | Ja | Nee | Nee | Nee |
| Andere waarde | Ja | Ja | Nee | Nee |

## Wie vraagt deze write en erase aan?

De [normale MCU-dispatcher](micom-mcu-update-chain.md) kiest object `fe400` voor manager 0 en `fe402` voor manager 1. De manager-1-commandhandler `1611c` heeft een acht-bit dispatchketen die bij FC begint en via FF naar 00 wrapt. De gereconstrueerde tabel bevat 19 selectors; **00 → 164c7, 07 → 163c6, FD → 168f9**.

Windows CE `MicomManager.exe`, timerfunctie `23fb8`, stuurt in timerstatus **5** manager 1/type 1/commando 0 zonder payload (`241ec–24210`). Timerstatus 6 kiest daarna status 5 met interval **1000**. Dit levert het offline frame `aa 11 00 00 bb`; er is geen capture of verzending uitgevoerd.

MCU-command 0 zet bit `fe1eb.3` en test bit `fe1eb.0`. Bij bit 0 clear roept `164ea–164fe` object `fe400`, veld `18`, aan met selector **6**: de markerwrite. Daarna volgen andere init-/configstappen. Verderop kan de code bit 0 zetten (`165bc`); de volgende command-0-aanroep kan dan de markerwrite overslaan. Het schrijfresultaat wordt ook hier niet gecontroleerd. Command **FD** roept dezelfde selector 6 rechtstreeks aan en negeert eveneens diens resultaat.

Dit ondersteunt de interpretatie **opstartstatusmarker**, maar bewijst geen volledige hardware-/recoverybetekenis. Ook de functievelden veranderen: `165c0–165c6` vervangt het manager-1-controlveld `fe716/fe718` door doel `17316`. Initializerbindings gelden daarom niet als onveranderlijke runtime-dispatch.

Command **7** geeft zijn payload door aan object `fe400`, schrijfveld `10`, met propertyadres **42**. De initializer kiest `19269`; property 42 bereikt `1934b`. Die zet `fe830.7` volgens payloadbit 0. Is het bit set, dan vraagt hij via object `fe41e`, veld `c`, selector **2**, met byte **FD**, een erase aan.

Dit tweede initializerdoel is **`1e7ca`**. Selector 2 bereikt `1e840`, rekent FD << 10 en roept `135b` voor `3f400` aan. Hij negeert het wisresultaat en retourneert de eerder ingestelde waarde **1**. De RAM-flag is al gezet vóór de erase. Bij een teruggegeven wisfout kunnen RAM en flash dus ook in deze richting verschillen. `19372` roept daarna de toestandsroutine `18e0e` aan. Volledige poort-/powersemantiek daarvan blijft open.

## A6 bevestigt geen geslaagde flashoperatie

MCU-helper `154a0` bouwt één byte **A6** voor de normale TX-route. Na **type 2** (`156bf → 156c2`) en **type 6** (`1573b → 1573f`) roept de dispatcher deze helper aan zonder het handlerresultaat te testen. Dit geldt voor handlers die terugkeren; een reset, eindeloze wachtroute of TX-fout bewijst geen ontvangen A6.

Bij type 1 gebruikt de dispatcher retourbyte C: waarden **0 en 1** bereiken eveneens A6. De manager-1-handler retourneert aan het normale eind BC=1, ook na de gevolgde markerroute. Alleen een betere statusreturn in de onderliggende helper maakt deze keten dus nog niet betrouwbaar.

Aan CE-zijde signaleert ontvangthread **`25cac`** bij A6 het event op `CCmd+0xc`. `SendWriteCmd` **`14db0`** en `SendCommandEx` **`15158`** geven succes terug als de eventwait voltooit. A6 bevat geen commando-identiteit of flashstatus. De oorspronkelijke bytes van deze drie functies en de command-0-call zijn apart bewaard met de gepinde executablehash.

Hetzelfde event wordt gesignaleerd bij een AA/type-D-readreply. `SendReadCmd` controleert na de wait geen manager-/commando-identiteit en kopieert de aanwezige cachelengte. Een late A6 of een verkeerd gekoppeld type-D-antwoord kan daarom niet op basis van dit event van de bedoelde response worden onderscheiden. Dat is een protocolbeperking; een actuele late-responsefout is niet waargenomen.

## De bestaande getter is geen volledige markerreadback

Object `fe400`, leesveld `14`, kiest initializerfunctie `1938a`. Property **42 → 19406** schrijft RAM-bit `fe830.7` naar de aangeboden payloadpointer, maar verandert de standaard retourlengte 0 niet. Dispatcher `156c8` gebruikt deze retourbyte als replylengte voor `154b7`. De statische keten levert daarom een **lege type-D-reply**, waarna CE `SendReadCmd` nul bytes teruggeeft. Dit leest bovendien een RAM-bit, geen actuele flashbyte.

Voor een echt herstelcontract is dus aanvullende flashreadback nodig, naast herstel van statuspropagatie. Een willekeurige A6 en deze bestaande propertygetter zijn daarvoor onvoldoende.

## Herleidbare controle

`inspect_micom_flash_marker.py` pint de volledige imagehash, bewaart 17 oorspronkelijke codebereiken en controleert concrete indirecte bindings en callargumenten. Hij extraheert 39 parameterselectors, 19 manager-1-commands en negen getter-/acht settercases uit begrensde dispatchreeksen. Hij projecteert de vier byte-afhankelijke beslissingen voor alle 256 waarden en bouwt zes expliciet als offline gelabelde AA-framefixtures. Oorspronkelijke CE-instructies zijn met executablehash en MIPS-preimages vastgelegd. Ghidra bevestigt alle **1.324 instructielengtes**, zonder afwijkende of ontbrekende grenzen. De modellen voeren geen MCU-code, chip-ROM of geheugentransacties uit; gelijke instructielengtes bewijzen geen volledige semantiek of exacte chip.

```powershell
py tools/inspect_micom_flash_marker.py
py tools/run_micom_ghidra.py --flash-marker
```

Evidence: [contracten en bytes](firmware/flash-marker/contracts.json), [originele instructies](firmware/flash-marker/marker-paths.asm), [onafhankelijke decodervergelijking](firmware/flash-marker/decoder-comparison.json). De [bootnotification-vervolganalyse](micom-boot-notification-contracts.md) volgt vier expliciete controlfieldwissels en de twee-byte reply die de CE-opstarttimer stopt. Vervolg: volledige toestands-/poortsemantiek, overige dynamische writes, aanvullende readbackroutes en een coherent protocol voor inhoudelijk installatiesucces.
