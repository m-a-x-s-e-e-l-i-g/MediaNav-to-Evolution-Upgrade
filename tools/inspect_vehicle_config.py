"""Offline, read-only interpretation of MAXConfigProbe output or four-card backup.

Only checks bounded known files. Never modifies a car/backup or prescribes a profile.
"""
import argparse, hashlib, json, re, struct, zlib
from pathlib import Path

def known_file(root,name,backup,limit):
    p=root/name
    if not p.is_file():p=root/backup
    if not p.is_file():return None,dict(present=False)
    size=p.stat().st_size
    info=dict(present=True,bytes=size)
    if size>limit:return None,dict(**info,refused='larger than bounded configuration format')
    b=p.read_bytes();return b,dict(**info,sha256=hashlib.sha256(b).hexdigest())

def inspect(root):
    findings=[];result=dict(format=1,physical_resolution_confirmed=False)
    b,dsi=known_file(root,'DSI_config.bsd','Storage Card/System/DSI_config.bsd',36)
    if b is not None:
        dsi['exact_size']=len(b)==36
        if len(b)==36:
            dsi.update(crc_valid=zlib.crc32(b[:32])==int.from_bytes(b[32:],'little'),
                       header_valid=all(v<bound for v,bound in zip(b[:7],[32,13,100,35,6,6,10])),
                       profile_bits=b[7]>>6)
            dsi['usable_by_native_loader']=dsi['crc_valid']and dsi['header_valid']
    result['dsi']=dsi
    b,eco=known_file(root,'EcoDrive.cfg','Storage Card2/EcoDrive.cfg',9)
    if b is not None:
        eco['exact_size']=len(b)==9
        if len(b)==9:
            checksum=0
            for x in b[:8]:checksum^=x
            eco.update(xor_valid=checksum==b[8],hvac_setting=struct.unpack_from('<I',b)[0],temperature_units_setting=struct.unpack_from('<I',b,4)[0])
    result['eco']=eco
    b,mgr=known_file(root,'MgrSys.cfg','Storage Card2/MgrSys.cfg',128)
    if b is not None:
        mgr['exact_size']=len(b)==128
        if len(b)==128:mgr.update(inverse_preference=struct.unpack_from('<I',b,96)[0],language_setting=struct.unpack_from('<I',b,92)[0],rear_camera_setting=struct.unpack_from('<I',b,100)[0])
    result['mgrsys']=mgr
    snapshots=[];samples=[];statuses=[];complete=False;p=root/'capture.txt'
    if p.is_file()and p.stat().st_size<=65536:
        current=None
        for line in p.read_text(encoding='ascii',errors='replace').splitlines():
            fields={k:int(v)for k,v in re.findall(r'(\w+)=(\d+)',line)}
            if line.startswith('registry '):
                current=dict(**fields,values={});snapshots.append(current)
            elif line.startswith('reg ')and current is not None:
                name=line.split()[1]
                if fields.get('status')==0 and fields.get('type')==4 and fields.get('bytes')==4 and 'value'in fields:
                    current['values'][name]=fields['value']
            elif line.startswith('temp '):
                sample=dict(**fields)
                if 'current_raw'in fields:
                    raw=fields['current_raw'];sample['native_celsius_if_units_1']=raw-40 if raw<255 and fields.get('units')==1 else None
                    sample['native_invalid_sentinel']=raw==255
                else:sample['unavailable']=True
                samples.append(sample)
            elif line.startswith('ram '):statuses.append(line[4:])
            elif line.startswith('capture complete;'):complete=True
    result.update(registry=snapshots,temperature_samples=samples,ram_status=statuses,capture_complete=complete)
    if dsi.get('usable_by_native_loader'):
        profile=dsi['profile_bits']
        findings.append(f'CRC/header-valid saved DSI selects profile {profile}. Profile 0 can be a legitimate vehicle configuration.')
        for snap in snapshots:
            live=snap['values'].get('UI_TYPE')
            if live is not None and live!=profile:
                findings.append(f'Saved profile {profile} differs from registry UI_TYPE {live} at sample {snap.get("sample")}; startup fallback, tool override, or later synchronization requires further evidence.')
    else:findings.append('No native-valid DSI cache captured; failed MCU fallback reads could leave the startup UI buffer zero. This does not establish that those reads failed.')
    for snap in snapshots:
        v=snap['values']
        if v.get('UI_TYPE')==0:findings.append(f'Registry sample {snap.get("sample")}: UI_TYPE 0 selects the M0 resource bank and can omit theme controls.')
        if v.get('HMI_TEMP_CNF')==0:findings.append(f'Registry sample {snap.get("sample")}: HMI_TEMP_CNF is 0; outside-temperature capability is disabled in native startup configuration.')
    if any(x.get('current_raw')==3 for x in samples):findings.append('Observed raw 3 in MICOM state; with Celsius units the native conversion yields -37 C. This is processed state, not proof of the original received packet.')
    if any(x.get('native_invalid_sentinel')for x in samples):findings.append('Observed raw 255 in MICOM state; native conversion uses its invalid-temperature sentinel, displayed as dashes.')
    result['findings']=findings
    result['limits']='A later snapshot cannot prove the values or read failures at an earlier boot. RAM uses explicit MICOM hash/signature/base guards; missing/unsupported RAM is not evidence of a faulty MCU. No profile or temperature correction is prescribed.'
    return result

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--output',type=Path);a=p.parse_args();text=json.dumps(inspect(a.directory),indent=2)+'\n'
    if a.output:a.output.write_text(text,encoding='utf-8')
    else:print(text,end='')
