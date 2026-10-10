/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c059112c FUN_c059112c */

/* Boundary evidence: original MIPS .pdata c059112c..c059115f. Semantic name remains unreviewed. */

undefined4 FUN_c059112c(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0591160 FUN_c0591160 */

/* Boundary evidence: original MIPS .pdata c0591160..c059130f. Semantic name remains unreviewed. */

undefined4 FUN_c0591160(void)

{
  DWORD DVar1;
  int iVar2;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  int local_30 [2];
  
  DVar1 = WaitForSingleObject(DAT_c05930c0,0xffffffff);
  do {
    if (DVar1 != 0) {
      return 1;
    }
    iVar2 = ReadMsgQueue(DAT_c05930c0,local_30,8,auStack_34,1,auStack_38);
    while (iVar2 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05930ac);
      if (local_30[0] == 1) {
        DAT_c05930c4 = 1;
        DAT_c05930d8 = 0;
        DAT_c05930dc = 0;
      }
      else if (local_30[0] == 2) {
        DAT_c05930c4 = 0;
        DAT_c05930dc = GetTickCount();
      }
      else {
        if (local_30[0] == 3) {
          DAT_c05930d8 = GetTickCount();
        }
        else {
          if (local_30[0] != 4) goto LAB_c0591290;
          DAT_c05930e0 = 1;
        }
        if (DAT_c05930c8 != 0) {
          EventModify(DAT_c05930e8,3);
        }
      }
LAB_c0591290:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05930ac);
      iVar2 = ReadMsgQueue(DAT_c05930c0,local_30,8,auStack_34,1,auStack_38);
    }
    DVar1 = WaitForSingleObject(DAT_c05930c0,0xffffffff);
  } while( true );
}



/* c0591310 FUN_c0591310 */

/* Boundary evidence: original MIPS .pdata c0591310..c059147f. Semantic name remains unreviewed. */

undefined4 FUN_c0591310(LPBYTE param_1,DWORD param_2)

{
  DWORD DVar1;
  LSTATUS LVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  HKEY local_20;
  DWORD local_1c;
  DWORD local_18 [2];
  
  uVar5 = 0;
  local_20 = (HKEY)0x0;
  DVar1 = GetTickCount();
  if ((((DAT_c05930c4 == 0) &&
       ((DAT_c05930d8 == 0 ||
        (uVar4 = (int)(DAT_c05930d8 - DVar1) >> 0x1f,
        4999 < (int)((DAT_c05930d8 - DVar1 ^ uVar4) - uVar4))))) &&
      ((DAT_c05930dc == 0 ||
       (uVar4 = (int)(DAT_c05930dc - DVar1) >> 0x1f,
       9999 < (int)((DAT_c05930dc - DVar1 ^ uVar4) - uVar4))))) &&
     (LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Autoras",0,0x20019,&local_20), LVar2 != 2)) {
    if (local_20 == (HKEY)0x0) {
      return 0;
    }
    local_1c = param_2;
    LVar2 = RegQueryValueExW(local_20,L"RasEntry",(LPDWORD)0x0,local_18,param_1,&local_1c);
    if (((LVar2 == 0) && (local_18[0] == 1)) && (iVar3 = FUN_c0591c2c(), iVar3 == 0)) {
      uVar5 = 1;
    }
  }
  if (local_20 != (HKEY)0x0) {
    RegCloseKey(local_20);
  }
  return uVar5;
}



/* c0591480 FUN_c0591480 */

/* Boundary evidence: original MIPS .pdata c0591480..c059164b. Semantic name remains unreviewed. */

undefined4 FUN_c0591480(wchar_t *param_1)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  size_t sVar5;
  LPWSTR pszDest;
  BOOL BVar6;
  SIZE_T uBytes;
  undefined4 uVar7;
  
  uVar7 = 0;
  iVar1 = FUN_c0591df8(param_1);
  iVar2 = FUN_c0591d18(param_1);
  if (iVar2 == 0) {
    sVar3 = wcslen(DAT_c05930d0);
    sVar4 = wcslen(DAT_c05930d4);
    sVar5 = wcslen(param_1);
    uBytes = (sVar5 + sVar4 + sVar3 + 6) * 2;
    pszDest = LocalAlloc(0x40,uBytes);
    if (pszDest != (LPWSTR)0x0) {
      if (iVar1 == 0) {
        iVar1 = StringCbPrintfW(pszDest,uBytes,L"%s %s\"%s\"",DAT_c05930d4,DAT_c05930d0,param_1);
      }
      else {
        iVar1 = StringCbPrintfW(pszDest,uBytes,L"%s\"%s\"",DAT_c05930d0,param_1);
      }
      if (((iVar1 == 0) && (DAT_c05930c4 == 0)) &&
         (BVar6 = CreateProcessW(DAT_c05930cc,pszDest,(LPSECURITY_ATTRIBUTES)0x0,
                                 (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                                 (LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0), BVar6 != 0)) {
        DAT_c05930c4 = 1;
        if (DAT_c05930c8 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05930ac);
          WaitForSingleObject(DAT_c05930e8,30000);
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05930ac);
          DAT_c05930e0 = 0;
          EventModify(DAT_c05930e8,2);
        }
        uVar7 = 1;
      }
      LocalFree(pszDest);
    }
  }
  return uVar7;
}



/* c059164c FUN_c059164c */

/* Boundary evidence: original MIPS .pdata c059164c..c059172f. Semantic name remains unreviewed. */

undefined4 FUN_c059164c(HKEY param_1,LPCWSTR param_2,undefined4 *param_3)

{
  LPBYTE lpData;
  LSTATUS LVar1;
  undefined4 uVar2;
  DWORD local_28;
  DWORD local_24;
  
  local_24 = 0;
  local_28 = 0;
  uVar2 = 0;
  RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_24,(LPBYTE)0x0,&local_28);
  if (local_24 == 1) {
    local_28 = local_28 + 2;
    lpData = LocalAlloc(0x40,local_28);
    *param_3 = lpData;
    if (lpData != (LPBYTE)0x0) {
      LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_24,lpData,&local_28);
      if (LVar1 == 0) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



/* c0591730 FUN_c0591730 */

/* Boundary evidence: original MIPS .pdata c0591730..c0591807. Semantic name remains unreviewed. */

undefined4 FUN_c0591730(void)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 uVar3;
  HKEY local_10 [2];
  
  uVar3 = 0;
  local_10[0] = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Autoras",0,0x20019,local_10);
  if ((LVar1 != 2) &&
     (iVar2 = FUN_c059164c(local_10[0],L"Dialer",&DAT_c05930cc), uVar3 = 0, iVar2 != 0)) {
    FUN_c059164c(local_10[0],L"RasEntryOpt",&DAT_c05930d0);
    FUN_c059164c(local_10[0],L"NoPromptOpt",&DAT_c05930d4);
    uVar3 = 1;
  }
  if (local_10[0] != (HKEY)0x0) {
    RegCloseKey(local_10[0]);
  }
  return uVar3;
}



/* c0591808 ARS_Init */

/* Boundary evidence: original MIPS .pdata c0591808..c059197f. Semantic name remains unreviewed. */

undefined4 ARS_Init(void)

{
  int iVar1;
  HANDLE hObject;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
                    /* 0x1808  4  ARS_Init */
  iVar1 = FUN_c0591730();
  if (iVar1 != 0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05930ac);
    local_24 = 2;
    local_20 = 8;
    local_1c = 8;
    local_28 = 0x14;
    local_18 = 1;
    DAT_c05930c0 = CreateMsgQueue(L"AutorasMsgqueue",&local_28);
    if (DAT_c05930c0 == 0) goto LAB_c05918fc;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0591160,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
      DAT_c05930e8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
      if (DAT_c05930e8 != (HANDLE)0x0) {
        return 0x12345678;
      }
    }
  }
  if (DAT_c05930c0 != 0) {
    CloseMsgQueue();
  }
LAB_c05918fc:
  if (DAT_c05930cc != (HLOCAL)0x0) {
    LocalFree(DAT_c05930cc);
  }
  if (DAT_c05930d0 != (HLOCAL)0x0) {
    LocalFree(DAT_c05930d0);
  }
  if (DAT_c05930d4 != (HLOCAL)0x0) {
    LocalFree(DAT_c05930d4);
  }
  if (DAT_c05930e8 != (HANDLE)0x0) {
    CloseHandle(DAT_c05930e8);
  }
  return 0;
}



/* c0591980 ARS_Deinit */

/* Boundary evidence: original MIPS .pdata c0591980..c0591a23. Semantic name remains unreviewed. */

undefined4 ARS_Deinit(void)

{
                    /* 0x1980  2  ARS_Deinit */
  if (DAT_c05930c0 != 0) {
    CloseMsgQueue();
  }
  if (DAT_c05930cc != (HLOCAL)0x0) {
    LocalFree(DAT_c05930cc);
  }
  if (DAT_c05930d0 != (HLOCAL)0x0) {
    LocalFree(DAT_c05930d0);
  }
  if (DAT_c05930d4 != (HLOCAL)0x0) {
    LocalFree(DAT_c05930d4);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c05930ac);
  if (DAT_c05930e8 != 0) {
    CloseHandle((HANDLE)DAT_c05930e8);
  }
  return 1;
}



/* c0591a24 ARS_Close */

undefined4 ARS_Close(void)

{
                    /* 0x1a24  1  ARS_Close
                       0x1a24  5  ARS_Open */
  return 1;
}



/* c0591a2c ARS_Read */

undefined4 ARS_Read(void)

{
                    /* 0x1a2c  6  ARS_Read
                       0x1a2c  8  ARS_Write
                       0x1a2c  11  DriverEntry */
  return 0;
}



/* c0591a34 ARS_Seek */

undefined4 ARS_Seek(void)

{
                    /* 0x1a34  7  ARS_Seek */
  return 0xffffffff;
}



/* c0591a3c ARS_IOControl */

/* Boundary evidence: original MIPS .pdata c0591a3c..c0591b27. Semantic name remains unreviewed. */

undefined4 ARS_IOControl(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t awStack_48 [22];
  uint local_1c;
  
                    /* 0x1a3c  3  ARS_IOControl */
  local_1c = DAT_c05930a4;
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05930ac);
  if (param_2 != 0x120800) {
    if (param_2 != 0x120804) {
      uVar2 = 0;
      goto LAB_c0591adc;
    }
    if (DAT_c05930c4 == 0) {
      DAT_c05930c8 = 1;
    }
  }
  iVar1 = FUN_c0591310((LPBYTE)awStack_48,0x2a);
  if (iVar1 != 0) {
    uVar2 = FUN_c0591480(awStack_48);
  }
LAB_c0591adc:
  DAT_c05930c8 = 0;
  if (param_2 != 0x120804) {
    uVar2 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05930ac);
  FUN_c05921a4(local_1c);
  return uVar2;
}



/* c0591b28 FUN_c0591b28 */

/* Boundary evidence: original MIPS .pdata c0591b28..c0591beb. Semantic name remains unreviewed. */

BOOL FUN_c0591b28(DWORD param_1)

{
  HANDLE hDevice;
  BOOL BVar1;
  
  hDevice = CreateFileW(L"ARS1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0xffffffff);
  if (hDevice == (HANDLE)0xffffffff) {
    BVar1 = 0;
  }
  else {
    BVar1 = DeviceIoControl(hDevice,param_1,(LPVOID)0x0,0,(LPVOID)0x0,0,(LPDWORD)0x0,
                            (LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  return BVar1;
}



/* c0591bec Autoras_Dial */

/* Boundary evidence: original MIPS .pdata c0591bec..c0591c0b. Semantic name remains unreviewed. */

void Autoras_Dial(void)

{
                    /* 0x1bec  9  Autoras_Dial */
  FUN_c0591b28(0x120800);
  return;
}



/* c0591c0c Autoras_Dial_Sync */

/* Boundary evidence: original MIPS .pdata c0591c0c..c0591c2b. Semantic name remains unreviewed. */

void Autoras_Dial_Sync(void)

{
                    /* 0x1c0c  10  Autoras_Dial_Sync */
  FUN_c0591b28(0x120804);
  return;
}



/* c0591c2c FUN_c0591c2c */

/* Boundary evidence: original MIPS .pdata c0591c2c..c0591d17. Semantic name remains unreviewed. */

undefined4 FUN_c0591c2c(void)

{
  SIZE_T *pSVar1;
  int iVar2;
  SIZE_T *hMem;
  ulong uVar3;
  SIZE_T *pSVar4;
  undefined4 uVar5;
  SIZE_T local_20 [2];
  
  local_20[0] = 0;
  uVar5 = 1;
  iVar2 = GetAdaptersInfo(0,local_20);
  if (iVar2 == 0x6f) {
    hMem = LocalAlloc(0x40,local_20[0]);
    if ((hMem != (SIZE_T *)0x0) &&
       (iVar2 = GetAdaptersInfo(hMem,local_20), pSVar4 = hMem, pSVar1 = (SIZE_T *)local_20[0],
       iVar2 == 0)) {
      while (pSVar1 != (SIZE_T *)0x0) {
        uVar3 = inet_addr((char *)(pSVar4[0x6a] + 4));
        if (((uVar3 != 0) && ((uVar3 & 0xff) != 0xa9)) && ((uVar3 & 0xff) != 0)) goto LAB_c0591ce8;
        pSVar4 = (SIZE_T *)*pSVar4;
        pSVar1 = pSVar4;
      }
      uVar5 = 0;
LAB_c0591ce8:
      if (hMem != (SIZE_T *)0x0) {
        LocalFree(hMem);
      }
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



/* c0591d18 FUN_c0591d18 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0591d18..c0591df7. Semantic name remains unreviewed. */

undefined4 FUN_c0591d18(wchar_t *param_1)

{
  undefined4 *hMem;
  int iVar1;
  undefined4 uVar2;
  wchar_t *_Str1;
  uint uVar3;
  uint local_20 [2];
  
  uVar2 = 0;
  if ((param_1 == (wchar_t *)0x0) || (hMem = LocalAlloc(0x40,0x208), hMem == (undefined4 *)0x0)) {
    uVar2 = 1;
  }
  else {
    local_20[1] = 0x208;
    *hMem = 0x34;
    iVar1 = RasEnumConnections(hMem,local_20 + 1,local_20);
    if (iVar1 == 0) {
      uVar3 = 0;
      if (local_20[0] != 0) {
        _Str1 = (wchar_t *)(hMem + 2);
        do {
          iVar1 = _wcsicmp(_Str1,param_1);
          if (iVar1 == 0) goto LAB_c0591dc8;
          uVar3 = uVar3 + 1;
          _Str1 = _Str1 + 0x1a;
        } while (uVar3 < local_20[0]);
      }
    }
    else {
LAB_c0591dc8:
      uVar2 = 1;
    }
    LocalFree(hMem);
  }
  return uVar2;
}



/* c0591df8 FUN_c0591df8 */

/* Boundary evidence: original MIPS .pdata c0591df8..c0591f2b. Semantic name remains unreviewed. */

undefined4 FUN_c0591df8(wchar_t *param_1)

{
  undefined4 *_Dst;
  undefined4 *hMem;
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28;
  int local_24;
  
  uVar2 = 0;
  _Dst = LocalAlloc(0,0x5b8);
  if (_Dst != (undefined4 *)0x0) {
    hMem = LocalAlloc(0,0xd90);
    if (hMem != (undefined4 *)0x0) {
      *hMem = 0xd90;
      local_28 = 0xd90;
      iVar1 = RasGetEntryProperties(0,param_1,hMem,&local_28,0,0);
      if ((iVar1 == 0) && (iVar1 = wcscmp((wchar_t *)(hMem + 0x1d9),L"modem"), iVar1 == 0)) {
        memset(_Dst,0,0x5b8);
        *_Dst = 0x5b8;
        wcscpy((wchar_t *)(_Dst + 1),param_1);
        RasGetEntryDialParams(0,_Dst,&local_24);
        if (local_24 == 0) {
          uVar2 = 1;
        }
      }
      LocalFree(_Dst);
      LocalFree(hMem);
      return uVar2;
    }
    LocalFree(_Dst);
  }
  return 0;
}



/* c059203c entry */

/* Boundary evidence: original MIPS .pdata c059203c..c05920af. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c05920b0();
    FUN_c0592384();
  }
  uVar1 = FUN_c059112c(param_1,param_2);
  if (param_2 == 0) {
    FUN_c059230c();
  }
  return uVar1;
}



/* c05920b0 FUN_c05920b0 */

/* Boundary evidence: original MIPS .pdata c05920b0..c0592123. Semantic name remains unreviewed. */

void FUN_c05920b0(void)

{
  uint uVar1;
  
  if ((DAT_c05930a4 == 0) || (DAT_c05930a4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c05930a4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c05930a4 == 0) {
      DAT_c05930a4 = 0xb064;
    }
  }
  DAT_c05930a8 = ~DAT_c05930a4;
  return;
}



/* c0592124 FUN_c0592124 */

/* Boundary evidence: original MIPS .pdata c0592124..c0592177. Semantic name remains unreviewed. */

void FUN_c0592124(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c05921a4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0592178 FUN_c0592178 */

/* Boundary evidence: original MIPS .pdata c0592178..c05921a3. Semantic name remains unreviewed. */

undefined4 FUN_c0592178(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0592124(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c05921a4 FUN_c05921a4 */

/* Boundary evidence: original MIPS .pdata c05921a4..c05921eb. Semantic name remains unreviewed. */

void FUN_c05921a4(uint param_1)

{
  if ((param_1 == DAT_c05930a4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c05921ec FUN_c05921ec */

/* Boundary evidence: original MIPS .pdata c05921ec..c059230b. Semantic name remains unreviewed. */

void FUN_c05921ec(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c05930e4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c05930f0;
    if (DAT_c05930f0 != (undefined4 *)0x0) {
      while (DAT_c05930ec = DAT_c05930ec + -1, _Memory <= DAT_c05930ec) {
        if ((code *)*DAT_c05930ec != (code *)0x0) {
          (*(code *)*DAT_c05930ec)();
          _Memory = DAT_c05930f0;
        }
      }
      free(_Memory);
      DAT_c05930ec = (undefined4 *)0x0;
      DAT_c05930f0 = (undefined4 *)0x0;
    }
    FUN_c0592330((undefined4 *)&DAT_c0591010,(undefined4 *)&DAT_c0591014);
  }
  FUN_c0592330((undefined4 *)&DAT_c0591018,(undefined4 *)&DAT_c059101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c05930f4,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c059230c FUN_c059230c */

/* Boundary evidence: original MIPS .pdata c059230c..c059232f. Semantic name remains unreviewed. */

void FUN_c059230c(void)

{
  FUN_c05921ec(0,0,1);
  return;
}



/* c0592330 FUN_c0592330 */

/* Boundary evidence: original MIPS .pdata c0592330..c0592383. Semantic name remains unreviewed. */

void FUN_c0592330(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0592384 FUN_c0592384 */

/* Boundary evidence: original MIPS .pdata c0592384..c05923bf. Semantic name remains unreviewed. */

void FUN_c0592384(void)

{
  FUN_c0592330((undefined4 *)&DAT_c0591008,(undefined4 *)&DAT_c059100c);
  FUN_c0592330((undefined4 *)&DAT_c0591000,(undefined4 *)&DAT_c0591004);
  return;
}


