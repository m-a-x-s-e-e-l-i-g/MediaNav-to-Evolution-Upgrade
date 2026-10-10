# Display-escapes: navigatie en camera tegenover de ROM-driver

De handler **`ddi_au13xxlcd.dll!0xc08dd640–0xc08de153`** koppelt de eerder gevonden RVC- en glnavi-escapes aan registerbewerkingen. De driver mapt fysieke basis **`0x15000000`, lengte `0x900`**, met MmMapIoSpace. Dat is een firmwareconstante, geen onafhankelijke identificatie van de fysieke SoC.

De gevalideerde HKLM-defaultregistry beschrijft vier windows onder `Drivers\Display\AU13XXLCD\Windows`: Desktop index 0, MAE index 1, OpenGL/3d index 2 en DirectDraw index 3. Desktop gebruikt Pipe 1, de overige Pipe 0. RVC geeft in de gevolgde calls index **3** door. De actuele unitregistry kan die configuratie veranderen.

## Escapes aan beide kanten

`B` hieronder is de gemapte registerbasis; `i` is de eerste DWORD van de inputbuffer. De velden zijn registerwaarden, geen stabiele publieke SDK-structuur.

| Escape | Minimale/vereiste input | Gevolgd gedrag |
| --- | --- | --- |
| `0x229c44` | Exact 4 bytes: index | Zet bit `(index & 31)` in `B+0x24`; voor index 2 eerst de OpenGL-vrijgaveflag controleren |
| `0x229c48` | Exact 4 bytes: index | Wist dat enable-bit |
| `0x229c4c` | Minimaal 32 bytes | Schrijft DWORDs +4/+8/+c/+10 naar windowregisters; kan topbits van input-DWORD +8 aanpassen |
| `0x229c50` | Minimaal 32 bytes | Wist vier configuratieregisters van window `i` |
| `0x229c74` | Minimaal 32 bytes | DWORD +14 bit 0: lees vier registers terug; anders controleer geometrie/stride/scalers en schrijf ze |
| `0x229c78` | Minimaal 12 bytes | Schrijft input-DWORD +8 naar één van twee bufferadresregisters en wisselt de selectiestatus |
| `0x229c7c` | Exact 4 bytes: flag | Zet een boolean op driverobjectoffset `0x6adc`, intern `m_bOGL_Activate` genoemd |

Registeradressen per window: `B+0x100+i*0x20`, `+0x104+i*0x20`, `+0x108+i*0x20`, `+0x114+i*0x20`. De alternatieve bufferadressen staan op `+0x10c/+0x110+i*0x20`. Bij `0x229c78` kiest bit 1 van het statusregister welk adres wordt geschreven; daarna wordt het statusregister op 0 of 1 gezet. De tweede input-DWORD wordt in deze handler niet gebruikt.

Voor `0x229c74` interpreteert de setter input +4 bits 21..31 als x-orig en bits 10..20 als y-orig; +8 bits 11..21 als width-minus-one en bits 0..10 als height-minus-one; +c bits 8..20 als stride en twee vier-bit scalervelden. Hij controleert de geometrie tegen displaybreedte/hoogte en beide scalervelden op <3. De precieze registerdefinities, timing en hardware-scaling blijven open.

## Wat glnavi werkelijk vrijgeeft

`glnavi.exe!0x11000–0x1116b` geeft TRUE aan `0x229c7c`. Dat zet **alleen de interne vrijgaveflag**. Bij een latere `0x229c44` voor index 2 weigert de handler zonder die flag het enable-bit te zetten en logt `Block ... OGL Enable m_bOGL_Activate`. Het pad geeft in dat geweigerde geval toch 1 terug. Een geslaagde escape-return is dus geen bewijs dat de OpenGL-laag zichtbaar is.

Daarmee is de launcher/driverkoppeling vastgesteld. Welke navigatiefunctie vervolgens het daadwerkelijke enable-commando geeft, blijft te volgen in nngnavi/OpenGL-libraries. Het debuglabel in glnavi (`setOSOverlayActivate`) dekt niet op zichzelf alle driversemantiek.

## RVC-koppeling en ABI

RVC-wrappers `0x10001c0c`, `0x10001c90`, `0x10001cf8`, `0x10001d70` en `0x10001de0` leveren respectievelijk enable/disable, init, configure, bufferwisseling en clear. Calls op `0x10007408` geven acht DWORDs door voor configure: vier via argumentregisters, vier via de caller-stack. De automatische pseudocode toont bij de wrapper maar vier parameters; de disassembly bewaart het volledige ABI. Trek daarom geen conclusie over ontbrekende velden uit de verkorte prototypeweergave.

Bij configure zet de wrapper DWORD +14 expliciet op nul; hierdoor wordt de setterroute gebruikt. Sommige overige handlerbranches geven ook 1 terug bij te korte/ongeschikte buffers. Callsite-bufferlengtes en de feitelijke registerwijziging moeten samen worden gecontroleerd.

Evidence: [ROM-driver-disassembly](disassembly/rom/ddi_au13xxlcd.dll.asm), [ROM-driver-pseudocode](decompiled/rom/ddi_au13xxlcd.dll/decompiled.c), [RVC-disassembly](disassembly/RVC.dll.asm), [RVC/camera-contract](camera-contracts.md), [gevalideerde registry](boot-registry.md).
