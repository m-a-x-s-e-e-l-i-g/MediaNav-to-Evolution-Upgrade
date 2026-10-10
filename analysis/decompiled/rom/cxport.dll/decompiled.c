/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0471454 CTEInitEvent */

void CTEInitEvent(undefined4 *param_1,undefined4 param_2)

{
                    /* 0x1454  8  CTEInitEvent */
  param_1[6] = 0;
  *param_1 = 0xffffffff;
  param_1[1] = param_2;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}



/* c0471474 CTEInitTimer */

void CTEInitTimer(undefined4 *param_1)

{
                    /* 0x1474  9  CTEInitTimer */
  param_1[6] = 0;
  *param_1 = 0xffffffff;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[4] = 1;
  return;
}



/* c0471498 FUN_c0471498 */

/* Boundary evidence: original MIPS .pdata c0471498..c0471523. Semantic name remains unreviewed. */

undefined4 FUN_c0471498(void)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = CeGetThreadPriority(0x41);
  CeSetThreadPriority(0x41,0);
  GetTickCount();
  for (piVar2 = (int *)DAT_c0477460; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
  }
  CeSetThreadPriority(0x41,uVar1);
  return 0;
}



/* c0471524 FUN_c0471524 */

/* Boundary evidence: original MIPS .pdata c0471524..c0471593. Semantic name remains unreviewed. */

void FUN_c0471524(void)

{
  int iVar1;
  
  if (DAT_c0477424 == 0) {
    iVar1 = WaitForAPIReady(0x51,0);
    if (iVar1 != 0) {
      DAT_c0477424 = 0;
      return;
    }
    DAT_c0477424 = 1;
  }
  if (DAT_c0477530 != (code *)0x0) {
    (*DAT_c0477530)();
  }
  return;
}



/* c0471594 CTEIOControl */

/* Boundary evidence: original MIPS .pdata c0471594..c0471737. Semantic name remains unreviewed. */

undefined4
CTEIOControl(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,uint param_5,
            undefined4 *param_6)

{
  LONG LVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
                    /* 0x1594  7  CTEIOControl */
  uVar2 = 0;
  uVar3 = 0;
  if (param_1 == 1) {
    LVar1 = InterlockedIncrement(&DAT_c04774dc);
    if (LVar1 == 1) {
      FUN_c0471524();
    }
  }
  else if (param_1 == 2) {
    if (DAT_c04774dc == 0) {
      uVar2 = 0x1f;
    }
    else {
      InterlockedDecrement(&DAT_c04774dc);
    }
  }
  else if (param_1 == 3) {
    if (param_5 < 0x38) {
      uVar2 = 0x7a;
    }
    else if (param_4 == (undefined4 *)0x0) {
      uVar2 = 0x57;
    }
    else {
      *param_4 = 1;
      uVar3 = 0x38;
      param_4[1] = DAT_c04774e0;
      param_4[2] = DAT_c0477604;
      param_4[3] = DAT_c047742c;
      param_4[4] = DAT_c0477470;
      param_4[5] = DAT_c04775f0;
      param_4[6] = DAT_c04774a4;
      param_4[7] = DAT_c0477534;
      param_4[8] = DAT_c0477614;
      param_4[9] = DAT_c0477434;
      param_4[10] = DAT_c0477430;
      param_4[0xb] = DAT_c047761c;
      param_4[0xc] = DAT_c04775ec;
      param_4[0xd] = DAT_c04774dc;
    }
  }
  else {
    if (param_1 == 4) {
      uVar2 = FUN_c0471498();
      return uVar2;
    }
    uVar2 = 0x75;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = uVar3;
  }
  return uVar2;
}



/* c0471738 CTEEnlargedUnsignedDivide */

undefined4 CTEEnlargedUnsignedDivide(void)

{
                    /* 0x1738  3  CTEEnlargedUnsignedDivide */
  return 0x11c1;
}



/* c0471740 FUN_c0471740 */

/* Boundary evidence: original MIPS .pdata c0471740..c04717b3. Semantic name remains unreviewed. */

LONG FUN_c0471740(LONG param_1)

{
  LONG *Target;
  uint uVar1;
  
  Target = &DAT_c0477540;
  uVar1 = 0;
  while ((*Target != 0 || (param_1 = InterlockedExchange(Target,param_1), param_1 != 0))) {
    uVar1 = uVar1 + 4;
    Target = Target + 1;
    if (0x9f < uVar1) {
      return param_1;
    }
  }
  return 0;
}



/* c04717b4 FUN_c04717b4 */

/* Boundary evidence: original MIPS .pdata c04717b4..c0471817. Semantic name remains unreviewed. */

LONG FUN_c04717b4(void)

{
  LONG LVar1;
  LONG *Target;
  uint uVar2;
  
  Target = &DAT_c0477540;
  uVar2 = 0;
  while ((*Target == 0 || (LVar1 = InterlockedExchange(Target,0), LVar1 == 0))) {
    uVar2 = uVar2 + 4;
    Target = Target + 1;
    if (0x9f < uVar2) {
      return 0;
    }
  }
  return LVar1;
}



/* c0471818 FUN_c0471818 */

/* Boundary evidence: original MIPS .pdata c0471818..c04718bb. Semantic name remains unreviewed. */

HKEY FUN_c0471818(int param_1)

{
  LSTATUS LVar1;
  HKEY local_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c0477134;
  if (param_1 == 0) {
    wcscpy(awStack_218,L"Comm\\Cxport");
  }
  else {
    StringCchPrintfW(awStack_218,0x104,L"Comm\\Cxport\\%s",param_1);
  }
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,awStack_218,0,0,local_220);
  if (LVar1 == 0) {
    FUN_c04759a8(local_10);
  }
  else {
    FUN_c04759a8(local_10);
    local_220[0] = (HKEY)0x0;
  }
  return local_220[0];
}



/* c04718bc CTECancelEvent */

undefined4 CTECancelEvent(void)

{
                    /* 0x18bc  2  CTECancelEvent */
  return 0;
}



/* c04718c4 FUN_c04718c4 */

/* Boundary evidence: original MIPS .pdata c04718c4..c047196b. Semantic name remains unreviewed. */

HANDLE FUN_c04718c4(void)

{
  HANDLE pvVar1;
  LONG *Target;
  
  Target = &DAT_c0477520;
  while ((*Target == 0 || (pvVar1 = (HANDLE)InterlockedExchange(Target,0), pvVar1 == (HANDLE)0x0)))
  {
    Target = Target + 1;
    if (-0x3fb88ad1 < (int)Target) {
      pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      return pvVar1;
    }
  }
  EventModify(pvVar1,2);
  return pvVar1;
}



/* c047196c FUN_c047196c */

/* Boundary evidence: original MIPS .pdata c047196c..c04719e3. Semantic name remains unreviewed. */

void FUN_c047196c(HANDLE param_1)

{
  LONG *Target;
  
  Target = &DAT_c0477520;
  while ((*Target != 0 ||
         (param_1 = (HANDLE)InterlockedExchange(Target,(LONG)param_1), param_1 != (HANDLE)0x0))) {
    Target = Target + 1;
    if (-0x3fb88ad1 < (int)Target) {
      CloseHandle(param_1);
      return;
    }
  }
  return;
}



/* c04719e4 CTEStartFTimer */

/* Boundary evidence: original MIPS .pdata c04719e4..c0471aeb. Semantic name remains unreviewed. */

int * CTEStartFTimer(int *param_1,DWORD param_2,DWORD param_3,int param_4,int param_5)

{
  int iVar1;
  LONG LVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  FILETIME local_res4;
  
                    /* 0x19e4  12  CTEStartFTimer */
  piVar4 = &DAT_c0477428;
  local_res4.dwLowDateTime = param_2;
  local_res4.dwHighDateTime = param_3;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0477480);
  piVar5 = piVar4;
  if (DAT_c0477428 != 0) {
    do {
      piVar3 = (int *)*piVar5;
      if (param_1 == piVar3) {
        *piVar5 = *param_1;
        iVar1 = DAT_c0477428;
        break;
      }
      piVar5 = piVar3;
      iVar1 = DAT_c0477428;
    } while (*piVar3 != 0);
    while ((iVar1 != 0 &&
           (LVar2 = CompareFileTime((FILETIME *)(*piVar4 + 8),&local_res4), LVar2 < 0))) {
      piVar4 = (int *)*piVar4;
      iVar1 = *piVar4;
    }
  }
  param_1[1] = param_4;
  param_1[2] = local_res4.dwLowDateTime;
  param_1[3] = local_res4.dwHighDateTime;
  param_1[4] = param_5;
  *param_1 = *piVar4;
  *piVar4 = (int)param_1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0477480);
  return param_1;
}



/* c0471aec CTEStopFTimer */

/* Boundary evidence: original MIPS .pdata c0471aec..c0471b8b. Semantic name remains unreviewed. */

undefined4 CTEStopFTimer(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
                    /* 0x1aec  14  CTEStopFTimer */
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0477480);
  piVar1 = &DAT_c0477428;
  iVar3 = DAT_c0477428;
  do {
    if (iVar3 == 0) {
LAB_c0471b60:
      *param_1 = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0477480);
      return uVar4;
    }
    piVar2 = (int *)*piVar1;
    if (param_1 == piVar2) {
      uVar4 = 1;
      *piVar1 = *param_1;
      goto LAB_c0471b60;
    }
    iVar3 = *piVar2;
    piVar1 = piVar2;
  } while( true );
}



/* c0471b8c CTEGetTimerState */

undefined4 CTEGetTimerState(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x1b8c  6  CTEGetTimerState */
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
  }
  return uVar1;
}



/* c0471ba0 GetRegDWORDValue */

/* Boundary evidence: original MIPS .pdata c0471ba0..c0471c37. Semantic name remains unreviewed. */

undefined4 GetRegDWORDValue(HKEY param_1,LPCWSTR param_2,undefined4 *param_3)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  DWORD local_20;
  DWORD local_1c;
  undefined4 local_18 [2];
  
                    /* 0x1ba0  34  GetRegDWORDValue */
  local_20 = 4;
  dwErrCode = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_1c,(LPBYTE)local_18,&local_20);
  if (((dwErrCode == 0) && (local_20 == 4)) && (local_1c == 4)) {
    uVar1 = 1;
    *param_3 = local_18[0];
  }
  else {
    SetLastError(dwErrCode);
    uVar1 = 0;
  }
  return uVar1;
}



/* c0471c38 SetRegDWORDValue */

/* Boundary evidence: original MIPS .pdata c0471c38..c0471c97. Semantic name remains unreviewed. */

bool SetRegDWORDValue(HKEY param_1,LPCWSTR param_2,undefined4 param_3)

{
  DWORD dwErrCode;
  undefined4 local_res8 [2];
  
                    /* 0x1c38  38  SetRegDWORDValue */
  local_res8[0] = param_3;
  dwErrCode = RegSetValueExW(param_1,param_2,0,4,(BYTE *)local_res8,4);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c0471c98 SetRegSZValue */

/* Boundary evidence: original MIPS .pdata c0471c98..c0471d27. Semantic name remains unreviewed. */

bool SetRegSZValue(HKEY param_1,LPCWSTR param_2,wchar_t *param_3)

{
  size_t sVar1;
  DWORD dwErrCode;
  
                    /* 0x1c98  40  SetRegSZValue */
  sVar1 = wcslen(param_3);
  dwErrCode = RegSetValueExW(param_1,param_2,0,1,(BYTE *)param_3,(sVar1 + 1) * 2);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c0471d28 GetRegMultiSZValue */

/* Boundary evidence: original MIPS .pdata c0471d28..c0471dfb. Semantic name remains unreviewed. */

undefined4 GetRegMultiSZValue(HKEY param_1,LPCWSTR param_2,short *param_3,int param_4)

{
  short sVar1;
  DWORD dwErrCode;
  short *psVar2;
  int iVar3;
  DWORD local_resc;
  DWORD local_10 [2];
  
                    /* 0x1d28  35  GetRegMultiSZValue */
  local_resc = param_4 - 2;
  dwErrCode = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,local_10,(LPBYTE)param_3,&local_resc);
  if (dwErrCode == 0) {
    if (local_10[0] == 1) {
      iVar3 = 0;
      sVar1 = *param_3;
      psVar2 = param_3;
      while (sVar1 != 0) {
        if (*psVar2 == 0x2c) {
          *psVar2 = 0;
          iVar3 = iVar3 + 1;
          psVar2 = psVar2 + 1;
        }
        psVar2 = psVar2 + 1;
        iVar3 = iVar3 + 1;
        sVar1 = *psVar2;
      }
      param_3[iVar3 + 1] = 0;
      return 1;
    }
    if (local_10[0] == 7) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0471dfc SetRegMultiSZValue */

/* Boundary evidence: original MIPS .pdata c0471dfc..c0471efb. Semantic name remains unreviewed. */

bool SetRegMultiSZValue(HKEY param_1,LPCWSTR param_2,wchar_t *param_3)

{
  wchar_t wVar1;
  DWORD dwErrCode;
  size_t sVar2;
  wchar_t *_Str;
  int iVar3;
  
                    /* 0x1dfc  39  SetRegMultiSZValue */
  if (param_3 == (wchar_t *)0x0) {
    dwErrCode = RegSetValueExW(param_1,param_2,0,7,"",2);
  }
  else {
    iVar3 = 0;
    wVar1 = *param_3;
    _Str = param_3;
    while (wVar1 != L'\0') {
      sVar2 = wcslen(_Str);
      iVar3 = sVar2 + iVar3 + 1;
      _Str = param_3 + iVar3;
      wVar1 = *_Str;
    }
    dwErrCode = RegSetValueExW(param_1,param_2,0,7,(BYTE *)param_3,(iVar3 + 1) * 2);
  }
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c0471efc GetRegSZValue */

/* Boundary evidence: original MIPS .pdata c0471efc..c0471f63. Semantic name remains unreviewed. */

undefined4 GetRegSZValue(HKEY param_1,LPCWSTR param_2,LPBYTE param_3,DWORD param_4)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  DWORD local_resc;
  DWORD local_10 [2];
  
                    /* 0x1efc  36  GetRegSZValue */
  local_resc = param_4;
  dwErrCode = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,local_10,param_3,&local_resc);
  if ((dwErrCode != 0) || (uVar1 = 1, local_10[0] != 1)) {
    SetLastError(dwErrCode);
    uVar1 = 0;
  }
  return uVar1;
}



/* c0471f64 GetRegBinaryValue */

/* Boundary evidence: original MIPS .pdata c0471f64..c0471fc7. Semantic name remains unreviewed. */

undefined4 GetRegBinaryValue(HKEY param_1,LPCWSTR param_2,LPBYTE param_3,LPDWORD param_4)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  DWORD local_10 [2];
  
                    /* 0x1f64  33  GetRegBinaryValue */
  dwErrCode = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,local_10,param_3,param_4);
  if ((dwErrCode == 0) && (local_10[0] == 3)) {
    uVar1 = 1;
  }
  else {
    SetLastError(dwErrCode);
    uVar1 = 0;
  }
  return uVar1;
}



/* c0471fc8 SetRegBinaryValue */

/* Boundary evidence: original MIPS .pdata c0471fc8..c047201b. Semantic name remains unreviewed. */

bool SetRegBinaryValue(HKEY param_1,LPCWSTR param_2,BYTE *param_3,DWORD param_4)

{
  DWORD dwErrCode;
  
                    /* 0x1fc8  37  SetRegBinaryValue */
  dwErrCode = RegSetValueExW(param_1,param_2,0,3,param_3,param_4);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c047201c FUN_c047201c */

/* Boundary evidence: original MIPS .pdata c047201c..c0472087. Semantic name remains unreviewed. */

uint FUN_c047201c(uint param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  uint local_10 [2];
  
  local_10[0] = 0;
  if (param_3 != 0x1000) {
    iVar1 = AllocPhysMem(param_2,4,0,0,local_10);
    *param_4 = iVar1;
    if (iVar1 == 0) {
      param_1 = 0;
    }
    else {
      param_1 = local_10[0] | 0x80000000;
    }
  }
  return param_1;
}



/* c0472088 FUN_c0472088 */

/* Boundary evidence: original MIPS .pdata c0472088..c04720c3. Semantic name remains unreviewed. */

undefined4 FUN_c0472088(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_3 == 0x8000) && (iVar2 = FreePhysMem(param_4), iVar2 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c04720c4 FUN_c04720c4 */

/* Boundary evidence: original MIPS .pdata c04720c4..c0472507. Semantic name remains unreviewed. */

undefined4 FUN_c04720c4(void)

{
  uint *puVar1;
  HKEY hKey;
  int iVar2;
  size_t sVar3;
  long lVar4;
  undefined4 *puVar5;
  wchar_t *pwVar6;
  uint uVar7;
  wchar_t local_430 [512];
  uint local_30 [2];
  
  local_30[0] = DAT_c0477134;
  if (DAT_c04775f8 != 0) {
    hKey = FUN_c0471818(-0x3fb8ef6c);
    if (hKey != (HKEY)0x0) {
      iVar2 = GetRegMultiSZValue(hKey,L"Sizes",local_430,0x400);
      if (iVar2 == 0) {
        RegCloseKey(hKey);
      }
      else {
        DAT_c0477610 = 1;
        pwVar6 = local_430;
        do {
          uVar7 = DAT_c0477610;
          if (*pwVar6 == L'\0') break;
          sVar3 = wcslen(pwVar6);
          pwVar6 = pwVar6 + sVar3 + 1;
          DAT_c0477610 = uVar7 + 1;
        } while (pwVar6 < local_30);
        DAT_c04774a0 = HeapAlloc(DAT_c0477494,0,DAT_c0477610 * 0x54);
        DAT_c04775e8 = HeapAlloc(DAT_c0477494,0,DAT_c0477610 << 2);
        DAT_c04775e4 = HeapAlloc(DAT_c0477494,0,DAT_c0477610 << 2);
        if (DAT_c04774a0 != (LPVOID)0x0) {
          if ((DAT_c04775e8 != (uint *)0x0) && (DAT_c04775e4 != (LPVOID)0x0)) {
            pwVar6 = local_430;
            uVar7 = 0;
            if (DAT_c0477610 != 1) {
              iVar2 = 0;
              do {
                if (local_30 <= pwVar6) break;
                lVar4 = wcstol(pwVar6,(wchar_t **)0x0,10);
                *(long *)(iVar2 + (int)DAT_c04775e8) = lVar4;
                *(undefined4 *)(iVar2 + (int)DAT_c04775e4) = DAT_c047745c;
                sVar3 = wcslen(pwVar6);
                uVar7 = uVar7 + 1;
                pwVar6 = pwVar6 + sVar3 + 1;
                iVar2 = iVar2 + 4;
              } while (uVar7 < DAT_c0477610 - 1);
            }
            DAT_c04775e8[DAT_c0477610 - 1] = 0xffffffff;
            uVar7 = 1;
            puVar1 = DAT_c04775e8;
            if (1 < DAT_c0477610) {
              do {
                if (puVar1[1] <= *puVar1) {
                  HeapFree(DAT_c0477494,0,DAT_c04774a0);
                  HeapFree(DAT_c0477494,0,DAT_c04775e8);
                  goto LAB_c04723f4;
                }
                uVar7 = uVar7 + 1;
                puVar1 = puVar1 + 1;
              } while (uVar7 < DAT_c0477610);
            }
            iVar2 = GetRegMultiSZValue(hKey,L"Limits",local_430,0x400);
            if (iVar2 != 0) {
              pwVar6 = local_430;
              uVar7 = 0;
              if (DAT_c0477610 != 1) {
                iVar2 = 0;
                do {
                  if (local_30 <= pwVar6) break;
                  lVar4 = wcstol(pwVar6,(wchar_t **)0x0,10);
                  *(long *)(iVar2 + (int)DAT_c04775e4) = lVar4;
                  sVar3 = wcslen(pwVar6);
                  uVar7 = uVar7 + 1;
                  pwVar6 = pwVar6 + sVar3 + 1;
                  iVar2 = iVar2 + 4;
                } while (uVar7 < DAT_c0477610 - 1);
              }
            }
            RegCloseKey(hKey);
            goto LAB_c0472380;
          }
          HeapFree(DAT_c0477494,0,DAT_c04774a0);
        }
        if (DAT_c04775e8 != (uint *)0x0) {
          HeapFree(DAT_c0477494,0,DAT_c04775e8);
        }
        if (DAT_c04775e4 != (LPVOID)0x0) {
LAB_c04723f4:
          HeapFree(DAT_c0477494,0,DAT_c04775e4);
        }
        RegCloseKey(hKey);
      }
    }
    DAT_c0477610 = 0x10;
    DAT_c04775e8 = (uint *)&DAT_c04770f4;
    DAT_c04774a0 = HeapAlloc(DAT_c0477494,0,0x540);
    DAT_c04775e4 = HeapAlloc(DAT_c0477494,0,DAT_c0477610 << 2);
    if (DAT_c04774a0 != (LPVOID)0x0) {
      if (DAT_c04775e4 != (LPVOID)0x0) {
        uVar7 = 0;
        do {
          puVar5 = (undefined4 *)(uVar7 + (int)DAT_c04775e4);
          uVar7 = uVar7 + 4;
          *puVar5 = DAT_c047745c;
        } while (uVar7 < 0x40);
LAB_c0472380:
        FUN_c04759a8(local_30[0]);
        return 1;
      }
      HeapFree(DAT_c0477494,0,DAT_c04774a0);
    }
    if (DAT_c04775e4 != (LPVOID)0x0) {
      HeapFree(DAT_c0477494,0,DAT_c04775e4);
    }
  }
  FUN_c04759a8(local_30[0]);
  return 0;
}



/* c0472508 FUN_c0472508 */

/* Boundary evidence: original MIPS .pdata c0472508..c04725ab. Semantic name remains unreviewed. */

void FUN_c0472508(LONG *param_1)

{
  LONG *Value;
  LONG *Target;
  uint uVar1;
  
  Value = (LONG *)param_1[0x11];
  if (Value != (LONG *)0x0) {
    uVar1 = 0;
    param_1[0x11] = *Value;
    Target = param_1;
    do {
      Target = Target + 1;
      if ((*Target == 0) &&
         (Value = (LONG *)InterlockedExchange(Target,(LONG)Value), Value == (LONG *)0x0)) {
        Value = (LONG *)param_1[0x11];
        if (Value == (LONG *)0x0) {
          return;
        }
        param_1[0x11] = *Value;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 10);
    if (Value != (LONG *)0x0) {
      *Value = param_1[0x11];
      param_1[0x11] = (LONG)Value;
    }
  }
  return;
}



/* c04725ac FUN_c04725ac */

/* Boundary evidence: original MIPS .pdata c04725ac..c04725fb. Semantic name remains unreviewed. */

undefined4 * FUN_c04725ac(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x44);
  if ((puVar1 == (undefined4 *)0x0) &&
     (puVar1 = (undefined4 *)InterlockedExchange((LONG *)(param_1 + 0x2c),0),
     puVar1 == (undefined4 *)0x0)) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *(undefined4 *)(param_1 + 0x44) = *puVar1;
  }
  return puVar1;
}



/* c04725fc CTEFreeMem */

/* Boundary evidence: original MIPS .pdata c04725fc..c0472797. Semantic name remains unreviewed. */

void CTEFreeMem(int *param_1)

{
  bool bVar1;
  int *Value;
  int Comperand;
  LONG LVar2;
  int *piVar3;
  int *Target;
  uint uVar4;
  
                    /* 0x25fc  4  CTEFreeMem */
  if (DAT_c04775f8 != 0) {
    if (param_1 == (int *)0x0) {
      return;
    }
    Value = param_1 + -4;
    if (param_1[-3] != -0x5eef3582) {
      trap(0x400);
      return;
    }
    piVar3 = (int *)param_1[-1];
    if (piVar3 < DAT_c04774a0) {
      return;
    }
    if (DAT_c04774a0 + DAT_c0477610 * 0x15 + -0x15 < piVar3) {
      return;
    }
    if (*piVar3 != -0x6ffe6fff) {
      trap(0x400);
    }
    if (piVar3 != DAT_c04774a0 + DAT_c0477610 * 0x15 + -0x15) {
      if (*(int *)((int)Value + piVar3[0x12] + 0x10) != 0x4c494154) {
        trap(0x400);
      }
      param_1[-3] = -0x6110612;
      uVar4 = 0;
      Target = piVar3;
      while ((Target = Target + 1, *Target != 0 ||
             (Value = (int *)InterlockedExchange(Target,(LONG)Value), Value != (int *)0x0))) {
        uVar4 = uVar4 + 1;
        if (9 < uVar4) {
          Comperand = piVar3[0xb];
          do {
            *Value = Comperand;
            LVar2 = InterlockedCompareExchange(piVar3 + 0xb,(LONG)Value,Comperand);
            bVar1 = LVar2 != Comperand;
            Comperand = LVar2;
          } while (bVar1);
          return;
        }
      }
      return;
    }
    if (*(int *)((int)Value + param_1[-2] + -4) != 0x4c494154) {
      trap(0x400);
    }
    param_1[-3] = 0;
    param_1 = Value;
  }
  HeapFree(DAT_c0477494,0,param_1);
  return;
}



/* c0472798 FUN_c0472798 */

/* Boundary evidence: original MIPS .pdata c0472798..c0472aeb. Semantic name remains unreviewed. */

void FUN_c0472798(int param_1)

{
  bool bVar1;
  int *piVar2;
  LPVOID lpMem;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar8 = 0;
  if (param_1 == 0) {
    uVar8 = 0x800;
  }
  uVar9 = 0;
  if (DAT_c0477610 != 1) {
    iVar10 = 0;
    do {
      piVar6 = (int *)(iVar10 + DAT_c04774a0);
      if (*piVar6 != -0x6ffe6fff) {
        trap(0x400);
      }
      piVar2 = (int *)InterlockedExchange(piVar6 + 0xb,0);
      if (piVar2 != (int *)0x0) {
        iVar3 = *piVar2;
        piVar7 = piVar2;
        while (iVar3 != 0) {
          piVar7 = (int *)*piVar7;
          iVar3 = *piVar7;
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(piVar6 + 0xc));
        *piVar7 = piVar6[0x11];
        piVar6[0x11] = (int)piVar2;
        LeaveCriticalSection((LPCRITICAL_SECTION)(piVar6 + 0xc));
      }
      if (piVar6[0x11] != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(piVar6 + 0xc));
        iVar3 = 0;
        for (piVar7 = (int *)piVar6[0x11]; piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
          iVar3 = iVar3 + 1;
        }
        piVar6[0x13] = iVar3;
        LeaveCriticalSection((LPCRITICAL_SECTION)(piVar6 + 0xc));
      }
      if (((uint)piVar6[0x14] < (uint)(piVar6[0x13] * piVar6[0x12])) || (param_1 != 0)) {
        EnterCriticalSection((LPCRITICAL_SECTION)(piVar6 + 0xc));
        uVar5 = 0;
        if (param_1 == 0) {
          uVar4 = piVar6[0x12];
          if (uVar4 == 0) {
            trap(0x1c00);
          }
          uVar4 = (piVar6[0x13] * uVar4 - piVar6[0x14]) / uVar4 >> 2;
        }
        else {
          uVar4 = piVar6[0x13];
        }
        if ((uVar4 != 0) && (piVar2 = (int *)piVar6[0x11], piVar2 != (int *)0x0)) {
          piVar7 = piVar2;
          if (uVar4 != 0) {
            do {
              uVar5 = uVar5 + 1;
              if ((uVar5 == uVar4) || ((int *)*piVar7 == (int *)0x0)) {
                piVar6[0x11] = *piVar7;
                *piVar7 = 0;
                break;
              }
              piVar7 = (int *)*piVar7;
            } while (uVar5 < uVar4);
          }
          piVar6[0x13] = piVar6[0x13] - uVar5;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(piVar6 + 0xc));
        if (uVar5 != 0) {
          while (piVar2 != (int *)0x0) {
            piVar7 = (int *)*piVar2;
            if (*(int *)((int)piVar2 + piVar6[0x12] + 0x10) != 0x4c494154) {
              trap(0x400);
            }
            HeapFree(DAT_c0477494,0,piVar2);
            piVar2 = piVar7;
          }
        }
      }
      if (uVar8 <= (uint)piVar6[0x12]) {
        bVar1 = param_1 == 0;
        if (bVar1) {
          iVar3 = 1;
        }
        else {
          iVar3 = 10;
        }
        uVar5 = 0;
        piVar2 = piVar6;
        do {
          piVar2 = piVar2 + 1;
          if (*piVar2 != 0) {
            if (bVar1) {
              bVar1 = false;
            }
            else {
              lpMem = (LPVOID)InterlockedExchange(piVar2,0);
              if (lpMem != (LPVOID)0x0) {
                if (*(int *)((int)lpMem + piVar6[0x12] + 0x10) != 0x4c494154) {
                  trap(0x400);
                }
                HeapFree(DAT_c0477494,0,lpMem);
                iVar3 = iVar3 + -1;
                if (iVar3 == 0) break;
              }
            }
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < 10);
      }
      uVar9 = uVar9 + 1;
      iVar10 = iVar10 + 0x54;
    } while (uVar9 < DAT_c0477610 - 1U);
  }
  return;
}



/* c0472aec FUN_c0472aec */

/* Boundary evidence: original MIPS .pdata c0472aec..c0472b8b. Semantic name remains unreviewed. */

void FUN_c0472aec(void)

{
  uint uVar1;
  
  if (DAT_c0477538 != (code *)0x0) {
    (*DAT_c0477538)(DAT_c0477418,0);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0477500);
  uVar1 = 0;
  do {
    if (*(int **)((int)&DAT_c0477468 + uVar1) != (int *)0x0) {
      CTEFreeMem(*(int **)((int)&DAT_c0477468 + uVar1));
    }
    uVar1 = uVar1 + 4;
  } while (uVar1 < 8);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0477500);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0477500);
  return;
}



/* c0472b8c FUN_c0472b8c */

/* Boundary evidence: original MIPS .pdata c0472b8c..c0472cd3. Semantic name remains unreviewed. */

undefined4 FUN_c0472b8c(void)

{
  int *piVar1;
  LONG LVar2;
  int iVar3;
  
  while( true ) {
    while (piVar1 = (int *)FUN_c04717b4(), piVar1 != (int *)0x0) {
      *(undefined4 *)(piVar1[4] + 0x14) = 0;
      (*(code *)piVar1[1])(piVar1[4],piVar1[2]);
      iVar3 = CeGetThreadPriority(0x41);
      if (iVar3 != DAT_c0477470) {
        CeSetThreadPriority(0x41);
      }
      CTEFreeMem(piVar1);
    }
    EventModify(DAT_c0477618,3);
    if ((DAT_c0477614 != 0) && (LVar2 = InterlockedExchange(&DAT_c0477614,0), LVar2 != 0)) break;
    InterlockedIncrement(&DAT_c0477604);
    WaitForSingleObject(DAT_c0477620,0xffffffff);
    InterlockedDecrement(&DAT_c0477604);
  }
  InterlockedDecrement(&DAT_c04774e0);
  return 0;
}



/* c0472cd4 FUN_c0472cd4 */

/* Boundary evidence: original MIPS .pdata c0472cd4..c0472dff. Semantic name remains unreviewed. */

void FUN_c0472cd4(void)

{
  HANDLE hObject;
  DWORD aDStack_30 [2];
  
  do {
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0472b8c,DAT_c047742c,0,aDStack_30);
    if (hObject == (HANDLE)0x0) {
      if (DAT_c04774e0 != 0) {
        return;
      }
      Sleep(5000);
    }
    else {
      InterlockedIncrement(&DAT_c04774e0);
      InterlockedIncrement((LONG *)&DAT_c047742c);
      CeSetThreadQuantum(hObject,DAT_c04775f0);
      CeSetThreadPriority(hObject,DAT_c0477470);
      CloseHandle(hObject);
      DAT_c047742c = (LPVOID)((int)DAT_c047742c + 1);
    }
  } while (hObject == (HANDLE)0x0);
  return;
}



/* c0472e00 FUN_c0472e00 */

/* Boundary evidence: original MIPS .pdata c0472e00..c047304f. Semantic name remains unreviewed. */

void FUN_c0472e00(void)

{
  HKEY hKey;
  int iVar1;
  WCHAR local_238 [260];
  uint local_30;
  
  local_30 = DAT_c0477134;
  DAT_c04774a4 = 10;
  DAT_c0477470 = 0x84;
  DAT_c047760c = (HANDLE)0x0;
  DAT_c0477534 = 1;
  DAT_c04775f0 = 100;
  DAT_c04775f8 = 1;
  DAT_c0477438 = 0;
  DAT_c047745c = 20000;
  DAT_c0477624 = 0;
  DAT_c047741c = 0x100;
  local_238[0] = L'\0';
  hKey = FUN_c0471818(0);
  if (hKey != (HKEY)0x0) {
    GetRegDWORDValue(hKey,L"NoIdleTimerReset",&DAT_c0477438);
    iVar1 = GetRegSZValue(hKey,L"NoIdleTimerEvent",(LPBYTE)local_238,0x208);
    if (iVar1 == 0) {
      local_238[0] = L'\0';
    }
    GetRegDWORDValue(hKey,L"MaxWorkerThreads",&DAT_c04774a4);
    GetRegDWORDValue(hKey,L"MinWorkerThreads",&DAT_c0477534);
    GetRegDWORDValue(hKey,L"Priority256",&DAT_c0477470);
    GetRegDWORDValue(hKey,L"Quantum",&DAT_c04775f0);
    GetRegDWORDValue(hKey,L"FreeLists",&DAT_c04775f8);
    GetRegDWORDValue(hKey,L"FreeLimit",&DAT_c047745c);
    GetRegDWORDValue(hKey,L"PhysHeap",&DAT_c0477624);
    GetRegDWORDValue(hKey,L"RandomBufferSize",&DAT_c047741c);
    RegCloseKey(hKey);
    if (0x10000 < DAT_c047741c) {
      DAT_c047741c = 0x10000;
    }
  }
  if (local_238[0] != L'\0') {
    DAT_c047760c = OpenEventW(0x1f0003,0,local_238);
  }
  FUN_c04759a8(local_30);
  return;
}



/* c0473050 FUN_c0473050 */

/* Boundary evidence: original MIPS .pdata c0473050..c0473217. Semantic name remains unreviewed. */

void FUN_c0473050(void)

{
  int *piVar1;
  int *piVar2;
  DWORD DVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  piVar2 = (int *)InterlockedExchange(&DAT_c0477420,0);
joined_r0xc0473074:
  piVar1 = piVar2;
  if (piVar1 == (int *)0x0) {
    piVar2 = (int *)InterlockedExchange(&DAT_c0477600,0);
    if (piVar2 != (int *)0x0) {
      DVar3 = GetTickCount();
      piVar1 = piVar2;
      do {
        piVar4 = piVar1;
        piVar4[3] = DVar3;
        piVar1 = (int *)*piVar4;
      } while ((int *)*piVar4 != (int *)0x0);
      if (piVar4 == (int *)0x0) {
        *piVar2 = (int)DAT_c0477460;
        DAT_c0477460 = piVar2;
      }
      else {
        *piVar4 = (int)DAT_c0477460;
        DAT_c0477460 = piVar2;
      }
    }
    piVar2 = (int *)InterlockedExchange(&DAT_c04775e0,0);
    do {
      if (piVar2 == (int *)0x0) {
        return;
      }
      iVar7 = *piVar2;
      if (DAT_c0477460 != (int *)0x0) {
        piVar1 = DAT_c0477460;
        piVar4 = (int *)0x0;
        do {
          piVar6 = piVar1;
          if (piVar2[4] == piVar6[4]) {
            piVar2[6] = 1;
            if (piVar4 == (int *)0x0) {
              DAT_c0477460 = (int *)*piVar6;
            }
            else {
              *piVar4 = *piVar6;
            }
            CTEFreeMem(piVar6);
            break;
          }
          piVar1 = (int *)*piVar6;
          piVar4 = piVar6;
        } while ((int *)*piVar6 != (int *)0x0);
      }
      EventModify(piVar2[5],3);
      piVar2 = (int *)iVar7;
    } while( true );
  }
  piVar2 = (int *)*piVar1;
  if (DAT_c0477460 != (int *)0x0) goto code_r0xc0473090;
  goto LAB_c04730f8;
code_r0xc0473090:
  piVar4 = DAT_c0477460;
  piVar6 = (int *)0x0;
  do {
    piVar5 = piVar4;
    if (piVar1[4] == piVar5[4]) {
      CTEFreeMem(piVar1);
      goto joined_r0xc0473074;
    }
  } while (((uint)(piVar1[3] - piVar5[3]) < 0x80000001) &&
          (piVar4 = (int *)*piVar5, piVar6 = piVar5, (int *)*piVar5 != (int *)0x0));
  if (piVar6 == (int *)0x0) {
LAB_c04730f8:
    *piVar1 = (int)DAT_c0477460;
    DAT_c0477460 = piVar1;
  }
  else {
    *piVar1 = *piVar6;
    *piVar6 = (int)piVar1;
  }
  goto joined_r0xc0473074;
}



/* c0473218 FUN_c0473218 */

/* Boundary evidence: original MIPS .pdata c0473218..c047371f. Semantic name remains unreviewed. */

undefined4 FUN_c0473218(void)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  HMODULE pHVar5;
  int *piVar6;
  DWORD DVar7;
  int *piVar8;
  HANDLE hObject;
  LONG LVar9;
  uint uVar10;
  DWORD dwMilliseconds;
  uint uVar11;
  uint uVar12;
  int *local_38 [2];
  FILETIME FStack_30;
  
  DAT_c0477414 = 1;
  uVar12 = 0;
  if ((DAT_c0477438 == 0) && (pHVar5 = LoadLibraryW(L"COREDLL.DLL"), pHVar5 != (HMODULE)0x0)) {
    DAT_c0477530 = GetProcAddressW(pHVar5,L"SystemIdleTimerReset");
  }
  DAT_c0477620 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_c0477604 = 0;
  bVar1 = false;
  uVar10 = 0;
  DAT_c04774e0 = 0;
  DAT_c0477614 = 0;
  DAT_c0477460 = (int *)0x0;
  if (DAT_c0477534 != 0) {
    do {
      FUN_c0472cd4();
      uVar10 = uVar10 + 1;
    } while (uVar10 < DAT_c0477534);
  }
  FUN_c0475414();
  piVar8 = local_38[0];
  piVar6 = local_38[0];
  do {
    if (DAT_c0477414 == 0) {
      DAT_c0477414 = 0;
      while (DAT_c04774e0 != 0) {
        InterlockedExchange(&DAT_c0477614,1);
        EventModify(DAT_c0477620,3);
        Sleep(200);
      }
      while (piVar6 = DAT_c0477460, DAT_c0477460 != (int *)0x0) {
        DAT_c0477460 = (int *)*DAT_c0477460;
        CTEFreeMem(piVar6);
        piVar8 = piVar6;
      }
      while (LVar9 = FUN_c04717b4(), LVar9 != 0) {
        CTEFreeMem(piVar8);
      }
      CloseHandle(DAT_c0477620);
      CloseHandle(DAT_c0477618);
      DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0477480);
      EventModify(DAT_c0477498,3);
      return 0;
    }
    FUN_c0473050();
    piVar8 = DAT_c0477460;
    if (DAT_c0477460 == (int *)0x0) {
LAB_c04733d4:
      dwMilliseconds = 45000;
    }
    else {
      piVar6 = (int *)GetTickCount();
      dwMilliseconds = 0;
      if (0x80000000 < (uint)((int)piVar6 - piVar8[3])) {
        dwMilliseconds = piVar8[3] - (int)piVar6;
      }
      if ((bVar1) && (bVar1 = false, dwMilliseconds < 0x32)) {
        dwMilliseconds = 0x32;
      }
      if (DAT_c04774dc != 0) {
        if (DAT_c047760c != 0) {
          EventModify(DAT_c047760c,3);
        }
        FUN_c0471524();
      }
      if (45000 < dwMilliseconds) goto LAB_c04733d4;
    }
    if (dwMilliseconds == 0) {
      bVar1 = false;
      uVar10 = 0;
      do {
        piVar3 = DAT_c0477460;
        uVar11 = uVar10;
        if ((DAT_c0477460 == (int *)0x0) || (0x80000000 < (uint)((int)piVar6 - DAT_c0477460[3])))
        break;
        piVar8 = DAT_c0477460 + 4;
        piVar4 = (int *)*DAT_c0477460;
        *DAT_c0477460 = 0;
        DAT_c0477460 = piVar4;
        *(undefined4 *)(*piVar8 + 0x14) = 2;
        piVar8 = (int *)FUN_c0471740((LONG)piVar3);
        uVar11 = uVar10 + 1;
        if (piVar8 != (int *)0x0) {
          *piVar8 = (int)DAT_c0477460;
          bVar1 = true;
          DAT_c0477460 = piVar8;
          *(undefined4 *)(piVar8[4] + 0x14) = 1;
          uVar11 = uVar10;
        }
        if ((DAT_c0477604 == 0) && (DAT_c04774e0 < DAT_c04774a4)) {
          FUN_c0472cd4();
        }
        uVar10 = uVar11;
      } while (!bVar1);
      if (DAT_c04774e0 < uVar11) {
        uVar11 = DAT_c04774e0;
      }
      for (; uVar11 != 0; uVar11 = uVar11 - 1) {
        EventModify(DAT_c0477620,3);
      }
      if (60000 < uVar12) {
        uVar12 = 0;
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0477480);
        GetCurrentFT(&FStack_30);
        puVar2 = DAT_c0477428;
        while ((DAT_c0477428 = puVar2, puVar2 != (undefined4 *)0x0 &&
               (LVar9 = CompareFileTime(&FStack_30,(FILETIME *)(puVar2 + 2)), -1 < LVar9))) {
          DAT_c0477428 = (undefined4 *)*puVar2;
          *puVar2 = 0;
          hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)puVar2[1],
                                 (LPVOID)puVar2[4],0,(LPDWORD)local_38);
          CloseHandle(hObject);
          puVar2 = DAT_c0477428;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0477480);
        if (((DAT_c0477604 != 0) && (DAT_c0477534 < DAT_c04774e0)) &&
           ((DAT_c04774e0 != 1 || (DAT_c0477460 == (int *)0x0)))) {
          InterlockedExchange(&DAT_c0477614,1);
          EventModify(DAT_c0477620,3);
        }
      }
    }
    else {
      DVar7 = WaitForSingleObject(DAT_c0477618,dwMilliseconds);
      if (DVar7 == 0x102) {
        uVar12 = dwMilliseconds + uVar12;
      }
    }
  } while( true );
}



/* c0473720 CTEAllocMem */

/* Boundary evidence: original MIPS .pdata c0473720..c0473a4b. Semantic name remains unreviewed. */

undefined4 * CTEAllocMem(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  LONG *pLVar6;
  SIZE_T dwBytes;
  LONG *Target;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar7;
  
                    /* 0x3720  1  CTEAllocMem */
  bVar1 = false;
  if (DAT_c04775f8 == 0) {
    puVar7 = HeapAlloc(DAT_c0477494,0,param_1);
    return puVar7;
  }
  puVar7 = (undefined4 *)0x0;
  iVar4 = (DAT_c0477610 >> 1) + 1;
  if (param_1 <= *(uint *)((DAT_c0477610 >> 1) * 4 + DAT_c04775e8)) {
    iVar4 = 0;
  }
  puVar5 = (uint *)(iVar4 * 4 + DAT_c04775e8);
  uVar3 = *puVar5;
  while (uVar3 < param_1) {
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + 1;
    uVar3 = *puVar5;
  }
  pLVar6 = (LONG *)(iVar4 * 0x54 + DAT_c04774a0);
  iVar4 = DAT_c0477610 * 0x54 + DAT_c04774a0;
  if (pLVar6 == (LONG *)(iVar4 + -0x54)) {
    if (0x1000000 < param_1) {
      return (undefined4 *)0x0;
    }
    dwBytes = param_1 + 0x14;
    pLVar6 = (LONG *)(iVar4 + -0x54);
    if ((dwBytes & 3) != 0) {
      dwBytes = (dwBytes - (dwBytes & 3)) + 4;
    }
    bVar1 = true;
  }
  else {
    if (*pLVar6 != -0x6ffe6fff) {
      trap(0x400);
    }
    uVar3 = 0;
    Target = pLVar6;
    do {
      Target = Target + 1;
      if ((*Target != 0) &&
         (puVar2 = (undefined4 *)InterlockedExchange(Target,0), puVar2 != (undefined4 *)0x0)) {
        if (puVar2[1] != -0x6110612) {
          trap(0x400);
          return (undefined4 *)0x0;
        }
        if (*(int *)((int)puVar2 + pLVar6[0x12] + 0x10) != 0x4c494154) {
          trap(0x400);
        }
        goto LAB_c04739f4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 10);
    lpCriticalSection = (LPCRITICAL_SECTION)(pLVar6 + 0xc);
    EnterCriticalSection(lpCriticalSection);
    puVar2 = FUN_c04725ac((int)pLVar6);
    if (puVar2 != (undefined4 *)0x0) {
      if (puVar2[1] != -0x6110612) {
        trap(0x400);
        LeaveCriticalSection(lpCriticalSection);
        return (undefined4 *)0x0;
      }
      if (pLVar6[0x11] != 0) {
        FUN_c0472508(pLVar6);
      }
      LeaveCriticalSection(lpCriticalSection);
      if (*(int *)((int)puVar2 + pLVar6[0x12] + 0x10) != 0x4c494154) {
        trap(0x400);
      }
      goto LAB_c04739ec;
    }
    LeaveCriticalSection(lpCriticalSection);
    uVar3 = pLVar6[0x12];
    if (uVar3 + 0x10 < uVar3) {
      return (undefined4 *)0x0;
    }
    dwBytes = uVar3 + 0x14;
    if (dwBytes < uVar3 + 0x10) {
      return (undefined4 *)0x0;
    }
  }
  iVar4 = 2;
  while (puVar2 = HeapAlloc(DAT_c0477494,0,dwBytes), puVar2 == (undefined4 *)0x0) {
    FUN_c0472798(1);
    if (iVar4 == 0) goto LAB_c04739ec;
    iVar4 = iVar4 + -1;
  }
  puVar2[3] = pLVar6;
  if (bVar1) {
    *(undefined4 *)((int)puVar2 + (dwBytes - 4)) = 0x4c494154;
    puVar2[2] = dwBytes;
  }
  else {
    *(undefined4 *)((int)puVar2 + pLVar6[0x12] + 0x10) = 0x4c494154;
  }
LAB_c04739ec:
  if (puVar2 != (undefined4 *)0x0) {
LAB_c04739f4:
    puVar2[1] = 0xa110ca7e;
    puVar7 = puVar2 + 4;
  }
  return puVar7;
}



/* c0473a4c FUN_c0473a4c */

/* Boundary evidence: original MIPS .pdata c0473a4c..c0473bcb. Semantic name remains unreviewed. */

void FUN_c0473a4c(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  uVar1 = CeGetThreadPriority(0x41);
  CeSetThreadPriority(0x41,0xfc);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0477500);
  do {
    uVar5 = 0;
    piVar4 = &DAT_c0477468;
    do {
      if (*piVar4 == 0) break;
      uVar5 = uVar5 + 1;
      piVar4 = piVar4 + 1;
    } while ((int)uVar5 < 2);
    if ((1 < uVar5) || (puVar2 = CTEAllocMem(DAT_c047741c), puVar2 == (undefined4 *)0x0)) {
      DAT_c0477608 = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0477500);
      CeSetThreadPriority(0x41,uVar1);
      return;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0477500);
    if ((DAT_c0477464 == (code *)0x0) ||
       (iVar3 = (*DAT_c0477464)(DAT_c0477418,DAT_c047741c,puVar2), iVar3 == 0)) {
      CeGenRandom(DAT_c047741c,puVar2);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0477500);
    (&DAT_c0477468)[uVar5] = puVar2;
    if (uVar5 == DAT_c04775fc) {
      DAT_c047749c = DAT_c047741c;
    }
  } while( true );
}



/* c0473bcc CTEScheduleEvent */

/* Boundary evidence: original MIPS .pdata c0473bcc..c0473cc3. Semantic name remains unreviewed. */

undefined4 CTEScheduleEvent(int param_1,undefined4 param_2)

{
  bool bVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  int *Exchange;
  LONG Comperand;
  LONG LVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
                    /* 0x3bcc  11  CTEScheduleEvent */
  DVar2 = GetTickCount();
  puVar3 = CTEAllocMem(0x1c);
  if (puVar3 == (undefined4 *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = 1;
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(DWORD *)(param_1 + 0xc) = DVar2;
    puVar3[3] = DVar2;
    puVar3[4] = param_1;
    puVar3[1] = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 8) = param_2;
    puVar3[2] = param_2;
    *puVar3 = 0;
    Exchange = (int *)FUN_c0471740((LONG)puVar3);
    Comperand = DAT_c0477600;
    uVar5 = DAT_c0477620;
    if (Exchange != (int *)0x0) {
      do {
        *Exchange = Comperand;
        LVar4 = InterlockedCompareExchange(&DAT_c0477600,(LONG)Exchange,Comperand);
        bVar1 = LVar4 != Comperand;
        Comperand = LVar4;
      } while (bVar1);
      uVar5 = DAT_c0477618;
      if (LVar4 != 0) {
        return 1;
      }
    }
    EventModify(uVar5,3);
  }
  return uVar6;
}



/* c0473cc4 CTEStartTimer */

/* Boundary evidence: original MIPS .pdata c0473cc4..c0473dcf. Semantic name remains unreviewed. */

int CTEStartTimer(int param_1,uint param_2,int param_3,int param_4)

{
  bool bVar1;
  DWORD DVar2;
  int *Exchange;
  int Comperand;
  LONG LVar3;
  
                    /* 0x3cc4  13  CTEStartTimer */
  DVar2 = GetTickCount();
  if (0x7f000000 < param_2) {
    param_2 = 0x7f000000;
  }
  Exchange = CTEAllocMem(0x1c);
  if (Exchange == (int *)0x0) {
    param_1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(DWORD *)(param_1 + 0xc) = DVar2 + param_2;
    Exchange[3] = DVar2 + param_2;
    Exchange[4] = param_1;
    *(int *)(param_1 + 4) = param_3;
    Exchange[1] = param_3;
    *(int *)(param_1 + 8) = param_4;
    Exchange[2] = param_4;
    *Exchange = 0;
    Comperand = DAT_c0477420;
    do {
      *Exchange = Comperand;
      LVar3 = InterlockedCompareExchange(&DAT_c0477420,(LONG)Exchange,Comperand);
      bVar1 = LVar3 != Comperand;
      Comperand = LVar3;
    } while (bVar1);
    if (LVar3 == 0) {
      EventModify(DAT_c0477618,3);
    }
  }
  return param_1;
}



/* c0473dd0 CTEStopTimer */

/* Boundary evidence: original MIPS .pdata c0473dd0..c0473eab. Semantic name remains unreviewed. */

int CTEStopTimer(int param_1)

{
  bool bVar1;
  int *Exchange;
  HANDLE pvVar2;
  LONG LVar3;
  int iVar4;
  
                    /* 0x3dd0  15  CTEStopTimer */
  iVar4 = 0;
  Exchange = CTEAllocMem(0x1c);
  if (Exchange == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    Exchange[4] = param_1;
    *Exchange = 0;
    pvVar2 = FUN_c04718c4();
    Exchange[5] = (int)pvVar2;
    if (pvVar2 != (HANDLE)0x0) {
      Exchange[6] = 0;
      iVar4 = DAT_c04775e0;
      do {
        *Exchange = iVar4;
        LVar3 = InterlockedCompareExchange(&DAT_c04775e0,(LONG)Exchange,iVar4);
        bVar1 = LVar3 != iVar4;
        iVar4 = LVar3;
      } while (bVar1);
      if (LVar3 == 0) {
        EventModify(DAT_c0477618,3);
      }
      WaitForSingleObject((HANDLE)Exchange[5],0xffffffff);
      FUN_c047196c((HANDLE)Exchange[5]);
      iVar4 = Exchange[6];
    }
    CTEFreeMem(Exchange);
  }
  return iVar4;
}



/* c0473eac FUN_c0473eac */

/* Boundary evidence: original MIPS .pdata c0473eac..c0473f33. Semantic name remains unreviewed. */

void FUN_c0473eac(void)

{
  CeSetThreadPriority(0x41,DAT_c0477470 + 100);
  FUN_c0472798(0);
  CeSetThreadPriority(0x41,DAT_c0477470);
  if (DAT_c0477414 != 0) {
    CTEStartTimer(-0x3fb88b40,300000,-0x3fb8c154,0);
  }
  return;
}



/* c0473f34 FUN_c0473f34 */

/* Boundary evidence: original MIPS .pdata c0473f34..c04740bb. Semantic name remains unreviewed. */

void FUN_c0473f34(void)

{
  HMODULE pHVar1;
  int iVar2;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0477500);
  memset(&DAT_c0477468,0,8);
  DAT_c047749c = 0;
  DAT_c04775fc = 0;
  pHVar1 = LoadLibraryW(L"COREDLL.DLL");
  if (pHVar1 != (HMODULE)0x0) {
    DAT_c04775f4 = (code *)GetProcAddressW(pHVar1,L"CryptAcquireContextW");
    DAT_c0477538 = GetProcAddressW(pHVar1,L"CryptReleaseContext");
    DAT_c0477464 = GetProcAddressW(pHVar1,L"CryptGenRandom");
    if (((DAT_c04775f4 == (code *)0x0) || (DAT_c0477538 == 0)) || (DAT_c0477464 == 0)) {
      DAT_c04775f4 = (code *)0x0;
      DAT_c0477538 = 0;
      DAT_c0477464 = 0;
    }
  }
  if ((DAT_c04775f4 != (code *)0x0) &&
     (iVar2 = (*DAT_c04775f4)(&DAT_c0477418,0,0,1,0xf0000040), iVar2 == 0)) {
    DAT_c0477464 = 0;
  }
  DAT_c0477458 = 0;
  DAT_c0477440 = 0xffffffff;
  DAT_c0477444 = FUN_c0473a4c;
  DAT_c0477448 = 0;
  DAT_c0477450 = 0;
  DAT_c0477454 = 0;
  CTEScheduleEvent(-0x3fb88bc0,0);
  return;
}



/* c04740bc CTEGenRandom */

/* Boundary evidence: original MIPS .pdata c04740bc..c04742c7. Semantic name remains unreviewed. */

undefined4 CTEGenRandom(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
                    /* 0x40bc  5  CTEGenRandom */
  iVar5 = 0;
  if ((param_2 == 0) || (DAT_c047741c < param_1)) {
    uVar1 = 0x57;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0477500);
    uVar3 = DAT_c047741c;
    iVar2 = DAT_c0477608;
joined_r0xc0474128:
    if (param_1 != 0) {
      if (DAT_c047749c != 0) goto code_r0xc0474168;
      goto LAB_c04741c0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0477500);
    uVar1 = 0;
  }
  return uVar1;
code_r0xc0474168:
  uVar4 = param_1;
  if (DAT_c047749c <= param_1) {
    uVar4 = DAT_c047749c;
  }
  memcpy((void *)(iVar5 + param_2),(void *)(((&DAT_c0477468)[DAT_c04775fc] - DAT_c047749c) + uVar3),
         uVar4);
  DAT_c047749c = DAT_c047749c - uVar4;
  param_1 = param_1 - uVar4;
  iVar5 = uVar4 + iVar5;
  iVar2 = DAT_c0477608;
  uVar3 = DAT_c047741c;
  if (DAT_c047749c == 0) {
LAB_c04741c0:
    if ((int *)(&DAT_c0477468)[DAT_c04775fc] != (int *)0x0) {
      CTEFreeMem((int *)(&DAT_c0477468)[DAT_c04775fc]);
      iVar2 = DAT_c0477608;
      uVar3 = DAT_c047741c;
      (&DAT_c0477468)[DAT_c04775fc] = 0;
    }
    DAT_c04775fc = DAT_c04775fc + 1;
    if (1 < DAT_c04775fc) {
      DAT_c04775fc = 0;
    }
    uVar4 = uVar3;
    if ((&DAT_c0477468)[DAT_c04775fc] == 0) {
      CeGenRandom(param_1,iVar5 + param_2);
      param_1 = 0;
      iVar2 = DAT_c0477608;
      uVar3 = DAT_c047741c;
      uVar4 = DAT_c047749c;
    }
    DAT_c047749c = uVar4;
    if (iVar2 == 0) {
      DAT_c0477608 = 1;
      CTEScheduleEvent(-0x3fb88bc0,0);
      uVar3 = DAT_c047741c;
      iVar2 = DAT_c0477608;
    }
  }
  goto joined_r0xc0474128;
}



/* c04742c8 FUN_c04742c8 */

/* Boundary evidence: original MIPS .pdata c04742c8..c047447f. Semantic name remains unreviewed. */

void FUN_c04742c8(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  if (DAT_c0477624 == 0) {
    DAT_c0477494 = HeapCreate(0,0,0);
  }
  else {
    DAT_c0477494 = (HANDLE)CeHeapCreate();
  }
  if ((DAT_c0477494 != (HANDLE)0x0) && (iVar1 = FUN_c04720c4(), iVar1 != 0)) {
    uVar3 = 0;
    if (DAT_c0477610 != 0) {
      iVar1 = 0;
      iVar4 = 0;
      do {
        InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + DAT_c04774a0 + 0x30));
        *(undefined4 *)(iVar1 + DAT_c04774a0 + 0x44) = 0;
        *(undefined4 *)(iVar1 + DAT_c04774a0 + 0x2c) = 0;
        memset((void *)(iVar1 + DAT_c04774a0 + 4),0,0x28);
        uVar3 = uVar3 + 1;
        *(undefined4 *)(iVar1 + DAT_c04774a0 + 0x48) = *(undefined4 *)(iVar4 + DAT_c04775e8);
        *(undefined4 *)(iVar1 + DAT_c04774a0 + 0x4c) = 0;
        puVar2 = (undefined4 *)(iVar4 + DAT_c04775e4);
        iVar4 = iVar4 + 4;
        *(undefined4 *)(iVar1 + DAT_c04774a0 + 0x50) = *puVar2;
        *(undefined4 *)(iVar1 + DAT_c04774a0) = 0x90019001;
        iVar1 = iVar1 + 0x54;
      } while (uVar3 < DAT_c0477610);
    }
    DAT_c04774d8 = 0;
    DAT_c04774c0 = 0xffffffff;
    DAT_c04774c4 = 0;
    DAT_c04774c8 = 0;
    DAT_c04774d4 = 0;
    DAT_c04774d0 = 1;
    CTEStartTimer(-0x3fb88b40,300000,-0x3fb8c154,0);
  }
  return;
}



/* c0474480 FUN_c0474480 */

/* Boundary evidence: original MIPS .pdata c0474480..c0474587. Semantic name remains unreviewed. */

undefined4 FUN_c0474480(void)

{
  HANDLE pvVar1;
  DWORD aDStack_10 [2];
  
  DAT_c0477600 = 0;
  DAT_c0477420 = 0;
  DAT_c04775e0 = 0;
  memset(&DAT_c0477540,0,0xa0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0477480);
  FUN_c0472e00();
  DAT_c0477618 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_c0477498 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  FUN_c04742c8();
  FUN_c0473f34();
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0473218,(LPVOID)0x0,0,aDStack_10);
  CeSetThreadQuantum(pvVar1,DAT_c04775f0);
  CeSetThreadPriority(pvVar1,DAT_c0477470);
  return 1;
}



/* c0474588 FUN_c0474588 */

/* Boundary evidence: original MIPS .pdata c0474588..c047465b. Semantic name remains unreviewed. */

undefined4 FUN_c0474588(HMODULE param_1,int param_2,int param_3)

{
  if (param_2 == 0) {
    DAT_c0477414 = 0;
    EventModify(DAT_c0477618,3);
    if (param_3 == 0) {
      WaitForSingleObject(DAT_c0477498,0xffffffff);
    }
    Sleep(100);
    CloseHandle(DAT_c0477498);
    CxLogShutdown();
    FUN_c0472aec();
  }
  else if (param_2 == 1) {
    FUN_c0474480();
    DisableThreadLibraryCalls(param_1);
    CxLogInitialize();
    FUN_c0475414();
  }
  return 1;
}



/* c047465c CTEInitialize */

undefined4 CTEInitialize(void)

{
                    /* 0x465c  10  CTEInitialize
                       0x465c  16  CTE_Close
                       0x465c  17  CTE_Deinit
                       0x465c  19  CTE_Init
                       0x465c  20  CTE_Open */
  return 1;
}



/* c0474664 CTE_Read */

undefined4 CTE_Read(void)

{
                    /* 0x4664  21  CTE_Read
                       0x4664  22  CTE_Seek
                       0x4664  23  CTE_Write */
  return 0xffffffff;
}



/* c047466c CTE_IOControl */

/* Boundary evidence: original MIPS .pdata c047466c..c04747e3. Semantic name remains unreviewed. */

uint CTE_IOControl(undefined4 param_1,int param_2,uint *param_3,uint param_4,STRSAFE_LPSTR param_5,
                  uint param_6)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar2;
  int iVar3;
  STRSAFE_LPSTR pszDest;
  uint uVar4;
  STRSAFE_LPCSTR local_28;
  int local_24;
  uint local_20;
  uint local_18;
  
                    /* 0x466c  18  CTE_IOControl */
  uVar2 = 0;
  if (param_2 == 1000) {
    uVar2 = FUN_c0475414();
  }
  else if (param_2 == 0x3e9) {
    uVar2 = FUN_c0475388();
  }
  else if (param_2 == 0x3ea) {
    if ((((param_3 != (uint *)0x0) && (3 < param_4)) && (param_5 != (STRSAFE_LPSTR)0x0)) &&
       (0x11f < param_6)) {
      uVar4 = *param_3;
      bVar1 = FUN_c04751c0(uVar4,(int *)&local_28);
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        memset(param_5,0,0x120);
        *(uint *)(param_5 + 0x10) = uVar4;
        StringCbCopyA(param_5,0x10,local_28);
        uVar2 = 0;
        *(uint *)(param_5 + 0x14) = local_18 >> 0x10 & 0xff;
        *(uint *)(param_5 + 0x18) = local_18 & 0xffff;
        *(uint *)(param_5 + 0x1c) = local_20;
        if (local_20 != 0) {
          iVar3 = 0;
          pszDest = param_5 + 0x20;
          do {
            StringCbCopyA(pszDest,0x10,*(STRSAFE_LPCSTR *)(iVar3 + local_24));
            uVar2 = uVar2 + 1;
            pszDest = pszDest + 0x10;
            iVar3 = iVar3 + 4;
          } while (uVar2 < local_20);
        }
        uVar2 = 1;
      }
    }
  }
  else if ((param_2 == 0x3eb) && (0xb < param_4)) {
    bVar1 = FUN_c0475274(*param_3,param_3[1],param_3[2]);
    uVar2 = CONCAT31(extraout_var,bVar1);
  }
  return uVar2;
}



/* c04747e4 FUN_c04747e4 */

/* Boundary evidence: original MIPS .pdata c04747e4..c0474923. Semantic name remains unreviewed. */

DWORD FUN_c04747e4(LPCWSTR param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  HMODULE hLibModule;
  DWORD DVar3;
  
  hLibModule = (HMODULE)*param_2;
  DVar3 = 0;
  if ((hLibModule == (HMODULE)0x0) &&
     (hLibModule = LoadLibraryW(param_1), hLibModule == (HMODULE)0x0)) {
    DVar3 = GetLastError();
  }
  else {
    do {
      piVar2 = (int *)((int)param_3 + 3U & 0xfffffffc);
      if (*piVar2 == 0) goto LAB_c04748f0;
      param_3 = piVar2 + 2;
      piVar2 = (int *)piVar2[1];
      iVar1 = GetProcAddressW(hLibModule);
      *piVar2 = iVar1;
    } while ((param_4 == 0) || (iVar1 != 0));
    DVar3 = GetLastError();
    if ((DVar3 != 0) && (*param_2 == 0)) {
      FreeLibrary(hLibModule);
      hLibModule = (HMODULE)0x0;
    }
LAB_c04748f0:
    *param_2 = (int)hLibModule;
  }
  return DVar3;
}



/* c0474924 CXUtilGetProcAddresses */

/* Boundary evidence: original MIPS .pdata c0474924..c047494f. Semantic name remains unreviewed. */

void CXUtilGetProcAddresses(LPCWSTR param_1,int *param_2,int param_3,undefined4 param_4)

{
  int local_res8;
  undefined4 local_resc;
  
                    /* 0x4924  24  CXUtilGetProcAddresses */
  local_res8 = param_3;
  local_resc = param_4;
  FUN_c04747e4(param_1,param_2,&local_res8,1);
  return;
}



/* c0474950 CXUtilTryGetProcAddresses */

/* Boundary evidence: original MIPS .pdata c0474950..c047497b. Semantic name remains unreviewed. */

void CXUtilTryGetProcAddresses(LPCWSTR param_1,int *param_2,int param_3,undefined4 param_4)

{
  int local_res8;
  undefined4 local_resc;
  
                    /* 0x4950  25  CXUtilTryGetProcAddresses */
  local_res8 = param_3;
  local_resc = param_4;
  FUN_c04747e4(param_1,param_2,&local_res8,0);
  return;
}



/* c047497c CxRegReadValues */

/* Boundary evidence: original MIPS .pdata c047497c..c0474c9f. Semantic name remains unreviewed. */

int CxRegReadValues(HKEY param_1,LPCWSTR param_2,undefined4 param_3,undefined4 param_4)

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
  
                    /* 0x497c  31  CxRegReadValues */
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
            goto LAB_c0474bb4;
          }
        }
        else {
          lpData = LocalAlloc(0x40,local_34);
          if (lpData == (LPBYTE)0x0) {
            dwErrCode = 0xe;
LAB_c0474bb4:
            SetLastError(dwErrCode);
          }
          else {
            local_38 = local_34;
          }
          if (lpData == (LPBYTE)0x0) goto LAB_c0474c30;
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
LAB_c0474c30:
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



/* c0474ca0 CxRegWriteValues */

/* Boundary evidence: original MIPS .pdata c0474ca0..c0474e4b. Semantic name remains unreviewed. */

int CxRegWriteValues(HKEY param_1,LPCWSTR param_2,undefined4 param_3,undefined4 param_4)

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
  
                    /* 0x4ca0  32  CxRegWriteValues */
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



/* c0474e4c CxLogInitialize */

/* Boundary evidence: original MIPS .pdata c0474e4c..c0474e6b. Semantic name remains unreviewed. */

void CxLogInitialize(void)

{
                    /* 0x4e4c  27  CxLogInitialize */
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0477400);
  return;
}



/* c0474e6c CxLogShutdown */

/* Boundary evidence: original MIPS .pdata c0474e6c..c0474e8b. Semantic name remains unreviewed. */

void CxLogShutdown(void)

{
                    /* 0x4e6c  30  CxLogShutdown */
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0477400);
  return;
}



/* c0474e8c CxLogRegister */

/* Boundary evidence: original MIPS .pdata c0474e8c..c047500f. Semantic name remains unreviewed. */

int CxLogRegister(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_240;
  wchar_t awStack_238 [260];
  uint local_30;
  
                    /* 0x4e8c  29  CxLogRegister */
  local_30 = DAT_c0477134;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0477400);
  iVar4 = 0;
  uVar3 = 0;
  do {
    if (*(int *)((int)&DAT_c0477180 + uVar3) == 0) {
      iVar1 = iVar4 * 0x14;
      (&DAT_c0477180)[iVar4 * 5] = param_1;
      *(undefined4 *)(&DAT_c0477184 + iVar1) = param_2;
      *(undefined4 *)(&DAT_c0477188 + iVar1) = param_3;
      *(undefined4 **)(&DAT_c047718c + iVar1) = param_4;
      StringCbPrintfW(awStack_238,0x208,L"Comm\\CxLog\\%hs",param_1);
      iVar2 = CxRegReadValues((HKEY)0x80000002,awStack_238,L"Filter",4);
      if (iVar2 != 0) {
        *param_4 = local_240;
      }
      *(undefined4 *)(&DAT_c0477190 + iVar1) = *param_4;
      break;
    }
    uVar3 = uVar3 + 0x14;
    iVar4 = iVar4 + 1;
  } while (uVar3 < 0x280);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0477400);
  if (iVar4 == 0x20) {
    iVar4 = -1;
  }
  FUN_c04759a8(local_30);
  return iVar4;
}



/* c0475010 CxLogDeregister */

void CxLogDeregister(uint param_1)

{
                    /* 0x5010  26  CxLogDeregister */
  if (param_1 < 0x20) {
    (&DAT_c0477180)[param_1 * 5] = 0;
    *(undefined4 *)(&DAT_c0477184 + param_1 * 0x14) = 0;
    *(undefined4 *)(&DAT_c047718c + param_1 * 0x14) = 0;
  }
  return;
}



/* c0475058 FUN_c0475058 */

/* Boundary evidence: original MIPS .pdata c0475058..c0475163. Semantic name remains unreviewed. */

void FUN_c0475058(int param_1,int param_2,STRSAFE_LPCSTR param_3,va_list param_4)

{
  size_t sVar1;
  char *pcVar2;
  char acStack_418 [1024];
  uint local_18;
  
  local_18 = DAT_c0477134;
  if (param_1 != 0) {
    if (param_2 == 0) {
      pcVar2 = "FATAL-";
    }
    else if (param_2 == 1) {
      pcVar2 = "ERROR-";
    }
    else if (param_2 == 2) {
      pcVar2 = "WARN- ";
    }
    else if (param_2 == 3) {
      pcVar2 = "";
    }
    else {
      pcVar2 = "???";
    }
    StringCbPrintfA(acStack_418,0x400,"%hs: %hs",param_1,pcVar2);
    sVar1 = strlen(acStack_418);
    StringCbVPrintfA(acStack_418 + sVar1,0x400 - sVar1,param_3,param_4);
    if (g_pLogEvent != (code *)0x0) {
      (*g_pLogEvent)(acStack_418);
    }
  }
  FUN_c04759a8(local_18);
  return;
}



/* c0475164 CxLogMsg */

/* Boundary evidence: original MIPS .pdata c0475164..c04751bf. Semantic name remains unreviewed. */

void CxLogMsg(uint param_1,STRSAFE_LPCSTR param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res8;
  undefined4 local_resc;
  
                    /* 0x5164  28  CxLogMsg */
  if (param_1 >> 0x18 < 0x20) {
    local_res8 = param_3;
    local_resc = param_4;
    FUN_c0475058((&DAT_c0477180)[(param_1 >> 0x18) * 5],param_1 >> 0x10 & 0xff,param_2,
                 (va_list)&local_res8);
  }
  return;
}



/* c04751c0 FUN_c04751c0 */

/* Boundary evidence: original MIPS .pdata c04751c0..c0475273. Semantic name remains unreviewed. */

bool FUN_c04751c0(uint param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_1 < 0x20) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0477400);
    iVar1 = param_1 * 0x14;
    bVar2 = (&DAT_c0477180)[param_1 * 5] != 0;
    if (bVar2) {
      *param_2 = (&DAT_c0477180)[param_1 * 5];
      param_2[1] = *(int *)(&DAT_c0477184 + iVar1);
      param_2[2] = *(int *)(&DAT_c0477188 + iVar1);
      param_2[3] = *(int *)(&DAT_c047718c + iVar1);
      param_2[4] = *(int *)(&DAT_c0477190 + iVar1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0477400);
  }
  return bVar2;
}



/* c0475274 FUN_c0475274 */

/* Boundary evidence: original MIPS .pdata c0475274..c0475387. Semantic name remains unreviewed. */

bool FUN_c0475274(uint param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c0477134;
  bVar3 = false;
  if (param_1 < 0x20) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0477400);
    bVar3 = *(uint **)(&DAT_c047718c + param_1 * 0x14) != (uint *)0x0;
    if (bVar3) {
      uVar2 = param_2 << 0x10 | param_3;
      **(uint **)(&DAT_c047718c + param_1 * 0x14) = uVar2;
      uVar1 = (&DAT_c0477180)[param_1 * 5];
      *(uint *)(&DAT_c0477190 + param_1 * 0x14) = uVar2;
      StringCbPrintfW(awStack_228,0x208,L"Comm\\CxLog\\%hs",uVar1);
      CxRegWriteValues((HKEY)0x80000002,awStack_228,L"Filter",4);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0477400);
  }
  FUN_c04759a8(local_20);
  return bVar3;
}



/* c0475388 FUN_c0475388 */

/* Boundary evidence: original MIPS .pdata c0475388..c0475413. Semantic name remains unreviewed. */

undefined4 FUN_c0475388(void)

{
  g_pLogNdisSendPackets = 0;
  g_pLogNdisSend = 0;
  g_pLogMiniportIndicateReceive = 0;
  g_pLogMiniportIndicateReceivePackets = 0;
  g_pLogNdisTransferData = 0;
  g_pLogEvent = 0;
  g_pLogTxNdisWanPacket = 0;
  g_pLogRxContigPacket = 0;
  if (DAT_c0477154 != 0) {
    FreeLibrary((HMODULE)DAT_c0477154);
    DAT_c0477154 = 0;
  }
  return 1;
}



/* c0475414 FUN_c0475414 */

/* Boundary evidence: original MIPS .pdata c0475414..c0475533. Semantic name remains unreviewed. */

undefined4 FUN_c0475414(void)

{
  if (((DAT_c0477154 == 0) &&
      (CXUtilGetProcAddresses(L"netlog.dll",&DAT_c0477154,-0x3fb8ed14,&g_pLogNdisSend),
      DAT_c0477154 == 0)) && (FUN_c0475388(), DAT_c0477154 == 0)) {
    return 0;
  }
  return 1;
}



/* c04756f4 FUN_c04756f4 */

/* Boundary evidence: original MIPS .pdata c04756f4..c047582f. Semantic name remains unreviewed. */

int FUN_c04756f4(HMODULE param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c0477634 != (code *)0x0) {
      iVar2 = (*DAT_c0477634)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c04757a4;
    FUN_c0475b88();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0474588(param_1,param_2,param_3);
  }
LAB_c04757a4:
  if (((param_2 == 0) && (FUN_c0475b10(), iVar1 != 0)) && (DAT_c0477634 != (code *)0x0)) {
    iVar1 = (*DAT_c0477634)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0475830 FUN_c0475830 */

/* Boundary evidence: original MIPS .pdata c0475830..c047585b. Semantic name remains unreviewed. */

void FUN_c0475830(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c047585c entry */

/* Boundary evidence: original MIPS .pdata c047585c..c04758b3. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,int param_3)

{
  if (param_2 == 1) {
    FUN_c04758b4();
  }
  FUN_c04756f4(param_1,param_2,param_3);
  return;
}



/* c04758b4 FUN_c04758b4 */

/* Boundary evidence: original MIPS .pdata c04758b4..c0475927. Semantic name remains unreviewed. */

void FUN_c04758b4(void)

{
  uint uVar1;
  
  if ((DAT_c0477134 == 0) || (DAT_c0477134 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0477134 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0477134 == 0) {
      DAT_c0477134 = 0xb064;
    }
  }
  DAT_c0477138 = ~DAT_c0477134;
  return;
}



/* c0475928 FUN_c0475928 */

/* Boundary evidence: original MIPS .pdata c0475928..c047597b. Semantic name remains unreviewed. */

void FUN_c0475928(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c04759a8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c047597c FUN_c047597c */

/* Boundary evidence: original MIPS .pdata c047597c..c04759a7. Semantic name remains unreviewed. */

undefined4 FUN_c047597c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0475928(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c04759a8 FUN_c04759a8 */

/* Boundary evidence: original MIPS .pdata c04759a8..c04759ef. Semantic name remains unreviewed. */

void FUN_c04759a8(uint param_1)

{
  if ((param_1 == DAT_c0477134) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c04759f0 FUN_c04759f0 */

/* Boundary evidence: original MIPS .pdata c04759f0..c0475b0f. Semantic name remains unreviewed. */

void FUN_c04759f0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c0477164 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c047762c;
    if (DAT_c047762c != (undefined4 *)0x0) {
      while (DAT_c0477628 = DAT_c0477628 + -1, _Memory <= DAT_c0477628) {
        if ((code *)*DAT_c0477628 != (code *)0x0) {
          (*(code *)*DAT_c0477628)();
          _Memory = DAT_c047762c;
        }
      }
      free(_Memory);
      DAT_c0477628 = (undefined4 *)0x0;
      DAT_c047762c = (undefined4 *)0x0;
    }
    FUN_c0475b34((undefined4 *)&DAT_c0471010,(undefined4 *)&DAT_c0471014);
  }
  FUN_c0475b34((undefined4 *)&DAT_c0471018,(undefined4 *)&DAT_c047101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c0477630,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0475b10 FUN_c0475b10 */

/* Boundary evidence: original MIPS .pdata c0475b10..c0475b33. Semantic name remains unreviewed. */

void FUN_c0475b10(void)

{
  FUN_c04759f0(0,0,1);
  return;
}



/* c0475b34 FUN_c0475b34 */

/* Boundary evidence: original MIPS .pdata c0475b34..c0475b87. Semantic name remains unreviewed. */

void FUN_c0475b34(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0475b88 FUN_c0475b88 */

/* Boundary evidence: original MIPS .pdata c0475b88..c0475bc3. Semantic name remains unreviewed. */

void FUN_c0475b88(void)

{
  FUN_c0475b34((undefined4 *)&DAT_c0471008,(undefined4 *)&DAT_c047100c);
  FUN_c0475b34((undefined4 *)&DAT_c0471000,(undefined4 *)&DAT_c0471004);
  return;
}


