# AppMain tekst en fontselectie

De gedeelde labelroutine, tekstbuffer, fontkeuze en richtingsdetectie zijn gevolgd in AppMain 7.0.5.MD. De bronhash, 32 originele bewijsbereiken uit AppMain/GWES/mgtt_o en relevante registrysecties staan in [het machineleesbare bewijs](firmware/appmain-text-contracts.json). Er is geen rendering op Windows CE getest.

## Object en tekstbuffer

Constructor `139458` zet font op offset `0x30`, tien fallbackhandles op `0x34..0x58`, autofit op `0x5c`, kleur op `0x60` en tekenformat op `0x64` (default `0x824`). De UTF16-buffer begint op `0x70`; setter `139668` kopieert maximaal 128 code-eenheden en forceert ook een NUL op `0x170`. Setter `139718` gebruikt dezelfde start met capaciteit 270 en geforceerde NUL op `0x28c`. De offscreen-vtable `17cc60` koppelt zijn textset-slot op `+0x38` aan die uitgebreidere setter. Dit zijn code-eenheden, geen gegarandeerde aantallen Unicode-tekens; een surrogatepair kan aan de grens worden gesplitst.

Vergelijker `1381c8` gebruikt de capaciteit die de caller meegeeft en stopt bij NUL. De gewone setter geeft 128 mee; de uitgebreide setter geeft **270** mee op `13974c`. De eerdere claim dat de uitgebreide setter verschillen na 128 eenheden negeert is ingetrokken: [408 byte-interpretercases](firmware/appmain-text-compare-recheck.json) controleren alle veranderde posities binnen beide capaciteiten, de eerste uitgesloten positie en NUL-gevallen. De kopieerloop leest telkens de volgende source-eenheid voordat hij de resterende capaciteit controleert. Voor een lege source wordt eerst NUL gekopieerd en daarna de daaropvolgende opslag gelezen; eventuele niet-nul opslag kan nog achter die eerste NUL terechtkomen. Het zichtbare tekenpad stopt bij de eerste NUL. Dit is een statisch geheugencontract, geen bewezen crash.

De setter slaat nullpointers over. Een gewijzigde tekst leidt alleen tot redraw als de opgegeven redrawflag actief is. Het maximum voor DrawText komt afzonderlijk uit objectveld `0x290`: een positief maximum kleiner dan de daadwerkelijke lengte wordt doorgegeven; anders gebruikt de gewone labelroutine lengte `-1`.

## Fontselectie

`139528` vult maximaal tien fallbackhandles uit de resourcefontcatalogus, vanaf de gekozen index terug naar kleinere indices. De eerste fallback kan dus dezelfde fontgrootte vertegenwoordigen als het hoofdfont. De setter activeert autofit niet zelf.

`139b94` meet de volledige tekst. Zodra de tekstbreedte groter dan of gelijk aan de labelbreedte is, probeert hij de fallbackfonts. Alleen een gemeten breedte **strikt kleiner** dan de labelbreedte telt als passend. Een nulhandle stopt de zoeklus; geen passend font betekent terugval naar het hoofdfont. De tekenlengtelimiet wordt pas daarna toegepast en beïnvloedt deze meting niet.

De offscreen-labelroutine `13bc9c` bevat dezelfde breedtevergelijking, maar zijn fallbacklus stopt alleen op een nulhandle. Assembly `13bed8..13bee8` verhoogt de pointer en index zonder vergelijking met tien. Na tien gevulde slots leest hij dus `0x5c`, het actieve autofitveld, als volgende handle. Daarna kan hij andere objectvelden bereiken als de handle/meting niet tot stoppen leidt. De gewone labelroutine begrenst de lus wel tot tien. **Open:** concrete schermen die tegelijk deze tekenroutine, tien niet-nul handles en voldoende brede tekst gebruiken; GDI-effecten van de extra handle en foutafhandeling van de meting.

## Richtingsdetectie

`1397c8` herkent UTF16-eenheden `0590..05ff`. `1398a0` herkent `0600..06ff`. `139918` controleert daarnaast een tabel van 32 Arabische letters, maar alle tabelwaarden vallen al binnen de tweede reeks. Gezamenlijk zet `139b94` tekenformatbit `0x20000` zodra vóór de eerste NUL minstens één code-eenheid in `0590..06ff` staat. Andere Hebreeuwse/Arabische Unicode-blokken worden door deze helpers niet herkend.

De Arabische helper wordt binnen de outer tekstlus opnieuw aangeroepen bij een niet-gematcht teken. Bij tekst zonder dergelijke letters ontstaat daardoor herhaald volledig scannen; de booleanuitkomst verandert niet. De lokale `_snwprintf`-kopieën in de helpers worden niet als gescande input gebruikt.

## Verificatie en grenzen

Op 9 oktober 2026 is de herhaalde Arabischscan vervangen door één gelijkwaardige rangescan in [BT8T03](bt-menu-audio-test-build.md). De originele bron-evidence hieronder blijft behouden. De nieuwe byte-interpreter vergelijkt alle 65.536 UTF16-waarden en 172 gemengde/lange gevallen; unitrendering en algemene snelheid blijven te meten.

`py tools/inspect_appmain_text.py` controleert alle 65.536 mogelijke UTF16-eenheden (368 positieve), twee samengestelde NUL-/richtingsgevallen, zes fontbreedtegrenzen, twaalf kopieerlengtes voor beide setters, alle 128 veranderde prefixposities en de lege-string-lookahead. De fontloadingverschillen staan in [ACT3/RAC3-fontcontainer](ac3-font-contracts.md).

Open vervolg: list-/marqueetimers en clipgedrag, tekstrichting op echte fonts, screen-callers van autofit, overige labelvarianten, list-/editcontrols en runtimefoutafhandeling. Deze controles vergelijken offline modellen met behouden broninstructies; ze emuleren geen native GDI.
