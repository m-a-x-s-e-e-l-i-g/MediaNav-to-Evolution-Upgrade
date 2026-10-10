/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011af4 FUN_00011af4 */

/* Boundary evidence: original MIPS .pdata 00011af4..00011b87. Semantic name remains unreviewed. */

void FUN_00011af4(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  UINT UVar1;
  
  FUN_00011e04();
  UVar1 = FUN_00017e88(param_1,param_2,param_3);
  FUN_00011d44(UVar1);
  FUN_00011d64(UVar1);
  return;
}



/* 00011b88 FUN_00011b88 */

/* Boundary evidence: original MIPS .pdata 00011b88..00011bc7. Semantic name remains unreviewed. */

void FUN_00011b88(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00011bc8 entry */

/* Boundary evidence: original MIPS .pdata 00011bc8..00011c23. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  FUN_00011e40();
  FUN_00011af4(param_1,param_2,param_3);
  return;
}



/* 00011c24 FUN_00011c24 */

/* Boundary evidence: original MIPS .pdata 00011c24..00011d43. Semantic name remains unreviewed. */

void FUN_00011c24(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0001d258 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_0001d4a4;
    if (DAT_0001d4a4 != (undefined4 *)0x0) {
      while (DAT_0001d4a0 = DAT_0001d4a0 + -1, _Memory <= DAT_0001d4a0) {
        if ((code *)*DAT_0001d4a0 != (code *)0x0) {
          (*(code *)*DAT_0001d4a0)();
          _Memory = DAT_0001d4a4;
        }
      }
      free(_Memory);
      DAT_0001d4a0 = (undefined4 *)0x0;
      DAT_0001d4a4 = (undefined4 *)0x0;
    }
    FUN_00011db0((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_00011db0((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_0001d4a8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011d44 FUN_00011d44 */

/* Boundary evidence: original MIPS .pdata 00011d44..00011d63. Semantic name remains unreviewed. */

void FUN_00011d44(UINT param_1)

{
  FUN_00011c24(param_1,0,0);
  return;
}



/* 00011d64 FUN_00011d64 */

/* Boundary evidence: original MIPS .pdata 00011d64..00011daf. Semantic name remains unreviewed. */

void FUN_00011d64(UINT param_1)

{
  DAT_0001d258 = 0;
  FUN_00011db0((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00011db0 FUN_00011db0 */

/* Boundary evidence: original MIPS .pdata 00011db0..00011e03. Semantic name remains unreviewed. */

void FUN_00011db0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00011e04 FUN_00011e04 */

/* Boundary evidence: original MIPS .pdata 00011e04..00011e3f. Semantic name remains unreviewed. */

void FUN_00011e04(void)

{
  FUN_00011db0((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_00011db0((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00011e40 FUN_00011e40 */

/* Boundary evidence: original MIPS .pdata 00011e40..00011eb3. Semantic name remains unreviewed. */

void FUN_00011e40(void)

{
  uint uVar1;
  
  if ((DAT_0001d244 == 0) || (DAT_0001d244 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0001d244 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0001d244 == 0) {
      DAT_0001d244 = 0xb064;
    }
  }
  DAT_0001d248 = ~DAT_0001d244;
  return;
}



/* 00011f54 FUN_00011f54 */

/* Boundary evidence: original MIPS .pdata 00011f54..0001201b. Semantic name remains unreviewed. */

uint FUN_00011f54(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  DWORD aDStack_18 [2];
  
  uVar1 = 0;
  if (DAT_0001d458 == 0) {
    uVar1 = RegCreateKeyExW((HKEY)0x80000002,L"Windows CE Services\\Synchronization",0,(LPWSTR)0x0,0
                            ,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,(PHKEY)&DAT_0001d454,aDStack_18);
    if (uVar1 == 0) {
      DAT_0001d2e4 = param_1;
      DAT_0001d300 = param_2;
    }
  }
  DAT_0001d458 = DAT_0001d458 + 1;
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  return uVar1;
}



/* 0001201c FUN_0001201c */

/* Boundary evidence: original MIPS .pdata 0001201c..00012097. Semantic name remains unreviewed. */

uint FUN_0001201c(void)

{
  uint uVar1;
  
  if ((0 < DAT_0001d458) && (DAT_0001d458 = DAT_0001d458 + -1, DAT_0001d458 == 0)) {
    uVar1 = RegCloseKey(DAT_0001d454);
    DAT_0001d2e4 = 0;
    DAT_0001d300 = 0;
    if (uVar1 != 0) {
      if ((int)uVar1 < 1) {
        DAT_0001d2e4 = 0;
        DAT_0001d300 = 0;
        return uVar1;
      }
      DAT_0001d2e4 = 0;
      DAT_0001d300 = 0;
      return uVar1 & 0xffff | 0x80070000;
    }
  }
  return 0;
}



/* 00012098 FUN_00012098 */

int * FUN_00012098(int param_1,int param_2,int *param_3)

{
  if (param_2 == 0) {
    param_3 = (int *)0x0;
  }
  else if (param_2 == 1) {
    *param_3 = param_1;
  }
  else if (param_2 == 2) {
    param_3 = (int *)(param_1 + 4);
  }
  else {
    param_3 = (int *)0x0;
    if (param_2 == 3) {
      param_3 = (int *)(param_1 + 0xcc);
    }
  }
  return param_3;
}



/* 000120ec FUN_000120ec */

/* Boundary evidence: original MIPS .pdata 000120ec..00012153. Semantic name remains unreviewed. */

void FUN_000120ec(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_2 != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x24);
    while (puVar1 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)puVar1[0x34];
      (**(code **)*puVar1)(puVar1,1);
      puVar1 = puVar2;
    }
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}



/* 00012154 FUN_00012154 */

/* Boundary evidence: original MIPS .pdata 00012154..000121a3. Semantic name remains unreviewed. */

undefined4 FUN_00012154(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(lpCriticalSection);
  }
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 000121a4 FUN_000121a4 */

/* Boundary evidence: original MIPS .pdata 000121a4..00012233. Semantic name remains unreviewed. */

void FUN_000121a4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(lpCriticalSection);
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (*(int *)(param_1 + 0x24) != 0) {
    do {
      iVar2 = iVar1;
      iVar1 = *(int *)(iVar2 + 0xd0);
    } while (*(int *)(iVar2 + 0xd0) != 0);
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0xd0) = param_2;
      goto LAB_00012200;
    }
  }
  *(int *)(param_1 + 0x24) = param_2;
LAB_00012200:
  *(undefined4 *)(param_2 + 0xd0) = 0;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return;
}



/* 00012234 FUN_00012234 */

/* Boundary evidence: original MIPS .pdata 00012234..00012317. Semantic name remains unreviewed. */

void FUN_00012234(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(lpCriticalSection);
  }
  puVar3 = *(undefined4 **)(param_1 + 0x24);
  puVar2 = (undefined4 *)0x0;
  while (puVar1 = puVar3, puVar1 != (undefined4 *)0x0) {
    if (puVar1 == param_2) goto LAB_00012294;
    puVar2 = puVar1;
    puVar3 = (undefined4 *)puVar1[0x34];
  }
  if (param_2 == (undefined4 *)0x0) {
LAB_00012294:
    if (param_2 != (undefined4 *)0x0) {
      if (puVar2 == (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0x24) = param_2[0x34];
      }
      else {
        puVar2[0x34] = param_2[0x34];
      }
      if (param_3 != 0) {
        (**(code **)*param_2)(param_2,1);
      }
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
      *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    }
  }
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return;
}



/* 00012318 FUN_00012318 */

/* Boundary evidence: original MIPS .pdata 00012318..000125ab. Semantic name remains unreviewed. */

int FUN_00012318(int param_1,wchar_t *param_2,uint param_3,int param_4,int param_5)

{
  bool bVar1;
  int *piVar2;
  wchar_t *_Str1;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar5;
  int local_38;
  int iStack_34;
  int local_30;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  local_30 = param_4;
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(lpCriticalSection);
  }
  if (*(int *)(param_1 + 0x20) == 0) {
    if (*(int *)(param_1 + 0x1c) < 0) goto LAB_000123b0;
  }
  else if ((*(int *)(param_1 + 0x1c) <= *(int *)(param_1 + 0x18)) && (-1 < *(int *)(param_1 + 0x1c))
          ) goto LAB_000123b0;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0;
LAB_000123b0:
  if ((param_3 == 0) && (-1 < *(int *)(param_1 + 0x1c))) {
    iVar4 = *(int *)(param_1 + 0x1c) + 1;
    if ((*(int *)param_2 == iVar4) && (*(int *)(*(int *)(param_1 + 0x20) + 0xd0) != 0)) {
      *(int *)(param_1 + 0x1c) = iVar4;
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0xd0);
    }
    if ((*(int *)param_2 == *(int *)(param_1 + 0x1c)) &&
       (piVar2 = FUN_00012098(*(int *)(param_1 + 0x20),param_4,&iStack_34), piVar2 != (int *)0x0)) {
      iVar4 = *piVar2;
LAB_0001241c:
      if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
        return iVar4;
      }
      LeaveCriticalSection(lpCriticalSection);
      return iVar4;
    }
  }
  iVar4 = *(int *)(param_1 + 0x1c);
  bVar1 = iVar4 < 0;
  if (bVar1) {
    iVar5 = *(int *)(param_1 + 0x24);
    iVar4 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 0x20);
  }
  bVar1 = !bVar1;
  do {
    local_38 = iVar4;
    if (iVar5 == 0) {
      if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
        LeaveCriticalSection(lpCriticalSection);
      }
      return param_5;
    }
    _Str1 = (wchar_t *)FUN_00012098(iVar5,param_3,&iStack_34);
    if (_Str1 == (wchar_t *)0x0) {
      _Str1 = (wchar_t *)&local_38;
    }
    piVar2 = FUN_00012098(iVar5,param_4,&iStack_34);
    if (piVar2 == (int *)0x0) {
      piVar2 = &local_38;
    }
    if (param_3 < 2) {
LAB_000124c8:
      if (*(int *)_Str1 != *(int *)param_2) goto LAB_000124d8;
    }
    else {
      if (param_3 == 2) {
        iVar3 = wcscmp(_Str1,param_2);
        if (iVar3 == 0) goto LAB_000124dc;
      }
      else if (param_3 == 3) goto LAB_000124c8;
LAB_000124d8:
      piVar2 = (int *)0x0;
    }
LAB_000124dc:
    if (piVar2 != (int *)0x0) {
      if (iVar5 != 0) {
        *(int *)(param_1 + 0x1c) = iVar4;
        *(int *)(param_1 + 0x20) = iVar5;
      }
      iVar4 = *piVar2;
      goto LAB_0001241c;
    }
    if (bVar1) {
      iVar5 = *(int *)(param_1 + 0x24);
      bVar1 = false;
      iVar4 = 0;
    }
    else {
      iVar5 = *(int *)(iVar5 + 0xd0);
      iVar4 = iVar4 + 1;
    }
    param_4 = local_30;
    if ((-1 < *(int *)(param_1 + 0x1c)) && (iVar5 == *(int *)(param_1 + 0x20))) {
      iVar4 = iVar4 + 1;
      iVar5 = *(int *)(iVar5 + 0xd0);
    }
  } while( true );
}



/* 000125ac FUN_000125ac */

/* Boundary evidence: original MIPS .pdata 000125ac..0001271f. Semantic name remains unreviewed. */

undefined4 FUN_000125ac(int *param_1,HKEY param_2)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD dwIndex;
  HKEY local_f0;
  DWORD local_ec;
  WCHAR aWStack_e8 [100];
  uint local_20;
  
  local_20 = DAT_0001d244;
  if (DAT_0001d458 != 0) {
    param_2 = DAT_0001d454;
  }
  LVar1 = RegOpenKeyExW(param_2,L"Objects",0,0x20019,&local_f0);
  if (LVar1 == 0) {
    dwIndex = 0;
    do {
      local_ec = 100;
      LVar1 = RegEnumKeyExW(local_f0,dwIndex,aWStack_e8,&local_ec,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
      if (LVar1 == 0x103) {
        LVar1 = 0;
        break;
      }
      iVar2 = (**(code **)(*param_1 + 8))(param_1);
      wcscpy((wchar_t *)(iVar2 + 4),aWStack_e8);
      *(DWORD *)(iVar2 + 0xcc) = dwIndex + 10000;
      FUN_000121a4((int)param_1,iVar2);
      dwIndex = dwIndex + 1;
    } while (LVar1 == 0);
    RegCloseKey(local_f0);
    if (LVar1 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0x8000ffff;
    }
    FUN_0001c2c0(local_20);
  }
  else {
    FUN_0001c2c0(local_20);
    uVar3 = 0x8000ffff;
  }
  return uVar3;
}



/* 00012720 FUN_00012720 */

/* Boundary evidence: original MIPS .pdata 00012720..0001278b. Semantic name remains unreviewed. */

void FUN_00012720(int param_1)

{
  *(undefined4 *)(param_1 + 0x10c) = 0;
  if (*(void **)(param_1 + 0x110) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x110));
    *(undefined4 *)(param_1 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x108) = 0;
    *(undefined4 *)(param_1 + 0x104) = 0;
    *(undefined4 *)(param_1 + 0x100) = 0;
    *(undefined4 *)(param_1 + 0xfc) = 0;
  }
  if (*(int *)(param_1 + 8) != 0) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 0xf8) != 5) {
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  return;
}



/* 00012798 FUN_00012798 */

/* Boundary evidence: original MIPS .pdata 00012798..00012843. Semantic name remains unreviewed. */

undefined4 FUN_00012798(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_00011ab0,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_00011aa0,0x10), iVar1 == 0)) {
    *param_3 = param_1;
  }
  else {
    *param_3 = 0;
  }
  if ((int *)*param_3 == (int *)0x0) {
    uVar2 = 0x80004002;
  }
  else {
    (**(code **)(*(int *)*param_3 + 4))();
    uVar2 = 0;
  }
  return uVar2;
}



/* 00012844 FUN_00012844 */

/* Boundary evidence: original MIPS .pdata 00012844..0001285f. Semantic name remains unreviewed. */

void FUN_00012844(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 00012860 FUN_00012860 */

/* Boundary evidence: original MIPS .pdata 00012860..00012913. Semantic name remains unreviewed. */

int FUN_00012860(int param_1,int *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  memcpy((void *)(param_1 + 0xc),param_3,0xec);
  *(int **)(param_1 + 8) = param_2;
  iVar1 = (**(code **)(*param_2 + 0xc))(param_2,(void *)(param_1 + 0xc));
  if (iVar1 < 0) {
    uVar2 = 7;
  }
  else if (*(int *)(param_1 + 0x10) == 0) {
    uVar2 = 6;
  }
  else {
    uVar2 = 1;
  }
  *(undefined4 *)(param_1 + 0xf8) = uVar2;
  *(undefined2 *)(param_1 + 0x114) = 1;
  *(undefined4 *)(param_1 + 0x118) = 0;
  if ((*(int *)(param_1 + 0x10) == 0) && (iVar1 == -0x7febfffb)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 00012914 FUN_00012914 */

/* Boundary evidence: original MIPS .pdata 00012914..00012dcb. Semantic name remains unreviewed. */

int FUN_00012914(int param_1,uint *param_2,uint param_3,int *param_4)

{
  ushort uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  uint uVar9;
  uint local_30;
  void *local_2c;
  
  *param_4 = 0;
  iVar3 = *(int *)(param_1 + 0xf8);
  iVar7 = 0;
  uVar9 = param_3;
  pvVar8 = local_2c;
  if ((((iVar3 == 1) || (iVar3 == 2)) || (iVar3 == 3)) || (iVar3 == 4)) {
    while (uVar9 != 0) {
      iVar7 = 0x140001;
      uVar5 = *(uint *)(param_1 + 0x104);
      if (uVar5 < *(uint *)(param_1 + 0x100)) {
        uVar6 = *(uint *)(param_1 + 0x100) - uVar5;
        if (uVar9 < uVar6) {
          uVar6 = uVar9;
        }
        memcpy(param_2,(void *)(*(int *)(param_1 + 0x110) + uVar5),uVar6);
        *(uint *)(param_1 + 0x104) = uVar6 + *(int *)(param_1 + 0x104);
        param_2 = (uint *)(uVar6 + (int)param_2);
        uVar9 = uVar9 - uVar6;
        iVar7 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0xf8);
        if (iVar3 == 2) {
          iVar7 = -0x7febfeff;
          break;
        }
        if (iVar3 == 3) {
          iVar7 = -0x7febfefe;
          break;
        }
        if (iVar3 == 4) break;
        local_2c = (void *)0x0;
        iVar7 = (**(code **)(**(int **)(param_1 + 8) + 0x14))
                          (*(int **)(param_1 + 8),&local_2c,&local_30,param_3);
        *(int *)(param_1 + 0x18) = iVar7;
        if (*(int *)(param_1 + 0x118) != 0) {
          *(undefined4 *)(param_1 + 0x118) = 0;
          iVar7 = -0x7febfeff;
          *(undefined4 *)(param_1 + 0x18) = 0x80140101;
        }
        if (260000 < local_30) {
          local_30 = 260000;
        }
        if (iVar7 == -0x7febfeff) {
          *(undefined4 *)(param_1 + 0xf8) = 2;
          iVar7 = 0;
        }
        else if (iVar7 == -0x7febfefe) {
          *(undefined4 *)(param_1 + 0xf8) = 3;
          iVar7 = 0;
        }
        else {
          if (iVar7 == 0x140001) {
            *(undefined4 *)(param_1 + 0xf8) = 4;
          }
          if (iVar7 < 0) break;
        }
        uVar5 = ((local_30 & 3) * -0x40000 ^ (uint)pvVar8) & 0xc0000 ^ (uint)pvVar8;
        if ((uVar5 & 0xc0000) == 0x100000) {
          uVar5 = uVar5 & 0xfff3ffff;
        }
        uVar5 = (uVar5 ^ local_30) & 0x3ffff ^ uVar5;
        if (iVar7 == 0x140001) {
          pvVar8 = (void *)(uVar5 & 0xfffff | 0xffa00000);
        }
        else {
          iVar3 = *(int *)(param_1 + 0xf8);
          if ((iVar3 == 2) || (iVar3 == 3)) {
            local_2c = (void *)0x0;
            local_30 = 0;
            iVar4 = 0xffb;
            if (iVar3 != 2) {
              iVar4 = 0xffc;
            }
            pvVar8 = (void *)(iVar4 << 0x14);
          }
          else {
            uVar1 = *(ushort *)(param_1 + 0x114);
            *(ushort *)(param_1 + 0x114) = uVar1 + 1;
            pvVar8 = (void *)((uint)uVar1 << 0x14 | uVar5 & 0xfffff);
          }
        }
        iVar3 = ((uint)pvVar8 >> 0x12 & 3) + local_30;
        uVar5 = iVar3 + 4;
        if (uVar9 < uVar5) {
          if (*(uint *)(param_1 + 0xfc) < uVar5) {
            if (*(void **)(param_1 + 0x110) != (void *)0x0) {
              operator_delete(*(void **)(param_1 + 0x110));
            }
            uVar6 = iVar3 + 0x404U & 0xfffffc00;
            pvVar2 = operator_new(uVar6);
            *(void **)(param_1 + 0x110) = pvVar2;
            if (pvVar2 == (void *)0x0) {
              iVar7 = -0x7ff8fff2;
              break;
            }
            *(uint *)(param_1 + 0xfc) = uVar6;
          }
          memset(*(void **)(param_1 + 0x110),0,*(size_t *)(param_1 + 0xfc));
          **(uint **)(param_1 + 0x110) = (uint)pvVar8;
          if ((local_2c != (void *)0x0) && (local_30 != 0)) {
            memcpy((void *)(*(int *)(param_1 + 0x110) + 4),local_2c,local_30);
          }
          *(undefined4 *)(param_1 + 0x104) = 0;
          *(uint *)(param_1 + 0x100) = uVar5;
        }
        else {
          memset(param_2,0,uVar5);
          *param_2 = (uint)pvVar8;
          if ((local_2c != (void *)0x0) && (local_30 != 0)) {
            memcpy(param_2 + 1,local_2c,local_30);
          }
          param_2 = (uint *)(uVar5 + (int)param_2);
          uVar9 = uVar9 - uVar5;
        }
      }
    }
    *param_4 = param_3 - uVar9;
    if ((iVar7 < 0) || (iVar7 == 0x140001)) {
      *(int *)(param_1 + 0x18) = iVar7;
      if (iVar7 == 0x140001) {
        *(undefined4 *)(param_1 + 0xf8) = 5;
      }
      else if ((iVar7 == -0x7febfeff) || (iVar7 == -0x7febfefe)) {
        iVar7 = 0;
      }
      (**(code **)(**(int **)(param_1 + 8) + 0x10))(*(int **)(param_1 + 8),param_1 + 0xc);
      (**(code **)(**(int **)(param_1 + 0xe4) + 0xc))(*(int **)(param_1 + 0xe4),param_1 + 0xc);
      FUN_00012720(param_1);
    }
    if (iVar7 < 0) {
      return iVar7;
    }
  }
  else if (iVar3 == 5) {
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  else if (iVar3 != 7) {
    return -0x7fff0001;
  }
  return 0;
}



/* 00012dcc FUN_00012dcc */

/* Boundary evidence: original MIPS .pdata 00012dcc..000131c3. Semantic name remains unreviewed. */

int FUN_00012dcc(int param_1,uint *param_2,uint param_3,int *param_4)

{
  bool bVar1;
  void *pvVar2;
  undefined4 uVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  
  iVar6 = *(int *)(param_1 + 0xf8);
  iVar8 = 0;
  bVar1 = false;
  uVar7 = param_3;
  if ((iVar6 == 6) || (iVar6 == 7)) {
    do {
      do {
        uVar9 = 0;
        if (uVar7 == 0) goto LAB_00013108;
        uVar10 = *(uint *)(param_1 + 0x108);
        if (uVar10 == 0) {
          puVar11 = param_2;
          if (uVar7 < 4) {
            uVar10 = 4;
            *(undefined4 *)(param_1 + 0x10c) = 1;
          }
          else {
            uVar10 = (*param_2 >> 0x12 & 3) + (*param_2 & 0x3ffff) + 4;
            if (uVar10 <= uVar7) {
              puVar11 = param_2 + 1;
              uVar9 = uVar7;
              puVar12 = param_2;
              goto LAB_00012f50;
            }
          }
LAB_00013084:
          if (*(uint *)(param_1 + 0xfc) < uVar10) {
            if (*(void **)(param_1 + 0x110) != (void *)0x0) {
              operator_delete(*(void **)(param_1 + 0x110));
            }
            uVar9 = uVar10 + 0x400 & 0xfffffc00;
            pvVar2 = operator_new(uVar9);
            *(void **)(param_1 + 0x110) = pvVar2;
            if (pvVar2 != (void *)0x0) {
              *(uint *)(param_1 + 0xfc) = uVar9;
              goto LAB_000130e8;
            }
            *(undefined4 *)(param_1 + 0x18) = 0x8007000e;
            iVar8 = -0x7febfeff;
            bVar1 = true;
          }
          else {
LAB_000130e8:
            memcpy(*(void **)(param_1 + 0x110),puVar11,uVar7);
            *(uint *)(param_1 + 0x100) = uVar7;
            *(uint *)(param_1 + 0x108) = uVar10 - uVar7;
          }
          uVar9 = 0;
          goto LAB_00013108;
        }
        if (uVar7 <= uVar10) {
          uVar10 = uVar7;
        }
        memcpy((void *)(*(int *)(param_1 + 0x110) + *(int *)(param_1 + 0x100)),param_2,uVar10);
        iVar6 = *(int *)(param_1 + 0x108) - uVar10;
        puVar11 = (uint *)(uVar10 + (int)param_2);
        uVar9 = uVar7 - uVar10;
        *(uint *)(param_1 + 0x100) = uVar10 + *(int *)(param_1 + 0x100);
        *(int *)(param_1 + 0x108) = iVar6;
        param_2 = puVar11;
        uVar7 = uVar9;
      } while (iVar6 != 0);
      param_2 = *(uint **)(param_1 + 0x110);
      if (*(int *)(param_1 + 0x10c) == 0) {
        puVar5 = param_2 + 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x10c) = 0;
        uVar10 = (*param_2 >> 0x12 & 3) + (*param_2 & 0x3ffff);
        puVar12 = puVar11;
        if (uVar9 < uVar10) goto LAB_00013084;
LAB_00012f50:
        uVar9 = uVar9 - uVar10;
        puVar5 = puVar11;
        puVar11 = (uint *)(uVar10 + (int)puVar12);
      }
      uVar7 = *param_2 >> 0x14;
      if (uVar7 == 0xffb) {
LAB_00013070:
        iVar8 = -0x7febfeff;
        goto LAB_00013074;
      }
      if (uVar7 == 0xffc) {
        iVar8 = -0x7febfefe;
        goto LAB_00013074;
      }
      if ((uVar7 != 0xffa) && (uVar7 != *(ushort *)(param_1 + 0x114))) {
        *(undefined4 *)(param_1 + 0xf8) = 7;
        iVar8 = -0x7febfeff;
      }
      *(short *)(param_1 + 0x114) = *(short *)(param_1 + 0x114) + 1;
      if ((*param_2 & 0x3ffff) == 0) goto LAB_00013070;
      if (*(int *)(param_1 + 0xf8) != 7) {
        iVar6 = (**(code **)(**(int **)(param_1 + 8) + 0x18))(*(int **)(param_1 + 8),puVar5);
        *(int *)(param_1 + 0x18) = iVar6;
        if (iVar6 < 0) {
          *(undefined4 *)(param_1 + 0xf8) = 7;
          if (iVar6 == -0x7ff8fff2) {
            iVar8 = -0x7febfeff;
            goto LAB_00013074;
          }
          iVar8 = 0;
        }
      }
      uVar10 = *param_2;
      param_2 = puVar11;
      uVar7 = uVar9;
    } while ((uVar10 & 0xfff00000) != 0xffa00000);
    if (((*(int *)(param_1 + 0xf8) == 7) && (iVar8 != -0x7febfeff)) && (iVar8 != -0x7febfefe)) {
      iVar8 = -0x7febff00;
    }
LAB_00013074:
    bVar1 = true;
LAB_00013108:
    *param_4 = param_3 - uVar9;
    if (bVar1) {
      piVar4 = *(int **)(param_1 + 8);
      if ((piVar4 != (int *)0x0) &&
         (uVar3 = (**(code **)(*piVar4 + 0x10))(piVar4,param_1 + 0xc), -1 < *(int *)(param_1 + 0x18)
         )) {
        *(undefined4 *)(param_1 + 0x18) = uVar3;
      }
      piVar4 = *(int **)(param_1 + 0xe4);
      if (piVar4 != (int *)0x0) {
        if (-1 < *(int *)(param_1 + 0x18)) {
          *(int *)(param_1 + 0x18) = iVar8;
        }
        (**(code **)(*piVar4 + 0xc))(piVar4,param_1 + 0xc);
      }
      iVar8 = -0x7ffcff90;
      *(undefined4 *)(param_1 + 0xf8) = 8;
      FUN_00012720(param_1);
    }
    if (iVar8 < 0) {
      return iVar8;
    }
  }
  else {
    if (iVar6 != 8) {
      return -0x7fff0001;
    }
    *param_4 = 0;
  }
  return 0;
}



/* 000131c4 FUN_000131c4 */

/* Boundary evidence: original MIPS .pdata 000131c4..0001324f. Semantic name remains unreviewed. */

undefined4 *
FUN_000131c4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4,void *param_5)

{
  param_1[0x25] = param_2;
  param_1[0x26] = param_3;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x24] = 0;
  param_1[0x27] = (param_1[0x27] ^ param_4) & 1 ^ param_1[0x27];
  param_1[0x28] = 0xffffffff;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  memset(param_1 + 4,0,0x80);
  memcpy(param_1 + 0x29,param_5,0x20);
  return param_1;
}



/* 00013250 FUN_00013250 */

/* Boundary evidence: original MIPS .pdata 00013250..0001329f. Semantic name remains unreviewed. */

bool FUN_00013250(HWND param_1,HWND param_2)

{
  HWND pHVar1;
  
  pHVar1 = GetParent(param_1);
  if (pHVar1 == param_2) {
    SetForegroundWindow(param_1);
  }
  return pHVar1 != param_2;
}



/* 000132a0 FUN_000132a0 */

/* Boundary evidence: original MIPS .pdata 000132a0..00013323. Semantic name remains unreviewed. */

void FUN_000132a0(void)

{
  WCHAR aWStack_2e8 [64];
  WCHAR aWStack_268 [300];
  uint local_10;
  
  local_10 = DAT_0001d244;
  LoadStringW(DAT_0001d344,0x7d9,aWStack_2e8,0x40);
  LoadStringW(DAT_0001d344,0x7da,aWStack_268,300);
  DAT_0001d460 = 1;
  MessageBoxW((HWND)0x0,aWStack_268,aWStack_2e8,0x10010);
  DAT_0001d460 = 0;
  FUN_0001c2c0(local_10);
  return;
}



/* 00013324 FUN_00013324 */

/* Boundary evidence: original MIPS .pdata 00013324..0001336b. Semantic name remains unreviewed. */

void FUN_00013324(HKEY param_1,LPCWSTR param_2,PHKEY param_3)

{
  DWORD aDStack_10 [2];
  
  RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,param_3,
                  aDStack_10);
  return;
}



/* 0001336c FUN_0001336c */

/* Boundary evidence: original MIPS .pdata 0001336c..000133a7. Semantic name remains unreviewed. */

void FUN_0001336c(HKEY param_1,LPCWSTR param_2,undefined4 param_3)

{
  undefined4 local_res8 [2];
  
  local_res8[0] = param_3;
  RegSetValueExW(param_1,param_2,0,4,(BYTE *)local_res8,4);
  return;
}



/* 000133a8 FUN_000133a8 */

/* Boundary evidence: original MIPS .pdata 000133a8..000133e3. Semantic name remains unreviewed. */

void FUN_000133a8(HKEY param_1,LPCWSTR param_2,LPBYTE param_3)

{
  DWORD local_10 [2];
  
  local_10[0] = 4;
  RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,param_3,local_10);
  return;
}



/* 000133e4 FUN_000133e4 */

/* Boundary evidence: original MIPS .pdata 000133e4..000134a3. Semantic name remains unreviewed. */

LSTATUS FUN_000133e4(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,LPBYTE param_4)

{
  LSTATUS LVar1;
  HKEY local_18;
  DWORD local_14;
  
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_18,&local_14);
  if (LVar1 == 0) {
    local_14 = 4;
    LVar1 = RegQueryValueExW(local_18,param_3,(LPDWORD)0x0,(LPDWORD)0x0,param_4,&local_14);
    RegCloseKey(local_18);
  }
  return LVar1;
}



/* 000134a4 FUN_000134a4 */

/* Boundary evidence: original MIPS .pdata 000134a4..0001359b. Semantic name remains unreviewed. */

void FUN_000134a4(int param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 8) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      DVar1 = GetTickCount();
      DVar2 = GetTickCount();
      uVar4 = DVar2 - DVar1;
      while ((uVar4 < 900000 && (iVar3 = (**(code **)(param_1 + 0xc))(0,0,0), iVar3 == 0))) {
        Sleep(2000);
        DVar2 = GetTickCount();
        uVar4 = DVar2 - DVar1;
      }
    }
    FreeLibrary(*(HMODULE *)(param_1 + 8));
  }
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    free(*(void **)(param_1 + 4));
  }
  return;
}



/* 0001359c FUN_0001359c */

/* Boundary evidence: original MIPS .pdata 0001359c..00013693. Semantic name remains unreviewed. */

undefined4 FUN_0001359c(int param_1,LPCWSTR param_2)

{
  HMODULE pHVar1;
  wchar_t *pwVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = 0x80004005;
  pHVar1 = LoadLibraryW(param_2);
  *(HMODULE *)(param_1 + 8) = pHVar1;
  if (pHVar1 != (HMODULE)0x0) {
    pwVar2 = _wcsdup(param_2);
    *(wchar_t **)(param_1 + 4) = pwVar2;
    iVar3 = GetProcAddressW(*(undefined4 *)(param_1 + 8),L"ObjectNotify");
    *(int *)(param_1 + 0x10) = iVar3;
    if (iVar3 != 0) {
      iVar3 = GetProcAddressW(*(undefined4 *)(param_1 + 8),L"InitObjType");
      *(int *)(param_1 + 0xc) = iVar3;
      if (iVar3 != 0) {
        iVar3 = GetProcAddressW(*(undefined4 *)(param_1 + 8),L"GetObjTypeInfo");
        *(int *)(param_1 + 0x14) = iVar3;
        if (iVar3 != 0) {
          uVar5 = GetProcAddressW(*(undefined4 *)(param_1 + 8),L"ReportStatus");
          *(undefined4 *)(param_1 + 0x18) = uVar5;
          uVar5 = GetProcAddressW(*(undefined4 *)(param_1 + 8),L"FindObjects");
          *(undefined4 *)(param_1 + 0x1c) = uVar5;
          uVar4 = GetProcAddressW(*(undefined4 *)(param_1 + 8),L"SyncData");
          uVar5 = 0;
          *(undefined4 *)(param_1 + 0x20) = uVar4;
        }
      }
    }
  }
  return uVar5;
}



/* 00013694 FUN_00013694 */

/* Boundary evidence: original MIPS .pdata 00013694..000136e7. Semantic name remains unreviewed. */

void FUN_00013694(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if ((void *)*param_1 == (void *)0x0) {
      return;
    }
    operator_delete((void *)*param_1);
    uVar1 = uVar1 + 1;
    param_1 = param_1 + 2;
  } while (uVar1 < 0xf);
  return;
}



/* 000136e8 FUN_000136e8 */

void FUN_000136e8(int param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  
  if ((param_2 == 0) || (0xf < param_2)) {
    *param_3 = 0;
    *param_4 = 0;
  }
  else {
    iVar1 = param_2 * 8 + param_1;
    *param_3 = *(undefined4 *)(iVar1 + -8);
    *param_4 = (uint)*(ushort *)(iVar1 + -4);
  }
  return;
}



/* 00013728 FUN_00013728 */

/* Boundary evidence: original MIPS .pdata 00013728..000137f3. Semantic name remains unreviewed. */

int FUN_00013728(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  if (*param_1 == 0) {
    iVar1 = 0;
  }
  else {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = param_2;
    }
    piVar2 = param_3 + 2;
    uVar3 = 0;
    do {
      if (*param_1 == 0) break;
      if (param_3 != (undefined4 *)0x0) {
        *(char *)(param_3 + 1) = *(char *)(param_3 + 1) + '\x01';
        *piVar2 = *param_1;
        piVar2[1] = param_1[1];
        memcpy(piVar2 + 2,(void *)*param_1,(uint)*(ushort *)(param_1 + 1));
      }
      uVar3 = uVar3 + 1;
      piVar2 = (int *)((int)piVar2 + *(ushort *)(param_1 + 1) + 8);
      param_1 = param_1 + 2;
    } while (uVar3 < 0xf);
    iVar1 = (int)piVar2 - (int)param_3;
  }
  return iVar1;
}



/* 000137f4 FUN_000137f4 */

/* Boundary evidence: original MIPS .pdata 000137f4..000138f3. Semantic name remains unreviewed. */

int FUN_000137f4(int *param_1,void *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_2 == (void *)0x0) {
    return 0;
  }
  uVar2 = 0;
  do {
    if (((void *)*param_1 == (void *)0x0) ||
       ((*(ushort *)(param_1 + 1) == param_3 &&
        (iVar1 = memcmp((void *)*param_1,param_2,(uint)*(ushort *)(param_1 + 1)), iVar1 == 0))))
    break;
    uVar2 = uVar2 + 1;
    param_1 = param_1 + 2;
  } while (uVar2 < 0xf);
  if (uVar2 < 0xf) {
    if (*param_1 == 0) {
      _Dst = operator_new(param_3);
      *param_1 = (int)_Dst;
      if (_Dst == (void *)0x0) goto LAB_00013884;
      *(short *)(param_1 + 1) = (short)param_3;
      memcpy(_Dst,param_2,param_3 & 0xffff);
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 1;
      }
    }
    iVar1 = uVar2 + 1;
  }
  else {
LAB_00013884:
    iVar1 = -1;
  }
  return iVar1;
}



/* 000138f4 FUN_000138f4 */

/* Boundary evidence: original MIPS .pdata 000138f4..00013977. Semantic name remains unreviewed. */

undefined4 * FUN_000138f4(undefined4 *param_1)

{
  memset(param_1 + 1,0,200);
  param_1[0x33] = 0xffffffff;
  param_1[0x34] = 0;
  *param_1 = &PTR_FUN_00011664;
  memset(param_1 + 0x6d,0,0x78);
  param_1[0x36] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  memset(param_1 + 0x37,0,200);
  return param_1;
}



/* 00013978 FUN_00013978 */

/* Boundary evidence: original MIPS .pdata 00013978..000139e3. Semantic name remains unreviewed. */

void FUN_00013978(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00011664;
  if ((int *)param_1[0x36] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x36] + 8))();
  }
  if ((void *)param_1[0x6c] != (void *)0x0) {
    operator_delete((void *)param_1[0x6c]);
  }
  FUN_00013694(param_1 + 0x6d);
  *param_1 = &PTR_FUN_00011618;
  return;
}



/* 000139e4 FUN_000139e4 */

/* Boundary evidence: original MIPS .pdata 000139e4..00013bb7. Semantic name remains unreviewed. */

undefined4 FUN_000139e4(void)

{
  HMODULE hLibModule;
  code *pcVar1;
  int iVar2;
  DWORD DVar3;
  HANDLE hHandle;
  int *local_20;
  int *local_1c;
  DWORD aDStack_18 [2];
  
  local_20 = (int *)0x0;
  hHandle = (HANDLE)0x0;
  hLibModule = LoadLibraryW(L"rra_stm.dll");
  if (hLibModule != (HMODULE)0x0) {
    hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000196bc,(LPVOID)0x0,0,aDStack_18);
    if (hHandle != (HANDLE)0x0) {
      pcVar1 = (code *)GetProcAddressW(hLibModule,L"DllGetClassObject");
      if (((pcVar1 != (code *)0x0) &&
          (iVar2 = (*pcVar1)(&UNK_0001104c,&UNK_00011ac0,&local_1c), -1 < iVar2)) &&
         (iVar2 = (**(code **)(*local_1c + 0xc))(local_1c,0,&DAT_0001108c,&local_20), -1 < iVar2)) {
        (**(code **)(*local_20 + 0xc))(local_20,DAT_0001d314 + 0x80);
      }
      goto LAB_00013ae0;
    }
  }
  FUN_000132a0();
LAB_00013ae0:
  if (DAT_0001d468 != 0) {
    InterlockedExchange((LONG *)(DAT_0001d468 + 0xc),1);
    EventModify(*(undefined4 *)(DAT_0001d468 + 8),3);
  }
  if (hHandle != (HANDLE)0x0) {
    DVar3 = WaitForSingleObject(hHandle,40000);
    if (DVar3 == 0x102) {
      TerminateThread(hHandle,0);
    }
    CloseHandle(hHandle);
  }
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))();
  }
  if (hLibModule != (HMODULE)0x0) {
    FreeLibrary(hLibModule);
  }
  PostMessageW(DAT_0001d25c,0x4ca,0,1);
  return 0;
}



/* 00013bb8 FUN_00013bb8 */

/* Boundary evidence: original MIPS .pdata 00013bb8..00013c13. Semantic name remains unreviewed. */

undefined4 FUN_00013bb8(HWND param_1,int param_2,short param_3)

{
  HWND pHVar1;
  
  pHVar1 = param_1;
  if (((param_2 != 0x110) && (pHVar1 = DAT_0001d2fc, param_2 == 0x111)) && (param_3 == 1)) {
    DAT_0001d2fc = (HWND)0x0;
    EndDialog(param_1,1);
    pHVar1 = DAT_0001d2fc;
  }
  DAT_0001d2fc = pHVar1;
  return 0;
}



/* 00013c14 FUN_00013c14 */

/* Boundary evidence: original MIPS .pdata 00013c14..00013c93. Semantic name remains unreviewed. */

undefined4 FUN_00013c14(void)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  
  if (DAT_0001d2fc == 0) {
    hResInfo = FindResourceW(DAT_0001d344,(LPCWSTR)0x71,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_0001d344,hResInfo);
    DialogBoxIndirectParamW(DAT_0001d344,hDialogTemplate,DAT_0001d25c,FUN_00013bb8,0);
  }
  return 0;
}



/* 00013c94 FUN_00013c94 */

/* Boundary evidence: original MIPS .pdata 00013c94..00013d4b. Semantic name remains unreviewed. */

undefined4 FUN_00013c94(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  
  *param_3 = 0;
  iVar1 = memcmp(param_2,&DAT_00011ab0,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_000110ac,0x10), iVar1 == 0)) {
    *param_3 = param_1;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_000110cc,0x10);
    if (iVar1 != 0) {
      return 0x80004002;
    }
    iVar1 = param_1 + 4;
    if (param_1 == 0) {
      iVar1 = 0;
    }
    *param_3 = iVar1;
  }
  return 0;
}



/* 00013d4c FUN_00013d4c */

/* Boundary evidence: original MIPS .pdata 00013d4c..00013ebf. Semantic name remains unreviewed. */

undefined4
FUN_00013d4c(int param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,int param_6,
            int param_7,int param_8)

{
  DWORD DVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = (param_3 & 0xf | 0x40) << 0x14;
  if (param_7 != 0) {
    uVar4 = uVar4 | 0x2000000;
  }
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x18),60000);
  if ((DVar1 == 0) && (DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x14),60000), DVar1 == 0))
  {
    if ((param_5 == 0) && (param_4 == 0)) {
      if (param_7 == 0) {
        return 0;
      }
      uVar2 = (**(code **)(**(int **)(param_1 + 0x20) + 0xc))
                        (*(int **)(param_1 + 0x20),param_2,0,0,0,uVar4);
      return uVar2;
    }
    if ((((param_8 != 0) && (param_5 < 0x20)) && (param_4 != 0)) && (param_6 != 0)) {
      memmove((void *)(param_5 * 4 + param_6),(void *)(param_6 + 0x80),param_4 << 2);
    }
    piVar3 = *(int **)(param_1 + 0x20);
    if (piVar3 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar3 + 0xc))(piVar3,param_2,param_4,param_5,param_6,uVar4);
      return uVar2;
    }
  }
  return 0x80141001;
}



/* 00013ec0 FUN_00013ec0 */

/* Boundary evidence: original MIPS .pdata 00013ec0..00013f43. Semantic name remains unreviewed. */

void FUN_00013ec0(SOCKET *param_1)

{
  SOCKET *pSVar1;
  int iVar2;
  
  iVar2 = 2;
  pSVar1 = param_1;
  do {
    pSVar1 = pSVar1 + 1;
    if (*pSVar1 != 0xffffffff) {
      closesocket(*pSVar1);
      *pSVar1 = 0xffffffff;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



/* 00013f44 FUN_00013f44 */

/* Boundary evidence: original MIPS .pdata 00013f44..00013f6f. Semantic name remains unreviewed. */

void FUN_00013f44(void)

{
  (**(code **)*DAT_0001d314)();
  return;
}



/* 00013f70 FUN_00013f70 */

/* Boundary evidence: original MIPS .pdata 00013f70..00013ff7. Semantic name remains unreviewed. */

undefined4 FUN_00013f70(SOCKET *param_1,short *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*param_2 == 1) {
    FUN_00013ec0(param_1);
    WSACleanup();
  }
  if ((*param_2 == 3) && (iVar1 = EventModify(*(undefined4 *)(DAT_0001d314 + 0x14),3), iVar1 == 0))
  {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 00013ff8 FUN_00013ff8 */

/* Boundary evidence: original MIPS .pdata 00013ff8..0001424f. Semantic name remains unreviewed. */

undefined4 FUN_00013ff8(SOCKET *param_1,SOCKET *param_2)

{
  int iVar1;
  SOCKET SVar2;
  int iVar3;
  SOCKET *pSVar4;
  undefined4 uVar5;
  SOCKET *pSVar6;
  undefined2 local_248;
  undefined2 local_246;
  sockaddr local_240 [8];
  WSADATA WStack_1c0;
  uint local_30;
  
  local_30 = DAT_0001d244;
  uVar5 = 0x80004005;
  if (param_1[4] == 0) {
    iVar1 = WSAStartup(0x202,&WStack_1c0);
    if (iVar1 == 0) {
      memcpy(local_240,&DAT_0001d260,0x80);
      FUN_00019a4c((short *)local_240,0x162e);
      pSVar6 = param_1 + 1;
      iVar1 = 0;
      pSVar4 = pSVar6;
      do {
        SVar2 = socket(2,1,0);
        *pSVar4 = SVar2;
        if (SVar2 == 0xffffffff) goto LAB_0001420c;
        local_248 = 1;
        local_246 = 0;
        iVar3 = setsockopt(SVar2,0xffff,0x80,(char *)&local_248,4);
        if (iVar3 != 0) goto LAB_0001420c;
        iVar1 = iVar1 + 1;
        pSVar4 = pSVar4 + 1;
      } while (iVar1 < 2);
      iVar1 = connect(*pSVar6,local_240,0x80);
      while (iVar1 == -1) {
        iVar1 = WSAGetLastError();
        closesocket(*pSVar6);
        if ((iVar1 != 0x274d) && (iVar1 != 0x274c)) goto LAB_0001420c;
        SVar2 = socket((int)(short)local_240[0].sa_family,1,0);
        *pSVar6 = SVar2;
        if (SVar2 == 0xffffffff) goto LAB_0001420c;
        iVar1 = connect(SVar2,local_240,0x80);
      }
      iVar1 = 1;
      pSVar4 = param_1 + 2;
      do {
        iVar3 = connect(*pSVar4,local_240,0x80);
        if (iVar3 == -1) goto LAB_0001420c;
        iVar1 = iVar1 + 1;
        pSVar4 = pSVar4 + 1;
      } while (iVar1 < 2);
      uVar5 = 0;
      *param_2 = *pSVar6;
      param_1[4] = 1;
      goto LAB_00014214;
    }
  }
  else if (param_1[4] == 1) {
    *param_2 = param_1[2];
    uVar5 = 0;
    param_1[4] = 2;
    goto LAB_00014214;
  }
LAB_0001420c:
  FUN_00013ec0(param_1);
LAB_00014214:
  FUN_0001c2c0(local_30);
  return uVar5;
}



/* 00014250 FUN_00014250 */

/* Boundary evidence: original MIPS .pdata 00014250..000142e7. Semantic name remains unreviewed. */

undefined4 FUN_00014250(HWND param_1)

{
  BOOL BVar1;
  tagMSG tStack_30;
  
  BVar1 = PeekMessageW(&tStack_30,param_1,0x471,0x471,0);
  if ((BVar1 == 0) && (BVar1 = PeekMessageW(&tStack_30,param_1,0x46f,0x46f,0), BVar1 == 0)) {
    return 0;
  }
  do {
    BVar1 = PeekMessageW(&tStack_30,param_1,0x4ca,0x4ca,1);
  } while (BVar1 != 0);
  return 1;
}



/* 000142e8 FUN_000142e8 */

/* Boundary evidence: original MIPS .pdata 000142e8..00014353. Semantic name remains unreviewed. */

bool FUN_000142e8(HINSTANCE param_1)

{
  DAT_0001d344 = param_1;
  DAT_0001d25c = CreateWindowExW(0,L"ReplLog",L"ReplLog",0x80000000,0,0,0,0,(HWND)0x0,(HMENU)0x0,
                                 param_1,(LPVOID)0x0);
  return DAT_0001d25c != (HWND)0x0;
}



/* 00014354 FUN_00014354 */

/* Boundary evidence: original MIPS .pdata 00014354..000143f3. Semantic name remains unreviewed. */

int FUN_00014354(SOCKET param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = -1;
  iVar2 = 0;
  if (param_3 != -1) {
    do {
      iVar1 = recv(param_1,(char *)(iVar2 + param_2),param_3 - iVar2,0);
      if ((iVar1 == -1) || (iVar1 == 0)) {
        return 0;
      }
      iVar2 = iVar2 + iVar1;
    } while (iVar1 != param_3);
  }
  return iVar1;
}



/* 000143f4 FUN_000143f4 */

/* Boundary evidence: original MIPS .pdata 000143f4..0001448f. Semantic name remains unreviewed. */

undefined4 FUN_000143f4(HWND param_1,undefined4 *param_2)

{
  int iVar1;
  LONG LVar2;
  undefined4 uVar3;
  WCHAR aWStack_58 [32];
  uint local_18;
  
  local_18 = DAT_0001d244;
  GetClassNameW(param_1,aWStack_58,0x20);
  iVar1 = wcscmp(aWStack_58,L"Dialog");
  if ((iVar1 == 0) && (LVar2 = GetWindowLongW(param_1,8), LVar2 == 0x6a6d6d)) {
    *param_2 = param_1;
    FUN_0001c2c0(local_18);
    uVar3 = 0;
  }
  else {
    FUN_0001c2c0(local_18);
    uVar3 = 1;
  }
  return uVar3;
}



/* 00014490 FUN_00014490 */

/* Boundary evidence: original MIPS .pdata 00014490..000145bb. Semantic name remains unreviewed. */

void FUN_00014490(void)

{
  bool bVar1;
  LSTATUS LVar2;
  HKEY local_20;
  DWORD local_1c;
  DWORD aDStack_18 [2];
  
  local_1c = 0x100;
  bVar1 = false;
  local_20 = (HKEY)0x0;
  if (DAT_0001d30c != 0) {
    return;
  }
  if (DAT_0001d450 == 0) {
    LVar2 = RegCreateKeyExW((HKEY)0x80000001,L"ControlPanel\\Comm",0,(LPWSTR)0x0,0,0xf003f,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_20,aDStack_18);
    if ((LVar2 != 0) ||
       (LVar2 = RegQueryValueExW(local_20,L"Cnct",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&DAT_0001d34c,
                                 &local_1c), LVar2 != 0)) {
      bVar1 = true;
    }
    if (DAT_0001d34c == 0) {
      bVar1 = true;
    }
    if (bVar1) {
      wcscpy(&DAT_0001d34c,L"Direct");
    }
    return;
  }
  LoadStringW(DAT_0001d344,0x806,&DAT_0001d34c,0x80);
  return;
}



/* 000145bc FUN_000145bc */

/* Boundary evidence: original MIPS .pdata 000145bc..00014803. Semantic name remains unreviewed. */

undefined4 FUN_000145bc(void)

{
  bool bVar1;
  LSTATUS LVar2;
  int iVar3;
  UINT UVar4;
  int local_148;
  HKEY local_144;
  DWORD local_140 [2];
  timeval local_138;
  fd_set local_130;
  
  local_140[0] = 0x3c;
  bVar1 = true;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Windows CE Services",0,0x20019,
                        &local_144);
  if (LVar2 == 0) {
    local_138.tv_sec = 4;
    RegQueryValueExW(local_144,L"RasTimeoutResponse",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_140,
                     (LPDWORD)&local_138);
    RegCloseKey(local_144);
  }
  if (DAT_0001d24c != 0xffffffff) {
    DAT_0001d2e0 = 1;
    if (DAT_0001d474 != 0) {
      EventModify(DAT_0001d474,3);
    }
    while (DAT_0001d24c != 0xffffffff) {
      local_130.fd_count = 1;
      local_138.tv_usec = 0;
      local_138.tv_sec = local_140[0];
      local_130.fd_array[0] = DAT_0001d24c;
      iVar3 = select(0,&local_130,(fd_set *)0x0,(fd_set *)0x0,&local_138);
      if ((iVar3 != 1) || (iVar3 = recv(DAT_0001d24c,(char *)&local_148,4,0), iVar3 != 4)) break;
      if (local_148 == 1) {
        UVar4 = 0x7ec;
LAB_0001478c:
        FUN_00019fcc(UVar4);
        bVar1 = false;
        break;
      }
      if (local_148 == 2) {
        UVar4 = 0x7e8;
        goto LAB_0001478c;
      }
      if (local_148 == 3) {
        UVar4 = 0x7e9;
        goto LAB_0001478c;
      }
      if (local_148 == 4) {
        UVar4 = 0x7fd;
        goto LAB_0001478c;
      }
      send(DAT_0001d24c,(char *)&local_148,4,0);
    }
  }
  DAT_0001d2e0 = 0;
  if (DAT_0001d474 != 0) {
    EventModify(DAT_0001d474,3);
  }
  if (bVar1) {
    PostMessageW(DAT_0001d25c,0x4ca,1,0);
  }
  return 0;
}



/* 00014804 FUN_00014804 */

/* Boundary evidence: original MIPS .pdata 00014804..0001494b. Semantic name remains unreviewed. */

undefined4 FUN_00014804(void)

{
  int iVar1;
  BOOL BVar2;
  HANDLE hThread;
  undefined4 uVar3;
  undefined4 local_430;
  DWORD DStack_42c;
  WCHAR local_428;
  undefined1 auStack_426 [518];
  WCHAR aWStack_220 [9];
  undefined1 auStack_20e [502];
  uint local_18;
  
  local_18 = DAT_0001d244;
  uVar3 = 0;
  local_430 = 0;
  local_428 = L'\0';
  memset(auStack_426,0,0x206);
  memcpy(aWStack_220,L"Resuming",0x12);
  memset(auStack_20e,0,0x1f6);
  GetSystemPowerState(&local_428,0x104,&local_430);
  iVar1 = lstrcmpiW(aWStack_220,&local_428);
  if (iVar1 == 0) {
    SetSystemPowerState(0,0x10000);
  }
  BVar2 = CreateProcessW(L"udp2tcp.exe",(LPWSTR)0x0,(LPSECURITY_ATTRIBUTES)0x0,
                         (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0
                         ,(LPPROCESS_INFORMATION)0x0);
  if (BVar2 != 0) {
    hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000145bc,(LPVOID)0x0,0,&DStack_42c);
    if (hThread != (HANDLE)0x0) {
      uVar3 = 1;
      SetThreadPriority(hThread,1);
      CloseHandle(hThread);
    }
  }
  FUN_0001c2c0(local_18);
  return uVar3;
}



/* 0001494c FUN_0001494c */

/* Boundary evidence: original MIPS .pdata 0001494c..000149ef. Semantic name remains unreviewed. */

undefined4 FUN_0001494c(void)

{
  LSTATUS LVar1;
  HKEY local_18;
  undefined4 local_14;
  DWORD local_10 [2];
  
  local_14 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Windows CE Services\\Partners",0,
                        0x20019,&local_18);
  if (LVar1 == 0) {
    local_10[0] = 4;
    RegQueryValueExW(local_18,L"PCur",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_14,local_10);
    RegCloseKey(local_18);
  }
  return local_14;
}



/* 000149f0 FUN_000149f0 */

/* Boundary evidence: original MIPS .pdata 000149f0..00014a9f. Semantic name remains unreviewed. */

undefined2 FUN_000149f0(LPBYTE param_1)

{
  LSTATUS LVar1;
  HKEY local_18;
  DWORD local_14;
  
  param_1[0] = '\0';
  param_1[1] = '\0';
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Windows CE Services\\Partners",0,
                        0x20019,&local_18);
  if (LVar1 == 0) {
    local_14 = 0x100;
    RegQueryValueExW(local_18,L"Connectoid",(LPDWORD)0x0,(LPDWORD)0x0,param_1,&local_14);
    RegCloseKey(local_18);
  }
  return *(undefined2 *)param_1;
}



/* 00014aa0 FUN_00014aa0 */

/* Boundary evidence: original MIPS .pdata 00014aa0..00014b77. Semantic name remains unreviewed. */

bool FUN_00014aa0(wchar_t *param_1)

{
  LSTATUS LVar1;
  size_t sVar2;
  bool bVar3;
  HKEY local_18 [2];
  
  bVar3 = false;
  if (DAT_0001d30c == 0) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Windows CE Services\\Partners",0,
                          0x20019,local_18);
    if (LVar1 == 0) {
      sVar2 = wcslen(param_1);
      LVar1 = RegSetValueExW(local_18[0],L"Connectoid",0,1,(BYTE *)param_1,(sVar2 + 1) * 2);
      bVar3 = LVar1 == 0;
      RegCloseKey(local_18[0]);
    }
  }
  else {
    bVar3 = true;
  }
  return bVar3;
}



/* 00014b78 FUN_00014b78 */

/* Boundary evidence: original MIPS .pdata 00014b78..00014c33. Semantic name remains unreviewed. */

undefined4 FUN_00014b78(void)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_18;
  undefined4 local_14;
  DWORD local_10 [2];
  
  local_14 = 0;
  uVar2 = DAT_0001d46c;
  if ((DAT_0001d30c == 0) &&
     (LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Windows CE Services\\Partners",0
                            ,0x20019,&local_18), uVar2 = local_14, LVar1 == 0)) {
    local_10[0] = 4;
    RegQueryValueExW(local_18,L"AutoDisc",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_14,local_10);
    RegCloseKey(local_18);
    uVar2 = local_14;
  }
  return uVar2;
}



/* 00014c34 FUN_00014c34 */

/* Boundary evidence: original MIPS .pdata 00014c34..00014d07. Semantic name remains unreviewed. */

bool FUN_00014c34(undefined4 param_1)

{
  LSTATUS LVar1;
  bool bVar2;
  HKEY local_18;
  undefined4 local_14;
  
  bVar2 = false;
  if (DAT_0001d30c == 0) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Windows CE Services\\Partners",0,
                          0x20019,&local_18);
    if (LVar1 == 0) {
      local_14 = param_1;
      LVar1 = RegSetValueExW(local_18,L"AutoDisc",0,4,(BYTE *)&local_14,4);
      bVar2 = LVar1 == 0;
      RegCloseKey(local_18);
    }
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}



/* 00014d08 FUN_00014d08 */

/* Boundary evidence: original MIPS .pdata 00014d08..00014dcf. Semantic name remains unreviewed. */

undefined4 FUN_00014d08(undefined4 param_1)

{
  LSTATUS LVar1;
  undefined4 local_120;
  HKEY local_11c;
  DWORD local_118 [2];
  WCHAR aWStack_110 [128];
  uint local_10;
  
  local_10 = DAT_0001d244;
  local_120 = 0;
  wsprintfW(aWStack_110,L"Software\\Microsoft\\Windows CE Services\\Partners\\P%d",param_1);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,aWStack_110,0,0x20019,&local_11c);
  if (LVar1 == 0) {
    local_118[0] = 4;
    RegQueryValueExW(local_11c,L"PId",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_120,local_118);
    RegCloseKey(local_11c);
  }
  FUN_0001c2c0(local_10);
  return local_120;
}



/* 00014dd0 FUN_00014dd0 */

/* Boundary evidence: original MIPS .pdata 00014dd0..00014ea3. Semantic name remains unreviewed. */

undefined2 FUN_00014dd0(undefined4 param_1,LPBYTE param_2)

{
  undefined2 uVar1;
  LSTATUS LVar2;
  HKEY local_120;
  DWORD local_11c;
  WCHAR aWStack_118 [128];
  uint local_18;
  
  local_18 = DAT_0001d244;
  param_2[0] = '\0';
  param_2[1] = '\0';
  wsprintfW(aWStack_118,L"Software\\Microsoft\\Windows CE Services\\Partners\\P%d",param_1);
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,aWStack_118,0,0x20019,&local_120);
  if (LVar2 == 0) {
    local_11c = 0x20;
    RegQueryValueExW(local_120,L"PName",(LPDWORD)0x0,(LPDWORD)0x0,param_2,&local_11c);
    RegCloseKey(local_120);
  }
  uVar1 = *(undefined2 *)param_2;
  FUN_0001c2c0(local_18);
  return uVar1;
}



/* 00014ea4 FUN_00014ea4 */

/* Boundary evidence: original MIPS .pdata 00014ea4..00014f4b. Semantic name remains unreviewed. */

undefined2 FUN_00014ea4(LPBYTE param_1)

{
  LSTATUS LVar1;
  HKEY local_10;
  DWORD local_c;
  
  param_1[0] = '\0';
  param_1[1] = '\0';
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0x20019,&local_10);
  if (LVar1 == 0) {
    local_c = 0x20;
    RegQueryValueExW(local_10,L"Name",(LPDWORD)0x0,(LPDWORD)0x0,param_1,&local_c);
    RegCloseKey(local_10);
  }
  return *(undefined2 *)param_1;
}



/* 00014f4c FUN_00014f4c */

/* Boundary evidence: original MIPS .pdata 00014f4c..00014f8f. Semantic name remains unreviewed. */

undefined4 * FUN_00014f4c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00011618;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00014f90 FUN_00014f90 */

/* Boundary evidence: original MIPS .pdata 00014f90..00014fdb. Semantic name remains unreviewed. */

undefined4 * FUN_00014f90(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000116bc;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  param_1[9] = 0;
  param_1[6] = 0;
  param_1[7] = 0xffffffff;
  param_1[8] = 0;
  return param_1;
}



/* 00014fdc FUN_00014fdc */

/* Boundary evidence: original MIPS .pdata 00014fdc..00015043. Semantic name remains unreviewed. */

undefined4 * FUN_00014fdc(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xd4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_00011618;
    memset(puVar1 + 1,0,200);
    puVar1[0x34] = 0;
    puVar1[0x33] = 0xffffffff;
  }
  return puVar1;
}



/* 00015044 FUN_00015044 */

/* Boundary evidence: original MIPS .pdata 00015044..000150a7. Semantic name remains unreviewed. */

LONG FUN_00015044(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    *param_1 = &PTR_FUN_0001162c;
    FUN_00012720((int)param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



/* 000150a8 FUN_000150a8 */

/* Boundary evidence: original MIPS .pdata 000150a8..000150f3. Semantic name remains unreviewed. */

undefined4 * FUN_000150a8(undefined4 *param_1,uint param_2)

{
  FUN_00013978(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 000150f4 FUN_000150f4 */

/* Boundary evidence: original MIPS .pdata 000150f4..000154ef. Semantic name remains unreviewed. */

int FUN_000150f4(int *param_1)

{
  int iVar1;
  int iVar2;
  LSTATUS LVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  wchar_t *_Source;
  HKEY hKey;
  HKEY local_458;
  DWORD local_454;
  DWORD local_450;
  wchar_t *local_44c;
  wchar_t *local_448;
  wchar_t awStack_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_0001d244;
  iVar1 = FUN_0001494c();
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  iVar2 = FUN_000125ac(param_1,(HKEY)0x0);
  if (-1 < iVar2) {
    hKey = (HKEY)0x0;
    if (DAT_0001d458 != 0) {
      hKey = DAT_0001d454;
    }
    if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
      local_44c = L"%s\\%s";
      local_448 = L"Objects";
      puVar8 = (undefined4 *)param_1[9];
      do {
        _Source = (wchar_t *)(puVar8 + 1);
        wsprintfW(aWStack_238,local_44c,local_448,_Source);
        RegOpenKeyExW(hKey,aWStack_238,0,0x20019,&local_458);
        local_454 = 200;
        LVar3 = RegQueryValueExW(local_458,L"Display Name",(LPDWORD)0x0,&local_450,
                                 (LPBYTE)(puVar8 + 0x37),&local_454);
        if (LVar3 != 0) {
          wcscpy((wchar_t *)(puVar8 + 0x37),_Source);
        }
        local_454 = 0x208;
        LVar3 = RegQueryValueExW(local_458,L"Store",(LPDWORD)0x0,&local_450,(LPBYTE)awStack_440,
                                 &local_454);
        if ((LVar3 != 0) || (local_450 != 1)) {
          RegCloseKey(local_458);
          iVar2 = -0x7fff0001;
          break;
        }
        RegCloseKey(local_458);
        uVar6 = 0;
        if (*(int *)(DAT_0001d314 + 0x50) != 0) {
          iVar9 = 0;
          do {
            iVar4 = _wcsicmp(*(wchar_t **)(*(int *)(*(int *)(DAT_0001d314 + 0x54) + iVar9) + 4),
                             awStack_440);
            if (iVar4 == 0) break;
            uVar6 = uVar6 + 1;
            iVar9 = iVar9 + 4;
          } while (uVar6 < *(uint *)(DAT_0001d314 + 0x50));
        }
        if (*(uint *)(DAT_0001d314 + 0x50) <= uVar6) {
          *(uint *)(DAT_0001d314 + 0x50) = *(uint *)(DAT_0001d314 + 0x50) + 1;
          if (*(uint *)(DAT_0001d314 + 0x50) < 0x40000000) {
            uVar6 = *(uint *)(DAT_0001d314 + 0x50) << 2;
          }
          else {
            uVar6 = 0xffffffff;
          }
          pvVar5 = operator_new(uVar6);
          if (pvVar5 != (void *)0x0) {
            if (*(void **)(DAT_0001d314 + 0x54) != (void *)0x0) {
              memcpy(pvVar5,*(void **)(DAT_0001d314 + 0x54),(*(int *)(DAT_0001d314 + 0x50) + -1) * 4
                    );
              operator_delete(*(void **)(DAT_0001d314 + 0x54));
            }
            *(void **)(DAT_0001d314 + 0x54) = pvVar5;
            pvVar5 = operator_new(0x24);
            if (pvVar5 == (void *)0x0) {
              pvVar5 = (void *)0x0;
            }
            else {
              *(undefined4 *)((int)pvVar5 + 4) = 0;
              *(undefined4 *)((int)pvVar5 + 8) = 0;
              *(undefined4 *)((int)pvVar5 + 0xc) = 0;
              *(undefined4 *)((int)pvVar5 + 0x10) = 0;
              *(undefined4 *)((int)pvVar5 + 0x14) = 0;
              *(undefined4 *)((int)pvVar5 + 0x18) = 0;
              *(undefined4 *)((int)pvVar5 + 0x1c) = 0;
              *(undefined4 *)((int)pvVar5 + 0x20) = 0;
            }
            *(void **)(*(int *)(DAT_0001d314 + 0x50) * 4 + *(int *)(DAT_0001d314 + 0x54) + -4) =
                 pvVar5;
            puVar8[0x35] = pvVar5;
            if (pvVar5 != (void *)0x0) {
              iVar9 = FUN_0001359c((int)pvVar5,awStack_440);
              if (-1 < iVar9) goto LAB_00015458;
              pvVar5 = (void *)puVar8[0x35];
              if (pvVar5 != (void *)0x0) {
                FUN_000134a4((int)pvVar5);
                operator_delete(pvVar5);
              }
              *(int *)(DAT_0001d314 + 0x50) = *(int *)(DAT_0001d314 + 0x50) + -1;
              goto LAB_00015418;
            }
          }
          iVar2 = -0x7ff8fff2;
          break;
        }
        puVar8[0x35] = *(undefined4 *)(*(int *)(DAT_0001d314 + 0x54) + uVar6 * 4);
LAB_00015458:
        iVar9 = (**(code **)(puVar8[0x35] + 0xc))(_Source,puVar8 + 0x36,iVar1);
        if ((iVar9 == 0) || (puVar8[0x36] == 0)) {
LAB_00015418:
          puVar7 = (undefined4 *)puVar8[0x34];
          FUN_00012234((int)param_1,puVar8,1);
        }
        else {
          puVar7 = (undefined4 *)puVar8[0x34];
        }
        puVar8 = puVar7;
      } while (puVar7 != (undefined4 *)0x0);
    }
  }
  FUN_0001c2c0(local_30);
  return iVar2;
}



/* 000154f0 FUN_000154f0 */

/* Boundary evidence: original MIPS .pdata 000154f0..00015527. Semantic name remains unreviewed. */

undefined4 * FUN_000154f0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x22c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_000138f4(puVar1);
  }
  return puVar1;
}



/* 00015528 FUN_00015528 */

/* Boundary evidence: original MIPS .pdata 00015528..0001558b. Semantic name remains unreviewed. */

undefined4 * FUN_00015528(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000116bc;
  FUN_000120ec((int)param_1,1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0001558c FUN_0001558c */

/* Boundary evidence: original MIPS .pdata 0001558c..000157bb. Semantic name remains unreviewed. */

void FUN_0001558c(undefined4 *param_1)

{
  DWORD DVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  *param_1 = &PTR_FUN_00011720;
  param_1[1] = &PTR_LAB_000116f0;
  param_1[2] = &PTR_LAB_000116e0;
  KillTimer(DAT_0001d25c,param_1[9]);
  FUN_00013ec0(param_1 + 0x20);
  if ((HANDLE)param_1[4] != (HANDLE)0x0) {
    DVar1 = WaitForSingleObject((HANDLE)param_1[4],40000);
    if (DVar1 == 0x102) {
      TerminateThread((HANDLE)param_1[4],0);
    }
    if ((HANDLE)param_1[4] != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[4]);
      param_1[4] = 0;
    }
  }
  if ((HANDLE)param_1[3] != (HANDLE)0x0) {
    DVar1 = WaitForSingleObject((HANDLE)param_1[3],40000);
    if (DVar1 == 0x102) {
      TerminateThread((HANDLE)param_1[3],0);
    }
    CloseHandle((HANDLE)param_1[3]);
  }
  puVar5 = param_1 + 0x16;
  FUN_000120ec((int)puVar5,1);
  if (param_1[0x15] != 0) {
    uVar4 = 0;
    if (param_1[0x14] != 0) {
      iVar3 = 0;
      do {
        pvVar2 = *(void **)(iVar3 + param_1[0x15]);
        if (pvVar2 != (void *)0x0) {
          FUN_000134a4((int)pvVar2);
          operator_delete(pvVar2);
        }
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 4;
      } while (uVar4 < (uint)param_1[0x14]);
    }
    operator_delete((void *)param_1[0x15]);
  }
  if ((HANDLE)param_1[7] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[7]);
  }
  if ((HANDLE)param_1[5] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[5]);
  }
  if ((HANDLE)param_1[6] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[6]);
  }
  if ((int *)param_1[8] != (int *)0x0) {
    (**(code **)(*(int *)param_1[8] + 8))();
    param_1[8] = 0;
  }
  CeRegisterReplNotification(0);
  param_1[0x6c] = &PTR_FUN_0001162c;
  FUN_00012720((int)(param_1 + 0x6c));
  param_1[0x25] = &PTR_FUN_0001162c;
  FUN_00012720((int)(param_1 + 0x25));
  *puVar5 = &PTR_FUN_000116bc;
  FUN_000120ec((int)puVar5,1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 10));
  return;
}



/* 00015818 FUN_00015818 */

/* Boundary evidence: original MIPS .pdata 00015818..0001590b. Semantic name remains unreviewed. */

int FUN_00015818(int param_1)

{
  int iVar1;
  int iVar2;
  HANDLE pvVar3;
  DWORD aDStack_18 [2];
  
  iVar1 = FUN_000150f4((int *)(param_1 + 0x58));
  if (-1 < iVar1) {
    iVar2 = CeRegisterReplNotification(&DAT_0001d2e8);
    if (iVar2 != 0) {
      pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
      *(HANDLE *)(param_1 + 0x18) = pvVar3;
      if (pvVar3 != (HANDLE)0x0) {
        pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
        *(HANDLE *)(param_1 + 0x14) = pvVar3;
        if (pvVar3 != (HANDLE)0x0) {
          pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
          *(HANDLE *)(param_1 + 0x1c) = pvVar3;
          if (pvVar3 != (HANDLE)0x0) {
            pvVar3 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000139e4,(LPVOID)0x0,0,aDStack_18
                                 );
            *(HANDLE *)(param_1 + 0xc) = pvVar3;
            if (pvVar3 != (HANDLE)0x0) {
              return iVar1;
            }
          }
        }
      }
    }
    iVar1 = -0x7fff0001;
  }
  return iVar1;
}



/* 0001590c FUN_0001590c */

/* Boundary evidence: original MIPS .pdata 0001590c..00015e27. Semantic name remains unreviewed. */

int FUN_0001590c(int param_1,int param_2,int *param_3,undefined4 param_4,undefined4 param_5,
                int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  DWORD DVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int local_350 [2];
  int aiStack_348 [4];
  undefined4 local_338;
  wchar_t awStack_334 [100];
  uint local_26c;
  undefined4 local_264;
  short local_260 [2];
  undefined4 local_25c;
  undefined4 local_258;
  uint local_40;
  uint local_3c;
  undefined4 *local_38;
  int *local_34;
  uint local_30;
  uint local_2c;
  
  local_2c = DAT_0001d244;
  iVar8 = 0;
  if (param_3 == (int *)0x0) {
    memset(aiStack_348,0,0x10);
    param_3 = aiStack_348;
  }
  memset(&local_338,0,0x30c);
  local_338 = 0x30c;
  local_30 = 0x10;
  local_264 = param_4;
  local_34 = param_3;
  if (param_2 == 0x113) {
    local_26c = local_26c | 0x100;
LAB_00015a5c:
    if (param_2 != 0x113) goto LAB_00015a64;
  }
  else {
    if (param_2 == 0x401) {
LAB_00015a44:
      local_26c = local_26c | 0x10;
      goto LAB_00015a5c;
    }
    if (param_2 == 0x402) {
      local_26c = local_26c | 0x24;
    }
    else if (param_2 == 0x403) {
      local_26c = local_26c | 0x28;
      local_25c = param_5;
    }
    else {
      if (param_2 == 0x404) {
        local_26c = local_26c | 0x21;
      }
      else {
        if (param_2 != 0x405) {
          if (param_2 != 0x406) goto LAB_00015a5c;
          goto LAB_00015a44;
        }
        local_26c = local_26c | 0x22;
      }
      local_258 = param_5;
    }
LAB_00015a64:
    if ((local_26c & 0x20) == 0) {
      iVar1 = CeOidGetInfoEx(param_3,param_4,local_260);
      if (local_260[0] == 1) {
        local_26c = local_26c | 1;
      }
      else if (local_260[0] == 2) {
        local_26c = local_26c | 2;
      }
      else if (local_260[0] == 3) {
        local_26c = local_26c | 4;
      }
      else {
        if (local_260[0] != 4) goto LAB_00015d4c;
        local_26c = local_26c | 8;
      }
      if (iVar1 == 0) goto LAB_00015d4c;
    }
  }
  local_350[0] = 0;
  iVar1 = 0;
  iVar2 = FUN_00012318(param_1 + 0x58,(wchar_t *)local_350,0,1,0);
  while (iVar2 != 0) {
    if (((param_6 == 0) || (iVar2 == param_6)) &&
       ((param_2 != 0 || (*(int *)(*(int *)(iVar2 + 0xd4) + 0x1c) == 0)))) {
      wcscpy(awStack_334,(wchar_t *)(iVar2 + 4));
      local_40 = 0;
      local_3c = 0;
      local_38 = (undefined4 *)0x0;
      iVar3 = (**(code **)(*(int *)(iVar2 + 0xd4) + 0x10))(&local_338);
      if (iVar3 != 0) {
        if ((local_26c & 0x80) != 0) {
          DVar4 = GetTickCount();
          *(DWORD *)(iVar2 + 0x1a4) = DVar4 + 2000;
        }
        if (param_2 == 0) {
          if (*(int *)(iVar2 + 0x1b0) != 0) {
            puVar7 = local_38 + local_40;
            uVar6 = 0;
            if (local_3c != 0) {
              do {
                *(undefined4 *)(*(int *)(iVar2 + 0x1ac) * 4 + *(int *)(iVar2 + 0x1b0)) = *puVar7;
                uVar5 = *(int *)(iVar2 + 0x1ac) + 1;
                puVar7 = puVar7 + 1;
                *(uint *)(iVar2 + 0x1ac) = uVar5;
                if (0x1f < uVar5) {
                  iVar8 = FUN_00013d4c(param_1,*(undefined4 *)(iVar2 + 0xcc),0,
                                       *(int *)(iVar2 + 0x1a8),uVar5,*(int *)(iVar2 + 0x1b0),0,1);
                  if (iVar8 < 0) goto LAB_00015d4c;
                  *(undefined4 *)(iVar2 + 0x1ac) = 0;
                  *(undefined4 *)(iVar2 + 0x1a8) = 0;
                }
                uVar6 = uVar6 + 1;
              } while (uVar6 < local_3c);
            }
            uVar6 = 0;
            if (local_40 != 0) {
              do {
                *(undefined4 *)((*(int *)(iVar2 + 0x1a8) + 0x20) * 4 + *(int *)(iVar2 + 0x1b0)) =
                     *local_38;
                *(int *)(iVar2 + 0x1a8) = *(int *)(iVar2 + 0x1a8) + 1;
                local_38 = local_38 + 1;
                if (0x1f < *(uint *)(iVar2 + 0x1a8)) {
                  iVar8 = FUN_00013d4c(param_1,*(undefined4 *)(iVar2 + 0xcc),0,
                                       *(uint *)(iVar2 + 0x1a8),*(uint *)(iVar2 + 0x1ac),
                                       *(int *)(iVar2 + 0x1b0),0,1);
                  if (iVar8 < 0) goto LAB_00015d4c;
                  *(undefined4 *)(iVar2 + 0x1ac) = 0;
                  *(undefined4 *)(iVar2 + 0x1a8) = 0;
                }
                uVar6 = uVar6 + 1;
              } while (uVar6 < local_40);
            }
          }
        }
        else if (local_3c + local_40 != 0) {
          DVar4 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x18),60000);
          if ((DVar4 == 0) &&
             (DVar4 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x14),60000), DVar4 == 0)) {
            iVar8 = **(int **)(param_1 + 0x20);
            uVar6 = FUN_00018cc8(param_1,0,iVar2,local_34,local_30);
            iVar8 = (**(code **)(iVar8 + 0xc))
                              (*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(iVar2 + 0xcc),
                               local_40,local_3c,local_38,uVar6);
          }
          else {
            iVar8 = -0x7febefff;
          }
        }
      }
      if (param_6 != 0) break;
    }
    iVar1 = iVar1 + 1;
    local_350[0] = iVar1;
    iVar2 = FUN_00012318(param_1 + 0x58,(wchar_t *)local_350,0,1,0);
  }
LAB_00015d4c:
  FUN_0001c2c0(local_2c);
  return iVar8;
}



/* 00015e30 FUN_00015e30 */

/* Boundary evidence: original MIPS .pdata 00015e30..00015e83. Semantic name remains unreviewed. */

undefined4 FUN_00015e30(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0001494c();
  uVar2 = 1;
  if (((iVar1 != 1) && (iVar1 != 2)) || (iVar1 = FUN_00014d08(iVar1), iVar1 == 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00015e84 FUN_00015e84 */

/* Boundary evidence: original MIPS .pdata 00015e84..00015ee7. Semantic name remains unreviewed. */

undefined4 * FUN_00015e84(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000116bc;
  FUN_000120ec((int)param_1,1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00015ee8 FUN_00015ee8 */

/* Boundary evidence: original MIPS .pdata 00015ee8..000166bb. Semantic name remains unreviewed. */

undefined4 FUN_00015ee8(void)

{
  bool bVar1;
  undefined *_Memory;
  int iVar2;
  void *pvVar3;
  HANDLE pvVar4;
  DWORD DVar5;
  HANDLE hObject;
  DWORD DVar6;
  wchar_t *pwVar7;
  BOOL BVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined *puVar15;
  int local_ab0;
  int local_aac;
  DWORD local_aa8 [2];
  undefined4 local_aa0;
  undefined4 local_a9c;
  undefined4 local_a98;
  undefined *local_a90;
  undefined1 auStack_a8c [796];
  undefined1 auStack_770 [544];
  uint local_550;
  wchar_t awStack_54c [100];
  int local_484;
  uint local_480;
  int local_47c;
  int *local_478;
  uint local_474;
  _WIN32_FIND_DATAW local_468;
  uint local_30;
  
  local_30 = DAT_0001d244;
  iVar13 = 0;
  if (DAT_0001d314 != 0) {
    if (*(int *)(DAT_0001d314 + 0x20) != 0) {
      local_aa0 = FUN_0001494c();
      local_a9c = FUN_00014d08(1);
      local_a98 = FUN_00014d08(2);
      (**(code **)(**(int **)(DAT_0001d314 + 0x20) + 0xc))
                (*(int **)(DAT_0001d314 + 0x20),0xffffffff,3,0,&local_aa0,0x2000000);
    }
    if (DAT_0001d314 != 0) {
      local_aac = 0;
      local_ab0 = 0;
      bVar1 = true;
      iVar2 = FUN_00012318(DAT_0001d314 + 0x58,(wchar_t *)&local_ab0,0,1,0);
      if (iVar2 != 0) {
        do {
          if (*(int *)(*(int *)(iVar2 + 0xd4) + 0x1c) == 0) {
            bVar1 = false;
            pvVar3 = operator_new(0x100);
            *(void **)(iVar2 + 0x1b0) = pvVar3;
            if (pvVar3 == (void *)0x0) goto LAB_000160e8;
          }
          local_ab0 = local_aac + 1;
          local_aac = local_ab0;
          iVar2 = FUN_00012318(DAT_0001d314 + 0x58,(wchar_t *)&local_ab0,0,1,0);
        } while (iVar2 != 0);
        if (!bVar1) {
          pvVar4 = (HANDLE)CeFindFirstDatabase(0);
          DVar5 = CeFindNextDatabase(pvVar4);
          local_aa8[0] = DVar5;
          if (DVar5 != 0) {
            do {
              local_aa8[0] = DVar5;
              memset(auStack_770,0,0x220);
              iVar2 = CeOidGetInfo(DVar5,auStack_770);
              if (iVar2 != 0) {
                iVar13 = FUN_0001590c(DAT_0001d314,0,(int *)0x0,local_aa8[0],0,0);
                if (iVar13 < 0) goto LAB_000160f0;
                hObject = (HANDLE)CeOpenDatabase(local_aa8,0,0,0,0);
                if (hObject != (HANDLE)0xffffffff) {
                  uVar11 = 0;
                  uVar10 = 2;
                  while (iVar2 = CeSeekDatabase(hObject,uVar10,uVar11,&local_aac), iVar2 != 0) {
                    DVar5 = WaitForSingleObject(DAT_0001d340,0);
                    if (DVar5 == 0x102) {
                      iVar13 = -0x7fffbffc;
                      goto LAB_000160f0;
                    }
                    iVar13 = FUN_0001590c(DAT_0001d314,0,(int *)0x0,iVar2,local_aa8[0],0);
                    if (iVar13 < 0) goto LAB_000160f0;
                    uVar11 = 1;
                    uVar10 = 8;
                  }
                  CloseHandle(hObject);
                }
              }
              DVar5 = CeFindNextDatabase(pvVar4);
            } while (DVar5 != 0);
            local_aa8[0] = 0;
          }
          CloseHandle(pvVar4);
          memset(&local_a90,0,800);
          uVar12 = 1;
          pvVar4 = FindFirstFileW(L"\\",&local_468);
          if (pvVar4 == (HANDLE)0xffffffff) {
            local_aa8[0] = 0;
          }
          else {
            FindClose(pvVar4);
            local_aa8[0] = local_468.dwReserved0;
          }
          do {
            _Memory = local_a90;
            puVar15 = local_a90;
            if (local_a90 == (undefined *)0x0) {
              puVar15 = &DAT_00011778;
            }
            uVar12 = uVar12 - 1;
            if (uVar12 != 0) {
              memmove(&local_a90,auStack_a8c,uVar12 * 4);
            }
            wsprintfW(local_468.cFileName + 0x102,L"%s\\*",puVar15);
            pvVar4 = FindFirstFileW(local_468.cFileName + 0x102,&local_468);
            if (pvVar4 != (HANDLE)0xffffffff) {
              puVar14 = (undefined4 *)(auStack_a8c + uVar12 * 4 + -4);
              do {
                DVar6 = WaitForSingleObject(DAT_0001d340,0);
                DVar5 = local_468.dwFileAttributes;
                if (DVar6 == 0x102) {
                  iVar13 = -0x7fffbffc;
                  goto LAB_000160f0;
                }
                if (((local_468.dwFileAttributes & 0x40) == 0) &&
                   (((_Memory != (undefined *)0x0 ||
                     ((iVar2 = wcscmp((wchar_t *)&local_468.dwReserved1,L"Windows"), iVar2 != 0 &&
                      (iVar2 = wcscmp((wchar_t *)&local_468.dwReserved1,L"CEreg.reg"), iVar2 != 0)))
                     ) && (iVar13 = FUN_0001590c(DAT_0001d314,0,(int *)0x0,local_468.dwReserved0,
                                                 local_aa8[0],0), DVar5 = local_468.dwFileAttributes
                          , iVar13 < 0)))) goto LAB_000160f0;
                if (((DVar5 & 0x10) != 0) && (uVar12 < 199)) {
                  wsprintfW(local_468.cFileName + 0x102,L"%s\\%s",puVar15,&local_468.dwReserved1);
                  pwVar7 = _wcsdup(local_468.cFileName + 0x102);
                  if (pwVar7 != (wchar_t *)0x0) {
                    *puVar14 = pwVar7;
                    uVar12 = uVar12 + 1;
                    puVar14 = puVar14 + 1;
                  }
                }
                BVar8 = FindNextFileW(pvVar4,&local_468);
              } while (BVar8 != 0);
              FindClose(pvVar4);
            }
            if (_Memory != (undefined *)0x0) {
              free(_Memory);
            }
          } while (uVar12 != 0);
        }
      }
      local_aac = 0;
      local_ab0 = 0;
      iVar2 = FUN_00012318(DAT_0001d314 + 0x58,(wchar_t *)&local_ab0,0,1,0);
      while (iVar2 != 0) {
        if (*(int *)(*(int *)(iVar2 + 0xd4) + 0x1c) != 0) {
          do {
            memset(&local_550,0,0xe4);
            wcscpy(awStack_54c,(wchar_t *)(iVar2 + 4));
            iVar9 = (**(code **)(*(int *)(iVar2 + 0xd4) + 0x1c))(&local_550);
            if (iVar9 < 0) break;
            if ((local_478 == (int *)0x0) ||
               ((local_474 == 0x10 &&
                (((local_478[3] == 0 && local_478[2] == 0) && local_478[1] == 0) && *local_478 == 0)
                ))) {
              uVar12 = 0;
            }
            else {
              uVar12 = FUN_000137f4((int *)(iVar2 + 0x1b4),local_478,local_474,(undefined4 *)0x0);
            }
            if ((-1 < (int)uVar12) &&
               (((local_47c != 0 || (local_480 != 0)) &&
                (iVar13 = FUN_00013d4c(DAT_0001d314,*(undefined4 *)(iVar2 + 0xcc),uVar12,local_47c,
                                       local_480,local_484,0,0), iVar13 < 0)))) goto LAB_000160f0;
            local_550 = local_550 | 2;
            (**(code **)(*(int *)(iVar2 + 0xd4) + 0x1c))(&local_550);
          } while ((local_550 & 1) != 0);
        }
        local_ab0 = local_aac + 1;
        local_aac = local_ab0;
        iVar2 = FUN_00012318(DAT_0001d314 + 0x58,(wchar_t *)&local_ab0,0,1,0);
      }
      local_aac = 0;
      local_ab0 = 0;
      iVar2 = FUN_00012318(DAT_0001d314 + 0x58,(wchar_t *)&local_ab0,0,1,0);
      while ((iVar2 != 0 &&
             (iVar13 = FUN_00013d4c(DAT_0001d314,*(undefined4 *)(iVar2 + 0xcc),0,
                                    *(int *)(iVar2 + 0x1a8),*(uint *)(iVar2 + 0x1ac),
                                    *(int *)(iVar2 + 0x1b0),1,1), -1 < iVar13))) {
        *(undefined4 *)(iVar2 + 0x1ac) = 0;
        *(undefined4 *)(iVar2 + 0x1a8) = 0;
        local_ab0 = local_aac + 1;
        local_aac = local_ab0;
        iVar2 = FUN_00012318(DAT_0001d314 + 0x58,(wchar_t *)&local_ab0,0,1,0);
      }
      goto LAB_000160f0;
    }
  }
LAB_000160e8:
  iVar13 = -0x7ff8fff2;
LAB_000160f0:
  if (DAT_0001d314 != 0) {
    local_aac = 0;
    local_ab0 = 0;
    iVar2 = FUN_00012318(DAT_0001d314 + 0x58,(wchar_t *)&local_ab0,0,1,0);
    while (iVar2 != 0) {
      operator_delete(*(void **)(iVar2 + 0x1b0));
      *(undefined4 *)(iVar2 + 0x1b0) = 0;
      local_ab0 = local_aac + 1;
      local_aac = local_ab0;
      iVar2 = FUN_00012318(DAT_0001d314 + 0x58,(wchar_t *)&local_ab0,0,1,0);
    }
  }
  if (iVar13 < 0) {
    PostMessageW(DAT_0001d25c,0x4ca,0,1);
  }
  FUN_0001c2c0(local_30);
  return 0;
}



/* 000166bc FUN_000166bc */

/* Boundary evidence: original MIPS .pdata 000166bc..000169ef. Semantic name remains unreviewed. */

void FUN_000166bc(int param_1,int param_2)

{
  LSTATUS LVar1;
  undefined4 *puVar2;
  int iVar3;
  HANDLE pvVar4;
  void *_Dst;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint local_38;
  HKEY local_34;
  int local_30;
  DWORD DStack_2c;
  
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Tasks\\TeamMan",0,(LPWSTR)0x0,0,
                          0x20006,(LPSECURITY_ATTRIBUTES)0x0,&local_34,&local_38);
  if (LVar1 == 0) {
    local_38 = (uint)((*(uint *)(param_2 + 8) & 1) != 0);
    RegSetValueExW(local_34,L"TeamMan",0,4,(BYTE *)&local_38,4);
    RegCloseKey(local_34);
  }
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Pim\\Outlook",0,(LPWSTR)0x0,0,
                          0x20006,(LPSECURITY_ATTRIBUTES)0x0,&local_34,&local_38);
  if (LVar1 == 0) {
    local_38 = (uint)((*(uint *)(param_2 + 8) & 2) != 0);
    RegSetValueExW(local_34,L"Outlook",0,4,(BYTE *)&local_38,4);
    RegCloseKey(local_34);
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar7 = 0;
    do {
      uVar6 = uVar6 + 1;
      **(undefined4 **)(*(int *)(param_1 + 0x54) + iVar7) = 0;
      iVar7 = iVar7 + 4;
    } while (uVar6 < *(uint *)(param_1 + 0x50));
  }
  uVar6 = 0;
  if (*(int *)(param_2 + 0x18) != 0) {
    puVar9 = (undefined4 *)(param_2 + 0x1c);
    do {
      local_30 = *puVar9;
      puVar2 = (undefined4 *)FUN_00012318(param_1 + 0x58,(wchar_t *)&local_30,3,1,0);
      if (puVar2 != (undefined4 *)0x0) {
        FUN_00012234(param_1 + 0x58,puVar2,1);
      }
      uVar6 = uVar6 + 1;
      puVar9 = puVar9 + 1;
    } while (uVar6 < *(uint *)(param_2 + 0x18));
  }
  local_30 = 0;
  iVar7 = 0;
  iVar3 = FUN_00012318(param_1 + 0x58,(wchar_t *)&local_30,0,1,0);
  while (iVar3 != 0) {
    iVar7 = iVar7 + 1;
    **(undefined4 **)(iVar3 + 0xd4) = 1;
    local_30 = iVar7;
    iVar3 = FUN_00012318(param_1 + 0x58,(wchar_t *)&local_30,0,1,0);
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar7 = 0;
    do {
      piVar8 = *(int **)(*(int *)(param_1 + 0x54) + iVar7);
      if (*piVar8 == 0) {
        if (piVar8 != (int *)0x0) {
          FUN_000134a4((int)piVar8);
          operator_delete(piVar8);
        }
        uVar5 = *(int *)(param_1 + 0x50) - 1;
        *(uint *)(param_1 + 0x50) = uVar5;
        if (uVar6 != uVar5) {
          _Dst = (void *)(*(int *)(param_1 + 0x54) + iVar7);
          memmove(_Dst,(void *)((int)_Dst + 4),(uVar5 - uVar6) * 4);
        }
      }
      uVar6 = uVar6 + 1;
      iVar7 = iVar7 + 4;
    } while (uVar6 < *(uint *)(param_1 + 0x50));
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00015ee8,(LPVOID)0x0,0,&DStack_2c);
    *(HANDLE *)(param_1 + 0x10) = pvVar4;
  }
  return;
}



/* 000169f0 FUN_000169f0 */

/* Boundary evidence: original MIPS .pdata 000169f0..00016bc7. Semantic name remains unreviewed. */

void FUN_000169f0(int param_1)

{
  int iVar1;
  DWORD DVar2;
  short *psVar3;
  code *pcVar4;
  void *_Src;
  int iVar5;
  uint uVar6;
  int local_120 [2];
  undefined1 auStack_118 [8];
  short local_110 [100];
  undefined4 local_48;
  undefined4 local_44;
  uint local_28;
  
  local_28 = DAT_0001d244;
  local_120[0] = 0;
  iVar5 = 0;
  iVar1 = FUN_00012318(param_1 + 0x58,(wchar_t *)local_120,0,1,0);
  while (iVar1 != 0) {
    if ((*(int *)(iVar1 + 0x1a4) != 0) && (DVar2 = GetTickCount(), *(uint *)(iVar1 + 0x1a4) < DVar2)
       ) {
      *(undefined4 *)(iVar1 + 0x1a4) = 0;
      FUN_0001590c(param_1,0x113,(int *)0x0,0,0,iVar1);
    }
    iVar5 = iVar5 + 1;
    local_120[0] = iVar5;
    iVar1 = FUN_00012318(param_1 + 0x58,(wchar_t *)local_120,0,1,0);
  }
  while( true ) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
    _Src = *(void **)(param_1 + 0x3c);
    if (_Src != (void *)0x0) {
      memcpy(auStack_118,_Src,0xf0);
      operator_delete(_Src);
      memmove((undefined4 *)(param_1 + 0x3c),(void *)(param_1 + 0x40),0x10);
      *(undefined4 *)(param_1 + 0x4c) = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
    if (_Src == (void *)0x0) break;
    uVar6 = 0;
    if (*(int *)(DAT_0001d314 + 0x50) != 0) {
      iVar1 = 0;
      iVar5 = DAT_0001d314;
      do {
        pcVar4 = *(code **)(*(int *)(*(int *)(iVar5 + 0x54) + iVar1) + 0x18);
        if (pcVar4 != (code *)0x0) {
          psVar3 = local_110;
          if (local_110[0] == 0) {
            psVar3 = (short *)0x0;
          }
          (*pcVar4)(psVar3,local_48,local_44);
          iVar5 = DAT_0001d314;
        }
        uVar6 = uVar6 + 1;
        iVar1 = iVar1 + 4;
      } while (uVar6 < *(uint *)(iVar5 + 0x50));
    }
    EventModify(*(undefined4 *)(param_1 + 0x1c),3);
  }
  FUN_0001c2c0(local_28);
  return;
}



/* 00016bc8 FUN_00016bc8 */

/* Boundary evidence: original MIPS .pdata 00016bc8..00016e7b. Semantic name remains unreviewed. */

void FUN_00016bc8(int param_1)

{
  undefined4 *puVar1;
  HWND pHVar2;
  DWORD DVar3;
  DWORD DVar4;
  BOOL BVar5;
  UINT Msg;
  WPARAM wParam;
  
  WaitForSingleObject(DAT_0001d340,0xfde80);
  EventModify(DAT_0001d340,2);
  if ((param_1 != 0) && (DAT_0001d24c != -1)) {
    closesocket(DAT_0001d24c);
    DAT_0001d24c = -1;
  }
  if (DAT_0001d488 != (HWND)0x0) {
    if (param_1 == 0) {
      wParam = 0x4cf;
      Msg = 0x111;
    }
    else {
      wParam = 0;
      Msg = 0x10;
    }
    PostMessageW(DAT_0001d488,Msg,wParam,0);
  }
  puVar1 = DAT_0001d314;
  if (DAT_0001d314 != (undefined4 *)0x0) {
    FUN_0001558c(DAT_0001d314);
    operator_delete(puVar1);
  }
  DAT_0001d314 = (undefined4 *)0x0;
  if (param_1 != 0) {
    pHVar2 = FindWindowW(L"RapiSrv",(LPCWSTR)0x0);
    if (pHVar2 != (HWND)0x0) {
      DVar3 = GetTickCount();
      PostMessageW(pHVar2,0x47c,0,0);
      while( true ) {
        DVar4 = GetTickCount();
        if ((29999 < DVar4 - DVar3) || (BVar5 = IsWindow(pHVar2), BVar5 == 0)) break;
        Sleep(1000);
      }
    }
    pHVar2 = FindWindowW(L"U2TPROXY",(LPCWSTR)0x0);
    if (pHVar2 != (HWND)0x0) {
      DVar3 = GetTickCount();
      PostMessageW(pHVar2,0x47c,0,0);
      while( true ) {
        DVar4 = GetTickCount();
        if ((29999 < DVar4 - DVar3) || (BVar5 = IsWindow(pHVar2), BVar5 == 0)) break;
        Sleep(1000);
      }
    }
    if ((DAT_0001d348 != (HWND)0x0) && (DAT_0001d310 != 0)) {
      DAT_0001d310 = 0;
      PostMessageW(DAT_0001d348,0x401,2,0);
      DAT_0001d348 = (HWND)0x0;
    }
    DAT_0001d318 = 0;
    memset(&DAT_0001d260,0,0x80);
    if (DAT_0001d2fc != (HWND)0x0) {
      PostMessageW(DAT_0001d2fc,0x111,1,0);
    }
  }
  EventModify(DAT_0001d340,3);
  if (DAT_0001d308 != 0) {
    DAT_0001d308 = 0;
    PostMessageW(DAT_0001d25c,0x4c9,0,0);
  }
  return;
}



/* 00016e7c FUN_00016e7c */

/* Boundary evidence: original MIPS .pdata 00016e7c..00016ef3. Semantic name remains unreviewed. */

undefined4 * FUN_00016e7c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0001162c;
  param_1[1] = 1;
  memset(param_1 + 3,0,0xec);
  *(undefined2 *)(param_1 + 0x45) = 1;
  param_1[0x3e] = 0;
  param_1[2] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  param_1[0x40] = 0;
  param_1[0x3f] = 0;
  param_1[0x43] = 0;
  param_1[0x46] = 0;
  param_1[0x44] = 0;
  return param_1;
}



/* 00016ef4 FUN_00016ef4 */

/* Boundary evidence: original MIPS .pdata 00016ef4..00017043. Semantic name remains unreviewed. */

undefined4 * FUN_00016ef4(undefined4 *param_1)

{
  UINT_PTR UVar1;
  
  param_1[1] = &PTR_LAB_00011668;
  param_1[2] = &PTR_LAB_00011698;
  *param_1 = &PTR_FUN_00011720;
  param_1[1] = &PTR_LAB_000116f0;
  param_1[2] = &PTR_LAB_000116e0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 10));
  FUN_00014f90(param_1 + 0x16);
  param_1[0x16] = &PTR_FUN_000116d4;
  param_1[0x20] = &PTR_FUN_00011750;
  memset(param_1 + 0x21,0,8);
  param_1[0x24] = 0;
  param_1[0x23] = 0;
  FUN_00016e7c(param_1 + 0x25);
  FUN_00016e7c(param_1 + 0x6c);
  DAT_0001d314 = param_1;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[8] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  UVar1 = SetTimer(DAT_0001d25c,1,500,(TIMERPROC)0x0);
  param_1[9] = UVar1;
  memset(param_1 + 0xf,0,0x14);
  DAT_0001d2e8 = 0x14;
  DAT_0001d2ec = DAT_0001d25c;
  DAT_0001d2f0 = 1;
  DAT_0001d2f4 = 0;
  DAT_0001d2f8 = param_1;
  return param_1;
}



/* 00017044 FUN_00017044 */

/* Boundary evidence: original MIPS .pdata 00017044..00017def. Semantic name remains unreviewed. */

LRESULT FUN_00017044(HWND param_1,uint param_2,UINT param_3,UINT param_4)

{
  int *piVar1;
  HANDLE lParam;
  BOOL BVar2;
  int iVar3;
  HWND pHVar4;
  LSTATUS LVar5;
  undefined4 *puVar6;
  LRESULT LVar7;
  UINT UVar8;
  wchar_t *pwVar9;
  LONG LVar10;
  WPARAM wParam;
  HWND lParam_00;
  uint uVar11;
  short *psVar12;
  LPCWSTR lpString1;
  uint local_f10;
  HWND local_f0c;
  DWORD local_f08;
  int local_f04 [3];
  undefined1 auStack_ef8 [4];
  int local_ef4;
  WCHAR aWStack_dc8 [64];
  WCHAR aWStack_d48 [64];
  WCHAR local_cc8 [2];
  undefined4 local_cc4;
  WCHAR aWStack_cc0 [124];
  WCHAR aWStack_bc8 [32];
  WCHAR aWStack_b88 [32];
  WCHAR aWStack_b48 [64];
  WCHAR aWStack_ac8 [400];
  WCHAR aWStack_7a8 [128];
  WCHAR aWStack_6a8 [128];
  WCHAR aWStack_5a8 [400];
  WCHAR aWStack_288 [300];
  uint local_30;
  
  local_30 = DAT_0001d244;
  if (0x471 < param_2) {
    if (param_2 < 0x602) {
      if (param_2 != 0x601) {
        if (param_2 == 0x4c9) {
          if (DAT_0001d314 != 0) {
            DAT_0001d308 = 1;
LAB_00017cf0:
            FUN_0001c2c0(local_30);
            return 0;
          }
          puVar6 = operator_new(0x2cc);
          if (puVar6 != (undefined4 *)0x0) {
            FUN_00016ef4(puVar6);
          }
          if (DAT_0001d314 != 0) {
            iVar3 = FUN_00015818(DAT_0001d314);
            if (-1 < iVar3) {
              if (DAT_0001d488 != (HWND)0x0) {
                PostMessageW(DAT_0001d488,0x111,0x4d0,0);
              }
              goto LAB_00017cf0;
            }
            PostMessageW(DAT_0001d25c,0x10,0,0);
          }
          FUN_0001c2c0(local_30);
          return -0x7fffbffb;
        }
        if (param_2 != 0x4ca) {
          if (param_2 == 0x4ce) {
            if (DAT_0001d45c == (int *)0x0) {
              puVar6 = operator_new(0xcc);
              if (puVar6 == (undefined4 *)0x0) {
                DAT_0001d45c = (int *)0x0;
              }
              else {
                DAT_0001d45c = FUN_000131c4(puVar6,param_1,param_1,DAT_0001d338,&DAT_0001d318);
              }
              if (DAT_0001d45c != (int *)0x0) {
                iVar3 = FUN_0001c190(DAT_0001d45c);
                piVar1 = DAT_0001d45c;
                if (iVar3 != 0) {
                  LVar10 = 1;
                  goto LAB_00017d94;
                }
                if (DAT_0001d45c != (int *)0x0) {
                  FUN_0001b3f8(DAT_0001d45c);
                  operator_delete(piVar1);
                }
                DAT_0001d45c = (int *)0x0;
              }
            }
          }
          else {
            if (param_2 != 0x600) goto LAB_00017d9c;
            if ((param_3 != 0) || (param_4 != 0)) {
              LoadStringW(DAT_0001d344,param_3,aWStack_b48,0x40);
              LoadStringW(DAT_0001d344,param_4,aWStack_288,300);
              DAT_0001d460 = 1;
              MessageBoxW(param_1,aWStack_288,aWStack_b48,0x10010);
              DAT_0001d460 = 0;
            }
            if (DAT_0001d45c != (int *)0x0) {
              FUN_0001b8fc(DAT_0001d45c);
              DAT_0001d45c = (int *)0x0;
            }
          }
LAB_00017b50:
          FUN_00016bc8(1);
          goto LAB_00017d9c;
        }
        if (DAT_0001d45c != (int *)0x0) {
          FUN_0001b8fc(DAT_0001d45c);
          DAT_0001d45c = (int *)0x0;
        }
        FUN_00016bc8(param_3);
        if ((param_4 != 0) || (iVar3 = FUN_00014250(param_1), iVar3 != 0)) goto LAB_00017d9c;
        goto LAB_00017c28;
      }
      if (DAT_0001d45c == (int *)0x0) goto LAB_00017d9c;
      LVar10 = 2;
    }
    else {
      if (param_2 != 0x602) {
        if (((param_2 == 0x603) || (param_2 == 0x604)) && (DAT_0001d45c != (int *)0x0)) {
          FUN_0001b4b4((int)DAT_0001d45c,&DAT_0001d24c,&DAT_0001d318,&DAT_0001d260);
          FUN_0001b8fc(DAT_0001d45c);
          DAT_0001d45c = (int *)0x0;
          FUN_00014804();
        }
        goto LAB_00017d9c;
      }
      if (DAT_0001d45c == (int *)0x0) goto LAB_00017d9c;
      LVar10 = 3;
    }
LAB_00017d94:
    FUN_0001b534((int)DAT_0001d45c,LVar10);
    goto LAB_00017d9c;
  }
  if (param_2 == 0x471) {
    local_f04[1] = 4;
    local_f04[0] = 0;
    LVar5 = RegQueryValueExW((HKEY)0x80000002,L"AllowRemoteSync",
                             (LPDWORD)L"Software\\Microsoft\\Windows CE Services",
                             (LPDWORD)(local_f04 + 2),(LPBYTE)local_f04,(LPDWORD)(local_f04 + 1));
    if ((LVar5 == 0) && (local_f04[0] != 0)) {
      if (DAT_0001d460 != 0) {
LAB_000173e4:
        EnumWindows(FUN_00013250,(LPARAM)param_1);
        goto LAB_00017d9c;
      }
      iVar3 = FUN_00015e30();
      if (iVar3 != 0) {
        if (DAT_0001d33c == (HANDLE)0x0) {
          DAT_0001d33c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001b200,(LPVOID)0x0,0,
                                      &local_f08);
        }
        if ((param_3 != 0) && (DAT_0001d488 != (HWND)0x0)) {
          SetForegroundWindow(DAT_0001d488);
        }
        goto LAB_00017d9c;
      }
      LoadStringW(DAT_0001d344,0x7dd,aWStack_b88,0x20);
      LoadStringW(DAT_0001d344,0x7de,aWStack_7a8,0x80);
      DAT_0001d460 = 1;
      MessageBoxW(param_1,aWStack_7a8,aWStack_b88,0x10010);
      DAT_0001d460 = 0;
    }
    else {
      LoadStringW(DAT_0001d344,0x807,aWStack_bc8,0x20);
      LoadStringW(DAT_0001d344,0x808,aWStack_6a8,0x80);
      DAT_0001d460 = 1;
      MessageBoxW(param_1,aWStack_6a8,aWStack_bc8,0x10010);
      DAT_0001d460 = 0;
    }
LAB_00017c28:
    UVar8 = 0x10;
LAB_00017c2c:
    wParam = 0;
  }
  else {
    if (param_2 < 0x3fe) {
      if (param_2 == 0x3fd) {
        if (DAT_0001d314 != 0) {
          FUN_0001590c(DAT_0001d314,*(int *)(param_4 + 8),(int *)(param_4 + 0xc),
                       *(undefined4 *)(param_4 + 0x1c),*(undefined4 *)(param_4 + 0x20),0);
        }
        CeFreeNotification(&DAT_0001d2e8,param_4);
        goto LAB_00017d9c;
      }
      if (param_2 != 1) {
        if (param_2 == 2) {
          if (DAT_0001d464 != (HANDLE)0x0) {
            CloseHandle(DAT_0001d464);
            DAT_0001d464 = (HANDLE)0x0;
          }
          PostQuitMessage(0);
          goto LAB_00017cf0;
        }
        if (param_2 != 0x10) {
          if (param_2 == 0x113) {
            if (DAT_0001d314 != 0) {
              FUN_000169f0(DAT_0001d314);
            }
            SystemIdleTimerReset();
          }
          goto LAB_00017d9c;
        }
        goto LAB_00017b50;
      }
      lParam = LoadImageW(DAT_0001d344,(LPCWSTR)0x64,1,0x10,0x10,0);
      SendMessageW(param_1,0x80,0,(LPARAM)lParam);
      DAT_0001d464 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"RAPI:STARTEVNT");
      if (DAT_0001d250 != -1) {
        CloseHandle((HANDLE)DAT_0001d250);
        DAT_0001d250 = -1;
        DeleteFileW(L"\\Windows\\Repllog.Up");
      }
      UVar8 = 0x470;
      goto LAB_00017c2c;
    }
    if (param_2 != 0x3fe) {
      if (param_2 == 0x46f) {
        if (DAT_0001d460 == 0) {
          if (((param_3 != 0) && (DAT_0001d338 != 0)) || (DAT_0001d44c != 0)) goto LAB_00017d9c;
          DAT_0001d44c = 1;
          pHVar4 = FindWindowW(L"RapiSrv",(LPCWSTR)0x0);
          local_f0c = (HWND)0x0;
          EnumWindows(FUN_000143f4,(LPARAM)&local_f0c);
          if ((pHVar4 == (HWND)0x0) &&
             (BVar2 = CreateProcessW(L"rapisrv.exe",(LPWSTR)0x0,(LPSECURITY_ATTRIBUTES)0x0,
                                     (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                                     (LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0), BVar2 != 0)) {
            WaitForSingleObject(DAT_0001d464,30000);
          }
          if (local_f0c == (HWND)0x0) {
            if ((DAT_0001d338 == 0) || (DAT_0001d34c == 0)) {
              FUN_00014490();
            }
            LoadStringW(DAT_0001d344,0x7e5,local_cc8,0x80);
            iVar3 = lstrcmpW(&DAT_0001d34c,local_cc8);
            if (iVar3 == 0) {
              DAT_0001d44c = 0;
              goto LAB_000173c4;
            }
            pwVar9 = L"-p -n -m -e\"%s\"";
            if (DAT_0001d30c == 0) {
              pwVar9 = L"-n -m -e\"%s\"";
            }
            wsprintfW(aWStack_d48,pwVar9,&DAT_0001d34c);
            BVar2 = CreateProcessW(L"rnaapp.exe",aWStack_d48,(LPSECURITY_ATTRIBUTES)0x0,
                                   (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                                   (LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
            if (BVar2 != 0) goto LAB_00017d9c;
          }
          else {
            local_f08 = 0xd0;
            local_f10 = 0;
            local_cc8[0] = L'4';
            local_cc8[1] = L'\0';
            iVar3 = RasEnumConnections(local_cc8,&local_f08,&local_f10);
            if ((iVar3 == 0) && (uVar11 = 0, local_f10 != 0)) {
              lpString1 = aWStack_cc0;
              do {
                iVar3 = lstrcmpW(lpString1,&DAT_0001d34c);
                if (iVar3 == 0) {
                  iVar3 = RasGetConnectStatus((&local_cc4)[uVar11 * 0xd],auStack_ef8);
                  if ((iVar3 == 0) && (local_ef4 == 0x2000)) {
                    wParam = 3;
                    UVar8 = 0x401;
                    pHVar4 = local_f0c;
                    lParam_00 = param_1;
                    goto LAB_00017c38;
                  }
                  break;
                }
                uVar11 = uVar11 + 1;
                lpString1 = lpString1 + 0x1a;
              } while (uVar11 < local_f10);
            }
          }
          DAT_0001d44c = 0;
          goto LAB_00017d9c;
        }
        goto LAB_000173e4;
      }
      if (param_2 != 0x470) goto LAB_00017d9c;
      if (DAT_0001d304 != 0) {
        DAT_0001d44c = 1;
        wsprintfW(aWStack_d48,L"%d",param_1);
        BVar2 = CreateProcessW(L"rapisrv.exe",aWStack_d48,(LPSECURITY_ATTRIBUTES)0x0,
                               (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                               (LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
        if (BVar2 == 0) {
LAB_000172d0:
          FUN_000132a0();
          DAT_0001d44c = 0;
          FUN_0001c2c0(local_30);
          return -1;
        }
        WaitForSingleObject(DAT_0001d464,30000);
        if ((DAT_0001d338 == 0) || (DAT_0001d34c == 0)) {
          FUN_00014490();
        }
        LoadStringW(DAT_0001d344,0x7e5,local_cc8,0x80);
        iVar3 = lstrcmpW(&DAT_0001d34c,local_cc8);
        if (iVar3 != 0) {
          pwVar9 = L"-p -n -m -e\"%s\"";
          if (DAT_0001d30c == 0) {
            pwVar9 = L"-n -m -e\"%s\"";
          }
          wsprintfW(aWStack_d48,pwVar9,&DAT_0001d34c);
          BVar2 = CreateProcessW(L"rnaapp.exe",aWStack_d48,(LPSECURITY_ATTRIBUTES)0x0,
                                 (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                                 (LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
          if (BVar2 != 0) goto LAB_00017d9c;
          goto LAB_000172d0;
        }
        DAT_0001d44c = 0;
        goto LAB_000173c4;
      }
      UVar8 = 0x471;
      goto LAB_00017c2c;
    }
    DAT_0001d44c = 0;
    iVar3 = wcscmp(&DAT_0001d34c,(wchar_t *)(param_4 + 0x10));
    if (iVar3 != 0) goto LAB_00017d9c;
    if (param_3 != 0) {
      DAT_0001d480 = 0;
      DAT_0001d348 = *(HWND *)(param_4 + 4);
      PostMessageW(DAT_0001d348,0x401,1,0);
      DAT_0001d310 = 1;
LAB_000173c4:
      UVar8 = 0x4ce;
      goto LAB_00017c2c;
    }
    if (DAT_0001d310 == 0) {
      if ((DAT_0001d480 != 0) && (DAT_0001d480 = 0, DAT_0001d48c != (HWND)0x0)) {
        pHVar4 = GetDlgItem(DAT_0001d48c,0x3e9);
        EnableWindow(pHVar4,1);
        goto LAB_00017d9c;
      }
      psVar12 = *(short **)(param_4 + 0xc);
      if ((((DAT_0001d338 == 0) && ((psVar12 == (short *)0x26b || (psVar12 == (short *)0x2a7)))) ||
          (psVar12 == (short *)0x277)) ||
         ((psVar12 == (short *)0x2f3 || (psVar12 == (short *)0x2f4)))) goto LAB_000178ac;
      if (psVar12 == (short *)0x26b) {
        LoadStringW(DAT_0001d344,0x7e3,aWStack_dc8,0x40);
        UVar8 = 0x7e4;
LAB_00017874:
        LoadStringW(DAT_0001d344,UVar8,aWStack_ac8,400);
      }
      else {
        if (psVar12 != (short *)0x26f) {
          if (psVar12 == (short *)0x274) {
            LoadStringW(DAT_0001d344,0x7fe,aWStack_dc8,0x40);
            UVar8 = 0x7ff;
          }
          else if (psVar12 == (short *)0x279) {
            LoadStringW(DAT_0001d344,0x7d5,aWStack_dc8,0x40);
            UVar8 = 0x7d6;
          }
          else if (psVar12 == (short *)0x29c) {
            LoadStringW(DAT_0001d344,0x800,aWStack_dc8,0x40);
            UVar8 = 0x801;
          }
          else if (psVar12 == (short *)0x2a7) {
            LoadStringW(DAT_0001d344,0x7e1,aWStack_dc8,0x40);
            UVar8 = 0x7e2;
          }
          else {
            if (psVar12 != (short *)0x2b8) {
              LoadStringW(DAT_0001d344,0x7d1,aWStack_dc8,0x40);
              LoadStringW(DAT_0001d344,0x7d2,aWStack_5a8,400);
              goto LAB_0001784c;
            }
            LoadStringW(DAT_0001d344,0x7d3,aWStack_dc8,0x40);
            UVar8 = 0x7d4;
          }
          goto LAB_00017874;
        }
        LoadStringW(DAT_0001d344,0x7d7,aWStack_dc8,0x40);
        LoadStringW(DAT_0001d344,0x7d8,aWStack_5a8,400);
        psVar12 = &DAT_0001d34c;
LAB_0001784c:
        wsprintfW(aWStack_ac8,aWStack_5a8,psVar12);
      }
      DAT_0001d460 = 1;
      MessageBoxW(param_1,aWStack_ac8,aWStack_dc8,0x10010);
      DAT_0001d460 = 0;
    }
LAB_000178ac:
    PostMessageW(param_1,0x4ca,1,0);
    DAT_0001d34c = 0;
    if (*(int *)(param_4 + 0xc) != 0x2f4) goto LAB_00017d9c;
    wParam = 1;
    UVar8 = 0x46f;
  }
  pHVar4 = param_1;
  lParam_00 = (HWND)0x0;
LAB_00017c38:
  PostMessageW(pHVar4,UVar8,wParam,(LPARAM)lParam_00);
LAB_00017d9c:
  LVar7 = DefWindowProcW(param_1,param_2,param_3,param_4);
  FUN_0001c2c0(local_30);
  return LVar7;
}



/* 00017df0 FUN_00017df0 */

/* Boundary evidence: original MIPS .pdata 00017df0..00017e87. Semantic name remains unreviewed. */

void FUN_00017df0(HINSTANCE param_1)

{
  WNDCLASSW local_30;
  
  memset(&local_30,0,0x28);
  local_30.style = 0;
  local_30.lpfnWndProc = FUN_00017044;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hInstance = param_1;
  local_30.hIcon = LoadImageW(param_1,(LPCWSTR)0x64,1,0x10,0x10,0);
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hbrBackground = GetStockObject(0);
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.lpszClassName = L"ReplLog";
  RegisterClassW(&local_30);
  return;
}



/* 00017e88 FUN_00017e88 */

/* Boundary evidence: original MIPS .pdata 00017e88..000183df. Semantic name remains unreviewed. */

undefined4 FUN_00017e88(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  bool bVar1;
  HMODULE hLibModule;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  size_t sVar5;
  HWND hWnd;
  DWORD DVar6;
  int iVar7;
  undefined3 extraout_var;
  BOOL BVar8;
  UINT Msg;
  uint uVar9;
  int local_208 [2];
  MSG local_200;
  WSADATA WStack_1e0;
  WCHAR aWStack_50 [16];
  uint local_30;
  
  local_30 = DAT_0001d244;
  local_200.hwnd = (HWND)0x0;
  local_200.message = 0;
  local_200.wParam = 0;
  local_200.lParam = 0;
  local_200.time = 0;
  memset(&local_200.pt,0,8);
  hLibModule = LoadLibraryW(L"UICOM.DLL");
  FUN_00011f54(0,0);
  DAT_0001d304 = 1;
  DAT_0001d46c = 0;
  DAT_0001d450 = 0;
  DAT_0001d30c = 0;
  pwVar2 = wcschr(param_3,L'/');
  if ((pwVar2 != (wchar_t *)0x0) && (*pwVar2 != L'\0')) {
    pwVar3 = wcschr(pwVar2 + 1,L'/');
LAB_00017f78:
    if (pwVar3 != (wchar_t *)0x0) {
      *pwVar3 = L'\0';
    }
    pwVar4 = wcsstr(pwVar2,L"/remote");
    if (pwVar4 == (wchar_t *)0x0) {
      pwVar4 = wcsstr(pwVar2,L"/ircomm");
      if (pwVar4 == (wchar_t *)0x0) {
        pwVar4 = wcsstr(pwVar2,L"/auto");
        if (pwVar4 == (wchar_t *)0x0) {
          pwVar4 = wcsstr(pwVar2,L"/d");
          if (pwVar4 == (wchar_t *)0x0) {
            pwVar4 = wcsstr(pwVar2,L"/c:");
            if (pwVar4 == (wchar_t *)0x0) {
              pwVar2 = wcsstr(pwVar2,L"/p:");
              if (pwVar2 != (wchar_t *)0x0) {
                pwVar4 = pwVar2 + 3;
                if (*pwVar4 == L'\"') {
                  pwVar4 = pwVar2 + 4;
                  pwVar2 = wcsrchr(pwVar4,L'\"');
                  if (pwVar2 != (wchar_t *)0x0) {
                    *pwVar2 = L'\0';
                  }
                }
                sVar5 = wcslen(pwVar4);
                pwVar2 = pwVar4 + sVar5;
                while ((pwVar2 = pwVar2 + -1, pwVar2 != (wchar_t *)0x0 &&
                       (iVar7 = _isctype((uint)(ushort)*pwVar2,8), iVar7 != 0))) {
                  *pwVar2 = L'\0';
                }
                wcscpy(&DAT_0001d318,pwVar4);
                uVar9 = 1;
                do {
                  iVar7 = FUN_00014d08(uVar9);
                  if (iVar7 != 0) {
                    FUN_00014dd0(uVar9,(LPBYTE)aWStack_50);
                    iVar7 = lstrcmpW(aWStack_50,&DAT_0001d318);
                    if (iVar7 == 0) goto LAB_0001820c;
                  }
                  uVar9 = uVar9 + 1;
                  if (2 < uVar9) goto LAB_0001819c;
                } while( true );
              }
            }
            else {
              pwVar2 = pwVar4 + 3;
              if (*pwVar2 == L'\"') {
                pwVar2 = pwVar4 + 4;
                pwVar4 = wcsrchr(pwVar2,L'\"');
                if (pwVar4 != (wchar_t *)0x0) {
                  *pwVar4 = L'\0';
                }
              }
              sVar5 = wcslen(pwVar2);
              pwVar4 = pwVar2 + sVar5;
              while ((pwVar4 = pwVar4 + -1, pwVar4 != (wchar_t *)0x0 &&
                     (iVar7 = _isctype((uint)(ushort)*pwVar4,8), iVar7 != 0))) {
                *pwVar4 = L'\0';
              }
              wcscpy(&DAT_0001d34c,pwVar2);
            }
          }
          else {
            DAT_0001d46c = 1;
          }
        }
        else {
          DAT_0001d30c = 1;
        }
      }
      else {
        DAT_0001d450 = 1;
      }
    }
    else {
      DAT_0001d304 = 0;
    }
    goto LAB_00018224;
  }
LAB_00018258:
  if ((DAT_0001d304 == 0) || (DAT_0001d450 != 0)) {
LAB_00018294:
    hWnd = FindWindowW(L"ReplLog",(LPCWSTR)0x0);
    if (hWnd == (HWND)0x0) {
      DAT_0001d250 = CreateFileW(L"\\Windows\\Repllog.Up",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,
                                 2,(HANDLE)0x0);
      if ((DAT_0001d250 != (HANDLE)0xffffffff) || (DVar6 = GetLastError(), DVar6 != 0x20)) {
        DAT_0001d340 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
        if (DAT_0001d340 == (HANDLE)0x0) goto LAB_000181b8;
        FUN_00014490();
        WSAStartup(0x202,&WStack_1e0);
        iVar7 = FUN_00017df0(param_1);
        if ((iVar7 != 0) && (bVar1 = FUN_000142e8(param_1), CONCAT31(extraout_var,bVar1) != 0)) {
          while (BVar8 = GetMessageW(&local_200,(HWND)0x0,0,0), BVar8 != 0) {
            TranslateMessage(&local_200);
            DispatchMessageW(&local_200);
          }
        }
        WSACleanup();
      }
    }
    else {
      if (DAT_0001d304 == 0) {
        Msg = 0x471;
      }
      else {
        Msg = 0x46f;
      }
      PostMessageW(hWnd,Msg,1,0);
    }
  }
  else {
    local_208[0] = 1;
    FUN_000133e4((HKEY)0x80000001,L"ControlPanel\\Comm",L"AutoCnct",(LPBYTE)local_208);
    if (local_208[0] != 0) goto LAB_00018294;
  }
LAB_0001819c:
  if (DAT_0001d340 != (HANDLE)0x0) {
    CloseHandle(DAT_0001d340);
  }
LAB_000181b8:
  FUN_0001201c();
  FreeLibrary(hLibModule);
  FUN_0001c2c0(local_30);
  return 0;
LAB_0001820c:
  if (uVar9 == 0) goto LAB_0001819c;
LAB_00018224:
  if (pwVar3 == (wchar_t *)0x0) goto LAB_00018258;
  *pwVar3 = L'/';
  pwVar4 = wcschr(pwVar3 + 1,L'/');
  bVar1 = pwVar3 == (wchar_t *)0x0;
  pwVar2 = pwVar3;
  pwVar3 = pwVar4;
  if (bVar1) goto LAB_00018258;
  goto LAB_00017f78;
}



/* 000183e0 FUN_000183e0 */

/* Boundary evidence: original MIPS .pdata 000183e0..0001842f. Semantic name remains unreviewed. */

bool FUN_000183e0(int param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)(param_1 + 8) = pvVar1;
  return pvVar1 != (HANDLE)0x0;
}



/* 00018430 FUN_00018430 */

/* Boundary evidence: original MIPS .pdata 00018430..000184a7. Semantic name remains unreviewed. */

undefined4 FUN_00018430(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 8))();
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (param_2 == (int *)0x0) {
    uVar1 = 2;
  }
  else {
    *(int **)(param_1 + 0x20) = param_2;
    (**(code **)(*param_2 + 4))(param_2);
    uVar1 = 3;
  }
  EventModify(*(undefined4 *)(param_1 + 0x18),uVar1);
  return 0;
}



/* 000184a8 FUN_000184a8 */

/* Boundary evidence: original MIPS .pdata 000184a8..000185cf. Semantic name remains unreviewed. */

undefined4 FUN_000184a8(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_110 [2];
  undefined4 local_108;
  undefined4 local_104;
  uint local_100;
  wchar_t awStack_f8 [100];
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  uint uStack_20;
  uint local_1c;
  
  local_1c = DAT_0001d244;
  local_110[0] = param_2;
  iVar1 = FUN_00012318(param_1 + 0x58,(wchar_t *)local_110,3,1,0);
  if (iVar1 == 0) {
    FUN_0001c2c0(local_1c);
    uVar2 = 0x80070057;
  }
  else {
    SystemIdleTimerReset();
    memset(&local_108,0,0xec);
    local_108 = 0xec;
    local_104 = 0;
    local_100 = param_5;
    if (param_1 == 0) {
      local_30 = 0;
    }
    else {
      local_30 = param_1 + 8;
    }
    local_2c = param_3;
    local_28 = param_3;
    wcscpy(awStack_f8,(wchar_t *)(iVar1 + 4));
    FUN_000136e8(iVar1 + 0x1b4,param_5 >> 0x14 & 0xf,&uStack_24,&uStack_20);
    FUN_00012860(param_1 + 0x1b0,*(int **)(iVar1 + 0xd8),&local_108);
    if (param_4 != (int *)0x0) {
      *param_4 = param_1 + 0x1b0;
    }
    FUN_0001c2c0(local_1c);
    uVar2 = 0;
  }
  return uVar2;
}



/* 000185d0 FUN_000185d0 */

/* Boundary evidence: original MIPS .pdata 000185d0..0001863f. Semantic name remains unreviewed. */

void FUN_000185d0(int *param_1)

{
  if ((HANDLE)param_1[2] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[2]);
  }
  while (*param_1 != 0) {
    param_1[1] = *(int *)(*param_1 + 0xc);
    operator_delete((void *)*param_1);
    *param_1 = param_1[1];
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



/* 00018640 FUN_00018640 */

/* Boundary evidence: original MIPS .pdata 00018640..00018727. Semantic name remains unreviewed. */

undefined4
FUN_00018640(int *param_1,undefined4 param_2,int param_3,void *param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(lpCriticalSection);
  }
  puVar1 = operator_new((param_3 + 4) * 4);
  if (puVar1 == (undefined4 *)0x0) {
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      LeaveCriticalSection(lpCriticalSection);
    }
    uVar2 = 0;
  }
  else {
    puVar1[3] = 0;
    *puVar1 = param_2;
    puVar1[1] = param_5;
    puVar1[2] = param_3;
    memcpy(puVar1 + 4,param_4,param_3 << 2);
    if (*param_1 == 0) {
      *param_1 = (int)puVar1;
    }
    else {
      *(undefined4 **)(param_1[1] + 0xc) = puVar1;
    }
    param_1[1] = (int)puVar1;
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      LeaveCriticalSection(lpCriticalSection);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 00018728 FUN_00018728 */

/* Boundary evidence: original MIPS .pdata 00018728..0001879b. Semantic name remains unreviewed. */

int FUN_00018728(int *param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar2;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(lpCriticalSection);
  }
  iVar2 = *param_1;
  if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 0xc), *param_1 = iVar1, iVar1 == 0)) {
    param_1[1] = 0;
  }
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar2;
}



/* 0001879c FUN_0001879c */

/* Boundary evidence: original MIPS .pdata 0001879c..00018973. Semantic name remains unreviewed. */

void FUN_0001879c(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  uint local_110;
  wchar_t awStack_108 [100];
  int local_40;
  undefined4 local_3c;
  undefined4 uStack_34;
  uint uStack_30;
  uint local_2c;
  
  local_2c = DAT_0001d244;
  local_11c = param_2;
  iVar1 = FUN_00012318(param_1 + 0x58,(wchar_t *)&local_11c,3,1,0);
  memset(&local_118,0,0xec);
  local_118 = 0xec;
  local_114 = 1;
  local_110 = param_5;
  if (param_1 == 0) {
    local_40 = 0;
  }
  else {
    local_40 = param_1 + 8;
  }
  wcscpy(awStack_108,(wchar_t *)(iVar1 + 4));
  FUN_000136e8(iVar1 + 0x1b4,param_5 >> 0x14 & 0xf,&uStack_34,&uStack_30);
  if (param_3 != 0) {
    do {
      local_3c = *param_4;
      SystemIdleTimerReset();
      iVar2 = FUN_00012860(param_1 + 0x94,*(int **)(iVar1 + 0xd8),&local_118);
      if (iVar2 < 0) {
LAB_000188d0:
        piVar3 = *(int **)(param_1 + 0x20);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x18))(piVar3,param_2,local_3c,iVar2,local_110 | 0x42000000);
        }
      }
      else {
        piVar3 = *(int **)(param_1 + 0x20);
        if (piVar3 != (int *)0x0) {
          local_120 = param_1 + 0x94;
          iVar2 = (**(code **)(*piVar3 + 0x10))(piVar3,param_2,local_3c,&local_120,param_5);
        }
        if (iVar2 < 0) goto LAB_000188d0;
      }
      param_3 = param_3 + -1;
      param_4 = param_4 + 1;
    } while (param_3 != 0);
    if ((-1 < iVar2) && (piVar3 = *(int **)(param_1 + 0x20), piVar3 != (int *)0x0)) {
      (**(code **)(*piVar3 + 0x1c))(piVar3,param_2,0);
    }
  }
  FUN_0001c2c0(local_2c);
  return;
}



/* 00018974 FUN_00018974 */

/* Boundary evidence: original MIPS .pdata 00018974..00018a27. Semantic name remains unreviewed. */

undefined4 FUN_00018974(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,uint param_5)

{
  int iVar1;
  
  if ((DAT_0001d468 != (int *)0x0) &&
     (iVar1 = FUN_00018640(DAT_0001d468,param_2,param_3,param_4,param_5), iVar1 != 0)) {
    EventModify(DAT_0001d468[2],3);
    return 0;
  }
  FUN_0001879c(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



/* 00018a28 FUN_00018a28 */

/* Boundary evidence: original MIPS .pdata 00018a28..00018b87. Semantic name remains unreviewed. */

int FUN_00018a28(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_118 [2];
  undefined4 local_110 [2];
  uint local_108;
  wchar_t awStack_100 [100];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  uint local_24;
  
  local_24 = DAT_0001d244;
  local_118[0] = param_2;
  iVar1 = FUN_00012318(param_1 + 0x58,(wchar_t *)local_118,3,1,0);
  if (iVar1 == 0) {
    FUN_0001c2c0(local_24);
    iVar1 = -0x7ff8ffa9;
  }
  else {
    memset(local_110,0,0xec);
    local_110[0] = 0xec;
    if (param_1 == 0) {
      local_38 = 0;
    }
    else {
      local_38 = param_1 + 8;
    }
    local_108 = param_4;
    wcscpy(awStack_100,(wchar_t *)(iVar1 + 4));
    local_34 = param_3;
    local_30 = param_3;
    FUN_000136e8(iVar1 + 0x1b4,param_4 >> 0x14 & 0xf,&uStack_2c,&uStack_28);
    iVar1 = (**(code **)(**(int **)(iVar1 + 0xd8) + 0x1c))(*(int **)(iVar1 + 0xd8),local_110);
    iVar2 = **(int **)(param_1 + 0x20);
    if (iVar1 < 0) {
      (**(code **)(iVar2 + 0x18))();
    }
    else {
      (**(code **)(iVar2 + 0x14))
                (*(int **)(param_1 + 0x20),param_2,param_3,param_3,param_4 | 0x80000000);
    }
    FUN_0001c2c0(local_24);
  }
  return iVar1;
}



/* 00018b88 FUN_00018b88 */

/* Boundary evidence: original MIPS .pdata 00018b88..00018cc7. Semantic name remains unreviewed. */

undefined4
FUN_00018b88(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  undefined4 local_res8 [2];
  undefined4 local_330 [2];
  undefined4 local_328;
  wchar_t awStack_324 [100];
  undefined4 local_25c;
  undefined4 local_254;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 uStack_24;
  uint uStack_20;
  uint local_1c;
  
  local_1c = DAT_0001d244;
  local_res8[0] = param_3;
  local_330[0] = param_2;
  iVar1 = FUN_00012318(param_1 + 0x58,(wchar_t *)local_330,3,1,0);
  if (((param_5 & 0x8000000) == 0) && ((param_5 & 0x80000000) == 0)) {
    memset(&local_328,0,0x30c);
    wcscpy(awStack_324,(wchar_t *)(iVar1 + 4));
    local_328 = 0x30c;
    local_28 = local_res8;
    local_254 = local_res8[0];
    local_25c = 0x40;
    local_30 = 0;
    local_2c = 0;
    if (*(int *)(*(int *)(iVar1 + 0xd4) + 0x1c) != 0) {
      FUN_000136e8(iVar1 + 0x1b4,param_5 >> 0x14 & 0xf,&uStack_24,&uStack_20);
    }
    iVar2 = (**(code **)(*(int *)(iVar1 + 0xd4) + 0x10))(&local_328);
    if (iVar2 != 0) {
      (**(code **)(**(int **)(param_1 + 0x20) + 0xc))
                (*(int **)(param_1 + 0x20),*(undefined4 *)(iVar1 + 0xcc),1,0,local_res8,0);
    }
  }
  FUN_0001c2c0(local_1c);
  return 0;
}



/* 00018cc8 FUN_00018cc8 */

/* Boundary evidence: original MIPS .pdata 00018cc8..00018d63. Semantic name remains unreviewed. */

uint FUN_00018cc8(undefined4 param_1,uint param_2,int param_3,int *param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  int local_10 [2];
  
  uVar2 = param_2 & 0xff0fffff;
  if (((param_4 != (int *)0x0) &&
      (((param_5 != 0x10 ||
        (((param_4[3] != 0 || param_4[2] != 0) || param_4[1] != 0) || *param_4 != 0)) &&
       (uVar1 = FUN_000137f4((int *)(param_3 + 0x1b4),param_4,param_5,local_10), 0 < (int)uVar1))))
     && (uVar2 = (uVar1 & 0xf) << 0x14 | uVar2, local_10[0] != 0)) {
    uVar2 = uVar2 | 0x100;
  }
  return uVar2;
}



/* 00018d64 FUN_00018d64 */

/* Boundary evidence: original MIPS .pdata 00018d64..00018e6b. Semantic name remains unreviewed. */

undefined4 FUN_00018d64(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (*(int *)(param_2 + 4) == 0) {
    iVar1 = FUN_00012318(param_1 + 0x50,(wchar_t *)(param_2 + 0x10),2,1,0);
    if ((iVar1 == 0) || (*(int *)(param_2 + 0xc) < 0)) {
      if (*(int *)(param_1 + 0x18) != 0) {
        if (iVar1 == 0) {
          uVar3 = 0xffffffff;
        }
        else {
          uVar3 = *(undefined4 *)(iVar1 + 0xcc);
        }
        (**(code **)(**(int **)(param_1 + 0x18) + 0x18))
                  (*(int **)(param_1 + 0x18),uVar3,*(undefined4 *)(param_2 + 0xdc),
                   *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 8));
      }
    }
    else {
      uVar2 = FUN_00018cc8(param_1 + -8,*(uint *)(param_2 + 8),iVar1,*(int **)(param_2 + 0xe4),
                           *(uint *)(param_2 + 0xe8));
      *(uint *)(param_2 + 8) = uVar2;
      piVar4 = *(int **)(param_1 + 0x18);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x14))
                  (piVar4,*(undefined4 *)(iVar1 + 0xcc),*(undefined4 *)(param_2 + 0xdc),
                   *(undefined4 *)(param_2 + 0xe0),uVar2);
      }
    }
  }
  return 0;
}



/* 00018e6c FUN_00018e6c */

/* Boundary evidence: original MIPS .pdata 00018e6c..000194a3. Semantic name remains unreviewed. */

undefined4 FUN_00018e6c(uint *param_1,uint *param_2,undefined4 *param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  HANDLE pvVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *local_2b8;
  uint *local_2b4;
  uint *local_2b0;
  undefined4 local_2ac;
  undefined4 *local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined1 auStack_298 [16];
  wchar_t awStack_288 [100];
  undefined4 local_1c0;
  uint local_1bc;
  undefined4 *local_1b8;
  int local_1b4;
  undefined4 local_1b0;
  wchar_t awStack_1ac [100];
  undefined4 local_e4;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  
  local_30 = DAT_0001d244;
  puVar10 = param_1 + 0x15;
  local_2ac = 0;
  local_2b8 = param_2;
  local_2b4 = param_1;
  local_2a8 = param_3;
  puVar1 = (uint *)FUN_00012154((int)puVar10);
  *param_3 = 0;
  *param_2 = 0;
  uVar6 = 0xc;
  memset(auStack_298,0,0xc);
  uVar8 = 0;
  if ((param_4 & 1) != 0) {
    uVar8 = 1;
    uVar6 = 0x14;
    if (((param_4 & 8) == 0) && ((param_4 & 0x80) != 0)) {
      uVar6 = (int)puVar1 * 0x180 + 0x14;
    }
    else {
      pvVar5 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00013c14,(LPVOID)0x0,0,(LPDWORD)0x0);
      CloseHandle(pvVar5);
    }
  }
  if ((param_4 & 2) != 0) {
    uVar8 = uVar8 + 1;
    uVar6 = uVar6 + 8;
    if (((param_4 & 8) == 0) && ((param_4 & 0x80) != 0)) {
      uVar6 = (int)puVar1 * 0x14 + uVar6;
    }
  }
  if ((param_4 & 4) != 0) {
    uVar8 = uVar8 + 1;
    uVar6 = uVar6 + 0xc;
    GetStoreInformation(&local_2a0);
  }
  if ((param_4 & 0x10) != 0) {
    uVar8 = uVar8 + 1;
    uVar6 = uVar6 + 8;
    puVar9 = (uint *)0x0;
    if (puVar1 != (uint *)0x0) {
      do {
        local_2b0 = puVar9;
        iVar2 = FUN_00012318((int)puVar10,(wchar_t *)&local_2b0,0,1,0);
        iVar2 = FUN_00013728((int *)(iVar2 + 0x1b4),0,(undefined4 *)0x0);
        puVar9 = (uint *)((int)puVar9 + 1);
        uVar6 = iVar2 + uVar6;
      } while (puVar9 < puVar1);
    }
  }
  if ((param_4 & 0x20) != 0) {
    local_2b0 = (uint *)((param_4 >> 0x1b) + 10000);
    uVar8 = uVar8 + 1;
    uVar6 = uVar6 + 0x10;
    iVar2 = FUN_00012318((int)puVar10,(wchar_t *)&local_2b0,3,1,0);
    if ((iVar2 != 0) && (*(int *)(*(int *)(iVar2 + 0xd4) + 0x20) != 0)) {
      memset(awStack_288,0,0xd8);
      local_1c0 = 0;
      wcscpy(awStack_288,(wchar_t *)(iVar2 + 4));
      local_1bc = param_4 >> 0x18 & 7;
      (**(code **)(*(int *)(iVar2 + 0xd4) + 0x20))(awStack_288);
      uVar6 = local_1b4 + uVar6;
    }
  }
  puVar3 = operator_new(uVar6);
  *local_2a8 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    local_2ac = 0x8007000e;
  }
  else {
    *local_2b8 = uVar6;
    memset(puVar3,0,uVar6);
    uVar6 = (int)puVar3 + 0xbU & 3;
    puVar9 = (uint *)(((int)puVar3 + 0xbU) - uVar6);
    *puVar9 = *puVar9 & -1 << (uVar6 + 1) * 8 | uVar8 >> (3 - uVar6) * 8;
    *puVar3 = 0xf0000001;
    puVar3[1] = 1;
    uVar6 = (uint)(puVar3 + 2) & 3;
    puVar9 = (uint *)((int)(puVar3 + 2) - uVar6);
    *puVar9 = *puVar9 & 0xffffffffU >> (4 - uVar6) * 8 | uVar8 << uVar6 * 8;
    puVar7 = puVar3 + 3;
    if ((param_4 & 1) != 0) {
      puVar7 = puVar3 + 5;
      puVar3[3] = 1;
      if (((param_4 & 8) == 0) && ((param_4 & 0x80) != 0)) {
        puVar3[4] = puVar1;
        local_2b8 = (uint *)0x0;
        if (puVar1 != (uint *)0x0) {
          puVar9 = (uint *)0x0;
          puVar3 = puVar7;
          do {
            local_2b8 = puVar9;
            iVar2 = FUN_00012318((int)puVar10,(wchar_t *)&local_2b8,0,1,0);
            memset(&local_1b0,0,0x180);
            local_1b0 = 0x180;
            wcscpy(awStack_1ac,(wchar_t *)(iVar2 + 4));
            (**(code **)(*(int *)(iVar2 + 0xd4) + 0x14))(&local_1b0);
            *puVar3 = local_e4;
            wcscpy((wchar_t *)(puVar3 + 1),(wchar_t *)(iVar2 + 4));
            StringCchCopyW((STRSAFE_LPWSTR)(puVar3 + 0x33),0x50,(STRSAFE_LPCWSTR)(iVar2 + 0xdc));
            puVar9 = (uint *)((int)puVar9 + 1);
            uVar4 = *(undefined4 *)(iVar2 + 0xcc);
            puVar3[0x5c] = local_40;
            puVar3[0x5d] = local_3c;
            puVar3[0x5e] = local_38;
            puVar3[0x5f] = local_34;
            puVar7 = puVar3 + 0x60;
            puVar3[0x5b] = uVar4;
            puVar3 = puVar7;
          } while (puVar9 < puVar1);
        }
      }
    }
    puVar3 = puVar7;
    if ((param_4 & 2) != 0) {
      *puVar7 = 2;
      puVar3 = puVar7 + 2;
      if (((param_4 & 8) == 0) && ((param_4 & 0x80) != 0)) {
        puVar7[1] = puVar1;
        puVar9 = (uint *)0x0;
        if (puVar1 != (uint *)0x0) {
          do {
            local_2b8 = puVar9;
            iVar2 = FUN_00012318((int)puVar10,(wchar_t *)&local_2b8,0,1,0);
            memset(&local_1b0,0,0x180);
            local_1b0 = 0x180;
            wcscpy(awStack_1ac,(wchar_t *)(iVar2 + 4));
            (**(code **)(*(int *)(iVar2 + 0xd4) + 0x14))(&local_1b0);
            uVar4 = *(undefined4 *)(iVar2 + 0xcc);
            puVar9 = (uint *)((int)puVar9 + 1);
            puVar3[1] = local_40;
            *puVar3 = uVar4;
            puVar3[2] = local_3c;
            puVar3[3] = local_38;
            puVar3[4] = local_34;
            puVar3 = puVar3 + 5;
          } while (puVar9 < puVar1);
        }
      }
    }
    puVar9 = local_2b4;
    if ((param_4 & 4) != 0) {
      *puVar3 = 4;
      puVar3[1] = local_2a0;
      puVar3[2] = local_29c;
      puVar3 = puVar3 + 3;
    }
    puVar7 = puVar3;
    if ((param_4 & 0x10) != 0) {
      *puVar3 = 0x10;
      puVar3[1] = 0;
      puVar7 = puVar3 + 2;
      if ((HANDLE)local_2b4[3] != (HANDLE)0x0) {
        WaitForSingleObject((HANDLE)local_2b4[3],40000);
        pvVar5 = (HANDLE)puVar9[3];
        if (pvVar5 != (HANDLE)0x0) {
          CloseHandle(pvVar5);
          puVar9[3] = 0;
        }
      }
      puVar9 = (uint *)0x0;
      if (puVar1 != (uint *)0x0) {
        do {
          local_2b4 = puVar9;
          iVar2 = FUN_00012318((int)puVar10,(wchar_t *)&local_2b4,0,1,0);
          if (*(int *)(iVar2 + 0x1b4) != 0) {
            puVar3[1] = puVar3[1] + 1;
            iVar2 = FUN_00013728((int *)(iVar2 + 0x1b4),*(undefined4 *)(iVar2 + 0xcc),puVar7);
            puVar7 = (undefined4 *)(iVar2 + (int)puVar7);
          }
          puVar9 = (uint *)((int)puVar9 + 1);
        } while (puVar9 < puVar1);
      }
    }
    if ((param_4 & 0x20) != 0) {
      *puVar7 = 0x20;
      local_2b4 = (uint *)((param_4 >> 0x1b) + 10000);
      puVar7[3] = param_4 >> 0x18 & 7;
      iVar2 = FUN_00012318((int)puVar10,(wchar_t *)&local_2b4,3,1,0);
      if ((iVar2 != 0) && (*(int *)(*(int *)(iVar2 + 0xd4) + 0x20) != 0)) {
        puVar7[2] = *(undefined4 *)(iVar2 + 0xcc);
        memset(awStack_288,0,0xd8);
        local_1c0 = 0;
        wcscpy(awStack_288,(wchar_t *)(iVar2 + 4));
        local_1bc = puVar7[3];
        local_1b8 = puVar7 + 4;
        iVar2 = (**(code **)(*(int *)(iVar2 + 0xd4) + 0x20))(awStack_288);
        if (-1 < iVar2) {
          puVar7[1] = local_1b4;
        }
      }
    }
  }
  FUN_0001c2c0(local_30);
  return local_2ac;
}



/* 000194a4 FUN_000194a4 */

/* Boundary evidence: original MIPS .pdata 000194a4..000196bb. Semantic name remains unreviewed. */

undefined4 FUN_000194a4(int param_1,uint param_2,int *param_3)

{
  void *_Dst;
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int local_100 [2];
  wchar_t awStack_f8 [100];
  undefined4 local_30;
  int local_2c;
  int *local_28;
  int local_24;
  uint local_20;
  
  local_20 = DAT_0001d244;
  if (*param_3 == -0xfffffff) {
    iVar1 = param_3[1];
    if (iVar1 == 2) {
      EventModify(*(undefined4 *)(param_1 + 0x18),2);
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
      uVar4 = 0;
      piVar2 = (int *)(param_1 + 0x38);
      do {
        if (*piVar2 == 0) break;
        uVar4 = uVar4 + 1;
        piVar2 = piVar2 + 1;
      } while (uVar4 < 5);
      if (uVar4 < 5) {
        _Dst = operator_new(0xf0);
        *(void **)((uVar4 + 0xe) * 4 + param_1) = _Dst;
        if (_Dst != (void *)0x0) {
          memcpy(_Dst,param_3,0xf0);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
      if (param_3[0x34] == 8) {
        *(undefined4 *)(param_1 + 0x1a8) = 1;
      }
      if (param_3[0x34] == 2) {
        CeEventHasOccurred(2,0);
      }
      else {
        WaitForSingleObject(*(HANDLE *)(param_1 + 0x18),60000);
      }
    }
    else if (iVar1 == 3) {
      FUN_000166bc(param_1 + -4,(int)param_3);
    }
    else if (iVar1 == 4) {
      local_100[0] = param_3[4];
      iVar1 = FUN_00012318(param_1 + 0x54,(wchar_t *)local_100,3,1,0);
      if (((iVar1 != 0) && (*(int *)(*(int *)(iVar1 + 0xd4) + 0x20) != 0)) &&
         (iVar3 = param_3[3], iVar3 + 0x28U <= param_2)) {
        memset(awStack_f8,0,0xd8);
        local_30 = 1;
        wcscpy(awStack_f8,(wchar_t *)(iVar1 + 4));
        local_2c = param_3[5];
        local_28 = param_3 + 10;
        local_24 = iVar3;
        (**(code **)(*(int *)(iVar1 + 0xd4) + 0x20))(awStack_f8);
      }
    }
  }
  FUN_0001c2c0(local_20);
  return 0;
}



/* 000196bc FUN_000196bc */

/* Boundary evidence: original MIPS .pdata 000196bc..000197fb. Semantic name remains unreviewed. */

undefined4 FUN_000196bc(void)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  undefined4 *puVar3;
  
  piVar2 = operator_new(0x24);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)(piVar2 + 4));
    piVar2[1] = 0;
    *piVar2 = 0;
    piVar2[2] = 0;
    piVar2[3] = 0;
  }
  DAT_0001d468 = piVar2;
  if (piVar2 != (int *)0x0) {
    bVar1 = FUN_000183e0((int)piVar2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      while (DAT_0001d468[3] == 0) {
        WaitForSingleObject((HANDLE)DAT_0001d468[2],0xffffffff);
        while (puVar3 = (undefined4 *)FUN_00018728(DAT_0001d468), puVar3 != (undefined4 *)0x0) {
          if ((DAT_0001d468[3] == 0) && (DAT_0001d314 != 0)) {
            FUN_0001879c(DAT_0001d314,*puVar3,puVar3[2],puVar3 + 4,puVar3[1]);
          }
          operator_delete(puVar3);
        }
      }
    }
    piVar2 = DAT_0001d468;
    if (DAT_0001d468 != (int *)0x0) {
      FUN_000185d0(DAT_0001d468);
      operator_delete(piVar2);
    }
    DAT_0001d468 = (int *)0x0;
  }
  return 0;
}



/* 000197fc FUN_000197fc */

/* Boundary evidence: original MIPS .pdata 000197fc..000198d7. Semantic name remains unreviewed. */

uint FUN_000197fc(void)

{
  LSTATUS LVar1;
  uint uVar2;
  uint local_70;
  HKEY local_6c;
  DWORD local_68 [2];
  WCHAR aWStack_60 [40];
  uint local_10;
  
  local_10 = DAT_0001d244;
  local_70 = 0;
  memcpy(aWStack_60,L"Software\\Microsoft\\Windows CE Services",0x4e);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,aWStack_60,0,0x20019,&local_6c);
  if (LVar1 == 0) {
    local_68[0] = 4;
    RegQueryValueExW(local_6c,L"IPVersionSetting",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_70,
                     local_68);
    RegCloseKey(local_6c);
  }
  uVar2 = local_70 & 3;
  if (uVar2 == 0) {
    uVar2 = 3;
  }
  FUN_0001c2c0(local_10);
  return uVar2;
}



/* 000198d8 FUN_000198d8 */

/* Boundary evidence: original MIPS .pdata 000198d8..00019a4b. Semantic name remains unreviewed. */

SOCKET FUN_000198d8(int param_1,uint param_2)

{
  int iVar1;
  SOCKET s;
  
  s = 0xffffffff;
  if (param_1 != 0) {
    do {
      iVar1 = *(int *)(param_1 + 4);
      if ((((iVar1 != 2) || ((param_2 & 1) != 0)) && ((iVar1 != 0x17 || ((param_2 & 2) != 0)))) &&
         (s = socket(iVar1,*(int *)(param_1 + 8),*(int *)(param_1 + 0xc)), s != 0xffffffff)) {
        iVar1 = connect(s,*(sockaddr **)(param_1 + 0x18),*(int *)(param_1 + 0x10));
        if (iVar1 != -1) break;
        iVar1 = WSAGetLastError();
        closesocket(s);
        s = 0xffffffff;
        WSASetLastError(iVar1);
      }
      param_1 = *(int *)(param_1 + 0x1c);
    } while (param_1 != 0);
    if ((param_1 == 0) && (s != 0xffffffff)) {
      iVar1 = WSAGetLastError();
      closesocket(s);
      s = 0xffffffff;
      if (iVar1 != 0) {
        WSASetLastError(iVar1);
      }
    }
  }
  return s;
}



/* 00019a4c FUN_00019a4c */

/* Boundary evidence: original MIPS .pdata 00019a4c..00019ab3. Semantic name remains unreviewed. */

void FUN_00019a4c(short *param_1,u_short param_2)

{
  u_short uVar1;
  
  if ((param_1 != (short *)0x0) && ((*param_1 == 2 || (*param_1 == 0x17)))) {
    uVar1 = htons(param_2);
    param_1[1] = uVar1;
  }
  return;
}



/* 00019ab4 FUN_00019ab4 */

/* Boundary evidence: original MIPS .pdata 00019ab4..00019bdb. Semantic name remains unreviewed. */

void FUN_00019ab4(HWND param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  WPARAM WVar4;
  BYTE aBStack_40 [32];
  uint local_20;
  
  local_20 = DAT_0001d244;
  iVar2 = FUN_0001494c();
  bVar1 = false;
  iVar3 = FUN_00014d08(1);
  if (iVar3 != 0) {
    FUN_00014dd0(1,aBStack_40);
    WVar4 = SendMessageW(param_1,0x143,0,(LPARAM)aBStack_40);
    if (iVar2 == 1) {
      SendMessageW(param_1,0x14e,WVar4,0);
      bVar1 = true;
    }
  }
  iVar3 = FUN_00014d08(2);
  if (iVar3 != 0) {
    FUN_00014dd0(2,aBStack_40);
    WVar4 = SendMessageW(param_1,0x143,0,(LPARAM)aBStack_40);
    if (iVar2 == 2) {
      SendMessageW(param_1,0x14e,WVar4,0);
      bVar1 = true;
    }
  }
  if (!bVar1) {
    SendMessageW(param_1,0x14e,0,0);
  }
  FUN_0001c2c0(local_20);
  return;
}



/* 00019bdc FUN_00019bdc */

/* Boundary evidence: original MIPS .pdata 00019bdc..00019e03. Semantic name remains unreviewed. */

void FUN_00019bdc(wchar_t *param_1)

{
  HWND hWnd;
  HDC hdc;
  size_t cchString;
  HGDIOBJ h;
  int local_40;
  int local_3c;
  tagSIZE local_38;
  tagRECT tStack_30;
  
  if (DAT_0001d47c != (HWND)0x0) {
    hWnd = GetDlgItem(DAT_0001d47c,0x3ed);
    hdc = GetDC(hWnd);
    cchString = wcslen(param_1);
    h = (HGDIOBJ)SendMessageW(hWnd,0x31,0,0);
    SelectObject(hdc,h);
    GetClientRect(hWnd,&tStack_30);
    GetTextExtentExPointW(hdc,param_1,cchString,tStack_30.right,&local_40,(LPINT)0x0,&local_38);
    if (local_40 < (int)cchString) {
      for (; 0 < local_40; local_40 = local_40 + -1) {
        if (param_1[local_40] == L' ') {
          param_1[local_40] = L'\n';
          local_40 = local_40 + 1;
          break;
        }
      }
      GetTextExtentExPointW
                (hdc,param_1 + local_40,cchString - local_40,tStack_30.right,&local_3c,(LPINT)0x0,
                 &local_38);
      if (local_3c + local_40 < (int)cchString) {
        if (DAT_0001d494 == 0) {
          GetTextExtentExPointW(hdc,L"...",3,0,(LPINT)0x0,(LPINT)0x0,&local_38);
          DAT_0001d494 = local_38.cx;
        }
        GetTextExtentExPointW
                  (hdc,param_1 + local_40,cchString - local_40,tStack_30.right - DAT_0001d494,
                   &local_3c,(LPINT)0x0,&local_38);
        wcscpy(param_1 + local_3c + local_40,L"...");
      }
    }
    ReleaseDC(hWnd,hdc);
    SetDlgItemTextW(DAT_0001d47c,0x3ed,param_1);
  }
  return;
}



/* 00019e04 FUN_00019e04 */

/* Boundary evidence: original MIPS .pdata 00019e04..00019fcb. Semantic name remains unreviewed. */

undefined4 FUN_00019e04(HWND param_1,int param_2,short param_3)

{
  HWND hWnd;
  char *buf;
  
  if (param_2 == 0x110) {
    DAT_0001d47c = param_1;
    SendDlgItemMessageW(param_1,0x3ea,0x401,0,0x10000);
    hWnd = GetDlgItem(param_1,0x3ea);
    EnableWindow(hWnd,0);
    DAT_0001d46c = FUN_00014b78();
    SendDlgItemMessageW(param_1,0x3eb,0xf1,(uint)(DAT_0001d46c != 0),0);
    buf = "\x01";
  }
  else {
    if (param_2 != 0x111) {
      return 0;
    }
    if (param_3 != 1) {
      if (param_3 == 2) {
        DAT_0001d47c = (HWND)0x0;
        send(DAT_0001d254,"",4,0);
        FUN_00014c34(DAT_0001d46c);
        EndDialog(param_1,2);
        return 1;
      }
      if (param_3 != 0x3eb) {
        return 1;
      }
      DAT_0001d46c = SendDlgItemMessageW(param_1,0x3eb,0xf0,0,0);
      return 1;
    }
    if (DAT_0001d478 == 0) {
      buf = "\x02";
    }
    else {
      buf = "\x03";
    }
  }
  send(DAT_0001d254,buf,4,0);
  return 1;
}



/* 00019fcc FUN_00019fcc */

/* Boundary evidence: original MIPS .pdata 00019fcc..0001a097. Semantic name remains unreviewed. */

void FUN_00019fcc(UINT param_1)

{
  WCHAR aWStack_b8 [80];
  uint local_18;
  
  local_18 = DAT_0001d244;
  LoadStringW(DAT_0001d344,param_1,aWStack_b8,0x50);
  if (DAT_0001d470 != (HWND)0x0) {
    SetDlgItemTextW(DAT_0001d470,0x3ec,aWStack_b8);
  }
  if (((((param_1 == 0x7ec) || (param_1 == 0x7e8)) || (param_1 == 0x7e9)) || (param_1 == 0x7fd)) &&
     (DAT_0001d254 != -1)) {
    closesocket(DAT_0001d254);
    DAT_0001d254 = -1;
  }
  FUN_0001c2c0(local_18);
  return;
}



/* 0001a098 FUN_0001a098 */

/* Boundary evidence: original MIPS .pdata 0001a098..0001a12f. Semantic name remains unreviewed. */

undefined4 FUN_0001a098(HWND param_1,int param_2,short param_3)

{
  INT_PTR nResult;
  undefined4 uVar1;
  
  if (param_2 == 0x110) {
    uVar1 = 1;
    DAT_0001d470 = param_1;
  }
  else if (param_2 == 0x111) {
    uVar1 = 1;
    if (param_3 == 1) {
      nResult = 1;
    }
    else {
      if (param_3 != 2) {
        return 1;
      }
      nResult = 2;
    }
    DAT_0001d470 = (HWND)0x0;
    EndDialog(param_1,nResult);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 0001a130 FUN_0001a130 */

/* Boundary evidence: original MIPS .pdata 0001a130..0001a7d7. Semantic name remains unreviewed. */

undefined4 FUN_0001a130(void)

{
  int iVar1;
  DWORD DVar2;
  HWND pHVar3;
  wchar_t *pwVar4;
  UINT uID;
  uint uVar5;
  int iVar6;
  int local_8d8;
  uint local_8d4;
  char local_8d0 [4];
  LPARAM local_8cc;
  sockaddr local_8c8 [8];
  WSADATA WStack_848;
  WCHAR aWStack_6b8 [260];
  WCHAR aWStack_4b0 [64];
  undefined1 auStack_430 [1024];
  uint local_30;
  
  local_30 = DAT_0001d244;
  iVar6 = 0xf;
  if (DAT_0001d2e0 == 0) {
    WaitForSingleObject(DAT_0001d474,0xffffffff);
  }
  if (DAT_0001d474 != (HANDLE)0x0) {
    EventModify(DAT_0001d474,2);
    iVar1 = WSAStartup(0x202,&WStack_848);
    if (iVar1 == 0) {
      memcpy(local_8c8,&DAT_0001d260,0x80);
      FUN_00019a4c((short *)local_8c8,999);
      DAT_0001d254 = socket((int)(short)local_8c8[0].sa_family,1,0);
      if (DAT_0001d254 == 0xffffffff) goto LAB_0001a78c;
      do {
        iVar1 = connect(DAT_0001d254,local_8c8,0x80);
        if (iVar1 != -1) {
          if (iVar6 != 0) {
            LoadStringW(DAT_0001d344,0x805,aWStack_4b0,0x40);
            goto LAB_0001a2d4;
          }
          break;
        }
        DVar2 = GetLastError();
        if ((DVar2 != 0x274c) && (DVar2 != 0x274d)) goto LAB_0001a76c;
        if (DAT_0001d254 == 0xffffffff) goto LAB_0001a78c;
        Sleep(2000);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      FUN_00019fcc(0x7fc);
    }
  }
LAB_0001a76c:
  if (DAT_0001d254 != 0xffffffff) {
    closesocket(DAT_0001d254);
    DAT_0001d254 = 0xffffffff;
  }
LAB_0001a78c:
  WSACleanup();
  FUN_0001c2c0(local_30);
  return 0;
LAB_0001a2d4:
  if (DAT_0001d470 != (HWND)0x0) {
    SendMessageW(DAT_0001d470,0x111,1,0);
  }
  DVar2 = WaitForSingleObject(DAT_0001d474,0);
  if ((DVar2 != 0x102) || (iVar6 = FUN_00014354(DAT_0001d254,(int)&local_8d4,4), iVar6 != 4))
  goto LAB_0001a76c;
  uVar5 = local_8d4 >> 0x10;
  if (uVar5 != 1) {
    if (uVar5 == 4) {
      iVar6 = 0;
      if ((local_8d4 & 0xffff) != 0) {
        do {
          iVar1 = FUN_00014354(DAT_0001d254,(int)local_8d0,4);
          if (((((iVar1 != 4) || (iVar1 = FUN_00014354(DAT_0001d254,(int)&local_8d8,4), iVar1 != 4))
               || (iVar1 = FUN_00014354(DAT_0001d254,(int)auStack_430,local_8d8), iVar1 != local_8d8
                  )) || ((iVar1 = FUN_00014354(DAT_0001d254,(int)&local_8d8,4), iVar1 != 4 ||
                         (iVar1 = FUN_00014354(DAT_0001d254,(int)auStack_430,local_8d8),
                         iVar1 != local_8d8)))) ||
             ((iVar1 = FUN_00014354(DAT_0001d254,(int)&local_8d8,4), iVar1 != 4 ||
              (iVar1 = FUN_00014354(DAT_0001d254,(int)auStack_430,local_8d8), iVar1 != local_8d8))))
          goto LAB_0001a76c;
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)(local_8d4 & 0xffff));
      }
      local_8d0[0] = '\0';
      local_8d0[1] = '\0';
      local_8d0[2] = '\0';
      local_8d0[3] = '\0';
      iVar6 = send(DAT_0001d254,"\x04",4,0);
      if (iVar6 != 4) goto LAB_0001a76c;
      iVar6 = 0;
      if ((short)local_8d4 != 0) {
        do {
          iVar1 = send(DAT_0001d254,local_8d0,4,0);
          if (iVar1 != 4) goto LAB_0001a76c;
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)(local_8d4 & 0xffff));
      }
    }
    else {
      if (uVar5 == 10) {
        DAT_0001d490 = 1;
        uVar5 = FUN_00014354(DAT_0001d254,(int)aWStack_6b8,local_8d4 & 0xffff);
        if ((uVar5 == (local_8d4 & 0xffff)) && (DAT_0001d47c != (HWND)0x0)) {
          SendDlgItemMessageW(DAT_0001d47c,0x3ea,0x402,0,0);
          FUN_00019bdc(aWStack_6b8);
          LoadStringW(DAT_0001d344,0x7f0,aWStack_6b8,0x104);
          SetDlgItemTextW(DAT_0001d47c,0x3ec,aWStack_6b8);
          pHVar3 = GetDlgItem(DAT_0001d47c,1);
          EnableWindow(pHVar3,0);
          pHVar3 = GetDlgItem(DAT_0001d47c,2);
          SetFocus(pHVar3);
        }
        goto LAB_0001a76c;
      }
      if (uVar5 == 0x5a) {
        DAT_0001d478 = 1;
        if (DAT_0001d47c != (HWND)0x0) {
          LoadStringW(DAT_0001d344,0x7fb,aWStack_6b8,0x104);
          SetDlgItemTextW(DAT_0001d47c,1,aWStack_6b8);
          pHVar3 = GetDlgItem(DAT_0001d47c,0x3ea);
          EnableWindow(pHVar3,1);
        }
      }
      else if (uVar5 == 0x5b) {
        DAT_0001d478 = 0;
        if (DAT_0001d47c != (HWND)0x0) {
          SendDlgItemMessageW(DAT_0001d47c,0x3ea,0x402,0,0);
          pHVar3 = GetDlgItem(DAT_0001d47c,0x3ea);
          EnableWindow(pHVar3,0);
          LoadStringW(DAT_0001d344,0x7fa,aWStack_6b8,0x104);
          SetDlgItemTextW(DAT_0001d47c,1,aWStack_6b8);
          if (DAT_0001d46c != 0) {
            SendMessageW(DAT_0001d47c,0x111,2,0);
          }
        }
      }
      else if (uVar5 == 0x5c) {
        iVar6 = FUN_00014354(DAT_0001d254,(int)&local_8cc,4);
        if (iVar6 != 4) goto LAB_0001a76c;
        if (DAT_0001d47c != (HWND)0x0) {
          SendDlgItemMessageW(DAT_0001d47c,0x3ea,0x401,0,local_8cc);
        }
      }
      else if ((uVar5 == 0x5d) && (DAT_0001d47c != (HWND)0x0)) {
        SendDlgItemMessageW(DAT_0001d47c,0x3ea,0x402,local_8d4 & 0xffff,0);
      }
    }
    goto LAB_0001a2d4;
  }
  uVar5 = FUN_00014354(DAT_0001d254,(int)aWStack_6b8,local_8d4 & 0xffff);
  if (uVar5 != (local_8d4 & 0xffff)) goto LAB_0001a76c;
  if (DAT_0001d47c != (HWND)0x0) {
    iVar6 = lstrcmpW(aWStack_6b8,L"$UPTODATE$");
    pwVar4 = L"";
    if (iVar6 != 0) {
      pwVar4 = aWStack_6b8;
    }
    FUN_00019bdc(pwVar4);
    if (DAT_0001d478 == 0) {
      uID = 0x7ed;
      if (iVar6 != 0) {
        uID = 0x7ee;
      }
    }
    else {
      uID = 0x7ef;
    }
    LoadStringW(DAT_0001d344,uID,aWStack_6b8,0x104);
    SetDlgItemTextW(DAT_0001d47c,0x3ec,aWStack_6b8);
  }
  goto LAB_0001a2d4;
}



/* 0001a7d8 FUN_0001a7d8 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 0001a7d8..0001a92f. Semantic name remains unreviewed. */

undefined4 FUN_0001a7d8(void)

{
  int iVar1;
  hostent *phVar2;
  char *pcVar3;
  char **ppcVar4;
  char **ppcVar5;
  uint uVar6;
  undefined4 uVar7;
  uint local_2b0 [54];
  WSADATA WStack_1d8;
  char acStack_48 [16];
  WCHAR aWStack_38 [16];
  uint local_18;
  
  local_18 = DAT_0001d244;
  uVar7 = 0;
  iVar1 = WSAStartup(0x101,&WStack_1d8);
  if (iVar1 == 0) {
    iVar1 = gethostname(acStack_48,0x10);
    if (iVar1 == 0) {
      MultiByteToWideChar(0,0,acStack_48,0x10,aWStack_38,0x10);
      phVar2 = gethostbyname(acStack_48);
      if (phVar2 != (hostent *)0x0) {
        ppcVar5 = phVar2->h_addr_list;
        iVar1 = 0;
        uVar6 = 0;
        pcVar3 = *ppcVar5;
        ppcVar4 = ppcVar5;
        while (pcVar3 != (char *)0x0) {
          if (*(int *)*ppcVar4 != 0x100007f) {
            uVar6 = uVar6 + 1;
          }
          iVar1 = iVar1 + 1;
          ppcVar4 = ppcVar5 + iVar1;
          pcVar3 = *ppcVar4;
        }
        local_2b0[1] = 0xd0;
        local_2b0[0] = 0;
        local_2b0[2] = 0x34;
        iVar1 = RasEnumConnections(local_2b0 + 2,local_2b0 + 1,local_2b0);
        if ((iVar1 == 0) && (local_2b0[0] < uVar6)) {
          uVar7 = 1;
        }
      }
    }
    WSACleanup();
  }
  FUN_0001c2c0(local_18);
  return uVar7;
}



/* 0001a930 FUN_0001a930 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 0001a930..0001ac97. Semantic name remains unreviewed. */

void FUN_0001a930(HWND param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined4 *hMem;
  LRESULT LVar3;
  int iVar4;
  undefined4 *_Dst;
  short *lParam;
  WPARAM wParam;
  uint uVar5;
  uint local_2b0 [2];
  SIZE_T local_2a8;
  WPARAM local_2a4;
  undefined4 local_2a0 [12];
  WCHAR aWStack_270 [32];
  wchar_t local_230 [128];
  undefined4 local_130 [2];
  wchar_t awStack_128 [126];
  uint local_2c;
  
  local_2c = DAT_0001d244;
  wParam = 0;
  local_2a8 = 0x30;
  local_2a4 = 0;
  local_2b0[1] = 0xd0;
  local_2b0[0] = 0;
  iVar4 = 0;
  local_230[0] = L'\0';
  local_130[0] = 0x34;
  iVar2 = RasEnumConnections(local_130,local_2b0 + 1,local_2b0);
  if ((iVar2 == 0) && (local_2b0[0] != 0)) {
    wcscpy(local_230,awStack_128);
    iVar4 = 1;
  }
  DAT_0001d480 = iVar4;
  if ((iVar4 == 0) && (uVar1 = FUN_000149f0((LPBYTE)local_230), CONCAT22(extraout_var,uVar1) == 0))
  {
    local_230[0] = L'\0';
  }
  local_2a0[0] = 0x30;
  RasEnumEntries(0,0,local_2a0,&local_2a8,0);
  if (local_2a8 != 0) {
    local_2b0[1] = 0;
    _Dst = (undefined4 *)0x0;
    hMem = LocalAlloc(0x40,local_2a8);
    if (hMem != (undefined4 *)0x0) {
      local_2b0[0] = 0;
      *hMem = 0x30;
      RasEnumEntries(0,0,hMem,&local_2a8,local_2b0);
      uVar5 = 0;
      if (local_2b0[0] != 0) {
        lParam = (short *)(hMem + 1);
        do {
          if ((_Dst == (undefined4 *)0x0) &&
             (_Dst = LocalAlloc(0x40,0xd90), _Dst == (undefined4 *)0x0)) {
LAB_0001aaf8:
            SendMessageW(param_1,0x143,0,(LPARAM)lParam);
          }
          else {
            memset(_Dst,0,0xd90);
            local_2b0[1] = 0xd90;
            *_Dst = 0xd90;
            iVar2 = RasGetEntryProperties(0,lParam,_Dst,local_2b0 + 1,0,0);
            if ((iVar2 == 0) &&
               ((iVar2 = lstrcmpW((LPCWSTR)(_Dst + 0x1d9),L"direct"), iVar2 != 0 ||
                (*lParam == 0x60)))) goto LAB_0001aaf8;
          }
          uVar5 = uVar5 + 1;
          lParam = lParam + 0x18;
          wParam = local_2a4;
        } while (uVar5 < local_2b0[0]);
      }
      LocalFree(_Dst);
      LocalFree(hMem);
    }
  }
  iVar2 = FUN_0001a7d8();
  if (iVar2 != 0) {
    LoadStringW(DAT_0001d344,0x7e5,aWStack_270,0x20);
    SendMessageW(param_1,0x143,0,(LPARAM)aWStack_270);
  }
  LVar3 = SendMessageW(param_1,0x146,0,0);
  if (0 < LVar3) {
    do {
      SendMessageW(param_1,0x148,0,(LPARAM)local_130);
      if ((short)local_130[0] == 0x60) {
        SendMessageW(param_1,0x144,0,0);
        SendMessageW(param_1,0x14a,0xffffffff,(LPARAM)local_130);
      }
      LVar3 = LVar3 + -1;
    } while (LVar3 != 0);
  }
  if ((local_230[0] != L'\0') &&
     (wParam = SendMessageW(param_1,0x158,0xffffffff,(LPARAM)local_230), wParam == 0xffffffff)) {
    wParam = 0;
  }
  SendMessageW(param_1,0x14e,wParam,0);
  if (DAT_0001d480 != 0) {
    EnableWindow(param_1,0);
    wcscpy(&DAT_0001d34c,local_230);
  }
  FUN_0001c2c0(local_2c);
  return;
}



/* 0001ac98 FUN_0001ac98 */

/* Boundary evidence: original MIPS .pdata 0001ac98..0001adb3. Semantic name remains unreviewed. */

undefined4 FUN_0001ac98(HWND param_1,int param_2,short param_3)

{
  HWND pHVar1;
  INT_PTR nResult;
  undefined4 uVar2;
  
  if (param_2 == 0x110) {
    pHVar1 = GetDlgItem(param_1,0x3e9);
    FUN_0001a930(pHVar1);
    pHVar1 = GetDlgItem(param_1,0x3ea);
    FUN_00019ab4(pHVar1);
    uVar2 = 1;
    DAT_0001d48c = param_1;
  }
  else if (param_2 == 0x111) {
    uVar2 = 1;
    if (param_3 == 1) {
      pHVar1 = GetDlgItem(param_1,0x3e9);
      GetWindowTextW(pHVar1,&DAT_0001d34c,0x80);
      pHVar1 = GetDlgItem(param_1,0x3ea);
      GetWindowTextW(pHVar1,&DAT_0001d318,0x10);
      FUN_00014aa0(&DAT_0001d34c);
      nResult = 1;
    }
    else {
      if (param_3 != 2) {
        return 1;
      }
      nResult = 2;
    }
    DAT_0001d48c = (HWND)0x0;
    EndDialog(param_1,nResult);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0001adb4 FUN_0001adb4 */

/* Boundary evidence: original MIPS .pdata 0001adb4..0001b1ff. Semantic name remains unreviewed. */

LRESULT FUN_0001adb4(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  HWND hWnd;
  HRSRC pHVar2;
  LPCDLGTEMPLATEW pDVar3;
  INT_PTR IVar4;
  WPARAM wParam;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_0001d244;
  if (param_2 == 1) {
    DAT_0001d498 = (HANDLE)0x0;
    DAT_0001d474 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    wParam = 0x78;
    if (DAT_0001d310 != 0) {
      wParam = 0x7a;
    }
LAB_0001b1cc:
    PostMessageW(param_1,0x111,wParam,0);
  }
  else {
    if (param_2 == 2) {
      DAT_0001d488 = 0;
      if (DAT_0001d474 != (HANDLE)0x0) {
        EventModify(DAT_0001d474,3);
        CloseHandle(DAT_0001d474);
        DAT_0001d474 = (HANDLE)0x0;
      }
      if (DAT_0001d254 != -1) {
        closesocket(DAT_0001d254);
        DAT_0001d254 = -1;
      }
      if (DAT_0001d498 != (HANDLE)0x0) {
        CloseHandle(DAT_0001d498);
        DAT_0001d498 = (HANDLE)0x0;
      }
      if (DAT_0001d338 != 0) {
        PostMessageW(DAT_0001d25c,0x10,0,0);
      }
      PostQuitMessage(0);
      goto LAB_0001b1d4;
    }
    if (param_2 != 0x10) {
      if (param_2 != 0x111) {
        LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
        FUN_0001c2c0(local_20);
        return LVar1;
      }
      if (param_3 == 0x78) {
        DAT_0001d338 = 1;
        if (DAT_0001d30c == 0) {
          pHVar2 = FindResourceW(DAT_0001d344,(LPCWSTR)0x6e,(LPCWSTR)0x5);
          pDVar3 = LoadResource(DAT_0001d344,pHVar2);
          IVar4 = DialogBoxIndirectParamW(DAT_0001d344,pDVar3,param_1,FUN_0001ac98,0);
          if (IVar4 != 1) goto LAB_0001b084;
        }
        PostMessageW(DAT_0001d25c,0x46f,0,0);
LAB_0001b0ac:
        wParam = 0x7a;
        goto LAB_0001b1cc;
      }
      if (param_3 == 0x79) {
        pHVar2 = FindResourceW(DAT_0001d344,(LPCWSTR)0x6f,(LPCWSTR)0x5);
        pDVar3 = LoadResource(DAT_0001d344,pHVar2);
        DialogBoxIndirectParamW(DAT_0001d344,pDVar3,param_1,FUN_00019e04,0);
        if (DAT_0001d484 != 0) {
          DAT_0001d484 = 0;
          goto LAB_0001b0ac;
        }
      }
      else {
        if (param_3 != 0x7a) {
          if (param_3 == 0x4cf) {
            if ((DAT_0001d490 == 0) && (DAT_0001d47c != (HWND)0x0)) {
              SendDlgItemMessageW(DAT_0001d47c,0x3ea,0x402,0,0);
              LoadStringW(DAT_0001d344,0x7f3,aWStack_228,0x104);
              FUN_00019bdc(aWStack_228);
              LoadStringW(DAT_0001d344,0x7f0,aWStack_228,0x104);
              SetDlgItemTextW(DAT_0001d47c,0x3ec,aWStack_228);
              hWnd = GetDlgItem(DAT_0001d47c,1);
              EnableWindow(hWnd,0);
            }
          }
          else if ((param_3 == 0x4d0) && (DAT_0001d47c != (HWND)0x0)) {
            DAT_0001d484 = 1;
            SendMessageW(DAT_0001d47c,0x111,2,0);
          }
          goto LAB_0001b1d4;
        }
        DAT_0001d498 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001a130,(LPVOID)0x0,0,
                                    (LPDWORD)0x0);
        if (DAT_0001d498 != (HANDLE)0x0) {
          pHVar2 = FindResourceW(DAT_0001d344,(LPCWSTR)0x70,(LPCWSTR)0x5);
          pDVar3 = LoadResource(DAT_0001d344,pHVar2);
          IVar4 = DialogBoxIndirectParamW(DAT_0001d344,pDVar3,param_1,FUN_0001a098,0);
          if (IVar4 != 2) {
            wParam = 0x79;
            goto LAB_0001b1cc;
          }
        }
      }
    }
LAB_0001b084:
    DestroyWindow(param_1);
  }
LAB_0001b1d4:
  FUN_0001c2c0(local_20);
  return 0;
}



/* 0001b200 FUN_0001b200 */

/* Boundary evidence: original MIPS .pdata 0001b200..0001b3f7. Semantic name remains unreviewed. */

undefined4 FUN_0001b200(void)

{
  ATOM AVar1;
  HMODULE hLibModule;
  code *pcVar2;
  undefined2 extraout_var;
  BOOL BVar3;
  undefined4 local_70;
  undefined4 local_6c;
  MSG MStack_68;
  WNDCLASSW local_48;
  
  hLibModule = LoadLibraryW(L"commctrl.dll");
  if (hLibModule == (HMODULE)0x0) goto LAB_0001b3a4;
  pcVar2 = (code *)GetProcAddressW(hLibModule,L"InitCommonControls");
  if (pcVar2 != (code *)0x0) {
    if (DAT_0001d49c == 0) {
      local_48.style = 0;
      local_48.lpfnWndProc = FUN_0001adb4;
      local_48.cbClsExtra = 0;
      local_48.cbWndExtra = 0;
      local_48.hInstance = DAT_0001d344;
      local_48.hIcon = LoadImageW(DAT_0001d344,(LPCWSTR)0x64,1,0x10,0x10,0);
      local_48.hCursor = (HCURSOR)0x0;
      local_48.hbrBackground = GetStockObject(0);
      local_48.lpszMenuName = (LPCWSTR)0x0;
      local_48.lpszClassName = L"ActiveSync";
      AVar1 = RegisterClassW(&local_48);
      DAT_0001d49c = CONCAT22(extraout_var,AVar1);
      if (DAT_0001d49c == 0) goto LAB_0001b394;
    }
    (*pcVar2)();
    pcVar2 = (code *)GetProcAddressW(hLibModule,L"InitCommonControlsEx");
    if (pcVar2 != (code *)0x0) {
      local_70 = 8;
      local_6c = 0x1000;
      (*pcVar2)(&local_70);
      DAT_0001d488 = CreateWindowExW(0,L"ActiveSync",L"ActiveSync",0x10c80000,-0x32,-0x32,1,1,
                                     (HWND)0x0,(HMENU)0x0,DAT_0001d344,(LPVOID)0x0);
      if (DAT_0001d488 != (HWND)0x0) {
        while (BVar3 = GetMessageW(&MStack_68,(HWND)0x0,0,0), BVar3 != 0) {
          TranslateMessage(&MStack_68);
          DispatchMessageW(&MStack_68);
        }
      }
    }
  }
LAB_0001b394:
  FreeLibrary(hLibModule);
LAB_0001b3a4:
  if (DAT_0001d33c != 0) {
    CloseHandle((HANDLE)DAT_0001d33c);
    DAT_0001d33c = 0;
  }
  return 0;
}



/* 0001b3f8 FUN_0001b3f8 */

/* Boundary evidence: original MIPS .pdata 0001b3f8..0001b4b3. Semantic name remains unreviewed. */

void FUN_0001b3f8(int *param_1)

{
  if (*param_1 != 0) {
    EventModify(param_1[2],3);
    CloseHandle((HANDLE)*param_1);
  }
  if ((HANDLE)param_1[2] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[2]);
  }
  if ((HANDLE)param_1[3] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[3]);
  }
  if (param_1[0x28] != 0xffffffff) {
    closesocket(param_1[0x28]);
  }
  if (param_1[0x31] != 0) {
    freeaddrinfo();
  }
  return;
}



/* 0001b4b4 FUN_0001b4b4 */

/* Boundary evidence: original MIPS .pdata 0001b4b4..0001b533. Semantic name remains unreviewed. */

bool FUN_0001b4b4(int param_1,undefined4 *param_2,void *param_3,void *param_4)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x90) == 100;
  if (bVar1) {
    *param_2 = *(undefined4 *)(param_1 + 0xa0);
    memcpy(param_3,(void *)(param_1 + 0xa4),0x20);
    memcpy(param_4,*(void **)(param_1 + 200),0x80);
    *(undefined4 *)(param_1 + 0xa0) = 0xffffffff;
    *(undefined4 *)(param_1 + 200) = 0;
  }
  return bVar1;
}



/* 0001b534 FUN_0001b534 */

/* Boundary evidence: original MIPS .pdata 0001b534..0001b567. Semantic name remains unreviewed. */

void FUN_0001b534(int param_1,LONG param_2)

{
  InterlockedExchange((LONG *)(param_1 + 0x90),param_2);
  EventModify(*(undefined4 *)(param_1 + 0xc),3);
  return;
}



/* 0001b568 FUN_0001b568 */

/* Boundary evidence: original MIPS .pdata 0001b568..0001b5e3. Semantic name remains unreviewed. */

void FUN_0001b568(int param_1)

{
  HWND hWnd;
  size_t sVar1;
  undefined4 local_20;
  int local_1c;
  wchar_t *local_18;
  
  hWnd = FindWindowW(L"RapiSrv",(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    local_20 = 0x1f5;
    sVar1 = wcslen((wchar_t *)(param_1 + 0xa4));
    local_1c = sVar1 << 1;
    local_18 = (wchar_t *)(param_1 + 0xa4);
    SendMessageW(hWnd,0x4a,DAT_0001d338,(LPARAM)&local_20);
  }
  return;
}



/* 0001b5e4 FUN_0001b5e4 */

/* Boundary evidence: original MIPS .pdata 0001b5e4..0001b63f. Semantic name remains unreviewed. */

void FUN_0001b5e4(int param_1,int param_2)

{
  WPARAM wParam;
  LPARAM lParam;
  
  wParam = 0x7db;
  if (param_2 == 0x2745) {
    wParam = 0x802;
    lParam = 0x803;
  }
  else if ((param_2 < 0x274c) || (0x274d < param_2)) {
    lParam = 0x7dc;
  }
  else {
    lParam = 0x7f9;
  }
  PostMessageW(*(HWND *)(param_1 + 0x94),0x600,wParam,lParam);
  return;
}



/* 0001b640 FUN_0001b640 */

/* Boundary evidence: original MIPS .pdata 0001b640..0001b8fb. Semantic name remains unreviewed. */

void FUN_0001b640(int param_1)

{
  undefined2 uVar1;
  char *buf;
  LSTATUS LVar2;
  undefined4 uVar3;
  undefined2 extraout_var;
  size_t sVar4;
  BOOL BVar5;
  wchar_t *_Str;
  HKEY local_238;
  HKEY local_234;
  uint local_230;
  DWORD local_22c;
  _SYSTEM_INFO _Stack_228;
  _OSVERSIONINFOW local_200;
  WCHAR aWStack_e8 [100];
  uint local_20;
  
  local_20 = DAT_0001d244;
  buf = LocalAlloc(0x40,0x45c);
  if (buf != (char *)0x0) {
    buf[0] = '(';
    buf[1] = '\0';
    buf[2] = '\0';
    buf[3] = '\0';
    local_200.dwOSVersionInfoSize = 0x114;
    GetVersionExW(&local_200);
    *(DWORD *)(buf + 4) =
         (local_200.dwMinorVersion & 0xff) << 8 | local_200.dwBuildNumber << 0x10 |
         (uint)(byte)local_200.dwMajorVersion;
    GetSystemInfo(&_Stack_228);
    *(DWORD *)(buf + 8) = _Stack_228.dwProcessorType;
    *(uint *)(buf + 0xc) = (*(uint *)(param_1 + 0x9c) & 1) != 0 | 2;
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Windows CE Services\\Synchronization",0,0x20019,
                          &local_238);
    if (LVar2 == 0) {
      LVar2 = RegOpenKeyExW(local_238,L"Objects",0,0x20019,&local_234);
      if (LVar2 == 0) {
        local_22c = 100;
        LVar2 = RegEnumKeyExW(local_234,0,aWStack_e8,&local_22c,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,(PFILETIME)0x0);
        if (LVar2 != 0x103) {
          *(uint *)(buf + 0xc) = *(uint *)(buf + 0xc) & 0xfffffffd;
          uVar3 = FUN_00014d08(1);
          *(undefined4 *)(buf + 0x10) = uVar3;
          uVar3 = FUN_00014d08(2);
          *(undefined4 *)(buf + 0x14) = uVar3;
        }
        RegCloseKey(local_234);
      }
      RegCloseKey(local_238);
    }
    _Str = (wchar_t *)(buf + 0x28);
    uVar1 = FUN_00014ea4((LPBYTE)_Str);
    if (CONCAT22(extraout_var,uVar1) != 0) {
      *(int *)(buf + 0x18) = (int)_Str - (int)buf;
      sVar4 = wcslen(_Str);
      _Str = _Str + sVar4 + 1;
    }
    BVar5 = SystemParametersInfoW(0x104,0x208,_Str,0);
    if (BVar5 != 0) {
      *(int *)(buf + 0x1c) = (int)_Str - (int)buf;
      sVar4 = wcslen(_Str);
      _Str = _Str + sVar4 + 1;
    }
    BVar5 = SystemParametersInfoW(0x102,0x208,_Str,0);
    if (BVar5 != 0) {
      *(int *)(buf + 0x20) = (int)_Str - (int)buf;
      sVar4 = wcslen(_Str);
      _Str = _Str + sVar4 + 1;
    }
    local_230 = (int)_Str - (int)buf;
    send(*(SOCKET *)(param_1 + 0xa0),(char *)&local_230,4,0);
    if (local_230 < 0x435) {
      send(*(SOCKET *)(param_1 + 0xa0),buf,local_230,0);
    }
    LocalFree(buf);
  }
  FUN_0001c2c0(local_20);
  return;
}



/* 0001b8fc FUN_0001b8fc */

/* Boundary evidence: original MIPS .pdata 0001b8fc..0001b93b. Semantic name remains unreviewed. */

void FUN_0001b8fc(int *param_1)

{
  if (99 < (uint)param_1[0x24]) {
    FUN_0001b3f8(param_1);
    operator_delete(param_1);
  }
  return;
}



/* 0001b93c FUN_0001b93c */

/* Boundary evidence: original MIPS .pdata 0001b93c..0001bb3f. Semantic name remains unreviewed. */

bool FUN_0001b93c(int param_1)

{
  int iVar1;
  int iVar2;
  UINT Msg;
  wchar_t *_Dest;
  int *piVar3;
  undefined1 auStack_70 [4];
  undefined4 local_6c;
  undefined4 local_68;
  CHAR aCStack_50 [16];
  char acStack_40 [16];
  uint local_30;
  
  local_30 = DAT_0001d244;
  piVar3 = (int *)(param_1 + 0xc4);
  if (*piVar3 != 0) {
    freeaddrinfo();
    *piVar3 = 0;
  }
  memset(auStack_70,0,0x20);
  local_6c = 0;
  local_68 = 1;
  sprintf(acStack_40,"%d",0x162f);
  _Dest = (wchar_t *)(param_1 + 0xa4);
  if (*_Dest == L'\0') {
    wcscpy(_Dest,L"ppp_peer");
  }
  WideCharToMultiByte(0,0,_Dest,0x10,aCStack_50,0x10,(LPCSTR)0x0,(LPBOOL)0x0);
  iVar1 = getaddrinfo(aCStack_50,acStack_40,auStack_70,piVar3);
  do {
    if (iVar1 == 0) {
      Msg = 0x601;
LAB_0001bac8:
      PostMessageW(*(HWND *)(param_1 + 0x94),Msg,0,0);
      FUN_0001c2c0(local_30);
      return iVar1 == 0;
    }
    iVar2 = lstrcmpW(_Dest,L"ppp_peer");
    if (iVar2 == 0) {
      InterlockedExchange((LONG *)(param_1 + 0x90),0x65);
      EventModify(*(undefined4 *)(param_1 + 0xc),3);
      Msg = 0x600;
      goto LAB_0001bac8;
    }
    wcscpy(_Dest,L"ppp_peer");
    WideCharToMultiByte(0,0,_Dest,0x10,aCStack_50,0x10,(LPCSTR)0x0,(LPBOOL)0x0);
    iVar1 = getaddrinfo(aCStack_50,acStack_40,auStack_70,piVar3);
  } while( true );
}



/* 0001bb40 FUN_0001bb40 */

/* Boundary evidence: original MIPS .pdata 0001bb40..0001bc57. Semantic name remains unreviewed. */

undefined4 FUN_0001bb40(int param_1)

{
  uint uVar1;
  SOCKET s;
  int iVar2;
  int local_20 [2];
  
  iVar2 = 0;
  if ((*(uint *)(param_1 + 0x9c) & 1) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_000197fc();
  }
  s = FUN_000198d8(*(int *)(param_1 + 0xc4),uVar1);
  *(SOCKET *)(param_1 + 0xa0) = s;
  if (s != 0xffffffff) {
    local_20[0] = 0x80;
    iVar2 = getpeername(s,(sockaddr *)(param_1 + 0x10),local_20);
    if (iVar2 != -1) {
      *(sockaddr **)(param_1 + 200) = (sockaddr *)(param_1 + 0x10);
      PostMessageW(*(HWND *)(param_1 + 0x94),0x602,0,0);
      return 1;
    }
    iVar2 = WSAGetLastError();
    closesocket(*(SOCKET *)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa0) = 0xffffffff;
  }
  InterlockedExchange((LONG *)(param_1 + 0x90),0x65);
  EventModify(*(undefined4 *)(param_1 + 0xc),3);
  FUN_0001b5e4(param_1,iVar2);
  return 0;
}



/* 0001bc58 FUN_0001bc58 */

/* Boundary evidence: original MIPS .pdata 0001bc58..0001bffb. Semantic name remains unreviewed. */

int FUN_0001bc58(int param_1)

{
  int iVar1;
  LSTATUS LVar2;
  uint uVar3;
  UINT Msg;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  ushort local_98 [2];
  DWORD local_94;
  DWORD local_90;
  HKEY local_8c;
  HKEY local_88;
  DWORD local_84;
  byte local_80 [84];
  uint local_2c;
  
  local_2c = DAT_0001d244;
  iVar5 = 0;
  local_90 = 0;
  FUN_00019fcc(0x7e0);
  iVar1 = GetPasswordActive();
  if ((iVar1 == 0) || ((*(uint *)(param_1 + 0x9c) & 1) != 0)) {
    send(*(SOCKET *)(param_1 + 0xa0),(char *)&local_90,4,0);
    FUN_0001b568(param_1);
    FUN_0001b640(param_1);
LAB_0001bf84:
    iVar5 = 1;
  }
  else {
    iVar1 = FUN_00013324((HKEY)0x80000002,L"Ident",&local_8c);
    if (iVar1 == 0) {
      local_98[0] = 0;
      iVar1 = FUN_000133a8(local_8c,L"PegId",(LPBYTE)&local_90);
      if (iVar1 != 0) {
        local_90 = GetTickCount();
        iVar1 = FUN_0001336c(local_8c,L"PegId",local_90);
        if (iVar1 != 0) {
          RegCloseKey(local_8c);
          goto LAB_0001bf88;
        }
      }
      RegCloseKey(local_8c);
      iVar1 = send(*(SOCKET *)(param_1 + 0xa0),(char *)&local_90,4,0);
      if (iVar1 != -1) {
        FUN_0001b640(param_1);
        iVar1 = FUN_00014354(*(SOCKET *)(param_1 + 0xa0),(int)local_98,2);
        while( true ) {
          if ((iVar1 != 2) || (uVar6 = (uint)local_98[0], 0x51 < uVar6)) goto LAB_0001bf88;
          memset(local_80,0,0x52);
          uVar6 = FUN_00014354(*(SOCKET *)(param_1 + 0xa0),(int)local_80,uVar6);
          uVar3 = (uint)local_98[0];
          if (uVar6 != uVar3) goto LAB_0001bf88;
          uVar6 = 0;
          if (uVar3 != 0) {
            do {
              pbVar4 = local_80 + uVar6;
              uVar6 = uVar6 + 1;
              *pbVar4 = *pbVar4 ^ (byte)local_90;
            } while (uVar6 < uVar3);
          }
          local_88 = (HKEY)0x0;
          local_84 = 0;
          local_94 = 0;
          LVar2 = RegCreateKeyExW((HKEY)0x80000002,L"ControlPanel\\Password",0,(LPWSTR)0x0,0,0,
                                  (LPSECURITY_ATTRIBUTES)0x0,&local_88,&local_84);
          if (LVar2 != 0) break;
          FUN_000133a8(local_88,L"TimeOut",(LPBYTE)&local_94);
          Sleep(local_94);
          local_98[0] = CheckPassword(local_80);
          if (local_98[0] == 0) {
            local_94 = (local_94 + 1) * 2;
          }
          else {
            local_94 = 0;
          }
          if (local_88 != (HKEY)0x0) {
            FUN_0001336c(local_88,L"TimeOut",local_94);
            RegCloseKey(local_88);
          }
          if (local_98[0] != 0) {
            FUN_0001b568(param_1);
          }
          iVar1 = send(*(SOCKET *)(param_1 + 0xa0),(char *)local_98,2,0);
          if (iVar1 == -1) goto LAB_0001bf88;
          if (local_98[0] != 0) goto LAB_0001bf84;
          iVar1 = FUN_00014354(*(SOCKET *)(param_1 + 0xa0),(int)local_98,2);
        }
        iVar5 = 0;
      }
    }
  }
LAB_0001bf88:
  InterlockedExchange((LONG *)(param_1 + 0x90),100);
  EventModify(*(undefined4 *)(param_1 + 0xc),3);
  Msg = 0x604;
  if (iVar5 == 0) {
    Msg = 0x603;
  }
  PostMessageW(*(HWND *)(param_1 + 0x94),Msg,0,0);
  FUN_0001c2c0(local_2c);
  return iVar5;
}



/* 0001bffc FUN_0001bffc */

/* WARNING: Removing unreachable block (ram,0x0001c124) */
/* Boundary evidence: original MIPS .pdata 0001bffc..0001c173. Semantic name remains unreviewed. */

undefined4 FUN_0001bffc(int param_1)

{
  DWORD DVar1;
  LONG LVar2;
  HANDLE local_30;
  undefined4 local_2c;
  
  local_30 = *(HANDLE *)(param_1 + 8);
  local_2c = *(undefined4 *)(param_1 + 0xc);
  do {
    DVar1 = WaitForMultipleObjects(2,&local_30,0,30000);
    if (DVar1 == 0) {
LAB_0001c0f8:
      if (DVar1 != 1) break;
    }
    else {
      if (DVar1 != 1) {
        if (DVar1 != 0x102) {
          *(undefined4 *)(param_1 + 0x90) = 0x65;
          goto LAB_0001c0f8;
        }
        SystemIdleTimerReset();
        break;
      }
      if (*(uint *)(param_1 + 0x90) < 100) {
        LVar2 = InterlockedExchange((LONG *)(param_1 + 0x90),0);
        if (LVar2 == 1) {
          FUN_0001b93c(param_1);
          goto LAB_0001c0f8;
        }
        if (LVar2 == 2) {
          FUN_0001bb40(param_1);
        }
        else if (LVar2 == 3) {
          FUN_0001bc58(param_1);
        }
      }
    }
  } while (*(uint *)(param_1 + 0x90) < 100);
  if (*(int *)(param_1 + 0x90) != 100) {
    *(undefined4 *)(param_1 + 0x90) = 0x65;
  }
  return 1;
}



/* 0001c174 FUN_0001c174 */

/* Boundary evidence: original MIPS .pdata 0001c174..0001c18f. Semantic name remains unreviewed. */

void FUN_0001c174(int param_1)

{
  FUN_0001bffc(param_1);
  return;
}



/* 0001c190 FUN_0001c190 */

/* Boundary evidence: original MIPS .pdata 0001c190..0001c23f. Semantic name remains unreviewed. */

undefined4 FUN_0001c190(undefined4 *param_1)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[2] = pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    param_1[3] = pvVar1;
    if (pvVar1 != (HANDLE)0x0) {
      pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001c174,param_1,0,param_1 + 1);
      *param_1 = pvVar1;
      uVar2 = 1;
      if (pvVar1 == (HANDLE)0x0) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



/* 0001c240 FUN_0001c240 */

/* Boundary evidence: original MIPS .pdata 0001c240..0001c293. Semantic name remains unreviewed. */

void FUN_0001c240(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_0001c2c0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 0001c294 FUN_0001c294 */

/* Boundary evidence: original MIPS .pdata 0001c294..0001c2bf. Semantic name remains unreviewed. */

undefined4 FUN_0001c294(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0001c240(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 0001c2c0 FUN_0001c2c0 */

/* Boundary evidence: original MIPS .pdata 0001c2c0..0001c307. Semantic name remains unreviewed. */

void FUN_0001c2c0(uint param_1)

{
  if ((param_1 == DAT_0001d244) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


