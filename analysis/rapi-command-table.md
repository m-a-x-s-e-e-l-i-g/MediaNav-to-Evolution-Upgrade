# RAPI-commandotabel uit de oorspronkelijke ROM

86 pointers vanaf VA 0x110f8 in rapisrv.exe. Alleen statische analyse.

De API-kolom bevat automatisch uit pseudocode verzamelde directe calls. Dat geeft onderzoekspointers; de complete payloadvoorwaarden en alle helpercalls zijn nog niet per slot beoordeeld. Speciale dispatch voor 45/46/47/48 staat in remote-service-contracts.md.

| Slot | Originele target-VA | Directe API-callkandidaten |
| --- | --- | --- |
| 0x0 | 0x167b0 | FindFirstFileW |
| 0x1 | 0x16910 | FindNextFileW |
| 0x2 | 0x16a38 | FindClose |
| 0x3 | 0x16af8 | GetFileAttributesW |
| 0x4 | 0x16ba0 | SetFileAttributesW |
| 0x5 | 0x16c68 | CreateFileW |
| 0x6 | 0x16df0 | ReadFile |
| 0x7 | 0x16fdc | WriteFile |
| 0x8 | 0x171d0 | CloseHandle |
| 0x9 | 0x1bbe8 | FindClose, FindFirstFileW, FindNextFileW, GetFileAttributesW, SHGetShortcutTarget |
| 0xa | 0x174b4 | CeFindFirstDatabase |
| 0xb | 0x17668 | CeFindNextDatabase |
| 0xc | 0x177c4 | CeOidGetInfo |
| 0xd | 0x17c30 | CeCreateDatabase |
| 0xe | 0x17e2c | CeOpenDatabase |
| 0xf | 0x18144 | CeDeleteDatabase |
| 0x10 | 0x182a0 | CeReadRecordProps |
| 0x11 | 0x188a0 | CeWriteRecordProps |
| 0x12 | 0x18a98 | CeDeleteRecord |
| 0x13 | 0x18b4c | CeSeekDatabase |
| 0x14 | 0x18d44 | CeSetDatabaseInfo |
| 0x15 | 0x136b4 | SetFilePointer |
| 0x16 | 0x13828 | SetEndOfFile |
| 0x17 | 0x138dc | CreateDirectoryW |
| 0x18 | 0x139f0 | RemoveDirectoryW |
| 0x19 | 0x13acc | CreateProcessW |
| 0x1a | 0x13db0 | MoveFileW |
| 0x1b | 0x13ec4 | CopyFileW |
| 0x1c | 0x1b474 | DeleteFileW |
| 0x1d | 0x14000 | GetFileSize |
| 0x1e | 0x193d0 | RegOpenKeyExW |
| 0x1f | 0x14124 | RegEnumKeyExW |
| 0x20 | 0x194ec | RegCreateKeyExW |
| 0x21 | 0x19658 | RegCloseKey |
| 0x22 | 0x14450 | RegDeleteKeyW |
| 0x23 | 0x14554 | RegEnumValueW |
| 0x24 | 0x14878 | RegDeleteValueW |
| 0x25 | 0x1497c | RegQueryInfoKeyW |
| 0x26 | 0x14e2c | RegQueryValueExW |
| 0x27 | 0x1508c | RegSetValueExW |
| 0x28 | 0x15228 | GetSystemMemoryDivision |
| 0x29 | 0x1b924 | GetDiskFreeSpaceExW |
| 0x2a | 0x15478 | GetSystemMetrics |
| 0x2b | 0x1ba28 |  |
| 0x2c | 0x18f64 | CeFindFirstDatabase, CeFindNextDatabase, CeOidGetInfo, CloseHandle |
| 0x2d | 0x15524 | RegCopyFile |
| 0x2e | 0x155f8 | RegRestoreFile |
| 0x2f | 0x156cc | GetSystemInfo |
| 0x30 | 0x157ac | SHCreateShortcut |
| 0x31 | 0x158b8 | SHGetShortcutTarget |
| 0x32 | 0x15a10 | GetPasswordActive |
| 0x33 | 0x15a9c | SetPasswordActive |
| 0x34 | 0x15b98 | CheckPassword |
| 0x35 | 0x15c6c | SetPassword |
| 0x36 | 0x19310 | CeEventHasOccurred |
| 0x37 | 0x19af8 | FileTimeToSystemTime, GetSystemTime, GetTimeZoneInformation, SetDaylightTime, SetSystemTime, SystemTimeToFileTime |
| 0x38 | 0x19cd8 | FindWindowW, SendMessageW |
| 0x39 | 0x15d78 | GetFileTime |
| 0x3a | 0x15f4c | SetFileTime |
| 0x3b | 0x19d54 | GetVersionExW |
| 0x3c | 0x160c0 | GetWindow |
| 0x3d | 0x16190 | GetWindowLongW |
| 0x3e | 0x16260 | GetWindowTextW |
| 0x3f | 0x163a8 | GetClassNameW |
| 0x40 | 0x164f0 | GlobalMemoryStatus |
| 0x41 | 0x1ad08 | GetProcAddressW, LoadLibraryW |
| 0x42 | 0x153cc | SetSystemMemoryDivision |
| 0x43 | 0x165c8 | GetTempPathW |
| 0x44 | 0x1ae40 | GetProcAddressW |
| 0x45 | 0x1a60c | FreeLibrary, GetProcAddressW, LoadLibraryW |
| 0x46 | 0x19ec4 | CeCreateDatabase, CeOpenDatabase, CeWriteRecordProps, CloseHandle |
| 0x47 | 0x1a234 | CeOpenDatabase, CeReadRecordProps |
| 0x48 | 0x1aae4 | CreateFileW, GetFileSize, ReadFile |
| 0x49 | 0x1b0ac | FreeLibrary, GetProcAddressW, LoadLibraryW |
| 0x4a | 0x17574 | CeFindFirstDatabaseEx |
| 0x4b | 0x176fc | CeFindNextDatabaseEx |
| 0x4c | 0x17d50 | CeCreateDatabaseEx |
| 0x4d | 0x18e38 | CeSetDatabaseInfoEx |
| 0x4e | 0x17f9c | CeOpenDatabaseEx |
| 0x4f | 0x181d8 | CeDeleteDatabaseEx |
| 0x50 | 0x1858c | CeReadRecordPropsEx |
| 0x51 | 0x1b52c | CeMountDBVol |
| 0x52 | 0x1b654 | CeUnmountDBVol |
| 0x53 | 0x1b720 | CeFlushDBVol |
| 0x54 | 0x1b7c8 | CeEnumDBVolumes |
| 0x55 | 0x179e0 | CeOidGetInfoEx |

Bronhash en oorspronkelijke bytes: [remote-service-contracts.json](firmware/remote-service-contracts.json). Reproduceer met `py tools/inspect_remote_services.py`.
