/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011074 FUN_00011074 */

/* Boundary evidence: original MIPS .pdata 00011074..0001111f. Semantic name remains unreviewed. */

undefined4 FUN_00011074(void)

{
  HANDLE hDevice;
  undefined1 local_10 [8];
  
  hDevice = CreateFileW(L"MGR1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hDevice != (HANDLE)0xffffffff) {
    local_10[0] = 1;
    DeviceIoControl(hDevice,3,local_10,1,(LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  return 0;
}



/* 00011120 FUN_00011120 */

/* Boundary evidence: original MIPS .pdata 00011120..0001114b. Semantic name remains unreviewed. */

void FUN_00011120(void)

{
  if (DAT_00012068 != (void *)0x0) {
    free(DAT_00012068);
  }
  return;
}



/* 0001114c FUN_0001114c */

/* Boundary evidence: original MIPS .pdata 0001114c..000111db. Semantic name remains unreviewed. */

int FUN_0001114c(wint_t *param_1)

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



/* 000111dc FUN_000111dc */

/* Boundary evidence: original MIPS .pdata 000111dc..0001129f. Semantic name remains unreviewed. */

void FUN_000111dc(int *param_1,int *param_2,wint_t *param_3)

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
    iVar2 = FUN_0001114c(pwVar3);
    *param_2 = *param_2 + iVar2 + 1;
    param_3 = pwVar3 + iVar2;
    *param_1 = *param_1 + 1;
    if (*param_3 == 0) {
      return;
    }
  }
  return;
}



/* 000112a0 FUN_000112a0 */

/* Boundary evidence: original MIPS .pdata 000112a0..00011477. Semantic name remains unreviewed. */

undefined4 FUN_000112a0(wchar_t *param_1,wint_t *param_2,int *param_3,undefined4 *param_4)

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
    FUN_000111dc(&local_38,(int *)&local_34,param_2);
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
        iVar6 = FUN_0001114c(pwVar10);
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



/* 00011478 FUN_00011478 */

/* Boundary evidence: original MIPS .pdata 00011478..0001156f. Semantic name remains unreviewed. */

void FUN_00011478(HMODULE param_1,wint_t *param_2)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  int local_224;
  undefined4 local_220 [2];
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_0001205c;
  DAT_00012070 = param_1;
  DVar1 = GetModuleFileNameW(param_1,aWStack_218,0x100);
  if (DVar1 == 0) {
    FUN_0001172c(0xfffffffd);
  }
  FUN_00011a4c(FUN_00011120);
  FUN_000117cc();
  iVar2 = FUN_000112a0(aWStack_218,param_2,&local_224,local_220);
  if (iVar2 == 0) {
    FUN_0001172c(0xfffffffc);
  }
  DAT_0001206c = local_224;
  DAT_00012068 = local_220[0];
  UVar3 = FUN_00011074();
  FUN_0001170c(UVar3);
  FUN_0001172c(UVar3);
  FUN_00011b6c(local_18);
  return;
}



/* 00011570 FUN_00011570 */

/* Boundary evidence: original MIPS .pdata 00011570..000115af. Semantic name remains unreviewed. */

void FUN_00011570(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x228) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x228),param_1);
  return;
}



/* 000115b0 entry */

/* Boundary evidence: original MIPS .pdata 000115b0..000115eb. Semantic name remains unreviewed. */

void entry(HMODULE param_1,undefined4 param_2,wint_t *param_3)

{
  FUN_00011a7c();
  FUN_00011478(param_1,param_3);
  return;
}



/* 000115ec FUN_000115ec */

/* Boundary evidence: original MIPS .pdata 000115ec..0001170b. Semantic name remains unreviewed. */

void FUN_000115ec(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00012074 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_0001207c;
    if (DAT_0001207c != (undefined4 *)0x0) {
      while (DAT_00012078 = DAT_00012078 + -1, _Memory <= DAT_00012078) {
        if ((code *)*DAT_00012078 != (code *)0x0) {
          (*(code *)*DAT_00012078)();
          _Memory = DAT_0001207c;
        }
      }
      free(_Memory);
      DAT_00012078 = (undefined4 *)0x0;
      DAT_0001207c = (undefined4 *)0x0;
    }
    FUN_00011778((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_00011778((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_00012080,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 0001170c FUN_0001170c */

/* Boundary evidence: original MIPS .pdata 0001170c..0001172b. Semantic name remains unreviewed. */

void FUN_0001170c(UINT param_1)

{
  FUN_000115ec(param_1,0,0);
  return;
}



/* 0001172c FUN_0001172c */

/* Boundary evidence: original MIPS .pdata 0001172c..00011777. Semantic name remains unreviewed. */

void FUN_0001172c(UINT param_1)

{
  DAT_00012074 = 0;
  FUN_00011778((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00011778 FUN_00011778 */

/* Boundary evidence: original MIPS .pdata 00011778..000117cb. Semantic name remains unreviewed. */

void FUN_00011778(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 000117cc FUN_000117cc */

/* Boundary evidence: original MIPS .pdata 000117cc..00011807. Semantic name remains unreviewed. */

void FUN_000117cc(void)

{
  FUN_00011778((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_00011778((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00011808 FUN_00011808 */

/* Boundary evidence: original MIPS .pdata 00011808..00011913. Semantic name remains unreviewed. */

undefined4 FUN_00011808(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_0001207c;
  puVar3 = DAT_00012078;
  iVar4 = (int)DAT_00012078 - (int)DAT_0001207c;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_0001184c:
    param_1 = 0;
  }
  else {
    if (DAT_0001207c != (void *)0x0) {
      uVar1 = _msize(DAT_0001207c);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_000118c0:
        if (pvVar2 == (void *)0x0) goto LAB_0001184c;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_000118c0;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_00012078 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_0001207c = pvVar2;
  }
  return param_1;
}



/* 00011914 FUN_00011914 */

/* Boundary evidence: original MIPS .pdata 00011914..000119ff. Semantic name remains unreviewed. */

undefined4 FUN_00011914(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_00012080 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_00012080,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_00012080 == (LPCRITICAL_SECTION)0x0) goto LAB_000119b8;
  }
  EnterCriticalSection(DAT_00012080);
LAB_000119b8:
  uVar2 = FUN_00011808(param_1);
  FUN_00011a00();
  return uVar2;
}



/* 00011a00 FUN_00011a00 */

/* Boundary evidence: original MIPS .pdata 00011a00..00011a4b. Semantic name remains unreviewed. */

void FUN_00011a00(void)

{
  if (DAT_00012080 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_00012080);
  }
  return;
}



/* 00011a4c FUN_00011a4c */

/* Boundary evidence: original MIPS .pdata 00011a4c..00011a7b. Semantic name remains unreviewed. */

undefined4 FUN_00011a4c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00011914(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00011a7c FUN_00011a7c */

/* Boundary evidence: original MIPS .pdata 00011a7c..00011aef. Semantic name remains unreviewed. */

void FUN_00011a7c(void)

{
  uint uVar1;
  
  if ((DAT_0001205c == 0) || (DAT_0001205c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0001205c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0001205c == 0) {
      DAT_0001205c = 0xb064;
    }
  }
  DAT_00012060 = ~DAT_0001205c;
  return;
}



/* 00011af0 FUN_00011af0 */

/* Boundary evidence: original MIPS .pdata 00011af0..00011b6b. Semantic name remains unreviewed. */

void FUN_00011af0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_00011bb4(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 00011b6c FUN_00011b6c */

/* Boundary evidence: original MIPS .pdata 00011b6c..00011bb3. Semantic name remains unreviewed. */

void FUN_00011b6c(uint param_1)

{
  if ((param_1 == DAT_0001205c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00011bb4 FUN_00011bb4 */

/* Boundary evidence: original MIPS .pdata 00011bb4..00011c07. Semantic name remains unreviewed. */

void FUN_00011bb4(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00011b6c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}


