/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00013144 FUN_00013144 */

/* Boundary evidence: original MIPS .pdata 00013144..000131d7. Semantic name remains unreviewed. */

void FUN_00013144(HINSTANCE param_1,int param_2,wchar_t *param_3)

{
  UINT UVar1;
  
  FUN_00013454();
  UVar1 = FUN_00013ff0(param_1,param_2,param_3);
  FUN_00013394(UVar1);
  FUN_000133b4(UVar1);
  return;
}



/* 000131d8 FUN_000131d8 */

/* Boundary evidence: original MIPS .pdata 000131d8..00013217. Semantic name remains unreviewed. */

void FUN_000131d8(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00013218 entry */

/* Boundary evidence: original MIPS .pdata 00013218..00013273. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,int param_2,wchar_t *param_3)

{
  FUN_00013490();
  FUN_00013144(param_1,param_2,param_3);
  return;
}



/* 00013274 FUN_00013274 */

/* Boundary evidence: original MIPS .pdata 00013274..00013393. Semantic name remains unreviewed. */

void FUN_00013274(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00035550 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000356ac;
    if (DAT_000356ac != (undefined4 *)0x0) {
      while (DAT_000356a8 = DAT_000356a8 + -1, _Memory <= DAT_000356a8) {
        if ((code *)*DAT_000356a8 != (code *)0x0) {
          (*(code *)*DAT_000356a8)();
          _Memory = DAT_000356ac;
        }
      }
      free(_Memory);
      DAT_000356a8 = (undefined4 *)0x0;
      DAT_000356ac = (undefined4 *)0x0;
    }
    FUN_00013400((undefined4 *)&DAT_00011014,(undefined4 *)&DAT_00011018);
  }
  FUN_00013400((undefined4 *)&DAT_0001101c,(undefined4 *)&DAT_00011020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_000356b0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00013394 FUN_00013394 */

/* Boundary evidence: original MIPS .pdata 00013394..000133b3. Semantic name remains unreviewed. */

void FUN_00013394(UINT param_1)

{
  FUN_00013274(param_1,0,0);
  return;
}



/* 000133b4 FUN_000133b4 */

/* Boundary evidence: original MIPS .pdata 000133b4..000133ff. Semantic name remains unreviewed. */

void FUN_000133b4(UINT param_1)

{
  DAT_00035550 = 0;
  FUN_00013400((undefined4 *)&DAT_0001101c,(undefined4 *)&DAT_00011020);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00013400 FUN_00013400 */

/* Boundary evidence: original MIPS .pdata 00013400..00013453. Semantic name remains unreviewed. */

void FUN_00013400(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00013454 FUN_00013454 */

/* Boundary evidence: original MIPS .pdata 00013454..0001348f. Semantic name remains unreviewed. */

void FUN_00013454(void)

{
  FUN_00013400((undefined4 *)&DAT_0001100c,(undefined4 *)&DAT_00011010);
  FUN_00013400((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011008);
  return;
}



/* 00013490 FUN_00013490 */

/* Boundary evidence: original MIPS .pdata 00013490..00013503. Semantic name remains unreviewed. */

void FUN_00013490(void)

{
  uint uVar1;
  
  if ((DAT_00035518 == 0) || (DAT_00035518 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00035518 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00035518 == 0) {
      DAT_00035518 = 0xb064;
    }
  }
  DAT_0003551c = ~DAT_00035518;
  return;
}



/* 000135a4 FUN_000135a4 */

/* Boundary evidence: original MIPS .pdata 000135a4..00013ae3. Semantic name remains unreviewed. */

undefined4 FUN_000135a4(void)

{
  int iVar1;
  HANDLE pvVar2;
  HRESULT HVar3;
  BOOL BVar4;
  uint uVar5;
  HLOCAL hMem;
  wchar_t *pwVar6;
  STRSAFE_LPCWSTR pwVar7;
  int iVar8;
  wchar_t **ppwVar9;
  int *piVar10;
  uint nCount;
  HANDLE *ppvVar11;
  wchar_t *pwVar12;
  STRSAFE_LPCWSTR local_490;
  STRSAFE_LPWSTR local_48c;
  uint local_488;
  wchar_t *local_484 [3];
  HANDLE local_478 [4];
  _WIN32_FIND_DATAW local_468;
  uint local_30;
  
  local_30 = DAT_00035518;
  local_484[1] = (wchar_t *)0x14;
  local_484[2] = (wchar_t *)0x24;
  local_48c = (wchar_t *)0x0;
  local_468.dwFileAttributes = 0;
  memset(&local_468.ftCreationTime,0,0x22c);
  nCount = 1;
  local_478[0] = DAT_0003555c;
  iVar8 = 2;
  pwVar6 = L"\\*.*";
  ppvVar11 = local_478 + 1;
  ppwVar9 = local_484;
  local_488 = 1;
  local_484[0] = L".ttc";
  local_490 = L"\\*.*";
  do {
    ppwVar9 = ppwVar9 + 1;
    iVar1 = SHGetSpecialFolderPath(0,local_468.cFileName + 0x102,*ppwVar9,1);
    if (iVar1 != 0) {
      pvVar2 = FindFirstChangeNotificationW(local_468.cFileName + 0x102,0,0x80000009);
      *ppvVar11 = pvVar2;
      if (pvVar2 != (HANDLE)0xffffffff) {
        nCount = nCount + 1;
        ppvVar11 = ppvVar11 + 1;
        local_488 = nCount;
      }
      HVar3 = StringCchCatExW(local_468.cFileName + 0x102,0x104,pwVar6,&local_48c,(size_t *)0x0,0);
      if (-1 < HVar3) {
        local_48c = local_48c + -3;
        pvVar2 = FindFirstFileW(local_468.cFileName + 0x102,&local_468);
        pwVar6 = local_490;
        if (pvVar2 != (HANDLE)0xffffffff) {
          do {
            iVar1 = PathIsExtension(&local_468.dwReserved1,L".ttf");
            if ((((iVar1 != 0) ||
                 (iVar1 = PathIsExtension(&local_468.dwReserved1,L".ttc"), iVar1 != 0)) ||
                (iVar1 = PathIsExtension(&local_468.dwReserved1,L".fon"), iVar1 != 0)) ||
               (iVar1 = PathIsExtension(&local_468.dwReserved1,L".fnt"), iVar1 != 0)) {
              wcscpy(local_48c,(wchar_t *)&local_468.dwReserved1);
              iVar1 = AddFontResourceW(local_468.cFileName + 0x102);
              if (iVar1 != 0) {
                PostMessageW((HWND)0xffff,0x1d,0,0);
              }
            }
            BVar4 = FindNextFileW(pvVar2,&local_468);
          } while (BVar4 != 0);
          FindClose(pvVar2);
          pwVar6 = local_490;
          nCount = local_488;
        }
      }
    }
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (1 < nCount) {
    uVar5 = WaitForMultipleObjects(nCount,local_478,0,0xffffffff);
    while ((uVar5 != 0 && (uVar5 < nCount))) {
      local_490 = (STRSAFE_LPCWSTR)0x0;
      iVar8 = CeGetFileNotificationInfo(local_478[uVar5],0,0,0,0,&local_490);
      if ((iVar8 != 0) && (hMem = LocalAlloc(0,(SIZE_T)local_490), hMem != (HLOCAL)0x0)) {
        iVar8 = CeGetFileNotificationInfo(local_478[uVar5],0,hMem,local_490,0,0);
        pwVar6 = local_484[0];
        if (iVar8 == 0) {
          LocalFree(hMem);
        }
        else {
          pwVar12 = local_484[uVar5];
          iVar8 = 0;
          do {
            piVar10 = (int *)(iVar8 + (int)hMem);
            iVar1 = piVar10[1];
            if ((iVar1 == 2) || (iVar1 == 4)) {
              pwVar7 = (STRSAFE_LPCWSTR)(piVar10 + 3);
              iVar1 = PathIsExtension(pwVar7,L".ttf");
              if (((iVar1 != 0) ||
                  (((iVar1 = PathIsExtension(pwVar7,pwVar6), iVar1 != 0 ||
                    (iVar1 = PathIsExtension(pwVar7,L".fon"), iVar1 != 0)) ||
                   (iVar1 = PathIsExtension(pwVar7,L".fnt"), iVar1 != 0)))) &&
                 (((iVar1 = SHGetSpecialFolderPath(0,local_468.cFileName + 0x102,pwVar12,0),
                   iVar1 != 0 &&
                   (HVar3 = StringCchCatW(local_468.cFileName + 0x102,0x104,L"\\"), HVar3 == 0)) &&
                  (HVar3 = StringCchCatW(local_468.cFileName + 0x102,0x104,pwVar7), HVar3 == 0)))) {
                iVar1 = RemoveFontResourceW(local_468.cFileName + 0x102);
LAB_00013a4c:
                if (iVar1 != 0) {
                  PostMessageW((HWND)0xffff,0x1d,0,0);
                }
              }
            }
            else if ((iVar1 == 5) || (iVar1 == 0x10000)) {
              pwVar7 = (STRSAFE_LPCWSTR)(piVar10 + 3);
              iVar1 = PathIsExtension(pwVar7,L".ttf");
              if ((((iVar1 != 0) ||
                   (((iVar1 = PathIsExtension(pwVar7,pwVar6), iVar1 != 0 ||
                     (iVar1 = PathIsExtension(pwVar7,L".fon"), iVar1 != 0)) ||
                    (iVar1 = PathIsExtension(pwVar7,L".fnt"), iVar1 != 0)))) &&
                  ((iVar1 = SHGetSpecialFolderPath(0,local_468.cFileName + 0x102,pwVar12,0),
                   iVar1 != 0 &&
                   (HVar3 = StringCchCatW(local_468.cFileName + 0x102,0x104,L"\\"), HVar3 == 0))))
                 && (HVar3 = StringCchCatW(local_468.cFileName + 0x102,0x104,pwVar7), HVar3 == 0)) {
                iVar1 = AddFontResourceW(local_468.cFileName + 0x102);
                goto LAB_00013a4c;
              }
            }
            iVar8 = *piVar10 + iVar8;
          } while (*piVar10 != 0);
          LocalFree(hMem);
          nCount = local_488;
        }
      }
      uVar5 = WaitForMultipleObjects(nCount,local_478,0,0xffffffff);
    }
  }
  FUN_00033770(local_30);
  return 0;
}



/* 00013ae4 FUN_00013ae4 */

/* Boundary evidence: original MIPS .pdata 00013ae4..00013c63. Semantic name remains unreviewed. */

void FUN_00013ae4(void)

{
  int iVar1;
  HRESULT HVar2;
  HANDLE hFindFile;
  BOOL BVar3;
  STRSAFE_LPWSTR local_4a0 [2];
  undefined4 local_498;
  undefined1 auStack_494 [12];
  WCHAR *local_488;
  undefined4 local_47c;
  _WIN32_FIND_DATAW local_458;
  uint local_20;
  
  local_20 = DAT_00035518;
  local_458.dwFileAttributes = 0;
  memset(&local_458.ftCreationTime,0,0x22c);
  local_4a0[0] = (wchar_t *)0x0;
  iVar1 = SHGetSpecialFolderPath(0,local_458.cFileName + 0x102,7,0);
  if (iVar1 != 0) {
    HVar2 = StringCchCatExW(local_458.cFileName + 0x102,0x104,L"\\*.*",local_4a0,(size_t *)0x0,0);
    if ((-1 < HVar2) &&
       (hFindFile = FindFirstFileW(local_458.cFileName + 0x102,&local_458),
       hFindFile != (HANDLE)0xffffffff)) {
      memset(auStack_494,0,0x38);
      local_488 = local_458.cFileName + 0x102;
      local_47c = 1;
      local_4a0[0] = local_4a0[0] + -3;
      local_498 = 0x3c;
      do {
        if (((local_458.dwFileAttributes & 0x10) == 0) &&
           (iVar1 = _wcsicmp(L"desktop.ini",(wchar_t *)&local_458.dwReserved1), iVar1 != 0)) {
          wcscpy(local_4a0[0],(wchar_t *)&local_458.dwReserved1);
          ShellExecuteEx(&local_498);
        }
        BVar3 = FindNextFileW(hFindFile,&local_458);
      } while (BVar3 != 0);
      FindClose(hFindFile);
    }
  }
  FUN_00033770(local_20);
  return;
}



/* 00013c64 FUN_00013c64 */

/* Boundary evidence: original MIPS .pdata 00013c64..00013e4b. Semantic name remains unreviewed. */

void FUN_00013c64(void)

{
  int iVar1;
  HRESULT HVar2;
  wchar_t *pszSrc;
  int iVar3;
  int iVar4;
  wchar_t *local_488 [5];
  wchar_t *local_474;
  wchar_t *local_470;
  wchar_t *local_46c;
  wchar_t *local_468;
  undefined4 local_464;
  undefined4 local_460 [10];
  wchar_t awStack_438 [260];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_00035518;
  pszSrc = L"appdata.ini";
  local_488[1] = L"desktopdirectory.ini";
  local_488[2] = L"favorites.ini";
  local_488[4] = L"mydocuments.ini";
  local_474 = L"programfiles.ini";
  local_488[3] = L"fonts.ini";
  local_46c = L"recent.ini";
  local_468 = L"startup.ini";
  local_470 = L"programs.ini";
  local_460[1] = 0x10;
  local_460[3] = 0x14;
  local_460[0] = 0x1a;
  local_460[2] = 6;
  local_460[6] = 2;
  local_460[8] = 7;
  iVar4 = 0;
  iVar3 = 0;
  local_488[0] = L"appdata.ini";
  local_464 = 0;
  local_460[4] = 5;
  local_460[5] = 0x26;
  local_460[7] = 8;
  local_460[9] = 0;
  do {
    iVar1 = SHGetSpecialFolderPath(0,awStack_438,0x24,1);
    if ((((iVar1 != 0) &&
         (iVar3 = SHGetSpecialFolderPath(0,awStack_230,*(undefined4 *)((int)local_460 + iVar3),1),
         iVar3 != 0)) && (HVar2 = StringCbCatW(awStack_438,0x208,L"\\"), -1 < HVar2)) &&
       ((HVar2 = StringCbCatW(awStack_438,0x208,pszSrc), -1 < HVar2 &&
        (HVar2 = StringCbCatW(awStack_230,0x208,L"\\desktop.ini"), -1 < HVar2)))) {
      CopyFileW(awStack_438,awStack_230,1);
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar4 * 4;
    pszSrc = local_488[iVar4];
  } while (pszSrc != (STRSAFE_LPCWSTR)0x0);
  FUN_00033770(local_28);
  return;
}



/* 00013e4c FUN_00013e4c */

/* Boundary evidence: original MIPS .pdata 00013e4c..00013e9f. Semantic name remains unreviewed. */

void FUN_00013e4c(void)

{
  HANDLE hObject;
  
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000135a4,(LPVOID)0x0,0,(LPDWORD)0x0);
  if (hObject != (HANDLE)0x0) {
    CloseHandle(hObject);
  }
  FUN_00013ae4();
  return;
}



/* 00013ea0 FUN_00013ea0 */

/* Boundary evidence: original MIPS .pdata 00013ea0..00013f0b. Semantic name remains unreviewed. */

void FUN_00013ea0(void)

{
  HANDLE hHandle;
  
  hHandle = OpenEventW(0x1f0003,0,L"SYSTEM/DCOMApiSetReady");
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
    CloseHandle(hHandle);
  }
  return;
}



/* 00013f0c FUN_00013f0c */

/* Boundary evidence: original MIPS .pdata 00013f0c..00013fef. Semantic name remains unreviewed. */

WPARAM FUN_00013f0c(undefined4 *param_1)

{
  HLOCAL pvVar1;
  int *hMem;
  int iVar2;
  WPARAM WVar3;
  undefined4 uVar4;
  
  uVar4 = *param_1;
  pvVar1 = LocalAlloc(0x40,0xcc);
  if (pvVar1 == (HLOCAL)0x0) {
    hMem = (int *)0x0;
  }
  else {
    hMem = (int *)FUN_00021790((int)pvVar1);
  }
  if (hMem != (int *)0x0) {
    DAT_0003556c = hMem;
    iVar2 = FUN_0002ac98(hMem,DAT_00035560);
    if (iVar2 != 0) {
      RegisterTaskBar(hMem[2]);
      EventModify(uVar4,3);
      WVar3 = FUN_00021a7c((int)hMem);
      FUN_00026ef8(hMem);
      LocalFree(hMem);
      return WVar3;
    }
    DAT_0003556c = (int *)0x0;
    FUN_00026ef8(hMem);
    LocalFree(hMem);
  }
  EventModify(uVar4,3);
  return 0;
}



/* 00013ff0 FUN_00013ff0 */

/* Boundary evidence: original MIPS .pdata 00013ff0..0001472f. Semantic name remains unreviewed. */

undefined4 FUN_00013ff0(HINSTANCE param_1,int param_2,wchar_t *param_3)

{
  bool bVar1;
  bool bVar2;
  SHORT SVar3;
  LSTATUS LVar4;
  undefined3 extraout_var;
  HWND pHVar5;
  HRESULT HVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined3 extraout_var_00;
  HANDLE pvVar10;
  long lVar11;
  undefined2 extraout_var_01;
  BOOL BVar12;
  DWORD DVar13;
  wchar_t *_Dest;
  uint uVar14;
  STRSAFE_LPWSTR hMem;
  HKEY local_70;
  HANDLE local_6c;
  DWORD local_68;
  int local_64;
  int local_60;
  DWORD local_5c;
  uint local_58 [2];
  INITCOMMONCONTROLSEX local_50;
  MSG MStack_48;
  
  bVar1 = false;
  local_68 = 4;
  local_6c = (HANDLE)0x0;
  DAT_00035560 = param_1;
  LVar4 = RegOpenKeyExW((HKEY)0x80000001,L"SOFTWARE\\Microsoft\\Internet Explorer\\Main",0,0,
                        &local_70);
  if (LVar4 == 0) {
    RegQueryValueExW(local_70,L"StackRes",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&DAT_00035520,&local_68)
    ;
    RegCloseKey(local_70);
  }
  if ((DAT_00035520 < 0x10000) || (0x80000 < DAT_00035520)) {
    DAT_00035520 = 0x20000;
  }
  bVar2 = FUN_00015834();
  DAT_00035524 = CONCAT31(extraout_var,bVar2);
  local_60 = 0;
  LVar4 = RegOpenKeyExW((HKEY)0x80000002,L"Explorer",0,0,&local_70);
  if (LVar4 == 0) {
    local_68 = 4;
    RegQueryValueExW(local_70,L"QVGA",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_60,&local_68);
    RegCloseKey(local_70);
  }
  DAT_00035568 = (uint)(local_60 != 0);
  DAT_00035558 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (DAT_00035558 != (HANDLE)0x0) {
    if ((param_2 == 0) &&
       (pHVar5 = FindWindowW(L"DesktopExplorerWindow",(LPCWSTR)0x0), pHVar5 == (HWND)0x0)) {
      FUN_00014908();
      FUN_00013ea0();
      HVar6 = CoInitializeEx((LPVOID)0x0,0);
      if ((-1 < HVar6) &&
         (DAT_0003555c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0),
         DAT_0003555c != (HANDLE)0x0)) {
        local_50.dwSize = 8;
        local_50.dwICC = 0x400;
        InitCommonControlsEx(&local_50);
        FUN_0001e55c();
        iVar7 = FUN_0001e5bc();
        if (iVar7 != 0) {
          FUN_0001e7e0();
        }
        DAT_00035564 = LoadLibraryW(L"coredll");
        FUN_00016160(DAT_00035560);
        FUN_00015b18();
        FUN_00013c64();
        puVar8 = LocalAlloc(0x40,0x10);
        if (puVar8 == (undefined4 *)0x0) {
          piVar9 = (int *)0x0;
        }
        else {
          piVar9 = FUN_000168a8(puVar8);
        }
        if (piVar9 != (int *)0x0) {
          bVar2 = FUN_000166f0(piVar9);
          if ((CONCAT31(extraout_var_00,bVar2) != 0) &&
             (DAT_00035570 = piVar9,
             local_6c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0),
             local_6c != (HANDLE)0x0)) {
            pvVar10 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00013f0c,&local_6c,0,
                                   (LPDWORD)0x0);
            WaitForSingleObject(local_6c,0xffffffff);
            CloseHandle(pvVar10);
            CloseHandle(local_6c);
            SendMessageW((HWND)piVar9[1],0x1a,0x2f,0);
            FUN_000331dc();
            lVar11 = _wtol(param_3);
            SignalStarted(lVar11);
            pvVar10 = OpenEventW(0x1f0003,0,L"SYSTEM/ShellAPIReady");
            if (pvVar10 != (HANDLE)0x0) {
              EventModify(pvVar10,3);
              CloseHandle(pvVar10);
            }
            SVar3 = GetAsyncKeyState(0x10);
            if (CONCAT22(extraout_var_01,SVar3) == 0) {
              FUN_00013e4c();
            }
            else {
              local_5c = 0;
              LVar4 = RegQueryValueExW((HKEY)0x80000002,L"CalibrationData",
                                       (LPDWORD)L"HARDWARE\\DEVICEMAP\\TOUCH",(LPDWORD)0x0,
                                       (LPBYTE)0x0,&local_5c);
              if (LVar4 != 0) {
                TouchCalibrate();
              }
            }
            sndPlaySoundW(L"SystemStart",0x10003);
            bVar1 = true;
            while ((BVar12 = GetMessageW(&MStack_48,(HWND)0x0,0,0), BVar12 != 0 &&
                   (MStack_48.message != 0x12))) {
              iVar7 = (**(code **)(*piVar9 + 0x28))(piVar9,&MStack_48,0);
              if (iVar7 != 0) {
                TranslateMessage(&MStack_48);
                DispatchMessageW(&MStack_48);
              }
            }
            EventModify(DAT_0003555c,3);
            while (0 < DAT_00035554) {
              WaitForSingleObject(DAT_00035558,0xffffffff);
            }
          }
          (**(code **)(*piVar9 + 8))(piVar9);
        }
        FUN_0001e674();
        FUN_0001e58c();
        if (DAT_00035564 != (HMODULE)0x0) {
          FreeLibrary(DAT_00035564);
        }
        FUN_00016248();
        FUN_00016014();
        CoUninitialize();
        FUN_00033224();
        if (!bVar1) {
          return 1;
        }
        iVar7 = __GetUserKData(0xc);
        FUN_00033250(0,iVar7);
        return 1;
      }
    }
    else {
      hMem = (STRSAFE_LPWSTR)0x0;
      local_5c = 0x5c;
      if ((param_3 == (wchar_t *)0x0) || (*param_3 == L'\0')) {
        param_3 = (wchar_t *)&local_5c;
      }
      iVar7 = _wcsnicmp(param_3,L"-u",2);
      if (iVar7 == 0) {
        local_64 = -1;
        hMem = LocalAlloc(0,0x1018);
        if ((hMem != (STRSAFE_LPWSTR)0x0) &&
           (DVar13 = FUN_0001f080(&local_64,param_3 + 2,0), DVar13 == 0)) {
          FUN_0001eaa8(&local_64,hMem,0x80c);
          param_3 = hMem;
        }
        FUN_0001f030(&local_64);
      }
      _Dest = LocalAlloc(0x40,0x208);
      if (_Dest != (wchar_t *)0x0) {
        wcscpy(_Dest,L"::");
        local_58[0] = 0x102;
        iVar7 = FUN_00014ff4(param_3,_Dest + 2,local_58);
        if (iVar7 != 0) {
          param_3 = _Dest;
        }
      }
      if ((DAT_00035524 == 0) && (uVar14 = FUN_000158ec(param_3), uVar14 == 0)) {
        local_50.dwSize = 8;
        local_50.dwICC = 0x400;
        InitCommonControlsEx(&local_50);
        DAT_00035524 = 1;
        FUN_00014730(param_3);
        while (0 < DAT_00035554) {
          WaitForSingleObject(DAT_00035558,0xffffffff);
        }
      }
      else {
        (*(code *)&SUB_fffe67de)(param_3,0);
      }
      if (_Dest != (wchar_t *)0x0) {
        LocalFree(_Dest);
      }
      if (hMem != (STRSAFE_LPWSTR)0x0) {
        LocalFree(hMem);
      }
    }
  }
  return 0;
}



/* 00014730 FUN_00014730 */

/* Boundary evidence: original MIPS .pdata 00014730..000147d7. Semantic name remains unreviewed. */

void FUN_00014730(LPWSTR param_1)

{
  HWND hWnd;
  
  if (param_1 != (LPWSTR)0x0) {
    hWnd = (HWND)FUN_00015b7c(param_1);
    if (hWnd == (HWND)0x0) {
      FUN_0001af8c(param_1,0,(int *)0x0);
    }
    else {
      SetForegroundWindow(hWnd);
    }
  }
  return;
}



/* 000147d8 FUN_000147d8 */

/* Boundary evidence: original MIPS .pdata 000147d8..000147e3. Semantic name remains unreviewed. */

undefined4 FUN_000147d8(void)

{
  return 1;
}



/* 000147e4 FUN_000147e4 */

/* Boundary evidence: original MIPS .pdata 000147e4..000148fb. Semantic name remains unreviewed. */

LRESULT FUN_000147e4(undefined4 param_1,int *param_2)

{
  BOOL BVar1;
  LRESULT LVar2;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  
  local_28 = 0;
  memset(&local_24,0,8);
  LVar2 = 0;
  if (((param_2 == (int *)0x0) || (*param_2 != 0x98)) ||
     (BVar1 = IsWindow((HWND)param_2[1]), BVar1 == 0)) {
    SetLastError(0x57);
  }
  else {
    local_24 = 0x98;
    if (DAT_0003556c != 0) {
      local_28 = param_1;
      local_20 = param_2;
      LVar2 = SendMessageW(*(HWND *)(DAT_0003556c + 8),0x4a,0,(LPARAM)&local_28);
    }
  }
  return LVar2;
}



/* 000148fc FUN_000148fc */

/* Boundary evidence: original MIPS .pdata 000148fc..00014907. Semantic name remains unreviewed. */

undefined4 FUN_000148fc(void)

{
  return 1;
}



/* 00014908 FUN_00014908 */

/* Boundary evidence: original MIPS .pdata 00014908..00014b17. Semantic name remains unreviewed. */

void FUN_00014908(void)

{
  LSTATUS LVar1;
  DWORD DVar2;
  uint uVar3;
  COLORREF *pCVar4;
  COLORREF *pCVar5;
  uint *puVar6;
  COLORREF *pCVar7;
  uint uVar8;
  DWORD *pDVar9;
  HKEY local_3a0;
  DWORD local_39c [3];
  COLORREF local_390 [30];
  short local_318 [2];
  COLORREF local_314 [29];
  uint local_2a0 [30];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_00035518;
  local_39c[1] = 0x206;
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"ControlPanel\\Appearance",0,0,&local_3a0);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_3a0,L"Current",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)aWStack_228,
                             local_39c + 1);
    if (LVar1 == 0) {
      RegCloseKey(local_3a0);
      LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"ControlPanel\\Appearance\\Schemes",0,0,&local_3a0);
      if (LVar1 == 0) {
        local_39c[0] = 0x78;
        LVar1 = RegQueryValueExW(local_3a0,aWStack_228,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_318,
                                 local_39c);
        if (((LVar1 == 0) && (local_39c[0] != 0)) && (local_318[0] == -1)) {
          if (local_39c[0] < 0x78) {
            uVar8 = 0x1d - (0x78 - local_39c[0] >> 2);
          }
          else {
            uVar8 = 0x1d;
          }
          if (0 < (int)uVar8) {
            pCVar5 = local_314;
            pCVar4 = local_390;
            if (uVar8 != 0) {
              pCVar7 = pCVar4 + uVar8;
              do {
                *pCVar4 = *pCVar5;
                pCVar4 = pCVar4 + 1;
                pCVar5 = pCVar5 + 1;
              } while (pCVar4 != pCVar7);
            }
          }
          if ((int)uVar8 < 0x1d) {
            pDVar9 = local_390 + uVar8;
            do {
              DVar2 = GetSysColor(uVar8 | 0x40000000);
              uVar8 = uVar8 + 1;
              *pDVar9 = DVar2;
              pDVar9 = pDVar9 + 1;
            } while ((int)uVar8 < 0x1d);
          }
          uVar8 = 0;
          puVar6 = local_2a0;
          do {
            uVar3 = uVar8 | 0x40000000;
            uVar8 = uVar8 + 1;
            *puVar6 = uVar3;
            puVar6 = puVar6 + 1;
          } while ((int)uVar8 < 0x1d);
          SetSysColors(0x1d,(INT *)local_2a0,local_390);
        }
      }
    }
  }
  RegCloseKey(local_3a0);
  FUN_00033770(local_20);
  return;
}



/* 00014b18 FUN_00014b18 */

/* Boundary evidence: original MIPS .pdata 00014b18..00014bb7. Semantic name remains unreviewed. */

undefined4 FUN_00014b18(undefined2 *param_1,void *param_2,size_t param_3)

{
  SAFEARRAY *pSVar1;
  undefined4 uVar2;
  
  pSVar1 = SafeArrayCreateVector(0x11,0,param_3);
  if (pSVar1 == (SAFEARRAY *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    memcpy(pSVar1->pvData,param_2,param_3);
    memset(param_1,0,0x10);
    *(SAFEARRAY **)(param_1 + 4) = pSVar1;
    *param_1 = 0x2011;
    uVar2 = 0;
  }
  return uVar2;
}



/* 00014bb8 FUN_00014bb8 */

/* Boundary evidence: original MIPS .pdata 00014bb8..00014c17. Semantic name remains unreviewed. */

void FUN_00014bb8(undefined2 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  size_t sVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  sVar3 = 0;
  if (param_2 != (undefined1 *)0x0) {
    uVar2 = *param_2;
    sVar3 = 2;
    uVar1 = param_2[1];
    puVar4 = param_2;
    while (uVar5 = (uint)CONCAT11(uVar1,uVar2), uVar5 != 0) {
      puVar4 = puVar4 + uVar5;
      uVar2 = *puVar4;
      sVar3 = uVar5 + sVar3;
      uVar1 = puVar4[1];
    }
  }
  FUN_00014b18(param_1,param_2,sVar3);
  return;
}



/* 00014c18 FUN_00014c18 */

undefined4 FUN_00014c18(undefined4 *param_1,int *param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  
  puVar4 = (ushort *)*param_1;
  iVar6 = 0;
  uVar1 = 1;
  iVar3 = 0;
  puVar5 = puVar4;
  if (0 < param_3) {
    do {
      uVar2 = (uint)*puVar5;
      if (uVar2 - 0x30 < 10) {
        iVar6 = iVar6 * 0x10 + uVar2 + -0x30;
      }
      else {
        if (5 < (uVar2 | 0x20) - 0x61) {
          return 0;
        }
        iVar6 = iVar6 * 0x10 + (uVar2 | 0x20) + -0x57;
      }
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar3 < param_3);
  }
  if ((param_4 != 0) && (puVar5 = puVar4 + iVar3, iVar3 = iVar3 + 1, *puVar5 != param_4)) {
    uVar1 = 0;
  }
  *param_2 = iVar6;
  *param_1 = puVar4 + iVar3;
  return uVar1;
}



/* 00014cd4 FUN_00014cd4 */

/* Boundary evidence: original MIPS .pdata 00014cd4..00014e97. Semantic name remains unreviewed. */

undefined4 FUN_00014cd4(short *param_1,int *param_2)

{
  int iVar1;
  short *local_res0 [4];
  undefined1 local_10 [8];
  
  local_res0[0] = param_1 + 1;
  if (((*param_1 == 0x7b) && (iVar1 = FUN_00014c18(local_res0,param_2,8,0x2d), iVar1 != 0)) &&
     (iVar1 = FUN_00014c18(local_res0,(int *)local_10,4,0x2d), iVar1 != 0)) {
    *(short *)(param_2 + 1) = (short)local_10._0_4_;
    iVar1 = FUN_00014c18(local_res0,(int *)local_10,4,0x2d);
    if (iVar1 != 0) {
      *(short *)((int)param_2 + 6) = (short)local_10._0_4_;
      iVar1 = FUN_00014c18(local_res0,(int *)local_10,2,0);
      if (iVar1 != 0) {
        *(undefined1 *)(param_2 + 2) = local_10[0];
        iVar1 = FUN_00014c18(local_res0,(int *)local_10,2,0x2d);
        if (iVar1 != 0) {
          *(undefined1 *)((int)param_2 + 9) = local_10[0];
          iVar1 = FUN_00014c18(local_res0,(int *)local_10,2,0);
          if (iVar1 != 0) {
            *(undefined1 *)((int)param_2 + 10) = local_10[0];
            iVar1 = FUN_00014c18(local_res0,(int *)local_10,2,0);
            if (iVar1 != 0) {
              *(undefined1 *)((int)param_2 + 0xb) = local_10[0];
              iVar1 = FUN_00014c18(local_res0,(int *)local_10,2,0);
              if (iVar1 != 0) {
                *(undefined1 *)(param_2 + 3) = local_10[0];
                iVar1 = FUN_00014c18(local_res0,(int *)local_10,2,0);
                if (iVar1 != 0) {
                  *(undefined1 *)((int)param_2 + 0xd) = local_10[0];
                  iVar1 = FUN_00014c18(local_res0,(int *)local_10,2,0);
                  if (iVar1 != 0) {
                    *(undefined1 *)((int)param_2 + 0xe) = local_10[0];
                    iVar1 = FUN_00014c18(local_res0,(int *)local_10,2,0x7d);
                    if (iVar1 != 0) {
                      *(undefined1 *)((int)param_2 + 0xf) = local_10[0];
                      return 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



/* 00014e98 FUN_00014e98 */

/* Boundary evidence: original MIPS .pdata 00014e98..00014ff3. Semantic name remains unreviewed. */

undefined4 FUN_00014e98(STRSAFE_LPCWSTR param_1,PCNZWCH param_2,int param_3)

{
  HRESULT HVar1;
  LSTATUS LVar2;
  int iVar3;
  undefined4 uVar4;
  HKEY local_438;
  DWORD local_434 [3];
  wchar_t awStack_428 [7];
  undefined1 auStack_41a [498];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_00035518;
  uVar4 = 0;
  memcpy(awStack_428,L"CLSID\\",0xe);
  memset(auStack_41a,0,0x1f2);
  local_434[0] = 0;
  local_438 = (HKEY)0x0;
  HVar1 = StringCchCatW(awStack_428,0x100,param_1);
  if (HVar1 == 0) {
    LVar2 = RegOpenKeyExW((HKEY)0x80000000,awStack_428,0,0,&local_438);
    if (LVar2 == 0) {
      local_434[1] = 0x208;
      LVar2 = RegQueryValueExW(local_438,L"DisplayName",(LPDWORD)0x0,local_434,(LPBYTE)aWStack_228,
                               local_434 + 1);
      if (LVar2 == 0) {
        iVar3 = CompareStringW(0x400,0x20001,param_2,param_3,aWStack_228,-1);
        if (iVar3 == 2) {
          uVar4 = 1;
        }
      }
      RegCloseKey(local_438);
    }
  }
  FUN_00033770(local_20);
  return uVar4;
}



/* 00014ff4 FUN_00014ff4 */

/* Boundary evidence: original MIPS .pdata 00014ff4..00015483. Semantic name remains unreviewed. */

undefined4 FUN_00014ff4(wchar_t *param_1,STRSAFE_LPWSTR param_2,uint *param_3)

{
  wchar_t *pwVar1;
  PCNZWCH lpString2;
  size_t cchCount1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint cchDest;
  LPCWSTR pWVar5;
  wchar_t *pwVar6;
  DWORD DVar7;
  uint uVar8;
  DWORD local_258;
  HKEY local_254;
  wchar_t *local_250;
  DWORD local_24c;
  LPCWSTR local_248;
  DWORD local_244;
  PCNZWCH local_240;
  size_t local_23c;
  wchar_t *local_238;
  WCHAR aWStack_230 [256];
  uint local_30;
  
  local_30 = DAT_00035518;
  cchDest = *param_3;
  local_244 = 0;
  if ((((param_1 != (wchar_t *)0x0) && (param_2 != (STRSAFE_LPWSTR)0x0)) && (*param_1 != L'\\')) &&
     ((pwVar1 = wcschr(param_1,L':'), pwVar1 == (wchar_t *)0x0 &&
      (lpString2 = operator_new(0x208), local_240 = lpString2, lpString2 != (PCNZWCH)0x0)))) {
    local_258 = 0xffffffff;
    cchCount1 = wcslen(param_1);
    local_23c = cchCount1;
    pwVar1 = wcschr(param_1,L'\\');
    if (pwVar1 != (wchar_t *)0x0) {
      cchCount1 = (int)pwVar1 - (int)param_1 >> 1;
    }
    pwVar6 = L"\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CurrentGUIDs";
    local_254 = (HKEY)0x0;
    local_250 = L"\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CurrentGUIDs";
    local_238 = pwVar1;
    iVar2 = RegOpenKeyExW((HKEY)0x80000001,
                          L"\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CurrentGUIDs",
                          0,0,&local_254);
    if (local_254 == (HKEY)0x0) {
LAB_00015238:
      iVar3 = 0;
      if (iVar2 != 0) goto LAB_00015240;
    }
    else {
      if (iVar2 == 0) {
        local_258 = 0x100;
        local_24c = 0x208;
        DVar7 = 0;
        iVar2 = RegEnumValueW(local_254,0,aWStack_230,&local_258,(LPDWORD)0x0,&local_244,
                              (LPBYTE)lpString2,&local_24c);
        while (iVar2 == 0) {
          DVar7 = DVar7 + 1;
          iVar2 = CompareStringW(0x400,0x20001,param_1,cchCount1,lpString2,-1);
          if (iVar2 == 2) {
            cchDest = *param_3;
            if (local_258 + 1 <= *param_3) {
              cchDest = local_258 + 1;
            }
            iVar2 = StringCchCopyW(param_2,cchDest,aWStack_230);
            break;
          }
          local_258 = 0x100;
          local_24c = 0x208;
          iVar2 = RegEnumValueW(local_254,DVar7,aWStack_230,&local_258,(LPDWORD)0x0,&local_244,
                                (LPBYTE)lpString2,&local_24c);
        }
        RegCloseKey(local_254);
        pwVar6 = local_250;
        goto LAB_00015238;
      }
LAB_00015240:
      iVar2 = FUN_00014e98(pwVar6 + -0x28,param_1,cchCount1);
      if (iVar2 == 0) {
        local_248 = L"Explorer\\Desktop";
        uVar8 = 0;
        do {
          pWVar5 = local_248;
          local_254 = (HKEY)0x0;
          iVar3 = RegOpenKeyExW((HKEY)0x80000002,local_248,0,0,&local_254);
          if (local_254 == (HKEY)0x0) {
LAB_000153cc:
            lpString2 = local_240;
            pwVar1 = local_238;
            if (iVar3 == 0) break;
          }
          else if (iVar3 == 0) {
            local_258 = 0x100;
            local_250 = (wchar_t *)0x0;
            iVar3 = RegEnumValueW(local_254,0,aWStack_230,&local_258,(LPDWORD)0x0,(LPDWORD)0x0,
                                  (LPBYTE)0x0,(LPDWORD)0x0);
            DVar7 = local_258;
            while (iVar3 == 0) {
              local_258 = DVar7;
              iVar2 = FUN_00014e98(aWStack_230,param_1,cchCount1);
              if (iVar2 != 0) {
                cchDest = *param_3;
                if (DVar7 + 1 <= *param_3) {
                  cchDest = DVar7 + 1;
                }
                iVar3 = StringCchCopyW(param_2,cchDest,aWStack_230);
                pWVar5 = local_248;
                break;
              }
              local_250 = (wchar_t *)((int)local_250 + 1);
              local_258 = 0x100;
              iVar3 = RegEnumValueW(local_254,(DWORD)local_250,aWStack_230,&local_258,(LPDWORD)0x0,
                                    (LPDWORD)0x0,(LPBYTE)0x0,(LPDWORD)0x0);
              DVar7 = local_258;
              pWVar5 = local_248;
            }
            local_258 = DVar7;
            RegCloseKey(local_254);
            goto LAB_000153cc;
          }
          uVar8 = uVar8 + 0x32;
          local_248 = pWVar5 + 0x19;
          lpString2 = local_240;
          pwVar1 = local_238;
        } while (uVar8 < 100);
      }
      else {
        cchDest = *param_3;
        if (0x26 < cchDest) {
          cchDest = 0x27;
        }
        iVar3 = StringCchCopyW(param_2,cchDest,pwVar6 + -0x28);
      }
    }
    operator_delete(lpString2);
    if (iVar3 == 0) {
      if ((pwVar1 != (wchar_t *)0x0) && ((local_23c - cchCount1) + cchDest < *param_3)) {
        wcscat(param_2,pwVar1);
      }
      *param_3 = local_258 + 1;
      uVar4 = 1;
      goto LAB_00015448;
    }
  }
  uVar4 = 0;
LAB_00015448:
  FUN_00033770(local_30);
  return uVar4;
}



/* 00015484 FUN_00015484 */

/* Boundary evidence: original MIPS .pdata 00015484..0001564b. Semantic name remains unreviewed. */

undefined4 FUN_00015484(LPCWSTR param_1,wchar_t *param_2,int *param_3)

{
  bool bVar1;
  HKEY hKey;
  LSTATUS LVar2;
  LPBYTE lpData;
  int iVar3;
  size_t sVar4;
  HKEY local_30;
  DWORD local_2c [3];
  
  local_30 = (HKEY)0x0;
  LVar2 = RegCreateKeyExW((HKEY)0x80000001,
                          L"\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CurrentGUIDs",
                          0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_30,local_2c + 2);
  if (local_30 == (HKEY)0x0) goto LAB_00015614;
  if (LVar2 != 0) {
    return 0;
  }
  bVar1 = true;
  if (param_3 == (int *)0x0) {
LAB_000155cc:
    hKey = local_30;
    sVar4 = wcslen(param_2);
    LVar2 = RegSetValueExW(hKey,param_1,0,1,(BYTE *)param_2,(sVar4 + 1) * 2);
  }
  else {
    lpData = LocalAlloc(0,0x208);
    *param_3 = (int)lpData;
    if (lpData == (LPBYTE)0x0) goto LAB_000155cc;
    local_2c[1] = 0;
    local_2c[0] = 0x208;
    LVar2 = RegQueryValueExW(local_30,param_1,(LPDWORD)0x0,local_2c + 1,lpData,local_2c);
    if (LVar2 == 0) {
      *(undefined2 *)(*param_3 + 0x206) = 0;
      iVar3 = CompareStringW(0x400,0x20001,param_2,-1,(PCNZWCH)*param_3,local_2c[0] >> 1);
      if (iVar3 != 2) goto LAB_000155cc;
      bVar1 = false;
    }
    LocalFree((HLOCAL)*param_3);
    *param_3 = 0;
    if (bVar1) goto LAB_000155cc;
  }
  RegCloseKey(local_30);
LAB_00015614:
  if (LVar2 != 0) {
    return 0;
  }
  return 1;
}



/* 0001564c FUN_0001564c */

/* Boundary evidence: original MIPS .pdata 0001564c..000156c3. Semantic name remains unreviewed. */

UINT FUN_0001564c(HMENU param_1)

{
  BOOL BVar1;
  UINT item;
  tagMENUITEMINFOW local_40;
  
  memset(&local_40.fMask,0,0x28);
  local_40.cbSize = 0x2c;
  local_40.fMask = 2;
  item = 0;
  while (BVar1 = GetMenuItemInfoW(param_1,item,1,&local_40), BVar1 != 0) {
    item = item + 1;
  }
  return item;
}



/* 000156c4 FUN_000156c4 */

/* Boundary evidence: original MIPS .pdata 000156c4..000156f7. Semantic name remains unreviewed. */

UINT FUN_000156c4(HMENU param_1,UINT param_2)

{
  tagMENUITEMINFOW local_38;
  
  local_38.cbSize = 0x2c;
  local_38.fMask = 2;
  GetMenuItemInfoW(param_1,param_2,1,&local_38);
  return local_38.wID;
}



/* 000156f8 FUN_000156f8 */

/* Boundary evidence: original MIPS .pdata 000156f8..00015763. Semantic name remains unreviewed. */

wchar_t * FUN_000156f8(wchar_t *param_1)

{
  size_t sVar1;
  wchar_t *_Dest;
  
  if (param_1 == (wchar_t *)0x0) {
    _Dest = (wchar_t *)0x0;
  }
  else {
    sVar1 = wcslen(param_1);
    _Dest = LocalAlloc(0,(sVar1 + 1) * 2);
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,param_1);
    }
  }
  return _Dest;
}



/* 00015764 FUN_00015764 */

/* Boundary evidence: original MIPS .pdata 00015764..00015833. Semantic name remains unreviewed. */

undefined4 FUN_00015764(HDC param_1,wchar_t *param_2,int *param_3,size_t *param_4,int param_5)

{
  size_t cchString;
  int iVar1;
  int iVar2;
  tagSIZE tStack_20;
  
  iVar2 = param_3[2];
  iVar1 = *param_3;
  cchString = wcslen(param_2);
  if (cchString == 0) {
    *param_4 = 0;
  }
  else {
    GetTextExtentExPointW
              (param_1,param_2,cchString,iVar2 - iVar1,(LPINT)param_4,(LPINT)0x0,&tStack_20);
    if (*param_4 != cchString) {
      GetTextExtentExPointW
                (param_1,param_2,cchString,(iVar2 - iVar1) - param_5,(LPINT)param_4,(LPINT)0x0,
                 &tStack_20);
      return 1;
    }
  }
  return 0;
}



/* 00015834 FUN_00015834 */

/* Boundary evidence: original MIPS .pdata 00015834..000158eb. Semantic name remains unreviewed. */

bool FUN_00015834(void)

{
  LSTATUS LVar1;
  HKEY local_18;
  int local_14 [3];
  
  local_18 = (HKEY)0x0;
  local_14[0] = 1;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Explorer",0,0,&local_18);
  if (LVar1 == 0) {
    local_14[1] = 4;
    RegQueryValueExW(local_18,L"BrowseInPlace",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_14,
                     (LPDWORD)(local_14 + 1));
    RegCloseKey(local_18);
  }
  return local_14[0] != 0;
}



/* 000158ec FUN_000158ec */

/* Boundary evidence: original MIPS .pdata 000158ec..000159db. Semantic name remains unreviewed. */

uint FUN_000158ec(wchar_t *param_1)

{
  wchar_t wVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  int aiStack_28 [4];
  uint local_18;
  
  local_18 = DAT_00035518;
  uVar4 = 0;
  if ((param_1 != (wchar_t *)0x0) && (wVar1 = *param_1, wVar1 != L'\0')) {
    if (wVar1 != L'\\') {
      if ((wVar1 == L':') && (param_1[1] == L':')) {
        uVar4 = FUN_00014cd4(param_1 + 2,aiStack_28);
        goto LAB_000159bc;
      }
      iVar2 = _wcsnicmp(param_1,L"file://",7);
      if (iVar2 == 0) {
        param_1 = param_1 + 7;
      }
      else {
        iVar2 = _wcsnicmp(param_1,L"file:",5);
        if (iVar2 != 0) goto LAB_000159bc;
        param_1 = param_1 + 5;
      }
    }
    if (param_1 != (LPCWSTR)0x0) {
      DVar3 = GetFileAttributesW(param_1);
      uVar4 = DVar3 & 0x10;
    }
  }
LAB_000159bc:
  FUN_00033770(local_18);
  return uVar4;
}



/* 000159dc FUN_000159dc */

/* Boundary evidence: original MIPS .pdata 000159dc..00015a6f. Semantic name remains unreviewed. */

undefined4 * FUN_000159dc(undefined4 *param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    param_2 = (undefined4 *)0x0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    param_2[1] = 0;
    *param_2 = 0;
    if (param_1[2] == 0) {
      param_1[1] = param_2;
    }
    else {
      param_2[1] = *param_1;
      *(undefined4 **)*param_1 = param_2;
    }
    *param_1 = param_2;
    param_1[2] = param_1[2] + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  return param_2;
}



/* 00015a70 FUN_00015a70 */

/* Boundary evidence: original MIPS .pdata 00015a70..00015b17. Semantic name remains unreviewed. */

int * FUN_00015a70(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 == (int *)0x0) {
    param_2 = (int *)0x0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    iVar1 = param_1[2];
    param_1[2] = iVar1 + -1;
    if (iVar1 + -1 == 0) {
      *param_1 = 0;
      param_1[1] = 0;
    }
    else {
      iVar1 = *param_2;
      piVar2 = (int *)param_2[1];
      if (iVar1 == 0) {
        *piVar2 = 0;
        *param_1 = piVar2;
      }
      else if (piVar2 == (int *)0x0) {
        *(undefined4 *)(iVar1 + 4) = 0;
        param_1[1] = iVar1;
      }
      else {
        *piVar2 = iVar1;
        *(int **)(iVar1 + 4) = piVar2;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  return param_2;
}



/* 00015b18 FUN_00015b18 */

/* Boundary evidence: original MIPS .pdata 00015b18..00015b7b. Semantic name remains unreviewed. */

undefined4 * FUN_00015b18(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 3));
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  DAT_00035574 = puVar1;
  return puVar1;
}



/* 00015b7c FUN_00015b7c */

/* Boundary evidence: original MIPS .pdata 00015b7c..00015de3. Semantic name remains unreviewed. */

undefined4 FUN_00015b7c(LPWSTR param_1)

{
  HRESULT HVar1;
  int iVar2;
  int iVar3;
  LPCRITICAL_SECTION p_Var4;
  undefined4 uVar5;
  LPITEMIDLIST local_340;
  IMalloc *local_33c;
  int *local_338;
  LPCITEMIDLIST local_334;
  IShellFolder *local_330 [2];
  STRRET local_328;
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_00035518;
  uVar5 = 0;
  local_33c = (IMalloc *)0x0;
  local_330[0] = (IShellFolder *)0x0;
  local_338 = (int *)0x0;
  local_340 = (LPCITEMIDLIST)0x0;
  local_334 = (LPCITEMIDLIST)0x0;
  local_328.uType = 0;
  memset(&local_328.u,0,0x104);
  if (((DAT_00035574 != (int *)0x0) && (param_1 != (LPWSTR)0x0)) &&
     (HVar1 = SHGetMalloc(&local_33c), -1 < HVar1)) {
    HVar1 = SHGetDesktopFolder(local_330);
    if (((-1 < HVar1) &&
        (HVar1 = (*local_330[0]->lpVtbl->ParseDisplayName)
                           (local_330[0],(HWND)0x0,(IBindCtx *)0x0,param_1,(ULONG *)0x0,&local_340,
                            (ULONG *)0x0), -1 < HVar1)) &&
       ((HVar1 = SHBindToParent(local_340,(IID *)&DAT_00012000,&local_338,&local_334), -1 < HVar1 &&
        ((iVar2 = (**(code **)(*local_338 + 0x2c))(local_338,local_334,0x4000,&local_328),
         -1 < iVar2 && (HVar1 = StrRetToBufW(&local_328,local_340,aWStack_220,0x104), -1 < HVar1))))
       )) {
      p_Var4 = (LPCRITICAL_SECTION)(DAT_00035574 + 3);
      EnterCriticalSection(p_Var4);
      EnterCriticalSection(p_Var4);
      LeaveCriticalSection(p_Var4);
      for (iVar2 = *DAT_00035574; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
        if ((*(wchar_t **)(iVar2 + 0xc) != (wchar_t *)0x0) &&
           (iVar3 = _wcsicmp(aWStack_220,*(wchar_t **)(iVar2 + 0xc)), iVar3 == 0)) {
          uVar5 = *(undefined4 *)(iVar2 + 8);
          break;
        }
      }
      p_Var4 = (LPCRITICAL_SECTION)(DAT_00035574 + 3);
      EnterCriticalSection(p_Var4);
      LeaveCriticalSection(p_Var4);
      LeaveCriticalSection(p_Var4);
    }
    if (local_330[0] != (IShellFolder *)0x0) {
      (*local_330[0]->lpVtbl->Release)(local_330[0]);
    }
    if (local_338 != (int *)0x0) {
      (**(code **)(*local_338 + 8))();
    }
    if (local_340 != (LPCITEMIDLIST)0x0) {
      (*local_33c->lpVtbl->Free)(local_33c,local_340);
    }
    if (local_334 != (LPCITEMIDLIST)0x0) {
      (*local_33c->lpVtbl->Free)(local_33c,local_334);
    }
    (*local_33c->lpVtbl->Release)(local_33c);
  }
  FUN_00033770(local_18);
  return uVar5;
}



/* 00015de4 FUN_00015de4 */

/* Boundary evidence: original MIPS .pdata 00015de4..00015ecb. Semantic name remains unreviewed. */

undefined4 FUN_00015de4(int param_1)

{
  LPCRITICAL_SECTION p_Var1;
  int *hMem;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00035574 != (int *)0x0) && (param_1 != 0)) {
    p_Var1 = (LPCRITICAL_SECTION)(DAT_00035574 + 3);
    EnterCriticalSection(p_Var1);
    EnterCriticalSection(p_Var1);
    LeaveCriticalSection(p_Var1);
    hMem = (int *)*DAT_00035574;
    if (hMem != (int *)0x0) {
      do {
        if (hMem[2] == param_1) break;
        hMem = (int *)hMem[1];
      } while (hMem != (int *)0x0);
      if (hMem != (int *)0x0) {
        uVar2 = 1;
        FUN_00015a70(DAT_00035574,hMem);
        if ((HLOCAL)hMem[3] != (HLOCAL)0x0) {
          LocalFree((HLOCAL)hMem[3]);
        }
        LocalFree(hMem);
      }
    }
    p_Var1 = (LPCRITICAL_SECTION)(DAT_00035574 + 3);
    EnterCriticalSection(p_Var1);
    LeaveCriticalSection(p_Var1);
    LeaveCriticalSection(p_Var1);
  }
  return uVar2;
}



/* 00015ecc FUN_00015ecc */

/* Boundary evidence: original MIPS .pdata 00015ecc..00016013. Semantic name remains unreviewed. */

bool FUN_00015ecc(int param_1,wchar_t *param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  SIZE_T uBytes;
  LPCRITICAL_SECTION p_Var2;
  int iVar3;
  bool bVar4;
  
  bVar4 = false;
  if ((DAT_00035574 != (int *)0x0) && (param_1 != 0)) {
    p_Var2 = (LPCRITICAL_SECTION)(DAT_00035574 + 3);
    EnterCriticalSection(p_Var2);
    EnterCriticalSection(p_Var2);
    LeaveCriticalSection(p_Var2);
    iVar3 = *DAT_00035574;
    bVar4 = false;
    if (iVar3 != 0) {
      do {
        if (*(int *)(iVar3 + 8) == param_1) break;
        iVar3 = *(int *)(iVar3 + 4);
      } while (iVar3 != 0);
      if (iVar3 != 0) {
        if (param_2 == (wchar_t *)0x0) {
          if (*(HLOCAL *)(iVar3 + 0xc) != (HLOCAL)0x0) {
            LocalFree(*(HLOCAL *)(iVar3 + 0xc));
            *(undefined4 *)(iVar3 + 0xc) = 0;
          }
          bVar4 = true;
        }
        else {
          sVar1 = wcslen(param_2);
          uBytes = (sVar1 + 1) * 2;
          if (*(HLOCAL *)(iVar3 + 0xc) == (HLOCAL)0x0) {
            _Dest = LocalAlloc(0,uBytes);
          }
          else {
            _Dest = LocalReAlloc(*(HLOCAL *)(iVar3 + 0xc),uBytes,2);
          }
          bVar4 = _Dest != (wchar_t *)0x0;
          if (bVar4) {
            wcscpy(_Dest,param_2);
            *(wchar_t **)(iVar3 + 0xc) = _Dest;
          }
        }
      }
    }
    p_Var2 = (LPCRITICAL_SECTION)(DAT_00035574 + 3);
    EnterCriticalSection(p_Var2);
    LeaveCriticalSection(p_Var2);
    LeaveCriticalSection(p_Var2);
  }
  return bVar4;
}



/* 00016014 FUN_00016014 */

/* Boundary evidence: original MIPS .pdata 00016014..00016063. Semantic name remains unreviewed. */

undefined4 FUN_00016014(void)

{
  void *pvVar1;
  
  pvVar1 = DAT_00035574;
  if (DAT_00035574 != (void *)0x0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)DAT_00035574 + 0xc));
    operator_delete(pvVar1);
    DAT_00035574 = (void *)0x0;
  }
  return 1;
}



/* 00016064 FUN_00016064 */

/* Boundary evidence: original MIPS .pdata 00016064..0001615f. Semantic name remains unreviewed. */

bool FUN_00016064(HWND param_1)

{
  BOOL BVar1;
  undefined4 *puVar2;
  int iVar3;
  LPCRITICAL_SECTION p_Var4;
  bool bVar5;
  
  bVar5 = false;
  if (DAT_00035574 == (int *)0x0) {
    return false;
  }
  if (param_1 == (HWND)0x0) {
    return false;
  }
  BVar1 = IsWindow(param_1);
  if (BVar1 == 0) {
    return false;
  }
  p_Var4 = (LPCRITICAL_SECTION)(DAT_00035574 + 3);
  EnterCriticalSection(p_Var4);
  EnterCriticalSection(p_Var4);
  LeaveCriticalSection(p_Var4);
  iVar3 = *DAT_00035574;
  if (iVar3 != 0) {
    do {
      if (*(HWND *)(iVar3 + 8) == param_1) break;
      iVar3 = *(int *)(iVar3 + 4);
    } while (iVar3 != 0);
    if (iVar3 != 0) goto LAB_00016124;
  }
  puVar2 = LocalAlloc(0x40,0x10);
  bVar5 = puVar2 != (undefined4 *)0x0;
  if (bVar5) {
    puVar2[2] = param_1;
    FUN_000159dc(DAT_00035574,puVar2);
  }
LAB_00016124:
  p_Var4 = (LPCRITICAL_SECTION)(DAT_00035574 + 3);
  EnterCriticalSection(p_Var4);
  LeaveCriticalSection(p_Var4);
  LeaveCriticalSection(p_Var4);
  return bVar5;
}



/* 00016160 FUN_00016160 */

/* Boundary evidence: original MIPS .pdata 00016160..00016247. Semantic name remains unreviewed. */

undefined4 FUN_00016160(HINSTANCE param_1)

{
  HANDLE pvVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00035580);
  DAT_00035594 = 1;
  puVar5 = &DAT_0003559c;
  iVar4 = 0;
  do {
    pvVar1 = LoadImageW(param_1,(LPCWSTR)(iVar4 + 300U & 0xffff),1,0x10,0x10,0);
    *puVar5 = pvVar1;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + 1;
  } while ((int)puVar5 < 0x355b4);
  piVar3 = &DAT_000355b4;
  iVar4 = 0;
  do {
    iVar2 = LoadStringW(param_1,iVar4 + 0x4e84,(LPWSTR)0x0,0);
    *piVar3 = iVar2;
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + 1;
  } while ((int)piVar3 < 0x355c8);
  return 1;
}



/* 00016248 FUN_00016248 */

/* Boundary evidence: original MIPS .pdata 00016248..000162db. Semantic name remains unreviewed. */

undefined4 FUN_00016248(void)

{
  undefined4 *puVar1;
  
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00035580);
  puVar1 = &DAT_0003559c;
  DAT_00035594 = 0;
  do {
    if ((HICON)*puVar1 != (HICON)0x0) {
      DestroyIcon((HICON)*puVar1);
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x355b4);
  puVar1 = &DAT_000355b4;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != &DAT_000355c8);
  return 1;
}



/* 000162dc FUN_000162dc */

/* Boundary evidence: original MIPS .pdata 000162dc..00016393. Semantic name remains unreviewed. */

undefined4 FUN_000162dc(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_00035594 == 0) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00035580);
    if (DAT_0003557c == (HMODULE)0x0) {
      DAT_0003557c = LoadLibraryW(L"Urlmon.dll");
      if (DAT_0003557c != (HMODULE)0x0) {
        DAT_00035578 = DAT_00035578 + 1;
        uVar1 = 1;
        DAT_00035598 = 1;
      }
    }
    else {
      DAT_00035578 = DAT_00035578 + 1;
      uVar1 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00035580);
  }
  return uVar1;
}



/* 00016394 FUN_00016394 */

/* Boundary evidence: original MIPS .pdata 00016394..0001644b. Semantic name remains unreviewed. */

undefined4 FUN_00016394(void)

{
  undefined4 uVar1;
  
  if ((DAT_00035594 == 0) || (DAT_00035598 == 0)) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00035580);
    DAT_00035578 = DAT_00035578 + -1;
    if (DAT_00035578 == 0) {
      FreeLibrary(DAT_0003557c);
      DAT_0003557c = (HMODULE)0x0;
      DAT_00035598 = 0;
      DAT_000355c8 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00035580);
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001644c FUN_0001644c */

/* Boundary evidence: original MIPS .pdata 0001644c..00016507. Semantic name remains unreviewed. */

undefined4 FUN_0001644c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004001;
  if ((DAT_00035594 != 0) && (DAT_00035598 != 0)) {
    if ((DAT_000355c8 == (code *)0x0) &&
       (DAT_000355c8 = (code *)GetProcAddressW(DAT_0003557c,L"CoInternetCreateSecurityManager"),
       DAT_000355c8 == (code *)0x0)) {
      return 0x80004001;
    }
    uVar1 = (*DAT_000355c8)(param_1,param_2,param_3);
  }
  return uVar1;
}



/* 00016508 FUN_00016508 */

undefined4 FUN_00016508(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 6) {
    uVar1 = (&DAT_0003559c)[param_1];
  }
  return uVar1;
}



/* 00016530 FUN_00016530 */

undefined4 FUN_00016530(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 5) {
    uVar1 = (&DAT_000355b4)[param_1];
  }
  return uVar1;
}



/* 00016558 FUN_00016558 */

/* Boundary evidence: original MIPS .pdata 00016558..000165af. Semantic name remains unreviewed. */

void FUN_00016558(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000115d0;
  if ((int *)param_1[2] != (int *)0x0) {
    (**(code **)(*(int *)param_1[2] + 8))();
  }
  if ((HWND)param_1[1] != (HWND)0x0) {
    DestroyWindow((HWND)param_1[1]);
  }
  return;
}



/* 000165b0 FUN_000165b0 */

/* Boundary evidence: original MIPS .pdata 000165b0..00016647. Semantic name remains unreviewed. */

undefined4 FUN_000165b0(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_00012020,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_00012010,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004002;
    *param_3 = 0;
  }
  return uVar2;
}



/* 00016648 FUN_00016648 */

/* Boundary evidence: original MIPS .pdata 00016648..00016673. Semantic name remains unreviewed. */

LONG FUN_00016648(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0xc));
  return *(LONG *)(param_1 + 0xc);
}



/* 0001668c FUN_0001668c */

/* Boundary evidence: original MIPS .pdata 0001668c..000166ab. Semantic name remains unreviewed. */

void FUN_0001668c(undefined4 param_1,int param_2)

{
  FUN_0001af8c((wchar_t *)0x0,param_2,(int *)0x0);
  return;
}



/* 000166ac FUN_000166ac */

/* Boundary evidence: original MIPS .pdata 000166ac..000166ef. Semantic name remains unreviewed. */

undefined4 FUN_000166ac(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 8) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x14))();
  }
  return uVar1;
}



/* 000166f0 FUN_000166f0 */

/* Boundary evidence: original MIPS .pdata 000166f0..0001684f. Semantic name remains unreviewed. */

bool FUN_000166f0(int *param_1)

{
  HRESULT HVar1;
  int yBottom;
  int xRight;
  void **ppv;
  IShellFolder *local_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  tagRECT tStack_28;
  
  HVar1 = SHGetDesktopFolder(local_38);
  if (HVar1 == 0) {
    if (local_38[0] == (IShellFolder *)0x0) {
      return true;
    }
    ppv = (void **)(param_1 + 2);
    HVar1 = (*local_38[0]->lpVtbl->CreateViewObject)(local_38[0],(HWND)0x0,(IID *)&DAT_00012030,ppv)
    ;
    if ((HVar1 == 0) && (*ppv != (void *)0x0)) {
      local_30 = 1;
      local_2c = 0xc20;
      yBottom = GetSystemMetrics(0x4f);
      xRight = GetSystemMetrics(0x4e);
      SetRect(&tStack_28,0,0,xRight,yBottom);
      HVar1 = (**(code **)(*(int *)*ppv + 0x24))(*ppv,0,&local_30,param_1,&tStack_28,param_1 + 1);
      if ((HVar1 == 0) && (param_1[1] != 0)) {
        RegisterDesktop();
      }
      else {
        (**(code **)(*param_1 + 8))(param_1);
      }
    }
  }
  if (local_38[0] != (IShellFolder *)0x0) {
    (*local_38[0]->lpVtbl->Release)(local_38[0]);
  }
  return HVar1 == 0;
}



/* 00016850 FUN_00016850 */

/* Boundary evidence: original MIPS .pdata 00016850..000168a7. Semantic name remains unreviewed. */

int FUN_00016850(undefined4 *param_1)

{
  LONG LVar1;
  int iVar2;
  
  iVar2 = param_1[3];
  LVar1 = InterlockedDecrement(param_1 + 3);
  if (LVar1 == 0) {
    FUN_00016558(param_1);
    LocalFree(param_1);
    iVar2 = 0;
  }
  else {
    iVar2 = iVar2 + -1;
  }
  return iVar2;
}



/* 000168a8 FUN_000168a8 */

undefined4 * FUN_000168a8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000115d0;
  param_1[3] = 1;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



/* 000168cc FUN_000168cc */

/* Boundary evidence: original MIPS .pdata 000168cc..00016acf. Semantic name remains unreviewed. */

undefined4 FUN_000168cc(int param_1)

{
  LSTATUS LVar1;
  int iVar2;
  HRESULT HVar3;
  BSTR pOVar4;
  undefined4 uVar5;
  DWORD dwIndex;
  HKEY local_e0;
  DWORD local_dc;
  int *local_d8 [2];
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c4;
  IID IStack_c0;
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00035518;
  uVar5 = 0;
  if ((*(int *)(param_1 + 0x28) != 0) &&
     (LVar1 = RegOpenKeyExW((HKEY)0x80000002,
                            L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Browser Helper Objects"
                            ,0,0,&local_e0), LVar1 == 0)) {
    dwIndex = 0;
    local_dc = 0x40;
    iVar2 = RegEnumKeyExW(local_e0,0,aWStack_b0,&local_dc,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                          (PFILETIME)0x0);
    while (iVar2 == 0) {
      iVar2 = FUN_00014cd4(aWStack_b0,(int *)&IStack_c0);
      if ((iVar2 != 0) &&
         (HVar3 = CoCreateInstance(&IStack_c0,(LPUNKNOWN)0x0,1,(IID *)&DAT_00012040,local_d8),
         -1 < HVar3)) {
        (**(code **)(*local_d8[0] + 0xc))(local_d8[0],*(undefined4 *)(param_1 + 0x28));
        pOVar4 = SysAllocString(aWStack_b0);
        memset((void *)((int)&local_d0 + 2),0,0xe);
        local_d0 = CONCAT22(local_d0._2_2_,0xd);
        (**(code **)(**(int **)(param_1 + 0x28) + 0x88))
                  (*(int **)(param_1 + 0x28),pOVar4,local_d0,local_cc,local_d8[0],local_c4);
        (**(code **)(*local_d8[0] + 8))();
        uVar5 = 1;
      }
      dwIndex = dwIndex + 1;
      local_dc = 0x40;
      iVar2 = RegEnumKeyExW(local_e0,dwIndex,aWStack_b0,&local_dc,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
    }
    RegCloseKey(local_e0);
  }
  FUN_00033770(local_30);
  return uVar5;
}



/* 00016ad0 FUN_00016ad0 */

/* Boundary evidence: original MIPS .pdata 00016ad0..00016bd7. Semantic name remains unreviewed. */

undefined4 * FUN_00016ad0(undefined4 *param_1)

{
  FUN_0001d8f0(param_1);
  *param_1 = &PTR_FUN_00011a2c;
  param_1[3] = &PTR_LAB_00011a04;
  param_1[1] = &PTR_LAB_000119e0;
  param_1[6] = &PTR_LAB_00011998;
  param_1[2] = &PTR_LAB_0001195c;
  param_1[4] = &PTR_LAB_0001194c;
  param_1[9] = &PTR_LAB_00011904;
  param_1[5] = &PTR_LAB_000118e8;
  param_1[7] = &PTR_LAB_000118d4;
  param_1[8] = &PTR_LAB_000118b8;
  *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) & 0xfc;
  param_1[0x19] = 0;
  *(undefined2 *)((int)param_1 + 0x12e) = 0;
  *(byte *)((int)param_1 + 0x12d) = *(byte *)((int)param_1 + 0x12d) & 0xfe;
  *(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) & 0x87 | 0x58;
  param_1[0x452] = 2;
  param_1[0x453] = 0;
  param_1[0x1d] = 0;
  param_1[0x23] = 3;
  param_1[0x21] = 0;
  *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) & 0xfe;
  param_1[0x24] = 0;
  param_1[0x29] = 0;
  param_1[0x2c] = 0;
  return param_1;
}



/* 00016bd8 FUN_00016bd8 */

/* Boundary evidence: original MIPS .pdata 00016bd8..00016dfb. Semantic name remains unreviewed. */

undefined4 FUN_00016bd8(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_000120e0,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_00012010,0x10), iVar1 == 0)) {
    *param_3 = (int)param_1;
    goto LAB_00016dd0;
  }
  iVar1 = memcmp(param_2,&DAT_000120d0,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 1;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_000120c0,0x10);
    if (iVar1 == 0) {
LAB_00016cb0:
      piVar2 = param_1 + 2;
    }
    else {
      iVar1 = memcmp(param_2,&DAT_000120b0,0x10);
      if (iVar1 == 0) {
        piVar2 = param_1 + 3;
      }
      else {
        iVar1 = memcmp(param_2,&DAT_000120a0,0x10);
        if (iVar1 == 0) goto LAB_00016cb0;
        iVar1 = memcmp(param_2,&DAT_00011c64,0x10);
        if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_00012090,0x10), iVar1 == 0)) {
          piVar2 = param_1 + 5;
        }
        else {
          iVar1 = memcmp(param_2,&DAT_00012080,0x10);
          if (iVar1 == 0) {
            piVar2 = param_1 + 4;
          }
          else {
            iVar1 = memcmp(param_2,&DAT_00012070,0x10);
            if (iVar1 == 0) {
              piVar2 = param_1 + 6;
            }
            else {
              iVar1 = memcmp(param_2,&DAT_00012060,0x10);
              if (iVar1 == 0) {
                piVar2 = param_1 + 7;
              }
              else {
                iVar1 = memcmp(param_2,&DAT_00012050,0x10);
                if (iVar1 == 0) {
                  piVar2 = param_1 + 8;
                }
                else {
                  iVar1 = memcmp(param_2,&DAT_00012020,0x10);
                  if (iVar1 != 0) {
                    *param_3 = 0;
                    return 0x80004002;
                  }
                  piVar2 = param_1 + 9;
                }
              }
            }
          }
        }
      }
    }
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  *param_3 = (int)piVar2;
LAB_00016dd0:
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}



/* 00016dfc FUN_00016dfc */

/* Boundary evidence: original MIPS .pdata 00016dfc..00016e27. Semantic name remains unreviewed. */

LONG FUN_00016dfc(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x30));
  return *(LONG *)(param_1 + 0x30);
}



/* 00016e28 FUN_00016e28 */

/* Boundary evidence: original MIPS .pdata 00016e28..00016e83. Semantic name remains unreviewed. */

int FUN_00016e28(int *param_1)

{
  LONG LVar1;
  int iVar2;
  
  iVar2 = param_1[0xc];
  LVar1 = InterlockedDecrement(param_1 + 0xc);
  if (LVar1 == 0) {
    (**(code **)(*param_1 + 0x18))(param_1,1);
    iVar2 = 0;
  }
  else {
    iVar2 = iVar2 + -1;
  }
  return iVar2;
}



/* 00016ebc FUN_00016ebc */

/* Boundary evidence: original MIPS .pdata 00016ebc..00016f3b. Semantic name remains unreviewed. */

undefined4 FUN_00016ebc(int param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_00012050,0x10);
  if (iVar1 == 0) {
    uVar2 = (*(code *)**(undefined4 **)(param_1 + -0x10))
                      ((undefined4 *)(param_1 + -0x10),param_3,param_4);
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 00016f3c FUN_00016f3c */

/* Boundary evidence: original MIPS .pdata 00016f3c..00016f7f. Semantic name remains unreviewed. */

undefined4
FUN_00016f3c(undefined4 param_1,HWND param_2,LPCWSTR param_3,LPCWSTR param_4,UINT param_5,
            undefined4 param_6,undefined4 param_7,int *param_8)

{
  int iVar1;
  
  iVar1 = MessageBoxW(param_2,param_3,param_4,param_5);
  if (param_8 != (int *)0x0) {
    *param_8 = iVar1;
  }
  return 0;
}



/* 00016f8c FUN_00016f8c */

/* Boundary evidence: original MIPS .pdata 00016f8c..00017083. Semantic name remains unreviewed. */

undefined4
FUN_00016f8c(int param_1,undefined4 param_2,undefined4 param_3,LONG *param_4,LONG *param_5)

{
  LRESULT LVar1;
  tagRECT local_30;
  tagRECT tStack_20;
  
  GetClientRect(*(HWND *)(param_1 + 0x44),&local_30);
  if (((*(byte *)(param_1 + 0x124) & 8) != 0) && (*(HWND *)(param_1 + 0x88) != (HWND)0x0)) {
    LVar1 = SendMessageW(*(HWND *)(param_1 + 0x88),0x41b,0,0);
    local_30.top = LVar1 + local_30.top;
  }
  if (((*(byte *)(param_1 + 0x124) & 0x20) != 0) && (*(HWND *)(param_1 + 0x98) != (HWND)0x0)) {
    GetClientRect(*(HWND *)(param_1 + 0x98),&tStack_20);
    local_30.bottom = (local_30.bottom - tStack_20.bottom) + tStack_20.top;
  }
  if (param_4 != (LONG *)0x0) {
    *param_4 = local_30.left;
    param_4[1] = local_30.top;
    param_4[2] = local_30.right;
    param_4[3] = local_30.bottom;
  }
  if (param_5 != (LONG *)0x0) {
    *param_5 = local_30.left;
    param_5[1] = local_30.top;
    param_5[2] = local_30.right;
    param_5[3] = local_30.bottom;
  }
  return 0;
}



/* 00017084 FUN_00017084 */

/* Boundary evidence: original MIPS .pdata 00017084..00017147. Semantic name remains unreviewed. */

void FUN_00017084(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00011a2c;
  param_1[1] = &PTR_LAB_000119e0;
  param_1[2] = &PTR_LAB_0001195c;
  param_1[3] = &PTR_LAB_00011a04;
  param_1[4] = &PTR_LAB_0001194c;
  param_1[5] = &PTR_LAB_000118e8;
  param_1[6] = &PTR_LAB_00011998;
  param_1[7] = &PTR_LAB_000118d4;
  param_1[8] = &PTR_LAB_000118b8;
  param_1[9] = &PTR_LAB_00011904;
  if ((HLOCAL)param_1[0x19] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x19]);
  }
  if ((void *)param_1[0x1f] != (void *)0x0) {
    operator_delete((void *)param_1[0x1f]);
  }
  FUN_0001cfb0(param_1);
  return;
}



/* 00017148 FUN_00017148 */

/* Boundary evidence: original MIPS .pdata 00017148..000171fb. Semantic name remains unreviewed. */

undefined4 FUN_00017148(int param_1)

{
  int iVar1;
  int *piVar2;
  BSTR local_18;
  undefined4 local_14;
  
  piVar2 = *(int **)(param_1 + 0x28);
  local_18 = (BSTR)0x0;
  if ((piVar2 != (int *)0x0) && (*(int *)(param_1 + 0x74) != 0)) {
    iVar1 = (**(code **)(*piVar2 + 0x78))(piVar2,&local_18);
    if ((-1 < iVar1) &&
       (iVar1 = (**(code **)(**(int **)(param_1 + 0x74) + 0x14))
                          (*(int **)(param_1 + 0x74),local_18,&local_14,0), -1 < iVar1)) {
      *(undefined4 *)(param_1 + 0x8c) = local_14;
    }
    if (local_18 != (BSTR)0x0) {
      SysFreeString(local_18);
    }
    if (-1 < iVar1) {
      return 1;
    }
  }
  return 0;
}



/* 000171fc FUN_000171fc */

/* Boundary evidence: original MIPS .pdata 000171fc..00017323. Semantic name remains unreviewed. */

void FUN_000171fc(int param_1)

{
  wchar_t *bstrString;
  LPARAM LVar1;
  int iVar2;
  wchar_t *local_18 [2];
  
  if (*(uint *)(param_1 + 0x8c) < 5) {
    if ((*(byte *)(param_1 + 300) & 0x40) == 0) {
      local_18[0] = (wchar_t *)0x0;
      (**(code **)(**(int **)(param_1 + 0x28) + 0x74))(*(int **)(param_1 + 0x28),local_18);
      bstrString = local_18[0];
      if (local_18[0] == (wchar_t *)0x0) {
        return;
      }
      iVar2 = wcsncmp(local_18[0],L"\\\\",2);
      SysFreeString(bstrString);
      if (iVar2 != 0) {
        return;
      }
    }
    if ((*(byte *)(param_1 + 300) & 0x20) == 0) {
      return;
    }
    LVar1 = FUN_00016508(*(uint *)(param_1 + 0x8c));
    SendMessageW(*(HWND *)(param_1 + 0xa0),0x40f,4,LVar1);
    LVar1 = FUN_00016530(*(uint *)(param_1 + 0x8c));
  }
  else {
    SendMessageW(*(HWND *)(param_1 + 0xa0),0x40f,4,0);
    LVar1 = LoadStringW(DAT_00035560,0x4e2c,(LPWSTR)0x0,0);
  }
  SendMessageW(*(HWND *)(param_1 + 0xa0),0x40b,4,LVar1);
  return;
}



/* 00017324 FUN_00017324 */

/* Boundary evidence: original MIPS .pdata 00017324..000173f7. Semantic name remains unreviewed. */

void FUN_00017324(int param_1)

{
  LRESULT Y;
  int iVar1;
  tagRECT local_30;
  tagRECT tStack_20;
  
  Y = 0;
  iVar1 = 0;
  if ((*(byte *)(param_1 + 300) & 0x20) != 0) {
    GetClientRect(*(HWND *)(param_1 + 0xa0),&tStack_20);
    iVar1 = tStack_20.bottom - tStack_20.top;
  }
  if ((*(byte *)(param_1 + 300) & 8) != 0) {
    Y = SendMessageW(*(HWND *)(param_1 + 0x90),0x41b,0,0);
  }
  GetClientRect(*(HWND *)(param_1 + 0x4c),&local_30);
  SetWindowPos(*(HWND *)(param_1 + 0x48),(HWND)0x0,0,Y,local_30.right - local_30.left,
               ((local_30.bottom - local_30.top) - iVar1) - Y,4);
  return;
}



/* 000173f8 FUN_000173f8 */

/* Boundary evidence: original MIPS .pdata 000173f8..0001752b. Semantic name remains unreviewed. */

undefined4 FUN_000173f8(int param_1,int param_2)

{
  WPARAM wParam;
  LRESULT LVar1;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  int local_34;
  
  if ((param_2 == 0) != ((*(byte *)(param_1 + 300) & 0x10) == 0)) {
    local_64 = 0x101;
    local_68 = 0x4c;
    wParam = SendMessageW(*(HWND *)(param_1 + 0x90),0x410,0x16,0);
    SendMessageW(*(HWND *)(param_1 + 0x90),0x41c,wParam,(LPARAM)&local_68);
    if (local_34 != 0x16) {
      return 0;
    }
    if (param_2 == 0) {
      local_60 = local_60 | 8;
    }
    else {
      local_60 = local_60 & 0xfffffff7;
    }
    LVar1 = SendMessageW(*(HWND *)(param_1 + 0x90),0x40b,wParam,(LPARAM)&local_68);
    if (LVar1 == 0) {
      return 0;
    }
    *(byte *)(param_1 + 300) =
         ((param_2 != 0) << 4 ^ *(byte *)(param_1 + 300)) & 0x10 ^ *(byte *)(param_1 + 300);
  }
  return 1;
}



/* 0001752c FUN_0001752c */

/* Boundary evidence: original MIPS .pdata 0001752c..000175df. Semantic name remains unreviewed. */

undefined4 FUN_0001752c(int param_1,int param_2)

{
  int nCmdShow;
  
  if (((*(byte *)(param_1 + 300) & 0x20) == 0) != (param_2 == 0)) {
    nCmdShow = 5;
    if (param_2 == 0) {
      nCmdShow = 0;
    }
    ShowWindow(*(HWND *)(param_1 + 0xa0),nCmdShow);
    *(byte *)(param_1 + 300) =
         ((param_2 != 0) << 5 ^ *(byte *)(param_1 + 300)) & 0x20 ^ *(byte *)(param_1 + 300);
  }
  if (param_2 != 0) {
    FUN_000171fc(param_1);
  }
  return 1;
}



/* 000175e0 FUN_000175e0 */

/* Boundary evidence: original MIPS .pdata 000175e0..000176af. Semantic name remains unreviewed. */

undefined4 FUN_000175e0(int param_1)

{
  WPARAM wParam;
  HWND hWnd;
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 0x6c) & 2) == 0) {
    wParam = SendMessageW(*(HWND *)(param_1 + 0x90),0x410,0xffffffff,0);
    hWnd = (HWND)CommandBands_GetCommandBar(*(undefined4 *)(param_1 + 0x90),wParam);
    SendMessageW(*(HWND *)(param_1 + 0x90),0x402,wParam,0);
    DestroyWindow(hWnd);
  }
  else {
    uVar1 = 0xb;
    if ((*(byte *)(param_1 + 300) & 0x80) == 0) {
      uVar1 = 0;
    }
    CommandBands_AddAdornments(*(undefined4 *)(param_1 + 0x90),DAT_00035560,uVar1,0);
  }
  return 1;
}



/* 000176b0 FUN_000176b0 */

/* Boundary evidence: original MIPS .pdata 000176b0..00017833. Semantic name remains unreviewed. */

undefined4 FUN_000176b0(int param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  LRESULT LVar1;
  int iVar2;
  undefined4 uVar3;
  HWND hWnd;
  undefined4 uVar4;
  tagRECT local_80;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_54;
  int local_44;
  undefined4 local_3c;
  
  local_70 = 0x4c;
  local_6c = 0x109;
  local_68 = 0x100;
  local_3c = 0x14;
  local_54 = 1;
  uVar4 = 0;
  if (param_4 != -1) {
    local_6c = 0x149;
    local_44 = param_4;
  }
  LVar1 = SendMessageW(*(HWND *)(param_1 + 0x90),0x40c,0,0);
  if (LVar1 == 0) {
    iVar2 = CommandBands_AddBands(*(HWND *)(param_1 + 0x90),DAT_00035560,1);
  }
  else {
    iVar2 = SendMessageW(*(HWND *)(param_1 + 0x90),0x40a,0,(LPARAM)&local_70);
  }
  if (iVar2 != 0) {
    uVar3 = CommandBands_GetCommandBar(*(undefined4 *)(param_1 + 0x90),0);
    *(undefined4 *)(param_1 + 0x94) = uVar3;
    iVar2 = CommandBar_InsertMenubar(uVar3,DAT_00035560,param_2,0);
    if (iVar2 != 0) {
      if (param_4 == -1) {
        hWnd = (HWND)CommandBar_GetItemWindow(*(undefined4 *)(param_1 + 0x94),0);
        GetClientRect(hWnd,&local_80);
        local_44 = (local_80.right - local_80.left) + 5;
        local_6c = 0x40;
        SendMessageW(*(HWND *)(param_1 + 0x90),0x40b,0,(LPARAM)&local_70);
      }
      uVar4 = 1;
    }
  }
  return uVar4;
}



/* 00017834 FUN_00017834 */

/* Boundary evidence: original MIPS .pdata 00017834..000179ab. Semantic name remains unreviewed. */

undefined4 FUN_00017834(int param_1,LPARAM param_2,WPARAM param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  LRESULT LVar3;
  undefined4 uVar4;
  tagRECT tStack_c8;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_9c;
  int local_8c;
  undefined4 local_84;
  undefined4 local_68;
  undefined4 local_64;
  int local_3c;
  
  local_b4 = 0x148;
  local_b8 = 0x4c;
  uVar4 = 0;
  local_84 = 0x15;
  local_9c = 0;
  if (param_5 == -1) {
    GetClientRect(*(HWND *)(param_1 + 0x4c),&tStack_c8);
    local_68 = 0x4c;
    local_64 = 0x40;
    SendMessageW(*(HWND *)(param_1 + 0x90),0x41c,0,(LPARAM)&local_68);
    local_8c = tStack_c8.right - local_3c;
  }
  else {
    local_b4 = 0x149;
    local_8c = param_5;
    local_b0 = param_4;
  }
  iVar1 = CommandBands_AddBands(*(undefined4 *)(param_1 + 0x90),DAT_00035560,1,&local_b8);
  if (iVar1 != 0) {
    uVar2 = CommandBands_GetCommandBar(*(undefined4 *)(param_1 + 0x90),1);
    *(undefined4 *)(param_1 + 0x9c) = uVar2;
    iVar1 = CommandBar_AddBitmap(uVar2,DAT_00035560,0x33,0x10,0x10,0x10);
    if ((-1 < iVar1) &&
       (LVar3 = SendMessageW(*(HWND *)(param_1 + 0x9c),0x444,param_3,param_2), LVar3 != 0)) {
      SendMessageW(*(HWND *)(param_1 + 0x9c),0x451,7,DAT_000355d0);
      uVar4 = 1;
    }
  }
  return uVar4;
}



/* 00017a14 FUN_00017a14 */

/* Boundary evidence: original MIPS .pdata 00017a14..00017a83. Semantic name remains unreviewed. */

undefined4
FUN_00017a14(int param_1,int param_2,UINT param_3,WPARAM param_4,LPARAM param_5,LRESULT *param_6)

{
  undefined4 uVar1;
  LRESULT LVar2;
  HWND hWnd;
  
  uVar1 = 0x80004005;
  if (param_2 == 1) {
    hWnd = *(HWND *)(param_1 + 0x7c);
  }
  else {
    if (param_2 != 2) {
      return 0x80004005;
    }
    hWnd = *(HWND *)(param_1 + 0x78);
  }
  if (hWnd != (HWND)0x0) {
    LVar2 = SendMessageW(hWnd,param_3,param_4,param_5);
    uVar1 = 0;
    if (param_6 != (LRESULT *)0x0) {
      *param_6 = LVar2;
    }
  }
  return uVar1;
}



/* 00017a84 FUN_00017a84 */

/* Boundary evidence: original MIPS .pdata 00017a84..00017f07. Semantic name remains unreviewed. */

undefined4 FUN_00017a84(int param_1,LPARAM param_2,WPARAM param_3,uint param_4)

{
  WPARAM WVar1;
  HWND hWnd;
  LRESULT LVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 local_d8;
  uint local_d4;
  int local_d0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  int local_ac;
  undefined4 local_a4;
  tagRECT tStack_88;
  undefined4 local_78;
  undefined4 local_74;
  uint local_70;
  int local_4c;
  
  uVar9 = 0x80004005;
  if ((param_4 & 2) == 0) {
    if (*(int *)(param_1 + 0x78) != 0) {
      WVar1 = SendMessageW(*(HWND *)(param_1 + 0x6c),0x410,0x15,0);
      SendMessageW(*(HWND *)(param_1 + 0x6c),0x402,WVar1,0);
      DestroyWindow(*(HWND *)(param_1 + 0x78));
    }
    hWnd = CreateWindowExW(0,L"ToolbarWindow32",(LPCWSTR)0x0,0x50001104,0,0,0,0,
                           *(HWND *)(param_1 + 0x6c),(HMENU)0x0,DAT_00035560,(LPVOID)0x0);
    *(HWND *)(param_1 + 0x78) = hWnd;
    if (hWnd != (HWND)0x0) {
      SendMessageW(hWnd,0x41e,0x14,0);
      local_d4 = 0x178;
      local_b8 = *(undefined4 *)(param_1 + 0x78);
      local_a4 = 0x15;
      local_b0 = 0x18;
      local_d8 = 0x4c;
      local_78 = 0x4c;
      local_b4 = 0;
      local_bc = 0;
      iVar8 = -1;
      iVar7 = -1;
      iVar5 = 0;
      piVar6 = (int *)(param_1 + 0xd0);
      iVar3 = -1;
      do {
        iVar4 = *piVar6;
        iVar10 = iVar5;
        if (iVar4 != 0x14) {
          iVar10 = iVar3;
          if (iVar4 == 0x15) {
            local_d0 = piVar6[1];
            local_ac = piVar6[2];
            local_d4 = local_d4 | 1;
            if ((iVar7 == -1) || (iVar5 <= iVar7)) {
              iVar3 = SendMessageW(*(HWND *)(param_1 + 0x6c),0x40a,1,(LPARAM)&local_d8);
            }
            else {
              iVar3 = CommandBands_AddBands
                                (*(undefined4 *)(param_1 + 0x6c),DAT_00035560,1,&local_d8);
            }
            iVar8 = iVar5;
            if (iVar3 == 0) {
              return 0x80004005;
            }
          }
          else if (iVar4 == 0x16) {
            local_74 = 0x41;
            local_70 = piVar6[1];
            local_4c = piVar6[2];
            *(byte *)(param_1 + 0x108) =
                 (((local_70 & 8) == 0) << 4 ^ *(byte *)(param_1 + 0x108)) & 0x10 ^
                 *(byte *)(param_1 + 0x108);
            WVar1 = SendMessageW(*(HWND *)(param_1 + 0x6c),0x410,0x16,0);
            SendMessageW(*(HWND *)(param_1 + 0x6c),0x40b,WVar1,(LPARAM)&local_78);
            iVar7 = iVar5;
          }
        }
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 5;
        iVar3 = iVar10;
      } while (iVar5 < 3);
      if (iVar8 == -1) {
        GetClientRect(*(HWND *)(param_1 + 0x28),&tStack_88);
        local_74 = 0x40;
        local_4c = 0;
        SendMessageW(*(HWND *)(param_1 + 0x6c),0x41c,0,(LPARAM)&local_78);
        local_ac = tStack_88.right - local_4c;
        LVar2 = SendMessageW(*(HWND *)(param_1 + 0x6c),0x40a,1,(LPARAM)&local_d8);
        if (LVar2 == 0) {
          return 0x80004005;
        }
      }
      if (((((param_4 & 1) == 0) ||
           (iVar3 = CommandBar_AddBitmap
                              (*(undefined4 *)(param_1 + 0x78),DAT_00035560,0x33,0x10,0x10,0x10),
           -1 < iVar3)) &&
          (iVar3 = CommandBar_AddBitmap(*(undefined4 *)(param_1 + 0x78),0xffffffff,0,0xf,0x10,0x10),
          -1 < iVar3)) &&
         ((iVar3 = CommandBar_AddBitmap(*(undefined4 *)(param_1 + 0x78),0xffffffff,4,0xc,0x10,0x10),
          -1 < iVar3 &&
          (LVar2 = SendMessageW(*(HWND *)(param_1 + 0x78),0x444,param_3,param_2), LVar2 != 0)))) {
        if ((iVar10 != -1) && (*(int *)((iVar10 + 0xb) * 0x14 + param_1) != 0)) {
          SendMessageW(*(HWND *)(param_1 + 0x6c),0x41f,0,0);
        }
        if ((iVar8 != -1) && (*(int *)((iVar8 + 0xb) * 0x14 + param_1) != 0)) {
          WVar1 = SendMessageW(*(HWND *)(param_1 + 0x6c),0x410,0x15,0);
          SendMessageW(*(HWND *)(param_1 + 0x6c),0x41f,WVar1,0);
        }
        if ((iVar7 != -1) && (*(int *)((iVar7 + 0xb) * 0x14 + param_1) != 0)) {
          WVar1 = SendMessageW(*(HWND *)(param_1 + 0x6c),0x410,0x16,0);
          SendMessageW(*(HWND *)(param_1 + 0x6c),0x41f,WVar1,0);
        }
        uVar9 = 0;
      }
    }
  }
  return uVar9;
}



/* 00017f08 FUN_00017f08 */

/* Boundary evidence: original MIPS .pdata 00017f08..00017f67. Semantic name remains unreviewed. */

undefined4 FUN_00017f08(int param_1,int param_2)

{
  undefined4 uVar1;
  HWND pHVar2;
  
  uVar1 = 1;
  if ((*(int *)(param_2 + 4) == 0x100) && (*(int *)(param_2 + 8) == 9)) {
    pHVar2 = GetFocus();
    if (pHVar2 != *(HWND *)(param_1 + 0x9c)) {
      SetFocus(*(HWND *)(param_1 + 0x9c));
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 00017f68 FUN_00017f68 */

/* Boundary evidence: original MIPS .pdata 00017f68..00018063. Semantic name remains unreviewed. */

undefined4 FUN_00017f68(int *param_1)

{
  undefined4 uVar1;
  _union_2683 local_20;
  
  local_20.n2.vt = 0;
  uVar1 = FUN_0001d6ac(param_1);
  FUN_00016064((HWND)param_1[0x13]);
  if ((*(byte *)(param_1 + 0x1b) & 1) == 0) {
    return uVar1;
  }
  if ((int *)param_1[10] == (int *)0x0) {
    return uVar1;
  }
  if ((undefined1 *)param_1[0x1a] == (undefined1 *)0x0) {
    if ((OLECHAR *)param_1[0x19] == (OLECHAR *)0x0) {
      (**(code **)(*(int *)param_1[10] + 0x24))();
      goto LAB_0001803c;
    }
    local_20.n2.vt = 8;
    local_20._8_4_ = SysAllocString((OLECHAR *)param_1[0x19]);
    LocalFree((HLOCAL)param_1[0x19]);
    param_1[0x19] = 0;
  }
  else {
    FUN_00014bb8((undefined2 *)&local_20,(undefined1 *)param_1[0x1a]);
    param_1[0x1a] = 0;
  }
  (**(code **)(*(int *)param_1[10] + 0xd0))((int *)param_1[10],&local_20,0,0,0,0);
LAB_0001803c:
  VariantClear((VARIANTARG *)&local_20.n2);
  return uVar1;
}



/* 00018064 FUN_00018064 */

/* Boundary evidence: original MIPS .pdata 00018064..0001821b. Semantic name remains unreviewed. */

void FUN_00018064(int param_1,HMENU param_2)

{
  bool bVar1;
  UINT UVar2;
  UINT *hMem;
  int iVar3;
  UINT UVar4;
  int iVar5;
  uint uVar6;
  UINT *pUVar7;
  UINT *pUVar8;
  UINT UVar9;
  int *local_28 [2];
  
  if (*(int *)(param_1 + 0x28) != 0) {
    UVar2 = FUN_0001564c(param_2);
    hMem = LocalAlloc(0x40,UVar2 << 3);
    if (hMem != (UINT *)0x0) {
      iVar3 = (**(code **)**(undefined4 **)(param_1 + 0x28))
                        (*(undefined4 **)(param_1 + 0x28),&DAT_00012100,local_28);
      if (-1 < iVar3) {
        UVar9 = 0;
        iVar3 = 0;
        pUVar7 = hMem;
        if (0 < (int)UVar2) {
          do {
            UVar4 = FUN_000156c4(param_2,UVar9);
            if ((0xfff < (int)UVar4) && ((int)UVar4 < 0x1200)) {
              *pUVar7 = UVar4;
              iVar3 = iVar3 + 1;
              pUVar7 = pUVar7 + 2;
            }
            UVar9 = UVar9 + 1;
          } while ((int)UVar9 < (int)UVar2);
          if (iVar3 != 0) {
            iVar5 = (**(code **)(*local_28[0] + 0xc))(local_28[0],&UNK_00011f5c,iVar3,hMem,0);
            if (-1 < iVar5) {
              while (bVar1 = iVar3 != 0, iVar3 = iVar3 + -1, bVar1) {
                pUVar8 = pUVar7 + -2;
                uVar6 = pUVar7[-1];
                pUVar7 = pUVar8;
                if ((uVar6 & 2) == 0) {
                  if ((uVar6 & 1) != 0) {
                    EnableMenuItem(param_2,*pUVar8,1);
                  }
                }
                else {
                  UVar2 = 0;
                  if ((uVar6 & 4) != 0) {
                    UVar2 = 8;
                  }
                  EnableMenuItem(param_2,*pUVar8,0);
                  CheckMenuItem(param_2,*pUVar8,UVar2);
                }
              }
            }
          }
        }
        (**(code **)(*local_28[0] + 8))();
      }
      LocalFree(hMem);
    }
  }
  return;
}



/* 0001821c FUN_0001821c */

/* Boundary evidence: original MIPS .pdata 0001821c..000182e3. Semantic name remains unreviewed. */

HMENU FUN_0001821c(undefined4 param_1,UINT *param_2,int param_3,int *param_4)

{
  HMENU hMenu;
  int iVar1;
  int iVar2;
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_00035518;
  hMenu = CreatePopupMenu();
  if (hMenu != (HMENU)0x0) {
    iVar2 = 0;
    iVar1 = param_3;
    if (0 < param_3) {
      do {
        LoadStringW(DAT_00035560,param_2[2],aWStack_230,0x104);
        AppendMenuW(hMenu,*param_2,param_2[1],aWStack_230);
        iVar1 = iVar1 + -1;
        param_2 = param_2 + 3;
        iVar2 = param_3;
      } while (iVar1 != 0);
    }
    *param_4 = iVar2;
  }
  FUN_00033770(local_28);
  return hMenu;
}



/* 000182f4 FUN_000182f4 */

/* Boundary evidence: original MIPS .pdata 000182f4..0001832f. Semantic name remains unreviewed. */

undefined4 FUN_000182f4(int param_1,int param_2,int param_3)

{
  SetWindowPos(*(HWND *)(param_1 + 0x2c),(HWND)0x0,param_2,param_3,0,0,0x15);
  return 0;
}



/* 00018330 FUN_00018330 */

/* Boundary evidence: original MIPS .pdata 00018330..000183a3. Semantic name remains unreviewed. */

undefined4 FUN_00018330(int param_1,int param_2,int param_3)

{
  tagRECT local_20;
  
  GetWindowRect(*(HWND *)(param_1 + 0x2c),&local_20);
  SetWindowPos(*(HWND *)(param_1 + 0x2c),(HWND)0x0,local_20.left + param_2,local_20.top + param_3,0,
               0,0x15);
  return 0;
}



/* 000183a4 FUN_000183a4 */

/* Boundary evidence: original MIPS .pdata 000183a4..000183ff. Semantic name remains unreviewed. */

undefined4 FUN_000183a4(int param_1,int param_2,int param_3)

{
  if (param_2 < 100) {
    param_2 = 100;
  }
  if (param_3 < 100) {
    param_3 = 100;
  }
  SetWindowPos(*(HWND *)(param_1 + 0x2c),(HWND)0x0,0,0,param_2,param_3,0x16);
  return 0;
}



/* 00018400 FUN_00018400 */

/* Boundary evidence: original MIPS .pdata 00018400..000184a7. Semantic name remains unreviewed. */

undefined4 FUN_00018400(int param_1,int param_2,int param_3)

{
  int cy;
  int cx;
  tagRECT local_20;
  
  GetWindowRect(*(HWND *)(param_1 + 0x2c),&local_20);
  cx = (local_20.right - local_20.left) + param_2;
  cy = (local_20.bottom - local_20.top) + param_3;
  if (cx < 100) {
    cx = 100;
  }
  if (cy < 100) {
    cy = 100;
  }
  SetWindowPos(*(HWND *)(param_1 + 0x2c),(HWND)0x0,0,0,cx,cy,0x16);
  return 0;
}



/* 000184a8 FUN_000184a8 */

/* Boundary evidence: original MIPS .pdata 000184a8..00018677. Semantic name remains unreviewed. */

undefined4 FUN_000184a8(int param_1,int param_2,int *param_3)

{
  LRESULT Y;
  undefined4 *puVar1;
  int iVar2;
  int *local_48 [2];
  tagRECT tStack_40;
  tagRECT local_30;
  tagRECT tStack_20;
  
  if (param_2 == 0x19) {
    if (param_3[2] == -0x33f) {
      Y = SendMessageW((HWND)*param_3,0x41b,0,0);
      if (((*(byte *)(param_1 + 300) & 0x20) == 0) || (*(HWND *)(param_1 + 0xa0) == (HWND)0x0)) {
        tStack_40.top = 0;
        tStack_40.bottom = 0;
      }
      else {
        GetClientRect(*(HWND *)(param_1 + 0xa0),&tStack_40);
      }
      if (*(int *)(param_1 + 0x48) != 0) {
        GetClientRect(*(HWND *)(param_1 + 0x4c),&local_30);
        GetClientRect(*(HWND *)(param_1 + 0x48),&tStack_20);
        iVar2 = (((local_30.bottom - local_30.top) - tStack_40.bottom) - Y) + tStack_40.top;
        if (iVar2 != tStack_20.bottom - tStack_20.top) {
          SetWindowPos(*(HWND *)(param_1 + 0x48),(HWND)0x0,0,Y,local_30.right - local_30.left,iVar2,
                       4);
        }
      }
    }
  }
  else if (((((*param_3 == *(int *)(param_1 + 0x9c)) && (param_3[2] == -0x2c6)) &&
            (0xfff < param_3[3])) &&
           ((param_3[3] < 0x1200 &&
            (puVar1 = *(undefined4 **)(param_1 + 0x28), puVar1 != (undefined4 *)0x0)))) &&
          (iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00012100,local_48), -1 < iVar2)) {
    (**(code **)(*local_48[0] + 0x10))(local_48[0],&UNK_00011f5c,param_3[3],0,0,0);
    (**(code **)(*local_48[0] + 8))();
  }
  return 0;
}



/* 00018678 FUN_00018678 */

/* Boundary evidence: original MIPS .pdata 00018678..0001877b. Semantic name remains unreviewed. */

void FUN_00018678(int param_1,WPARAM param_2,LPARAM param_3)

{
  int iVar1;
  HWND local_28;
  int *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  if ((param_2 == 0x2f) && ((*(byte *)(param_1 + 0x6c) & 2) != 0)) {
    SystemParametersInfoW(0x30,0,&local_20,0);
    SetWindowPos(*(HWND *)(param_1 + 0x4c),(HWND)0x0,local_20,local_1c,local_18 - local_20,
                 local_14 - local_1c,4);
  }
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x34))
                    (*(undefined4 **)(param_1 + 0x34),&UNK_00012110,&local_24);
  if (-1 < iVar1) {
    local_28 = (HWND)0x0;
    iVar1 = (**(code **)(*local_24 + 0xc))(local_24,&local_28);
    if (-1 < iVar1) {
      SendMessageW(local_28,0x1a,param_2,param_3);
    }
    (**(code **)(*local_24 + 8))();
  }
  return;
}



/* 0001877c FUN_0001877c */

/* Boundary evidence: original MIPS .pdata 0001877c..000188cf. Semantic name remains unreviewed. */

undefined4 FUN_0001877c(int *param_1)

{
  byte bVar1;
  uint uVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  uVar2 = GetWindowLongW((HWND)param_1[0x13],-0x10);
  if ((*(byte *)(param_1 + 0x1b) & 2) == 0) {
    SystemParametersInfoW(0x30,0,&local_20,0);
    SetWindowLongW((HWND)param_1[0x13],-0x10,uVar2 & 0xff33ffff);
    SetWindowPos((HWND)param_1[0x13],(HWND)0x0,local_20,local_1c,local_18 - local_20,
                 local_14 - local_1c,4);
  }
  else {
    SetWindowLongW((HWND)param_1[0x13],-0x10,uVar2 | 0xcc0000);
    SetWindowPos((HWND)param_1[0x13],(HWND)0x0,param_1[0x14],param_1[0x15],
                 param_1[0x16] - param_1[0x14],param_1[0x17] - param_1[0x15],4);
  }
  bVar1 = *(byte *)(param_1 + 0x1b);
  *(byte *)(param_1 + 0x1b) = (((bVar1 & 2) == 0) << 1 ^ bVar1) & 2 ^ bVar1;
  if (param_1[0x24] == 0) {
    (**(code **)(*param_1 + 0x38))();
  }
  else {
    FUN_000175e0((int)param_1);
  }
  return 0;
}



/* 000188d0 FUN_000188d0 */

/* Boundary evidence: original MIPS .pdata 000188d0..000189ab. Semantic name remains unreviewed. */

int FUN_000188d0(int param_1,LPMSG param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  HWND local_18 [2];
  
  if (param_2->hwnd == *(HWND *)(param_1 + 0xa8)) {
    if ((((param_2->message != 0x100) || (param_2->wParam != 9)) ||
        (piVar3 = *(int **)(param_1 + 0x3c), piVar3 == (int *)0x0)) ||
       (iVar1 = (**(code **)(*piVar3 + 0xc))(piVar3,local_18), iVar1 != 0)) {
      return 0;
    }
    SetFocus(local_18[0]);
  }
  piVar3 = *(int **)(param_1 + 0x3c);
  if (((piVar3 == (int *)0x0) || (iVar1 = (**(code **)(*piVar3 + 0x14))(piVar3,param_2), iVar1 < 0))
     || (iVar2 = 1, iVar1 == 1)) {
    iVar2 = TranslateAcceleratorW(*(HWND *)(param_1 + 0x4c),*(HACCEL *)(param_1 + 0x78),param_2);
  }
  return iVar2;
}



/* 000189ac FUN_000189ac */

/* Boundary evidence: original MIPS .pdata 000189ac..00018a7f. Semantic name remains unreviewed. */

void FUN_000189ac(int param_1,int param_2)

{
  HMENU hmenu;
  int *piVar1;
  undefined2 local_18 [4];
  undefined4 local_10;
  
  piVar1 = *(int **)(param_1 + 0x28);
  local_18[0] = 3;
  if (param_2 == 0) {
    local_10 = *(undefined4 *)(param_1 + 0x1148);
    (**(code **)(*piVar1 + 0xd8))(piVar1,0x13,2,local_18,0);
  }
  else {
    local_18[0] = 0;
    (**(code **)(*piVar1 + 0xd8))(piVar1,0x13,2,0,local_18);
    *(undefined4 *)(param_1 + 0x1148) = local_10;
  }
  hmenu = (HMENU)CommandBar_GetMenu(*(undefined4 *)(param_1 + 0x94),0);
  CheckMenuRadioItem(hmenu,0xa002,0xa006,*(int *)(param_1 + 0x1148) + 0xa002,0);
  if ((*(byte *)(param_1 + 300) & 8) != 0) {
    CommandBar_DrawMenuBar(*(undefined4 *)(param_1 + 0x94),0);
  }
  return;
}



/* 00018a80 FUN_00018a80 */

/* Boundary evidence: original MIPS .pdata 00018a80..00018cff. Semantic name remains unreviewed. */

undefined4 FUN_00018a80(int param_1,wchar_t *param_2)

{
  int iVar1;
  LSTATUS LVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  LPBYTE lpData;
  DWORD local_68;
  HKEY local_64;
  HKEY local_60;
  undefined4 local_5c;
  wchar_t awStack_58 [20];
  uint local_30;
  
  local_30 = DAT_00035518;
  uVar5 = 0;
  local_60 = (HKEY)0x0;
  iVar1 = wcscmp(param_2,L"IE");
  iVar4 = 3;
  puVar3 = (undefined4 *)(((iVar1 != 0) + 3) * 0x3c + param_1);
  do {
    *puVar3 = 0x14;
    puVar3[1] = 0x17;
    iVar4 = iVar4 + -1;
    puVar3 = puVar3 + 5;
  } while (iVar4 != 0);
  LVar2 = RegOpenKeyExW((HKEY)0x80000001,
                        L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CmdBands",0,0,
                        &local_60);
  if (LVar2 == 0) {
    uVar5 = 1;
    iVar4 = 0;
    lpData = (LPBYTE)((uint)(iVar1 != 0) * 0x3c + param_1 + 0xc0);
    do {
      StringCchPrintfExW(awStack_58,0x14,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,L"%sBand%d",
                         param_2,iVar4);
      LVar2 = RegOpenKeyExW(local_60,awStack_58,0,0,&local_64);
      if (LVar2 == 0) {
        local_68 = 4;
        RegQueryValueExW(local_64,L"ID",(LPDWORD)0x0,(LPDWORD)0x0,lpData + -8,&local_68);
        local_68 = 4;
        RegQueryValueExW(local_64,L"Break",(LPDWORD)0x0,(LPDWORD)0x0,lpData + -4,&local_68);
        local_68 = 4;
        RegQueryValueExW(local_64,L"Width",(LPDWORD)0x0,(LPDWORD)0x0,lpData,&local_68);
        local_68 = 4;
        RegQueryValueExW(local_64,L"Max",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_5c,&local_68);
        *(undefined4 *)(lpData + 4) = local_5c;
        RegCloseKey(local_64);
      }
      else {
        uVar5 = 0;
      }
      iVar4 = iVar4 + 1;
      lpData = lpData + 0x14;
    } while (iVar4 < 3);
    RegCloseKey(local_60);
  }
  FUN_00033770(local_30);
  return uVar5;
}



/* 00018d00 FUN_00018d00 */

/* Boundary evidence: original MIPS .pdata 00018d00..0001908b. Semantic name remains unreviewed. */

undefined4 FUN_00018d00(int param_1,wchar_t *param_2,int param_3)

{
  int iVar1;
  LSTATUS LVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  HKEY local_70;
  HKEY local_6c;
  uint local_68;
  wchar_t *local_64;
  DWORD aDStack_60 [2];
  wchar_t awStack_58 [20];
  uint local_30;
  
  local_30 = DAT_00035518;
  uVar6 = 0;
  local_6c = (HKEY)0x0;
  iVar1 = wcscmp(param_2,L"IE");
  uVar5 = (uint)(iVar1 != 0);
  if (param_3 == 0) {
    if (*(int *)(param_1 + 0x90) != 0) {
      uVar6 = 1;
      iVar1 = 0;
      iVar4 = 0;
      do {
        if (2 < iVar1) break;
        iVar3 = CommandBands_GetRestoreInformation
                          (*(undefined4 *)(param_1 + 0x90),iVar4,
                           ((uVar5 + 3) * 3 + iVar1) * 0x14 + param_1);
        if (iVar3 == 0) {
          iVar3 = (uVar5 * 3 + iVar1) * 0x14 + param_1;
          *(undefined4 *)(iVar3 + 0xb8) = 0x17;
          *(undefined4 *)(iVar3 + 0xbc) = 0;
          *(undefined4 *)(iVar3 + 0xc0) = 0;
          *(undefined4 *)(iVar3 + 0xc4) = 0;
        }
        if (*(int *)((uVar5 * 3 + iVar1) * 0x14 + param_1 + 0xb8) != -1) {
          iVar1 = iVar1 + 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
    }
  }
  else {
    LVar2 = RegCreateKeyExW((HKEY)0x80000001,
                            L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\CmdBands",0,
                            (LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_6c,aDStack_60);
    if (LVar2 == 0) {
      uVar6 = 1;
      iVar1 = 0;
      local_64 = L"%sBand%d";
      do {
        local_70 = (HKEY)0x0;
        StringCchPrintfExW(awStack_58,0x14,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x100,local_64,
                           param_2,iVar1);
        LVar2 = RegCreateKeyExW(local_6c,awStack_58,0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,
                                &local_70,aDStack_60);
        if (LVar2 == 0) {
          iVar4 = (uVar5 * 3 + iVar1) * 0x14 + param_1;
          RegSetValueExW(local_70,L"ID",0,4,(BYTE *)(iVar4 + 0xb8),4);
          RegSetValueExW(local_70,L"Break",0,4,(BYTE *)(iVar4 + 0xbc),4);
          RegSetValueExW(local_70,L"Width",0,4,(BYTE *)(iVar4 + 0xc0),4);
          local_68 = (uint)(*(int *)(iVar4 + 0xc4) != 0);
          RegSetValueExW(local_70,L"Max",0,4,(BYTE *)&local_68,4);
          RegCloseKey(local_70);
        }
        else {
          uVar6 = 0;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 3);
      RegCloseKey(local_6c);
    }
  }
  FUN_00033770(local_30);
  return uVar6;
}



/* 0001908c FUN_0001908c */

/* Boundary evidence: original MIPS .pdata 0001908c..00019203. Semantic name remains unreviewed. */

void FUN_0001908c(int param_1)

{
  LPBYTE lpData;
  LSTATUS LVar1;
  int iVar2;
  DWORD dwIndex;
  HKEY local_48;
  DWORD local_44;
  DWORD local_40;
  DWORD local_3c;
  WCHAR aWStack_38 [10];
  uint local_24;
  
  local_24 = DAT_00035518;
  dwIndex = 0;
  local_3c = 0;
  local_48 = (HKEY)0x0;
  lpData = LocalAlloc(0,0x1018);
  if (lpData != (LPBYTE)0x0) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"Software\\Microsoft\\Internet Explorer\\TypedURLs",0,0,
                          &local_48);
    if ((local_48 != (HKEY)0x0) && (LVar1 == 0)) {
      local_44 = 10;
      local_40 = 0x1018;
      iVar2 = RegEnumValueW(local_48,0,aWStack_38,&local_44,(LPDWORD)0x0,&local_3c,lpData,&local_40)
      ;
      while (iVar2 == 0) {
        dwIndex = dwIndex + 1;
        SendMessageW(*(HWND *)(param_1 + 0xa4),0x14a,0,(LPARAM)lpData);
        local_44 = 10;
        local_40 = 0x1018;
        iVar2 = RegEnumValueW(local_48,dwIndex,aWStack_38,&local_44,(LPDWORD)0x0,&local_3c,lpData,
                              &local_40);
      }
      RegCloseKey(local_48);
    }
    LocalFree(lpData);
  }
  FUN_00033770(local_24);
  return;
}



/* 00019204 FUN_00019204 */

/* Boundary evidence: original MIPS .pdata 00019204..000193e3. Semantic name remains unreviewed. */

void FUN_00019204(int param_1)

{
  LSTATUS LVar1;
  LRESULT LVar2;
  LRESULT LVar3;
  size_t sVar4;
  wchar_t *_Str;
  int iVar5;
  WPARAM wParam;
  HKEY local_48;
  DWORD DStack_44;
  wchar_t awStack_40 [8];
  uint local_30;
  
  local_30 = DAT_00035518;
  _Str = (wchar_t *)0x0;
  iVar5 = 0;
  local_48 = (HKEY)0x0;
  LVar1 = RegCreateKeyExW((HKEY)0x80000001,L"Software\\Microsoft\\Internet Explorer\\TypedURLs",0,
                          (LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_48,&DStack_44);
  if ((local_48 != (HKEY)0x0) && (LVar1 == 0)) {
    LVar2 = SendMessageW(*(HWND *)(param_1 + 0xa4),0x146,0,0);
    wParam = 0;
    if (0 < LVar2) {
      do {
        LVar3 = SendMessageW(*(HWND *)(param_1 + 0xa4),0x149,wParam,0);
        if (LVar3 == -1) break;
        if (iVar5 < LVar3) {
          if (_Str != (wchar_t *)0x0) {
            LocalFree(_Str);
          }
          _Str = LocalAlloc(0,(LVar3 + 1) * 2);
          iVar5 = LVar3;
        }
        if (_Str == (wchar_t *)0x0) break;
        SendMessageW(*(HWND *)(param_1 + 0xa4),0x148,wParam,(LPARAM)_Str);
        wParam = wParam + 1;
        StringCbPrintfW(awStack_40,0xe,L"url%d",wParam);
        sVar4 = wcslen(_Str);
        RegSetValueExW(local_48,awStack_40,0,1,(BYTE *)_Str,(sVar4 + 1) * 2);
      } while ((int)wParam < LVar2);
    }
    RegCloseKey(local_48);
    if (_Str != (wchar_t *)0x0) {
      LocalFree(_Str);
    }
  }
  FUN_00033770(local_30);
  return;
}



/* 000193e4 FUN_000193e4 */

/* Boundary evidence: original MIPS .pdata 000193e4..0001949b. Semantic name remains unreviewed. */

void FUN_000193e4(int param_1,LPARAM param_2)

{
  WPARAM wParam;
  LRESULT LVar1;
  HWND hWnd;
  
  wParam = SendMessageW(*(HWND *)(param_1 + 0xa4),0x158,0xffffffff,param_2);
  hWnd = *(HWND *)(param_1 + 0xa4);
  if (wParam == 0xffffffff) {
    SendMessageW(hWnd,0x14a,0,param_2);
    hWnd = *(HWND *)(param_1 + 0xa4);
    wParam = 0;
  }
  SendMessageW(hWnd,0x14e,wParam,0);
  LVar1 = SendMessageW(*(HWND *)(param_1 + 0xa4),0x146,0,0);
  if (0x19 < LVar1) {
    SendMessageW(*(HWND *)(param_1 + 0xa4),0x144,0x18,0);
  }
  return;
}



/* 0001949c FUN_0001949c */

/* Boundary evidence: original MIPS .pdata 0001949c..0001951b. Semantic name remains unreviewed. */

void FUN_0001949c(int param_1)

{
  int *piVar1;
  wchar_t *local_10 [2];
  
  piVar1 = *(int **)(param_1 + 0x28);
  local_10[0] = (wchar_t *)0x0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x74))(piVar1,local_10);
    if (local_10[0] != (wchar_t *)0x0) {
      FUN_00015ecc(*(int *)(param_1 + 0x4c),local_10[0]);
      if (*(HWND *)(param_1 + 0xa4) != (HWND)0x0) {
        SendMessageW(*(HWND *)(param_1 + 0xa4),0xc,0,(LPARAM)local_10[0]);
      }
      SysFreeString(local_10[0]);
    }
  }
  return;
}



/* 0001951c FUN_0001951c */

/* Boundary evidence: original MIPS .pdata 0001951c..00019797. Semantic name remains unreviewed. */

LRESULT FUN_0001951c(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  undefined1 *puVar1;
  wchar_t wVar2;
  LONG LVar3;
  int iVar4;
  LPWSTR lpString;
  uint uVar5;
  LRESULT LVar6;
  wchar_t *pwVar7;
  byte bVar8;
  uint local_270 [2];
  undefined4 local_268;
  undefined1 auStack_264 [8];
  undefined1 auStack_25c [4];
  wchar_t *local_258;
  undefined1 auStack_254 [4];
  undefined1 auStack_250 [4];
  undefined1 auStack_24c [36];
  undefined4 local_228;
  wchar_t local_224;
  undefined1 auStack_222 [514];
  uint local_20;
  
  local_20 = DAT_00035518;
  LVar3 = GetWindowLongW(param_1,-0x15);
  local_228 = 0x3a003a;
  local_224 = L'\0';
  memset(auStack_222,0,0x202);
  local_270[0] = 0x102;
  if (LVar3 == 0) goto LAB_0001959c;
  if ((param_2 != 0x102) || (param_3 != 0xd)) {
    LVar6 = CallWindowProcW(*(WNDPROC *)(LVar3 + 0x60),param_1,param_2,param_3,param_4);
    FUN_00033770(local_20);
    return LVar6;
  }
  iVar4 = GetWindowTextLengthW(param_1);
  if ((iVar4 == 0) || (lpString = LocalAlloc(0,(iVar4 + 1) * 2), lpString == (LPWSTR)0x0))
  goto LAB_0001959c;
  GetWindowTextW(param_1,lpString,iVar4 + 1);
  wVar2 = *lpString;
  pwVar7 = lpString;
  while (wVar2 == L' ') {
    pwVar7 = pwVar7 + 1;
    wVar2 = *pwVar7;
  }
  iVar4 = FUN_00014ff4(pwVar7,&local_224,local_270);
  bVar8 = 1;
  if (iVar4 == 0) {
    if ((DAT_00035524 == 0) && (uVar5 = FUN_000158ec(pwVar7), uVar5 == 0)) {
      memset(auStack_264,0,0x38);
      local_258 = L"explorer.exe";
      local_268 = 0x3c;
      puVar1 = auStack_264 + 3;
      uVar5 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar5) =
           *(uint *)(puVar1 + -uVar5) & -1 << (uVar5 + 1) * 8 | 0U >> (3 - uVar5) * 8;
      puVar1 = auStack_25c + 3;
      uVar5 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar5) =
           *(uint *)(puVar1 + -uVar5) & -1 << (uVar5 + 1) * 8 | 0U >> (3 - uVar5) * 8;
      puVar1 = auStack_254 + 3;
      uVar5 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar5) =
           *(uint *)(puVar1 + -uVar5) & -1 << (uVar5 + 1) * 8 | (uint)pwVar7 >> (3 - uVar5) * 8;
      puVar1 = auStack_250 + 3;
      uVar5 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar5) =
           *(uint *)(puVar1 + -uVar5) & -1 << (uVar5 + 1) * 8 | 0U >> (3 - uVar5) * 8;
      puVar1 = auStack_24c + 3;
      uVar5 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar5) =
           *(uint *)(puVar1 + -uVar5) & -1 << (uVar5 + 1) * 8 | 1U >> (3 - uVar5) * 8;
      auStack_264._0_4_ = 0;
      auStack_25c = (undefined1  [4])0x0;
      auStack_250 = (undefined1  [4])0x0;
      auStack_24c._0_4_ = 1;
      auStack_254 = (undefined1  [4])pwVar7;
      iVar4 = ShellExecuteEx(&local_268);
      if (iVar4 != 0) {
        FUN_0001949c(LVar3);
        bVar8 = 0;
        goto LAB_00019728;
      }
    }
    (**(code **)(**(int **)(LVar3 + 0x28) + 0x2c))(*(int **)(LVar3 + 0x28),pwVar7,0,0,0,0);
  }
  else {
    (**(code **)(**(int **)(LVar3 + 0x28) + 0x2c))(*(int **)(LVar3 + 0x28),&local_228,0,0,0,0);
  }
LAB_00019728:
  *(byte *)(LVar3 + 300) = (bVar8 ^ *(byte *)(LVar3 + 300)) & 1 ^ *(byte *)(LVar3 + 300);
  LocalFree(lpString);
LAB_0001959c:
  FUN_00033770(local_20);
  return 0;
}



/* 00019798 FUN_00019798 */

/* Boundary evidence: original MIPS .pdata 00019798..000198df. Semantic name remains unreviewed. */

undefined4 FUN_00019798(HWND param_1,wchar_t *param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  size_t sVar5;
  BOOL BVar6;
  WCHAR *pWVar7;
  undefined4 uVar8;
  tagOFNW atStack_490 [7];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_00035518;
  uVar8 = 0;
  memset(atStack_490,0,0x4c);
  puVar1 = (undefined1 *)((int)&atStack_490[0].lStructSize + 3);
  uVar2 = (uint)puVar1 & 3;
  puVar3 = (uint *)(puVar1 + -uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0x4cU >> (3 - uVar2) * 8;
  puVar1 = (undefined1 *)((int)&atStack_490[0].hwndOwner + 3);
  uVar2 = (uint)puVar1 & 3;
  puVar3 = (uint *)(puVar1 + -uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | (uint)param_1 >> (3 - uVar2) * 8;
  puVar1 = (undefined1 *)((int)&atStack_490[0].Flags + 3);
  uVar2 = (uint)puVar1 & 3;
  puVar3 = (uint *)(puVar1 + -uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0x1806U >> (3 - uVar2) * 8;
  atStack_490[0].lStructSize = 0x4c;
  atStack_490[0].Flags = 0x1806;
  atStack_490[0].hwndOwner = param_1;
  iVar4 = LoadStringW(DAT_00035560,0x4e2a,aWStack_228,0x102);
  if (0 < iVar4) {
    pWVar7 = aWStack_228 + iVar4;
    do {
      if (*pWVar7 == L'@') {
        *pWVar7 = L'\0';
      }
      iVar4 = iVar4 + -1;
      pWVar7 = pWVar7 + -1;
    } while (-1 < iVar4);
    atStack_490[0].lpstrFilter = aWStack_228;
    atStack_490[0].nFilterIndex = 1;
    wcscpy((wchar_t *)&atStack_490[0].dwReserved,L"file://");
    sVar5 = wcslen((wchar_t *)&atStack_490[0].dwReserved);
    atStack_490[0].lpstrFile = (LPWSTR)((int)&atStack_490[0].dwReserved + sVar5 * 2);
    atStack_490[0].nMaxFile = 0x104;
    BVar6 = GetOpenFileNameW(atStack_490);
    if (BVar6 != 0) {
      wcsncpy(param_2,(wchar_t *)&atStack_490[0].dwReserved,0x80b);
      uVar8 = 1;
    }
  }
  FUN_00033770(local_20);
  return uVar8;
}



/* 000198e0 FUN_000198e0 */

/* Boundary evidence: original MIPS .pdata 000198e0..00019a03. Semantic name remains unreviewed. */

void FUN_000198e0(void)

{
  HLOCAL pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  UINT *pUVar5;
  
  if ((DAT_000355cc == 0) && (pvVar1 = LocalAlloc(0,0x47c), pvVar1 != (HLOCAL)0x0)) {
    iVar2 = 0;
    iVar3 = 0;
    iVar4 = 0;
    pUVar5 = &DAT_00011f78;
    DAT_000355d0 = pvVar1;
    do {
      *(HLOCAL *)(iVar3 + (int)DAT_000355d0) = (HLOCAL)((iVar4 + 7) * 4 + (int)pvVar1);
      LoadStringW(DAT_00035560,*pUVar5,*(LPWSTR *)(iVar3 + (int)DAT_000355d0),0x50);
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x28;
      iVar3 = iVar3 + 4;
      pUVar5 = pUVar5 + 5;
    } while (iVar2 < 7);
  }
  DAT_000355cc = DAT_000355cc + 1;
  return;
}



/* 00019a04 FUN_00019a04 */

/* Boundary evidence: original MIPS .pdata 00019a04..00019a53. Semantic name remains unreviewed. */

int FUN_00019a04(void)

{
  DAT_000355cc = DAT_000355cc + -1;
  if (DAT_000355cc == 0) {
    LocalFree(DAT_000355d0);
    DAT_000355d0 = (HLOCAL)0x0;
  }
  return DAT_000355cc;
}



/* 00019c98 FUN_00019c98 */

/* Boundary evidence: original MIPS .pdata 00019c98..00019ce3. Semantic name remains unreviewed. */

undefined4 * FUN_00019c98(undefined4 *param_1,uint param_2)

{
  FUN_00017084(param_1);
  if ((param_2 & 1) != 0) {
    LocalFree(param_1);
  }
  return param_1;
}



/* 00019ce4 FUN_00019ce4 */

/* Boundary evidence: original MIPS .pdata 00019ce4..00019ed7. Semantic name remains unreviewed. */

undefined4 FUN_00019ce4(int *param_1)

{
  HACCEL pHVar1;
  undefined2 *puVar2;
  LSTATUS LVar3;
  DWORD DVar4;
  undefined4 uVar5;
  uint uVar6;
  HKEY local_20;
  DWORD local_1c;
  int local_18 [2];
  
  pHVar1 = LoadAcceleratorsW(DAT_00035560,(LPCWSTR)0xc9);
  param_1[0x1e] = (int)pHVar1;
  puVar2 = operator_new(8);
  if (puVar2 == (undefined2 *)0x0) {
    puVar2 = (undefined2 *)0x0;
  }
  else {
    *(undefined4 *)(puVar2 + 2) = 0;
    *puVar2 = 0xa0ff;
    puVar2[1] = 0xa1c9;
  }
  param_1[0x1f] = (int)puVar2;
  FUN_000162dc();
  FUN_0001644c(0,param_1 + 0x1d,0);
  FUN_000198e0();
  FUN_00018a80((int)param_1,L"IE");
  FUN_00018a80((int)param_1,L"SH");
  local_20 = (HKEY)0x0;
  LVar3 = RegOpenKeyExW((HKEY)0x80000001,
                        L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StatusBar",0,0,
                        &local_20);
  if (LVar3 == 0) {
    local_1c = 4;
    LVar3 = RegQueryValueExW(local_20,L"ShowStatusBar",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_18,
                             &local_1c);
    if (LVar3 == 0) {
      *(byte *)(param_1 + 0x4b) =
           ((local_18[0] != 0) << 5 ^ *(byte *)(param_1 + 0x4b)) & 0x20 ^ *(byte *)(param_1 + 0x4b);
    }
    RegCloseKey(local_20);
  }
  DVar4 = GetFileAttributesW(L"\\Windows\\peghelp.exe");
  *(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) & 0x7f | (DVar4 != 0xffffffff) << 7;
  *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) | 2;
  uVar5 = FUN_0001d51c(param_1,0x10030000);
  if ((*(byte *)(param_1 + 0x4b) & 0x80) != 0) {
    uVar6 = GetWindowLongW((HWND)param_1[0x13],-0x14);
    SetWindowLongW((HWND)param_1[0x13],-0x14,uVar6 | 0x400);
  }
  return uVar5;
}



/* 00019ed8 FUN_00019ed8 */

/* Boundary evidence: original MIPS .pdata 00019ed8..0001a067. Semantic name remains unreviewed. */

undefined4 FUN_00019ed8(int param_1)

{
  HWND pHVar1;
  undefined4 uVar2;
  tagRECT tStack_38;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  uVar2 = 0;
  pHVar1 = CreateStatusWindowW(0x50000000,L"Ready",*(HWND *)(param_1 + 0x4c),0x1a);
  *(HWND *)(param_1 + 0xa0) = pHVar1;
  if (pHVar1 != (HWND)0x0) {
    GetClientRect(pHVar1,&tStack_38);
    local_18 = tStack_38.right;
    local_1c = 0;
    if (-1 < tStack_38.right + -0x6e) {
      local_1c = tStack_38.right + -0x6e;
    }
    local_20 = 0;
    if (-1 < tStack_38.right + -0x82) {
      local_20 = tStack_38.right + -0x82;
    }
    local_24 = 0;
    if (-1 < tStack_38.right + -0xa0) {
      local_24 = tStack_38.right + -0xa0;
    }
    local_28 = 0;
    if (-1 < tStack_38.right + -0x104) {
      local_28 = tStack_38.right + -0x104;
    }
    SendMessageW(*(HWND *)(param_1 + 0xa0),0x404,5,(LPARAM)&local_28);
    SendMessageW(*(HWND *)(param_1 + 0xa0),0x40a,1,(LPARAM)&tStack_38);
    InflateRect(&tStack_38,-1,-1);
    pHVar1 = CreateWindowExW(0,L"msctls_progress32",L"",0x50000001,local_28,tStack_38.top,100,
                             tStack_38.bottom - tStack_38.top,*(HWND *)(param_1 + 0xa0),(HMENU)0x0,
                             DAT_00035560,(LPVOID)0x0);
    *(HWND *)(param_1 + 0xac) = pHVar1;
    if (pHVar1 != (HWND)0x0) {
      SendMessageW(pHVar1,0x401,0,0x640000);
      if ((*(byte *)(param_1 + 300) & 0x20) == 0) {
        *(byte *)(param_1 + 300) = *(byte *)(param_1 + 300) | 0x20;
        FUN_0001752c(param_1,0);
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 0001a068 FUN_0001a068 */

/* Boundary evidence: original MIPS .pdata 0001a068..0001a2a3. Semantic name remains unreviewed. */

undefined4 FUN_0001a068(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  HWND pHVar2;
  LONG LVar3;
  int iVar4;
  undefined4 uVar5;
  DWORD dwExStyle;
  tagRECT tStack_d8;
  undefined4 local_c8;
  undefined4 local_c4;
  uint local_c0;
  WCHAR *local_b4;
  undefined4 local_ac;
  HWND local_a8;
  undefined4 local_a4;
  int local_a0;
  int local_9c;
  undefined4 local_94;
  WCHAR aWStack_78 [40];
  uint local_28;
  
  local_28 = DAT_00035518;
  uVar5 = 1;
  dwExStyle = 0;
  uVar1 = GetWindowLongW(*(HWND *)(param_1 + 0x4c),-0x14);
  if ((uVar1 & 0x400000) != 0) {
    dwExStyle = 0x2000;
  }
  pHVar2 = CreateWindowExW(dwExStyle,L"combobox",L"",0x50010040,0,0,0x14,0x6e,
                           *(HWND *)(param_1 + 0x4c),(HMENU)0x18,DAT_00035560,(LPVOID)0x0);
  *(HWND *)(param_1 + 0xa4) = pHVar2;
  if (pHVar2 != (HWND)0x0) {
    FUN_0001908c(param_1);
    pHVar2 = GetDlgItem(*(HWND *)(param_1 + 0xa4),0x3e9);
    *(HWND *)(param_1 + 0xa8) = pHVar2;
    if (pHVar2 != (HWND)0x0) {
      SetWindowLongW(pHVar2,-0x15,param_1);
      LVar3 = SetWindowLongW(*(HWND *)(param_1 + 0xa8),-4,0x1951c);
      *(LONG *)(param_1 + 0x60) = LVar3;
      SendMessageW(*(HWND *)(param_1 + 0xa8),0xc5,0x80b,0);
    }
  }
  GetWindowRect(*(HWND *)(param_1 + 0xa4),&tStack_d8);
  LoadStringW(DAT_00035560,0x4e21,aWStack_78,0x28);
  local_c4 = 0x13d;
  local_94 = 0x16;
  local_a0 = tStack_d8.bottom - tStack_d8.top;
  local_c8 = 0x4c;
  local_a8 = *(HWND *)(param_1 + 0xa4);
  local_b4 = aWStack_78;
  local_a4 = 0;
  local_ac = 2;
  if (param_3 == -1) {
    param_2 = 1;
  }
  else {
    local_c4 = 0x17d;
    local_9c = param_3;
  }
  if ((*(byte *)(param_1 + 300) & 0x10) == 0) {
    local_c0 = param_2 | 8;
  }
  else {
    local_c0 = param_2 & 0xfffffff7;
  }
  FUN_0001e874(local_a8);
  iVar4 = CommandBands_AddBands(*(undefined4 *)(param_1 + 0x90),DAT_00035560,1,&local_c8);
  if (iVar4 == 0) {
    uVar5 = 0;
    if (*(HWND *)(param_1 + 0xa4) != (HWND)0x0) {
      DestroyWindow(*(HWND *)(param_1 + 0xa4));
      *(undefined4 *)(param_1 + 0xa4) = 0;
    }
  }
  FUN_00033770(local_28);
  return uVar5;
}



/* 0001a2a4 FUN_0001a2a4 */

/* Boundary evidence: original MIPS .pdata 0001a2a4..0001a567. Semantic name remains unreviewed. */

undefined4 FUN_0001a2a4(int param_1,HMENU param_2,int *param_3)

{
  HMENU pHVar1;
  BOOL BVar2;
  HMENU uIDNewItem;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00035518;
  uVar3 = 0x80004005;
  if ((param_2 == (HMENU)0x0) || (param_3 == (int *)0x0)) {
    uVar3 = 0x80070057;
    goto LAB_0001a530;
  }
  iVar5 = param_1 + -0x24;
  pHVar1 = FUN_0001821c(iVar5,(UINT *)&DAT_000117c4,1,param_3);
  if (pHVar1 != (HMENU)0x0) {
    LoadStringW(DAT_00035560,22000,aWStack_238,0x104);
    BVar2 = AppendMenuW(param_2,0x10,(UINT_PTR)pHVar1,aWStack_238);
    if (BVar2 == 0) {
      DestroyMenu(pHVar1);
      *param_3 = 0;
      goto LAB_0001a530;
    }
  }
  pHVar1 = CreatePopupMenu();
  if (pHVar1 != (HMENU)0x0) {
    LoadStringW(DAT_00035560,0x5622,aWStack_238,0x104);
    BVar2 = AppendMenuW(param_2,0x10,(UINT_PTR)pHVar1,aWStack_238);
    if (BVar2 == 0) {
      DestroyMenu(pHVar1);
      goto LAB_0001a530;
    }
  }
  piVar4 = param_3 + 2;
  pHVar1 = FUN_0001821c(iVar5,(UINT *)&DAT_000117d0,4,piVar4);
  if (pHVar1 == (HMENU)0x0) {
LAB_0001a408:
    piVar4 = param_3 + 3;
    pHVar1 = FUN_0001821c(iVar5,(UINT *)&DAT_00011800,2,piVar4);
    if (pHVar1 != (HMENU)0x0) {
      LoadStringW(DAT_00035560,0x5686,aWStack_238,0x104);
      BVar2 = AppendMenuW(param_2,0x10,(UINT_PTR)pHVar1,aWStack_238);
      if (BVar2 == 0) goto LAB_0001a510;
    }
    piVar4 = param_3 + 4;
    uIDNewItem = FUN_0001821c(iVar5,(UINT *)&DAT_00011818,1,piVar4);
    if (uIDNewItem != (HMENU)0x0) {
      LoadStringW(DAT_00035560,0x56b8,aWStack_238,0x104);
      if ((DAT_00035568 == 0) || (pHVar1 == (HMENU)0x0)) {
        iVar5 = AppendMenuW(param_2,0x10,(UINT_PTR)uIDNewItem,aWStack_238);
      }
      else {
        InsertMenuW(pHVar1,0,0xc00,0,(LPCWSTR)0x0);
        iVar5 = InsertMenuW(pHVar1,0,0x410,(UINT_PTR)uIDNewItem,aWStack_238);
      }
      pHVar1 = uIDNewItem;
      if (iVar5 == 0) goto LAB_0001a510;
    }
    uVar3 = 0;
  }
  else {
    LoadStringW(DAT_00035560,0x5654,aWStack_238,0x104);
    BVar2 = AppendMenuW(param_2,0x10,(UINT_PTR)pHVar1,aWStack_238);
    if (BVar2 != 0) goto LAB_0001a408;
LAB_0001a510:
    DestroyMenu(pHVar1);
    *piVar4 = 0;
  }
LAB_0001a530:
  FUN_00033770(local_30);
  return uVar3;
}



/* 0001a568 FUN_0001a568 */

/* Boundary evidence: original MIPS .pdata 0001a568..0001a5fb. Semantic name remains unreviewed. */

undefined4 FUN_0001a568(int param_1,HMENU param_2)

{
  HMENU hMenu;
  int *piVar1;
  
  piVar1 = (int *)(param_1 + -0x24);
  FUN_00018d00((int)piVar1,L"SH",0);
  while (hMenu = GetSubMenu(param_2,0), hMenu != (HMENU)0x0) {
    RemoveMenu(param_2,0,0x400);
    DestroyMenu(hMenu);
  }
  (**(code **)(*piVar1 + 0x38))(piVar1);
  return 0;
}



/* 0001a5fc FUN_0001a5fc */

/* Boundary evidence: original MIPS .pdata 0001a5fc..0001a81b. Semantic name remains unreviewed. */

undefined4 FUN_0001a5fc(int param_1,int param_2)

{
  HWND pHVar1;
  LRESULT LVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  tagRECT local_80;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_3c;
  
  uVar6 = 0x80004005;
  if (param_2 != 0) {
    FUN_00018d00(param_1 + -0x24,L"IE",0);
    if (*(int *)(param_1 + 0x70) != 0) {
      SendMessageW(*(HWND *)(param_1 + 0x6c),0x402,0,0);
      DestroyWindow(*(HWND *)(param_1 + 0x70));
    }
    iVar5 = 0;
    piVar4 = (int *)(param_1 + 0xd0);
    do {
      if (*piVar4 == 0x14) break;
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 5;
    } while (iVar5 < 3);
    pHVar1 = CreateWindowExW(0,L"ToolbarWindow32",(LPCWSTR)0x0,0x50001104,0,0,0,0,
                             *(HWND *)(param_1 + 0x6c),(HMENU)0x0,DAT_00035560,(LPVOID)0x0);
    *(HWND *)(param_1 + 0x70) = pHVar1;
    if (pHVar1 != (HWND)0x0) {
      SendMessageW(pHVar1,0x41e,0x14,0);
      local_6c = 0x139;
      local_50 = *(undefined4 *)(param_1 + 0x70);
      local_70 = 0x4c;
      local_68 = 0x100;
      local_4c = 0;
      local_48 = 0x18;
      local_3c = 0x14;
      local_54 = 1;
      if (iVar5 != 3) {
        local_6c = 0x179;
        local_44 = *(undefined4 *)(iVar5 * 0x14 + param_1 + 0xd8);
      }
      LVar2 = SendMessageW(*(HWND *)(param_1 + 0x6c),0x40a,0,(LPARAM)&local_70);
      if ((LVar2 != 0) &&
         (iVar3 = CommandBar_InsertMenubarEx(*(undefined4 *)(param_1 + 0x70),0,param_2,0),
         iVar3 != 0)) {
        if (iVar5 == 3) {
          pHVar1 = (HWND)CommandBar_GetItemWindow(*(undefined4 *)(param_1 + 0x70),0);
          GetClientRect(pHVar1,&local_80);
          local_44 = (local_80.right - local_80.left) + 5;
          local_6c = 0x40;
          SendMessageW(*(HWND *)(param_1 + 0x6c),0x40b,0,(LPARAM)&local_70);
        }
        *(byte *)(param_1 + 0x108) = *(byte *)(param_1 + 0x108) & 0xbf;
        uVar6 = 0;
      }
    }
  }
  return uVar6;
}



/* 0001a81c FUN_0001a81c */

/* Boundary evidence: original MIPS .pdata 0001a81c..0001a9d7. Semantic name remains unreviewed. */

void FUN_0001a81c(int param_1)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 *puVar3;
  HKEY local_20;
  uint local_1c;
  DWORD aDStack_18 [2];
  
  puVar3 = *(undefined4 **)(param_1 + 0x84);
  *(byte *)(param_1 + 0x12d) = *(byte *)(param_1 + 0x12d) | 1;
  if (puVar3 != (undefined4 *)0x0) {
    FUN_0001dac0(puVar3);
    operator_delete(puVar3);
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x7c);
  if (iVar2 != 0) {
    FUN_0001f55c(iVar2,*(HMENU *)(iVar2 + 4));
  }
  FUN_0001d2c8(param_1);
  FUN_00015de4(*(int *)(param_1 + 0x4c));
  FUN_00018d00(param_1,L"IE",1);
  FUN_00018d00(param_1,L"SH",1);
  local_20 = (HKEY)0x0;
  LVar1 = RegCreateKeyExW((HKEY)0x80000001,
                          L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StatusBar",0,
                          (LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_20,aDStack_18);
  if (LVar1 == 0) {
    local_1c = (uint)((*(byte *)(param_1 + 300) & 0x20) != 0);
    RegSetValueExW(local_20,L"ShowStatusBar",0,4,(BYTE *)&local_1c,4);
    RegCloseKey(local_20);
  }
  if (*(int *)(param_1 + 0xa4) != 0) {
    FUN_00019204(param_1);
  }
  if (*(HIMAGELIST *)(param_1 + 0xb0) != (HIMAGELIST)0x0) {
    ImageList_Destroy(*(HIMAGELIST *)(param_1 + 0xb0));
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  if (*(HWND *)(param_1 + 0x90) != (HWND)0x0) {
    DestroyWindow(*(HWND *)(param_1 + 0x90));
  }
  FUN_00019a04();
  if (*(int **)(param_1 + 0x74) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x74) + 8))();
  }
  FUN_00016394();
  return;
}



/* 0001a9d8 FUN_0001a9d8 */

/* Boundary evidence: original MIPS .pdata 0001a9d8..0001abe7. Semantic name remains unreviewed. */

void FUN_0001a9d8(int param_1)

{
  undefined1 *puVar1;
  WPARAM wParam;
  LRESULT LVar2;
  wchar_t *hMem;
  int iVar3;
  uint uVar4;
  char cVar5;
  uint local_268 [2];
  undefined4 local_260;
  undefined1 auStack_25c [8];
  undefined1 auStack_254 [4];
  wchar_t *local_250;
  undefined1 auStack_24c [4];
  undefined1 auStack_248 [4];
  undefined1 auStack_244 [36];
  undefined4 local_220;
  wchar_t local_21c;
  undefined1 auStack_21a [514];
  uint local_18;
  
  local_18 = DAT_00035518;
  wParam = SendMessageW(*(HWND *)(param_1 + 0xa4),0x147,0,0);
  if (((wParam == 0xffffffff) ||
      (LVar2 = SendMessageW(*(HWND *)(param_1 + 0xa4),0x149,wParam,0), LVar2 == -1)) ||
     (hMem = LocalAlloc(0,(LVar2 + 1) * 2), hMem == (wchar_t *)0x0)) goto LAB_0001abc8;
  SendMessageW(*(HWND *)(param_1 + 0xa4),0x148,wParam,(LPARAM)hMem);
  local_220 = 0x3a003a;
  local_21c = L'\0';
  memset(auStack_21a,0,0x202);
  local_268[0] = 0x102;
  iVar3 = FUN_00014ff4(hMem,&local_21c,local_268);
  cVar5 = '\x01';
  if (iVar3 == 0) {
    if ((DAT_00035524 == 0) && (uVar4 = FUN_000158ec(hMem), uVar4 == 0)) {
      memset(auStack_25c,0,0x38);
      local_250 = L"explorer.exe";
      local_260 = 0x3c;
      puVar1 = auStack_25c + 3;
      uVar4 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar4) =
           *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | 0U >> (3 - uVar4) * 8;
      puVar1 = auStack_254 + 3;
      uVar4 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar4) =
           *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | 0U >> (3 - uVar4) * 8;
      puVar1 = auStack_24c + 3;
      uVar4 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar4) =
           *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | (uint)hMem >> (3 - uVar4) * 8;
      puVar1 = auStack_248 + 3;
      uVar4 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar4) =
           *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | 0U >> (3 - uVar4) * 8;
      puVar1 = auStack_244 + 3;
      uVar4 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar4) =
           *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | 1U >> (3 - uVar4) * 8;
      auStack_25c._0_4_ = 0;
      auStack_254 = (undefined1  [4])0x0;
      auStack_248 = (undefined1  [4])0x0;
      auStack_244._0_4_ = 1;
      auStack_24c = (undefined1  [4])hMem;
      iVar3 = ShellExecuteEx(&local_260);
      if (iVar3 != 0) {
        FUN_0001949c(param_1);
        cVar5 = '\0';
        goto LAB_0001aba4;
      }
    }
    (**(code **)(**(int **)(param_1 + 0x28) + 0x2c))(*(int **)(param_1 + 0x28),hMem,0,0,0,0);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x28) + 0x2c))(*(int **)(param_1 + 0x28),&local_220,0,0,0,0);
  }
LAB_0001aba4:
  *(byte *)(param_1 + 300) = (cVar5 << 1 ^ *(byte *)(param_1 + 300)) & 2 ^ *(byte *)(param_1 + 300);
  LocalFree(hMem);
LAB_0001abc8:
  FUN_00033770(local_18);
  return;
}



/* 0001abe8 FUN_0001abe8 */

/* Boundary evidence: original MIPS .pdata 0001abe8..0001ae1b. Semantic name remains unreviewed. */

undefined4 FUN_0001abe8(HWND param_1,int param_2,short param_3,LPCWSTR param_4)

{
  LPCWSTR lpString;
  int iVar1;
  HWND pHVar2;
  LRESULT LVar3;
  BOOL BVar4;
  INT_PTR nResult;
  tagWNDCLASSW tStack_48;
  
  lpString = (LPCWSTR)GetWindowLongW(param_1,8);
  nResult = 4;
  if (param_2 == 2) {
    SetWindowLongW(param_1,8,0);
  }
  else {
    if (param_2 == 0x110) {
      BVar4 = GetClassInfoW(DAT_00035560,L"SIPPREF",&tStack_48);
      if (BVar4 != 0) {
        CreateWindowExW(0,L"SIPPREF",(LPCWSTR)0x0,0x40000000,-10,-10,5,5,param_1,(HMENU)0x0,
                        DAT_00035560,(LPVOID)0x0);
      }
      FUN_0001e71c(param_1,2);
      if (param_4 == (LPCWSTR)0x0) {
        pHVar2 = GetDlgItem(param_1,1);
        EnableWindow(pHVar2,0);
        pHVar2 = GetDlgItem(param_1,0xbb9);
        EnableWindow(pHVar2,0);
        return 1;
      }
      SetWindowLongW(param_1,8,(LONG)param_4);
      pHVar2 = GetDlgItem(param_1,3000);
      SendMessageW(pHVar2,0xc5,0x80b,0);
      lpString = param_4;
      if (*param_4 == L'\0') {
        return 1;
      }
LAB_0001adcc:
      SetDlgItemTextW(param_1,3000,lpString);
      return 1;
    }
    if (param_2 == 0x111) {
      if (param_3 == 1) {
        GetDlgItemTextW(param_1,3000,lpString,0x80b);
        pHVar2 = GetDlgItem(param_1,0xbba);
        LVar3 = SendMessageW(pHVar2,0xf0,0,0);
        nResult = 2;
        if (LVar3 == 0) {
          nResult = 1;
        }
      }
      else if (param_3 != 2) {
        if (param_3 != 0xbb9) {
          return 1;
        }
        iVar1 = FUN_00019798(param_1,lpString);
        if (iVar1 == 0) {
          return 1;
        }
        goto LAB_0001adcc;
      }
      EndDialog(param_1,nResult);
      return 1;
    }
  }
  return 0;
}



/* 0001ae1c FUN_0001ae1c */

/* Boundary evidence: original MIPS .pdata 0001ae1c..0001af8b. Semantic name remains unreviewed. */

WPARAM FUN_0001ae1c(int *param_1)

{
  int iVar1;
  int iVar2;
  HRESULT HVar3;
  BOOL BVar4;
  tagMSG tStack_30;
  
  CoInitializeEx((LPVOID)0x0,0);
  iVar1 = FUN_00019ce4(param_1);
  iVar2 = IEUsesDCOM();
  if ((iVar2 != 0) && ((LPUNKNOWN)param_1[10] != (LPUNKNOWN)0x0)) {
    HVar3 = CoMarshalInterThreadInterfaceInStream
                      ((IID *)&DAT_00012090,(LPUNKNOWN)param_1[10],(LPSTREAM *)(param_1 + 0x1c));
    if (HVar3 != 0) {
      param_1[0x1c] = 0;
    }
  }
  EventModify(param_1[0xb],3);
  if (iVar1 == 0) {
    param_1[10] = 0;
    tStack_30.wParam = 0;
  }
  else {
    FUN_00017324((int)param_1);
    while ((BVar4 = GetMessageW(&tStack_30,(HWND)0x0,0,0), BVar4 != 0 && (tStack_30.message != 0x12)
           )) {
      iVar1 = FUN_000188d0((int)param_1,&tStack_30);
      if ((iVar1 == 0) && ((tStack_30.message != 0x102 || (tStack_30.wParam != 9)))) {
        TranslateMessage(&tStack_30);
        DispatchMessageW(&tStack_30);
      }
    }
    (**(code **)(*param_1 + 8))(param_1);
    CoUninitialize();
    InterlockedDecrement(&DAT_00035554);
    EventModify(DAT_00035558,3);
  }
  return tStack_30.wParam;
}



/* 0001af8c FUN_0001af8c */

/* Boundary evidence: original MIPS .pdata 0001af8c..0001b223. Semantic name remains unreviewed. */

int FUN_0001af8c(wchar_t *param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  int *lpParameter;
  size_t sVar2;
  STRSAFE_LPWSTR pszDest;
  HRESULT HVar3;
  HANDLE pvVar4;
  int iVar5;
  int iVar6;
  LPVOID local_28 [2];
  
  iVar6 = 0;
  puVar1 = LocalAlloc(0x40,0x1150);
  if (puVar1 == (undefined4 *)0x0) {
    lpParameter = (int *)0x0;
  }
  else {
    lpParameter = FUN_00016ad0(puVar1);
  }
  if (lpParameter != (int *)0x0) {
    if (param_1 != (wchar_t *)0x0) {
      sVar2 = wcslen(param_1);
      if (0x80b < (int)sVar2) {
        sVar2 = 0x80b;
      }
      pszDest = LocalAlloc(0,(sVar2 + 1) * 2);
      lpParameter[0x19] = (int)pszDest;
      if ((pszDest == (STRSAFE_LPWSTR)0x0) ||
         (HVar3 = StringCchCopyW(pszDest,sVar2 + 1,param_1), HVar3 != 0)) {
        (**(code **)(*lpParameter + 0x18))(lpParameter,1);
        return -0x7fffbffb;
      }
    }
    lpParameter[0x1a] = param_2;
    if (param_3 == (int *)0x0) {
      *(byte *)(lpParameter + 0x1b) = *(byte *)(lpParameter + 0x1b) | 1;
    }
    pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpParameter[0xb] = (int)pvVar4;
    if (pvVar4 == (HANDLE)0x0) {
      (**(code **)(*lpParameter + 0x18))(lpParameter,1);
    }
    else {
      InterlockedIncrement(&DAT_00035554);
      pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,DAT_00035520,FUN_0001ae1c,lpParameter,0x10000
                            ,(LPDWORD)0x0);
      if (pvVar4 != (HANDLE)0x0) {
        WaitForSingleObject((HANDLE)lpParameter[0xb],0xffffffff);
        CloseHandle(pvVar4);
        if (param_3 == (int *)0x0) {
          return 0;
        }
        iVar5 = IEUsesDCOM();
        if ((iVar5 == 0) || ((LPSTREAM)lpParameter[0x1c] == (LPSTREAM)0x0)) {
          puVar1 = (undefined4 *)lpParameter[10];
          if (puVar1 == (undefined4 *)0x0) {
            local_28[0] = (LPVOID)0x0;
            iVar6 = -0x7fffbffb;
          }
          else {
            iVar6 = (**(code **)*puVar1)(puVar1,&DAT_00012090,local_28);
          }
        }
        else {
          CoGetInterfaceAndReleaseStream((LPSTREAM)lpParameter[0x1c],(IID *)&DAT_00012090,local_28);
          lpParameter[0x1c] = 0;
        }
        **(undefined2 **)(*param_3 + 8) = 0;
        **(undefined4 **)(*param_3 + 0x18) = local_28[0];
        if (iVar6 != -0x7ff8fff2) {
          return iVar6;
        }
        goto LAB_0001b1f0;
      }
      (**(code **)(*lpParameter + 0x18))(lpParameter,1);
      InterlockedDecrement(&DAT_00035554);
    }
  }
  iVar6 = -0x7ff8fff2;
LAB_0001b1f0:
  SHShowOutOfMemory(0,0);
  return iVar6;
}



/* 0001b224 FUN_0001b224 */

/* Boundary evidence: original MIPS .pdata 0001b224..0001b85f. Semantic name remains unreviewed. */

undefined4 FUN_0001b224(int param_1,int param_2,void *param_3,uint param_4,undefined2 param_5)

{
  HIMAGELIST p_Var1;
  HBITMAP hbmImage;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  WPARAM WVar5;
  LRESULT LVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  HLOCAL _Dst;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  HLOCAL local_58;
  int local_54;
  LPWSTR local_50;
  undefined4 local_48;
  tagRECT tStack_40;
  uint local_30;
  
  local_30 = DAT_00035518;
  _Dst = (HLOCAL)0x0;
  local_48 = 0;
  local_50 = (LPWSTR)0x0;
  if (*(HIMAGELIST *)(param_1 + 0xb0) != (HIMAGELIST)0x0) {
    ImageList_Destroy(*(HIMAGELIST *)(param_1 + 0xb0));
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  if (*(int *)(param_1 + 0xa4) != 0) {
    FUN_00019204(param_1);
    local_50 = LocalAlloc(0,0x1018);
    if (local_50 != (LPWSTR)0x0) {
      *local_50 = L'\0';
      GetWindowTextW(*(HWND *)(param_1 + 0xa4),local_50,0x80c);
    }
  }
  if (*(HWND *)(param_1 + 0x90) != (HWND)0x0) {
    DestroyWindow(*(HWND *)(param_1 + 0x90));
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(undefined4 *)(param_1 + 0x94) = 0;
    *(undefined4 *)(param_1 + 0x9c) = 0;
    *(undefined4 *)(param_1 + 0xa4) = 0;
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  p_Var1 = ImageList_Create(0xb,0xd,0,1,0);
  *(HIMAGELIST *)(param_1 + 0xb0) = p_Var1;
  hbmImage = LoadBitmapW(DAT_00035560,(LPCWSTR)0x32);
  if (hbmImage != (HBITMAP)0x0) {
    ImageList_Add(*(HIMAGELIST *)(param_1 + 0xb0),hbmImage,(HBITMAP)0x0);
    DeleteObject(hbmImage);
  }
  iVar2 = CommandBands_Create(DAT_00035560,*(undefined4 *)(param_1 + 0x4c),0x19,0x3400,
                              *(undefined4 *)(param_1 + 0xb0));
  *(int *)(param_1 + 0x90) = iVar2;
  uVar4 = 0;
  if (iVar2 == 0) goto LAB_0001b814;
  iVar2 = -1;
  local_54 = -1;
  iVar18 = -1;
  uVar3 = GetWindowLongW(*(HWND *)(param_1 + 0x4c),-0x14);
  local_58 = param_3;
  if ((uVar3 & 0x400000) != 0) {
    iVar13 = -1;
    local_58 = param_3;
    if (((int)((ulonglong)param_4 * 0x14 >> 0x20) == 0) &&
       (_Dst = LocalAlloc(0,(SIZE_T)((ulonglong)param_4 * 0x14)), local_58 = param_3,
       _Dst != (HLOCAL)0x0)) {
      memcpy(_Dst,param_3,param_4 * 0x14);
      iVar8 = 0;
      if (0 < (int)param_4) {
        piVar9 = (int *)((int)_Dst + 4);
        iVar14 = -1;
        do {
          iVar15 = iVar8;
          if ((*piVar9 != 0x8150) && (iVar15 = iVar14, *piVar9 == 0x8151)) {
            iVar13 = iVar8;
          }
          if ((iVar15 != -1) && (iVar13 != -1)) goto LAB_0001b460;
          iVar8 = iVar8 + 1;
          piVar9 = piVar9 + 5;
          iVar14 = iVar15;
        } while (iVar8 < (int)param_4);
        if (iVar13 != -1) {
LAB_0001b460:
          local_58 = param_3;
          if (iVar15 != -1) {
            puVar7 = (undefined4 *)(iVar13 * 0x14 + (int)_Dst);
            uVar4 = *puVar7;
            uVar17 = puVar7[1];
            uVar16 = puVar7[2];
            uVar12 = puVar7[3];
            uVar11 = puVar7[4];
            puVar10 = (undefined4 *)(iVar15 * 0x14 + (int)_Dst);
            *puVar7 = *puVar10;
            puVar7[1] = puVar10[1];
            puVar7[2] = puVar10[2];
            puVar7[3] = puVar10[3];
            puVar7[4] = puVar10[4];
            *puVar10 = uVar4;
            puVar10[1] = uVar17;
            puVar10[2] = uVar16;
            puVar10[3] = uVar12;
            puVar10[4] = uVar11;
            local_58 = _Dst;
          }
        }
      }
    }
  }
  iVar13 = 0;
  piVar9 = (int *)(param_1 + 0xc0);
  do {
    iVar8 = piVar9[-2];
    if (iVar8 == 0x14) {
      FUN_000176b0(param_1,param_5,piVar9[-1],*piVar9);
      iVar2 = iVar13;
    }
    else if (iVar8 == 0x15) {
      FUN_00017834(param_1,(LPARAM)local_58,param_4,piVar9[-1],*piVar9);
      iVar18 = iVar13;
    }
    else if (iVar8 == 0x16) {
      *(byte *)(param_1 + 300) =
           (((piVar9[-1] & 8U) == 0) << 4 ^ *(byte *)(param_1 + 300)) & 0x10 ^
           *(byte *)(param_1 + 300);
      FUN_0001a068(param_1,piVar9[-1],*piVar9);
      local_54 = iVar13;
    }
    iVar13 = iVar13 + 1;
    piVar9 = piVar9 + 5;
  } while (iVar13 < 3);
  if (iVar2 == -1) {
    FUN_000176b0(param_1,param_5,0xffffffff,-1);
  }
  if (iVar18 == -1) {
    FUN_00017834(param_1,(LPARAM)local_58,param_4,0xffffffff,-1);
  }
  if (local_54 == -1) {
    FUN_0001a068(param_1,0xffffffff,-1);
  }
  if ((iVar2 != -1) && (*(int *)(iVar2 * 0x14 + param_1 + 0xc4) != 0)) {
    SendMessageW(*(HWND *)(param_1 + 0x90),0x41f,0,0);
  }
  if ((iVar18 != -1) && (*(int *)(iVar18 * 0x14 + param_1 + 0xc4) != 0)) {
    WVar5 = SendMessageW(*(HWND *)(param_1 + 0x90),0x410,0x15,0);
    SendMessageW(*(HWND *)(param_1 + 0x90),0x41f,WVar5,0);
  }
  if ((local_54 != -1) && (*(int *)(local_54 * 0x14 + param_1 + 0xc4) != 0)) {
    WVar5 = SendMessageW(*(HWND *)(param_1 + 0x90),0x410,0x16,0);
    SendMessageW(*(HWND *)(param_1 + 0x90),0x41f,WVar5,0);
  }
  if ((local_50 != (LPWSTR)0x0) && (*(HWND *)(param_1 + 0xa4) != (HWND)0x0)) {
    SendMessageW(*(HWND *)(param_1 + 0xa4),0xc,0,(LPARAM)local_50);
  }
  if (param_2 != 0) {
    if ((*(byte *)(param_1 + 300) & 0x80) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0xb;
    }
    CommandBands_AddAdornments(*(undefined4 *)(param_1 + 0x90),DAT_00035560,uVar4,0);
  }
  if (*(int *)(param_1 + 0x84) == 0) {
    puVar7 = operator_new(0x28);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = FUN_0001d9bc(puVar7,*(undefined4 *)(param_1 + 0x4c));
    }
    *(undefined4 **)(param_1 + 0x84) = puVar7;
    if (puVar7 != (undefined4 *)0x0) {
      FUN_0001df14(puVar7);
      WaitForSingleObject((HANDLE)**(undefined4 **)(param_1 + 0x84),0xffffffff);
      goto LAB_0001b7b4;
    }
  }
  else {
LAB_0001b7b4:
    GetWindowRect(*(HWND *)(param_1 + 0x4c),&tStack_40);
    LVar6 = SendMessageW(*(HWND *)(param_1 + 0x90),0x41b,0,0);
    tStack_40.top = LVar6 + tStack_40.top;
    FUN_0001db4c(*(int *)(param_1 + 0x84),(int)&tStack_40);
    local_48 = 1;
    *(byte *)(param_1 + 300) = *(byte *)(param_1 + 300) | 0x40;
  }
  uVar4 = local_48;
  if (_Dst != (HLOCAL)0x0) {
    LocalFree(_Dst);
  }
LAB_0001b814:
  if (local_50 != (LPWSTR)0x0) {
    LocalFree(local_50);
  }
  FUN_00033770(local_30);
  return uVar4;
}



/* 0001b860 FUN_0001b860 */

/* Boundary evidence: original MIPS .pdata 0001b860..0001c0ab. Semantic name remains unreviewed. */

int FUN_0001b860(int param_1,int param_2)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  HMENU hMenu;
  size_t sVar4;
  LPCWSTR lpText;
  HWND hWnd;
  int *piVar5;
  UINT Msg;
  wchar_t *pwVar6;
  undefined2 *puVar7;
  int iVar8;
  short *psVar9;
  uint uVar10;
  size_t sVar11;
  WPARAM WVar12;
  wchar_t *_Str;
  undefined2 uVar13;
  int *in_stack_00000014;
  HWND local_330 [2];
  wchar_t awStack_328 [80];
  undefined2 local_288;
  undefined2 local_22a;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_00035518;
  if (param_2 < 0xfb) {
    if (param_2 == 0xfa) goto LAB_0001c05c;
    if (0x6a < param_2) {
      if (param_2 != 0x6c) {
        if (param_2 != 0x70) {
          if (param_2 != 0x71) {
LAB_0001bc24:
            FUN_00033770(DAT_00035518);
            return -0x7ffdfffd;
          }
          if ((in_stack_00000014 != (int *)0x0) && (*(short *)*in_stack_00000014 == 8)) {
            _Str = *(wchar_t **)((short *)*in_stack_00000014 + 4);
            sVar4 = wcslen(_Str);
            pwVar6 = _Str + sVar4;
            sVar11 = sVar4;
            do {
              if ((int)sVar11 < 1) break;
              pwVar6 = pwVar6 + -1;
              sVar11 = sVar11 - 1;
            } while (*pwVar6 != L'\\');
            iVar8 = (_Str[sVar11] == L'\\') + sVar11;
            wcsncpy((wchar_t *)(param_1 + 0x11a),_Str + iVar8,0x80b);
            wcsncpy(awStack_328,_Str + iVar8,0x50);
            local_288 = 0;
            if (0x50 < (int)(sVar4 - iVar8)) {
              wcscat(awStack_328,L"...");
            }
            SetWindowTextW(*(HWND *)(param_1 + 0x38),awStack_328);
          }
        }
        goto LAB_0001c05c;
      }
      if (*(int *)(*in_stack_00000014 + 0x18) == -1) {
        WVar12 = 999;
      }
      else {
        WVar12 = (*(int *)(*in_stack_00000014 + 0x18) + -1) % 1000;
      }
      hWnd = *(HWND *)(param_1 + 0x98);
      pwVar6 = (wchar_t *)0x0;
      Msg = 0x402;
LAB_0001b9e8:
      SendMessageW(hWnd,Msg,WVar12,(LPARAM)pwVar6);
      goto LAB_0001c05c;
    }
    if (param_2 == 0x6a) {
      iVar8 = *(int *)(param_1 + 0x1138) + 1;
      *(int *)(param_1 + 0x1138) = iVar8;
      if (iVar8 == 1) {
        if (((*(byte *)(param_1 + 0x74) & 1) != 0) && (*(int *)(param_1 + 0x70) != 0)) {
          FUN_0001dc84(*(int *)(param_1 + 0x70));
        }
        FUN_0001e4dc();
      }
      goto LAB_0001c05c;
    }
    if (param_2 == 4) {
      if ((((in_stack_00000014 != (int *)0x0) && (in_stack_00000014[2] == 2)) &&
          (psVar9 = (short *)*in_stack_00000014, *psVar9 == 8)) &&
         ((psVar9[8] == 8 && (*(int *)(param_1 + 0x68) != 0)))) {
        FUN_0002061c(*(int *)(param_1 + 0x68),*(HWND *)(param_1 + 0x38),*(wchar_t **)(psVar9 + 4),
                     *(short **)(psVar9 + 0xc));
      }
      goto LAB_0001c05c;
    }
    if (param_2 == 0x66) {
      if ((((*(byte *)(param_1 + 0x118) & 0x20) == 0) || (in_stack_00000014 == (int *)0x0)) ||
         (*(short *)*in_stack_00000014 != 8)) goto LAB_0001c05c;
      wcsncpy(awStack_328,*(wchar_t **)((short *)*in_stack_00000014 + 4),0x80);
      local_22a = 0;
      pwVar6 = awStack_328;
      WVar12 = 0;
      Msg = 0x40b;
      goto LAB_0001b9e4;
    }
    if (param_2 != 0x68) {
      if (param_2 != 0x69) goto LAB_0001bc24;
      if (*(int *)(*in_stack_00000014 + 0x18) == 1) {
        WVar12 = 0x8151;
      }
      else {
        if (*(int *)(*in_stack_00000014 + 0x18) != 2) goto LAB_0001c05c;
        WVar12 = 0x8150;
      }
      uVar3 = SendMessageW(*(HWND *)(param_1 + 0x88),0x412,WVar12,0);
      bVar1 = *(short *)(*in_stack_00000014 + 8) == 0;
      if (bVar1) {
        uVar3 = uVar3 & 0xfffffffb;
      }
      else {
        uVar3 = uVar3 | 4;
      }
      SendMessageW(*(HWND *)(param_1 + 0x88),0x411,WVar12,uVar3);
      hMenu = (HMENU)CommandBar_GetMenu(*(undefined4 *)(param_1 + 0x80),0);
      if (hMenu != (HMENU)0x0) {
        EnableMenuItem(hMenu,WVar12,(uint)bVar1);
      }
      goto LAB_0001c05c;
    }
LAB_0001be70:
    iVar8 = *(int *)(param_1 + 0x1138) + -1;
    *(int *)(param_1 + 0x1138) = iVar8;
    if (iVar8 < 1) {
      FUN_0001e4dc();
      if (((*(byte *)(param_1 + 0x74) & 1) != 0) && (*(int *)(param_1 + 0x70) != 0)) {
        FUN_0001dcd4(*(int *)(param_1 + 0x70));
      }
      FUN_000189ac(param_1 + -0x14,1);
      uVar3 = *(byte *)(param_1 + 0x118) & 0x40;
      *(undefined4 *)(param_1 + 0x1138) = 0;
      if ((*(byte *)(param_1 + 0x74) & 1) != uVar3 >> 6) {
        *(byte *)(param_1 + 0x74) = *(byte *)(param_1 + 0x74) & 0xfe | (byte)(uVar3 >> 6);
      }
    }
    goto LAB_0001c05c;
  }
  if (param_2 == 0xfb) {
    iVar8 = FUN_0001af8c((wchar_t *)0x0,0,in_stack_00000014);
    FUN_00033770(local_20);
    return iVar8;
  }
  if (param_2 == 0xfc) {
    bVar2 = *(byte *)(param_1 + 0x118);
    if (((bVar2 & 1) == 0) && ((bVar2 & 2) == 0)) {
      piVar5 = *(int **)(param_1 + 0x28);
      if ((piVar5 != (int *)0x0) &&
         (iVar8 = (**(code **)(*piVar5 + 0xc))(piVar5,local_330), iVar8 == 0)) {
        SetFocus(local_330[0]);
      }
    }
    else {
      *(byte *)(param_1 + 0x118) = bVar2 & 0xfc;
      SetFocus(*(HWND *)(param_1 + 0x90));
      if ((in_stack_00000014 != (int *)0x0) &&
         (psVar9 = (short *)*in_stack_00000014, *psVar9 == 0x400c)) {
        pwVar6 = *(wchar_t **)(*(int *)(psVar9 + 4) + 8);
        iVar8 = wcsncmp(pwVar6,L"::{",3);
        if (iVar8 == 0) {
          local_330[0] = (HWND)0x0;
          pwVar6 = (wchar_t *)(param_1 + 0x11a);
          FUN_00015484((LPCWSTR)(*(int *)(*(int *)(psVar9 + 4) + 8) + 4),pwVar6,(int *)local_330);
          if (local_330[0] != (HWND)0x0) {
            WVar12 = SendMessageW(*(HWND *)(param_1 + 0x90),0x158,0xffffffff,(LPARAM)local_330[0]);
            if (WVar12 != 0xffffffff) {
              SendMessageW(*(HWND *)(param_1 + 0x90),0x144,WVar12,0);
              SendMessageW(*(HWND *)(param_1 + 0x90),0x14a,WVar12,(LPARAM)pwVar6);
            }
            LocalFree(local_330[0]);
          }
        }
        FUN_000193e4(param_1 + -0x14,(LPARAM)pwVar6);
      }
    }
    iVar8 = param_1 + -0x14;
    FUN_0001949c(iVar8);
    FUN_00017148(iVar8);
    FUN_000171fc(iVar8);
    goto LAB_0001c05c;
  }
  if (param_2 == 0xfd) {
    PostMessageW(*(HWND *)(param_1 + 0x38),0x10,0,0);
    goto LAB_0001c05c;
  }
  if (param_2 == 0x103) goto LAB_0001be70;
  if (param_2 == 0x10d) {
    if ((in_stack_00000014 == (int *)0x0) || (*(short *)*in_stack_00000014 != 3)) goto LAB_0001c05c;
    iVar8 = *(int *)((short *)*in_stack_00000014 + 4);
    pwVar6 = (wchar_t *)0x0;
    if (((iVar8 == 2) || (((iVar8 == 3 || (iVar8 == 4)) || (iVar8 == 5)))) ||
       ((iVar8 == 6 || (iVar8 == 1)))) {
      pwVar6 = (wchar_t *)FUN_00016508(5);
    }
    WVar12 = 2;
    Msg = 0x40f;
LAB_0001b9e4:
    hWnd = *(HWND *)(param_1 + 0x8c);
    goto LAB_0001b9e8;
  }
  if (param_2 == 0x10e) goto LAB_0001c05c;
  if (param_2 != 0x10f) goto LAB_0001bc24;
  *(byte *)(param_1 + 0x118) = *(byte *)(param_1 + 0x118) & 0xfe;
  if (((in_stack_00000014 == (int *)0x0) ||
      (iVar8 = *in_stack_00000014, *(short *)(iVar8 + 0x30) != 0x400c)) ||
     ((psVar9 = *(short **)(iVar8 + 0x38), psVar9 == (short *)0x0 || (*psVar9 != 8))))
  goto LAB_0001c05c;
  pwVar6 = *(wchar_t **)(psVar9 + 4);
  uVar13 = 1;
  uVar3 = 0x80004005;
  if (pwVar6 == (wchar_t *)0x0) {
    pwVar6 = L"";
  }
  uVar10 = 0x80004005;
  if ((((*(short *)(iVar8 + 0x10) == 0x400c) &&
       (psVar9 = *(short **)(iVar8 + 0x18), uVar10 = uVar3, psVar9 != (short *)0x0)) &&
      (*psVar9 == 3)) && (*(uint *)(psVar9 + 4) != 0)) {
    uVar10 = *(uint *)(psVar9 + 4);
  }
  uVar10 = uVar10 & 0xffff;
  if (uVar10 == 0x80004005) {
LAB_0001bd48:
    LoadStringW(DAT_00035560,0x4e2b,aWStack_228,0x104);
    sVar11 = wcslen(aWStack_228);
    sVar4 = wcslen(pwVar6);
    lpText = LocalAlloc(0,(sVar4 + sVar11 + 1) * 2);
    if (lpText != (LPCWSTR)0x0) {
      wsprintfW(lpText,aWStack_228,pwVar6);
      MessageBoxW(*(HWND *)(param_1 + 0x38),lpText,pwVar6,0x10010);
      LocalFree(lpText);
    }
LAB_0001bdc4:
    FUN_0001949c(param_1 + -0x14);
  }
  else {
    if (uVar10 == 0x8007000e) {
      SHShowOutOfMemory(*(undefined4 *)(param_1 + 0x38),0);
      goto LAB_0001bdc4;
    }
    if (uVar10 == 0x80070057) goto LAB_0001bd48;
    if (1 < uVar10) {
      if (uVar10 < 4) goto LAB_0001bd48;
      if ((uVar10 == 0x35) || (uVar10 == 0x4c6)) goto LAB_0001bdc4;
    }
    uVar13 = 0;
  }
  if ((*(short *)*in_stack_00000014 == 0x400b) &&
     (puVar7 = *(undefined2 **)((short *)*in_stack_00000014 + 4), puVar7 != (undefined2 *)0x0)) {
    *puVar7 = uVar13;
  }
LAB_0001c05c:
  FUN_00033770(local_20);
  return 0;
}



/* 0001c0ac FUN_0001c0ac */

/* Boundary evidence: original MIPS .pdata 0001c0ac..0001c9af. Semantic name remains unreviewed. */

undefined4 FUN_0001c0ac(int *param_1,uint param_2)

{
  undefined1 *puVar1;
  OLECHAR OVar2;
  bool bVar3;
  undefined3 extraout_var;
  int iVar4;
  LRESULT LVar5;
  wchar_t *pwVar6;
  HWND pHVar7;
  STRSAFE_LPWSTR pszDest;
  HRESULT HVar8;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar9;
  undefined4 uVar10;
  HMENU pHVar11;
  undefined4 *puVar12;
  UINT Msg;
  code *pcVar13;
  OLECHAR *pOVar14;
  HWND hWnd;
  uint uVar15;
  wchar_t *local_70 [2];
  tagRECT local_68;
  OLECHAR local_58 [4];
  int local_50;
  undefined1 auStack_4c [4];
  wchar_t *local_48;
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined4 local_3c;
  
  uVar15 = param_2 & 0xffff;
  bVar3 = FUN_0001e4e4((int)param_1,(short)param_2);
  if (CONCAT31(extraout_var,bVar3) == 0) {
    return 0;
  }
  if (uVar15 < 0xa00c) {
    if (uVar15 == 0xa00b) {
      hWnd = (HWND)param_1[0x2a];
      pHVar7 = GetFocus();
      if (pHVar7 != hWnd) {
        (**(code **)(*(int *)param_1[10] + 0xd8))((int *)param_1[10],0xb,2,0,0);
        return 0;
      }
      Msg = 0x300;
      goto LAB_0001c780;
    }
    if (uVar15 < 0x8172) {
      if (uVar15 == 0x8171) {
        if (param_1[0x1f] == 0) {
          return 0;
        }
        FUN_0002022c(param_1[0x1f],param_1[0x13]);
        return 0;
      }
      if (uVar15 == 0x18) {
        if (param_2 >> 0x10 != 9) {
          return 0;
        }
        FUN_0001a9d8((int)param_1);
        return 0;
      }
      if (uVar15 == 0x8000) {
        (**(code **)(*(int *)param_1[10] + 0xd8))((int *)param_1[10],0x2d,0,0,0);
        return 0;
      }
      if (uVar15 == 0x8080) {
        if (param_1[0x24] == 0) {
          return 0;
        }
        uVar15 = ((uint)((*(byte *)(param_1 + 0x4b) & 8) == 0) << 3 ^
                 (uint)*(byte *)(param_1 + 0x4b)) & 8 ^ (uint)*(byte *)(param_1 + 0x4b);
        *(char *)(param_1 + 0x4b) = (char)uVar15;
        CommandBands_Show(param_1[0x24],uVar15 >> 3 & 1);
        GetClientRect((HWND)param_1[0x13],&local_68);
        if ((*(byte *)(param_1 + 0x4b) & 8) != 0) {
          LVar5 = SendMessageW((HWND)param_1[0x24],0x41b,0,0);
          local_68.top = LVar5 + local_68.top;
        }
        if (param_1[0x21] != 0) {
          FUN_0001db4c(param_1[0x21],(int)&local_68);
        }
        goto LAB_0001c4e4;
      }
      if (uVar15 == 0x8081) {
        FUN_000173f8((int)param_1,(uint)((*(byte *)(param_1 + 0x4b) & 0x10) == 0));
        return 0;
      }
      if (uVar15 == 0x8150) {
        pwVar6 = (BSTR)param_1[10];
        pcVar13 = *(code **)(*(int *)param_1[10] + 0x1c);
        goto LAB_0001c90c;
      }
      if (uVar15 == 0x8151) {
        pwVar6 = (BSTR)param_1[10];
        pcVar13 = *(code **)(*(int *)param_1[10] + 0x20);
        goto LAB_0001c90c;
      }
      if (uVar15 == 0x8170) {
        local_70[0] = (wchar_t *)0x0;
        if (param_1[0x1f] == 0) {
          return 0;
        }
        iVar4 = (**(code **)(*(int *)param_1[10] + 0x78))((int *)param_1[10],local_70);
        if (iVar4 != 0) {
          return 0;
        }
        FUN_0002061c(param_1[0x1f],(HWND)param_1[0x13],local_70[0],(short *)((int)param_1 + 0x12e));
        pwVar6 = local_70[0];
        pcVar13 = SysFreeString_exref;
        goto LAB_0001c90c;
      }
    }
    else {
      if (uVar15 == 0xa000) {
        pwVar6 = (BSTR)param_1[10];
        pcVar13 = *(code **)(*(int *)param_1[10] + 0x38);
        goto LAB_0001c90c;
      }
      if (uVar15 == 0xa001) {
        pwVar6 = (BSTR)param_1[10];
        pcVar13 = *(code **)(*(int *)param_1[10] + 0x30);
        goto LAB_0001c90c;
      }
      if ((uVar15 == 0xa002) || (uVar15 - 0xa002 < 5)) {
        param_1[0x452] = uVar15 - 0xa002;
        goto LAB_0001c5a4;
      }
      if (uVar15 == 0xa008) goto switchD_0001c490_caseD_a00f;
      if (uVar15 == 0xa009) {
        FUN_0001df5c((int)param_1);
        return 0;
      }
      if (uVar15 == 0xa00a) {
        pwVar6 = SysAllocString((OLECHAR *)((int)param_1 + 0x12e));
        if (pwVar6 == (BSTR)0x0) {
          return 0;
        }
        OVar2 = *pwVar6;
        pOVar14 = pwVar6;
        while (OVar2 != L'\0') {
          if (*pOVar14 == L'.') {
            *pOVar14 = L'_';
          }
          pOVar14 = pOVar14 + 1;
          OVar2 = *pOVar14;
        }
        local_68.left._0_2_ = 8;
        local_68.right = (LONG)pwVar6;
        (**(code **)(*(int *)param_1[10] + 0xd8))((int *)param_1[10],4,0,&local_68,0);
        pcVar13 = SysFreeString_exref;
        goto LAB_0001c90c;
      }
    }
    goto switchD_0001c490_caseD_a018;
  }
  switch(uVar15) {
  case 0xa00c:
    hWnd = (HWND)param_1[0x2a];
    pHVar7 = GetFocus();
    if (pHVar7 != hWnd) {
      (**(code **)(*(int *)param_1[10] + 0xd8))((int *)param_1[10],0xc,2,0,0);
      return 0;
    }
    Msg = 0x301;
    goto LAB_0001c780;
  case 0xa00d:
    hWnd = (HWND)param_1[0x2a];
    pHVar7 = GetFocus();
    if (pHVar7 != hWnd) {
      (**(code **)(*(int *)param_1[10] + 0xd8))((int *)param_1[10],0xd,2,0,0);
      return 0;
    }
    Msg = 0x302;
LAB_0001c780:
    SendMessageW(hWnd,Msg,0,0);
    return 0;
  case 0xa00e:
    pHVar7 = (HWND)param_1[0x2a];
    if (pHVar7 == (HWND)0x0) {
      return 0;
    }
    goto LAB_0001c5dc;
  case 0xa00f:
switchD_0001c490_caseD_a00f:
    pszDest = LocalAlloc(0,0x1018);
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      return 0;
    }
    local_70[0] = (STRSAFE_LPCWSTR)0x0;
    (**(code **)(*(int *)param_1[10] + 0x78))((int *)param_1[10],local_70);
    HVar8 = StringCchCopyW(pszDest,0x80c,local_70[0]);
    if (HVar8 == 0) {
      SysFreeString(local_70[0]);
      hResInfo = FindResourceW(DAT_00035560,(LPCWSTR)0x3e8,(LPCWSTR)0x5);
      hDialogTemplate = LoadResource(DAT_00035560,hResInfo);
      IVar9 = DialogBoxIndirectParamW
                        (DAT_00035560,hDialogTemplate,(HWND)param_1[0x13],FUN_0001abe8,
                         (LPARAM)pszDest);
      if (IVar9 == 1) {
        (**(code **)(*(int *)param_1[10] + 0x2c))((int *)param_1[10],pszDest,0,0,0,0);
      }
      else if (IVar9 == 2) {
        FUN_0001af8c(pszDest,0,(int *)0x0);
      }
      LocalFree(pszDest);
      return 0;
    }
    LocalFree(pszDest);
    pwVar6 = local_70[0];
    pcVar13 = SysFreeString_exref;
    break;
  case 0xa010:
    pcVar13 = *(code **)(*(int *)param_1[10] + 0x24);
    pwVar6 = (BSTR)param_1[10];
    break;
  case 0xa011:
    pcVar13 = *(code **)(*(int *)param_1[10] + 0x28);
    pwVar6 = (BSTR)param_1[10];
    break;
  case 0xa012:
    uVar10 = FUN_0001877c(param_1);
    return uVar10;
  case 0xa013:
    local_58[0] = L'<';
    local_58[1] = L'\0';
    local_50 = param_1[0x13];
    local_58[2] = L'Ѐ';
    local_58[3] = L'\0';
    local_48 = L"ctlpnl";
    puVar1 = auStack_4c + 3;
    uVar15 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar15) =
         *(uint *)(puVar1 + -uVar15) & -1 << (uVar15 + 1) * 8 | 0U >> (3 - uVar15) * 8;
    puVar1 = auStack_44 + 3;
    uVar15 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar15) =
         *(uint *)(puVar1 + -uVar15) & -1 << (uVar15 + 1) * 8 | 0x11bfcU >> (3 - uVar15) * 8;
    puVar1 = auStack_40 + 3;
    uVar15 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar15) =
         *(uint *)(puVar1 + -uVar15) & -1 << (uVar15 + 1) * 8 | 0U >> (3 - uVar15) * 8;
    local_3c = 1;
    auStack_4c = (undefined1  [4])0x0;
    auStack_44 = (undefined1  [4])0x11bfc;
    auStack_40 = (undefined1  [4])0x0;
    pwVar6 = local_58;
    pcVar13 = ShellExecuteEx_exref;
    break;
  case 0xa014:
    iVar4 = param_1[0x452];
    param_1[0x452] = iVar4 + 1;
    if (4 < iVar4 + 1) {
      param_1[0x452] = 4;
    }
    goto LAB_0001c5a4;
  case 0xa015:
    iVar4 = param_1[0x452];
    param_1[0x452] = iVar4 + -1;
    if (iVar4 + -1 < 0) {
      param_1[0x452] = 0;
    }
LAB_0001c5a4:
    FUN_000189ac((int)param_1,0);
    return 0;
  case 0xa016:
    if ((HWND)param_1[0x29] == (HWND)0x0) {
      return 0;
    }
    SendMessageW((HWND)param_1[0x29],0x14f,1,0);
    pHVar7 = (HWND)param_1[0x29];
LAB_0001c5dc:
    SetFocus(pHVar7);
    return 0;
  case 0xa017:
    if ((*(byte *)(param_1 + 0x4b) & 0x80) != 0) {
      if ((*(byte *)(param_1 + 0x4b) & 0x40) == 0) {
        pwVar6 = L"wince.htm#Windows_Explorer_Help";
      }
      else {
        pwVar6 = L"wince.htm";
      }
      CreateProcessW(L"\\windows\\peghelp.exe",pwVar6,(LPSECURITY_ATTRIBUTES)0x0,
                     (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,
                     (LPPROCESS_INFORMATION)0x0);
    }
  default:
switchD_0001c490_caseD_a018:
    if ((0xa0ff < uVar15) && (uVar15 < 0xa1c9)) {
      if (param_1[0x1f] == 0) {
        return 0;
      }
      pHVar11 = (HMENU)CommandBar_GetMenu(param_1[0x25],0);
      FUN_00020170((ushort *)param_1[0x1f],pHVar11,uVar15,(int *)param_1[10],param_1[0x13]);
      return 0;
    }
    if ((uVar15 < 0xe19) || (0xe73 < uVar15)) {
      if ((uVar15 < 0x1000) || (0x11ff < uVar15)) {
        return 1;
      }
      puVar12 = (undefined4 *)param_1[10];
      if (puVar12 == (undefined4 *)0x0) {
        return 0;
      }
      iVar4 = (**(code **)*puVar12)(puVar12,&DAT_00012100,local_70);
      if (iVar4 < 0) {
        return 0;
      }
      (**(code **)(*(int *)local_70[0] + 0x10))(local_70[0],&UNK_00011f5c,uVar15,0,0,0);
    }
    else {
      puVar12 = (undefined4 *)param_1[10];
      if (puVar12 == (undefined4 *)0x0) {
        return 0;
      }
      iVar4 = (**(code **)*puVar12)(puVar12,&DAT_00012100,local_70);
      if (iVar4 < 0) {
        return 0;
      }
      (**(code **)(*(int *)local_70[0] + 0x10))(local_70[0],&UNK_00012120,uVar15,0,0,0);
    }
    pwVar6 = local_70[0];
    pcVar13 = *(code **)(*(int *)local_70[0] + 8);
    break;
  case 0xa022:
    FUN_0001752c((int)param_1,(uint)((*(byte *)(param_1 + 0x4b) & 0x20) == 0));
LAB_0001c4e4:
    FUN_00017324((int)param_1);
    return 0;
  }
LAB_0001c90c:
  (*pcVar13)(pwVar6);
  return 0;
}



/* 0001c9b0 FUN_0001c9b0 */

/* Boundary evidence: original MIPS .pdata 0001c9b0..0001cf5f. Semantic name remains unreviewed. */

HANDLE FUN_0001c9b0(int *param_1,HWND param_2,uint param_3,HMENU param_4,HMENU param_5)

{
  LRESULT LVar1;
  HANDLE pvVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  HWND local_60 [2];
  tagRECT local_58;
  tagRECT local_48;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  if (param_1 != (int *)0x0) {
    if (param_3 < 0x2d) {
      if (param_3 == 0x2c) {
        if (param_1[0x1f] != 0) {
          pvVar2 = (HANDLE)FUN_0001f5fc(param_1[0x1f],(int)param_5);
          return pvVar2;
        }
      }
      else if (param_3 < 0x11) {
        if ((param_3 == 0x10) || (param_3 == 2)) {
          SetWindowLongW(param_2,-0x15,0);
          (**(code **)(*param_1 + 0x40))(param_1);
          PostQuitMessage(0);
        }
        else {
          if (param_3 != 3) {
            if (param_3 != 5) {
              if (param_3 == 6) {
                piVar4 = (int *)param_1[0xf];
                if (piVar4 != (int *)0x0) {
                  (**(code **)(*piVar4 + 0x18))(piVar4,((uint)param_4 & 0xffff) != 0);
                }
                return (HANDLE)0x0;
              }
              goto LAB_0001cc44;
            }
            GetClientRect((HWND)param_1[0x13],&local_58);
            FUN_00017324((int)param_1);
            if ((*(byte *)(param_1 + 0x4b) & 8) != 0) {
              GetClientRect((HWND)param_1[0x24],&local_48);
              if (local_48.right - local_48.left != local_58.right - local_58.left) {
                local_48.right = local_58.right;
                local_48.left = local_58.left;
                SetWindowPos((HWND)param_1[0x24],(HWND)0x0,local_58.left,local_48.top,
                             local_58.right - local_58.left,local_48.bottom - local_48.top,4);
              }
            }
            if (param_1[0x21] != 0) {
              LVar1 = SendMessageW((HWND)param_1[0x24],0x41b,0,0);
              local_58.top = LVar1 + local_58.top;
              FUN_0001db4c(param_1[0x21],(int)&local_58);
            }
            GetClientRect((HWND)param_1[0x28],&local_48);
            local_58.top = (local_58.bottom - local_48.bottom) + local_48.top;
            local_28 = local_58.right;
            local_2c = 0;
            if (-1 < local_58.right + -0x6e) {
              local_2c = local_58.right + -0x6e;
            }
            local_30 = 0;
            if (-1 < local_58.right + -0x82) {
              local_30 = local_58.right + -0x82;
            }
            local_34 = 0;
            if (-1 < local_58.right + -0x96) {
              local_34 = local_58.right + -0x96;
            }
            local_38 = 0;
            if (-1 < local_58.right + -0xfa) {
              local_38 = local_58.right + -0xfa;
            }
            SendMessageW((HWND)param_1[0x28],0x404,5,(LPARAM)&local_38);
            SetWindowPos((HWND)param_1[0x28],(HWND)0x0,local_58.left,local_58.top,
                         local_58.right - local_58.left,local_58.bottom - local_58.top,4);
            SendMessageW((HWND)param_1[0x28],0x40a,1,(LPARAM)&local_58);
            InflateRect(&local_58,-1,-1);
            SetWindowPos((HWND)param_1[0x2b],(HWND)0x0,local_38,local_58.top,0,0,5);
          }
          if ((*(byte *)(param_1 + 0x1b) & 2) == 0) {
            GetWindowRect(param_2,(LPRECT)(param_1 + 0x14));
          }
        }
      }
      else if (param_3 == 0x15) {
        SendMessageW((HWND)param_1[0x24],0x15,(WPARAM)param_4,(LPARAM)param_5);
        piVar4 = (int *)param_1[0xf];
        if ((piVar4 != (int *)0x0) &&
           (iVar3 = (**(code **)(*piVar4 + 0xc))(piVar4,local_60), iVar3 == 0)) {
          SendMessageW(local_60[0],0x15,(WPARAM)param_4,(LPARAM)param_5);
        }
      }
      else if (param_3 == 0x1a) {
        FUN_00018678((int)param_1,(WPARAM)param_4,(LPARAM)param_5);
      }
      else if ((param_3 == 0x2b) && ((ushort *)param_1[0x1f] != (ushort *)0x0)) {
        pvVar2 = (HANDLE)FUN_0001f7bc((ushort *)param_1[0x1f],(int)param_5);
        return pvVar2;
      }
    }
    else {
      if (param_3 == 0x4e) {
        pvVar2 = (HANDLE)FUN_000184a8((int)param_1,(int)param_4,&param_5->unused);
        return pvVar2;
      }
      if (param_3 == 0x53) {
        piVar4 = (int *)param_1[0xf];
        if (((piVar4 == (int *)0x0) ||
            (iVar3 = (**(code **)(*piVar4 + 0xc))(piVar4,local_60), iVar3 != 0)) ||
           (LVar1 = SendMessageW(local_60[0],0x53,(WPARAM)param_4,(LPARAM)param_5), LVar1 == 0)) {
          FUN_0001c0ac(param_1,0xa017);
        }
        return (HANDLE)0x1;
      }
      if (param_3 == 0x7f) {
        puVar5 = (undefined4 *)param_1[10];
        if ((puVar5 != (undefined4 *)0x0) &&
           (iVar3 = (**(code **)*puVar5)(puVar5,&DAT_00012100,local_60), -1 < iVar3)) {
          local_48.left = local_48.left & 0xffff0000;
          memset((void *)((int)&local_48.left + 2),0,0xe);
          iVar3 = (**(code **)(local_60[0]->unused + 0x10))
                            (local_60[0],&UNK_00012130,0x12,0,0,&local_48);
          (**(code **)(local_60[0]->unused + 8))();
          if (-1 < iVar3) {
            pvVar2 = LoadImageW(DAT_00035560,(LPCWSTR)0x6c,1,0x10,0x10,0);
            return pvVar2;
          }
        }
      }
      else {
        if (param_3 == 0x111) {
          pvVar2 = (HANDLE)FUN_0001c0ac(param_1,(uint)param_4);
          return pvVar2;
        }
        if (param_3 == 0x117) {
          FUN_0001e048((int)param_1,param_4);
        }
        else if (param_3 == 0x120) {
          if (param_1[0x1f] != 0) {
            pvVar2 = (HANDLE)FUN_0001fb0c(param_1[0x1f],param_5,(wint_t)param_4);
            return pvVar2;
          }
        }
        else if ((param_3 == 0x212) && ((*(byte *)(param_1 + 0x20) & 1) != 0)) {
          *(byte *)(param_1 + 0x20) = *(byte *)(param_1 + 0x20) & 0xfe;
        }
      }
    }
  }
LAB_0001cc44:
  pvVar2 = (HANDLE)DefWindowProcW(param_2,param_3,(WPARAM)param_4,(LPARAM)param_5);
  return pvVar2;
}



/* 0001cf60 FUN_0001cf60 */

/* Boundary evidence: original MIPS .pdata 0001cf60..0001cfaf. Semantic name remains unreviewed. */

undefined4 FUN_0001cf60(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(byte *)(param_1 + 0x12d) & 1) == 0) {
    uVar1 = FUN_0001b224(param_1,*(byte *)(param_1 + 0x6c) >> 1 & 1,&DAT_00011f6c,7,100);
  }
  return uVar1;
}



/* 0001cfb0 FUN_0001cfb0 */

/* Boundary evidence: original MIPS .pdata 0001cfb0..0001d07f. Semantic name remains unreviewed. */

void FUN_0001cfb0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00011df8;
  param_1[1] = &PTR_LAB_00011dd4;
  param_1[2] = &PTR_LAB_00011d98;
  param_1[3] = &PTR_LAB_00011d70;
  param_1[4] = &PTR_LAB_00011d60;
  param_1[5] = &PTR_LAB_00011d44;
  param_1[6] = &PTR_LAB_00011cfc;
  param_1[7] = &PTR_LAB_00011ce8;
  param_1[8] = &PTR_LAB_00011ccc;
  param_1[9] = &PTR_LAB_00011c84;
  if ((int *)param_1[10] != (int *)0x0) {
    (**(code **)(*(int *)param_1[10] + 8))();
  }
  if ((HANDLE)param_1[0xb] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0xb]);
    param_1[0xb] = 0;
  }
  return;
}



/* 0001d080 FUN_0001d080 */

/* Boundary evidence: original MIPS .pdata 0001d080..0001d0ef. Semantic name remains unreviewed. */

undefined4
FUN_0001d080(int param_1,undefined4 param_2,undefined4 param_3,LONG *param_4,LONG *param_5)

{
  tagRECT local_18;
  
  GetClientRect(*(HWND *)(param_1 + 0x44),&local_18);
  if (param_4 != (LONG *)0x0) {
    *param_4 = local_18.left;
    param_4[1] = local_18.top;
    param_4[2] = local_18.right;
    param_4[3] = local_18.bottom;
  }
  if (param_5 != (LONG *)0x0) {
    *param_5 = local_18.left;
    param_5[1] = local_18.top;
    param_5[2] = local_18.right;
    param_5[3] = local_18.bottom;
  }
  return 0;
}



/* 0001d0fc FUN_0001d0fc */

undefined4 FUN_0001d0fc(void)

{
  return 1;
}



/* 0001d104 FUN_0001d104 */

/* Boundary evidence: original MIPS .pdata 0001d104..0001d133. Semantic name remains unreviewed. */

void FUN_0001d104(undefined4 param_1,HWND param_2,UINT param_3,WPARAM param_4,LPARAM param_5)

{
  DefWindowProcW(param_2,param_3,param_4,param_5);
  return;
}



/* 0001d134 FUN_0001d134 */

/* Boundary evidence: original MIPS .pdata 0001d134..0001d257. Semantic name remains unreviewed. */

int FUN_0001d134(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_20;
  int *local_1c;
  
  puVar1 = (undefined4 *)param_1[10];
  local_20 = (int *)0x0;
  local_1c = (int *)0x0;
  if ((puVar1 == (undefined4 *)0x0) ||
     (iVar2 = (**(code **)*puVar1)(puVar1,&UNK_00012140,&local_20), iVar2 != 0)) {
    iVar2 = 1;
  }
  else {
    puVar1 = param_1 + 0xe;
    iVar2 = (**(code **)(*local_20 + 0x10))(local_20,&DAT_00011c64,puVar1);
    if (iVar2 == 0) {
      iVar2 = (**(code **)*param_1)(param_1,&DAT_00011c64,&local_1c);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*(int *)*puVar1 + 0x14))((int *)*puVar1,local_1c,param_1 + 0x11);
      }
    }
    else {
      *puVar1 = 0;
    }
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))();
    }
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))();
    }
  }
  return iVar2;
}



/* 0001d258 FUN_0001d258 */

/* Boundary evidence: original MIPS .pdata 0001d258..0001d2c7. Semantic name remains unreviewed. */

void FUN_0001d258(int param_1,int *param_2)

{
  tagRECT tStack_18;
  
  *(int **)(param_1 + 0x34) = param_2;
  (**(code **)(*param_2 + 4))(param_2);
  GetClientRect(*(HWND *)(param_1 + 0x4c),&tStack_18);
  (**(code **)(**(int **)(param_1 + 0x34) + 0x2c))
            (*(int **)(param_1 + 0x34),0xfffffffc,0,param_1 + 4,0,*(undefined4 *)(param_1 + 0x4c),
             &tStack_18);
  return;
}



/* 0001d2c8 FUN_0001d2c8 */

/* Boundary evidence: original MIPS .pdata 0001d2c8..0001d397. Semantic name remains unreviewed. */

void FUN_0001d2c8(int param_1)

{
  int *piVar1;
  
  SendMessageW(*(HWND *)(param_1 + 0x48),0x10,0,0);
  if (*(int **)(param_1 + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x3c) + 8))();
  }
  piVar1 = *(int **)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x18))(piVar1,*(undefined4 *)(param_1 + 0x44));
    (**(code **)(**(int **)(param_1 + 0x38) + 8))();
  }
  piVar1 = *(int **)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x18))(piVar1,0);
    (**(code **)(**(int **)(param_1 + 0x34) + 8))();
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x28) + 8))();
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}



/* 0001d398 FUN_0001d398 */

/* Boundary evidence: original MIPS .pdata 0001d398..0001d42b. Semantic name remains unreviewed. */

void FUN_0001d398(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  int *piVar1;
  
  piVar1 = (int *)GetWindowLongW(param_1,-0x15);
  if (piVar1 == (int *)0x0) {
    DefWindowProcW(param_1,param_2,param_3,param_4);
  }
  else {
    (**(code **)(*piVar1 + 0x44))(piVar1,param_1,param_2,param_3,param_4);
  }
  return;
}



/* 0001d42c FUN_0001d42c */

/* Boundary evidence: original MIPS .pdata 0001d42c..0001d4cf. Semantic name remains unreviewed. */

int FUN_0001d42c(void)

{
  ATOM AVar1;
  undefined2 extraout_var;
  WNDCLASSW local_30;
  
  if (DAT_000355d4 == 0) {
    local_30.style = 0;
    local_30.lpfnWndProc = FUN_0001d398;
    local_30.cbClsExtra = 0;
    local_30.cbWndExtra = 0;
    local_30.hInstance = DAT_00035560;
    local_30.hIcon = (HICON)0x0;
    local_30.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_30.hbrBackground = GetSysColorBrush(0x40000005);
    local_30.lpszMenuName = (LPCWSTR)0x0;
    local_30.lpszClassName = L"Explore";
    AVar1 = RegisterClassW(&local_30);
    if (CONCAT22(extraout_var,AVar1) != 0) {
      DAT_000355d4 = 1;
    }
  }
  return DAT_000355d4;
}



/* 0001d4d0 FUN_0001d4d0 */

/* Boundary evidence: original MIPS .pdata 0001d4d0..0001d51b. Semantic name remains unreviewed. */

undefined4 * FUN_0001d4d0(undefined4 *param_1,uint param_2)

{
  FUN_0001cfb0(param_1);
  if ((param_2 & 1) != 0) {
    LocalFree(param_1);
  }
  return param_1;
}



/* 0001d51c FUN_0001d51c */

/* Boundary evidence: original MIPS .pdata 0001d51c..0001d6ab. Semantic name remains unreviewed. */

undefined4 FUN_0001d51c(int *param_1,DWORD param_2)

{
  LANGID LVar1;
  int iVar2;
  HWND hWnd;
  ushort uVar3;
  DWORD dwExStyle;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  dwExStyle = 0;
  if (param_2 == 0) {
    param_2 = 0x10cf0000;
  }
  iVar2 = FUN_0001d42c();
  if (iVar2 != 0) {
    SystemParametersInfoW(0x30,0,&local_28,0);
    LVar1 = GetUserDefaultUILanguage();
    uVar3 = LVar1 & 0x3ff;
    if ((((uVar3 == 1) || (uVar3 == 0x29)) || (uVar3 == 0xd)) || (uVar3 == 0x20)) {
      dwExStyle = 0x400000;
    }
    hWnd = CreateWindowExW(dwExStyle,L"Explore",L"",param_2,local_28,local_24,local_20 - local_28,
                           local_1c - local_24,(HWND)0x0,(HMENU)0x0,DAT_00035560,(LPVOID)0x0);
    param_1[0x13] = (int)hWnd;
    if (hWnd != (HWND)0x0) {
      SetWindowLongW(hWnd,-0x15,(LONG)param_1);
      GetWindowRect((HWND)param_1[0x13],(LPRECT)(param_1 + 0x14));
      iVar2 = (**(code **)(*param_1 + 0x38))(param_1);
      if ((iVar2 != 0) && (iVar2 = (**(code **)(*param_1 + 0x3c))(param_1), iVar2 != 0)) {
        iVar2 = (**(code **)(*param_1 + 0x34))(param_1);
        param_1[0x12] = iVar2;
        if (iVar2 != 0) {
          SetFocus((HWND)param_1[0x13]);
          return 1;
        }
      }
    }
  }
  return 0;
}



/* 0001d6ac FUN_0001d6ac */

/* Boundary evidence: original MIPS .pdata 0001d6ac..0001d8ef. Semantic name remains unreviewed. */

undefined4 FUN_0001d6ac(int *param_1)

{
  HRESULT HVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  undefined4 local_18;
  uint local_14;
  
  piVar4 = param_1 + 10;
  local_24 = (int *)0x0;
  local_28 = (int *)0x0;
  if (*piVar4 != 0) goto LAB_0001d874;
  HVar1 = CoCreateInstance((IID *)&DAT_00011c24,(LPUNKNOWN)0x0,3,(IID *)&DAT_00012010,&local_24);
  if (HVar1 != 0) {
    return 0;
  }
  iVar2 = (**(code **)*local_24)(local_24,&UNK_00012160,&local_28);
  if ((iVar2 == 0) && (iVar2 = (**(code **)(*local_28 + 0x58))(local_28,1,&local_14), iVar2 == 0)) {
    if ((local_14 & 0x20000) == 0) {
LAB_0001d7c0:
      iVar2 = FUN_0001d258((int)param_1,local_28);
      if ((iVar2 == 0) &&
         (iVar2 = (*(code *)**(undefined4 **)param_1[0xd])
                            ((undefined4 *)param_1[0xd],&UNK_00011c44,piVar4), iVar2 == 0)) {
        (**(code **)(*param_1 + 0x2c))(param_1);
        iVar2 = (**(code **)*local_24)(local_24,&DAT_00012150,param_1 + 0xf);
        if (iVar2 != 0) {
          param_1[0xf] = 0;
        }
        FUN_0001d134(param_1);
      }
    }
    else {
      iVar2 = (**(code **)*param_1)(param_1,&DAT_000120d0,&local_1c);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*local_28 + 0xc))(local_28,local_1c);
        (**(code **)(*local_1c + 8))();
        if (iVar2 == 0) goto LAB_0001d7c0;
      }
    }
  }
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))();
  }
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))();
  }
LAB_0001d874:
  puVar3 = (undefined4 *)*piVar4;
  local_20 = (int *)0x0;
  local_18 = 0;
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)*puVar3)(puVar3,&DAT_000120a0,&local_20);
  if (iVar2 != 0) {
    return 0;
  }
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 0xc))(local_20,&local_18);
    (**(code **)(*local_20 + 8))();
    return local_18;
  }
  return local_18;
}



/* 0001d8f0 FUN_0001d8f0 */

undefined4 * FUN_0001d8f0(undefined4 *param_1)

{
  param_1[1] = &PTR_LAB_00011e50;
  param_1[2] = &PTR_LAB_00011e74;
  param_1[3] = &PTR_LAB_00011eb0;
  param_1[9] = &PTR_LAB_00011618;
  *param_1 = &PTR_FUN_00011df8;
  param_1[1] = &PTR_LAB_00011dd4;
  param_1[2] = &PTR_LAB_00011d98;
  param_1[3] = &PTR_LAB_00011d70;
  param_1[4] = &PTR_LAB_00011d60;
  param_1[5] = &PTR_LAB_00011d44;
  param_1[6] = &PTR_LAB_00011cfc;
  param_1[7] = &PTR_LAB_00011ce8;
  param_1[8] = &PTR_LAB_00011ccc;
  param_1[9] = &PTR_LAB_00011c84;
  param_1[0xc] = 1;
  param_1[0x13] = 0;
  param_1[10] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xb] = 0;
  return param_1;
}



/* 0001d9bc FUN_0001d9bc */

/* Boundary evidence: original MIPS .pdata 0001d9bc..0001dabf. Semantic name remains unreviewed. */

undefined4 * FUN_0001d9bc(undefined4 *param_1,undefined4 param_2)

{
  HBITMAP pHVar1;
  LSTATUS LVar2;
  HANDLE pvVar3;
  LPBYTE lpData;
  HKEY local_18;
  DWORD local_14;
  
  param_1[3] = 0;
  pHVar1 = LoadBitmapW(DAT_00035560,(LPCWSTR)0x34);
  local_14 = 4;
  param_1[4] = pHVar1;
  param_1[8] = 0;
  param_1[5] = param_2;
  local_18 = (HKEY)0x0;
  LVar2 = RegOpenKeyExW((HKEY)0x80000001,L"Software\\Microsoft\\Internet Explorer\\Main",0,0,
                        &local_18);
  if (LVar2 == 0) {
    lpData = (LPBYTE)(param_1 + 2);
    LVar2 = RegQueryValueExW(local_18,L"AnimationTicks",(LPDWORD)0x0,(LPDWORD)0x0,lpData,&local_14);
    if (LVar2 != 0) {
      lpData[0] = 'x';
      lpData[1] = '\0';
      lpData[2] = '\0';
      lpData[3] = '\0';
    }
    RegCloseKey(local_18);
  }
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *param_1 = pvVar3;
  param_1[7] = 0;
  return param_1;
}



/* 0001dac0 FUN_0001dac0 */

/* Boundary evidence: original MIPS .pdata 0001dac0..0001db4b. Semantic name remains unreviewed. */

void FUN_0001dac0(undefined4 *param_1)

{
  DeleteObject((HGDIOBJ)param_1[4]);
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
  }
  if ((HWND)param_1[6] != (HWND)0x0) {
    PostMessageW((HWND)param_1[6],0x10,0,0);
    if ((HANDLE)param_1[7] != (HANDLE)0x0) {
      WaitForSingleObject((HANDLE)param_1[7],5000);
      CloseHandle((HANDLE)param_1[7]);
    }
  }
  return;
}



/* 0001db4c FUN_0001db4c */

/* Boundary evidence: original MIPS .pdata 0001db4c..0001db87. Semantic name remains unreviewed. */

void FUN_0001db4c(int param_1,int param_2)

{
  SetWindowPos(*(HWND *)(param_1 + 0x18),(HWND)0x0,*(int *)(param_2 + 8) + -0x2a,
               *(int *)(param_2 + 4),0,0,0x15);
  return;
}



/* 0001db88 FUN_0001db88 */

/* Boundary evidence: original MIPS .pdata 0001db88..0001dc83. Semantic name remains unreviewed. */

void FUN_0001db88(int param_1)

{
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ h;
  LONG *lpAddend;
  
  if (*(int *)(param_1 + 0x20) != 0) {
    hdc = GetDC(*(HWND *)(param_1 + 0x18));
    hdc_00 = CreateCompatibleDC(hdc);
    h = SelectObject(hdc_00,*(HGDIOBJ *)(param_1 + 0x10));
    lpAddend = (LONG *)(param_1 + 0xc);
    BitBlt(hdc,0,0,0x16,0x16,hdc_00,*lpAddend * 0x16,0,0xcc0020);
    SelectObject(hdc_00,h);
    DeleteDC(hdc_00);
    ReleaseDC(*(HWND *)(param_1 + 0x18),hdc);
    InterlockedIncrement(lpAddend);
    if (*lpAddend == 0x19) {
      InterlockedExchange(lpAddend,0);
    }
  }
  return;
}



/* 0001dc84 FUN_0001dc84 */

/* Boundary evidence: original MIPS .pdata 0001dc84..0001dcd3. Semantic name remains unreviewed. */

void FUN_0001dc84(int param_1)

{
  SetWindowPos(*(HWND *)(param_1 + 0x18),(HWND)0x0,0,0,0,0,0x53);
  InterlockedExchange((LONG *)(param_1 + 0x20),1);
  return;
}



/* 0001dcd4 FUN_0001dcd4 */

/* Boundary evidence: original MIPS .pdata 0001dcd4..0001dd2f. Semantic name remains unreviewed. */

void FUN_0001dcd4(int param_1)

{
  InterlockedExchange((LONG *)(param_1 + 0x20),0);
  InterlockedExchange((LONG *)(param_1 + 0xc),0);
  SetWindowPos(*(HWND *)(param_1 + 0x18),(HWND)0x0,0,0,0,0,0x93);
  return;
}



/* 0001dd30 FUN_0001dd30 */

/* Boundary evidence: original MIPS .pdata 0001dd30..0001ddeb. Semantic name remains unreviewed. */

LRESULT FUN_0001dd30(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LONG LVar1;
  LRESULT LVar2;
  
  LVar1 = GetWindowLongW(param_1,-0x15);
  if (param_2 == 2) {
    SetWindowLongW(param_1,-0x15,0);
  }
  else if (param_2 == 0x113) {
    if (LVar1 == 0) {
      return 0;
    }
    FUN_0001db88(LVar1);
    return 0;
  }
  if (LVar1 == 0) {
    return 0;
  }
  LVar2 = CallWindowProcW(*(WNDPROC *)(LVar1 + 0x24),param_1,param_2,param_3,param_4);
  return LVar2;
}



/* 0001ddec FUN_0001ddec */

/* Boundary evidence: original MIPS .pdata 0001ddec..0001def7. Semantic name remains unreviewed. */

WPARAM FUN_0001ddec(undefined4 *param_1)

{
  HWND pHVar1;
  LONG LVar2;
  BOOL BVar3;
  MSG MStack_28;
  
  pHVar1 = CreateWindowExW(0,L"STATIC",(LPCWSTR)0x0,0x48000000,0,0,0x16,0x16,(HWND)param_1[5],
                           (HMENU)0x0,DAT_00035560,(LPVOID)0x0);
  param_1[6] = pHVar1;
  EventModify(*param_1,3);
  if ((HWND)param_1[6] == (HWND)0x0) {
    MStack_28.wParam = 0;
  }
  else {
    SetWindowLongW((HWND)param_1[6],-0x15,(LONG)param_1);
    LVar2 = SetWindowLongW((HWND)param_1[6],-4,0x1dd30);
    param_1[9] = LVar2;
    SetTimer((HWND)param_1[6],0x8176,param_1[2],(TIMERPROC)0x0);
    while ((BVar3 = GetMessageW(&MStack_28,(HWND)param_1[6],0,0), BVar3 != 0 &&
           (MStack_28.message != 0x12))) {
      TranslateMessage(&MStack_28);
      DispatchMessageW(&MStack_28);
    }
  }
  return MStack_28.wParam;
}



/* 0001def8 FUN_0001def8 */

/* Boundary evidence: original MIPS .pdata 0001def8..0001df13. Semantic name remains unreviewed. */

void FUN_0001def8(undefined4 *param_1)

{
  FUN_0001ddec(param_1);
  return;
}



/* 0001df14 FUN_0001df14 */

/* Boundary evidence: original MIPS .pdata 0001df14..0001df5b. Semantic name remains unreviewed. */

void FUN_0001df14(LPVOID param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001def8,param_1,0,
                        (LPDWORD)((int)param_1 + 4));
  *(HANDLE *)((int)param_1 + 0x1c) = pvVar1;
  return;
}



/* 0001df5c FUN_0001df5c */

/* Boundary evidence: original MIPS .pdata 0001df5c..0001e047. Semantic name remains unreviewed. */

undefined4 FUN_0001df5c(int param_1)

{
  undefined4 uVar1;
  int *local_20;
  int *local_1c;
  undefined2 local_18 [4];
  undefined4 local_10;
  
  local_20 = (int *)0x0;
  local_1c = (int *)0x0;
  if (*(int *)(param_1 + 0x28) == 0) {
    return 0;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + 0x28) + 0x48))(*(int **)(param_1 + 0x28),&local_20);
  if (local_20 != (int *)0x0) {
    uVar1 = (**(code **)*local_20)(local_20,&DAT_00012100,&local_1c);
    if (local_1c == (int *)0x0) goto LAB_0001e01c;
    local_18[0] = 3;
    local_10 = 0;
    uVar1 = (**(code **)(*local_1c + 0x10))(local_1c,0,0x20,1,0,local_18);
  }
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
LAB_0001e01c:
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))();
  }
  return uVar1;
}



/* 0001e048 FUN_0001e048 */

/* Boundary evidence: original MIPS .pdata 0001e048..0001e4db. Semantic name remains unreviewed. */

undefined4 FUN_0001e048(int param_1,HMENU param_2)

{
  HMENU pHVar1;
  UINT UVar2;
  HMENU pHVar3;
  HWND pHVar4;
  BOOL BVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  HWND hWnd;
  uint *puVar9;
  UINT uCheck;
  int *local_f0;
  int local_ec;
  int local_e8 [2];
  undefined4 local_e0;
  uint local_dc [5];
  undefined2 local_c8;
  undefined1 auStack_c6 [6];
  UINT_PTR local_c0;
  tagMENUITEMINFOW local_b8;
  WCHAR aWStack_88 [50];
  uint local_24;
  
  local_24 = DAT_00035518;
  pHVar1 = (HMENU)CommandBar_GetMenu(*(undefined4 *)(param_1 + 0x94),0);
  local_e0 = 0xb;
  local_dc[0] = 0;
  local_dc[1] = 0xc;
  local_dc[2] = 0;
  local_dc[3] = 0xd;
  local_dc[4] = 0;
  UVar2 = FUN_0001564c(pHVar1);
  FUN_00018064(param_1,param_2);
  pHVar3 = GetSubMenu(pHVar1,1);
  if (pHVar3 != param_2) {
    pHVar3 = GetSubMenu(pHVar1,2);
    if (pHVar3 == param_2) {
      uCheck = 8;
      UVar2 = 8;
      if ((*(byte *)(param_1 + 300) & 0x10) == 0) {
        UVar2 = 0;
      }
      CheckMenuItem(param_2,0x8081,UVar2);
      if ((*(byte *)(param_1 + 300) & 0x20) == 0) {
        uCheck = 0;
      }
      CheckMenuItem(param_2,0xa022,uCheck);
      if (*(int *)(param_1 + 0x28) != 0) {
        local_b8.cbSize = 0x2c;
        local_b8.fMask = 2;
        GetMenuItemInfoW(param_2,3,1,&local_b8);
        if ((local_b8.wID == 0xa000) &&
           (iVar6 = (**(code **)**(undefined4 **)(param_1 + 0x28))
                              (*(undefined4 **)(param_1 + 0x28),&DAT_00012100,&local_f0), -1 < iVar6
           )) {
          local_c8 = 0;
          memset(auStack_c6,0,0xe);
          iVar6 = (**(code **)(*local_f0 + 0x10))(local_f0,&UNK_00012130,0x1b,0,0,&local_c8);
          if (iVar6 == 0) {
            local_b8.dwTypeData = aWStack_88;
            local_b8.fMask = 0x10;
            local_b8.fType = 0;
            local_b8.cch = 0x32;
            GetMenuItemInfoW(param_2,1,1,&local_b8);
            pHVar1 = GetSubMenu(param_2,1);
            RemoveMenu(param_2,1,0x400);
            DestroyMenu(pHVar1);
            InsertMenuW(param_2,1,0x410,local_c0,aWStack_88);
          }
          (**(code **)(*local_f0 + 8))();
        }
      }
    }
    else {
      if ((((DAT_00035568 == 0) || (pHVar3 = GetSubMenu(pHVar1,UVar2 - 1), pHVar3 != param_2)) ||
          (pHVar3 = GetSubMenu(param_2,0), *(int *)(param_1 + 0x7c) == 0)) || (pHVar3 == (HMENU)0x0)
         ) {
        pHVar1 = GetSubMenu(pHVar1,UVar2 - 1);
        if ((*(ushort **)(param_1 + 0x7c) == (ushort *)0x0) || (pHVar1 != param_2)) {
          if ((*(byte *)(param_1 + 0x80) & 1) != 0) {
            FUN_00021110(*(ushort **)(param_1 + 0x7c),param_2);
          }
          goto LAB_0001e4ac;
        }
        UVar2 = FUN_000156c4(param_2,0);
        pHVar3 = param_2;
      }
      else {
        UVar2 = FUN_000156c4(pHVar3,0);
      }
      if ((UVar2 == 0x8172) || (UVar2 == 0x8170)) {
        FUN_00021200(*(ushort **)(param_1 + 0x7c),pHVar3);
        *(byte *)(param_1 + 0x80) = *(byte *)(param_1 + 0x80) | 1;
      }
    }
    goto LAB_0001e4ac;
  }
  hWnd = *(HWND *)(param_1 + 0xa8);
  pHVar4 = GetFocus();
  if (pHVar4 != hWnd) {
    puVar7 = *(undefined4 **)(param_1 + 0x28);
    if (puVar7 != (undefined4 *)0x0) {
      iVar6 = (**(code **)*puVar7)(puVar7,&DAT_00012100,&local_f0);
      if (-1 < iVar6) {
        (**(code **)(*local_f0 + 0xc))(local_f0,0,3,&local_e0,0);
        (**(code **)(*local_f0 + 8))();
      }
      uVar8 = 0;
      puVar9 = local_dc;
      do {
        EnableMenuItem(param_2,uVar8 + 0xa00b,(uint)((*puVar9 & 2) == 0));
        uVar8 = uVar8 + 1;
        puVar9 = puVar9 + 2;
      } while (uVar8 < 3);
    }
    goto LAB_0001e4ac;
  }
  SendMessageW(hWnd,0xb0,(WPARAM)local_e8,(LPARAM)&local_ec);
  if (local_ec == local_e8[0]) {
    EnableMenuItem(param_2,0xa00b,1);
  }
  else {
    EnableMenuItem(param_2,0xa00b,0);
  }
  EnableMenuItem(param_2,0xa00c,(uint)(local_ec == local_e8[0]));
  BVar5 = IsClipboardFormatAvailable(0xd);
  if (BVar5 == 0) {
    BVar5 = IsClipboardFormatAvailable(1);
    UVar2 = 1;
    if (BVar5 != 0) goto LAB_0001e16c;
  }
  else {
LAB_0001e16c:
    UVar2 = 0;
  }
  EnableMenuItem(param_2,0xa00d,UVar2);
LAB_0001e4ac:
  FUN_00033770(local_24);
  return 1;
}



/* 0001e4dc FUN_0001e4dc */

void FUN_0001e4dc(void)

{
  return;
}



/* 0001e4e4 FUN_0001e4e4 */

/* Boundary evidence: original MIPS .pdata 0001e4e4..0001e51b. Semantic name remains unreviewed. */

bool FUN_0001e4e4(int param_1,short param_2)

{
  if (param_2 == -0x5ff7) {
    FUN_0001df5c(param_1);
  }
  return param_2 != -0x5ff7;
}



/* 0001e55c FUN_0001e55c */

/* Boundary evidence: original MIPS .pdata 0001e55c..0001e58b. Semantic name remains unreviewed. */

undefined4 FUN_0001e55c(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_000355d8);
  DAT_000355fc = 1;
  return 1;
}



/* 0001e58c FUN_0001e58c */

/* Boundary evidence: original MIPS .pdata 0001e58c..0001e5bb. Semantic name remains unreviewed. */

undefined4 FUN_0001e58c(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_000355d8);
  DAT_000355fc = 0;
  return 1;
}



/* 0001e5bc FUN_0001e5bc */

/* Boundary evidence: original MIPS .pdata 0001e5bc..0001e673. Semantic name remains unreviewed. */

undefined4 FUN_0001e5bc(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_000355fc == 0) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_000355d8);
    if (DAT_000355ec == (HMODULE)0x0) {
      DAT_000355ec = LoadLibraryW(L"aygshell.dll");
      if (DAT_000355ec != (HMODULE)0x0) {
        DAT_000355f8 = DAT_000355f8 + 1;
        uVar1 = 1;
        DAT_000355f4 = 1;
      }
    }
    else {
      DAT_000355f8 = DAT_000355f8 + 1;
      uVar1 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_000355d8);
  }
  return uVar1;
}



/* 0001e674 FUN_0001e674 */

/* Boundary evidence: original MIPS .pdata 0001e674..0001e71b. Semantic name remains unreviewed. */

undefined4 FUN_0001e674(void)

{
  undefined4 uVar1;
  
  if ((DAT_000355fc == 0) || (DAT_000355f4 == 0)) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_000355d8);
    DAT_000355f8 = DAT_000355f8 + -1;
    if (DAT_000355f8 < 1) {
      FreeLibrary(DAT_000355ec);
      DAT_000355ec = (HMODULE)0x0;
      DAT_000355f0 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_000355d8);
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001e71c FUN_0001e71c */

/* Boundary evidence: original MIPS .pdata 0001e71c..0001e7df. Semantic name remains unreviewed. */

undefined4 FUN_0001e71c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = 0;
  uVar3 = 0;
  memset(&local_1c,0,8);
  if ((DAT_000355fc != 0) && (iVar1 = FUN_0001e5bc(), iVar1 != 0)) {
    local_20 = 1;
    local_1c = param_1;
    local_18 = param_2;
    pcVar2 = (code *)GetProcAddressW(DAT_000355ec,L"SHInitDialog");
    if (pcVar2 != (code *)0x0) {
      uVar3 = (*pcVar2)(&local_20);
    }
    iVar1 = FUN_0001e674();
    if (iVar1 != 0) {
      return uVar3;
    }
  }
  return 0;
}



/* 0001e7e0 FUN_0001e7e0 */

/* Boundary evidence: original MIPS .pdata 0001e7e0..0001e873. Semantic name remains unreviewed. */

int FUN_0001e7e0(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = DAT_000355f0;
  if ((DAT_000355fc == 0) || (DAT_000355ec == 0)) {
    iVar3 = 0;
  }
  else if (DAT_000355f0 == 0) {
    pcVar2 = (code *)GetProcAddressW(DAT_000355ec,L"SHInitExtraControls");
    iVar1 = iVar3;
    if (pcVar2 != (code *)0x0) {
      iVar3 = (*pcVar2)();
      iVar1 = iVar3;
    }
  }
  else {
    iVar3 = 1;
  }
  DAT_000355f0 = iVar1;
  return iVar3;
}



/* 0001e874 FUN_0001e874 */

/* Boundary evidence: original MIPS .pdata 0001e874..0001e93b. Semantic name remains unreviewed. */

undefined4 FUN_0001e874(HWND param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  tagWNDCLASSW tStack_38;
  
  if ((((DAT_000355fc == 0) || (DAT_000355ec == (HINSTANCE)0x0)) ||
      (iVar1 = FUN_0001e7e0(), iVar1 == 0)) ||
     (BVar2 = GetClassInfoW(DAT_000355ec,L"SIPPREF",&tStack_38), BVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    CreateWindowExW(0,L"SIPPREF",(LPCWSTR)0x0,0x40000000,-10,-10,5,5,param_1,(HMENU)0x0,DAT_000355ec
                    ,(LPVOID)0x0);
    uVar3 = 1;
  }
  return uVar3;
}



/* 0001e93c FUN_0001e93c */

/* Boundary evidence: original MIPS .pdata 0001e93c..0001eaa7. Semantic name remains unreviewed. */

int FUN_0001e93c(undefined4 *param_1,int param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  BOOL BVar3;
  DWORD nNumberOfBytesToRead;
  uint uVar4;
  uint uVar5;
  int iVar6;
  DWORD local_28 [2];
  
  local_28[0] = 0;
  iVar6 = 0;
  uVar5 = param_3 - 1;
  if ((param_2 != 0) && (param_3 != 0)) {
    for (; uVar5 != 0; uVar5 = uVar5 - local_28[0]) {
      nNumberOfBytesToRead = 100;
      if (uVar5 < 0x65) {
        nNumberOfBytesToRead = uVar5;
      }
      BVar3 = ReadFile((HANDLE)*param_1,(LPVOID)(iVar6 + param_2),nNumberOfBytesToRead,local_28,
                       (LPOVERLAPPED)0x0);
      if ((BVar3 == 0) || (local_28[0] == 0)) {
        *(undefined1 *)(iVar6 + param_2) = 0;
        return iVar6;
      }
      bVar2 = false;
      uVar4 = 0;
      if (local_28[0] != 0) {
        do {
          cVar1 = *(char *)(iVar6 + param_2 + uVar4);
          if (cVar1 == '\r') {
            bVar2 = true;
          }
          else {
            if ((cVar1 == '\n') && (bVar2)) {
              *(undefined1 *)(uVar4 + iVar6 + param_2 + -1) = 0;
              SetFilePointer((HANDLE)*param_1,(uVar4 - local_28[0]) + 1,(PLONG)0x0,1);
              return local_28[0] + iVar6;
            }
            bVar2 = false;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < local_28[0]);
      }
      iVar6 = local_28[0] + iVar6;
    }
    *(undefined1 *)(param_2 + param_3 + -1) = 0;
  }
  return iVar6;
}



/* 0001eaa8 FUN_0001eaa8 */

/* Boundary evidence: original MIPS .pdata 0001eaa8..0001eceb. Semantic name remains unreviewed. */

DWORD FUN_0001eaa8(int *param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  int iVar1;
  size_t sVar2;
  char *hMem;
  DWORD DVar3;
  wchar_t *lpWideCharStr;
  char *_Str;
  UINT CodePage;
  DWORD dwFlags;
  
  DVar3 = 0x80004005;
  lpWideCharStr = (wchar_t *)0x0;
  hMem = (char *)0x0;
  if (*param_1 != -1) {
    if ((param_2 == (STRSAFE_LPWSTR)0x0) || (param_3 == 0)) {
      DVar3 = 0x80070057;
    }
    else {
      hMem = LocalAlloc(0,0x805);
      if ((hMem == (char *)0x0) ||
         (lpWideCharStr = LocalAlloc(0,0x100a), lpWideCharStr == (wchar_t *)0x0)) {
        DVar3 = 0x8007000e;
      }
      else {
        iVar1 = FUN_0001e93c(param_1,(int)hMem,0x805);
        if (iVar1 != 0) {
          if (((*hMem == -0x11) && (hMem[1] == -0x45)) && (hMem[2] == -0x41)) {
            CodePage = 0xfde9;
            dwFlags = 0;
            _Str = hMem + 3;
          }
          else {
            CodePage = 0;
            dwFlags = 1;
            _Str = hMem;
          }
          do {
            sVar2 = strlen(_Str);
            iVar1 = MultiByteToWideChar(CodePage,dwFlags,_Str,sVar2 + 1,lpWideCharStr,0x805);
            if (iVar1 == 0) {
              DVar3 = GetLastError();
              if ((int)DVar3 < 1) {
                DVar3 = GetLastError();
              }
              else {
                DVar3 = GetLastError();
                DVar3 = DVar3 & 0xffff | 0x80070000;
              }
              break;
            }
            lpWideCharStr[iVar1] = L'\0';
            iVar1 = wcsncmp(lpWideCharStr,L"URL=",4);
            if (iVar1 == 0) {
              DVar3 = StringCchCopyW(param_2,param_3,lpWideCharStr + 4);
              break;
            }
            iVar1 = FUN_0001e93c(param_1,(int)hMem,0x805);
            _Str = hMem;
          } while (iVar1 != 0);
        }
      }
    }
    if (hMem != (char *)0x0) {
      LocalFree(hMem);
    }
    if (lpWideCharStr != (wchar_t *)0x0) {
      LocalFree(lpWideCharStr);
    }
  }
  return DVar3;
}



/* 0001ecec FUN_0001ecec */

/* Boundary evidence: original MIPS .pdata 0001ecec..0001f02f. Semantic name remains unreviewed. */

DWORD FUN_0001ecec(int *param_1,int param_2)

{
  STRSAFE_PCNZWCH pszDest;
  SIZE_T cbMultiByte;
  int iVar1;
  BOOL BVar2;
  SIZE_T uBytes;
  LPSTR pCVar3;
  DWORD nNumberOfBytesToWrite;
  DWORD DVar4;
  LPSTR lpMultiByteStr;
  size_t local_30;
  DWORD DStack_2c;
  
  lpMultiByteStr = (LPSTR)0x0;
  if (*param_1 == -1) {
    DVar4 = 0x80004005;
  }
  else if (param_2 == 0) {
    DVar4 = 0x80070057;
  }
  else {
    pszDest = LocalAlloc(0,0x100a);
    if (pszDest == (STRSAFE_PCNZWCH)0x0) {
LAB_0001ee08:
      DVar4 = 0x8007000e;
    }
    else {
      DVar4 = StringCchPrintfW(pszDest,0x805,L"%s%s",L"[InternetShortcut]",&DAT_00012208);
      if (((int)DVar4 < 0) || (DVar4 = StringCchLengthW(pszDest,0x805,&local_30), (int)DVar4 < 0))
      goto LAB_0001efa8;
      cbMultiByte = WideCharToMultiByte(0xfde9,0,pszDest,local_30,(LPSTR)0x0,0,(LPCSTR)0x0,
                                        (LPBOOL)0x0);
      lpMultiByteStr = LocalAlloc(0,cbMultiByte + 3);
      if (lpMultiByteStr == (LPSTR)0x0) goto LAB_0001ee08;
      *lpMultiByteStr = -0x11;
      lpMultiByteStr[1] = -0x45;
      lpMultiByteStr[2] = -0x41;
      iVar1 = WideCharToMultiByte(0xfde9,0,pszDest,local_30,lpMultiByteStr + 3,cbMultiByte,
                                  (LPCSTR)0x0,(LPBOOL)0x0);
      if (iVar1 != 0) {
        BVar2 = WriteFile((HANDLE)*param_1,lpMultiByteStr,iVar1 + 3,&DStack_2c,(LPOVERLAPPED)0x0);
        if (BVar2 != 0) {
          DVar4 = StringCchPrintfW(pszDest,0x805,L"%s%s",L"URL=",param_2);
          if (((int)DVar4 < 0) ||
             (DVar4 = StringCchLengthW(pszDest,0x805,&local_30), (int)DVar4 < 0)) goto LAB_0001efa8;
          uBytes = WideCharToMultiByte(0xfde9,0,pszDest,local_30,(LPSTR)0x0,0,(LPCSTR)0x0,
                                       (LPBOOL)0x0);
          pCVar3 = LocalReAlloc(lpMultiByteStr,uBytes,0);
          if (pCVar3 != (LPSTR)0x0) {
            lpMultiByteStr = pCVar3;
            cbMultiByte = uBytes;
          }
          nNumberOfBytesToWrite =
               WideCharToMultiByte(0xfde9,0,pszDest,local_30,lpMultiByteStr,cbMultiByte,(LPCSTR)0x0,
                                   (LPBOOL)0x0);
          if (nNumberOfBytesToWrite != 0) {
            BVar2 = WriteFile((HANDLE)*param_1,lpMultiByteStr,nNumberOfBytesToWrite,&DStack_2c,
                              (LPOVERLAPPED)0x0);
            if (BVar2 != 0) goto LAB_0001efa8;
          }
        }
      }
      DVar4 = GetLastError();
      if ((int)DVar4 < 1) {
        DVar4 = GetLastError();
      }
      else {
        DVar4 = GetLastError();
        DVar4 = DVar4 & 0xffff | 0x80070000;
      }
    }
LAB_0001efa8:
    if (pszDest != (STRSAFE_PCNZWCH)0x0) {
      LocalFree(pszDest);
    }
    if (lpMultiByteStr != (LPSTR)0x0) {
      LocalFree(lpMultiByteStr);
    }
    if (-1 < (int)DVar4) goto LAB_0001efec;
  }
  SetFilePointer((HANDLE)*param_1,0,(PLONG)0x0,0);
LAB_0001efec:
  SetEndOfFile((HANDLE)*param_1);
  return DVar4;
}



/* 0001f030 FUN_0001f030 */

/* Boundary evidence: original MIPS .pdata 0001f030..0001f07f. Semantic name remains unreviewed. */

void FUN_0001f030(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)*param_1);
  }
  *param_1 = 0xffffffff;
  return;
}



/* 0001f080 FUN_0001f080 */

/* Boundary evidence: original MIPS .pdata 0001f080..0001f16f. Semantic name remains unreviewed. */

DWORD FUN_0001f080(int *param_1,LPCWSTR param_2,int param_3)

{
  HANDLE pvVar1;
  DWORD dwDesiredAccess;
  DWORD dwCreationDisposition;
  DWORD DVar2;
  
  DVar2 = 0;
  if (*param_1 != -1) {
    FUN_0001f030(param_1);
  }
  if (param_3 == 0) {
    dwDesiredAccess = 0x80000000;
    dwCreationDisposition = 3;
  }
  else {
    dwDesiredAccess = 0x40000000;
    dwCreationDisposition = 1;
  }
  pvVar1 = CreateFileW(param_2,dwDesiredAccess,0,(LPSECURITY_ATTRIBUTES)0x0,dwCreationDisposition,
                       0x80,(HANDLE)0x0);
  *param_1 = (int)pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    DVar2 = GetLastError();
    if ((int)DVar2 < 1) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = GetLastError();
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
  }
  return DVar2;
}



/* 0001f170 FUN_0001f170 */

int FUN_0001f170(int param_1)

{
  if (param_1 < 0x3d) {
    if (((param_1 != 0x3c) && (param_1 != 0x22)) && (param_1 != 0x2a)) {
      if (param_1 < 0x2e) {
        return param_1;
      }
      if (param_1 < 0x30) {
        return 0x5f;
      }
      if (param_1 != 0x3a) {
        return param_1;
      }
    }
  }
  else {
    if (param_1 < 0x3e) {
      return param_1;
    }
    if (0x3f < param_1) {
      if (param_1 == 0x5c) {
        return 0x5f;
      }
      if (param_1 != 0x7c) {
        return param_1;
      }
    }
  }
  return 0x20;
}



/* 0001f214 FUN_0001f214 */

/* Boundary evidence: original MIPS .pdata 0001f214..0001f27b. Semantic name remains unreviewed. */

undefined4 * FUN_0001f214(undefined4 *param_1,uint param_2)

{
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0001f27c FUN_0001f27c */

/* Boundary evidence: original MIPS .pdata 0001f27c..0001f3a3. Semantic name remains unreviewed. */

HMENU FUN_0001f27c(undefined4 param_1,int param_2)

{
  LPCWSTR lpNewItem;
  size_t sVar1;
  STRSAFE_LPWSTR pszDest;
  HRESULT HVar2;
  BOOL BVar3;
  uint uVar4;
  HMENU hMenu;
  uint cchDest;
  
  hMenu = (HMENU)0x0;
  lpNewItem = operator_new(0x10);
  if (lpNewItem == (LPCWSTR)0x0) {
    lpNewItem = (LPCWSTR)0x0;
  }
  else {
    lpNewItem[0] = L'\0';
    lpNewItem[1] = L'\0';
    lpNewItem[2] = L'\0';
    lpNewItem[3] = L'\0';
    lpNewItem[4] = L'\0';
    lpNewItem[5] = L'\0';
    lpNewItem[6] = L'\0';
    lpNewItem[7] = L'\0';
  }
  if (lpNewItem == (LPCWSTR)0x0) {
    return (HMENU)0x0;
  }
  if (param_2 != 0) {
    sVar1 = wcslen(*(wchar_t **)(param_2 + 4));
    cchDest = sVar1 + 1;
    lpNewItem[0] = L'\0';
    lpNewItem[1] = L'\0';
    if (cchDest < 0x80000000) {
      uVar4 = cchDest * 2;
    }
    else {
      uVar4 = 0xffffffff;
    }
    pszDest = operator_new(uVar4);
    *(STRSAFE_LPWSTR *)(lpNewItem + 2) = pszDest;
    if ((pszDest == (STRSAFE_LPWSTR)0x0) ||
       (HVar2 = StringCchCopyW(pszDest,cchDest,*(STRSAFE_LPCWSTR *)(param_2 + 4)), HVar2 != 0))
    goto LAB_0001f364;
  }
  hMenu = CreatePopupMenu();
  if ((hMenu != (HMENU)0x0) && (BVar3 = InsertMenuW(hMenu,0,0x500,0xfffe,lpNewItem), BVar3 != 0)) {
    return hMenu;
  }
LAB_0001f364:
  FUN_0001f214((undefined4 *)lpNewItem,1);
  if (hMenu != (HMENU)0x0) {
    DestroyMenu(hMenu);
  }
  return (HMENU)0x0;
}



/* 0001f3a4 FUN_0001f3a4 */

/* Boundary evidence: original MIPS .pdata 0001f3a4..0001f42b. Semantic name remains unreviewed. */

BOOL FUN_0001f3a4(undefined4 param_1,HMENU param_2)

{
  int iVar1;
  BOOL BVar2;
  WCHAR aWStack_d8 [100];
  uint local_10;
  
  local_10 = DAT_00035518;
  iVar1 = LoadStringW(DAT_00035560,0x4e24,aWStack_d8,100);
  if (iVar1 == 0) {
    FUN_00033770(local_10);
    BVar2 = 0;
  }
  else {
    BVar2 = InsertMenuW(param_2,0,0x401,0xffff,aWStack_d8);
    FUN_00033770(local_10);
  }
  return BVar2;
}



/* 0001f42c FUN_0001f42c */

/* Boundary evidence: original MIPS .pdata 0001f42c..0001f47f. Semantic name remains unreviewed. */

ULONG_PTR FUN_0001f42c(undefined4 param_1,HMENU param_2,UINT param_3,BOOL param_4)

{
  BOOL BVar1;
  tagMENUITEMINFOW local_38;
  
  local_38.cbSize = 0x2c;
  local_38.fMask = 0x20;
  BVar1 = GetMenuItemInfoW(param_2,param_3,param_4,&local_38);
  if (BVar1 == 0) {
    local_38.dwItemData = 0;
  }
  return local_38.dwItemData;
}



/* 0001f480 FUN_0001f480 */

/* Boundary evidence: original MIPS .pdata 0001f480..0001f4cf. Semantic name remains unreviewed. */

HMENU FUN_0001f480(undefined4 param_1,HMENU param_2,UINT param_3)

{
  BOOL BVar1;
  tagMENUITEMINFOW local_38;
  
  local_38.cbSize = 0x2c;
  local_38.fMask = 4;
  BVar1 = GetMenuItemInfoW(param_2,param_3,1,&local_38);
  if (BVar1 == 0) {
    local_38.hSubMenu = (HMENU)0x0;
  }
  return local_38.hSubMenu;
}



/* 0001f4d0 FUN_0001f4d0 */

/* Boundary evidence: original MIPS .pdata 0001f4d0..0001f55b. Semantic name remains unreviewed. */

int FUN_0001f4d0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_2[2] & 0x10) != 0) {
    if ((param_3[2] & 0x10) == 0) {
      return -1;
    }
    if ((param_2[2] & 0x10) != 0) goto LAB_0001f520;
  }
  if ((param_3[2] & 0x10) != 0) {
    return 1;
  }
LAB_0001f520:
  iVar1 = CompareStringW(0x800,1,(PCNZWCH)*param_2,-1,(PCNZWCH)*param_3,-1);
  return iVar1 + -2;
}



/* 0001f55c FUN_0001f55c */

/* Boundary evidence: original MIPS .pdata 0001f55c..0001f5fb. Semantic name remains unreviewed. */

void FUN_0001f55c(undefined4 param_1,HMENU param_2)

{
  undefined4 *puVar1;
  HMENU pHVar2;
  BOOL BVar3;
  
  if (param_2 != (HMENU)0x0) {
    while( true ) {
      puVar1 = (undefined4 *)FUN_0001f42c(param_1,param_2,0,1);
      pHVar2 = FUN_0001f480(param_1,param_2,0);
      FUN_0001f55c(param_1,pHVar2);
      BVar3 = RemoveMenu(param_2,0,0x400);
      if (BVar3 == 0) break;
      if (puVar1 != (undefined4 *)0x0) {
        FUN_0001f214(puVar1,1);
      }
    }
  }
  return;
}



/* 0001f5fc FUN_0001f5fc */

/* Boundary evidence: original MIPS .pdata 0001f5fc..0001f7bb. Semantic name remains unreviewed. */

undefined4 FUN_0001f5fc(undefined4 param_1,int param_2)

{
  int iVar1;
  HDC hdc;
  size_t cchString;
  int *piVar2;
  wchar_t *_Str;
  tagSIZE local_f0;
  WCHAR local_e8 [100];
  uint local_20;
  
  local_20 = DAT_00035518;
  piVar2 = *(int **)(param_2 + 0x14);
  if (((short)piVar2[3] == 0) || (*(ushort *)((int)piVar2 + 0xe) == 0)) {
    local_f0.cx = 0x5e;
    local_f0.cy = 0;
    if (*(int *)(param_2 + 8) == 0) {
      *(undefined4 *)(param_2 + 0x10) = 7;
    }
    else {
      iVar1 = GetSystemMetrics(0x32);
      *(int *)(param_2 + 0x10) = iVar1 + 6;
    }
    if (*(int *)(param_2 + 8) == 0xffff) {
      iVar1 = LoadStringW(DAT_00035560,0x4e24,local_e8,100);
      if (iVar1 == 0) {
        local_e8[0] = L'\0';
      }
      _Str = local_e8;
    }
    else {
      _Str = L"";
      if ((wchar_t *)*piVar2 != (wchar_t *)0x0) {
        _Str = (wchar_t *)*piVar2;
      }
    }
    hdc = GetDC((HWND)0x0);
    if (hdc != (HDC)0x0) {
      cchString = wcslen(_Str);
      GetTextExtentExPointW(hdc,_Str,cchString,200,(LPINT)0x0,(LPINT)0x0,&local_f0);
      if (200 < local_f0.cx) {
        local_f0.cx = 200;
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    iVar1 = GetSystemMetrics(0x32);
    if (iVar1 < local_f0.cy) {
      *(LONG *)(param_2 + 0x10) = local_f0.cy + 10;
    }
    iVar1 = GetSystemMetrics(0x31);
    *(int *)(param_2 + 0xc) = iVar1 + local_f0.cx + 0x10;
    if (*piVar2 != 0) {
      *(short *)((int)piVar2 + 0xe) = (short)*(undefined4 *)(param_2 + 0x10);
      *(short *)(piVar2 + 3) = (short)*(undefined4 *)(param_2 + 0xc);
    }
  }
  else {
    *(uint *)(param_2 + 0x10) = (uint)*(ushort *)((int)piVar2 + 0xe);
    *(uint *)(param_2 + 0xc) = (uint)*(ushort *)(piVar2 + 3);
  }
  FUN_00033770(local_20);
  return 1;
}



/* 0001f7bc FUN_0001f7bc */

/* Boundary evidence: original MIPS .pdata 0001f7bc..0001fb0b. Semantic name remains unreviewed. */

undefined4 FUN_0001f7bc(ushort *param_1,int param_2)

{
  DWORD DVar1;
  HBRUSH hbr;
  HIMAGELIST himl;
  size_t sVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  RECT local_3d0;
  tagRECT local_3c0;
  POINT local_3b0;
  int local_3a8;
  int local_3a4;
  undefined1 auStack_3a0 [4];
  int local_39c;
  WCHAR aWStack_e8 [100];
  uint local_20;
  
  local_20 = DAT_00035518;
  if ((param_2 == 0) || (puVar6 = *(undefined4 **)(param_2 + 0x2c), puVar6 == (undefined4 *)0x0)) {
    FUN_00033770(DAT_00035518);
    uVar7 = 0;
  }
  else {
    local_3d0.left = *(int *)(param_2 + 0x1c);
    local_3d0.top = *(int *)(param_2 + 0x20);
    local_3d0.right = *(int *)(param_2 + 0x24);
    local_3d0.bottom = *(LONG *)(param_2 + 0x28);
    if ((*(uint *)(param_2 + 0xc) != 0) && (*(uint *)(param_2 + 0xc) < 3)) {
      if (((*(uint *)(param_2 + 0x10) & 1) == 0) || (*(int *)(param_2 + 8) == 0)) {
        DVar1 = GetSysColor(0x40000004);
        hbr = CreateSolidBrush(DVar1);
        iVar3 = 0x40000007;
      }
      else {
        DVar1 = GetSysColor(0x4000000d);
        hbr = CreateSolidBrush(DVar1);
        iVar3 = 0x4000000e;
      }
      DVar1 = GetSysColor(iVar3);
      SetTextColor(*(HDC *)(param_2 + 0x18),DVar1);
      FillRect(*(HDC *)(param_2 + 0x18),&local_3d0,hbr);
      DeleteObject(hbr);
    }
    uVar5 = *(uint *)(param_2 + 8);
    uVar7 = 1;
    local_3c0.bottom = local_3d0.bottom;
    local_3c0.left = local_3d0.left;
    local_3c0.top = local_3d0.top;
    local_3c0.right = local_3d0.right;
    if (uVar5 == 0) {
      local_3b0.y = local_3d0.top + 3;
      local_3a8 = local_3d0.right + -3;
      local_3b0.x = local_3d0.left;
      local_3a4 = local_3b0.y;
      Polyline(*(HDC *)(param_2 + 0x18),&local_3b0,2);
    }
    else if ((uVar5 == 0xffff) || (uVar5 == 0xfffe)) {
      iVar3 = LoadStringW(DAT_00035560,0x4e24,aWStack_e8,100);
      if (iVar3 != 0) {
        sVar2 = wcslen(aWStack_e8);
        DrawTextW(*(HDC *)(param_2 + 0x18),aWStack_e8,sVar2,&local_3c0,0x124);
      }
    }
    else if (((uVar5 < 0xa100) || (0xa1c8 < uVar5)) && ((puVar6[2] & 0x10) == 0)) {
      local_3c0.left = local_3d0.left + 0x18;
      pwVar4 = (wchar_t *)*puVar6;
      if (pwVar4 != (wchar_t *)0x0) {
        sVar2 = wcslen(pwVar4);
        DrawTextW(*(HDC *)(param_2 + 0x18),pwVar4,sVar2,&local_3c0,0x8124);
      }
    }
    else {
      if (*param_1 < uVar5) {
        if ((puVar6[2] & 0x10) == 0) {
          pwVar4 = L"foo.htm";
        }
        else {
          pwVar4 = L"\foo";
        }
      }
      else {
        pwVar4 = (wchar_t *)puVar6[1];
      }
      himl = (HIMAGELIST)SHGetFileInfo(pwVar4,puVar6[2],auStack_3a0,0x2b4,0x4011);
      SetBkMode(*(HDC *)(param_2 + 0x18),1);
      if (himl != (HIMAGELIST)0x0) {
        ImageList_Draw(himl,local_39c,*(HDC *)(param_2 + 0x18),local_3d0.left + 4,local_3d0.top + 3,
                       0);
      }
      local_3c0.left = local_3c0.left + 0x18;
      local_3c0.right = local_3c0.right + -8;
      pwVar4 = (wchar_t *)*puVar6;
      if (pwVar4 != (wchar_t *)0x0) {
        sVar2 = wcslen(pwVar4);
        DrawTextW(*(HDC *)(param_2 + 0x18),pwVar4,sVar2,&local_3c0,0x8924);
      }
    }
    FUN_00033770(local_20);
  }
  return uVar7;
}



/* 0001fb0c FUN_0001fb0c */

/* Boundary evidence: original MIPS .pdata 0001fb0c..0001fc2f. Semantic name remains unreviewed. */

undefined4 FUN_0001fb0c(undefined4 param_1,HMENU param_2,wint_t param_3)

{
  wint_t wVar1;
  undefined2 extraout_var;
  BOOL BVar2;
  wchar_t *pwVar3;
  int iVar4;
  undefined4 uVar5;
  tagMENUITEMINFOW local_40;
  
  uVar5 = 0;
  wVar1 = towlower(param_3);
  memset(&local_40.fMask,0,0x28);
  local_40.cbSize = 0x2c;
  local_40.fMask = 0x22;
  BVar2 = GetMenuItemInfoW(param_2,0,1,&local_40);
  if ((((BVar2 == 0) || (local_40.wID != 0x8170)) ||
      (pwVar3 = wcschr(*(wchar_t **)local_40.dwItemData,L'&'), pwVar3 == (wchar_t *)0x0)) ||
     (iVar4 = tolower((uint)(ushort)pwVar3[1]), iVar4 != CONCAT22(extraout_var,wVar1))) {
    BVar2 = GetMenuItemInfoW(param_2,1,1,&local_40);
    if (((BVar2 != 0) && (local_40.wID == 0x8171)) &&
       ((pwVar3 = wcschr(*(wchar_t **)local_40.dwItemData,L'&'), pwVar3 != (wchar_t *)0x0 &&
        (iVar4 = tolower((uint)(ushort)pwVar3[1]), iVar4 == CONCAT22(extraout_var,wVar1))))) {
      uVar5 = 0x20001;
    }
  }
  else {
    uVar5 = 0x20000;
  }
  return uVar5;
}



/* 0001fc30 FUN_0001fc30 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 0001fc30..0001fdcf. Semantic name remains unreviewed. */

void FUN_0001fc30(undefined4 param_1,LPCWSTR param_2,int *param_3)

{
  undefined1 *puVar1;
  wchar_t *lpData;
  LSTATUS LVar2;
  uint uVar3;
  int iVar4;
  HKEY local_60;
  DWORD local_5c [2];
  undefined1 auStack_54 [8];
  undefined1 auStack_4c [4];
  wchar_t *local_48;
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [36];
  
  local_60 = (HKEY)0x0;
  lpData = operator_new(0x1018);
  local_5c[0] = 0x1018;
  if (lpData != (wchar_t *)0x0) {
    LVar2 = RegOpenKeyExW((HKEY)0x80000001,param_2,0,0,&local_60);
    if (LVar2 == 0) {
      LVar2 = RegQueryValueExW(local_60,L"",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)lpData,local_5c);
      if (LVar2 == 0) {
        lpData[0x80b] = L'\0';
        if ((DAT_00035524 == 0) && (uVar3 = FUN_000158ec(lpData), uVar3 == 0)) {
          memset(auStack_54,0,0x38);
          local_48 = L"explorer.exe";
          local_5c[1] = 0x3c;
          puVar1 = auStack_54 + 3;
          uVar3 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar3) =
               *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0U >> (3 - uVar3) * 8;
          puVar1 = auStack_4c + 3;
          uVar3 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar3) =
               *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0U >> (3 - uVar3) * 8;
          puVar1 = auStack_44 + 3;
          uVar3 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar3) =
               *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | (uint)lpData >> (3 - uVar3) * 8;
          puVar1 = auStack_40 + 3;
          uVar3 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar3) =
               *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0U >> (3 - uVar3) * 8;
          puVar1 = auStack_3c + 3;
          uVar3 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar3) =
               *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 1U >> (3 - uVar3) * 8;
          auStack_54._0_4_ = 0;
          auStack_4c = (undefined1  [4])0x0;
          auStack_40 = (undefined1  [4])0x0;
          auStack_3c._0_4_ = 1;
          auStack_44 = (undefined1  [4])lpData;
          iVar4 = ShellExecuteEx(local_5c + 1);
          if (iVar4 != 0) goto LAB_0001fd88;
        }
        (**(code **)(*param_3 + 0x2c))(param_3,lpData,0,0,0,0);
      }
    }
  }
LAB_0001fd88:
  if (local_60 != (HKEY)0x0) {
    RegCloseKey(local_60);
  }
  if (lpData != (wchar_t *)0x0) {
    operator_delete(lpData);
  }
  return;
}



/* 0001fdd0 FUN_0001fdd0 */

/* Boundary evidence: original MIPS .pdata 0001fdd0..0002016f. Semantic name remains unreviewed. */

void FUN_0001fdd0(undefined4 param_1,STRSAFE_LPCWSTR param_2,int *param_3,uint param_4)

{
  undefined1 *puVar1;
  wchar_t *pszDest;
  HRESULT HVar2;
  size_t sVar3;
  int iVar4;
  wchar_t *pwVar5;
  DWORD DVar6;
  uint uVar7;
  int local_68 [2];
  undefined4 local_60;
  undefined1 local_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 local_50 [4];
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 local_44 [36];
  
  pszDest = operator_new(0x1018);
  if (pszDest == (STRSAFE_LPWSTR)0x0) {
    return;
  }
  HVar2 = StringCchCopyW(pszDest,0x80c,param_2);
  if (HVar2 == 0) {
    do {
      sVar3 = wcslen(pszDest);
      if (sVar3 != 0) {
        pwVar5 = pszDest + sVar3;
        do {
          if (*pwVar5 == L'.') break;
          sVar3 = sVar3 - 1;
          pwVar5 = pwVar5 + -1;
        } while (sVar3 != 0);
      }
      pwVar5 = pszDest + sVar3;
      if (*pwVar5 != L'.') {
LAB_000200e0:
        local_60 = 0x3c;
        local_5c = (undefined1  [4])0x400;
        local_44._0_4_ = 1;
        puVar1 = auStack_58 + 3;
        uVar7 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar7) =
             *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | param_4 >> (3 - uVar7) * 8;
        puVar1 = auStack_54 + 3;
        uVar7 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar7) =
             *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
        puVar1 = local_50 + 3;
        uVar7 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar7) =
             *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | (uint)pszDest >> (3 - uVar7) * 8;
        puVar1 = auStack_4c + 3;
        uVar7 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar7) =
             *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
        puVar1 = auStack_48 + 3;
        uVar7 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar7) =
             *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
        auStack_54 = (undefined1  [4])0x0;
        auStack_4c = (undefined1  [4])0x0;
        auStack_48 = (undefined1  [4])0x0;
        auStack_58 = (undefined1  [4])param_4;
        local_50 = (undefined1  [4])pszDest;
        ShellExecuteEx(&local_60);
        break;
      }
      iVar4 = _wcsicmp(pwVar5,L".lnk");
      if (iVar4 != 0) {
        iVar4 = _wcsicmp(pwVar5,L".url");
        if (iVar4 == 0) {
          local_68[0] = -1;
          DVar6 = FUN_0001f080(local_68,pszDest,0);
          if ((DVar6 == 0) && (FUN_0001eaa8(local_68,pszDest,0x80c), param_3 != (int *)0x0)) {
            if ((DAT_00035524 == 0) && (uVar7 = FUN_000158ec(pszDest), uVar7 == 0)) {
              memset(local_5c,0,0x38);
              local_50 = (undefined1  [4])0x11ac4;
              local_60 = 0x3c;
              puVar1 = local_5c + 3;
              uVar7 = (uint)puVar1 & 3;
              *(uint *)(puVar1 + -uVar7) =
                   *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
              puVar1 = auStack_54 + 3;
              uVar7 = (uint)puVar1 & 3;
              *(uint *)(puVar1 + -uVar7) =
                   *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
              puVar1 = auStack_4c + 3;
              uVar7 = (uint)puVar1 & 3;
              *(uint *)(puVar1 + -uVar7) =
                   *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 |
                   (uint)pszDest >> (3 - uVar7) * 8;
              puVar1 = auStack_48 + 3;
              uVar7 = (uint)puVar1 & 3;
              *(uint *)(puVar1 + -uVar7) =
                   *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
              puVar1 = local_44 + 3;
              uVar7 = (uint)puVar1 & 3;
              *(uint *)(puVar1 + -uVar7) =
                   *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 1U >> (3 - uVar7) * 8;
              local_5c = (undefined1  [4])0x0;
              auStack_54 = (undefined1  [4])0x0;
              auStack_48 = (undefined1  [4])0x0;
              local_44._0_4_ = 1;
              auStack_4c = (undefined1  [4])pszDest;
              iVar4 = ShellExecuteEx(&local_60);
              if (iVar4 != 0) goto LAB_0001ffdc;
            }
            (**(code **)(*param_3 + 0x2c))(param_3,pszDest,0,0,0,0);
          }
LAB_0001ffdc:
          FUN_0001f030(local_68);
        }
        else {
          iVar4 = _wcsicmp(pwVar5,L".htm");
          if ((iVar4 != 0) && (iVar4 = _wcsicmp(pwVar5,L".html"), iVar4 != 0)) goto LAB_000200e0;
          if (param_3 == (int *)0x0) break;
          if ((DAT_00035524 == 0) && (uVar7 = FUN_000158ec(pszDest), uVar7 == 0)) {
            memset(local_5c,0,0x38);
            local_50 = (undefined1  [4])0x11ac4;
            local_60 = 0x3c;
            puVar1 = local_5c + 3;
            uVar7 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar7) =
                 *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
            puVar1 = auStack_54 + 3;
            uVar7 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar7) =
                 *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
            puVar1 = auStack_4c + 3;
            uVar7 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar7) =
                 *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 |
                 (uint)pszDest >> (3 - uVar7) * 8;
            puVar1 = auStack_48 + 3;
            uVar7 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar7) =
                 *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
            puVar1 = local_44 + 3;
            uVar7 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar7) =
                 *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 1U >> (3 - uVar7) * 8;
            local_5c = (undefined1  [4])0x0;
            auStack_54 = (undefined1  [4])0x0;
            auStack_48 = (undefined1  [4])0x0;
            local_44._0_4_ = 1;
            auStack_4c = (undefined1  [4])pszDest;
            iVar4 = ShellExecuteEx(&local_60);
            if (iVar4 != 0) break;
          }
          (**(code **)(*param_3 + 0x2c))(param_3,pszDest,0,0,0,0);
        }
        break;
      }
      pwVar5 = operator_new(0x1018);
      if (pwVar5 == (wchar_t *)0x0) break;
      iVar4 = SHGetShortcutTarget(pszDest,pwVar5,0x80c);
      if (iVar4 == 0) goto LAB_0001fec8;
      operator_delete(pszDest);
      pszDest = pwVar5;
    } while( true );
  }
LAB_0002013c:
  if (pszDest != (STRSAFE_LPWSTR)0x0) {
    operator_delete(pszDest);
  }
  return;
LAB_0001fec8:
  operator_delete(pwVar5);
  goto LAB_0002013c;
}



/* 00020170 FUN_00020170 */

/* Boundary evidence: original MIPS .pdata 00020170..0002022b. Semantic name remains unreviewed. */

void FUN_00020170(ushort *param_1,HMENU param_2,UINT param_3,int *param_4,uint param_5)

{
  ULONG_PTR UVar1;
  
  if (((0xa0ff < (int)param_3) && ((int)param_3 < 0xa1c9)) &&
     (UVar1 = FUN_0001f42c(param_1,param_2,param_3,0), UVar1 != 0)) {
    if ((int)(uint)*param_1 < (int)param_3) {
      if ((int)(uint)param_1[1] <= (int)param_3) {
        FUN_0001fc30(param_1,*(LPCWSTR *)(UVar1 + 4),param_4);
      }
    }
    else {
      FUN_0001fdd0(param_1,*(STRSAFE_LPCWSTR *)(UVar1 + 4),param_4,param_5);
    }
  }
  return;
}



/* 0002022c FUN_0002022c */

/* Boundary evidence: original MIPS .pdata 0002022c..000202eb. Semantic name remains unreviewed. */

void FUN_0002022c(undefined4 param_1,uint param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  HLOCAL hMem;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [36];
  
  hMem = LocalAlloc(0,0x208);
  if (hMem != (HLOCAL)0x0) {
    SHGetSpecialFolderPath(param_2,hMem,6,1);
    local_4c = 0x400;
    local_50 = 0x3c;
    puVar1 = auStack_48 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_2 >> (3 - uVar2) * 8;
    puVar1 = auStack_44 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    puVar1 = auStack_40 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)hMem >> (3 - uVar2) * 8;
    puVar1 = auStack_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    puVar1 = auStack_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    puVar1 = auStack_34 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 1U >> (3 - uVar2) * 8;
    auStack_44 = (undefined1  [4])0x0;
    auStack_3c = (undefined1  [4])0x0;
    auStack_38 = (undefined1  [4])0x0;
    auStack_34._0_4_ = 1;
    auStack_48 = (undefined1  [4])param_2;
    auStack_40 = (undefined1  [4])hMem;
    ShellExecuteEx(&local_50);
    LocalFree(hMem);
  }
  return;
}



/* 000202ec FUN_000202ec */

/* Boundary evidence: original MIPS .pdata 000202ec..0002061b. Semantic name remains unreviewed. */

undefined4 FUN_000202ec(undefined4 param_1,HWND param_2,wchar_t *param_3,short *param_4)

{
  short sVar1;
  wchar_t wVar2;
  uint uVar3;
  uint *puVar4;
  bool bVar5;
  undefined1 *puVar6;
  LPWSTR lpBuffer;
  LPCWSTR pWVar7;
  STRSAFE_LPWSTR pszDest;
  int iVar8;
  HRESULT HVar9;
  size_t sVar10;
  BOOL BVar11;
  DWORD DVar12;
  int iVar13;
  wchar_t *pwVar14;
  wchar_t *_Str;
  undefined4 uVar15;
  int local_150 [2];
  tagOFNW local_148;
  undefined2 auStack_ea [93];
  uint local_30;
  
  local_30 = DAT_00035518;
  local_150[0] = -1;
  uVar15 = 0;
  lpBuffer = operator_new(0x208);
  pWVar7 = operator_new(0x208);
  pszDest = operator_new(0x208);
  if (lpBuffer != (LPWSTR)0x0) {
    if ((pWVar7 != (LPCWSTR)0x0) && (pszDest != (STRSAFE_LPWSTR)0x0)) {
      bVar5 = true;
      iVar13 = 0;
      iVar8 = wcsncmp(param_3,L"file",4);
      if (iVar8 == 0) {
        iVar8 = 0;
        sVar1 = *param_4;
        while (sVar1 != 0) {
          if (sVar1 == 0x5c) {
            iVar13 = iVar8 + 1;
          }
          iVar8 = iVar8 + 1;
          sVar1 = param_4[iVar8];
        }
        bVar5 = false;
      }
      HVar9 = StringCchCopyW(pszDest,0x104,param_4 + iVar13);
      if (HVar9 == 0) {
        _Str = pszDest;
        if (bVar5) {
          wVar2 = *pszDest;
          pwVar14 = pszDest;
          while (wVar2 != L'\0') {
            iVar13 = FUN_0001f170((uint)(ushort)*pwVar14);
            *pwVar14 = (wchar_t)iVar13;
            pwVar14 = pwVar14 + 1;
            wVar2 = *pwVar14;
          }
          wVar2 = *pszDest;
          while (wVar2 == L'_') {
            _Str = _Str + 1;
            wVar2 = *_Str;
          }
        }
        SHGetSpecialFolderPath(param_2,pWVar7,6,0);
        local_148.lStructSize = 0;
        memset(&local_148.hwndOwner,0,0x48);
        local_148.Flags = 0x806;
        LoadStringW(DAT_00035560,0x4e27,lpBuffer,0x104);
        LoadStringW(DAT_00035560,0x5722,(LPWSTR)&local_148.dwReserved,100);
        wcscat((wchar_t *)&local_148.dwReserved,L" (*.url)");
        sVar10 = wcslen((wchar_t *)&local_148.dwReserved);
        wcscpy((wchar_t *)((int)&local_148.dwReserved + sVar10 * 2 + 2),L"*.url");
        auStack_ea[sVar10] = 0;
        local_148.lStructSize = 0x4c;
        puVar6 = (undefined1 *)((int)&local_148.hwndOwner + 3);
        uVar3 = (uint)puVar6 & 3;
        puVar4 = (uint *)(puVar6 + -uVar3);
        *puVar4 = *puVar4 & -1 << (uVar3 + 1) * 8 | (uint)param_2 >> (3 - uVar3) * 8;
        puVar6 = (undefined1 *)((int)&local_148.lpstrFilter + 3);
        uVar3 = (uint)puVar6 & 3;
        puVar4 = (uint *)(puVar6 + -uVar3);
        *puVar4 = *puVar4 & -1 << (uVar3 + 1) * 8 | (uint)&local_148.dwReserved >> (3 - uVar3) * 8;
        puVar6 = (undefined1 *)((int)&local_148.lpstrDefExt + 3);
        uVar3 = (uint)puVar6 & 3;
        puVar4 = (uint *)(puVar6 + -uVar3);
        *puVar4 = *puVar4 & -1 << (uVar3 + 1) * 8 | 0x122c8U >> (3 - uVar3) * 8;
        puVar6 = (undefined1 *)((int)&local_148.nMaxFile + 3);
        uVar3 = (uint)puVar6 & 3;
        puVar4 = (uint *)(puVar6 + -uVar3);
        *puVar4 = *puVar4 & -1 << (uVar3 + 1) * 8 | 0x103U >> (3 - uVar3) * 8;
        puVar6 = (undefined1 *)((int)&local_148.lpstrFile + 3);
        uVar3 = (uint)puVar6 & 3;
        puVar4 = (uint *)(puVar6 + -uVar3);
        *puVar4 = *puVar4 & -1 << (uVar3 + 1) * 8 | (uint)_Str >> (3 - uVar3) * 8;
        puVar6 = (undefined1 *)((int)&local_148.lpstrTitle + 3);
        uVar3 = (uint)puVar6 & 3;
        puVar4 = (uint *)(puVar6 + -uVar3);
        *puVar4 = *puVar4 & -1 << (uVar3 + 1) * 8 | (uint)lpBuffer >> (3 - uVar3) * 8;
        puVar6 = (undefined1 *)((int)&local_148.lpstrInitialDir + 3);
        uVar3 = (uint)puVar6 & 3;
        puVar4 = (uint *)(puVar6 + -uVar3);
        *puVar4 = *puVar4 & -1 << (uVar3 + 1) * 8 | (uint)pWVar7 >> (3 - uVar3) * 8;
        local_148.lpstrDefExt = L"url";
        local_148.nMaxFile = 0x103;
        local_148.hwndOwner = param_2;
        local_148.lpstrFilter = (LPCWSTR)&local_148.dwReserved;
        local_148.lpstrFile = _Str;
        local_148.lpstrInitialDir = pWVar7;
        local_148.lpstrTitle = lpBuffer;
        BVar11 = GetSaveFileNameW(&local_148);
        if (BVar11 != 0) {
          if (((local_148.Flags & 0x400) != 0) && (sVar10 = wcslen(_Str), sVar10 < 0xff)) {
            wcscat(_Str,L".url");
          }
          DVar12 = FUN_0001f080(local_150,_Str,1);
          if (DVar12 == 0) {
            FUN_0001ecec(local_150,(int)param_3);
            FUN_0001f030(local_150);
            uVar15 = 1;
          }
        }
      }
    }
    operator_delete(lpBuffer);
  }
  if (pWVar7 != (LPCWSTR)0x0) {
    operator_delete(pWVar7);
  }
  if (pszDest != (STRSAFE_LPWSTR)0x0) {
    operator_delete(pszDest);
  }
  FUN_0001f030(local_150);
  FUN_00033770(local_30);
  return uVar15;
}



/* 0002061c FUN_0002061c */

/* Boundary evidence: original MIPS .pdata 0002061c..00020637. Semantic name remains unreviewed. */

void FUN_0002061c(undefined4 param_1,HWND param_2,wchar_t *param_3,short *param_4)

{
  FUN_000202ec(param_1,param_2,param_3,param_4);
  return;
}



/* 00020638 FUN_00020638 */

/* Boundary evidence: original MIPS .pdata 00020638..0002072b. Semantic name remains unreviewed. */

UINT FUN_00020638(undefined4 param_1,HMENU param_2,undefined4 *param_3)

{
  UINT UVar1;
  undefined4 *puVar2;
  int iVar3;
  UINT UVar4;
  UINT UVar5;
  UINT UVar6;
  
  UVar6 = 0;
  UVar1 = FUN_0001564c(param_2);
  UVar1 = UVar1 - 1;
  UVar4 = UVar1;
  UVar5 = UVar1;
  if (-1 < (int)UVar1) {
    do {
      iVar3 = (UVar5 - UVar6) + 1;
      if (iVar3 < 0) {
        iVar3 = (UVar5 - UVar6) + 2;
      }
      UVar4 = (iVar3 >> 1) + UVar6;
      puVar2 = (undefined4 *)FUN_0001f42c(param_1,param_2,UVar4,1);
      if (puVar2 == (undefined4 *)0x0) goto LAB_000206fc;
      iVar3 = FUN_0001f4d0(param_1,param_3,puVar2);
      if (iVar3 < 0) {
        UVar5 = UVar4 - 1;
      }
      else {
        UVar4 = UVar4 + 1;
        UVar6 = UVar4;
      }
    } while ((int)UVar6 <= (int)UVar5);
    if ((int)UVar1 < (int)UVar4) {
LAB_000206fc:
      UVar4 = 0xffffffff;
    }
  }
  return UVar4;
}



/* 0002072c FUN_0002072c */

/* Boundary evidence: original MIPS .pdata 0002072c..000208ab. Semantic name remains unreviewed. */

BOOL FUN_0002072c(undefined4 param_1,HMENU param_2,UINT_PTR param_3,LPCWSTR param_4)

{
  UINT UVar1;
  HMENU uIDNewItem;
  UINT UVar2;
  undefined4 *puVar3;
  int iVar4;
  BOOL BVar5;
  MENUITEMINFOW local_50;
  
  UVar1 = FUN_00020638(param_1,param_2,(undefined4 *)param_4);
  BVar5 = 0;
  if ((*(uint *)(param_4 + 4) & 0x10) == 0) {
    UVar2 = UVar1;
    if (UVar1 == 0xffffffff) {
      UVar2 = FUN_0001564c(param_2);
    }
    puVar3 = (undefined4 *)FUN_0001f42c(param_1,param_2,UVar2 - 1,1);
    if ((puVar3 == (undefined4 *)0x0) ||
       (iVar4 = CompareStringW(0x800,1,(PCNZWCH)*puVar3,-1,*(PCNZWCH *)param_4,-1), iVar4 != 2)) {
      BVar5 = InsertMenuW(param_2,UVar1,0x500,param_3,param_4);
    }
  }
  else {
    uIDNewItem = FUN_0001f27c(param_1,(int)param_4);
    if (uIDNewItem != (HMENU)0x0) {
      InsertMenuW(param_2,UVar1,0x510,(UINT_PTR)uIDNewItem,param_4);
      if (UVar1 == 0xffffffff) {
        UVar1 = FUN_0001564c(param_2);
        UVar1 = UVar1 - 1;
      }
      local_50.cbSize = 0x2c;
      local_50.fMask = 0x20;
      local_50.dwItemData = (ULONG_PTR)param_4;
      BVar5 = SetMenuItemInfoW(param_2,UVar1,1,&local_50);
    }
  }
  return BVar5;
}



/* 000208ac FUN_000208ac */

/* Boundary evidence: original MIPS .pdata 000208ac..00020ca3. Semantic name remains unreviewed. */

undefined4 FUN_000208ac(ushort *param_1,HMENU param_2,wchar_t *param_3)

{
  bool bVar1;
  wchar_t *lpName;
  short *lpData;
  LSTATUS LVar2;
  int iVar3;
  LPCWSTR pWVar4;
  size_t sVar5;
  void *pvVar6;
  HRESULT HVar7;
  BOOL BVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  UINT_PTR UVar12;
  DWORD dwIndex;
  uint uVar13;
  undefined4 uVar14;
  DWORD local_40;
  HKEY local_3c;
  HKEY local_38;
  size_t local_34;
  DWORD local_30;
  HMENU local_2c;
  
  dwIndex = 0;
  local_40 = 0x104;
  local_30 = 0;
  uVar14 = 0;
  local_2c = param_2;
  local_34 = wcslen(param_3);
  lpName = operator_new(0x208);
  lpData = operator_new(0x1018);
  if (lpName != (wchar_t *)0x0) {
    if ((lpData != (short *)0x0) &&
       (LVar2 = RegOpenKeyExW((HKEY)0x80000001,param_3,0,0,&local_3c), LVar2 == 0)) {
      iVar3 = RegEnumKeyExW(local_3c,0,lpName,&local_40,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            (PFILETIME)0x0);
      uVar14 = 1;
      while (iVar3 == 0) {
        LVar2 = RegOpenKeyExW(local_3c,lpName,0,0,&local_38);
        if (LVar2 == 0) {
          local_40 = 0x1018;
          LVar2 = RegQueryValueExW(local_38,(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)lpData,
                                   &local_40);
          if ((LVar2 != 0) || (bVar1 = false, *lpData == 0)) {
            bVar1 = true;
          }
          pWVar4 = operator_new(0x10);
          if (pWVar4 == (LPCWSTR)0x0) {
            pWVar4 = (LPCWSTR)0x0;
          }
          else {
            pWVar4[0] = L'\0';
            pWVar4[1] = L'\0';
            pWVar4[2] = L'\0';
            pWVar4[3] = L'\0';
            pWVar4[4] = L'\0';
            pWVar4[5] = L'\0';
            pWVar4[6] = L'\0';
            pWVar4[7] = L'\0';
          }
          if (pWVar4 != (LPCWSTR)0x0) {
            sVar5 = wcslen(lpName);
            uVar13 = sVar5 + 1;
            if (uVar13 < 0x80000000) {
              uVar9 = uVar13 * 2;
            }
            else {
              uVar9 = 0xffffffff;
            }
            pvVar6 = operator_new(uVar9);
            uVar9 = sVar5 + local_34 + 2;
            *(void **)pWVar4 = pvVar6;
            if (uVar9 < 0x80000000) {
              uVar10 = uVar9 * 2;
            }
            else {
              uVar10 = 0xffffffff;
            }
            pvVar6 = operator_new(uVar10);
            *(void **)(pWVar4 + 2) = pvVar6;
            if ((((pvVar6 != (void *)0x0) && (*(STRSAFE_LPWSTR *)pWVar4 != (STRSAFE_LPWSTR)0x0)) &&
                (HVar7 = StringCchCopyW(*(STRSAFE_LPWSTR *)pWVar4,uVar13,lpName), HVar7 == 0)) &&
               (HVar7 = StringCchCopyW(*(STRSAFE_LPWSTR *)(pWVar4 + 2),uVar9,param_3), HVar7 == 0))
            {
              *(undefined2 *)(*(int *)(pWVar4 + 2) + local_34 * 2) = 0x5c;
              *(undefined2 *)(*(int *)(pWVar4 + 2) + local_34 * 2 + 2) = 0;
              HVar7 = StringCchCatW(*(STRSAFE_LPWSTR *)(pWVar4 + 2),uVar9,lpName);
              if (HVar7 == 0) {
                uVar11 = 0x10;
                if (!bVar1) {
                  uVar11 = 0;
                }
                *(undefined4 *)(pWVar4 + 4) = uVar11;
                if ((int)((uint)param_1[1] - (uint)*param_1) < 2) {
                  UVar12 = 0xffff;
                }
                else {
                  uVar13 = param_1[1] + 0xffff;
                  UVar12 = uVar13 & 0xffff;
                  param_1[1] = (ushort)uVar13;
                }
                if (UVar12 != 0xffffffff) {
                  BVar8 = FUN_0002072c(param_1,local_2c,UVar12,pWVar4);
                  if (BVar8 == 0) {
                    if (param_1[1] < 0xa1c9) {
                      param_1[1] = param_1[1] + 1;
                    }
                    FUN_0001f214((undefined4 *)pWVar4,1);
                  }
                  RegCloseKey(local_38);
                  dwIndex = local_30;
                  goto LAB_00020bd8;
                }
              }
            }
            FUN_0001f214((undefined4 *)pWVar4,1);
          }
          RegCloseKey(local_38);
          RegCloseKey(local_3c);
          uVar14 = 0;
          goto LAB_00020c28;
        }
LAB_00020bd8:
        local_40 = 0x104;
        dwIndex = dwIndex + 1;
        local_30 = dwIndex;
        iVar3 = RegEnumKeyExW(local_3c,dwIndex,lpName,&local_40,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,(PFILETIME)0x0);
      }
      RegCloseKey(local_3c);
    }
LAB_00020c28:
    operator_delete(lpName);
  }
  if (lpData != (short *)0x0) {
    operator_delete(lpData);
  }
  return uVar14;
}



/* 00020ca4 FUN_00020ca4 */

/* Boundary evidence: original MIPS .pdata 00020ca4..0002110f. Semantic name remains unreviewed. */

undefined4 FUN_00020ca4(ushort *param_1,HMENU param_2,STRSAFE_PCNZWCH param_3)

{
  HRESULT HVar1;
  HANDLE hFindFile;
  LPCWSTR pWVar2;
  size_t sVar3;
  STRSAFE_LPWSTR pwVar4;
  int iVar5;
  BOOL BVar6;
  uint uVar7;
  void *pvVar8;
  short *psVar9;
  UINT_PTR UVar10;
  uint uVar11;
  size_t local_470;
  HMENU local_46c;
  _WIN32_FIND_DATAW local_468;
  uint local_30;
  
  local_30 = DAT_00035518;
  local_470 = 0;
  local_46c = param_2;
  if (((((param_3 != (STRSAFE_PCNZWCH)0x0) &&
        (HVar1 = StringCchLengthW(param_3,0x104,&local_470), -1 < HVar1)) && (local_470 != 0)) &&
      (((local_470 < 0x104 &&
        (HVar1 = StringCchCopyW(local_468.cFileName + 0x102,0x104,param_3), HVar1 == 0)) &&
       ((local_468.cFileName[local_470 + 0x101] == L'\\' ||
        (HVar1 = StringCchCatW(local_468.cFileName + 0x102,0x104,L"\\"), HVar1 == 0)))))) &&
     (HVar1 = StringCchCatW(local_468.cFileName + 0x102,0x104,(STRSAFE_LPCWSTR)PTR_DAT_00035528),
     HVar1 == 0)) {
    hFindFile = FindFirstFileW(local_468.cFileName + 0x102,&local_468);
    HVar1 = StringCchCopyW(local_468.cFileName + 0x102,0x104,param_3);
    if ((HVar1 == 0) &&
       ((local_468.cFileName[local_470 + 0x101] == L'\\' ||
        (HVar1 = StringCchCatW(local_468.cFileName + 0x102,0x104,L"\\"), HVar1 == 0)))) {
      if (hFindFile != (HANDLE)0xffffffff) {
        do {
          pWVar2 = operator_new(0x10);
          if (pWVar2 == (LPCWSTR)0x0) {
            pWVar2 = (LPCWSTR)0x0;
          }
          else {
            pWVar2[0] = L'\0';
            pWVar2[1] = L'\0';
            pWVar2[2] = L'\0';
            pWVar2[3] = L'\0';
            pWVar2[4] = L'\0';
            pWVar2[5] = L'\0';
            pWVar2[6] = L'\0';
            pWVar2[7] = L'\0';
          }
          if (pWVar2 == (LPCWSTR)0x0) break;
          sVar3 = wcslen((wchar_t *)&local_468.dwReserved1);
          uVar11 = sVar3 + 1;
          if (uVar11 < 0x80000000) {
            uVar7 = uVar11 * 2;
          }
          else {
            uVar7 = 0xffffffff;
          }
          pwVar4 = operator_new(uVar7);
          *(STRSAFE_LPWSTR *)pWVar2 = pwVar4;
          if (pwVar4 == (STRSAFE_LPWSTR)0x0) {
LAB_000210b4:
            FUN_0001f214((undefined4 *)pWVar2,1);
            break;
          }
          HVar1 = StringCchCopyW(pwVar4,uVar11,(STRSAFE_LPCWSTR)&local_468.dwReserved1);
          if (HVar1 != 0) {
            pvVar8 = *(void **)pWVar2;
LAB_000210ac:
            operator_delete(pvVar8);
            goto LAB_000210b4;
          }
          uVar11 = sVar3 + local_470 + 2;
          if (uVar11 < 0x80000000) {
            uVar11 = uVar11 * 2;
          }
          else {
            uVar11 = 0xffffffff;
          }
          pwVar4 = operator_new(uVar11);
          *(STRSAFE_LPWSTR *)(pWVar2 + 2) = pwVar4;
          if (pwVar4 == (STRSAFE_LPWSTR)0x0) goto LAB_000210b4;
          HVar1 = StringCchCopyW(pwVar4,sVar3 + local_470 + 2,param_3);
          if ((HVar1 != 0) ||
             ((((*(STRSAFE_LPWSTR *)(pWVar2 + 2))[local_470 - 1] != L'\\' &&
               (HVar1 = StringCchCatW(*(STRSAFE_LPWSTR *)(pWVar2 + 2),sVar3 + local_470 + 2,L"\\"),
               HVar1 != 0)) ||
              (HVar1 = StringCchCatW(*(STRSAFE_LPWSTR *)(pWVar2 + 2),sVar3 + local_470 + 2,
                                     (STRSAFE_LPCWSTR)&local_468.dwReserved1), HVar1 != 0)))) {
            operator_delete(*(void **)pWVar2);
            pvVar8 = *(void **)(pWVar2 + 2);
            goto LAB_000210ac;
          }
          if ((local_468.dwFileAttributes & 0x10) == 0) {
            if (sVar3 != 0) {
              psVar9 = (short *)(sVar3 * 2 + *(int *)pWVar2);
              do {
                if (*psVar9 == 0x2e) break;
                sVar3 = sVar3 - 1;
                psVar9 = psVar9 + -1;
              } while (sVar3 != 0);
            }
            psVar9 = (short *)(sVar3 * 2 + *(int *)pWVar2);
            iVar5 = _wcsicmp(psVar9 + 1,L"url");
            if ((iVar5 == 0) || (iVar5 = _wcsicmp(psVar9 + 1,L"lnk"), iVar5 == 0)) {
              if (*psVar9 == 0x2e) {
                *psVar9 = 0;
              }
              goto LAB_00020fe4;
            }
LAB_00021068:
            FUN_0001f214((undefined4 *)pWVar2,1);
          }
          else {
LAB_00020fe4:
            *(DWORD *)(pWVar2 + 4) = local_468.dwFileAttributes;
            if ((int)((uint)param_1[1] - (uint)*param_1) < 2) {
              UVar10 = 0xffff;
            }
            else {
              uVar11 = *param_1 + 1;
              UVar10 = uVar11 & 0xffff;
              *param_1 = (ushort)uVar11;
            }
            if (UVar10 == 0xffffffff) goto LAB_000210b4;
            BVar6 = FUN_0002072c(param_1,local_46c,UVar10,pWVar2);
            if (BVar6 == 0) {
              if (0xa0ff < *param_1) {
                *param_1 = *param_1 - 1;
              }
              goto LAB_00021068;
            }
          }
          BVar6 = FindNextFileW(hFindFile,&local_468);
        } while (BVar6 != 0);
      }
      FUN_00033770(local_30);
      return 1;
    }
  }
  FUN_00033770(local_30);
  return 0;
}



/* 00021110 FUN_00021110 */

/* Boundary evidence: original MIPS .pdata 00021110..000211ff. Semantic name remains unreviewed. */

undefined4 FUN_00021110(ushort *param_1,HMENU param_2)

{
  UINT UVar1;
  undefined4 *puVar2;
  int iVar3;
  wchar_t *_Str1;
  
  UVar1 = FUN_000156c4(param_2,0);
  if ((UVar1 == 0xfffe) &&
     (puVar2 = (undefined4 *)FUN_0001f42c(param_1,param_2,0,1), puVar2 != (undefined4 *)0x0)) {
    RemoveMenu(param_2,0,0x400);
    _Str1 = (wchar_t *)puVar2[1];
    iVar3 = wcsncmp(_Str1,L"SOFTWARE\\Microsoft\\Internet Explorer\\Favorites",0x2e);
    if (iVar3 == 0) {
      FUN_000208ac(param_1,param_2,_Str1);
    }
    else {
      FUN_00020ca4(param_1,param_2,_Str1);
    }
    UVar1 = FUN_0001564c(param_2);
    if (UVar1 == 0) {
      FUN_0001f3a4(param_1,param_2);
    }
    FUN_0001f214(puVar2,1);
  }
  return 1;
}



/* 00021200 FUN_00021200 */

/* Boundary evidence: original MIPS .pdata 00021200..0002147f. Semantic name remains unreviewed. */

void FUN_00021200(ushort *param_1,HMENU param_2)

{
  wchar_t *_Str;
  size_t sVar1;
  HRESULT HVar2;
  UINT UVar3;
  LPCWSTR lpNewItem;
  LPCWSTR lpNewItem_00;
  LPWSTR pWVar4;
  BOOL BVar5;
  HMENU pHVar6;
  
  pHVar6 = *(HMENU *)(param_1 + 2);
  if ((pHVar6 != (HMENU)0x0) && (pHVar6 != param_2)) {
    FUN_0001f55c(param_1,pHVar6);
  }
  *(HMENU *)(param_1 + 2) = param_2;
  *param_1 = 0xa0ff;
  param_1[1] = 0xa1c9;
  FUN_0001f55c(param_1,param_2);
  _Str = LocalAlloc(0,0x208);
  if (_Str == (wchar_t *)0x0) {
    return;
  }
  SHGetSpecialFolderPath(0,_Str,6,0);
  sVar1 = wcslen(_Str);
  if ((sVar1 == 0) ||
     ((_Str[sVar1 - 1] != L'\\' && (HVar2 = StringCchCatW(_Str,0x104,L"\\"), HVar2 != 0))))
  goto LAB_00021458;
  FUN_00020ca4(param_1,param_2,_Str);
  FUN_000208ac(param_1,param_2,L"SOFTWARE\\Microsoft\\Internet Explorer\\Favorites");
  UVar3 = FUN_0001564c(param_2);
  if (UVar3 == 0) {
    FUN_0001f3a4(param_1,param_2);
  }
  lpNewItem = operator_new(0x10);
  if (lpNewItem == (LPCWSTR)0x0) {
    lpNewItem = (LPCWSTR)0x0;
  }
  else {
    lpNewItem[0] = L'\0';
    lpNewItem[1] = L'\0';
    lpNewItem[2] = L'\0';
    lpNewItem[3] = L'\0';
    lpNewItem[4] = L'\0';
    lpNewItem[5] = L'\0';
    lpNewItem[6] = L'\0';
    lpNewItem[7] = L'\0';
  }
  lpNewItem_00 = operator_new(0x10);
  if (lpNewItem_00 == (LPCWSTR)0x0) {
    lpNewItem_00 = (LPCWSTR)0x0;
  }
  else {
    lpNewItem_00[0] = L'\0';
    lpNewItem_00[1] = L'\0';
    lpNewItem_00[2] = L'\0';
    lpNewItem_00[3] = L'\0';
    lpNewItem_00[4] = L'\0';
    lpNewItem_00[5] = L'\0';
    lpNewItem_00[6] = L'\0';
    lpNewItem_00[7] = L'\0';
  }
  if (lpNewItem == (LPCWSTR)0x0) {
LAB_00021444:
    if (lpNewItem_00 == (LPCWSTR)0x0) goto LAB_00021458;
  }
  else {
    if (lpNewItem_00 == (LPCWSTR)0x0) {
      FUN_0001f214((undefined4 *)lpNewItem,1);
      goto LAB_00021444;
    }
    pWVar4 = operator_new(200);
    *(LPWSTR *)lpNewItem = pWVar4;
    if (pWVar4 != (LPWSTR)0x0) {
      LoadStringW(DAT_00035560,0x4e25,pWVar4,100);
    }
    pWVar4 = operator_new(200);
    *(LPWSTR *)lpNewItem_00 = pWVar4;
    if (pWVar4 != (LPWSTR)0x0) {
      LoadStringW(DAT_00035560,0x4e26,pWVar4,100);
    }
    InsertMenuW(param_2,0,0xc00,0,(LPCWSTR)0x0);
    BVar5 = InsertMenuW(param_2,0,0x500,0x8171,lpNewItem);
    if (BVar5 == 0) {
      FUN_0001f214((undefined4 *)lpNewItem,1);
    }
    BVar5 = InsertMenuW(param_2,0,0x500,0x8170,lpNewItem_00);
    if (BVar5 != 0) goto LAB_00021458;
  }
  FUN_0001f214((undefined4 *)lpNewItem_00,1);
LAB_00021458:
  LocalFree(_Str);
  return;
}



/* 00021480 FUN_00021480 */

/* Boundary evidence: original MIPS .pdata 00021480..00021513. Semantic name remains unreviewed. */

undefined4 * FUN_00021480(undefined4 *param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    param_2 = (undefined4 *)0x0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    param_2[1] = 0;
    *param_2 = 0;
    if (param_1[2] == 0) {
      *param_1 = param_2;
    }
    else {
      *param_2 = param_1[1];
      *(undefined4 **)(param_1[1] + 4) = param_2;
    }
    param_1[1] = param_2;
    param_1[2] = param_1[2] + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  return param_2;
}



/* 00021514 FUN_00021514 */

/* Boundary evidence: original MIPS .pdata 00021514..00021593. Semantic name remains unreviewed. */

int FUN_00021514(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    iVar2 = 0;
    for (iVar1 = *param_1; (iVar1 != 0 && (iVar1 != param_2)); iVar1 = *(int *)(iVar1 + 4)) {
      iVar2 = iVar2 + 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  return iVar2;
}



/* 00021594 FUN_00021594 */

/* Boundary evidence: original MIPS .pdata 00021594..0002161b. Semantic name remains unreviewed. */

int FUN_00021594(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 < param_1[2]) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    iVar2 = *param_1;
    for (iVar1 = 0; (iVar2 != 0 && (iVar1 < param_2)); iVar1 = iVar1 + 1) {
      iVar2 = *(int *)(iVar2 + 4);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 0002161c FUN_0002161c */

/* Boundary evidence: original MIPS .pdata 0002161c..0002168f. Semantic name remains unreviewed. */

int * FUN_0002161c(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  piVar1 = (int *)FUN_00021594(param_1,param_2);
  piVar2 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    piVar2 = FUN_00015a70(param_1,piVar1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return piVar2;
}



/* 00021690 FUN_00021690 */

/* Boundary evidence: original MIPS .pdata 00021690..0002178f. Semantic name remains unreviewed. */

int * FUN_00021690(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00021594(param_1,param_3);
  if (((param_2 == (int *)0x0) || (param_3 < 0)) || (param_1[2] < param_3)) {
    param_2 = (int *)0x0;
  }
  else if ((param_3 == 0) || (piVar1 == (int *)0x0)) {
    param_2 = FUN_000159dc(param_1,param_2);
  }
  else if (param_3 == param_1[2]) {
    param_2 = FUN_00021480(param_1,param_2);
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    param_2[1] = 0;
    *param_2 = 0;
    iVar2 = *piVar1;
    param_2[1] = (int)piVar1;
    *param_2 = *piVar1;
    *piVar1 = (int)param_2;
    if (iVar2 != 0) {
      *(int **)(iVar2 + 4) = param_2;
    }
    param_1[2] = param_1[2] + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  return param_2;
}



/* 00021790 FUN_00021790 */

/* Boundary evidence: original MIPS .pdata 00021790..00021917. Semantic name remains unreviewed. */

int FUN_00021790(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  HFONT pHVar5;
  undefined3 extraout_var;
  int local_18;
  int local_14;
  
  *(undefined4 *)(param_1 + 0x3c) = 1;
  local_18 = 0;
  local_14 = 0;
  FUN_0002d8a8(&local_18,&local_14);
  if ((local_18 == 0) && (local_14 == 0)) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    puVar2 = operator_new(0x28);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_0002d9e8(puVar2,DAT_00035560);
    }
    *(undefined4 **)(param_1 + 0x20) = puVar2;
  }
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_0002d0d0((int)pvVar3);
  }
  *(int *)(param_1 + 0x24) = iVar4;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x70) = 1;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 100) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x68) = 0xffffffff;
  iVar4 = FUN_0002cf98();
  *(int *)(param_1 + 0x80) = iVar4;
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 0xb8) = 0x4000;
    *(undefined4 *)(param_1 + 0xb0) = 0x4000;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x98) = 0;
    *(undefined4 *)(param_1 + 0x84) = 1;
    *(undefined4 *)(param_1 + 0xc4) = 2;
    *(undefined4 *)(param_1 + 200) = 3;
  }
  else {
    *(undefined4 *)(param_1 + 0xb8) = 2;
    *(undefined4 *)(param_1 + 0xb0) = 1;
    pHVar5 = FUN_0002d054(0xc);
    *(HFONT *)(param_1 + 0x30) = pHVar5;
    *(undefined4 *)(param_1 + 0x98) = 1;
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 2;
    *(undefined4 *)(param_1 + 200) = 1;
  }
  *(undefined4 *)(param_1 + 0x88) = 1;
  bVar1 = FUN_0002c7b4();
  *(uint *)(param_1 + 0x88) = (uint)(CONCAT31(extraout_var,bVar1) != 0);
  FUN_0002bf24();
  return param_1;
}



/* 00021918 FUN_00021918 */

int FUN_00021918(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)*param_1;
  while (((iVar1 != 0 && (iVar2 = *(int *)(iVar1 + 8), iVar2 != 0)) &&
         ((*(uint *)(iVar2 + 8) & 0x40) == 0))) {
    if (param_2 == *(int *)(iVar2 + 0x1c)) {
      return iVar1;
    }
    iVar1 = *(int *)(iVar1 + 4);
  }
  return 0;
}



/* 00021968 FUN_00021968 */

/* Boundary evidence: original MIPS .pdata 00021968..00021a7b. Semantic name remains unreviewed. */

undefined4 FUN_00021968(undefined4 *param_1,HWND param_2)

{
  BOOL BVar1;
  HWND pHVar2;
  uint uVar3;
  int iVar4;
  HWND hWnd;
  UINT uCmd;
  HWND pHVar5;
  
  pHVar5 = *(HWND *)(DAT_00035570 + 4);
  uCmd = 1;
  hWnd = param_2;
  while (hWnd = GetWindow(hWnd,uCmd), hWnd != (HWND)0x0) {
    BVar1 = IsWindowVisible(hWnd);
    if (((((BVar1 != 0) && (hWnd != param_2)) && (hWnd != pHVar5)) &&
        ((pHVar2 = GetWindow(hWnd,4), pHVar2 == (HWND)0x0 &&
         (pHVar2 = GetParent(hWnd), pHVar2 == (HWND)0x0)))) &&
       ((uVar3 = GetWindowLongW(hWnd,-0x10), (uVar3 & 0x40000000) == 0 &&
        ((iVar4 = FUN_00021918(param_1,(int)hWnd), iVar4 == 0 &&
         (uVar3 = GetWindowLongW(hWnd,-0x14), (uVar3 & 0x80) == 0)))))) {
      PostMessageW(param_2,0x400,6,(LPARAM)hWnd);
    }
    uCmd = 3;
  }
  return 1;
}



/* 00021a7c FUN_00021a7c */

/* Boundary evidence: original MIPS .pdata 00021a7c..00022067. Semantic name remains unreviewed. */

WPARAM FUN_00021a7c(int param_1)

{
  bool bVar1;
  bool bVar2;
  DWORD DVar3;
  int iVar4;
  HANDLE pvVar5;
  BOOL BVar6;
  HWND pHVar7;
  DWORD nCount;
  DWORD DVar8;
  HANDLE *ppvVar9;
  int iVar10;
  tagMSG local_b0;
  HANDLE local_90 [2];
  DWORD local_88;
  DWORD local_84;
  DWORD local_80;
  int local_7c;
  DWORD local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [44];
  uint local_2c;
  
  local_2c = DAT_00035518;
  local_90[0] = (HANDLE)0x0;
  local_90[1] = (HANDLE)0x0;
  iVar10 = 0;
  local_7c = 0;
  DVar8 = 0;
  local_80 = 0;
  local_88 = 0;
  local_84 = 1;
  bVar1 = false;
  bVar2 = false;
  local_78 = 0;
  CeRunAppAtEvent(L"\\\\.\\Notifications\\NamedEvents\\TaskbarTimeChangeEvent",0);
  local_90[0] = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"TaskbarTimeChangeEvent");
  if (local_90[0] != (HANDLE)0x0) {
    iVar4 = CeRunAppAtEvent(L"\\\\.\\Notifications\\NamedEvents\\TaskbarTimeChangeEvent",1);
    if (iVar4 == 0) {
      CloseHandle(local_90[0]);
      local_90[0] = (HANDLE)0x0;
      local_84 = 0;
    }
    else {
      DVar8 = 1;
      local_80 = 1;
      bVar1 = true;
    }
  }
  nCount = DVar8;
  if (*(int *)(param_1 + 0x20) != 0) {
    memset(&local_70,0,0x14);
    local_70 = 0x14;
    local_6c = 0;
    local_68 = 0;
    local_64 = 0x2c;
    local_60 = 1;
    pvVar5 = (HANDLE)CreateMsgQueue(0,&local_70);
    local_90[DVar8] = pvVar5;
    if (pvVar5 != (HANDLE)0x0) {
      iVar10 = RequestPowerNotifications(pvVar5,8);
      local_7c = iVar10;
      if (iVar10 != 0) {
        nCount = DVar8 + 1;
        bVar2 = true;
        local_80 = nCount;
        local_78 = DVar8;
        goto LAB_00021c6c;
      }
      CloseHandle(local_90[DVar8]);
    }
    if (DVar8 == 0) goto LAB_00021e7c;
  }
LAB_00021c6c:
  DVar3 = local_84;
  DVar8 = nCount;
  if (nCount != 0) {
LAB_00021c7c:
    while (DVar8 = MsgWaitForMultipleObjectsEx(nCount,local_90,0xffffffff,0x7f,4), DVar8 != nCount)
    {
      if ((bVar1) && (DVar8 == local_88)) {
        if (*(HWND *)(param_1 + 8) != (HWND)0x0) {
          PostMessageW(*(HWND *)(param_1 + 8),0x403,0,0);
        }
      }
      else if ((bVar2) &&
              (((DVar8 == DVar3 &&
                (iVar4 = ReadMsgQueue(local_90[local_78],auStack_58,0x2c,auStack_5c,0,&local_84),
                iVar4 != 0)) && (*(int *)(param_1 + 0x20) != 0)))) {
        FUN_0002db24(*(int *)(param_1 + 0x20),*(HWND *)(param_1 + 8),(int)auStack_58);
      }
    }
LAB_00021d58:
    do {
      BVar6 = PeekMessageW(&local_b0,(HWND)0x0,0,0,1);
      if (BVar6 == 0) goto LAB_00021c7c;
      if (local_b0.message == 0x12) goto LAB_00021f84;
      if ((*(undefined4 **)(param_1 + 0x24) == (undefined4 *)0x0) ||
         (iVar4 = FUN_0002d12c(*(undefined4 **)(param_1 + 0x24),local_b0.hwnd,local_b0.message,
                               local_b0.wParam), iVar4 == 0)) {
        iVar4 = FUN_0002e4e4(param_1);
        if (iVar4 != 0) {
          pHVar7 = (HWND)FUN_0002e4e4(param_1);
          BVar6 = IsDialogMessageW(pHVar7,&local_b0);
          if (BVar6 != 0) goto LAB_00021d58;
        }
        if ((*(int *)(param_1 + 0x20) == 0) ||
           (iVar4 = FUN_0002e3c4(*(int *)(param_1 + 0x20),local_b0.hwnd,local_b0.message,
                                 local_b0.wParam), iVar4 == 0)) {
          TranslateMessage(&local_b0);
          DispatchMessageW(&local_b0);
        }
      }
    } while( true );
  }
LAB_00021e7c:
  do {
    BVar6 = GetMessageW(&local_b0,(HWND)0x0,0,0);
    nCount = DVar8;
    if (BVar6 == 0) {
LAB_00021f84:
      CeRunAppAtEvent(L"\\\\.\\Notifications\\NamedEvents\\TaskbarTimeChangeEvent",0);
      if (iVar10 != 0) {
        StopPowerNotifications(iVar10);
      }
      if (nCount != 0) {
        ppvVar9 = local_90;
        do {
          CloseHandle(*ppvVar9);
          ppvVar9 = ppvVar9 + 1;
          nCount = nCount - 1;
        } while (nCount != 0);
      }
      FUN_00033770(local_2c);
      return local_b0.wParam;
    }
  } while ((*(undefined4 **)(param_1 + 0x24) != (undefined4 *)0x0) &&
          (iVar4 = FUN_0002d12c(*(undefined4 **)(param_1 + 0x24),local_b0.hwnd,local_b0.message,
                                local_b0.wParam), iVar4 != 0));
  iVar4 = FUN_0002e4e4(param_1);
  if (iVar4 != 0) goto code_r0x00021ef8;
  goto LAB_00021f1c;
code_r0x00021ef8:
  pHVar7 = (HWND)FUN_0002e4e4(param_1);
  BVar6 = IsDialogMessageW(pHVar7,&local_b0);
  if (BVar6 == 0) {
LAB_00021f1c:
    if ((*(int *)(param_1 + 0x20) == 0) ||
       (iVar4 = FUN_0002e3c4(*(int *)(param_1 + 0x20),local_b0.hwnd,local_b0.message,local_b0.wParam
                            ), iVar4 == 0)) {
      TranslateMessage(&local_b0);
      DispatchMessageW(&local_b0);
    }
  }
  goto LAB_00021e7c;
}



/* 00022068 FUN_00022068 */

/* Boundary evidence: original MIPS .pdata 00022068..00022073. Semantic name remains unreviewed. */

undefined4 FUN_00022068(void)

{
  return 1;
}



/* 00022074 FUN_00022074 */

/* Boundary evidence: original MIPS .pdata 00022074..00022113. Semantic name remains unreviewed. */

void FUN_00022074(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 0x4c) != 0)) &&
     (iVar1 = param_3 - *(int *)(param_1 + 0x60), iVar2 = param_2 - *(int *)(param_1 + 0x5c),
     0x28 < iVar1 * iVar1 + iVar2 * iVar2)) {
    SetTimer(*(HWND *)(param_1 + 8),5,100,(TIMERPROC)0x0);
    *(int *)(param_1 + 0x5c) = param_2;
    *(int *)(param_1 + 0x60) = param_3;
  }
  return;
}



/* 00022114 FUN_00022114 */

/* Boundary evidence: original MIPS .pdata 00022114..0002249b. Semantic name remains unreviewed. */

void FUN_00022114(int param_1,HWND param_2,int *param_3,int param_4)

{
  LONG X;
  LONG LVar1;
  int iVar2;
  DWORD DVar3;
  DWORD DVar4;
  HWND pHVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  POINT Point;
  tagPOINT local_40;
  tagRECT local_38;
  
  if (*(int *)(param_1 + 0x6c) != 0) {
    ImageList_DragMove(-1,-1);
    ImageList_DragShowNolock(0);
  }
  if (*(int *)(param_1 + 0x70) != 0) {
    iVar8 = 200;
    if (param_4 == 0) {
      iVar8 = 0x15e;
    }
    iVar2 = GetThreadPriority((HANDLE)0x41);
    local_40.x = iVar2;
    SetThreadPriority((HANDLE)0x41,2);
    if (param_4 != 0) {
      SetWindowPos(param_2,(HWND)0xffffffff,0,0,0,0,0x13);
    }
    GetWindowRect(param_2,&local_38);
    iVar6 = param_3[1] - local_38.top;
    DVar3 = GetTickCount();
    LVar1 = local_38.right;
    iVar7 = local_38.top;
    X = local_38.left;
    DVar4 = GetTickCount();
    while (((int)DVar4 < (int)(DVar3 + iVar8) &&
           ((*(int *)(param_1 + 0x58) == 0 || (iVar2 = local_40.x, param_4 != 0))))) {
      iVar2 = (DVar4 - DVar3) * iVar6;
      if (iVar8 == 0) {
        trap(0x1c00);
      }
      if ((iVar8 == -1) && (iVar2 == -0x80000000)) {
        trap(0x1800);
      }
      iVar2 = iVar2 / iVar8 + local_38.top;
      if (iVar7 != iVar2) {
        MoveWindow(param_2,X,iVar2,LVar1 - X,local_38.bottom - iVar2,0);
        InvalidateRect(param_2,(RECT *)0x0,1);
        if (param_4 == 0) {
          iVar7 = local_38.right + local_38.left;
          if (iVar7 < 0) {
            iVar7 = iVar7 + 1;
          }
          Point.x = iVar7 >> 1;
          Point.y = local_38.top;
          pHVar5 = WindowFromPoint(Point);
          UpdateWindow(pHVar5);
        }
        UpdateWindow(param_2);
        iVar7 = iVar2;
      }
      DVar4 = GetTickCount();
      iVar2 = local_40.x;
    }
    SetThreadPriority((HANDLE)0x41,iVar2);
  }
  pHVar5 = (HWND)0xffffffff;
  if ((*(int *)(param_1 + 0x58) == 0) || (param_4 != 0)) {
    *(uint *)(param_1 + 0x4c) = (uint)(param_4 == 0);
    MoveWindow(param_2,*param_3,param_3[1],param_3[2] - *param_3,param_3[3] - param_3[1],0);
    InvalidateRect(param_2,(RECT *)0x0,1);
    UpdateWindow(param_2);
    if (param_4 == 0) {
      if (*(int *)(param_1 + 0x54) == 0) {
        pHVar5 = (HWND)0xfffffffe;
      }
      SetWindowPos(param_2,pHVar5,0,0,0,0,0x13);
    }
    if (*(int *)(param_1 + 0x6c) != 0) {
      GetCursorPos(&local_40);
      ImageList_DragShowNolock(1);
      ImageList_DragMove(local_40.x,local_40.y);
    }
  }
  return;
}



/* 0002249c FUN_0002249c */

/* Boundary evidence: original MIPS .pdata 0002249c..00022567. Semantic name remains unreviewed. */

void FUN_0002249c(int param_1)

{
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  KillTimer(*(HWND *)(param_1 + 8),5);
  if (*(int *)(param_1 + 0x4c) != 0) {
    local_18 = 0;
    local_10 = GetSystemMetrics(0);
    local_c = GetSystemMetrics(1);
    local_14 = local_c + -0x1a;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    ShowWindow(*(HWND *)(param_1 + 0x10),1);
    FUN_00022114(param_1,*(HWND *)(param_1 + 8),&local_18,1);
    if (*(int *)(param_1 + 0x58) != 0) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      ShowWindow(*(HWND *)(param_1 + 0x10),1);
    }
    if ((*(int *)(param_1 + 0x6c) != 0) && (*(int *)(param_1 + 0x50) != 0)) {
      SetTimer(*(HWND *)(param_1 + 8),6,500,(TIMERPROC)0x0);
    }
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  return;
}



/* 00022568 FUN_00022568 */

/* Boundary evidence: original MIPS .pdata 00022568..000226e3. Semantic name remains unreviewed. */

void FUN_00022568(int param_1,HWND param_2)

{
  BOOL BVar1;
  POINT local_28;
  tagRECT local_20;
  
  GetCursorPos(&local_28);
  GetWindowRect(param_2,&local_20);
  InflateRect(&local_20,6,6);
  PtInRect(&local_20,local_28);
  if ((*(int *)(param_1 + 0x78) == 0) &&
     ((((BVar1 = GetCursorPos(&local_28), BVar1 == 0 ||
        (BVar1 = GetWindowRect(*(HWND *)(param_1 + 8),&local_20), BVar1 == 0)) ||
       (BVar1 = InflateRect(&local_20,6,6), BVar1 == 0)) ||
      (BVar1 = PtInRect(&local_20,local_28), BVar1 == 0)))) {
    KillTimer(*(HWND *)(param_1 + 8),5);
    KillTimer(*(HWND *)(param_1 + 8),6);
    if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 0x4c) == 0)) {
      local_20.left = 0;
      local_20.right = GetSystemMetrics(0);
      local_20.bottom = GetSystemMetrics(1);
      local_20.top = local_20.bottom + -5;
      FUN_00022114(param_1,*(HWND *)(param_1 + 8),&local_20.left,0);
      if (*(int *)(param_1 + 0x58) == 0) {
        *(undefined4 *)(param_1 + 0x4c) = 1;
        ShowWindow(*(HWND *)(param_1 + 0x10),0);
      }
    }
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  else if ((*(int *)(param_1 + 0x6c) != 0) && (*(int *)(param_1 + 0x50) != 0)) {
    SetTimer(*(HWND *)(param_1 + 8),6,500,(TIMERPROC)0x0);
  }
  return;
}



/* 000226e4 FUN_000226e4 */

/* Boundary evidence: original MIPS .pdata 000226e4..00022773. Semantic name remains unreviewed. */

undefined4 FUN_000226e4(int param_1)

{
  HWND pHVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  pHVar1 = GetForegroundWindow();
  if ((((pHVar1 != (HWND)0x0) &&
       ((pHVar1 == *(HWND *)(param_1 + 8) ||
        (pHVar1 = GetParent(pHVar1), pHVar1 == *(HWND *)(param_1 + 8))))) ||
      (*(int *)(param_1 + 0x78) != 0)) ||
     (((*(int *)(param_1 + 0x28) != 0 && (*(int *)(*(int *)(param_1 + 0x28) + 0x228) != 0)) ||
      (*(int *)(param_1 + 0x7c) != 0)))) {
    uVar2 = 1;
  }
  return uVar2;
}



/* 00022774 FUN_00022774 */

/* Boundary evidence: original MIPS .pdata 00022774..000227fb. Semantic name remains unreviewed. */

void FUN_00022774(int param_1,HWND param_2)

{
  uint uVar1;
  HWND pHVar2;
  
  pHVar2 = (HWND)0xffffffff;
  if (param_2 == (HWND)0x0) {
    param_2 = (HWND)0xffffffff;
  }
  uVar1 = GetWindowLongW(*(HWND *)(param_1 + 8),-0x14);
  if ((uVar1 & 8) == 0) {
    pHVar2 = (HWND)0xfffffffe;
  }
  if (param_2 != pHVar2) {
    SetWindowPos(*(HWND *)(param_1 + 8),param_2,0,0,0,0,0x13);
  }
  return;
}



/* 000227fc FUN_000227fc */

/* Boundary evidence: original MIPS .pdata 000227fc..0002289f. Semantic name remains unreviewed. */

void FUN_000227fc(int param_1,int param_2)

{
  int iVar1;
  HWND pHVar2;
  
  if ((param_2 == 0) || (*(char *)(param_2 + 0x229) == '\0')) {
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 0x1c);
  }
  if ((*(int *)(param_1 + 0x54) == 0) || (*(int *)(param_1 + 0xa0) != 0)) {
    iVar1 = FUN_000226e4(param_1);
    if (iVar1 != 0) {
      pHVar2 = (HWND)0x0;
      goto LAB_00022888;
    }
    pHVar2 = (HWND)0x1;
    if (*(int *)(param_1 + 0xa0) != 0) goto LAB_00022888;
  }
  else if ((param_2 == 0) || (*(char *)(param_2 + 0x22a) == '\0')) {
    pHVar2 = (HWND)0xffffffff;
    goto LAB_00022888;
  }
  pHVar2 = (HWND)0xfffffffe;
LAB_00022888:
  FUN_00022774(param_1,pHVar2);
  return;
}



/* 000228a0 FUN_000228a0 */

/* Boundary evidence: original MIPS .pdata 000228a0..00022993. Semantic name remains unreviewed. */

void FUN_000228a0(undefined4 param_1,undefined4 param_2)

{
  LSTATUS LVar1;
  undefined4 local_res4 [3];
  HKEY local_18;
  DWORD DStack_14;
  
  local_res4[0] = param_2;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Shell\\AutoHide",0,0xf003f,&local_18
                       );
  if ((LVar1 != 0) &&
     (LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Shell\\AutoHide",0,(LPWSTR)0x0
                              ,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_18,&DStack_14),
     LVar1 != 0)) {
    return;
  }
  RegSetValueExW(local_18,L"",0,4,(BYTE *)local_res4,4);
  RegCloseKey(local_18);
  return;
}



/* 00022994 FUN_00022994 */

/* Boundary evidence: original MIPS .pdata 00022994..00022a53. Semantic name remains unreviewed. */

undefined4 FUN_00022994(undefined4 param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_20;
  DWORD local_1c;
  DWORD aDStack_18 [2];
  
  local_1c = 4;
  uVar2 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Shell\\AutoHide",0,0,&local_20);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_20,L"",(LPDWORD)0x0,aDStack_18,param_2,&local_1c);
    RegCloseKey(local_20);
    if (LVar1 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* 00022a54 FUN_00022a54 */

/* Boundary evidence: original MIPS .pdata 00022a54..00022b47. Semantic name remains unreviewed. */

void FUN_00022a54(undefined4 param_1,undefined4 param_2)

{
  LSTATUS LVar1;
  undefined4 local_res4 [3];
  HKEY local_18;
  DWORD DStack_14;
  
  local_res4[0] = param_2;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Explorer",0,0xf003f,&local_18);
  if ((LVar1 != 0) &&
     (LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"Explorer",0,(LPWSTR)0x0,0,0xf003f,
                              (LPSECURITY_ATTRIBUTES)0x0,&local_18,&DStack_14), LVar1 != 0)) {
    return;
  }
  RegSetValueExW(local_18,L"ExpandControlPanel",0,4,(BYTE *)local_res4,4);
  RegCloseKey(local_18);
  return;
}



/* 00022b48 FUN_00022b48 */

/* Boundary evidence: original MIPS .pdata 00022b48..00022c07. Semantic name remains unreviewed. */

undefined4 FUN_00022b48(undefined4 param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_20;
  DWORD local_1c;
  DWORD aDStack_18 [2];
  
  local_1c = 4;
  uVar2 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Explorer",0,0,&local_20);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_20,L"ExpandControlPanel",(LPDWORD)0x0,aDStack_18,param_2,
                             &local_1c);
    RegCloseKey(local_20);
    if (LVar1 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* 00022c08 FUN_00022c08 */

/* Boundary evidence: original MIPS .pdata 00022c08..00022cab. Semantic name remains unreviewed. */

undefined4 FUN_00022c08(undefined4 param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  HKEY local_18;
  DWORD local_14;
  DWORD aDStack_10 [2];
  
  param_2[0] = '\x01';
  param_2[1] = '\0';
  param_2[2] = '\0';
  param_2[3] = '\0';
  local_14 = 4;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Shell\\SlideTaskBar",0,0,&local_18);
  if (LVar1 == 0) {
    RegQueryValueExW(local_18,L"",(LPDWORD)0x0,aDStack_10,param_2,&local_14);
    RegCloseKey(local_18);
  }
  return 1;
}



/* 00022cac FUN_00022cac */

/* Boundary evidence: original MIPS .pdata 00022cac..00022d4b. Semantic name remains unreviewed. */

undefined4 FUN_00022cac(undefined4 param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  HKEY local_18;
  DWORD local_14;
  DWORD aDStack_10 [2];
  
  local_14 = 4;
  param_2[0] = '\0';
  param_2[1] = '\0';
  param_2[2] = '\0';
  param_2[3] = '\0';
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Shell\\TameStartMenu",0,0,&local_18)
  ;
  if (LVar1 == 0) {
    RegQueryValueExW(local_18,L"",(LPDWORD)0x0,aDStack_10,param_2,&local_14);
    RegCloseKey(local_18);
  }
  return 1;
}



/* 00022d4c FUN_00022d4c */

/* Boundary evidence: original MIPS .pdata 00022d4c..00022e3f. Semantic name remains unreviewed. */

void FUN_00022d4c(undefined4 param_1,undefined4 param_2)

{
  LSTATUS LVar1;
  undefined4 local_res4 [3];
  HKEY local_18;
  DWORD DStack_14;
  
  local_res4[0] = param_2;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Shell\\OnTop",0,0xf003f,&local_18);
  if ((LVar1 != 0) &&
     (LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Shell\\OnTop",0,(LPWSTR)0x0,0,
                              0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_18,&DStack_14), LVar1 != 0))
  {
    return;
  }
  RegSetValueExW(local_18,L"",0,4,(BYTE *)local_res4,4);
  RegCloseKey(local_18);
  return;
}



/* 00022e40 FUN_00022e40 */

/* Boundary evidence: original MIPS .pdata 00022e40..00022eff. Semantic name remains unreviewed. */

undefined4 FUN_00022e40(undefined4 param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_20;
  DWORD local_1c;
  DWORD aDStack_18 [2];
  
  local_1c = 4;
  uVar2 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Shell\\OnTop",0,0,&local_20);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_20,L"",(LPDWORD)0x0,aDStack_18,param_2,&local_1c);
    RegCloseKey(local_20);
    if (LVar1 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* 00022f00 FUN_00022f00 */

/* Boundary evidence: original MIPS .pdata 00022f00..00022fef. Semantic name remains unreviewed. */

void FUN_00022f00(int param_1)

{
  int yBottom;
  int xRight;
  tagRECT local_30;
  undefined4 local_20;
  undefined1 auStack_1c [8];
  int local_14;
  
  local_20 = 0;
  memset(auStack_1c,0,0xc);
  local_30.left = 0;
  memset(&local_30.top,0,0xc);
  SystemParametersInfoW(0x30,0,&local_20,0);
  yBottom = GetSystemMetrics(1);
  xRight = GetSystemMetrics(0);
  SetRect(&local_30,0,0,xRight,yBottom);
  if (*(int *)(param_1 + 0x54) != 0) {
    if (*(int *)(param_1 + 0x50) == 0) {
      local_30.bottom = local_30.bottom + -0x1a;
    }
    else {
      local_30.bottom = local_30.bottom + -5;
    }
  }
  if (local_14 != local_30.bottom) {
    SystemParametersInfoW(0x2f,0,&local_30,2);
  }
  FUN_0002c7e4();
  return;
}



/* 00022ff0 FUN_00022ff0 */

/* Boundary evidence: original MIPS .pdata 00022ff0..00023123. Semantic name remains unreviewed. */

undefined4 FUN_00022ff0(HWND param_1,int *param_2)

{
  uint uVar1;
  int Y;
  tagRECT local_20;
  
  if ((param_1 != *(HWND *)(DAT_0003556c + 8)) && (param_1 != *(HWND *)(DAT_00035570 + 4))) {
    uVar1 = GetWindowLongW(param_1,-0x10);
    GetWindowRect(param_1,&local_20);
    if ((((uVar1 & 0x80000000) == 0) &&
        (((local_20.left == 0 && (local_20.top == 0)) && (local_20.bottom == param_2[1])))) &&
       (local_20.right == *param_2)) {
      MoveWindow(param_1,0,0,param_2[2],param_2[3],0);
      InvalidateRect(param_1,(RECT *)0x0,1);
    }
    else if (param_2[3] < local_20.bottom) {
      Y = (param_2[3] - local_20.bottom) + local_20.top;
      if (Y < 0) {
        Y = 0;
      }
      SetWindowPos(param_1,(HWND)0x0,local_20.left,Y,0,0,5);
    }
  }
  return 1;
}



/* 00023124 FUN_00023124 */

/* Boundary evidence: original MIPS .pdata 00023124..000231e7. Semantic name remains unreviewed. */

void FUN_00023124(undefined4 param_1,int param_2,int param_3)

{
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_20 = 0;
  memset(&local_1c,0,0xc);
  local_28 = GetSystemMetrics(0);
  local_24 = GetSystemMetrics(1);
  SystemParametersInfoW(0x30,0,&local_20,0);
  local_30 = local_18 - local_20;
  local_2c = local_14 - local_1c;
  if (param_3 != 0) {
    if (param_2 == 0) {
      local_24 = local_24 + -5;
    }
    else {
      local_24 = local_24 + -0x1a;
    }
  }
  EnumWindows(FUN_00022ff0,(LPARAM)&local_30);
  return;
}



/* 000231e8 FUN_000231e8 */

/* Boundary evidence: original MIPS .pdata 000231e8..00023387. Semantic name remains unreviewed. */

int FUN_000231e8(void)

{
  HRESULT HVar1;
  int iVar2;
  int iVar3;
  int *local_28;
  IMalloc *local_24;
  int local_20;
  void *local_1c;
  int *local_18;
  LPITEMIDLIST local_14;
  IShellFolder *local_10 [2];
  
  iVar3 = 0;
  local_10[0] = (IShellFolder *)0x0;
  local_14 = (LPCITEMIDLIST)0x0;
  local_18 = (int *)0x0;
  local_28 = (int *)0x0;
  local_24 = (IMalloc *)0x0;
  local_1c = (void *)0x0;
  local_20 = 0;
  HVar1 = SHGetMalloc(&local_24);
  if (HVar1 < 0) {
    iVar3 = 0;
  }
  else {
    HVar1 = SHGetDesktopFolder(local_10);
    if (-1 < HVar1) {
      HVar1 = SHGetSpecialFolderLocation((HWND)0x0,8,&local_14);
      if (-1 < HVar1) {
        HVar1 = (*local_10[0]->lpVtbl->BindToObject)
                          (local_10[0],local_14,(IBindCtx *)0x0,(IID *)&DAT_00012000,&local_18);
        if (-1 < HVar1) {
          iVar2 = (**(code **)(*local_18 + 0x10))(local_18,0,0x40,&local_28);
          if (-1 < iVar2) {
            while ((iVar2 = (**(code **)(*local_28 + 0xc))(local_28,1,&local_1c,&local_20),
                   iVar2 == 0 && (local_20 != 0))) {
              iVar3 = local_20 + iVar3;
              (*local_24->lpVtbl->Free)(local_24,local_1c);
            }
            (**(code **)(*local_28 + 8))();
          }
          (**(code **)(*local_18 + 8))();
        }
        (*local_24->lpVtbl->Free)(local_24,local_14);
      }
      (*local_10[0]->lpVtbl->Release)(local_10[0]);
    }
    (*local_24->lpVtbl->Release)(local_24);
  }
  return iVar3;
}



/* 00023388 FUN_00023388 */

/* Boundary evidence: original MIPS .pdata 00023388..0002348f. Semantic name remains unreviewed. */

int * FUN_00023388(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if (param_3 < -7) {
LAB_00023478:
    piVar1 = (int *)FUN_00021594((int *)*param_1,param_3);
    return piVar1;
  }
  if (-6 < param_3) {
    if (-3 < param_3) {
      if (param_3 == -2) {
        for (piVar1 = *(int **)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
          if ((*(uint *)(piVar1[2] + 8) & 0x40) != 0) {
            return piVar1;
          }
        }
      }
      else if (param_3 != -1) {
        if (param_3 == 0) {
          return *(int **)*param_1;
        }
        goto LAB_00023478;
      }
    }
    piVar1 = *(int **)(*param_1 + 4);
    if (param_3 == -5) {
      return piVar1;
    }
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)*piVar1;
    }
    if (param_3 == -4) {
      return piVar1;
    }
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)*piVar1;
    }
    if (param_3 == -3) {
      return piVar1;
    }
    if (piVar1 != (int *)0x0) {
      return (int *)*piVar1;
    }
  }
  return (int *)0x0;
}



/* 00023490 FUN_00023490 */

/* Boundary evidence: original MIPS .pdata 00023490..000235a3. Semantic name remains unreviewed. */

undefined4 FUN_00023490(undefined4 *param_1,undefined4 param_2,LPRECT param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 == (LPRECT)0x0) {
    uVar1 = 0;
  }
  else {
    piVar3 = (int *)((int *)*param_1)[1];
    if (((piVar3 == (int *)0x0) || ((int *)*piVar3 == (int *)0x0)) ||
       (piVar2 = *(int **)*piVar3, piVar2 == (int *)0x0)) {
      iVar4 = 0;
    }
    else {
      iVar4 = *piVar2;
    }
    for (iVar5 = *(int *)*param_1; iVar5 != 0; iVar5 = *(int *)(iVar5 + 4)) {
      if ((*(uint *)(*(int *)(iVar5 + 8) + 8) & 0x40) != 0) goto LAB_00023544;
    }
    if (((piVar3 == (int *)0x0) || ((int *)*piVar3 == (int *)0x0)) ||
       (piVar3 = *(int **)*piVar3, piVar3 == (int *)0x0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = *piVar3;
    }
LAB_00023544:
    CopyRect(param_3,(RECT *)(*(int *)(iVar4 + 8) + 0xc));
    iVar4 = *(int *)(*(int *)(iVar5 + 8) + 0xc) + param_1[0x31] * -2;
    param_3->left = iVar4;
    if (0 < (int)param_1[0x2f]) {
      param_3->left = (iVar4 - param_1[0x31]) + -5;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 000235a4 FUN_000235a4 */

/* Boundary evidence: original MIPS .pdata 000235a4..00023643. Semantic name remains unreviewed. */

undefined4 FUN_000235a4(int param_1)

{
  LSTATUS LVar1;
  HKEY local_18;
  DWORD local_14;
  DWORD aDStack_10 [2];
  
  local_14 = 4;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Clock",0,0,&local_18);
  if (LVar1 == 0) {
    RegQueryValueExW(local_18,L"SHOW_CLOCK",(LPDWORD)0x0,aDStack_10,(LPBYTE)(param_1 + 0x3c),
                     &local_14);
    RegCloseKey(local_18);
  }
  return *(undefined4 *)(param_1 + 0x3c);
}



/* 00023644 FUN_00023644 */

/* Boundary evidence: original MIPS .pdata 00023644..000237c3. Semantic name remains unreviewed. */

undefined4 FUN_00023644(int *param_1,int *param_2)

{
  HDC hdc;
  HGDIOBJ h;
  size_t cchString;
  int *piVar1;
  int iVar2;
  tagSIZE local_a8;
  WCHAR aWStack_a0 [64];
  uint local_20;
  
  local_20 = DAT_00035518;
  if ((*(int **)(*param_1 + 4) == (int *)0x0) ||
     (piVar1 = (int *)**(int **)(*param_1 + 4), piVar1 == (int *)0x0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar1;
  }
  iVar2 = *(int *)(*(int *)(iVar2 + 8) + 0xc);
  param_2[2] = iVar2 + -1;
  *param_2 = iVar2 + -5;
  if (param_1[0xf] != 0) {
    hdc = GetDC((HWND)param_1[2]);
    h = (HGDIOBJ)local_a8.cx;
    if ((HGDIOBJ)param_1[0xc] != (HGDIOBJ)0x0) {
      h = SelectObject(hdc,(HGDIOBJ)param_1[0xc]);
    }
    iVar2 = GetTimeFormatW(0x400,2,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,aWStack_a0,0x40);
    if (iVar2 != 0) {
      cchString = wcslen(aWStack_a0);
      GetTextExtentExPointW(hdc,aWStack_a0,cchString,1000,(LPINT)0x0,(LPINT)0x0,&local_a8);
      if (param_1[0x20] == 0) {
        iVar2 = 0xc;
      }
      else {
        iVar2 = param_1[0x31] * 2 + 1;
      }
      *param_2 = (param_2[2] - iVar2) - local_a8.cx;
    }
    if (param_1[0xc] != 0) {
      SelectObject(hdc,h);
    }
    ReleaseDC((HWND)param_1[2],hdc);
  }
  FUN_00033770(local_20);
  return 1;
}



/* 000237c4 FUN_000237c4 */

/* Boundary evidence: original MIPS .pdata 000237c4..0002390f. Semantic name remains unreviewed. */

undefined4 FUN_000237c4(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar1 = GetSystemMetrics(0);
  puVar3 = *(undefined4 **)(*param_1 + 4);
  if (puVar3 != (undefined4 *)0x0) {
    *(int *)(puVar3[2] + 0x14) = iVar1;
    if (param_1[0x26] == 0) {
      *(undefined4 *)(puVar3[2] + 0xc) = *(undefined4 *)(puVar3[2] + 0x14);
    }
    else {
      *(int *)(puVar3[2] + 0xc) = iVar1 + -0x17;
      InvalidateRect((HWND)param_1[2],(RECT *)(puVar3[2] + 0xc),0);
    }
    iVar1 = *(int *)(puVar3[2] + 0xc);
    piVar4 = (int *)*puVar3;
    if (piVar4 != (int *)0x0) {
      *(int *)(piVar4[2] + 0x14) = iVar1 + -1;
      if (param_1[0x22] == 0) {
        *(undefined4 *)(piVar4[2] + 0xc) = *(undefined4 *)(piVar4[2] + 0x14);
      }
      else {
        *(int *)(piVar4[2] + 0xc) = iVar1 + -0x18;
        InvalidateRect((HWND)param_1[2],(RECT *)(piVar4[2] + 0xc),0);
      }
      iVar1 = *(int *)(piVar4[2] + 0xc);
      iVar2 = *piVar4;
      if (iVar2 != 0) {
        *(int *)(*(int *)(iVar2 + 8) + 0x14) = iVar1 + -1;
        if (param_1[0x21] == 0) {
          *(undefined4 *)(*(int *)(iVar2 + 8) + 0xc) = *(undefined4 *)(*(int *)(iVar2 + 8) + 0x14);
        }
        else {
          *(int *)(*(int *)(iVar2 + 8) + 0xc) = iVar1 + -0x18;
          InvalidateRect((HWND)param_1[2],(RECT *)(*(int *)(iVar2 + 8) + 0xc),0);
        }
        return 1;
      }
    }
  }
  return 0;
}



/* 00023910 FUN_00023910 */

/* Boundary evidence: original MIPS .pdata 00023910..00023da3. Semantic name remains unreviewed. */

undefined4 FUN_00023910(int *param_1,HINSTANCE param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  HDC hdc;
  size_t cchString;
  BOOL BVar3;
  HANDLE pvVar4;
  HGDIOBJ h;
  wchar_t *lpBuffer;
  tagSIZE local_30;
  
  h = (HGDIOBJ)0x0;
  if ((*param_1 == 0) && (param_2 != (HINSTANCE)0x0)) {
    puVar1 = operator_new(0x20);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 3));
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
    }
    *param_1 = (int)puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = operator_new(0x228);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = FUN_0002fa6c(puVar1,0,4,0,2,0x34,0x19,0,L"");
      }
      puVar2 = LocalAlloc(0,0xc);
      if ((puVar1 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
        if (param_1[0x20] == 0) {
          lpBuffer = (wchar_t *)(puVar1 + 8);
          LoadStringW(param_2,0x5209,lpBuffer,0x104);
          hdc = GetDC((HWND)0x0);
          if ((HGDIOBJ)param_1[0xc] != (HGDIOBJ)0x0) {
            h = SelectObject(hdc,(HGDIOBJ)param_1[0xc]);
          }
          cchString = wcslen(lpBuffer);
          BVar3 = GetTextExtentExPointW(hdc,lpBuffer,cchString,1000,(LPINT)0x0,(LPINT)0x0,&local_30)
          ;
          if (BVar3 != 0) {
            puVar1[5] = puVar1[3] + local_30.cx + 0x1e;
          }
          if (param_1[0xc] != 0) {
            SelectObject(hdc,h);
          }
          ReleaseDC((HWND)0x0,hdc);
        }
        else {
          puVar1[5] = puVar1[3] + 0x18;
        }
        pvVar4 = LoadImageW(param_2,(LPCWSTR)0x2,1,0x10,0x10,0);
        puVar1[1] = pvVar4;
        puVar2[2] = puVar1;
        FUN_00021480((undefined4 *)*param_1,puVar2);
        param_1[0x2b] = 1;
        puVar1 = operator_new(0x228);
        if (puVar1 == (undefined4 *)0x0) {
          puVar1 = (undefined4 *)0x0;
        }
        else {
          puVar1 = FUN_0002fa6c(puVar1,0,0x10,0,2,0,0x19,0xffffffff,L"");
        }
        puVar2 = LocalAlloc(0,0xc);
        if ((puVar1 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
          puVar2[2] = puVar1;
          FUN_00021480((undefined4 *)*param_1,puVar2);
          puVar1 = operator_new(0x228);
          if (puVar1 == (undefined4 *)0x0) {
            puVar1 = (undefined4 *)0x0;
          }
          else {
            puVar1 = FUN_0002fa6c(puVar1,0,4,0,2,0x34,0x19,0xfffffffd,L"");
          }
          puVar2 = LocalAlloc(0,0xc);
          if ((puVar1 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
            pvVar4 = LoadImageW(param_2,(LPCWSTR)0x4b8,1,0x10,0x10,0);
            puVar1[1] = pvVar4;
            puVar2[2] = puVar1;
            FUN_00021480((undefined4 *)*param_1,puVar2);
            puVar1 = operator_new(0x228);
            if (puVar1 == (undefined4 *)0x0) {
              puVar1 = (undefined4 *)0x0;
            }
            else {
              puVar1 = FUN_0002fa6c(puVar1,0,4,0,2,0x34,0x19,0xfffffffc,L"");
            }
            puVar2 = LocalAlloc(0,0xc);
            if ((puVar1 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
              pvVar4 = LoadImageW(param_2,(LPCWSTR)0x4d4,1,0x10,0x10,0);
              puVar1[1] = pvVar4;
              param_1[0x23] = (int)pvVar4;
              pvVar4 = LoadImageW(param_2,(LPCWSTR)0x4d5,1,0x10,0x10,0);
              param_1[0x24] = (int)pvVar4;
              param_1[0x25] = (int)pvVar4;
              puVar2[2] = puVar1;
              FUN_00021480((undefined4 *)*param_1,puVar2);
              puVar1 = (undefined4 *)param_1[10];
              if (puVar1 != (undefined4 *)0x0) {
                (**(code **)*puVar1)(puVar1,1);
                param_1[10] = 0;
              }
              puVar1 = operator_new(0x22c);
              if (puVar1 == (undefined4 *)0x0) {
                puVar1 = (undefined4 *)0x0;
              }
              else {
                puVar1 = FUN_0002f084(puVar1,0,2,0x34,0x19);
              }
              param_1[10] = (int)puVar1;
              puVar1 = LocalAlloc(0,0xc);
              if ((param_1[10] != 0) && (puVar1 != (undefined4 *)0x0)) {
                puVar1[2] = param_1[10];
                FUN_00021480((undefined4 *)*param_1,puVar1);
                return 1;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



/* 00023da4 FUN_00023da4 */

/* Boundary evidence: original MIPS .pdata 00023da4..00023e07. Semantic name remains unreviewed. */

int FUN_00023da4(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)*param_1;
  while( true ) {
    if (iVar1 == 0) {
      return -1;
    }
    if ((param_3 == *(int *)(*(int *)(iVar1 + 8) + 0x1c)) &&
       ((*(uint *)(*(int *)(iVar1 + 8) + 8) & 0x40) == 0)) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  iVar1 = FUN_00021514((int *)*param_1,iVar1);
  return iVar1;
}



/* 00023e08 FUN_00023e08 */

/* Boundary evidence: original MIPS .pdata 00023e08..00023ea7. Semantic name remains unreviewed. */

int FUN_00023e08(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    for (iVar2 = *piVar1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      iVar3 = *(int *)(iVar2 + 8);
      if (((((*(uint *)(iVar3 + 8) & 0x40) != 0) && ((*(uint *)(iVar3 + 8) & 0x80) == 0)) &&
          (*(int *)(param_3 + 4) == *(int *)(iVar3 + 0x1c))) &&
         (*(int *)(param_3 + 8) == *(int *)(iVar3 + 0x228))) {
        iVar2 = FUN_00021514(piVar1,iVar2);
        return iVar2;
      }
    }
  }
  return -1;
}



/* 00023ea8 FUN_00023ea8 */

undefined4 FUN_00023ea8(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((int *)*param_1 != (int *)0x0) {
    for (iVar1 = *(int *)*param_1; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      iVar2 = *(int *)(iVar1 + 8);
      if (((((*(uint *)(iVar2 + 8) & 0x40) != 0) && ((*(uint *)(iVar2 + 8) & 0x80) == 0)) &&
          (*(int *)(param_3 + 4) == *(int *)(iVar2 + 0x1c))) &&
         (*(int *)(param_3 + 8) == *(int *)(iVar2 + 0x228))) {
        *(uint *)(*(int *)(iVar1 + 8) + 8) = *(uint *)(*(int *)(iVar1 + 8) + 8) | 0x10000000;
        return 1;
      }
    }
  }
  return 0;
}



/* 00023f44 FUN_00023f44 */

/* Boundary evidence: original MIPS .pdata 00023f44..0002400b. Semantic name remains unreviewed. */

uint FUN_00023f44(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_00021594((int *)*param_1,param_4);
  if ((iVar1 == 0) || ((*(uint *)(*(int *)(iVar1 + 8) + 8) & 0x40) == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00030368(*(int *)(iVar1 + 8),param_3);
    uVar2 = 1;
    if (((*(uint *)(param_3 + 0xc) & 2) == 0) || (*(int *)(param_3 + 0x14) == 0)) {
      uVar2 = 0;
    }
    if ((uVar2 & uVar3) != 0) {
      InvalidateRect((HWND)param_1[4],(RECT *)0x0,1);
      UpdateWindow((HWND)param_1[4]);
    }
  }
  return uVar3;
}



/* 0002400c FUN_0002400c */

/* Boundary evidence: original MIPS .pdata 0002400c..0002457b. Semantic name remains unreviewed. */

undefined4 FUN_0002400c(int *param_1,HWND param_2)

{
  BOOL BVar1;
  LPRECT lprcDst;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  RECT local_68;
  undefined4 local_58;
  undefined1 auStack_54 [4];
  HWND local_50;
  int local_4c;
  tagPOINT local_48;
  undefined4 local_40;
  undefined4 local_3c;
  
  local_58 = 0;
  iVar10 = 0;
  memset(auStack_54,0,0x28);
  piVar5 = (int *)((int *)*param_1)[1];
  iVar9 = *(int *)*param_1;
  iVar7 = iVar9;
  if (((piVar5 == (int *)0x0) || ((undefined4 *)*piVar5 == (undefined4 *)0x0)) ||
     (puVar2 = *(undefined4 **)*piVar5, puVar2 == (undefined4 *)0x0)) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)*puVar2;
  }
  for (; iVar7 != 0; iVar7 = *(int *)(iVar7 + 4)) {
    if ((*(uint *)(*(int *)(iVar7 + 8) + 8) & 0x40) != 0) goto LAB_000240e4;
  }
  if (((piVar5 == (int *)0x0) || ((int *)*piVar5 == (int *)0x0)) ||
     (piVar5 = *(int **)*piVar5, piVar5 == (int *)0x0)) {
    iVar7 = 0;
  }
  else {
    iVar7 = *piVar5;
  }
LAB_000240e4:
  piVar5 = (int *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    piVar5 = (int *)*puVar2;
  }
  iVar6 = *(int *)(puVar2[2] + 0xc);
  iVar3 = param_1[0x30];
  iVar8 = param_1[0x2d];
  if (param_1[0x2f] < iVar3 - param_1[0x2e]) {
    iVar6 = (iVar6 - param_1[0x31]) + -5;
  }
  while ((piVar5 != (int *)0x0 && (iVar3 = iVar3 + -1, (*(uint *)(piVar5[2] + 8) & 0x40) != 0))) {
    if ((iVar3 < param_1[0x2f]) || (param_1[0x2e] + param_1[0x2f] <= iVar3)) {
      *(int *)(piVar5[2] + 0x14) = iVar6;
      *(undefined4 *)(piVar5[2] + 0xc) = *(undefined4 *)(piVar5[2] + 0x14);
    }
    else {
      *(int *)(piVar5[2] + 0x14) = iVar6 - param_1[0x31];
      if ((*(uint *)(piVar5[2] + 8) & 0x100) == 0) {
        *(int *)(piVar5[2] + 0xc) = *(int *)(piVar5[2] + 0x14) + -0x10;
      }
      else {
        FUN_0002ba40(piVar5[2],(HWND)param_1[2]);
      }
      iVar6 = *(int *)(piVar5[2] + 0xc);
    }
    *(undefined4 *)(piVar5[2] + 0x10) = 6;
    *(undefined4 *)(piVar5[2] + 0x18) = 0x16;
    piVar5 = (int *)*piVar5;
  }
  iVar3 = param_1[0x2c];
  if (0 < iVar3) {
    iVar4 = param_1[0x32];
    iVar6 = iVar8;
    if (iVar8 < iVar4) {
      iVar6 = iVar4;
    }
    if (iVar3 < iVar6) {
      iVar6 = iVar3;
    }
    local_68.left = *(int *)(*(int *)(iVar9 + 8) + 0x14);
    iVar3 = (*(int *)(*(int *)(iVar7 + 8) + 0xc) + param_1[0x31] * -3) - local_68.left;
    if (0 < param_1[0x2f]) {
      iVar3 = iVar3 + -5;
    }
    if (iVar8 < iVar4) {
      iVar8 = 0;
    }
    else {
      iVar8 = iVar3 % iVar6;
      if (iVar6 == 0) {
        trap(0x1c00);
      }
      if ((iVar6 == -1) && (iVar3 == -0x80000000)) {
        trap(0x1800);
      }
    }
    iVar4 = iVar3 / iVar6;
    if (iVar6 == 0) {
      trap(0x1c00);
    }
    if ((iVar6 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    local_68.right = local_68.left + iVar4;
    local_68.top = 2;
    local_68.bottom = 0x19;
    for (iVar9 = *(int *)(iVar9 + 4); iVar9 != iVar7; iVar9 = *(int *)(iVar9 + 4)) {
      iVar6 = iVar6 + -1;
      lprcDst = (LPRECT)(*(int *)(iVar9 + 8) + 0xc);
      if (iVar8 == 0) {
        CopyRect(lprcDst,&local_68);
        OffsetRect((LPRECT)(*(int *)(iVar9 + 8) + 0xc),iVar10,0);
        iVar10 = iVar4 + iVar10;
        iVar8 = 0;
      }
      else {
        CopyRect(lprcDst,&local_68);
        *(int *)(*(int *)(iVar9 + 8) + 0x14) = *(int *)(*(int *)(iVar9 + 8) + 0x14) + 1;
        OffsetRect((LPRECT)(*(int *)(iVar9 + 8) + 0xc),iVar10,0);
        iVar10 = iVar4 + iVar10 + 1;
        iVar8 = iVar8 + -1;
      }
      *(int *)(*(int *)(iVar9 + 8) + 0xc) = *(int *)(*(int *)(iVar9 + 8) + 0xc) + param_1[0x31];
      if ((iVar6 < 0) ||
         ((param_1[0x20] != 0 &&
          (BVar1 = IsWindowVisible(*(HWND *)(*(int *)(iVar9 + 8) + 0x1c)), BVar1 == 0)))) {
        *(undefined4 *)(*(int *)(iVar9 + 8) + 0x14) = *(undefined4 *)(*(int *)(iVar9 + 8) + 0xc);
      }
      local_50 = (HWND)param_1[2];
      local_58 = 0x2c;
      iVar3 = *(int *)(iVar9 + 8);
      local_48.x = *(LONG *)(iVar3 + 0xc);
      local_48.y = *(LONG *)(iVar3 + 0x10);
      local_40 = *(undefined4 *)(iVar3 + 0x14);
      local_3c = *(undefined4 *)(iVar3 + 0x18);
      local_4c = iVar9;
      SendMessageW((HWND)param_1[3],0x434,0,(LPARAM)&local_58);
    }
  }
  FUN_00023490(param_1,param_2,&local_68);
  MoveWindow((HWND)param_1[4],local_68.left,local_68.top,local_68.right - local_68.left,
             local_68.bottom - local_68.top,0);
  InvalidateRect((HWND)param_1[4],(RECT *)0x0,1);
  iVar10 = local_4c;
  while ((iVar7 != 0 && ((*(uint *)(*(int *)(iVar7 + 8) + 8) & 0x40) != 0))) {
    local_50 = (HWND)param_1[4];
    local_58 = 0x2c;
    iVar10 = *(int *)(iVar7 + 8);
    local_48.x = *(LONG *)(iVar10 + 0xc);
    local_48.y = *(LONG *)(iVar10 + 0x10);
    local_40 = *(undefined4 *)(iVar10 + 0x14);
    local_3c = *(undefined4 *)(iVar10 + 0x18);
    local_4c = iVar7;
    MapWindowPoints((HWND)param_1[2],local_50,&local_48,2);
    SendMessageW((HWND)param_1[3],0x434,0,(LPARAM)&local_58);
    iVar7 = *(int *)(iVar7 + 4);
    iVar10 = local_4c;
  }
  if ((((*(undefined4 **)(*param_1 + 4) != (undefined4 *)0x0) &&
       (piVar5 = (int *)**(undefined4 **)(*param_1 + 4), piVar5 != (int *)0x0)) &&
      (piVar5 = (int *)*piVar5, piVar5 != (int *)0x0)) && (local_4c = *piVar5, local_4c != 0)) {
    local_50 = (HWND)param_1[4];
    local_58 = 0x2c;
    FUN_00023644(param_1,&local_48.x);
    MapWindowPoints((HWND)param_1[2],(HWND)param_1[4],&local_48,2);
    SendMessageW((HWND)param_1[3],0x434,0,(LPARAM)&local_58);
    iVar10 = local_4c;
  }
  local_4c = iVar10;
  InvalidateRect(param_2,(RECT *)0x0,1);
  return 1;
}



/* 0002457c FUN_0002457c */

/* Boundary evidence: original MIPS .pdata 0002457c..00024643. Semantic name remains unreviewed. */

undefined4 FUN_0002457c(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  HWND hWnd;
  tagRECT tStack_20;
  
  piVar1 = FUN_00023388(param_1,param_2,param_3);
  if ((piVar1 == (int *)0x0) || (param_4 == 0)) {
    uVar2 = 0;
  }
  else {
    FUN_0002fb1c(piVar1[2],param_4);
    if ((*(uint *)(piVar1[2] + 8) & 0x50) == 0) {
      InvalidateRect((HWND)param_1[2],(RECT *)(param_4 + 0xc),0);
      hWnd = (HWND)param_1[2];
    }
    else {
      CopyRect(&tStack_20,(RECT *)(param_4 + 0xc));
      MapWindowPoints((HWND)param_1[2],(HWND)param_1[4],(LPPOINT)&tStack_20,2);
      InvalidateRect((HWND)param_1[4],&tStack_20,0);
      hWnd = (HWND)param_1[4];
    }
    UpdateWindow(hWnd);
    uVar2 = 1;
  }
  return uVar2;
}



/* 00024644 FUN_00024644 */

/* Boundary evidence: original MIPS .pdata 00024644..000246e7. Semantic name remains unreviewed. */

int FUN_00024644(undefined4 *param_1,undefined4 param_2,LONG param_3,LONG param_4,
                undefined4 *param_5)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  POINT pt;
  
  iVar3 = *(int *)*param_1;
  iVar2 = 0;
  while( true ) {
    if (iVar3 == 0) {
      return -1;
    }
    pt.y = param_4;
    pt.x = param_3;
    BVar1 = PtInRect((RECT *)(*(int *)(iVar3 + 8) + 0xc),pt);
    if ((BVar1 != 0) && (param_5 != (undefined4 *)0x0)) break;
    iVar3 = *(int *)(iVar3 + 4);
    iVar2 = iVar2 + 1;
  }
  *param_5 = *(undefined4 *)(*(int *)(iVar3 + 8) + 8);
  return iVar2;
}



/* 000246e8 FUN_000246e8 */

/* Boundary evidence: original MIPS .pdata 000246e8..00024787. Semantic name remains unreviewed. */

void FUN_000246e8(undefined4 *param_1,HWND param_2,int param_3)

{
  BOOL BVar1;
  int iVar2;
  undefined4 auStack_38 [2];
  tagMSG tStack_30;
  
  BVar1 = PeekMessageW(&tStack_30,param_2,0x201,0x201,0);
  if (BVar1 != 0) {
    iVar2 = FUN_00024644(param_1,param_2,tStack_30.lParam & 0xffff,(uint)tStack_30.lParam >> 0x10,
                         auStack_38);
    if (iVar2 == param_3) {
      PeekMessageW(&tStack_30,param_2,0x201,0x201,1);
    }
  }
  return;
}



/* 00024788 FUN_00024788 */

int FUN_00024788(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)*param_1;
  for (iVar2 = iVar3; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    if ((*(uint *)(*(int *)(iVar2 + 8) + 8) & 0x40) != 0) goto LAB_000247ec;
  }
  piVar1 = (int *)((int *)*param_1)[1];
  if (((piVar1 == (int *)0x0) || (piVar1 = (int *)*piVar1, piVar1 == (int *)0x0)) ||
     (piVar1 = (int *)*piVar1, piVar1 == (int *)0x0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar1;
  }
LAB_000247ec:
  if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 4), iVar3 != 0)) {
    for (; iVar3 != iVar2; iVar3 = *(int *)(iVar3 + 4)) {
      if ((*(uint *)(*(int *)(iVar3 + 8) + 8) & 0x20) != 0) {
        return iVar3;
      }
    }
  }
  return 0;
}



/* 00024834 FUN_00024834 */

/* Boundary evidence: original MIPS .pdata 00024834..00024933. Semantic name remains unreviewed. */

undefined4 FUN_00024834(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  LSTATUS LVar1;
  HKEY local_228;
  DWORD local_224;
  DWORD aDStack_220 [2];
  wchar_t awStack_218 [259];
  undefined2 local_12;
  uint local_10;
  
  local_10 = DAT_00035518;
  local_224 = 0x104;
  StringCbPrintfW(awStack_218,0x208,L"%s\\%2.2X%2.2X",L"Software\\Microsoft\\Shell\\Keys",param_3,
                  param_2);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,awStack_218,0,0,&local_228);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_228,L"",(LPDWORD)0x0,aDStack_220,(LPBYTE)awStack_218,&local_224);
    RegCloseKey(local_228);
    if (LVar1 == 0) {
      local_12 = 0;
      FUN_0002c9e4(0,awStack_218,0);
      FUN_00033770(local_10);
      return 1;
    }
  }
  FUN_00033770(local_10);
  return 0;
}



/* 00024934 FUN_00024934 */

/* Boundary evidence: original MIPS .pdata 00024934..00024d17. Semantic name remains unreviewed. */

undefined4 FUN_00024934(undefined4 *param_1,HDC param_2,int param_3,UINT param_4,HGDIOBJ param_5)

{
  int iVar1;
  DWORD DVar2;
  HGDIOBJ h;
  HBRUSH ho;
  UINT edge;
  UINT grfFlags;
  int iVar3;
  int iVar4;
  size_t local_288 [2];
  tagRECT local_280;
  tagRECT local_270;
  HGDIOBJ local_260;
  tagRECT local_258;
  tagSIZE local_248;
  wchar_t awStack_240 [264];
  uint local_30;
  
  local_30 = DAT_00035518;
  iVar3 = 1;
  iVar4 = 1;
  iVar1 = GetSystemMetrics(0x2d);
  CopyRect(&local_258,(RECT *)(param_3 + 0xc));
  MapWindowPoints((HWND)param_1[2],(HWND)param_1[4],(LPPOINT)&local_258,2);
  local_260 = (HGDIOBJ)local_258.left;
  FUN_00023490(param_1,param_1[2],&local_270);
  MapWindowPoints((HWND)param_1[2],(HWND)param_1[4],(LPPOINT)&local_270,2);
  SelectObject(param_2,param_5);
  DVar2 = GetSysColor(0x40000014);
  SetTextColor(param_2,DVar2);
  DVar2 = GetSysColor(0x4000000f);
  SetBkColor(param_2,DVar2);
  PatBlt(param_2,local_270.left,local_270.top,local_270.right - local_270.left,
         local_270.bottom - local_270.top,0xf00021);
  if ((param_1[0xf] != 0) || (param_1[0x30] != 0)) {
    if (param_1[0x20] == 0) {
      grfFlags = 0x100f;
      edge = param_4;
    }
    else {
      grfFlags = 1;
      edge = 6;
    }
    DrawEdge(param_2,&local_270,edge,grfFlags);
  }
  InflateRect(&local_258,-iVar1,-iVar1);
  if (param_4 == 10) {
    iVar3 = 2;
    iVar4 = 3;
  }
  local_258.left = local_258.left + iVar3;
  local_258.top = local_258.top + iVar4 + -2;
  StringCchCopyW(awStack_240,0x107,(STRSAFE_LPCWSTR)(param_3 + 0x20));
  h = local_260;
  if ((HGDIOBJ)param_1[0xc] != (HGDIOBJ)0x0) {
    h = SelectObject(param_2,(HGDIOBJ)param_1[0xc]);
  }
  GetTextExtentExPointW(param_2,L"...",3,0,(LPINT)0x0,(LPINT)0x0,&local_248);
  iVar1 = FUN_0002cbe0(param_2,(STRSAFE_LPCWSTR)(param_3 + 0x20),&local_258.left,local_288,
                       local_248.cx);
  if (iVar1 == 0) {
    local_288[0] = wcslen(awStack_240);
  }
  else {
    StringCchCopyW(awStack_240 + local_288[0],0x107 - local_288[0],L"...");
    local_288[0] = local_288[0] + 3;
  }
  DVar2 = GetSysColor(0x40000012);
  SetTextColor(param_2,DVar2);
  SetBkMode(param_2,1);
  DrawTextW(param_2,awStack_240,local_288[0],&local_258,0x824);
  if (param_1[0xc] != 0) {
    SelectObject(param_2,h);
  }
  local_280.left = local_270.left;
  local_280.top = local_270.top;
  local_280.right = local_270.right;
  local_280.bottom = local_270.bottom;
  ho = CreateSolidBrush(0xc80000);
  iVar1 = local_280.bottom - local_280.top;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 3;
  }
  InflateRect(&local_280,0,-(iVar1 >> 2));
  if ((0 < (int)param_1[0x2f]) && (0 < (int)param_1[0x30])) {
    local_280.left = param_1[0x31] * 2 + local_280.left;
    local_280.right = local_280.left + 5;
    FUN_0002ce10(param_2,ho,3,&local_280.left);
  }
  if (((int)param_1[0x2f] < (int)(param_1[0x30] - param_1[0x2e])) &&
     ((int)param_1[0x2e] < (int)param_1[0x30])) {
    local_280.right = (int)local_260 - param_1[0x31];
    local_280.left = local_280.right + -5;
    FUN_0002ce10(param_2,ho,4,&local_280.left);
  }
  DeleteObject(ho);
  FUN_00033770(local_30);
  return 1;
}



/* 00024d44 FUN_00024d44 */

/* Boundary evidence: original MIPS .pdata 00024d44..00024e97. Semantic name remains unreviewed. */

void FUN_00024d44(HWND param_1,UINT param_2,WPARAM param_3,int param_4)

{
  HMONITOR pHVar1;
  int iVar2;
  WNDPROC lpPrevWndFunc;
  POINT pt;
  tagRECT local_58;
  undefined4 local_48;
  undefined1 auStack_44 [28];
  int local_28;
  
  if (param_2 == 3) {
    memset(&local_58.top,0,4);
    memset(auStack_44,0,0x24);
    local_48 = 0x28;
    pt.y = param_4 >> 0x10;
    pt.x = (int)(short)param_4;
    pHVar1 = MonitorFromPoint(pt,2);
    if ((pHVar1 != (HMONITOR)0x0) && (iVar2 = GetMonitorInfo(pHVar1,&local_48), iVar2 != 0)) {
      local_58.left = 0;
      memset(&local_58.top,0,0xc);
      GetWindowRect(param_1,&local_58);
      if (local_28 <= local_58.top + 5) {
        SetWindowPos(param_1,(HWND)0x0,(int)(short)param_4,
                     (local_28 - local_58.bottom) + local_58.top,0,0,0x205);
      }
    }
  }
  lpPrevWndFunc = (WNDPROC)GetWindowLongW(param_1,-0x15);
  CallWindowProcW(lpPrevWndFunc,param_1,param_2,param_3,param_4);
  return;
}



/* 00024e98 FUN_00024e98 */

/* Boundary evidence: original MIPS .pdata 00024e98..00024f33. Semantic name remains unreviewed. */

undefined4 FUN_00024e98(HWND param_1)

{
  HWND hWnd;
  DWORD DVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  hWnd = GetForegroundWindow();
  DVar1 = GetWindowThreadProcessId(param_1,(LPDWORD)0x0);
  DVar2 = GetWindowThreadProcessId(hWnd,(LPDWORD)0x0);
  if (DVar1 == DVar2) {
LAB_00024f10:
    uVar3 = 1;
  }
  else {
    for (; hWnd != (HWND)0x0; hWnd = GetParent(hWnd)) {
      if (hWnd == param_1) goto LAB_00024f10;
    }
  }
  return uVar3;
}



/* 00024f34 FUN_00024f34 */

/* Boundary evidence: original MIPS .pdata 00024f34..00024fab. Semantic name remains unreviewed. */

undefined4 FUN_00024f34(int param_1,int param_2,LPARAM param_3)

{
  WPARAM wParam;
  
  if (param_2 == 1) {
    wParam = 6;
  }
  else if (param_2 == 2) {
    wParam = 7;
  }
  else {
    if (param_2 != 4) {
      return 0;
    }
    wParam = 8;
  }
  SendMessageW(*(HWND *)(param_1 + 8),0x400,wParam,param_3);
  return 1;
}



/* 00024fac FUN_00024fac */

/* Boundary evidence: original MIPS .pdata 00024fac..0002500f. Semantic name remains unreviewed. */

undefined4 FUN_00024fac(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int **)(*param_1 + 4) == (int *)0x0) || (iVar2 = **(int **)(*param_1 + 4), iVar2 == 0)) {
    uVar1 = 0;
  }
  else {
    if (param_2 == 0) {
      param_2 = param_1[0x25];
    }
    *(int *)(*(int *)(iVar2 + 8) + 4) = param_2;
    FUN_0002457c(param_1,param_1[2],-4,*(int *)(iVar2 + 8));
    uVar1 = 1;
  }
  return uVar1;
}



/* 00025010 FUN_00025010 */

/* Boundary evidence: original MIPS .pdata 00025010..00025083. Semantic name remains unreviewed. */

undefined4 FUN_00025010(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_3 & 0xffff;
  if ((uVar3 < 0xa300) || (0xa3c8 < uVar3)) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_0002c6a8(uVar3 - 0xa300);
    if (iVar1 == 0) {
      iVar1 = param_1[0x23];
    }
    else {
      iVar1 = param_1[0x25];
    }
    uVar2 = FUN_00024fac(param_1,iVar1);
  }
  return uVar2;
}



/* 00025084 FUN_00025084 */

/* Boundary evidence: original MIPS .pdata 00025084..0002514b. Semantic name remains unreviewed. */

undefined4 FUN_00025084(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)*param_1;
  for (iVar4 = iVar3; iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
    if ((*(uint *)(*(int *)(iVar4 + 8) + 8) & 0x40) != 0) goto LAB_000250f4;
  }
  piVar1 = (int *)((int *)*param_1)[1];
  if (((piVar1 == (int *)0x0) || (piVar1 = (int *)*piVar1, piVar1 == (int *)0x0)) ||
     (piVar1 = (int *)*piVar1, piVar1 == (int *)0x0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = *piVar1;
  }
LAB_000250f4:
  if (param_2 == 0) {
    iVar2 = 0;
    if (iVar3 != 0) {
      iVar2 = *(int *)(iVar3 + 4);
    }
  }
  else {
    iVar3 = FUN_00021918(param_1,*(int *)(param_2 + 0x1c));
    if (iVar3 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar3 + 4);
  }
  if ((iVar2 != iVar4) && (iVar2 != 0)) {
    return *(undefined4 *)(iVar2 + 8);
  }
  return 0;
}



/* 0002514c FUN_0002514c */

/* Boundary evidence: original MIPS .pdata 0002514c..00025213. Semantic name remains unreviewed. */

undefined4 FUN_0002514c(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)*param_1;
  for (puVar2 = puVar3; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[1]) {
    if ((*(uint *)(puVar2[2] + 8) & 0x40) != 0) goto LAB_000251bc;
  }
  puVar2 = (undefined4 *)((undefined4 *)*param_1)[1];
  if (((puVar2 == (undefined4 *)0x0) ||
      (puVar2 = (undefined4 *)*puVar2, puVar2 == (undefined4 *)0x0)) ||
     (puVar2 = (undefined4 *)*puVar2, puVar2 == (undefined4 *)0x0)) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)*puVar2;
  }
LAB_000251bc:
  if (param_2 == 0) {
    puVar1 = (undefined4 *)0x0;
    if (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar2;
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_00021918(param_1,*(int *)(param_2 + 0x1c));
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    puVar1 = (undefined4 *)*puVar1;
  }
  if ((puVar1 != puVar3) && (puVar1 != (undefined4 *)0x0)) {
    return puVar1[2];
  }
  return 0;
}



/* 00025214 FUN_00025214 */

/* Boundary evidence: original MIPS .pdata 00025214..00025273. Semantic name remains unreviewed. */

undefined4 FUN_00025214(int param_1)

{
  HWND pHVar1;
  HWND pHVar2;
  
  if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 0x4c) == 0)) {
    pHVar2 = *(HWND *)(param_1 + 8);
    pHVar1 = GetForegroundWindow();
    if (pHVar1 != pHVar2) {
      FUN_00022568(param_1,pHVar2);
    }
  }
  return 1;
}



/* 00025274 FUN_00025274 */

/* Boundary evidence: original MIPS .pdata 00025274..000252fb. Semantic name remains unreviewed. */

undefined4 FUN_00025274(int param_1)

{
  BOOL BVar1;
  POINT local_20;
  tagRECT tStack_18;
  
  KillTimer(*(HWND *)(param_1 + 8),5);
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  if ((((*(int *)(param_1 + 0x4c) != 0) && (BVar1 = GetCursorPos(&local_20), BVar1 != 0)) &&
      (BVar1 = GetWindowRect(*(HWND *)(param_1 + 8),&tStack_18), BVar1 != 0)) &&
     (BVar1 = PtInRect(&tStack_18,local_20), BVar1 != 0)) {
    FUN_0002249c(param_1);
  }
  return 1;
}



/* 000252fc FUN_000252fc */

/* Boundary evidence: original MIPS .pdata 000252fc..00025393. Semantic name remains unreviewed. */

undefined4 FUN_000252fc(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  FUN_000237c4(param_1);
  piVar1 = FUN_00023388(param_1,param_1[2],-1);
  if ((piVar1 != (int *)0x0) && (iVar2 = piVar1[2], iVar2 != 0)) {
    FUN_000235a4((int)param_1);
    FUN_00023644(param_1,(int *)(iVar2 + 0xc));
    FUN_0002457c(param_1,param_1[2],-1,iVar2);
    FUN_0002400c(param_1,(HWND)param_1[2]);
    UpdateWindow((HWND)param_1[4]);
  }
  return 1;
}



/* 00025394 FUN_00025394 */

/* Boundary evidence: original MIPS .pdata 00025394..0002546b. Semantic name remains unreviewed. */

undefined4 FUN_00025394(int *param_1)

{
  int *piVar1;
  int X;
  int iVar2;
  
  FUN_000237c4(param_1);
  piVar1 = FUN_00023388(param_1,param_1[2],-1);
  if ((piVar1 != (int *)0x0) && (iVar2 = piVar1[2], iVar2 != 0)) {
    FUN_000235a4((int)param_1);
    FUN_00023644(param_1,(int *)(iVar2 + 0xc));
    X = *(int *)(iVar2 + 0xc);
    SetWindowPos((HWND)param_1[4],(HWND)0x0,X,*(int *)(iVar2 + 0x10),*(int *)(iVar2 + 0x14) - X,
                 *(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x10),0x214);
    FUN_0002457c(param_1,param_1[2],-1,iVar2);
    FUN_0002400c(param_1,(HWND)param_1[2]);
    UpdateWindow((HWND)param_1[4]);
  }
  return 1;
}



/* 0002546c FUN_0002546c */

/* Boundary evidence: original MIPS .pdata 0002546c..0002562b. Semantic name remains unreviewed. */

void FUN_0002546c(undefined4 *param_1)

{
  HIMAGELIST p_Var1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined1 auStack_2c8 [692];
  uint local_14;
  
  local_14 = DAT_00035518;
  KillTimer((HWND)param_1[2],0x2a);
  KillTimer((HWND)param_1[2],6);
  KillTimer((HWND)param_1[2],5);
  puVar2 = (undefined4 *)param_1[9];
  if (puVar2 != (undefined4 *)0x0) {
    FUN_0002d284(puVar2);
    operator_delete(puVar2);
    param_1[9] = 0;
  }
  if ((HWND)param_1[5] != (HWND)0x0) {
    DestroyWindow((HWND)param_1[5]);
    param_1[5] = 0;
  }
  if (*(HWND *)(DAT_00035570 + 4) != (HWND)0x0) {
    DestroyWindow(*(HWND *)(DAT_00035570 + 4));
  }
  pvVar3 = (void *)*param_1;
  if (pvVar3 != (void *)0x0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)pvVar3 + 0xc));
    operator_delete(pvVar3);
    *param_1 = 0;
  }
  pvVar3 = (void *)param_1[1];
  if (pvVar3 != (void *)0x0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)pvVar3 + 0xc));
    operator_delete(pvVar3);
    param_1[1] = 0;
  }
  if ((HGDIOBJ)param_1[0xc] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0xc]);
    param_1[0xc] = 0;
  }
  if ((HICON)param_1[0xb] != (HICON)0x0) {
    DestroyIcon((HICON)param_1[0xb]);
    param_1[0xb] = 0;
  }
  if (DAT_00035600 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00035600);
    DAT_00035600 = (HGDIOBJ)0x0;
  }
  puVar2 = (undefined4 *)param_1[10];
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(puVar2,1);
    param_1[10] = 0;
  }
  p_Var1 = (HIMAGELIST)SHGetFileInfo(&DAT_00011b38,0,auStack_2c8,0x2b4,0x4000);
  ImageList_Destroy(p_Var1);
  p_Var1 = (HIMAGELIST)SHGetFileInfo(&DAT_00011b38,0,auStack_2c8,0x2b4,0x4001);
  ImageList_Destroy(p_Var1);
  FUN_00033770(local_14);
  return;
}



/* 0002562c FUN_0002562c */

/* Boundary evidence: original MIPS .pdata 0002562c..00025953. Semantic name remains unreviewed. */

undefined4 FUN_0002562c(int *param_1,HWND param_2)

{
  bool bVar1;
  HWND hWnd;
  int iVar2;
  int *piVar3;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  RECT *lprc2;
  RECT local_88;
  _SYSTEMTIME _Stack_78;
  _MEMORYSTATUS local_68;
  _SYSTEM_INFO _Stack_48;
  
  bVar1 = false;
  if (DAT_00035608 == 0) {
    GetSystemInfo(&_Stack_48);
    DAT_00035608 = _Stack_48.dwPageSize * 0x28;
    if (DAT_00035608 < 0x20000) {
      DAT_00035608 = 0x20000;
    }
  }
  local_68.dwLength = 0x20;
  GlobalMemoryStatus(&local_68);
  if (local_68.dwAvailPhys < DAT_00035608) {
    if (DAT_00035604 == 0) {
      DAT_00035604 = 1;
    }
    hWnd = GetWindow(param_2,1);
    do {
      iVar2 = FUN_00021918(param_1,(int)hWnd);
      if ((iVar2 != 0) && (*(char *)(*(int *)(iVar2 + 8) + 0x228) == '\0')) {
        bVar1 = true;
      }
      hWnd = GetWindow(hWnd,3);
    } while ((hWnd != (HWND)0x0) && (!bVar1));
    if (bVar1) {
      *(undefined1 *)(*(int *)(iVar2 + 8) + 0x228) = 1;
      PostMessageW(*(HWND *)(*(int *)(iVar2 + 8) + 0x1c),0x3ff,0,0);
    }
  }
  else if (DAT_00035604 != 0) {
    iVar6 = *(int *)*param_1;
    DAT_00035604 = 0;
    for (iVar2 = iVar6; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      if ((*(uint *)(*(int *)(iVar2 + 8) + 8) & 0x40) != 0) goto LAB_000257dc;
    }
    piVar3 = (int *)((int *)*param_1)[1];
    if (((piVar3 == (int *)0x0) || (piVar3 = (int *)*piVar3, piVar3 == (int *)0x0)) ||
       (piVar3 = (int *)*piVar3, piVar3 == (int *)0x0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *piVar3;
    }
LAB_000257dc:
    iVar5 = 0;
    if (iVar6 != 0) {
      iVar5 = *(int *)(iVar6 + 4);
    }
    for (; iVar5 != iVar2; iVar5 = *(int *)(iVar5 + 4)) {
      *(undefined1 *)(*(int *)(iVar5 + 8) + 0x228) = 0;
    }
  }
  if ((param_1[0xf] != 0) &&
     (((GetLocalTime(&_Stack_78), _Stack_78.wHour != DAT_00035530 ||
       (_Stack_78.wMinute != DAT_0003552c)) || (param_1[0xe] != 0)))) {
    DAT_00035530 = _Stack_78.wHour;
    DAT_0003552c = _Stack_78.wMinute;
    piVar3 = FUN_00023388(param_1,param_2,-1);
    iVar2 = 0;
    if (piVar3 != (int *)0x0) {
      iVar2 = piVar3[2];
    }
    GetTimeFormatW(0x400,2,&_Stack_78,(LPCWSTR)0x0,(LPWSTR)(iVar2 + 0x20),0x104);
    if (param_1[0xe] != 0) {
      FUN_000235a4((int)param_1);
    }
    lprc2 = (RECT *)(iVar2 + 0xc);
    local_88.left = lprc2->left;
    local_88.top = *(LONG *)(iVar2 + 0x10);
    local_88.right = *(LONG *)(iVar2 + 0x14);
    local_88.bottom = *(LONG *)(iVar2 + 0x18);
    FUN_00023644(param_1,(int *)lprc2);
    FUN_0002457c(param_1,param_2,-1,iVar2);
    if ((param_1[0xe] != 0) || (BVar4 = EqualRect(&local_88,lprc2), BVar4 == 0)) {
      FUN_0002400c(param_1,param_2);
      UpdateWindow((HWND)param_1[4]);
    }
    param_1[0xe] = 0;
  }
  return 0;
}



/* 00025954 FUN_00025954 */

/* Boundary evidence: original MIPS .pdata 00025954..00025bb3. Semantic name remains unreviewed. */

int FUN_00025954(int *param_1,HWND param_2)

{
  BOOL BVar1;
  uint uVar2;
  int *hMem;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int *local_3c;
  undefined4 local_24;
  
  BVar1 = IsWindow(param_2);
  if ((((BVar1 != 0) && (uVar2 = GetWindowLongW(param_2,-0x14), (uVar2 & 0x80) == 0)) &&
      (param_2 != (HWND)param_1[2])) &&
     (((param_2 != (HWND)param_1[3] && (param_2 != (HWND)param_1[4])) &&
      (hMem = LocalAlloc(0x40,0xc), hMem != (int *)0x0)))) {
    puVar3 = operator_new(0x22c);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = FUN_00030588(puVar3,param_2);
    }
    if (puVar3 != (undefined4 *)0x0) {
      hMem[2] = (int)puVar3;
      if ((puVar3[1] == 0) || (puVar3[1] == -0x7fffbffb)) {
        puVar3[1] = param_1[0xb];
      }
      SetRect((LPRECT)(hMem[2] + 0xc),0,0,0,0);
      if ((param_1[0x26] == 0) || (param_1[0x2d] < param_1[0x2c])) {
        piVar4 = (int *)*param_1;
        for (iVar6 = *piVar4; iVar6 != 0; iVar6 = *(int *)(iVar6 + 4)) {
          if ((*(uint *)(*(int *)(iVar6 + 8) + 8) & 0x40) != 0) goto LAB_00025ae0;
        }
        if ((((undefined4 *)piVar4[1] == (undefined4 *)0x0) ||
            (puVar3 = *(undefined4 **)piVar4[1], puVar3 == (undefined4 *)0x0)) ||
           (piVar5 = (int *)*puVar3, piVar5 == (int *)0x0)) {
          iVar6 = 0;
        }
        else {
          iVar6 = *piVar5;
        }
LAB_00025ae0:
        iVar6 = FUN_00021514(piVar4,iVar6);
      }
      else {
        iVar6 = param_1[0x2b];
      }
      piVar4 = FUN_00021690((int *)*param_1,hMem,iVar6);
      if (piVar4 != (int *)0x0) {
        memset(&local_44,0,0x28);
        local_44 = 0x10;
        local_40 = param_1[2];
        local_48 = 0x2c;
        local_24 = 0xffffffff;
        local_3c = hMem;
        SendMessageW((HWND)param_1[3],0x432,0,(LPARAM)&local_48);
        param_1[0x2d] = param_1[0x2d] + 1;
        FUN_0002400c(param_1,(HWND)param_1[2]);
        return iVar6;
      }
      puVar3 = (undefined4 *)hMem[2];
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(puVar3,1);
      }
    }
    LocalFree(hMem);
  }
  return -1;
}



/* 00025bb4 FUN_00025bb4 */

/* Boundary evidence: original MIPS .pdata 00025bb4..00025d63. Semantic name remains unreviewed. */

undefined4 FUN_00025bb4(int *param_1,HWND param_2,int param_3,int param_4)

{
  int iVar1;
  int *hMem;
  HICON hIcon;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_48;
  undefined1 auStack_44 [4];
  int local_40;
  int *local_3c;
  
  if ((param_3 < 1) ||
     (iVar3 = *(int *)*param_1, iVar1 = FUN_00021594((int *)*param_1,param_3), iVar1 == iVar3)) {
    uVar4 = 0;
  }
  else {
    hMem = FUN_0002161c((int *)*param_1,param_3);
    if ((*(uint *)(hMem[2] + 8) & 0x40) == 0) {
      if (0 < *(int *)(hMem[2] + 0x1c)) {
        param_1[0x2d] = param_1[0x2d] + -1;
      }
    }
    else {
      iVar1 = param_1[0x30] + -1;
      param_1[0x30] = iVar1;
      if ((iVar1 <= param_1[0x2f]) &&
         (param_1[0x2f] = iVar1 - param_1[0x2e], iVar1 - param_1[0x2e] < 0)) {
        param_1[0x2f] = 0;
      }
    }
    if ((((*(uint *)(hMem[2] + 8) & 0x10000000) != 0) &&
        (hIcon = *(HICON *)(hMem[2] + 4), hIcon != (HICON)0x0)) && (param_4 != 0)) {
      DestroyIcon(hIcon);
    }
    memset(auStack_44,0,0x28);
    local_48 = 0x2c;
    if ((*(uint *)(hMem[2] + 8) & 0x40) == 0) {
      local_40 = param_1[2];
    }
    else {
      local_40 = param_1[4];
    }
    local_3c = hMem;
    SendMessageW((HWND)param_1[3],0x433,0,(LPARAM)&local_48);
    FUN_0002400c(param_1,param_2);
    uVar4 = 1;
    if (param_4 != 0) {
      puVar2 = (undefined4 *)hMem[2];
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(puVar2,1);
      }
      LocalFree(hMem);
    }
  }
  return uVar4;
}



/* 00025d64 FUN_00025d64 */

/* Boundary evidence: original MIPS .pdata 00025d64..00025faf. Semantic name remains unreviewed. */

undefined4 FUN_00025d64(int *param_1,HWND param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int *local_3c;
  undefined4 local_24;
  
  puVar1 = operator_new(0x230);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_00030200(puVar1,param_3);
  }
  if (puVar1 != (undefined4 *)0x0) {
    for (iVar7 = *(int *)*param_1; iVar7 != 0; iVar7 = *(int *)(iVar7 + 4)) {
      if ((*(uint *)(*(int *)(iVar7 + 8) + 8) & 0x40) != 0) goto LAB_00025e1c;
    }
    piVar3 = (int *)((int *)*param_1)[1];
    if (((piVar3 == (int *)0x0) || (piVar3 = (int *)*piVar3, piVar3 == (int *)0x0)) ||
       (piVar3 = (int *)*piVar3, piVar3 == (int *)0x0)) {
      iVar7 = 0;
    }
    else {
      iVar7 = *piVar3;
    }
LAB_00025e1c:
    iVar5 = *(int *)(*(int *)(iVar7 + 8) + 0xc);
    iVar7 = param_1[0x31];
    puVar1[4] = 7;
    iVar5 = iVar5 - iVar7;
    puVar1[3] = iVar5 + -0x10;
    puVar1[5] = iVar5;
    puVar1[6] = 0x17;
    piVar3 = LocalAlloc(0,0xc);
    if (piVar3 == (int *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
    else {
      piVar3[2] = (int)puVar1;
      piVar2 = (int *)*param_1;
      for (iVar7 = *piVar2; iVar7 != 0; iVar7 = *(int *)(iVar7 + 4)) {
        if ((*(uint *)(*(int *)(iVar7 + 8) + 8) & 0x40) != 0) goto LAB_00025ebc;
      }
      if ((((undefined4 *)piVar2[1] == (undefined4 *)0x0) ||
          (puVar4 = *(undefined4 **)piVar2[1], puVar4 == (undefined4 *)0x0)) ||
         (piVar6 = (int *)*puVar4, piVar6 == (int *)0x0)) {
        iVar7 = 0;
      }
      else {
        iVar7 = *piVar6;
      }
LAB_00025ebc:
      iVar7 = FUN_00021514(piVar2,iVar7);
      piVar2 = FUN_00021690((int *)*param_1,piVar3,iVar7);
      if (piVar2 != (int *)0x0) {
        param_1[0x30] = param_1[0x30] + 1;
        if (0 < param_1[0x2f]) {
          param_1[0x2f] = 0;
        }
        memset(&local_44,0,0x28);
        local_44 = 0x10;
        local_40 = param_1[4];
        local_48 = 0x2c;
        local_24 = 0xffffffff;
        local_3c = piVar3;
        SendMessageW((HWND)param_1[3],0x432,0,(LPARAM)&local_48);
        FUN_0002400c(param_1,param_2);
        UpdateWindow((HWND)param_1[4]);
        return 1;
      }
      (**(code **)*puVar1)(puVar1,1);
      LocalFree(piVar3);
    }
  }
  return 0;
}



/* 00025fb0 FUN_00025fb0 */

/* Boundary evidence: original MIPS .pdata 00025fb0..00026367. Semantic name remains unreviewed. */

undefined4 FUN_00025fb0(int *param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int *piVar3;
  STRSAFE_LPCWSTR pszSrc;
  HRESULT HVar4;
  wchar_t *pwVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  RECT local_58;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int *local_3c;
  undefined4 local_24;
  
  uVar10 = 0;
  if (*param_1 == 0) {
    return 0;
  }
  iVar2 = FUN_0002b6d8(param_2);
  if (iVar2 == 0) {
    return 0;
  }
  bVar1 = FUN_0002b3cc();
  piVar9 = *(int **)*param_1;
  if (piVar9 == (int *)0x0) {
LAB_000260d4:
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0;
    }
    piVar3 = LocalAlloc(0,0xc);
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    local_58.top = 6;
    local_58.bottom = 0x1d;
    for (iVar2 = *(int *)*param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      if ((*(uint *)(*(int *)(iVar2 + 8) + 8) & 0x40) != 0) goto LAB_00026164;
    }
    piVar9 = (int *)((int *)*param_1)[1];
    if (((piVar9 == (int *)0x0) || (piVar9 = (int *)*piVar9, piVar9 == (int *)0x0)) ||
       (piVar9 = (int *)*piVar9, piVar9 == (int *)0x0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *piVar9;
    }
LAB_00026164:
    local_58.left = *(int *)(*(int *)(iVar2 + 8) + 0xc) - param_1[0x31];
    local_58.right = local_58.left;
    puVar6 = operator_new(0x234);
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6 = FUN_0002b978(puVar6,local_58.left,local_58.top,local_58.right,local_58.bottom,
                            param_1[4]);
    }
    if (puVar6 != (undefined4 *)0x0) {
      piVar9 = piVar3 + 2;
      *piVar9 = (int)puVar6;
      piVar7 = (int *)*param_1;
      for (iVar2 = *piVar7; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
        if ((*(uint *)(*(int *)(iVar2 + 8) + 8) & 0x40) != 0) goto LAB_0002622c;
      }
      if ((((undefined4 *)piVar7[1] == (undefined4 *)0x0) ||
          (puVar6 = *(undefined4 **)piVar7[1], puVar6 == (undefined4 *)0x0)) ||
         (piVar8 = (int *)*puVar6, piVar8 == (int *)0x0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *piVar8;
      }
LAB_0002622c:
      iVar2 = FUN_00021514(piVar7,iVar2);
      piVar7 = FUN_00021690((int *)*param_1,piVar3,iVar2);
      if (piVar7 != (int *)0x0) {
        param_1[0x30] = param_1[0x30] + 1;
        if (0 < param_1[0x2f]) {
          param_1[0x2f] = 0;
        }
        memset(&local_44,0,0x28);
        local_44 = 0x10;
        local_40 = param_1[4];
        local_48 = 0x2c;
        local_24 = 0xffffffff;
        local_3c = piVar3;
        SendMessageW((HWND)param_1[3],0x432,0,(LPARAM)&local_48);
        goto LAB_000262d8;
      }
      puVar6 = (undefined4 *)*piVar9;
      if (puVar6 != (undefined4 *)0x0) {
        (**(code **)*puVar6)(puVar6,1);
      }
    }
    LocalFree(piVar3);
  }
  else {
    do {
      if ((*(uint *)(piVar9[2] + 8) & 0x100) != 0) break;
      piVar9 = (int *)piVar9[1];
    } while (piVar9 != (int *)0x0);
    if (piVar9 == (int *)0x0) goto LAB_000260d4;
    if ((CONCAT31(extraout_var,bVar1) == 0) &&
       (piVar3 = FUN_00015a70((int *)*param_1,piVar9), piVar3 != (int *)0x0)) {
      puVar6 = (undefined4 *)piVar9[2];
      if (puVar6 != (undefined4 *)0x0) {
        (**(code **)*puVar6)(puVar6,1);
      }
      LocalFree(piVar9);
      FUN_0002400c(param_1,(HWND)param_1[2]);
      UpdateWindow((HWND)param_1[4]);
      return 0;
    }
    piVar9 = piVar9 + 2;
    iVar2 = *piVar9;
    local_58.left = *(int *)(iVar2 + 0xc);
    local_58.top = *(LONG *)(iVar2 + 0x10);
    local_58.right = *(int *)(iVar2 + 0x14);
    local_58.bottom = *(LONG *)(iVar2 + 0x18);
    MapWindowPoints((HWND)param_1[2],(HWND)param_1[4],(LPPOINT)&local_58,2);
    InvalidateRect((HWND)param_1[4],&local_58,0);
LAB_000262d8:
    pszSrc = (STRSAFE_LPCWSTR)FUN_0002b318();
    HVar4 = StringCbCopyW((STRSAFE_LPWSTR)(*piVar9 + 0x20),0x208,pszSrc);
    if (HVar4 < 0) {
      *(undefined2 *)(*piVar9 + 0x20) = 0;
    }
    else {
      pwVar5 = wcschr((wchar_t *)(*piVar9 + 0x20),L'$');
      if (pwVar5 != (wchar_t *)0x0) {
        *pwVar5 = L'\0';
      }
    }
    FUN_0002ba40(*piVar9,(HWND)param_1[2]);
    FUN_0002400c(param_1,(HWND)param_1[2]);
    UpdateWindow((HWND)param_1[4]);
    uVar10 = 1;
  }
  return uVar10;
}



/* 00026368 FUN_00026368 */

/* Boundary evidence: original MIPS .pdata 00026368..00026483. Semantic name remains unreviewed. */

undefined4 FUN_00026368(int *param_1,int param_2,HDC param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  HBRUSH pHVar2;
  undefined4 uVar3;
  
  if (param_1[0x13] == 0) {
    piVar1 = FUN_00023388(param_1,param_2,param_4);
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if (param_2 == param_1[4]) {
      if ((*(uint *)(piVar1[2] + 8) & 0x10) == 0) {
        if ((*(uint *)(piVar1[2] + 8) & 0x40) != 0) {
          uVar3 = (**(code **)(*(int *)piVar1[2] + 0xc))
                            ((int *)piVar1[2],param_1[2],param_1[4],param_3);
          return uVar3;
        }
      }
      else {
        pHVar2 = GetSysColorBrush(0x40000004);
        FUN_00024934(param_1,param_3,piVar1[2],2,pHVar2);
      }
    }
    else if (param_2 == param_1[2]) {
      (**(code **)(*(int *)piVar1[2] + 4))
                ((int *)piVar1[2],param_1[2],param_3,param_1[0xc],param_1[0x20],param_5);
    }
  }
  return 1;
}



/* 00026484 FUN_00026484 */

/* Boundary evidence: original MIPS .pdata 00026484..00026617. Semantic name remains unreviewed. */

undefined4 FUN_00026484(int *param_1,HWND param_2,int param_3,LPARAM param_4)

{
  int *piVar1;
  undefined4 uVar2;
  BOOL BVar3;
  int iVar4;
  
  piVar1 = FUN_00023388(param_1,param_2,param_3);
  if (piVar1 == (int *)0x0) {
    if (param_3 == -6) {
      if (param_1[0x2f] + -1 < 0) {
        return 0;
      }
      param_1[0x2f] = param_1[0x2f] + -1;
    }
    else {
      if (param_3 != -7) {
        return 0;
      }
      if (param_1[0x30] - param_1[0x2e] < param_1[0x2f] + 1) {
        return 0;
      }
      param_1[0x2f] = param_1[0x2f] + 1;
    }
  }
  else {
    iVar4 = piVar1[2];
    if ((*(uint *)(iVar4 + 8) & 0x80) != 0) {
      uVar2 = FUN_0002f024();
      return uVar2;
    }
    if (*(int *)(iVar4 + 0x22c) == 0) {
      return 0;
    }
    BVar3 = IsWindow(*(HWND *)(iVar4 + 0x1c));
    if (BVar3 != 0) {
      iVar4 = piVar1[2];
      PostMessageW(*(HWND *)(iVar4 + 0x1c),*(UINT *)(iVar4 + 0x22c),*(WPARAM *)(iVar4 + 0x228),
                   param_4);
      return 1;
    }
    if (param_3 == -1) {
      return 1;
    }
    FUN_00025bb4(param_1,param_2,param_3,1);
  }
  FUN_0002400c(param_1,param_2);
  return 1;
}



/* 00026618 FUN_00026618 */

/* Boundary evidence: original MIPS .pdata 00026618..0002678f. Semantic name remains unreviewed. */

void FUN_00026618(int *param_1,HWND param_2)

{
  HDC hDC;
  int *piVar1;
  int iVar2;
  tagPOINT local_28;
  tagPOINT local_20;
  
  if ((param_1[0xd] == 0) && ((param_1[10] == 0 || (*(int *)(param_1[10] + 0x228) == 0)))) {
    iVar2 = param_1[0x13];
    FUN_0002249c((int)param_1);
    param_1[0xd] = 1;
    SetForegroundWindow(param_2);
    if (((param_1[0x14] == 0) || (iVar2 == 0)) || (param_1[0x1d] == 0)) {
      hDC = GetDC(param_2);
      FUN_00026368(param_1,(int)param_2,hDC,0,1);
      piVar1 = FUN_00023388(param_1,param_2,0);
      iVar2 = 0;
      if (piVar1 != (int *)0x0) {
        iVar2 = piVar1[2];
      }
      local_28.x = *(int *)(iVar2 + 0xc);
      local_28.y = *(int *)(iVar2 + 0x10);
      local_20.x = *(LONG *)(iVar2 + 0x14);
      local_20.y = *(LONG *)(iVar2 + 0x18);
      ClientToScreen(param_2,&local_28);
      ClientToScreen(param_2,&local_20);
      FUN_0003199c(0x20,local_28.x,local_28.y + -1,param_2);
      FUN_00026368(param_1,(int)param_2,hDC,0,0);
      ReleaseDC(param_2,hDC);
      FUN_000246e8(param_1,param_2,0);
    }
    param_1[0xd] = 0;
  }
  else {
    SetCapture(param_2);
    ReleaseCapture();
  }
  return;
}



/* 00026790 FUN_00026790 */

/* Boundary evidence: original MIPS .pdata 00026790..00026903. Semantic name remains unreviewed. */

void FUN_00026790(int *param_1,int param_2,int param_3,int param_4)

{
  HMENU pHVar1;
  HDC hDC;
  BOOL BVar2;
  tagPOINT local_res4;
  tagMENUITEMINFOW local_48;
  
  local_res4.x = param_2;
  local_res4.y = param_3;
  if (param_1[0x1f] == 0) {
    ClientToScreen((HWND)param_1[2],&local_res4);
    pHVar1 = LoadMenuW(DAT_00035560,(LPCWSTR)0x70);
    if ((pHVar1 != (HMENU)0x0) && (pHVar1 = GetSubMenu(pHVar1,0), pHVar1 != (HMENU)0x0)) {
      param_1[0x1f] = 1;
      hDC = GetDC((HWND)param_1[2]);
      FUN_00026368(param_1,param_1[2],hDC,param_4,1);
      TrackPopupMenuEx(pHVar1,0x28,local_res4.x + 0xc,local_res4.y,(HWND)param_1[2],(LPTPMPARAMS)0x0
                      );
      FUN_00026368(param_1,param_1[2],hDC,param_4,0);
      ReleaseDC((HWND)param_1[2],hDC);
      FUN_000246e8(param_1,(HWND)param_1[2],param_4);
      param_1[0x1f] = 0;
      local_48.cbSize = 0x2c;
      local_48.fMask = 0x22;
      while (BVar2 = GetMenuItemInfoW(pHVar1,0,0x400,&local_48), BVar2 != 0) {
        DeleteMenu(pHVar1,0,0x400);
      }
      DestroyMenu(pHVar1);
    }
  }
  else {
    SetCapture((HWND)param_1[2]);
    ReleaseCapture();
  }
  return;
}



/* 00026904 FUN_00026904 */

/* Boundary evidence: original MIPS .pdata 00026904..00026ef7. Semantic name remains unreviewed. */

undefined4 FUN_00026904(int *param_1,HWND param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  BOOL BVar3;
  int *piVar4;
  uint uVar5;
  HWND pHVar6;
  undefined4 *puVar7;
  HWND hWnd;
  HWND hWnd_00;
  HWND local_60;
  tagRECT tStack_58;
  tagRECT tStack_48;
  tagRECT tStack_38;
  
  local_60 = (HWND)0x0;
  hWnd_00 = (HWND)0x0;
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 1;
  }
  SetRect(&tStack_58,0,0,0,0);
  SetRect(&tStack_48,0,0,0,0);
  if (param_3 == -1) {
    if (param_4 != 0) {
      param_4 = 0;
      goto LAB_000269a4;
    }
LAB_00026a28:
    pHVar6 = GetForegroundWindow();
    do {
      hWnd = pHVar6;
      pHVar6 = GetParent(hWnd);
    } while (pHVar6 != (HWND)0x0);
    piVar2 = (int *)FUN_00021918(param_1,(int)hWnd);
    iVar1 = FUN_00024788(param_1);
    if (iVar1 != 0) {
      *(uint *)(*(int *)(iVar1 + 8) + 8) = *(uint *)(*(int *)(iVar1 + 8) + 8) & 0xffffffdf;
      *(uint *)(*(int *)(iVar1 + 8) + 8) = *(uint *)(*(int *)(iVar1 + 8) + 8) | 4;
      hWnd_00 = *(HWND *)(*(int *)(iVar1 + 8) + 0x1c);
      CopyRect(&tStack_58,(RECT *)(*(int *)(iVar1 + 8) + 0xc));
    }
LAB_00026ab8:
    if (piVar2 == (int *)0x0) {
LAB_00026ac0:
      if (param_4 == 0) goto LAB_00026e7c;
      goto LAB_00026ac8;
    }
    *(uint *)(piVar2[2] + 8) = *(uint *)(piVar2[2] + 8) & 0xfffffffb;
    *(uint *)(piVar2[2] + 8) = *(uint *)(piVar2[2] + 8) | 0x28;
    local_60 = *(HWND *)(piVar2[2] + 0x1c);
    CopyRect(&tStack_48,(RECT *)(piVar2[2] + 0xc));
    if (param_4 == 0) goto LAB_00026e7c;
    *(uint *)(piVar2[2] + 8) = *(uint *)(piVar2[2] + 8) | 0x20000000;
    uVar5 = GetWindowLongW(*(HWND *)(piVar2[2] + 0x1c),-0x10);
    if ((uVar5 & 0x80000000) == 0) {
      sndPlaySoundW(L"Maximize",0x10003);
      FUN_000300f0(piVar2[2],param_2,1);
    }
    SetForegroundWindow((HWND)(*(uint *)(piVar2[2] + 0x1c) | 1));
    pHVar6 = *(HWND *)(piVar2[2] + 0x1c);
  }
  else {
LAB_000269a4:
    if (param_3 != 0) {
      if (param_3 == -1) goto LAB_00026a28;
      piVar2 = FUN_00023388(param_1,param_2,param_3);
      if (((piVar2 == (int *)0x0) ||
          (pHVar6 = *(HWND *)(piVar2[2] + 0x1c), pHVar6 == (HWND)0xfffffffb)) ||
         (pHVar6 == (HWND)0xfffffffc)) {
        return 0;
      }
      BVar3 = IsWindow(pHVar6);
      if ((BVar3 == 0) && (*(int *)(piVar2[2] + 0x1c) != -3)) {
        FUN_00025bb4(param_1,param_2,param_3,1);
        UpdateWindow(param_2);
        if (param_5 == (undefined4 *)0x0) {
          return 0;
        }
        *param_5 = 0;
        return 0;
      }
      if ((*(uint *)(piVar2[2] + 8) & 0x20000000) != 0) {
        *(uint *)(piVar2[2] + 8) = *(uint *)(piVar2[2] + 8) & 0xdfffffff;
        FUN_000227fc((int)param_1,piVar2[2]);
        return 0;
      }
      piVar4 = (int *)FUN_00024788(param_1);
      if (piVar4 == (int *)0x0) {
        if ((*(undefined4 **)(*param_1 + 4) == (undefined4 *)0x0) ||
           (puVar7 = (undefined4 *)**(undefined4 **)(*param_1 + 4), puVar7 == (undefined4 *)0x0)) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)*puVar7;
        }
        if ((piVar4 != (int *)0x0) && (iVar1 = piVar4[2], (*(uint *)(iVar1 + 8) & 0x20) != 0)) {
          *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xffffffdf;
          *(uint *)(piVar4[2] + 8) = *(uint *)(piVar4[2] + 8) | 4;
          InvalidateRect(param_2,(RECT *)(piVar4[2] + 0xc),0);
          piVar4 = (int *)0x0;
        }
      }
      else {
        uVar5 = GetWindowLongW(*(HWND *)(piVar2[2] + 0x1c),-0x10);
        if (piVar2 == piVar4) {
          if ((uVar5 & 0x80000000) != 0) {
            return 0;
          }
          if ((uVar5 & 0x8000000) != 0) {
            return 0;
          }
        }
        *(uint *)(piVar4[2] + 8) = *(uint *)(piVar4[2] + 8) & 0xffffffdf;
        *(uint *)(piVar4[2] + 8) = *(uint *)(piVar4[2] + 8) | 4;
        hWnd_00 = *(HWND *)(piVar4[2] + 0x1c);
        CopyRect(&tStack_58,(RECT *)(piVar4[2] + 0xc));
      }
      if (*(int *)(piVar2[2] + 0x14) == *(int *)(piVar2[2] + 0xc)) {
        piVar2 = FUN_00015a70((undefined4 *)*param_1,piVar2);
        FUN_00021690((int *)*param_1,piVar2,param_1[0x2b]);
        FUN_0002400c(param_1,(HWND)param_1[2]);
      }
      if ((param_4 != 0) && (piVar2 == piVar4)) {
        ShowWindow(*(HWND *)(piVar2[2] + 0x1c),6);
        sndPlaySoundW(L"Minimize",0x10003);
        FUN_00026904(param_1,param_2,-1,0,(undefined4 *)0x0);
        FUN_000300f0(piVar4[2],param_2,0);
        return 0;
      }
      FUN_000227fc((int)param_1,piVar2[2]);
      goto LAB_00026ab8;
    }
    iVar1 = FUN_00024788(param_1);
    if (iVar1 != 0) {
      *(uint *)(*(int *)(iVar1 + 8) + 8) = *(uint *)(*(int *)(iVar1 + 8) + 8) & 0xffffffdf;
      *(uint *)(*(int *)(iVar1 + 8) + 8) = *(uint *)(*(int *)(iVar1 + 8) + 8) | 4;
      hWnd_00 = *(HWND *)(*(int *)(iVar1 + 8) + 0x1c);
      CopyRect(&tStack_58,(RECT *)(*(int *)(iVar1 + 8) + 0xc));
    }
    if (param_1[0x28] == 0) goto LAB_00026ac0;
    param_4 = 1;
    FUN_000227fc((int)param_1,0);
LAB_00026ac8:
    SetForegroundWindow((HWND)(*(uint *)(DAT_00035570 + 4) | 1));
    pHVar6 = *(HWND *)(DAT_00035570 + 4);
  }
  UpdateWindow(pHVar6);
LAB_00026e7c:
  if (hWnd_00 != local_60) {
    if (hWnd_00 != (HWND)0x0) {
      GetClientRect(hWnd_00,&tStack_38);
      InvalidateRect(param_2,&tStack_58,0);
    }
    if (local_60 != (HWND)0x0) {
      if (param_4 != 0) {
        GetClientRect(local_60,&tStack_38);
      }
      InvalidateRect(param_2,&tStack_48,0);
    }
    if ((hWnd_00 != (HWND)0x0) || (local_60 != (HWND)0x0)) {
      UpdateWindow(param_2);
    }
  }
  return 1;
}



/* 00026ef8 FUN_00026ef8 */

/* Boundary evidence: original MIPS .pdata 00026ef8..00026f1b. Semantic name remains unreviewed. */

void FUN_00026ef8(undefined4 *param_1)

{
  FUN_0002546c(param_1);
  FUN_0002bdf0();
  return;
}



/* 00026f1c FUN_00026f1c */

/* Boundary evidence: original MIPS .pdata 00026f1c..00026fbb. Semantic name remains unreviewed. */

void FUN_00026f1c(int *param_1,undefined4 param_2,undefined4 param_3)

{
  LSTATUS LVar1;
  undefined4 local_res8 [2];
  HKEY local_10 [2];
  
  local_res8[0] = param_3;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Clock",0,0,local_10);
  if (LVar1 == 0) {
    RegSetValueExW(local_10[0],L"SHOW_CLOCK",0,4,(BYTE *)local_res8,4);
    RegCloseKey(local_10[0]);
  }
  FUN_000252fc(param_1);
  return;
}



/* 00026fbc FUN_00026fbc */

/* Boundary evidence: original MIPS .pdata 00026fbc..000271cf. Semantic name remains unreviewed. */

void FUN_00026fbc(int *param_1,HWND param_2,int param_3)

{
  HWND pHVar1;
  LRESULT LVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar5 = param_1[0x12];
  iVar6 = param_1[0x14];
  iVar8 = param_1[0x15];
  iVar7 = param_1[0xf];
  if (param_3 == 0) {
    pHVar1 = GetDlgItem(param_2,0xbc2);
    LVar2 = SendMessageW(pHVar1,0xf0,0,0);
    uVar4 = (uint)(LVar2 == 1);
    param_1[0x12] = uVar4;
    if (uVar4 != uVar5) {
      FUN_00022a54(param_1,uVar4);
    }
  }
  else {
    pHVar1 = GetDlgItem(param_2,0xbb9);
    LVar2 = SendMessageW(pHVar1,0xf0,0,0);
    param_1[0x14] = (uint)(LVar2 == 1);
    pHVar1 = GetDlgItem(param_2,3000);
    LVar2 = SendMessageW(pHVar1,0xf0,0,0);
    param_1[0x15] = (uint)(LVar2 == 1);
    pHVar1 = GetDlgItem(param_2,0xbba);
    LVar2 = SendMessageW(pHVar1,0xf0,0,0);
    param_1[0xf] = (uint)(LVar2 == 1);
    if (param_1[0x14] != iVar6) {
      if (param_1[0x14] == 0) {
        param_1[0x16] = 1;
        FUN_0002249c((int)param_1);
      }
      else {
        FUN_00022568((int)param_1,(HWND)param_1[2]);
      }
      FUN_000228a0(param_1,param_1[0x14]);
    }
    FUN_00023124(param_1,(uint)(param_1[0x14] == 0),param_1[0x15]);
    iVar3 = param_1[0x15];
    if ((iVar8 != iVar3) || ((param_1[0x14] != iVar6 && (iVar3 == 0)))) {
      pHVar1 = (HWND)0xffffffff;
      if (iVar3 == 0) {
        pHVar1 = (HWND)0xfffffffe;
      }
      SetWindowPos((HWND)param_1[2],pHVar1,0,0,0,0,3);
      FUN_00022d4c(param_1,param_1[0x15]);
    }
    if (iVar7 != param_1[0xf]) {
      FUN_00026f1c(param_1,param_1[2],param_1[0xf]);
    }
    FUN_00022f00((int)param_1);
  }
  return;
}



/* 000271d0 FUN_000271d0 */

/* Boundary evidence: original MIPS .pdata 000271d0..00027303. Semantic name remains unreviewed. */

void FUN_000271d0(int *param_1)

{
  HWND hWndInsertAfter;
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = param_1 + 0x14;
  piVar1 = param_1 + 0x15;
  iVar4 = *piVar3;
  iVar2 = *piVar1;
  FUN_00022994(param_1,(LPBYTE)piVar3);
  FUN_00022e40(param_1,(LPBYTE)piVar1);
  FUN_00022c08(param_1,(LPBYTE)(param_1 + 0x1c));
  FUN_00022cac(param_1,(LPBYTE)(param_1 + 0x1d));
  if (iVar4 != *piVar3) {
    if (*piVar3 == 0) {
      param_1[0x16] = 1;
      FUN_0002249c((int)param_1);
    }
    else {
      FUN_00022568((int)param_1,(HWND)param_1[2]);
    }
  }
  if (iVar2 != *piVar1) {
    hWndInsertAfter = (HWND)0xffffffff;
    if (*piVar1 == 0) {
      hWndInsertAfter = (HWND)0xfffffffe;
    }
    SetWindowPos((HWND)param_1[2],hWndInsertAfter,0,0,0,0,0x13);
  }
  FUN_000252fc(param_1);
  if ((iVar4 != *piVar3) || (iVar2 != *piVar1)) {
    FUN_00023124(param_1,(uint)(*piVar3 == 0),*piVar1);
    FUN_00022f00((int)param_1);
  }
  return;
}



/* 00027304 FUN_00027304 */

/* Boundary evidence: original MIPS .pdata 00027304..00027473. Semantic name remains unreviewed. */

void FUN_00027304(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int nWidth;
  int iVar1;
  uint uVar2;
  undefined1 auStack_1c [12];
  
  if (param_4 == 0x3001) {
    memset(auStack_1c,0,0xc);
    nWidth = GetSystemMetrics(0);
    iVar1 = GetSystemMetrics(1);
    MoveWindow(*(HWND *)(DAT_0003556c + 8),0,iVar1 + -0x1a,nWidth,iVar1 - (iVar1 + -0x1a),0);
    FUN_00025394(param_1);
    FUN_00022f00((int)param_1);
    FUN_00023124(param_1,(uint)(param_1[0x14] == 0),param_1[0x15]);
    UpdateWindow(*(HWND *)(DAT_0003556c + 8));
    if ((param_1[0x14] != 0) && (param_1[0x13] != 0)) {
      FUN_00022568((int)param_1,(HWND)param_1[2]);
    }
  }
  else {
    if (param_4 == 0xe0) {
      FUN_00024fac(param_1,0);
    }
    if (param_4 == 0x2f) {
      FUN_0002c900();
    }
    if (param_5 == 1) {
      uVar2 = FUN_0002b30c();
      FUN_0002bf24();
      FUN_00025fb0(param_1,uVar2);
      param_1[0xe] = 1;
    }
    else if (param_5 == 5000) {
      FUN_000271d0(param_1);
    }
  }
  return;
}



/* 00027474 FUN_00027474 */

/* Boundary evidence: original MIPS .pdata 00027474..00027ab3. Semantic name remains unreviewed. */

int FUN_00027474(int *param_1,HWND param_2)

{
  LANGID LVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  int iVar4;
  HWND pHVar5;
  void *pvVar6;
  ushort uVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  DWORD dwExStyle;
  HWND hWndInsertAfter;
  DWORD dwStyle;
  uint local_78 [2];
  tagPOINT tStack_70;
  tagRECT local_68;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  tagPOINT local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_34;
  
  local_58 = 0;
  dwStyle = 0x80000000;
  memset(&local_54,0,0x28);
  BVar2 = GetCursorPos(&tStack_70);
  param_1[0x1b] = BVar2;
  if (param_2 == (HWND)0x0) {
    iVar4 = GetSystemMetrics(1);
    iVar9 = GetSystemMetrics(0);
    SetRect(&local_68,0,0,iVar9,iVar4);
  }
  else {
    dwStyle = 0xc0000000;
    GetClientRect(param_2,&local_68);
  }
  puVar3 = operator_new(0x20);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 3));
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
  }
  param_1[1] = (int)puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    iVar4 = 0;
  }
  else {
    dwExStyle = 0;
    LVar1 = GetUserDefaultUILanguage();
    uVar7 = LVar1 & 0x3ff;
    if ((((uVar7 == 1) || (uVar7 == 0x29)) || (uVar7 == 0xd)) || (uVar7 == 0x20)) {
      dwExStyle = 0x400000;
    }
    local_68.top = local_68.bottom + -0x1a;
    pHVar5 = CreateWindowExW(dwExStyle,L"HHTaskBar",L"",dwStyle,local_68.left,local_68.top,
                             local_68.right - local_68.left,local_68.bottom - local_68.top,param_2,
                             (HMENU)0x0,DAT_00035560,(LPVOID)0x0);
    param_1[2] = (int)pHVar5;
    FUN_00021968(param_1,pHVar5);
    FUN_00023490(param_1,param_1[2],&local_68);
    pHVar5 = CreateWindowExW(0x8000000,L"HHTaskBarTray",L"",0x50000000,local_68.left,local_68.top,
                             local_68.right - local_68.left,local_68.bottom - local_68.top,
                             (HWND)param_1[2],(HMENU)0x0,DAT_00035560,(LPVOID)0x0);
    param_1[4] = (int)pHVar5;
    FUN_000252fc(param_1);
    pHVar5 = CreateWindowExW(8,L"tooltips_class32",(LPCWSTR)0x0,0x80000003,-0x80000000,-0x80000000,
                             -0x80000000,-0x80000000,(HWND)param_1[2],(HMENU)0x0,DAT_00035560,
                             (LPVOID)0x0);
    hWndInsertAfter = (HWND)0xffffffff;
    param_1[3] = (int)pHVar5;
    local_58 = 0x2c;
    local_54 = 0x10;
    local_50 = param_1[2];
    local_34 = 0xffffffff;
    iVar4 = *(int *)*param_1;
    if (iVar4 != 0) {
      iVar9 = *(int *)(iVar4 + 8);
      local_48.x = *(LONG *)(iVar9 + 0xc);
      local_48.y = *(LONG *)(iVar9 + 0x10);
      local_40 = *(undefined4 *)(iVar9 + 0x14);
      local_3c = *(undefined4 *)(iVar9 + 0x18);
      local_4c = iVar4;
      SendMessageW(pHVar5,0x432,0,(LPARAM)&local_58);
    }
    if (((*(undefined4 **)(*param_1 + 4) != (undefined4 *)0x0) &&
        (piVar8 = (int *)**(undefined4 **)(*param_1 + 4), piVar8 != (int *)0x0)) &&
       (iVar4 = *piVar8, iVar4 != 0)) {
      iVar9 = *(int *)(iVar4 + 8);
      local_48.x = *(LONG *)(iVar9 + 0xc);
      local_48.y = *(LONG *)(iVar9 + 0x10);
      local_40 = *(undefined4 *)(iVar9 + 0x14);
      local_3c = *(undefined4 *)(iVar9 + 0x18);
      local_4c = iVar4;
      SendMessageW((HWND)param_1[3],0x432,0,(LPARAM)&local_58);
    }
    if (param_1[0x22] != 0) {
      if ((*(int **)(*param_1 + 4) != (int *)0x0) && (iVar4 = **(int **)(*param_1 + 4), iVar4 != 0))
      {
        iVar9 = *(int *)(iVar4 + 8);
        local_48.x = *(LONG *)(iVar9 + 0xc);
        local_48.y = *(LONG *)(iVar9 + 0x10);
        local_40 = *(undefined4 *)(iVar9 + 0x14);
        local_3c = *(undefined4 *)(iVar9 + 0x18);
        local_4c = iVar4;
        SendMessageW((HWND)param_1[3],0x432,0,(LPARAM)&local_58);
      }
      FUN_0002c798(param_1[2]);
    }
    if ((param_1[0x26] != 0) && (iVar4 = *(int *)(*param_1 + 4), iVar4 != 0)) {
      iVar9 = *(int *)(iVar4 + 8);
      local_48.x = *(LONG *)(iVar9 + 0xc);
      local_48.y = *(LONG *)(iVar9 + 0x10);
      local_40 = *(undefined4 *)(iVar9 + 0x14);
      local_3c = *(undefined4 *)(iVar9 + 0x18);
      local_4c = iVar4;
      SendMessageW((HWND)param_1[3],0x432,0,(LPARAM)&local_58);
    }
    if ((((*(undefined4 **)(*param_1 + 4) != (undefined4 *)0x0) &&
         (piVar8 = (int *)**(undefined4 **)(*param_1 + 4), piVar8 != (int *)0x0)) &&
        (piVar8 = (int *)*piVar8, piVar8 != (int *)0x0)) && (iVar4 = *piVar8, iVar4 != 0)) {
      local_50 = param_1[4];
      local_4c = iVar4;
      FUN_00023644(param_1,&local_48.x);
      MapWindowPoints((HWND)param_1[2],(HWND)param_1[4],&local_48,2);
      SendMessageW((HWND)param_1[3],0x432,0,(LPARAM)&local_58);
    }
    if (param_1[8] != 0) {
      FUN_0002da48(param_1[8],param_1[2],1);
    }
    SystemParametersInfoW(0x59,0,local_78,0);
    FUN_00025fb0(param_1,local_78[0]);
    if ((HWND)param_1[2] != (HWND)0x0) {
      SetTimer((HWND)param_1[2],0x2a,30000,(TIMERPROC)0x0);
      FUN_0002562c(param_1,(HWND)param_1[2]);
      piVar8 = param_1 + 0x15;
      *piVar8 = 1;
      FUN_00022b48(param_1,(LPBYTE)(param_1 + 0x12));
      piVar10 = param_1 + 0x14;
      FUN_00022994(param_1,(LPBYTE)piVar10);
      FUN_00022e40(param_1,(LPBYTE)piVar8);
      FUN_00022c08(param_1,(LPBYTE)(param_1 + 0x1c));
      FUN_00022cac(param_1,(LPBYTE)(param_1 + 0x1d));
      FUN_00022f00((int)param_1);
      if (*piVar8 == 0) {
        hWndInsertAfter = (HWND)0xfffffffe;
      }
      SetWindowPos((HWND)param_1[2],hWndInsertAfter,0,0,0,0,3);
      FUN_00023124(param_1,(uint)(*piVar10 == 0),*piVar8);
      if (*piVar10 == 0) {
        param_1[0x13] = 1;
        FUN_0002249c((int)param_1);
      }
      else {
        param_1[0x13] = 0;
        FUN_00022568((int)param_1,(HWND)param_1[2]);
      }
      InvalidateRect((HWND)param_1[2],(RECT *)0x0,1);
      ShowWindow((HWND)param_1[2],1);
      UpdateWindow((HWND)param_1[2]);
    }
    pvVar6 = operator_new(0x1c);
    if (pvVar6 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_000331d4(pvVar6);
    }
    param_1[7] = iVar4;
    if (iVar4 != 0) {
      FUN_0002f024();
    }
    if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
      FUN_0002d830((undefined4 *)param_1[9]);
    }
    SetFocus((HWND)param_1[2]);
    iVar4 = param_1[2];
  }
  return iVar4;
}



/* 00027ab4 FUN_00027ab4 */

/* Boundary evidence: original MIPS .pdata 00027ab4..00027c13. Semantic name remains unreviewed. */

undefined4 FUN_00027ab4(int *param_1,HWND param_2,HDC param_3,RECT *param_4)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  RECT local_40;
  tagRECT local_30;
  
  piVar4 = *(int **)(*param_1 + 4);
  iVar2 = *(int *)(*param_1 + 8);
  local_30.left = 0;
  memset(&local_30.top,0,0xc);
  if (param_1[0x13] == 0) {
    for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      iVar2 = iVar2 + -1;
      iVar3 = piVar4[2];
      if ((*(uint *)(iVar3 + 8) & 0x50) == 0) {
        if ((param_2 == (HWND)param_1[2]) &&
           (BVar1 = IntersectRect(&local_30,(RECT *)(iVar3 + 0xc),param_4), BVar1 != 0)) {
          FUN_00026368(param_1,(int)param_2,param_3,iVar2,0);
        }
      }
      else if (param_2 == (HWND)param_1[4]) {
        local_40.left = *(LONG *)(iVar3 + 0xc);
        local_40.top = *(LONG *)(iVar3 + 0x10);
        local_40.right = *(LONG *)(iVar3 + 0x14);
        local_40.bottom = *(LONG *)(iVar3 + 0x18);
        MapWindowPoints((HWND)param_1[2],(HWND)param_1[4],(LPPOINT)&local_40,2);
        BVar1 = IntersectRect(&local_30,&local_40,param_4);
        if (BVar1 != 0) {
          FUN_00026368(param_1,(int)param_2,param_3,iVar2,0);
        }
      }
    }
  }
  return 1;
}



/* 00027c14 FUN_00027c14 */

/* Boundary evidence: original MIPS .pdata 00027c14..00027d7f. Semantic name remains unreviewed. */

undefined4 FUN_00027c14(int *param_1,HWND param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = FUN_00024788(param_1);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 4), iVar1 != 0)) {
    for (iVar3 = *(int *)*param_1; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
      if ((*(uint *)(*(int *)(iVar3 + 8) + 8) & 0x40) != 0) goto LAB_00027cb0;
    }
    piVar2 = (int *)((int *)*param_1)[1];
    if (((piVar2 == (int *)0x0) || (piVar2 = (int *)*piVar2, piVar2 == (int *)0x0)) ||
       (piVar2 = (int *)*piVar2, piVar2 == (int *)0x0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *piVar2;
    }
LAB_00027cb0:
    if (iVar1 != iVar3) goto LAB_00027d30;
  }
  iVar3 = *(int *)*param_1;
  iVar1 = 0;
  if (iVar3 != 0) {
    iVar1 = *(int *)(iVar3 + 4);
    for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
      if ((*(uint *)(*(int *)(iVar3 + 8) + 8) & 0x40) != 0) goto LAB_00027d20;
    }
  }
  piVar2 = (int *)((int *)*param_1)[1];
  if (((piVar2 == (int *)0x0) || (piVar2 = (int *)*piVar2, piVar2 == (int *)0x0)) ||
     (piVar2 = (int *)*piVar2, piVar2 == (int *)0x0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar2;
  }
LAB_00027d20:
  if (iVar1 == iVar3) {
    return 0;
  }
LAB_00027d30:
  if (iVar1 != 0) {
    iVar1 = FUN_00023da4(param_1,param_2,*(int *)(*(int *)(iVar1 + 8) + 0x1c));
    FUN_00026904(param_1,param_2,iVar1,1,(undefined4 *)0x0);
  }
  return 1;
}



/* 00027d80 FUN_00027d80 */

/* Boundary evidence: original MIPS .pdata 00027d80..000280cb. Semantic name remains unreviewed. */

void FUN_00027d80(int *param_1,HWND param_2,int param_3,HWND param_4,undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  HANDLE local_ac;
  undefined1 local_a8;
  undefined1 local_a7;
  uint local_28;
  
  local_28 = DAT_00035518;
  if (param_4 != (HWND)param_1[2]) {
    if (param_4 == *(HWND *)(DAT_00035570 + 4)) {
      FUN_00026904(param_1,param_2,0,0,(undefined4 *)0x0);
    }
    else {
      iVar1 = FUN_00023da4(param_1,param_2,(int)param_4);
      if (param_3 == 6) {
        if (iVar1 == -1) {
          FUN_00025954(param_1,param_4);
        }
      }
      else if (param_3 == 7) {
        if (iVar1 != -1) {
          FUN_00025bb4(param_1,param_2,iVar1,1);
          *param_5 = 0xffffffff;
        }
      }
      else if (param_3 == 8) {
        if (iVar1 != -1) {
          FUN_00026904(param_1,param_2,iVar1,0,(undefined4 *)0x0);
        }
      }
      else if (param_3 == 9) {
        if (iVar1 != -1) {
          piVar2 = FUN_00023388(param_1,param_2,iVar1);
          iVar4 = 0;
          if (piVar2 != (int *)0x0) {
            iVar4 = piVar2[2];
          }
          iVar3 = GetWindowTextWDirect(param_4,(undefined2 *)(iVar4 + 0x20),0x104);
          if (iVar3 == 0) {
            *(undefined2 *)(iVar4 + 0x20) = 0;
          }
          if (((*(uint *)(iVar4 + 8) & 0x10000000) != 0) && (*(HICON *)(iVar4 + 4) != (HICON)0x0)) {
            DestroyIcon(*(HICON *)(iVar4 + 4));
            *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) & 0xefffffff;
          }
          piVar2 = (int *)(iVar4 + 4);
          iVar3 = SendMessageTimeout(param_4,0x7f,0,0,0,2000,piVar2);
          if (iVar3 == 0) {
            *piVar2 = 0;
          }
          if (*piVar2 == -0x7fffbffb) {
            *piVar2 = 0;
          }
          if (*piVar2 == 0) {
            *piVar2 = param_1[0xb];
          }
          FUN_0002457c(param_1,param_2,iVar1,iVar4);
        }
      }
      else if (param_3 == 10) {
        FUN_00025fb0(param_1,(uint)param_4);
      }
      else if (param_3 == 0xb) {
        local_bc = param_1[2];
        local_b0 = 0x402;
        local_c0 = 0x98;
        local_b4 = 2;
        local_ac = (HANDLE)0x0;
        local_a8 = 0;
        local_a7 = 0;
        if (param_4 == (HWND)0x0) {
          local_b8 = 3;
          FUN_000147e4(2,&local_c0);
        }
        else {
          local_b4 = 2;
          local_b8 = 3;
          local_ac = LoadImageW(DAT_00035560,(LPCWSTR)0x4d2,1,0x10,0x10,0);
          FUN_000147e4(0,&local_c0);
          FUN_00023ea8(param_1,param_1[2],(int)&local_c0);
        }
      }
    }
  }
  FUN_00033770(local_28);
  return;
}



/* 000280cc FUN_000280cc */

/* Boundary evidence: original MIPS .pdata 000280cc..0002824f. Semantic name remains unreviewed. */

undefined4 FUN_000280cc(int *param_1,HWND param_2,int param_3,short param_4,int param_5)

{
  HWND pHVar1;
  int iVar2;
  
  if (param_3 == 0x4e) {
    iVar2 = *(int *)(param_5 + 8);
    if (iVar2 == -0xca) {
      FUN_00026fbc(param_1,param_2,0);
    }
    else if (iVar2 != -0xd1) {
      if (iVar2 != -200) {
        return 0;
      }
      iVar2 = FUN_000231e8();
      pHVar1 = GetDlgItem(param_2,1);
      EnableWindow(pHVar1,(uint)(iVar2 != 0));
      return 0;
    }
    SetWindowLongW(param_2,0,0);
    PostMessageW((HWND)0x0,0,0,0);
  }
  else if (param_3 == 0x110) {
    pHVar1 = GetDlgItem(param_2,0xbc2);
    SendMessageW(pHVar1,0xf1,(uint)(param_1[0x12] != 0),0);
  }
  else if ((param_3 == 0x111) && (param_4 == 1)) {
    SHAddToRecentDocs(0,(LPCVOID)0x0);
    pHVar1 = GetDlgItem(param_2,1);
    EnableWindow(pHVar1,0);
    pHVar1 = GetDlgItem(param_2,0xbc2);
    if (pHVar1 != (HWND)0x0) {
      SetFocus(pHVar1);
    }
  }
  return 0;
}



/* 00028250 FUN_00028250 */

/* Boundary evidence: original MIPS .pdata 00028250..000283b7. Semantic name remains unreviewed. */

undefined4 FUN_00028250(int *param_1,HWND param_2,int param_3,undefined4 param_4,int param_5)

{
  HWND pHVar1;
  int iVar2;
  
  if (param_3 == 0x4e) {
    iVar2 = *(int *)(param_5 + 8);
    if (iVar2 == -0xca) {
      FUN_00026fbc(param_1,param_2,1);
    }
    else if ((iVar2 != -0xc9) && (iVar2 != -0xd1)) {
      return 0;
    }
    SetWindowLongW(param_2,0,0);
    PostMessageW((HWND)0x0,0,0,0);
  }
  else if (param_3 == 0x110) {
    FUN_0001e71c(param_2,8);
    pHVar1 = GetDlgItem(param_2,0xbb9);
    SendMessageW(pHVar1,0xf1,(uint)(param_1[0x14] != 0),0);
    pHVar1 = GetDlgItem(param_2,3000);
    SendMessageW(pHVar1,0xf1,(uint)(param_1[0x15] != 0),0);
    pHVar1 = GetDlgItem(param_2,0xbba);
    SendMessageW(pHVar1,0xf1,(uint)(param_1[0xf] != 0),0);
    GetParent(param_2);
  }
  return 0;
}



/* 000283b8 FUN_000283b8 */

/* Boundary evidence: original MIPS .pdata 000283b8..00028b8f. Semantic name remains unreviewed. */

LRESULT FUN_000283b8(int *param_1,HWND param_2,uint param_3,HDC param_4,int *param_5)

{
  POINT pt;
  POINT pt_00;
  BOOL BVar1;
  HBRUSH hbr;
  HDC pHVar2;
  UINT lParam;
  HWND hWnd;
  LRESULT LVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  tagPOINT local_90;
  uint local_88 [2];
  RECT local_80;
  tagRECT local_70;
  tagPAINTSTRUCT tStack_60;
  uint local_20;
  
  local_20 = DAT_00035518;
  if (param_3 < 0x203) {
    if (param_3 != 0x202) {
      if (param_3 == 0xf) {
        pHVar2 = BeginPaint(param_2,&tStack_60);
        FUN_00027ab4(param_1,param_2,pHVar2,&tStack_60.rcPaint);
        EndPaint(param_2,&tStack_60);
      }
      else {
        if (param_3 == 0x14) {
          GetClientRect(param_2,&local_70);
          hbr = GetSysColorBrush(0x4000000f);
          FillRect(param_4,&local_70,hbr);
          FUN_00033770(local_20);
          return 1;
        }
        if (param_3 == 0x4e) {
          if ((((param_5 != (int *)0x0) && (param_1[3] == *param_5)) && (param_5[2] == -0x212)) &&
             (BVar1 = GetCursorPos(&local_90), BVar1 != 0)) {
            MapWindowPoints((HWND)0x0,(HWND)param_1[2],&local_90,1);
            iVar7 = FUN_00024644(param_1,param_2,local_90.x,local_90.y,local_88);
            if (iVar7 != -1) {
              piVar4 = FUN_00023388(param_1,param_2,iVar7);
              if (((*(undefined4 **)(*param_1 + 4) == (undefined4 *)0x0) ||
                  (puVar6 = (undefined4 *)**(undefined4 **)(*param_1 + 4),
                  puVar6 == (undefined4 *)0x0)) ||
                 (puVar6 = (undefined4 *)*puVar6, puVar6 == (undefined4 *)0x0)) {
                piVar5 = (int *)0x0;
              }
              else {
                piVar5 = (int *)*puVar6;
              }
              if (piVar4 == piVar5) {
                GetDateFormatW(0x400,2,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,(LPWSTR)(param_5 + 4),0x50);
              }
              else if ((piVar4 != (int *)0x0) && (*(STRSAFE_LPCWSTR)(piVar4[2] + 0x20) != L'\0')) {
                StringCchCopyW((STRSAFE_LPWSTR)(param_5 + 4),0x50,
                               (STRSAFE_LPCWSTR)(piVar4[2] + 0x20));
              }
            }
            SetWindowPos((HWND)param_1[3],(HWND)0xffffffff,0,0,0,0,0x13);
          }
        }
        else if (param_3 == 0x200) {
          local_90.x = (uint)param_5 & 0xffff;
          local_90.y = (uint)param_5 >> 0x10;
          MapWindowPoints((HWND)param_1[4],(HWND)param_1[2],&local_90,1);
          if ((param_1[0x19] != local_90.x) || (param_1[0x1a] != local_90.y)) {
            iVar7 = FUN_00024644(param_1,param_2,local_90.x,local_90.y,local_88);
            if ((iVar7 != -1) && ((local_88[0] & 0x40) != 0)) {
              FUN_00026484(param_1,param_2,iVar7,0x200);
            }
            param_1[0x19] = local_90.x;
            param_1[0x1a] = local_90.y;
          }
        }
        else {
          if (param_3 != 0x201) goto LAB_00028a3c;
          local_90.x = (uint)param_5 & 0xffff;
          local_90.y = (uint)param_5 >> 0x10;
          MapWindowPoints((HWND)param_1[4],(HWND)param_1[2],&local_90,1);
          FUN_00023490(param_1,param_1[2],&local_70);
          local_80.left = local_70.left;
          local_80.top = local_70.top;
          local_80.right = local_70.right;
          local_80.bottom = local_70.bottom;
          if ((0 < param_1[0x2f]) && (0 < param_1[0x30])) {
            local_80.right = param_1[0x31] + local_70.left + 5;
            pt.y = local_90.y;
            pt.x = local_90.x;
            BVar1 = PtInRect(&local_80,pt);
            if (BVar1 != 0) {
              FUN_00026484(param_1,param_2,-6,0x201);
              goto LAB_00028b60;
            }
          }
          if ((((param_1[0x2f] < param_1[0x30] - param_1[0x2e]) && (param_1[0x2e] < param_1[0x30]))
              && (*(int **)(*param_1 + 4) != (int *)0x0)) &&
             (((piVar4 = (int *)**(int **)(*param_1 + 4), piVar4 != (int *)0x0 &&
               (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0)) && (iVar7 = *piVar4, iVar7 != 0))))
          {
            local_80.right = *(int *)(*(int *)(iVar7 + 8) + 0xc) - param_1[0x31];
            local_80.left = local_80.right + -5;
            pt_00.y = local_90.y;
            pt_00.x = local_90.x;
            BVar1 = PtInRect(&local_80,pt_00);
            if (BVar1 != 0) {
              FUN_00026484(param_1,param_2,-7,0x201);
              goto LAB_00028b60;
            }
          }
          iVar7 = FUN_00024644(param_1,param_2,local_90.x,local_90.y,local_88);
          if ((iVar7 != -1) && ((local_88[0] & 0x40) != 0)) {
            FUN_00026484(param_1,param_2,iVar7,0x201);
          }
        }
      }
      goto LAB_00028b60;
    }
  }
  else {
    if (param_3 == 0x203) {
      local_90.x = (uint)param_5 & 0xffff;
      local_90.y = (uint)param_5 >> 0x10;
      MapWindowPoints((HWND)param_1[4],(HWND)param_1[2],&local_90,1);
      iVar7 = FUN_00024644(param_1,param_2,local_90.x,local_90.y,local_88);
      if (iVar7 != -1) {
        if ((local_88[0] & 0x40) == 0) {
          piVar4 = FUN_00023388(param_1,param_2,iVar7);
          if (((*(undefined4 **)(*param_1 + 4) == (undefined4 *)0x0) ||
              (puVar6 = (undefined4 *)**(undefined4 **)(*param_1 + 4), puVar6 == (undefined4 *)0x0))
             || (puVar6 = (undefined4 *)*puVar6, puVar6 == (undefined4 *)0x0)) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = (int *)*puVar6;
          }
          if ((piVar4 == piVar5) &&
             (iVar7 = FUN_0002c9e4(param_2,L"clock",L"Date & Time"), iVar7 == 0)) {
            FUN_0002c9e4(param_2,L"ctlpnl",L"clock.cpl");
          }
        }
        else {
          FUN_00026484(param_1,param_2,iVar7,0x203);
        }
      }
      goto LAB_00028b60;
    }
    if (param_3 < 0x204) {
LAB_00028a3c:
      LVar3 = DefWindowProcW(param_2,param_3,(WPARAM)param_4,(LPARAM)param_5);
      FUN_00033770(local_20);
      return LVar3;
    }
    if (0x205 < param_3) {
      if (param_3 == 0x404) {
        if (param_1[8] != 0) {
          FUN_0002e350(param_1[8],param_2,(int)param_4,(int)param_5);
        }
      }
      else {
        if (param_3 != 0x405) goto LAB_00028a3c;
        if ((param_5 == (int *)0x203) || (param_5 == (int *)0x201)) {
          for (iVar7 = *(int *)*param_1; iVar7 != 0; iVar7 = *(int *)(iVar7 + 4)) {
            if ((*(uint *)(*(int *)(iVar7 + 8) + 8) & 0x40) != 0) goto LAB_00028924;
          }
          piVar4 = (int *)((int *)*param_1)[1];
          if (((piVar4 == (int *)0x0) || (piVar4 = (int *)*piVar4, piVar4 == (int *)0x0)) ||
             (piVar4 = (int *)*piVar4, piVar4 == (int *)0x0)) {
            iVar7 = 0;
          }
          else {
            iVar7 = *piVar4;
          }
LAB_00028924:
          if (iVar7 != 0) {
            do {
              if ((*(uint *)(*(int *)(iVar7 + 8) + 8) & 0x100) != 0) break;
              iVar7 = *(int *)(iVar7 + 4);
            } while (iVar7 != 0);
            if ((iVar7 != 0) &&
               (lParam = FUN_0002b45c((HWND)param_1[2],(int *)(*(int *)(iVar7 + 8) + 0xc)),
               lParam != 0)) {
              hWnd = GetForegroundWindow();
              PostMessageW(hWnd,0x50,0,lParam);
            }
          }
        }
      }
      goto LAB_00028b60;
    }
  }
  local_90.x = (uint)param_5 & 0xffff;
  local_90.y = (uint)param_5 >> 0x10;
  MapWindowPoints((HWND)param_1[4],(HWND)param_1[2],&local_90,1);
  iVar7 = FUN_00024644(param_1,param_2,local_90.x,local_90.y,local_88);
  if ((iVar7 != -1) && ((local_88[0] & 0x40) != 0)) {
    FUN_00026484(param_1,param_2,iVar7,param_3);
  }
LAB_00028b60:
  FUN_00033770(local_20);
  return 0;
}



/* 00028b90 FUN_00028b90 */

/* Boundary evidence: original MIPS .pdata 00028b90..00028bd7. Semantic name remains unreviewed. */

undefined4 FUN_00028b90(HWND param_1,int param_2,short param_3,int param_4)

{
  undefined4 uVar1;
  
  if (DAT_0003556c == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_000280cc(DAT_0003556c,param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 00028bd8 FUN_00028bd8 */

/* Boundary evidence: original MIPS .pdata 00028bd8..00028c1f. Semantic name remains unreviewed. */

undefined4 FUN_00028bd8(HWND param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (DAT_0003556c == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00028250(DAT_0003556c,param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 00028c20 FUN_00028c20 */

/* Boundary evidence: original MIPS .pdata 00028c20..00028c67. Semantic name remains unreviewed. */

LRESULT FUN_00028c20(HWND param_1,uint param_2,HDC param_3,int *param_4)

{
  LRESULT LVar1;
  
  if (DAT_0003556c == (int *)0x0) {
    LVar1 = 0;
  }
  else {
    LVar1 = FUN_000283b8(DAT_0003556c,param_1,param_2,param_3,param_4);
  }
  return LVar1;
}



/* 00028c68 FUN_00028c68 */

/* Boundary evidence: original MIPS .pdata 00028c68..00028eab. Semantic name remains unreviewed. */

undefined4 FUN_00028c68(undefined4 param_1)

{
  HWND hWnd;
  LONG dwNewLong;
  BOOL BVar1;
  LRESULT LVar2;
  undefined4 local_b0;
  PROPSHEETHEADERW_V2 local_a8;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  code *local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_54;
  _union_1968 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  code *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  tagMSG tStack_30;
  
  local_a8.dwSize = 0x28;
  local_a8.dwFlags = 0x508;
  local_a8.hwndParent = (HWND)0x0;
  local_a8.hInstance = (HINSTANCE)DAT_00035560;
  local_a8.u.hIcon = (HICON)0x0;
  local_a8.pszCaption = (LPCWSTR)0x52d0;
  local_a8.u2.nStartPage = 0;
  local_a8.u3.ppsp = (LPCPROPSHEETPAGEW)&local_a8.u4;
  local_a8.pfnCallback = (PFNPROPSHEETCALLBACK)&LAB_00024d18;
  local_a8.nPages = 2;
  local_a8.u4 = (_union_1967)0x28;
  local_a8.hplWatermark = (HPALETTE)0x8;
  local_a8.u5 = DAT_00035560;
  local_74 = 0x3ec;
  local_70 = 0;
  local_68 = FUN_00028bd8;
  local_6c = 0x5270;
  local_64 = 0;
  local_60 = 0;
  local_58 = 0x28;
  local_54 = 8;
  local_50 = DAT_00035560;
  local_4c = 0x3ed;
  local_48 = 0;
  local_40 = FUN_00028b90;
  local_44 = 0x5271;
  local_3c = 0;
  local_38 = 0;
  EventModify(param_1,3);
  hWnd = (HWND)PropertySheetW(&local_a8);
  *(HWND *)(DAT_0003556c + 0x18) = hWnd;
  if (hWnd == (HWND)0xffffffff) {
    local_b0 = 0;
  }
  else {
    dwNewLong = SetWindowLongW(hWnd,4,0x24d44);
    SetWindowLongW(hWnd,-0x15,dwNewLong);
    while (BVar1 = GetMessageW(&tStack_30,(HWND)0x0,0,0), BVar1 != 0) {
      LVar2 = SendMessageW(hWnd,0x475,0,(LPARAM)&tStack_30);
      if (LVar2 == 0) {
        if ((hWnd != (HWND)0x0) && (LVar2 = SendMessageW(hWnd,0x476,0,0), LVar2 == 0)) {
          DestroyWindow(hWnd);
          PostQuitMessage(0);
          hWnd = (HWND)0x0;
        }
        TranslateMessage(&tStack_30);
        DispatchMessageW(&tStack_30);
      }
    }
    *(undefined4 *)(DAT_0003556c + 0x18) = 0;
    local_b0 = 1;
  }
  return local_b0;
}



/* 00028eac FUN_00028eac */

/* Boundary evidence: original MIPS .pdata 00028eac..00028eb7. Semantic name remains unreviewed. */

undefined4 FUN_00028eac(void)

{
  return 1;
}



/* 00028eb8 FUN_00028eb8 */

/* Boundary evidence: original MIPS .pdata 00028eb8..00028f8f. Semantic name remains unreviewed. */

void FUN_00028eb8(void)

{
  HANDLE lpParameter;
  HANDLE hObject;
  DWORD aDStack_18 [2];
  
  if (*(HWND *)(DAT_0003556c + 0x18) == (HWND)0x0) {
    lpParameter = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (lpParameter != (HANDLE)0x0) {
      hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00028c68,lpParameter,0,aDStack_18);
      if (hObject != (HANDLE)0x0) {
        CloseHandle(hObject);
        WaitForSingleObject(lpParameter,0xffffffff);
      }
      CloseHandle(lpParameter);
    }
  }
  else {
    SetForegroundWindow(*(HWND *)(DAT_0003556c + 0x18));
  }
  return;
}



/* 00028f90 FUN_00028f90 */

/* Boundary evidence: original MIPS .pdata 00028f90..0002ac4f. Semantic name remains unreviewed. */

uint FUN_00028f90(int *param_1,HWND param_2,UINT param_3,HDC param_4,HMENU param_5)

{
  bool bVar1;
  SHORT SVar2;
  uint uVar3;
  HDC pHVar4;
  int *piVar5;
  HBRUSH pHVar6;
  HRGN hrgn;
  BOOL BVar7;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  HWND pHVar8;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 extraout_var_12;
  undefined2 extraout_var_13;
  undefined2 extraout_var_14;
  LPWSTR lpCommandLine;
  undefined2 extraout_var_15;
  undefined2 extraout_var_16;
  undefined2 extraout_var_17;
  undefined2 extraout_var_18;
  undefined2 extraout_var_19;
  undefined2 extraout_var_20;
  undefined2 extraout_var_21;
  undefined2 extraout_var_22;
  undefined2 extraout_var_23;
  undefined2 extraout_var_24;
  undefined2 extraout_var_25;
  DWORD DVar9;
  HMENU hMenu;
  HMENU pHVar10;
  wchar_t *pwVar11;
  UINT UVar12;
  uint uVar13;
  wchar_t *pwVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  undefined4 *puVar18;
  LPCRITICAL_SECTION p_Var19;
  int iVar20;
  tagPOINT local_b0;
  uint local_a8 [2];
  tagRECT tStack_a0;
  int local_90 [2];
  tagRECT local_88;
  tagPAINTSTRUCT tStack_78;
  tagRECT tStack_38;
  uint local_24;
  
  local_24 = DAT_00035518;
  if (((param_1[0x29] != 0) && (uVar3 = FUN_0002f024(), uVar3 != 0)) ||
     (uVar3 = (**(code **)(*(int *)param_1[10] + 0xc))
                        ((int *)param_1[10],param_2,param_3,param_4,param_5), uVar3 != 0))
  goto LAB_00029000;
  if (0x113 < param_3) {
    if (param_3 < 0x401) {
      if (param_3 == 0x400) {
        FUN_00027d80(param_1,param_2,(int)param_4,(HWND)param_5,&DAT_00035534);
        goto LAB_0002ac18;
      }
      if (param_3 < 0x203) {
        if (param_3 != 0x202) {
          if (param_3 == 0x117) {
            if (param_1[0xd] == 0) {
              if (param_1[0x1f] == 0) {
                DVar9 = GetMessagePos();
                local_b0.x = DVar9 & 0xffff;
                local_b0.y = DVar9 >> 0x10;
                ScreenToClient(param_2,&local_b0);
                iVar15 = FUN_00024644(param_1,param_2,local_b0.x,local_b0.y,local_a8);
                if (iVar15 != -1) {
                  bVar1 = (local_a8[0] & 0x20) == 0;
                  if (bVar1) {
                    EnableMenuItem((HMENU)param_4,0xc80,1);
                  }
                  else {
                    EnableMenuItem((HMENU)param_4,0xc80,0);
                  }
                  EnableMenuItem((HMENU)param_4,0xc81,(uint)!bVar1);
                }
              }
              else {
                DeleteMenu((HMENU)param_4,0,0x400);
                FUN_0002c498((HMENU)param_4,DAT_00035560,0xa300);
              }
            }
            else {
              FUN_00031a38((HMENU)param_4);
            }
            goto LAB_0002ac18;
          }
          if (param_3 == 0x120) {
            if (param_1[0xd] != 0) {
              uVar3 = FUN_00032004(param_5,(uint)param_4 & 0xffff);
              goto LAB_00029000;
            }
            goto LAB_0002ac18;
          }
          if (param_3 == 0x200) {
            local_b0.x = (uint)param_5 & 0xffff;
            local_b0.y = (uint)param_5 >> 0x10;
            if (param_1[0x1b] != 0) {
              FUN_00022074((int)param_1,local_b0.x,local_b0.y);
            }
            iVar15 = FUN_00024644(param_1,param_2,local_b0.x,local_b0.y,local_a8);
            if ((iVar15 != -1) && ((local_a8[0] & 0x40) != 0)) {
              FUN_00026484(param_1,param_2,iVar15,0x200);
            }
            if (DAT_0003560c == 0) goto LAB_0002ac18;
            pHVar4 = GetDC(param_2);
            if (iVar15 == DAT_00035534) {
              if (DAT_00035610 == 0) {
                DAT_00035610 = 1;
                FUN_00026368(param_1,(int)param_2,pHVar4,DAT_00035534,1);
              }
            }
            else if (DAT_00035610 != 0) {
              DAT_00035610 = 0;
              FUN_00026368(param_1,(int)param_2,pHVar4,DAT_00035534,0);
            }
          }
          else {
            if (param_3 != 0x201) goto LAB_0002aa98;
            SVar2 = GetAsyncKeyState(0x12);
            if (CONCAT22(extraout_var_25,SVar2) != 0) goto LAB_0002a7a4;
            local_b0.x = (uint)param_5 & 0xffff;
            local_b0.y = (uint)param_5 >> 0x10;
            SetFocus(param_2);
            iVar15 = param_1[0x13];
            FUN_0002249c((int)param_1);
            DAT_00035534 = FUN_00024644(param_1,param_2,local_b0.x,local_b0.y,local_a8);
            if (DAT_00035534 == 0) goto LAB_00029d78;
            if ((DAT_00035534 == -1) ||
               (((param_1[0x14] != 0 && (iVar15 != 0)) &&
                (DAT_00035534 < *(int *)(*param_1 + 8) + -3)))) goto LAB_0002ac18;
            piVar5 = FUN_00023388(param_1,param_2,DAT_00035534);
            if (*(int *)(piVar5[2] + 0x1c) == -5) {
              local_b0.x = *(uint *)(piVar5[2] + 0xc);
              piVar17 = (int *)param_1[10];
              local_b0.y = *(int *)(piVar5[2] + 0x10) - 1;
              if (piVar17 != (int *)0x0) {
                (**(code **)(*piVar17 + 0x10))(piVar17,param_2);
              }
              goto LAB_0002ac18;
            }
            if ((param_1[0x22] != 0) && (DAT_00035534 == *(int *)(*param_1 + 8) + -2)) {
              local_b0.x = *(uint *)(piVar5[2] + 0xc);
              local_b0.y = *(int *)(piVar5[2] + 0x10) - 1;
              FUN_00026790(param_1,local_b0.x,local_b0.y,DAT_00035534);
              goto LAB_0002ac18;
            }
            if (((local_a8[0] & 4) == 0) && ((local_a8[0] & 8) == 0)) {
              if ((local_a8[0] & 0x40) != 0) {
                FUN_00026484(param_1,param_2,DAT_00035534,0x201);
                DAT_00035610 = 0;
              }
              goto LAB_0002ac18;
            }
            SetCapture(param_2);
            DAT_0003560c = 1;
            pHVar4 = GetDC(param_2);
            DAT_00035610 = 1;
            FUN_00026368(param_1,(int)param_2,pHVar4,DAT_00035534,1);
          }
          ReleaseDC(param_2,pHVar4);
          goto LAB_0002ac18;
        }
        local_b0.x = (uint)param_5 & 0xffff;
        local_b0.y = (uint)param_5 >> 0x10;
        local_90[0] = 1;
        iVar15 = FUN_00024644(param_1,param_2,local_b0.x,local_b0.y,local_a8);
        pHVar8 = (HWND)0xffffffff;
        if ((iVar15 != -1) && ((local_a8[0] & 0x40) != 0)) {
          FUN_00026484(param_1,param_2,iVar15,0x202);
        }
        if (DAT_0003560c != 0) {
          ReleaseCapture();
          DAT_0003560c = 0;
        }
        pHVar4 = GetDC(param_2);
        if (DAT_00035610 != 0) {
          piVar5 = FUN_00023388(param_1,param_2,DAT_00035534);
          if (*(int *)(piVar5[2] + 0x1c) == -3) {
            if ((*(uint *)(piVar5[2] + 8) & 0x20) == 0) {
              *(uint *)(piVar5[2] + 8) = *(uint *)(piVar5[2] + 8) & 0xfffffffb;
              *(uint *)(piVar5[2] + 8) = *(uint *)(piVar5[2] + 8) | 0x28;
              FUN_00026904(param_1,param_2,0,1,(undefined4 *)0x0);
            }
            else {
              *(uint *)(piVar5[2] + 8) = *(uint *)(piVar5[2] + 8) & 0xffffffdf;
              *(uint *)(piVar5[2] + 8) = *(uint *)(piVar5[2] + 8) | 4;
              ShowWindow(*(HWND *)(DAT_00035570 + 4),6);
              if (param_1[0x15] == 0) {
                pHVar8 = (HWND)0xfffffffe;
              }
              SetWindowPos(param_2,pHVar8,0,0,0,0,3);
              FUN_00026904(param_1,param_2,-1,0,(undefined4 *)0x0);
            }
          }
          else if (((0 < DAT_00035534) && (DAT_00035534 < *(int *)(*param_1 + 8))) &&
                  (FUN_00026904(param_1,param_2,DAT_00035534,1,local_90), local_90[0] == 0)) {
            DAT_00035534 = -1;
            goto LAB_0002a680;
          }
          DAT_00035610 = 0;
          FUN_00026368(param_1,(int)param_2,pHVar4,DAT_00035534,0);
        }
LAB_0002a680:
        ReleaseDC(param_2,pHVar4);
        DAT_00035534 = -1;
LAB_0002ac18:
        FUN_00033770(local_24);
        return 0;
      }
      if (param_3 == 0x203) {
        local_b0.x = (uint)param_5 & 0xffff;
        local_b0.y = (uint)param_5 >> 0x10;
        iVar15 = FUN_00024644(param_1,param_2,local_b0.x,local_b0.y,local_a8);
        if (iVar15 == -1) goto LAB_0002ac18;
        if ((local_a8[0] & 0x40) != 0) {
          FUN_00026484(param_1,param_2,iVar15,0x203);
          goto LAB_0002ac18;
        }
        piVar5 = FUN_00023388(param_1,param_2,iVar15);
        if (((*(undefined4 **)(*param_1 + 4) == (undefined4 *)0x0) ||
            (puVar18 = (undefined4 *)**(undefined4 **)(*param_1 + 4), puVar18 == (undefined4 *)0x0))
           || (puVar18 = (undefined4 *)*puVar18, puVar18 == (undefined4 *)0x0)) {
          piVar17 = (int *)0x0;
        }
        else {
          piVar17 = (int *)*puVar18;
        }
        if ((piVar5 != piVar17) ||
           (iVar15 = FUN_0002c9e4(param_2,L"clock",L"Date & Time"), iVar15 != 0)) goto LAB_0002ac18;
        pwVar14 = L"clock.cpl";
        pwVar11 = L"ctlpnl";
        goto LAB_0002aa0c;
      }
      if (param_3 == 0x205) {
LAB_0002a7a4:
        local_b0.x = (uint)param_5 & 0xffff;
        local_b0.y = (uint)param_5 >> 0x10;
        SetFocus(param_2);
        FUN_0002249c((int)param_1);
        DAT_00035534 = FUN_00024644(param_1,param_2,local_b0.x,local_b0.y,local_a8);
        if ((DAT_00035534 == -1) || (DAT_00035534 == 0)) {
          hMenu = LoadMenuW(DAT_00035560,(LPCWSTR)0x6d);
          pHVar10 = GetSubMenu(hMenu,0);
          ClientToScreen(param_2,&local_b0);
          param_1[0x1e] = 1;
          TrackPopupMenuEx(pHVar10,0x20,local_b0.x - 4,local_b0.y,param_2,(LPTPMPARAMS)0x0);
          param_1[0x1e] = 0;
        }
        else {
          if ((*(int *)(*param_1 + 8) + -3 <= DAT_00035534) ||
             (piVar5 = FUN_00023388(param_1,param_2,DAT_00035534), piVar5 == (int *)0x0))
          goto LAB_0002ac18;
          pHVar8 = *(HWND *)(piVar5[2] + 0x1c);
          BVar7 = IsWindowEnabled(pHVar8);
          if (BVar7 == 0) goto LAB_0002ac18;
          pHVar8 = (HWND)((uint)pHVar8 | 1);
          SetForegroundWindow(pHVar8);
          ClientToScreen(param_2,&local_b0);
          SetForegroundWindow(param_2);
          hMenu = LoadMenuW(DAT_00035560,(LPCWSTR)0x6e);
          pHVar10 = GetSubMenu(hMenu,0);
          param_1[0x1e] = 1;
          TrackPopupMenuEx(pHVar10,0x20,local_b0.x - 4,local_b0.y,param_2,(LPTPMPARAMS)0x0);
          param_1[0x1e] = 0;
          SetForegroundWindow(pHVar8);
        }
        DestroyMenu(hMenu);
        goto LAB_0002ac18;
      }
      if (param_3 == 0x218) {
        memcpy(&tStack_38,L"MSGSBlObj",0x14);
        pHVar8 = FindWindowW((LPCWSTR)&tStack_38,(LPCWSTR)0x0);
        if (pHVar8 == (HWND)0x0) goto LAB_0002ac18;
        pHVar8 = FindWindowW((LPCWSTR)&tStack_38,(LPCWSTR)0x0);
        UVar12 = 0x218;
LAB_0002a794:
        PostMessageW(pHVar8,UVar12,(WPARAM)param_4,(LPARAM)param_5);
        goto LAB_0002ac18;
      }
    }
    else {
      if (param_3 == 0x403) {
        FUN_0002562c(param_1,param_2);
        goto LAB_0002ac18;
      }
      if (param_3 == 0x404) {
        if (param_1[8] != 0) {
          FUN_0002e350(param_1[8],param_2,(int)param_4,(int)param_5);
        }
        goto LAB_0002ac18;
      }
      if (param_3 == 0x40a) {
        uVar3 = 1;
        param_1[0x2a] = (int)param_4;
        param_1[0x29] = (uint)(param_4 != (HDC)0x0);
        goto LAB_00029000;
      }
      if (param_3 == 0x40b) {
        param_1[0x2a] = 0;
        param_1[0x29] = 0;
LAB_00029214:
        FUN_00033770(local_24);
        return 1;
      }
      if (param_3 == 0x432) goto LAB_0002ac18;
      if (param_3 == 0x43c) {
        if (param_4 == (HDC)0x0) {
          if (param_1[0x14] != 0) {
            SetTimer((HWND)param_1[2],6,500,(TIMERPROC)0x0);
          }
        }
        else {
          KillTimer((HWND)param_1[2],6);
        }
        BVar7 = IsWindow((HWND)param_5);
        if (BVar7 != 0) {
          iVar15 = FUN_00021918(param_1,(int)param_5);
          uVar3 = 1;
          if (iVar15 == 0) {
            FUN_00025954(param_1,(HWND)param_5);
            iVar15 = FUN_00021918(param_1,(int)param_5);
            if (iVar15 == 0) goto LAB_00029000;
          }
          *(bool *)(*(int *)(iVar15 + 8) + 0x229) = param_4 != (HDC)0x0;
          iVar20 = FUN_00024e98((HWND)param_5);
          if (iVar20 != 0) {
            FUN_000227fc((int)param_1,*(int *)(iVar15 + 8));
          }
          goto LAB_00029000;
        }
        goto LAB_0002ac18;
      }
      if (param_3 == 0x466) {
        if (param_5 != (HMENU)0x0) {
          FUN_0002f024();
        }
        LocalFree(param_5);
        FUN_0002f024();
        goto LAB_0002ac18;
      }
    }
    goto LAB_0002aa98;
  }
  if (param_3 == 0x113) {
    if (param_4 == (HDC)0x2a) {
      FUN_0002562c(param_1,param_2);
    }
    else if (param_4 == (HDC)0x6) {
      FUN_00025214((int)param_1);
    }
    else if (param_4 == (HDC)0x5) {
      FUN_00025274((int)param_1);
    }
    else if (param_4 == (HDC)0x2b) {
      FUN_0001d0fc();
    }
    goto LAB_0002ac18;
  }
  if (param_3 < 0x2d) {
    if (param_3 == 0x2c) {
      if (param_1[0xd] != 0) {
        uVar3 = FUN_00031208((int)param_5);
        goto LAB_00029000;
      }
      goto LAB_0002ac18;
    }
    if (param_3 < 0x11) {
      if (param_3 == 0x10) {
        DestroyWindow(param_2);
        goto LAB_0002ac18;
      }
      if (param_3 == 1) {
        ImmAssociateContext(param_2,(HIMC)0x0);
        goto LAB_0002ac18;
      }
      if (param_3 == 2) {
        FUN_0002546c(param_1);
        PostQuitMessage(0);
        goto LAB_0002ac18;
      }
      if (6 < param_3) {
        if (param_3 < 9) {
          piVar5 = FUN_00023388(param_1,param_2,0);
          iVar15 = 0;
          if (piVar5 != (int *)0x0) {
            iVar15 = piVar5[2];
          }
          InvalidateRect(param_2,(RECT *)(iVar15 + 0xc),0);
          if (param_3 == 8) {
            FUN_00022568((int)param_1,param_2);
          }
          UpdateWindow(param_2);
          goto LAB_0002ac18;
        }
        if (param_3 == 0xf) {
          pHVar4 = BeginPaint(param_2,&tStack_78);
          FUN_00027ab4(param_1,param_2,pHVar4,&tStack_78.rcPaint);
          EndPaint(param_2,&tStack_78);
          goto LAB_0002ac18;
        }
      }
    }
    else {
      if (param_3 == 0x14) {
        if (param_1[0x13] != 0) {
          GetClientRect(param_2,&tStack_a0);
          pHVar6 = GetSysColorBrush(0x4000000f);
          FillRect(param_4,&tStack_a0,pHVar6);
          goto LAB_00029214;
        }
        GetClipBox(param_4,&tStack_a0);
        hrgn = CreateRectRgnIndirect(&tStack_a0);
        SelectClipRgn(param_4,hrgn);
        DeleteObject(hrgn);
        p_Var19 = (LPCRITICAL_SECTION)(*param_1 + 0xc);
        EnterCriticalSection(p_Var19);
        EnterCriticalSection(p_Var19);
        LeaveCriticalSection(p_Var19);
        iVar20 = *(int *)*param_1;
        for (iVar15 = iVar20; iVar15 != 0; iVar15 = *(int *)(iVar15 + 4)) {
          if ((*(uint *)(*(int *)(iVar15 + 8) + 8) & 0x40) != 0) goto joined_r0x000292d0;
        }
        piVar5 = (int *)((int *)*param_1)[1];
        if (((piVar5 == (int *)0x0) || (piVar5 = (int *)*piVar5, piVar5 == (int *)0x0)) ||
           (piVar5 = (int *)*piVar5, piVar5 == (int *)0x0)) {
          iVar15 = 0;
        }
        else {
          iVar15 = *piVar5;
        }
joined_r0x000292d0:
        for (; iVar20 != iVar15; iVar20 = *(int *)(iVar20 + 4)) {
          BVar7 = IntersectRect(&tStack_38,(RECT *)(*(int *)(iVar20 + 8) + 0xc),&tStack_a0);
          if (BVar7 != 0) {
            iVar16 = *(int *)(iVar20 + 8);
            ExcludeClipRect(param_4,*(int *)(iVar16 + 0xc),*(int *)(iVar16 + 0x10),
                            *(int *)(iVar16 + 0x14),*(int *)(iVar16 + 0x18));
          }
        }
        if ((*(int **)(*param_1 + 4) == (int *)0x0) ||
           (piVar5 = (int *)**(int **)(*param_1 + 4), piVar5 == (int *)0x0)) {
          iVar15 = 0;
        }
        else {
          iVar15 = *piVar5;
        }
        BVar7 = IntersectRect(&tStack_38,(RECT *)(*(int *)(iVar15 + 8) + 0xc),&tStack_a0);
        if (BVar7 != 0) {
          iVar15 = *(int *)(iVar15 + 8);
          ExcludeClipRect(param_4,*(int *)(iVar15 + 0xc),*(int *)(iVar15 + 0x10),
                          *(int *)(iVar15 + 0x14),*(int *)(iVar15 + 0x18));
        }
        iVar15 = 0;
        if (*(int **)(*param_1 + 4) != (int *)0x0) {
          iVar15 = **(int **)(*param_1 + 4);
        }
        if ((param_1[0x22] != 0) &&
           (BVar7 = IntersectRect(&tStack_38,(RECT *)(*(int *)(iVar15 + 8) + 0xc),&tStack_a0),
           BVar7 != 0)) {
          iVar20 = *(int *)(iVar15 + 8);
          ExcludeClipRect(param_4,*(int *)(iVar20 + 0xc),*(int *)(iVar20 + 0x10),
                          *(int *)(iVar20 + 0x14),*(int *)(iVar20 + 0x18));
        }
        if (param_1[0xf] == 0) {
          piVar5 = (int *)*param_1;
          for (iVar20 = *piVar5; iVar20 != 0; iVar20 = *(int *)(iVar20 + 4)) {
            if ((*(uint *)(*(int *)(iVar20 + 8) + 8) & 0x40) != 0) goto LAB_0002944c;
          }
          if ((((int *)piVar5[1] == (int *)0x0) ||
              (piVar17 = *(int **)piVar5[1], piVar17 == (int *)0x0)) ||
             (piVar17 = (int *)*piVar17, piVar17 == (int *)0x0)) {
            iVar20 = 0;
          }
          else {
            iVar20 = *piVar17;
          }
LAB_0002944c:
          if ((((undefined4 *)piVar5[1] == (undefined4 *)0x0) ||
              (puVar18 = *(undefined4 **)piVar5[1], puVar18 == (undefined4 *)0x0)) ||
             (piVar5 = (int *)*puVar18, piVar5 == (int *)0x0)) {
            iVar16 = 0;
          }
          else {
            iVar16 = *piVar5;
          }
          if (iVar20 != iVar16) goto LAB_00029484;
        }
        else {
LAB_00029484:
          FUN_00023490(param_1,param_2,&local_88);
          BVar7 = IntersectRect(&tStack_38,(RECT *)(*(int *)(iVar15 + 8) + 0xc),&tStack_a0);
          if (BVar7 != 0) {
            ExcludeClipRect(param_4,local_88.left,local_88.top,local_88.right,local_88.bottom);
          }
        }
        p_Var19 = (LPCRITICAL_SECTION)(*param_1 + 0xc);
        EnterCriticalSection(p_Var19);
        LeaveCriticalSection(p_Var19);
        LeaveCriticalSection(p_Var19);
        pHVar6 = GetSysColorBrush(0x4000000f);
        FillRect(param_4,&tStack_a0,pHVar6);
        uVar3 = 1;
        if (tStack_a0.top == 0) {
          tStack_a0.bottom = 1;
          pHVar6 = GetSysColorBrush(0x40000016);
          FillRect(param_4,&tStack_a0,pHVar6);
        }
        SelectClipRgn(param_4,(HRGN)0x0);
        goto LAB_00029000;
      }
      if (param_3 == 0x1a) {
        FUN_00027304(param_1,param_2,0x1a,(int)param_4,(int)param_5);
        goto LAB_0002ac18;
      }
      if (param_3 == 0x2b) {
        if (param_1[0xd] != 0) {
          uVar3 = FUN_0003141c((int)param_5);
          goto LAB_00029000;
        }
        goto LAB_0002ac18;
      }
    }
LAB_0002aa98:
    if (param_3 == param_1[0x27]) {
      uVar3 = FUN_00024f34((int)param_1,(int)param_4,(LPARAM)param_5);
      goto LAB_00029000;
    }
  }
  else {
    if (param_3 < 0x105) {
      if (param_3 != 0x104) {
        if (param_3 == 0x4a) {
          uVar3 = 1;
          bVar1 = true;
          if ((((param_5 == (HMENU)0x0) || (iVar15 = param_5[2].unused, iVar15 == 0)) ||
              ((param_5[1].unused != 0x98 && (param_5[1].unused != 4)))) ||
             ((uVar13 = param_5->unused, 2 < uVar13 && ((uVar13 < 4 || (iVar15 = 0, 0x10 < uVar13)))
              ))) goto LAB_0002ac18;
          if (uVar13 == 0) {
            iVar20 = FUN_00023e08(param_1,param_1[2],iVar15);
            if ((iVar20 != -1) ||
               (iVar15 = FUN_00025d64(param_1,(HWND)param_1[2],iVar15), iVar15 == 0))
            goto LAB_0002ac18;
            bVar1 = false;
          }
          else {
            if (uVar13 == 1) {
              iVar20 = FUN_00023e08(param_1,param_1[2],iVar15);
              if ((iVar20 < 0) ||
                 (uVar13 = FUN_00023f44(param_1,param_1[2],iVar15,iVar20), uVar13 == 0))
              goto LAB_0002ac18;
              goto LAB_00029000;
            }
            if (uVar13 == 2) {
              iVar15 = FUN_00023e08(param_1,param_1[2],iVar15);
              if (-1 < iVar15) {
                FUN_00025bb4(param_1,(HWND)param_1[2],iVar15,1);
                goto LAB_00029000;
              }
              goto LAB_0002ac18;
            }
            if (uVar13 != 4) {
              if (uVar13 == 8) {
                bVar1 = false;
              }
              else if (uVar13 != 0x10) goto LAB_0002ac18;
            }
            iVar15 = FUN_0002f024();
            if (iVar15 == 0) goto LAB_0002ac18;
          }
          if (bVar1) {
            FUN_0002400c(param_1,(HWND)param_1[2]);
          }
          goto LAB_00029000;
        }
        if (param_3 == 0x4e) {
          if (param_5 == (HMENU)0x0) goto LAB_0002ac18;
          if ((param_1[3] == param_5->unused) && (param_5[2].unused == -0x212)) {
            BVar7 = GetCursorPos(&local_b0);
            if (BVar7 == 0) goto LAB_0002ac18;
            MapWindowPoints((HWND)0x0,(HWND)param_1[2],&local_b0,1);
            iVar15 = FUN_00024644(param_1,param_2,local_b0.x,local_b0.y,local_a8);
            if (iVar15 != -1) {
              piVar5 = FUN_00023388(param_1,param_2,iVar15);
              if (piVar5 == *(int **)*param_1) {
                UVar12 = 0x5278;
              }
              else {
                puVar18 = (undefined4 *)((undefined4 *)*param_1)[1];
                if ((puVar18 == (undefined4 *)0x0) || ((undefined4 *)*puVar18 == (undefined4 *)0x0))
                {
                  piVar17 = (int *)0x0;
                }
                else {
                  piVar17 = *(int **)*puVar18;
                }
                if (piVar5 == piVar17) {
                  UVar12 = 0x5279;
                }
                else {
                  piVar17 = (int *)0x0;
                  if (puVar18 != (undefined4 *)0x0) {
                    piVar17 = (int *)*puVar18;
                  }
                  if (piVar5 != piVar17) {
                    if ((piVar5 != (int *)0x0) && (piVar5 = (int *)piVar5[2], piVar5 != (int *)0x0))
                    {
                      (**(code **)(*piVar5 + 8))(piVar5,param_5 + 4,0x50);
                    }
                    goto LAB_00029718;
                  }
                  UVar12 = 0x527e;
                }
              }
              LoadStringW(DAT_00035560,UVar12,(LPWSTR)(param_5 + 4),0x50);
            }
          }
LAB_00029718:
          if ((HWND)param_1[3] == (HWND)param_5->unused) {
            SetWindowPos((HWND)param_1[3],(HWND)0xffffffff,0,0,0,0,0x13);
          }
          goto LAB_0002ac18;
        }
        if (param_3 != 0x100) {
          if (param_3 != 0x101) goto LAB_0002aa98;
          goto LAB_000295ac;
        }
      }
      if ((param_4 == (HDC)0x5b) || (param_4 == (HDC)0x5c)) {
        DAT_00035614 = 1;
      }
      else {
        DAT_00035614 = 0;
      }
      if (param_4 < (HDC)0x46) {
        if (param_4 != (HDC)0x45) {
          if (param_4 == (HDC)0x8) {
LAB_00029a5c:
            SVar2 = GetKeyState(0x11);
            if ((CONCAT22(extraout_var_06,SVar2) == 0) ||
               (SVar2 = GetKeyState(0x12), CONCAT22(extraout_var_07,SVar2) == 0)) goto LAB_0002ac18;
          }
          else {
            if (param_4 != (HDC)0x9) {
              if (param_4 != (HDC)0xd) {
                if (param_4 == (HDC)0x1b) {
                  SVar2 = GetKeyState(0x11);
                  if (CONCAT22(extraout_var_03,SVar2) == 0) {
                    SVar2 = GetKeyState(0x12);
                    if (CONCAT22(extraout_var_04,SVar2) != 0) {
                      FUN_00027c14(param_1,param_2);
                    }
                    goto LAB_0002ac18;
                  }
                }
                else {
                  if (param_4 != (HDC)0x20) {
                    if (param_4 != (HDC)0x2e) {
                      if (param_4 != (HDC)0x43) goto LAB_00029b28;
                      SVar2 = GetKeyState(0x5b);
                      if ((CONCAT22(extraout_var,SVar2) == 0) &&
                         (SVar2 = GetKeyState(0x5c), CONCAT22(extraout_var_00,SVar2) == 0))
                      goto LAB_0002ac18;
                      if (param_1[0xd] != 0) {
                        FUN_00026618(param_1,param_2);
                      }
                      pwVar14 = (wchar_t *)0x0;
                      pwVar11 = L"control.exe";
                      goto LAB_0002aa0c;
                    }
                    goto LAB_00029a5c;
                  }
                  SVar2 = GetKeyState(0x5b);
                  if ((CONCAT22(extraout_var_01,SVar2) != 0) ||
                     (SVar2 = GetKeyState(0x5c), CONCAT22(extraout_var_02,SVar2) != 0))
                  goto LAB_00029d6c;
                }
              }
              goto LAB_00029d78;
            }
            SVar2 = GetKeyState(0x12);
            if (CONCAT22(extraout_var_05,SVar2) == 0) {
              pHVar8 = GetFocus();
              if (pHVar8 == (HWND)param_1[2]) {
                SetForegroundWindow(*(HWND *)(DAT_00035570 + 4));
              }
              goto LAB_0002ac18;
            }
          }
LAB_00029a7c:
          if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
            FUN_0002d0ec((undefined4 *)param_1[9]);
          }
          goto LAB_0002ac18;
        }
        SVar2 = GetKeyState(0x5b);
        if ((CONCAT22(extraout_var_08,SVar2) == 0) &&
           (SVar2 = GetKeyState(0x5c), CONCAT22(extraout_var_09,SVar2) == 0)) goto LAB_0002ac18;
        if (param_1[0xd] != 0) {
          FUN_00026618(param_1,param_2);
        }
        pwVar14 = (wchar_t *)0x0;
        pwVar11 = L"\\";
      }
      else {
        if (param_4 == (HDC)0x48) {
          SVar2 = GetKeyState(0x5b);
          if ((CONCAT22(extraout_var_23,SVar2) == 0) &&
             (SVar2 = GetKeyState(0x5c), CONCAT22(extraout_var_24,SVar2) == 0)) goto LAB_0002ac18;
LAB_00029d6c:
          if (param_1[0xd] == 0) goto LAB_0002ac18;
          goto LAB_00029d78;
        }
        if (param_4 == (HDC)0x49) {
          SVar2 = GetKeyState(0x5b);
          if ((CONCAT22(extraout_var_21,SVar2) == 0) &&
             (SVar2 = GetKeyState(0x5c), CONCAT22(extraout_var_22,SVar2) == 0)) goto LAB_0002ac18;
          if (param_1[0xd] != 0) {
            FUN_00026618(param_1,param_2);
          }
          UVar12 = 0x526d;
        }
        else {
          if (param_4 != (HDC)0x4b) {
            if (param_4 == (HDC)0x4d) {
              SVar2 = GetKeyState(0x5b);
              if (((CONCAT22(extraout_var_17,SVar2) != 0) ||
                  (SVar2 = GetKeyState(0x5c), CONCAT22(extraout_var_18,SVar2) != 0)) &&
                 (iVar15 = FUN_00024788(param_1), iVar15 != 0)) {
                FUN_00026904(param_1,param_2,0,1,(undefined4 *)0x0);
              }
              goto LAB_0002ac18;
            }
            if (param_4 == (HDC)0x52) {
              SVar2 = GetKeyState(0x5b);
              if ((CONCAT22(extraout_var_15,SVar2) != 0) ||
                 (SVar2 = GetKeyState(0x5c), CONCAT22(extraout_var_16,SVar2) != 0)) {
                if (param_1[0xd] != 0) {
                  FUN_00026618(param_1,param_2);
                }
                FUN_0002ef1c((int)param_1);
              }
              goto LAB_0002ac18;
            }
            if (param_4 == (HDC)0x70) {
              lpCommandLine = (LPWSTR)LoadStringW(DAT_00035560,0x5272,(LPWSTR)0x0,0);
              CreateProcessW(L"\\windows\\peghelp.exe",lpCommandLine,(LPSECURITY_ATTRIBUTES)0x0,
                             (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                             (LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
              goto LAB_0002ac18;
            }
LAB_00029b28:
            iVar15 = FUN_0002f024();
            if (iVar15 == 0) {
              uVar3 = 0;
              SVar2 = GetKeyState(0x5b);
              if ((CONCAT22(extraout_var_10,SVar2) != 0) ||
                 (SVar2 = GetKeyState(0x5c), CONCAT22(extraout_var_11,SVar2) != 0)) {
                uVar3 = 0x40;
              }
              SVar2 = GetKeyState(0x12);
              if (CONCAT22(extraout_var_12,SVar2) != 0) {
                uVar3 = uVar3 | 0x20;
              }
              SVar2 = GetKeyState(0x11);
              if (CONCAT22(extraout_var_13,SVar2) != 0) {
                uVar3 = uVar3 | 8;
              }
              SVar2 = GetKeyState(0x10);
              if (CONCAT22(extraout_var_14,SVar2) != 0) {
                uVar3 = uVar3 | 4;
              }
              FUN_00024834(param_1,param_4,uVar3);
            }
            goto LAB_0002ac18;
          }
          SVar2 = GetKeyState(0x5b);
          if ((CONCAT22(extraout_var_19,SVar2) == 0) &&
             (SVar2 = GetKeyState(0x5c), CONCAT22(extraout_var_20,SVar2) == 0)) goto LAB_0002ac18;
          if (param_1[0xd] != 0) {
            FUN_00026618(param_1,param_2);
          }
          UVar12 = 0x526c;
        }
        pwVar14 = (wchar_t *)LoadStringW(DAT_00035560,UVar12,(LPWSTR)0x0,0);
        pwVar11 = L"ctlpnl";
      }
LAB_0002aa0c:
      FUN_0002c9e4(param_2,pwVar11,pwVar14);
      goto LAB_0002ac18;
    }
    if (param_3 == 0x105) {
LAB_000295ac:
      if ((param_4 < (HDC)0x5b) || ((HDC)0x5c < param_4)) {
        FUN_0002f024();
        goto LAB_0002ac18;
      }
      if (DAT_00035614 == 0) goto LAB_0002ac18;
      DAT_00035614 = 0;
LAB_00029d78:
      FUN_00026618(param_1,param_2);
      goto LAB_0002ac18;
    }
    if (param_3 == 0x10c) {
      if (param_4 == (HDC)0x2) {
        if (param_5 == (HMENU)0x0) {
          param_1[0x25] = param_1[0x24];
        }
        else {
          param_1[0x25] = (int)param_5;
        }
        FUN_00024fac(param_1,0);
      }
      goto LAB_0002ac18;
    }
    if (param_3 != 0x111) goto LAB_0002aa98;
    uVar3 = (uint)param_4 & 0xffff;
    if (uVar3 == 0x67) {
      if (param_1[8] != 0) {
        FUN_0002e1bc(param_1[8],param_2,(int)param_5,FUN_00028c20);
      }
      goto LAB_0002ac18;
    }
    if (uVar3 == 0xc82) {
      if ((DAT_00035534 == -1) ||
         (piVar5 = FUN_00023388(param_1,param_2,DAT_00035534), piVar5 == (int *)0x0))
      goto LAB_0002ac18;
      param_5 = (HMENU)0x0;
      pHVar8 = *(HWND *)(piVar5[2] + 0x1c);
      param_4 = (HDC)0x0;
      UVar12 = 0x10;
      goto LAB_0002a794;
    }
    if (uVar3 == 0xc83) {
      if (((uint)param_5 & 0xffff) == 0) {
        if ((*(int **)(*param_1 + 4) == (int *)0x0) ||
           (piVar5 = (int *)**(int **)(*param_1 + 4), piVar5 == (int *)0x0)) {
          iVar15 = 0;
        }
        else {
          iVar15 = *piVar5;
        }
        *(uint *)(*(int *)(iVar15 + 8) + 8) = *(uint *)(*(int *)(iVar15 + 8) + 8) & 0xfffffffb;
        *(uint *)(*(int *)(iVar15 + 8) + 8) = *(uint *)(*(int *)(iVar15 + 8) + 8) | 0x28;
        InvalidateRect(param_2,(RECT *)(*(int *)(iVar15 + 8) + 0xc),0);
        UpdateWindow(param_2);
      }
      FUN_00026904(param_1,param_2,(uint)param_5 & 0xffff,(uint)param_5 >> 0x10,(undefined4 *)0x0);
      goto LAB_0002ac18;
    }
    if (uVar3 == 0xce4) {
      FUN_00028eb8();
      goto LAB_0002ac18;
    }
    if (uVar3 == 0xce5) {
      FUN_000310fc();
      goto LAB_0002ac18;
    }
    if (uVar3 == 0xce6) goto LAB_00029a7c;
    if (uVar3 == 0xce7) {
      FUN_000252fc(param_1);
      goto LAB_0002ac18;
    }
    if (((uVar3 == 0) || (iVar15 = FUN_00025010(param_1,param_2,(uint)param_4), iVar15 != 0)) ||
       (iVar15 = FUN_00031ca0(param_2,(uint)param_4), iVar15 != 0)) goto LAB_0002ac18;
    param_3 = 0x111;
  }
  uVar3 = DefWindowProcW(param_2,param_3,(WPARAM)param_4,(LPARAM)param_5);
LAB_00029000:
  FUN_00033770(local_24);
  return uVar3;
}



/* 0002ac50 FUN_0002ac50 */

/* Boundary evidence: original MIPS .pdata 0002ac50..0002ac97. Semantic name remains unreviewed. */

uint FUN_0002ac50(HWND param_1,UINT param_2,HDC param_3,HMENU param_4)

{
  uint uVar1;
  
  if (DAT_0003556c == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00028f90(DAT_0003556c,param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 0002ac98 FUN_0002ac98 */

/* Boundary evidence: original MIPS .pdata 0002ac98..0002adef. Semantic name remains unreviewed. */

undefined4 FUN_0002ac98(int *param_1,HINSTANCE param_2)

{
  ATOM AVar1;
  undefined2 extraout_var;
  int iVar2;
  LPDROPTARGET pDropTarget;
  UINT UVar3;
  undefined4 uVar4;
  WNDCLASSW local_38;
  
  if (DAT_0003556c == (int *)0x0) {
    DAT_0003556c = param_1;
  }
  FUN_0002cb3c();
  local_38.style = 8;
  local_38.cbWndExtra = 8;
  local_38.lpfnWndProc = FUN_0002ac50;
  local_38.cbClsExtra = 0;
  local_38.hIcon = (HICON)0x0;
  local_38.hInstance = param_2;
  local_38.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
  local_38.hbrBackground = GetStockObject(1);
  local_38.lpszMenuName = (LPCWSTR)0x0;
  local_38.lpszClassName = L"HHTaskBar";
  RegisterClassW(&local_38);
  local_38.hbrBackground = (HBRUSH)0x40000004;
  local_38.lpfnWndProc = FUN_00028c20;
  local_38.cbWndExtra = 0;
  local_38.lpszClassName = L"HHTaskBarTray";
  AVar1 = RegisterClassW(&local_38);
  uVar4 = 0;
  if (CONCAT22(extraout_var,AVar1) != 0) {
    param_1[0xb] = 0;
    iVar2 = FUN_00023910(param_1,param_2);
    uVar4 = 0;
    if (iVar2 != 0) {
      iVar2 = FUN_00027474(param_1,(HWND)0x0);
      param_1[2] = iVar2;
      pDropTarget = (LPDROPTARGET)FUN_00032610(iVar2,*param_1);
      if (pDropTarget != (LPDROPTARGET)0x0) {
        RegisterDragDrop((HWND)param_1[2],pDropTarget);
        (*pDropTarget->lpVtbl->Release)(pDropTarget);
      }
      UVar3 = RegisterWindowMessageW(L"SHELLHOOK");
      param_1[0x27] = UVar3;
      uVar4 = 1;
      if (param_1[2] == 0) {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}



/* 0002adf0 FUN_0002adf0 */

/* Boundary evidence: original MIPS .pdata 0002adf0..0002aebf. Semantic name remains unreviewed. */

int * FUN_0002adf0(undefined4 *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  
  if (param_2 == (int *)0x0) {
    param_2 = (int *)0x0;
  }
  else if (param_3 == 0) {
    param_2 = FUN_000159dc(param_1,param_2);
  }
  else if (*(int *)(param_3 + 4) == 0) {
    param_2 = FUN_00021480(param_1,param_2);
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    param_2[1] = 0;
    *param_2 = 0;
    puVar1 = *(undefined4 **)(param_3 + 4);
    *param_2 = param_3;
    param_2[1] = *(int *)(param_3 + 4);
    *(int **)(param_3 + 4) = param_2;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = param_2;
    }
    param_1[2] = param_1[2] + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  return param_2;
}



/* 0002aec0 FUN_0002aec0 */

/* Boundary evidence: original MIPS .pdata 0002aec0..0002af0f. Semantic name remains unreviewed. */

wchar_t * FUN_0002aec0(int param_1,wchar_t *param_2)

{
  wchar_t *pwVar1;
  
  pwVar1 = (wchar_t *)0x0;
  if ((param_1 != 0) && (param_2 != (wchar_t *)0x0)) {
    param_2[8] = L'\0';
    _snwprintf(param_2,8,L"%08X",param_1);
    pwVar1 = param_2;
  }
  return pwVar1;
}



/* 0002af10 FUN_0002af10 */

/* Boundary evidence: original MIPS .pdata 0002af10..0002af7f. Semantic name remains unreviewed. */

ulong FUN_0002af10(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  ulong uVar2;
  size_t local_18;
  wchar_t *pwStack_14;
  
  uVar2 = 0;
  if (((param_1 != (STRSAFE_PCNZWCH)0x0) &&
      (HVar1 = StringCchLengthW(param_1,9,&local_18), -1 < HVar1)) && (local_18 == 8)) {
    uVar2 = wcstoul(param_1,&pwStack_14,0x10);
  }
  return uVar2;
}



/* 0002af80 FUN_0002af80 */

/* Boundary evidence: original MIPS .pdata 0002af80..0002b30b. Semantic name remains unreviewed. */

undefined4 FUN_0002af80(uint param_1)

{
  int *hMem;
  int iVar1;
  LSTATUS LVar2;
  LPCWSTR pszSource;
  HRESULT HVar3;
  uint uVar4;
  uint *puVar5;
  LPCRITICAL_SECTION p_Var6;
  int *piVar7;
  undefined4 uVar8;
  HKEY local_50;
  DWORD local_4c;
  HKEY local_48;
  DWORD local_44;
  wchar_t awStack_40 [8];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_00035518;
  uVar8 = 0;
  if ((param_1 == 0) ||
     (((DAT_00035628 != '\0' && ((param_1 == 0x411 || (param_1 == 0x412)))) ||
      (DAT_00035618 == (undefined4 *)0x0)))) goto LAB_0002b2d4;
  p_Var6 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
  EnterCriticalSection(p_Var6);
  EnterCriticalSection(p_Var6);
  LeaveCriticalSection(p_Var6);
  piVar7 = (int *)DAT_00035618[1];
  if (piVar7 != (int *)0x0) {
    do {
      uVar4 = piVar7[2];
      if ((uVar4 & 0xffff) < (param_1 & 0xffff)) break;
      if ((param_1 & 0xffff) == (uVar4 & 0xffff)) {
        if (param_1 == uVar4) goto LAB_0002b2b8;
        if (uVar4 < param_1) break;
      }
      piVar7 = (int *)*piVar7;
    } while (piVar7 != (int *)0x0);
  }
  hMem = LocalAlloc(0,0x14);
  if (hMem != (int *)0x0) {
    uVar4 = 0;
    hMem[2] = param_1;
    puVar5 = &DAT_00012820;
    hMem[3] = 0;
    *(undefined1 *)(hMem + 4) = 0;
    do {
      if (param_1 == *puVar5) break;
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 1;
    } while ((int)uVar4 < 0xe);
    if (uVar4 < 0xe) {
      iVar1 = LoadStringW(DAT_00035560,uVar4 + 0x9000,(LPWSTR)0x0,0);
      hMem[3] = iVar1;
    }
    if (hMem[3] == 0) {
      local_48 = (HKEY)0x0;
      local_50 = (HKEY)0x0;
      local_30 = 0;
      _snwprintf(awStack_40,8,L"%08X",param_1);
      LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\CurrentControlSet\\Control\\Layouts",0,0,
                            &local_48);
      if ((LVar2 == 0) && (LVar2 = RegOpenKeyExW(local_48,awStack_40,0,0,&local_50), LVar2 == 0)) {
        local_44 = 0x208;
        pszSource = LocalAlloc(0,0x208);
        if (pszSource != (LPCWSTR)0x0) {
          LVar2 = RegQueryValueExW(local_50,L"Layout Display Name",(LPDWORD)0x0,&local_4c,
                                   (LPBYTE)pszSource,&local_44);
          if (((LVar2 != 0) || (local_4c != 1)) ||
             (HVar3 = SHLoadIndirectString(pszSource,pszSource,0x104,(void **)0x0), HVar3 < 0)) {
            local_44 = 0x208;
            LVar2 = RegQueryValueExW(local_50,L"Layout Text",(LPDWORD)0x0,&local_4c,
                                     (LPBYTE)pszSource,&local_44);
            if ((LVar2 != 0) || (local_4c != 1)) {
              LocalFree(pszSource);
              goto LAB_0002b240;
            }
          }
          hMem[3] = (int)pszSource;
          *(undefined1 *)(hMem + 4) = 1;
        }
      }
LAB_0002b240:
      if (local_50 != (HKEY)0x0) {
        RegCloseKey(local_50);
      }
      if (local_48 != (HKEY)0x0) {
        RegCloseKey(local_48);
      }
    }
    if (hMem[3] == 0) {
      LocalFree(hMem);
    }
    else {
      if (piVar7 == (int *)0x0) {
        FUN_000159dc(DAT_00035618,hMem);
      }
      else {
        FUN_0002adf0(DAT_00035618,hMem,(int)piVar7);
      }
      uVar8 = 1;
    }
  }
LAB_0002b2b8:
  p_Var6 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
  EnterCriticalSection(p_Var6);
  LeaveCriticalSection(p_Var6);
  LeaveCriticalSection(p_Var6);
LAB_0002b2d4:
  FUN_00033770(local_2c);
  return uVar8;
}



/* 0002b30c FUN_0002b30c */

undefined4 FUN_0002b30c(void)

{
  return DAT_0003561c;
}



/* 0002b318 FUN_0002b318 */

/* Boundary evidence: original MIPS .pdata 0002b318..0002b3cb. Semantic name remains unreviewed. */

undefined4 FUN_0002b318(void)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (DAT_00035618 != (int *)0x0) {
    p_Var2 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
    EnterCriticalSection(p_Var2);
    EnterCriticalSection(p_Var2);
    LeaveCriticalSection(p_Var2);
    iVar1 = *DAT_00035618;
    if (iVar1 != 0) {
      do {
        if (DAT_0003561c == *(int *)(iVar1 + 8)) break;
        iVar1 = *(int *)(iVar1 + 4);
      } while (iVar1 != 0);
      if (iVar1 != 0) {
        uVar3 = *(undefined4 *)(iVar1 + 0xc);
      }
    }
    p_Var2 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
    EnterCriticalSection(p_Var2);
    LeaveCriticalSection(p_Var2);
    LeaveCriticalSection(p_Var2);
  }
  return uVar3;
}



/* 0002b3cc FUN_0002b3cc */

/* Boundary evidence: original MIPS .pdata 0002b3cc..0002b45b. Semantic name remains unreviewed. */

bool FUN_0002b3cc(void)

{
  LPCRITICAL_SECTION p_Var1;
  bool bVar2;
  
  bVar2 = false;
  if (DAT_00035618 != 0) {
    p_Var1 = (LPCRITICAL_SECTION)(DAT_00035618 + 0xc);
    EnterCriticalSection(p_Var1);
    EnterCriticalSection(p_Var1);
    LeaveCriticalSection(p_Var1);
    bVar2 = 1 < *(int *)(DAT_00035618 + 8);
    p_Var1 = (LPCRITICAL_SECTION)(DAT_00035618 + 0xc);
    EnterCriticalSection(p_Var1);
    LeaveCriticalSection(p_Var1);
    LeaveCriticalSection(p_Var1);
  }
  return bVar2;
}



/* 0002b45c FUN_0002b45c */

/* Boundary evidence: original MIPS .pdata 0002b45c..0002b6d7. Semantic name remains unreviewed. */

UINT FUN_0002b45c(HWND param_1,int *param_2)

{
  int iVar1;
  HMENU hMenu;
  wchar_t *pwVar2;
  HRESULT HVar3;
  BOOL BVar4;
  LPCWSTR lpNewItem;
  LPCRITICAL_SECTION p_Var5;
  int iVar6;
  UINT UVar7;
  uint uVar8;
  short sVar9;
  tagPOINT local_248;
  int local_240;
  int local_23c;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00035518;
  sVar9 = 0;
  UVar7 = 0;
  if (((param_1 != (HWND)0x0) && (param_2 != (int *)0x0)) && (DAT_00035618 != (int *)0x0)) {
    p_Var5 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
    EnterCriticalSection(p_Var5);
    EnterCriticalSection(p_Var5);
    LeaveCriticalSection(p_Var5);
    hMenu = CreatePopupMenu();
    if (hMenu != (HMENU)0x0) {
      iVar6 = *DAT_00035618;
      do {
        do {
          iVar1 = iVar6;
          if (iVar1 == 0) {
            CheckMenuItem(hMenu,DAT_0003561c,8);
            local_248.x = *param_2;
            local_248.y = param_2[1];
            local_240 = param_2[2];
            local_23c = param_2[3];
            MapWindowPoints(param_1,(HWND)0x0,&local_248,2);
            uVar8 = GetWindowLongW(param_1,-0x14);
            iVar6 = local_248.x;
            if ((uVar8 & 0x400000) == 0) {
              iVar6 = local_240;
            }
            UVar7 = TrackPopupMenuEx(hMenu,0x128,iVar6,local_248.y,param_1,(LPTPMPARAMS)0x0);
            if (DAT_0003561c == UVar7) {
              UVar7 = 0;
            }
            goto LAB_0002b66c;
          }
          iVar6 = 0;
          if (iVar1 != 0) {
            iVar6 = *(int *)(iVar1 + 4);
          }
        } while (*(wchar_t **)(iVar1 + 0xc) == (wchar_t *)0x0);
        pwVar2 = wcschr(*(wchar_t **)(iVar1 + 0xc),L'$');
        if (pwVar2 == (wchar_t *)0x0) {
LAB_0002b5b4:
          lpNewItem = *(LPCWSTR *)(iVar1 + 0xc);
        }
        else {
          uVar8 = (int)pwVar2 - (int)*(STRSAFE_LPCWSTR *)(iVar1 + 0xc) >> 1;
          if ((0x104 < uVar8) ||
             (HVar3 = StringCchCopyW(awStack_238,0x104,*(STRSAFE_LPCWSTR *)(iVar1 + 0xc)), HVar3 < 0
             )) goto LAB_0002b5b4;
          lpNewItem = awStack_238;
          if ((sVar9 == *(short *)(iVar1 + 8)) ||
             ((iVar6 != 0 && (*(short *)(iVar6 + 8) == *(short *)(iVar1 + 8))))) {
            awStack_238[uVar8] = L'-';
          }
          else {
            awStack_238[uVar8] = L'\0';
            sVar9 = *(short *)(iVar1 + 8);
          }
        }
        BVar4 = AppendMenuW(hMenu,0,*(UINT_PTR *)(iVar1 + 8),lpNewItem);
      } while (BVar4 != 0);
    }
LAB_0002b66c:
    p_Var5 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
    EnterCriticalSection(p_Var5);
    LeaveCriticalSection(p_Var5);
    LeaveCriticalSection(p_Var5);
    if (hMenu != (HMENU)0x0) {
      DestroyMenu(hMenu);
    }
  }
  FUN_00033770(local_30);
  return UVar7;
}



/* 0002b6d8 FUN_0002b6d8 */

/* Boundary evidence: original MIPS .pdata 0002b6d8..0002b803. Semantic name remains unreviewed. */

undefined4 FUN_0002b6d8(uint param_1)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_1 == DAT_0003561c) {
    return 0;
  }
  if (DAT_00035618 == (int *)0x0) {
    return 0;
  }
  p_Var2 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
  EnterCriticalSection(p_Var2);
  EnterCriticalSection(p_Var2);
  LeaveCriticalSection(p_Var2);
  iVar1 = *DAT_00035618;
  if (iVar1 == 0) {
LAB_0002b764:
    iVar1 = FUN_0002af80(param_1);
    if (iVar1 == 0) goto LAB_0002b7c0;
  }
  else {
    do {
      if (param_1 == *(uint *)(iVar1 + 8)) break;
      iVar1 = *(int *)(iVar1 + 4);
    } while (iVar1 != 0);
    if (iVar1 == 0) goto LAB_0002b764;
  }
  uVar3 = 1;
  DAT_0003561c = param_1;
  iVar1 = GetLocaleInfoW(param_1 & 0xffff,3,&DAT_00035620,4);
  if (iVar1 == 0) {
    DAT_00035620 = 0;
  }
  else {
    DAT_00035624 = 0;
  }
LAB_0002b7c0:
  p_Var2 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
  EnterCriticalSection(p_Var2);
  LeaveCriticalSection(p_Var2);
  LeaveCriticalSection(p_Var2);
  return uVar3;
}



/* 0002b804 FUN_0002b804 */

/* Boundary evidence: original MIPS .pdata 0002b804..0002b977. Semantic name remains unreviewed. */

undefined4 FUN_0002b804(int param_1,wchar_t *param_2)

{
  LSTATUS LVar1;
  wchar_t *pwVar2;
  int iVar3;
  undefined4 uVar4;
  HKEY local_250;
  HKEY local_24c;
  DWORD local_248;
  DWORD local_244;
  wchar_t awStack_240 [12];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_00035518;
  uVar4 = 0;
  local_250 = (HKEY)0x0;
  local_24c = (HKEY)0x0;
  if ((param_1 != 0) && (param_2 != (wchar_t *)0x0)) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\CurrentControlSet\\Control\\Layouts",0,0,
                          &local_250);
    if ((LVar1 == 0) && (pwVar2 = FUN_0002aec0(param_1,awStack_240), pwVar2 != (wchar_t *)0x0)) {
      LVar1 = RegOpenKeyExW(local_250,awStack_240,0,0,&local_24c);
      if (LVar1 == 0) {
        local_248 = 0x208;
        LVar1 = RegQueryValueExW(local_24c,L"Ime File",(LPDWORD)0x0,&local_244,(LPBYTE)awStack_228,
                                 &local_248);
        if (((LVar1 == 0) && (local_244 == 1)) && (iVar3 = wcscmp(awStack_228,param_2), iVar3 == 0))
        {
          uVar4 = 1;
        }
      }
    }
    if (local_250 != (HKEY)0x0) {
      RegCloseKey(local_250);
    }
    if (local_24c != (HKEY)0x0) {
      RegCloseKey(local_24c);
    }
  }
  FUN_00033770(local_20);
  return uVar4;
}



/* 0002b978 FUN_0002b978 */

/* Boundary evidence: original MIPS .pdata 0002b978..0002b9f7. Semantic name remains unreviewed. */

undefined4 *
FUN_0002b978(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  FUN_000302d4(param_1,0,0x140,param_2,param_3,param_4,param_5,param_6,L"",4,0x405);
  *param_1 = &PTR_FUN_00012864;
  param_1[0x8c] = 0;
  return param_1;
}



/* 0002b9f8 FUN_0002b9f8 */

/* Boundary evidence: original MIPS .pdata 0002b9f8..0002ba3f. Semantic name remains unreviewed. */

void FUN_0002b9f8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00012864;
  if ((HGDIOBJ)param_1[0x8c] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0x8c]);
    param_1[0x8c] = 0;
  }
  FUN_00030344(param_1);
  return;
}



/* 0002ba40 FUN_0002ba40 */

/* Boundary evidence: original MIPS .pdata 0002ba40..0002bbb3. Semantic name remains unreviewed. */

undefined4 FUN_0002ba40(int param_1,HWND param_2)

{
  HDC hdc;
  HGDIOBJ h;
  HFONT pHVar1;
  size_t cchString;
  undefined4 uVar2;
  HGDIOBJ h_00;
  tagSIZE local_80;
  LOGFONTW local_78;
  uint local_1c;
  
  local_1c = DAT_00035518;
  local_80.cx = 0;
  uVar2 = 0;
  h_00 = (HGDIOBJ)0x0;
  memset(&local_80.cy,0,4);
  hdc = GetDC(param_2);
  if (hdc != (HDC)0x0) {
    if ((*(int *)(param_1 + 0x230) == 0) && (h = GetStockObject(0xd), h != (HGDIOBJ)0x0)) {
      memset(&local_78,0,0x5c);
      GetObjectW(h,0x5c,&local_78);
      local_78.lfHeight = 0xc;
      local_78.lfWeight = 700;
      pHVar1 = CreateFontIndirectW(&local_78);
      *(HFONT *)(param_1 + 0x230) = pHVar1;
    }
    if (*(HGDIOBJ *)(param_1 + 0x230) != (HGDIOBJ)0x0) {
      h_00 = SelectObject(hdc,*(HGDIOBJ *)(param_1 + 0x230));
    }
    cchString = wcslen(&DAT_00035620);
    GetTextExtentExPointW(hdc,&DAT_00035620,cchString,100,(LPINT)0x0,(LPINT)0x0,&local_80);
    if (local_80.cx != 0) {
      local_80.cx = local_80.cx + 5;
    }
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0x14) - local_80.cx;
    if (h_00 != (HGDIOBJ)0x0) {
      SelectObject(hdc,h_00);
    }
    uVar2 = 1;
    ReleaseDC(param_2,hdc);
  }
  FUN_00033770(local_1c);
  return uVar2;
}



/* 0002bbb4 FUN_0002bbb4 */

/* Boundary evidence: original MIPS .pdata 0002bbb4..0002bd07. Semantic name remains unreviewed. */

undefined4 FUN_0002bbb4(int param_1,HWND param_2,HWND param_3,HDC param_4)

{
  HBRUSH h;
  HGDIOBJ h_00;
  DWORD color;
  COLORREF color_00;
  HGDIOBJ h_01;
  tagRECT local_30;
  
  h_01 = (HGDIOBJ)0x0;
  CopyRect(&local_30,(RECT *)(param_1 + 0xc));
  MapWindowPoints(param_2,param_3,(LPPOINT)&local_30,2);
  if (*(HGDIOBJ *)(param_1 + 0x230) != (HGDIOBJ)0x0) {
    h_01 = SelectObject(param_4,*(HGDIOBJ *)(param_1 + 0x230));
  }
  h = GetSysColorBrush(0x40000012);
  h_00 = SelectObject(param_4,h);
  RoundRect(param_4,local_30.left,local_30.top,local_30.right,local_30.bottom,2,2);
  if (h_00 != (HGDIOBJ)0x0) {
    SelectObject(param_4,h_00);
  }
  color = GetSysColor(0x40000005);
  color_00 = SetTextColor(param_4,color);
  DrawTextW(param_4,&DAT_00035620,-1,&local_30,5);
  if (color_00 != 0xffffffff) {
    SetTextColor(param_4,color_00);
  }
  if (h_01 != (HGDIOBJ)0x0) {
    SelectObject(param_4,h_01);
  }
  return 1;
}



/* 0002bd08 FUN_0002bd08 */

/* Boundary evidence: original MIPS .pdata 0002bd08..0002bd7b. Semantic name remains unreviewed. */

undefined4 FUN_0002bd08(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == -0x1ffef7fc) && (iVar1 = FUN_0002b804(-0x1ffef7fc,L"msimesp.dll"), iVar1 != 0))
     || ((param_1 == -0x1ffdf7fc && (iVar1 = FUN_0002b804(-0x1ffdf7fc,L"msimepy.dll"), iVar1 != 0)))
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0002bd7c FUN_0002bd7c */

/* Boundary evidence: original MIPS .pdata 0002bd7c..0002bdef. Semantic name remains unreviewed. */

undefined4 FUN_0002bd7c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == -0x1ffefbfc) && (iVar1 = FUN_0002b804(-0x1ffefbfc,L"msimeph.dll"), iVar1 != 0))
     || ((param_1 == -0x1ffdfbfc && (iVar1 = FUN_0002b804(-0x1ffdfbfc,L"msimecj.dll"), iVar1 != 0)))
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0002bdf0 FUN_0002bdf0 */

/* Boundary evidence: original MIPS .pdata 0002bdf0..0002bed7. Semantic name remains unreviewed. */

undefined4 FUN_0002bdf0(void)

{
  int *hMem;
  undefined4 *puVar1;
  LPCRITICAL_SECTION p_Var2;
  int *piVar3;
  
  if (DAT_00035618 != (undefined4 *)0x0) {
    p_Var2 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
    EnterCriticalSection(p_Var2);
    EnterCriticalSection(p_Var2);
    LeaveCriticalSection(p_Var2);
    hMem = (int *)*DAT_00035618;
    while (hMem != (int *)0x0) {
      piVar3 = (int *)0x0;
      if (hMem != (int *)0x0) {
        piVar3 = (int *)hMem[1];
      }
      FUN_00015a70(DAT_00035618,hMem);
      if ((char)hMem[4] != '\0') {
        LocalFree((HLOCAL)hMem[3]);
      }
      LocalFree(hMem);
      hMem = piVar3;
    }
    p_Var2 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
    EnterCriticalSection(p_Var2);
    LeaveCriticalSection(p_Var2);
    LeaveCriticalSection(p_Var2);
    puVar1 = DAT_00035618;
    if (DAT_00035618 != (undefined4 *)0x0) {
      DeleteCriticalSection((LPCRITICAL_SECTION)(DAT_00035618 + 3));
      operator_delete(puVar1);
    }
    DAT_00035618 = (undefined4 *)0x0;
  }
  return 0;
}



/* 0002bed8 FUN_0002bed8 */

/* Boundary evidence: original MIPS .pdata 0002bed8..0002bf23. Semantic name remains unreviewed. */

undefined4 * FUN_0002bed8(undefined4 *param_1,uint param_2)

{
  FUN_0002b9f8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0002bf24 FUN_0002bf24 */

/* Boundary evidence: original MIPS .pdata 0002bf24..0002c22b. Semantic name remains unreviewed. */

undefined4 * FUN_0002bf24(void)

{
  undefined4 *puVar1;
  LSTATUS LVar2;
  int iVar3;
  HKL pHVar4;
  uint uVar5;
  HKL *ppHVar6;
  int iVar7;
  LPCRITICAL_SECTION p_Var8;
  HKL pHVar9;
  HKL pHVar10;
  HKEY local_90;
  DWORD local_8c [3];
  HKL local_80 [16];
  wchar_t awStack_40 [10];
  uint local_2c;
  
  local_2c = DAT_00035518;
  DAT_0003561c = 0;
  pHVar9 = (HKL)0x0;
  pHVar10 = (HKL)0x0;
  local_90 = (HKEY)0x0;
  DAT_00035620 = 0;
  DAT_00035628 = 0;
  FUN_0002bdf0();
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 3));
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  DAT_00035618 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    p_Var8 = (LPCRITICAL_SECTION)(puVar1 + 3);
    EnterCriticalSection(p_Var8);
    EnterCriticalSection(p_Var8);
    LeaveCriticalSection(p_Var8);
    LVar2 = RegOpenKeyExW((HKEY)0x80000001,L"Keyboard Layout\\Preload",0,0,&local_90);
    if (LVar2 == 0) {
      local_8c[1] = 0x12;
      LVar2 = RegQueryValueExW(local_90,(LPCWSTR)0x0,(LPDWORD)0x0,local_8c,(LPBYTE)awStack_40,
                               local_8c + 1);
      if ((LVar2 == 0) && (local_8c[0] == 1)) {
        pHVar9 = (HKL)FUN_0002af10(awStack_40);
      }
    }
    iVar3 = GetKeyboardLayoutList(0xf,local_80);
    if (0 < iVar3) {
      ppHVar6 = local_80;
      iVar7 = iVar3;
      do {
        if ((((uint)*ppHVar6 & 0xff000000) == 0xe0000000) &&
           ((uVar5 = (uint)*ppHVar6 & 0xffff, uVar5 == 0x411 || (uVar5 == 0x412)))) {
          DAT_00035628 = 1;
        }
        iVar7 = iVar7 + -1;
        ppHVar6 = ppHVar6 + 1;
      } while (iVar7 != 0);
    }
    if (0 < iVar3) {
      ppHVar6 = local_80;
      do {
        pHVar4 = *ppHVar6;
        if (((uint)pHVar4 & 0xff000000) == 0xe0000000) {
          if ((((pHVar10 == (HKL)0x0) &&
               ((((((uint)pHVar9 & 0xff000000) != 0xe0000000 || (pHVar9 == pHVar4)) ||
                 ((iVar7 = FUN_0002bd08((int)pHVar9), iVar7 != 0 &&
                  (iVar7 = FUN_0002bd08((int)*ppHVar6), iVar7 != 0)))) ||
                ((iVar7 = FUN_0002bd7c((int)pHVar9), iVar7 != 0 &&
                 (iVar7 = FUN_0002bd7c((int)*ppHVar6), iVar7 != 0)))))) ||
              ((iVar7 = FUN_0002bd08((int)pHVar10), iVar7 != 0 &&
               (iVar7 = FUN_0002bd08((int)*ppHVar6), iVar7 != 0)))) ||
             ((iVar7 = FUN_0002bd7c((int)pHVar10), iVar7 != 0 &&
              (iVar7 = FUN_0002bd7c((int)*ppHVar6), iVar7 != 0)))) {
            pHVar4 = *ppHVar6;
            pHVar10 = pHVar4;
            goto LAB_0002c198;
          }
        }
        else {
LAB_0002c198:
          FUN_0002af80((uint)pHVar4);
        }
        iVar3 = iVar3 + -1;
        ppHVar6 = ppHVar6 + 1;
      } while (iVar3 != 0);
    }
    p_Var8 = (LPCRITICAL_SECTION)(DAT_00035618 + 3);
    EnterCriticalSection(p_Var8);
    LeaveCriticalSection(p_Var8);
    LeaveCriticalSection(p_Var8);
  }
  if (local_90 != (HKEY)0x0) {
    RegCloseKey(local_90);
  }
  puVar1 = DAT_00035618;
  FUN_00033770(local_2c);
  return puVar1;
}



/* 0002c22c FUN_0002c22c */

/* Boundary evidence: original MIPS .pdata 0002c22c..0002c36f. Semantic name remains unreviewed. */

undefined4 FUN_0002c22c(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_30;
  
  if ((param_2 != 0) && (0 < param_2 + -1)) {
    local_30 = 0;
    iVar4 = 0;
    do {
      iVar5 = iVar4 + 1;
      iVar7 = local_30;
      iVar8 = local_30;
      for (iVar6 = iVar5; iVar6 < param_2; iVar6 = iVar6 + 1) {
        iVar7 = iVar7 + 4;
        iVar1 = CompareStringW(0x400,1,*(PCNZWCH *)(iVar7 + param_1),-1,
                               *(PCNZWCH *)(iVar8 + param_1),-1);
        if (iVar1 == 1) {
          iVar8 = iVar7;
          iVar4 = iVar6;
        }
      }
      puVar2 = (undefined4 *)(iVar4 * 4 + DAT_00035630);
      uVar3 = *puVar2;
      *puVar2 = *(undefined4 *)(local_30 + DAT_00035630);
      puVar2 = (undefined4 *)(local_30 + DAT_00035630);
      local_30 = local_30 + 4;
      *puVar2 = uVar3;
      iVar4 = iVar5;
    } while (iVar5 < param_2 + -1);
  }
  return 1;
}



/* 0002c370 FUN_0002c370 */

/* Boundary evidence: original MIPS .pdata 0002c370..0002c417. Semantic name remains unreviewed. */

undefined4 FUN_0002c370(void *param_1)

{
  HLOCAL pvVar1;
  void *_Dst;
  
  if (DAT_0003562c < DAT_00035634) {
    pvVar1 = LocalAlloc(0,0x218);
    *(HLOCAL *)(DAT_0003562c * 4 + DAT_00035630) = pvVar1;
    _Dst = *(void **)(DAT_0003562c * 4 + DAT_00035630);
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_1,0x218);
      DAT_0003562c = DAT_0003562c + 1;
      return 1;
    }
  }
  return 0;
}



/* 0002c418 FUN_0002c418 */

/* Boundary evidence: original MIPS .pdata 0002c418..0002c497. Semantic name remains unreviewed. */

void FUN_0002c418(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_0003562c != 0) {
    iVar1 = 0;
    do {
      LocalFree(*(HLOCAL *)(iVar1 + (int)DAT_00035630));
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar2 < DAT_0003562c);
  }
  LocalFree(DAT_00035630);
  DAT_00035630 = (HLOCAL)0x0;
  return;
}



/* 0002c498 FUN_0002c498 */

/* Boundary evidence: original MIPS .pdata 0002c498..0002c6a7. Semantic name remains unreviewed. */

undefined4 FUN_0002c498(HMENU param_1,HINSTANCE param_2,int param_3)

{
  int iVar1;
  int iVar2;
  UINT uIDCheckItem;
  UINT UVar3;
  LPCWSTR lpNewItem;
  UINT uFlags;
  undefined4 local_e0;
  uint local_dc;
  undefined4 local_b8;
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00035518;
  uIDCheckItem = 0xffffffff;
  if (param_1 != (HMENU)0x0) {
    if (DAT_00035630 != (HLOCAL)0x0) {
      FUN_0002c418();
    }
    DAT_00035634 = 0;
    DAT_0003562c = 0;
    DAT_00035634 = FUN_000332f0(0);
    if ((DAT_00035634 != 0) &&
       (DAT_00035630 = LocalAlloc(0,DAT_00035634 << 2), DAT_00035630 != (HLOCAL)0x0)) {
      DAT_0003562c = 0;
      FUN_000332f0(FUN_0002c370);
      DAT_00035634 = DAT_0003562c;
      FUN_0002c22c((int)DAT_00035630,DAT_0003562c);
      FUN_00033370(&DAT_00035638);
      UVar3 = 0;
      if (DAT_00035634 != 0) {
        iVar2 = 0;
        do {
          lpNewItem = *(LPCWSTR *)(iVar2 + (int)DAT_00035630);
          iVar1 = memcmp(&DAT_00035638,lpNewItem + 0x104,0x10);
          if (iVar1 == 0) {
            uIDCheckItem = UVar3;
          }
          AppendMenuW(param_1,0,UVar3 + param_3,lpNewItem);
          UVar3 = UVar3 + 1;
          iVar2 = iVar2 + 4;
        } while (UVar3 < DAT_00035634);
      }
      AppendMenuW(param_1,0x800,0,(LPCWSTR)0x0);
      LoadStringW(param_2,0x527f,aWStack_b0,0x40);
      local_e0 = 0x30;
      local_b8 = 0;
      uFlags = 0;
      iVar2 = FUN_000334f0(&local_e0);
      if ((iVar2 != 0) && ((local_dc & 1) == 0)) {
        uFlags = 1;
      }
      AppendMenuW(param_1,uFlags,UVar3 + param_3,aWStack_b0);
      if (uIDCheckItem != 0xffffffff) {
        CheckMenuItem(param_1,uIDCheckItem,0x408);
      }
      FUN_00033770(local_30);
      return 1;
    }
  }
  FUN_00033770(local_30);
  return 0;
}



/* 0002c6a8 FUN_0002c6a8 */

/* Boundary evidence: original MIPS .pdata 0002c6a8..0002c797. Semantic name remains unreviewed. */

undefined4 FUN_0002c6a8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *_Buf2;
  
  uVar2 = 0;
  if ((param_1 < 0) || (DAT_00035634 <= param_1)) {
    if (param_1 == DAT_00035634) {
      FUN_00033470(0);
      uVar2 = 1;
    }
  }
  else {
    _Buf2 = (void *)(*(int *)(param_1 * 4 + DAT_00035630) + 0x208);
    iVar1 = memcmp(&DAT_00035638,_Buf2,0x10);
    if (iVar1 != 0) {
      FUN_000333f0(_Buf2);
      iVar1 = *(int *)(param_1 * 4 + DAT_00035630);
      DAT_00035638 = *(undefined4 *)(iVar1 + 0x208);
      DAT_0003563c = *(undefined4 *)(iVar1 + 0x20c);
      DAT_00035640 = *(undefined4 *)(iVar1 + 0x210);
      DAT_00035644 = *(undefined4 *)(iVar1 + 0x214);
    }
    uVar2 = 1;
    FUN_00033470(1);
  }
  FUN_0002c418();
  return uVar2;
}



/* 0002c798 FUN_0002c798 */

/* Boundary evidence: original MIPS .pdata 0002c798..0002c7b3. Semantic name remains unreviewed. */

void FUN_0002c798(undefined4 param_1)

{
  FUN_000335f0(param_1);
  return;
}



/* 0002c7b4 FUN_0002c7b4 */

/* Boundary evidence: original MIPS .pdata 0002c7b4..0002c7e3. Semantic name remains unreviewed. */

bool FUN_0002c7b4(void)

{
  int iVar1;
  
  iVar1 = FUN_000332f0(0);
  return 0 < iVar1;
}



/* 0002c7e4 FUN_0002c7e4 */

/* Boundary evidence: original MIPS .pdata 0002c7e4..0002c8ff. Semantic name remains unreviewed. */

void FUN_0002c7e4(void)

{
  LSTATUS LVar1;
  int iVar2;
  int iVar3;
  int local_40;
  HKEY local_3c;
  DWORD local_38 [2];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined1 auStack_20 [8];
  int local_18;
  int local_14;
  
  local_38[0] = 4;
  iVar2 = 0;
  iVar3 = 0;
  local_40 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"ControlPanel\\Sip",0,0,&local_3c);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_3c,L"DragStyle",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_40,
                             local_38);
    if ((LVar1 == 0) && (local_40 != 0)) {
      iVar2 = 2;
      iVar3 = GetSystemMetrics(4);
      iVar3 = iVar3 + 2;
    }
    RegCloseKey(local_3c);
  }
  SystemParametersInfoW(0x30,0,auStack_20,0);
  local_30 = (local_18 - iVar2) + -0xf0;
  local_2c = (local_14 - iVar3) + -0x50;
  local_28 = local_18;
  local_24 = local_14;
  FUN_00033670(&local_30);
  return;
}



/* 0002c900 FUN_0002c900 */

/* Boundary evidence: original MIPS .pdata 0002c900..0002c9e3. Semantic name remains unreviewed. */

undefined4 FUN_0002c900(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_40 [4];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  bVar1 = false;
  memset(local_40,0,0x30);
  local_40[0] = 0x30;
  iVar2 = FUN_000334f0(local_40);
  if (iVar2 != 0) {
    iVar2 = local_20 - local_28;
    local_2c = local_1c - local_2c;
    local_1c = local_1c - local_24;
    if ((0 < local_2c) && (local_2c < local_24)) {
      local_24 = local_24 - local_2c;
      bVar1 = true;
    }
    local_20 = local_20 - local_30;
    if ((0 < local_20) && (local_20 < local_28)) {
      local_28 = local_28 - local_20;
      bVar1 = true;
    }
    if (bVar1) {
      local_20 = iVar2 + local_28;
      local_1c = local_1c + local_24;
      local_40[0] = 0x30;
      uVar3 = FUN_00033570(local_40);
      return uVar3;
    }
  }
  return 0;
}



/* 0002c9e4 FUN_0002c9e4 */

/* Boundary evidence: original MIPS .pdata 0002c9e4..0002ca53. Semantic name remains unreviewed. */

void FUN_0002c9e4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 auStack_30 [4];
  undefined4 local_2c;
  
  local_48 = 0x3c;
  local_44 = 0x400;
  local_2c = 1;
  puVar1 = auStack_30 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  local_3c = 0;
  auStack_30 = (undefined1  [4])0x0;
  local_40 = param_1;
  local_38 = param_2;
  local_34 = param_3;
  ShellExecuteEx(&local_48);
  return;
}



/* 0002ca54 FUN_0002ca54 */

/* Boundary evidence: original MIPS .pdata 0002ca54..0002cb3b. Semantic name remains unreviewed. */

undefined4 FUN_0002ca54(HWND param_1)

{
  HMODULE hModule;
  wchar_t *pwVar1;
  undefined *puVar2;
  int iVar3;
  undefined **ppuVar4;
  DWORD local_228 [2];
  WCHAR local_220 [259];
  undefined2 local_1a;
  uint local_18;
  
  local_18 = DAT_00035518;
  GetWindowThreadProcessId(param_1,local_228);
  hModule = OpenProcess(0x1f0fff,0,local_228[0]);
  local_220[0] = L'\0';
  GetModuleFileNameW(hModule,local_220,0x104);
  local_1a = 0;
  CloseHandle(hModule);
  _wcslwr(local_220);
  ppuVar4 = &PTR_u_device_exe_00035538;
  iVar3 = 0;
  puVar2 = PTR_u_device_exe_00035538;
  while( true ) {
    if (puVar2 == (undefined *)0x0) {
      FUN_00033770(local_18);
      return 1;
    }
    pwVar1 = wcsstr(local_220,(wchar_t *)*ppuVar4);
    if (pwVar1 != (wchar_t *)0x0) break;
    iVar3 = iVar3 + 1;
    ppuVar4 = &PTR_u_device_exe_00035538 + iVar3;
    puVar2 = *ppuVar4;
  }
  FUN_00033770(local_18);
  return 0;
}



/* 0002cb3c FUN_0002cb3c */

/* Boundary evidence: original MIPS .pdata 0002cb3c..0002cbdf. Semantic name remains unreviewed. */

void FUN_0002cb3c(void)

{
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_58 = 0x28;
  local_54 = 8;
  local_50 = 8;
  local_4c = 1;
  local_4a = 1;
  local_38 = 2;
  local_34 = 2;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_30 = 0;
  local_2c = 0xffffff;
  local_28 = 0x55555555;
  local_24 = 0xaaaaaaaa;
  local_20 = 0x55555555;
  local_1c = 0xaaaaaaaa;
  local_18 = 0x55555555;
  local_14 = 0xaaaaaaaa;
  local_10 = 0x55555555;
  local_c = 0xaaaaaaaa;
  DAT_00035600 = CreateDIBPatternBrushPt(&local_58,0);
  return;
}



/* 0002cbe0 FUN_0002cbe0 */

/* Boundary evidence: original MIPS .pdata 0002cbe0..0002cd63. Semantic name remains unreviewed. */

undefined4 FUN_0002cbe0(HDC param_1,wchar_t *param_2,int *param_3,size_t *param_4,int param_5)

{
  size_t cchString;
  int iVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  tagSIZE local_30;
  
  iVar2 = param_3[2];
  iVar1 = *param_3;
  cchString = wcslen(param_2);
  if (cchString == 0) {
    *param_4 = 0;
  }
  else {
    GetTextExtentExPointW(param_1,param_2,cchString,0,(LPINT)0x0,(LPINT)0x0,&local_30);
    if (iVar2 - iVar1 < local_30.cx) {
      iVar1 = (iVar2 - iVar1) - param_5;
      sVar3 = 1;
      if (0 < iVar1) {
        sVar4 = 0;
        sVar3 = cchString;
        if (0 < (int)cchString) {
          do {
            iVar2 = sVar4 + sVar3 + 1;
            if (iVar2 < 0) {
              iVar2 = sVar4 + sVar3 + 2;
            }
            cchString = iVar2 >> 1;
            GetTextExtentExPointW
                      (param_1,param_2 + sVar4,cchString - sVar4,0,(LPINT)0x0,(LPINT)0x0,&local_30);
            if (local_30.cx < iVar1) {
              iVar1 = iVar1 - local_30.cx;
              sVar4 = cchString;
            }
            else {
              if (local_30.cx <= iVar1) break;
              sVar3 = cchString - 1;
            }
            cchString = sVar3;
            sVar3 = cchString;
          } while ((int)sVar4 < (int)cchString);
        }
        sVar3 = cchString;
        if ((int)cchString < 1) {
          sVar3 = 1;
        }
      }
      *param_4 = sVar3;
      return 1;
    }
    *param_4 = cchString;
  }
  return 0;
}



/* 0002cd64 FUN_0002cd64 */

/* Boundary evidence: original MIPS .pdata 0002cd64..0002ce0f. Semantic name remains unreviewed. */

void FUN_0002cd64(HDC param_1,HGDIOBJ param_2,int param_3,int param_4,int param_5,int param_6)

{
  HGDIOBJ h;
  
  if ((param_3 < param_5) && (param_4 < param_6)) {
    h = SelectObject(param_1,param_2);
    PatBlt(param_1,param_3,param_4,param_5 - param_3,param_6 - param_4,0xf00021);
    SelectObject(param_1,h);
  }
  return;
}



/* 0002ce10 FUN_0002ce10 */

/* Boundary evidence: original MIPS .pdata 0002ce10..0002cf97. Semantic name remains unreviewed. */

void FUN_0002ce10(HDC param_1,HGDIOBJ param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_3 == 3) || (param_3 == 4)) {
    iVar3 = (param_4[3] - param_4[1]) * 5;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 7;
    }
    iVar5 = (iVar3 >> 3) + 1;
    if (iVar5 < 0) {
      iVar5 = (iVar3 >> 3) + 2;
    }
    iVar5 = iVar5 >> 1;
    iVar4 = param_4[2] - *param_4;
    iVar3 = iVar4;
    if (iVar5 <= iVar4) {
      iVar3 = iVar5;
    }
    if (iVar3 < 1) {
      iVar5 = 1;
    }
    else if (iVar5 > iVar4) {
      iVar5 = iVar4;
    }
    iVar3 = (iVar4 - iVar5) + 1;
    if (iVar3 < 0) {
      iVar3 = (iVar4 - iVar5) + 2;
    }
    iVar4 = (iVar3 >> 1) + *param_4;
    iVar3 = param_4[3] - param_4[1];
    if (iVar3 < 0) {
      iVar3 = iVar3 + 1;
    }
    iVar3 = (iVar3 >> 1) + param_4[1];
    iVar6 = 0;
    if (0 < iVar5) {
      iVar2 = iVar4 + iVar5;
      iVar7 = iVar3 + 1;
      do {
        iVar2 = iVar2 + -1;
        iVar1 = iVar6 + iVar4;
        if (param_3 != 3) {
          iVar1 = iVar2;
        }
        FUN_0002cd64(param_1,param_2,iVar1,iVar3,iVar1 + 1,iVar7 + iVar6);
        iVar6 = iVar6 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar6 < iVar5);
    }
  }
  return;
}



/* 0002cf98 FUN_0002cf98 */

/* Boundary evidence: original MIPS .pdata 0002cf98..0002d053. Semantic name remains unreviewed. */

undefined4 FUN_0002cf98(void)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  int local_18;
  HKEY local_14;
  DWORD local_10 [2];
  
  local_10[0] = 4;
  uVar2 = 0;
  local_18 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Explorer",0,0,&local_14);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_14,L"QVGA",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_18,local_10);
    if ((LVar1 == 0) && (uVar2 = 1, local_18 == 0)) {
      uVar2 = 0;
    }
    RegCloseKey(local_14);
  }
  return uVar2;
}



/* 0002d054 FUN_0002d054 */

/* Boundary evidence: original MIPS .pdata 0002d054..0002d0cf. Semantic name remains unreviewed. */

HFONT FUN_0002d054(LONG param_1)

{
  HFONT pHVar1;
  LOGFONTW local_68;
  uint local_c;
  
  local_c = DAT_00035518;
  memset(&local_68,0,0x5c);
  local_68.lfWeight = 700;
  local_68.lfCharSet = '\x01';
  local_68.lfOutPrecision = '\0';
  local_68.lfClipPrecision = '\0';
  local_68.lfQuality = '\0';
  local_68.lfPitchAndFamily = ' ';
  local_68.lfHeight = param_1;
  pHVar1 = CreateFontIndirectW(&local_68);
  FUN_00033770(local_c);
  return pHVar1;
}



/* 0002d0d0 FUN_0002d0d0 */

int FUN_0002d0d0(int param_1)

{
  if (DAT_00035648 == 0) {
    DAT_00035648 = param_1;
  }
  return param_1;
}



/* 0002d0ec FUN_0002d0ec */

/* Boundary evidence: original MIPS .pdata 0002d0ec..0002d12b. Semantic name remains unreviewed. */

void FUN_0002d0ec(undefined4 *param_1)

{
  if ((HWND)*param_1 != (HWND)0x0) {
    SetForegroundWindow((HWND)*param_1);
    ShowWindow((HWND)*param_1,1);
  }
  return;
}



/* 0002d12c FUN_0002d12c */

/* Boundary evidence: original MIPS .pdata 0002d12c..0002d16f. Semantic name remains unreviewed. */

undefined4 FUN_0002d12c(undefined4 *param_1,HWND param_2,UINT param_3,WPARAM param_4)

{
  BOOL BVar1;
  undefined4 uVar2;
  HWND local_res4;
  UINT local_res8;
  WPARAM local_resc;
  
  if (((HWND)*param_1 == (HWND)0x0) ||
     (local_res4 = param_2, local_res8 = param_3, local_resc = param_4,
     BVar1 = IsDialogMessageW((HWND)*param_1,(LPMSG)&local_res4), BVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 0002d170 FUN_0002d170 */

/* Boundary evidence: original MIPS .pdata 0002d170..0002d283. Semantic name remains unreviewed. */

undefined4 FUN_0002d170(undefined4 param_1,HWND param_2,int param_3,uint param_4,LONG param_5)

{
  LONG LVar1;
  HANDLE hProcess;
  uint nResult;
  DWORD local_18 [2];
  
  if (param_3 == 0x110) {
    SetWindowLongW(param_2,8,param_5);
    SetWindowTextW(param_2,(LPCWSTR)(*(int *)(param_5 + 8) + 0x20));
    FUN_0001e71c(param_2,8);
    MessageBeep(0xffffffff);
  }
  else if (param_3 == 0x111) {
    nResult = param_4 & 0xffff;
    if (nResult == 1) {
      LVar1 = GetWindowLongW(param_2,8);
      GetWindowThreadProcessId(*(HWND *)(*(int *)(LVar1 + 8) + 0x1c),local_18);
      hProcess = OpenProcess(0x1f0fff,0,local_18[0]);
      TerminateProcess(hProcess,0xffffffff);
      CloseHandle(hProcess);
    }
    else if (nResult != 2) {
      return 0;
    }
    EndDialog(param_2,nResult);
  }
  return 0;
}



/* 0002d284 FUN_0002d284 */

/* Boundary evidence: original MIPS .pdata 0002d284..0002d2bb. Semantic name remains unreviewed. */

void FUN_0002d284(undefined4 *param_1)

{
  if ((HWND)*param_1 != (HWND)0x0) {
    DestroyWindow((HWND)*param_1);
    *param_1 = 0;
  }
  return;
}



/* 0002d2bc FUN_0002d2bc */

/* Boundary evidence: original MIPS .pdata 0002d2bc..0002d303. Semantic name remains unreviewed. */

undefined4 FUN_0002d2bc(HWND param_1,int param_2,uint param_3,LONG param_4)

{
  undefined4 uVar1;
  
  if (DAT_00035648 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0002d170(DAT_00035648,param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 0002d304 FUN_0002d304 */

/* Boundary evidence: original MIPS .pdata 0002d304..0002d7e7. Semantic name remains unreviewed. */

undefined4 FUN_0002d304(undefined4 param_1,HWND param_2,int param_3,uint param_4)

{
  HWND pHVar1;
  WPARAM WVar2;
  BOOL BVar3;
  int iVar4;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  int iVar5;
  LRESULT LVar6;
  UINT Msg;
  HWND pHVar7;
  WCHAR *lParam;
  LPARAM lParam_00;
  uint uVar8;
  int iVar9;
  WCHAR aWStack_278 [32];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00035518;
  pHVar1 = GetDlgItem(param_2,0xbcc);
  if (param_3 == 6) {
    if ((param_4 & 0xffff) == 0) goto LAB_0002d380;
    SendMessageW(pHVar1,0x184,0,0);
    if (DAT_0003556c == (undefined4 *)0x0) goto LAB_0002d7ac;
    iVar4 = 0;
    do {
      iVar4 = FUN_00025084(DAT_0003556c,iVar4);
      if (iVar4 == 0) {
        iVar4 = FUN_00025084(DAT_0003556c,0);
        iVar9 = 0;
        break;
      }
      iVar9 = iVar4;
    } while ((*(uint *)(iVar4 + 8) & 0x20) == 0);
    do {
      if (iVar4 == 0) {
        iVar4 = FUN_00025084(DAT_0003556c,0);
      }
      else {
        GetClassNameW(*(HWND *)(iVar4 + 0x1c),aWStack_278,0x1f);
        iVar5 = lstrcmpiW(aWStack_278,L"Explore");
        if (iVar5 == 0) {
          LoadStringW(DAT_00035560,21000,aWStack_238,0x104);
          wcscat(aWStack_238,L" - ");
          wcscat(aWStack_238,(wchar_t *)(iVar4 + 0x20));
          lParam = aWStack_238;
        }
        else {
          lParam = (WCHAR *)(iVar4 + 0x20);
        }
        WVar2 = SendMessageW(pHVar1,0x180,0,(LPARAM)lParam);
        if ((WVar2 != 0xffffffff) &&
           (SendMessageW(pHVar1,0x19a,WVar2,*(LPARAM *)(iVar4 + 0x1c)),
           (*(uint *)(iVar4 + 8) & 0x20) != 0)) {
          SendMessageW(pHVar1,0x186,WVar2,0);
        }
        iVar4 = FUN_00025084(DAT_0003556c,iVar4);
      }
    } while (iVar4 != iVar9);
    LVar6 = SendMessageW(pHVar1,0x18b,0,0);
    if (LVar6 != 0) {
      pHVar7 = GetDlgItem(param_2,1);
      EnableWindow(pHVar7,1);
      pHVar7 = GetDlgItem(param_2,0xbce);
      EnableWindow(pHVar7,1);
      SendMessageW(param_2,0x28,(WPARAM)pHVar1,1);
      LVar6 = SendMessageW(pHVar1,0x188,0,0);
      if (LVar6 != -1) goto LAB_0002d7ac;
      Msg = 0x186;
      goto LAB_0002d798;
    }
    pHVar1 = GetDlgItem(param_2,1);
    EnableWindow(pHVar1,0);
    pHVar1 = GetDlgItem(param_2,0xbce);
    EnableWindow(pHVar1,0);
    pHVar7 = GetDlgItem(param_2,2);
    lParam_00 = 1;
    Msg = 0x28;
  }
  else {
    if (param_3 == 0x110) {
      FUN_0001e71c(param_2,8);
      SetFocus(pHVar1);
      FUN_00033770(local_30);
      return 0xffffffff;
    }
    if (param_3 != 0x111) goto LAB_0002d7ac;
LAB_0002d380:
    uVar8 = param_4 & 0xffff;
    if (uVar8 == 1) {
LAB_0002d74c:
      WVar2 = SendMessageW(pHVar1,0x188,0,0);
      if (WVar2 == 0xffffffff) goto LAB_0002d7ac;
      uVar8 = SendMessageW(pHVar1,0x199,WVar2,0);
      SetForegroundWindow((HWND)(uVar8 | 1));
    }
    else if (uVar8 != 2) {
      if (uVar8 != 0xbcc) {
        if (uVar8 == 0xbce) {
          ShowWindow(param_2,0);
          WVar2 = SendMessageW(pHVar1,0x188,0,0);
          if (WVar2 != 0xffffffff) {
            pHVar1 = (HWND)SendMessageW(pHVar1,0x199,WVar2,0);
            BVar3 = IsWindowEnabled(pHVar1);
            if (BVar3 != 0) {
              PostMessageW(pHVar1,0x10,0,0);
              Sleep(5000);
            }
            BVar3 = IsWindow(pHVar1);
            if ((((BVar3 != 0) && (iVar4 = FUN_0002ca54(pHVar1), iVar4 != 0)) &&
                (DAT_0003556c != (undefined4 *)0x0)) &&
               (iVar4 = FUN_00021918(DAT_0003556c,(int)pHVar1), iVar4 != 0)) {
              hResInfo = FindResourceW(DAT_00035560,(LPCWSTR)0x3f6,(LPCWSTR)0x5);
              hDialogTemplate = LoadResource(DAT_00035560,hResInfo);
              DialogBoxIndirectParamW(DAT_00035560,hDialogTemplate,param_2,FUN_0002d2bc,iVar4);
            }
          }
        }
        goto LAB_0002d7ac;
      }
      if (param_4 >> 0x10 != 2) goto LAB_0002d7ac;
      goto LAB_0002d74c;
    }
    ShowWindow(param_2,0);
    Msg = 0x184;
LAB_0002d798:
    pHVar7 = (HWND)0x0;
    lParam_00 = 0;
    param_2 = pHVar1;
  }
  SendMessageW(param_2,Msg,(WPARAM)pHVar7,lParam_00);
LAB_0002d7ac:
  FUN_00033770(local_30);
  return 0;
}



/* 0002d7e8 FUN_0002d7e8 */

/* Boundary evidence: original MIPS .pdata 0002d7e8..0002d82f. Semantic name remains unreviewed. */

undefined4 FUN_0002d7e8(HWND param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (DAT_00035648 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0002d304(DAT_00035648,param_1,param_2,param_3);
  }
  return uVar1;
}



/* 0002d830 FUN_0002d830 */

/* Boundary evidence: original MIPS .pdata 0002d830..0002d8a7. Semantic name remains unreviewed. */

void FUN_0002d830(undefined4 *param_1)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  HWND pHVar1;
  
  hResInfo = FindResourceW(DAT_00035560,(LPCWSTR)0x3ee,(LPCWSTR)0x5);
  lpTemplate = LoadResource(DAT_00035560,hResInfo);
  pHVar1 = CreateDialogIndirectParamW(DAT_00035560,lpTemplate,(HWND)0x0,FUN_0002d7e8,0);
  *param_1 = pHVar1;
  return;
}



/* 0002d8a8 FUN_0002d8a8 */

/* Boundary evidence: original MIPS .pdata 0002d8a8..0002d9e7. Semantic name remains unreviewed. */

void FUN_0002d8a8(undefined4 *param_1,undefined4 *param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_30 [2];
  HKEY local_28 [2];
  
  local_30[0] = 0;
  local_30[1] = 4;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Power",0,0,local_28);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_28[0],L"ShowIcon",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_30,
                             (LPDWORD)(local_30 + 1));
    uVar3 = 1;
    if ((LVar1 != 0) || (uVar2 = 1, local_30[0] == 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
    local_30[1] = 4;
    LVar1 = RegQueryValueExW(local_28[0],L"ShowWarnings",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_30,
                             (LPDWORD)(local_30 + 1));
    RegCloseKey(local_28[0]);
    if ((LVar1 != 0) || (local_30[0] == 0)) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 1;
    *param_1 = 1;
  }
  *param_2 = uVar3;
  return;
}



/* 0002d9e8 FUN_0002d9e8 */

/* Boundary evidence: original MIPS .pdata 0002d9e8..0002da47. Semantic name remains unreviewed. */

undefined4 * FUN_0002d9e8(undefined4 *param_1,undefined4 param_2)

{
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_00012988;
  FUN_0002d8a8(param_1 + 1,param_1 + 2);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0xffffffff;
  param_1[8] = 0;
  param_1[9] = 0;
  return param_1;
}



/* 0002da48 FUN_0002da48 */

/* Boundary evidence: original MIPS .pdata 0002da48..0002db23. Semantic name remains unreviewed. */

void FUN_0002da48(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  HINSTANCE hInst;
  int local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 auStack_a4 [4];
  undefined1 auStack_a0 [4];
  HANDLE local_9c;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00035518;
  hInst = *(HINSTANCE *)(param_1 + 0xc);
  if ((hInst != (HINSTANCE)0x0) &&
     (*(undefined4 *)(param_1 + 0x1c) = param_3, *(int *)(param_1 + 4) != 0)) {
    local_b0 = 0x98;
    puVar1 = auStack_a4 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x10000007U >> (3 - uVar2) * 8;
    puVar1 = auStack_a0 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x404U >> (3 - uVar2) * 8;
    auStack_a4 = (undefined1  [4])0x10000007;
    auStack_a0 = (undefined1  [4])0x404;
    local_ac = param_2;
    local_a8 = param_3;
    local_9c = LoadImageW(hInst,(LPCWSTR)0x136,1,0x10,0x10,0);
    LoadStringW(*(HINSTANCE *)(param_1 + 0xc),0x527a,aWStack_98,0x40);
    FUN_000147e4(0,&local_b0);
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  FUN_00033770(local_18);
  return;
}



/* 0002db24 FUN_0002db24 */

/* Boundary evidence: original MIPS .pdata 0002db24..0002e1bb. Semantic name remains unreviewed. */

void FUN_0002db24(int param_1,HWND param_2,int param_3)

{
  undefined1 *puVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  HANDLE pvVar5;
  HWND hWnd;
  WPARAM WVar6;
  LPARAM LVar7;
  uint uVar8;
  int local_c8;
  undefined1 auStack_c4 [4];
  undefined1 local_c0 [4];
  undefined1 local_bc [4];
  undefined4 local_b8;
  undefined1 auStack_b4 [4];
  undefined1 local_b0;
  undefined1 local_af;
  uint local_30;
  
  local_30 = DAT_00035518;
  if ((param_3 == 0) || (param_3 == -0xc)) goto LAB_0002e188;
  if (*(int *)(param_1 + 4) != 0) {
    local_c8 = 0x98;
    local_bc = (undefined1  [4])0x3;
    uVar8 = *(uint *)(param_1 + 0x1c);
    local_b0 = 0;
    puVar1 = auStack_c4 + 3;
    uVar4 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar4) =
         *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | (uint)param_2 >> (3 - uVar4) * 8;
    local_b8 = 0x404;
    puVar1 = auStack_b4 + 3;
    uVar4 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar4) =
         *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | 0U >> (3 - uVar4) * 8;
    puVar1 = local_c0 + 3;
    uVar4 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar4) =
         *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | uVar8 >> (3 - uVar4) * 8;
    cVar2 = *(char *)(param_3 + 0x20);
    auStack_b4 = (undefined1  [4])0x0;
    local_af = 0;
    auStack_c4 = (undefined1  [4])param_2;
    local_c0 = (undefined1  [4])uVar8;
    if (DAT_0003564e != cVar2) {
      DAT_0003564e = cVar2;
      if ((cVar2 == '\x01') && ((*(byte *)(param_3 + 0x21) & 8) == 0)) {
        pvVar5 = LoadImageW(*(HINSTANCE *)(param_1 + 0xc),(LPCWSTR)0x136,1,0x10,0x10,0);
        puVar1 = auStack_b4 + 3;
        uVar4 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar4) =
             *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | (uint)pvVar5 >> (3 - uVar4) * 8;
        local_bc = (undefined1  [4])((uint)local_bc | 0x10000000);
        puVar1 = local_bc + 3;
        uVar4 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar4) =
             *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | (uint)local_bc >> (3 - uVar4) * 8;
        auStack_b4 = (undefined1  [4])pvVar5;
        if (*(int *)(param_1 + 0x20) == 0) {
          FUN_000147e4(0,&local_c8);
          *(undefined4 *)(param_1 + 0x20) = 1;
        }
        else {
          FUN_000147e4(1,&local_c8);
        }
      }
      DAT_0003564d = 0;
    }
    bVar3 = *(byte *)(param_3 + 0x21);
    if (DAT_0003564d != bVar3) {
      DAT_0003564d = bVar3;
      if (DAT_0003564e == '\x01') {
        if ((bVar3 & 8) == 0) {
          pvVar5 = LoadImageW(*(HINSTANCE *)(param_1 + 0xc),(LPCWSTR)0x136,1,0x10,0x10,0);
        }
        else {
          pvVar5 = LoadImageW(*(HINSTANCE *)(param_1 + 0xc),(LPCWSTR)0x13d,1,0x10,0x10,0);
        }
LAB_0002dcd4:
        puVar1 = auStack_b4 + 3;
        uVar4 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar4) =
             *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | (uint)pvVar5 >> (3 - uVar4) * 8;
        local_bc = (undefined1  [4])((uint)local_bc | 0x10000000);
        puVar1 = local_bc + 3;
        uVar4 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar4) =
             *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | (uint)local_bc >> (3 - uVar4) * 8;
        auStack_b4 = (undefined1  [4])pvVar5;
        if (*(int *)(param_1 + 0x20) == 0) {
          FUN_000147e4(0,&local_c8);
          *(undefined4 *)(param_1 + 0x20) = 1;
        }
        else {
          FUN_000147e4(1,&local_c8);
        }
      }
      else if (((bVar3 & 1) == 0) && (bVar3 != 0xff)) {
        if ((bVar3 & 2) != 0) {
          pvVar5 = LoadImageW(*(HINSTANCE *)(param_1 + 0xc),(LPCWSTR)0x138,1,0x10,0x10,0);
          goto LAB_0002dcd4;
        }
        if (((bVar3 & 4) == 0) && ((bVar3 & 0x80) == 0)) {
          pvVar5 = LoadImageW(*(HINSTANCE *)(param_1 + 0xc),(LPCWSTR)0x139,1,0x10,0x10,0);
          puVar1 = auStack_b4 + 3;
          uVar4 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar4) =
               *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | (uint)pvVar5 >> (3 - uVar4) * 8;
          local_bc = (undefined1  [4])((uint)local_bc | 0x10000000);
          puVar1 = local_bc + 3;
          uVar4 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar4) =
               *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 |
               (uint)local_bc >> (3 - uVar4) * 8;
          auStack_b4 = (undefined1  [4])pvVar5;
          if (*(int *)(param_1 + 0x20) == 0) {
            FUN_000147e4(0,&local_c8);
            *(undefined4 *)(param_1 + 0x20) = 1;
          }
          else {
            FUN_000147e4(1,&local_c8);
          }
          if (*(char *)(param_3 + 0x21) != '\x04') goto LAB_0002dea0;
        }
        else {
          pvVar5 = LoadImageW(*(HINSTANCE *)(param_1 + 0xc),(LPCWSTR)0x139,1,0x10,0x10,0);
          puVar1 = auStack_b4 + 3;
          uVar4 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar4) =
               *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | (uint)pvVar5 >> (3 - uVar4) * 8;
          local_bc = (undefined1  [4])((uint)local_bc | 0x10000000);
          puVar1 = local_bc + 3;
          uVar4 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar4) =
               *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 |
               (uint)local_bc >> (3 - uVar4) * 8;
          auStack_b4 = (undefined1  [4])pvVar5;
          if (*(int *)(param_1 + 0x20) == 0) {
            FUN_000147e4(0,&local_c8);
            *(undefined4 *)(param_1 + 0x20) = 1;
          }
          else {
            FUN_000147e4(1,&local_c8);
          }
        }
        PostMessageW(param_2,0x111,0x67,0x3f4);
      }
      else {
        FUN_000147e4(2,&local_c8);
        if (*(HWND *)(param_1 + 0x18) != (HWND)0x0) {
          PostMessageW(*(HWND *)(param_1 + 0x18),0x111,1,0);
        }
        *(undefined4 *)(param_1 + 0x20) = 0;
      }
    }
LAB_0002dea0:
    bVar3 = *(byte *)(param_3 + 0x23);
    if (DAT_0003564c != bVar3) {
      local_c0 = (undefined1  [4])(*(int *)(param_1 + 0x1c) + 1);
      if ((bVar3 == 0xff) || ((bVar3 & 1) != 0)) {
        FUN_000147e4(2,&local_c8);
        if (*(HWND *)(param_1 + 0x10) != (HWND)0x0) {
          PostMessageW(*(HWND *)(param_1 + 0x10),0x111,1,0);
        }
        if (*(int *)(param_1 + 0x14) != 0) {
          PostMessageW(*(HWND *)(param_1 + 0x18),0x111,1,0);
        }
        *(undefined4 *)(param_1 + 0x24) = 0;
      }
      else {
        if ((bVar3 & 2) == 0) {
          if (((bVar3 & 4) == 0) && ((bVar3 & 0x80) == 0)) goto LAB_0002e030;
          pvVar5 = LoadImageW(*(HINSTANCE *)(param_1 + 0xc),(LPCWSTR)0x13c,1,0x10,0x10,0);
          puVar1 = auStack_b4 + 3;
          uVar4 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar4) =
               *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | (uint)pvVar5 >> (3 - uVar4) * 8;
          local_bc = (undefined1  [4])((uint)local_bc | 0x10000000);
          puVar1 = local_bc + 3;
          uVar4 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar4) =
               *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 |
               (uint)local_bc >> (3 - uVar4) * 8;
          auStack_b4 = (undefined1  [4])pvVar5;
          if (*(int *)(param_1 + 0x24) == 0) {
            FUN_000147e4(0,&local_c8);
            *(undefined4 *)(param_1 + 0x24) = 1;
          }
          else {
            FUN_000147e4(1,&local_c8);
          }
          LVar7 = 0x3f3;
        }
        else {
          pvVar5 = LoadImageW(*(HINSTANCE *)(param_1 + 0xc),(LPCWSTR)0x13a,1,0x10,0x10,0);
          puVar1 = auStack_b4 + 3;
          uVar4 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar4) =
               *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | (uint)pvVar5 >> (3 - uVar4) * 8;
          local_bc = (undefined1  [4])((uint)local_bc | 0x10000000);
          puVar1 = local_bc + 3;
          uVar4 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar4) =
               *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 |
               (uint)local_bc >> (3 - uVar4) * 8;
          auStack_b4 = (undefined1  [4])pvVar5;
          if (*(int *)(param_1 + 0x24) == 0) {
            FUN_000147e4(0,&local_c8);
            *(undefined4 *)(param_1 + 0x24) = 1;
          }
          else {
            FUN_000147e4(1,&local_c8);
          }
          LVar7 = 0x3f2;
        }
        PostMessageW(param_2,0x111,0x67,LVar7);
      }
    }
LAB_0002e030:
    DAT_0003564c = *(byte *)(param_3 + 0x23);
    goto LAB_0002e188;
  }
  if (DAT_0003564e != *(char *)(param_3 + 0x20)) {
    DAT_0003564d = 0;
    DAT_0003564e = *(char *)(param_3 + 0x20);
  }
  bVar3 = *(byte *)(param_3 + 0x21);
  if (DAT_0003564d == bVar3) goto LAB_0002e188;
  DAT_0003564d = bVar3;
  if (DAT_0003564e != '\x01') {
    if (((bVar3 & 1) == 0) && (bVar3 != 0xff)) {
      if (((bVar3 & 4) != 0) || ((bVar3 & 0x80) != 0)) {
        LVar7 = 0x3f4;
        WVar6 = 0x67;
        hWnd = param_2;
LAB_0002e0d8:
        PostMessageW(hWnd,0x111,WVar6,LVar7);
      }
    }
    else {
      hWnd = *(HWND *)(param_1 + 0x18);
      if (hWnd != (HWND)0x0) {
        LVar7 = 0;
        WVar6 = 1;
        goto LAB_0002e0d8;
      }
    }
  }
  bVar3 = *(byte *)(param_3 + 0x23);
  if (DAT_0003564c != bVar3) {
    if (((bVar3 & 1) == 0) && (bVar3 != 0xff)) {
      if ((bVar3 & 2) == 0) {
        if (((bVar3 & 4) == 0) && ((bVar3 & 0x80) == 0)) goto LAB_0002e180;
        LVar7 = 0x3f3;
      }
      else {
        LVar7 = 0x3f2;
      }
      WVar6 = 0x67;
    }
    else {
      if (*(HWND *)(param_1 + 0x10) != (HWND)0x0) {
        PostMessageW(*(HWND *)(param_1 + 0x10),0x111,1,0);
      }
      param_2 = *(HWND *)(param_1 + 0x14);
      if (param_2 == (HWND)0x0) goto LAB_0002e180;
      LVar7 = 0;
      WVar6 = 1;
    }
    PostMessageW(param_2,0x111,WVar6,LVar7);
  }
LAB_0002e180:
  DAT_0003564c = *(byte *)(param_3 + 0x23);
LAB_0002e188:
  FUN_00033770(local_30);
  return;
}



/* 0002e1bc FUN_0002e1bc */

/* Boundary evidence: original MIPS .pdata 0002e1bc..0002e34f. Semantic name remains unreviewed. */

undefined4 FUN_0002e1bc(int param_1,undefined4 param_2,int param_3,DLGPROC param_4)

{
  HRSRC pHVar1;
  LPCDLGTEMPLATEW pDVar2;
  HWND pHVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 8) == 0) {
LAB_0002e1e4:
    uVar4 = 0;
  }
  else {
    if (param_3 == 0x3f2) {
      pHVar3 = *(HWND *)(param_1 + 0x10);
      if (pHVar3 == (HWND)0x0) {
        pHVar1 = FindResourceW(*(HMODULE *)(param_1 + 0xc),(LPCWSTR)0x3f2,(LPCWSTR)0x5);
        pDVar2 = LoadResource(*(HMODULE *)(param_1 + 0xc),pHVar1);
        pHVar3 = CreateDialogIndirectParamW
                           (*(HINSTANCE *)(param_1 + 0xc),pDVar2,(HWND)0x0,param_4,0x3f2);
        *(HWND *)(param_1 + 0x10) = pHVar3;
LAB_0002e324:
        ShowWindow(pHVar3,1);
        return 1;
      }
    }
    else if (param_3 == 0x3f3) {
      pHVar3 = *(HWND *)(param_1 + 0x14);
      if (pHVar3 == (HWND)0x0) {
        pHVar1 = FindResourceW(*(HMODULE *)(param_1 + 0xc),(LPCWSTR)0x3f3,(LPCWSTR)0x5);
        pDVar2 = LoadResource(*(HMODULE *)(param_1 + 0xc),pHVar1);
        pHVar3 = CreateDialogIndirectParamW
                           (*(HINSTANCE *)(param_1 + 0xc),pDVar2,(HWND)0x0,param_4,0x3f3);
        *(HWND *)(param_1 + 0x14) = pHVar3;
        goto LAB_0002e324;
      }
    }
    else {
      if (param_3 != 0x3f4) goto LAB_0002e1e4;
      pHVar3 = *(HWND *)(param_1 + 0x18);
      if (pHVar3 == (HWND)0x0) {
        pHVar1 = FindResourceW(*(HMODULE *)(param_1 + 0xc),(LPCWSTR)0x3f4,(LPCWSTR)0x5);
        pDVar2 = LoadResource(*(HMODULE *)(param_1 + 0xc),pHVar1);
        pHVar3 = CreateDialogIndirectParamW
                           (*(HINSTANCE *)(param_1 + 0xc),pDVar2,(HWND)0x0,param_4,0x3f4);
        *(HWND *)(param_1 + 0x18) = pHVar3;
        goto LAB_0002e324;
      }
    }
    uVar4 = 1;
    SetForegroundWindow(pHVar3);
  }
  return uVar4;
}



/* 0002e350 FUN_0002e350 */

/* Boundary evidence: original MIPS .pdata 0002e350..0002e3c3. Semantic name remains unreviewed. */

undefined4 FUN_0002e350(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_3 == *(int *)(param_1 + 0x1c)) || (param_3 == *(int *)(param_1 + 0x1c) + 1)) &&
     (param_4 == 0x203)) {
    iVar1 = LoadStringW(*(HINSTANCE *)(param_1 + 0xc),0x526e,(LPWSTR)0x0,0);
    FUN_0002c9e4(param_2,L"ctlpnl",iVar1);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0002e3c4 FUN_0002e3c4 */

/* Boundary evidence: original MIPS .pdata 0002e3c4..0002e42f. Semantic name remains unreviewed. */

undefined4 FUN_0002e3c4(int param_1,HWND param_2,UINT param_3,WPARAM param_4)

{
  BOOL BVar1;
  undefined4 uVar2;
  HWND local_res4;
  UINT local_res8;
  WPARAM local_resc;
  
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if (((*(HWND *)(param_1 + 0x10) == (HWND)0x0) ||
      (BVar1 = IsDialogMessageW(*(HWND *)(param_1 + 0x10),(LPMSG)&local_res4), BVar1 == 0)) &&
     ((*(HWND *)(param_1 + 0x14) == (HWND)0x0 ||
      (BVar1 = IsDialogMessageW(*(HWND *)(param_1 + 0x14),(LPMSG)&local_res4), BVar1 == 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 0002e430 FUN_0002e430 */

/* Boundary evidence: original MIPS .pdata 0002e430..0002e473. Semantic name remains unreviewed. */

undefined4 * FUN_0002e430(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00012988;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0002e474 FUN_0002e474 */

/* Boundary evidence: original MIPS .pdata 0002e474..0002e4e3. Semantic name remains unreviewed. */

undefined4 FUN_0002e474(HKEY param_1,LPDWORD param_2,LPCWSTR param_3,LPBYTE param_4,int param_5)

{
  undefined4 uVar1;
  LSTATUS LVar2;
  DWORD local_10;
  DWORD DStack_c;
  
  if (param_2 == (LPDWORD)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    local_10 = param_5 << 1;
    LVar2 = RegQueryValueExW(param_1,param_3,param_2,&DStack_c,param_4,&local_10);
    if (LVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x80004005;
    }
  }
  return uVar1;
}



/* 0002e4e4 FUN_0002e4e4 */

undefined4 FUN_0002e4e4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



/* 0002e4ec FUN_0002e4ec */

/* Boundary evidence: original MIPS .pdata 0002e4ec..0002e61f. Semantic name remains unreviewed. */

undefined4 FUN_0002e4ec(undefined4 param_1,HWND param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  WCHAR aWStack_258 [20];
  WCHAR local_230 [260];
  uint local_28;
  
  local_28 = DAT_00035518;
  iVar3 = 0;
  if (param_2 == (HWND)0x0) {
    FUN_00033770(DAT_00035518);
    uVar1 = 0;
  }
  else {
    local_230[0] = L'\0';
    wsprintfW(aWStack_258,L"%d",0);
    iVar2 = FUN_0002e474((HKEY)0x80000002,(LPDWORD)L"Explorer\\RunHistory",aWStack_258,
                         (LPBYTE)local_230,0x104);
    while (iVar2 == 0) {
      SendMessageW(param_2,0x143,0,(LPARAM)local_230);
      iVar3 = iVar3 + 1;
      StringCbPrintfW(aWStack_258,0x24,L"%d",iVar3);
      iVar2 = FUN_0002e474((HKEY)0x80000002,(LPDWORD)L"Explorer\\RunHistory",aWStack_258,
                           (LPBYTE)local_230,0x104);
    }
    SendMessageW(param_2,0x148,0,(LPARAM)local_230);
    SetWindowTextW(param_2,local_230);
    FUN_00033770(local_28);
    uVar1 = 1;
  }
  return uVar1;
}



/* 0002e620 FUN_0002e620 */

/* Boundary evidence: original MIPS .pdata 0002e620..0002e7d3. Semantic name remains unreviewed. */

undefined4 FUN_0002e620(undefined4 param_1,HWND param_2,LPARAM param_3)

{
  WPARAM WVar1;
  LSTATUS LVar2;
  LRESULT LVar3;
  size_t sVar4;
  undefined4 uVar5;
  HKEY local_260 [2];
  wchar_t awStack_258 [20];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_00035518;
  WVar1 = SendMessageW(param_2,0x158,0xffffffff,param_3);
  if (WVar1 != 0xffffffff) {
    SendMessageW(param_2,0x144,WVar1,0);
  }
  SendMessageW(param_2,0x14a,0,param_3);
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Explorer\\RunHistory",0,0,local_260);
  if (LVar2 == 0) {
    WVar1 = 0;
    LVar3 = SendMessageW(param_2,0x146,0,0);
    uVar5 = 1;
    if (0 < LVar3) {
      do {
        SendMessageW(param_2,0x148,WVar1,(LPARAM)awStack_230);
        sVar4 = wcslen(awStack_230);
        StringCbPrintfW(awStack_258,0x24,L"%d",WVar1);
        RegSetValueExW(local_260[0],awStack_258,0,1,(BYTE *)awStack_230,(sVar4 + 1) * 2);
        WVar1 = WVar1 + 1;
        LVar3 = SendMessageW(param_2,0x146,0,0);
      } while ((int)WVar1 < LVar3);
    }
    RegCloseKey(local_260[0]);
    FUN_00033770(local_28);
  }
  else {
    FUN_00033770(local_28);
    uVar5 = 0;
  }
  return uVar5;
}



/* 0002e7d4 FUN_0002e7d4 */

/* Boundary evidence: original MIPS .pdata 0002e7d4..0002e9df. Semantic name remains unreviewed. */

undefined4 FUN_0002e7d4(HWND param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  int iVar4;
  size_t sVar5;
  BOOL BVar6;
  wchar_t *pwVar7;
  HWND pHVar8;
  LPWSTR pWVar9;
  int iVar10;
  undefined4 uVar11;
  tagOFNW local_680 [6];
  WCHAR aWStack_428 [128];
  undefined1 auStack_328 [256];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_00035518;
  local_680[0].lStructSize = 0;
  memset(&local_680[0].hwndOwner,0,0x48);
  pWVar9 = aWStack_428;
  uVar11 = 0;
  iVar10 = 0;
  do {
    iVar4 = LoadStringW(DAT_00035560,iVar10 + 0x520a,pWVar9,(int)(auStack_328 + -(int)pWVar9));
    if (iVar4 != 0) {
      sVar5 = wcslen(pWVar9);
      pWVar9 = pWVar9 + sVar5 + 1;
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 < 4);
  local_680[0].lpstrFilter = aWStack_428;
  local_680[0].lStructSize = 0x4c;
  *pWVar9 = L'\0';
  pWVar9 = pWVar9 + 1;
  LoadStringW(DAT_00035560,0x5275,pWVar9,(int)(auStack_328 + -(int)pWVar9));
  local_680[0].lpstrFile = (LPWSTR)&local_680[0].dwReserved;
  puVar3 = (undefined1 *)((int)&local_680[0].lpstrTitle + 3);
  uVar1 = (uint)puVar3 & 3;
  puVar2 = (uint *)(puVar3 + -uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | (uint)pWVar9 >> (3 - uVar1) * 8;
  puVar3 = (undefined1 *)((int)&local_680[0].lpstrDefExt + 3);
  uVar1 = (uint)puVar3 & 3;
  puVar2 = (uint *)(puVar3 + -uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0x129c0U >> (3 - uVar1) * 8;
  puVar3 = (undefined1 *)((int)&local_680[0].nFilterIndex + 3);
  uVar1 = (uint)puVar3 & 3;
  puVar2 = (uint *)(puVar3 + -uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 1U >> (3 - uVar1) * 8;
  puVar3 = (undefined1 *)((int)&local_680[0].Flags + 3);
  uVar1 = (uint)puVar3 & 3;
  puVar2 = (uint *)(puVar3 + -uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0x1000U >> (3 - uVar1) * 8;
  puVar3 = (undefined1 *)((int)&local_680[0].nMaxFile + 3);
  uVar1 = (uint)puVar3 & 3;
  puVar2 = (uint *)(puVar3 + -uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0x104U >> (3 - uVar1) * 8;
  puVar3 = (undefined1 *)((int)&local_680[0].hwndOwner + 3);
  uVar1 = (uint)puVar3 & 3;
  puVar2 = (uint *)(puVar3 + -uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | (uint)param_1 >> (3 - uVar1) * 8;
  local_680[0].lpstrDefExt = L"exe";
  local_680[0].nFilterIndex = 1;
  local_680[0].Flags = 0x1000;
  local_680[0].nMaxFile = 0x104;
  local_680[0].dwReserved._0_2_ = 0;
  local_680[0].hwndOwner = param_1;
  local_680[0].lpstrTitle = pWVar9;
  BVar6 = GetOpenFileNameW(local_680);
  if (BVar6 != 0) {
    pwVar7 = wcschr((wchar_t *)&local_680[0].dwReserved,L' ');
    if (pwVar7 != (wchar_t *)0x0) {
      wcscpy(awStack_228,L"\"");
      wcscat(awStack_228,(wchar_t *)&local_680[0].dwReserved);
      wcscat(awStack_228,L"\"");
      wcscpy((wchar_t *)&local_680[0].dwReserved,awStack_228);
    }
    SetDlgItemTextW(param_1,0x3f5,(LPCWSTR)&local_680[0].dwReserved);
    sVar5 = wcslen((wchar_t *)&local_680[0].dwReserved);
    pHVar8 = GetDlgItem(param_1,1);
    EnableWindow(pHVar8,(uint)(sVar5 != 0));
    pHVar8 = GetDlgItem(param_1,1);
    SendMessageW(param_1,0x28,(WPARAM)pHVar8,1);
    uVar11 = 1;
  }
  FUN_00033770(local_20);
  return uVar11;
}



/* 0002e9e0 FUN_0002e9e0 */

/* Boundary evidence: original MIPS .pdata 0002e9e0..0002eed3. Semantic name remains unreviewed. */

undefined4 FUN_0002e9e0(int param_1,HWND param_2,int param_3,uint param_4)

{
  HANDLE hObject;
  size_t sVar1;
  HWND pHVar2;
  int iVar3;
  HCURSOR hCursor;
  HIMC pHVar4;
  BOOL BVar5;
  DWORD dwIndex;
  wchar_t *pwVar6;
  LPWSTR pWVar7;
  wchar_t *_Source;
  LPWSTR _Str;
  uint uVar8;
  uint local_4b0 [2];
  undefined4 local_4a8;
  undefined1 auStack_4a4 [4];
  HWND local_4a0;
  wchar_t *local_498;
  LPWSTR local_494;
  undefined4 local_48c;
  tagWNDCLASSW tStack_468;
  wchar_t awStack_440 [260];
  wchar_t local_238;
  wchar_t local_236 [259];
  uint local_30;
  
  local_30 = DAT_00035518;
  if (param_3 == 0x110) {
    BVar5 = GetClassInfoW(DAT_00035560,L"SIPPREF",&tStack_468);
    if (BVar5 != 0) {
      CreateWindowExW(0,L"SIPPREF",(LPCWSTR)0x0,0x40000000,-10,-10,5,5,param_2,(HMENU)0x0,
                      DAT_00035560,(LPVOID)0x0);
    }
    FUN_0001e71c(param_2,2);
    pHVar2 = GetDlgItem(param_2,0x3f5);
    SendMessageW(pHVar2,0x141,0x103,0);
    pHVar2 = GetDlgItem(param_2,0x3f5);
    FUN_0002e4ec(param_1,pHVar2);
    GetDlgItemTextW(param_2,0x3f5,&local_238,0x104);
    sVar1 = wcslen(&local_238);
    pHVar2 = GetDlgItem(param_2,1);
    EnableWindow(pHVar2,(uint)(sVar1 != 0));
    FUN_00033770(local_30);
    return 1;
  }
  if (param_3 == 0x111) {
    uVar8 = param_4 & 0xffff;
    if (uVar8 == 1) {
      _Str = (LPWSTR)0x0;
      if (*(int *)(param_1 + 0x4c) == 0) {
        SetFocus(*(HWND *)(param_1 + 8));
      }
      GetDlgItemTextW(param_2,0x3f5,&local_238,0x104);
      _Source = &local_238;
      while (local_238 == L' ') {
        _Source = _Source + 1;
        local_238 = *_Source;
      }
      wcscpy(awStack_440,_Source);
      local_4b0[0] = 0x104;
      BVar5 = PathIsURLW(awStack_440);
      if ((BVar5 == 0) && (iVar3 = FUN_00014ff4(_Source,awStack_440,local_4b0), iVar3 == 0)) {
        PathRemoveArgsW(awStack_440);
        sVar1 = wcslen(awStack_440);
        iVar3 = sVar1 - 1;
        if (0 < iVar3) {
          pwVar6 = awStack_440 + iVar3;
          do {
            if (*pwVar6 != L' ') break;
            iVar3 = iVar3 + -1;
            pwVar6 = pwVar6 + -1;
          } while (0 < iVar3);
        }
        awStack_440[iVar3 + 1] = L'\0';
        _Str = PathGetArgsW(_Source);
        sVar1 = wcslen(_Str);
        iVar3 = sVar1 - 1;
        if (0 < iVar3) {
          pWVar7 = _Str + iVar3;
          do {
            if (*pWVar7 != L' ') break;
            iVar3 = iVar3 + -1;
            pWVar7 = pWVar7 + -1;
          } while (0 < iVar3);
        }
        _Str[iVar3 + 1] = L'\0';
      }
      memset(auStack_4a4,0,0x38);
      local_498 = awStack_440;
      local_4a8 = 0x3c;
      local_48c = 1;
      local_4a0 = param_2;
      local_494 = _Str;
      iVar3 = ShellExecuteEx(&local_4a8);
      hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
      SetCursor(hCursor);
      if (iVar3 == 0) {
        pHVar2 = GetDlgItem(param_2,0x3f5);
        SendMessageW(param_2,0x28,(WPARAM)pHVar2,1);
        goto LAB_0002ed9c;
      }
      pHVar2 = GetDlgItem(param_2,0x3f5);
      FUN_0002e620(param_1,pHVar2,(LPARAM)&local_238);
    }
    else if (uVar8 != 2) {
      if (uVar8 == 0x3f5) {
        if (param_4 >> 0x10 == 5) {
          GetDlgItemTextW(param_2,0x3f5,&local_238,0x104);
          sVar1 = wcslen(&local_238);
          uVar8 = (uint)(sVar1 != 0);
          pHVar2 = GetDlgItem(param_2,1);
        }
        else {
          if (param_4 >> 0x10 != 9) goto LAB_0002ed9c;
          pHVar2 = GetDlgItem(param_2,1);
          uVar8 = 1;
        }
        EnableWindow(pHVar2,uVar8);
      }
      else if (uVar8 == 0x3f7) {
        hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0002e7d4,param_2,0,(LPDWORD)0x0);
        CloseHandle(hObject);
      }
      goto LAB_0002ed9c;
    }
    pHVar4 = ImmGetContext(param_2);
    if (pHVar4 != (HIMC)0x0) {
      BVar5 = ImmGetOpenStatus(pHVar4);
      if (BVar5 != 0) {
        BVar5 = ImmSetCompositionStringW(pHVar4,9,&DAT_000129c8,0,(LPVOID)0x0,0);
        dwIndex = 1;
        if (BVar5 == 0) {
          dwIndex = 4;
        }
        ImmNotifyIME(pHVar4,0x15,dwIndex,0);
      }
      ImmReleaseContext(param_2,pHVar4);
    }
    DestroyWindow(param_2);
    *(undefined4 *)(param_1 + 0x14) = 0;
    if ((uVar8 == 2) && (*(int *)(param_1 + 0x4c) == 0)) {
      SetFocus(*(HWND *)(param_1 + 8));
    }
  }
LAB_0002ed9c:
  FUN_00033770(local_30);
  return 0;
}



/* 0002eed4 FUN_0002eed4 */

/* Boundary evidence: original MIPS .pdata 0002eed4..0002ef1b. Semantic name remains unreviewed. */

undefined4 FUN_0002eed4(HWND param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (DAT_0003556c == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0002e9e0(DAT_0003556c,param_1,param_2,param_3);
  }
  return uVar1;
}



/* 0002ef1c FUN_0002ef1c */

/* Boundary evidence: original MIPS .pdata 0002ef1c..0002efbf. Semantic name remains unreviewed. */

undefined4 FUN_0002ef1c(int param_1)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  HWND pHVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    hResInfo = FindResourceW(DAT_00035560,(LPCWSTR)0x3eb,(LPCWSTR)0x5);
    lpTemplate = LoadResource(DAT_00035560,hResInfo);
    pHVar1 = CreateDialogIndirectParamW(DAT_00035560,lpTemplate,(HWND)0x0,FUN_0002eed4,param_1);
    *(HWND *)(param_1 + 0x14) = pHVar1;
  }
  SetForegroundWindow(*(HWND *)(param_1 + 0x14));
  ShowWindow(*(HWND *)(param_1 + 0x14),5);
  UpdateWindow(*(HWND *)(param_1 + 0x14));
  return 1;
}



/* 0002efc0 FUN_0002efc0 */

/* Boundary evidence: original MIPS .pdata 0002efc0..0002f023. Semantic name remains unreviewed. */

undefined4 *
FUN_0002efc0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            STRSAFE_LPCWSTR param_9)

{
  FUN_0002fa6c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  *param_1 = &PTR_FUN_000129cc;
  param_1[0x8a] = 0;
  return param_1;
}



/* 0002f024 FUN_0002f024 */

undefined4 FUN_0002f024(void)

{
  return 0;
}



/* 0002f02c FUN_0002f02c */

/* Boundary evidence: original MIPS .pdata 0002f02c..0002f083. Semantic name remains unreviewed. */

undefined4 * FUN_0002f02c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000129cc;
  FUN_0002fb0c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0002f084 FUN_0002f084 */

/* Boundary evidence: original MIPS .pdata 0002f084..0002f117. Semantic name remains unreviewed. */

undefined4 *
FUN_0002f084(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  HANDLE pvVar1;
  
  FUN_0002efc0(param_1,0,4,param_2,param_3,param_4,param_5,0xfffffffb,L"");
  *param_1 = &PTR_FUN_000129e0;
  pvVar1 = LoadImageW(DAT_00035560,(LPCWSTR)0x4b7,1,0x10,0x10,0);
  param_1[1] = pvVar1;
  return param_1;
}



/* 0002f118 FUN_0002f118 */

/* Boundary evidence: original MIPS .pdata 0002f118..0002f167. Semantic name remains unreviewed. */

void FUN_0002f118(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000129e0;
  if ((HICON)param_1[1] != (HICON)0x0) {
    DestroyIcon((HICON)param_1[1]);
  }
  *param_1 = &PTR_FUN_000129cc;
  FUN_0002fb0c(param_1);
  return;
}



/* 0002f168 FUN_0002f168 */

/* Boundary evidence: original MIPS .pdata 0002f168..0002f203. Semantic name remains unreviewed. */

undefined4 FUN_0002f168(undefined4 param_1,HWND param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_0003556c != (int *)0x0) {
    iVar2 = (param_3 & 0xffff) - 0xa200;
    if (iVar2 < DAT_0003556c[0x2d] + DAT_0003556c[0x2b]) {
      if ((param_3 & 0xffff) == 0xa1ff) {
        FUN_00026904(DAT_0003556c,param_2,0,1,(undefined4 *)0x0);
        return 1;
      }
      if (0 < iVar2) {
        uVar1 = FUN_00026904(DAT_0003556c,param_2,iVar2,1,(undefined4 *)0x0);
        return uVar1;
      }
    }
  }
  return 0;
}



/* 0002f204 FUN_0002f204 */

/* Boundary evidence: original MIPS .pdata 0002f204..0002f4bf. Semantic name remains unreviewed. */

undefined4 FUN_0002f204(undefined4 param_1,HMENU param_2)

{
  undefined4 uVar1;
  BOOL BVar2;
  int iVar3;
  STRSAFE_LPWSTR pszDest;
  size_t sVar4;
  HRESULT HVar5;
  int *piVar6;
  LPWSTR lpBuffer;
  wchar_t *_Str;
  UINT_PTR uIDNewItem;
  UINT uPosition;
  tagMENUITEMINFOW local_58;
  
  if (DAT_0003556c == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    local_58.cbSize = 0x2c;
    uPosition = 0;
    local_58.fMask = 0x22;
    uIDNewItem = DAT_0003556c[0x2d] + DAT_0003556c[0x2b] + 0xa1ff;
    while (BVar2 = GetMenuItemInfoW(param_2,0,0x400,&local_58), BVar2 != 0) {
      DeleteMenu(param_2,0,0x400);
      if ((local_58.wID != 0xce8) && ((void *)local_58.dwItemData != (void *)0x0)) {
        operator_delete((void *)local_58.dwItemData);
      }
    }
    for (iVar3 = FUN_0002514c(DAT_0003556c,0); iVar3 != 0; iVar3 = FUN_0002514c(DAT_0003556c,iVar3))
    {
      if (*(int *)(iVar3 + 0x14) <= *(int *)(iVar3 + 0xc)) {
        pszDest = operator_new(0xb8);
        if (pszDest == (STRSAFE_LPWSTR)0x0) {
          pszDest = (STRSAFE_LPWSTR)0x0;
        }
        else {
          *pszDest = L'\0';
          pszDest[0x54] = L'\0';
          pszDest[0x55] = L'\0';
          pszDest[0x56] = L'\0';
          pszDest[0x57] = L'\0';
          pszDest[0x58] = L'\0';
          pszDest[0x59] = L'\0';
          pszDest[0x5a] = L'\0';
          pszDest[0x5b] = L'\0';
        }
        if (pszDest != (STRSAFE_LPWSTR)0x0) {
          _Str = (wchar_t *)(iVar3 + 0x20);
          *(undefined4 *)(pszDest + 0x54) = *(undefined4 *)(iVar3 + 4);
          *(undefined4 *)(pszDest + 0x56) = *(undefined4 *)(iVar3 + 0x1c);
          sVar4 = wcslen(_Str);
          HVar5 = StringCchCopyW(pszDest,0x51,_Str);
          if ((HVar5 == 0) &&
             ((((int)sVar4 < 0x51 || (HVar5 = StringCchCatW(pszDest,0x54,L"..."), HVar5 == 0)) ||
              (HVar5 = StringCchCopyW(pszDest,0x51,_Str), HVar5 == 0)))) {
            InsertMenuW(param_2,uPosition,0x500,uIDNewItem,pszDest);
            uPosition = uPosition + 1;
            uIDNewItem = uIDNewItem - 1;
          }
          else {
            operator_delete(pszDest);
          }
        }
      }
    }
    if (DAT_0003556c[0x21] == 0) {
      piVar6 = FUN_00023388(DAT_0003556c,DAT_0003556c[2],-3);
      lpBuffer = operator_new(0xb8);
      if (lpBuffer == (LPWSTR)0x0) {
        lpBuffer = (LPWSTR)0x0;
      }
      else {
        *lpBuffer = L'\0';
        lpBuffer[0x54] = L'\0';
        lpBuffer[0x55] = L'\0';
        lpBuffer[0x56] = L'\0';
        lpBuffer[0x57] = L'\0';
        lpBuffer[0x58] = L'\0';
        lpBuffer[0x59] = L'\0';
        lpBuffer[0x5a] = L'\0';
        lpBuffer[0x5b] = L'\0';
      }
      if (lpBuffer != (LPWSTR)0x0) {
        *(undefined4 *)(lpBuffer + 0x54) = *(undefined4 *)(piVar6[2] + 4);
        *(undefined4 *)(lpBuffer + 0x56) = *(undefined4 *)(piVar6[2] + 0x1c);
        LoadStringW(DAT_00035560,0x527b,lpBuffer,0x54);
        InsertMenuW(param_2,uPosition,0x500,0xa1ff,lpBuffer);
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 0002f4c0 FUN_0002f4c0 */

/* Boundary evidence: original MIPS .pdata 0002f4c0..0002f657. Semantic name remains unreviewed. */

undefined4 FUN_0002f4c0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  DWORD DVar2;
  HBRUSH hbr;
  size_t cchText;
  int nIndex;
  wchar_t *_Str;
  RECT local_30;
  tagRECT local_20;
  
  if ((param_2 == 0) || (_Str = *(wchar_t **)(param_2 + 0x2c), _Str == (wchar_t *)0x0)) {
    uVar1 = 0;
  }
  else {
    local_30.left = *(int *)(param_2 + 0x1c);
    local_30.top = *(int *)(param_2 + 0x20);
    local_30.right = *(LONG *)(param_2 + 0x24);
    local_30.bottom = *(LONG *)(param_2 + 0x28);
    if ((*(uint *)(param_2 + 0xc) != 0) && (*(uint *)(param_2 + 0xc) < 3)) {
      if (((*(uint *)(param_2 + 0x10) & 1) == 0) || (*(int *)(param_2 + 8) == 0)) {
        DVar2 = GetSysColor(0x40000004);
        hbr = CreateSolidBrush(DVar2);
        nIndex = 0x40000007;
      }
      else {
        DVar2 = GetSysColor(0x4000000d);
        hbr = CreateSolidBrush(DVar2);
        nIndex = 0x4000000e;
      }
      DVar2 = GetSysColor(nIndex);
      SetTextColor(*(HDC *)(param_2 + 0x18),DVar2);
      FillRect(*(HDC *)(param_2 + 0x18),&local_30,hbr);
      DeleteObject(hbr);
    }
    local_20.right = local_30.right;
    local_20.bottom = local_30.bottom;
    if (*(int *)(param_2 + 8) != 0) {
      local_20.left = local_30.left;
      local_20.top = local_30.top;
      if (*(HICON *)(_Str + 0x54) != (HICON)0x0) {
        DrawIconEx(*(HDC *)(param_2 + 0x18),local_30.left + 4,local_30.top + 3,
                   *(HICON *)(_Str + 0x54),0x10,0x10,0,(HBRUSH)0x0,3);
      }
      local_20.left = local_20.left + 0x18;
      cchText = wcslen(_Str);
      DrawTextW(*(HDC *)(param_2 + 0x18),_Str,cchText,&local_20,0x8924);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 0002f658 FUN_0002f658 */

/* Boundary evidence: original MIPS .pdata 0002f658..0002f797. Semantic name remains unreviewed. */

undefined4 FUN_0002f658(undefined4 param_1,int param_2)

{
  int iVar1;
  HDC hdc;
  size_t cchString;
  wchar_t *_Str;
  tagSIZE local_20;
  
  _Str = *(wchar_t **)(param_2 + 0x14);
  if ((_Str[0x5a] == L'\0') || ((ushort)_Str[0x5b] == 0)) {
    local_20.cx = 0x5e;
    local_20.cy = 0;
    if (*(int *)(param_2 + 8) == 0) {
      *(undefined4 *)(param_2 + 0x10) = 7;
    }
    else {
      iVar1 = GetSystemMetrics(0x32);
      *(int *)(param_2 + 0x10) = iVar1 + 6;
    }
    hdc = GetDC((HWND)0x0);
    cchString = wcslen(_Str);
    GetTextExtentExPointW(hdc,_Str,cchString,200,(LPINT)0x0,(LPINT)0x0,&local_20);
    if (200 < local_20.cx) {
      local_20.cx = 200;
    }
    ReleaseDC((HWND)0x0,hdc);
    iVar1 = GetSystemMetrics(0x32);
    if (iVar1 < local_20.cy) {
      *(LONG *)(param_2 + 0x10) = local_20.cy + 10;
    }
    iVar1 = GetSystemMetrics(0x31);
    *(int *)(param_2 + 0xc) = iVar1 + local_20.cx + 8;
    _Str[0x5b] = (wchar_t)*(undefined4 *)(param_2 + 0x10);
    _Str[0x5a] = (wchar_t)*(undefined4 *)(param_2 + 0xc);
  }
  else {
    *(uint *)(param_2 + 0x10) = (uint)(ushort)_Str[0x5b];
    *(uint *)(param_2 + 0xc) = (uint)(ushort)_Str[0x5a];
  }
  return 1;
}



/* 0002f798 FUN_0002f798 */

/* Boundary evidence: original MIPS .pdata 0002f798..0002f7e3. Semantic name remains unreviewed. */

undefined4 FUN_0002f798(undefined4 param_1,LPWSTR param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_2 == (LPWSTR)0x0) || (param_3 < 3)) {
    uVar1 = 0;
  }
  else {
    LoadStringW(DAT_00035560,0x5280,param_2,param_3 + -1);
    uVar1 = 1;
  }
  return uVar1;
}



/* 0002f7e4 FUN_0002f7e4 */

/* Boundary evidence: original MIPS .pdata 0002f7e4..0002f82f. Semantic name remains unreviewed. */

undefined4 * FUN_0002f7e4(undefined4 *param_1,uint param_2)

{
  FUN_0002f118(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0002f830 FUN_0002f830 */

/* Boundary evidence: original MIPS .pdata 0002f830..0002f9cf. Semantic name remains unreviewed. */

void FUN_0002f830(int *param_1,HWND param_2,int param_3,int param_4)

{
  HMENU pHVar1;
  HDC hDC;
  BOOL BVar2;
  tagPOINT local_res8;
  tagMENUITEMINFOW local_48;
  
  if (param_2 != (HWND)0x0) {
    local_res8.x = param_3;
    local_res8.y = param_4;
    if (param_1[0x8a] == 0) {
      ClientToScreen(param_2,&local_res8);
      pHVar1 = LoadMenuW(DAT_00035560,(LPCWSTR)0x6f);
      if ((pHVar1 != (HMENU)0x0) && (pHVar1 = GetSubMenu(pHVar1,0), pHVar1 != (HMENU)0x0)) {
        param_1[0x8a] = 1;
        hDC = GetDC(param_2);
        (**(code **)(*param_1 + 4))(param_1,param_2,hDC,0,1,1);
        TrackPopupMenuEx(pHVar1,0x20,local_res8.x + -4,local_res8.y,param_2,(LPTPMPARAMS)0x0);
        (**(code **)(*param_1 + 4))(param_1,param_2,hDC,0,1,0);
        ReleaseDC(param_2,hDC);
        param_1[0x8a] = 0;
        local_48.cbSize = 0x2c;
        local_48.fMask = 0x22;
        while (BVar2 = GetMenuItemInfoW(pHVar1,0,0x400,&local_48), BVar2 != 0) {
          DeleteMenu(pHVar1,0,0x400);
          if ((local_48.wID != 0xce8) && ((void *)local_48.dwItemData != (void *)0x0)) {
            operator_delete((void *)local_48.dwItemData);
          }
        }
        DestroyMenu(pHVar1);
      }
    }
    else {
      SetCapture(param_2);
      ReleaseCapture();
    }
  }
  return;
}



/* 0002f9d0 FUN_0002f9d0 */

/* Boundary evidence: original MIPS .pdata 0002f9d0..0002fa6b. Semantic name remains unreviewed. */

undefined4 FUN_0002f9d0(int param_1,HWND param_2,int param_3,HMENU param_4,int param_5)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x228) != 0) || (param_3 == 0x111)) {
    if (param_3 == 0x2b) {
      uVar1 = FUN_0002f4c0(param_1,param_5);
      return uVar1;
    }
    if (param_3 == 0x2c) {
      uVar1 = FUN_0002f658(param_1,param_5);
      return uVar1;
    }
    if (param_3 == 0x111) {
      uVar1 = FUN_0002f168(param_1,param_2,(uint)param_4);
      return uVar1;
    }
    if (param_3 == 0x117) {
      uVar1 = FUN_0002f204(param_1,param_4);
      return uVar1;
    }
  }
  return 0;
}



/* 0002fa6c FUN_0002fa6c */

/* Boundary evidence: original MIPS .pdata 0002fa6c..0002fad7. Semantic name remains unreviewed. */

undefined4 *
FUN_0002fa6c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            STRSAFE_LPCWSTR param_9)

{
  *param_1 = &PTR_FUN_000129f4;
  param_1[2] = param_3;
  param_1[1] = param_2;
  param_1[3] = param_4;
  param_1[4] = param_5;
  param_1[5] = param_6;
  param_1[6] = param_7;
  param_1[7] = param_8;
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 8),0x104,param_9);
  return param_1;
}



/* 0002fad8 FUN_0002fad8 */

undefined4 * FUN_0002fad8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000129f4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  return param_1;
}



/* 0002fb0c FUN_0002fb0c */

void FUN_0002fb0c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000129f4;
  return;
}



/* 0002fb1c FUN_0002fb1c */

/* Boundary evidence: original MIPS .pdata 0002fb1c..0002fb7f. Semantic name remains unreviewed. */

void FUN_0002fb1c(int param_1,int param_2)

{
  if (param_2 != param_1) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
    StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x20),0x104,(STRSAFE_LPCWSTR)(param_2 + 0x20));
  }
  return;
}



/* 0002fb80 FUN_0002fb80 */

/* Boundary evidence: original MIPS .pdata 0002fb80..000300ef. Semantic name remains unreviewed. */

undefined4
FUN_0002fb80(int param_1,HWND param_2,HDC param_3,HGDIOBJ param_4,int param_5,int param_6)

{
  bool bVar1;
  HDC hDC;
  HDC hdc;
  UINT UVar2;
  DWORD DVar3;
  HRESULT HVar4;
  HWND pHVar5;
  LPRECT qrc;
  UINT grfFlags;
  HICON hIcon;
  int iVar6;
  int iVar7;
  UINT UVar8;
  int iVar9;
  HGDIOBJ h;
  tagRECT local_288;
  size_t local_278;
  HBRUSH local_274;
  int local_270;
  HWND local_26c;
  HDC local_268;
  COLORREF local_264;
  HGDIOBJ local_260;
  HBITMAP local_25c;
  tagRECT local_258;
  tagSIZE local_248;
  wchar_t awStack_240 [264];
  uint local_30;
  
  local_30 = DAT_00035518;
  local_26c = param_2;
  local_268 = param_3;
  if (*(int *)(param_1 + 0x14) < ((RECT *)(param_1 + 0xc))->left) goto LAB_000300b4;
  iVar9 = 1;
  h = (HGDIOBJ)0x0;
  UVar8 = 10;
  if (param_6 == 0) {
    UVar8 = 5;
  }
  local_274 = GetSysColorBrush(0x4000000f);
  iVar6 = *(int *)(param_1 + 0x1c);
  if ((((iVar6 == 0) || (iVar6 == -5)) || (iVar6 == -4)) || (bVar1 = false, param_5 != 0)) {
    bVar1 = true;
  }
  if ((*(uint *)(param_1 + 8) & 0x20) != 0) {
    if (bVar1) {
      local_274 = DAT_00035600;
    }
    UVar8 = 10;
  }
  local_270 = GetSystemMetrics(0x2d);
  CopyRect(&local_288,(RECT *)(param_1 + 0xc));
  OffsetRect(&local_288,-local_288.left,-local_288.top);
  iVar6 = (local_288.bottom - local_288.top) + -0x10;
  if (iVar6 < 0) {
    iVar6 = (local_288.bottom - local_288.top) + -0xf;
  }
  iVar6 = (iVar6 >> 1) - local_270;
  hdc = CreateCompatibleDC(param_3);
  UVar2 = GetDeviceCaps(local_268,0xc);
  local_25c = CreateBitmap(local_288.right - local_288.left,local_288.bottom - local_288.top,1,UVar2
                           ,(void *)0x0);
  local_260 = SelectObject(hdc,local_25c);
  SelectObject(hdc,local_274);
  DVar3 = GetSysColor(0x40000014);
  local_274 = (HBRUSH)SetTextColor(hdc,DVar3);
  DVar3 = GetSysColor(0x4000000f);
  local_264 = SetBkColor(hdc,DVar3);
  PatBlt(hdc,local_288.left,local_288.top,local_288.right - local_288.left,
         local_288.bottom - local_288.top,0xf00021);
  if ((param_5 == 0) || (bVar1)) {
    GetClientRect(local_26c,&local_258);
    local_258.left = local_288.left;
    local_258.right = local_288.right;
    if (param_5 == 0) {
      grfFlags = 0x100f;
      UVar2 = UVar8;
LAB_0002fe28:
      qrc = &local_288;
    }
    else {
      if (!bVar1) {
LAB_0002fe14:
        grfFlags = 0xf;
        UVar2 = 6;
        goto LAB_0002fe28;
      }
      iVar7 = *(int *)(param_1 + 0x1c);
      if (iVar7 == 0) {
        grfFlags = 4;
      }
      else {
        if ((iVar7 != -5) && (iVar7 != -4)) goto LAB_0002fe14;
        grfFlags = 1;
      }
      UVar2 = 6;
      qrc = &local_258;
    }
    DrawEdge(hdc,qrc,UVar2,grfFlags);
  }
  SetTextColor(hdc,(COLORREF)local_274);
  SetBkColor(hdc,local_264);
  InflateRect(&local_288,-local_270,-local_270);
  if ((param_5 == 0) && (UVar8 == 10)) {
    iVar9 = 2;
    iVar6 = iVar6 + 2;
  }
  hIcon = *(HICON *)(param_1 + 4);
  if (hIcon != (HICON)0x0) {
    if (hIcon == (HICON)0x80004005) {
      trap(0x400);
    }
    DrawIconEx(hdc,local_288.left + iVar9,local_288.top + iVar6,hIcon,0x10,0x10,0,(HBRUSH)0x0,3);
    local_288.left = local_288.left + 0x12;
  }
  local_288.left = local_288.left + iVar9;
  local_288.top = local_288.top + iVar6 + -2;
  StringCchCopyW(awStack_240,0x107,(STRSAFE_LPCWSTR)(param_1 + 0x20));
  if (param_4 != (HGDIOBJ)0x0) {
    h = SelectObject(hdc,param_4);
  }
  GetTextExtentExPointW(hdc,L"...",3,0,(LPINT)0x0,(LPINT)0x0,&local_248);
  iVar9 = FUN_0002cbe0(hdc,(STRSAFE_LPCWSTR)(param_1 + 0x20),&local_288.left,&local_278,local_248.cx
                      );
  if (iVar9 == 0) {
    HVar4 = StringCchLengthW(awStack_240,0x107,&local_278);
    if (HVar4 < 0) {
      local_278 = 0;
    }
  }
  else {
    StringCchCopyW(awStack_240 + local_278,0x107 - local_278,L"...");
    local_278 = local_278 + 3;
  }
  DVar3 = GetSysColor(0x40000012);
  SetTextColor(hdc,DVar3);
  SetBkMode(hdc,1);
  DrawTextW(hdc,awStack_240,local_278,&local_288,0x824);
  if (h != (HGDIOBJ)0x0) {
    SelectObject(hdc,h);
  }
  CopyRect(&local_288,(RECT *)(param_1 + 0xc));
  hDC = local_268;
  BitBlt(local_268,local_288.left,local_288.top,local_288.right - local_288.left,
         local_288.bottom - local_288.top,hdc,0,0,0xcc0020);
  if ((*(int *)(param_1 + 0x1c) == 0) && (pHVar5 = GetFocus(), pHVar5 == local_26c)) {
    InflateRect(&local_288,-3,-3);
    DrawFocusRect(hDC,&local_288);
  }
  SelectObject(hdc,local_260);
  DeleteDC(hdc);
  DeleteObject(local_25c);
LAB_000300b4:
  FUN_00033770(local_30);
  return 1;
}



/* 000300f0 FUN_000300f0 */

/* Boundary evidence: original MIPS .pdata 000300f0..00030167. Semantic name remains unreviewed. */

void FUN_000300f0(int param_1,HWND param_2,undefined4 param_3)

{
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  tagRECT tStack_20;
  
  GetWindowRect(param_2,&tStack_20);
  local_30 = *(undefined4 *)(param_1 + 0xc);
  local_2c = *(int *)(param_1 + 0x10) + tStack_20.top;
  local_28 = *(undefined4 *)(param_1 + 0x14);
  local_24 = *(int *)(param_1 + 0x18) + tStack_20.top;
  RectangleAnimation(*(undefined4 *)(param_1 + 0x1c),&local_30,param_3);
  return;
}



/* 00030168 FUN_00030168 */

/* Boundary evidence: original MIPS .pdata 00030168..000301bb. Semantic name remains unreviewed. */

undefined4 FUN_00030168(int param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  undefined4 uVar1;
  
  if (((*(STRSAFE_LPCWSTR)(param_1 + 0x20) == L'\0') || (param_2 == (STRSAFE_LPWSTR)0x0)) ||
     ((int)param_3 < 3)) {
    uVar1 = 0;
  }
  else {
    StringCchCopyW(param_2,param_3,(STRSAFE_LPCWSTR)(param_1 + 0x20));
    uVar1 = 1;
  }
  return uVar1;
}



/* 000301bc FUN_000301bc */

/* Boundary evidence: original MIPS .pdata 000301bc..000301ff. Semantic name remains unreviewed. */

undefined4 * FUN_000301bc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000129f4;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00030200 FUN_00030200 */

/* Boundary evidence: original MIPS .pdata 00030200..000302d3. Semantic name remains unreviewed. */

undefined4 * FUN_00030200(undefined4 *param_1,int param_2)

{
  HRESULT HVar1;
  undefined4 uVar2;
  
  FUN_0002fad8(param_1);
  *param_1 = &PTR_FUN_00012a00;
  uVar2 = *(undefined4 *)(param_2 + 0x14);
  param_1[2] = 0x40;
  param_1[1] = uVar2;
  param_1[7] = *(undefined4 *)(param_2 + 4);
  if ((*(uint *)(param_2 + 0xc) & 4) == 0) {
    *(undefined2 *)(param_1 + 8) = 0;
  }
  else {
    HVar1 = StringCbCopyW((STRSAFE_LPWSTR)(param_1 + 8),0x208,(STRSAFE_LPCWSTR)(param_2 + 0x18));
    if (HVar1 != 0) {
      *(wchar_t *)(param_1 + 8) = L'\0';
    }
  }
  param_1[0x8a] = *(undefined4 *)(param_2 + 8);
  param_1[0x8b] = *(undefined4 *)(param_2 + 0x10);
  return param_1;
}



/* 000302d4 FUN_000302d4 */

/* Boundary evidence: original MIPS .pdata 000302d4..00030343. Semantic name remains unreviewed. */

undefined4 *
FUN_000302d4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            STRSAFE_LPCWSTR param_9,undefined4 param_10,undefined4 param_11)

{
  FUN_0002fa6c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  *param_1 = &PTR_FUN_00012a00;
  param_1[0x8a] = param_10;
  param_1[0x8b] = param_11;
  return param_1;
}



/* 00030344 FUN_00030344 */

/* Boundary evidence: original MIPS .pdata 00030344..00030367. Semantic name remains unreviewed. */

void FUN_00030344(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00012a00;
  FUN_0002fb0c(param_1);
  return;
}



/* 00030368 FUN_00030368 */

/* Boundary evidence: original MIPS .pdata 00030368..0003045b. Semantic name remains unreviewed. */

undefined4 FUN_00030368(int param_1,int param_2)

{
  HRESULT HVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(param_2 + 0xc);
  if (((*puVar2 & 2) != 0) && (*(int *)(param_2 + 0x14) != 0)) {
    if (((*(uint *)(param_1 + 8) & 0x10000000) != 0) && (*(HICON *)(param_1 + 4) != (HICON)0x0)) {
      DestroyIcon(*(HICON *)(param_1 + 4));
    }
    *(int *)(param_1 + 4) = *(int *)(param_2 + 0x14);
  }
  if ((*puVar2 & 1) != 0) {
    *(undefined4 *)(param_1 + 0x22c) = *(undefined4 *)(param_2 + 0x10);
  }
  if ((*puVar2 & 4) != 0) {
    HVar1 = StringCbCopyW((STRSAFE_LPWSTR)(param_1 + 0x20),0x208,(STRSAFE_LPCWSTR)(param_2 + 0x18));
    if (HVar1 != 0) {
      *(STRSAFE_LPWSTR)(param_1 + 0x20) = L'\0';
    }
  }
  return 1;
}



/* 0003045c FUN_0003045c */

/* Boundary evidence: original MIPS .pdata 0003045c..0003052f. Semantic name remains unreviewed. */

undefined4 FUN_0003045c(int param_1,HWND param_2,HWND param_3,HDC param_4)

{
  int iVar1;
  int iVar2;
  tagRECT local_28;
  
  if (((RECT *)(param_1 + 0xc))->left < *(int *)(param_1 + 0x14)) {
    iVar1 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x10);
    iVar2 = iVar1 + -0x10;
    if (iVar2 < 0) {
      iVar2 = iVar1 + -0xf;
    }
    CopyRect(&local_28,(RECT *)(param_1 + 0xc));
    MapWindowPoints(param_2,param_3,(LPPOINT)&local_28,2);
    DrawIconEx(param_4,local_28.left,local_28.top + (iVar2 >> 1),*(HICON *)(param_1 + 4),0x10,0x10,0
               ,(HBRUSH)0x0,3);
  }
  return 1;
}



/* 00030530 FUN_00030530 */

/* Boundary evidence: original MIPS .pdata 00030530..00030587. Semantic name remains unreviewed. */

undefined4 * FUN_00030530(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00012a00;
  FUN_0002fb0c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00030588 FUN_00030588 */

/* Boundary evidence: original MIPS .pdata 00030588..0003065b. Semantic name remains unreviewed. */

undefined4 * FUN_00030588(undefined4 *param_1,HWND param_2)

{
  uint uVar1;
  int iVar2;
  
  FUN_0002fad8(param_1);
  *param_1 = &PTR_FUN_00012a10;
  param_1[7] = param_2;
  *(undefined1 *)(param_1 + 0x8a) = 0;
  *(undefined1 *)((int)param_1 + 0x229) = 0;
  *(undefined1 *)((int)param_1 + 0x22a) = 0;
  if (param_2 != (HWND)0x0) {
    uVar1 = GetWindowLongW(param_2,-0x14);
    *(bool *)((int)param_1 + 0x22a) = (uVar1 & 8) != 0;
    iVar2 = GetWindowTextWDirect(param_1[7],param_1 + 8,0x104);
    if (iVar2 == 0) {
      *(undefined2 *)(param_1 + 8) = 0;
    }
    param_1[2] = 4;
    iVar2 = SendMessageTimeout(param_1[7],0x7f,0,0,0,2000,param_1 + 1);
    if (iVar2 == 0) {
      param_1[1] = 0;
    }
  }
  return param_1;
}



/* 0003065c FUN_0003065c */

/* Boundary evidence: original MIPS .pdata 0003065c..000306b3. Semantic name remains unreviewed. */

undefined4 * FUN_0003065c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00012a10;
  FUN_0002fb0c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 000306b4 FUN_000306b4 */

/* Boundary evidence: original MIPS .pdata 000306b4..00030713. Semantic name remains unreviewed. */

void FUN_000306b4(undefined4 *param_1)

{
  if ((param_1 != (undefined4 *)0x0) && (((uint)*param_1 & 0xffff0000) != 0)) {
    FUN_00032680((HLOCAL)*param_1);
  }
  if ((HLOCAL)param_1[4] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[4]);
  }
  LocalFree(param_1);
  return;
}



/* 00030714 FUN_00030714 */

/* Boundary evidence: original MIPS .pdata 00030714..00030afb. Semantic name remains unreviewed. */

uint FUN_00030714(int param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  HANDLE hFindFile;
  int iVar6;
  HMODULE hInst;
  code *pcVar7;
  int iVar8;
  HANDLE pvVar9;
  BOOL BVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined1 local_640 [4];
  undefined1 auStack_63c [8];
  uint local_634;
  wchar_t awStack_62c [32];
  wchar_t awStack_5ec [194];
  _WIN32_FIND_DATAW _Stack_468;
  uint local_30;
  
  local_30 = DAT_00035518;
  uVar12 = 0;
  uVar13 = 0;
  uVar4 = GetSystemMetrics(0x31);
  uVar5 = GetSystemMetrics(0x32);
  hFindFile = FindFirstFileW(L"\\Windows\\*.cpl",&_Stack_468);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      bVar3 = false;
      uVar11 = 0;
      do {
        iVar6 = _wcsicmp(*(wchar_t **)((int)&PTR_u_connpnl_cpl_00012c08 + uVar11),
                         (wchar_t *)&_Stack_468.dwReserved1);
        if (iVar6 == 0) {
          bVar3 = true;
          break;
        }
        uVar11 = uVar11 + 4;
      } while (uVar11 < 4);
      wcscpy(_Stack_468.cFileName + 0x102,L"\\Windows\\");
      StringCchCatW(_Stack_468.cFileName + 0x102,0x104,(STRSAFE_LPCWSTR)&_Stack_468.dwReserved1);
      if (((!bVar3) && (hInst = LoadLibraryW(_Stack_468.cFileName + 0x102), hInst != (HMODULE)0x0))
         && (pcVar7 = (code *)GetProcAddressW(hInst,L"CPlApplet"), pcVar7 != (code *)0x0)) {
        (*pcVar7)(0,1,0,0);
        if (param_1 == 0) {
          iVar6 = (*pcVar7)(0,2,0,0);
          uVar12 = iVar6 + uVar12;
        }
        else if (((param_1 == 1) && (DAT_00035678 != 0)) &&
                ((uVar13 < DAT_00035678 && (DAT_0003567c != 0)))) {
          uVar12 = (*pcVar7)(0,2,0,0);
          uVar11 = 0;
          if (uVar12 != 0) {
            iVar6 = uVar13 * 0x460;
            do {
              puVar1 = local_640 + 3;
              uVar2 = (uint)puVar1 & 3;
              *(uint *)(puVar1 + -uVar2) =
                   *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
              puVar1 = auStack_63c + 3;
              uVar2 = (uint)puVar1 & 3;
              *(uint *)(puVar1 + -uVar2) =
                   *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
              local_640 = (undefined1  [4])0x0;
              auStack_63c._0_4_ = 0;
              iVar8 = (*pcVar7)(0,8,uVar11,local_640);
              if (iVar8 == -1) {
                DAT_00035678 = DAT_00035678 - 1;
              }
              else if (local_640 == (undefined1  [4])0x1d4) {
                if (local_634 == 0) {
                  *(undefined4 *)(iVar6 + DAT_0003567c + 0x454) = 0;
                }
                else {
                  pvVar9 = LoadImageW(hInst,(LPCWSTR)(local_634 & 0xffff),1,uVar4 & 0xffff,
                                      uVar5 & 0xffff,0);
                  *(HANDLE *)(iVar6 + DAT_0003567c + 0x454) = pvVar9;
                }
                *(HMODULE *)(iVar6 + DAT_0003567c + 0x458) = hInst;
                *(uint *)(iVar6 + DAT_0003567c + 0x450) = uVar11;
                wcscpy((wchar_t *)(iVar6 + DAT_0003567c),awStack_62c);
                wcscpy((wchar_t *)(iVar6 + DAT_0003567c + 0x40),awStack_5ec);
                wcscpy((wchar_t *)(iVar6 + DAT_0003567c + 0x248),_Stack_468.cFileName + 0x102);
                *(undefined4 *)(iVar6 + DAT_0003567c + 0x45c) = 0;
                uVar13 = uVar13 + 1;
                iVar6 = iVar6 + 0x460;
                (*pcVar7)(0,6,uVar11,local_634);
              }
              else {
                DAT_00035678 = DAT_00035678 - 1;
              }
              uVar11 = uVar11 + 1;
            } while (uVar11 < uVar12);
          }
        }
        (*pcVar7)(0,7,0,0);
        if (param_1 == 0) {
          FreeLibrary(hInst);
        }
      }
      BVar10 = FindNextFileW(hFindFile,&_Stack_468);
    } while (BVar10 != 0);
    FindClose(hFindFile);
  }
  FUN_00033770(local_30);
  return uVar12;
}



/* 00030afc FUN_00030afc */

/* Boundary evidence: original MIPS .pdata 00030afc..00030bbf. Semantic name remains unreviewed. */

UINT FUN_00030afc(HMENU param_1,wchar_t *param_2,UINT param_3)

{
  BOOL BVar1;
  int iVar2;
  UINT item;
  tagMENUITEMINFOW local_48;
  
  if ((int)param_3 < 0) {
    param_3 = FUN_0001564c(param_1);
  }
  local_48.cbSize = 0x2c;
  local_48.fMask = 0x30;
  local_48.fType = 0x100;
  local_48.hSubMenu = (HMENU)0x0;
  item = 0;
  if (0 < (int)param_3) {
    do {
      BVar1 = GetMenuItemInfoW(param_1,item,1,&local_48);
      if ((BVar1 != 0) &&
         (iVar2 = _wcsicmp(param_2,*(wchar_t **)(local_48.dwItemData + 4)), iVar2 < 0)) {
        return item;
      }
      item = item + 1;
    } while ((int)item < (int)param_3);
  }
  return 0xffffffff;
}



/* 00030bc0 FUN_00030bc0 */

/* Boundary evidence: original MIPS .pdata 00030bc0..00030d33. Semantic name remains unreviewed. */

HMENU FUN_00030bc0(void)

{
  uint uVar1;
  LPCWSTR lpNewItem;
  UINT uPosition;
  BOOL BVar2;
  HMENU hMenu;
  int iVar3;
  UINT UVar4;
  int iVar5;
  
  hMenu = (HMENU)0x0;
  DAT_00035678 = FUN_00030714(0);
  if (DAT_00035678 != 0) {
    DAT_0003567c = LocalAlloc(0x40,DAT_00035678 * 0x460);
    if (((DAT_0003567c != (HLOCAL)0x0) && (uVar1 = FUN_00030714(1), uVar1 != 0)) &&
       (hMenu = CreatePopupMenu(), hMenu != (HMENU)0x0)) {
      iVar5 = 0x21;
      UVar4 = 0;
      if (DAT_00035678 != 0) {
        iVar3 = 0;
        do {
          lpNewItem = LocalAlloc(0x40,0x1c);
          if (lpNewItem != (LPCWSTR)0x0) {
            *(int *)lpNewItem = iVar5;
            *(int *)(lpNewItem + 2) = iVar3 + (int)DAT_0003567c;
            *(undefined4 *)(lpNewItem + 4) = *(undefined4 *)((int)DAT_0003567c + iVar3 + 0x454);
            lpNewItem[6] = L'췯';
            lpNewItem[7] = L'\0';
            lpNewItem[8] = L'\0';
            lpNewItem[9] = L'\0';
            lpNewItem[10] = L'\0';
            lpNewItem[0xb] = L'\0';
            lpNewItem[0xc] = L'\0';
            lpNewItem[0xd] = L'\0';
            iVar5 = iVar5 + 1;
            uPosition = FUN_00030afc(hMenu,(wchar_t *)(iVar3 + (int)DAT_0003567c),UVar4);
            BVar2 = InsertMenuW(hMenu,uPosition,0x500,*(UINT_PTR *)lpNewItem,lpNewItem);
            if (BVar2 == 0) {
              LocalFree(lpNewItem);
            }
            else {
              *(LPCWSTR *)((int)DAT_0003567c + iVar3 + 0x45c) = lpNewItem;
            }
          }
          UVar4 = UVar4 + 1;
          iVar3 = iVar3 + 0x460;
        } while (UVar4 < DAT_00035678);
      }
    }
  }
  return hMenu;
}



/* 00030d34 FUN_00030d34 */

/* Boundary evidence: original MIPS .pdata 00030d34..00030e83. Semantic name remains unreviewed. */

HMENU FUN_00030d34(void)

{
  HMENU hMenu;
  DWORD DVar1;
  int iVar2;
  UINT uFlags;
  HMENU uIDNewItem;
  int iVar3;
  LPCWSTR lpNewItem;
  int local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_00035518;
  hMenu = CreatePopupMenu();
  if (hMenu != (HMENU)0x0) {
    lpNewItem = L"\x1e";
    iVar3 = 3;
    do {
      if (*(int *)lpNewItem == 0x20) {
        swprintf(awStack_230,0x12c40,L"\\Windows",0x5c,L"ConnMC.exe");
        DVar1 = GetFileAttributesW(awStack_230);
        if (DVar1 != 0xffffffff) goto LAB_00030de0;
      }
      else {
LAB_00030de0:
        uIDNewItem = *(HMENU *)lpNewItem;
        if (uIDNewItem == (HMENU)0x1e) {
          local_238[0] = 0;
          iVar2 = FUN_00022b48(DAT_0003556c,(LPBYTE)local_238);
          if ((iVar2 == 0) || (local_238[0] == 0)) {
            uIDNewItem = *(HMENU *)lpNewItem;
            goto LAB_00030e34;
          }
          uIDNewItem = FUN_00030bc0();
          if (uIDNewItem == (HMENU)0x0) goto LAB_00030e44;
          uFlags = 0x110;
        }
        else {
LAB_00030e34:
          uFlags = 0x100;
        }
        AppendMenuW(hMenu,uFlags,(UINT_PTR)uIDNewItem,lpNewItem);
      }
LAB_00030e44:
      iVar3 = iVar3 + -1;
      lpNewItem = lpNewItem + 0xe;
    } while (iVar3 != 0);
  }
  FUN_00033770(local_28);
  return hMenu;
}



/* 00030e84 FUN_00030e84 */

/* Boundary evidence: original MIPS .pdata 00030e84..000310fb. Semantic name remains unreviewed. */

HMENU FUN_00030e84(void)

{
  HMENU hMenu;
  HMENU hMenu_00;
  DWORD DVar1;
  LSTATUS LVar2;
  HRESULT HVar3;
  HMENU uIDNewItem;
  UINT uFlags;
  int csidl;
  LPCWSTR pWVar4;
  LPCWSTR pWVar5;
  int iVar6;
  HKEY local_38;
  int local_34 [2];
  LPITEMIDLIST local_2c;
  
  hMenu = FUN_00030d34();
  if (hMenu != (HMENU)0x0) {
    hMenu_00 = CreatePopupMenu();
    if (hMenu_00 != (HMENU)0x0) {
      pWVar5 = L"\r";
      iVar6 = 8;
      do {
        if ((*(int *)pWVar5 != 0x11) ||
           (DVar1 = GetFileAttributesW(L"\\Windows\\peghelp.exe"), DVar1 != 0xffffffff)) {
          if ((*(int *)pWVar5 == 0x13) || (*(int *)pWVar5 == 0)) {
            local_34[0] = 1;
            local_34[1] = 4;
            LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Explorer",0,0x20019,&local_38);
            if (LVar2 == 0) {
              RegQueryValueExW(local_38,L"Suspend",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_34,
                               (LPDWORD)(local_34 + 1));
              RegCloseKey(local_38);
            }
            if (local_34[0] == 0) goto LAB_000310a0;
          }
          if (DAT_00035654 == 0) {
            DAT_00035654 = *(int *)pWVar5;
          }
          DAT_00035660 = *(HMENU *)pWVar5;
          if (*(int *)(pWVar5 + 4) == 0) {
            pWVar4 = (LPCWSTR)0x0;
            uIDNewItem = (HMENU)0x0;
            uFlags = 0x800;
          }
          else {
            uIDNewItem = hMenu;
            pWVar4 = pWVar5;
            if (DAT_00035660 != (HMENU)0xf) {
              csidl = *(int *)(pWVar5 + 6);
              if ((csidl == 0) || (csidl == 0xffff)) {
                uFlags = 0x100;
                uIDNewItem = DAT_00035660;
                goto LAB_00031098;
              }
              HVar3 = SHGetSpecialFolderLocation((HWND)0x0,csidl,&local_2c);
              if (HVar3 < 0) goto LAB_000310a0;
              uIDNewItem = FUN_00032c20(local_2c);
            }
            uFlags = 0x110;
          }
LAB_00031098:
          AppendMenuW(hMenu_00,uFlags,(UINT_PTR)uIDNewItem,pWVar4);
        }
LAB_000310a0:
        pWVar5 = pWVar5 + 0xe;
        iVar6 = iVar6 + -1;
        if (iVar6 == 0) {
          DAT_00035650 = 0;
          DAT_00035658 = 0;
          DAT_0003565c = 0;
          return hMenu_00;
        }
      } while( true );
    }
    FUN_00032884(hMenu);
    DestroyMenu(hMenu);
  }
  return (HMENU)0x0;
}



/* 000310fc FUN_000310fc */

/* Boundary evidence: original MIPS .pdata 000310fc..00031207. Semantic name remains unreviewed. */

void FUN_000310fc(void)

{
  HMODULE hLibModule;
  int iVar1;
  uint uVar2;
  HMODULE pHVar3;
  
  if (DAT_00035650 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00035650);
    DAT_00035650 = (HGDIOBJ)0x0;
  }
  FUN_00032884(DAT_00035664);
  DestroyMenu(DAT_00035664);
  DAT_00035664 = (HMENU)0x0;
  if (DAT_0003567c != (HLOCAL)0x0) {
    hLibModule = *(HMODULE *)((int)DAT_0003567c + 0x458);
    uVar2 = 0;
    if (DAT_00035678 != 0) {
      iVar1 = 0;
      do {
        DestroyIcon(*(HICON *)((int)DAT_0003567c + iVar1 + 0x454));
        pHVar3 = *(HMODULE *)((int)DAT_0003567c + iVar1 + 0x458);
        if (pHVar3 != hLibModule) {
          FreeLibrary(hLibModule);
          hLibModule = pHVar3;
        }
        uVar2 = uVar2 + 1;
        iVar1 = iVar1 + 0x460;
      } while (uVar2 < DAT_00035678);
    }
    LocalFree(DAT_0003567c);
    DAT_0003567c = (HLOCAL)0x0;
    DAT_00035678 = 0;
  }
  return;
}



/* 00031208 FUN_00031208 */

/* Boundary evidence: original MIPS .pdata 00031208..0003141b. Semantic name remains unreviewed. */

undefined4 FUN_00031208(int param_1)

{
  int iVar1;
  HDC hdc;
  size_t cchString;
  UINT uID;
  uint *puVar2;
  wchar_t *pwVar3;
  tagSIZE local_230;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_00035518;
  if ((param_1 == 0) || (puVar2 = *(uint **)(param_1 + 0x14), puVar2 == (uint *)0x0)) {
    FUN_00033770(DAT_00035518);
    return 0;
  }
  if ((puVar2[5] != 0) && (puVar2[6] != 0)) {
    *(uint *)(param_1 + 0x10) = puVar2[6];
    *(uint *)(param_1 + 0xc) = puVar2[5];
    goto LAB_000313f0;
  }
  local_230.cx = 0x5e;
  local_230.cy = 0;
  if (*puVar2 == 0) {
    *(undefined4 *)(param_1 + 0x10) = 7;
  }
  else {
    iVar1 = GetSystemMetrics(0x32);
    *(int *)(param_1 + 0x10) = iVar1 + 6;
  }
  pwVar3 = awStack_228;
  if ((*puVar2 & 0xffff0000) == 0) {
    if (puVar2[3] != 0xcdef) {
      uID = puVar2[1];
      goto LAB_0003130c;
    }
    pwVar3 = (wchar_t *)puVar2[1];
  }
  else if (*puVar2 == 0xffff) {
    uID = 0x4e24;
LAB_0003130c:
    LoadStringW(DAT_00035560,uID,awStack_228,0x104);
  }
  else if ((wchar_t *)puVar2[4] != (wchar_t *)0x0) {
    pwVar3 = (wchar_t *)puVar2[4];
  }
  hdc = GetDC((HWND)0x0);
  cchString = wcslen(pwVar3);
  GetTextExtentExPointW(hdc,pwVar3,cchString,200,(LPINT)0x0,(LPINT)0x0,&local_230);
  if (200 < local_230.cx) {
    local_230.cx = 200;
  }
  ReleaseDC((HWND)0x0,hdc);
  iVar1 = GetSystemMetrics(0x32);
  if (iVar1 < local_230.cy) {
    *(LONG *)(param_1 + 0x10) = local_230.cy + 10;
  }
  iVar1 = GetSystemMetrics(0x31);
  iVar1 = iVar1 + local_230.cx + 0x10;
  *(int *)(param_1 + 0xc) = iVar1;
  if ((int)*puVar2 < 0x15) {
    *(int *)(param_1 + 0xc) = iVar1 + DAT_00035658;
  }
  if (puVar2[4] != 0) {
    puVar2[6] = *(uint *)(param_1 + 0x10);
    puVar2[5] = *(uint *)(param_1 + 0xc);
  }
LAB_000313f0:
  FUN_00033770(local_20);
  return 1;
}



/* 0003141c FUN_0003141c */

/* Boundary evidence: original MIPS .pdata 0003141c..0003199b. Semantic name remains unreviewed. */

undefined4 FUN_0003141c(int param_1)

{
  HINSTANCE hInstance;
  HDC hdc;
  DWORD DVar1;
  HBRUSH pHVar2;
  wchar_t *pwVar3;
  size_t sVar4;
  int iVar5;
  HIMAGELIST himl;
  uint *puVar6;
  int *piVar7;
  HICON hIcon;
  undefined4 uVar8;
  size_t local_528 [2];
  tagRECT local_520;
  tagRECT local_510;
  tagSIZE local_500;
  int local_4f8;
  int local_4f4;
  undefined1 auStack_4f0 [4];
  int local_4ec;
  undefined1 auStack_238 [520];
  uint local_30;
  
  hInstance = DAT_00035560;
  local_30 = DAT_00035518;
  if ((param_1 == 0) || (piVar7 = *(int **)(param_1 + 0x2c), piVar7 == (int *)0x0)) {
LAB_00031460:
    FUN_00033770(local_30);
    uVar8 = 0;
  }
  else {
    CopyRect(&local_510,(RECT *)(param_1 + 0x1c));
    if (*piVar7 < 0x15) {
      local_510.left = DAT_00035658 + local_510.left;
    }
    uVar8 = 1;
    if (*(int *)(param_1 + 0xc) == 1) {
      if (DAT_00035654 == *piVar7) {
        CopyRect((LPRECT)&DAT_00035668,(RECT *)(param_1 + 0x1c));
        DAT_00035670 = DAT_00035668 + DAT_00035658;
      }
      else if (((DAT_00035660 == *piVar7) &&
               (DAT_00035674 = *(int *)(param_1 + 0x28), DAT_00035650 != (HGDIOBJ)0x0)) &&
              (hdc = CreateCompatibleDC(*(HDC *)(param_1 + 0x18)), hdc != (HDC)0x0)) {
        SelectObject(hdc,DAT_00035650);
        pHVar2 = GetSysColorBrush(0x40000002);
        FillRect(*(HDC *)(param_1 + 0x18),(RECT *)&DAT_00035668,pHVar2);
        BitBlt(*(HDC *)(param_1 + 0x18),0,DAT_00035674 - DAT_0003565c,DAT_00035658,DAT_0003565c,hdc,
               0,0,0xcc0020);
        DeleteDC(hdc);
      }
LAB_00031598:
      if (((*(uint *)(param_1 + 0x10) & 1) == 0) || (*piVar7 == 0)) {
        DVar1 = GetSysColor(0x40000004);
        pHVar2 = CreateSolidBrush(DVar1);
        iVar5 = 0x40000007;
      }
      else {
        DVar1 = GetSysColor(0x4000000d);
        pHVar2 = CreateSolidBrush(DVar1);
        iVar5 = 0x4000000e;
      }
      DVar1 = GetSysColor(iVar5);
      SetTextColor(*(HDC *)(param_1 + 0x18),DVar1);
      FillRect(*(HDC *)(param_1 + 0x18),&local_510,pHVar2);
      DeleteObject(pHVar2);
    }
    else if (*(int *)(param_1 + 0xc) == 2) goto LAB_00031598;
    puVar6 = *(uint **)(param_1 + 0x2c);
    local_520.left = local_510.left;
    local_520.top = local_510.top;
    local_520.right = local_510.right;
    local_520.bottom = local_510.bottom;
    if ((puVar6 == (uint *)0x0) || ((*puVar6 & 0xffff0000) == 0)) {
      if (*piVar7 == 0) {
        local_500.cy = local_510.top + 3;
        local_4f8 = local_510.right + -3;
        local_500.cx = local_510.left;
        local_4f4 = local_500.cy;
        Polyline(*(HDC *)(param_1 + 0x18),(POINT *)&local_500,2);
      }
      else {
        SetBkMode(*(HDC *)(param_1 + 0x18),1);
        hIcon = (HICON)piVar7[2];
        if (hIcon == (HICON)0x0) {
          hIcon = (HICON)0x0;
        }
        else {
          if (piVar7[3] != 0xcdef) {
            hIcon = LoadImageW(DAT_00035560,(LPCWSTR)((uint)hIcon & 0xffff),1,0x10,0x10,0);
          }
          DrawIconEx(*(HDC *)(param_1 + 0x18),local_510.left + 4,local_510.top + 3,hIcon,0x10,0x10,0
                     ,(HBRUSH)0x0,3);
        }
        OffsetRect(&local_520,0x18,0);
        if (piVar7[3] == 0xcdef) {
          pwVar3 = (wchar_t *)piVar7[1];
          sVar4 = wcslen(pwVar3);
          DrawTextW(*(HDC *)(param_1 + 0x18),pwVar3,sVar4,&local_520,0x924);
        }
        else {
          pwVar3 = (wchar_t *)LoadStringW(hInstance,piVar7[1],(LPWSTR)0x0,0);
          if (pwVar3 == (wchar_t *)0x0) goto LAB_00031460;
          sVar4 = wcslen(pwVar3);
          DrawTextW(*(HDC *)(param_1 + 0x18),pwVar3,sVar4,&local_520,0x124);
        }
        if ((hIcon != (HICON)0x0) && (piVar7[3] != 0xcdef)) {
          DestroyIcon(hIcon);
        }
      }
    }
    else if (*puVar6 == 0xffff) {
      pwVar3 = (wchar_t *)LoadStringW(hInstance,0x4e24,(LPWSTR)0x0,0);
      if (pwVar3 == (wchar_t *)0x0) goto LAB_00031460;
      sVar4 = wcslen(pwVar3);
      DrawTextW(*(HDC *)(param_1 + 0x18),pwVar3,sVar4,&local_520,0x124);
    }
    else {
      iVar5 = SHGetPathFromIDList(*puVar6,auStack_238);
      if (iVar5 != 0) {
        himl = (HIMAGELIST)SHGetFileInfo(auStack_238,0,auStack_4f0,0x2b4,0x4001);
        SetBkMode(*(HDC *)(param_1 + 0x18),1);
        ImageList_Draw(himl,local_4ec,*(HDC *)(param_1 + 0x18),local_510.left + 4,local_510.top + 3,
                       0);
        local_520.left = local_520.left + 0x18;
        local_520.right = local_520.right + -8;
      }
      GetTextExtentExPointW(*(HDC *)(param_1 + 0x18),L"...",3,0,(LPINT)0x0,(LPINT)0x0,&local_500);
      iVar5 = FUN_00015764(*(HDC *)(param_1 + 0x18),*(wchar_t **)(*(int *)(param_1 + 0x2c) + 0x10),
                           &local_520.left,local_528,local_500.cx);
      if (iVar5 == 0) {
        local_528[0] = wcslen(*(wchar_t **)(*(int *)(param_1 + 0x2c) + 0x10));
      }
      else {
        wcscpy((wchar_t *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x10) + local_528[0] * 2),L"...");
        local_528[0] = local_528[0] + 3;
      }
      DrawTextW(*(HDC *)(param_1 + 0x18),*(LPCWSTR *)(*(int *)(param_1 + 0x2c) + 0x10),local_528[0],
                &local_520,0x924);
    }
    FUN_00033770(local_30);
  }
  return uVar8;
}



/* 0003199c FUN_0003199c */

/* Boundary evidence: original MIPS .pdata 0003199c..00031a37. Semantic name remains unreviewed. */

bool FUN_0003199c(UINT param_1,int param_2,int param_3,HWND param_4)

{
  bool bVar1;
  
  DAT_00035680 = 0xefff;
  DAT_00035664 = FUN_00030e84();
  bVar1 = DAT_00035664 != (HMENU)0x0;
  if (bVar1) {
    TrackPopupMenuEx(DAT_00035664,param_1,param_2,param_3,param_4,(LPTPMPARAMS)0x0);
    PostMessageW(param_4,0x111,0xce5,0);
  }
  return bVar1;
}



/* 00031a38 FUN_00031a38 */

/* Boundary evidence: original MIPS .pdata 00031a38..00031ab7. Semantic name remains unreviewed. */

undefined4 FUN_00031a38(HMENU param_1)

{
  UINT UVar1;
  undefined4 *puVar2;
  
  UVar1 = FUN_000156c4(param_1,0);
  if (UVar1 == 0xfffe) {
    puVar2 = (undefined4 *)FUN_00032a08(param_1,0);
    RemoveMenu(param_1,0,0x400);
    FUN_00032f00(param_1,0,(LPCITEMIDLIST)*puVar2,1);
    FUN_000306b4(puVar2);
  }
  return 1;
}



/* 00031ab8 FUN_00031ab8 */

/* Boundary evidence: original MIPS .pdata 00031ab8..00031b7f. Semantic name remains unreviewed. */

bool FUN_00031ab8(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_258;
  undefined1 auStack_254 [4];
  undefined4 local_250;
  undefined1 auStack_24c [4];
  undefined1 auStack_248 [4];
  undefined1 auStack_244 [4];
  undefined1 auStack_240 [4];
  undefined1 auStack_23c [36];
  undefined1 auStack_218 [520];
  uint local_10;
  
  local_10 = DAT_00035518;
  iVar3 = SHGetPathFromIDList(param_2,auStack_218);
  if (iVar3 == 0) {
    FUN_00033770(local_10);
  }
  else {
    local_258 = 0x3c;
    local_250 = param_1;
    puVar1 = auStack_254 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    puVar1 = auStack_24c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    puVar1 = auStack_248 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)auStack_218 >> (3 - uVar2) * 8;
    puVar1 = auStack_244 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    puVar1 = auStack_240 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    puVar1 = auStack_23c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 1U >> (3 - uVar2) * 8;
    auStack_254 = (undefined1  [4])0x0;
    auStack_24c = (undefined1  [4])0x0;
    auStack_244 = (undefined1  [4])0x0;
    auStack_240 = (undefined1  [4])0x0;
    auStack_23c._0_4_ = 1;
    auStack_248 = (undefined1  [4])auStack_218;
    ShellExecuteEx(&local_258);
    FUN_00033770(local_10);
  }
  return iVar3 != 0;
}



/* 00031b80 FUN_00031b80 */

/* Boundary evidence: original MIPS .pdata 00031b80..00031bf7. Semantic name remains unreviewed. */

HWND FUN_00031b80(HWND param_1)

{
  HWND hWnd;
  uint uVar1;
  
  hWnd = GetWindow(param_1,2);
  uVar1 = GetWindowLongW(hWnd,-0x10);
  while ((uVar1 & 0x10000000) == 0) {
    hWnd = GetWindow(hWnd,2);
    uVar1 = GetWindowLongW(hWnd,-0x10);
  }
  return hWnd;
}



/* 00031bf8 FUN_00031bf8 */

/* Boundary evidence: original MIPS .pdata 00031bf8..00031c9f. Semantic name remains unreviewed. */

undefined4 FUN_00031bf8(HWND param_1)

{
  HWND hWnd;
  LPWSTR lpCommandLine;
  HWND pHVar1;
  
  hWnd = FUN_00031b80(param_1);
  lpCommandLine = (LPWSTR)LoadStringW(DAT_00035560,0x5272,(LPWSTR)0x0,0);
  CreateProcessW(L"\\windows\\peghelp.exe",lpCommandLine,(LPSECURITY_ATTRIBUTES)0x0,
                 (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,
                 (LPPROCESS_INFORMATION)0x0);
  Sleep(500);
  pHVar1 = GetDesktopWindow();
  if (pHVar1 != hWnd) {
    PostMessageW(hWnd,0x53,0,0);
  }
  return 1;
}



/* 00031ca0 FUN_00031ca0 */

/* Boundary evidence: original MIPS .pdata 00031ca0..00032003. Semantic name remains unreviewed. */

undefined4 FUN_00031ca0(undefined4 param_1,uint param_2)

{
  undefined1 *puVar1;
  BOOL BVar2;
  uint uVar3;
  int iVar4;
  int local_2a0 [2];
  undefined4 local_298;
  undefined4 local_294;
  undefined1 auStack_28c [4];
  wchar_t *local_288;
  undefined1 auStack_284 [4];
  undefined1 auStack_280 [4];
  undefined1 auStack_27c [4];
  undefined1 auStack_278 [28];
  DWORD local_25c;
  DWORD aDStack_258 [2];
  tagMENUITEMINFOW local_250;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_00035518;
  uVar3 = param_2 & 0xffff;
  if (uVar3 == 0xc) {
    local_288 = L"\\";
  }
  else {
    if (uVar3 == 0x11) {
      FUN_00031bf8(*(HWND *)(DAT_0003556c + 8));
      goto LAB_00031fe0;
    }
    if (uVar3 == 0x12) {
      if (DAT_0003556c != 0) {
        FUN_0002ef1c(DAT_0003556c);
      }
      goto LAB_00031fe0;
    }
    if (uVar3 == 0x13) {
      local_25c = 4;
      local_2a0[0] = 1;
      RegQueryValueExW((HKEY)0x80000002,L"Suspend",(LPDWORD)L"Explorer",aDStack_258,
                       (LPBYTE)local_2a0,&local_25c);
      if (local_2a0[0] != 0) {
        GwesPowerOffSystem();
      }
      goto LAB_00031fe0;
    }
    if (uVar3 == 0x1e) {
      local_288 = L"control.exe";
    }
    else {
      if (uVar3 == 0x1f) {
        if (DAT_0003556c != 0) {
          FUN_00028eb8();
        }
        goto LAB_00031fe0;
      }
      if (uVar3 != 0x20) {
        local_250.fMask = 0x20;
        if (uVar3 < 0xefff) {
          local_250.cbSize = 0x2c;
          if ((DAT_00035664 == (HMENU)0x0) ||
             (BVar2 = GetMenuItemInfoW(DAT_00035664,uVar3,0,&local_250), BVar2 == 0)) {
            local_250.dwItemData = 0;
          }
          if (((undefined4 *)local_250.dwItemData != (undefined4 *)0x0) &&
             (*(int *)(local_250.dwItemData + 0xc) == 0xcdef)) {
            iVar4 = uVar3 * 0x460 + DAT_0003567c;
            swprintf(awStack_220,0x12c60,(wchar_t *)(iVar4 + -0x8e18),
                     *(undefined4 *)(iVar4 + -0x8c10));
            local_294 = 0x440;
            local_288 = L"ctlpnl.exe";
            local_298 = 0x3c;
            puVar1 = auStack_28c + 3;
            uVar3 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar3) =
                 *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0U >> (3 - uVar3) * 8;
            puVar1 = auStack_284 + 3;
            uVar3 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar3) =
                 *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 |
                 (uint)awStack_220 >> (3 - uVar3) * 8;
            puVar1 = auStack_280 + 3;
            uVar3 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar3) =
                 *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0U >> (3 - uVar3) * 8;
            puVar1 = auStack_27c + 3;
            uVar3 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar3) =
                 *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 5U >> (3 - uVar3) * 8;
            puVar1 = auStack_278 + 3;
            uVar3 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar3) =
                 *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0U >> (3 - uVar3) * 8;
            auStack_28c = (undefined1  [4])0x0;
            auStack_280 = (undefined1  [4])0x0;
            auStack_27c = (undefined1  [4])0x5;
            auStack_278._0_4_ = 0;
            auStack_284 = (undefined1  [4])awStack_220;
            ShellExecuteEx(&local_298);
            FUN_00033770(local_18);
            return 1;
          }
        }
        else {
          local_250.cbSize = 0x2c;
          if ((DAT_00035664 == (HMENU)0x0) ||
             (BVar2 = GetMenuItemInfoW(DAT_00035664,uVar3,0,&local_250), BVar2 == 0)) {
            local_250.dwItemData = 0;
          }
          if ((undefined4 *)local_250.dwItemData != (undefined4 *)0x0) {
            FUN_00031ab8(param_1,*(undefined4 *)local_250.dwItemData);
            goto LAB_00031fe0;
          }
        }
        FUN_00033770(local_18);
        return 0;
      }
      local_288 = L"ConnMC.exe";
    }
  }
  local_298 = 0x3c;
  local_294 = 0x440;
  puVar1 = auStack_28c + 3;
  uVar3 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar3) =
       *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0U >> (3 - uVar3) * 8;
  puVar1 = auStack_284 + 3;
  uVar3 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar3) =
       *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0U >> (3 - uVar3) * 8;
  puVar1 = auStack_280 + 3;
  uVar3 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar3) =
       *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0U >> (3 - uVar3) * 8;
  puVar1 = auStack_27c + 3;
  uVar3 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar3) =
       *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 5U >> (3 - uVar3) * 8;
  puVar1 = auStack_278 + 3;
  uVar3 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar3) =
       *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | 0U >> (3 - uVar3) * 8;
  auStack_28c = (undefined1  [4])0x0;
  auStack_284 = (undefined1  [4])0x0;
  auStack_280 = (undefined1  [4])0x0;
  auStack_27c = (undefined1  [4])0x5;
  auStack_278._0_4_ = 0;
  ShellExecuteEx(&local_298);
LAB_00031fe0:
  FUN_00033770(local_18);
  return 1;
}



/* 00032004 FUN_00032004 */

/* Boundary evidence: original MIPS .pdata 00032004..0003226f. Semantic name remains unreviewed. */

uint FUN_00032004(HMENU param_1,uint param_2)

{
  wchar_t wVar1;
  bool bVar2;
  wint_t wVar3;
  BOOL BVar4;
  int iVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  wchar_t *pwVar6;
  uint uVar7;
  uint item;
  wchar_t *pwVar8;
  uint uVar9;
  tagMENUITEMINFOW local_310;
  wchar_t local_2d4;
  wchar_t local_2d2 [339];
  uint local_2c;
  
  local_2c = DAT_00035518;
  uVar7 = 0xffffffff;
  item = 0;
  uVar9 = 0xffffffff;
  bVar2 = false;
  memset(&local_310,0,0x2c);
  local_310.cbSize = 0x2c;
  local_310.fMask = 0x27;
  BVar4 = GetMenuItemInfoW(param_1,0,1,&local_310);
  if (BVar4 != 0) {
    do {
      pwVar8 = &local_2d4;
      local_2d4 = L'\0';
      if ((uint *)local_310.dwItemData != (uint *)0x0) {
        if (((*(uint *)local_310.dwItemData & 0xffff0000) == 0) || (local_310.wID == 0xffff)) {
          if (*(uint *)local_310.dwItemData != 0) {
            if (*(uint *)(local_310.dwItemData + 0xc) == 0xcdef) {
              wcscpy(&local_2d4,*(wchar_t **)(local_310.dwItemData + 4));
            }
            else {
              LoadStringW(DAT_00035560,(UINT)*(wchar_t **)(local_310.dwItemData + 4),&local_2d4,
                          0x104);
            }
            pwVar6 = &local_2d4;
            wVar1 = local_2d4;
            while (wVar1 != L'&') {
              pwVar6 = pwVar6 + 1;
              wVar1 = *pwVar6;
            }
            if (*pwVar6 == L'&') {
              pwVar8 = pwVar6 + 1;
            }
          }
        }
        else {
          pwVar8 = *(wchar_t **)(local_310.dwItemData + 0x10);
        }
        iVar5 = iswctype(*pwVar8,2);
        if (iVar5 == 0) {
          wVar3 = towupper((wint_t)param_2);
          param_2 = CONCAT22(extraout_var_00,wVar3);
        }
        else {
          wVar3 = towlower((wint_t)param_2);
          param_2 = CONCAT22(extraout_var,wVar3);
        }
        if ((local_310.fState & 0x80) != 0) {
          uVar9 = item;
        }
        if ((ushort)*pwVar8 == param_2) {
          if (-1 < (int)uVar7) {
            bVar2 = true;
          }
          if ((((-1 < (int)uVar9) && ((int)uVar9 < (int)item)) && ((int)uVar7 <= (int)uVar9)) ||
             ((int)uVar7 < 0)) {
            uVar7 = item;
          }
        }
      }
      item = item + 1;
      BVar4 = GetMenuItemInfoW(param_1,item,1,&local_310);
    } while (BVar4 != 0);
    if (-1 < (int)uVar7) {
      if (bVar2) {
        uVar9 = 0x30000;
      }
      else {
        uVar9 = 0x20000;
      }
      FUN_00033770(local_2c);
      return uVar7 & 0xffff | uVar9;
    }
  }
  MessageBeep(0xffffffff);
  FUN_00033770(local_2c);
  return 0;
}



/* 00032270 FUN_00032270 */

/* Boundary evidence: original MIPS .pdata 00032270..00032303. Semantic name remains unreviewed. */

undefined4 FUN_00032270(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_3 = 0;
  iVar1 = memcmp(param_2,&DAT_00012010,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_0001310c,0x10), iVar1 == 0)) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    uVar2 = 0;
    *param_3 = param_1;
  }
  else {
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 00032314 FUN_00032314 */

/* Boundary evidence: original MIPS .pdata 00032314..00032343. Semantic name remains unreviewed. */

int FUN_00032314(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 4) + -1;
  *(int *)((int)param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 00032344 FUN_00032344 */

/* Boundary evidence: original MIPS .pdata 00032344..00032393. Semantic name remains unreviewed. */

undefined4
FUN_00032344(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (param_6 == 0)) {
    uVar1 = 0x80070057;
  }
  else {
    ImageList_DragEnter((HWND)0x0,param_4,param_5);
    uVar1 = 0;
  }
  return uVar1;
}



/* 00032394 FUN_00032394 */

/* Boundary evidence: original MIPS .pdata 00032394..000325a7. Semantic name remains unreviewed. */

undefined4 FUN_00032394(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  uint uVar1;
  int *piVar2;
  BOOL BVar3;
  DWORD DVar4;
  HIMAGELIST himlDrag;
  HWND hWnd;
  uint lParam;
  undefined4 auStack_30 [2];
  tagPOINT local_28;
  
  local_28.x = param_3;
  local_28.y = param_4;
  ScreenToClient(*(HWND *)(param_1 + 8),&local_28);
  uVar1 = FUN_00024644(DAT_0003556c,*(undefined4 *)(param_1 + 8),local_28.x,local_28.y,auStack_30);
  ImageList_DragMove(param_3,param_4);
  FUN_00022074((int)DAT_0003556c,local_28.x,local_28.y);
  if (uVar1 == 0xffffffff) {
    *param_5 = 0;
  }
  else {
    piVar2 = FUN_00023388(DAT_0003556c,*(undefined4 *)(param_1 + 8),uVar1);
    if (((piVar2 == (int *)0x0) || ((*(uint *)(piVar2[2] + 8) & 4) == 0)) ||
       ((hWnd = *(HWND *)(piVar2[2] + 0x1c), hWnd != (HWND)0xfffffffd &&
        (BVar3 = IsWindow(hWnd), BVar3 == 0)))) {
      *param_5 = 0;
    }
    else if ((*(int *)(param_1 + 0x14) == 0) || (uVar1 != *(uint *)(param_1 + 0x10))) {
      DVar4 = GetTickCount();
      *(DWORD *)(param_1 + 0x14) = DVar4;
    }
    else {
      DVar4 = GetTickCount();
      if (1000 < DVar4 - *(int *)(param_1 + 0x14)) {
        himlDrag = ImageList_GetDragImage((POINT *)0x0,(POINT *)0x0);
        ImageList_DragShowNolock(0);
        if (*(int *)(piVar2[2] + 0x1c) == -3) {
          lParam = 0x10000;
        }
        else {
          lParam = uVar1 & 0xffff | 0x10000;
        }
        SendMessageW(*(HWND *)(param_1 + 8),0x111,0xc83,lParam);
        ImageList_DragShowNolock(1);
        if (himlDrag != (HIMAGELIST)0x0) {
          ImageList_SetDragCursorImage(himlDrag,0,0,0);
        }
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
    }
  }
  *(uint *)(param_1 + 0x10) = uVar1;
  return 0;
}



/* 000325a8 FUN_000325a8 */

/* Boundary evidence: original MIPS .pdata 000325a8..000325cf. Semantic name remains unreviewed. */

undefined4 FUN_000325a8(void)

{
  ImageList_DragLeave((HWND)0x0);
  return 0;
}



/* 000325d0 FUN_000325d0 */

/* Boundary evidence: original MIPS .pdata 000325d0..0003260f. Semantic name remains unreviewed. */

undefined4 FUN_000325d0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    ImageList_DragLeave((HWND)0x0);
    uVar1 = 0x8000ffff;
  }
  return uVar1;
}



/* 00032610 FUN_00032610 */

/* Boundary evidence: original MIPS .pdata 00032610..0003267f. Semantic name remains unreviewed. */

undefined4 * FUN_00032610(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_00012c70;
    puVar1[1] = 1;
    puVar1[2] = param_1;
    puVar1[3] = param_2;
    puVar1[4] = 0xffffffff;
    puVar1[5] = 0;
  }
  return puVar1;
}



/* 00032680 FUN_00032680 */

/* Boundary evidence: original MIPS .pdata 00032680..000326a3. Semantic name remains unreviewed. */

void FUN_00032680(HLOCAL param_1)

{
  if (param_1 != (HLOCAL)0x0) {
    LocalFree(param_1);
  }
  return;
}



/* 000326a4 FUN_000326a4 */

char * FUN_000326a4(ushort *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if ((param_1 != (ushort *)0x0) &&
     (pcVar1 = (char *)((uint)*param_1 + (int)param_1), *pcVar1 == '\0' && pcVar1[1] == '\0')) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}



/* 000326ec FUN_000326ec */

/* Boundary evidence: original MIPS .pdata 000326ec..0003275f. Semantic name remains unreviewed. */

int FUN_000326ec(ushort *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 == (ushort *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    do {
      bVar1 = param_2 == 0;
      param_2 = param_2 + -1;
      if (bVar1) break;
      iVar2 = (uint)*param_1 + iVar2;
      param_1 = (ushort *)FUN_000326a4(param_1);
    } while (param_1 != (ushort *)0x0);
    iVar2 = iVar2 + 2;
  }
  return iVar2;
}



/* 00032760 FUN_00032760 */

/* Boundary evidence: original MIPS .pdata 00032760..00032813. Semantic name remains unreviewed. */

HLOCAL FUN_00032760(ushort *param_1,ushort *param_2)

{
  int iVar1;
  HLOCAL _Dst;
  size_t _Size;
  
  _Dst = (HLOCAL)0x0;
  if ((param_1 != (ushort *)0x0) && (param_2 != (ushort *)0x0)) {
    iVar1 = FUN_000326ec(param_1,-1);
    _Size = iVar1 - 2;
    iVar1 = FUN_000326ec(param_2,-1);
    _Dst = LocalAlloc(0x40,(iVar1 - 2U) + _Size + 2);
    if (_Dst != (HLOCAL)0x0) {
      memcpy(_Dst,param_1,_Size);
      memcpy((void *)(_Size + (int)_Dst),param_2,iVar1 - 2U);
    }
  }
  return _Dst;
}



/* 00032814 FUN_00032814 */

/* Boundary evidence: original MIPS .pdata 00032814..00032883. Semantic name remains unreviewed. */

HLOCAL FUN_00032814(ushort *param_1,int param_2)

{
  SIZE_T uBytes;
  HLOCAL _Dst;
  
  _Dst = (HLOCAL)0x0;
  if (param_1 != (ushort *)0x0) {
    uBytes = FUN_000326ec(param_1,param_2);
    _Dst = LocalAlloc(0x40,uBytes);
    if (_Dst != (HLOCAL)0x0) {
      memcpy(_Dst,param_1,uBytes - 2);
    }
  }
  return _Dst;
}



/* 00032884 FUN_00032884 */

/* Boundary evidence: original MIPS .pdata 00032884..0003292b. Semantic name remains unreviewed. */

void FUN_00032884(HMENU param_1)

{
  BOOL BVar1;
  UINT item;
  tagMENUITEMINFOW local_40;
  
  local_40.cbSize = 0x2c;
  local_40.fMask = 0x26;
  local_40.hSubMenu = (HMENU)0x0;
  item = 0;
  while (BVar1 = GetMenuItemInfoW(param_1,item,1,&local_40), BVar1 != 0) {
    if (((undefined4 *)local_40.dwItemData != (undefined4 *)0x0) &&
       ((*(int *)(local_40.dwItemData + 0xc) == 0 || (*(int *)(local_40.dwItemData + 0xc) == 0xcdef)
        ))) {
      FUN_000306b4((undefined4 *)local_40.dwItemData);
    }
    if (local_40.hSubMenu != (HMENU)0x0) {
      FUN_00032884(local_40.hSubMenu);
    }
    item = item + 1;
  }
  return;
}



/* 0003292c FUN_0003292c */

/* Boundary evidence: original MIPS .pdata 0003292c..0003298b. Semantic name remains unreviewed. */

BOOL FUN_0003292c(HMENU param_1)

{
  LPCWSTR lpNewItem;
  BOOL BVar1;
  
  lpNewItem = (LPCWSTR)LoadStringW(DAT_00035560,0x4e24,(LPWSTR)0x0,0);
  if (lpNewItem == (LPCWSTR)0x0) {
    BVar1 = 0;
  }
  else {
    BVar1 = InsertMenuW(param_1,0,0x401,0xffff,lpNewItem);
  }
  return BVar1;
}



/* 0003298c FUN_0003298c */

/* Boundary evidence: original MIPS .pdata 0003298c..00032a07. Semantic name remains unreviewed. */

int FUN_0003298c(PCNZWCH param_1,uint param_2,PCNZWCH param_3,uint param_4)

{
  int iVar1;
  
  if ((param_2 & 0x10) != 0) {
    if ((param_4 & 0x10) == 0) {
      return -1;
    }
    if ((param_2 & 0x10) != 0) goto LAB_000329d0;
  }
  if ((param_4 & 0x10) != 0) {
    return 1;
  }
LAB_000329d0:
  iVar1 = CompareStringW(0x800,1,param_1,-1,param_3,-1);
  return iVar1 + -2;
}



/* 00032a08 FUN_00032a08 */

/* Boundary evidence: original MIPS .pdata 00032a08..00032a4b. Semantic name remains unreviewed. */

ULONG_PTR FUN_00032a08(HMENU param_1,UINT param_2)

{
  BOOL BVar1;
  tagMENUITEMINFOW local_38;
  
  local_38.cbSize = 0x2c;
  local_38.fMask = 0x20;
  BVar1 = GetMenuItemInfoW(param_1,param_2,1,&local_38);
  if (BVar1 == 0) {
    local_38.dwItemData = 0;
  }
  return local_38.dwItemData;
}



/* 00032a4c FUN_00032a4c */

/* Boundary evidence: original MIPS .pdata 00032a4c..00032b53. Semantic name remains unreviewed. */

UINT FUN_00032a4c(HMENU param_1,int param_2)

{
  UINT UVar1;
  BOOL BVar2;
  int iVar3;
  UINT item;
  UINT UVar4;
  UINT UVar5;
  tagMENUITEMINFOW local_50;
  
  UVar5 = 0;
  UVar1 = FUN_0001564c(param_1);
  UVar1 = UVar1 - 1;
  item = UVar1;
  UVar4 = UVar1;
  if (-1 < (int)UVar1) {
    do {
      iVar3 = (UVar4 - UVar5) + 1;
      if (iVar3 < 0) {
        iVar3 = (UVar4 - UVar5) + 2;
      }
      item = (iVar3 >> 1) + UVar5;
      local_50.cbSize = 0x2c;
      local_50.fMask = 0x20;
      BVar2 = GetMenuItemInfoW(param_1,item,1,&local_50);
      if ((BVar2 == 0) || (local_50.dwItemData == 0)) goto LAB_00032b28;
      iVar3 = FUN_0003298c(*(PCNZWCH *)(param_2 + 0x10),*(uint *)(param_2 + 4),
                           *(PCNZWCH *)(local_50.dwItemData + 0x10),
                           *(uint *)(local_50.dwItemData + 4));
      if (iVar3 < 0) {
        UVar4 = item - 1;
      }
      else {
        item = item + 1;
        UVar5 = item;
      }
    } while ((int)UVar5 <= (int)UVar4);
    if ((int)UVar1 < (int)item) {
LAB_00032b28:
      item = 0xffffffff;
    }
  }
  return item;
}



/* 00032b54 FUN_00032b54 */

/* Boundary evidence: original MIPS .pdata 00032b54..00032bb7. Semantic name remains unreviewed. */

DWORD FUN_00032b54(undefined4 param_1)

{
  int iVar1;
  DWORD DVar2;
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_00035518;
  DVar2 = 0;
  iVar1 = SHGetPathFromIDList(param_1,aWStack_218);
  if (iVar1 != 0) {
    DVar2 = GetFileAttributesW(aWStack_218);
  }
  FUN_00033770(local_10);
  return DVar2;
}



/* 00032bb8 FUN_00032bb8 */

/* Boundary evidence: original MIPS .pdata 00032bb8..00032c1f. Semantic name remains unreviewed. */

undefined4 * FUN_00032bb8(undefined4 param_1)

{
  undefined4 *puVar1;
  DWORD DVar2;
  
  puVar1 = LocalAlloc(0,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    DVar2 = FUN_00032b54(param_1);
    puVar1[1] = DVar2;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[6] = 0;
    puVar1[5] = 0;
  }
  return puVar1;
}



/* 00032c20 FUN_00032c20 */

/* Boundary evidence: original MIPS .pdata 00032c20..00032caf. Semantic name remains unreviewed. */

HMENU FUN_00032c20(undefined4 param_1)

{
  HMENU hMenu;
  LPCWSTR lpNewItem;
  BOOL BVar1;
  
  hMenu = CreatePopupMenu();
  lpNewItem = (LPCWSTR)FUN_00032bb8(param_1);
  if (hMenu != (HMENU)0x0) {
    if (lpNewItem == (LPCWSTR)0x0) goto LAB_00032c84;
    BVar1 = InsertMenuW(hMenu,0,0x500,0xfffe,lpNewItem);
    if (BVar1 != 0) {
      return hMenu;
    }
  }
  if (lpNewItem != (LPCWSTR)0x0) {
    FUN_000306b4((undefined4 *)lpNewItem);
  }
LAB_00032c84:
  if (hMenu != (HMENU)0x0) {
    DestroyMenu(hMenu);
  }
  return (HMENU)0x0;
}



/* 00032cb0 FUN_00032cb0 */

/* Boundary evidence: original MIPS .pdata 00032cb0..00032eff. Semantic name remains unreviewed. */

int FUN_00032cb0(HMENU param_1,UINT_PTR param_2,ushort *param_3)

{
  LPCWSTR lpNewItem;
  HRESULT HVar1;
  int iVar2;
  LPWSTR pWVar3;
  wchar_t *pwVar4;
  UINT UVar5;
  HLOCAL pvVar6;
  HMENU uIDNewItem;
  BOOL BVar7;
  LPCITEMIDLIST local_370;
  int *local_36c;
  MENUITEMINFOW local_368;
  STRRET local_338;
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_00035518;
  lpNewItem = (LPCWSTR)FUN_00032bb8(param_3);
  if (lpNewItem != (LPCWSTR)0x0) {
    local_36c = (int *)0x0;
    local_370 = (LPCITEMIDLIST)0x0;
    HVar1 = SHBindToParent(*(LPCITEMIDLIST *)lpNewItem,(IID *)&DAT_00012000,&local_36c,&local_370);
    if (-1 < HVar1) {
      local_338.uType = 0;
      memset(&local_338.u,0,0x104);
      iVar2 = (**(code **)(*local_36c + 0x2c))(local_36c,local_370,0x4001,&local_338);
      if (-1 < iVar2) {
        iVar2 = StrRetToBufW(&local_338,local_370,aWStack_230,0x104);
      }
      (**(code **)(*local_36c + 8))();
      FUN_00032680(local_370);
      if (-1 < iVar2) {
        pWVar3 = PathFindFileNameW(aWStack_230);
        PathRemoveExtensionW(aWStack_230);
        pwVar4 = FUN_000156f8(pWVar3);
        *(wchar_t **)(lpNewItem + 8) = pwVar4;
        UVar5 = FUN_00032a4c(param_1,(int)lpNewItem);
        if ((*(uint *)(lpNewItem + 2) & 0x10) == 0) {
          BVar7 = InsertMenuW(param_1,UVar5,0x500,param_2,lpNewItem);
        }
        else {
          pvVar6 = FUN_00032814(param_3,-1);
          uIDNewItem = FUN_00032c20(pvVar6);
          if (uIDNewItem == (HMENU)0x0) {
            BVar7 = 0;
            FUN_00032680(pvVar6);
          }
          else {
            BVar7 = InsertMenuW(param_1,UVar5,0x510,(UINT_PTR)uIDNewItem,lpNewItem);
            if (UVar5 == 0xffffffff) {
              UVar5 = FUN_0001564c(param_1);
              UVar5 = UVar5 - 1;
            }
            local_368.cbSize = 0x2c;
            local_368.fMask = 0x20;
            local_368.dwItemData = (ULONG_PTR)lpNewItem;
            SetMenuItemInfoW(param_1,UVar5,1,&local_368);
          }
        }
        if (BVar7 == 0) {
          FUN_000306b4((undefined4 *)lpNewItem);
        }
        FUN_00033770(local_28);
        return BVar7;
      }
    }
    FUN_000306b4((undefined4 *)lpNewItem);
  }
  FUN_00033770(local_28);
  return 0;
}



/* 00032f00 FUN_00032f00 */

/* Boundary evidence: original MIPS .pdata 00032f00..000331c3. Semantic name remains unreviewed. */

HRESULT FUN_00032f00(HMENU param_1,undefined4 param_2,LPCITEMIDLIST param_3,int param_4)

{
  UINT_PTR UVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HRESULT HVar5;
  ushort *puVar6;
  BOOL BVar7;
  UINT item;
  int iVar8;
  int *local_68;
  IShellFolder *local_64;
  ushort *local_60;
  int *local_5c;
  tagMENUITEMINFOW local_58;
  
  local_68 = (int *)0x0;
  local_5c = (int *)0x0;
  iVar8 = 0;
  iVar2 = GetSystemMetrics(1);
  iVar3 = GetSystemMetrics(0x32);
  iVar4 = GetSystemMetrics(0xf);
  if (iVar4 < iVar3 + 6) {
    iVar3 = GetSystemMetrics(0x32);
    iVar3 = iVar3 + 6;
  }
  else {
    iVar3 = GetSystemMetrics(0xf);
  }
  HVar5 = SHGetDesktopFolder(&local_64);
  if (HVar5 != 0) {
    return HVar5;
  }
  HVar5 = (*local_64->lpVtbl->BindToObject)
                    (local_64,param_3,(IBindCtx *)0x0,(IID *)&DAT_00012000,&local_5c);
  if (local_64 != (IShellFolder *)0x0) {
    (*local_64->lpVtbl->Release)(local_64);
    local_64 = (IShellFolder *)0x0;
  }
  if ((-1 < HVar5) &&
     (HVar5 = (**(code **)(*local_5c + 0x10))(local_5c,0,0x60,&local_68), HVar5 == 0)) {
    iVar4 = (**(code **)(*local_68 + 0xc))(local_68,1,&local_60,0);
    while (iVar4 == 0) {
      puVar6 = FUN_00032760((ushort *)param_3,local_60);
      FUN_00032680(local_60);
      UVar1 = DAT_00035680;
      DAT_00035680 = DAT_00035680 + 1;
      iVar4 = FUN_00032cb0(param_1,UVar1,puVar6);
      if (iVar4 == 0) {
        HVar5 = -0x7fff0001;
        goto LAB_0003313c;
      }
      iVar8 = iVar8 + 1;
      iVar4 = (**(code **)(*local_68 + 0xc))(local_68,1,&local_60,0);
    }
    if ((param_4 != 0) && (iVar2 <= iVar3 * iVar8)) {
      local_58.cbSize = 0x2c;
      local_58.fMask = 0x10;
      item = 0;
      iVar4 = iVar3;
      if (0 < iVar8) {
        do {
          if (iVar2 <= iVar4) {
            BVar7 = GetMenuItemInfoW(param_1,item,1,&local_58);
            if (BVar7 != 0) {
              local_58.fType = local_58.fType | 0x20;
            }
            SetMenuItemInfoW(param_1,item,1,&local_58);
            iVar4 = 0;
          }
          item = item + 1;
          iVar4 = iVar3 + iVar4;
        } while ((int)item < iVar8);
      }
    }
    HVar5 = 0;
LAB_0003313c:
    if (iVar8 != 0) goto LAB_0003314c;
  }
  FUN_0003292c(param_1);
LAB_0003314c:
  if (local_68 != (int *)0x0) {
    (**(code **)(*local_68 + 8))();
    local_68 = (int *)0x0;
  }
  if (local_5c != (int *)0x0) {
    (**(code **)(*local_5c + 8))();
  }
  return HVar5;
}



/* 000331d4 FUN_000331d4 */

undefined4 FUN_000331d4(undefined4 param_1)

{
  return param_1;
}



/* 000331dc FUN_000331dc */

/* Boundary evidence: original MIPS .pdata 000331dc..00033223. Semantic name remains unreviewed. */

void FUN_000331dc(void)

{
  DAT_00035684 = CreateAPISet(&DAT_00013008,0x4a,&PTR_FUN_00012c90,&DAT_00012db8);
  RegisterAPISet(DAT_00035684,0x55);
  return;
}



/* 00033224 FUN_00033224 */

/* Boundary evidence: original MIPS .pdata 00033224..0003324f. Semantic name remains unreviewed. */

void FUN_00033224(void)

{
  CloseHandle(DAT_00035684);
  return;
}



/* 00033250 FUN_00033250 */

/* Boundary evidence: original MIPS .pdata 00033250..000332ef. Semantic name remains unreviewed. */

void FUN_00033250(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 6) {
    CompactAllHeaps();
  }
  else if ((param_1 == 0) && (iVar1 = __GetUserKData(0xc), param_2 == iVar1)) {
    CloseHandle(DAT_00035684);
    RegisterTaskBar(0);
    CreateProcessW(L"explorer.exe",(LPWSTR)0x0,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0
                   ,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
  }
  return;
}



/* 000332f0 FUN_000332f0 */

/* Boundary evidence: original MIPS .pdata 000332f0..0003336f. Semantic name remains unreviewed. */

undefined4 FUN_000332f0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_00035564 != 0) {
    if ((DAT_00035688 == (code *)0x0) &&
       (DAT_00035688 = (code *)GetProcAddressW(DAT_00035564,L"SipEnumIM"),
       DAT_00035688 == (code *)0x0)) {
      return 0;
    }
    uVar1 = (*DAT_00035688)(param_1);
  }
  return uVar1;
}



/* 00033370 FUN_00033370 */

/* Boundary evidence: original MIPS .pdata 00033370..000333ef. Semantic name remains unreviewed. */

undefined4 FUN_00033370(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_00035564 != 0) {
    if ((DAT_0003568c == (code *)0x0) &&
       (DAT_0003568c = (code *)GetProcAddressW(DAT_00035564,L"SipGetCurrentIM"),
       DAT_0003568c == (code *)0x0)) {
      return 0;
    }
    uVar1 = (*DAT_0003568c)(param_1);
  }
  return uVar1;
}



/* 000333f0 FUN_000333f0 */

/* Boundary evidence: original MIPS .pdata 000333f0..0003346f. Semantic name remains unreviewed. */

undefined4 FUN_000333f0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_00035564 != 0) {
    if ((DAT_00035690 == (code *)0x0) &&
       (DAT_00035690 = (code *)GetProcAddressW(DAT_00035564,L"SipSetCurrentIM"),
       DAT_00035690 == (code *)0x0)) {
      return 0;
    }
    uVar1 = (*DAT_00035690)(param_1);
  }
  return uVar1;
}



/* 00033470 FUN_00033470 */

/* Boundary evidence: original MIPS .pdata 00033470..000334ef. Semantic name remains unreviewed. */

undefined4 FUN_00033470(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_00035564 != 0) {
    if ((DAT_00035698 == (code *)0x0) &&
       (DAT_00035698 = (code *)GetProcAddressW(DAT_00035564,L"SipShowIM"),
       DAT_00035698 == (code *)0x0)) {
      return 0;
    }
    uVar1 = (*DAT_00035698)(param_1);
  }
  return uVar1;
}



/* 000334f0 FUN_000334f0 */

/* Boundary evidence: original MIPS .pdata 000334f0..0003356f. Semantic name remains unreviewed. */

undefined4 FUN_000334f0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_00035564 != 0) {
    if ((DAT_00035694 == (code *)0x0) &&
       (DAT_00035694 = (code *)GetProcAddressW(DAT_00035564,L"SipGetInfo"),
       DAT_00035694 == (code *)0x0)) {
      return 0;
    }
    uVar1 = (*DAT_00035694)(param_1);
  }
  return uVar1;
}



/* 00033570 FUN_00033570 */

/* Boundary evidence: original MIPS .pdata 00033570..000335ef. Semantic name remains unreviewed. */

undefined4 FUN_00033570(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (DAT_00035564 != 0) {
    if ((DAT_0003569c == (code *)0x0) &&
       (DAT_0003569c = (code *)GetProcAddressW(DAT_00035564,L"SipSetInfo"),
       DAT_0003569c == (code *)0x0)) {
      return 1;
    }
    uVar1 = (*DAT_0003569c)(param_1);
  }
  return uVar1;
}



/* 000335f0 FUN_000335f0 */

/* Boundary evidence: original MIPS .pdata 000335f0..0003366f. Semantic name remains unreviewed. */

undefined4 FUN_000335f0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_00035564 != 0) {
    if ((DAT_000356a0 == (code *)0x0) &&
       (DAT_000356a0 = (code *)GetProcAddressW(DAT_00035564,L"SipRegisterNotification"),
       DAT_000356a0 == (code *)0x0)) {
      return 0;
    }
    uVar1 = (*DAT_000356a0)(param_1);
  }
  return uVar1;
}



/* 00033670 FUN_00033670 */

/* Boundary evidence: original MIPS .pdata 00033670..000336ef. Semantic name remains unreviewed. */

undefined4 FUN_00033670(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_00035564 != 0) {
    if ((DAT_000356a4 == (code *)0x0) &&
       (DAT_000356a4 = (code *)GetProcAddressW(DAT_00035564,L"SipSetDefaultRect"),
       DAT_000356a4 == (code *)0x0)) {
      return 0;
    }
    uVar1 = (*DAT_000356a4)(param_1);
  }
  return uVar1;
}



/* 000336f0 FUN_000336f0 */

/* Boundary evidence: original MIPS .pdata 000336f0..00033743. Semantic name remains unreviewed. */

void FUN_000336f0(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00033770(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00033744 FUN_00033744 */

/* Boundary evidence: original MIPS .pdata 00033744..0003376f. Semantic name remains unreviewed. */

undefined4 FUN_00033744(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_000336f0(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00033770 FUN_00033770 */

/* Boundary evidence: original MIPS .pdata 00033770..000337b7. Semantic name remains unreviewed. */

void FUN_00033770(uint param_1)

{
  if ((param_1 == DAT_00035518) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 000337b8 FUN_000337b8 */

/* Boundary evidence: original MIPS .pdata 000337b8..00033833. Semantic name remains unreviewed. */

void FUN_000337b8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_000336f0(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}


