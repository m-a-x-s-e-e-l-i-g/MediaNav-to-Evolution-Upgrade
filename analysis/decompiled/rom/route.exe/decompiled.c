/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 000124c0 FUN_000124c0 */

/* Boundary evidence: original MIPS .pdata 000124c0..000124eb. Semantic name remains unreviewed. */

void FUN_000124c0(void)

{
  if (DAT_000150b0 != (void *)0x0) {
    free(DAT_000150b0);
  }
  return;
}



/* 000124ec FUN_000124ec */

/* Boundary evidence: original MIPS .pdata 000124ec..0001257b. Semantic name remains unreviewed. */

int FUN_000124ec(wint_t *param_1)

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



/* 0001257c FUN_0001257c */

/* Boundary evidence: original MIPS .pdata 0001257c..0001263f. Semantic name remains unreviewed. */

void FUN_0001257c(int *param_1,int *param_2,wint_t *param_3)

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
    iVar2 = FUN_000124ec(pwVar3);
    *param_2 = *param_2 + iVar2 + 1;
    param_3 = pwVar3 + iVar2;
    *param_1 = *param_1 + 1;
    if (*param_3 == 0) {
      return;
    }
  }
  return;
}



/* 00012640 FUN_00012640 */

/* Boundary evidence: original MIPS .pdata 00012640..00012817. Semantic name remains unreviewed. */

undefined4 FUN_00012640(wchar_t *param_1,wint_t *param_2,int *param_3,undefined4 *param_4)

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
    FUN_0001257c(&local_38,(int *)&local_34,param_2);
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
        iVar6 = FUN_000124ec(pwVar10);
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



/* 00012818 FUN_00012818 */

/* Boundary evidence: original MIPS .pdata 00012818..0001290f. Semantic name remains unreviewed. */

void FUN_00012818(HMODULE param_1,wint_t *param_2)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  int *piVar4;
  _union_1226 _Var5;
  int local_224;
  wchar_t *local_220 [2];
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_000150a8;
  DAT_000150b8 = param_1;
  DVar1 = GetModuleFileNameW(param_1,aWStack_218,0x100);
  if (DVar1 == 0) {
    FUN_00012acc(0xfffffffd);
  }
  FUN_00012dec(FUN_000124c0);
  FUN_00012b6c();
  _Var5.S_addr = (ULONG)local_220;
  piVar4 = &local_224;
  iVar2 = FUN_00012640(aWStack_218,param_2,piVar4,(undefined4 *)_Var5);
  if (iVar2 == 0) {
    FUN_00012acc(0xfffffffc);
  }
  DAT_000150b4 = local_224;
  DAT_000150b0 = local_220[0];
  UVar3 = FUN_00013fa8(local_224,local_220[0],piVar4,_Var5);
  FUN_00012aac(UVar3);
  FUN_00012acc(UVar3);
  FUN_00012f0c(local_18);
  return;
}



/* 00012910 FUN_00012910 */

/* Boundary evidence: original MIPS .pdata 00012910..0001294f. Semantic name remains unreviewed. */

void FUN_00012910(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x228) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x228),param_1);
  return;
}



/* 00012950 entry */

/* Boundary evidence: original MIPS .pdata 00012950..0001298b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,undefined4 param_2,wint_t *param_3)

{
  FUN_00012e1c();
  FUN_00012818(param_1,param_3);
  return;
}



/* 0001298c FUN_0001298c */

/* Boundary evidence: original MIPS .pdata 0001298c..00012aab. Semantic name remains unreviewed. */

void FUN_0001298c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_000150bc = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000150d0;
    if (DAT_000150d0 != (undefined4 *)0x0) {
      while (DAT_000150cc = DAT_000150cc + -1, _Memory <= DAT_000150cc) {
        if ((code *)*DAT_000150cc != (code *)0x0) {
          (*(code *)*DAT_000150cc)();
          _Memory = DAT_000150d0;
        }
      }
      free(_Memory);
      DAT_000150cc = (undefined4 *)0x0;
      DAT_000150d0 = (undefined4 *)0x0;
    }
    FUN_00012b18((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_00012b18((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_000150d4,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00012aac FUN_00012aac */

/* Boundary evidence: original MIPS .pdata 00012aac..00012acb. Semantic name remains unreviewed. */

void FUN_00012aac(UINT param_1)

{
  FUN_0001298c(param_1,0,0);
  return;
}



/* 00012acc FUN_00012acc */

/* Boundary evidence: original MIPS .pdata 00012acc..00012b17. Semantic name remains unreviewed. */

void FUN_00012acc(UINT param_1)

{
  DAT_000150bc = 0;
  FUN_00012b18((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00012b18 FUN_00012b18 */

/* Boundary evidence: original MIPS .pdata 00012b18..00012b6b. Semantic name remains unreviewed. */

void FUN_00012b18(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00012b6c FUN_00012b6c */

/* Boundary evidence: original MIPS .pdata 00012b6c..00012ba7. Semantic name remains unreviewed. */

void FUN_00012b6c(void)

{
  FUN_00012b18((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_00012b18((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00012ba8 FUN_00012ba8 */

/* Boundary evidence: original MIPS .pdata 00012ba8..00012cb3. Semantic name remains unreviewed. */

undefined4 FUN_00012ba8(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_000150d0;
  puVar3 = DAT_000150cc;
  iVar4 = (int)DAT_000150cc - (int)DAT_000150d0;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_00012bec:
    param_1 = 0;
  }
  else {
    if (DAT_000150d0 != (void *)0x0) {
      uVar1 = _msize(DAT_000150d0);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_00012c60:
        if (pvVar2 == (void *)0x0) goto LAB_00012bec;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_00012c60;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_000150cc = puVar3 + 1;
    *puVar3 = param_1;
    DAT_000150d0 = pvVar2;
  }
  return param_1;
}



/* 00012cb4 FUN_00012cb4 */

/* Boundary evidence: original MIPS .pdata 00012cb4..00012d9f. Semantic name remains unreviewed. */

undefined4 FUN_00012cb4(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_000150d4 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_000150d4,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_000150d4 == (LPCRITICAL_SECTION)0x0) goto LAB_00012d58;
  }
  EnterCriticalSection(DAT_000150d4);
LAB_00012d58:
  uVar2 = FUN_00012ba8(param_1);
  FUN_00012da0();
  return uVar2;
}



/* 00012da0 FUN_00012da0 */

/* Boundary evidence: original MIPS .pdata 00012da0..00012deb. Semantic name remains unreviewed. */

void FUN_00012da0(void)

{
  if (DAT_000150d4 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_000150d4);
  }
  return;
}



/* 00012dec FUN_00012dec */

/* Boundary evidence: original MIPS .pdata 00012dec..00012e1b. Semantic name remains unreviewed. */

undefined4 FUN_00012dec(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00012cb4(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00012e1c FUN_00012e1c */

/* Boundary evidence: original MIPS .pdata 00012e1c..00012e8f. Semantic name remains unreviewed. */

void FUN_00012e1c(void)

{
  uint uVar1;
  
  if ((DAT_000150a8 == 0) || (DAT_000150a8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000150a8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000150a8 == 0) {
      DAT_000150a8 = 0xb064;
    }
  }
  DAT_000150ac = ~DAT_000150a8;
  return;
}



/* 00012e90 FUN_00012e90 */

/* Boundary evidence: original MIPS .pdata 00012e90..00012f0b. Semantic name remains unreviewed. */

void FUN_00012e90(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_00012f54(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 00012f0c FUN_00012f0c */

/* Boundary evidence: original MIPS .pdata 00012f0c..00012f53. Semantic name remains unreviewed. */

void FUN_00012f0c(uint param_1)

{
  if ((param_1 == DAT_000150a8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00012f54 FUN_00012f54 */

/* Boundary evidence: original MIPS .pdata 00012f54..00012fa7. Semantic name remains unreviewed. */

void FUN_00012f54(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00012f0c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00012fa8 FUN_00012fa8 */

/* Boundary evidence: original MIPS .pdata 00012fa8..00012fd3. Semantic name remains unreviewed. */

undefined4 FUN_00012fa8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00012f54(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00013104 FUN_00013104 */

/* Boundary evidence: original MIPS .pdata 00013104..00013207. Semantic name remains unreviewed. */

int FUN_00013104(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  wchar_t awStack_218 [255];
  undefined2 local_1a;
  uint local_18;
  
  local_18 = DAT_000150a8;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  iVar1 = _vsnwprintf(awStack_218,0xff,param_1,(va_list)&local_res4);
  local_1a = 0;
  if (DAT_000150c4 == 0) {
    if (DAT_000150c8 == (code *)0x0) {
      DAT_000150c0 = LoadLibraryW(L"coredll.dll");
      if (DAT_000150c0 != (HMODULE)0x0) {
        DAT_000150c8 = (code *)GetProcAddressW(DAT_000150c0,L"wprintf");
      }
      if (DAT_000150c8 != (code *)0x0) goto LAB_000131bc;
      DAT_000150c4 = 1;
    }
    else {
LAB_000131bc:
      (*DAT_000150c8)(&UNK_0001103c,awStack_218);
    }
    if (DAT_000150c4 == 0) goto LAB_000131e4;
  }
  OutputDebugStringW(awStack_218);
LAB_000131e4:
  FUN_00012f0c(local_18);
  return iVar1;
}



/* 00013208 FUN_00013208 */

/* Boundary evidence: original MIPS .pdata 00013208..00013277. Semantic name remains unreviewed. */

void FUN_00013208(wchar_t *param_1,ulong *param_2)

{
  ulong uVar1;
  char local_28;
  undefined1 auStack_27 [15];
  uint local_18;
  
  local_18 = DAT_000150a8;
  local_28 = '\0';
  memset(auStack_27,0,0xf);
  wcstombs(&local_28,param_1,0x10);
  uVar1 = inet_addr(&local_28);
  *param_2 = uVar1;
  FUN_00012f0c(local_18);
  return;
}



/* 00013278 FUN_00013278 */

undefined4 FUN_00013278(short *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (*param_1 != 0) {
    do {
      sVar1 = param_1[iVar2];
      while ((sVar1 != 0x2e && (sVar1 != 0))) {
        iVar2 = iVar2 + 1;
        sVar1 = param_1[iVar2];
      }
      if (param_1[iVar2] == 0x2e) {
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 1;
      }
    } while (param_1[iVar2] != 0);
    if (iVar3 == 3) {
      return 1;
    }
  }
  return 0;
}



/* 00013310 FUN_00013310 */

/* Boundary evidence: original MIPS .pdata 00013310..0001337f. Semantic name remains unreviewed. */

void FUN_00013310(DWORD param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  HLOCAL local_10 [2];
  
  uVar2 = 0x400;
  uVar1 = 0;
  local_10[0] = (HLOCAL)0x0;
  FormatMessageW(0x1300,(LPCVOID)0x0,param_1,0x400,(LPWSTR)local_10,0,(va_list *)0x0);
  FUN_00013104(L" \n Error Message ....::  ",uVar1,param_1,uVar2);
  if (local_10[0] != (HLOCAL)0x0) {
    FUN_00013104(L"%ls \n ",local_10[0],param_1,uVar2);
    LocalFree(local_10[0]);
  }
  return;
}



/* 00013380 FUN_00013380 */

/* Boundary evidence: original MIPS .pdata 00013380..00013433. Semantic name remains unreviewed. */

undefined4 FUN_00013380(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  size_t *psVar2;
  void *_Memory;
  undefined4 uVar3;
  size_t local_18 [2];
  
  psVar2 = local_18;
  local_18[0] = 0;
  _Memory = (void *)0x0;
  DVar1 = GetAdaptersInfo(0);
  if (DVar1 == 0x6f) {
    _Memory = malloc(local_18[0]);
    if (_Memory == (void *)0x0) {
      FUN_00013104(L"\n Insufficient Memory",psVar2,param_3,param_4);
      FUN_00012aac(1);
    }
    DVar1 = GetAdaptersInfo(_Memory,local_18);
  }
  if (DVar1 != 0) {
    FUN_00013310(DVar1);
    FUN_00012aac(1);
  }
  uVar3 = 0;
  if (_Memory != (void *)0x0) {
    if (local_18[0] != 0) {
      uVar3 = *(undefined4 *)((int)_Memory + 0x19c);
    }
    free(_Memory);
  }
  return uVar3;
}



/* 00013434 FUN_00013434 */

/* Boundary evidence: original MIPS .pdata 00013434..0001361b. Semantic name remains unreviewed. */

void FUN_00013434(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  DWORD DVar1;
  int iVar2;
  size_t *psVar3;
  undefined4 *_Memory;
  undefined4 *puVar4;
  char *_Dest;
  uint uVar5;
  size_t local_140;
  char *local_13c;
  undefined4 *local_138;
  size_t asStack_130 [65];
  uint local_2c;
  
  local_2c = DAT_000150a8;
  psVar3 = &local_140;
  _Memory = (undefined4 *)0x0;
  local_140 = 0;
  DVar1 = GetAdaptersInfo(0);
  if (DVar1 == 0x6f) {
    _Memory = malloc(local_140);
    if (_Memory == (undefined4 *)0x0) {
      FUN_00013104(L"\n Insufficient Memory",psVar3,param_3,param_4);
      FUN_00012aac(1);
    }
    psVar3 = &local_140;
    DVar1 = GetAdaptersInfo(_Memory);
  }
  if (DVar1 != 0) {
    FUN_00013310(DVar1);
    FUN_00012aac(1);
  }
  puVar4 = _Memory;
  if (local_140 == 0) {
    puVar4 = (undefined4 *)0x0;
  }
  local_138 = _Memory;
  FUN_00013104(L"=============================================================================\n",
               psVar3,param_3,param_4);
  FUN_00013104(L"Interface List\n",psVar3,param_3,param_4);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_00013104(L"No Interfaces Present.\n",psVar3,param_3,param_4);
  }
  else {
    local_13c = " %02x";
    do {
      iVar2 = sprintf((char *)asStack_130," %#8x ",puVar4[0x67]);
      _Dest = (char *)((int)asStack_130 + iVar2);
      uVar5 = 0;
      if (puVar4[100] != 0) {
        do {
          iVar2 = sprintf(_Dest," %02x",(uint)*(byte *)((int)puVar4 + uVar5 + 0x194));
          uVar5 = uVar5 + 1;
          _Dest = _Dest + iVar2;
        } while (uVar5 < (uint)puVar4[100]);
      }
      param_3 = puVar4 + 0x43;
      sprintf(_Dest,"\t %s\n");
      psVar3 = asStack_130;
      FUN_00013104(L"%hs",psVar3,param_3,param_4);
      puVar4 = (undefined4 *)*puVar4;
      _Memory = local_138;
    } while (puVar4 != (undefined4 *)0x0);
  }
  FUN_00013104(L"=============================================================================\n",
               psVar3,param_3,param_4);
  if (_Memory != (undefined4 *)0x0) {
    free(_Memory);
  }
  FUN_00012f0c(local_2c);
  return;
}



/* 0001361c FUN_0001361c */

/* Boundary evidence: original MIPS .pdata 0001361c..0001372b. Semantic name remains unreviewed. */

uint FUN_0001361c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint *_Dst;
  DWORD DVar2;
  size_t *psVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  size_t local_18 [2];
  
  uVar4 = 1;
  psVar3 = local_18;
  local_18[0] = 0;
  iVar1 = GetIpAddrTable(0);
  if (iVar1 == 0x7a) {
    _Dst = malloc(local_18[0]);
    if (_Dst == (uint *)0x0) {
      FUN_00013104(L"\n Insufficient Memory",psVar3,uVar4,param_4);
      FUN_00012aac(1);
    }
    memset(_Dst,0,local_18[0]);
    DVar2 = GetIpAddrTable(_Dst,local_18,1);
    if (DVar2 != 0) {
      FUN_00013310(DVar2);
      free(_Dst);
      FUN_00012aac(1);
    }
    uVar6 = 0;
    if (*_Dst != 0) {
      puVar5 = _Dst + 2;
      do {
        if (*puVar5 == param_1) {
          uVar6 = _Dst[uVar6 * 6 + 1];
          free(_Dst);
          return uVar6;
        }
        uVar6 = uVar6 + 1;
        puVar5 = puVar5 + 6;
      } while (uVar6 < *_Dst);
    }
    free(_Dst);
  }
  return 0;
}



/* 0001372c FUN_0001372c */

/* Boundary evidence: original MIPS .pdata 0001372c..00013a27. Semantic name remains unreviewed. */

void FUN_0001372c(wchar_t *param_1,undefined4 param_2,undefined4 param_3,_union_1226 param_4)

{
  bool bVar1;
  _struct_1227 _Var2;
  int iVar3;
  DWORD DVar4;
  int iVar5;
  in_addr in;
  wchar_t *pwVar6;
  size_t *psVar7;
  char *pcVar8;
  uint uVar9;
  char *pcVar10;
  _struct_1227 in_00;
  char *_Dest;
  uint *_Memory;
  _struct_1227 _Var11;
  _union_1226 *p_Var12;
  uint uVar13;
  _struct_1227 local_140;
  size_t local_13c;
  wchar_t *local_138;
  char acStack_130 [260];
  uint local_2c;
  
  local_2c = DAT_000150a8;
  _Var11.s_b1 = '\0';
  _Var11.s_b2 = '\0';
  _Var11.s_b3 = '\0';
  _Var11.s_b4 = '\0';
  local_140.s_b1 = '\0';
  local_140.s_b2 = '\0';
  local_140.s_b3 = '\0';
  local_140.s_b4 = '\0';
  _Memory = (uint *)0x0;
  local_13c = 0;
  iVar3 = _wcsicmp(param_1,L"");
  if (iVar3 != 0) {
    FUN_00013208(param_1,(ulong *)&local_140);
    _Var11 = local_140;
  }
  pcVar10 = (char *)0x0;
  psVar7 = &local_13c;
  DVar4 = GetIpForwardTable(0);
  if (DVar4 == 0x7a) {
    _Memory = malloc(local_13c);
    if (_Memory == (uint *)0x0) {
      FUN_00013104(L" Insufficient Memory\n",psVar7,pcVar10,param_4);
      FUN_00012aac(1);
    }
    pcVar10 = (char *)0x0;
    DVar4 = GetIpForwardTable(_Memory,&local_13c);
  }
  if (DVar4 != 0) {
    FUN_00013310(DVar4);
    FUN_00012aac(1);
  }
  pwVar6 = param_1;
  pcVar8 = "";
  iVar3 = _wcsicmp(param_1,L"");
  local_140 = (_struct_1227)0x114f0;
  local_138 = L"=============================================================================\n";
  bVar1 = iVar3 == 0;
  if (bVar1) {
    FUN_00013434(pwVar6,pcVar8,(undefined4 *)pcVar10,param_4);
    FUN_00013104(L"=============================================================================\n",
                 pcVar8,pcVar10,param_4);
    FUN_00013104(L" Active Routes\n",pcVar8,pcVar10,param_4);
    pcVar8 = (char *)*_Memory;
    FUN_00013104(L" The no. of entries is ::: %lu\n",pcVar8,pcVar10,param_4);
    FUN_00013104(L"      Destination       Netmask       GatewayAddress     Interface    Metric\n",
                 pcVar8,pcVar10,param_4);
    FUN_00013104(L" ----------------------------------------------------------------------------",
                 pcVar8,pcVar10,param_4);
  }
  _Var2 = local_140;
  uVar13 = 0;
  pwVar6 = L"=============================================================================\n";
  if (*_Memory != 0) {
    p_Var12 = (_union_1226 *)(_Memory + 4);
    do {
      in_00 = p_Var12[-3].S_un_b;
      pwVar6 = param_1;
      pcVar8 = "";
      iVar3 = _wcsicmp(param_1,L"");
      if ((iVar3 == 0) || (_Var11 == in_00)) {
        if ((!bVar1) && (_Var11 == in_00)) {
          bVar1 = true;
          FUN_00013434(pwVar6,pcVar8,(undefined4 *)pcVar10,param_4);
          uVar9 = *_Memory;
          FUN_00013104((wchar_t *)_Var2,uVar9,pcVar10,param_4);
          FUN_00013104(L"      Destination       Netmask       GatewayAddress     Interface    Metric \n"
                       ,uVar9,pcVar10,param_4);
          FUN_00013104(L" ----------------------------------------------------------------------------\n"
                       ,uVar9,pcVar10,param_4);
        }
        pcVar10 = inet_ntoa((in_addr)in_00);
        iVar3 = sprintf(acStack_130," %16s",pcVar10);
        _Dest = acStack_130 + iVar3;
        pcVar10 = inet_ntoa((in_addr)p_Var12[-2].S_un_b);
        iVar3 = sprintf(_Dest," %16s",pcVar10);
        pcVar10 = inet_ntoa((in_addr)p_Var12->S_un_b);
        pcVar8 = " %16s";
        iVar5 = sprintf(_Dest + iVar3," %16s");
        in.S_un = (_union_1226)FUN_0001361c(p_Var12[1].S_addr,pcVar8,pcVar10,param_4);
        pcVar10 = inet_ntoa(in);
        param_4 = p_Var12[6];
        sprintf(_Dest + iVar3 + iVar5," %16hs %7u");
        pcVar8 = acStack_130;
        FUN_00013104(L"%hs\n",pcVar8,pcVar10,param_4);
      }
      uVar13 = uVar13 + 1;
      p_Var12 = p_Var12 + 0xe;
      pwVar6 = local_138;
    } while (uVar13 < *_Memory);
  }
  if (bVar1) {
    FUN_00013104(pwVar6,pcVar8,pcVar10,param_4);
  }
  else {
    FUN_00013104(L" No entry found in the routing table\n",pcVar8,pcVar10,param_4);
  }
  free(_Memory);
  FUN_00012f0c(local_2c);
  return;
}



/* 00013a28 FUN_00013a28 */

/* Boundary evidence: original MIPS .pdata 00013a28..00013b53. Semantic name remains unreviewed. */

void FUN_00013a28(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,int param_4,undefined4 param_5)

{
  DWORD DVar1;
  wchar_t *pwVar2;
  ulong *puVar3;
  wchar_t *pwVar4;
  int iVar5;
  ulong local_50 [2];
  ulong local_48;
  ulong local_44;
  undefined4 local_40;
  ulong local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  pwVar4 = param_3;
  iVar5 = param_4;
  FUN_00013208(param_1,local_50);
  local_48 = local_50[0];
  FUN_00013208(param_2,local_50);
  puVar3 = local_50;
  local_44 = local_50[0];
  local_40 = 0;
  FUN_00013208(param_3,puVar3);
  local_3c = local_50[0];
  if (param_4 == 0) {
    param_4 = FUN_00013380(local_50[0],puVar3,pwVar4,iVar5);
  }
  local_34 = 3;
  local_30 = 3;
  local_2c = 0;
  local_28 = 0;
  local_24 = param_5;
  local_20 = 0xffffffff;
  local_1c = 0xffffffff;
  local_18 = 0xffffffff;
  local_14 = 0xffffffff;
  local_38 = param_4;
  DVar1 = CreateIpForwardEntry(&local_48);
  if (DVar1 == 0) {
    pwVar2 = L" \n Entry added successfully \n";
  }
  else {
    if (DVar1 != 0x57) {
      if (DVar1 == 0x32) {
        FUN_00013104(L"\nCreateIpForwardEntry not supported\n",puVar3,pwVar4,iVar5);
        return;
      }
      FUN_00013310(DVar1);
      FUN_00012aac(1);
      return;
    }
    pwVar2 = L" \nCreateIpForwardEntry failed: Invalid Parameter\n";
  }
  FUN_00013104(pwVar2,puVar3,pwVar4,iVar5);
  return;
}



/* 00013b54 FUN_00013b54 */

/* Boundary evidence: original MIPS .pdata 00013b54..00013d13. Semantic name remains unreviewed. */

void FUN_00013b54(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  uint *_Dst;
  DWORD DVar3;
  size_t *psVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  undefined *puVar8;
  uint uVar9;
  size_t local_28;
  ulong local_24;
  
  puVar8 = &DAT_0001155c;
  local_24 = 0;
  local_28 = 0;
  bVar1 = false;
  iVar2 = _wcsicmp(param_1,L"");
  uVar6 = 0;
  if (iVar2 != 0) {
    FUN_00013208(param_1,&local_24);
    uVar6 = local_24;
  }
  uVar5 = 0;
  psVar4 = &local_28;
  iVar2 = GetIpForwardTable(0);
  if (iVar2 != 0x7a) {
    return;
  }
  _Dst = malloc(local_28);
  if (_Dst == (uint *)0x0) {
    FUN_00013104(L"\n Insufficient Memory",psVar4,uVar5,param_4);
    FUN_00012aac(1);
  }
  memset(_Dst,0,local_28);
  uVar5 = 0;
  DVar3 = GetIpForwardTable(_Dst,&local_28);
  if (DVar3 != 0) {
    FUN_00013310(DVar3);
    FUN_00012aac(1);
  }
  iVar2 = _wcsicmp(param_1,L"");
  if (iVar2 == 0) {
    uVar6 = 0;
    if (*_Dst != 0) {
      puVar7 = _Dst + 1;
      do {
        DeleteIpForwardEntry(puVar7);
        uVar6 = uVar6 + 1;
        puVar7 = puVar7 + 0xe;
      } while (uVar6 < *_Dst);
    }
  }
  else {
    uVar9 = 0;
    if (*_Dst != 0) {
      puVar7 = _Dst + 1;
      do {
        if (*puVar7 == uVar6) {
          bVar1 = true;
          DVar3 = DeleteIpForwardEntry(puVar7);
          if (DVar3 == 0) {
            FUN_00013104(L" \n Deletion Successful!!!\n\n",puVar8,uVar5,param_4);
          }
          else {
            FUN_00013310(DVar3);
          }
        }
        uVar9 = uVar9 + 1;
        puVar7 = puVar7 + 0xe;
      } while (uVar9 < *_Dst);
      if (bVar1) goto LAB_00013ce8;
    }
    FUN_00013104(L" \n Destination specified is not in table.\n\n",puVar8,uVar5,param_4);
  }
LAB_00013ce8:
  free(_Dst);
  return;
}



/* 00013d14 FUN_00013d14 */

/* Boundary evidence: original MIPS .pdata 00013d14..00013f07. Semantic name remains unreviewed. */

void FUN_00013d14(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uint param_5)

{
  bool bVar1;
  DWORD DVar2;
  wchar_t *pwVar3;
  size_t *psVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint *_Memory;
  uint local_38;
  uint local_34;
  size_t local_30;
  uint local_2c;
  
  local_30 = 0;
  bVar1 = false;
  _Memory = (uint *)0x0;
  uVar6 = param_4;
  FUN_00013208(param_1,&local_2c);
  FUN_00013208(param_2,&local_38);
  FUN_00013208(param_3,&local_34);
  uVar5 = 0;
  psVar4 = &local_30;
  DVar2 = GetIpForwardTable(0);
  if ((DVar2 == 0x6f) || (DVar2 == 0x7a)) {
    _Memory = malloc(local_30);
    if (_Memory == (uint *)0x0) {
      FUN_00013104(L"\n Insufficient Memory",psVar4,uVar5,uVar6);
      FUN_00012aac(1);
    }
    uVar5 = 0;
    psVar4 = &local_30;
    DVar2 = GetIpForwardTable(_Memory);
  }
  if (DVar2 != 0) {
    FUN_00013310(DVar2);
    FUN_00012aac(1);
  }
  uVar10 = 0;
  if (*_Memory != 0) {
    puVar9 = _Memory + 4;
    uVar7 = local_38;
    uVar8 = local_34;
    do {
      if (((puVar9[-3] == local_2c) && (puVar9[-2] == uVar7)) &&
         (uVar7 = local_38, *puVar9 == uVar8)) {
        bVar1 = true;
        if (param_5 != 0) {
          puVar9[6] = param_5;
        }
        if (param_4 != 0) {
          puVar9[1] = param_4;
        }
        DVar2 = SetIpForwardEntry();
        pwVar3 = L" \n Entry changed successfully !!\n";
        if ((DVar2 == 0) || (pwVar3 = L" \n INVALID PARAMETERS ", DVar2 == 0x57)) {
          FUN_00013104(pwVar3,psVar4,uVar5,uVar6);
          uVar7 = local_38;
          uVar8 = local_34;
        }
        else {
          FUN_00013310(DVar2);
          uVar7 = local_38;
          uVar8 = local_34;
        }
      }
      uVar10 = uVar10 + 1;
      puVar9 = puVar9 + 0xe;
    } while (uVar10 < *_Memory);
    if (bVar1) goto LAB_00013ed0;
  }
  FUN_00013104(L" \n No matching entry found\n",psVar4,uVar5,uVar6);
LAB_00013ed0:
  free(_Memory);
  return;
}



/* 00013f08 FUN_00013f08 */

/* Boundary evidence: original MIPS .pdata 00013f08..00013fa7. Semantic name remains unreviewed. */

void FUN_00013f08(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00013104(L"\n\n Route Information \n",param_2,param_3,param_4);
  FUN_00013104(L" \n Manipulates Network Routing Tables \n",param_2,param_3,param_4);
  FUN_00013104(L" \n ROUTE  [-d] [-f] command [destination] [MASK netmask]  [gateway] [METRIC metric]  [IF interface]"
               ,param_2,param_3,param_4);
  FUN_00013104(L"\n\n   -f   Clears the routing tables of all gateway entries.  If this is used in \n conjunction with one of the commands, the tables are cleared prior to running \n the command."
               ,param_2,param_3,param_4);
  FUN_00013104(L"\n\n   -d   Redirects the output to the Output debug port ",param_2,param_3,param_4
              );
  FUN_00013104(L"\n\n command      One of these: ",param_2,param_3,param_4);
  FUN_00013104(L"\n\t\t PRINT     Prints  a route  \n\t\t ADD       Adds    a route \n\t\t DELETE    Deletes a route \n\t\t CHANGE    Modifies an existing route \n\n destination  Specifies the host."
               ,param_2,param_3,param_4);
  FUN_00013104(L" \n MASK         Specifies that the next parameter is the \'netmask\' value. \n netmask      Specifies a subnet mask value for this route entry. If not \n\t      specified, it defaults to 255.255.255.255."
               ,param_2,param_3,param_4);
  FUN_00013104(L" \n gateway      Specifies gateway \n interface    The interface number for the specified route. \n METRIC       specifies the metric, ie. cost for the destination."
               ,param_2,param_3,param_4);
  FUN_00013104(L"\n\n Diagnostic Notes: \n Invalid MASK generates an error, that is when (DEST & MASK) != DEST.\n Example\n     >route ADD 157.0.0.0 MASK 255.0.0.0 157.55.80.1 IF 1 \n The route addition failed: 87"
               ,param_2,param_3,param_4);
  FUN_00013104(L"\n Examples: \n     >route PRINT \n     >route ADD 157.0.0.0 MASK 255.0.0.0  157.55.80.1 METRIC 3 IF 2 \n If IF is not given, it tries to find the best interface for a given gateway. \n     >route DELETE 157.0.0.0  \n\n"
               ,param_2,param_3,param_4);
  FUN_00012aac(0);
  return;
}



/* 00013fa8 FUN_00013fa8 */

/* Boundary evidence: original MIPS .pdata 00013fa8..000144c3. Semantic name remains unreviewed. */

undefined4 FUN_00013fa8(int param_1,wchar_t *param_2,undefined4 param_3,_union_1226 param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_v1;
  wchar_t *_Str1;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  wchar_t *_Str1_00;
  int iVar9;
  int in_t7;
  wchar_t *pwVar10;
  int iVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  wchar_t *pwVar14;
  uint uVar15;
  uint uVar16;
  int in_t8;
  int in_t9;
  int local_34;
  
  pwVar14 = L"";
  bVar2 = false;
  bVar3 = false;
  bVar1 = false;
  iVar11 = 0;
  pwVar12 = (wchar_t *)0x0;
  pwVar13 = (wchar_t *)0x0;
  pwVar10 = (wchar_t *)0x0;
  uVar15 = 0;
  uVar16 = 0;
  _Str1 = pwVar14;
  pwVar8 = param_2;
  FUN_00013104(L"",param_2,param_3,param_4);
  local_34 = 1;
  if (param_1 == 1) {
    FUN_00013f08(_Str1,pwVar8,param_3,param_4);
  }
  if (param_1 < 2) {
LAB_0001448c:
    uVar5 = FUN_00013f08(_Str1,pwVar8,param_3,param_4);
    return uVar5;
  }
  do {
    pwVar7 = L"mask";
    pwVar6 = L"print";
    param_2 = param_2 + 2;
    _Str1_00 = *(wchar_t **)param_2;
    if ((*_Str1_00 == L'-') || (iVar9 = 0x2f, *_Str1_00 == L'/')) {
      _Str1 = (wchar_t *)(uint)(ushort)_Str1_00[1];
      iVar9 = toupper((int)_Str1);
      if (iVar9 == 0x3f) {
        FUN_00013f08(_Str1,pwVar8,param_3,param_4);
        goto LAB_0001448c;
      }
      if (iVar9 == 0x44) {
        DAT_000150c4 = 1;
      }
      else if (iVar9 == 0x46) {
        iVar11 = 5;
      }
    }
    else if (iVar11 == 0) {
      iVar4 = _wcsicmp(_Str1_00,L"print");
      if (iVar4 == 0) {
        iVar11 = 1;
        _Str1 = _Str1_00;
        pwVar8 = pwVar6;
      }
      else {
        pwVar8 = L"add";
        _Str1 = *(wchar_t **)param_2;
        iVar4 = _wcsicmp(_Str1,L"add");
        if (iVar4 == 0) {
          iVar11 = 2;
        }
        else {
          pwVar8 = L"delete";
          _Str1 = *(wchar_t **)param_2;
          iVar4 = _wcsicmp(_Str1,L"delete");
          if (iVar4 == 0) {
            iVar11 = 3;
          }
          else {
            pwVar8 = L"change";
            _Str1 = *(wchar_t **)param_2;
            iVar4 = _wcsicmp(_Str1,L"change");
            if (iVar4 != 0) {
              FUN_00013f08(_Str1,pwVar8,param_3,param_4);
              _Str1_00 = pwVar10;
              goto LAB_000142f8;
            }
            iVar11 = 4;
          }
        }
      }
    }
    else if (pwVar10 == (wchar_t *)0x0) {
      _Str1 = _Str1_00;
      iVar4 = FUN_00013278(_Str1_00);
      pwVar10 = _Str1_00;
      if (iVar4 == 0) {
LAB_000142f8:
        FUN_00013104(L"\n  Incorrect Parameter",pwVar8,param_3,param_4);
        FUN_00012aac(1);
        pwVar10 = _Str1_00;
LAB_0001430c:
        FUN_00013104(L" \n  Incorrect Parameter: Invalid mask",pwVar8,param_3,param_4);
        FUN_00012aac(1);
LAB_00014320:
        FUN_00013104(L"\n  Incorrect Parameter: Invalid interface",pwVar8,param_3,param_4);
        FUN_00012aac(1);
LAB_00014334:
        FUN_00013104(L"\n  Incorrect Parameters: Invalid metric",pwVar8,param_3,param_4);
        FUN_00012aac(1);
LAB_00014348:
        FUN_00013104(L"\n  Incorrect Parameters: Invalid gateway",pwVar8,param_3,param_4);
        FUN_00012aac(1);
LAB_0001435c:
        FUN_00013104(L"\n  Incorrect Parameters",pwVar8,param_3,param_4);
        _Str1 = (wchar_t *)0x1;
        FUN_00012aac(1);
        iVar4 = extraout_v1;
        break;
      }
    }
    else {
      iVar4 = _wcsicmp(_Str1_00,L"mask");
      if (iVar4 == 0) {
        bVar1 = true;
        _Str1 = _Str1_00;
        pwVar8 = pwVar7;
      }
      else {
        pwVar8 = L"metric";
        _Str1 = *(wchar_t **)param_2;
        iVar4 = _wcsicmp(_Str1,L"metric");
        if (iVar4 == 0) {
          bVar3 = true;
        }
        else {
          pwVar8 = L"if";
          _Str1 = *(wchar_t **)param_2;
          iVar4 = _wcsicmp(_Str1,L"if");
          if (iVar4 == 0) {
            bVar2 = true;
          }
          else if (bVar1) {
            pwVar13 = *(wchar_t **)param_2;
            bVar1 = false;
            _Str1 = pwVar13;
            iVar4 = FUN_00013278(pwVar13);
            if (iVar4 == 0) goto LAB_0001430c;
          }
          else if (bVar2) {
            _Str1 = *(wchar_t **)param_2;
            bVar2 = false;
            uVar16 = _wtol(_Str1);
            if (uVar16 == 0) goto LAB_00014320;
          }
          else if (bVar3) {
            _Str1 = *(wchar_t **)param_2;
            bVar3 = false;
            uVar15 = _wtol(_Str1);
            if (uVar15 == 0) goto LAB_00014334;
          }
          else {
            if (pwVar12 != (wchar_t *)0x0) goto LAB_0001435c;
            pwVar12 = *(wchar_t **)param_2;
            _Str1 = pwVar12;
            iVar4 = FUN_00013278(pwVar12);
            if (iVar4 == 0) goto LAB_00014348;
          }
        }
      }
    }
    in_t9 = 3;
    in_t8 = 2;
    in_t7 = 5;
    iVar9 = 1;
    iVar4 = 4;
    local_34 = local_34 + 1;
  } while (local_34 < param_1);
  if (iVar11 == iVar9) {
LAB_00014468:
    if (pwVar10 != (wchar_t *)0x0) {
      pwVar14 = pwVar10;
    }
    FUN_0001372c(pwVar14,pwVar8,param_3,param_4);
    return 0;
  }
  if (iVar11 == in_t8) {
    if (((pwVar10 != (wchar_t *)0x0) && (pwVar12 != (wchar_t *)0x0)) && (pwVar13 != (wchar_t *)0x0))
    {
      FUN_00013a28(pwVar10,pwVar13,pwVar12,uVar16,uVar15);
      return 0;
    }
    FUN_00013104(L"\n  Incorrect Parameters ",pwVar8,param_3,param_4);
    FUN_00012aac(1);
    goto LAB_00014468;
  }
  if (iVar11 != in_t9) {
    if (iVar11 != iVar4) {
      if (iVar11 != in_t7) goto LAB_0001448c;
      goto LAB_0001439c;
    }
    if (((pwVar10 != (wchar_t *)0x0) && (pwVar12 != (wchar_t *)0x0)) && (pwVar13 != (wchar_t *)0x0))
    {
      FUN_00013d14(pwVar10,pwVar13,pwVar12,uVar16,uVar15);
      return 0;
    }
    FUN_00013104(L"\n  Incorrect Parameters",pwVar8,param_3,param_4);
    FUN_00012aac(1);
  }
  pwVar14 = pwVar10;
  if (pwVar10 == (wchar_t *)0x0) {
    FUN_00013104(L"\n No destination Specified ",pwVar8,param_3,param_4);
    FUN_00012aac(1);
  }
LAB_0001439c:
  FUN_00013b54(pwVar14,pwVar8,param_3,param_4);
  return 0;
}


