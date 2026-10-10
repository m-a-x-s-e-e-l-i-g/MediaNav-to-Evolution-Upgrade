# USB-devicefunctie, COM5 en RAS-startup

Onderzocht: oorspronkelijke ROM-modules USBware2.dll, jacmdev.dll en jacminit.exe uit de beschikbare 7.0.5.MD-update. Alleen statische analyse; geen executable is uitgevoerd en geen apparaat aangesloten. Het reproduceerbare bewijs staat in [usb-serial-contracts.json](firmware/usb-serial-contracts.json): drie SHA-256-bewaakte bronbestanden en 56 oorspronkelijke code-/databereiken.

## Concrete keten

```text
USBware2.dll / UDD device-controller
  function type 6 -> c082c81c -> c082a970
  LoadDriver(JACMDEV.DLL), register_usb_stack
  twee bulk-endpoints, tien RX-buffers
       <-> USB TX/RX callbacks
jacmdev.dll / COM5 / Unimodem FriendlyName uwserial
       <-> Windows CE serial IOCTLs, read/write, events en ringbuffer
jacminit.exe
  bootregistry -> RasSetEntryProperties("`Default USB`")
  voorwaardelijk HKCU ControlPanel\Comm AutoCnct/Cnct
```

Hiermee is function type 6 als seriële brug geïdentificeerd. Welke fysieke poort op de echte unit in device-mode staat en welk hostprogramma ermee communiceert, is nog niet bewezen.

## Defaultinterface is vendor-specifiek

De oorspronkelijke defaultfunctionconfig op **c08390d8** is `(6,1,0)`. De initializer-tabel op **c0839164** koppelt type 6 aan **c082c81c**. Heapallocator **c08246fc** gebruikt HeapAlloc flag 8 en wist de nieuwe context. **c082a970** zet de functionflags op `0x1f`, capabilities op `0x3f` en installeert de callbacks.

**c082c81c** wist zijn 28-byte descriptorargumenten. Met die flags blijven subclass/protocol nul, interrupt-endpoint uit, split-interface uit en de callback voor CDC-functionaldescriptors nul. De bulk-pairflag wordt één en de vendor-variantflag één. **c08344b8 → c0834550** maakt daardoor:

| Eigenschap | In deze defaultconfig |
| --- | --- |
| Interfaces | Eén |
| Interface class/subclass/protocol | **FF / FF / FF** |
| Data-endpoints | Twee bulk-endpoints, tegengestelde richtingen |
| Interrupt-endpoint | Geen |
| CDC-functionaldescriptors | Geen |
| Bulk maxpacket | 64 full-speed, 512 high-speed; helper c0834a84 |

De generieke CDC-descriptorbuilder **c082ca1c** is aanwezig, maar wordt door deze flagcombinatie niet gebruikt. Dat onderscheid bepaalt of een standaard hostdriver de interface automatisch herkent; daadwerkelijke driverbinding is nog open. Device VID/PID `045e:00ce` en controllerselectie staan in [USB-controllercontracten](usb-controller-contracts.md).

## Controlrequests blijven aanwezig

**c08364f8** verdeelt standaard-, class- en vendorrequests. Bij interface-recipient gebruikt hij het lage byte van wIndex om de interfacecallback te selecteren. De callback wordt met de opgeslagen functioncontext aangeroepen; de interfaceklasse FF verhindert dit codepad niet. **c082b79c** verdeelt vervolgens uitsluitend op bRequest:

| bRequest | Routine | Gevolgd contract |
| --- | --- | --- |
| 00 / 01 | c0833bc8 / c0833dd8 | Encapsulated-command/response helpers; payloadsemantiek open |
| 02 / 03 / 04 | c082b96c / c082bb80 / c082bd5c | Comm-feature helpers; volledige werking open |
| 20 | c082be44 | Set line coding; capabilitybit 2, lengte exact 7, callback op context+a8 |
| 21 | c082c0bc | Get line coding; dezelfde capability/lengte, callback op context+ac |
| 22 | c082c2e8 | Control-line state; callback context+b0 naar c082b70c |
| 23 | c082c3bc | Break; capabilitybit 4 en callback context+b4 |

De namen en de zeven bytes voor line coding zijn vergeleken met de [primaire Linux USB CDC-header](https://raw.githubusercontent.com/torvalds/linux/master/include/uapi/linux/usb/cdc.h). Die vergelijking geeft namen aan requestnummers; zij bewijst geen actieve CDC-interface op de MediaNav.

**c082b70c** vertaalt control-line bit 0 naar `0xa0` en bit 1 naar `0x10`, waarna een work-item de reverse callback aanroept. De betekenis van alle resulterende modemstatusbits en het gebruik door PPP/replicatie moeten nog verder worden gekoppeld.

## Bidirectionele bufferbrug

**c082ab4c** laadt JACMDEV.DLL en zoekt `register_usb_stack` en `unregister_usb_stack`. **c082ac58** registreert de appcontext, bewaart het teruggegeven serial-object, maakt de worker aan, haalt via **c083385c** de WORD op functioncontext+46 op en reserveert in **c082b0fc** tien DMA/RX-buffers. De waarde komt uit de geïnitialiseerde endpointcontext, niet uit een willekeurig aangenomen baudrate.

De oorspronkelijke callbacktabel op **c0839174** bevat:

| Callback | Richting en gedrag |
| --- | --- |
| c082a460 | Serial write → nieuw DMA-buffer, memcpy, c08331f8 om USB-transmit in te dienen. Bij alloc/submitfout wordt bytecount nul. |
| c082a5b4 | USB receive → serial read: consumeert de queued RX-buffers, houdt gedeeltelijk verbruik bij en dient volledig verbruikte buffers opnieuw in via c08334b0. |
| c082a920 | Slaat een statuswaarde op appcontext+20 op. |

RX-completion **c082b628** zet ontvangen buffers in de queue en plant **c082a364**; die meldt de serial-driver eventselector 1. TX-completion **c082b4ec** ruimt de transfer op en plant **c082a3e0**, eventselector 0. De driver heeft daarvoor twee reverse callbacks op **c08470ec**.

**register_usb_stack c0841400** retourneert het bestaande globale serial-object in register v0. Ghidra heeft dit bladfunctieprototype ten onrechte als `void` afgeleid. De oorspronkelijke 64 bytes bevestigen de retourwaarde en de drie callbackpointers op object+100/+104/+108. De routine dereferenceert de global zonder lokale nullcontrole. Driverinitialisatie vóór USB-registratie is dus een voorwaarde; de bootregistry noemt jacmdev Order 3, maar alle startup-races zijn nog open.

## COM5-driver

De bootregistry zet `Prefix=COM`, `Index=5`, `DeviceArrayIndex=4`, `Dll=jacmdev.dll`; de Unimodem-subkey noemt **uwserial** en **Unimodem.dll**. **COM_Init c084583c** maakt de seriële context, events, critical sections en RX-ring aan. De ringgrootte heeft een minimum van 2048 bytes en wordt aan een PDD-gerelateerde buffergrootte gekoppeld; de volledige objectinitialisatie bepaalt de uiteindelijke waarde.

**COM_Open c0845b18** zet onder meer de initiële DCB op 9600 baud, acht databits en nul parity-/stopcodering. Het gevolgde backend-baudmethod **c0841780** retourneert succes als stub: 9600 is hier geen bewijs van een echte UART of USB-doorvoersnelheid. De driver onderscheidt actieve read/write-opens en overige opens.

**COM_Read c084409c** vereist read-access en een actieve context. Hij verwerkt interval- en totale timeouts, wacht op het RX-event, kopieert contigu ringdata naar de caller en schuift de read-index modulo de capaciteit door. **COM_Write c0845e54** gebruikt CeAllocAsynchronousBuffer en een write-event; de timeout wordt uit multiplier × gevraagde bytes + constant berekend, met nul als oneindige wacht in dit pad.

**COM_IOControl c0844894** behandelt onder meer break, DTR/RTS, eventmask, modemstatus, properties, timeouts, purge, immediate character en 28-byte DCB get/set. Hij biedt ook beperkte power-IOCTLs via **c0841fe0**. De complete seriële eventstate, close/purge-races en alle undocumented codes zijn nog open.

## jacminit maakt een RAS-entry

Boot `Launch80=jacminit.exe`, Depend80 `14,00`, koppelt de executable aan device-startup. De volledige applicatieroutine **1151c..12580** leest maximaal negen named entries uit HKLM `Comm\Ras\Init`, bouwt per entry een zeroed record van **0xd90 bytes** en roept RasSetEntryProperties aan. Er zit geen RasDial in deze routine.

De beschikbare registry noemt entry en Cnct letterlijk **`Default USB`**, inclusief backticks. De entry gebruikt `szDeviceName=uwserial`, `szDeviceType=direct`, framingprotocol 1 en netwerkprotocolflags 4. De ipaddr_a/b/c/d-values worden als bytes **64 37 a8 c0** in het record geschreven. De omzetting door de RAS-laag naar een zichtbaar IP-adres blijft te controleren; alleen op basis van de namen mag de bytevolgorde niet worden omgekeerd.

HKLM AutoCnct 1 schrijft de autoconnectinstellingen naar HKCU. Bij waarde 2 gebeurt dat afhankelijk van RasValidateEntryName; resultaat `0xb7` voorkomt deze update. Waarde 0 doet dat niet. De originele bootregistry heeft zowel HKLM als HKCU AutoCnct 0. Het onderzochte dboot-pad kan later HKCU AutoCnct 1 schrijven; zie [boot-helpercontracten](boot-helper-contracts.md). Deze registrywijziging bewijst nog geen gestarte verbinding of desktopreplicatie.

## Statisch bevestigde foutpaden

1. **GET_LINE_CODING:** de geïnstalleerde callback op context+ac is **c082b5e0**, een successtub zonder writes. **c082c0bc** geeft haar een niet-geïnitialiseerde zevenbyte stackbuffer en kopieert die daarna naar de transferbuffer. Assembly bevestigt zowel de onbeschreven buffer als de copy. De interface-dispatch biedt hiervoor een class/interface-requestpad met lengte 7. Werkelijke hostbereikbaarheid, ontvangen bytes en gevolgen zijn niet op hardware getest.
2. **Controlbuffer-allocation:** **c0833a44** schrijft `local_10[3]` ook na een mislukte allocation. Die branch dereferenceert nul. Of geheugenuitputting dit op de unit bereikt is onbekend.
3. **COM_Read:** bij **c084427c** wordt de retourwaarde van CeSafeCopyMemory genegeerd; de daaropvolgende instructies verhogen toch de verbruikte bytecount en ringindex. Een mislukte copy kan daardoor data consumeren en een positieve readcount produceren. Geen runtime-fout opgewekt.
4. **RAS options:** de bootregistry heeft `dwfOptions=hex:08,02`, slechts twee bytes. **1191c..11964** vraagt vier bytes in scratch-DWORD stack+20 en kopieert daarna de gehele DWORD naar entry+4. Deze scratch wordt niet vooraf geïnitialiseerd; de memset voor het RAS-record begint pas op stack+30. De low WORD is 0208, de high WORD is uit deze code niet gegarandeerd. De daadwerkelijke registry-API-write en effecten moeten nog worden bevestigd.
5. **RAS stringvelden:** meerdere registryqueries gebruiken een bronbuffer van 1000 bytes en memcpy van de teruggegeven lengte naar kleinere recordvelden, waaronder 22 en 34 bytes. Er is in deze routine geen lokale veldlengtecap. Originele standaardwaarden zijn kort; bereikbaarheid met gewijzigde registry en effecten zijn nog open.

Dit zijn codebevindingen, geen gevalideerde exploit- of crashclaims.

## Vervolg

- PPP/Unimodem, autoras, repllog en de daadwerkelijke autoconnecttrigger.
- Endpointtoewijzing, maximale RX-bufferlengte, disconnect/close en worker-lifetime.
- Alle CDC-feature-/modemstatusdetails en powertransities.
- Actieve unitregistry, fysieke role-selectie en hostdriver; deze ontbreken in de updatebestanden.

`py tools/inspect_usb_serial.py` controleert de originele bytes en defaultdescriptorafleiding en doorloopt zes onafhankelijke ringbuffer-rekenmodellen. Dit is verificatie van de reconstructie, geen uitvoering van firmware.
