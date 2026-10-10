/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c02c1df0 FUN_c02c1df0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c02c1df0..c02c1e57. Semantic name remains unreviewed. */

void FUN_c02c1df0(void)

{
  undefined4 local_10 [2];
  
  if (((_DAT_00005b68 & 0x20000000) != 0) && ((_DAT_00005b68 & 0x10000) != 0)) {
    local_10[0] = 0x15;
    CeLogData(1,0x67,local_10,4,0,0x10000,0,0);
  }
  return;
}



/* c02c1e58 FUN_c02c1e58 */

/* Boundary evidence: original MIPS .pdata c02c1e58..c02c1ecb. Semantic name remains unreviewed. */

void FUN_c02c1e58(void)

{
  uint uVar1;
  _SYSTEM_INFO _Stack_30;
  
  GetSystemInfo(&_Stack_30);
  uVar1 = 0x2000 / _Stack_30.dwPageSize;
  if (_Stack_30.dwPageSize == 0) {
    trap(0x1c00);
  }
  if (uVar1 < 3) {
    uVar1 = 2;
  }
  if (_Stack_30.dwPageSize == 0) {
    trap(0x1c00);
  }
  SetOOMEvent(0,0x1e,0xf,0x4000 / _Stack_30.dwPageSize,uVar1);
  return;
}



/* c02c1ecc FUN_c02c1ecc */

/* Boundary evidence: original MIPS .pdata c02c1ecc..c02c1f73. Semantic name remains unreviewed. */

void FUN_c02c1ecc(void)

{
  bool bVar1;
  int *piVar2;
  
  while( true ) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    bVar1 = false;
    piVar2 = DAT_c02d22d0;
    if ((int **)DAT_c02d22d0 == &DAT_c02d22d0) break;
    do {
      if ((*(ushort *)(piVar2 + 0x12) & 2) != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
        FUN_c02c2a24(piVar2);
        bVar1 = true;
        break;
      }
      piVar2 = (int *)*piVar2;
    } while ((int **)piVar2 != &DAT_c02d22d0);
    if ((int **)piVar2 == &DAT_c02d22d0) break;
    if (!bVar1) {
      return;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  return;
}



/* c02c1f74 FUN_c02c1f74 */

/* Boundary evidence: original MIPS .pdata c02c1f74..c02c213b. Semantic name remains unreviewed. */

void FUN_c02c1f74(void)

{
  HRESULT HVar1;
  int *piVar2;
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_c02d2224;
LAB_c02c1fd0:
  do {
    if ((int **)DAT_c02d22f0 == &DAT_c02d22f0) {
      FUN_c02d1074(local_28);
      return;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    for (piVar2 = DAT_c02d22f0; (int **)piVar2 != &DAT_c02d22f0; piVar2 = (int *)*piVar2) {
      if (piVar2[0x13] == 0) {
        *(int *)piVar2[1] = *piVar2;
        *(int *)(*piVar2 + 4) = piVar2[1];
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
        if (piVar2[4] != 0) {
          (*(code *)piVar2[5])(piVar2[0xf]);
        }
        if (piVar2[0x11] != -1) {
          HVar1 = StringCchPrintfW(awStack_228,0x100,L"%s\\%02u",L"Drivers\\Active",piVar2[0x11]);
          if (-1 < HVar1) {
            FUN_c02c80a0(awStack_228);
          }
        }
        FUN_c02c6e94(piVar2);
        goto LAB_c02c1fd0;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    Sleep(5000);
  } while( true );
}



/* c02c213c FUN_c02c213c */

/* Boundary evidence: original MIPS .pdata c02c213c..c02c2177. Semantic name remains unreviewed. */

undefined4 FUN_c02c213c(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x22c) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x22c),0);
  return 1;
}



/* c02c2178 FUN_c02c2178 */

/* Boundary evidence: original MIPS .pdata c02c2178..c02c22e7. Semantic name remains unreviewed. */

void FUN_c02c2178(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *hMem;
  int iVar3;
  undefined4 *puVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  puVar2 = DAT_c02d22e8;
  puVar1 = DAT_c02d22e8;
  puVar4 = DAT_c02d22e8;
  while (hMem = puVar1, hMem != (undefined4 *)0x0) {
    if (hMem[4] == 0) {
      iVar3 = hMem[2];
      if (((iVar3 != 0) && ((*(ushort *)(iVar3 + 0x48) & 0x8000) == 0)) &&
         (*(int *)(iVar3 + 0x1c) != 0)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
        (**(code **)(iVar3 + 0x20))(hMem[1]);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
        puVar2 = DAT_c02d22e8;
      }
      if (hMem == puVar2) {
        DAT_c02d22e8 = (undefined4 *)*hMem;
        LocalFree(hMem);
        puVar2 = DAT_c02d22e8;
        puVar1 = DAT_c02d22e8;
        puVar4 = DAT_c02d22e8;
      }
      else {
        *puVar4 = (undefined4 *)*hMem;
        LocalFree(hMem);
        puVar2 = DAT_c02d22e8;
        puVar1 = (undefined4 *)*puVar4;
      }
    }
    else {
      puVar1 = (undefined4 *)*hMem;
      puVar4 = hMem;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  return;
}



/* c02c22e8 FUN_c02c22e8 */

/* Boundary evidence: original MIPS .pdata c02c22e8..c02c2323. Semantic name remains unreviewed. */

undefined4 FUN_c02c22e8(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x28) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x28),0);
  return 1;
}



/* c02c2324 FUN_c02c2324 */

/* Boundary evidence: original MIPS .pdata c02c2324..c02c24eb. Semantic name remains unreviewed. */

void FUN_c02c2324(void)

{
  LSTATUS LVar1;
  int iVar2;
  long lVar3;
  wchar_t *_Str;
  DWORD dwIndex;
  DWORD local_240;
  DWORD local_23c;
  HKEY local_238;
  DWORD local_234;
  DWORD aDStack_230 [2];
  WCHAR aWStack_228 [6];
  wchar_t awStack_21c [122];
  wchar_t awStack_128 [128];
  uint local_28;
  
  local_28 = DAT_c02d2224;
  _Str = (wchar_t *)0x0;
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"init",0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_238,aDStack_230);
  if (LVar1 == 0) {
    local_240 = 0x80;
    local_23c = 0x100;
    dwIndex = 0;
    iVar2 = RegEnumValueW(local_238,0,aWStack_228,&local_240,(LPDWORD)0x0,&local_234,
                          (LPBYTE)awStack_128,&local_23c);
    while (iVar2 == 0) {
      if (((local_234 == 1) && (iVar2 = wcsncmp(aWStack_228,L"Launch",6), iVar2 == 0)) &&
         (iVar2 = wcscmp(awStack_128,L"device.dll"), iVar2 == 0)) {
        _Str = awStack_21c;
        break;
      }
      dwIndex = dwIndex + 1;
      local_240 = 0x80;
      local_23c = 0x100;
      iVar2 = RegEnumValueW(local_238,dwIndex,aWStack_228,&local_240,(LPDWORD)0x0,&local_234,
                            (LPBYTE)awStack_128,&local_23c);
    }
    RegCloseKey(local_238);
    if (_Str != (wchar_t *)0x0) {
      lVar3 = _wtol(_Str);
      SignalStarted(lVar3);
    }
  }
  FUN_c02d1074(local_28);
  return;
}



/* c02c24ec StartDeviceManager */

/* Boundary evidence: original MIPS .pdata c02c24ec..c02c287f. Semantic name remains unreviewed. */

undefined4 StartDeviceManager(undefined4 param_1,undefined4 param_2,wchar_t *param_3)

{
  int iVar1;
  HANDLE pvVar2;
  HMODULE hLibModule;
  code *pcVar3;
  long lVar4;
  
                    /* 0x24ec  1  StartDeviceManager */
  iVar1 = WaitForAPIReady(0x56,0);
  if (iVar1 != 0) {
    DAT_c02d2240 = 1;
    FUN_c02c1e58();
    DAT_c02d22d4 = &DAT_c02d22d0;
    DAT_c02d22d0 = &DAT_c02d22d0;
    DAT_c02d22c4 = &DAT_c02d22c0;
    DAT_c02d22f4 = &DAT_c02d22f0;
    DAT_c02d22c0 = &DAT_c02d22c0;
    DAT_c02d22f0 = &DAT_c02d22f0;
    DAT_c02d22e4 = &DAT_c02d22e0;
    DAT_c02d22e0 = &DAT_c02d22e0;
    DAT_c02d22c8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    DAT_c02d22f8 = CreateAPISet(&DAT_c02c14d4,0x26,&PTR_FUN_c02c1120,&DAT_c02c11b8);
    DAT_c02d22b8 = CreateAPISet(&DAT_c02c14cc,0xc,&PTR_FUN_c02c1318,&DAT_c02c1348);
    RegisterDirectMethods(DAT_c02d22b8,&PTR_FUN_c02c12e8);
    RegisterAPISet(DAT_c02d22b8,0x80000007);
    FUN_c02cafa0();
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    FUN_c02cfb18();
    FUN_c02cf890(L"Drivers\\Resources");
    SetPowerOffHandler(FUN_c02c3208);
    RegisterDirectMethods(DAT_c02d22f8,&PTR_FUN_c02c1088);
    RegisterAPISet(DAT_c02d22f8,0x56);
    FUN_c02c9c8c();
    pvVar2 = OpenEventW(0x1f0003,0,L"SYSTEM/DevMgrApiSetReady");
    if (pvVar2 != (HANDLE)0x0) {
      EventModify(pvVar2,3);
      CloseHandle(pvVar2);
    }
    hLibModule = LoadLibraryW(L"ceddk.dll");
    if (hLibModule != (HMODULE)0x0) {
      pcVar3 = (code *)GetProcAddressW(hLibModule,L"CalibrateStallCounter");
      if (pcVar3 == (code *)0x0) {
        FreeLibrary(hLibModule);
      }
      else {
        (*pcVar3)();
      }
    }
    FUN_c02cfb50();
    FUN_c02d0070((STRSAFE_LPCWSTR)0x0,0x10000,0x1000);
    FUN_c02c642c();
    pvVar2 = OpenEventW(0x1f0003,0,L"SYSTEM/BootPhase1");
    if (pvVar2 == (HANDLE)0x0) {
      DAT_c02d2240 = 2;
      FUN_c02c92a8();
      if (param_3 == (wchar_t *)0x0) {
        lVar4 = 0x14;
      }
      else {
        lVar4 = _wtol(param_3);
      }
      SignalStarted(lVar4);
    }
    else {
      FUN_c02c92a8();
      EventModify(pvVar2,3);
      CloseHandle(pvVar2);
      pvVar2 = OpenEventW(0x1f0003,0,L"SYSTEM/BootPhase2");
      if (pvVar2 != (HANDLE)0x0) {
        WaitForSingleObject(pvVar2,0xffffffff);
        CloseHandle(pvVar2);
      }
      DAT_c02d2240 = 2;
      FUN_c02d0070((STRSAFE_LPCWSTR)0x0,0x10000,0x1000);
      FUN_c02c9094((wchar_t *)0x0);
      FUN_c02c2324();
    }
    DAT_c02d2240 = 3;
    FUN_c02c1df0();
    do {
      WaitForSingleObject(DAT_c02d22c8,0xffffffff);
      FUN_c02c1ecc();
      FUN_c02c1f74();
      FUN_c02c2178();
    } while( true );
  }
  return 0;
}



/* c02c2880 FUN_c02c2880 */

/* Boundary evidence: original MIPS .pdata c02c2880..c02c28df. Semantic name remains unreviewed. */

undefined4 FUN_c02c2880(HMODULE param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_2 == 1) {
    iVar1 = WaitForAPIReady(0x56,0);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      DisableThreadLibraryCalls(param_1);
    }
  }
  return uVar2;
}



/* c02c28e0 FUN_c02c28e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c02c28e0..c02c29c3. Semantic name remains unreviewed. */

void FUN_c02c28e0(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  size_t local_228 [2];
  undefined4 local_220;
  wchar_t awStack_21c [260];
  uint local_14;
  
  local_14 = DAT_c02d2224;
  if (((_DAT_00005b68 & 0x20000000) != 0) && ((_DAT_00005b68 & 0x10000) != 0)) {
    local_228[0] = 0;
    local_220 = 0x14;
    if ((param_1 != (STRSAFE_PCNZWCH)0x0) &&
       (HVar1 = StringCchLengthW(param_1,0x104,local_228), -1 < HVar1)) {
      StringCchCopyNW(awStack_21c,0x104,param_1,local_228[0]);
      local_228[0] = local_228[0] + 1;
    }
    CeLogData(1,0x67,&local_220,(local_228[0] + 2) * 2 & 0xffff,0,0x10000,0,0);
  }
  FUN_c02d1074(local_14);
  return;
}



/* c02c29c4 FUN_c02c29c4 */

/* Boundary evidence: original MIPS .pdata c02c29c4..c02c29eb. Semantic name remains unreviewed. */

undefined4 FUN_c02c29c4(void)

{
  SetLastError(0x424);
  return 0;
}



/* c02c29ec DmAdvertiseInterface */

/* Boundary evidence: original MIPS .pdata c02c29ec..c02c2a07. Semantic name remains unreviewed. */

void DmAdvertiseInterface(int param_1,undefined4 *param_2,wchar_t *param_3,int param_4)

{
                    /* 0x29ec  2  DmAdvertiseInterface */
  FUN_c02ca738(param_1,param_2,param_3,param_4);
  return;
}



/* c02c2a08 FUN_c02c2a08 */

/* Boundary evidence: original MIPS .pdata c02c2a08..c02c2a23. Semantic name remains unreviewed. */

void FUN_c02c2a08(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,LPCWSTR param_4)

{
  FUN_c02c7c94(param_1,param_2,param_3,param_4);
  return;
}



/* c02c2a24 FUN_c02c2a24 */

/* Boundary evidence: original MIPS .pdata c02c2a24..c02c2a3f. Semantic name remains unreviewed. */

void FUN_c02c2a24(int *param_1)

{
  FUN_c02c9318(param_1);
  return;
}



/* c02c2a40 FUN_c02c2a40 */

/* Boundary evidence: original MIPS .pdata c02c2a40..c02c2a9f. Semantic name remains unreviewed. */

void FUN_c02c2a40(STRSAFE_PCNZWCH param_1,int param_2,int param_3,undefined4 param_4)

{
  FUN_c02c28e0(param_1);
  FUN_c02c89a8(param_1,param_2,param_3,param_4);
  return;
}



/* c02c2aa0 FUN_c02c2aa0 */

/* Boundary evidence: original MIPS .pdata c02c2aa0..c02c2d37. Semantic name remains unreviewed. */

int FUN_c02c2aa0(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  size_t sVar2;
  STRSAFE_LPWSTR pszDest;
  int iVar3;
  uint cbDest;
  void *local_38;
  wchar_t *local_34;
  undefined4 local_30;
  int *local_2c;
  
  iVar3 = 0;
  if ((((param_3 != 0) && (param_2 != (int *)0x0)) && (*param_2 != 0)) &&
     ((param_2[1] != 0 && (param_1 != (int *)0x0)))) {
    iVar3 = 1;
    local_30 = 1;
    while (((param_3 != 0 && (param_2 != (int *)0x0)) && (iVar3 != 0))) {
      local_34 = (wchar_t *)0x0;
      local_38 = (void *)0x0;
      local_2c = param_2;
      iVar1 = CeOpenCallerBuffer(&local_34,*param_2,0,5,0);
      if (iVar1 < 0) {
        local_34 = (wchar_t *)0x0;
      }
      iVar1 = CeOpenCallerBuffer(&local_38,param_2[1],param_2[2],4,0);
      if (iVar1 < 0) {
        local_38 = (void *)0x0;
      }
      if ((local_34 == (wchar_t *)0x0) || (local_38 == (void *)0x0)) {
        iVar3 = 0;
        local_30 = 0;
      }
      else {
        sVar2 = wcslen(local_34);
        cbDest = sVar2 * 2 + 5 & 0xfffffffc;
        iVar1 = param_2[2];
        pszDest = malloc(iVar1 + cbDest);
        *param_1 = (int)pszDest;
        if ((pszDest == (STRSAFE_LPWSTR)0x0) || (iVar1 + cbDest < cbDest)) {
          iVar3 = 0;
          local_30 = 0;
        }
        else {
          StringCbCopyW(pszDest,cbDest,local_34);
          param_1[1] = (int)(*param_1 + cbDest);
          memcpy((void *)(*param_1 + cbDest),local_38,param_2[2]);
          param_1[3] = param_2[3];
          param_1[2] = param_2[2];
        }
      }
      if (local_34 != (wchar_t *)0x0) {
        CeCloseCallerBuffer(local_34,*param_2,0,5);
      }
      if (local_38 != (void *)0x0) {
        CeCloseCallerBuffer(local_38,param_2[1],param_2[2],4);
      }
      param_2 = param_2 + 4;
      param_1 = param_1 + 4;
      param_3 = param_3 + -1;
    }
  }
  return iVar3;
}



/* c02c2d38 FUN_c02c2d38 */

/* Boundary evidence: original MIPS .pdata c02c2d38..c02c2d43. Semantic name remains unreviewed. */

undefined4 FUN_c02c2d38(void)

{
  return 1;
}



/* c02c2d44 FUN_c02c2d44 */

/* Boundary evidence: original MIPS .pdata c02c2d44..c02c2d4f. Semantic name remains unreviewed. */

undefined4 FUN_c02c2d44(void)

{
  return 1;
}



/* c02c2d50 FUN_c02c2d50 */

/* Boundary evidence: original MIPS .pdata c02c2d50..c02c2db3. Semantic name remains unreviewed. */

undefined4 FUN_c02c2d50(undefined4 *param_1,int param_2)

{
  for (; (param_1 != (undefined4 *)0x0 && (param_2 != 0)); param_2 = param_2 + -1) {
    if ((void *)*param_1 != (void *)0x0) {
      free((void *)*param_1);
      *param_1 = 0;
      param_1[1] = 0;
    }
    param_1 = param_1 + 4;
  }
  return 1;
}



/* c02c2db4 FUN_c02c2db4 */

/* Boundary evidence: original MIPS .pdata c02c2db4..c02c309b. Semantic name remains unreviewed. */

int * FUN_c02c2db4(STRSAFE_PCNZWCH param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int *_Dst;
  int iVar2;
  DWORD dwErrCode;
  int *piVar3;
  size_t _Size;
  int *local_250;
  HKEY local_24c;
  undefined4 local_248 [2];
  uint local_240;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c02d2224;
  local_250 = (int *)0x0;
  piVar3 = (int *)0x0;
  FUN_c02c28e0(param_1);
  if (param_1 == (STRSAFE_PCNZWCH)0x0) {
    dwErrCode = 0x64a;
  }
  else {
    StringCchCopyW(awStack_230,0x104,param_1);
    iVar1 = CeGetCallerTrust();
    if (iVar1 == 2) {
LAB_c02c2f08:
      if (((param_3 == 0) || (param_2 == 0)) || (0xffffffe < param_3)) {
        piVar3 = FUN_c02c89a8(awStack_230,0,0,param_4);
      }
      else {
        _Size = param_3 << 4;
        iVar1 = CeOpenCallerBuffer(&local_250,param_2,_Size,4,1);
        _Dst = malloc(_Size);
        if (((iVar1 < 0) || (local_250 == (int *)0x0)) || (_Dst == (int *)0x0)) {
          SetLastError(0x57);
        }
        else {
          memset(_Dst,0,_Size);
          iVar2 = FUN_c02c2aa0(_Dst,local_250,param_3);
          if (iVar2 == 0) {
            SetLastError(0x57);
          }
          else {
            piVar3 = FUN_c02c89a8(awStack_230,(int)_Dst,param_3,param_4);
          }
          FUN_c02c2d50(_Dst,param_3);
        }
        if (_Dst != (int *)0x0) {
          free(_Dst);
        }
        if ((-1 < iVar1) && (local_250 != (int *)0x0)) {
          CeCloseCallerBuffer(local_250,param_2,_Size,4);
        }
      }
      FUN_c02d1074(local_28);
      return piVar3;
    }
    if ((param_2 == 0) || (param_3 == 0)) {
      dwErrCode = RegOpenKeyExW((HKEY)0x80000002,awStack_230,0,0,&local_24c);
      if (dwErrCode == 0) {
        dwErrCode = 5;
        memset(local_248,0,0x14);
        local_248[0] = 0x14;
        iVar1 = CeFsIoControlW(0,0x9008c,&local_24c,4,local_248,0x14,0,0);
        if ((iVar1 != 0) && ((local_240 & 1) != 0)) {
          dwErrCode = 0;
        }
        RegCloseKey(local_24c);
        if (dwErrCode == 0) goto LAB_c02c2f08;
      }
    }
    else {
      dwErrCode = 5;
    }
  }
  SetLastError(dwErrCode);
  FUN_c02d1074(local_28);
  return (int *)0x0;
}



/* c02c309c FUN_c02c309c */

/* Boundary evidence: original MIPS .pdata c02c309c..c02c30b7. Semantic name remains unreviewed. */

void FUN_c02c309c(int *param_1)

{
  FUN_c02c9674(param_1);
  return;
}



/* c02c30b8 FUN_c02c30b8 */

/* Boundary evidence: original MIPS .pdata c02c30b8..c02c30ff. Semantic name remains unreviewed. */

undefined4 FUN_c02c30b8(undefined4 *param_1,uint *param_2)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  
  dwErrCode = 0x57;
  if ((param_2 == (uint *)0x0) || (dwErrCode = FUN_c02c8df8(param_1,param_2), dwErrCode != 0)) {
    SetLastError(dwErrCode);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c02c3100 FUN_c02c3100 */

/* Boundary evidence: original MIPS .pdata c02c3100..c02c31fb. Semantic name remains unreviewed. */

bool FUN_c02c3100(undefined4 *param_1,uint *param_2)

{
  DWORD dwErrCode;
  uint local_648 [396];
  uint local_18;
  
  local_18 = DAT_c02d2224;
  dwErrCode = 0x57;
  if ((param_2 != (uint *)0x0) && (0x62f < *param_2)) {
    local_648[0] = 0x630;
    dwErrCode = FUN_c02c8df8(param_1,local_648);
    if (dwErrCode == 0) {
      memcpy(param_2,local_648,0x630);
    }
  }
  if (dwErrCode == 0) {
    FUN_c02d1074(local_18);
  }
  else {
    SetLastError(dwErrCode);
    FUN_c02d1074(local_18);
  }
  return dwErrCode == 0;
}



/* c02c31fc FUN_c02c31fc */

/* Boundary evidence: original MIPS .pdata c02c31fc..c02c3207. Semantic name remains unreviewed. */

undefined4 FUN_c02c31fc(void)

{
  return 1;
}



/* c02c3208 FUN_c02c3208 */

/* Boundary evidence: original MIPS .pdata c02c3208..c02c3313. Semantic name remains unreviewed. */

void FUN_c02c3208(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_c02d22d4;
  if (param_1 == 0) {
    PmPowerHandler(0);
    for (puVar1 = DAT_c02d22d0; (undefined4 **)puVar1 != &DAT_c02d22d0;
        puVar1 = (undefined4 *)*puVar1) {
      if ((code *)puVar1[0xd] != (code *)0x0) {
        (*(code *)puVar1[0xd])(puVar1[0xf]);
      }
    }
  }
  else {
    for (; (undefined4 **)puVar1 != &DAT_c02d22d0; puVar1 = (undefined4 *)puVar1[1]) {
      if ((code *)puVar1[0xe] != (code *)0x0) {
        (*(code *)puVar1[0xe])(puVar1[0xf]);
      }
    }
    PmPowerHandler(param_1);
  }
  return;
}



/* c02c3314 FUN_c02c3314 */

/* Boundary evidence: original MIPS .pdata c02c3314..c02c331f. Semantic name remains unreviewed. */

undefined4 FUN_c02c3314(void)

{
  return 1;
}



/* c02c3320 FUN_c02c3320 */

/* Boundary evidence: original MIPS .pdata c02c3320..c02c332b. Semantic name remains unreviewed. */

undefined4 FUN_c02c3320(void)

{
  return 1;
}



/* c02c332c FUN_c02c332c */

/* Boundary evidence: original MIPS .pdata c02c332c..c02c349f. Semantic name remains unreviewed. */

undefined4 FUN_c02c332c(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 == (undefined4 *)0x0) {
    SetLastError(0x57);
    uVar2 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    for (puVar1 = DAT_c02d22d0; (undefined4 **)puVar1 != &DAT_c02d22d0;
        puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[0x16] != 0) {
        if (param_1 == 0) {
          if ((undefined4 **)puVar1 != &DAT_c02d22d0) {
            *param_2 = 0x80;
            param_2[1] = 0;
            param_2[2] = 0;
            param_2[3] = 0;
            param_2[4] = 0;
            param_2[5] = 0;
            param_2[6] = 0;
            param_2[7] = 0;
            param_2[8] = 0;
            param_2[9] = 0xffffffff;
            wcsncpy((wchar_t *)(param_2 + 10),(wchar_t *)puVar1[0x16],0x104);
            uVar2 = 1;
          }
          break;
        }
        param_1 = param_1 + -1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  }
  return uVar2;
}



/* c02c34a0 FUN_c02c34a0 */

/* Boundary evidence: original MIPS .pdata c02c34a0..c02c34ab. Semantic name remains unreviewed. */

undefined4 FUN_c02c34a0(void)

{
  return 1;
}



/* c02c34ac FUN_c02c34ac */

/* Boundary evidence: original MIPS .pdata c02c34ac..c02c3693. Semantic name remains unreviewed. */

undefined4
FUN_c02c34ac(undefined4 *param_1,int param_2,undefined4 *param_3,wchar_t *param_4,uint *param_5)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  int *piVar4;
  DWORD dwErrCode;
  uint uVar5;
  wchar_t *_Str;
  
  if ((param_3 == (undefined4 *)0x0) || ((param_4 != (wchar_t *)0x0 && (param_5 == (uint *)0x0)))) {
    dwErrCode = 0x57;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    iVar1 = FUN_c02c6c48(param_1);
    if (iVar1 == 0) {
      dwErrCode = 6;
    }
    else {
      piVar4 = (int *)param_1[0x15];
      for (; (piVar4 != (int *)0x0 && (param_2 != 0)); param_2 = param_2 + -1) {
        piVar4 = (int *)*piVar4;
      }
      if ((param_2 == 0) && (piVar4 != (int *)0x0)) {
        dwErrCode = 0;
        *param_3 = piVar4[1];
        param_3[1] = piVar4[2];
        param_3[2] = piVar4[3];
        param_3[3] = piVar4[4];
        if (param_5 != (uint *)0x0) {
          _Str = (wchar_t *)piVar4[5];
          sVar2 = wcslen(_Str);
          uVar5 = (sVar2 + 1) * 2;
          if (*param_5 < uVar5) {
            dwErrCode = 0x7a;
          }
          else if (param_4 != (wchar_t *)0x0) {
            wcscpy(param_4,_Str);
          }
          *param_5 = uVar5;
        }
      }
      else {
        dwErrCode = 0x103;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  }
  if ((dwErrCode == 0) || (SetLastError(dwErrCode), dwErrCode == 0)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* c02c3694 FUN_c02c3694 */

/* Boundary evidence: original MIPS .pdata c02c3694..c02c369f. Semantic name remains unreviewed. */

undefined4 FUN_c02c3694(void)

{
  return 1;
}



/* c02c36a0 FUN_c02c36a0 */

/* Boundary evidence: original MIPS .pdata c02c36a0..c02c3877. Semantic name remains unreviewed. */

undefined4
FUN_c02c36a0(undefined4 *param_1,int param_2,undefined4 *param_3,void *param_4,uint *param_5)

{
  uint uVar1;
  wchar_t *_Src;
  undefined4 uVar2;
  uint local_50;
  wchar_t *local_4c;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  
  local_30 = DAT_c02d2224;
  _Src = (wchar_t *)0x0;
  local_4c = (wchar_t *)0x0;
  local_50 = 0;
  uVar2 = 0;
  if ((param_3 != (undefined4 *)0x0) && ((param_4 == (void *)0x0 || (param_5 != (uint *)0x0)))) {
    local_40 = *param_3;
    local_3c = param_3[1];
    local_38 = param_3[2];
    local_34 = param_3[3];
    if ((param_4 != (void *)0x0) && (local_50 = *param_5 & 0xfffffffe, local_50 != 0)) {
      local_4c = malloc(local_50);
    }
    _Src = local_4c;
    uVar2 = FUN_c02c34ac(param_1,param_2,&local_40,local_4c,&local_50);
    uVar1 = local_50;
    *param_3 = local_40;
    param_3[1] = local_3c;
    param_3[2] = local_38;
    param_3[3] = local_34;
    local_48 = uVar2;
    if (((local_50 != 0) && (_Src != (wchar_t *)0x0)) && (param_4 != (void *)0x0)) {
      memcpy(param_4,_Src,local_50);
      *param_5 = uVar1;
    }
  }
  if (_Src != (wchar_t *)0x0) {
    free(_Src);
  }
  FUN_c02d1074(local_30);
  return uVar2;
}



/* c02c3878 FUN_c02c3878 */

/* Boundary evidence: original MIPS .pdata c02c3878..c02c3883. Semantic name remains unreviewed. */

undefined4 FUN_c02c3878(void)

{
  return 1;
}



/* c02c3884 FUN_c02c3884 */

/* Boundary evidence: original MIPS .pdata c02c3884..c02c3a0f. Semantic name remains unreviewed. */

void FUN_c02c3884(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_88;
  undefined4 local_84;
  int local_80;
  undefined4 local_7c;
  int local_78 [20];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  uVar4 = 0;
  piVar1 = DAT_c02d22b4;
  if (DAT_c02d22b4 != (int *)0x0) {
    do {
      if (piVar1[6] == param_2) {
        uVar4 = uVar4 + 1;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if (0x13 < uVar4) {
      piVar1 = LocalAlloc(0,uVar4 << 2);
      if (piVar1 != (int *)0x0) goto LAB_c02c3924;
      uVar4 = 0x14;
    }
  }
  piVar1 = local_78;
LAB_c02c3924:
  iVar5 = 0;
  piVar3 = piVar1;
  piVar2 = DAT_c02d22b4;
  while ((piVar2 != (int *)0x0 && (iVar5 < (int)uVar4))) {
    if (piVar2[6] == param_2) {
      *piVar3 = (int)piVar2;
      iVar5 = iVar5 + 1;
      piVar3 = piVar3 + 1;
      FUN_c02c3bf0((int)piVar2);
    }
    piVar2 = (int *)*piVar2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  local_88 = 0x10;
  piVar3 = piVar1;
  local_84 = param_1;
  local_80 = param_2;
  local_7c = param_3;
  if (0 < (int)uVar4) {
    do {
      FUN_c02c4b84(*piVar3,0x10303ff,&local_88,0x10,0,0,0);
      FUN_c02c3c20(*piVar3);
      uVar4 = uVar4 - 1;
      piVar3 = piVar3 + 1;
    } while (uVar4 != 0);
  }
  if (piVar1 != local_78) {
    LocalFree(piVar1);
  }
  return;
}



/* c02c3a10 FUN_c02c3a10 */

/* Boundary evidence: original MIPS .pdata c02c3a10..c02c3adf. Semantic name remains unreviewed. */

void FUN_c02c3a10(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 == 4) {
    iVar1 = CeGetCallerTrust();
    if ((iVar1 != 2) && (iVar1 = GetCallerProcess(), param_2 != iVar1)) {
      return;
    }
    FUN_c02c3884(4,param_2,param_3);
  }
  else if (param_1 == 5) {
    iVar1 = CeGetCallerTrust();
    if (iVar1 != 2) {
      return;
    }
    FUN_c02c92f8();
  }
  else if (param_1 == 6) {
    CompactAllHeaps();
    return;
  }
  FUN_c02cfc50();
  return;
}



/* c02c3ae0 FUN_c02c3ae0 */

/* Boundary evidence: original MIPS .pdata c02c3ae0..c02c3bef. Semantic name remains unreviewed. */

BOOL FUN_c02c3ae0(undefined4 *param_1)

{
  int iVar1;
  DWORD DVar2;
  BOOL BVar3;
  uint local_850 [396];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c02d2224;
  memset(local_850,0,0x630);
  local_850[0] = 0x630;
  iVar1 = FUN_c02c8df8(param_1,local_850);
  if ((((iVar1 == 0) && (param_1[0x16] != 0)) &&
      (DVar2 = GetFileAttributesW(L"\\StoreMgr"), DVar2 != 0xffffffff)) &&
     (DVar2 = GetFileAttributesW(L"\\StoreMgr"), (DVar2 & 0x100) != 0)) {
    StringCchCopyW(awStack_220,0x104,L"\\StoreMgr\\");
    StringCchCatW(awStack_220,0x104,(STRSAFE_LPCWSTR)param_1[0x16]);
    BVar3 = MoveFileW(awStack_220,awStack_220);
    FUN_c02d1074(local_18);
  }
  else {
    FUN_c02d1074(local_18);
    BVar3 = 0;
  }
  return BVar3;
}



/* c02c3bf0 FUN_c02c3bf0 */

/* Boundary evidence: original MIPS .pdata c02c3bf0..c02c3c1f. Semantic name remains unreviewed. */

void FUN_c02c3bf0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  InterlockedIncrement(*(LONG **)(param_1 + 0xc));
  return;
}



/* c02c3c20 FUN_c02c3c20 */

/* Boundary evidence: original MIPS .pdata c02c3c20..c02c3c4f. Semantic name remains unreviewed. */

void FUN_c02c3c20(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 0x10));
  InterlockedDecrement(*(LONG **)(param_1 + 0xc));
  return;
}



/* c02c3c50 FUN_c02c3c50 */

/* Boundary evidence: original MIPS .pdata c02c3c50..c02c3db7. Semantic name remains unreviewed. */

undefined4 FUN_c02c3c50(HMODULE param_1)

{
  DWORD DVar1;
  LSTATUS LVar2;
  WCHAR *pWVar3;
  uint uVar4;
  LPCWSTR lpSubKey;
  undefined4 uVar5;
  HKEY local_238;
  HKEY local_234;
  DWORD local_230;
  undefined4 local_22c;
  DWORD local_228 [2];
  WCHAR local_220 [259];
  undefined2 local_1a;
  uint local_18;
  
  local_18 = DAT_c02d2224;
  uVar5 = 0;
  DVar1 = GetModuleFileNameW(param_1,local_220,0x104);
  if (DVar1 != 0) {
    lpSubKey = local_220;
    local_1a = 0;
    uVar4 = 0;
    pWVar3 = local_220;
    do {
      if (*pWVar3 == L'\0') break;
      if (*pWVar3 == L'\\') {
        lpSubKey = pWVar3 + 1;
      }
      uVar4 = uVar4 + 1;
      pWVar3 = pWVar3 + 1;
    } while (uVar4 < 0x104);
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\OldAccessException",0,0,&local_234);
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExW(local_234,lpSubKey,0,0,&local_238);
      if (LVar2 == 0) {
        local_230 = 4;
        LVar2 = RegQueryValueExW(local_238,L"ExceptionFlags",(LPDWORD)0x0,local_228,
                                 (LPBYTE)&local_22c,&local_230);
        if ((LVar2 == 0) && (local_228[0] == 4)) {
          uVar5 = local_22c;
        }
        RegCloseKey(local_238);
      }
      RegCloseKey(local_234);
    }
  }
  FUN_c02d1074(local_18);
  return uVar5;
}



/* c02c3db8 FUN_c02c3db8 */

/* Boundary evidence: original MIPS .pdata c02c3db8..c02c4153. Semantic name remains unreviewed. */

int FUN_c02c3db8(wchar_t *param_1,int param_2,uint param_3,undefined4 param_4,HMODULE param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  int iVar3;
  undefined4 *local_3c;
  
  iVar3 = -1;
  dwErrCode = 0x37;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  puVar1 = FUN_c02c6ccc(param_1,param_2);
  if (puVar1 == (undefined4 *)0x0) {
LAB_c02c40a0:
    if (dwErrCode == 0) {
      InterlockedDecrement(local_3c + 4);
      InterlockedDecrement((LONG *)local_3c[3]);
      goto LAB_c02c40d8;
    }
  }
  else {
    if (param_2 == 2) {
      if ((*(ushort *)(puVar1 + 0x12) & 0x10) == 0) goto LAB_c02c40a0;
      param_3 = param_3 | 0x100;
    }
    if (puVar1 == (undefined4 *)0x0) goto LAB_c02c40a0;
    local_3c = LocalAlloc(0x40,0x24);
    if (local_3c != (undefined4 *)0x0) {
      local_3c[2] = puVar1;
      local_3c[3] = puVar1 + 0x13;
      InterlockedIncrement(local_3c + 4);
      InterlockedIncrement((LONG *)local_3c[3]);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      SetLastError(0);
      uVar2 = (*(code *)puVar1[6])(puVar1[0xf],param_3,param_4);
      local_3c[1] = uVar2;
      local_3c[7] = param_3;
      uVar2 = FUN_c02c3c50(param_5);
      local_3c[8] = uVar2;
      if ((local_3c[1] == 0) && (dwErrCode = GetLastError(), dwErrCode == 0)) {
        dwErrCode = 0x6e;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      if (local_3c[1] != 0) {
        local_3c[6] = param_5;
        iVar3 = CreateAPIHandle(DAT_c02d22b8,local_3c);
        if (iVar3 != 0) {
          dwErrCode = 0;
          local_3c[5] = iVar3;
          *local_3c = DAT_c02d22b4;
          DAT_c02d22b4 = local_3c;
          goto LAB_c02c40a0;
        }
        if ((code *)puVar1[7] != (code *)0x0) {
          (*(code *)puVar1[7])(local_3c[1]);
        }
        if ((code *)puVar1[8] != (code *)0x0) {
          (*(code *)puVar1[8])(local_3c[1]);
        }
        dwErrCode = 0xe;
      }
      iVar3 = -1;
      InterlockedDecrement(local_3c + 4);
      InterlockedDecrement((LONG *)local_3c[3]);
      LocalFree(local_3c);
      goto LAB_c02c40a0;
    }
    dwErrCode = 0xe;
  }
  SetLastError(dwErrCode);
LAB_c02c40d8:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  return iVar3;
}



/* c02c4154 FUN_c02c4154 */

/* Boundary evidence: original MIPS .pdata c02c4154..c02c418f. Semantic name remains unreviewed. */

undefined4 FUN_c02c4154(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x40) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x40),0);
  return 1;
}



/* c02c4190 FUN_c02c4190 */

/* Boundary evidence: original MIPS .pdata c02c4190..c02c41cb. Semantic name remains unreviewed. */

undefined4 FUN_c02c4190(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x40) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x40),0);
  return 1;
}



/* c02c41cc FUN_c02c41cc */

/* Boundary evidence: original MIPS .pdata c02c41cc..c02c4207. Semantic name remains unreviewed. */

undefined4 FUN_c02c41cc(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x40) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x40),0);
  return 1;
}



/* c02c4208 FUN_c02c4208 */

/* Boundary evidence: original MIPS .pdata c02c4208..c02c43ef. Semantic name remains unreviewed. */

bool FUN_c02c4208(int *param_1)

{
  int *piVar1;
  int *piVar2;
  DWORD dwErrCode;
  int iVar3;
  
  dwErrCode = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (DAT_c02d22b4 == param_1) {
    DAT_c02d22b4 = (int *)*param_1;
  }
  else {
    piVar2 = DAT_c02d22b4;
    if (DAT_c02d22b4 != (int *)0x0) {
      do {
        piVar1 = (int *)*piVar2;
        if (piVar1 == param_1) break;
        piVar2 = piVar1;
      } while (piVar1 != (int *)0x0);
      if (piVar2 != (int *)0x0) {
        *piVar2 = *param_1;
        goto LAB_c02c42ac;
      }
    }
    dwErrCode = 6;
  }
LAB_c02c42ac:
  if (((dwErrCode == 0) && (iVar3 = param_1[2], iVar3 != 0)) &&
     ((*(ushort *)(iVar3 + 0x48) & 0x8000) == 0)) {
    InterlockedIncrement(param_1 + 4);
    InterlockedIncrement((LONG *)param_1[3]);
    if (*(int *)(iVar3 + 0x1c) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      (**(code **)(iVar3 + 0x20))(param_1[1]);
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      (**(code **)(iVar3 + 0x1c))(param_1[1]);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    InterlockedDecrement(param_1 + 4);
    InterlockedDecrement((LONG *)param_1[3]);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c02c43f0 FUN_c02c43f0 */

/* Boundary evidence: original MIPS .pdata c02c43f0..c02c442b. Semantic name remains unreviewed. */

undefined4 FUN_c02c43f0(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x20) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x20),0);
  return 1;
}



/* c02c442c FUN_c02c442c */

/* Boundary evidence: original MIPS .pdata c02c442c..c02c4467. Semantic name remains unreviewed. */

undefined4 FUN_c02c442c(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x20) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x20),0);
  return 1;
}



/* c02c4468 FUN_c02c4468 */

/* Boundary evidence: original MIPS .pdata c02c4468..c02c457f. Semantic name remains unreviewed. */

undefined4 FUN_c02c4468(HLOCAL param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  iVar1 = *(int *)((int)param_1 + 8);
  if (((iVar1 != 0) && ((*(ushort *)(iVar1 + 0x48) & 0x8000) == 0)) && (*(int *)(iVar1 + 0x1c) != 0)
     ) {
    InterlockedIncrement((LONG *)((int)param_1 + 0x10));
    InterlockedIncrement(*(LONG **)((int)param_1 + 0xc));
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    (**(code **)(iVar1 + 0x20))(*(undefined4 *)((int)param_1 + 4));
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    InterlockedDecrement((LONG *)((int)param_1 + 0x10));
    InterlockedDecrement(*(LONG **)((int)param_1 + 0xc));
  }
  LocalFree(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  return 1;
}



/* c02c4580 FUN_c02c4580 */

/* Boundary evidence: original MIPS .pdata c02c4580..c02c45bb. Semantic name remains unreviewed. */

undefined4 FUN_c02c4580(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x20) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x20),0);
  return 1;
}



/* c02c45bc FUN_c02c45bc */

/* Boundary evidence: original MIPS .pdata c02c45bc..c02c47a3. Semantic name remains unreviewed. */

undefined4 FUN_c02c45bc(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (*(int *)(param_1 + 8) == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    SetLastError(0x649);
    return 0;
  }
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  InterlockedIncrement(*(LONG **)(param_1 + 0xc));
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) &&
     ((*(uint *)(param_1 + 0x20) & 0x80000000) == 0)) {
    dwErrCode = 0xc;
  }
  else {
    if ((*(ushort *)(*(int *)(param_1 + 8) + 0x48) & 0x8000) == 0) {
      iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x24))
                        (*(undefined4 *)(param_1 + 4),param_2,param_3);
      *param_4 = iVar1;
      if (iVar1 == -1) {
        uVar2 = 0;
        *param_4 = 0;
      }
      else {
        uVar2 = 1;
      }
      goto LAB_c02c4728;
    }
    *param_4 = -1;
    dwErrCode = 0x651;
  }
  SetLastError(dwErrCode);
LAB_c02c4728:
  InterlockedDecrement((LONG *)(param_1 + 0x10));
  InterlockedDecrement(*(LONG **)(param_1 + 0xc));
  return uVar2;
}



/* c02c47a4 FUN_c02c47a4 */

/* Boundary evidence: original MIPS .pdata c02c47a4..c02c47df. Semantic name remains unreviewed. */

undefined4 FUN_c02c47a4(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x2c) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x2c),0);
  return 1;
}



/* c02c47e0 FUN_c02c47e0 */

/* Boundary evidence: original MIPS .pdata c02c47e0..c02c49c7. Semantic name remains unreviewed. */

undefined4 FUN_c02c47e0(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (*(int *)(param_1 + 8) == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    SetLastError(0x649);
    return 0;
  }
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  InterlockedIncrement(*(LONG **)(param_1 + 0xc));
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (((*(uint *)(param_1 + 0x1c) & 0x40000000) == 0) &&
     ((*(uint *)(param_1 + 0x20) & 0x40000000) == 0)) {
    dwErrCode = 0xc;
  }
  else {
    if ((*(ushort *)(*(int *)(param_1 + 8) + 0x48) & 0x8000) == 0) {
      iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x28))
                        (*(undefined4 *)(param_1 + 4),param_2,param_3);
      *param_4 = iVar1;
      if (iVar1 == -1) {
        *param_4 = 0;
      }
      else {
        uVar2 = 1;
      }
      goto LAB_c02c494c;
    }
    *param_4 = -1;
    dwErrCode = 0x651;
  }
  uVar2 = 0;
  SetLastError(dwErrCode);
LAB_c02c494c:
  InterlockedDecrement((LONG *)(param_1 + 0x10));
  InterlockedDecrement(*(LONG **)(param_1 + 0xc));
  return uVar2;
}



/* c02c49c8 FUN_c02c49c8 */

/* Boundary evidence: original MIPS .pdata c02c49c8..c02c4a03. Semantic name remains unreviewed. */

undefined4 FUN_c02c49c8(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x2c) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x2c),0);
  return 1;
}



/* c02c4a04 FUN_c02c4a04 */

/* Boundary evidence: original MIPS .pdata c02c4a04..c02c4b77. Semantic name remains unreviewed. */

undefined4 FUN_c02c4a04(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = 0xffffffff;
  uVar3 = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (*(int *)(param_1 + 8) == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    SetLastError(0x649);
  }
  else {
    InterlockedIncrement((LONG *)(param_1 + 0x10));
    InterlockedIncrement(*(LONG **)(param_1 + 0xc));
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    iVar1 = *(int *)(param_1 + 8);
    if ((*(ushort *)(iVar1 + 0x48) & 0x8000) == 0) {
      uVar2 = (**(code **)(iVar1 + 0x2c))(*(undefined4 *)(param_1 + 4),param_2,param_4,iVar1,uVar3);
    }
    else {
      SetLastError(0x651);
    }
    InterlockedDecrement((LONG *)(param_1 + 0x10));
    InterlockedDecrement(*(LONG **)(param_1 + 0xc));
  }
  return uVar2;
}



/* c02c4b78 FUN_c02c4b78 */

/* Boundary evidence: original MIPS .pdata c02c4b78..c02c4b83. Semantic name remains unreviewed. */

undefined4 FUN_c02c4b78(void)

{
  return 1;
}



/* c02c4b84 FUN_c02c4b84 */

/* Boundary evidence: original MIPS .pdata c02c4b84..c02c4def. Semantic name remains unreviewed. */

int FUN_c02c4b84(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  DWORD dwErrCode;
  int iVar1;
  DWORD DVar2;
  int iVar3;
  
  iVar3 = 0;
  dwErrCode = GetLastError();
  SetLastError(0x1f);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (*(int *)(param_1 + 8) == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    DVar2 = 0x649;
  }
  else {
    if (((param_2 != 0x10303ff) || (iVar1 = CeGetCallerTrust(), iVar1 == 2)) ||
       (iVar1 = GetCallerProcess(), *(int *)(param_1 + 0x18) == iVar1)) {
      InterlockedIncrement((LONG *)(param_1 + 0x10));
      InterlockedIncrement(*(LONG **)(param_1 + 0xc));
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      if ((*(ushort *)(*(int *)(param_1 + 8) + 0x48) & 0x8000) == 0) {
        iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                          (*(undefined4 *)(param_1 + 4),param_2,param_3,param_4,param_5,param_6,
                           param_7);
      }
      else {
        iVar3 = 0;
        SetLastError(0x651);
      }
      InterlockedDecrement((LONG *)(param_1 + 0x10));
      InterlockedDecrement(*(LONG **)(param_1 + 0xc));
      goto LAB_c02c4d7c;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    DVar2 = 5;
  }
  SetLastError(DVar2);
LAB_c02c4d7c:
  if ((iVar3 != 0) && (DVar2 = GetLastError(), DVar2 == 0x1f)) {
    SetLastError(dwErrCode);
  }
  return iVar3;
}



/* c02c4df0 FUN_c02c4df0 */

/* Boundary evidence: original MIPS .pdata c02c4df0..c02c4e2b. Semantic name remains unreviewed. */

undefined4 FUN_c02c4df0(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x34) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x34),0);
  return 1;
}



/* c02c4e2c FUN_c02c4e2c */

/* Boundary evidence: original MIPS .pdata c02c4e2c..c02c4e53. Semantic name remains unreviewed. */

undefined4 FUN_c02c4e2c(void)

{
  SetLastError(1);
  return 0xffffffff;
}



/* c02c4e54 FUN_c02c4e54 */

/* Boundary evidence: original MIPS .pdata c02c4e54..c02c4f27. Semantic name remains unreviewed. */

undefined4 FUN_c02c4e54(int param_1,uint *param_2)

{
  int *piVar1;
  DWORD dwErrCode;
  
  if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
    dwErrCode = 0x57;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    dwErrCode = 6;
    for (piVar1 = (int *)DAT_c02d22b4; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (piVar1 == (int *)param_1) {
        if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
          dwErrCode = FUN_c02c8df8(*(undefined4 **)(param_1 + 8),param_2);
        }
        break;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c02c4f28 FUN_c02c4f28 */

/* Boundary evidence: original MIPS .pdata c02c4f28..c02c5023. Semantic name remains unreviewed. */

int FUN_c02c4f28(int param_1,uint *param_2)

{
  int iVar1;
  uint local_648 [396];
  uint local_18;
  
  local_18 = DAT_c02d2224;
  if ((param_2 == (uint *)0x0) || (*param_2 < 0x630)) {
    SetLastError(0x57);
    iVar1 = 0;
  }
  else {
    local_648[0] = 0x630;
    iVar1 = FUN_c02c4e54(param_1,local_648);
    if (iVar1 != 0) {
      memcpy(param_2,local_648,0x630);
    }
  }
  FUN_c02d1074(local_18);
  return iVar1;
}



/* c02c5024 FUN_c02c5024 */

/* Boundary evidence: original MIPS .pdata c02c5024..c02c502f. Semantic name remains unreviewed. */

undefined4 FUN_c02c5024(void)

{
  return 1;
}



/* c02c5030 FUN_c02c5030 */

/* Boundary evidence: original MIPS .pdata c02c5030..c02c5057. Semantic name remains unreviewed. */

undefined4 FUN_c02c5030(void)

{
  SetLastError(1);
  return 0;
}



/* c02c5058 FUN_c02c5058 */

/* Boundary evidence: original MIPS .pdata c02c5058..c02c507f. Semantic name remains unreviewed. */

undefined4 FUN_c02c5058(void)

{
  SetLastError(1);
  return 0;
}



/* c02c5080 FUN_c02c5080 */

/* Boundary evidence: original MIPS .pdata c02c5080..c02c50a7. Semantic name remains unreviewed. */

undefined4 FUN_c02c5080(void)

{
  SetLastError(1);
  return 0;
}



/* c02c50a8 FUN_c02c50a8 */

/* Boundary evidence: original MIPS .pdata c02c50a8..c02c50cf. Semantic name remains unreviewed. */

undefined4 FUN_c02c50a8(void)

{
  SetLastError(1);
  return 0;
}



/* c02c50d0 FUN_c02c50d0 */

/* Boundary evidence: original MIPS .pdata c02c50d0..c02c512b. Semantic name remains unreviewed. */

LONG FUN_c02c50d0(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 < 1) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(param_1,1);
  }
  return LVar1;
}



/* c02c512c FUN_c02c512c */

/* Boundary evidence: original MIPS .pdata c02c512c..c02c52a3. Semantic name remains unreviewed. */

undefined4 FUN_c02c512c(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  DWORD dwErrCode;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_40 [2];
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else {
    puVar1 = (undefined4 *)FUN_c02c68b0(DAT_c02d2244,2,0);
    if (puVar1 != (undefined4 *)0x0) {
      uVar4 = puVar1[7];
      uVar5 = puVar1[8];
      uVar6 = puVar1[9];
      uVar2 = GetCallerProcess();
      uVar3 = VirtualAllocCopyEx(uVar2,uVar6,param_1,0xc,4);
      if (uVar3 == 0) {
        uVar2 = 0;
      }
      else {
        memset(local_40,0,0x24);
        local_40[0] = GetDirectCallerProcessId();
        local_38 = 0x1040fac;
        local_30 = 0xc;
        local_34 = uVar3;
        uVar2 = CeFsIoControlW(puVar1[0xe],0x1090034,local_40,0x24,0,0,0,0,uVar4,uVar5);
        VirtualFreeEx((HANDLE)puVar1[9],(LPVOID)(uVar3 & 0xffff0000),0,0x8000);
      }
      FUN_c02c50d0(puVar1);
      return uVar2;
    }
    dwErrCode = 0x426;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c02c52a4 FUN_c02c52a4 */

/* Boundary evidence: original MIPS .pdata c02c52a4..c02c52bf. Semantic name remains unreviewed. */

void FUN_c02c52a4(int param_1)

{
  FUN_c02c512c(param_1);
  return;
}



/* c02c52c0 FUN_c02c52c0 */

/* Boundary evidence: original MIPS .pdata c02c52c0..c02c531f. Semantic name remains unreviewed. */

PHKEY FUN_c02c52c0(PHKEY param_1,HKEY param_2,LPCWSTR param_3)

{
  LSTATUS LVar1;
  
  *param_1 = (HKEY)0x0;
  if (param_3 != (LPCWSTR)0x0) {
    LVar1 = RegOpenKeyExW(param_2,param_3,0,0,param_1);
    if (LVar1 != 0) {
      *param_1 = (HKEY)0x0;
    }
  }
  return param_1;
}



/* c02c5320 FUN_c02c5320 */

/* Boundary evidence: original MIPS .pdata c02c5320..c02c5363. Semantic name remains unreviewed. */

undefined4 * FUN_c02c5320(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c02c1560;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c02c5364 FUN_c02c5364 */

/* Boundary evidence: original MIPS .pdata c02c5364..c02c53fb. Semantic name remains unreviewed. */

ULONG_PTR FUN_c02c5364(LPCRITICAL_SECTION param_1,int param_2)

{
  ULONG_PTR UVar1;
  ULONG_PTR UVar2;
  
  EnterCriticalSection(param_1);
  UVar1 = param_1->SpinCount;
  do {
    UVar2 = 0;
    if (UVar1 == 0) {
LAB_c02c53d8:
      LeaveCriticalSection(param_1);
      return UVar2;
    }
    if (*(int *)(UVar1 + 0x24) == param_2) {
      InterlockedIncrement((LONG *)(UVar1 + 4));
      UVar2 = UVar1;
      goto LAB_c02c53d8;
    }
    UVar1 = *(ULONG_PTR *)(UVar1 + 0x2c);
  } while( true );
}



/* c02c53fc FUN_c02c53fc */

/* Boundary evidence: original MIPS .pdata c02c53fc..c02c5573. Semantic name remains unreviewed. */

undefined4 FUN_c02c53fc(int param_1)

{
  BOOL BVar1;
  int iVar2;
  DWORD DVar3;
  undefined4 uVar4;
  uint uVar5;
  LPPROCESS_INFORMATION lpProcessInformation;
  
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if ((*(LPCWSTR *)(param_1 + 0x34) != (LPCWSTR)0x0) && (*(LPWSTR *)(param_1 + 0x38) != (LPWSTR)0x0)
     ) {
    lpProcessInformation = (LPPROCESS_INFORMATION)(param_1 + 0x1c);
    BVar1 = CreateProcessW(*(LPCWSTR *)(param_1 + 0x34),*(LPWSTR *)(param_1 + 0x38),
                           (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,
                           (LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,lpProcessInformation);
    uVar4 = 0;
    if (BVar1 != 0) {
      uVar5 = *(uint *)(param_1 + 0x3c);
      iVar2 = CeFsIoControlW(*(undefined4 *)(param_1 + 0x38),0x1090804,0,0,0,0,0,0);
      for (; (((iVar2 == 0 && (uVar5 != 0)) &&
              (DVar3 = WaitForSingleObject(lpProcessInformation->hProcess,10), DVar3 != 0)) &&
             (10 < uVar5)); uVar5 = uVar5 - 10) {
        iVar2 = CeFsIoControlW(*(undefined4 *)(param_1 + 0x38),0x1090804,0,0,0,0,0,0);
      }
      uVar4 = 1;
      DVar3 = WaitForSingleObject(lpProcessInformation->hProcess,1);
      if (DVar3 == 0) {
        uVar4 = 0;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return uVar4;
}



/* c02c5574 FUN_c02c5574 */

/* Boundary evidence: original MIPS .pdata c02c5574..c02c55e7. Semantic name remains unreviewed. */

void FUN_c02c5574(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  ULONG_PTR UVar2;
  
  EnterCriticalSection(param_1);
  while (param_1->SpinCount != 0) {
    puVar1 = (undefined4 *)param_1->SpinCount;
    UVar2 = puVar1[10];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
    param_1->SpinCount = UVar2;
  }
  LeaveCriticalSection(param_1);
  DeleteCriticalSection(param_1);
  return;
}



/* c02c55e8 FUN_c02c55e8 */

/* Boundary evidence: original MIPS .pdata c02c55e8..c02c5697. Semantic name remains unreviewed. */

ULONG_PTR FUN_c02c55e8(LPCRITICAL_SECTION param_1,ULONG_PTR param_2,int param_3)

{
  ULONG_PTR UVar1;
  ULONG_PTR UVar2;
  ULONG_PTR *pUVar3;
  
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    EnterCriticalSection(param_1);
    if ((param_3 == 0) && (UVar2 = param_1->SpinCount, UVar2 != 0)) {
      pUVar3 = (ULONG_PTR *)(UVar2 + 0x28);
      UVar1 = *pUVar3;
      while (UVar1 != 0) {
        UVar2 = *pUVar3;
        pUVar3 = (ULONG_PTR *)(UVar2 + 0x28);
        UVar1 = *pUVar3;
      }
      *(ULONG_PTR *)(UVar2 + 0x28) = param_2;
    }
    else {
      *(ULONG_PTR *)(param_2 + 0x28) = param_1->SpinCount;
      param_1->SpinCount = param_2;
    }
    InterlockedIncrement((LONG *)(param_2 + 4));
    LeaveCriticalSection(param_1);
  }
  return param_2;
}



/* c02c5698 FUN_c02c5698 */

/* Boundary evidence: original MIPS .pdata c02c5698..c02c5743. Semantic name remains unreviewed. */

undefined4 * FUN_c02c5698(LPCRITICAL_SECTION param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  EnterCriticalSection(param_1);
  puVar3 = (undefined4 *)param_1->SpinCount;
  puVar4 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    if (puVar3 == param_2) {
      param_1->SpinCount = param_2[10];
LAB_c02c5714:
      FUN_c02c50d0(param_2);
      puVar4 = param_2;
    }
    else {
      iVar2 = puVar3[10];
      while (iVar2 != 0) {
        puVar1 = (undefined4 *)puVar3[10];
        if (puVar1 == param_2) {
          puVar3[10] = param_2[10];
          goto LAB_c02c5714;
        }
        puVar3 = puVar1;
        iVar2 = puVar1[10];
      }
    }
  }
  LeaveCriticalSection(param_1);
  return puVar4;
}



/* c02c5744 FUN_c02c5744 */

/* Boundary evidence: original MIPS .pdata c02c5744..c02c57d3. Semantic name remains unreviewed. */

ULONG_PTR FUN_c02c5744(LPCRITICAL_SECTION param_1,ULONG_PTR param_2)

{
  ULONG_PTR UVar1;
  ULONG_PTR UVar2;
  
  if (param_2 == 0) {
    UVar2 = 0;
  }
  else {
    EnterCriticalSection(param_1);
    for (UVar1 = param_1->SpinCount; UVar2 = 0, UVar1 != 0; UVar1 = *(ULONG_PTR *)(UVar1 + 0x28)) {
      if (UVar1 == param_2) {
        UVar2 = UVar1;
        if (UVar1 != 0) {
          InterlockedIncrement((LONG *)(UVar1 + 4));
        }
        break;
      }
    }
    LeaveCriticalSection(param_1);
  }
  return UVar2;
}



/* c02c57d4 FUN_c02c57d4 */

/* Boundary evidence: original MIPS .pdata c02c57d4..c02c5847. Semantic name remains unreviewed. */

void FUN_c02c57d4(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  ULONG_PTR UVar2;
  
  EnterCriticalSection(param_1);
  while (param_1->SpinCount != 0) {
    puVar1 = (undefined4 *)param_1->SpinCount;
    UVar2 = puVar1[0xb];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
    param_1->SpinCount = UVar2;
  }
  LeaveCriticalSection(param_1);
  DeleteCriticalSection(param_1);
  return;
}



/* c02c5848 FUN_c02c5848 */

/* Boundary evidence: original MIPS .pdata c02c5848..c02c58f7. Semantic name remains unreviewed. */

ULONG_PTR FUN_c02c5848(LPCRITICAL_SECTION param_1,ULONG_PTR param_2,int param_3)

{
  ULONG_PTR UVar1;
  ULONG_PTR UVar2;
  ULONG_PTR *pUVar3;
  
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    EnterCriticalSection(param_1);
    if ((param_3 == 0) && (UVar2 = param_1->SpinCount, UVar2 != 0)) {
      pUVar3 = (ULONG_PTR *)(UVar2 + 0x2c);
      UVar1 = *pUVar3;
      while (UVar1 != 0) {
        UVar2 = *pUVar3;
        pUVar3 = (ULONG_PTR *)(UVar2 + 0x2c);
        UVar1 = *pUVar3;
      }
      *(ULONG_PTR *)(UVar2 + 0x2c) = param_2;
    }
    else {
      *(ULONG_PTR *)(param_2 + 0x2c) = param_1->SpinCount;
      param_1->SpinCount = param_2;
    }
    InterlockedIncrement((LONG *)(param_2 + 4));
    LeaveCriticalSection(param_1);
  }
  return param_2;
}



/* c02c58f8 FUN_c02c58f8 */

/* Boundary evidence: original MIPS .pdata c02c58f8..c02c59a3. Semantic name remains unreviewed. */

undefined4 * FUN_c02c58f8(LPCRITICAL_SECTION param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  EnterCriticalSection(param_1);
  puVar3 = (undefined4 *)param_1->SpinCount;
  puVar4 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    if (puVar3 == param_2) {
      param_1->SpinCount = param_2[0xb];
LAB_c02c5974:
      FUN_c02c50d0(param_2);
      puVar4 = param_2;
    }
    else {
      iVar2 = puVar3[0xb];
      while (iVar2 != 0) {
        puVar1 = (undefined4 *)puVar3[0xb];
        if (puVar1 == param_2) {
          puVar3[0xb] = param_2[0xb];
          goto LAB_c02c5974;
        }
        puVar3 = puVar1;
        iVar2 = puVar1[0xb];
      }
    }
  }
  LeaveCriticalSection(param_1);
  return puVar4;
}



/* c02c59a4 FUN_c02c59a4 */

/* Boundary evidence: original MIPS .pdata c02c59a4..c02c5a33. Semantic name remains unreviewed. */

ULONG_PTR FUN_c02c59a4(LPCRITICAL_SECTION param_1,ULONG_PTR param_2)

{
  ULONG_PTR UVar1;
  ULONG_PTR UVar2;
  
  if (param_2 == 0) {
    UVar2 = 0;
  }
  else {
    EnterCriticalSection(param_1);
    for (UVar1 = param_1->SpinCount; UVar2 = 0, UVar1 != 0; UVar1 = *(ULONG_PTR *)(UVar1 + 0x2c)) {
      if (UVar1 == param_2) {
        UVar2 = UVar1;
        if (UVar1 != 0) {
          InterlockedIncrement((LONG *)(UVar1 + 4));
        }
        break;
      }
    }
    LeaveCriticalSection(param_1);
  }
  return UVar2;
}



/* c02c5a34 FUN_c02c5a34 */

/* Boundary evidence: original MIPS .pdata c02c5a34..c02c5cff. Semantic name remains unreviewed. */

LPCRITICAL_SECTION FUN_c02c5a34(LPCRITICAL_SECTION param_1)

{
  LSTATUS LVar1;
  LPBYTE pBVar2;
  uint uVar3;
  uint uVar4;
  DWORD local_38;
  HKEY local_34;
  DWORD local_30;
  DWORD local_2c;
  DWORD local_28 [2];
  
  InitializeCriticalSection(param_1);
  param_1->SpinCount = 0;
  param_1[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x1000;
  param_1[1].LockCount = 0;
  local_38 = 0;
  FUN_c02c52c0(&local_34,(HKEY)0x80000002,L"Drivers");
  uVar4 = 0xffffffff;
  if (((local_34 != (HKEY)0x0) &&
      (LVar1 = RegQueryValueExW(local_34,L"ProcName",(LPDWORD)0x0,&local_30,(LPBYTE)0x0,&local_38),
      LVar1 == 0)) && (local_30 == 1)) {
    local_38 = (local_38 >> 1) + 1;
    if (0x103 < local_38) {
      local_38 = 0x104;
    }
    uVar3 = local_38 << 1;
    if (0x7fffffff < local_38) {
      uVar3 = uVar4;
    }
    pBVar2 = operator_new(uVar3);
    param_1[1].LockCount = (LONG)pBVar2;
    if (pBVar2 != (LPBYTE)0x0) {
      local_2c = local_38 << 1;
      local_28[0] = 0;
      LVar1 = RegQueryValueExW(local_34,L"ProcName",(LPDWORD)0x0,local_28,pBVar2,&local_2c);
      if (LVar1 != 0) {
        operator_delete((void *)param_1[1].LockCount);
        param_1[1].LockCount = 0;
      }
    }
    if (param_1[1].LockCount != 0) {
      *(undefined2 *)(local_38 * 2 + param_1[1].LockCount + -2) = 0;
    }
  }
  param_1[1].RecursionCount = 0;
  if (local_34 != (HKEY)0x0) {
    LVar1 = RegQueryValueExW(local_34,L"ProcVolPrefix",(LPDWORD)0x0,&local_30,(LPBYTE)0x0,&local_38)
    ;
    if ((LVar1 == 0) && (local_30 == 1)) {
      local_38 = (local_38 >> 1) + 1;
      if (0x103 < local_38) {
        local_38 = 0x104;
      }
      if (local_38 < 0x80000000) {
        uVar4 = local_38 << 1;
      }
      pBVar2 = operator_new(uVar4);
      param_1[1].RecursionCount = (LONG)pBVar2;
      if (pBVar2 != (LPBYTE)0x0) {
        local_28[0] = local_38 << 1;
        local_2c = 0;
        LVar1 = RegQueryValueExW(local_34,L"ProcVolPrefix",(LPDWORD)0x0,&local_2c,pBVar2,local_28);
        if (LVar1 != 0) {
          operator_delete((void *)param_1[1].RecursionCount);
          param_1[1].RecursionCount = 0;
        }
      }
      if (param_1[1].RecursionCount != 0) {
        *(undefined2 *)(local_38 * 2 + param_1[1].RecursionCount + -2) = 0;
      }
    }
    if (local_34 != (HKEY)0x0) {
      local_28[0] = 4;
      local_2c = 0;
      LVar1 = RegQueryValueExW(local_34,L"ProcTimeout",(LPDWORD)0x0,&local_2c,
                               (LPBYTE)&param_1[1].OwningThread,local_28);
      if (LVar1 == 0) goto LAB_c02c5cc0;
    }
  }
  param_1[1].OwningThread = (HANDLE)0x4e20;
LAB_c02c5cc0:
  if (local_34 != (HKEY)0x0) {
    RegCloseKey(local_34);
  }
  return param_1;
}



/* c02c5d00 FUN_c02c5d00 */

/* Boundary evidence: original MIPS .pdata c02c5d00..c02c5d4f. Semantic name remains unreviewed. */

void FUN_c02c5d00(LPCRITICAL_SECTION param_1)

{
  if ((void *)param_1[1].LockCount != (void *)0x0) {
    operator_delete((void *)param_1[1].LockCount);
  }
  if ((void *)param_1[1].RecursionCount != (void *)0x0) {
    operator_delete((void *)param_1[1].RecursionCount);
  }
  FUN_c02c57d4(param_1);
  return;
}



/* c02c5d50 FUN_c02c5d50 */

/* Boundary evidence: original MIPS .pdata c02c5d50..c02c5e43. Semantic name remains unreviewed. */

void FUN_c02c5d50(undefined4 *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 2);
  *param_1 = &PTR_FUN_c02c15bc;
  EnterCriticalSection(lpCriticalSection);
  CeFsIoControlW(param_1[0xe],0x1090800,0,0,0,0,0,0);
  if ((void *)param_1[0xd] != (void *)0x0) {
    operator_delete((void *)param_1[0xd]);
  }
  if ((void *)param_1[0xe] != (void *)0x0) {
    operator_delete((void *)param_1[0xe]);
  }
  if ((HANDLE)param_1[7] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[7]);
  }
  if ((HANDLE)param_1[8] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[8]);
  }
  LeaveCriticalSection(lpCriticalSection);
  FUN_c02c5574((LPCRITICAL_SECTION)(param_1 + 0x11));
  DeleteCriticalSection(lpCriticalSection);
  *param_1 = &PTR_FUN_c02c1560;
  return;
}



/* c02c5e44 FUN_c02c5e44 */

/* Boundary evidence: original MIPS .pdata c02c5e44..c02c5e5f. Semantic name remains unreviewed. */

void FUN_c02c5e44(int param_1,ULONG_PTR param_2)

{
  FUN_c02c5744((LPCRITICAL_SECTION)(param_1 + 0x44),param_2);
  return;
}



/* c02c5e60 FUN_c02c5e60 */

/* Boundary evidence: original MIPS .pdata c02c5e60..c02c5ebb. Semantic name remains unreviewed. */

undefined4 FUN_c02c5e60(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x16] == 0) {
    uVar1 = 1;
    param_1[0x10] = 1;
    if (DAT_c02d2244 != (LPCRITICAL_SECTION)0x0) {
      FUN_c02c58f8(DAT_c02d2244,param_1);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c02c5ebc FUN_c02c5ebc */

/* Boundary evidence: original MIPS .pdata c02c5ebc..c02c5fab. Semantic name remains unreviewed. */

uint FUN_c02c5ebc(int param_1,undefined4 param_2,uint *param_3,uint param_4,LPHANDLE param_5,
                 uint param_6,undefined4 *param_7)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((*(int *)(param_1 + 0x40) == 0) && (*(int *)(param_1 + 0x58) != 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    iVar1 = *(int *)(param_1 + 0x58);
    while ((iVar1 != 0 &&
           (uVar2 = FUN_c02cdc2c(iVar1,param_2,param_3,param_4,param_5,param_6,param_7), uVar2 == 0)
           )) {
      iVar1 = *(int *)(iVar1 + 0x28);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  return uVar2;
}



/* c02c5fac FUN_c02c5fac */

/* Boundary evidence: original MIPS .pdata c02c5fac..c02c607b. Semantic name remains unreviewed. */

uint FUN_c02c5fac(undefined4 param_1,uint *param_2,uint param_3,LPHANDLE param_4,uint param_5,
                 undefined4 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  SetLastError(0x57);
  if (DAT_c02d2244 != (LPCRITICAL_SECTION)0x0) {
    iVar1 = GetDirectCallerProcessId();
    puVar2 = (undefined4 *)FUN_c02c5364(DAT_c02d2244,iVar1);
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = FUN_c02c5ebc((int)puVar2,param_1,param_2,param_3,param_4,param_5,param_6);
      FUN_c02c50d0(puVar2);
    }
  }
  return uVar3;
}



/* c02c607c FUN_c02c607c */

/* Boundary evidence: original MIPS .pdata c02c607c..c02c6257. Semantic name remains unreviewed. */

undefined4 *
FUN_c02c607c(undefined4 *param_1,undefined4 param_2,STRSAFE_PCNZWCH param_3,int param_4,
            undefined4 param_5,undefined4 param_6)

{
  HRESULT HVar1;
  STRSAFE_LPWSTR pwVar2;
  uint uVar3;
  uint uVar4;
  size_t local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c02d2224;
  *param_1 = &PTR_FUN_c02c1560;
  param_1[1] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  *param_1 = &PTR_FUN_c02c15bc;
  param_1[0xb] = param_6;
  param_1[0xc] = param_2;
  param_1[0xf] = param_5;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x11));
  param_1[0x16] = 0;
  param_1[0xd] = 0;
  uVar4 = 0xffffffff;
  param_1[0xe] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  if ((param_3 != (STRSAFE_PCNZWCH)0x0) &&
     (HVar1 = StringCchLengthW(param_3,0x104,local_238), -1 < HVar1)) {
    uVar3 = (local_238[0] + 1) * 2;
    if (0x7fffffff < local_238[0] + 1) {
      uVar3 = uVar4;
    }
    pwVar2 = operator_new(uVar3);
    param_1[0xd] = pwVar2;
    if ((pwVar2 != (STRSAFE_LPWSTR)0x0) &&
       (HVar1 = StringCchCopyW(pwVar2,local_238[0] + 1,param_3), HVar1 < 0)) {
      operator_delete((void *)param_1[0xd]);
      param_1[0xd] = 0;
    }
  }
  if (param_4 != 0) {
    HVar1 = StringCchPrintfW(awStack_230,0x104,L"%s_%04x",param_4,param_2);
    if ((-1 < HVar1) && (HVar1 = StringCchLengthW(awStack_230,0x104,local_238), -1 < HVar1)) {
      if (local_238[0] + 1 < 0x80000000) {
        uVar4 = (local_238[0] + 1) * 2;
      }
      pwVar2 = operator_new(uVar4);
      param_1[0xe] = pwVar2;
      if ((pwVar2 != (STRSAFE_LPWSTR)0x0) &&
         (HVar1 = StringCchCopyW(pwVar2,local_238[0] + 1,awStack_230), HVar1 < 0)) {
        operator_delete((void *)param_1[0xe]);
        param_1[0xe] = 0;
      }
    }
  }
  param_1[0x10] = 0;
  FUN_c02d1074(local_28);
  return param_1;
}



/* c02c6258 FUN_c02c6258 */

/* Boundary evidence: original MIPS .pdata c02c6258..c02c62a3. Semantic name remains unreviewed. */

undefined4 * FUN_c02c6258(undefined4 *param_1,uint param_2)

{
  FUN_c02c5d50(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c02c62a4 FUN_c02c62a4 */

/* Boundary evidence: original MIPS .pdata c02c62a4..c02c63af. Semantic name remains unreviewed. */

int * FUN_c02c62a4(undefined4 *param_1,STRSAFE_LPCWSTR param_2,STRSAFE_LPCWSTR param_3,
                  undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  if (param_1[0x10] == 0) {
    puVar1 = operator_new(0x14c);
    if (puVar1 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_c02ccc8c(puVar1,(int)param_1,param_2,param_3,param_4,0);
    }
    if (piVar3 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar3 + 4))(piVar3);
      if (iVar2 == 0) {
        (**(code **)*piVar3)(piVar3,1);
        piVar3 = (int *)0x0;
      }
      if (piVar3 != (int *)0x0) {
        FUN_c02c55e8((LPCRITICAL_SECTION)(param_1 + 0x11),(ULONG_PTR)piVar3,1);
      }
    }
    FUN_c02c5e60(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  return piVar3;
}



/* c02c63b0 FUN_c02c63b0 */

/* Boundary evidence: original MIPS .pdata c02c63b0..c02c642b. Semantic name remains unreviewed. */

undefined4 FUN_c02c63b0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  uVar2 = 0;
  if (param_2 != (undefined4 *)0x0) {
    puVar1 = FUN_c02c5698((LPCRITICAL_SECTION)(param_1 + 0x11),param_2);
    uVar2 = 1;
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0;
    }
  }
  FUN_c02c5e60(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  return uVar2;
}



/* c02c642c FUN_c02c642c */

/* Boundary evidence: original MIPS .pdata c02c642c..c02c655b. Semantic name remains unreviewed. */

undefined4 FUN_c02c642c(void)

{
  LPCRITICAL_SECTION p_Var1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_c02d2244 == (LPCRITICAL_SECTION)0x0) {
    p_Var1 = operator_new(0x28);
    if (p_Var1 == (LPCRITICAL_SECTION)0x0) {
      p_Var1 = (LPCRITICAL_SECTION)0x0;
    }
    else {
      p_Var1 = FUN_c02c5a34(p_Var1);
    }
    DAT_c02d2244 = p_Var1;
    if ((p_Var1 != (LPCRITICAL_SECTION)0x0) &&
       ((p_Var1[1].RecursionCount == 0 || (p_Var1[1].LockCount == 0)))) {
      FUN_c02c5d00(p_Var1);
      operator_delete(p_Var1);
      DAT_c02d2244 = (LPCRITICAL_SECTION)0x0;
    }
  }
  if (DAT_c02d2248 == (LPCRITICAL_SECTION)0x0) {
    p_Var1 = operator_new(0x1c);
    if (p_Var1 == (LPCRITICAL_SECTION)0x0) {
      DAT_c02d2248 = (LPCRITICAL_SECTION)0x0;
    }
    else {
      DAT_c02d2248 = FUN_c02cb3c4(p_Var1);
    }
    if ((DAT_c02d2248 != (LPCRITICAL_SECTION)0x0) &&
       (iVar2 = FUN_c02cb06c((int)DAT_c02d2248), p_Var1 = DAT_c02d2248, iVar2 == 0)) {
      if (DAT_c02d2248 != (LPCRITICAL_SECTION)0x0) {
        FUN_c02cb3fc(DAT_c02d2248);
        operator_delete(p_Var1);
      }
      DAT_c02d2248 = (LPCRITICAL_SECTION)0x0;
    }
  }
  if ((DAT_c02d2244 == (LPCRITICAL_SECTION)0x0) || (DAT_c02d2248 == (LPCRITICAL_SECTION)0x0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* c02c655c FUN_c02c655c */

/* Boundary evidence: original MIPS .pdata c02c655c..c02c6817. Semantic name remains unreviewed. */

int * FUN_c02c655c(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  HRESULT HVar1;
  LSTATUS LVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  ULONG_PTR UVar6;
  HANDLE pvVar7;
  BYTE *pBVar8;
  STRSAFE_PCNZWCH pwVar9;
  HKEY local_668;
  DWORD local_664;
  DWORD local_660;
  HKEY local_65c;
  DWORD local_658 [2];
  HANDLE local_650 [2];
  wchar_t awStack_648 [259];
  undefined2 local_442;
  BYTE aBStack_440 [518];
  undefined2 local_23a;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c02d2224;
  pwVar9 = (STRSAFE_PCNZWCH)param_1[1].LockCount;
  pBVar8 = (BYTE *)param_1[1].RecursionCount;
  pvVar7 = param_1[1].OwningThread;
  FUN_c02c52c0(&local_65c,(HKEY)0x80000002,L"Drivers");
  if (local_65c != (HKEY)0x0) {
    HVar1 = StringCchPrintfW(awStack_238,0x104,L"%s_%04x",L"ProcGroup",param_2);
    if (-1 < HVar1) {
      FUN_c02c52c0(&local_668,local_65c,awStack_238);
      if (local_668 != (HKEY)0x0) {
        local_664 = 0x208;
        LVar2 = RegQueryValueExW(local_668,L"ProcName",(LPDWORD)0x0,&local_660,(LPBYTE)awStack_648,
                                 &local_664);
        if ((LVar2 == 0) && (local_660 == 1)) {
          local_442 = 0;
          pwVar9 = awStack_648;
        }
        local_664 = 0x208;
        LVar2 = RegQueryValueExW(local_668,L"ProcVolPrefix",(LPDWORD)0x0,&local_660,aBStack_440,
                                 &local_664);
        if ((LVar2 == 0) && (local_660 == 1)) {
          local_23a = 0;
          pBVar8 = aBStack_440;
        }
        local_658[0] = 4;
        local_658[1] = 0;
        LVar2 = RegQueryValueExW(local_668,L"ProcTimeout",(LPDWORD)0x0,local_658 + 1,
                                 (LPBYTE)local_650,local_658);
        if (LVar2 == 0) {
          pvVar7 = local_650[0];
        }
        if (local_668 != (HKEY)0x0) {
          RegCloseKey(local_668);
        }
      }
    }
  }
  EnterCriticalSection(param_1);
  puVar3 = operator_new(0x5c);
  if (puVar3 == (undefined4 *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = FUN_c02c607c(puVar3,param_2,pwVar9,(int)pBVar8,pvVar7,0);
  }
  if (piVar4 != (int *)0x0) {
    iVar5 = (**(code **)(*piVar4 + 4))(piVar4);
    if (iVar5 == 0) {
      (**(code **)*piVar4)(piVar4,1);
      piVar4 = (int *)0x0;
    }
    if ((piVar4 != (int *)0x0) && (UVar6 = FUN_c02c5848(param_1,(ULONG_PTR)piVar4,1), UVar6 == 0)) {
      (**(code **)*piVar4)(piVar4,1);
      piVar4 = (int *)0x0;
    }
  }
  LeaveCriticalSection(param_1);
  if (local_65c != (HKEY)0x0) {
    RegCloseKey(local_65c);
  }
  FUN_c02d1074(local_30);
  return piVar4;
}



/* c02c6818 FUN_c02c6818 */

/* Boundary evidence: original MIPS .pdata c02c6818..c02c68af. Semantic name remains unreviewed. */

int * FUN_c02c6818(LPCRITICAL_SECTION param_1)

{
  int *piVar1;
  ULONG_PTR UVar2;
  PRTL_CRITICAL_SECTION_DEBUG p_Var3;
  ULONG_PTR UVar4;
  
  EnterCriticalSection(param_1);
  UVar2 = param_1->SpinCount;
  while( true ) {
    p_Var3 = (PRTL_CRITICAL_SECTION_DEBUG)((int)&(param_1[1].DebugInfo)->Type + 1);
    param_1[1].DebugInfo = p_Var3;
    if (p_Var3 < (PRTL_CRITICAL_SECTION_DEBUG)0x1000) {
      param_1[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x1000;
    }
    if (UVar2 == 0) break;
    UVar4 = UVar2;
    while (*(PRTL_CRITICAL_SECTION_DEBUG *)(UVar4 + 0x30) != param_1[1].DebugInfo) {
      UVar4 = *(ULONG_PTR *)(UVar4 + 0x2c);
      if (UVar4 == 0) goto LAB_c02c6880;
    }
  }
LAB_c02c6880:
  piVar1 = FUN_c02c655c(param_1,param_1[1].DebugInfo);
  LeaveCriticalSection(param_1);
  return piVar1;
}



/* c02c68b0 FUN_c02c68b0 */

/* Boundary evidence: original MIPS .pdata c02c68b0..c02c69a3. Semantic name remains unreviewed. */

ULONG_PTR FUN_c02c68b0(LPCRITICAL_SECTION param_1,uint param_2,int param_3)

{
  int *piVar1;
  ULONG_PTR UVar2;
  ULONG_PTR UVar3;
  
  UVar3 = 0;
  if ((param_2 < 0x1000) && (param_2 != 0)) {
    EnterCriticalSection(param_1);
    for (UVar2 = param_1->SpinCount; UVar2 != 0; UVar2 = *(ULONG_PTR *)(UVar2 + 0x2c)) {
      if (*(uint *)(UVar2 + 0x30) == param_2) {
        InterlockedIncrement((LONG *)(UVar2 + 4));
        goto LAB_c02c6940;
      }
    }
    UVar2 = UVar3;
    if ((param_3 != 0) && (piVar1 = FUN_c02c655c(param_1,param_2), piVar1 != (int *)0x0)) {
      UVar2 = FUN_c02c59a4(param_1,(ULONG_PTR)piVar1);
    }
LAB_c02c6940:
    LeaveCriticalSection(param_1);
    UVar3 = UVar2;
  }
  else {
    piVar1 = FUN_c02c6818(param_1);
    if (piVar1 != (int *)0x0) {
      UVar3 = FUN_c02c59a4(param_1,(ULONG_PTR)piVar1);
    }
  }
  return UVar3;
}



/* c02c69a4 FUN_c02c69a4 */

/* Boundary evidence: original MIPS .pdata c02c69a4..c02c69cb. Semantic name remains unreviewed. */

undefined4 FUN_c02c69a4(void)

{
  SetLastError(0x32);
  return 0;
}



/* c02c69cc FUN_c02c69cc */

/* Boundary evidence: original MIPS .pdata c02c69cc..c02c69f3. Semantic name remains unreviewed. */

undefined4 FUN_c02c69cc(void)

{
  SetLastError(0x32);
  return 0xffffffff;
}



/* c02c69f4 FUN_c02c69f4 */

/* Boundary evidence: original MIPS .pdata c02c69f4..c02c6a7f. Semantic name remains unreviewed. */

undefined4 FUN_c02c69f4(short *param_1,wchar_t *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_50;
  short local_4c;
  undefined2 local_4a;
  wchar_t awStack_48 [28];
  uint local_10;
  
  local_10 = DAT_c02d2224;
  if ((param_1 != (short *)0x0) && (*param_1 != 0)) {
    local_50 = *(undefined4 *)param_1;
    local_4c = param_1[2];
    local_4a = 0x5f;
    wcscpy(awStack_48,param_2);
    param_2 = (wchar_t *)&local_50;
  }
  uVar1 = GetProcAddressW(param_3,param_2);
  FUN_c02d1074(local_10);
  return uVar1;
}



/* c02c6a80 FUN_c02c6a80 */

/* Boundary evidence: original MIPS .pdata c02c6a80..c02c6c0b. Semantic name remains unreviewed. */

undefined4 * FUN_c02c6a80(wchar_t *param_1,wchar_t *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *local_20;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  puVar2 = DAT_c02d22e0;
  do {
    if ((undefined4 **)puVar2 == &DAT_c02d22e0) {
LAB_c02c6b28:
      puVar2 = (undefined4 *)0x0;
LAB_c02c6b2c:
      if (puVar2 == (undefined4 *)0x0) {
        local_20 = LocalAlloc(0,0x250);
        if (local_20 == (undefined4 *)0x0) {
          SetLastError(0xe);
        }
        else {
          memset(local_20,0,0x250);
          wcsncpy((wchar_t *)(local_20 + 2),param_1,0x20);
          wcsncpy((wchar_t *)(local_20 + 0x12),param_2,0x104);
          *local_20 = &DAT_c02d22e0;
          local_20[1] = DAT_c02d22e4;
          *DAT_c02d22e4 = local_20;
          DAT_c02d22e4 = local_20;
        }
      }
      else {
        local_20 = (undefined4 *)0x0;
      }
      FUN_c02c6c0c();
      return local_20;
    }
    if (((*param_1 != L'\0') && (iVar1 = _wcsicmp((wchar_t *)(puVar2 + 2),param_1), iVar1 == 0)) ||
       ((*param_2 != L'\0' && (iVar1 = _wcsicmp((wchar_t *)(puVar2 + 0x12),param_2), iVar1 == 0))))
    {
      if ((undefined4 **)puVar2 != &DAT_c02d22e0) goto LAB_c02c6b2c;
      goto LAB_c02c6b28;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}



/* c02c6c0c FUN_c02c6c0c */

/* Boundary evidence: original MIPS .pdata c02c6c0c..c02c6c47. Semantic name remains unreviewed. */

void FUN_c02c6c0c(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  return;
}



/* c02c6c48 FUN_c02c6c48 */

/* Boundary evidence: original MIPS .pdata c02c6c48..c02c6ccb. Semantic name remains unreviewed. */

undefined4 FUN_c02c6c48(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  puVar1 = DAT_c02d22d0;
  if ((undefined4 **)DAT_c02d22d0 != &DAT_c02d22d0) {
    do {
      if (puVar1 == param_1) {
        uVar2 = 1;
        break;
      }
      puVar1 = (undefined4 *)*puVar1;
    } while ((undefined4 **)puVar1 != &DAT_c02d22d0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  return uVar2;
}



/* c02c6ccc FUN_c02c6ccc */

/* Boundary evidence: original MIPS .pdata c02c6ccc..c02c6da3. Semantic name remains unreviewed. */

undefined4 * FUN_c02c6ccc(wchar_t *param_1,int param_2)

{
  int iVar1;
  wchar_t *_Str1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  puVar2 = DAT_c02d22d0;
  if ((undefined4 **)DAT_c02d22d0 != &DAT_c02d22d0) {
    do {
      if (param_2 == 0) {
        _Str1 = (wchar_t *)puVar2[0x16];
LAB_c02c6d48:
        if ((_Str1 != (wchar_t *)0x0) && (iVar1 = _wcsicmp(_Str1,param_1), iVar1 == 0)) break;
      }
      else {
        if (param_2 == 1) {
          _Str1 = (wchar_t *)puVar2[0x17];
          goto LAB_c02c6d48;
        }
        if (param_2 == 2) {
          _Str1 = (wchar_t *)puVar2[0x18];
          goto LAB_c02c6d48;
        }
      }
      puVar2 = (undefined4 *)*puVar2;
    } while ((undefined4 **)puVar2 != &DAT_c02d22d0);
    if ((undefined4 **)puVar2 != &DAT_c02d22d0) goto LAB_c02c6d78;
  }
  puVar2 = (undefined4 *)0x0;
LAB_c02c6d78:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  return puVar2;
}



/* c02c6da4 FUN_c02c6da4 */

/* Boundary evidence: original MIPS .pdata c02c6da4..c02c6e93. Semantic name remains unreviewed. */

undefined4 * FUN_c02c6da4(short *param_1,undefined4 param_2,wchar_t *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  wchar_t local_60 [32];
  uint local_20;
  
  local_20 = DAT_c02d2224;
  puVar2 = (undefined4 *)0x0;
  if (*param_1 == 0) {
    local_60[0] = L'\0';
  }
  else {
    StringCchPrintfW(local_60,0x20,L"%s%u",param_1,param_2);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (((*param_1 == 0) || (puVar1 = FUN_c02c6ccc(local_60,1), puVar1 == (undefined4 *)0x0)) &&
     ((*param_3 == L'\0' || (puVar1 = FUN_c02c6ccc(param_3,2), puVar1 == (undefined4 *)0x0)))) {
    puVar2 = FUN_c02c6a80(local_60,param_3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  FUN_c02d1074(local_20);
  return puVar2;
}



/* c02c6e94 FUN_c02c6e94 */

/* Boundary evidence: original MIPS .pdata c02c6e94..c02c6f4f. Semantic name remains unreviewed. */

void FUN_c02c6e94(HLOCAL param_1)

{
  int *piVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  for (piVar2 = (int *)DAT_c02d22b4; piVar1 = DAT_c02d22e8, piVar2 != (int *)0x0;
      piVar2 = (int *)*piVar2) {
    if ((HLOCAL)piVar2[2] == param_1) {
      piVar2[2] = 0;
    }
  }
  for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    if ((HLOCAL)piVar1[2] == param_1) {
      piVar1[2] = 0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (*(HMODULE *)((int)param_1 + 0x40) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)((int)param_1 + 0x40));
  }
  LocalFree(param_1);
  return;
}



/* c02c6f50 FUN_c02c6f50 */

/* Boundary evidence: original MIPS .pdata c02c6f50..c02c7563. Semantic name remains unreviewed. */

HLOCAL FUN_c02c6f50(short *param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                   LPCWSTR param_5,uint param_6,short *param_7,wchar_t *param_8,wchar_t *param_9,
                   undefined4 param_10)

{
  size_t sVar1;
  HLOCAL _Dst;
  int iVar2;
  HMODULE pHVar3;
  undefined4 uVar4;
  wchar_t *_Dest;
  SIZE_T uBytes;
  DWORD dwErrCode;
  short *psVar5;
  short *psVar6;
  wchar_t local_b0 [32];
  wchar_t awStack_70 [32];
  uint local_30;
  
  local_30 = DAT_c02d2224;
  dwErrCode = 0;
  uBytes = 0x70;
  if (*param_1 == 0) {
    local_b0[0] = L'\0';
  }
  else {
    StringCchPrintfW(local_b0,0x20,L"%s%u",param_1,param_2);
    if (param_3 < 10) {
      StringCchPrintfW(awStack_70,0x20,L"%s%u:",param_1,param_3);
      sVar1 = wcslen(awStack_70);
      uBytes = (sVar1 + 0x39) * 2;
    }
    sVar1 = wcslen(local_b0);
    uBytes = (sVar1 + 1) * 2 + uBytes;
  }
  if ((*param_8 == L'\0') && (local_b0[0] != L'\0')) {
    param_8 = local_b0;
  }
  if (*param_8 != L'\0') {
    sVar1 = wcslen(param_8);
    uBytes = (sVar1 + 1) * 2 + uBytes;
  }
  if (param_9 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_9);
    uBytes = (sVar1 + 1) * 2 + uBytes;
  }
  _Dst = LocalAlloc(0,uBytes);
  if (_Dst == (HLOCAL)0x0) {
    dwErrCode = 0xe;
  }
  else {
    psVar5 = (short *)0x0;
    _Dest = (wchar_t *)((int)_Dst + 0x70);
    memset(_Dst,0,uBytes);
    *(undefined4 *)((int)_Dst + 0x44) = param_4;
    *(undefined2 *)((int)_Dst + 0x48) = 0;
    *(uint *)((int)_Dst + 0x6c) = param_6;
    iVar2 = CeGetCallerTrust();
    if (iVar2 == 2) {
      *(ushort *)((int)_Dst + 0x48) = *(ushort *)((int)_Dst + 0x48) | 8;
      *(undefined4 *)((int)_Dst + 0x50) = param_10;
    }
    if (*param_1 != 0) {
      if (param_3 < 10) {
        *(wchar_t **)((int)_Dst + 0x58) = _Dest;
        wcscpy(_Dest,awStack_70);
        sVar1 = wcslen(*(wchar_t **)((int)_Dst + 0x58));
        _Dest = _Dest + sVar1 + 1;
      }
      *(wchar_t **)((int)_Dst + 0x5c) = _Dest;
      wcscpy(_Dest,local_b0);
      sVar1 = wcslen(*(wchar_t **)((int)_Dst + 0x5c));
      _Dest = _Dest + sVar1 + 1;
    }
    if (*param_8 != L'\0') {
      *(wchar_t **)((int)_Dst + 0x60) = _Dest;
      wcscpy(_Dest,param_8);
      sVar1 = wcslen(param_8);
      _Dest = _Dest + sVar1 + 1;
    }
    if (param_9 != (wchar_t *)0x0) {
      *(wchar_t **)((int)_Dst + 100) = _Dest;
      wcscpy(_Dest,param_9);
    }
    psVar6 = psVar5;
    if (((((param_6 & 8) == 0) && (psVar6 = param_1, *param_1 == 0)) &&
        ((*param_7 == 0 || (psVar6 = param_7, *(int *)((int)_Dst + 0x60) == 0)))) &&
       (psVar6 = psVar5, *(int *)((int)_Dst + 0x5c) != 0)) {
      dwErrCode = 1;
    }
    if ((param_6 & 0x10) == 0) {
      if ((param_6 & 2) == 0) {
        pHVar3 = (HMODULE)LoadDriver();
      }
      else {
        pHVar3 = LoadLibraryW(param_5);
      }
      *(HMODULE *)((int)_Dst + 0x40) = pHVar3;
      if (pHVar3 != (HMODULE)0x0) {
        *(undefined4 *)((int)_Dst + 0xc) = 0;
        uVar4 = FUN_c02c69f4(psVar6,L"Init",pHVar3);
        *(undefined4 *)((int)_Dst + 8) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"PreDeinit",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x10) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"Deinit",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x14) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"Open",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x18) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"PreClose",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x1c) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"Close",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x20) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"Read",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x24) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"Write",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x28) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"Seek",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x2c) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"IOControl",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x30) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"PowerUp",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x34) = uVar4;
        uVar4 = FUN_c02c69f4(psVar6,L"PowerDown",*(undefined4 *)((int)_Dst + 0x40));
        *(undefined4 *)((int)_Dst + 0x38) = uVar4;
        if (((*(int *)((int)_Dst + 8) == 0) || (*(int *)((int)_Dst + 0x14) == 0)) ||
           ((*(int *)((int)_Dst + 0x5c) != 0 &&
            ((((*(int *)((int)_Dst + 0x18) == 0 || (*(int *)((int)_Dst + 0x20) == 0)) ||
              ((*(int *)((int)_Dst + 0x24) == 0 &&
               (((*(int *)((int)_Dst + 0x28) == 0 && (*(int *)((int)_Dst + 0x2c) == 0)) &&
                (*(int *)((int)_Dst + 0x30) == 0)))))) ||
             ((*(int *)((int)_Dst + 0x1c) != 0 && (*(int *)((int)_Dst + 0x10) == 0)))))))) {
          dwErrCode = 1;
        }
        if (*(int *)((int)_Dst + 0x18) == 0) {
          *(code **)((int)_Dst + 0x18) = FUN_c02c69a4;
        }
        if (*(int *)((int)_Dst + 0x20) == 0) {
          *(code **)((int)_Dst + 0x20) = FUN_c02c69a4;
        }
        if (*(int *)((int)_Dst + 0x30) == 0) {
          *(code **)((int)_Dst + 0x30) = FUN_c02c69a4;
        }
        if (*(int *)((int)_Dst + 0x24) == 0) {
          *(code **)((int)_Dst + 0x24) = FUN_c02c69cc;
        }
        if (*(int *)((int)_Dst + 0x28) == 0) {
          *(code **)((int)_Dst + 0x28) = FUN_c02c69cc;
        }
        if (*(int *)((int)_Dst + 0x2c) == 0) {
          *(code **)((int)_Dst + 0x2c) = FUN_c02c69cc;
        }
        goto LAB_c02c7508;
      }
      dwErrCode = 2;
    }
    else {
      *(undefined4 *)((int)_Dst + 0x40) = 0;
      iVar2 = FUN_c02cca90(param_9,psVar6,param_5,param_6);
      *(int *)((int)_Dst + 0x3c) = iVar2;
      if (iVar2 == 0) {
        dwErrCode = 2;
      }
      else {
        *(code **)((int)_Dst + 0xc) = FUN_c02cd834;
        *(code **)((int)_Dst + 0x10) = FUN_c02cd888;
        *(code **)((int)_Dst + 0x14) = FUN_c02ce278;
        *(code **)((int)_Dst + 0x18) = FUN_c02ccaac;
        *(code **)((int)_Dst + 0x1c) = FUN_c02ccad4;
        *(code **)((int)_Dst + 0x20) = FUN_c02cd8bc;
        *(code **)((int)_Dst + 0x24) = FUN_c02ccaf0;
        *(code **)((int)_Dst + 0x28) = FUN_c02ccb0c;
        *(code **)((int)_Dst + 0x2c) = FUN_c02ccb28;
        *(undefined4 *)((int)_Dst + 8) = 0;
        *(code **)((int)_Dst + 0x30) = FUN_c02ccb44;
        *(code **)((int)_Dst + 0x34) = FUN_c02cd914;
        *(code **)((int)_Dst + 0x38) = FUN_c02cd948;
      }
LAB_c02c7508:
      if (dwErrCode == 0) goto LAB_c02c752c;
    }
    FUN_c02c6e94(_Dst);
    _Dst = (HLOCAL)0x0;
  }
  SetLastError(dwErrCode);
LAB_c02c752c:
  FUN_c02d1074(local_30);
  return _Dst;
}



/* c02c7564 FUN_c02c7564 */

/* Boundary evidence: original MIPS .pdata c02c7564..c02c765f. Semantic name remains unreviewed. */

undefined4 FUN_c02c7564(LPCWSTR param_1)

{
  int iVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  HKEY local_30 [2];
  undefined4 local_28 [2];
  uint local_20;
  
  iVar1 = CeGetCallerTrust();
  if (((iVar1 != 2) && (param_1 != (LPCWSTR)0x0)) &&
     (LVar2 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,local_30), LVar2 == 0)) {
    uVar3 = 0x57;
    memset(local_28,0,0x14);
    local_28[0] = 0x14;
    iVar1 = CeFsIoControlW(0,0x9008c,local_30,4,local_28,0x14,0,0);
    if ((iVar1 != 0) && ((local_20 & 1) != 0)) {
      uVar3 = 0;
    }
    RegCloseKey(local_30[0]);
    return uVar3;
  }
  return 0;
}



/* c02c7660 FUN_c02c7660 */

/* Boundary evidence: original MIPS .pdata c02c7660..c02c789b. Semantic name remains unreviewed. */

int FUN_c02c7660(int *param_1,LPCWSTR param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = __GetUserKData(8);
  param_1[0x1a] = iVar1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  *param_1 = (int)&DAT_c02d22c0;
  param_1[1] = (int)DAT_c02d22c4;
  *DAT_c02d22c4 = (int)param_1;
  DAT_c02d22c4 = param_1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  iVar1 = FUN_c02c7564(param_2);
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((code *)param_1[2] == (code *)0x0) {
    if ((code *)param_1[3] == (code *)0x0) {
      param_1[0xf] = 0;
      goto LAB_c02c775c;
    }
    iVar1 = (*(code *)param_1[3])(param_1[0xf],param_2,param_4);
  }
  else {
    iVar1 = (*(code *)param_1[2])(param_2,param_4);
  }
  param_1[0xf] = iVar1;
LAB_c02c775c:
  iVar1 = 0;
  if (param_1[0xf] == 0) {
    iVar1 = 0x6e;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  *(int *)param_1[1] = *param_1;
  *(int *)(*param_1 + 4) = param_1[1];
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  param_1[0x1a] = 0;
  if (iVar1 == 0) {
    if ((param_3 & 1) == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      *param_1 = (int)&DAT_c02d22d0;
      param_1[1] = (int)DAT_c02d22d4;
      *DAT_c02d22d4 = (int)param_1;
      DAT_c02d22d4 = param_1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    }
    else {
      if ((code *)param_1[4] != (code *)0x0) {
        (*(code *)param_1[4])(param_1[0xf]);
      }
      (*(code *)param_1[5])(param_1[0xf]);
    }
  }
  return iVar1;
}



/* c02c789c FUN_c02c789c */

/* Boundary evidence: original MIPS .pdata c02c789c..c02c78d7. Semantic name remains unreviewed. */

undefined4 FUN_c02c789c(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x30) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x30),0);
  return 1;
}



/* c02c78d8 FUN_c02c78d8 */

/* Boundary evidence: original MIPS .pdata c02c78d8..c02c78e3. Semantic name remains unreviewed. */

undefined4 FUN_c02c78d8(void)

{
  return 1;
}



/* c02c78e4 FUN_c02c78e4 */

/* Boundary evidence: original MIPS .pdata c02c78e4..c02c791f. Semantic name remains unreviewed. */

undefined4 FUN_c02c78e4(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x30) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x30),0);
  return 1;
}



/* c02c7920 FUN_c02c7920 */

/* Boundary evidence: original MIPS .pdata c02c7920..c02c7c93. Semantic name remains unreviewed. */

undefined4 FUN_c02c7920(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint *param_4)

{
  bool bVar1;
  bool bVar2;
  LSTATUS LVar3;
  int iVar4;
  undefined4 uVar5;
  DWORD dwIndex;
  DWORD local_250;
  DWORD local_24c;
  HKEY local_248;
  uint local_244;
  wchar_t *local_240;
  HKEY local_23c;
  uint *local_238;
  DWORD local_234;
  WCHAR aWStack_230 [255];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_c02d2224;
  local_244 = 0x10000;
  bVar2 = false;
  local_238 = param_4;
  LVar3 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\RegisteredDevice",0,0,&local_23c);
  uVar5 = 1;
  if (LVar3 == 0) {
    dwIndex = 0;
    bVar1 = true;
    local_240 = L"Flags";
    do {
      local_250 = 0x100;
      LVar3 = RegEnumKeyExW(local_23c,dwIndex,aWStack_230,&local_250,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
      if (LVar3 == 0) {
        local_32 = 0;
        LVar3 = RegOpenKeyExW(local_23c,aWStack_230,0,0,&local_248);
        if (LVar3 == 0) {
          local_250 = 0x200;
          LVar3 = RegQueryValueExW(local_248,L"Dll",(LPDWORD)0x0,&local_24c,(LPBYTE)aWStack_230,
                                   &local_250);
          local_250 = local_250 >> 1;
          if (((LVar3 == 0) && (local_24c == 1)) &&
             (iVar4 = _wcsnicmp(param_3,aWStack_230,local_250), iVar4 == 0)) {
            local_250 = 0x200;
            LVar3 = RegQueryValueExW(local_248,L"Prefix",(LPDWORD)0x0,&local_24c,(LPBYTE)aWStack_230
                                     ,&local_250);
            local_250 = local_250 >> 1;
            if (((LVar3 == 0) && (local_24c == 1)) &&
               (iVar4 = _wcsnicmp(param_1,aWStack_230,local_250), iVar4 == 0)) {
              local_240 = (wchar_t *)0xffffffff;
              local_234 = 4;
              LVar3 = RegQueryValueExW(local_248,L"Index",(LPDWORD)0x0,&local_24c,(LPBYTE)&local_240
                                       ,&local_234);
              if ((((LVar3 == 0) && (local_24c == 4)) && (local_240 == param_2)) ||
                 ((!bVar1 && (LVar3 != 0)))) {
                bVar2 = true;
                local_250 = 4;
                LVar3 = RegQueryValueExW(local_248,L"Flags",(LPDWORD)0x0,&local_24c,
                                         (LPBYTE)&local_244,&local_250);
                if ((LVar3 != 0) || (local_24c != 4)) {
                  local_244 = 0x10000;
                }
              }
            }
          }
          RegCloseKey(local_248);
        }
        dwIndex = dwIndex + 1;
      }
      else {
        if (!bVar1) break;
        bVar1 = false;
        dwIndex = 0;
      }
    } while (!bVar2);
    RegCloseKey(local_23c);
    param_4 = local_238;
  }
  if (((local_244 & 0x10000) == 0) || (iVar4 = CeGetCallerTrust(), iVar4 == 2)) {
    if (param_4 != (uint *)0x0) {
      *param_4 = local_244;
    }
    FUN_c02d1074(local_30);
  }
  else {
    FUN_c02d1074(local_30);
    uVar5 = 0;
  }
  return uVar5;
}



/* c02c7c94 FUN_c02c7c94 */

/* Boundary evidence: original MIPS .pdata c02c7c94..c02c7f67. Semantic name remains unreviewed. */

int * FUN_c02c7c94(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,LPCWSTR param_4)

{
  int iVar1;
  DWORD dwErrCode;
  int *piVar2;
  int *hMem;
  uint local_bc [3];
  wchar_t awStack_b0 [3];
  short local_aa;
  wchar_t awStack_a8 [64];
  short local_28;
  uint local_24;
  
  local_24 = DAT_c02d2224;
  piVar2 = (int *)0x0;
  local_bc[1] = 0;
  hMem = (int *)0x0;
  dwErrCode = 0;
  local_bc[0] = 0;
  if ((param_1 == (wchar_t *)0x0) || (param_3 == (wchar_t *)0x0)) {
    dwErrCode = 0x57;
  }
  else if (param_2 < (wchar_t *)0xa) {
    local_aa = 0;
    local_28 = 0;
    wcsncpy(awStack_b0,param_1,4);
    wcsncpy(awStack_a8,param_3,0x41);
    if ((local_aa != 0) || (local_28 != 0)) {
      dwErrCode = 0x57;
      local_bc[2] = 0x57;
    }
    if ((dwErrCode == 0) &&
       (iVar1 = FUN_c02c7920(awStack_b0,param_2,awStack_a8,local_bc), iVar1 != 0)) {
      piVar2 = FUN_c02c6f50(awStack_b0,param_2,(uint)param_2,0xffffffff,awStack_a8,local_bc[0],
                            awStack_b0,L"",(wchar_t *)0x0,0);
      if (piVar2 == (int *)0x0) {
        dwErrCode = GetLastError();
      }
      else {
        *(ushort *)(piVar2 + 0x12) = *(ushort *)(piVar2 + 0x12) | 4;
        if ((piVar2[0x17] == 0) || (hMem = FUN_c02c6da4(awStack_b0,param_2,L""), hMem != (int *)0x0)
           ) {
          if ((piVar2[0x17] != 0) && (hMem == (int *)0x0)) goto LAB_c02c7ef4;
          dwErrCode = FUN_c02c7660(piVar2,param_4,0,0);
        }
        else {
          dwErrCode = 0x964;
        }
      }
    }
  }
  else {
    dwErrCode = 0x585;
  }
  if (hMem != (int *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    *(int *)hMem[1] = *hMem;
    *(int *)(*hMem + 4) = hMem[1];
    LocalFree(hMem);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  }
LAB_c02c7ef4:
  if (dwErrCode != 0) {
    if (piVar2 != (int *)0x0) {
      FUN_c02c6e94(piVar2);
      piVar2 = (int *)0x0;
    }
    SetLastError(dwErrCode);
  }
  FUN_c02d1074(local_24);
  return piVar2;
}



/* c02c7f68 FUN_c02c7f68 */

/* Boundary evidence: original MIPS .pdata c02c7f68..c02c7f73. Semantic name remains unreviewed. */

undefined4 FUN_c02c7f68(void)

{
  return 1;
}



/* c02c7f74 FUN_c02c7f74 */

/* Boundary evidence: original MIPS .pdata c02c7f74..c02c809f. Semantic name remains unreviewed. */

void FUN_c02c7f74(LPCWSTR param_1,DWORD param_2,undefined4 param_3,LPCWSTR param_4)

{
  LSTATUS LVar1;
  HANDLE hDevice;
  HKEY local_28 [2];
  undefined4 local_20;
  HKEY local_1c;
  
  local_28[0] = (HKEY)0x0;
  hDevice = (HANDLE)0xffffffff;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,param_4,0,0,local_28);
  if (LVar1 == 0) {
    hDevice = CreateFileW(param_1,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    if (hDevice != (HANDLE)0xffffffff) {
      local_1c = local_28[0];
      local_20 = param_3;
      DeviceIoControl(hDevice,param_2,&local_20,8,(LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    }
  }
  if (local_28[0] != (HKEY)0x0) {
    RegCloseKey(local_28[0]);
  }
  if (hDevice != (HANDLE)0xffffffff) {
    CloseHandle(hDevice);
  }
  return;
}



/* c02c80a0 FUN_c02c80a0 */

/* Boundary evidence: original MIPS .pdata c02c80a0..c02c81a3. Semantic name remains unreviewed. */

void FUN_c02c80a0(LPCWSTR param_1)

{
  LSTATUS LVar1;
  HKEY local_18 [2];
  
  LVar1 = RegDeleteKeyW((HKEY)0x80000002,param_1);
  if (LVar1 != 0) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,local_18);
    if (LVar1 == 0) {
      RegDeleteValueW(local_18[0],L"ClientInfo");
      RegDeleteValueW(local_18[0],L"Hnd");
      RegDeleteValueW(local_18[0],L"Name");
      RegDeleteValueW(local_18[0],L"Key");
      RegDeleteValueW(local_18[0],L"PnpId");
      RegDeleteValueW(local_18[0],L"Sckt");
      RegCloseKey(local_18[0]);
    }
  }
  return;
}



/* c02c81a4 FUN_c02c81a4 */

/* Boundary evidence: original MIPS .pdata c02c81a4..c02c851b. Semantic name remains unreviewed. */

LSTATUS FUN_c02c81a4(wchar_t *param_1,LPBYTE param_2)

{
  bool bVar1;
  LSTATUS LVar2;
  size_t sVar3;
  int iVar4;
  undefined3 extraout_var;
  wchar_t *_Str;
  wchar_t *_Str_00;
  LPBYTE lpData;
  uint *lpData_00;
  DWORD local_38;
  HKEY local_34;
  DWORD aDStack_30 [2];
  
  local_34 = (HKEY)0x0;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,&local_34);
  if (LVar2 != 0) {
    return LVar2;
  }
  local_38 = 0x80;
  LVar2 = RegQueryValueExW(local_34,L"Dll",(LPDWORD)0x0,aDStack_30,param_2,&local_38);
  if (LVar2 != 0) goto LAB_c02c84dc;
  lpData_00 = (uint *)(param_2 + 0x94);
  param_2[0x7e] = '\0';
  param_2[0x7f] = '\0';
  local_38 = 4;
  LVar2 = RegQueryValueExW(local_34,L"Flags",(LPDWORD)0x0,aDStack_30,(LPBYTE)lpData_00,&local_38);
  if (LVar2 != 0) {
    *lpData_00 = 0;
  }
  _Str = (wchar_t *)(param_2 + 0x80);
  local_38 = 8;
  LVar2 = RegQueryValueExW(local_34,L"Prefix",(LPDWORD)0x0,aDStack_30,(LPBYTE)_Str,&local_38);
  if (((LVar2 != 0) || (*(short *)(param_2 + 0x86) != 0)) ||
     ((sVar3 = wcslen(_Str), sVar3 != 3 && (sVar3 = wcslen(_Str), sVar3 != 0)))) {
    *_Str = L'\0';
  }
  local_38 = 8;
  _Str_00 = (wchar_t *)(param_2 + 0x88);
  param_2[0x86] = '\0';
  param_2[0x87] = '\0';
  LVar2 = RegQueryValueExW(local_34,L"BusPrefix",(LPDWORD)0x0,aDStack_30,(LPBYTE)_Str_00,&local_38);
  if (((LVar2 == 0) && (*(short *)(param_2 + 0x8e) == 0)) &&
     ((sVar3 = wcslen(_Str_00), sVar3 == 3 || (sVar3 = wcslen(_Str_00), sVar3 == 0)))) {
    if ((*_Str == L'\0') || (iVar4 = _wcsicmp(_Str,_Str_00), iVar4 == 0)) goto LAB_c02c838c;
LAB_c02c8380:
    LVar2 = 0x57;
  }
  else {
    *_Str_00 = L'\0';
LAB_c02c838c:
    lpData = param_2 + 0x90;
    param_2[0x8e] = '\0';
    param_2[0x8f] = '\0';
    local_38 = 4;
    LVar2 = RegQueryValueExW(local_34,L"Index",(LPDWORD)0x0,aDStack_30,lpData,&local_38);
    if (LVar2 != 0) {
      lpData[0] = 0xff;
      lpData[1] = 0xff;
      lpData[2] = 0xff;
      lpData[3] = 0xff;
    }
    local_38 = 4;
    LVar2 = RegQueryValueExW(local_34,L"Context",(LPDWORD)0x0,aDStack_30,param_2 + 0x98,&local_38);
    if (LVar2 == 0) {
      param_2[0x9c] = '\x01';
      param_2[0x9d] = '\0';
      param_2[0x9e] = '\0';
      param_2[0x9f] = '\0';
    }
    else {
      param_2[0x9c] = '\0';
      param_2[0x9d] = '\0';
      param_2[0x9e] = '\0';
      param_2[0x9f] = '\0';
    }
    param_2[0xa8] = '\0';
    param_2[0xa9] = '\0';
    param_2[0xaa] = '\0';
    param_2[0xab] = '\0';
    param_2[0xac] = '\0';
    param_2[0xad] = '\0';
    param_2[0xae] = '\0';
    param_2[0xaf] = '\0';
    if (*_Str != L'\0') {
      local_38 = 4;
      LVar2 = RegQueryValueExW(local_34,L"Ioctl",(LPDWORD)0x0,aDStack_30,param_2 + 0xa0,&local_38);
      if (LVar2 == 0) {
        param_2[0xa8] = '\x01';
        param_2[0xa9] = '\0';
        param_2[0xaa] = '\0';
        param_2[0xab] = '\0';
      }
    }
    local_38 = 4;
    LVar2 = RegQueryValueExW(local_34,L"BusIoctl",(LPDWORD)0x0,aDStack_30,param_2 + 0xa4,&local_38);
    if (LVar2 == 0) {
      param_2[0xac] = '\x01';
      param_2[0xad] = '\0';
      param_2[0xae] = '\0';
      param_2[0xaf] = '\0';
    }
    bVar1 = FUN_c02cb6b8(param_1);
    if ((CONCAT31(extraout_var,bVar1) != 0) &&
       (*lpData_00 = *lpData_00 | 0x10, *(int *)(param_2 + 0x9c) != 0)) {
      if (*(int *)(param_2 + 0x98) != 0) goto LAB_c02c8380;
      param_2[0x9c] = '\0';
      param_2[0x9d] = '\0';
      param_2[0x9e] = '\0';
      param_2[0x9f] = '\0';
    }
    LVar2 = 0;
  }
LAB_c02c84dc:
  RegCloseKey(local_34);
  return LVar2;
}



/* c02c851c FUN_c02c851c */

/* Boundary evidence: original MIPS .pdata c02c851c..c02c866b. Semantic name remains unreviewed. */

LSTATUS FUN_c02c851c(STRSAFE_LPWSTR param_1,size_t param_2,int *param_3,undefined4 *param_4)

{
  LONG LVar1;
  HRESULT HVar2;
  LSTATUS LVar3;
  HKEY local_30;
  DWORD local_2c;
  
  while( true ) {
    LVar1 = InterlockedIncrement(&DAT_c02d22b0);
    *param_3 = LVar1 + -1;
    if (LVar1 + -1 == -1) {
      LVar1 = InterlockedIncrement(&DAT_c02d22b0);
      *param_3 = LVar1 + -1;
    }
    HVar2 = StringCchPrintfW(param_1,param_2,L"%s\\%02u",L"Drivers\\Active",*param_3);
    if (HVar2 != 0) break;
    LVar3 = RegCreateKeyExW((HKEY)0x80000002,param_1,0,(LPWSTR)0x0,1,0,(LPSECURITY_ATTRIBUTES)0x0,
                            &local_30,&local_2c);
    if (LVar3 != 0) goto LAB_c02c8634;
    if (local_2c == 1) goto LAB_c02c863c;
    RegCloseKey(local_30);
  }
  LVar3 = 0x7a;
LAB_c02c8634:
  local_30 = (HKEY)0x0;
  *param_1 = L'\0';
LAB_c02c863c:
  *param_4 = local_30;
  return LVar3;
}



/* c02c866c FUN_c02c866c */

/* Boundary evidence: original MIPS .pdata c02c866c..c02c87eb. Semantic name remains unreviewed. */

LSTATUS FUN_c02c866c(HKEY param_1,wchar_t *param_2,int param_3,int param_4)

{
  LSTATUS LVar1;
  size_t sVar2;
  undefined4 *puVar3;
  
  if ((param_4 != 0) && (param_3 == 0)) {
    param_4 = 0;
  }
  do {
    LVar1 = 0;
    if (param_4 == 0) {
LAB_c02c877c:
      if (param_2 != (wchar_t *)0x0) {
        sVar2 = wcslen(param_2);
        LVar1 = RegSetValueExW(param_1,L"Key",0,1,(BYTE *)param_2,(sVar2 + 1) * 2);
        return LVar1;
      }
      return LVar1;
    }
    puVar3 = (undefined4 *)((param_4 + -1) * 0x10 + param_3);
    if (((LPCWSTR)*puVar3 == (LPCWSTR)0x0) || ((BYTE *)puVar3[1] == (BYTE *)0x0)) {
      LVar1 = 0xc;
      goto LAB_c02c877c;
    }
    LVar1 = RegSetValueExW(param_1,(LPCWSTR)*puVar3,0,puVar3[3],(BYTE *)puVar3[1],puVar3[2]);
    param_4 = param_4 + -1;
    if (LVar1 != 0) {
      return LVar1;
    }
  } while( true );
}



/* c02c87ec FUN_c02c87ec */

/* Boundary evidence: original MIPS .pdata c02c87ec..c02c87f7. Semantic name remains unreviewed. */

undefined4 FUN_c02c87ec(void)

{
  return 1;
}



/* c02c87f8 FUN_c02c87f8 */

/* Boundary evidence: original MIPS .pdata c02c87f8..c02c88f7. Semantic name remains unreviewed. */

undefined4 FUN_c02c87f8(HKEY param_1,LPBYTE param_2)

{
  int iVar1;
  LSTATUS LVar2;
  LPBYTE lpData;
  DWORD local_20;
  DWORD local_1c;
  
  iVar1 = CeGetCallerTrust();
  if (iVar1 == 2) {
    local_20 = 4;
    LVar2 = RegQueryValueExW(param_1,L"BusParent",(LPDWORD)0x0,&local_1c,param_2,&local_20);
    if ((LVar2 != 0) || (local_1c != 4)) {
      param_2[0] = '\0';
      param_2[1] = '\0';
      param_2[2] = '\0';
      param_2[3] = '\0';
    }
    local_20 = 0x208;
    lpData = param_2 + 4;
    LVar2 = RegQueryValueExW(param_1,L"BusName",(LPDWORD)0x0,&local_1c,lpData,&local_20);
    if ((LVar2 == 0) && (local_1c == 1)) {
      param_2[0x20a] = '\0';
      param_2[0x20b] = '\0';
    }
    else {
      lpData[0] = '\0';
      lpData[1] = '\0';
    }
  }
  else {
    param_2[0] = '\0';
    param_2[1] = '\0';
    param_2[2] = '\0';
    param_2[3] = '\0';
    param_2[4] = '\0';
    param_2[5] = '\0';
  }
  return 0;
}



/* c02c88f8 FUN_c02c88f8 */

/* Boundary evidence: original MIPS .pdata c02c88f8..c02c89a7. Semantic name remains unreviewed. */

void FUN_c02c88f8(HKEY param_1,int param_2)

{
  size_t sVar1;
  LSTATUS LVar2;
  int local_res4 [3];
  
  local_res4[0] = param_2;
  if (*(wchar_t **)(param_2 + 0x58) != (wchar_t *)0x0) {
    sVar1 = wcslen(*(wchar_t **)(param_2 + 0x58));
    LVar2 = RegSetValueExW(param_1,L"Name",0,1,*(BYTE **)(param_2 + 0x58),(sVar1 + 1) * 2);
    if (LVar2 != 0) {
      return;
    }
  }
  RegSetValueExW(param_1,L"Hnd",0,4,(BYTE *)local_res4,4);
  return;
}



/* c02c89a8 FUN_c02c89a8 */

/* Boundary evidence: original MIPS .pdata c02c89a8..c02c8df7. Semantic name remains unreviewed. */

int * FUN_c02c89a8(wchar_t *param_1,int param_2,int param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  DWORD DVar2;
  HKEY hKey;
  int *piVar3;
  uint uVar4;
  int *hMem;
  HKEY local_578;
  int local_574;
  WCHAR aWStack_570 [64];
  short local_4f0 [4];
  short asStack_4e8 [4];
  uint local_4e0;
  uint local_4dc;
  LPCWSTR local_4d8;
  int local_4d4;
  DWORD local_4d0;
  DWORD local_4cc;
  int local_4c8;
  int local_4c4;
  undefined4 local_4c0;
  wchar_t local_4bc [262];
  wchar_t awStack_2b0 [64];
  wchar_t local_230 [256];
  uint local_30;
  
  local_30 = DAT_c02d2224;
  local_578 = (HKEY)0x0;
  piVar3 = (int *)0x0;
  hMem = (int *)0x0;
  LVar1 = FUN_c02c81a4(param_1,(LPBYTE)aWStack_570);
  if (LVar1 != 0) {
    DVar2 = 0x64a;
LAB_c02c8a10:
    SetLastError(DVar2);
LAB_c02c8a20:
    FUN_c02d1074(local_30);
    return (int *)0x0;
  }
  if ((local_4dc & 4) != 0) {
    SetLastError(0);
    goto LAB_c02c8a20;
  }
  if (((local_4dc & 0x1000) != 0) && (1 < DAT_c02d2240)) {
    DVar2 = 0;
    goto LAB_c02c8a10;
  }
  DVar2 = FUN_c02c851c(local_230,0x100,&local_574,&local_578);
  hKey = local_578;
  if (((DVar2 != 0) || (DVar2 = FUN_c02c866c(local_578,param_1,param_2,param_3), DVar2 != 0)) ||
     (DVar2 = FUN_c02c87f8(hKey,(LPBYTE)&local_4c0), uVar4 = local_4e0, DVar2 != 0))
  goto LAB_c02c8bb0;
  if (local_4f0[0] == 0) {
    if (local_4bc[0] != L'\0') {
LAB_c02c8b00:
      hMem = FUN_c02c6da4(local_4f0,local_4e0,local_4bc);
      goto LAB_c02c8ba0;
    }
  }
  else {
    if (local_4e0 != 0xffffffff) goto LAB_c02c8b00;
    SetLastError(0);
    local_4e0 = 1;
    while (hMem = FUN_c02c6da4(local_4f0,local_4e0,local_4bc), hMem == (int *)0x0) {
      DVar2 = GetLastError();
      if ((DVar2 == 0xe) || (local_4e0 = local_4e0 + 1, 0xfffe < local_4e0)) goto LAB_c02c8ba0;
    }
    uVar4 = 0;
    if (local_4e0 != 10) {
      uVar4 = local_4e0;
    }
LAB_c02c8ba0:
    if (hMem == (int *)0x0) {
      DVar2 = 0x964;
      goto LAB_c02c8bb0;
    }
  }
  piVar3 = FUN_c02c6f50(local_4f0,local_4e0,uVar4,local_574,aWStack_570,local_4dc,asStack_4e8,
                        local_4bc,param_1,local_4c0);
  if (piVar3 == (int *)0x0) {
    DVar2 = GetLastError();
  }
  else {
    DVar2 = FUN_c02c88f8(hKey,(int)piVar3);
    if (DVar2 == 0) {
      RegCloseKey(hKey);
      hKey = (HKEY)0x0;
      if (local_4d4 == 0) {
        local_4d8 = local_230;
      }
      DVar2 = FUN_c02c7660(piVar3,local_4d8,local_4dc,param_4);
    }
  }
LAB_c02c8bb0:
  if (hKey != (HKEY)0x0) {
    RegCloseKey(hKey);
  }
  if (hMem != (int *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    *(int *)hMem[1] = *hMem;
    *(int *)(*hMem + 4) = hMem[1];
    LocalFree(hMem);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  }
  if (DVar2 == 0) {
    if ((local_4dc & 1) == 0) {
      FUN_c02ca9f0((int)piVar3);
      if (local_4c8 != 0) {
        StringCchPrintfW(awStack_2b0,0x40,L"$device\\%s",piVar3[0x17]);
        FUN_c02c7f74(awStack_2b0,local_4d0,piVar3,param_1);
      }
      if ((local_4c4 != 0) && (local_4bc[0] != L'\0')) {
        StringCchPrintfW(awStack_2b0,0x40,L"$bus\\%s",local_4bc);
        FUN_c02c7f74(awStack_2b0,local_4cc,piVar3,param_1);
      }
    }
    else {
      FUN_c02c6e94(piVar3);
      FUN_c02c80a0(local_230);
      SetLastError(0);
      piVar3 = (int *)0x0;
    }
  }
  else {
    if (piVar3 != (int *)0x0) {
      FUN_c02c6e94(piVar3);
      piVar3 = (int *)0x0;
    }
    if (local_230[0] != L'\0') {
      FUN_c02c80a0(local_230);
    }
    SetLastError(DVar2);
  }
  FUN_c02d1074(local_30);
  return piVar3;
}



/* c02c8df8 FUN_c02c8df8 */

/* Boundary evidence: original MIPS .pdata c02c8df8..c02c907b. Semantic name remains unreviewed. */

int FUN_c02c8df8(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (uint *)0x0)) {
    return 0x57;
  }
  if (*param_2 < 0x630) {
    iVar3 = 0x57;
  }
  if (iVar3 != 0) {
    return iVar3;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  iVar1 = FUN_c02c6c48(param_1);
  iVar3 = 0;
  if (iVar1 == 0) {
    iVar1 = __GetUserKData(8);
    puVar2 = DAT_c02d22c0;
    if ((undefined4 **)DAT_c02d22c0 != &DAT_c02d22c0) {
      do {
        if ((puVar2 == param_1) && (puVar2[0x1a] == iVar1)) break;
        puVar2 = (undefined4 *)*puVar2;
      } while ((undefined4 **)puVar2 != &DAT_c02d22c0);
      if ((undefined4 **)puVar2 != &DAT_c02d22c0) goto LAB_c02c8ee8;
    }
    iVar3 = 0x490;
  }
LAB_c02c8ee8:
  if (iVar3 == 0) {
    param_2[1] = (uint)param_1;
    puVar2 = (undefined4 *)param_1[0x14];
    param_2[2] = (uint)puVar2;
    if ((puVar2 != (undefined4 *)0x0) && (iVar3 = FUN_c02c6c48(puVar2), iVar3 == 0)) {
      param_2[2] = 0;
    }
    if ((STRSAFE_LPCWSTR)param_1[0x16] == (STRSAFE_LPCWSTR)0x0) {
      *(undefined2 *)(param_2 + 3) = 0;
    }
    else {
      StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 3),6,(STRSAFE_LPCWSTR)param_1[0x16]);
    }
    if (param_1[0x17] == 0) {
      *(undefined2 *)(param_2 + 0x88) = 0;
    }
    else {
      StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0x88),0x104,L"$device\\");
      StringCchCatW((STRSAFE_LPWSTR)(param_2 + 0x88),0x104,(STRSAFE_LPCWSTR)param_1[0x17]);
    }
    if (param_1[0x18] == 0) {
      *(undefined2 *)(param_2 + 0x10a) = 0;
    }
    else {
      StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0x10a),0x104,L"$bus\\");
      StringCchCatW((STRSAFE_LPWSTR)(param_2 + 0x10a),0x104,(STRSAFE_LPCWSTR)param_1[0x18]);
    }
    if ((*(ushort *)(param_1 + 0x12) & 4) == 0) {
      wcsncpy((wchar_t *)(param_2 + 6),(wchar_t *)param_1[0x19],0x103);
      *(undefined2 *)((int)param_2 + 0x21e) = 0;
    }
    else {
      *(undefined2 *)(param_2 + 6) = 0;
    }
    *param_2 = 0x630;
    iVar3 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  return iVar3;
}



/* c02c907c FUN_c02c907c */

/* Boundary evidence: original MIPS .pdata c02c907c..c02c9087. Semantic name remains unreviewed. */

undefined4 FUN_c02c907c(void)

{
  return 1;
}



/* c02c9088 FUN_c02c9088 */

/* Boundary evidence: original MIPS .pdata c02c9088..c02c9093. Semantic name remains unreviewed. */

undefined4 FUN_c02c9088(void)

{
  return 1;
}



/* c02c9094 FUN_c02c9094 */

/* Boundary evidence: original MIPS .pdata c02c9094..c02c92a7. Semantic name remains unreviewed. */

void FUN_c02c9094(wchar_t *param_1)

{
  LSTATUS LVar1;
  size_t sVar2;
  int iVar3;
  HKEY local_450;
  DWORD local_44c;
  DWORD local_448 [2];
  wchar_t *local_440;
  wchar_t *local_43c;
  DWORD local_438;
  undefined4 local_434;
  wchar_t awStack_430 [255];
  undefined2 local_232;
  wchar_t awStack_230 [255];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_c02d2224;
  iVar3 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers",0,0,&local_450);
  if (LVar1 != 0) goto LAB_c02c9274;
  local_44c = 0x200;
  LVar1 = RegQueryValueExW(local_450,L"RootKey",(LPDWORD)0x0,local_448,(LPBYTE)awStack_430,
                           &local_44c);
  local_232 = 0;
  if (LVar1 != 0) {
    wcscpy(awStack_430,L"Drivers");
  }
  RegCloseKey(local_450);
  if (param_1 == (wchar_t *)0x0) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,awStack_430,0,0,&local_450);
    if (LVar1 == 0) {
      local_44c = 0x200;
      LVar1 = RegQueryValueExW(local_450,L"BusName",(LPDWORD)0x0,local_448,(LPBYTE)awStack_230,
                               &local_44c);
      if ((LVar1 == 0) && (local_448[0] == 1)) {
        local_43c = awStack_230;
        iVar3 = 1;
        local_32 = 0;
        local_440 = L"BusName";
        local_434 = 1;
        local_438 = local_44c;
      }
      RegCloseKey(local_450);
      if (iVar3 != 0) goto LAB_c02c924c;
    }
    ActivateDevice(awStack_430,0);
  }
  else {
    local_440 = L"BusName";
    local_434 = 1;
    local_43c = param_1;
    sVar2 = wcslen(param_1);
    local_438 = (sVar2 + 1) * 2;
    iVar3 = 1;
LAB_c02c924c:
    ActivateDeviceEx(awStack_430,&local_440,iVar3,0);
  }
LAB_c02c9274:
  FUN_c02d1074(local_30);
  return;
}



/* c02c92a8 FUN_c02c92a8 */

/* Boundary evidence: original MIPS .pdata c02c92a8..c02c92f7. Semantic name remains unreviewed. */

void FUN_c02c92a8(void)

{
  RegDeleteKeyW((HKEY)0x80000002,L"Drivers\\Active");
  DAT_c02d22d8 = 0;
  DAT_c02d22b0 = 1;
  FUN_c02c9094(L"BuiltInPhase1");
  return;
}



/* c02c92f8 FUN_c02c92f8 */

void FUN_c02c92f8(void)

{
  if (DAT_c02d22d8 == 0) {
    DAT_c02d22d8 = 1;
  }
  return;
}



/* c02c9318 FUN_c02c9318 */

/* Boundary evidence: original MIPS .pdata c02c9318..c02c95ef. Semantic name remains unreviewed. */

int FUN_c02c9318(int *param_1)

{
  ushort uVar1;
  int iVar2;
  HRESULT HVar3;
  DWORD dwErrCode;
  int iVar4;
  wchar_t awStack_220 [256];
  uint local_20;
  
  local_20 = DAT_c02d2224;
  dwErrCode = 0x490;
  iVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  iVar2 = FUN_c02c6c48(param_1);
  if (iVar2 != 0) {
    if ((param_1[0x1b] & 0x20U) != 0) {
LAB_c02c9394:
      dwErrCode = 5;
      goto LAB_c02c9568;
    }
    uVar1 = *(ushort *)(param_1 + 0x12);
    if (((uVar1 & 4) != 0) || ((uVar1 & 1) != 0)) {
      if (((uVar1 & 8) != 0) && (iVar2 = CeGetCallerTrust(), iVar2 != 2)) goto LAB_c02c9394;
      dwErrCode = 0;
    }
  }
  if (dwErrCode == 0) {
    FUN_c02c976c(param_1);
    *(int *)param_1[1] = *param_1;
    *(int *)(*param_1 + 4) = param_1[1];
    *(ushort *)(param_1 + 0x12) = *(ushort *)(param_1 + 0x12) | 0x8000;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    if ((code *)param_1[4] == (code *)0x0) {
      (*(code *)param_1[5])(param_1[0xf]);
    }
    else {
      (*(code *)param_1[4])();
    }
    if (param_1[0x13] == 0) {
      if (param_1[4] != 0) {
        (*(code *)param_1[5])(param_1[0xf]);
      }
      if (param_1[0x11] != -1) {
        HVar3 = StringCchPrintfW(awStack_220,0x100,L"%s\\%02u",L"Drivers\\Active",param_1[0x11]);
        if (-1 < HVar3) {
          FUN_c02c80a0(awStack_220);
        }
      }
      FUN_c02c6e94(param_1);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      *param_1 = (int)&DAT_c02d22f0;
      param_1[1] = (int)DAT_c02d22f4;
      *DAT_c02d22f4 = (int)param_1;
      DAT_c02d22f4 = param_1;
      EventModify(DAT_c02d22c8,3);
    }
    iVar4 = 1;
  }
LAB_c02c9568:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (iVar4 == 0) {
    SetLastError(dwErrCode);
  }
  FUN_c02d1074(local_20);
  return iVar4;
}



/* c02c95f0 FUN_c02c95f0 */

/* Boundary evidence: original MIPS .pdata c02c95f0..c02c95fb. Semantic name remains unreviewed. */

undefined4 FUN_c02c95f0(void)

{
  return 1;
}



/* c02c95fc FUN_c02c95fc */

/* Boundary evidence: original MIPS .pdata c02c95fc..c02c9637. Semantic name remains unreviewed. */

undefined4 FUN_c02c95fc(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x228) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x228),0);
  return 1;
}



/* c02c9638 FUN_c02c9638 */

/* Boundary evidence: original MIPS .pdata c02c9638..c02c9673. Semantic name remains unreviewed. */

undefined4 FUN_c02c9638(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x228) = param_1;
  ReportFault(*(undefined4 *)(in_v0 + -0x228),0);
  return 1;
}



/* c02c9674 FUN_c02c9674 */

/* Boundary evidence: original MIPS .pdata c02c9674..c02c976b. Semantic name remains unreviewed. */

bool FUN_c02c9674(int *param_1)

{
  ushort uVar1;
  int iVar2;
  DWORD dwErrCode;
  
  dwErrCode = 0x490;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  iVar2 = FUN_c02c6c48(param_1);
  if (iVar2 == 0) goto LAB_c02c9718;
  if ((param_1[0x1b] & 0x20U) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x12);
    if (((uVar1 & 4) != 0) || ((uVar1 & 1) != 0)) goto LAB_c02c9718;
    if (((uVar1 & 8) == 0) || (iVar2 = CeGetCallerTrust(), iVar2 == 2)) {
      *(ushort *)(param_1 + 0x12) = *(ushort *)(param_1 + 0x12) | 1;
      dwErrCode = 0;
      goto LAB_c02c9718;
    }
  }
  dwErrCode = 5;
LAB_c02c9718:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (dwErrCode == 0) {
    FUN_c02caf1c((int)param_1);
    FUN_c02c9318(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c02c976c FUN_c02c976c */

void FUN_c02c976c(undefined4 *param_1)

{
  int iVar1;
  
  for (iVar1 = DAT_c02d22a8; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
    if (*(undefined4 **)(iVar1 + 4) == param_1) {
      *(undefined4 *)(iVar1 + 4) = *param_1;
    }
  }
  return;
}



/* c02c97a4 FUN_c02c97a4 */

/* Boundary evidence: original MIPS .pdata c02c97a4..c02c9987. Semantic name remains unreviewed. */

int FUN_c02c97a4(int *param_1,uint *param_2)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  int *piVar4;
  wchar_t *_Str;
  
  piVar4 = (int *)param_1[1];
  if (piVar4 == (int *)0x0) {
    piVar4 = DAT_c02d22d0;
  }
  if ((int **)piVar4 != &DAT_c02d22d0) {
    do {
      iVar3 = *param_1;
      if (iVar3 == 1) {
        _Str = (wchar_t *)piVar4[0x17];
LAB_c02c9820:
        if (_Str == (wchar_t *)0x0) {
          if ((short)param_1[3] == 0) break;
        }
        else {
          sVar1 = wcslen(_Str);
          sVar2 = wcslen((wchar_t *)(param_1 + 3));
          iVar3 = MatchesWildcardMask(sVar2,param_1 + 3,sVar1,_Str);
LAB_c02c98e8:
          if (iVar3 != 0) break;
        }
      }
      else {
        if (iVar3 == 2) {
          _Str = (wchar_t *)piVar4[0x18];
          goto LAB_c02c9820;
        }
        if (iVar3 == 0) {
          _Str = (wchar_t *)piVar4[0x16];
          goto LAB_c02c9820;
        }
        if (iVar3 != 4) {
          if (iVar3 != 3) goto LAB_c02c98f0;
          iVar3 = FUN_c02ca6e0((int)piVar4,param_1 + 3);
          goto LAB_c02c98e8;
        }
        if (piVar4[0x14] == param_1[3]) break;
      }
LAB_c02c98f0:
      piVar4 = (int *)*piVar4;
    } while ((int **)piVar4 != &DAT_c02d22d0);
    if ((int **)piVar4 != &DAT_c02d22d0) {
      iVar3 = FUN_c02c8df8(piVar4,param_2);
      if (iVar3 != 0) {
        return iVar3;
      }
      param_1[1] = *piVar4;
      return 0;
    }
  }
  return 0x12;
}



/* c02c9988 FUN_c02c9988 */

/* Boundary evidence: original MIPS .pdata c02c9988..c02c9993. Semantic name remains unreviewed. */

undefined4 FUN_c02c9988(void)

{
  return 1;
}



/* c02c9994 FUN_c02c9994 */

/* Boundary evidence: original MIPS .pdata c02c9994..c02c9a8f. Semantic name remains unreviewed. */

int FUN_c02c9994(int param_1,HMODULE param_2,int param_3,uint param_4,undefined4 param_5,int param_6
                ,int param_7)

{
  wchar_t *pwVar1;
  DWORD dwErrCode;
  int iVar2;
  
  if (param_3 != 0) {
    iVar2 = 2;
    if ((((param_1 == 2) || (param_1 == 3)) && (param_6 == 0)) && ((param_7 == 3 || (param_7 == 4)))
       ) {
      pwVar1 = wcschr((wchar_t *)(param_3 + 2),L'\\');
      if (pwVar1 == (wchar_t *)0x0) {
        if (param_1 != 3) {
          iVar2 = 1;
        }
        iVar2 = FUN_c02c3db8((wchar_t *)(param_3 + 2),iVar2,param_4,param_5,param_2);
        return iVar2;
      }
      dwErrCode = 0xa1;
      goto LAB_c02c9a54;
    }
  }
  dwErrCode = 0x57;
LAB_c02c9a54:
  SetLastError(dwErrCode);
  return -1;
}



/* c02c9a90 FUN_c02c9a90 */

/* Boundary evidence: original MIPS .pdata c02c9a90..c02c9bb3. Semantic name remains unreviewed. */

undefined4 FUN_c02c9a90(int *param_1,uint *param_2)

{
  int *piVar1;
  DWORD dwErrCode;
  
  if (param_2 == (uint *)0x0) {
    dwErrCode = 0x57;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    for (piVar1 = DAT_c02d22a8; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      if (piVar1 == param_1) goto LAB_c02c9b14;
    }
    if (param_1 == (int *)0x0) {
LAB_c02c9b14:
      dwErrCode = FUN_c02c97a4(param_1,param_2);
    }
    else {
      dwErrCode = 6;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  if (dwErrCode == 0) {
    return 1;
  }
  return 0;
}



/* c02c9bb4 FUN_c02c9bb4 */

/* Boundary evidence: original MIPS .pdata c02c9bb4..c02c9bbf. Semantic name remains unreviewed. */

undefined4 FUN_c02c9bb4(void)

{
  return 1;
}



/* c02c9bc0 FUN_c02c9bc0 */

/* Boundary evidence: original MIPS .pdata c02c9bc0..c02c9c83. Semantic name remains unreviewed. */

bool FUN_c02c9bc0(HLOCAL param_1)

{
  HLOCAL pvVar1;
  HLOCAL pvVar2;
  DWORD dwErrCode;
  
  dwErrCode = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  pvVar1 = (HLOCAL)0x0;
  for (pvVar2 = DAT_c02d22a8; pvVar2 != (HLOCAL)0x0; pvVar2 = *(HLOCAL *)((int)pvVar2 + 8)) {
    if (pvVar2 == param_1) goto LAB_c02c9c24;
    pvVar1 = pvVar2;
  }
  if (param_1 == (HLOCAL)0x0) {
LAB_c02c9c24:
    pvVar2 = *(HLOCAL *)((int)param_1 + 8);
    if (pvVar1 != (HLOCAL)0x0) {
      *(HLOCAL *)((int)pvVar1 + 8) = *(HLOCAL *)((int)param_1 + 8);
      pvVar2 = DAT_c02d22a8;
    }
  }
  else {
    dwErrCode = 6;
    pvVar2 = DAT_c02d22a8;
  }
  DAT_c02d22a8 = pvVar2;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  else {
    LocalFree(param_1);
  }
  return dwErrCode == 0;
}



/* c02c9c8c FUN_c02c9c8c */

/* Boundary evidence: original MIPS .pdata c02c9c8c..c02c9f07. Semantic name remains unreviewed. */

int FUN_c02c9c8c(void)

{
  wchar_t *pwVar1;
  wchar_t **ppwVar2;
  uint uVar3;
  int iVar4;
  wchar_t *local_40;
  undefined4 local_3c;
  wchar_t *local_38 [4];
  
  iVar4 = 1;
  DAT_c02d22ac = CreateAPISet(&DAT_c02c19cc,0x18,&PTR_LAB_c02c1850,&DAT_c02c18b0);
  RegisterAPISet(DAT_c02d22ac,0x80000010);
  DAT_c02d22a4 = CreateAPISet(&DAT_c02c19c4,0xc,&PTR_FUN_c02c1318,&DAT_c02c1348);
  RegisterDirectMethods(DAT_c02d22a4,&PTR_FUN_c02c12e8);
  RegisterAPISet(DAT_c02d22a4,0x80000007);
  DAT_c02d22a0 = CreateAPISet(&DAT_c02c19bc,3,&PTR_FUN_c02c197c,&DAT_c02c1988);
  RegisterDirectMethods(DAT_c02d22a0,&PTR_FUN_c02c1970);
  RegisterAPISet(DAT_c02d22a0,0x80000008);
  DAT_c02d22a8 = 0;
  if (DAT_c02d22ac != 0) {
    if ((DAT_c02d22a4 != 0) && (DAT_c02d22a0 != 0)) {
      local_3c = 2;
      local_38[2] = (wchar_t *)0x3;
      local_40 = L"$device";
      uVar3 = 0;
      local_38[0] = (wchar_t *)0xffffffff;
      ppwVar2 = &local_40;
      local_38[1] = L"$bus";
      local_38[3] = (wchar_t *)0xffffffff;
      do {
        if (1 < uVar3) break;
        pwVar1 = (wchar_t *)RegisterAFSName(*ppwVar2);
        ppwVar2[2] = pwVar1;
        if (pwVar1 == (wchar_t *)0xffffffff) {
          iVar4 = 0;
        }
        else {
          iVar4 = RegisterAFSEx(pwVar1,DAT_c02d22ac,ppwVar2[1],4,1);
          if (iVar4 == 0) {
            DeregisterAFSName(pwVar1);
          }
        }
        uVar3 = uVar3 + 1;
        ppwVar2 = ppwVar2 + 3;
      } while (iVar4 != 0);
      if (iVar4 != 0) {
        return iVar4;
      }
      if ((int)uVar3 < 1) {
        return 0;
      }
      ppwVar2 = local_38 + uVar3 * 3;
      do {
        ppwVar2 = ppwVar2 + -3;
        pwVar1 = *ppwVar2;
        uVar3 = uVar3 - 1;
        DeregisterAFS(pwVar1);
        DeregisterAFSName(pwVar1);
      } while (0 < (int)uVar3);
      return 0;
    }
    CloseHandle((HANDLE)DAT_c02d22ac);
  }
  if (DAT_c02d22a4 != 0) {
    CloseHandle((HANDLE)DAT_c02d22a4);
  }
  if (DAT_c02d22a0 != 0) {
    CloseHandle((HANDLE)DAT_c02d22a0);
  }
  return 0;
}



/* c02c9f08 FUN_c02c9f08 */

/* Boundary evidence: original MIPS .pdata c02c9f08..c02ca233. Semantic name remains unreviewed. */

int FUN_c02c9f08(int param_1,undefined4 param_2,short *param_3,uint *param_4,int param_5)

{
  bool bVar1;
  wchar_t *pwVar2;
  int iVar3;
  undefined3 extraout_var;
  long lVar4;
  int *hMem;
  DWORD dwErrCode;
  int iVar5;
  wchar_t *_Str;
  size_t _MaxCount;
  wchar_t *local_38;
  DWORD local_34;
  int *local_30;
  undefined4 local_2c;
  
  hMem = (int *)0x0;
  dwErrCode = 0x57;
  iVar5 = -1;
  local_2c = 0xffffffff;
  if ((((param_4 != (uint *)0x0) && (param_3 != (short *)0x0)) && (*param_3 == 0x5c)) &&
     ((param_1 == 2 && (param_5 == 0x630)))) {
    _Str = param_3 + 1;
    hMem = LocalAlloc(0,0x214);
    hMem[1] = 0;
    local_30 = hMem;
    pwVar2 = wcschr(_Str,L'+');
    if (pwVar2 != (wchar_t *)0x0) {
      pwVar2 = pwVar2 + 1;
      _MaxCount = ((int)pwVar2 - (int)_Str >> 1) - 1;
      iVar3 = wcsncmp(_Str,L"byLegacyName",_MaxCount);
      if (iVar3 == 0) {
        *hMem = 0;
LAB_c02ca054:
        wcsncpy((wchar_t *)(hMem + 3),pwVar2,0x104);
        *(undefined2 *)((int)hMem + 0x212) = 0;
      }
      else {
        iVar3 = wcsncmp(_Str,L"byDeviceName",_MaxCount);
        if (iVar3 == 0) {
          iVar5 = 1;
LAB_c02ca050:
          *hMem = iVar5;
          goto LAB_c02ca054;
        }
        iVar3 = wcsncmp(_Str,L"byBusName",_MaxCount);
        if (iVar3 == 0) {
          iVar5 = 2;
          goto LAB_c02ca050;
        }
        iVar3 = wcsncmp(_Str,L"byInterfaceClass",_MaxCount);
        if (iVar3 != 0) {
          iVar3 = wcsncmp(_Str,L"byParent",_MaxCount);
          if (iVar3 == 0) {
            *hMem = 4;
            lVar4 = wcstol(pwVar2,&local_38,0x10);
            hMem[3] = lVar4;
            if (*local_38 == L'\0') goto LAB_c02ca188;
          }
          goto LAB_c02ca0b4;
        }
        *hMem = 3;
        iVar3 = FUN_c02ca5d4(pwVar2,(int)(hMem + 3));
        if (iVar3 == 0) goto LAB_c02ca0b4;
      }
LAB_c02ca188:
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      hMem[2] = (int)DAT_c02d22a8;
      DAT_c02d22a8 = hMem;
      dwErrCode = FUN_c02c97a4(hMem,param_4);
      local_34 = dwErrCode;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      if (dwErrCode != 0) goto LAB_c02ca0bc;
      iVar5 = CreateAPIHandle(DAT_c02d22a0,hMem);
      if (iVar5 == 0) {
        dwErrCode = 0xe;
      }
    }
  }
LAB_c02ca0b4:
  if (dwErrCode == 0) {
    return iVar5;
  }
LAB_c02ca0bc:
  if ((hMem != (int *)0x0) && (bVar1 = FUN_c02c9bc0(hMem), CONCAT31(extraout_var,bVar1) == 0)) {
    LocalFree(hMem);
  }
  SetLastError(dwErrCode);
  return -1;
}



/* c02ca234 FUN_c02ca234 */

/* Boundary evidence: original MIPS .pdata c02ca234..c02ca23f. Semantic name remains unreviewed. */

undefined4 FUN_c02ca234(void)

{
  return 1;
}



/* c02ca240 FUN_c02ca240 */

/* Boundary evidence: original MIPS .pdata c02ca240..c02ca527. Semantic name remains unreviewed. */

void FUN_c02ca240(int *param_1)

{
  bool bVar1;
  LSTATUS LVar2;
  HMODULE hLibModule;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  SIZE_T *hMem;
  size_t sVar6;
  wchar_t *_Dest;
  undefined4 uVar7;
  wchar_t *_Str;
  int *hMem_00;
  SIZE_T uBytes;
  wchar_t *_Source;
  wchar_t *local_38;
  HKEY local_34;
  wchar_t *local_30;
  undefined4 local_2c;
  
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers",0,0,&local_34);
  if (LVar2 == 0) {
    local_30 = (wchar_t *)0x4;
    LVar2 = RegQueryValueExW(local_34,L"NotifyPriority256",(LPDWORD)0x0,(LPDWORD)&local_38,
                             (LPBYTE)&local_2c,(LPDWORD)&local_30);
    if ((LVar2 == 0) && (local_38 == (wchar_t *)0x4)) {
      CeSetThreadPriority(0x41,local_2c);
    }
    RegCloseKey(local_34);
  }
  hLibModule = LoadLibraryW(L"COREDLL.DLL");
  if (hLibModule != (HMODULE)0x0) {
    DAT_c02d224c = (code *)GetProcAddressW(hLibModule,L"SendNotifyMessageW");
    FreeLibrary(hLibModule);
  }
  _Source = L" ";
  _Str = L"/ADD";
  local_30 = L" ";
  local_38 = L"/ADD";
  do {
    do {
      DVar3 = WaitForSingleObject((HANDLE)param_1[7],0xffffffff);
    } while (DVar3 != 0);
    bVar1 = false;
    do {
      hMem_00 = (int *)0x0;
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
      if ((int *)*param_1 != param_1) {
        hMem_00 = (int *)param_1[1];
        *(int *)hMem_00[1] = *hMem_00;
        *(int *)(*hMem_00 + 4) = hMem_00[1];
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
      if (hMem_00 == (int *)0x0) {
        bVar1 = true;
      }
      else {
        if ((DAT_c02d224c != (code *)0x0) && (iVar4 = WaitForAPIReady(0x51,0), iVar4 == 0)) {
          iVar4 = hMem_00[10];
          sVar5 = wcslen((wchar_t *)(hMem_00 + 2));
          uBytes = (sVar5 + 7) * 2;
          hMem = LocalAlloc(0x40,uBytes);
          _Str = local_38;
          _Source = local_30;
          if (hMem != (SIZE_T *)0x0) {
            hMem[1] = 3;
            hMem[2] = 0;
            wcscpy((wchar_t *)(hMem + 3),(wchar_t *)(hMem_00 + 2));
            *hMem = uBytes;
            uVar7 = 0x8000;
            if (iVar4 == 0) {
              uVar7 = 0x8004;
            }
            (*DAT_c02d224c)(0xffff,0x219,uVar7,hMem);
            LocalFree(hMem);
            _Str = local_38;
            _Source = local_30;
          }
        }
        if (hMem_00[10] == 0) {
          _Str = L"/REMOVE";
        }
        sVar5 = wcslen(_Str);
        sVar6 = wcslen((wchar_t *)(hMem_00 + 2));
        _Dest = LocalAlloc(0x40,(sVar6 + sVar5 + 2) * 2);
        if (_Dest != (wchar_t *)0x0) {
          wcscpy(_Dest,_Str);
          wcscat(_Dest,_Source);
          wcscat(_Dest,(wchar_t *)(hMem_00 + 2));
          CeEventHasOccurred(7,_Dest);
          LocalFree(_Dest);
        }
        LocalFree(hMem_00);
        _Str = local_38;
      }
    } while (!bVar1);
  } while( true );
}



/* c02ca528 FUN_c02ca528 */

/* Boundary evidence: original MIPS .pdata c02ca528..c02ca5d3. Semantic name remains unreviewed. */

void FUN_c02ca528(void *param_1,int param_2)

{
  int *piVar1;
  
  if ((DAT_c02d229c != 0) && (piVar1 = LocalAlloc(0x40,0x2c), piVar1 != (int *)0x0)) {
    piVar1[10] = param_2;
    memcpy(piVar1 + 2,param_1,0x20);
    *(undefined2 *)((int)piVar1 + 0x26) = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2288);
    *piVar1 = (int)DAT_c02d2280;
    piVar1[1] = (int)&DAT_c02d2280;
    DAT_c02d2280[1] = (int)piVar1;
    DAT_c02d2280 = piVar1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2288);
    EventModify(DAT_c02d229c,3);
  }
  return;
}



/* c02ca5d4 FUN_c02ca5d4 */

/* Boundary evidence: original MIPS .pdata c02ca5d4..c02ca6df. Semantic name remains unreviewed. */

undefined4 FUN_c02ca5d4(wchar_t *param_1,int param_2)

{
  size_t sVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_a0;
  undefined1 auStack_9c [4];
  undefined1 auStack_98 [4];
  undefined1 auStack_94 [4];
  undefined1 auStack_90 [4];
  undefined1 auStack_8c [4];
  undefined1 auStack_88 [4];
  undefined1 auStack_84 [4];
  wchar_t awStack_80 [52];
  uint local_18;
  
  local_18 = DAT_c02d2224;
  memcpy(awStack_80,L"{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",0x68);
  sVar1 = wcslen(param_1);
  if ((sVar1 == 0x26) &&
     (iVar2 = swscanf(param_1,awStack_80,param_2,param_2 + 4,param_2 + 6,&local_a0,auStack_9c,
                      auStack_98,auStack_94,auStack_90,auStack_8c,auStack_88,auStack_84),
     iVar2 == 0xb)) {
    uVar4 = 0;
    puVar5 = &local_a0;
    do {
      puVar3 = (undefined1 *)(param_2 + 8 + uVar4);
      uVar4 = uVar4 + 1;
      *puVar3 = (char)*puVar5;
      puVar5 = puVar5 + 1;
    } while (uVar4 < 8);
    FUN_c02d1074(local_18);
    return 1;
  }
  FUN_c02d1074(local_18);
  return 0;
}



/* c02ca6e0 FUN_c02ca6e0 */

/* Boundary evidence: original MIPS .pdata c02ca6e0..c02ca737. Semantic name remains unreviewed. */

int FUN_c02ca6e0(int param_1,void *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x54);
  while ((piVar2 != (int *)0x0 && (iVar1 = memcmp(piVar2 + 1,param_2,0x10), iVar1 != 0))) {
    piVar2 = (int *)*piVar2;
  }
  return (int)piVar2;
}



/* c02ca738 FUN_c02ca738 */

/* Boundary evidence: original MIPS .pdata c02ca738..c02ca9ef. Semantic name remains unreviewed. */

DWORD FUN_c02ca738(int param_1,undefined4 *param_2,wchar_t *param_3,int param_4)

{
  size_t sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  undefined4 *puVar6;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c02d2224;
  DVar5 = 0;
  if (param_4 != 0) {
    sVar1 = wcslen(param_3);
    puVar2 = LocalAlloc(0,(sVar1 + 0xd) * 2);
    if (puVar2 == (undefined4 *)0x0) {
      DVar5 = 0xe;
    }
    else {
      wcscpy((wchar_t *)(puVar2 + 6),param_3);
      puVar2[5] = puVar2 + 6;
      puVar2[1] = *param_2;
      puVar2[2] = param_2[1];
      puVar2[3] = param_2[2];
      puVar2[4] = param_2[3];
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      iVar3 = FUN_c02ce2cc();
      if (iVar3 == 0) {
        DVar5 = GetLastError();
      }
      else {
        *puVar2 = *(undefined4 *)(param_1 + 0x54);
        *(undefined4 **)(param_1 + 0x54) = puVar2;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      if (DVar5 != 0) {
        LocalFree(puVar2);
      }
    }
    goto LAB_c02ca918;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  puVar2 = *(undefined4 **)(param_1 + 0x54);
  puVar6 = (undefined4 *)0x0;
  if (*(undefined4 **)(param_1 + 0x54) == (undefined4 *)0x0) {
LAB_c02ca90c:
    DVar5 = 2;
  }
  else {
    do {
      puVar4 = puVar2;
      iVar3 = memcmp(puVar4 + 1,param_2,0x10);
      if ((iVar3 == 0) &&
         (iVar3 = wcscmp((wchar_t *)puVar4[5],param_3), puVar2 = puVar4, iVar3 == 0)) break;
      puVar2 = (undefined4 *)*puVar4;
      puVar6 = puVar4;
    } while (puVar2 != (undefined4 *)0x0);
    if (puVar2 == (undefined4 *)0x0) goto LAB_c02ca90c;
    if (puVar6 == (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x54) = *puVar2;
    }
    else {
      *puVar6 = *puVar2;
    }
    iVar3 = FUN_c02ce2cc();
    if (iVar3 == 0) {
      DVar5 = GetLastError();
    }
    LocalFree(puVar2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
LAB_c02ca918:
  if (((*(int *)(param_1 + 0x60) != 0) && (*(int *)(param_1 + 0x18) != 0)) &&
     (iVar3 = memcmp(&DAT_c02c1a58,param_2,0x10), iVar3 == 0)) {
    StringCchCopyW(awStack_238,0x104,L"$bus\\");
    StringCchCatW(awStack_238,0x104,*(STRSAFE_LPCWSTR *)(param_1 + 0x60));
    iVar3 = wcscmp(awStack_238,param_3);
    if (iVar3 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
      if (param_4 == 0) {
        *(ushort *)(param_1 + 0x48) = *(ushort *)(param_1 + 0x48) & 0xffef;
      }
      else {
        *(ushort *)(param_1 + 0x48) = *(ushort *)(param_1 + 0x48) | 0x10;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
    }
  }
  FUN_c02d1074(local_30);
  return DVar5;
}



/* c02ca9f0 FUN_c02ca9f0 */

/* Boundary evidence: original MIPS .pdata c02ca9f0..c02caf0f. Semantic name remains unreviewed. */

void FUN_c02ca9f0(int param_1)

{
  wchar_t wVar1;
  LSTATUS LVar2;
  LSTATUS LVar3;
  size_t sVar4;
  wchar_t *pwVar5;
  int iVar6;
  STRSAFE_LPCWSTR pszSrc;
  wchar_t *_Str1;
  wchar_t *_Str;
  HKEY local_258;
  uint local_254;
  HKEY *local_250;
  int local_24c;
  int aiStack_248 [4];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c02d2224;
  local_258 = (HKEY)0x0;
  local_24c = param_1;
  StringCchPrintfW(awStack_238,0x104,L"%s\\%02u",L"Drivers\\Active");
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,awStack_238,0,0,&local_258);
  if ((LVar2 == 0) &&
     (LVar2 = RegQueryValueExW(local_258,L"IClass",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,&local_254)
     , LVar2 != 0)) {
    RegCloseKey(local_258);
  }
  LVar3 = 0;
  if ((LVar2 == 0) ||
     ((LVar2 = RegOpenKeyExW((HKEY)0x80000002,*(LPCWSTR *)(param_1 + 100),0,0,&local_258),
      LVar2 == 0 &&
      ((LVar3 = RegQueryValueExW(local_258,L"IClass",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,
                                 &local_254), LVar3 == 0 || (RegCloseKey(local_258), LVar3 == 0)))))
     ) {
    if ((local_254 & 1) != 0) {
      RegCloseKey(local_258);
      goto LAB_c02caecc;
    }
    if (local_254 + 2 < local_254) {
      local_254 = local_254 - 2;
    }
    iVar6 = (int)(local_254 + 9) >> 3;
    _Str = (wchar_t *)(&local_258 + iVar6 * -2);
    local_250 = (HKEY *)_Str;
    if ((HKEY *)_Str != (HKEY *)0x0) {
      aiStack_248[iVar6 * -2 + -5] = (int)&local_254;
      aiStack_248[iVar6 * -2 + -6] = (int)_Str;
      LVar3 = RegQueryValueExW(local_258,L"IClass",(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)aiStack_248[iVar6 * -2 + -6],
                               (LPDWORD)aiStack_248[iVar6 * -2 + -5]);
      local_254 = local_254 >> 1;
      *(wchar_t *)((int)_Str + (local_254 - 1) * 2) = L'\0';
      *(wchar_t *)((int)_Str + local_254 * 2) = L'\0';
    }
    RegCloseKey(local_258);
    if (LVar3 != 0) goto LAB_c02caecc;
  }
  else {
    _Str = L"{f8a6ba98-087a-43ac-a9d8-b7f13c5bae31}";
  }
  if (*(void **)(param_1 + 0x58) != (void *)0x0) {
    FUN_c02ca528(*(void **)(param_1 + 0x58),1);
  }
  wVar1 = *_Str;
  while (wVar1 != L'\0') {
    sVar4 = wcslen(_Str);
    pwVar5 = wcschr(_Str,L'=');
    if (pwVar5 == (wchar_t *)0x0) {
LAB_c02cad5c:
      _Str1 = *(wchar_t **)(param_1 + 0x58);
      if ((_Str1 == (wchar_t *)0x0) &&
         (_Str1 = pwVar5, *(wchar_t **)(param_1 + 0x5c) != (wchar_t *)0x0)) {
        _Str1 = *(wchar_t **)(param_1 + 0x5c);
      }
      if (_Str1 != (wchar_t *)0x0) {
LAB_c02cad8c:
        iVar6 = _wcsicmp(_Str1,L"%d");
        if (iVar6 == 0) {
          if (*(int *)(param_1 + 0x5c) == 0) goto LAB_c02caec0;
          StringCchCopyW(awStack_238,0x104,L"$device\\");
          pszSrc = *(STRSAFE_LPCWSTR *)(param_1 + 0x5c);
LAB_c02cadd0:
          StringCchCatW(awStack_238,0x104,pszSrc);
LAB_c02cae78:
          _Str1 = awStack_238;
        }
        else {
          iVar6 = _wcsicmp(_Str1,L"%b");
          if (iVar6 == 0) {
            if ((*(int *)(param_1 + 0x60) != 0) && (*(int *)(param_1 + 0x18) != 0)) {
              StringCchCopyW(awStack_238,0x104,L"$bus\\");
              pszSrc = *(STRSAFE_LPCWSTR *)(param_1 + 0x60);
              goto LAB_c02cadd0;
            }
            _Str1 = (wchar_t *)0x0;
          }
          else {
            iVar6 = _wcsicmp(_Str1,L"%l");
            if (iVar6 == 0) {
              if (*(STRSAFE_LPCWSTR *)(param_1 + 0x58) == (STRSAFE_LPCWSTR)0x0) goto LAB_c02caec0;
              StringCchCopyW(awStack_238,0x104,*(STRSAFE_LPCWSTR *)(param_1 + 0x58));
              goto LAB_c02cae78;
            }
          }
        }
        if ((_Str1 != (wchar_t *)0x0) && (iVar6 = FUN_c02ca5d4(_Str,(int)aiStack_248), iVar6 != 0))
        {
          FUN_c02ca738(param_1,aiStack_248,_Str1,1);
        }
      }
    }
    else {
      *pwVar5 = L'\0';
      _Str1 = pwVar5 + 1;
      if (*_Str1 != L'\0') {
        pwVar5 = _Str1;
        if (_Str1 == (wchar_t *)0x0) goto LAB_c02cad5c;
        goto LAB_c02cad8c;
      }
    }
LAB_c02caec0:
    _Str = (wchar_t *)((int)_Str + (sVar4 + 1) * 2);
    wVar1 = *_Str;
  }
LAB_c02caecc:
  FUN_c02d1074(local_30);
  return;
}



/* c02caf10 FUN_c02caf10 */

/* Boundary evidence: original MIPS .pdata c02caf10..c02caf1b. Semantic name remains unreviewed. */

undefined4 FUN_c02caf10(void)

{
  return 1;
}



/* c02caf1c FUN_c02caf1c */

/* Boundary evidence: original MIPS .pdata c02caf1c..c02caf9f. Semantic name remains unreviewed. */

void FUN_c02caf1c(int param_1)

{
  int iVar1;
  
  if (*(void **)(param_1 + 0x58) != (void *)0x0) {
    FUN_c02ca528(*(void **)(param_1 + 0x58),0);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  iVar1 = *(int *)(param_1 + 0x54);
  while (iVar1 != 0) {
    FUN_c02ca738(param_1,(undefined4 *)(*(int *)(param_1 + 0x54) + 4),
                 *(wchar_t **)(*(int *)(param_1 + 0x54) + 0x14),0);
    iVar1 = *(int *)(param_1 + 0x54);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2300);
  return;
}



/* c02cafa0 FUN_c02cafa0 */

/* Boundary evidence: original MIPS .pdata c02cafa0..c02cb06b. Semantic name remains unreviewed. */

void FUN_c02cafa0(void)

{
  HANDLE hObject;
  
  DAT_c02d229c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2288);
  DAT_c02d2284 = &DAT_c02d2280;
  DAT_c02d2280 = &DAT_c02d2280;
  if (DAT_c02d229c != (HANDLE)0x0) {
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c02ca240,&DAT_c02d2280,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
      return;
    }
    if (DAT_c02d229c != (HANDLE)0x0) {
      CloseHandle(DAT_c02d229c);
      DAT_c02d229c = (HANDLE)0x0;
    }
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2288);
  return;
}



/* c02cb06c FUN_c02cb06c */

/* Boundary evidence: original MIPS .pdata c02cb06c..c02cb0df. Semantic name remains unreviewed. */

undefined4 FUN_c02cb06c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = CreateAPISet(&DAT_c02c1c60,0xc,&PTR_FUN_c02c1bd0,&DAT_c02c1c00);
  *(int *)(param_1 + 0x18) = iVar1;
  if (iVar1 != -1) {
    uVar2 = RegisterAPISet(iVar1,0x80000007);
  }
  return uVar2;
}



/* c02cb0e0 FUN_c02cb0e0 */

/* Boundary evidence: original MIPS .pdata c02cb0e0..c02cb127. Semantic name remains unreviewed. */

void FUN_c02cb0e0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c02c1c68;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    FUN_c02c50d0((undefined4 *)param_1[2]);
  }
  *param_1 = &PTR_FUN_c02c1560;
  return;
}



/* c02cb128 FUN_c02cb128 */

bool FUN_c02cb128(int param_1)

{
  return *(int *)(param_1 + 8) != 0;
}



/* c02cb140 FUN_c02cb140 */

/* Boundary evidence: original MIPS .pdata c02cb140..c02cb163. Semantic name remains unreviewed. */

void FUN_c02cb140(undefined4 param_1,undefined4 param_2)

{
  CreateAPIHandle(param_2,param_1);
  return;
}



/* c02cb164 FUN_c02cb164 */

/* Boundary evidence: original MIPS .pdata c02cb164..c02cb1d7. Semantic name remains unreviewed. */

void FUN_c02cb164(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  ULONG_PTR UVar2;
  
  EnterCriticalSection(param_1);
  while (param_1->SpinCount != 0) {
    puVar1 = (undefined4 *)param_1->SpinCount;
    UVar2 = puVar1[3];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
    param_1->SpinCount = UVar2;
  }
  LeaveCriticalSection(param_1);
  DeleteCriticalSection(param_1);
  return;
}



/* c02cb1d8 FUN_c02cb1d8 */

/* Boundary evidence: original MIPS .pdata c02cb1d8..c02cb287. Semantic name remains unreviewed. */

ULONG_PTR FUN_c02cb1d8(LPCRITICAL_SECTION param_1,ULONG_PTR param_2,int param_3)

{
  ULONG_PTR UVar1;
  ULONG_PTR UVar2;
  ULONG_PTR *pUVar3;
  
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    EnterCriticalSection(param_1);
    if ((param_3 == 0) && (UVar2 = param_1->SpinCount, UVar2 != 0)) {
      pUVar3 = (ULONG_PTR *)(UVar2 + 0xc);
      UVar1 = *pUVar3;
      while (UVar1 != 0) {
        UVar2 = *pUVar3;
        pUVar3 = (ULONG_PTR *)(UVar2 + 0xc);
        UVar1 = *pUVar3;
      }
      *(ULONG_PTR *)(UVar2 + 0xc) = param_2;
    }
    else {
      *(ULONG_PTR *)(param_2 + 0xc) = param_1->SpinCount;
      param_1->SpinCount = param_2;
    }
    InterlockedIncrement((LONG *)(param_2 + 4));
    LeaveCriticalSection(param_1);
  }
  return param_2;
}



/* c02cb288 FUN_c02cb288 */

/* Boundary evidence: original MIPS .pdata c02cb288..c02cb333. Semantic name remains unreviewed. */

undefined4 * FUN_c02cb288(LPCRITICAL_SECTION param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  EnterCriticalSection(param_1);
  puVar3 = (undefined4 *)param_1->SpinCount;
  puVar4 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    if (puVar3 == param_2) {
      param_1->SpinCount = param_2[3];
LAB_c02cb304:
      FUN_c02c50d0(param_2);
      puVar4 = param_2;
    }
    else {
      iVar2 = puVar3[3];
      while (iVar2 != 0) {
        puVar1 = (undefined4 *)puVar3[3];
        if (puVar1 == param_2) {
          puVar3[3] = param_2[3];
          goto LAB_c02cb304;
        }
        puVar3 = puVar1;
        iVar2 = puVar1[3];
      }
    }
  }
  LeaveCriticalSection(param_1);
  return puVar4;
}



/* c02cb334 FUN_c02cb334 */

/* Boundary evidence: original MIPS .pdata c02cb334..c02cb3c3. Semantic name remains unreviewed. */

ULONG_PTR FUN_c02cb334(LPCRITICAL_SECTION param_1,ULONG_PTR param_2)

{
  ULONG_PTR UVar1;
  ULONG_PTR UVar2;
  
  if (param_2 == 0) {
    UVar2 = 0;
  }
  else {
    EnterCriticalSection(param_1);
    for (UVar1 = param_1->SpinCount; UVar2 = 0, UVar1 != 0; UVar1 = *(ULONG_PTR *)(UVar1 + 0xc)) {
      if (UVar1 == param_2) {
        UVar2 = UVar1;
        if (UVar1 != 0) {
          InterlockedIncrement((LONG *)(UVar1 + 4));
        }
        break;
      }
    }
    LeaveCriticalSection(param_1);
  }
  return UVar2;
}



/* c02cb3c4 FUN_c02cb3c4 */

/* Boundary evidence: original MIPS .pdata c02cb3c4..c02cb3fb. Semantic name remains unreviewed. */

LPCRITICAL_SECTION FUN_c02cb3c4(LPCRITICAL_SECTION param_1)

{
  InitializeCriticalSection(param_1);
  param_1->SpinCount = 0;
  param_1[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0xffffffff;
  return param_1;
}



/* c02cb3fc FUN_c02cb3fc */

/* Boundary evidence: original MIPS .pdata c02cb3fc..c02cb447. Semantic name remains unreviewed. */

void FUN_c02cb3fc(LPCRITICAL_SECTION param_1)

{
  if (param_1[1].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0xffffffff) {
    CloseHandle(param_1[1].DebugInfo);
  }
  FUN_c02cb164(param_1);
  return;
}



/* c02cb448 FUN_c02cb448 */

/* Boundary evidence: original MIPS .pdata c02cb448..c02cb493. Semantic name remains unreviewed. */

undefined4 FUN_c02cb448(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = 0;
  if ((param_1 != (undefined4 *)0x0) && (DAT_c02d2248 != (LPCRITICAL_SECTION)0x0)) {
    puVar2 = FUN_c02cb288(DAT_c02d2248,param_1);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* c02cb494 FUN_c02cb494 */

/* Boundary evidence: original MIPS .pdata c02cb494..c02cb54f. Semantic name remains unreviewed. */

uint FUN_c02cb494(ULONG_PTR param_1,undefined4 param_2,uint *param_3,uint param_4,LPHANDLE param_5,
                 uint param_6,undefined4 *param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (((param_1 != 0) && (DAT_c02d2248 != (LPCRITICAL_SECTION)0x0)) &&
     (puVar1 = (undefined4 *)FUN_c02cb334(DAT_c02d2248,param_1), puVar1 != (undefined4 *)0x0)) {
    uVar2 = FUN_c02cdc2c(puVar1[2],param_2,param_3,param_4,param_5,param_6,param_7);
    FUN_c02c50d0(puVar1);
  }
  return uVar2;
}



/* c02cb550 FUN_c02cb550 */

/* Boundary evidence: original MIPS .pdata c02cb550..c02cb66b. Semantic name remains unreviewed. */

HANDLE FUN_c02cb550(int param_1)

{
  int *piVar1;
  int iVar2;
  HANDLE hObject;
  ULONG_PTR UVar3;
  
  if (DAT_c02d2248 != (LPCRITICAL_SECTION)0x0) {
    piVar1 = operator_new(0x10);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1[1] = 0;
      *piVar1 = (int)&PTR_FUN_c02c1c68;
      piVar1[2] = param_1;
      piVar1[3] = 0;
      if (param_1 != 0) {
        InterlockedIncrement((LONG *)(param_1 + 4));
      }
    }
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 4))(piVar1);
      if ((iVar2 != 0) &&
         (hObject = (HANDLE)(**(code **)(*piVar1 + 8))(piVar1,DAT_c02d2248[1].DebugInfo),
         hObject != (HANDLE)0x0)) {
        UVar3 = FUN_c02cb1d8(DAT_c02d2248,(ULONG_PTR)piVar1,1);
        if (UVar3 == 0) {
          CloseHandle(hObject);
          hObject = (HANDLE)0x0;
        }
        if (hObject != (HANDLE)0x0) {
          return hObject;
        }
      }
      (**(code **)*piVar1)(piVar1,1);
    }
  }
  return (HANDLE)0x0;
}



/* c02cb66c FUN_c02cb66c */

/* Boundary evidence: original MIPS .pdata c02cb66c..c02cb6b7. Semantic name remains unreviewed. */

undefined4 * FUN_c02cb66c(undefined4 *param_1,uint param_2)

{
  FUN_c02cb0e0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c02cb6b8 FUN_c02cb6b8 */

/* Boundary evidence: original MIPS .pdata c02cb6b8..c02cb6ef. Semantic name remains unreviewed. */

bool FUN_c02cb6b8(wchar_t *param_1)

{
  int iVar1;
  
  iVar1 = _wcsnicmp(param_1,L"services\\",9);
  return iVar1 == 0;
}



/* c02cb6f0 FUN_c02cb6f0 */

/* Boundary evidence: original MIPS .pdata c02cb6f0..c02cb8d3. Semantic name remains unreviewed. */

int FUN_c02cb6f0(LPCWSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  LSTATUS LVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint local_38;
  HKEY local_34;
  DWORD local_30 [2];
  
  FUN_c02c52c0(&local_34,(HKEY)0x80000002,param_1);
  local_38 = 0;
  iVar6 = 0;
  iVar7 = 2;
  do {
    if (local_34 == (HKEY)0x0) {
LAB_c02cb7c8:
      iVar4 = _wcsnicmp(param_1,L"services\\",9);
      if (iVar4 == 0) {
        if (DAT_c02d2244 != (LPCRITICAL_SECTION)0x0) {
          uVar5 = 2;
          goto LAB_c02cb7b8;
        }
LAB_c02cb7f0:
        piVar3 = (int *)0x0;
        goto LAB_c02cb824;
      }
      if (DAT_c02d2244 == (LPCRITICAL_SECTION)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = FUN_c02c6818(DAT_c02d2244);
      }
      if (piVar3 != (int *)0x0) {
        InterlockedIncrement(piVar3 + 1);
        goto LAB_c02cb824;
      }
    }
    else {
      local_30[0] = 4;
      local_30[1] = 0;
      LVar2 = RegQueryValueExW(local_34,L"UserProcGroup",(LPDWORD)0x0,local_30 + 1,(LPBYTE)&local_38
                               ,local_30);
      if (LVar2 != 0) goto LAB_c02cb7c8;
      uVar5 = local_38;
      if (DAT_c02d2244 == (LPCRITICAL_SECTION)0x0) goto LAB_c02cb7f0;
LAB_c02cb7b8:
      piVar3 = (int *)FUN_c02c68b0(DAT_c02d2244,uVar5,1);
LAB_c02cb824:
      if (piVar3 != (int *)0x0) {
        iVar6 = (**(code **)(*piVar3 + 8))(piVar3,param_2,param_3,param_4);
        FUN_c02c50d0(piVar3);
      }
    }
    if (iVar6 == 0) {
      Sleep(1000);
    }
    bVar1 = iVar7 == 0;
    iVar7 = iVar7 + -1;
    if ((bVar1) || (iVar6 != 0)) {
      if (local_34 != (HKEY)0x0) {
        RegCloseKey(local_34);
      }
      return iVar6;
    }
  } while( true );
}



/* c02cb8d4 FUN_c02cb8d4 */

/* Boundary evidence: original MIPS .pdata c02cb8d4..c02cb9b7. Semantic name remains unreviewed. */

undefined4 FUN_c02cb8d4(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if ((param_2 != (undefined4 *)0x0) &&
     (puVar3 = *(undefined4 **)(param_1 + 0x30), puVar3 != (undefined4 *)0x0)) {
    iVar1 = puVar3[3];
    if (param_2 == puVar3) {
      *(int *)(param_1 + 0x30) = iVar1;
      uVar4 = 1;
      (**(code **)*param_2)(param_2,1);
    }
    else {
      while (iVar1 != 0) {
        puVar2 = (undefined4 *)puVar3[3];
        if (puVar2 == param_2) {
          puVar3[3] = param_2[3];
          uVar4 = 1;
          (**(code **)*param_2)(param_2,1);
          break;
        }
        puVar3 = puVar2;
        iVar1 = puVar2[3];
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return uVar4;
}



/* c02cb9b8 FUN_c02cb9b8 */

/* Boundary evidence: original MIPS .pdata c02cb9b8..c02cbab3. Semantic name remains unreviewed. */

BOOL FUN_c02cb9b8(int param_1,DWORD param_2,LPVOID param_3,DWORD param_4,LPVOID param_5,
                 DWORD param_6,LPDWORD param_7)

{
  int iVar1;
  undefined4 uVar2;
  BOOL BVar3;
  undefined4 uVar4;
  
  iVar1 = __GetUserKData(0);
  uVar4 = *(undefined4 *)(iVar1 + -0x1c);
  uVar2 = GetDirectCallerProcessId();
  iVar1 = __GetUserKData(0);
  *(undefined4 *)(iVar1 + -0x1c) = uVar2;
  if (*(HANDLE *)(param_1 + 0x144) == (HANDLE)0xffffffff) {
    BVar3 = CeFsIoControlW(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x38));
  }
  else {
    BVar3 = DeviceIoControl(*(HANDLE *)(param_1 + 0x144),param_2,param_3,param_4,param_5,param_6,
                            param_7,(LPOVERLAPPED)0x0);
  }
  iVar1 = __GetUserKData(0);
  *(undefined4 *)(iVar1 + -0x1c) = uVar4;
  return BVar3;
}



/* c02cbab4 FUN_c02cbab4 */

/* Boundary evidence: original MIPS .pdata c02cbab4..c02cbb37. Semantic name remains unreviewed. */

undefined4 FUN_c02cbab4(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x20) + 0x24);
  iVar1 = GetCallerVMProcessId();
  if (iVar1 == iVar4) {
    uVar3 = 0x70000000;
    if (param_3 == 0) {
      uVar3 = 0x80000000;
    }
    uVar2 = 1;
    if (param_2 < uVar3) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c02cbb38 FUN_c02cbb38 */

/* Boundary evidence: original MIPS .pdata c02cbb38..c02cbbef. Semantic name remains unreviewed. */

undefined4 FUN_c02cbb38(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((*(int *)(param_1 + 0x148) == 0) && (*(int *)(param_1 + 0x38) != 0)) &&
     (*(int *)(param_1 + 0x38) != -1)) {
    iVar1 = _wcsicmp(L"giisr.dll",(wchar_t *)(param_1 + 0x40));
    if (iVar1 == 0) {
      iVar1 = _wcsicmp(L"ISRHandler",(wchar_t *)(param_1 + 0xc0));
      if (iVar1 == 0) {
        uVar2 = LoadIntChainHandler((wchar_t *)(param_1 + 0x40),(wchar_t *)(param_1 + 0xc0),
                                    *(undefined1 *)(param_1 + 0x38));
        *(undefined4 *)(param_1 + 0x148) = uVar2;
      }
    }
  }
  return uVar2;
}



/* c02cbbf0 FUN_c02cbbf0 */

/* Boundary evidence: original MIPS .pdata c02cbbf0..c02cbc6b. Semantic name remains unreviewed. */

undefined4 *
FUN_c02cbbf0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10)

{
  *param_1 = param_10;
  param_1[2] = param_3;
  param_1[3] = param_4;
  param_1[6] = param_6;
  param_1[7] = param_5;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  TranslateBusAddr(param_9,param_7,param_8,param_4,param_3,param_4,param_1 + 6,param_1 + 4);
  return param_1;
}



/* c02cbc6c FUN_c02cbc6c */

undefined4 FUN_c02cbc6c(int param_1,undefined4 param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x14);
  if ((((uVar2 != 0 || iVar1 != 0) && (*(int *)(param_1 + 0x18) == 0)) && (iVar1 <= param_4)) &&
     ((param_4 != iVar1 || (uVar2 <= param_3)))) {
    uVar2 = *(uint *)(param_1 + 0x1c) + uVar2;
    iVar1 = iVar1 + (uint)(uVar2 < *(uint *)(param_1 + 0x1c));
    iVar3 = param_4 + (uint)(param_5 + param_3 < param_5);
    if ((iVar3 <= iVar1) && ((iVar3 != iVar1 || (param_5 + param_3 <= uVar2)))) {
      return 1;
    }
  }
  return 0;
}



/* c02cbd00 FUN_c02cbd00 */

undefined4 FUN_c02cbd00(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_4 == 0) {
    uVar2 = *(uint *)(param_1 + 0x20);
    if ((((uVar2 != 0) && (*(int *)(param_1 + 0x18) == 0)) && (uVar2 <= param_2)) &&
       (param_2 + param_3 <= *(int *)(param_1 + 0x24) + uVar2)) {
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x10);
    iVar1 = *(int *)(param_1 + 0x14);
    if (((uVar2 != 0 || iVar1 != 0) && (*(int *)(param_1 + 0x18) != 0)) &&
       ((iVar1 < 1 && ((iVar1 != 0 || (uVar2 <= param_2)))))) {
      if ((param_3 <= param_3 + param_2) && (param_3 + param_2 <= *(int *)(param_1 + 0x1c) + uVar2))
      {
        return 1;
      }
    }
  }
  return 0;
}



/* c02cbdc8 FUN_c02cbdc8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_c02cbdc8(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = ~(_DAT_00005b04 - 1U) & *(uint *)(param_1 + 0x10);
  uVar2 = (int)~(_DAT_00005b04 - 1U) >> 0x1f & *(uint *)(param_1 + 0x14);
  if ((((uVar3 != 0 || uVar2 != 0) && (*(int *)(param_1 + 0x18) == 0)) &&
      ((int)uVar2 <= (int)param_4)) && ((param_4 != uVar2 || (uVar3 <= param_3)))) {
    uVar1 = (_DAT_00005b04 - 1U & *(uint *)(param_1 + 0x10)) + *(int *)(param_1 + 0x1c);
    uVar3 = uVar1 + uVar3;
    iVar5 = uVar2 + (uVar3 < uVar1);
    iVar4 = param_4 + (param_5 + param_3 < param_5);
    if ((iVar4 <= iVar5) && ((iVar4 != iVar5 || (param_5 + param_3 <= uVar3)))) {
      return 1;
    }
  }
  return 0;
}



/* c02cbe88 FUN_c02cbe88 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c02cbe88..c02cbfe3. Semantic name remains unreviewed. */

int FUN_c02cbe88(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,char param_6)

{
  int iVar1;
  HANDLE pvVar2;
  LPVOID lpAddress;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint dwSize;
  
  iVar1 = FUN_c02cbc6c(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    uVar4 = _DAT_00005b04 - 1;
    dwSize = (_DAT_00005b04 - 1U & param_3) + param_5;
    if (param_5 <= dwSize) {
      pvVar2 = (HANDLE)GetCallerProcess();
      lpAddress = VirtualAllocEx(pvVar2,(LPVOID)0x0,dwSize,0x2000,1);
      if (lpAddress == (LPVOID)0x0) {
        return 0;
      }
      uVar5 = 0;
      if (param_6 == '\0') {
        uVar5 = 0x200;
      }
      uVar3 = GetCallerProcess();
      iVar1 = VirtualCopyEx(uVar3,lpAddress,0x42,
                            ((int)~uVar4 >> 0x1f & param_4) << 0x18 | (~uVar4 & param_3) >> 8,dwSize
                            ,uVar5 | 0x404);
      if (iVar1 != 0) {
        return (_DAT_00005b04 - 1U & param_3) + (int)lpAddress;
      }
      pvVar2 = (HANDLE)GetCallerProcess();
      VirtualFreeEx(pvVar2,lpAddress,0,0x8000);
    }
  }
  return 0;
}



/* c02cbfe4 FUN_c02cbfe4 */

/* Boundary evidence: original MIPS .pdata c02cbfe4..c02cc117. Semantic name remains unreviewed. */

int FUN_c02cbfe4(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_2 >> 0x18;
  uVar3 = param_2 * 0x100;
  iVar1 = FUN_c02cbdc8(param_1,param_2,uVar3,uVar4,param_3);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    return 0;
  }
  iVar1 = CreateStaticMapping(param_2,param_3);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = *(uint *)(param_1 + 0x10);
  if (((int)*(uint *)(param_1 + 0x14) < (int)uVar4) ||
     ((uVar4 == *(uint *)(param_1 + 0x14) && (uVar2 < uVar3)))) {
    *(int *)(param_1 + 0x20) = iVar1;
    if (param_3 < uVar3 - uVar2) goto LAB_c02cc0ec;
    uVar4 = *(uint *)(param_1 + 0x1c);
    uVar3 = uVar2 + param_2 * -0x100 + param_3;
    if (uVar4 < uVar3) goto LAB_c02cc0e4;
  }
  else {
    *(uint *)(param_1 + 0x20) = uVar2 + param_2 * -0x100 + iVar1;
    if (param_3 < uVar2 + param_2 * -0x100) {
LAB_c02cc0ec:
      *(undefined4 *)(param_1 + 0x24) = 0;
      return iVar1;
    }
    uVar4 = *(uint *)(param_1 + 0x1c);
    uVar3 = (uVar3 - uVar2) + param_3;
    if (uVar4 < uVar3) goto LAB_c02cc0e4;
  }
  uVar4 = uVar3;
LAB_c02cc0e4:
  *(uint *)(param_1 + 0x24) = uVar4;
  return iVar1;
}



/* c02cc118 FUN_c02cc118 */

/* Boundary evidence: original MIPS .pdata c02cc118..c02cc1e3. Semantic name remains unreviewed. */

undefined4 *
FUN_c02cc118(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  DWORD local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  *param_1 = &PTR_FUN_c02c1cd0;
  puVar3 = param_1 + 2;
  param_1[1] = param_2;
  param_1[3] = param_5;
  *puVar3 = 0;
  local_28 = GetDirectCallerProcessId();
  iVar2 = param_1[1];
  local_30[0] = 0;
  if (iVar2 != 0) {
    local_24 = *(undefined4 *)(iVar2 + 0x1c);
    local_20 = param_3;
    local_1c = param_4;
    BVar1 = FUN_c02cb9b8(iVar2,0x1090018,&local_28,0x10,puVar3,4,local_30);
    if ((BVar1 == 0) || (local_30[0] < 4)) {
      *puVar3 = 0;
    }
  }
  return param_1;
}



/* c02cc208 FUN_c02cc208 */

/* Boundary evidence: original MIPS .pdata c02cc208..c02cc25f. Semantic name remains unreviewed. */

void FUN_c02cc208(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c02c1cd0;
  if ((param_1[1] != 0) && (param_1[2] != 0)) {
    FUN_c02cb9b8(param_1[1],0x109001c,param_1 + 2,4,(LPVOID)0x0,0,(LPDWORD)0x0);
  }
  return;
}



/* c02cc260 FUN_c02cc260 */

/* Boundary evidence: original MIPS .pdata c02cc260..c02cc34b. Semantic name remains unreviewed. */

void FUN_c02cc260(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  *param_5 = 0;
  uVar3 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x20) + 0x24);
  uVar1 = GetCallerProcess();
  iVar2 = VirtualAllocCopyEx(uVar1,uVar3,param_2,param_3,4);
  if ((param_4 != 0) && (iVar2 == 0)) {
    uVar3 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x20) + 0x24);
    uVar1 = GetCallerProcess();
    VirtualAllocCopyEx(uVar1,uVar3,param_2,param_3,2);
  }
  return;
}



/* c02cc34c FUN_c02cc34c */

/* Boundary evidence: original MIPS .pdata c02cc34c..c02cc487. Semantic name remains unreviewed. */

undefined4
FUN_c02cc34c(int param_1,uint param_2,void *param_3,size_t param_4,int param_5,void *param_6)

{
  if (param_6 == (void *)0x0) {
    if (param_2 != 0) {
      VirtualFreeEx(*(HANDLE *)(*(int *)(*(int *)(param_1 + 4) + 0x20) + 0x24),
                    (LPVOID)(param_2 & 0xffff0000),0,0x8000);
    }
  }
  else {
    if (param_2 != 0) {
      VirtualFreeEx(*(HANDLE *)(*(int *)(*(int *)(param_1 + 4) + 0x20) + 0x24),
                    (LPVOID)(param_2 & 0xffff0000),0,0x8000);
    }
    if (param_5 == 0) {
      memcpy(param_3,param_6,param_4);
    }
    VirtualFree(param_6,0,0x8000);
  }
  return 1;
}



/* c02cc488 FUN_c02cc488 */

/* Boundary evidence: original MIPS .pdata c02cc488..c02cc493. Semantic name remains unreviewed. */

undefined4 FUN_c02cc488(void)

{
  return 1;
}



/* c02cc494 FUN_c02cc494 */

/* Boundary evidence: original MIPS .pdata c02cc494..c02cc4df. Semantic name remains unreviewed. */

BOOL FUN_c02cc494(int param_1)

{
  BOOL BVar1;
  
  BVar1 = 0;
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 4) != 0)) {
    BVar1 = FUN_c02cb9b8(*(int *)(param_1 + 4),0x1090020,(int *)(param_1 + 8),4,(LPVOID)0x0,0,
                         (LPDWORD)0x0);
  }
  return BVar1;
}



/* c02cc4e0 FUN_c02cc4e0 */

/* Boundary evidence: original MIPS .pdata c02cc4e0..c02cc63b. Semantic name remains unreviewed. */

undefined4 FUN_c02cc4e0(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  void *pvVar4;
  void *pvVar5;
  void *local_40 [2];
  undefined4 local_38;
  undefined4 local_34;
  void *local_30;
  size_t local_2c;
  undefined4 local_28;
  
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 4) == 0)) {
    SetLastError(6);
    uVar3 = 0xffffffff;
  }
  else {
    pvVar4 = (void *)0x0;
    local_40[0] = (void *)0x0;
    pvVar5 = (void *)0x0;
    local_38 = GetDirectCallerProcessId();
    local_34 = *(undefined4 *)(param_1 + 8);
    local_28 = 0xffffffff;
    local_30 = param_2;
    local_2c = param_3;
    if (((param_2 != (void *)0x0) && (param_3 != 0)) &&
       (iVar1 = FUN_c02cbab4(*(int *)(param_1 + 4),(uint)param_2,1), iVar1 != 0)) {
      pvVar5 = (void *)FUN_c02cc260(param_1,param_2,param_3,0,local_40);
      pvVar4 = local_40[0];
      local_30 = pvVar5;
    }
    BVar2 = FUN_c02cb9b8(*(int *)(param_1 + 4),0x1090024,&local_38,0x14,(LPVOID)0x0,0,(LPDWORD)0x0);
    FUN_c02cc34c(param_1,(uint)pvVar5,param_2,param_3,0,pvVar4);
    uVar3 = 0xffffffff;
    if (BVar2 != 0) {
      uVar3 = local_28;
    }
  }
  return uVar3;
}



/* c02cc63c FUN_c02cc63c */

/* Boundary evidence: original MIPS .pdata c02cc63c..c02cc7a3. Semantic name remains unreviewed. */

undefined4 FUN_c02cc63c(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  void *pvVar4;
  void *pvVar5;
  void *local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  void *local_38;
  size_t local_34;
  undefined4 local_30;
  
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 4) == 0)) {
    SetLastError(6);
    uVar3 = 0xffffffff;
  }
  else {
    pvVar4 = (void *)0x0;
    local_48[0] = (void *)0x0;
    pvVar5 = (void *)0x0;
    local_40 = GetDirectCallerProcessId();
    local_3c = *(undefined4 *)(param_1 + 8);
    local_30 = 0xffffffff;
    local_38 = param_2;
    local_34 = param_3;
    if (((param_2 != (void *)0x0) && (param_3 != 0)) &&
       (iVar1 = FUN_c02cbab4(*(int *)(param_1 + 4),(uint)param_2,0), iVar1 != 0)) {
      pvVar5 = (void *)FUN_c02cc260(param_1,param_2,param_3,1,local_48);
      pvVar4 = local_48[0];
      local_38 = pvVar5;
    }
    BVar2 = FUN_c02cb9b8(*(int *)(param_1 + 4),0x1090028,&local_40,0x14,(LPVOID)0x0,0,(LPDWORD)0x0);
    FUN_c02cc34c(param_1,(uint)pvVar5,param_2,param_3,1,pvVar4);
    uVar3 = 0xffffffff;
    if (BVar2 != 0) {
      uVar3 = local_30;
    }
  }
  return uVar3;
}



/* c02cc7a4 FUN_c02cc7a4 */

/* Boundary evidence: original MIPS .pdata c02cc7a4..c02cc867. Semantic name remains unreviewed. */

undefined4 FUN_c02cc7a4(int param_1,undefined4 param_2,undefined4 param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 4) == 0)) {
    SetLastError(6);
    uVar2 = 0xffffffff;
  }
  else {
    local_28 = GetDirectCallerProcessId();
    local_24 = *(undefined4 *)(param_1 + 8);
    local_18 = 0xffffffff;
    local_20 = param_2;
    local_1c = param_3;
    BVar1 = FUN_c02cb9b8(*(int *)(param_1 + 4),0x109002c,&local_28,0x14,(LPVOID)0x0,0,(LPDWORD)0x0);
    uVar2 = 0xffffffff;
    if (BVar1 != 0) {
      uVar2 = local_18;
    }
  }
  return uVar2;
}



/* c02cc868 FUN_c02cc868 */

/* Boundary evidence: original MIPS .pdata c02cc868..c02cca8f. Semantic name remains unreviewed. */

BOOL FUN_c02cc868(int param_1,undefined4 param_2,void *param_3,size_t param_4,void *param_5,
                 size_t param_6,undefined4 *param_7)

{
  int iVar1;
  BOOL BVar2;
  void *pvVar3;
  void *local_68;
  void *local_64;
  void *local_60;
  void *local_5c;
  void *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  void *local_44;
  size_t local_40;
  void *local_3c;
  size_t local_38;
  uint local_34;
  undefined4 local_30;
  
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 4) == 0)) {
    SetLastError(6);
    BVar2 = 0;
  }
  else {
    local_60 = (void *)0x0;
    local_68 = (void *)0x0;
    pvVar3 = (void *)0x0;
    local_58 = (void *)0x0;
    local_5c = (void *)0x0;
    local_64 = (void *)0x0;
    local_50 = GetDirectCallerProcessId();
    local_4c = *(undefined4 *)(param_1 + 8);
    local_48 = param_2;
    local_44 = param_3;
    if (((param_3 != (void *)0x0) && (param_4 != 0)) &&
       (iVar1 = FUN_c02cbab4(*(int *)(param_1 + 4),(uint)param_3,0), iVar1 != 0)) {
      pvVar3 = (void *)FUN_c02cc260(param_1,param_3,param_4,1,&local_68);
      local_60 = local_68;
      local_44 = pvVar3;
    }
    local_40 = param_4;
    if (((param_5 == (void *)0x0) || (param_6 == 0)) ||
       (iVar1 = FUN_c02cbab4(*(int *)(param_1 + 4),(uint)param_5,1), iVar1 == 0)) {
      local_3c = param_5;
    }
    else {
      local_58 = (void *)FUN_c02cc260(param_1,param_5,param_6,0,&local_64);
      local_5c = local_64;
      local_3c = local_58;
    }
    local_38 = param_6;
    if (param_7 != (undefined4 *)0x0) {
      local_30 = *param_7;
    }
    local_34 = (uint)(param_7 != (undefined4 *)0x0);
    BVar2 = FUN_c02cb9b8(*(int *)(param_1 + 4),0x1090030,&local_50,0x24,(LPVOID)0x0,0,(LPDWORD)0x0);
    FUN_c02cc34c(param_1,(uint)pvVar3,param_3,param_4,1,local_60);
    FUN_c02cc34c(param_1,(uint)local_58,param_5,param_6,0,local_5c);
    if (param_7 != (undefined4 *)0x0) {
      *param_7 = local_30;
    }
  }
  return BVar2;
}



/* c02cca90 FUN_c02cca90 */

/* Boundary evidence: original MIPS .pdata c02cca90..c02ccaab. Semantic name remains unreviewed. */

void FUN_c02cca90(LPCWSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c02cb6f0(param_1,param_2,param_3,param_4);
  return;
}



/* c02ccaac FUN_c02ccaac */

/* Boundary evidence: original MIPS .pdata c02ccaac..c02ccad3. Semantic name remains unreviewed. */

void FUN_c02ccaac(int *param_1)

{
  (**(code **)(*param_1 + 0xc))();
  return;
}



/* c02ccad4 FUN_c02ccad4 */

/* Boundary evidence: original MIPS .pdata c02ccad4..c02ccaef. Semantic name remains unreviewed. */

void FUN_c02ccad4(int param_1)

{
  FUN_c02cc494(param_1);
  return;
}



/* c02ccaf0 FUN_c02ccaf0 */

/* Boundary evidence: original MIPS .pdata c02ccaf0..c02ccb0b. Semantic name remains unreviewed. */

void FUN_c02ccaf0(int param_1,void *param_2,size_t param_3)

{
  FUN_c02cc4e0(param_1,param_2,param_3);
  return;
}



/* c02ccb0c FUN_c02ccb0c */

/* Boundary evidence: original MIPS .pdata c02ccb0c..c02ccb27. Semantic name remains unreviewed. */

void FUN_c02ccb0c(int param_1,void *param_2,size_t param_3)

{
  FUN_c02cc63c(param_1,param_2,param_3);
  return;
}



/* c02ccb28 FUN_c02ccb28 */

/* Boundary evidence: original MIPS .pdata c02ccb28..c02ccb43. Semantic name remains unreviewed. */

void FUN_c02ccb28(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_c02cc7a4(param_1,param_2,param_3);
  return;
}



/* c02ccb44 FUN_c02ccb44 */

/* Boundary evidence: original MIPS .pdata c02ccb44..c02ccb73. Semantic name remains unreviewed. */

void FUN_c02ccb44(int param_1,undefined4 param_2,void *param_3,size_t param_4,void *param_5,
                 size_t param_6,undefined4 *param_7)

{
  FUN_c02cc868(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* c02ccb74 FUN_c02ccb74 */

/* Boundary evidence: original MIPS .pdata c02ccb74..c02ccc03. Semantic name remains unreviewed. */

bool FUN_c02ccb74(ULONG_PTR param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  bVar3 = false;
  if (param_1 != 0) {
    if (DAT_c02d2244 == (LPCRITICAL_SECTION)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = (undefined4 *)FUN_c02c59a4(DAT_c02d2244,*(ULONG_PTR *)(param_1 + 0x20));
    }
    if (puVar1 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_c02c5e44((int)puVar1,param_1);
      bVar3 = puVar2 != (undefined4 *)0x0;
      if (bVar3) {
        FUN_c02c50d0(puVar2);
      }
      FUN_c02c50d0(puVar1);
    }
  }
  return bVar3;
}



/* c02ccc04 FUN_c02ccc04 */

/* Boundary evidence: original MIPS .pdata c02ccc04..c02ccc8b. Semantic name remains unreviewed. */

undefined4 FUN_c02ccc04(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    if (DAT_c02d2244 == (LPCRITICAL_SECTION)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)FUN_c02c59a4(DAT_c02d2244,*(ULONG_PTR *)(param_1 + 0x20));
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(piVar1,param_1);
      FUN_c02c50d0(piVar1);
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* c02ccc8c FUN_c02ccc8c */

/* Boundary evidence: original MIPS .pdata c02ccc8c..c02ccf07. Semantic name remains unreviewed. */

undefined4 *
FUN_c02ccc8c(undefined4 *param_1,int param_2,STRSAFE_LPCWSTR param_3,STRSAFE_LPCWSTR param_4,
            undefined4 param_5,undefined4 param_6)

{
  bool bVar1;
  HRESULT HVar2;
  BOOL BVar3;
  int iVar4;
  LPHANDLE lpTargetHandle;
  undefined4 local_258;
  HANDLE local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_244;
  undefined4 *local_240;
  undefined4 local_23c;
  wchar_t local_238 [4];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c02d2224;
  *param_1 = &PTR_FUN_c02c1560;
  param_1[1] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  *param_1 = &PTR_FUN_c02c1cd8;
  param_1[8] = param_2;
  param_1[10] = param_6;
  param_1[0xc] = 0;
  param_1[9] = 0;
  param_1[7] = 0;
  param_1[0xb] = 0;
  param_1[0x50] = 0;
  param_1[0x52] = 0;
  param_1[0x51] = 0xffffffff;
  param_1[0xd] = 0x10c;
  param_1[0xf] = 0;
  param_1[0xe] = 0;
  if (param_2 == 0) goto LAB_c02ccec0;
  InterlockedIncrement((LONG *)(param_2 + 4));
  local_23c = param_5;
  local_240 = param_1;
  if (param_3 == (STRSAFE_LPCWSTR)0x0) {
    local_238[0] = L'\0';
LAB_c02ccda8:
    bVar1 = true;
    HVar2 = StringCbCopyW(awStack_230,0x208,param_4);
    if (HVar2 < 0) goto LAB_c02ccdc4;
  }
  else {
    HVar2 = StringCbCopyW(local_238,8,param_3);
    if (-1 < HVar2) goto LAB_c02ccda8;
LAB_c02ccdc4:
    bVar1 = false;
  }
  if (bVar1) {
    local_258 = 0;
    local_254 = (HANDLE)0xffffffff;
    BVar3 = FUN_c02cb9b8((int)param_1,0x1090400,&local_240,0x218,&local_258,8,(LPDWORD)0x0);
    if ((((BVar3 != 0) && (param_1[7] = local_258, local_254 != (HANDLE)0x0)) &&
        (local_254 != (HANDLE)0xffffffff)) &&
       (lpTargetHandle = (LPHANDLE)(param_1 + 0x51), *lpTargetHandle == (HANDLE)0xffffffff)) {
      iVar4 = param_1[8];
      local_250 = *(undefined4 *)(iVar4 + 0x1c);
      local_24c = *(undefined4 *)(iVar4 + 0x20);
      local_244 = *(undefined4 *)(iVar4 + 0x28);
      BVar3 = DuplicateHandle(*(HANDLE *)(iVar4 + 0x24),local_254,&DAT_00000042,lpTargetHandle,0,0,2
                             );
      if (((BVar3 == 0) || (*lpTargetHandle == (HANDLE)0x0)) ||
         (*lpTargetHandle == (HANDLE)0xffffffff)) {
        *lpTargetHandle = (HANDLE)0xffffffff;
      }
    }
  }
LAB_c02ccec0:
  FUN_c02d1074(local_28);
  return param_1;
}



/* c02ccf08 FUN_c02ccf08 */

/* Boundary evidence: original MIPS .pdata c02ccf08..c02ccf13. Semantic name remains unreviewed. */

undefined4 FUN_c02ccf08(void)

{
  return 1;
}



/* c02ccf38 FUN_c02ccf38 */

/* Boundary evidence: original MIPS .pdata c02ccf38..c02cd0af. Semantic name remains unreviewed. */

void FUN_c02ccf38(undefined4 *param_1)

{
  undefined4 *puVar1;
  HANDLE hObject;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int local_20 [2];
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 2);
  *param_1 = &PTR_FUN_c02c1cd8;
  EnterCriticalSection(lpCriticalSection);
  if ((HANDLE)param_1[0x50] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x50]);
    param_1[0x50] = 0;
  }
  while (param_1[9] != 0) {
    uVar2 = *(undefined4 *)param_1[9];
    operator_delete((undefined4 *)param_1[9]);
    param_1[9] = uVar2;
  }
  if (param_1[0x52] != 0) {
    FreeIntChainHandler();
    param_1[0x52] = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  if (param_1[8] != 0) {
    EnterCriticalSection(lpCriticalSection);
    while (param_1[0xc] != 0) {
      puVar1 = (undefined4 *)param_1[0xc];
      uVar2 = puVar1[3];
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(puVar1,1);
      }
      param_1[0xc] = uVar2;
    }
    if (param_1[7] != 0) {
      local_20[0] = param_1[7];
      FUN_c02cb9b8((int)param_1,0x1090404,local_20,4,(LPVOID)0x0,0,(LPDWORD)0x0);
    }
    LeaveCriticalSection(lpCriticalSection);
    FUN_c02c50d0((undefined4 *)param_1[8]);
  }
  hObject = (HANDLE)param_1[0x51];
  if ((hObject != (HANDLE)0x0) && (hObject != (HANDLE)0xffffffff)) {
    CloseHandle(hObject);
    param_1[0x51] = 0xffffffff;
  }
  DeleteCriticalSection(lpCriticalSection);
  *param_1 = &PTR_FUN_c02c1560;
  return;
}



/* c02cd0b0 FUN_c02cd0b0 */

/* Boundary evidence: original MIPS .pdata c02cd0b0..c02cd183. Semantic name remains unreviewed. */

int * FUN_c02cd0b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c02cc118(puVar1,param_1,param_2,param_3,*(undefined4 *)(param_1 + 0x30));
  }
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 4))(piVar2);
    if (iVar3 == 0) {
      (**(code **)*piVar2)(piVar2,1);
      piVar2 = (int *)0x0;
    }
    if (piVar2 != (int *)0x0) {
      *(int **)(param_1 + 0x30) = piVar2;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return piVar2;
}



/* c02cd184 FUN_c02cd184 */

/* Boundary evidence: original MIPS .pdata c02cd184..c02cd377. Semantic name remains unreviewed. */

undefined4 FUN_c02cd184(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  iVar2 = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  uVar3 = 0;
  if (*(int *)(param_2 + 0x40) != 0) {
    puVar4 = (undefined4 *)(param_2 + 0x48);
    do {
      if (5 < uVar3) break;
      uVar5 = puVar4[-1];
      puVar1 = operator_new(0x28);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = FUN_c02cbbf0(puVar1,iVar2,uVar5,0,*puVar4,0,*(undefined4 *)(param_2 + 8),
                              *(undefined4 *)(param_2 + 4),param_3,*(undefined4 *)(param_1 + 0x24));
      }
      if (puVar1 != (undefined4 *)0x0) {
        if (puVar1[4] == 0 && puVar1[5] == 0) {
          operator_delete(puVar1);
          puVar1 = (undefined4 *)0x0;
        }
        if (puVar1 != (undefined4 *)0x0) {
          *(undefined4 **)(param_1 + 0x24) = puVar1;
        }
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 2;
    } while (uVar3 < *(uint *)(param_2 + 0x40));
  }
  uVar3 = 0;
  if (*(int *)(param_2 + 0xc) != 0) {
    puVar4 = (undefined4 *)(param_2 + 0x10);
    do {
      if (5 < uVar3) break;
      uVar5 = *puVar4;
      puVar1 = operator_new(0x28);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = FUN_c02cbbf0(puVar1,iVar2,uVar5,0,puVar4[1],1,*(undefined4 *)(param_2 + 8),
                              *(undefined4 *)(param_2 + 4),param_3,*(undefined4 *)(param_1 + 0x24));
      }
      if (puVar1 != (undefined4 *)0x0) {
        if (puVar1[4] == 0 && puVar1[5] == 0) {
          operator_delete(puVar1);
          puVar1 = (undefined4 *)0x0;
        }
        if (puVar1 != (undefined4 *)0x0) {
          *(undefined4 **)(param_1 + 0x24) = puVar1;
        }
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 2;
    } while (uVar3 < *(uint *)(param_2 + 0xc));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return 1;
}



/* c02cd378 FUN_c02cd378 */

/* Boundary evidence: original MIPS .pdata c02cd378..c02cd42b. Semantic name remains unreviewed. */

int FUN_c02cd378(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,char param_6)

{
  int *piVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  iVar2 = 0;
  for (piVar1 = *(int **)(param_1 + 0x24); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    iVar2 = FUN_c02cbe88((int)piVar1,param_2,param_3,param_4,param_5,param_6);
    if (iVar2 != 0) break;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return iVar2;
}



/* c02cd42c FUN_c02cd42c */

/* Boundary evidence: original MIPS .pdata c02cd42c..c02cd547. Semantic name remains unreviewed. */

undefined4 FUN_c02cd42c(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (((((param_5 & 0x400) != 0) && (-1 < (int)param_4)) && (0xffff < param_2)) &&
     (param_2 + param_4 < 0x70000000)) {
    iVar2 = param_2;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    for (piVar3 = *(int **)(param_1 + 0x24); piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      iVar1 = FUN_c02cbdc8((int)piVar3,iVar2,param_3 << 8,param_3 >> 0x18,param_4);
      if (iVar1 != 0) {
        uVar4 = GetCallerProcess();
        uVar4 = VirtualCopyEx(uVar4,param_2,0x42,param_3,param_4,param_5);
        break;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  return uVar4;
}



/* c02cd548 FUN_c02cd548 */

/* Boundary evidence: original MIPS .pdata c02cd548..c02cd5e3. Semantic name remains unreviewed. */

int FUN_c02cd548(int param_1,uint param_2,uint param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  piVar1 = *(int **)(param_1 + 0x24);
  do {
    if (piVar1 == (int *)0x0) break;
    iVar2 = FUN_c02cbd00((int)piVar1,param_2,param_3,param_4);
    piVar1 = (int *)*piVar1;
  } while (iVar2 == 0);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return iVar2;
}



/* c02cd5e4 FUN_c02cd5e4 */

/* Boundary evidence: original MIPS .pdata c02cd5e4..c02cd66f. Semantic name remains unreviewed. */

int FUN_c02cd5e4(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  piVar1 = *(int **)(param_1 + 0x24);
  do {
    if (piVar1 == (int *)0x0) break;
    iVar2 = FUN_c02cbfe4((int)piVar1,param_2,param_3);
    piVar1 = (int *)*piVar1;
  } while (iVar2 == 0);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return iVar2;
}



/* c02cd670 FUN_c02cd670 */

/* Boundary evidence: original MIPS .pdata c02cd670..c02cd7db. Semantic name remains unreviewed. */

undefined4
FUN_c02cd670(int param_1,int param_2,int param_3,void *param_4,uint param_5,int param_6,int param_7,
            int param_8)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [4];
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_14;
  
  uVar2 = 0;
  if (((((*(int *)(param_1 + 0x148) != 0) && (param_2 == *(int *)(param_1 + 0x148))) &&
       (param_3 == 0x100)) && ((param_5 != 0 && (0x1f < param_5)))) &&
     ((param_6 == 0 && ((param_7 == 0 && (param_8 == 0)))))) {
    memcpy(auStack_30,param_4,0x20);
    iVar1 = 1;
    if (local_2c != 0) {
      iVar1 = FUN_c02cd548(param_1,local_20,local_1c,local_28);
      if (iVar1 == 0) {
        return 0;
      }
      if (local_24 != 0) {
        iVar1 = FUN_c02cd548(param_1,local_14,local_1c,local_28);
      }
    }
    if (iVar1 != 0) {
      uVar2 = KernelLibIoControl(*(undefined4 *)(param_1 + 0x148),0x100,auStack_30,0x20,0,0,0);
    }
  }
  return uVar2;
}



/* c02cd7dc FUN_c02cd7dc */

/* Boundary evidence: original MIPS .pdata c02cd7dc..c02cd7e7. Semantic name remains unreviewed. */

undefined4 FUN_c02cd7dc(void)

{
  return 1;
}



/* c02cd7e8 FUN_c02cd7e8 */

/* Boundary evidence: original MIPS .pdata c02cd7e8..c02cd833. Semantic name remains unreviewed. */

undefined4 * FUN_c02cd7e8(undefined4 *param_1,uint param_2)

{
  FUN_c02cc208(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c02cd834 FUN_c02cd834 */

/* Boundary evidence: original MIPS .pdata c02cd834..c02cd887. Semantic name remains unreviewed. */

int * FUN_c02cd834(int *param_1)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 8))(param_1), iVar1 == 0)) {
    FUN_c02ccc04((int)param_1);
    param_1 = (int *)0x0;
  }
  return param_1;
}



/* c02cd888 FUN_c02cd888 */

/* Boundary evidence: original MIPS .pdata c02cd888..c02cd8bb. Semantic name remains unreviewed. */

void FUN_c02cd888(int param_1)

{
  FUN_c02cb9b8(param_1,0x109000c,(LPVOID)(param_1 + 0x1c),4,(LPVOID)0x0,0,(LPDWORD)0x0);
  return;
}



/* c02cd8bc FUN_c02cd8bc */

/* Boundary evidence: original MIPS .pdata c02cd8bc..c02cd913. Semantic name remains unreviewed. */

undefined4 FUN_c02cd8bc(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = FUN_c02ccb74(*(ULONG_PTR *)(param_1 + 4));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x10))(*(int **)(param_1 + 4),param_1);
  }
  return uVar2;
}



/* c02cd914 FUN_c02cd914 */

/* Boundary evidence: original MIPS .pdata c02cd914..c02cd947. Semantic name remains unreviewed. */

void FUN_c02cd914(int param_1)

{
  FUN_c02cb9b8(param_1,0x1090014,(LPVOID)(param_1 + 0x1c),4,(LPVOID)0x0,0,(LPDWORD)0x0);
  return;
}



/* c02cd948 FUN_c02cd948 */

/* Boundary evidence: original MIPS .pdata c02cd948..c02cd97b. Semantic name remains unreviewed. */

void FUN_c02cd948(int param_1)

{
  FUN_c02cb9b8(param_1,0x1090010,(LPVOID)(param_1 + 0x1c),4,(LPVOID)0x0,0,(LPDWORD)0x0);
  return;
}



/* c02cd97c FUN_c02cd97c */

/* Boundary evidence: original MIPS .pdata c02cd97c..c02cd9c7. Semantic name remains unreviewed. */

undefined4 * FUN_c02cd97c(undefined4 *param_1,uint param_2)

{
  FUN_c02ccf38(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c02cd9c8 FUN_c02cd9c8 */

/* Boundary evidence: original MIPS .pdata c02cd9c8..c02cdc2b. Semantic name remains unreviewed. */

BOOL FUN_c02cd9c8(int param_1,LPCWSTR param_2,undefined4 param_3)

{
  HRESULT HVar1;
  HANDLE hSourceHandle;
  int iVar2;
  HKEY hKey;
  BOOL BVar3;
  HKEY local_2d8;
  HANDLE local_2d4;
  HANDLE local_2d0 [2];
  undefined4 local_2c8;
  undefined4 local_2c4;
  undefined4 local_2bc;
  undefined4 local_2b8 [30];
  undefined4 local_240;
  undefined4 local_23c;
  LPCWSTR local_238;
  undefined4 local_234;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c02d2224;
  BVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if (*(int *)(param_1 + 0x20) != 0) {
    local_240 = GetDirectCallerProcessId();
    local_23c = *(undefined4 *)(param_1 + 0x1c);
    FUN_c02c52c0(&local_2d8,(HKEY)0x80000002,param_2);
    local_238 = param_2;
    if ((local_2d8 != (HKEY)0x0) && (HVar1 = StringCbCopyW(awStack_230,0x208,param_2), -1 < HVar1))
    {
      hSourceHandle = FUN_c02cb550(param_1);
      if (hSourceHandle != (HANDLE)0x0) {
        iVar2 = *(int *)(param_1 + 0x20);
        local_2d4 = (HANDLE)0x0;
        local_2c8 = *(undefined4 *)(iVar2 + 0x1c);
        local_2c4 = *(undefined4 *)(iVar2 + 0x20);
        local_2bc = *(undefined4 *)(iVar2 + 0x28);
        BVar3 = DuplicateHandle(&DAT_00000042,hSourceHandle,*(HANDLE *)(iVar2 + 0x24),&local_2d4,0,0
                                ,2);
        if (BVar3 != 0) {
          local_2d0[0] = local_2d4;
          RegSetValueExW(local_2d8,L"ReflectorHandle",0,4,(BYTE *)local_2d0,4);
        }
        CloseHandle(hSourceHandle);
      }
      local_238 = (LPCWSTR)0x0;
    }
    hKey = (HKEY)0x0;
    if ((param_2 != (LPCWSTR)0x0) && (hKey = (HKEY)OpenDeviceKey(param_2), hKey != (HKEY)0x0)) {
      if ((undefined4 *)(param_1 + 0x34) != (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0x34) = 0x10c;
        DDKReg_GetIsrInfo(hKey);
      }
      iVar2 = CreateBusAccessHandle(param_2);
      local_2b8[0] = 0x74;
      DDKReg_GetWindowInfo(hKey,local_2b8);
      FUN_c02cd184(param_1,(int)local_2b8,iVar2);
      if (iVar2 != 0) {
        CloseBusAccessHandle(iVar2);
      }
    }
    local_234 = param_3;
    BVar3 = FUN_c02cb9b8(param_1,0x1090004,&local_240,0x218,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hKey != (HKEY)0x0) {
      RegCloseKey(hKey);
    }
    if (local_2d8 != (HKEY)0x0) {
      RegCloseKey(local_2d8);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  FUN_c02d1074(local_28);
  return BVar3;
}



/* c02cdc2c FUN_c02cdc2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c02cdc2c..c02ce277. Semantic name remains unreviewed. */

uint FUN_c02cdc2c(int param_1,undefined4 param_2,uint *param_3,uint param_4,LPHANDLE param_5,
                 uint param_6,undefined4 *param_7)

{
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  LPHANDLE lpTargetHandle;
  HANDLE pvVar5;
  uint uVar6;
  uint uVar7;
  void *local_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  
  uVar7 = 0;
  uVar3 = param_2;
  SetLastError(0x57);
  switch(param_2) {
  case 0x10a0004:
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    if (((param_3 != (uint *)0x0) && (0xf < param_4)) &&
       (lpTargetHandle = (LPHANDLE)(param_1 + 0x140), *lpTargetHandle == (HANDLE)0x0)) {
      if (*param_3 == *(uint *)(param_1 + 0x3c)) {
        pvVar5 = (HANDLE)GetCallerProcess();
        BVar1 = DuplicateHandle(pvVar5,(HANDLE)param_3[1],&DAT_00000042,lpTargetHandle,0,0,2);
        if (BVar1 != 0) {
          uVar4 = param_3[2];
          if ((uVar4 == 0) || (uVar6 = param_3[3], uVar6 == 0)) {
            uVar7 = InterruptInitialize(*param_3,*lpTargetHandle,0,0);
          }
          else {
            local_38[0] = (void *)0x0;
            iVar2 = CeOpenCallerBuffer(local_38,uVar4,uVar6,4,1);
            if ((-1 < iVar2) && (local_38[0] != (void *)0x0)) {
              uVar7 = InterruptInitialize(*param_3,*lpTargetHandle,local_38[0],uVar6);
              CeCloseCallerBuffer(local_38[0],uVar4,uVar6,4);
            }
          }
          goto LAB_c02cde50;
        }
      }
      *lpTargetHandle = (HANDLE)0x0;
    }
    goto LAB_c02cde50;
  case 0x10a0008:
    if (param_3 == (uint *)0x0) {
      return 0;
    }
    if (param_4 < 4) {
      return 0;
    }
    if (*param_3 != *(uint *)(param_1 + 0x3c)) {
      return 0;
    }
    InterruptDone();
    goto LAB_c02cde8c;
  case 0x10a000c:
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    if ((((param_3 != (uint *)0x0) && (3 < param_4)) && (*(int *)(param_1 + 0x140) != 0)) &&
       (*param_3 == *(uint *)(param_1 + 0x3c))) {
      InterruptDisable();
      CloseHandle(*(HANDLE *)(param_1 + 0x140));
      uVar7 = 1;
      *(undefined4 *)(param_1 + 0x140) = 0;
    }
LAB_c02cde50:
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    break;
  case 0x10a0010:
    if (param_3 == (uint *)0x0) {
      return 0;
    }
    if (param_4 < 8) {
      return 0;
    }
    if (*param_3 != *(uint *)(param_1 + 0x3c)) {
      return 0;
    }
    InterruptMask(*param_3,param_3[1]);
    goto LAB_c02cde8c;
  case 0x10a0014:
    if ((param_3 != (uint *)0x0) && (0xf < param_4)) {
      uVar7 = FUN_c02cd42c(param_1,*param_3,param_3[1],param_3[2],param_3[3]);
    }
    break;
  case 0x10a0018:
    if (param_3 == (uint *)0x0) {
      return 0;
    }
    if (param_4 < 0x102) {
      return 0;
    }
    if (param_5 == (LPHANDLE)0x0) {
      return 0;
    }
    if (param_6 < 4) {
      return 0;
    }
    pvVar5 = (HANDLE)FUN_c02cbb38(param_1);
    goto LAB_c02ce114;
  case 0x10a001c:
    if ((param_3 != (uint *)0x0) && (3 < param_4)) {
      uVar7 = 0;
      if ((*param_3 != 0) && (*param_3 == *(uint *)(param_1 + 0x148))) {
        FreeIntChainHandler();
        uVar7 = 1;
        *(undefined4 *)(param_1 + 0x148) = 0;
      }
    }
    break;
  case 0x10a0020:
    if (param_3 == (uint *)0x0) {
      return 0;
    }
    if (param_4 < 8) {
      return 0;
    }
    if (param_5 == (LPHANDLE)0x0) {
      return 0;
    }
    if (param_6 < 4) {
      return 0;
    }
    pvVar5 = (HANDLE)FUN_c02cd5e4(param_1,*param_3,param_3[1]);
LAB_c02ce114:
    if (pvVar5 == (HANDLE)0x0) {
      return 0;
    }
    *param_5 = pvVar5;
    goto LAB_c02cde8c;
  case 0x10a0024:
    if ((param_3 != (uint *)0x0) && (0xf < param_4)) {
      local_38[0] = (void *)0x0;
      if ((param_3[2] != 0) &&
         ((param_3[3] != 0 &&
          (iVar2 = CeOpenCallerBuffer(local_38,param_3[2],param_3[3],4,0), iVar2 < 0)))) {
        local_38[0] = (void *)0x0;
      }
      uVar7 = FUN_c02cd670(param_1,*param_3,param_3[1],local_38[0],param_3[3],(int)param_5,param_6,
                           (int)param_7);
      if (local_38[0] != (void *)0x0) {
        CeCloseCallerBuffer(local_38[0],param_3[2],param_3[3],4);
      }
    }
    break;
  case 0x10a0040:
    if (((param_3 != (uint *)0x0) && (0xf < param_4)) &&
       ((param_5 != (LPHANDLE)0x0 && (3 < param_6)))) {
      pvVar5 = (HANDLE)FUN_c02cd378(param_1,uVar3,*param_3,param_3[1],param_3[2],(char)param_3[3]);
      *param_5 = pvVar5;
      uVar7 = (uint)(pvVar5 != (HANDLE)0x0);
      if (param_7 != (undefined4 *)0x0) {
        *param_7 = 4;
      }
    }
    break;
  case 0x10a0044:
    if (param_3 == (uint *)0x0) {
      return 0;
    }
    if (param_4 < 8) {
      return 0;
    }
    uVar4 = *param_3;
    uVar7 = _DAT_00005b04 - 1;
    pvVar5 = (HANDLE)GetCallerProcess();
    VirtualFreeEx(pvVar5,(LPVOID)(~uVar7 & uVar4),0,0x8000);
LAB_c02cde8c:
    uVar7 = 1;
    break;
  case 0x10a0048:
    if ((((param_3 != (uint *)0x0) && (0xf < param_4)) && (param_5 != (LPHANDLE)0x0)) &&
       ((3 < param_6 && (iVar2 = __GetUserKData(0), *(int *)(iVar2 + -0x1c) != 0)))) {
      iVar2 = *(int *)(param_1 + 0x20);
      local_30 = *(undefined4 *)(iVar2 + 0x1c);
      local_2c = *(undefined4 *)(iVar2 + 0x20);
      pvVar5 = *(HANDLE *)(iVar2 + 0x24);
      local_24 = *(undefined4 *)(iVar2 + 0x28);
      iVar2 = __GetUserKData(0);
      uVar7 = DuplicateHandle(*(HANDLE *)(iVar2 + -0x1c),(HANDLE)*param_3,pvVar5,param_5,param_3[1],
                              param_3[2],param_3[3]);
    }
  }
  return uVar7;
}



/* c02ce278 FUN_c02ce278 */

/* Boundary evidence: original MIPS .pdata c02ce278..c02ce2cb. Semantic name remains unreviewed. */

void FUN_c02ce278(int param_1)

{
  undefined4 local_10 [2];
  
  local_10[0] = *(undefined4 *)(param_1 + 0x1c);
  FUN_c02cb9b8(param_1,0x1090008,local_10,4,(LPVOID)0x0,0,(LPDWORD)0x0);
  FUN_c02ccc04(param_1);
  return;
}



/* c02ce2cc FUN_c02ce2cc */

/* Boundary evidence: original MIPS .pdata c02ce2cc..c02ce2ef. Semantic name remains unreviewed. */

void FUN_c02ce2cc(void)

{
  (*(code *)&SUB_fffe6a8a)();
  return;
}



/* c02ce2f0 FUN_c02ce2f0 */

/* Boundary evidence: original MIPS .pdata c02ce2f0..c02ce54b. Semantic name remains unreviewed. */

undefined4 FUN_c02ce2f0(int param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  if (param_4 == 0) {
    uVar6 = 0;
    if (param_3 != 0) {
      iVar8 = param_2 << 1;
      uVar7 = param_2;
      do {
        if (((1 << (uVar7 & 0x1f) & *(uint *)((uVar7 >> 5) * 4 + *(int *)(param_1 + 4))) != 0) &&
           (*(short *)(*(int *)(param_1 + 0x10) + iVar8) == 0)) {
          return 0x57;
        }
        uVar6 = uVar6 + 1;
        uVar7 = uVar7 + 1;
        iVar8 = iVar8 + 2;
      } while (uVar6 < param_3);
      if (param_3 != 0) {
        iVar8 = param_2 << 1;
        do {
          uVar7 = param_2 >> 5;
          uVar6 = 1 << (param_2 & 0x1f);
          if ((*(uint *)(uVar7 * 4 + *(int *)(param_1 + 4)) & uVar6) == 0) {
            puVar5 = (uint *)(uVar7 * 4 + *(int *)(param_1 + 4));
            *puVar5 = *puVar5 | uVar6;
            *(undefined2 *)(iVar8 + *(int *)(param_1 + 0x10)) = 0;
          }
          else {
            if ((*(uint *)(uVar7 * 4 + *(int *)(param_1 + 0xc)) & uVar6) != 0) {
              puVar5 = (uint *)(uVar7 * 4 + *(int *)(param_1 + 0xc));
              *puVar5 = ~uVar6 & *puVar5;
            }
            psVar4 = (short *)(iVar8 + *(int *)(param_1 + 0x10));
            *psVar4 = *psVar4 + -1;
          }
          param_3 = param_3 - 1;
          param_2 = param_2 + 1;
          iVar8 = iVar8 + 2;
        } while (param_3 != 0);
      }
    }
  }
  else {
    bVar1 = (param_5 & 1) != 0;
    uVar6 = 0;
    if (param_3 != 0) {
      iVar8 = param_2 << 1;
      uVar7 = param_2;
      do {
        iVar2 = (uVar7 >> 5) * 4;
        uVar3 = 1 << (uVar7 & 0x1f);
        if ((*(uint *)(iVar2 + *(int *)(param_1 + 4)) & uVar3) == 0) {
          return 0x57;
        }
        if ((*(short *)(*(int *)(param_1 + 0x10) + iVar8) != 0) &&
           ((((*(uint *)(*(int *)(param_1 + 8) + iVar2) & uVar3) == 0 || (bVar1)) ||
            ((*(uint *)(*(int *)(param_1 + 0xc) + iVar2) & uVar3) != 0)))) {
          return 0xaa;
        }
        uVar6 = uVar6 + 1;
        uVar7 = uVar7 + 1;
        iVar8 = iVar8 + 2;
      } while (uVar6 < param_3);
      if (param_3 != 0) {
        iVar8 = param_2 << 1;
        do {
          psVar4 = (short *)(*(int *)(param_1 + 0x10) + iVar8);
          *psVar4 = *psVar4 + 1;
          if (bVar1) {
            puVar5 = (uint *)((param_2 >> 5) * 4 + *(int *)(param_1 + 0xc));
            *puVar5 = 1 << (param_2 & 0x1f) | *puVar5;
          }
          param_3 = param_3 - 1;
          param_2 = param_2 + 1;
          iVar8 = iVar8 + 2;
        } while (param_3 != 0);
      }
    }
  }
  return 0;
}



/* c02ce54c FUN_c02ce54c */

/* Boundary evidence: original MIPS .pdata c02ce54c..c02ce7c7. Semantic name remains unreviewed. */

undefined4 FUN_c02ce54c(uint *param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  if (param_5 != 0) {
    return 0x32;
  }
  while (puVar4 = (uint *)*param_1, puVar4 != (uint *)0x0) {
    if (param_4 == 0) {
      uVar2 = *puVar4;
      if ((param_2 < puVar4[1] + uVar2) && (uVar2 < param_2 + param_3)) {
        return 0x57;
      }
      if ((param_2 + param_3 <= uVar2) || (puVar4[1] + uVar2 == param_2)) goto LAB_c02ce6e4;
    }
    else if ((*puVar4 <= param_2) && (param_2 <= (puVar4[1] + *puVar4) - 1)) break;
    param_1 = puVar4 + 2;
  }
  if (param_4 == 0) {
LAB_c02ce6e4:
    if (puVar4 != (uint *)0x0) {
      uVar3 = puVar4[1];
      uVar2 = *puVar4;
      if (uVar3 + uVar2 == param_2) {
        puVar1 = (uint *)puVar4[2];
        if ((puVar1 != (uint *)0x0) && (*puVar1 < param_2 + param_3)) {
          return 0x57;
        }
        puVar4[1] = uVar3 + param_3;
        if (puVar1 == (uint *)0x0) {
          return 0;
        }
        if (*puVar1 != param_2 + param_3) {
          return 0;
        }
        puVar4[1] = puVar1[1] + uVar3 + param_3;
        puVar4[2] = puVar1[2];
        goto LAB_c02ce750;
      }
      if (uVar2 == param_2 + param_3) {
        *puVar4 = uVar2 - param_3;
        uVar3 = uVar3 + param_3;
        goto LAB_c02ce778;
      }
    }
    puVar1 = LocalAlloc(0,0xc);
    if (puVar1 == (uint *)0x0) {
      return 8;
    }
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = (uint)puVar4;
    *param_1 = (uint)puVar1;
  }
  else {
    if (puVar4 == (uint *)0x0) {
      return 0x57;
    }
    uVar2 = puVar4[1];
    uVar3 = *puVar4;
    uVar5 = param_2 + param_3;
    if (uVar2 + uVar3 < uVar5) {
      return 0xaa;
    }
    if (uVar2 != param_3) {
      if (uVar3 == param_2) {
        *puVar4 = uVar3 + param_3;
        puVar4[1] = uVar2 - param_3;
        return 0;
      }
      if (uVar2 + uVar3 == uVar5) {
        puVar4[1] = uVar2 - param_3;
        return 0;
      }
      puVar1 = LocalAlloc(0,0xc);
      if (puVar1 == (uint *)0x0) {
        return 8;
      }
      *puVar1 = uVar5;
      puVar1[1] = (*puVar4 - uVar5) + puVar4[1];
      puVar1[2] = puVar4[2];
      puVar4[2] = (uint)puVar1;
      uVar3 = (puVar4[1] - puVar1[1]) - param_3;
LAB_c02ce778:
      puVar4[1] = uVar3;
      return 0;
    }
    *param_1 = puVar4[2];
    puVar1 = puVar4;
LAB_c02ce750:
    LocalFree(puVar1);
  }
  return 0;
}



/* c02ce7c8 FUN_c02ce7c8 */

/* Boundary evidence: original MIPS .pdata c02ce7c8..c02cea4b. Semantic name remains unreviewed. */

undefined4 FUN_c02ce7c8(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  DWORD dwErrCode;
  uint uVar6;
  
  dwErrCode = 0x57;
  iVar1 = CeGetCallerTrust();
  if (iVar1 == 2) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
    for (piVar4 = DAT_c02d2268; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[8]) {
      if (*piVar4 == param_1) {
        if ((piVar4 != (int *)0x0) && ((uint)piVar4[1] <= param_2)) {
          uVar5 = param_2 - piVar4[1];
          uVar3 = piVar4[2];
          if ((uVar5 < uVar3) && (param_3 <= uVar3 - uVar5)) {
            if (DAT_c02d2250 < uVar3) {
              dwErrCode = 0x32;
            }
            else {
              uVar6 = 0;
              for (uVar3 = uVar5;
                  ((uVar6 < param_3 &&
                   ((*(uint *)((uVar3 >> 5) * 4 + piVar4[4]) & 1 << (uVar3 & 0x1f)) != 0)) &&
                  (*(short *)(uVar3 * 2 + piVar4[7]) == 0)); uVar3 = uVar3 + 1) {
                uVar6 = uVar6 + 1;
              }
              if (uVar6 == param_3) {
                for (uVar3 = 0; uVar3 < param_3; uVar3 = uVar3 + 1) {
                  if (param_4 == 0) {
                    puVar2 = (uint *)((uVar5 >> 5) * 4 + piVar4[5]);
                    *puVar2 = ~(1 << (uVar5 & 0x1f)) & *puVar2;
                  }
                  else {
                    puVar2 = (uint *)((uVar5 >> 5) * 4 + piVar4[5]);
                    *puVar2 = 1 << (uVar5 & 0x1f) | *puVar2;
                  }
                  uVar5 = uVar5 + 1;
                }
                dwErrCode = 0;
              }
            }
          }
        }
        break;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  else {
    dwErrCode = 5;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c02cea4c FUN_c02cea4c */

/* Boundary evidence: original MIPS .pdata c02cea4c..c02cea57. Semantic name remains unreviewed. */

undefined4 FUN_c02cea4c(void)

{
  return 1;
}



/* c02cea58 FUN_c02cea58 */

/* Boundary evidence: original MIPS .pdata c02cea58..c02cebff. Semantic name remains unreviewed. */

undefined4 FUN_c02cea58(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  DWORD dwErrCode;
  
  iVar1 = CeGetCallerTrust();
  dwErrCode = 2;
  if (iVar1 == 2) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
    for (piVar3 = DAT_c02d2268; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[8]) {
      if (*piVar3 == param_1) {
        if (piVar3 == (int *)0x0) break;
        if ((uint)piVar3[1] <= param_2) {
          uVar2 = param_2 - piVar3[1];
          uVar4 = piVar3[2];
          if ((uVar2 < uVar4) && (param_3 <= uVar4 - uVar2)) {
            if (DAT_c02d2250 < uVar4) {
              dwErrCode = FUN_c02ce54c((uint *)(piVar3 + 3),uVar2,param_3,param_4,0);
            }
            else {
              dwErrCode = FUN_c02ce2f0((int)(piVar3 + 3),uVar2,param_3,param_4,0);
            }
            break;
          }
        }
        dwErrCode = 0x57;
        break;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  else {
    dwErrCode = 5;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c02cec00 FUN_c02cec00 */

/* Boundary evidence: original MIPS .pdata c02cec00..c02cec0b. Semantic name remains unreviewed. */

undefined4 FUN_c02cec00(void)

{
  return 1;
}



/* c02cec0c FUN_c02cec0c */

/* Boundary evidence: original MIPS .pdata c02cec0c..c02cede3. Semantic name remains unreviewed. */

undefined4 FUN_c02cec0c(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  DWORD dwErrCode;
  
  iVar1 = CeGetCallerTrust();
  dwErrCode = 2;
  if (iVar1 == 2) {
    if ((param_4 & 1) != param_4) {
      SetLastError(0x57);
      return 0;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
    for (piVar3 = DAT_c02d2268; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[8]) {
      if (*piVar3 == param_1) {
        if (piVar3 == (int *)0x0) break;
        if ((uint)piVar3[1] <= param_2) {
          uVar2 = param_2 - piVar3[1];
          uVar4 = piVar3[2];
          if ((uVar2 < uVar4) && (param_3 <= uVar4 - uVar2)) {
            if (DAT_c02d2250 < uVar4) {
              dwErrCode = FUN_c02ce54c((uint *)(piVar3 + 3),uVar2,param_3,1,param_4);
            }
            else {
              dwErrCode = FUN_c02ce2f0((int)(piVar3 + 3),uVar2,param_3,1,param_4);
            }
            break;
          }
        }
        dwErrCode = 0x57;
        break;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  else {
    dwErrCode = 5;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c02cede4 FUN_c02cede4 */

/* Boundary evidence: original MIPS .pdata c02cede4..c02cedef. Semantic name remains unreviewed. */

undefined4 FUN_c02cede4(void)

{
  return 1;
}



/* c02cedf0 FUN_c02cedf0 */

/* Boundary evidence: original MIPS .pdata c02cedf0..c02cf04b. Semantic name remains unreviewed. */

undefined4 FUN_c02cedf0(int param_1,int param_2,uint param_3)

{
  int iVar1;
  SIZE_T uBytes;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  size_t _Size;
  DWORD dwErrCode;
  
  dwErrCode = 0;
  iVar1 = CeGetCallerTrust();
  if (iVar1 == 2) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
    for (piVar2 = DAT_c02d2268; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[8]) {
      if (*piVar2 == param_1) {
        if (piVar2 != (int *)0x0) {
          dwErrCode = 0xb7;
          goto LAB_c02cefd4;
        }
        break;
      }
    }
    if (param_3 == 0) {
      dwErrCode = 0x57;
    }
    else {
      uBytes = 0x24;
      if (param_3 <= DAT_c02d2250) {
        uBytes = (param_3 + 0x1f >> 5) * 0xc + (param_3 + 0x12) * 2;
      }
      piVar2 = LocalAlloc(0,uBytes);
      if (piVar2 == (int *)0x0) {
        dwErrCode = 8;
      }
      else {
        *piVar2 = param_1;
        piVar2[2] = param_3;
        piVar2[1] = param_2;
        if (DAT_c02d2250 < param_3) {
          piVar2[3] = 0;
        }
        else {
          uVar4 = param_3 + 0x1f >> 5;
          piVar3 = piVar2 + 9;
          piVar2[4] = (int)piVar3;
          piVar3 = piVar3 + uVar4;
          piVar2[5] = (int)piVar3;
          piVar2[6] = (int)(piVar3 + uVar4);
          piVar2[7] = (int)(piVar3 + uVar4 + uVar4);
          piVar2[3] = param_3 - 1;
          _Size = uVar4 << 2;
          memset((void *)piVar2[4],0,_Size);
          memset((void *)piVar2[5],0,_Size);
          memset((void *)piVar2[6],0,_Size);
        }
        piVar2[8] = (int)DAT_c02d2268;
        DAT_c02d2268 = piVar2;
      }
    }
LAB_c02cefd4:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  else {
    dwErrCode = 5;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c02cf04c FUN_c02cf04c */

/* Boundary evidence: original MIPS .pdata c02cf04c..c02cf057. Semantic name remains unreviewed. */

undefined4 FUN_c02cf04c(void)

{
  return 1;
}



/* c02cf058 FUN_c02cf058 */

/* Boundary evidence: original MIPS .pdata c02cf058..c02cf26b. Semantic name remains unreviewed. */

undefined4 FUN_c02cf058(int param_1)

{
  int *piVar1;
  int iVar2;
  HLOCAL hMem;
  uint uVar3;
  HLOCAL pvVar4;
  int *hMem_00;
  DWORD dwErrCode;
  int *piVar5;
  
  dwErrCode = 0;
  iVar2 = CeGetCallerTrust();
  if (iVar2 != 2) {
    dwErrCode = 5;
    goto LAB_c02cf0a0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
  piVar1 = DAT_c02d2268;
  piVar5 = (int *)0x0;
  while (hMem_00 = piVar1, hMem_00 != (int *)0x0) {
    if (*hMem_00 == param_1) {
      if (hMem_00 != (int *)0x0) {
        if (DAT_c02d2250 < (uint)hMem_00[2]) {
          hMem = (HLOCAL)hMem_00[3];
          while (hMem != (HLOCAL)0x0) {
            pvVar4 = *(HLOCAL *)((int)hMem + 8);
            LocalFree(hMem);
            hMem = pvVar4;
          }
          goto LAB_c02cf1c4;
        }
        uVar3 = 0;
        goto LAB_c02cf134;
      }
      break;
    }
    piVar5 = hMem_00;
    piVar1 = (int *)hMem_00[8];
  }
  dwErrCode = 2;
  goto LAB_c02cf1f8;
LAB_c02cf134:
  if ((uint)hMem_00[2] <= uVar3) goto LAB_c02cf1c4;
  if ((*(short *)(hMem_00[7] + uVar3 * 2) != 0) &&
     ((*(uint *)((uVar3 >> 5) * 4 + hMem_00[4]) & 1 << (uVar3 & 0x1f)) != 0)) {
    dwErrCode = 0xaa;
    goto LAB_c02cf1c4;
  }
  uVar3 = uVar3 + 1;
  goto LAB_c02cf134;
LAB_c02cf1c4:
  if (dwErrCode == 0) {
    if (piVar5 == (int *)0x0) {
      DAT_c02d2268 = (int *)hMem_00[8];
    }
    else {
      piVar5[8] = hMem_00[8];
    }
    LocalFree(hMem_00);
  }
LAB_c02cf1f8:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
  if (dwErrCode == 0) {
    return 1;
  }
LAB_c02cf0a0:
  SetLastError(dwErrCode);
  return 0;
}



/* c02cf26c FUN_c02cf26c */

/* Boundary evidence: original MIPS .pdata c02cf26c..c02cf277. Semantic name remains unreviewed. */

undefined4 FUN_c02cf26c(void)

{
  return 1;
}



/* c02cf278 FUN_c02cf278 */

/* Boundary evidence: original MIPS .pdata c02cf278..c02cf353. Semantic name remains unreviewed. */

undefined4 FUN_c02cf278(wchar_t **param_1,ulong *param_2,uint *param_3)

{
  wchar_t wVar1;
  uint uVar2;
  wchar_t *pwVar3;
  
  if (**param_1 != L'\0') {
    uVar2 = wcstoul(*param_1,param_1,0);
    *param_2 = uVar2;
    if (**param_1 == L'-') {
      uVar2 = wcstoul(*param_1 + 1,param_1,0);
    }
    *param_3 = uVar2;
    if (*param_2 <= uVar2) {
      *param_3 = (uVar2 - *param_2) + 1;
      wVar1 = **param_1;
      if ((wVar1 == L'\0') ||
         ((wVar1 == L',' && (pwVar3 = *param_1 + 1, *param_1 = pwVar3, *pwVar3 != L'\0')))) {
        return 1;
      }
    }
  }
  return 0;
}



/* c02cf354 FUN_c02cf354 */

/* Boundary evidence: original MIPS .pdata c02cf354..c02cf4fb. Semantic name remains unreviewed. */

undefined4 FUN_c02cf354(HKEY param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  DWORD dwIndex;
  DWORD local_448;
  DWORD local_444;
  DWORD local_440 [2];
  uint local_438;
  uint local_434;
  wchar_t *local_430 [2];
  undefined4 local_428;
  WCHAR aWStack_228 [256];
  uint local_28;
  
  local_28 = DAT_c02d2224;
  local_444 = 0x100;
  local_448 = 0x200;
  dwIndex = 0;
  iVar1 = RegEnumValueW(param_1,0,aWStack_228,&local_444,(LPDWORD)0x0,local_440,(LPBYTE)&local_428,
                        &local_448);
  while (iVar1 == 0) {
    if (local_440[0] == 1) {
      local_430[0] = (wchar_t *)&local_428;
      uVar2 = local_448;
      if (0x1fc < local_448) {
        uVar2 = 0x1fc;
      }
      *(undefined2 *)((int)&local_428 + (uVar2 & 0xfffffffe) + 2) = 0;
      *(undefined2 *)((int)&local_428 + (uVar2 & 0xfffffffe)) = 0;
      while (iVar1 = FUN_c02cf278(local_430,&local_438,&local_434), iVar1 != 0) {
        FUN_c02cec0c(param_2,local_438,local_434,1);
      }
    }
    else if (local_440[0] == 4) {
      FUN_c02cec0c(param_2,local_428,1,1);
    }
    dwIndex = dwIndex + 1;
    local_444 = 0x100;
    local_448 = 0x200;
    iVar1 = RegEnumValueW(param_1,dwIndex,aWStack_228,&local_444,(LPDWORD)0x0,local_440,
                          (LPBYTE)&local_428,&local_448);
  }
  FUN_c02d1074(local_28);
  return 1;
}



/* c02cf4fc FUN_c02cf4fc */

/* Boundary evidence: original MIPS .pdata c02cf4fc..c02cf883. Semantic name remains unreviewed. */

void FUN_c02cf4fc(HKEY param_1)

{
  int iVar1;
  LSTATUS LVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint local_40;
  uint local_3c;
  wchar_t *local_38 [2];
  int local_30;
  uint local_2c;
  uint local_28;
  HKEY local_24;
  wchar_t *local_20;
  uint local_1c;
  
  local_1c = DAT_c02d2224;
  LVar2 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_3c,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  if (LVar2 == 0) {
    local_3c = ((local_3c + 1 >> 1) + 2) * 2;
    iVar3 = (int)(local_3c + 7) >> 3;
    iVar1 = iVar3 * -8;
    pwVar4 = (wchar_t *)(&local_40 + iVar3 * -2);
    local_20 = pwVar4;
    if (pwVar4 != (wchar_t *)0x0) {
      local_40 = 4;
      *(uint **)(&stack0xffffffa4 + iVar1) = &local_40;
      *(int **)(&stack0xffffffa0 + iVar1) = &local_30;
      LVar2 = RegQueryValueExW(param_1,L"Identifier",(LPDWORD)0x0,(LPDWORD)0x0,
                               *(LPBYTE *)(&stack0xffffffa0 + iVar1),
                               *(LPDWORD *)(&stack0xffffffa4 + iVar1));
      if (LVar2 == 0) {
        local_40 = 4;
        *(uint **)(&stack0xffffffa4 + iVar1) = &local_40;
        *(uint **)(&stack0xffffffa0 + iVar1) = &local_2c;
        LVar2 = RegQueryValueExW(param_1,L"Minimum",(LPDWORD)0x0,(LPDWORD)0x0,
                                 *(LPBYTE *)(&stack0xffffffa0 + iVar1),
                                 *(LPDWORD *)(&stack0xffffffa4 + iVar1));
        if (LVar2 == 0) {
          local_40 = 4;
          *(uint **)(&stack0xffffffa4 + iVar1) = &local_40;
          *(uint **)(&stack0xffffffa0 + iVar1) = &local_28;
          LVar2 = RegQueryValueExW(param_1,L"Space",(LPDWORD)0x0,(LPDWORD)0x0,
                                   *(LPBYTE *)(&stack0xffffffa0 + iVar1),
                                   *(LPDWORD *)(&stack0xffffffa4 + iVar1));
          if ((LVar2 == 0) && (iVar3 = FUN_c02cedf0(local_30,local_2c,local_28), iVar3 != 0)) {
            local_40 = local_3c;
            *(uint **)(&stack0xffffffa4 + iVar1) = &local_40;
            *(wchar_t **)(&stack0xffffffa0 + iVar1) = pwVar4;
            LVar2 = RegQueryValueExW(param_1,L"Ranges",(LPDWORD)0x0,(LPDWORD)0x0,
                                     *(LPBYTE *)(&stack0xffffffa0 + iVar1),
                                     *(LPDWORD *)(&stack0xffffffa4 + iVar1));
            if (LVar2 == 0) {
              local_38[0] = pwVar4;
              pwVar4[(local_3c >> 1) - 2] = L'\0';
              *(undefined2 *)((int)local_38[0] + ((local_3c & 0xfffffffe) - 2)) = 0;
              while (iVar3 = FUN_c02cf278(local_38,&local_2c,&local_28), iVar3 != 0) {
                FUN_c02cea58(local_30,local_2c,local_28,0);
              }
            }
            local_40 = local_3c;
            *(uint **)(&stack0xffffffa4 + iVar1) = &local_40;
            *(wchar_t **)(&stack0xffffffa0 + iVar1) = pwVar4;
            LVar2 = RegQueryValueExW(param_1,L"Shared",(LPDWORD)0x0,(LPDWORD)0x0,
                                     *(LPBYTE *)(&stack0xffffffa0 + iVar1),
                                     *(LPDWORD *)(&stack0xffffffa4 + iVar1));
            if (LVar2 == 0) {
              local_38[0] = pwVar4;
              pwVar4[(local_3c >> 1) - 2] = L'\0';
              *(undefined2 *)((int)local_38[0] + ((local_3c & 0xfffffffe) - 2)) = 0;
              while (iVar3 = FUN_c02cf278(local_38,&local_2c,&local_28), iVar3 != 0) {
                FUN_c02ce7c8(local_30,local_2c,local_28,1);
              }
            }
            *(HKEY **)(&stack0xffffffa0 + iVar1) = &local_24;
            LVar2 = RegOpenKeyExW(param_1,L"Reserved",0,0,*(PHKEY *)(&stack0xffffffa0 + iVar1));
            if (LVar2 == 0) {
              FUN_c02cf354(local_24,local_30);
              RegCloseKey(local_24);
            }
          }
        }
      }
    }
  }
  FUN_c02d1074(local_1c);
  return;
}



/* c02cf884 FUN_c02cf884 */

/* Boundary evidence: original MIPS .pdata c02cf884..c02cf88f. Semantic name remains unreviewed. */

undefined4 FUN_c02cf884(void)

{
  return 1;
}



/* c02cf890 FUN_c02cf890 */

/* Boundary evidence: original MIPS .pdata c02cf890..c02cfb0b. Semantic name remains unreviewed. */

void FUN_c02cf890(LPCWSTR param_1)

{
  int iVar1;
  LSTATUS LVar2;
  HKEY dwIndex;
  uint uVar3;
  int iVar4;
  LPCWSTR lpName;
  DWORD local_38;
  HKEY local_34;
  HKEY local_30;
  uint local_2c;
  HKEY local_28;
  LPCWSTR local_24;
  uint local_20;
  
  local_20 = DAT_c02d2224;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,&local_34);
  if ((LVar2 == 0) &&
     (LVar2 = RegQueryInfoKeyW(local_34,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_38
                               ,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                               (PFILETIME)0x0), LVar2 == 0)) {
    local_38 = 4;
    LVar2 = RegQueryValueExW(local_34,L"MaxDenseResources",(LPDWORD)0x0,(LPDWORD)0x0,
                             (LPBYTE)&local_30,&local_38);
    if (LVar2 == 0) {
      DAT_c02d2250 = local_30;
    }
    uVar3 = local_38 + 1;
    local_38 = uVar3 * 2;
    iVar4 = (int)(local_38 + 7) >> 3;
    iVar1 = iVar4 * -8;
    lpName = (LPCWSTR)(&local_38 + iVar4 * -2);
    local_24 = lpName;
    if (lpName != (LPCWSTR)0x0) {
      local_38 = uVar3 & 0x7fffffff;
      local_30 = (HKEY)0x0;
      local_2c = local_38;
      *(undefined4 *)(&stack0xffffffb4 + iVar1) = 0;
      *(undefined4 *)(&stack0xffffffb0 + iVar1) = 0;
      *(undefined4 *)(&stack0xffffffac + iVar1) = 0;
      *(undefined4 *)(&stack0xffffffa8 + iVar1) = 0;
      iVar4 = RegEnumKeyExW(local_34,0,lpName,&local_2c,*(LPDWORD *)(&stack0xffffffa8 + iVar1),
                            *(LPWSTR *)(&stack0xffffffac + iVar1),
                            *(LPDWORD *)(&stack0xffffffb0 + iVar1),
                            *(PFILETIME *)(&stack0xffffffb4 + iVar1));
      while (iVar4 == 0) {
        *(HKEY **)(&stack0xffffffa8 + iVar1) = &local_28;
        LVar2 = RegOpenKeyExW(local_34,lpName,0,0,*(PHKEY *)(&stack0xffffffa8 + iVar1));
        if (LVar2 == 0) {
          FUN_c02cf4fc(local_28);
          RegCloseKey(local_28);
        }
        dwIndex = (HKEY)((int)&local_30->unused + 1);
        local_30 = dwIndex;
        local_2c = local_38;
        *(undefined4 *)(&stack0xffffffb4 + iVar1) = 0;
        *(undefined4 *)(&stack0xffffffb0 + iVar1) = 0;
        *(undefined4 *)(&stack0xffffffac + iVar1) = 0;
        *(undefined4 *)(&stack0xffffffa8 + iVar1) = 0;
        iVar4 = RegEnumKeyExW(local_34,(DWORD)dwIndex,lpName,&local_2c,
                              *(LPDWORD *)(&stack0xffffffa8 + iVar1),
                              *(LPWSTR *)(&stack0xffffffac + iVar1),
                              *(LPDWORD *)(&stack0xffffffb0 + iVar1),
                              *(PFILETIME *)(&stack0xffffffb4 + iVar1));
      }
    }
    RegCloseKey(local_34);
  }
  FUN_c02d1074(local_20);
  return;
}



/* c02cfb0c FUN_c02cfb0c */

/* Boundary evidence: original MIPS .pdata c02cfb0c..c02cfb17. Semantic name remains unreviewed. */

undefined4 FUN_c02cfb0c(void)

{
  return 1;
}



/* c02cfb18 FUN_c02cfb18 */

/* Boundary evidence: original MIPS .pdata c02cfb18..c02cfb4f. Semantic name remains unreviewed. */

void FUN_c02cfb18(void)

{
  DAT_c02d2268 = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c02d2254);
  DAT_c02d2250 = 0x40;
  return;
}



/* c02cfb50 FUN_c02cfb50 */

/* Boundary evidence: original MIPS .pdata c02cfb50..c02cfb9f. Semantic name remains unreviewed. */

void FUN_c02cfb50(void)

{
  PmInit();
  return;
}



/* c02cfba0 FUN_c02cfba0 */

/* Boundary evidence: original MIPS .pdata c02cfba0..c02cfbab. Semantic name remains unreviewed. */

undefined4 FUN_c02cfba0(void)

{
  return 1;
}



/* c02cfbac FUN_c02cfbac */

/* Boundary evidence: original MIPS .pdata c02cfbac..c02cfc4f. Semantic name remains unreviewed. */

int FUN_c02cfbac(void)

{
  DWORD DVar1;
  
  if ((DAT_c02d226c == 0) &&
     (((DAT_c02d2270 != (HANDLE)0x0 ||
       (DAT_c02d2270 = OpenEventW(0x1f0003,0,L"SYSTEM/PowerManagerReady"),
       DAT_c02d2270 != (HANDLE)0x0)) && (DVar1 = WaitForSingleObject(DAT_c02d2270,0), DVar1 == 0))))
  {
    DAT_c02d226c = 1;
    CloseHandle(DAT_c02d2270);
    DAT_c02d2270 = (HANDLE)0x0;
  }
  return DAT_c02d226c;
}



/* c02cfc50 FUN_c02cfc50 */

/* Boundary evidence: original MIPS .pdata c02cfc50..c02cfc87. Semantic name remains unreviewed. */

void FUN_c02cfc50(void)

{
  PmNotify();
  return;
}



/* c02cfc88 FUN_c02cfc88 */

/* Boundary evidence: original MIPS .pdata c02cfc88..c02cfc93. Semantic name remains unreviewed. */

undefined4 FUN_c02cfc88(void)

{
  return 1;
}



/* c02cfc94 FUN_c02cfc94 */

/* Boundary evidence: original MIPS .pdata c02cfc94..c02cfdd3. Semantic name remains unreviewed. */

undefined4
FUN_c02cfc94(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3,STRSAFE_LPCWSTR param_4,
            undefined4 param_5)

{
  int iVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  wchar_t awStack_438 [260];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c02d2224;
  uVar4 = 0;
  if (param_1 != (STRSAFE_LPCWSTR)0x0) {
    StringCchCopyW(awStack_230,0x104,param_1);
  }
  if (param_4 != (STRSAFE_LPCWSTR)0x0) {
    StringCchCopyW(awStack_438,0x104,param_4);
  }
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    SetLastError(0x426);
  }
  else {
    pwVar3 = awStack_438;
    if (param_4 == (STRSAFE_LPCWSTR)0x0) {
      pwVar3 = (wchar_t *)0x0;
    }
    pwVar2 = awStack_230;
    if (param_1 == (STRSAFE_LPCWSTR)0x0) {
      pwVar2 = (wchar_t *)0x0;
    }
    uVar4 = PmSetPowerRequirement(pwVar2,param_2,param_3,pwVar3,param_5);
  }
  FUN_c02d1074(local_28);
  return uVar4;
}



/* c02cfdd4 FUN_c02cfdd4 */

/* Boundary evidence: original MIPS .pdata c02cfdd4..c02cfddf. Semantic name remains unreviewed. */

undefined4 FUN_c02cfdd4(void)

{
  return 1;
}



/* c02cfde0 FUN_c02cfde0 */

/* Boundary evidence: original MIPS .pdata c02cfde0..c02cfe63. Semantic name remains unreviewed. */

undefined4
FUN_c02cfde0(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3,STRSAFE_LPCWSTR param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = CeSetDirectCall(1);
  uVar2 = FUN_c02cfc94(param_1,param_2,param_3,param_4,param_5);
  CeSetDirectCall(uVar1);
  return uVar2;
}



/* c02cfe64 FUN_c02cfe64 */

/* Boundary evidence: original MIPS .pdata c02cfe64..c02cfedf. Semantic name remains unreviewed. */

undefined4 FUN_c02cfe64(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    uVar2 = 0x426;
  }
  else {
    uVar2 = PmReleasePowerRequirement(param_1,0);
  }
  return uVar2;
}



/* c02cfee0 FUN_c02cfee0 */

/* Boundary evidence: original MIPS .pdata c02cfee0..c02cfeeb. Semantic name remains unreviewed. */

undefined4 FUN_c02cfee0(void)

{
  return 1;
}



/* c02cfeec FUN_c02cfeec */

/* Boundary evidence: original MIPS .pdata c02cfeec..c02cff37. Semantic name remains unreviewed. */

undefined4 FUN_c02cfeec(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = CeSetDirectCall(1);
  uVar2 = FUN_c02cfe64(param_1);
  CeSetDirectCall(uVar1);
  return uVar2;
}



/* c02cff38 FUN_c02cff38 */

/* Boundary evidence: original MIPS .pdata c02cff38..c02d0063. Semantic name remains unreviewed. */

undefined4 FUN_c02cff38(STRSAFE_LPWSTR param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_230;
  undefined4 local_22c;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c02d2224;
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    uVar2 = 0x426;
  }
  else {
    if ((param_1 == (STRSAFE_LPWSTR)0x0) || (param_2 == 0)) {
      uVar2 = PmGetSystemPowerState(0,0,&local_230);
      local_22c = uVar2;
    }
    else {
      uVar2 = PmGetSystemPowerState(awStack_228,0x104,&local_230);
      if (0x103 < param_2) {
        param_2 = 0x104;
      }
      local_22c = uVar2;
      StringCchCopyW(param_1,param_2,awStack_228);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = local_230;
    }
  }
  FUN_c02d1074(local_20);
  return uVar2;
}



/* c02d0064 FUN_c02d0064 */

/* Boundary evidence: original MIPS .pdata c02d0064..c02d006f. Semantic name remains unreviewed. */

undefined4 FUN_c02d0064(void)

{
  return 1;
}



/* c02d0070 FUN_c02d0070 */

/* Boundary evidence: original MIPS .pdata c02d0070..c02d0153. Semantic name remains unreviewed. */

undefined4 FUN_c02d0070(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c02d2224;
  if (param_1 != (STRSAFE_LPCWSTR)0x0) {
    StringCchCopyW(awStack_228,0x104,param_1);
  }
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    uVar2 = 0x426;
  }
  else {
    pwVar3 = awStack_228;
    if (param_1 == (STRSAFE_LPCWSTR)0x0) {
      pwVar3 = (wchar_t *)0x0;
    }
    uVar2 = PmSetSystemPowerState(pwVar3,param_2,param_3);
  }
  FUN_c02d1074(local_20);
  return uVar2;
}



/* c02d0154 FUN_c02d0154 */

/* Boundary evidence: original MIPS .pdata c02d0154..c02d015f. Semantic name remains unreviewed. */

undefined4 FUN_c02d0154(void)

{
  return 1;
}



/* c02d0160 FUN_c02d0160 */

/* Boundary evidence: original MIPS .pdata c02d0160..c02d01f7. Semantic name remains unreviewed. */

undefined4 FUN_c02d0160(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    uVar2 = 0x426;
  }
  else {
    uVar2 = PmDevicePowerNotify(param_1,param_2,param_3);
  }
  return uVar2;
}



/* c02d01f8 FUN_c02d01f8 */

/* Boundary evidence: original MIPS .pdata c02d01f8..c02d0203. Semantic name remains unreviewed. */

undefined4 FUN_c02d01f8(void)

{
  return 1;
}



/* c02d0204 FUN_c02d0204 */

/* Boundary evidence: original MIPS .pdata c02d0204..c02d02e7. Semantic name remains unreviewed. */

undefined4 FUN_c02d0204(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c02d2224;
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    uVar2 = 0x426;
  }
  else {
    pwVar3 = awStack_228;
    if (param_1 == (STRSAFE_LPCWSTR)0x0) {
      pwVar3 = (wchar_t *)0x0;
    }
    else {
      StringCchCopyW(awStack_228,0x104,param_1);
    }
    uVar2 = PmDevicePowerNotify(pwVar3,param_2,param_3);
  }
  FUN_c02d1074(local_20);
  return uVar2;
}



/* c02d02e8 FUN_c02d02e8 */

/* Boundary evidence: original MIPS .pdata c02d02e8..c02d02f3. Semantic name remains unreviewed. */

undefined4 FUN_c02d02e8(void)

{
  return 1;
}



/* c02d02f4 FUN_c02d02f4 */

/* Boundary evidence: original MIPS .pdata c02d02f4..c02d03a3. Semantic name remains unreviewed. */

undefined4 FUN_c02d02f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    SetLastError(0x426);
  }
  else {
    uVar2 = PmRequestPowerNotifications(param_1,param_2);
  }
  return uVar2;
}



/* c02d03a4 FUN_c02d03a4 */

/* Boundary evidence: original MIPS .pdata c02d03a4..c02d03af. Semantic name remains unreviewed. */

undefined4 FUN_c02d03a4(void)

{
  return 1;
}



/* c02d03b0 FUN_c02d03b0 */

/* Boundary evidence: original MIPS .pdata c02d03b0..c02d040b. Semantic name remains unreviewed. */

undefined4 FUN_c02d03b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = CeSetDirectCall(1);
  uVar2 = FUN_c02d02f4(param_1,param_2,param_3,param_4);
  CeSetDirectCall(uVar1);
  return uVar2;
}



/* c02d040c FUN_c02d040c */

/* Boundary evidence: original MIPS .pdata c02d040c..c02d0483. Semantic name remains unreviewed. */

undefined4 FUN_c02d040c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    uVar2 = 0x426;
  }
  else {
    uVar2 = PmStopPowerNotifications(param_1);
  }
  return uVar2;
}



/* c02d0484 FUN_c02d0484 */

/* Boundary evidence: original MIPS .pdata c02d0484..c02d048f. Semantic name remains unreviewed. */

undefined4 FUN_c02d0484(void)

{
  return 1;
}



/* c02d0490 FUN_c02d0490 */

/* Boundary evidence: original MIPS .pdata c02d0490..c02d055f. Semantic name remains unreviewed. */

undefined4 FUN_c02d0490(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    SetLastError(0x426);
  }
  else {
    uVar2 = PmRegisterPowerRelationship(param_1,param_2,param_3,param_4,uVar3);
  }
  return uVar2;
}



/* c02d0560 FUN_c02d0560 */

/* Boundary evidence: original MIPS .pdata c02d0560..c02d056b. Semantic name remains unreviewed. */

undefined4 FUN_c02d0560(void)

{
  return 1;
}



/* c02d056c FUN_c02d056c */

/* Boundary evidence: original MIPS .pdata c02d056c..c02d0663. Semantic name remains unreviewed. */

undefined4 FUN_c02d056c(undefined4 param_1,undefined4 param_2,void *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_50 [48];
  
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    SetLastError(0x426);
    return 0;
  }
  if (param_3 != (void *)0x0) {
    memcpy(auStack_50,param_3,0x30);
    puVar3 = auStack_50;
    if (param_3 != (void *)0x0) goto LAB_c02d05e0;
  }
  puVar3 = (undefined1 *)0x0;
LAB_c02d05e0:
  uVar2 = PmRegisterPowerRelationship(param_1,param_2,puVar3,param_4);
  return uVar2;
}



/* c02d0664 FUN_c02d0664 */

/* Boundary evidence: original MIPS .pdata c02d0664..c02d066f. Semantic name remains unreviewed. */

undefined4 FUN_c02d0664(void)

{
  return 1;
}



/* c02d0670 FUN_c02d0670 */

/* Boundary evidence: original MIPS .pdata c02d0670..c02d06e7. Semantic name remains unreviewed. */

undefined4 FUN_c02d0670(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    uVar2 = 0x426;
  }
  else {
    uVar2 = PmReleasePowerRelationship(param_1);
  }
  return uVar2;
}



/* c02d06e8 FUN_c02d06e8 */

/* Boundary evidence: original MIPS .pdata c02d06e8..c02d06f3. Semantic name remains unreviewed. */

undefined4 FUN_c02d06e8(void)

{
  return 1;
}



/* c02d06f4 FUN_c02d06f4 */

/* Boundary evidence: original MIPS .pdata c02d06f4..c02d07d7. Semantic name remains unreviewed. */

undefined4 FUN_c02d06f4(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c02d2224;
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    uVar2 = 0x426;
  }
  else {
    pwVar3 = awStack_228;
    if (param_1 == (STRSAFE_LPCWSTR)0x0) {
      pwVar3 = (wchar_t *)0x0;
    }
    else {
      StringCchCopyW(awStack_228,0x104,param_1);
    }
    uVar2 = PmSetDevicePower(pwVar3,param_2,param_3);
  }
  FUN_c02d1074(local_20);
  return uVar2;
}



/* c02d07d8 FUN_c02d07d8 */

/* Boundary evidence: original MIPS .pdata c02d07d8..c02d07e3. Semantic name remains unreviewed. */

undefined4 FUN_c02d07d8(void)

{
  return 1;
}



/* c02d07e4 FUN_c02d07e4 */

/* Boundary evidence: original MIPS .pdata c02d07e4..c02d08c7. Semantic name remains unreviewed. */

undefined4 FUN_c02d07e4(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c02d2224;
  iVar1 = FUN_c02cfbac();
  if (iVar1 == 0) {
    uVar2 = 0x426;
  }
  else {
    pwVar3 = awStack_228;
    if (param_1 == (STRSAFE_LPCWSTR)0x0) {
      pwVar3 = (wchar_t *)0x0;
    }
    else {
      StringCchCopyW(awStack_228,0x104,param_1);
    }
    uVar2 = PmGetDevicePower(pwVar3,param_2,param_3);
  }
  FUN_c02d1074(local_20);
  return uVar2;
}



/* c02d08c8 FUN_c02d08c8 */

/* Boundary evidence: original MIPS .pdata c02d08c8..c02d08d3. Semantic name remains unreviewed. */

undefined4 FUN_c02d08c8(void)

{
  return 1;
}



/* c02d0dc4 FUN_c02d0dc4 */

/* Boundary evidence: original MIPS .pdata c02d0dc4..c02d0eff. Semantic name remains unreviewed. */

int FUN_c02d0dc4(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c02d2320 != (code *)0x0) {
      iVar2 = (*DAT_c02d2320)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c02d0e74;
    FUN_c02d12d4();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c02c2880(param_1,param_2);
  }
LAB_c02d0e74:
  if (((param_2 == 0) && (FUN_c02d125c(), iVar1 != 0)) && (DAT_c02d2320 != (code *)0x0)) {
    iVar1 = (*DAT_c02d2320)(param_1,0,param_3);
  }
  return iVar1;
}



/* c02d0f00 FUN_c02d0f00 */

/* Boundary evidence: original MIPS .pdata c02d0f00..c02d0f2b. Semantic name remains unreviewed. */

void FUN_c02d0f00(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c02d0f2c entry */

/* Boundary evidence: original MIPS .pdata c02d0f2c..c02d0f83. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c02d0f84();
  }
  FUN_c02d0dc4(param_1,param_2,param_3);
  return;
}



/* c02d0f84 FUN_c02d0f84 */

/* Boundary evidence: original MIPS .pdata c02d0f84..c02d0ff7. Semantic name remains unreviewed. */

void FUN_c02d0f84(void)

{
  uint uVar1;
  
  if ((DAT_c02d2224 == 0) || (DAT_c02d2224 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c02d2224 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c02d2224 == 0) {
      DAT_c02d2224 = 0xb064;
    }
  }
  DAT_c02d2228 = ~DAT_c02d2224;
  return;
}



/* c02d0ff8 FUN_c02d0ff8 */

/* Boundary evidence: original MIPS .pdata c02d0ff8..c02d1073. Semantic name remains unreviewed. */

void FUN_c02d0ff8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c02d10bc(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c02d1074 FUN_c02d1074 */

/* Boundary evidence: original MIPS .pdata c02d1074..c02d10bb. Semantic name remains unreviewed. */

void FUN_c02d1074(uint param_1)

{
  if ((param_1 == DAT_c02d2224) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c02d10bc FUN_c02d10bc */

/* Boundary evidence: original MIPS .pdata c02d10bc..c02d110f. Semantic name remains unreviewed. */

void FUN_c02d10bc(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c02d1074(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c02d1110 FUN_c02d1110 */

/* Boundary evidence: original MIPS .pdata c02d1110..c02d113b. Semantic name remains unreviewed. */

undefined4 FUN_c02d1110(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c02d10bc(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c02d113c FUN_c02d113c */

/* Boundary evidence: original MIPS .pdata c02d113c..c02d125b. Semantic name remains unreviewed. */

void FUN_c02d113c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c02d2274 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c02d2318;
    if (DAT_c02d2318 != (undefined4 *)0x0) {
      while (DAT_c02d2314 = DAT_c02d2314 + -1, _Memory <= DAT_c02d2314) {
        if ((code *)*DAT_c02d2314 != (code *)0x0) {
          (*(code *)*DAT_c02d2314)();
          _Memory = DAT_c02d2318;
        }
      }
      free(_Memory);
      DAT_c02d2314 = (undefined4 *)0x0;
      DAT_c02d2318 = (undefined4 *)0x0;
    }
    FUN_c02d1280((undefined4 *)&DAT_c02c1010,(undefined4 *)&DAT_c02c1014);
  }
  FUN_c02d1280((undefined4 *)&DAT_c02c1018,(undefined4 *)&DAT_c02c101c);
  if (param_3 == 0) {
    TerminateProcess(&DAT_00000042,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c02d231c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c02d125c FUN_c02d125c */

/* Boundary evidence: original MIPS .pdata c02d125c..c02d127f. Semantic name remains unreviewed. */

void FUN_c02d125c(void)

{
  FUN_c02d113c(0,0,1);
  return;
}



/* c02d1280 FUN_c02d1280 */

/* Boundary evidence: original MIPS .pdata c02d1280..c02d12d3. Semantic name remains unreviewed. */

void FUN_c02d1280(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c02d12d4 FUN_c02d12d4 */

/* Boundary evidence: original MIPS .pdata c02d12d4..c02d130f. Semantic name remains unreviewed. */

void FUN_c02d12d4(void)

{
  FUN_c02d1280((undefined4 *)&DAT_c02c1008,(undefined4 *)&DAT_c02c100c);
  FUN_c02d1280((undefined4 *)&DAT_c02c1000,(undefined4 *)&DAT_c02c1004);
  return;
}


