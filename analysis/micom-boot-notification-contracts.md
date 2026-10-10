# MICOM: bootnotification en veranderende dispatch

Vervolg op de [flashmarker](micom-flash-marker-contracts.md). De oorspronkelijke MCU-image blijft gepind op SHA256 `4c5a45266f11cbd2a408c3b9880008a819091e61c61a7283f51949244bd76512`; CE `MicomManager.exe` op `c56e8e08600cd69a656ec487779d3dbb0cea672ae2c5cb2da685b9217e6f8824`. Geen firmware uitgevoerd, seriële verbinding geopend of updatepakket gewijzigd.

## Eén controlveld, twee functies

Manager 1 gebruikt het object uit RAM-global `fe402`, initial pointer `e6fe`. Veld **18** ligt op RAM **fe716**, segmentbyte op **fe718**. Initializer-ROM **7206** bevat `b7 72 01 00`: doel **172b7**.

Vier gevolgde codeplaatsen schrijven dit veld expliciet. De exacte encodings voor deze pointer-/segmentstores zijn over de hele beschikbare image gezocht en komen uitsluitend op deze vier plaatsen voor. Andere store-encodings en indirecte writes zijn daarmee niet uitgeput.

| Codeplaats | Context | Doel |
| --- | --- | --- |
| 15ea3–15ea9 | Init-tak van 15e92, selector 1 | 172b7 |
| 15f26–15f2c | Andere tak van 15e92 | 172b7 |
| 166ff–16705 | Manager 1/command FE | 172b7 |
| 165c0–165c6 | Later pad van manager 1/command 0 | 17316 |

`172b7` handelt een klein bereik van selectors af door een andere objectactie aan te vragen en/of terug te geven of statebyte **fe1ea == 3**. Hij bouwt geen bootnotification. De in een initializer gevonden functionpointer is dus geen vaste definitie van de latere controle-route.

`15c96` zet fe1ea op 3 en registreert de gewone RX-dispatcher `155f0` met intervalargument 1000. De andere tak van `15e92` zet state eerst op 6, annuleert meerdere timers en kan uiteindelijk state 0 zetten. Command FE zet eveneens state 0 na zijn gevolgde cleanup. De volledige fysieke betekenis van deze states en poorten is nog niet gereconstrueerd.

## Command 0 na de markerwrite

De eerder gevolgde normale CE-opstarttimer stuurt manager 1/type 1/command 0. De MCU-route kan eerst de marker schrijven, vervolgens aanvullende config-/initstappen doorlopen, bit **fe1eb.0** zetten en het controlveld op **17316** zetten.

Daarna roept `165ca–165da` dat controlveld aan met selector **0** en pointer **e6f4** op de stack. Het oude `172b7` en het nieuwe `17316` hebben dus verschillende gevolgen voor dezelfde selector.

`17316` verlangt **fe1ea == 3**. Bij een andere state retourneert hij BC=0 zonder notification op te bouwen. Voor selector 0 kiest `173bf` replylengte **2**. De gemeenschappelijke staart `174ae–174c4` geeft manager **1**, type **2**, commando **0**, payloadpointer en lengte door aan framebuilder `154b7`.

De bootnotification bevat daarmee twee bytes uit **fe6f4/fe6f5**, in dezelfde volgorde als een little-endian WORD. Voor het expliciete offline fixturewoord `0017` is het frame:

```text
aa 12 00 02 17 00 ad
   │  │  │ └───┘ └ XOR
   │  │  └ lengte 2
   │  └ command 0
   └ manager 1, type 2
```

`0017` is een fixture, geen waargenomen apparaatstatus. De maker van het statuswoord en zijn velden zijn maar deels gevolgd. Het markerwrite-resultaat wordt niet in deze gevolgde notificatieketen opgenomen; de verloren flashstatus uit de [markeranalyse](micom-flash-marker-contracts.md) wordt hiermee niet alsnog bevestigd.

## Wanneer stopt Windows CE met wachten?

`CMicom::OnCommand`, functie **21748**, accepteert de gevolgde type-2/command-0-notification voor bootinitialisatie alleen wanneer CE-objectveld **+24 == 0**. Bij een andere waarde verlaat deze tak de functie. Dit veld wordt later voor verschillende power-/appstates gebruikt; nul is hier de geobserveerde initvoorwaarde.

De aanroep op **21d60** gaat naar **1f444**. De eerste relevante instructies daar lezen een WORD op packetoffset **+4**, bewaren het op **this+84**, wissen timerstate **this+38** en roepen **3006c** aan om de timer te stoppen. Daarna volgen propertyreads, configuratie en verdere applicatieinitialisatie. Die grote body is niet volledig handmatig gereconstrueerd.

De timer stopt dus op een ontvangen bootstatuspacket, vóór aanvullende propertyreads en zonder flashmarkerreadback op dit gevolgde pad. Een succesvolle bootnotification of gestopte opstarttimer mag niet als bewijs gelden dat de markerwrite, volledige update of navigatiecontent geslaagd is.

## Verificatie en resterend werk

`inspect_micom_boot_notifications.py` bewaart zeven oorspronkelijke MCU-codebereiken, de initializerbinding, vier rebinds en begrensde CE-codebereiken. MIPS-preimages bevestigen de status-WORD-load, timerstateclear en beide calls. Ghidra bevestigt alle **507 instructielengtes**, zonder afwijkende of ontbrekende grenzen. Het WORD-/XOR-model controleert alle **65.536** waarden; zeven framefixtures worden aanvullend door de afzonderlijke lokale captureparser gelezen. Dit zijn arithmetic-/framingchecks, geen unitobservaties; gelijke instructielengtes bewijzen geen volledige semantiek of chipidentiteit.

```powershell
py tools/inspect_micom_boot_notifications.py
py tools/run_micom_ghidra.py --boot-notifications
```

Evidence: [contracten en bytes](firmware/boot-notifications/contracts.json), [MCU-instructies](firmware/boot-notifications/boot-paths.asm), [decodervergelijking](firmware/boot-notifications/decoder-comparison.json).

Open: complete status-WORD-productie en powerstates; overige dynamische writes/aliases; ontvangst-/lengtevoorwaarden boven deze CE-tak; native configuratieinitialisatie en notificaties naar andere managers. De beschikbare image is geen actuele RAM-/flashdump.
