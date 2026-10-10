# MediaNav 7.0.5.MD — updater, ROM en communicatie

Onderzocht op 8 oktober 2026. Dit vervolg op [de eerste inventarisatie](findings.md) gebruikt de ongewijzigde updatebestanden uit de repository. Hieronder betekent **bevestigd**: teruggevonden in deze binaries en handmatig gevolgd in de disassembly. Er is geen runtime-test op de unit uitgevoerd en geen firmware gewijzigd.

## Hoofd-update en corruption-fix kunnen waarschijnlijk één pakket vormen

De hoofd-update mist `Storage Card4/NNG/nngnavi.exe`; de aparte fix levert precies dat bestand. De installatiecode ondersteunt juist expliciet een navigatiebestand naast de overige updatebestanden:

- `UpgradeManager.exe`, VA `0x15054–0x15084`: controleert `\Storage Card3\upgrade\Storage Card4\NNG\nngnavi.exe` en verwijdert bij aanwezigheid de bestaande `\Storage Card4\NNG\nngnavi.exe`.
- De recursieve overdracht van de payload gebruikt `CopyFileW` gevolgd door `DeleteFileW` in de routine rond `0x18698`.
- Ook de oudere 4.0.6-updater bevat de staged- en doelpaden voor dit navigatiebestand, rond `0x14c4c` en `0x14c5c`.

Dit maakt samenvoegen technisch aannemelijk: er is een installatiepad voor beide payloads. Het verklaart niet waarom de maker twee pakketten publiceerde. Een daadwerkelijk gecombineerd LGU is nog niet gebouwd of geïnstalleerd; pakketacceptatie, volgorde en gedrag op de huidige unit zijn daarmee nog niet bewezen.

**Een concrete zwakte in de updater:** op `0x18870` wordt `CopyFileW` aangeroepen. Daarna volgt op `0x18880` direct `DeleteFileW` voor het staged-bronbestand, zonder controle van het kopieerresultaat in `$v0`. Als die kopie faalt, probeert deze code toch de bron te verwijderen. Bovendien kan het bestaande navigatiebestand al eerder zijn verwijderd. Dit is een aantoonbaar verbeterpunt voor installatiebetrouwbaarheid, maar nog geen verklaring voor een daadwerkelijk waargenomen navigatiefout.

Evidence: [7.0.5.MD-updater](disassembly/UpgradeManager.exe.asm) en [4.0.6-updater](disassembly/remove-md/UpgradeManager.exe.asm). De adressen in dit rapport zijn PE-VA's, geen NAND-adressen of bestandsoffsets.

## Wat de corruption-fix werkelijk doet is nog niet bewezen

Het meegeleverde `nngnavi.exe` meldt bestands- en productversie **9.4.6.398870** van NNG. Dit is de navigatieappversie; het betekent niet dat de gehele MediaNav versie 9.4.6 draait.

De UTF-16-foutmelding `File corruption detected, Navigation stops.` staat op bestandsoffset `0x937e90`, VA `0x948c90`. Er bestaat ook code die dit adres gebruikt:

1. Aanroep van een controlefunctie op `0x4f8ea0`, doel `0x4fae54`.
2. Bij een niet-nulresultaat wordt het foutpad overgeslagen op `0x4f8ea8`.
3. Het andere pad laadt de melding op `0x4f8ec0` en doet twee volgende aanroepen.

De controlefunctie bevat substantiële code; zij is geen eenvoudige constante-returnstub. De betekenis van alle interne controles is nog niet gereconstrueerd. Het bestaan van dit pad bewijst niet dat het bereikbaar is met de huidige data, maar wel dat we niet kunnen stellen dat alle corruptiecontroles zijn verwijderd.

Voor de exacte patch is een **ongewijzigd origineel van dezelfde navigatieversie** nodig. Alleen het bestand uit de fix is nu beschikbaar. Een andere appversie levert een veel bredere diff en bewijst de fix niet.

Evidence: [versie, hash en adressen](navigation-fix.json), [foutpad](disassembly/nngnavi-error-xrefs.asm).

**Vervolg:** de normale nulreturn blijkt een lege geaccepteerde kaartenlijst te betekenen. De scan-/cache-/formaat-/distributorketen en de bestaande specifieke foutmeldingen zijn inmiddels gevolgd in [navigation-content-contracts.md](navigation-content-contracts.md). Een [gecombineerde lokale kandidaat](review-update-contracts.md) is gebouwd en volledig uitgepakt en vergeleken; unitinstallatie blijft ongeverifieerd.

## ROM, registry en eerste opstartstappen

`NK.bin` is nu uitgepakt met [extract-wince-rom](https://github.com/gweslab/extract-wince-rom), in `--fs=raw --sections=full`-modus. De exacte tool- en decompressorcommits staan in [provenance.json](provenance.json). Er zijn **164 ROM-modules en 49 overige bestanden**, inclusief de bootregistry.

Eigen verificatie leest de oorspronkelijke B000FF-records en ROM-tabellen opnieuw. Alle 114 recordchecksums zijn geldig. De modulelijst en aantallen zijn gecontroleerd; **265 ongecomprimeerde PE-secties komen byte voor byte overeen met de bronbytes**. De aanvullende [ROM-byteverificatie](rom-verification.md) bevestigt inmiddels ook 287 gecomprimeerde secties, vier gedeelde-RVA-records en alle 49 losse ROM-files. De [FDF-analyse](boot-registry.md) valideert alle records en corrigeert verkeerd gerootte HKCR/HKCU-sleutels in de externe tekstexport. Gebruik de aparte gevalideerde registry-export.

De bootregistry bevat onder `HKLM\init` onder andere `device.dll`, `gwes.dll`, `ULC_launcher.exe`, `servicesStart.exe` en `jacminit.exe`. `ULC_launcher.exe` start na afhankelijkheden 20 en 30:

```text
CE init → ULC_launcher.exe → dboot.exe → UpgradeManager.exe
                          ↘ UpgradeManager.exe als dboot ontbreekt
```

De launcher wacht begrensd op `\Storage Card\System\dboot.exe`. DBOOT heeft een aparte `StartWinCE`-route; zonder die marker roept het de updater aan. Het schema beschrijft deze aangetroffen startpaden, niet iedere herstel- of desktoproute.

De ROM bevat onder meer `TouchI2C.dll`, `ddi_au13xxlcd.dll`, `i2cbus.dll` en de I2S-audiodrivers. AU1300/MALI-verwijzingen geven een buildtarget, geen bevestiging van de exact geïnstalleerde CPU of RAM.

`firmware.hex` is geldige Intel HEX: alle 16.470 recordchecksums kloppen; het bevat 262.144 unieke databytes op adressen `0x0–0x3ffff`. `MicomManager.exe` verwijst in zijn updatepad naar het staged-bestand, rond `0x23b80`. Het is daarmee gekoppeld aan de MICOM-updater; de precieze chip en compatibiliteit zijn nog niet vastgesteld.

Evidence: [ROM-verificatie](705md-rom-verification.json), [HEX-verificatie](705md-firmware-hex.json), [launcher](disassembly/ULC_launcher.exe.asm), [DBOOT](disassembly/dboot.exe.asm), [MICOM-manager](disassembly/MicomManager.exe.asm). Uitgepakte ROM en registry staan lokaal onder `extracted/705md-rom/`.

## IPC uit de echte CmnDll.dll

De DLL heeft een tabel van 42 logische doelen. De tabel gebruikt UTF-16-namen met een stride van 32 bytes, RVA `0x7144`; de handlecache staat op RVA `0x7d50`. Voor dit onderzoek zijn onder andere `AppMain = 21`, `MgrUsb = 5`, `MgrBt = 11`, `MgrHf = 12` en `MgrMcm = 3` relevant. Dit zijn logische routing-ID's, geen Windows-proces-ID's.

De doelhandle wordt via `FindWindowW` gevonden en gecachet. `IpcGetProcessHandle` retourneert een **pointer naar de handlecache-entry**, niet rechtstreeks de HWND.

De verzendargumenten zijn `src, dst, cmd, size, payloadPointer`. Voor kleine berichten:

```text
message = 0x8064
wParam  = (cmd << 16) | (src << 8) | (size & 0xff)
lParam  = maximaal 4 bytes payload als één woord
```

`IpcPostMsg` gebruikt `PostMessageW`. Bij een te grote payload logt het een fout en kopieert toch de eerste vier bytes; het behoudt daarbij de opgegeven grootte in de berichtcodering. Dit is geen nette afwijzing. `IpcSendMsg` gebruikt voor grootte tot vier bytes dezelfde codering, en voor grotere payloads `WM_COPYDATA` met een `COPYDATASTRUCT`. De metadata daarvan bevat `(cmd << 16) | (0x8000 + src*100 + dst)`. De send-timeout is 2.500 ms.

**Belangrijk ABI-detail:** `IpcGetMsg` verwacht als vierde argument het **adres van de lParam-variabele**. AppMain slaat die variabele op `0x170cc` op en geeft het adres door op `0x170e4`. Bij kleine berichten wordt dat adres de payloadpointer; bij `WM_COPYDATA` dereferentieert de DLL het eerst tot de pointer naar `COPYDATASTRUCT`. Daarmee klopt de extra pointerlaag aan de ontvangende kant. De externe 9.1.3-header declareert hier een lParam-waarde en kan dus niet rechtstreeks worden overgenomen.

De output gebruikt offsets `+0` voor source, `+4` voor command, `+8` voor grootte en `+0xc` voor payloadpointer. Source en command worden met 16-bit stores geschreven; initialisatie van de overige bytes en levensduur van de payloadpointer moeten bij een toekomstige testapp worden meegenomen. Er zijn nog geen berichten naar de unit gestuurd.

Evidence: [CmnDll-disassembly](disassembly/CmnDll.dll.asm), [AppMain-disassembly](disassembly/AppMain.exe.asm), [routingtabel en callsites](705md-ipc.json). De `CmnDLL.cpp` in MediaNavMods bevat stubs, geen implementatie die deze firmware kan vervangen.

## USB-commando's bevestigd aan beide kanten

De volgende commando's zijn teruggevonden in AppMain-aanroepen met doel 5 én in de AppMain-dispatcher van `MgrUSB.exe`. De tabelbasis van die dispatcher is VA `0x21dd4`.

| Commando | Betekenis | Payloadbytes | Voorbeeld AppMain-VA | MgrUSB-case-VA |
| ---: | --- | ---: | --- | --- |
| 100 | Vorige track | 0 | `0x11dec` | `0x22024` |
| 101 | Volgende track | 0 | `0x12010` | `0x21fdc` |
| 106 | Shuffle | 4 | `0x4fc90` | `0x2206c` |
| 107 | Repeat | 4 | `0x4fa68` | `0x220b4` |
| 108 | Afspeelstatus wijzigen | 4 | `0x119c8` | `0x220fc` |

Interne berichten van MgrUSB gebruiken deels andere ID's; bovenstaande tabel geldt specifiek voor de route **AppMain → MgrUSB**. De exacte waarden voor alle shuffle-, repeat- en afspeelmodi worden nog uitgewerkt.

De manager maakt een statusmapping `ShmFmMgrUsbAppMain` met grootte **3.670 bytes (`0xe56`)**, zichtbaar op `0x248e8`. De packed statusstructuur uit de 9.1.3-referentie is 2.630 bytes. Dezelfde naam betekent dus niet dat veldposities en buffers identiek zijn. Het blok kan aanvullende velden of andere buffergroottes bevatten; dat moet worden afgeleid uit de lezende en schrijvende code.

## Volgende onderzoek

De beste volgende stap voor een eigen interface is de USB-statusmapping reconstrueren: vind de schrijvers voor tracktitel, artiest, positie, duur en afspeelstatus en vergelijk die met AppMain-lezers. Daarna volgt dezelfde analyse voor Bluetooth/audio. Zo kunnen bestaande diensten behouden blijven terwijl de interface verbetert.

Voor de navigatiefix blijft de ontbrekende originele executable het noodzakelijke vergelijkingsmateriaal. Voor een gecombineerd updatepakket is het installatiepad nu gevonden; betrouwbaarheid van kopiëren en herstel verdient afzonderlijke aandacht voordat het op de unit wordt gebruikt.

De nieuwe eigen scripts zijn [disassemble_mips.py](../tools/disassemble_mips.py) en [research_baseline.py](../tools/research_baseline.py). De disassembler annoteert lokale constanten en importaanroepen; die kandidaten zijn zoekhulp, geen volledige control-flowanalyse. Handmatig bevestigde conclusies staan hierboven. Geen native firmwarecode is uitgevoerd.
