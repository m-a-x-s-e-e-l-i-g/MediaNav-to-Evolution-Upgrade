/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c05810f4 FUN_c05810f4 */

/* Boundary evidence: original MIPS .pdata c05810f4..c0581127. Semantic name remains unreviewed. */

undefined4 FUN_c05810f4(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0581128 NPW_Deinit */

/* Boundary evidence: original MIPS .pdata c0581128..c058114b. Semantic name remains unreviewed. */

undefined4 NPW_Deinit(void)

{
                    /* 0x1128  3  NPW_Deinit */
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c05830c0);
  return 1;
}



/* c058114c NPW_Close */

undefined4 NPW_Close(void)

{
                    /* 0x114c  2  NPW_Close
                       0x114c  6  NPW_Open */
  return 1;
}



/* c0581154 DriverEntry */

undefined4 DriverEntry(void)

{
                    /* 0x1154  1  DriverEntry
                       0x1154  7  NPW_Read
                       0x1154  9  NPW_Write */
  return 0;
}



/* c058115c NPW_Seek */

undefined4 NPW_Seek(void)

{
                    /* 0x115c  8  NPW_Seek */
  return 0xffffffff;
}



/* c0581164 FUN_c0581164 */

/* Boundary evidence: original MIPS .pdata c0581164..c0581257. Semantic name remains unreviewed. */

undefined4 FUN_c0581164(LPCWSTR param_1,int param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  int local_res4 [3];
  HKEY local_18 [2];
  
  uVar2 = 0;
  local_18[0] = (HKEY)0x0;
  local_res4[0] = param_2;
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"Comm\\NdisPower",0,(LPWSTR)0x0,0,0x20006,
                          (LPSECURITY_ATTRIBUTES)0x0,local_18,(LPDWORD)0x0);
  if (LVar1 == 0) {
    if (local_res4[0] == -1) {
      RegDeleteValueW(local_18[0],param_1);
    }
    else {
      RegSetValueExW(local_18[0],param_1,0,4,(BYTE *)local_res4,4);
    }
    uVar2 = 1;
  }
  if (local_18[0] != (HKEY)0x0) {
    RegCloseKey(local_18[0]);
  }
  return uVar2;
}



/* c0581258 FUN_c0581258 */

/* Boundary evidence: original MIPS .pdata c0581258..c058133f. Semantic name remains unreviewed. */

undefined4 FUN_c0581258(LPCWSTR param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_28;
  DWORD local_24;
  DWORD local_20 [2];
  
  uVar2 = 0;
  local_28 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\NdisPower",0,0x20019,&local_28);
  if (LVar1 != 2) {
    local_24 = 4;
    LVar1 = RegQueryValueExW(local_28,param_1,(LPDWORD)0x0,local_20,param_2,&local_24);
    if ((LVar1 == 0) && (local_20[0] == 4)) {
      uVar2 = 1;
    }
  }
  if (local_28 != (HKEY)0x0) {
    RegCloseKey(local_28);
  }
  return uVar2;
}



/* c0581340 FUN_c0581340 */

/* Boundary evidence: original MIPS .pdata c0581340..c0581437. Semantic name remains unreviewed. */

BOOL FUN_c0581340(DWORD param_1,LPVOID param_2,DWORD param_3,LPVOID param_4,LPDWORD param_5)

{
  HANDLE hDevice;
  DWORD nOutBufferSize;
  BOOL BVar1;
  
  BVar1 = 0;
  hDevice = CreateFileW(L"NDS0:",0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,4,0,(HANDLE)0x0);
  if (hDevice != (HANDLE)0xffffffff) {
    if (param_5 == (LPDWORD)0x0) {
      nOutBufferSize = 0;
    }
    else {
      nOutBufferSize = *param_5;
    }
    BVar1 = DeviceIoControl(hDevice,param_1,param_2,param_3,param_4,nOutBufferSize,param_5,
                            (LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  return BVar1;
}



/* c0581438 FUN_c0581438 */

/* Boundary evidence: original MIPS .pdata c0581438..c0581527. Semantic name remains unreviewed. */

undefined4 FUN_c0581438(LPCWSTR param_1)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  int local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c0583094;
  uVar3 = 0;
  iVar1 = FUN_c0581258(param_1,(LPBYTE)local_228);
  if ((iVar1 != 0) && (local_228[0] != -1)) {
    iVar1 = _snwprintf(awStack_220,0x103,L"%s\\%s",L"{98C5250D-C29A-4985-AE5F-AFE5367E5006}",param_1
                      );
    uVar3 = 1;
    if (iVar1 != -1) {
      SetDevicePower(awStack_220,1,local_228[0]);
    }
    memset(awStack_220,0,0x208);
    StringCchCopyW(awStack_220,0x103,param_1);
    sVar2 = wcslen(param_1);
    FUN_c0581340(0x170036,awStack_220,(sVar2 + 2) * 2,(LPVOID)0x0,(LPDWORD)0x0);
  }
  FUN_c0581e10(local_18);
  return uVar3;
}



/* c0581528 FUN_c0581528 */

/* Boundary evidence: original MIPS .pdata c0581528..c058163b. Semantic name remains unreviewed. */

undefined4 FUN_c0581528(void)

{
  int iVar1;
  DWORD DVar2;
  undefined1 auStack_238 [4];
  undefined1 auStack_234 [4];
  uint local_230;
  WCHAR aWStack_22c [264];
  uint local_1c;
  
  local_1c = DAT_c0583094;
  do {
    iVar1 = WaitForAPIReady(0x55,500);
  } while (iVar1 != 0);
  DVar2 = WaitForSingleObject(DAT_c05830a0,0xffffffff);
  while (DVar2 == 0) {
    iVar1 = ReadMsgQueue(DAT_c05830a0,&local_230,0x214,auStack_238,1,auStack_234);
    while (iVar1 != 0) {
      if ((local_230 & 0x10) != 0) {
        Sleep(2000);
        FUN_c0581438(aWStack_22c);
      }
      iVar1 = ReadMsgQueue(DAT_c05830a0,&local_230,0x214,auStack_238,1,auStack_234);
    }
    DVar2 = WaitForSingleObject(DAT_c05830a0,0xffffffff);
  }
  FUN_c0581e10(local_1c);
  return 0;
}



/* c058163c FUN_c058163c */

/* Boundary evidence: original MIPS .pdata c058163c..c05818f3. Semantic name remains unreviewed. */

undefined4 FUN_c058163c(void)

{
  int iVar1;
  HANDLE pvVar2;
  int iVar3;
  BOOL BVar4;
  LPCWSTR pWVar5;
  undefined4 uVar6;
  DWORD aDStack_458 [2];
  int local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  WCHAR WStack_432;
  int local_430;
  int local_42c;
  uint local_428;
  uint local_30;
  
  local_30 = DAT_c0583094;
  uVar6 = 0;
  do {
    iVar1 = WaitForAPIReady(0x55,500);
  } while (iVar1 != 0);
  iVar1 = 0;
  pvVar2 = CreateFileW(L"UIO1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0xffffffff);
  DAT_c05830a4 = pvVar2;
  if (pvVar2 == (HANDLE)0xffffffff) {
    GetLastError();
LAB_c05816ec:
    if (DAT_c05830a0 != 0) {
      CloseMsgQueue();
    }
  }
  else {
    memset(&local_430,0,0x14);
    local_430 = 0;
    iVar3 = DeviceIoControl(pvVar2,0x12080c,&local_430,0x14,&local_430,0x400,aDStack_458,
                            (LPOVERLAPPED)0x0);
    while (iVar3 != 0) {
      pWVar5 = (LPCWSTR)((int)&local_430 + local_42c);
      *(undefined2 *)((int)pWVar5 + ((local_428 & 0xfffffffe) - 2)) = 0;
      iVar3 = FUN_c0581438(pWVar5);
      if (iVar3 == 0) {
        iVar1 = iVar1 + 1;
      }
      else {
        iVar1 = 0;
      }
      memset(&local_430,0,0x14);
      local_430 = iVar1;
      iVar3 = DeviceIoControl(DAT_c05830a4,0x12080c,&local_430,0x14,&local_430,0x400,aDStack_458,
                              (LPOVERLAPPED)0x0);
    }
    local_448 = 0x14;
    local_444 = 0;
    local_440 = 4;
    local_43c = 0x214;
    local_438 = 1;
    DAT_c05830a0 = CreateMsgQueue(0,&local_448);
    if (DAT_c05830a0 != 0) {
      local_44c = 0x10;
      local_450 = DAT_c05830a0;
      BVar4 = DeviceIoControl(DAT_c05830a4,0x12081c,&local_450,8,(LPVOID)0x0,0,(LPDWORD)0x0,
                              (LPOVERLAPPED)0x0);
      if (BVar4 != 0) {
        pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0581528,(LPVOID)0x0,0,(LPDWORD)0x0);
        CloseHandle(pvVar2);
        uVar6 = 1;
        goto LAB_c058171c;
      }
      goto LAB_c05816ec;
    }
  }
  if (DAT_c05830a4 != (HANDLE)0x0) {
    CloseHandle(DAT_c05830a4);
  }
LAB_c058171c:
  FUN_c0581e10(local_30);
  return uVar6;
}



/* c05818f4 NPW_Init */

/* Boundary evidence: original MIPS .pdata c05818f4..c0581973. Semantic name remains unreviewed. */

undefined4 NPW_Init(void)

{
  HANDLE hObject;
  undefined4 uVar1;
  
                    /* 0x18f4  5  NPW_Init */
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05830c0);
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c058163c,(LPVOID)0x0,0,(LPDWORD)0x0);
  if (hObject == (HANDLE)0x0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c05830c0);
    uVar1 = 0xffffffff;
  }
  else {
    CloseHandle(hObject);
    uVar1 = 0xce01ce01;
  }
  return uVar1;
}



/* c0581974 NPW_IOControl */

/* Boundary evidence: original MIPS .pdata c0581974..c0581bbf. Semantic name remains unreviewed. */

int NPW_IOControl(undefined4 param_1,int param_2,undefined4 *param_3,int param_4,undefined4 *param_5
                 ,int param_6)

{
  int iVar1;
  int iVar2;
  LPCWSTR local_28;
  undefined4 local_24;
  int local_20 [2];
  
                    /* 0x1974  4  NPW_IOControl */
  iVar2 = 0;
  local_24 = 0;
  local_28 = (LPCWSTR)0x0;
  if (param_2 == 0x120800) {
    if ((param_4 == 8) && (param_3 != (undefined4 *)0x0)) {
      local_20[0] = param_3[1];
      iVar2 = CeOpenCallerBuffer(&local_28,*param_3,0,5,1);
      if (iVar2 != 0) {
        local_28 = (LPCWSTR)0x0;
      }
      if (local_28 == (LPCWSTR)0x0) {
        SetLastError(0x57);
        return 0;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05830c0);
      iVar2 = FUN_c0581164(local_28,local_20[0]);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05830c0);
      if (local_28 == (LPCWSTR)0x0) {
        return iVar2;
      }
      CeCloseCallerBuffer(local_28,*param_3,0,5);
      return iVar2;
    }
  }
  else {
    if (param_2 != 0x120804) {
      return 0;
    }
    if ((param_6 == 8) && (param_5 != (undefined4 *)0x0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05830c0);
      iVar1 = CeOpenCallerBuffer(&local_28,*param_5,0,5,1);
      if (iVar1 == 0) {
        param_5[1] = 0;
        iVar2 = FUN_c0581258(local_28,(LPBYTE)local_20);
        if (iVar2 != 0) {
          param_5[1] = local_20[0];
        }
        iVar2 = 1;
        local_24 = 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05830c0);
      if (local_28 != (LPCWSTR)0x0) {
        CeCloseCallerBuffer(local_28,*param_5,0,5);
      }
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  SetLastError(0x57);
  return 0;
}



/* c0581bc0 FUN_c0581bc0 */

/* Boundary evidence: original MIPS .pdata c0581bc0..c0581bcb. Semantic name remains unreviewed. */

undefined4 FUN_c0581bc0(void)

{
  return 1;
}



/* c0581bcc FUN_c0581bcc */

/* Boundary evidence: original MIPS .pdata c0581bcc..c0581bd7. Semantic name remains unreviewed. */

undefined4 FUN_c0581bcc(void)

{
  return 1;
}



/* c0581ca8 entry */

/* Boundary evidence: original MIPS .pdata c0581ca8..c0581d1b. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c0581d1c();
    FUN_c0581ff0();
  }
  uVar1 = FUN_c05810f4(param_1,param_2);
  if (param_2 == 0) {
    FUN_c0581f78();
  }
  return uVar1;
}



/* c0581d1c FUN_c0581d1c */

/* Boundary evidence: original MIPS .pdata c0581d1c..c0581d8f. Semantic name remains unreviewed. */

void FUN_c0581d1c(void)

{
  uint uVar1;
  
  if ((DAT_c0583094 == 0) || (DAT_c0583094 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0583094 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0583094 == 0) {
      DAT_c0583094 = 0xb064;
    }
  }
  DAT_c0583098 = ~DAT_c0583094;
  return;
}



/* c0581d90 FUN_c0581d90 */

/* Boundary evidence: original MIPS .pdata c0581d90..c0581de3. Semantic name remains unreviewed. */

void FUN_c0581d90(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0581e10(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0581de4 FUN_c0581de4 */

/* Boundary evidence: original MIPS .pdata c0581de4..c0581e0f. Semantic name remains unreviewed. */

undefined4 FUN_c0581de4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0581d90(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0581e10 FUN_c0581e10 */

/* Boundary evidence: original MIPS .pdata c0581e10..c0581e57. Semantic name remains unreviewed. */

void FUN_c0581e10(uint param_1)

{
  if ((param_1 == DAT_c0583094) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0581e58 FUN_c0581e58 */

/* Boundary evidence: original MIPS .pdata c0581e58..c0581f77. Semantic name remains unreviewed. */

void FUN_c0581e58(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c05830a8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c05830d8;
    if (DAT_c05830d8 != (undefined4 *)0x0) {
      while (DAT_c05830d4 = DAT_c05830d4 + -1, _Memory <= DAT_c05830d4) {
        if ((code *)*DAT_c05830d4 != (code *)0x0) {
          (*(code *)*DAT_c05830d4)();
          _Memory = DAT_c05830d8;
        }
      }
      free(_Memory);
      DAT_c05830d4 = (undefined4 *)0x0;
      DAT_c05830d8 = (undefined4 *)0x0;
    }
    FUN_c0581f9c((undefined4 *)&DAT_c0581010,(undefined4 *)&DAT_c0581014);
  }
  FUN_c0581f9c((undefined4 *)&DAT_c0581018,(undefined4 *)&DAT_c058101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c05830dc,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0581f78 FUN_c0581f78 */

/* Boundary evidence: original MIPS .pdata c0581f78..c0581f9b. Semantic name remains unreviewed. */

void FUN_c0581f78(void)

{
  FUN_c0581e58(0,0,1);
  return;
}



/* c0581f9c FUN_c0581f9c */

/* Boundary evidence: original MIPS .pdata c0581f9c..c0581fef. Semantic name remains unreviewed. */

void FUN_c0581f9c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0581ff0 FUN_c0581ff0 */

/* Boundary evidence: original MIPS .pdata c0581ff0..c058202b. Semantic name remains unreviewed. */

void FUN_c0581ff0(void)

{
  FUN_c0581f9c((undefined4 *)&DAT_c0581008,(undefined4 *)&DAT_c058100c);
  FUN_c0581f9c((undefined4 *)&DAT_c0581000,(undefined4 *)&DAT_c0581004);
  return;
}


