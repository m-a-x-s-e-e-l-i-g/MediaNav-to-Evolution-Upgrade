/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011344 FUN_00011344 */

/* Boundary evidence: original MIPS .pdata 00011344..000113d7. Semantic name remains unreviewed. */

void FUN_00011344(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  UINT UVar1;
  
  FUN_00011654();
  UVar1 = FUN_00011744(param_1,param_2,param_3);
  FUN_00011594(UVar1);
  FUN_000115b4(UVar1);
  return;
}



/* 000113d8 FUN_000113d8 */

/* Boundary evidence: original MIPS .pdata 000113d8..00011417. Semantic name remains unreviewed. */

void FUN_000113d8(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00011418 entry */

/* Boundary evidence: original MIPS .pdata 00011418..00011473. Semantic name remains unreviewed. */

void entry(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00011690();
  FUN_00011344(param_1,param_2,param_3);
  return;
}



/* 00011474 FUN_00011474 */

/* Boundary evidence: original MIPS .pdata 00011474..00011593. Semantic name remains unreviewed. */

void FUN_00011474(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_000150ac = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000150c4;
    if (DAT_000150c4 != (undefined4 *)0x0) {
      while (DAT_000150c0 = DAT_000150c0 + -1, _Memory <= DAT_000150c0) {
        if ((code *)*DAT_000150c0 != (code *)0x0) {
          (*(code *)*DAT_000150c0)();
          _Memory = DAT_000150c4;
        }
      }
      free(_Memory);
      DAT_000150c0 = (undefined4 *)0x0;
      DAT_000150c4 = (undefined4 *)0x0;
    }
    FUN_00011600((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_00011600((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_000150c8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011594 FUN_00011594 */

/* Boundary evidence: original MIPS .pdata 00011594..000115b3. Semantic name remains unreviewed. */

void FUN_00011594(UINT param_1)

{
  FUN_00011474(param_1,0,0);
  return;
}



/* 000115b4 FUN_000115b4 */

/* Boundary evidence: original MIPS .pdata 000115b4..000115ff. Semantic name remains unreviewed. */

void FUN_000115b4(UINT param_1)

{
  DAT_000150ac = 0;
  FUN_00011600((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00011600 FUN_00011600 */

/* Boundary evidence: original MIPS .pdata 00011600..00011653. Semantic name remains unreviewed. */

void FUN_00011600(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00011654 FUN_00011654 */

/* Boundary evidence: original MIPS .pdata 00011654..0001168f. Semantic name remains unreviewed. */

void FUN_00011654(void)

{
  FUN_00011600((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_00011600((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00011690 FUN_00011690 */

/* Boundary evidence: original MIPS .pdata 00011690..00011703. Semantic name remains unreviewed. */

void FUN_00011690(void)

{
  uint uVar1;
  
  if ((DAT_0001509c == 0) || (DAT_0001509c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0001509c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0001509c == 0) {
      DAT_0001509c = 0xb064;
    }
  }
  DAT_000150a0 = ~DAT_0001509c;
  return;
}



/* 00011744 FUN_00011744 */

/* Boundary evidence: original MIPS .pdata 00011744..0001177b. Semantic name remains unreviewed. */

undefined4 FUN_00011744(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_00012894(param_3);
  if (iVar1 != 0) {
    FUN_00011858(0xffffffff);
  }
  FUN_00012a5c();
  return 0xffffffff;
}



/* 0001177c FUN_0001177c */

/* Boundary evidence: original MIPS .pdata 0001177c..000117c7. Semantic name remains unreviewed. */

undefined4 * FUN_0001177c(void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x27c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_00012c00(puVar1,param_1,0);
  }
  return puVar1;
}



/* 000117c8 FUN_000117c8 */

/* Boundary evidence: original MIPS .pdata 000117c8..00011823. Semantic name remains unreviewed. */

LONG FUN_000117c8(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 < 1) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(param_1,1);
  }
  return LVar1;
}



/* 00011824 FUN_00011824 */

/* Boundary evidence: original MIPS .pdata 00011824..0001184f. Semantic name remains unreviewed. */

undefined4 FUN_00011824(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[0x9d] = 0xffffffff;
    FUN_000117c8(param_1);
  }
  return 1;
}



/* 00011850 FUN_00011850 */

undefined4 FUN_00011850(void)

{
  return 0;
}



/* 00011858 FUN_00011858 */

/* Boundary evidence: original MIPS .pdata 00011858..00011887. Semantic name remains unreviewed. */

void FUN_00011858(DWORD param_1)

{
  WaitForSingleObject(DAT_000150b8,param_1);
  return;
}



/* 00011888 FUN_00011888 */

/* Boundary evidence: original MIPS .pdata 00011888..00011937. Semantic name remains unreviewed. */

int * FUN_00011888(void *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined3 extraout_var;
  
  if (DAT_000150bc != (LPCRITICAL_SECTION)0x0) {
    piVar2 = FUN_0001177c(param_1);
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar3 = (**(code **)(*piVar2 + 4))(piVar2);
    if (iVar3 == 0) {
      (**(code **)*piVar2)(piVar2,1);
      piVar2 = (int *)0x0;
    }
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    bVar1 = FUN_00014134(DAT_000150bc,(ULONG_PTR)piVar2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      return piVar2;
    }
    (**(code **)*piVar2)(piVar2,1);
  }
  return (int *)0x0;
}



/* 00011938 FUN_00011938 */

/* Boundary evidence: original MIPS .pdata 00011938..000119af. Semantic name remains unreviewed. */

undefined4 FUN_00011938(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_00013c50(DAT_000150bc,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,param_1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 000119b0 FUN_000119b0 */

/* Boundary evidence: original MIPS .pdata 000119b0..00011a27. Semantic name remains unreviewed. */

undefined4 FUN_000119b0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_00013c50(DAT_000150bc,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,param_1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 00011a28 FUN_00011a28 */

/* Boundary evidence: original MIPS .pdata 00011a28..00011a9f. Semantic name remains unreviewed. */

undefined4 FUN_00011a28(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_00013c50(DAT_000150bc,*(undefined4 *)(param_1 + 4)), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,param_1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 00011aa0 FUN_00011aa0 */

/* Boundary evidence: original MIPS .pdata 00011aa0..00011b17. Semantic name remains unreviewed. */

undefined4 FUN_00011aa0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_00013c50(DAT_000150bc,*(undefined4 *)(param_1 + 4)), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x34))(piVar1,param_1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 00011b18 FUN_00011b18 */

/* Boundary evidence: original MIPS .pdata 00011b18..00011b8f. Semantic name remains unreviewed. */

undefined4 FUN_00011b18(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_00013c50(DAT_000150bc,*(undefined4 *)(param_1 + 4)), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x38))(piVar1,param_1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 00011b90 FUN_00011b90 */

/* Boundary evidence: original MIPS .pdata 00011b90..00011c07. Semantic name remains unreviewed. */

undefined4 FUN_00011b90(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_00013c50(DAT_000150bc,*(undefined4 *)(param_1 + 4)), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x3c))(piVar1,param_1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 00011c08 FUN_00011c08 */

/* Boundary evidence: original MIPS .pdata 00011c08..00011f83. Semantic name remains unreviewed. */

int FUN_00011c08(int *param_1,uint param_2,undefined4 *param_3,uint param_4,int *param_5,
                uint param_6,undefined4 *param_7)

{
  bool bVar1;
  DWORD dwErrCode;
  int iVar2;
  undefined3 extraout_var;
  DWORD DVar3;
  code *pcVar4;
  int iVar5;
  
  dwErrCode = GetLastError();
  SetLastError(0x57);
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_2 < 0x109001d) {
    if (param_2 == 0x109001c) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 4) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x20);
LAB_00011f18:
      param_3 = (undefined4 *)*param_3;
      goto LAB_00011f1c;
    }
    if (param_2 == 0x1090004) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 0x218) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 8);
      goto LAB_00011f1c;
    }
    if (param_2 == 0x1090008) {
      pcVar4 = *(code **)(*param_1 + 0xc);
    }
    else if (param_2 == 0x109000c) {
      pcVar4 = *(code **)(*param_1 + 0x10);
    }
    else if (param_2 == 0x1090010) {
      pcVar4 = *(code **)(*param_1 + 0x14);
    }
    else {
      if (param_2 != 0x1090014) {
        if (param_2 != 0x1090018) {
          return 0;
        }
        if (param_3 == (undefined4 *)0x0) {
          return 0;
        }
        if (param_4 < 0x10) {
          return 0;
        }
        if (param_5 == (int *)0x0) {
          return 0;
        }
        if (param_6 < 4) {
          return 0;
        }
        iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,param_3);
        if (iVar2 == 0) {
          return 0;
        }
        iVar5 = 1;
        *param_5 = iVar2;
        if (param_7 != (undefined4 *)0x0) {
          *param_7 = 4;
        }
        goto LAB_00011f30;
      }
      pcVar4 = *(code **)(*param_1 + 0x18);
    }
    iVar5 = (*pcVar4)(param_1);
  }
  else {
    if (param_2 == 0x1090020) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 4) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x2c);
      goto LAB_00011f18;
    }
    if (param_2 == 0x1090024) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 0x14) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x30);
    }
    else if (param_2 == 0x1090028) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 0x14) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x34);
    }
    else if (param_2 == 0x109002c) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 0x14) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x38);
    }
    else {
      if (param_2 != 0x1090030) {
        if (param_2 != 0x1090404) {
          return 0;
        }
        if ((HANDLE)param_1[0x9d] != (HANDLE)0xffffffff) {
          CloseHandle((HANDLE)param_1[0x9d]);
          param_1[0x9d] = -1;
        }
        if (DAT_000150bc == (LPCRITICAL_SECTION)0x0) {
          iVar5 = 0;
        }
        else {
          bVar1 = FUN_0001416c(DAT_000150bc,param_1);
          iVar5 = CONCAT31(extraout_var,bVar1);
        }
        goto LAB_00011f28;
      }
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 0x24) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x3c);
    }
LAB_00011f1c:
    iVar5 = (*pcVar4)(param_1,param_3);
  }
LAB_00011f28:
  if (iVar5 == 0) {
    return 0;
  }
LAB_00011f30:
  DVar3 = GetLastError();
  if (DVar3 == 0x57) {
    SetLastError(dwErrCode);
  }
  return iVar5;
}



/* 00011f84 FUN_00011f84 */

/* Boundary evidence: original MIPS .pdata 00011f84..00011ff7. Semantic name remains unreviewed. */

void FUN_00011f84(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  ULONG_PTR UVar2;
  
  EnterCriticalSection(param_1);
  while (param_1->SpinCount != 0) {
    puVar1 = (undefined4 *)param_1->SpinCount;
    UVar2 = puVar1[0x9e];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
    param_1->SpinCount = UVar2;
  }
  LeaveCriticalSection(param_1);
  DeleteCriticalSection(param_1);
  return;
}



/* 00011ff8 FUN_00011ff8 */

/* Boundary evidence: original MIPS .pdata 00011ff8..00012087. Semantic name remains unreviewed. */

ULONG_PTR FUN_00011ff8(LPCRITICAL_SECTION param_1,ULONG_PTR param_2)

{
  ULONG_PTR UVar1;
  ULONG_PTR UVar2;
  
  if (param_2 == 0) {
    UVar2 = 0;
  }
  else {
    EnterCriticalSection(param_1);
    for (UVar1 = param_1->SpinCount; UVar2 = 0, UVar1 != 0; UVar1 = *(ULONG_PTR *)(UVar1 + 0x278)) {
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



/* 00012088 FUN_00012088 */

/* Boundary evidence: original MIPS .pdata 00012088..000120ff. Semantic name remains unreviewed. */

undefined4 FUN_00012088(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00011ff8(DAT_000150bc,*(ULONG_PTR *)(param_1 + 4)), piVar1 != (int *)0x0))
  {
    uVar2 = (**(code **)(*piVar1 + 8))(piVar1,param_1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 00012100 FUN_00012100 */

/* Boundary evidence: original MIPS .pdata 00012100..0001216b. Semantic name remains unreviewed. */

undefined4 FUN_00012100(ULONG_PTR param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00011ff8(DAT_000150bc,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 0001216c FUN_0001216c */

/* Boundary evidence: original MIPS .pdata 0001216c..000121d7. Semantic name remains unreviewed. */

undefined4 FUN_0001216c(ULONG_PTR param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00011ff8(DAT_000150bc,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 000121d8 FUN_000121d8 */

/* Boundary evidence: original MIPS .pdata 000121d8..00012243. Semantic name remains unreviewed. */

undefined4 FUN_000121d8(ULONG_PTR param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00011ff8(DAT_000150bc,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 00012244 FUN_00012244 */

/* Boundary evidence: original MIPS .pdata 00012244..000122af. Semantic name remains unreviewed. */

undefined4 FUN_00012244(ULONG_PTR param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00011ff8(DAT_000150bc,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x18))(piVar1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 000122b0 FUN_000122b0 */

/* Boundary evidence: original MIPS .pdata 000122b0..00012327. Semantic name remains unreviewed. */

undefined4 FUN_000122b0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00011ff8(DAT_000150bc,*(ULONG_PTR *)(param_1 + 4)), piVar1 != (int *)0x0))
  {
    uVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_1);
    FUN_000117c8(piVar1);
  }
  return uVar2;
}



/* 00012328 FUN_00012328 */

/* Boundary evidence: original MIPS .pdata 00012328..00012893. Semantic name remains unreviewed. */

int FUN_00012328(undefined4 param_1,undefined4 param_2,uint param_3,ULONG_PTR *param_4,uint param_5,
                int *param_6,uint param_7,undefined4 *param_8)

{
  bool bVar1;
  DWORD dwErrCode;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined3 extraout_var;
  DWORD DVar5;
  int iVar6;
  
  iVar6 = 0;
  dwErrCode = GetLastError();
  SetLastError(0x57);
  if (0x1090024 < param_3) {
    if (param_3 < 0x1090401) {
      if (param_3 == 0x1090400) {
        if (param_4 == (ULONG_PTR *)0x0) {
          return 0;
        }
        if (param_5 < 0x218) {
          return 0;
        }
        if (param_6 == (int *)0x0) {
          return 0;
        }
        if (param_7 < 8) {
          return 0;
        }
        piVar3 = FUN_00011888(param_4);
        if (piVar3 == (int *)0x0) {
          return 0;
        }
        *param_6 = (int)piVar3;
        iVar6 = CreateAPIHandle(DAT_000150a4,piVar3);
        if ((iVar6 != 0) && (iVar6 != -1)) {
          piVar3[0x9d] = iVar6;
          InterlockedIncrement(piVar3 + 1);
        }
        param_6[1] = iVar6;
        if (param_8 != (undefined4 *)0x0) {
          *param_8 = 8;
        }
LAB_0001274c:
        iVar6 = 1;
        goto LAB_00012844;
      }
      if (param_3 == 0x1090028) {
        if (param_4 == (ULONG_PTR *)0x0) {
          return 0;
        }
        if (param_5 < 0x14) {
          return 0;
        }
        iVar6 = FUN_00011aa0((int)param_4);
      }
      else if (param_3 == 0x109002c) {
        if (param_4 == (ULONG_PTR *)0x0) {
          return 0;
        }
        if (param_5 < 0x14) {
          return 0;
        }
        iVar6 = FUN_00011b18((int)param_4);
      }
      else if (param_3 == 0x1090030) {
        if (param_4 == (ULONG_PTR *)0x0) {
          return 0;
        }
        if (param_5 < 0x24) {
          return 0;
        }
        iVar6 = FUN_00011b90((int)param_4);
      }
      else {
        if (param_3 != 0x1090034) {
          return 0;
        }
        if (param_4 == (ULONG_PTR *)0x0) {
          return 0;
        }
        if (param_5 < 0x24) {
          return 0;
        }
        iVar6 = FUN_00011850();
      }
    }
    else {
      if (param_3 != 0x1090404) {
        if (param_3 == 0x1090800) {
          if (DAT_000150b8 == 0) {
            return 0;
          }
          EventModify(DAT_000150b8,3);
          return 0;
        }
        if (param_3 != 0x1090804) {
          return 0;
        }
        goto LAB_0001274c;
      }
      if (param_4 == (ULONG_PTR *)0x0) {
        return 0;
      }
      if (param_5 < 4) {
        return 0;
      }
      if ((DAT_000150bc != (LPCRITICAL_SECTION)0x0) &&
         (puVar4 = (undefined4 *)FUN_00011ff8(DAT_000150bc,*param_4), puVar4 != (undefined4 *)0x0))
      {
        if ((HANDLE)puVar4[0x9d] != (HANDLE)0xffffffff) {
          CloseHandle((HANDLE)puVar4[0x9d]);
          puVar4[0x9d] = 0xffffffff;
        }
        FUN_000117c8(puVar4);
      }
      if (DAT_000150bc == (LPCRITICAL_SECTION)0x0) {
        iVar6 = 0;
      }
      else {
        bVar1 = FUN_0001416c(DAT_000150bc,(undefined4 *)*param_4);
        iVar6 = CONCAT31(extraout_var,bVar1);
      }
    }
    goto LAB_0001283c;
  }
  if (param_3 == 0x1090024) {
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 0x14) {
      return 0;
    }
    iVar6 = FUN_00011a28((int)param_4);
    goto LAB_0001283c;
  }
  switch(param_3) {
  case 0x1090004:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 0x218) {
      return 0;
    }
    iVar6 = FUN_00012088((int)param_4);
    break;
  default:
    goto switchD_000123d4_caseD_1090005;
  case 0x1090008:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_00012100(*param_4);
    break;
  case 0x109000c:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_0001216c(*param_4);
    break;
  case 0x1090010:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_000121d8(*param_4);
    break;
  case 0x1090014:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_00012244(*param_4);
    break;
  case 0x1090018:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 0x10) {
      return 0;
    }
    if (param_6 == (int *)0x0) {
      return 0;
    }
    if (param_7 < 4) {
      return 0;
    }
    iVar2 = FUN_000122b0((int)param_4);
    if (iVar2 == 0) {
      return 0;
    }
    iVar6 = 1;
    *param_6 = iVar2;
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = 4;
    }
    goto LAB_00012844;
  case 0x109001c:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_00011938(*param_4);
    break;
  case 0x1090020:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_000119b0(*param_4);
  }
LAB_0001283c:
  if (iVar6 != 0) {
LAB_00012844:
    DVar5 = GetLastError();
    if (DVar5 == 0x57) {
      SetLastError(dwErrCode);
    }
  }
switchD_000123d4_caseD_1090005:
  return iVar6;
}



/* 00012894 FUN_00012894 */

/* Boundary evidence: original MIPS .pdata 00012894..00012a5b. Semantic name remains unreviewed. */

undefined4 FUN_00012894(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  int iVar2;
  
  lpCriticalSection = operator_new(0x18);
  if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
    DAT_000150bc = (LPCRITICAL_SECTION)0x0;
  }
  else {
    InitializeCriticalSection(lpCriticalSection);
    lpCriticalSection->SpinCount = 0;
    DAT_000150bc = lpCriticalSection;
  }
  DAT_000150a4 = CreateAPISet(&DAT_000111f8,0xc,&PTR_FUN_00011040,&DAT_00011070);
  iVar2 = 0;
  if (DAT_000150a4 != -1) {
    iVar2 = RegisterAPISet(DAT_000150a4,0x80000007);
  }
  DAT_000150b0 = CreateAPISet(&DAT_000111f0,0x18,&PTR_FUN_000110d0,&DAT_00011130);
  RegisterAPISet(DAT_000150b0,0x80000010);
  DAT_000150a8 = RegisterAFSName(param_1);
  if ((DAT_000150b0 != 0) && (DAT_000150a8 != -1)) {
    DAT_000150b4 = RegisterAFSEx(DAT_000150a8,DAT_000150b0,0,4,0x101);
  }
  uVar1 = 1;
  if (DAT_000150b4 != 0) {
    DAT_000150b8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  }
  if ((((DAT_000150bc == (LPCRITICAL_SECTION)0x0) || (DAT_000150b4 == 0)) ||
      (DAT_000150b8 == (HANDLE)0x0)) || ((DAT_000150a4 == -1 || (iVar2 == 0)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 00012a5c FUN_00012a5c */

/* Boundary evidence: original MIPS .pdata 00012a5c..00012b2b. Semantic name remains unreviewed. */

void FUN_00012a5c(void)

{
  LPCRITICAL_SECTION p_Var1;
  
  if (DAT_000150a4 != -1) {
    CloseHandle((HANDLE)DAT_000150a4);
  }
  if (DAT_000150a8 != -1) {
    DeregisterAFS();
    DeregisterAFSName(DAT_000150a8);
  }
  if (DAT_000150b0 != 0) {
    CloseHandle((HANDLE)DAT_000150b0);
  }
  if (DAT_000150b8 != 0) {
    CloseHandle((HANDLE)DAT_000150b8);
  }
  p_Var1 = DAT_000150bc;
  if (DAT_000150bc != (LPCRITICAL_SECTION)0x0) {
    FUN_00011f84(DAT_000150bc);
    operator_delete(p_Var1);
    DAT_000150bc = (LPCRITICAL_SECTION)0x0;
  }
  return;
}



/* 00012b2c FUN_00012b2c */

/* Boundary evidence: original MIPS .pdata 00012b2c..00012b8b. Semantic name remains unreviewed. */

PHKEY FUN_00012b2c(PHKEY param_1,HKEY param_2,LPCWSTR param_3)

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



/* 00012b8c FUN_00012b8c */

/* Boundary evidence: original MIPS .pdata 00012b8c..00012bcf. Semantic name remains unreviewed. */

undefined4 * FUN_00012b8c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00011200;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00012bd0 FUN_00012bd0 */

/* Boundary evidence: original MIPS .pdata 00012bd0..00012bff. Semantic name remains unreviewed. */

void FUN_00012bd0(int param_1)

{
  if (*(HMODULE *)(param_1 + 0x238) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0x238));
  }
  return;
}



/* 00012c00 FUN_00012c00 */

/* Boundary evidence: original MIPS .pdata 00012c00..00012cbb. Semantic name remains unreviewed. */

undefined4 * FUN_00012c00(undefined4 *param_1,void *param_2,undefined4 param_3)

{
  *param_1 = &PTR_FUN_00011200;
  param_1[1] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  *param_1 = &PTR_FUN_00011204;
  memcpy(param_1 + 7,param_2,0x218);
  param_1[0x9e] = param_3;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0xffffffff;
  return param_1;
}



/* 00012cbc FUN_00012cbc */

/* Boundary evidence: original MIPS .pdata 00012cbc..00012d6f. Semantic name remains unreviewed. */

void FUN_00012cbc(int param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  HKEY local_20;
  DWORD local_1c;
  DWORD local_18;
  undefined4 local_14;
  
  FUN_00012b2c(&local_20,(HKEY)0x80000002,param_2);
  if (local_20 != (HKEY)0x0) {
    local_1c = 4;
    LVar1 = RegQueryValueExW(local_20,L"ReflectorHandle",(LPDWORD)0x0,&local_18,(LPBYTE)&local_14,
                             &local_1c);
    if ((LVar1 == 0) && (local_18 == 4)) {
      *(undefined4 *)(param_1 + 0x270) = local_14;
    }
    if (local_20 != (HKEY)0x0) {
      RegCloseKey(local_20);
    }
  }
  return;
}



/* 00012d70 FUN_00012d70 */

/* Boundary evidence: original MIPS .pdata 00012d70..00012ecb. Semantic name remains unreviewed. */

bool FUN_00012d70(int param_1,undefined4 *param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  bVar2 = false;
  if ((*(int *)(param_1 + 0x23c) != 0) && (*(int *)(param_1 + 0x26c) == 0)) {
    if ((param_2[2] == 0) && (*(int *)(param_1 + 0x270) == 0)) {
      FUN_00012cbc(param_1,(LPCWSTR)(param_2 + 4));
    }
    puVar3 = (undefined4 *)param_2[2];
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = param_2 + 4;
    }
    iVar1 = __GetUserKData(0);
    uVar4 = *(undefined4 *)(iVar1 + -0x1c);
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = *param_2;
    iVar1 = (**(code **)(param_1 + 0x23c))(puVar3,param_2[3]);
    *(int *)(param_1 + 0x26c) = iVar1;
    bVar2 = iVar1 != 0;
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = uVar4;
    if ((!bVar2) && (*(HANDLE *)(param_1 + 0x270) != (HANDLE)0x0)) {
      CloseHandle(*(HANDLE *)(param_1 + 0x270));
      *(undefined4 *)(param_1 + 0x270) = 0;
    }
  }
  return bVar2;
}



/* 00012ecc FUN_00012ecc */

/* Boundary evidence: original MIPS .pdata 00012ecc..00012ed7. Semantic name remains unreviewed. */

undefined4 FUN_00012ecc(void)

{
  return 1;
}



/* 00012ed8 FUN_00012ed8 */

/* Boundary evidence: original MIPS .pdata 00012ed8..00012fe7. Semantic name remains unreviewed. */

undefined4 FUN_00012ed8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  iVar2 = *(int *)(param_1 + 0x26c);
  *(undefined4 *)(param_1 + 0x26c) = 0;
  while (*(int *)(param_1 + 0x234) != 0) {
    uVar1 = **(undefined4 **)(param_1 + 0x234);
    operator_delete(*(undefined4 **)(param_1 + 0x234));
    *(undefined4 *)(param_1 + 0x234) = uVar1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if ((iVar2 != 0) && (*(code **)(param_1 + 0x244) != (code *)0x0)) {
    (**(code **)(param_1 + 0x244))(iVar2);
    if (*(HANDLE *)(param_1 + 0x270) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)(param_1 + 0x270));
      *(undefined4 *)(param_1 + 0x270) = 0;
    }
  }
  return 1;
}



/* 00012fe8 FUN_00012fe8 */

/* Boundary evidence: original MIPS .pdata 00012fe8..00012ff3. Semantic name remains unreviewed. */

undefined4 FUN_00012fe8(void)

{
  return 1;
}



/* 00012ff4 FUN_00012ff4 */

/* Boundary evidence: original MIPS .pdata 00012ff4..0001308b. Semantic name remains unreviewed. */

undefined4 FUN_00012ff4(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((code *)param_1[0x90] == (code *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0xc))();
  }
  else if (param_1[0x9b] != 0) {
    (*(code *)param_1[0x90])(param_1[0x9b]);
  }
  return uVar1;
}



/* 0001308c FUN_0001308c */

/* Boundary evidence: original MIPS .pdata 0001308c..00013097. Semantic name remains unreviewed. */

undefined4 FUN_0001308c(void)

{
  return 1;
}



/* 00013098 FUN_00013098 */

/* Boundary evidence: original MIPS .pdata 00013098..00013113. Semantic name remains unreviewed. */

undefined4 FUN_00013098(int param_1)

{
  if ((*(int *)(param_1 + 0x26c) != 0) && (*(code **)(param_1 + 0x268) != (code *)0x0)) {
    (**(code **)(param_1 + 0x268))(*(int *)(param_1 + 0x26c));
  }
  return 1;
}



/* 00013114 FUN_00013114 */

/* Boundary evidence: original MIPS .pdata 00013114..0001311f. Semantic name remains unreviewed. */

undefined4 FUN_00013114(void)

{
  return 1;
}



/* 00013120 FUN_00013120 */

/* Boundary evidence: original MIPS .pdata 00013120..0001319b. Semantic name remains unreviewed. */

undefined4 FUN_00013120(int param_1)

{
  if ((*(int *)(param_1 + 0x26c) != 0) && (*(code **)(param_1 + 0x264) != (code *)0x0)) {
    (**(code **)(param_1 + 0x264))(*(int *)(param_1 + 0x26c));
  }
  return 1;
}



/* 0001319c FUN_0001319c */

/* Boundary evidence: original MIPS .pdata 0001319c..000131a7. Semantic name remains unreviewed. */

undefined4 FUN_0001319c(void)

{
  return 1;
}



/* 000131a8 FUN_000131a8 */

/* Boundary evidence: original MIPS .pdata 000131a8..00013327. Semantic name remains unreviewed. */

undefined4 * FUN_000131a8(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  DWORD dwErrCode;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x248) == 0) {
    dwErrCode = 1;
  }
  else {
    puVar1 = operator_new(8);
    if (puVar1 != (undefined4 *)0x0) {
      iVar2 = __GetUserKData(0);
      uVar4 = *(undefined4 *)(iVar2 + -0x1c);
      iVar2 = __GetUserKData(0);
      *(undefined4 *)(iVar2 + -0x1c) = *param_2;
      iVar2 = (**(code **)(param_1 + 0x248))(*(undefined4 *)(param_1 + 0x26c),param_2[2],param_2[3])
      ;
      iVar3 = __GetUserKData(0);
      *(undefined4 *)(iVar3 + -0x1c) = uVar4;
      if (iVar2 != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        puVar1[1] = iVar2;
        *puVar1 = *(undefined4 *)(param_1 + 0x234);
        *(undefined4 **)(param_1 + 0x234) = puVar1;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        return puVar1;
      }
      operator_delete(puVar1);
      return (undefined4 *)0x0;
    }
    dwErrCode = 0xe;
  }
  SetLastError(dwErrCode);
  return (undefined4 *)0x0;
}



/* 00013328 FUN_00013328 */

/* Boundary evidence: original MIPS .pdata 00013328..00013333. Semantic name remains unreviewed. */

undefined4 FUN_00013328(void)

{
  return 1;
}



/* 00013334 FUN_00013334 */

/* Boundary evidence: original MIPS .pdata 00013334..00013467. Semantic name remains unreviewed. */

undefined4 FUN_00013334(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  piVar2 = *(int **)(param_1 + 0x234);
  piVar3 = (int *)0x0;
  if (*(int **)(param_1 + 0x234) != (int *)0x0) {
    do {
      piVar1 = piVar2;
      piVar2 = piVar1;
      if (piVar1 == param_2) break;
      piVar2 = (int *)*piVar1;
      piVar3 = piVar1;
    } while (piVar2 != (int *)0x0);
    if (piVar2 != (int *)0x0) {
      iVar5 = piVar2[1];
      if (piVar3 == (int *)0x0) {
        *(int *)(param_1 + 0x234) = *piVar2;
      }
      else {
        *piVar3 = *piVar2;
      }
      operator_delete(piVar2);
      goto LAB_000133d4;
    }
  }
  iVar5 = 0;
LAB_000133d4:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  uVar4 = 1;
  SetLastError(0x1f);
  if ((iVar5 != 0) && (*(code **)(param_1 + 0x250) != (code *)0x0)) {
    uVar4 = (**(code **)(param_1 + 0x250))(iVar5);
  }
  return uVar4;
}



/* 00013468 FUN_00013468 */

/* Boundary evidence: original MIPS .pdata 00013468..00013473. Semantic name remains unreviewed. */

undefined4 FUN_00013468(void)

{
  return 1;
}



/* 00013474 FUN_00013474 */

/* Boundary evidence: original MIPS .pdata 00013474..000134e7. Semantic name remains unreviewed. */

bool FUN_00013474(int param_1,int param_2)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  for (piVar1 = *(int **)(param_1 + 0x234); (piVar1 != (int *)0x0 && (piVar1 != (int *)param_2));
      piVar1 = (int *)*piVar1) {
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return piVar1 != (int *)0x0;
}



/* 000134e8 FUN_000134e8 */

/* Boundary evidence: original MIPS .pdata 000134e8..0001356b. Semantic name remains unreviewed. */

undefined4 FUN_000134e8(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  piVar1 = *(int **)(param_1 + 0x234);
  do {
    if (piVar1 == (int *)0x0) {
LAB_00013544:
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
      return uVar2;
    }
    if (piVar1 == (int *)param_2) {
      uVar2 = piVar1[1];
      goto LAB_00013544;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}



/* 0001356c FUN_0001356c */

/* Boundary evidence: original MIPS .pdata 0001356c..000136c7. Semantic name remains unreviewed. */

undefined4 FUN_0001356c(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar3;
  
  uVar2 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 8);
  EnterCriticalSection(lpCriticalSection);
  piVar1 = *(int **)(param_1 + 0x234);
  if (piVar1 != (int *)0x0) {
    do {
      if (piVar1 == param_2) break;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if ((piVar1 != (int *)0x0) && (iVar3 = piVar1[1], iVar3 != 0)) {
      if (*(int *)(param_1 + 0x24c) == 0) {
        piVar1[1] = 0;
        if (*(int *)(param_1 + 0x250) == 0) goto LAB_00013634;
        LeaveCriticalSection(lpCriticalSection);
        uVar2 = (**(code **)(param_1 + 0x250))(iVar3);
      }
      else {
        LeaveCriticalSection(lpCriticalSection);
        uVar2 = (**(code **)(param_1 + 0x24c))(iVar3);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    }
  }
LAB_00013634:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return uVar2;
}



/* 000136c8 FUN_000136c8 */

/* Boundary evidence: original MIPS .pdata 000136c8..000136d3. Semantic name remains unreviewed. */

undefined4 FUN_000136c8(void)

{
  return 1;
}



/* 000136d4 FUN_000136d4 */

/* Boundary evidence: original MIPS .pdata 000136d4..000136df. Semantic name remains unreviewed. */

undefined4 FUN_000136d4(void)

{
  return 1;
}



/* 000136e0 FUN_000136e0 */

/* Boundary evidence: original MIPS .pdata 000136e0..00013807. Semantic name remains unreviewed. */

int FUN_000136e0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2[1]);
  if ((iVar1 != 0) && (param_1[0x95] != 0)) {
    iVar3 = __GetUserKData(0);
    uVar4 = *(undefined4 *)(iVar3 + -0x1c);
    iVar3 = __GetUserKData(0);
    *(undefined4 *)(iVar3 + -0x1c) = *param_2;
    uVar2 = (*(code *)param_1[0x95])(iVar1,param_2[2],param_2[3]);
    param_2[4] = uVar2;
    iVar3 = 1;
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = uVar4;
  }
  if (iVar3 == 0) {
    param_2[4] = 0xffffffff;
  }
  return iVar3;
}



/* 00013808 FUN_00013808 */

/* Boundary evidence: original MIPS .pdata 00013808..00013813. Semantic name remains unreviewed. */

undefined4 FUN_00013808(void)

{
  return 1;
}



/* 00013814 FUN_00013814 */

/* Boundary evidence: original MIPS .pdata 00013814..0001393b. Semantic name remains unreviewed. */

int FUN_00013814(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2[1]);
  if ((iVar1 != 0) && (param_1[0x96] != 0)) {
    iVar3 = __GetUserKData(0);
    uVar4 = *(undefined4 *)(iVar3 + -0x1c);
    iVar3 = __GetUserKData(0);
    *(undefined4 *)(iVar3 + -0x1c) = *param_2;
    uVar2 = (*(code *)param_1[0x96])(iVar1,param_2[2],param_2[3]);
    param_2[4] = uVar2;
    iVar3 = 1;
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = uVar4;
  }
  if (iVar3 == 0) {
    param_2[4] = 0xffffffff;
  }
  return iVar3;
}



/* 0001393c FUN_0001393c */

/* Boundary evidence: original MIPS .pdata 0001393c..00013947. Semantic name remains unreviewed. */

undefined4 FUN_0001393c(void)

{
  return 1;
}



/* 00013948 FUN_00013948 */

/* Boundary evidence: original MIPS .pdata 00013948..00013a6f. Semantic name remains unreviewed. */

int FUN_00013948(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2[1]);
  if ((iVar1 != 0) && (param_1[0x97] != 0)) {
    iVar3 = __GetUserKData(0);
    uVar4 = *(undefined4 *)(iVar3 + -0x1c);
    iVar3 = __GetUserKData(0);
    *(undefined4 *)(iVar3 + -0x1c) = *param_2;
    uVar2 = (*(code *)param_1[0x97])(iVar1,param_2[2],param_2[3]);
    param_2[4] = uVar2;
    iVar3 = 1;
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = uVar4;
  }
  if (iVar3 == 0) {
    param_2[4] = 0xffffffff;
  }
  return iVar3;
}



/* 00013a70 FUN_00013a70 */

/* Boundary evidence: original MIPS .pdata 00013a70..00013a7b. Semantic name remains unreviewed. */

undefined4 FUN_00013a70(void)

{
  return 1;
}



/* 00013a7c FUN_00013a7c */

/* Boundary evidence: original MIPS .pdata 00013a7c..00013baf. Semantic name remains unreviewed. */

undefined4 FUN_00013a7c(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar4 = 0;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2[1]);
  if ((iVar1 != 0) && (param_1[0x98] != 0)) {
    iVar2 = __GetUserKData(0);
    uVar5 = *(undefined4 *)(iVar2 + -0x1c);
    iVar2 = __GetUserKData(0);
    *(undefined4 *)(iVar2 + -0x1c) = *param_2;
    puVar3 = param_2 + 8;
    if (param_2[7] == 0) {
      puVar3 = (undefined4 *)0x0;
    }
    uVar4 = (*(code *)param_1[0x98])
                      (iVar1,param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],puVar3);
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = uVar5;
  }
  return uVar4;
}



/* 00013bb0 FUN_00013bb0 */

/* Boundary evidence: original MIPS .pdata 00013bb0..00013bbb. Semantic name remains unreviewed. */

undefined4 FUN_00013bb0(void)

{
  return 1;
}



/* 00013bbc FUN_00013bbc */

/* Boundary evidence: original MIPS .pdata 00013bbc..00013c4f. Semantic name remains unreviewed. */

undefined4 FUN_00013bbc(undefined4 param_1,short *param_2,wchar_t *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 local_50;
  short local_4c;
  undefined2 local_4a;
  wchar_t awStack_48 [28];
  uint local_10;
  
  local_10 = DAT_0001509c;
  if ((param_2 != (short *)0x0) && (*param_2 != 0)) {
    local_50 = *(undefined4 *)param_2;
    local_4c = param_2[2];
    local_4a = 0x5f;
    wcscpy(awStack_48,param_3);
    param_3 = (wchar_t *)&local_50;
  }
  uVar1 = GetProcAddressW(param_4,param_3);
  FUN_000143b4(local_10);
  return uVar1;
}



/* 00013c50 FUN_00013c50 */

/* Boundary evidence: original MIPS .pdata 00013c50..00013ce7. Semantic name remains unreviewed. */

int * FUN_00013c50(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  EnterCriticalSection(param_1);
  piVar2 = (int *)param_1->SpinCount;
  do {
    piVar3 = (int *)0x0;
    if (piVar2 == (int *)0x0) {
LAB_00013cc0:
      LeaveCriticalSection(param_1);
      return piVar3;
    }
    iVar1 = (**(code **)(*piVar2 + 0x24))(piVar2,param_2);
    if (iVar1 != 0) {
      InterlockedIncrement(piVar2 + 1);
      piVar3 = piVar2;
      goto LAB_00013cc0;
    }
    piVar2 = (int *)piVar2[0x9e];
  } while( true );
}



/* 00013ce8 FUN_00013ce8 */

/* Boundary evidence: original MIPS .pdata 00013ce8..00013d97. Semantic name remains unreviewed. */

ULONG_PTR FUN_00013ce8(LPCRITICAL_SECTION param_1,ULONG_PTR param_2,int param_3)

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
      pUVar3 = (ULONG_PTR *)(UVar2 + 0x278);
      UVar1 = *pUVar3;
      while (UVar1 != 0) {
        UVar2 = *pUVar3;
        pUVar3 = (ULONG_PTR *)(UVar2 + 0x278);
        UVar1 = *pUVar3;
      }
      *(ULONG_PTR *)(UVar2 + 0x278) = param_2;
    }
    else {
      *(ULONG_PTR *)(param_2 + 0x278) = param_1->SpinCount;
      param_1->SpinCount = param_2;
    }
    InterlockedIncrement((LONG *)(param_2 + 4));
    LeaveCriticalSection(param_1);
  }
  return param_2;
}



/* 00013d98 FUN_00013d98 */

/* Boundary evidence: original MIPS .pdata 00013d98..00013e43. Semantic name remains unreviewed. */

undefined4 * FUN_00013d98(LPCRITICAL_SECTION param_1,undefined4 *param_2)

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
      param_1->SpinCount = param_2[0x9e];
LAB_00013e14:
      FUN_000117c8(param_2);
      puVar4 = param_2;
    }
    else {
      iVar2 = puVar3[0x9e];
      while (iVar2 != 0) {
        puVar1 = (undefined4 *)puVar3[0x9e];
        if (puVar1 == param_2) {
          puVar3[0x9e] = param_2[0x9e];
          goto LAB_00013e14;
        }
        puVar3 = puVar1;
        iVar2 = puVar1[0x9e];
      }
    }
  }
  LeaveCriticalSection(param_1);
  return puVar4;
}



/* 00013e44 FUN_00013e44 */

/* Boundary evidence: original MIPS .pdata 00013e44..0001407b. Semantic name remains unreviewed. */

undefined4 FUN_00013e44(int param_1)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  short *psVar3;
  
  if (*(int *)(param_1 + 0x238) == 0) {
    if ((*(uint *)(param_1 + 0x20) & 2) == 0) {
      pHVar1 = (HMODULE)LoadDriver();
    }
    else {
      pHVar1 = LoadLibraryW((LPCWSTR)(param_1 + 0x2c));
    }
    *(HMODULE *)(param_1 + 0x238) = pHVar1;
    if (pHVar1 != (HMODULE)0x0) {
      psVar3 = (short *)(param_1 + 0x24);
      uVar2 = FUN_00013bbc(param_1,psVar3,L"Init",pHVar1);
      *(undefined4 *)(param_1 + 0x23c) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"PreDeinit",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x240) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"Deinit",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x244) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"Open",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x248) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"PreClose",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x24c) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"Close",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x250) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"Read",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x254) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"Write",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 600) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"Seek",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x25c) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"IOControl",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x260) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"PowerUp",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x264) = uVar2;
      uVar2 = FUN_00013bbc(param_1,psVar3,L"PowerDown",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x268) = uVar2;
      if (((((*(int *)(param_1 + 0x23c) != 0) && (*(int *)(param_1 + 0x244) != 0)) &&
           ((*(int *)(param_1 + 0x248) == 0 || (*(int *)(param_1 + 0x250) != 0)))) &&
          ((((*(int *)(param_1 + 0x254) != 0 || (*(int *)(param_1 + 600) != 0)) ||
            (*(int *)(param_1 + 0x25c) != 0)) || (*(int *)(param_1 + 0x260) != 0)))) &&
         ((*(int *)(param_1 + 0x24c) == 0 || (*(int *)(param_1 + 0x240) != 0)))) {
        return 1;
      }
    }
  }
  return 0;
}



/* 0001407c FUN_0001407c */

/* Boundary evidence: original MIPS .pdata 0001407c..00014133. Semantic name remains unreviewed. */

void FUN_0001407c(undefined4 *param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 2);
  *param_1 = &PTR_FUN_00011204;
  EnterCriticalSection(lpCriticalSection);
  if (param_1[0x8e] != 0) {
    FUN_00012ed8((int)param_1);
    if ((HMODULE)param_1[0x8e] != (HMODULE)0x0) {
      FreeLibrary((HMODULE)param_1[0x8e]);
    }
  }
  while (param_1[0x8d] != 0) {
    uVar1 = *(undefined4 *)param_1[0x8d];
    operator_delete((undefined4 *)param_1[0x8d]);
    param_1[0x8d] = uVar1;
  }
  LeaveCriticalSection(lpCriticalSection);
  DeleteCriticalSection(lpCriticalSection);
  *param_1 = &PTR_FUN_00011200;
  return;
}



/* 00014134 FUN_00014134 */

/* Boundary evidence: original MIPS .pdata 00014134..0001416b. Semantic name remains unreviewed. */

bool FUN_00014134(LPCRITICAL_SECTION param_1,ULONG_PTR param_2)

{
  ULONG_PTR UVar1;
  
  UVar1 = FUN_00013ce8(param_1,param_2,1);
  return UVar1 != 0;
}



/* 0001416c FUN_0001416c */

/* Boundary evidence: original MIPS .pdata 0001416c..0001419b. Semantic name remains unreviewed. */

bool FUN_0001416c(LPCRITICAL_SECTION param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_00013d98(param_1,param_2);
  return puVar1 != (undefined4 *)0x0;
}



/* 0001419c FUN_0001419c */

/* Boundary evidence: original MIPS .pdata 0001419c..000141b7. Semantic name remains unreviewed. */

void FUN_0001419c(int param_1)

{
  FUN_00013e44(param_1);
  return;
}



/* 000141b8 FUN_000141b8 */

/* Boundary evidence: original MIPS .pdata 000141b8..00014203. Semantic name remains unreviewed. */

undefined4 * FUN_000141b8(undefined4 *param_1,uint param_2)

{
  FUN_0001407c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00014334 FUN_00014334 */

/* Boundary evidence: original MIPS .pdata 00014334..00014387. Semantic name remains unreviewed. */

void FUN_00014334(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_000143b4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00014388 FUN_00014388 */

/* Boundary evidence: original MIPS .pdata 00014388..000143b3. Semantic name remains unreviewed. */

undefined4 FUN_00014388(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00014334(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 000143b4 FUN_000143b4 */

/* Boundary evidence: original MIPS .pdata 000143b4..000143fb. Semantic name remains unreviewed. */

void FUN_000143b4(uint param_1)

{
  if ((param_1 == DAT_0001509c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


