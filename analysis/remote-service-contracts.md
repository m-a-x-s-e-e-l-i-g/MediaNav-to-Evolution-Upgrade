# RAS-autoconnect en desktop-/RAPI-services

Zeven oorspronkelijke ROM-modules gevolgd: autoras.dll, repllog.exe, rnaapp.exe, rapisrv.exe, ppp.dll, afd.dll en udp2tcp.exe. Alleen statisch; geen verbinding geopend of remote commando uitgevoerd. [JSON-evidence](firmware/remote-service-contracts.json) bewaart hashes, oorspronkelijke codebereiken, de volledige 86-slot commandotabel en onafhankelijke rekenmodellen.

## Relatie met COM5

[jacminit](usb-serial-contracts.md) maakt de RAS-entry **`Default USB`** voor device **uwserial**. Dboot schrijft die entrynaam en AutoCnct=1 naar HKCU ControlPanel\Comm. **Repllog 17e88** leest diezelfde AutoCnct-value voordat hij zijn lokale verbindingspad opent. **Repllog 14490** leest Cnct, tenzij `/auto` of `/ircomm` een ander pad kiest; bij ontbrekende/lege Cnct gebruikt hij `Direct`.

De startupvalue voor AutoCnct wordt eerst op 1 gezet. Een mislukte registryread laat die default dus bestaan. De originele bootregistry heeft AutoCnct=0, maar dboot wijzigt die waarde. Het precieze moment waarop de unit repllog start is nog niet uit een startup-/notificatierecord gekoppeld.

**Repllog 17044**, messages 470/46f, start **rapisrv.exe** en wacht maximaal 30 seconden op **RAPI:STARTEVNT**. Vervolgens start hij **rnaapp.exe** met `-n -m -e"<Cnct>"`, of met aanvullend `-p` bij `/auto`. Bij bestaande vensters/verbindingen gebruikt hij andere branches en statusmessages; dit is geen onvoorwaardelijke launch op iedere message.

**Rnaapp 12c60** parseert opties met `-` of `/`, accepteert hoofd-/kleine lettervarianten en begrenst de entrynaam op 21 tekens. Hij leest de entry via RasGetEntryProperties, maakt het dialoogvenster en post message **4c9**. **12280** behandelt die message, haalt dialparams op en roept **RasDial(0,0,&dialparams,ffffffff,hwnd,&connection)** aan. Bij beëindiging gebruikt hij RasHangUp. De PPP-onderhandeling en de wijze waarop Unimodem uwserial selecteert blijven verder te volgen.

## Autoras is een afzonderlijke launcher

Bootregistry BuiltIn\autoras heeft Prefix **ARS**, Index 1, Dll autoras.dll, Order 40 en Flags 2. HKLM Comm\Autoras noemt **Dialer=rnaapp.exe**, **RasEntryOpt=-e** en **NoPromptOpt=-p**, maar bevat **geen RasEntry-value**. Die ontbrekende instelling voorkomt dat de gevolgde automatic-entry-selectie een naam uit deze bootconfig haalt. Een runtime-registry kan daarvan afwijken.

**ARS_Init c0591808** maakt de critical section, named queue **AutorasMsgqueue** (achtbyte messages) en een handmatig gereset event. Succescontext is **12345678**. Hij start de readerthread **c0591160** en sluit alleen diens handle; de thread blijft actief.

| Message eerste DWORD | Effect in de queue-reader |
| --- | --- |
| 1 | Dialer actief, timestamps gewist |
| 2 | Dialer inactief, exittimestamp GetTickCount |
| 3 | Disconnect-/annuleertimestamp GetTickCount; bij synchronous waiter event signaleren |
| 4 | Statusflag gezet; bij synchronous waiter event signaleren |

Rnaapp schrijft message 1 bij startup, 2 bij exit en 3 vanuit zijn stopbranch. Andere producenten en de volledige betekenis van message 4 zijn nog open.

**Autoras_Dial c0591bec** opent ARS1: en geeft IOCTL **120800** door. **Autoras_Dial_Sync c0591c0c** gebruikt **120804**. Ghidra leidt beide wrappers als void af; verdere ABI-verificatie vereist hun oorspronkelijke returns. **ARS_IOControl c0591a3c** doet de selectie en launch onder een critical section; de synchronous variant wacht via **c0591480** maximaal 30 seconden en laat tijdens het wachten de lock los.

**c0591310** vereist geen actieve dialer, ongeveer vijf seconden afstand tot de cancel/disconnecttimestamp, tien seconden tot de exittimestamp, een REG_SZ RasEntry en geen bruikbaar adapteradres volgens **c0591c2c**. Die adapterhelper gebruikt GetAdaptersInfo/inet_addr en test de laagste adresbyte onder meer tegen a9 en nul; de precieze uitsluitingssemantiek en errorbranches zijn nog niet volledig beoordeeld.

**c0591d18** controleert bestaande RAS-connecties met een 520-byte buffer voor maximaal tien 52-byte records en case-insensitive entryvergelijking. **c0591df8** bepaalt op basis van device type `modem` en dialparams of een prompt nodig is. **c0591480** bouwt de commandline en start de geconfigureerde dialer.

Een IOCTL-retourwaarde is hier beperkt bewijs: **c0591a3c** overschrijft iedere return behalve die voor 120804 naar TRUE, ook bij onbekende codes of wanneer geen dialer is gestart. De asynchronous wrapper kan dus geen geslaagde verbinding aantonen. Deinit sluit queue/event en wist de critical section zonder een gevolgde readerthread-join; de volledige shutdownvolgorde blijft open.

## RAPI-listener en hostfilter

**Rapisrv 12910** gebruikt window class **RapiSrv**, titel **Pegasus Remote API Server** en start thread **12040**. Die opent TCP-listeners op **990** (`0x3de`). **135c8 → 1343c** gebruikt AF_INET 2 of AF_INET6 23, SOCK_STREAM 1, bind op het zeroed/all-addresses socketadres en listen backlog 2.

**13360** leest IPVersionSetting uit HKLM Software\Microsoft\Windows CE Services, maskert op drie en gebruikt default 3 als het resultaat nul is. De onderzochte listenercode probeert IPv4 ongeacht bit 1 en IPv6 indien bit 2 gezet is. De naam IPVersionSetting alleen voorspelt dus niet iedere branch.

De server accepteert nog geen sessions zolang de host-addresslist **1e2d8** ontbreekt. **Windowproc 11da8** verwerkt WM_COPYDATA (`4a`) met ID **1f5** en minder dan 33 bytes, kopieert de UTF16-hostnaam, zet een flag uit wParam en roept **11c44** aan. Die converteert maximaal 17 tekens en gebruikt getaddrinfo met servicetekst **5679**. **11d20 / 132e0** vergelijkt een incoming peer met die addresslist: family en IPv4-adres of zestien IPv6-adresbytes. De peerpoort wordt hier niet vergeleken.

De producent is **Repllog 1b568**: hij geeft de hostnaam uit zijn sessionobject+**a4** door, met wParam uit de globale flag **1d338**. Zijn handshake **1bc58** roept dat pad pas na een geslaagde passwordcontrole, of vanuit de branch zonder passwordvereiste. Bind-all-addresses is daarom geen bewijs dat alle hosts geaccepteerd worden. De runtime-hostnaam en keuze van die lokale flag blijven nog te bevestigen.

### PPP-peer en tweede poort

Repllog **1b93c** resolved de opgegeven sessionhost op TCP **5679**, met **ppp_peer** als default/fallback. **1bb40** opent de TCP-connectie en bewaart het peeradres. **1bc58** handelt de desktop-handshake af: zonder passwordvereiste stuurt hij een nul-DWORD; anders stuurt hij Ident\\PegId, ontvangt maximaal 81 passwordbytes, XORt die met de lage PegId-byte en controleert CheckPassword. De berichtvorm verschilt van de latere RAPI-passwordbranch: hier gaat een WORD-status terug.

**1b640** stuurt vervolgens een info-record met headergrootte 40, gepakte OS-versie, processortype, flags, twee eventuele partnershipwaarden en offsets naar UTF16-strings voor identiteit/platform. Vooraf gaat een DWORD recordlengte over de socket. De bronnen van alle strings en partnershipwaarden blijven verder te volgen. **1b568** koppelt de succesvol geverifieerde host aan de RAPI-filter op poort 990. De firmware bevat dus afzonderlijke desktop-handshake- en remote-API-kanalen.

PPP **c0435398** haalt een adres uit de gekoppelde IP-state, roept **c0435dec** aan wanneer nonzero en configureert vervolgens de virtuele adapter met VEMSetIPConfig/bindings/media-state. **c0435dec** verwisselt de vier adresbytes en geeft ze aan **c0435cc0**. Die verwijdert eerst HKLM **Comm\\Tcpip\\Hosts\\ppp_peer** en maakt bij een nonzero adres de key opnieuw met **ipaddr REG_BINARY, vier bytes**. **c0434af4** doorloopt resterende sessies en werkt deze mapping eveneens bij. De precieze IP-state-layout en de callbacks die dat bij connect/disconnect triggeren zijn nog open.

AFD **c051a698** probeert hosts-registryhelper **c0514ba0** voordat hij overige naamresolutie doet. Die leest ipaddr/ipaddr6 en vergelijkt hostnamen/aliases. Als ppp_peer niet in die mapping wordt gevonden, geeft c051a698 **2af9** terug in plaats van door te gaan naar het gewone DNS-pad. Deze naam is daarmee expliciet gekoppeld aan de lokale PPP-hostregistratie.

## Wachtwoordbranch

**12040** bewaart GetPasswordActive bij threadstart. Na de adresfilter wordt de wachtwoordbranch overgeslagen wanneer die waarde nul is of de host-updateflag **1e2d4** nonzero is. De betekenis/vertrouwensgrens van die flag hangt af van de nog te volgen WM_COPYDATA-producent.

Anders leest de server een WORD met bytecount, vereist count <520 en leest de payload. Bij succesvolle Ident\PegId-query XORt hij iedere payloadbyte met de laagste PegId-byte. Daarna volgt de Windows CE CheckPassword-call. ControlPanel\Password\TimeOut bepaalt een Sleep vóór de controle; succes zet TimeOut nul, mislukking maakt `(oudewaarde+1)*2`. Eén statusbyte gaat terug naar de peer. Dit beschrijft code; het is geen claim over de actieve unitinstellingen of de cryptografische veiligheid van een volledige externe sessie.

Een assembly-/pseudocodebevinding in deze branch: de tweebyte length-loop test **de laatst ontvangen bytecount ==2**, terwijl hij het bufferadres en remaining count met de totale teller bijwerkt. Twee opeenvolgende reads van één byte vullen de WORD maar verlaten de loop niet; de volgende recv heeft lengte nul en leidt tot de closebranch. De algemene receivehelper voor RAPI-frames gebruikt wél de totale teller. Hardware-/netwerkgedrag is niet getest.

## Wireframe en 86 commandslots

**12e30** leest eerst een native DWORD lengte en daarna een DWORD command-index. MIPS is little-endian en er zit hier geen byteorderconversie tussen. Lengte nul wordt afgewezen; index moet **0..55 hex** zijn. De dispatch **12bec** ontvangt `lengte-4` payloadbytes. **1c250** verzamelt partial receives tot de gevraagde totale bytecount. **1c660** alloceert de payload en schrijft die in de per-session buffer.

De originele pointertabel begint op **110f8** en heeft **86 slots**. [De complete commandotabel](rapi-command-table.md) geeft alle targets en directe API-callkandidaten; de payloads zijn nog niet allemaal semantisch beoordeeld.

| Voorbeeldslot | Target | Handmatig gevolgde actie |
| --- | --- | --- |
| 05 | 16c68 | Parseert vijf DWORD-argumenten en een wide string, roept CreateFileW aan; bewaart geldig handle met type 1. |
| 06 / 07 | 16df0 / 16fdc | File read/write-wrappers; volledige schema's nog open. |
| 19 | 13acc | Parseert application/commandline en optionele structures, roept CreateProcessW aan; stuurt LastError, BOOL en 16-byte processinfo terug. |
| 1e / 20 / 27 | 193d0 / 194ec / 1508c | Registry open/create/set; slot 27 leest handle, valuenaam, type, data en bytecount vóór RegSetValueExW. |
| 45 | 1a60c | Parseert DLL-naam, exportnaam, inputdata en streamflag; LoadLibraryW/GetProcAddressW en call naar de export. |

Andere slots bieden fileenumeratie/attributen, directory/copy/move/delete, CE-databases, registryenumeratie, systeeminfo, shortcuts, password-API's, tijd/vensterinfo en extended databasevolumes. Voor wijzigingen op de echte unit zijn dit mogelijk bruikbare originele interfaces, maar hun actieve bereikbaarheid is nog niet vastgesteld.

Speciale dispatch: 30/31 hebben een WaitForAPIReady-voorwaarde, 45 behandelt de streammode apart, 46 gebruikt een andere helper en 47/48 gebruiken de sessioncontext als eerste argument. Deze slots volgen niet allemaal hetzelfde tabelprototype.

**1c900** leest uit de ring-/sessionbuffer en controleert beschikbare bytecount. **1cc40** leest een aanwezigheid-DWORD en een UTF16-character-count, alloceert count×2 en consumeert die bytes. **1cb2c** verwerkt aanwezigheid, bytegrootte en een extra dataflag voor optionele bufferargumenten. De volledige pointer-/NUL-/structuurcontracten en foutcleanup zijn nog open.

**1c100** verstuurt replies als DWORD payloadlengte gevolgd door de verzamelde payload. Hij doet één send en verwacht alle bytes in die call; een partial send wordt niet doorgestuurd in een loop. Errorcodevorming gebruikt hier GetLastError. Gevolgen bij een partial send of socketfout blijven runtimevragen.

De requestlengte heeft vóór `-4` geen expliciete minimumcontrole op vier: 1 en 2 worden enorme unsigned payloadgroottes, 3 wordt ffffffff. Die laatste waarde is bovendien een special case in 1c660 die een extra lengte-DWORD leest. Er is in deze gevolgde laag geen vaste maximumframegrootte. Dit is statisch beschreven; geen malformed request is verstuurd.

## UDP-over-TCP-proxy voor DNS

Na de handshake-/sessionmessages **603/604** roept Repllog **14804** de launcher voor **udp2tcp.exe** aan. Dat gebeurt ook vanuit een foutmessagebranch; alleen het bestaan van dit proces bewijst dus geen geslaagde sessie. De executable gebruikt window class **U2TPROXY** en sluit op message **47c**. Repllog verwijdert dat window bij zijn shutdownpad.

Proxy **119e8** leest HKLM **Comm\\UDP2TCP\\Port** en de Port-values van iedere subkey. De bootconfig heeft TCP-port **7438 (1d0e)** en één subkey **DNS, UDP-port 53**. **12020** resolved **ppp_peer**, connect naar die TCP-port en maakt één UDP-readerthread per subkey plus een TCP-readerthread.

**117ec** bindt UDP op alle IPv4-adressen en de geconfigureerde lokale port. Iedere ontvangen datagram van maximaal **1016 bytes** wordt als een TCP-frame gestuurd:

| Offset | Grootte | Bytes |
| --- | --- | --- |
| 0 | 2 | UDP-sourceport, network byte order |
| 2 | 2 | Lokale/destinationport, network byte order |
| 4 | 2 | Totale framelengte inclusief achtbyte header, network byte order |
| 6 | 2 | Geen write vóór de send in deze routine; stackinhoud |
| 8 | 0..1016 | UDP-payload |

De oorspronkelijke assembly **118ec..11930** schrijft expliciet de eerste zes headerbytes en kopieert de volledige acht. De laatste twee bytes worden in dit pad niet geïnitialiseerd. De proxy doet één send per datagram en controleert alleen op -1, zonder partial-send-loop. Bij meerdere UDP-subkeys delen de workers dezelfde TCP-socket; volledige send/lifetimevoorwaarden blijven open.

**11ce4** verzamelt TCP-chunks in een **4096-byte ring**, consumeert een achtbyte header en berekent payloadlengte als `(BE16_total-8)&ffff`. Header+payload moet in de callerbuffer passen; **11f10** geeft daarvoor 1024 bytes. Totals onder acht worden dus grote payloads en vallen door de buffercontrole af. De ringhelpers **1249c/125c8** controleren vrije/beschikbare bytes en verwerken wraparound.

**11f10** stuurt replies naar **127.0.0.1**, met de destinationport uit headeroffset 2. Er wordt geen IP-adres uit het wireframe overgenomen. De proxy kan zo lokale DNS-UDP over een TCP-kanaal naar de PPP-peer vervoeren; inhoudelijke DNS-parsing staat niet in deze gevolgde routine. Een zero-length UDP-datagram beëindigt de lokale readerloop. Shutdown sluit het TCP-kanaal en gebruikt lokale UDP-datagrams om readers wakker te maken, wacht per worker maximaal tien seconden en sluit handles. De volledige races en eventuele open readers zijn nog niet runtime-gevalideerd.

## Vervolg

- Volledige hostbinding/handshake, betekenis van de lokale flag en repllog-launchtrigger; de WM_COPYDATA-producent is hierboven gekoppeld.
- PPP framing/auth/IP, Unimodem en COM5-events tot aan een echte connectie.
- Payload-/handle-/returncontracten van ieder RAPI-slot en de RPC-/streamsubprotocollen.
- Timeout/error/cleanup en thread-lifetime; actieve unitregistry en fysieke USB-role.

`py tools/inspect_remote_services.py` controleert zeven SHA-256-bronnen, bewaart de commandotabel en codebytes en rekent zeven RAPI-requestlengtes, acht UDP-proxy-lengtes en twee partial-receivegevallen onafhankelijk door. Geen firmwarecode wordt uitgevoerd.
