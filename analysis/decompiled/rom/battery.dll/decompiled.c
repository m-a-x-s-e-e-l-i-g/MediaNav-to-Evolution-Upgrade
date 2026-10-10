/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0861218 FUN_c0861218 */

/* Boundary evidence: original MIPS .pdata c0861218..c0861347. Semantic name remains unreviewed. */

undefined4 FUN_c0861218(DWORD *param_1)

{
  bool bVar1;
  DWORD DVar2;
  int iVar3;
  undefined1 auStack_58 [56];
  
  bVar1 = false;
  CeSetThreadPriority(0x41,param_1[1]);
  PowerPolicyNotify(2,0);
  do {
    DVar2 = WaitForSingleObject(DAT_c08641a0,*param_1);
    if (DVar2 == 0) {
      FUN_c0862644(0,0);
      FUN_c0862644(1,0);
      FUN_c0862554();
    }
    else if (DVar2 == 0x102) {
      FUN_c0862768(auStack_58,0x38,1);
      iVar3 = memcmp(auStack_58,param_1 + 2,0x38);
      if (iVar3 != 0) {
        memcpy(param_1 + 2,auStack_58,0x38);
        PowerPolicyNotify(2,0);
      }
    }
    else {
      bVar1 = true;
    }
    if (DAT_c08641e0 != 0) {
      bVar1 = true;
    }
  } while (!bVar1);
  return 0;
}



/* c0861348 Init */

/* Boundary evidence: original MIPS .pdata c0861348..c086173f. Semantic name remains unreviewed. */

undefined4 Init(undefined4 param_1)

{
  HANDLE hObject;
  int iVar1;
  HKEY hKey;
  LSTATUS LVar2;
  DWORD local_38;
  DWORD local_34;
  uint local_30 [2];
  
                    /* 0x1348  4  Init */
  if (DAT_c08641a0 != (HANDLE)0x0) {
    return 0;
  }
  hObject = OpenEventW(0x1f0003,0,L"SYSTEM/BatteryAPIsReady");
  if (hObject != (HANDLE)0x0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0864140);
    DAT_c08641dc = 0x38;
    DAT_c08641a4 = 0;
    DAT_c08641d8 = (HLOCAL)0x0;
    DAT_c08641d4 = (HLOCAL)0x0;
    DAT_c08641a0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if ((DAT_c08641a0 != (HANDLE)0x0) && (iVar1 = FUN_c0862078(), iVar1 != 0)) {
      DAT_c0864160 = 5000;
      DAT_c0864164 = 0xf9;
      memset(&DAT_c0864168,0xff,0x38);
      hKey = (HKEY)OpenDeviceKey(param_1);
      if (hKey != (HKEY)0x0) {
        local_38 = 4;
        LVar2 = RegQueryValueExW(hKey,L"PollPriority256",(LPDWORD)0x0,&local_34,(LPBYTE)local_30,
                                 &local_38);
        if ((LVar2 == 0) && (local_34 == 4)) {
          DAT_c0864164 = local_30[0];
        }
        local_38 = 4;
        LVar2 = RegQueryValueExW(hKey,L"PollInterval",(LPDWORD)0x0,&local_34,(LPBYTE)local_30,
                                 &local_38);
        if ((LVar2 == 0) && (local_34 == 4)) {
          DAT_c0864160 = local_30[0];
        }
        local_38 = 4;
        LVar2 = RegQueryValueExW(hKey,L"PddBufferSize",(LPDWORD)0x0,&local_34,(LPBYTE)local_30,
                                 &local_38);
        if (((LVar2 == 0) && (local_34 == 4)) && (DAT_c08641dc < local_30[0])) {
          DAT_c08641dc = local_30[0];
        }
        RegCloseKey(hKey);
      }
      DAT_c08641d8 = LocalAlloc(0x40,DAT_c08641dc);
      if (DAT_c08641d8 == (HLOCAL)0x0) goto LAB_c086167c;
      DAT_c08641d4 = LocalAlloc(0x40,DAT_c08641dc);
      if (DAT_c08641d4 != (HLOCAL)0x0) {
        FUN_c0862768(&DAT_c0864168,0x38,1);
        DAT_c08641e4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0861218,&DAT_c0864160,0,
                                    (LPDWORD)0x0);
        if (DAT_c08641e4 != (HANDLE)0x0) {
          EventModify(hObject,3);
          CloseHandle(hObject);
          return 1;
        }
      }
    }
  }
  if (DAT_c08641d8 != (HLOCAL)0x0) {
    LocalFree(DAT_c08641d8);
    DAT_c08641d8 = (HLOCAL)0x0;
  }
LAB_c086167c:
  if (DAT_c08641d4 != (HLOCAL)0x0) {
    LocalFree(DAT_c08641d4);
    DAT_c08641d4 = (HLOCAL)0x0;
  }
  if (DAT_c08641e4 != (HANDLE)0x0) {
    DAT_c08641e0 = 1;
    EventModify(DAT_c08641a0,3);
    WaitForSingleObject(DAT_c08641e4,0xffffffff);
    CloseHandle(DAT_c08641e4);
    DAT_c08641e4 = (HANDLE)0x0;
  }
  if (DAT_c08641a0 != (HANDLE)0x0) {
    CloseHandle(DAT_c08641a0);
    DAT_c08641a0 = (HANDLE)0x0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0864140);
  return 0;
}



/* c0861740 Deinit */

/* Boundary evidence: original MIPS .pdata c0861740..c0861843. Semantic name remains unreviewed. */

undefined4 Deinit(void)

{
                    /* 0x1740  2  Deinit */
  FUN_c08624c0();
  if (DAT_c08641e4 != (HANDLE)0x0) {
    DAT_c08641e0 = 1;
    EventModify(DAT_c08641a0,3);
    WaitForSingleObject(DAT_c08641e4,0xffffffff);
    CloseHandle(DAT_c08641e4);
    DAT_c08641e4 = (HANDLE)0x0;
  }
  if (DAT_c08641a0 != 0) {
    CloseHandle((HANDLE)DAT_c08641a0);
    DAT_c08641a0 = 0;
  }
  if (DAT_c08641d8 != (HLOCAL)0x0) {
    LocalFree(DAT_c08641d8);
    DAT_c08641d8 = (HLOCAL)0x0;
  }
  if (DAT_c08641d4 != (HLOCAL)0x0) {
    LocalFree(DAT_c08641d4);
    DAT_c08641d4 = (HLOCAL)0x0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0864140);
  return 1;
}



/* c0861844 IOControl */

/* WARNING: Removing unreachable block (ram,0xc0861e58) */
/* Boundary evidence: original MIPS .pdata c0861844..c0861e73. Semantic name remains unreviewed. */

bool IOControl(undefined4 param_1,int param_2,uint *param_3,int param_4,int *param_5,uint param_6,
              size_t *param_7)

{
  DWORD dwErrCode;
  int iVar1;
  int local_58 [2];
  uint local_50;
  uint local_4c;
  undefined4 local_48;
  size_t local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  _SYSTEMTIME local_30;
  
                    /* 0x1844  3  IOControl */
  dwErrCode = 0x57;
  if (param_2 == 0x290400) {
    if ((((param_5 != (int *)0x0) && (param_6 == 0x18)) && (param_3 != (uint *)0x0)) &&
       ((param_4 == 4 && (param_7 != (size_t *)0x0)))) {
      local_38 = *param_3;
      iVar1 = FUN_c0862ab4(param_5,local_38);
      if (iVar1 == 0) {
        *param_7 = 0;
        dwErrCode = GetLastError();
      }
      else {
        *param_7 = 0x18;
        dwErrCode = 0;
      }
    }
  }
  else if (param_2 == 0x290404) {
    if (((param_5 != (int *)0x0) && (0x37 < param_6)) &&
       ((param_3 != (uint *)0x0 && ((param_4 == 4 && (param_7 != (size_t *)0x0)))))) {
      local_3c = *param_3;
      local_48 = 1;
      local_44 = 0;
      local_44 = FUN_c0862768(param_5,param_6,local_3c);
      *param_7 = local_44;
      if (local_44 == 0) {
        dwErrCode = GetLastError();
      }
      else {
        dwErrCode = 0;
      }
    }
  }
  else if (param_2 == 0x290408) {
    if ((param_5 != (int *)0x0) && (param_6 == 0x18)) {
      local_30.wYear = 0;
      memset(&local_30.wMonth,0,0xe);
      local_58[0] = 0;
      local_50 = 0;
      SetLastError(0);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
      FUN_c0862afc(&local_30,local_58,&local_50);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
      memcpy(param_5,&local_30,0x10);
      param_5[4] = local_58[0];
      param_5[5] = local_50;
      if (param_7 != (size_t *)0x0) {
        *param_7 = 4;
      }
      dwErrCode = GetLastError();
    }
  }
  else if (param_2 == 0x29040c) {
    if (((param_5 != (int *)0x0) && (param_6 == 4)) && (param_7 != (size_t *)0x0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
      iVar1 = FUN_c08625c8();
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
      *param_5 = iVar1;
      *param_7 = 4;
      dwErrCode = 0;
    }
  }
  else if (param_2 == 0x290410) {
    if (((param_5 != (int *)0x0) && (param_6 == 4)) && (param_7 != (size_t *)0x0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
      iVar1 = FUN_c086260c();
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
      *param_5 = iVar1;
      *param_7 = 4;
      dwErrCode = 0;
    }
  }
  else if (param_2 == 0x290414) {
    if (((param_3 != (uint *)0x0) && (param_4 == 8)) && ((param_5 != (int *)0x0 && (param_6 == 4))))
    {
      local_50 = *param_3;
      local_4c = param_3[1];
      iVar1 = *param_5;
      local_40 = iVar1;
      SetLastError(0);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
      FUN_c0862be0(iVar1,&local_50);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
      dwErrCode = GetLastError();
    }
  }
  else if (DAT_c08641a4 == (code *)0x0) {
    dwErrCode = 0x32;
  }
  else {
    dwErrCode = (*DAT_c08641a4)();
  }
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c0861e74 FUN_c0861e74 */

/* Boundary evidence: original MIPS .pdata c0861e74..c0861e7f. Semantic name remains unreviewed. */

undefined4 FUN_c0861e74(void)

{
  return 1;
}



/* c0861e80 FUN_c0861e80 */

/* Boundary evidence: original MIPS .pdata c0861e80..c0861e8b. Semantic name remains unreviewed. */

undefined4 FUN_c0861e80(void)

{
  return 1;
}



/* c0861e8c FUN_c0861e8c */

/* Boundary evidence: original MIPS .pdata c0861e8c..c0861e97. Semantic name remains unreviewed. */

undefined4 FUN_c0861e8c(void)

{
  return 1;
}



/* c0861e98 FUN_c0861e98 */

/* Boundary evidence: original MIPS .pdata c0861e98..c0861ea3. Semantic name remains unreviewed. */

undefined4 FUN_c0861e98(void)

{
  return 1;
}



/* c0861ea4 FUN_c0861ea4 */

/* Boundary evidence: original MIPS .pdata c0861ea4..c0861eaf. Semantic name remains unreviewed. */

undefined4 FUN_c0861ea4(void)

{
  return 1;
}



/* c0861eb0 FUN_c0861eb0 */

/* Boundary evidence: original MIPS .pdata c0861eb0..c0861ebb. Semantic name remains unreviewed. */

undefined4 FUN_c0861eb0(void)

{
  return 1;
}



/* c0861ebc FUN_c0861ebc */

/* Boundary evidence: original MIPS .pdata c0861ebc..c0861ec7. Semantic name remains unreviewed. */

undefined4 FUN_c0861ebc(void)

{
  return 1;
}



/* c0861ec8 FUN_c0861ec8 */

/* Boundary evidence: original MIPS .pdata c0861ec8..c0861ed3. Semantic name remains unreviewed. */

undefined4 FUN_c0861ec8(void)

{
  return 1;
}



/* c0861ed4 FUN_c0861ed4 */

/* Boundary evidence: original MIPS .pdata c0861ed4..c0861edf. Semantic name remains unreviewed. */

undefined4 FUN_c0861ed4(void)

{
  return 1;
}



/* c0861ee0 FUN_c0861ee0 */

/* Boundary evidence: original MIPS .pdata c0861ee0..c0861eeb. Semantic name remains unreviewed. */

undefined4 FUN_c0861ee0(void)

{
  return 1;
}



/* c0861eec PowerDown */

/* Boundary evidence: original MIPS .pdata c0861eec..c0861f07. Semantic name remains unreviewed. */

void PowerDown(void)

{
                    /* 0x1eec  6  PowerDown */
  FUN_c0862554();
  return;
}



/* c0861f08 PowerUp */

/* Boundary evidence: original MIPS .pdata c0861f08..c0861f3b. Semantic name remains unreviewed. */

void PowerUp(void)

{
                    /* 0x1f08  7  PowerUp */
  FUN_c0862554();
  if (DAT_c08641a0 != 0) {
    CeSetPowerOnEvent();
  }
  return;
}



/* c0861f3c Open */

undefined4 Open(undefined4 param_1)

{
                    /* 0x1f3c  5  Open */
  return param_1;
}



/* c0861f44 Close */

undefined4 Close(void)

{
                    /* 0x1f44  1  Close */
  return 1;
}



/* c0861f4c Read */

/* Boundary evidence: original MIPS .pdata c0861f4c..c0861f73. Semantic name remains unreviewed. */

undefined4 Read(void)

{
                    /* 0x1f4c  8  Read */
  SetLastError(1);
  return 0;
}



/* c0861f74 Write */

/* Boundary evidence: original MIPS .pdata c0861f74..c0861f9b. Semantic name remains unreviewed. */

undefined4 Write(void)

{
                    /* 0x1f74  10  Write */
  SetLastError(1);
  return 0;
}



/* c0861f9c Seek */

undefined4 Seek(void)

{
                    /* 0x1f9c  9  Seek */
  return 0xffffffff;
}



/* c0861fa4 FUN_c0861fa4 */

/* Boundary evidence: original MIPS .pdata c0861fa4..c0861fd7. Semantic name remains unreviewed. */

undefined4 FUN_c0861fa4(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0861fd8 FUN_c0861fd8 */

/* Boundary evidence: original MIPS .pdata c0861fd8..c0862023. Semantic name remains unreviewed. */

DWORD FUN_c0861fd8(void)

{
  DWORD DVar1;
  
  DVar1 = WaitForSingleObject(DAT_c0864118,5000);
  if (DVar1 == 0) {
    DVar1 = 0;
  }
  else {
    DVar1 = GetLastError();
  }
  return DVar1;
}



/* c0862024 FUN_c0862024 */

/* Boundary evidence: original MIPS .pdata c0862024..c0862077. Semantic name remains unreviewed. */

DWORD FUN_c0862024(void)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  BVar1 = ReleaseMutex(DAT_c0864118);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
  }
  return DVar2;
}



/* c0862078 FUN_c0862078 */

/* Boundary evidence: original MIPS .pdata c0862078..c08624bf. Semantic name remains unreviewed. */

int FUN_c0862078(void)

{
  undefined *puVar1;
  HKEY hKey;
  LSTATUS LVar2;
  HMODULE hLibModule;
  DWORD DVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  DWORD local_a8;
  DWORD local_a4;
  int local_a0 [2];
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_95;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a;
  undefined1 local_89;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64;
  BYTE aBStack_60 [56];
  
  local_95 = 0;
  iVar4 = 1;
  local_98 = 1;
  local_97 = 1;
  uVar6 = 3;
  local_96 = 0xff;
  uVar7 = 3;
  local_94 = 0xffffffff;
  uVar5 = 0;
  local_90 = 0xffffffff;
  local_8c = 0;
  local_8b = 1;
  local_8a = 0xff;
  local_89 = 0;
  local_88 = 0xffffffff;
  local_84 = 0xffffffff;
  local_64 = 0xff;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  hKey = (HKEY)OpenDeviceKey();
  if (hKey != (HKEY)0x0) {
    local_a8 = 4;
    LVar2 = RegQueryValueExW(hKey,L"MainLevels",(LPDWORD)0x0,&local_a4,(LPBYTE)local_a0,&local_a8);
    if ((LVar2 == 0) && (local_a4 == 4)) {
      uVar6 = (undefined2)local_a0[0];
    }
    local_a8 = 4;
    LVar2 = RegQueryValueExW(hKey,L"BackupLevels",(LPDWORD)0x0,&local_a4,(LPBYTE)local_a0,&local_a8)
    ;
    if ((LVar2 == 0) && (local_a4 == 4)) {
      uVar7 = (undefined2)local_a0[0];
    }
    local_a8 = 4;
    LVar2 = RegQueryValueExW(hKey,L"SupportsChange",(LPDWORD)0x0,&local_a4,(LPBYTE)local_a0,
                             &local_a8);
    if (((LVar2 == 0) && (local_a4 == 4)) && (uVar5 = 1, local_a0[0] == 0)) {
      uVar5 = 0;
    }
    local_a8 = 0x38;
    LVar2 = RegQueryValueExW(hKey,L"InitialStatus",(LPDWORD)0x0,&local_a4,aBStack_60,&local_a8);
    if (((LVar2 == 0) && (local_a4 == 3)) && (local_a8 == 0x38)) {
      memcpy(&local_98,aBStack_60,0x38);
    }
    RegCloseKey(hKey);
  }
  DAT_c0864118 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,L"Battery File Mutex");
  if (DAT_c0864118 == (HANDLE)0x0) goto LAB_c0862420;
  hLibModule = LoadLibraryW(L"coredll.dll");
  if (hLibModule != (HMODULE)0x0) {
    DAT_c0864110 = (code *)GetProcAddressW(hLibModule,L"CreateFileMappingW");
    DAT_c086410c = (code *)GetProcAddressW(hLibModule,L"MapViewOfFile");
    DAT_c0864114 = (code *)GetProcAddressW(hLibModule,L"UnmapViewOfFile");
  }
  FreeLibrary(hLibModule);
  FUN_c0861fd8();
  if (DAT_c0864110 == (code *)0x0) {
    DAT_c08640c4 = &DAT_c08640c8;
LAB_c08623e4:
    puVar1 = DAT_c08640c4;
    memcpy(DAT_c08640c4,&local_98,0x38);
    *(undefined4 *)(puVar1 + 0x3c) = uVar5;
    *(undefined4 *)(puVar1 + 0x40) = 0;
    *(undefined2 *)(puVar1 + 0x38) = uVar6;
    *(undefined2 *)(puVar1 + 0x3a) = uVar7;
  }
  else {
    DAT_c08640c0 = (*DAT_c0864110)(0xffffffff,0,4,0,0x44,L"Battery File");
    if (DAT_c08640c0 != 0) {
      DVar3 = GetLastError();
      if ((DAT_c086410c != (code *)0x0) &&
         (DAT_c08640c4 = (undefined *)(*DAT_c086410c)(DAT_c08640c0,0xf001f,0,0,0x44),
         DAT_c08640c4 != (undefined *)0x0)) {
        if (DVar3 != 0xb7) goto LAB_c08623e4;
        goto LAB_c086240c;
      }
    }
    iVar4 = 0;
  }
LAB_c086240c:
  FUN_c0862024();
  if (iVar4 != 0) {
    return iVar4;
  }
LAB_c0862420:
  if ((DAT_c08640c4 != (undefined *)0x0) && (DAT_c0864114 != (code *)0x0)) {
    (*DAT_c0864114)();
  }
  if (DAT_c08640c0 != 0) {
    CloseHandle((HANDLE)DAT_c08640c0);
  }
  if (DAT_c0864118 != (HANDLE)0x0) {
    CloseHandle(DAT_c0864118);
  }
  DAT_c0864118 = (HANDLE)0x0;
  DAT_c08640c4 = (undefined *)0x0;
  DAT_c08640c0 = 0;
  return 0;
}



/* c08624c0 FUN_c08624c0 */

/* Boundary evidence: original MIPS .pdata c08624c0..c0862553. Semantic name remains unreviewed. */

void FUN_c08624c0(void)

{
  if ((DAT_c08640c4 != 0) && (DAT_c0864114 != (code *)0x0)) {
    (*DAT_c0864114)();
  }
  if (DAT_c08640c0 != 0) {
    CloseHandle((HANDLE)DAT_c08640c0);
  }
  if (DAT_c0864118 != 0) {
    CloseHandle((HANDLE)DAT_c0864118);
  }
  DAT_c08640c4 = 0;
  DAT_c08640c0 = 0;
  DAT_c0864118 = 0;
  return;
}



/* c0862554 FUN_c0862554 */

void FUN_c0862554(void)

{
  return;
}



/* c086255c FUN_c086255c */

/* Boundary evidence: original MIPS .pdata c086255c..c08625c7. Semantic name remains unreviewed. */

undefined4 FUN_c086255c(void *param_1,int *param_2)

{
  void *pvVar1;
  int iVar2;
  
  FUN_c0861fd8();
  pvVar1 = DAT_c08640c4;
  memcpy(param_1,DAT_c08640c4,0x38);
  iVar2 = *(int *)((int)pvVar1 + 0x40);
  *param_2 = iVar2;
  if (iVar2 != 0) {
    *(undefined4 *)((int)pvVar1 + 0x40) = 0;
  }
  FUN_c0862024();
  return 1;
}



/* c08625c8 FUN_c08625c8 */

/* Boundary evidence: original MIPS .pdata c08625c8..c086260b. Semantic name remains unreviewed. */

undefined4 FUN_c08625c8(void)

{
  undefined4 uVar1;
  
  FUN_c0861fd8();
  uVar1 = *(undefined4 *)(DAT_c08640c4 + 0x38);
  FUN_c0862024();
  return uVar1;
}



/* c086260c FUN_c086260c */

/* Boundary evidence: original MIPS .pdata c086260c..c0862643. Semantic name remains unreviewed. */

undefined4 FUN_c086260c(void)

{
  undefined4 uVar1;
  
  FUN_c0861fd8();
  uVar1 = *(undefined4 *)(DAT_c08640c4 + 0x3c);
  FUN_c0862024();
  return uVar1;
}



/* c0862644 FUN_c0862644 */

/* Boundary evidence: original MIPS .pdata c0862644..c0862767. Semantic name remains unreviewed. */

void FUN_c0862644(int param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = DAT_c0864130;
  if (param_2 != 0) {
    DAT_c0864130 = DAT_c0864138;
    if (DAT_c0864124 != 0) {
      DVar2 = GetTickCount();
      DAT_c0864138 = DVar2 + (DAT_c0864130 - DAT_c0864120);
    }
    DAT_c0864130 = DAT_c0864138;
    if (DAT_c0864138 == 0) {
      DAT_c0864130 = iVar1;
    }
    DAT_c0864138 = 0;
  }
  if (param_1 == 0) {
    if (DAT_c0864124 != 0) {
      DVar2 = GetTickCount();
      DAT_c0864138 = DVar2 + (DAT_c0864138 - DAT_c0864120);
      DAT_c0864124 = 0;
    }
  }
  else if ((DAT_c0864124 == 0) || (param_2 != 0)) {
    DAT_c0864120 = GetTickCount();
    DAT_c0864124 = 1;
  }
  return;
}



/* c0862768 FUN_c0862768 */

/* Boundary evidence: original MIPS .pdata c0862768..c0862a9b. Semantic name remains unreviewed. */

size_t FUN_c0862768(void *param_1,uint param_2,int param_3)

{
  char *_Src;
  void *_Dst;
  int local_4c;
  void *local_48;
  char *local_44;
  _FILETIME local_40;
  _SYSTEMTIME _Stack_38;
  
  _Dst = DAT_c08641d8;
  _Src = DAT_c08641d4;
  if ((DAT_c08641d8 != (void *)0x0) && (DAT_c08641d4 != (char *)0x0)) {
    local_48 = DAT_c08641d8;
    local_44 = DAT_c08641d4;
    if (param_1 != (void *)0x0) {
      if (param_3 != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
        FUN_c086255c(_Src,&local_4c);
        if (*_Src == '\0') {
          if ((DAT_c0864134 != 0) && (DAT_c0864134 = 0, DAT_c0864124 == 0)) {
            DAT_c0864120 = GetTickCount();
            DAT_c0864124 = 1;
          }
        }
        else if (DAT_c0864134 == 0) {
          DAT_c0864134 = 1;
          FUN_c0862644(0,0);
        }
        if ((local_4c != 0) || ((DAT_c086412c == 0 && (DAT_c0864128 == 0)))) {
          GetLocalTime(&_Stack_38);
          SystemTimeToFileTime(&_Stack_38,&local_40);
          DAT_c0864128 = local_40.dwLowDateTime;
          DAT_c086412c = local_40.dwHighDateTime;
          FUN_c0862644((uint)(DAT_c0864134 == 0),1);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0864140);
        memcpy(_Dst,_Src,DAT_c08641dc);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0864140);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c08641c0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0864140);
      if (DAT_c08641dc < param_2) {
        param_2 = DAT_c08641dc;
      }
      memcpy(param_1,_Dst,param_2);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0864140);
      return param_2;
    }
  }
  return 0;
}



/* c0862a9c FUN_c0862a9c */

/* Boundary evidence: original MIPS .pdata c0862a9c..c0862aa7. Semantic name remains unreviewed. */

undefined4 FUN_c0862a9c(void)

{
  return 1;
}



/* c0862aa8 FUN_c0862aa8 */

/* Boundary evidence: original MIPS .pdata c0862aa8..c0862ab3. Semantic name remains unreviewed. */

undefined4 FUN_c0862aa8(void)

{
  return 1;
}



/* c0862ab4 FUN_c0862ab4 */

/* Boundary evidence: original MIPS .pdata c0862ab4..c0862afb. Semantic name remains unreviewed. */

undefined4 FUN_c0862ab4(void *param_1,int param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  
  if ((param_1 == (void *)0x0) || (sVar1 = FUN_c0862768(param_1,0x18,param_2), sVar1 != 0x18)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c0862afc FUN_c0862afc */

/* Boundary evidence: original MIPS .pdata c0862afc..c0862bd3. Semantic name remains unreviewed. */

void FUN_c0862afc(LPSYSTEMTIME param_1,int *param_2,undefined4 *param_3)

{
  DWORD DVar1;
  
  if (param_1 != (LPSYSTEMTIME)0x0) {
    FileTimeToSystemTime((FILETIME *)&DAT_c0864128,param_1);
  }
  if ((param_2 != (int *)0x0) && (*param_2 = DAT_c0864138, DAT_c0864124 != 0)) {
    DVar1 = GetTickCount();
    *param_2 = DVar1 + (*param_2 - DAT_c0864120);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = DAT_c0864130;
  }
  return;
}



/* c0862bd4 FUN_c0862bd4 */

/* Boundary evidence: original MIPS .pdata c0862bd4..c0862bdf. Semantic name remains unreviewed. */

undefined4 FUN_c0862bd4(void)

{
  return 1;
}



/* c0862be0 FUN_c0862be0 */

/* Boundary evidence: original MIPS .pdata c0862be0..c0862c8b. Semantic name remains unreviewed. */

void FUN_c0862be0(int param_1,uint *param_2)

{
  uint uVar1;
  
  if (param_2 != (uint *)0x0) {
    uVar1 = *param_2;
    if (param_1 == 0) {
      DAT_c086412c = (DAT_c086412c - param_2[1]) - (uint)(DAT_c0864128 < uVar1);
      DAT_c0864128 = DAT_c0864128 - uVar1;
    }
    else {
      DAT_c086412c = DAT_c086412c + param_2[1] + (uint)(DAT_c0864128 + uVar1 < DAT_c0864128);
      DAT_c0864128 = DAT_c0864128 + uVar1;
    }
  }
  return;
}



/* c0862c8c FUN_c0862c8c */

/* Boundary evidence: original MIPS .pdata c0862c8c..c0862c97. Semantic name remains unreviewed. */

undefined4 FUN_c0862c8c(void)

{
  return 1;
}



/* c0862d88 FUN_c0862d88 */

/* Boundary evidence: original MIPS .pdata c0862d88..c0862ec3. Semantic name remains unreviewed. */

int FUN_c0862d88(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c08641f4 != (code *)0x0) {
      iVar2 = (*DAT_c08641f4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0862e38;
    FUN_c08630e0();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0861fa4(param_1,param_2);
  }
LAB_c0862e38:
  if (((param_2 == 0) && (FUN_c0863068(), iVar1 != 0)) && (DAT_c08641f4 != (code *)0x0)) {
    iVar1 = (*DAT_c08641f4)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0862ec4 FUN_c0862ec4 */

/* Boundary evidence: original MIPS .pdata c0862ec4..c0862eef. Semantic name remains unreviewed. */

void FUN_c0862ec4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c0862ef0 entry */

/* Boundary evidence: original MIPS .pdata c0862ef0..c0862f47. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c086311c();
  }
  FUN_c0862d88(param_1,param_2,param_3);
  return;
}



/* c0862f48 FUN_c0862f48 */

/* Boundary evidence: original MIPS .pdata c0862f48..c0863067. Semantic name remains unreviewed. */

void FUN_c0862f48(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c086411c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c08641ec;
    if (DAT_c08641ec != (undefined4 *)0x0) {
      while (DAT_c08641e8 = DAT_c08641e8 + -1, _Memory <= DAT_c08641e8) {
        if ((code *)*DAT_c08641e8 != (code *)0x0) {
          (*(code *)*DAT_c08641e8)();
          _Memory = DAT_c08641ec;
        }
      }
      free(_Memory);
      DAT_c08641e8 = (undefined4 *)0x0;
      DAT_c08641ec = (undefined4 *)0x0;
    }
    FUN_c086308c((undefined4 *)&DAT_c0861010,(undefined4 *)&DAT_c0861014);
  }
  FUN_c086308c((undefined4 *)&DAT_c0861018,(undefined4 *)&DAT_c086101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c08641f0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0863068 FUN_c0863068 */

/* Boundary evidence: original MIPS .pdata c0863068..c086308b. Semantic name remains unreviewed. */

void FUN_c0863068(void)

{
  FUN_c0862f48(0,0,1);
  return;
}



/* c086308c FUN_c086308c */

/* Boundary evidence: original MIPS .pdata c086308c..c08630df. Semantic name remains unreviewed. */

void FUN_c086308c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c08630e0 FUN_c08630e0 */

/* Boundary evidence: original MIPS .pdata c08630e0..c086311b. Semantic name remains unreviewed. */

void FUN_c08630e0(void)

{
  FUN_c086308c((undefined4 *)&DAT_c0861008,(undefined4 *)&DAT_c086100c);
  FUN_c086308c((undefined4 *)&DAT_c0861000,(undefined4 *)&DAT_c0861004);
  return;
}



/* c086311c FUN_c086311c */

/* Boundary evidence: original MIPS .pdata c086311c..c086318f. Semantic name remains unreviewed. */

void FUN_c086311c(void)

{
  uint uVar1;
  
  if ((DAT_c08640a0 == 0) || (DAT_c08640a0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c08640a0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c08640a0 == 0) {
      DAT_c08640a0 = 0xb064;
    }
  }
  DAT_c08640a4 = ~DAT_c08640a0;
  return;
}


