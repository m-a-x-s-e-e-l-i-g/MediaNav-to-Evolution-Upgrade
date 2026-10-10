"""Regenerate research coverage without equating disassembly with understanding."""
from pathlib import Path
from collections import Counter
import json
from datetime import datetime, timezone

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/"analysis"

REVIEW={
    "CmnDll.dll":("IPC-routing en berichtformaat deels handmatig bevestigd","research-02.md"),
    "UpgradeManager.exe":("LGU/ZIP, staging/marker/cleanup, kopieerfouten, configbackup/format, versiecommit en apps-MICOM-controlpad gevolgd; native reparatie/volledige recovery/directoryparsing open","updater-recovery-contracts.md"),
    "fatutil.dll":("FormatVolume-dispatch, FAT/TFAT en exFAT-keuze aan updater gekoppeld; overige formatter/scan open","updater-storage-contracts.md"),
    "CodeChecker.exe":("Radiocode-invoer, registryread, pogingteller, factory/MICOM-wachttijden en IPC gevolgd; GUI en provisioning open","codechecker-contracts.md"),
    "MicomManager.exe":("COM2/ULC, HEX/blokken, AB-statusverlies, MCU-updateketen en CE-opstarttimer/flashmarker/A6-event gevolgd; volledige commands/power/unit/readback en native reparatie open","micom-flash-marker-contracts.md"),
    "MgrUSB.exe":("UI/IPC/seek, catalogus/repeat/shuffle, playlists/resume, ID3/ASF/tekstkopieën/hoesstride, allocatiepoolcleanup en COM-creatie/events/Stop/Pause gevolgd; pixeldecoders/sortering/races open","usb-metadata-contracts.md"),
    "imaging.dll":("Factory/stream/IImage, BMP, PNG-chunks/rijen/54 scatterhelpers/pixels/tRNS, tekst/ICC/DPI/tijd/properties/cleanup gevolgd; malformed/SetProperty/sink/overige codecs/GDI/concurrency open","png-metadata-contracts.md"),
    "zlib.dll":("PNG-importketen, versie/header/Adler en uncompress-capaciteit/status aan metadata gekoppeld; volledige DEFLATE/encoder/dictionary/runtime open","png-metadata-contracts.md"),
    "MgrIpod.exe":("UWD-versie/IOCTL, callbacks, audiofocus, list/status/UID-layout en artwork gevolgd; volledig iAP/auth/encoding open","ipod-contracts.md"),
    "USBware.dll":("UWD/iPod/audio en RMD-diskadapter, twee vaste hostcontrollers en DMA/SG deels gevolgd; volledig USB/iAP/recovery open","usb-controller-contracts.md"),
    "USBware2.dll":("UDD-controller, vendorinterface/twee bulk-endpoints, JACM-callbacks en controlrequests gevolgd; IRQ/lifetime/unit open","usb-serial-contracts.md"),
    "jacmdev.dll":("COM5-init/open/read/write/IOCTL, USB-callbackbrug en ringbuffer deels gevolgd; volledige event/lifetime/powerstate open","usb-serial-contracts.md"),
    "jacminit.exe":("Volledige applicatieroutine: RAS-entrybouw, registryvelden en AutoCnct-branches gevolgd; RAS/runtime open","usb-serial-contracts.md"),
    "autoras.dll":("ARS1 launch/IOCTL/queue, entryselectie en 30s-wacht gevolgd; adapterdetails/runtime/lifetime open","remote-service-contracts.md"),
    "repllog.exe":("AutoCnct/Cnct, commandline, RAPI/rnaapp launch en verbindingsmessages gevolgd; overige sync/launchtrigger open","remote-service-contracts.md"),
    "rnaapp.exe":("Opties/entryselectie, RasDial/HangUp en AutorasMsgqueue gevolgd; overige UI/TAPI/runtime open","remote-service-contracts.md"),
    "rapisrv.exe":("TCP990/peerfilter/password, requestframing en 86-slot tabel gevolgd; volledige slotschema's/RPC/lifetime open","remote-service-contracts.md"),
    "ppp.dll":("RAS/WAN, protocol/FSM, auth/crypto, CCP/MPPE-state en MPPC-token/hash/decodergrenzen gevolgd; exacte matchkeuzes/volledige FSM/lifetime open","mppc-contracts.md"),
    "unimodem.dll":("Devicecfg/poortkeuze, twee serial handles, DCB/timeouts en TSPI-table deels gevolgd; volledige TAPI/lifetime open","ppp-transport-contracts.md"),
    "asyncmac.dll":("NDIS/TAPI/serial-HANDLE, PPP/SLIP framing, CRC, buffers en partial I/O gevolgd; overige OID/lifetime/runtime open","ppp-transport-contracts.md"),
    "eap.dll":("Registrypluginloader, session/callbacks, packetparser/notification, timers en VSA/MPPE deels gevolgd; UI/registry/lifetime open","eap-contracts.md"),
    "eapchap.dll":("Types4/26 context/framing/MD5, MSV2 response/servercheck en MPPE-attributen gevolgd; UI/change-password/rolinterpretatie open","mschap-crypto-contracts.md"),
    "rsaenh.dll":("MD4-blok-API/foutgrenzen, DES-LM-keyexpansie/pariteit en RC4 KSA/PRGA gevolgd; overige provider/API/primitives open","mschap-crypto-contracts.md"),
    "afd.dll":("Hosts-registrylookup en speciale ppp_peer-resolutie gevolgd; overige sockets/DNS/network open","remote-service-contracts.md"),
    "udp2tcp.exe":("Proxylaunch, registryports, TCP7438/UDP53, achtbyte frame en ring/reply/shutdown gevolgd; CRT/races/runtime open","remote-service-contracts.md"),
    "MgrDAB.exe":("Update/SPI, opties, station/preset/scan/EPG-layouts deels gevolgd; driver, images en volledige tunerstate open","dab-shared-contracts.md"),
    "AppMain.exe":("Startup, managers, GDI/touch/tekst/RTL en USB/IPC/BT gevolgd; acht-recordbasis/caller/reconnect/count-ACK, cacheprovenance en originele allocatie/mapping/destructor-faults gevolgd; aparte safe-copy-proef begrenst count/NULL, wist stale actieve/PB-status en volgt 368 copy/18 krimp/12 callbackcases, 122 volledige UI- en 222 geldige/18 NULL-HFP-traces; negatieve-index UI-store naar object+232 en stale-count Empty-connect gereproduceerd/geguard in zes UI- en zes profielparen; acht andere connect-failuresuffixes gevolgd; cachelezers/snapshotgeneratie/locking/heap/destructor/complete profielaanloop/native werking open","bt-safe-copy-draft.md"),
    "gwes.dll":("Fontextensies/-directory, AC3-suffix, mapping en driverload gekoppeld; overige GUI/kernelcontracten open","ac3-font-contracts.md"),
    "mgtt_o.dll":("TTC/face-load en SFNT-bereikvalidatie aan AC3-pakket gekoppeld; verdere fontscaler/glyph/runtime open","ac3-font-contracts.md"),
    "coredll.dll":("rand_s/CeGenRandom/wavecalls/queues/barrier/async-PCM gevolgd; FreePhysMem en VirtualFree MEM_RELEASE-syscallargumenten gelijk bevestigd; oorspronkelijke memset-export/leaf aan CBtData failed buffers gekoppeld, 160 alignment/lengte/waarde-cases en native NULL-storewitness; objectlifetime/allocator/kernel/runtime open","bt-data-cache-lifecycle.md"),
    "Blue.exe":("BlueEarth/A2DP/lifecycle/MAX02, acht-recordopslag/I/O/callers/GUI/security/reconnect/count-ACK, SC/CM/DM/cache/HCI en BCSP/H4DS-transport gevolgd; cleanupvariant repareert globale-head-free en herhaalde payloadfree; geregistreerde RX/mblk/DM_HCI/key-command-completion volgt 216 traces; BCSP SLIP/header/CRC/sequence en H4-eventframing tot decoder volgen 60 normale traces, dertien vastgezette foutprobes, 30 hersteltraces en vier BCSP-duplicaatcases; inner korte events bereiken decoderread via beide parsers, outer BCSP-fouten/duplicaten geweigerd; volledige ACK/retransmit/serialdriver/overige events/profile/power/timers/concurrency/radio/controller/heap/unit en gezamenlijke pairingupdate open","bt-rx-frame-contracts.md"),
    "EchoCanceller.dll":("Zeven exports, PCM/buffers/samplepad, SSE-calls en TCP-debug gevolgd; opname/shutdown/runtime open","echo-audio-contracts.md"),
    "sse_int.dll":("382 parameterrecords, switch/accessenum, processingdispatch, BSD-container/moduleverdeling en 13 MAIN_Config-schema's gevolgd; DSP en overige payloadschema's open","sse-bsd-contracts.md"),
    "wavedev2_i2s.dll":("PSC2/formats/PCM/queue/pumps/OEM-WAM en buitenste init/deinit/retry gevolgd; null-channel IRQ-read, genegeerde connect/initialize, stale-global retry en beperkte deinit met oorspronkelijke instructies bevestigd; kernel/unload/render/MMIO/unit open","wave-lifetime-contracts.md"),
    "wavedev2_i2s2.dll":("PSC0/8k/formats/PCM/queue/pumps en buitenste init/deinit/retry gevolgd; null-channel IRQ-read, genegeerde connect/initialize, stale-global retry en beperkte deinit met oorspronkelijke instructies bevestigd; kernel/unload/mixing/MMIO/unit open","wave-lifetime-contracts.md"),
    "audevman.dll":("Dynamische notificaties/device-ID's en wavebericht-envelope/DeviceIoControl-MMRESULT gevolgd; overige mixer/runtime open","wave-queue-contracts.md"),
    "waveapi.dll":("WAM-init/driverketen en private-headercapaciteit/identiteit/write/automatische closecleanup/completionqueue gevolgd; begrensde fouttraces bevestigd; mixer/tables/lifetime/runtime open","wave-queue-contracts.md"),
    "glnavi.exe":("Launcher: overlay activeren en nngnavi met argumenten starten","research-03.md"),
    "RVD.dll":("Vijf RVC-wrapperexports gevolgd, venster 800x480; camera-runtime open","research-03.md"),
    "RVC.dll":("Config en SMB/CAM/mempool/ITE/displayketen gevolgd; runtime en filters open","camera-driver-chain.md"),
    "camera.dll":("18 modes en drie CAM-IOCTLs gekoppeld aan RVC; registers deels gevolgd","camera-contracts.md"),
    "ddi_au13xxlcd.dll":("RVC-escapes en glnavi-vrijgave gekoppeld aan windowregisters; overige displaycode open","display-overlay.md"),
    "filesys.dll":("FDF-framing, rootkeys, defaultnaam en boot-restorepad gevolgd; overige filesystemcode open","boot-registry.md"),
    "psc_smbus.dll":("SMB1-RVC-contract, adresvorming, lengtegrenzen en timeoutpaden gevolgd","camera-driver-chain.md"),
    "mempool.dll":("RVC-alloc/free-layout, regio's, 64KiB-rounding en caller-mapping gevolgd","camera-driver-chain.md"),
    "mae_ite.dll":("Transactionlayout, registerkopieën, eventwacht en foutpropagatie gevolgd","camera-driver-chain.md"),
    "DRVMGR.dll":("Alle 21 IOCTL-codes, resetselectors en mismatch met Blue/MICOM/USB/iPod gevolgd","mgr-driver-contracts.md"),
    "gpintr.dll":("Directe GPIO-exports, NK/OAL-handler en 43 platformrecords gekoppeld","gpio-kernel-contracts.md"),
    "nk.exe":("34 OAL-codes, GPIO, klok/TLB/hardware/tracehandlers gevolgd; overige boot/kernel open","oal-ioctl-contracts.md"),
    "oalioctl.dll":("Volledige IOControl-filter en lokale registry/UUID-outputcontracten gevolgd","oal-ioctl-contracts.md"),
    "ceddk.dll":("CPU/PBUS/klok/TLB en DMA-runtimeconfig/select/activate/IRQ/ack/stop gevolgd; unchecked allocaties/verkeerde free/mutex/initreturns en herhaalde mapping/allocator-free met oorspronkelijke instructies bevestigd; kernelcleanup/concurrency/unit/overige DDK open","dma-mapping-contracts.md"),
    "k.ceddk.dll":("Eigen DMA-runtimeconfig/select/activate/IRQ/ack/stop en allocatie/cleanupfouttraces bevestigd; oorspronkelijke mapper/unmap/herhaalde allocator-free gekoppeld; kernelcleanup/concurrency/unit/overige kernel-DDK open","dma-mapping-contracts.md"),
    "Physical_Manager.dll":("Alle vier IOCTLs en NOR erase/program/read/statushelpers gevolgd","boot-update-contracts.md"),
    "dboot.exe":("Bootkeuze, eenmalige StartWinCE-marker, desktopshortcuts en drag-menu gevolgd; overige debugfuncties open","boot-helper-contracts.md"),
    "dmenu.exe":("800x480 menu, marker/rebootvolgorde, COM2-frameconstructie, threads en disk-sleep gevolgd; hardware/CRT open","boot-helper-contracts.md"),
    "cereboot.exe":("Prompt, close/terminate-reeks, COM2-frames, MGR/disk-sleep/powercalls gevolgd; hardware/CRT open","boot-helper-contracts.md"),
    "USB_PHY_enable.exe":("Complete applicatieroutine en CRT-call naar MGR1 code3 byte1 gevolgd; launch/runtime open","boot-helper-contracts.md"),
    "sdmemory.dll":("Disk-sleep-IOCTL, standby-pogingen en gemaskeerde foutstatus gevolgd; overige SD/MMC-code open","boot-helper-contracts.md"),
    "ULC_launcher.exe":("ROM-bootpad naar dboot/UpgradeManager gevolgd","research-02.md"),
}


def main():
    modules=json.loads((OUT/"corpus/modules.json").read_text(encoding="utf-8"))
    rows=[]
    for module in modules:
        origin=module["origin"];name=module["name"]
        asm=OUT/"disassembly"/("" if origin=="705md" else origin)/(name+".asm")
        directory=OUT/"decompiled"/origin/name
        run=json.loads((directory/"run.json").read_text()) if (directory/"run.json").exists() else {}
        gh=json.loads((directory/"summary.json").read_text(encoding="utf-8")) if (directory/"summary.json").exists() else {}
        exported=run.get("status")=="exported" and gh.get("executable_sha256","").lower()==module["sha256"]
        log=(directory/"headless.log").read_text(encoding="utf-8",errors="replace") if (directory/"headless.log").exists() else ""
        timed_out="Analysis timed out" in log
        if "resume_analysis_timed_out" in run:timed_out=run["resume_analysis_timed_out"]
        failed=[f for f in gh.get("functions",[]) if not f.get("decompiled")] if exported else []
        recovered=[]
        for entry in failed:
            retry=directory/"recovered-functions"/(entry["address"]+".json")
            if retry.exists():
                result=json.loads(retry.read_text(encoding="utf-8"))
                if result.get("decompiled") and result.get("executable_sha256","").lower()==module["sha256"]:
                    recovered.append(entry["address"])
        review=REVIEW.get(name) if origin in ("705md","rom") else None
        if origin=="corruption-fix" and name=="nngnavi.exe":
            review=("Corruption-dialog gekoppeld aan lege accepted-mapvector; zes contenttypen, header/versiebounds, cachefallback en license-interface gevolgd; interne fixdiff/unit/volledige parsers open","navigation-content-contracts.md")
        if origin=="705md" and name.startswith("LangDll"):
            review=("RT_STRING-resources uitgelezen; gedeelde codehash bevestigd","research-03.md")
        rows.append(dict(origin=origin,name=name,sha256=module["sha256"],path=module["path"],
                         disassembled=asm.exists(),pdata_functions=len(module["functions"]),
                         function_table_anomalies=len(module["function_table_anomalies"]),
                         ghidra_status=run.get("status","legacy_export" if gh else "not_started"),
                         ghidra_analyzer_timed_out=timed_out,
                         decompiled_candidates=gh.get("functions_decompiled",0)+len(recovered) if exported else 0,
                         failed_function_candidates=[f for f in failed if f["address"] not in recovered],
                         recovered_function_candidates=recovered,
                         reviewed_scope=review[0] if review else "Semantisch onderzoek open",report=review[1] if review else None))
    summary=dict(generated_utc=datetime.now(timezone.utc).isoformat(),scope="Beschikbare pakketten, niet een volledige dump van de fysieke unit",
                 binary_execution=False,inventory_modules=len(rows),origin_counts=dict(Counter(r["origin"] for r in rows)),
                 disassembled=sum(r["disassembled"] for r in rows),pdata_function_candidates=sum(r["pdata_functions"] for r in rows),
                 decompiler_exported=sum(r["ghidra_status"]=="exported" for r in rows),
                 decompiler_analysis_timeouts=sum(r["ghidra_analyzer_timed_out"] for r in rows),
                 decompiler_function_candidates=sum(r["decompiled_candidates"] for r in rows),
                 decompiler_function_failures=sum(len(r["failed_function_candidates"]) for r in rows),
                 meaning="Automatische dekking is geen percentage begrepen gedrag",modules=rows)
    (OUT/"research-status.json").write_text(json.dumps(summary,indent=2,ensure_ascii=False),encoding="utf-8")
    lines=["# Onderzoeksdekking per executable en DLL","",f"Momentopname: {summary['generated_utc']}.","",
           f"**{len(rows)} PE-bestanden geïnventariseerd; {summary['disassembled']} disassemblies; {summary['pdata_function_candidates']:,} functiegrenzen uit .pdata.**".replace(",","."),"",
           f"Ghidra heeft voor {summary['decompiler_exported']} modules pseudocode geëxporteerd ({summary['decompiler_function_candidates']:,} functiekandidaten). Dat zegt niets over hoeveel gedrag handmatig bewezen is.","",
           f"Er zijn {summary['decompiler_analysis_timeouts']} analyzertime-outs en {summary['decompiler_function_failures']} afzonderlijke functie-exports die nog niet slagen. Foutdetails staan per module in research-status.json.","",
           "Dit betreft de aanwezige 7.0.5.MD-update, gereconstrueerde ROM, downgrade en navigatiefix. Dynamisch geladen bestanden, persistente configuratie, bootloader en bestanden op de echte unit kunnen ontbreken.","",
           "De kolom 'gevolgd gedrag' beschrijft uitsluitend het onderzochte deel. Een open module heeft wel imports/exports, secties, versiemetadata, strings, resources en disassembly. Geen firmwarecode is uitgevoerd.",""]
    for origin in ("705md","rom","remove-md","corruption-fix"):
        lines.extend([f"## {origin}","","| Module | .pdata-functies | Ghidra | Gevolgd gedrag |","| --- | ---: | --- | --- |"])
        for row in rows:
            if row["origin"]!=origin:continue
            scope=row["reviewed_scope"]
            if row["report"]:scope=f"[{scope}]({row['report']})"
            anomaly=" ⚠ tabelafwijking" if row["function_table_anomalies"] else ""
            asm_path="disassembly/"+("" if origin=="705md" else origin+"/")+row["name"]+".asm"
            timeout="; analyzer onvolledig" if row["ghidra_analyzer_timed_out"] else ""
            if row["failed_function_candidates"]:timeout+=f"; {len(row['failed_function_candidates'])} functiefouten"
            lines.append(f"| [{row['name']}]({asm_path}) | {row['pdata_functions']}{anomaly} | {row['ghidra_status']}{timeout} | {scope} |")
        lines.append("")
    lines.extend(["## Open onderzoek", "",
                  "- AppMain: schermen, rendering, instellingen, audiofocus, events en dynamische functies.",
                  "- Blue: Bluetooth-stack, handsfree, A2DP, telefoonboek en koppelen.",
                  "- MICOM: alle commandogroepen, updatertransport, taakdispatchers en exacte chip/ISA.",
                  "- USB/iPod/DAB: resterende commando's, toestanden, codecs en foutpaden.",
                  "- RVC/audio: camera, overlays, echo cancellation, DSP en hardware-IOCTLs.",
                  "- ROM: resterende drivercontracten, kernel-/filesystemgedrag, OEM-registrypersistentie en resourceverwijzingen.",
                  "- Updater: volledige fasevolgorde, recovery, opslagindeling en oorspronkelijke navigatiepatch.",
                  "- Unitvergelijking: werkelijke hashes, registry en configuratie. Hiervoor ontbreekt een lokale dump.",""])
    (OUT/"research-status.md").write_text("\n".join(lines),encoding="utf-8")
    print(json.dumps({k:v for k,v in summary.items() if k!="modules"},ensure_ascii=False,indent=2))


if __name__=="__main__":main()
