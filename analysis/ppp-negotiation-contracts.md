# PPP-onderhandeling, opties en authenticatie

Vervolg op de [transportlaag](ppp-transport-contracts.md). Originele ROM-`ppp.dll` SHA-256 `b5f6bd4f0d8295e9203b3f92bd23a2920ecc086804f76caadb2e18d9e6d05df5`. [Machineleesbare evidence](firmware/ppp-negotiation-contracts.json) bevat originele functie-/tabelbytes, callbackadressen en onafhankelijke offline modellen; reproduceer met `py tools/inspect_ppp_negotiation.py`. Geen firmwarecode uitgevoerd.

## Protocolregistratie en demultiplexing

`c04335e0` bewaart per sessie een gesorteerde lijst van 12-byte records: protocol-DWORD, callbacktable-pointer, context-pointer. De tabel groeit met 15 records. De gevolgde constructors registreren:

| Constructor | Contextbytes | Protocolwaarden |
| --- | ---: | --- |
| `c0439fb8` | 136 | `c021` LCP |
| `c043bb08` | 2308 | `c023` PAP, `c223` CHAP, `c227` EAP |
| `c0437040` | 4696 | `8021` IPCP, `0021` IPv4, `002d/002f` gecomprimeerde/ongecomprimeerde TCP-headers |
| `c0438e5c` | 112 | `8057` IPv6CP, `0057` IPv6 |
| `c043f058` | 26260 | `80fd` CCP, `00fd` gecomprimeerde data |

`c0436878` is de bovenliggende netwerk-/compressiecontext; IPv6 wordt alleen aangemaakt als de capability/config-helper toestaat. De CCS/IPv6-capabilitylogica en volledige compressiecode zijn nog niet afgerond.

Receive-leaf `c0433158` verwijdert optioneel `ff 03`, leest het protocol big-endian tot een byte met lage bit 1, en zoekt daarna de tabel. Bij `ff` gevolgd door een andere controlbyte wordt geen protocol geleverd. Een opvallend concreet verschil: de lus begrenst het protocol via de opgebouwde hoge byte, niet via een teller van maximaal twee bytes. Extra leading zeroes, bijvoorbeeld `00 00 21`, leveren daardoor alsnog IPv4-protocol `21`. Dat is gereproduceerd in een offline model en gevolgd in assembly `c04331a8..c04331d8`.

`c0446f50` bouwt de zendheader: protocol low byte, zo nodig high byte; framingflag `0x400` laat een lage protocolwaarde toe als één byte. Flag `0x200` kan `ff 03` onderdrukken, maar LCP krijgt deze prefix altijd op het normale pad. De protocolheader komt vóór de payload in de gereserveerde padding. Deze flags zijn onderscheiden van de PPP-framingbit `0x100` uit AsyncMac.

## Gedeelde onderhandelingsmachine

Descriptors op `c044d4c4/d2a4/d404/d6fc` benoemen LCP/IPCP/IPV6CP/CCP en bevatten protocol, requestbufferomvang en handlers. `c044a4d4` maakt een nulgevulde `0x64c + descriptor-bufferbytes` context. Requestruimte is 64 bytes voor LCP/IPCP, 32 voor IPv6CP/CCP. Een afzonderlijke replyruimte in de context heeft capaciteit 1500 bytes; dit is geen algemene packetlimiet voor alle protocols.

Staten `0..9` volgen het gebruikelijke PPP-automaatpatroon: Initial, Starting, Closed, Stopped, Closing, Stopping, Req-Sent, Ack-Rcvd, Ack-Sent, Opened. Die namen zijn interpretaties van gevolgde transitions en het [PPP-automaat in RFC 1661](https://www.rfc-editor.org/rfc/rfc1661.html#section-4.2); de originele binary bewaart hier numerieke staten.

Defaultwaarden en registry-overrides onder `HKLM\Comm\ppp\Parms`:

| Veld | Default | Override |
| --- | ---: | --- |
| Restarttimer | 3000 ms | `RestartTimer` in seconden, ×1000 |
| Configure-counter | 10 | `MaxConfigure` |
| Terminate-counter | 2 | `MaxTerminate` |
| Failure-counterlimiet | 5 | `MaxFailure` |

De pseudocode van `c044a4d4` liet drie registryqueries weg en markeerde timeroverride-code als onbereikbaar. Assembly toont één variadische queryhelper met vier records en de uitvoerbare ×1000-branch. Het option-initialisatiepad `c044a6b8` is eveneens variadisch: elk descriptor krijgt twee policywaarden tot een nulterminator. Een pseudocodecall met slechts vier argumenten is dus onvolledig.

Receive `c044afb0` verwerpt packets kleiner dan vier bytes, declared length<4 en declared length>ontvangen bytes. Configure-code 1 komt in de optionengine; codes 2–4 moeten de huidige identifier dragen. Een Configure-Ack moet bovendien dezelfde declared length en identieke bytes vanaf identifier bevatten als het uitstaande request. Padding na declared length verandert die vergelijking niet. Terminate 5/6, Code-Reject 7 en extra protocolspecifieke codes hebben aparte branches.

`c044a830` verwerkt statewijziging, timerstop en uitgestelde zendflags, gevolgd door descriptorcallbacks. `c044acd4` start timer `c044abe8`; die callback retransmitteert configure/terminate zolang de counter niet nul is en verandert de staat na uitputting. Volledige concurrency, alle callbacks en iedere eventcombinatie blijven open; hier is geen volledige runtime-conformiteit bewezen.

## Optieformaten

Originele records zijn 32 bytes: ID-byte, payload-size-byte, twee overige bytes, ASCII-name-pointer en zes callbackpointers. Size `ff` betekent variabel. De generieke TLV-lus `c044b690` vereist telkens twee headerbytes, lengte≥2 en lengte≤remaining, en consumeert precies die lengte.

| Groep | ID | Payloadbytes | Naam uit binary |
| --- | ---: | ---: | --- |
| LCP | 1 | 2 | MRU |
| LCP | 2 | 4 | ACCM |
| LCP | 3 | variabel | Auth-Protocol |
| LCP | 5 | 4 | Magic |
| LCP | 7 | 0 | PFC |
| LCP | 8 | 0 | ACFC |
| IPCP | 2 | variabel | IP-Compression-Protocol |
| IPCP | 3 | 4 | IP-Address |
| IPCP | 129 | 4 | DNS-Address |
| IPCP | 130 | 4 | WINS-Address |
| IPCP | 131 | 4 | DNS-Backup-Address |
| IPCP | 132 | 4 | WINS-Backup-Address |
| IPv6CP | 1 | 8 | IFID |

`c044b740` zoekt een aangeboden requestoptie, test peer-policy en vaste/variabele payloadlengte, vraagt de optionhandler om Ack/Nak/Reject en bouwt de reply. Onbekende, uitgeschakelde of verkeerd gesizede opties krijgen Reject. `c044bc4c` houdt bij welke vereiste opties ontbreken en kan deze NAK-en. Na herhaalde Naks wordt de failurelimiet gebruikt. Ack/Nak/Reject-callbacks op `c044b868/b8e4/b984` wijzigen de individuele optionstate.

Standaard-LCP policyparen uit `c043aef8`: MRU `(1,1)`, ACCM `(2,1)`, Magic `(0,1)`, PFC `(2,1)`, ACFC `(2,1)`. Authenticatie `(0,1)` op het normale clientpad, `(0,3)` bij gecombineerde entrybits `0x1800`, `(0,0)` op het gevolgde serverpad. Voor devicetype `PPPoE` veranderen ACCM naar `(0,0)`, PFC naar `(1,1)`, ACFC naar `(0,1)`. De paren zijn opgeslagen als exacte lokale/peer-policywaarden; hun volledige enumsemantiek wordt verder onderzocht.

IPCP vraagt VJ-compressie alleen bij entrybit `8`. IP-adrespolicy is `(2,1)`. DNS/WINS-policies hangen af van server/clientmode, entrybit `4` en een sessie-configveld. IPv6CP registreert IFID met `(2,2)`. De daadwerkelijke uitkomst op een USB-peer is nog niet waargenomen.

## Authenticatiekeuze

Vijf originele 8-byte records op `c044d50c`, gevolgd door nulterminator:

| Index/bit | Binarynaam | Protocol | Algorithmbyte |
| --- | --- | --- | ---: |
| 0 | PAP | c023 | 0 |
| 1 | CHAP-MD5 | c223 | 5 |
| 2 | CHAP-MS | c223 | 128 |
| 3 | CHAP-MSV2 | c223 | 129 |
| 4 | EAP | c227 | 0 |

`c0432eac` maakt sessiemask `+0xad4` aanvankelijk `1f`. Entrybit `400` wist PAP; `800` of `1000` wist PAP én CHAP-MD5. Bits `40000/80000/100000/200000/400000` wissen respectievelijk PAP/MD5/MS/MSV2/EAP. EAP verdwijnt ook bij afwezige geladen EAP-library of type=0. `c043aae0` probeert vanaf index 4 naar 0 en slaat al afgewezen keuzes over. Dit is een voorkeur uit de code, geen vast bewijs welke methode de boot-entry gebruikt.

`c043a930` decodeert de Auth-Protocol-optie naar protocol en optionele algorithmbyte; `c043ab5c/ac90/ac00` vergelijken tegen allowed mask en bouwen zo nodig een alternatief of Reject. De vijf algorithmrecords zijn afzonderlijk aan PAP/CHAP/EAP-initialisatie gekoppeld.

## PAP en CHAP

PAP-client `c043e648` bouwt code 1, ID, BE16-total length, éénbyte gebruikersnaamlengte/data en éénbyte wachtwoordlengte/data. Conversiehelper `c043e350` gebruikt `WideCharToMultiByte(1,...)`. De lokale/codepage-afhankelijke conversie en mogelijke éénbyte-lengteoverloop bij lange invoer zijn nog niet volledig onderzocht. Parser `c043e3b0` bewaakt de gebruikersnaam-/wachtwoordgrenzen in binnenkomende requests.

Voor ACK/NAK in clientmode bewaart deze PAP-handler de laatst ontvangen ID op `+0x8e6` en negeert duplicaten; binnen deze handler is geen vergelijking met de ID van het uitgaande request zichtbaar. De volledige toegestane authstates/callercontroles worden nog gevolgd.

CHAP-parser `c043e0b4` bewaakt value-size binnen declared packetlengte. Client challenge kopieert de value en laat de geselecteerde algorithmcallback een response genereren; Success/Failure moeten overeenkomen met de bijgehouden challenge-ID. Algorithmtabellen liggen op `c044d63c/d654/d6c0`. MD5 levert 16 responsebytes; MS-CHAP en MS-CHAPv2 leveren beide 49 bytes. De volledige Microsoft-crypto/key derivation wordt apart onderzocht.

MD5-client `c043d230` roept werkelijk `RSAENH!MD5Init`, drie `MD5Update`s en `MD5Final` aan. De inputs zijn achtereenvolgens één ID-byte, geconverteerde wachtwoordbytes en challengebytes. De wachtwoordconversie gebruikt een 56-byte buffer; conversiefalen en lange invoer blijven een open foutpad. Serververifier `c043d2fc` gebruikt dezelfde invoervolgorde en vergelijkt 16 digestbytes. Deze volgorde komt overeen met [CHAP in RFC 1994](https://www.rfc-editor.org/rfc/rfc1994.html). Offline voorbeelden gebruiken uitsluitend synthetische publieke invoer; er zijn geen wachtwoorden uit de unit gelezen.

PAP-server en de gevolgde CHAP-serververificatie proberen een helper `c0439bb8` te gebruiken. De oorspronkelijke twee instructies zijn `jr ra; addiu v0,zero,0`: de helper geeft altijd false. PAP neemt hierdoor de `Access Denied`-branch; CHAP begint met failure `0x2b3` en gaat niet naar de credential-verifier. Dit is een concrete buildbeperking op deze paden. EAP heeft een apart pad; daaruit volgt geen uitspraak over alle servermogelijkheden.

## EAP-grens

`c043b030` haalt twaalf functies uit `eap.dll`: session create/destroy, get identity, process RX, implied success, process result, set connection/userdata, identity/password, config UI en MPPE-key extraction. `c043b840` maakt een sessie met maxpacket 1500, stelt identity/password in en laadt entrygebonden `EapConnData` en `EapUserData`. De externe module is aanwezig maar haar volledige gedrag is nog niet semantisch onderzocht.

## Validatie en resterend werk

De tool controleert 79 oorspronkelijke bytebereiken, 13 optionrecords en vijf authenticatierecords, 144 combinaties van packetlengte, 1536 TLV-gevallen, vier Ack-vergelijkingen en zes protocolprefixes. Dit zijn offline modellen van gevolgde code, geen tests op de fysieke MediaNav.

Open: iedere optionhandler, volledige FSM-eventmatrix met side effects, PAP-conversie/ID-controles, MS-CHAP/MPPE/CCP, `eap.dll`, effectieve USB-peerconfig en runtime/lifetime-fouten. Het onderzoeksdekkingsoverzicht blijft deze onderdelen expliciet open noemen.
