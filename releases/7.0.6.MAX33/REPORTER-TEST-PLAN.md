## Physical acceptance test

Use stable power and leave the USB connected through both normal install stages.
Do not deliberately remove power, corrupt files or erase markers to provoke recovery
in the daily car. Fault injection belongs on a recoverable bench unit.

1. Check the offered version is MAX33, allow the complete install, then confirm
   Settings > System > System version shows 7.0.6.MAX33.
2. Confirm normal startup, radio/Bluetooth/USB, navigation and saved settings.
3. Enter Windows CE via the normal DBoot route and return to MediaNav; check that
   a healthy session does not create a false unfinished-installation prompt.
4. Check USB logging still starts when enabled and older log sessions remain.
5. On a recoverable bench: interrupt only the application transaction, restart,
   verify automatic progress resume and final byte receipts; separately test the
   explicit Repair action and independent Windows CE action after a copy failure.

The LGU has independent Python verification and separate native-tool extraction.
See installer-resume-evidence for tests, manifests, source pins and generated C
headers. Full-payload tests accelerate hashes; native SHA boundaries and actual
native chunk publication are tested separately. Reused baseline helper evidence
is accepted only with exact instruction-byte comparisons.
