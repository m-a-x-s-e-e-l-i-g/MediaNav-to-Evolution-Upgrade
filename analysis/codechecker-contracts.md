# CodeChecker: radiocode, pogingteller en IPC

CodeChecker.exe is de viercijferige radiocode-interface in 7.0.5.MD. Zijn hoofdpad gebruikt eigen CGUI-klassen en Windows CE GDI, een venster van 800×480, taalresources en registrywaarden. De update-MD5/Synctool-route is een ander programma. Er is geen werkelijke unitcode gelezen, ingevoerd of gewijzigd.

## Start en invoer

`0x1b758` controleert een vaste commandoregelprefix die ook de MicomManager-launcher gebruikt, registreert de vensterklasse en draait de message loop. `0x1b2dc` gebruikt een named mutex `CodeChecker.exe` om dubbele uitvoering te beperken. MicomManager `0x1df38` zet zijn lockveld, actualiseert de power/audio-interface en start deze executable tenzij het productpilotveld actief is.

Initialisatie `0x1aa64` maakt vier lege WCHAR-posities, nulled de vier-byte vergelijkingsbuffer en vraagt HKLM/LGE/SystemInfo/F_CODE. De echte call op `0x1ab34–0x1ab3c` geeft **zes argumenten**: buffer als vijfde stackargument en lengte **4** als zesde. Ghidra toont de zesde lengte niet in zijn gegenereerde signatuur. De return van de registryread wordt door deze initialisatie niet getoetst.

De keypad `0x1ab54` accepteert maximaal vier cijfers; IDs `0x3e9–0x3f2` zijn 1–9 en 0, `0x3f3` is wissen en 1000 is bevestigen. Bevestigen doet pas iets bij exact vier WCHARs. Zij vergelijkt iedere WCHAR met één byte uit de vier-byte registrybuffer. Dit is een directe bytevergelijking; er is geen MD5 of afleiding uit een serienummer in deze routine. `0x1a69c` toont iedere gevulde positie als een ster.

Bij overeenkomst wordt de pogingteller in RAM op nul gezet. Met FACTORY_TYPE != 0 volgt een bericht naar AppMain `0x83e9 / 0x10001` en sluit de interface. Met FACTORY_TYPE == 0 verschijnt de Code OK-dialoog. Bij verschil stijgt de teller, wordt de invoer gewist en kiest het programma een normale of factory-resultaatdialoog.

## Persistente pogingteller

`Antitheft.cfg` bevat één little-endian DWORD. `0x18c3c` leest vier bytes; ontbrekend of kort bestand wordt nul. De waarde wordt signed gelezen, negatieve waarden worden nul en waarden boven acht worden acht. `0x18b8c` schrijft vier bytes in wb-modus; fwrite/fclose-resultaten worden niet inhoudelijk bevestigd. Dit bestand bevat in het gevolgde pad de teller, niet de vier invoercijfers.

Bij WM_DESTROY schrijft CodeChecker de teller en post naar MGRMCM:

```text
message = 0x8064
wParam  = 0xb40300
lParam  = (in-memory attempt counter == 0)
```

De vaste tekst `Current Authkey : 0000` wordt in `0x1a7dc` in een lokale string geformatteerd; dit bewijst geen daadwerkelijke unitcode en wordt in deze functie niet naar een zichtbaar label gekopieerd.

## Twee verschillende wachtroutes

Het programmacontextveld FACTORY_TYPE komt uit de registry. Bij een normale verkeerde invoer krijgt de resultaatdialoog status 0: Incorrect code en een 5000-ms sluit-/resultaattimer. Factory-verkeerde invoer krijgt status 2 en activeert de onderstaande tabel. Bij factory-start met een bewaarde positieve teller roept een 50-ms timer de dialoog met status 4 aan; die status start het wachten zonder de teller opnieuw te schrijven.

| Teller | Factory-dialoog, seconden | MicomManager-antithefttimer, seconden |
| ---: | ---: | ---: |
| 0 | 0 | 60 |
| 1 | 60 | 120 |
| 2 | 120 | 120 |
| 3 | 120 | 120 |
| 4 | 120 | 240 |
| 5 | 240 | 480 |
| 6 | 480 | 960 |
| 7 | 960 | 1920 |
| 8 | 1920 | 1920 |

Factory-dialoog `0x1995c` gebruikt de negen DWORDs op `0x25a58`. Een teller >= 9 kiest entry 8. Timer `0x19da0` verlaagt de resterende seconden en sluit de dialoog bij de eindwaarde. De dialoogtimer is niet dezelfde timer als MicomManager.

MicomManager `0x1dfc4` leest dezelfde Antitheft.cfg maar controleert hier niet expliciet dat ReadFile vier bytes leverde. Deze functie selecteert 60 s voor teller 0, 120 s voor 1–3, 240/480/960 s voor 4/5/6 en 1920 s voor overige waarden. Zij stuurt audio-/MICOM-commando's en zet venstertimer **2**. Bij timer 2 wist WndProc het runningveld en roept `0x1e5cc → 0x1df38` aan om de code-interface weer te openen. Dit verklaart waarom de tabel in CodeChecker alleen niet alle wachttijden van de unit voorspelt.

MicomManager behandelt IPC-commando `0xb4` in `0x23308`: de waarde beïnvloedt het lockveld, power-/weergavestatus en kan het antitheftwachtpad activeren. De verdere audiofocus- en MCU-beveiligingssemantiek blijven aparte onderzoeksdelen. CodeChecker-venster sluiten is daarom niet zelfstandig bewijs dat de hele unit ontgrendeld is.

## Reproduceerbare evidence

[inspect_codechecker.py](../tools/inspect_codechecker.py) bewaart de ruwe functieranges en wachttabel in [codechecker-contracts.json](firmware/codechecker-contracts.json). Met `--counter <lokale kopie>` leest het uitsluitend het tellerbestand; het vraagt geen registrywaarde op en opent geen device. Synthetische tellerchecks dekken korte data, negatieve waarden, normale waarden en clamp boven acht.

Bronhash: `3746a195cb1a0121fdf55359b0c36672d07735b9bff793c7635342b1a13d1e6a`. [Assembly](disassembly/CodeChecker.exe.asm), [pseudocode](decompiled/705md/CodeChecker.exe/decompiled.c). Open: volledige widget-/resourcelifecycle, provisioning van F_CODE vanuit MICOM en gedrag bij afwijkende registrydata op de fysieke unit.
