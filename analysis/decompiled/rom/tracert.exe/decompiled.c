/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011814 FUN_00011814 */

/* Boundary evidence: original MIPS .pdata 00011814..0001183f. Semantic name remains unreviewed. */

void FUN_00011814(void)

{
  if (DAT_00014160 != (void *)0x0) {
    free(DAT_00014160);
  }
  return;
}



/* 00011840 FUN_00011840 */

/* Boundary evidence: original MIPS .pdata 00011840..000118cf. Semantic name remains unreviewed. */

int FUN_00011840(wint_t *param_1)

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



/* 000118d0 FUN_000118d0 */

/* Boundary evidence: original MIPS .pdata 000118d0..00011993. Semantic name remains unreviewed. */

void FUN_000118d0(int *param_1,int *param_2,wint_t *param_3)

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
    iVar2 = FUN_00011840(pwVar3);
    *param_2 = *param_2 + iVar2 + 1;
    param_3 = pwVar3 + iVar2;
    *param_1 = *param_1 + 1;
    if (*param_3 == 0) {
      return;
    }
  }
  return;
}



/* 00011994 FUN_00011994 */

/* Boundary evidence: original MIPS .pdata 00011994..00011b6b. Semantic name remains unreviewed. */

undefined4 FUN_00011994(wchar_t *param_1,wint_t *param_2,int *param_3,undefined4 *param_4)

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
    FUN_000118d0(&local_38,(int *)&local_34,param_2);
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
        iVar6 = FUN_00011840(pwVar10);
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



/* 00011b6c FUN_00011b6c */

/* Boundary evidence: original MIPS .pdata 00011b6c..00011c63. Semantic name remains unreviewed. */

void FUN_00011b6c(HMODULE param_1,wint_t *param_2)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  short **ppsVar4;
  undefined4 **ppuVar5;
  short *local_224;
  undefined4 *local_220 [2];
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_000140b4;
  DAT_00014168 = param_1;
  DVar1 = GetModuleFileNameW(param_1,aWStack_218,0x100);
  if (DVar1 == 0) {
    FUN_00011e20(0xfffffffd);
  }
  FUN_00012140(FUN_00011814);
  FUN_00011ec0();
  ppuVar5 = local_220;
  ppsVar4 = &local_224;
  iVar2 = FUN_00011994(aWStack_218,param_2,(int *)ppsVar4,ppuVar5);
  if (iVar2 == 0) {
    FUN_00011e20(0xfffffffc);
  }
  DAT_00014164 = local_224;
  DAT_00014160 = local_220[0];
  UVar3 = FUN_00012c48(local_224,local_220[0],ppsVar4,(int *)ppuVar5);
  FUN_00011e00(UVar3);
  FUN_00011e20(UVar3);
  FUN_00012260(local_18);
  return;
}



/* 00011c64 FUN_00011c64 */

/* Boundary evidence: original MIPS .pdata 00011c64..00011ca3. Semantic name remains unreviewed. */

void FUN_00011c64(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x228) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x228),param_1);
  return;
}



/* 00011ca4 entry */

/* Boundary evidence: original MIPS .pdata 00011ca4..00011cdf. Semantic name remains unreviewed. */

void entry(HMODULE param_1,undefined4 param_2,wint_t *param_3)

{
  FUN_00012170();
  FUN_00011b6c(param_1,param_3);
  return;
}



/* 00011ce0 FUN_00011ce0 */

/* Boundary evidence: original MIPS .pdata 00011ce0..00011dff. Semantic name remains unreviewed. */

void FUN_00011ce0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0001416c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00016404;
    if (DAT_00016404 != (undefined4 *)0x0) {
      while (DAT_00016400 = DAT_00016400 + -1, _Memory <= DAT_00016400) {
        if ((code *)*DAT_00016400 != (code *)0x0) {
          (*(code *)*DAT_00016400)();
          _Memory = DAT_00016404;
        }
      }
      free(_Memory);
      DAT_00016400 = (undefined4 *)0x0;
      DAT_00016404 = (undefined4 *)0x0;
    }
    FUN_00011e6c((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_00011e6c((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_00016408,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011e00 FUN_00011e00 */

/* Boundary evidence: original MIPS .pdata 00011e00..00011e1f. Semantic name remains unreviewed. */

void FUN_00011e00(UINT param_1)

{
  FUN_00011ce0(param_1,0,0);
  return;
}



/* 00011e20 FUN_00011e20 */

/* Boundary evidence: original MIPS .pdata 00011e20..00011e6b. Semantic name remains unreviewed. */

void FUN_00011e20(UINT param_1)

{
  DAT_0001416c = 0;
  FUN_00011e6c((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00011e6c FUN_00011e6c */

/* Boundary evidence: original MIPS .pdata 00011e6c..00011ebf. Semantic name remains unreviewed. */

void FUN_00011e6c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00011ec0 FUN_00011ec0 */

/* Boundary evidence: original MIPS .pdata 00011ec0..00011efb. Semantic name remains unreviewed. */

void FUN_00011ec0(void)

{
  FUN_00011e6c((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_00011e6c((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00011efc FUN_00011efc */

/* Boundary evidence: original MIPS .pdata 00011efc..00012007. Semantic name remains unreviewed. */

undefined4 FUN_00011efc(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_00016404;
  puVar3 = DAT_00016400;
  iVar4 = (int)DAT_00016400 - (int)DAT_00016404;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_00011f40:
    param_1 = 0;
  }
  else {
    if (DAT_00016404 != (void *)0x0) {
      uVar1 = _msize(DAT_00016404);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_00011fb4:
        if (pvVar2 == (void *)0x0) goto LAB_00011f40;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_00011fb4;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_00016400 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_00016404 = pvVar2;
  }
  return param_1;
}



/* 00012008 FUN_00012008 */

/* Boundary evidence: original MIPS .pdata 00012008..000120f3. Semantic name remains unreviewed. */

undefined4 FUN_00012008(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_00016408 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_00016408,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_00016408 == (LPCRITICAL_SECTION)0x0) goto LAB_000120ac;
  }
  EnterCriticalSection(DAT_00016408);
LAB_000120ac:
  uVar2 = FUN_00011efc(param_1);
  FUN_000120f4();
  return uVar2;
}



/* 000120f4 FUN_000120f4 */

/* Boundary evidence: original MIPS .pdata 000120f4..0001213f. Semantic name remains unreviewed. */

void FUN_000120f4(void)

{
  if (DAT_00016408 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_00016408);
  }
  return;
}



/* 00012140 FUN_00012140 */

/* Boundary evidence: original MIPS .pdata 00012140..0001216f. Semantic name remains unreviewed. */

undefined4 FUN_00012140(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00012008(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00012170 FUN_00012170 */

/* Boundary evidence: original MIPS .pdata 00012170..000121e3. Semantic name remains unreviewed. */

void FUN_00012170(void)

{
  uint uVar1;
  
  if ((DAT_000140b4 == 0) || (DAT_000140b4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000140b4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000140b4 == 0) {
      DAT_000140b4 = 0xb064;
    }
  }
  DAT_000140b8 = ~DAT_000140b4;
  return;
}



/* 000121e4 FUN_000121e4 */

/* Boundary evidence: original MIPS .pdata 000121e4..0001225f. Semantic name remains unreviewed. */

void FUN_000121e4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_000122a8(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 00012260 FUN_00012260 */

/* Boundary evidence: original MIPS .pdata 00012260..000122a7. Semantic name remains unreviewed. */

void FUN_00012260(uint param_1)

{
  if ((param_1 == DAT_000140b4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 000122a8 FUN_000122a8 */

/* Boundary evidence: original MIPS .pdata 000122a8..000122fb. Semantic name remains unreviewed. */

void FUN_000122a8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00012260(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 000122fc FUN_000122fc */

/* Boundary evidence: original MIPS .pdata 000122fc..00012327. Semantic name remains unreviewed. */

undefined4 FUN_000122fc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_000122a8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00012458 FUN_00012458 */

/* Boundary evidence: original MIPS .pdata 00012458..000124cf. Semantic name remains unreviewed. */

bool FUN_00012458(char *param_1,LPWSTR param_2,int param_3)

{
  size_t sVar1;
  int iVar2;
  
  sVar1 = strlen(param_1);
  iVar2 = MultiByteToWideChar(1,0,param_1,sVar1 + 1,param_2,param_3);
  return iVar2 != 0;
}



/* 000124d0 FUN_000124d0 */

/* Boundary evidence: original MIPS .pdata 000124d0..0001254f. Semantic name remains unreviewed. */

bool FUN_000124d0(wchar_t *param_1,LPSTR param_2,int param_3)

{
  size_t sVar1;
  int iVar2;
  
  sVar1 = wcslen(param_1);
  iVar2 = WideCharToMultiByte(1,0,param_1,sVar1 + 1,param_2,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
  return iVar2 != 0;
}



/* 00012550 FUN_00012550 */

/* Boundary evidence: original MIPS .pdata 00012550..000126df. Semantic name remains unreviewed. */

void FUN_00012550(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  WCHAR WVar1;
  bool bVar2;
  undefined3 extraout_var;
  size_t sVar3;
  LPCWSTR lpOutputString;
  int iVar4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res8 = param_3;
  local_resc = param_4;
  bVar2 = FUN_00012458(param_2,(LPWSTR)&DAT_00014360,0x800);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    lpOutputString = (LPCWSTR)&DAT_00015400;
    wvsprintfW((LPWSTR)&DAT_00015400,(LPCWSTR)&DAT_00014360,(va_list)&local_res8);
    if (DAT_000140bc == 0) {
      sVar3 = wcslen((wchar_t *)&DAT_00015400);
      for (iVar4 = (int)sVar3 / 0xfa; 0 < iVar4; iVar4 = iVar4 + -1) {
        WVar1 = lpOutputString[0xfa];
        lpOutputString[0xfa] = L'\0';
        OutputDebugStringW(lpOutputString);
        lpOutputString[0xfa] = WVar1;
        lpOutputString = lpOutputString + 0xfa;
      }
      if ((int)sVar3 % 0xfa != 0) {
        OutputDebugStringW((LPCWSTR)(&DAT_00015400 + ((int)sVar3 / 0xfa) * 500));
      }
    }
    else {
      if (DAT_000153e4 == (code *)0x0) {
        DAT_00014170 = LoadLibraryW(L"coredll.dll");
        if (DAT_00014170 != (HMODULE)0x0) {
          DAT_000153e4 = (code *)GetProcAddressW(DAT_00014170,L"wprintf");
        }
        if (DAT_000153e4 == (code *)0x0) {
          DAT_000140bc = 0;
          return;
        }
      }
      (*DAT_000153e4)(&UNK_00011244,&DAT_00015400);
    }
  }
  return;
}



/* 000126e0 FUN_000126e0 */

/* Boundary evidence: original MIPS .pdata 000126e0..000127fb. Semantic name remains unreviewed. */

void FUN_000126e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 auStack_420 [1028];
  uint local_1c;
  
  local_1c = DAT_000140b4;
  bVar1 = false;
  pcVar5 = "%hs ";
  if (param_3 != 0) {
    uVar4 = 0x401;
    iVar2 = getnameinfo(param_1,param_2,auStack_420,0x401,0,0,4);
    if (iVar2 == 0) {
      bVar1 = true;
      FUN_00012550(1,"%hs ",auStack_420,uVar4);
    }
  }
  uVar4 = 0x401;
  puVar3 = auStack_420;
  iVar2 = getnameinfo(param_1,param_2,puVar3,0x401,0,0,2);
  if (iVar2 != 0) {
    FUN_00012550(1,"No resources.\n",puVar3,uVar4);
    FUN_00011e00(1);
  }
  if (bVar1) {
    pcVar5 = "[%hs] ";
  }
  FUN_00012550(1,pcVar5,auStack_420,uVar4);
  FUN_00012260(local_1c);
  return;
}



/* 000127fc FUN_000127fc */

/* Boundary evidence: original MIPS .pdata 000127fc..00012867. Semantic name remains unreviewed. */

void FUN_000127fc(undefined4 param_1,int param_2)

{
  undefined2 local_28 [2];
  undefined4 local_24;
  uint local_18;
  
  local_18 = DAT_000140b4;
  memset(local_28,0,0x10);
  local_28[0] = 2;
  local_24 = param_1;
  FUN_000126e0(local_28,0x10,param_2);
  FUN_00012260(local_18);
  return;
}



/* 00012868 FUN_00012868 */

/* Boundary evidence: original MIPS .pdata 00012868..000128df. Semantic name remains unreviewed. */

void FUN_00012868(void *param_1,int param_2)

{
  undefined2 local_30 [4];
  undefined1 auStack_28 [20];
  uint local_14;
  
  local_14 = DAT_000140b4;
  memset(local_30,0,0x1c);
  local_30[0] = 0x17;
  memcpy(auStack_28,param_1,0x10);
  FUN_000126e0(local_30,0x1c,param_2);
  FUN_00012260(local_14);
  return;
}



/* 000128e0 FUN_000128e0 */

/* Boundary evidence: original MIPS .pdata 000128e0..00012927. Semantic name remains unreviewed. */

void FUN_000128e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == 0) {
    FUN_00012550(1,"  <1 ms  ",param_3,param_4);
  }
  else {
    FUN_00012550(1,"%4lu ms  ",param_1,param_4);
  }
  return;
}



/* 00012928 FUN_00012928 */

/* Boundary evidence: original MIPS .pdata 00012928..000129cb. Semantic name remains unreviewed. */

undefined4
FUN_00012928(ulong *param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6)

{
  ulong uVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char *apcStack_18 [2];
  
  if (param_4 == param_3 + -1) {
    uVar3 = *(undefined4 *)(param_4 * 4 + param_2);
    pcVar2 = "A value must be supplied for option %hs.\n";
  }
  else {
    puVar4 = (undefined4 *)(param_4 * 4 + param_2);
    uVar1 = strtoul((char *)puVar4[1],apcStack_18,0);
    if ((param_5 <= uVar1) && (uVar1 <= param_6)) {
      *param_1 = uVar1;
      return 1;
    }
    uVar3 = *puVar4;
    pcVar2 = "Bad value for option %hs.\n";
  }
  FUN_00012550(1,pcVar2,uVar3,param_4);
  return 0;
}



/* 000129cc FUN_000129cc */

/* Boundary evidence: original MIPS .pdata 000129cc..00012b3f. Semantic name remains unreviewed. */

undefined4
FUN_000129cc(undefined4 param_1,char *param_2,void *param_3,undefined4 *param_4,char *param_5,
            undefined4 param_6,char param_7)

{
  int iVar1;
  int iVar2;
  int local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  
  *param_5 = '\0';
  memset(&local_40,0,0x20);
  local_40 = 4;
  local_3c = param_1;
  iVar1 = getaddrinfo(param_2,0,&local_40,local_48);
  iVar2 = local_48[0];
  if (iVar1 == 0) {
    *param_4 = *(undefined4 *)(local_48[0] + 0x10);
    memcpy(param_3,*(void **)(local_48[0] + 0x18),*(size_t *)(local_48[0] + 0x10));
    if (param_7 != '\0') {
      getnameinfo(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x10),param_5,param_6,0,0,4)
      ;
      iVar2 = local_48[0];
    }
  }
  else {
    local_40 = 2;
    iVar2 = getaddrinfo(param_2,0,&local_40,local_48);
    if (iVar2 != 0) {
      return 0;
    }
    *param_4 = *(undefined4 *)(local_48[0] + 0x10);
    memcpy(param_3,*(void **)(local_48[0] + 0x18),*(size_t *)(local_48[0] + 0x10));
    if (*(char **)(local_48[0] + 0x14) != (char *)0x0) {
      param_2 = *(char **)(local_48[0] + 0x14);
    }
    strcpy(param_5,param_2);
    iVar2 = local_48[0];
  }
  freeaddrinfo(iVar2);
  return 1;
}



/* 00012b40 FUN_00012b40 */

/* Boundary evidence: original MIPS .pdata 00012b40..00012bdf. Semantic name remains unreviewed. */

bool FUN_00012b40(undefined4 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  int local_40 [2];
  undefined4 local_38;
  undefined4 local_34;
  
  memset(&local_38,0,0x20);
  local_38 = 1;
  local_34 = param_1;
  iVar1 = getaddrinfo(param_2,0,&local_38,local_40);
  if (iVar1 == 0) {
    memcpy(param_3,*(void **)(local_40[0] + 0x18),*(size_t *)(local_40[0] + 0x10));
  }
  return iVar1 == 0;
}



/* 00012be0 FUN_00012be0 */

/* Boundary evidence: original MIPS .pdata 00012be0..00012c47. Semantic name remains unreviewed. */

undefined4 FUN_00012be0(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  if ((*param_1 == 0) || (*param_1 == param_2)) {
    *param_1 = param_2;
    uVar1 = 1;
  }
  else {
    if (param_2 == 2) {
      puVar2 = &DAT_0001131c;
    }
    else {
      puVar2 = &DAT_00011314;
    }
    FUN_00012550(1,"\nThe option %hs is only supported for %hs.\n\n",param_3,puVar2);
    uVar1 = 0;
  }
  return uVar1;
}



/* 00012c48 FUN_00012c48 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 00012c48..0001385b. Semantic name remains unreviewed. */

undefined4 FUN_00012c48(short *param_1,undefined4 *param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  PUCHAR pUVar4;
  bool bVar5;
  int iVar6;
  DWORD DVar7;
  DWORD *pDVar8;
  size_t sVar9;
  LPSTR pCVar10;
  undefined3 extraout_var;
  ulong uVar11;
  HANDLE IcmpHandle;
  char *pcVar12;
  undefined4 uVar13;
  short *psVar14;
  char *pcVar15;
  short *psVar16;
  short *psVar17;
  int *piVar18;
  int iVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  short *psVar22;
  DWORD *pDVar23;
  uint uVar24;
  uint uVar25;
  byte local_5e0;
  ip_option_information local_5d8;
  int local_5d0;
  int local_5cc;
  short *local_5c8;
  char *local_5c4;
  undefined4 local_5c0;
  char *local_5bc;
  short *local_5b8 [2];
  undefined1 auStack_5b0 [16];
  short local_5a0 [2];
  IPAddr local_59c;
  short asStack_520 [64];
  short asStack_4a0 [36];
  short local_458 [20];
  char local_430 [1028];
  uint local_2c;
  
  local_2c = DAT_000140b4;
  local_5bc = (char *)0xfa0;
  local_5c4 = (char *)0xfa0;
  bVar3 = false;
  uVar24 = 1;
  uVar25 = 0;
  local_5c0 = 0;
  local_5c8 = (short *)0x1e;
  local_5b8[0] = (short *)0x1e;
  local_5e0 = 1;
  local_5d0 = 0;
  iVar6 = WSAStartup(2,(LPWSADATA)&DAT_000141c0);
  if (iVar6 != 0) {
    DVar7 = GetLastError();
    FUN_00012550(1,"Unable to initialize the Windows Sockets interface, error code %d.\n",DVar7,
                 param_4);
    goto LAB_00012d04;
  }
  iVar6 = 0x80;
  memset(asStack_520,0,0x80);
  psVar14 = (short *)0x80;
  memset(local_5a0,0,0x80);
  local_5d8.OptionsData = (PUCHAR)local_458;
  local_5cc = 0x80;
  local_5d8.Ttl = 1;
  local_5d8.Tos = '\0';
  local_5d8.Flags = 0;
  local_5d8.OptionsSize = 0;
  pDVar8 = malloc((int)param_1 << 2);
  if (pDVar8 == (DWORD *)0x0) {
    FUN_00012550(1,"malloc failed\n",psVar14,param_4);
    FUN_00011e00(1);
  }
  iVar19 = 0;
  psVar22 = (short *)0x1e;
  if (0 < (int)param_1) {
    uVar24 = (int)pDVar8 - (int)param_2;
    do {
      sVar9 = wcslen((wchar_t *)*param_2);
      psVar22 = (short *)(sVar9 + 1);
      pCVar10 = malloc((size_t)psVar22);
      *(LPSTR *)(uVar24 + (int)param_2) = pCVar10;
      if (pCVar10 == (LPSTR)0x0) {
        FUN_00012550(1,"malloc failed\n",psVar14,param_4);
        FUN_00011e00(1);
        goto LAB_00012df4;
      }
      FUN_000124d0((wchar_t *)*param_2,pCVar10,(int)psVar22);
      iVar19 = iVar19 + 1;
      param_2 = param_2 + 1;
      psVar14 = psVar22;
    } while (iVar19 < (int)param_1);
    uVar24 = 1;
    psVar22 = (short *)0x1e;
  }
LAB_00012df4:
  if (1 < (int)param_1) {
    piVar18 = (int *)0x1;
    if (1 < (int)param_1) {
LAB_00012e28:
      pDVar23 = pDVar8 + (int)piVar18;
      psVar17 = (short *)*pDVar23;
      if (((char)*psVar17 == '-') || ((char)*psVar17 == '/')) {
        cVar1 = *(char *)((int)psVar17 + 1);
        if (cVar1 < 'e') {
          if (cVar1 == 'd') {
            uVar24 = 0;
            local_5e0 = 0;
            psVar17 = psVar14;
          }
          else {
            if (cVar1 == '4') {
              iVar6 = 2;
            }
            else {
              if (cVar1 != '6') {
                if (cVar1 == '?') {
                  pcVar15 = (char *)*pDVar8;
                  pcVar12 = 
                  "\nUsage: tracert [-p] [-d] [-h maximum_hops] [-j host-list] [-w timeout] \n               [-R] [-S srcaddr] [-4] [-6] target_name\n\nOptions:\n    -p                 Output to the debug window.\n    -d                 Do not resolve addresses to hostnames.\n    -h maximum_hops    Maximum number of hops to search for target.\n    -j host-list       Loose source route along host-list (IPv4-only).\n    -w timeout         Wait timeout milliseconds for each reply.\n    -R                 Trace round-trip path (IPv6-only).\n    -S srcaddr         Source address to use (IPv6-only).\n    -4                 Force using IPv4.\n    -6                 Force using IPv6.\n"
                  ;
                  goto LAB_00013298;
                }
                if (cVar1 == 'R') {
                  iVar6 = FUN_00012be0(&local_5d0,0x17,psVar17);
                  if (iVar6 != 0) {
                    local_5d8.Flags = local_5d8.Flags | 1;
                    goto LAB_00013170;
                  }
                  goto LAB_000132a0;
                }
                if (cVar1 != 'S') goto LAB_000131a8;
                iVar6 = FUN_00012be0(&local_5d0,0x17,psVar17);
                if (iVar6 == 0) goto LAB_000132a0;
                piVar18 = (int *)((int)piVar18 + 1);
                psVar17 = asStack_520;
                bVar5 = FUN_00012b40(local_5d0,pDVar8[(int)piVar18],psVar17);
                if (CONCAT31(extraout_var,bVar5) == 0) {
                  pcVar15 = (char *)pDVar8[(int)piVar18];
                  pcVar12 = "%hs is not a valid address.\n";
                  goto LAB_00013298;
                }
                goto LAB_00013170;
              }
              iVar6 = 0x17;
            }
            iVar6 = FUN_00012be0(&local_5d0,iVar6,psVar17);
LAB_0001315c:
            if (iVar6 == 0) goto LAB_000132a0;
          }
        }
        else {
          if (cVar1 == 'h') {
            psVar17 = param_1;
            param_4 = piVar18;
            iVar6 = FUN_00012928((ulong *)local_5b8,(int)pDVar8,(int)param_1,(int)piVar18,1,0xff);
LAB_00013158:
            piVar18 = (int *)((int)piVar18 + 1);
            goto LAB_0001315c;
          }
          if (cVar1 == 'j') {
            iVar6 = FUN_00012be0(&local_5d0,2,psVar17);
            pUVar4 = local_5d8.OptionsData;
            if (iVar6 == 0) goto LAB_000132a0;
            uVar25 = (uint)local_5d8.OptionsSize;
            if (0x28 < uVar25 + 7) {
LAB_000131e0:
              pcVar15 = "Too many options have been specified.\n";
              goto LAB_000131e8;
            }
            *(undefined1 *)((int)local_5d8.OptionsData + uVar25 + 1) = 3;
            local_5c8 = (short *)local_5d8.OptionsData;
            *(undefined1 *)(uVar25 + (int)local_5d8.OptionsData) = 0x83;
            *(undefined1 *)((int)local_5d8.OptionsData + uVar25 + 2) = 4;
            local_5d8.OptionsSize = local_5d8.OptionsSize + 3;
            if ((int)piVar18 < (int)(param_1 + -1)) {
              do {
                if (*(char *)pDVar23[1] == '-') break;
                if (0x28 < uVar25 + 7) goto LAB_000131e0;
                piVar18 = (int *)((int)piVar18 + 1);
                pDVar23 = pDVar8 + (int)piVar18;
                pcVar15 = (char *)*pDVar23;
                uVar11 = inet_addr(pcVar15);
                if (uVar11 == 0xffffffff) {
                  pcVar12 = "%hs is not a valid source route address.\n";
                  goto LAB_00013298;
                }
                *(ulong *)(*(byte *)((int)pUVar4 + uVar25 + 1) + uVar25 + (int)local_5c8) = uVar11;
                *(char *)((int)pUVar4 + uVar25 + 1) = *(char *)((int)pUVar4 + uVar25 + 1) + '\x04';
                local_5d8.OptionsSize = local_5d8.OptionsSize + 4;
              } while ((int)piVar18 < (int)(param_1 + -1));
            }
            bVar2 = *(byte *)((int)pUVar4 + uVar25 + 1);
            uVar24 = (uint)local_5e0;
            *(byte *)((int)pUVar4 + uVar25 + 1) = bVar2 + 4;
            local_5d8.OptionsSize = local_5d8.OptionsSize + 4;
            uVar25 = uVar25 + bVar2 & 0xff;
          }
          else {
            if (cVar1 != 'p') {
              if (cVar1 == 'w') {
                psVar17 = param_1;
                param_4 = piVar18;
                iVar6 = FUN_00012928((ulong *)&local_5c4,(int)pDVar8,(int)param_1,(int)piVar18,1,
                                     0xffffffff);
                goto LAB_00013158;
              }
LAB_000131a8:
              psVar17 = (short *)pDVar8[(int)piVar18];
              FUN_00012550(1,"%hs is not a valid command option.\n",psVar17,param_4);
              goto LAB_000131c4;
            }
            DAT_000140bc = 0;
            psVar17 = psVar14;
          }
        }
      }
      else {
        param_4 = &local_5cc;
        psVar14 = local_5a0;
        bVar3 = true;
        iVar6 = FUN_000129cc(local_5d0,(char *)psVar17,psVar14,param_4,local_430,0x401,(char)uVar24)
        ;
        psVar17 = psVar14;
        if (iVar6 == 0) {
          pcVar15 = (char *)pDVar8[(int)piVar18];
          pcVar12 = "Unable to resolve target system name %hs.\n";
          goto LAB_00013298;
        }
      }
LAB_00013170:
      piVar18 = (int *)((int)piVar18 + 1);
      psVar14 = psVar17;
      if ((int)param_1 <= (int)piVar18) goto code_r0x00013180;
      goto LAB_00012e28;
    }
    pcVar15 = (char *)0xfa0;
    psVar17 = psVar14;
    goto LAB_000131fc;
  }
  pcVar15 = (char *)*pDVar8;
  pcVar12 = 
  "\nUsage: tracert [-p] [-d] [-h maximum_hops] [-j host-list] [-w timeout] \n               [-R] [-S srcaddr] [-4] [-6] target_name\n\nOptions:\n    -p                 Output to the debug window.\n    -d                 Do not resolve addresses to hostnames.\n    -h maximum_hops    Maximum number of hops to search for target.\n    -j host-list       Loose source route along host-list (IPv4-only).\n    -w timeout         Wait timeout milliseconds for each reply.\n    -R                 Trace round-trip path (IPv6-only).\n    -S srcaddr         Source address to use (IPv6-only).\n    -4                 Force using IPv4.\n    -6                 Force using IPv6.\n"
  ;
LAB_00013298:
  FUN_00012550(1,pcVar12,pcVar15,param_4);
  goto LAB_000132a0;
code_r0x00013180:
  local_5c8 = local_5b8[0];
  local_5bc = local_5c4;
  pcVar15 = local_5c4;
  iVar6 = local_5cc;
  psVar22 = local_5b8[0];
LAB_000131fc:
  if (bVar3) {
    iVar19 = (int)local_5a0[0];
    local_5cc = iVar19;
    if (iVar19 == 2) {
      if (uVar25 != 0) {
        *(IPAddr *)(uVar25 + (int)local_5d8.OptionsData) = local_59c;
      }
      IcmpHandle = IcmpCreateFile();
    }
    else {
      IcmpHandle = (HANDLE)Icmp6CreateFile();
    }
    if (IcmpHandle != (HANDLE)0xffffffff) {
      getnameinfo(local_5a0,iVar6,asStack_4a0,0x41,0,0,2);
      if (local_430[0] == '\0') {
        psVar17 = asStack_4a0;
        psVar14 = psVar22;
        FUN_00012550(1,"\nTracing route to %hs over a maximum of %u hops\n\n",psVar17,psVar22);
      }
      else {
        psVar14 = asStack_4a0;
        psVar17 = (short *)local_430;
        FUN_00012550(1,"\nTracing route to %hs [%hs]\nover a maximum of %u hops:\n\n",psVar17,
                     psVar14);
      }
      psVar16 = (short *)(uint)local_5d8.Ttl;
      if (psVar16 <= psVar22) {
        pcVar12 = "\n";
        local_5c4 = "%3lu  ";
        while (psVar16 != (short *)0x0) {
          FUN_00012550(1,local_5c4,psVar16,psVar14);
          bVar3 = false;
          iVar6 = 0;
          do {
            bVar5 = false;
            psVar14 = (short *)0x0;
            psVar17 = (short *)0x0;
            uVar13 = 0;
            if (iVar19 == 2) {
              DVar7 = IcmpSendEcho2(IcmpHandle,(HANDLE)0x0,(FARPROC)0x0,(PVOID)0x0,local_59c,
                                    &DAT_00014180,0x40,&local_5d8,&DAT_00015360,0x84,(DWORD)pcVar15)
              ;
              psVar22 = DAT_00015364;
              if (DVar7 == 0) {
                psVar22 = (short *)GetLastError();
                puVar20 = (undefined4 *)0x0;
                if (psVar22 == (short *)0x2b02) {
                  FUN_00012550(1,"   *     ",psVar17,psVar14);
                  puVar21 = puVar20;
                  if (iVar6 == 2) {
                    if (bVar3) {
                      FUN_000127fc(local_5c0,(uint)local_5e0);
                      pcVar15 = pcVar12;
                    }
                    else {
                      pcVar15 = "Request timed out.\n";
                    }
                    FUN_00012550(1,pcVar15,psVar17,psVar14);
                  }
                }
                else {
LAB_000134f0:
                  bVar5 = true;
                  puVar21 = puVar20;
                }
              }
              else {
                puVar21 = &DAT_00015360;
                if (DAT_00015364 == (short *)0x0) {
                  FUN_000128e0(DAT_00015368,uVar13,psVar17,psVar14);
                  if (iVar6 == 2) {
                    FUN_000127fc(DAT_00015360,(uint)local_5e0);
                    goto LAB_000137ec;
                  }
                }
                else {
                  puVar20 = &DAT_00015360;
                  if (DAT_00015364 != (short *)0x2b05) goto LAB_000134f0;
                  FUN_000128e0(DAT_00015368,uVar13,psVar17,psVar14);
                  if (iVar6 == 2) {
                    FUN_000127fc(DAT_00015360,(uint)local_5e0);
                    FUN_00012550(1,"\n",psVar17,psVar14);
                    if (DAT_00015368 < 1000) {
                      Sleep(1000 - DAT_00015368);
                    }
                    goto LAB_000134f4;
                  }
                }
                bVar3 = true;
                local_5c0 = DAT_00015360;
                puVar21 = &DAT_00015360;
              }
LAB_000134f4:
              if (bVar5) {
                if ((short *)0x2af7 < psVar22) {
                  if (puVar21 != (undefined4 *)0x0) {
                    FUN_000127fc(*puVar21,(uint)local_5e0);
                    FUN_00012550(1," reports: ",psVar17,psVar14);
                  }
                  iVar6 = 0;
                  psVar16 = DAT_000140c0;
                  while ((psVar16 != psVar22 && (psVar16 != (short *)0x2b2a))) {
                    iVar6 = iVar6 + 1;
                    psVar16 = (&DAT_000140c0)[iVar6 * 2];
                  }
LAB_000137dc:
                  pcVar12 = (&PTR_s_General_failure__000140c4)[iVar6 * 2];
LAB_000137ec:
                  FUN_00012550(1,pcVar12,psVar17,psVar14);
                  goto LAB_000137f4;
                }
LAB_00013760:
                psVar17 = psVar22;
                FUN_00012550(1,"Transmit error: code %lu.\n",psVar17,psVar14);
                goto LAB_000137f4;
              }
            }
            else {
              iVar19 = Icmp6SendEcho2();
              psVar22 = DAT_0001537c;
              if (iVar19 == 0) {
                psVar22 = (short *)GetLastError();
                puVar20 = (undefined4 *)0x0;
                if (psVar22 == (short *)0x2b02) {
                  FUN_00012550(1,"   *     ",psVar17,psVar14);
                  puVar21 = puVar20;
                  if (iVar6 == 2) {
                    if (bVar3) {
                      FUN_00012868(auStack_5b0,(uint)local_5e0);
                      pcVar15 = pcVar12;
                    }
                    else {
                      pcVar15 = "Request timed out.\n";
                    }
                    FUN_00012550(1,pcVar15,psVar17,psVar14);
                  }
                }
                else {
LAB_000136dc:
                  bVar5 = true;
                  puVar21 = puVar20;
                }
              }
              else {
                puVar21 = &DAT_00015360;
                if (DAT_0001537c == (short *)0x0) {
                  FUN_000128e0(DAT_00015380,uVar13,psVar17,psVar14);
                  if (iVar6 == 2) {
                    FUN_00012868((void *)((int)&DAT_00015364 + 2),(uint)local_5e0);
                    goto LAB_000137ec;
                  }
                }
                else {
                  puVar20 = &DAT_00015360;
                  if (DAT_0001537c != (short *)0x2b05) goto LAB_000136dc;
                  FUN_000128e0(DAT_00015380,uVar13,psVar17,psVar14);
                  if (iVar6 == 2) {
                    FUN_00012868((void *)((int)&DAT_00015364 + 2),(uint)local_5e0);
                    FUN_00012550(1,"\n",psVar17,psVar14);
                    if (DAT_00015380 < 1000) {
                      Sleep(1000 - DAT_00015380);
                    }
                    goto LAB_000136e0;
                  }
                }
                psVar17 = (short *)0x10;
                bVar3 = true;
                memcpy(auStack_5b0,(void *)((int)&DAT_00015364 + 2),0x10);
                puVar21 = &DAT_00015360;
              }
LAB_000136e0:
              if (bVar5) {
                if (psVar22 < (short *)0x2af8) goto LAB_00013760;
                if (puVar21 != (undefined4 *)0x0) {
                  FUN_00012868((void *)((int)puVar21 + 6),(uint)local_5e0);
                  FUN_00012550(1," reports: ",psVar17,psVar14);
                }
                iVar6 = 0;
                psVar16 = DAT_000140c0;
                while ((psVar16 != psVar22 && (psVar16 != (short *)0x2b2a))) {
                  iVar6 = iVar6 + 1;
                  psVar16 = (&DAT_000140c0)[iVar6 * 2];
                }
                goto LAB_000137dc;
              }
            }
            iVar6 = iVar6 + 1;
            iVar19 = local_5cc;
            pcVar15 = local_5bc;
          } while (iVar6 < 3);
          local_5d8.Ttl = local_5d8.Ttl + 1;
          psVar16 = (short *)(uint)local_5d8.Ttl;
          if (local_5c8 < psVar16) break;
        }
      }
LAB_000137f4:
      FUN_00012550(1,"\nTrace complete.\n",psVar17,psVar14);
      IcmpCloseHandle(IcmpHandle);
      WSACleanup();
      FUN_00012260(local_2c);
      return 0;
    }
    pcVar15 = (char *)GetLastError();
    pcVar12 = "Unable to contact IP driver. Error code %d.\n";
    goto LAB_00013298;
  }
  FUN_00012550(1,"A target name or address must be specified.\n",psVar17,param_4);
LAB_000131c4:
  pcVar15 = 
  "\nUsage: tracert [-p] [-d] [-h maximum_hops] [-j host-list] [-w timeout] \n               [-R] [-S srcaddr] [-4] [-6] target_name\n\nOptions:\n    -p                 Output to the debug window.\n    -d                 Do not resolve addresses to hostnames.\n    -h maximum_hops    Maximum number of hops to search for target.\n    -j host-list       Loose source route along host-list (IPv4-only).\n    -w timeout         Wait timeout milliseconds for each reply.\n    -R                 Trace round-trip path (IPv6-only).\n    -S srcaddr         Source address to use (IPv6-only).\n    -4                 Force using IPv4.\n    -6                 Force using IPv6.\n"
  ;
LAB_000131e8:
  FUN_00012550(1,pcVar15,psVar17,param_4);
LAB_000132a0:
  WSACleanup();
LAB_00012d04:
  FUN_00012260(local_2c);
  return 1;
}


