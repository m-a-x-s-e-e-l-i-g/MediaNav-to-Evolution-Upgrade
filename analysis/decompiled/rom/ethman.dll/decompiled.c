/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 4025117c ETM_Close */

undefined4 ETM_Close(void)

{
                    /* 0x117c  1  ETM_Close
                       0x117c  2  ETM_Deinit
                       0x117c  3  ETM_IOControl */
  return 1;
}



/* 40251184 ETM_Open */

undefined4 ETM_Open(void)

{
                    /* 0x1184  5  ETM_Open */
  return 0x12345678;
}



/* 40251190 ETM_Seek */

undefined4 ETM_Seek(void)

{
                    /* 0x1190  7  ETM_Seek
                       0x1190  8  ETM_Write */
  return 0xffffffff;
}



/* 40251198 ETM_Read */

undefined4 ETM_Read(void)

{
                    /* 0x1198  6  ETM_Read */
  return 0;
}



/* 402511a0 FUN_402511a0 */

/* Boundary evidence: original MIPS .pdata 402511a0..402511fb. Semantic name remains unreviewed. */

undefined4 FUN_402511a0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  
  if (param_2 == 0) {
    pcVar2 = FreeLibrary_exref;
    uVar1 = DAT_402530e0;
    if (DAT_402530ec == 0) {
      return 1;
    }
  }
  else {
    pcVar2 = DisableThreadLibraryCalls_exref;
    uVar1 = param_1;
    if (param_2 != 1) {
      return 1;
    }
  }
  DAT_402530e0 = uVar1;
  (*pcVar2)();
  return 1;
}



/* 402511fc FUN_402511fc */

/* Boundary evidence: original MIPS .pdata 402511fc..40251313. Semantic name remains unreviewed. */

DWORD FUN_402511fc(void)

{
  DWORD DVar1;
  
  DAT_402530ec = LoadLibraryW(L"netui.dll");
  if ((((DAT_402530ec != (HMODULE)0x0) &&
       (DAT_402530f8 = GetProcAddressW(DAT_402530ec,L"AddNetUISystrayIcon"), DAT_402530f8 != 0)) &&
      (DAT_402530fc = GetProcAddressW(DAT_402530ec,L"RemoveNetUISystrayIcon"), DAT_402530fc != 0))
     && (((DAT_40253104 = GetProcAddressW(DAT_402530ec,L"UpdateConnectionStatus"), DAT_40253104 != 0
          && (DAT_40253100 = GetProcAddressW(DAT_402530ec,L"IsPropSheetDialogMessage"),
             DAT_40253100 != 0)) &&
         (DAT_40253108 = GetProcAddressW(DAT_402530ec,L"ClosePropSheetDialogIfReady"),
         DAT_40253108 != 0)))) {
    return 0;
  }
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



/* 40251314 FUN_40251314 */

/* Boundary evidence: original MIPS .pdata 40251314..40251383. Semantic name remains unreviewed. */

void FUN_40251314(void)

{
  DAT_402530f8 = 0;
  DAT_402530fc = 0;
  DAT_40253104 = 0;
  DAT_40253100 = 0;
  DAT_40253108 = 0;
  if (DAT_402530ec != 0) {
    FreeLibrary((HMODULE)DAT_402530ec);
    DAT_402530ec = 0;
  }
  return;
}



/* 40251384 FUN_40251384 */

/* Boundary evidence: original MIPS .pdata 40251384..4025142b. Semantic name remains unreviewed. */

undefined4 FUN_40251384(undefined4 param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  DWORD local_88 [2];
  undefined4 local_80;
  undefined4 local_7c [4];
  int local_6c;
  
  local_80 = 0;
  memset(local_7c,0,0x6c);
  local_88[0] = 0;
  uVar2 = 0;
  local_7c[0] = param_1;
  BVar1 = DeviceIoControl(DAT_402530f0,0x120824,(LPVOID)0x0,0,&local_80,0x70,local_88,
                          (LPOVERLAPPED)0x0);
  if ((BVar1 != 0) && (local_6c == 1)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* 4025142c FUN_4025142c */

/* Boundary evidence: original MIPS .pdata 4025142c..40251477. Semantic name remains unreviewed. */

void FUN_4025142c(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
  *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
  return;
}



/* 40251478 FUN_40251478 */

/* Boundary evidence: original MIPS .pdata 40251478..40251543. Semantic name remains unreviewed. */

void FUN_40251478(HLOCAL param_1)

{
  if (param_1 != (HLOCAL)0x0) {
    if ((param_1 == DAT_402530e8) &&
       (DAT_402530e8 = *(HLOCAL *)((int)DAT_402530e8 + 0x78), DAT_402530e8 == (HLOCAL)0x0)) {
      FUN_40251314();
    }
    if (*(int *)((int)param_1 + 0x78) != 0) {
      *(undefined4 *)(*(int *)((int)param_1 + 0x78) + 0x7c) = *(undefined4 *)((int)param_1 + 0x7c);
    }
    if (*(int *)((int)param_1 + 0x7c) != 0) {
      *(undefined4 *)(*(int *)((int)param_1 + 0x7c) + 0x78) = *(undefined4 *)((int)param_1 + 0x78);
    }
    if (*(HANDLE *)((int)param_1 + 100) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)param_1 + 100));
    }
    if (*(HANDLE *)((int)param_1 + 0x68) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)param_1 + 0x68));
    }
    if (*(HANDLE *)((int)param_1 + 0x6c) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)param_1 + 0x6c));
    }
    LocalFree(param_1);
  }
  return;
}



/* 40251544 FUN_40251544 */

/* Boundary evidence: original MIPS .pdata 40251544..4025165f. Semantic name remains unreviewed. */

DWORD FUN_40251544(undefined4 *param_1,wchar_t *param_2,undefined4 param_3)

{
  wchar_t *_Dest;
  HANDLE pvVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  _Dest = LocalAlloc(0,0x80);
  if (_Dest == (wchar_t *)0x0) {
    DVar2 = 0x8007000e;
  }
  else {
    memset(_Dest,0,0x80);
    _Dest[0x3a] = L'\x01';
    _Dest[0x3b] = L'\0';
    wcsncpy(_Dest,param_2,0x32);
    *(undefined4 *)(_Dest + 0x38) = param_3;
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE *)(_Dest + 0x32) = pvVar1;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
    if ((DAT_402530e8 != (wchar_t *)0x0) || (DVar2 = FUN_402511fc(), -1 < (int)DVar2)) {
      *(wchar_t **)(_Dest + 0x3c) = DAT_402530e8;
      DAT_402530e8 = _Dest;
      _Dest[0x3e] = L'\0';
      _Dest[0x3f] = L'\0';
      if (*(int *)(_Dest + 0x3c) != 0) {
        *(wchar_t **)(*(int *)(_Dest + 0x3c) + 0x7c) = _Dest;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
  }
  *param_1 = _Dest;
  return DVar2;
}



/* 40251660 FUN_40251660 */

/* Boundary evidence: original MIPS .pdata 40251660..4025170f. Semantic name remains unreviewed. */

undefined4 FUN_40251660(undefined4 *param_1,wchar_t *param_2)

{
  int iVar1;
  wchar_t *_Str1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
  _Str1 = DAT_402530e8;
  do {
    if (_Str1 == (wchar_t *)0x0) {
LAB_402516e0:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
      *param_1 = _Str1;
      return uVar2;
    }
    iVar1 = wcscmp(_Str1,param_2);
    if (iVar1 == 0) {
      FUN_4025142c((int)_Str1);
      uVar2 = 0;
      goto LAB_402516e0;
    }
    _Str1 = *(wchar_t **)(_Str1 + 0x3c);
  } while( true );
}



/* 40251710 FUN_40251710 */

/* Boundary evidence: original MIPS .pdata 40251710..402518a7. Semantic name remains unreviewed. */

void FUN_40251710(wchar_t *param_1)

{
  int iVar1;
  size_t sVar2;
  undefined4 *puVar3;
  wchar_t *_Dest;
  undefined4 *hMem;
  uint uVar4;
  SIZE_T local_28 [2];
  
  local_28[0] = 0;
  hMem = (undefined4 *)0x0;
  _Dest = (wchar_t *)0x0;
  uVar4 = 0;
  iVar1 = GetAdaptersInfo(0,local_28);
  if (iVar1 == 0x6f) {
    hMem = LocalAlloc(0,local_28[0]);
    if (hMem == (undefined4 *)0x0) {
      return;
    }
    iVar1 = GetAdaptersInfo(hMem,local_28);
    if (iVar1 != 0) goto LAB_40251870;
  }
  else if (iVar1 != 0) {
    return;
  }
  puVar3 = hMem;
  if (local_28[0] != 0) {
    do {
      sVar2 = strlen((char *)(puVar3 + 2));
      if (uVar4 < sVar2 + 1) {
        if (_Dest != (wchar_t *)0x0) {
          LocalFree(_Dest);
        }
        uVar4 = sVar2 + 0xb;
        _Dest = LocalAlloc(0,uVar4 * 2);
        if (_Dest == (wchar_t *)0x0) goto LAB_40251870;
      }
      mbstowcs(_Dest,(char *)(puVar3 + 2),sVar2 + 1);
      iVar1 = wcscmp(param_1,_Dest);
      if (iVar1 == 0) {
        iVar1 = strcmp((char *)(puVar3 + 0x6c),"0.0.0.0");
        (*DAT_40253104)(param_1,iVar1 != 0);
        break;
      }
      puVar3 = (undefined4 *)*puVar3;
    } while (puVar3 != (undefined4 *)0x0);
    if (_Dest != (wchar_t *)0x0) {
      LocalFree(_Dest);
    }
  }
LAB_40251870:
  if (hMem != (undefined4 *)0x0) {
    LocalFree(hMem);
  }
  return;
}



/* 402518a8 FUN_402518a8 */

/* Boundary evidence: original MIPS .pdata 402518a8..402518ff. Semantic name remains unreviewed. */

void FUN_402518a8(HLOCAL param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
  iVar1 = *(int *)((int)param_1 + 0x74) + -1;
  *(int *)((int)param_1 + 0x74) = iVar1;
  if (iVar1 == 0) {
    FUN_40251478(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
  return;
}



/* 40251900 FUN_40251900 */

/* Boundary evidence: original MIPS .pdata 40251900..40251b47. Semantic name remains unreviewed. */

undefined4 FUN_40251900(wchar_t *param_1)

{
  int iVar1;
  SOCKET s;
  HANDLE pvVar2;
  DWORD DVar3;
  DWORD DVar4;
  HANDLE local_240;
  HANDLE local_23c;
  undefined1 auStack_238 [16];
  HANDLE local_228;
  WSADATA WStack_220;
  wchar_t awStack_90 [50];
  uint local_2c;
  
  local_2c = DAT_402530c0;
  local_240 = *(HANDLE *)(param_1 + 0x32);
  local_23c = (HANDLE)0x0;
  wcscpy(awStack_90,param_1);
  FUN_402518a8(param_1);
  iVar1 = WSAStartup(0x202,&WStack_220);
  if (iVar1 == 0) {
    s = socket(2,1,0);
    if (s != 0xffffffff) {
      pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      local_23c = pvVar2;
      if (pvVar2 != (HANDLE)0x0) {
        memset(auStack_238,0,0x14);
        local_228 = pvVar2;
        iVar1 = WSAIoctl(s,0x28000017,0,0,0,0,0,auStack_238,0);
        if ((iVar1 == 0) || (DVar3 = GetLastError(), DVar3 == 0x3e5)) {
          FUN_40251710(awStack_90);
          while( true ) {
            DVar3 = WaitForMultipleObjects(2,&local_240,0,0xffffffff);
            iVar1 = WSAIoctl(s,0x28000017,0,0,0,0,0,auStack_238,0);
            if (((iVar1 != 0) && (DVar4 = GetLastError(), DVar4 != 0x3e5)) || (DVar3 != 1)) break;
            FUN_40251710(awStack_90);
          }
        }
      }
      closesocket(s);
    }
    WSACleanup();
  }
  if (local_23c != (HANDLE)0x0) {
    CloseHandle(local_23c);
  }
  FUN_402524fc(local_2c);
  return 0;
}



/* 40251b48 FUN_40251b48 */

/* Boundary evidence: original MIPS .pdata 40251b48..40251caf. Semantic name remains unreviewed. */

undefined4 FUN_40251b48(HLOCAL param_1)

{
  int iVar1;
  HANDLE pvVar2;
  undefined4 local_38 [2];
  tagMSG tStack_30;
  
  iVar1 = (*DAT_402530f8)(param_1,*(undefined4 *)((int)param_1 + 0x70),local_38);
  if (-1 < iVar1) {
    FUN_4025142c((int)param_1);
    pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40251900,param_1,0,(LPDWORD)0x0);
    *(HANDLE *)((int)param_1 + 0x6c) = pvVar2;
    if (pvVar2 != (HANDLE)0x0) {
      EventModify(DAT_402530f4,3);
      iVar1 = GetMessageW(&tStack_30,(HWND)0x0,0,0);
      while (iVar1 != 0) {
        (*DAT_40253108)(local_38[0]);
        iVar1 = (*DAT_40253100)(local_38[0],&tStack_30);
        if (iVar1 == 0) {
          TranslateMessage(&tStack_30);
          DispatchMessageW(&tStack_30);
        }
        iVar1 = GetMessageW(&tStack_30,(HWND)0x0,0,0);
      }
      goto LAB_40251c5c;
    }
    FUN_402518a8(param_1);
  }
  EventModify(DAT_402530f4,3);
LAB_40251c5c:
  FUN_402518a8(param_1);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
  if (DAT_402530e8 == 0) {
    FUN_40251314();
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
  return 0;
}



/* 40251cb0 FUN_40251cb0 */

/* Boundary evidence: original MIPS .pdata 40251cb0..40251d47. Semantic name remains unreviewed. */

int FUN_40251cb0(wchar_t *param_1)

{
  HLOCAL pvVar1;
  int iVar2;
  HLOCAL local_18 [2];
  
  local_18[0] = (HLOCAL)0x0;
  iVar2 = FUN_40251660(local_18,param_1);
  pvVar1 = local_18[0];
  if (-1 < iVar2) {
    EventModify(*(undefined4 *)((int)local_18[0] + 100),3);
    WaitForSingleObject(*(HANDLE *)((int)pvVar1 + 0x6c),5000);
    iVar2 = (*DAT_402530fc)(param_1);
    FUN_402518a8(pvVar1);
    FUN_402518a8(pvVar1);
  }
  return iVar2;
}



/* 40251d48 FUN_40251d48 */

/* Boundary evidence: original MIPS .pdata 40251d48..40251de7. Semantic name remains unreviewed. */

DWORD FUN_40251d48(wchar_t *param_1,undefined4 param_2)

{
  LPVOID lpParameter;
  DWORD DVar1;
  HANDLE pvVar2;
  LPVOID local_18 [2];
  
  local_18[0] = (LPVOID)0x0;
  DVar1 = FUN_40251544(local_18,param_1,param_2);
  lpParameter = local_18[0];
  if ((int)DVar1 < 0) {
    EventModify(DAT_402530f4,3);
  }
  else {
    FUN_4025142c((int)local_18[0]);
    pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40251b48,lpParameter,0,(LPDWORD)0x0);
    *(HANDLE *)((int)lpParameter + 0x68) = pvVar2;
    if (pvVar2 == (HANDLE)0x0) {
      FUN_402518a8(lpParameter);
    }
  }
  return DVar1;
}



/* 40251de8 FUN_40251de8 */

/* Boundary evidence: original MIPS .pdata 40251de8..40251f4b. Semantic name remains unreviewed. */

undefined4 FUN_40251de8(void)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
  int iVar6;
  DWORD local_430 [2];
  undefined1 local_428 [4];
  int local_424;
  uint local_28;
  
  local_28 = DAT_402530c0;
  DAT_402530f0 = CreateFileW(DAT_402530e4,0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,
                             (HANDLE)0xffffffff);
  if (DAT_402530f0 != (HANDLE)0xffffffff) {
    puVar1 = local_428 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    local_430[0] = 0;
    iVar6 = 0;
    local_428 = (undefined1  [4])0x0;
    iVar3 = DeviceIoControl(DAT_402530f0,0x12080c,local_428,0x14,local_428,0x400,local_430,
                            (LPOVERLAPPED)0x0);
    while (iVar3 != 0) {
      pwVar5 = (wchar_t *)(local_428 + local_424);
      uVar4 = FUN_40251384(pwVar5);
      FUN_40251d48(pwVar5,uVar4);
      iVar6 = iVar6 + 1;
      local_428 = (undefined1  [4])iVar6;
      iVar3 = DeviceIoControl(DAT_402530f0,0x12080c,local_428,0x14,local_428,0x400,local_430,
                              (LPOVERLAPPED)0x0);
    }
  }
  FUN_402524fc(local_28);
  return 0;
}



/* 40251f4c FUN_40251f4c */

/* Boundary evidence: original MIPS .pdata 40251f4c..40252177. Semantic name remains unreviewed. */

undefined4 FUN_40251f4c(void)

{
  int iVar1;
  HANDLE hHandle;
  BOOL BVar2;
  DWORD DVar3;
  wchar_t *_Str;
  undefined1 auStack_258 [4];
  undefined1 auStack_254 [4];
  HANDLE local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  int local_230;
  wchar_t awStack_22c [264];
  uint local_1c;
  
  local_1c = DAT_402530c0;
  iVar1 = FUN_40251de8();
  if (-1 < iVar1) {
    local_248 = 0x14;
    local_244 = 0;
    local_240 = 4;
    local_23c = 0x214;
    local_238 = 1;
    hHandle = (HANDLE)CreateMsgQueue(0,&local_248);
    if (hHandle != (HANDLE)0x0) {
      local_24c = 0xffffffff;
      local_250 = hHandle;
      BVar2 = DeviceIoControl(DAT_402530f0,0x12081c,&local_250,8,(LPVOID)0x0,0,(LPDWORD)0x0,
                              (LPOVERLAPPED)0x0);
      if (BVar2 != 0) {
        DVar3 = WaitForSingleObject(hHandle,0xffffffff);
        while (DVar3 == 0) {
          iVar1 = ReadMsgQueue(hHandle,&local_230,0x214,auStack_254,1,auStack_258);
          while (iVar1 != 0) {
            _Str = _wcsdup(awStack_22c);
            if (_Str != (wchar_t *)0x0) {
              _wcsupr(_Str);
              if (local_230 == 0x10) {
                WaitForSingleObject(DAT_402530f4,5000);
                iVar1 = FUN_40251384(_Str);
                FUN_40251d48(_Str,(uint)(iVar1 != 0));
              }
              else if (local_230 == 0x20) {
                WaitForSingleObject(DAT_402530f4,5000);
                FUN_40251cb0(_Str);
                EventModify(DAT_402530f4,3);
              }
              LocalFree(_Str);
            }
            iVar1 = ReadMsgQueue(hHandle,&local_230,0x214,auStack_254,1,auStack_258);
          }
          DVar3 = WaitForSingleObject(hHandle,0xffffffff);
        }
      }
      CloseHandle(hHandle);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
  }
  FUN_402524fc(local_1c);
  return 0;
}



/* 40252178 FUN_40252178 */

/* Boundary evidence: original MIPS .pdata 40252178..40252213. Semantic name remains unreviewed. */

undefined4 FUN_40252178(void)

{
  HANDLE hObject;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_40253120);
  DAT_402530f4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,1,(LPCWSTR)0x0);
  if ((DAT_402530f4 != (HANDLE)0x0) &&
     (hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40251f4c,(LPVOID)0x0,0,(LPDWORD)0x0),
     hObject != (HANDLE)0x0)) {
    CloseHandle(hObject);
    return 0;
  }
  return 0x80004005;
}



/* 40252214 FUN_40252214 */

/* Boundary evidence: original MIPS .pdata 40252214..4025224b. Semantic name remains unreviewed. */

undefined4 FUN_40252214(void)

{
  WaitForAPIReady(0x55,0xffffffff);
  DAT_402530e4 = L"UIO1:";
  FUN_40252178();
  return 0;
}



/* 4025224c ETM_Init */

/* Boundary evidence: original MIPS .pdata 4025224c..40252293. Semantic name remains unreviewed. */

undefined4 ETM_Init(void)

{
  HANDLE hObject;
  
                    /* 0x224c  4  ETM_Init */
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40252214,(LPVOID)0x0,0,(LPDWORD)0x0);
  CloseHandle(hObject);
  return 1;
}



/* 40252394 entry */

/* Boundary evidence: original MIPS .pdata 40252394..40252407. Semantic name remains unreviewed. */

undefined4 entry(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_40252408();
    FUN_402526dc();
  }
  uVar1 = FUN_402511a0(param_1,param_2);
  if (param_2 == 0) {
    FUN_40252664();
  }
  return uVar1;
}



/* 40252408 FUN_40252408 */

/* Boundary evidence: original MIPS .pdata 40252408..4025247b. Semantic name remains unreviewed. */

void FUN_40252408(void)

{
  uint uVar1;
  
  if ((DAT_402530c0 == 0) || (DAT_402530c0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_402530c0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_402530c0 == 0) {
      DAT_402530c0 = 0xb064;
    }
  }
  DAT_402530c4 = ~DAT_402530c0;
  return;
}



/* 4025247c FUN_4025247c */

/* Boundary evidence: original MIPS .pdata 4025247c..402524cf. Semantic name remains unreviewed. */

void FUN_4025247c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_402524fc(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 402524d0 FUN_402524d0 */

/* Boundary evidence: original MIPS .pdata 402524d0..402524fb. Semantic name remains unreviewed. */

undefined4 FUN_402524d0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_4025247c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 402524fc FUN_402524fc */

/* Boundary evidence: original MIPS .pdata 402524fc..40252543. Semantic name remains unreviewed. */

void FUN_402524fc(uint param_1)

{
  if ((param_1 == DAT_402530c0) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40252544 FUN_40252544 */

/* Boundary evidence: original MIPS .pdata 40252544..40252663. Semantic name remains unreviewed. */

void FUN_40252544(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_4025310c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40253138;
    if (DAT_40253138 != (undefined4 *)0x0) {
      while (DAT_40253134 = DAT_40253134 + -1, _Memory <= DAT_40253134) {
        if ((code *)*DAT_40253134 != (code *)0x0) {
          (*(code *)*DAT_40253134)();
          _Memory = DAT_40253138;
        }
      }
      free(_Memory);
      DAT_40253134 = (undefined4 *)0x0;
      DAT_40253138 = (undefined4 *)0x0;
    }
    FUN_40252688((undefined4 *)&DAT_40251010,(undefined4 *)&DAT_40251014);
  }
  FUN_40252688((undefined4 *)&DAT_40251018,(undefined4 *)&DAT_4025101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_4025313c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40252664 FUN_40252664 */

/* Boundary evidence: original MIPS .pdata 40252664..40252687. Semantic name remains unreviewed. */

void FUN_40252664(void)

{
  FUN_40252544(0,0,1);
  return;
}



/* 40252688 FUN_40252688 */

/* Boundary evidence: original MIPS .pdata 40252688..402526db. Semantic name remains unreviewed. */

void FUN_40252688(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 402526dc FUN_402526dc */

/* Boundary evidence: original MIPS .pdata 402526dc..40252717. Semantic name remains unreviewed. */

void FUN_402526dc(void)

{
  FUN_40252688((undefined4 *)&DAT_40251008,(undefined4 *)&DAT_4025100c);
  FUN_40252688((undefined4 *)&DAT_40251000,(undefined4 *)&DAT_40251004);
  return;
}


