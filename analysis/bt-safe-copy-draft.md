# Acht Bluetooth-koppelingen: begrensde lijstkopie en callers

Deze **afzonderlijke interpreterproef** bouwt verder op de acht-recordbasis en count-ACK-proef. Er wordt geen executable/LGU geschreven; `build_allowed` blijft false. De originele bestanden, eerdere varianten en MAX02 blijven gelijk. Acht betekent acht opgeslagen koppelingen; het aantal gelijktijdige radioverbindingen verandert niet.

Uitvoeren: `py tools/verify_bt_safe_copy.py`. De [evidence](firmware/bt-safe-copy-draft/contracts.json) bewaart oorspronkelijke bronbereiken, gepinde edits, failurewitnesses, gekoppelde traces en toolhashes. [De patchhelper](../tools/draft_bt_safe_copy.py) wijzigt uitsluitend bestaande codebereiken, met behoud van PE-lengte, oorspronkelijke frames/epilogen en `.pdata`. Dat is geen native unwindbewijs.

## Kopie bij ontbrekende of veranderde lijst

De oorspronkelijke `110708` kan na native mappingfailure met count groter dan nul naar adres nul lezen. Dat is [eerder met de echte singleton/mappinginstructies gereproduceerd](bt-data-cache-lifecycle.md). De nieuwe leafbody controleert count nul tot acht en vereist bij een niet-lege lijst een niet-nulle shared-base. Een lege lijst mag zonder mapping worden verwerkt.

De body kopieert of wist precies acht records van 64 bytes naar `CBtData+270..470`. Ongeldige count of ontbrekende niet-lege bank geeft BOOL nul, zet count nul en wist alle acht records. Bij iedere invocation worden actieve index en pointer eerst gewist. Zonder actieve record wordt ook PB-status `+5ac` gewist. Een geldige lijst met actieve record bewaart die PB-status voor de bestaande PB-consumer. Zowel HFP- als mediaflag gelden; net als de oude copy wint de laatste actieve record. De aparte scan behoudt zijn bestaande keuze voor de eerste actieve record.

De oude overlappende UTF-16-cacheconversie was al in de acht-recordbasis uitgeschakeld. Deze proef herintroduceert haar niet. Naamconversie blijft bij de raw-recordconsumers. De afwezigheid van alle indirecte cachelezers is nog niet bewezen.

## Schermcode schrijft anders buiten de recordbank

Een tweede fout bestaat ook met een geldige mapping. De renderer `cfcb8` ziet vóór reload een actieve record met status vier of zeven. Na native copy leest hij opnieuw index `+5a4`, maar valideert die niet vóór de status-store. Wanneer de nieuwe lijst leeg is of geen actieve record heeft, is die index −1. De berekening schrijft vervolgens één byte naar **object+232**, buiten de raw-recordbank.

Zes begrensde voor/na-traceparen modelleren lege/no-active/NULL-publicatie bij beide statuses. Vier baselineparen reproduceren de concrete store naar `+232`; de twee NULL-baselines stoppen eerder bij de low-read. In de nieuwe variant worden beide post-copy statusstores gedeeld en wordt de index vóór de write begrensd tot nul t/m zeven. Alle zes nieuwe traces bereiken de continuation zonder geïndexeerde store.

De gedeelde guard gebruikt het behouden `a0`-objectargument: de nieuwe copybody bevat geen calls en verandert `a0` niet. Dat behoud wordt in de copycases expliciet gecontroleerd. De rendererprefix heeft vanaf de oorspronkelijke objectload tot deze stores geen andere call dan copy. Volledige geldige render/reloadtraces blijven apart gecontroleerd. Publicatie bij de tweede copy-entry is een inputfixture; dit is geen bewijs van een specifieke CE-race of een waargenomen unitcrash.

## Profielzoekroute kan een ongeldige connectindex sturen

De caller bij `11d250` zoekt namen met de eerdere managercount `+28`, hoewel de native naamhelper iedere index tegen de actuele objectcount `+26c` controleert. Buiten die count geeft de helper de literal `Empty` terug. Een naamvergelijking met `Empty` kan daardoor matchen op een niet-bestaande positie en alsnog commando `1010804` sturen.

De native suffixbaseline reproduceert een connectparameter één bij actuele count nul/eerdere count acht. Bij actuele count één en naam `Other` wordt de ontbrekende tweede positie als `Empty` gematcht: connectparameter twee. Een mismatchfixture volgt bovendien acht helperindices ondanks actuele count nul of één. Dit zijn concrete suffixtraces met een expliciete gewenste naam; de volledige aanloop en frequentie op de unit zijn niet vastgesteld.

De nieuwe caller leest na copy/scan/PB-read de genormaliseerde objectcount, stopt bij nul en zoekt uitsluitend bestaande records. De managerpointer in `s0` blijft volgens de oorspronkelijke native helpers callee-preserved. Een werkelijk aanwezige record met de naam `Empty` blijft correct verbinden. De connectcaller bij `115c60` las al de actuele count na copy; acht failure/empty-suffixtraces tonen dat hij de zoeklus overslaat en naar de oorspronkelijke epiloog gaat.

De list-endcallback `121630` bewaart nu het copyresultaat in stateveld `+628`. Bij een ontbrekende bank en een niet-lege countmelding wordt dat nul en is de lokale lijst leeg; de bestaande physical-HFP-clearing blijft afhangen van de oorspronkelijke messagecount. Veld `+628` heeft andere writers en is geen algemene freshnessflag.

## Verificatie

| Controle | Resultaat |
| --- | --- |
| Copy/count/flags/NULL | 368 cases: count nul t/m acht, iedere/geen/meerdere actieve posities, HFP/media, NULL/non-NULL en vier ongeldige counts |
| Krimp na acht records | 18 cases: oude slot-zevenflag blijft fysiek aanwezig, nieuwe count nul t/m acht; tail en stale actieve verwijzingen gewist waar nodig |
| Native list-endcallback | 12 cases: geldig/leeg/ongeldig/NULL, echte resultstore en bestaande HFP-state-uitkomst |
| Rendererfailure | Zes voor/na-paren: negatieve-indexstore/NULL-read gereproduceerd en guard bereikt |
| Geldige UI | 122 volledige copy/renderertraces: iedere pagina/actieve positie, Unicode-namen en statusreloads |
| Mappingproducer → copy | Twee traces: echte CreateFileMapping/MapViewfailure met geïnjecteerde latere count acht; copy keert nu met failure terug |
| Blue → native HFP | 222 geldige gekoppelde traces: count nul t/m acht, iedere selectie, popup/gewone entry en notificationtransports |
| NULL HFP-consumer | 18 gekoppelde traces: counts één/vijf/acht, beide entries, success/timeout/retry; geen PB-open, actuele count nul en progress-cleanup |
| Database-/ACK-failure | 14 gekoppelde traces behouden de eerdere HFP-failureguards |
| Profielzoekroute | Zes voor/na-suffixparen: empty/short/naam-match/mismatch/NULL; geen connect naar ontbrekende positie |
| Andere connectcaller | Acht empty/NULL/invalid-suffixtraces slaan naamzoeklus over |

Copycases bewaken alle shared reads en writes in de objectregio, vergelijken volledige raw bytes en controleren frame, saved-registers en `a0`. API-, heap-, transport-, gewenste-naam- en mappingfixtures blijven expliciet. Native suffixwitnesses stoppen vóór de buitenste epiloog en claimen geen volledige caller-ABI; de volledige UI/HFP-traces controleren terugkeer afzonderlijk.

## Grenzen vóór integratie

Een niet-nulle bank is nog slechts een pointerfixture: mappinglengte, lifetime, gelijktijdige writes en snapshotgeneratie zijn niet bewezen. Een welgevormde stale ACK blijft geaccepteerd. De ongecontroleerde object-/heapallocaties en destructorherintreding zijn hiermee niet gerepareerd. Cache-aliases, volledige profiel-/connectaanloop, atomisch DB-herstel, acht-device CSR/keycapaciteit en native unitgedrag blijven open.

De AppMain-proef wordt opgebouwd boven ACK-SHA `c89f3b16c2f3a62b12e66501966957d38c4a0c4a04088f37b5596ae67d306d4a`; zijn actuele SHA staat in de reproduceerbare evidence. Blue blijft de afzonderlijke ACK-variant `ddeca3721a3efdd908fac58ef5072071bd8c3bbbe3b9da5715ee16e985cda2e2`. Er is geen MAX03 of nieuwe pairing-LGU. Samenvoegen met playback/nav vereist nog verdere verificatie en unitmetingen.
