# ROM-audio: wave-API, dynamische device-ID's, PSC en DMA

De twee OEM-wavedrivers, `waveapi.dll` en `audevman.dll` zijn aan hun originele ROM-bytes gekoppeld. [wave-driver-contracts.json](firmware/wave-driver-contracts.json) bevat bronhashes, gelezen instructiebereiken en de twee gevalideerde boot-registrysecties; [inspect_wave_drivers.py](../tools/inspect_wave_drivers.py) reproduceert dit. Geen driver is uitgevoerd en er is geen unit benaderd.

## Twee hardwarepaden

| ROM-driver | Boot-registry Index / Order | Door code genoemde PSC | Fysieke MMIO-regio | DMA-selector TX / RX | PSC-config bij init |
| --- | --- | --- | --- | --- | --- |
| wavedev2_i2s.dll | 0 / 0 | PSC2, I2S | `0x10a02000`, 32 bytes | `0x0c` / `0x0d` | `0xf41d34f0` |
| wavedev2_i2s2.dll | 1 / 1 | PSC0, I2S2 | `0x10a00000`, 32 bytes | `0x12` / `0x13` | `0xf42c60f0` |

De PSC-nummers komen zowel uit logargumenten als de werkelijk aan `MmMapIoSpace` meegegeven adressen, niet uit de DLL-naam. Inithelpers zijn `0xc0948940` en `0xc095878c`. Beide drivers gebruiken prefix WAV en dezelfde audio-interfaceclass `{A32942B7-920C-486b-B0E6-92A702A99B35}`. De registry noemt Priority256 16 en giisr.dll/ISRHandler; de onderzochte initcode maakt daarnaast zelf een DMA-eventthread en SYSINTR-koppeling.

DMA-inithelpers `0xc09483c0`/`0xc09584ac` reserveren twee channels en geven de selectors uit de tabel aan `HalInitDmaChannel`. Richtingsargument 1 in start/stophelpers is receive; 2 is transmit. Receive zet PSC+0x10 naar 0x10; transmit naar 1. Eerste driver wacht bij transmitstart 1 ms voordat `HalStartDMA` wordt aangeroepen, tweede niet. Stop zet respectievelijk 0x20/2. De exacte CEDDK-selectorbetekenis en descriptoropbouw moeten nog naar de HAL worden gevolgd.

## Formats en hardware-samplefrequentie

De gemeenschappelijke PCM-validator `0xc09428b4`/`0xc095291c` accepteert format-tag 1, één of twee kanalen, 8 of 16 bits en nominale samplefrequentie 100..192000. Dit is slechts de formatcheck; hardware-instelling heeft eigen beperkingen. De outputvalidator kent daarnaast een afzonderlijke route voor format-tag 0x3000 of een aparte streamflag; de betekenis daarvan is nog niet volledig gevolgd.

I2S/PSC2 initialiseert de hardwarefrequentie op **48000 Hz**. Ratehelper `0xc0948660` heeft expliciete instellingen voor 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100 en 48000; een andere aanvraag wordt naar 48000 aangepast. DAC-/ADC-setters `0xc09489ec`/`0xc0948894` controleren actieve input/output-lijsten en minimumfrequenties voordat zij deze helper gebruiken. Een al actieve andere stream kan wijziging verhinderen. De hardware-ratehelper bevat meerdere registerwachtlussen zonder eigen deadline.

I2S2/PSC0 gebruikt helpers **`0xc0958714`/`0xc0958750`** die bij een lege betreffende streamlijst uitsluitend **8000** accepteren: return 8000 bij die aanvraag, anders 0. Een niet-lege lijst geeft de afzonderlijke waarde 1 terug. De device-wrapper `0xc09533a0`/`0xc0953418` vertaalt die 1 naar MMRESULT 4 en 0 naar 0x20. Een algemene PCM-formatacceptatie betekent dus niet dat deze driver 48 kHz kan openen.

Beide driverinitfuncties vragen hun devicecontexts aanvankelijk 48000 aan; de I2S2-route controleert die initiale setteruitkomst niet en configureert zijn PSC zelfstandig. De initcalls vormen geen bewijs dat I2S2 werkelijk op 48 kHz draait. Beide lezen MinDACSampleRate/MinADCSampleRate, standaard 8000, via hun registryhelper. De eerste zet context+0xe8 naar 0x1000, de tweede context+0xe4 naar 0x100; de volledige bufferbetekenis blijft te volgen.

## Waarom registry-index niet voldoende is voor waveInOpen(0/1)

De [EchoCanceller](echo-audio-contracts.md) opent HF als wave-device 0 op 48 kHz en BT als device 1 op 8 kHz. De registryvolgorde en hardware-ratehelpers passen bij **HF→I2S/PSC2** en **BT→I2S2/PSC0**. Dit is nog een afgeleide koppeling; de API-index is een index in een dynamische audiomanagerlijst.

`audevman.dll` initialiseert drie aparte devicearrays en maakt notificatiethead `0xc0413c38`. Die vraagt alle device-notificaties aan, herkent prefix WAV/MIX of de interface-GUIDs, opent de gemelde devicenaam en publiceert een of meer input/output/mixerobjects. Nieuwe input/outputobjects worden achteraan toegevoegd door `0xc04124b4`, met hun actuele array-index. `audmGetInputDevice`/`audmGetOutputDevice` lezen die arrays op API-index.

`audmSetInputDeviceId` en `audmSetOutputDeviceId` kunnen via helper `0xc04125b4` een object naar een andere positie verplaatsen, tussenliggende entries verschuiven en ID's herschrijven. Boot-registry Index 0/1 bepaalt daarom niet op zichzelf voor alle runtimefasen de wave-API-ID. Voor een definitieve unitkoppeling ontbreken de werkelijke notificatievolgorde, eventuele reordercalls en actieve-devicelijst.

## Wavebericht en foutpropagatie

`WAV_IOControl`, `0xc0942714`/`0xc0952774`, vereist callertrust 2; anders SetLastError(5) en FALSE. Het gewone wave-IOCTL is **0x1d000c** met een envelope van vijf DWORDs/20 bytes: device-index, message, stream/user-handle, param1 en param2. Dispatcher `0xc0942138` gebruikt de vier laatste velden. De audiomanager vraagt met die envelope het aantal input/outputdevices op: messages 0x32/3. Beide drivers retourneren daarvoor 1.

De dispatcher houdt een driver-critical-section vast tijdens verwerking. Hij retourneert zelf TRUE en schrijft de afzonderlijke MMRESULT als output-DWORD. Een succesvolle `DeviceIoControl` kan daarom samengaan met een geweigerd wavebericht. Openmessages 5/0x34 volgen device-validatie, samplefrequentiesetter, nieuwe streamcontext en stream-open; queryflag 1 vermijdt streamcreatie. In de eerste driver wordt de afzonderlijke setterreturn in de generic openhelper niet gebruikt om te stoppen; de verdere stream-open kan nog fouten opleveren.

De outer IOCTL-route herkent ook 0x321000/4/8/c en 0x80000100. De powerhelper van I2S handelt 0x321000, 0x321008 en 0x32100c af; 0x321004 komt niet als eigen afgehandelde branch voor. Power-set leest het outputpointerargument al voor zijn volledige lengte-/rangetest. D4 gebruikt een success-stub; andere states volgen reinitialisatie, waarvan helper `0xc09489cc` de echte inituitkomst negeert en 1 teruggeeft. De powerhelper slaat de aangevraagde state lokaal op. Werkelijk hardware-powergedrag is nog niet gemeten.

## Open

Het [wave-manager-/runtimequeuevervolg](wave-queue-contracts.md) volgt nu audevman-methode `c0412900` en WAM-write/prepare/unprepare/close/completion. Het bevestigt voorbereide-capaciteitsvalidatie vóór de driver, automatische private-headercleanup bij normaal afsluiten en twee callbackqueues met een beperkte 100-ms-barrier. Het vervangt geen onderzoek van de concrete OEM-streamvtable, mixer, DMA of unitdevicekeuze.

Het [OEM-streamvervolg](wave-stream-contracts.md) volgt inmiddels beide PCM-vtableketens, factoryselectie, private WAM-headerownership, queue/advance/WOM_DONE, reset/pause/restart en close. Begrensde oorspronkelijke instructies bevestigen 64 flag-, acht drain/close-, acht reset-, zes loop- en 108 factorycases; een gekoppelde OEM→WAM→coredll-trace bewaart de overgang van proxy naar original header. Directe PCM-readpointers en de 16-bit-stereorenderkernel zijn statisch gekoppeld. Dit meet geen DMA-/hardwarelatency en voltooit niet alle driverfuncties.

Het [DMA-vervolg](wave-dma-contracts.md) bevestigt twee startup-pumps en outputvensters van 4096/256 bytes met 130 oorspronkelijke instructietraces en bewaart de user-/kernel-DDK-init/getnext/activate/start/stophelpers. De interruptloop neemt dezelfde device-critical-section als wave-IOCTL. Descriptor-/registerfixtures, allocatiefoutafhandeling, alle overige locks en gemeten unitlatency blijven open.

De PSC-/DMA-adressen, registrycontracten, formatvalidator, ratehelpers, devicearray en wave-envelope zijn gevolgd. Open blijven de elektrische codec-/microfoon-/Bluetoothbedrading, alle mix/resamplekernels, de CEDDK DMA-implementatie, volledige power-/streamcleanup, actieve device-ID's en audio op de unit. Er is geen reden om deze beperkte driveranalyse als volledige kennis van alle ongeveer 385 .pdata-functies van beide DLLs te presenteren.
