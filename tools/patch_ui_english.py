"""English updater/DBoot development edits; never execute firmware or build an LGU."""
import hashlib
import struct
import pefile

HASHES = {
    "dboot.exe": "a7cddff89aeed7970b332b2fb7f2c579e5fc68ce8c4d03875d7167cddb70546c",
    "dmenu.exe": "351161c5ace16a88dc9737bfdb6b6905e33b0a87c217054366387d28c92f35b3",
    "cereboot.exe": "65785ef321ca4fbc89dce3d31bfb913b83cdf9d10e3458cad7b39a84c397f921",
    "UpgradeManager.exe": "4d6ffa36bc0e42945ba1ebce79de48d82030894e0e1f9c9e05165d3c33735f87",
}
DIAGNOSTICS = [
    ("Impossible de configurer les timeouts\n", "Cannot set serial timeouts\n"),
    ("Impossible de configurer le port série\n", "Cannot configure serial port\n"),
    ("Impossible de se connecter au port COM2\n", "Cannot connect to COM2\n"),
    ("Problème d'écriture sur le port COM ...\n", "Serial port write error ...\n"),
    ("Non connecté ...\n", "Not connected\n"),
    ("Attente de réception d'une réponse en cours ...\n", "Waiting for a response ...\n"),
]
LABELS = {
    "dboot.exe": [("Redemarrer WinCE", "Restart WinCE"), ("Redemarrer", "Restart")],
    "dmenu.exe": [
        ("Souhaitez-vous redémarrer sur Windows CE ?", "Restart into Windows CE?"),
        ("Annuler", "Cancel"),
        ("Patientez svp, redémarrage en cours", "Please wait, restarting"),
        *DIAGNOSTICS,
    ],
    "cereboot.exe": [
        ("Etes-vous sûr de vouloir redémarrer ?", "Are you sure you want to restart?"),
        ("Redémarrer", "Restart"),
        *DIAGNOSTICS,
    ],
    "UpgradeManager.exe": [],
}


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def patch(name, original):
    assert sha(original) == HASHES[name], f"Unexpected preimage: {name}"
    pe = pefile.PE(data=original)
    result = bytearray(original)
    edits = []

    def edit(offset, before, after, role, section):
        assert len(before) == len(after)
        assert result[offset:offset + len(before)] == before, role
        owner = next(s for s in pe.sections
                     if s.PointerToRawData <= offset and
                     offset + len(before) <= s.PointerToRawData + s.SizeOfRawData)
        assert owner.Name.rstrip(b"\0").decode() == section
        assert not any(offset < int(e["offset"], 16) + e["bytes"] and
                       int(e["offset"], 16) < offset + len(before) for e in edits)
        result[offset:offset + len(before)] = after
        edits.append(dict(offset=hex(offset), bytes=len(before), section=section,
                          before_hex=before.hex(), after_hex=after.hex(), role=role))

    for old, new in LABELS[name]:
        before = (old + "\0").encode("utf-16-le")
        after = (new + "\0").encode("utf-16-le")
        assert original.count(before) == 1, old
        assert len(after) <= len(before), "Translation exceeds its existing slot"
        edit(original.index(before), before, after.ljust(len(before), b"\0"),
             f"{old.rstrip()} -> {new.rstrip()}", ".rdata")

    if name == "dmenu.exe":
        at = pe.get_offset_from_rva(0x123c4 - pe.OPTIONAL_HEADER.ImageBase)
        edit(at, struct.pack("<I", 0x24060007), struct.pack("<I", 0x24060006),
             "Cancel DrawTextW length: seven -> six UTF16 units", ".text")
    elif name == "UpgradeManager.exe":
        at = pe.get_offset_from_rva(0x14d74 - pe.OPTIONAL_HEADER.ImageBase)
        edit(at, struct.pack("<I", 0x00808025), struct.pack("<I", 0x24100002),
             "Updater language loader selects English index 2, including LTR state", ".text")

    candidate = bytes(result)
    restored = bytearray(candidate)
    for e in edits:
        at = int(e["offset"], 16)
        restored[at:at + e["bytes"]] = bytes.fromhex(e["before_hex"])
    assert bytes(restored) == original, "Change outside reviewed edit ranges"
    assert len(candidate) == len(original)
    # Structural data, resources, imports, entry point and unwind table do not move.
    checked = pefile.PE(data=candidate)
    assert checked.FILE_HEADER.Machine == pe.FILE_HEADER.Machine
    assert checked.OPTIONAL_HEADER.AddressOfEntryPoint == pe.OPTIONAL_HEADER.AddressOfEntryPoint
    assert candidate[:pe.sections[0].PointerToRawData] == original[:pe.sections[0].PointerToRawData]
    for section in pe.sections:
        if section.Name.rstrip(b"\0") not in (b".text", b".rdata"):
            assert section.get_data() == next(s for s in checked.sections if s.Name == section.Name).get_data()
    return candidate, dict(name=name, source_sha256=sha(original), sha256=sha(candidate),
                           bytes=len(candidate), edits=edits)
