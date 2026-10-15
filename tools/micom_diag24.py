"""Narrow native-call telemetry and two failure-path guards for issues 53/54."""
import struct
from debug_image import Image
from debug_metrics21 import timed_call,patch_call
from debug_clients23 import command


def build(raw,pin):
    i=Image(raw,pin)
    i.replace_imports={(b'coredll.dll',541):('CmnDll.dll','MxOutputDebugStringW'),
                       (b'coredll.dll',545):('CmnDll.dll','MxNKDbgPrintfW')}
    try:dbg=i.import_at('DbgDebugPrint')
    except StopIteration:dbg=i.add_import('CmnDll.dll','DbgDebugPrint')
    i.last=i.import_at(516)
    try:i.setlast=i.import_at(517)
    except StopIteration:i.setlast=i.add_import('COREDLL.dll',517)
    tick=i.import_at(535)
    rows=[]
    for site,target,event,label,mask,guard,metadata in [
        (0x23e0c,0x3f01c,400,'service_tool_entry',0,False,'zero'),
        (0x23c58,0x213f0,401,'service_power_state',0,False,'argument1'),
        (0x41cd0,0x15158,402,'dsi_can_configuration_request',0,False,'zero'),
        (0x42828,0x14db0,403,'rvc_configuration_write',4,False,'setting'),
        (0x42888,0x14db0,404,'gps_fitted_configuration_write',8,False,'setting'),
        (0x3f08c,0x44b7c,405,'service_tool_window_create',0,True,'zero'),
        (0x49ca4,0x44b7c,406,'micom_test_window_create',0,True,'zero'),
    ]:
        assert i.p.get_data(site-i.base,4)==struct.pack('<I',(3<<26)|(target>>2))
        row=timed_call(i,dbg,tick,target,4,event,label)
        r=next(r for r in i.routines if r['address']==row['wrapper']);code=r['assembly']
        value='move a3, zero';result='sw zero, 0x10(sp)'
        if metadata=='argument1':value='move a3, s1'
        if metadata=='setting':
            value='lbu t0, 0(s3)\nlbu t1, 1(s3)\nsll t1, t1, 8\nor a3, t0, t1'
            result='lw t0, 0xc4(s0)\nsw t0, 0x10(sp)'
        # Low-rate human actions: retain a begin even when the subsequent native
        # operation resets the unit. Queue durability still depends on shutdown.
        begin=f'''addiu a1, zero, 4
lui a2, 0x8000
ori a2, a2, {event}
{value}
{result}
{command(i,dbg,4)}'''
        code=code.replace('move s5, v0\noriginal:',f'move s5, v0\n{begin}\noriginal:')
        if mask:
            # The native button already toggled this local bit before sending.
            # On a rejected write, restore just that bit before native redraw.
            rollback=f'''bnez s6, retained
nop
lbu t0, 1(s3)
xori t0, t0, {mask}
sb t0, 1(s3)
retained:
'''
            needle='sw v0, 0x44(sp)\nbeqz s4, finish'
            assert needle in code
            code=code.replace(needle,'sw v0, 0x44(sp)\n'+rollback+'beqz s4, finish')
        if guard:
            original=f'jal {hex(target)}\nnop'
            assert original in code
            code=code.replace(original,f'''bnez s0, allocated
nop
addiu a0, zero, 8
la t8, {hex(i.setlast)}
lw t9, 0(t8)
jalr t9
nop
move v0, zero
move v1, zero
b called
nop
allocated:
{original}
called:''')
        at=row['wrapper'];cap=r['capacity']
        i.routines.remove(r);i.rows=[x for x in i.rows if x[0]!=at]
        i.reloc=[x for x in i.reloc if not at-i.base<=x[0]<at-i.base+cap]
        i.routine_at(at,code,cap,r['frame_bytes'],r['registers'])
        patch_call(i,site,at)
        row.update(site=site,rollback_mask=mask,null_window_guard=guard,begin_metadata=metadata)
        rows.append(row)
    out,recipe=i.finish()
    recipe.update(binary='MicomManager.exe',events=[],settings=None,capture_native_output=True,
                  metrics=None,issue_diagnostics=rows,
                  limits='No MCU protocol, retries, successful writes or power-state policy changed.')
    return out,recipe
