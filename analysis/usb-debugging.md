# MAX19 USB debugging implementation

Local full-successor test candidate from the owner-tested MAX18 payload.

Seven binaries and Version_Info change; all 1,919 payload paths remain.
The native Settings page gains a Debugging toggle and writer status.
The shared queue, suspended priority-confirmed worker, USB rotation, error
handling and event/ABI fixtures are described in the release README.

The source/writer outputs are workspace-specific development artifacts.
Native loader, touch, USB timing, registry persistence and long-session
performance remain to be verified in the car. No public release is authorized
until owner feedback. Kernel, MCU, bootloader, navigation resources and all
other payload members remain byte-exact MAX18.

The recipe addresses an inline jump table in the cloned source-switch
routine; 47 actual-instruction table cases cover its relocated destination.
All callbacks preserve original arguments, v0/v1 and GetLastError.

Build in the established development workspace:

    python tools/build_max19.py --output build/max19-debugging-development-NEW
    python tools/verify_max19.py --build build/max19-debugging-development-NEW
    python tools/package_max19.py --stage build/max19-debugging-development-NEW

The build requires the complete pinned MAX18 stage and its member manifest.
The package uses the pinned PC LGU tools and independent decoder. All source
inputs and every member output are retained in the local full delivery.
