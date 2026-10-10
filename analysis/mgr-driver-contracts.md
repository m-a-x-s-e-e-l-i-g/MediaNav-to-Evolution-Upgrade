# MGR1: dispatch, GPIO en verschillen tussen applicatie en ROM

De gevalideerde bootregistry koppelt MGR1 aan **DRVMGR.dll**. De onderzochte driver heeft SHA-256 `eef794a2c6e211d252832a30b59dbf5dab74045f377c9253653c0dc4c2740400` en logt een build op 28 november 2014. De hier besproken verbindingen zijn statisch gevolgd in dit pakket; de actieve driver op de fysieke unit is nog niet vergeleken.

## Alle publieke MGR_IOControl-codes

Handler **`0xc09a194c–0xc09a1d2f`** toetst eerst code <`0x15` en dispatcht via 21 signed 16-bit offsets op **`0xc09a1990`**. De [bytecontrole](firmware/mgr-driver-contracts.json) bewaart de oorspronkelijke tabel, adressen, driverhash en drie callerinstructies. [inspect_driver_contracts.py](../tools/inspect_driver_contracts.py) leest die rechtstreeks uit de PE-bytes.

| Code | Gevolgd gedrag |
| --- | --- |
| `0` | Resetselector in eerste inputbyte; alleen 0x0e/16/3e/3f heeft een GPIO-sequentie |
| `1` | GPIO-pin uit inputbyte lezen; schrijft 0 of 0xff naar **zevende argument pdwActualOut** |
| `2` | GPIO-pin uit inputbyte instellen; tweede byte 0 betekent LOW, anders HIGH |
| `3` | Niet-nul inputbyte: USB-PHY-helper uitvoeren; nul: fout 0x78 |
| `4` | Inputbyte kiest USB-testmodus, met vaste registerwrites |
| `5` | `start xm`: GPIO 0x44/0x2a met 51ms-wachten schakelen |
| `6` | `stop xm`: GPIO 0x44/0x2a laag zetten |
| `7/8` | Register +4 van 0x10a00000: bits 0/1 zetten/wissen |
| `9/a` | Zelfde voor 0x10a01000 |
| `b/c` | Zelfde voor 0x10a02000 |
| `d/e` | Zelfde voor 0x10a03000 |
| `f/10` | Register +0 van CAM-basis 0x14004000: bit 0 zetten/wissen |
| `11/12` | Geen bewerking; return 1 |
| `13` | BT-enable: GPIO 0x16 laag, Sleep(10), hoog |
| `14` | BT-disable: GPIO 0x16 laag |
| `15` en hoger | Buiten tabel: SetLastError(0x78), return 0 |

De GPIO-high/low-benamingen komen uit de debuglabels en calls met configuratie 3/2. De betekenis van de fysieke signaallijnen, PSC-registerbits en chipvariant is niet onafhankelijk op hardware bevestigd. `xm` en `CP` zijn driverlabels, geen aangetoonde geïnstalleerde functies.

Resethelper **`0xc09a14d0–0xc09a165f`** kent selector 0x0e (DAB), 0x16 (BT), 0x3e (CIM) en 0x3f (CP), elk met een eigen high/low- en Sleep-sequentie. Andere selectors retourneren zonder bewerking. De IOCTL-handler geeft ook dan **1** terug. De driver verricht tijdens MGR_Init al een reset met **0x16**; een mismatch in een latere caller betekent dus niet dat Bluetooth tijdens de hele boot nooit gereset wordt.

## Aangetoonde afwijkende callers

IOCTL 1 gebruikt een afwijkend outputcontract: de stackframe is 0x28 bytes en de pointerloads op `0xc09a1a00/1a30/1a70` lezen `sp+0x40`, dus `entry_sp+0x18`. Dat is in MIPS O32 het zevende argument, **pdwActualOut**, waarin de standaard Windows CE-streaminterface een byteaantal teruggeeft. Het vijfde argument pBufOut wordt in dit pad niet gebruikt. De code schrijft de pinstatus 0/0xff zonder NULL-controle naar deze pointer. Een caller moet daarom individueel worden onderzocht; dit is geen algemene aanbeveling om IOCTL 1 met de CmnDll-readwrapper aan te roepen. De bytecontrole bewaart deze drie loads. [Microsoft XXX_IOControl-contract](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms923699%28v%3Dmsdn.10%29).

**Blue 7.0.5.MD:** helper **`0x00033c8c–0x00033d33`** geeft selector **0x18** aan IOCTL 0. Het constante instructionword staat op `0x33ce4`; de call staat op `0x33d0c`. De helper wordt aangeroepen bij `BLUE_BT_reinitialize` en bij de destroy-handler. De meegeleverde ROM-resethelper herkent 0x18 niet: in deze combinatie wordt via die call geen resetsequentie uitgevoerd, terwijl MGR_IOControl succes teruggeeft.

**Blue downgrade 4.0.6:** helper **`0x0002c508–0x0002c5cf`** geeft wél **0x16** door. Dat past bij de onderzochte ROM-driver. Deze vergelijking is specifiek voor het resetcontract; de volledige Bluetooth-versiecompatibiliteit volgt er niet uit.

**MicomManager 7.0.5.MD:** helper **`0x0001ea70–0x0001eb17`** geeft selector **0x26** aan IOCTL 0. Ook die heeft geen uitvoerend pad in de ROM-resethelper. De call is conditioneel: een commandotak met selector 0x28 en waarde 0 gebruikt hem met een intervalcheck van ongeveer 62 seconden. De inhoudelijke betekenis van dat managercommando is nog open; de helper mag daarom niet zonder evidence als een bepaalde hardware-reset worden benoemd.

**USB en iPod:** hun externe-geheugenpaden vragen allocatie via **IOCTL 0x15** en free via **0x16** aan MGR1. Beide codes vallen buiten deze driverdispatch. De callers initialiseren de allocatieoutput op nul en vallen dan terug op gewone heapallocatie. Dit is een statisch bevestigd alternatief pad, geen bewijs van een geheugenlek of een fout bij normaal afspelen. Het freepad voor externe allocaties kan in deze specifieke drivercombinatie niet vanuit een geslaagde 0x15-allocatie ontstaan.

Deze verschillen tonen dat de applicatieverwachtingen ruimer/anders zijn dan dit ROM-contract. Ze identificeren geen veilige GPIO-patch voor deze unit: daarvoor ontbreken de vergelijking met de actieve binaries en de fysieke wiring. Er is geen firmware aangepast.

## CmnDll en GPINTR

CmnDll **MIOCTL_Dll_Init!0x10002ae8** opent MGR1 en maakt `MUTEXIOCTL`. Read-helper `0x100025b8` geeft uitsluitend een outputbuffer door, Write-helper `0x10002738` uitsluitend input; beide wachten INFINITE op de mutex en geven de DeviceIoControl-BOOL terug. WAIT_ABANDONED wordt hier niet als normaal verkregen ownership behandeld. De exports op `0x10002a70/2a8c` bewaren de return in `$v0`; de automatische pseudocode noemt deze wrappers ten onrechte `void`.

Dit is een andere interface dan de CmnDll-IPC-router. De twee nummerreeksen mogen niet worden gemengd. Een IOCTL waarvoor de ROM-handler input én output verwacht moet aan het feitelijke callcontract worden getoetst.

GPINTR.dll is grotendeels een bridge naar **KernelIoControl `0x01032c87`**, met een 16-byte inputrecord. Subcode +4 is 1 voor pinstate, 8 voor configuratie lezen, 0x10 voor configuratie schrijven, 0x20 voor resetwaarde en 2/4 voor outputstate. Pin-ID staat op +0; de configuratieparameter op +8. De GPINTR-stream Read/Write/IOControl-exports zijn hier dezelfde return-0-stub; de directe GPINTR-exports verrichten de kernelcalls. Het [gevolgde kernelpad](gpio-kernel-contracts.md) beschrijft alle subcodes, de ongebruikte vierde DWORD en de ROM-pintabel.

Evidence: [DRVMGR-disassembly](disassembly/rom/DRVMGR.dll.asm), [driver-pseudocode](decompiled/rom/DRVMGR.dll/decompiled.c), [Blue-disassembly](disassembly/Blue.exe.asm), [downgrade-Blue](disassembly/remove-md/Blue.exe.asm), [MICOM-disassembly](disassembly/MicomManager.exe.asm), [GPINTR-disassembly](disassembly/rom/gpintr.dll.asm).
