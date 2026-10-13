"""Generate a MAX20-based client builder; earlier authoring modules stay fixed."""
from pathlib import Path
P=Path(__file__).resolve().parent


def change(s,a,b):
    assert a in s,a[:80]
    return s.replace(a,b)


def main():
    s=(P/'debug_clients20.py').read_text()
    s=change(s,'from debug_runtime20 import MAGIC',
        'from debug_runtime20 import MAGIC\nfrom debug_metrics21 import app_metrics,poll_wrapper,sample_call')
    s=change(s,'{begin}\noriginal:', '{begin}\n{sample_call(i,dbg,902) if event==310 else ""}\noriginal:')
    s=change(s,'finish:\n{after}', 'finish:\n{sample_call(i,dbg,903) if event==310 else ""}\n{after}')
    # Imports fit the confirmed-zero existing AppMain state; no extra PE section.
    s=change(s,"    hooks=[]\n    for entry", """    if name=='AppMain.exe':
        i.apis={'memory':i.add_import('COREDLL.dll',88,0x214c68),
                'increment':i.add_import('COREDLL.dll',10,0x214c6c)}
    hooks=[]
    for entry""")
    s=change(s,'        hooks.append(instrument(i,dbg,tick,entry,module,event,label))',
        "        hooks.append((poll_wrapper if name=='Blue.exe' and event==301 else instrument)(i,dbg,tick,entry,module,event,label))")
    s=change(s,"    out,recipe=i.finish()", "    metrics=app_metrics(i,dbg,tick,hooks) if name=='AppMain.exe' else None\n    out,recipe=i.finish()")
    s=change(s,'recipe.update(binary=name,events=hooks,settings=ui,capture_native_output=True)',
        'recipe.update(binary=name,events=hooks,settings=ui,capture_native_output=True,metrics=metrics)')
    (P/'debug_clients21.py').write_text(s,encoding='utf-8')


if __name__=='__main__':main()
