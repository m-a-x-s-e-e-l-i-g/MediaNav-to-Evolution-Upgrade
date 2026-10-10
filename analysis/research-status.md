# Onderzoeksdekking per executable en DLL

Momentopname: 2026-10-08T20:17:31.800895+00:00.

**256 PE-bestanden geïnventariseerd; 256 disassemblies; 91.257 functiegrenzen uit .pdata.**

Ghidra heeft voor 256 modules pseudocode geëxporteerd (100,187 functiekandidaten). Dat zegt niets over hoeveel gedrag handmatig bewezen is.

Er zijn 0 analyzertime-outs en 1 afzonderlijke functie-exports die nog niet slagen. Foutdetails staan per module in research-status.json.

Dit betreft de aanwezige 7.0.5.MD-update, gereconstrueerde ROM, downgrade en navigatiefix. Dynamisch geladen bestanden, persistente configuratie, bootloader en bestanden op de echte unit kunnen ontbreken.

De kolom 'gevolgd gedrag' beschrijft uitsluitend het onderzochte deel. Een open module heeft wel imports/exports, secties, versiemetadata, strings, resources en disassembly. Geen firmwarecode is uitgevoerd.

## 705md

| Module | .pdata-functies | Ghidra | Gevolgd gedrag |
| --- | ---: | --- | --- |
| [AppMain.exe](disassembly/AppMain.exe.asm) | 2907 | exported | [Startup, managers, GDI/touch/tekst/RTL en USB/IPC/BT gevolgd; acht-recordbasis/caller/reconnect/count-ACK, cacheprovenance en originele allocatie/mapping/destructor-faults gevolgd; aparte safe-copy-proef begrenst count/NULL, wist stale actieve/PB-status en volgt 368 copy/18 krimp/12 callbackcases, 122 volledige UI- en 222 geldige/18 NULL-HFP-traces; negatieve-index UI-store naar object+232 en stale-count Empty-connect gereproduceerd/geguard in zes UI- en zes profielparen; acht andere connect-failuresuffixes gevolgd; cachelezers/snapshotgeneratie/locking/heap/destructor/complete profielaanloop/native werking open](bt-safe-copy-draft.md) |
| [Blue.exe](disassembly/Blue.exe.asm) | 4009 | exported | [BlueEarth/A2DP/lifecycle/MAX02, acht-recordopslag/I/O/callers/GUI/security/reconnect/count-ACK, SC/CM/DM/cache/HCI en BCSP/H4DS-transport gevolgd; cleanupvariant repareert globale-head-free en herhaalde payloadfree; geregistreerde RX/mblk/DM_HCI/key-command-completion volgt 216 traces; BCSP SLIP/header/CRC/sequence en H4-eventframing tot decoder volgen 60 normale traces, dertien vastgezette foutprobes, 30 hersteltraces en vier BCSP-duplicaatcases; inner korte events bereiken decoderread via beide parsers, outer BCSP-fouten/duplicaten geweigerd; volledige ACK/retransmit/serialdriver/overige events/profile/power/timers/concurrency/radio/controller/heap/unit en gezamenlijke pairingupdate open](bt-rx-frame-contracts.md) |
| [cereboot.exe](disassembly/cereboot.exe.asm) | 31 | exported | [Prompt, close/terminate-reeks, COM2-frames, MGR/disk-sleep/powercalls gevolgd; hardware/CRT open](boot-helper-contracts.md) |
| [CmnDll.dll](disassembly/CmnDll.dll.asm) | 64 | exported | [IPC-routing en berichtformaat deels handmatig bevestigd](research-02.md) |
| [CodeChecker.exe](disassembly/CodeChecker.exe.asm) | 190 | exported | [Radiocode-invoer, registryread, pogingteller, factory/MICOM-wachttijden en IPC gevolgd; GUI en provisioning open](codechecker-contracts.md) |
| [LangDllAra.dll](disassembly/LangDllAra.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllBul.dll](disassembly/LangDllBul.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllCro.dll](disassembly/LangDllCro.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllCze.dll](disassembly/LangDllCze.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllDan.dll](disassembly/LangDllDan.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllDut.dll](disassembly/LangDllDut.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllEng.dll](disassembly/LangDllEng.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllFarsi.dll](disassembly/LangDllFarsi.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllFin.dll](disassembly/LangDllFin.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllFre.dll](disassembly/LangDllFre.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllGer.dll](disassembly/LangDllGer.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllGre.dll](disassembly/LangDllGre.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllHeb.dll](disassembly/LangDllHeb.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllHindi.dll](disassembly/LangDllHindi.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllHun.dll](disassembly/LangDllHun.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllIndonesia.dll](disassembly/LangDllIndonesia.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllIta.dll](disassembly/LangDllIta.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllJap.dll](disassembly/LangDllJap.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllNor.dll](disassembly/LangDllNor.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllPol.dll](disassembly/LangDllPol.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllPor.dll](disassembly/LangDllPor.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllPTBR.dll](disassembly/LangDllPTBR.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllRom.dll](disassembly/LangDllRom.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllRus.dll](disassembly/LangDllRus.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllSer.dll](disassembly/LangDllSer.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllSlo.dll](disassembly/LangDllSlo.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllSloven.dll](disassembly/LangDllSloven.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllSpa.dll](disassembly/LangDllSpa.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllSwe.dll](disassembly/LangDllSwe.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllTur.dll](disassembly/LangDllTur.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [LangDllUka.dll](disassembly/LangDllUka.dll.asm) | 8 | exported | [RT_STRING-resources uitgelezen; gedeelde codehash bevestigd](research-03.md) |
| [dboot.exe](disassembly/dboot.exe.asm) | 161 | exported | [Bootkeuze, eenmalige StartWinCE-marker, desktopshortcuts en drag-menu gevolgd; overige debugfuncties open](boot-helper-contracts.md) |
| [dmenu.exe](disassembly/dmenu.exe.asm) | 29 | exported | [800x480 menu, marker/rebootvolgorde, COM2-frameconstructie, threads en disk-sleep gevolgd; hardware/CRT open](boot-helper-contracts.md) |
| [EchoCanceller.dll](disassembly/EchoCanceller.dll.asm) | 41 | exported | [Zeven exports, PCM/buffers/samplepad, SSE-calls en TCP-debug gevolgd; opname/shutdown/runtime open](echo-audio-contracts.md) |
| [glnavi.exe](disassembly/glnavi.exe.asm) | 22 | exported | [Launcher: overlay activeren en nngnavi met argumenten starten](research-03.md) |
| [MgrDAB.exe](disassembly/MgrDAB.exe.asm) | 892 | exported | [Update/SPI, opties, station/preset/scan/EPG-layouts deels gevolgd; driver, images en volledige tunerstate open](dab-shared-contracts.md) |
| [MgrIpod.exe](disassembly/MgrIpod.exe.asm) | 408 | exported | [UWD-versie/IOCTL, callbacks, audiofocus, list/status/UID-layout en artwork gevolgd; volledig iAP/auth/encoding open](ipod-contracts.md) |
| [MgrUSB.exe](disassembly/MgrUSB.exe.asm) | 321 | exported | [UI/IPC/seek, catalogus/repeat/shuffle, playlists/resume, ID3/ASF/tekstkopieën/hoesstride, allocatiepoolcleanup en COM-creatie/events/Stop/Pause gevolgd; pixeldecoders/sortering/races open](usb-metadata-contracts.md) |
| [MicomManager.exe](disassembly/MicomManager.exe.asm) | 808 | exported | [COM2/ULC, HEX/blokken, AB-statusverlies, MCU-updateketen en CE-opstarttimer/flashmarker/A6-event gevolgd; volledige commands/power/unit/readback en native reparatie open](micom-flash-marker-contracts.md) |
| [QtCore4.dll](disassembly/QtCore4.dll.asm) | 5944 | exported; 1 functiefouten | Semantisch onderzoek open |
| [RVC.dll](disassembly/RVC.dll.asm) | 105 | exported | [Config en SMB/CAM/mempool/ITE/displayketen gevolgd; runtime en filters open](camera-driver-chain.md) |
| [RVD.dll](disassembly/RVD.dll.asm) | 13 | exported | [Vijf RVC-wrapperexports gevolgd, venster 800x480; camera-runtime open](research-03.md) |
| [sse_int.dll](disassembly/sse_int.dll.asm) | 470 | exported | [382 parameterrecords, switch/accessenum, processingdispatch, BSD-container/moduleverdeling en 13 MAIN_Config-schema's gevolgd; DSP en overige payloadschema's open](sse-bsd-contracts.md) |
| [UpgradeManager.exe](disassembly/UpgradeManager.exe.asm) | 349 | exported | [LGU/ZIP, staging/marker/cleanup, kopieerfouten, configbackup/format, versiecommit en apps-MICOM-controlpad gevolgd; native reparatie/volledige recovery/directoryparsing open](updater-recovery-contracts.md) |

## rom

| Module | .pdata-functies | Ghidra | Gevolgd gedrag |
| --- | ---: | --- | --- |
| [afd.dll](disassembly/rom/afd.dll.asm) | 339 | exported | [Hosts-registrylookup en speciale ppp_peer-resolutie gevolgd; overige sockets/DNS/network open](remote-service-contracts.md) |
| [asyncmac.dll](disassembly/rom/asyncmac.dll.asm) | 37 | exported | [NDIS/TAPI/serial-HANDLE, PPP/SLIP framing, CRC, buffers en partial I/O gevolgd; overige OID/lifetime/runtime open](ppp-transport-contracts.md) |
| [au16550.dll](disassembly/rom/au16550.dll.asm) | 53 | exported | Semantisch onderzoek open |
| [au16550_dma.dll](disassembly/rom/au16550_dma.dll.asm) | 54 | exported | Semantisch onderzoek open |
| [audevman.dll](disassembly/rom/audevman.dll.asm) | 108 | exported | [Dynamische notificaties/device-ID's en wavebericht-envelope/DeviceIoControl-MMRESULT gevolgd; overige mixer/runtime open](wave-queue-contracts.md) |
| [audiocombiner.dll](disassembly/rom/audiocombiner.dll.asm) | 289 | exported | Semantisch onderzoek open |
| [autoras.dll](disassembly/rom/autoras.dll.asm) | 24 | exported | [ARS1 launch/IOCTL/queue, entryselectie en 30s-wacht gevolgd; adapterdetails/runtime/lifetime open](remote-service-contracts.md) |
| [battery.dll](disassembly/rom/battery.dll.asm) | 43 | exported | Semantisch onderzoek open |
| [busenum.dll](disassembly/rom/busenum.dll.asm) | 59 | exported | Semantisch onderzoek open |
| [camera.dll](disassembly/rom/camera.dll.asm) | 4 | exported | [18 modes en drie CAM-IOCTLs gekoppeld aan RVC; registers deels gevolgd](camera-contracts.md) |
| [ceddk.dll](disassembly/rom/ceddk.dll.asm) | 96 | exported | [CPU/PBUS/klok/TLB en DMA-runtimeconfig/select/activate/IRQ/ack/stop gevolgd; unchecked allocaties/verkeerde free/mutex/initreturns en herhaalde mapping/allocator-free met oorspronkelijke instructies bevestigd; kernelcleanup/concurrency/unit/overige DDK open](dma-mapping-contracts.md) |
| [ceshell.dll](disassembly/rom/ceshell.dll.asm) | 576 | exported | Semantisch onderzoek open |
| [commctrl.dll](disassembly/rom/commctrl.dll.asm) | 1034 | exported | Semantisch onderzoek open |
| [commdlg.dll](disassembly/rom/commdlg.dll.asm) | 107 | exported | Semantisch onderzoek open |
| [connmc.exe](disassembly/rom/connmc.exe.asm) | 202 | exported | Semantisch onderzoek open |
| [connpnl.cpl](disassembly/rom/connpnl.cpl.asm) | 7 | exported | Semantisch onderzoek open |
| [control.exe](disassembly/rom/control.exe.asm) | 32 | exported | Semantisch onderzoek open |
| [coredll.dll](disassembly/rom/coredll.dll.asm) | 2743 | exported | [rand_s/CeGenRandom/wavecalls/queues/barrier/async-PCM gevolgd; FreePhysMem en VirtualFree MEM_RELEASE-syscallargumenten gelijk bevestigd; oorspronkelijke memset-export/leaf aan CBtData failed buffers gekoppeld, 160 alignment/lengte/waarde-cases en native NULL-storewitness; objectlifetime/allocator/kernel/runtime open](bt-data-cache-lifecycle.md) |
| [cplmain.cpl](disassembly/rom/cplmain.cpl.asm) | 237 | exported | Semantisch onderzoek open |
| [ctlpnl.exe](disassembly/rom/ctlpnl.exe.asm) | 20 | exported | Semantisch onderzoek open |
| [cxport.dll](disassembly/rom/cxport.dll.asm) | 68 | exported | Semantisch onderzoek open |
| [ddi_au13xxlcd.dll](disassembly/rom/ddi_au13xxlcd.dll.asm) | 297 | exported | [RVC-escapes en glnavi-vrijgave gekoppeld aan windowregisters; overige displaycode open](display-overlay.md) |
| [ddi_nop.dll](disassembly/rom/ddi_nop.dll.asm) | 180 | exported | Semantisch onderzoek open |
| [ddraw.dll](disassembly/rom/ddraw.dll.asm) | 175 | exported | Semantisch onderzoek open |
| [device.dll](disassembly/rom/device.dll.asm) | 10 | exported | Semantisch onderzoek open |
| [devmgr.dll](disassembly/rom/devmgr.dll.asm) | 278 | exported | Semantisch onderzoek open |
| [dhcp.dll](disassembly/rom/dhcp.dll.asm) | 84 | exported | Semantisch onderzoek open |
| [dhcpsrv.dll](disassembly/rom/dhcpsrv.dll.asm) | 19 | exported | Semantisch onderzoek open |
| [diskcache.dll](disassembly/rom/diskcache.dll.asm) | 44 | exported | Semantisch onderzoek open |
| [DRVMGR.dll](disassembly/rom/DRVMGR.dll.asm) | 18 | exported | [Alle 21 IOCTL-codes, resetselectors en mismatch met Blue/MICOM/USB/iPod gevolgd](mgr-driver-contracts.md) |
| [eap.dll](disassembly/rom/eap.dll.asm) | 80 | exported | [Registrypluginloader, session/callbacks, packetparser/notification, timers en VSA/MPPE deels gevolgd; UI/registry/lifetime open](eap-contracts.md) |
| [eapchap.dll](disassembly/rom/eapchap.dll.asm) | 63 | exported | [Types4/26 context/framing/MD5, MSV2 response/servercheck en MPPE-attributen gevolgd; UI/change-password/rolinterpretatie open](mschap-crypto-contracts.md) |
| [eapol.dll](disassembly/rom/eapol.dll.asm) | 124 | exported | Semantisch onderzoek open |
| [ethman.dll](disassembly/rom/ethman.dll.asm) | 28 | exported | Semantisch onderzoek open |
| [eventrst.exe](disassembly/rom/eventrst.exe.asm) | 13 | exported | Semantisch onderzoek open |
| [exfat.dll](disassembly/rom/exfat.dll.asm) | 413 | exported | Semantisch onderzoek open |
| [explorer.exe](disassembly/rom/explorer.exe.asm) | 392 | exported | Semantisch onderzoek open |
| [fatutil.dll](disassembly/rom/fatutil.dll.asm) | 144 | exported | [FormatVolume-dispatch, FAT/TFAT en exFAT-keuze aan updater gekoppeld; overige formatter/scan open](updater-storage-contracts.md) |
| [filesys.dll](disassembly/rom/filesys.dll.asm) | 1000 | exported | [FDF-framing, rootkeys, defaultnaam en boot-restorepad gevolgd; overige filesystemcode open](boot-registry.md) |
| [fsdmgr.dll](disassembly/rom/fsdmgr.dll.asm) | 703 | exported | Semantisch onderzoek open |
| [giisr.dll](disassembly/rom/giisr.dll.asm) | 1 | exported | Semantisch onderzoek open |
| [gpintr.dll](disassembly/rom/gpintr.dll.asm) | 16 | exported | [Directe GPIO-exports, NK/OAL-handler en 43 platformrecords gekoppeld](gpio-kernel-contracts.md) |
| [gwes.dll](disassembly/rom/gwes.dll.asm) | 2546 | exported | [Fontextensies/-directory, AC3-suffix, mapping en driverload gekoppeld; overige GUI/kernelcontracten open](ac3-font-contracts.md) |
| [i2cbus.dll](disassembly/rom/i2cbus.dll.asm) | 15 | exported | Semantisch onderzoek open |
| [IECEExt.dll](disassembly/rom/IECEExt.dll.asm) | 48 | exported | Semantisch onderzoek open |
| [imaging.dll](disassembly/rom/imaging.dll.asm) | 655 | exported | [Factory/stream/IImage, BMP, PNG-chunks/rijen/54 scatterhelpers/pixels/tRNS, tekst/ICC/DPI/tijd/properties/cleanup gevolgd; malformed/SetProperty/sink/overige codecs/GDI/concurrency open](png-metadata-contracts.md) |
| [intll.cpl](disassembly/rom/intll.cpl.asm) | 85 | exported | Semantisch onderzoek open |
| [ipconfig.exe](disassembly/rom/ipconfig.exe.asm) | 33 | exported | Semantisch onderzoek open |
| [iphlpapi.dll](disassembly/rom/iphlpapi.dll.asm) | 189 | exported | Semantisch onderzoek open |
| [ipseccfg.exe](disassembly/rom/ipseccfg.exe.asm) | 58 | exported | Semantisch onderzoek open |
| [jacmdev.dll](disassembly/rom/jacmdev.dll.asm) | 119 | exported | [COM5-init/open/read/write/IOCTL, USB-callbackbrug en ringbuffer deels gevolgd; volledige event/lifetime/powerstate open](usb-serial-contracts.md) |
| [jacminit.exe](disassembly/rom/jacminit.exe.asm) | 4 | exported | [Volledige applicatieroutine: RAS-entrybouw, registryvelden en AutoCnct-branches gevolgd; RAS/runtime open](usb-serial-contracts.md) |
| [k.ceddk.dll](disassembly/rom/k.ceddk.dll.asm) | 96 | exported | [Eigen DMA-runtimeconfig/select/activate/IRQ/ack/stop en allocatie/cleanupfouttraces bevestigd; oorspronkelijke mapper/unmap/herhaalde allocator-free gekoppeld; kernelcleanup/concurrency/unit/overige kernel-DDK open](dma-mapping-contracts.md) |
| [k.coredll.dll](disassembly/rom/k.coredll.dll.asm) | 2736 | exported | Semantisch onderzoek open |
| [k.dhcpsrv.dll](disassembly/rom/k.dhcpsrv.dll.asm) | 19 | exported | Semantisch onderzoek open |
| [k.fatutil.dll](disassembly/rom/k.fatutil.dll.asm) | 144 | exported | Semantisch onderzoek open |
| [k.iphlpapi.dll](disassembly/rom/k.iphlpapi.dll.asm) | 189 | exported | Semantisch onderzoek open |
| [k.mmtimer.dll](disassembly/rom/k.mmtimer.dll.asm) | 23 | exported | Semantisch onderzoek open |
| [k.nspm.dll](disassembly/rom/k.nspm.dll.asm) | 25 | exported | Semantisch onderzoek open |
| [k.toolhelp.dll](disassembly/rom/k.toolhelp.dll.asm) | 26 | exported | Semantisch onderzoek open |
| [k.uspce.dll](disassembly/rom/k.uspce.dll.asm) | 443 | exported | Semantisch onderzoek open |
| [k.winsock.dll](disassembly/rom/k.winsock.dll.asm) | 38 | exported | Semantisch onderzoek open |
| [k.ws2.dll](disassembly/rom/k.ws2.dll.asm) | 172 | exported | Semantisch onderzoek open |
| [k.wspm.dll](disassembly/rom/k.wspm.dll.asm) | 46 | exported | Semantisch onderzoek open |
| [kbdmouse.dll](disassembly/rom/kbdmouse.dll.asm) | 61 | exported | Semantisch onderzoek open |
| [kernel.dll](disassembly/rom/kernel.dll.asm) | 0 ⚠ tabelafwijking | exported | Semantisch onderzoek open |
| [largekb.dll](disassembly/rom/largekb.dll.asm) | 26 | exported | Semantisch onderzoek open |
| [libEGL.dll](disassembly/rom/libEGL.dll.asm) | 299 | exported | Semantisch onderzoek open |
| [libEGLOverlay.dll](disassembly/rom/libEGLOverlay.dll.asm) | 299 | exported | Semantisch onderzoek open |
| [libGLESv1_CM.dll](disassembly/rom/libGLESv1_CM.dll.asm) | 752 | exported | Semantisch onderzoek open |
| [libGLESv2.dll](disassembly/rom/libGLESv2.dll.asm) | 698 | exported | Semantisch onderzoek open |
| [libMali.dll](disassembly/rom/libMali.dll.asm) | 1671 | exported | Semantisch onderzoek open |
| [libOpenVG.dll](disassembly/rom/libOpenVG.dll.asm) | 761 | exported | Semantisch onderzoek open |
| [libOpenVGU.dll](disassembly/rom/libOpenVGU.dll.asm) | 24 | exported | Semantisch onderzoek open |
| [mae_bsa.dll](disassembly/rom/mae_bsa.dll.asm) | 19 | exported | Semantisch onderzoek open |
| [mae_ite.dll](disassembly/rom/mae_ite.dll.asm) | 17 | exported | [Transactionlayout, registerkopieën, eventwacht en foutpropagatie gevolgd](camera-driver-chain.md) |
| [mae_mpe.dll](disassembly/rom/mae_mpe.dll.asm) | 19 | exported | Semantisch onderzoek open |
| [MaliDrv.dll](disassembly/rom/MaliDrv.dll.asm) | 277 | exported | Semantisch onderzoek open |
| [mempool.dll](disassembly/rom/mempool.dll.asm) | 17 | exported | [RVC-alloc/free-layout, regio's, 64KiB-rounding en caller-mapping gevolgd](camera-driver-chain.md) |
| [mgtt_o.dll](disassembly/rom/mgtt_o.dll.asm) | 438 | exported | [TTC/face-load en SFNT-bereikvalidatie aan AC3-pakket gekoppeld; verdere fontscaler/glyph/runtime open](ac3-font-contracts.md) |
| [mmtimer.dll](disassembly/rom/mmtimer.dll.asm) | 23 | exported | Semantisch onderzoek open |
| [mp3decfilter.dll](disassembly/rom/mp3decfilter.dll.asm) | 261 | exported | Semantisch onderzoek open |
| [mp3demux.dll](disassembly/rom/mp3demux.dll.asm) | 401 | exported | Semantisch onderzoek open |
| [msacmce.dll](disassembly/rom/msacmce.dll.asm) | 50 | exported | Semantisch onderzoek open |
| [msadpcm.dll](disassembly/rom/msadpcm.dll.asm) | 25 | exported | Semantisch onderzoek open |
| [msdmo.dll](disassembly/rom/msdmo.dll.asm) | 56 | exported | Semantisch onderzoek open |
| [mspart.dll](disassembly/rom/mspart.dll.asm) | 51 | exported | Semantisch onderzoek open |
| [ndis.dll](disassembly/rom/ndis.dll.asm) | 498 | exported | Semantisch onderzoek open |
| [ndisconfig.exe](disassembly/rom/ndisconfig.exe.asm) | 42 | exported | Semantisch onderzoek open |
| [ndispwr.dll](disassembly/rom/ndispwr.dll.asm) | 21 | exported | Semantisch onderzoek open |
| [ndisuio.dll](disassembly/rom/ndisuio.dll.asm) | 63 | exported | Semantisch onderzoek open |
| [netbios.dll](disassembly/rom/netbios.dll.asm) | 117 | exported | Semantisch onderzoek open |
| [netmui.dll](disassembly/rom/netmui.dll.asm) | 6 | exported | Semantisch onderzoek open |
| [netstat.exe](disassembly/rom/netstat.exe.asm) | 38 | exported | Semantisch onderzoek open |
| [netui.dll](disassembly/rom/netui.dll.asm) | 304 | exported | Semantisch onderzoek open |
| [nk.exe](disassembly/rom/nk.exe.asm) | 1 ⚠ tabelafwijking | exported | [34 OAL-codes, GPIO, klok/TLB/hardware/tracehandlers gevolgd; overige boot/kernel open](oal-ioctl-contracts.md) |
| [notify.dll](disassembly/rom/notify.dll.asm) | 91 | exported | Semantisch onderzoek open |
| [nspm.dll](disassembly/rom/nspm.dll.asm) | 25 | exported | Semantisch onderzoek open |
| [oalioctl.dll](disassembly/rom/oalioctl.dll.asm) | 16 | exported | [Volledige IOControl-filter en lokale registry/UUID-outputcontracten gevolgd](oal-ioctl-contracts.md) |
| [ogm.dll](disassembly/rom/ogm.dll.asm) | 336 | exported | Semantisch onderzoek open |
| [ole32.dll](disassembly/rom/ole32.dll.asm) | 683 | exported | Semantisch onderzoek open |
| [oleaut32.dll](disassembly/rom/oleaut32.dll.asm) | 507 | exported | Semantisch onderzoek open |
| [pcmdecfilter.dll](disassembly/rom/pcmdecfilter.dll.asm) | 263 | exported | Semantisch onderzoek open |
| [Physical_Manager.dll](disassembly/rom/Physical_Manager.dll.asm) | 23 | exported | [Alle vier IOCTLs en NOR erase/program/read/statushelpers gevolgd](boot-update-contracts.md) |
| [ping.exe](disassembly/rom/ping.exe.asm) | 28 | exported | Semantisch onderzoek open |
| [pm.dll](disassembly/rom/pm.dll.asm) | 218 | exported | Semantisch onderzoek open |
| [ppp.dll](disassembly/rom/ppp.dll.asm) | 486 | exported | [RAS/WAN, protocol/FSM, auth/crypto, CCP/MPPE-state en MPPC-token/hash/decodergrenzen gevolgd; exacte matchkeuzes/volledige FSM/lifetime open](mppc-contracts.md) |
| [psc_smbus.dll](disassembly/rom/psc_smbus.dll.asm) | 23 | exported | [SMB1-RVC-contract, adresvorming, lengtegrenzen en timeoutpaden gevolgd](camera-driver-chain.md) |
| [psdemuxfilter.dll](disassembly/rom/psdemuxfilter.dll.asm) | 478 | exported | Semantisch onderzoek open |
| [ptdemuxfilter.dll](disassembly/rom/ptdemuxfilter.dll.asm) | 424 | exported | Semantisch onderzoek open |
| [quartz.dll](disassembly/rom/quartz.dll.asm) | 2678 | exported | Semantisch onderzoek open |
| [rapisrv.exe](disassembly/rom/rapisrv.exe.asm) | 152 | exported | [TCP990/peerfilter/password, requestframing en 86-slot tabel gevolgd; volledige slotschema's/RPC/lifetime open](remote-service-contracts.md) |
| [regenum.dll](disassembly/rom/regenum.dll.asm) | 19 | exported | Semantisch onderzoek open |
| [repllog.exe](disassembly/rom/repllog.exe.asm) | 128 | exported | [AutoCnct/Cnct, commandline, RAPI/rnaapp launch en verbindingsmessages gevolgd; overige sync/launchtrigger open](remote-service-contracts.md) |
| [rnaapp.exe](disassembly/rom/rnaapp.exe.asm) | 31 | exported | [Opties/entryselectie, RasDial/HangUp en AutorasMsgqueue gevolgd; overige UI/TAPI/runtime open](remote-service-contracts.md) |
| [romfsd.dll](disassembly/rom/romfsd.dll.asm) | 54 | exported | Semantisch onderzoek open |
| [route.exe](disassembly/rom/route.exe.asm) | 33 | exported | Semantisch onderzoek open |
| [rra_stm.dll](disassembly/rom/rra_stm.dll.asm) | 44 | exported | Semantisch onderzoek open |
| [rsaenh.dll](disassembly/rom/rsaenh.dll.asm) | 332 | exported | [MD4-blok-API/foutgrenzen, DES-LM-keyexpansie/pariteit en RC4 KSA/PRGA gevolgd; overige provider/API/primitives open](mschap-crypto-contracts.md) |
| [sdbus.dll](disassembly/rom/sdbus.dll.asm) | 258 | exported | Semantisch onderzoek open |
| [sdio.dll](disassembly/rom/sdio.dll.asm) | 49 | exported | Semantisch onderzoek open |
| [sdmemory.dll](disassembly/rom/sdmemory.dll.asm) | 77 | exported | [Disk-sleep-IOCTL, standby-pogingen en gemaskeerde foutstatus gevolgd; overige SD/MMC-code open](boot-helper-contracts.md) |
| [serial.dll](disassembly/rom/serial.dll.asm) | 102 | exported | Semantisch onderzoek open |
| [services.exe](disassembly/rom/services.exe.asm) | 35 | exported | Semantisch onderzoek open |
| [servicesd.exe](disassembly/rom/servicesd.exe.asm) | 168 | exported | Semantisch onderzoek open |
| [servicesEnum.dll](disassembly/rom/servicesEnum.dll.asm) | 57 | exported | Semantisch onderzoek open |
| [servicesStart.exe](disassembly/rom/servicesStart.exe.asm) | 13 | exported | Semantisch onderzoek open |
| [shcore.dll](disassembly/rom/shcore.dll.asm) | 41 | exported | Semantisch onderzoek open |
| [shdocvw.dll](disassembly/rom/shdocvw.dll.asm) | 889 | exported | Semantisch onderzoek open |
| [shell.exe](disassembly/rom/shell.exe.asm) | 73 | exported | Semantisch onderzoek open |
| [shellcelog.dll](disassembly/rom/shellcelog.dll.asm) | 33 | exported | Semantisch onderzoek open |
| [shlwapi.dll](disassembly/rom/shlwapi.dll.asm) | 313 | exported | Semantisch onderzoek open |
| [softkb.dll](disassembly/rom/softkb.dll.asm) | 61 | exported | Semantisch onderzoek open |
| [stguil.cpl](disassembly/rom/stguil.cpl.asm) | 38 | exported | Semantisch onderzoek open |
| [system.cpl](disassembly/rom/system.cpl.asm) | 8 | exported | Semantisch onderzoek open |
| [tapi.dll](disassembly/rom/tapi.dll.asm) | 348 | exported | Semantisch onderzoek open |
| [tcpstk.dll](disassembly/rom/tcpstk.dll.asm) | 648 | exported | Semantisch onderzoek open |
| [timesvc.dll](disassembly/rom/timesvc.dll.asm) | 28 | exported | Semantisch onderzoek open |
| [toolhelp.dll](disassembly/rom/toolhelp.dll.asm) | 26 | exported | Semantisch onderzoek open |
| [TouchI2C.dll](disassembly/rom/TouchI2C.dll.asm) | 41 | exported | Semantisch onderzoek open |
| [tracert.exe](disassembly/rom/tracert.exe.asm) | 33 | exported | Semantisch onderzoek open |
| [tsdemuxfilter.dll](disassembly/rom/tsdemuxfilter.dll.asm) | 518 | exported | Semantisch onderzoek open |
| [udevice.exe](disassembly/rom/udevice.exe.asm) | 78 | exported | Semantisch onderzoek open |
| [udp2tcp.exe](disassembly/rom/udp2tcp.exe.asm) | 26 | exported | [Proxylaunch, registryports, TCP7438/UDP53, achtbyte frame en ring/reply/shutdown gevolgd; CRT/races/runtime open](remote-service-contracts.md) |
| [uiproxy.dll](disassembly/rom/uiproxy.dll.asm) | 12 | exported | Semantisch onderzoek open |
| [ULC_launcher.exe](disassembly/rom/ULC_launcher.exe.asm) | 15 | exported | [ROM-bootpad naar dboot/UpgradeManager gevolgd](research-02.md) |
| [unimodem.dll](disassembly/rom/unimodem.dll.asm) | 118 | exported | [Devicecfg/poortkeuze, twee serial handles, DCB/timeouts en TSPI-table deels gevolgd; volledige TAPI/lifetime open](ppp-transport-contracts.md) |
| [USB_PHY_enable.exe](disassembly/rom/USB_PHY_enable.exe.asm) | 21 | exported | [Complete applicatieroutine en CRT-call naar MGR1 code3 byte1 gevolgd; launch/runtime open](boot-helper-contracts.md) |
| [USBware.dll](disassembly/rom/USBware.dll.asm) | 1064 | exported | [UWD/iPod/audio en RMD-diskadapter, twee vaste hostcontrollers en DMA/SG deels gevolgd; volledig USB/iAP/recovery open](usb-controller-contracts.md) |
| [USBware2.dll](disassembly/rom/USBware2.dll.asm) | 395 | exported | [UDD-controller, vendorinterface/twee bulk-endpoints, JACM-callbacks en controlrequests gevolgd; IRQ/lifetime/unit open](usb-serial-contracts.md) |
| [uspce.dll](disassembly/rom/uspce.dll.asm) | 443 | exported | Semantisch onderzoek open |
| [veim.dll](disassembly/rom/veim.dll.asm) | 69 | exported | Semantisch onderzoek open |
| [waveapi.dll](disassembly/rom/waveapi.dll.asm) | 215 | exported | [WAM-init/driverketen en private-headercapaciteit/identiteit/write/automatische closecleanup/completionqueue gevolgd; begrensde fouttraces bevestigd; mixer/tables/lifetime/runtime open](wave-queue-contracts.md) |
| [wavedev2_i2s.dll](disassembly/rom/wavedev2_i2s.dll.asm) | 194 | exported | [PSC2/formats/PCM/queue/pumps/OEM-WAM en buitenste init/deinit/retry gevolgd; null-channel IRQ-read, genegeerde connect/initialize, stale-global retry en beperkte deinit met oorspronkelijke instructies bevestigd; kernel/unload/render/MMIO/unit open](wave-lifetime-contracts.md) |
| [wavedev2_i2s2.dll](disassembly/rom/wavedev2_i2s2.dll.asm) | 191 | exported | [PSC0/8k/formats/PCM/queue/pumps en buitenste init/deinit/retry gevolgd; null-channel IRQ-read, genegeerde connect/initialize, stale-global retry en beperkte deinit met oorspronkelijke instructies bevestigd; kernel/unload/mixing/MMIO/unit open](wave-lifetime-contracts.md) |
| [winsock.dll](disassembly/rom/winsock.dll.asm) | 38 | exported | Semantisch onderzoek open |
| [wmadecfilter.dll](disassembly/rom/wmadecfilter.dll.asm) | 342 | exported | Semantisch onderzoek open |
| [wmadmod.dll](disassembly/rom/wmadmod.dll.asm) | 621 | exported | Semantisch onderzoek open |
| [ws2.dll](disassembly/rom/ws2.dll.asm) | 172 | exported | Semantisch onderzoek open |
| [ws2instl.dll](disassembly/rom/ws2instl.dll.asm) | 37 | exported | Semantisch onderzoek open |
| [ws2k.dll](disassembly/rom/ws2k.dll.asm) | 363 | exported | Semantisch onderzoek open |
| [ws2serv.dll](disassembly/rom/ws2serv.dll.asm) | 186 | exported | Semantisch onderzoek open |
| [wspm.dll](disassembly/rom/wspm.dll.asm) | 46 | exported | Semantisch onderzoek open |
| [wzcsapi.dll](disassembly/rom/wzcsapi.dll.asm) | 40 | exported | Semantisch onderzoek open |
| [wzcsvc.dll](disassembly/rom/wzcsvc.dll.asm) | 291 | exported | Semantisch onderzoek open |
| [zlib.dll](disassembly/rom/zlib.dll.asm) | 57 | exported | [PNG-importketen, versie/header/Adler en uncompress-capaciteit/status aan metadata gekoppeld; volledige DEFLATE/encoder/dictionary/runtime open](png-metadata-contracts.md) |

## remove-md

| Module | .pdata-functies | Ghidra | Gevolgd gedrag |
| --- | ---: | --- | --- |
| [AppMain.exe](disassembly/remove-md/AppMain.exe.asm) | 1532 | exported | Semantisch onderzoek open |
| [Blue.exe](disassembly/remove-md/Blue.exe.asm) | 4435 | exported | Semantisch onderzoek open |
| [cMgrLog.exe](disassembly/remove-md/cMgrLog.exe.asm) | 31 | exported | Semantisch onderzoek open |
| [CmnDll.dll](disassembly/remove-md/CmnDll.dll.asm) | 70 | exported | Semantisch onderzoek open |
| [CodeChecker.exe](disassembly/remove-md/CodeChecker.exe.asm) | 183 | exported | Semantisch onderzoek open |
| [LangDllAra.dll](disassembly/remove-md/LangDllAra.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllBul.dll](disassembly/remove-md/LangDllBul.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllCro.dll](disassembly/remove-md/LangDllCro.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllCze.dll](disassembly/remove-md/LangDllCze.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllDan.dll](disassembly/remove-md/LangDllDan.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllDut.dll](disassembly/remove-md/LangDllDut.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllEng.dll](disassembly/remove-md/LangDllEng.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllFin.dll](disassembly/remove-md/LangDllFin.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllFre.dll](disassembly/remove-md/LangDllFre.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllGer.dll](disassembly/remove-md/LangDllGer.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllGre.dll](disassembly/remove-md/LangDllGre.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllHeb.dll](disassembly/remove-md/LangDllHeb.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllHun.dll](disassembly/remove-md/LangDllHun.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllIta.dll](disassembly/remove-md/LangDllIta.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllJap.dll](disassembly/remove-md/LangDllJap.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllNor.dll](disassembly/remove-md/LangDllNor.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllPol.dll](disassembly/remove-md/LangDllPol.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllPor.dll](disassembly/remove-md/LangDllPor.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllPTBR.dll](disassembly/remove-md/LangDllPTBR.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllRom.dll](disassembly/remove-md/LangDllRom.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllRus.dll](disassembly/remove-md/LangDllRus.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllSer.dll](disassembly/remove-md/LangDllSer.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllSlo.dll](disassembly/remove-md/LangDllSlo.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllSloven.dll](disassembly/remove-md/LangDllSloven.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllSpa.dll](disassembly/remove-md/LangDllSpa.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllSwe.dll](disassembly/remove-md/LangDllSwe.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllTur.dll](disassembly/remove-md/LangDllTur.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [LangDllUka.dll](disassembly/remove-md/LangDllUka.dll.asm) | 8 | exported | Semantisch onderzoek open |
| [EchoCanceller.dll](disassembly/remove-md/EchoCanceller.dll.asm) | 41 | exported | Semantisch onderzoek open |
| [MgrIpod.exe](disassembly/remove-md/MgrIpod.exe.asm) | 402 | exported | Semantisch onderzoek open |
| [MgrUSB.exe](disassembly/remove-md/MgrUSB.exe.asm) | 309 | exported | Semantisch onderzoek open |
| [MicomManager.exe](disassembly/remove-md/MicomManager.exe.asm) | 524 | exported | Semantisch onderzoek open |
| [RVC.dll](disassembly/remove-md/RVC.dll.asm) | 105 | exported | Semantisch onderzoek open |
| [sse.dll](disassembly/remove-md/sse.dll.asm) | 398 | exported | Semantisch onderzoek open |
| [UpgradeManager.exe](disassembly/remove-md/UpgradeManager.exe.asm) | 347 | exported | Semantisch onderzoek open |

## corruption-fix

| Module | .pdata-functies | Ghidra | Gevolgd gedrag |
| --- | ---: | --- | --- |
| [nngnavi.exe](disassembly/corruption-fix/nngnavi.exe.asm) | 24423 | exported | [Corruption-dialog gekoppeld aan lege accepted-mapvector; zes contenttypen, header/versiebounds, cachefallback en license-interface gevolgd; interne fixdiff/unit/volledige parsers open](navigation-content-contracts.md) |

## Open onderzoek

- AppMain: schermen, rendering, instellingen, audiofocus, events en dynamische functies.
- Blue: Bluetooth-stack, handsfree, A2DP, telefoonboek en koppelen.
- MICOM: alle commandogroepen, updatertransport, taakdispatchers en exacte chip/ISA.
- USB/iPod/DAB: resterende commando's, toestanden, codecs en foutpaden.
- RVC/audio: camera, overlays, echo cancellation, DSP en hardware-IOCTLs.
- ROM: resterende drivercontracten, kernel-/filesystemgedrag, OEM-registrypersistentie en resourceverwijzingen.
- Updater: volledige fasevolgorde, recovery, opslagindeling en oorspronkelijke navigatiepatch.
- Unitvergelijking: werkelijke hashes, registry en configuratie. Hiervoor ontbreekt een lokale dump.
