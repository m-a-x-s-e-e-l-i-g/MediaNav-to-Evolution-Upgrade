# CCP, MPPE-pakketstate en sleutelrichting

Vervolg op [PPP-negotiatie](ppp-negotiation-contracts.md) en [MS-CHAPv2/MPPE-crypto](mschap-crypto-contracts.md). Originele ROM-ppp.dll SHA-256 `b5f6bd4f0d8295e9203b3f92bd23a2920ecc086804f76caadb2e18d9e6d05df5`. [JSON-evidence](firmware/ppp-ccp-contracts.json) bewaart 30 originele code-/tabelbereiken en onafhankelijke offline modellen. Reproduceer met `py tools/inspect_ppp_ccp.py`. Geen firmwarecode uitgevoerd.

## Onderhandeling en mogelijkheden van deze build

Constructor `c043f058` maakt een nulgevulde context van `6694` bytes, registreert CCP `80fd` en data `00fd`, en beperkt encryption-capabilities uit session `+b28` tot `60`. De verplichte encryptiecase (entrybits `1800` beide gezet) faalt met `57` wanneer die capabilities nul zijn. Compressie krijgt lokale support bij entrybit `200`.

De 32-byte optiedescriptor op `c044d760` bevat ID 18 en payloadgrootte 4; de volledige wireoptie is daarmee zes bytes. Zijn callbacks zijn:

| Descriptoroffset | Target | Gevolgd contract |
| --- | --- | --- |
| +08 | f954 | Bouw eigen vier-byte big-endian voorstel |
| +0c | f9a8 | Verwerk Configure-Ack |
| +10 | f9fc | Verwerk Configure-Nak |
| +14 | 0 | Geen eigen Reject-callback |
| +18 | faa0 | Beoordeel peer Configure-Request |
| +1c | f7b8 | Formatteer logtekst |

Dit zijn leaf-functies die niet allemaal in .pdata of de pseudocode-export stonden. Hun grenzen zijn nu uit de oorspronkelijke assembly gevolgd en afzonderlijk bewaard. Het resultaat laat zien waarom een volledige automatische export niet gelijkstaat aan volledig onderzocht gedrag.

De peer-requesthandler accepteert compressiebit `1` alleen wanneer entrybit `200` dat toestaat. Hij intersecteert aangeboden encryptiebits met de lokale mask en kiest `40` (128 bits) wanneer `20` en `40` allebei voorkomen. Bij verplichte encryptie en geen gemeenschappelijke keuze voegt hij lokale encryptiecapabilities aan de Nak toe. Een exact gelijk voorstel krijgt code 2/Ack en wordt als TX-opties op `ctx+c` opgeslagen; anders volgt code 3/Nak met de aangepaste vier bytes.

Concrete voorbeelden bij lokale capabilities `60`:

| Aangeboden payloadwaarde | Uitkomst bij niet-verplichte encryptie |
| --- | --- |
| 00000040 | Ack: 128 bits |
| 00000020 | Ack: 40 bits |
| 00000060 | Nak: 00000040 |
| 00000080 | Nak: 00000000 |
| 01000040 | Nak: 00000040 |

De laatste twee tonen dat 56-bit en stateless niet in het gevolgde onderhandelingspad worden ondersteund. `f7b8` kan die namen wel loggen. Dat is geen bewijs dat hun data-implementatie actief is. De bitbetekenissen zijn vergeleken met [RFC 3078, sectie 2](https://www.rfc-editor.org/rfc/rfc3078.html#section-2).

De Nak-handler doet eveneens een beleidsfilter en kiest bij beide encryptiebits de sterkere. De Ack-handler retourneert `28c` en wist de 40-bit-keuze als toch beide encryptiebits bevestigd worden. De generieke FSM controleert daarnaast dat de Ack de oorspronkelijke requestbytes exact weerspiegelt.

## Context en lifecycle

| Contextoffset | Gevolgd gebruik |
| --- | --- |
| 0000 / 0004 | Session / gedeelde CCP-FSM |
| 0008 / 000c | RX-/TX-opties |
| 0010 | TX flush-pending |
| 0014 | TX coherency count, 12 bits |
| 0018 | Zendende MPPC-state |
| 4664 | Verwachte RX coherency count, WORD |
| 4668 | Ontvangende MPPC-state |
| 6670 | Wacht op herstel/flush |
| 6674 | Huidige RX-keyepoch, modulo 16 |
| 6678 | Lokale encryptiecapabilities, mask60 |
| 667c / 6680 | TX-/RX-keycontext pointers |
| 6688 | Reset-Request-ID-byte |
| 668c / 6690 | Tijdelijke gedecomprimeerde buffer / capaciteit |

`ef34` initialiseert beide MPPC-states, zet de eerste TX-flush en nulmaakt counters/wachtstate. Hij maakt indien nodig keycontexts voor RX met richtingsargument 0, TX met 2. `05c0` alloceert een keycontext van `134` bytes, bewaart optieflags op `+12c`, voegt rolebit 1 toe als session `+6c` niet nul is en roept `0440` voor de keyinitialisatie aan.

`f1f8` maakt de ontvangen decompressiebuffer op basis van de via LCP opgehaalde MRU plus `40` bytes. Een ontbrekende buffer haalt compressie uit het eigen voorstel via `f954`. Volledige allocatie-/shutdownraces en de inhoud van iedere MPPC-state blijven apart onderzoek.

## Sleutelinitialisatie en EAP-koppeling

`0440` kiest acht keybytes wanneer 40-bit-optie `20` is gezet; anders zestien. Hij alloceert een SHA-context van `5c` bytes. Authprotocol CHAP `c223`, algorithm 128 gaat naar de oudere MS-CHAP-keyafleiding; algorithm 129 gaat naar `02d8`. EAP `c227` gaat naar `0360`.

Direct MS-CHAPv2 `02d8` gebruikt UTF16-wachtwoord op session `+408`, HashHash16 en NTResponse op authcontext `+5cd`. Na de masterafleiding kiest `fea4` de directionele magic: rolewaarden 0/3 gebruiken magic3, 1/2 magic2. Daarmee heeft de normale clientcase RX=magic3, TX=magic2; de andere rolecase draait dat om. Vervolgens wordt de eerste sessiesleutel met `fc60` afgeleid. Acht-byte sessiesleutels krijgen de 40-bit-prefix `D1 26 9E`, waarna RC4 wordt geïnitialiseerd.

EAP callback `b678` kopieert vendor311 subtype16 naar session `ae0`, lengte `b00`; subtype17 naar `b04`, lengte `b24`. Beide extractie-returnwaarden worden op dit pad genegeerd. `0360` selecteert subtype16 voor richtingbit 2 (TX) en subtype17 voor RX. Hij padt korte keys links met nullen, kapt lange keys af tot de keylength en geeft `273` bij ontbrekende keylengte.

De EAP-plugin uit het crypto-rapport geeft subtype16=magic3, subtype17=magic2. De hier gevolgde keten gebruikt dus TX=magic3/RX=magic2. Dat verschilt van de directe MS-CHAPv2-clientcase. **Dit is een concrete discrepantie die nog moet worden verklaard:** de precieze rol/configuratie waarin deze EAP-plugin op de unit gebruikt wordt en de interoperabiliteit zijn niet waargenomen. De extractie en CCP-selectie zelf zijn geen open vraag meer.

## Zendpad

`f5b0` vereist Opened-state 9 en niet-nul TX-opties. Bij ontbrekend CCP doet entrybeleid de keuze tussen doorlaten en weigeren. Op het actieve pad duwt hij eerst de oorspronkelijke PPP-protocolwaarde als twee big-endian bytes vóór de payload en verandert de buitenste protocolwaarde in `00fd`.

Hij bewaart de huidige coherency count voor de header en verhoogt de contextcount modulo 4096. Bij compressie maakt hij zo mogelijk een tweede packetbuffer en roept MPPC `065c` aan. De returnflags bepalen of de gecomprimeerde buffer behouden wordt. Een ontbrekende extra buffer kan tot een ongecomprimeerde maar versleutelde fallback leiden, met MPPC-reset en flushflag.

Daarna versleutelt `00a4` de volledige huidige payload, inclusief het ingesloten protocol. Encryptieflag `1000` komt in de header. Flush-pending veroorzaakt herinitialisatie van RC4 en wireflag `8000`; de pendingflag wordt vervolgens nul. Tot slot schrijft hij de twee-byte big-endian CCP-header vóór de payload.

De keyupdate geldt wanneer het lage byte van de **al verhoogde** TX-count nul is. Voor de gepubliceerde packetcounts gebeurt dat dus bij count `0ff`, `1ff`, enzovoort. Bij iedere update volgen SHA-afleiding, RC4 over de nieuwe key, eventuele 40-bit-prefix en een nieuwe RC4-context.

## Ontvangst, pakketverlies en herstel

`f364` eist FSM-state 9 en minstens twee payloadbytes. Hij leest de CCP-header big-endian, verwijdert die bytes en volgt deze volgorde:

1. Bij flushflag `8000`: met encryptie worden flushes geweigerd als `(received-expected)&fff >= f00`. Anders initialiseert hij RC4 opnieuw, reset zo nodig MPPC en neemt de ontvangen count als verwachte waarde over; wachtstate wordt nul.
2. Alleen als wachtstate nul is en count exact gelijk is, verhoogt hij expected modulo4096.
3. Bij encryptieflag `1000` roept hij `0138` met de resterende buffer/omvang aan. Die haalt keyupdates in totdat de high byte van de verhoogde count overeenkomt met epoch `6674`, modulo16.
4. Bij compressieflag `2000` is lokale RX-compressie vereist. `1144` decodeert; failure veroorzaakt een Reset-Request en wachtstate. Output groter dan de MRU-buffer wordt gedropt.
5. De resterende/gedecodeerde payload gaat naar de gewone PPP-protocolrouter.

Een teller-mismatch of actieve wachtstate zet wachtstate en roept `f318` aan. Die verzendt CCP code14, verhoogde ID en length4. De extra-codetabel op `d6d8` koppelt ontvangen Reset-Request14 aan `f2f4`: zet TX-flush-pending en reset de zendende MPPC-state. Code15 heeft een aparte callback; de generieke herstel-/timersemantiek is nog niet volledig onderzocht.

Het gevolgde RX-pad kiest decryptie via de wireflag. Een passend ongecomprimeerd pakket zonder encryptieflag bereikt eveneens de protocolrouter. Dat is vastgelegd als handlercontract, zonder te claimen dat een willekeurige dergelijke payload een geldig IP-pakket is of op de unit geaccepteerd wordt.

De wirelayout en volgorde zijn vergeleken met [RFC 3078, sectie 3](https://www.rfc-editor.org/rfc/rfc3078.html#section-3). De implementatie gebruikt stateful encryptie; de loggingnaam voor stateless verandert dat niet.

## Onafhankelijke modellen en grenzen

De tool controleert 12.288 onderhandelingscombinaties en 28.672 flush/countgevallen. Acht synthetische streams bevatten samen 72.000 packets voor 40 en 128 bits: normaal verkeer en verlies bij counts255,300,4095. De modellen simuleren de Reset-Request/flush en controleren elke afgeleverde plaintext en dezelfde TX-/RX-key, inclusief twee telleromslagen. Elk streammodel maakt 35 keyupdates.

Deze checks tonen dat de gereconstrueerde stateful berekeningen onder deze scenario's samen kunnen werken. Ze zijn geen emulatie of uitvoering van de originele MIPS-code, geen verificatie van MPPC en geen bewijs van EAP-clientinteroperabiliteit. Open: volledige compressie/decompressie, alle FSM-events, allocatiefouten, timeouts/races, effectieve unitconfig en de EAP-roldiscrepantie.
