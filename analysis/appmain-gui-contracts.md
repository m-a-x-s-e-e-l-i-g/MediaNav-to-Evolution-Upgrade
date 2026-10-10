# AppMain: GDI-buffer, controls en touchdispatch

Vervolg op [startup/resources](appmain-startup-contracts.md), statisch in de aanwezige 7.0.5.MD-AppMain. Reproduceer met `py tools/inspect_appmain_startup.py` en `py tools/inspect_appmain_gui.py`. Geen firmwarecode of Windows CE-app uitgevoerd.

## Buffer en tekenen

`0x135548` zet het dialogvenster op 800×480, maakt een compatible memory-DC en een **24-bit BI_RGB DIBSection van 800×480**: 1.152.000 ongecomprimeerde pixelbytes, stride 2400. Dialogvelden +0x4c/+0x54/+0x58 bevatten memory-DC, bitmap en vooraf geselecteerd object. De display-DC en memory-DC worden door de ingebedde container gedeeld.

De gewone windowrouter `0x134ed0` routeert WM_PAINT (0x0f) naar `0x134d28`, met BeginPaint/EndPaint. Het damage-RECT wordt vertaald naar x/y/breedte/hoogte. `0x13d220` kopieert van memory-DC naar display-DC met BitBlt/SRCCOPY 0x00cc0020, als HWND/initialized/state/globalflags dit toestaan. De speciale paintbranch bij DAT_1867a8 gebruikt een nul-rechthoek en kan de voorgaande dialog opnieuw foreground maken.

`0x13d098` herstelt een achtergrondfragment uit de gecachete achtergrondbitmap. `0x13d164` doorloopt controls voorwaarts en tekent de controls met vlag 0x80. Een controlredraw via `0x139020` tekent alleen bij vlag 0x80, en kiest een callback afhankelijk van de context/overlayvelden. De volledige betekenis van die overlayvelden blijft open.

Buttonstate `0x13e444`: vlag 0x100 uit→state 2; ingedrukt→state 1; niet ingedrukt en selectedveld+0x34 != 0→state 3; anders state 0. Painter `0x13e7ec` haalt een bitmap op en gebruikt **source-x = tekenbreedte × state, source-y = 0**. Dit is een horizontale strip, geen verticale frame-indeling. Drawflag 0x200 kiest TransparentImage in plaats van BitBlt; het oorspronkelijke transparent-argument is letterlijk 0xffff. Flag 0x400 kan eerst het achtergrondfragment laten herstellen. Kleurinterpretatie van het transparent-argument is niet op de unit geverifieerd.

Buttontext `0x13ecec` kiest een van vier kleuren op control+0x54c..0x558. Pressed/selected flags op +0x56c kunnen tekst met ingebouwde x/y-offset verplaatsen. De embedded textcontrol heeft een afzonderlijke drawcallback; volledige textlayout en Japanse fontfallback blijven open.

## Gedeelde source-DC en geneste selectie

`0x13fe40` maakt een 28-byte object: critical section, gedeelde source-DC op +0x14 en laatst geselecteerd object op +0x18. Iedere aanroep neemt de lock en overschrijft die **ene** previous-objectslot. Callers herstellen dat slot en verlaten de lock. Ghidra's CRITICAL_SECTION-structuurveldnaam SpinCount op deze offsets is geen betrouwbare semantische naam voor de eigen extra HDC-opslag.

Een gevolgde geneste route is `0x13e7ec`: selecteer sprite → bij drawflag 0x400 herstel achtergrond via `0x13d098` → teken sprite → restore. De inner helper gebruikt dezelfde source-DC/previous-slot. Het statische model laat zien dat na deze route de sprite geselecteerd blijft, terwijl een niet-geneste route het oorspronkelijke object herstelt. De critical section voorkomt geen overschrijving van die gedeelde slot tijdens een geneste aanroep. Of dit op de unit tot een merkbare GDI-/cache-/themawisselfout leidt, is nog niet bewezen.

## Touch-to-eventketen

WM_MOUSEMOVE/DOWN/UP (0x200/201/202) worden door `0x134ed0` verwerkt. x en y komen uit de **unsigned** low/high WORD van lParam; deze code doet geen signed GET_X_LPARAM-conversie. Mousedown `0x135aec` neemt capture, zet dialog+0x60 en zoekt **van de laatst toegevoegde control terug naar de eerste**. Alleen controltypes `(flags & 0x3f) == 3 of 5` worden geprobeerd.

Buttonvtable 0x17ce10 koppelt +4 aan `0x13e554` (down), +8 aan `0x13e620` (up), +0xc aan `0x13e6f8` (move/cancel). Baseconstructor `0x13e1d4` zet flags 0x183: type 3, drawflag 0x80 en interactieflag 0x100.

- Down: controleer vlag 0x100 en vier signed rechthoekgrenzen; **alle randen zijn inclusief**, ook x+breedte/y+hoogte. Zet pressed op +0x30, teken opnieuw, call parent vtable+0x48 en bewaar de actieve control via `0x13cf30`.
- Up: alleen een eerder ingedrukte control kan een klik produceren; reset pressed. Als loslaten binnen dezelfde inclusive rect valt en event-id+0x48 != -1: parentcallback+0x4c, daarna parentcallback+0x44 met event-id en actie 2 of 5 afhankelijk van repeatvelden. Wis actieve control.
- Move buiten rect: wist pressed, call parent+0x50, eventueel eventactie 5 bij repeat, redraw en wis actieve control. `0x135bcc` laat capture los als deze callback succes meldt.
- Window-up laat capture los, roept de actieve control aan en verwijdert vervolgens wachtende mousemessages 0x200..0x20d uit de queue via PeekMessageW.

Longpress/repeat gebruikt timers 0x3f6/0x3f7. `0x13cf30` start de eerste timer met de duur uit dialog+0x84 indien control+0x38 != 0; windowrouter verstuurt actie 3 en start herhaling met de duur uit dialog+0x88, daarna actie 4. Defaults zijn 700 en 200 ms. De verdere lifecycle, popup-timers en koppeling aan USB-seek staan in [het interactierapport](appmain-interaction-contracts.md).

## Koppeling aan het verborgen systeemversiescherm

Het [vorige rapport](appmain-startup-contracts.md) heeft vijf rects/events in `CSystemVerDlg`. De nu gevolgde controlketen bewijst dat een normale down/up binnen zo'n control via vtable+0x44 naar `0xcacbc` kan gaan. Deze callback gebruikt uitsluitend het eventnummer voor de vijf stappen, en laat de actieparameter bij die vijf events buiten beschouwing. De vtablekoppeling, control-parentroute en hitrect-layout zijn dus verbonden; een echt touchscreen/eventtrace ontbreekt nog.

De offline routecontrole vergelijkt alle **384.000** schermpunten tegen onafhankelijk gemaakte integer-regiosets, plus zes randen/buitenpunten. Een afzonderlijk overlappend-rectgeval bevestigt dat op een gedeelde inclusive rand de later toegevoegde control wint. Dit is een controle van het gereconstrueerde model, geen native uitvoeringsproef.

## Bewijs en open punten

Het hulpmiddel bewaart 20 oorspronkelijke .pdata-routines, twee leafroutines zonder .pdata en de 16-entry buttonvtable: 23 bewijsbereiken. De source-SHA256 is dezelfde als in het startuprapport. Pixelrouting, inclusive randen, reverse-order-prioriteit en eenvoudige/geneste bitmapselecties slagen als zelfstandige modellen.

De [tekst-/fontanalyse](appmain-text-contracts.md) en [interactieanalyse](appmain-interaction-contracts.md) vullen dit basisrapport aan met buffergrenzen, fontkeuze, negen control-vtables, hold/cancel en popup-timers. Open blijven de volledige dialogcatalogus, clipping, list/marquee-controls, animatie, overlays, thread-/handlelifetime, alle schermspecifieke callbacks en fysiek touch/rendergedrag. Alle AppMain-schermen zijn nog niet afgehandeld.
