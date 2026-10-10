# Audit van de resterende detailrapporten

Bijgewerkt op 8 oktober 2026. Dit voert stap 3 van het eerdere [resume-checkpoint](resume-checkpoint.md) uit: bestaande rapportbevindingen naar het [keuzeoverzicht](bug-keuzes.md) herleiden. Het is een inventarisatie van lokale evidence, geen nieuwe volledige firmwareaudit of selectie van reparaties.

## Expliciet overgeslagen

Op verzoek zijn de oorspronkelijke checkpointstappen 1 en 2 overgeslagen: geen vervolgtrace van H4-length-nul/incomplete bodies via timeout/power/reset, RX/TX-ACK/resend of overige HCI-events; geen vervolgonderzoek naar controllerauthenticatie/profielstatus, cache-aliases/snapshotgeneratie of gecombineerde acht-apparatenfixture. Bestaande conclusies daarover blijven ongewijzigd. Er wordt geen acht-apparatenpayload geschreven.

## Rapportdekking en samenvoeging

De eerdere 51 IDs blijven behouden. Onderstaande audit voegt bestaande concrete codeafwijkingen toe en bewaart onverklaarde verschillen als open punten. De genoemde aantallen en fixtures komen uit de detailrapporten; deze audit telt ze niet als nieuw uitgevoerde native tests.

| Nagelopen rapport | Afhandeling in het overzicht | Nog open / niet als extra bug geteld |
| --- | --- | --- |
| [iPod](ipod-contracts.md) | IPD-01..05 | Driver-/iAP-grenzen vóór callbacks, authenticator, UID-writer, werkelijke iPod/hardware |
| [DAB-opties](dab-options-contracts.md) | DAB-01/02 | Twaalfde DWORD/resetbetekenis onbekend; elf bekende opties vormen geen bewezen twaalfde gebruikersoptie |
| [DAB-update/SPI](dab-update-contracts.md) | DAB-03..08 en DAB-wacht bij UPD | BC/UC en SPI-provider ontbreken; checksum-indexwrap bij payload ≥250 vereist volledige fragment/callerroute |
| [DAB-shared](dab-shared-contracts.md) | Lokale preset-/EPG-guards als kandidaat hieronder | Scanproducer en AppMain-count hebben wel 250-grenzen; EPG-WORDs niet als bewezen datums benoemen |
| [AppMain-startup](appmain-startup-contracts.md) | APP-01/06 | Thema-/fontpakketverschillen, LCID-writers, GetMessage(-1), schermcatalogus |
| [AppMain-GUI](appmain-gui-contracts.md) | APP-04 | Inclusive randen en reverse controlvolgorde zijn contracten; geen zelfstandige bug |
| [AppMain-tekst](appmain-text-contracts.md) | APP-02/03 | Lookahead/surrogategrenzen, richtingsdetectie en herhaald scannen behouden als contract-/optimalisatievragen |
| [AppMain-interactie](appmain-interaction-contracts.md) | APP-05 en USB-13 | Dragselectie, alternatieve RTL-draw en timerplanning vragen concrete screencallers |
| [IPC-basisonderzoek](research-02.md) | IPC-01; copy/delete bij UPD-01 | WM_COPYDATA-zenders/sizecompatibiliteit; geen nieuwe pairingintegratie |
| [Vervolgonderzoek](research-03.md) | Historische pointers samengevoegd met latere contracten | Decoder-/ISA-correcties zijn analysetoolbevindingen, geen firmwarebugs |
| [Display](display-overlay.md) | OpenGL-returnverschil hieronder | Volledige enablecaller, registersemantiek en unitweergave ontbreken |
| [Camera-driverketen](camera-driver-chain.md) | CAM-03..08; capture blijft CAM-01 | MEM-/ITE-/SMB-inputs en resultaatcontracten verschillen; camera-BOOL-bug niet dubbel geteld |
| [USB-controllers](usb-controller-contracts.md) | UWD-stackcopy bij IPD-04; SER-01..03 blijven afzonderlijk | UDD-successstub/initstatus, IRQ-ownership, RMD-detach en BOT/SCSI nog onvolledig |
| [EchoCanceller](echo-audio-contracts.md) | AUD-05..09 en EC-partial-send bij NET-03 | Ongemeten DSP/downsamplingkwaliteit, BSD-fallback en echte devices; geen audio-optimalisatie geselecteerd |
| [SSE/BSD](sse-bsd-contracts.md) | Geen extra concrete unitbug | Minder strikte checksum voor ongebruikte records en merge-/sentinelbeleid zijn vastgelegde contracten |
| [Wave-drivers](wave-driver-contracts.md) | Bestaande AUD/DMA-families; rate/powerpunten hieronder | Wave-ID's zijn dynamisch; PCM-formatacceptatie is geen bewijs van elke hardware-rate |
| [Wave-queue](wave-queue-contracts.md) | AUD-03/04; Blue-submitboekhouding bij BT-02 | Normale manager-close ruimt proxies op: korte Blue-unpreparelus bewijst geen onvermijdelijk lek |
| [Wave-stream](wave-stream-contracts.md) | Onderbouwing ownership bij AUD-04/BT-02 | Restart na reset met lege queue is contract, geen bewezen fout; WOM_DONE is geen fysiek audio-einde |
| [Wave-DMA](wave-dma-contracts.md) | AUD-01 en DMA-01..05 behouden | API-foutinjectie is geen bewezen normaal bereikbare hardwarefailure; fragmentduren geen latency-meting |
| [MGR-driver](mgr-driver-contracts.md) | Mismatchkandidaten hieronder | Andere resetselectors en memory-IOCTLs bewijzen zonder actieve unit/wiring geen veilige patch |
| [GPIO-kernel](gpio-kernel-contracts.md) | DRV-01 | Platformpintabel identificeert geen vervangende resetpin; geen fysieke registeractie uitgevoerd |
| [OAL/filter](oal-ioctl-contracts.md) | DRV-03..05 | Wired-TLB geblokkeerd door userfilter; blokindexcallers gebruiken 0..3; overige output-/wrappervragen hieronder |
| [Boothelpers](boot-helper-contracts.md) | BOOT-01..03 | dmenu-font/threadhandlecleanup en HWND/CloseHandle zijn lokale lifecyclevragen; unitfrequentie ontbreekt |
| [Boot-update](boot-update-contracts.md) | UPD-05..07, DRV-02 en DAB-05 | NK-bestandskopie verschilt van NOR-write; BootSequence bewijst geen complete bootfallback |
| [Bootregistry](boot-registry.md) | Geen extra firmwarebug | Verkeerde roots in externe export gecorrigeerd in apart artifact; oorspronkelijke FDF intact |
| [Updater-storage](updater-storage-contracts.md) | BOOT-04; staging/config bij UPD-01..03 | Lexicografische versievergelijking, header-short-read en extractieretry vereisen eigen callers/failurefixtures |
| [Updater-ZIP](updater-zip-contracts.md) | UPD-04 | Writer controleert BOOL én count; namejoin/rootcontainment, writerjoin en malformed inflate blijven open |
| [Radio/audioformats](radio-audio-formats.md) | RAD-01 | Coëfficiënten en inhoudelijk MCU-antwoord onbekend; oorspronkelijke defaults juiste lengte |
| [CodeChecker](codechecker-contracts.md) | I/O-kandidaten hieronder | Twee verschillende wachttabellen zijn geen bewezen verkeerde gebruikerswachttijd; provisioning ontbreekt |
| [Remote services](remote-service-contracts.md) | NET-01..04 | Bind-all is geen open hosttoegang: addressfilter/handshake bestaan; Autoras-shutdown/returns nog open |
| [RAPI-commandotabel](rapi-command-table.md) | Context voor NET-02/03 | 86 targets/API-kandidaten zijn geen 86 bewezen volledige payloadschema's |
| [PPP-transport](ppp-transport-contracts.md) | Protocolverschillen hieronder | Normale TX verwerkt partial writes; default escaped-bufferbound past; afwijkende configs apart |
| [PPP-negotiatie](ppp-negotiation-contracts.md) | Parser/authverschillen hieronder | TLV/declared lengths/Ack gelden als bestaande guards; credential-serverstub is buildbeperking |
| [EAP](eap-contracts.md) | NET-05..08 | Nak-capability, MPPE-outputcapacity en volledige session/UI/lifetime open |
| [MS-CHAP/crypto](mschap-crypto-contracts.md) | NET-09 | 56-bit referentieciphertextverschil telt niet als firmwarebug |
| [PPP-CCP](ppp-ccp-contracts.md) | EAP-richtingverschil hieronder | Modellen bevestigen stateful synthetische streams; geen bewijs van native EAP-interoperabiliteit |
| [MPPC](mppc-contracts.md) | NET-10/11 | Ontbrekende lange decoderklassen zijn asymmetrie; default 1502-frame gebruikt zulke lange matches niet |
| [ACT3-font](ac3-font-contracts.md) | Pakket/driverdiscrepantie hieronder | Glyphtransformatie, installatieconversie, actieve fontnaam/bytes en 16-byte verschil open |
| [MICOM-framing](micom-protocol.md) | Short-write als kandidaat; update-ACK bij MCU-02 | A6 bevestigt geen inhoudelijk flashsucces; exacte MCU/serialcapturing ontbreekt |
| [MICOM-transfer](micom-update-transport.md) | MCU-03/04; ontbrekend HEX bij MCU-01 | A4/teller/100%-voortgang geen readback; termination na reset op unit onbekend |
| [MCU-flow](micom-mcu-flow-contracts.md) | Context voor bestaande MCU-01/02 | Traversal-/decoderfixes geen firmwarebugs; ringownership/ISA blijven aannames |
| [MCU-updateketen](micom-mcu-update-chain.md) | MCU-01 en onderbouwing MCU-03 | Geen bewezen reboot-only A1-bypass; fysieke programmeerstatus/swap open |
| [MCU-flashlibrary](micom-flash-library-contracts.md) | Onderbouwing MCU-01/02 | Logische tagmapping bewijst geen geïnstalleerde fysieke bootmapping |
| [MICOM-bootnotification](micom-boot-notification-contracts.md) | Onderbouwing MCU-02/installatiegrenzen | Bootstatus, ACK en geverifieerde installatie blijven afzonderlijke voorwaarden |

## Kandidaten en verschillen zonder nieuwe bug-ID

Deze punten zijn daadwerkelijk in de rapporten beschreven, maar zijn hier nog geen afzonderlijke releasefix. Eerst de ontbrekende semantiek of concrete callers vaststellen.

| Onderwerp | Lokale evidence | Waarom nog geen extra bugrij |
| --- | --- | --- |
| DAB-preset/EPG-index | `28154` mist presetindexguard; `27d84` test count<100 zonder ondergrens; ontvangen payloadlengte ontbreekt lokaal | Normale UI-writers/reset en voorafgaande payloadvalidatie kunnen zulke inputs beperken; geen gekoppelde fouttrace |
| AppMain-profielen | M0_INV-pakket heeft 44/461 hits; overige profielen missen twee resources | Actieve UI_TYPE en reeds geïnstalleerde bestanden onbekend; geen gemeten ontbrekende schermassets |
| ACT3/fontload | Pakketbytes voldoen niet aan gevolgde mgtt_o-directoryvalidator; .ac3-herkenning bestaat in GWES | Mogelijke installatieconversie/andere driver/fallback niet gevolgd; geen claim dat unitfont corrupt is |
| MGR-resetselectie | 7.0.5-Blue geeft 18 en MicomManager 26 aan ROM-reset die 0e/16/3e/3f kent | Versie/wiring op unit ontbreken; driverinit doet al BT-reset 16; bestaande callerinfo hier alleen geïnventariseerd |
| MGR-geheugencontract | USB/iPod gebruiken 15/16 buiten ROM-dispatch | Callers vallen terug op gewone heap; geen bewezen leak of playbackdefect door deze mismatch |
| Display-success | OGL-enable kan met geblokkeerde vrijgaveflag toch 1 geven; sommige korte buffers idem | Volledige aanroepvolgorde/outputverwerking en zichtbaar unitprobleem niet bewezen |
| Wave-rate/power | Ratepolls missen deadline; setters/initstatus worden op enkele paden genegeerd; powerpad dereferentie vóór volledige check | Bestaande AUD-initfamilie dekt bewezen initfouten; extra routes nog zonder concrete bereikbaarheid/ownershiptrace |
| OAL-overige handlers | Wired-TLB zonder bufferchecks; hardwareblokindex zonder cap; UUID schrijft 16 maar meldt 4; clockwrappers negeren BOOL | Userfilter sluit Wired-TLB uit; bekende blokcallers gebruiken 0..3; precieze clientbuffers/ABI nog volgen |
| CodeChecker-I/O | Counter-fwrite en MicomManager-readcount niet inhoudelijk bevestigd; F_CODE-readreturn genegeerd | Failureroute met echte provisioning/antitheftstate ontbreekt; geen conclusie over ontgrendelen uit een lokale stub |
| PPP-parserverschillen | Dangling escape vóór closing flag kan passeren; protocolprefix laat extra leading zeros toe; RX-ACCM/minimum verschillen | Afwijking is lokaal beschreven; peer/config en verdere protocolafwijzing bepalen gebruikersimpact |
| PPP/EAP-serverpolicy | PAP/CHAP-servercredentialhelper geeft altijd false; beperkte Nak-variant en PAP-ID-check lokaal onvolledig | Buildcapability/ontworpen clientgebruik niet verwarren met bewezen regressie; volledige authcallerstate open |
| EAP-MPPE-richting | Plugin subtype16=magic3, CCP kiest deze voor TX; directe MSV2-client gebruikt magic2 voor TX | Exacte rol/config/interoperabiliteit ontbreekt; niet als bewezen verkeerde controller-/unitverbinding presenteren |
| MPPC-lange matches | Encoder ondersteunt 2048..8191, decoder eindigt bij 2047 | Default frame1502 valt eronder; grotere MRU en peerdata niet vastgesteld |
| MICOM-short-write/A4 | Gewone zender toetst BOOL zonder complete count; updatevlag blijft na A4 gezet | Inhoudelijk completion-/resetcontract ontbreekt; latere verzoeken/stop op unit niet geobserveerd |
| SPP/ring | [SPP](spp-protocol.md): gelijkheid indices kan wrap-pad kiezen, lokale chunkcap/minimumframe/16-bitlengte vragen open | Volheid/notificatie/writers kunnen bereikbaarheid bepalen; geen extra trace of Bluetooth-vervolg uitgevoerd |
| Historische analysetoolfouten | Registryroots, SSE-tabelstart en MCU-decoder/traversal zijn apart gecorrigeerd | Onderzoeksfouten tellen niet als originele firmwarebugs |

## Regressievragen voor een latere fixkeuze

| Groep | Minimaal te bewaren gedrag / bewijs vóór combinatie |
| --- | --- |
| iPod/DAB/media | Normale metadata/encoding, single/multiple artwork, chunkgrenzen, scan/presets, TA/DLS/announcements; werkelijk aanwezige hardware |
| AppMain/IPC/display | Berichtcompatibiliteit, lange tekst/redraw, fontfallback, bitmaprestore, tap/hold/cancel, thema's en navigatie/camera-overlay |
| Audio/EC/opname | Init/unwind, juiste eventowner, stop/join, completion/postfailure, gekoppelde bufferownership, correcte WAV-header en langere playback/calls |
| Update/boot/radio/MCU | Inputvalidatie, behoud retrybron/backup, inhoudelijke status, readback, herstart/onderbreking en veilige herstelroute per firmwarelaag |
| Drivers/OAL/camera | Normale ABI/counts, geldige pointer/index/range, resourcefailure, bus-/interruptcompletion, stop/locking en echte hardware |
| Netwerk/crypto/compressie | Partial I/O, packetgrenzen, normale authvectors, lange/Unicode-invoer, token/historygrenzen, interoperabiliteit en effectieve unitconfig |

De individuele bronrapporten blijven leidend voor adressen, bewaarde bytes en fixturebeperkingen. `py tools/audit_detail_reports.py` schrijft [audit-evidence](firmware/detail-report-audit.json) met de cataloguscontrole en actuele bronhashcontrole; dat bewijst geen native uitvoering. De [releasevoorwaarden](release-requirements.md) blijven gelden: MAX02 is een lokale kandidaat; unitbackup, fysieke vóór/na-controles en installatie/herstelbewijs ontbreken.
