# MediaNav MAXmade 7.0.6.MAX04 — complete gecombineerde build

Documentation update: short English release/general READMEs, eight before/after UI previews and a new-design gallery are included in [PR #23](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/pull/23). The ZIP was refreshed with the screenshots; the LGU and integration proof are unchanged. The earlier no-GitHub status below describes the original build step; MAX04 is now on the PR branch, with main/MAX03 retained.

10 oktober 2026. Max heeft de Home/Radio/Media/Telefoon-skin goedgekeurd en gevraagd deze samen met alle opgebouwde bugfixes in de nieuwe build op te nemen. De volledige lokale build is afgerond; er is niets geïnstalleerd of gepubliceerd op GitHub.

## Bestanden

- [Volledige ZIP](../build/maxmade-7.0.6.MAX04.zip): LGU, changelog, SHA256SUMS en drie bewijsmanifesten.
- [Volledige LGU](../build/maxmade-7.0.6.MAX04/upgrade.lgu): 37,229,267 bytes.
- [Release-uitleg en beperkingen](../build/maxmade-7.0.6.MAX04/README.md).
- [Buildmanifest](../build/maxmade-7.0.6.MAX04/build-manifest.json), [stagingmanifest](../build/maxmade-7.0.6.MAX04/staging-manifest.json) en [integratiebewijs](../build/maxmade-7.0.6.MAX04/integration-proof.json).

LGU SHA256: `94bb17ac6df670eb17927a7be627620a2a04cd2d64e92c042fb49c650a6187b0`.

## Volledige overname

Basis is de complete MAX03-release met 1.918 bestanden. De nieuwe build heeft exact dezelfde 1.918 paden: geen ontbrekende of extra members. 279 bestanden zijn gewijzigd; 1.639 blijven byte-identiek aan MAX03. De oorspronkelijke OS/boot/MCU-payload en meegeleverde instellingen blijven opgenomen, evenals de bestaande navigatie-corruptiefix. Navigatie heeft geen nieuwe skin of patch.

De functionele basis is `bt-startup-audio-development-02`. De volledige, via SHA256 gekoppelde geschiedenis van 17 ontwikkelstappen is gecontroleerd, inclusief actuele memberhashes, gewijzigde vorige members, toolpins en bewijsfiles. De ongewijzigde Blue- en MgrUSB-bestanden behouden hun bestaande bewijs via exacte hashes; de eerder uitgesloten brede Bluetooth/controlleronderzoeken zijn niet hervat.

De skin komt uit de goedgekeurde `av-theme-development-09`: 271 native M1-BMPs zijn met hun oorspronkelijke formaat, dimensies, kleurkey/transparantie en padding gecontroleerd en overgenomen. De oude skin-AppMain is niet over de nieuwste bugfix-AppMain gekopieerd. Alleen 138 goedgekeurde kleurinstructies zijn toegevoegd, met 280 gewijzigde codebytes.

## Laadadrescorrectie bij integratie

Vijf AV-initializers herschikken bestaande adresinstructies om witte actieve labels te tekenen. De oude skin had hiervoor nog verwijzingen op de oude instructieposities. In MAX04 bewegen 30 relocatierecords mee met exact dezelfde oorspronkelijke instructies; HIGHADJ-companions blijven gelijk. Van de 72.988 actieve relocatierecords blijven de overige ongewijzigd. Directorylengte, headers, sectionindeling, imports, exceptionmetadata en branch/call-opcodes behouden hun bestaande bytes.

De kleurcode plus relocatiemetadata verandert in totaal 311 bytes in AppMain. Het terugdraaien van beide expliciete edits herstelt exact de volledige nieuwste bugfix-AppMain. Voor vier alternatieve laadadressen (`+0x1000`, `+0x10000`, `+0x123000`, `+0x500000`) is het volledig gerealloceerde image byte voor byte vergeleken met dezelfde instructieherschikking op de gerealloceerde basis. Dit is een architecturale offline controle, geen native CE-loaderuitvoering.

## Gecontroleerd op de gecombineerde bestanden

| Controle | Geslaagde cases |
| --- | ---: |
| Home-layoutvarianten | 24 |
| Radio/Media/Telefoon-initializers, beide UI-profielen | 106 |
| Native bronmenu-afbeeldingen, vier standen per menu | 8 |
| Repeat/shuffle-statusmomentopname | 1410 |
| USB-titel/artist/albumhoesconsumenten | 375 |
| Oorspronkelijke albumhoes-callers | 32 |
| Touch-release/seek-gedrag | 117 |

Home/AV behouden posities, events, fonts, labels en flags. Registers en fixturegeheugen blijven gelijk behalve de bedoelde kleurslots. De vier alternate-loadcontroles en exacte editreversal bewijzen dat het combineren geen overige cumulatieve codebytes vervangt. De functionele tests zijn MIPS-byte-interpreterfixtures met gemodelleerde CE/GDI/threadfuncties; hardwaretiming en native werking worden hiermee niet bewezen.

De LGU is onafhankelijk gedecodeerd: header, versie, XOR/CRC, encrypted ZIP-headers en alle 1.918 gedecomprimeerde membergroottes/CRCs/SHA256-hashes kloppen. Daarnaast komt de uitkomst van de gepinde PC-extractor overeen met alle 1.918 stagingbestanden. De buitenste ZIP is op integriteit en exacte inhoud gecontroleerd. Header en meegeleverde Version.bin zijn beide `7.0.6.MAX04`.

## Modulehashes

| Bestand | Bytes | SHA256 |
| --- | ---: | --- |
| AppMain.exe | 2010112 | `b34676225ad428426b417cec33c30f7e18e56aeeb6e438900c01dc022225fcd9` |
| Blue.exe | 1149952 | `2b1eb3adee76a7867d1fd9d0a6c376f41d2b7a42cf4b54834e9ebc153854ed51` |
| MgrUSB.exe | 249344 | `cac3d40f5d54de681b1aad8c99fe79df5b430d3ee3d668616b63970f02ca1a2c` |
| UpgradeManager.exe | 197120 | `22ebd96233a121935ac985ae7b667ed8a2f11cc8a47757c3d3ea25753fb06e73` |
| cereboot.exe | 113664 | `177fc797eb116f72257edc25445276fa90ead6668d76981ff260d94079e9f7a6` |
| dboot.exe | 40960 | `0b32b9d203facc43f4e8f47a3f9362cd814fc0c297ec6fe42869355e0dd654b3` |
| dmenu.exe | 115712 | `e7357a7929cff25690453bb6a542d30a65512ab18a6e2cd850a090fd996ad6be` |
| nngnavi.exe | 10364952 | `d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9` |

## Grenzen

Experimentele volledige build voor de eerste generatie MediaNav onder de bestaande 7.0.5.MD-conversie; niet voor fabrieks-Evolution. Geen fysieke installatie, loader/GDI/audio/scheduler/stackheadroom- of stroomverlieshersteltest uitgevoerd. De goedgekeurde skin is M1; gedeelde tekstkleuren vragen nog contrastcontrole bij andere profielen. De browserpreview is een native-asset/layoutweergave en geen volledige firmware-emulator.

De eerder afgesproken voorkeur voor reversibele CE-applicatietests blijft gelden. De volledige LGU bevat ook OS/boot/MCU en oorspronkelijke instellingen. De bestaande publieke MAX03-release en eerdere artifacts zijn behouden. Het bouwen maakt de herstelroute of installatie op de unit niet automatisch bewezen.
