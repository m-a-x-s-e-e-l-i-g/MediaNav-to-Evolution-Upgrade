"""Retain prior schemas; identify the nested Bluetooth/fade waits explicitly."""
import argparse,json
from pathlib import Path
import analyze_debug_logs21 as previous

previous.NAMES.update({133:'Bluetooth navigation/audio wait',134:'Bluetooth play settle wait',
                       135:'Media fade settle wait',136:'Media fade IPC'})


def analyze(paths):return previous.analyze(paths)


def main():
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--output',type=Path);a=p.parse_args()
    text=json.dumps(analyze(sorted(a.directory.glob('debug-*.log'))),indent=2,ensure_ascii=False)
    if a.output:a.output.write_text(text+'\n',encoding='utf-8')
    else:print(text)


if __name__=='__main__':main()
