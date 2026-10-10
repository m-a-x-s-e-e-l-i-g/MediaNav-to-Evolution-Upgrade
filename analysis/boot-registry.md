# Bootregistry: onafhankelijk gelezen FDF en correctie van de rootkeys

De originele `default.fdf` is 218.967 bytes, SHA-256 `57a6e2d77084215555041ceab8f6299c647123ae4b90468725c5963670b8f5c3`. De bytes zijn al onafhankelijk tegen NK.bin gecontroleerd. Nu zijn ook alle **3.095 records**, zonder restbytes, langs de reader in `filesys.dll` gelezen. Dit betreft firmwaredefaults; persistente instellingen op de unit kunnen hiervan afwijken.

## Fout in de externe tekstexport

De externe extractor noemt het eerste WORD van een KEY-record `reserved (=0)` en schrijft iedere sleutel onder HKLM. In deze firmware bevat dat veld echter root-ID's **0, 1 en 2**. De eerder gegenereerde `extracted/705md-rom/Registry/default.reg` is daardoor voor **470 van de 883 keyrecords** en **688 van de 2.212 valuerecords** verkeerd geroot. De originele FDF blijft intact. De HKLM-init- en driverbevindingen hebben root-ID 2 en worden door deze fout niet gewijzigd.

Gebruik voor vervolgonderzoek [records.json](firmware/boot-registry/records.json) of [default.validated.reg](firmware/boot-registry/default.validated.reg), geproduceerd door de eigen [inspect_boot_registry.py](../tools/inspect_boot_registry.py). Deze tool wijzigt noch de externe repository, noch de eerdere extractie.

| Root-ID | Handle in reader | Rootkey | KEY-records | VALUE-records |
| --- | --- | --- | ---: | ---: |
| 0 | `0x80000000` | HKEY_CLASSES_ROOT | 443 | 635 |
| 1 | `0x80000001` | HKEY_CURRENT_USER | 27 | 53 |
| 2 | `0x80000002` | HKEY_LOCAL_MACHINE | 413 | 1.524 |

De mapping is code-evidence: `filesys.dll` reader **`0xc0112024–0xc011230b`** laadt basis `0x80000000` op `0xc011213c`, leest de rootbyte op `0xc0112234`, telt die bij de basis op `0xc0112244` en roept de key-create-helper op `0xc011225c` aan. De numerieke handlebenamingen passen bij de [Microsoft predefined keys](https://learn.microsoft.com/en-us/windows/win32/sysinfo/predefined-keys). HKCR bevat hier onder andere extensies, ProgIDs en CLSIDs; HKCU gebruikersinstellingen; HKLM hardware, drivers en init.

## Recordcontract uit de firmware

De acht-byte header bestaat uit magic `b2 74 83 1d` en een little-endian DWORD met de volledige bestandsgrootte. Daarna volgen records met een WORD payloadlengte en WORD type. De validator `0xc0111abc–0xc0111c93` controleert magic, totale grootte en framing. De restore-reader gebruikt een buffer van `0x2202` bytes en weigert payloadlengtes ≥ die grens.

KEY, type 1, heeft een vier-byte prefix: **rootbyte, gereserveerde byte, aantal UTF-16 pathcodeunits, aantal UTF-16 classcodeunits**. Dat zijn bytevelden, geen twee WORDs. Path en optionele class volgen. De reader gebruikt `lbu` voor beide lengtes (`0xc01121f8`, `0xc0112214`). In dit bestand zijn alle gereserveerde bytes en classlengtes nul; maximale pathlengte inclusief NUL is 148 codeunits.

VALUE, type 2, heeft zes prefixbytes: WORD registrytype, byte namelengte, gereserveerde byte, WORD datalengte. Daarna volgen UTF-16 naam en de ongewijzigde data. De reader berekent de datapointer op `0xc01121a8–0xc01121bc` en roept de value-set-helper op `0xc01121d0` aan. Alle werkelijke namelengtes passen in één byte; maximum 39 codeunits.

De interne defaultnaam is `Default`. De setter `0xc010b7f8–0xc010ba93` vervangt een NULL/lege API-naam door die string op `0xc010b9bc–0xc010b9d4`. De offline tekstexport zet zulke namen om naar `@`; JSON bewaart zowel de opgeslagen als de leesbare naam. Er zijn 241 defaultwaarden. Er zijn geen dubbele root/path/valuenaam-combinaties in deze FDF, vergeleken zonder hoofdletterverschil.

De gevonden registrytypes zijn 970 REG_SZ, 124 REG_BINARY, 745 REG_DWORD, 17 REG_MULTI_SZ en 356 waarden met type `0x15`. Alle REG_SZ-waarden hebben geldige UTF-16 met precies één afsluitende NUL. Type `0x15` bevat onder andere strings als `ceshell.dll,#24581`; dit past bij resourceverwijzingen, maar de volledige resolutiesemantiek blijft open. De export bewaart dit als `hex(15)` en maakt er geen gewone REG_SZ van.

## Boot/herstelpad

`prgInitRegistry` **`0xc0112edc–0xc01131a7`** heeft paden voor registrydata van de OEM, `\Windows\Restore.fdf` en `\Windows\Default.fdf`, en roept daarna kernel-registryinit en locale-init aan. Dat is een ROM-bootmechanisme, geen bewijs welke persistente route de unit bij iedere start kiest.

De file-helper `0xc011230c–0xc01123f7` toetst bestaan en attribuutbit 4, valideert de framing en probeert restore. Na openen/valideren verwerkt hij ook het bestand-verwijderpad; het gedrag van de ROM-filesystemlaag en foutcodes bepaalt wat daarvan werkelijk verdwijnt. De precieze OEM-opslag en herstartscenario's blijven vervolgonderzoek.

## Verificatie

De eigen decoder controleert headergrootte, alle recordgrenzen, root-ID's, bytevelden, exacte veldlengtes en strikte UTF-16. Alle oorspronkelijke recordbytes worden behouden en opnieuw samengevoegd tot **exact dezelfde 218.967 bytes**. Een fixture met Unicode, classnaam, HKCU en default-DWORD is gecontroleerd; negen gevallen met afgekorte bytes, verkeerde lengte/type/root, reserved byte en orphan value zijn afgewezen. De tekstexport is een onderzoeksartifact, geen actie op de Windows-registry van deze pc.

Evidence: [filesys-disassembly](disassembly/rom/filesys.dll.asm), [onafhankelijke ROM-verificatie](rom-verification.md), [externe parser met foutieve rootaanname](../sources/extract-wince-rom/winmob_extract/registry.py).
