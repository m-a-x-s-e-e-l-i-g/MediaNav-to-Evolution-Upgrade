"""Low-volume worker handoff / GUI acceptance evidence and honest fallback text."""
from debug_clients23 import build_client,instrument


def extend(i,dbg,tick,hooks):
    at=0x341c00+11*64
    old=('Cover decoded (D9)'+'\0').encode('utf-16-le').ljust(64,b'\0')
    assert i.p.get_data(at-i.base,64)==old
    i.edit(at,('Waiting for current cover'+'\0').encode('utf-16-le').ljust(64,b'\0'),
           'A historical decoder attempt does not certify a current GUI bitmap')
    begin,end=i.text+0xd400,i.text+0x10000
    assert not any(i.body[begin-i.text:end-i.text])
    assert not any(a<end and b>begin for a,b,*_ in i.rows)
    i.code_cursor=0xd400
    rows=[]
    for entry,event,label in [(0x231000,350,'artwork_worker_handoff'),(0x233000,351,'artwork_GUI_change')]:
        row=instrument(i,dbg,tick,entry,1,event,label,emit_begin=False)
        routine=i.routines[-1];assert routine['address']==row['wrapper']
        source=routine['assembly'].replace('subu a3, v0, s5','beqz s6, finish\nnop\nsubu a3, v0, s5',1)
        if event==351:
            source=source.replace('sw s6, 0x10(sp)', '''la t0, 0x300020
lw t1, 20(t0)
sltu t1, zero, t1
lw t2, 16(t0)
sltu t2, zero, t2
sll t2, t2, 1
or t1, t1, t2
lw t2, 12(t0)
andi t2, t2, 1
sll t2, t2, 2
or t1, t1, t2
sw t1, 0x10(sp)''',1)
        else:source=source.replace('sw s6, 0x10(sp)','sltu t0, zero, s6\nsw t0, 0x10(sp)',1)
        i.rows=[r for r in i.rows if r[0]!=row['wrapper']]
        i.routines=[r for r in i.routines if r['address']!=row['wrapper']]
        i.reloc=[r for r in i.reloc if not row['wrapper']-i.base<=r[0]<row['wrapper']-i.base+0x800]
        i.routine_at(row['wrapper'],source,0x800,0x80,routine['registers'])
        row['successful_changes_only']=True;hooks.append(row);rows.append(row)
    assert i.code_cursor<=0x10000
    return dict(events=rows,caption_address=at,
        scope='Worker handoff is not GUI acceptance; GUI bitmap ownership is not proof of visible pixels. No pointer or metadata logging.')


def build(raw,pin):return build_client(raw,pin,'AppMain.exe',extend)
