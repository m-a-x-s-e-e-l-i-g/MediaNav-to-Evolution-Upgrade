"""Retain legacy wrapper fixtures and extend their expectations for new metrics."""
from pathlib import Path
P=Path(__file__).resolve().parent


def main():
    s=(P/'verify_max19.py').read_text()
    start=s.index('def client_cases(');stop=s.index('\n\n\ndef inherited_cases',start)
    s=s[start:stop]
    anchor="                        elif s.name==b'DbgDebugPrint':"
    assert anchor in s
    s=s.replace(anchor,"""                        elif s.ordinal==88:
                            def memory(v):
                                assert v.read(v.reg[4])==32
                                for j,value in enumerate([32,50,0,104857600,0,0,0,0]):v.write(v.reg[4]+j*4,value)
                                return 0
                            m.hooks[target]=memory
                        elif s.ordinal==10:
                            def increment(v):
                                value=(v.read(v.reg[4])+1)&0xffffffff;v.write(v.reg[4],value);return value
                            m.hooks[target]=increment
"""+anchor)
    s=s.replace("[c for c in commands if c[0]==MAGIC+4]", "[c for c in commands if c[0]==MAGIC+4 and c[2] in [event['event'],event['event']|0x80000000]]")
    (P/'verify_clients21.py').write_text('import json\nfrom verify_max20 import VM\nfrom verify_max19 import MAGIC,STACK\nfrom inspect_wave_queue import STOP\n\n'+s,encoding='utf-8')


if __name__=='__main__':main()
