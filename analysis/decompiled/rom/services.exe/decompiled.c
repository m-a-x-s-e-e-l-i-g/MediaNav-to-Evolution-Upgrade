/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011280 FUN_00011280 */

/* Boundary evidence: original MIPS .pdata 00011280..000112ab. Semantic name remains unreviewed. */

void FUN_00011280(void)

{
  if (DAT_000140b8 != (void *)0x0) {
    free(DAT_000140b8);
  }
  return;
}



/* 000112ac FUN_000112ac */

/* Boundary evidence: original MIPS .pdata 000112ac..0001133b. Semantic name remains unreviewed. */

int FUN_000112ac(wint_t *param_1)

{
  bool bVar1;
  int iVar2;
  wint_t *pwVar3;
  
  bVar1 = false;
  pwVar3 = param_1;
  while ((*pwVar3 != 0 && ((iVar2 = iswctype(*pwVar3,8), iVar2 == 0 || (bVar1))))) {
    if (*pwVar3 == 0x22) {
      bVar1 = !bVar1;
    }
    pwVar3 = pwVar3 + 1;
  }
  return (int)pwVar3 - (int)param_1 >> 1;
}



/* 0001133c FUN_0001133c */

/* Boundary evidence: original MIPS .pdata 0001133c..000113ff. Semantic name remains unreviewed. */

void FUN_0001133c(int *param_1,int *param_2,wint_t *param_3)

{
  wint_t wVar1;
  int iVar2;
  wint_t *pwVar3;
  
  while( true ) {
    wVar1 = *param_3;
    pwVar3 = param_3;
    while ((wVar1 != 0 && (iVar2 = iswctype(*pwVar3,8), iVar2 != 0))) {
      pwVar3 = pwVar3 + 1;
      wVar1 = *pwVar3;
    }
    pwVar3 = param_3 + ((int)pwVar3 - (int)param_3 >> 1);
    if (*pwVar3 == 0) break;
    iVar2 = FUN_000112ac(pwVar3);
    *param_2 = *param_2 + iVar2 + 1;
    param_3 = pwVar3 + iVar2;
    *param_1 = *param_1 + 1;
    if (*param_3 == 0) {
      return;
    }
  }
  return;
}



/* 00011400 FUN_00011400 */

/* Boundary evidence: original MIPS .pdata 00011400..000115d7. Semantic name remains unreviewed. */

undefined4 FUN_00011400(wchar_t *param_1,wint_t *param_2,int *param_3,undefined4 *param_4)

{
  wint_t wVar1;
  short sVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  undefined4 *puVar9;
  wint_t *pwVar10;
  undefined4 *_Dst;
  short *_Dst_00;
  int local_38;
  undefined4 *local_34;
  int *local_30;
  
  local_30 = param_3;
  sVar4 = wcslen(param_1);
  puVar9 = (undefined4 *)(sVar4 + 1);
  local_38 = 1;
  if (puVar9 != (undefined4 *)0xffffffff) {
    local_34 = puVar9;
    FUN_0001133c(&local_38,(int *)&local_34,param_2);
    iVar3 = local_38;
    puVar5 = malloc(((local_38 + 1) * 2 + (int)local_34) * 2);
    if (puVar5 != (undefined4 *)0x0) {
      _Dst = puVar5 + iVar3 + 1;
      memcpy(_Dst,param_1,(int)puVar9 * 2);
      *puVar5 = _Dst;
      _Dst_00 = (short *)((int)puVar9 * 2 + (int)_Dst);
      local_34 = puVar5;
      do {
        local_34 = local_34 + 1;
        wVar1 = *param_2;
        pwVar10 = param_2;
        while ((wVar1 != 0 && (iVar6 = iswctype(*pwVar10,8), iVar6 != 0))) {
          pwVar10 = pwVar10 + 1;
          wVar1 = *pwVar10;
        }
        pwVar10 = param_2 + ((int)pwVar10 - (int)param_2 >> 1);
        if (*pwVar10 == 0) break;
        iVar6 = FUN_000112ac(pwVar10);
        memcpy(_Dst_00,pwVar10,iVar6 * 2);
        _Dst_00[iVar6] = 0;
        sVar2 = *_Dst_00;
        psVar7 = _Dst_00;
        psVar8 = _Dst_00;
        while (sVar2 != 0) {
          sVar2 = *psVar7;
          psVar7 = psVar7 + 1;
          if (sVar2 != 0x22) {
            *psVar8 = sVar2;
            psVar8 = psVar8 + 1;
          }
          sVar2 = *psVar7;
        }
        *psVar8 = 0;
        *local_34 = _Dst_00;
        param_2 = pwVar10 + iVar6;
        _Dst_00 = _Dst_00 + iVar6 + 1;
      } while (*param_2 != 0);
      *local_30 = iVar3;
      *param_4 = puVar5;
      puVar5[iVar3] = 0;
      return 1;
    }
  }
  return 0;
}



/* 000115d8 FUN_000115d8 */

/* Boundary evidence: original MIPS .pdata 000115d8..000116cf. Semantic name remains unreviewed. */

void FUN_000115d8(HMODULE param_1,wint_t *param_2)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  int *piVar4;
  int *piVar5;
  int local_224;
  int local_220 [2];
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_000140b0;
  DAT_000140c0 = param_1;
  DVar1 = GetModuleFileNameW(param_1,aWStack_218,0x100);
  if (DVar1 == 0) {
    FUN_0001188c(0xfffffffd);
  }
  FUN_00011bac(FUN_00011280);
  FUN_0001192c();
  piVar5 = local_220;
  piVar4 = &local_224;
  iVar2 = FUN_00011400(aWStack_218,param_2,piVar4,piVar5);
  if (iVar2 == 0) {
    FUN_0001188c(0xfffffffc);
  }
  DAT_000140bc = local_224;
  DAT_000140b8 = local_220[0];
  UVar3 = FUN_00012d40(local_224,local_220[0],piVar4,piVar5);
  FUN_0001186c(UVar3);
  FUN_0001188c(UVar3);
  FUN_00011ccc(local_18);
  return;
}



/* 000116d0 FUN_000116d0 */

/* Boundary evidence: original MIPS .pdata 000116d0..0001170f. Semantic name remains unreviewed. */

void FUN_000116d0(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x228) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x228),param_1);
  return;
}



/* 00011710 entry */

/* Boundary evidence: original MIPS .pdata 00011710..0001174b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,undefined4 param_2,wint_t *param_3)

{
  FUN_00011bdc();
  FUN_000115d8(param_1,param_3);
  return;
}



/* 0001174c FUN_0001174c */

/* Boundary evidence: original MIPS .pdata 0001174c..0001186b. Semantic name remains unreviewed. */

void FUN_0001174c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_000140c4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000140f0;
    if (DAT_000140f0 != (undefined4 *)0x0) {
      while (DAT_000140ec = DAT_000140ec + -1, _Memory <= DAT_000140ec) {
        if ((code *)*DAT_000140ec != (code *)0x0) {
          (*(code *)*DAT_000140ec)();
          _Memory = DAT_000140f0;
        }
      }
      free(_Memory);
      DAT_000140ec = (undefined4 *)0x0;
      DAT_000140f0 = (undefined4 *)0x0;
    }
    FUN_000118d8((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_000118d8((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_000140f4,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 0001186c FUN_0001186c */

/* Boundary evidence: original MIPS .pdata 0001186c..0001188b. Semantic name remains unreviewed. */

void FUN_0001186c(UINT param_1)

{
  FUN_0001174c(param_1,0,0);
  return;
}



/* 0001188c FUN_0001188c */

/* Boundary evidence: original MIPS .pdata 0001188c..000118d7. Semantic name remains unreviewed. */

void FUN_0001188c(UINT param_1)

{
  DAT_000140c4 = 0;
  FUN_000118d8((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000118d8 FUN_000118d8 */

/* Boundary evidence: original MIPS .pdata 000118d8..0001192b. Semantic name remains unreviewed. */

void FUN_000118d8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 0001192c FUN_0001192c */

/* Boundary evidence: original MIPS .pdata 0001192c..00011967. Semantic name remains unreviewed. */

void FUN_0001192c(void)

{
  FUN_000118d8((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_000118d8((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00011968 FUN_00011968 */

/* Boundary evidence: original MIPS .pdata 00011968..00011a73. Semantic name remains unreviewed. */

undefined4 FUN_00011968(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_000140f0;
  puVar3 = DAT_000140ec;
  iVar4 = (int)DAT_000140ec - (int)DAT_000140f0;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_000119ac:
    param_1 = 0;
  }
  else {
    if (DAT_000140f0 != (void *)0x0) {
      uVar1 = _msize(DAT_000140f0);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_00011a20:
        if (pvVar2 == (void *)0x0) goto LAB_000119ac;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_00011a20;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_000140ec = puVar3 + 1;
    *puVar3 = param_1;
    DAT_000140f0 = pvVar2;
  }
  return param_1;
}



/* 00011a74 FUN_00011a74 */

/* Boundary evidence: original MIPS .pdata 00011a74..00011b5f. Semantic name remains unreviewed. */

undefined4 FUN_00011a74(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_000140f4 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_000140f4,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_000140f4 == (LPCRITICAL_SECTION)0x0) goto LAB_00011b18;
  }
  EnterCriticalSection(DAT_000140f4);
LAB_00011b18:
  uVar2 = FUN_00011968(param_1);
  FUN_00011b60();
  return uVar2;
}



/* 00011b60 FUN_00011b60 */

/* Boundary evidence: original MIPS .pdata 00011b60..00011bab. Semantic name remains unreviewed. */

void FUN_00011b60(void)

{
  if (DAT_000140f4 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_000140f4);
  }
  return;
}



/* 00011bac FUN_00011bac */

/* Boundary evidence: original MIPS .pdata 00011bac..00011bdb. Semantic name remains unreviewed. */

undefined4 FUN_00011bac(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00011a74(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00011bdc FUN_00011bdc */

/* Boundary evidence: original MIPS .pdata 00011bdc..00011c4f. Semantic name remains unreviewed. */

void FUN_00011bdc(void)

{
  uint uVar1;
  
  if ((DAT_000140b0 == 0) || (DAT_000140b0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000140b0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000140b0 == 0) {
      DAT_000140b0 = 0xb064;
    }
  }
  DAT_000140b4 = ~DAT_000140b0;
  return;
}



/* 00011c50 FUN_00011c50 */

/* Boundary evidence: original MIPS .pdata 00011c50..00011ccb. Semantic name remains unreviewed. */

void FUN_00011c50(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_00011d14(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 00011ccc FUN_00011ccc */

/* Boundary evidence: original MIPS .pdata 00011ccc..00011d13. Semantic name remains unreviewed. */

void FUN_00011ccc(uint param_1)

{
  if ((param_1 == DAT_000140b0) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00011d14 FUN_00011d14 */

/* Boundary evidence: original MIPS .pdata 00011d14..00011d67. Semantic name remains unreviewed. */

void FUN_00011d14(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00011ccc(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00011d68 FUN_00011d68 */

/* Boundary evidence: original MIPS .pdata 00011d68..00011d93. Semantic name remains unreviewed. */

undefined4 FUN_00011d68(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00011d14(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00011ec4 FUN_00011ec4 */

/* Boundary evidence: original MIPS .pdata 00011ec4..00011f13. Semantic name remains unreviewed. */

void FUN_00011ec4(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  return;
}



/* 00011f14 FUN_00011f14 */

/* Boundary evidence: original MIPS .pdata 00011f14..00011f67. Semantic name remains unreviewed. */

undefined4 FUN_00011f14(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

{
  undefined4 local_10;
  DWORD local_c;
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_c = 4;
    local_10 = param_3;
    RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_10,&local_c);
    param_3 = local_10;
  }
  return param_3;
}



/* 00011f68 FUN_00011f68 */

/* Boundary evidence: original MIPS .pdata 00011f68..0001212b. Semantic name remains unreviewed. */

undefined4 FUN_00011f68(void)

{
  HMODULE hLibModule;
  undefined4 uVar1;
  
  hLibModule = LoadLibraryW(L"\\windows\\coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    uVar1 = 0;
  }
  else {
    DAT_000140d8 = GetProcAddressW(hLibModule,L"_wfopen");
    DAT_000140dc = GetProcAddressW(hLibModule,L"fclose");
    DAT_000140cc = GetProcAddressW(hLibModule,L"ftell");
    DAT_000140e4 = GetProcAddressW(hLibModule,L"fseek");
    DAT_000140d0 = GetProcAddressW(hLibModule,L"fgetws");
    DAT_000140e8 = GetProcAddressW(hLibModule,L"wprintf");
    DAT_000140d4 = GetProcAddressW(hLibModule,L"_getstdfilex");
    uVar1 = 1;
    if ((((DAT_000140d8 == 0) || (DAT_000140dc == 0)) || (DAT_000140cc == 0)) ||
       (((DAT_000140e4 == 0 || (DAT_000140d0 == 0)) || ((DAT_000140e8 == 0 || (DAT_000140d4 == 0))))
       )) {
      DAT_000140d4 = 0;
      DAT_000140d8 = 0;
      DAT_000140dc = 0;
      DAT_000140cc = 0;
      DAT_000140e4 = 0;
      DAT_000140d0 = 0;
      DAT_000140e8 = 0;
      DAT_000140e0 = 1;
      FreeLibrary(hLibModule);
    }
  }
  return uVar1;
}



/* 0001212c FUN_0001212c */

/* Boundary evidence: original MIPS .pdata 0001212c..000121c7. Semantic name remains unreviewed. */

void FUN_0001212c(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HRESULT HVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  wchar_t awStack_410 [512];
  uint local_10;
  
  local_10 = DAT_000140b0;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if ((DAT_000140e0 == 0) &&
     (HVar1 = StringCchVPrintfW(awStack_410,0x200,param_1,(va_list)&local_res4), -1 < HVar1)) {
    if (DAT_000140c8 == 0) {
      (*DAT_000140e8)(&UNK_00011114,awStack_410);
    }
    else {
      OutputDebugStringW(awStack_410);
    }
  }
  FUN_00011ccc(local_10);
  return;
}



/* 000121c8 FUN_000121c8 */

/* Boundary evidence: original MIPS .pdata 000121c8..00012277. Semantic name remains unreviewed. */

void FUN_000121c8(UINT param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HMODULE hInstance;
  int iVar1;
  HRESULT HVar2;
  LPWSTR lpBuffer;
  STRSAFE_LPCWSTR pszFormat;
  undefined4 uVar3;
  va_list argList;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  WCHAR aWStack_810 [512];
  wchar_t awStack_410 [512];
  uint local_10;
  
  local_10 = DAT_000140b0;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if (DAT_000140e0 == 0) {
    hInstance = GetModuleHandleW((LPCWSTR)0x0);
    uVar3 = 0x200;
    lpBuffer = aWStack_810;
    iVar1 = LoadStringW(hInstance,param_1,lpBuffer,0x200);
    if (iVar1 == 0) {
      FUN_0001212c(L"Can\'t find the resource %d!",param_1,lpBuffer,uVar3);
    }
    argList = (va_list)&local_res4;
    pszFormat = aWStack_810;
    HVar2 = StringCchVPrintfW(awStack_410,0x200,pszFormat,argList);
    if (-1 < HVar2) {
      FUN_0001212c(L"%s\n",awStack_410,pszFormat,argList);
    }
  }
  FUN_00011ccc(local_10);
  return;
}



/* 00012278 FUN_00012278 */

/* Boundary evidence: original MIPS .pdata 00012278..000122ef. Semantic name remains unreviewed. */

undefined4 FUN_00012278(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_000140e0 == 0) {
    FUN_000121c8(1,param_2,param_3,param_4);
    FUN_000121c8(2,param_2,param_3,param_4);
    FUN_000121c8(3,param_2,param_3,param_4);
    FUN_000121c8(4,param_2,param_3,param_4);
    FUN_000121c8(5,param_2,param_3,param_4);
    FUN_000121c8(6,param_2,param_3,param_4);
    FUN_000121c8(7,param_2,param_3,param_4);
    FUN_000121c8(8,param_2,param_3,param_4);
    FUN_000121c8(0x14,param_2,param_3,param_4);
    FUN_000121c8(0x15,param_2,param_3,param_4);
  }
  return 0;
}



/* 000122f0 FUN_000122f0 */

undefined4 FUN_000122f0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_0001103c;
  iVar1 = 0;
  do {
    if (param_1 == *piVar2) {
      return *(undefined4 *)(&UNK_00011040 + iVar1 * 8);
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 2;
  } while (iVar1 < 7);
  return 0x13;
}



/* 0001233c FUN_0001233c */

/* Boundary evidence: original MIPS .pdata 0001233c..0001249b. Semantic name remains unreviewed. */

undefined4 FUN_0001233c(void)

{
  int iVar1;
  DWORD DVar2;
  HLOCAL pvVar3;
  UINT UVar4;
  SIZE_T SVar5;
  undefined4 *puVar6;
  SIZE_T *pSVar7;
  undefined4 uVar8;
  undefined4 in_a3;
  undefined4 uVar9;
  HLOCAL hMem;
  uint uVar10;
  undefined4 *puVar11;
  SIZE_T local_20;
  uint local_1c;
  
  pSVar7 = &local_20;
  local_1c = 0;
  local_20 = 0;
  iVar1 = EnumServices(0,&local_1c);
  hMem = (HLOCAL)0x0;
  do {
    if (iVar1 != 0) {
      uVar10 = 0;
      if (local_1c != 0) {
        puVar11 = (undefined4 *)((int)hMem + 0x10);
        do {
          uVar9 = puVar11[-1];
          uVar8 = *puVar11;
          puVar6 = puVar11 + -4;
          FUN_0001212c(L"%s\t0x%08x\t%s\t",puVar6,uVar8,uVar9);
          UVar4 = FUN_000122f0(puVar11[1]);
          FUN_000121c8(UVar4,puVar6,uVar8,uVar9);
          uVar10 = uVar10 + 1;
          puVar11 = puVar11 + 6;
        } while (uVar10 < local_1c);
      }
LAB_0001244c:
      if (hMem != (HLOCAL)0x0) {
        LocalFree(hMem);
      }
      return 0;
    }
    DVar2 = GetLastError();
    if ((DVar2 != 0x7a) && (DVar2 != 0xea)) {
      DVar2 = GetLastError();
      FUN_000121c8(0xb,DVar2,pSVar7,in_a3);
      goto LAB_0001244c;
    }
    SVar5 = local_20;
    if (hMem == (HLOCAL)0x0) {
      pvVar3 = LocalAlloc(2,local_20);
      hMem = pvVar3;
    }
    else {
      pSVar7 = (SIZE_T *)0x2;
      pvVar3 = LocalReAlloc(hMem,local_20,2);
    }
    if (pvVar3 == (HLOCAL)0x0) {
      FUN_000121c8(10,SVar5,pSVar7,in_a3);
      goto LAB_0001244c;
    }
    pSVar7 = &local_20;
    iVar1 = EnumServices(pvVar3,&local_1c);
    hMem = pvVar3;
  } while( true );
}



/* 0001249c FUN_0001249c */

/* Boundary evidence: original MIPS .pdata 0001249c..000125b7. Semantic name remains unreviewed. */

undefined4 FUN_0001249c(LPCWSTR param_1)

{
  HANDLE hObject;
  int iVar1;
  DWORD DVar2;
  UINT UVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_648;
  undefined4 local_644;
  uint local_18;
  
  local_18 = DAT_000140b0;
  uVar5 = 0;
  uVar4 = 0;
  hObject = CreateFileW(param_1,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (hObject == (HANDLE)0xffffffff) {
    UVar3 = 0xc;
  }
  else {
    local_648 = 0x630;
    iVar1 = GetDeviceInformationByFileHandle(hObject,&local_648);
    if (iVar1 == 0) {
      DVar2 = GetLastError();
      FUN_000121c8(0xb,DVar2,uVar4,uVar5);
      CloseHandle(hObject);
      goto LAB_00012598;
    }
    CloseHandle(hObject);
    iVar1 = DeregisterService(local_644);
    if (iVar1 != 0) goto LAB_00012598;
    param_1 = (LPCWSTR)GetLastError();
    UVar3 = 0xb;
  }
  FUN_000121c8(UVar3,param_1,uVar4,uVar5);
LAB_00012598:
  FUN_00011ccc(local_18);
  return 0;
}



/* 000125b8 FUN_000125b8 */

/* Boundary evidence: original MIPS .pdata 000125b8..000126c7. Semantic name remains unreviewed. */

undefined4
FUN_000125b8(DWORD param_1,LPCWSTR param_2,LPVOID param_3,DWORD param_4,LPVOID param_5,DWORD param_6
            ,LPDWORD param_7)

{
  HANDLE hDevice;
  BOOL BVar1;
  DWORD DVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  hDevice = CreateFileW(param_2,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (hDevice == (HANDLE)0xffffffff) {
    FUN_000121c8(0xc,param_2,uVar3,uVar4);
  }
  else {
    BVar1 = DeviceIoControl(hDevice,param_1,param_3,param_4,param_5,param_6,param_7,
                            (LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      FUN_000121c8(0xb,DVar2,param_3,param_4);
    }
    CloseHandle(hDevice);
  }
  return 0;
}



/* 000126c8 FUN_000126c8 */

/* Boundary evidence: original MIPS .pdata 000126c8..0001286f. Semantic name remains unreviewed. */

undefined4 FUN_000126c8(wchar_t *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint local_230;
  HKEY local_22c;
  DWORD local_228;
  DWORD local_224;
  wchar_t awStack_220 [8];
  undefined2 local_210;
  wchar_t awStack_20e [253];
  uint local_14;
  
  local_14 = DAT_000140b0;
  local_228 = 4;
  sVar1 = wcslen(param_1);
  if (sVar1 + 8 < 0x106) {
    wcscpy(awStack_220,L"Services");
    local_210 = 0x5c;
    wcscpy(awStack_20e,param_1);
    param_4 = 0xf003f;
    param_3 = 0;
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,awStack_220,0,0xf003f,&local_22c);
    if (LVar2 == 0) {
      LVar2 = RegQueryValueExW(local_22c,L"Flags",(LPDWORD)0x0,&local_224,(LPBYTE)&local_230,
                               &local_228);
      if (((LVar2 != 0) || (local_224 != 4)) || (local_228 != 4)) {
        local_230 = 0;
      }
      if (param_2 == 0) {
        local_230 = local_230 | 4;
      }
      else {
        local_230 = local_230 & 0xfffffffb;
      }
      uVar4 = 4;
      uVar3 = 0;
      LVar2 = RegSetValueExW(local_22c,L"Flags",0,4,(BYTE *)&local_230,4);
      if (LVar2 != 0) {
        FUN_000121c8(0xb,LVar2,uVar3,uVar4);
      }
      RegCloseKey(local_22c);
      goto LAB_0001284c;
    }
    uVar3 = 0x37;
  }
  else {
    uVar3 = 0x6f;
  }
  FUN_000121c8(0xb,uVar3,param_3,param_4);
LAB_0001284c:
  FUN_00011ccc(local_14);
  return 0;
}



/* 00012870 FUN_00012870 */

undefined4 FUN_00012870(int *param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  *param_1 = 0;
  iVar4 = 10;
  if ((*param_2 == 0x30) && (param_2[1] == 0x78)) {
    iVar4 = 0x10;
    param_2 = param_2 + 2;
  }
  uVar1 = *param_2;
  do {
    uVar2 = (uint)uVar1;
    if (uVar2 == 0) {
      return 1;
    }
    if ((uVar2 < 0x30) || (0x39 < uVar2)) {
      if (iVar4 != 0x10) {
        return 0;
      }
      if ((uVar2 < 0x41) || (0x46 < uVar2)) {
        if (uVar2 < 0x61) {
          return 0;
        }
        if (0x66 < uVar2) {
          return 0;
        }
        iVar3 = uVar2 - 0x57;
      }
      else {
        iVar3 = uVar2 - 0x37;
      }
    }
    else {
      iVar3 = uVar2 - 0x30;
    }
    param_2 = param_2 + 1;
    *param_1 = *param_1 * iVar4 + iVar3;
    uVar1 = *param_2;
  } while( true );
}



/* 00012950 FUN_00012950 */

/* Boundary evidence: original MIPS .pdata 00012950..00012c37. Semantic name remains unreviewed. */

undefined4 FUN_00012950(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  DWORD DVar6;
  DWORD DVar7;
  int iVar8;
  wchar_t *pwVar9;
  DWORD DStack_850;
  int iStack_84c;
  undefined2 local_848 [1040];
  uint local_28;
  
  local_28 = DAT_000140b0;
  pwVar4 = (wchar_t *)*param_2;
  pwVar5 = L"help";
  DVar7 = 0;
  pwVar9 = (wchar_t *)0x0;
  iVar8 = 1;
  local_848[0] = 0;
  iVar1 = _wcsicmp(pwVar4,L"help");
  if (iVar1 == 0) {
    uVar2 = FUN_00012278(pwVar4,pwVar5,param_3,param_4);
  }
  else {
    iVar1 = _wcsicmp((wchar_t *)*param_2,L"list");
    if ((iVar1 == 0) && (param_1 == 1)) {
      uVar2 = FUN_0001233c();
    }
    else {
      iVar1 = _wcsicmp((wchar_t *)*param_2,L"load");
      if ((iVar1 == 0) && (param_1 == 2)) {
        iVar1 = ActivateService(param_2[1],0);
        if (iVar1 == 0) {
          DVar7 = GetLastError();
          FUN_000121c8(0xb,DVar7,param_3,param_4);
        }
        FUN_00011ccc(local_28);
        return 0;
      }
      iVar1 = _wcsicmp((wchar_t *)*param_2,L"unload");
      if ((iVar1 == 0) && (param_1 == 2)) {
        uVar2 = FUN_0001249c((LPCWSTR)param_2[1]);
      }
      else {
        iVar1 = _wcsicmp((wchar_t *)*param_2,L"register");
        if ((iVar1 == 0) && (param_1 == 2)) {
          iVar1 = 1;
        }
        else {
          iVar1 = _wcsicmp((wchar_t *)*param_2,L"unregister");
          if ((iVar1 != 0) || (param_1 != 2)) {
            iVar1 = _wcsicmp((wchar_t *)*param_2,L"start");
            pwVar4 = pwVar9;
            if ((iVar1 == 0) && (param_1 == 2)) {
              DVar6 = 0x1040004;
            }
            else {
              iVar1 = _wcsicmp((wchar_t *)*param_2,L"stop");
              if ((iVar1 == 0) && (param_1 == 2)) {
                DVar6 = 0x1040008;
              }
              else {
                iVar1 = _wcsicmp((wchar_t *)*param_2,L"refresh");
                if ((iVar1 == 0) && (param_1 == 2)) {
                  DVar6 = 0x104000c;
                }
                else {
                  pwVar4 = L"debug";
                  iVar1 = _wcsicmp((wchar_t *)*param_2,L"debug");
                  uVar2 = 3;
                  if ((iVar1 != 0) || (param_1 != 3)) {
                    FUN_000121c8(9,pwVar4,param_3,param_4);
                    goto LAB_00012c04;
                  }
                  pwVar4 = (wchar_t *)param_2[1];
                  DVar6 = 0x1040024;
                  iVar8 = 2;
                  iVar1 = FUN_00012870(&iStack_84c,(ushort *)pwVar4);
                  if (iVar1 == 0) {
                    sVar3 = wcslen(pwVar4);
                    DVar7 = (sVar3 + 1) * 2;
                  }
                  else {
                    DVar7 = 4;
                    pwVar4 = pwVar9;
                  }
                }
              }
            }
            uVar2 = FUN_000125b8(DVar6,(LPCWSTR)param_2[iVar8],pwVar4,DVar7,local_848,0x820,
                                 &DStack_850);
            goto LAB_00012c04;
          }
          iVar1 = 0;
        }
        uVar2 = FUN_000126c8((wchar_t *)param_2[1],iVar1,param_3,param_4);
      }
    }
  }
LAB_00012c04:
  FUN_00011ccc(local_28);
  return uVar2;
}



/* 00012c38 FUN_00012c38 */

/* Boundary evidence: original MIPS .pdata 00012c38..00012ccf. Semantic name remains unreviewed. */

bool FUN_00012c38(PHKEY param_1,HKEY param_2,LPCWSTR param_3,REGSAM param_4)

{
  LSTATUS LVar1;
  
  if (*param_1 != (HKEY)0x0) {
    RegCloseKey(*param_1);
    *param_1 = (HKEY)0x0;
  }
  param_1[1] = (HKEY)0x0;
  LVar1 = RegOpenKeyExW(param_2,param_3,0,param_4,param_1);
  return LVar1 == 0;
}



/* 00012cd0 FUN_00012cd0 */

/* Boundary evidence: original MIPS .pdata 00012cd0..00012d3f. Semantic name remains unreviewed. */

undefined4 FUN_00012cd0(void)

{
  undefined4 uVar1;
  HKEY local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = (HKEY)0x0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  FUN_00012c38(&local_18,(HKEY)0x80000002,L"Services",0x20019);
  uVar1 = FUN_00011f14(&local_18,L"AllowCmdLine",1);
  FUN_00011ec4(&local_18);
  return uVar1;
}



/* 00012d40 FUN_00012d40 */

/* Boundary evidence: original MIPS .pdata 00012d40..00012e43. Semantic name remains unreviewed. */

undefined4 FUN_00012d40(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = param_2;
  iVar1 = FUN_00011f68();
  if (iVar1 != 0) {
    iVar1 = FUN_00012cd0();
    if (iVar1 == 0) {
      FUN_000121c8(0xb,5,param_3,param_4);
    }
    else if (param_1 < 2) {
      FUN_000121c8(9,iVar2,param_3,param_4);
    }
    else {
      iVar2 = _wcsicmp(*(wchar_t **)(param_2 + 4),L"-s");
      if (iVar2 == 0) {
        if (param_1 < 3) {
          return 0;
        }
        iVar3 = 1;
        DAT_000140e0 = 1;
      }
      else {
        iVar2 = _wcsicmp(*(wchar_t **)(param_2 + 4),L"-d");
        if (iVar2 == 0) {
          if (param_1 < 3) {
            return 0;
          }
          iVar3 = 1;
          DAT_000140c8 = 1;
        }
      }
      FUN_00012950((param_1 - iVar3) + -1,(undefined4 *)((iVar3 + 1) * 4 + param_2),param_3,param_4)
      ;
    }
  }
  return 0;
}


