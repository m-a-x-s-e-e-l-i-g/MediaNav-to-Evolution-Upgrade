# Volledig gevolgd RVC-pad: SMB, CAM, mempool, ITE en display

De gevolgde cameraweergave heeft vijf afzonderlijke drivercontracten. De [camera-analyse](camera-contracts.md) beschrijft CAM-capture en instellingen; [display-overlay.md](display-overlay.md) beschrijft de laatste stap naar het LCD. Dit document vult de tussenliggende drivers in. Geen code is op de fysieke unit uitgevoerd.

| Stap | Apparaat | ROM-driver | Gevolgd gebruik |
| --- | --- | --- | --- |
| Decoderinstellingen | SMB1: | psc_smbus.dll | TW9900-gelabelde registerreads/writes |
| DMA-capture | CAM1: | camera.dll | Mode 0x1c, 720×480, twee DMA-kanalen |
| Geheugen | MEM1: | mempool.dll | Fysiek geheugen en virtuele mapping voor de caller |
| Beeldbewerking | ITE1: | mae_ite.dll | Transaction van 0x3a0 bytes, registers en completion-event |
| Uitvoer | Desktop-DC | ddi_au13xxlcd.dll | Window 3 configureren, buffer wisselen en inschakelen |

## SMB1: een afzonderlijk contract van I2C1:

RVC helper **`0x10001414`** opent `SMB1:` en maakt `MUTEXI2C`. De naam van de mutex betekent dus niet dat dit pad via `i2cbus.dll` loopt. De gevalideerde registry koppelt SMB aan `psc_smbus.dll`; de IOCTL-handler **`0xc092209c–0xc092213b`** herkent exact `0x80002000`, `0x80002001` en `0x80002002`. De afzonderlijke I2C_IOControl gebruikt codes 0, 1, 2 en 4 en een ander buffercontract.

SMB-write gebruikt input +0 als adresbyte, +4 als lengte-DWORD, +8 als data. De driver accepteert **lengte 0..7**. SMB-read-reg gebruikt +8 als registerbyte, leest **0..5 bytes** en levert ze in de outputbuffer. De RVC-wrapper plaatst die output op inputbuffer+9. De driver verschuift de adresbyte één bit en voegt voor de readfase bit 0 toe; dit is code-evidence voor de adresvorming.

RVC laat in de generieke wrapper lengtes onder 512 toe; de drivergrenzen zijn veel kleiner. De gevolgde TW9900-calls lezen/schrijven kleine waarden en passen daarbinnen. Er is geen aanname gemaakt dat iedere theoretische wrapperlengte werkt.

`SMB_Init!0xc0921f94` mapt fysieke basis **`0x10a03000`, lengte `0x24`** en logt PSC3. De read/write-helpers wachten vóór hun critical section tot mask `0x10000030` van register +14 nul is, met `Sleep(1)` en **zonder zichtbare deadline** in die lus. De afzonderlijke transactiewacht `0xc092171c` pollt eventbit `0x10` op register +18 met GetTickCount.

In die laatste helper verschillen de grenzen: loop zolang elapsed <3000 (`0xc0921778`), accepteer als succes zolang elapsed <3001 (`0xc0921784`). Een pad zonder completionbit maar met elapsed precies 3000 wordt dus als succes behandeld en wist het eventbit. Dit volgt uit de vergelijkingen; het is geen meting van een storing op deze unit. De onbegrensde pre-wacht en de latere poll zijn twee verschillende lussen.

## MEM1: 32-byte allocatiecontract

RVC **`0x1000165c`** maakt een 32-byte descriptor en geeft hem in-place aan `0x220404`. De driverhandler **`0xc0961704–0xc09618a3`** gebruikt:

| Descriptoroffset | Betekenis uit beide kanten |
| --- | --- |
| +0 | Teruggegeven interne allocatietoken, gebruikt bij free |
| +4 | Virtueel adres in het callerproces |
| +8 | Fysiek bufferadres |
| +c | Gevraagde bytegrootte |
| +10 | Mappingflags |
| +14 | Region-index |
| +18/+1c | Niet gebruikt door de gevolgde alloc/free-handler |

`0x220408` geeft een token vrij; `0x22040c` geeft de regioomvang terug. De allocatiehelper `0xc0961524` gebruikt GetCallerVMProcessId en VirtualAllocCopyEx voor de caller-mapping. De allocator `0xc09612f0` rondt een niet-aligned aanvraag **omhoog op 64 KiB** en splitst een vrije linked-list-entry. Het merge/free-pad is aanwezig op `0xc09613e4`.

Het apparaat heeft volgens de firmwaredefaults regio 0 MAE (`0x01d00000`, 1 MiB), regio 1 ITE (`0x0d200000`, 5 MiB) en regio 2 LCD (`0x0d700000`, 6 MiB). RVC kiest **regio 1**, flags 0. Het vraagt twee raw buffers en twee interleavingbuffers van 720×480×2, plus twee outputbuffers van displaybreedte×displayhoogte×2. Bij 800×480 gebruikt dat met de geobserveerde rounding 4.456.448 van 5.242.880 bytes, zonder rekening te houden met andere gebruikers/allocaties.

De wrapper controleert de IOCTL-return en fysiek adres +8. De startfunctie `0x10007224` slaat de zes wrapperresultaten op zonder afzonderlijke NULL-checks voordat de threads ze gebruiken. Allocatiefouten zijn daarom een nog niet runtime-geteste foutpadkwestie. De driver kan return 1 geven terwijl de interne allocatie faalt; het token en de adressen horen bij de succescontrole.

## ITE1: beeldtransaction en ontbrekende foutpropagatie

RVC **`0x10001a50`** gebruikt IOCTL **`0x232008`**, inputlengte **`0x3a0`**, magic **`0x050903a0`**. De handler **`0xc09c11b0–0xc09c123b`** geeft bij afwijkende magic alleen een debugmelding en gaat voor deze code alsnog verder. Hij toetst in dit pad niet de meegegeven inputlengte.

`ITE_Init!0xc09c1244` mapt **`0x14010000`, lengte `0x714`** en gebruikt interruptconstant `0x5c`. Transactionhelper **`0xc09c1000`** kopieert 192 DWORDs vanaf input+14 naar zes registerblokken van 0x80 bytes; overige inputvelden gaan naar registers +0/+4/+8, +400..430, +500..51c en +600..60c. Hij zet input+398 op nul, start via registers +704/+70c en wacht op een event met **INFINITE**.

De helper retourneert uiteindelijk de WaitForSingleObject-return; ITE_IOControl negeert die waarde en geeft **1** terug na de helpercall. RVC roept zijn submitwrapper aan zonder het resultaat te gebruiken voordat het displaybufferadres wordt gewisseld. Dat betekent dat de zichtbare BOOL-successroute geen volledige end-to-end verwerking bevestigt.

Het resource-initpad **`0xc09c15a4`** maakt drie events en een thread. Op sommige resourcefouten retourneert het waarde 1, terwijl ITE_Open dat als objectpointer verder gebruikt. Het normale pad retourneert de echte objectpointer. Dit foutpad is in assembly bevestigd; de daadwerkelijke foutconditie op de unit is niet aangetoond.

## Frames door de applicatie

Na het capture-event leest thread **`0x10006a8c–0x10006dc7`** de bufferindex. Hij weeft twee halve bronvelden met afwisselende memcpy's in een tussenbuffer, stelt bron/destinationadres en afmetingen in de ITE-transaction in, verstuurt die en geeft daarna het outputadres aan escape `0x229c78`, window 3. Na enkele iteraties schakelt hij de window in via `0x229c44` en post hij een gereedmelding naar het RVC-venster.

Hiermee is ook verklaard waarom capturebufferbreedte 720 en overlaybreedte 800 naast elkaar voorkomen: er zit een afzonderlijke verwerkingsstap met input-/outputgeometrie tussen. Exacte filtercoëfficiënten, scalerregisters, field order, frame-timing en de geometrie van guidelines blijven open.

Evidence: [RVC-disassembly](disassembly/RVC.dll.asm), [SMB-disassembly](disassembly/rom/psc_smbus.dll.asm), [mempool-disassembly](disassembly/rom/mempool.dll.asm), [ITE-disassembly](disassembly/rom/mae_ite.dll.asm), [gevalideerde bootregistry](boot-registry.md).
