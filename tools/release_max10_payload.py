"""Reproduce complete MAX10 from the pinned historical MAX04 LGU."""
import release_payload as payload

payload.PLAN = payload.ROOT / 'src/patches/max10.json'

if __name__ == '__main__':
    payload.main()
