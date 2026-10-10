/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011b3c FUN_00011b3c */

/* Boundary evidence: original MIPS .pdata 00011b3c..00011b67. Semantic name remains unreviewed. */

void FUN_00011b3c(void)

{
  if (DAT_0001b1a4 != (void *)0x0) {
    free(DAT_0001b1a4);
  }
  return;
}



/* 00011b68 FUN_00011b68 */

/* Boundary evidence: original MIPS .pdata 00011b68..00011bf7. Semantic name remains unreviewed. */

int FUN_00011b68(wint_t *param_1)

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



/* 00011bf8 FUN_00011bf8 */

/* Boundary evidence: original MIPS .pdata 00011bf8..00011cbb. Semantic name remains unreviewed. */

void FUN_00011bf8(int *param_1,int *param_2,wint_t *param_3)

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
    iVar2 = FUN_00011b68(pwVar3);
    *param_2 = *param_2 + iVar2 + 1;
    param_3 = pwVar3 + iVar2;
    *param_1 = *param_1 + 1;
    if (*param_3 == 0) {
      return;
    }
  }
  return;
}



/* 00011cbc FUN_00011cbc */

/* Boundary evidence: original MIPS .pdata 00011cbc..00011e93. Semantic name remains unreviewed. */

undefined4 FUN_00011cbc(wchar_t *param_1,wint_t *param_2,int *param_3,undefined4 *param_4)

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
    FUN_00011bf8(&local_38,(int *)&local_34,param_2);
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
        iVar6 = FUN_00011b68(pwVar10);
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



/* 00011e94 FUN_00011e94 */

/* Boundary evidence: original MIPS .pdata 00011e94..00011f8b. Semantic name remains unreviewed. */

void FUN_00011e94(HMODULE param_1,wint_t *param_2)

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
  
  local_18 = DAT_000150c4;
  DAT_0001b1ac = param_1;
  DVar1 = GetModuleFileNameW(param_1,aWStack_218,0x100);
  if (DVar1 == 0) {
    FUN_00012148(0xfffffffd);
  }
  FUN_00012468(FUN_00011b3c);
  FUN_000121e8();
  piVar5 = local_220;
  piVar4 = &local_224;
  iVar2 = FUN_00011cbc(aWStack_218,param_2,piVar4,piVar5);
  if (iVar2 == 0) {
    FUN_00012148(0xfffffffc);
  }
  DAT_0001b1a8 = local_224;
  DAT_0001b1a4 = local_220[0];
  UVar3 = FUN_00013ecc(local_224,local_220[0],piVar4,piVar5);
  FUN_00012128(UVar3);
  FUN_00012148(UVar3);
  FUN_00012588(local_18);
  return;
}



/* 00011f8c FUN_00011f8c */

/* Boundary evidence: original MIPS .pdata 00011f8c..00011fcb. Semantic name remains unreviewed. */

void FUN_00011f8c(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x228) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x228),param_1);
  return;
}



/* 00011fcc entry */

/* Boundary evidence: original MIPS .pdata 00011fcc..00012007. Semantic name remains unreviewed. */

void entry(HMODULE param_1,undefined4 param_2,wint_t *param_3)

{
  FUN_00012498();
  FUN_00011e94(param_1,param_3);
  return;
}



/* 00012008 FUN_00012008 */

/* Boundary evidence: original MIPS .pdata 00012008..00012127. Semantic name remains unreviewed. */

void FUN_00012008(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0001b1b0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_0001be04;
    if (DAT_0001be04 != (undefined4 *)0x0) {
      while (DAT_0001be00 = DAT_0001be00 + -1, _Memory <= DAT_0001be00) {
        if ((code *)*DAT_0001be00 != (code *)0x0) {
          (*(code *)*DAT_0001be00)();
          _Memory = DAT_0001be04;
        }
      }
      free(_Memory);
      DAT_0001be00 = (undefined4 *)0x0;
      DAT_0001be04 = (undefined4 *)0x0;
    }
    FUN_00012194((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_00012194((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_0001be08,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00012128 FUN_00012128 */

/* Boundary evidence: original MIPS .pdata 00012128..00012147. Semantic name remains unreviewed. */

void FUN_00012128(UINT param_1)

{
  FUN_00012008(param_1,0,0);
  return;
}



/* 00012148 FUN_00012148 */

/* Boundary evidence: original MIPS .pdata 00012148..00012193. Semantic name remains unreviewed. */

void FUN_00012148(UINT param_1)

{
  DAT_0001b1b0 = 0;
  FUN_00012194((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00012194 FUN_00012194 */

/* Boundary evidence: original MIPS .pdata 00012194..000121e7. Semantic name remains unreviewed. */

void FUN_00012194(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 000121e8 FUN_000121e8 */

/* Boundary evidence: original MIPS .pdata 000121e8..00012223. Semantic name remains unreviewed. */

void FUN_000121e8(void)

{
  FUN_00012194((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_00012194((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00012224 FUN_00012224 */

/* Boundary evidence: original MIPS .pdata 00012224..0001232f. Semantic name remains unreviewed. */

undefined4 FUN_00012224(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_0001be04;
  puVar3 = DAT_0001be00;
  iVar4 = (int)DAT_0001be00 - (int)DAT_0001be04;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_00012268:
    param_1 = 0;
  }
  else {
    if (DAT_0001be04 != (void *)0x0) {
      uVar1 = _msize(DAT_0001be04);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_000122dc:
        if (pvVar2 == (void *)0x0) goto LAB_00012268;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_000122dc;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_0001be00 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_0001be04 = pvVar2;
  }
  return param_1;
}



/* 00012330 FUN_00012330 */

/* Boundary evidence: original MIPS .pdata 00012330..0001241b. Semantic name remains unreviewed. */

undefined4 FUN_00012330(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_0001be08 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_0001be08,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_0001be08 == (LPCRITICAL_SECTION)0x0) goto LAB_000123d4;
  }
  EnterCriticalSection(DAT_0001be08);
LAB_000123d4:
  uVar2 = FUN_00012224(param_1);
  FUN_0001241c();
  return uVar2;
}



/* 0001241c FUN_0001241c */

/* Boundary evidence: original MIPS .pdata 0001241c..00012467. Semantic name remains unreviewed. */

void FUN_0001241c(void)

{
  if (DAT_0001be08 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_0001be08);
  }
  return;
}



/* 00012468 FUN_00012468 */

/* Boundary evidence: original MIPS .pdata 00012468..00012497. Semantic name remains unreviewed. */

undefined4 FUN_00012468(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00012330(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00012498 FUN_00012498 */

/* Boundary evidence: original MIPS .pdata 00012498..0001250b. Semantic name remains unreviewed. */

void FUN_00012498(void)

{
  uint uVar1;
  
  if ((DAT_000150c4 == 0) || (DAT_000150c4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000150c4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000150c4 == 0) {
      DAT_000150c4 = 0xb064;
    }
  }
  DAT_000150c8 = ~DAT_000150c4;
  return;
}



/* 0001250c FUN_0001250c */

/* Boundary evidence: original MIPS .pdata 0001250c..00012587. Semantic name remains unreviewed. */

void FUN_0001250c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_000125d0(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 00012588 FUN_00012588 */

/* Boundary evidence: original MIPS .pdata 00012588..000125cf. Semantic name remains unreviewed. */

void FUN_00012588(uint param_1)

{
  if ((param_1 == DAT_000150c4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 000125d0 FUN_000125d0 */

/* Boundary evidence: original MIPS .pdata 000125d0..00012623. Semantic name remains unreviewed. */

void FUN_000125d0(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00012588(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00012624 FUN_00012624 */

/* Boundary evidence: original MIPS .pdata 00012624..0001264f. Semantic name remains unreviewed. */

undefined4 FUN_00012624(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_000125d0(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00012780 FUN_00012780 */

/* Boundary evidence: original MIPS .pdata 00012780..000127cf. Semantic name remains unreviewed. */

void FUN_00012780(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  return;
}



/* 000127d0 FUN_000127d0 */

/* Boundary evidence: original MIPS .pdata 000127d0..0001282b. Semantic name remains unreviewed. */

undefined4 FUN_000127d0(undefined4 *param_1,LPCWSTR param_2,LPBYTE param_3,int param_4)

{
  LSTATUS LVar1;
  DWORD local_resc;
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_resc = param_4 << 1;
    LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,param_3,&local_resc);
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* 0001282c FUN_0001282c */

/* Boundary evidence: original MIPS .pdata 0001282c..0001287f. Semantic name remains unreviewed. */

undefined4 FUN_0001282c(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

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



/* 00012880 FUN_00012880 */

/* Boundary evidence: original MIPS .pdata 00012880..000128ff. Semantic name remains unreviewed. */

bool FUN_00012880(undefined4 *param_1,LPCWSTR param_2,wchar_t *param_3)

{
  size_t sVar1;
  LSTATUS LVar2;
  
  sVar1 = wcslen(param_3);
  LVar2 = RegSetValueExW((HKEY)*param_1,param_2,0,1,(BYTE *)param_3,(sVar1 + 1) * 2);
  return LVar2 == 0;
}



/* 00012900 FUN_00012900 */

/* Boundary evidence: original MIPS .pdata 00012900..00012953. Semantic name remains unreviewed. */

bool FUN_00012900(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

{
  LSTATUS LVar1;
  undefined4 local_res8 [2];
  
  local_res8[0] = param_3;
  LVar1 = RegSetValueExW((HKEY)*param_1,param_2,0,4,(BYTE *)local_res8,4);
  return LVar1 == 0;
}



/* 00012954 FUN_00012954 */

/* Boundary evidence: original MIPS .pdata 00012954..00012a03. Semantic name remains unreviewed. */

undefined4 FUN_00012954(void)

{
  int iVar1;
  hostent *phVar2;
  undefined4 uVar3;
  char local_210;
  undefined1 auStack_20f [511];
  uint local_10;
  
  local_10 = DAT_000150c4;
  local_210 = '\0';
  memset(auStack_20f,0,0x1ff);
  uVar3 = 0;
  iVar1 = gethostname(&local_210,0x200);
  if ((iVar1 == -1) || (phVar2 = gethostbyname(&local_210), phVar2 == (hostent *)0x0)) {
    FUN_00012588(local_10);
    uVar3 = 0;
  }
  else {
    if (*phVar2->h_addr_list != (char *)0x0) {
      uVar3 = *(undefined4 *)*phVar2->h_addr_list;
    }
    FUN_00012588(local_10);
  }
  return uVar3;
}



/* 00012a04 FUN_00012a04 */

/* Boundary evidence: original MIPS .pdata 00012a04..00012a8b. Semantic name remains unreviewed. */

ulong FUN_00012a04(wchar_t *param_1)

{
  ulong uVar1;
  char local_210;
  undefined1 auStack_20f [510];
  undefined1 local_11;
  uint local_10;
  
  local_10 = DAT_000150c4;
  local_210 = '\0';
  memset(auStack_20f,0,0x1ff);
  wcstombs(&local_210,param_1,0x1ff);
  local_11 = 0;
  uVar1 = inet_addr(&local_210);
  if (uVar1 == 0xffffffff) {
    uVar1 = 0;
  }
  FUN_00012588(local_10);
  return uVar1;
}



/* 00012a8c FUN_00012a8c */

/* Boundary evidence: original MIPS .pdata 00012a8c..00012b17. Semantic name remains unreviewed. */

undefined4 FUN_00012a8c(wchar_t *param_1,ulong *param_2)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = _wcsicmp(param_1,L"me");
  if (iVar1 == 0) {
    *param_2 = 0;
  }
  else {
    iVar1 = _wcsicmp(param_1,L"myip");
    if (iVar1 == 0) {
      uVar2 = FUN_00012954();
      *param_2 = uVar2;
      if (uVar2 != 0) {
        return 1;
      }
    }
    uVar2 = FUN_00012a04(param_1);
    *param_2 = uVar2;
    if (uVar2 == 0) {
      return 0;
    }
  }
  return 1;
}



/* 00012b18 FUN_00012b18 */

/* Boundary evidence: original MIPS .pdata 00012b18..00012cc3. Semantic name remains unreviewed. */

void FUN_00012b18(undefined4 param_1,wchar_t *param_2)

{
  uint uVar1;
  wchar_t *_Dest;
  
  switch(param_1) {
  case 1:
    _Dest = u_default_000150cc;
    goto LAB_00012ca0;
  case 3:
    uVar1 = _wtol(param_2);
    DAT_0001b1bc = uVar1 & 0xffff;
    break;
  case 4:
    _Dest = (wchar_t *)&DAT_0001b1f4;
    goto LAB_00012ca0;
  case 5:
    uVar1 = _wtol(param_2);
    DAT_0001b1c8 = uVar1 & 0xffff;
    break;
  case 6:
    uVar1 = _wtol(param_2);
    DAT_0001b1d0 = uVar1 & 0xffff;
    break;
  case 7:
    uVar1 = _wtol(param_2);
    DAT_0001b1cc = uVar1 & 0xffff;
    break;
  case 8:
    uVar1 = _wtol(param_2);
    DAT_0001b1d4 = uVar1 & 0xffff;
    break;
  case 9:
    uVar1 = _wtol(param_2);
    DAT_0001b1dc = uVar1 & 0xffff;
    break;
  case 10:
    uVar1 = _wtol(param_2);
    DAT_0001b1f0 = uVar1 & 0xffff;
    break;
  case 0xb:
    uVar1 = _wtol(param_2);
    DAT_0001b1d8 = uVar1 & 0xffff;
    break;
  case 0xc:
    _Dest = (wchar_t *)&DAT_0001b9f4;
LAB_00012ca0:
    wcsncpy(_Dest,param_2,0x1ff);
    _Dest[0x1ff] = L'\0';
    break;
  case 0xd:
    uVar1 = _wtol(param_2);
    DAT_0001b1b4 = uVar1 & 0xffff;
    break;
  case 0xe:
    uVar1 = _wtol(param_2);
    DAT_0001b1b8 = uVar1 & 0xffff;
  }
  return;
}



/* 00012cc4 FUN_00012cc4 */

/* Boundary evidence: original MIPS .pdata 00012cc4..00012d53. Semantic name remains unreviewed. */

void FUN_00012cc4(wchar_t *param_1)

{
  int iVar1;
  wchar_t *_Str2;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_00018934 != 0) {
    _Str2 = u_policy__000154cc;
    do {
      iVar1 = _wcsnicmp(param_1,_Str2,*(size_t *)(_Str2 + 0x200));
      if (iVar1 == 0) {
        FUN_00012b18(*(undefined4 *)(_Str2 + 0x202),param_1 + *(int *)(_Str2 + 0x200));
      }
      uVar2 = uVar2 + 1;
      _Str2 = _Str2 + 0x204;
    } while (uVar2 < DAT_00018934);
  }
  return;
}



/* 00012d54 FUN_00012d54 */

/* Boundary evidence: original MIPS .pdata 00012d54..00012dd3. Semantic name remains unreviewed. */

void FUN_00012d54(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_000142cc(L"ipseccfg load policyFile \n",param_2,param_3,param_4);
  FUN_000142cc(L"ipseccfg unload policyName \n",param_2,param_3,param_4);
  FUN_000142cc(L"ipseccfg startonly \n",param_2,param_3,param_4);
  FUN_000142cc(L"ipseccfg start [policyName] \n",param_2,param_3,param_4);
  FUN_000142cc(L"ipseccfg set [policyName] \n",param_2,param_3,param_4);
  FUN_000142cc(L"ipseccfg reset [me/myip/ip] \n",param_2,param_3,param_4);
  FUN_000142cc(L"ipseccfg stop \n",param_2,param_3,param_4);
  FUN_000142cc(L"ipseccfg loglevel [none/err/warn/diag/pss/trace/verb/audit] \n",param_2,param_3,
               param_4);
  FUN_000142cc(L"ipseccfg logmethod [celog/debug] \n",param_2,param_3,param_4);
  return;
}



/* 00012dd4 FUN_00012dd4 */

/* Boundary evidence: original MIPS .pdata 00012dd4..00012e57. Semantic name remains unreviewed. */

void FUN_00012dd4(void)

{
  memset(&DAT_0001b1b4,0,0x30);
  DAT_0001b1b4 = 1;
  DAT_0001b1b8 = 2;
  DAT_0001b1bc = 2;
  DAT_0001b1c0 = 0;
  DAT_0001b1c4 = 0;
  DAT_0001b1c8 = 3;
  DAT_0001b1cc = 3;
  DAT_0001b1d0 = 3;
  DAT_0001b1d4 = 3;
  DAT_0001b1d8 = 3;
  DAT_0001b1dc = 0;
  DAT_0001b1e0 = 0;
  DAT_0001b1f0 = 0;
  return;
}



/* 00012e58 FUN_00012e58 */

/* Boundary evidence: original MIPS .pdata 00012e58..00012f03. Semantic name remains unreviewed. */

void FUN_00012e58(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  wchar_t *pwVar2;
  uint uVar3;
  uint *puVar4;
  
  DVar1 = FUN_000143f4();
  if ((int)DVar1 < 0) {
    uVar3 = 0;
    if (DAT_0001b188 != 0) {
      puVar4 = &DAT_00018d3c;
      do {
        if ((DVar1 & 0xffff) == *puVar4) {
          pwVar2 = u_ERROR_SUCCESS_00018938 + uVar3 * 0x204;
          goto LAB_00012eb0;
        }
        uVar3 = uVar3 + 1;
        puVar4 = puVar4 + 0x102;
      } while (uVar3 < DAT_0001b188);
    }
    pwVar2 = (wchar_t *)0x0;
LAB_00012eb0:
    if (pwVar2 == (wchar_t *)0x0) {
      pwVar2 = L"UNKNOWN ERROR";
    }
    FUN_000142cc(L"Unable to start IPSec. Error code [%d] [%s] \n",DVar1 & 0xffff,pwVar2,param_4);
  }
  else {
    FUN_000142cc(L"Started IPSec \n",param_2,param_3,param_4);
  }
  return;
}



/* 00012f04 FUN_00012f04 */

/* Boundary evidence: original MIPS .pdata 00012f04..00012fd7. Semantic name remains unreviewed. */

void FUN_00012f04(void)

{
  char *pcVar1;
  DWORD DVar2;
  wchar_t *pwVar3;
  uint uVar4;
  uint *puVar5;
  
  pcVar1 = inet_ntoa((in_addr)DAT_0001bdf4.S_un_b);
  FUN_000142cc(L"Resetting existing IPSec policy for [%s] [%d] [%S]\n",&DAT_0001b9f4,DAT_0001bdf4,
               pcVar1);
  DVar2 = FUN_0001473c(DAT_0001bdf4,0);
  if ((int)DVar2 < 0) {
    uVar4 = 0;
    if (DAT_0001b188 != 0) {
      puVar5 = &DAT_00018d3c;
      do {
        if ((DVar2 & 0xffff) == *puVar5) {
          pwVar3 = u_ERROR_SUCCESS_00018938 + uVar4 * 0x204;
          goto LAB_00012f94;
        }
        uVar4 = uVar4 + 1;
        puVar5 = puVar5 + 0x102;
      } while (uVar4 < DAT_0001b188);
    }
    pwVar3 = (wchar_t *)0x0;
LAB_00012f94:
    if (pwVar3 == (wchar_t *)0x0) {
      pwVar3 = L"UNKNOWN ERROR";
    }
    FUN_000142cc(L"Unable to reset IPSec policy. Error code [%d] [%s] \n",DVar2 & 0xffff,pwVar3,
                 pcVar1);
  }
  return;
}



/* 00012fd8 FUN_00012fd8 */

/* Boundary evidence: original MIPS .pdata 00012fd8..0001309f. Semantic name remains unreviewed. */

void FUN_00012fd8(void)

{
  DWORD DVar1;
  uint uVar2;
  wchar_t *pwVar3;
  uint *puVar4;
  
  pwVar3 = (wchar_t *)0x0;
  uVar2 = 4;
  DVar1 = FUN_00014818(1,&DAT_0001b1e8,4,0);
  if ((int)DVar1 < 0) {
    uVar2 = 0;
    if (DAT_0001b188 != 0) {
      puVar4 = &DAT_00018d3c;
      do {
        if ((DVar1 & 0xffff) == *puVar4) {
          pwVar3 = u_ERROR_SUCCESS_00018938 + uVar2 * 0x204;
          goto LAB_00013048;
        }
        uVar2 = uVar2 + 1;
        puVar4 = puVar4 + 0x102;
      } while (uVar2 < DAT_0001b188);
    }
    pwVar3 = (wchar_t *)0x0;
LAB_00013048:
    if (pwVar3 == (wchar_t *)0x0) {
      pwVar3 = L"UNKNOWN ERROR";
    }
    uVar2 = DVar1 & 0xffff;
    FUN_000142cc(L"Unable to set log level to [%d] due to [%d] [%s]\n",DAT_0001b1e8,uVar2,pwVar3);
  }
  FUN_000142cc(L"Set loglevel to [%d] \n",DAT_0001b1e8,uVar2,pwVar3);
  return;
}



/* 000130a0 FUN_000130a0 */

/* Boundary evidence: original MIPS .pdata 000130a0..00013167. Semantic name remains unreviewed. */

void FUN_000130a0(void)

{
  DWORD DVar1;
  uint uVar2;
  wchar_t *pwVar3;
  uint *puVar4;
  
  pwVar3 = (wchar_t *)0x0;
  uVar2 = 4;
  DVar1 = FUN_00014818(2,&DAT_0001b1ec,4,0);
  if ((int)DVar1 < 0) {
    uVar2 = 0;
    if (DAT_0001b188 != 0) {
      puVar4 = &DAT_00018d3c;
      do {
        if ((DVar1 & 0xffff) == *puVar4) {
          pwVar3 = u_ERROR_SUCCESS_00018938 + uVar2 * 0x204;
          goto LAB_00013110;
        }
        uVar2 = uVar2 + 1;
        puVar4 = puVar4 + 0x102;
      } while (uVar2 < DAT_0001b188);
    }
    pwVar3 = (wchar_t *)0x0;
LAB_00013110:
    if (pwVar3 == (wchar_t *)0x0) {
      pwVar3 = L"UNKNOWN ERROR";
    }
    uVar2 = DVar1 & 0xffff;
    FUN_000142cc(L"Unable to set log method to [%d] due to [%d] [%s] \n",DAT_0001b1ec,uVar2,pwVar3);
  }
  FUN_000142cc(L"Set log method to [%d] \n",DAT_0001b1ec,uVar2,pwVar3);
  return;
}



/* 00013168 FUN_00013168 */

/* Boundary evidence: original MIPS .pdata 00013168..0001320f. Semantic name remains unreviewed. */

bool FUN_00013168(PHKEY param_1,HKEY param_2,LPCWSTR param_3)

{
  LSTATUS LVar1;
  DWORD aDStack_18 [2];
  
  if (*param_1 != (HKEY)0x0) {
    RegCloseKey(*param_1);
    *param_1 = (HKEY)0x0;
  }
  param_1[1] = (HKEY)0x0;
  LVar1 = RegCreateKeyExW(param_2,param_3,0,(LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,param_1
                          ,aDStack_18);
  return LVar1 == 0;
}



/* 00013210 FUN_00013210 */

/* Boundary evidence: original MIPS .pdata 00013210..000132a7. Semantic name remains unreviewed. */

bool FUN_00013210(PHKEY param_1,HKEY param_2,LPCWSTR param_3,REGSAM param_4)

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



/* 000132a8 FUN_000132a8 */

/* Boundary evidence: original MIPS .pdata 000132a8..0001330f. Semantic name remains unreviewed. */

bool FUN_000132a8(PHKEY param_1,HKEY param_2,LPCWSTR param_3,REGSAM param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_00013210(param_1,param_2,param_3,param_4);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = FUN_00013168(param_1,param_2,param_3);
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}



/* 00013310 FUN_00013310 */

/* Boundary evidence: original MIPS .pdata 00013310..000135af. Semantic name remains unreviewed. */

void FUN_00013310(void)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  wchar_t *pwVar2;
  undefined4 uVar3;
  HKEY local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  HKEY local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar3 = 0x20019;
  pwVar2 = L"Comm\\IPSec\\Policies";
  local_30 = (HKEY)0x0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_40 = (HKEY)0x0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  bVar1 = FUN_000132a8(&local_30,(HKEY)0x80000002,L"Comm\\IPSec\\Policies",0x20019);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_000142cc(L"Writing policy [%s] to registry \n",u_default_000150cc,pwVar2,uVar3);
    FUN_000142cc(L"inaction = [%d] \n",DAT_0001b1b4,pwVar2,uVar3);
    FUN_000142cc(L"outaction = [%d] \n",DAT_0001b1b8,pwVar2,uVar3);
    FUN_000142cc(L"auth = [%d] \n",DAT_0001b1bc,pwVar2,uVar3);
    FUN_000142cc(L"mmhash = [%d] \n",DAT_0001b1c8,pwVar2,uVar3);
    FUN_000142cc(L"mmenc = [%d] \n",DAT_0001b1cc,pwVar2,uVar3);
    FUN_000142cc(L"qmhash = [%d] \n",DAT_0001b1d0,pwVar2,uVar3);
    FUN_000142cc(L"qmenc = [%d] \n",DAT_0001b1d4,pwVar2,uVar3);
    FUN_000142cc(L"dh = [%d] \n",DAT_0001b1d8,pwVar2,uVar3);
    FUN_000142cc(L"protocol = [%d] \n",DAT_0001b1dc,pwVar2,uVar3);
    FUN_000142cc(L"srcip = [%s] \n",&DAT_0001b9f4,pwVar2,uVar3);
    FUN_000142cc(L"flags = [%d] \n",DAT_0001b1f0,pwVar2,uVar3);
    FUN_000142cc(L"info = [%s] \n",&DAT_0001b1f4,pwVar2,uVar3);
    bVar1 = FUN_000132a8(&local_40,local_30,u_default_000150cc,0x20019);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      FUN_00012900(&local_40,L"inaction",DAT_0001b1b4);
      FUN_00012900(&local_40,L"outaction",DAT_0001b1b8);
      FUN_00012900(&local_40,L"auth",DAT_0001b1bc);
      FUN_00012900(&local_40,L"mmhash",DAT_0001b1c8);
      FUN_00012900(&local_40,L"mmenc",DAT_0001b1cc);
      FUN_00012900(&local_40,L"qmhash",DAT_0001b1d0);
      FUN_00012900(&local_40,L"qmEnc",DAT_0001b1d4);
      FUN_00012900(&local_40,L"dh",DAT_0001b1d8);
      FUN_00012900(&local_40,L"protocol",DAT_0001b1dc);
      FUN_00012900(&local_40,L"flags",DAT_0001b1f0);
      FUN_00012880(&local_40,L"info",(wchar_t *)&DAT_0001b1f4);
      FUN_00012880(&local_40,L"srcip",(wchar_t *)&DAT_0001b9f4);
    }
  }
  FUN_00012780(&local_40);
  FUN_00012780(&local_30);
  return;
}



/* 000135b0 FUN_000135b0 */

/* Boundary evidence: original MIPS .pdata 000135b0..000138bb. Semantic name remains unreviewed. */

void FUN_000135b0(void)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  size_t sVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined *puVar6;
  HKEY local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  HKEY local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = (HKEY)0x0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_38 = (HKEY)0x0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  bVar1 = FUN_00013210(&local_28,(HKEY)0x80000002,L"Comm\\IPSec\\Policies",0x20019);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    bVar1 = FUN_00013210(&local_38,local_28,u_default_000150cc,0x20019);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      DAT_0001b1b4 = FUN_0001282c(&local_38,L"inaction",DAT_0001b1b4);
      DAT_0001b1b8 = FUN_0001282c(&local_38,L"outaction",DAT_0001b1b8);
      DAT_0001b1bc = FUN_0001282c(&local_38,L"auth",DAT_0001b1bc);
      DAT_0001b1c8 = FUN_0001282c(&local_38,L"mmhash",DAT_0001b1c8);
      DAT_0001b1cc = FUN_0001282c(&local_38,L"mmenc",DAT_0001b1cc);
      DAT_0001b1d0 = FUN_0001282c(&local_38,L"qmhash",DAT_0001b1d0);
      DAT_0001b1d4 = FUN_0001282c(&local_38,L"qmEnc",DAT_0001b1d4);
      DAT_0001b1d8 = FUN_0001282c(&local_38,L"dh",DAT_0001b1d8);
      DAT_0001b1dc = FUN_0001282c(&local_38,L"protocol",DAT_0001b1dc);
      DAT_0001b1f0 = FUN_0001282c(&local_38,L"flags",DAT_0001b1f0);
      puVar6 = &DAT_0001b9f4;
      FUN_000127d0(&local_38,L"srcip",&DAT_0001b9f4,0x1ff);
      DAT_0001bdf2 = 0;
      FUN_00012a8c((wchar_t *)&DAT_0001b9f4,(ulong *)&DAT_0001b1e0);
      puVar5 = &DAT_0001b1f4;
      uVar4 = 0x1ff;
      FUN_000127d0(&local_38,L"info",&DAT_0001b1f4,0x1ff);
      DAT_0001b5f2 = 0;
      DAT_0001b1c0 = &DAT_0001b1f4;
      sVar2 = wcslen((wchar_t *)&DAT_0001b1f4);
      DAT_0001b1c4 = sVar2 << 1;
      FUN_000142cc(L"Loaded policy [%s] from registry \n",u_default_000150cc,puVar5,uVar4);
      FUN_000142cc(L"inaction = [%d] \n",DAT_0001b1b4,puVar5,uVar4);
      FUN_000142cc(L"outaction = [%d] \n",DAT_0001b1b8,puVar5,uVar4);
      FUN_000142cc(L"auth = [%d] \n",DAT_0001b1bc,puVar5,uVar4);
      FUN_000142cc(L"mmhash = [%d] \n",DAT_0001b1c8,puVar5,uVar4);
      FUN_000142cc(L"mmenc = [%d] \n",DAT_0001b1cc,puVar5,uVar4);
      FUN_000142cc(L"qmhash = [%d] \n",DAT_0001b1d0,puVar5,uVar4);
      FUN_000142cc(L"qmenc = [%d] \n",DAT_0001b1d4,puVar5,uVar4);
      FUN_000142cc(L"dh = [%d] \n",DAT_0001b1d8,puVar5,uVar4);
      FUN_000142cc(L"protocol = [%d] \n",DAT_0001b1dc,puVar5,uVar4);
      pcVar3 = inet_ntoa((in_addr)DAT_0001b1e0.S_un_b);
      FUN_000142cc(L"srcip = [%d] [%s] [%S] \n",DAT_0001b1e0,&DAT_0001b9f4,pcVar3);
      FUN_000142cc(L"flags = [%d] \n",DAT_0001b1f0,puVar6,pcVar3);
      FUN_000142cc(L"info = [%s] \n",&DAT_0001b1f4,puVar6,pcVar3);
    }
  }
  FUN_00012780(&local_38);
  FUN_00012780(&local_28);
  return;
}



/* 000138bc FUN_000138bc */

/* Boundary evidence: original MIPS .pdata 000138bc..00013a77. Semantic name remains unreviewed. */

void FUN_000138bc(void)

{
  FILE *_File;
  size_t sVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  undefined4 in_a3;
  uint uVar4;
  undefined4 local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  wchar_t local_420;
  undefined1 local_41e [1020];
  undefined2 local_22;
  uint local_20;
  
  local_20 = DAT_000150c4;
  uVar3 = 0x3fe;
  local_430 = 0;
  local_42c = 0;
  local_428 = 0;
  local_424 = 0;
  local_420 = L'\0';
  memset(local_41e,0,0x3fe);
  _File = _wfopen((wchar_t *)&DAT_0001b5f4,L"r");
  if (_File == (FILE *)0x0) {
    FUN_000142cc(L"File [%s] not found \n",&DAT_0001b5f4,uVar3,in_a3);
  }
  else {
    FUN_00012dd4();
    u_default_000150cc[0] = L'\0';
    while( true ) {
      local_420 = L'\0';
      pwVar2 = fgetws(&local_420,0x1ff,_File);
      local_22 = 0;
      if (pwVar2 == (wchar_t *)0x0) break;
      uVar4 = 0;
      sVar1 = wcslen(&local_420);
      if (sVar1 != 0) {
        pwVar2 = &local_420;
        do {
          if ((*pwVar2 == L'\r') || (*pwVar2 == L'\n')) {
            *(undefined2 *)(local_41e + uVar4 * 2 + -2) = 0;
            break;
          }
          uVar4 = uVar4 + 1;
          pwVar2 = pwVar2 + 1;
          sVar1 = wcslen(&local_420);
        } while (uVar4 < sVar1);
      }
      if ((local_420 != L';') && (local_420 != L'\0')) {
        if (local_420 == L'#') break;
        FUN_00012cc4(&local_420);
      }
    }
    if (u_default_000150cc[0] != L'\0') {
      FUN_000142cc(L"Loading policy [%s] from file [%s] into registry \n",u_default_000150cc,
                   &DAT_0001b5f4,in_a3);
      FUN_00013310();
    }
    fclose(_File);
  }
  FUN_00012780(&local_430);
  FUN_00012588(local_20);
  return;
}



/* 00013a78 FUN_00013a78 */

/* Boundary evidence: original MIPS .pdata 00013a78..00013aff. Semantic name remains unreviewed. */

void FUN_00013a78(void)

{
  bool bVar1;
  undefined3 extraout_var;
  wchar_t *pwVar2;
  undefined4 uVar3;
  HKEY local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar3 = 0x20019;
  pwVar2 = L"Comm\\IPSec\\Policies";
  local_18 = (HKEY)0x0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  bVar1 = FUN_00013210(&local_18,(HKEY)0x80000002,L"Comm\\IPSec\\Policies",0x20019);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    RegDeleteKeyW(local_18,u_default_000150cc);
    FUN_000142cc(L"Unloaded policy [%s] from the registry \n",u_default_000150cc,pwVar2,uVar3);
  }
  FUN_00012780(&local_18);
  return;
}



/* 00013b00 FUN_00013b00 */

/* Boundary evidence: original MIPS .pdata 00013b00..00013caf. Semantic name remains unreviewed. */

void FUN_00013b00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int in_stack_ffffffd0;
  
  DVar1 = FUN_000143f4();
  if ((int)DVar1 < 0) {
    uVar5 = 0;
    if (DAT_0001b188 != 0) {
      puVar6 = &DAT_00018d3c;
      do {
        if ((DVar1 & 0xffff) == *puVar6) {
          pwVar3 = u_ERROR_SUCCESS_00018938 + uVar5 * 0x204;
          goto LAB_00013b5c;
        }
        uVar5 = uVar5 + 1;
        puVar6 = puVar6 + 0x102;
      } while (uVar5 < DAT_0001b188);
    }
    pwVar3 = (wchar_t *)0x0;
LAB_00013b5c:
    if (pwVar3 == (wchar_t *)0x0) {
      pwVar3 = L"UNKNOWN ERROR";
    }
    FUN_000142cc(L"Unable to start IPSec. Error code [%d] [%s] \n",DVar1 & 0xffff,pwVar3,param_4);
  }
  else {
    FUN_000142cc(L"Started IPSec \n",param_2,param_3,param_4);
    FUN_00012dd4();
    FUN_000135b0();
    memcpy(&stack0xffffffd0,&DAT_0001b1c4,0x20);
    uVar5 = DAT_0001b1bc;
    iVar4 = DAT_0001b1c0;
    DVar1 = FUN_00014584(DAT_0001b1b4,DAT_0001b1b8,DAT_0001b1bc,DAT_0001b1c0,in_stack_ffffffd0);
    if ((int)DVar1 < 0) {
      uVar5 = 0;
      if (DAT_0001b188 != 0) {
        puVar6 = &DAT_00018d3c;
        do {
          if ((DVar1 & 0xffff) == *puVar6) {
            pwVar3 = u_ERROR_SUCCESS_00018938 + uVar5 * 0x204;
            goto LAB_00013c34;
          }
          uVar5 = uVar5 + 1;
          puVar6 = puVar6 + 0x102;
        } while (uVar5 < DAT_0001b188);
      }
      pwVar3 = (wchar_t *)0x0;
LAB_00013c34:
      if (pwVar3 == (wchar_t *)0x0) {
        pwVar3 = L"UNKNOWN ERROR";
      }
      uVar5 = DVar1 & 0xffff;
      pwVar2 = u_default_000150cc;
      FUN_000142cc(L"Unable to set IPSec policy [%s]. Error code [%d] [%s] \n",u_default_000150cc,
                   uVar5,pwVar3);
      FUN_000142cc(L"Stopping IPSec \n",pwVar2,uVar5,pwVar3);
      FUN_000144bc();
    }
    else {
      FUN_000142cc(L"Set policy to [%s] successfully \n",u_default_000150cc,uVar5,iVar4);
    }
  }
  return;
}



/* 00013cb0 FUN_00013cb0 */

/* Boundary evidence: original MIPS .pdata 00013cb0..00013dc7. Semantic name remains unreviewed. */

void FUN_00013cb0(void)

{
  DWORD DVar1;
  wchar_t *pwVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint uVar5;
  uint *puVar6;
  int in_stack_ffffffd0;
  
  FUN_00012dd4();
  FUN_000135b0();
  memcpy(&stack0xffffffd0,&DAT_0001b1c4,0x20);
  uVar5 = DAT_0001b1bc;
  iVar3 = DAT_0001b1c0;
  DVar1 = FUN_00014584(DAT_0001b1b4,DAT_0001b1b8,DAT_0001b1bc,DAT_0001b1c0,in_stack_ffffffd0);
  if ((int)DVar1 < 0) {
    uVar5 = 0;
    if (DAT_0001b188 != 0) {
      puVar6 = &DAT_00018d3c;
      do {
        if ((DVar1 & 0xffff) == *puVar6) {
          pwVar4 = u_ERROR_SUCCESS_00018938 + uVar5 * 0x204;
          goto LAB_00013d4c;
        }
        uVar5 = uVar5 + 1;
        puVar6 = puVar6 + 0x102;
      } while (uVar5 < DAT_0001b188);
    }
    pwVar4 = (wchar_t *)0x0;
LAB_00013d4c:
    if (pwVar4 == (wchar_t *)0x0) {
      pwVar4 = L"UNKNOWN ERROR";
    }
    uVar5 = DVar1 & 0xffff;
    pwVar2 = u_default_000150cc;
    FUN_000142cc(L"Unable to set IPSec policy [%s]. Error code [%d] [%s] \n",u_default_000150cc,
                 uVar5,pwVar4);
    FUN_000142cc(L"Stopping IPSec \n",pwVar2,uVar5,pwVar4);
    FUN_000144bc();
  }
  else {
    FUN_000142cc(L"Set policy to [%s] successfully \n",u_default_000150cc,uVar5,iVar3);
  }
  return;
}



/* 00013dc8 FUN_00013dc8 */

/* Boundary evidence: original MIPS .pdata 00013dc8..00013ecb. Semantic name remains unreviewed. */

void FUN_00013dc8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  switch(DAT_0001b1e4) {
  case 1:
    FUN_00013b00(param_1,param_2,param_3,param_4);
    break;
  case 2:
    FUN_00012f04();
    break;
  case 3:
    FUN_000142cc(L"Stopping IPSec \n",param_2,param_3,param_4);
    FUN_000144bc();
    break;
  case 4:
    FUN_00012fd8();
    break;
  case 5:
    FUN_000130a0();
    break;
  case 6:
    FUN_00012e58(param_1,param_2,param_3,param_4);
    break;
  case 7:
    FUN_00013cb0();
    break;
  case 8:
    FUN_00013a78();
    break;
  case 9:
    FUN_000138bc();
    break;
  default:
    FUN_00012d54(param_1,param_2,param_3,param_4);
  }
  return;
}



/* 00013ecc FUN_00013ecc */

/* Boundary evidence: original MIPS .pdata 00013ecc..000142cb. Semantic name remains unreviewed. */

undefined4 FUN_00013ecc(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  wchar_t *_Str1;
  wchar_t *lpWSAData;
  wchar_t *_Dest;
  WSADATA WStack_1b8;
  uint local_28;
  
  local_28 = DAT_000150c4;
  lpWSAData = (wchar_t *)&WStack_1b8;
  _Str1 = (wchar_t *)0x2;
  iVar1 = WSAStartup(2,(LPWSADATA)lpWSAData);
  if (iVar1 != 0) goto LAB_00013fd4;
  if (param_1 < 2) goto LAB_00013fbc;
  DAT_0001b1e4 = 0;
  _Str1 = *(wchar_t **)(param_2 + 4);
  lpWSAData = L"start";
  iVar1 = _wcsicmp(_Str1,L"start");
  if (iVar1 == 0) {
    DAT_0001b1e4 = 1;
LAB_00013f50:
    if (2 < param_1) {
LAB_00013f60:
      lpWSAData = *(wchar_t **)(param_2 + 8);
      _Dest = u_default_000150cc;
      goto LAB_0001403c;
    }
  }
  else {
    _Str1 = *(wchar_t **)(param_2 + 4);
    lpWSAData = (wchar_t *)&LAB_00011ad8;
    iVar1 = _wcsicmp(_Str1,L"set");
    if (iVar1 == 0) {
      DAT_0001b1e4 = 7;
      goto LAB_00013f50;
    }
    _Str1 = *(wchar_t **)(param_2 + 4);
    lpWSAData = L"unload";
    iVar1 = _wcsicmp(_Str1,L"unload");
    if (iVar1 == 0) {
      DAT_0001b1e4 = 8;
      if (param_1 < 3) goto LAB_00013fbc;
      goto LAB_00013f60;
    }
    _Str1 = *(wchar_t **)(param_2 + 4);
    lpWSAData = L"load";
    iVar1 = _wcsicmp(_Str1,L"load");
    if (iVar1 != 0) {
      _Str1 = *(wchar_t **)(param_2 + 4);
      lpWSAData = L"startonly";
      iVar1 = _wcsicmp(_Str1,L"startonly");
      if (iVar1 == 0) {
        DAT_0001b1e4 = 6;
      }
      else {
        _Str1 = *(wchar_t **)(param_2 + 4);
        lpWSAData = L"reset";
        iVar1 = _wcsicmp(_Str1,L"reset");
        if (iVar1 == 0) {
          DAT_0001b1e4 = 2;
          if (2 < param_1) {
            _Str1 = (wchar_t *)&DAT_0001b9f4;
            param_3 = 0x1ff;
            wcsncpy((wchar_t *)&DAT_0001b9f4,*(wchar_t **)(param_2 + 8),0x1ff);
            DAT_0001bdf2 = 0;
            lpWSAData = (wchar_t *)&DAT_0001bdf4;
            FUN_00012a8c((wchar_t *)&DAT_0001b9f4,&DAT_0001bdf4);
          }
        }
        else {
          _Str1 = *(wchar_t **)(param_2 + 4);
          lpWSAData = L"stop";
          iVar1 = _wcsicmp(_Str1,L"stop");
          if (iVar1 != 0) {
            _Str1 = *(wchar_t **)(param_2 + 4);
            lpWSAData = L"loglevel";
            iVar1 = _wcsicmp(_Str1,L"loglevel");
            if (iVar1 == 0) {
              DAT_0001b1e4 = 4;
              DAT_0001b1e8 = 1;
              if (2 < param_1) {
                _Str1 = *(wchar_t **)(param_2 + 8);
                lpWSAData = L"none";
                iVar1 = _wcsicmp(_Str1,L"none");
                if (iVar1 == 0) {
                  DAT_0001b1e8 = 0;
                }
                else {
                  _Str1 = *(wchar_t **)(param_2 + 8);
                  lpWSAData = (wchar_t *)&DAT_00011a68;
                  iVar1 = _wcsicmp(_Str1,L"err");
                  if (iVar1 == 0) {
                    DAT_0001b1e8 = 1;
                  }
                  else {
                    _Str1 = *(wchar_t **)(param_2 + 8);
                    lpWSAData = L"warn";
                    iVar1 = _wcsicmp(_Str1,L"warn");
                    if (iVar1 == 0) {
                      DAT_0001b1e8 = 2;
                    }
                    else {
                      _Str1 = *(wchar_t **)(param_2 + 8);
                      lpWSAData = L"diag";
                      iVar1 = _wcsicmp(_Str1,L"diag");
                      if (iVar1 == 0) {
                        DAT_0001b1e8 = 3;
                      }
                      else {
                        _Str1 = *(wchar_t **)(param_2 + 8);
                        lpWSAData = (wchar_t *)&DAT_00011a48;
                        iVar1 = _wcsicmp(_Str1,L"pss");
                        if (iVar1 == 0) {
                          DAT_0001b1e8 = 4;
                        }
                        else {
                          _Str1 = *(wchar_t **)(param_2 + 8);
                          lpWSAData = L"trace";
                          iVar1 = _wcsicmp(_Str1,L"trace");
                          if (iVar1 == 0) {
                            DAT_0001b1e8 = 5;
                          }
                          else {
                            _Str1 = *(wchar_t **)(param_2 + 8);
                            lpWSAData = L"verb";
                            iVar1 = _wcsicmp(_Str1,L"verb");
                            if (iVar1 == 0) {
                              DAT_0001b1e8 = 6;
                            }
                            else {
                              _Str1 = *(wchar_t **)(param_2 + 8);
                              lpWSAData = L"audit";
                              iVar1 = _wcsicmp(_Str1,L"audit");
                              if (iVar1 != 0) goto LAB_00013fbc;
                              DAT_0001b1e8 = 7;
                            }
                          }
                        }
                      }
                    }
                  }
                }
                goto LAB_0001429c;
              }
            }
            else {
              _Str1 = *(wchar_t **)(param_2 + 4);
              lpWSAData = L"logmethod";
              iVar1 = _wcsicmp(_Str1,L"logmethod");
              if (iVar1 == 0) {
                DAT_0001b1e4 = 5;
                DAT_0001b1ec = 1;
                if (2 < param_1) {
                  _Str1 = *(wchar_t **)(param_2 + 8);
                  lpWSAData = L"celog";
                  iVar1 = _wcsicmp(_Str1,L"celog");
                  if (iVar1 == 0) {
                    DAT_0001b1ec = 2;
                  }
                  else {
                    _Str1 = *(wchar_t **)(param_2 + 8);
                    lpWSAData = L"debug";
                    iVar1 = _wcsicmp(_Str1,L"debug");
                    if (iVar1 != 0) goto LAB_00013fbc;
                    DAT_0001b1ec = 1;
                  }
                  goto LAB_0001429c;
                }
              }
            }
LAB_00013fbc:
            WSACleanup();
            FUN_00012d54(_Str1,lpWSAData,param_3,param_4);
            goto LAB_00013fd4;
          }
          DAT_0001b1e4 = 3;
        }
      }
      goto LAB_0001429c;
    }
    DAT_0001b1e4 = 9;
    if (param_1 < 3) goto LAB_00013fbc;
    lpWSAData = *(wchar_t **)(param_2 + 8);
    _Dest = (wchar_t *)&DAT_0001b5f4;
LAB_0001403c:
    param_3 = 0x1ff;
    wcsncpy(_Dest,lpWSAData,0x1ff);
    _Str1 = (wchar_t *)0x0;
    _Dest[0x1ff] = L'\0';
  }
LAB_0001429c:
  FUN_00014914();
  FUN_00013dc8(_Str1,lpWSAData,param_3,param_4);
  FUN_00014914();
  WSACleanup();
LAB_00013fd4:
  FUN_00012588(local_28);
  return 0;
}



/* 000142cc FUN_000142cc */

/* Boundary evidence: original MIPS .pdata 000142cc..0001433b. Semantic name remains unreviewed. */

void FUN_000142cc(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  wchar_t awStack_810 [1024];
  undefined2 local_10;
  uint local_c;
  
  local_c = DAT_000150c4;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  _vsnwprintf(awStack_810,0x400,param_1,(va_list)&local_res4);
  local_10 = 0;
  if (DAT_0001b18c == 1) {
    NKDbgPrintfW(L"IPSECCFG: %s",awStack_810);
  }
  FUN_00012588(local_c);
  return;
}



/* 0001433c FUN_0001433c */

/* Boundary evidence: original MIPS .pdata 0001433c..000143f3. Semantic name remains unreviewed. */

undefined4 FUN_0001433c(void)

{
  LONG LVar1;
  
  if (DAT_0001b190 == -1) {
    DAT_0001b194 = CreateFileW(L"IKE0:",0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    LVar1 = InterlockedCompareExchange(&DAT_0001b190,(LONG)DAT_0001b194,-1);
    if (LVar1 != -1) {
      CloseHandle(DAT_0001b194);
    }
    if (DAT_0001b190 == -1) {
      return 0;
    }
  }
  return 1;
}



/* 000143f4 FUN_000143f4 */

/* Boundary evidence: original MIPS .pdata 000143f4..000144bb. Semantic name remains unreviewed. */

DWORD FUN_000143f4(void)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 local_10;
  DWORD local_c;
  
  iVar1 = FUN_0001433c();
  if (iVar1 == 0) {
    local_c = 0x80070426;
  }
  else {
    local_10 = 2;
    local_c = 0x80004005;
    BVar2 = DeviceIoControl(DAT_0001b190,1,&local_10,8,(LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0)
    ;
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      if ((int)DVar3 < 1) {
        local_c = GetLastError();
      }
      else {
        DVar3 = GetLastError();
        local_c = DVar3 & 0xffff | 0x80070000;
      }
    }
  }
  return local_c;
}



/* 000144bc FUN_000144bc */

/* Boundary evidence: original MIPS .pdata 000144bc..00014583. Semantic name remains unreviewed. */

DWORD FUN_000144bc(void)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 local_10;
  DWORD local_c;
  
  iVar1 = FUN_0001433c();
  if (iVar1 == 0) {
    local_c = 0x80070426;
  }
  else {
    local_10 = 3;
    local_c = 0x80004005;
    BVar2 = DeviceIoControl(DAT_0001b190,1,&local_10,8,(LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0)
    ;
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      if ((int)DVar3 < 1) {
        local_c = GetLastError();
      }
      else {
        DVar3 = GetLastError();
        local_c = DVar3 & 0xffff | 0x80070000;
      }
    }
  }
  return local_c;
}



/* 00014584 FUN_00014584 */

/* Boundary evidence: original MIPS .pdata 00014584..0001473b. Semantic name remains unreviewed. */

DWORD FUN_00014584(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  int local_res0;
  int local_res4;
  uint local_res8;
  int local_resc;
  undefined4 local_58;
  DWORD local_54;
  undefined1 auStack_50 [56];
  
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  iVar1 = FUN_0001433c();
  if (iVar1 == 0) {
    local_54 = 0x80070426;
  }
  else {
    if (param_1 == 0) {
      local_res0 = 1;
    }
    if (param_2 == 0) {
      local_res4 = 2;
    }
    if (param_3 == 0) {
      param_3 = 0;
      local_res8 = 2;
    }
    if (((param_3 & 1) == 0) || ((param_4 != 0 && (param_5 != 0)))) {
      local_58 = 4;
      local_54 = 0x80004005;
      memcpy(auStack_50,&local_res0,0x30);
      BVar2 = DeviceIoControl(DAT_0001b190,1,&local_58,0x3c,(LPVOID)0x0,0,(LPDWORD)0x0,
                              (LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        DVar3 = GetLastError();
        if ((int)DVar3 < 1) {
          local_54 = GetLastError();
        }
        else {
          DVar3 = GetLastError();
          local_54 = DVar3 & 0xffff | 0x80070000;
        }
      }
    }
    else {
      local_54 = 0x80070057;
    }
  }
  return local_54;
}



/* 0001473c FUN_0001473c */

/* Boundary evidence: original MIPS .pdata 0001473c..00014817. Semantic name remains unreviewed. */

DWORD FUN_0001473c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 local_20;
  DWORD local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = FUN_0001433c();
  if (iVar1 == 0) {
    local_1c = 0x80070426;
  }
  else {
    local_20 = 5;
    local_1c = 0x80004005;
    local_18 = param_1;
    local_14 = param_2;
    BVar2 = DeviceIoControl(DAT_0001b190,1,&local_20,0x10,(LPVOID)0x0,0,(LPDWORD)0x0,
                            (LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      if ((int)DVar3 < 1) {
        local_1c = GetLastError();
      }
      else {
        DVar3 = GetLastError();
        local_1c = DVar3 & 0xffff | 0x80070000;
      }
    }
  }
  return local_1c;
}



/* 00014818 FUN_00014818 */

/* Boundary evidence: original MIPS .pdata 00014818..00014913. Semantic name remains unreviewed. */

DWORD FUN_00014818(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 local_30;
  DWORD local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar1 = FUN_0001433c();
  if (iVar1 == 0) {
    local_2c = 0x80070426;
  }
  else {
    local_30 = 6;
    local_2c = 0x80004005;
    local_28 = param_1;
    local_24 = param_2;
    local_20 = param_3;
    local_1c = param_4;
    BVar2 = DeviceIoControl(DAT_0001b190,1,&local_30,0x18,(LPVOID)0x0,0,(LPDWORD)0x0,
                            (LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      if ((int)DVar3 < 1) {
        local_2c = GetLastError();
      }
      else {
        DVar3 = GetLastError();
        local_2c = DVar3 & 0xffff | 0x80070000;
      }
    }
  }
  return local_2c;
}



/* 00014914 FUN_00014914 */

void FUN_00014914(void)

{
  return;
}



/* 0001491c FUN_0001491c */

/* Boundary evidence: original MIPS .pdata 0001491c..00014937. Semantic name remains unreviewed. */

void FUN_0001491c(size_t param_1)

{
  malloc(param_1);
  return;
}



/* 00014938 FUN_00014938 */

/* Boundary evidence: original MIPS .pdata 00014938..00014953. Semantic name remains unreviewed. */

void FUN_00014938(void *param_1,size_t param_2)

{
  realloc(param_1,param_2);
  return;
}



/* 00014954 FUN_00014954 */

/* Boundary evidence: original MIPS .pdata 00014954..0001496f. Semantic name remains unreviewed. */

void FUN_00014954(void *param_1)

{
  free(param_1);
  return;
}


