# GPIO: GPINTR naar NK/OAL en platformtabel

De IOCTL-tabel in NK bevat op **0x80101174** het 12-byte record `0x01032c87, 0, 0x80107424`. De laatste DWORD wijst naar de GPIO-handler **0x80107424–0x80107563**. Dat koppelt de directe GPINTR-exports aan uitvoerende kernelcode; de driverstreamstubs zijn een afzonderlijk pad.

[inspect_gpio_kernel.py](../tools/inspect_gpio_kernel.py) leest de bronbytes via de eerder onafhankelijk gevalideerde CER1-sectiemetadata. Dat is hier nodig: initialized data heeft een ander **realaddr** dan PE ImageBase+RVA, en NK heeft twee oorspronkelijke secties met dezelfde RVA. De tool gebruikt voor iedere read de juiste oorspronkelijke sectie, inclusief bewaarde shadowbytes wanneer nodig. Hij voert geen kernelcode uit. [JSON met hashes, records, handlerbytes en labels](firmware/gpio-kernel-contracts.json).

## Record en registers

Het inputrecord is 16 bytes: DWORD pin op +0, subcode op +4, configuratiewaarde op +8. De vierde DWORD op +0x0c wordt door deze handler niet gelezen. GPINTR-wrappers initialiseren deze vierde DWORD niet expliciet.

De globale pointer op **realaddr 0x8112b238** bevat **0xb0200000**, hier `B`. Binnen de gebruikelijke MIPS KSEG1-adresmapping correspondeert dat met fysiek 0x10200000; de statische registeroperaties gebruiken het ongecachete adres B. De handler berekent bank=`pin >> 5`, bit=`pin & 31`, mask=`1 << bit`.

| Subcode | Gevolgd gedrag | pdwActualOut |
| --- | --- | --- |
| `1` | output = `*(B + bank*4) & mask` | 4 |
| `2` | schrijft mask naar `B + 0x10 + bank*4` | 0 |
| `4` | schrijft mask naar `B + bank*4` | 0 |
| `0x10` | schrijft input+8 naar `B + 0x1000 + pin*4` | 0 |
| `0x20` | output = `*(B + 0xa0 + bank*4) & mask` | 4 |
| `8` en alle overige waarden | leest configuratie uit `B + 0x1000 + pin*4` | 4 |

Pinstate is een **gemaskeerde bitwaarde**, geen genormaliseerde BOOL en geen volledige bankwaarde. DRVMGR toetst daarna de betreffende bit opnieuw en maakt er 0/0xff van. Subcode 8 heeft geen eigen vergelijking in de kernelhandler: GPINTR_GetPinConfiguration gebruikt bewust het algemene read-fallbackpad. De fysische set/clear-betekenis van de bankwrites volgt nog niet alleen uit hun offset.

De handler controleert uitsluitend input != NULL en inputlengte >=16. Bij een mislukte inputcontrole retourneert hij alsnog 1 zonder iets uit te voeren. Op de uitvoerende paden zijn outputpointer, outputlengte, bytesReturned-pointer en pinbereik niet gecontroleerd. Het eindpunt retourneert altijd 1. De directe GPINTR-wrappers leveren een outputDWORD en bytesReturned-locatie voor readcalls. Dit toont het contract van deze onderzochte firmware, geen runtimebewijs dat iedere hogere caller deze velden geldig aanlevert.

## Platformtabel

**realaddr 0x8112b23c** bevat 43 records van 16 bytes, eindigend met pin 0xffffffff. Velden zijn pin, pointer naar UTF-16-label, enableflag en configuratie. De initializer **0x801075d4–0x80107817** schrijft configuratie naar `B+0x1000+pin*4` voor pin <128. Bij niet-nul enableflag schrijft hij mask naar `B+0x40+bank*4`. Die enableflag staat aan voor Tick, RTCMatch0 en DDMA.

Een selectie van de ROM-labels:

| Pins | Label | Initialisatieconfiguratie |
| --- | --- | --- |
| `0x54/55/56` | Tick / RTCMatch0 / RTCMatch1 | 0x6d / 0xe1 / 0xe1 |
| `0x4b` | DDMA | 0xa1 |
| `0x4e` | GPU | 0xa1 |
| `0x2c/2e/30/31` | PSC0 CLK / SYC0 / IRQ/DAT0 / DAT1 | 1 / 1 / 0xa1 / 1 |
| `0x4a/3c/3d` | PSC3 CLK / IRQ/DAT0 / DAT1 | 1 / 0xa1 / 2 |
| `0x5a/60/5b` | USB IRQ / CIM IRQ / LCD IRQ | 0xa1 |
| `0x11/12` | U1RXD/IRQ / U1TXD | 0xa1 / 1 |
| `0x1b/1c` | U3RXD/IRQ / U3TXD | 0xa1 / 1 |
| `0x19/1a` | U2RXD / U2TXD | 1 / 1 |
| `0x43/23` | GPIO TIRQ | 0xd0 |
| `0x45` | GPS TIMEPULSE | 0 |

De volledige tabel staat in JSON. De 43 records omvatten ook interne interruptbronnen; niet ieder label identificeert een externe connectorpin. Resetpins 0x0e/16/3e/3f komen niet als benoemde resetfuncties in deze tabel voor. De tabel bevestigt daarom geen veilige vervangende Bluetooth- of MICOM-resetselector. Het MGR-initpad stelt 0x45 opnieuw op configuratie 0 in, passend bij deze bootwaarde.

Bron: [NK-disassembly](disassembly/rom/nk.exe.asm), [GPINTR-disassembly](disassembly/rom/gpintr.dll.asm), [MGR-contracten](mgr-driver-contracts.md), [ROM-sectieverificatie](rom-verification.md).
