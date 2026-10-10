/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0411bac FUN_c0411bac */

/* Boundary evidence: original MIPS .pdata c0411bac..c0411c93. Semantic name remains unreviewed. */

LPBYTE FUN_c0411bac(int param_1)

{
  HKEY hKey;
  LSTATUS LVar1;
  LPBYTE lpData;
  uint local_20;
  DWORD DStack_1c;
  
  hKey = (HKEY)RegOpenProcessKey(*(undefined4 *)(param_1 + 0x10));
  if ((hKey != (HKEY)0x0) &&
     (LVar1 = RegQueryValueExW(hKey,L"dll",(LPDWORD)0x0,&DStack_1c,(LPBYTE)0x0,&local_20),
     -1 < LVar1)) {
    lpData = operator_new(local_20);
    if ((lpData != (LPBYTE)0x0) &&
       (LVar1 = RegQueryValueExW(hKey,L"dll",(LPDWORD)0x0,&DStack_1c,lpData,&local_20), LVar1 < 0))
    {
      operator_delete(lpData);
      lpData = (LPBYTE)0x0;
    }
    RegCloseKey(hKey);
    return lpData;
  }
  return (LPBYTE)0x0;
}



/* c0411c94 FUN_c0411c94 */

/* Boundary evidence: original MIPS .pdata c0411c94..c0411d2b. Semantic name remains unreviewed. */

void FUN_c0411c94(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)param_1[4];
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    puVar1 = (undefined4 *)puVar1[3];
    (*(code *)*puVar2)();
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
  }
  if ((void *)param_1[2] != (void *)0x0) {
    operator_delete((void *)param_1[2]);
  }
  if ((HANDLE)*param_1 != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)*param_1);
  }
  return;
}



/* c0411d2c FUN_c0411d2c */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0411d2c..c0411d9b. Semantic name remains unreviewed. */

undefined4 FUN_c0411d2c(undefined4 *param_1,DWORD param_2,undefined4 param_3)

{
  BOOL BVar1;
  undefined4 local_28;
  DWORD aDStack_24 [3];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  aDStack_24[1] = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  aDStack_24[2] = param_3;
  BVar1 = DeviceIoControl((HANDLE)*param_1,param_2,aDStack_24 + 1,0x14,&local_28,4,aDStack_24,
                          (LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    local_28 = 0;
  }
  return local_28;
}



/* c0411d9c FUN_c0411d9c */

/* Boundary evidence: original MIPS .pdata c0411d9c..c0411e83. Semantic name remains unreviewed. */

undefined4 FUN_c0411d9c(undefined4 *param_1,int param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  LPBYTE pBVar2;
  HANDLE pvVar3;
  uint uVar4;
  
  sVar1 = wcslen((wchar_t *)(param_2 + 0x1c));
  uVar4 = (sVar1 + 1) * 2;
  if (0x7fffffff < sVar1 + 1) {
    uVar4 = 0xffffffff;
  }
  _Dest = operator_new(uVar4);
  param_1[1] = _Dest;
  if (_Dest != (wchar_t *)0x0) {
    wcscpy(_Dest,(wchar_t *)(param_2 + 0x1c));
    param_1[3] = DAT_c04185fc;
    DAT_c04185fc = DAT_c04185fc + 1;
    pBVar2 = FUN_c0411bac(param_2);
    param_1[2] = pBVar2;
    pvVar3 = CreateFileW((LPCWSTR)param_1[1],0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0
                        );
    *param_1 = pvVar3;
    if (pvVar3 != (HANDLE)0xffffffff) {
      return 1;
    }
  }
  return 0;
}



/* c0411e9c FUN_c0411e9c */

/* Boundary evidence: original MIPS .pdata c0411e9c..c0411ed3. Semantic name remains unreviewed. */

void FUN_c0411e9c(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + param_1 + 4) + 8))();
  return;
}



/* c0411ed4 FUN_c0411ed4 */

/* Boundary evidence: original MIPS .pdata c0411ed4..c0411f67. Semantic name remains unreviewed. */

undefined4 FUN_c0411ed4(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x18);
  *piVar2 = 0;
  iVar1 = FUN_c0414a54(piVar2);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)(*(int *)*piVar2 + 8))
                        ((int *)*piVar2,*(int *)(*(int *)(param_1 + 4) + 8) + param_1 + 4),
     iVar1 < 0)) {
    (**(code **)(*(int *)(*(int *)(*(int *)(*piVar2 + 4) + 4) + *piVar2 + 4) + 8))();
    *piVar2 = 0;
  }
  return 1;
}



/* c0411f68 FUN_c0411f68 */

/* Boundary evidence: original MIPS .pdata c0411f68..c041201b. Semantic name remains unreviewed. */

uint FUN_c0411f68(void *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = wcsncmp((wchar_t *)((int)param_1 + 0x1c),L"WAV",3);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,&DAT_c0411170,0x10), iVar1 == 0)) {
    uVar2 = 3;
  }
  iVar1 = wcsncmp((wchar_t *)((int)param_1 + 0x1c),L"MIX",3);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,&DAT_c0411180,0x10), iVar1 == 0)) {
    uVar2 = uVar2 | 4;
  }
  return uVar2;
}



/* c041201c FUN_c041201c */

/* Boundary evidence: original MIPS .pdata c041201c..c04120b3. Semantic name remains unreviewed. */

int FUN_c041201c(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  uVar2 = DAT_c0418618;
  piVar1 = DAT_c04185d0;
  uVar4 = 0;
  if (DAT_c0418618 != 0) {
    piVar5 = DAT_c04185d0;
    do {
      iVar3 = wcscmp((wchar_t *)(param_1 + 0x1c),*(wchar_t **)(*piVar5 + 4));
      if (iVar3 == 0) {
        return piVar1[uVar4];
      }
      uVar4 = uVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (uVar4 < uVar2);
  }
  return 0;
}



/* c04120b4 FUN_c04120b4 */

/* Boundary evidence: original MIPS .pdata c04120b4..c04121af. Semantic name remains unreviewed. */

void FUN_c04120b4(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  
  uVar4 = DAT_c0418618;
  piVar5 = DAT_c04185d0;
  uVar2 = 0;
  if (DAT_c0418618 != 0) {
    piVar6 = DAT_c04185d0;
    do {
      iVar1 = wcscmp((wchar_t *)(param_1 + 0x1c),*(wchar_t **)(*piVar6 + 4));
      if (iVar1 == 0) {
        puVar3 = (undefined4 *)piVar5[uVar2];
        if (puVar3 != (undefined4 *)0x0) {
          FUN_c0411c94(puVar3);
          operator_delete(puVar3);
          uVar4 = DAT_c0418618;
          piVar5 = DAT_c04185d0;
        }
        DAT_c0418618 = uVar4 - 1;
        piVar5[uVar2] = piVar5[DAT_c0418618];
        DAT_c04185d0[DAT_c0418618 + 1] = 0;
        return;
      }
      uVar2 = uVar2 + 1;
      piVar6 = piVar6 + 1;
    } while (uVar2 < uVar4);
  }
  return;
}



/* c04121b0 DllMain */

/* Boundary evidence: original MIPS .pdata c04121b0..c041229f. Semantic name remains unreviewed. */

undefined4 DllMain(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
                    /* 0x21b0  1  DllMain */
  uVar1 = 1;
  if (param_2 == 0) {
    if (DAT_c04185f4 != (HANDLE)0x0) {
      EventModify(DAT_c04185f4,3);
      CloseHandle(DAT_c04185f4);
    }
  }
  else if (param_2 == 1) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
    DAT_c04185fc = 0;
    DAT_c0418600 = 1;
    DAT_c0418618 = 0;
    DAT_c04185d0 = LocalAlloc(0,4);
    if ((DAT_c04185d0 != (HLOCAL)0x0) &&
       (DAT_c04185f4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0),
       DAT_c04185f4 != (HANDLE)0x0)) {
      DAT_c04185f8 = 0;
      DisableThreadLibraryCalls(param_1);
      return 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* c04122a0 FUN_c04122a0 */

/* Boundary evidence: original MIPS .pdata c04122a0..c04122f3. Semantic name remains unreviewed. */

undefined4 FUN_c04122a0(undefined4 *param_1,undefined4 param_2)

{
  HLOCAL pvVar1;
  undefined4 uVar2;
  
  param_1[3] = param_2;
  param_1[1] = 0;
  param_1[2] = 1;
  pvVar1 = LocalAlloc(0,4);
  *param_1 = pvVar1;
  if (pvVar1 == (HLOCAL)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c04122f4 FUN_c04122f4 */

/* Boundary evidence: original MIPS .pdata c04122f4..c04123af. Semantic name remains unreviewed. */

void FUN_c04122f4(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  undefined *puVar1;
  wchar_t awStack_28 [8];
  uint local_18;
  
  local_18 = DAT_c04185b8;
  if ((param_2 & 2) == 0) {
    puVar1 = &UNK_c04111a0;
  }
  else {
    puVar1 = &DAT_c0411190;
  }
  _itow(param_3,awStack_28,10);
  if ((param_4 == 2) || (param_4 == 4)) {
    AdvertiseInterface(puVar1,awStack_28,0);
  }
  if ((param_4 == 1) || (param_4 == 4)) {
    AdvertiseInterface(puVar1,awStack_28,1);
  }
  FUN_c041747c(local_18);
  return;
}



/* c04123b0 FUN_c04123b0 */

/* Boundary evidence: original MIPS .pdata c04123b0..c04124b3. Semantic name remains unreviewed. */

void FUN_c04123b0(int *param_1,int *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = param_1[1];
  uVar3 = 0;
  if (uVar1 != 0) {
    puVar2 = (undefined4 *)*param_1;
    do {
      if (param_2 == (int *)*puVar2) break;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 < (uint)param_1[1]);
  }
  if (uVar3 != uVar1) {
    param_1[1] = uVar1 - 1;
    if (uVar3 < uVar1 - 1) {
      iVar4 = uVar3 << 2;
      do {
        *(undefined4 *)(iVar4 + *param_1) = ((undefined4 *)(iVar4 + *param_1))[1];
        *(uint *)(*(int *)(iVar4 + *param_1) + 8) = uVar3;
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 4;
      } while (uVar3 < (uint)param_1[1]);
    }
    uVar1 = (**(code **)(*param_2 + 0xc))(param_2);
    if ((code *)param_1[3] != (code *)0x0) {
      (*(code *)param_1[3])((int)param_2 + *(int *)(param_2[1] + 8) + 4,uVar1,2);
    }
    FUN_c04122f4(param_1,uVar1,param_2[2],2);
  }
  return;
}



/* c04124b4 FUN_c04124b4 */

/* Boundary evidence: original MIPS .pdata c04124b4..c04125b3. Semantic name remains unreviewed. */

undefined4 FUN_c04124b4(int *param_1,int *param_2)

{
  HLOCAL pvVar1;
  uint uVar2;
  
  uVar2 = param_1[2];
  if (uVar2 <= (uint)param_1[1]) {
    if ((0x400 < uVar2 << 1) ||
       (pvVar1 = LocalReAlloc((HLOCAL)*param_1,uVar2 << 3,2), pvVar1 == (HLOCAL)0x0)) {
      return 0;
    }
    param_1[2] = uVar2 << 1;
    *param_1 = (int)pvVar1;
  }
  *(int **)(param_1[1] * 4 + *param_1) = param_2;
  param_2[2] = param_1[1];
  param_1[1] = param_1[1] + 1;
  uVar2 = (**(code **)(*param_2 + 0xc))(param_2);
  if ((code *)param_1[3] != (code *)0x0) {
    (*(code *)param_1[3])((int)param_2 + *(int *)(param_2[1] + 8) + 4,uVar2,1);
  }
  FUN_c04122f4(param_1,uVar2,param_2[2],1);
  return 1;
}



/* c04125b4 FUN_c04125b4 */

/* Boundary evidence: original MIPS .pdata c04125b4..c041274f. Semantic name remains unreviewed. */

undefined4 FUN_c04125b4(int *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  
  uVar6 = 0;
  if (param_3 == 0xffffffff) {
    param_3 = param_1[1] - 1;
  }
  if ((param_2 < (uint)param_1[1]) && (param_3 < (uint)param_1[1])) {
    if (param_2 != param_3) {
      iVar2 = *param_1;
      piVar5 = *(int **)(param_2 * 4 + iVar2);
      if (param_3 < param_2) {
        iVar7 = param_2 - param_3;
        param_2 = param_3 + 1;
        uVar8 = param_3;
        uVar4 = param_3;
      }
      else {
        uVar8 = param_2 + 1;
        iVar7 = param_3 - param_2;
        uVar4 = param_2;
      }
      memmove((void *)(param_2 * 4 + iVar2),(void *)(uVar8 * 4 + iVar2),iVar7 << 2);
      uVar8 = uVar4 + iVar7;
      *(int **)(param_3 * 4 + *param_1) = piVar5;
      bVar1 = uVar4 <= uVar8;
      if (bVar1) {
        iVar2 = uVar4 << 2;
        uVar3 = uVar4;
        do {
          *(uint *)(*(int *)(iVar2 + *param_1) + 8) = uVar3;
          uVar3 = uVar3 + 1;
          iVar2 = iVar2 + 4;
        } while (uVar3 <= uVar8);
      }
      uVar3 = (**(code **)(*piVar5 + 0xc))(piVar5);
      if ((code *)param_1[3] != (code *)0x0) {
        (*(code *)param_1[3])((int)piVar5 + *(int *)(piVar5[1] + 8) + 4,uVar3,4);
      }
      while (bVar1) {
        FUN_c04122f4(param_1,uVar3,uVar4,4);
        uVar4 = uVar4 + 1;
        bVar1 = uVar4 <= uVar8;
      }
    }
  }
  else {
    uVar6 = 2;
  }
  return uVar6;
}



/* c0412750 FUN_c0412750 */

/* Boundary evidence: original MIPS .pdata c0412750..c04127db. Semantic name remains unreviewed. */

undefined4 FUN_c0412750(int *param_1,uint param_2,int *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  if (param_2 < (uint)param_1[1]) {
    piVar2 = (int *)(param_2 * 4 + *param_1);
    if (*piVar2 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *piVar2;
      iVar3 = *(int *)(*(int *)(iVar3 + 4) + 8) + iVar3 + 4;
    }
    *param_3 = iVar3;
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + iVar3 + 4) + 4))();
    uVar1 = 0;
  }
  else {
    uVar1 = 0x88800001;
  }
  return uVar1;
}



/* c04127e8 FUN_c04127e8 */

/* Boundary evidence: original MIPS .pdata c04127e8..c0412803. Semantic name remains unreviewed. */

void FUN_c04127e8(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + -0x1c));
  return;
}



/* c0412804 FUN_c0412804 */

/* Boundary evidence: original MIPS .pdata c0412804..c041285f. Semantic name remains unreviewed. */

LONG FUN_c0412804(int param_1)

{
  LONG LVar1;
  int *piVar2;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + -0x1c));
  if ((LVar1 == 0) && (piVar2 = (int *)(param_1 + -0x2c), piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 4))(piVar2,1);
  }
  return LVar1;
}



/* c0412860 FUN_c0412860 */

/* Boundary evidence: original MIPS .pdata c0412860..c04128ff. Semantic name remains unreviewed. */

undefined4 FUN_c0412860(int param_1,int param_2,undefined4 *param_3)

{
  if (param_2 == 1) {
    *param_3 = *(undefined4 *)(param_1 + -0x1c);
    if (*(int *)(param_1 + -0x1c) != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x1c) + 4) + 4) +
                            *(int *)(param_1 + -0x1c) + 4) + 4))();
      return 0;
    }
  }
  else {
    if (param_2 == 2) {
      *param_3 = *(undefined4 *)(param_1 + -0x20);
      return 0;
    }
    if (param_2 == 3) {
      *param_3 = *(undefined4 *)(param_1 + -0x2c);
      return 0;
    }
  }
  return 0x80004005;
}



/* c0412900 FUN_c0412900 */

/* Boundary evidence: original MIPS .pdata c0412900..c0412b17. Semantic name remains unreviewed. */

int FUN_c0412900(int param_1,int param_2,undefined4 param_3,int param_4,uint param_5)

{
  bool bVar1;
  BOOL BVar2;
  int iVar3;
  int local_40;
  DWORD DStack_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  uint local_28;
  
  bVar1 = false;
  if (*(undefined4 **)(param_1 + -0x18) == (undefined4 *)0x0) {
    return 6;
  }
  if (*(int *)(param_1 + -0x1c) != 0) {
    if (param_2 == 5) {
      if ((((param_5 & 1) == 0) && ((param_5 & 0x80000000) == 0)) && ((param_5 & 0x40000000) != 0))
      {
        if (*(int *)(param_1 + -0x14) < 2) {
          return 4;
        }
        bVar1 = true;
      }
      param_5 = param_5 & 0x3fffffff;
    }
    else if (param_2 == 6) {
      if (((param_5 & 0x80000000) == 0) && ((param_5 & 0x40000000) != 0)) {
        bVar1 = true;
      }
      param_5 = param_5 & 0x3fffffff;
    }
  }
  local_38 = *(undefined4 *)(param_1 + -0x20);
  local_40 = 1;
  local_34 = param_2;
  local_30 = param_3;
  local_2c = param_4;
  local_28 = param_5;
  BVar2 = DeviceIoControl((HANDLE)**(undefined4 **)(param_1 + -0x18),0x1d000c,&local_38,0x14,
                          &local_40,4,&DStack_3c,(LPOVERLAPPED)0x0);
  if (BVar2 == 0) {
    local_40 = 6;
  }
  if ((bVar1) && (local_40 == 0)) {
    if (param_2 == 5) {
      iVar3 = *(int *)(param_1 + -0x14) + -1;
    }
    else {
      if (param_2 != 6) goto LAB_c0412aa4;
      iVar3 = *(int *)(param_1 + -0x14) + 1;
    }
    *(int *)(param_1 + -0x14) = iVar3;
  }
LAB_c0412aa4:
  if (((*(int *)(param_1 + -0x1c) != 0) && (local_40 == 0)) && (param_2 == 4)) {
    *(uint *)(param_4 + 0x50) = *(uint *)(param_4 + 0x50) | 0xe;
    *(uint *)(param_4 + 0x48) = *(uint *)(param_4 + 0x48) | 0xfff;
  }
  return local_40;
}



/* c0412b18 FUN_c0412b18 */

/* Boundary evidence: original MIPS .pdata c0412b18..c0412bab. Semantic name remains unreviewed. */

undefined4
FUN_c0412b18(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  BOOL BVar1;
  undefined4 local_28;
  DWORD DStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(undefined4 **)(param_1 + -0x18) != (undefined4 *)0x0) {
    local_20 = *(undefined4 *)(param_1 + -0x20);
    local_10 = param_5;
    local_28 = 1;
    local_1c = param_2;
    local_18 = param_3;
    local_14 = param_4;
    BVar1 = DeviceIoControl((HANDLE)**(undefined4 **)(param_1 + -0x18),0x80000100,&local_20,0x14,
                            &local_28,4,&DStack_24,(LPOVERLAPPED)0x0);
    if (BVar1 != 0) {
      return local_28;
    }
  }
  return 6;
}



/* c0412bac FUN_c0412bac */

/* Boundary evidence: original MIPS .pdata c0412bac..c0412cf7. Semantic name remains unreviewed. */

int FUN_c0412bac(int param_1,DWORD param_2,int *param_3,DWORD param_4)

{
  BOOL BVar1;
  int iVar2;
  int local_28;
  DWORD DStack_24;
  
  if (*(undefined4 **)(param_1 + -0x18) == (undefined4 *)0x0) {
    local_28 = -0x777ffffe;
  }
  else if ((param_2 == 0x1d0014) &&
          (((*param_3 == 100 || (*param_3 == 0x66)) && (*(int *)(param_1 + -0x14) < 2)))) {
    local_28 = -0x7787fff6;
  }
  else {
    local_28 = -0x7fffbffb;
    BVar1 = DeviceIoControl((HANDLE)**(undefined4 **)(param_1 + -0x18),param_2,param_3,param_4,
                            &local_28,4,&DStack_24,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      local_28 = -0x777ffffe;
    }
    if ((param_2 == 0x1d0014) && (-1 < local_28)) {
      iVar2 = *param_3;
      if (iVar2 != 100) {
        if (iVar2 == 0x65) {
          *(int *)(param_1 + -0x14) = *(int *)(param_1 + -0x14) + 1;
          return local_28;
        }
        if (iVar2 != 0x66) {
          return local_28;
        }
      }
      *(int *)(param_1 + -0x14) = *(int *)(param_1 + -0x14) + -1;
    }
  }
  return local_28;
}



/* c0412cf8 audmGetNumMixerDevices */

/* Boundary evidence: original MIPS .pdata c0412cf8..c0412d43. Semantic name remains unreviewed. */

undefined4 audmGetNumMixerDevices(void)

{
  undefined4 uVar1;
  
                    /* 0x2cf8  5  audmGetNumMixerDevices */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  uVar1 = DAT_c04185d8;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  return uVar1;
}



/* c0412d44 audmGetNumInputDevices */

/* Boundary evidence: original MIPS .pdata c0412d44..c0412d8f. Semantic name remains unreviewed. */

undefined4 audmGetNumInputDevices(void)

{
  undefined4 uVar1;
  
                    /* 0x2d44  4  audmGetNumInputDevices */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  uVar1 = DAT_c04185c4;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  return uVar1;
}



/* c0412d90 audmGetNumOutputDevices */

/* Boundary evidence: original MIPS .pdata c0412d90..c0412ddb. Semantic name remains unreviewed. */

undefined4 audmGetNumOutputDevices(void)

{
  undefined4 uVar1;
  
                    /* 0x2d90  6  audmGetNumOutputDevices */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  uVar1 = DAT_c04185e8;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  return uVar1;
}



/* c0412ddc audmGetMixerDevice */

/* Boundary evidence: original MIPS .pdata c0412ddc..c0412e43. Semantic name remains unreviewed. */

undefined4 audmGetMixerDevice(uint param_1,int *param_2)

{
  undefined4 uVar1;
  
                    /* 0x2ddc  3  audmGetMixerDevice */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  uVar1 = FUN_c0412750((int *)&DAT_c04185d4,param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  return uVar1;
}



/* c0412e44 audmGetInputDevice */

/* Boundary evidence: original MIPS .pdata c0412e44..c0412eab. Semantic name remains unreviewed. */

undefined4 audmGetInputDevice(uint param_1,int *param_2)

{
  undefined4 uVar1;
  
                    /* 0x2e44  2  audmGetInputDevice */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  uVar1 = FUN_c0412750((int *)&DAT_c04185c0,param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  return uVar1;
}



/* c0412eac audmGetOutputDevice */

/* Boundary evidence: original MIPS .pdata c0412eac..c0412f13. Semantic name remains unreviewed. */

undefined4 audmGetOutputDevice(uint param_1,int *param_2)

{
  undefined4 uVar1;
  
                    /* 0x2eac  7  audmGetOutputDevice */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  uVar1 = FUN_c0412750((int *)&DAT_c04185e4,param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  return uVar1;
}



/* c0412f14 audmSetOutputDeviceId */

/* Boundary evidence: original MIPS .pdata c0412f14..c0412f7b. Semantic name remains unreviewed. */

undefined4 audmSetOutputDeviceId(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
                    /* 0x2f14  10  audmSetOutputDeviceId */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  uVar1 = FUN_c04125b4((int *)&DAT_c04185e4,param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  return uVar1;
}



/* c0412f7c audmSetInputDeviceId */

/* Boundary evidence: original MIPS .pdata c0412f7c..c0412fe3. Semantic name remains unreviewed. */

undefined4 audmSetInputDeviceId(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
                    /* 0x2f7c  9  audmSetInputDeviceId */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  uVar1 = FUN_c04125b4((int *)&DAT_c04185c0,param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  return uVar1;
}



/* c041308c FUN_c041308c */

/* Boundary evidence: original MIPS .pdata c041308c..c04130fb. Semantic name remains unreviewed. */

undefined4 FUN_c041308c(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  param_2[3] = *(int *)(param_1 + 0x10);
  *(int **)(param_1 + 0x10) = param_2;
  iVar1 = (**(code **)(*param_2 + 8))(param_2);
  if ((iVar1 == 0) || (iVar1 = FUN_c04124b4(param_3,param_2), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c04130fc FUN_c04130fc */

undefined4 * FUN_c04130fc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_4 != 0) {
    param_1[1] = &DAT_c04110a4;
    param_1[0xe] = &DAT_c041109c;
    param_1[0xd] = &PTR_LAB_c0411050;
    *(undefined ***)((int)(param_1 + 0xd) + *(int *)(param_1[0xe] + 4) + 4) = &PTR_LAB_c0411044;
  }
  *param_1 = &PTR_FUN_c041107c;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411070;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c0411060;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x28;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x30;
  param_1[4] = 1;
  param_1[5] = param_3;
  param_1[9] = 1;
  param_1[8] = 1;
  param_1[7] = param_2;
  return param_1;
}



/* c04131c8 FUN_c04131c8 */

/* Boundary evidence: original MIPS .pdata c04131c8..c04132f3. Semantic name remains unreviewed. */

undefined4 * FUN_c04131c8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  
  if (param_4 != 0) {
    param_1[1] = &DAT_c04110e4;
    param_1[0xe] = &DAT_c04110dc;
    param_1[0xd] = &PTR_LAB_c0411050;
    *(undefined ***)((int)(param_1 + 0xd) + *(int *)(param_1[0xe] + 4) + 4) = &PTR_LAB_c0411044;
  }
  FUN_c04130fc(param_1,param_2,param_3,0);
  *param_1 = &PTR_FUN_c04110cc;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c04110c0;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c04110b0;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x28;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x30;
  local_28 = param_1[9];
  local_24 = param_1[8];
  iVar1 = FUN_c0412900((int)(param_1 + 0xd),0x16,0,(int)&local_28,0x1c);
  if (iVar1 == 0) {
    param_1[9] = local_28;
    param_1[8] = local_24;
  }
  return param_1;
}



/* c04132f4 FUN_c04132f4 */

/* Boundary evidence: original MIPS .pdata c04132f4..c04133cb. Semantic name remains unreviewed. */

undefined4 * FUN_c04132f4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_4 != 0) {
    param_1[1] = &DAT_c0411124;
    param_1[0xe] = &DAT_c041111c;
    param_1[0xd] = &PTR_LAB_c0411050;
    *(undefined ***)((int)(param_1 + 0xd) + *(int *)(param_1[0xe] + 4) + 4) = &PTR_LAB_c0411044;
  }
  FUN_c04130fc(param_1,param_2,param_3,0);
  *param_1 = &PTR_FUN_c041110c;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411100;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c04110f0;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x28;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x30;
  return param_1;
}



/* c04133cc FUN_c04133cc */

/* Boundary evidence: original MIPS .pdata c04133cc..c04134a3. Semantic name remains unreviewed. */

undefined4 * FUN_c04133cc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_4 != 0) {
    param_1[1] = &DAT_c0411164;
    param_1[0xe] = &DAT_c041115c;
    param_1[0xd] = &PTR_LAB_c0411050;
    *(undefined ***)((int)(param_1 + 0xd) + *(int *)(param_1[0xe] + 4) + 4) = &PTR_LAB_c0411044;
  }
  FUN_c04130fc(param_1,param_2,param_3,0);
  *param_1 = &PTR_FUN_c041114c;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411140;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c0411130;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x28;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x30;
  return param_1;
}



/* c04134a4 FUN_c04134a4 */

/* Boundary evidence: original MIPS .pdata c04134a4..c04135df. Semantic name remains unreviewed. */

void FUN_c04134a4(int *param_1)

{
  *param_1 = (int)&PTR_FUN_c04110cc;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c04110c0;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c04110b0;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x28;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x30;
  if ((int *)param_1[6] != (int *)0x0) {
    (**(code **)(*(int *)param_1[6] + 0xc))();
    (**(code **)(*(int *)(*(int *)(*(int *)(param_1[6] + 4) + 4) + param_1[6] + 4) + 8))();
    param_1[6] = 0;
  }
  FUN_c04123b0((int *)&DAT_c04185e4,param_1);
  *param_1 = (int)&PTR_FUN_c041107c;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411070;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c0411060;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x28;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x30;
  return;
}



/* c04135e0 FUN_c04135e0 */

/* Boundary evidence: original MIPS .pdata c04135e0..c04136d7. Semantic name remains unreviewed. */

void FUN_c04135e0(int *param_1)

{
  *param_1 = (int)&PTR_FUN_c041110c;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411100;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c04110f0;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x28;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x30;
  FUN_c04123b0((int *)&DAT_c04185c0,param_1);
  *param_1 = (int)&PTR_FUN_c041107c;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411070;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c0411060;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x28;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x30;
  return;
}



/* c04136d8 FUN_c04136d8 */

/* Boundary evidence: original MIPS .pdata c04136d8..c04137cf. Semantic name remains unreviewed. */

void FUN_c04136d8(int *param_1)

{
  *param_1 = (int)&PTR_FUN_c041114c;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411140;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c0411130;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x28;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x30;
  FUN_c04123b0((int *)&DAT_c04185d4,param_1);
  *param_1 = (int)&PTR_FUN_c041107c;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411070;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c0411060;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x28;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x30;
  return;
}



/* c04137d0 FUN_c04137d0 */

/* Boundary evidence: original MIPS .pdata c04137d0..c0413a03. Semantic name remains unreviewed. */

undefined4 FUN_c04137d0(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = ~param_1[5] & param_2;
  if (uVar5 != 0) {
    param_1[5] = param_1[5] | uVar5;
    if ((uVar5 & 1) != 0) {
      uVar1 = FUN_c0411d2c(param_1,0x1d000c,0x32);
      uVar6 = 0;
      if (uVar1 != 0) {
        do {
          puVar2 = operator_new(0x3c);
          if (puVar2 == (undefined4 *)0x0) {
            piVar3 = (int *)0x0;
          }
          else {
            piVar3 = FUN_c04132f4(puVar2,param_1,uVar6,1);
          }
          if (piVar3 == (int *)0x0) {
            return 0;
          }
          iVar4 = FUN_c041308c((int)param_1,piVar3,(int *)&DAT_c04185c0);
          if (iVar4 == 0) {
            return 0;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar1);
      }
    }
    if ((uVar5 & 2) != 0) {
      uVar1 = FUN_c0411d2c(param_1,0x1d000c,3);
      uVar6 = 0;
      if (uVar1 != 0) {
        do {
          puVar2 = operator_new(0x3c);
          if (puVar2 == (undefined4 *)0x0) {
            piVar3 = (int *)0x0;
          }
          else {
            piVar3 = FUN_c04131c8(puVar2,param_1,uVar6,1);
          }
          if (piVar3 == (int *)0x0) {
            return 0;
          }
          iVar4 = FUN_c041308c((int)param_1,piVar3,(int *)&DAT_c04185e4);
          if (iVar4 == 0) {
            return 0;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar1);
      }
    }
    if ((uVar5 & 4) != 0) {
      uVar5 = FUN_c0411d2c(param_1,0x80000100,1);
      uVar1 = 0;
      if (uVar5 != 0) {
        do {
          puVar2 = operator_new(0x3c);
          if (puVar2 == (undefined4 *)0x0) {
            piVar3 = (int *)0x0;
          }
          else {
            piVar3 = FUN_c04133cc(puVar2,param_1,uVar1,1);
          }
          if ((piVar3 == (int *)0x0) ||
             (iVar4 = FUN_c041308c((int)param_1,piVar3,(int *)&DAT_c04185d4), iVar4 == 0)) {
            return 0;
          }
          uVar1 = uVar1 + 1;
        } while (uVar1 < uVar5);
      }
    }
  }
  return 1;
}



/* c0413a04 FUN_c0413a04 */

/* Boundary evidence: original MIPS .pdata c0413a04..c0413a4f. Semantic name remains unreviewed. */

int * FUN_c0413a04(int *param_1,uint param_2)

{
  FUN_c04134a4(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0413a50 FUN_c0413a50 */

/* Boundary evidence: original MIPS .pdata c0413a50..c0413a9b. Semantic name remains unreviewed. */

int * FUN_c0413a50(int *param_1,uint param_2)

{
  FUN_c04135e0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0413a9c FUN_c0413a9c */

/* Boundary evidence: original MIPS .pdata c0413a9c..c0413ae7. Semantic name remains unreviewed. */

int * FUN_c0413a9c(int *param_1,uint param_2)

{
  FUN_c04136d8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0413ae8 FUN_c0413ae8 */

/* Boundary evidence: original MIPS .pdata c0413ae8..c0413c37. Semantic name remains unreviewed. */

void FUN_c0413ae8(void *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  HLOCAL pvVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = FUN_c0411f68(param_1);
  if (uVar1 == 0) {
    return;
  }
  puVar2 = (undefined4 *)FUN_c041201c((int)param_1);
  if (puVar2 == (undefined4 *)0x0) {
    pvVar3 = DAT_c04185d0;
    uVar5 = DAT_c0418600;
    if (DAT_c0418600 <= DAT_c0418618) {
      uVar5 = DAT_c0418600 << 1;
      if (0x200 < uVar5) {
        return;
      }
      pvVar3 = LocalReAlloc(DAT_c04185d0,DAT_c0418600 << 3,2);
      if (pvVar3 == (HLOCAL)0x0) {
        return;
      }
    }
    DAT_c0418600 = uVar5;
    DAT_c04185d0 = pvVar3;
    puVar2 = operator_new(0x18);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0xffffffff;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
    }
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    iVar4 = FUN_c0411d9c(puVar2,(int)param_1);
    if (iVar4 == 0) {
      FUN_c0411c94(puVar2);
      operator_delete(puVar2);
      return;
    }
    *(undefined4 **)(DAT_c0418618 * 4 + (int)DAT_c04185d0) = puVar2;
    DAT_c0418618 = DAT_c0418618 + 1;
  }
  FUN_c04137d0(puVar2,uVar1);
  return;
}



/* c0413c38 FUN_c0413c38 */

/* Boundary evidence: original MIPS .pdata c0413c38..c0413db7. Semantic name remains unreviewed. */

undefined4 FUN_c0413c38(void)

{
  HANDLE pvVar1;
  int iVar2;
  DWORD DVar3;
  undefined1 auStack_f8 [4];
  undefined1 auStack_f4 [4];
  HANDLE local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d0;
  undefined1 auStack_cc [12];
  undefined1 auStack_c0 [20];
  int local_ac;
  uint local_20;
  
  local_20 = DAT_c04185b8;
  local_d0 = 0;
  memset(auStack_cc,0,0xc);
  local_e8 = 0x14;
  local_e4 = 0;
  local_e0 = 0;
  local_dc = 0xa0;
  local_d8 = 1;
  pvVar1 = (HANDLE)CreateMsgQueue(0,&local_e8);
  if (pvVar1 != (HANDLE)0x0) {
    iVar2 = RequestDeviceNotifications(&local_d0,pvVar1,1);
    if (iVar2 != 0) {
      local_ec = DAT_c04185f4;
      local_f0 = pvVar1;
      do {
        do {
          do {
            DVar3 = WaitForMultipleObjects(2,&local_f0,0,0xffffffff);
          } while (DVar3 != 0);
          iVar2 = ReadMsgQueue(pvVar1,auStack_c0,0xa0,auStack_f4,1,auStack_f8);
        } while (iVar2 == 0);
        do {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
          if (local_ac == 0) {
            FUN_c04120b4((int)auStack_c0);
          }
          else {
            FUN_c0413ae8(auStack_c0);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
          iVar2 = ReadMsgQueue(pvVar1,auStack_c0,0xa0,auStack_f4,1,auStack_f8);
        } while (iVar2 != 0);
      } while( true );
    }
    CloseMsgQueue(pvVar1);
  }
  FUN_c041747c(local_20);
  return 0;
}



/* c0413db8 FUN_c0413db8 */

/* Boundary evidence: original MIPS .pdata c0413db8..c0413e83. Semantic name remains unreviewed. */

undefined4 FUN_c0413db8(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  HANDLE hObject;
  
  if (DAT_c04185f8 == 0) {
    iVar2 = FUN_c04122a0((undefined4 *)&DAT_c04185c0,param_1);
    if ((((-1 < iVar2) && (iVar2 = FUN_c04122a0((undefined4 *)&DAT_c04185e4,param_1), -1 < iVar2))
        && (iVar2 = FUN_c04122a0((undefined4 *)&DAT_c04185d4,param_1), -1 < iVar2)) &&
       (hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0413c38,(LPVOID)0x0,0,(LPDWORD)0x0)
       , hObject != (HANDLE)0x0)) {
      CloseHandle(hObject);
      DAT_c04185f8 = 1;
      return 1;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c0413e84 audmInitialize */

/* Boundary evidence: original MIPS .pdata c0413e84..c0413eeb. Semantic name remains unreviewed. */

undefined4 audmInitialize(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x3e84  8  audmInitialize */
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  iVar1 = FUN_c0413db8(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x80004005;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0418604);
  return uVar2;
}



/* c0413eec FUN_c0413eec */

/* Boundary evidence: original MIPS .pdata c0413eec..c0413f7b. Semantic name remains unreviewed. */

undefined4 FUN_c0413eec(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_c04111b0,0x10);
  if (iVar1 == 0) {
    InterlockedIncrement((LONG *)(param_1 + -0x74));
    if (param_1 == 0x94) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(*(int *)(param_1 + -0x90) + 8) + param_1 + -0x90;
    }
    *param_3 = iVar1;
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* c0413f7c FUN_c0413f7c */

/* Boundary evidence: original MIPS .pdata c0413f7c..c0413f97. Semantic name remains unreviewed. */

void FUN_c0413f7c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + -0x74));
  return;
}



/* c0413f98 FUN_c0413f98 */

/* Boundary evidence: original MIPS .pdata c0413f98..c0413fc3. Semantic name remains unreviewed. */

undefined4 FUN_c0413f98(int param_1)

{
  *(undefined4 *)(param_1 + -0x5c) = 1;
  EventModify(*(undefined4 *)(param_1 + -0x94),3);
  return 0;
}



/* c04140e8 FUN_c04140e8 */

/* Boundary evidence: original MIPS .pdata c04140e8..c04141d3. Semantic name remains unreviewed. */

void FUN_c04140e8(int *param_1,void *param_2,uint param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = true;
  if ((0 < param_1[3]) && (iVar3 = 0, 0 < param_1[3])) {
    iVar4 = 0;
    do {
      if (*(int *)(*(int *)(iVar4 + *param_1) + 0x10) == 0) {
        bVar1 = false;
        piVar2 = *(int **)(iVar4 + *param_1);
        (**(code **)(*piVar2 + 0x38))(piVar2,param_3 >> 2,param_2,0 < iVar3);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar3 < param_1[3]);
    if (!bVar1) {
      return;
    }
  }
  memset(param_2,0,param_3);
  return;
}



/* c04141d4 FUN_c04141d4 */

/* Boundary evidence: original MIPS .pdata c04141d4..c041427f. Semantic name remains unreviewed. */

void FUN_c04141d4(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1[3]) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(iVar2 + *param_1);
      if ((piVar1[3] == 0) && (piVar1[4] == 0)) {
        piVar1[3] = 1;
        (**(code **)(*piVar1 + 0x3c))(piVar1,param_2,param_3);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < param_1[3]);
  }
  return;
}



/* c0414280 FUN_c0414280 */

/* Boundary evidence: original MIPS .pdata c0414280..c04142fb. Semantic name remains unreviewed. */

void FUN_c0414280(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[3]) {
    iVar1 = 0;
    do {
      (**(code **)(**(int **)(iVar1 + *param_1) + 0x40))(*(int **)(iVar1 + *param_1),param_2);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < param_1[3]);
  }
  return;
}



/* c04142fc FUN_c04142fc */

/* Boundary evidence: original MIPS .pdata c04142fc..c041433f. Semantic name remains unreviewed. */

void FUN_c04142fc(int param_1,undefined4 param_2,undefined4 *param_3)

{
  (**(code **)(**(int **)(param_1 + 0x24) + 0x10))();
  *param_3 = *(undefined4 *)(param_1 + 0x48);
  return;
}



/* c0414340 FUN_c0414340 */

/* Boundary evidence: original MIPS .pdata c0414340..c04143e3. Semantic name remains unreviewed. */

undefined4 FUN_c0414340(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x50));
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  if (*(int *)(param_2 + 0x18) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x18) + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  }
  if (*(int *)(param_2 + 0x1c) == 0) {
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 0x18);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0x1c) + 0x18) = *(undefined4 *)(param_2 + 0x18);
  }
  (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + param_2 + 4) + 8))();
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x50));
  return 0;
}



/* c04143e4 FUN_c04143e4 */

/* Boundary evidence: original MIPS .pdata c04143e4..c04144c3. Semantic name remains unreviewed. */

undefined4 FUN_c04143e4(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x6c) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    iVar2 = *(int *)(param_2 + 0x10);
    *(undefined4 *)(param_2 + 8) = 1;
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0xc) = 0;
    if (iVar2 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x50));
      iVar3 = *(int *)(param_1 + 0x44);
      *(undefined4 *)(param_1 + 0x44) = 1;
      (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + param_2 + 4) + 4))();
      iVar2 = *(int *)(param_1 + 100);
      *(int *)(param_2 + 0x18) = iVar2;
      *(undefined4 *)(param_2 + 0x1c) = 0;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 0x1c) = param_2;
      }
      *(int *)(param_1 + 100) = param_2;
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x50));
      if (iVar3 == 0) {
        EventModify(*(undefined4 *)(param_1 + 0xc),3);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* c04144d8 FUN_c04144d8 */

/* Boundary evidence: original MIPS .pdata c04144d8..c0414563. Semantic name remains unreviewed. */

void FUN_c04144d8(int param_1)

{
  LONG LVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x70));
  if (LVar1 == 0) {
    EventModify(*(undefined4 *)(param_1 + 0x10),3);
    iVar2 = __GetUserKData(8);
    if ((iVar2 != *(int *)(param_1 + 0x1c)) && (*(int *)(param_1 + 0x6c) != 0)) {
      WaitForSingleObject(*(HANDLE *)(param_1 + 0x18),10000);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  return;
}



/* c0414564 FUN_c0414564 */

/* Boundary evidence: original MIPS .pdata c0414564..c041460b. Semantic name remains unreviewed. */

undefined4 FUN_c0414564(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x24);
  iVar1 = (**(code **)(*piVar3 + 4))();
  iVar2 = (**(code **)*piVar3)(piVar3);
  if (*(uint *)(param_1 + 0x30) == 0) {
    trap(0x1c00);
  }
  *param_2 = (uint)(iVar1 * iVar2 * 1000) / *(uint *)(param_1 + 0x30);
  return 0;
}



/* c041460c FUN_c041460c */

/* Boundary evidence: original MIPS .pdata c041460c..c041466b. Semantic name remains unreviewed. */

undefined4 * FUN_c041460c(undefined4 *param_1,uint param_2)

{
  void *pvVar1;
  uint uVar2;
  
  param_1[1] = 1;
  *param_1 = 0;
  param_1[2] = param_2;
  param_1[3] = 0;
  if (param_2 < 0x40000000) {
    uVar2 = param_2 << 2;
  }
  else {
    uVar2 = 0xffffffff;
  }
  pvVar1 = operator_new(uVar2);
  *param_1 = pvVar1;
  return param_1;
}



/* c041466c FUN_c041466c */

/* Boundary evidence: original MIPS .pdata c041466c..c0414703. Semantic name remains unreviewed. */

void FUN_c041466c(int *param_1,int param_2)

{
  InterlockedIncrement(param_1 + 1);
  param_1[3] = 0;
  while ((param_2 != 0 && (param_1[3] < param_1[2]))) {
    (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + param_2 + 4) + 4))();
    *(int *)(param_1[3] * 4 + *param_1) = param_2;
    param_2 = *(int *)(param_2 + 0x18);
    param_1[3] = param_1[3] + 1;
  }
  return;
}



/* c0414704 FUN_c0414704 */

/* Boundary evidence: original MIPS .pdata c0414704..c041475f. Semantic name remains unreviewed. */

undefined4 * FUN_c0414704(undefined4 *param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  HKEY local_10 [2];
  
  *param_1 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,param_2,0,8,local_10);
  if (LVar1 == 0) {
    *param_1 = local_10[0];
  }
  return param_1;
}



/* c0414760 FUN_c0414760 */

/* Boundary evidence: original MIPS .pdata c0414760..c04147d3. Semantic name remains unreviewed. */

undefined4 FUN_c0414760(undefined4 *param_1,LPCWSTR param_2,LPBYTE param_3)

{
  LSTATUS LVar1;
  DWORD local_18;
  DWORD local_14;
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_18 = 4;
    LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,&local_14,param_3,&local_18);
    if ((LVar1 == 0) && (local_14 == 4)) {
      return 1;
    }
  }
  return 0;
}



/* c04147d4 FUN_c04147d4 */

/* Boundary evidence: original MIPS .pdata c04147d4..c04148fb. Semantic name remains unreviewed. */

undefined4 * FUN_c04147d4(undefined4 *param_1,int param_2)

{
  if (param_2 != 0) {
    param_1[1] = &DAT_c0411280;
    param_1[0x28] = &DAT_c0411278;
    param_1[0x27] = &PTR_LAB_c041121c;
    *(undefined ***)((int)(param_1 + 0x27) + *(int *)(param_1[0x28] + 4) + 4) = &PTR_LAB_c0411210;
  }
  *param_1 = &PTR_FUN_c0411260;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411254;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c0411238;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x90;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x98;
  param_1[8] = 1;
  param_1[0x12] = 0;
  param_1[0x13] = 0xdc;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  param_1[0x1c] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[0xf] = 1;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1d));
  return param_1;
}



/* c04149a4 FUN_c04149a4 */

/* Boundary evidence: original MIPS .pdata c04149a4..c0414a53. Semantic name remains unreviewed. */

void FUN_c04149a4(int *param_1)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1[3]) {
    iVar2 = 0;
    do {
      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + *param_1) + 4) + 4) +
                            *(int *)(iVar2 + *param_1) + 4) + 8))();
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < param_1[3]);
  }
  param_1[3] = 0;
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if ((void *)*param_1 != (void *)0x0) {
      operator_delete((void *)*param_1);
    }
    operator_delete(param_1);
  }
  return;
}



/* c0414a54 FUN_c0414a54 */

/* Boundary evidence: original MIPS .pdata c0414a54..c0414ad7. Semantic name remains unreviewed. */

undefined4 FUN_c0414a54(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  puVar1 = operator_new(0xa4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c04147d4(puVar1,1);
  }
  if (puVar1 == (undefined4 *)0x0) {
    uVar3 = 0x8007000e;
    iVar2 = 0;
  }
  else {
    iVar2 = (int)puVar1 + *(int *)(puVar1[1] + 8) + 4;
  }
  *param_1 = iVar2;
  return uVar3;
}



/* c0414ad8 FUN_c0414ad8 */

/* Boundary evidence: original MIPS .pdata c0414ad8..c0414bff. Semantic name remains unreviewed. */

void FUN_c0414ad8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0411260;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411254;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c0411238;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x90;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x98;
  if ((HANDLE)param_1[2] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[2]);
  }
  if ((HANDLE)param_1[3] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[3]);
  }
  if ((HANDLE)param_1[4] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[4]);
  }
  if ((HANDLE)param_1[6] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[6]);
  }
  if ((HANDLE)param_1[5] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[5]);
  }
  if ((int *)param_1[0x1a] != (int *)0x0) {
    FUN_c04149a4((int *)param_1[0x1a]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1d));
  return;
}



/* c0414c00 FUN_c0414c00 */

/* Boundary evidence: original MIPS .pdata c0414c00..c0414e6f. Semantic name remains unreviewed. */

int FUN_c0414c00(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = (undefined4 *)(*(int *)(*(int *)(param_1 + -0x98) + 8) + param_1 + -0x98);
  iVar1 = (**(code **)*puVar4)(puVar4,param_2);
  if (iVar1 < 0) {
    return iVar1;
  }
  *param_3 = 0;
  puVar4 = operator_new(0xb0);
  if (puVar4 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c04164a0(puVar4,1);
  }
  if (piVar2 == (int *)0x0) {
    return -0x7ff8fff2;
  }
  iVar1 = (**(code **)(*piVar2 + 0x44))
                    (piVar2,param_1 + -0x9c,param_2,*(undefined4 *)(param_1 + -0x60));
  if (iVar1 < 0) {
    (**(code **)(*(int *)((int)piVar2 + *(int *)(piVar2[1] + 4) + 4) + 8))();
    return iVar1;
  }
  *param_3 = piVar2;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + -0x28));
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + -0x4c));
  iVar5 = *(int *)(param_1 + -0x2c) + 1;
  *(int *)(param_1 + -0x2c) = iVar5;
  if (*(int *)(*(int *)(param_1 + -0x34) + 8) < iVar5) {
    puVar4 = operator_new(0x10);
    if (puVar4 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_c041460c(puVar4,*(int *)(param_1 + -0x2c) + 0x20);
    }
    if (piVar3 != (int *)0x0) {
      if (*piVar3 != 0) {
        FUN_c04149a4(*(int **)(param_1 + -0x34));
        *(int **)(param_1 + -0x34) = piVar3;
        goto LAB_c0414d78;
      }
      operator_delete(piVar3);
    }
    (**(code **)(*(int *)((int)piVar2 + *(int *)(piVar2[1] + 4) + 4) + 8))();
    iVar1 = -0x7ff8fff2;
  }
  else {
LAB_c0414d78:
    if ((*(int *)(param_1 + -0x2c) == 1) && (*(int *)(param_1 + -0x30) == 0)) {
      iVar1 = (**(code **)(**(int **)(param_1 + -0x78) + 0x18))();
      if (iVar1 < 0) {
        (**(code **)(*(int *)((int)piVar2 + *(int *)(piVar2[1] + 4) + 4) + 8))();
        *param_3 = 0;
      }
      else {
        *(undefined4 *)(param_1 + -0x30) = 1;
        *(undefined4 *)(param_1 + -0x54) = 0;
        EventModify(*(undefined4 *)(param_1 + -0x88),3);
        EventModify(*(undefined4 *)(param_1 + -0x84),2);
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + -0x4c));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + -0x28));
  return iVar1;
}



/* c0414e70 FUN_c0414e70 */

/* Boundary evidence: original MIPS .pdata c0414e70..c04150ef. Semantic name remains unreviewed. */

void FUN_c0414e70(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  DWORD DVar4;
  DWORD DVar5;
  uint uVar6;
  int *piVar7;
  size_t local_30;
  void *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar2 = (**(code **)**(undefined4 **)(param_1 + 0x24))();
  uVar6 = 0;
  iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))
                    (*(int **)(param_1 + 0x24),&local_2c,&local_30,&local_28,0);
  while (iVar3 != 0) {
    memset(local_2c,0,local_30);
    (**(code **)(**(int **)(param_1 + 0x24) + 0xc))(*(int **)(param_1 + 0x24),local_28);
    bVar1 = uVar2 < uVar6;
    uVar6 = uVar6 + 1;
    *(size_t *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + local_30;
    if (bVar1) break;
    iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))
                      (*(int **)(param_1 + 0x24),&local_2c,&local_30,&local_28,0);
  }
  DVar4 = GetTickCount();
  do {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))
                      (*(int **)(param_1 + 0x24),&local_2c,&local_30,&local_28,0);
    if (iVar3 == 0) {
      DVar4 = GetTickCount();
      iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 8))
                        (*(int **)(param_1 + 0x24),&local_2c,&local_30,&local_28,1000);
      if (iVar3 != 0) goto LAB_c0414ff4;
    }
    else {
      DVar5 = GetTickCount();
      if (1000 < DVar5 - DVar4) {
        Sleep(100);
        DVar4 = GetTickCount();
      }
LAB_c0414ff4:
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x50));
      piVar7 = *(int **)(param_1 + 0x68);
      FUN_c041466c(piVar7,*(int *)(param_1 + 100));
      if (piVar7[3] == 0) {
        *(undefined4 *)(param_1 + 0x44) = 0;
      }
      iVar3 = *(int *)(param_1 + 0x44);
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x50));
      (**(code **)(**(int **)(param_1 + 0x24) + 0x10))(*(int **)(param_1 + 0x24),&local_24);
      FUN_c04141d4(piVar7,local_24,*(undefined4 *)(param_1 + 0x48));
      FUN_c04140e8(piVar7,local_2c,local_30);
      (**(code **)(**(int **)(param_1 + 0x24) + 0x10))(*(int **)(param_1 + 0x24),&local_24);
      FUN_c0414280(piVar7,local_24);
      FUN_c04149a4(piVar7);
      (**(code **)(**(int **)(param_1 + 0x24) + 0xc))(*(int **)(param_1 + 0x24),local_28);
      *(size_t *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + local_30;
      if (iVar3 == 0) {
        return;
      }
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      return;
    }
  } while( true );
}



/* c0415108 FUN_c0415108 */

/* Boundary evidence: original MIPS .pdata c0415108..c0415163. Semantic name remains unreviewed. */

LONG FUN_c0415108(int param_1)

{
  LONG LVar1;
  undefined4 *puVar2;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + -0x74));
  if ((LVar1 == 0) && (puVar2 = (undefined4 *)(param_1 + -0x94), puVar2 != (undefined4 *)0x0)) {
    FUN_c0414ad8(puVar2);
    operator_delete(puVar2);
  }
  return LVar1;
}



/* c0415164 FUN_c0415164 */

/* Boundary evidence: original MIPS .pdata c0415164..c0415297. Semantic name remains unreviewed. */

void FUN_c0415164(int param_1)

{
  undefined4 uVar1;
  DWORD DVar2;
  int iVar3;
  HANDLE local_28;
  undefined4 local_24;
  HANDLE local_20;
  undefined4 local_1c;
  
  local_28 = *(HANDLE *)(param_1 + 0x14);
  local_24 = *(undefined4 *)(param_1 + 8);
  local_20 = *(HANDLE *)(param_1 + 0xc);
  local_1c = *(undefined4 *)(param_1 + 0x10);
  uVar1 = __GetUserKData(8);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  DVar2 = WaitForMultipleObjects(2,&local_28,0,0xffffffff);
  while (DVar2 != 1) {
    while (*(int *)(param_1 + 0x6c) != 0) {
      DVar2 = WaitForMultipleObjects(2,&local_20,0,0xffffffff);
      if (DVar2 == 0) {
        FUN_c0414e70(param_1);
      }
      else if (DVar2 == 1) {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x50));
        if ((*(int *)(param_1 + 0x70) == 0) &&
           (iVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 0x14))(), -1 < iVar3)) {
          *(undefined4 *)(param_1 + 0x6c) = 0;
          EventModify(*(undefined4 *)(param_1 + 0x18),3);
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x50));
      }
    }
    DVar2 = WaitForMultipleObjects(2,&local_28,0,0xffffffff);
  }
  return;
}



/* c04152b0 FUN_c04152b0 */

/* Boundary evidence: original MIPS .pdata c04152b0..c04152fb. Semantic name remains unreviewed. */

undefined4 FUN_c04152b0(int param_1)

{
  FUN_c0415164(param_1);
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + param_1 + 4) + 8))();
  return 0;
}



/* c04152fc FUN_c04152fc */

/* Boundary evidence: original MIPS .pdata c04152fc..c041572b. Semantic name remains unreviewed. */

int FUN_c04152fc(int param_1,int *param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  HANDLE pvVar6;
  HKEY local_58;
  uint local_54;
  int local_50;
  int local_4c;
  undefined4 local_48 [2];
  undefined1 auStack_40 [8];
  uint local_38;
  int local_34;
  int local_30;
  
  puVar3 = operator_new(0x10);
  if (puVar3 == (undefined4 *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = FUN_c041460c(puVar3,0x20);
  }
  *(int **)(param_1 + -0x34) = piVar4;
  if ((piVar4 != (int *)0x0) && (*piVar4 != 0)) {
    puVar3 = operator_new(0x2c);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = FUN_c0416790(puVar3);
    }
    *(undefined4 **)(param_1 + -0x78) = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      local_50 = 4;
      local_4c = 0x800;
      local_54 = 0xac44;
      local_48[0] = 1;
      FUN_c0414704(&local_58,L"Audio\\SoftwareMixer");
      FUN_c0414760(&local_58,L"SampleRate",(LPBYTE)&local_54);
      FUN_c0414760(&local_58,L"BufferSize",(LPBYTE)&local_4c);
      FUN_c0414760(&local_58,L"Buffers",(LPBYTE)&local_50);
      FUN_c0414760(&local_58,L"EnableLowPassFilter",(LPBYTE)local_48);
      FUN_c0414760(&local_58,L"Priority256",(LPBYTE)(param_1 + -0x50));
      *(undefined4 *)(param_1 + -0x60) = local_48[0];
      memset(auStack_40,0,0x1c);
      iVar5 = (**(code **)(*param_2 + 4))(param_2,0x16,0,auStack_40,0x1c);
      if (iVar5 == 0) {
        if (local_30 != 0) {
          local_50 = local_30;
        }
        if (local_34 != 0) {
          local_4c = local_34;
        }
        if (local_38 != 0) {
          local_54 = local_38;
        }
      }
      *(undefined1 *)(param_1 + -0x73) = 0;
      *(undefined1 *)(param_1 + -0x65) = 0;
      *(undefined1 *)(param_1 + -0x72) = 2;
      *(undefined1 *)(param_1 + -0x71) = 0;
      *(uint *)(param_1 + -0x6c) = local_54 << 2;
      piVar4 = *(int **)(param_1 + -0x78);
      uVar1 = param_1 - 0x6dU & 3;
      puVar2 = (uint *)((param_1 - 0x6dU) - uVar1);
      *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | local_54 >> (3 - uVar1) * 8;
      *(undefined1 *)(param_1 + -0x67) = 0;
      *(undefined1 *)(param_1 + -99) = 0;
      *(undefined1 *)(param_1 + -0x74) = 1;
      *(undefined1 *)(param_1 + -0x66) = 0x10;
      *(undefined1 *)(param_1 + -0x68) = 4;
      uVar1 = param_1 - 0x70U & 3;
      puVar2 = (uint *)((param_1 - 0x70U) - uVar1);
      *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | local_54 << uVar1 * 8;
      *(undefined1 *)(param_1 + -100) = 0;
      iVar5 = (**(code **)(*piVar4 + 0x1c))
                        (piVar4,param_2,(undefined1 *)(param_1 + -0x74),local_4c,local_50);
      if (iVar5 < 0) {
        if (local_58 == (HKEY)0x0) {
          return iVar5;
        }
        RegCloseKey(local_58);
        return iVar5;
      }
      pvVar6 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      *(HANDLE *)(param_1 + -0x94) = pvVar6;
      if (pvVar6 != (HANDLE)0x0) {
        pvVar6 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        *(HANDLE *)(param_1 + -0x90) = pvVar6;
        if (pvVar6 != (HANDLE)0x0) {
          pvVar6 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
          *(HANDLE *)(param_1 + -0x8c) = pvVar6;
          if (pvVar6 != (HANDLE)0x0) {
            pvVar6 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
            *(HANDLE *)(param_1 + -0x88) = pvVar6;
            if (pvVar6 != (HANDLE)0x0) {
              pvVar6 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
              *(HANDLE *)(param_1 + -0x84) = pvVar6;
              if (pvVar6 != (HANDLE)0x0) {
                (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x98) + 4) + param_1 + -0x98) + 4
                            ))();
                pvVar6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c04152b0,
                                      (LPVOID)(param_1 + -0x9c),0,(LPDWORD)0x0);
                if (pvVar6 == (HANDLE)0x0) {
                  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x98) + 4) + param_1 + -0x98) +
                              8))();
                  if (local_58 != (HKEY)0x0) {
                    RegCloseKey(local_58);
                  }
                  return -0x7fffbffb;
                }
                CeSetThreadPriority(pvVar6,*(undefined4 *)(param_1 + -0x50));
                CloseHandle(pvVar6);
                if (local_58 != (HKEY)0x0) {
                  RegCloseKey(local_58);
                }
                return 0;
              }
            }
          }
        }
      }
      if (local_58 != (HKEY)0x0) {
        RegCloseKey(local_58);
      }
    }
  }
  return -0x7ff8fff2;
}



/* c0415744 FUN_c0415744 */

/* Boundary evidence: original MIPS .pdata c0415744..c0415833. Semantic name remains unreviewed. */

void FUN_c0415744(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  
  *param_1 = &PTR_LAB_c0411380;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411374;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xa8;
  iVar2 = param_1[5];
  if (iVar2 != 0) {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + iVar2 + 4) + 8))();
  }
  piVar1 = (int *)param_1[9];
  if (piVar1 != (int *)0x0) {
    if (param_1[2] != 0) {
      (**(code **)(*piVar1 + 4))(piVar1,param_1);
    }
    (**(code **)(*(int *)param_1[9] + 0x10))((int *)param_1[9],param_1);
  }
  if ((void *)param_1[0x1d] != (void *)0x0) {
    operator_delete((void *)param_1[0x1d]);
  }
  if ((void *)param_1[0x1e] != (void *)0x0) {
    operator_delete((void *)param_1[0x1e]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  return;
}



/* c0415834 FUN_c0415834 */

/* Boundary evidence: original MIPS .pdata c0415834..c04158a3. Semantic name remains unreviewed. */

undefined4 FUN_c0415834(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_c04111c0,0x10);
  if (iVar1 == 0) {
    InterlockedIncrement((LONG *)(param_1 + -0x8c));
    *param_3 = param_1 + -0xac;
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* c04158a4 FUN_c04158a4 */

/* Boundary evidence: original MIPS .pdata c04158a4..c04158bf. Semantic name remains unreviewed. */

void FUN_c04158a4(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + -0x8c));
  return;
}



/* c04158cc FUN_c04158cc */

/* Boundary evidence: original MIPS .pdata c04158cc..c041590f. Semantic name remains unreviewed. */

undefined4 FUN_c04158cc(int param_1)

{
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + param_1 + 4) + 8))();
  return 0;
}



/* c0415910 FUN_c0415910 */

/* Boundary evidence: original MIPS .pdata c0415910..c0415997. Semantic name remains unreviewed. */

undefined4 FUN_c0415910(int *param_1,uint *param_2,int *param_3)

{
  if (param_2 != (uint *)0x0) {
    (**(code **)(*param_1 + 0x48))(param_1);
    *param_2 = param_1[0x14] + (param_1[10] - 1U) & ~(param_1[10] - 1U);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = param_1[0x25] * param_1[10];
  }
  return 0;
}



/* c04159fc FUN_c04159fc */

/* Boundary evidence: original MIPS .pdata c04159fc..c0415a3f. Semantic name remains unreviewed. */

undefined4 FUN_c04159fc(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  *(int *)(param_1 + 0x60) = param_2;
  *(undefined4 *)(param_1 + 100) = param_3;
  uVar1 = FUN_c0417054(param_2);
  *(uint *)(param_1 + 0x58) = uVar1;
  uVar1 = FUN_c0417054(*(int *)(param_1 + 100));
  *(uint *)(param_1 + 0x5c) = uVar1;
  return 0;
}



/* c0415a58 FUN_c0415a58 */

/* Boundary evidence: original MIPS .pdata c0415a58..c0415b17. Semantic name remains unreviewed. */

undefined4 FUN_c0415a58(int *param_1,int param_2,uint param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  param_1[0x28] = param_2;
  if (param_1[10] == 0) {
    trap(0x1c00);
  }
  param_1[0x26] = param_3 / (uint)param_1[10];
  pcVar1 = *(code **)(*param_1 + 0x34);
  param_1[0x27] = param_3;
  param_1[0x15] = 0;
  param_1[0x1a] = (uint)param_1[0x20] >> 1;
  (*pcVar1)(param_1);
  memset((void *)param_1[0x1d],0,0x10);
  memset((void *)param_1[0x1e],0,0x10);
  param_1[0x11] = 0;
  if ((param_1[2] == 0) || (param_1[4] != 0)) {
    uVar2 = (*(code *)**(undefined4 **)param_1[9])((undefined4 *)param_1[9],param_1);
  }
  return uVar2;
}



/* c0415b18 FUN_c0415b18 */

/* Boundary evidence: original MIPS .pdata c0415b18..c0415b67. Semantic name remains unreviewed. */

undefined4 FUN_c0415b18(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    uVar1 = 0x88810005;
  }
  else {
    *(undefined4 *)(param_1 + 0x98) = 0;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    (**(code **)(**(int **)(param_1 + 0x24) + 8))();
    uVar1 = 0;
  }
  return uVar1;
}



/* c0415b68 FUN_c0415b68 */

/* Boundary evidence: original MIPS .pdata c0415b68..c0415bb7. Semantic name remains unreviewed. */

undefined4 FUN_c0415b68(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    uVar1 = 0x88810005;
  }
  else {
    *(undefined4 *)(param_1 + 0x98) = 0;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    (**(code **)(**(int **)(param_1 + 0x24) + 4))();
    uVar1 = 0;
  }
  return uVar1;
}



/* c0415bb8 FUN_c0415bb8 */

/* Boundary evidence: original MIPS .pdata c0415bb8..c0415df7. Semantic name remains unreviewed. */

void FUN_c0415bb8(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  void *local_30;
  void *local_2c;
  int local_28;
  int local_24;
  
  *(undefined4 *)(param_1 + 0x70) = 0x3b;
  puVar2 = *(undefined4 **)(param_1 + 0x74);
  *puVar2 = puVar2[0x3c];
  puVar2[1] = puVar2[0x3d];
  puVar2[2] = puVar2[0x3e];
  puVar2[3] = puVar2[0x3f];
  puVar2 = *(undefined4 **)(param_1 + 0x78);
  *puVar2 = puVar2[0x3c];
  puVar2[1] = puVar2[0x3d];
  puVar2[2] = puVar2[0x3e];
  puVar2[3] = puVar2[0x3f];
  local_30 = (void *)(*(int *)(param_1 + 0x74) + 0x10);
  local_2c = (void *)(*(int *)(param_1 + 0x78) + 0x10);
  iVar4 = *(int *)(param_1 + 0x70) + 1;
  local_28 = iVar4;
  while (0 < iVar4) {
    if (*(int *)(param_1 + 0x98) == 0) {
      memset(local_30,0,iVar4 << 2);
      memset(local_2c,0,iVar4 << 2);
      iVar4 = 0;
      local_28 = iVar4;
    }
    else {
      iVar1 = iVar4;
      if (*(int *)(param_1 + 0x98) < iVar4) {
        iVar1 = *(int *)(param_1 + 0x98);
      }
      local_24 = iVar1;
      (**(code **)(param_1 + 0xa4))(iVar1,&local_30,&local_2c,param_1 + 0xa0);
      *(int *)(param_1 + 0x94) = iVar1 + *(int *)(param_1 + 0x94);
      iVar4 = iVar4 - iVar1;
      iVar1 = *(int *)(param_1 + 0x98) - iVar1;
      *(int *)(param_1 + 0x98) = iVar1;
      local_28 = iVar4;
      if (iVar1 < 1) {
        puVar3 = (uint *)(param_1 + 0x9c);
        *puVar3 = 0;
        (**(code **)(**(int **)(param_1 + 0x14) + 4))
                  (*(int **)(param_1 + 0x14),param_1 + 0xa0,puVar3);
        if (*(uint *)(param_1 + 0x28) == 0) {
          trap(0x1c00);
        }
        *(uint *)(param_1 + 0x98) = *puVar3 / *(uint *)(param_1 + 0x28);
      }
    }
  }
  return;
}



/* c0415df8 FUN_c0415df8 */

/* Boundary evidence: original MIPS .pdata c0415df8..c0415e03. Semantic name remains unreviewed. */

undefined4 FUN_c0415df8(void)

{
  return 1;
}



/* c0415e04 FUN_c0415e04 */

/* Boundary evidence: original MIPS .pdata c0415e04..c04160ff. Semantic name remains unreviewed. */

void FUN_c0415e04(int *param_1,int param_2,uint *param_3,int param_4)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar5 = param_1[0x16];
  iVar6 = param_1[0x17];
  iVar7 = (0x3b - param_1[0x1c]) * 4;
  iVar8 = param_1[0x21];
  piVar3 = (int *)(iVar7 + param_1[0x1d]);
  piVar2 = (int *)(iVar7 + param_1[0x1e]);
  iVar12 = param_1[0x1f];
  iVar11 = param_1[0x20];
  iVar7 = param_1[0x1a];
  if ((param_1[0x1b] == 0) || (bVar1 = true, iVar12 == iVar11)) {
    bVar1 = false;
  }
  while (0 < param_2) {
    param_2 = param_2 + -1;
    if (bVar1) {
      iVar10 = ((uint)(iVar7 * iVar8) >> 0x1a) * 0x14;
      iVar4 = piVar3[1] * *(int *)(&DAT_c04180d0 + iVar10) +
              piVar3[2] * *(int *)(&DAT_c04180d4 + iVar10) +
              piVar3[3] * *(int *)(&DAT_c04180d8 + iVar10) +
              piVar3[4] * *(int *)(&DAT_c04180dc + iVar10) +
              *piVar3 * *(int *)(&DAT_c04180cc + iVar10) >> 0xe;
      iVar10 = piVar2[1] * *(int *)(&DAT_c04180d0 + iVar10) +
               piVar2[2] * *(int *)(&DAT_c04180d4 + iVar10) +
               piVar2[3] * *(int *)(&DAT_c04180d8 + iVar10) +
               piVar2[4] * *(int *)(&DAT_c04180dc + iVar10) +
               *piVar2 * *(int *)(&DAT_c04180cc + iVar10) >> 0xe;
    }
    else {
      iVar4 = piVar3[4];
      iVar10 = piVar2[4];
    }
    uVar9 = iVar4 * (iVar5 >> 2) >> 0xe;
    iVar4 = iVar10 * (iVar6 >> 2) >> 0xe;
    if (param_4 != 0) {
      uVar9 = (int)(short)*param_3 + uVar9;
      iVar4 = ((int)*param_3 >> 0x10) + iVar4;
    }
    if ((int)uVar9 < -0x8000) {
      uVar9 = 0xffff8000;
    }
    else if (0x7fff < (int)uVar9) {
      uVar9 = 0x7fff;
    }
    if (iVar4 < -0x8000) {
      iVar4 = -0x8000;
    }
    else if (0x7fff < iVar4) {
      iVar4 = 0x7fff;
    }
    *param_3 = iVar4 << 0x10 | uVar9 & 0xffff;
    param_3 = param_3 + 1;
    for (iVar7 = iVar7 - iVar12; iVar7 < 0; iVar7 = iVar7 + iVar11) {
      iVar4 = param_1[0x1c];
      piVar3 = piVar3 + 1;
      param_1[0x1c] = iVar4 + -1;
      piVar2 = piVar2 + 1;
      if (iVar4 + -1 < 0) {
        (**(code **)(*param_1 + 0x34))(param_1);
        piVar3 = (int *)param_1[0x1d];
        piVar2 = (int *)param_1[0x1e];
      }
    }
  }
  param_1[0x1a] = iVar7;
  return;
}



/* c0416100 FUN_c0416100 */

/* Boundary evidence: original MIPS .pdata c0416100..c0416167. Semantic name remains unreviewed. */

void FUN_c0416100(int *param_1)

{
  undefined4 local_18;
  undefined1 auStack_14 [4];
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  (**(code **)(*(int *)param_1[9] + 0xc))((int *)param_1[9],&local_18,auStack_14);
  (**(code **)(*param_1 + 0x4c))(param_1,local_18);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  return;
}



/* c0416274 FUN_c0416274 */

/* Boundary evidence: original MIPS .pdata c0416274..c04162f7. Semantic name remains unreviewed. */

void FUN_c0416274(int *param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  (**(code **)(*param_1 + 0x4c))(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  (*(code *)**(undefined4 **)param_1[5])
            ((undefined4 *)param_1[5],~(param_1[10] - 1U) & param_1[0x14]);
  return;
}



/* c04162f8 FUN_c04162f8 */

/* Boundary evidence: original MIPS .pdata c04162f8..c041631f. Semantic name remains unreviewed. */

void FUN_c04162f8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x24) + 0x14))();
  return;
}



/* c04164a0 FUN_c04164a0 */

/* Boundary evidence: original MIPS .pdata c04164a0..c041657b. Semantic name remains unreviewed. */

undefined4 * FUN_c04164a0(undefined4 *param_1,int param_2)

{
  if (param_2 != 0) {
    param_1[1] = &DAT_c04113d0;
  }
  *param_1 = &PTR_LAB_c0411340;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411334;
  *param_1 = &PTR_LAB_c0411380;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c0411374;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xa8;
  param_1[8] = 1;
  param_1[9] = 0;
  param_1[5] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x25] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x28] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[0x14] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  return param_1;
}



/* c041657c FUN_c041657c */

/* Boundary evidence: original MIPS .pdata c041657c..c041671b. Semantic name remains unreviewed. */

undefined4 FUN_c041657c(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  if (*(short *)(param_3 + 2) == 1) {
    if (*(short *)(param_3 + 0xe) != 8) {
      puVar4 = &LAB_c041637c;
LAB_c041661c:
      *(undefined1 **)(param_1 + 0xa4) = puVar4;
      goto LAB_c0416620;
    }
    puVar4 = &LAB_c0416328;
  }
  else {
    if (*(short *)(param_3 + 0xe) != 8) {
      puVar4 = &LAB_c0416424;
      goto LAB_c041661c;
    }
    puVar4 = &LAB_c04163bc;
  }
  *(undefined1 **)(param_1 + 0xa4) = puVar4;
LAB_c0416620:
  *(uint *)(param_1 + 0x28) = (uint)*(ushort *)(param_3 + 0xc);
  *(undefined4 *)(param_1 + 0x58) = 0x10000;
  *(undefined4 *)(param_1 + 0x5c) = 0x10000;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x6c) = param_4;
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 8) + param_2 + 4) + 0x10))();
  uVar5 = *(uint *)(iVar1 + 4);
  *(uint *)(param_1 + 0x80) = uVar5;
  if (uVar5 == 0) {
    trap(0x1c00);
  }
  *(uint *)(param_1 + 0x84) = 0xfc000000 / uVar5;
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_3 + 8);
  pvVar2 = operator_new(0x100);
  *(void **)(param_1 + 0x74) = pvVar2;
  pvVar2 = operator_new(0x100);
  *(void **)(param_1 + 0x78) = pvVar2;
  if ((*(int *)(param_1 + 0x74) == 0) || (pvVar2 == (void *)0x0)) {
    uVar3 = 0x8007000e;
  }
  else {
    *(int *)(param_1 + 0x24) = param_2;
    uVar3 = 0;
  }
  return uVar3;
}



/* c041671c FUN_c041671c */

/* Boundary evidence: original MIPS .pdata c041671c..c0416777. Semantic name remains unreviewed. */

LONG FUN_c041671c(int param_1)

{
  LONG LVar1;
  undefined4 *puVar2;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + -0x8c));
  if ((LVar1 == 0) && (puVar2 = (undefined4 *)(param_1 + -0xac), puVar2 != (undefined4 *)0x0)) {
    FUN_c0415744(puVar2);
    operator_delete(puVar2);
  }
  return LVar1;
}



/* c0416790 FUN_c0416790 */

undefined4 * FUN_c0416790(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_c04113d8;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  return param_1;
}



/* c04167c8 FUN_c04167c8 */

/* Boundary evidence: original MIPS .pdata c04167c8..c041688b. Semantic name remains unreviewed. */

undefined4
FUN_c04167c8(int param_1,undefined4 *param_2,undefined4 *param_3,int *param_4,DWORD param_5)

{
  DWORD DVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 8),param_5);
  if (DVar1 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x14);
    *param_4 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24) * 0x20;
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x24) * 4);
    uVar2 = *(int *)(param_1 + 0x24) + 1;
    *(uint *)(param_1 + 0x24) = uVar2;
    if (*(uint *)(param_1 + 0x10) <= uVar2) {
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* c041688c FUN_c041688c */

/* Boundary evidence: original MIPS .pdata c041688c..c04168f3. Semantic name remains unreviewed. */

void FUN_c041688c(int param_1,int param_2)

{
  uint uVar1;
  long local_10 [2];
  
  if (*(int *)(param_2 + 0xc) != *(int *)(param_1 + 0x28)) {
    *(int *)(param_1 + 0x28) = *(int *)(param_2 + 0xc);
  }
  uVar1 = *(int *)(param_1 + 0x28) + 1;
  *(uint *)(param_1 + 0x28) = uVar1;
  if (*(uint *)(param_1 + 0x10) <= uVar1) {
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  local_10[0] = 0x1c43fe;
  ReleaseSemaphore(*(HANDLE *)(param_1 + 8),1,local_10);
  return;
}



/* c04168f4 FUN_c04168f4 */

/* Boundary evidence: original MIPS .pdata c04168f4..c0416983. Semantic name remains unreviewed. */

undefined4 FUN_c04168f4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_14;
  
  local_14 = DAT_c04185b8;
  local_20 = 4;
  local_1c = *param_2;
  uVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))
                    (*(int **)(param_1 + 4),0xd,*(undefined4 *)(param_1 + 0xc),&local_20,0xc);
  *param_2 = local_1c;
  FUN_c041747c(local_14);
  return uVar1;
}



/* c0416984 FUN_c0416984 */

/* Boundary evidence: original MIPS .pdata c0416984..c04169ef. Semantic name remains unreviewed. */

void FUN_c0416984(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))
                    (*(int **)(param_1 + 4),7,*(undefined4 *)(param_1 + 0xc),param_2,0x20);
  if (iVar1 == 8) {
    iVar1 = 0;
  }
  if (iVar1 == 0) {
    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 2;
  }
  return;
}



/* c0416a00 FUN_c0416a00 */

undefined4 FUN_c0416a00(uint param_1)

{
  if (param_1 < 8) {
    if (param_1 != 7) {
      if (param_1 == 0) {
        return 0;
      }
      if (param_1 != 3) {
        if (param_1 == 4) {
          return 0x88810002;
        }
        if (param_1 < 5) {
          return 0x80004005;
        }
        if (6 < param_1) {
          return 0x80004005;
        }
      }
      return 0x88810003;
    }
  }
  else if (param_1 != 8) {
    if (9 < param_1) {
      if (param_1 < 0xc) {
        return 0x80070057;
      }
      if (param_1 == 0x20) {
        return 0x88810001;
      }
    }
    return 0x80004005;
  }
  return 0x80004001;
}



/* c0416ad4 FUN_c0416ad4 */

/* Boundary evidence: original MIPS .pdata c0416ad4..c0416bd3. Semantic name remains unreviewed. */

undefined4 FUN_c0416ad4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  DWORD dwMilliseconds;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))
                    (*(int **)(param_1 + 4),9,*(undefined4 *)(param_1 + 0xc),param_2,0x20);
  if (iVar1 != 0) {
    uVar2 = *(uint *)(*(int *)(param_1 + 0x20) + 8);
    dwMilliseconds = (uint)(*(int *)(param_1 + 0x14) * 1000) / uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    if (200 < dwMilliseconds) {
      dwMilliseconds = 200;
    }
    Sleep(dwMilliseconds);
    uVar2 = 0;
    if (*(int *)(param_1 + 0x10) != 0) {
      iVar1 = *(int *)(param_1 + 0x1c);
      do {
        if (param_2 == iVar1) {
          *(uint *)(param_1 + 0x24) = uVar2;
          break;
        }
        uVar2 = uVar2 + 1;
        iVar1 = iVar1 + 0x20;
      } while (uVar2 < *(uint *)(param_1 + 0x10));
    }
    ReleaseSemaphore(*(HANDLE *)(param_1 + 8),1,(LPLONG)0x0);
  }
  return 0;
}



/* c0416bd4 FUN_c0416bd4 */

/* Boundary evidence: original MIPS .pdata c0416bd4..c0416bff. Semantic name remains unreviewed. */

void FUN_c0416bd4(undefined4 param_1,int param_2,int param_3,int param_4)

{
  if (param_2 == 0x3bd) {
    FUN_c041688c(param_3,param_4);
  }
  return;
}



/* c0416c00 FUN_c0416c00 */

/* Boundary evidence: original MIPS .pdata c0416c00..c0416e3b. Semantic name remains unreviewed. */

undefined4 FUN_c0416c00(int param_1,int *param_2,uint param_3,uint param_4,uint param_5)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  void *pvVar4;
  HANDLE pvVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [8];
  
  pcVar6 = *(code **)(*param_2 + 4);
  puVar1 = auStack_30 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  puVar1 = auStack_2c + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_3 >> (3 - uVar2) * 8;
  puVar1 = auStack_28 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  puVar1 = auStack_24 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  puVar1 = auStack_20 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  auStack_30 = (undefined1  [4])0x0;
  auStack_28 = (undefined1  [4])0x0;
  auStack_24 = (undefined1  [4])0x0;
  auStack_20._0_4_ = 0;
  auStack_2c = (undefined1  [4])param_3;
  uVar2 = (*pcVar6)(param_2,5,0,auStack_30,1);
  if (uVar2 == 0) {
    *(int **)(param_1 + 4) = param_2;
    *(uint *)(param_1 + 0x20) = param_3;
    *(uint *)(param_1 + 0x14) = param_4;
    *(uint *)(param_1 + 0x10) = param_5;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (*(ushort *)(param_3 + 0xc) == 0) {
      trap(0x1c00);
    }
    if (param_4 % (uint)*(ushort *)(param_3 + 0xc) == 0) {
      uVar8 = 0xffffffff;
      uVar2 = param_5 << 5;
      if (0x7ffffff < param_5) {
        uVar2 = uVar8;
      }
      pvVar4 = operator_new(uVar2);
      *(void **)(param_1 + 0x1c) = pvVar4;
      if (pvVar4 != (void *)0x0) {
        if (*(uint *)(param_1 + 0x10) < 0x40000000) {
          uVar8 = *(uint *)(param_1 + 0x10) << 2;
        }
        pvVar4 = operator_new(uVar8);
        *(void **)(param_1 + 0x18) = pvVar4;
        if (pvVar4 != (void *)0x0) {
          memset(pvVar4,0,*(int *)(param_1 + 0x10) << 2);
          uVar2 = 0;
          if (param_5 != 0) {
            iVar10 = 0;
            iVar9 = 0;
            do {
              pvVar4 = operator_new(*(uint *)(param_1 + 0x14));
              *(void **)(iVar9 + *(int *)(param_1 + 0x18)) = pvVar4;
              if (*(int *)(iVar9 + *(int *)(param_1 + 0x18)) == 0) goto LAB_c0416d14;
              *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar10 + 4) =
                   *(undefined4 *)(param_1 + 0x14);
              *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar10) =
                   *(undefined4 *)(iVar9 + *(int *)(param_1 + 0x18));
              *(uint *)(*(int *)(param_1 + 0x1c) + iVar10 + 0xc) = uVar2;
              *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar10 + 0x10) = 0;
              iVar7 = *(int *)(param_1 + 0x1c) + iVar10;
              uVar2 = uVar2 + 1;
              iVar9 = iVar9 + 4;
              iVar10 = iVar10 + 0x20;
              *(undefined4 *)(iVar7 + 0x14) = 0;
            } while (uVar2 < param_5);
          }
          pvVar5 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,*(LONG *)(param_1 + 0x10),
                                    *(LONG *)(param_1 + 0x10),(LPCWSTR)0x0);
          *(HANDLE *)(param_1 + 8) = pvVar5;
          if (pvVar5 != (HANDLE)0x0) {
            return 0;
          }
        }
      }
LAB_c0416d14:
      uVar3 = 0x8007000e;
    }
    else {
      uVar3 = 0x80004005;
    }
  }
  else {
    uVar3 = FUN_c0416a00(uVar2);
  }
  return uVar3;
}



/* c0416e3c FUN_c0416e3c */

/* Boundary evidence: original MIPS .pdata c0416e3c..c0416f67. Semantic name remains unreviewed. */

undefined4 FUN_c0416e3c(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_30;
  int local_2c;
  code *local_28;
  int *local_24;
  undefined4 local_20;
  
  local_2c = param_1[8];
  local_28 = FUN_c0416bd4;
  local_30 = 0;
  local_20 = 0;
  local_24 = param_1;
  uVar1 = (**(code **)(*(int *)param_1[1] + 4))
                    ((int *)param_1[1],5,param_1 + 3,&local_30,0x80030000);
  if (uVar1 == 0) {
    uVar4 = 0;
    if (param_1[4] != 0) {
      iVar3 = 0;
      do {
        uVar1 = FUN_c0416984((int)param_1,iVar3 + param_1[7]);
        if (uVar1 != 0) {
          (**(code **)(*param_1 + 0x14))(param_1);
          goto LAB_c0416ebc;
        }
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 0x20;
      } while (uVar4 < (uint)param_1[4]);
    }
    (**(code **)(*(int *)(*(int *)(*(int *)(param_1[1] + 4) + 4) + param_1[1] + 4) + 4))();
    uVar2 = 0;
  }
  else {
LAB_c0416ebc:
    uVar2 = FUN_c0416a00(uVar1);
  }
  return uVar2;
}



/* c0416f68 FUN_c0416f68 */

/* Boundary evidence: original MIPS .pdata c0416f68..c0417053. Semantic name remains unreviewed. */

void FUN_c0416f68(int param_1)

{
  int iVar1;
  uint uVar2;
  
  (**(code **)(**(int **)(param_1 + 4) + 4))
            (*(int **)(param_1 + 4),0xc,*(undefined4 *)(param_1 + 0xc),0,0);
  uVar2 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    iVar1 = 0;
    do {
      (**(code **)(**(int **)(param_1 + 4) + 4))
                (*(int **)(param_1 + 4),8,*(undefined4 *)(param_1 + 0xc),
                 iVar1 + *(int *)(param_1 + 0x1c),0x20);
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0x20;
    } while (uVar2 < *(uint *)(param_1 + 0x10));
  }
  uVar2 = (**(code **)(**(int **)(param_1 + 4) + 4))
                    (*(int **)(param_1 + 4),6,*(undefined4 *)(param_1 + 0xc),0,0x80000000);
  (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4) + *(int *)(param_1 + 4) +
                       4) + 8))();
  FUN_c0416a00(uVar2);
  return;
}



/* c0417054 FUN_c0417054 */

uint FUN_c0417054(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0x10000;
  }
  else {
    iVar2 = (param_1 + -5) / 10;
    if (0 < iVar2) {
      iVar2 = 0;
    }
    if (iVar2 < -0x3c4) {
      uVar1 = 0;
    }
    else {
      uVar1 = (uint)(ushort)(&DAT_c0411b80)[iVar2];
    }
  }
  return uVar1;
}



/* c04171c8 FUN_c04171c8 */

/* Boundary evidence: original MIPS .pdata c04171c8..c0417303. Semantic name remains unreviewed. */

int FUN_c04171c8(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c041862c != (code *)0x0) {
      iVar2 = (*DAT_c041862c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0417278;
    FUN_c041765c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = DllMain(param_1,param_2);
  }
LAB_c0417278:
  if (((param_2 == 0) && (FUN_c04175e4(), iVar1 != 0)) && (DAT_c041862c != (code *)0x0)) {
    iVar1 = (*DAT_c041862c)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0417304 FUN_c0417304 */

/* Boundary evidence: original MIPS .pdata c0417304..c041732f. Semantic name remains unreviewed. */

void FUN_c0417304(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c0417330 entry */

/* Boundary evidence: original MIPS .pdata c0417330..c0417387. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c0417388();
  }
  FUN_c04171c8(param_1,param_2,param_3);
  return;
}



/* c0417388 FUN_c0417388 */

/* Boundary evidence: original MIPS .pdata c0417388..c04173fb. Semantic name remains unreviewed. */

void FUN_c0417388(void)

{
  uint uVar1;
  
  if ((DAT_c04185b8 == 0) || (DAT_c04185b8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c04185b8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c04185b8 == 0) {
      DAT_c04185b8 = 0xb064;
    }
  }
  DAT_c04185bc = ~DAT_c04185b8;
  return;
}



/* c04173fc FUN_c04173fc */

/* Boundary evidence: original MIPS .pdata c04173fc..c041744f. Semantic name remains unreviewed. */

void FUN_c04173fc(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c041747c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0417450 FUN_c0417450 */

/* Boundary evidence: original MIPS .pdata c0417450..c041747b. Semantic name remains unreviewed. */

undefined4 FUN_c0417450(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c04173fc(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c041747c FUN_c041747c */

/* Boundary evidence: original MIPS .pdata c041747c..c04174c3. Semantic name remains unreviewed. */

void FUN_c041747c(uint param_1)

{
  if ((param_1 == DAT_c04185b8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c04174c4 FUN_c04174c4 */

/* Boundary evidence: original MIPS .pdata c04174c4..c04175e3. Semantic name remains unreviewed. */

void FUN_c04174c4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c041861c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c0418624;
    if (DAT_c0418624 != (undefined4 *)0x0) {
      while (DAT_c0418620 = DAT_c0418620 + -1, _Memory <= DAT_c0418620) {
        if ((code *)*DAT_c0418620 != (code *)0x0) {
          (*(code *)*DAT_c0418620)();
          _Memory = DAT_c0418624;
        }
      }
      free(_Memory);
      DAT_c0418620 = (undefined4 *)0x0;
      DAT_c0418624 = (undefined4 *)0x0;
    }
    FUN_c0417608((undefined4 *)&DAT_c0411010,(undefined4 *)&DAT_c0411014);
  }
  FUN_c0417608((undefined4 *)&DAT_c0411018,(undefined4 *)&DAT_c041101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c0418628,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c04175e4 FUN_c04175e4 */

/* Boundary evidence: original MIPS .pdata c04175e4..c0417607. Semantic name remains unreviewed. */

void FUN_c04175e4(void)

{
  FUN_c04174c4(0,0,1);
  return;
}



/* c0417608 FUN_c0417608 */

/* Boundary evidence: original MIPS .pdata c0417608..c041765b. Semantic name remains unreviewed. */

void FUN_c0417608(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c041765c FUN_c041765c */

/* Boundary evidence: original MIPS .pdata c041765c..c0417697. Semantic name remains unreviewed. */

void FUN_c041765c(void)

{
  FUN_c0417608((undefined4 *)&DAT_c0411008,(undefined4 *)&DAT_c041100c);
  FUN_c0417608((undefined4 *)&DAT_c0411000,(undefined4 *)&DAT_c0411004);
  return;
}


