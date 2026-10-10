# AppMain Bluetooth-data: cache-aliases en singletonlifetime

Dit vervolg onderzoekt twee voorwaarden van de [acht-apparatenbasis](bt-pairing-storage-draft.md) en de [lijst-ACK-proef](bt-list-ack-draft.md): de overlappende naamcache en de geldigheid van dataobject/shared-bank. Er zijn geen firmwarebytes gewijzigd, executables geschreven of updates gebouwd.

## Provenance van cache-adressen

Uitvoeren: `py tools/inspect_bt_cache_aliases.py`. [Evidence](firmware/bt-cache-aliases/contracts.json) bevat de modulehash, oorspronkelijke bewijsbereiken, CFG-dekking, afgeleide objectevents en expliciete analysegaten.

De analyzer volgt 2.907 `.pdata`-bereiken plus drie handmatig begrensde leaves (`1108f0`, `11095c`, `113720`), samen 2.910 bereikentries. Hij volgt beide conditionele edges tenzij de conditie constant is, voert MIPS-delay-instructies uit en herkent stackspills, singleton `186560`, manager `187be4` → veld `+a0` en getter/constructor. Callersaved registers worden na calls ongeldig gemaakt. Verschillende offsets worden verbreed naar een expliciet onbekende objectoffset. Methode-entrytypes zijn aannames: dit is een kandidateninventarisatie, geen complete type-/aliasproof.

Er zijn zeven exact afgeleide cache-events, allemaal in drie oorspronkelijke functies:

| Functie | Instructies en betekenis |
| --- | --- |
| Constructor `110010` | `1100a4`: pointer `this+3b0`; `1100ac`: 500-byte memset-destination |
| Copy `110708` | `110754`: conversiepointer `this+3b0`; `110820`: vijfde argument van MultiByteToWideChar; `1108a8`: stap van 100 bytes |
| Reset `113d40` | `113d6c`: pointer `this+3b0`; `113d74`: 500-byte memset-destination |

De conversiecall gebruikt IAT `185088`, COREDLL ordinal 196. Geen exact cache-load, persistent opgeslagen cachepointer of geretourneerde cachepointer is in deze provenance-events gevonden. Dat is uitsluitend de uitkomst van deze begrensde analyse.

Er blijven **291 onbekende-offsetevents in 23 functies**: onder andere geïndexeerde raw-recordnamen, lookup/copy/renderlussen en veel grotere phonebook/mediaregio's. Hun indexinvarianten volgen niet uit deze abstracte analyse. Ook 205 computed jumps, 1.423 calls, vier special-instructies en één buitenbereikedge blijven onopgelost. Andere niet-pdata/indirect-only code, objectgeladen pointers en interprocedural geheugen ontbreken. Alle gaten staan met bronwoorden in de evidence. De drie bekende cachevormen bewijzen dus nog niet dat alle indirecte readers ontbreken.

## Native singleton- en foutpaden

Uitvoeren: `py tools/verify_bt_data_lifecycle.py`. [Evidence](firmware/bt-data-lifecycle/contracts.json) bewaart oorspronkelijke AppMain-/ROM-bytes, vtable-entry, direct-callinventarisatie en gekoppelde traces. Firmware-instructies worden geïnterpreteerd; heap/mapping/close/free zijn OS-fixtures. Grote succesvolle zero-calls zijn intervalevents; de relevante record/cachebytes worden werkelijk in fixture-RAM gewist.

`1103a4` beheert singleton `186560`. De hoofdallocatie vraagt **`0x15947c` bytes**; dit is een grootte, ondanks de misleidende decompiler-stringannotatie op hetzelfde getal. Constructor `110010` initialiseert onder andere raw-records, 500 cachebytes en buffers van `0xb8920`, `0x42680` en 4.000 bytes. Managerconstructor `114518` bewaart de geretourneerde objectpointer in `+a0`.

De verifier volgt 24 constructorcases, twaalf destructorcases en zes ontbrekende-shared-consumercases, verdeeld over origineel, acht-recordbasis en ACK-proef. De volgende defecten bestaan in alle drie; de eerdere pairingwijzigingen repareren ze niet.

### Hoofdallocatiefailure bereikt store op adres acht

Wanneer operator-new nul retourneert, gaat de oorspronkelijke nullbranch alsnog naar mappinghelper `11b06c` met subobjectadres vier. Deze helper schrijft de CreateFileMapping-uitkomst op `4(subobject)`, dus **adres acht**, bij `11b0b4`. De trace stopt vóór die lage write. De singleton blijft nul en heapinitialisatie is niet uitgevoerd. Dit bewijst het pad bij de allocatiefailurefixture, niet de failurefrequentie op de unit.

### Object zonder shared-map/view wordt toch teruggegeven

`11b06c` probeert BlueEarth met size nul te openen en bij failure nogmaals met `0x13d620` bytes. Viewfailure sluit en wist de handle. De getter verwerkt de BOOL van deze helper niet en retourneert het dataobject met `+c=0` en `+8=0`.

Na deze native producent zet de fixture een latere ontvangen count één. Copy `110708` → getter `11afcc` bereikt dan een **read op adres nul**, zowel oorspronkelijk als in de basis/ACK-proef. De producer/copyinstructies worden uitgevoerd; de latere count en timing zijn geïnjecteerd. Dit is het concrete pad achter de ontbrekende NULL-guard, geen waargenomen live IPC-fout.

### Aanvullende allocatiefailure bereikt ROM-memset op NULL

De drie aanvullende allocationreturns worden niet gecontroleerd. De getter registreert het object vóór reset `113d40` → `113dac`. Een ontbrekende eerste of tweede buffer bereikt daarna memset op NULL met respectievelijk `0xb8920` of `0x42680` bytes. De gekoppelde ROM-instructies bereiken werkelijk de eerste store op adres nul in de interpreter. De derde ontbrekende buffer blijft op nul zonder in dit resetpad te worden gebruikt; de getter retourneert het object alsnog. Die bufferconsumers blijven open.

COREDLL ordinal 1047, `memset`, loopt hier op **`4007be0c..4007bfa4`**. PE ImageBase `40010000` plus export-RVA `6be0c` bepaalt de entry. De evidence bewaart de leafbytes en controleert de oorspronkelijke exportbinding. 160 CRT-cases toetsen alignment nul tot drie, lengtes nul/1/2/3/4/31/32/33/64/65, bytewaarden, guards en ABI. Het NULL-pad stopt vóór de eerste lage store; er is niets op host of unit geschreven.

De geregistreerde singleton blijft na de gestopte initialisatiefixture staan. Een expliciet nieuwe getteraanroep retourneert dezelfde pointer zonder nieuwe initialisatie. Dat is een fixture-retry, geen bewijs van echte exceptionrecovery of bereikbaarheid na een live crash.

### Destructor herintreedt via zijn eigen singleton

Vtable `176b18` wijst naar deleting-destructor `1102a8`, die body `110478` aanroept. Deze body leest singleton `186560` en roept zijn eerste vtable-entry aan **voordat** zij de global wist. Als de global nog dit object aanwijst, volgt `1102a8` → `110478` → vtable `1102a8` → `110478` → …

De native trace volgt drie doorgangen naar een volgende destructor en stopt bij de vierde body-entry. Het stackadres daalt telkens `0x40` bytes; de global blijft staan en unmap/close/free worden niet bereikt. De onderbroken trace claimt geen ABI-herstel of echte stack-exhaustion. Met vooraf gewiste singleton keert dezelfde native destructor terug: twee unmaps, twee closes en optioneel free, met bewaarde ABI.

De inventarisatie vindt één directe bodycall vanuit `1102a8` en drie directe gettercallers, maar geen directe call naar `1102a8`. De vtable-entry/self-route zijn bewezen; de buitenste destructortrigger, shutdownbereikbaarheid en failurefrequentie blijven open. Dit is geen waargenomen live destructorcrash.

## Vervolg naar een bruikbare update

De cache-inventarisatie is uitgebreid maar nog niet afgesloten. Object/shared-failures vereisen guards en passende cleanup/recovery vóór integratie: een geldige count-ACK beschermt niet tegen een ontbrekende AppMain-mapping. Ownership, ongecontroleerde heapconsumers en de 23 onbekende-offsetfuncties moeten verder gevolgd worden. Originele bestanden, basis-/ACK-varianten en MAX02 blijven ongewijzigd; deze onderzoeken geven geen LGU-buildvrijgave.

De [afzonderlijke safe-copy-proef](bt-safe-copy-draft.md) maakt de nonempty NULL-consumer inmiddels lokaal afhandelbaar: hij retourneert failure met lege raw-lijst en zonder actieve/PB-verwijzing. De oorspronkelijke producerfailure wordt opnieuw gevolgd tot deze nieuwe copy. Calleronderzoek reproduceert daarnaast een UI-store buiten de recordbank en een profielzoekroute naar een ontbrekende positie; beide hebben aparte guards. Object-/heapallocatie, mappingrecovery, destructorownership en cache-aliases blijven open; de oorspronkelijke lifecyclevarianten hierboven zijn niet aangepast.
