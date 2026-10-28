"""Check diagnosis/collector source and recorded evidence, not car health."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]

def check():
    folder=ROOT/'analysis/issue66-vehicle-config'
    manifest=json.loads((folder/'source-manifest.json').read_bytes())
    for row in manifest['files']:
        b=(ROOT/row['path']).read_bytes()
        if len(b)!=row['bytes']or hashlib.sha256(b).hexdigest()!=row['sha256']:raise ValueError('Changed vehicle-config source/evidence: '+row['path'])
    native=json.loads((folder/'vehicle-config-paths.json').read_bytes());collector=json.loads((folder/'vehicle-config-probe-verification.json').read_bytes());build=json.loads((folder/'build.json').read_bytes())
    assert native['passed']and native['cases']==14
    assert collector['passed']and collector['cases']==21 and not collector['physical_tested']
    assert collector['exe_sha256']==build['exe_sha256']and not build['physical_tested']
    assert native['micom_sha256']==build['micom_pin']
    assert hashlib.sha256((ROOT/'tools/vehicle_config_probe.c').read_bytes()).hexdigest()==build['source_sha256']
    for name,digest in build['generated_headers'].items():assert hashlib.sha256((folder/name).read_bytes()).hexdigest()==digest
    print(json.dumps(dict(passed=True,pinned_files=len(manifest['files']),native_path_cases=14,collector_cases=21,physical_tested=False),indent=2))

if __name__=='__main__':check()
