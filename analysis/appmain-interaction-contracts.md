# AppMain interactie, popup-timers en USB-seek

Ontwikkelvervolg: [outside-release-cancellation](media-responsiveness-development.md) gebruikt de bestaande move/cancelroute voordat pressedstate wordt gewist. 117 actual-byte checks incl. originele window-up/timers en USBscreen-seek-stop-IPC slagen. Native touchdriver/lifetime open; oorspronkelijke analyse hieronder blijft behouden.

Vervolganalyse: [USB-muzieklijst, repeat/shuffle en DirectShow](usb-playlist-contracts.md) identificeert inmiddels de COM-interfaces en graphcreatie; volledige playback-lifecycle en hardwaregedrag blijven open.

Dit onderzoek koppelt de gedeelde buttoncallbacks aan de USB-muziekschermcommando's en de seek-engine in MgrUSB. Bronhashes, 43 oorspronkelijke bewijsbereiken, negen GUI-vtables en offline traces staan in [het bewijsbestand](firmware/appmain-interaction-contracts.json). Native applicaties en hardware zijn niet uitgevoerd.

## GUI-controltypen

De vtablebytes onderscheiden vier labelvarianten en vijf button-/sliderfamilies. De adressen hieronder zijn oorspronkelijke AppMain-VA's; namen zijn beschrijvende reconstructies.

| Vtable | Variant | Tekenroutine `+0x34` | Tekstsetter `+0x38` |
| --- | --- | --- | --- |
| `17cba8` | Gewoon label | `139b94` | `139718` |
| `17cbe4` | Label met gemarkeerde substring | `13a0d4` | `139718` |
| `17cc20` | Label met ingevoegde bitmap | `13c3cc` | `139718` |
| `17cc60` | Label via eigen offscreen-DC/bitmap | `13bc9c` | `139718` |
| `17cdd8` | Basisbutton | `13e7ec` | Anders gebruikte slot |
| `17ce10` | Button met tekst | `13ecec` | Anders gebruikte slot |
| `17ce4c` | Afgeleide tekstbutton | `13f258` | Anders gebruikte slot |
| `17ce88` | Alternatieve bitmapbutton | `13ea34` | Anders gebruikte slot |
| `17cec4` | Slider | `13f598` | 0 |

De eerste vier delen virtual draw-wrapper `139ac0`, die via slot `+0x34` tekent en vervolgens zichtbare childcontrols afloopt. Offscreen-init `13bbb4` maakt een compatible DC/bitmap, selecteert de bitmap en bewaart het vorige object op `+0x2b4`. Dit type alleen als een scrollcontrol benoemen was te stellig; timer- of marqueegedrag is daarmee niet bewezen.

De bitmap-insertionvariant gebruikt resource-ID `0xb`, pixelmaten in bytes op `+0x2b1/+0x2b2` en een optionele UTF16-splitpositie in de lage byte op `+0x2b0`. Zijn setter `13c204` accepteert gewijzigde tekst alleen als gemeten tekstbreedte plus bitmapbreedte strikt kleiner is dan de controlbreedte. Vlaggen `0x01000000`, `0x02000000` en `0x04000000` veranderen het insertionpad en de behandeling van RTL-tekst. Complete callersemantiek blijft open.

Alternatieve tekenroutine `13cbc4` scant wel Arabische/Hebreeuwse tekst maar gebruikt het resultaat niet om bit `0x20000` toe te voegen: assembly `13cd38..13cd78` geeft alleen het bestaande format op `+0x64` door. Een caller kan dat bit zelf al zetten; het verschil met automatische detectie in `139b94` is bewezen, zichtbare runtimeproblemen nog niet.

## Tap en lange druk

Dialogconstructor `134a70` zet eerste-delay `+0x84` op 700 ms en repeat-delay `+0x88` op 200 ms. Dit zijn defaults; screen-code kan ze overschrijven.

Button-down `13e554` vereist enablebit `0x100` en een inclusief hitrect. Hij zet pressedveld `+0x30`, roept de screen-downcallback op vtable `+0x48` aan en selecteert de control via `13cf30`. Als controltype 3 en repeatveld `+0x38` actief zijn, start timer `0x3f6`.

Dialog-dispatch `134ed0` handelt de timers af:

| Moment | Timer/bron | Callback op screen-vtable `+0x44` |
| --- | --- | --- |
| Loslaten binnen de knop, vóór eerste timer | Up | Actie 2 |
| Eerste holdtimer | `0x3f6` | Actie 3; zet repeatstate en start `0x3f7` |
| Volgende holdticks | `0x3f7` | Actie 4 |
| Loslaten of bewegen buiten de knop na holdstart | Up/move | Actie 5 |

`13e6f8` annuleert pressedstate wanneer een move buiten het hitrect valt. `13cf30` met nulselectie stopt beide timers en wist de repeatstate. De handler van een later reeds aangeboden timer ziet dan nulselectie en start geen nieuwe holdactie. Op exact de holdgrens hangt tap versus holdstart/holdend af van de eventvolgorde; het model veronderstelt geen exacte Windows-timerplanning.

**Voorwaardelijk foutpad:** `13e620` wist pressedstate vóór de hitcheck, maar annuleert selectie/timers alleen als de up binnen de knop valt en het event-ID geldig is. Komt een up buiten de knop zonder voorafgaande annulerende move, dan kan de selectie blijven staan. Timerhandlers controleren selectie en repeatveld, niet pressedstate. Het offline pad down → outside-up → eerste timer → repeat levert daardoor acties 3 en 4 na loslaten. De benodigde eventvolgorde op de fysieke touchdriver is nog onbewezen.

`135c58` kan bij drag over andere buttons opnieuw hun downslot aanroepen, maar alleen wanneer dialogveld `+0x64` en buttonveld `+0x44` actief zijn. De default voor het dialogveld is nul. Een niet-nul selectie direct vervangen annuleert de oude repeat-timer niet in `13cf30`; schermconfiguraties en concrete overgangseffecten blijven open.

## USB-scherm naar MgrUSB

Initializer `4c26c` maakt repeatbuttons met events `0x3ea` en `0x3ec`, op objectoffsets `0x148c` en `0x1578`, en zet hun repeatvelden op 1. De rechthoeken zijn `(361,293,139,83)` en `(634,293,139,83)`. Screen-handler `4d00c` is door de oorspronkelijke `CUSBMainDlg::onBtnClick`-logstrings geïdentificeerd.

| Schermactie | UI-event | Actie 2, tap | Actie 3, holdstart | Actie 5, holdend |
| --- | --- | --- | --- | --- |
| Vorige/terug | `0x3ea` | Extern commando 100 | `0x68` | `0x69` |
| Volgende/vooruit | `0x3ec` | Extern commando `0x65` | `0x66` | `0x67` |

AppMain sender is `0x15` (21), MgrUSB receiver 5. Tap gebruikt `IpcPostMsg` met vier payloadbytes uit systeemveld `+0xe4`; holdstart/stop gebruiken `IpcSendMsg` zonder payload. Actie 4 veroorzaakt in deze twee cases geen nieuw seek-startcommando. De GUI-repeat-timer voert de feitelijke seekstappen dus niet uit.

MgrUSB-handler `21d00` vertaalt extern 100 naar intern `0x65`, en extern `0x65` naar intern 100. Dat is een expliciete namespacevertaling: interne handler `20eac` noemt 100 next-track en `0x65` previous-track. Extern `0x66` betekent richting 1, extern `0x68` richting 2; beide stopcommando's leiden naar dezelfde stophelper. Start is ook afhankelijk van managerstate, waaronder veld `+0x78`; de volledige statebetekenis blijft open.

## Werkelijke seek-engine

Wrappers `1de20/1de3c` leiden naar `CPlayControl+8`, start `1b374` en stop `1d1b0`. Start zet multiplier `+0xe60` op nul, richting `+0x2930` op 1 of 2, vraagt Pause aan en start via `1b300` twee timers:

- `0x3e9`: iedere 300 ms een seekstap via `20340 → 1d880`.
- `0x3ea`: na 5.000 ms multiplier naar 4; deze timer stopt zichzelf.

Zonder multiplier is een stap drie seconden. Met multiplier 4 is een stap twaalf seconden. Richting 1 telt op; richting 2 trekt af. Forward op of voorbij de duration zet beide statevelden op nul, stopt beide timers en roept `1d23c` (`dshowEndAutoNextPlay`) aan. Rewind onder nul klemt de doelpositie op nul en zet alleen multiplier op nul: richting 2 en de steptimer blijven actief totdat stop volgt.

`11230` leest de positie en duration via virtuele media-interfacecalls en rekent van 10.000.000 tijdseenheden per seconde naar integer milliseconden/seconden. De kleinere positie/duration wordt vanaf 850 ms naar boven afgerond, met een bovengrens op de gehele durationseconden. `1137c` geeft afzonderlijk duration in gehele seconden terug.

Setter `1111c` zet doelseconden om naar 64-bit tijdseenheden. Wanneer de remaining duration kleiner dan 1.500.000 eenheden is, gebruikt hij `duration − 1.500.000` (150 ms vóór het einde). De vergelijking is strikt: exact 150 ms marge veroorzaakt geen aanpassing. Voor een duration korter dan 150 ms kan zo een negatieve doelwaarde ontstaan; er staat in deze helper geen nulclamp. COM-acceptatie en eventuele callerfilters zijn onbewezen.

Elke seekstap publiceert tijd/status opnieuw via `1b3b0` naar de eerder beschreven 3.670-byte USB-mapping. De volledige auto-next-, repeat-, shuffle- en media-interfacecontracten zijn nog open.

## Controle

`py tools/inspect_appmain_interaction.py` controleert zes tap/hold/canceltraces, twee grensvolgordes, een niet-repeatbutton, de outside-up-afwijking, 488 seekstappen, zes 64-bit seekgrenzen en 4.000 milliseconde-afrondingen. De modellen houden schedulertiming, gelijktijdige IPC, touchdrivervolgordes en COM-fouten expliciet buiten hun bewijsclaims.
