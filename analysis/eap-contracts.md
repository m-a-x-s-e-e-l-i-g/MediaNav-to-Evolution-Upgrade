# EAP-engine en eapchap-plugin

Vervolg op [PPP-authenticatie](ppp-negotiation-contracts.md). Onderzocht: ROM-`eap.dll` (`89fb0a5396b9063ce548434207b763c24fa4f11640367167b50777842ae87e20`) en `eapchap.dll` (`01173e78734f818078914c152286716fdd3d46be38725ed87f52a825242a9a98`). [Evidence en offline modellen](firmware/eap-contracts.json), reproduceerbaar met `py tools/inspect_eap_contracts.py`. Geen firmwarecode uitgevoerd en geen netwerk/deviceverkeer verstuurd.

## Plugins uit de bootregistry

| Type | FriendlyName | Module | UI |
| --- | --- | --- | --- |
| 4 | MD5-Challenge | eapchap.dll | Username/password-dialog enabled |
| 26 | MSV2-Challenge | eapchap.dll | Username/password-dialog enabled; InteractiveUIPath=eapchap.dll |

De pluginloader `eap!c05d17f0` accepteert type 4..255 en leest `HKLM\Comm\EAP\Extension\<type>`. Hij reserveert `0xc70` bytes, leest configuratie, laadt `Path`, vraagt `RasEapGetInfo(type,&info)` en roept de initcallback aan indien aanwezig. De pseudocode laat het tweede argument weg; de structinitialisatie/calls zijn statisch gevolgd. Plugins worden met referenties gecachet. UI-bibliotheken kunnen uit aparte registryvelden komen.

`eapchap!RasEapGetInfo c05e1c5c` accepteert uitsluitend 4 en 26 en vult een 24-byte proceduretable. Init is `c05e22d4`; Begin is respectievelijk `c05e17d0/c05e17f4`; End is `c05e1818`; MakeMessage is `c05e199c`. Andere types retourneren `0x32`.

## Sessies, callbacks en timers

`EapSessionCreate c05d2c84` vereist maxpacket 5..65534, padding<65535 en type>3, plus een callback passend bij server/clientmode. Allocatie is `0x150 + padding + maxpacket`. Het type wordt naar één byte gekopieerd, zodat de publieke constructor grotere typewaarden niet zelf afwijst; de latere pluginloader werkt met het opgeslagen byte. Defaulttimer 5000 ms, retransmitlimiet 10. Het record krijgt een critical section, timer, global-list-link en refcount 1.

`c05d210c` zoekt een sessie in de globale lijst en verhoogt haar referentie. Packetverwerking gebeurt onder de sessielock. `c05d32c8` laat de lock los vóór de callback en pakt hem daarna weer; de callback bevat packetpointer/lengte en eventuele completion/error. De overige concurrency-/lifetimepaden zijn nog niet volledig bewezen.

SetConnectionData/SetUserData kopiëren naar nieuwe heapbuffers. SetIdentity/SetPassword maken UTF16-stringkopieën. GetIdentity kan de plugin en username/password-UI gebruiken; het kopieert tijdelijk naar vaste lokale buffers. Langere publieke invoer en callergrenzen blijven een open contract. Reset beëindigt pluginstate, stopt/wist tussentoestand en zet twee ID-velden op FFFFFFFF. Destroy verwisselt callbacks voor een dummytable en laat sessiereferenties los.

MakeMessage-wrapper `c05d3370` geeft plugincontext, ontvangen packet, outputbuffer/maxpacket, een 64-byte outputrecord en sessioninput door. Plugincode `0x2d2` wordt door de engine naar een genegeerd packet vertaald. `c05d3748` vertaalt pluginactions naar verzenden, completion, UI en opgeslagen connection/userdata. Timers `c05d36e0/c05d34e0` herhalen het eerder gebouwde packet in de gevolgde initiale states, gebruiken een counter en eindigen bij uitputting. Volledige eventvolgorde en retry-countinterpretatie blijven open.

## EAP-parser en packagebouw

Leaf `c05d4364` bewaakt:

- Minstens vier ontvangen bytes; BE16 length≥4 en ≤ontvangen bytes.
- Code uitsluitend 1=Request, 2=Response, 3=Success, 4=Failure.
- Request/Response hebben minstens een vijfde Type-byte.
- Success/Failure hebben declared length exact 4.
- Type 3=Nak mag uitsluitend als Response, met precies één type-alternatief van waarde≥4.

De single-alternative-Nak-beperking is concreet; de algemene engine implementeert niet alle Nak-varianten uit [RFC 3748 §5.3](https://www.rfc-editor.org/rfc/rfc3748.html#section-5.3).

Request-handler `c05d3d28` bewaart laatste request-ID en kan een bestaande response herhalen. Type 1 gaat naar identity, type 2 naar notification, het geconfigureerde type naar de plugin. Een ander methodtype levert een zes-byte Nak met het voorkeurs-type. Serverresponse `c05d3f24` vergelijkt response-ID met de uitstaande ID en behandelt identity/Nak/plugin afzonderlijk.

**Notification-response heeft een bewezen lengtefout.** Assembly `c05d3e90..c05d3ecc` schrijft code=2, request-ID, length=4 en Type=2 op offset 4. De zendroute leest length uit die header en levert slechts vier bytes. De ontbrekende Type-byte maakt deze response ongeldig voor de eigen parser. Een geldige lege notification-response heeft vijf bytes volgens [RFC 3748 §5.2](https://www.rfc-editor.org/rfc/rfc3748.html#section-5.2). Het offline model toont zowel rejection van de originele `02 2a 00 04` als acceptatie van het gecorrigeerde voorbeeld `02 2a 00 05 02`. Er is geen patch gemaakt en het runtime-effect op een peer is onbekend.

## eapchap-context en MD5

Begin `c05e1714` maakt een nulgevuld `0x638`-record, kiest een bytewaarde 1..250 via `rand()`, slaat type op, converteert identity/password en levert de context terug. End wist alle `0x638` bytes voor LocalFree. MakeMessage `c05e199c` ondersteunt de client-request- en success/failure-paden; een ontvangen code 2 neemt het gevolgde foutpad.

Identityconversie `c05e15dc` gebruikt codepage-parameter 1 en maximaal 273 bytes inclusief terminator. Passwordconversie `c05e1668` gebruikt maximaal 257 bytes inclusief terminator en bewaart de lengte zonder NUL. Na omzetting wordt het wachtwoord omkeerbaar gemaskeerd.

**Passwordsetter test de pointer in plaats van het conversieresultaat.** `c05e16d0` test `$s1`, de reeds berekende destinationpointer, vóór GetLastError. Bij geldige context kan een mislukte WideCharToMultiByte dus als succes worden geretourneerd, met passwordlengte 0. Lange/ongeldige input en codepage-uitkomst zijn niet op de unit getest.

Masker `c05e2090` keert de string om en XORt bytes met de contextwaarde, behalve wanneer de als signed byte geladen waarde gelijk is aan de positieve key. `c05e2104` gebruikt dezelfde helper om weer te openen. Dit is omkeerbare obfuscatie voor gewone invoer, geen afzonderlijk cryptografisch transportprotocol.

De signed vergelijking veroorzaakt een concreet grensgeval: een geconverteerde niet-ASCII-byte gelijk aan een key 128..250 wordt toch XOR-ed naar NUL. De tweede bewerking gebruikt strlen en herstelt die byte niet. Van 63.750 synthetische single-byte/key-roundtrips falen precies de 123 overeenkomende gevallen. Welke tekens deze codepage op Max' unit produceert en of zo'n key/input ooit voorkomt is nog niet vastgesteld.

MD5-handler `c05e2270` bewaakt de challenge-value-size; `c05e2148` eist minimaal 17 outputbytes. Originele calls naar RSAENH tonen hashing van identifier, geopende passwordbytes en challenge. Response-data is `10` + 16-byte digest + identity indien die past. Als de identity niet past, wordt ze geheel weggelaten. MakeMessage zet daar een vijf-byte EAP-header met type 4 voor. De decompiler verloor verscheidene argumenten; assembly en synthetische MD5-modellen leggen de invoervolgorde vast.

## MS-CHAPv2 binnen EAP

Type 26 gaat van `c05e199c` naar `c05e3394`. Binnen de EAP-Type-Data zitten opcode, MS-CHAP-ID en een eigen BE16-length. Challenge, success, failure en password-change/UI hebben afzonderlijke branches. Responsebuilder `c05e2a74` maakt 16 random peerchallengebytes, acht nulbytes, response-data en flag, verpakt als 49-byte value met een voorafgaande value-size-byte. Identity volgt indien deze past. Domainprefix vóór backslash wordt voor een cryptografische helper weggelaten.

**De interne length heeft geen ondergrens 4.** `c05e33d8..c05e3428` controleert actual≥4 en innerlength≤actual, maar berekent bodylen als `(innerlength-4)&ffff`. Values 0..3 worden hierdoor 65532..65535. Challengehelper `c05e2fe8` vertrouwt op die afgeleide lengte en kan een value-size/copy toelaten buiten de feitelijke packetbytes. De buitenste EAP-parser controleert deze interne header niet. Dit is statisch bevestigd met 24 lengtemodellen; het daadwerkelijke leesgedrag, eventuele crash en callerbufferindeling zijn nog niet runtime onderzocht.

De volledige MS-CHAPv2-hashes, DES/SHA/MD4, authenticator-response, MPPE-keys, password-change en interactive-UI blijven open. Outer Success wordt pas geaccepteerd na de passende inner-success-state; `c05e3678` bewaakt states 4/6.

## Vendorattributes en MPPE

EAP-authattributes zijn 12-byte records `{type,length,pointer}`, beëindigd door type=0. Vendor-Specific gebruikt type 26 en data met BE32-vendor-ID, subtypebyte, lengthbyte, payload. `c05d4508` matcht vendor en subtype; `c05d45d0` bouwt zulke records.

`EapUtilExtractMPPEKey c05d478c` leest een keylengtebyte op VSA-dataoffset 8 en kopieert keybytes vanaf offset 9 wanneer keylen+9≤attribute length. Daarmee is de bron begrensd. De functie wist de uitgegeven length eerst en heeft geen output-capacityargument/check. Caller-/plugin-capacitygaranties moeten dus apart worden gevolgd; hier is geen overflow op de echte unit vastgesteld.

## Onderzoeksdekking

46 originele bytebereiken, twee registryregistraties, 7680 EAP-code/length/type-gevallen, 63.750 obfuscatiegevallen, MD5-capaciteitsmodellen, 24 interne MSV2-lengtegevallen en MPPE-brongrenzen zijn reproduceerbaar. Dit dekt geen volledige module: overige exports voor registry/UI, alle event-/cleanup-paden, MSV2-crypto en effectieve unitconfig blijven open.
