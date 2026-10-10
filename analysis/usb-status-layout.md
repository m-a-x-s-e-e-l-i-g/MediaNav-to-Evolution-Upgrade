# USB-statusgeheugen in 7.0.5.MD

De [nieuwste menufix](usb-option-snapshot-development.md) kopieert repeat en shuffle samen: exact acht bytes vanaf `0xe42`. De opties worden na unlock uit die private kopie afgeleid. Zo is de hieronder beschreven herhaalde-menu-readfout gerepareerd in development; de oude scalar-audit blijft het bewijs van het oorspronkelijke probleem. Andere directe scalarlezers en producerlocalmetadataopbouw blijven afzonderlijke scope.

De [vervolgontwikkeling](usb-snapshot-copy-development.md) maakt de beveiligde titel-/statuskopie efficiënter. De [scalarreaderaudit](firmware/usb-scalar-readers-audit.json) onderzoekt zes directe afspeelstatuslezers plus repeat/shuffle. Geldige enkele enums blijven binnen hun bereik bij de geteste merge-load-interleavings. De menu-update leest repeat viermaal en shuffle tweemaal; een publicatie tussendoor kan tegenstrijdige selecties opleveren. Deze specifieke menufout is nog niet gerepareerd. De onderstaande oorspronkelijke readeraudit hoort bij de oudere startup-failure-bytes; titel-/hoesconsumers zijn inmiddels wel aangepast.

Nieuwste implementatie: [USB-tekst en hoesconsumers](usb-status-consumers-development.md) behoudt startupfailure handling en alle 1.918 vorige files/fixes. Titel-/artiestconsumers gebruiken begrensde lokale snapshots; publicatie en coverinstall/delete/acquire/paint delen een namedmutex. Onderstaande ABI blijft gelijk; andere directe scalarlezers en lokale metadataopbouw zijn nog niet globaal gesynchroniseerd. Native CE/GDI/loaderwerking blijft te testen.

Mapping `ShmFmMgrUsbAppMain`, grootte **0xe56 = 3.670 bytes**. Statische reconstructie; nog geen live snapshot van de unit.

MgrUSB publiceert bytes uit `CPlayControl + 0x1ad8`: `makeSongInfo`, VA `0x1b8b8–0x1b8c8`, geeft die pointer met offset 0 en lengte `0xe56` door aan `0x24094`. Die wrapper roept `CSharedMem::write` op `0x23c44` aan. Dat kopieert naar de mappingpointer op objectoffset +8. MgrUSB heeft zijn eigen ingebouwde IPC/shared-memorycode en importeert hiervoor niet CmnDll.

| Mappingoffset | Bytes | Veld | Evidence in MgrUSB |
| --- | ---: | --- | --- |
| `0x0000` | 1 | Huidige minuut | `0x198b0 / 0x198b8` |
| `0x0001` | 1 | Huidige seconde | `0x198cc` |
| `0x0002` | 1 | Huidig uur | `0x198a4 / 0x198b4` |
| `0x0003` | 1 | Totale minuut | `0x19830 / 0x19838` |
| `0x0004` | 1 | Totale seconde | `0x1984c` |
| `0x0005` | 1 | Totaal uur | `0x19824 / 0x19834` |
| `0x0006` | 520 | Onbekende regio, gereserveerd als tekstslot in voorlopige parser | Semantiek open |
| `0x020e` | 520 | Titel, UTF-16LE-buffer | `0x19e14`, track-name-log en ID3-kopie |
| `0x0416` | 520 | Artiest, UTF-16LE-buffer | `0x19e3c`, `No Artist`-fallback `0x1a060–0x1a070` |
| `0x061e` | 520 | Album, UTF-16LE-buffer | `0x19e28`, `No Album`-fallback `0x1a004–0x1a014` |
| `0x0826` | 520 | Onbekende regio, gereserveerd als tekstslot in voorlopige parser | Semantiek open |
| `0x0a2e` | 520 | Pad/bovenliggende map, UTF-16LE-buffer | `0x1b848–0x1b870`; exacte padnormalisatie nog uitwerken |
| `0x0c36` | 520 | Bestandsnaam, UTF-16LE-buffer | `0x1b830–0x1b83c` |
| `0x0e3e` | 4 | Afspeelitem-index | `0x19d20–0x19d24` |
| `0x0e42` | 4 | Repeatwaarde: 0 off, 1 track, 2 map, 3 alles | `0x1b568`; [auto-next-branches](usb-playlist-contracts.md) |
| `0x0e46` | 4 | Shufflewaarde | `0x19ae0–0x19af4`, schrijft 0 of 1 |
| `0x0e4a` | 4 | Afspeelstatus | `0x1ae68–0x1ae74` |
| `0x0e4e` | 4 | Cover-HBITMAP | `0x19520–0x19538` leest veld en roept `DeleteObject` aan |
| `0x0e52` | 4 | Onbekend laatste woord | Gebruik nog volgen |

De vijf bewezen tekstbuffers hebben 260 WCHAR-posities. Twee extra regio's van dezelfde grootte zijn nog niet als daadwerkelijk gebruikte tekstvelden bewezen. Dat verklaart de grotere structuur zonder hun betekenis te verzinnen.

De tijdcode deelt het aantal seconden door 60 en splitst uur/minuut/seconde. De DWORD-velden staan op oneven alignment ten opzichte van vier-bytegrenzen en worden met MIPS `lwl/lwr` en `swl/swr` gelezen en geschreven. Een native C-struct moet daarom packed zijn; een gewone uitgelijnde struct verschuift de velden.

AppMain leest onder andere titel op `0x1df28`, artiest op `0x4dd7c`, status op `0x4cfac` en coverhandle op `0x4e268` met dezelfde mappingoffsets. Daarmee zijn zowel de schrijvers als verschillende lezers teruggevonden. Het HBITMAP-veld bevat een GDI-handle, geen PNG-bytes; overname tussen processen moet afzonderlijk worden onderzocht.

De [vijf-case readeraudit](firmware/usb-status-reader-audit.json) interpreteert de echte titelscan `1df10..1df4c`, packed handleload `4e268..4e274` en widgethelper `138d60..138e90` op de startup-failure-development-01-bytes. Een 260-WCHAR-titel zonder terminator loopt door in het artiestvak. Een gesimuleerde publicatie tussen LWL en LWR mengt handles `12340001` en `56780002` tot `12340002`. De widgethelper bewaart de borrowed handle op `+3c` en dupliceert deze daar niet. Het interleaving en GetObject zijn fixtures; native scheduling/bitmaplifetime niet bewezen. Nog geen snapshot-/lockingfix.

De [offline parser](../tools/parse_usb_status.py) bewaart onbekende velden expliciet en stuurt geen opdrachten. Gebruik uitsluitend met een dump van exact 3.670 bytes:

```powershell
py tools/parse_usb_status.py pad/naar/usb-status-dump.bin
```

De parser is met een synthetische fixture gecontroleerd op UTF-16-grenzen, little-endian DWORDs en packed offsets. Dat verifieert de parser, niet de werkelijke runtimebetekenis van alle velden.
