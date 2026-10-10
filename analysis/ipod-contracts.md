# MgrIpod, USBware en AppMain

Deze analyse volgt de originele MgrIpod.exe uit 7.0.5.MD, USBware.dll uit de gereconstrueerde ROM en de bijbehorende AppMain-lezers. Geen executable is uitgevoerd en geen USB-apparaat is geopend. [De reproduceerbare evidence](firmware/ipod-contracts.json) bevat bronhashes, 50 oorspronkelijke codebereiken, 97 commandowrapper-kandidaten en afzonderlijke rekenmodellen. De kandidatenlijst is geen verklaring dat alle iAP-commando's begrepen zijn.

## Architectuur en versiecontract

De applicatie importeert CmnDll/COREDLL en bevat zelf USBware-code. `20744` meldt expliciet `wince_usbware_entry: USER MODE`; `207bc`/`252a8` initialiseren de user-mode-stack. De echte driver wordt via `CreateFile("UWD1:")` geopend, niet via een applicatie-import van USBware.dll.

De bootregistry koppelt `Drivers\BuiltIn\UWD` aan USBware.dll, Prefix UWD, Index 1, Order 0x100, TaskPriority 0x66 en MaxHeapSize 0x100000. `21280` vraagt tien bytes op en vereist exact `3.5.14.82` inclusief NUL. De ROM-driver levert precies die bytes in `c09f36fc`. Een mismatch geeft applicatiestatus 10; een mislukte IOCTL geeft 5. Dit bewijst het bedoelde ABI tussen de aanwezige applicatie en ROM, niet de versie die op Max' fysieke unit draait.

USBware2.dll staat afzonderlijk onder BuiltIn\UDD, met Prefix UDD. Het [vervolgonderzoek naar USB-controllers](usb-controller-contracts.md) bevestigt inmiddels de twee hostcontrollers in USBware.dll en de geselecteerde Synopsys-devicecontroller in USBware2.dll. USBware.dll exporteert naast zeven UWD-exports ook tien RMD-exports voor de opslagadapter; details staan in dat vervolgonderzoek.

## UWD-IOCTL en callbacks

| Code | Gevolgd gedrag |
| --- | --- |
| 0x81002040 | Blocking receive uit de driverqueue; wacht op twee events als de queue leeg is. |
| 0x81002044 | Zet het cancel-event en voert resterende queue-items terug naar de callback met selector 0. |
| 0x81002048 | Commandobuffer naar de iPod-backend; status-DWORD plus eventuele uitvoer terug. |
| 0x8100204c | Zelfde enveloproute naar de tweede backend; verdere betekenis open. |
| 0x81002050 | Tien-byte versiestring inclusief NUL. |

`UWD_IOControl c09f3120` retourneert TRUE als de helper status 0 geeft. Het commandoresultaat in de eerste uitvoer-DWORD is dus een andere status dan DeviceIoControl's BOOL. MgrIpod `217d4` eist BOOL succes en minstens vier geretourneerde bytes, leest de status-DWORD en bewaart de volledige geretourneerde lengte.

De receiver `215cc` levert een outputbuffer van 0x1008 bytes. De driver zet de berichtlengte op output+0, kopieert data naar output+4 en schrijft nog een DWORD op output+0x1004. De reported bytecount is de data-lengte, niet noodzakelijk de gehele envelop. Het in/out-byteargument wordt 1 wanneer receive geannuleerd wordt. De user-thread verlaat dan de lus.

`216c0` vraagt cancel aan, wacht onbeperkt op de receiverthread, sluit die thread en het driverhandle en bevrijdt het contextobject. Een niet-afgehandelde cancel of geblokkeerde receiver kan deze afsluitroute dus onbeperkt laten wachten. Dat is een statische wachtvoorwaarde, geen gemeten hang.

### Segmenten van een commando

`1c9d0` serializeert een 24-byte header en minstens 48 bytes commandopayload. Met extra payload N start remaining op N+0x48. Iedere IOCTL heeft maximaal 0x1000 inputbytes; iedere chunk draagt inputlen-0x18 payloadbytes. Het bericht stopt wanneer remaining 0x18 is. Ook N=0 stuurt daarom 72 inputbytes. Header:

| Offset in input | Betekenis in de gevolgde code |
| --- | --- |
| 0x00 DWORD | Commandoselector uit wrapper+0. |
| 0x04 DWORD | Totale payloadlengte N+48. |
| 0x08 DWORD | Payloadlengte van deze chunk. |
| 0x0c DWORD | Oplopend berichtnummer. |
| 0x10 DWORD | Chunkindex, start op 0. |
| 0x14 DWORD | Callback-cookie uit wrapper+0x14. |
| 0x18 ... | Commandopayload, vanaf wrapper+0x18. |

De ROM-backend `c0a0779c` reconstrueert meerdere chunks en controleert berichtnummer, opeenvolgende index, totale lengte en de som van ontvangen payloadbytes. `1ab68` doet vergelijkbaar werk voor callbacks. `1a92c` maakt bij een callback een acht-byte cookie met functiepointer en callback-context. Veel wrappers initialiseren uitsluitend gebruikte velden: een volledig nulgevulde payload mag niet worden aangenomen.

De bufferkopie in `c09f36fc`, voor 2048/204c, heeft in deze routine geen check `inputlen <= 4096` vóór de kopie naar de 4096-byte stackbuffer. De normale MgrIpod-zender houdt zich wel aan die grens. Bereikbaarheid met andere callers en eventuele bescherming elders zijn niet onderzocht.

Gevolgde commando's zijn onder meer 10 open audio, 11 close audio, 12 prepare audio, 13 start read, 14 stop read, 0x3e categorized records, 0x41 artwork formats, 0x42 artwork data, 0x43 artwork times en 0x6c/0x6d aan-/afmelden van usercallbacks. De overige 97 wrapperentries hebben een numerieke selector en bronadres; hun volledige argumenten en Apple-protocolsemantiek blijven open.

## Digitale audio loopt door USBware.dll

MgrIpod `13fac` stuurt prepare selector 12. `14050` vraagt start read met argument 100 en callback `16ad8`, wacht op het gezamenlijke event en vraagt daarna audio open. Bij UWE_BUSY, waarde 8, wordt onder voorwaarden een timer van 10 ms gebruikt om opnieuw te proberen. De manager onderscheidt het audio-read-startflag en wave-open-flag; alleen een van beide is geen bewijs dat afspelen lukt.

De driver `c0a05d60` kiest bij ontbrekende sample-rate 44100 Hz en forceert daarbij periodeargument 100. `c0a088cc` bewaart kandidaten 32000, 44100 en 48000; de selectie/onderhandeling is nog niet volledig gevolgd. `c09f79cc` bouwt PCM tag 1, stereo, 16 bits, blockalign 4 en bytes/sec rate*4. De buffergrootte is:

`ceil(((rate * 4 + 4) * periodeargument) / 1000)`, daarna omhoog naar een veelvoud van vier.

Met argument 100 levert dat 12804, 17644 en 19204 bytes bij respectievelijk 32000, 44100 en 48000 Hz. Dit zijn letterlijke rekenmodellen van de driver, geen gemeten latencies.

`c09f76cc` maakt tien buffers en opent `waveOutOpen` met device 0xffffffff, functiecallback `c09f75b4`, callbackflag 0x30000. Het concrete fysieke outputdevice hangt af van de wave-mapper/device-registratie. `c0a03904` leest USB-audio naar de volgende buffer en biedt het via `c09f7c9c` aan. Wanneer geen geschikte buffer beschikbaar is, leest hij data naar een tijdelijke buffer en gooit die weer weg. Daarmee is het expliciete discard-pad bewezen.

`c09f7c9c` prepareert waveheaders, draait modulo tien, roept waveOutWrite en herstart onder zijn statevoorwaarden de uitvoer. `c09f7bf0` vermindert de beschikbare-buffercounter pas bij succesvolle waveOutWrite. De overige timing, USB-isocronous transfer, DMA en mixer blijven open.

## Shared-memorylayout

De allocatie in `17700` en AppMain `13234` bevestigen dezelfde drie namen en afmetingen. De decompiler toont 0x13d628 soms als `&DAT_0013d628`; de oorspronkelijke MIPS `177e4/177f4` bouwt juist het onmiddellijke getal 0x13d628. Het is een lengte, geen pointer naar een lengtevariabele.

| Mapping | Bytes | Gevolgd deel |
| --- | ---: | --- |
| ShmFmMgrIpodAppMain | 3164 / 0xc5c | Playerstatus, tijdvelden, trackindex, metadata en bitmaphandle. |
| ShmFmMgrIpodAppMainList | 1300008 / 0x13d628 | Acht headerbytes en 5000 records van 260 bytes. |
| ShmFmMgrIpodAppMainListUID | 40020 / 0x9c54 | AppMain UID-vergelijking; producer nog niet gevonden. |

Statusbasis is lokaal 0x16d0fc. `1136c`, `15f14`, `16344`, `1679c`, `16904` en `16bb4` tonen:

| Statusoffset | Gevolgd betekenis |
| --- | --- |
| 0x00..0x0f | Totale tijd: vier DWORDs, uur/minuut/seconde/millisecondecomponent. |
| 0x10..0x1f | Huidige tijd met dezelfde indeling. |
| 0x20 WORD | Playerstatus; managerbranches gebruiken 0 stopped, 1 playing, 2 paused. |
| 0x22 WORD | Titel-lengte uit title-callback. |
| 0x26 WORD | Lengte van het derde metadata-veld uit artist2-callback. |
| 0x2c DWORD | Huidige trackindex. |
| 0x30 DWORD | Chapterindex uit playback notification. |
| 0x54..0x453 | Titelbuffer, 1024 bytes. |
| 0x454..0x853 | Geïnitialiseerde metadata-buffer; schrijver/semantiek hier nog niet bevestigd. |
| 0x854..0xc53 | Artist2-buffer, 1024 bytes; bij lege artist2 wordt de titel gekopieerd. |
| 0xc54 DWORD | DIB/bitmaphandle. |
| 0xc58/0xc5a WORD | Artworkafmetingen uit callback. |

`1168c` rondt een millisecondewaarde bij een rest **groter dan 400** naar de volgende seconde af en zet de millisecondecomponent op nul. Dat is de exacte grens uit de code; geen standaard afronding op 500 ms. De strengen zijn bytebuffers; hun volledige encodingcontract is nog niet bewezen.

De categorized-record callback `14d9c` bewaart maximaal 259 bytes per record, alleen bij index <5000. De voorafgaande memset van 1300000 bytes laat dan een afsluitende nul over. `124cc`/`127ec` vragen maximaal 200 records per batch en plannen de vervolgbatch met een timer van 20 ms. Requests accepteren categorie 1..7; de volledige categorienamen blijven open. De inhoud begint op mapping+8. AppMain `41508` leest de eerste DWORD als aantal en kan recordnamen met strcmp vergelijken.

De UID-reader in AppMain `41508` gebruikt DWORD+0 als enableflag, 8-byte UID-records vanaf +4, huidige track-UID op +0x9c44 en count op +0x9c4c. Hij vergelijkt acht bytes per record. +0x9c50 is nog onbekend. MgrIpod initialiseert deze mapping met nul en ruimt haar op; in de onderzochte managerfuncties is geen verdere payloadschrijver gevonden. Een ingeschakeld/gevuld UID-pad op de unit is dus nog niet bewezen.

## Albumhoezen en grenzen

`12e2c` vraagt achtereenvolgens formats, artwork times en artwork data op. De eerste twee wachten op een afzonderlijk manual-reset event zonder timeout. `16ea4` kiest uit 8-byte formatrecords de grootste WORD op record+4 en bewaart de formatidentifier op +0, maar doet dit alleen wanneer **meer dan één** format aanwezig is. Bij precies één blijft de eerder op nul gezette identifier nul.

`17700` vraagt een 1-MiB imagebuffer aan. `16bb4` zet bij de eerste chunk de afmetingen en schrijfpositie, kopieert elke chunk op buffer+positie en verhoogt positie. In deze routine ontbreekt een check dat positie+chunklengte binnen 1 MiB blijft. `13078` gebruikt een top-down 16-bit DIB, BITFIELDS-masks f800/07e0/001f, vervangt pixel 0001 door 0000 en kopieert lengte-2 bytes. Het oude bitmapobject wordt gewist. De callback corrigeert op het einde positie met `(positie-2)&3` door deze rest erbij op te tellen; dat is de letterlijke formule en niet een algemene align-up-formule.

Ook de title- en artist2-callbacks kopiëren een ontvangen WORD-lengte naar 1024-byte buffers zonder lokale cap. Eerdere driver-/protocolgrenzen zijn nog niet volledig gevolgd. Dit zijn aantoonbaar ontbrekende lokale controles, niet automatisch bewijs van een praktisch misbruikbare of op deze unit opgetreden fout.

## IPC, audiofocus en toestanden

WndProc `17bcc` verwerkt 0x8064 en WM_COPYDATA via CmnDll. De dispatch gebeurt op afzender: 1 systeem, 6 zichzelf, 0x15 AppMain. Een connected-flag van nul laat deze berichten zonder verdere dispatch vallen. Timers en create/destroy blijven wel actief.

System `193d0` behandelt shutdown command 10 en bevestigt met 6→1 command 11. Stream stop/start zijn 0x67/0x68. Daarbij worden aparte flags bijgehouden voor ontvangen stop, mute, user pause, blocked streaming, seek en uitgestelde hervatting. AppMain-play is daarom niet altijd gelijk aan onmiddellijk USB-audio starten.

AppMain `1842c` volgt repeat 0x65, shuffle 0x66, positie 0x67 (WORD seconden naar milliseconden), shuffle-query 0x68, shuffle-reset 0x69, play/pause 0x6a, next 0x6d, previous 0x6e, fast forward 0x6f, rewind 0x70, einde seek 0x71, category count 0x73, list 0x74, select record 0x75, back database 0x76, user play 0x78 en user pause 0x79. Overige waarden in de gevolgde dispatcher vallen terug zonder actie.

Self `1995c` behandelt 1000 initialiseren, 0x3e9 indexing, 0x3ea trackwissel, 0x3eb einde seek, 0x3ec categorie, 0x3ed volgende listbatch, 0x3ee play-state event, 0x3ef trackpos-reset/einde seek en 0x3f0 uitgestelde trackinfo. Deze states zijn uit de branches en debuglabels gevolgd; het gehele combinatorische gedrag is niet dynamisch getest.

Dezelfde auto-reset-eventhandle wordt door veel opeenvolgende commandocallbacks gesignaleerd en door commands met INFINITE afgewacht. `1842c` wacht daarnaast in een Sleep(100)-lus zolang artwork-processing actief is. Welke callbackvolgorden deze voorwaarden kunnen laten blijven staan, is een volgende onderzoeksvraag.

## Nog te onderzoeken

- Alle argumentlayouts van de 97 wrappers en de USB/iAP-frameconstructie in de driver.
- Authenticator, accessory identity, attach/reconnect, overcurrent en USB-host-controllerketen.
- Volledige artist/album/UID-writers, encoding en metadata-grenzen vóór callbacks.
- RMD-exports, USBware2/UDD, mass storage en eventuele koppeling aan MgrUSB.
- Driver locking, global queue ownership, foutrecovery en daadwerkelijke power-down.
- Exacte samplerateonderhandeling, isochronous transfers en fysieke outputrouting.
- Unitbackup/captures om de gebruikte versie, mappings en bereikbare states te vergelijken.

`py tools/inspect_ipod_contracts.py` controleert drie bronhashes en genereert evidence en modellen opnieuw. De modellen testen hun eigen lengte-invarianten en vervangen geen uitvoering van firmware of trace van een apparaat.
