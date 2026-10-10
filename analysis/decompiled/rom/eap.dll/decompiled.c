/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c05d143c FUN_c05d143c */

/* Boundary evidence: original MIPS .pdata c05d143c..c05d14a7. Semantic name remains unreviewed. */

void FUN_c05d143c(void)

{
  if (DAT_c05d6120 == 0) {
    FUN_c05d1a34();
    FUN_c05d31ec();
    DAT_c05d60d4 = CxLogRegister(&DAT_c05d1048,&PTR_s_Plugin_c05d60c8,2,&DAT_c05d60d0);
    DAT_c05d6120 = 1;
  }
  return;
}



/* c05d14a8 FUN_c05d14a8 */

/* Boundary evidence: original MIPS .pdata c05d14a8..c05d150b. Semantic name remains unreviewed. */

void FUN_c05d14a8(void)

{
  if (DAT_c05d6120 != 0) {
    FUN_c05d1a60();
    FUN_c05d3214();
    CxLogDeregister(DAT_c05d60d4);
    DAT_c05d60d4 = 0xffffffff;
    DAT_c05d6120 = 0;
  }
  return;
}



/* c05d150c DllEntry */

/* Boundary evidence: original MIPS .pdata c05d150c..c05d1567. Semantic name remains unreviewed. */

undefined4 DllEntry(HMODULE param_1,int param_2)

{
                    /* 0x150c  1  DllEntry */
  if (param_2 == 0) {
    FUN_c05d14a8();
  }
  else if (param_2 == 1) {
    FUN_c05d143c();
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c05d1568 EapFreeConnectionData */

/* Boundary evidence: original MIPS .pdata c05d1568..c05d1583. Semantic name remains unreviewed. */

void EapFreeConnectionData(HLOCAL param_1)

{
                    /* 0x1568  3  EapFreeConnectionData */
  LocalFree(param_1);
  return;
}



/* c05d1584 EapInvokeInteractiveUI */

/* Boundary evidence: original MIPS .pdata c05d1584..c05d16b3. Semantic name remains unreviewed. */

int EapInvokeInteractiveUI
              (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  HMODULE local_e88;
  code *local_e84;
  undefined1 auStack_e80 [8];
  uint auStack_e78 [131];
  undefined1 auStack_c6c [2620];
  wchar_t awStack_230 [260];
  uint local_28;
  
                    /* 0x1584  5  EapInvokeInteractiveUI */
  local_28 = DAT_c05d6114;
  local_e88 = (HMODULE)0x0;
  swprintf(awStack_230,0xc05d10a4,L"Comm\\EAP\\Extension",param_1);
  iVar1 = FUN_c05d4824((HKEY)0x80000002,awStack_230,param_1,auStack_e78);
  if (iVar1 == 0) {
    iVar1 = CXUtilGetProcAddresses
                      (auStack_c6c,&local_e88,L"RasEapInvokeInteractiveUI",&local_e84,
                       L"RasEapFreeMemory",auStack_e80,0);
    if (iVar1 == 0) {
      iVar1 = (*local_e84)(param_1,param_2,param_3,param_4,param_5,param_6);
      FreeLibrary(local_e88);
    }
  }
  FUN_c05d5580(local_28);
  return iVar1;
}



/* c05d16b4 FUN_c05d16b4 */

/* Boundary evidence: original MIPS .pdata c05d16b4..c05d173b. Semantic name remains unreviewed. */

int FUN_c05d16b4(int param_1)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6160);
  piVar1 = (int *)DAT_c05d6124;
  do {
    if (piVar1 == (int *)0x0) {
LAB_c05d1718:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6160);
      return (int)piVar1;
    }
    if (piVar1[0x317] == param_1) {
      piVar1[1] = piVar1[1] + 1;
      goto LAB_c05d1718;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}



/* c05d173c FUN_c05d173c */

/* Boundary evidence: original MIPS .pdata c05d173c..c05d17ef. Semantic name remains unreviewed. */

void FUN_c05d173c(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_1[1];
  param_1[1] = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6160);
    piVar1 = &DAT_c05d6124;
    do {
      piVar3 = piVar1;
      if (*piVar3 == 0) goto LAB_c05d17d4;
      piVar1 = (int *)*piVar3;
    } while ((int *)*piVar3 != param_1);
    *piVar3 = *param_1;
    if ((code *)param_1[0x318] != (code *)0x0) {
      (*(code *)param_1[0x318])(0);
    }
    FreeLibrary((HMODULE)param_1[0x315]);
    LocalFree(param_1);
LAB_c05d17d4:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6160);
  }
  return;
}



/* c05d17f0 FUN_c05d17f0 */

/* Boundary evidence: original MIPS .pdata c05d17f0..c05d19ab. Semantic name remains unreviewed. */

undefined4 * FUN_c05d17f0(uint param_1)

{
  undefined4 *_Dst;
  int iVar1;
  HMODULE pHVar2;
  DWORD DVar3;
  code *pcVar4;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c05d6114;
  if ((param_1 < 4) || (0xff < param_1)) {
    FUN_c05d5580(DAT_c05d6114);
    return (undefined4 *)0x0;
  }
  _Dst = LocalAlloc(0x40,0xc70);
  if (_Dst == (undefined4 *)0x0) goto LAB_c05d1978;
  memset(_Dst,0,0xc70);
  _Dst[1] = 1;
  swprintf(awStack_220,0xc05d10a4,L"Comm\\EAP\\Extension",param_1);
  iVar1 = FUN_c05d4824((HKEY)0x80000002,awStack_220,param_1,_Dst + 2);
  if (iVar1 == 0) {
    pHVar2 = LoadLibraryW((LPCWSTR)(_Dst + 3));
    _Dst[0x315] = pHVar2;
    if (pHVar2 == (HMODULE)0x0) {
      DVar3 = GetLastError();
    }
    else {
      pcVar4 = (code *)GetProcAddressW(pHVar2,L"RasEapGetInfo");
      if (pcVar4 == (code *)0x0) {
        DVar3 = GetLastError();
LAB_c05d1948:
        if (DVar3 == 0) goto LAB_c05d1978;
      }
      else {
        _Dst[0x316] = 0x18;
        _Dst[0x317] = param_1;
        DVar3 = (*pcVar4)(param_1);
        if ((DVar3 == 0) &&
           (((code *)_Dst[0x318] == (code *)0x0 || (DVar3 = (*(code *)_Dst[0x318])(1), DVar3 == 0)))
           ) {
          *_Dst = DAT_c05d6124;
          DAT_c05d6124 = _Dst;
          goto LAB_c05d1948;
        }
      }
      FreeLibrary((HMODULE)_Dst[0x315]);
      _Dst[0x315] = 0;
    }
    if (DVar3 == 0) goto LAB_c05d1978;
  }
  LocalFree(_Dst);
  _Dst = (undefined4 *)0x0;
LAB_c05d1978:
  FUN_c05d5580(local_18);
  return _Dst;
}



/* c05d19ac FUN_c05d19ac */

/* Boundary evidence: original MIPS .pdata c05d19ac..c05d1a17. Semantic name remains unreviewed. */

undefined4 * FUN_c05d19ac(uint param_1)

{
  undefined4 *puVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6160);
  puVar1 = (undefined4 *)FUN_c05d16b4(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = FUN_c05d17f0(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6160);
  return puVar1;
}



/* c05d1a18 FUN_c05d1a18 */

/* Boundary evidence: original MIPS .pdata c05d1a18..c05d1a33. Semantic name remains unreviewed. */

void FUN_c05d1a18(int *param_1)

{
  FUN_c05d173c(param_1);
  return;
}



/* c05d1a34 FUN_c05d1a34 */

/* Boundary evidence: original MIPS .pdata c05d1a34..c05d1a5f. Semantic name remains unreviewed. */

undefined4 FUN_c05d1a34(void)

{
  DAT_c05d6124 = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6160);
  return 0;
}



/* c05d1a60 FUN_c05d1a60 */

/* Boundary evidence: original MIPS .pdata c05d1a60..c05d1a83. Semantic name remains unreviewed. */

undefined4 FUN_c05d1a60(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6160);
  return 0;
}



/* c05d1a84 EapInvokeConfigUI */

/* Boundary evidence: original MIPS .pdata c05d1a84..c05d1bcf. Semantic name remains unreviewed. */

int EapInvokeConfigUI(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 *param_6,SIZE_T *param_7)

{
  int *piVar1;
  HLOCAL _Dst;
  int iVar2;
  void *local_30;
  HMODULE local_2c;
  code *local_28;
  code *local_24;
  
                    /* 0x1a84  4  EapInvokeConfigUI */
  local_2c = (HMODULE)0x0;
  iVar2 = 0x490;
  piVar1 = FUN_c05d19ac(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = CXUtilGetProcAddresses
                      (piVar1 + 0x189,&local_2c,L"RasEapInvokeConfigUI",&local_28,
                       L"RasEapFreeMemory",&local_24,0);
    if (iVar2 == 0) {
      iVar2 = (*local_28)(param_1,param_2,param_3,param_4,param_5,&local_30,param_7);
      if (iVar2 == 0) {
        _Dst = LocalAlloc(0x40,*param_7);
        *param_6 = _Dst;
        if (_Dst == (HLOCAL)0x0) {
          iVar2 = 0xe;
        }
        else {
          memcpy(_Dst,local_30,*param_7);
          iVar2 = 0;
        }
        (*local_24)(local_30);
      }
      FreeLibrary(local_2c);
    }
    FUN_c05d173c(piVar1);
  }
  return iVar2;
}



/* c05d1bd0 FUN_c05d1bd0 */

/* Boundary evidence: original MIPS .pdata c05d1bd0..c05d1c8b. Semantic name remains unreviewed. */

undefined4 FUN_c05d1bd0(undefined4 param_1,undefined4 param_2)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"WaitForAPIReady");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c05d1c8c FUN_c05d1c8c */

/* Boundary evidence: original MIPS .pdata c05d1c8c..c05d1d7b. Semantic name remains unreviewed. */

undefined4
FUN_c05d1c8c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"CeCallUserProc");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c05d1d7c FUN_c05d1d7c */

/* Boundary evidence: original MIPS .pdata c05d1d7c..c05d1edf. Semantic name remains unreviewed. */

undefined4 FUN_c05d1d7c(undefined4 param_1,void *param_2,uint *param_3)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 local_5d8 [2];
  DWORD local_5d0;
  undefined4 local_5cc;
  undefined1 auStack_5c8 [1456];
  uint local_18;
  uint local_14;
  
  local_14 = DAT_c05d6114;
  local_5d8[0] = 0;
  local_5d0 = 0;
  local_18 = (uint)(param_3 != (uint *)0x0);
  local_5cc = param_1;
  memcpy(auStack_5c8,param_2,0x5b0);
  iVar1 = FUN_c05d1bd0(0x51,60000);
  if (iVar1 == 0) {
    iVar1 = FUN_c05d1c8c(L"netui.dll",L"GetUsernamePasswordExExt",&local_5d0,0x5bc,&local_5d0,0x5bc,
                         local_5d8);
    if (iVar1 == 0) {
      dwErrCode = GetLastError();
      if (dwErrCode == 0) {
        dwErrCode = 0x57;
      }
    }
    else {
      dwErrCode = local_5d0;
      if (local_5d0 == 0) {
        memcpy(param_2,auStack_5c8,0x5b0);
        if (param_3 != (uint *)0x0) {
          *param_3 = local_18;
        }
        SetLastError(0);
        FUN_c05d5580(local_14);
        return 1;
      }
    }
  }
  else {
    dwErrCode = GetLastError();
    if (dwErrCode == 0) {
      dwErrCode = 0x1f;
    }
  }
  SetLastError(dwErrCode);
  FUN_c05d5580(local_14);
  return 0;
}



/* c05d1ee0 FUN_c05d1ee0 */

/* Boundary evidence: original MIPS .pdata c05d1ee0..c05d1f7f. Semantic name remains unreviewed. */

undefined4 FUN_c05d1ee0(undefined4 param_1)

{
  int iVar1;
  undefined4 local_18 [2];
  DWORD local_10;
  undefined4 local_c;
  
  local_18[0] = 0;
  local_10 = 0;
  local_c = param_1;
  iVar1 = FUN_c05d1bd0(0x51,60000);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_c05d1c8c(L"netui.dll",L"CloseUsernamePasswordDialogExt",&local_10,8,&local_10,8,
                           local_18), iVar1 != 0)) {
    if (local_10 == 0) {
      return 1;
    }
    SetLastError(local_10);
  }
  return 0;
}



/* c05d1f80 FUN_c05d1f80 */

/* Boundary evidence: original MIPS .pdata c05d1f80..c05d202f. Semantic name remains unreviewed. */

int FUN_c05d1f80(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1c) = 0x4c;
  *(undefined1 *)(param_1 + 0x30) = *(undefined1 *)(param_1 + 0x100);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x10c);
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x110);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x114);
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x118);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x11c);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x120);
  if ((*(int *)(param_1 + 0xb0) == 0) && (*(int *)(*(int *)(param_1 + 0xa8) + 0xc64) != 0)) {
    if (*(int *)(param_1 + 0x11c) == 0) {
      iVar1 = 0x3ea;
    }
    else {
      *(undefined4 *)(param_1 + 0xb0) = 1;
      iVar1 = (**(code **)(*(int *)(param_1 + 0xa8) + 0xc64))((undefined4 *)(param_1 + 0xac));
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0xac) = 0;
      }
    }
  }
  return iVar1;
}



/* c05d2030 FUN_c05d2030 */

/* Boundary evidence: original MIPS .pdata c05d2030..c05d2097. Semantic name remains unreviewed. */

void FUN_c05d2030(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xa8);
  if (piVar1 != (int *)0x0) {
    if ((*(int *)(param_1 + 0xac) != 0) && ((code *)piVar1[0x31a] != (code *)0x0)) {
      (*(code *)piVar1[0x31a])();
    }
    FUN_c05d1a18(piVar1);
    *(undefined4 *)(param_1 + 0xa8) = 0;
    *(undefined4 *)(param_1 + 0xac) = 0;
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  return;
}



/* c05d2098 FUN_c05d2098 */

/* Boundary evidence: original MIPS .pdata c05d2098..c05d210b. Semantic name remains unreviewed. */

undefined4 FUN_c05d2098(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*(int *)(param_1 + 0xa8) == 0) || (*(uint *)(*(int *)(param_1 + 0xa8) + 0xc5c) != param_2)) {
    FUN_c05d2030(param_1);
    puVar1 = FUN_c05d19ac(param_2);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0x490;
    }
    else {
      *(undefined4 **)(param_1 + 0xa8) = puVar1;
    }
  }
  return uVar2;
}



/* c05d210c FUN_c05d210c */

/* Boundary evidence: original MIPS .pdata c05d210c..c05d2197. Semantic name remains unreviewed. */

undefined4 FUN_c05d210c(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6140);
  piVar1 = (int *)DAT_c05d6128;
  do {
    if (piVar1 == (int *)0x0) {
LAB_c05d2174:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6140);
      return uVar2;
    }
    if (piVar1 == (int *)param_1) {
      piVar1[1] = piVar1[1] + 1;
      uVar2 = 1;
      goto LAB_c05d2174;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}



/* c05d2198 FUN_c05d2198 */

/* Boundary evidence: original MIPS .pdata c05d2198..c05d21df. Semantic name remains unreviewed. */

void FUN_c05d2198(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x144) != 0) && (iVar1 = CTECancelEvent(param_1 + 0x128), iVar1 != 0)) {
    *(undefined4 *)(param_1 + 0x144) = 0;
    FUN_c05d21e0((int *)param_1);
  }
  return;
}



/* c05d21e0 FUN_c05d21e0 */

/* Boundary evidence: original MIPS .pdata c05d21e0..c05d22db. Semantic name remains unreviewed. */

void FUN_c05d21e0(int *param_1)

{
  int *piVar1;
  size_t sVar2;
  int iVar3;
  int *piVar4;
  wchar_t *_Str;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6140);
  iVar3 = param_1[1];
  param_1[1] = iVar3 + -1;
  if (iVar3 + -1 == 0) {
    piVar1 = &DAT_c05d6128;
    do {
      piVar4 = piVar1;
      if (*piVar4 == 0) goto LAB_c05d22bc;
      piVar1 = (int *)*piVar4;
    } while ((int *)*piVar4 != param_1);
    *piVar4 = *param_1;
    FUN_c05d2198((int)param_1);
    FUN_c05d34a0((int)param_1);
    FUN_c05d2030((int)param_1);
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    LocalFree((HLOCAL)param_1[0x43]);
    LocalFree((HLOCAL)param_1[0x45]);
    LocalFree((HLOCAL)param_1[0x47]);
    _Str = (wchar_t *)param_1[0x48];
    if (_Str != (wchar_t *)0x0) {
      sVar2 = wcslen(_Str);
      memset(_Str,0,sVar2 << 1);
      LocalFree((HLOCAL)param_1[0x48]);
    }
    LocalFree(param_1);
  }
LAB_c05d22bc:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6140);
  return;
}



/* c05d22dc EapSessionSetConnectionData */

/* Boundary evidence: original MIPS .pdata c05d22dc..c05d2383. Semantic name remains unreviewed. */

undefined4 EapSessionSetConnectionData(int *param_1,void *param_2,SIZE_T param_3)

{
  int iVar1;
  HLOCAL _Dst;
  undefined4 uVar2;
  
                    /* 0x22dc  14  EapSessionSetConnectionData */
  uVar2 = 0x57;
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 != 0) {
    uVar2 = 0;
    LocalFree((HLOCAL)param_1[0x43]);
    param_1[0x43] = 0;
    param_1[0x44] = 0;
    if (param_3 != 0) {
      _Dst = LocalAlloc(0x40,param_3);
      param_1[0x43] = (int)_Dst;
      if (_Dst == (HLOCAL)0x0) {
        uVar2 = 8;
      }
      else {
        memcpy(_Dst,param_2,param_3);
        param_1[0x44] = param_3;
      }
    }
    FUN_c05d21e0(param_1);
  }
  return uVar2;
}



/* c05d2384 EapSessionSetUserData */

/* Boundary evidence: original MIPS .pdata c05d2384..c05d242b. Semantic name remains unreviewed. */

undefined4 EapSessionSetUserData(int *param_1,void *param_2,SIZE_T param_3)

{
  int iVar1;
  HLOCAL _Dst;
  undefined4 uVar2;
  
                    /* 0x2384  17  EapSessionSetUserData */
  uVar2 = 0x57;
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 != 0) {
    uVar2 = 0;
    LocalFree((HLOCAL)param_1[0x45]);
    param_1[0x45] = 0;
    param_1[0x46] = 0;
    if (param_3 != 0) {
      _Dst = LocalAlloc(0x40,param_3);
      param_1[0x45] = (int)_Dst;
      if (_Dst == (HLOCAL)0x0) {
        uVar2 = 8;
      }
      else {
        memcpy(_Dst,param_2,param_3);
        param_1[0x46] = param_3;
      }
    }
    FUN_c05d21e0(param_1);
  }
  return uVar2;
}



/* c05d242c EapSessionSetIdentity */

/* Boundary evidence: original MIPS .pdata c05d242c..c05d24bf. Semantic name remains unreviewed. */

undefined4 EapSessionSetIdentity(int *param_1,wchar_t *param_2)

{
  int iVar1;
  size_t sVar2;
  wchar_t *_Dest;
  undefined4 uVar3;
  
                    /* 0x242c  15  EapSessionSetIdentity */
  uVar3 = 0x57;
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 != 0) {
    uVar3 = 0;
    LocalFree((HLOCAL)param_1[0x47]);
    sVar2 = wcslen(param_2);
    _Dest = LocalAlloc(0x40,(sVar2 + 1) * 2);
    param_1[0x47] = (int)_Dest;
    if (_Dest == (wchar_t *)0x0) {
      uVar3 = 8;
    }
    else {
      wcscpy(_Dest,param_2);
    }
    FUN_c05d21e0(param_1);
  }
  return uVar3;
}



/* c05d24c0 EapSessionSetPassword */

/* Boundary evidence: original MIPS .pdata c05d24c0..c05d2553. Semantic name remains unreviewed. */

undefined4 EapSessionSetPassword(int *param_1,wchar_t *param_2)

{
  int iVar1;
  size_t sVar2;
  wchar_t *_Dest;
  undefined4 uVar3;
  
                    /* 0x24c0  16  EapSessionSetPassword */
  uVar3 = 0x57;
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 != 0) {
    uVar3 = 0;
    LocalFree((HLOCAL)param_1[0x48]);
    sVar2 = wcslen(param_2);
    _Dest = LocalAlloc(0x40,(sVar2 + 1) * 2);
    param_1[0x48] = (int)_Dest;
    if (_Dest == (wchar_t *)0x0) {
      uVar3 = 8;
    }
    else {
      wcscpy(_Dest,param_2);
    }
    FUN_c05d21e0(param_1);
  }
  return uVar3;
}



/* c05d2554 FUN_c05d2554 */

/* Boundary evidence: original MIPS .pdata c05d2554..c05d27cb. Semantic name remains unreviewed. */

undefined4
FUN_c05d2554(int param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
            STRSAFE_LPCWSTR param_5,int *param_6)

{
  wchar_t *pwVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  wchar_t *pwVar5;
  undefined *puVar6;
  undefined4 uVar7;
  wchar_t awStack_5e0 [257];
  wchar_t awStack_3de [257];
  wchar_t local_1dc [16];
  uint local_1bc;
  uint local_30;
  
  local_30 = DAT_c05d6114;
  uVar7 = 0;
  memset(awStack_5e0,0,0x5b0);
  pwVar1 = wcschr(param_4,L'\\');
  pwVar5 = param_4;
  if (pwVar1 != (wchar_t *)0x0) {
    StringCchCopyNW(local_1dc,0x10,param_4,(int)pwVar1 - (int)param_4 >> 1);
    pwVar5 = pwVar1 + 1;
  }
  StringCchCopyW(awStack_5e0,0x101,pwVar5);
  if (param_5 == (STRSAFE_LPCWSTR)0x0) {
    local_1bc = local_1bc | 8;
  }
  else {
    local_1bc = local_1bc | 2;
    StringCchCopyW(awStack_3de,0x101,param_5);
    if (*param_6 != 0) {
      local_1bc = local_1bc | 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  iVar2 = FUN_c05d1d7c(param_2,awStack_5e0,(uint *)(param_1 + 0x14c));
  *(uint *)(param_1 + 0x14c) = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if (iVar2 == 0) {
    uVar7 = 0x4c7;
    goto LAB_c05d2790;
  }
  LocalFree(*(HLOCAL *)(param_1 + 0x11c));
  sVar3 = wcslen(local_1dc);
  sVar4 = wcslen(awStack_5e0);
  pwVar5 = LocalAlloc(0x40,(sVar4 + sVar3 + 2) * 2);
  *(wchar_t **)(param_1 + 0x11c) = pwVar5;
  if (pwVar5 != (wchar_t *)0x0) {
    if (local_1dc[0] == L'\0') {
      puVar6 = &DAT_c05d1214;
    }
    else {
      puVar6 = &DAT_c05d1218;
    }
    swprintf(pwVar5,0xc05d1204,local_1dc,puVar6,awStack_5e0);
    wcscpy(param_4,*(wchar_t **)(param_1 + 0x11c));
    if (param_5 == (STRSAFE_LPCWSTR)0x0) goto LAB_c05d2790;
    pwVar5 = *(wchar_t **)(param_1 + 0x120);
    if (pwVar5 != (wchar_t *)0x0) {
      sVar3 = wcslen(pwVar5);
      memset(pwVar5,0,sVar3 << 1);
      LocalFree(*(HLOCAL *)(param_1 + 0x120));
    }
    sVar3 = wcslen(awStack_3de);
    pwVar5 = LocalAlloc(0x40,(sVar3 + 1) * 2);
    *(wchar_t **)(param_1 + 0x120) = pwVar5;
    if (pwVar5 != (wchar_t *)0x0) {
      wcscpy(pwVar5,awStack_3de);
      if ((local_1bc & 1) == 0) {
        *param_6 = 0;
      }
      else {
        wcscpy(param_5,*(wchar_t **)(param_1 + 0x120));
        *param_6 = 1;
      }
      goto LAB_c05d2790;
    }
  }
  uVar7 = 0xe;
LAB_c05d2790:
  FUN_c05d5580(local_30);
  return uVar7;
}



/* c05d27cc FUN_c05d27cc */

/* Boundary evidence: original MIPS .pdata c05d27cc..c05d29c3. Semantic name remains unreviewed. */

int FUN_c05d27cc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  HLOCAL _Dst;
  size_t sVar2;
  wchar_t *_Dest;
  wchar_t *local_30;
  SIZE_T local_2c;
  void *local_28;
  code *local_24;
  HMODULE local_20;
  code *local_1c;
  
  local_20 = (HMODULE)0x0;
  local_28 = (void *)0x0;
  local_2c = 0;
  local_30 = (wchar_t *)0x0;
  iVar1 = CXUtilGetProcAddresses
                    (*(int *)(param_1 + 0xa8) + 0x41c,&local_20,L"RasEapGetIdentity",&local_1c,
                     L"RasEapFreeMemory",&local_24,0);
  if (iVar1 == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    iVar1 = (*local_1c)(*(undefined1 *)(param_1 + 0xc4),param_2,0,0,param_3,
                        *(undefined4 *)(param_1 + 0x10c),*(undefined4 *)(param_1 + 0x110),
                        *(undefined4 *)(param_1 + 0x114),*(undefined4 *)(param_1 + 0x118),&local_28,
                        &local_2c,&local_30);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    if (iVar1 == 0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x114));
      *(undefined4 *)(param_1 + 0x114) = 0;
      *(undefined4 *)(param_1 + 0x118) = 0;
      LocalFree(*(HLOCAL *)(param_1 + 0x11c));
      *(undefined4 *)(param_1 + 0x11c) = 0;
      if (local_2c != 0) {
        _Dst = LocalAlloc(0x40,local_2c);
        *(HLOCAL *)(param_1 + 0x114) = _Dst;
        if (_Dst == (HLOCAL)0x0) {
          iVar1 = 8;
        }
        else {
          memcpy(_Dst,local_28,local_2c);
          *(SIZE_T *)(param_1 + 0x118) = local_2c;
        }
      }
      if ((local_30 != (wchar_t *)0x0) && (iVar1 == 0)) {
        sVar2 = wcslen(local_30);
        _Dest = LocalAlloc(0x40,(sVar2 + 1) * 2);
        *(wchar_t **)(param_1 + 0x11c) = _Dest;
        if (_Dest == (wchar_t *)0x0) {
          iVar1 = 8;
        }
        else {
          wcscpy(_Dest,local_30);
        }
      }
      if (local_28 != (void *)0x0) {
        (*local_24)(local_28);
      }
      if (local_30 != (wchar_t *)0x0) {
        (*local_24)();
      }
    }
    FreeLibrary(local_20);
  }
  return iVar1;
}



/* c05d29c4 EapSessionGetIdentity */

/* Boundary evidence: original MIPS .pdata c05d29c4..c05d2c83. Semantic name remains unreviewed. */

int EapSessionGetIdentity
              (int *param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
              STRSAFE_LPCWSTR param_5,int param_6,int *param_7,undefined4 *param_8)

{
  int iVar1;
  int iVar2;
  wchar_t *pwVar3;
  wchar_t *_Source;
  int *piVar4;
  wchar_t *_Str1;
  wchar_t local_458 [260];
  wchar_t awStack_250 [274];
  uint local_2c;
  
                    /* 0x29c4  8  EapSessionGetIdentity */
  local_2c = DAT_c05d6114;
  iVar2 = 0x57;
  *param_8 = 0;
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 == 0) goto LAB_c05d2c04;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  iVar2 = FUN_c05d2098((int)param_1,(uint)*(byte *)(param_1 + 0x31));
  if (iVar2 == 0) {
    iVar1 = param_1[0x2a];
    iVar2 = EapSessionSetIdentity(param_1,param_4);
    if (iVar2 == 0) {
      piVar4 = param_1 + 0x49;
      *piVar4 = *param_7;
      if ((*param_7 == 0) || (iVar2 = EapSessionSetPassword(param_1,param_5), iVar2 == 0)) {
        pwVar3 = (wchar_t *)param_1[0x47];
        wcscpy(awStack_250,pwVar3);
        _Source = (wchar_t *)param_1[0x48];
        _Str1 = (wchar_t *)0x0;
        if (_Source != (wchar_t *)0x0) {
          wcscpy(local_458,_Source);
          _Str1 = local_458;
        }
        if (((param_6 == 0) && (*pwVar3 != L'\0')) &&
           ((*(int *)(iVar1 + 0xa44) == 0 || (_Source != (wchar_t *)0x0)))) {
          wcscpy(param_4,pwVar3);
          pwVar3 = (wchar_t *)param_1[0x48];
          param_4 = param_5;
          if (pwVar3 != (wchar_t *)0x0) {
LAB_c05d2bac:
            wcscpy(param_4,pwVar3);
          }
        }
        else {
          if ((param_1[8] & 2U) == 0) {
            if ((*(int *)(iVar1 + 0xa40) == 0) && (*(int *)(iVar1 + 0xa44) == 0)) {
              iVar2 = FUN_c05d27cc((int)param_1,param_2,param_3);
            }
            else {
              if (*(int *)(iVar1 + 0xa44) == 0) {
                param_5 = (STRSAFE_LPCWSTR)0x0;
              }
              iVar2 = FUN_c05d2554((int)param_1,param_2,param_3,param_4,param_5,piVar4);
            }
            if (iVar2 == 0) {
              pwVar3 = (wchar_t *)param_1[0x47];
              goto LAB_c05d2bac;
            }
            goto LAB_c05d2bf4;
          }
          iVar2 = 0x2bf;
        }
        iVar1 = wcscmp(awStack_250,(wchar_t *)param_1[0x47]);
        if (iVar1 == 0) {
          if (_Str1 == (wchar_t *)0x0) {
            if (param_1[0x48] != 0) goto LAB_c05d2bdc;
          }
          else {
            if ((wchar_t *)param_1[0x48] == (wchar_t *)0x0) goto LAB_c05d2bdc;
            iVar1 = wcscmp(_Str1,(wchar_t *)param_1[0x48]);
            if (iVar1 != 0) {
              *param_8 = 1;
            }
          }
        }
        else {
LAB_c05d2bdc:
          *param_8 = 1;
        }
        *param_7 = *piVar4;
      }
    }
  }
LAB_c05d2bf4:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  FUN_c05d21e0(param_1);
LAB_c05d2c04:
  iVar1 = 0x202;
  pwVar3 = local_458;
  do {
    *(undefined1 *)pwVar3 = 0;
    iVar1 = iVar1 + -1;
    pwVar3 = (wchar_t *)((int)pwVar3 + 1);
  } while (iVar1 != 0);
  FUN_c05d5580(local_2c);
  return iVar2;
}



/* c05d2c84 EapSessionCreate */

/* Boundary evidence: original MIPS .pdata c05d2c84..c05d2e0b. Semantic name remains unreviewed. */

undefined4 *
EapSessionCreate(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,uint param_5,
                uint param_6,int param_7)

{
  undefined4 *_Dst;
  int iVar1;
  
                    /* 0x2c84  6  EapSessionCreate */
  if ((((4 < param_5) && (param_5 < 0xffff)) && (param_6 < 0xffff)) && (3 < param_4)) {
    if (param_3 == 0) {
      iVar1 = *(int *)(param_7 + 4);
    }
    else {
      iVar1 = *(int *)(param_7 + 0x10);
    }
    if (iVar1 != 0) {
      _Dst = LocalAlloc(0x40,param_5 + param_6 + 0x150);
      if (_Dst == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      memset(_Dst,0,0x150);
      _Dst[1] = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 2));
      *(char *)(_Dst + 0x31) = (char)param_4;
      _Dst[7] = 0x4c;
      _Dst[0x3e] = 0xffffffff;
      _Dst[0x3f] = 0xffffffff;
      _Dst[8] = param_2;
      _Dst[9] = param_3;
      _Dst[0x2d] = param_1;
      _Dst[0x2e] = param_5;
      _Dst[0x2f] = param_6;
      _Dst[0x30] = param_7;
      _Dst[0x41] = (int)_Dst + param_6 + 0x150;
      CTEInitTimer(_Dst + 0x33);
      _Dst[0x3b] = 5000;
      _Dst[0x3c] = 10;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6140);
      *_Dst = DAT_c05d6128;
      DAT_c05d6128 = _Dst;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6140);
      return _Dst;
    }
  }
  return (undefined4 *)0x0;
}



/* c05d2e20 EapSessionDestroy */

/* Boundary evidence: original MIPS .pdata c05d2e20..c05d2e7f. Semantic name remains unreviewed. */

void EapSessionDestroy(int *param_1)

{
  int iVar1;
  
                    /* 0x2e20  7  EapSessionDestroy */
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 != 0) {
    param_1[0x30] = (int)&DAT_c05d60d8;
    if (param_1[0x53] != 0) {
      FUN_c05d1ee0(param_1[0x53]);
      param_1[0x53] = 0;
    }
    FUN_c05d21e0(param_1);
    FUN_c05d21e0(param_1);
  }
  return;
}



/* c05d2e80 EapSessionReset */

/* Boundary evidence: original MIPS .pdata c05d2e80..c05d2f3f. Semantic name remains unreviewed. */

undefined4 EapSessionReset(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x2e80  11  EapSessionReset */
  uVar2 = 0x57;
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c05d2030((int)param_1);
    FUN_c05d3234((int)param_1,0);
    FUN_c05d34a0((int)param_1);
    param_1[0x3e] = -1;
    param_1[0x3f] = -1;
    if (param_1[9] != 0) {
      LocalFree((HLOCAL)param_1[0x47]);
      param_1[0x47] = 0;
    }
    FUN_c05d2198((int)param_1);
    if ((HLOCAL)param_1[0x52] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[0x52]);
      param_1[0x52] = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c05d21e0(param_1);
    uVar2 = 0;
  }
  return uVar2;
}



/* c05d2f40 FUN_c05d2f40 */

/* Boundary evidence: original MIPS .pdata c05d2f40..c05d2fe7. Semantic name remains unreviewed. */

int FUN_c05d2f40(int param_1,undefined4 param_2)

{
  int iVar1;
  HMODULE local_18;
  code *local_14;
  
  local_18 = (HMODULE)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if (*(int *)(param_1 + 0xa8) == 0) {
    iVar1 = 0x57;
  }
  else {
    iVar1 = CXUtilGetProcAddresses
                      (*(int *)(param_1 + 0xa8) + 0x214,&local_18,L"RasEapFreeMemory",&local_14,0);
    if (iVar1 == 0) {
      (*local_14)(param_2);
      FreeLibrary(local_18);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return iVar1;
}



/* c05d2fe8 EapSessionSendIdentityRequest */

/* Boundary evidence: original MIPS .pdata c05d2fe8..c05d306f. Semantic name remains unreviewed. */

void EapSessionSendIdentityRequest(int *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
                    /* 0x2fe8  13  EapSessionSendIdentityRequest */
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    if (param_1[9] != 0) {
      FUN_c05d42d8(param_1,param_2,param_3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c05d21e0(param_1);
  }
  return;
}



/* c05d3070 EapSessionProcessRxPacket */

/* Boundary evidence: original MIPS .pdata c05d3070..c05d30ff. Semantic name remains unreviewed. */

void EapSessionProcessRxPacket(int *param_1,byte *param_2,uint param_3)

{
  int iVar1;
  undefined4 auStack_30 [6];
  
                    /* 0x3070  10  EapSessionProcessRxPacket */
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    iVar1 = FUN_c05d4364(param_2,param_3,auStack_30);
    if (iVar1 != 0) {
      FUN_c05d411c(param_1,auStack_30);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c05d21e0(param_1);
  }
  return;
}



/* c05d3100 EapSessionRxImpliedSuccessPacket */

/* Boundary evidence: original MIPS .pdata c05d3100..c05d3173. Semantic name remains unreviewed. */

void EapSessionRxImpliedSuccessPacket(int *param_1)

{
  int iVar1;
  
                    /* 0x3100  12  EapSessionRxImpliedSuccessPacket */
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    if (param_1[9] == 0) {
      param_1[0x11] = 1;
      FUN_c05d3c84(param_1,(undefined4 *)0x0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c05d21e0(param_1);
  }
  return;
}



/* c05d3174 EapSessionProcessAuthenticationResult */

/* Boundary evidence: original MIPS .pdata c05d3174..c05d31eb. Semantic name remains unreviewed. */

void EapSessionProcessAuthenticationResult(int *param_1,int param_2)

{
  int iVar1;
  
                    /* 0x3174  9  EapSessionProcessAuthenticationResult */
  iVar1 = FUN_c05d210c((int)param_1);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    if (param_1[9] != 0) {
      FUN_c05d4280(param_1,param_2);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c05d21e0(param_1);
  }
  return;
}



/* c05d31ec FUN_c05d31ec */

/* Boundary evidence: original MIPS .pdata c05d31ec..c05d3213. Semantic name remains unreviewed. */

void FUN_c05d31ec(void)

{
  DAT_c05d6128 = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6140);
  return;
}



/* c05d3214 FUN_c05d3214 */

/* Boundary evidence: original MIPS .pdata c05d3214..c05d3233. Semantic name remains unreviewed. */

void FUN_c05d3214(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c05d6140);
  return;
}



/* c05d3234 FUN_c05d3234 */

/* Boundary evidence: original MIPS .pdata c05d3234..c05d32c7. Semantic name remains unreviewed. */

void FUN_c05d3234(int param_1,int param_2)

{
  if (param_2 != *(int *)(param_1 + 200)) {
    if ((DAT_c05d60d0 & 2) != 0) {
      CxLogMsg(DAT_c05d60d4 << 0x18 | 0x30002,"State %hs --> %hs",
               (&PTR_s_Initial_c05d60fc)[*(int *)(param_1 + 200)],(&PTR_s_Initial_c05d60fc)[param_2]
              );
    }
    *(int *)(param_1 + 200) = param_2;
  }
  return;
}



/* c05d32c8 FUN_c05d32c8 */

/* Boundary evidence: original MIPS .pdata c05d32c8..c05d336f. Semantic name remains unreviewed. */

void FUN_c05d32c8(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  (**(code **)(*(int *)(param_1 + 0xc0) + 0xc))
            (*(undefined4 *)(param_1 + 0xb4),param_2,param_3,param_4,param_5);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if ((param_4 != 0) && (param_5 != 0)) {
    LocalFree(*(HLOCAL *)(param_1 + 0x120));
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  return;
}



/* c05d3370 FUN_c05d3370 */

/* Boundary evidence: original MIPS .pdata c05d3370..c05d349f. Semantic name remains unreviewed. */

int FUN_c05d3370(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *_Dst;
  
  iVar2 = *(int *)(param_1 + 0xa8);
  uVar3 = 0;
  if (iVar2 == 0) {
    iVar1 = 0x139f;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      uVar3 = *param_2;
    }
    _Dst = (undefined4 *)(param_1 + 0x68);
    memset(_Dst,0,0x40);
    *_Dst = 0x40;
    if ((DAT_c05d60d0 & 1) != 0) {
      CxLogMsg(DAT_c05d60d4 << 0x18 | 0x30001,"Call %ls:MakeMessage",iVar2 + 0x82c);
    }
    iVar1 = (**(code **)(iVar2 + 0xc6c))
                      (*(undefined4 *)(param_1 + 0xac),uVar3,*(undefined4 *)(param_1 + 0x104),
                       *(undefined4 *)(param_1 + 0xb8),_Dst,param_1 + 0x1c);
    if ((DAT_c05d60d0 & 1) != 0) {
      CxLogMsg(DAT_c05d60d4 << 0x18 | 0x30001,"Done %ls:MakeMessage",iVar2 + 0x82c);
    }
    if ((iVar1 != 0) && (iVar1 == 0x2d2)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* c05d34a0 FUN_c05d34a0 */

/* Boundary evidence: original MIPS .pdata c05d34a0..c05d34df. Semantic name remains unreviewed. */

void FUN_c05d34a0(int param_1)

{
  if (*(int *)(param_1 + 0xe8) != 0) {
    CTEStopTimer(param_1 + 0xcc);
    *(undefined4 *)(param_1 + 0xe8) = 0;
    FUN_c05d21e0((int *)param_1);
  }
  return;
}



/* c05d34e0 FUN_c05d34e0 */

/* Boundary evidence: original MIPS .pdata c05d34e0..c05d35bf. Semantic name remains unreviewed. */

void FUN_c05d34e0(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 2));
  param_2[0x3a] = 0;
  if ((uint)param_2[0x3c] < (uint)param_2[0x3d]) {
    iVar1 = 0x5b4;
  }
  else {
    if ((param_2[0x32] == 0) || (param_2[0x32] == 1)) {
      iVar1 = param_2[0x41];
      FUN_c05d32c8((int)param_2,iVar1,
                   (uint)CONCAT11(*(undefined1 *)(iVar1 + 2),*(undefined1 *)(iVar1 + 3)),0,0);
      if (param_2[0x42] == 0) {
        param_2[0x3d] = param_2[0x3d] + 1;
      }
      FUN_c05d36e0(param_2);
      goto LAB_c05d359c;
    }
    iVar1 = 0x285;
  }
  FUN_c05d32c8((int)param_2,0,0,1,iVar1);
LAB_c05d359c:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 2));
  FUN_c05d21e0(param_2);
  return;
}



/* c05d35c0 FUN_c05d35c0 */

/* Boundary evidence: original MIPS .pdata c05d35c0..c05d36df. Semantic name remains unreviewed. */

undefined4 FUN_c05d35c0(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((param_1[8] & 2U) == 0) {
    if (param_1[0x51] != 1) {
      if (param_2 != (undefined4 *)0x0) {
        puVar1 = LocalAlloc(0x40,param_2[1] + 0x14);
        param_1[0x52] = (int)puVar1;
        if (puVar1 == (undefined4 *)0x0) {
          return 0xe;
        }
        *puVar1 = *param_2;
        puVar1[1] = param_2[1];
        puVar1[2] = param_2[2];
        puVar1[3] = param_2[3];
        puVar1[4] = param_2[4];
        *(int *)param_1[0x52] = (int)((int *)param_1[0x52] + 5);
        memcpy(*(void **)param_1[0x52],(void *)*param_2,param_2[1]);
      }
      CTEInitEvent(param_1 + 0x4a,param_3);
      FUN_c05d210c((int)param_1);
      iVar2 = CTEScheduleEvent(param_1 + 0x4a,param_1);
      param_1[0x51] = iVar2;
      if (iVar2 == 0) {
        LocalFree((HLOCAL)param_1[0x52]);
        uVar3 = 0x285;
        param_1[0x52] = 0;
        FUN_c05d21e0(param_1);
      }
    }
  }
  else {
    uVar3 = 0x2bf;
  }
  return uVar3;
}



/* c05d36e0 FUN_c05d36e0 */

/* Boundary evidence: original MIPS .pdata c05d36e0..c05d3747. Semantic name remains unreviewed. */

void FUN_c05d36e0(int *param_1)

{
  if (param_1[0x3a] != 0) {
    CTEStopTimer(param_1 + 0x33);
    param_1[0x3a] = 0;
    FUN_c05d21e0(param_1);
  }
  FUN_c05d210c((int)param_1);
  param_1[0x3a] = 1;
  CTEStartTimer(param_1 + 0x33,param_1[0x3b],FUN_c05d34e0,param_1);
  return;
}



/* c05d3748 FUN_c05d3748 */

/* Boundary evidence: original MIPS .pdata c05d3748..c05d39f3. Semantic name remains unreviewed. */

void FUN_c05d3748(int *param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = 0;
  iVar7 = 0;
  bVar1 = false;
  bVar2 = false;
  iVar6 = 0;
  if (param_1[0x27] != 0) {
    iVar4 = EapSessionSetPassword(param_1,(wchar_t *)param_1[0x29]);
    if (*(code **)(param_1[0x30] + 0x20) != (code *)0x0) {
      (**(code **)(param_1[0x30] + 0x20))(param_1[0x2d],param_1[0x29],param_1[0x28]);
    }
  }
  if (param_1[0x21] != 0) {
    iVar4 = EapSessionSetConnectionData(param_1,(void *)param_1[0x22],param_1[0x23]);
    if (iVar4 == 0) {
      if (*(code **)(param_1[0x30] + 0x14) != (code *)0x0) {
        (**(code **)(param_1[0x30] + 0x14))(param_1[0x2d],param_1[0x22],param_1[0x23]);
      }
    }
    else {
      param_1[0x1b] = 2;
      param_1[0x1c] = iVar4;
    }
  }
  if ((iVar4 == 0) && (param_1[0x24] != 0)) {
    iVar4 = EapSessionSetUserData(param_1,(void *)param_1[0x25],param_1[0x26]);
    if (iVar4 == 0) {
      if (*(code **)(param_1[0x30] + 0x18) != (code *)0x0) {
        (**(code **)(param_1[0x30] + 0x18))(param_1[0x2d],param_1[0x25],param_1[0x26]);
      }
    }
    else {
      param_1[0x1b] = 2;
      param_1[0x1c] = iVar4;
    }
  }
  iVar4 = param_1[0x1b];
  if (iVar4 == 1) {
    if (param_1[9] == 0) {
      return;
    }
    FUN_c05d3234((int)param_1,2);
    (**(code **)(param_1[0x30] + 0x10))(param_1[0x2d],param_1[0x1d]);
    return;
  }
  if (iVar4 == 2) {
LAB_c05d38c4:
    iVar7 = 1;
    iVar4 = 3;
    if (param_1[0x1c] != 0) {
      iVar4 = 4;
    }
    FUN_c05d3234((int)param_1,iVar4);
  }
  else {
    if (iVar4 == 3) {
      bVar1 = true;
      goto LAB_c05d38c4;
    }
    if (iVar4 != 4) {
      if (iVar4 != 5) {
        if (iVar4 != 6) {
          return;
        }
        iVar6 = 1;
      }
      bVar2 = true;
    }
    bVar1 = true;
  }
  pcVar5 = (char *)0x0;
  uVar3 = 0;
  if (!bVar1) goto LAB_c05d3964;
  pcVar5 = (char *)param_1[0x41];
  if (*pcVar5 == '\x02') {
    param_1[0x3f] = (uint)(byte)pcVar5[1];
    if (pcVar5[4] == '\x01') {
LAB_c05d3948:
      iVar4 = 1;
    }
    else {
      if (pcVar5[4] == '\x03') goto LAB_c05d3954;
      iVar4 = 2;
    }
    FUN_c05d3234((int)param_1,iVar4);
  }
  else if ((*pcVar5 == '\x01') && (param_1[0x3e] = (uint)(byte)pcVar5[1], pcVar5[4] != '\x01'))
  goto LAB_c05d3948;
LAB_c05d3954:
  uVar3 = (uint)CONCAT11(pcVar5[2],pcVar5[3]);
LAB_c05d3964:
  FUN_c05d32c8((int)param_1,pcVar5,uVar3,iVar7,param_1[0x1c]);
  if (bVar2) {
    param_1[0x42] = iVar6;
    FUN_c05d36e0(param_1);
  }
  return;
}



/* c05d39f4 FUN_c05d39f4 */

/* Boundary evidence: original MIPS .pdata c05d39f4..c05d3b13. Semantic name remains unreviewed. */

void FUN_c05d39f4(undefined4 param_1,int *param_2)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar2;
  
  piVar2 = param_2 + 0x13;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_2 + 2);
  while( true ) {
    iVar1 = EapInvokeInteractiveUI
                      ((uint)*(byte *)(param_2 + 0x31),0,param_2[0x1f],param_2[0x20],piVar2,
                       param_2 + 0x14);
    EnterCriticalSection(lpCriticalSection);
    if (iVar1 != 0) break;
    param_2[0x12] = 1;
    iVar1 = FUN_c05d3370((int)param_2,(undefined4 *)param_2[0x52]);
    if (iVar1 == 0) {
      FUN_c05d3748(param_2);
    }
    FUN_c05d2f40((int)param_2,*piVar2);
    *piVar2 = 0;
    param_2[0x14] = 0;
    param_2[0x12] = 0;
    if (iVar1 != 0) break;
    if (param_2[0x1e] == 0) goto LAB_c05d3ad0;
    LeaveCriticalSection(lpCriticalSection);
  }
  FUN_c05d32c8((int)param_2,0,0,1,iVar1);
LAB_c05d3ad0:
  param_2[0x51] = 0;
  LocalFree((HLOCAL)param_2[0x52]);
  param_2[0x52] = 0;
  LeaveCriticalSection(lpCriticalSection);
  FUN_c05d21e0(param_2);
  return;
}



/* c05d3b14 FUN_c05d3b14 */

/* Boundary evidence: original MIPS .pdata c05d3b14..c05d3c17. Semantic name remains unreviewed. */

void FUN_c05d3b14(int *param_1,int param_2)

{
  uint local_18 [2];
  
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  local_18[0] = param_1[0x2e] - 5;
  (**(code **)(param_1[0x30] + 4))
            (param_1[0x2d],*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),
             param_1[0x41] + 5,local_18);
  if (param_1[0x2e] - 5U < local_18[0]) {
    local_18[0] = 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  *(char *)(param_2 + 9) = (char)param_1[0x3e];
  *(undefined1 *)param_1[0x41] = 2;
  *(undefined1 *)(param_1[0x41] + 1) = *(undefined1 *)(param_2 + 9);
  *(char *)(param_1[0x41] + 2) = (char)(local_18[0] + 5 >> 8);
  *(char *)(param_1[0x41] + 3) = (char)(local_18[0] + 5);
  *(undefined1 *)(param_1[0x41] + 4) = 1;
  param_1[0x3f] = (uint)*(byte *)(param_2 + 9);
  param_1[0x1b] = 4;
  FUN_c05d3748(param_1);
  FUN_c05d3234((int)param_1,1);
  return;
}



/* c05d3c18 FUN_c05d3c18 */

/* Boundary evidence: original MIPS .pdata c05d3c18..c05d3c83. Semantic name remains unreviewed. */

void FUN_c05d3c18(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_2[0x52];
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 2));
  FUN_c05d3b14(param_2,iVar1);
  LocalFree((HLOCAL)param_2[0x52]);
  param_2[0x52] = 0;
  param_2[0x51] = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 2));
  FUN_c05d21e0(param_2);
  return;
}



/* c05d3c84 FUN_c05d3c84 */

/* Boundary evidence: original MIPS .pdata c05d3c84..c05d3d27. Semantic name remains unreviewed. */

int FUN_c05d3c84(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_c05d3370((int)param_1,param_2);
  if ((iVar1 == 0) && (param_1[0x1e] != 0)) {
    if (param_1[9] == 0) {
      if (*(int *)param_1[0x30] == 0) {
        iVar1 = FUN_c05d35c0(param_1,param_2,FUN_c05d39f4);
      }
      else {
        iVar1 = (*(code *)((int *)param_1[0x30])[7])
                          (param_1[0x2d],(char)param_1[0x31],param_1[0x1f],param_1[0x20]);
      }
    }
    else {
      iVar1 = 0x2bf;
    }
  }
  return iVar1;
}



/* c05d3d28 FUN_c05d3d28 */

/* Boundary evidence: original MIPS .pdata c05d3d28..c05d3f23. Semantic name remains unreviewed. */

int FUN_c05d3d28(int *param_1,undefined4 *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((param_1[0x12] == 0) && ((uint)*(byte *)((int)param_2 + 9) == param_1[0x3e])) {
    if (param_1[0x3f] == (uint)*(byte *)((int)param_2 + 9)) {
      param_1[0x1b] = 4;
    }
  }
  else {
    bVar1 = *(byte *)((int)param_2 + 9);
    param_1[0x3f] = -1;
    param_1[0x3e] = (uint)bVar1;
    uVar2 = (uint)*(byte *)((int)param_2 + 10);
    if (uVar2 == 1) {
      if (*(int *)param_1[0x30] == 0) {
        iVar3 = FUN_c05d35c0(param_1,param_2,FUN_c05d3c18);
      }
      else {
        FUN_c05d3b14(param_1,(int)param_2);
      }
    }
    else if (uVar2 == 2) {
      if (*(code **)(param_1[0x30] + 8) != (code *)0x0) {
        (**(code **)(param_1[0x30] + 8))(param_1[0x2d],param_2[3],param_2[4]);
      }
      *(undefined1 *)param_1[0x41] = 2;
      *(undefined1 *)(param_1[0x41] + 1) = *(undefined1 *)((int)param_2 + 9);
      *(undefined1 *)(param_1[0x41] + 2) = 0;
      *(undefined1 *)(param_1[0x41] + 3) = 4;
      *(undefined1 *)(param_1[0x41] + 4) = 2;
      param_1[0x3f] = (uint)*(byte *)((int)param_2 + 9);
      param_1[0x1b] = 4;
    }
    else if (uVar2 != 3) {
      if (uVar2 == *(byte *)(param_1 + 0x31)) {
        iVar3 = FUN_c05d2098((int)param_1,uVar2);
        if (((iVar3 == 0) && (iVar3 = FUN_c05d1f80((int)param_1), iVar3 == 0)) &&
           (iVar3 = FUN_c05d3c84(param_1,param_2), iVar3 == 0)) {
          FUN_c05d3234((int)param_1,2);
        }
      }
      else {
        *(byte *)(param_1[0x41] + 5) = *(byte *)(param_1 + 0x31);
        *(undefined1 *)param_1[0x41] = 2;
        *(undefined1 *)(param_1[0x41] + 1) = *(undefined1 *)((int)param_2 + 9);
        *(undefined1 *)(param_1[0x41] + 2) = 0;
        *(undefined1 *)(param_1[0x41] + 3) = 6;
        *(undefined1 *)(param_1[0x41] + 4) = 3;
        param_1[0x3f] = (uint)*(byte *)((int)param_2 + 9);
        param_1[0x1b] = 4;
      }
    }
  }
  return iVar3;
}



/* c05d3f24 FUN_c05d3f24 */

/* Boundary evidence: original MIPS .pdata c05d3f24..c05d411b. Semantic name remains unreviewed. */

DWORD FUN_c05d3f24(int *param_1,undefined4 *param_2)

{
  char cVar1;
  HLOCAL pvVar2;
  int iVar3;
  uint uVar4;
  DWORD DVar5;
  
  if (param_1[9] == 0) {
    return 0;
  }
  if ((param_1[0x32] == 0) && (*(char *)((int)param_2 + 10) != '\x01')) {
    return 0;
  }
  if ((param_1[0x32] == 1) && (*(byte *)((int)param_2 + 10) < 3)) {
    return 0;
  }
  if ((uint)*(byte *)((int)param_2 + 9) != param_1[0x3e]) {
    return 0;
  }
  if (param_1[0x3a] != 0) {
    CTEStopTimer(param_1 + 0x33);
    param_1[0x3a] = 0;
    FUN_c05d21e0(param_1);
  }
  cVar1 = *(char *)((int)param_2 + 10);
  if (cVar1 == '\x01') {
    if (param_2[4] == 0) {
      return 0x490;
    }
    LocalFree((HLOCAL)param_1[0x47]);
    pvVar2 = LocalAlloc(0x40,(param_2[4] + 1) * 2);
    param_1[0x47] = (int)pvVar2;
    if (pvVar2 == (HLOCAL)0x0) {
      return 0xe;
    }
    *(undefined2 *)(param_2[4] * 2 + (int)pvVar2) = 0;
    iVar3 = MultiByteToWideChar(1,0,(LPCSTR)param_2[3],param_2[4],(LPWSTR)param_1[0x47],param_2[4]);
    if ((iVar3 == 0) && (DVar5 = GetLastError(), DVar5 != 0)) {
      return DVar5;
    }
    FUN_c05d3234((int)param_1,1);
    uVar4 = (uint)*(byte *)(param_1 + 0x31);
LAB_c05d40c4:
    DVar5 = FUN_c05d2098((int)param_1,uVar4);
    if (DVar5 != 0) {
      return DVar5;
    }
    DVar5 = FUN_c05d1f80((int)param_1);
    if (DVar5 != 0) {
      return DVar5;
    }
    param_2 = (undefined4 *)0x0;
LAB_c05d40f0:
    DVar5 = FUN_c05d3c84(param_1,param_2);
  }
  else {
    if (cVar1 == '\x02') {
      return 0;
    }
    if (cVar1 == '\x03') {
      uVar4 = (uint)*(byte *)(param_1 + 0x31);
      if (*(byte *)param_2[3] != uVar4) goto LAB_c05d40c4;
    }
    else if (cVar1 == (char)param_1[0x31]) goto LAB_c05d40f0;
    DVar5 = 0x2b3;
  }
  return DVar5;
}



/* c05d411c FUN_c05d411c */

/* Boundary evidence: original MIPS .pdata c05d411c..c05d427f. Semantic name remains unreviewed. */

void FUN_c05d411c(int *param_1,undefined4 *param_2)

{
  byte bVar1;
  int iVar2;
  DWORD DVar3;
  
  param_1[0x1b] = 0;
  param_1[0x21] = 0;
  param_1[0x24] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  bVar1 = *(byte *)(param_2 + 2);
  DVar3 = 0;
  if (bVar1 == 1) {
    iVar2 = param_1[0x32];
    if ((((iVar2 != 0) && (iVar2 != 1)) && (iVar2 != 2)) && (iVar2 != 3)) goto LAB_c05d4264;
    DVar3 = FUN_c05d3d28(param_1,param_2);
  }
  else if (bVar1 == 2) {
    if ((param_1[0x32] != 0) && (param_1[0x32] != 1)) goto LAB_c05d4264;
    DVar3 = FUN_c05d3f24(param_1,param_2);
  }
  else {
    if ((bVar1 < 3) || (4 < bVar1)) goto LAB_c05d4264;
    if (param_1[0x32] == 2) {
      DVar3 = 0;
      if (param_1[9] == 0) {
        DVar3 = FUN_c05d3c84(param_1,param_2);
      }
    }
    else {
      if (bVar1 != 4) goto LAB_c05d4264;
      FUN_c05d32c8((int)param_1,0,0,1,0x2b3);
    }
  }
  if (DVar3 != 0) {
    FUN_c05d3234((int)param_1,5);
    FUN_c05d32c8((int)param_1,0,0,1,DVar3);
    return;
  }
LAB_c05d4264:
  FUN_c05d3748(param_1);
  return;
}



/* c05d4280 FUN_c05d4280 */

/* Boundary evidence: original MIPS .pdata c05d4280..c05d42d7. Semantic name remains unreviewed. */

void FUN_c05d4280(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1[0x32] == 2) {
    param_1[0xf] = param_2;
    param_1[0xe] = 1;
    iVar1 = FUN_c05d3370((int)param_1,(undefined4 *)0x0);
    if (iVar1 == 0) {
      FUN_c05d3748(param_1);
    }
  }
  return;
}



/* c05d42d8 FUN_c05d42d8 */

/* Boundary evidence: original MIPS .pdata c05d42d8..c05d4363. Semantic name remains unreviewed. */

void FUN_c05d42d8(int *param_1,void *param_2,size_t param_3)

{
  if (param_1[0x32] == 0) {
    *(undefined1 *)param_1[0x41] = 1;
    *(char *)(param_1[0x41] + 1) = (char)param_1[0x40];
    *(char *)(param_1 + 0x40) = (char)param_1[0x40] + '\x01';
    *(char *)(param_1[0x41] + 2) = (char)(param_3 + 5 >> 8);
    *(char *)(param_1[0x41] + 3) = (char)(param_3 + 5);
    *(undefined1 *)(param_1[0x41] + 4) = 1;
    memcpy((void *)(param_1[0x41] + 5),param_2,param_3);
    param_1[0x1b] = 6;
    FUN_c05d3748(param_1);
  }
  return;
}



/* c05d4364 FUN_c05d4364 */

undefined4 FUN_c05d4364(byte *param_1,uint param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  *param_3 = param_1;
  param_3[1] = param_2;
  if (3 < param_2) {
    *(byte *)((int)param_3 + 9) = param_1[1];
    uVar3 = (uint)CONCAT11(param_1[2],param_1[3]);
    if ((3 < uVar3) && (uVar3 <= param_2)) {
      bVar1 = *param_1;
      *(byte *)(param_3 + 2) = bVar1;
      if ((bVar1 != 0) && ((bVar1 < 5 && (bVar1 != 0)))) {
        if (bVar1 < 3) {
          if (uVar3 == 4) {
            return 0;
          }
          bVar1 = param_1[4];
          *(byte *)((int)param_3 + 10) = bVar1;
          param_3[3] = param_1 + 5;
          param_3[4] = uVar3 - 5;
          if (bVar1 == 3) {
            if (*(char *)(param_3 + 2) == '\x01') {
              return 0;
            }
            if (uVar3 - 5 != 1) {
              return 0;
            }
            if (param_1[5] < 4) {
              return 0;
            }
            return 1;
          }
        }
        else {
          if (4 < bVar1) {
            return 0;
          }
          if (uVar3 != 4) {
            return 0;
          }
        }
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



/* c05d4508 EapUtilAuthAttributeGetVendorSpecific */

/* Boundary evidence: original MIPS .pdata c05d4508..c05d45cf. Semantic name remains unreviewed. */

int * EapUtilAuthAttributeGetVendorSpecific(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  void *_Buf1;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  
                    /* 0x4508  20  EapUtilAuthAttributeGetVendorSpecific */
  if (param_1 != (int *)0x0) {
    local_20 = (undefined1)((uint)param_2 >> 0x18);
    local_1f = (undefined1)((uint)param_2 >> 0x10);
    local_1e = (undefined1)((uint)param_2 >> 8);
    local_1d = (undefined1)param_2;
    for (; *param_1 != 0; param_1 = param_1 + 3) {
      if ((*param_1 == 0x1a) && (6 < (uint)param_1[1])) {
        _Buf1 = (void *)param_1[2];
        iVar1 = memcmp(_Buf1,&local_20,4);
        if ((iVar1 == 0) && (*(byte *)((int)_Buf1 + 4) == param_3)) {
          return param_1;
        }
      }
    }
  }
  return (int *)0x0;
}



/* c05d45d0 EapUtilAuthAttributeInsertVSA */

/* Boundary evidence: original MIPS .pdata c05d45d0..c05d46af. Semantic name remains unreviewed. */

undefined4
EapUtilAuthAttributeInsertVSA
          (int param_1,int param_2,undefined4 param_3,undefined1 param_4,void *param_5,byte param_6)

{
  undefined1 *puVar1;
  SIZE_T uBytes;
  undefined4 uVar2;
  undefined4 *puVar3;
  
                    /* 0x45d0  21  EapUtilAuthAttributeInsertVSA */
  puVar3 = (undefined4 *)(param_1 * 0xc + param_2);
  *puVar3 = 0x1a;
  uBytes = param_6 + 6;
  puVar3[1] = uBytes;
  uVar2 = 0;
  puVar1 = LocalAlloc(0x40,uBytes);
  puVar3[2] = puVar1;
  if (puVar1 == (undefined1 *)0x0) {
    uVar2 = 0xe;
  }
  else {
    *puVar1 = (char)((uint)param_3 >> 0x18);
    *(char *)(puVar3[2] + 1) = (char)((uint)param_3 >> 0x10);
    *(char *)(puVar3[2] + 2) = (char)((uint)param_3 >> 8);
    *(char *)(puVar3[2] + 3) = (char)param_3;
    *(undefined1 *)(puVar3[2] + 4) = param_4;
    *(byte *)(puVar3[2] + 5) = param_6 + 2;
    memcpy((void *)(puVar3[2] + 6),param_5,(uint)param_6);
  }
  return uVar2;
}



/* c05d46b0 EapUtilAuthAttributeArrayAlloc */

/* Boundary evidence: original MIPS .pdata c05d46b0..c05d470f. Semantic name remains unreviewed. */

HLOCAL EapUtilAuthAttributeArrayAlloc(uint param_1)

{
  SIZE_T uBytes;
  HLOCAL pvVar1;
  
                    /* 0x46b0  18  EapUtilAuthAttributeArrayAlloc */
  if (param_1 < 0x10000) {
    uBytes = (param_1 + 1) * 0xc;
    pvVar1 = LocalAlloc(0x40,uBytes);
    if (pvVar1 != (HLOCAL)0x0) {
      *(undefined4 *)((int)pvVar1 + (uBytes - 0xc)) = 0;
    }
  }
  else {
    pvVar1 = (HLOCAL)0x0;
  }
  return pvVar1;
}



/* c05d4710 EapUtilAuthAttributeArrayFree */

/* Boundary evidence: original MIPS .pdata c05d4710..c05d478b. Semantic name remains unreviewed. */

void EapUtilAuthAttributeArrayFree(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
                    /* 0x4710  19  EapUtilAuthAttributeArrayFree */
  if (param_1 != (int *)0x0) {
    iVar2 = 0;
    iVar1 = *param_1;
    piVar3 = param_1;
    while (iVar1 != 0) {
      LocalFree((HLOCAL)piVar3[2]);
      iVar2 = iVar2 + 1;
      piVar3[2] = 0;
      piVar3 = param_1 + iVar2 * 3;
      iVar1 = *piVar3;
    }
    LocalFree(param_1);
  }
  return;
}



/* c05d478c EapUtilExtractMPPEKey */

/* Boundary evidence: original MIPS .pdata c05d478c..c05d4823. Semantic name remains unreviewed. */

undefined4
EapUtilExtractMPPEKey(void *param_1,uint *param_2,int *param_3,undefined4 param_4,byte param_5)

{
  int *piVar1;
  uint _Size;
  
                    /* 0x478c  22  EapUtilExtractMPPEKey */
  *param_2 = 0;
  piVar1 = EapUtilAuthAttributeGetVendorSpecific(param_3,param_4,(uint)param_5);
  if ((piVar1 != (int *)0x0) && (8 < (uint)piVar1[1])) {
    _Size = (uint)*(byte *)(piVar1[2] + 8);
    if (_Size + 9 <= (uint)piVar1[1]) {
      memcpy(param_1,(void *)(piVar1[2] + 9),_Size);
      *param_2 = _Size;
    }
  }
  return 0;
}



/* c05d4824 FUN_c05d4824 */

/* Boundary evidence: original MIPS .pdata c05d4824..c05d4a17. Semantic name remains unreviewed. */

undefined4 FUN_c05d4824(HKEY param_1,LPCWSTR param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x64a;
  memset(param_4,0,0xc48);
  *param_4 = param_3;
  if ((3 < param_3) && (param_3 < 0x100)) {
    iVar1 = RegReadValues(param_1,param_2,L"Path",1);
    if (iVar1 == 1) {
      RegReadValues(param_1,param_2,L"ConfigUIPath",1);
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* c05d4a18 FUN_c05d4a18 */

/* Boundary evidence: original MIPS .pdata c05d4a18..c05d4adb. Semantic name remains unreviewed. */

int FUN_c05d4a18(HKEY param_1,wchar_t *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint auStack_c60 [786];
  uint local_18;
  
  local_18 = DAT_c05d6114;
  uVar1 = _wtol(param_2);
  iVar2 = FUN_c05d4824(param_1,param_2,uVar1,auStack_c60);
  if (iVar2 == 0) {
    uVar1 = param_3[3];
    param_3[3] = uVar1 + 0xc48;
    if (uVar1 + 0xc48 <= *param_3) {
      memcpy((void *)(param_3[2] * 0xc48 + param_3[1]),auStack_c60,0xc48);
    }
    param_3[2] = param_3[2] + 1;
  }
  FUN_c05d5580(local_18);
  return iVar2;
}



/* c05d4adc EapEnumExtensions */

/* Boundary evidence: original MIPS .pdata c05d4adc..c05d4b6b. Semantic name remains unreviewed. */

LSTATUS EapEnumExtensions(uint param_1,undefined4 param_2,undefined4 *param_3,uint *param_4)

{
  LSTATUS LVar1;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  
                    /* 0x4adc  2  EapEnumExtensions */
  local_18 = 0;
  local_14 = 0;
  local_20 = param_1;
  local_1c = param_2;
  LVar1 = RegTraverseKey((HKEY)0x80000002,L"Comm\\EAP\\Extension",FUN_c05d4a18,&local_20);
  if (LVar1 == 0) {
    *param_3 = local_18;
    *param_4 = local_14;
    if (param_1 < local_14) {
      LVar1 = 0x7a;
    }
  }
  return LVar1;
}



/* c05d4b6c RegReadValues */

/* Boundary evidence: original MIPS .pdata c05d4b6c..c05d4e8f. Semantic name remains unreviewed. */

int RegReadValues(HKEY param_1,LPCWSTR param_2,undefined4 param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  DWORD dwErrCode;
  LPBYTE lpData;
  uint *puVar2;
  int iVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  uint uVar6;
  LPCWSTR lpValueName;
  LPCWSTR pWVar7;
  HKEY local_res0;
  LPCWSTR local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  DWORD local_38;
  SIZE_T local_34;
  DWORD local_30;
  LPCWSTR local_2c;
  
                    /* 0x4b6c  25  RegReadValues */
  iVar3 = 0;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  local_2c = param_2;
  if ((param_2 == (LPCWSTR)0x0) ||
     (LVar1 = RegOpenKeyExW(param_1,param_2,0,0x20019,&local_res0), LVar1 == 0)) {
    puVar5 = &local_res8;
    pWVar7 = local_2c;
    while (lpValueName = (LPCWSTR)*puVar5, lpValueName != (LPCWSTR)0x0) {
      DVar4 = puVar5[1];
      puVar2 = (uint *)0x0;
      uVar6 = puVar5[2] & 1;
      if (uVar6 == 0) {
        lpData = (LPBYTE)puVar5[3];
        if (DVar4 == 3) {
          puVar2 = (uint *)puVar5[4];
          local_38 = *puVar2;
        }
        else {
          local_38 = puVar5[4];
        }
      }
      else {
        local_38 = 0;
        pWVar7 = (LPCWSTR)puVar5[3];
        puVar2 = (uint *)puVar5[4];
        lpData = (LPBYTE)0x0;
      }
      puVar5 = puVar5 + 5;
      LVar1 = RegQueryValueExW(local_res0,lpValueName,(LPDWORD)0x0,&local_30,(LPBYTE)0x0,&local_34);
      if (((LVar1 == 0) || (LVar1 == 0xea)) && (local_30 == DVar4)) {
        if (uVar6 == 0) {
          if ((local_38 < local_34) || (lpData == (LPBYTE)0x0)) {
            if (DVar4 == 3) {
              *puVar2 = local_34;
            }
            lpData = (LPBYTE)0x0;
            dwErrCode = 0x7a;
            goto LAB_c05d4da4;
          }
        }
        else {
          lpData = LocalAlloc(0x40,local_34);
          if (lpData == (LPBYTE)0x0) {
            dwErrCode = 0xe;
LAB_c05d4da4:
            SetLastError(dwErrCode);
          }
          else {
            local_38 = local_34;
          }
          if (lpData == (LPBYTE)0x0) goto LAB_c05d4e20;
        }
        LVar1 = RegQueryValueExW(local_res0,lpValueName,(LPDWORD)0x0,(LPDWORD)0x0,lpData,&local_38);
        if (LVar1 == 0) {
          iVar3 = iVar3 + 1;
          if (DVar4 == 3) {
            *puVar2 = local_38;
          }
        }
        else if (uVar6 != 0) {
          LocalFree(lpData);
          local_38 = 0;
          lpData = (LPBYTE)0x0;
        }
      }
LAB_c05d4e20:
      if ((uVar6 != 0) && (*(LPBYTE *)pWVar7 = lpData, puVar2 != (uint *)0x0)) {
        *puVar2 = local_38;
      }
    }
    if (local_2c != (LPCWSTR)0x0) {
      RegCloseKey(local_res0);
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



/* c05d4e90 RegWriteValues */

/* Boundary evidence: original MIPS .pdata c05d4e90..c05d503b. Semantic name remains unreviewed. */

int RegWriteValues(HKEY param_1,LPCWSTR param_2,undefined4 param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  int iVar2;
  LPCWSTR lpValueName;
  undefined4 *puVar3;
  DWORD *pDVar4;
  DWORD *pDVar5;
  int iVar6;
  undefined4 *puVar7;
  HKEY local_res0;
  LPCWSTR local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  DWORD aDStack_28 [2];
  
                    /* 0x4e90  27  RegWriteValues */
  iVar6 = 0;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if ((param_2 == (LPCWSTR)0x0) ||
     (LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                              &local_res0,aDStack_28), LVar1 == 0)) {
    puVar7 = &local_res8;
    while (lpValueName = (LPCWSTR)*puVar7, lpValueName != (LPCWSTR)0x0) {
      pDVar5 = puVar7 + 1;
      puVar3 = puVar7 + 3;
      pDVar4 = puVar7 + 4;
      puVar7 = puVar7 + 5;
      if ((BYTE *)*puVar3 == (BYTE *)0x0) {
        iVar2 = RegDeleteValueW(local_res0,lpValueName);
      }
      else {
        iVar2 = RegSetValueExW(local_res0,lpValueName,0,*pDVar5,(BYTE *)*puVar3,*pDVar4);
      }
      if (iVar2 == 0) {
        iVar6 = iVar6 + 1;
      }
    }
    if (param_2 != (LPCWSTR)0x0) {
      RegCloseKey(local_res0);
    }
  }
  else {
    iVar6 = 0;
  }
  return iVar6;
}



/* c05d503c RegDeleteKeyValues */

/* Boundary evidence: original MIPS .pdata c05d503c..c05d519b. Semantic name remains unreviewed. */

int RegDeleteKeyValues(HKEY param_1,LPCWSTR param_2)

{
  int iVar1;
  DWORD dwIndex;
  HKEY local_230;
  DWORD local_22c;
  WCHAR aWStack_228 [258];
  uint local_24;
  
                    /* 0x503c  24  RegDeleteKeyValues */
  local_24 = DAT_c05d6114;
  local_230 = param_1;
  if ((param_2 == (LPCWSTR)0x0) ||
     (iVar1 = RegOpenKeyExW(param_1,param_2,0,0x20019,&local_230), iVar1 == 0)) {
    local_22c = 0x101;
    dwIndex = 0;
    iVar1 = RegEnumValueW(local_230,0,aWStack_228,&local_22c,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,
                          (LPDWORD)0x0);
    while (iVar1 == 0) {
      iVar1 = RegDeleteValueW(local_230,aWStack_228);
      if (iVar1 != 0) goto LAB_c05d5154;
      dwIndex = dwIndex + 1;
      local_22c = 0x101;
      iVar1 = RegEnumValueW(local_230,dwIndex,aWStack_228,&local_22c,(LPDWORD)0x0,(LPDWORD)0x0,
                            (LPBYTE)0x0,(LPDWORD)0x0);
    }
    if (iVar1 == 0x103) {
      iVar1 = 0;
    }
LAB_c05d5154:
    if (param_2 != (LPCWSTR)0x0) {
      RegCloseKey(local_230);
    }
  }
  FUN_c05d5580(local_24);
  return iVar1;
}



/* c05d519c RegTraverseKey */

/* Boundary evidence: original MIPS .pdata c05d519c..c05d52f7. Semantic name remains unreviewed. */

LSTATUS RegTraverseKey(HKEY param_1,LPCWSTR param_2,undefined *param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  DWORD dwIndex;
  HKEY local_230;
  DWORD local_22c;
  WCHAR aWStack_228 [258];
  uint local_24;
  
                    /* 0x519c  26  RegTraverseKey */
  local_24 = DAT_c05d6114;
  local_230 = param_1;
  if ((param_2 == (LPCWSTR)0x0) ||
     (LVar1 = RegOpenKeyExW(param_1,param_2,0,0xf003f,&local_230), LVar1 == 0)) {
    local_22c = 0x101;
    dwIndex = 0;
    LVar1 = RegEnumKeyExW(local_230,0,aWStack_228,&local_22c,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                          (PFILETIME)0x0);
    while (LVar1 == 0) {
      (*(code *)param_3)(local_230,aWStack_228,param_4);
      dwIndex = dwIndex + 1;
      local_22c = 0x101;
      LVar1 = RegEnumKeyExW(local_230,dwIndex,aWStack_228,&local_22c,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
    }
    if (LVar1 == 0x103) {
      LVar1 = 0;
    }
    if (param_2 != (LPCWSTR)0x0) {
      RegCloseKey(local_230);
    }
  }
  FUN_c05d5580(local_24);
  return LVar1;
}



/* c05d52f8 FUN_c05d52f8 */

/* Boundary evidence: original MIPS .pdata c05d52f8..c05d536b. Semantic name remains unreviewed. */

void FUN_c05d52f8(HKEY param_1,LPCWSTR param_2)

{
  int iVar1;
  LSTATUS LVar2;
  
  iVar1 = RegDeleteKeyValues(param_1,param_2);
  if ((iVar1 == 0) && (LVar2 = RegTraverseKey(param_1,param_2,FUN_c05d52f8,0), LVar2 == 0)) {
    RegDeleteKeyW(param_1,param_2);
  }
  return;
}



/* c05d536c RegDeleteKeyAndContents */

/* Boundary evidence: original MIPS .pdata c05d536c..c05d5387. Semantic name remains unreviewed. */

void RegDeleteKeyAndContents(HKEY param_1,LPCWSTR param_2)

{
                    /* 0x536c  23  RegDeleteKeyAndContents */
  FUN_c05d52f8(param_1,param_2);
  return;
}



/* c05d5418 entry */

/* Boundary evidence: original MIPS .pdata c05d5418..c05d548b. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c05d548c();
    FUN_c05d5760();
  }
  uVar1 = DllEntry(param_1,param_2);
  if (param_2 == 0) {
    FUN_c05d56e8();
  }
  return uVar1;
}



/* c05d548c FUN_c05d548c */

/* Boundary evidence: original MIPS .pdata c05d548c..c05d54ff. Semantic name remains unreviewed. */

void FUN_c05d548c(void)

{
  uint uVar1;
  
  if ((DAT_c05d6114 == 0) || (DAT_c05d6114 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c05d6114 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c05d6114 == 0) {
      DAT_c05d6114 = 0xb064;
    }
  }
  DAT_c05d6118 = ~DAT_c05d6114;
  return;
}



/* c05d5500 FUN_c05d5500 */

/* Boundary evidence: original MIPS .pdata c05d5500..c05d5553. Semantic name remains unreviewed. */

void FUN_c05d5500(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c05d5580(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c05d5554 FUN_c05d5554 */

/* Boundary evidence: original MIPS .pdata c05d5554..c05d557f. Semantic name remains unreviewed. */

undefined4 FUN_c05d5554(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c05d5500(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c05d5580 FUN_c05d5580 */

/* Boundary evidence: original MIPS .pdata c05d5580..c05d55c7. Semantic name remains unreviewed. */

void FUN_c05d5580(uint param_1)

{
  if ((param_1 == DAT_c05d6114) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c05d55c8 FUN_c05d55c8 */

/* Boundary evidence: original MIPS .pdata c05d55c8..c05d56e7. Semantic name remains unreviewed. */

void FUN_c05d55c8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c05d612c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c05d6178;
    if (DAT_c05d6178 != (undefined4 *)0x0) {
      while (DAT_c05d6174 = DAT_c05d6174 + -1, _Memory <= DAT_c05d6174) {
        if ((code *)*DAT_c05d6174 != (code *)0x0) {
          (*(code *)*DAT_c05d6174)();
          _Memory = DAT_c05d6178;
        }
      }
      free(_Memory);
      DAT_c05d6174 = (undefined4 *)0x0;
      DAT_c05d6178 = (undefined4 *)0x0;
    }
    FUN_c05d570c((undefined4 *)&DAT_c05d1010,(undefined4 *)&DAT_c05d1014);
  }
  FUN_c05d570c((undefined4 *)&DAT_c05d1018,(undefined4 *)&DAT_c05d101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c05d617c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c05d56e8 FUN_c05d56e8 */

/* Boundary evidence: original MIPS .pdata c05d56e8..c05d570b. Semantic name remains unreviewed. */

void FUN_c05d56e8(void)

{
  FUN_c05d55c8(0,0,1);
  return;
}



/* c05d570c FUN_c05d570c */

/* Boundary evidence: original MIPS .pdata c05d570c..c05d575f. Semantic name remains unreviewed. */

void FUN_c05d570c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c05d5760 FUN_c05d5760 */

/* Boundary evidence: original MIPS .pdata c05d5760..c05d579b. Semantic name remains unreviewed. */

void FUN_c05d5760(void)

{
  FUN_c05d570c((undefined4 *)&DAT_c05d1008,(undefined4 *)&DAT_c05d100c);
  FUN_c05d570c((undefined4 *)&DAT_c05d1000,(undefined4 *)&DAT_c05d1004);
  return;
}


