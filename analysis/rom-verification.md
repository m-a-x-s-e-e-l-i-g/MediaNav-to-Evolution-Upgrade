# Onafhankelijke ROM-byteverificatie

Onderzoek op 8 oktober 2026 aan de NK.bin uit de 7.0.5.MD-update. SHA-256 van de bron: `8b2bd9944565f2b9ec2af6e2e1f0aa8620db9456c4b36329a140f70835db6de1`. Er is geen firmwarecode uitgevoerd.

## Resultaat

| Onderdeel | Controle | Uitkomst |
| --- | --- | --- |
| NK-container | 114 records, checksums en terminalrecord | Geldig |
| Modulecatalogus | Namen en TOC | 164 ROM-modules |
| Unieke ongecomprimeerde secties | Bronbytes tegen PE-sectiebytes | 265 matches |
| Gecomprimeerde modulesecties | Tweede LZX-decoder tegen extractie | 287 matches |
| Gedeelde RVA's van nk.exe/kernel.dll | Primaire bytes en bewaarde shadowbytes | Vier matches |
| Secties zonder bronbytes | Geen gegevens om bytegewijs te vergelijken | Twee records |
| Losse gecomprimeerde ROM-files | Tweede decoder tegen uitgepakt bestand | 29 matches |
| Losse ongecomprimeerde ROM-files | Rechtstreeks tegen bronbytes | 20 matches |
| Synthetische .cerom TOC-metadata | Vergelijking met oorspronkelijke module-TOC | 164 matches |

De 558 originele o32-sectierecords vallen hiermee allemaal onder een bytecontrole of de expliciete categorie zonder bronbytes. Dit valideert de onderzochte bytes en metadata. Het bewijst geen correcte runtime-MMU-indeling, relocation, functiegrenzen, hardwarevariant of bestandenset op de fysieke unit.

## Tweede LZX-decoder

De eerste extractor gebruikt wince_decompr in Python. Voor een onafhankelijke decoder is de hostutility **Windows expand.exe** gebruikt. De aanwezige binary heeft een geldige Microsoft Windows-signatuur en SHA-256 `e5cd2d9536b0729ce90368dce9d923dccfa6f75f2996e31bb349e6a75a2aa897`.

Elke CE-sectie/file heeft een tabel van 24-bit little-endian offsets en één of meer losse compressieblokken. De tool verwijdert de CE-tabel en de 16-byte wrapper van een blok en zet **de bestaande gecomprimeerde LZX-stream ongewijzigd** in een minimale CAB-folder. Per folder staat één stream, met zijn originele windowbits en opgegeven uitvoerlengte. Er wordt geen decompressie/recompressie vóór expand gedaan.

In totaal zijn **718 streams** met expand.exe verwerkt, gegroepeerd in vier tijdelijke CABs. De uitkomsten zijn per oorspronkelijke sectie/file samengevoegd en met de bestaande extractie vergeleken. Waar de CE-sectie groter is dan de gedeclareerde streamuitvoer is de afzonderlijk gerapporteerde tail nulpadding; file-uitvoer moet exact de oorspronkelijke bestandsgrootte hebben.

De gebruikte opdracht is `expand.exe -R <cab> -F:* <uitvoerdirectory>`. `-R` behoudt hier de interne namen van de losse controleblokken; zonder die flag gaf de eerste één-file-proef het resultaat de CAB-bestandsnaam. De [Microsoft-documentatie](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/expand) beschrijft de CAB-extractieparameters. De tijdelijke CABs bevatten uitsluitend `.dat`-namen en worden niet uitgevoerd.

Tool en evidence: [verify_rom_lzx.py](../tools/verify_rom_lzx.py), [resultaten en hashes](705md-rom-lzx-verification.json). Tijdelijke bronblokken, CABs en uitvoer staan onder de in het rapport genoemde, genegeerde werkdirectory; de firmwarebronnen blijven ongewijzigd.

## Gedeelde RVA's en .cerom

`nk.exe` heeft twee o32-records met RVA `0xc000`; `kernel.dll` twee met RVA `0x42000`. De extractor bewaart per groep één primaire sectie zichtbaar in het PE-bestand en de overige bytes in zijn **eigen synthetische `.cerom`-sectie**. Standaard PE-tools gebruiken die shadowbytes niet automatisch als runtimegeheugen.

[verify_rom_aliases.py](../tools/verify_rom_aliases.py) leest de `.cerom`-header, objectrecords en TOC opnieuw zonder de extractorparser te importeren. De oorspronkelijke zes o32-velden en negen TOC-velden worden tegen NK.bin gecontroleerd. Bij de gedeelde RVA's zijn zowel de twee primaire gegevensreeksen als de twee shadowreeksen exact vergeleken: 6.704 / 2.560 bytes voor nk.exe en 749 / 18.432 bytes voor kernel.dll.

[Aliasverificatie](705md-rom-alias-verification.json) bewaart de adressen, hashes en opslaglocaties. De bekende afwijkingen in `.pdata` van nk.exe/kernel.dll blijven bestaan: bytebehoud maakt zo'n synthetisch PE-bestand niet automatisch semantisch gelijk aan een normale executable.

## Nog open

- Registry-resourceverwijzingen, OEM-persistentie en wijzigingen op de fysieke unit. De framing en rootkeys zijn inmiddels [apart gevalideerd](boot-registry.md).
- Runtimeplaatsing van primaire/shadow-secties en MMU-mapping.
- Functie-/exceptioninterpretatie bij de twee afwijkende kernelmodules.
- Device IOCTLs, registerbetekenissen en uitvoering op echte hardware.

Het eerdere [baseline-rapport](705md-rom-verification.json) bewaart zijn oorspronkelijke beperkte scope. Dit document en de twee nieuwe verificatierapporten vullen de toen nog open decompressie- en aliascontroles aan.
