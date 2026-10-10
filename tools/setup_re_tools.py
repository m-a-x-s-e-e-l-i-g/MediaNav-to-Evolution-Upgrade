"""Download pinned official portable RE tools into this workspace; no global installation."""
from pathlib import Path
import hashlib
import json
import urllib.request
import zipfile

ROOT=Path(__file__).resolve().parents[1]
DEST=ROOT/"tools/vendor"


def fetch_json(url):
    request=urllib.request.Request(url,headers={"User-Agent":"MediaNav-local-research"})
    with urllib.request.urlopen(request,timeout=60) as response:return json.load(response)


def download(package):
    target=DEST/package["file"]
    if not target.exists():
        print("Downloading",package["file"],flush=True)
        request=urllib.request.Request(package["url"],headers={"User-Agent":"MediaNav-local-research"})
        with urllib.request.urlopen(request,timeout=60) as response, target.open("wb") as stream:
            while chunk:=response.read(1024*1024):stream.write(chunk)
    actual=hashlib.sha256(target.read_bytes()).hexdigest()
    if actual!=package["sha256"]:raise ValueError("Hash mismatch: "+target.name)
    with zipfile.ZipFile(target) as archive:
        roots={Path(x.filename).parts[0] for x in archive.infolist() if x.filename}
        assert len(roots)==1,roots
        root=DEST/roots.pop()
        root.resolve().relative_to(ROOT)
        for item in archive.infolist():(DEST/item.filename).resolve().relative_to(DEST.resolve())
        marker=root/".medianav-extraction-complete"
        if not marker.exists():
            if root.exists():raise ValueError("Partial/existing extraction must be inspected before retry: "+str(root))
            archive.extractall(DEST)
            marker.write_text(actual,encoding="ascii")
    package["directory"]=str(root.relative_to(ROOT))
    print("Verified/extracted",root.name,flush=True)
    return package


def main():
    DEST.mkdir(parents=True,exist_ok=True)
    ghidra={"file":"ghidra_12.1.4_PUBLIC_20260921.zip", "version":"12.1.4",
            "url":"https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_12.1.4_build/ghidra_12.1.4_PUBLIC_20260921.zip",
            "sha256":"ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db"}
    jdk_data=fetch_json("https://api.adoptium.net/v3/assets/latest/21/hotspot?architecture=x64&image_type=jdk&os=windows&vendor=eclipse")[0]
    binary=jdk_data["binary"]["package"]
    jdk={"file":binary["name"],"version":jdk_data["version"]["semver"],"url":binary["link"],"sha256":binary["checksum"]}
    metadata={"ghidra":download(ghidra),"jdk":download(jdk),"scope":"Portable tools, verified against upstream SHA256, no global PATH or system installation"}
    (ROOT/"analysis/re-toolchain.json").write_text(json.dumps(metadata,indent=2),encoding="utf-8")


if __name__=="__main__":main()
