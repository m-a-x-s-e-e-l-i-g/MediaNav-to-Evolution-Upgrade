# MS-CHAPv2, MD4 en MPPE: gevolgde cryptografische contracten

Dit onderzoek verbindt de EAP-plugin, het directe PPP-pad en hun RSAENH-provider. De oorspronkelijke instructies en constanten zijn bewaard in [de JSON-evidence](firmware/mschap-crypto-contracts.json). De modellen voeren uitsluitend zelfgeschreven Python en een onafhankelijke cryptobibliotheek uit; er is geen firmwarecode uitgevoerd.

## Bronnen en reproduceerbaarheid

| ROM-module | SHA-256 |
| --- | --- |
| eapchap.dll | `01173e78734f818078914c152286716fdd3d46be38725ed87f52a825242a9a98` |
| ppp.dll | `b5f6bd4f0d8295e9203b3f92bd23a2920ecc086804f76caadb2e18d9e6d05df5` |
| rsaenh.dll | `f5877e9ec8b0771cf2d4f795ac19dcbabddd58146cf6ee751e1264cf05ab4e7e` |

```powershell
py -m pip install --target tools/vendor/crypto-models -r tools/requirements-crypto-models.txt
py tools/inspect_mschap_crypto.py
```

PyCryptodome 3.23.0 staat uitsluitend in de genegeerde lokale vendormap. Het script controleert eerst de firmwarehashes, bewaart 37 code-/databereiken en vergelijkt een eigen MD4-model voor 257 verschillende invoerlengtes met de onafhankelijke implementatie. Het controleert tevens twee DES-pariteitsvoorbeelden, tien wachtwoordgrensgevallen en drie MPPE-sleutellengtes.

## Challenge en response

| Contract | EAP-plugin | Direct PPP |
| --- | --- | --- |
| Eén aanroep MDbegin/MDupdate en 16-byte statekopie | `c05e2484` | `c043e8ec` |
| SHA1(peer16 + authenticator16 + ASCII-username), eerste 8 bytes | `c05e24f8` | `c043ea38` |
| Hash16 aanvullen tot 21 bytes, drie DES-blokken met elk 7-byte sleutelinvoer | `c05e23e0` | `c043edd4` |
| UTF16-wachtwoord, challenge en response samenvoegen | `c05e25bc` | `c043eafc` |

De registervolgorde, verschuivingen, lengtes en calltargets zijn handmatig tegen assembly gecontroleerd. Deze tabel beschrijft overeenkomende callcontracten; hij beweert geen identieke binaire functies. De username-helper hasht de aangeleverde ASCII-string; domain-prefixverwijdering gebeurt bij de caller, zoals beschreven in [EAP-contracten](eap-contracts.md).

RSAENH `1001acf0` spreidt de 56 sleutelbits over acht bytes en roept `1001e884` aan voor oneven DES-pariteit. `DES_ECB_LM` op `1001adfc` gebruikt deze sleutel via deskey/des. De MD4-compressieroutine `1001cbf8` bevat de drie MD4-rondes met hun rotaties en constanten; `MDbegin` op `1001cbb8` zet de vier standaard beginwoorden.

De openbare referentie uit [RFC 2759, sectie 9.2](https://www.rfc-editor.org/rfc/rfc2759.html#section-9.2) geeft in het onafhankelijke model exact:

| Uitkomst | Bytes |
| --- | --- |
| Challenge8 | `d02e4386bce91226` |
| PasswordHash | `44ebba8d5312b8d611474411f56989ae` |
| HashHash | `41c00c584bd2d91c4017a2a12fa59f3f` |
| NTResponse24 | `82309ecd8d708b5ea08faa3981cd83544233114a3d85d6df` |
| AuthenticatorResponse | `S=407A5589115FD0D6209F510FE9C04566932CDA56` |

Alle invoer in deze vergelijking is de gepubliceerde testdata, geen gegevens van de fysieke unit.

## Aangetoonde wachtwoordgrensfout

Beide wrappers roepen `MDupdate` precies eenmaal aan met bytecount verschoven met drie bits. Daarna kopiëren ze direct de eerste 16 bytes van de context; ze controleren de returnwaarde niet en doen geen aanvullende finalisatie.

RSAENH `1001d41c` verwacht een blokgerichte API met **bitcount**:

- Onder 512 bits: pad en finaliseer de boodschap; 448..511 bits gebruiken twee paddingblokken.
- Precies 512 bits: voer uitsluitend één compressieblok uit en laat de finalized-vlag nul. Een volgende afsluitende aanroep ontbreekt in de wrappers.
- Meer dan 512 bits: return 1 zonder compressie. De context houdt de vier beginwoorden; de wrapper kopieert ze als vermeende hash.

Voor een UTF16-wachtwoord betekent dit correcte hashing tot en met 31 code-eenheden, een onvolledige hash bij precies 32, en de vaste bytes `0123456789abcdeffedcba9876543210` vanaf 33. Verschillende lange wachtwoorden leveren in dit gevolgde contract dus dezelfde eerste hash. Een niet-BMP-teken gebruikt twee code-eenheden; dit is geen grens van 32 zichtbare tekens.

De afwijking is zichtbaar in de oorspronkelijke instructies (`1001d47c..1001d4a8`, `c05e24b0..c05e24d4`, `c043e918..c043e93c`) en in het onafhankelijke grensmodel. Dit bewijst het gedrag van deze callketen. Bereikbaarheid met lange ingevoerde wachtwoorden, eventuele hogere UI-limieten en het gevolg voor een echte verbinding zijn nog niet op een unit waargenomen.

Bij kortere invoer kopieert de provider tijdelijk één byte na de aangegeven boodschap om een eventueel gedeeltelijk bitbyte te bewaren; bij byte-uitgelijnde invoer overschrijft padding die byte. De gewone UTF16-string biedt daar zijn NUL-byte. Andere callers met exact bemeten buffers moeten afzonderlijk beoordeeld worden.

## Controle van de serverrespons

EAP-plugin `c05e2bd8` berekent SHA1(HashHash16 + NTResponse24 + magic39), gevolgd door SHA1(digest20 + challenge8 + magic41). De twee ASCII-constanten staan op `c05e50d4` en `c05e50fc`; hun lengtes zijn in de calls bevestigd. De formatter schrijft `S=` en twintig hoofdletter-hexbytes. Caller `c05e2d6c` vergelijkt 42 bytes met memcmp, dus de gevolgde vergelijking is hoofdlettergevoelig.

## MPPE-sleutels en EAP-attributen

`c05e321c` deobfusceert het wachtwoord, hasht het en hasht de 16-byte uitkomst opnieuw. Hij geeft HashHash16 en de context-NTResponse24 op `ctx+3b6` aan `c05e3080`.

`c05e3080` berekent een master van de eerste 16 SHA1-bytes. Vervolgens maakt hij twee directionele startsleutels met master16, zero-pad40, één van de twee magic84-constanten en F2-pad40. Alle vijf constanten en beide pads zijn byte voor byte gecontroleerd. Deze berekeningen en de rolbetekenis komen overeen met [RFC 3079, sectie 3.4](https://www.rfc-editor.org/rfc/rfc3079.html#section-3.4).

De outputvolgorde is belangrijk: magic3 gaat naar de eerste stack-outputarg, magic2 naar de tweede. Caller `321c` publiceert magic3 als Microsoft-vendor 311 subtype 16 (send), magic2 als subtype 17 (receive). Dat zijn de serverrichting-benamingen. Dit is een vastgesteld attribuutcontract; de interpretatie bij de PPP-caller en eventuele rolverwisseling moeten in de volledige CCP-initialisatie gevolgd worden.

Ieder payload is 34 bytes: twee nulbytes, keylength 16, sleutel16 en vijftien nulbytes. De vendorheader is zes bytes, zodat de volledige attribuutlengte 40 is. Dit is de lokale in-memory sleutelattribuutvorm; er is hier geen RADIUS-netwerkversleuteling uitgevoerd.

De openbare testdata levert master `fdece3717a8c838cb388e527ae3cdd31`, magic3-key `8b7cdc149b993a1ba118cb153f56dccb` en de apart bewaarde magic2-key in de JSON.

## PPP-keyupdate en RC4

`c043fc60` berekent SHA1(startkey + zero-pad40 + currentkey + F2-pad40), met keylength uit `keyctx+20`, en kopieert die lengte naar currentkey op `+10`.

`c0440000` gebruikt die nieuwe bytes vervolgens als RC4-key **en** als RC4-invoer om de volgende sleutel te maken. Voor optiebit `20` overschrijft hij daarna de eerste drie bytes met `D1 26 9E`. Tot slot initialiseert hij de RC4-context opnieuw met de resulterende sleutel. Dit is een latere keyupdate; hij mag niet worden verward met de eerste SHA-afleiding van de sessiesleutel.

`c04400a4` voert de encryptie op de meegegeven buffer uit, vernieuwt de sleutel wanneer het lage byte van `ctx+14` nul is en herinitialiseert RC4 afhankelijk van `ctx+10`. `c0440138` voert het ontvangende decryptiepad uit en haalt keyupdates in met een teller modulo 16. De volledige coherency-countbouw, optionbits en herstelvolgorde worden verder onderzocht.

RSAENH `rc4_key` (`1001e990..1001ea23`) bevat de 256-byte KSA; `rc4` (`1001ea24..1001ea8f`) bevat de PRGA met bewaarde indices op context `+100/+101`. De Python-RC4 is tegen de onafhankelijke bibliotheek vergeleken.

Alle drie sessiesleutels uit [RFC 3079, sectie 3.5](https://www.rfc-editor.org/rfc/rfc3079.html#section-3.5) komen exact overeen. De ciphertextvoorbeelden voor 40 en 128 bits komen ook overeen. **Het gepubliceerde 56-bit voorbeeld eindigt in `58`; beide onafhankelijke berekeningen eindigen in `B8`.** Deze afwijking is expliciet bewaard als referentiediscrepantie en wordt niet als firmwarefout geteld. De publicatie heeft daarnaast in die regel een 40-bit variabelenaam; een formele erratumstatus kon via de beschikbare webtool niet worden opgehaald.

## Resterend onderzoek

- Volledige CCP-optionkeuze, eerste keyinitialisatie en rolverdeling van EAP-attributen.
- Alle ontvangende compressie-/encryptieheaderchecks, coherency count, resetrequests en recovery.
- Password-change-protocol, randombronnen en alle CryptoAPI-providerfuncties buiten deze primitives.
- UI-invoergrenzen, daadwerkelijke credentials/configuratie en netwerkgedrag van de unit.

Deze evidence sluit het bovenstaande deel van de callketen af, niet de volledige modules of cryptografische stack.
