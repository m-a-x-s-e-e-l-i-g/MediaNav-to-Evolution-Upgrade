# MCU: van AA5 naar ULC en de programmeer-/resetroute

Dit is statische analyse van dezelfde firmwareimage, SHA256 `4c5a45266f11cbd2a408c3b9880008a819091e61c61a7283f51949244bd76512`. Exacte chip en geïnstalleerde unit-state zijn onbekend. Geen firmware is uitgevoerd en geen seriële verbinding geopend. De nieuwe graaf vult de [eerdere skip-/ontvangstanalyse](micom-mcu-flow-contracts.md) aan.

## Initial RAM en callbackkandidaten

De opstartlus `3f6–409` kopieert ROM `[6ec2,758e)` naar RAM `[fe3d2,fea9e)`: 1.740 bytes, hash `49843f25f724283b843eddafc067c2a6e2e58f8d81eb95302f63a0137464e186`. ES wordt nul voor de ROM-read; de ongeprefixte destination gebruikt de kandidaat-F-segmentmapping.

Daarmee worden indirecte objectcalls herleidbaar naar **beginwaarden**, zonder actuele RAM te reconstrueren. Voorbeeld: RAM `fe400` krijgt `e83a` uit ROM `6ef0`. Objectveld `0` correspondeert met ROM `732a: c9 90 01 00`, kandidaatfunctie `190c9`; veld `8` met `7332: 8c 91 01 00`, kandidaatfunctie `1918c`.

`inspect_micom_startup.py` volgt expliciete rechte loadreeksen naar CS/lowword en een afzonderlijk timerpatroon. `7dea` geeft het in AX/C opgebouwde callbackadres door aan `7cd9`; die bewaart het lage woord op timerrecord `+a` en hoge byte op `+c`. `7eb6` gebruikt precies die velden voor `CALL DE`. De timerstructuur heeft 32 records van 14 bytes vanaf `fe420`; scheduler `7ef3` gebruikt tijdverschil en interval voordat hij de callback probeert.

Na acht rondes zonder nieuwe gematchte roots: 106 objectcallbindings, 59 expliciete timerregistraties, 85 roots, **33.084 instructiekandidaten / 65.209 bytes**. Geen overlap. 321 grenzen blijven open, waaronder indirecte calls, externe adressen en de FF-trap. Beginwaarden bewijzen geen callbackselectie of onveranderlijke pointers op de unit. De matcher behandelt complexe stack-/scratchreeksen niet als opgelost.

Ghidra bevestigt 33.083 kandidaat-instructielengtes; `283: ff` ontbreekt in zijn export. De brondecoder noemt FF `brk1`; dat is geen aangetoonde hardware-instructienaam. De [78K0R/KE3-hardwarehandleiding, hoofdstuk 18](https://www.renesas.com/en/document/mah/78k0rke3-users-manual) beschrijft FF-uitvoering als oorzaak van een interne illegal-instruction-reset. Dit maakt een resetintentie aannemelijk; het identificeert onze chip niet. Het gat wordt bewaard, niet als reguliere instructie aan Ghidra opgedrongen.

## Ringconsumer en dispatcher

Consumer `1527c–1540f` vergelijkt headerproducer `+3c` en consumer `+3a`. Bij gelijkheid retourneert hij nul. Anders kopieert hij route/command/lengte naar callerrecord offsets `0/1/2`, leest de payload via contextpointer `+240` en schrijft naar de callerpayloadpointer op `+4`. Payloadpointerwrap gebeurt bij `+23e`; headerconsumptie schuift zes bytes op en wrapt bij `+38`. Retourwaarde wordt één. Dit onderbouwt de eerder als kandidaat beschreven producer-/consumerrollen.

Timercallback `155f0` initialiseert beide contexts bij zijn eerste stap. Daarna gebruikt hij `1527c` voor ingang nul en één. De eerste ingang wordt opgedeeld in manager-highnibble en typebits. Bit `8` leidt naar de algemene vervolgtak; lage drie bits selecteren:

| Type | Objectveld | Callsite | Vervolg |
| --- | --- | --- | --- |
| 1 | `c` | `15695` | Commandobyte als argument, payloadpointer op stack; A6 alleen bij bepaalde returnwaarden |
| 2 | `18` | `156bf` | Command/payload; vervolgens A6 |
| 5 | `14` | `156f1` | 32-bit adres uit payload; antwoord via AA/type D |
| 6 | `10` | `1573b` | 32-bit adres, payload vanaf +4; vervolgens A6 |

Het object wordt geselecteerd via `e400 + manager*2`. De code doet dat met `X=0`, manager in A, `SHRW AX,7`, dan `ADDW AX,e400`. Dit is geen koppeling met CmnDll-routing-ID's.

## Concreet updatecontrolframe

WinCE stuurt `aa110500be`: manager 1, type 1, command 5, nul payload. De MCU-dispatcher selecteert dan:

1. RAM-global `fe402`, initial value `e6fe` uit ROM `6ef2`.
2. Objectveld `c`: RAM `fe70a`, initializer-ROM `71fa: 1c 61 01 00`.
3. Kandidaathandler `1611c`; de acht-bit subtract/skip-keten selecteert voor command 5 tak `16682`.
4. Twee indirecte servicecalls, daarna directe call `166a6 → 1993`.

Dit is een concrete statische keten naar de updater, onder de initializer-/ISA-aanname. Type-1-handler `1611c` is daarom als extra root opgenomen in een afzonderlijke updategraaf: **34.669 instructiekandidaten / 68.175 bytes**. Ghidra bevestigt 34.668 lengtes, met opnieuw alleen FF bij `283` niet geëxporteerd. Geen overlaps; 368 expliciete open grenzen. De bredere handler-/hardwaresemantiek is niet volledig gevolgd.

## ULC aan MCU-zijde

`1993` leest eerst byte `3f400` en kan vooraf helper `135b` aanroepen. De [markeranalyse](micom-flash-marker-contracts.md) volgt dit als erase van blok 253 bij een niet-FF-byte, met een genegeerd wisresultaat, en verbindt de marker met normale opstartcommands. Volledige power-/recoverybetekenis blijft open. Daarna wordt `1873` aangeroepen, dat interrupts uitschakelt en naar de eerste AB-statuszender springt.

Ontvanger `1890` herkent **55,4c,43** met drie afzonderlijke vergelijkingen bij `18c6/18d3/18e6`. Daarom was een zoekactie naar een aaneengesloten ASCII-literal ULC onvoldoende. Daarna leest hij exact `403` bytes: control, tag, 1024 payloadbytes en checksum. Hij pollt dezelfde kandidaat-UART als de normale index-0-interrupt; de ontvangstwachtroute voedt de watchdog via `fffab=ac`.

`1993` telt `402` ontvangen bytes op modulo 256 en vergelijkt de laatste byte. Dat sluit aan bij de [WinCE-ULC-zender](micom-update-transport.md), die de prefix niet meetelt.

| MCU-routine | Uitvoer naar kandidaat-UART TX-register `fff44` |
| --- | --- |
| `183a` | `AB 20` |
| `184d` | `AB 21` bij checksumafwijking |
| `1860` | `AB 22` bij mislukte programmeerwrapper |

De MCU-code ondersteunt daarmee de eerder gevonden Windows-fout: de ontvangende thread laat de tweede AB-byte vallen, terwijl `OnRequest` aparte retrytakken voor 21/22 heeft. Een simpele statuspatch moet ook de eerder beschreven retry-afwijking na bronblok 7 oplossen; anders wordt een al bestaande verkeerde blokselectie bereikbaar.

## A1 en A4 gaan door de programmeerwrapper

Na een geldige checksum roept `1993` wrapper `191f` aan met tag, payloadpointer, lengte `400`, aanvullende nulwaarde en `control & f`. Die wrapper bouwt een request en roept `14f5` aan. Daar worden programmeerhelpers en status-/retryloops aangeroepen voordat op requestveld `+8` wordt vertakt.

Bij vlag 1 is het gevolgde pad na een succesvolle status `17ba → CALL 283`, waar byte FF staat. Vlag 4 volgt `17de → CALL 284`; bij nulresultaat volgt eveneens `CALL 283`. Wrapper `191f` heeft bovendien een zelflus bij `1988` voor vlag 1/4 indien controle daar nog terugkeert. Een gewone terugkeer/succesreply na deze eindframes mag niet worden aangenomen.

Het ontbrekende-HEX-frame aan Windows-zijde is A1/tag8 met 1024 nulbytes. De MCU-ontvanger behandelt dat als een valide ULC-blok met vlag 1 en geeft de nulbytes aan dezelfde programmeerroutine door. **Er is geen aangetoonde reboot-only bypass vóór die routine.** Dat bewijst geen succesvolle fysieke flashwrite: blokkoppeling, beschermde/inactieve bootregio's, programmeerstatussen en flash-/swaphelpers moeten nog worden gevolgd. Ook de werkelijke reset moet op de geïdentificeerde chip/unit worden vastgesteld.

De kleinere apps-payload en losse navfix blijven daarom ongevalideerd wat betreft dit MCU-pad. Deze analyse verandert geen uitvoerbaar bestand of updatepakket.

De [flashlibrary-vervolganalyse](micom-flash-library-contracts.md) koppelt tags aan logische adressen met tag × 1024, onderzoekt de Fx3-bootvensters en decodeert de 61-byte RAM-template. De lokale chunkcapaciteit is 256 bytes; het capaciteitswoord en de initbuffer hebben verschillende adressen. Hidden chip-ROM, exacte bootflagfunctie en fysieke unitmapping blijven onbekend. De eerdere open blokmapping hieronder wordt daarmee gedeeltelijk ingevuld, geen fysieke flashwrite bewezen.

## Evidence en vervolg

`inspect_micom_startup.py` bewaart de initializer, negen bootpreimages, kandidaatbindings met byte-evidence en alle closure-rondes. Alle 106 objectbindings worden aanvullend gecontroleerd op de aaneengesloten highbyte/CS/lowword-load en op behoud van het callregister tijdens argumentvoorbereiding. `inspect_micom_flash_rx.py` bewaart acht oorspronkelijke codebereiken en 23 preimages. De code wordt gelezen; native wachtroutes, interrupts en programmeerhelpers worden niet uitgevoerd.

Vervolg: betekenis van `da/de/e2/351`, tag-/blokmapping en boot-/swaphelpers `283/284/2e1`; inhoudelijke programmeerstatus en protected-regiongedrag; ringcollision/interruptownership en alle niet-gematchte dispatchers. De aanwezige pakketten blijven geen volledige dump van de unit.

```powershell
py tools/inspect_micom_startup.py
py tools/run_micom_ghidra.py --flow-startup
py tools/inspect_micom_flash_rx.py
py tools/run_micom_ghidra.py --flow-update
```

Evidence: [startupbindings](firmware/flow-startup/micom-cpu-candidates.json), [startupvergelijking](firmware/flow-startup/decoder-comparison.json), [updateketen en bytes](firmware/flow-update/micom-cpu-candidates.json), [update-instructies](firmware/flow-update/rl78-flow.asm), [updatevergelijking](firmware/flow-update/decoder-comparison.json).
