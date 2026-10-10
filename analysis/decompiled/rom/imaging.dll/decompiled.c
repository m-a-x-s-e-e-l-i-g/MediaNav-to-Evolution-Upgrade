/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40486bc4 FUN_40486bc4 */

/* Boundary evidence: original MIPS .pdata 40486bc4..40486c3f. Semantic name remains unreviewed. */

bool FUN_40486bc4(HMODULE param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = true;
  if (param_2 == 0) {
    FUN_40487244();
    FUN_4049d5c4();
  }
  else if (param_2 == 1) {
    DAT_404bd328 = param_1;
    DisableThreadLibraryCalls(param_1);
    iVar2 = FUN_40496398();
    bVar1 = false;
    if (iVar2 != 0) {
      bVar1 = FUN_40487180(0);
    }
  }
  return bVar1;
}



/* 40486c40 FUN_40486c40 */

/* Boundary evidence: original MIPS .pdata 40486c40..40486cdb. Semantic name remains unreviewed. */

undefined4 FUN_40486c40(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40482c64,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40481064,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 40486cdc FUN_40486cdc */

/* Boundary evidence: original MIPS .pdata 40486cdc..40486cf7. Semantic name remains unreviewed. */

void FUN_40486cdc(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 40486cf8 FUN_40486cf8 */

/* Boundary evidence: original MIPS .pdata 40486cf8..40486d53. Semantic name remains unreviewed. */

LONG FUN_40486cf8(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x14))(param_1,1);
  }
  return LVar1;
}



/* 40486d54 FUN_40486d54 */

/* Boundary evidence: original MIPS .pdata 40486d54..40486d97. Semantic name remains unreviewed. */

undefined4 * FUN_40486d54(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_4048104c;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 40486d98 FUN_40486d98 */

/* Boundary evidence: original MIPS .pdata 40486d98..40486e33. Semantic name remains unreviewed. */

undefined4 FUN_40486d98(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40482c64,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_404810d0,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 40486e34 FUN_40486e34 */

/* Boundary evidence: original MIPS .pdata 40486e34..40486e4f. Semantic name remains unreviewed. */

void FUN_40486e34(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 40486e50 FUN_40486e50 */

/* Boundary evidence: original MIPS .pdata 40486e50..40486eab. Semantic name remains unreviewed. */

LONG FUN_40486e50(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x40))(param_1,1);
  }
  return LVar1;
}



/* 40486eac FUN_40486eac */

/* Boundary evidence: original MIPS .pdata 40486eac..40486eeb. Semantic name remains unreviewed. */

undefined4 FUN_40486eac(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    InterlockedDecrement((LONG *)&DAT_404bd29c);
  }
  else {
    InterlockedIncrement((LONG *)&DAT_404bd29c);
  }
  return 0;
}



/* 40486eec FUN_40486eec */

/* Boundary evidence: original MIPS .pdata 40486eec..40486f2f. Semantic name remains unreviewed. */

undefined4 * FUN_40486eec(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_4048108c;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 40486f30 FUN_40486f30 */

/* Boundary evidence: original MIPS .pdata 40486f30..40486f73. Semantic name remains unreviewed. */

undefined4 * FUN_40486f30(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_4048104c;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 40486f74 FUN_40486f74 */

/* Boundary evidence: original MIPS .pdata 40486f74..40486fb7. Semantic name remains unreviewed. */

undefined4 * FUN_40486f74(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_4048108c;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 40486fb8 FUN_40486fb8 */

/* Boundary evidence: original MIPS .pdata 40486fb8..4048706f. Semantic name remains unreviewed. */

undefined4 FUN_40486fb8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    piVar1 = (int *)FUN_404962c4(8);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1[1] = 1;
      *piVar1 = (int)&PTR_FUN_404810e0;
    }
    if (piVar1 == (int *)0x0) {
      uVar2 = 0x8007000e;
    }
    else {
      uVar2 = (**(code **)*piVar1)(piVar1,param_3,param_4);
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  else {
    uVar2 = 0x80040110;
  }
  return uVar2;
}



/* 40487070 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40487070..4048713b. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  int *piVar2;
  HRESULT HVar3;
  
                    /* 0x7070  2  DllGetClassObject */
  iVar1 = memcmp(rclsid,&DAT_4048128c,0x10);
  if (iVar1 == 0) {
    piVar2 = (int *)FUN_404962c4(8);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2[1] = 1;
      *piVar2 = (int)&PTR_FUN_40481074;
    }
    if (piVar2 == (int *)0x0) {
      HVar3 = -0x7ff8fff2;
    }
    else {
      HVar3 = (**(code **)*piVar2)(piVar2,riid,ppv);
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  else {
    HVar3 = -0x7ffbfeef;
  }
  return HVar3;
}



/* 4048713c FUN_4048713c */

/* Boundary evidence: original MIPS .pdata 4048713c..4048717f. Semantic name remains unreviewed. */

void FUN_4048713c(void)

{
  if (DAT_404bd380 == 0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_404bd354);
  }
  DAT_404bd380 = DAT_404bd380 + 1;
  return;
}



/* 40487180 FUN_40487180 */

/* Boundary evidence: original MIPS .pdata 40487180..40487237. Semantic name remains unreviewed. */

bool FUN_40487180(undefined4 param_1)

{
  bool bVar1;
  
  DAT_404bd298 = param_1;
  DAT_404bd324 = HeapCreate(0,0x8000,0);
  bVar1 = DAT_404bd324 != (HANDLE)0x0;
  if (bVar1) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
    DAT_404bd2a0 = 1;
    FUN_4048713c();
  }
  return bVar1;
}



/* 40487238 FUN_40487238 */

/* Boundary evidence: original MIPS .pdata 40487238..40487243. Semantic name remains unreviewed. */

undefined4 FUN_40487238(void)

{
  return 1;
}



/* 40487244 FUN_40487244 */

/* Boundary evidence: original MIPS .pdata 40487244..404872d3. Semantic name remains unreviewed. */

void FUN_40487244(void)

{
  FUN_40487fa8(0xffffffff);
  FUN_4048a4f8();
  DAT_404bd380 = DAT_404bd380 + -1;
  if (DAT_404bd380 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_404bd354);
  }
  if (DAT_404bd2a0 != 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
    DAT_404bd2a0 = 0;
  }
  if (DAT_404bd324 != (HANDLE)0x0) {
    HeapDestroy(DAT_404bd324);
    DAT_404bd324 = (HANDLE)0x0;
  }
  return;
}



/* 404872d4 FUN_404872d4 */

/* Boundary evidence: original MIPS .pdata 404872d4..4048735f. Semantic name remains unreviewed. */

int FUN_404872d4(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_18 [2];
  
  BVar1 = IsBadReadPtr(param_2,4);
  if ((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_3,4), BVar1 == 0)) {
    iVar2 = FUN_4048ba3c(param_2,local_18);
    if (-1 < iVar2) {
      *param_3 = local_18[0];
    }
  }
  else {
    iVar2 = -0x7fffbffd;
  }
  return iVar2;
}



/* 40487360 FUN_40487360 */

/* Boundary evidence: original MIPS .pdata 40487360..404873eb. Semantic name remains unreviewed. */

DWORD FUN_40487360(undefined4 param_1,LPCWSTR param_2,undefined4 *param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 local_18 [2];
  
  BVar1 = IsBadReadPtr(param_2,4);
  if ((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_3,4), BVar1 == 0)) {
    DVar2 = FUN_4048baf0(param_2,local_18);
    if (-1 < (int)DVar2) {
      *param_3 = local_18[0];
    }
  }
  else {
    DVar2 = 0x80004003;
  }
  return DVar2;
}



/* 404873ec FUN_404873ec */

/* Boundary evidence: original MIPS .pdata 404873ec..404874af. Semantic name remains unreviewed. */

int FUN_404873ec(undefined4 param_1,int *param_2,uint param_3,uint param_4,uint param_5,int param_6,
                undefined4 *param_7)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_20 [2];
  
  BVar1 = IsBadReadPtr(param_2,4);
  if ((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_7,4), BVar1 == 0)) {
    iVar2 = FUN_4048e3bc(param_2,param_3,param_4,param_5,param_6,local_20,0,0);
    if (iVar2 < 0) {
      return iVar2;
    }
    *param_7 = local_20[0];
    return iVar2;
  }
  return -0x7fffbffd;
}



/* 404874b0 FUN_404874b0 */

/* Boundary evidence: original MIPS .pdata 404874b0..4048753f. Semantic name remains unreviewed. */

int FUN_404874b0(undefined4 param_1,int *param_2,uint param_3,undefined4 *param_4)

{
  BOOL BVar1;
  int iVar2;
  
  BVar1 = IsBadReadPtr(param_2,4);
  if ((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_4,4), BVar1 == 0)) {
    iVar2 = FUN_4048a094(param_2,param_4,param_3);
  }
  else {
    iVar2 = -0x7fffbffd;
  }
  return iVar2;
}



/* 40487540 FUN_40487540 */

/* Boundary evidence: original MIPS .pdata 40487540..40487567. Semantic name remains unreviewed. */

void FUN_40487540(undefined4 param_1,void *param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_4048a37c(param_2,param_3,param_4);
  return;
}



/* 40487568 FUN_40487568 */

/* Boundary evidence: original MIPS .pdata 40487568..4048763f. Semantic name remains unreviewed. */

DWORD FUN_40487568(int *param_1,undefined4 param_2,LPCWSTR param_3,LPVOID param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  int *local_20 [2];
  
  BVar1 = IsBadReadPtr(param_3,4);
  if ((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_4,4), BVar1 == 0)) {
    DVar2 = FUN_4048f7b4(param_3,local_20);
    if (-1 < (int)DVar2) {
      DVar2 = (**(code **)(*param_1 + 0x28))(param_1,param_2,local_20[0],param_4);
      (**(code **)(*local_20[0] + 8))();
    }
  }
  else {
    DVar2 = 0x80004003;
  }
  return DVar2;
}



/* 40487640 FUN_40487640 */

/* Boundary evidence: original MIPS .pdata 40487640..404876c7. Semantic name remains unreviewed. */

undefined4 FUN_40487640(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  BVar1 = IsBadWritePtr(param_2,4);
  if ((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_3,4), BVar1 == 0)) {
    uVar2 = FUN_404890c0(param_2,param_3,2);
  }
  else {
    uVar2 = 0x80004003;
  }
  return uVar2;
}



/* 404876c8 FUN_404876c8 */

/* Boundary evidence: original MIPS .pdata 404876c8..4048774f. Semantic name remains unreviewed. */

undefined4 FUN_404876c8(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  BVar1 = IsBadWritePtr(param_2,4);
  if ((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_3,4), BVar1 == 0)) {
    uVar2 = FUN_404890c0(param_2,param_3,1);
  }
  else {
    uVar2 = 0x80004003;
  }
  return uVar2;
}



/* 40487750 FUN_40487750 */

/* Boundary evidence: original MIPS .pdata 40487750..4048776b. Semantic name remains unreviewed. */

void FUN_40487750(undefined4 param_1,BYTE *param_2)

{
  FUN_404889a4(param_2);
  return;
}



/* 4048776c FUN_4048776c */

/* Boundary evidence: original MIPS .pdata 4048776c..4048778b. Semantic name remains unreviewed. */

void FUN_4048776c(undefined4 param_1,wchar_t *param_2,uint param_3)

{
  FUN_40488dcc(param_2,param_3);
  return;
}



/* 4048778c FUN_4048778c */

/* Boundary evidence: original MIPS .pdata 4048778c..40487827. Semantic name remains unreviewed. */

undefined4 FUN_4048778c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40482c64,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40481160,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 40487828 FUN_40487828 */

/* Boundary evidence: original MIPS .pdata 40487828..40487843. Semantic name remains unreviewed. */

void FUN_40487828(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 40487844 FUN_40487844 */

/* Boundary evidence: original MIPS .pdata 40487844..4048789f. Semantic name remains unreviewed. */

LONG FUN_40487844(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x38))(param_1,1);
  }
  return LVar1;
}



/* 404878a0 FUN_404878a0 */

/* Boundary evidence: original MIPS .pdata 404878a0..404878e3. Semantic name remains unreviewed. */

undefined4 * FUN_404878a0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40481124;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404878e4 FUN_404878e4 */

/* Boundary evidence: original MIPS .pdata 404878e4..404879db. Semantic name remains unreviewed. */

int FUN_404878e4(undefined4 param_1,uint param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  BOOL BVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  BVar1 = IsBadWritePtr(param_5,4);
  if (BVar1 == 0) {
    *param_5 = 0;
    puVar2 = (undefined4 *)FUN_404962c4(0xc0);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_4048e19c(puVar2);
    }
    if (piVar3 == (int *)0x0) {
      iVar4 = -0x7ff8fff2;
    }
    else {
      iVar4 = FUN_4048c7a0((int)piVar3,param_2,param_3,param_4,0);
      if (iVar4 < 0) {
        (**(code **)(*piVar3 + 0x24))(piVar3,1);
      }
      else {
        *param_5 = piVar3;
      }
    }
  }
  else {
    iVar4 = -0x7fffbffd;
  }
  return iVar4;
}



/* 404879dc FUN_404879dc */

/* Boundary evidence: original MIPS .pdata 404879dc..40487acb. Semantic name remains unreviewed. */

int FUN_404879dc(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  BOOL BVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  BVar1 = IsBadReadPtr(param_2,0x18);
  if ((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_3,4), BVar1 == 0)) {
    *param_3 = 0;
    puVar2 = (undefined4 *)FUN_404962c4(0xc0);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_4048e19c(puVar2);
    }
    if (piVar3 == (int *)0x0) {
      iVar4 = -0x7ff8fff2;
    }
    else {
      iVar4 = FUN_4048cba0((int)piVar3,param_2);
      if (iVar4 < 0) {
        (**(code **)(*piVar3 + 0x24))(piVar3,1);
      }
      else {
        *param_3 = piVar3;
      }
    }
  }
  else {
    iVar4 = -0x7fffbffd;
  }
  return iVar4;
}



/* 40487ad8 FUN_40487ad8 */

/* Boundary evidence: original MIPS .pdata 40487ad8..40487bbb. Semantic name remains unreviewed. */

void FUN_40487ad8(undefined4 *param_1)

{
  HLOCAL hMem;
  int iVar1;
  
  hMem = (HLOCAL)param_1[3];
  *param_1 = &PTR_FUN_40481170;
  if (hMem != (HLOCAL)0x0) {
    iVar1 = param_1[6];
    if (iVar1 == 1) {
      LocalFree(hMem);
    }
    else if (iVar1 == 2) {
      VirtualFree(hMem,0,0x8000);
    }
    else if (iVar1 == 3) {
      CoTaskMemFree(hMem);
    }
    else if (iVar1 == 4) {
      UnmapViewOfFile(hMem);
    }
  }
  if ((HANDLE)param_1[7] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)param_1[7]);
  }
  FUN_404962ec((LPVOID)param_1[8]);
  *param_1 = &PTR_FUN_40481124;
  return;
}



/* 40487bbc FUN_40487bbc */

/* Boundary evidence: original MIPS .pdata 40487bbc..40487c07. Semantic name remains unreviewed. */

undefined4 * FUN_40487bbc(undefined4 *param_1,uint param_2)

{
  FUN_40487ad8(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 40487c08 FUN_40487c08 */

/* Boundary evidence: original MIPS .pdata 40487c08..40487dbf. Semantic name remains unreviewed. */

int FUN_40487c08(undefined4 param_1,void *param_2,int param_3,int param_4,LPVOID param_5)

{
  BOOL BVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *local_28 [2];
  
  iVar4 = 4;
  BVar1 = IsBadReadPtr(param_2,4);
  if ((BVar1 != 0) || (BVar1 = IsBadWritePtr(param_5,4), BVar1 != 0)) {
    return -0x7fffbffd;
  }
  if (param_4 == 0) {
    iVar4 = 0;
  }
  else if (param_4 == 1) {
    iVar4 = 1;
  }
  else if (param_4 == 2) {
    iVar4 = 3;
  }
  else if (param_4 != 3) {
    return -0x7ff8ffa9;
  }
  piVar2 = (int *)FUN_404962c4(0x24);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[1] = 1;
    *piVar2 = (int)&PTR_FUN_40481170;
    piVar2[2] = -1;
    piVar2[3] = 0;
    piVar2[5] = 0;
    piVar2[4] = 0;
    piVar2[6] = 0;
    piVar2[7] = -1;
    piVar2[8] = 0;
  }
  if (piVar2 == (int *)0x0) {
    return -0x7ff8fff2;
  }
  piVar2[3] = (int)param_2;
  piVar2[4] = param_3;
  piVar2[5] = 0;
  piVar2[6] = 0;
  iVar3 = FUN_4048ba3c(piVar2,local_28);
  if (-1 < iVar3) {
    piVar2[6] = iVar4;
    iVar3 = (**(code **)*local_28[0])(local_28[0],&DAT_4048129c,param_5);
    (**(code **)(*local_28[0] + 8))();
  }
  (**(code **)(*piVar2 + 8))(piVar2);
  return iVar3;
}



/* 40487dc0 FUN_40487dc0 */

/* Boundary evidence: original MIPS .pdata 40487dc0..40487e1b. Semantic name remains unreviewed. */

void FUN_40487dc0(LPVOID param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = *(LPVOID *)((int)param_1 + 0x4c);
  if (param_1 == DAT_404bd2bc) {
    DAT_404bd2bc = pvVar1;
  }
  if (pvVar1 != (LPVOID)0x0) {
    *(undefined4 *)((int)pvVar1 + 0x50) = *(undefined4 *)((int)param_1 + 0x50);
  }
  if (*(int *)((int)param_1 + 0x50) != 0) {
    *(LPVOID *)(*(int *)((int)param_1 + 0x50) + 0x4c) = pvVar1;
  }
  FUN_404962ec(param_1);
  DAT_404bd2c0 = 1;
  return;
}



/* 40487e1c FUN_40487e1c */

/* Boundary evidence: original MIPS .pdata 40487e1c..40487edf. Semantic name remains unreviewed. */

int FUN_40487e1c(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int local_28 [2];
  
  *param_4 = 0;
  iVar1 = 0;
  while( true ) {
    if (param_3 == 0) {
      return iVar1;
    }
    local_28[0] = 0;
    iVar1 = (**(code **)(*param_1 + 0xc))(param_1,param_2,param_3,local_28);
    *param_4 = *param_4 + local_28[0];
    if (iVar1 != -0x7ffffff6) break;
    param_3 = param_3 - local_28[0];
    param_2 = local_28[0] + param_2;
    Sleep(0);
    iVar1 = -0x7ffffff6;
  }
  return iVar1;
}



/* 40487ee0 FUN_40487ee0 */

/* Boundary evidence: original MIPS .pdata 40487ee0..40487fa7. Semantic name remains unreviewed. */

void FUN_40487ee0(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_2,param_2,param_2 >> 0x1f,1,param_3);
  while (iVar1 == -0x7ffffff6) {
    Sleep(0);
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  return;
}



/* 40487fa8 FUN_40487fa8 */

/* Boundary evidence: original MIPS .pdata 40487fa8..40487fff. Semantic name remains unreviewed. */

void FUN_40487fa8(uint param_1)

{
  LPVOID pvVar1;
  LPVOID pvVar2;
  
  pvVar2 = DAT_404bd2bc;
  while (pvVar1 = pvVar2, pvVar1 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((int)pvVar1 + 0x4c);
    if ((*(uint *)((int)pvVar1 + 0x34) & param_1) != 0) {
      FUN_40487dc0(pvVar1);
    }
  }
  return;
}



/* 40488000 FUN_40488000 */

/* Boundary evidence: original MIPS .pdata 40488000..4048832b. Semantic name remains unreviewed. */

void FUN_40488000(void)

{
  size_t _Size;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *_Dst;
  void *pvVar5;
  int *piVar6;
  size_t _Size_00;
  size_t _Size_01;
  size_t _Size_02;
  size_t _Size_03;
  WCHAR aWStack_850 [260];
  WCHAR aWStack_648 [260];
  WCHAR aWStack_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_404bd274;
  DAT_404bd2d4 = FUN_404a1fcc();
  DAT_404bd2d8 = FUN_4049d180();
  DAT_404bd2dc = FUN_404996d8();
  DAT_404bd2e0 = FUN_404a3c98();
  DAT_404bd2e4 = FUN_404964f0();
  DAT_404bd2e8 = FUN_404a3c98();
  piVar6 = &DAT_404bd2ec;
  do {
    piVar6 = piVar6 + -1;
    if ((*piVar6 != 0) &&
       (iVar1 = FUN_40490194(DAT_404bd328,*(UINT *)(*piVar6 + 8),aWStack_440,0x104), 0 < iVar1)) {
      _Size_02 = (iVar1 + 1) * 2;
      iVar1 = FUN_40490194(DAT_404bd328,*(UINT *)(*piVar6 + 0xc),aWStack_850,0x104);
      if (0 < iVar1) {
        _Size_01 = (iVar1 + 1) * 2;
        iVar1 = FUN_40490194(DAT_404bd328,*(UINT *)(*piVar6 + 0x10),aWStack_648,0x104);
        if (0 < iVar1) {
          _Size_00 = (iVar1 + 1) * 2;
          iVar1 = FUN_40490194(DAT_404bd328,*(UINT *)(*piVar6 + 0x14),aWStack_238,0x104);
          if (0 < iVar1) {
            _Size = *(int *)(*piVar6 + 0x24) * *(int *)(*piVar6 + 0x20);
            _Size_03 = (iVar1 + 1) * 2;
            uVar4 = _Size * 2 + _Size_03 + _Size_00 + _Size_01 + _Size_02 + 0x6b & 0xfffffff0;
            puVar2 = (undefined4 *)FUN_404962c4(uVar4);
            if (puVar2 != (undefined4 *)0x0) {
              puVar2[0x15] = uVar4;
              _Dst = puVar2 + 0x17;
              puVar3 = *(undefined4 **)*piVar6;
              *puVar2 = *puVar3;
              puVar2[1] = puVar3[1];
              puVar2[2] = puVar3[2];
              puVar2[3] = puVar3[3];
              puVar3 = *(undefined4 **)(*piVar6 + 4);
              puVar2[4] = *puVar3;
              puVar2[5] = puVar3[1];
              puVar2[6] = puVar3[2];
              puVar2[7] = puVar3[3];
              puVar2[8] = _Dst;
              memcpy(_Dst,aWStack_440,_Size_02);
              pvVar5 = (void *)((int)_Dst + _Size_02);
              puVar2[10] = pvVar5;
              memcpy(pvVar5,aWStack_850,_Size_01);
              pvVar5 = (void *)((int)pvVar5 + _Size_01);
              puVar2[0xb] = pvVar5;
              memcpy(pvVar5,aWStack_648,_Size_00);
              pvVar5 = (void *)((int)pvVar5 + _Size_00);
              puVar2[0xc] = pvVar5;
              memcpy(pvVar5,aWStack_238,_Size_03);
              pvVar5 = (void *)((int)pvVar5 + _Size_03);
              puVar2[9] = 0;
              puVar2[0xd] = *(uint *)(*piVar6 + 0x1c) | 0x10000;
              puVar2[0xe] = *(undefined4 *)(*piVar6 + 0x18);
              puVar2[0x16] = *(undefined4 *)(*piVar6 + 0x30);
              puVar2[0xf] = *(undefined4 *)(*piVar6 + 0x20);
              puVar2[0x10] = *(undefined4 *)(*piVar6 + 0x24);
              if (_Size == 0) {
                puVar2[0x12] = 0;
                puVar2[0x11] = 0;
              }
              else {
                puVar2[0x11] = pvVar5;
                memcpy(pvVar5,*(void **)(*piVar6 + 0x28),_Size);
                puVar2[0x12] = (void *)((int)pvVar5 + _Size);
                memcpy((void *)((int)pvVar5 + _Size),*(void **)(*piVar6 + 0x2c),_Size);
              }
              puVar2[0x14] = 0;
              puVar2[0x13] = DAT_404bd2bc;
              if (DAT_404bd2bc != (undefined4 *)0x0) {
                DAT_404bd2bc[0x14] = puVar2;
              }
              DAT_404bd2c0 = 1;
              DAT_404bd2bc = puVar2;
            }
          }
        }
      }
    }
  } while (piVar6 != &DAT_404bd2d4);
  FUN_404a438c(local_30);
  return;
}



/* 4048832c FUN_4048832c */

/* Boundary evidence: original MIPS .pdata 4048832c..4048866f. Semantic name remains unreviewed. */

undefined4 FUN_4048832c(short *param_1,HKEY param_2,LPBYTE param_3,int param_4)

{
  int iVar1;
  LSTATUS LVar2;
  uint uVar3;
  LPBYTE _Dst;
  short *psVar4;
  uint uVar5;
  
  memset(param_3,0,0x5c);
  *(int *)(param_3 + 0x54) = param_4;
  _Dst = param_3 + 0x5c;
  iVar1 = FUN_404963e4(param_1);
  uVar3 = (iVar1 + 1) * 2;
  if (uVar3 <= param_4 - 0x5cU) {
    memcpy(_Dst,param_1,uVar3);
    *(LPBYTE *)(param_3 + 0x20) = _Dst;
    uVar5 = (param_4 - 0x5cU) + (iVar1 + 1) * -2;
    psVar4 = (short *)(_Dst + uVar3);
    LVar2 = FUN_404900d4(param_2,L"CLSID",param_3,0x10);
    if ((LVar2 == 0) && (LVar2 = FUN_404900d4(param_2,L"Format ID",param_3 + 0x10,0x10), LVar2 == 0)
       ) {
      LVar2 = FUN_4049006c(param_2,L"Version",param_3 + 0x38);
      if (LVar2 == 0) {
        LVar2 = FUN_4049006c(param_2,L"Flags",param_3 + 0x34);
        if ((LVar2 == 0) && (*(int *)(param_3 + 0x38) == 1)) {
          param_3[0x36] = '\0';
          param_3[0x37] = '\0';
          LVar2 = FUN_40490140(param_2,L"DLLNAME",(LPBYTE)psVar4,uVar5);
          if (LVar2 == 0) {
            *(short **)(param_3 + 0x24) = psVar4;
            iVar1 = FUN_404963e4(psVar4);
            iVar1 = iVar1 + 1;
            if ((uint)(iVar1 * 2) <= uVar5) {
              psVar4 = psVar4 + iVar1;
              uVar5 = uVar5 + iVar1 * -2;
              LVar2 = FUN_40490140(param_2,L"File Type Description",(LPBYTE)psVar4,uVar5);
              if (LVar2 == 0) {
                *(short **)(param_3 + 0x28) = psVar4;
                iVar1 = FUN_404963e4(psVar4);
                iVar1 = iVar1 + 1;
                if ((uint)(iVar1 * 2) <= uVar5) {
                  psVar4 = psVar4 + iVar1;
                  uVar5 = uVar5 + iVar1 * -2;
                  LVar2 = FUN_40490140(param_2,L"Filename Extension",(LPBYTE)psVar4,uVar5);
                  if (LVar2 == 0) {
                    *(short **)(param_3 + 0x2c) = psVar4;
                    iVar1 = FUN_404963e4(psVar4);
                    iVar1 = iVar1 + 1;
                    if ((uint)(iVar1 * 2) <= uVar5) {
                      psVar4 = psVar4 + iVar1;
                      uVar5 = uVar5 + iVar1 * -2;
                      LVar2 = FUN_40490140(param_2,L"MIME Type",(LPBYTE)psVar4,uVar5);
                      if (LVar2 == 0) {
                        *(short **)(param_3 + 0x30) = psVar4;
                        iVar1 = FUN_404963e4(psVar4);
                        iVar1 = iVar1 + 1;
                        if ((uint)(iVar1 * 2) <= uVar5) {
                          psVar4 = psVar4 + iVar1;
                          uVar5 = uVar5 + iVar1 * -2;
                          if ((*(uint *)(param_3 + 0x34) & 2) == 0) {
                            return 1;
                          }
                          LVar2 = FUN_4049006c(param_2,L"Signature Count",param_3 + 0x3c);
                          if (LVar2 == 0) {
                            LVar2 = FUN_4049006c(param_2,L"Signature Size",param_3 + 0x40);
                            if ((((LVar2 == 0) &&
                                 (uVar3 = *(int *)(param_3 + 0x40) * *(int *)(param_3 + 0x3c),
                                 uVar3 != 0)) && (uVar3 * 2 <= uVar5)) &&
                               ((LVar2 = FUN_404900d4(param_2,L"Signature Pattern",(LPBYTE)psVar4,
                                                      uVar3), LVar2 == 0 &&
                                (*(short **)(param_3 + 0x44) = psVar4, uVar3 <= uVar5)))) {
                              LVar2 = FUN_404900d4(param_2,L"Signature Mask",
                                                   (LPBYTE)(uVar3 + (int)psVar4),uVar3);
                              if ((LVar2 == 0) &&
                                 (*(short **)(param_3 + 0x48) = (short *)(uVar3 + (int)psVar4),
                                 uVar3 <= uVar5 - uVar3)) {
                                return 1;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



/* 40488670 FUN_40488670 */

/* Boundary evidence: original MIPS .pdata 40488670..4048887b. Semantic name remains unreviewed. */

void FUN_40488670(HKEY param_1,LPCWSTR param_2,int *param_3,uint param_4)

{
  int iVar1;
  LSTATUS LVar2;
  LPBYTE pBVar3;
  DWORD DVar4;
  HKEY local_248;
  HKEY local_244;
  int local_240;
  uint local_23c;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_404bd274;
  iVar1 = FUN_4048ff28(param_1,param_2,0x20019,&local_248);
  if (iVar1 == 0) {
    LVar2 = FUN_4049006c(local_248,L"_LastCookie",(LPBYTE)&local_240);
    if (LVar2 != 0) {
      local_240 = 0;
    }
    if (local_240 == *param_3) {
      RegCloseKey(local_248);
    }
    else {
      *param_3 = local_240;
      DVar4 = 0;
      iVar1 = FUN_4048ff54(local_248,0,aWStack_238);
      while (iVar1 == 0) {
        DVar4 = DVar4 + 1;
        iVar1 = FUN_4048ff28(local_248,aWStack_238,0x20019,&local_244);
        if (iVar1 == 0) {
          pBVar3 = (LPBYTE)0x0;
          LVar2 = FUN_4049006c(local_244,L"_InfoSize",(LPBYTE)&local_23c);
          if ((((LVar2 == 0) && (0x5c < local_23c)) && (local_23c == (local_23c + 0xf & 0xfffffff0))
              ) && ((pBVar3 = (LPBYTE)FUN_404962c4(local_23c), pBVar3 != (LPBYTE)0x0 &&
                    (iVar1 = FUN_4048832c(aWStack_238,local_244,pBVar3,local_23c), iVar1 != 0)))) {
            pBVar3[0x50] = '\0';
            pBVar3[0x51] = '\0';
            pBVar3[0x52] = '\0';
            pBVar3[0x53] = '\0';
            *(uint *)(pBVar3 + 0x34) = param_4 | *(uint *)(pBVar3 + 0x34);
            *(LPBYTE *)(pBVar3 + 0x4c) = DAT_404bd2bc;
            if (DAT_404bd2bc != (LPBYTE)0x0) {
              *(LPBYTE *)(DAT_404bd2bc + 0x50) = pBVar3;
            }
            DAT_404bd2c0 = 1;
            DAT_404bd2bc = pBVar3;
          }
          else {
            FUN_404962ec(pBVar3);
          }
          RegCloseKey(local_244);
        }
        iVar1 = FUN_4048ff54(local_248,DVar4,aWStack_238);
      }
      RegCloseKey(local_248);
    }
  }
  FUN_404a438c(local_30);
  return;
}



/* 4048887c FUN_4048887c */

/* Boundary evidence: original MIPS .pdata 4048887c..404889a3. Semantic name remains unreviewed. */

void FUN_4048887c(void)

{
  DWORD DVar1;
  int iVar2;
  
  DAT_404bd2c0 = 0;
  if (DAT_404bd2bc == 0) {
    FUN_40488000();
  }
  else {
    DVar1 = GetTickCount();
    if (DVar1 - DAT_404bd2d0 < 30000) {
      return;
    }
  }
  if (DAT_404bd298 == 0) {
    FUN_40488670((HKEY)0x80000002,L"Software\\Microsoft\\Imaging\\Codecs",(int *)&DAT_404bd2cc,
                 0x20000);
    FUN_40488670((HKEY)0x80000001,L"Software\\Microsoft\\Imaging\\Codecs",(int *)&DAT_404bd2c8,
                 0x40000);
  }
  if (DAT_404bd2c0 != 0) {
    DAT_404bd2c4 = 0;
    for (iVar2 = DAT_404bd2bc; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
      if (DAT_404bd2c4 < *(uint *)(iVar2 + 0x40)) {
        DAT_404bd2c4 = *(uint *)(iVar2 + 0x40);
      }
    }
    DAT_404bd2c0 = 0;
  }
  DAT_404bd2d0 = GetTickCount();
  return;
}



/* 404889a4 FUN_404889a4 */

/* Boundary evidence: original MIPS .pdata 404889a4..40488dcb. Semantic name remains unreviewed. */

uint FUN_404889a4(BYTE *param_1)

{
  LSTATUS LVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  DWORD DVar7;
  HKEY pHVar8;
  uint uVar9;
  HKEY local_28;
  HKEY local_24;
  int local_20 [2];
  
  if (((((param_1 != (BYTE *)0x0) && (*(int *)(param_1 + 0x20) != 0)) &&
       (*(int *)(param_1 + 0x24) != 0)) &&
      ((*(int *)(param_1 + 0x38) != 0 && (*(int *)(param_1 + 0x28) != 0)))) &&
     ((*(int *)(param_1 + 0x2c) != 0 && (*(int *)(param_1 + 0x30) != 0)))) {
    uVar9 = *(uint *)(param_1 + 0x34);
    DVar7 = *(int *)(param_1 + 0x3c) * *(int *)(param_1 + 0x40);
    if ((uVar9 & 0x70000) == 0x20000) {
      pHVar8 = (HKEY)0x80000002;
    }
    else {
      if ((uVar9 & 0x70000) != 0x40000) {
        return 0x80070057;
      }
      pHVar8 = (HKEY)0x80000001;
    }
    if ((((uVar9 & 3) != 0) && (((uVar9 & 2) == 0 || (DVar7 != 0)))) &&
       ((DVar7 == 0 || ((*(int *)(param_1 + 0x44) != 0 && (*(int *)(param_1 + 0x48) != 0)))))) {
      local_24 = (HKEY)0x0;
      local_28 = (HKEY)0x0;
      uVar9 = FUN_4048fee8(pHVar8,L"Software\\Microsoft\\Imaging\\Codecs",0xf003f,&local_24);
      if (uVar9 == 0) {
        LVar1 = FUN_4049006c(local_24,L"_LastCookie",(LPBYTE)local_20);
        iVar2 = 0;
        if (LVar1 == 0) {
          iVar2 = local_20[0];
        }
        local_20[0] = iVar2 + 1;
        uVar9 = FUN_40490000(local_24,L"_LastCookie",local_20[0]);
        if ((uVar9 == 0) &&
           (uVar9 = FUN_4048fee8(local_24,*(LPCWSTR *)(param_1 + 0x20),0xf003f,&local_28),
           uVar9 == 0)) {
          iVar2 = FUN_404963e4(*(short **)(param_1 + 0x30));
          iVar3 = FUN_404963e4(*(short **)(param_1 + 0x2c));
          iVar4 = FUN_404963e4(*(short **)(param_1 + 0x28));
          iVar5 = FUN_404963e4(*(short **)(param_1 + 0x24));
          iVar6 = FUN_404963e4(*(short **)(param_1 + 0x20));
          uVar9 = FUN_40490000(local_28,L"_InfoSize",
                               (iVar6 + iVar5 + iVar4 + iVar2 + iVar3 + DVar7) * 2 + 0x75 &
                               0xfffffff0);
          if (((((uVar9 == 0) &&
                (((uVar9 = FUN_40490000(local_28,L"Version",*(undefined4 *)(param_1 + 0x38)),
                  uVar9 == 0 &&
                  (uVar9 = FUN_40490000(local_28,L"Flags",*(undefined4 *)(param_1 + 0x34)),
                  uVar9 == 0)) && (uVar9 = FUN_4049003c(local_28,L"CLSID",param_1,0x10), uVar9 == 0)
                 ))) && (uVar9 = FUN_4049003c(local_28,L"Format ID",param_1 + 0x10,0x10), uVar9 == 0
                        )) &&
              ((DVar7 == 0 ||
               (((uVar9 = FUN_40490000(local_28,L"Signature Count",*(undefined4 *)(param_1 + 0x3c)),
                 uVar9 == 0 &&
                 (uVar9 = FUN_40490000(local_28,L"Signature Size",*(undefined4 *)(param_1 + 0x40)),
                 uVar9 == 0)) &&
                ((uVar9 = FUN_4049003c(local_28,L"Signature Pattern",*(BYTE **)(param_1 + 0x44),
                                       DVar7), uVar9 == 0 &&
                 (uVar9 = FUN_4049003c(local_28,L"Signature Mask",*(BYTE **)(param_1 + 0x48),DVar7),
                 uVar9 == 0)))))))) &&
             ((((uVar9 = FUN_4048ff94(local_28,L"DLLNAME",*(short **)(param_1 + 0x24)), uVar9 == 0
                && (uVar9 = FUN_4048ff94(local_28,L"File Type Description",
                                         *(short **)(param_1 + 0x28)), uVar9 == 0)) &&
               (uVar9 = FUN_4048ff94(local_28,L"Filename Extension",*(short **)(param_1 + 0x2c)),
               uVar9 == 0)) &&
              (uVar9 = FUN_4048ff94(local_28,L"MIME Type",*(short **)(param_1 + 0x30)), uVar9 == 0))
             )) {
            DVar7 = GetTickCount();
            DAT_404bd2d0 = DVar7 - 30000;
          }
        }
      }
      if (local_28 != (HKEY)0x0) {
        RegCloseKey(local_28);
      }
      if (local_24 != (HKEY)0x0) {
        RegCloseKey(local_24);
      }
      if (uVar9 != 0) {
        if (0 < (int)uVar9) {
          return uVar9 & 0xffff | 0x80070000;
        }
        return uVar9;
      }
      return 0;
    }
  }
  return 0x80070057;
}



/* 40488dcc FUN_40488dcc */

/* Boundary evidence: original MIPS .pdata 40488dcc..40488f6b. Semantic name remains unreviewed. */

uint FUN_40488dcc(wchar_t *param_1,uint param_2)

{
  LPVOID pvVar1;
  uint uVar2;
  LSTATUS LVar3;
  int iVar4;
  DWORD DVar5;
  HKEY pHVar6;
  LPVOID pvVar7;
  HKEY local_28;
  int local_24;
  
  if (param_1 == (wchar_t *)0x0) {
LAB_40488f3c:
    uVar2 = 0x80070057;
  }
  else {
    if (param_2 == 0x40000) {
      pHVar6 = (HKEY)0x80000001;
    }
    else {
      if (param_2 != 0x20000) goto LAB_40488f3c;
      pHVar6 = (HKEY)0x80000002;
    }
    uVar2 = FUN_4048ff28(pHVar6,L"Software\\Microsoft\\Imaging\\Codecs",0xf003f,&local_28);
    if (uVar2 == 0) {
      LVar3 = FUN_4049006c(local_28,L"_LastCookie",(LPBYTE)&local_24);
      iVar4 = 0;
      if (LVar3 == 0) {
        iVar4 = local_24;
      }
      local_24 = iVar4 + 1;
      uVar2 = FUN_40490000(local_28,L"_LastCookie",local_24);
      pvVar7 = DAT_404bd2bc;
      if (uVar2 == 0) {
        while (pvVar1 = pvVar7, pvVar1 != (LPVOID)0x0) {
          pvVar7 = *(LPVOID *)((int)pvVar1 + 0x4c);
          iVar4 = wcscmp(*(wchar_t **)((int)pvVar1 + 0x20),param_1);
          if ((iVar4 == 0) &&
             (((*(uint *)((int)pvVar1 + 0x34) & 0x20000) == param_2 ||
              ((*(uint *)((int)pvVar1 + 0x34) & 0x40000) == param_2)))) {
            FUN_40487dc0(pvVar1);
          }
        }
        uVar2 = FUN_40490384(local_28,param_1);
        DVar5 = GetTickCount();
        DAT_404bd2d0 = DVar5 - 30000;
      }
      RegCloseKey(local_28);
      if (uVar2 == 0) {
        return 0;
      }
    }
    if (0 < (int)uVar2) {
      uVar2 = uVar2 & 0xffff | 0x80070000;
    }
  }
  return uVar2;
}



/* 40488f6c FUN_40488f6c */

/* Boundary evidence: original MIPS .pdata 40488f6c..4048903b. Semantic name remains unreviewed. */

int FUN_40488f6c(byte *param_1,uint param_2,uint param_3)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = DAT_404bd2bc;
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if ((((*(uint *)(iVar1 + 0x34) & 2) != 0) && ((*(uint *)(iVar1 + 0x34) & param_3) == param_3))
       && (uVar3 = *(uint *)(iVar1 + 0x40), uVar3 <= param_2)) {
      iVar6 = *(int *)(iVar1 + 0x44);
      iVar4 = *(int *)(iVar1 + 0x3c);
      iVar7 = *(int *)(iVar1 + 0x48);
      while (iVar4 != 0) {
        iVar4 = iVar4 + -1;
        uVar5 = 0;
        if (uVar3 != 0) {
          pbVar2 = param_1;
          do {
            if ((pbVar2[iVar7 - (int)param_1] & *pbVar2) != pbVar2[iVar6 - (int)param_1]) break;
            uVar5 = uVar5 + 1;
            pbVar2 = pbVar2 + 1;
          } while (uVar5 < uVar3);
        }
        if (uVar5 == uVar3) {
          return iVar1;
        }
        iVar6 = *(int *)(iVar1 + 0x40) + iVar6;
        iVar7 = *(int *)(iVar1 + 0x40) + iVar7;
      }
    }
    iVar1 = *(int *)(iVar1 + 0x4c);
  } while( true );
}



/* 4048903c FUN_4048903c */

/* Boundary evidence: original MIPS .pdata 4048903c..404890bf. Semantic name remains unreviewed. */

undefined4 FUN_4048903c(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((uint)param_1[1] < param_2) {
    if (param_1[2] != 0) {
      FUN_404962ec((LPVOID)*param_1);
    }
    uVar2 = 1;
    param_1[2] = 1;
    param_1[1] = param_2;
    iVar1 = FUN_404962c4(param_2);
    *param_1 = iVar1;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 404890c0 FUN_404890c0 */

/* Boundary evidence: original MIPS .pdata 404890c0..4048931f. Semantic name remains unreviewed. */

undefined4 FUN_404890c0(int *param_1,undefined4 *param_2,uint param_3)

{
  SIZE_T cb;
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  size_t _Size;
  void *pvVar5;
  void *_Src;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
  FUN_4048887c();
  cb = 0;
  iVar2 = 0;
  for (pvVar1 = DAT_404bd2bc; pvVar1 != (void *)0x0; pvVar1 = *(void **)((int)pvVar1 + 0x4c)) {
    if ((*(uint *)((int)pvVar1 + 0x34) & param_3) != 0) {
      iVar2 = iVar2 + 1;
      cb = *(int *)((int)pvVar1 + 0x54) + cb;
    }
  }
  *param_1 = 0;
  *param_2 = 0;
  if (iVar2 == 0) {
    uVar3 = 0x887b0006;
  }
  else {
    pvVar1 = CoTaskMemAlloc(cb);
    if (pvVar1 == (LPVOID)0x0) {
      uVar3 = 0x8007000e;
    }
    else {
      *param_1 = iVar2;
      *param_2 = pvVar1;
      pvVar5 = (void *)(iVar2 * 0x4c + (int)pvVar1);
      for (_Src = DAT_404bd2bc; _Src != (void *)0x0; _Src = *(void **)((int)_Src + 0x4c)) {
        if ((*(uint *)((int)_Src + 0x34) & param_3) != 0) {
          memcpy(pvVar1,_Src,0x4c);
          *(void **)((int)pvVar1 + 0x20) = pvVar5;
          iVar2 = FUN_404963e4(*(short **)((int)_Src + 0x20));
          sVar4 = (iVar2 + 1) * 2;
          memcpy(pvVar5,*(void **)((int)_Src + 0x20),sVar4);
          pvVar5 = (void *)((int)pvVar5 + sVar4);
          if (*(int *)((int)_Src + 0x24) != 0) {
            *(void **)((int)pvVar1 + 0x24) = pvVar5;
            iVar2 = FUN_404963e4(*(short **)((int)_Src + 0x24));
            sVar4 = (iVar2 + 1) * 2;
            memcpy(pvVar5,*(void **)((int)_Src + 0x24),sVar4);
            pvVar5 = (void *)((int)pvVar5 + sVar4);
          }
          *(void **)((int)pvVar1 + 0x28) = pvVar5;
          iVar2 = FUN_404963e4(*(short **)((int)_Src + 0x28));
          sVar4 = (iVar2 + 1) * 2;
          memcpy(pvVar5,*(void **)((int)_Src + 0x28),sVar4);
          pvVar5 = (void *)((int)pvVar5 + sVar4);
          *(void **)((int)pvVar1 + 0x2c) = pvVar5;
          iVar2 = FUN_404963e4(*(short **)((int)_Src + 0x2c));
          sVar4 = (iVar2 + 1) * 2;
          memcpy(pvVar5,*(void **)((int)_Src + 0x2c),sVar4);
          pvVar5 = (void *)((int)pvVar5 + sVar4);
          *(void **)((int)pvVar1 + 0x30) = pvVar5;
          iVar2 = FUN_404963e4(*(short **)((int)_Src + 0x30));
          _Size = (iVar2 + 1) * 2;
          memcpy(pvVar5,*(void **)((int)_Src + 0x30),_Size);
          sVar4 = *(int *)((int)_Src + 0x40) * *(int *)((int)_Src + 0x3c);
          pvVar5 = (void *)((int)pvVar5 + _Size);
          if (sVar4 != 0) {
            *(void **)((int)pvVar1 + 0x44) = pvVar5;
            memcpy(pvVar5,*(void **)((int)_Src + 0x44),sVar4);
            pvVar5 = (void *)((int)pvVar5 + sVar4);
            *(void **)((int)pvVar1 + 0x48) = pvVar5;
            memcpy(pvVar5,*(void **)((int)_Src + 0x48),sVar4);
            pvVar5 = (void *)((int)pvVar5 + sVar4);
          }
          pvVar1 = (void *)((int)pvVar1 + 0x4c);
        }
      }
      uVar3 = 0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
  return uVar3;
}



/* 40489320 FUN_40489320 */

/* Boundary evidence: original MIPS .pdata 40489320..40489407. Semantic name remains unreviewed. */

undefined4 FUN_40489320(undefined4 *param_1,uint param_2)

{
  void *_Dst;
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1[0xb];
  if (uVar1 < param_2) {
    uVar1 = (uVar1 >> 1) + uVar1;
    if (uVar1 < param_2) {
      uVar1 = param_2;
    }
    iVar2 = uVar1 * 2;
    _Dst = (void *)FUN_404962c4(iVar2 + 2);
    if (_Dst == (void *)0x0) {
      iVar2 = param_2 * 2;
      _Dst = (void *)FUN_404962c4(iVar2 + 2);
      uVar1 = param_2;
      if (_Dst == (void *)0x0) {
        return 0;
      }
    }
    memmove(_Dst,(void *)*param_1,param_1[0xb] << 1);
    if (param_1[0xb] != 0x10) {
      FUN_404962ec((LPVOID)*param_1);
    }
    *param_1 = _Dst;
    param_1[0xb] = uVar1;
    *(undefined2 *)(iVar2 + (int)_Dst) = 0;
  }
  return 1;
}



/* 40489408 FUN_40489408 */

/* Boundary evidence: original MIPS .pdata 40489408..40489467. Semantic name remains unreviewed. */

undefined * FUN_40489408(void)

{
  if ((DAT_404bd318 & 1) == 0) {
    DAT_404bd318 = DAT_404bd318 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_404bd304);
    FUN_404a4618(FUN_404bc5f0);
  }
  return &DAT_404bd304;
}



/* 40489468 FUN_40489468 */

/* Boundary evidence: original MIPS .pdata 40489468..404894cf. Semantic name remains unreviewed. */

int FUN_40489468(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_404962c4(0x3c);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    *(int *)(iVar1 + 0x34) = param_2;
    *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(param_2 + 0x38);
    *(int *)(*(int *)(param_2 + 0x38) + 0x34) = iVar1;
    *(int *)(param_2 + 0x38) = iVar1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  return iVar1;
}



/* 404894d0 FUN_404894d0 */

/* Boundary evidence: original MIPS .pdata 404894d0..404896db. Semantic name remains unreviewed. */

undefined4 FUN_404894d0(uint *param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  uVar7 = (int)(param_1[1] - *param_1) >> 3;
  if (((int)(param_1[2] - *param_1) >> 3) - uVar7 < param_3) {
    if (((param_3 <= param_3 + 10) && (uVar4 = uVar7 + param_3 + 10, uVar4 < 0x20000000)) &&
       (uVar7 <= uVar4)) {
      puVar2 = (undefined4 *)FUN_404962c4(uVar4 * 8);
      if (puVar2 != (undefined4 *)0x0) {
        puVar8 = puVar2;
        for (puVar5 = (undefined4 *)*param_1; puVar5 != param_2; puVar5 = puVar5 + 2) {
          if (puVar8 != (undefined4 *)0x0) {
            *puVar8 = *puVar5;
            puVar8[1] = puVar5[1];
          }
          puVar8 = puVar8 + 2;
        }
        for (; param_3 != 0; param_3 = param_3 - 1) {
          if (puVar8 != (undefined4 *)0x0) {
            *puVar8 = *param_4;
            puVar8[1] = param_4[1];
          }
          puVar8 = puVar8 + 2;
        }
        puVar5 = (undefined4 *)param_1[1];
        if (param_2 != puVar5) {
          iVar6 = (int)param_2 - (int)puVar8;
          do {
            if (puVar8 != (undefined4 *)0x0) {
              puVar3 = (undefined4 *)(iVar6 + (int)puVar8);
              *puVar8 = *puVar3;
              puVar8[1] = puVar3[1];
            }
            puVar8 = puVar8 + 2;
          } while ((undefined4 *)(iVar6 + (int)puVar8) != puVar5);
        }
        FUN_404962ec((LPVOID)*param_1);
        *param_1 = (uint)puVar2;
        param_1[1] = (uint)puVar8;
        param_1[2] = (uint)(puVar2 + uVar4 * 2);
        goto LAB_404896b0;
      }
    }
    uVar1 = 0;
  }
  else {
    puVar2 = (undefined4 *)(param_1[1] - 8);
    puVar5 = param_2 + (((int)puVar2 - (int)param_2 >> 3) + param_3) * 2;
    for (; param_2 <= puVar2; puVar2 = puVar2 + -2) {
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = *puVar2;
        puVar5[1] = puVar2[1];
      }
      puVar5 = puVar5 + -2;
    }
    for (; param_3 != 0; param_3 = param_3 - 1) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *param_4;
        param_2[1] = param_4[1];
      }
      param_1[1] = param_1[1] + 8;
      param_2 = param_2 + 2;
    }
LAB_404896b0:
    uVar1 = 1;
  }
  return uVar1;
}



/* 404896dc FUN_404896dc */

int FUN_404896dc(int param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  
  uVar1 = param_2[10];
  uVar5 = 0;
  iVar3 = uVar1 / 0xf + 1;
  uVar2 = 0;
  if (uVar1 != 0) {
    puVar4 = (ushort *)*param_2;
    uVar2 = uVar1;
    do {
      uVar5 = iVar3 + uVar5;
      uVar2 = *puVar4 + uVar2;
      puVar4 = puVar4 + iVar3;
    } while (uVar5 < uVar1);
  }
  return (*(uint *)(param_1 + 0x1c) & uVar2) * 8 + *(int *)(param_1 + 0x10);
}



/* 40489734 FUN_40489734 */

void FUN_40489734(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if (param_3 != iVar3) {
    puVar2 = param_2;
    do {
      if (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)((param_3 - (int)param_2) + (int)puVar2);
        *puVar2 = *puVar1;
        puVar2[1] = puVar1[1];
      }
      puVar2 = puVar2 + 2;
    } while ((param_3 - (int)param_2) + (int)puVar2 != iVar3);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - (int)param_2 >> 3) * -8;
  return;
}



/* 4048978c FUN_4048978c */

/* Boundary evidence: original MIPS .pdata 4048978c..4048982f. Semantic name remains unreviewed. */

undefined4 FUN_4048978c(int *param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_3 + param_4;
  if ((uVar3 < param_3) || (iVar1 = FUN_40489320(param_1,uVar3), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    memmove((void *)(param_4 * 2 + *param_1),param_2,param_3 << 1);
    param_1[10] = uVar3;
    *(undefined2 *)(uVar3 * 2 + *param_1) = 0;
    uVar2 = 1;
  }
  return uVar2;
}



/* 40489830 FUN_40489830 */

/* Boundary evidence: original MIPS .pdata 40489830..404898bb. Semantic name remains unreviewed. */

undefined4 * FUN_40489830(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_3[0xd];
  *(undefined4 *)(param_3[0xe] + 0x34) = uVar2;
  *(undefined4 *)(param_3[0xd] + 0x38) = param_3[0xe];
  if (param_3[0xb] != 0x10) {
    FUN_404962ec((LPVOID)*param_3);
  }
  FUN_404962ec(param_3);
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = uVar2;
  *(int *)(param_1 + 0xc) = iVar1 + -1;
  return param_2;
}



/* 404898bc FUN_404898bc */

/* Boundary evidence: original MIPS .pdata 404898bc..4048991b. Semantic name remains unreviewed. */

bool FUN_404898bc(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((wchar_t *)*param_1 == (wchar_t *)0x0) {
    iVar1 = -1;
  }
  else if ((wchar_t *)*param_2 == (wchar_t *)0x0) {
    iVar1 = 1;
  }
  else {
    iVar1 = wcscmp((wchar_t *)*param_1,(wchar_t *)*param_2);
  }
  return iVar1 == 0;
}



/* 4048991c FUN_4048991c */

/* Boundary evidence: original MIPS .pdata 4048991c..4048998b. Semantic name remains unreviewed. */

undefined4 FUN_4048991c(uint *param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = (undefined4 *)param_1[1];
  uVar4 = *param_1;
  uVar3 = (int)((int)puVar2 - uVar4) >> 3;
  if (uVar3 < param_2) {
    uVar1 = FUN_404894d0(param_1,puVar2,param_2 - ((int)((int)puVar2 - uVar4) >> 3),param_3);
  }
  else {
    if (param_2 < uVar3) {
      FUN_40489734((int)param_1,(undefined4 *)(param_2 * 8 + uVar4),(int)puVar2);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 4048998c FUN_4048998c */

/* Boundary evidence: original MIPS .pdata 4048998c..40489a4b. Semantic name remains unreviewed. */

undefined4 * FUN_4048998c(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined3 extraout_var;
  int iVar3;
  
  if ((param_1[5] - param_1[4] & 0xfffffff8) != 0) {
    puVar2 = (undefined4 *)FUN_404896dc((int)param_1,param_3);
    iVar3 = puVar2[1];
    puVar2 = (undefined4 *)*puVar2;
    while (iVar3 != 0) {
      iVar3 = iVar3 + -1;
      bVar1 = FUN_404898bc(puVar2,param_3);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        *param_2 = puVar2;
        return param_2;
      }
      puVar2 = (undefined4 *)puVar2[0xd];
    }
  }
  *param_2 = *param_1;
  return param_2;
}



/* 40489a4c FUN_40489a4c */

/* Boundary evidence: original MIPS .pdata 40489a4c..40489a9b. Semantic name remains unreviewed. */

void FUN_40489a4c(int *param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  
  if (param_2 == (short *)0x0) {
    uVar2 = 0;
  }
  else {
    sVar1 = *param_2;
    psVar3 = param_2;
    while (sVar1 != 0) {
      psVar3 = psVar3 + 1;
      sVar1 = *psVar3;
    }
    uVar2 = (int)psVar3 - (int)param_2 >> 1;
  }
  FUN_4048978c(param_1,param_2,uVar2,0);
  return;
}



/* 40489a9c FUN_40489a9c */

/* Boundary evidence: original MIPS .pdata 40489a9c..40489b27. Semantic name remains unreviewed. */

undefined4 * FUN_40489a9c(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 auStack_20 [2];
  
  while (param_3 != param_4) {
    puVar1 = (undefined4 *)param_3[0xd];
    FUN_40489830(param_1,auStack_20,param_3);
    param_3 = puVar1;
  }
  *param_2 = param_3;
  return param_2;
}



/* 40489b28 FUN_40489b28 */

/* Boundary evidence: original MIPS .pdata 40489b28..40489b7f. Semantic name remains unreviewed. */

int * FUN_40489b28(int *param_1,undefined4 *param_2)

{
  param_1[0xb] = 0x10;
  *param_1 = (int)(param_1 + 1);
  *(undefined2 *)(param_1 + 9) = 0;
  param_1[10] = 0;
  *(undefined2 *)*param_1 = 0;
  FUN_4048978c(param_1,(void *)*param_2,param_2[10],0);
  return param_1;
}



/* 40489b80 FUN_40489b80 */

/* Boundary evidence: original MIPS .pdata 40489b80..40489bff. Semantic name remains unreviewed. */

undefined4 * FUN_40489b80(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_40489468((int)param_1,param_3);
  if (piVar1 == (int *)0x0) {
    *param_2 = *param_1;
  }
  else {
    FUN_40489b28(piVar1,param_4);
    piVar1[0xc] = param_4[0xc];
    *param_2 = piVar1;
  }
  return param_2;
}



/* 40489c00 FUN_40489c00 */

/* Boundary evidence: original MIPS .pdata 40489c00..40489c6b. Semantic name remains unreviewed. */

int * FUN_40489c00(int *param_1,uint param_2)

{
  int local_10 [2];
  
  *param_1 = (int)(param_1 + -0xc);
  param_1[3] = 0;
  param_1[1] = (int)(param_1 + -0xc);
  *(undefined4 *)(*param_1 + 0x38) = *(undefined4 *)(*param_1 + 0x34);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  local_10[0] = *param_1;
  param_1[7] = param_2 - 1;
  local_10[1] = 0;
  FUN_4048991c((uint *)(param_1 + 4),param_2,local_10);
  return param_1;
}



/* 40489c6c FUN_40489c6c */

/* Boundary evidence: original MIPS .pdata 40489c6c..40489d97. Semantic name remains unreviewed. */

int * FUN_40489c6c(int *param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 auStack_28 [2];
  
  if ((param_1[5] - param_1[4] & 0xfffffff8U) != 0) {
    piVar2 = (int *)FUN_404896dc((int)param_1,param_3);
    iVar5 = piVar2[1];
    puVar4 = (undefined4 *)*piVar2;
    while (iVar5 != 0) {
      iVar5 = iVar5 + -1;
      bVar1 = FUN_404898bc(puVar4,param_3);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        *param_2 = (int)puVar4;
        return param_2;
      }
      puVar4 = (undefined4 *)puVar4[0xd];
    }
    iVar5 = *param_1;
    piVar3 = FUN_40489b80(param_1,auStack_28,*piVar2,param_3);
    if (iVar5 != *piVar3) {
      piVar2[1] = piVar2[1] + 1;
      iVar5 = *(int *)(*piVar2 + 0x38);
      *piVar2 = iVar5;
      *param_2 = iVar5;
      return param_2;
    }
  }
  *param_2 = *param_1;
  return param_2;
}



/* 40489d98 FUN_40489d98 */

/* Boundary evidence: original MIPS .pdata 40489d98..40489def. Semantic name remains unreviewed. */

void FUN_40489d98(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 auStack_18 [2];
  
  puVar1 = param_1 + 4;
  FUN_40489734((int)puVar1,(undefined4 *)*puVar1,param_1[5]);
  FUN_404962ec((LPVOID)*puVar1);
  FUN_40489a9c((int)param_1,auStack_18,(undefined4 *)((undefined4 *)*param_1)[0xd],
               (undefined4 *)*param_1);
  return;
}



/* 40489df0 FUN_40489df0 */

/* Boundary evidence: original MIPS .pdata 40489df0..40489e67. Semantic name remains unreviewed. */

int * FUN_40489df0(int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  LPVOID local_48 [11];
  int local_1c;
  undefined4 local_18;
  
  FUN_40489b28((int *)local_48,param_3);
  local_18 = *param_4;
  FUN_40489c6c(param_1,param_2,local_48);
  if (local_1c != 0x10) {
    FUN_404962ec(local_48[0]);
  }
  return param_2;
}



/* 40489e68 FUN_40489e68 */

/* Boundary evidence: original MIPS .pdata 40489e68..4048a01f. Semantic name remains unreviewed. */

HMODULE FUN_40489e68(LPCWSTR param_1)

{
  int *piVar1;
  HMODULE pHVar2;
  HMODULE local_88;
  int iStack_84;
  undefined2 *local_80;
  undefined2 local_7c [16];
  undefined2 local_5c;
  undefined4 local_58;
  int local_54;
  undefined2 *local_50;
  undefined2 local_4c [16];
  undefined2 local_2c;
  undefined4 local_28;
  int local_24;
  
  pHVar2 = (HMODULE)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2f0);
  if (DAT_404bd2ec == (int *)0x0) {
    piVar1 = (int *)FUN_404962c4(0x20);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      FUN_40489c00(piVar1,0x20);
    }
    DAT_404bd2ec = piVar1;
    if (piVar1 == (int *)0x0) {
      return (HMODULE)0x0;
    }
  }
  local_80 = local_7c;
  local_54 = 0x10;
  local_5c = 0;
  local_58 = 0;
  local_7c[0] = 0;
  FUN_40489a4c((int *)&local_80,param_1);
  piVar1 = DAT_404bd2ec;
  FUN_4048998c(DAT_404bd2ec,&local_88,&local_80);
  if (local_54 != 0x10) {
    FUN_404962ec(local_80);
    piVar1 = DAT_404bd2ec;
  }
  if (local_88 == (HMODULE)*piVar1) {
    pHVar2 = LoadLibraryW(param_1);
    local_88 = pHVar2;
    if (pHVar2 != (HMODULE)0x0) {
      local_50 = local_4c;
      local_24 = 0x10;
      local_2c = 0;
      local_28 = 0;
      local_4c[0] = 0;
      FUN_40489a4c((int *)&local_50,param_1);
      FUN_40489df0(DAT_404bd2ec,&iStack_84,&local_50,&local_88);
      if (local_24 != 0x10) {
        FUN_404962ec(local_50);
      }
    }
  }
  else if (local_88 != (HMODULE)*piVar1) {
    pHVar2 = (HMODULE)local_88[0xc].unused;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2f0);
  return pHVar2;
}



/* 4048a020 FUN_4048a020 */

/* Boundary evidence: original MIPS .pdata 4048a020..4048a093. Semantic name remains unreviewed. */

undefined4 FUN_4048a020(LPCWSTR param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE pHVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  pHVar1 = FUN_40489e68(param_1);
  if ((pHVar1 == (HMODULE)0x0) ||
     (pcVar2 = (code *)GetProcAddressW(pHVar1,L"CreateCodecInstance"), pcVar2 == (code *)0x0)) {
    uVar3 = 0x887b0009;
  }
  else {
    uVar3 = (*pcVar2)(param_2,param_3);
  }
  return uVar3;
}



/* 4048a094 FUN_4048a094 */

/* Boundary evidence: original MIPS .pdata 4048a094..4048a37b. Semantic name remains unreviewed. */

int FUN_4048a094(int *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  code *pcVar4;
  LPCWSTR pWVar5;
  int *local_88 [2];
  byte *local_80;
  undefined4 local_7c;
  int local_78;
  uint local_74;
  byte abStack_70 [64];
  uint local_30;
  
  local_30 = DAT_404bd274;
  local_80 = abStack_70;
  local_7c = 0x40;
  local_78 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
  FUN_4048887c();
  uVar1 = DAT_404bd2c4;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
  if (uVar1 == 0) {
LAB_4048a11c:
    FUN_404a438c(local_30);
    iVar3 = -0x7784fffa;
  }
  else {
    iVar3 = FUN_4048903c((int *)&local_80,uVar1);
    if (iVar3 == 0) {
      if (local_78 != 0) {
        FUN_404962ec(local_80);
      }
      FUN_404a438c(local_30);
      return -0x7ff8fff2;
    }
    iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
    pbVar2 = local_80;
    if (-1 < iVar3) {
      iVar3 = FUN_40487e1c(param_1,(int)local_80,uVar1,(int *)&local_74);
      if (local_74 == 0) {
        if (-1 < iVar3) {
          iVar3 = -0x7fffbffb;
        }
      }
      else {
        iVar3 = FUN_40487ee0(param_1,-local_74,0);
        if (-1 < iVar3) {
          pcVar4 = (code *)0x0;
          pWVar5 = (LPCWSTR)0x0;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
          if (((((param_3 & 2) != 0) && (iVar3 = FUN_40488f6c(pbVar2,local_74,0x10000), iVar3 != 0))
              || (iVar3 = FUN_40488f6c(pbVar2,local_74,0), iVar3 != 0)) &&
             (pcVar4 = *(code **)(iVar3 + 0x58), pcVar4 == (code *)0x0)) {
            pWVar5 = *(LPCWSTR *)(iVar3 + 0x24);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
          if (iVar3 == 0) {
            if (local_78 != 0) {
              FUN_404962ec(pbVar2);
            }
            goto LAB_4048a11c;
          }
          if (pcVar4 == (code *)0x0) {
            iVar3 = FUN_4048a020(pWVar5,&DAT_404812bc,local_88);
          }
          else {
            iVar3 = (*pcVar4)(&DAT_404812bc,local_88);
          }
          if (-1 < iVar3) {
            iVar3 = (**(code **)(*local_88[0] + 0xc))(local_88[0],param_1,param_3);
            if (iVar3 < 0) {
              (**(code **)(*local_88[0] + 0x10))();
              (**(code **)(*local_88[0] + 8))();
            }
            else {
              *param_2 = local_88[0];
            }
          }
        }
      }
    }
    if (local_78 != 0) {
      FUN_404962ec(pbVar2);
    }
    FUN_404a438c(local_30);
  }
  return iVar3;
}



/* 4048a37c FUN_4048a37c */

/* Boundary evidence: original MIPS .pdata 4048a37c..4048a4f7. Semantic name remains unreviewed. */

int FUN_4048a37c(void *param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  int iVar2;
  void *_Buf1;
  code *pcVar3;
  LPCWSTR pWVar4;
  int *local_30 [2];
  
  bVar1 = false;
  pWVar4 = (LPCWSTR)0x0;
  pcVar3 = (code *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
  FUN_4048887c();
  _Buf1 = DAT_404bd2bc;
  do {
    if (_Buf1 == (void *)0x0) {
LAB_4048a42c:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
      if (bVar1) {
        if (pcVar3 == (code *)0x0) {
          iVar2 = FUN_4048a020(pWVar4,&DAT_404812cc,local_30);
        }
        else {
          iVar2 = (*pcVar3)(&DAT_404812cc,local_30);
        }
        if (-1 < iVar2) {
          iVar2 = (**(code **)(*local_30[0] + 0xc))(local_30[0],param_2);
          if (iVar2 < 0) {
            (**(code **)(*local_30[0] + 8))();
          }
          else {
            *param_3 = local_30[0];
          }
        }
      }
      else {
        iVar2 = -0x7784fffa;
      }
      return iVar2;
    }
    if (((*(uint *)((int)_Buf1 + 0x34) & 1) != 0) &&
       (iVar2 = memcmp(_Buf1,param_1,0x10), iVar2 == 0)) {
      pWVar4 = *(LPCWSTR *)((int)_Buf1 + 0x24);
      pcVar3 = *(code **)((int)_Buf1 + 0x58);
      bVar1 = true;
      goto LAB_4048a42c;
    }
    _Buf1 = *(void **)((int)_Buf1 + 0x4c);
  } while( true );
}



/* 4048a4f8 FUN_4048a4f8 */

/* Boundary evidence: original MIPS .pdata 4048a4f8..4048a5c3. Semantic name remains unreviewed. */

void FUN_4048a4f8(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2f0);
  if (DAT_404bd2ec != (int *)0x0) {
    iVar3 = *DAT_404bd2ec;
    for (iVar2 = *(int *)(iVar3 + 0x34); piVar1 = DAT_404bd2ec, iVar2 != iVar3;
        iVar2 = *(int *)(iVar2 + 0x34)) {
      FreeLibrary(*(HMODULE *)(iVar2 + 0x30));
    }
    if (DAT_404bd2ec != (int *)0x0) {
      FUN_40489d98(DAT_404bd2ec);
      FUN_404962ec(piVar1);
    }
    DAT_404bd2ec = (int *)0x0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2f0);
  return;
}



/* 4048a5c4 FUN_4048a5c4 */

/* Boundary evidence: original MIPS .pdata 4048a5c4..4048a647. Semantic name remains unreviewed. */

undefined4 FUN_4048a5c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = __gts(param_2,0);
  if ((iVar1 == 0) || (iVar1 = __gts(param_3,0), iVar1 == 0)) {
    uVar2 = 0x80070057;
  }
  else {
    *(undefined4 *)(param_1 + 0x28) = param_2;
    *(undefined4 *)(param_1 + 0x2c) = param_3;
  }
  return uVar2;
}



/* 4048a648 FUN_4048a648 */

/* Boundary evidence: original MIPS .pdata 4048a648..4048a6e3. Semantic name remains unreviewed. */

undefined4 FUN_4048a648(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40482c64,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40481654,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 4048a6e4 FUN_4048a6e4 */

/* Boundary evidence: original MIPS .pdata 4048a6e4..4048a6ff. Semantic name remains unreviewed. */

void FUN_4048a6e4(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 4048a700 FUN_4048a700 */

/* Boundary evidence: original MIPS .pdata 4048a700..4048a75b. Semantic name remains unreviewed. */

LONG FUN_4048a700(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x24))(param_1,1);
  }
  return LVar1;
}



/* 4048a75c FUN_4048a75c */

/* Boundary evidence: original MIPS .pdata 4048a75c..4048a79f. Semantic name remains unreviewed. */

undefined4 * FUN_4048a75c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_4048162c;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 4048a7a0 FUN_4048a7a0 */

/* Boundary evidence: original MIPS .pdata 4048a7a0..4048a863. Semantic name remains unreviewed. */

void FUN_4048a7a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40481664;
  if ((int *)param_1[6] != (int *)0x0) {
    (**(code **)(*(int *)param_1[6] + 8))();
  }
  if ((int *)param_1[4] != (int *)0x0) {
    (**(code **)(*(int *)param_1[4] + 0x10))();
    (**(code **)(*(int *)param_1[4] + 8))();
  }
  if ((int *)param_1[5] != (int *)0x0) {
    (**(code **)(*(int *)param_1[5] + 8))();
  }
  if ((int *)param_1[9] != (int *)0x0) {
    (**(code **)(*(int *)param_1[9] + 8))();
  }
  param_1[2] = 0x4c494146;
  *param_1 = &PTR_FUN_4048162c;
  return;
}



/* 4048a864 FUN_4048a864 */

/* Boundary evidence: original MIPS .pdata 4048a864..4048a927. Semantic name remains unreviewed. */

undefined4 FUN_4048a864(int param_1,uint param_2)

{
  undefined4 uVar1;
  int local_18;
  LONG *local_14;
  
  if ((param_2 & 0xfffcffff) == 0) {
    local_14 = (LONG *)(param_1 + 0xc);
    if (local_14 == (LONG *)0x0) {
      local_14 = &local_18;
      local_18 = 0;
    }
    else {
      local_18 = InterlockedIncrement(local_14);
    }
    if (local_18 == 0) {
      *(uint *)(param_1 + 0x1c) = param_2;
      if (((param_2 & 0x20000) == 0) && (*(int **)(param_1 + 0x18) != (int *)0x0)) {
        (**(code **)(**(int **)(param_1 + 0x18) + 8))();
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
      uVar1 = 0;
    }
    else {
      uVar1 = 0x887b0001;
    }
    InterlockedDecrement(local_14);
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



/* 4048a928 FUN_4048a928 */

/* Boundary evidence: original MIPS .pdata 4048a928..4048aa03. Semantic name remains unreviewed. */

void FUN_4048a928(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x10);
  if (((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) &&
     (iVar1 = (**(code **)(*(int *)*piVar2 + 0x14))
                        ((int *)*piVar2,param_2,*(undefined4 *)(param_1 + 0x24)), -1 < iVar1)) {
    iVar1 = (**(code **)(*(int *)*piVar2 + 0x18))();
    while (iVar1 == -0x7ffffff6) {
      Sleep(0);
      iVar1 = (**(code **)(*(int *)*piVar2 + 0x18))();
    }
    (**(code **)(*(int *)*piVar2 + 0x1c))((int *)*piVar2,iVar1);
  }
  return;
}



/* 4048aa04 FUN_4048aa04 */

/* Boundary evidence: original MIPS .pdata 4048aa04..4048aabb. Semantic name remains unreviewed. */

int FUN_4048aa04(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = DAT_404bd274;
  piVar3 = (int *)(param_1 + 0x10);
  if ((*piVar3 != 0) || (iVar2 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar3,0), -1 < iVar2)) {
    iVar2 = (**(code **)(*(int *)*piVar3 + 0x38))((int *)*piVar3,param_2,param_3,param_4,param_5);
  }
  FUN_404a438c(uVar1);
  return iVar2;
}



/* 4048aabc FUN_4048aabc */

/* Boundary evidence: original MIPS .pdata 4048aabc..4048ab8b. Semantic name remains unreviewed. */

int FUN_4048aabc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = DAT_404bd274;
  piVar3 = (int *)(param_1 + 0x10);
  if ((*piVar3 != 0) || (iVar2 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar3,0), -1 < iVar2)) {
    iVar2 = (**(code **)(*(int *)*piVar3 + 0x3c))
                      ((int *)*piVar3,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  FUN_404a438c(uVar1);
  return iVar2;
}



/* 4048ab8c FUN_4048ab8c */

/* Boundary evidence: original MIPS .pdata 4048ab8c..4048abeb. Semantic name remains unreviewed. */

void FUN_4048ab8c(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x10);
  if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
    (**(code **)(*(int *)*piVar2 + 0x40))((int *)*piVar2,param_2);
  }
  return;
}



/* 4048abec FUN_4048abec */

/* Boundary evidence: original MIPS .pdata 4048abec..4048ac5b. Semantic name remains unreviewed. */

void FUN_4048abec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x10);
  if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
    (**(code **)(*(int *)*piVar2 + 0x44))((int *)*piVar2,param_2,param_3);
  }
  return;
}



/* 4048ac5c FUN_4048ac5c */

/* Boundary evidence: original MIPS .pdata 4048ac5c..4048accb. Semantic name remains unreviewed. */

void FUN_4048ac5c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x10);
  if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
    (**(code **)(*(int *)*piVar2 + 0x48))((int *)*piVar2,param_2,param_3);
  }
  return;
}



/* 4048accc FUN_4048accc */

/* Boundary evidence: original MIPS .pdata 4048accc..4048ad4b. Semantic name remains unreviewed. */

void FUN_4048accc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x10);
  if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
    (**(code **)(*(int *)*piVar2 + 0x4c))((int *)*piVar2,param_2,param_3,param_4);
  }
  return;
}



/* 4048ad4c FUN_4048ad4c */

/* Boundary evidence: original MIPS .pdata 4048ad4c..4048adbb. Semantic name remains unreviewed. */

void FUN_4048ad4c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x10);
  if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
    (**(code **)(*(int *)*piVar2 + 0x50))((int *)*piVar2,param_2,param_3);
  }
  return;
}



/* 4048adbc FUN_4048adbc */

/* Boundary evidence: original MIPS .pdata 4048adbc..4048ae3b. Semantic name remains unreviewed. */

void FUN_4048adbc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x10);
  if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
    (**(code **)(*(int *)*piVar2 + 0x54))((int *)*piVar2,param_2,param_3,param_4);
  }
  return;
}



/* 4048ae3c FUN_4048ae3c */

/* Boundary evidence: original MIPS .pdata 4048ae3c..4048ae9b. Semantic name remains unreviewed. */

void FUN_4048ae3c(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x10);
  if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
    (**(code **)(*(int *)*piVar2 + 0x58))((int *)*piVar2,param_2);
  }
  return;
}



/* 4048ae9c FUN_4048ae9c */

/* Boundary evidence: original MIPS .pdata 4048ae9c..4048af23. Semantic name remains unreviewed. */

void FUN_4048ae9c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x10);
  if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
    (**(code **)(*(int *)*piVar2 + 0x5c))((int *)*piVar2,param_2,param_3,param_4,param_5);
  }
  return;
}



/* 4048af24 FUN_4048af24 */

/* Boundary evidence: original MIPS .pdata 4048af24..4048b033. Semantic name remains unreviewed. */

int FUN_4048af24(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int local_20;
  LONG *local_1c;
  
  local_1c = (LONG *)(param_1 + 0xc);
  if (local_1c == (LONG *)0x0) {
    local_1c = &local_20;
    local_20 = 0;
  }
  else {
    local_20 = InterlockedIncrement(local_1c);
  }
  if (local_20 == 0) {
    piVar3 = (int *)(param_1 + 0x10);
    if ((*piVar3 != 0) || (iVar2 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar3,0), -1 < iVar2)) {
      iVar2 = (**(code **)(*(int *)*piVar3 + 0x30))((int *)*piVar3,param_2);
    }
    uVar4 = *(undefined4 *)(param_1 + 0x28);
    iVar1 = __gts(uVar4,0);
    if ((iVar1 != 0) && (iVar1 = __gts(*(undefined4 *)(param_1 + 0x2c),0), iVar1 != 0)) {
      uVar5 = __fptodp(uVar4);
      *(undefined8 *)(param_2 + 0x28) = uVar5;
      uVar5 = __fptodp(*(undefined4 *)(param_1 + 0x2c));
      *(undefined8 *)(param_2 + 0x30) = uVar5;
    }
  }
  else {
    iVar2 = -0x7784ffff;
  }
  InterlockedDecrement(local_1c);
  return iVar2;
}



/* 4048b034 FUN_4048b034 */

/* Boundary evidence: original MIPS .pdata 4048b034..4048b0ff. Semantic name remains unreviewed. */

int FUN_4048b034(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int local_20;
  LONG *local_1c;
  
  local_1c = (LONG *)(param_1 + 0xc);
  if (local_1c == (LONG *)0x0) {
    local_1c = &local_20;
    local_20 = 0;
  }
  else {
    local_20 = InterlockedIncrement(local_1c);
  }
  if (local_20 == 0) {
    piVar2 = (int *)(param_1 + 0x10);
    if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
      iVar1 = (**(code **)(*(int *)*piVar2 + 0x28))((int *)*piVar2,param_2,param_3);
    }
  }
  else {
    iVar1 = -0x7784ffff;
  }
  InterlockedDecrement(local_1c);
  return iVar1;
}



/* 4048b100 FUN_4048b100 */

/* Boundary evidence: original MIPS .pdata 4048b100..4048b1bb. Semantic name remains unreviewed. */

int FUN_4048b100(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int local_18;
  LONG *local_14;
  
  local_14 = (LONG *)(param_1 + 0xc);
  if (local_14 == (LONG *)0x0) {
    local_14 = &local_18;
    local_18 = 0;
  }
  else {
    local_18 = InterlockedIncrement(local_14);
  }
  if (local_18 == 0) {
    piVar2 = (int *)(param_1 + 0x10);
    if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
      iVar1 = (**(code **)(*(int *)*piVar2 + 0x20))((int *)*piVar2,param_2);
    }
  }
  else {
    iVar1 = -0x7784ffff;
  }
  InterlockedDecrement(local_14);
  return iVar1;
}



/* 4048b1bc FUN_4048b1bc */

/* Boundary evidence: original MIPS .pdata 4048b1bc..4048b287. Semantic name remains unreviewed. */

int FUN_4048b1bc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int local_20;
  LONG *local_1c;
  
  local_1c = (LONG *)(param_1 + 0xc);
  if (local_1c == (LONG *)0x0) {
    local_1c = &local_20;
    local_20 = 0;
  }
  else {
    local_20 = InterlockedIncrement(local_1c);
  }
  if (local_20 == 0) {
    piVar2 = (int *)(param_1 + 0x10);
    if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
      iVar1 = (**(code **)(*(int *)*piVar2 + 0x24))((int *)*piVar2,param_2,param_3);
    }
  }
  else {
    iVar1 = -0x7784ffff;
  }
  InterlockedDecrement(local_1c);
  return iVar1;
}



/* 4048b288 FUN_4048b288 */

/* Boundary evidence: original MIPS .pdata 4048b288..4048b353. Semantic name remains unreviewed. */

int FUN_4048b288(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int local_20;
  LONG *local_1c;
  
  local_1c = (LONG *)(param_1 + 0xc);
  if (local_1c == (LONG *)0x0) {
    local_1c = &local_20;
    local_20 = 0;
  }
  else {
    local_20 = InterlockedIncrement(local_1c);
  }
  if (local_20 == 0) {
    piVar2 = (int *)(param_1 + 0x10);
    if ((*piVar2 != 0) || (iVar1 = FUN_4048a094(*(int **)(param_1 + 0x14),piVar2,0), -1 < iVar1)) {
      iVar1 = (**(code **)(*(int *)*piVar2 + 0x2c))((int *)*piVar2,param_2,param_3);
    }
  }
  else {
    iVar1 = -0x7784ffff;
  }
  InterlockedDecrement(local_1c);
  return iVar1;
}



/* 4048b354 FUN_4048b354 */

/* Boundary evidence: original MIPS .pdata 4048b354..4048b58b. Semantic name remains unreviewed. */

int FUN_4048b354(int *param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  int *local_80 [2];
  int local_78;
  LONG *local_74;
  int *local_70 [2];
  undefined1 auStack_68 [20];
  uint local_54;
  uint local_50;
  uint local_28;
  
  local_28 = DAT_404bd274;
  if (param_2 == 0) {
    if (param_3 != 0) goto LAB_4048b3c4;
  }
  else if (param_3 == 0) {
LAB_4048b3c4:
    FUN_404a438c(DAT_404bd274);
    return -0x7ff8ffa9;
  }
  local_74 = param_1 + 3;
  local_80[0] = (int *)0x0;
  if (local_74 == (LONG *)0x0) {
    local_74 = &local_78;
    local_78 = 0;
  }
  else {
    local_78 = InterlockedIncrement(local_74);
  }
  if (local_78 == 0) {
    piVar1 = param_1 + 4;
    if ((*piVar1 != 0) || (iVar2 = FUN_4048a094((int *)param_1[5],piVar1,0), -1 < iVar2)) {
      iVar2 = (**(code **)(*(int *)*piVar1 + 0x34))((int *)*piVar1,param_2,param_3,local_80);
      if (iVar2 < 0) {
        local_80[0] = (int *)0x0;
      }
      else {
        iVar2 = (**(code **)(*local_80[0] + 0x10))(local_80[0],auStack_68);
        if ((((-1 < iVar2) && (local_54 == param_2)) || ((param_2 == 0 && (local_50 == param_3))))
           || (param_3 == 0)) {
          iVar2 = 0;
          *param_4 = local_80[0];
          goto LAB_4048b498;
        }
      }
      InterlockedDecrement(local_74);
      if ((param_2 == 0) && (param_3 == 0)) {
        param_3 = 0x78;
        param_2 = 0x78;
      }
      piVar1 = local_80[0];
      if (local_80[0] == (int *)0x0) {
        piVar1 = param_1;
      }
      iVar2 = FUN_4048e3bc(piVar1,param_2,param_3,0,3,local_70,0,0);
      if (-1 < iVar2) {
        iVar2 = (**(code **)*local_70[0])(local_70[0],&DAT_4048129c,param_4);
        (**(code **)(*local_70[0] + 8))();
      }
      if (local_80[0] != (int *)0x0) {
        (**(code **)(*local_80[0] + 8))();
      }
      goto LAB_4048b55c;
    }
  }
  else {
    iVar2 = -0x7784ffff;
  }
LAB_4048b498:
  InterlockedDecrement(local_74);
LAB_4048b55c:
  FUN_404a438c(local_28);
  return iVar2;
}



/* 4048b58c FUN_4048b58c */

/* Boundary evidence: original MIPS .pdata 4048b58c..4048b5d7. Semantic name remains unreviewed. */

undefined4 * FUN_4048b58c(undefined4 *param_1,uint param_2)

{
  FUN_4048a7a0(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 4048b5d8 FUN_4048b5d8 */

/* Boundary evidence: original MIPS .pdata 4048b5d8..4048b6ef. Semantic name remains unreviewed. */

int FUN_4048b5d8(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 auStack_60 [20];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_20;
  
  local_20 = DAT_404bd274;
  iVar1 = FUN_4048af24(param_1,(int)auStack_60);
  if (-1 < iVar1) {
    uVar3 = __litodp(local_4c);
    uVar3 = __dpmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x40a3d800);
    uVar3 = __dpdiv((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),local_38,local_34);
    uVar3 = __dpadd((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x3fe00000);
    uVar2 = __dptoli((int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
    *param_2 = uVar2;
    uVar3 = __litodp(local_48);
    uVar3 = __dpmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x40a3d800);
    uVar3 = __dpdiv((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),local_30,local_2c);
    uVar3 = __dpadd((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x3fe00000);
    uVar2 = __dptoli((int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
    param_2[1] = uVar2;
  }
  FUN_404a438c(local_20);
  return iVar1;
}



/* 4048b6f0 FUN_4048b6f0 */

/* Boundary evidence: original MIPS .pdata 4048b6f0..4048b797. Semantic name remains unreviewed. */

int FUN_4048b6f0(int param_1,int param_2)

{
  int iVar1;
  int local_18;
  LONG *local_14;
  
  iVar1 = FUN_4048af24(param_1,param_2);
  if (-1 < iVar1) {
    local_14 = (LONG *)(param_1 + 0xc);
    if (local_14 == (LONG *)0x0) {
      local_14 = &local_18;
      local_18 = 0;
    }
    else {
      local_18 = InterlockedIncrement(local_14);
    }
    if (local_18 == 0) {
      *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) & 0xffff | *(uint *)(param_1 + 0x1c);
    }
    else {
      iVar1 = -0x7784ffff;
    }
    InterlockedDecrement(local_14);
  }
  return iVar1;
}



/* 4048b798 FUN_4048b798 */

/* Boundary evidence: original MIPS .pdata 4048b798..4048b917. Semantic name remains unreviewed. */

int FUN_4048b798(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  LONG *local_24;
  
  local_24 = (LONG *)(param_1 + 0xc);
  if (local_24 == (LONG *)0x0) {
    local_24 = &local_28;
    local_28 = 0;
  }
  else {
    local_28 = InterlockedIncrement(local_24);
  }
  if (local_28 != 0) {
    iVar3 = -0x7784ffff;
    goto LAB_4048b8e4;
  }
  piVar4 = (int *)(param_1 + 0x18);
  if (*piVar4 == 0) {
    puVar1 = (undefined4 *)FUN_404962c4(0xc0);
    if (puVar1 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_4048e19c(puVar1);
    }
    if (piVar2 == (int *)0x0) {
      iVar3 = -0x7ff8fff2;
      goto LAB_4048b8e4;
    }
    iVar3 = FUN_4048a928(param_1,piVar2 + 2);
    if (-1 < iVar3) {
      iVar3 = (**(code **)*piVar2)(piVar2,&DAT_4048129c,piVar4);
    }
    (**(code **)(*piVar2 + 8))(piVar2);
    if (iVar3 < 0) goto LAB_4048b8e4;
  }
  iVar3 = (**(code **)(*(int *)*piVar4 + 0x18))((int *)*piVar4,param_2,param_3,param_4);
  if ((*(uint *)(param_1 + 0x1c) & 0x20000) == 0) {
    (**(code **)(*(int *)*piVar4 + 8))();
    *piVar4 = 0;
  }
LAB_4048b8e4:
  InterlockedDecrement(local_24);
  return iVar3;
}



/* 4048b918 FUN_4048b918 */

/* Boundary evidence: original MIPS .pdata 4048b918..4048b997. Semantic name remains unreviewed. */

undefined4 FUN_4048b918(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int local_18;
  LONG *local_14;
  
  local_14 = (LONG *)(param_1 + 0xc);
  if (local_14 == (LONG *)0x0) {
    local_14 = &local_18;
    local_18 = 0;
  }
  else {
    local_18 = InterlockedIncrement(local_14);
  }
  if (local_18 == 0) {
    uVar1 = FUN_4048a928(param_1,param_2);
  }
  else {
    uVar1 = 0x887b0001;
  }
  InterlockedDecrement(local_14);
  return uVar1;
}



/* 4048b998 FUN_4048b998 */

/* Boundary evidence: original MIPS .pdata 4048b998..4048ba3b. Semantic name remains unreviewed. */

undefined4 * FUN_4048b998(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1[1] = 1;
  *param_1 = &PTR_FUN_40481664;
  param_1[3] = 0xffffffff;
  param_1[5] = param_2;
  (**(code **)(*param_2 + 4))(param_2);
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0x10000;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  iVar1 = FUN_4048a094((int *)param_1[5],param_1 + 4,0);
  if (iVar1 == 0) {
    uVar2 = 0x49654431;
  }
  else {
    uVar2 = 0x4c494146;
  }
  param_1[2] = uVar2;
  return param_1;
}



/* 4048ba3c FUN_4048ba3c */

/* Boundary evidence: original MIPS .pdata 4048ba3c..4048baef. Semantic name remains unreviewed. */

undefined4 FUN_4048ba3c(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    puVar2 = (undefined4 *)FUN_404962c4(0x30);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_4048b998(puVar2,param_1);
    }
    if (piVar3 == (int *)0x0) {
      uVar1 = 0x8007000e;
    }
    else if (piVar3[2] == 0x49654431) {
      *param_2 = piVar3;
      uVar1 = 0;
    }
    else {
      (**(code **)(*piVar3 + 0x24))(piVar3,1);
      uVar1 = 0x80004005;
    }
  }
  return uVar1;
}



/* 4048baf0 FUN_4048baf0 */

/* Boundary evidence: original MIPS .pdata 4048baf0..4048bb4f. Semantic name remains unreviewed. */

DWORD FUN_4048baf0(LPCWSTR param_1,undefined4 *param_2)

{
  DWORD DVar1;
  int *local_18 [2];
  
  DVar1 = FUN_4048fd58(param_1,local_18);
  if (-1 < (int)DVar1) {
    DVar1 = FUN_4048ba3c(local_18[0],param_2);
    (**(code **)(*local_18[0] + 8))();
  }
  return DVar1;
}



/* 4048bb50 FUN_4048bb50 */

/* Boundary evidence: original MIPS .pdata 4048bb50..4048bba7. Semantic name remains unreviewed. */

void FUN_4048bb50(int param_1)

{
  if ((*(uint *)(param_1 + 0x14) & 0x10000) == 0) {
    if ((*(uint *)(param_1 + 0x14) & 0x20000) != 0) {
      VirtualFree(*(LPVOID *)(param_1 + 0x10),0,0x8000);
    }
  }
  else {
    FUN_404962ec(*(LPVOID *)(param_1 + 0x10));
  }
  return;
}



/* 4048bba8 FUN_4048bba8 */

/* Boundary evidence: original MIPS .pdata 4048bba8..4048bbf3. Semantic name remains unreviewed. */

void FUN_4048bba8(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + 0x10;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  FUN_4048bb50(iVar1);
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xfffcffff;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}



/* 4048bd18 FUN_4048bd18 */

/* Boundary evidence: original MIPS .pdata 4048bd18..4048bdcf. Semantic name remains unreviewed. */

undefined4 FUN_4048bd18(int param_1,int param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_4 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    if (*(int *)(param_1 + 0xac) != 0) {
      piVar2 = (int *)**(int **)(param_1 + 0x78);
      piVar4 = *(int **)(param_1 + 0x78);
      if (piVar2 != (int *)0x0) {
        do {
          piVar3 = piVar2;
          if (piVar4[2] == param_2) break;
          piVar2 = (int *)*piVar3;
          piVar4 = piVar3;
        } while ((int *)*piVar3 != (int *)0x0);
        if ((*piVar4 != 0) && (piVar4[3] + 0x10 == param_3)) {
          *param_4 = piVar4[2];
          param_4[1] = piVar4[3];
          *(short *)(param_4 + 2) = (short)piVar4[4];
          param_4[3] = (int)(param_4 + 4);
          memcpy(param_4 + 4,(void *)piVar4[5],piVar4[3]);
          return 0;
        }
      }
    }
    uVar1 = 0x80004005;
  }
  return uVar1;
}



/* 4048be14 FUN_4048be14 */

/* Boundary evidence: original MIPS .pdata 4048be14..4048bf03. Semantic name remains unreviewed. */

undefined4 FUN_4048be14(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
  int *piVar5;
  void *_Dst;
  int iVar6;
  
  iVar3 = *(int *)(param_1 + 0xac);
  if (((param_2 == *(int *)(param_1 + 0xa8) + iVar3 * 0x10) && (param_3 == iVar3)) && (param_4 != 0)
     ) {
    if (iVar3 == 0) {
      uVar2 = 0x80004005;
    }
    else {
      piVar5 = *(int **)(param_1 + 0x78);
      _Dst = (void *)(iVar3 * 0x10 + param_4);
      iVar6 = 0;
      if (0 < iVar3) {
        puVar4 = (undefined2 *)(param_4 + 8);
        do {
          *(int *)(puVar4 + -4) = piVar5[2];
          *(int *)(puVar4 + -2) = piVar5[3];
          *puVar4 = *(undefined2 *)(piVar5 + 4);
          *(void **)(puVar4 + 2) = _Dst;
          memcpy(_Dst,(void *)piVar5[5],piVar5[3]);
          piVar1 = piVar5 + 3;
          iVar6 = iVar6 + 1;
          piVar5 = (int *)*piVar5;
          _Dst = (void *)(*piVar1 + (int)_Dst);
          puVar4 = puVar4 + 8;
        } while (iVar6 < *(int *)(param_1 + 0xac));
      }
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}



/* 4048bf04 FUN_4048bf04 */

/* Boundary evidence: original MIPS .pdata 4048bf04..4048bf9f. Semantic name remains unreviewed. */

undefined4 FUN_4048bf04(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0xac) != 0) {
    piVar1 = (int *)**(int **)(param_1 + 0x78);
    piVar3 = *(int **)(param_1 + 0x78);
    if (piVar1 != (int *)0x0) {
      do {
        piVar2 = piVar1;
        if (piVar3[2] == param_2) break;
        piVar1 = (int *)*piVar2;
        piVar3 = piVar2;
      } while ((int *)*piVar2 != (int *)0x0);
      if (*piVar3 != 0) {
        *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + -1;
        *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) - piVar3[3];
        FUN_40490480(piVar3);
        FUN_404962ec(piVar3);
        return 0;
      }
    }
  }
  return 0x80004005;
}



/* 4048bfa0 FUN_4048bfa0 */

/* Boundary evidence: original MIPS .pdata 4048bfa0..4048c09f. Semantic name remains unreviewed. */

undefined4 FUN_4048bfa0(int param_1,int param_2,SIZE_T param_3,undefined2 param_4,void *param_5)

{
  void *_Dst;
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x78);
  if (*piVar2 != 0) {
    do {
      if (piVar2[2] == param_2) break;
      piVar2 = (int *)*piVar2;
    } while (*piVar2 != 0);
    if (*piVar2 != 0) {
      *(SIZE_T *)(param_1 + 0xa8) = (*(int *)(param_1 + 0xa8) - piVar2[3]) + param_3;
      FUN_404962ec((LPVOID)piVar2[5]);
      piVar2[3] = param_3;
      *(undefined2 *)(piVar2 + 4) = param_4;
      _Dst = (void *)FUN_404962c4(param_3);
      piVar2[5] = (int)_Dst;
      if (_Dst != (void *)0x0) {
        memcpy(_Dst,param_5,param_3);
        return 0;
      }
      piVar2[3] = 0;
      return 0x8007000e;
    }
  }
  *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
  *(SIZE_T *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + param_3;
  iVar1 = FUN_404904d0(param_1 + 0x90,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  return 0x80004005;
}



/* 4048c0a0 FUN_4048c0a0 */

uint FUN_4048c0a0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 >> 0x18;
  if (uVar3 != 0xff) {
    if (uVar3 == 0) {
      param_1 = 0;
    }
    else {
      uVar2 = (param_1 >> 8 & 0xff) * uVar3 + 0x80;
      uVar1 = (param_1 & 0xff00ff) * uVar3 + 0x800080;
      param_1 = (uVar1 >> 8 & 0xff00ff) + uVar1 >> 8 & 0xff00ff | (uVar2 >> 8) + uVar2 & 0xff00 |
                uVar3 << 0x18;
    }
  }
  return param_1;
}



/* 4048c130 FUN_4048c130 */

/* Boundary evidence: original MIPS .pdata 4048c130..4048c23f. Semantic name remains unreviewed. */

undefined4 FUN_4048c130(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 == (int *)0x0) {
    param_2[1] = 0;
    *param_2 = 0;
    param_2[2] = *(int *)(param_1 + 0x10);
    param_2[3] = *(int *)(param_1 + 0x14);
  }
  else {
    if (((((*param_3 < 0) || (iVar1 = param_3[2], iVar1 < 0)) || (iVar1 <= *param_3)) ||
        ((*(int *)(param_1 + 0x10) < iVar1 || (param_3[1] < 0)))) ||
       ((iVar1 = param_3[3], iVar1 < 0 ||
        ((iVar1 <= param_3[1] || (*(int *)(param_1 + 0x14) < iVar1)))))) {
      return 0;
    }
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
    param_2[3] = param_3[3];
  }
  return 1;
}



/* 4048c240 FUN_4048c240 */

/* Boundary evidence: original MIPS .pdata 4048c240..4048c24b. Semantic name remains unreviewed. */

undefined4 FUN_4048c240(void)

{
  return 1;
}



/* 4048c24c FUN_4048c24c */

/* Boundary evidence: original MIPS .pdata 4048c24c..4048c2df. Semantic name remains unreviewed. */

undefined4 FUN_4048c24c(int param_1)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
  if (*(int *)(param_1 + 0xb0) != 1) {
    pHVar1 = LoadLibraryW(L"coredll.dll");
    *(HMODULE *)(param_1 + 0xb4) = pHVar1;
    if (pHVar1 != (HMODULE)0x0) {
      uVar2 = GetProcAddressW(pHVar1,L"AlphaBlend");
      *(undefined4 *)(param_1 + 0xb8) = uVar2;
    }
    *(undefined4 *)(param_1 + 0xb0) = 1;
  }
  uVar2 = *(undefined4 *)(param_1 + 0xb8);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2a4);
  return uVar2;
}



/* 4048c2e0 FUN_4048c2e0 */

/* Boundary evidence: original MIPS .pdata 4048c2e0..4048c3fb. Semantic name remains unreviewed. */

undefined4 FUN_4048c2e0(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,&DAT_404812ac,0x10);
  if (iVar1 == 0) {
LAB_4048c35c:
    *param_3 = param_1;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_4048129c,0x10);
    if (iVar1 == 0) {
      iVar1 = param_1 + 4;
    }
    else {
      iVar1 = memcmp(param_2,&DAT_40482c64,0x10);
      if (iVar1 == 0) goto LAB_4048c35c;
      iVar1 = memcmp(param_2,&DAT_404812ec,0x10);
      if (iVar1 == 0) {
        iVar1 = param_1 + 0xc;
      }
      else {
        iVar1 = memcmp(param_2,&DAT_404812dc,0x10);
        if (iVar1 != 0) {
          *param_3 = 0;
          return 0x80004002;
        }
        iVar1 = param_1 + 8;
      }
    }
    if (param_1 == 0) {
      iVar1 = 0;
    }
    *param_3 = iVar1;
  }
  (**(code **)(*(int *)*param_3 + 4))();
  return 0;
}



/* 4048c3fc FUN_4048c3fc */

/* Boundary evidence: original MIPS .pdata 4048c3fc..4048c50b. Semantic name remains unreviewed. */

void FUN_4048c3fc(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_1 = &PTR_FUN_404820c8;
  param_1[1] = &PTR_LAB_404820a4;
  param_1[2] = &PTR_LAB_40482068;
  param_1[3] = &PTR_LAB_40482040;
  if (param_1[0x2c] == 1) {
    FreeLibrary((HMODULE)param_1[0x2d]);
  }
  if ((LPVOID)param_1[0x14] != (LPVOID)0x0) {
    FUN_404962ec((LPVOID)param_1[0x14]);
  }
  FUN_4048bba8((int)param_1);
  InterlockedDecrement((LONG *)&DAT_404bd29c);
  if ((int *)param_1[0x19] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x19] + 8))();
  }
  if (param_1[0x2b] != 0) {
    iVar3 = 0;
    puVar2 = (undefined4 *)param_1[0x1e];
    if (0 < (int)param_1[0x2b]) {
      do {
        if (puVar2 == (undefined4 *)0x0) {
          return;
        }
        puVar1 = (undefined4 *)*puVar2;
        FUN_404962ec((LPVOID)puVar2[5]);
        FUN_404962ec(puVar2);
        iVar3 = iVar3 + 1;
        puVar2 = puVar1;
      } while (iVar3 < (int)param_1[0x2b]);
    }
  }
  return;
}



/* 4048c50c FUN_4048c50c */

/* Boundary evidence: original MIPS .pdata 4048c50c..4048c527. Semantic name remains unreviewed. */

void FUN_4048c50c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x28));
  return;
}



/* 4048c528 FUN_4048c528 */

/* Boundary evidence: original MIPS .pdata 4048c528..4048c583. Semantic name remains unreviewed. */

LONG FUN_4048c528(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 10);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x24))(param_1,1);
  }
  return LVar1;
}



/* 4048c5a0 FUN_4048c5a0 */

/* Boundary evidence: original MIPS .pdata 4048c5a0..4048c73b. Semantic name remains unreviewed. */

undefined4
FUN_4048c5a0(uint param_1,uint param_2,uint param_3,uint *param_4,undefined4 *param_5,int param_6)

{
  uint dwSize;
  longlong lVar1;
  void *_Dst;
  uint uVar2;
  
  lVar1 = (ulonglong)((int)param_3 >> 8 & 0xff) * (ulonglong)param_1;
  if ((int)((ulonglong)lVar1 >> 0x20) == 0) {
    uVar2 = ((int)lVar1 + 7U >> 3) + 3 & 0xfffffffc;
  }
  else {
    uVar2 = 0;
  }
  dwSize = (uint)((ulonglong)uVar2 * (ulonglong)param_2);
  if ((uVar2 != 0) && ((int)((ulonglong)uVar2 * (ulonglong)param_2 >> 0x20) == 0)) {
    if (dwSize < DAT_404bd390) {
      param_4[5] = param_4[5] | 0x10000;
      _Dst = (void *)FUN_404962c4(dwSize);
    }
    else {
      param_4[5] = param_4[5] | 0x20000;
      _Dst = VirtualAlloc((LPVOID)0x0,dwSize,0x3000,4);
    }
    param_4[4] = (uint)_Dst;
    if (_Dst != (void *)0x0) {
      if ((param_6 != 0) && (memset(_Dst,0,dwSize), param_5 != (undefined4 *)0x0)) {
        if ((param_3 & 0x40000) == 0) {
          if ((param_3 & 0x10000) == 0) {
            *param_5 = 5;
          }
          else {
            *param_5 = 0;
          }
        }
        else {
          *param_5 = 2;
        }
      }
      *param_4 = param_1;
      param_4[1] = param_2;
      param_4[2] = uVar2;
      param_4[3] = param_3;
      return 1;
    }
    param_4[5] = param_4[5] & 0xfffcffff;
  }
  return 0;
}



/* 4048c73c FUN_4048c73c */

/* Boundary evidence: original MIPS .pdata 4048c73c..4048c79f. Semantic name remains unreviewed. */

undefined4 FUN_4048c73c(int param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_1 + 0x10);
  if (param_1 == 0) {
    puVar3 = (uint *)0x0;
  }
  iVar1 = FUN_4048c5a0(param_2,param_3,param_4,puVar3,(undefined4 *)(param_1 + 0x68),param_5);
  if (iVar1 == 0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4048c7a0 FUN_4048c7a0 */

/* Boundary evidence: original MIPS .pdata 4048c7a0..4048c8df. Semantic name remains unreviewed. */

int FUN_4048c7a0(int param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  
  if ((((param_2 == 0) || (param_3 == 0)) || (uVar4 = param_4 & 0xff, 0xf < uVar4)) ||
     (*(uint *)(&DAT_40481ef0 + uVar4 * 8) != param_4)) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    uVar1 = (ulonglong)*(uint *)(&LAB_40481f6c + uVar4 * 4) * (ulonglong)param_2;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar4 = (((int)*(uint *)(&LAB_40481f6c + uVar4 * 4) >> 0x1f) * param_2 + (int)(uVar1 >> 0x20)) *
            param_3 + (int)((ulonglong)lVar2 >> 0x20);
    if ((uVar4 < 3) || ((uVar4 == 3 && (((uint)lVar2 & 0xfffffff8) < 0xfffffff9)))) {
      if (param_4 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_4048c73c(param_1,param_2,param_3,param_4,param_5);
      }
      if (-1 < iVar3) {
        *(undefined4 *)(param_1 + 0x48) = 1;
      }
    }
    else {
      iVar3 = -0x7ff8fff2;
    }
  }
  return iVar3;
}



/* 4048c8e0 FUN_4048c8e0 */

/* Boundary evidence: original MIPS .pdata 4048c8e0..4048cb9f. Semantic name remains unreviewed. */

int FUN_4048c8e0(int param_1,int *param_2,uint param_3,uint param_4,uint param_5,int param_6,
                undefined4 param_7,undefined4 param_8)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  undefined1 auStack_68 [56];
  uint local_30;
  uint local_28;
  
  local_28 = DAT_404bd274;
  if ((((param_5 != 0) &&
       ((0xf < (param_5 & 0xff) || (*(uint *)(&DAT_40481ef0 + (param_5 & 0xff) * 8) != param_5))))
      || ((param_3 == 0 && (param_4 != 0)))) || ((param_4 == 0 && (param_3 != 0)))) {
    FUN_404a438c(DAT_404bd274);
    return -0x7ff8ffa9;
  }
  uVar1 = (ulonglong)*(uint *)(&LAB_40481f6c + (param_5 & 0xff) * 4) * (ulonglong)param_3;
  lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_4;
  uVar5 = (((int)*(uint *)(&LAB_40481f6c + (param_5 & 0xff) * 4) >> 0x1f) * param_3 +
          (int)(uVar1 >> 0x20)) * param_4 + (int)((ulonglong)lVar2 >> 0x20);
  if ((2 < uVar5) && ((uVar5 != 3 || (0xfffffff8 < ((uint)lVar2 & 0xfffffff8))))) {
LAB_4048ca28:
    FUN_404a438c(local_28);
    return -0x7ff8fff2;
  }
  *(uint *)(param_1 + 0x10) = param_3;
  piVar7 = (int *)0x0;
  *(uint *)(param_1 + 0x14) = param_4;
  piVar8 = (int *)(param_1 + 8);
  *(uint *)(param_1 + 0x1c) = param_5;
  if ((param_3 != 0) || (param_4 != 0)) {
    iVar3 = (**(code **)(*param_2 + 0x10))(param_2,auStack_68);
    if ((iVar3 < 0) || ((local_30 & 1) == 0)) {
      puVar4 = (undefined4 *)FUN_404962c4(200);
      if (puVar4 == (undefined4 *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = FUN_4049432c(puVar4,piVar8,param_3,param_4,param_6);
      }
      piVar8 = piVar7;
      if (piVar7 == (int *)0x0) goto LAB_4048ca28;
    }
    *(uint *)(param_1 + 0x4c) = local_30;
  }
  *(undefined4 *)(param_1 + 0x70) = param_7;
  *(undefined4 *)(param_1 + 0x74) = param_8;
  iVar3 = (**(code **)(*param_2 + 0x1c))(param_2,piVar8);
  uVar6 = 2;
  if (-1 < iVar3) {
    *(undefined4 *)(param_1 + 0x48) = 2;
  }
  uVar5 = *(uint *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  if (((uVar5 & 0x40000) == 0) && ((uVar5 & 0x10000) == 0)) {
    uVar6 = 5;
  }
  else if (uVar5 != 0x61007) {
    *(undefined4 *)(param_1 + 0x68) = 0;
    goto LAB_4048cb54;
  }
  *(undefined4 *)(param_1 + 0x68) = uVar6;
LAB_4048cb54:
  if (piVar7 != (int *)0x0) {
    (**(code **)(*piVar7 + 0x3c))(piVar7,1);
  }
  FUN_404a438c(local_28);
  return iVar3;
}



/* 4048cba0 FUN_4048cba0 */

/* Boundary evidence: original MIPS .pdata 4048cba0..4048cca3. Semantic name remains unreviewed. */

undefined4 FUN_4048cba0(int param_1,int *param_2)

{
  void *_Dst;
  uint uVar1;
  uint uVar2;
  
  if ((((param_2 != (int *)0x0) && (*param_2 != 0)) && (param_2[1] != 0)) && (param_2[4] != 0)) {
    uVar2 = param_2[3];
    if ((((uVar2 & 0xff) < 0x10) && (*(uint *)(&DAT_40481ef0 + (uVar2 & 0xff) * 8) == uVar2)) &&
       ((param_2[5] == 0 &&
        (uVar1 = param_2[2] >> 0x1f,
        (param_2[2] ^ uVar1) - uVar1 ==
        ((*(int *)(&LAB_40481f6c + (uVar2 & 0xff) * 4) * *param_2 + 7U >> 3) + 3 & 0xfffffffc))))) {
      _Dst = (void *)(param_1 + 0x10);
      if (param_1 == 0) {
        _Dst = (void *)0x0;
      }
      memcpy(_Dst,param_2,0x18);
      *(undefined4 *)(param_1 + 0x48) = 3;
      return 0;
    }
  }
  return 0x80070057;
}



/* 4048cca4 FUN_4048cca4 */

/* Boundary evidence: original MIPS .pdata 4048cca4..4048cdfb. Semantic name remains unreviewed. */

undefined4 FUN_4048cca4(int param_1,undefined4 *param_2)

{
  LONG *lpAddend;
  undefined4 uVar1;
  undefined8 uVar2;
  int local_20;
  LONG *local_1c;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    local_1c = (LONG *)(param_1 + 0x28);
    if (local_1c == (LONG *)0x0) {
      local_1c = &local_20;
      local_20 = 0;
    }
    else {
      local_20 = InterlockedIncrement(local_1c);
    }
    lpAddend = local_1c;
    if (local_20 == 0) {
      uVar2 = __litodp(*(undefined4 *)(param_1 + 0xc));
      uVar2 = __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x40a3d800);
      uVar2 = __dpdiv((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),*(undefined4 *)(param_1 + 0x34),
                      *(undefined4 *)(param_1 + 0x38));
      uVar2 = __dpadd((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x3fe00000);
      uVar1 = __dptoli((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
      *param_2 = uVar1;
      uVar2 = __litodp(*(undefined4 *)(param_1 + 0x10));
      uVar2 = __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x40a3d800);
      uVar2 = __dpdiv((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),*(undefined4 *)(param_1 + 0x3c),
                      *(undefined4 *)(param_1 + 0x40));
      uVar2 = __dpadd((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x3fe00000);
      uVar1 = __dptoli((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
      param_2[1] = uVar1;
      uVar1 = 0;
    }
    else {
      uVar1 = 0x887b0001;
    }
    InterlockedDecrement(lpAddend);
  }
  return uVar1;
}



/* 4048cdfc FUN_4048cdfc */

/* Boundary evidence: original MIPS .pdata 4048cdfc..4048cf1b. Semantic name remains unreviewed. */

undefined4 FUN_4048cdfc(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int local_18;
  LONG *local_14;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar2 = 0x80004005;
  }
  else {
    local_14 = (LONG *)(param_1 + 0x28);
    if (local_14 == (LONG *)0x0) {
      local_14 = &local_18;
      local_18 = 0;
    }
    else {
      local_18 = InterlockedIncrement(local_14);
    }
    if (local_18 == 0) {
      *param_2 = 0xb96b3caa;
      param_2[1] = 0x11d30728;
      param_2[2] = 0x7b9d;
      param_2[3] = 0x2ef31ef8;
      param_2[4] = *(undefined4 *)(param_1 + 0x18);
      uVar2 = *(undefined4 *)(param_1 + 0xc);
      param_2[7] = uVar2;
      param_2[5] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x10);
      param_2[8] = uVar2;
      param_2[6] = uVar2;
      param_2[10] = *(undefined4 *)(param_1 + 0x34);
      param_2[0xb] = *(undefined4 *)(param_1 + 0x38);
      param_2[0xc] = *(undefined4 *)(param_1 + 0x3c);
      param_2[0xd] = *(undefined4 *)(param_1 + 0x40);
      uVar1 = *(uint *)(param_1 + 0x48);
      if (((*(uint *)(param_1 + 0x18) & 0x40000) != 0) ||
         ((*(uint *)(param_1 + 0x18) & 0x10000) != 0)) {
        uVar1 = uVar1 | 2;
      }
      param_2[0xe] = uVar1;
      uVar2 = 0;
    }
    else {
      uVar2 = 0x887b0001;
    }
    InterlockedDecrement(local_14);
  }
  return uVar2;
}



/* 4048cf1c FUN_4048cf1c */

/* Boundary evidence: original MIPS .pdata 4048cf1c..4048cfcb. Semantic name remains unreviewed. */

undefined4 FUN_4048cf1c(int param_1,uint param_2)

{
  undefined4 uVar1;
  int local_18;
  LONG *local_14;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar1 = 0x80004005;
  }
  else if ((param_2 & 0xfffcffff) == 0) {
    local_14 = (LONG *)(param_1 + 0x28);
    if (local_14 == (LONG *)0x0) {
      local_14 = &local_18;
      local_18 = 0;
    }
    else {
      local_18 = InterlockedIncrement(local_14);
    }
    if (local_18 == 0) {
      *(uint *)(param_1 + 0x48) = param_2;
      uVar1 = 0;
    }
    else {
      uVar1 = 0x887b0001;
    }
    InterlockedDecrement(local_14);
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



/* 4048cfcc FUN_4048cfcc */

/* Boundary evidence: original MIPS .pdata 4048cfcc..4048d5eb. Semantic name remains unreviewed. */

DWORD FUN_4048cfcc(int param_1,HDC param_2,int *param_3,int *param_4)

{
  int iVar1;
  bool bVar2;
  code *pcVar3;
  uint *puVar4;
  HDC hdc;
  HBITMAP h;
  undefined *puVar5;
  HGDIOBJ h_00;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined *puVar9;
  DWORD DVar10;
  uint uVar11;
  HDC pHVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  uint *local_494;
  HDC local_490;
  int *local_48c;
  int *local_488;
  int local_480;
  undefined4 local_47c;
  int local_478;
  undefined4 local_474;
  uint *local_470;
  undefined4 local_46c;
  int local_468;
  undefined4 local_464;
  undefined4 local_460;
  uint local_45c;
  undefined4 local_458;
  undefined4 local_454;
  BITMAPINFO local_450;
  undefined4 local_424;
  undefined4 local_420;
  
  local_490 = param_2;
  local_48c = param_4;
  local_488 = param_3;
  pcVar3 = (code *)FUN_4048c24c(param_1);
  uVar13 = *(uint *)(param_1 + 0x1c);
  DVar10 = 0;
  uVar11 = (int)uVar13 >> 8 & 0xff;
  if (uVar11 == 0) {
    return 0x80004005;
  }
  uVar14 = *(uint *)(param_1 + 0x10);
  iVar8 = *(int *)(param_1 + 0x14);
  uVar6 = *(uint *)(param_1 + 0x18);
  uVar7 = (uVar14 * uVar11 + 7 >> 3) + 3 & 0xfffffffc;
  bVar2 = false;
  if ((int)uVar6 < 1) {
    iVar1 = (iVar8 + -1) * uVar6;
    uVar6 = -uVar6;
    local_494 = (uint *)local_48c[1];
    puVar15 = (uint *)(iVar1 + *(int *)(param_1 + 0x20));
  }
  else {
    puVar15 = *(uint **)(param_1 + 0x20);
    local_494 = (uint *)(iVar8 - local_48c[3]);
    iVar8 = -iVar8;
  }
  if ((uVar6 != uVar7) && (uVar14 = (uVar7 << 3) / uVar11, uVar11 == 0)) {
    trap(0x1c00);
  }
  memset(&local_450,0,0x28);
  local_450.bmiHeader.biSize = 0x28;
  local_450.bmiHeader.biPlanes = 1;
  local_450.bmiHeader.biBitCount = (WORD)uVar11;
  local_450.bmiHeader.biCompression = 0;
  local_450.bmiHeader.biWidth = uVar14;
  local_450.bmiHeader.biHeight = iVar8;
  if ((uVar13 & 0x10000) == 0) {
    if (uVar11 == 0x10) {
      local_450.bmiHeader.biCompression = 3;
      if (uVar13 == 0x21006) {
        local_450.bmiColors[0].rgbBlue = '\0';
        local_450.bmiColors[0].rgbGreen = 0xf8;
        local_450.bmiColors[0].rgbRed = '\0';
        local_450.bmiColors[0].rgbReserved = '\0';
        local_424 = 0x7e0;
        local_420 = 0x1f;
      }
      else if ((uVar13 == 0x61007) && (pcVar3 != (code *)0x0)) {
        local_450.bmiHeader.biBitCount = 0x20;
        local_450.bmiHeader.biCompression = 0;
      }
      else {
        local_450.bmiColors[0].rgbBlue = '\0';
        local_450.bmiColors[0].rgbGreen = '|';
        local_450.bmiColors[0].rgbRed = '\0';
        local_450.bmiColors[0].rgbReserved = '\0';
        local_424 = 0x3e0;
        local_420 = 0x1f;
      }
    }
  }
  else {
    puVar4 = *(uint **)(param_1 + 0x50);
    if ((puVar4 == (uint *)0x0) && (puVar4 = (uint *)FUN_404905b8(uVar13), puVar4 == (uint *)0x0)) {
      return 0x80004005;
    }
    if (((*puVar4 & 1) == 0) || (pcVar3 == (code *)0x0)) {
      if (puVar4[1] < 0x101) {
        memcpy(local_450.bmiColors,puVar4 + 2,puVar4[1] << 2);
      }
    }
    else {
      local_450.bmiHeader.biBitCount = 0x20;
      bVar2 = true;
    }
  }
  pHVar12 = local_490;
  if ((pcVar3 == (code *)0x0) ||
     (((*(int *)(param_1 + 0x1c) != 0x26200a && (*(int *)(param_1 + 0x1c) != 0x61007)) && (!bVar2)))
     ) {
    iVar8 = StretchDIBits(local_490,*local_488,local_488[1],local_488[2] - *local_488,
                          local_488[3] - local_488[1],*local_48c,(int)local_494,
                          local_48c[2] - *local_48c,local_48c[3] - local_48c[1],puVar15,&local_450,0
                          ,0xcc0020);
    if (iVar8 != 0) {
      return 0;
    }
  }
  else {
    hdc = CreateCompatibleDC(local_490);
    if ((hdc != (HDC)0x0) &&
       (h = CreateDIBSection(hdc,&local_450,0,&local_494,(HANDLE)0x0,0), h != (HBITMAP)0x0)) {
      uVar11 = *(uint *)(param_1 + 0x1c);
      if (uVar11 == 0x26200a) {
        uVar11 = 0;
        pHVar12 = local_490;
        if (*(int *)(param_1 + 0x14) != 0) {
          uVar13 = *(uint *)(param_1 + 0x10);
          puVar4 = local_494;
          do {
            uVar6 = 0;
            if (uVar13 != 0) {
              do {
                uVar13 = FUN_4048c0a0(*puVar15);
                uVar6 = uVar6 + 1;
                puVar15 = puVar15 + 1;
                *puVar4 = uVar13;
                uVar13 = *(uint *)(param_1 + 0x10);
                puVar4 = puVar4 + 1;
              } while (uVar6 < uVar13);
            }
            uVar11 = uVar11 + 1;
            pHVar12 = local_490;
          } while (uVar11 < *(uint *)(param_1 + 0x14));
        }
      }
      else if (uVar11 == 0x61007) {
        uVar11 = 0;
        puVar4 = local_494;
        if (*(int *)(param_1 + 0x14) != 0) {
          do {
            uVar13 = 0;
            if (*(int *)(param_1 + 0x10) != 0) {
              do {
                uVar6 = (uint)(ushort)*puVar15;
                if (((ushort)*puVar15 & 0x8000) == 0) {
                  *puVar4 = 0;
                }
                else {
                  *puVar4 = ((uVar6 & 0x7c00 | 0xfffc0000) << 3 | uVar6 & 0x3e0) << 3 | uVar6 & 0x1f
                  ;
                }
                uVar13 = uVar13 + 1;
                puVar4 = puVar4 + 1;
                puVar15 = (uint *)((int)puVar15 + 2);
              } while (uVar13 < *(uint *)(param_1 + 0x10));
            }
            uVar11 = uVar11 + 1;
          } while (uVar11 < *(uint *)(param_1 + 0x14));
        }
      }
      else {
        local_458 = *(undefined4 *)(param_1 + 0x20);
        local_47c = *(undefined4 *)(param_1 + 0x14);
        local_480 = *(int *)(param_1 + 0x10);
        local_460 = *(undefined4 *)(param_1 + 0x18);
        local_478 = local_480 << 2;
        puVar9 = *(undefined **)(param_1 + 0x50);
        local_454 = 0;
        local_470 = local_494;
        local_474 = 0x26200a;
        local_46c = 0;
        local_468 = local_480;
        local_464 = local_47c;
        local_45c = uVar11;
        if (puVar9 == (undefined *)0x0) {
          if ((uVar11 & 0x10000) == 0) {
            puVar9 = (undefined *)0x0;
          }
          else {
            puVar9 = FUN_404905b8(uVar11);
          }
        }
        puVar5 = FUN_404906e0(puVar9,0);
        if (puVar5 == (undefined *)0x0) goto LAB_4048d594;
        uVar11 = 0;
        if (*(int *)(puVar9 + 4) != 0) {
          puVar15 = (uint *)(puVar9 + 8);
          do {
            if ((*puVar15 & 0xff000000) != 0xff000000) {
              uVar13 = FUN_4048c0a0(*puVar15);
              *(uint *)(((int)puVar5 - (int)puVar9) + (int)puVar15) = uVar13;
            }
            uVar11 = uVar11 + 1;
            puVar15 = puVar15 + 1;
          } while (uVar11 < *(uint *)(puVar9 + 4));
        }
        DVar10 = FUN_40494f0c((int)&local_480,(undefined *)0x0,&local_468,puVar5);
        FUN_404962ec(puVar5);
        pHVar12 = local_490;
        if ((int)DVar10 < 0) goto LAB_4048d594;
      }
      h_00 = SelectObject(hdc,h);
      if ((h_00 != (HGDIOBJ)0x0) &&
         (iVar8 = (*pcVar3)(pHVar12,*local_488,local_488[1],local_488[2] - *local_488,
                            local_488[3] - local_488[1],hdc,*local_48c,local_48c[1],
                            local_48c[2] - *local_48c,local_48c[3] - local_48c[1]), iVar8 != 0)) {
        SelectObject(hdc,h_00);
        DeleteObject(h);
        DeleteDC(hdc);
        return DVar10;
      }
    }
  }
LAB_4048d594:
  DVar10 = GetLastError();
  if (0 < (int)DVar10) {
    DVar10 = DVar10 & 0xffff | 0x80070000;
  }
  return DVar10;
}



/* 4048d5ec FUN_4048d5ec */

/* Boundary evidence: original MIPS .pdata 4048d5ec..4048d687. Semantic name remains unreviewed. */

undefined4 FUN_4048d5ec(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int local_18;
  LONG *local_14;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    local_14 = (LONG *)(param_1 + 0x2c);
    if (local_14 == (LONG *)0x0) {
      local_14 = &local_18;
      local_18 = 0;
    }
    else {
      local_18 = InterlockedIncrement(local_14);
    }
    if (local_18 == 0) {
      *param_2 = *(undefined4 *)(param_1 + 0x10);
      uVar1 = 0;
      param_2[1] = *(undefined4 *)(param_1 + 0x14);
    }
    else {
      uVar1 = 0x887b0001;
    }
    InterlockedDecrement(local_14);
  }
  return uVar1;
}



/* 4048d688 FUN_4048d688 */

/* Boundary evidence: original MIPS .pdata 4048d688..4048d87b. Semantic name remains unreviewed. */

int FUN_4048d688(int param_1,int *param_2,uint param_3,uint param_4,uint *param_5)

{
  undefined *puVar1;
  int iVar2;
  void *_Dst;
  uint uVar3;
  void *_Src;
  int iVar4;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  void *local_28;
  undefined4 local_24;
  
  iVar4 = *param_2;
  local_38 = param_2[2] - iVar4;
  local_2c = *(int *)(param_1 + 0x1c);
  local_34 = param_2[3] - param_2[1];
  local_30 = *(uint *)(param_1 + 0x18);
  local_24 = 0;
  local_28 = (void *)(((local_2c >> 8 & 0xffU) * iVar4 >> 3) + local_30 * param_2[1] +
                     *(int *)(param_1 + 0x20));
  if (param_4 == 0) {
    param_4 = *(uint *)(param_1 + 0x1c);
  }
  iVar2 = *(int *)(param_1 + 0x1c);
  *param_5 = local_38;
  param_5[1] = local_34;
  param_5[3] = param_4;
  param_5[5] = param_3;
  uVar3 = (iVar2 >> 8) * iVar4 & 7;
  if ((param_4 == *(uint *)(param_1 + 0x1c)) && (uVar3 == 0)) {
    if ((param_3 & 4) == 0) {
      param_5[4] = (uint)local_28;
      param_5[2] = local_30;
    }
    else if ((param_3 & 1) != 0) {
      iVar4 = ((int)param_4 >> 8 & 0xffU) * local_38;
      _Dst = (void *)param_5[4];
      _Src = local_28;
      for (uVar3 = local_34; uVar3 != 0; uVar3 = uVar3 - 1) {
        memcpy(_Dst,_Src,iVar4 + 7U >> 3);
        _Src = (void *)((int)_Src + local_30);
        _Dst = (void *)(param_5[2] + (int)_Dst);
      }
    }
  }
  else {
    if (((param_3 & 4) == 0) &&
       (iVar4 = FUN_4048c5a0(local_38,local_34,param_4,param_5,(undefined4 *)0x0,0), iVar4 == 0)) {
      return -0x7ff8fff2;
    }
    if ((param_3 & 1) != 0) {
      puVar1 = *(undefined **)(param_1 + 0x50);
      if (uVar3 == 0) {
        iVar4 = FUN_40494f0c((int)param_5,puVar1,(int *)&local_38,puVar1);
      }
      else {
        iVar4 = FUN_40494fcc((int)param_5,puVar1,(int *)&local_38,puVar1,uVar3);
      }
      if (-1 < iVar4) {
        return iVar4;
      }
      FUN_4048bb50((int)param_5);
      return iVar4;
    }
  }
  return 0;
}



/* 4048d87c FUN_4048d87c */

/* Boundary evidence: original MIPS .pdata 4048d87c..4048d9ff. Semantic name remains unreviewed. */

int FUN_4048d87c(int param_1,int *param_2,int *param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  
  if ((param_3[5] & 2U) == 0) {
    iVar3 = 0;
  }
  else {
    if ((param_3[5] & 0x30004U) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *param_2;
      local_1c = *(int *)(param_1 + 0x1c);
      local_28 = param_2[2] - iVar3;
      local_20 = *(int *)(param_1 + 0x18);
      local_24 = param_2[3] - param_2[1];
      puVar1 = *(undefined **)(param_1 + 0x50);
      local_14 = 0;
      local_18 = ((local_1c >> 8 & 0xffU) * iVar3 >> 3) + local_20 * param_2[1] +
                 *(int *)(param_1 + 0x20);
      uVar2 = (local_1c >> 8) * iVar3 & 7;
      if (uVar2 == 0) {
        iVar3 = FUN_40494f0c((int)&local_28,puVar1,param_3,puVar1);
      }
      else {
        iVar3 = FUN_40495148(&local_28,puVar1,param_3,puVar1,uVar2);
      }
    }
    uVar2 = *(uint *)(param_1 + 0x1c);
    if ((((uVar2 & 0x40000) == 0) && ((uVar2 & 0x10000) == 0)) ||
       (((param_3[3] & 0x40000U) == 0 && ((param_3[3] & 0x10000U) == 0)))) {
      *(undefined4 *)(param_1 + 0x68) = 5;
    }
    else if (uVar2 == 0x61007) {
      *(undefined4 *)(param_1 + 0x68) = 2;
    }
    else {
      *(undefined4 *)(param_1 + 0x68) = 0;
    }
  }
  FUN_4048bb50((int)param_3);
  return iVar3;
}



/* 4048da00 FUN_4048da00 */

/* Boundary evidence: original MIPS .pdata 4048da00..4048db2b. Semantic name remains unreviewed. */

undefined4 FUN_4048da00(int param_1,void *param_2)

{
  void *pvVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_18;
  LONG *local_14;
  
  if (param_2 == (void *)0x0) {
    uVar4 = 0x80070057;
  }
  else {
    pvVar1 = FUN_404906e0(param_2,0);
    if (pvVar1 == (void *)0x0) {
      uVar4 = 0x8007000e;
    }
    else {
      local_14 = (LONG *)(param_1 + 0x2c);
      if (local_14 == (LONG *)0x0) {
        local_14 = &local_18;
        local_18 = 0;
      }
      else {
        local_18 = InterlockedIncrement(local_14);
      }
      if (local_18 == 0) {
        if (*(LPVOID *)(param_1 + 0x50) != (LPVOID)0x0) {
          FUN_404962ec(*(LPVOID *)(param_1 + 0x50));
        }
        *(void **)(param_1 + 0x50) = pvVar1;
        *(undefined4 *)(param_1 + 0x68) = 3;
        uVar3 = 0;
        if (*(int *)((int)pvVar1 + 4) != 0) {
          puVar2 = (uint *)((int)pvVar1 + 8);
          do {
            if ((*puVar2 & 0xff000000) != 0xff000000) {
              if ((*puVar2 & 0xff000000) != 0) {
                *(undefined4 *)(param_1 + 0x68) = 1;
                break;
              }
              *(undefined4 *)(param_1 + 0x68) = 2;
            }
            uVar3 = uVar3 + 1;
            puVar2 = puVar2 + 1;
          } while (uVar3 < *(uint *)((int)pvVar1 + 4));
        }
        uVar4 = 0;
      }
      else {
        FUN_404962ec(pvVar1);
        uVar4 = 0x887b0001;
      }
      InterlockedDecrement(local_14);
    }
  }
  return uVar4;
}



/* 4048db2c FUN_4048db2c */

/* Boundary evidence: original MIPS .pdata 4048db2c..4048dc0b. Semantic name remains unreviewed. */

undefined4 FUN_4048db2c(int param_1,undefined4 *param_2)

{
  undefined *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  int local_18;
  LONG *local_14;
  
  local_14 = (LONG *)(param_1 + 0x2c);
  *param_2 = 0;
  if (local_14 == (LONG *)0x0) {
    local_14 = &local_18;
    local_18 = 0;
  }
  else {
    local_18 = InterlockedIncrement(local_14);
  }
  if (local_18 == 0) {
    puVar1 = *(undefined **)(param_1 + 0x50);
    if (puVar1 == (undefined *)0x0) {
      if ((*(uint *)(param_1 + 0x1c) & 0x10000) == 0) {
        puVar1 = (undefined *)0x0;
      }
      else {
        puVar1 = FUN_404905b8(*(uint *)(param_1 + 0x1c));
      }
      if (puVar1 == (undefined *)0x0) {
        uVar3 = 0x887b0002;
        goto LAB_4048dbec;
      }
    }
    pvVar2 = FUN_404906e0(puVar1,1);
    *param_2 = pvVar2;
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0x8007000e;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0x887b0001;
  }
LAB_4048dbec:
  InterlockedDecrement(local_14);
  return uVar3;
}



/* 4048dc0c FUN_4048dc0c */

/* Boundary evidence: original MIPS .pdata 4048dc0c..4048df17. Semantic name remains unreviewed. */

int FUN_4048dc0c(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  *param_2 = 0xb96b3caa;
  param_2[1] = 0x11d30728;
  param_2[2] = 0x7b9d;
  param_2[3] = 0x2ef31ef8;
  uVar3 = *(uint *)(param_1 + 0x14);
  if (uVar3 == 0) {
    uVar3 = param_2[4];
  }
  if ((0xf < (uVar3 & 0xff)) || (*(uint *)(&DAT_40481ef0 + (uVar3 & 0xff) * 8) != uVar3)) {
    return -0x7ff8ffa9;
  }
  if (((uVar3 & 0x40000) == 0) && ((uVar3 & 0x10000) == 0)) {
    param_2[0xe] = param_2[0xe] & 0xfffffffd;
  }
  else {
    param_2[0xe] = param_2[0xe] | 2;
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    param_2[0xe] = param_2[0xe] & 0xffefffff;
  }
  uVar2 = param_2[0xe];
  param_2[0xe] = uVar2 & 0xfff7ffff;
  iVar4 = *(int *)(param_1 + 8);
  if ((iVar4 != 0) || (bVar1 = true, *(int *)(param_1 + 0xc) != 0)) {
    bVar1 = false;
  }
  uVar2 = uVar2 & 9;
  if (bVar1) {
    if (uVar2 != 0) {
      *(undefined4 *)(param_1 + 8) = param_2[5];
      *(undefined4 *)(param_1 + 0xc) = param_2[6];
      param_2[10] = *(undefined4 *)(param_1 + 0x30);
      param_2[0xb] = *(undefined4 *)(param_1 + 0x34);
      param_2[0xc] = *(undefined4 *)(param_1 + 0x38);
      param_2[0xd] = *(undefined4 *)(param_1 + 0x3c);
      goto LAB_4048de90;
    }
  }
  else {
    iVar5 = param_2[5];
    if ((iVar4 != iVar5) || (*(int *)(param_1 + 0xc) != param_2[6])) {
      if (uVar2 == 0) {
        return -0x7ff8ffa9;
      }
      uVar6 = __ultodp(iVar4);
      uVar6 = __dpmul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),param_2[10],param_2[0xb]);
      uVar7 = __ultodp(iVar5);
      uVar6 = __dpdiv((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,
                      (int)((ulonglong)uVar7 >> 0x20));
      *(undefined8 *)(param_1 + 0x30) = uVar6;
      uVar6 = __ultodp(*(undefined4 *)(param_1 + 0xc));
      uVar6 = __dpmul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),param_2[0xc],param_2[0xd]);
      uVar7 = __ultodp(param_2[6]);
      uVar6 = __dpdiv((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,
                      (int)((ulonglong)uVar7 >> 0x20));
      *(undefined8 *)(param_1 + 0x38) = uVar6;
      param_2[5] = iVar4;
      param_2[6] = *(undefined4 *)(param_1 + 0xc);
      param_2[10] = *(undefined4 *)(param_1 + 0x30);
      param_2[0xb] = *(undefined4 *)(param_1 + 0x34);
      param_2[0xc] = *(undefined4 *)(param_1 + 0x38);
      param_2[0xd] = *(undefined4 *)(param_1 + 0x3c);
      goto LAB_4048de90;
    }
  }
  *(undefined4 *)(param_1 + 8) = param_2[5];
  *(undefined4 *)(param_1 + 0xc) = param_2[6];
  *(undefined4 *)(param_1 + 0x30) = param_2[10];
  *(undefined4 *)(param_1 + 0x34) = param_2[0xb];
  *(undefined4 *)(param_1 + 0x38) = param_2[0xc];
  *(undefined4 *)(param_1 + 0x3c) = param_2[0xd];
LAB_4048de90:
  if ((*(int *)(param_1 + 0x18) == 0) &&
     (iVar4 = FUN_4048c73c(param_1 + -8,*(uint *)(param_1 + 8),*(uint *)(param_1 + 0xc),uVar3,0),
     iVar4 < 0)) {
    return iVar4;
  }
  if (param_3 != (undefined4 *)0x0) {
    param_3[1] = 0;
    *param_3 = 0;
    param_3[2] = *(undefined4 *)(param_1 + 8);
    param_3[3] = *(undefined4 *)(param_1 + 0xc);
  }
  return 0;
}



/* 4048df18 FUN_4048df18 */

/* Boundary evidence: original MIPS .pdata 4048df18..4048df67. Semantic name remains unreviewed. */

undefined4
FUN_4048df18(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x8000ffff;
  }
  else {
    uVar1 = (**(code **)(*(int *)(param_1 + -8) + 0x14))
                      ((int *)(param_1 + -8),param_2,2,param_3,param_5);
  }
  return uVar1;
}



/* 4048df68 FUN_4048df68 */

/* Boundary evidence: original MIPS .pdata 4048df68..4048dfab. Semantic name remains unreviewed. */

undefined4 FUN_4048df68(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x8000ffff;
  }
  else {
    uVar1 = (**(code **)(*(int *)(param_1 + -8) + 0x18))();
  }
  return uVar1;
}



/* 4048dfac FUN_4048dfac */

/* Boundary evidence: original MIPS .pdata 4048dfac..4048e0d3. Semantic name remains unreviewed. */

int FUN_4048dfac(int param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int local_48;
  LONG *local_44;
  int aiStack_40 [4];
  uint auStack_30 [3];
  uint local_24;
  
  if (*(int *)((int)param_3 + 0xc) == 0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    local_44 = (LONG *)(param_1 + 0x24);
    if (local_44 == (LONG *)0x0) {
      local_44 = &local_48;
      local_48 = 0;
    }
    else {
      local_48 = InterlockedIncrement(local_44);
    }
    if (local_48 == 0) {
      if (*(int *)(param_1 + 0x18) == 0) {
        iVar1 = -0x7fff0001;
      }
      else {
        iVar2 = param_1 + -8;
        iVar1 = FUN_4048c130(iVar2,aiStack_40,param_2);
        if (iVar1 == 0) {
          iVar1 = -0x7ff8ffa9;
        }
        else {
          memcpy(auStack_30,param_3,0x18);
          iVar1 = FUN_4048d688(iVar2,aiStack_40,6,local_24,auStack_30);
          if (-1 < iVar1) {
            iVar1 = FUN_4048d87c(iVar2,aiStack_40,(int *)auStack_30);
          }
        }
      }
    }
    else {
      iVar1 = -0x7784ffff;
    }
    InterlockedDecrement(local_44);
  }
  return iVar1;
}



/* 4048e19c FUN_4048e19c */

/* Boundary evidence: original MIPS .pdata 4048e19c..4048e36f. Semantic name remains unreviewed. */

undefined4 * FUN_4048e19c(undefined4 *param_1)

{
  HDC hdc;
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  param_1[1] = &PTR_LAB_404816c8;
  param_1[2] = &PTR_LAB_40481fdc;
  param_1[3] = &PTR_LAB_40482018;
  *param_1 = &PTR_FUN_404820c8;
  param_1[1] = &PTR_LAB_404820a4;
  param_1[2] = &PTR_LAB_40482068;
  param_1[3] = &PTR_LAB_40482040;
  param_1[0xb] = 0xffffffff;
  param_1[8] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[10] = 1;
  param_1[0xc] = 0xffffffff;
  hdc = GetDC((HWND)0x0);
  if (hdc != (HDC)0x0) {
    iVar1 = GetDeviceCaps(hdc,0x58);
    uVar2 = __litofp(iVar1);
    uVar3 = __fptodp(uVar2);
    *(undefined8 *)(param_1 + 0xe) = uVar3;
    iVar1 = __led((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0);
    if (iVar1 == 0) {
      iVar1 = GetDeviceCaps(hdc,0x5a);
      uVar2 = __litofp(iVar1);
      uVar3 = __fptodp(uVar2);
      *(undefined8 *)(param_1 + 0x10) = uVar3;
      iVar1 = __led((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0);
      if (iVar1 == 0) goto LAB_4048e2d8;
    }
  }
  param_1[0xe] = 0;
  param_1[0xf] = 0x40580000;
  param_1[0x10] = 0;
  param_1[0x11] = 0x40580000;
LAB_4048e2d8:
  ReleaseDC((HWND)0x0,hdc);
  param_1[0x1e] = param_1 + 0x24;
  param_1[0x25] = param_1 + 0x1e;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  *(undefined2 *)(param_1 + 0x22) = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  *(undefined2 *)(param_1 + 0x28) = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  InterlockedIncrement((LONG *)&DAT_404bd29c);
  return param_1;
}



/* 4048e370 FUN_4048e370 */

/* Boundary evidence: original MIPS .pdata 4048e370..4048e3bb. Semantic name remains unreviewed. */

undefined4 * FUN_4048e370(undefined4 *param_1,uint param_2)

{
  FUN_4048c3fc(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 4048e3bc FUN_4048e3bc */

/* Boundary evidence: original MIPS .pdata 4048e3bc..4048e49f. Semantic name remains unreviewed. */

int FUN_4048e3bc(int *param_1,uint param_2,uint param_3,uint param_4,int param_5,undefined4 *param_6
                ,undefined4 param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)FUN_404962c4(0xc0);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_4048e19c(puVar1);
  }
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ff8fff2;
  }
  else {
    iVar3 = FUN_4048c8e0((int)piVar2,param_1,param_2,param_3,param_4,param_5,param_7,param_8);
    if (iVar3 < 0) {
      (**(code **)(*piVar2 + 0x24))(piVar2,1);
    }
    else {
      *param_6 = piVar2;
    }
  }
  return iVar3;
}



/* 4048e4a0 FUN_4048e4a0 */

/* Boundary evidence: original MIPS .pdata 4048e4a0..4048e73f. Semantic name remains unreviewed. */

DWORD FUN_4048e4a0(int param_1,HDC param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined8 uVar7;
  int local_50;
  LONG *local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int aiStack_38 [4];
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    DVar2 = 0x80004005;
  }
  else {
    local_4c = (LONG *)(param_1 + 0x28);
    if (local_4c == (LONG *)0x0) {
      local_4c = &local_50;
      local_50 = 0;
    }
    else {
      local_50 = InterlockedIncrement(local_4c);
    }
    if (local_50 == 0) {
      piVar6 = (int *)0x0;
      if (param_4 != (undefined4 *)0x0) {
        uVar5 = *(undefined4 *)(param_1 + 0x34);
        uVar3 = *(undefined4 *)(param_1 + 0x38);
        uVar7 = __litodp(*param_4);
        uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar5,uVar3);
        uVar7 = __dpdiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x40a3d800);
        uVar7 = __dpadd((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x3fe00000);
        local_48 = __dptoli((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
        uVar7 = __litodp(param_4[2]);
        uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar5,uVar3);
        uVar7 = __dpdiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x40a3d800);
        uVar7 = __dpadd((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x3fe00000);
        local_40 = __dptoli((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
        uVar5 = *(undefined4 *)(param_1 + 0x3c);
        uVar3 = *(undefined4 *)(param_1 + 0x40);
        uVar7 = __litodp(param_4[1]);
        uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar5,uVar3);
        uVar7 = __dpdiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x40a3d800);
        uVar7 = __dpadd((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x3fe00000);
        local_44 = __dptoli((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
        uVar7 = __litodp(param_4[3]);
        uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar5,uVar3);
        uVar7 = __dpdiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x40a3d800);
        uVar7 = __dpadd((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x3fe00000);
        local_3c = __dptoli((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
        piVar6 = &local_48;
      }
      iVar4 = param_1 + -4;
      iVar1 = FUN_4048c130(iVar4,aiStack_38,piVar6);
      if (iVar1 == 0) {
        DVar2 = 0x80070057;
      }
      else if ((*(uint *)(param_1 + 0x18) & 0x20000) == 0) {
        DVar2 = FUN_4048e740(iVar4,param_2,param_3,aiStack_38);
      }
      else {
        DVar2 = FUN_4048cfcc(iVar4,param_2,param_3,aiStack_38);
      }
    }
    else {
      DVar2 = 0x887b0001;
    }
    InterlockedDecrement(local_4c);
  }
  return DVar2;
}



/* 4048e740 FUN_4048e740 */

/* Boundary evidence: original MIPS .pdata 4048e740..4048e9d3. Semantic name remains unreviewed. */

int FUN_4048e740(int param_1,HDC param_2,int *param_3,int *param_4)

{
  DWORD DVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint local_110;
  uint local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 uStack_e8;
  undefined1 auStack_e4 [20];
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  
  FUN_4048e19c(&uStack_e8);
  uVar5 = param_4[2] - *param_4;
  uVar6 = param_4[3] - param_4[1];
  DVar1 = FUN_4048c7a0((int)&uStack_e8,uVar5,uVar6,0x26200a,0);
  if (-1 < (int)DVar1) {
    local_104 = local_cc;
    local_108 = local_d0;
    local_fc = 0;
    local_100 = local_c8;
    local_110 = uVar5;
    local_10c = uVar6;
    DVar1 = FUN_4048d688(param_1,param_4,5,0x26200a,&local_110);
    if (-1 < (int)DVar1) {
      FUN_4048d87c(param_1,param_4,(int *)&local_110);
    }
  }
  uVar7 = __dpmul(0,0,0,0x40a3d800);
  uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar4 = *(undefined4 *)(param_1 + 0x38);
  uVar3 = *(undefined4 *)(param_1 + 0x3c);
  uVar8 = __dpdiv((int)uVar7,uVar2,uVar4,uVar3);
  uVar8 = __dpadd((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0x3fe00000);
  local_f8 = __dptoli((int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
  uVar8 = __litodp(uVar5);
  uVar8 = __dpmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0x40a3d800);
  uVar8 = __dpdiv((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar4,uVar3);
  uVar8 = __dpadd((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0x3fe00000);
  local_f0 = __dptoli((int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
  uVar4 = *(undefined4 *)(param_1 + 0x40);
  uVar3 = *(undefined4 *)(param_1 + 0x44);
  uVar7 = __dpdiv((int)uVar7,uVar2,uVar4,uVar3);
  uVar7 = __dpadd((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x3fe00000);
  local_f4 = __dptoli((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
  uVar7 = __litodp(uVar6);
  uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x40a3d800);
  uVar7 = __dpdiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar4,uVar3);
  uVar7 = __dpadd((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x3fe00000);
  local_ec = __dptoli((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
  if (-1 < (int)DVar1) {
    DVar1 = FUN_4048e4a0((int)auStack_e4,param_2,param_3,&local_f8);
  }
  FUN_4048c3fc(&uStack_e8);
  return DVar1;
}



/* 4048e9d4 FUN_4048e9d4 */

/* Boundary evidence: original MIPS .pdata 4048e9d4..4048ee4b. Semantic name remains unreviewed. */

int FUN_4048e9d4(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  LONG *local_ac;
  uint local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  undefined4 local_94;
  uint auStack_90 [6];
  int aiStack_78 [4];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_28;
  
  local_28 = DAT_404bd274;
  if (*(int *)(param_1 + 0x1c) == 0) {
    FUN_404a438c(DAT_404bd274);
    return -0x7fffbffb;
  }
  local_ac = (LONG *)(param_1 + 0x28);
  if (local_ac == (LONG *)0x0) {
    local_ac = &local_b0;
    local_b0 = 0;
  }
  else {
    local_b0 = InterlockedIncrement(local_ac);
  }
  if (local_b0 != 0) {
    iVar5 = -0x7784ffff;
    goto LAB_4048ee10;
  }
  local_68 = 0xb96b3caa;
  local_54 = *(undefined4 *)(param_1 + 0xc);
  local_64 = 0x11d30728;
  local_50 = *(uint *)(param_1 + 0x10);
  local_40 = *(undefined4 *)(param_1 + 0x34);
  local_3c = *(undefined4 *)(param_1 + 0x38);
  local_60 = 0x7b9d;
  local_5c = 0x2ef31ef8;
  local_58 = *(uint *)(param_1 + 0x18);
  local_38 = *(undefined4 *)(param_1 + 0x3c);
  local_34 = *(undefined4 *)(param_1 + 0x40);
  local_30 = 0x50000;
  if (((local_58 & 0x40000) != 0) ||
     ((((local_58 & 0x10000) != 0 && (*(uint **)(param_1 + 0x4c) != (uint *)0x0)) &&
      ((**(uint **)(param_1 + 0x4c) & 1) != 0)))) {
    local_30 = 0x50002;
  }
  local_4c = local_54;
  local_48 = local_50;
  iVar5 = (**(code **)(*param_2 + 0xc))(param_2,&local_68,aiStack_78);
  uVar2 = local_58;
  if (iVar5 < 0) goto LAB_4048ee10;
  iVar6 = param_1 + -4;
  iVar5 = FUN_4048c130(iVar6,&local_c0,aiStack_78);
  if (((iVar5 == 0) || (0xf < (uVar2 & 0xff))) ||
     ((*(uint *)(&DAT_40481ef0 + (uVar2 & 0xff) * 8) != uVar2 || (local_48 == 0)))) {
    iVar5 = -0x7fff0001;
  }
  else {
    puVar3 = *(undefined **)(param_1 + 0x4c);
    if (puVar3 == (undefined *)0x0) {
      if ((*(uint *)(param_1 + 0x18) & 0x10000) == 0) {
        puVar3 = (undefined *)0x0;
      }
      else {
        puVar3 = FUN_404905b8(*(uint *)(param_1 + 0x18));
      }
      if (puVar3 != (undefined *)0x0) goto LAB_4048ebd8;
    }
    else {
LAB_4048ebd8:
      iVar5 = (**(code **)(*param_2 + 0x14))(param_2,puVar3);
      if (iVar5 < 0) goto LAB_4048edf8;
    }
    iVar1 = local_b4;
    if (*(uint *)(param_1 + 0x18) == uVar2) {
      local_9c = *(int *)(param_1 + 0x18);
      local_a4 = local_b4 - local_bc;
      local_a8 = local_b8 - local_c0;
      local_a0 = *(int *)(param_1 + 0x14);
      local_98 = ((local_9c >> 8 & 0xffU) * local_c0 >> 3) + local_a0 * local_bc +
                 *(int *)(param_1 + 0x1c);
      local_94 = 0;
      iVar5 = (**(code **)(*param_2 + 0x20))(param_2,&local_c0,&local_a8,1);
    }
    else {
      uVar4 = ((int)uVar2 >> 8 & 0xffU) * (local_b8 - local_c0) + 7 >> 3;
      uVar7 = (uint)(DAT_404bd390 << 2) / uVar4;
      if (uVar4 == 0) {
        trap(0x1c00);
      }
      uVar4 = local_48;
      if ((int)uVar7 < (int)local_48) {
        uVar4 = uVar7;
      }
      local_94 = 0;
      iVar5 = FUN_4048c5a0(local_b8 - local_c0,uVar4,uVar2,&local_a8,(undefined4 *)0x0,0);
      if (iVar5 == 0) {
        iVar5 = -0x7ff8fff2;
      }
      else {
        memcpy(auStack_90,&local_a8,0x18);
        while ((*(code **)(param_1 + 0x6c) == (code *)0x0 ||
               (iVar5 = (**(code **)(param_1 + 0x6c))(*(undefined4 *)(param_1 + 0x70)), iVar5 == 0))
              ) {
          local_b4 = local_bc + uVar4;
          if (iVar1 < (int)(local_bc + uVar4)) {
            local_b4 = iVar1;
          }
          iVar5 = FUN_4048d688(iVar6,&local_c0,5,uVar2,auStack_90);
          if (iVar5 < 0) goto LAB_4048ede0;
          iVar5 = (**(code **)(*param_2 + 0x20))(param_2,&local_c0,auStack_90,1);
          FUN_4048d87c(iVar6,&local_c0,(int *)auStack_90);
          if ((iVar5 < 0) || (local_bc = local_bc + uVar4, iVar1 <= local_bc)) goto LAB_4048ede0;
        }
        iVar5 = -0x7784fff8;
LAB_4048ede0:
        FUN_4048bb50((int)&local_a8);
      }
    }
  }
LAB_4048edf8:
  iVar5 = (**(code **)(*param_2 + 0x10))(param_2,iVar5);
LAB_4048ee10:
  InterlockedDecrement(local_ac);
  FUN_404a438c(local_28);
  return iVar5;
}



/* 4048ee4c FUN_4048ee4c */

/* Boundary evidence: original MIPS .pdata 4048ee4c..4048effb. Semantic name remains unreviewed. */

int FUN_4048ee4c(int param_1,int *param_2,uint param_3,uint param_4,uint *param_5)

{
  LONG LVar1;
  int iVar2;
  int local_28;
  LONG *local_24;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    return -0x7fffbffb;
  }
  if ((((param_4 != 0) &&
       ((0xf < (param_4 & 0xff) || (*(uint *)(&DAT_40481ef0 + (param_4 & 0xff) * 8) != param_4))))
      || ((param_3 & 0xffff0000) != 0)) ||
     ((param_5 == (uint *)0x0 || (((param_3 & 4) != 0 && (param_5[4] == 0)))))) {
    return -0x7ff8ffa9;
  }
  local_24 = (LONG *)(param_1 + 0x2c);
  if (local_24 == (LONG *)0x0) {
    local_24 = &local_28;
    local_28 = 0;
  }
  else {
    local_28 = InterlockedIncrement(local_24);
  }
  if (local_28 != 0) {
    InterlockedDecrement(local_24);
    return -0x7784ffff;
  }
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 0x30));
  if (LVar1 == 0) {
    iVar2 = FUN_4048c130(param_1,(int *)(param_1 + 0x54),param_2);
    if (iVar2 == 0) {
      iVar2 = -0x7ff8ffa9;
    }
    else {
      iVar2 = FUN_4048d688(param_1,(int *)(param_1 + 0x54),param_3,param_4,param_5);
      if (-1 < iVar2) goto LAB_4048efb8;
    }
  }
  else {
    iVar2 = -0x7784fffd;
  }
  InterlockedDecrement((LONG *)(param_1 + 0x30));
LAB_4048efb8:
  InterlockedDecrement(local_24);
  return iVar2;
}



/* 4048effc FUN_4048effc */

/* Boundary evidence: original MIPS .pdata 4048effc..4048f0d7. Semantic name remains unreviewed. */

int FUN_4048effc(int param_1,int *param_2)

{
  int iVar1;
  int local_18;
  LONG *local_14;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    local_14 = (LONG *)(param_1 + 0x2c);
    if (local_14 == (LONG *)0x0) {
      local_14 = &local_18;
      local_18 = 0;
    }
    else {
      local_18 = InterlockedIncrement(local_14);
    }
    if (local_18 == 0) {
      if (param_2 == (int *)0x0) {
        iVar1 = -0x7ff8ffa9;
      }
      else if (*(LONG *)(param_1 + 0x30) == 0) {
        iVar1 = FUN_4048d87c(param_1,(int *)(param_1 + 0x54),param_2);
        InterlockedDecrement((LONG *)(param_1 + 0x30));
      }
      else {
        iVar1 = -0x7784fffc;
      }
    }
    else {
      iVar1 = -0x7784ffff;
    }
    InterlockedDecrement(local_14);
  }
  return iVar1;
}



/* 4048f0d8 FUN_4048f0d8 */

/* Boundary evidence: original MIPS .pdata 4048f0d8..4048f1df. Semantic name remains unreviewed. */

int FUN_4048f0d8(int *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int *local_18 [2];
  
  if (param_2 == 0) {
    if (param_3 != 0) {
      return -0x7ff8ffa9;
    }
    param_2 = param_1[3];
    if (0x77 < param_2) {
      param_2 = 0x78;
    }
    param_3 = param_1[4];
    if (0x77 < param_3) {
      param_3 = 0x78;
    }
    if (param_2 != 0) goto LAB_4048f12c;
  }
  else {
LAB_4048f12c:
    if (param_3 == 0) {
      return -0x7ff8ffa9;
    }
    if (param_2 != 0) goto LAB_4048f144;
  }
  bVar1 = param_3 != 0;
  param_3 = 0;
  if (bVar1) {
    return -0x7ff8ffa9;
  }
LAB_4048f144:
  if (param_1 == (int *)0x4) {
    param_1 = (int *)0x0;
  }
  iVar2 = FUN_4048e3bc(param_1,param_2,param_3,0,3,local_18,0,0);
  if (-1 < iVar2) {
    iVar2 = (**(code **)*local_18[0])(local_18[0],&DAT_4048129c,param_4);
    (**(code **)(*local_18[0] + 8))(local_18[0]);
    return iVar2;
  }
  return iVar2;
}



/* 4048f1e0 FUN_4048f1e0 */

/* Boundary evidence: original MIPS .pdata 4048f1e0..4048f22b. Semantic name remains unreviewed. */

DWORD FUN_4048f1e0(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (DVar1 == 0) {
    DVar1 = 0x80004005;
  }
  else if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



/* 4048f22c FUN_4048f22c */

/* Boundary evidence: original MIPS .pdata 4048f22c..4048f2f3. Semantic name remains unreviewed. */

DWORD FUN_4048f22c(int param_1,LPVOID param_2,DWORD param_3,DWORD *param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_res8 [2];
  int local_18;
  LONG *local_14;
  
  local_14 = (LONG *)(param_1 + 8);
  local_res8[0] = param_3;
  if (local_14 == (LONG *)0x0) {
    local_14 = &local_18;
    local_18 = 0;
  }
  else {
    local_18 = InterlockedIncrement(local_14);
  }
  if (local_18 == 0) {
    BVar1 = ReadFile(*(HANDLE *)(param_1 + 0xc),param_2,local_res8[0],local_res8,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = FUN_4048f1e0();
    }
    else {
      DVar2 = 0;
    }
    if (param_4 != (DWORD *)0x0) {
      *param_4 = local_res8[0];
    }
  }
  else {
    DVar2 = 0x800700aa;
  }
  InterlockedDecrement(local_14);
  return DVar2;
}



/* 4048f2f4 FUN_4048f2f4 */

/* Boundary evidence: original MIPS .pdata 4048f2f4..4048f417. Semantic name remains unreviewed. */

DWORD FUN_4048f2f4(int param_1,undefined4 param_2,LONG param_3,DWORD param_4,int param_5,
                  DWORD *param_6)

{
  DWORD DVar1;
  DWORD DVar2;
  DWORD local_20 [2];
  int local_18;
  LONG *local_14;
  
  local_14 = (LONG *)(param_1 + 8);
  if (local_14 == (LONG *)0x0) {
    local_14 = &local_18;
    local_18 = 0;
  }
  else {
    local_18 = InterlockedIncrement(local_14);
  }
  if (local_18 == 0) {
    if (param_5 == 0) {
      DVar2 = 0;
    }
    else {
      DVar2 = 1;
      if ((param_5 != 1) && (DVar2 = 2, param_5 != 2)) {
        DVar2 = 0x80070057;
        goto LAB_4048f3f4;
      }
    }
    local_20[0] = param_4;
    DVar2 = SetFilePointer(*(HANDLE *)(param_1 + 0xc),param_3,(PLONG)local_20,DVar2);
    if ((DVar2 == 0xffffffff) && (DVar1 = GetLastError(), DVar1 != 0)) {
      DVar2 = FUN_4048f1e0();
    }
    else {
      if (param_6 != (DWORD *)0x0) {
        *param_6 = DVar2;
        param_6[1] = local_20[0];
      }
      DVar2 = 0;
    }
  }
  else {
    DVar2 = 0x800700aa;
  }
LAB_4048f3f4:
  InterlockedDecrement(local_14);
  return DVar2;
}



/* 4048f418 FUN_4048f418 */

/* Boundary evidence: original MIPS .pdata 4048f418..4048f58b. Semantic name remains unreviewed. */

DWORD FUN_4048f418(int param_1,undefined4 *param_2,uint param_3)

{
  BOOL BVar1;
  int iVar2;
  LPVOID _Dst;
  DWORD DVar3;
  size_t cb;
  int local_18;
  LONG *local_14;
  
  local_14 = (LONG *)(param_1 + 8);
  if (local_14 == (LONG *)0x0) {
    local_14 = &local_18;
    local_18 = 0;
  }
  else {
    local_18 = InterlockedIncrement(local_14);
  }
  if (local_18 == 0) {
    param_2[1] = 2;
    param_2[10] = *(undefined4 *)(param_1 + 0x14);
    param_2[0x11] = 0;
    param_2[0x10] = 0;
    memset(param_2 + 0xc,0,0x10);
    param_2[0xb] = 0;
    DVar3 = GetFileSize(*(HANDLE *)(param_1 + 0xc),param_2 + 3);
    param_2[2] = DVar3;
    if (((DVar3 == 0xffffffff) && (DVar3 = GetLastError(), DVar3 != 0)) ||
       (BVar1 = GetFileTime(*(HANDLE *)(param_1 + 0xc),(LPFILETIME)(param_2 + 6),
                            (LPFILETIME)(param_2 + 8),(LPFILETIME)(param_2 + 4)), BVar1 == 0)) {
      DVar3 = FUN_4048f1e0();
    }
    else {
      if ((param_3 & 1) == 0) {
        iVar2 = FUN_404963e4(*(short **)(param_1 + 0x10));
        cb = (iVar2 + 1) * 2;
        _Dst = CoTaskMemAlloc(cb);
        *param_2 = _Dst;
        if (_Dst == (LPVOID)0x0) {
          DVar3 = 0x8007000e;
          goto LAB_4048f568;
        }
        memcpy(_Dst,*(void **)(param_1 + 0x10),cb);
      }
      else {
        *param_2 = 0;
      }
      DVar3 = 0;
    }
  }
  else {
    DVar3 = 0x800700aa;
  }
LAB_4048f568:
  InterlockedDecrement(local_14);
  return DVar3;
}



/* 4048f58c FUN_4048f58c */

/* Boundary evidence: original MIPS .pdata 4048f58c..4048f653. Semantic name remains unreviewed. */

DWORD FUN_4048f58c(int param_1,LPCVOID param_2,DWORD param_3,DWORD *param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_res8 [2];
  int local_18;
  LONG *local_14;
  
  local_14 = (LONG *)(param_1 + 8);
  local_res8[0] = param_3;
  if (local_14 == (LONG *)0x0) {
    local_14 = &local_18;
    local_18 = 0;
  }
  else {
    local_18 = InterlockedIncrement(local_14);
  }
  if (local_18 == 0) {
    BVar1 = WriteFile(*(HANDLE *)(param_1 + 0xc),param_2,local_res8[0],local_res8,(LPOVERLAPPED)0x0)
    ;
    if (BVar1 == 0) {
      DVar2 = FUN_4048f1e0();
    }
    else {
      DVar2 = 0;
    }
    if (param_4 != (DWORD *)0x0) {
      *param_4 = local_res8[0];
    }
  }
  else {
    DVar2 = 0x800700aa;
  }
  InterlockedDecrement(local_14);
  return DVar2;
}



/* 4048f654 FUN_4048f654 */

/* Boundary evidence: original MIPS .pdata 4048f654..4048f707. Semantic name remains unreviewed. */

DWORD FUN_4048f654(int param_1,uint param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  int local_18;
  LONG *local_14;
  
  local_14 = (LONG *)(param_1 + 8);
  if (local_14 == (LONG *)0x0) {
    local_14 = &local_18;
    local_18 = 0;
  }
  else {
    local_18 = InterlockedIncrement(local_14);
  }
  if (local_18 == 0) {
    if (((*(int *)(param_1 + 0x14) == 0) || ((param_2 & 4) != 0)) ||
       (BVar1 = FlushFileBuffers(*(HANDLE *)(param_1 + 0xc)), BVar1 != 0)) {
      DVar2 = 0;
    }
    else {
      DVar2 = FUN_4048f1e0();
    }
  }
  else {
    DVar2 = 0x800700aa;
  }
  InterlockedDecrement(local_14);
  return DVar2;
}



/* 4048f708 FUN_4048f708 */

/* Boundary evidence: original MIPS .pdata 4048f708..4048f767. Semantic name remains unreviewed. */

void FUN_4048f708(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40482110;
  if ((HANDLE)param_1[3] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)param_1[3]);
  }
  FUN_404962ec((LPVOID)param_1[4]);
  *param_1 = &PTR_FUN_40481124;
  return;
}



/* 4048f768 FUN_4048f768 */

/* Boundary evidence: original MIPS .pdata 4048f768..4048f7b3. Semantic name remains unreviewed. */

undefined4 * FUN_4048f768(undefined4 *param_1,uint param_2)

{
  FUN_4048f708(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 4048f7b4 FUN_4048f7b4 */

/* Boundary evidence: original MIPS .pdata 4048f7b4..4048f8cf. Semantic name remains unreviewed. */

DWORD FUN_4048f7b4(LPCWSTR param_1,undefined4 *param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  DWORD DVar4;
  
  piVar1 = (int *)FUN_404962c4(0x18);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 1;
    *piVar1 = (int)&PTR_FUN_40482110;
    piVar1[2] = -1;
    piVar1[3] = -1;
    piVar1[4] = 0;
    piVar1[5] = 0;
  }
  if (piVar1 == (int *)0x0) {
    DVar4 = 0x8007000e;
  }
  else {
    pvVar2 = FUN_40496408(param_1);
    piVar1[4] = (int)pvVar2;
    if (pvVar2 == (void *)0x0) {
      DVar4 = 0x8007000e;
    }
    else {
      piVar1[5] = 1;
      iVar3 = FUN_404901b0(param_1,0x40000000,1,4,0x80);
      piVar1[3] = iVar3;
      if (iVar3 == -1) {
        DVar4 = FUN_4048f1e0();
      }
      else {
        DVar4 = 0;
      }
      if (-1 < (int)DVar4) {
        *param_2 = piVar1;
        return DVar4;
      }
    }
    (**(code **)(*piVar1 + 0x38))(piVar1,1);
  }
  return DVar4;
}



/* 4048f8d0 FUN_4048f8d0 */

/* Boundary evidence: original MIPS .pdata 4048f8d0..4048f9af. Semantic name remains unreviewed. */

undefined4 FUN_4048f8d0(int param_1,void *param_2,uint param_3,size_t *param_4)

{
  LONG *lpAddend;
  undefined4 uVar1;
  uint _Size;
  int local_28;
  LONG *local_24;
  
  local_24 = (LONG *)(param_1 + 8);
  if (local_24 == (LONG *)0x0) {
    local_24 = &local_28;
    local_28 = 0;
  }
  else {
    local_28 = InterlockedIncrement(local_24);
  }
  lpAddend = local_24;
  if (local_28 == 0) {
    _Size = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x14);
    if (param_3 < _Size) {
      _Size = param_3;
    }
    memcpy(param_2,(void *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14)),_Size);
    *(uint *)(param_1 + 0x14) = _Size + *(int *)(param_1 + 0x14);
    if (param_4 != (size_t *)0x0) {
      *param_4 = _Size;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0x887b0001;
  }
  InterlockedDecrement(lpAddend);
  return uVar1;
}



/* 4048f9b0 FUN_4048f9b0 */

/* Boundary evidence: original MIPS .pdata 4048f9b0..4048fac7. Semantic name remains unreviewed. */

undefined4
FUN_4048f9b0(int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,uint *param_6)

{
  int local_18;
  LONG *local_14;
  
  local_14 = (LONG *)(param_1 + 8);
  if (local_14 == (LONG *)0x0) {
    local_14 = &local_18;
    local_18 = 0;
  }
  else {
    local_18 = InterlockedIncrement(local_14);
  }
  if (local_18 != 0) {
    InterlockedDecrement(local_14);
    return 0x887b0001;
  }
  if (param_5 != 0) {
    if (param_5 == 1) {
      param_3 = *(uint *)(param_1 + 0x14) + param_3;
      param_4 = param_4 + (param_3 < *(uint *)(param_1 + 0x14));
    }
    else {
      if (param_5 != 2) goto LAB_4048faa0;
      param_3 = *(uint *)(param_1 + 0x10);
      param_4 = 0;
    }
  }
  if (((-1 < (int)param_4) && ((int)param_4 < 1)) &&
     ((param_4 != 0 || (param_3 <= *(uint *)(param_1 + 0x10))))) {
    *(uint *)(param_1 + 0x14) = param_3;
    if (param_6 != (uint *)0x0) {
      *param_6 = param_3;
      param_6[1] = param_4;
    }
    InterlockedDecrement(local_14);
    return 0;
  }
LAB_4048faa0:
  InterlockedDecrement(local_14);
  return 0x80070057;
}



/* 4048fac8 FUN_4048fac8 */

/* Boundary evidence: original MIPS .pdata 4048fac8..4048fc17. Semantic name remains unreviewed. */

DWORD FUN_4048fac8(int param_1,undefined4 *param_2,uint param_3)

{
  BOOL BVar1;
  int iVar2;
  LPVOID _Dst;
  DWORD DVar3;
  short *_Src;
  size_t cb;
  int local_18;
  LONG *local_14;
  
  local_14 = (LONG *)(param_1 + 8);
  if (local_14 == (LONG *)0x0) {
    local_14 = &local_18;
    local_18 = 0;
  }
  else {
    local_18 = InterlockedIncrement(local_14);
  }
  if (local_18 == 0) {
    memset(param_2,0,0x48);
    param_2[1] = 2;
    param_2[2] = *(undefined4 *)(param_1 + 0x10);
    param_2[3] = 0;
    param_2[10] = 0;
    if ((*(HANDLE *)(param_1 + 0x1c) == (HANDLE)0xffffffff) ||
       (BVar1 = GetFileTime(*(HANDLE *)(param_1 + 0x1c),(LPFILETIME)(param_2 + 6),
                            (LPFILETIME)(param_2 + 8),(LPFILETIME)(param_2 + 4)), BVar1 != 0)) {
      if ((param_3 & 1) == 0) {
        _Src = *(short **)(param_1 + 0x20);
        if (_Src == (short *)0x0) {
          _Src = (short *)&DAT_4048214c;
        }
        iVar2 = FUN_404963e4(_Src);
        cb = (iVar2 + 1) * 2;
        _Dst = CoTaskMemAlloc(cb);
        *param_2 = _Dst;
        if (_Dst == (LPVOID)0x0) {
          DVar3 = 0x8007000e;
          goto LAB_4048fbf4;
        }
        memcpy(_Dst,_Src,cb);
      }
      DVar3 = 0;
    }
    else {
      DVar3 = FUN_4048f1e0();
    }
  }
  else {
    DVar3 = 0x887b0001;
  }
LAB_4048fbf4:
  InterlockedDecrement(local_14);
  return DVar3;
}



/* 4048fc18 FUN_4048fc18 */

/* Boundary evidence: original MIPS .pdata 4048fc18..4048fd57. Semantic name remains unreviewed. */

DWORD FUN_4048fc18(int param_1,LPCWSTR param_2)

{
  void *pvVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  LPVOID pvVar4;
  DWORD local_20 [2];
  
  pvVar1 = FUN_40496408(param_2);
  *(void **)(param_1 + 0x20) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    DVar2 = 0x8007000e;
  }
  else {
    pvVar3 = (HANDLE)FUN_404901b0(param_2,0x80000000,1,3,0x80);
    *(HANDLE *)(param_1 + 0x1c) = pvVar3;
    if ((((pvVar3 != (HANDLE)0xffffffff) &&
         (DVar2 = GetFileSize(pvVar3,local_20), DVar2 != 0xffffffff)) && (local_20[0] == 0)) &&
       (pvVar3 = CreateFileMappingW(*(HANDLE *)(param_1 + 0x1c),(LPSECURITY_ATTRIBUTES)0x0,2,0,0,
                                    (LPCWSTR)0x0), pvVar3 != (HANDLE)0x0)) {
      pvVar4 = MapViewOfFile(pvVar3,4,0,0,0);
      CloseHandle(pvVar3);
      if (pvVar4 != (LPVOID)0x0) {
        *(LPVOID *)(param_1 + 0xc) = pvVar4;
        *(DWORD *)(param_1 + 0x10) = DVar2;
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined4 *)(param_1 + 0x18) = 4;
        return 0;
      }
    }
    DVar2 = FUN_4048f1e0();
  }
  return DVar2;
}



/* 4048fd58 FUN_4048fd58 */

/* Boundary evidence: original MIPS .pdata 4048fd58..4048fe27. Semantic name remains unreviewed. */

DWORD FUN_4048fd58(LPCWSTR param_1,undefined4 *param_2)

{
  int *piVar1;
  DWORD DVar2;
  
  piVar1 = (int *)FUN_404962c4(0x24);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 1;
    *piVar1 = (int)&PTR_FUN_40481170;
    piVar1[2] = -1;
    piVar1[3] = 0;
    piVar1[5] = 0;
    piVar1[4] = 0;
    piVar1[6] = 0;
    piVar1[7] = -1;
    piVar1[8] = 0;
  }
  if (piVar1 == (int *)0x0) {
    DVar2 = 0x8007000e;
  }
  else {
    DVar2 = FUN_4048fc18((int)piVar1,param_1);
    if ((int)DVar2 < 0) {
      (**(code **)(*piVar1 + 0x38))(piVar1,1);
    }
    else {
      *param_2 = piVar1;
    }
  }
  return DVar2;
}



/* 4048fe28 FUN_4048fe28 */

uint FUN_4048fe28(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = param_1 >> 0x18;
  if ((uVar4 != 0) && (uVar4 != 0xff)) {
    iVar2 = *(int *)(&DAT_40482150 + uVar4 * 4);
    uVar1 = (param_1 >> 0x10 & 0xff) * iVar2 >> 0x10;
    uVar5 = (param_1 >> 8 & 0xff) * iVar2 >> 0x10;
    uVar6 = (param_1 & 0xff) * iVar2 >> 0x10;
    if (0xff < uVar1) {
      uVar1 = 0xff;
    }
    if (0xff < uVar5) {
      uVar5 = 0xff;
    }
    uVar3 = 0xff;
    if (uVar6 < 0x100) {
      uVar3 = uVar6;
    }
    param_1 = ((uVar4 << 8 | uVar1) << 8 | uVar5) << 8 | uVar3;
  }
  return param_1;
}



/* 4048fee8 FUN_4048fee8 */

/* Boundary evidence: original MIPS .pdata 4048fee8..4048ff27. Semantic name remains unreviewed. */

void FUN_4048fee8(HKEY param_1,LPCWSTR param_2,REGSAM param_3,PHKEY param_4)

{
  DWORD aDStack_10 [2];
  
  RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,param_3,(LPSECURITY_ATTRIBUTES)0x0,param_4,
                  aDStack_10);
  return;
}



/* 4048ff28 FUN_4048ff28 */

/* Boundary evidence: original MIPS .pdata 4048ff28..4048ff53. Semantic name remains unreviewed. */

void FUN_4048ff28(HKEY param_1,LPCWSTR param_2,REGSAM param_3,PHKEY param_4)

{
  RegOpenKeyExW(param_1,param_2,0,param_3,param_4);
  return;
}



/* 4048ff54 FUN_4048ff54 */

/* Boundary evidence: original MIPS .pdata 4048ff54..4048ff93. Semantic name remains unreviewed. */

void FUN_4048ff54(HKEY param_1,DWORD param_2,LPWSTR param_3)

{
  DWORD local_18 [2];
  _FILETIME _Stack_10;
  
  local_18[0] = 0x104;
  RegEnumKeyExW(param_1,param_2,param_3,local_18,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,&_Stack_10);
  return;
}



/* 4048ff94 FUN_4048ff94 */

/* Boundary evidence: original MIPS .pdata 4048ff94..4048ffff. Semantic name remains unreviewed. */

void FUN_4048ff94(HKEY param_1,LPCWSTR param_2,short *param_3)

{
  int iVar1;
  
  iVar1 = FUN_404963e4(param_3);
  RegSetValueExW(param_1,param_2,0,1,(BYTE *)param_3,(iVar1 + 1) * 2);
  return;
}



/* 40490000 FUN_40490000 */

/* Boundary evidence: original MIPS .pdata 40490000..4049003b. Semantic name remains unreviewed. */

void FUN_40490000(HKEY param_1,LPCWSTR param_2,undefined4 param_3)

{
  undefined4 local_res8 [2];
  
  local_res8[0] = param_3;
  RegSetValueExW(param_1,param_2,0,4,(BYTE *)local_res8,4);
  return;
}



/* 4049003c FUN_4049003c */

/* Boundary evidence: original MIPS .pdata 4049003c..4049006b. Semantic name remains unreviewed. */

void FUN_4049003c(HKEY param_1,LPCWSTR param_2,BYTE *param_3,DWORD param_4)

{
  RegSetValueExW(param_1,param_2,0,3,param_3,param_4);
  return;
}



/* 4049006c FUN_4049006c */

/* Boundary evidence: original MIPS .pdata 4049006c..404900d3. Semantic name remains unreviewed. */

LSTATUS FUN_4049006c(HKEY param_1,LPCWSTR param_2,LPBYTE param_3)

{
  LSTATUS LVar1;
  DWORD local_10;
  DWORD local_c;
  
  local_10 = 4;
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_c,param_3,&local_10);
  if ((LVar1 == 0) && ((local_c != 4 || (LVar1 = 0, local_10 != 4)))) {
    LVar1 = 0xd;
  }
  return LVar1;
}



/* 404900d4 FUN_404900d4 */

/* Boundary evidence: original MIPS .pdata 404900d4..4049013f. Semantic name remains unreviewed. */

LSTATUS FUN_404900d4(HKEY param_1,LPCWSTR param_2,LPBYTE param_3,DWORD param_4)

{
  LSTATUS LVar1;
  DWORD local_10;
  DWORD local_c;
  
  local_10 = param_4;
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_c,param_3,&local_10);
  if ((LVar1 == 0) && ((local_c != 3 || (LVar1 = 0, local_10 != param_4)))) {
    LVar1 = 0xd;
  }
  return LVar1;
}



/* 40490140 FUN_40490140 */

/* Boundary evidence: original MIPS .pdata 40490140..40490193. Semantic name remains unreviewed. */

LSTATUS FUN_40490140(HKEY param_1,LPCWSTR param_2,LPBYTE param_3,DWORD param_4)

{
  LSTATUS LVar1;
  DWORD local_10;
  DWORD local_c;
  
  local_10 = param_4;
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_c,param_3,&local_10);
  if ((LVar1 == 0) && (local_c != 1)) {
    LVar1 = 0xd;
  }
  return LVar1;
}



/* 40490194 FUN_40490194 */

/* Boundary evidence: original MIPS .pdata 40490194..404901af. Semantic name remains unreviewed. */

void FUN_40490194(HINSTANCE param_1,UINT param_2,LPWSTR param_3,int param_4)

{
  LoadStringW(param_1,param_2,param_3,param_4);
  return;
}



/* 404901b0 FUN_404901b0 */

/* Boundary evidence: original MIPS .pdata 404901b0..404901e3. Semantic name remains unreviewed. */

void FUN_404901b0(LPCWSTR param_1,DWORD param_2,DWORD param_3,DWORD param_4,DWORD param_5)

{
  CreateFileW(param_1,param_2,param_3,(LPSECURITY_ATTRIBUTES)0x0,param_4,param_5,(HANDLE)0x0);
  return;
}



/* 404901e4 FUN_404901e4 */

/* Boundary evidence: original MIPS .pdata 404901e4..4049035b. Semantic name remains unreviewed. */

int FUN_404901e4(int *param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int local_30 [2];
  
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  local_30[0] = 0;
  do {
    if (param_2 == 0) {
      iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
      iVar1 = param_3;
      if (iVar2 < 0) goto LAB_40490268;
    }
    else {
      if (param_3 < 0) {
        return -0x7ff8ffa9;
      }
      iVar2 = (**(code **)(*param_1 + 0xc))(param_1,param_2,param_3,local_30);
LAB_40490268:
      iVar1 = local_30[0];
    }
    local_30[0] = iVar1;
    if ((iVar2 != -0x7ffffff6) || (param_4 == 0)) {
      if (param_5 != (int *)0x0) {
        *param_5 = local_30[0];
      }
      if (((param_4 == 0) && (iVar2 == -0x7ffffff6)) &&
         (iVar2 = (**(code **)(*param_1 + 0x14))(param_1), -1 < iVar2)) {
        iVar2 = -0x7ffffff6;
      }
      return iVar2;
    }
    param_2 = local_30[0] + param_2;
    param_3 = param_3 - local_30[0];
    Sleep(0);
  } while( true );
}



/* 4049035c FUN_4049035c */

/* Boundary evidence: original MIPS .pdata 4049035c..40490383. Semantic name remains unreviewed. */

void FUN_4049035c(int *param_1,int param_2,int param_3)

{
  FUN_404901e4(param_1,0,param_2,param_3,(int *)0x0);
  return;
}



/* 40490384 FUN_40490384 */

/* Boundary evidence: original MIPS .pdata 40490384..4049047f. Semantic name remains unreviewed. */

LSTATUS FUN_40490384(HKEY param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  HKEY local_230;
  DWORD local_22c;
  _FILETIME _Stack_228;
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_404bd274;
  LVar1 = RegOpenKeyExW(param_1,param_2,0,0xf003f,&local_230);
  if (LVar1 == 0) {
    do {
      local_22c = 0x104;
      LVar1 = RegEnumKeyExW(local_230,0,aWStack_220,&local_22c,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,&_Stack_228);
      if (LVar1 != 0) break;
      LVar1 = FUN_40490384(local_230,aWStack_220);
    } while (LVar1 == 0);
    RegCloseKey(local_230);
    LVar1 = RegDeleteKeyW(param_1,param_2);
  }
  FUN_404a438c(local_18);
  return LVar1;
}



/* 40490480 FUN_40490480 */

/* Boundary evidence: original MIPS .pdata 40490480..404904cf. Semantic name remains unreviewed. */

undefined4 FUN_40490480(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    FUN_404962ec((LPVOID)param_1[5]);
    piVar2 = (int *)param_1[1];
    iVar3 = *param_1;
    uVar1 = 0;
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
  }
  return uVar1;
}



/* 404904d0 FUN_404904d0 */

/* Boundary evidence: original MIPS .pdata 404904d0..404905b7. Semantic name remains unreviewed. */

undefined4 FUN_404904d0(int param_1,int param_2,SIZE_T param_3,undefined2 param_4,void *param_5)

{
  int *_Dst;
  void *_Dst_00;
  
  _Dst = (int *)FUN_404962c4(0x18);
  if (_Dst == (int *)0x0) {
    _Dst = (int *)0x0;
  }
  else {
    memset(_Dst,0,0x18);
  }
  if (_Dst != (int *)0x0) {
    _Dst[2] = param_2;
    *(undefined2 *)(_Dst + 4) = param_4;
    _Dst[3] = param_3;
    _Dst_00 = (void *)FUN_404962c4(param_3);
    _Dst[5] = (int)_Dst_00;
    if (_Dst_00 != (void *)0x0) {
      memcpy(_Dst_00,param_5,param_3);
      **(undefined4 **)(param_1 + 4) = _Dst;
      _Dst[1] = *(int *)(param_1 + 4);
      *_Dst = param_1;
      *(int **)(param_1 + 4) = _Dst;
      return 0;
    }
    FUN_404962ec(_Dst);
  }
  return 0x8007000e;
}



/* 404905b8 FUN_404905b8 */

undefined * FUN_404905b8(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0x30101) {
    puVar1 = &DAT_40482550;
  }
  else if (param_1 == 0x30402) {
    puVar1 = &DAT_40482560;
  }
  else if (param_1 == 0x30803) {
    puVar1 = &DAT_404825a8;
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}



/* 4049061c FUN_4049061c */

/* Boundary evidence: original MIPS .pdata 4049061c..404906df. Semantic name remains unreviewed. */

void * FUN_4049061c(void *param_1,uint param_2,undefined4 param_3)

{
  void *_Dst;
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  size_t _Size;
  
  _Size = (*(int *)((int)param_1 + 4) + 2) * 4;
  _Dst = (void *)FUN_404962c4((param_2 - *(int *)((int)param_1 + 4)) * 4 + _Size);
  if (_Dst != (void *)0x0) {
    memcpy(_Dst,param_1,_Size);
    *(uint *)((int)_Dst + 4) = param_2;
    uVar3 = *(uint *)((int)param_1 + 4);
    puVar2 = (undefined4 *)((uVar3 + 2) * 4 + (int)_Dst);
    if ((uVar3 < param_2) && (param_2 - uVar3 != 0)) {
      puVar1 = puVar2 + (param_2 - uVar3);
      do {
        *puVar2 = param_3;
        puVar2 = puVar2 + 1;
      } while (puVar2 != puVar1);
    }
  }
  return _Dst;
}



/* 404906e0 FUN_404906e0 */

/* Boundary evidence: original MIPS .pdata 404906e0..40490763. Semantic name remains unreviewed. */

void * FUN_404906e0(void *param_1,int param_2)

{
  void *_Dst;
  SIZE_T cb;
  
  cb = (*(int *)((int)param_1 + 4) + 2) * 4;
  if (param_2 == 0) {
    _Dst = (void *)FUN_404962c4(cb);
  }
  else {
    _Dst = CoTaskMemAlloc(cb);
  }
  if (_Dst != (void *)0x0) {
    memcpy(_Dst,param_1,cb);
  }
  return _Dst;
}



/* 40490764 FUN_40490764 */

/* Boundary evidence: original MIPS .pdata 40490764..40490813. Semantic name remains unreviewed. */

undefined4 FUN_40490764(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0xac) != 0) {
    piVar2 = *(int **)(param_1 + 0x78);
    if (*piVar2 != 0) {
      do {
        iVar1 = FUN_404904d0(param_2 + 0x90,piVar2[2],piVar2[3],(short)piVar2[4],(void *)piVar2[5]);
        if (iVar1 != 0) {
          return 0x80004005;
        }
        piVar2 = (int *)*piVar2;
      } while (*piVar2 != 0);
    }
    *(undefined4 *)(param_2 + 0xac) = *(undefined4 *)(param_1 + 0xac);
    *(undefined4 *)(param_2 + 0xa8) = *(undefined4 *)(param_1 + 0xa8);
  }
  return 0;
}



/* 40490814 FUN_40490814 */

/* Boundary evidence: original MIPS .pdata 40490814..4049082f. Semantic name remains unreviewed. */

void FUN_40490814(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}



/* 40490830 FUN_40490830 */

/* Boundary evidence: original MIPS .pdata 40490830..40490977. Semantic name remains unreviewed. */

void FUN_40490830(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  
  if (param_3 != 0) {
    uVar9 = param_3 + 7 >> 3;
    uVar7 = 0;
    if (uVar9 != 0) {
      puVar5 = (undefined1 *)(uVar9 + param_2);
      do {
        puVar5 = puVar5 + -1;
        puVar6 = (undefined1 *)(uVar7 + param_1);
        uVar7 = uVar7 + 1;
        *puVar6 = *puVar5;
      } while (uVar7 < uVar9);
    }
    uVar7 = 0;
    if (uVar9 != 0) {
      do {
        pbVar8 = (byte *)(uVar7 + param_1);
        bVar1 = *pbVar8;
        uVar7 = uVar7 + 1;
        *pbVar8 = (&DAT_404829b0)[bVar1 & 0xf] << 4 | (&DAT_404829b0)[bVar1 >> 4];
      } while (uVar7 < uVar9);
    }
    uVar7 = param_3 & 7;
    bVar1 = (&DAT_404829c0)[uVar7];
    bVar2 = (&DAT_404829c8)[uVar7];
    uVar3 = 0;
    if (uVar9 != 1) {
      do {
        pbVar8 = (byte *)(uVar3 + param_1);
        iVar4 = uVar3 + param_1;
        uVar3 = uVar3 + 1;
        *pbVar8 = (*(byte *)(iVar4 + 1) & bVar2) >> uVar7 | (*pbVar8 & bVar1) << (8 - uVar7 & 0x1f);
      } while (uVar3 < uVar9 - 1);
    }
    *(byte *)(uVar3 + param_1) = (bVar1 & *(byte *)(uVar3 + param_1)) << (8 - uVar7 & 0x1f);
  }
  return;
}



/* 40490978 FUN_40490978 */

void FUN_40490978(int param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  
  if ((param_3 & 1) == 0) {
    pbVar1 = (byte *)((param_3 >> 1) + param_1);
    for (; param_3 != 0; param_3 = param_3 - 2) {
      pbVar1 = pbVar1 + -1;
      *pbVar1 = *param_2 << 4 | *param_2 >> 4;
      param_2 = param_2 + 1;
    }
  }
  else {
    pbVar1 = (byte *)((param_3 >> 1) + param_1);
    *pbVar1 = *param_2 & 0xf0;
    for (iVar3 = param_3 - 1; iVar3 != 0; iVar3 = iVar3 + -2) {
      pbVar1 = pbVar1 + -1;
      pbVar2 = param_2 + 1;
      *pbVar1 = (*pbVar2 ^ *param_2) & 0xf ^ *pbVar2;
      param_2 = pbVar2;
    }
  }
  return;
}



/* 40490a20 FUN_40490a20 */

void FUN_40490a20(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(param_1 + param_3);
  for (; param_3 != 0; param_3 = param_3 + -1) {
    puVar1 = puVar1 + -1;
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
  }
  return;
}



/* 40490a48 FUN_40490a48 */

void FUN_40490a48(int param_1,undefined2 *param_2,int param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(param_3 * 2 + param_1);
  for (; param_3 != 0; param_3 = param_3 + -1) {
    puVar1 = puVar1 + -1;
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
  }
  return;
}



/* 40490a74 FUN_40490a74 */

void FUN_40490a74(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(param_3 * 3 + param_1);
  for (; param_3 != 0; param_3 = param_3 + -1) {
    puVar2[-3] = *param_2;
    puVar2[-2] = param_2[1];
    puVar1 = param_2 + 2;
    param_2 = param_2 + 3;
    puVar2[-1] = *puVar1;
    puVar2 = puVar2 + -3;
  }
  return;
}



/* 40490abc FUN_40490abc */

void FUN_40490abc(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_3 * 4 + param_1);
  for (; param_3 != 0; param_3 = param_3 + -1) {
    puVar1 = puVar1 + -1;
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
  }
  return;
}



/* 40490ae8 FUN_40490ae8 */

void FUN_40490ae8(int param_1,undefined4 *param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_3 * 6 + param_1);
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *(undefined4 *)((int)puVar2 + -6) = *param_2;
    uVar1 = *(undefined1 *)((int)param_2 + 5);
    *(undefined1 *)((int)puVar2 + -2) = *(undefined1 *)(param_2 + 1);
    *(undefined1 *)((int)puVar2 + -1) = uVar1;
    param_2 = (undefined4 *)((int)param_2 + 6);
    puVar2 = (undefined4 *)((int)puVar2 + -6);
  }
  return;
}



/* 40490b48 FUN_40490b48 */

void FUN_40490b48(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_3 * 8 + param_1);
  for (; param_3 != 0; param_3 = param_3 + -1) {
    puVar2[-2] = *param_2;
    puVar1 = param_2 + 1;
    param_2 = param_2 + 2;
    puVar2[-1] = *puVar1;
    puVar2 = puVar2 + -2;
  }
  return;
}



/* 40490b90 FUN_40490b90 */

/* Boundary evidence: original MIPS .pdata 40490b90..40490c07. Semantic name remains unreviewed. */

int FUN_40490b90(int param_1,uint param_2,uint param_3,uint param_4,int param_5,undefined4 *param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 local_10 [2];
  
  *param_6 = 0;
  if ((param_2 == 0) || (param_3 == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    piVar2 = (int *)(param_1 + -8);
    if (param_1 == 0xc) {
      piVar2 = (int *)0x0;
    }
    iVar1 = FUN_4048e3bc(piVar2,param_2,param_3,param_4,param_5,local_10,0,0);
    if (-1 < iVar1) {
      *param_6 = local_10[0];
    }
  }
  return iVar1;
}



/* 40490c68 FUN_40490c68 */

void FUN_40490c68(int *param_1,undefined2 *param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  uVar1 = param_1[2];
  puVar4 = (undefined2 *)param_1[4];
  iVar3 = param_1[1];
  if (param_3 < 0) {
    param_2 = param_2 + iVar3 + -1;
  }
  if (iVar3 != 0) {
    do {
      iVar2 = *param_1;
      iVar3 = iVar3 + -1;
      if (iVar2 != 0) {
        puVar5 = puVar4;
        puVar6 = param_2;
        do {
          iVar2 = iVar2 + -1;
          *puVar5 = *puVar6;
          puVar5 = puVar5 + 1;
          puVar6 = (undefined2 *)((param_4 & 0xfffffffe) + (int)puVar6);
        } while (iVar2 != 0);
      }
      puVar4 = (undefined2 *)((uVar1 & 0xfffffffe) + (int)puVar4);
      param_2 = param_2 + param_3;
    } while (iVar3 != 0);
  }
  return;
}



/* 40490d58 FUN_40490d58 */

/* Boundary evidence: original MIPS .pdata 40490d58..404912bb. Semantic name remains unreviewed. */

void FUN_40490d58(uint *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  uVar7 = *param_1;
  pbVar2 = (byte *)param_1[4];
  uVar17 = param_1[1];
  uVar16 = uVar7 >> 3;
  uVar10 = uVar7 & 7;
  iVar1 = (param_4 ^ (int)param_4 >> 0x1f) - ((int)param_4 >> 0x1f);
  iVar6 = 0x5a;
  if (param_3 != 1) {
    iVar6 = 0x10e;
  }
  if ((iVar6 == 0x10e) || (param_2 = (uVar7 - 1) * param_4 + param_2, iVar6 != 0x5a)) {
    uVar7 = 0;
    if (uVar17 != 0) {
      do {
        uVar20 = (uVar17 - uVar7) - 1;
        uVar15 = uVar20 >> 3;
        uVar19 = 7 - (uVar20 & 7);
        pbVar4 = pbVar2;
        uVar20 = 0;
        if (uVar16 != 0) {
          uVar21 = 1 << (uVar19 & 0x1f);
          pbVar14 = (byte *)(uVar15 + param_2);
          iVar6 = iVar1 * 8;
          pbVar18 = (byte *)(iVar1 * 7 + uVar15 + param_2);
          pbVar12 = (byte *)(iVar1 * 6 + uVar15 + param_2);
          pbVar13 = (byte *)(iVar1 * 4 + uVar15 + param_2);
          pbVar8 = (byte *)(iVar1 * 5 + uVar15 + param_2);
          pbVar9 = (byte *)(iVar1 * 3 + uVar15 + param_2);
          pbVar3 = (byte *)(iVar1 * 2 + uVar15 + param_2);
          uVar11 = uVar16;
          do {
            *pbVar4 = (byte)((((((((int)(pbVar14[iVar1] & uVar21) >> (uVar19 & 0x1f) |
                                  ((int)(*pbVar14 & uVar21) >> (uVar19 & 0x1f)) << 1) << 1 |
                                 (int)(*pbVar3 & uVar21) >> (uVar19 & 0x1f)) << 1 |
                                (int)(*pbVar9 & uVar21) >> (uVar19 & 0x1f)) << 1 |
                               (int)(*pbVar13 & uVar21) >> (uVar19 & 0x1f)) << 1 |
                              (int)(*pbVar8 & uVar21) >> (uVar19 & 0x1f)) << 1 |
                             (int)(*pbVar12 & uVar21) >> (uVar19 & 0x1f)) << 1) |
                      (byte)((int)(*pbVar18 & uVar21) >> (uVar19 & 0x1f));
            pbVar4 = pbVar4 + 1;
            pbVar14 = pbVar14 + iVar6;
            pbVar3 = pbVar3 + iVar6;
            pbVar9 = pbVar9 + iVar6;
            pbVar13 = pbVar13 + iVar6;
            pbVar8 = pbVar8 + iVar6;
            pbVar12 = pbVar12 + iVar6;
            uVar11 = uVar11 - 1;
            pbVar18 = pbVar18 + iVar6;
            uVar20 = uVar16;
          } while (uVar11 != 0);
        }
        if (uVar10 != 0) {
          *pbVar4 = 0;
          if (uVar10 != 0) {
            uVar11 = 7;
            pbVar9 = (byte *)(uVar20 * 8 * iVar1 + uVar15 + param_2);
            uVar20 = uVar10;
            do {
              *pbVar4 = (byte)(((int)((uint)*pbVar9 & 1 << (uVar19 & 0x1f)) >> (uVar19 & 0x1f)) <<
                              (uVar11 & 0x1f)) | *pbVar4;
              pbVar9 = pbVar9 + iVar1;
              uVar20 = uVar20 - 1;
              uVar11 = uVar11 - 1;
            } while (uVar20 != 0);
          }
        }
        pbVar2 = pbVar2 + param_1[2];
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar17);
    }
  }
  else {
    uVar7 = 0;
    if (uVar17 != 0) {
      do {
        uVar19 = uVar7 >> 3;
        uVar15 = 7 - (uVar7 & 7);
        pbVar4 = pbVar2;
        uVar20 = 0;
        if (uVar16 != 0) {
          uVar21 = 1 << (uVar15 & 0x1f);
          iVar6 = 0;
          uVar11 = uVar16;
          do {
            iVar5 = *param_1 - iVar6;
            *pbVar4 = (byte)(((((((((int)(*(byte *)((iVar5 + -1) * iVar1 + uVar19 + param_2) &
                                         uVar21) >> (uVar15 & 0x1f)) << 1 |
                                  (int)(*(byte *)((iVar5 + -2) * iVar1 + uVar19 + param_2) & uVar21)
                                  >> (uVar15 & 0x1f)) << 1 |
                                 (int)(*(byte *)((iVar5 + -3) * iVar1 + uVar19 + param_2) & uVar21)
                                 >> (uVar15 & 0x1f)) << 1 |
                                (int)(*(byte *)((iVar5 + -4) * iVar1 + uVar19 + param_2) & uVar21)
                                >> (uVar15 & 0x1f)) << 1 |
                               (int)(*(byte *)((iVar5 + -5) * iVar1 + uVar19 + param_2) & uVar21) >>
                               (uVar15 & 0x1f)) << 1 |
                              (int)(*(byte *)((iVar5 + -6) * iVar1 + uVar19 + param_2) & uVar21) >>
                              (uVar15 & 0x1f)) << 1 |
                             (int)(*(byte *)((iVar5 + -7) * iVar1 + uVar19 + param_2) & uVar21) >>
                             (uVar15 & 0x1f)) << 1) |
                      (byte)((int)(*(byte *)((iVar5 + -8) * iVar1 + uVar19 + param_2) & uVar21) >>
                            (uVar15 & 0x1f));
            pbVar4 = pbVar4 + 1;
            uVar11 = uVar11 - 1;
            iVar6 = iVar6 + 8;
            uVar20 = uVar16;
          } while (uVar11 != 0);
        }
        if (uVar10 != 0) {
          *pbVar4 = 0;
          if (uVar10 != 0) {
            uVar11 = 7;
            pbVar9 = (byte *)((*param_1 + uVar20 * -8 + -1) * iVar1 + uVar19 + param_2);
            uVar20 = uVar10;
            do {
              *pbVar4 = (byte)(((int)((uint)*pbVar9 & 1 << (uVar15 & 0x1f)) >> (uVar15 & 0x1f)) <<
                              (uVar11 & 0x1f)) | *pbVar4;
              pbVar9 = pbVar9 + -iVar1;
              uVar20 = uVar20 - 1;
              uVar11 = uVar11 - 1;
            } while (uVar20 != 0);
          }
        }
        pbVar2 = pbVar2 + param_1[2];
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar17);
    }
  }
  return;
}



/* 404912bc FUN_404912bc */

/* Boundary evidence: original MIPS .pdata 404912bc..4049152f. Semantic name remains unreviewed. */

void FUN_404912bc(int *param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  
  uVar3 = param_1[1];
  uVar8 = uVar3 & 1;
  iVar5 = 0x5a;
  if (param_3 < 1) {
    iVar5 = 0x10e;
  }
  if (uVar8 != 0) {
    pbVar4 = (byte *)param_1[4];
    pbVar6 = param_2 + (uVar3 >> 1);
    if (iVar5 == 0x5a) {
      pbVar4 = pbVar4 + (uVar3 - 1) * param_1[2];
    }
    for (iVar2 = *param_1; iVar2 != 0; iVar2 = iVar2 + -2) {
      *pbVar4 = *pbVar6 & 0xf0;
      if (iVar2 == 1) break;
      *pbVar4 = pbVar6[param_4] >> 4 | *pbVar4;
      pbVar6 = pbVar6 + param_4 + param_4;
      pbVar4 = pbVar4 + 1;
    }
    uVar3 = uVar3 - 1;
  }
  pbVar6 = (byte *)param_1[4];
  if (iVar5 == 0x10e) {
    param_2 = param_2 + ((uVar3 >> 1) - 1);
    if (uVar8 == 0) goto joined_r0x40491458;
    pbVar6 = pbVar6 + param_1[2];
  }
  if (iVar5 == 0x5a) {
    do {
      if (uVar3 == 0) {
        return;
      }
      pbVar4 = param_2;
      pbVar7 = pbVar6;
      for (iVar5 = *param_1; iVar5 != 0; iVar5 = iVar5 + -2) {
        *pbVar7 = *pbVar4 & 0xf0;
        if (iVar5 == 1) break;
        *pbVar7 = pbVar4[param_4] >> 4 | *pbVar7;
        pbVar4 = pbVar4 + param_4 + param_4;
        pbVar7 = pbVar7 + 1;
      }
      if (uVar3 == 1) {
        return;
      }
      iVar2 = param_1[2];
      pbVar4 = pbVar6 + iVar2;
      pbVar7 = param_2;
      for (iVar5 = *param_1; iVar5 != 0; iVar5 = iVar5 + -2) {
        bVar1 = *pbVar7;
        *pbVar4 = bVar1 << 4;
        if (iVar5 == 1) break;
        *pbVar4 = pbVar7[param_4] & 0xf | bVar1 << 4;
        pbVar7 = pbVar7 + param_4 + param_4;
        pbVar4 = pbVar4 + 1;
      }
      uVar3 = uVar3 - 2;
      pbVar6 = pbVar6 + iVar2 + param_1[2];
      param_2 = param_2 + param_3;
    } while( true );
  }
joined_r0x40491458:
  do {
    if (uVar3 == 0) {
      return;
    }
    pbVar4 = param_2;
    pbVar7 = pbVar6;
    for (iVar5 = *param_1; iVar5 != 0; iVar5 = iVar5 + -2) {
      bVar1 = *pbVar4;
      *pbVar7 = bVar1 << 4;
      if (iVar5 == 1) break;
      *pbVar7 = pbVar4[param_4] & 0xf | bVar1 << 4;
      pbVar4 = pbVar4 + param_4 + param_4;
      pbVar7 = pbVar7 + 1;
    }
    if (uVar3 == 1) {
      return;
    }
    iVar2 = param_1[2];
    pbVar4 = pbVar6 + iVar2;
    pbVar7 = param_2;
    for (iVar5 = *param_1; iVar5 != 0; iVar5 = iVar5 + -2) {
      *pbVar4 = *pbVar7 & 0xf0;
      if (iVar5 == 1) break;
      *pbVar4 = pbVar7[param_4] >> 4 | *pbVar4;
      pbVar7 = pbVar7 + param_4 + param_4;
      pbVar4 = pbVar4 + 1;
    }
    uVar3 = uVar3 - 2;
    pbVar6 = pbVar6 + iVar2 + param_1[2];
    param_2 = param_2 + param_3;
  } while( true );
}



/* 404916c8 FUN_404916c8 */

/* Boundary evidence: original MIPS .pdata 404916c8..40491713. Semantic name remains unreviewed. */

void FUN_404916c8(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}



/* 40491714 FUN_40491714 */

/* Boundary evidence: original MIPS .pdata 40491714..4049171f. Semantic name remains unreviewed. */

undefined4 FUN_40491714(void)

{
  return 1;
}



/* 40491720 FUN_40491720 */

/* Boundary evidence: original MIPS .pdata 40491720..404919b7. Semantic name remains unreviewed. */

int FUN_40491720(int param_1,int *param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_60;
  LONG *local_5c;
  int local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  
  local_5c = (LONG *)(param_1 + 0x20);
  if (local_5c == (LONG *)0x0) {
    local_5c = &local_60;
    local_60 = 0;
  }
  else {
    local_60 = InterlockedIncrement(local_5c);
  }
  if (local_60 == 0) {
    iVar3 = FUN_404916c8(param_3);
    if (iVar3 != 0) {
      iVar4 = param_1 + -0xc;
      iVar3 = FUN_4048c130(iVar4,&local_48,param_2);
      if (iVar3 != 0) {
        puVar1 = (undefined4 *)FUN_404962c4(0xc0);
        if (puVar1 == (undefined4 *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = FUN_4048e19c(puVar1);
        }
        if (piVar2 == (int *)0x0) {
          iVar3 = -0x7ff8fff2;
        }
        else {
          local_50 = local_40 - local_48;
          local_4c = local_3c - local_44;
          local_58 = 0;
          local_54 = 0;
          iVar3 = FUN_4048c7a0((int)piVar2,local_50,local_4c,*(uint *)(param_1 + 0x10),0);
          if (-1 < iVar3) {
            local_38 = local_50 - local_58;
            local_34 = local_4c - local_54;
            local_2c = piVar2[7];
            local_30 = piVar2[6];
            local_24 = 0;
            local_28 = ((piVar2[7] >> 8 & 0xffU) * local_58 >> 3) + local_54 * piVar2[6] + piVar2[8]
            ;
            iVar3 = FUN_4048d688(iVar4,&local_48,5,*(uint *)(param_1 + 0x10),&local_38);
            if (-1 < iVar3) {
              FUN_4048d87c(iVar4,&local_58,(int *)&local_38);
              piVar2[0xe] = *(int *)(param_1 + 0x2c);
              piVar2[0xf] = *(int *)(param_1 + 0x30);
              piVar2[0x10] = *(int *)(param_1 + 0x34);
              piVar2[0x11] = *(int *)(param_1 + 0x38);
              if ((*(int *)(param_1 + 0x44) == 0) ||
                 (iVar3 = (**(code **)(*piVar2 + 0x20))(piVar2), -1 < iVar3)) {
                iVar3 = 0;
              }
              if (-1 < iVar3) {
                if ((param_4 == 1) && (*(int *)(param_1 + 0xa0) != 0)) {
                  iVar3 = FUN_40490764(iVar4,(int)piVar2);
                }
                if (-1 < iVar3) {
                  *param_3 = piVar2;
                  goto LAB_40491984;
                }
              }
            }
          }
          (**(code **)(*piVar2 + 0x24))(piVar2,1);
        }
        goto LAB_40491984;
      }
    }
    iVar3 = -0x7ff8ffa9;
  }
  else {
    iVar3 = -0x7784ffff;
  }
LAB_40491984:
  InterlockedDecrement(local_5c);
  return iVar3;
}



/* 404919b8 FUN_404919b8 */

/* Boundary evidence: original MIPS .pdata 404919b8..40491ccf. Semantic name remains unreviewed. */

int FUN_404919b8(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  uint local_38;
  int local_30;
  LONG *local_2c;
  
  if ((param_2 == 0) && (param_3 == 0)) {
    iVar2 = (**(code **)(*param_1 + 0xc))(param_1,0,param_4,1);
    return iVar2;
  }
  local_2c = param_1 + 8;
  *param_4 = 0;
  if (local_2c == (LONG *)0x0) {
    local_2c = &local_30;
    local_30 = 0;
  }
  else {
    local_30 = InterlockedIncrement(local_2c);
  }
  if (local_30 != 0) {
    iVar2 = -0x7784ffff;
    goto LAB_40491bb4;
  }
  puVar3 = (undefined4 *)FUN_404962c4(0xc0);
  if (puVar3 == (undefined4 *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = FUN_4048e19c(puVar3);
  }
  if (piVar4 == (int *)0x0) {
    iVar2 = -0x7ff8fff2;
    goto LAB_40491bb4;
  }
  iVar2 = FUN_4048c7a0((int)piVar4,param_1[1],param_1[2],param_1[4],0);
  if (-1 < iVar2) {
    local_38 = param_1[1];
    uVar5 = param_1[4] >> 8 & 0xff;
    if (param_2 == 0) {
      pcVar6 = FUN_40490814;
      local_38 = local_38 * uVar5 + 7 >> 3;
    }
    else if (uVar5 < 0x19) {
      if (uVar5 == 0x18) {
        pcVar6 = FUN_40490a74;
      }
      else if (uVar5 == 1) {
        pcVar6 = FUN_40490830;
      }
      else if (uVar5 == 4) {
        pcVar6 = FUN_40490978;
      }
      else if (uVar5 == 8) {
        pcVar6 = FUN_40490a20;
      }
      else {
        if (uVar5 != 0x10) goto LAB_40491b98;
        pcVar6 = FUN_40490a48;
      }
    }
    else if (uVar5 == 0x20) {
      pcVar6 = FUN_40490abc;
    }
    else if (uVar5 == 0x30) {
      pcVar6 = FUN_40490ae8;
    }
    else {
      if (uVar5 != 0x40) {
LAB_40491b98:
        iVar2 = -0x7fffbfff;
        goto LAB_40491ba0;
      }
      pcVar6 = FUN_40490b48;
    }
    iVar8 = param_1[5];
    iVar7 = piVar4[8];
    iVar2 = piVar4[6];
    if (param_3 != 0) {
      iVar1 = (param_1[2] + -1) * iVar2;
      iVar2 = -iVar2;
      iVar7 = iVar1 + iVar7;
    }
    uVar5 = 0;
    if (param_1[2] != 0) {
      do {
        (*pcVar6)(iVar7,iVar8,local_38);
        uVar5 = uVar5 + 1;
        iVar8 = param_1[3] + iVar8;
        iVar7 = iVar2 + iVar7;
      } while (uVar5 < (uint)param_1[2]);
    }
    piVar4[0xe] = param_1[0xb];
    piVar4[0xf] = param_1[0xc];
    piVar4[0x10] = param_1[0xd];
    piVar4[0x11] = param_1[0xe];
    if ((param_1[0x11] == 0) || (iVar2 = (**(code **)(*piVar4 + 0x20))(piVar4), -1 < iVar2)) {
      iVar2 = 0;
    }
    if (-1 < iVar2) {
      *param_4 = piVar4;
      goto LAB_40491bb4;
    }
  }
LAB_40491ba0:
  (**(code **)(*piVar4 + 0x24))(piVar4,1);
LAB_40491bb4:
  InterlockedDecrement(local_2c);
  return iVar2;
}



/* 40491cd0 FUN_40491cd0 */

/* Boundary evidence: original MIPS .pdata 40491cd0..40491fdb. Semantic name remains unreviewed. */

int FUN_40491cd0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  int local_28;
  LONG *local_24;
  
  iVar1 = __fptoli(param_2);
  iVar1 = iVar1 % 0x168;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x168;
  }
  if (iVar1 == 0) {
LAB_40491f94:
    pcVar6 = *(code **)(*param_1 + 0xc);
    uVar5 = 0;
    puVar2 = param_4;
    param_4 = (undefined4 *)0x1;
LAB_40491fa8:
    iVar1 = (*pcVar6)(param_1,uVar5,puVar2,param_4);
    return iVar1;
  }
  if (iVar1 != 0x5a) {
    if (iVar1 == 0xb4) {
      pcVar6 = *(code **)(*param_1 + 0x10);
      puVar2 = (undefined4 *)0x1;
      uVar5 = 1;
      goto LAB_40491fa8;
    }
    if (iVar1 != 0x10e) {
      if (iVar1 != 0x168) {
        return -0x7fffbfff;
      }
      goto LAB_40491f94;
    }
  }
  local_24 = param_1 + 8;
  *param_4 = 0;
  if (local_24 == (LONG *)0x0) {
    local_24 = &local_28;
    local_28 = 0;
  }
  else {
    local_28 = InterlockedIncrement(local_24);
  }
  if (local_28 != 0) {
    iVar8 = -0x7784ffff;
    goto LAB_40491ed4;
  }
  puVar2 = (undefined4 *)FUN_404962c4(0xc0);
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_4048e19c(puVar2);
  }
  if (piVar3 == (int *)0x0) {
    iVar8 = -0x7ff8fff2;
    goto LAB_40491ed4;
  }
  iVar8 = FUN_4048c7a0((int)piVar3,param_1[2],param_1[1],param_1[4],0);
  uVar5 = 1;
  if (-1 < iVar8) {
    uVar7 = param_1[4] >> 8 & 0xff;
    if (uVar7 < 0x19) {
      if (uVar7 == 0x18) {
        pcVar6 = (code *)&UNK_40491530;
      }
      else if (uVar7 == 1) {
        pcVar6 = FUN_40490d58;
      }
      else if (uVar7 == 4) {
        pcVar6 = FUN_404912bc;
      }
      else if (uVar7 == 8) {
        pcVar6 = (code *)&UNK_40490c08;
      }
      else {
        if (uVar7 != 0x10) goto LAB_40491eb8;
        pcVar6 = FUN_40490c68;
      }
    }
    else if (uVar7 == 0x20) {
      pcVar6 = (code *)&UNK_40490ce0;
    }
    else if (uVar7 == 0x30) {
      pcVar6 = (code *)&UNK_404915b4;
    }
    else {
      if (uVar7 != 0x40) {
LAB_40491eb8:
        iVar8 = -0x7fffbfff;
        goto LAB_40491ec0;
      }
      pcVar6 = (code *)&UNK_4049164c;
    }
    iVar4 = param_1[5];
    iVar8 = param_1[3];
    if (iVar1 == 0x5a) {
      iVar1 = (param_1[2] + -1) * iVar8;
      iVar8 = -iVar8;
      iVar4 = iVar1 + iVar4;
    }
    else {
      uVar5 = 0xffffffff;
    }
    (*pcVar6)(piVar3 + 4,iVar4,uVar5,iVar8);
    piVar3[0xe] = param_1[0xd];
    piVar3[0xf] = param_1[0xe];
    piVar3[0x10] = param_1[0xb];
    piVar3[0x11] = param_1[0xc];
    if ((param_1[0x11] == 0) || (iVar8 = (**(code **)(*piVar3 + 0x20))(piVar3), -1 < iVar8)) {
      iVar8 = 0;
    }
    if (-1 < iVar8) {
      *param_4 = piVar3;
      goto LAB_40491ed4;
    }
  }
LAB_40491ec0:
  (**(code **)(*piVar3 + 0x24))(piVar3,1);
LAB_40491ed4:
  InterlockedDecrement(local_24);
  return iVar8;
}



/* 40491fdc FUN_40491fdc */

void FUN_40491fdc(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar1 = *param_1;
    *param_1 = (uint)CONCAT21(CONCAT11(*(undefined1 *)((uVar1 >> 0x10 & 0xff) + param_3),
                                       *(undefined1 *)((uVar1 >> 8 & 0xff) + param_3)),
                              *(undefined1 *)((uVar1 & 0xff) + param_3)) | uVar1 & 0xff000000;
    param_1 = param_1 + 1;
  }
  return;
}



/* 40492048 FUN_40492048 */

/* Boundary evidence: original MIPS .pdata 40492048..404922fb. Semantic name remains unreviewed. */

int FUN_40492048(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  undefined *puVar3;
  void *pvVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int local_68;
  LONG *local_64;
  uint *local_60;
  undefined4 local_5c;
  int local_58;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40 [2];
  uint local_38;
  uint *local_30;
  undefined4 local_2c;
  
  local_64 = (LONG *)(param_1 + 0x2c);
  if (local_64 == (LONG *)0x0) {
    local_64 = &local_68;
    local_68 = 0;
  }
  else {
    local_68 = InterlockedIncrement(local_64);
  }
  if (local_68 != 0) {
    iVar7 = -0x7784ffff;
    goto LAB_404922a8;
  }
  uVar5 = *(uint *)(param_1 + 0x1c);
  if ((uVar5 & 0x10000) == 0) {
    if (((uVar5 == 0x21808) || (uVar5 == 0x22009)) || (uVar8 = 0x26200a, uVar5 == 0x26200a)) {
      uVar8 = uVar5;
    }
    local_48 = *(int *)(param_1 + 0x10);
    local_44 = 1;
    local_60 = (uint *)0x0;
    local_5c = 0;
    uVar9 = 3;
    local_58 = 0;
    local_50 = 0;
    local_4c = 0;
    if (uVar8 != uVar5) {
      local_38 = local_48 << 2;
      local_2c = 0;
      iVar7 = FUN_4048903c((int *)&local_60,local_38);
      if (iVar7 == 0) {
        if (local_58 != 0) {
          FUN_404962ec(local_60);
        }
        goto LAB_404920f4;
      }
      uVar9 = 7;
      local_30 = local_60;
    }
    iVar2 = local_58;
    puVar1 = local_60;
    uVar5 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      do {
        iVar7 = FUN_4048d688(param_1,&local_50,uVar9,uVar8,local_40);
        if (iVar7 < 0) {
          if (iVar2 != 0) {
            FUN_404962ec(puVar1);
          }
          goto LAB_404922a8;
        }
        if (uVar8 == 0x21808) {
          puVar6 = local_30;
          for (iVar7 = local_40[0] * 3; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(byte *)puVar6 = *(byte *)((uint)(byte)*puVar6 + param_2);
            puVar6 = (uint *)((int)puVar6 + 1);
          }
        }
        else {
          FUN_40491fdc(local_30,local_40[0],param_2);
        }
        FUN_4048d87c(param_1,&local_50,(int *)local_40);
        uVar5 = uVar5 + 1;
        local_4c = local_4c + 1;
        local_44 = local_44 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0x14));
    }
    if (iVar2 != 0) {
      FUN_404962ec(puVar1);
    }
  }
  else {
    puVar3 = *(undefined **)(param_1 + 0x50);
    if (puVar3 == (undefined *)0x0) {
      puVar3 = FUN_404905b8(uVar5);
    }
    pvVar4 = FUN_404906e0(puVar3,0);
    if (pvVar4 == (void *)0x0) {
LAB_404920f4:
      iVar7 = -0x7ff8fff2;
      goto LAB_404922a8;
    }
    FUN_40491fdc((uint *)((int)pvVar4 + 8),*(int *)((int)pvVar4 + 4),param_2);
    FUN_404962ec(*(LPVOID *)(param_1 + 0x50));
    *(void **)(param_1 + 0x50) = pvVar4;
  }
  iVar7 = 0;
LAB_404922a8:
  InterlockedDecrement(local_64);
  return iVar7;
}



/* 404922fc FUN_404922fc */

/* Boundary evidence: original MIPS .pdata 404922fc..404923e7. Semantic name remains unreviewed. */

int FUN_404922fc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_118 [256];
  uint local_18;
  
  local_18 = DAT_404bd274;
  iVar1 = __gts(param_2,0x3f800000);
  if ((iVar1 == 0) && (iVar1 = __lts(param_2,0xbf800000), iVar1 == 0)) {
    uVar2 = __fpmul(param_2,0x437f0000);
    iVar3 = __fptoli(uVar2);
    iVar5 = 0x100;
    iVar1 = iVar3;
    do {
      if (iVar1 < 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0xff;
        if (iVar1 < 0x100) {
          iVar4 = iVar1;
        }
      }
      auStack_118[iVar1 - iVar3] = (char)iVar4;
      iVar5 = iVar5 + -1;
      iVar1 = iVar1 + 1;
    } while (iVar5 != 0);
    iVar1 = FUN_40492048(param_1 + -0xc,(int)auStack_118);
    FUN_404a438c(local_18);
  }
  else {
    FUN_404a438c(local_18);
    iVar1 = -0x7ff8ffa9;
  }
  return iVar1;
}



/* 404923e8 FUN_404923e8 */

/* Boundary evidence: original MIPS .pdata 404923e8..404924f7. Semantic name remains unreviewed. */

int FUN_404923e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 local_120 [256];
  uint local_20;
  
  local_20 = DAT_404bd274;
  uVar1 = __fpmul(param_2,0x437f0000);
  iVar2 = __fptoli(uVar1);
  uVar1 = __fpmul(param_3,0x437f0000);
  iVar3 = __fptoli(uVar1);
  if (iVar3 < iVar2) {
    FUN_404a438c(local_20);
    iVar2 = -0x7ff8ffa9;
  }
  else {
    iVar7 = 0;
    iVar6 = 0;
    do {
      iVar5 = iVar6 / 0xff + iVar2;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      else if (0xff < iVar5) {
        iVar5 = 0xff;
      }
      puVar4 = local_120 + iVar7;
      iVar7 = iVar7 + 1;
      *puVar4 = (char)iVar5;
      iVar6 = iVar6 + (iVar3 - iVar2);
    } while (iVar7 < 0x100);
    iVar2 = FUN_40492048(param_1 + -0xc,(int)local_120);
    FUN_404a438c(local_20);
  }
  return iVar2;
}



/* 404924f8 FUN_404924f8 */

/* Boundary evidence: original MIPS .pdata 404924f8..40492613. Semantic name remains unreviewed. */

int FUN_404924f8(double param_1,double param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined1 local_120 [256];
  uint local_20;
  
  local_20 = DAT_404bd274;
  iVar2 = __lts(param_4,0);
  if (iVar2 == 0) {
    local_120[0] = 0;
    iVar2 = 1;
    __fptodp(param_4);
    do {
      uVar4 = __litodp(iVar2);
      __dpdiv((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x406fe000);
      uVar4 = FUN_404964d4(param_1,param_2);
      uVar4 = __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x406fe000);
      uVar1 = __dptoul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
      puVar3 = local_120 + iVar2;
      iVar2 = iVar2 + 1;
      *puVar3 = uVar1;
    } while (iVar2 < 0x100);
    iVar2 = FUN_40492048(param_3 + -0xc,(int)local_120);
    FUN_404a438c(local_20);
  }
  else {
    FUN_404a438c(local_20);
    iVar2 = -0x7ff8ffa9;
  }
  return iVar2;
}



/* 40492614 FUN_40492614 */

/* Boundary evidence: original MIPS .pdata 40492614..40492697. Semantic name remains unreviewed. */

undefined4 FUN_40492614(int param_1,SIZE_T param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x3c) < (int)param_2) {
    if (*(LPVOID *)(param_1 + 0x38) != (LPVOID)0x0) {
      FUN_404962ec(*(LPVOID *)(param_1 + 0x38));
    }
    iVar1 = FUN_404962c4(param_2);
    *(int *)(param_1 + 0x38) = iVar1;
    if (iVar1 == 0) {
      param_2 = 0;
    }
    *(SIZE_T *)(param_1 + 0x3c) = param_2;
  }
  if (*(int *)(param_1 + 0x38) == 0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40492698 FUN_40492698 */

/* Boundary evidence: original MIPS .pdata 40492698..404926bf. Semantic name remains unreviewed. */

void FUN_40492698(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  return;
}



/* 404926c0 FUN_404926c0 */

/* Boundary evidence: original MIPS .pdata 404926c0..40492743. Semantic name remains unreviewed. */

int FUN_404926c0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x34) < param_2) {
    if (*(LPVOID *)(param_1 + 0x30) != (LPVOID)0x0) {
      FUN_404962ec(*(LPVOID *)(param_1 + 0x30));
    }
    iVar1 = FUN_404962c4((*(int *)(param_1 + 0x28) + 4) * param_2 * 4);
    *(int *)(param_1 + 0x30) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0x34) = param_2;
  }
  return *(int *)(param_1 + 0x30) + 8;
}



/* 40492794 FUN_40492794 */

/* Boundary evidence: original MIPS .pdata 40492794..404928bf. Semantic name remains unreviewed. */

void FUN_40492794(int param_1,uint *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar4 = *(int *)(param_1 + 0x5c) + -0x10000;
  uVar5 = iVar4 >> 1;
  puVar3 = (uint *)((iVar4 >> 0x11) * 4 + param_3);
  for (iVar4 = *(int *)(param_1 + 0x10); iVar4 != 0; iVar4 = iVar4 + -1) {
    uVar6 = *puVar3;
    iVar1 = (int)(uVar5 & 0xffff) >> 8;
    iVar2 = 0x100 - iVar1;
    uVar7 = puVar3[1];
    *param_2 = ((uVar6 >> 8 & 0xffff00ff) * iVar2 + (uVar7 >> 8 & 0xffff00ff) * iVar1 ^
               (uVar6 & 0xff00ff) * iVar2 + (uVar7 & 0xff00ff) * iVar1 >> 8) & 0xff00ff ^
               (uVar6 >> 8 & 0xff00ff) * iVar2 + (uVar7 >> 8 & 0xff00ff) * iVar1;
    uVar5 = *(int *)(param_1 + 0x5c) + (uVar5 & 0xffff);
    param_2 = param_2 + 1;
    puVar3 = puVar3 + ((int)uVar5 >> 0x10);
  }
  return;
}



/* 404928c0 FUN_404928c0 */

/* Boundary evidence: original MIPS .pdata 404928c0..40492bc7. Semantic name remains unreviewed. */

void FUN_404928c0(int param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar3 = *(int *)(param_1 + 0x5c) + -0x10000;
  uVar4 = iVar3 >> 1;
  puVar2 = (uint *)((iVar3 >> 0x11) * 4 + param_3);
  while (iVar1 != 0) {
    iVar3 = (int)(uVar4 & 0xffff) >> 10;
    iVar5 = iVar3 * 4;
    iVar3 = iVar3 * -4;
    uVar12 = *puVar2;
    iVar6 = *(int *)(&DAT_40482ad0 + iVar5);
    iVar7 = *(int *)(&DAT_40482ad0 + iVar3);
    iVar5 = *(int *)(&DAT_404829d0 + iVar5);
    uVar11 = puVar2[-1];
    iVar8 = *(int *)(&DAT_40482bd0 + iVar3);
    uVar10 = puVar2[1];
    uVar9 = puVar2[2];
    iVar3 = (int)(((int)uVar12 >> 0x18 & 0xffU) * iVar5 + ((int)uVar11 >> 0x18 & 0xffU) * iVar6 +
                  ((int)uVar10 >> 0x18 & 0xffU) * iVar7 + ((int)uVar9 >> 0x18 & 0xffU) * iVar8) >>
            0x10;
    iVar1 = iVar1 + -1;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (0xff < iVar3) {
      iVar3 = 0xff;
    }
    uVar14 = (int)(((int)uVar12 >> 0x10 & 0xffU) * iVar5 + ((int)uVar11 >> 0x10 & 0xffU) * iVar6 +
                   ((int)uVar10 >> 0x10 & 0xffU) * iVar7 + ((int)uVar9 >> 0x10 & 0xffU) * iVar8) >>
             0x10;
    if ((int)uVar14 < 0) {
      uVar14 = 0;
    }
    else if (0xff < (int)uVar14) {
      uVar14 = 0xff;
    }
    uVar13 = (int)(((int)uVar12 >> 8 & 0xffU) * iVar5 + ((int)uVar11 >> 8 & 0xffU) * iVar6 +
                   ((int)uVar10 >> 8 & 0xffU) * iVar7 + ((int)uVar9 >> 8 & 0xffU) * iVar8) >> 0x10;
    if ((int)uVar13 < 0) {
      uVar13 = 0;
    }
    else if (0xff < (int)uVar13) {
      uVar13 = 0xff;
    }
    uVar9 = (int)((uVar12 & 0xff) * iVar5 + (uVar11 & 0xff) * iVar6 + (uVar10 & 0xff) * iVar7 +
                 (uVar9 & 0xff) * iVar8) >> 0x10;
    if ((int)uVar9 < 0) {
      uVar9 = 0;
    }
    else if (0xff < (int)uVar9) {
      uVar9 = 0xff;
    }
    *param_2 = ((iVar3 << 8 | uVar14) << 8 | uVar13) << 8 | uVar9;
    uVar4 = *(int *)(param_1 + 0x5c) + (uVar4 & 0xffff);
    param_2 = param_2 + 1;
    puVar2 = puVar2 + ((int)uVar4 >> 0x10);
  }
  return;
}



/* 40492bc8 FUN_40492bc8 */

/* Boundary evidence: original MIPS .pdata 40492bc8..40492c93. Semantic name remains unreviewed. */

int FUN_40492bc8(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  
  if (*(int *)(param_1 + 0xb8) != 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))(*(int **)(param_1 + 0xc),param_1 + 0xa0)
    ;
    *(undefined4 *)(param_1 + 0xbc) = 0;
    *(undefined4 *)(param_1 + 0xb8) = 0;
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  local_1c = *(int *)(param_1 + 0x54);
  iVar2 = *(int *)(param_1 + 0x14) - local_1c;
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar2 <= *(int *)(param_1 + 0x18)) {
    iVar1 = iVar2;
  }
  local_18 = *(undefined4 *)(param_1 + 0x10);
  local_14 = local_1c + iVar1;
  local_20 = 0;
  iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))
                    (*(int **)(param_1 + 0xc),&local_20,*(undefined4 *)(param_1 + 0x24),1,
                     param_1 + 0xa0);
  if (-1 < iVar2) {
    iVar2 = 0;
    *(int *)(param_1 + 0xbc) = iVar1;
    *(int *)(param_1 + 0xb8) = iVar1;
    *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0xb0);
  }
  return iVar2;
}



/* 40492c94 FUN_40492c94 */

/* Boundary evidence: original MIPS .pdata 40492c94..40492ce3. Semantic name remains unreviewed. */

undefined4 FUN_40492c94(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xb8) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))(*(int **)(param_1 + 0xc),param_1 + 0xa0)
    ;
  }
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  return uVar1;
}



/* 40492ce4 FUN_40492ce4 */

/* Boundary evidence: original MIPS .pdata 40492ce4..40492d7f. Semantic name remains unreviewed. */

undefined4 FUN_40492ce4(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40482c64,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40482c14,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 40492d80 FUN_40492d80 */

/* Boundary evidence: original MIPS .pdata 40492d80..40492d9b. Semantic name remains unreviewed. */

void FUN_40492d80(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 40492d9c FUN_40492d9c */

/* Boundary evidence: original MIPS .pdata 40492d9c..40492df7. Semantic name remains unreviewed. */

LONG FUN_40492d9c(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x3c))(param_1,1);
  }
  return LVar1;
}



/* 40492df8 FUN_40492df8 */

/* Boundary evidence: original MIPS .pdata 40492df8..40492e3b. Semantic name remains unreviewed. */

undefined4 * FUN_40492df8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40482bd4;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 40492e3c FUN_40492e3c */

/* Boundary evidence: original MIPS .pdata 40492e3c..40492ebb. Semantic name remains unreviewed. */

void FUN_40492e3c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40482c24;
  (**(code **)(*(int *)param_1[3] + 8))();
  if ((LPVOID)param_1[0xc] != (LPVOID)0x0) {
    FUN_404962ec((LPVOID)param_1[0xc]);
  }
  if ((LPVOID)param_1[0xe] != (LPVOID)0x0) {
    FUN_404962ec((LPVOID)param_1[0xe]);
  }
  param_1[2] = 0x4c494146;
  *param_1 = &PTR_FUN_40482bd4;
  return;
}



/* 40492ebc FUN_40492ebc */

/* Boundary evidence: original MIPS .pdata 40492ebc..40492f0f. Semantic name remains unreviewed. */

void FUN_40492ebc(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_40492c94(param_1);
  if (iVar1 < 0) {
    param_2 = iVar1;
  }
  (**(code **)(**(int **)(param_1 + 0xc) + 0x10))(*(int **)(param_1 + 0xc),param_2);
  return;
}



/* 40492f10 FUN_40492f10 */

/* Boundary evidence: original MIPS .pdata 40492f10..40492fdf. Semantic name remains unreviewed. */

undefined4 FUN_40492f10(int param_1,int *param_2,undefined4 param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  if ((*param_2 == 0) && (param_2[2] == *(int *)(param_1 + 0x28))) {
    if ((param_2[1] < param_2[3]) &&
       (((param_2[3] <= *(int *)(param_1 + 0x2c) && (*(int *)(param_1 + 0x50) == param_2[1])) &&
        (param_4 != 0)))) {
      *param_5 = *(int *)(param_1 + 0x28);
      iVar2 = param_2[3];
      iVar1 = param_2[1];
      param_5[5] = 0;
      param_5[1] = iVar2 - iVar1;
      param_5[3] = *(int *)(param_1 + 0x24);
      param_5[2] = (*(int *)(param_1 + 0x28) + 4) * 4;
      iVar1 = FUN_404926c0(param_1,iVar2 - iVar1);
      param_5[4] = iVar1;
      if (iVar1 != 0) {
        return 0;
      }
      return 0x8007000e;
    }
  }
  return 0x80070057;
}



/* 40492fe0 FUN_40492fe0 */

/* Boundary evidence: original MIPS .pdata 40492fe0..404930e3. Semantic name remains unreviewed. */

int FUN_40492fe0(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar4 = param_2[1];
  puVar3 = (uint *)param_2[4];
  while( true ) {
    if (uVar4 == 0) {
      return 0;
    }
    uVar4 = uVar4 - 1;
    if ((*(char *)(param_1 + 0xc4) != '\0') && (uVar6 = 0, puVar5 = puVar3, *param_2 != 0)) {
      do {
        uVar1 = FUN_4048c0a0(*puVar5);
        uVar6 = uVar6 + 1;
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
      } while (uVar6 < *param_2);
    }
    if (*(int *)(param_1 + 0x9c) != 0) {
      puVar3[-1] = *puVar3;
      puVar3[-2] = *puVar3;
      puVar3[*(int *)(param_1 + 0x28) + 1] = puVar3[*(int *)(param_1 + 0x28) + -1];
      puVar3[*(int *)(param_1 + 0x28)] = (puVar3 + *(int *)(param_1 + 0x28))[1];
    }
    iVar2 = (**(code **)(param_1 + 0x44))(param_1,puVar3);
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
    if (iVar2 < 0) break;
    puVar3 = (uint *)(param_2[2] + (int)puVar3);
  }
  return iVar2;
}



/* 404930e4 FUN_404930e4 */

/* Boundary evidence: original MIPS .pdata 404930e4..404932a3. Semantic name remains unreviewed. */

int FUN_404930e4(int param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  
  uVar4 = param_3[1];
  puVar7 = (uint *)param_3[4];
  iVar5 = 0;
  if (*(int *)(param_1 + 0x9c) == 0) {
    while (uVar4 != 0) {
      uVar4 = uVar4 - 1;
      if ((*(char *)(param_1 + 0xc4) != '\0') && (uVar8 = 0, puVar2 = puVar7, *param_3 != 0)) {
        do {
          uVar1 = FUN_4048c0a0(*puVar2);
          uVar8 = uVar8 + 1;
          *puVar2 = uVar1;
          puVar2 = puVar2 + 1;
        } while (uVar8 < *param_3);
      }
      iVar5 = (**(code **)(param_1 + 0x44))(param_1,puVar7);
      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
      if (iVar5 < 0) {
        return iVar5;
      }
      puVar7 = (uint *)(param_3[2] + (int)puVar7);
    }
  }
  else {
    puVar2 = (uint *)FUN_404926c0(param_1,1);
    if (puVar2 == (uint *)0x0) {
      iVar5 = -0x7ff8fff2;
    }
    else {
      while (uVar4 != 0) {
        uVar4 = uVar4 - 1;
        if ((*(char *)(param_1 + 0xc4) != '\0') && (uVar8 = 0, puVar6 = puVar7, *param_3 != 0)) {
          do {
            uVar1 = FUN_4048c0a0(*puVar6);
            uVar8 = uVar8 + 1;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 1;
          } while (uVar8 < *param_3);
        }
        uVar8 = *puVar7;
        iVar5 = *(int *)(param_1 + 0x28);
        puVar2[-1] = uVar8;
        puVar2[-2] = uVar8;
        puVar6 = puVar2;
        puVar3 = puVar7;
        for (; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar6 = *puVar3;
          puVar6 = puVar6 + 1;
          puVar3 = puVar3 + 1;
        }
        uVar8 = puVar3[-1];
        puVar6[1] = uVar8;
        *puVar6 = uVar8;
        iVar5 = (**(code **)(param_1 + 0x44))(param_1,puVar2);
        *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
        if (iVar5 < 0) {
          return iVar5;
        }
        puVar7 = (uint *)(param_3[2] + (int)puVar7);
      }
    }
  }
  return iVar5;
}



/* 404932a4 FUN_404932a4 */

/* Boundary evidence: original MIPS .pdata 404932a4..4049346b. Semantic name remains unreviewed. */

int FUN_404932a4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar3 = *(int *)(param_1 + 0x2c);
  iVar2 = *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x4c);
  *(int *)(param_1 + 0x4c) = iVar2;
  if (iVar3 <= iVar2) {
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar2 == -0x80000000)) {
      trap(0x1800);
    }
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar2 == -0x80000000)) {
      trap(0x1800);
    }
    *(int *)(param_1 + 0x4c) = iVar2 % iVar3;
    if ((*(int *)(param_1 + 0xbc) == 0) && (iVar1 = FUN_40492bc8(param_1), iVar1 < 0)) {
      return iVar1;
    }
    puVar5 = *(undefined4 **)(param_1 + 0xc0);
    *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + -1;
    *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xa8) + (int)puVar5;
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    (**(code **)(param_1 + 0x48))(param_1,puVar5,param_2);
    iVar2 = iVar2 / iVar3 + -1;
    if (*(int *)(param_1 + 0xbc) < iVar2) {
      puVar4 = *(undefined4 **)(param_1 + 0x38);
      for (iVar3 = *(int *)(param_1 + 0x10); iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar5 = *(undefined4 **)(param_1 + 0x38);
    }
    while (iVar2 != 0) {
      iVar2 = iVar2 + -1;
      if ((*(int *)(param_1 + 0xbc) == 0) && (iVar3 = FUN_40492bc8(param_1), iVar3 < 0)) {
        return iVar3;
      }
      iVar1 = *(int *)(param_1 + 0xc0);
      *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + -1;
      iVar3 = *(int *)(param_1 + 0x10);
      *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xa8) + iVar1;
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
      if (iVar3 != 0) {
        puVar4 = puVar5;
        do {
          iVar3 = iVar3 + -1;
          *(undefined4 *)((iVar1 - (int)puVar5) + (int)puVar4) = *puVar4;
          puVar4 = puVar4 + 1;
        } while (iVar3 != 0);
      }
    }
  }
  return 0;
}



/* 4049346c FUN_4049346c */

void FUN_4049346c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar3 = *(int *)(param_1 + 0x2c) + -1;
  if (param_2 < 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = iVar3;
    if (param_2 <= iVar3) {
      iVar2 = param_2;
    }
  }
  if (param_2 + 1 <= iVar3) {
    iVar3 = param_2 + 1;
  }
  iVar4 = *(int *)(param_1 + 0x6c);
  *(int *)(param_1 + 0x70) = iVar2;
  if (iVar2 != iVar4) {
    if (iVar2 == *(int *)(param_1 + 0x78)) {
      *(int *)(param_1 + 0x6c) = iVar2;
      uVar1 = *(undefined4 *)(param_1 + 0x74);
      *(int *)(param_1 + 0x78) = iVar4;
      *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x80);
      *(undefined4 *)(param_1 + 0x80) = uVar1;
    }
    else {
      *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
    }
  }
  *(int *)(param_1 + 0x7c) = iVar3;
  if (iVar3 != *(int *)(param_1 + 0x78)) {
    if (iVar3 == *(int *)(param_1 + 0x6c)) {
      iVar2 = *(int *)(param_1 + 0x10);
      puVar5 = *(undefined4 **)(param_1 + 0x74);
      puVar6 = *(undefined4 **)(param_1 + 0x80);
      *(int *)(param_1 + 0x78) = iVar3;
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar5;
        puVar6 = puVar6 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
    }
  }
  return;
}



/* 40493538 FUN_40493538 */

/* Boundary evidence: original MIPS .pdata 40493538..40493823. Semantic name remains unreviewed. */

int FUN_40493538(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  byte *pbVar16;
  int iVar17;
  
  if (*(int *)(param_1 + 0x54) < *(int *)(param_1 + 0x14)) {
    (**(code **)(param_1 + 0x48))(param_1,*(undefined4 *)(param_1 + 0x38),param_2);
    iVar17 = *(int *)(param_1 + 0x10);
    piVar15 = *(int **)(param_1 + 0x40);
    pbVar16 = *(byte **)(param_1 + 0x38);
    if (*(int *)(param_1 + 0x60) < 0x10001) {
      if ((*(int *)(param_1 + 0xbc) == 0) && (iVar5 = FUN_40492bc8(param_1), iVar5 < 0)) {
        return iVar5;
      }
      iVar5 = *(int *)(param_1 + 0xc0);
      *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + -1;
      *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xa8) + iVar5;
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
      if (iVar17 != 0) {
        puVar6 = (undefined1 *)(iVar5 + 2);
        do {
          iVar5 = (uint)*pbVar16 * *(int *)(param_1 + 0x60);
          iVar10 = *piVar15;
          iVar14 = *(int *)(param_1 + 100);
          iVar17 = iVar17 + -1;
          *piVar15 = (uint)*pbVar16 * 0x10000 - iVar5;
          iVar2 = (uint)pbVar16[1] * *(int *)(param_1 + 0x60);
          iVar7 = piVar15[1];
          iVar11 = *(int *)(param_1 + 100);
          piVar15[1] = (uint)pbVar16[1] * 0x10000 - iVar2;
          iVar3 = (uint)pbVar16[2] * *(int *)(param_1 + 0x60);
          iVar8 = piVar15[2];
          iVar12 = *(int *)(param_1 + 100);
          piVar15[2] = (uint)pbVar16[2] * 0x10000 - iVar3;
          pbVar1 = pbVar16 + 3;
          iVar4 = (uint)*pbVar1 * *(int *)(param_1 + 0x60);
          iVar9 = piVar15[3];
          iVar13 = *(int *)(param_1 + 100);
          pbVar16 = pbVar16 + 4;
          piVar15[3] = (uint)*pbVar1 * 0x10000 - iVar4;
          piVar15 = piVar15 + 4;
          puVar6[-1] = (char)((uint)((int)((longlong)(iVar7 + iVar2) * (longlong)iVar11 >> 0x10) +
                                    0x8000) >> 0x10);
          *puVar6 = (char)((uint)((int)((longlong)(iVar3 + iVar8) * (longlong)iVar12 >> 0x10) +
                                 0x8000) >> 0x10);
          puVar6[-2] = (char)((uint)((int)((longlong)(iVar10 + iVar5) * (longlong)iVar14 >> 0x10) +
                                    0x8000) >> 0x10);
          puVar6[1] = (char)((uint)((int)((longlong)(iVar9 + iVar4) * (longlong)iVar13 >> 0x10) +
                                   0x8000) >> 0x10);
          puVar6 = puVar6 + 4;
        } while (iVar17 != 0);
      }
      *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) + -0x10000;
    }
    else {
      for (; iVar17 != 0; iVar17 = iVar17 + -1) {
        *piVar15 = (uint)*pbVar16 * 0x10000 + *piVar15;
        piVar15[1] = (uint)pbVar16[1] * 0x10000 + piVar15[1];
        piVar15[2] = (uint)pbVar16[2] * 0x10000 + piVar15[2];
        piVar15[3] = (uint)pbVar16[3] * 0x10000 + piVar15[3];
        piVar15 = piVar15 + 4;
        pbVar16 = pbVar16 + 4;
      }
      *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + -0x10000;
    }
  }
  return 0;
}



/* 40493824 FUN_40493824 */

/* Boundary evidence: original MIPS .pdata 40493824..40493a3b. Semantic name remains unreviewed. */

void FUN_40493824(int param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar6 = *(int *)(param_1 + 0x10);
  uVar5 = *(uint *)(param_1 + 0x5c);
  pbVar2 = (byte *)(param_3 + 2);
  iVar15 = *(int *)(param_1 + 0x68);
  iVar11 = 0;
  iVar12 = 0;
  iVar13 = 0;
  iVar14 = 0;
  puVar3 = (undefined1 *)(param_2 + 2);
  do {
    if (uVar5 < 0x10001) {
      iVar8 = pbVar2[-2] * uVar5;
      iVar9 = iVar8 + iVar11;
      iVar1 = pbVar2[-1] * uVar5;
      iVar11 = (uint)pbVar2[-2] * 0x10000 - iVar8;
      iVar7 = iVar1 + iVar12;
      iVar8 = *pbVar2 * uVar5;
      iVar12 = (uint)pbVar2[-1] * 0x10000 - iVar1;
      iVar10 = iVar8 + iVar13;
      iVar1 = pbVar2[1] * uVar5;
      iVar13 = (uint)*pbVar2 * 0x10000 - iVar8;
      iVar8 = iVar1 + iVar14;
      iVar14 = (uint)pbVar2[1] * 0x10000 - iVar1;
      puVar3[-2] = (char)((uint)((int)((longlong)iVar9 * (longlong)iVar15 >> 0x10) + 0x8000) >> 0x10
                         );
      *puVar3 = (char)((uint)((int)((longlong)iVar10 * (longlong)iVar15 >> 0x10) + 0x8000) >> 0x10);
      puVar3[-1] = (char)((uint)((int)((longlong)iVar7 * (longlong)iVar15 >> 0x10) + 0x8000) >> 0x10
                         );
      puVar3[1] = (char)((uint)((int)((longlong)iVar8 * (longlong)iVar15 >> 0x10) + 0x8000) >> 0x10)
      ;
      puVar4 = puVar3 + 4;
      if (puVar3 + 2 == (undefined1 *)(iVar6 * 4 + param_2)) {
        return;
      }
      uVar5 = uVar5 + *(int *)(param_1 + 0x5c);
    }
    else {
      iVar11 = (uint)pbVar2[-2] * 0x10000 + iVar11;
      iVar12 = (uint)pbVar2[-1] * 0x10000 + iVar12;
      iVar13 = (uint)*pbVar2 * 0x10000 + iVar13;
      iVar14 = (uint)pbVar2[1] * 0x10000 + iVar14;
      puVar4 = puVar3;
    }
    uVar5 = uVar5 - 0x10000;
    pbVar2 = pbVar2 + 4;
    puVar3 = puVar4;
  } while( true );
}



/* 40493a3c FUN_40493a3c */

undefined4 FUN_40493a3c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  uVar1 = 1;
  iVar2 = *(int *)(param_1 + 0x2c) + -1;
  iVar10 = param_2 + -1;
  iVar11 = 0;
  piVar8 = (int *)(param_1 + 0x70);
  do {
    if (iVar10 < 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = iVar2;
      if (iVar10 <= iVar2) {
        iVar7 = iVar10;
      }
    }
    iVar10 = iVar10 + 1;
    *piVar8 = iVar7;
    if (iVar7 != piVar8[-1]) {
      iVar9 = iVar11 + 1;
      if (iVar9 < 4) {
        piVar3 = piVar8 + 2;
        do {
          if (iVar7 == *piVar3) break;
          iVar9 = iVar9 + 1;
          piVar3 = piVar3 + 3;
        } while (iVar9 < 4);
        if (iVar9 < 4) {
          puVar6 = (undefined4 *)piVar8[1];
          if (iVar7 < iVar2) {
            iVar4 = iVar9 * 0xc + param_1;
            piVar8[1] = *(int *)(iVar4 + 0x74);
            *(undefined4 **)(iVar4 + 0x74) = puVar6;
            *(int *)((iVar9 + 9) * 0xc + param_1) = piVar8[-1];
          }
          else {
            puVar5 = *(undefined4 **)(iVar9 * 0xc + param_1 + 0x74);
            for (iVar9 = *(int *)(param_1 + 0x10); iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar6 = *puVar5;
              puVar6 = puVar6 + 1;
              puVar5 = puVar5 + 1;
            }
          }
          piVar8[-1] = iVar7;
          goto LAB_40493b4c;
        }
      }
      piVar8[-1] = -1;
      uVar1 = 0;
    }
LAB_40493b4c:
    iVar11 = iVar11 + 1;
    piVar8 = piVar8 + 3;
    if (3 < iVar11) {
      return uVar1;
    }
  } while( true );
}



/* 40493b64 FUN_40493b64 */

/* Boundary evidence: original MIPS .pdata 40493b64..40493baf. Semantic name remains unreviewed. */

undefined4 * FUN_40493b64(undefined4 *param_1,uint param_2)

{
  FUN_40492e3c(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 40493bb0 FUN_40493bb0 */

/* Boundary evidence: original MIPS .pdata 40493bb0..40493e07. Semantic name remains unreviewed. */

int FUN_40493bb0(int param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar6 = *(int *)(param_1 + 0x50);
  if (iVar6 == *(int *)(param_1 + 0x70)) {
    (**(code **)(param_1 + 0x48))(param_1,*(undefined4 *)(param_1 + 0x74),param_2);
    iVar6 = *(int *)(param_1 + 0x50);
    *(int *)(param_1 + 0x6c) = iVar6;
  }
  if (iVar6 == *(int *)(param_1 + 0x7c)) {
    (**(code **)(param_1 + 0x48))(param_1,*(undefined4 *)(param_1 + 0x80),param_2);
    *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x50);
  }
  if (*(int *)(param_1 + 0x54) < *(int *)(param_1 + 0x14)) {
    do {
      if (*(int *)(param_1 + 0x78) == -1) {
        return 0;
      }
      if (*(int *)(param_1 + 0x6c) == -1) {
        return 0;
      }
      if ((*(int *)(param_1 + 0xbc) == 0) && (iVar6 = FUN_40492bc8(param_1), iVar6 < 0)) {
        return iVar6;
      }
      puVar5 = *(uint **)(param_1 + 0xc0);
      *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + -1;
      iVar4 = *(int *)(param_1 + 0x60) >> 8;
      puVar1 = *(uint **)(param_1 + 0x74);
      puVar3 = *(uint **)(param_1 + 0x80);
      iVar6 = *(int *)(param_1 + 0x10);
      iVar2 = 0x100 - iVar4;
      *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xa8) + (int)puVar5;
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
      if (iVar6 != 0) {
        if (iVar4 == 0) {
          iVar2 = (int)puVar5 - (int)puVar1;
          do {
            iVar6 = iVar6 + -1;
            *(uint *)(iVar2 + (int)puVar1) = *puVar1;
            puVar1 = puVar1 + 1;
          } while (iVar6 != 0);
        }
        else {
          do {
            uVar7 = *puVar1;
            uVar8 = *puVar3;
            iVar6 = iVar6 + -1;
            puVar1 = puVar1 + 1;
            puVar3 = puVar3 + 1;
            *puVar5 = ((uVar7 >> 8 & 0xffff00ff) * iVar2 + (uVar8 >> 8 & 0xffff00ff) * iVar4 ^
                      (uVar7 & 0xff00ff) * iVar2 + (uVar8 & 0xff00ff) * iVar4 >> 8) & 0xff00ff ^
                      (uVar7 >> 8 & 0xff00ff) * iVar2 + (uVar8 >> 8 & 0xff00ff) * iVar4;
            puVar5 = puVar5 + 1;
          } while (iVar6 != 0);
        }
      }
      iVar6 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60);
      *(int *)(param_1 + 0x60) = iVar6;
      iVar6 = (iVar6 >> 0x10) + *(int *)(param_1 + 0x4c);
      *(int *)(param_1 + 0x4c) = iVar6;
      *(undefined2 *)(param_1 + 0x62) = 0;
      FUN_4049346c(param_1,iVar6);
    } while (*(int *)(param_1 + 0x54) < *(int *)(param_1 + 0x14));
  }
  return 0;
}



/* 40493e08 FUN_40493e08 */

/* Boundary evidence: original MIPS .pdata 40493e08..40493ea7. Semantic name remains unreviewed. */

int FUN_40493e08(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(code **)(param_1 + 0x44) = FUN_40493bb0;
  iVar1 = FUN_40492614(param_1,*(int *)(param_1 + 0x10) << 3);
  if (-1 < iVar1) {
    *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x38);
    iVar3 = *(int *)(param_1 + 0x58) + -0x10000;
    iVar2 = iVar3 >> 0x11;
    *(int *)(param_1 + 0x60) = iVar3 >> 1;
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x10) * 4 + *(int *)(param_1 + 0x38);
    *(int *)(param_1 + 0x4c) = iVar2;
    *(undefined2 *)(param_1 + 0x62) = 0;
    FUN_4049346c(param_1,iVar2);
  }
  return iVar1;
}



/* 40493ea8 FUN_40493ea8 */

/* Boundary evidence: original MIPS .pdata 40493ea8..4049432b. Semantic name remains unreviewed. */

int FUN_40493ea8(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint *puVar18;
  uint uVar19;
  int iVar20;
  
  piVar10 = (int *)(param_1 + 0x70);
  iVar12 = 4;
  do {
    if (*(int *)(param_1 + 0x50) == *piVar10) {
      (**(code **)(param_1 + 0x48))(param_1,piVar10[1],param_2);
      piVar10[-1] = *(int *)(param_1 + 0x50);
    }
    iVar12 = iVar12 + -1;
    piVar10 = piVar10 + 3;
  } while (iVar12 != 0);
  if ((((*(int *)(param_1 + 0x90) != -1) && (*(int *)(param_1 + 0x84) != -1)) &&
      (*(int *)(param_1 + 0x78) != -1)) &&
     ((*(int *)(param_1 + 0x6c) != -1 && (*(int *)(param_1 + 0x54) < *(int *)(param_1 + 0x14))))) {
    do {
      if ((*(int *)(param_1 + 0xbc) == 0) && (iVar12 = FUN_40492bc8(param_1), iVar12 < 0)) {
        return iVar12;
      }
      puVar9 = *(undefined4 **)(param_1 + 0xc0);
      *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + -1;
      iVar12 = *(int *)(param_1 + 0x60) >> 10;
      *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xa8) + (int)puVar9;
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
      if (iVar12 == 0) {
        puVar6 = *(undefined4 **)(param_1 + 0x80);
        for (iVar12 = *(int *)(param_1 + 0x10); iVar12 != 0; iVar12 = iVar12 + -1) {
          *puVar9 = *puVar6;
          puVar9 = puVar9 + 1;
          puVar6 = puVar6 + 1;
        }
      }
      else {
        iVar8 = *(int *)(&DAT_40482ad0 + iVar12 * 4);
        iVar14 = *(int *)(&DAT_404829d0 + iVar12 * 4);
        iVar15 = *(int *)(&DAT_40482ad0 + iVar12 * -4);
        iVar16 = *(int *)(&DAT_40482bd0 + iVar12 * -4);
        puVar18 = *(uint **)(param_1 + 0x8c);
        iVar12 = 0;
        if (0 < *(int *)(param_1 + 0x10)) {
          iVar7 = *(int *)(param_1 + 0x74) - (int)puVar18;
          iVar20 = *(int *)(param_1 + 0x98) - (int)puVar18;
          iVar11 = *(int *)(param_1 + 0x80) - (int)puVar18;
          iVar17 = (int)puVar9 - (int)puVar18;
          do {
            uVar4 = *puVar18;
            uVar5 = *(uint *)((int)puVar18 + iVar20);
            uVar13 = *(uint *)((int)puVar18 + iVar7);
            uVar3 = *(uint *)((int)puVar18 + iVar11);
            iVar1 = (int)(((int)uVar4 >> 0x18 & 0xffU) * iVar15 +
                          ((int)uVar13 >> 0x18 & 0xffU) * iVar8 +
                          ((int)uVar3 >> 0x18 & 0xffU) * iVar14 +
                         ((int)uVar5 >> 0x18 & 0xffU) * iVar16) >> 0x10;
            if (iVar1 < 0) {
              iVar1 = 0;
            }
            else if (0xff < iVar1) {
              iVar1 = 0xff;
            }
            uVar2 = (int)(((int)uVar4 >> 0x10 & 0xffU) * iVar15 +
                          ((int)uVar13 >> 0x10 & 0xffU) * iVar8 +
                          ((int)uVar3 >> 0x10 & 0xffU) * iVar14 +
                         ((int)uVar5 >> 0x10 & 0xffU) * iVar16) >> 0x10;
            if ((int)uVar2 < 0) {
              uVar2 = 0;
            }
            else if (0xff < (int)uVar2) {
              uVar2 = 0xff;
            }
            uVar19 = (int)(((int)uVar4 >> 8 & 0xffU) * iVar15 + ((int)uVar13 >> 8 & 0xffU) * iVar8 +
                           ((int)uVar3 >> 8 & 0xffU) * iVar14 + ((int)uVar5 >> 8 & 0xffU) * iVar16)
                     >> 0x10;
            if ((int)uVar19 < 0) {
              uVar19 = 0;
            }
            else if (0xff < (int)uVar19) {
              uVar19 = 0xff;
            }
            uVar3 = (int)((uVar4 & 0xff) * iVar15 + (uVar13 & 0xff) * iVar8 +
                          (uVar3 & 0xff) * iVar14 + (uVar5 & 0xff) * iVar16) >> 0x10;
            if ((int)uVar3 < 0) {
              uVar3 = 0;
            }
            else if (0xff < (int)uVar3) {
              uVar3 = 0xff;
            }
            *(uint *)((int)puVar18 + iVar17) = ((iVar1 << 8 | uVar2) << 8 | uVar19) << 8 | uVar3;
            iVar12 = iVar12 + 1;
            puVar18 = puVar18 + 1;
          } while (iVar12 < *(int *)(param_1 + 0x10));
        }
      }
      iVar8 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60);
      iVar12 = (iVar8 >> 0x10) + *(int *)(param_1 + 0x4c);
      *(int *)(param_1 + 0x60) = iVar8;
      *(int *)(param_1 + 0x4c) = iVar12;
      *(undefined2 *)(param_1 + 0x62) = 0;
      iVar12 = FUN_40493a3c(param_1,iVar12);
    } while ((iVar12 != 0) && (*(int *)(param_1 + 0x54) < *(int *)(param_1 + 0x14)));
  }
  return 0;
}



/* 4049432c FUN_4049432c */

/* Boundary evidence: original MIPS .pdata 4049432c..40494413. Semantic name remains unreviewed. */

undefined4 *
FUN_4049432c(undefined4 *param_1,int *param_2,uint param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  
  param_1[1] = 1;
  *param_1 = &PTR_FUN_40482c24;
  param_1[3] = param_2;
  (**(code **)(*param_2 + 4))(param_2);
  param_1[4] = param_3;
  param_1[5] = param_4;
  if ((param_5 < 1) || (4 < param_5)) {
    param_5 = 2;
  }
  param_1[8] = param_5;
  param_1[7] = param_5;
  uVar1 = DAT_404bd390 / param_3;
  if (param_3 == 0) {
    trap(0x1c00);
  }
  param_1[6] = uVar1;
  if ((int)uVar1 < 4) {
    param_1[6] = 4;
  }
  param_1[0x2f] = 0;
  param_1[0x2e] = 0;
  param_1[0x30] = 0;
  param_1[0xe] = 0;
  param_1[0xc] = 0;
  param_1[0xf] = 0;
  param_1[0xd] = 0;
  *(undefined1 *)(param_1 + 0x31) = 0;
  param_1[2] = 0x4c494146;
  return param_1;
}



/* 40494414 FUN_40494414 */

/* Boundary evidence: original MIPS .pdata 40494414..4049490b. Semantic name remains unreviewed. */

int FUN_40494414(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *_Dst;
  SIZE_T SVar7;
  SIZE_T SVar8;
  uint uVar9;
  uint uVar10;
  code *pcVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  uVar17 = __litodp(*(undefined4 *)(param_1 + 0x28));
  uVar3 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar18 = __litodp(*(undefined4 *)(param_1 + 0x10));
  uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = __dpmul((int)uVar17,uVar3,0,0x40f00000);
  uVar19 = __dpdiv((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar4);
  iVar1 = __dptoli((int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
  *(int *)(param_1 + 0x5c) = iVar1;
  uVar19 = __litodp(*(undefined4 *)(param_1 + 0x2c));
  uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar20 = __litodp(*(undefined4 *)(param_1 + 0x14));
  uVar6 = (undefined4)((ulonglong)uVar20 >> 0x20);
  uVar21 = __dpmul((int)uVar19,uVar5,0,0x40f00000);
  uVar21 = __dpdiv((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),(int)uVar20,uVar6);
  iVar2 = __dptoli((int)uVar21,(int)((ulonglong)uVar21 >> 0x20));
  *(int *)(param_1 + 0x58) = iVar2;
  uVar18 = __dpmul((int)uVar18,uVar4,0,0x40f00000);
  uVar17 = __dpdiv((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,uVar3);
  uVar3 = __dptoli((int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
  *(undefined4 *)(param_1 + 0x68) = uVar3;
  uVar17 = __dpmul((int)uVar20,uVar6,0,0x40f00000);
  uVar17 = __dpdiv((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,uVar5);
  uVar3 = __dptoli((int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
  uVar10 = (int)(0x10000U - iVar1) >> 0x1f;
  *(undefined4 *)(param_1 + 100) = uVar3;
  if ((int)((0x10000U - iVar1 ^ uVar10) - uVar10) < 0x51f) {
    *(undefined4 *)(param_1 + 0x1c) = 1;
  }
  uVar10 = (int)(0x10000U - iVar2) >> 0x1f;
  if ((int)((0x10000U - iVar2 ^ uVar10) - uVar10) < 0x51f) {
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  uVar10 = *(uint *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x9c) = 4;
  if (iVar1 == 2) {
    pcVar11 = FUN_40492794;
LAB_40494668:
    *(code **)(param_1 + 0x48) = pcVar11;
  }
  else if (iVar1 == 3) {
    if (*(int *)(param_1 + 0x28) <= (int)uVar10) {
      pcVar11 = FUN_40492794;
      goto LAB_40494668;
    }
    *(code **)(param_1 + 0x48) = FUN_40493824;
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  else {
    if (iVar1 == 4) {
      pcVar11 = FUN_404928c0;
      goto LAB_40494668;
    }
    *(undefined4 *)(param_1 + 0x9c) = 0;
    *(undefined1 **)(param_1 + 0x48) = &LAB_40492744;
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 == 2) {
LAB_404948ac:
    iVar1 = FUN_40493e08(param_1);
LAB_404948b8:
    if (-1 < iVar1) {
      uVar3 = 0x63534231;
      goto LAB_404948d4;
    }
  }
  else {
    if (iVar1 == 3) {
      if (*(int *)(param_1 + 0x14) < *(int *)(param_1 + 0x2c)) {
        iVar12 = -0x7ff8fdea;
        uVar15 = 0xffffffff;
        *(code **)(param_1 + 0x44) = FUN_40493538;
        *(int *)(param_1 + 0x60) = iVar2;
        uVar9 = uVar15;
        iVar1 = iVar12;
        if ((int)((ulonglong)uVar10 * 4 >> 0x20) == 0) {
          iVar1 = 0;
          uVar9 = (uint)((ulonglong)uVar10 * 4);
        }
        if (-1 < iVar1) {
          uVar16 = uVar9 + 3 & 0xfffffffc;
          uVar9 = uVar15;
          iVar1 = iVar12;
          if ((int)((ulonglong)uVar10 * 4 >> 0x20) == 0) {
            iVar1 = 0;
            uVar9 = (uint)((ulonglong)uVar10 * 4);
          }
          if (-1 < iVar1) {
            iVar1 = iVar12;
            uVar10 = uVar15;
            if ((int)((ulonglong)uVar9 * 4 >> 0x20) == 0) {
              iVar1 = 0;
              uVar10 = (size_t)((ulonglong)uVar9 * 4);
            }
            if (-1 < iVar1) {
              iVar1 = iVar12;
              if (uVar16 <= uVar10 + uVar16) {
                iVar1 = 0;
                uVar15 = uVar10 + uVar16;
              }
              if ((-1 < iVar1) && (iVar1 = FUN_40492614(param_1,uVar15), -1 < iVar1)) {
                _Dst = (void *)(*(int *)(param_1 + 0x38) + uVar16);
                *(void **)(param_1 + 0x40) = _Dst;
                memset(_Dst,0,uVar10);
                goto LAB_404948b8;
              }
            }
          }
        }
        goto LAB_404948cc;
      }
      goto LAB_404948ac;
    }
    if (iVar1 != 4) {
      *(code **)(param_1 + 0x44) = FUN_404932a4;
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x2c) >> 1;
      iVar1 = FUN_40492614(param_1,uVar10 << 2);
      goto LAB_404948b8;
    }
    *(code **)(param_1 + 0x44) = FUN_40493ea8;
    SVar8 = 0xffffffff;
    iVar1 = -0x7ff8fdea;
    if ((int)((ulonglong)uVar10 * 4 >> 0x20) == 0) {
      iVar1 = 0;
      SVar8 = (uint)((ulonglong)uVar10 * 4);
    }
    if (-1 < iVar1) {
      SVar7 = 0xffffffff;
      iVar1 = -0x7ff8fdea;
      if ((int)((ulonglong)SVar8 * 4 >> 0x20) == 0) {
        iVar1 = 0;
        SVar7 = (SIZE_T)((ulonglong)SVar8 * 4);
      }
      if ((-1 < iVar1) && (iVar1 = FUN_40492614(param_1,SVar7), -1 < iVar1)) {
        iVar14 = *(int *)(param_1 + 0x10) * 4;
        *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x38);
        iVar2 = *(int *)(param_1 + 0x38) + iVar14;
        iVar12 = iVar2 + iVar14;
        *(int *)(param_1 + 0x80) = iVar2;
        *(int *)(param_1 + 0x8c) = iVar12;
        iVar13 = *(int *)(param_1 + 0x58) + -0x10000;
        iVar2 = iVar13 >> 0x11;
        *(int *)(param_1 + 0x60) = iVar13 >> 1;
        *(int *)(param_1 + 0x98) = iVar12 + iVar14;
        *(undefined4 *)(param_1 + 0x90) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x84) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
        *(int *)(param_1 + 0x4c) = iVar2;
        *(undefined2 *)(param_1 + 0x62) = 0;
        FUN_40493a3c(param_1,iVar2);
        goto LAB_404948b8;
      }
    }
  }
LAB_404948cc:
  uVar3 = 0x4c494146;
LAB_404948d4:
  *(undefined4 *)(param_1 + 8) = uVar3;
  return iVar1;
}



/* 4049490c FUN_4049490c */

/* Boundary evidence: original MIPS .pdata 4049490c..40494c27. Semantic name remains unreviewed. */

int FUN_4049490c(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined8 local_48;
  undefined8 local_40;
  uint local_38;
  uint local_30;
  
  local_30 = DAT_404bd274;
  uVar2 = param_2[4];
  bVar1 = true;
  *(uint *)(param_1 + 0x24) = uVar2;
  if (((uVar2 != 0x22009) && (uVar2 != 0xe200b)) &&
     (((param_2[0xe] & 0x20) != 0x20 || ((uVar2 & 0xff00) != 0x2000)))) {
    if ((((uVar2 != 0x21005) && (uVar2 != 0x21006)) && (uVar2 != 0x10300c)) && (uVar2 != 0x21808)) {
      *(undefined1 *)(param_1 + 0xc4) = 1;
    }
    *(undefined4 *)(param_1 + 0x24) = 0xe200b;
  }
  *(undefined4 *)(param_1 + 0x28) = param_2[5];
  *(undefined4 *)(param_1 + 0x2c) = param_2[6];
  uVar2 = param_2[0xe];
  if (((uVar2 & 8) == 0) ||
     ((param_2[5] == *(int *)(param_1 + 0x10) && (param_2[6] == *(int *)(param_1 + 0x14))))) {
    param_2[0xe] = uVar2 & 0xfffffff7;
    uVar5 = *(undefined4 *)(param_1 + 0x10);
    local_60 = *(undefined4 *)(param_1 + 0x24);
    uVar4 = *(undefined4 *)(param_1 + 0x14);
    local_70 = 0xb96b3caa;
    local_6c = 0x11d30728;
    local_68 = 0x7b9d;
    local_64 = 0x2ef31ef8;
    local_5c = uVar5;
    local_58 = uVar4;
    uVar6 = __litodp(uVar5);
    uVar6 = __dpmul(param_2[10],param_2[0xb],(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
    uVar7 = __litodp(*(undefined4 *)(param_1 + 0x28));
    local_48 = __dpdiv((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,
                       (int)((ulonglong)uVar7 >> 0x20));
    uVar6 = __litodp(uVar4);
    uVar6 = __dpmul(param_2[0xc],param_2[0xd],(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
    uVar7 = __litodp(*(undefined4 *)(param_1 + 0x2c));
    local_40 = __dpdiv((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,
                       (int)((ulonglong)uVar7 >> 0x20));
    local_50 = *(undefined4 *)(param_1 + 0x18);
    local_38 = uVar2 & 2 | 0x50000;
    local_54 = uVar5;
    iVar3 = (**(code **)(**(int **)(param_1 + 0xc) + 0xc))(*(int **)(param_1 + 0xc),&local_70,0);
    if (iVar3 < 0) goto LAB_40494bec;
    *(undefined4 *)(param_1 + 0x18) = local_50;
    if ((local_38 & 0x200000) != 0) {
      param_2[0xe] = param_2[0xe] | 0x200000;
    }
    bVar1 = false;
    *(undefined4 *)(param_1 + 0x24) = local_60;
  }
  else {
    param_2[5] = *(int *)(param_1 + 0x10);
    param_2[6] = *(undefined4 *)(param_1 + 0x14);
  }
  param_2[4] = *(undefined4 *)(param_1 + 0x24);
  *param_2 = 0xb96b3caa;
  param_2[1] = 0x11d30728;
  param_2[2] = 0x7b9d;
  param_2[3] = 0x2ef31ef8;
  *(undefined2 *)((int)param_2 + 0x3a) = 5;
  if (param_3 != (undefined4 *)0x0) {
    param_3[1] = 0;
    *param_3 = 0;
    param_3[2] = param_2[5];
    param_3[3] = param_2[6];
  }
  if (bVar1) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_40494414(param_1);
  }
LAB_40494bec:
  FUN_404a438c(local_30);
  return iVar3;
}



/* 40494c28 FUN_40494c28 */

void FUN_40494c28(byte *param_1,byte *param_2,uint param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 8 - param_4;
  for (uVar4 = param_3 >> 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *param_1 = *param_2 << (param_4 & 0x1f) | param_2[1] >> (uVar3 & 0x1f);
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  uVar4 = param_3 & 7;
  if (uVar4 != 0) {
    bVar1 = (byte)(0xff >> uVar4);
    bVar2 = *param_2 << (param_4 & 0x1f);
    if (uVar3 < uVar4) {
      bVar2 = param_2[1] >> (uVar3 & 0x1f) | bVar2;
    }
    *param_1 = *param_1 & bVar1 | bVar2 & ~bVar1;
  }
  return;
}



/* 40494cd4 FUN_40494cd4 */

/* Boundary evidence: original MIPS .pdata 40494cd4..40494e07. Semantic name remains unreviewed. */

void FUN_40494cd4(byte *param_1,byte *param_2,uint param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = 8 - param_4;
  if (param_3 < uVar4) {
    uVar4 = 0xff >> (param_4 & 0x1f);
    bVar1 = (byte)(uVar4 >> (param_3 & 0x1f)) ^ (byte)uVar4;
    *param_1 = ~bVar1 & *param_1 | *param_2 >> (param_4 & 0x1f) & bVar1;
  }
  else {
    *param_1 = ~(byte)(0xff >> (param_4 & 0x1f)) & *param_1 | *param_2 >> (param_4 & 0x1f);
    for (uVar2 = param_3 - uVar4 >> 3; param_1 = param_1 + 1, uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_1 = *param_2 << (uVar4 & 0x1f) | param_2[1] >> (param_4 & 0x1f);
      param_2 = param_2 + 1;
    }
    uVar2 = param_3 - uVar4 & 7;
    if (uVar2 != 0) {
      bVar1 = (byte)(0xff >> uVar2);
      bVar3 = *param_2 << (uVar4 & 0x1f);
      if (param_4 < uVar2) {
        bVar3 = param_2[1] >> (param_4 & 0x1f) | bVar3;
      }
      *param_1 = *param_1 & bVar1 | bVar3 & ~bVar1;
    }
  }
  return;
}



/* 40494e08 FUN_40494e08 */

/* Boundary evidence: original MIPS .pdata 40494e08..40494ea3. Semantic name remains unreviewed. */

void FUN_40494e08(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = param_1 + 0xf;
  if (param_1[0x11] != 0) {
    iVar3 = param_3;
    puVar4 = puVar5;
    iVar2 = param_1[0x11];
    do {
      param_3 = iVar2;
      (*(code *)*puVar4)(param_3,iVar3,*param_1,param_1 + 2);
      puVar5 = puVar4 + 3;
      piVar1 = puVar4 + 5;
      iVar3 = param_3;
      puVar4 = puVar5;
      iVar2 = *piVar1;
    } while (*piVar1 != 0);
  }
  (*(code *)*puVar5)(param_2,param_3,*param_1,param_1 + 2);
  return;
}



/* 40494ea4 FUN_40494ea4 */

/* Boundary evidence: original MIPS .pdata 40494ea4..40494f0b. Semantic name remains unreviewed. */

void FUN_40494ea4(int param_1)

{
  if (*(LPVOID *)(param_1 + 0x60) != (LPVOID)0x0) {
    FUN_404962ec(*(LPVOID *)(param_1 + 0x60));
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  if (*(LPVOID *)(param_1 + 100) != (LPVOID)0x0) {
    FUN_404962ec(*(LPVOID *)(param_1 + 100));
    *(undefined4 *)(param_1 + 100) = 0;
  }
  if (*(LPVOID *)(param_1 + 4) != (LPVOID)0x0) {
    FUN_404962ec(*(LPVOID *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



/* 40494f0c FUN_40494f0c */

/* Boundary evidence: original MIPS .pdata 40494f0c..40494fcb. Semantic name remains unreviewed. */

int FUN_40494f0c(int param_1,undefined *param_2,int *param_3,undefined *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_88;
  undefined4 local_84;
  undefined4 local_28;
  undefined4 local_24;
  
  local_28 = 0;
  local_24 = 0;
  local_84 = 0;
  iVar1 = FUN_404953ec(&iStack_88,param_1,param_2,param_3,param_4);
  if (-1 < iVar1) {
    iVar3 = param_3[4];
    iVar4 = *(int *)(param_1 + 0x10);
    for (iVar2 = *(int *)(param_1 + 4); iVar2 != 0; iVar2 = iVar2 + -1) {
      FUN_40494e08(&iStack_88,iVar4,iVar3);
      iVar3 = iVar3 + param_3[2];
      iVar4 = iVar4 + *(int *)(param_1 + 8);
    }
  }
  FUN_40494ea4((int)&iStack_88);
  return iVar1;
}



/* 40494fcc FUN_40494fcc */

/* Boundary evidence: original MIPS .pdata 40494fcc..40495147. Semantic name remains unreviewed. */

int FUN_40494fcc(int param_1,undefined *param_2,int *param_3,undefined *param_4,uint param_5)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *local_2a8;
  undefined4 local_2a4;
  int local_2a0;
  int iStack_298;
  undefined4 local_294;
  undefined4 local_238;
  undefined4 local_234;
  byte abStack_230 [512];
  uint local_30;
  
  local_30 = DAT_404bd274;
  local_2a8 = abStack_230;
  local_2a4 = 0x200;
  uVar1 = (param_3[3] >> 8 & 0xffU) * *param_3;
  local_238 = 0;
  local_234 = 0;
  local_294 = 0;
  local_2a0 = 0;
  iVar3 = FUN_404953ec(&iStack_298,param_1,param_2,param_3,param_4);
  if (-1 < iVar3) {
    iVar4 = FUN_4048903c((int *)&local_2a8,(uVar1 + 7 >> 3) + 3 & 0xfffffffc);
    pbVar2 = local_2a8;
    if (iVar4 == 0) {
      iVar3 = -0x7ff8fff2;
    }
    if (-1 < iVar3) {
      pbVar5 = (byte *)param_3[4];
      iVar6 = *(int *)(param_1 + 0x10);
      for (iVar4 = *(int *)(param_1 + 4); iVar4 != 0; iVar4 = iVar4 + -1) {
        FUN_40494c28(pbVar2,pbVar5,uVar1,param_5);
        pbVar5 = pbVar5 + param_3[2];
        FUN_40494e08(&iStack_298,iVar6,(int)pbVar2);
        iVar6 = *(int *)(param_1 + 8) + iVar6;
      }
    }
    if (local_2a0 != 0) {
      FUN_404962ec(pbVar2);
    }
  }
  FUN_40494ea4((int)&iStack_298);
  FUN_404a438c(local_30);
  return iVar3;
}



/* 40495148 FUN_40495148 */

/* Boundary evidence: original MIPS .pdata 40495148..404952c3. Semantic name remains unreviewed. */

int FUN_40495148(int *param_1,undefined *param_2,int *param_3,undefined *param_4,uint param_5)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *local_2a8;
  undefined4 local_2a4;
  int local_2a0;
  int iStack_298;
  undefined4 local_294;
  undefined4 local_238;
  undefined4 local_234;
  byte abStack_230 [512];
  uint local_30;
  
  local_30 = DAT_404bd274;
  local_2a8 = abStack_230;
  local_2a4 = 0x200;
  uVar1 = (param_1[3] >> 8 & 0xffU) * *param_1;
  local_238 = 0;
  local_234 = 0;
  local_294 = 0;
  local_2a0 = 0;
  iVar3 = FUN_404953ec(&iStack_298,(int)param_1,param_2,param_3,param_4);
  if (-1 < iVar3) {
    iVar4 = FUN_4048903c((int *)&local_2a8,(uVar1 + 7 >> 3) + 3 & 0xfffffffc);
    pbVar2 = local_2a8;
    if (iVar4 == 0) {
      iVar3 = -0x7ff8fff2;
    }
    if (-1 < iVar3) {
      iVar4 = param_3[4];
      pbVar6 = (byte *)param_1[4];
      for (iVar5 = param_1[1]; iVar5 != 0; iVar5 = iVar5 + -1) {
        FUN_40494e08(&iStack_298,pbVar2,iVar4);
        iVar4 = param_3[2] + iVar4;
        FUN_40494cd4(pbVar6,pbVar2,uVar1,param_5);
        pbVar6 = pbVar6 + param_1[2];
      }
    }
    if (local_2a0 != 0) {
      FUN_404962ec(pbVar2);
    }
  }
  FUN_40494ea4((int)&iStack_298);
  FUN_404a438c(local_30);
  return iVar3;
}



/* 404952c4 FUN_404952c4 */

undefined4 FUN_404952c4(undefined4 param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_2 == param_3) {
    uVar1 = 1;
  }
  else if ((*(int *)(&DAT_4048351c + (param_2 & 0xff) * 4) == 0) ||
          (uVar1 = 1, *(int *)(&DAT_40482c9c + (param_3 & 0xff) * 4) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40495320 FUN_40495320 */

/* Boundary evidence: original MIPS .pdata 40495320..404953eb. Semantic name remains unreviewed. */

undefined4 FUN_40495320(int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_3 == 0) {
    uVar1 = 0x887b0005;
  }
  else {
    *(int *)*param_2 = param_3;
    *(undefined4 *)(*param_2 + 4) = param_4;
    *(undefined4 *)(*param_2 + 8) = 0;
    piVar4 = (int *)*param_2;
    if (piVar4 != param_1 + 0xf) {
      iVar2 = FUN_404962c4(*param_1 * (piVar4[-2] >> 8 & 0xffU) >> 3);
      if (iVar2 == 0) {
        return 0x8007000e;
      }
      piVar3 = param_1 + 0x18;
      piVar4[-1] = iVar2;
      if (*piVar3 != 0) {
        piVar3 = param_1 + 0x19;
      }
      *piVar3 = iVar2;
    }
    *param_2 = *param_2 + 0xc;
    uVar1 = 0;
  }
  return uVar1;
}



/* 404953ec FUN_404953ec */

/* Boundary evidence: original MIPS .pdata 404953ec..404956a7. Semantic name remains unreviewed. */

int FUN_404953ec(int *param_1,int param_2,undefined *param_3,int *param_4,undefined *param_5)

{
  uint uVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  int *local_30 [2];
  
  FUN_40494ea4((int)param_1);
  *param_1 = *param_4;
  uVar6 = param_4[3];
  uVar7 = *(uint *)(param_2 + 0xc);
  if ((uVar6 == uVar7) && (((uVar6 & 0x10000) == 0 || (param_5 == param_3)))) {
    param_1[0xf] = *(int *)(&DAT_404834dc + (uVar6 & 0xff) * 4);
    goto LAB_40495480;
  }
  if ((uVar6 & 0x10000) != 0) {
    if (param_5 == (undefined *)0x0) {
LAB_404954d4:
      param_5 = FUN_404905b8(uVar6);
    }
    else {
      uVar1 = 1 << ((int)uVar6 >> 8 & 0x1fU);
      if (*(uint *)(param_5 + 4) < uVar1) {
        param_5 = FUN_4049061c(param_5,uVar1,0xff000000);
        param_1[1] = (int)param_5;
      }
      if (param_5 == (undefined *)0x0) goto LAB_404954d4;
    }
    param_1[2] = (int)param_5;
  }
  if ((uVar7 & 0x10000) != 0) {
    return -0x7784fffb;
  }
  iVar5 = 0;
  iVar4 = 0;
  while ((uVar6 != *(uint *)((int)&DAT_40482c84 + iVar4) ||
         (uVar7 != *(uint *)((int)&DAT_40482c88 + iVar4)))) {
    iVar5 = iVar5 + 1;
    iVar4 = iVar5 * 0xc;
    if ((&PTR_LAB_40482c8c)[iVar5 * 3] == (undefined *)0x0) {
      local_30[0] = param_1 + 0xf;
      uVar8 = 0x34400d;
      if ((uVar6 & 0x200000) == 0) {
        uVar3 = uVar8;
        if ((uVar6 & 0x100000) == 0) {
          uVar3 = 0x26200a;
        }
        iVar4 = FUN_40495320(param_1,(int *)local_30,*(int *)(&DAT_4048351c + (uVar6 & 0xff) * 4),
                             uVar3);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      if (((uVar6 & 0x100000) != 0) != ((uVar7 & 0x100000) != 0)) {
        if ((uVar6 & 0x100000) == 0) {
          pcVar2 = (code *)&LAB_404960d8;
        }
        else {
          uVar8 = 0x26200a;
          pcVar2 = FUN_4049607c;
        }
        iVar4 = FUN_40495320(param_1,(int *)local_30,(int)pcVar2,uVar8);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      if (((uVar7 & 0x200000) == 0) &&
         (iVar4 = FUN_40495320(param_1,(int *)local_30,*(int *)(&DAT_40482c9c + (uVar7 & 0xff) * 4),
                               uVar7), iVar4 < 0)) {
        return iVar4;
      }
      return 0;
    }
  }
  param_1[0xf] = (int)(&PTR_LAB_40482c8c)[iVar5 * 3];
LAB_40495480:
  param_1[0x10] = uVar7;
  param_1[0x11] = 0;
  return 0;
}



/* 40495864 FUN_40495864 */

/* Boundary evidence: original MIPS .pdata 40495864..404958b3. Semantic name remains unreviewed. */

void FUN_40495864(int param_1,undefined4 *param_2,int param_3)

{
  undefined2 *puVar1;
  undefined2 local_8;
  undefined2 uStack_6;
  undefined2 local_4;
  
  if (param_3 != 0) {
    puVar1 = (undefined2 *)(param_1 + 4);
    do {
      local_8 = (undefined2)*param_2;
      uStack_6 = (undefined2)((uint)*param_2 >> 0x10);
      local_4 = (undefined2)param_2[1];
      puVar1[-2] = local_8;
      puVar1[-1] = uStack_6;
      *puVar1 = local_4;
      param_3 = param_3 + -1;
      param_2 = param_2 + 2;
      puVar1 = puVar1 + 3;
    } while (param_3 != 0);
  }
  return;
}



/* 40495968 FUN_40495968 */

/* Boundary evidence: original MIPS .pdata 40495968..40495a17. Semantic name remains unreviewed. */

void FUN_40495968(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  short local_8;
  short sStack_6;
  undefined4 local_4;
  
  if (param_3 != 0) {
    iVar5 = param_1 - (int)param_2;
    do {
      uVar4 = param_2[1];
      param_3 = param_3 + -1;
      uVar3 = *param_2;
      local_4._2_2_ = (short)((uint)uVar4 >> 0x10);
      iVar1 = (int)local_4._2_2_;
      if (iVar1 != 0x2000) {
        if (iVar1 == 0) {
          uVar3 = 0;
          uVar4 = 0;
        }
        else {
          local_4._0_2_ = (short)uVar4;
          local_4 = CONCAT22(local_4._2_2_,(short)((short)local_4 * iVar1 >> 0xd));
          sStack_6 = (short)((uint)uVar3 >> 0x10);
          local_8 = (short)uVar3;
          uVar3 = CONCAT22((short)(sStack_6 * iVar1 >> 0xd),(short)(local_8 * iVar1 >> 0xd));
          uVar4 = local_4;
        }
      }
      puVar2 = (undefined4 *)(iVar5 + (int)param_2);
      *puVar2 = uVar3;
      puVar2[1] = uVar4;
      param_2 = param_2 + 2;
    } while (param_3 != 0);
  }
  return;
}



/* 40495a18 FUN_40495a18 */

/* Boundary evidence: original MIPS .pdata 40495a18..40495a83. Semantic name remains unreviewed. */

void FUN_40495a18(int param_1,uint *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 != 0) {
    iVar2 = param_1 - (int)param_2;
    do {
      uVar1 = *param_2;
      param_3 = param_3 + -1;
      if ((uVar1 >> 0x18) - 1 < 0xfe) {
        uVar1 = FUN_4048fe28(uVar1);
      }
      *(uint *)(iVar2 + (int)param_2) = uVar1;
      param_2 = param_2 + 1;
    } while (param_3 != 0);
  }
  return;
}



/* 40495a84 FUN_40495a84 */

/* Boundary evidence: original MIPS .pdata 40495a84..40495b8b. Semantic name remains unreviewed. */

void FUN_40495a84(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_3 != 0) {
    iVar5 = param_1 - (int)param_2;
    do {
      uVar3 = param_2[1];
      local_4._2_2_ = (short)((uint)uVar3 >> 0x10);
      iVar4 = (int)local_4._2_2_;
      uVar2 = *param_2;
      param_3 = param_3 + -1;
      local_8 = uVar2;
      if ((iVar4 + 0xffffU & 0xffff) < 0x2001) {
        local_4._0_2_ = (short)uVar3;
        if (iVar4 == 0) {
          trap(0x1c00);
        }
        if ((iVar4 == -1) && ((int)(short)local_4 << 0xd == -0x80000000)) {
          trap(0x1800);
        }
        local_4 = CONCAT22(local_4._2_2_,(short)(((int)(short)local_4 << 0xd) / iVar4));
        local_8._2_2_ = (short)((uint)uVar2 >> 0x10);
        if (iVar4 == 0) {
          trap(0x1c00);
        }
        if ((iVar4 == -1) && ((int)local_8._2_2_ << 0xd == -0x80000000)) {
          trap(0x1800);
        }
        local_8._0_2_ = (short)uVar2;
        if (iVar4 == 0) {
          trap(0x1c00);
        }
        if ((iVar4 == -1) && ((int)(short)local_8 << 0xd == -0x80000000)) {
          trap(0x1800);
        }
        local_8 = CONCAT22((short)(((int)local_8._2_2_ << 0xd) / iVar4),
                           (short)(((int)(short)local_8 << 0xd) / iVar4));
        uVar3 = local_4;
      }
      puVar1 = (undefined4 *)(iVar5 + (int)param_2);
      *puVar1 = local_8;
      puVar1[1] = uVar3;
      param_2 = param_2 + 2;
    } while (param_3 != 0);
  }
  return;
}



/* 40495b8c FUN_40495b8c */

/* Boundary evidence: original MIPS .pdata 40495b8c..40495bab. Semantic name remains unreviewed. */

void FUN_40495b8c(void *param_1,void *param_2,int param_3)

{
  memcpy(param_1,param_2,param_3 + 7 >> 3);
  return;
}



/* 40495bac FUN_40495bac */

/* Boundary evidence: original MIPS .pdata 40495bac..40495bcf. Semantic name remains unreviewed. */

void FUN_40495bac(void *param_1,void *param_2,int param_3)

{
  memcpy(param_1,param_2,(param_3 + 1) * 4 >> 3);
  return;
}



/* 40495bd0 FUN_40495bd0 */

/* Boundary evidence: original MIPS .pdata 40495bd0..40495beb. Semantic name remains unreviewed. */

void FUN_40495bd0(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}



/* 40495bec FUN_40495bec */

/* Boundary evidence: original MIPS .pdata 40495bec..40495c07. Semantic name remains unreviewed. */

void FUN_40495bec(void *param_1,void *param_2,int param_3)

{
  memcpy(param_1,param_2,param_3 << 1);
  return;
}



/* 40495c08 FUN_40495c08 */

/* Boundary evidence: original MIPS .pdata 40495c08..40495c33. Semantic name remains unreviewed. */

void FUN_40495c08(void *param_1,void *param_2,int param_3)

{
  memcpy(param_1,param_2,param_3 * 3);
  return;
}



/* 40495c60 FUN_40495c60 */

/* Boundary evidence: original MIPS .pdata 40495c60..40495c8b. Semantic name remains unreviewed. */

void FUN_40495c60(void *param_1,void *param_2,int param_3)

{
  memcpy(param_1,param_2,param_3 * 6);
  return;
}



/* 40496024 FUN_40496024 */

/* Boundary evidence: original MIPS .pdata 40496024..4049607b. Semantic name remains unreviewed. */

void FUN_40496024(undefined4 *param_1,int param_2,int param_3)

{
  undefined2 *puVar1;
  undefined4 local_4;
  
  if (param_3 != 0) {
    local_4 = 0x20000000;
    puVar1 = (undefined2 *)(param_2 + 4);
    do {
      local_4 = CONCAT22(local_4._2_2_,*puVar1);
      *param_1 = *(undefined4 *)(puVar1 + -2);
      param_1[1] = local_4;
      param_3 = param_3 + -1;
      param_1 = param_1 + 2;
      puVar1 = puVar1 + 3;
    } while (param_3 != 0);
  }
  return;
}



/* 4049607c FUN_4049607c */

/* Boundary evidence: original MIPS .pdata 4049607c..404960d7. Semantic name remains unreviewed. */

void FUN_4049607c(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = FUN_404961c0(*param_2,param_2[1]);
    param_2 = param_2 + 2;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  }
  return;
}



/* 40496168 FUN_40496168 */

uint FUN_40496168(uint param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  
  uVar2 = (uint)(byte)(&DAT_40483d5c)[(param_1 & 0xffff) >> 8];
  psVar3 = (short *)(&DAT_40483d7c + uVar2 * 2);
  sVar1 = *psVar3;
  while ((int)sVar1 < (int)param_1) {
    psVar3 = psVar3 + 1;
    uVar2 = uVar2 + 1 & 0xff;
    sVar1 = *psVar3;
  }
  return uVar2;
}



/* 404961c0 FUN_404961c0 */

/* Boundary evidence: original MIPS .pdata 404961c0..404962c3. Semantic name remains unreviewed. */

undefined4 FUN_404961c0(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined2 local_res0;
  undefined2 uStackX_2;
  undefined2 local_res4;
  undefined2 uStackX_6;
  undefined4 local_10;
  
  uStackX_6 = (short)((uint)param_2 >> 0x10);
  iVar4 = (int)uStackX_6;
  uVar6 = 0xff;
  if (iVar4 < 1) {
    uVar5 = 0;
  }
  else if (iVar4 < 0x2000) {
    uVar5 = (undefined1)(iVar4 * 0xff >> 0xd);
  }
  else {
    uVar5 = 0xff;
  }
  local_res4 = (short)param_2;
  uVar3 = (uint)local_res4;
  if ((int)uVar3 < 1) {
    uVar1 = 0;
  }
  else if ((int)uVar3 < 0x2000) {
    uVar3 = FUN_40496168(uVar3);
    uVar1 = (undefined1)uVar3;
  }
  else {
    uVar1 = 0xff;
  }
  uStackX_2 = (short)((uint)param_1 >> 0x10);
  uVar3 = (uint)uStackX_2;
  if ((int)uVar3 < 1) {
    uVar2 = 0;
  }
  else if ((int)uVar3 < 0x2000) {
    uVar3 = FUN_40496168(uVar3);
    uVar2 = (undefined1)uVar3;
  }
  else {
    uVar2 = 0xff;
  }
  local_res0 = (short)param_1;
  uVar3 = (uint)local_res0;
  if ((int)uVar3 < 1) {
    uVar6 = 0;
  }
  else if ((int)uVar3 < 0x2000) {
    uVar3 = FUN_40496168(uVar3);
    uVar6 = (undefined1)uVar3;
  }
  local_10 = CONCAT31(CONCAT21(CONCAT11(uVar5,uVar1),uVar2),uVar6);
  return local_10;
}



/* 404962c4 FUN_404962c4 */

/* Boundary evidence: original MIPS .pdata 404962c4..404962eb. Semantic name remains unreviewed. */

void FUN_404962c4(SIZE_T param_1)

{
  HeapAlloc(DAT_404bd324,0,param_1);
  return;
}



/* 404962ec FUN_404962ec */

/* Boundary evidence: original MIPS .pdata 404962ec..4049631b. Semantic name remains unreviewed. */

void FUN_404962ec(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    HeapFree(DAT_404bd324,0,param_1);
  }
  return;
}



/* 4049631c FUN_4049631c */

/* Boundary evidence: original MIPS .pdata 4049631c..40496397. Semantic name remains unreviewed. */

LPVOID FUN_4049631c(LPVOID param_1,SIZE_T param_2)

{
  LPVOID pvVar1;
  
  if (param_2 == 0) {
    if (param_1 != (LPVOID)0x0) {
      HeapFree(DAT_404bd324,0,param_1);
    }
    pvVar1 = (LPVOID)0x0;
  }
  else if (param_1 == (LPVOID)0x0) {
    pvVar1 = HeapAlloc(DAT_404bd324,0,param_2);
  }
  else {
    pvVar1 = HeapReAlloc(DAT_404bd324,0,param_1,param_2);
  }
  return pvVar1;
}



/* 40496398 FUN_40496398 */

/* Boundary evidence: original MIPS .pdata 40496398..404963e3. Semantic name remains unreviewed. */

undefined4 FUN_40496398(void)

{
  FUN_40496498();
  if (DAT_404bd328 == (HMODULE)0x0) {
    DAT_404bd328 = GetModuleHandleW((LPCWSTR)0x0);
  }
  return 1;
}



/* 404963e4 FUN_404963e4 */

int FUN_404963e4(short *param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  sVar1 = *param_1;
  while (sVar1 != 0) {
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
    sVar1 = *param_1;
  }
  return iVar2;
}



/* 40496408 FUN_40496408 */

/* Boundary evidence: original MIPS .pdata 40496408..40496497. Semantic name remains unreviewed. */

void * FUN_40496408(short *param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  void *_Dst;
  SIZE_T _Size;
  
  if (param_1 == (short *)0x0) {
    _Dst = (void *)0x0;
  }
  else {
    iVar3 = 0;
    sVar1 = *param_1;
    psVar2 = param_1;
    while (sVar1 != 0) {
      psVar2 = psVar2 + 1;
      iVar3 = iVar3 + 1;
      sVar1 = *psVar2;
    }
    _Size = (iVar3 + 1) * 2;
    _Dst = (void *)FUN_404962c4(_Size);
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_1,_Size);
    }
  }
  return _Dst;
}



/* 40496498 FUN_40496498 */

/* Boundary evidence: original MIPS .pdata 40496498..404964d3. Semantic name remains unreviewed. */

void FUN_40496498(void)

{
  _SYSTEM_INFO _Stack_30;
  
  GetSystemInfo(&_Stack_30);
  DAT_404bd390 = _Stack_30.dwAllocationGranularity;
  DAT_404bd38c = _Stack_30.dwPageSize;
  return;
}



/* 404964d4 FUN_404964d4 */

/* Boundary evidence: original MIPS .pdata 404964d4..404964ef. Semantic name remains unreviewed. */

void FUN_404964d4(double param_1,double param_2)

{
  pow(param_1,param_2);
  return;
}



/* 404964f0 FUN_404964f0 */

/* Boundary evidence: original MIPS .pdata 404964f0..4049654b. Semantic name remains unreviewed. */

void FUN_404964f0(void)

{
  HRESULT HVar1;
  int iVar2;
  uint uVar3;
  
  HVar1 = DllCanUnloadNow();
  uVar3 = 2;
  if (HVar1 == 0) {
    uVar3 = 0;
  }
  iVar2 = FUN_404a3c98();
  DAT_404bd1c0 = iVar2 != 0 | uVar3 | DAT_404bd1c0;
  return;
}



/* 4049654c FUN_4049654c */

/* Boundary evidence: original MIPS .pdata 4049654c..404965cf. Semantic name remains unreviewed. */

undefined4 * FUN_4049654c(undefined4 *param_1)

{
  FUN_40498b5c(param_1);
  FUN_404a3d00(param_1 + 0x22);
  *param_1 = &PTR_FUN_40484038;
  param_1[1] = &PTR_LAB_4048401c;
  param_1[0x22] = &PTR_LAB_40483ff4;
  param_1[0x23] = &PTR_LAB_40483fb8;
  param_1[0x24] = &PTR_LAB_40483f9c;
  param_1[0x62] = 1;
  return param_1;
}



/* 40496600 FUN_40496600 */

/* Boundary evidence: original MIPS .pdata 40496600..4049666b. Semantic name remains unreviewed. */

void FUN_40496600(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40484038;
  param_1[1] = &PTR_LAB_4048401c;
  param_1[0x22] = &PTR_LAB_40483ff4;
  param_1[0x23] = &PTR_LAB_40483fb8;
  param_1[0x24] = &PTR_LAB_40483f9c;
  FUN_404a3c7c(param_1 + 0x22);
  FUN_40498bbc(param_1);
  return;
}



/* 4049666c FUN_4049666c */

/* Boundary evidence: original MIPS .pdata 4049666c..40496687. Semantic name remains unreviewed. */

void FUN_4049666c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x188));
  return;
}



/* 40496688 FUN_40496688 */

/* Boundary evidence: original MIPS .pdata 40496688..404966e3. Semantic name remains unreviewed. */

LONG FUN_40496688(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x188));
  if ((LVar1 == 0) && (param_1 != 0)) {
    (*(code *)**(undefined4 **)(param_1 + 4))((undefined4 *)(param_1 + 4),1);
  }
  return LVar1;
}



/* 4049675c FUN_4049675c */

/* Boundary evidence: original MIPS .pdata 4049675c..404967ff. Semantic name remains unreviewed. */

undefined4 FUN_4049675c(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_404962c4(400);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_4049654c(puVar1);
  }
  if (piVar2 == (int *)0x0) {
    *param_2 = 0;
    uVar3 = 0x8007000e;
  }
  else {
    uVar3 = (**(code **)*piVar2)(piVar2,param_1,param_2);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return uVar3;
}



/* 40496800 FUN_40496800 */

/* Boundary evidence: original MIPS .pdata 40496800..4049684b. Semantic name remains unreviewed. */

undefined4 * FUN_40496800(undefined4 *param_1,uint param_2)

{
  FUN_40496600(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 4049684c FUN_4049684c */

/* Boundary evidence: original MIPS .pdata 4049684c..40496933. Semantic name remains unreviewed. */

undefined4 FUN_4049684c(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  HRESULT HVar2;
  int *piVar3;
  
  iVar1 = memcmp(param_2,&DAT_404812bc,0x10);
  if ((iVar1 != 0) || (HVar2 = DllCanUnloadNow(), HVar2 == 0)) {
    iVar1 = memcmp(param_2,&DAT_404812cc,0x10);
    if ((iVar1 == 0) && (iVar1 = FUN_404a3c98(), iVar1 != 0)) {
      piVar3 = param_1 + 0x22;
      if (param_1 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      *param_3 = (int)piVar3;
      goto LAB_404968f8;
    }
    iVar1 = memcmp(param_2,&DAT_40482c64,0x10);
    if (iVar1 != 0) {
      *param_3 = 0;
      return 0x80004002;
    }
  }
  *param_3 = (int)param_1;
LAB_404968f8:
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}



/* 4049695c FUN_4049695c */

/* Boundary evidence: original MIPS .pdata 4049695c..4049699f. Semantic name remains unreviewed. */

undefined4 * FUN_4049695c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40484898;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404969a0 FUN_404969a0 */

/* Boundary evidence: original MIPS .pdata 404969a0..40496a37. Semantic name remains unreviewed. */

undefined4 FUN_404969a0(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_404812bc,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40482c64,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 40496a38 FUN_40496a38 */

/* Boundary evidence: original MIPS .pdata 40496a38..40496a53. Semantic name remains unreviewed. */

void FUN_40496a38(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x84));
  return;
}



/* 40496a54 FUN_40496a54 */

/* Boundary evidence: original MIPS .pdata 40496a54..40496aaf. Semantic name remains unreviewed. */

LONG FUN_40496a54(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x84));
  if ((LVar1 == 0) && (param_1 != 0)) {
    (*(code *)**(undefined4 **)(param_1 + 4))((undefined4 *)(param_1 + 4),1);
  }
  return LVar1;
}



/* 40496ab0 FUN_40496ab0 */

/* Boundary evidence: original MIPS .pdata 40496ab0..40496b73. Semantic name remains unreviewed. */

undefined4 FUN_40496ab0(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    (**(code **)(*param_2 + 4))(param_2);
    *(undefined4 *)(param_1 + 0x48) = (undefined4 *)(param_1 + 0x60);
    *(undefined4 **)(param_1 + 100) = (undefined4 *)(param_1 + 0x48);
    uVar1 = 0;
    *(int **)(param_1 + 8) = param_2;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined2 *)(param_1 + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x6c) = 0;
    *(undefined2 *)(param_1 + 0x70) = 0;
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  else {
    uVar1 = 0x80004005;
  }
  return uVar1;
}



/* 40496b74 FUN_40496b74 */

/* Boundary evidence: original MIPS .pdata 40496b74..40496ba3. Semantic name remains unreviewed. */

undefined4 FUN_40496b74(void)

{
  FUN_404a438c(DAT_404bd274);
  return 0x80004001;
}



/* 40496ba4 FUN_40496ba4 */

/* Boundary evidence: original MIPS .pdata 40496ba4..40496bd3. Semantic name remains unreviewed. */

undefined4 FUN_40496ba4(void)

{
  FUN_404a438c(DAT_404bd274);
  return 0x80004001;
}



/* 40496bd4 FUN_40496bd4 */

/* Boundary evidence: original MIPS .pdata 40496bd4..4049729b. Semantic name remains unreviewed. */

int FUN_40496bd4(int *param_1)

{
  SIZE_T SVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  int local_60 [3];
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  uint local_20;
  
  local_20 = DAT_404bd274;
  iVar3 = 0;
  if (param_1[0x11] == 1) {
LAB_40496c0c:
    FUN_404a438c(local_20);
    iVar3 = 0;
  }
  else {
    if ((param_1[0xd] != 0) ||
       (iVar3 = (**(code **)(*param_1 + 0x30))(param_1,local_60), -1 < iVar3)) {
      iVar2 = param_1[4];
      if (*(int *)(iVar2 + 0x218) != 0) {
        if (*(int *)(iVar2 + 0x220) != 0) {
          param_1[0x1f] = param_1[0x1f] + 1;
          param_1[0x1e] = *(int *)(iVar2 + 0x220) + param_1[0x1e];
          iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x302,*(SIZE_T *)(iVar2 + 0x220),2,
                               *(void **)(iVar2 + 0x21c));
          if (iVar2 != 0) goto LAB_40496c0c;
        }
        iVar2 = param_1[4];
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = *(int *)(iVar2 + 0x218) + param_1[0x1e];
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x8773,*(SIZE_T *)(iVar2 + 0x218),1,
                             *(void **)(iVar2 + 0x214));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      if (*(char *)(param_1[4] + 0x1d0) != -1) {
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + 1;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x303,1,1,(char *)(param_1[4] + 0x1d0));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      iVar2 = *(int *)(param_1[4] + 0xbc);
      if (iVar2 != 0) {
        local_70 = 100000;
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + 8;
        local_6c = iVar2;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x301,8,5,&local_70);
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      iVar2 = param_1[4];
      if (*(char *)(iVar2 + 0x1d3) == '\x01') {
        local_70 = *(int *)(iVar2 + 0x94);
        local_6c = 100000;
        local_68 = *(int *)(iVar2 + 0x98);
        local_64 = 100000;
        if ((0 < local_70) && (0 < local_68)) {
          param_1[0x1f] = param_1[0x1f] + 1;
          param_1[0x1e] = param_1[0x1e] + 0x10;
          iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x13e,0x10,5,&local_70);
          if (iVar2 != 0) goto LAB_40496c0c;
        }
        iVar2 = param_1[4];
        local_60[0] = *(int *)(iVar2 + 0x9c);
        local_60[1] = 100000;
        local_60[2] = *(int *)(iVar2 + 0xa0);
        local_54 = 100000;
        local_50 = *(int *)(iVar2 + 0xa4);
        local_4c = 100000;
        local_48 = *(int *)(iVar2 + 0xa8);
        local_44 = 100000;
        local_40 = *(int *)(iVar2 + 0xac);
        local_3c = 100000;
        local_38 = *(int *)(iVar2 + 0xb0);
        local_34 = 100000;
        if (((((0 < local_60[0]) && (0 < local_60[2])) && (0 < local_50)) &&
            ((0 < local_48 && (0 < local_40)))) && (0 < local_38)) {
          param_1[0x1f] = param_1[0x1f] + 1;
          param_1[0x1e] = param_1[0x1e] + 0x30;
          iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x13f,0x30,5,local_60);
          if (iVar2 != 0) goto LAB_40496c0c;
        }
      }
      SVar1 = *(SIZE_T *)(param_1[4] + 0x1d8);
      if (SVar1 != 0) {
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + SVar1;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),800,SVar1,2,*(void **)(param_1[4] + 0x1d4));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      SVar1 = *(SIZE_T *)(param_1[4] + 0x1e0);
      if (SVar1 != 0) {
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + SVar1;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x13b,SVar1,2,*(void **)(param_1[4] + 0x1dc));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      SVar1 = *(SIZE_T *)(param_1[4] + 0x1e8);
      if (SVar1 != 0) {
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + SVar1;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x8298,SVar1,2,*(void **)(param_1[4] + 0x1e4));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      SVar1 = *(SIZE_T *)(param_1[4] + 0x1f0);
      if (SVar1 != 0) {
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + SVar1;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x10e,SVar1,2,*(void **)(param_1[4] + 0x1ec));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      SVar1 = *(SIZE_T *)(param_1[4] + 0x1f8);
      if (SVar1 != 0) {
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + SVar1;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x9003,SVar1,2,*(void **)(param_1[4] + 500));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      SVar1 = *(SIZE_T *)(param_1[4] + 0x200);
      if (SVar1 != 0) {
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + SVar1;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x131,SVar1,2,*(void **)(param_1[4] + 0x1fc));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      SVar1 = *(SIZE_T *)(param_1[4] + 0x208);
      if (SVar1 != 0) {
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + SVar1;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x110,SVar1,2,*(void **)(param_1[4] + 0x204));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      SVar1 = *(SIZE_T *)(param_1[4] + 0x210);
      if (SVar1 != 0) {
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + SVar1;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x9286,SVar1,2,*(void **)(param_1[4] + 0x20c));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      iVar2 = param_1[4];
      if ((*(int *)(iVar2 + 0xb4) != 0) && (*(int *)(iVar2 + 0xb8) != 0)) {
        piVar4 = param_1 + 0x18;
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + 1;
        iVar2 = FUN_404904d0((int)piVar4,0x5110,1,1,(void *)(iVar2 + 0x1d1));
        if (iVar2 == 0) {
          param_1[0x1f] = param_1[0x1f] + 1;
          param_1[0x1e] = param_1[0x1e] + 4;
          iVar2 = FUN_404904d0((int)piVar4,0x5111,4,4,(void *)(param_1[4] + 0xb4));
          if (iVar2 == 0) {
            param_1[0x1f] = param_1[0x1f] + 1;
            param_1[0x1e] = param_1[0x1e] + 4;
            iVar2 = FUN_404904d0((int)piVar4,0x5112,4,4,(void *)(param_1[4] + 0xb8));
            if (iVar2 == 0) goto LAB_404971d4;
          }
        }
        goto LAB_40496c0c;
      }
LAB_404971d4:
      iVar2 = param_1[4];
      if (*(int *)(iVar2 + 0x228) != 0) {
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = *(int *)(iVar2 + 0x228) + param_1[0x1e];
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x132,*(SIZE_T *)(iVar2 + 0x228),2,
                             *(void **)(iVar2 + 0x224));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      iVar2 = *(int *)(param_1[4] + 0x238);
      if (iVar2 != 0) {
        SVar1 = iVar2 * 2;
        param_1[0x1f] = param_1[0x1f] + 1;
        param_1[0x1e] = param_1[0x1e] + SVar1;
        iVar2 = FUN_404904d0((int)(param_1 + 0x18),0x5113,SVar1,3,*(void **)(param_1[4] + 0x234));
        if (iVar2 != 0) goto LAB_40496c0c;
      }
      param_1[0x11] = 1;
    }
    FUN_404a438c(local_20);
  }
  return iVar3;
}



/* 4049729c FUN_4049729c */

/* Boundary evidence: original MIPS .pdata 4049729c..404972ff. Semantic name remains unreviewed. */

int FUN_4049729c(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else if ((param_1[0x11] != 0) || (iVar1 = FUN_40496bd4(param_1), -1 < iVar1)) {
    iVar1 = 0;
    *param_2 = param_1[0x1f];
  }
  return iVar1;
}



/* 40497300 FUN_40497300 */

/* Boundary evidence: original MIPS .pdata 40497300..404973c7. Semantic name remains unreviewed. */

int FUN_40497300(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((param_1[0x11] != 0) || (iVar1 = FUN_40496bd4(param_1), -1 < iVar1)) {
    iVar1 = param_1[0x1f];
    if ((param_2 == iVar1) && (param_3 != (int *)0x0)) {
      if (iVar1 != 0) {
        piVar2 = (int *)param_1[0x12];
        iVar3 = 0;
        if (0 < iVar1) {
          do {
            if ((piVar2 == (int *)0x0) || (piVar2 == param_1 + 0x18)) break;
            iVar3 = iVar3 + 1;
            *param_3 = piVar2[2];
            param_3 = param_3 + 1;
            piVar2 = (int *)*piVar2;
          } while (iVar3 < param_1[0x1f]);
        }
      }
      iVar1 = 0;
    }
    else {
      iVar1 = -0x7ff8ffa9;
    }
  }
  return iVar1;
}



/* 404973c8 FUN_404973c8 */

/* Boundary evidence: original MIPS .pdata 404973c8..4049747f. Semantic name remains unreviewed. */

int FUN_404973c8(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else if ((param_1[0x11] != 0) || (iVar1 = FUN_40496bd4(param_1), -1 < iVar1)) {
    piVar2 = *(int **)param_1[0x12];
    piVar4 = (int *)param_1[0x12];
    if (piVar2 != (int *)0x0) {
      do {
        piVar3 = piVar2;
        if (piVar4[2] == param_2) break;
        piVar2 = (int *)*piVar3;
        piVar4 = piVar3;
      } while ((int *)*piVar3 != (int *)0x0);
      if (*piVar4 != 0) {
        *param_3 = piVar4[3] + 0x10;
        return 0;
      }
    }
    iVar1 = -0x7784fff6;
  }
  return iVar1;
}



/* 40497480 FUN_40497480 */

/* Boundary evidence: original MIPS .pdata 40497480..40497593. Semantic name remains unreviewed. */

int FUN_40497480(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_4 == (int *)0x0) {
LAB_404974ac:
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if ((param_1[0x11] == 0) && (iVar1 = FUN_40496bd4(param_1), iVar1 < 0)) {
      return iVar1;
    }
    piVar2 = *(int **)param_1[0x12];
    piVar4 = (int *)param_1[0x12];
    if (piVar2 != (int *)0x0) {
      do {
        piVar3 = piVar2;
        if (piVar4[2] == param_2) break;
        piVar2 = (int *)*piVar3;
        piVar4 = piVar3;
      } while ((int *)*piVar3 != (int *)0x0);
      if ((*piVar4 != 0) && (piVar4[5] != 0)) {
        if (piVar4[3] + 0x10 == param_3) {
          *param_4 = piVar4[2];
          param_4[1] = piVar4[3];
          *(short *)(param_4 + 2) = (short)piVar4[4];
          if (piVar4[3] == 0) {
            param_4[3] = 0;
          }
          else {
            param_4[3] = (int)(param_4 + 4);
            memcpy(param_4 + 4,(void *)piVar4[5],piVar4[3]);
          }
          return 0;
        }
        goto LAB_404974ac;
      }
    }
    iVar1 = -0x7784fff6;
  }
  return iVar1;
}



/* 40497594 FUN_40497594 */

/* Boundary evidence: original MIPS .pdata 40497594..4049761f. Semantic name remains unreviewed. */

int FUN_40497594(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if ((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else if ((param_1[0x11] != 0) || (iVar1 = FUN_40496bd4(param_1), -1 < iVar1)) {
    iVar1 = 0;
    *param_3 = param_1[0x1f];
    *param_2 = param_1[0x1f] * 0x10 + param_1[0x1e];
  }
  return iVar1;
}



/* 40497620 FUN_40497620 */

/* Boundary evidence: original MIPS .pdata 40497620..4049772f. Semantic name remains unreviewed. */

int FUN_40497620(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  int *piVar4;
  int iVar5;
  void *_Dst;
  
  iVar5 = param_1[0x1f] * 0x10;
  if (((param_2 == param_1[0x1e] + iVar5) && (param_3 == param_1[0x1f])) && (param_4 != 0)) {
    if ((param_1[0x11] != 0) || (iVar2 = FUN_40496bd4(param_1), -1 < iVar2)) {
      piVar4 = (int *)param_1[0x12];
      _Dst = (void *)(iVar5 + param_4);
      iVar5 = 0;
      if (0 < param_1[0x1f]) {
        puVar3 = (undefined2 *)(param_4 + 8);
        do {
          *(int *)(puVar3 + -4) = piVar4[2];
          *(int *)(puVar3 + -2) = piVar4[3];
          *puVar3 = *(undefined2 *)(piVar4 + 4);
          if (piVar4[3] == 0) {
            *(undefined4 *)(puVar3 + 2) = 0;
          }
          else {
            *(void **)(puVar3 + 2) = _Dst;
            memcpy(_Dst,(void *)piVar4[5],piVar4[3]);
          }
          piVar1 = piVar4 + 3;
          piVar4 = (int *)*piVar4;
          _Dst = (void *)(*piVar1 + (int)_Dst);
          iVar5 = iVar5 + 1;
          puVar3 = puVar3 + 8;
        } while (iVar5 < param_1[0x1f]);
      }
      iVar2 = 0;
    }
  }
  else {
    iVar2 = -0x7ff8ffa9;
  }
  return iVar2;
}



/* 40497730 FUN_40497730 */

/* Boundary evidence: original MIPS .pdata 40497730..404977f7. Semantic name remains unreviewed. */

int FUN_40497730(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if ((param_1[0x11] != 0) || (iVar1 = FUN_40496bd4(param_1), -1 < iVar1)) {
    piVar2 = *(int **)param_1[0x12];
    piVar4 = (int *)param_1[0x12];
    if (piVar2 != (int *)0x0) {
      do {
        piVar3 = piVar2;
        if (piVar4[2] == param_2) break;
        piVar2 = (int *)*piVar3;
        piVar4 = piVar3;
      } while ((int *)*piVar3 != (int *)0x0);
      if (*piVar4 != 0) {
        param_1[0x1f] = param_1[0x1f] + -1;
        param_1[0x1e] = param_1[0x1e] - piVar4[3];
        FUN_40490480(piVar4);
        FUN_404962ec(piVar4);
        param_1[0x20] = 1;
        return 0;
      }
    }
    iVar1 = -0x7784fff6;
  }
  return iVar1;
}



/* 404977f8 FUN_404977f8 */

/* Boundary evidence: original MIPS .pdata 404977f8..40497937. Semantic name remains unreviewed. */

int FUN_404977f8(int *param_1,int param_2,SIZE_T param_3,undefined2 param_4,void *param_5)

{
  int iVar1;
  void *_Dst;
  int *piVar2;
  
  if ((param_1[0x11] == 0) && (iVar1 = FUN_40496bd4(param_1), iVar1 < 0)) {
    return iVar1;
  }
  piVar2 = (int *)param_1[0x12];
  if (*piVar2 != 0) {
    do {
      if (piVar2[2] == param_2) break;
      piVar2 = (int *)*piVar2;
    } while (*piVar2 != 0);
    if (*piVar2 != 0) {
      param_1[0x1e] = (param_1[0x1e] - piVar2[3]) + param_3;
      FUN_404962ec((LPVOID)piVar2[5]);
      piVar2[3] = param_3;
      *(undefined2 *)(piVar2 + 4) = param_4;
      _Dst = (void *)FUN_404962c4(param_3);
      piVar2[5] = (int)_Dst;
      if (_Dst == (void *)0x0) {
        piVar2[3] = 0;
        return -0x7ff8fff2;
      }
      memcpy(_Dst,param_5,param_3);
      goto LAB_404978c8;
    }
  }
  param_1[0x1f] = param_1[0x1f] + 1;
  param_1[0x1e] = param_1[0x1e] + param_3;
  iVar1 = FUN_404904d0((int)(param_1 + 0x18),param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    return -0x7fffbffb;
  }
LAB_404978c8:
  param_1[0x20] = 1;
  return 0;
}



/* 40497938 FUN_40497938 */

/* Boundary evidence: original MIPS .pdata 40497938..404979c7. Semantic name remains unreviewed. */

void FUN_40497938(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x44) == 1) {
    iVar3 = 0;
    puVar2 = *(undefined4 **)(param_1 + 0x48);
    if (0 < *(int *)(param_1 + 0x7c)) {
      do {
        if (puVar2 == (undefined4 *)0x0) break;
        puVar1 = (undefined4 *)*puVar2;
        FUN_404962ec((LPVOID)puVar2[5]);
        FUN_404962ec(puVar2);
        iVar3 = iVar3 + 1;
        puVar2 = puVar1;
      } while (iVar3 < *(int *)(param_1 + 0x7c));
    }
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  return;
}



/* 404979c8 FUN_404979c8 */

/* Boundary evidence: original MIPS .pdata 404979c8..40497ad7. Semantic name remains unreviewed. */

int FUN_404979c8(int *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  SIZE_T SVar3;
  undefined3 extraout_var;
  undefined1 auStack_58 [64];
  uint local_18;
  
  local_18 = DAT_404bd274;
  if (param_1[3] == 0) {
    (**(code **)(*param_2 + 4))(param_2);
    param_1[3] = (int)param_2;
    param_1[0x10] = 0;
    param_1[0xe] = 0;
    if ((param_1[0xd] == 0) &&
       (iVar2 = (**(code **)(*param_1 + 0x30))(param_1,auStack_58), iVar2 < 0)) {
      FUN_404a438c(local_18);
      return iVar2;
    }
    SVar3 = FUN_404a5f98(param_1[4]);
    param_1[9] = SVar3;
    if (param_1[8] == 0) {
      iVar2 = FUN_404962c4(SVar3);
      param_1[8] = iVar2;
      if (iVar2 == 0) {
        FUN_404a438c(local_18);
        return -0x7ff8fff2;
      }
    }
    bVar1 = FUN_404a5c70(param_1[4],param_1[8],param_1[9]);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      FUN_404a438c(local_18);
      return 0;
    }
  }
  FUN_404a438c(local_18);
  return -0x7fffbffb;
}



/* 40497ad8 FUN_40497ad8 */

/* Boundary evidence: original MIPS .pdata 40497ad8..40497b77. Semantic name remains unreviewed. */

int FUN_40497ad8(int param_1,int param_2)

{
  int iVar1;
  
  if (*(LPVOID *)(param_1 + 0x14) != (LPVOID)0x0) {
    FUN_404962ec(*(LPVOID *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    param_2 = -0x7fffbffb;
  }
  else {
    FUN_404a5cc8(*(int *)(param_1 + 0x10));
    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x10))(*(int **)(param_1 + 0xc),param_2);
    (**(code **)(**(int **)(param_1 + 0xc) + 8))();
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (iVar1 < 0) {
      param_2 = iVar1;
    }
  }
  return param_2;
}



/* 40497b78 FUN_40497b78 */

/* Boundary evidence: original MIPS .pdata 40497b78..40497bcf. Semantic name remains unreviewed. */

undefined4 FUN_40497b78(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_3 == (undefined4 *)0x0) || (iVar1 = memcmp(param_2,&DAT_4048132c,0x10), iVar1 != 0)) {
    uVar2 = 0x80070057;
  }
  else {
    *param_3 = 1;
    uVar2 = 0;
  }
  return uVar2;
}



/* 40497bd0 FUN_40497bd0 */

/* Boundary evidence: original MIPS .pdata 40497bd0..40497c2b. Semantic name remains unreviewed. */

undefined4 FUN_40497bd0(undefined4 param_1,void *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_2 == (void *)0x0) || (iVar1 = memcmp(param_2,&DAT_4048132c,0x10), iVar1 != 0)) ||
     (1 < param_3)) {
    uVar2 = 0x80070057;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40497c2c FUN_40497c2c */

undefined4 FUN_40497c2c(undefined4 param_1,ushort *param_2,int *param_3)

{
  undefined1 *puVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = (undefined1 *)param_3[4];
  for (iVar3 = *param_3; iVar3 != 0; iVar3 = iVar3 + -1) {
    uVar4 = (((*param_2 & 0xff) * 0x100 + (uint)(*param_2 >> 8)) * 0x2000 + 0x7fff) / 0xffff;
    puVar1[5] = (char)(uVar4 >> 8);
    puVar1[4] = (char)uVar4;
    uVar4 = (((param_2[1] & 0xff) * 0x100 + (uint)(param_2[1] >> 8)) * 0x2000 + 0x7fff) / 0xffff;
    puVar2 = param_2 + 2;
    param_2 = param_2 + 3;
    puVar1[2] = (char)uVar4;
    puVar1[3] = (char)(uVar4 >> 8);
    uVar4 = (((*puVar2 & 0xff) * 0x100 + (uint)(*puVar2 >> 8)) * 0x2000 + 0x7fff) / 0xffff;
    *puVar1 = (char)uVar4;
    puVar1[1] = (char)(uVar4 >> 8);
    puVar1 = puVar1 + 6;
  }
  return 0;
}



/* 40497d44 FUN_40497d44 */

undefined4 FUN_40497d44(undefined4 param_1,ushort *param_2,int *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  uint uVar5;
  
  puVar1 = (undefined1 *)param_3[4];
  for (iVar2 = *param_3; iVar2 != 0; iVar2 = iVar2 + -1) {
    uVar5 = (((*param_2 & 0xff) * 0x100 + (uint)(*param_2 >> 8)) * 0x2000 + 0x7fff) / 0xffff;
    puVar1[5] = (char)(uVar5 >> 8);
    puVar1[4] = (char)uVar5;
    uVar5 = (((param_2[1] & 0xff) * 0x100 + (uint)(param_2[1] >> 8)) * 0x2000 + 0x7fff) / 0xffff;
    puVar3 = param_2 + 2;
    puVar4 = param_2 + 3;
    param_2 = param_2 + 4;
    puVar1[2] = (char)uVar5;
    puVar1[3] = (char)(uVar5 >> 8);
    uVar5 = (((*puVar3 & 0xff) * 0x100 + (uint)(*puVar3 >> 8)) * 0x2000 + 0x7fff) / 0xffff;
    *puVar1 = (char)uVar5;
    puVar1[1] = (char)(uVar5 >> 8);
    uVar5 = (((*puVar4 & 0xff) * 0x100 + (uint)(*puVar4 >> 8)) * 0x2000 + 0x7fff) / 0xffff;
    puVar1[6] = (char)uVar5;
    puVar1[7] = (char)(uVar5 >> 8);
    puVar1 = puVar1 + 8;
  }
  return 0;
}



/* 40497eb0 FUN_40497eb0 */

/* Boundary evidence: original MIPS .pdata 40497eb0..40497fab. Semantic name remains unreviewed. */

int FUN_40497eb0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_18 [2];
  
  iVar2 = 0;
  if (((param_1[0x1f] != 0) && (iVar1 = (**(code **)(*(int *)param_1[3] + 0x2c))(), iVar1 == 0)) &&
     ((param_1[0x11] != 0 || (iVar2 = FUN_40496bd4(param_1), -1 < iVar2)))) {
    local_18[0] = 0;
    iVar1 = param_1[0x1e] + param_1[0x1f] * 0x10;
    iVar2 = (**(code **)(*(int *)param_1[3] + 0x34))((int *)param_1[3],iVar1,local_18);
    if ((-1 < iVar2) &&
       (iVar2 = (**(code **)(*param_1 + 0x54))(param_1,iVar1,param_1[0x1f],local_18[0]), -1 < iVar2)
       ) {
      iVar2 = (**(code **)(*(int *)param_1[3] + 0x38))
                        ((int *)param_1[3],param_1[0x1f],iVar1,local_18[0]);
    }
  }
  return iVar2;
}



/* 40497fac FUN_40497fac */

/* Boundary evidence: original MIPS .pdata 40497fac..4049809f. Semantic name remains unreviewed. */

undefined4 FUN_40497fac(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  
  if ((*(int *)(param_1 + 0x30) == 1) && (piVar1 = *(int **)(param_1 + 0x28), piVar1 != (int *)0x0))
  {
    (**(code **)(*piVar1 + 0x14))
              (piVar1,*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x1c),0);
    *(undefined4 *)(param_1 + 0x2c) = 0;
    (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x10);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(puVar2,1);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(LPVOID *)(param_1 + 0x18) != (LPVOID)0x0) {
    FUN_404962ec(*(LPVOID *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  if (*(LPVOID *)(param_1 + 0x20) != (LPVOID)0x0) {
    FUN_404962ec(*(LPVOID *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 8))();
    *(undefined4 *)(param_1 + 8) = 0;
  }
  FUN_40497938(param_1);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return 0;
}



/* 404980a0 FUN_404980a0 */

undefined4 FUN_404980a0(int param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *(int *)(param_1 + 0x10);
  cVar1 = *(char *)(*(int *)(iVar4 + 0x24) + *(int *)(iVar4 + 0x1c) + 0x11);
  cVar2 = *(char *)(*(int *)(iVar4 + 0x24) + *(int *)(iVar4 + 0x1c) + 0x10);
  uVar5 = 0x26200a;
  uVar3 = uVar5;
  if (cVar1 != '\0') {
    if (cVar1 == '\x02') {
      if (cVar2 == '\b') {
        uVar3 = 0x21808;
      }
      else {
        if (cVar2 != '\x10') {
          return 0;
        }
        uVar3 = 0x10300c;
      }
    }
    else if (cVar1 == '\x03') {
      if (cVar2 == '\x01') {
        uVar3 = 0x30101;
      }
      else if (cVar2 != '\x02') {
        if (cVar2 == '\x04') {
          uVar3 = 0x30402;
        }
        else {
          if (cVar2 != '\b') {
            return 0;
          }
          uVar3 = 0x30803;
        }
      }
    }
    else if (cVar1 == '\x04') {
      if ((cVar2 != '\b') && (cVar2 != '\x10')) {
        return 0;
      }
    }
    else {
      if (cVar1 != '\x06') {
        return 0;
      }
      if (cVar2 != '\b') {
        if (cVar2 != '\x10') {
          return 0;
        }
        uVar3 = 0x34400d;
      }
    }
  }
  if (0 < *(int *)(*(int *)(param_1 + 0x10) + 200)) {
    uVar3 = uVar5;
  }
  return uVar3;
}



/* 404981f8 FUN_404981f8 */

undefined4 FUN_404981f8(int param_1,byte *param_2,int *param_3)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte *pbVar9;
  int iVar10;
  
  iVar5 = *(int *)(param_1 + 0x10);
  iVar10 = *param_3;
  cVar2 = *(char *)(*(int *)(iVar5 + 0x24) + *(int *)(iVar5 + 0x1c) + 0x10);
  pbVar9 = (byte *)param_3[4];
  bVar1 = *(int *)(iVar5 + 200) < 1;
  if (cVar2 == '\x01') {
    uVar6 = 0;
    bVar3 = *(byte *)(*(int *)(param_1 + 0x10) + 0xcd);
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      uVar6 = uVar6 & 7;
      uVar7 = 1 << (7 - uVar6 & 0x1f) & (uint)*param_2;
      bVar8 = 0xff;
      if (uVar7 == 0) {
        bVar8 = 0;
      }
      if ((bVar1) || (bVar4 = 0, uVar7 != (bVar3 & 1))) {
        bVar4 = 0xff;
      }
      pbVar9[3] = bVar4;
      pbVar9[2] = bVar8;
      pbVar9[1] = bVar8;
      *pbVar9 = bVar8;
      pbVar9 = pbVar9 + 4;
      if (uVar6 == 7) {
        param_2 = param_2 + 1;
      }
      uVar6 = uVar6 + 1;
    }
  }
  else if (cVar2 == '\x02') {
    uVar6 = 0;
    bVar3 = *(byte *)(*(int *)(param_1 + 0x10) + 0xcd);
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      uVar6 = uVar6 & 3;
      uVar7 = (3 - uVar6) * 2;
      uVar7 = (int)(3 << (uVar7 & 0x1f) & (uint)*param_2) >> (uVar7 & 0x1f);
      bVar8 = (byte)(((uVar7 << 2 | uVar7) << 2 | uVar7) << 2) | (byte)uVar7;
      if ((bVar1) || (bVar4 = 0, uVar7 != (bVar3 & 3))) {
        bVar4 = 0xff;
      }
      pbVar9[3] = bVar4;
      pbVar9[2] = bVar8;
      pbVar9[1] = bVar8;
      *pbVar9 = bVar8;
      pbVar9 = pbVar9 + 4;
      if (uVar6 == 3) {
        param_2 = param_2 + 1;
      }
      uVar6 = uVar6 + 1;
    }
  }
  else if (cVar2 == '\x04') {
    uVar6 = 0;
    bVar3 = *(byte *)(*(int *)(param_1 + 0x10) + 0xcd);
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      uVar6 = uVar6 & 1;
      uVar7 = uVar6 * -4 + 4;
      uVar7 = (int)(0xf << (uVar7 & 0x1f) & (uint)*param_2) >> (uVar7 & 0x1f);
      bVar8 = (byte)(uVar7 << 4) | (byte)uVar7;
      if ((bVar1) || (bVar4 = 0, uVar7 != (bVar3 & 0xf))) {
        bVar4 = 0xff;
      }
      pbVar9[3] = bVar4;
      pbVar9[2] = bVar8;
      pbVar9[1] = bVar8;
      *pbVar9 = bVar8;
      pbVar9 = pbVar9 + 4;
      if (uVar6 == 1) {
        param_2 = param_2 + 1;
      }
      uVar6 = uVar6 + 1;
    }
  }
  else if (cVar2 == '\b') {
    bVar3 = *(byte *)(*(int *)(param_1 + 0x10) + 0xcd);
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      bVar8 = *param_2;
      if ((bVar1) || (bVar4 = 0, bVar8 != bVar3)) {
        bVar4 = 0xff;
      }
      pbVar9[2] = bVar8;
      pbVar9[1] = bVar8;
      *pbVar9 = bVar8;
      pbVar9[3] = bVar4;
      pbVar9 = pbVar9 + 4;
      param_2 = param_2 + 1;
    }
  }
  else {
    if (cVar2 != '\x10') {
      return 0x80004005;
    }
    bVar3 = *(byte *)(*(int *)(param_1 + 0x10) + 0xcc);
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      bVar8 = *param_2;
      if ((bVar1) || (bVar4 = 0, bVar8 != bVar3)) {
        bVar4 = 0xff;
      }
      pbVar9[2] = bVar8;
      pbVar9[1] = bVar8;
      *pbVar9 = bVar8;
      pbVar9[3] = bVar4;
      pbVar9 = pbVar9 + 4;
      param_2 = param_2 + 2;
    }
  }
  return 0;
}



/* 404984bc FUN_404984bc */

undefined4 FUN_404984bc(int param_1,char *param_2,int *param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  
  iVar6 = *(int *)(param_1 + 0x10);
  iVar8 = *param_3;
  cVar2 = *(char *)(*(int *)(iVar6 + 0x24) + *(int *)(iVar6 + 0x1c) + 0x10);
  pcVar5 = (char *)param_3[4];
  bVar1 = *(int *)(iVar6 + 200) < 1;
  if (cVar2 == '\b') {
    iVar6 = *(int *)(param_1 + 0x10);
    cVar2 = *(char *)(iVar6 + 0xcd);
    cVar3 = *(char *)(iVar6 + 0xcf);
    cVar4 = *(char *)(iVar6 + 0xd1);
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      if ((((bVar1) || (cVar2 != *param_2)) || (cVar3 != param_2[1])) ||
         (cVar7 = '\0', cVar4 != param_2[2])) {
        cVar7 = -1;
      }
      pcVar5[3] = cVar7;
      pcVar5[2] = *param_2;
      pcVar5[1] = param_2[1];
      *pcVar5 = param_2[2];
      param_2 = param_2 + 3;
      pcVar5 = pcVar5 + 4;
    }
  }
  else {
    if (cVar2 != '\x10') {
      return 0x80004005;
    }
    iVar6 = *(int *)(param_1 + 0x10);
    cVar2 = *(char *)(iVar6 + 0xcc);
    cVar3 = *(char *)(iVar6 + 0xce);
    cVar4 = *(char *)(iVar6 + 0xd0);
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      if (((bVar1) || (cVar2 != *param_2)) ||
         ((cVar3 != param_2[2] || (cVar7 = '\0', cVar4 != param_2[4])))) {
        cVar7 = -1;
      }
      pcVar5[3] = cVar7;
      pcVar5[2] = *param_2;
      pcVar5[1] = param_2[2];
      *pcVar5 = param_2[4];
      param_2 = param_2 + 6;
      pcVar5 = pcVar5 + 4;
    }
  }
  return 0;
}



/* 40498628 FUN_40498628 */

/* Boundary evidence: original MIPS .pdata 40498628..404989b3. Semantic name remains unreviewed. */

undefined4 FUN_40498628(int param_1,byte *param_2,int *param_3)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined1 uVar11;
  
  iVar6 = *(int *)(param_1 + 0x10);
  iVar10 = *param_3;
  cVar2 = *(char *)(*(int *)(iVar6 + 0x24) + *(int *)(iVar6 + 0x1c) + 0x10);
  puVar9 = (undefined1 *)param_3[4];
  iVar4 = *(int *)(iVar6 + 0xc);
  uVar3 = 0;
  if (0 < (int)*(uint *)(iVar6 + 0x10)) {
    uVar3 = *(uint *)(iVar6 + 0x10);
  }
  bVar1 = *(int *)(*(int *)(param_1 + 0x10) + 200) < 1;
  if (cVar2 == '\x01') {
    uVar5 = 0;
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      uVar5 = uVar5 & 7;
      uVar8 = (int)(1 << (7 - uVar5 & 0x1f) & (uint)*param_2) >> (7 - uVar5 & 0x1f);
      if (uVar8 < uVar3) {
        if ((bVar1) || (*(uint *)(*(int *)(param_1 + 0x10) + 200) <= uVar8)) {
          uVar11 = 0xff;
        }
        else {
          uVar11 = *(undefined1 *)(*(int *)(param_1 + 0x10) + uVar8 + 0xcc);
        }
        puVar9[3] = uVar11;
        puVar7 = (undefined1 *)(uVar8 * 3 + iVar4);
        puVar9[2] = *puVar7;
        puVar9[1] = puVar7[1];
        *puVar9 = puVar7[2];
      }
      else {
        puVar9[3] = 0xff;
        puVar9[2] = 0;
        puVar9[1] = 0;
        *puVar9 = 0;
      }
      puVar9 = puVar9 + 4;
      if (uVar5 == 7) {
        param_2 = param_2 + 1;
      }
      uVar5 = uVar5 + 1;
    }
  }
  else if (cVar2 == '\x02') {
    uVar5 = 0;
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      uVar5 = uVar5 & 3;
      uVar8 = (3 - uVar5) * 2;
      uVar8 = (int)(3 << (uVar8 & 0x1f) & (uint)*param_2) >> (uVar8 & 0x1f);
      if (uVar8 < uVar3) {
        if ((bVar1) || (*(uint *)(*(int *)(param_1 + 0x10) + 200) <= uVar8)) {
          uVar11 = 0xff;
        }
        else {
          uVar11 = *(undefined1 *)(*(int *)(param_1 + 0x10) + uVar8 + 0xcc);
        }
        puVar9[3] = uVar11;
        puVar7 = (undefined1 *)(uVar8 * 3 + iVar4);
        puVar9[2] = *puVar7;
        puVar9[1] = puVar7[1];
        *puVar9 = puVar7[2];
      }
      else {
        puVar9[3] = 0xff;
        puVar9[2] = 0;
        puVar9[1] = 0;
        *puVar9 = 0;
      }
      puVar9 = puVar9 + 4;
      if (uVar5 == 3) {
        param_2 = param_2 + 1;
      }
      uVar5 = uVar5 + 1;
    }
  }
  else if (cVar2 == '\x04') {
    uVar5 = 0;
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      uVar5 = uVar5 & 1;
      uVar8 = uVar5 * -4 + 4;
      uVar8 = (int)(0xf << (uVar8 & 0x1f) & (uint)*param_2) >> (uVar8 & 0x1f);
      if (uVar8 < uVar3) {
        if ((bVar1) || (*(uint *)(*(int *)(param_1 + 0x10) + 200) <= uVar8)) {
          uVar11 = 0xff;
        }
        else {
          uVar11 = *(undefined1 *)(*(int *)(param_1 + 0x10) + uVar8 + 0xcc);
        }
        puVar9[3] = uVar11;
        puVar7 = (undefined1 *)(uVar8 * 3 + iVar4);
        puVar9[2] = *puVar7;
        puVar9[1] = puVar7[1];
        *puVar9 = puVar7[2];
      }
      else {
        puVar9[3] = 0xff;
        puVar9[2] = 0;
        puVar9[1] = 0;
        *puVar9 = 0;
      }
      puVar9 = puVar9 + 4;
      if (uVar5 == 1) {
        param_2 = param_2 + 1;
      }
      uVar5 = uVar5 + 1;
    }
  }
  else {
    if (cVar2 != '\b') {
      return 0x80004005;
    }
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      uVar5 = (uint)*param_2;
      if (uVar5 < uVar3) {
        if ((bVar1) || (*(uint *)(*(int *)(param_1 + 0x10) + 200) <= uVar5)) {
          uVar11 = 0xff;
        }
        else {
          uVar11 = *(undefined1 *)(*(int *)(param_1 + 0x10) + uVar5 + 0xcc);
        }
        puVar9[3] = uVar11;
        puVar7 = (undefined1 *)(uVar5 * 3 + iVar4);
        puVar9[2] = *puVar7;
        puVar9[1] = puVar7[1];
        *puVar9 = puVar7[2];
      }
      else {
        puVar9[3] = 0xff;
        puVar9[2] = 0;
        puVar9[1] = 0;
        *puVar9 = 0;
      }
      puVar9 = puVar9 + 4;
      param_2 = param_2 + 1;
    }
  }
  return 0;
}



/* 404989b4 FUN_404989b4 */

undefined4 FUN_404989b4(int param_1,undefined1 *param_2,int *param_3)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  
  iVar4 = *param_3;
  cVar1 = *(char *)(*(int *)(*(int *)(param_1 + 0x10) + 0x24) +
                    *(int *)(*(int *)(param_1 + 0x10) + 0x1c) + 0x10);
  puVar5 = (undefined1 *)param_3[4];
  if (cVar1 == '\b') {
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar3 = param_2 + 1;
      uVar2 = *param_2;
      param_2 = param_2 + 2;
      puVar5[3] = *puVar3;
      puVar5[2] = uVar2;
      puVar5[1] = uVar2;
      *puVar5 = uVar2;
      puVar5 = puVar5 + 4;
    }
  }
  else {
    if (cVar1 != '\x10') {
      return 0x80004005;
    }
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar3 = param_2 + 2;
      uVar2 = *param_2;
      param_2 = param_2 + 4;
      puVar5[3] = *puVar3;
      puVar5[2] = uVar2;
      puVar5[1] = uVar2;
      *puVar5 = uVar2;
      puVar5 = puVar5 + 4;
    }
  }
  return 0;
}



/* 40498a78 FUN_40498a78 */

undefined4 FUN_40498a78(int param_1,undefined1 *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = *param_3;
  cVar1 = *(char *)(*(int *)(*(int *)(param_1 + 0x10) + 0x24) +
                    *(int *)(*(int *)(param_1 + 0x10) + 0x1c) + 0x10);
  puVar3 = (undefined1 *)param_3[4];
  if (cVar1 == '\b') {
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      puVar3[2] = *param_2;
      puVar3[1] = param_2[1];
      *puVar3 = param_2[2];
      puVar3[3] = param_2[3];
      param_2 = param_2 + 4;
      puVar3 = puVar3 + 4;
    }
  }
  else {
    if (cVar1 != '\x10') {
      return 0x80004005;
    }
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      puVar3[2] = *param_2;
      puVar3[1] = param_2[2];
      *puVar3 = param_2[4];
      puVar3[3] = param_2[6];
      param_2 = param_2 + 8;
      puVar3 = puVar3 + 4;
    }
  }
  return 0;
}



/* 40498b5c FUN_40498b5c */

undefined4 * FUN_40498b5c(undefined4 *param_1)

{
  param_1[1] = &PTR_FUN_40484898;
  *param_1 = &PTR_FUN_404848d0;
  param_1[1] = &PTR_LAB_404848b4;
  param_1[0x21] = 1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[5] = 0;
  param_1[0xf] = 0;
  return param_1;
}



/* 40498bbc FUN_40498bbc */

/* Boundary evidence: original MIPS .pdata 40498bbc..40498c0f. Semantic name remains unreviewed. */

void FUN_40498bbc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_404848d0;
  param_1[1] = &PTR_LAB_404848b4;
  if (param_1[0xf] != 0) {
    FUN_40497fac((int)param_1);
  }
  param_1[1] = &PTR_FUN_40484898;
  return;
}



/* 40498c10 FUN_40498c10 */

/* Boundary evidence: original MIPS .pdata 40498c10..404990c7. Semantic name remains unreviewed. */

int FUN_40498c10(int param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  HDC hdc;
  undefined4 *puVar4;
  code *pcVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    puVar4 = *(undefined4 **)(param_1 + 8);
    if (puVar4 == (undefined4 *)0x0) {
      return -0x7fffbffb;
    }
    puVar7 = (undefined4 *)(param_1 + 0x28);
    iVar2 = (**(code **)*puVar4)(puVar4,&DAT_404812fc,puVar7);
    if (iVar2 < 0) {
      iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x14))();
      if (iVar2 < 0) {
        return iVar2;
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        puVar4 = (undefined4 *)FUN_404962c4(0x23c);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4 = FUN_404a4a3c(puVar4,param_1 + 4,*(undefined4 *)(param_1 + 8));
        }
        *(undefined4 **)(param_1 + 0x10) = puVar4;
      }
    }
    else {
      iVar2 = (**(code **)(*(int *)*puVar7 + 0xc))((int *)*puVar7,(undefined4 *)(param_1 + 0x1c));
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = (**(code **)(*(int *)*puVar7 + 0x10))
                        ((int *)*puVar7,*(undefined4 *)(param_1 + 0x1c),0,param_1 + 0x2c);
      if (iVar2 < 0) {
        return iVar2;
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        puVar4 = (undefined4 *)FUN_404962c4(0x23c);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4 = FUN_404a4a3c(puVar4,param_1 + 4,*(undefined4 *)(param_1 + 8));
        }
        *(undefined4 **)(param_1 + 0x10) = puVar4;
      }
      *(undefined4 *)(param_1 + 0x30) = 1;
    }
    if (*(int **)(param_1 + 0x10) == (int *)0x0) {
      return -0x7fffbffb;
    }
    iVar2 = FUN_404a6a18(*(int **)(param_1 + 0x10));
    pcVar5 = *(code **)(**(int **)(param_1 + 8) + 8);
    if (iVar2 == 0) {
      (*pcVar5)();
      *(undefined4 *)(param_1 + 8) = 0;
      return -0x7fffbffb;
    }
    (*pcVar5)();
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x34) = 1;
  }
  param_2[0xe] = 0x52000;
  *param_2 = 0xb96b3caf;
  param_2[1] = 0x11d30728;
  param_2[2] = 0x7b9d;
  param_2[3] = 0x2ef31ef8;
  uVar3 = FUN_404980a0(param_1);
  param_2[4] = uVar3;
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x24) + *(int *)(*(int *)(param_1 + 0x10) + 0x1c);
  param_2[5] = (((uint)*(byte *)(iVar2 + 8) * 0x100 + (uint)*(byte *)(iVar2 + 9)) * 0x100 +
               (uint)*(byte *)(iVar2 + 10)) * 0x100 + (uint)*(byte *)(iVar2 + 0xb);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x24) + *(int *)(*(int *)(param_1 + 0x10) + 0x1c);
  param_2[6] = (((uint)*(byte *)(iVar2 + 0xc) * 0x100 + (uint)*(byte *)(iVar2 + 0xd)) * 0x100 +
               (uint)*(byte *)(iVar2 + 0xe)) * 0x100 + (uint)*(byte *)(iVar2 + 0xf);
  param_2[7] = param_2[5];
  param_2[8] = 1;
  if (*(char *)(*(int *)(param_1 + 0x10) + 0x1d1) == '\x01') {
    uVar8 = __ultodp(*(undefined4 *)(*(int *)(param_1 + 0x10) + 0xb4));
    uVar8 = __dpmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0x406fc000);
    uVar8 = __dpdiv((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0x40c38800);
    *(undefined8 *)(param_2 + 10) = uVar8;
    uVar8 = __ultodp(*(undefined4 *)(*(int *)(param_1 + 0x10) + 0xb8));
    uVar8 = __dpmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0x406fc000);
    uVar8 = __dpdiv((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0x40c38800);
    *(undefined8 *)(param_2 + 0xc) = uVar8;
    param_2[0xe] = 0x53000;
    goto LAB_40498fd0;
  }
  hdc = GetDC((HWND)0x0);
  if (hdc == (HDC)0x0) {
LAB_40498fb0:
    param_2[10] = 0;
    param_2[0xb] = 0x40580000;
    param_2[0xc] = 0;
    param_2[0xd] = 0x40580000;
  }
  else {
    iVar2 = GetDeviceCaps(hdc,0x58);
    uVar3 = __litofp(iVar2);
    uVar8 = __fptodp(uVar3);
    *(undefined8 *)(param_2 + 10) = uVar8;
    iVar2 = __led((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0);
    if (iVar2 != 0) goto LAB_40498fb0;
    iVar2 = GetDeviceCaps(hdc,0x5a);
    uVar3 = __litofp(iVar2);
    uVar8 = __fptodp(uVar3);
    *(undefined8 *)(param_2 + 0xc) = uVar8;
    iVar2 = __led((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0);
    if (iVar2 != 0) goto LAB_40498fb0;
  }
  ReleaseDC((HWND)0x0,hdc);
LAB_40498fd0:
  iVar2 = *(int *)(param_1 + 0x10);
  cVar1 = *(char *)(*(int *)(iVar2 + 0x24) + *(int *)(iVar2 + 0x1c) + 0x11);
  if (cVar1 == '\0') {
    if (0 < *(int *)(iVar2 + 200)) {
      param_2[0xe] = param_2[0xe] | 2;
    }
    uVar6 = param_2[0xe] | 0x40;
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x03') {
        if (*(int *)(iVar2 + 200) < 1) {
          return 0;
        }
        param_2[0xe] = param_2[0xe] | 6;
        return 0;
      }
      if (cVar1 != '\x04') {
        if (cVar1 != '\x06') {
          return 0;
        }
        param_2[0xe] = param_2[0xe] | 0x16;
        return 0;
      }
      param_2[0xe] = param_2[0xe] | 0x46;
      return 0;
    }
    if (0 < *(int *)(iVar2 + 200)) {
      param_2[0xe] = param_2[0xe] | 2;
    }
    uVar6 = param_2[0xe] | 0x10;
  }
  param_2[0xe] = uVar6;
  return 0;
}



/* 404990c8 FUN_404990c8 */

/* Boundary evidence: original MIPS .pdata 404990c8..4049917f. Semantic name remains unreviewed. */

undefined4 FUN_404990c8(int param_1,byte *param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *(char *)(*(int *)(*(int *)(param_1 + 0x10) + 0x24) +
                    *(int *)(*(int *)(param_1 + 0x10) + 0x1c) + 0x11);
  if (cVar1 == '\0') {
    uVar2 = FUN_404981f8(param_1,param_2,param_3);
  }
  else if (cVar1 == '\x02') {
    uVar2 = FUN_404984bc(param_1,(char *)param_2,param_3);
  }
  else if (cVar1 == '\x03') {
    uVar2 = FUN_40498628(param_1,param_2,param_3);
  }
  else if (cVar1 == '\x04') {
    uVar2 = FUN_404989b4(param_1,param_2,param_3);
  }
  else if (cVar1 == '\x06') {
    uVar2 = FUN_40498a78(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 40499180 FUN_40499180 */

/* Boundary evidence: original MIPS .pdata 40499180..404991cb. Semantic name remains unreviewed. */

undefined4 * FUN_40499180(undefined4 *param_1,uint param_2)

{
  FUN_40498bbc(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404991cc FUN_404991cc */

/* Boundary evidence: original MIPS .pdata 404991cc..404993f3. Semantic name remains unreviewed. */

int FUN_404991cc(int param_1,int param_2)

{
  int iVar1;
  ushort *_Src;
  uint _Size;
  size_t sVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  size_t local_28 [4];
  void *local_18;
  
  iVar1 = FUN_404980a0(param_1);
  local_30 = *(undefined4 *)(param_2 + 0x14);
  local_38 = 0;
  if (iVar1 == 0) {
LAB_404991fc:
    iVar1 = -0x7fffbffb;
  }
  else {
    if (*(uint *)(param_1 + 0x40) < *(uint *)(param_2 + 0x18)) {
      do {
        local_34 = *(int *)(param_1 + 0x40);
        local_2c = local_34 + 1;
        iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))
                          (*(int **)(param_1 + 0xc),&local_38,*(undefined4 *)(param_2 + 0x10),1,
                           local_28);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (local_18 == (void *)0x0) {
          return iVar1;
        }
        _Src = (ushort *)FUN_404a6118(*(int *)(param_1 + 0x10));
        if (_Src == (ushort *)0x0) goto LAB_404991fc;
        uVar3 = *(uint *)(param_2 + 0x10);
        if (uVar3 == 0x26200a) {
          FUN_404990c8(param_1,(byte *)_Src,(int *)local_28);
        }
        else if ((uVar3 & 0x10000) == 0) {
          if (uVar3 == 0x21808) {
            if (local_28[0] != 0) {
              puVar4 = (undefined1 *)((int)local_18 + 2);
              sVar2 = local_28[0];
              do {
                *puVar4 = (char)*_Src;
                puVar4[-1] = *(undefined1 *)((int)_Src + 1);
                sVar2 = sVar2 - 1;
                puVar4[-2] = (char)_Src[1];
                _Src = (ushort *)((int)_Src + 3);
                puVar4 = puVar4 + 3;
              } while (sVar2 != 0);
            }
          }
          else if (uVar3 == 0x10300c) {
            FUN_40497c2c(param_1,_Src,(int *)local_28);
          }
          else {
            if (uVar3 != 0x34400d) goto LAB_404991fc;
            FUN_40497d44(param_1,_Src,(int *)local_28);
          }
        }
        else {
          if (uVar3 == 0x30402) {
            _Size = local_28[0] + 1 >> 1;
          }
          else {
            _Size = local_28[0];
            if (uVar3 == 0x30101) {
              _Size = local_28[0] + 7 >> 3;
            }
          }
          memcpy(local_18,_Src,_Size);
        }
        iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))(*(int **)(param_1 + 0xc),local_28);
        if (iVar1 < 0) {
          return iVar1;
        }
        uVar3 = *(int *)(param_1 + 0x40) + 1;
        *(uint *)(param_1 + 0x40) = uVar3;
      } while (uVar3 < *(uint *)(param_2 + 0x18));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 404993f4 FUN_404993f4 */

/* Boundary evidence: original MIPS .pdata 404993f4..404996d7. Semantic name remains unreviewed. */

int FUN_404993f4(int *param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  undefined1 auStack_60 [16];
  uint local_50;
  int local_4c;
  int local_48;
  uint local_20;
  
  local_20 = DAT_404bd274;
  if (param_1[3] == 0) {
    FUN_404a438c(DAT_404bd274);
    return -0x7fffbffb;
  }
  iVar4 = (**(code **)(*param_1 + 0x30))(param_1,auStack_60);
  if (-1 < iVar4) {
    if (param_1[0xe] == 0) {
      iVar4 = FUN_40497eb0(param_1);
      if ((iVar4 < 0) ||
         (iVar4 = (**(code **)(*(int *)param_1[3] + 0xc))((int *)param_1[3],auStack_60,0), iVar4 < 0
         )) goto LAB_404996b0;
      iVar9 = param_1[4];
      iVar4 = *(int *)(iVar9 + 0x24) + *(int *)(iVar9 + 0x1c);
      local_4c = (((uint)*(byte *)(iVar4 + 8) * 0x100 + (uint)*(byte *)(iVar4 + 9)) * 0x100 +
                 (uint)*(byte *)(iVar4 + 10)) * 0x100 + (uint)*(byte *)(iVar4 + 0xb);
      iVar4 = *(int *)(iVar9 + 0x24) + *(int *)(iVar9 + 0x1c);
      local_48 = (((uint)*(byte *)(iVar4 + 0xc) * 0x100 + (uint)*(byte *)(iVar4 + 0xd)) * 0x100 +
                 (uint)*(byte *)(iVar4 + 0xe)) * 0x100 + (uint)*(byte *)(iVar4 + 0xf);
      uVar5 = FUN_404980a0((int)param_1);
      if ((local_50 != uVar5) || ((uVar5 == 0x10300c || (uVar5 == 0x34400d)))) {
        local_50 = 0x26200a;
      }
      param_1[0xe] = 1;
    }
    if ((local_50 & 0x10000) != 0) {
      uVar5 = *(uint *)(param_1[4] + 0x10);
      iVar4 = *(int *)(param_1[4] + 0xc);
      puVar6 = (undefined4 *)FUN_404962c4((uVar5 + 3) * 4);
      param_1[5] = (int)puVar6;
      if (puVar6 == (undefined4 *)0x0) {
        FUN_404a438c(local_20);
        return -0x7ff8fff2;
      }
      *puVar6 = 0;
      iVar9 = 8;
      *(uint *)(param_1[5] + 4) = uVar5;
      if (uVar5 != 0) {
        iVar11 = 8;
        pbVar10 = (byte *)(iVar4 + 2);
        uVar7 = uVar5;
        do {
          pbVar1 = pbVar10 + -2;
          pbVar2 = pbVar10 + -1;
          bVar3 = *pbVar10;
          puVar8 = (uint *)(iVar11 + param_1[5]);
          iVar11 = iVar11 + 4;
          pbVar10 = pbVar10 + 3;
          uVar7 = uVar7 - 1;
          *puVar8 = ((*pbVar1 | 0xff00) << 8 | (uint)*pbVar2) << 8 | (uint)bVar3;
        } while (uVar7 != 0);
      }
      if (0 < *(int *)(param_1[4] + 200)) {
        *(undefined4 *)param_1[5] = 1;
        uVar7 = *(uint *)(param_1[4] + 200);
        if ((int)uVar5 < (int)*(uint *)(param_1[4] + 200)) {
          uVar7 = uVar5;
        }
        uVar5 = 0;
        if (uVar7 != 0) {
          do {
            puVar8 = (uint *)(iVar9 + param_1[5]);
            iVar4 = param_1[4] + uVar5;
            uVar5 = uVar5 + 1;
            iVar9 = iVar9 + 4;
            *puVar8 = (uint)*(byte *)(iVar4 + 0xcc) << 0x18 | *puVar8 & 0xffffff;
          } while (uVar5 < uVar7);
        }
      }
      iVar4 = (**(code **)(*(int *)param_1[3] + 0x14))((int *)param_1[3],param_1[5]);
      if (iVar4 < 0) goto LAB_404996b0;
    }
    iVar4 = FUN_404991cc((int)param_1,(int)auStack_60);
  }
LAB_404996b0:
  FUN_404a438c(local_20);
  return iVar4;
}



/* 404996d8 FUN_404996d8 */

/* Boundary evidence: original MIPS .pdata 404996d8..40499733. Semantic name remains unreviewed. */

void FUN_404996d8(void)

{
  HRESULT HVar1;
  int iVar2;
  uint uVar3;
  
  HVar1 = DllCanUnloadNow();
  uVar3 = 2;
  if (HVar1 == 0) {
    uVar3 = 0;
  }
  iVar2 = FUN_404a3c98();
  DAT_404bd1f4 = iVar2 != 0 | uVar3 | DAT_404bd1f4;
  return;
}



/* 40499734 FUN_40499734 */

/* Boundary evidence: original MIPS .pdata 40499734..4049979f. Semantic name remains unreviewed. */

undefined4 * FUN_40499734(undefined4 *param_1)

{
  FUN_4049c068(param_1);
  FUN_404a3db4(param_1 + 0x200);
  *param_1 = &PTR_FUN_404849dc;
  param_1[0x200] = &PTR_LAB_40484994;
  param_1[0x201] = &PTR_LAB_40484958;
  param_1[0x32e] = 1;
  return param_1;
}



/* 404997a0 FUN_404997a0 */

/* Boundary evidence: original MIPS .pdata 404997a0..404997f3. Semantic name remains unreviewed. */

void FUN_404997a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_404849dc;
  param_1[0x200] = &PTR_LAB_40484994;
  param_1[0x201] = &PTR_LAB_40484958;
  FUN_404a3d2c(param_1 + 0x200);
  FUN_4049c0c8(param_1);
  return;
}



/* 404997f4 FUN_404997f4 */

/* Boundary evidence: original MIPS .pdata 404997f4..4049980f. Semantic name remains unreviewed. */

void FUN_404997f4(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0xcb8));
  return;
}



/* 40499810 FUN_40499810 */

/* Boundary evidence: original MIPS .pdata 40499810..4049986b. Semantic name remains unreviewed. */

LONG FUN_40499810(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0x32e);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xa0))(param_1,1);
  }
  return LVar1;
}



/* 404998d0 FUN_404998d0 */

/* Boundary evidence: original MIPS .pdata 404998d0..40499973. Semantic name remains unreviewed. */

undefined4 FUN_404998d0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_404962c4(0xcc0);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_40499734(puVar1);
  }
  if (piVar2 == (int *)0x0) {
    *param_2 = 0;
    uVar3 = 0x8007000e;
  }
  else {
    uVar3 = (**(code **)*piVar2)(piVar2,param_1,param_2);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return uVar3;
}



/* 40499974 FUN_40499974 */

/* Boundary evidence: original MIPS .pdata 40499974..404999bf. Semantic name remains unreviewed. */

undefined4 * FUN_40499974(undefined4 *param_1,uint param_2)

{
  FUN_404997a0(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404999c0 FUN_404999c0 */

/* Boundary evidence: original MIPS .pdata 404999c0..40499aa7. Semantic name remains unreviewed. */

undefined4 FUN_404999c0(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  HRESULT HVar2;
  int *piVar3;
  
  iVar1 = memcmp(param_2,&DAT_404812bc,0x10);
  if ((iVar1 != 0) || (HVar2 = DllCanUnloadNow(), HVar2 == 0)) {
    iVar1 = memcmp(param_2,&DAT_404812cc,0x10);
    if ((iVar1 == 0) && (iVar1 = FUN_404a3c98(), iVar1 != 0)) {
      piVar3 = param_1 + 0x200;
      if (param_1 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      *param_3 = (int)piVar3;
      goto LAB_40499a6c;
    }
    iVar1 = memcmp(param_2,&DAT_40482c64,0x10);
    if (iVar1 != 0) {
      *param_3 = 0;
      return 0x80004002;
    }
  }
  *param_3 = (int)param_1;
LAB_40499a6c:
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}



/* 40499ad0 FUN_40499ad0 */

/* Boundary evidence: original MIPS .pdata 40499ad0..40499b27. Semantic name remains unreviewed. */

undefined4 * FUN_40499ad0(undefined4 *param_1,SIZE_T param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_404962c4(param_2);
  param_1[2] = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0x4c494146;
  }
  else {
    uVar2 = 0x4f664731;
  }
  *param_1 = uVar2;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



/* 40499b28 FUN_40499b28 */

/* Boundary evidence: original MIPS .pdata 40499b28..40499bbf. Semantic name remains unreviewed. */

undefined4 FUN_40499b28(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_404812bc,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40482c64,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 40499bc0 FUN_40499bc0 */

/* Boundary evidence: original MIPS .pdata 40499bc0..40499bdb. Semantic name remains unreviewed. */

void FUN_40499bc0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x7fc));
  return;
}



/* 40499bdc FUN_40499bdc */

/* Boundary evidence: original MIPS .pdata 40499bdc..40499c37. Semantic name remains unreviewed. */

LONG FUN_40499bdc(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0x1ff);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xa0))(param_1,1);
  }
  return LVar1;
}



/* 40499c38 FUN_40499c38 */

/* Boundary evidence: original MIPS .pdata 40499c38..40499d67. Semantic name remains unreviewed. */

undefined4 FUN_40499c38(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x50) == 1) {
    uVar2 = 0x80004005;
  }
  else {
    if (*(int *)(param_1 + 0x54) == 0) {
      (**(code **)(*param_2 + 4))(param_2);
      *(int **)(param_1 + 0x54) = param_2;
      *(undefined4 *)(param_1 + 0x7b0) = param_3;
      *(undefined4 *)(param_1 + 0x7c4) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(param_1 + 0x7bc) = 0;
      *(undefined4 *)(param_1 + 0x7c0) = 1;
      *(undefined4 *)(param_1 + 0x7f8) = 0;
      *(undefined4 *)(param_1 + 0x7b8) = 0;
      memset((void *)(param_1 + 0x7a4),0,5);
      *(undefined4 *)(param_1 + 0x494) = 0;
      *(undefined2 *)(param_1 + 0x498) = 0;
      *(undefined2 *)(param_1 + 0x49a) = 0;
      *(undefined4 *)(param_1 + 0x49c) = 0;
      *(undefined2 *)(param_1 + 0x4a0) = 0;
      *(undefined2 *)(param_1 + 0x4a2) = 0;
      *(undefined2 *)(param_1 + 0x7d8) = 1;
      *(undefined4 *)(param_1 + 0x464) = 0;
      *(undefined4 *)(param_1 + 0x468) = 0;
      *(undefined4 *)(param_1 + 0x46c) = 0;
      *(undefined4 *)(param_1 + 0x474) = 100;
      iVar1 = FUN_404962c4(400);
      *(int *)(param_1 + 0x470) = iVar1;
      if (iVar1 == 0) {
        uVar2 = 0x8007000e;
      }
      else {
        *(undefined4 *)(param_1 + 0x478) = 0;
        *(undefined4 *)(param_1 + 0x47c) = 0;
        *(uint *)(param_1 + 0x7b4) = (uint)((*(uint *)(param_1 + 0x7b0) & 1) == 0);
      }
    }
    else {
      uVar2 = 0x80070057;
    }
    *(undefined4 *)(param_1 + 0x50) = 1;
  }
  return uVar2;
}



/* 40499d68 FUN_40499d68 */

/* Boundary evidence: original MIPS .pdata 40499d68..40499d97. Semantic name remains unreviewed. */

undefined4 FUN_40499d68(void)

{
  FUN_404a438c(DAT_404bd274);
  return 0x80004001;
}



/* 40499d98 FUN_40499d98 */

/* Boundary evidence: original MIPS .pdata 40499d98..40499dc7. Semantic name remains unreviewed. */

undefined4 FUN_40499d98(void)

{
  FUN_404a438c(DAT_404bd274);
  return 0x80004001;
}



/* 40499dc8 FUN_40499dc8 */

/* Boundary evidence: original MIPS .pdata 40499dc8..40499e43. Semantic name remains unreviewed. */

int FUN_40499dc8(int *param_1,int *param_2)

{
  int iVar1;
  undefined1 auStack_18 [8];
  
  if (param_2 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else if ((param_1[0x1f9] != -1) ||
          (iVar1 = (**(code **)(*param_1 + 0x28))(param_1,&DAT_4048130c,auStack_18), -1 < iVar1)) {
    iVar1 = 0;
    *param_2 = param_1[0x119];
  }
  return iVar1;
}



/* 40499e44 FUN_40499e44 */

/* Boundary evidence: original MIPS .pdata 40499e44..40499f1b. Semantic name remains unreviewed. */

int FUN_40499e44(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 auStack_18 [8];
  
  if ((param_1[0x1f9] != -1) ||
     (iVar1 = (**(code **)(*param_1 + 0x28))(param_1,&DAT_4048130c,auStack_18), -1 < iVar1)) {
    if ((param_2 == param_1[0x119]) && (param_3 != (undefined4 *)0x0)) {
      if (param_1[0x119] != 0) {
        *param_3 = 0x5100;
        iVar1 = 1;
        if (param_1[0x11f] != 0) {
          param_3[1] = 0x9286;
          iVar1 = 2;
        }
        if (param_1[0x1f5] == 1) {
          param_3[iVar1] = 0x5101;
        }
      }
      iVar1 = 0;
    }
    else {
      iVar1 = -0x7ff8ffa9;
    }
  }
  return iVar1;
}



/* 40499f1c FUN_40499f1c */

/* Boundary evidence: original MIPS .pdata 40499f1c..40499ff7. Semantic name remains unreviewed. */

int FUN_40499f1c(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined1 auStack_18 [8];
  
  iVar1 = 0;
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else if ((param_1[0x1f9] != -1) ||
          (iVar1 = (**(code **)(*param_1 + 0x28))(param_1,&DAT_4048130c,auStack_18), -1 < iVar1)) {
    if (param_2 == 0x5100) {
      *param_3 = (param_1[0x1f9] + 4) * 4;
    }
    else if (param_2 == 0x9286) {
      *param_3 = param_1[0x11f] + 0x11;
    }
    else if (param_2 == 0x5101) {
      *param_3 = 0x12;
    }
    else {
      iVar1 = -0x7784fff6;
    }
  }
  return iVar1;
}



/* 40499ff8 FUN_40499ff8 */

/* Boundary evidence: original MIPS .pdata 40499ff8..4049a187. Semantic name remains unreviewed. */

int FUN_40499ff8(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int *_Src;
  size_t _Size;
  int iVar1;
  int iVar2;
  undefined4 *_Dst;
  undefined1 auStack_28 [8];
  
  iVar2 = 0;
  if (param_4 != (undefined4 *)0x0) {
    if ((param_1[0x1f9] == -1) &&
       (iVar2 = (**(code **)(*param_1 + 0x28))(param_1,&DAT_4048130c,auStack_28), iVar2 < 0)) {
      return iVar2;
    }
    _Dst = param_4 + 4;
    if (param_2 == 0x5100) {
      _Size = param_1[0x1f9] * 4;
      if (param_3 == _Size + 0x10) {
        *param_4 = 0x5100;
        iVar1 = param_1[0x1f9];
        param_4[3] = _Dst;
        param_4[1] = iVar1 << 2;
        *(undefined2 *)(param_4 + 2) = 4;
        _Src = (int *)param_1[0x11c];
LAB_4049a148:
        memcpy(_Dst,_Src,_Size);
        return iVar2;
      }
    }
    else if (param_2 == 0x9286) {
      if (param_3 == param_1[0x11f] + 0x11) {
        *param_4 = 0x9286;
        iVar1 = param_1[0x11f];
        param_4[3] = _Dst;
        param_4[1] = iVar1 + 1;
        *(undefined2 *)(param_4 + 2) = 2;
        memcpy(_Dst,(void *)param_1[0x11e],param_1[0x11f]);
        *(undefined1 *)(param_1[0x11f] + (int)_Dst) = 0;
        return iVar2;
      }
    }
    else {
      if (param_2 != 0x5101) {
        return -0x7784fff6;
      }
      if (param_3 == 0x12) {
        *param_4 = 0x5101;
        param_4[1] = 2;
        *(undefined2 *)(param_4 + 2) = 3;
        _Src = param_1 + 0x1f6;
        param_4[3] = _Dst;
        _Size = 2;
        goto LAB_4049a148;
      }
    }
  }
  return -0x7ff8ffa9;
}



/* 4049a188 FUN_4049a188 */

/* Boundary evidence: original MIPS .pdata 4049a188..4049a22b. Semantic name remains unreviewed. */

int FUN_4049a188(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined1 auStack_18 [8];
  
  if ((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else if ((param_1[0x1f9] != -1) ||
          (iVar1 = (**(code **)(*param_1 + 0x28))(param_1,&DAT_4048130c,auStack_18), -1 < iVar1)) {
    iVar1 = 0;
    *param_3 = param_1[0x119];
    *param_2 = param_1[0x11a] + param_1[0x119] * 0x10;
  }
  return iVar1;
}



/* 4049a22c FUN_4049a22c */

/* Boundary evidence: original MIPS .pdata 4049a22c..4049a39b. Semantic name remains unreviewed. */

int FUN_4049a22c(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  size_t _Size;
  undefined4 *puVar3;
  undefined1 auStack_20 [8];
  
  if (((param_2 == param_1[0x119] * 0x10 + param_1[0x11a]) && (param_3 == param_1[0x119])) &&
     (param_4 != (undefined4 *)0x0)) {
    if ((param_1[0x1f9] != -1) ||
       (iVar1 = (**(code **)(*param_1 + 0x28))(param_1,&DAT_4048130c,auStack_20), -1 < iVar1)) {
      iVar1 = param_1[0x1f9];
      _Size = iVar1 * 4;
      puVar2 = param_4 + param_1[0x119] * 4;
      *param_4 = 0x5100;
      param_4[1] = _Size;
      *(undefined2 *)(param_4 + 2) = 4;
      param_4[3] = puVar2;
      memcpy(puVar2,(void *)param_1[0x11c],_Size);
      puVar2 = puVar2 + iVar1;
      puVar3 = param_4;
      if (param_1[0x11f] != 0) {
        puVar3 = param_4 + 4;
        *puVar3 = 0x9286;
        iVar1 = param_1[0x11f];
        *(undefined2 *)(param_4 + 6) = 2;
        param_4[5] = iVar1 + 1;
        param_4[7] = puVar2;
        memcpy(puVar2,(void *)param_1[0x11e],param_1[0x11f]);
        *(undefined1 *)(param_1[0x11f] + (int)puVar2) = 0;
        puVar2 = (undefined4 *)((int)puVar2 + param_1[0x11f] + 1);
      }
      if (param_1[0x1f5] == 1) {
        puVar3[4] = 0x5101;
        puVar3[5] = 2;
        *(undefined2 *)(puVar3 + 6) = 3;
        puVar3[7] = puVar2;
        iVar1 = param_1[0x1f6];
        *(char *)puVar2 = (char)(short)iVar1;
        *(char *)((int)puVar2 + 1) = (char)((ushort)(short)iVar1 >> 8);
      }
      iVar1 = 0;
    }
  }
  else {
    iVar1 = -0x7ff8ffa9;
  }
  return iVar1;
}



/* 4049a3a8 FUN_4049a3a8 */

/* Boundary evidence: original MIPS .pdata 4049a3a8..4049a45b. Semantic name remains unreviewed. */

int FUN_4049a3a8(int param_1,int *param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x4c) == 1) {
    iVar1 = -0x7fffbffb;
  }
  else {
    *(undefined4 *)(param_1 + 0x4c) = 1;
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 0x480) = param_2;
    *(undefined4 *)(param_1 + 0x7c4) = 0;
    if ((*(int *)(param_1 + 0x7c0) == 0) && (*(int *)(param_1 + 0x7c8) == 0)) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x54) + 0x14))();
      if (iVar1 < 0) {
        return iVar1;
      }
      *(undefined4 *)(param_1 + 0x7bc) = 0;
      *(undefined4 *)(param_1 + 0x7f8) = 0;
    }
    *(undefined4 *)(param_1 + 0x7c0) = 0;
    iVar1 = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x460) + 4) = 0;
  }
  return iVar1;
}



/* 4049a45c FUN_4049a45c */

/* Boundary evidence: original MIPS .pdata 4049a45c..4049a4cf. Semantic name remains unreviewed. */

undefined4 FUN_4049a45c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(param_1 + 0x4c) = 0;
    uVar1 = (**(code **)(**(int **)(param_1 + 0x480) + 0x10))();
    (**(code **)(**(int **)(param_1 + 0x480) + 8))();
    *(undefined4 *)(param_1 + 0x480) = 0;
  }
  return uVar1;
}



/* 4049a4d0 FUN_4049a4d0 */

void FUN_4049a4d0(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  byte *pbVar1;
  uint *puVar2;
  undefined1 *puVar3;
  
  param_3[1] = param_4;
  *param_3 = 0;
  if (param_4 != 0) {
    puVar2 = param_3 + 2;
    pbVar1 = (byte *)(param_2 + 2);
    do {
      param_4 = param_4 + -1;
      *puVar2 = ((pbVar1[-2] | 0xff00) << 8 | (uint)pbVar1[-1]) << 8 | (uint)*pbVar1;
      puVar2 = puVar2 + 1;
      pbVar1 = pbVar1 + 3;
    } while (param_4 != 0);
  }
  if ((*(int *)(param_1 + 0x7b8) != 0) && ((*(byte *)(param_1 + 0x7a5) & 1) != 0)) {
    puVar3 = (undefined1 *)((uint)*(byte *)(param_1 + 0x7a8) * 3 + param_2);
    param_3[*(byte *)(param_1 + 0x7a8) + 2] = (uint)CONCAT21(CONCAT11(*puVar3,puVar3[1]),puVar3[2]);
    *param_3 = 1;
  }
  return;
}



/* 4049a594 FUN_4049a594 */

/* Boundary evidence: original MIPS .pdata 4049a594..4049a633. Semantic name remains unreviewed. */

int FUN_4049a594(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_310 [768];
  
  *param_3 = 1;
  if (param_2 == 1) {
    iVar1 = FUN_404901e4(*(int **)(param_1 + 0x54),(int)auStack_310,param_3[1] * 3,
                         *(int *)(param_1 + 0x7b4),(int *)0x0);
    if (iVar1 < 0) {
      return iVar1;
    }
    puVar2 = auStack_310;
  }
  else {
    if (*(int *)(param_1 + 0x7e0) == 0) {
      return -0x7fffbffb;
    }
    puVar2 = (undefined1 *)(param_1 + 0x4a4);
    param_3[1] = *(int *)(param_1 + 0x7e0);
  }
  FUN_4049a4d0(param_1,(int)puVar2,param_3,param_3[1]);
  return 0;
}



/* 4049a634 FUN_4049a634 */

/* Boundary evidence: original MIPS .pdata 4049a634..4049a817. Semantic name remains unreviewed. */

int FUN_4049a634(int *param_1,void *param_2)

{
  int iVar1;
  ushort uVar2;
  undefined1 auStack_20 [8];
  
  if (param_2 == (void *)0x0) {
    return -0x7ff8ffa9;
  }
  if (param_1[0x12] == 1) {
    memcpy(param_2,param_1 + 2,0x40);
    return 0;
  }
  if ((param_1[0x1f9] == -1) &&
     (iVar1 = (**(code **)(*param_1 + 0x28))(param_1,&DAT_4048130c,auStack_20), iVar1 < 0)) {
    return iVar1;
  }
  if (param_1[0x1f2] == 1) {
    uVar2 = *(ushort *)(param_1 + 0x126);
    if (*(ushort *)((int)param_1 + 0x48a) < uVar2) {
      *(char *)((int)param_1 + 0x48a) = (char)uVar2;
      *(char *)((int)param_1 + 0x48b) = (char)(uVar2 >> 8);
    }
    uVar2 = *(ushort *)((int)param_1 + 0x49a);
    if (uVar2 <= *(ushort *)(param_1 + 0x123)) goto LAB_4049a79c;
    *(char *)((int)param_1 + 0x48d) = (char)(uVar2 >> 8);
  }
  else {
    if (param_1[499] != 1) goto LAB_4049a79c;
    uVar2 = *(ushort *)(param_1 + 0x128);
    if (*(ushort *)((int)param_1 + 0x48a) < uVar2) {
      *(char *)((int)param_1 + 0x48a) = (char)uVar2;
      *(char *)((int)param_1 + 0x48b) = (char)(uVar2 >> 8);
    }
    uVar2 = *(ushort *)((int)param_1 + 0x4a2);
    if (uVar2 <= *(ushort *)(param_1 + 0x123)) goto LAB_4049a79c;
    *(char *)((int)param_1 + 0x48d) = (char)(uVar2 >> 8);
  }
  *(char *)(param_1 + 0x123) = (char)uVar2;
LAB_4049a79c:
  iVar1 = (**(code **)(*param_1 + 0x68))(param_1);
  param_1[7] = (uint)*(ushort *)((int)param_1 + 0x48a);
  param_1[8] = (uint)*(ushort *)(param_1 + 0x123);
  if (-1 < iVar1) {
    memcpy(param_2,param_1 + 2,0x40);
    param_1[0x12] = 1;
  }
  return iVar1;
}



/* 4049a818 FUN_4049a818 */

/* Boundary evidence: original MIPS .pdata 4049a818..4049ac3b. Semantic name remains unreviewed. */

int FUN_4049a818(int *param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  LPVOID pvVar4;
  undefined1 uVar5;
  code *pcVar6;
  int iVar7;
  char local_70 [4];
  int local_6c;
  undefined1 auStack_68 [16];
  int local_58;
  uint local_28;
  
  local_28 = DAT_404bd274;
  iVar2 = (**(code **)(*param_1 + 0x30))(param_1,auStack_68);
  if (iVar2 < 0) {
LAB_4049aa9c:
    FUN_404a438c(local_28);
    return iVar2;
  }
  if ((param_1[0x1f1] == 0) && (param_3 != 0)) {
    iVar2 = (**(code **)(*param_1 + 0x68))(param_1);
    if ((iVar2 < 0) ||
       (iVar2 = (**(code **)(*(int *)param_1[0x120] + 0xc))((int *)param_1[0x120],auStack_68,0),
       iVar2 < 0)) goto LAB_4049aa9c;
    if (local_58 != param_1[6]) {
      local_58 = 0x26200a;
    }
    param_1[0x1f1] = 1;
  }
  if ((param_2 == 0) || (((param_1[0x1f2] != 1 && (param_1[499] != 1)) || (param_1[0x1eb] != 0)))) {
LAB_4049a9a8:
    bVar1 = true;
    do {
      local_70[0] = '\0';
      local_6c = 0;
      iVar2 = FUN_404901e4((int *)param_1[0x15],(int)local_70,1,param_1[0x1ed],&local_6c);
      if (iVar2 < 0) goto LAB_4049aa9c;
      if (local_70[0] == '\0') {
        if ((iVar2 != 0) || (local_6c == 0)) {
LAB_4049ab14:
          FUN_404a438c(local_28);
          return -0x7784fff9;
        }
      }
      else {
        if (local_70[0] != '!') {
          if (local_70[0] == ',') {
            if (param_4 == 0) {
              iVar2 = FUN_4049035c((int *)param_1[0x15],-1,param_1[0x1ed]);
              if (iVar2 < 0) goto LAB_4049aa9c;
            }
            else {
              iVar2 = *param_1;
              memcpy(&stack0xffffff50,auStack_68,0x40);
              iVar2 = (**(code **)(iVar2 + 0x70))(param_1,param_2,param_3);
              if (iVar2 < 0) goto LAB_4049aa9c;
              if (param_2 != 0) {
                param_1[0x1fa] = param_1[0x1fa] + 1;
              }
              if (param_1[0x11b] == 0) {
                iVar7 = param_1[0x1f9];
                iVar2 = param_1[0x11d];
                if (iVar7 < iVar2) {
                  if (iVar7 < 0) goto LAB_4049abfc;
                }
                else {
                  param_1[0x11d] = iVar2 << 1;
                  pvVar4 = FUN_4049631c((LPVOID)param_1[0x11c],iVar2 << 3);
                  if (pvVar4 == (LPVOID)0x0) goto LAB_4049a970;
                  param_1[0x11c] = (int)pvVar4;
                }
                if (param_1[0x11d] <= iVar7) {
LAB_4049abfc:
                  FUN_404a438c(local_28);
                  return -0x7ff8ffa9;
                }
                *(uint *)(param_1[0x11c] + iVar7 * 4) = (uint)*(ushort *)((int)param_1 + 0x7a6);
              }
            }
          }
          else if ((local_70[0] != ';') || (param_2 == 0)) goto LAB_4049ab14;
          break;
        }
        iVar2 = FUN_404901e4((int *)param_1[0x15],(int)local_70,1,param_1[0x1ed],(int *)0x0);
        if (iVar2 < 0) goto LAB_4049aa9c;
        if (local_70[0] == '\x01') {
          pcVar6 = *(code **)(*param_1 + 0x7c);
LAB_4049aa84:
          iVar2 = (*pcVar6)(param_1,param_2);
        }
        else {
          if (local_70[0] == -7) {
            pcVar6 = *(code **)(*param_1 + 0x74);
            goto LAB_4049aa84;
          }
          if (local_70[0] == -2) {
            pcVar6 = *(code **)(*param_1 + 0x78);
            goto LAB_4049aa84;
          }
          if (local_70[0] == -1) {
            pcVar6 = *(code **)(*param_1 + 0x80);
            goto LAB_4049aa84;
          }
          bVar1 = false;
        }
        if (iVar2 < 0) goto LAB_4049aa9c;
      }
    } while (bVar1);
    FUN_404a438c(local_28);
    iVar2 = 0;
  }
  else {
    local_58 = 0x26200a;
    piVar3 = (int *)FUN_404962c4(0x430);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      uVar5 = *(undefined1 *)((int)param_1 + 0x48f);
      if ((param_1[0x1ee] != 0) && ((*(byte *)((int)param_1 + 0x7a5) & 1) != 0)) {
        uVar5 = (undefined1)param_1[0x1ea];
      }
      piVar3 = FUN_404a8b00(piVar3,(int)(param_1 + 0x121),local_58,uVar5);
    }
    param_1[0x1eb] = (int)piVar3;
    if (piVar3 != (int *)0x0) {
      if (piVar3[0x10b] != 0) goto LAB_4049a9a8;
      FUN_404a8be8((int)piVar3);
      FUN_404962ec(piVar3);
      param_1[0x1eb] = 0;
    }
LAB_4049a970:
    FUN_404a438c(local_28);
    iVar2 = -0x7ff8fff2;
  }
  return iVar2;
}



/* 4049ac3c FUN_4049ac3c */

/* Boundary evidence: original MIPS .pdata 4049ac3c..4049ad9b. Semantic name remains unreviewed. */

int FUN_4049ac3c(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_20 [8];
  undefined1 auStack_18 [8];
  
  if (param_1[0x13] == 0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar1 = 1;
    if (param_1[499] == 1) {
      if (1 < param_1[0x1f9]) {
        do {
          iVar2 = (**(code **)(*param_1 + 0x90))(param_1);
          if (iVar2 < 0) {
            return -0x7784fff9;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < param_1[0x1f9]);
      }
      iVar1 = (**(code **)(*param_1 + 0x84))(param_1,param_1[0x15],auStack_20);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = (**(code **)(*param_1 + 0x8c))(param_1);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = (**(code **)(*param_1 + 0x98))(param_1,param_1[0x15],auStack_20);
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    iVar1 = (**(code **)(*param_1 + 0x84))(param_1,param_1[0x15],auStack_18);
    if (((-1 < iVar1) && (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,1,1,1), -1 < iVar1)) &&
       (iVar1 = (**(code **)(*param_1 + 0x98))(param_1,param_1[0x15],auStack_18), -1 < iVar1)) {
      param_1[0x1fa] = param_1[0x1fa] + -1;
    }
  }
  return iVar1;
}



/* 4049ae18 FUN_4049ae18 */

/* Boundary evidence: original MIPS .pdata 4049ae18..4049b01b. Semantic name remains unreviewed. */

int FUN_4049ae18(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  int aiStack_18 [2];
  
  if ((param_3 == (int *)0x0) || (iVar1 = memcmp(param_2,&DAT_4048130c,0x10), iVar1 != 0)) {
    return -0x7ff8ffa9;
  }
  if (param_1[0x1f9] == -1) {
    pcVar3 = *(code **)(*param_1 + 0x84);
    iVar4 = param_1[0x1ef];
    param_1[0x1f9] = 0;
    iVar1 = (*pcVar3)(param_1,param_1[0x15],aiStack_18);
    if (iVar1 < 0) {
      return iVar1;
    }
    if ((iVar4 != 0) &&
       (iVar1 = (**(code **)(*param_1 + 0x98))(param_1,param_1[0x15],param_1 + 0x1fc), iVar1 < 0)) {
      return iVar1;
    }
    while (iVar1 = (**(code **)(*param_1 + 0x8c))(param_1), -1 < iVar1) {
      param_1[0x1f9] = param_1[0x1f9] + 1;
    }
    if (iVar1 != -0x7784fff9) {
      return iVar1;
    }
    piVar2 = param_1 + 0x1fc;
    if (iVar4 != 0) {
      piVar2 = aiStack_18;
    }
    iVar1 = (**(code **)(*param_1 + 0x98))(param_1,param_1[0x15],piVar2);
    if (iVar1 < 0) {
      return iVar1;
    }
    param_1[0x127] = 1;
    if (param_1[0x1f9] < 2) {
      *param_3 = 1;
    }
    else {
      if ((param_1[0x1f5] == 1) || ((short)param_1[500] != 0)) {
        param_1[0x1f2] = 1;
        *param_3 = param_1[0x1f9];
      }
      else {
        param_1[499] = 1;
        *param_3 = 1;
      }
      if ((param_1[0x1f2] == 1) || (param_1[499] == 1)) {
        param_1[6] = 0x26200a;
      }
      else {
        param_1[6] = 0x30803;
      }
    }
    param_1[0x119] = 1;
    param_1[0x11a] = param_1[0x1f9] * 4;
    if (param_1[0x11f] != 0) {
      param_1[0x119] = 2;
      param_1[0x11a] = param_1[0x11f] + param_1[0x1f9] * 4 + 1;
    }
    if (param_1[0x1f5] == 1) {
      param_1[0x119] = param_1[0x119] + 1;
      param_1[0x11a] = param_1[0x11a] + 2;
    }
    param_1[0x11b] = 1;
  }
  else {
    *param_3 = param_1[0x1f9];
  }
  return 0;
}



/* 4049b01c FUN_4049b01c */

/* Boundary evidence: original MIPS .pdata 4049b01c..4049b1ab. Semantic name remains unreviewed. */

int FUN_4049b01c(int *param_1,void *param_2,uint param_3)

{
  int iVar1;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [8];
  
  if ((param_1[0x1f9] != -1) ||
     (iVar1 = (**(code **)(*param_1 + 0x28))(param_1,&DAT_4048130c,auStack_28), -1 < iVar1)) {
    if (((param_1[499] == 1) && (1 < param_3)) ||
       (((uint)param_1[0x1f9] <= param_3 || (iVar1 = memcmp(param_2,&DAT_4048130c,0x10), iVar1 != 0)
        ))) {
      iVar1 = -0x7ff8ffa9;
    }
    else {
      if ((int)param_3 <= param_1[0x1fa]) {
        (**(code **)(*param_1 + 0x98))(param_1,param_1[0x15],param_1 + 0x1fc);
        param_1[0x1fa] = -1;
      }
      do {
        if ((int)param_3 <= param_1[0x1fa] + 1) {
          iVar1 = (**(code **)(*param_1 + 0x84))(param_1,param_1[0x15],auStack_20);
          if (iVar1 < 0) {
            return iVar1;
          }
          iVar1 = (**(code **)(*param_1 + 0x8c))(param_1);
          if (iVar1 < 0) {
            return iVar1;
          }
          iVar1 = (**(code **)(*param_1 + 0x98))(param_1,param_1[0x15],auStack_20);
          if (iVar1 < 0) {
            return iVar1;
          }
          return 0;
        }
        iVar1 = (**(code **)(*param_1 + 0x90))(param_1);
      } while (-1 < iVar1);
      iVar1 = -0x7784fff9;
    }
  }
  return iVar1;
}



/* 4049b1ac FUN_4049b1ac */

/* Boundary evidence: original MIPS .pdata 4049b1ac..4049b1d7. Semantic name remains unreviewed. */

void FUN_4049b1ac(int *param_1)

{
  (**(code **)(*param_1 + 0x88))(param_1,0,0,1);
  return;
}



/* 4049b1d8 FUN_4049b1d8 */

/* Boundary evidence: original MIPS .pdata 4049b1d8..4049b203. Semantic name remains unreviewed. */

void FUN_4049b1d8(int *param_1)

{
  (**(code **)(*param_1 + 0x88))(param_1,1,0,0);
  return;
}



/* 4049b204 FUN_4049b204 */

/* Boundary evidence: original MIPS .pdata 4049b204..4049b22f. Semantic name remains unreviewed. */

void FUN_4049b204(int *param_1)

{
  (**(code **)(*param_1 + 0x88))(param_1,1,0,1);
  return;
}



/* 4049b230 FUN_4049b230 */

/* Boundary evidence: original MIPS .pdata 4049b230..4049b2e7. Semantic name remains unreviewed. */

int FUN_4049b230(int param_1,int *param_2,int param_3)

{
  int iVar1;
  byte local_18 [8];
  
  if ((param_3 == 0) ||
     (iVar1 = FUN_4049035c(param_2,param_3,*(int *)(param_1 + 0x7b4)), -1 < iVar1)) {
    iVar1 = FUN_404901e4(param_2,(int)local_18,1,*(int *)(param_1 + 0x7b4),(int *)0x0);
    while (-1 < iVar1) {
      if (local_18[0] == 0) {
        return 0;
      }
      iVar1 = FUN_4049035c(param_2,(uint)local_18[0],*(int *)(param_1 + 0x7b4));
      if (iVar1 < 0) {
        return iVar1;
      }
      local_18[0] = 0;
      iVar1 = FUN_404901e4(param_2,(int)local_18,1,*(int *)(param_1 + 0x7b4),(int *)0x0);
    }
  }
  return iVar1;
}



/* 4049b2e8 FUN_4049b2e8 */

int FUN_4049b2e8(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_4 == 0) {
    iVar1 = param_2 << 3;
  }
  else if (param_4 == 1) {
    iVar1 = param_3 + -1;
    if (iVar1 < 0) {
      iVar1 = param_3 + 6;
    }
    iVar1 = (param_2 - (iVar1 >> 3)) * 8 + -4;
  }
  else if (param_4 == 2) {
    iVar1 = param_3 + -1;
    if (iVar1 < 0) {
      iVar1 = param_3 + 2;
    }
    iVar1 = (param_2 - (iVar1 >> 2)) * 4 + -2;
  }
  else if (param_4 == 3) {
    iVar1 = param_3 + -1;
    if (param_3 + -1 < 0) {
      iVar1 = param_3;
    }
    iVar1 = (param_2 - (iVar1 >> 1)) * 2 + -1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4049b394 FUN_4049b394 */

undefined4 FUN_4049b394(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_3 + -1;
  iVar2 = iVar3;
  if (iVar3 < 0) {
    iVar2 = param_3 + 6;
  }
  if (param_2 < (iVar2 >> 3) + 1) {
    uVar1 = 0;
  }
  else {
    iVar2 = iVar3;
    if (iVar3 < 0) {
      iVar2 = param_3 + 2;
    }
    if (param_2 < (iVar2 >> 2) + 1) {
      uVar1 = 1;
    }
    else {
      if (iVar3 < 0) {
        iVar3 = param_3;
      }
      uVar1 = 2;
      if ((iVar3 >> 1) + 1 <= param_2) {
        uVar1 = 3;
      }
    }
  }
  return uVar1;
}



/* 4049b414 FUN_4049b414 */

undefined4 FUN_4049b414(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 8;
  }
  else {
    uVar1 = 1;
    if (param_2 == 1) {
      uVar1 = 4;
    }
    else if (param_2 == 2) {
      uVar1 = 2;
    }
    else if (param_2 != 3) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4049b464 FUN_4049b464 */

/* Boundary evidence: original MIPS .pdata 4049b464..4049b5cb. Semantic name remains unreviewed. */

int FUN_4049b464(undefined4 param_1,int param_2,undefined4 *param_3,int param_4,int param_5,
                uint param_6,ushort param_7,undefined4 param_8,undefined4 param_9,uint param_10)

{
  int iVar1;
  uint _Size;
  
  if (param_2 < (int)(param_10 >> 0x10)) {
    iVar1 = (**(code **)*param_3)(param_3,(param_6 >> 0x10) + param_2);
    if (iVar1 < 0) {
      return iVar1;
    }
    *(undefined4 *)(param_4 + 0xc) = param_3[0x11e];
  }
  else {
    *(undefined4 *)(param_4 + 0xc) = param_3[0x120];
  }
  _Size = (uint)param_7;
  *(uint *)(param_4 + 0x10) = _Size;
  if (*(int *)(param_5 + 4) != 0) {
    if ((int)_Size < (int)*(size_t *)(param_5 + 0x10)) {
      memcpy(*(void **)(param_4 + 0xc),(void *)(*(int *)(param_5 + 8) + *(int *)(param_5 + 0xc)),
             _Size);
      *(uint *)(param_4 + 0xc) = *(int *)(param_4 + 0xc) + _Size;
      *(undefined4 *)(param_4 + 0x10) = 0;
      memcpy(*(void **)(param_5 + 8),
             (void *)((int)*(void **)(param_5 + 8) + _Size + *(int *)(param_5 + 0xc)),
             *(int *)(param_5 + 0x10) - _Size);
      *(undefined4 *)(param_5 + 0xc) = 0;
      *(uint *)(param_5 + 0x10) = *(int *)(param_5 + 0x10) - _Size;
    }
    else {
      memcpy(*(void **)(param_4 + 0xc),(void *)(*(int *)(param_5 + 0xc) + *(int *)(param_5 + 8)),
             *(size_t *)(param_5 + 0x10));
      *(int *)(param_4 + 0xc) = *(int *)(param_4 + 0xc) + *(int *)(param_5 + 0x10);
      *(int *)(param_4 + 0x10) = *(int *)(param_4 + 0x10) - *(int *)(param_5 + 0x10);
      *(undefined4 *)(param_5 + 4) = 0;
    }
  }
  *(undefined1 *)(param_4 + 0x15) = 0;
  return 0;
}



/* 4049b5cc FUN_4049b5cc */

/* Boundary evidence: original MIPS .pdata 4049b5cc..4049b677. Semantic name remains unreviewed. */

int FUN_4049b5cc(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  byte local_20 [8];
  
  iVar1 = FUN_404901e4(*(int **)(param_1 + 0x54),(int)local_20,1,*(int *)(param_1 + 0x7b4),
                       (int *)0x0);
  if (-1 < iVar1) {
    if (local_20[0] == 0) {
      *param_4 = 0;
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_404901e4(*(int **)(param_1 + 0x54),param_3,(uint)local_20[0],
                           *(int *)(param_1 + 0x7b4),(int *)0x0);
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar2 = (uint)local_20[0];
      *(int *)(param_2 + 4) = param_3;
    }
    *(undefined1 *)(param_2 + 0x14) = 0;
    iVar1 = 0;
    *(uint *)(param_2 + 8) = uVar2;
  }
  return iVar1;
}



/* 4049b678 FUN_4049b678 */

/* Boundary evidence: original MIPS .pdata 4049b678..4049b73f. Semantic name remains unreviewed. */

void FUN_4049b678(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_18;
  undefined1 local_14;
  
  iVar1 = FUN_404901e4(*(int **)(param_1 + 0x54),(int)&local_18,5,*(int *)(param_1 + 0x7b4),
                       (int *)0x0);
  if (local_18._2_2_ != 0) {
    *(short *)(param_1 + 2000) = local_18._2_2_;
  }
  *(undefined4 *)(param_1 + 0x7a4) = local_18;
  *(undefined1 *)(param_1 + 0x7a8) = local_14;
  if ((*(byte *)(param_1 + 0x7a5) & 1) != 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 2;
  }
  if (param_2 != 0) {
    if (-1 < iVar1) {
      *(undefined4 *)(param_1 + 0x7b8) = 1;
    }
    if ((*(int *)(param_1 + 0x7ac) != 0) && ((*(byte *)(param_1 + 0x7a5) & 1) != 0)) {
      *(undefined1 *)(*(int *)(param_1 + 0x7ac) + 0x10) = *(undefined1 *)(param_1 + 0x7a8);
    }
  }
  return;
}



/* 4049b740 FUN_4049b740 */

/* Boundary evidence: original MIPS .pdata 4049b740..4049b883. Semantic name remains unreviewed. */

int FUN_4049b740(int *param_1)

{
  int iVar1;
  void *_Src;
  LPVOID pvVar2;
  byte local_18 [8];
  
  if (param_1[0x11b] == 1) {
    iVar1 = (**(code **)(*param_1 + 0x9c))(param_1,param_1[0x15],0);
  }
  else {
    iVar1 = FUN_404901e4((int *)param_1[0x15],(int)local_18,1,param_1[0x1ed],(int *)0x0);
    while (-1 < iVar1) {
      if (local_18[0] == 0) {
        return 0;
      }
      _Src = (void *)FUN_404962c4((uint)local_18[0]);
      if (_Src == (void *)0x0) {
        return -0x7ff8fff2;
      }
      iVar1 = FUN_404901e4((int *)param_1[0x15],(int)_Src,(uint)local_18[0],param_1[0x1ed],
                           (int *)0x0);
      if (iVar1 < 0) {
        return iVar1;
      }
      pvVar2 = FUN_4049631c((LPVOID)param_1[0x11e],(uint)local_18[0] + param_1[0x11f]);
      if (pvVar2 == (LPVOID)0x0) {
        return -0x7ff8fff2;
      }
      param_1[0x11e] = (int)pvVar2;
      memcpy((void *)(param_1[0x11f] + (int)pvVar2),_Src,(uint)local_18[0]);
      param_1[0x11f] = (uint)local_18[0] + param_1[0x11f];
      FUN_404962ec(_Src);
      local_18[0] = 0;
      iVar1 = FUN_404901e4((int *)param_1[0x15],(int)local_18,1,param_1[0x1ed],(int *)0x0);
    }
  }
  return iVar1;
}



/* 4049b884 FUN_4049b884 */

/* Boundary evidence: original MIPS .pdata 4049b884..4049b8ab. Semantic name remains unreviewed. */

void FUN_4049b884(int *param_1)

{
  (**(code **)(*param_1 + 0x9c))(param_1,param_1[0x15],0xd);
  return;
}



/* 4049b8ac FUN_4049b8ac */

/* Boundary evidence: original MIPS .pdata 4049b8ac..4049ba6f. Semantic name remains unreviewed. */

int FUN_4049b8ac(int *param_1)

{
  int iVar1;
  void *_Buf1;
  byte local_20;
  char local_1f [7];
  
  iVar1 = FUN_404901e4((int *)param_1[0x15],(int)&local_20,1,param_1[0x1ed],(int *)0x0);
  if (iVar1 < 0) {
    return iVar1;
  }
  _Buf1 = (void *)FUN_404962c4((uint)local_20);
  if (_Buf1 == (void *)0x0) {
    return -0x7ff8fff2;
  }
  iVar1 = FUN_404901e4((int *)param_1[0x15],(int)_Buf1,(uint)local_20,param_1[0x1ed],(int *)0x0);
  if (iVar1 < 0) goto LAB_4049b99c;
  iVar1 = memcmp(_Buf1,"NETSCAPE2.0",0xb);
  if ((iVar1 == 0) || (iVar1 = memcmp(_Buf1,"ANIMEXTS1.0",0xb), iVar1 == 0)) {
    iVar1 = FUN_404901e4((int *)param_1[0x15],(int)&local_20,1,param_1[0x1ed],(int *)0x0);
    if (iVar1 < 0) goto LAB_4049b99c;
    if (local_20 != 0) {
      iVar1 = FUN_404901e4((int *)param_1[0x15],(int)local_1f,1,param_1[0x1ed],(int *)0x0);
      if (iVar1 < 0) goto LAB_4049b99c;
      if (local_1f[0] != '\x01') {
        FUN_404962ec(_Buf1);
        iVar1 = (**(code **)(*param_1 + 0x9c))(param_1,param_1[0x15],0xfe);
        return iVar1;
      }
      param_1[0x1f5] = 1;
      iVar1 = FUN_404901e4((int *)param_1[0x15],(int)(param_1 + 0x1f6),2,param_1[0x1ed],(int *)0x0);
      goto LAB_4049b988;
    }
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x9c))(param_1,param_1[0x15],0);
LAB_4049b988:
    if (iVar1 < 0) goto LAB_4049b99c;
  }
  iVar1 = 0;
LAB_4049b99c:
  FUN_404962ec(_Buf1);
  return iVar1;
}



/* 4049ba70 FUN_4049ba70 */

/* Boundary evidence: original MIPS .pdata 4049ba70..4049bad3. Semantic name remains unreviewed. */

int FUN_4049ba70(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = (**(code **)(*param_2 + 0x14))(param_2,param_2,0,0,1,&local_10);
  if (-1 < iVar1) {
    iVar1 = 0;
    *param_3 = local_10;
    param_3[1] = local_c;
  }
  return iVar1;
}



/* 4049bad4 FUN_4049bad4 */

/* Boundary evidence: original MIPS .pdata 4049bad4..4049bb17. Semantic name remains unreviewed. */

int FUN_4049bad4(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x14))(param_2,param_2,*param_3,param_3[1],0,0);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4049bb18 FUN_4049bb18 */

/* Boundary evidence: original MIPS .pdata 4049bb18..4049bc0b. Semantic name remains unreviewed. */

byte * FUN_4049bb18(byte *param_1,uint param_2)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  
  param_1[1] = (byte)param_2 + 1;
  *param_1 = (byte)param_2;
  *(short *)(param_1 + 2) = (short)(1 << (param_2 & 0x1f)) + 1;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 1;
  param_1[0x15] = 1;
  param_1[0x18] = 0;
  uVar1 = 1 << (*param_1 & 0x1f) & 0xffff;
  uVar3 = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  *(uint *)(param_1 + 0x24) = uVar1;
  if (uVar1 != 0) {
    pbVar2 = param_1 + 0x28;
    do {
      *(uint *)pbVar2 = (uVar3 & 0xff) + 0x100000;
      uVar3 = uVar3 + 1;
      pbVar2 = pbVar2 + 4;
    } while ((int)uVar3 < (int)(1 << (*param_1 & 0x1f) & 0xffffU));
  }
  uVar1 = 1 << (*param_1 & 0x1f);
  uVar3 = uVar1 & 0xffff;
  param_1[1] = *param_1 + 1;
  *(short *)(param_1 + 2) = (short)uVar1 + 1;
  memset(param_1 + (uVar3 + 10) * 4,0,(0x1000 - uVar3) * 4);
  return param_1;
}



/* 4049bc0c FUN_4049bc0c */

/* Boundary evidence: original MIPS .pdata 4049bc0c..4049bcbf. Semantic name remains unreviewed. */

undefined4 FUN_4049bc0c(int param_1)

{
  undefined4 uVar1;
  LPVOID pvVar2;
  
  if (*(int *)(param_1 + 0x50) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    if (*(int **)(param_1 + 0x54) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x54) + 8))();
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    pvVar2 = *(LPVOID *)(param_1 + 0x7ac);
    if (pvVar2 != (LPVOID)0x0) {
      FUN_404a8be8((int)pvVar2);
      FUN_404962ec(pvVar2);
    }
    if (*(LPVOID *)(param_1 + 0x470) != (LPVOID)0x0) {
      FUN_404962ec(*(LPVOID *)(param_1 + 0x470));
      *(undefined4 *)(param_1 + 0x470) = 0;
    }
    if (*(LPVOID *)(param_1 + 0x478) != (LPVOID)0x0) {
      FUN_404962ec(*(LPVOID *)(param_1 + 0x478));
      *(undefined4 *)(param_1 + 0x478) = 0;
    }
    *(undefined4 *)(param_1 + 0x50) = 0;
    uVar1 = 0;
  }
  return uVar1;
}



/* 4049bcc0 FUN_4049bcc0 */

/* Boundary evidence: original MIPS .pdata 4049bcc0..4049bfb7. Semantic name remains unreviewed. */

int FUN_4049bcc0(int *param_1)

{
  int iVar1;
  HDC hdc;
  int iVar2;
  undefined4 uVar3;
  int *_Buf1;
  undefined8 uVar4;
  undefined8 uVar5;
  
  if (param_1[0x1ef] != 0) {
    return 0;
  }
  _Buf1 = param_1 + 0x121;
  iVar1 = FUN_404901e4((int *)param_1[0x15],(int)_Buf1,0xd,param_1[0x1ed],(int *)0x0);
  if (iVar1 < 0) {
    return iVar1;
  }
  param_1[2] = -0x4694c350;
  param_1[3] = 0x11d30728;
  param_1[4] = 0x7b9d;
  param_1[6] = 0x30803;
  param_1[5] = 0x2ef31ef8;
  param_1[7] = (uint)CONCAT11(*(undefined1 *)((int)param_1 + 0x48b),
                              *(undefined1 *)((int)param_1 + 0x48a));
  param_1[8] = (uint)*(ushort *)(param_1 + 0x123);
  if (*(byte *)(param_1 + 0x124) == 0) {
    uVar4 = 0x3ff0000000000000;
  }
  else {
    uVar4 = __litodp(*(byte *)(param_1 + 0x124) + 0xf);
    uVar4 = __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x3f900000);
  }
  hdc = GetDC((HWND)0x0);
  if (hdc != (HDC)0x0) {
    iVar2 = GetDeviceCaps(hdc,0x58);
    uVar3 = __litofp(iVar2);
    uVar5 = __fptodp(uVar3);
    *(undefined8 *)(param_1 + 0xc) = uVar5;
    iVar2 = __led((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0);
    if (iVar2 == 0) {
      iVar2 = GetDeviceCaps(hdc,0x5a);
      uVar3 = __litofp(iVar2);
      uVar5 = __fptodp(uVar3);
      *(undefined8 *)(param_1 + 0xe) = uVar5;
      iVar2 = __led((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0);
      if (iVar2 == 0) goto LAB_4049be64;
    }
  }
  param_1[0xc] = 0;
  param_1[0xd] = 0x40580000;
  param_1[0xe] = 0;
  param_1[0xf] = 0x40580000;
LAB_4049be64:
  ReleaseDC((HWND)0x0,hdc);
  uVar4 = __dpdiv(param_1[0xc],param_1[0xd],(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
  param_1[0x10] = 0x1c2010;
  *(undefined8 *)(param_1 + 0xc) = uVar4;
  param_1[9] = (uint)CONCAT11(*(undefined1 *)((int)param_1 + 0x48b),
                              *(undefined1 *)((int)param_1 + 0x48a));
  param_1[10] = 1;
  iVar2 = memcmp(_Buf1,"GIF87a",6);
  if ((iVar2 == 0) || (iVar2 = memcmp(_Buf1,"GIF89a",6), iVar2 == 0)) {
    if ((*(byte *)((int)param_1 + 0x48e) & 0x80) != 0) {
      iVar1 = 1 << (*(byte *)((int)param_1 + 0x48e) & 7) + 1;
      param_1[0x1f8] = iVar1;
      iVar1 = FUN_404901e4((int *)param_1[0x15],(int)(param_1 + 0x129),iVar1 * 3,param_1[0x1ed],
                           (int *)0x0);
      if (iVar1 < 0) {
        return iVar1;
      }
      FUN_4049a4d0((int)param_1,(int)(param_1 + 0x129),(undefined4 *)param_1[0x118],param_1[0x1f8]);
    }
    (**(code **)(*param_1 + 0x84))(param_1,param_1[0x15],param_1 + 0x1fc);
    param_1[0x1ef] = 1;
    param_1[0x1fa] = -1;
  }
  else {
    iVar1 = -0x7fffbffb;
  }
  return iVar1;
}



/* 4049bfb8 FUN_4049bfb8 */

/* Boundary evidence: original MIPS .pdata 4049bfb8..4049c007. Semantic name remains unreviewed. */

void FUN_4049bfb8(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_404a9478(puVar1);
    FUN_404962ec(puVar1);
  }
  *param_1 = param_2;
  return;
}



/* 4049c008 FUN_4049c008 */

/* Boundary evidence: original MIPS .pdata 4049c008..4049c067. Semantic name remains unreviewed. */

void FUN_4049c008(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_404962ec((LPVOID)puVar1[2]);
    puVar1[2] = 0;
    *puVar1 = 0x4c494146;
    FUN_404962ec(puVar1);
  }
  *param_1 = param_2;
  return;
}



/* 4049c068 FUN_4049c068 */

undefined4 * FUN_4049c068(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40484aa8;
  param_1[0x1f9] = 0xffffffff;
  param_1[0x1fa] = 0xffffffff;
  param_1[0x1ff] = 1;
  param_1[0x15] = 0;
  param_1[0x120] = 0;
  param_1[0x13] = 0;
  param_1[0x1eb] = 0;
  param_1[0x1f2] = 0;
  param_1[499] = 0;
  *(undefined2 *)(param_1 + 500) = 0;
  param_1[0x1f5] = 0;
  param_1[0x1f7] = 1;
  param_1[0x1f0] = 1;
  param_1[0x118] = param_1 + 0x16;
  param_1[0x1f8] = 0;
  param_1[0x14] = 0;
  return param_1;
}



/* 4049c0c8 FUN_4049c0c8 */

/* Boundary evidence: original MIPS .pdata 4049c0c8..4049c0fb. Semantic name remains unreviewed. */

void FUN_4049c0c8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40484aa8;
  if (param_1[0x14] != 0) {
    FUN_4049bc0c((int)param_1);
  }
  return;
}



/* 4049c0fc FUN_4049c0fc */

/* Boundary evidence: original MIPS .pdata 4049c0fc..4049c15b. Semantic name remains unreviewed. */

undefined4 * FUN_4049c0fc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40484aa8;
  if (param_1[0x14] != 0) {
    FUN_4049bc0c((int)param_1);
  }
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 4049c15c FUN_4049c15c */

/* Boundary evidence: original MIPS .pdata 4049c15c..4049d17f. Semantic name remains unreviewed. */

int FUN_4049c15c(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int *piVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  size_t _Size;
  undefined1 uVar13;
  undefined4 uVar14;
  byte bVar15;
  undefined1 uVar16;
  uint uVar17;
  uint uVar18;
  int *piVar19;
  undefined4 uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  uint local_5e0;
  undefined4 local_5dc;
  byte local_5d8;
  undefined4 local_5d0;
  undefined4 local_5cc;
  byte local_5c7 [3];
  int local_5c4;
  int *local_5c0;
  byte local_5bc;
  int *local_5b8;
  int local_5b4;
  uint local_5b0;
  int local_5ac;
  int local_5a8;
  int local_5a4;
  int local_5a0;
  undefined4 local_59c;
  uint local_598;
  uint local_594;
  uint local_590;
  uint local_58c;
  undefined4 local_588;
  int local_584;
  uint local_580;
  undefined1 auStack_578 [16];
  int local_568;
  uint local_540;
  undefined1 auStack_538 [256];
  undefined1 auStack_438 [4];
  int local_434;
  uint local_30;
  
  local_30 = DAT_404bd274;
  memcpy(auStack_578,&stack0x00000010,0x40);
  iVar7 = FUN_404901e4((int *)param_1[0x15],(int)&local_5e0,9,param_1[0x1ed],(int *)0x0);
  if (iVar7 < 0) goto LAB_4049c1d4;
  uVar5 = local_5dc._3_1_;
  uVar17 = (uint)local_5dc._2_2_;
  uVar4 = local_5dc._1_1_;
  uVar13 = (undefined1)local_5dc;
  uVar22 = local_5dc & 0xffff;
  uVar16 = (undefined1)(local_5dc >> 0x10);
  if ((param_1[7] == 0) || (param_1[8] == 0)) {
    param_1[7] = uVar22;
    param_1[8] = uVar17;
    *(undefined1 *)((int)param_1 + 0x48a) = uVar13;
    *(undefined1 *)((int)param_1 + 0x48b) = uVar4;
    *(undefined1 *)(param_1 + 0x123) = uVar16;
    *(undefined1 *)((int)param_1 + 0x48d) = uVar5;
  }
  if (0x7fff < *(ushort *)(param_1 + 0x123)) {
    *(undefined1 *)(param_1 + 0x123) = uVar16;
    *(undefined1 *)((int)param_1 + 0x48d) = uVar5;
    param_1[8] = uVar17;
  }
  if (0x7fff < *(ushort *)((int)param_1 + 0x48a)) {
    *(undefined1 *)((int)param_1 + 0x48a) = uVar13;
    *(undefined1 *)((int)param_1 + 0x48b) = uVar4;
    param_1[7] = uVar22;
  }
  local_5d0 = local_5e0;
  local_5cc = local_5dc;
  uVar2 = (ushort)(local_5e0 >> 0x10);
  uVar23 = (uint)uVar2;
  uVar12 = local_5e0 & 0xffff;
  local_5bc = local_5d8;
  if ((param_1[0x125] == 0) && (param_1[0x1fa] == -1)) {
    *(short *)(param_1 + 0x126) = (short)local_5e0 + (short)local_5dc;
    *(ushort *)((int)param_1 + 0x49a) = uVar2 + local_5dc._2_2_;
    param_1[0x125] = 1;
  }
  if (param_1[0x127] == 0) {
    if ((uint)*(ushort *)(param_1 + 0x128) < uVar12 + uVar22) {
      *(short *)(param_1 + 0x128) = (short)local_5e0 + (short)local_5dc;
    }
    if ((uint)*(ushort *)((int)param_1 + 0x4a2) < uVar23 + uVar17) {
      *(ushort *)((int)param_1 + 0x4a2) = uVar2 + local_5dc._2_2_;
    }
  }
  uVar3 = *(ushort *)(param_1 + 0x123);
  uVar18 = (uint)uVar3;
  if (uVar18 < uVar23 + uVar17) {
    if (uVar18 < uVar23) {
      uVar17 = 0;
      local_5cc._0_3_ = (uint3)local_5dc & 0xffff;
      local_5cc = (uint)(uint3)local_5cc;
      local_5d0 = CONCAT13((char)(uVar3 >> 8),CONCAT12((char)uVar3,(short)local_5e0));
    }
    else {
      uVar17 = uVar18 - uVar23 & 0xffff;
      local_5cc._0_3_ = CONCAT12((char)uVar17,(short)local_5dc);
      local_5cc = CONCAT13((char)(uVar17 >> 8),(uint3)local_5cc);
      uVar18 = (uint)uVar2;
    }
  }
  else {
    uVar17 = (uint)local_5dc._2_2_;
    uVar18 = (uint)uVar2;
  }
  uVar23 = (uint)*(ushort *)((int)param_1 + 0x48a);
  if (uVar23 < uVar12 + uVar22) {
    if (uVar23 < uVar12) {
      uVar22 = 0;
      local_5cc = (uint)local_5cc._2_2_ << 0x10;
      local_5d0 = CONCAT22(local_5d0._2_2_,*(ushort *)((int)param_1 + 0x48a));
    }
    else {
      uVar22 = uVar23 - uVar12 & 0xffff;
      local_5cc._0_2_ = (undefined2)(uVar23 - uVar12);
    }
  }
  else {
    uVar22 = local_5cc & 0xffff;
  }
  if ((local_5d8 & 0x40) == 0) {
    iVar21 = 1;
  }
  else if ((local_540 & 0x80000) == 0) {
    iVar21 = 2;
    if ((local_540 & 0x10000) != 0) goto LAB_4049c510;
  }
  else if ((param_1[0x1f2] == 0) && (param_1[499] == 0)) {
    iVar21 = 4;
  }
  else {
LAB_4049c510:
    iVar21 = 3;
  }
  bVar1 = (local_5d8 & 0x80) != 0;
  local_434 = 0;
  if (bVar1) {
    local_434 = 1 << (local_5d8 & 7) + 1;
  }
  local_5b4 = iVar21;
  iVar7 = (**(code **)(*param_1 + 0x6c))(param_1,bVar1,auStack_438);
  if (iVar7 < 0) goto LAB_4049c1d4;
  if (param_2 == 0) {
    iVar7 = (**(code **)(*param_1 + 0x9c))(param_1,param_1[0x15],1);
    FUN_404a438c(local_30);
    if (-1 < iVar7) {
      return 0;
    }
    return iVar7;
  }
  if (((param_3 != 0) &&
      (iVar7 = (**(code **)(*(int *)param_1[0x120] + 0x14))((int *)param_1[0x120],auStack_438),
      iVar7 < 0)) ||
     (iVar7 = FUN_404901e4((int *)param_1[0x15],(int)local_5c7,1,param_1[0x1ed],(int *)0x0),
     iVar7 < 0)) goto LAB_4049c1d4;
  if ((local_5c7[0] < 2) || (8 < local_5c7[0])) {
    FUN_404a438c(local_30);
    return -0x7fffbffb;
  }
  pbVar8 = (byte *)FUN_404962c4(0x4028);
  if (pbVar8 == (byte *)0x0) {
    pbVar8 = (byte *)0x0;
  }
  else {
    pbVar8 = FUN_4049bb18(pbVar8,(uint)local_5c7[0]);
  }
  FUN_404962ec((LPVOID)0x0);
  if (pbVar8 == (byte *)0x0) {
    FUN_404962ec((LPVOID)0x0);
    FUN_404a438c(local_30);
    return -0x7ff8fff2;
  }
  local_580 = local_5e0 & 0xffff;
  local_590 = local_5e0 >> 0x10;
  local_584 = (local_5dc & 0xffff) + local_580;
  local_5a8 = (local_5dc >> 0x10) + local_590;
  local_594 = (uint)*(ushort *)((int)param_1 + 0x48a);
  local_5c0 = (int *)(local_5d0 & 0xffff);
  local_58c = (uint)*(ushort *)(param_1 + 0x123);
  local_5c4 = uVar22 + (int)local_5c0;
  local_5a4 = uVar17 + uVar18;
  local_588 = 0;
  local_59c = 0;
  if ((param_1[0x1ee] == 0) || (param_1[0x1eb] == 0)) {
    bVar15 = 0;
  }
  else {
    bVar15 = *(byte *)((int)param_1 + 0x7a5) >> 2 & 7;
  }
  if ((((param_1[0x1f2] == 0) && (param_1[499] == 0)) || (param_1[0x1ee] == 0)) ||
     (uVar20 = 1, (*(byte *)((int)param_1 + 0x7a5) & 1) == 0)) {
    uVar20 = 0;
  }
  local_5b8 = (int *)0x0;
  local_5b0 = uVar18;
  local_598 = uVar17;
  puVar9 = (undefined4 *)FUN_404962c4(0x498);
  uVar17 = local_5b0;
  local_5a0 = local_568;
  if (puVar9 == (undefined4 *)0x0) {
    puVar9 = (undefined4 *)0x0;
  }
  else {
    if ((bVar1) || ((param_1[0x1ee] != 0 && ((*(byte *)((int)param_1 + 0x7a5) & 1) != 0)))) {
      iVar7 = 1;
    }
    else {
      iVar7 = 0;
    }
    if (((iVar21 != 1) && (iVar21 != 2)) || (uVar14 = 1, param_3 == 0)) {
      uVar14 = 0;
    }
    puVar9 = FUN_404a91b8(puVar9,param_1[0x120],local_580,local_590,local_584,local_5a8,local_588,
                          local_59c,local_594,local_58c,local_5c0,local_5b0,local_5c4,local_5a4,
                          uVar14,local_568,auStack_438,iVar7,(undefined4 *)param_1[0x1eb],param_3,
                          uVar20,(char)param_1[0x1ea],bVar15);
  }
  FUN_4049bfb8(&local_5b8,puVar9);
  piVar6 = local_5b8;
  if (local_5b8 == (int *)0x0) {
LAB_4049ca5c:
    iVar7 = -0x7ff8fff2;
  }
  else if (local_5b8[1] == 0x42664731) {
    if ((param_1[0x1eb] != 0) && (param_1[0x1fa] == -1)) {
      FUN_404a909c(param_1[0x1eb]);
    }
    if (((local_5d8 & 0x80) != 0) && ((int *)param_1[0x1eb] != (int *)0x0)) {
      local_5a0 = *(int *)param_1[0x1eb];
    }
    if (param_1[0x1fa] == -1) {
      local_5c4 = 1;
      if (uVar18 != 0) {
        uVar13 = *(undefined1 *)((int)param_1 + 0x48f);
        if ((param_1[0x1ee] != 0) && ((*(byte *)((int)param_1 + 0x7a5) & 1) != 0)) {
          uVar13 = (undefined1)param_1[0x1ea];
        }
        iVar7 = (**(code **)(*piVar6 + 0xc))(piVar6,0,uVar17 - 1,uVar13);
        if (iVar7 < 0) goto LAB_4049d0d0;
      }
LAB_4049c9ec:
      piVar19 = (int *)((local_5dc & 0xffff) + 0x400);
      local_5c0 = (int *)0x0;
      local_5b8 = piVar19;
      puVar9 = (undefined4 *)FUN_404962c4(0x18);
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        puVar9 = FUN_40499ad0(puVar9,(SIZE_T)piVar19);
      }
      FUN_4049c008(&local_5c0,puVar9);
      piVar19 = local_5c0;
      if (local_5c0 != (int *)0x0) {
        if (*local_5c0 == 0x4f664731) {
          local_5ac = 1;
          iVar24 = 0;
          do {
            if (((local_5ac != 1) && (piVar19[1] == 0)) ||
               (uVar17 = local_5dc >> 0x10, (int)uVar17 <= iVar24)) {
              if ((local_5c4 == 1) && (local_5a4 < (int)(uint)*(ushort *)(param_1 + 0x123))) {
                uVar13 = *(undefined1 *)((int)param_1 + 0x48f);
                if ((param_1[0x1ee] != 0) && ((*(byte *)((int)param_1 + 0x7a5) & 1) != 0)) {
                  uVar13 = (undefined1)param_1[0x1ea];
                }
                iVar7 = (**(code **)(*piVar6 + 0xc))
                                  (piVar6,local_5a4,*(ushort *)(param_1 + 0x123) - 1,uVar13);
joined_r0x4049d088:
                if (iVar7 < 0) break;
              }
              else if (local_5a4 < (int)(uint)*(ushort *)(param_1 + 0x123)) {
                iVar7 = (**(code **)(*piVar6 + 0x10))
                                  (piVar6,local_5a4,*(ushort *)(param_1 + 0x123) - 1);
                goto joined_r0x4049d088;
              }
              iVar7 = (**(code **)(*piVar6 + 8))(piVar6,1);
              if (-1 < iVar7) {
                param_1[0x1ee] = 0;
                FUN_404962ec((LPVOID)piVar19[2]);
                piVar19[2] = 0;
                *piVar19 = 0x4c494146;
                FUN_404962ec(piVar19);
                FUN_404a9478(piVar6);
                FUN_404962ec(piVar6);
                FUN_404962ec(pbVar8);
                FUN_404a438c(local_30);
                return 0;
              }
              break;
            }
            local_5c0 = (int *)FUN_4049b394(param_1,iVar24,uVar17);
            iVar10 = iVar24;
            if (iVar21 != 1) {
              iVar10 = FUN_4049b2e8(param_1,iVar24,uVar17,(int)local_5c0);
            }
            bVar1 = (int)local_598 <= iVar10;
            if ((pbVar8[0x15] == 1) &&
               (iVar7 = (**(code **)(*param_1 + 0x60))
                                  (param_1,iVar10,piVar6,pbVar8,piVar19,local_5e0,local_5dc,
                                   local_5d8,local_5d0,local_5cc,local_5bc,local_5c4), iVar7 < 0))
            break;
            if (*(int *)(pbVar8 + 0xc) == 0) goto LAB_4049ca7c;
            if ((pbVar8[0x14] == 1) &&
               ((iVar7 = (**(code **)(*param_1 + 100))(param_1,pbVar8,auStack_538,&local_5ac),
                iVar7 < 0 || (*(int *)(pbVar8 + 8) == 0)))) {
              local_5ac = 0;
              if (!bVar1) {
                if (local_5a0 == 0x26200a) {
                  FUN_404a9d74((int)piVar6);
                }
                uVar13 = *(undefined1 *)((int)param_1 + 0x48f);
                if ((param_1[0x1ee] != 0) && ((*(byte *)((int)param_1 + 0x7a5) & 1) != 0)) {
                  uVar13 = (undefined1)param_1[0x1ea];
                }
                (**(code **)(*piVar6 + 4))(piVar6,local_5c4,uVar13,local_5b0 + iVar10,0,0);
              }
              iVar7 = (**(code **)(*piVar6 + 0x10))
                                (piVar6,local_5b0 + iVar10 + 1,*(ushort *)(param_1 + 0x123) - 1);
              if (-1 < iVar7) {
                iVar7 = (**(code **)(*piVar6 + 8))(piVar6,1);
              }
              break;
            }
            if ((pbVar8[0x19] == 0) && (pbVar8[0x1a] == 0)) {
              iVar7 = FUN_404a9e58(pbVar8);
            }
            else {
              iVar7 = 0;
            }
            piVar11 = local_5b8;
            if (iVar7 == 0) {
              local_5ac = 0;
            }
            iVar7 = *(int *)(pbVar8 + 0x10);
            if ((iVar7 == 0) || ((piVar19[1] == 1 && (0 < (int)local_5b8 + (-iVar7 - piVar19[3])))))
            {
              pbVar8[0x15] = 1;
              if (piVar19[1] == 1) {
                _Size = piVar19[3];
                if (_Size == 0) {
                  *(int *)(pbVar8 + 0xc) = piVar19[2] + piVar19[4];
                  *(int *)(pbVar8 + 0x10) = (int)local_5b8 - piVar19[4];
                }
                else {
                  if (bVar1) {
                    iVar7 = piVar6[0x120];
                  }
                  else {
                    iVar7 = piVar6[0x11e];
                  }
                  memcpy((void *)(((local_5dc & 0xffff) - _Size) + iVar7),(void *)piVar19[2],_Size);
                  piVar19[4] = (int)piVar11 + (-*(int *)(pbVar8 + 0x10) - piVar19[3]);
                }
              }
              if (iVar21 == 4) {
                if (!bVar1) {
                  iVar21 = 0;
                  local_5a8 = FUN_4049b414(param_1,(int)local_5c0);
                  local_5a8 = local_5a8 + -1;
                  if (0 < local_5a8) {
                    do {
                      iVar7 = (**(code **)(*piVar6 + 0x14))(piVar6);
                      if (iVar7 < 0) goto LAB_4049d0b0;
                      iVar21 = iVar21 + 1;
                    } while (iVar21 < local_5a8);
                    goto LAB_4049cde4;
                  }
                  goto LAB_4049cdec;
                }
              }
              else {
LAB_4049cde4:
                if (!bVar1) {
LAB_4049cdec:
                  if (local_5a0 == 0x26200a) {
                    FUN_404a9d74((int)piVar6);
                  }
                  uVar13 = *(undefined1 *)((int)param_1 + 0x48f);
                  if ((param_1[0x1ee] != 0) && ((*(byte *)((int)param_1 + 0x7a5) & 1) != 0)) {
                    uVar13 = (undefined1)param_1[0x1ea];
                  }
                  iVar7 = (**(code **)(*piVar6 + 4))(piVar6,local_5c4,uVar13,local_5b0 + iVar10,0,0)
                  ;
                  if (iVar7 < 0) break;
                }
              }
              iVar24 = iVar24 + 1;
              iVar21 = local_5b4;
            }
            else if (pbVar8[0x15] != 0) {
              if (piVar19[1] != 0) {
                FUN_404962ec((LPVOID)piVar19[2]);
                piVar19[2] = 0;
                *piVar19 = 0x4c494146;
                FUN_404962ec(piVar19);
                goto LAB_4049c8f0;
              }
              piVar19[3] = iVar7;
              *(int *)(pbVar8 + 0xc) = piVar19[2];
              *(int **)(pbVar8 + 0x10) = local_5b8;
              piVar19[1] = 1;
              pbVar8[0x15] = 0;
            }
          } while ((((iVar21 != 4) ||
                    (piVar11 = (int *)FUN_4049b394(param_1,iVar24,local_5dc >> 0x10),
                    local_5c0 == piVar11)) || (bVar1)) ||
                  (iVar7 = (**(code **)(*piVar6 + 8))(piVar6,0), -1 < iVar7));
LAB_4049d0b0:
          FUN_404962ec((LPVOID)piVar19[2]);
          piVar19[2] = 0;
          *piVar19 = 0x4c494146;
          FUN_404962ec(piVar19);
          goto LAB_4049d0d0;
        }
LAB_4049ca7c:
        FUN_404962ec((LPVOID)piVar19[2]);
        piVar19[2] = 0;
        *piVar19 = 0x4c494146;
        FUN_404962ec(piVar19);
      }
      FUN_404a9478(piVar6);
      FUN_404962ec(piVar6);
      goto LAB_4049ca5c;
    }
    local_5c4 = 0;
    if ((uVar18 == 0) || (iVar7 = (**(code **)(*piVar6 + 0x10))(piVar6,0,uVar17 - 1), -1 < iVar7))
    goto LAB_4049c9ec;
LAB_4049d0d0:
    FUN_404a9478(piVar6);
    FUN_404962ec(piVar6);
  }
  else {
LAB_4049c8f0:
    FUN_404a9478(piVar6);
    FUN_404962ec(piVar6);
    iVar7 = -0x7fffbffb;
  }
  FUN_404962ec(pbVar8);
LAB_4049c1d4:
  FUN_404a438c(local_30);
  return iVar7;
}



/* 4049d180 FUN_4049d180 */

/* Boundary evidence: original MIPS .pdata 4049d180..4049d1db. Semantic name remains unreviewed. */

void FUN_4049d180(void)

{
  HRESULT HVar1;
  int iVar2;
  uint uVar3;
  
  HVar1 = DllCanUnloadNow();
  uVar3 = 2;
  if (HVar1 == 0) {
    uVar3 = 0;
  }
  iVar2 = FUN_404a3c98();
  DAT_404bd228 = iVar2 != 0 | uVar3 | DAT_404bd228;
  return;
}



/* 4049d1dc FUN_4049d1dc */

/* Boundary evidence: original MIPS .pdata 4049d1dc..4049d247. Semantic name remains unreviewed. */

undefined4 * FUN_4049d1dc(undefined4 *param_1)

{
  FUN_404a1ebc(param_1);
  FUN_404a3e48(param_1 + 0xd6);
  *param_1 = &PTR_FUN_40484bcc;
  param_1[0xd6] = &PTR_LAB_40484ba0;
  param_1[0xd7] = &PTR_LAB_40484b64;
  param_1[0x1be] = 1;
  return param_1;
}



/* 4049d294 FUN_4049d294 */

/* Boundary evidence: original MIPS .pdata 4049d294..4049d2e7. Semantic name remains unreviewed. */

void FUN_4049d294(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40484bcc;
  param_1[0xd6] = &PTR_LAB_40484ba0;
  param_1[0xd7] = &PTR_LAB_40484b64;
  FUN_404a3de0(param_1 + 0xd6);
  FUN_404a1f38(param_1);
  return;
}



/* 4049d2e8 FUN_4049d2e8 */

/* Boundary evidence: original MIPS .pdata 4049d2e8..4049d303. Semantic name remains unreviewed. */

void FUN_4049d2e8(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x6f8));
  return;
}



/* 4049d304 FUN_4049d304 */

/* Boundary evidence: original MIPS .pdata 4049d304..4049d35f. Semantic name remains unreviewed. */

LONG FUN_4049d304(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0x1be);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x94))(param_1,1);
  }
  return LVar1;
}



/* 4049d3c4 FUN_4049d3c4 */

/* Boundary evidence: original MIPS .pdata 4049d3c4..4049d467. Semantic name remains unreviewed. */

undefined4 FUN_4049d3c4(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_404962c4(0x700);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_4049d1dc(puVar1);
  }
  if (piVar2 == (int *)0x0) {
    *param_2 = 0;
    uVar3 = 0x8007000e;
  }
  else {
    uVar3 = (**(code **)*piVar2)(piVar2,param_1,param_2);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return uVar3;
}



/* 4049d468 FUN_4049d468 */

/* Boundary evidence: original MIPS .pdata 4049d468..4049d4b3. Semantic name remains unreviewed. */

undefined4 * FUN_4049d468(undefined4 *param_1,uint param_2)

{
  FUN_4049d294(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 4049d4b4 FUN_4049d4b4 */

/* Boundary evidence: original MIPS .pdata 4049d4b4..4049d59b. Semantic name remains unreviewed. */

undefined4 FUN_4049d4b4(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  HRESULT HVar2;
  int *piVar3;
  
  iVar1 = memcmp(param_2,&DAT_404812bc,0x10);
  if ((iVar1 != 0) || (HVar2 = DllCanUnloadNow(), HVar2 == 0)) {
    iVar1 = memcmp(param_2,&DAT_404812cc,0x10);
    if ((iVar1 == 0) && (iVar1 = FUN_404a3c98(), iVar1 != 0)) {
      piVar3 = param_1 + 0xd6;
      if (param_1 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      *param_3 = (int)piVar3;
      goto LAB_4049d560;
    }
    iVar1 = memcmp(param_2,&DAT_40482c64,0x10);
    if (iVar1 != 0) {
      *param_3 = 0;
      return 0x80004002;
    }
  }
  *param_3 = (int)param_1;
LAB_4049d560:
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}



/* 4049d5c4 FUN_4049d5c4 */

void FUN_4049d5c4(void)

{
  return;
}



/* 4049d5cc FUN_4049d5cc */

/* Boundary evidence: original MIPS .pdata 4049d5cc..4049d65b. Semantic name remains unreviewed. */

undefined4 FUN_4049d5cc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_18 [2];
  
  puVar3 = *(undefined4 **)(param_1 + 0x18);
  local_18[0] = 0;
  puVar4 = puVar3 + 10;
  iVar1 = FUN_404901e4((int *)puVar3[7],(int)puVar4,0x1000,puVar3[8],local_18);
  puVar3[0x40a] = iVar1;
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    if (local_18[0] == 0) {
      *(undefined1 *)puVar4 = 0xff;
      *(undefined1 *)((int)puVar3 + 0x29) = 0xd9;
      local_18[0] = 2;
    }
    *puVar3 = puVar4;
    uVar2 = 1;
    puVar3[1] = local_18[0];
  }
  return uVar2;
}



/* 4049d65c FUN_4049d65c */

/* Boundary evidence: original MIPS .pdata 4049d65c..4049d6df. Semantic name remains unreviewed. */

void FUN_4049d65c(int param_1,int param_2)

{
  int *piVar1;
  
  if (0 < param_2) {
    piVar1 = *(int **)(param_1 + 0x18);
    if (piVar1[1] < param_2) {
      do {
        param_2 = param_2 - piVar1[1];
        FUN_4049d5cc(param_1);
      } while (piVar1[1] < param_2);
    }
    *piVar1 = *piVar1 + param_2;
    piVar1[1] = piVar1[1] - param_2;
  }
  return;
}



/* 4049d6e0 FUN_4049d6e0 */

/* Boundary evidence: original MIPS .pdata 4049d6e0..4049d7a7. Semantic name remains unreviewed. */

undefined4 FUN_4049d6e0(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  
  puVar6 = *(undefined4 **)(param_1 + 0x18);
  iVar4 = puVar6[1];
  pbVar5 = (byte *)*puVar6;
  if (iVar4 == 0) {
    iVar4 = (*(code *)puVar6[3])(param_1);
    if (iVar4 != 0) {
      pbVar5 = (byte *)*puVar6;
      iVar4 = puVar6[1];
      goto LAB_4049d72c;
    }
LAB_4049d71c:
    uVar3 = 0;
  }
  else {
LAB_4049d72c:
    iVar4 = iVar4 + -1;
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    if (iVar4 == 0) {
      iVar4 = (*(code *)puVar6[3])(param_1);
      if (iVar4 == 0) goto LAB_4049d71c;
      pbVar5 = (byte *)*puVar6;
      iVar4 = puVar6[1];
    }
    bVar2 = *pbVar5;
    *puVar6 = pbVar5 + 1;
    puVar6[1] = iVar4 + -1;
    if (0 < (int)((uint)bVar2 + (uint)bVar1 * 0x100 + -2)) {
      (**(code **)(*(int *)(param_1 + 0x18) + 0x10))(param_1);
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* 4049d7a8 FUN_4049d7a8 */

/* Boundary evidence: original MIPS .pdata 4049d7a8..4049d7d3. Semantic name remains unreviewed. */

void FUN_4049d7a8(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -8;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  *(undefined4 *)(iVar1 + 0x34c) = 1;
  FUN_4049d6e0(param_1);
  return;
}



/* 4049d7d4 FUN_4049d7d4 */

/* Boundary evidence: original MIPS .pdata 4049d7d4..4049d86b. Semantic name remains unreviewed. */

undefined4 FUN_4049d7d4(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_404812bc,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40482c64,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 4049d86c FUN_4049d86c */

/* Boundary evidence: original MIPS .pdata 4049d86c..4049d887. Semantic name remains unreviewed. */

void FUN_4049d86c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x354));
  return;
}



/* 4049d888 FUN_4049d888 */

/* Boundary evidence: original MIPS .pdata 4049d888..4049d8e3. Semantic name remains unreviewed. */

LONG FUN_4049d888(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0xd5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x94))(param_1,1);
  }
  return LVar1;
}



/* 4049d8e4 FUN_4049d8e4 */

/* Boundary evidence: original MIPS .pdata 4049d8e4..4049d96f. Semantic name remains unreviewed. */

undefined4
FUN_4049d8e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  
  local_10 = DAT_404bd274;
  local_14 = param_5;
  local_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  iVar1 = memcmp(&local_20,&DAT_4048135c,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(&local_20,&DAT_4048137c,0x10), iVar1 == 0)) {
    FUN_404a438c(local_10);
    uVar2 = 0;
  }
  else {
    FUN_404a438c(local_10);
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4049d970 FUN_4049d970 */

/* Boundary evidence: original MIPS .pdata 4049d970..4049db6f. Semantic name remains unreviewed. */

undefined4
FUN_4049d970(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6,byte *param_7)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  
  local_10 = DAT_404bd274;
  local_14 = param_5;
  local_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  iVar2 = memcmp(&local_20,&DAT_4048135c,0x10);
  if (iVar2 == 0) {
    if (param_6 != 8) {
LAB_4049d9cc:
      FUN_404a438c(local_10);
      return 0x80070057;
    }
    *(undefined4 *)(param_1 + 0x2d8) = *(undefined4 *)param_7;
    *(undefined4 *)(param_1 + 0x2dc) = *(undefined4 *)(param_7 + 4);
    *(undefined4 *)(param_1 + 0x2d4) = 1;
    goto LAB_4049db54;
  }
  iVar2 = memcmp(&local_20,&DAT_4048137c,0x10);
  if (iVar2 != 0) goto LAB_4049db54;
  if (param_6 != 1) goto LAB_4049d9cc;
  *(undefined4 *)(param_1 + 0x2cc) = 1;
  bVar1 = *param_7;
  if (0x62 < bVar1) {
    if (bVar1 == 99) {
LAB_4049db50:
      *(undefined4 *)(param_1 + 0x2d0) = 0;
      goto LAB_4049db54;
    }
    if (bVar1 != 0x67) {
      if (bVar1 == 0x6b) {
LAB_4049da9c:
        *(undefined4 *)(param_1 + 0x2d0) = 3;
        goto LAB_4049db54;
      }
      if (bVar1 == 0x6c) goto LAB_4049db44;
      if (bVar1 != 0x6d) {
        if (bVar1 != 0x72) {
          if (bVar1 != 0x79) goto LAB_4049d9cc;
          goto LAB_4049db34;
        }
        goto LAB_4049db50;
      }
    }
    goto LAB_4049db3c;
  }
  if (bVar1 == 0x62) {
LAB_4049dad4:
    *(undefined4 *)(param_1 + 0x2d0) = 2;
    goto LAB_4049db54;
  }
  if (bVar1 < 0x4d) {
    if (bVar1 == 0x4c) {
LAB_4049db44:
      uVar3 = 4;
LAB_4049db48:
      *(undefined4 *)(param_1 + 0x2d0) = uVar3;
      goto LAB_4049db54;
    }
    if (bVar1 == 0x42) goto LAB_4049dad4;
    if (bVar1 == 0x43) goto LAB_4049db50;
    if (bVar1 != 0x47) {
      if (bVar1 != 0x4b) goto LAB_4049d9cc;
      goto LAB_4049da9c;
    }
  }
  else if (bVar1 != 0x4d) {
    if (bVar1 == 0x52) goto LAB_4049db50;
    if (bVar1 != 0x59) goto LAB_4049d9cc;
LAB_4049db34:
    uVar3 = 2;
    goto LAB_4049db48;
  }
LAB_4049db3c:
  *(undefined4 *)(param_1 + 0x2d0) = 1;
LAB_4049db54:
  FUN_404a438c(local_10);
  return 0;
}



/* 4049db70 FUN_4049db70 */

/* Boundary evidence: original MIPS .pdata 4049db70..4049dbcb. Semantic name remains unreviewed. */

undefined4 FUN_4049db70(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x1e4) == 0) {
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 0x1e4) = param_2;
    uVar1 = 0;
    *(undefined4 *)(param_1 + 700) = 0;
  }
  else {
    uVar1 = 0x80004005;
  }
  return uVar1;
}



/* 4049dbcc FUN_4049dbcc */

/* Boundary evidence: original MIPS .pdata 4049dbcc..4049dfaf. Semantic name remains unreviewed. */

int FUN_4049dbcc(int *param_1)

{
  bool bVar1;
  int iVar2;
  SIZE_T SVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  iVar6 = 0;
  if (param_1[0xaf] == 0) {
    iVar6 = (**(code **)(*param_1 + 0x30))(param_1,param_1 + 0x7a);
    if (-1 < iVar6) {
      local_2c = 0;
      local_30 = 0;
      local_28 = param_1[9];
      local_24 = param_1[10];
      iVar6 = (**(code **)(*param_1 + 0x8c))(param_1);
      if ((-1 < iVar6) &&
         (iVar6 = (**(code **)(*(int *)param_1[0x79] + 0xc))
                            ((int *)param_1[0x79],param_1 + 0x7a,&local_30), -1 < iVar6)) {
        bVar1 = false;
        uVar9 = 0;
        if ((param_1[0x88] & 8U) != 0) {
          uVar5 = param_1[0x80];
          if ((uVar5 != param_1[10]) || (param_1[0x7f] != param_1[9])) {
            bVar1 = true;
            uVar9 = 1;
            uVar4 = param_1[0x7f];
            uVar7 = ((param_1[9] + uVar4) - 1) / uVar4;
            if (uVar4 == 0) {
              trap(0x1c00);
            }
            uVar4 = ((param_1[10] + uVar5) - 1) / uVar5;
            if (uVar5 == 0) {
              trap(0x1c00);
            }
            if ((int)uVar4 <= (int)uVar7) {
              uVar7 = uVar4;
            }
            if ((int)uVar7 < 8) {
              if ((int)uVar7 < 4) {
                if (1 < (int)uVar7) {
                  param_1[0xf] = 2;
                }
              }
              else {
                param_1[0xf] = 4;
              }
            }
            else {
              param_1[0xf] = 8;
            }
          }
        }
        iVar2 = FUN_404ada6c(param_1 + 2);
        if (iVar2 == 0) {
          iVar6 = *(int *)(param_1[0xab] + 0x1028);
        }
        else {
          if (bVar1) {
            param_1[0x88] = param_1[0x88] & 0xfffffff7;
            param_1[0x7f] = param_1[0x1e];
            param_1[0x80] = param_1[0x1f];
            uVar8 = __ultodp(param_1[0xf]);
            uVar8 = __dpmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_1[0x84],param_1[0x85],
                            uVar9);
            *(undefined8 *)(param_1 + 0x84) = uVar8;
            uVar8 = __ultodp(param_1[0xf]);
            uVar8 = __dpmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_1[0x86],param_1[0x87]);
            *(undefined8 *)(param_1 + 0x86) = uVar8;
            iVar6 = (**(code **)(*(int *)param_1[0x79] + 0xc))
                              ((int *)param_1[0x79],param_1 + 0x7a,&local_30);
            if (iVar6 < 0) {
              return iVar6;
            }
          }
          param_1[0xaf] = 1;
          iVar2 = param_1[0x7e];
          if ((((iVar2 != 0x21808) && (iVar2 != 0x22009)) && (iVar2 != 0x26200a)) &&
             (iVar2 != 0xe200b)) {
            if ((iVar2 == 0x30803) && (param_1[0xd] == 1)) {
              iVar6 = (**(code **)(*param_1 + 0x60))(param_1);
            }
            else {
              param_1[0x7e] = 0x26200a;
            }
          }
          if (param_1[0xb2] == 1) {
            SVar3 = param_1[0x7f] << 2;
          }
          else {
            SVar3 = param_1[0x7f] * 3;
          }
          iVar2 = FUN_404962c4(SVar3);
          param_1[0xad] = iVar2;
          if (iVar2 == 0) {
            iVar6 = -0x7ff8fff2;
          }
        }
      }
    }
  }
  return iVar6;
}



/* 4049dfb0 FUN_4049dfb0 */

/* Boundary evidence: original MIPS .pdata 4049dfb0..4049dfbb. Semantic name remains unreviewed. */

undefined4 FUN_4049dfb0(void)

{
  return 1;
}



/* 4049dfbc FUN_4049dfbc */

/* Boundary evidence: original MIPS .pdata 4049dfbc..4049e06f. Semantic name remains unreviewed. */

undefined4 FUN_4049dfbc(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar1 = (undefined4 *)FUN_404962c4(0x40c);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0x100;
    uVar4 = 0;
    puVar5 = puVar1 + 2;
    do {
      uVar3 = uVar4 & 0xff;
      uVar4 = uVar4 + 1;
      *puVar5 = ((uVar3 | 0xff00) << 8 | uVar3) << 8 | uVar3;
      puVar5 = puVar5 + 1;
    } while ((int)uVar4 < 0x100);
    (**(code **)(**(int **)(param_1 + 0x1e4) + 0x14))(*(int **)(param_1 + 0x1e4),puVar1);
    FUN_404962ec(puVar1);
    uVar2 = 0;
  }
  return uVar2;
}



/* 4049e070 FUN_4049e070 */

/* Boundary evidence: original MIPS .pdata 4049e070..4049e117. Semantic name remains unreviewed. */

int FUN_4049e070(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  *(undefined4 *)(param_1 + 0x2b0) = 1;
  if (*(LPVOID *)(param_1 + 0x2b4) != (LPVOID)0x0) {
    FUN_404962ec(*(LPVOID *)(param_1 + 0x2b4));
    *(undefined4 *)(param_1 + 0x2b4) = 0;
  }
  piVar2 = *(int **)(param_1 + 0x1e4);
  if (piVar2 == (int *)0x0) {
    param_2 = -0x7fffbffb;
  }
  else {
    if (*(int *)(param_1 + 700) != 0) {
      iVar1 = (**(code **)(*piVar2 + 0x10))(piVar2,param_2);
      if (iVar1 < 0) {
        param_2 = iVar1;
      }
      *(undefined4 *)(param_1 + 700) = 0;
    }
    (**(code **)(**(int **)(param_1 + 0x1e4) + 8))();
    *(undefined4 *)(param_1 + 0x1e4) = 0;
  }
  return param_2;
}



/* 4049e118 FUN_4049e118 */

/* Boundary evidence: original MIPS .pdata 4049e118..4049e25f. Semantic name remains unreviewed. */

undefined4 FUN_4049e118(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x2b8) == 0) {
    iVar1 = FUN_404ae1d8((int *)(param_1 + 8),1);
    if (iVar1 == 0) {
      return *(undefined4 *)(*(int *)(param_1 + 0x2ac) + 0x1028);
    }
    *(undefined4 *)(param_1 + 0x2e0) = *(undefined4 *)(param_1 + 0x30);
    iVar1 = *(int *)(param_1 + 0x34);
    if (iVar1 == 4) {
      *(undefined4 *)(param_1 + 0x2c8) = 1;
      if (*(int *)(param_1 + 0x2cc) == 0) {
        *(undefined4 *)(param_1 + 0x34) = 2;
      }
    }
    else if (((iVar1 != 2) && (iVar1 != 1)) || (3 < *(int *)(param_1 + 0x2c))) {
      return 0x80004005;
    }
    *(undefined4 *)(param_1 + 0x2b8) = 1;
  }
  return 0;
}



/* 4049e260 FUN_4049e260 */

/* Boundary evidence: original MIPS .pdata 4049e260..4049e26b. Semantic name remains unreviewed. */

undefined4 FUN_4049e260(void)

{
  return 1;
}



/* 4049e26c FUN_4049e26c */

/* Boundary evidence: original MIPS .pdata 4049e26c..4049e713. Semantic name remains unreviewed. */

int FUN_4049e26c(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined1 *_Src;
  uint uVar6;
  uint local_54;
  int local_50;
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined1 auStack_38 [16];
  undefined1 *local_28;
  
  piVar3 = (int *)param_1[0x79];
  if (piVar3 == (int *)0x0) {
    return -0x7fffbffb;
  }
  iVar2 = (**(code **)(*piVar3 + 0x28))(piVar3,&local_54);
  if (iVar2 == 0) {
    param_1[0xd2] = local_54 >> 0x1f;
    local_54 = local_54 & 0x7fffffff;
    if (((0xc < local_54) && (local_54 < 0x12)) || (local_54 == 0)) {
      if (local_54 == 0xd) {
        iVar2 = 5;
LAB_4049e38c:
        param_1[0xb9] = iVar2;
      }
      else if (local_54 == 0xe) {
        iVar2 = 6;
LAB_4049e37c:
        param_1[0xb9] = iVar2;
      }
      else {
        if (local_54 == 0xf) {
          iVar2 = 7;
          goto LAB_4049e38c;
        }
        if (local_54 == 0x10) {
          iVar2 = 1;
          goto LAB_4049e37c;
        }
        if (local_54 == 0x11) {
          iVar2 = 2;
          goto LAB_4049e38c;
        }
        param_1[0xb9] = 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x80);
      goto LAB_4049e398;
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x90))(param_1);
  if (iVar2 < 0) {
    return iVar2;
  }
  if (param_1[0xb3] != 1) {
    if ((param_1[0xb5] == 1) && (iVar2 = (**(code **)(*param_1 + 0x7c))(param_1), iVar2 == 0)) {
      return 0;
    }
    do {
      if ((uint)param_1[0x80] <= (uint)param_1[0x25]) {
        FUN_404ae090(param_1 + 2);
        return iVar2;
      }
      iVar2 = FUN_404ad968(param_1 + 2,param_1 + 0xad,1);
      if (iVar2 == 0) {
        return *(int *)(param_1[0xab] + 0x1028);
      }
      local_48 = 0;
      local_40 = param_1[0x7f];
      local_3c = param_1[0x25];
      local_44 = local_3c + -1;
      local_50 = (**(code **)(*(int *)param_1[0x79] + 0x18))
                           ((int *)param_1[0x79],&local_48,param_1[0x7e],1,auStack_38);
      if (local_50 < 0) {
        return local_50;
      }
      _Src = (undefined1 *)param_1[0xad];
      if (param_1[0x7e] == 0x30803) {
        memcpy(local_28,_Src,param_1[0x7f]);
      }
      else if (param_1[0x7e] == 0x21808) {
        if (param_1[0xd] == 2) {
          puVar5 = local_28;
          for (uVar6 = 0; uVar6 < (uint)param_1[0x7f]; uVar6 = uVar6 + 1) {
            *puVar5 = _Src[2];
            puVar5[1] = _Src[1];
            puVar5[2] = *_Src;
            _Src = _Src + 3;
            puVar5 = puVar5 + 3;
          }
        }
        else {
          puVar5 = local_28;
          for (uVar6 = 0; uVar6 < (uint)param_1[0x7f]; uVar6 = uVar6 + 1) {
            uVar1 = *_Src;
            *puVar5 = uVar1;
            puVar5[1] = uVar1;
            puVar5[2] = uVar1;
            _Src = _Src + 1;
            puVar5 = puVar5 + 3;
          }
        }
      }
      else if ((param_1[0xd] == 2) || (param_1[0xd] == 4)) {
        puVar5 = local_28;
        for (uVar6 = 0; uVar6 < (uint)param_1[0x7f]; uVar6 = uVar6 + 1) {
          *puVar5 = _Src[2];
          puVar5[1] = _Src[1];
          puVar5[2] = *_Src;
          puVar5[3] = 0xff;
          _Src = _Src + 3;
          puVar5 = puVar5 + 4;
        }
      }
      else {
        puVar5 = local_28;
        for (uVar6 = 0; uVar6 < (uint)param_1[0x7f]; uVar6 = uVar6 + 1) {
          uVar1 = *_Src;
          *puVar5 = uVar1;
          puVar5[1] = uVar1;
          puVar5[2] = uVar1;
          puVar5[3] = 0xff;
          _Src = _Src + 1;
          puVar5 = puVar5 + 4;
        }
      }
      iVar2 = (**(code **)(*(int *)param_1[0x79] + 0x1c))((int *)param_1[0x79],auStack_38);
      local_50 = iVar2;
    } while (-1 < iVar2);
    return iVar2;
  }
  pcVar4 = *(code **)(*param_1 + 0x78);
LAB_4049e398:
  iVar2 = (*pcVar4)(param_1);
  return iVar2;
}



/* 4049e714 FUN_4049e714 */

/* Boundary evidence: original MIPS .pdata 4049e714..4049e71f. Semantic name remains unreviewed. */

undefined4 FUN_4049e714(void)

{
  return 1;
}



/* 4049e720 FUN_4049e720 */

/* Boundary evidence: original MIPS .pdata 4049e720..4049ea7f. Semantic name remains unreviewed. */

int FUN_4049e720(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  undefined1 auStack_40 [16];
  byte *local_30;
  
  iVar13 = 0;
  bVar1 = *(byte *)(param_1 + 0x2da);
  bVar2 = *(byte *)(param_1 + 0x2d9);
  bVar3 = *(byte *)(param_1 + 0x2d8);
  bVar4 = *(byte *)(param_1 + 0x2de);
  bVar5 = *(byte *)(param_1 + 0x2dd);
  bVar6 = *(byte *)(param_1 + 0x2dc);
  if (*(int *)(param_1 + 0x1f8) == 0x26200a) {
    do {
      if (*(uint *)(param_1 + 0x200) <= *(uint *)(param_1 + 0x94)) {
        FUN_404ae090((int *)(param_1 + 8));
        return iVar13;
      }
      iVar13 = FUN_404ad968((int *)(param_1 + 8),(undefined4 *)(param_1 + 0x2b4),1);
      if (iVar13 == 0) {
        return *(int *)(*(int *)(param_1 + 0x2ac) + 0x1028);
      }
      local_50 = 0;
      local_48 = *(undefined4 *)(param_1 + 0x1fc);
      local_44 = *(int *)(param_1 + 0x94);
      local_4c = local_44 + -1;
      iVar13 = (**(code **)(**(int **)(param_1 + 0x1e4) + 0x18))
                         (*(int **)(param_1 + 0x1e4),&local_50,*(undefined4 *)(param_1 + 0x1f8),1,
                          auStack_40);
      if (iVar13 < 0) {
        return iVar13;
      }
      pbVar12 = *(byte **)(param_1 + 0x2b4);
      if (*(int *)(param_1 + 0x34) == 2) {
        pbVar11 = local_30;
        for (uVar10 = 0; uVar10 < *(uint *)(param_1 + 0x1fc); uVar10 = uVar10 + 1) {
          bVar7 = *pbVar12;
          bVar8 = pbVar12[1];
          bVar9 = pbVar12[2];
          pbVar11[2] = bVar7;
          pbVar11[1] = bVar8;
          *pbVar11 = bVar9;
          if ((((bVar7 < bVar1) || (bVar4 < bVar7)) || (bVar8 < bVar2)) ||
             (((bVar5 < bVar8 || (bVar9 < bVar3)) || (bVar6 < bVar9)))) {
            pbVar11[3] = 0xff;
          }
          else {
            pbVar11[3] = 0;
          }
          pbVar12 = pbVar12 + 3;
          pbVar11 = pbVar11 + 4;
        }
      }
      else if (*(int *)(param_1 + 0x34) == 4) {
        pbVar11 = local_30;
        for (uVar10 = 0; uVar10 < *(uint *)(param_1 + 0x1fc); uVar10 = uVar10 + 1) {
          bVar7 = pbVar12[*(int *)(param_1 + 0x2d0)];
          *pbVar11 = bVar7;
          pbVar11[1] = bVar7;
          pbVar11[2] = bVar7;
          pbVar11[3] = 0xff;
          pbVar12 = pbVar12 + 4;
          pbVar11 = pbVar11 + 4;
        }
      }
      else {
        pbVar11 = local_30;
        for (uVar10 = 0; uVar10 < *(uint *)(param_1 + 0x1fc); uVar10 = uVar10 + 1) {
          bVar7 = *pbVar12;
          *pbVar11 = bVar7;
          pbVar11[1] = bVar7;
          pbVar11[2] = bVar7;
          pbVar11[3] = 0xff;
          pbVar12 = pbVar12 + 1;
          pbVar11 = pbVar11 + 4;
        }
      }
      iVar13 = (**(code **)(**(int **)(param_1 + 0x1e4) + 0x1c))
                         (*(int **)(param_1 + 0x1e4),auStack_40);
    } while (-1 < iVar13);
  }
  else {
    iVar13 = -0x7fffbffb;
  }
  return iVar13;
}



/* 4049ea80 FUN_4049ea80 */

/* Boundary evidence: original MIPS .pdata 4049ea80..4049ea8b. Semantic name remains unreviewed. */

undefined4 FUN_4049ea80(void)

{
  return 1;
}



/* 4049ea8c FUN_4049ea8c */

/* Boundary evidence: original MIPS .pdata 4049ea8c..4049efef. Semantic name remains unreviewed. */

int FUN_4049ea8c(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *_Src;
  uint uVar5;
  undefined8 uVar6;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  undefined1 auStack_40 [16];
  byte *local_30;
  
  iVar2 = param_1 + 8;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  if ((*(int *)(iVar2 + 0x2c) == 2) && (*(int *)(param_1 + 0x2d0) == 3)) {
    iVar2 = -0x7fffbffb;
  }
  else {
    iVar2 = 0;
    do {
      iVar3 = param_1 + 8;
      if (param_1 == 0) {
        iVar3 = 0;
      }
      if (*(uint *)(param_1 + 0x200) <= *(uint *)(iVar3 + 0x8c)) {
        FUN_404ae090((int *)(param_1 + 8));
        return iVar2;
      }
      iVar2 = FUN_404ad968((int *)(param_1 + 8),(undefined4 *)(param_1 + 0x2b4),1);
      if (iVar2 == 0) {
        return *(int *)(*(int *)(param_1 + 0x2ac) + 0x1028);
      }
      local_50 = 0;
      local_48 = *(undefined4 *)(param_1 + 0x1fc);
      local_44 = *(int *)(param_1 + 0x94);
      local_4c = local_44 + -1;
      iVar2 = (**(code **)(**(int **)(param_1 + 0x1e4) + 0x18))
                        (*(int **)(param_1 + 0x1e4),&local_50,*(undefined4 *)(param_1 + 0x1f8),1,
                         auStack_40);
      if (iVar2 < 0) {
        return iVar2;
      }
      _Src = *(byte **)(param_1 + 0x2b4);
      if (*(int *)(param_1 + 0x1f8) == 0x30803) {
        memcpy(local_30,_Src,*(size_t *)(param_1 + 0x1fc));
      }
      else if (*(int *)(param_1 + 0x1f8) == 0x21808) {
        if (*(int *)(param_1 + 0x34) == 2) {
          if (*(int *)(param_1 + 0x2d0) == 4) {
            pbVar4 = local_30;
            for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x1fc); uVar5 = uVar5 + 1) {
              uVar6 = __litodp((uint)_Src[2] + (uint)_Src[1] + (uint)*_Src);
              uVar6 = __dpdiv((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x40080000);
              bVar1 = __dptoul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
              *pbVar4 = bVar1;
              pbVar4[1] = bVar1;
              pbVar4[2] = bVar1;
              _Src = _Src + 3;
              pbVar4 = pbVar4 + 3;
            }
          }
          else {
            pbVar4 = local_30;
            for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x1fc); uVar5 = uVar5 + 1) {
              bVar1 = _Src[*(int *)(param_1 + 0x2d0)];
              *pbVar4 = bVar1;
              pbVar4[1] = bVar1;
              pbVar4[2] = bVar1;
              _Src = _Src + 3;
              pbVar4 = pbVar4 + 3;
            }
          }
        }
        else {
          pbVar4 = local_30;
          for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x1fc); uVar5 = uVar5 + 1) {
            bVar1 = *_Src;
            *pbVar4 = bVar1;
            pbVar4[1] = bVar1;
            pbVar4[2] = bVar1;
            _Src = _Src + 1;
            pbVar4 = pbVar4 + 3;
          }
        }
      }
      else if (*(int *)(param_1 + 0x34) == 2) {
        if (*(int *)(param_1 + 0x2d0) == 4) {
          pbVar4 = local_30;
          for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x1fc); uVar5 = uVar5 + 1) {
            uVar6 = __litodp((uint)_Src[2] + (uint)_Src[1] + (uint)*_Src);
            uVar6 = __dpdiv((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x40080000);
            bVar1 = __dptoul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
            *pbVar4 = bVar1;
            pbVar4[1] = bVar1;
            pbVar4[2] = bVar1;
            pbVar4[3] = 0xff;
            _Src = _Src + 3;
            pbVar4 = pbVar4 + 4;
          }
        }
        else {
          pbVar4 = local_30;
          for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x1fc); uVar5 = uVar5 + 1) {
            bVar1 = _Src[*(int *)(param_1 + 0x2d0)];
            *pbVar4 = bVar1;
            pbVar4[1] = bVar1;
            pbVar4[2] = bVar1;
            pbVar4[3] = 0xff;
            _Src = _Src + 3;
            pbVar4 = pbVar4 + 4;
          }
        }
      }
      else if (*(int *)(param_1 + 0x34) == 4) {
        if (*(int *)(param_1 + 0x2d0) == 4) {
          pbVar4 = local_30;
          for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x1fc); uVar5 = uVar5 + 1) {
            uVar6 = __litodp(((0x2fd - (uint)_Src[2]) - (uint)_Src[1]) - (uint)*_Src);
            uVar6 = __dpdiv((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x40080000);
            bVar1 = __dptoul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
            *pbVar4 = bVar1;
            pbVar4[1] = bVar1;
            pbVar4[2] = bVar1;
            pbVar4[3] = 0xff;
            _Src = _Src + 4;
            pbVar4 = pbVar4 + 4;
          }
        }
        else {
          pbVar4 = local_30;
          for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x1fc); uVar5 = uVar5 + 1) {
            bVar1 = _Src[*(int *)(param_1 + 0x2d0)];
            *pbVar4 = bVar1;
            pbVar4[1] = bVar1;
            pbVar4[2] = bVar1;
            pbVar4[3] = 0xff;
            _Src = _Src + 4;
            pbVar4 = pbVar4 + 4;
          }
        }
      }
      else {
        pbVar4 = local_30;
        for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x1fc); uVar5 = uVar5 + 1) {
          bVar1 = *_Src;
          *pbVar4 = bVar1;
          pbVar4[1] = bVar1;
          pbVar4[2] = bVar1;
          pbVar4[3] = 0xff;
          _Src = _Src + 1;
          pbVar4 = pbVar4 + 4;
        }
      }
      iVar2 = (**(code **)(**(int **)(param_1 + 0x1e4) + 0x1c))
                        (*(int **)(param_1 + 0x1e4),auStack_40);
    } while (-1 < iVar2);
  }
  return iVar2;
}



/* 4049eff0 FUN_4049eff0 */

/* Boundary evidence: original MIPS .pdata 4049eff0..4049effb. Semantic name remains unreviewed. */

undefined4 FUN_4049eff0(void)

{
  return 1;
}



/* 4049f050 FUN_4049f050 */

/* Boundary evidence: original MIPS .pdata 4049f050..4049f0a7. Semantic name remains unreviewed. */

undefined4 FUN_4049f050(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_3 == (undefined4 *)0x0) || (iVar1 = memcmp(param_2,&DAT_4048132c,0x10), iVar1 != 0)) {
    uVar2 = 0x80070057;
  }
  else {
    *param_3 = 1;
    uVar2 = 0;
  }
  return uVar2;
}



/* 4049f0a8 FUN_4049f0a8 */

/* Boundary evidence: original MIPS .pdata 4049f0a8..4049f103. Semantic name remains unreviewed. */

undefined4 FUN_4049f0a8(undefined4 param_1,void *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_2 == (void *)0x0) || (iVar1 = memcmp(param_2,&DAT_4048132c,0x10), iVar1 != 0)) ||
     (1 < param_3)) {
    uVar2 = 0x80070057;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4049f104 FUN_4049f104 */

/* Boundary evidence: original MIPS .pdata 4049f104..4049f2f7. Semantic name remains unreviewed. */

undefined4
FUN_4049f104(undefined4 param_1,int param_2,undefined2 param_3,undefined4 *param_4,short *param_5)

{
  byte bVar1;
  undefined2 *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  size_t _Size;
  undefined2 *_Dst;
  
  puVar8 = *(undefined4 **)(param_2 + 0x18);
  pbVar7 = (byte *)*puVar8;
  iVar5 = puVar8[1];
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar8[3])(param_2);
    if (iVar5 == 0) {
      return 0;
    }
    pbVar7 = (byte *)*puVar8;
    iVar5 = puVar8[1];
  }
  iVar5 = iVar5 + -1;
  bVar1 = *pbVar7;
  pbVar7 = pbVar7 + 1;
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar8[3])(param_2);
    if (iVar5 == 0) {
      return 0;
    }
    pbVar7 = (byte *)*puVar8;
    iVar5 = puVar8[1];
  }
  uVar6 = (uint)*pbVar7 + (uint)bVar1 * 0x100;
  *puVar8 = pbVar7 + 1;
  puVar8[1] = iVar5 + -1;
  if (1 < uVar6) {
    uVar3 = uVar6 + 2;
    *param_5 = (short)uVar3;
    if ((uVar3 & 0xffff) < uVar6) {
      *param_5 = ((short)uVar6 - (short)uVar3) + 1;
    }
    puVar2 = (undefined2 *)FUN_404962c4(uVar3);
    if (puVar2 != (undefined2 *)0x0) {
      *puVar2 = param_3;
      puVar2[1] = (short)uVar6;
      _Size = uVar6 - 2;
      _Dst = puVar2 + 2;
      do {
        if (_Size == 0) {
LAB_4049f2d0:
          *param_4 = puVar2;
          return 1;
        }
        puVar8 = *(undefined4 **)(param_2 + 0x18);
        if ((int)_Size < (int)puVar8[1]) {
          memcpy(_Dst,(void *)**(undefined4 **)(param_2 + 0x18),_Size);
          **(int **)(param_2 + 0x18) = **(int **)(param_2 + 0x18) + _Size;
          *(size_t *)(*(int *)(param_2 + 0x18) + 4) = *(int *)(*(int *)(param_2 + 0x18) + 4) - _Size
          ;
          goto LAB_4049f2d0;
        }
        if (puVar8[1] != 0) {
          memcpy(_Dst,(void *)*puVar8,puVar8[1]);
          piVar4 = *(int **)(param_2 + 0x18);
          iVar5 = piVar4[1];
          _Dst = (undefined2 *)(iVar5 + (int)_Dst);
          *piVar4 = *piVar4 + iVar5;
          _Size = _Size - iVar5;
          *(undefined4 *)(*(int *)(param_2 + 0x18) + 4) = 0;
        }
        iVar5 = (**(code **)(*(int *)(param_2 + 0x18) + 0xc))(param_2);
      } while (iVar5 != 0);
      FUN_404962ec(puVar2);
    }
  }
  return 0;
}



/* 4049f2f8 FUN_4049f2f8 */

uint FUN_4049f2f8(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  uVar1 = *(uint *)(param_1 + 0x1c);
  iVar3 = *(int *)(param_1 + 0x14c);
  iVar2 = 1;
  piVar4 = (int *)(param_1 + 800);
  if (0 < iVar3) {
    do {
      if (iVar2 < *piVar4) {
        iVar2 = *piVar4;
      }
      piVar4 = piVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  uVar5 = uVar1 / (uint)(iVar2 << 3);
  if (iVar2 << 3 == 0) {
    trap(0x1c00);
  }
  if (uVar5 != 0) {
    uVar1 = uVar5 * iVar2 * 8;
  }
  return uVar1;
}



/* 4049f364 FUN_4049f364 */

uint FUN_4049f364(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  iVar3 = *(int *)(param_1 + 0x14c);
  iVar2 = 1;
  piVar4 = (int *)(param_1 + 0x330);
  if (0 < iVar3) {
    do {
      if (iVar2 < *piVar4) {
        iVar2 = *piVar4;
      }
      piVar4 = piVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  uVar5 = uVar1 / (uint)(iVar2 << 3);
  if (iVar2 << 3 == 0) {
    trap(0x1c00);
  }
  if (uVar5 != 0) {
    uVar1 = uVar5 * iVar2 * 8;
  }
  return uVar1;
}



/* 4049f3d0 FUN_4049f3d0 */

/* Boundary evidence: original MIPS .pdata 4049f3d0..4049f48f. Semantic name remains unreviewed. */

void FUN_4049f3d0(int param_1,int param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  if (param_2 == 1) {
LAB_4049f45c:
    uVar2 = FUN_4049f364(param_1);
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 5) goto LAB_4049f45c;
      if (param_2 == 6) {
        uVar2 = FUN_4049f364(param_1);
      }
      else if (param_2 != 7) goto LAB_4049f468;
    }
    uVar1 = FUN_4049f2f8(param_1);
  }
LAB_4049f468:
  *param_3 = uVar1;
  *param_4 = uVar2;
  return;
}



/* 4049f490 FUN_4049f490 */

/* Boundary evidence: original MIPS .pdata 4049f490..4049f90f. Semantic name remains unreviewed. */

undefined4 FUN_4049f490(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  byte *local_48;
  uint local_44;
  uint local_38;
  uint local_34;
  uint local_30;
  
  puVar7 = *(undefined4 **)(param_1 + 0x18);
  local_38 = 0;
  iVar8 = *(int *)(param_1 + 0x1bc);
  local_48 = (byte *)*puVar7;
  local_30 = 0;
  local_34 = 0;
  puVar10 = *(undefined4 **)(iVar8 + 0xa4);
  iVar11 = puVar7[1];
  local_44 = 0;
  if (puVar10 == (undefined4 *)0x0) {
    if (iVar11 == 0) {
      iVar11 = (*(code *)puVar7[3])(param_1);
      if (iVar11 == 0) {
        return 0;
      }
      local_48 = (byte *)*puVar7;
      iVar11 = puVar7[1];
    }
    bVar1 = *local_48;
    iVar11 = iVar11 + -1;
    pbVar4 = local_48 + 1;
    if (iVar11 == 0) {
      iVar11 = (*(code *)puVar7[3])(param_1);
      if (iVar11 == 0) {
        return 0;
      }
      pbVar4 = (byte *)*puVar7;
      iVar11 = puVar7[1];
    }
    iVar11 = iVar11 + -1;
    local_48 = pbVar4 + 1;
    local_44 = ((uint)*pbVar4 + (uint)bVar1 * 0x100) - 2;
    if ((int)local_44 < 0) {
      uVar6 = 0;
      uVar9 = 0;
      pbVar4 = (byte *)0x0;
    }
    else {
      if (*(int *)(param_1 + 0x1a4) == 0xfe) {
        uVar6 = *(uint *)(iVar8 + 0x60);
      }
      else {
        uVar6 = *(uint *)((*(int *)(param_1 + 0x1a4) + -199) * 4 + iVar8);
      }
      if (local_44 < uVar6) {
        uVar6 = local_44;
      }
      puVar10 = (undefined4 *)(**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,uVar6 + 0x14);
      *puVar10 = 0;
      pbVar4 = (byte *)(puVar10 + 5);
      *(char *)(puVar10 + 1) = (char)*(undefined4 *)(param_1 + 0x1a4);
      puVar10[2] = local_44;
      puVar10[3] = uVar6;
      puVar10[4] = pbVar4;
      *(undefined4 **)(iVar8 + 0xa4) = puVar10;
      *(undefined4 *)(iVar8 + 0xa8) = 0;
      uVar9 = 0;
    }
  }
  else {
    uVar9 = *(uint *)(iVar8 + 0xa8);
    uVar6 = puVar10[3];
    pbVar4 = (byte *)(puVar10[4] + uVar9);
  }
  do {
    if (uVar6 <= uVar9) {
LAB_4049f6a0:
      if (puVar10 != (undefined4 *)0x0) {
        piVar5 = *(int **)(param_1 + 0x134);
        if (piVar5 == (int *)0x0) {
          *(undefined4 **)(param_1 + 0x134) = puVar10;
        }
        else {
          iVar2 = *piVar5;
          while (iVar2 != 0) {
            piVar5 = (int *)*piVar5;
            iVar2 = *piVar5;
          }
          *piVar5 = (int)puVar10;
        }
        pbVar4 = (byte *)puVar10[4];
        local_44 = puVar10[2] - uVar6;
      }
      *(undefined4 *)(iVar8 + 0xa4) = 0;
      iVar8 = *(int *)(param_1 + 0x1a4);
      if (iVar8 == 0xe0) {
        if ((((0xd < uVar6) && (*pbVar4 == 0x4a)) && (pbVar4[1] == 0x46)) &&
           (((pbVar4[2] == 0x49 && (pbVar4[3] == 0x46)) && (pbVar4[4] == 0)))) {
          *(undefined4 *)(param_1 + 0x11c) = 1;
          *(byte *)(param_1 + 0x120) = pbVar4[5];
          *(byte *)(param_1 + 0x121) = pbVar4[6];
          *(byte *)(param_1 + 0x122) = pbVar4[7];
          *(ushort *)(param_1 + 0x124) = (ushort)pbVar4[8] * 0x100 + (ushort)pbVar4[9];
          *(ushort *)(param_1 + 0x126) = (ushort)pbVar4[10] * 0x100 + (ushort)pbVar4[0xb];
        }
      }
      else if (iVar8 == 0xe1) {
        iVar8 = *(int *)(param_1 + 0x2dc);
        if (*(int *)(param_1 + 0x340) == 1) {
          FUN_4049f3d0(param_1,iVar8,&local_38,&local_34);
          uVar9 = 0;
          if (local_38 != *(uint *)(param_1 + 0x1c)) {
            uVar9 = local_38;
          }
          uVar3 = local_34;
          if (local_34 == *(uint *)(param_1 + 0x20)) {
            uVar3 = 0;
          }
        }
        else {
          uVar9 = 0;
          uVar3 = local_30;
        }
        FUN_404aae40(pbVar4,uVar6 & 0xffff,iVar8,uVar9,uVar3);
      }
      else if (iVar8 == 0xed) {
        FUN_404abf18(pbVar4,uVar6 & 0xffff);
      }
      else if (((iVar8 == 0xee) && (0xb < uVar6)) &&
              (((*pbVar4 == 0x41 &&
                (((pbVar4[1] == 100 && (pbVar4[2] == 0x6f)) && (pbVar4[3] == 0x62)))) &&
               (pbVar4[4] == 0x65)))) {
        bVar1 = pbVar4[0xb];
        *(undefined4 *)(param_1 + 0x128) = 1;
        *(byte *)(param_1 + 300) = bVar1;
      }
      *puVar7 = local_48;
      puVar7[1] = iVar11;
      if (0 < (int)local_44) {
        (**(code **)(*(int *)(param_1 + 0x18) + 0x10))(param_1,local_44);
      }
      return 1;
    }
    *puVar7 = local_48;
    puVar7[1] = iVar11;
    *(uint *)(iVar8 + 0xa8) = uVar9;
    if (iVar11 == 0) {
      iVar11 = (*(code *)puVar7[3])(param_1);
      if (iVar11 == 0) {
        return 0;
      }
      local_48 = (byte *)*puVar7;
      iVar11 = puVar7[1];
    }
    if (uVar6 <= uVar9) goto LAB_4049f6a0;
    do {
      if (iVar11 == 0) break;
      uVar9 = uVar9 + 1;
      *pbVar4 = *local_48;
      pbVar4 = pbVar4 + 1;
      local_48 = local_48 + 1;
      iVar11 = iVar11 + -1;
    } while (uVar9 < uVar6);
  } while( true );
}



/* 4049f910 FUN_4049f910 */

/* Boundary evidence: original MIPS .pdata 4049f910..4049f99b. Semantic name remains unreviewed. */

undefined4 FUN_4049f910(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    FUN_404b057c(param_2,0xfe,0xffff,FUN_4049f490);
  }
  if (param_3 == 2) {
    iVar1 = 0;
    do {
      FUN_404b057c(param_2,iVar1 + 0xe0,0xffff,FUN_4049f490);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
  }
  return 0;
}



/* 4049f99c FUN_4049f99c */

/* Boundary evidence: original MIPS .pdata 4049f99c..4049fc23. Semantic name remains unreviewed. */

undefined4 FUN_4049f99c(int param_1,int param_2,int param_3)

{
  LPVOID pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ushort local_78 [2];
  LPVOID local_74;
  undefined1 auStack_70 [20];
  undefined4 local_5c;
  int local_58;
  uint local_30;
  
  local_30 = DAT_404bd274;
  local_74 = (LPVOID)0x0;
  iVar2 = FUN_4049f104(param_1,param_2,(short)param_3,&local_74,(short *)local_78);
  pvVar1 = local_74;
  if (iVar2 == 0) {
    FUN_404a438c(local_30);
    uVar6 = 0;
  }
  else if (local_74 == (LPVOID)0x0) {
    FUN_404a438c(local_30);
    uVar6 = 1;
  }
  else {
    uVar6 = 1;
    if ((param_3 == 0xe1) && (*(int *)(param_1 + 0x2c4) == 0)) {
      *(undefined4 *)(param_1 + 0x34c) = 1;
      FUN_404abaf8((int *)(param_1 + 0x2c4),(void *)((int)local_74 + 4),
                   local_78[0] + 0xfffc & 0xffff);
    }
    else if ((param_3 == 0xed) && (*(int *)(param_1 + 0x2c4) == 0)) {
      *(undefined4 *)(param_1 + 0x34c) = 1;
      FUN_404ad340((int *)(param_1 + 0x2c4),(void *)((int)local_74 + 4),
                   local_78[0] + 0xfffc & 0xffff);
    }
    piVar5 = *(int **)(param_1 + 0x2c4);
    if ((((piVar5 != (int *)0x0) &&
         (iVar2 = (**(code **)(*piVar5 + 0x10))(piVar5,auStack_70), iVar2 == 0)) && (local_58 != 0))
       && (iVar2 = *(int *)(param_1 + 0x28), iVar2 != 0)) {
      uVar7 = __ultodp(local_5c);
      uVar8 = __ultodp(local_58);
      uVar7 = __dpdiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                      (int)((ulonglong)uVar8 >> 0x20));
      uVar3 = (undefined4)((ulonglong)uVar7 >> 0x20);
      uVar8 = __ultodp(*(undefined4 *)(param_1 + 0x24));
      uVar9 = __ultodp(iVar2);
      uVar8 = __dpdiv((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar9,
                      (int)((ulonglong)uVar9 >> 0x20));
      uVar4 = (undefined4)((ulonglong)uVar8 >> 0x20);
      uVar9 = __dpsub((int)uVar7,uVar3,(int)uVar8,uVar4);
      local_74 = (LPVOID)((uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff);
      iVar2 = __ltd((int)uVar7,uVar3,(int)uVar8,uVar4);
      if (iVar2 == 0) {
        uVar7 = uVar8;
      }
      uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0x9999999a,0x3fa99999);
      iVar2 = __gtd((int)uVar9,local_74,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
      if (iVar2 != 0) {
        (**(code **)(**(int **)(param_1 + 0x2c4) + 8))();
        *(undefined4 *)(param_1 + 0x2c4) = 0;
      }
    }
    FUN_404962ec(pvVar1);
    FUN_404a438c(local_30);
  }
  return uVar6;
}



/* 4049fc24 FUN_4049fc24 */

/* Boundary evidence: original MIPS .pdata 4049fc24..4049fdaf. Semantic name remains unreviewed. */

undefined4 FUN_4049fc24(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe1,FUN_4049d7a8);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xed,FUN_4049d7a8);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe3,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe4,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe5,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe6,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe7,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe8,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe9,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xea,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xeb,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xec,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xef,FUN_4049d6e0);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xfe,FUN_4049d6e0);
  return 0;
}



/* 4049fdb0 FUN_4049fdb0 */

/* Boundary evidence: original MIPS .pdata 4049fdb0..4049febf. Semantic name remains unreviewed. */

undefined4 FUN_4049fdb0(int param_1,int param_2,int param_3)

{
  LPVOID pvVar1;
  int iVar2;
  undefined4 uVar3;
  ushort local_20 [2];
  LPVOID local_1c;
  
  local_1c = (LPVOID)0x0;
  iVar2 = FUN_4049f104(param_1,param_2,(short)param_3,&local_1c,(short *)local_20);
  pvVar1 = local_1c;
  if (iVar2 == 0) {
LAB_4049fdfc:
    uVar3 = 0;
  }
  else {
    if (local_1c == (LPVOID)0x0) {
      return 1;
    }
    uVar3 = 1;
    if (param_3 == 0xe1) {
      *(undefined4 *)(param_1 + 0x34c) = 1;
      iVar2 = FUN_404ab724(param_2,(void *)((int)local_1c + 4),local_20[0] + 0xfffc & 0xffff);
      if (iVar2 != 0) {
        FUN_404962ec(pvVar1);
        goto LAB_4049fdfc;
      }
    }
    else if (param_3 == 0xed) {
      *(undefined4 *)(param_1 + 0x34c) = 1;
      iVar2 = FUN_404aceb0(param_2,(void *)((int)local_1c + 4),local_20[0] + 0xfffc & 0xffff);
      if (iVar2 != 0) {
        uVar3 = 0;
      }
    }
    FUN_404962ec(pvVar1);
  }
  return uVar3;
}



/* 4049fec0 FUN_4049fec0 */

/* Boundary evidence: original MIPS .pdata 4049fec0..404a00c7. Semantic name remains unreviewed. */

undefined4 FUN_4049fec0(int param_1,int param_2,int param_3)

{
  LPVOID pvVar1;
  int iVar2;
  void *_Dst;
  undefined4 uVar3;
  uint uVar4;
  size_t _Size;
  ushort local_28 [2];
  LPVOID local_24;
  
  local_24 = (LPVOID)0x0;
  iVar2 = FUN_4049f104(param_1,param_2,(short)param_3,&local_24,(short *)local_28);
  pvVar1 = local_24;
  if (iVar2 == 0) {
    return 0;
  }
  if (local_24 == (LPVOID)0x0) {
    return 1;
  }
  uVar4 = (uint)local_28[0];
  uVar3 = 1;
  if (param_3 == 0xe1) {
    *(undefined4 *)(param_1 + 0x34c) = 1;
    iVar2 = FUN_404ab254(param_1 + 0x304,(int *)(param_1 + 0x31c),(int *)(param_1 + 800),
                         (void *)((int)local_24 + 4),local_28[0] - 4);
    if (iVar2 != 0) goto LAB_4049ff68;
  }
  if (param_3 == 0xe2) {
    *(undefined4 *)(param_1 + 0x34c) = 1;
    iVar2 = FUN_404ad558(param_1 + 0x304,(int *)(param_1 + 0x31c),(int *)(param_1 + 800),
                         (void *)((int)pvVar1 + 4),local_28[0] - 4);
    if (iVar2 != 0) {
LAB_4049ff68:
      FUN_404962ec(pvVar1);
      return 0;
    }
  }
  else {
    if (param_3 == 0xed) {
      *(undefined4 *)(param_1 + 0x34c) = 1;
      iVar2 = FUN_404ac0fc(param_1 + 0x304,(int *)(param_1 + 0x31c),(int *)(param_1 + 800),
                           (void *)((int)pvVar1 + 4),local_28[0] - 4);
      if (iVar2 == 0) goto LAB_404a0098;
    }
    else {
      if ((param_3 != 0xfe) || (uVar4 < 5)) goto LAB_404a0098;
      _Size = uVar4 - 4;
      _Dst = (void *)FUN_404962c4(uVar4 - 3);
      if (_Dst != (void *)0x0) {
        memcpy(_Dst,(void *)((int)pvVar1 + 4),_Size);
        *(undefined1 *)((int)_Dst + _Size) = 0;
        iVar2 = FUN_404904d0(param_1 + 0x304,0x9286,uVar4 - 3,2,_Dst);
        if (iVar2 == 0) {
          *(int *)(param_1 + 800) = *(int *)(param_1 + 800) + 1;
          *(size_t *)(param_1 + 0x31c) = *(int *)(param_1 + 0x31c) + _Size + 1;
          FUN_404962ec(_Dst);
          goto LAB_404a0098;
        }
        FUN_404962ec(_Dst);
      }
    }
    uVar3 = 0;
  }
LAB_404a0098:
  FUN_404962ec(pvVar1);
  return uVar3;
}



/* 404a00c8 FUN_404a00c8 */

/* Boundary evidence: original MIPS .pdata 404a00c8..404a0133. Semantic name remains unreviewed. */

int FUN_404a00c8(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else if ((param_1[0xba] != 0) || (iVar1 = (**(code **)(*param_1 + 0x84))(param_1), -1 < iVar1)) {
    iVar1 = 0;
    *param_2 = param_1[200];
  }
  return iVar1;
}



/* 404a0134 FUN_404a0134 */

/* Boundary evidence: original MIPS .pdata 404a0134..404a0203. Semantic name remains unreviewed. */

int FUN_404a0134(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((param_1[0xba] != 0) || (iVar1 = (**(code **)(*param_1 + 0x84))(param_1), -1 < iVar1)) {
    iVar1 = param_1[200];
    if ((param_2 == iVar1) && (param_3 != (int *)0x0)) {
      if (iVar1 != 0) {
        piVar2 = (int *)param_1[0xbb];
        iVar3 = 0;
        if (0 < iVar1) {
          do {
            if ((piVar2 == (int *)0x0) || (piVar2 == param_1 + 0xc1)) break;
            iVar3 = iVar3 + 1;
            *param_3 = piVar2[2];
            param_3 = param_3 + 1;
            piVar2 = (int *)*piVar2;
          } while (iVar3 < param_1[200]);
        }
      }
      iVar1 = 0;
    }
    else {
      iVar1 = -0x7ff8ffa9;
    }
  }
  return iVar1;
}



/* 404a0204 FUN_404a0204 */

/* Boundary evidence: original MIPS .pdata 404a0204..404a02c3. Semantic name remains unreviewed. */

int FUN_404a0204(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else if ((param_1[0xba] != 0) || (iVar1 = (**(code **)(*param_1 + 0x84))(param_1), -1 < iVar1)) {
    piVar2 = *(int **)param_1[0xbb];
    piVar4 = (int *)param_1[0xbb];
    if (piVar2 != (int *)0x0) {
      do {
        piVar3 = piVar2;
        if (piVar4[2] == param_2) break;
        piVar2 = (int *)*piVar3;
        piVar4 = piVar3;
      } while ((int *)*piVar3 != (int *)0x0);
      if (*piVar4 != 0) {
        *param_3 = piVar4[3] + 0x10;
        return 0;
      }
    }
    iVar1 = -0x7784fff6;
  }
  return iVar1;
}



/* 404a02c4 FUN_404a02c4 */

/* Boundary evidence: original MIPS .pdata 404a02c4..404a03d3. Semantic name remains unreviewed. */

int FUN_404a02c4(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_4 == (int *)0x0) {
LAB_404a02f0:
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if ((param_1[0xba] == 0) && (iVar1 = (**(code **)(*param_1 + 0x84))(param_1), iVar1 < 0)) {
      return iVar1;
    }
    piVar2 = *(int **)param_1[0xbb];
    piVar4 = (int *)param_1[0xbb];
    if (piVar2 != (int *)0x0) {
      do {
        piVar3 = piVar2;
        if (piVar4[2] == param_2) break;
        piVar2 = (int *)*piVar3;
        piVar4 = piVar3;
      } while ((int *)*piVar3 != (int *)0x0);
      if (*piVar4 != 0) {
        if (piVar4[3] + 0x10 == param_3) {
          *param_4 = piVar4[2];
          param_4[1] = piVar4[3];
          *(short *)(param_4 + 2) = (short)piVar4[4];
          if (piVar4[3] == 0) {
            param_4[3] = 0;
          }
          else {
            param_4[3] = (int)(param_4 + 4);
            memcpy(param_4 + 4,(void *)piVar4[5],piVar4[3]);
          }
          return 0;
        }
        goto LAB_404a02f0;
      }
    }
    iVar1 = -0x7784fff6;
  }
  return iVar1;
}



/* 404a03d4 FUN_404a03d4 */

/* Boundary evidence: original MIPS .pdata 404a03d4..404a0467. Semantic name remains unreviewed. */

int FUN_404a03d4(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if ((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else if ((param_1[0xba] != 0) || (iVar1 = (**(code **)(*param_1 + 0x84))(param_1), -1 < iVar1)) {
    iVar1 = 0;
    *param_3 = param_1[200];
    *param_2 = param_1[199] + param_1[200] * 0x10;
  }
  return iVar1;
}



/* 404a0468 FUN_404a0468 */

/* Boundary evidence: original MIPS .pdata 404a0468..404a066f. Semantic name remains unreviewed. */

int FUN_404a0468(int *param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *_Dst;
  
  iVar3 = param_1[200];
  uVar6 = iVar3 * 0x10;
  if (((param_2 == param_1[199] + uVar6) && (param_3 == iVar3)) && (param_4 != (undefined4 *)0x0)) {
    if ((param_1[0xba] != 0) || (iVar1 = (**(code **)(*param_1 + 0x84))(param_1), -1 < iVar1)) {
      piVar5 = (int *)param_1[0xbb];
      _Dst = param_4 + iVar3 * 4;
      for (iVar3 = 0; iVar3 < param_1[200]; iVar3 = iVar3 + 1) {
        if ((piVar5 == (int *)0x0) || (param_4 == (undefined4 *)0x0)) {
          return -0x7ff8ffa9;
        }
        *param_4 = piVar5[2];
        param_4[1] = piVar5[3];
        *(undefined2 *)(param_4 + 2) = *(undefined2 *)(piVar5 + 4);
        if (piVar5[3] == 0) {
          param_4[3] = 0;
        }
        else {
          iVar1 = -0x7ff8fdea;
          uVar4 = piVar5[3] + uVar6;
          uVar2 = 0xffffffff;
          if (uVar6 <= uVar4) {
            iVar1 = 0;
            uVar2 = uVar4;
          }
          if ((iVar1 < 0) || (param_2 < uVar2)) {
            return -0x7ff8ffa9;
          }
          param_4[3] = _Dst;
          memcpy(_Dst,(void *)piVar5[5],piVar5[3]);
        }
        uVar6 = piVar5[3] + uVar6;
        _Dst = (undefined4 *)(piVar5[3] + (int)_Dst);
        piVar5 = (int *)*piVar5;
        param_4 = param_4 + 4;
      }
      iVar1 = 0;
    }
  }
  else {
    iVar1 = -0x7ff8ffa9;
  }
  return iVar1;
}



/* 404a0670 FUN_404a0670 */

/* Boundary evidence: original MIPS .pdata 404a0670..404a067b. Semantic name remains unreviewed. */

undefined4 FUN_404a0670(void)

{
  return 1;
}



/* 404a067c FUN_404a067c */

/* Boundary evidence: original MIPS .pdata 404a067c..404a074b. Semantic name remains unreviewed. */

int FUN_404a067c(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if ((param_1[0xba] != 0) || (iVar1 = (**(code **)(*param_1 + 0x84))(param_1), -1 < iVar1)) {
    piVar2 = *(int **)param_1[0xbb];
    piVar4 = (int *)param_1[0xbb];
    if (piVar2 != (int *)0x0) {
      do {
        piVar3 = piVar2;
        if (piVar4[2] == param_2) break;
        piVar2 = (int *)*piVar3;
        piVar4 = piVar3;
      } while ((int *)*piVar3 != (int *)0x0);
      if (*piVar4 != 0) {
        param_1[200] = param_1[200] + -1;
        param_1[199] = param_1[199] - piVar4[3];
        FUN_40490480(piVar4);
        FUN_404962ec(piVar4);
        param_1[0xc9] = 1;
        return 0;
      }
    }
    iVar1 = -0x7784fff6;
  }
  return iVar1;
}



/* 404a074c FUN_404a074c */

/* Boundary evidence: original MIPS .pdata 404a074c..404a089b. Semantic name remains unreviewed. */

int FUN_404a074c(int *param_1,int param_2,SIZE_T param_3,undefined2 param_4,void *param_5)

{
  int iVar1;
  void *_Dst;
  int *piVar2;
  
  if ((param_1[0xba] == 0) && (iVar1 = (**(code **)(*param_1 + 0x84))(param_1), iVar1 < 0)) {
    return iVar1;
  }
  piVar2 = (int *)param_1[0xbb];
  if (*piVar2 != 0) {
    do {
      if (piVar2[2] == param_2) break;
      piVar2 = (int *)*piVar2;
    } while (*piVar2 != 0);
    if (*piVar2 != 0) {
      param_1[199] = (param_1[199] - piVar2[3]) + param_3;
      FUN_404962ec((LPVOID)piVar2[5]);
      piVar2[3] = param_3;
      *(undefined2 *)(piVar2 + 4) = param_4;
      _Dst = (void *)FUN_404962c4(param_3);
      piVar2[5] = (int)_Dst;
      if (_Dst == (void *)0x0) {
        piVar2[3] = 0;
        return -0x7ff8fff2;
      }
      memcpy(_Dst,param_5,param_3);
      goto LAB_404a0874;
    }
  }
  iVar1 = FUN_404904d0((int)(param_1 + 0xc1),param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    return -0x7fffbffb;
  }
  param_1[200] = param_1[200] + 1;
  param_1[199] = param_1[199] + param_3;
LAB_404a0874:
  param_1[0xc9] = 1;
  return 0;
}



/* 404a089c FUN_404a089c */

/* Boundary evidence: original MIPS .pdata 404a089c..404a091b. Semantic name remains unreviewed. */

void FUN_404a089c(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x2ec);
  if (0 < *(int *)(param_1 + 800)) {
    do {
      if (puVar2 == (undefined4 *)0x0) break;
      puVar1 = (undefined4 *)*puVar2;
      FUN_404962ec((LPVOID)puVar2[5]);
      FUN_404962ec(puVar2);
      iVar3 = iVar3 + 1;
      puVar2 = puVar1;
    } while (iVar3 < *(int *)(param_1 + 800));
  }
  *(undefined4 *)(param_1 + 800) = 0;
  *(undefined4 *)(param_1 + 0x2e8) = 0;
  return;
}



/* 404a091c FUN_404a091c */

/* Boundary evidence: original MIPS .pdata 404a091c..404a0a0f. Semantic name remains unreviewed. */

undefined4 FUN_404a091c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_res8 [2];
  SIZE_T local_20 [2];
  
  *param_4 = 0;
  local_20[0] = 0;
  local_res8[0] = param_3;
  iVar1 = (**(code **)(*param_1 + 0x48))(param_1,param_2,local_20);
  if (-1 < iVar1) {
    puVar2 = (undefined4 *)FUN_404962c4(local_20[0]);
    if (puVar2 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    iVar1 = (**(code **)(*param_1 + 0x4c))(param_1,param_2,local_20[0],puVar2);
    if (-1 < iVar1) {
      *param_4 = *(undefined4 *)puVar2[3];
      puVar2[3] = local_res8;
      (**(code **)(*param_1 + 0x5c))(param_1,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    }
    FUN_404962ec(puVar2);
  }
  return 0;
}



/* 404a0a10 FUN_404a0a10 */

/* Boundary evidence: original MIPS .pdata 404a0a10..404a0b13. Semantic name remains unreviewed. */

int FUN_404a0a10(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_18 [2];
  
  iVar2 = 0;
  if (((param_1[200] != 0) && (iVar1 = (**(code **)(*(int *)param_1[0x79] + 0x2c))(), iVar1 == 0))
     && ((param_1[0xba] != 0 || (iVar2 = (**(code **)(*param_1 + 0x84))(param_1), -1 < iVar2)))) {
    local_18[0] = 0;
    iVar1 = param_1[199] + param_1[200] * 0x10;
    iVar2 = (**(code **)(*(int *)param_1[0x79] + 0x34))((int *)param_1[0x79],iVar1,local_18);
    if ((-1 < iVar2) &&
       (iVar2 = (**(code **)(*param_1 + 0x54))(param_1,iVar1,param_1[200],local_18[0]), -1 < iVar2))
    {
      iVar2 = (**(code **)(*(int *)param_1[0x79] + 0x38))
                        ((int *)param_1[0x79],param_1[200],iVar1,local_18[0]);
    }
  }
  return iVar2;
}



/* 404a0b14 FUN_404a0b14 */

int * FUN_404a0b14(int *param_1,int param_2,uint param_3)

{
  param_1[2] = (int)FUN_4049d5c4;
  param_1[6] = (int)FUN_4049d5c4;
  param_1[4] = (int)FUN_4049d65c;
  param_1[3] = (int)FUN_4049d5cc;
  param_1[5] = (int)FUN_404b02fc;
  param_1[1] = 0;
  *param_1 = (int)(param_1 + 10);
  param_1[8] = (uint)((param_3 & 1) == 0);
  param_1[9] = param_3;
  param_1[7] = param_2;
  param_1[0x40a] = 0;
  return param_1;
}



/* 404a0b84 FUN_404a0b84 */

/* Boundary evidence: original MIPS .pdata 404a0b84..404a0d7b. Semantic name remains unreviewed. */

undefined4 FUN_404a0b84(int param_1,int *param_2,uint param_3)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  if (*(int *)(param_1 + 0x1e0) == 0) {
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 0x1e0) = param_2;
    *(undefined4 *)(param_1 + 0x2b0) = 0;
    *(undefined4 *)(param_1 + 0x2b4) = 0;
    *(undefined4 *)(param_1 + 0x2c4) = 0;
    *(undefined4 *)(param_1 + 0x34c) = 0;
    *(undefined4 *)(param_1 + 0x2c8) = 0;
    *(undefined4 *)(param_1 + 0x2cc) = 0;
    *(undefined4 *)(param_1 + 0x2d0) = 0;
    *(undefined4 *)(param_1 + 0x2d4) = 0;
    *(undefined4 *)(param_1 + 0x2e0) = 0;
    *(undefined4 *)(param_1 + 0x2e4) = 0;
    *(undefined4 *)(param_1 + 0x348) = 0;
    puVar3 = (undefined4 *)(param_1 + 0x328);
    iVar4 = 4;
    do {
      *puVar3 = 0;
      puVar3[4] = 0;
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    *(undefined4 *)(param_1 + 0x2c0) = 1;
    piVar5 = (int *)(param_1 + 8);
    puVar3 = FUN_404ad854((undefined4 *)(param_1 + 0x228));
    *piVar5 = (int)puVar3;
    *(undefined4 *)(param_1 + 0x228) = FUN_404bc404;
    FUN_404adbe0(piVar5,0x3e,0x1d8);
    piVar2 = (int *)FUN_404962c4(0x102c);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_404a0b14(piVar2,(int)param_2,param_3);
    }
    *(int **)(param_1 + 0x2ac) = piVar2;
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      *(int **)(param_1 + 0x20) = piVar2;
      FUN_404b0698(piVar5,0xe1,FUN_4049d7a8);
      FUN_404b0698(piVar5,0xed,FUN_4049d7a8);
      *(undefined4 *)(param_1 + 0x2b8) = 0;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80004005;
  }
  return uVar1;
}



/* 404a0d7c FUN_404a0d7c */

/* Boundary evidence: original MIPS .pdata 404a0d7c..404a0d87. Semantic name remains unreviewed. */

undefined4 FUN_404a0d7c(void)

{
  return 1;
}



/* 404a0d88 FUN_404a0d88 */

/* Boundary evidence: original MIPS .pdata 404a0d88..404a0eaf. Semantic name remains unreviewed. */

undefined4 FUN_404a0d88(int param_1)

{
  if (*(int **)(param_1 + 0x1e0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x1e0) + 8))();
    *(undefined4 *)(param_1 + 0x1e0) = 0;
  }
  if (*(LPVOID *)(param_1 + 0x2ac) != (LPVOID)0x0) {
    FUN_404962ec(*(LPVOID *)(param_1 + 0x2ac));
    *(undefined4 *)(param_1 + 0x2ac) = 0;
  }
  if (*(LPVOID *)(param_1 + 0x2b4) != (LPVOID)0x0) {
    FUN_404962ec(*(LPVOID *)(param_1 + 0x2b4));
    *(undefined4 *)(param_1 + 0x2b4) = 0;
  }
  if (*(int **)(param_1 + 0x2c4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x2c4) + 8))();
    *(undefined4 *)(param_1 + 0x2c4) = 0;
  }
  FUN_404add08(param_1 + 8);
  if (*(int *)(param_1 + 0x2e8) == 1) {
    FUN_404a089c(param_1);
  }
  *(undefined4 *)(param_1 + 0x2c0) = 0;
  return 0;
}



/* 404a0eb0 FUN_404a0eb0 */

/* Boundary evidence: original MIPS .pdata 404a0eb0..404a0ebb. Semantic name remains unreviewed. */

undefined4 FUN_404a0eb0(void)

{
  return 1;
}



/* 404a0ebc FUN_404a0ebc */

/* Boundary evidence: original MIPS .pdata 404a0ebc..404a102b. Semantic name remains unreviewed. */

int FUN_404a0ebc(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  LPVOID pvVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x2b0) != 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x1e0) + 0x14))
                      (*(int **)(param_1 + 0x1e0),param_2,0,0,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    FUN_404add24(param_1 + 8);
    pvVar3 = *(LPVOID *)(param_1 + 0x20);
    if (pvVar3 != (LPVOID)0x0) {
      uVar4 = *(uint *)((int)pvVar3 + 0x24);
      FUN_404962ec(pvVar3);
      piVar2 = (int *)FUN_404962c4(0x102c);
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = FUN_404a0b14(piVar2,*(int *)(param_1 + 0x1e0),uVar4);
      }
      *(int **)(param_1 + 0x20) = piVar2;
      *(int **)(param_1 + 0x2ac) = piVar2;
      if (*(int *)(param_1 + 0x20) == 0) {
        return -0x7ff8fff2;
      }
    }
    *(undefined4 *)(param_1 + 0x2b8) = 0;
    *(undefined4 *)(param_1 + 0x2b0) = 0;
  }
  return 0;
}



/* 404a102c FUN_404a102c */

/* Boundary evidence: original MIPS .pdata 404a102c..404a1037. Semantic name remains unreviewed. */

undefined4 FUN_404a102c(void)

{
  return 1;
}



/* 404a1038 FUN_404a1038 */

/* Boundary evidence: original MIPS .pdata 404a1038..404a13db. Semantic name remains unreviewed. */

int FUN_404a1038(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20 [2];
  
  if (param_1[0xae] != 0) {
    param_1[0xac] = 1;
    iVar1 = (**(code **)(*param_1 + 100))(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  if (param_1[0xc9] == 0) {
    (**(code **)(*param_1 + 0x70))(param_1,param_1 + 2,2);
  }
  else {
    local_24 = 0;
    local_20[0] = 0;
    local_2c = 0;
    local_28 = 0;
    if (param_1[0xd2] == 1) {
      FUN_4049f3d0((int)(param_1 + 2),param_1[0xb9],&local_24,local_20);
      if (((local_24 != 0) && (local_24 != param_1[9])) &&
         (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,0xa002,local_24,&local_2c), iVar1 < 0)) {
        return iVar1;
      }
      if (((local_20[0] != 0) && (local_20[0] != param_1[10])) &&
         (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,0xa003,local_20[0],&local_28), iVar1 < 0))
      {
        return iVar1;
      }
    }
    iVar2 = param_1[200] * 0x10 + param_1[199];
    local_30 = 0;
    iVar1 = (**(code **)(*(int *)param_1[0x79] + 0x34))((int *)param_1[0x79],iVar2,&local_30);
    if ((iVar1 != 0) && (iVar1 != -0x7fffbfff)) {
      return iVar1;
    }
    iVar1 = (**(code **)(*param_1 + 0x54))(param_1,iVar2,param_1[200],local_30);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(int *)param_1[0x79] + 0x38))
                      ((int *)param_1[0x79],param_1[200],iVar2,local_30);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (param_1[0xd2] == 1) {
      if ((local_2c != 0) &&
         (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,0xa002,param_1[9],&local_2c), iVar1 < 0)) {
        return iVar1;
      }
      if ((local_28 != 0) &&
         (iVar1 = (**(code **)(*param_1 + 0x88))(param_1,0xa003,param_1[10],&local_28), iVar1 < 0))
      {
        return iVar1;
      }
    }
  }
  iVar1 = FUN_404ae1d8(param_1 + 2,1);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1[0xab] + 0x1028);
  }
  else {
    param_1[0xae] = 1;
    (**(code **)(*param_1 + 0x74))(param_1);
    iVar1 = (**(code **)(*(int *)param_1[0x79] + 0x30))((int *)param_1[0x79],param_1 + 2);
    if (-1 < iVar1) {
      FUN_404ae090(param_1 + 2);
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 404a13dc FUN_404a13dc */

/* Boundary evidence: original MIPS .pdata 404a13dc..404a13e7. Semantic name remains unreviewed. */

undefined4 FUN_404a13dc(void)

{
  return 1;
}



/* 404a13e8 FUN_404a13e8 */

/* Boundary evidence: original MIPS .pdata 404a13e8..404a13f3. Semantic name remains unreviewed. */

undefined4 FUN_404a13e8(void)

{
  return 1;
}



/* 404a13f4 DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
                    /* 0x213f4  1  DllCanUnloadNow */
  return 1;
}



/* 404a13fc FUN_404a13fc */

/* Boundary evidence: original MIPS .pdata 404a13fc..404a142b. Semantic name remains unreviewed. */

void FUN_404a13fc(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -8;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  FUN_4049f99c(iVar1,param_1,0xe1);
  return;
}



/* 404a142c FUN_404a142c */

/* Boundary evidence: original MIPS .pdata 404a142c..404a145b. Semantic name remains unreviewed. */

void FUN_404a142c(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -8;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  FUN_4049f99c(iVar1,param_1,0xed);
  return;
}



/* 404a145c FUN_404a145c */

/* Boundary evidence: original MIPS .pdata 404a145c..404a148b. Semantic name remains unreviewed. */

void FUN_404a145c(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -8;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  FUN_4049fec0(iVar1,param_1,0xe1);
  return;
}



/* 404a148c FUN_404a148c */

/* Boundary evidence: original MIPS .pdata 404a148c..404a14bb. Semantic name remains unreviewed. */

void FUN_404a148c(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -8;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  FUN_4049fec0(iVar1,param_1,0xe2);
  return;
}



/* 404a14bc FUN_404a14bc */

/* Boundary evidence: original MIPS .pdata 404a14bc..404a14eb. Semantic name remains unreviewed. */

void FUN_404a14bc(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -8;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  FUN_4049fec0(iVar1,param_1,0xed);
  return;
}



/* 404a14ec FUN_404a14ec */

/* Boundary evidence: original MIPS .pdata 404a14ec..404a151b. Semantic name remains unreviewed. */

void FUN_404a14ec(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -8;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  FUN_4049fec0(iVar1,param_1,0xfe);
  return;
}



/* 404a151c FUN_404a151c */

/* Boundary evidence: original MIPS .pdata 404a151c..404a154b. Semantic name remains unreviewed. */

void FUN_404a151c(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -8;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  FUN_4049fdb0(iVar1,param_1,0xe1);
  return;
}



/* 404a154c FUN_404a154c */

/* Boundary evidence: original MIPS .pdata 404a154c..404a157b. Semantic name remains unreviewed. */

void FUN_404a154c(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -8;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  FUN_4049fdb0(iVar1,param_1,0xed);
  return;
}



/* 404a157c FUN_404a157c */

/* Boundary evidence: original MIPS .pdata 404a157c..404a1743. Semantic name remains unreviewed. */

undefined4 FUN_404a157c(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe1,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe2,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe3,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe4,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe5,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe6,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe7,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe8,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xe9,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xea,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xeb,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xec,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xed,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xef,DllCanUnloadNow);
  piVar1 = (int *)(param_1 + 8);
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  FUN_404b0698(piVar1,0xfe,DllCanUnloadNow);
  return 0;
}



/* 404a1744 FUN_404a1744 */

/* Boundary evidence: original MIPS .pdata 404a1744..404a1907. Semantic name remains unreviewed. */

int FUN_404a1744(int *param_1)

{
  int iVar1;
  code *pcVar2;
  void *pvVar3;
  int *piVar4;
  
  if (param_1[0xba] != 1) {
    param_1[0xd4] = 10;
    if (param_1[0xae] == 1) {
      pcVar2 = *(code **)(*param_1 + 100);
      param_1[0xac] = 1;
      iVar1 = (*pcVar2)(param_1);
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    piVar4 = param_1 + 2;
    FUN_404b0698(piVar4,0xe1,FUN_404a145c);
    FUN_404b0698(piVar4,0xe2,FUN_404a148c);
    FUN_404b0698(piVar4,0xed,FUN_404a14bc);
    FUN_404b0698(piVar4,0xfe,FUN_404a14ec);
    iVar1 = (**(code **)(*param_1 + 0x68))(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (param_1 + 0x2c != (int *)0x0) {
      pvVar3 = (void *)param_1[0x2c];
      if (pvVar3 != (void *)0x0) {
        iVar1 = FUN_404904d0((int)(param_1 + 0xc1),0x5090,0x80,3,pvVar3);
        if (iVar1 != 0) {
          return 0;
        }
        param_1[200] = param_1[200] + 1;
        param_1[199] = param_1[199] + 0x80;
      }
      if ((void *)param_1[0x2d] != (void *)0x0) {
        iVar1 = FUN_404904d0((int)(param_1 + 0xc1),0x5091,0x80,3,(void *)param_1[0x2d]);
        if (iVar1 != 0) {
          return 0;
        }
        param_1[200] = param_1[200] + 1;
        param_1[199] = param_1[199] + 0x80;
      }
    }
    FUN_404b0698(piVar4,0xe1,FUN_4049d6e0);
    FUN_404b0698(piVar4,0xe2,FUN_4049d6e0);
    FUN_404b0698(piVar4,0xed,FUN_4049d6e0);
    FUN_404b0698(piVar4,0xfe,FUN_4049d6e0);
    param_1[0xba] = 1;
  }
  return 0;
}



/* 404a1908 FUN_404a1908 */

/* Boundary evidence: original MIPS .pdata 404a1908..404a1a13. Semantic name remains unreviewed. */

int FUN_404a1908(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  
  *param_4 = 0;
  if (param_1[0xae] != 0) {
    if (param_1[0xd3] == 0) {
      return -0x7fffbffb;
    }
    param_1[0xac] = 1;
    iVar1 = (**(code **)(*param_1 + 100))(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  piVar2 = param_1 + 2;
  FUN_404b0698(piVar2,0xe1,FUN_404a13fc);
  FUN_404b0698(piVar2,0xed,FUN_404a142c);
  iVar1 = (**(code **)(*param_1 + 0x68))(param_1);
  if (iVar1 < 0) {
    return iVar1;
  }
  FUN_404b0698(piVar2,0xe1,FUN_4049d6e0);
  FUN_404b0698(piVar2,0xed,FUN_4049d6e0);
  *param_4 = param_1[0xb1];
  param_1[0xb1] = 0;
  if (*param_4 == 0) {
    return -0x7fffbffb;
  }
  return 0;
}



/* 404a1a14 FUN_404a1a14 */

/* Boundary evidence: original MIPS .pdata 404a1a14..404a1ebb. Semantic name remains unreviewed. */

int FUN_404a1a14(int *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  HDC pHVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined8 uVar9;
  
  iVar2 = (**(code **)(*param_1 + 100))(param_1);
  if (iVar2 < 0) {
    return iVar2;
  }
  piVar7 = param_1 + 2;
  FUN_404b0698(piVar7,0xe1,FUN_404a151c);
  FUN_404b0698(piVar7,0xed,FUN_404a154c);
  iVar2 = (**(code **)(*param_1 + 0x68))(param_1);
  if (iVar2 < 0) {
    return iVar2;
  }
  FUN_404b0698(piVar7,0xe1,FUN_4049d6e0);
  FUN_404b0698(piVar7,0xed,FUN_4049d6e0);
  piVar7 = param_1 + 0x56;
  piVar8 = param_1 + 0xca;
  for (iVar2 = 0; iVar2 < param_1[0x55]; iVar2 = iVar2 + 1) {
    *piVar8 = *(int *)(*piVar7 + 8);
    iVar6 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar8[4] = *(int *)(iVar6 + 0xc);
    piVar8 = piVar8 + 1;
  }
  *param_2 = 0xb96b3cae;
  param_2[1] = 0x11d30728;
  param_2[2] = 0x7b9d;
  param_2[3] = 0x2ef31ef8;
  if (param_1[0xb5] == 1) {
    param_2[4] = 0x26200a;
  }
  else {
    if (param_1[0xd] == 4) {
      uVar4 = 0x26200a;
    }
    else {
      if (param_1[0xd] == 2) {
        param_2[4] = 0x21808;
        goto LAB_404a1b94;
      }
      uVar4 = 0x30803;
    }
    param_2[4] = uVar4;
  }
LAB_404a1b94:
  bVar1 = true;
  param_2[5] = param_1[9];
  param_2[6] = param_1[10];
  if (*(char *)((int)param_1 + 0x12a) == '\x01') {
    uVar9 = __ultodp((short)param_1[0x4b]);
    *(undefined8 *)(param_2 + 10) = uVar9;
    uVar9 = __ultodp(*(undefined2 *)((int)param_1 + 0x12e));
LAB_404a1cfc:
    *(undefined8 *)(param_2 + 0xc) = uVar9;
  }
  else {
    if (*(char *)((int)param_1 + 0x12a) == '\x02') {
      uVar9 = __ultodp((short)param_1[0x4b]);
      uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0x851eb852,0x400451eb);
      *(undefined8 *)(param_2 + 10) = uVar9;
      uVar9 = __ultodp(*(undefined2 *)((int)param_1 + 0x12e));
      uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0x851eb852,0x400451eb);
      goto LAB_404a1cfc;
    }
    pHVar3 = GetDC((HWND)0x0);
    if (pHVar3 == (HDC)0x0) {
LAB_404a1c54:
      param_2[10] = 0;
      param_2[0xb] = 0x40580000;
      param_2[0xc] = 0;
      param_2[0xd] = 0x40580000;
    }
    else {
      iVar2 = GetDeviceCaps(pHVar3,0x58);
      uVar4 = __litofp(iVar2);
      uVar9 = __fptodp(uVar4);
      *(undefined8 *)(param_2 + 10) = uVar9;
      iVar2 = __led((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0);
      if (iVar2 != 0) goto LAB_404a1c54;
      iVar2 = GetDeviceCaps(pHVar3,0x5a);
      uVar4 = __litofp(iVar2);
      uVar9 = __fptodp(uVar4);
      *(undefined8 *)(param_2 + 0xc) = uVar9;
      iVar2 = __led((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0);
      if (iVar2 != 0) goto LAB_404a1c54;
    }
    ReleaseDC((HWND)0x0,pHVar3);
    bVar1 = false;
  }
  iVar2 = __led(param_2[10],param_2[0xb],0,0);
  if ((iVar2 != 0) || (iVar2 = __led(param_2[0xc],param_2[0xd],0,0), iVar2 != 0)) {
    pHVar3 = GetDC((HWND)0x0);
    if (pHVar3 == (HDC)0x0) {
LAB_404a1dd0:
      param_2[10] = 0;
      param_2[0xb] = 0x40580000;
      param_2[0xc] = 0;
      param_2[0xd] = 0x40580000;
    }
    else {
      iVar2 = GetDeviceCaps(pHVar3,0x58);
      uVar4 = __litofp(iVar2);
      uVar9 = __fptodp(uVar4);
      *(undefined8 *)(param_2 + 10) = uVar9;
      iVar2 = __led((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0);
      if (iVar2 != 0) goto LAB_404a1dd0;
      iVar2 = GetDeviceCaps(pHVar3,0x5a);
      uVar4 = __litofp(iVar2);
      uVar9 = __fptodp(uVar4);
      *(undefined8 *)(param_2 + 0xc) = uVar9;
      iVar2 = __led((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0);
      if (iVar2 != 0) goto LAB_404a1dd0;
    }
    ReleaseDC((HWND)0x0,pHVar3);
    bVar1 = false;
  }
  param_2[0xe] = 0x52008;
  if (bVar1) {
    param_2[0xe] = 0x53008;
  }
  iVar2 = param_1[0xb8];
  if (iVar2 == 1) {
    uVar5 = param_2[0xe] | 0x40;
  }
  else {
    if (iVar2 == 2) {
      uVar5 = param_2[0xe] | 0x10;
LAB_404a1e6c:
      param_2[0xe] = uVar5;
      goto LAB_404a1e80;
    }
    if (iVar2 == 3) {
      uVar5 = param_2[0xe] | 0x80;
    }
    else {
      if (iVar2 == 4) {
        uVar5 = param_2[0xe] | 0x20;
        goto LAB_404a1e6c;
      }
      if (iVar2 != 5) goto LAB_404a1e80;
      uVar5 = param_2[0xe] | 0x100;
    }
  }
  param_2[0xe] = uVar5;
LAB_404a1e80:
  param_2[7] = param_1[9];
  param_2[8] = 1;
  return 0;
}



/* 404a1ebc FUN_404a1ebc */

undefined4 * FUN_404a1ebc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40484c70;
  param_1[0xd5] = 1;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0xad] = 0;
  param_1[0xab] = 0;
  param_1[0xba] = 0;
  param_1[0xbc] = 0;
  param_1[0xbb] = param_1 + 0xc1;
  param_1[0xbd] = 0;
  param_1[0xbe] = 0;
  *(undefined2 *)(param_1 + 0xbf) = 0;
  param_1[0xc0] = 0;
  param_1[0xc2] = param_1 + 0xbb;
  param_1[0xc1] = 0;
  param_1[0xc3] = 0;
  param_1[0xc4] = 0;
  *(undefined2 *)(param_1 + 0xc5) = 0;
  param_1[0xc6] = 0;
  param_1[199] = 0;
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[0xb1] = 0;
  param_1[0xb0] = 0;
  return param_1;
}



/* 404a1f38 FUN_404a1f38 */

/* Boundary evidence: original MIPS .pdata 404a1f38..404a1f6b. Semantic name remains unreviewed. */

void FUN_404a1f38(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40484c70;
  if (param_1[0xb0] != 0) {
    FUN_404a0d88((int)param_1);
  }
  return;
}



/* 404a1f6c FUN_404a1f6c */

/* Boundary evidence: original MIPS .pdata 404a1f6c..404a1fcb. Semantic name remains unreviewed. */

undefined4 * FUN_404a1f6c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40484c70;
  if (param_1[0xb0] != 0) {
    FUN_404a0d88((int)param_1);
  }
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404a1fcc FUN_404a1fcc */

/* Boundary evidence: original MIPS .pdata 404a1fcc..404a2027. Semantic name remains unreviewed. */

void FUN_404a1fcc(void)

{
  HRESULT HVar1;
  int iVar2;
  uint uVar3;
  
  HVar1 = DllCanUnloadNow();
  uVar3 = 2;
  if (HVar1 == 0) {
    uVar3 = 0;
  }
  iVar2 = FUN_404a3c98();
  DAT_404bd25c = iVar2 != 0 | uVar3 | DAT_404bd25c;
  return;
}



/* 404a2028 FUN_404a2028 */

/* Boundary evidence: original MIPS .pdata 404a2028..404a2093. Semantic name remains unreviewed. */

undefined4 * FUN_404a2028(undefined4 *param_1)

{
  FUN_404a3830(param_1);
  FUN_404a3edc(param_1 + 0x11c);
  *param_1 = &PTR_FUN_40484d88;
  param_1[0x11c] = &PTR_LAB_40484d5c;
  param_1[0x11d] = &PTR_LAB_40484d20;
  param_1[0x13c] = 1;
  return param_1;
}



/* 404a2094 FUN_404a2094 */

/* Boundary evidence: original MIPS .pdata 404a2094..404a20e7. Semantic name remains unreviewed. */

void FUN_404a2094(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40484d88;
  param_1[0x11c] = &PTR_LAB_40484d5c;
  param_1[0x11d] = &PTR_LAB_40484d20;
  FUN_404a3e74(param_1 + 0x11c);
  FUN_404a30c0(param_1);
  return;
}



/* 404a20e8 FUN_404a20e8 */

/* Boundary evidence: original MIPS .pdata 404a20e8..404a21af. Semantic name remains unreviewed. */

undefined4 FUN_404a20e8(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_404812bc,0x10);
  if (iVar1 != 0) {
    iVar1 = memcmp(param_2,&DAT_404812cc,0x10);
    if (iVar1 == 0) {
      piVar2 = param_1 + 0x11c;
      if (param_1 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      *param_3 = (int)piVar2;
      goto LAB_404a2174;
    }
    iVar1 = memcmp(param_2,&DAT_40482c64,0x10);
    if (iVar1 != 0) {
      *param_3 = 0;
      return 0x80004002;
    }
  }
  *param_3 = (int)param_1;
LAB_404a2174:
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}



/* 404a21b0 FUN_404a21b0 */

/* Boundary evidence: original MIPS .pdata 404a21b0..404a21cb. Semantic name remains unreviewed. */

void FUN_404a21b0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x4f0));
  return;
}



/* 404a21cc FUN_404a21cc */

/* Boundary evidence: original MIPS .pdata 404a21cc..404a2227. Semantic name remains unreviewed. */

LONG FUN_404a21cc(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0x13c);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x60))(param_1,1);
  }
  return LVar1;
}



/* 404a22b4 FUN_404a22b4 */

/* Boundary evidence: original MIPS .pdata 404a22b4..404a2357. Semantic name remains unreviewed. */

undefined4 FUN_404a22b4(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_404962c4(0x4f8);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_404a2028(puVar1);
  }
  if (piVar2 == (int *)0x0) {
    *param_2 = 0;
    uVar3 = 0x8007000e;
  }
  else {
    uVar3 = (**(code **)*piVar2)(piVar2,param_1,param_2);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return uVar3;
}



/* 404a2358 FUN_404a2358 */

/* Boundary evidence: original MIPS .pdata 404a2358..404a23a3. Semantic name remains unreviewed. */

undefined4 * FUN_404a2358(undefined4 *param_1,uint param_2)

{
  FUN_404a2094(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404a23a4 FUN_404a23a4 */

/* Boundary evidence: original MIPS .pdata 404a23a4..404a23ff. Semantic name remains unreviewed. */

undefined4 FUN_404a23a4(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [2];
  
  uVar2 = 1;
  iVar1 = FUN_404901e4(param_1,param_2,param_3,1,local_18);
  if ((iVar1 < 0) || (param_3 != local_18[0])) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 404a2400 FUN_404a2400 */

/* Boundary evidence: original MIPS .pdata 404a2400..404a2477. Semantic name remains unreviewed. */

undefined4 FUN_404a2400(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 8) = param_2;
    uVar1 = 0;
    *(undefined4 *)(param_1 + 4) = 0x446d4231;
    *(undefined4 *)(param_1 + 0x458) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x460) = 1;
  }
  else {
    uVar1 = 0x80004005;
  }
  return uVar1;
}



/* 404a2478 FUN_404a2478 */

uint FUN_404a2478(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x40) == 3) {
    if ((*(short *)(param_1 + 0x3e) == 0x10) || (*(short *)(param_1 + 0x3e) == 0x20)) {
      uVar1 = 3;
    }
  }
  else {
    uVar2 = (uint)*(ushort *)(param_1 + 0x3e);
    if (((uVar2 == 1) || (uVar2 == 4)) || (uVar2 == 8)) {
      uVar1 = *(uint *)(param_1 + 0x50);
      uVar2 = 1 << (uVar2 & 0x1f);
      if ((uVar1 == 0) || (uVar2 < uVar1)) {
        uVar1 = uVar2;
      }
    }
  }
  return uVar1;
}



/* 404a2500 FUN_404a2500 */

/* Boundary evidence: original MIPS .pdata 404a2500..404a2607. Semantic name remains unreviewed. */

undefined4 FUN_404a2500(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  byte *pbVar8;
  
  sVar4 = *(short *)(param_1 + 0x3e);
  if (((sVar4 == 1) || (sVar4 == 4)) || (sVar4 == 8)) {
    if (*(int *)(param_1 + 0x10) == 0) {
      uVar5 = FUN_404a2478(param_1);
      puVar6 = (undefined4 *)FUN_404962c4((uVar5 + 3) * 4);
      *(undefined4 **)(param_1 + 0x10) = puVar6;
      if (puVar6 == (undefined4 *)0x0) {
        return 0x8007000e;
      }
      *puVar6 = 0;
      *(uint *)(*(int *)(param_1 + 0x10) + 4) = uVar5;
      if (uVar5 != 0) {
        pbVar8 = (byte *)(param_1 + 0x58);
        do {
          pbVar1 = pbVar8 + 2;
          pbVar2 = pbVar8 + 1;
          bVar3 = *pbVar8;
          puVar7 = (uint *)(pbVar8 + *(int *)(param_1 + 0x10) + (-0x50 - param_1));
          uVar5 = uVar5 - 1;
          pbVar8 = pbVar8 + 4;
          *puVar7 = ((*pbVar1 | 0xff00) << 8 | (uint)*pbVar2) << 8 | (uint)bVar3;
        } while (uVar5 != 0);
      }
    }
    (**(code **)(**(int **)(param_1 + 0xc) + 0x14))
              (*(int **)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  }
  return 0;
}



/* 404a2608 FUN_404a2608 */

undefined4 FUN_404a2608(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = *(short *)(param_1 + 0x3e);
  if (sVar1 == 1) {
    uVar2 = 0x30101;
  }
  else if (sVar1 == 4) {
    uVar2 = 0x30402;
  }
  else if (sVar1 == 8) {
    uVar2 = 0x30803;
  }
  else if (sVar1 == 0x10) {
    uVar2 = 0x21005;
  }
  else if (sVar1 == 0x18) {
    uVar2 = 0x21808;
  }
  else {
    uVar2 = 0x22009;
    if (sVar1 != 0x20) {
      if (sVar1 == 0x40) {
        uVar2 = 0x34400d;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    uVar2 = 0x22009;
  }
  return uVar2;
}



/* 404a26d4 FUN_404a26d4 */

/* Boundary evidence: original MIPS .pdata 404a26d4..404a2703. Semantic name remains unreviewed. */

undefined4 FUN_404a26d4(void)

{
  FUN_404a438c(DAT_404bd274);
  return 0x80004001;
}



/* 404a2704 FUN_404a2704 */

/* Boundary evidence: original MIPS .pdata 404a2704..404a2733. Semantic name remains unreviewed. */

undefined4 FUN_404a2704(void)

{
  FUN_404a438c(DAT_404bd274);
  return 0x80004001;
}



/* 404a2840 FUN_404a2840 */

/* Boundary evidence: original MIPS .pdata 404a2840..404a28a3. Semantic name remains unreviewed. */

undefined4 FUN_404a2840(int param_1)

{
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 8))();
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(HGDIOBJ *)(param_1 + 0x24) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x24));
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  *(undefined4 *)(param_1 + 0x460) = 0;
  return 0;
}



/* 404a28a4 FUN_404a28a4 */

/* Boundary evidence: original MIPS .pdata 404a28a4..404a2917. Semantic name remains unreviewed. */

undefined4 FUN_404a28a4(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 4) == 0x446d4231) && (*(int *)(param_1 + 0xc) == 0)) {
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 0xc) = param_2;
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x464) = 0;
    *(undefined4 *)(param_1 + 0x45c) = 0;
  }
  else {
    uVar1 = 0x80004005;
  }
  return uVar1;
}



/* 404a2918 FUN_404a2918 */

/* Boundary evidence: original MIPS .pdata 404a2918..404a29db. Semantic name remains unreviewed. */

int FUN_404a2918(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 4) == 0x446d4231) {
    if (*(LPVOID *)(param_1 + 0x10) != (LPVOID)0x0) {
      FUN_404962ec(*(LPVOID *)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    if (*(HGDIOBJ *)(param_1 + 0x24) != (HGDIOBJ)0x0) {
      DeleteObject(*(HGDIOBJ *)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    piVar2 = *(int **)(param_1 + 0xc);
    if (piVar2 != (int *)0x0) {
      iVar1 = (**(code **)(*piVar2 + 0x10))(piVar2,param_2);
      (**(code **)(**(int **)(param_1 + 0xc) + 8))();
      *(undefined4 *)(param_1 + 0xc) = 0;
      if (-1 < iVar1) {
        return param_2;
      }
      return iVar1;
    }
  }
  return -0x7fffbffb;
}



/* 404a29dc FUN_404a29dc */

/* Boundary evidence: original MIPS .pdata 404a29dc..404a2b2b. Semantic name remains unreviewed. */

undefined4 FUN_404a29dc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_58 [64];
  uint local_18;
  
  local_18 = DAT_404bd274;
  memcpy(auStack_58,&stack0x00000010,0x40);
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x14))();
  if (-1 < iVar1) {
    iVar1 = (uint)*(ushort *)(param_1 + 0x3e) * *(int *)(param_1 + 0x34);
    iVar2 = iVar1 + 7;
    if (iVar2 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    iVar1 = FUN_404a23a4(*(int **)(param_1 + 8),param_2,iVar2 >> 3);
    if (iVar1 != 0) {
      FUN_404a438c(local_18);
      return 0;
    }
  }
  FUN_404a438c(local_18);
  return 0x80004005;
}



/* 404a2b2c FUN_404a2b2c */

/* Boundary evidence: original MIPS .pdata 404a2b2c..404a2f8f. Semantic name remains unreviewed. */

int FUN_404a2b2c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  int iVar2;
  LPVOID lpvBits;
  HDC hdc;
  HBITMAP pHVar3;
  BITMAPINFO *lpbmi;
  HDC hdc_00;
  HGDIOBJ h;
  RGBQUAD RVar4;
  uint uVar5;
  RGBQUAD *pRVar6;
  uint uVar7;
  uint uVar8;
  RGBQUAD *pRVar9;
  uint uVar10;
  uint uVar11;
  undefined4 local_res8;
  undefined4 local_resc;
  BITMAPINFO local_e8;
  undefined1 auStack_b8 [20];
  DWORD local_a4;
  DWORD local_a0;
  LPVOID local_78 [2];
  uint local_70;
  uint local_30;
  
  local_30 = DAT_404bd274;
  local_res8 = param_3;
  local_resc = param_4;
  memcpy(auStack_b8,&local_res8,0x40);
  iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x30))(*(int **)(param_1 + 8),local_78,1);
  if (iVar2 < 0) {
    FUN_404a438c(local_30);
    return iVar2;
  }
  CoTaskMemFree(local_78[0]);
  if (*(uint *)(param_1 + 0x1e) <= local_70) {
    uVar11 = local_70 - *(uint *)(param_1 + 0x1e);
    if ((*(int *)(param_1 + 0x40) == 0) || (*(int *)(param_1 + 0x40) == 3)) {
      uVar5 = (int)*(uint *)(param_1 + 0x38) >> 0x1f;
      uVar5 = (*(uint *)(param_1 + 0x38) ^ uVar5) - uVar5;
      lVar1 = (ulonglong)(uint)*(ushort *)(param_1 + 0x3e) * (ulonglong)*(uint *)(param_1 + 0x34);
      iVar2 = (uint)*(ushort *)(param_1 + 0x3e) * ((int)*(uint *)(param_1 + 0x34) >> 0x1f) +
              (int)((ulonglong)lVar1 >> 0x20);
      uVar7 = iVar2 * 0x20000000 | (uint)lVar1 >> 3;
      uVar8 = uVar7 + 3;
      uVar10 = uVar8 & 0xfffffffc;
      lVar1 = (ulonglong)uVar5 * (ulonglong)uVar10;
      iVar2 = uVar5 * ((iVar2 >> 3) + (uint)(uVar8 < uVar7)) + ((int)uVar5 >> 0x1f) * uVar10 +
              (int)((ulonglong)lVar1 >> 0x20);
      if ((-1 < iVar2) && ((iVar2 != 0 || (uVar11 < (uint)lVar1)))) goto LAB_404a2be0;
    }
    lpvBits = (LPVOID)FUN_404962c4(uVar11);
    if (lpvBits == (LPVOID)0x0) {
      FUN_404a438c(local_30);
      return -0x7ff8fff2;
    }
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x14))();
    if ((-1 < iVar2) &&
       (iVar2 = FUN_404a23a4(*(int **)(param_1 + 8),(int)lpvBits,uVar11), iVar2 != 0)) {
      local_e8.bmiHeader.biWidth = *(LONG *)(param_1 + 0x34);
      local_e8.bmiHeader.biHeight = *(LONG *)(param_1 + 0x38);
      local_e8.bmiHeader.biXPelsPerMeter = *(LONG *)(param_1 + 0x48);
      local_e8.bmiHeader.biYPelsPerMeter = *(LONG *)(param_1 + 0x4c);
      local_e8.bmiHeader.biSize = 0x28;
      local_e8.bmiHeader.biPlanes = 1;
      local_e8.bmiHeader.biBitCount = 0x20;
      local_e8.bmiHeader.biCompression = 0;
      local_e8.bmiHeader.biSizeImage = 0;
      local_e8.bmiHeader.biClrUsed = 0;
      local_e8.bmiHeader.biClrImportant = 0;
      hdc = GetDC((HWND)0x0);
      if (hdc != (HDC)0x0) {
        pHVar3 = CreateDIBSection(hdc,&local_e8,0,(void **)(param_1 + 0x28),(HANDLE)0x0,0);
        *(HBITMAP *)(param_1 + 0x24) = pHVar3;
        if (pHVar3 != (HBITMAP)0x0) {
          if ((*(uint *)(param_1 + 0x44) == 0) || (uVar11 < *(uint *)(param_1 + 0x44))) {
            *(uint *)(param_1 + 0x44) = uVar11;
          }
          lpbmi = (BITMAPINFO *)FUN_404962c4(0x428);
          if (lpbmi != (BITMAPINFO *)0x0) {
            (lpbmi->bmiHeader).biSize = 0x28;
            pRVar9 = lpbmi->bmiColors;
            (lpbmi->bmiHeader).biWidth = *(LONG *)(param_1 + 0x34);
            (lpbmi->bmiHeader).biHeight = *(LONG *)(param_1 + 0x38);
            (lpbmi->bmiHeader).biPlanes = *(WORD *)(param_1 + 0x3c);
            (lpbmi->bmiHeader).biBitCount = *(WORD *)(param_1 + 0x3e);
            (lpbmi->bmiHeader).biCompression = *(DWORD *)(param_1 + 0x40);
            (lpbmi->bmiHeader).biSizeImage = *(DWORD *)(param_1 + 0x44);
            (lpbmi->bmiHeader).biXPelsPerMeter = *(LONG *)(param_1 + 0x48);
            pRVar6 = (RGBQUAD *)(param_1 + 0x58);
            (lpbmi->bmiHeader).biYPelsPerMeter = *(LONG *)(param_1 + 0x4c);
            iVar2 = 0x100;
            (lpbmi->bmiHeader).biClrUsed = *(DWORD *)(param_1 + 0x50);
            (lpbmi->bmiHeader).biClrImportant = *(DWORD *)(param_1 + 0x54);
            do {
              RVar4 = *pRVar6;
              pRVar6 = pRVar6 + 1;
              *pRVar9 = RVar4;
              iVar2 = iVar2 + -1;
              pRVar9 = pRVar9 + 1;
            } while (iVar2 != 0);
            hdc_00 = CreateCompatibleDC((HDC)0x0);
            h = SelectObject(hdc_00,*(HGDIOBJ *)(param_1 + 0x24));
            iVar2 = SetDIBitsToDevice(hdc_00,0,0,local_a4,local_a0,0,0,0,local_a0,lpvBits,lpbmi,0);
            SelectObject(hdc_00,h);
            DeleteDC(hdc_00);
            FUN_404962ec(lpbmi);
            FUN_404962ec(lpvBits);
            ReleaseDC((HWND)0x0,hdc);
            if (iVar2 != 0) {
              FUN_404a438c(local_30);
              return 0;
            }
            DeleteObject(*(HGDIOBJ *)(param_1 + 0x24));
            *(undefined4 *)(param_1 + 0x24) = 0;
            *(void **)(param_1 + 0x28) = (void *)0x0;
            goto LAB_404a2be0;
          }
          DeleteObject(*(HGDIOBJ *)(param_1 + 0x24));
        }
        FUN_404962ec(lpvBits);
        ReleaseDC((HWND)0x0,hdc);
        goto LAB_404a2be0;
      }
    }
    FUN_404962ec(lpvBits);
  }
LAB_404a2be0:
  FUN_404a438c(local_30);
  return -0x7fffbffb;
}



/* 404a2f90 FUN_404a2f90 */

/* Boundary evidence: original MIPS .pdata 404a2f90..404a3017. Semantic name remains unreviewed. */

undefined4 FUN_404a2f90(int param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_3 == (undefined4 *)0x0) || (iVar1 = memcmp(param_2,&DAT_4048132c,0x10), iVar1 != 0)) {
    uVar2 = 0x80070057;
  }
  else if (*(int *)(param_1 + 4) == 0x446d4231) {
    *param_3 = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 404a3018 FUN_404a3018 */

/* Boundary evidence: original MIPS .pdata 404a3018..404a3097. Semantic name remains unreviewed. */

undefined4 FUN_404a3018(int param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) == 0x446d4231) {
    if (((param_2 == (void *)0x0) || (iVar2 = memcmp(param_2,&DAT_4048132c,0x10), iVar2 != 0)) ||
       (1 < param_3)) {
      uVar1 = 0x80070057;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80004005;
  }
  return uVar1;
}



/* 404a30c0 FUN_404a30c0 */

/* Boundary evidence: original MIPS .pdata 404a30c0..404a3123. Semantic name remains unreviewed. */

void FUN_404a30c0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40484dec;
  if (param_1[0x118] != 0) {
    FUN_404a2840((int)param_1);
  }
  if ((LPVOID)param_1[4] != (LPVOID)0x0) {
    FUN_404962ec((LPVOID)param_1[4]);
    param_1[4] = 0;
  }
  param_1[1] = 0x4c494146;
  return;
}



/* 404a3124 FUN_404a3124 */

/* Boundary evidence: original MIPS .pdata 404a3124..404a31bb. Semantic name remains unreviewed. */

undefined4 FUN_404a3124(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_404812bc,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40482c64,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 404a31bc FUN_404a31bc */

/* Boundary evidence: original MIPS .pdata 404a31bc..404a31d7. Semantic name remains unreviewed. */

void FUN_404a31bc(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x468));
  return;
}



/* 404a31d8 FUN_404a31d8 */

/* Boundary evidence: original MIPS .pdata 404a31d8..404a3233. Semantic name remains unreviewed. */

LONG FUN_404a31d8(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0x11a);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x60))(param_1,1);
  }
  return LVar1;
}



/* 404a3234 FUN_404a3234 */

/* Boundary evidence: original MIPS .pdata 404a3234..404a33fb. Semantic name remains unreviewed. */

undefined4 FUN_404a3234(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  ushort local_31c;
  ushort local_31a;
  undefined2 local_318;
  undefined2 local_316;
  undefined1 local_310 [768];
  
  if (*(int *)(param_1 + 0x458) != 0) {
    return 0;
  }
  FUN_404a23a4(*(int **)(param_1 + 8),param_1 + 0x14,0xe);
  iVar3 = FUN_404a23a4(*(int **)(param_1 + 8),param_1 + 0x30,4);
  if (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 0x30);
    if (iVar3 == 0x28) {
      iVar3 = FUN_404a23a4(*(int **)(param_1 + 8),param_1 + 0x34,0x24);
      if (iVar3 != 0) {
        uVar4 = FUN_404a2478(param_1);
        if ((uVar4 << 2 == 0) ||
           (iVar3 = FUN_404a23a4(*(int **)(param_1 + 8),param_1 + 0x58,uVar4 << 2), iVar3 != 0))
        goto LAB_404a33b4;
      }
    }
    else {
      if (iVar3 != 0xc) {
        *(undefined4 *)(param_1 + 4) = 0x4c494146;
        return 0x80004005;
      }
      iVar3 = FUN_404a23a4(*(int **)(param_1 + 8),(int)&local_31c,8);
      if (iVar3 != 0) {
        *(uint *)(param_1 + 0x34) = (uint)local_31c;
        *(uint *)(param_1 + 0x38) = (uint)local_31a;
        *(undefined2 *)(param_1 + 0x3c) = local_318;
        *(undefined2 *)(param_1 + 0x3e) = local_316;
        *(undefined4 *)(param_1 + 0x40) = 0;
        *(undefined4 *)(param_1 + 0x50) = 0;
        uVar4 = FUN_404a2478(param_1);
        if (uVar4 != 0) {
          iVar3 = FUN_404a23a4(*(int **)(param_1 + 8),(int)local_310,uVar4 * 3);
          if (iVar3 == 0) goto LAB_404a3284;
          if (uVar4 != 0) {
            puVar6 = local_310;
            puVar5 = (undefined1 *)(param_1 + 0x58);
            do {
              uVar1 = puVar6[1];
              uVar2 = puVar6[2];
              *puVar5 = *puVar6;
              uVar4 = uVar4 - 1;
              puVar5[1] = uVar1;
              puVar5[2] = uVar2;
              puVar5[3] = 0;
              puVar6 = puVar6 + 3;
              puVar5 = puVar5 + 4;
            } while (uVar4 != 0);
          }
        }
LAB_404a33b4:
        *(uint *)(param_1 + 0x2c) = (uint)(*(int *)(param_1 + 0x38) < 0);
        *(undefined4 *)(param_1 + 0x458) = 1;
        return 0;
      }
    }
  }
LAB_404a3284:
  *(undefined4 *)(param_1 + 4) = 0x4c494146;
  return 0x80004005;
}



/* 404a33fc FUN_404a33fc */

/* Boundary evidence: original MIPS .pdata 404a33fc..404a3613. Semantic name remains unreviewed. */

int FUN_404a33fc(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  HDC hdc;
  uint uVar3;
  undefined8 uVar4;
  
  iVar1 = FUN_404a3234(param_1);
  if (iVar1 < 0) {
    return iVar1;
  }
  *param_2 = 0xb96b3cab;
  param_2[1] = 0x11d30728;
  param_2[2] = 0x7b9d;
  param_2[3] = 0x2ef31ef8;
  uVar2 = FUN_404a2608(param_1);
  param_2[4] = uVar2;
  param_2[5] = *(undefined4 *)(param_1 + 0x34);
  uVar3 = (int)*(uint *)(param_1 + 0x38) >> 0x1f;
  param_2[6] = (*(uint *)(param_1 + 0x38) ^ uVar3) - uVar3;
  param_2[7] = *(undefined4 *)(param_1 + 0x34);
  param_2[8] = 1;
  param_2[0xe] = 0x52010;
  if ((0 < *(int *)(param_1 + 0x48)) && (0 < *(int *)(param_1 + 0x4c))) {
    uVar4 = __litodp();
    uVar4 = __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x406fc000);
    uVar4 = __dpdiv((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x40c38800);
    *(undefined8 *)(param_2 + 10) = uVar4;
    uVar4 = __litodp(*(undefined4 *)(param_1 + 0x4c));
    uVar4 = __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x406fc000);
    uVar4 = __dpdiv((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x40c38800);
    *(undefined8 *)(param_2 + 0xc) = uVar4;
    param_2[0xe] = 0x53010;
    return 0;
  }
  hdc = GetDC((HWND)0x0);
  if (hdc != (HDC)0x0) {
    iVar1 = GetDeviceCaps(hdc,0x58);
    uVar2 = __litofp(iVar1);
    uVar4 = __fptodp(uVar2);
    *(undefined8 *)(param_2 + 10) = uVar4;
    iVar1 = __led((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0);
    if (iVar1 == 0) {
      iVar1 = GetDeviceCaps(hdc,0x5a);
      uVar2 = __litofp(iVar1);
      uVar4 = __fptodp(uVar2);
      *(undefined8 *)(param_2 + 0xc) = uVar4;
      iVar1 = __led((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0);
      if (iVar1 == 0) goto LAB_404a35e8;
    }
  }
  param_2[10] = 0;
  param_2[0xb] = 0x40580000;
  param_2[0xc] = 0;
  param_2[0xd] = 0x40580000;
LAB_404a35e8:
  ReleaseDC((HWND)0x0,hdc);
  return 0;
}



/* 404a3614 FUN_404a3614 */

/* Boundary evidence: original MIPS .pdata 404a3614..404a3713. Semantic name remains unreviewed. */

int FUN_404a3614(int param_1,void *param_2,int param_3)

{
  int iVar1;
  undefined1 *_Src;
  void *_Src_00;
  size_t _Size;
  undefined1 auStack_98 [56];
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 auStack_58 [16];
  int local_48;
  uint local_20;
  
  local_20 = DAT_404bd274;
  memcpy(&local_60,&stack0x00000010,0x40);
  if (*(int *)(param_1 + 0x28) == 0) {
    _Src = auStack_58;
    memcpy(auStack_98,_Src,0x38);
    iVar1 = FUN_404a2b2c(param_1,_Src,local_60,local_5c);
    if (iVar1 < 0) {
      FUN_404a438c(local_20);
      return iVar1;
    }
  }
  _Size = *(int *)(param_1 + 0x34) * 4;
  if (*(int *)(param_1 + 0x2c) == 0) {
    _Src_00 = (void *)(((local_48 - param_3) + -1) * _Size + *(int *)(param_1 + 0x28));
  }
  else {
    _Src_00 = (void *)(_Size * param_3 + *(int *)(param_1 + 0x28));
  }
  memcpy(param_2,_Src_00,_Size);
  FUN_404a438c(local_20);
  return 0;
}



/* 404a3714 FUN_404a3714 */

/* Boundary evidence: original MIPS .pdata 404a3714..404a375f. Semantic name remains unreviewed. */

undefined4 * FUN_404a3714(undefined4 *param_1,uint param_2)

{
  FUN_404a30c0(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404a3760 FUN_404a3760 */

/* Boundary evidence: original MIPS .pdata 404a3760..404a382f. Semantic name remains unreviewed. */

int FUN_404a3760(int param_1,void *param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_98 [64];
  undefined1 auStack_58 [64];
  uint local_18;
  
  local_18 = DAT_404bd274;
  memcpy(auStack_58,&stack0x00000010,0x40);
  if (*(int *)(param_1 + 0x40) == 0) {
    memcpy(auStack_98,auStack_58,0x40);
    iVar1 = FUN_404a29dc(param_1,(int)param_2);
  }
  else if (*(int *)(param_1 + 0x40) == 3) {
    memcpy(auStack_98,auStack_58,0x40);
    iVar1 = FUN_404a3614(param_1,param_2,param_3);
  }
  else {
    iVar1 = -0x7fffbffb;
  }
  FUN_404a438c(local_18);
  return iVar1;
}



/* 404a3830 FUN_404a3830 */

/* Boundary evidence: original MIPS .pdata 404a3830..404a3887. Semantic name remains unreviewed. */

undefined4 * FUN_404a3830(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40484dec;
  param_1[0x11a] = 1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  memset(param_1 + 0xc,0,0x28);
  param_1[0x118] = 0;
  return param_1;
}



/* 404a3888 FUN_404a3888 */

/* Boundary evidence: original MIPS .pdata 404a3888..404a3ac3. Semantic name remains unreviewed. */

int FUN_404a3888(int param_1,void *param_2)

{
  int iVar1;
  void *_Src;
  int iVar2;
  SIZE_T SVar3;
  int *local_a0 [16];
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  int local_50 [3];
  int local_44;
  void *local_40;
  undefined4 local_3c;
  int local_38 [4];
  void *local_28;
  
  if (*(int *)(param_1 + 0x40) == 0) {
    iVar1 = (uint)*(ushort *)(param_1 + 0x3e) * *(int *)(param_1 + 0x34);
    iVar2 = iVar1 + 7;
    if (iVar2 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    SVar3 = (iVar2 >> 3) + 3U & 0xfffffffc;
  }
  else {
    SVar3 = *(int *)(param_1 + 0x34) << 2;
  }
  iVar1 = FUN_404a2608(param_1);
  if (iVar1 == 0) {
    iVar2 = -0x7fffbffb;
  }
  else {
    _Src = (void *)FUN_404962c4(SVar3);
    if (_Src == (void *)0x0) {
      iVar2 = -0x7ff8fff2;
    }
    else {
      if (*(int *)(param_1 + 0x2c) != 0) {
        SVar3 = -SVar3;
      }
      local_58 = *(undefined4 *)((int)param_2 + 0x14);
      local_60 = 0;
      if (*(int *)(param_1 + 0x464) < *(int *)((int)param_2 + 0x18)) {
        do {
          memcpy(local_a0,param_2,0x40);
          iVar2 = FUN_404a3760(param_1,_Src,*(int *)(param_1 + 0x464));
          if (iVar2 < 0) goto LAB_404a3a90;
          local_5c = *(int *)(param_1 + 0x464);
          local_a0[0] = local_38;
          local_54 = local_5c + 1;
          iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))
                            (*(int **)(param_1 + 0xc),&local_60,*(undefined4 *)((int)param_2 + 0x10)
                             ,1);
          if (iVar2 < 0) goto LAB_404a3a90;
          if (iVar1 == *(int *)((int)param_2 + 0x10)) {
            memcpy(local_28,_Src,
                   (*(int *)((int)param_2 + 0x10) >> 8 & 0xffU) * *(int *)((int)param_2 + 0x14) + 7
                   >> 3);
          }
          else {
            local_50[0] = local_38[0];
            local_50[1] = 1;
            local_3c = 0;
            local_50[2] = SVar3;
            local_44 = iVar1;
            local_40 = _Src;
            iVar2 = FUN_40494f0c((int)local_38,*(undefined **)(param_1 + 0x10),local_50,
                                 *(undefined **)(param_1 + 0x10));
            if (iVar2 < 0) goto LAB_404a3a90;
          }
          iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))(*(int **)(param_1 + 0xc),local_38)
          ;
          if (iVar2 < 0) goto LAB_404a3a90;
          iVar2 = *(int *)(param_1 + 0x464) + 1;
          *(int *)(param_1 + 0x464) = iVar2;
        } while (iVar2 < *(int *)((int)param_2 + 0x18));
      }
      iVar2 = 0;
LAB_404a3a90:
      FUN_404962ec(_Src);
    }
  }
  return iVar2;
}



/* 404a3ac4 FUN_404a3ac4 */

/* Boundary evidence: original MIPS .pdata 404a3ac4..404a3c7b. Semantic name remains unreviewed. */

int FUN_404a3ac4(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_c0 [4];
  undefined4 local_bc;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 auStack_58 [16];
  uint local_48;
  int local_44;
  int local_40;
  uint local_18;
  
  local_18 = DAT_404bd274;
  if ((param_1[3] == 0) || (param_1[1] != 0x446d4231)) {
    FUN_404a438c(DAT_404bd274);
    return -0x7fffbffb;
  }
  iVar1 = (**(code **)(*param_1 + 0x30))(param_1,auStack_58);
  if (iVar1 < 0) goto LAB_404a3c5c;
  if (param_1[0x117] == 0) {
    iVar1 = (**(code **)(*(int *)param_1[3] + 0xc))((int *)param_1[3],auStack_58,0);
    if (iVar1 < 0) goto LAB_404a3c5c;
    local_44 = param_1[0xd];
    uVar2 = param_1[0xe] >> 0x1f;
    local_40 = (param_1[0xe] ^ uVar2) - uVar2;
    param_1[0x117] = 1;
    iVar1 = FUN_404a2500((int)param_1);
    if (iVar1 < 0) goto LAB_404a3c5c;
  }
  uVar2 = FUN_404a2608((int)param_1);
  if (local_48 != uVar2) {
    if ((((local_48 == 0x21005) || (local_48 == 0x21808)) || (local_48 == 0x22009)) ||
       (((local_48 == 0x30101 || (local_48 == 0x30402)) || (local_48 == 0x30803)))) {
      local_60 = 0;
      local_5c = 0;
      local_bc = 0;
      iVar1 = FUN_404952c4(auStack_c0,uVar2,local_48);
      if (iVar1 == 0) {
        local_48 = 0x26200a;
      }
      FUN_40494ea4((int)auStack_c0);
    }
    else {
      local_48 = 0x26200a;
    }
  }
  iVar1 = FUN_404a3888((int)param_1,auStack_58);
LAB_404a3c5c:
  FUN_404a438c(local_18);
  return iVar1;
}



/* 404a3c7c FUN_404a3c7c */

void FUN_404a3c7c(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_40484e8c;
  param_1[1] = &PTR_LAB_40484e50;
  return;
}



/* 404a3c98 FUN_404a3c98 */

undefined4 FUN_404a3c98(void)

{
  return 0;
}



/* 404a3cb4 FUN_404a3cb4 */

/* Boundary evidence: original MIPS .pdata 404a3cb4..404a3cff. Semantic name remains unreviewed. */

undefined4 * FUN_404a3cb4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_40484e8c;
  param_1[1] = &PTR_LAB_40484e50;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404a3d00 FUN_404a3d00 */

undefined4 * FUN_404a3d00(undefined4 *param_1)

{
  param_1[1] = &PTR_LAB_40481fdc;
  *param_1 = &PTR_LAB_40484e8c;
  param_1[1] = &PTR_LAB_40484e50;
  return param_1;
}



/* 404a3d2c FUN_404a3d2c */

void FUN_404a3d2c(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_40484efc;
  param_1[1] = &PTR_LAB_40484ec0;
  return;
}



/* 404a3d68 FUN_404a3d68 */

/* Boundary evidence: original MIPS .pdata 404a3d68..404a3db3. Semantic name remains unreviewed. */

undefined4 * FUN_404a3d68(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_40484efc;
  param_1[1] = &PTR_LAB_40484ec0;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404a3db4 FUN_404a3db4 */

undefined4 * FUN_404a3db4(undefined4 *param_1)

{
  param_1[1] = &PTR_LAB_40481fdc;
  *param_1 = &PTR_LAB_40484efc;
  param_1[1] = &PTR_LAB_40484ec0;
  return param_1;
}



/* 404a3de0 FUN_404a3de0 */

void FUN_404a3de0(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_40484f80;
  param_1[1] = &PTR_LAB_40484f44;
  return;
}



/* 404a3dfc FUN_404a3dfc */

/* Boundary evidence: original MIPS .pdata 404a3dfc..404a3e47. Semantic name remains unreviewed. */

undefined4 * FUN_404a3dfc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_40484f80;
  param_1[1] = &PTR_LAB_40484f44;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404a3e48 FUN_404a3e48 */

undefined4 * FUN_404a3e48(undefined4 *param_1)

{
  param_1[1] = &PTR_LAB_40481fdc;
  *param_1 = &PTR_LAB_40484f80;
  param_1[1] = &PTR_LAB_40484f44;
  return param_1;
}



/* 404a3e74 FUN_404a3e74 */

void FUN_404a3e74(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_40484fe8;
  param_1[1] = &PTR_LAB_40484fac;
  return;
}



/* 404a3e90 FUN_404a3e90 */

/* Boundary evidence: original MIPS .pdata 404a3e90..404a3edb. Semantic name remains unreviewed. */

undefined4 * FUN_404a3e90(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_40484fe8;
  param_1[1] = &PTR_LAB_40484fac;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404a3edc FUN_404a3edc */

undefined4 * FUN_404a3edc(undefined4 *param_1)

{
  param_1[1] = &PTR_LAB_40481fdc;
  *param_1 = &PTR_LAB_40484fe8;
  param_1[1] = &PTR_LAB_40484fac;
  return param_1;
}



/* 404a40d8 FUN_404a40d8 */

/* Boundary evidence: original MIPS .pdata 404a40d8..404a4213. Semantic name remains unreviewed. */

int FUN_404a40d8(HMODULE param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  if (param_2 == 1) {
    if (DAT_404bd3bc != (code *)0x0) {
      iVar3 = (*DAT_404bd3bc)(param_1,1,param_3);
    }
    iVar2 = 0;
    if (iVar3 == 0) goto LAB_404a4188;
    FUN_404a47e0();
  }
  iVar2 = 0;
  if (iVar3 != 0) {
    bVar1 = FUN_40486bc4(param_1,param_2);
    iVar2 = CONCAT31(extraout_var,bVar1);
  }
LAB_404a4188:
  if (((param_2 == 0) && (FUN_404a4768(), iVar2 != 0)) && (DAT_404bd3bc != (code *)0x0)) {
    iVar2 = (*DAT_404bd3bc)(param_1,0,param_3);
  }
  return iVar2;
}



/* 404a4214 FUN_404a4214 */

/* Boundary evidence: original MIPS .pdata 404a4214..404a423f. Semantic name remains unreviewed. */

void FUN_404a4214(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 404a4240 entry */

/* Boundary evidence: original MIPS .pdata 404a4240..404a4297. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_404a4298();
  }
  FUN_404a40d8(param_1,param_2,param_3);
  return;
}



/* 404a4298 FUN_404a4298 */

/* Boundary evidence: original MIPS .pdata 404a4298..404a430b. Semantic name remains unreviewed. */

void FUN_404a4298(void)

{
  uint uVar1;
  
  if ((DAT_404bd274 == 0) || (DAT_404bd274 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_404bd274 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_404bd274 == 0) {
      DAT_404bd274 = 0xb064;
    }
  }
  DAT_404bd278 = ~DAT_404bd274;
  return;
}



/* 404a430c FUN_404a430c */

/* Boundary evidence: original MIPS .pdata 404a430c..404a435f. Semantic name remains unreviewed. */

void FUN_404a430c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_404a438c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 404a4360 FUN_404a4360 */

/* Boundary evidence: original MIPS .pdata 404a4360..404a438b. Semantic name remains unreviewed. */

undefined4 FUN_404a4360(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_404a430c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 404a438c FUN_404a438c */

/* Boundary evidence: original MIPS .pdata 404a438c..404a43d3. Semantic name remains unreviewed. */

void FUN_404a438c(uint param_1)

{
  if ((param_1 == DAT_404bd274) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 404a43d4 FUN_404a43d4 */

/* Boundary evidence: original MIPS .pdata 404a43d4..404a44df. Semantic name remains unreviewed. */

undefined4 FUN_404a43d4(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_404bd3b4;
  puVar3 = DAT_404bd3b0;
  iVar4 = (int)DAT_404bd3b0 - (int)DAT_404bd3b4;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_404a4418:
    param_1 = 0;
  }
  else {
    if (DAT_404bd3b4 != (void *)0x0) {
      uVar1 = _msize(DAT_404bd3b4);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_404a448c:
        if (pvVar2 == (void *)0x0) goto LAB_404a4418;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_404a448c;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_404bd3b0 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_404bd3b4 = pvVar2;
  }
  return param_1;
}



/* 404a44e0 FUN_404a44e0 */

/* Boundary evidence: original MIPS .pdata 404a44e0..404a45cb. Semantic name remains unreviewed. */

undefined4 FUN_404a44e0(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_404bd3b8 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_404bd3b8,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_404bd3b8 == (LPCRITICAL_SECTION)0x0) goto LAB_404a4584;
  }
  EnterCriticalSection(DAT_404bd3b8);
LAB_404a4584:
  uVar2 = FUN_404a43d4(param_1);
  FUN_404a45cc();
  return uVar2;
}



/* 404a45cc FUN_404a45cc */

/* Boundary evidence: original MIPS .pdata 404a45cc..404a4617. Semantic name remains unreviewed. */

void FUN_404a45cc(void)

{
  if (DAT_404bd3b8 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_404bd3b8);
  }
  return;
}



/* 404a4618 FUN_404a4618 */

/* Boundary evidence: original MIPS .pdata 404a4618..404a4647. Semantic name remains unreviewed. */

undefined4 FUN_404a4618(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_404a44e0(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 404a4648 FUN_404a4648 */

/* Boundary evidence: original MIPS .pdata 404a4648..404a4767. Semantic name remains unreviewed. */

void FUN_404a4648(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_404bd3a8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_404bd3b4;
    if (DAT_404bd3b4 != (undefined4 *)0x0) {
      while (DAT_404bd3b0 = DAT_404bd3b0 + -1, _Memory <= DAT_404bd3b0) {
        if ((code *)*DAT_404bd3b0 != (code *)0x0) {
          (*(code *)*DAT_404bd3b0)();
          _Memory = DAT_404bd3b4;
        }
      }
      free(_Memory);
      DAT_404bd3b0 = (undefined4 *)0x0;
      DAT_404bd3b4 = (undefined4 *)0x0;
    }
    FUN_404a478c((undefined4 *)&DAT_4048101c,(undefined4 *)&DAT_40481020);
  }
  FUN_404a478c((undefined4 *)&DAT_40481024,(undefined4 *)&DAT_40481028);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_404bd3b8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 404a4768 FUN_404a4768 */

/* Boundary evidence: original MIPS .pdata 404a4768..404a478b. Semantic name remains unreviewed. */

void FUN_404a4768(void)

{
  FUN_404a4648(0,0,1);
  return;
}



/* 404a478c FUN_404a478c */

/* Boundary evidence: original MIPS .pdata 404a478c..404a47df. Semantic name remains unreviewed. */

void FUN_404a478c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 404a47e0 FUN_404a47e0 */

/* Boundary evidence: original MIPS .pdata 404a47e0..404a481b. Semantic name remains unreviewed. */

void FUN_404a47e0(void)

{
  FUN_404a478c((undefined4 *)&DAT_40481014,(undefined4 *)&DAT_40481018);
  FUN_404a478c((undefined4 *)&DAT_40481000,(undefined4 *)&DAT_40481010);
  return;
}



/* 404a4a3c FUN_404a4a3c */

/* Boundary evidence: original MIPS .pdata 404a4a3c..404a4b27. Semantic name remains unreviewed. */

undefined4 * FUN_404a4a3c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_404a643c(param_1,param_2,param_3);
  *param_1 = "`LJ@HRJ@Warning";
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  *(undefined1 *)(param_1 + 0x74) = 0xff;
  *(undefined1 *)((int)param_1 + 0x1d1) = 0xff;
  *(undefined1 *)((int)param_1 + 0x1d2) = 0;
  *(undefined1 *)((int)param_1 + 0x1d3) = 0;
  param_1[0x75] = 0;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  param_1[0x7c] = 0;
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x80] = 0;
  param_1[0x81] = 0;
  param_1[0x82] = 0;
  param_1[0x83] = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
  param_1[0x87] = 0;
  param_1[0x88] = 0;
  param_1[0x89] = 0;
  param_1[0x8a] = 0;
  param_1[0x8b] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  *(undefined1 *)((int)param_1 + 0x1cf) = 0;
  *(undefined1 *)((int)param_1 + 0x1ce) = 0;
  *(undefined1 *)((int)param_1 + 0x1cd) = 0;
  *(undefined1 *)(param_1 + 0x73) = 0;
  return param_1;
}



/* 404a4b28 FUN_404a4b28 */

/* Boundary evidence: original MIPS .pdata 404a4b28..404a4c5f. Semantic name remains unreviewed. */

void FUN_404a4b28(undefined4 *param_1)

{
  *param_1 = "`LJ@HRJ@Warning";
  if (param_1[0x76] != 0) {
    FUN_404962ec((LPVOID)param_1[0x75]);
  }
  if (param_1[0x78] != 0) {
    FUN_404962ec((LPVOID)param_1[0x77]);
  }
  if (param_1[0x7a] != 0) {
    FUN_404962ec((LPVOID)param_1[0x79]);
  }
  if (param_1[0x7c] != 0) {
    FUN_404962ec((LPVOID)param_1[0x7b]);
  }
  if (param_1[0x7e] != 0) {
    FUN_404962ec((LPVOID)param_1[0x7d]);
  }
  if (param_1[0x80] != 0) {
    FUN_404962ec((LPVOID)param_1[0x7f]);
  }
  if (param_1[0x82] != 0) {
    FUN_404962ec((LPVOID)param_1[0x81]);
  }
  if (param_1[0x84] != 0) {
    FUN_404962ec((LPVOID)param_1[0x83]);
  }
  if (param_1[0x86] != 0) {
    FUN_404962ec((LPVOID)param_1[0x85]);
  }
  if (param_1[0x88] != 0) {
    FUN_404962ec((LPVOID)param_1[0x87]);
  }
  if (param_1[0x8a] != 0) {
    FUN_404962ec((LPVOID)param_1[0x89]);
  }
  if (param_1[0x8c] != 0) {
    FUN_404962ec((LPVOID)param_1[0x8b]);
  }
  if (param_1[0x8e] != 0) {
    FUN_404962ec((LPVOID)param_1[0x8d]);
  }
  FUN_404a64ec(param_1);
  return;
}



/* 404a4c60 FUN_404a4c60 */

/* Boundary evidence: original MIPS .pdata 404a4c60..404a4cab. Semantic name remains unreviewed. */

undefined4 * FUN_404a4c60(undefined4 *param_1,uint param_2)

{
  FUN_404a4b28(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404a4cac FUN_404a4cac */

/* Boundary evidence: original MIPS .pdata 404a4cac..404a4f27. Semantic name remains unreviewed. */

undefined4
FUN_404a4cac(undefined4 param_1,uint *param_2,undefined4 *param_3,SIZE_T param_4,LPVOID param_5,
            char param_6)

{
  int iVar1;
  SIZE_T SVar2;
  LPVOID pvVar3;
  LPVOID pvVar4;
  uint uVar5;
  SIZE_T local_30;
  SIZE_T local_2c;
  
  uVar5 = *param_2;
  pvVar3 = (LPVOID)*param_3;
  if (uVar5 == 0) {
    if (param_6 == '\0') {
      if ((param_4 <= param_4 + 1) &&
         (pvVar3 = (LPVOID)FUN_404962c4(param_4 + 1), pvVar3 != (void *)0x0)) {
        memcpy(pvVar3,param_5,param_4);
        SVar2 = param_4;
        goto LAB_404a4f0c;
      }
    }
    else {
      local_30 = (SIZE_T)((ulonglong)param_4 * 4);
      if (((int)((ulonglong)param_4 * 4 >> 0x20) == 0) &&
         (pvVar3 = (LPVOID)FUN_404962c4(local_30), pvVar3 != (LPVOID)0x0)) {
        iVar1 = uncompress(pvVar3,&local_30,param_5,param_4);
        SVar2 = local_30;
        while (local_30 = SVar2, iVar1 == -4) {
          FUN_404962ec(pvVar3);
          local_30 = local_30 << 1;
          pvVar3 = (LPVOID)FUN_404962c4(local_30);
          if (pvVar3 == (LPVOID)0x0) {
            return 0;
          }
          iVar1 = uncompress(pvVar3,&local_30,param_5,param_4);
          SVar2 = local_30;
        }
        if (iVar1 == 0) goto LAB_404a4f0c;
        FUN_404962ec(pvVar3);
      }
    }
  }
  else {
    *(undefined1 *)((int)pvVar3 + (uVar5 - 1)) = 0x20;
    pvVar4 = (LPVOID)0x0;
    if (param_6 != '\0') {
      local_2c = param_4 << 2;
      pvVar4 = (LPVOID)FUN_404962c4(local_2c);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      iVar1 = uncompress(pvVar4,&local_2c,param_5,param_4);
      while (iVar1 == -4) {
        FUN_404962ec(pvVar4);
        local_2c = local_2c << 1;
        pvVar4 = (LPVOID)FUN_404962c4(local_2c);
        if (pvVar4 == (LPVOID)0x0) {
          return 0;
        }
        iVar1 = uncompress(pvVar4,&local_2c,param_5,param_4);
      }
      param_4 = local_2c;
      param_5 = pvVar4;
      if (iVar1 != 0) {
        return 0;
      }
    }
    SVar2 = param_4 + uVar5;
    if (((uVar5 <= SVar2) && (SVar2 <= SVar2 + 1)) &&
       (pvVar3 = FUN_4049631c(pvVar3,SVar2 + 1), pvVar3 != (LPVOID)0x0)) {
      memcpy((void *)((int)pvVar3 + uVar5),param_5,param_4);
      if (pvVar4 != (LPVOID)0x0) {
        FUN_404962ec(pvVar4);
      }
LAB_404a4f0c:
      *(undefined1 *)((int)pvVar3 + SVar2) = 0;
      *param_2 = SVar2 + 1;
      *param_3 = pvVar3;
      return 1;
    }
  }
  return 0;
}



/* 404a4f28 FUN_404a4f28 */

/* Boundary evidence: original MIPS .pdata 404a4f28..404a5247. Semantic name remains unreviewed. */

undefined4 FUN_404a4f28(int param_1,uint param_2,char *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  SIZE_T SVar4;
  char cVar5;
  char local_70 [80];
  uint local_20;
  
  local_20 = DAT_404bd274;
  iVar1 = 0;
  uVar2 = 1;
  if (param_2 != 0) {
    do {
      if (0x4e < iVar1) goto LAB_404a4fa4;
      if (*param_3 == '\0') break;
      local_70[iVar1] = *param_3;
      iVar1 = iVar1 + 1;
      param_2 = param_2 - 1;
      param_3 = param_3 + 1;
    } while (param_2 != 0);
    if (0x4e < iVar1) goto LAB_404a4fa4;
  }
  if (param_4 == 1) {
    if (2 < param_2) {
      pcVar3 = param_3 + 2;
      SVar4 = param_2 - 2;
LAB_404a4fe8:
      iVar1 = memcmp(local_70,"Title",5);
      cVar5 = (char)param_4;
      if (iVar1 == 0) {
        uVar2 = FUN_404a4cac(param_1,(uint *)(param_1 + 0x1d8),(undefined4 *)(param_1 + 0x1d4),SVar4
                             ,pcVar3,cVar5);
      }
      else {
        iVar1 = memcmp(local_70,"Author",6);
        if (iVar1 == 0) {
          uVar2 = FUN_404a4cac(param_1,(uint *)(param_1 + 0x1e0),(undefined4 *)(param_1 + 0x1dc),
                               SVar4,pcVar3,cVar5);
        }
        else {
          iVar1 = memcmp(local_70,"Copyright",9);
          if (iVar1 == 0) {
            uVar2 = FUN_404a4cac(param_1,(uint *)(param_1 + 0x1e8),(undefined4 *)(param_1 + 0x1e4),
                                 SVar4,pcVar3,cVar5);
          }
          else {
            iVar1 = memcmp(local_70,"Description",0xb);
            if (iVar1 == 0) {
              uVar2 = FUN_404a4cac(param_1,(uint *)(param_1 + 0x1f0),(undefined4 *)(param_1 + 0x1ec)
                                   ,SVar4,pcVar3,cVar5);
            }
            else {
              iVar1 = memcmp(local_70,"CreationTime",0xc);
              if (iVar1 == 0) {
                uVar2 = FUN_404a4cac(param_1,(uint *)(param_1 + 0x1f8),(undefined4 *)(param_1 + 500)
                                     ,SVar4,pcVar3,cVar5);
              }
              else {
                iVar1 = memcmp(local_70,"Software",8);
                if (iVar1 == 0) {
                  uVar2 = FUN_404a4cac(param_1,(uint *)(param_1 + 0x200),
                                       (undefined4 *)(param_1 + 0x1fc),SVar4,pcVar3,cVar5);
                }
                else {
                  iVar1 = memcmp(local_70,"Source",6);
                  if (iVar1 == 0) {
                    uVar2 = FUN_404a4cac(param_1,(uint *)(param_1 + 0x208),
                                         (undefined4 *)(param_1 + 0x204),SVar4,pcVar3,cVar5);
                  }
                  else {
                    iVar1 = memcmp(local_70,"Comment",7);
                    if (((iVar1 == 0) || (iVar1 = memcmp(local_70,"Disclaimer",10), iVar1 == 0)) ||
                       (iVar1 = memcmp(local_70,"Warning",7), iVar1 == 0)) {
                      uVar2 = FUN_404a4cac(param_1,(uint *)(param_1 + 0x210),
                                           (undefined4 *)(param_1 + 0x20c),SVar4,pcVar3,cVar5);
                    }
                  }
                }
              }
            }
          }
        }
      }
      FUN_404a438c(local_20);
      return uVar2;
    }
  }
  else if (1 < param_2) {
    pcVar3 = param_3 + 1;
    SVar4 = param_2 - 1;
    goto LAB_404a4fe8;
  }
LAB_404a4fa4:
  FUN_404a438c(DAT_404bd274);
  return 0;
}



/* 404a5248 FUN_404a5248 */

/* Boundary evidence: original MIPS .pdata 404a5248..404a5abb. Semantic name remains unreviewed. */

undefined4 FUN_404a5248(int param_1,uint param_2,uint param_3,uint *param_4)

{
  int iVar1;
  char *pcVar2;
  void *pvVar3;
  SIZE_T SVar4;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  undefined2 *puVar9;
  int iVar10;
  int *piVar11;
  SIZE_T *pSVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  byte bStack_26;
  byte bStack_25;
  byte local_24;
  byte bStack_23;
  byte bStack_22;
  
  if (param_3 < 0x73504c55) {
    if (param_3 != 0x73504c54) {
      if (param_3 == 0x6348524d) {
        if (param_2 != 0x20) {
          return 1;
        }
        if (*(char *)(param_1 + 0x1d0) == -1) {
          *(undefined1 *)(param_1 + 0x1d3) = 1;
          piVar11 = (int *)(param_1 + 0x94);
          iVar1 = 8;
          do {
            *piVar11 = (((uint)(byte)*param_4 * 0x100 + (uint)*(byte *)((int)param_4 + 1)) * 0x100 +
                       (uint)*(byte *)((int)param_4 + 2)) * 0x100 +
                       (uint)*(byte *)((int)param_4 + 3);
            piVar11 = piVar11 + 1;
            iVar1 = iVar1 + -1;
            param_4 = param_4 + 1;
          } while (iVar1 != 0);
          return 1;
        }
        return 1;
      }
      if (param_3 == 0x67414d41) {
        if (param_2 != 4) {
          return 1;
        }
        if (*(char *)(param_1 + 0x1d0) == -1) {
          *(uint *)(param_1 + 0xbc) =
               (((uint)(byte)*param_4 * 0x100 + (uint)*(byte *)((int)param_4 + 1)) * 0x100 +
               (uint)*(byte *)((int)param_4 + 2)) * 0x100 + (uint)*(byte *)((int)param_4 + 3);
          return 1;
        }
        return 1;
      }
      if (param_3 == 0x68495354) {
        iVar1 = *(int *)(param_1 + 0x10);
        *(int *)(param_1 + 0x238) = iVar1;
        if (param_2 == 0) {
          return 0;
        }
        if (param_2 != iVar1 << 1) {
          return 0;
        }
        pvVar3 = (void *)FUN_404962c4(iVar1 << 1);
        *(void **)(param_1 + 0x234) = pvVar3;
        if (pvVar3 == (void *)0x0) {
          return 0;
        }
        memcpy(pvVar3,param_4,param_2);
        iVar1 = 0;
        if (0 < *(int *)(param_1 + 0x238)) {
          iVar10 = 0;
          do {
            puVar9 = (undefined2 *)(iVar10 + *(int *)(param_1 + 0x234));
            *puVar9 = (short)CONCAT21(*puVar9,*(undefined1 *)((int)puVar9 + 1));
            iVar1 = iVar1 + 1;
            iVar10 = iVar10 + 2;
          } while (iVar1 < *(int *)(param_1 + 0x238));
          return 1;
        }
        return 1;
      }
      if (param_3 == 0x69434350) {
        *(undefined4 *)(param_1 + 0x220) = 0;
        for (puVar8 = param_4; (param_2 != 0 && ((char)*puVar8 != '\0'));
            puVar8 = (uint *)((int)puVar8 + 1)) {
          param_2 = param_2 - 1;
          *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x220) + 1;
        }
        if (0x4f < *(uint *)(param_1 + 0x220)) {
          *(undefined4 *)(param_1 + 0x220) = 0;
          return 1;
        }
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) + 1;
        if (*(LPVOID *)(param_1 + 0x21c) != (LPVOID)0x0) {
          FUN_404962ec(*(LPVOID *)(param_1 + 0x21c));
        }
        pvVar3 = (void *)FUN_404962c4(*(SIZE_T *)(param_1 + 0x220));
        *(void **)(param_1 + 0x21c) = pvVar3;
        if (pvVar3 == (void *)0x0) {
          return 0;
        }
        memcpy(pvVar3,param_4,*(size_t *)(param_1 + 0x220));
        if (param_2 - 1 < 3) {
          return 1;
        }
        if (*(char *)((int)puVar8 + 1) != '\0') {
          return 1;
        }
        pbVar14 = (byte *)((int)puVar8 + 2);
        if ((*pbVar14 & 0xf) != 8) {
          return 1;
        }
        if (((uint)*pbVar14 * 0x100 + (uint)*(byte *)((int)puVar8 + 3)) % 0x1f == 0) {
          pSVar12 = (SIZE_T *)(param_1 + 0x218);
          if (*pSVar12 != 0) {
            return 1;
          }
          SVar4 = (param_2 - 2) * 4;
          *(uint *)(param_1 + 0xc4) = param_2 - 2;
          *pSVar12 = SVar4;
          iVar1 = FUN_404962c4(SVar4);
          *(int *)(param_1 + 0x214) = iVar1;
          if (iVar1 == 0) {
            return 0;
          }
          iVar1 = uncompress(iVar1,pSVar12,pbVar14,*(undefined4 *)(param_1 + 0xc4));
          while( true ) {
            if (iVar1 != -4) {
              if (iVar1 != 0) {
                FUN_404962ec(*(LPVOID *)(param_1 + 0x214));
                *(undefined4 *)(param_1 + 0x214) = 0;
                *pSVar12 = 0;
                return 1;
              }
              return 1;
            }
            FUN_404962ec(*(LPVOID *)(param_1 + 0x214));
            SVar4 = *pSVar12;
            *pSVar12 = SVar4 << 1;
            iVar1 = FUN_404962c4(SVar4 << 1);
            *(int *)(param_1 + 0x214) = iVar1;
            if (iVar1 == 0) break;
            iVar1 = uncompress(iVar1,pSVar12,pbVar14,*(undefined4 *)(param_1 + 0xc4));
          }
          return 0;
        }
        return 1;
      }
      if (param_3 == 0x6d734f43) {
        if (param_2 != 8) {
          return 1;
        }
        iVar1 = memcmp(param_4,"MSO aac",7);
        if (iVar1 == 0) {
          *(undefined1 *)(param_1 + 0x1d2) = *(undefined1 *)((int)param_4 + 7);
          return 1;
        }
        return 1;
      }
      if (param_3 == 0x70485973) {
        if (param_2 == 9) {
          *(uint *)(param_1 + 0xb4) =
               (((uint)(byte)*param_4 * 0x100 + (uint)*(byte *)((int)param_4 + 1)) * 0x100 +
               (uint)*(byte *)((int)param_4 + 2)) * 0x100 + (uint)*(byte *)((int)param_4 + 3);
          *(uint *)(param_1 + 0xb8) =
               (((uint)(byte)param_4[1] * 0x100 + (uint)*(byte *)((int)param_4 + 5)) * 0x100 +
               (uint)*(byte *)((int)param_4 + 6)) * 0x100 + (uint)*(byte *)((int)param_4 + 7);
          *(char *)(param_1 + 0x1d1) = (char)param_4[2];
          return 1;
        }
        return 1;
      }
      if (param_3 != 0x73424954) {
        return 1;
      }
      if (4 < param_2) {
        return 1;
      }
      pvVar3 = (void *)(param_1 + 0x1cc);
      goto LAB_404a5a2c;
    }
  }
  else {
    if (param_3 == 0x73524742) {
      if (param_2 != 1) {
        return 1;
      }
      uVar5 = (undefined1)*param_4;
LAB_404a5a48:
      *(undefined4 *)(param_1 + 0x9c) = 64000;
      *(undefined4 *)(param_1 + 0x98) = 0x8084;
      *(undefined4 *)(param_1 + 0x94) = 0x7a26;
      *(undefined4 *)(param_1 + 0xbc) = 0xb18f;
      *(undefined1 *)(param_1 + 0x1d0) = uVar5;
      *(undefined4 *)(param_1 + 0xb0) = 6000;
      *(undefined4 *)(param_1 + 0xac) = 15000;
      *(undefined4 *)(param_1 + 0xa8) = 60000;
      *(undefined4 *)(param_1 + 0xa4) = 30000;
      *(undefined4 *)(param_1 + 0xa0) = 33000;
      return 1;
    }
    if (param_3 != 0x7370414c) {
      if (param_3 != 0x73724742) {
        if (param_3 == 0x74455874) {
          iVar1 = 0;
        }
        else {
          if (param_3 == 0x74494d45) {
            uVar6 = *param_4;
            uVar7 = param_4[1];
            uVar13 = (uVar6 & 0xff) << 8 | uVar6 >> 8 & 0xff;
            if (*(LPVOID *)(param_1 + 0x224) != (LPVOID)0x0) {
              FUN_404962ec(*(LPVOID *)(param_1 + 0x224));
            }
            *(undefined4 *)(param_1 + 0x228) = 0x14;
            pcVar2 = (char *)FUN_404962c4(0x14);
            *(char **)(param_1 + 0x224) = pcVar2;
            if (pcVar2 == (char *)0x0) {
              return 0;
            }
            uVar15 = uVar13 % 1000;
            *pcVar2 = (char)(uVar13 / 1000) + '0';
            uVar13 = uVar15 % 100;
            *(char *)(*(int *)(param_1 + 0x224) + 1) = (char)(uVar15 / 100) + '0';
            *(char *)(*(int *)(param_1 + 0x224) + 2) = (char)(uVar13 / 10) + '0';
            *(char *)(*(int *)(param_1 + 0x224) + 3) = (char)(uVar13 % 10) + '0';
            *(undefined1 *)(*(int *)(param_1 + 0x224) + 4) = 0x3a;
            bStack_26 = (byte)(uVar6 >> 0x10);
            *(byte *)(*(int *)(param_1 + 0x224) + 5) = bStack_26 / 10 + 0x30;
            bStack_25 = (byte)(uVar6 >> 0x18);
            *(byte *)(*(int *)(param_1 + 0x224) + 6) = bStack_26 % 10 + 0x30;
            *(undefined1 *)(*(int *)(param_1 + 0x224) + 7) = 0x3a;
            *(byte *)(*(int *)(param_1 + 0x224) + 8) = bStack_25 / 10 + 0x30;
            *(byte *)(*(int *)(param_1 + 0x224) + 9) = bStack_25 % 10 + 0x30;
            *(undefined1 *)(*(int *)(param_1 + 0x224) + 10) = 0x20;
            local_24 = (byte)uVar7;
            *(byte *)(*(int *)(param_1 + 0x224) + 0xb) = local_24 / 10 + 0x30;
            bStack_23 = (byte)(uVar7 >> 8);
            *(byte *)(*(int *)(param_1 + 0x224) + 0xc) = local_24 % 10 + 0x30;
            *(undefined1 *)(*(int *)(param_1 + 0x224) + 0xd) = 0x3a;
            *(byte *)(*(int *)(param_1 + 0x224) + 0xe) = bStack_23 / 10 + 0x30;
            *(byte *)(*(int *)(param_1 + 0x224) + 0xf) = bStack_23 % 10 + 0x30;
            bStack_22 = (byte)(uVar7 >> 0x10);
            *(undefined1 *)(*(int *)(param_1 + 0x224) + 0x10) = 0x3a;
            *(byte *)(*(int *)(param_1 + 0x224) + 0x11) = bStack_22 / 10 + 0x30;
            *(byte *)(*(int *)(param_1 + 0x224) + 0x12) = bStack_22 % 10 + 0x30;
            *(undefined1 *)(*(int *)(param_1 + 0x224) + 0x13) = 0;
            return 1;
          }
          if (param_3 == 0x74524e53) {
            if (0x100 < param_2) {
              param_2 = 0x100;
            }
            *(uint *)(param_1 + 200) = param_2;
            pvVar3 = (void *)(param_1 + 0xcc);
            goto LAB_404a5a2c;
          }
          if (param_3 != 0x7a545874) {
            return 1;
          }
          iVar1 = 1;
        }
        FUN_404a4f28(param_1,param_2,(char *)param_4,iVar1);
        return 1;
      }
      if (param_2 != 0x16) {
        return 1;
      }
      iVar1 = memcmp(param_4,"PNG group 1996-09-14",0x15);
      if (iVar1 != 0) {
        return 1;
      }
      uVar5 = *(undefined1 *)((int)param_4 + 0x15);
      goto LAB_404a5a48;
    }
  }
  *(undefined4 *)(param_1 + 0x230) = 0;
  for (puVar8 = param_4; (param_2 != 0 && ((char)*puVar8 != '\0'));
      puVar8 = (uint *)((int)puVar8 + 1)) {
    param_2 = param_2 - 1;
    *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) + 1;
  }
  if (0x4f < *(uint *)(param_1 + 0x230)) {
    *(undefined4 *)(param_1 + 0x230) = 0;
    return 1;
  }
  *(uint *)(param_1 + 0x230) = *(uint *)(param_1 + 0x230) + 1;
  if (*(LPVOID *)(param_1 + 0x22c) != (LPVOID)0x0) {
    FUN_404962ec(*(LPVOID *)(param_1 + 0x22c));
  }
  pvVar3 = (void *)FUN_404962c4(*(SIZE_T *)(param_1 + 0x230));
  *(void **)(param_1 + 0x22c) = pvVar3;
  if (pvVar3 == (void *)0x0) {
    return 0;
  }
  param_2 = *(size_t *)(param_1 + 0x230);
LAB_404a5a2c:
  memcpy(pvVar3,param_4,param_2);
  return 1;
}



/* 404a5abc FUN_404a5abc */

int FUN_404a5abc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (param_4 != 2) {
    if (param_4 != 3) {
      if (param_4 != 4) {
        if (param_4 != 5) {
          if (param_4 != 6) {
            if (param_4 != 7) {
              return 0;
            }
            iVar1 = (((param_1 >> 1) * param_3 + 7 >> 3) + (uint)(0 < param_1 >> 1)) *
                    (param_2 + 1 >> 1);
          }
          iVar2 = param_1 + 1 >> 1;
          iVar1 = ((iVar2 * param_3 + 7 >> 3) + (uint)(0 < iVar2)) * (param_2 + 1 >> 2) + iVar1;
        }
        iVar2 = param_1 + 1 >> 2;
        iVar1 = ((iVar2 * param_3 + 7 >> 3) + (uint)(0 < iVar2)) * (param_2 + 3 >> 2) + iVar1;
      }
      iVar2 = param_1 + 3 >> 2;
      iVar1 = ((iVar2 * param_3 + 7 >> 3) + (uint)(0 < iVar2)) * (param_2 + 3 >> 3) + iVar1;
    }
    iVar2 = param_1 + 3 >> 3;
    iVar1 = ((iVar2 * param_3 + 7 >> 3) + (uint)(0 < iVar2)) * (param_2 + 7 >> 3) + iVar1;
  }
  iVar2 = param_1 + 7 >> 3;
  return ((iVar2 * param_3 + 7 >> 3) + (uint)(0 < iVar2)) * (param_2 + 7 >> 3) + iVar1;
}



/* 404a5c70 FUN_404a5c70 */

/* Boundary evidence: original MIPS .pdata 404a5c70..404a5cc7. Semantic name remains unreviewed. */

bool FUN_404a5c70(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x34) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  iVar1 = FUN_404a6f68(param_1,*(int *)(param_1 + 0x20),0);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  return iVar1 != 0;
}



/* 404a5cc8 FUN_404a5cc8 */

/* Boundary evidence: original MIPS .pdata 404a5cc8..404a5cf7. Semantic name remains unreviewed. */

void FUN_404a5cc8(int param_1)

{
  FUN_404a6f3c(param_1);
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return;
}



/* 404a5cf8 FUN_404a5cf8 */

/* Boundary evidence: original MIPS .pdata 404a5cf8..404a5f97. Semantic name remains unreviewed. */

undefined4 FUN_404a5cf8(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  size_t sVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  
  iVar17 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24);
  bVar1 = *(byte *)(iVar17 + 0x11);
  iVar16 = *(int *)(param_1 + 0x38) * 2;
  sVar9 = FUN_404a5abc((((uint)*(byte *)(iVar17 + 8) * 0x100 + (uint)*(byte *)(iVar17 + 9)) * 0x100
                       + (uint)*(byte *)(iVar17 + 10)) * 0x100 + (uint)*(byte *)(iVar17 + 0xb),
                       (((uint)*(byte *)(iVar17 + 0xc) * 0x100 + (uint)*(byte *)(iVar17 + 0xd)) *
                        0x100 + (uint)*(byte *)(iVar17 + 0xe)) * 0x100 +
                       (uint)*(byte *)(iVar17 + 0xf),
                       ((int)((bVar1 >> 2 & 1) + (bVar1 & 2) + 1) >> (bVar1 & 1)) *
                       (uint)*(byte *)(iVar17 + 0x10),7);
  FUN_404a6e9c(param_1,(void *)(iVar16 + *(int *)(param_1 + 0x30)),sVar9);
  iVar13 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24);
  bVar1 = *(byte *)(iVar13 + 0x11);
  bVar2 = *(byte *)(iVar13 + 8);
  bVar3 = *(byte *)(iVar13 + 9);
  bVar4 = *(byte *)(iVar13 + 0xc);
  iVar17 = ((int)((bVar1 >> 2 & 1) + (bVar1 & 2) + 1) >> (bVar1 & 1)) *
           (uint)*(byte *)(iVar13 + 0x10);
  bVar1 = *(byte *)(iVar13 + 10);
  bVar5 = *(byte *)(iVar13 + 0xd);
  bVar6 = *(byte *)(iVar13 + 0xb);
  bVar7 = *(byte *)(iVar13 + 0xe);
  bVar8 = *(byte *)(iVar13 + 0xf);
  iVar13 = 1;
  iVar14 = 7;
  do {
    iVar10 = (**(code **)(**(int **)(param_1 + 4) + 4))();
    if (iVar10 == 0) {
      return 0;
    }
    iVar10 = (int)((7 >> (iVar13 >> 1 & 0x1fU)) +
                  (((uint)bVar2 * 0x100 + (uint)bVar3) * 0x100 + (uint)bVar1) * 0x100 + (uint)bVar6)
             >> (iVar14 >> 1 & 0x1fU);
    uVar15 = (iVar10 * iVar17 + 7 >> 3) + (uint)(0 < iVar10);
    if (0 < (int)uVar15) {
      pbVar11 = (byte *)0x0;
      iVar10 = iVar13 - (uint)(1 < iVar13);
      iVar10 = ((int)((7 >> (iVar10 >> 1 & 0x1fU)) +
                     (((uint)bVar4 * 0x100 + (uint)bVar5) * 0x100 + (uint)bVar7) * 0x100 +
                     (uint)bVar8) >> (8 - iVar10 >> 1 & 0x1fU)) + -1;
      if (-1 < iVar10) {
        iVar12 = *(int *)(param_1 + 0x30);
        do {
          FUN_404a70ec(param_1,(char *)(iVar12 + iVar16),pbVar11,uVar15,iVar17);
          iVar12 = *(int *)(param_1 + 0x30);
          pbVar11 = (byte *)(iVar12 + iVar16);
          iVar10 = iVar10 + -1;
          iVar16 = uVar15 + iVar16;
        } while (-1 < iVar10);
      }
    }
    iVar14 = iVar14 + -1;
    iVar13 = iVar13 + 1;
  } while (1 < iVar14);
  return 1;
}



/* 404a5f98 FUN_404a5f98 */

/* Boundary evidence: original MIPS .pdata 404a5f98..404a6117. Semantic name remains unreviewed. */

int FUN_404a5f98(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x1c);
  iVar2 = 0;
  if (*(char *)(iVar5 + 0x14) == '\x01') {
    bVar1 = *(byte *)(iVar5 + 0x11);
    iVar2 = FUN_404a5abc((((uint)*(byte *)(iVar5 + 8) * 0x100 + (uint)*(byte *)(iVar5 + 9)) * 0x100
                         + (uint)*(byte *)(iVar5 + 10)) * 0x100 + (uint)*(byte *)(iVar5 + 0xb),
                         (((uint)*(byte *)(iVar5 + 0xc) * 0x100 + (uint)*(byte *)(iVar5 + 0xd)) *
                          0x100 + (uint)*(byte *)(iVar5 + 0xe)) * 0x100 +
                         (uint)*(byte *)(iVar5 + 0xf),
                         ((int)((bVar1 >> 2 & 1) + (bVar1 & 2) + 1) >> (bVar1 & 1)) *
                         (uint)*(byte *)(iVar5 + 0x10),7);
  }
  bVar1 = *(byte *)(iVar5 + 0x11);
  iVar4 = (((uint)*(byte *)(iVar5 + 8) * 0x100 + (uint)*(byte *)(iVar5 + 9)) * 0x100 +
          (uint)*(byte *)(iVar5 + 10)) * 0x100 + (uint)*(byte *)(iVar5 + 0xb);
  uVar3 = ((int)(((int)((bVar1 >> 2 & 1) + (bVar1 & 2) + 1) >> (bVar1 & 1)) *
                 (uint)*(byte *)(iVar5 + 0x10) * iVar4 + 7) >> 3) + (uint)(0 < iVar4) + 7 &
          0xfffffff8;
  *(uint *)(param_1 + 0x38) = uVar3;
  return uVar3 * 2 + iVar2;
}



/* 404a6118 FUN_404a6118 */

/* Boundary evidence: original MIPS .pdata 404a6118..404a63a7. Semantic name remains unreviewed. */

byte * FUN_404a6118(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  if ((((*(char *)(param_1 + 0x7c) == '\0') || (*(int *)(param_1 + 0x30) == 0)) ||
      (iVar3 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24),
      (((uint)*(byte *)(iVar3 + 0xc) * 0x100 + (uint)*(byte *)(iVar3 + 0xd)) * 0x100 +
      (uint)*(byte *)(iVar3 + 0xe)) * 0x100 + (uint)*(byte *)(iVar3 + 0xf) <=
      *(uint *)(param_1 + 0x3c))) ||
     (iVar3 = (**(code **)(**(int **)(param_1 + 4) + 4))(), iVar3 == 0)) {
LAB_404a6380:
    pbVar7 = (byte *)0x0;
  }
  else {
    pbVar6 = *(byte **)(param_1 + 0x30);
    iVar3 = *(int *)(param_1 + 0x38);
    pbVar7 = pbVar6;
    if (*(char *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24) + 0x14) == '\x01') {
      if ((*(int *)(param_1 + 0x3c) == 0) && (iVar4 = FUN_404a5cf8(param_1), iVar4 == 0))
      goto LAB_404a6380;
      uVar2 = *(uint *)(param_1 + 0x3c);
      if ((uVar2 & 2) == 0) {
        pbVar6 = pbVar6 + iVar3;
      }
      else {
        pbVar7 = pbVar6 + iVar3;
      }
      if ((uVar2 & 1) == 0) {
        FUN_404a89b8(param_1,pbVar7,uVar2);
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
        return pbVar7;
      }
      if (uVar2 == 1) goto LAB_404a6260;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x3c);
      if ((uVar2 & 1) == 0) {
        pbVar6 = pbVar6 + iVar3;
      }
      else {
        pbVar7 = pbVar6 + iVar3;
      }
      if (uVar2 == 0) {
LAB_404a6260:
        pbVar6 = (byte *)0x0;
      }
    }
    iVar3 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24);
    *(uint *)(param_1 + 0x3c) = uVar2 + 1;
    bVar1 = *(byte *)(iVar3 + 0x11);
    iVar4 = (((uint)*(byte *)(iVar3 + 8) * 0x100 + (uint)*(byte *)(iVar3 + 9)) * 0x100 +
            (uint)*(byte *)(iVar3 + 10)) * 0x100 + (uint)*(byte *)(iVar3 + 0xb);
    sVar5 = ((int)(((int)((bVar1 >> 2 & 1) + (bVar1 & 2) + 1) >> (bVar1 & 1)) *
                   (uint)*(byte *)(iVar3 + 0x10) * iVar4 + 7) >> 3) + (uint)(0 < iVar4);
    FUN_404a6e9c(param_1,pbVar7,sVar5);
    iVar3 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24);
    bVar1 = *(byte *)(iVar3 + 0x11);
    FUN_404a70ec(param_1,(char *)pbVar7,pbVar6,sVar5,
                 ((int)((bVar1 >> 2 & 1) + (bVar1 & 2) + 1) >> (bVar1 & 1)) *
                 (uint)*(byte *)(iVar3 + 0x10));
    pbVar7 = pbVar7 + 1;
  }
  return pbVar7;
}



/* 404a63a8 FUN_404a63a8 */

/* Boundary evidence: original MIPS .pdata 404a63a8..404a63eb. Semantic name remains unreviewed. */

undefined4 * FUN_404a63a8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_404850c4;
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404a63ec FUN_404a63ec */

/* Boundary evidence: original MIPS .pdata 404a63ec..404a643b. Semantic name remains unreviewed. */

undefined4 FUN_404a63ec(int param_1)

{
  int iVar1;
  
  if (((*(void **)(param_1 + 0x24) != (void *)0x0) && (7 < *(uint *)(param_1 + 0x28))) &&
     (iVar1 = memcmp(&DAT_4048537c,*(void **)(param_1 + 0x24),8), iVar1 == 0)) {
    return 1;
  }
  return 0;
}



/* 404a643c FUN_404a643c */

/* Boundary evidence: original MIPS .pdata 404a643c..404a64eb. Semantic name remains unreviewed. */

undefined4 * FUN_404a643c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[1] = param_2;
  param_1[0xb] = param_3;
  *param_1 = &PTR_FUN_404850c8;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  *(undefined1 *)(param_1 + 0x1f) = 0;
  *(undefined1 *)((int)param_1 + 0x7d) = 0;
  *(undefined1 *)((int)param_1 + 0x7e) = 0;
  *(undefined1 *)((int)param_1 + 0x7f) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  memset(param_1 + 0x11,0,0x38);
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = param_1;
  (**(code **)(*(int *)param_1[0xb] + 4))();
  return param_1;
}



/* 404a64ec FUN_404a64ec */

/* Boundary evidence: original MIPS .pdata 404a64ec..404a655b. Semantic name remains unreviewed. */

void FUN_404a64ec(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_404850c8;
  FUN_404a5cc8((int)param_1);
  if ((LPVOID)param_1[9] != (LPVOID)0x0) {
    FUN_404962ec((LPVOID)param_1[9]);
  }
  if ((int *)param_1[0xb] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xb] + 8))();
  }
  *param_1 = &PTR_FUN_404850c4;
  return;
}



/* 404a655c FUN_404a655c */

/* Boundary evidence: original MIPS .pdata 404a655c..404a69cb. Semantic name remains unreviewed. */

void FUN_404a655c(int *param_1,SIZE_T param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  SIZE_T *pSVar7;
  undefined4 uVar8;
  SIZE_T local_40;
  int local_3c;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  uint local_30;
  
  local_30 = DAT_404bd274;
  iVar1 = (**(code **)(*(int *)param_1[0xb] + 0x14))((int *)param_1[0xb],param_2,param_2,0,0,0);
  if ((-1 < iVar1) &&
     (local_40 = param_2, iVar1 = FUN_404901e4((int *)param_1[0xb],(int)&local_38,8,1,&local_3c),
     -1 < iVar1)) {
    while (local_3c != 0) {
      uVar2 = (((uint)local_38 * 0x100 + (uint)local_37) * 0x100 + (uint)local_36) * 0x100 +
              (uint)local_35;
      if (0x7fffffff < uVar2) goto LAB_404a66b0;
      local_40 = uVar2 + local_3c + local_40 + 4;
      if ((((uint)local_34 * 0x100 + (uint)local_33) * 0x100 + (uint)local_32) * 0x100 +
          (uint)local_31 == 0x49454e44) break;
      iVar1 = FUN_4049035c((int *)param_1[0xb],uVar2 + 4,1);
      if ((iVar1 < 0) ||
         (iVar1 = FUN_404901e4((int *)param_1[0xb],(int)&local_38,8,1,&local_3c), iVar1 < 0))
      goto LAB_404a66b0;
    }
    iVar1 = FUN_404962c4(local_40);
    param_1[9] = iVar1;
    param_1[10] = local_40;
    param_1[7] = local_40;
    if (iVar1 != 0) {
      uVar8 = 0;
      iVar1 = (**(code **)(*(int *)param_1[0xb] + 0x14))();
      if (-1 < iVar1) {
        pSVar7 = &local_40;
        iVar1 = FUN_404901e4((int *)param_1[0xb],param_1[9],local_40,1,(int *)pSVar7);
        if (-1 < iVar1) {
          (**(code **)(*(int *)param_1[0xb] + 8))();
          uVar2 = param_2 + 8;
          param_1[0xb] = 0;
          if (uVar2 < (uint)param_1[10]) goto LAB_404a67a0;
          goto LAB_404a66d0;
        }
      }
    }
  }
LAB_404a66b0:
  *(undefined1 *)(param_1 + 0x20) = 1;
  if ((int *)param_1[0xb] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xb] + 8))();
    param_1[0xb] = 0;
  }
  goto LAB_404a66d0;
  while( true ) {
    param_2 = uVar2 + uVar5 + 4;
    uVar2 = uVar2 + uVar5 + 0xc;
    if ((uint)param_1[10] <= uVar2) break;
LAB_404a67a0:
    uVar3 = param_1[10];
    pbVar6 = (byte *)(param_1[9] + param_2);
    uVar5 = (((uint)*pbVar6 * 0x100 + (uint)pbVar6[1]) * 0x100 + (uint)pbVar6[2]) * 0x100 +
            (uint)pbVar6[3];
    uVar4 = (((uint)pbVar6[4] * 0x100 + (uint)pbVar6[5]) * 0x100 + (uint)pbVar6[6]) * 0x100 +
            (uint)pbVar6[7];
    if (uVar3 < param_2 + uVar5 + 0xc) {
      if (uVar4 != 0x49444154) break;
      if (uVar3 < param_2 + uVar5 + 8) {
        uVar5 = (uVar3 - param_2) - 8;
      }
      param_1[2] = 0;
    }
    else {
      param_1[2] = (((uint)pbVar6[uVar5 + 8] * 0x100 + (uint)pbVar6[uVar5 + 9]) * 0x100 +
                   (uint)pbVar6[uVar5 + 10]) * 0x100 + (uint)pbVar6[uVar5 + 0xb];
    }
    if (uVar4 == 0x49444154) {
      if ((param_1[8] == 0) && (uVar5 != 0)) {
        param_1[8] = uVar2 - 8;
      }
    }
    else {
      if (uVar4 == 0x49454e44) break;
      if (uVar4 == 0x49484452) {
        if ((uVar3 <= (uint)param_1[7]) && (0xc < uVar5)) {
          param_1[7] = uVar2 - 8;
        }
      }
      else if (uVar4 == 0x504c5445) {
        if ((param_1[3] == 0) && (2 < uVar5)) {
          param_1[3] = param_1[9] + uVar2;
          param_1[4] = uVar5 / 3;
        }
      }
      else if (uVar4 == 0x74455874) {
        if (param_1[5] == 0) {
          param_1[5] = uVar2 - 8;
        }
        param_1[6] = uVar2 - 8;
      }
      else if (((uVar4 & 0x20000000) == 0) &&
              (iVar1 = (**(code **)(*(int *)param_1[1] + 8))
                                 ((int *)param_1[1],0,1,uVar4,pSVar7,uVar8), iVar1 == 0)) {
        *(undefined1 *)((int)param_1 + 0x7f) = 1;
      }
    }
    iVar1 = (**(code **)(*param_1 + 4))(param_1,uVar5,uVar4,uVar2 + param_1[9]);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x20) = 1;
      break;
    }
  }
LAB_404a66d0:
  FUN_404a438c(local_30);
  return;
}



/* 404a69cc FUN_404a69cc */

/* Boundary evidence: original MIPS .pdata 404a69cc..404a6a17. Semantic name remains unreviewed. */

undefined4 * FUN_404a69cc(undefined4 *param_1,uint param_2)

{
  FUN_404a64ec(param_1);
  if ((param_2 & 1) != 0) {
    FUN_404962ec(param_1);
  }
  return param_1;
}



/* 404a6a18 FUN_404a6a18 */

/* Boundary evidence: original MIPS .pdata 404a6a18..404a6caf. Semantic name remains unreviewed. */

undefined4 FUN_404a6a18(int *param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  SIZE_T SVar4;
  
  if (param_1[0xb] == 0) {
    *(undefined1 *)((int)param_1 + 0x7e) = 1;
  }
  else {
    SVar4 = 8;
    iVar3 = FUN_404962c4(8);
    param_1[9] = iVar3;
    if (iVar3 != 0) {
      param_1[10] = 8;
      iVar3 = FUN_404901e4((int *)param_1[0xb],iVar3,8,1,(int *)0x0);
      if (-1 < iVar3) {
        iVar3 = FUN_404a63ec((int)param_1);
        if (iVar3 == 0) {
          SVar4 = 0;
        }
        FUN_404962ec((LPVOID)param_1[9]);
        param_1[9] = 0;
        FUN_404a655c(param_1,SVar4);
        if ((((uint)param_1[10] <= (uint)param_1[7]) || ((char)param_1[0x20] != '\0')) ||
           (bVar2 = true, param_1[8] == 0)) {
          bVar2 = false;
        }
        if (bVar2) {
          iVar3 = param_1[7] + param_1[9];
          if (0xffff < (((uint)*(byte *)(iVar3 + 8) * 0x100 + (uint)*(byte *)(iVar3 + 9)) * 0x100 +
                       (uint)*(byte *)(iVar3 + 10)) * 0x100 + (uint)*(byte *)(iVar3 + 0xb)) {
            *(undefined1 *)(param_1 + 0x20) = 1;
          }
          if (0xffff < (((uint)*(byte *)(iVar3 + 0xc) * 0x100 + (uint)*(byte *)(iVar3 + 0xd)) *
                        0x100 + (uint)*(byte *)(iVar3 + 0xe)) * 0x100 + (uint)*(byte *)(iVar3 + 0xf)
             ) {
            *(undefined1 *)(param_1 + 0x20) = 1;
          }
          if (0x4000000 <
              ((((uint)*(byte *)(iVar3 + 0xc) * 0x100 + (uint)*(byte *)(iVar3 + 0xd)) * 0x100 +
               (uint)*(byte *)(iVar3 + 0xe)) * 0x100 + (uint)*(byte *)(iVar3 + 0xf)) *
              ((((uint)*(byte *)(iVar3 + 8) * 0x100 + (uint)*(byte *)(iVar3 + 9)) * 0x100 +
               (uint)*(byte *)(iVar3 + 10)) * 0x100 + (uint)*(byte *)(iVar3 + 0xb))) {
            *(undefined1 *)(param_1 + 0x20) = 1;
          }
          if ((*(byte *)(iVar3 + 0x10) - 1 & *(byte *)(iVar3 + 0x10)) == 0) {
            bVar1 = *(byte *)(iVar3 + 0x11);
            if (((int)(uint)*(byte *)(iVar3 + 0x10) <= (int)((bVar1 & 1) * -8 + 0x10)) &&
               (((bVar1 & 1) == 0 || ((bVar1 == 3 && (param_1[3] != 0)))))) {
              if (((char)param_1[0x20] == '\0') && (*(char *)((int)param_1 + 0x7f) == '\0')) {
                return 1;
              }
              return 0;
            }
          }
          *(undefined1 *)(param_1 + 0x20) = 1;
        }
        (**(code **)(*(int *)param_1[1] + 8))((int *)param_1[1],1,0,0x49484452);
      }
      *(undefined1 *)((int)param_1 + 0x7e) = 1;
      if ((LPVOID)param_1[9] != (LPVOID)0x0) {
        FUN_404962ec((LPVOID)param_1[9]);
        param_1[9] = 0;
      }
    }
  }
  return 0;
}



/* 404a6cb0 FUN_404a6cb0 */

/* Boundary evidence: original MIPS .pdata 404a6cb0..404a6e9b. Semantic name remains unreviewed. */

int FUN_404a6cb0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  
  if ((*(char *)(param_1 + 0x7d) == '\0') && (*(char *)(param_1 + 0x7e) == '\0')) {
    *(undefined4 *)(param_1 + 0x50) = param_2;
    *(int *)(param_1 + 0x54) = param_3;
    while ((iVar1 = inflate((int *)(param_1 + 0x44),1), iVar1 == -5 ||
           (iVar2 = FUN_404a8a6c(param_1,iVar1), iVar2 != 0))) {
      if (iVar1 == 1) {
        *(undefined1 *)(param_1 + 0x7d) = 1;
      }
      iVar1 = param_3 - *(int *)(param_1 + 0x54);
      if (0 < iVar1) {
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x54) = 0;
        return iVar1;
      }
      if ((*(int *)(param_1 + 0x48) != 0) || (param_4 == 0)) break;
      iVar2 = *(int *)(param_1 + 0x40);
      iVar1 = *(int *)(param_1 + 0x24);
      uVar3 = *(uint *)(param_1 + 0x28);
      pbVar7 = (byte *)(iVar1 + iVar2);
      iVar8 = (((uint)*pbVar7 * 0x100 + (uint)pbVar7[1]) * 0x100 + (uint)pbVar7[2]) * 0x100 +
              (uint)pbVar7[3];
      while( true ) {
        iVar4 = iVar8 + iVar2;
        iVar2 = iVar4 + 0xc;
        if (uVar3 <= iVar4 + 0x14U) goto LAB_404a6e1c;
        pbVar7 = (byte *)(iVar1 + iVar2);
        iVar8 = (((uint)*pbVar7 * 0x100 + (uint)pbVar7[1]) * 0x100 + (uint)pbVar7[2]) * 0x100 +
                (uint)pbVar7[3];
        iVar5 = (((uint)pbVar7[4] * 0x100 + (uint)pbVar7[5]) * 0x100 + (uint)pbVar7[6]) * 0x100 +
                (uint)pbVar7[7];
        if (iVar5 == param_4) break;
        if (iVar5 == 0x49454e44) goto LAB_404a6e1c;
      }
      uVar6 = iVar4 + 0x14U + iVar8;
      *(int *)(param_1 + 0x40) = iVar2;
      *(int *)(param_1 + 0x44) = iVar1 + iVar2 + 8;
      if ((uVar6 < iVar4 + 0x14U) || (uVar3 < uVar6)) {
        iVar8 = (uVar3 - iVar2) + -8;
      }
      *(int *)(param_1 + 0x48) = iVar8;
    }
LAB_404a6e1c:
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined1 *)(param_1 + 0x7e) = 1;
  }
  return 0;
}



/* 404a6e9c FUN_404a6e9c */

/* Boundary evidence: original MIPS .pdata 404a6e9c..404a6f3b. Semantic name remains unreviewed. */

void FUN_404a6e9c(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    do {
      if (((*(char *)(param_1 + 0x7e) != '\0') || (*(char *)(param_1 + 0x7d) != '\0')) ||
         (iVar1 = FUN_404a6cb0(param_1,param_2,param_3,0x49444154), iVar1 < 1)) break;
      param_3 = param_3 - iVar1;
      param_2 = (void *)(iVar1 + (int)param_2);
    } while (param_3 != 0);
    if (param_3 != 0) {
      *(undefined1 *)(param_1 + 0x7e) = 1;
      memset(param_2,0,param_3);
    }
  }
  return;
}



/* 404a6f3c FUN_404a6f3c */

/* Boundary evidence: original MIPS .pdata 404a6f3c..404a6f67. Semantic name remains unreviewed. */

void FUN_404a6f3c(int param_1)

{
  if (*(char *)(param_1 + 0x7c) != '\0') {
    *(undefined1 *)(param_1 + 0x7c) = 0;
    inflateEnd(param_1 + 0x44);
  }
  return;
}



/* 404a6f68 FUN_404a6f68 */

/* Boundary evidence: original MIPS .pdata 404a6f68..404a70eb. Semantic name remains unreviewed. */

int FUN_404a6f68(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  uint uVar5;
  undefined1 uVar6;
  
  if (*(char *)(param_1 + 0x7c) != '\0') {
    *(undefined1 *)(param_1 + 0x7c) = 0;
    inflateEnd(param_1 + 0x44);
  }
  uVar5 = *(uint *)(param_1 + 0x28);
  uVar6 = 1;
  if (((uVar5 <= *(uint *)(param_1 + 0x1c)) || (*(char *)(param_1 + 0x80) != '\0')) ||
     (bVar1 = true, *(int *)(param_1 + 0x20) == 0)) {
    bVar1 = false;
  }
  if ((bVar1) && (*(int *)(param_1 + 0x30) != 0)) {
    *(undefined1 *)(param_1 + 0x7e) = 0;
    pbVar4 = (byte *)(*(int *)(param_1 + 0x24) + param_2);
    puVar3 = (undefined4 *)(param_1 + 0x44);
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(int *)(param_1 + 0x40) = param_2;
    *puVar3 = pbVar4 + param_3 + 8;
    iVar2 = (((uint)*pbVar4 * 0x100 + (uint)pbVar4[1]) * 0x100 + (uint)pbVar4[2]) * 0x100 +
            (uint)pbVar4[3];
    *(int *)(param_1 + 0x48) = iVar2;
    if (uVar5 < iVar2 + param_2 + 8U) {
      *(uint *)(param_1 + 0x48) = (uVar5 - param_2) + -8;
    }
    if (*(uint *)(param_1 + 0x48) < param_3 + 1U) {
      *(undefined1 *)(param_1 + 0x7e) = 1;
      iVar2 = 0;
      *(undefined1 *)(param_1 + 0x7c) = 0;
      *puVar3 = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
    }
    else {
      *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) - param_3;
      iVar2 = inflateInit2_(puVar3,(pbVar4[param_3 + 8] >> 4) + 8,&DAT_404850d0,0x38);
      iVar2 = FUN_404a8a6c(param_1,iVar2);
      *(char *)(param_1 + 0x7c) = (char)iVar2;
      if (iVar2 != 0) {
        uVar6 = 0;
      }
    }
    *(undefined1 *)(param_1 + 0x7d) = uVar6;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 404a70ec FUN_404a70ec */

/* Boundary evidence: original MIPS .pdata 404a70ec..404a73e7. Semantic name remains unreviewed. */

void FUN_404a70ec(undefined4 param_1,char *param_2,byte *param_3,uint param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  
  if (param_4 < 2) {
    return;
  }
  cVar5 = *param_2;
  if (cVar5 != '\x01') {
    if (cVar5 == '\x02') {
      if (param_3 == (byte *)0x0) {
        return;
      }
      while (param_4 = param_4 - 1, param_4 != 0) {
        param_2 = param_2 + 1;
        param_3 = param_3 + 1;
        *param_2 = *param_2 + *param_3;
      }
      return;
    }
    if (cVar5 == '\x03') {
      uVar7 = param_5 + 7U >> 3;
      uVar9 = param_4 - 1;
      if (param_3 == (byte *)0x0) {
        if (uVar9 <= uVar7) {
          return;
        }
        uVar11 = uVar7;
        do {
          uVar11 = uVar11 + 1;
          param_2[uVar11] = ((byte)param_2[uVar11 - uVar7] >> 1) + param_2[uVar11];
        } while (uVar11 < uVar9);
        return;
      }
      uVar11 = 0;
      if (uVar7 != 0) {
        pcVar6 = param_2;
        do {
          if (uVar9 <= uVar11) break;
          pcVar6 = pcVar6 + 1;
          uVar11 = uVar11 + 1;
          *pcVar6 = ((byte)pcVar6[(int)param_3 - (int)param_2] >> 1) + *pcVar6;
        } while (uVar11 < uVar7);
      }
      if (uVar9 <= uVar7) {
        return;
      }
      pcVar6 = param_2 + uVar7;
      uVar11 = uVar7;
      do {
        pcVar6 = pcVar6 + 1;
        uVar11 = uVar11 + 1;
        *pcVar6 = (char)((int)((uint)(byte)param_2[uVar11 - uVar7] +
                              (uint)(byte)pcVar6[(int)param_3 - (int)param_2]) >> 1) + *pcVar6;
      } while (uVar11 < uVar9);
      return;
    }
    if (cVar5 != '\x04') {
      return;
    }
    if (param_3 != (byte *)0x0) {
      uVar9 = param_5 + 7U >> 3;
      uVar11 = param_4 - 1;
      uVar7 = 0;
      if (uVar9 != 0) {
        pcVar6 = param_2;
        do {
          if (uVar11 <= uVar7) break;
          pcVar6 = pcVar6 + 1;
          uVar7 = uVar7 + 1;
          *pcVar6 = pcVar6[(int)param_3 - (int)param_2] + *pcVar6;
        } while (uVar7 < uVar9);
      }
      if (uVar11 <= uVar9) {
        return;
      }
      pcVar6 = param_2 + uVar9;
      iVar10 = (int)param_2 - (int)param_3;
      iVar12 = uVar11 - uVar9;
      do {
        param_3 = param_3 + 1;
        bVar1 = *param_3;
        uVar11 = (uint)param_3[uVar9] - (uint)bVar1;
        uVar8 = (uint)param_3[iVar10] - (uint)bVar1;
        uVar7 = (int)(uVar11 + uVar8) >> 0x1f;
        iVar3 = (uVar11 + uVar8 ^ uVar7) - uVar7;
        iVar2 = (uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f);
        iVar4 = (uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f);
        pcVar6 = pcVar6 + 1;
        if (iVar4 < iVar2) {
          if (iVar4 <= iVar3) {
            cVar5 = *pcVar6 + param_3[uVar9];
            goto LAB_404a7240;
          }
          cVar5 = *pcVar6 + bVar1;
LAB_404a7250:
          *pcVar6 = cVar5;
        }
        else {
          if (iVar2 <= iVar3) {
            cVar5 = *pcVar6 + param_3[iVar10];
            goto LAB_404a7250;
          }
          cVar5 = *pcVar6 + bVar1;
LAB_404a7240:
          *pcVar6 = cVar5;
        }
        iVar12 = iVar12 + -1;
        if (iVar12 == 0) {
          return;
        }
      } while( true );
    }
  }
  uVar7 = param_5 + 7U >> 3;
  if (uVar7 < param_4 - 1) {
    uVar9 = uVar7;
    do {
      uVar9 = uVar9 + 1;
      param_2[uVar9] = param_2[uVar9 - uVar7] + param_2[uVar9];
    } while (uVar9 < param_4 - 1);
  }
  return;
}



/* 404a87b4 FUN_404a87b4 */

/* Boundary evidence: original MIPS .pdata 404a87b4..404a89b7. Semantic name remains unreviewed. */

void FUN_404a87b4(int param_1,undefined4 param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x1c);
  bVar1 = *(byte *)(iVar7 + 0x11);
  iVar5 = (((uint)*(byte *)(iVar7 + 8) * 0x100 + (uint)*(byte *)(iVar7 + 9)) * 0x100 +
          (uint)*(byte *)(iVar7 + 10)) * 0x100 + (uint)*(byte *)(iVar7 + 0xb);
  iVar2 = ((int)((bVar1 >> 2 & 1) + (bVar1 & 2) + 1) >> (bVar1 & 1)) * (uint)*(byte *)(iVar7 + 0x10)
  ;
  iVar6 = (7 >> (param_4 >> 1 & 0x1fU)) + iVar5 >> (8 - param_4 >> 1 & 0x1fU);
  iVar4 = param_4 - (uint)(1 < param_4);
  iVar7 = FUN_404a5abc(iVar5,(((uint)*(byte *)(iVar7 + 0xc) * 0x100 + (uint)*(byte *)(iVar7 + 0xd))
                              * 0x100 + (uint)*(byte *)(iVar7 + 0xe)) * 0x100 +
                             (uint)*(byte *)(iVar7 + 0xf),iVar2,param_4);
  if (iVar2 < 0x18) {
    if (iVar2 < 4) {
      iVar3 = iVar2 >> 1;
    }
    else {
      iVar3 = (iVar2 >> 3) + 2;
    }
  }
  else {
    iVar3 = (iVar2 >> 4) + 4;
  }
  (**(code **)(&DAT_404850d4 + (iVar3 * 6 + param_4) * 4))
            (param_2,iVar7 + ((7 >> (iVar4 >> 1 & 0x1fU)) + param_3 >> (8 - iVar4 >> 1 & 0x1fU)) *
                             ((iVar6 * iVar2 + 7 >> 3) + (uint)(0 < iVar6)) +
                     *(int *)(param_1 + 0x38) * 2 + *(int *)(param_1 + 0x30) + 1,iVar5);
  return;
}



/* 404a89b8 FUN_404a89b8 */

/* Boundary evidence: original MIPS .pdata 404a89b8..404a8a6b. Semantic name remains unreviewed. */

void FUN_404a89b8(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  if ((param_3 & 6) == 0) {
    FUN_404a87b4(param_1,param_2,param_3,1);
    iVar1 = 2;
  }
  else {
    if ((param_3 & 6) != 4) {
      iVar1 = 5;
      goto LAB_404a8a38;
    }
    iVar1 = 3;
  }
  FUN_404a87b4(param_1,param_2,param_3,iVar1);
  iVar1 = 4;
LAB_404a8a38:
  FUN_404a87b4(param_1,param_2,param_3,iVar1);
  FUN_404a87b4(param_1,param_2,param_3,6);
  return;
}



/* 404a8a6c FUN_404a8a6c */

/* Boundary evidence: original MIPS .pdata 404a8a6c..404a8abf. Semantic name remains unreviewed. */

undefined4 FUN_404a8a6c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 < 0) {
    iVar2 = -param_2;
    if (6 < iVar2) {
      iVar2 = 6;
    }
    (**(code **)(**(int **)(param_1 + 4) + 8))(*(int **)(param_1 + 4),1,3,iVar2);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 404a8b00 FUN_404a8b00 */

/* Boundary evidence: original MIPS .pdata 404a8b00..404a8be7. Semantic name remains unreviewed. */

int * FUN_404a8b00(int *param_1,int param_2,int param_3,undefined1 param_4)

{
  uint uVar1;
  SIZE_T SVar2;
  ushort uVar3;
  int iVar4;
  
  iVar4 = 1;
  param_1[6] = 0;
  param_1[0x10b] = 1;
  param_1[1] = (uint)*(ushort *)(param_2 + 6);
  uVar3 = *(ushort *)(param_2 + 8);
  param_1[7] = (int)(param_1 + 9);
  param_1[2] = (uint)uVar3;
  *(undefined1 *)(param_1 + 4) = param_4;
  param_1[9] = 0;
  *(undefined4 *)(param_1[7] + 4) = 0;
  param_1[8] = 0;
  *param_1 = param_3;
  uVar1 = (uint)((ulonglong)(uint)param_1[2] * (ulonglong)(uint)param_1[1]);
  param_1[5] = (uint)(param_3 == 0x26200a);
  if (((int)((ulonglong)(uint)param_1[2] * (ulonglong)(uint)param_1[1] >> 0x20) == 0) &&
     (uVar1 < 0x40000000)) {
    if ((param_3 == 0x26200a) != 0) {
      iVar4 = 4;
    }
    SVar2 = uVar1 * iVar4;
    param_1[3] = SVar2;
    iVar4 = FUN_404962c4(SVar2);
    param_1[6] = iVar4;
    if (iVar4 != 0) {
      return param_1;
    }
  }
  param_1[0x10b] = 0;
  return param_1;
}



/* 404a8be8 FUN_404a8be8 */

/* Boundary evidence: original MIPS .pdata 404a8be8..404a8c0b. Semantic name remains unreviewed. */

void FUN_404a8be8(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4) = 0;
  FUN_404962ec(*(LPVOID *)(param_1 + 0x18));
  return;
}



/* 404a8c0c FUN_404a8c0c */

/* Boundary evidence: original MIPS .pdata 404a8c0c..404a8d23. Semantic name remains unreviewed. */

void FUN_404a8c0c(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x14) == 1) {
    uVar4 = *(undefined4 *)((*(byte *)(param_1 + 0x10) + 2) * 4 + *(int *)(param_1 + 0x1c));
    if (param_3 < param_5) {
      do {
        if (param_2 < param_4) {
          puVar3 = (undefined4 *)
                   (param_2 * 4 + *(int *)(param_1 + 4) * param_3 * 4 + *(int *)(param_1 + 0x18));
          if (param_4 - param_2 != 0) {
            puVar1 = puVar3 + (param_4 - param_2);
            do {
              *puVar3 = uVar4;
              puVar3 = puVar3 + 1;
            } while (puVar3 != puVar1);
          }
        }
        param_3 = param_3 + 1;
      } while (param_3 < param_5);
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0x18);
    for (; param_3 < param_5; param_3 = param_3 + 1) {
      memset((void *)(*(int *)(param_1 + 4) * param_3 + iVar2 + param_2),
             (uint)*(byte *)(param_1 + 0x10),param_4 - param_2);
    }
  }
  return;
}



/* 404a8d24 FUN_404a8d24 */

/* Boundary evidence: original MIPS .pdata 404a8d24..404a8dfb. Semantic name remains unreviewed. */

void FUN_404a8d24(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  size_t _Size;
  int iVar1;
  int iVar2;
  void *_Dst;
  void *_Src;
  int iVar3;
  
  iVar2 = 4;
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = 1;
  }
  _Size = (param_4 - param_2) * iVar2;
  iVar1 = *(int *)(param_1 + 4) * iVar2;
  if (param_3 < param_5) {
    iVar3 = param_5 - param_3;
    _Dst = (void *)(param_3 * _Size + param_6);
    _Src = (void *)(param_3 * iVar1 + param_2 * iVar2 + *(int *)(param_1 + 0x18));
    do {
      memcpy(_Dst,_Src,_Size);
      _Src = (void *)((int)_Src + iVar1);
      iVar3 = iVar3 + -1;
      _Dst = (void *)((int)_Dst + _Size);
    } while (iVar3 != 0);
  }
  return;
}



/* 404a8dfc FUN_404a8dfc */

/* Boundary evidence: original MIPS .pdata 404a8dfc..404a8edb. Semantic name remains unreviewed. */

void FUN_404a8dfc(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  size_t _Size;
  int iVar1;
  int iVar2;
  void *_Dst;
  void *_Src;
  int iVar3;
  
  iVar2 = 4;
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = 1;
  }
  _Size = (param_4 - param_2) * iVar2;
  iVar1 = *(int *)(param_1 + 4) * iVar2;
  if (param_3 < param_5) {
    iVar3 = param_5 - param_3;
    _Dst = (void *)(param_3 * iVar1 + param_2 * iVar2 + *(int *)(param_1 + 0x18));
    _Src = (void *)(param_3 * _Size + param_6);
    do {
      memcpy(_Dst,_Src,_Size);
      _Src = (void *)((int)_Src + _Size);
      iVar3 = iVar3 + -1;
      _Dst = (void *)((int)_Dst + iVar1);
    } while (iVar3 != 0);
  }
  return;
}



/* 404a8edc FUN_404a8edc */

/* Boundary evidence: original MIPS .pdata 404a8edc..404a8f47. Semantic name remains unreviewed. */

void FUN_404a8edc(int param_1,void *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 4;
  iVar1 = 4;
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar1 = 1;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = 1;
  }
  memcpy(param_2,(void *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 4) * iVar1 * param_3),
         *(int *)(param_1 + 4) * iVar2);
  return;
}



/* 404a8f48 FUN_404a8f48 */

int FUN_404a8f48(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 4;
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar1 = 1;
  }
  return *(int *)(param_1 + 4) * iVar1 * param_2 + *(int *)(param_1 + 0x18);
}



/* 404a8f80 FUN_404a8f80 */

/* Boundary evidence: original MIPS .pdata 404a8f80..404a8fe7. Semantic name remains unreviewed. */

void FUN_404a8f80(int param_1,void *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 4;
  iVar2 = 4;
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = 1;
    iVar1 = 1;
  }
  memcpy((void *)(iVar1 * *(int *)(param_1 + 4) * param_3 + *(int *)(param_1 + 0x18)),param_2,
         *(int *)(param_1 + 4) * iVar2);
  return;
}



/* 404a8fe8 FUN_404a8fe8 */

/* Boundary evidence: original MIPS .pdata 404a8fe8..404a909b. Semantic name remains unreviewed. */

undefined4 FUN_404a8fe8(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  byte *pbVar3;
  uint uVar4;
  SIZE_T SVar5;
  undefined4 *puVar6;
  
  SVar5 = *(int *)(param_1 + 0xc) << 2;
  puVar1 = (undefined4 *)FUN_404962c4(SVar5);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar4 = 0;
    puVar6 = puVar1;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        pbVar3 = (byte *)(*(int *)(param_1 + 0x18) + uVar4);
        uVar4 = uVar4 + 1;
        *puVar6 = *(undefined4 *)((*pbVar3 + 2) * 4 + *(int *)(param_1 + 0x1c));
        puVar6 = puVar6 + 1;
      } while (uVar4 < *(uint *)(param_1 + 0xc));
    }
    FUN_404962ec(*(LPVOID *)(param_1 + 0x18));
    *(undefined4 **)(param_1 + 0x18) = puVar1;
    *(SIZE_T *)(param_1 + 0xc) = SVar5;
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x14) = 1;
  }
  return uVar2;
}



/* 404a909c FUN_404a909c */

/* Boundary evidence: original MIPS .pdata 404a909c..404a90c7. Semantic name remains unreviewed. */

void FUN_404a909c(int param_1)

{
  FUN_404a8c0c(param_1,0,0,*(int *)(param_1 + 4),*(int *)(param_1 + 8));
  return;
}



/* 404a90c8 FUN_404a90c8 */

/* Boundary evidence: original MIPS .pdata 404a90c8..404a91b7. Semantic name remains unreviewed. */

undefined4 FUN_404a90c8(undefined4 *param_1,void *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)((int)param_1[7] + 4);
  bVar1 = true;
  if ((iVar3 == 0) || (param_1[5] != 0)) {
    memcpy((void *)param_1[7],param_2,(*(int *)((int)param_2 + 4) + 2) * 4);
    goto LAB_404a919c;
  }
  *(int *)((int)param_2 + 4) = iVar3;
  uVar4 = 0;
  if (iVar3 == 0) {
LAB_404a917c:
    uVar2 = 0x30803;
  }
  else {
    iVar3 = 8;
    do {
      if (!bVar1) goto LAB_404a9158;
      bVar1 = *(int *)(iVar3 + (int)param_2) == *(int *)(iVar3 + param_1[7]);
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar4 < *(uint *)((int)param_2 + 4));
    if (bVar1) goto LAB_404a917c;
LAB_404a9158:
    iVar3 = FUN_404a8fe8((int)param_1);
    if (iVar3 != 1) {
      return 0;
    }
    uVar2 = 0x26200a;
  }
  *param_1 = uVar2;
LAB_404a919c:
  param_1[8] = 1;
  return 1;
}



/* 404a91b8 FUN_404a91b8 */

/* Boundary evidence: original MIPS .pdata 404a91b8..404a9477. Semantic name remains unreviewed. */

undefined4 *
FUN_404a91b8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
            void *param_17,int param_18,undefined4 *param_19,undefined4 param_20,undefined4 param_21
            ,undefined1 param_22,undefined1 param_23)

{
  int iVar1;
  undefined4 uVar2;
  SIZE_T SVar3;
  
  *param_1 = &PTR_FUN_4048538c;
  param_1[0x110] = param_6;
  param_1[0x10f] = param_5;
  param_1[0x111] = param_7;
  param_1[0x112] = param_8;
  param_1[0x114] = param_10;
  param_1[0x113] = param_9;
  param_1[0x115] = param_11;
  param_1[0x116] = param_12;
  param_1[0x10b] = param_2;
  param_1[0x10d] = param_3;
  param_1[0x118] = param_14;
  param_1[0x10e] = param_4;
  param_1[0x117] = param_13;
  param_1[0x123] = param_15;
  param_1[0x119] = param_16;
  param_1[0x10a] = param_1 + 8;
  memcpy(param_1 + 8,param_17,(*(int *)((int)param_17 + 4) + 2) * 4);
  param_1[0x10c] = param_19;
  param_1[0x124] = param_20;
  *(undefined1 *)(param_1 + 0x122) = param_22;
  *(undefined1 *)((int)param_1 + 0x489) = param_23;
  param_1[0x125] = param_21;
  if ((param_19 != (undefined4 *)0x0) && ((param_19[8] == 0 || (param_18 == 1)))) {
    iVar1 = FUN_404a90c8(param_19,param_17);
    if (iVar1 == 0) {
      param_1[1] = 0x4c494146;
      return param_1;
    }
    param_1[0x119] = *(undefined4 *)param_1[0x10c];
  }
  iVar1 = param_1[0x113] - param_1[0x111];
  SVar3 = param_1[0x10f] - param_1[0x10d];
  param_1[2] = iVar1;
  param_1[0x11a] = iVar1;
  if (param_1[0x119] == 0x26200a) {
    param_1[0x11a] = iVar1 * 4;
    SVar3 = SVar3 * 4;
  }
  param_1[1] = 0x42664731;
  param_1[3] = param_1[0x114] - param_1[0x112];
  param_1[4] = param_1[0x11a];
  param_1[5] = param_1[0x119];
  param_1[6] = 0;
  param_1[7] = 0;
  if (param_1[0x123] == 0) {
    if (param_1[0x10c] == 0) {
      uVar2 = FUN_404962c4((param_1[0x114] - param_1[0x112]) * param_1[0x11a]);
      param_1[0x11c] = uVar2;
    }
    else {
      param_1[0x11c] = *(undefined4 *)(param_1[0x10c] + 0x18);
    }
    if (param_1[0x11c] == 0) {
      param_1[1] = 0x4c494146;
    }
    else {
      param_1[6] = param_1[0x11c];
    }
  }
  else {
    param_1[0x11c] = 0;
  }
  if ((param_1[0x10c] == 0) || (*(char *)((int)param_1 + 0x489) != '\x03')) {
    param_1[0x121] = 0;
  }
  else {
    iVar1 = FUN_404962c4(param_1[4] * param_1[3]);
    param_1[0x121] = iVar1;
    if (iVar1 == 0) {
      param_1[1] = 0x4c494146;
    }
    else {
      FUN_404a8d24(param_1[0x10c],param_1[0x111],param_1[0x112],param_1[0x113],param_1[0x114],iVar1)
      ;
    }
  }
  uVar2 = FUN_404962c4(SVar3);
  param_1[0x11e] = uVar2;
  uVar2 = FUN_404962c4(SVar3);
  param_1[0x11f] = uVar2;
  iVar1 = FUN_404962c4(SVar3);
  param_1[0x120] = iVar1;
  if (((param_1[0x11e] == 0) || (param_1[0x11f] == 0)) || (iVar1 == 0)) {
    param_1[1] = 0x4c494146;
  }
  param_1[0x11d] = 0;
  return param_1;
}



/* 404a9478 FUN_404a9478 */

/* Boundary evidence: original MIPS .pdata 404a9478..404a94f7. Semantic name remains unreviewed. */

void FUN_404a9478(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_4048538c;
  if (param_1[0x10c] == 0) {
    FUN_404962ec((LPVOID)param_1[0x11c]);
  }
  *(undefined4 *)(param_1[0x10a] + 4) = 0;
  FUN_404962ec((LPVOID)param_1[0x11e]);
  FUN_404962ec((LPVOID)param_1[0x11f]);
  FUN_404962ec((LPVOID)param_1[0x120]);
  if ((LPVOID)param_1[0x121] != (LPVOID)0x0) {
    FUN_404962ec((LPVOID)param_1[0x121]);
  }
  param_1[1] = 0x4c494146;
  return;
}



/* 404a94f8 FUN_404a94f8 */

/* Boundary evidence: original MIPS .pdata 404a94f8..404a95df. Semantic name remains unreviewed. */

int FUN_404a94f8(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  if (*(int *)(param_1 + 0x48c) == 1) {
    local_1c = *(int *)(param_1 + 0x448) + param_2;
    local_18 = *(int *)(param_1 + 0x44c) - *(int *)(param_1 + 0x444);
    local_14 = local_1c + 1;
    local_20 = 0;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x42c) + 0x18))
                      (*(int **)(param_1 + 0x42c),&local_20,*(undefined4 *)(param_1 + 0x464),1,
                       param_1 + 8);
    if (iVar1 < 0) {
      return iVar1;
    }
    *(void **)(param_1 + 0x474) = *(void **)(param_1 + 0x18);
    if (*(int *)(param_1 + 0x430) != 0) {
      FUN_404a8edc(*(int *)(param_1 + 0x430),*(void **)(param_1 + 0x18),param_2);
    }
  }
  else if (*(int *)(param_1 + 0x430) == 0) {
    *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x468) * param_2 + *(int *)(param_1 + 0x470);
  }
  else {
    iVar1 = FUN_404a8f48(*(int *)(param_1 + 0x430),param_2);
    *(int *)(param_1 + 0x474) = iVar1;
  }
  *(int *)(param_1 + 0x46c) = param_2;
  return 0;
}



/* 404a95e0 FUN_404a95e0 */

/* Boundary evidence: original MIPS .pdata 404a95e0..404a9997. Semantic name remains unreviewed. */

int FUN_404a95e0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  
  if (param_6 == 0) {
    if (*(int *)(param_1 + 0x474) == 0) {
      return -0x7fffbffb;
    }
    uVar5 = (undefined1)param_3;
    if (param_5 == 1) {
      if (*(int *)(param_1 + 0x464) == 0x30803) {
        iVar1 = 0;
        if (0 < *(int *)(param_1 + 0x44c)) {
          do {
            *(undefined1 *)(*(int *)(param_1 + 0x474) + iVar1) = uVar5;
            iVar1 = iVar1 + 1;
          } while (iVar1 < *(int *)(param_1 + 0x44c));
        }
      }
      else {
        iVar1 = 0;
        if (0 < *(int *)(param_1 + 0x44c)) {
          iVar2 = 0;
          do {
            *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x474)) =
                 *(undefined4 *)(*(int *)(param_1 + 0x428) + (param_3 + 2) * 4);
            iVar1 = iVar1 + 1;
            iVar2 = iVar2 + 4;
          } while (iVar1 < *(int *)(param_1 + 0x44c));
        }
      }
    }
    else if (*(int *)(param_1 + 0x464) == 0x30803) {
      iVar1 = 0;
      if (0 < *(int *)(param_1 + 0x454)) {
        do {
          *(undefined1 *)(*(int *)(param_1 + 0x474) + iVar1) = uVar5;
          iVar1 = iVar1 + 1;
        } while (iVar1 < *(int *)(param_1 + 0x454));
      }
      iVar1 = *(int *)(param_1 + 0x454);
      if (iVar1 < *(int *)(param_1 + 0x45c)) {
        do {
          *(undefined1 *)(*(int *)(param_1 + 0x474) + iVar1) =
               *(undefined1 *)((iVar1 - *(int *)(param_1 + 0x454)) + *(int *)(param_1 + 0x478));
          iVar1 = iVar1 + 1;
        } while (iVar1 < *(int *)(param_1 + 0x45c));
      }
      for (iVar1 = *(int *)(param_1 + 0x45c); iVar1 < *(int *)(param_1 + 0x44c); iVar1 = iVar1 + 1)
      {
        *(undefined1 *)(*(int *)(param_1 + 0x474) + iVar1) = uVar5;
      }
    }
    else {
      iVar1 = 0;
      if (*(int *)(param_1 + 0x430) != 0) {
        iVar1 = FUN_404a8f48(*(int *)(param_1 + 0x430),param_4);
      }
      if (param_2 == 1) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x454)) {
          iVar3 = 0;
          do {
            *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x474)) =
                 *(undefined4 *)(*(int *)(param_1 + 0x428) + (param_3 + 2) * 4);
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + 4;
          } while (iVar2 < *(int *)(param_1 + 0x454));
        }
        iVar2 = *(int *)(param_1 + 0x45c);
        if (iVar2 < *(int *)(param_1 + 0x44c)) {
          iVar3 = iVar2 << 2;
          do {
            *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x474)) =
                 *(undefined4 *)(*(int *)(param_1 + 0x428) + (param_3 + 2) * 4);
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + 4;
          } while (iVar2 < *(int *)(param_1 + 0x44c));
        }
      }
      else if (iVar1 != 0) {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x454)) {
          iVar3 = 0;
          do {
            *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x474)) = *(undefined4 *)(iVar3 + iVar1);
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + 4;
          } while (iVar2 < *(int *)(param_1 + 0x454));
        }
        iVar2 = *(int *)(param_1 + 0x45c);
        if (iVar2 < *(int *)(param_1 + 0x44c)) {
          iVar3 = iVar2 << 2;
          do {
            *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x474)) = *(undefined4 *)(iVar3 + iVar1);
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + 4;
          } while (iVar2 < *(int *)(param_1 + 0x44c));
        }
      }
      iVar2 = *(int *)(param_1 + 0x454);
      if (iVar2 < *(int *)(param_1 + 0x45c)) {
        iVar3 = iVar2 << 2;
        do {
          uVar4 = *(uint *)((iVar2 - *(int *)(param_1 + 0x454)) * 4 + *(int *)(param_1 + 0x478));
          if ((*(int *)(param_1 + 0x430) == 0) || ((uVar4 & 0xff000000) != 0)) {
            *(uint *)(iVar3 + *(int *)(param_1 + 0x474)) = uVar4;
          }
          else {
            *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x474)) = *(undefined4 *)(iVar3 + iVar1);
          }
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar2 < *(int *)(param_1 + 0x45c));
      }
    }
  }
  if (*(int *)(param_1 + 0x430) != 0) {
    FUN_404a8f80(*(int *)(param_1 + 0x430),*(void **)(param_1 + 0x474),*(int *)(param_1 + 0x46c));
  }
  if ((*(int *)(param_1 + 0x48c) != 1) ||
     (iVar1 = (**(code **)(**(int **)(param_1 + 0x42c) + 0x1c))
                        (*(int **)(param_1 + 0x42c),param_1 + 8), -1 < iVar1)) {
    *(undefined4 *)(param_1 + 0x474) = 0;
    iVar1 = 0;
  }
  return iVar1;
}



/* 404a9998 FUN_404a9998 */

/* Boundary evidence: original MIPS .pdata 404a9998..404a9ab7. Semantic name remains unreviewed. */

int FUN_404a9998(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1[0x11d] != 0) && (iVar1 = (**(code **)(*param_1 + 4))(param_1,0,0,0,0,0), iVar1 < 0))
  {
    return iVar1;
  }
  if (((param_1[0x123] != 0) || (param_1[0x124] != 1)) ||
     (iVar1 = (**(code **)(*(int *)param_1[0x10b] + 0x20))
                        ((int *)param_1[0x10b],param_1 + 0x111,param_1 + 2,param_2), -1 < iVar1)) {
    if (param_2 == 1) {
      if (*(char *)((int)param_1 + 0x489) == '\x03') {
        FUN_404a8dfc(param_1[0x10c],param_1[0x115],param_1[0x116],param_1[0x117],param_1[0x118],
                     param_1[0x121]);
        FUN_404962ec((LPVOID)param_1[0x121]);
        param_1[0x121] = 0;
      }
      else if (*(char *)((int)param_1 + 0x489) == '\x02') {
        FUN_404a8c0c(param_1[0x10c],param_1[0x115],param_1[0x116],param_1[0x117],param_1[0x118]);
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 404a9ab8 FUN_404a9ab8 */

/* Boundary evidence: original MIPS .pdata 404a9ab8..404a9be7. Semantic name remains unreviewed. */

int FUN_404a9ab8(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    if (param_3 < param_2) {
      return 0;
    }
    iVar1 = (**(code **)*param_1)(param_1,param_2);
    if (iVar1 < 0) break;
    if (param_1[0x119] == 0x30803) {
      memset((void *)param_1[0x11e],param_4,param_1[0x10f] - param_1[0x10d]);
    }
    else {
      iVar1 = 0;
      if (0 < param_1[0x10f] - param_1[0x10d]) {
        iVar2 = 0;
        do {
          *(undefined4 *)(param_1[0x11e] + iVar2) =
               *(undefined4 *)(param_1[0x10a] + (param_4 + 2) * 4);
          iVar1 = iVar1 + 1;
          iVar2 = iVar2 + 4;
        } while (iVar1 < param_1[0x10f] - param_1[0x10d]);
      }
    }
    iVar1 = (**(code **)(*param_1 + 4))(param_1,0,param_4,param_2,1,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    param_2 = param_2 + 1;
  }
  return iVar1;
}



/* 404a9be8 FUN_404a9be8 */

/* Boundary evidence: original MIPS .pdata 404a9be8..404a9c83. Semantic name remains unreviewed. */

int FUN_404a9be8(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  while( true ) {
    if (param_3 < param_2) {
      return 0;
    }
    iVar1 = (**(code **)*param_1)(param_1,param_2);
    if (iVar1 < 0) break;
    iVar1 = (**(code **)(*param_1 + 4))(param_1,0,0,0,0,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    param_2 = param_2 + 1;
  }
  return iVar1;
}



/* 404a9c84 FUN_404a9c84 */

/* Boundary evidence: original MIPS .pdata 404a9c84..404a9d73. Semantic name remains unreviewed. */

int FUN_404a9c84(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (param_1[0x11b] < param_1[0x114] + -1) {
    iVar2 = 1;
    if (param_1[0x119] == 0x26200a) {
      iVar2 = 4;
    }
    memcpy((void *)param_1[0x11f],(void *)param_1[0x11e],(param_1[0x10f] - param_1[0x10d]) * iVar2);
    iVar1 = (**(code **)(*param_1 + 4))(param_1,0,0,0,0,0);
    if (-1 < iVar1) {
      iVar1 = (**(code **)*param_1)(param_1,param_1[0x11b] + 1);
    }
    memcpy((void *)param_1[0x11e],(void *)param_1[0x11f],(param_1[0x10f] - param_1[0x10d]) * iVar2);
  }
  return iVar1;
}



/* 404a9d74 FUN_404a9d74 */

void FUN_404a9d74(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x494) == 1) {
    iVar2 = (*(int *)(param_1 + 0x43c) - *(int *)(param_1 + 0x434)) + -1;
    if (-1 < iVar2) {
      iVar3 = iVar2 * 4;
      do {
        if (*(char *)(*(int *)(param_1 + 0x478) + iVar2) == *(char *)(param_1 + 0x488)) {
          *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x478)) = 0;
        }
        else {
          *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x478)) =
               *(undefined4 *)
                ((*(byte *)(*(int *)(param_1 + 0x478) + iVar2) + 2) * 4 + *(int *)(param_1 + 0x428))
          ;
        }
        iVar2 = iVar2 + -1;
        iVar3 = iVar3 + -4;
      } while (-1 < iVar2);
    }
  }
  else {
    iVar2 = (*(int *)(param_1 + 0x43c) - *(int *)(param_1 + 0x434)) + -1;
    if (-1 < iVar2) {
      iVar3 = iVar2 * 4;
      do {
        pbVar1 = (byte *)(*(int *)(param_1 + 0x478) + iVar2);
        iVar2 = iVar2 + -1;
        *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x478)) =
             *(undefined4 *)((*pbVar1 + 2) * 4 + *(int *)(param_1 + 0x428));
        iVar3 = iVar3 + -4;
      } while (-1 < iVar2);
    }
  }
  return;
}



/* 404a9e58 FUN_404a9e58 */

/* Boundary evidence: original MIPS .pdata 404a9e58..404aa147. Semantic name remains unreviewed. */

undefined4 FUN_404a9e58(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar11 = *(uint *)(param_1 + 0x1c);
  uVar9 = *(uint *)(param_1 + 0x20);
  uVar10 = (uint)param_1[0x18];
  uVar12 = *(uint *)(param_1 + (*(uint *)(param_1 + 0x24) + 10) * 4);
  uVar8 = *(uint *)(param_1 + 0x24);
  do {
    while( true ) {
      uVar5 = uVar8;
      uVar2 = uVar12;
      uVar3 = (uint)param_1[1];
      if ((int)uVar9 < (int)uVar3) {
        do {
          if (*(int *)(param_1 + 8) < 1) {
            param_1[0x14] = 1;
            goto LAB_404aa108;
          }
          bVar1 = **(byte **)(param_1 + 4);
          uVar12 = uVar9 & 0x1f;
          *(byte **)(param_1 + 4) = *(byte **)(param_1 + 4) + 1;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
          uVar9 = uVar9 + 8;
          uVar11 = ((uint)bVar1 << uVar12) + uVar11;
        } while ((int)uVar9 < (int)(uint)param_1[1]);
      }
      uVar8 = (1 << (uVar3 & 0x1f)) - 1U & uVar11;
      uVar12 = *(uint *)(param_1 + (uVar8 + 10) * 4);
      uVar6 = uVar12 >> 0x14;
      if (uVar6 == 0) break;
LAB_404a9fcc:
      if (*(int *)(param_1 + 0x10) < (int)uVar6) {
        param_1[0x15] = 1;
LAB_404aa108:
        param_1[0x18] = (byte)uVar10;
        *(uint *)(param_1 + 0x24) = uVar5;
        *(uint *)(param_1 + 0x1c) = uVar11;
        *(uint *)(param_1 + 0x20) = uVar9;
        return 1;
      }
      uVar9 = uVar9 - uVar3;
      uVar11 = (int)uVar11 >> (uVar3 & 0x1f);
      puVar7 = (undefined1 *)(uVar6 + *(int *)(param_1 + 0xc) + -1);
      *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - uVar6;
      *(uint *)(param_1 + 0xc) = uVar6 + *(int *)(param_1 + 0xc);
      *puVar7 = (char)uVar12;
      uVar10 = uVar12;
      while (1 < uVar6) {
        uVar10 = *(uint *)(param_1 + ((uVar10 >> 8 & 0xfff) + 10) * 4);
        puVar7 = puVar7 + -1;
        *puVar7 = (char)uVar10;
        uVar6 = uVar10 >> 0x14;
      }
      uVar10 = uVar10 & 0xff;
      if ((*(ushort *)(param_1 + 2) < 0xfff) && (uVar2 >> 0x14 != 0)) {
        uVar4 = *(ushort *)(param_1 + 2) + 1;
        uVar3 = (uint)uVar4;
        *(ushort *)(param_1 + 2) = uVar4;
        if ((int)uVar3 <= (int)uVar5) goto LAB_404aa0dc;
        *(uint *)(param_1 + (uVar3 + 10) * 4) =
             (uVar2 + 0x100000 & 0xfff00000) + uVar5 * 0x100 + uVar10;
        if (((uVar3 + 1 & uVar3) == 0) && (*(ushort *)(param_1 + 2) < 0xfff)) {
          param_1[1] = param_1[1] + 1;
        }
      }
    }
    uVar12 = 1 << (*param_1 & 0x1f);
    uVar6 = uVar12 & 0xffff;
    if (uVar8 != uVar6) {
      if (uVar8 == (uVar12 + 1 & 0xffff)) {
        param_1[0x19] = 1;
        uVar5 = (1 << (*param_1 & 0x1f)) + 1U & 0xffff;
        goto LAB_404aa108;
      }
      if (uVar8 == *(ushort *)(param_1 + 2) + 1) {
        uVar12 = (uVar2 + 0x100000 & 0xfff00000) + uVar5 * 0x100 + uVar10;
        uVar6 = uVar12 >> 0x14;
        goto LAB_404a9fcc;
      }
LAB_404aa0dc:
      param_1[0x1a] = 1;
      return 0;
    }
    *(short *)(param_1 + 2) = (short)uVar12 + 1;
    param_1[1] = *param_1 + 1;
    uVar9 = uVar9 - uVar3;
    uVar11 = (int)uVar11 >> (uVar3 & 0x1f);
    memset(param_1 + (uVar6 + 10) * 4,0,(0x1000 - uVar6) * 4);
    uVar12 = 0;
  } while( true );
}



/* 404aa148 FUN_404aa148 */

undefined4 FUN_404aa148(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_2 + 8) = 0;
  iVar2 = *param_1;
  if (iVar2 == 0) {
    *param_1 = param_2;
  }
  else {
    if (*(int *)(iVar2 + 8) != 0) {
      iVar3 = iVar2;
      iVar1 = *(int *)(iVar2 + 8);
      do {
        iVar2 = iVar1;
        if (*(int *)(iVar3 + 0xc) == *(int *)(param_2 + 0xc)) {
          return 0;
        }
        iVar3 = iVar2;
        iVar1 = *(int *)(iVar2 + 8);
      } while (*(int *)(iVar2 + 8) != 0);
    }
    *(int *)(iVar2 + 8) = param_2;
  }
  return 1;
}



/* 404aa1ac FUN_404aa1ac */

/* Boundary evidence: original MIPS .pdata 404aa1ac..404aa49b. Semantic name remains unreviewed. */

undefined4 FUN_404aa1ac(int param_1,ushort *param_2,int param_3,int *param_4)

{
  ushort uVar1;
  undefined2 uVar2;
  int *_Dst;
  undefined4 *_Dst_00;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  _Dst = (int *)FUN_404962c4(0x18);
  if (_Dst == (int *)0x0) {
    _Dst = (int *)0x0;
  }
  else {
    memset(_Dst,0,0x18);
  }
  if (_Dst == (int *)0x0) {
    return 0x8007000e;
  }
  _Dst[2] = (uint)*param_2;
  *(ushort *)(_Dst + 4) = param_2[1];
  if (*(SIZE_T *)(param_2 + 6) == 0) {
    _Dst[5] = 0;
    return 0x8007000e;
  }
  _Dst_00 = (undefined4 *)FUN_404962c4(*(SIZE_T *)(param_2 + 6));
  _Dst[5] = (int)_Dst_00;
  if (_Dst_00 == (undefined4 *)0x0) {
    FUN_404962ec(_Dst);
    return 0x8007000e;
  }
  iVar4 = *(int *)(param_2 + 2);
  if (iVar4 == 0) goto LAB_404aa354;
  uVar1 = param_2[1];
  if (uVar1 == 0) {
    return 0x80004005;
  }
  if (uVar1 < 3) {
    memcpy(_Dst_00,*(void **)(param_2 + 4),*(size_t *)(param_2 + 6));
    goto LAB_404aa354;
  }
  if (uVar1 == 3) {
    uVar5 = 0;
    if (iVar4 != 0) {
      iVar4 = 0;
      do {
        uVar2 = (**(code **)**(undefined4 **)(param_3 + 0x10))
                          (*(undefined4 **)(param_3 + 0x10),
                           *(undefined2 *)(iVar4 + *(int *)(param_2 + 4)));
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 2;
        *(undefined2 *)_Dst_00 = uVar2;
        _Dst_00 = (undefined4 *)((int)_Dst_00 + 2);
      } while (uVar5 < *(uint *)(param_2 + 2));
    }
    goto LAB_404aa354;
  }
  if (uVar1 == 4) {
LAB_404aa38c:
    uVar5 = 0;
    if (iVar4 != 0) {
      iVar4 = 0;
      do {
        uVar3 = (**(code **)(**(int **)(param_3 + 0x10) + 4))
                          (*(int **)(param_3 + 0x10),*(undefined4 *)(*(int *)(param_2 + 4) + iVar4))
        ;
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 4;
        *_Dst_00 = uVar3;
        _Dst_00 = _Dst_00 + 1;
      } while (uVar5 < *(uint *)(param_2 + 2));
    }
  }
  else {
    if (uVar1 != 5) {
      if (uVar1 == 9) goto LAB_404aa38c;
      if (uVar1 != 10) {
        return 0x80004005;
      }
    }
    uVar5 = 0;
    if (iVar4 != 0) {
      iVar4 = 0;
      do {
        uVar3 = (**(code **)(**(int **)(param_3 + 0x10) + 4))
                          (*(int **)(param_3 + 0x10),*(undefined4 *)(*(int *)(param_2 + 4) + iVar4))
        ;
        *_Dst_00 = uVar3;
        uVar3 = (**(code **)(**(int **)(param_3 + 0x10) + 4))
                          (*(int **)(param_3 + 0x10),
                           *(undefined4 *)(*(int *)(param_2 + 4) + iVar4 + 4));
        _Dst_00[1] = uVar3;
        NKDbgPrintfW(L"RATIONAL: %8d / %8d",*_Dst_00,_Dst_00[1]);
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 8;
        _Dst_00 = _Dst_00 + 2;
      } while (uVar5 < *(uint *)(param_2 + 2));
    }
  }
LAB_404aa354:
  _Dst[3] = *(int *)(param_2 + 6);
  **(undefined4 **)(param_1 + 4) = _Dst;
  _Dst[1] = *(int *)(param_1 + 4);
  *_Dst = param_1;
  *(int **)(param_1 + 4) = _Dst;
  *param_4 = *param_4 + *(int *)(param_2 + 6);
  return 0;
}



/* 404aa4b4 FUN_404aa4b4 */

uint FUN_404aa4b4(undefined4 param_1,uint param_2)

{
  return (param_2 & 0xff0000 | param_2 >> 0x10) >> 8 | (param_2 & 0xff00 | param_2 << 0x10) << 8;
}



/* 404aa4e0 FUN_404aa4e0 */

/* Boundary evidence: original MIPS .pdata 404aa4e0..404aa84f. Semantic name remains unreviewed. */

uint * FUN_404aa4e0(int param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  uint uVar4;
  LPVOID pvVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  HRESULT HVar9;
  SIZE_T SVar10;
  uint uVar11;
  uint uVar12;
  undefined2 *puVar13;
  STRSAFE_PCNZCH psz;
  uint uVar14;
  STRSAFE_PCNZCH pcVar15;
  int iVar16;
  undefined2 local_38;
  uint local_34;
  undefined *local_30;
  
  if (param_2 <= *(uint *)(param_1 + 0xc)) {
    puVar13 = (undefined2 *)(*(int *)(param_1 + 4) + param_2);
    bVar2 = true;
    if ((*(undefined2 **)(param_1 + 8) < puVar13) ||
       (bVar1 = true, (uint)((int)*(undefined2 **)(param_1 + 8) - (int)puVar13) < 2)) {
      bVar1 = false;
    }
    if (bVar1) {
      uVar4 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                        (*(undefined4 **)(param_1 + 0x10),*puVar13);
      if ((*(undefined2 **)(param_1 + 8) < puVar13 + 1) ||
         ((uint)((int)*(undefined2 **)(param_1 + 8) - (int)(puVar13 + 1)) / 0xc < uVar4)) {
        bVar2 = false;
      }
      if (bVar2) {
        if (uVar4 < 0xccccccd) {
          SVar10 = uVar4 * 0x14;
        }
        else {
          SVar10 = 0xffffffff;
        }
        pvVar5 = (LPVOID)FUN_404962c4(SVar10);
        if (pvVar5 != (LPVOID)0x0) {
          puVar6 = (uint *)FUN_404962c4(0x10);
          if (puVar6 == (uint *)0x0) {
            puVar6 = (uint *)0x0;
          }
          else {
            *puVar6 = uVar4;
            puVar6[1] = (uint)pvVar5;
            puVar6[2] = 0;
          }
          if (puVar6 != (uint *)0x0) {
            uVar4 = 0;
            puVar6[3] = param_2;
            if (*puVar6 == 0) {
              return puVar6;
            }
            iVar16 = 0;
            local_30 = &DAT_404bd27c;
            pcVar15 = (STRSAFE_PCNZCH)(puVar13 + 5);
            do {
              puVar3 = local_30;
              uVar7 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                                (*(undefined4 **)(param_1 + 0x10),*(undefined2 *)(pcVar15 + -6));
              uVar11 = (uint)*(ushort *)(pcVar15 + -8);
              local_38 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                                   (*(undefined4 **)(param_1 + 0x10),uVar11);
              uVar14 = (uint)(pcVar15 + -1) & 3;
              uVar8 = (uint)(pcVar15 + -4) & 3;
              uVar8 = (**(code **)(**(int **)(param_1 + 0x10) + 4))
                                (*(int **)(param_1 + 0x10),
                                 (*(int *)(pcVar15 + -1 + -uVar14) << (3 - uVar14) * 8 |
                                 uVar11 & 0xffffffffU >> (uVar14 + 1) * 8) & -1 << (4 - uVar8) * 8 |
                                 *(uint *)(pcVar15 + -4 + -uVar8) >> uVar8 * 8);
              uVar11 = (**(code **)(**(int **)(param_1 + 0x10) + 4))
                                 (*(int **)(param_1 + 0x10),*(undefined4 *)pcVar15);
              uVar14 = 0;
              if (((uVar7 == 0) || (0xc < uVar7)) || (0x10000 < uVar8)) {
LAB_404aa7c4:
                local_38 = 0;
                uVar8 = 0;
                uVar7 = 0;
                psz = (STRSAFE_PCNZCH)0x0;
              }
              else {
                uVar14 = (byte)puVar3[uVar7] * uVar8;
                psz = pcVar15;
                if (4 < uVar14) {
                  uVar12 = *(uint *)(param_1 + 0xc);
                  if (((uVar12 < uVar14) || (uVar12 < uVar11)) || (uVar12 < uVar14 + uVar11))
                  goto LAB_404aa7c4;
                  psz = (STRSAFE_PCNZCH)(*(int *)(param_1 + 4) + uVar11);
                  if (uVar7 == 2) {
                    local_34 = uVar8;
                    HVar9 = StringCchLengthA(psz,uVar8,&local_34);
                    if (-1 < HVar9) {
                      uVar8 = local_34 + 1;
                      uVar14 = uVar8;
                    }
                    psz[uVar8 - 1] = '\0';
                  }
                }
              }
              puVar13 = (undefined2 *)(iVar16 + puVar6[1]);
              *(STRSAFE_PCNZCH *)(puVar13 + 4) = psz;
              puVar13[1] = (short)uVar7;
              *puVar13 = local_38;
              *(uint *)(puVar13 + 2) = uVar8;
              *(STRSAFE_PCNZCH *)(puVar13 + 8) = pcVar15 + -8;
              *(uint *)(puVar13 + 6) = uVar14;
              uVar4 = uVar4 + 1;
              iVar16 = iVar16 + 0x14;
              pcVar15 = pcVar15 + 0xc;
              if (*puVar6 <= uVar4) {
                return puVar6;
              }
            } while( true );
          }
          FUN_404962ec(pvVar5);
        }
      }
    }
  }
  return (uint *)0x0;
}



/* 404aa850 FUN_404aa850 */

/* Boundary evidence: original MIPS .pdata 404aa850..404aa9af. Semantic name remains unreviewed. */

undefined4 FUN_404aa850(int *param_1)

{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  short *psVar5;
  
  psVar5 = (short *)param_1[1];
  if (((short *)param_1[2] < psVar5) || (bVar1 = true, (uint)(param_1[2] - (int)psVar5) < 8)) {
    bVar1 = false;
  }
  if (bVar1) {
    if (*psVar5 == 0x4d4d) {
      param_1[4] = (int)&PTR_PTR_404bd28c;
    }
    else {
      param_1[4] = (int)&PTR_PTR_404bd290;
    }
    psVar5 = psVar5 + 2;
    while( true ) {
      if (((short *)param_1[2] < psVar5) || (bVar1 = true, (uint)(param_1[2] - (int)psVar5) < 4)) {
        bVar1 = false;
      }
      if (!bVar1) {
        return 0x80004005;
      }
      uVar2 = (**(code **)(*(int *)param_1[4] + 4))((int *)param_1[4],*(undefined4 *)psVar5);
      if ((uVar2 == 0) || (puVar3 = FUN_404aa4e0((int)param_1,uVar2), puVar3 == (uint *)0x0)) {
        return 0;
      }
      iVar4 = FUN_404aa148(param_1,(int)puVar3);
      if (iVar4 == 0) break;
      psVar5 = (short *)(*puVar3 * 0xc + puVar3[3] + param_1[1] + 2);
    }
    FUN_404962ec((LPVOID)puVar3[1]);
    FUN_404962ec(puVar3);
  }
  return 0x80004005;
}



/* 404aa9b0 FUN_404aa9b0 */

/* Boundary evidence: original MIPS .pdata 404aa9b0..404aac63. Semantic name remains unreviewed. */

undefined4 FUN_404aa9b0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined1 *puVar9;
  ushort *puVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  
  uVar11 = 0xffffffff;
  uVar13 = 0xffffffff;
  if ((*(short *)(param_2 + 2) == 4) && (*(int *)(param_2 + 4) == 1)) {
    uVar5 = (**(code **)(**(int **)(param_1 + 0x10) + 4))
                      (*(int **)(param_1 + 0x10),**(undefined4 **)(param_2 + 8));
    puVar6 = FUN_404aa4e0(param_1,uVar5);
    uVar5 = 0;
    if (*puVar6 != 0) {
      iVar12 = 0;
      do {
        puVar10 = (ushort *)(puVar6[1] + iVar12);
        uVar8 = (uint)*puVar10;
        if ((uVar8 == 0x502d) || (uVar8 - 0x502d < 2)) {
          if ((puVar10[1] == 4) && (*(int *)(puVar10 + 2) == 1)) {
            uVar4 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                              (*(undefined4 **)(param_1 + 0x10),0x9286);
            puVar9 = *(undefined1 **)(puVar10 + 8);
            *puVar9 = (char)uVar4;
            puVar9[1] = (char)((ushort)uVar4 >> 8);
          }
        }
        else if (uVar8 == 0xa002) {
          if (*(int *)(puVar10 + 2) == 1) {
            uVar1 = puVar10[1];
            iVar2 = param_4;
            uVar8 = uVar5;
            uVar3 = uVar13;
            goto joined_r0x404aab10;
          }
        }
        else if ((uVar8 == 0xa003) && (*(int *)(puVar10 + 2) == 1)) {
          uVar1 = puVar10[1];
          iVar2 = param_5;
          uVar8 = uVar11;
          uVar3 = uVar5;
joined_r0x404aab10:
          if (((uVar1 == 3) || (uVar1 == 4)) && (uVar11 = uVar8, uVar13 = uVar3, iVar2 != 0)) {
            uVar7 = (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),iVar2);
            **(undefined4 **)(puVar10 + 4) = uVar7;
          }
        }
        uVar5 = uVar5 + 1;
        iVar12 = iVar12 + 0x14;
      } while (uVar5 < *puVar6);
      if (((-1 < (int)uVar11) && (-1 < (int)uVar13)) && ((param_3 == 5 || (param_3 == 7)))) {
        uVar5 = puVar6[1];
        uVar4 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),0xa003);
        puVar9 = *(undefined1 **)(uVar11 * 0x14 + uVar5 + 0x10);
        *puVar9 = (char)uVar4;
        puVar9[1] = (char)((ushort)uVar4 >> 8);
        uVar11 = puVar6[1];
        uVar4 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),0xa002);
        puVar9 = *(undefined1 **)(uVar13 * 0x14 + uVar11 + 0x10);
        *puVar9 = (char)uVar4;
        puVar9[1] = (char)((ushort)uVar4 >> 8);
      }
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 0x80004005;
  }
  return uVar7;
}



/* 404aac64 FUN_404aac64 */

/* Boundary evidence: original MIPS .pdata 404aac64..404aadf3. Semantic name remains unreviewed. */

int FUN_404aac64(int param_1,int *param_2,int *param_3,int param_4,int param_5)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  int local_38;
  int local_34;
  int local_30;
  
  iVar4 = *param_2;
  iVar5 = *param_3;
  iVar3 = -0x7fffbffb;
  if ((*(short *)(param_5 + 2) == 4) && (*(int *)(param_5 + 4) == 1)) {
    local_38 = iVar4;
    local_34 = param_1;
    local_30 = param_4;
    uVar1 = (**(code **)(**(int **)(param_4 + 0x10) + 4))
                      (*(int **)(param_4 + 0x10),**(undefined4 **)(param_5 + 8));
    puVar2 = FUN_404aa4e0(param_4,uVar1);
    if (puVar2 != (uint *)0x0) {
      uVar1 = 0;
      if (*puVar2 != 0) {
        iVar7 = 0;
        do {
          puVar6 = (ushort *)(iVar7 + puVar2[1]);
          if (puVar6[1] == 7) {
            iVar3 = FUN_404904d0(local_34,(uint)*puVar6,*(SIZE_T *)(puVar6 + 2),7,
                                 *(void **)(puVar6 + 4));
            if (iVar3 != 0) {
              return iVar3;
            }
            local_38 = *(int *)(puVar6 + 2) + iVar4;
          }
          else {
            iVar4 = FUN_404aa1ac(local_34,puVar6,local_30,&local_38);
            if (iVar4 != 0) {
              return iVar4;
            }
          }
          iVar3 = 0;
          uVar1 = uVar1 + 1;
          iVar5 = iVar5 + 1;
          iVar7 = iVar7 + 0x14;
          iVar4 = local_38;
        } while (uVar1 < *puVar2);
      }
      *param_2 = iVar4;
      *param_3 = iVar5;
    }
  }
  return iVar3;
}



/* 404aadf4 FUN_404aadf4 */

/* Boundary evidence: original MIPS .pdata 404aadf4..404aae3f. Semantic name remains unreviewed. */

void FUN_404aadf4(undefined4 *param_1)

{
  LPVOID pvVar1;
  LPVOID pvVar2;
  
  pvVar1 = (LPVOID)*param_1;
  while (pvVar1 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((int)pvVar1 + 8);
    FUN_404962ec(*(LPVOID *)((int)pvVar1 + 4));
    FUN_404962ec(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* 404aae40 FUN_404aae40 */

/* Boundary evidence: original MIPS .pdata 404aae40..404ab253. Semantic name remains unreviewed. */

undefined4 FUN_404aae40(void *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined2 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  ushort *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint local_44;
  uint *local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int *local_30;
  
  uVar15 = 0xffffffff;
  uVar14 = 0xffffffff;
  local_44 = 0xffffffff;
  bVar3 = false;
  if (5 < param_2) {
    iVar9 = memcmp(param_1,&DAT_404bd294,4);
    bVar2 = true;
    if (iVar9 == 0) goto LAB_404aaeb8;
  }
  bVar2 = false;
LAB_404aaeb8:
  if (bVar2) {
    local_34 = param_2 + 0xfffa & 0xffff;
    local_3c = (int)param_1 + 6;
    local_38 = local_34 + local_3c;
    local_40 = (uint *)0x0;
    local_30 = (int *)0x0;
    iVar9 = FUN_404aa850((int *)&local_40);
    piVar7 = local_30;
    puVar4 = local_40;
    if (-1 < iVar9) {
      for (; puVar4 != (uint *)0x0; puVar4 = (uint *)puVar4[2]) {
        uVar13 = 0;
        if (*puVar4 != 0) {
          iVar9 = 0;
          do {
            puVar12 = (ushort *)(puVar4[1] + iVar9);
            uVar1 = *puVar12;
            if (uVar1 < 0x202) {
              if (uVar1 == 0x201) {
                if ((puVar12[1] == 4) && (*(int *)(puVar12 + 2) == 1)) {
                  uVar8 = (**(code **)*piVar7)(piVar7,0x9286);
                  goto LAB_404ab12c;
                }
              }
              else if (((0xff < uVar1) &&
                       ((((uVar1 < 0x102 || (uVar1 == 0x103)) ||
                         ((0x119 < uVar1 && ((uVar1 < 0x11c || (uVar1 == 0x128)))))) && (bVar3))))
                      && (*(int *)(puVar12 + 2) == 1)) {
                uVar8 = (**(code **)*piVar7)(piVar7,0x9286);
LAB_404ab12c:
                puVar11 = *(undefined1 **)(puVar12 + 8);
                *puVar11 = (char)uVar8;
                puVar11[1] = (char)((ushort)uVar8 >> 8);
              }
            }
            else if (uVar1 == 0x202) {
              if ((puVar12[1] == 4) && (*(int *)(puVar12 + 2) == 1)) {
                uVar8 = (**(code **)*piVar7)(piVar7,0x9286);
                goto LAB_404ab12c;
              }
            }
            else if (uVar1 == 0x8769) {
              FUN_404aa9b0((int)&local_40,(int)puVar12,param_3,param_4,param_5);
            }
            else if (uVar1 == 0xa002) {
              if (*(int *)(puVar12 + 2) == 1) {
                uVar1 = puVar12[1];
                iVar5 = param_4;
                uVar14 = uVar13;
                uVar6 = local_44;
                goto joined_r0x404ab0ac;
              }
            }
            else if ((uVar1 == 0xa003) && (*(int *)(puVar12 + 2) == 1)) {
              uVar1 = puVar12[1];
              iVar5 = param_5;
              uVar14 = uVar15;
              uVar6 = uVar13;
joined_r0x404ab0ac:
              if (((uVar1 == 3) || (uVar1 == 4)) && (uVar15 = uVar14, local_44 = uVar6, iVar5 != 0))
              {
                uVar10 = (**(code **)(*piVar7 + 4))(piVar7,iVar5);
                **(undefined4 **)(puVar12 + 4) = uVar10;
              }
            }
            uVar13 = uVar13 + 1;
            iVar9 = iVar9 + 0x14;
            uVar14 = local_44;
          } while (uVar13 < *puVar4);
        }
        if (((-1 < (int)uVar15) && (-1 < (int)uVar14)) && ((param_3 == 5 || (param_3 == 7)))) {
          uVar13 = puVar4[1];
          uVar8 = (**(code **)*piVar7)(piVar7,0xa003);
          puVar11 = *(undefined1 **)(uVar15 * 0x14 + uVar13 + 0x10);
          *puVar11 = (char)uVar8;
          puVar11[1] = (char)((ushort)uVar8 >> 8);
          uVar13 = puVar4[1];
          uVar8 = (**(code **)*piVar7)(piVar7,0xa002);
          puVar11 = *(undefined1 **)(uVar14 * 0x14 + uVar13 + 0x10);
          *puVar11 = (char)uVar8;
          puVar11[1] = (char)((ushort)uVar8 >> 8);
        }
        bVar3 = true;
      }
    }
    FUN_404aadf4(&local_40);
  }
  return 0;
}



/* 404ab254 FUN_404ab254 */

/* Boundary evidence: original MIPS .pdata 404ab254..404ab723. Semantic name remains unreviewed. */

int FUN_404ab254(int param_1,int *param_2,int *param_3,void *param_4,ushort param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  int local_5c;
  uint local_58;
  int local_54;
  int local_50;
  int local_4c;
  int *local_48;
  int *local_44;
  uint *local_40;
  int local_3c;
  int local_38;
  uint local_34;
  undefined4 local_30;
  
  iVar8 = 0;
  iVar9 = 0;
  local_54 = 0;
  local_50 = 0;
  bVar2 = false;
  iVar7 = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (param_3 == (int *)0x0) {
    return 0;
  }
  if (param_4 == (void *)0x0) {
    return 0;
  }
  local_48 = param_3;
  local_44 = param_2;
  if (5 < param_5) {
    iVar3 = memcmp(param_4,&DAT_404bd294,4);
    bVar1 = true;
    if (iVar3 == 0) goto LAB_404ab304;
  }
  bVar1 = false;
LAB_404ab304:
  if (bVar1) {
    uVar5 = (uint)(ushort)(param_5 - 6);
    local_4c = (int)param_4 + 6;
    local_38 = uVar5 + local_4c;
    local_40 = (uint *)0x0;
    local_30 = 0;
    local_3c = local_4c;
    local_34 = uVar5;
    iVar3 = FUN_404aa850((int *)&local_40);
    if (-1 < iVar3) {
      uVar11 = 0;
      uVar10 = 0;
      puVar12 = local_40;
      do {
        if (puVar12 == (uint *)0x0) {
          *local_48 = *local_48 + iVar9;
          *local_44 = *local_44 + iVar8;
          FUN_404aadf4(&local_40);
          return iVar7;
        }
        local_58 = 0;
        if (*puVar12 != 0) {
          local_5c = 0;
          do {
            puVar6 = (ushort *)(local_5c + puVar12[1]);
            uVar4 = *puVar6;
            if (uVar4 == 0x201) {
              if ((puVar6[1] == 4) && (*(int *)(puVar6 + 2) == 1)) {
                uVar11 = **(uint **)(puVar6 + 4);
                iVar7 = FUN_404904d0(param_1,0x201,4,4,*(uint **)(puVar6 + 4));
                if (iVar7 == 0) {
                  iVar9 = iVar9 + 1;
                  iVar8 = iVar8 + 4;
                  local_54 = iVar8;
                  local_50 = iVar9;
                }
              }
              if ((((uVar10 != 0) && (uVar11 != 0)) && (uVar11 <= uVar5)) &&
                 (((uVar10 <= uVar5 && (uVar10 + uVar11 <= uVar5)) &&
                  (iVar7 = FUN_404904d0(param_1,0x501b,uVar10,1,(void *)(uVar11 + local_4c)),
                  iVar7 == 0)))) {
                iVar9 = iVar9 + 1;
                iVar8 = uVar10 + iVar8;
                local_54 = iVar8;
                local_50 = iVar9;
              }
            }
            else if (uVar4 == 0x202) {
              if ((puVar6[1] == 4) && (*(int *)(puVar6 + 2) == 1)) {
                uVar10 = **(SIZE_T **)(puVar6 + 4);
                iVar7 = FUN_404904d0(param_1,0x202,4,4,*(SIZE_T **)(puVar6 + 4));
                if (iVar7 == 0) {
                  iVar9 = iVar9 + 1;
                  iVar8 = iVar8 + 4;
                  local_54 = iVar8;
                  local_50 = iVar9;
                }
              }
              if ((((uVar10 != 0) && (uVar11 != 0)) && (uVar10 + uVar11 <= uVar5)) &&
                 (iVar7 = FUN_404904d0(param_1,0x501b,uVar10,1,(void *)(uVar11 + local_4c)),
                 iVar7 != 0)) {
                iVar8 = uVar10 + iVar8;
LAB_404ab5d0:
                iVar9 = iVar9 + 1;
                local_54 = iVar8;
                local_50 = iVar9;
              }
            }
            else if (uVar4 == 0x8769) {
              iVar7 = FUN_404aac64(param_1,&local_54,&local_50,(int)&local_40,(int)puVar6);
              iVar8 = local_54;
              iVar9 = local_50;
            }
            else {
              if (!bVar2) goto LAB_404ab47c;
              if (uVar4 == 0x100) {
                uVar4 = 0x5020;
LAB_404ab478:
                *puVar6 = uVar4;
              }
              else if (uVar4 == 0x101) {
                uVar4 = 0x5021;
LAB_404ab46c:
                *puVar6 = uVar4;
              }
              else {
                if (uVar4 == 0x103) {
                  uVar4 = 0x5023;
                  goto LAB_404ab478;
                }
                if (uVar4 == 0x11a) {
                  uVar4 = 0x502d;
                  goto LAB_404ab46c;
                }
                if (uVar4 == 0x11b) {
                  *puVar6 = 0x502e;
                }
                else if (uVar4 == 0x128) {
                  uVar4 = 0x5030;
                  goto LAB_404ab478;
                }
              }
LAB_404ab47c:
              if (puVar6[1] == 7) {
                iVar7 = FUN_404904d0(param_1,(uint)*puVar6,*(SIZE_T *)(puVar6 + 2),7,
                                     *(void **)(puVar6 + 4));
                if (iVar7 == 0) {
                  iVar8 = *(int *)(puVar6 + 2) + iVar8;
                  goto LAB_404ab5d0;
                }
              }
              else {
                iVar7 = FUN_404aa1ac(param_1,puVar6,(int)&local_40,&local_54);
                iVar8 = local_54;
                if (iVar7 == 0) {
                  iVar9 = iVar9 + 1;
                  local_50 = iVar9;
                }
              }
            }
            local_58 = local_58 + 1;
            local_5c = local_5c + 0x14;
          } while (local_58 < *puVar12);
        }
        puVar12 = (uint *)puVar12[2];
        bVar2 = true;
      } while( true );
    }
    FUN_404aadf4(&local_40);
  }
  return 0;
}



/* 404ab724 FUN_404ab724 */

/* Boundary evidence: original MIPS .pdata 404ab724..404aba23. Semantic name remains unreviewed. */

undefined4 FUN_404ab724(int param_1,void *param_2,uint param_3)

{
  short sVar1;
  bool bVar2;
  uint *puVar3;
  int *piVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  short *psVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  uint *local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int *local_30;
  
  if (5 < param_3) {
    iVar6 = memcmp(param_2,&DAT_404bd294,4);
    bVar2 = true;
    if (iVar6 == 0) goto LAB_404ab788;
  }
  bVar2 = false;
LAB_404ab788:
  if (bVar2) {
    local_34 = param_3 + 0xfffa & 0xffff;
    local_3c = (int)param_2 + 6;
    local_38 = local_34 + local_3c;
    local_40 = (uint *)0x0;
    local_30 = (int *)0x0;
    iVar6 = FUN_404aa850((int *)&local_40);
    piVar4 = local_30;
    puVar3 = local_40;
    if (-1 < iVar6) {
      for (; puVar3 != (uint *)0x0; puVar3 = (uint *)puVar3[2]) {
        uVar10 = 0;
        if (*puVar3 != 0) {
          iVar6 = 0;
          do {
            psVar9 = (short *)(puVar3[1] + iVar6);
            sVar1 = *psVar9;
            if (sVar1 == 0x11a) {
              if ((psVar9[1] == 5) && (*(int *)(psVar9 + 2) == 1)) {
                uVar8 = (**(code **)(*piVar4 + 4))(piVar4,**(undefined4 **)(psVar9 + 4));
                uVar11 = __litodp(uVar8);
                uVar8 = (**(code **)(*piVar4 + 4))(piVar4,*(undefined4 *)(*(int *)(psVar9 + 4) + 4))
                ;
                uVar12 = __litodp(uVar8);
                uVar11 = __dpdiv((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                                 (int)((ulonglong)uVar12 >> 0x20));
                uVar5 = __dptoul((int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
                *(undefined2 *)(param_1 + 0x124) = uVar5;
              }
            }
            else if (sVar1 == 0x11b) {
              if ((psVar9[1] == 5) && (*(int *)(psVar9 + 2) == 1)) {
                uVar8 = (**(code **)(*piVar4 + 4))(piVar4,**(undefined4 **)(psVar9 + 4));
                uVar11 = __litodp(uVar8);
                uVar8 = (**(code **)(*piVar4 + 4))(piVar4,*(undefined4 *)(*(int *)(psVar9 + 4) + 4))
                ;
                uVar12 = __litodp(uVar8);
                uVar11 = __dpdiv((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                                 (int)((ulonglong)uVar12 >> 0x20));
                uVar5 = __dptoul((int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
                *(undefined2 *)(param_1 + 0x126) = uVar5;
              }
            }
            else if (((sVar1 == 0x128) && (psVar9[1] == 3)) && (*(int *)(psVar9 + 2) == 1)) {
              iVar7 = (**(code **)*piVar4)(piVar4,**(undefined2 **)(psVar9 + 4));
              if (iVar7 == 2) {
                *(undefined1 *)(param_1 + 0x122) = 1;
              }
              else if (iVar7 == 3) {
                *(undefined1 *)(param_1 + 0x122) = 2;
              }
              else {
                *(undefined1 *)(param_1 + 0x122) = 0;
              }
            }
            uVar10 = uVar10 + 1;
            iVar6 = iVar6 + 0x14;
          } while (uVar10 < *puVar3);
        }
      }
    }
    FUN_404aadf4(&local_40);
  }
  return 0;
}



/* 404aba24 FUN_404aba24 */

/* Boundary evidence: original MIPS .pdata 404aba24..404abaf7. Semantic name remains unreviewed. */

int FUN_404aba24(int *param_1,void *param_2,size_t param_3)

{
  LPVOID _Dst;
  int iVar1;
  undefined **local_20;
  undefined4 local_1c;
  
  if (*param_1 == 0) {
    _Dst = CoTaskMemAlloc(param_3);
    if (_Dst == (LPVOID)0x0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      memcpy(_Dst,param_2,param_3);
      local_1c = 1;
      local_20 = &PTR_FUN_404810e0;
      iVar1 = FUN_40487c08(&local_20,_Dst,param_3,2,param_1);
      if (iVar1 < 0) {
        CoTaskMemFree(_Dst);
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 404abaf8 FUN_404abaf8 */

/* Boundary evidence: original MIPS .pdata 404abaf8..404abd33. Semantic name remains unreviewed. */

int FUN_404abaf8(int *param_1,void *param_2,uint param_3)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint *local_40;
  int local_3c;
  int local_38;
  uint local_34;
  undefined4 local_30;
  
  *param_1 = 0;
  pvVar6 = (void *)0x0;
  uVar7 = 0;
  if (5 < param_3) {
    iVar3 = memcmp(param_2,&DAT_404bd294,4);
    bVar1 = true;
    if (iVar3 == 0) goto LAB_404abb68;
  }
  bVar1 = false;
LAB_404abb68:
  if (bVar1) {
    uVar10 = param_3 + 0xfffa & 0xffff;
    iVar9 = (int)param_2 + 6;
    local_38 = uVar10 + iVar9;
    local_40 = (uint *)0x0;
    local_30 = 0;
    local_3c = iVar9;
    local_34 = uVar10;
    iVar3 = FUN_404aa850((int *)&local_40);
    puVar2 = local_40;
    if (-1 < iVar3) {
      for (; puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[2]) {
        uVar8 = 0;
        if (*puVar2 != 0) {
          iVar3 = 0;
          do {
            psVar5 = (short *)(puVar2[1] + iVar3);
            if (*psVar5 == 0x201) {
              if (((psVar5[1] == 4) && (*(int *)(psVar5 + 2) == 1)) &&
                 (**(uint **)(psVar5 + 4) <= uVar10)) {
                pvVar6 = (void *)(**(uint **)(psVar5 + 4) + iVar9);
              }
            }
            else if (((*psVar5 == 0x202) && (psVar5[1] == 4)) && (*(int *)(psVar5 + 2) == 1)) {
              uVar7 = **(uint **)(psVar5 + 4);
            }
            bVar1 = true;
            if ((pvVar6 != (void *)0x0) && (uVar7 != 0)) {
              if (((void *)(uVar10 + iVar9) < pvVar6) ||
                 ((uint)((int)(uVar10 + iVar9) - (int)pvVar6) < uVar7)) {
                bVar1 = false;
              }
              if (!bVar1) goto LAB_404abcf4;
              iVar4 = FUN_404aba24(param_1,pvVar6,uVar7);
              if (-1 < iVar4) goto LAB_404abcf8;
            }
            uVar8 = uVar8 + 1;
            iVar3 = iVar3 + 0x14;
          } while (uVar8 < *puVar2);
        }
      }
LAB_404abcf4:
      iVar4 = 0;
LAB_404abcf8:
      FUN_404aadf4(&local_40);
      return iVar4;
    }
    FUN_404aadf4(&local_40);
  }
  return 0;
}



/* 404abd34 FUN_404abd34 */

/* Boundary evidence: original MIPS .pdata 404abd34..404abf17. Semantic name remains unreviewed. */

int FUN_404abd34(undefined4 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  int *local_88;
  int *local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  int local_74;
  undefined1 *local_70;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  uint local_5c;
  undefined1 auStack_58 [16];
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_18;
  
  local_18 = DAT_404bd274;
  local_88 = (int *)*param_1;
  (**(code **)(*local_88 + 0x10))(local_88,auStack_58);
  iVar2 = FUN_4048e3bc(local_88,local_44,local_40,local_48,0,&local_84,0,0);
  if (iVar2 < 0) {
    FUN_404a438c(local_18);
    iVar2 = -0x7fffbffb;
  }
  else {
    local_60 = local_44;
    local_68 = 0;
    local_64 = 0;
    local_5c = local_40;
    iVar2 = (**(code **)(*local_84 + 0x14))(local_84,&local_68,2,local_48,&local_80);
    if (-1 < iVar2) {
      if ((local_74 == 0x21808) && (uVar5 = 0, puVar4 = local_70, local_7c != 0)) {
        do {
          uVar3 = 0;
          if (local_80 != 0) {
            do {
              uVar1 = puVar4[2];
              puVar4[2] = *puVar4;
              *puVar4 = uVar1;
              uVar3 = uVar3 + 1;
              puVar4 = puVar4 + 3;
            } while (uVar3 < local_80);
          }
          iVar2 = local_78 * uVar5;
          uVar5 = uVar5 + 1;
          puVar4 = local_70 + iVar2;
        } while (uVar5 < local_7c);
      }
      iVar2 = (**(code **)(*local_84 + 0x18))(local_84,&local_80);
      if (-1 < iVar2) {
        (**(code **)(*local_88 + 8))();
        iVar2 = (**(code **)*local_84)(local_84,&DAT_4048129c,&local_88);
        (**(code **)(*local_84 + 8))();
        if (-1 < iVar2) {
          *param_1 = local_88;
          FUN_404a438c(local_18);
          return 0;
        }
      }
    }
    FUN_404a438c(local_18);
  }
  return iVar2;
}



/* 404abf18 FUN_404abf18 */

/* Boundary evidence: original MIPS .pdata 404abf18..404ac0fb. Semantic name remains unreviewed. */

undefined4 FUN_404abf18(void *param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *_Buf1;
  
  if (0xb < param_2) {
    uVar6 = 10;
    iVar2 = memcmp(param_1,"Photoshop ",10);
    if (iVar2 != 0) {
      uVar6 = 0xf;
      iVar2 = memcmp(param_1,"Adobe_Photoshop",0xf);
      if (iVar2 != 0) {
        return 0;
      }
    }
    for (pcVar3 = (char *)(uVar6 + (int)param_1); (uVar6 < param_2 && (*pcVar3 != '\0'));
        pcVar3 = pcVar3 + 1) {
      uVar6 = uVar6 + 1;
    }
    uVar7 = uVar6 + 1;
    _Buf1 = (byte *)(pcVar3 + 1);
    if (uVar7 < param_2) {
      uVar6 = uVar6 + 0xd;
      while ((uVar6 < param_2 && (iVar2 = memcmp(_Buf1,&DAT_404853dc,4), iVar2 == 0))) {
        uVar1 = *(ushort *)(_Buf1 + 4);
        pbVar4 = _Buf1 + 6;
        uVar1 = uVar1 << 8 | uVar1 >> 8;
        uVar6 = *pbVar4 + 1;
        if ((uVar6 & 1) == 1) {
          uVar6 = *pbVar4 + 2;
        }
        if ((param_2 - uVar7) - 0xc < uVar6) {
          return 0;
        }
        uVar5 = *(uint *)(pbVar4 + uVar6);
        iVar2 = uVar6 + uVar7 + 10;
        uVar7 = (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8 | (uVar5 & 0xff00 | uVar5 << 0x10) << 8;
        if (param_2 - iVar2 < uVar7) {
          return 0;
        }
        if ((uVar1 == 0x409) || (uVar1 == 0x40c)) {
          if (uVar7 < 0x1c) {
            return 0;
          }
          *(ushort *)(_Buf1 + 4) = 0x3fff;
        }
        _Buf1 = (byte *)((int)(pbVar4 + uVar6) + uVar7 + 4);
        uVar7 = uVar7 + iVar2;
        if ((uVar5 >> 0x10 & 0x100) != 0) {
          _Buf1 = _Buf1 + 1;
        }
        uVar6 = uVar7 + 0xc;
      }
    }
  }
  return 0;
}



/* 404ac0fc FUN_404ac0fc */

/* Boundary evidence: original MIPS .pdata 404ac0fc..404aceaf. Semantic name remains unreviewed. */

int FUN_404ac0fc(int param_1,int *param_2,int *param_3,void *param_4,ushort param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint *_Buf1;
  uint uVar16;
  ushort local_170;
  ushort local_16e;
  uint local_16c;
  uint local_168;
  uint local_164;
  uint local_160 [2];
  uint local_158 [3];
  undefined4 local_14c;
  uint local_148;
  uint local_144;
  int *local_140;
  undefined *local_13c;
  int *local_138;
  undefined1 auStack_130 [256];
  uint local_30;
  
  local_30 = DAT_404bd274;
  uVar3 = (uint)param_5;
  iVar10 = 0;
  iVar11 = 0;
  iVar13 = 0;
  local_140 = param_3;
  local_138 = param_2;
  if (0xb < uVar3) {
    iVar1 = memcmp(param_4,"Photoshop ",10);
    if (iVar1 == 0) {
      uVar15 = 10;
    }
    else {
      uVar15 = 0xf;
      iVar1 = memcmp(param_4,"Adobe_Photoshop",0xf);
      if (iVar1 != 0) goto LAB_404ace70;
    }
    for (pcVar5 = (char *)((int)param_4 + uVar15); (uVar15 < uVar3 && (*pcVar5 != '\0'));
        pcVar5 = pcVar5 + 1) {
      uVar15 = uVar15 + 1;
    }
    uVar16 = uVar15 + 1;
    _Buf1 = (uint *)(pcVar5 + 1);
    if (uVar16 < uVar3) {
      iVar1 = iVar11;
      iVar14 = iVar13;
      if (uVar3 <= uVar15 + 0xd) {
LAB_404ace40:
        *local_140 = *local_140 + iVar14;
        *local_138 = *local_138 + iVar1;
        FUN_404a438c(local_30);
        return iVar10;
      }
      local_13c = &DAT_404853dc;
LAB_404ac200:
      iVar2 = memcmp(_Buf1,local_13c,4);
      iVar1 = iVar11;
      iVar14 = iVar13;
      if (iVar2 != 0) {
        iVar10 = 0;
        goto LAB_404ace40;
      }
      uVar8 = ((ushort)_Buf1[1] & 0xff) << 8 | (uint)(ushort)((ushort)_Buf1[1] >> 8);
      uVar15 = (uint)*(byte *)((int)_Buf1 + 6);
      uVar6 = uVar15 + 1;
      if ((uVar6 & 1) == 1) {
        uVar6 = uVar15 + 2;
      }
      if ((uVar3 - uVar16) - 0xc < uVar6) goto LAB_404ace70;
      puVar4 = (uint *)(uVar6 + (int)((int)_Buf1 + 6));
      uVar15 = *puVar4;
      _Buf1 = puVar4 + 1;
      iVar2 = uVar6 + uVar16;
      uVar16 = iVar2 + 10;
      uVar6 = (uVar15 & 0xff0000 | uVar15 >> 0x10) >> 8 | (uVar15 << 0x10 | uVar15 & 0xff00) << 8;
      if (uVar3 - uVar16 < uVar6) goto LAB_404ace70;
      if (uVar8 < 0x407) {
        if (uVar8 == 0x406) {
          if (uVar6 == 2) {
            local_170 = (ushort)*_Buf1 << 8 | (ushort)*_Buf1 >> 8;
            _Buf1 = (uint *)((int)puVar4 + 6);
            iVar10 = FUN_404904d0(param_1,0x5010,2,3,&local_170);
            if (iVar10 != 0) goto LAB_404ace40;
            iVar11 = iVar11 + 2;
          }
          else {
            iVar10 = FUN_404904d0(param_1,0x5010,uVar6,7,_Buf1);
            if (iVar10 != 0) goto LAB_404ace40;
            iVar11 = uVar6 + iVar11;
            _Buf1 = (uint *)(uVar6 + (int)_Buf1);
          }
          uVar16 = uVar6 + uVar16;
          goto LAB_404ace00;
        }
        if (uVar8 == 0x3ed) {
          if (uVar6 == 0x10) {
            local_170 = (ushort)puVar4[2] << 8 | (ushort)puVar4[2] >> 8;
            local_16c = CONCAT22(local_16c._2_2_,
                                 *(ushort *)((int)puVar4 + 10) << 8 |
                                 *(ushort *)((int)puVar4 + 10) >> 8);
            local_16e = (ushort)puVar4[4] << 8 | (ushort)puVar4[4] >> 8;
            uVar16 = *_Buf1;
            _Buf1 = puVar4 + 5;
            local_168 = CONCAT22(local_168._2_2_,
                                 *(ushort *)((int)puVar4 + 0x12) << 8 |
                                 *(ushort *)((int)puVar4 + 0x12) >> 8);
            local_158[1] = 0x10000;
            local_158[0] = (uVar16 & 0xff0000 | uVar16 >> 0x10) >> 8 |
                           (uVar16 << 0x10 | uVar16 & 0xff00) << 8;
            uVar6 = puVar4[3];
            uVar16 = iVar2 + 0x1a;
            iVar10 = FUN_404904d0(param_1,0x11a,8,5,local_158);
            if (iVar10 == 0) {
              local_158[1] = 0x10000;
              local_158[0] = (uVar6 & 0xff0000 | uVar6 >> 0x10) >> 8 |
                             (uVar6 << 0x10 | uVar6 & 0xff00) << 8;
              iVar10 = FUN_404904d0(param_1,0x11b,8,5,local_158);
              iVar1 = iVar11 + 8;
              iVar14 = iVar13 + 1;
              if (iVar10 == 0) {
                iVar10 = FUN_404904d0(param_1,0x5001,2,3,&local_170);
                iVar1 = iVar11 + 0x10;
                iVar14 = iVar13 + 2;
                if (iVar10 == 0) {
                  iVar10 = FUN_404904d0(param_1,0x5002,2,3,&local_16e);
                  iVar1 = iVar11 + 0x12;
                  iVar14 = iVar13 + 3;
                  if (iVar10 == 0) {
                    iVar10 = FUN_404904d0(param_1,0x5003,2,3,&local_16c);
                    iVar1 = iVar11 + 0x14;
                    iVar14 = iVar13 + 4;
                    if (iVar10 == 0) {
                      iVar13 = iVar13 + 5;
                      iVar10 = FUN_404904d0(param_1,0x5004,2,3,&local_168);
                      iVar1 = iVar11 + 0x16;
                      iVar14 = iVar13;
                      if (iVar10 == 0) {
                        iVar11 = iVar11 + 0x18;
                        goto LAB_404ace00;
                      }
                    }
                  }
                }
              }
            }
            goto LAB_404ace40;
          }
        }
        else {
          if (uVar8 == 0x3f3) {
            if ((uVar6 != 7) && (uVar6 != 8)) goto LAB_404ac338;
            iVar10 = FUN_404904d0(param_1,0x5005,uVar6,2,_Buf1);
            if (iVar10 == 0) goto LAB_404acdfc;
            goto LAB_404ace40;
          }
          if (uVar8 == 0x3f5) {
            if (uVar6 != 0x48) goto LAB_404ac338;
            local_164 = 0;
            do {
              uVar8 = *(uint *)((int)_Buf1 + 6);
              local_16e = (ushort)_Buf1[1] << 8 | (ushort)_Buf1[1] >> 8;
              uVar16 = _Buf1[3];
              local_170 = *(ushort *)((int)_Buf1 + 10) << 8 | *(ushort *)((int)_Buf1 + 10) >> 8;
              uVar6 = *_Buf1;
              local_168 = CONCAT31(local_168._1_3_,(byte)_Buf1[4]);
              local_16c = CONCAT31(local_16c._1_3_,*(byte *)((int)_Buf1 + 0x11));
              local_160[0] = (uVar16 << 0x10 | uVar16 & 0xff00) << 8 |
                             (uVar16 & 0xff0000 | uVar16 >> 0x10) >> 8;
              local_14c = 0x10000;
              local_158[2] = (uVar6 & 0xff0000 | uVar6 >> 0x10) >> 8 |
                             (uVar6 << 0x10 | uVar6 & 0xff00) << 8;
              _Buf1 = (uint *)((int)_Buf1 + 0x12);
              iVar10 = FUN_404904d0(param_1,0x500a,8,5,local_158 + 2);
              iVar1 = iVar11;
              iVar14 = iVar13;
              if (iVar10 != 0) goto LAB_404ace40;
              local_14c = 0x10000;
              local_158[2] = (uVar8 & 0xff0000 | uVar8 >> 0x10) >> 8 |
                             (uVar8 << 0x10 | uVar8 & 0xff00) << 8;
              iVar10 = FUN_404904d0(param_1,0x500c,8,5,local_158 + 2);
              iVar1 = iVar11 + 8;
              iVar14 = iVar13 + 1;
              if (iVar10 != 0) goto LAB_404ace40;
              iVar10 = FUN_404904d0(param_1,0x500b,2,3,&local_16e);
              iVar1 = iVar11 + 0x10;
              iVar14 = iVar13 + 2;
              if (iVar10 != 0) goto LAB_404ace40;
              iVar10 = FUN_404904d0(param_1,0x500d,2,3,&local_170);
              iVar1 = iVar11 + 0x12;
              iVar14 = iVar13 + 3;
              if (iVar10 != 0) goto LAB_404ace40;
              iVar1 = iVar11 + 0x14;
              iVar14 = iVar13 + 4;
              if (local_160[0] != 0) {
                iVar10 = FUN_404904d0(param_1,0x500e,4,4,local_160);
                if (iVar10 != 0) goto LAB_404ace40;
                iVar1 = iVar11 + 0x18;
                iVar14 = iVar13 + 5;
              }
              iVar13 = iVar14;
              iVar11 = iVar1;
              if ((char)local_168 != '\0') {
                iVar10 = FUN_404904d0(param_1,0x500f,1,1,&local_168);
                iVar1 = iVar11;
                iVar14 = iVar13;
                if (iVar10 != 0) goto LAB_404ace40;
                iVar13 = iVar13 + 1;
                iVar11 = iVar11 + 1;
              }
              if ((char)local_16c != '\0') {
                iVar10 = FUN_404904d0(param_1,0x500f,1,1,&local_16c);
                iVar1 = iVar11;
                iVar14 = iVar13;
                if (iVar10 != 0) goto LAB_404ace40;
                iVar13 = iVar13 + 1;
                iVar11 = iVar11 + 1;
              }
              local_164 = local_164 + 1;
            } while ((int)local_164 < 4);
            uVar16 = iVar2 + 0x52;
            goto LAB_404ace04;
          }
          if (uVar8 != 0x3f8) goto LAB_404ac91c;
          if (uVar6 == 0x70) {
            iVar10 = FUN_404904d0(param_1,0x501a,0x70,7,_Buf1);
            if (iVar10 == 0) {
              iVar13 = iVar13 + 1;
              iVar11 = iVar11 + 0x70;
              goto LAB_404ac338;
            }
            goto LAB_404ace40;
          }
        }
LAB_404ac338:
        uVar16 = uVar6 + uVar16;
        _Buf1 = (uint *)(uVar6 + (int)_Buf1);
      }
      else {
        if (uVar8 == 0x408) {
          if (0x100 < uVar6) {
            iVar10 = -0x7ff8ffa9;
            goto LAB_404ace40;
          }
          memcpy(auStack_130,_Buf1,uVar6);
          uVar16 = uVar6 + uVar16;
          iVar10 = FUN_404904d0(param_1,0x5011,uVar6,7,auStack_130);
          if (iVar10 != 0) goto LAB_404ace40;
LAB_404acdfc:
          _Buf1 = (uint *)(uVar6 + (int)_Buf1);
          iVar11 = uVar6 + iVar11;
        }
        else if ((uVar8 == 0x409) || (uVar8 == 0x40c)) {
          uVar8 = *_Buf1;
          uVar7 = puVar4[2];
          local_164 = (uVar8 << 0x10 | uVar8 & 0xff00) << 8 |
                      (uVar8 & 0xff0000 | uVar8 >> 0x10) >> 8;
          uVar9 = puVar4[3];
          local_160[0] = (uVar7 << 0x10 | uVar7 & 0xff00) << 8 |
                         (uVar7 & 0xff0000 | uVar7 >> 0x10) >> 8;
          uVar8 = puVar4[4];
          local_16c = (uVar9 & 0xff0000 | uVar9 >> 0x10) >> 8 |
                      (uVar9 << 0x10 | uVar9 & 0xff00) << 8;
          uVar7 = puVar4[5];
          local_168 = (uVar8 & 0xff0000 | uVar8 >> 0x10) >> 8 |
                      (uVar8 << 0x10 | uVar8 & 0xff00) << 8;
          uVar8 = puVar4[6];
          local_148 = (uVar7 & 0xff0000 | uVar7 >> 0x10) >> 8 |
                      (uVar7 << 0x10 | uVar7 & 0xff00) << 8;
          local_144 = (uVar8 & 0xff0000 | uVar8 >> 0x10) >> 8 |
                      (uVar8 << 0x10 | uVar8 & 0xff00) << 8;
          local_170 = (ushort)puVar4[7] << 8 | (ushort)puVar4[7] >> 8;
          local_16e = *(ushort *)((int)puVar4 + 0x1e) << 8 | *(ushort *)((int)puVar4 + 0x1e) >> 8;
          if ((local_164 == 0) || (local_164 == 1)) {
            iVar10 = FUN_404904d0(param_1,0x5012,4,4,&local_164);
            if (iVar10 != 0) goto LAB_404ace40;
            iVar13 = iVar13 + 1;
            iVar11 = iVar11 + 4;
          }
          iVar10 = FUN_404904d0(param_1,0x5013,4,4,local_160);
          iVar1 = iVar11;
          iVar14 = iVar13;
          if (iVar10 != 0) goto LAB_404ace40;
          iVar10 = FUN_404904d0(param_1,0x5014,4,4,&local_16c);
          iVar1 = iVar11 + 4;
          iVar14 = iVar13 + 1;
          if (iVar10 != 0) goto LAB_404ace40;
          iVar10 = FUN_404904d0(param_1,0x5017,4,4,&local_168);
          iVar1 = iVar11 + 8;
          iVar14 = iVar13 + 2;
          if (iVar10 != 0) goto LAB_404ace40;
          iVar10 = FUN_404904d0(param_1,0x5018,4,4,&local_148);
          iVar1 = iVar11 + 0xc;
          iVar14 = iVar13 + 3;
          if (iVar10 != 0) goto LAB_404ace40;
          iVar10 = FUN_404904d0(param_1,0x5019,4,4,&local_144);
          iVar1 = iVar11 + 0x10;
          iVar14 = iVar13 + 4;
          if (iVar10 != 0) goto LAB_404ace40;
          iVar10 = FUN_404904d0(param_1,0x5015,2,3,&local_170);
          iVar1 = iVar11 + 0x14;
          iVar14 = iVar13 + 5;
          if (iVar10 != 0) goto LAB_404ace40;
          iVar13 = iVar13 + 6;
          iVar10 = FUN_404904d0(param_1,0x5016,2,3,&local_16e);
          iVar1 = iVar11 + 0x16;
          iVar14 = iVar13;
          if (iVar10 != 0) goto LAB_404ace40;
          iVar11 = iVar11 + 0x18;
          uVar16 = uVar6 + uVar16;
          _Buf1 = (uint *)((int)puVar4 + uVar6 + 4);
        }
        else {
          if (uVar8 != 10000) {
LAB_404ac91c:
            iVar10 = FUN_404904d0(param_1,uVar8,uVar6,7,_Buf1);
            if (iVar10 == 0) {
              uVar16 = uVar6 + uVar16;
              goto LAB_404acdfc;
            }
            goto LAB_404ace40;
          }
          if (uVar6 != 10) goto LAB_404ac338;
          local_170 = (ushort)*_Buf1 << 8 | (ushort)*_Buf1 >> 8;
          uVar16 = puVar4[2];
          local_16c = CONCAT31(local_16c._1_3_,*(byte *)((int)puVar4 + 6));
          local_164 = (uVar16 & 0xff0000 | uVar16 >> 0x10) >> 8 |
                      (uVar16 << 0x10 | uVar16 & 0xff00) << 8;
          local_16e = (ushort)puVar4[3] << 8 | (ushort)puVar4[3] >> 8;
          _Buf1 = (uint *)((int)puVar4 + 0xe);
          iVar10 = FUN_404904d0(param_1,0x5006,2,3,&local_170);
          if (iVar10 != 0) goto LAB_404ace40;
          iVar14 = iVar13 + 1;
          iVar12 = iVar11 + 2;
          if ((char)local_16c != '\0') {
            iVar10 = FUN_404904d0(param_1,0x5007,1,1,&local_16c);
            iVar1 = iVar12;
            if (iVar10 != 0) goto LAB_404ace40;
            iVar14 = iVar13 + 2;
            iVar12 = iVar11 + 3;
          }
          iVar10 = FUN_404904d0(param_1,0x5008,4,4,&local_164);
          iVar1 = iVar12;
          if (iVar10 != 0) goto LAB_404ace40;
          iVar13 = iVar14 + 1;
          iVar10 = FUN_404904d0(param_1,0x5009,2,3,&local_16e);
          iVar1 = iVar12 + 4;
          iVar14 = iVar13;
          if (iVar10 != 0) goto LAB_404ace40;
          iVar11 = iVar12 + 6;
          uVar16 = iVar2 + 0x14;
        }
LAB_404ace00:
        iVar13 = iVar13 + 1;
      }
LAB_404ace04:
      if ((uVar15 >> 0x10 & 0x100) != 0) {
        _Buf1 = (uint *)((int)_Buf1 + 1);
      }
      iVar1 = iVar11;
      iVar14 = iVar13;
      if (uVar3 <= uVar16 + 0xc) goto LAB_404ace40;
      goto LAB_404ac200;
    }
  }
LAB_404ace70:
  FUN_404a438c(local_30);
  return 0;
}



/* 404aceb0 FUN_404aceb0 */

/* Boundary evidence: original MIPS .pdata 404aceb0..404ad1db. Semantic name remains unreviewed. */

undefined4 FUN_404aceb0(int param_1,void *param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  uint *puVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *_Buf1;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  
  if (0xb < param_3) {
    uVar6 = 10;
    iVar2 = memcmp(param_2,"Photoshop ",10);
    if (iVar2 != 0) {
      uVar6 = 0xf;
      iVar2 = memcmp(param_2,"Adobe_Photoshop",0xf);
      if (iVar2 != 0) {
        return 0;
      }
    }
    for (pcVar4 = (char *)(uVar6 + (int)param_2); (uVar6 < param_3 && (*pcVar4 != '\0'));
        pcVar4 = pcVar4 + 1) {
      uVar6 = uVar6 + 1;
    }
    uVar7 = uVar6 + 1;
    _Buf1 = (uint *)(pcVar4 + 1);
    if (uVar7 < param_3) {
      uVar6 = uVar6 + 0xd;
      while ((uVar6 < param_3 && (iVar2 = memcmp(_Buf1,&DAT_404853dc,4), iVar2 == 0))) {
        uVar6 = (uint)*(byte *)((int)_Buf1 + 6);
        uVar5 = uVar6 + 1;
        if ((uVar5 & 1) == 1) {
          uVar5 = uVar6 + 2;
        }
        if ((param_3 - uVar7) - 0xc < uVar5) {
          return 0;
        }
        puVar3 = (uint *)((byte *)((int)_Buf1 + 6) + uVar5);
        uVar6 = *puVar3;
        iVar2 = uVar5 + uVar7 + 10;
        uVar8 = (uVar6 & 0xff0000 | uVar6 >> 0x10) >> 8 | (uVar6 << 0x10 | uVar6 & 0xff00) << 8;
        if (param_3 - iVar2 < uVar8) {
          return 0;
        }
        if (((ushort)((ushort)_Buf1[1] << 8 | (ushort)_Buf1[1] >> 8) == 0x3ed) && (uVar8 == 0x10)) {
          uVar8 = puVar3[3];
          _Buf1 = puVar3 + 5;
          uVar9 = puVar3[1];
          uVar7 = uVar5 + uVar7 + 0x1a;
          if (((int)((uint)(ushort)puVar3[2] << 0x18) >> 0x10 |
              (uint)(ushort)((ushort)puVar3[2] >> 8)) ==
              ((int)((uint)(ushort)puVar3[4] << 0x18) >> 0x10 |
              (uint)(ushort)((ushort)puVar3[4] >> 8))) {
            uVar10 = __litodp((uVar9 & 0xff0000 | uVar9 >> 0x10) >> 8 |
                              (uVar9 << 0x10 | uVar9 & 0xff00) << 8);
            uVar10 = __dpmul((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,0x3ef00000);
            uVar10 = __dpadd((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,0x3fe00000);
            uVar1 = __dptoul((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
            *(undefined2 *)(param_1 + 0x124) = uVar1;
            uVar10 = __litodp((uVar8 & 0xff0000 | uVar8 >> 0x10) >> 8 |
                              (uVar8 << 0x10 | uVar8 & 0xff00) << 8);
            uVar10 = __dpmul((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,0x3ef00000);
            uVar10 = __dpadd((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,0x3fe00000);
            uVar1 = __dptoul((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
            *(undefined2 *)(param_1 + 0x126) = uVar1;
            *(undefined1 *)(param_1 + 0x122) = 1;
          }
        }
        else {
          uVar7 = uVar8 + iVar2;
          _Buf1 = (uint *)(uVar8 + (int)(puVar3 + 1));
        }
        if ((uVar6 >> 0x10 & 0x100) != 0) {
          _Buf1 = (uint *)((int)_Buf1 + 1);
        }
        uVar6 = uVar7 + 0xc;
      }
    }
  }
  return 0;
}



/* 404ad1dc FUN_404ad1dc */

/* Boundary evidence: original MIPS .pdata 404ad1dc..404ad33f. Semantic name remains unreviewed. */

int FUN_404ad1dc(undefined4 param_1,int *param_2,uint *param_3,int param_4,int param_5)

{
  int iVar1;
  LPVOID _Dst;
  uint uVar2;
  uint uVar3;
  undefined **local_20;
  undefined4 local_1c;
  
  uVar2 = param_3[5];
  uVar3 = *param_3;
  uVar2 = (uVar2 & 0xff0000 | uVar2 >> 0x10) >> 8 | (uVar2 << 0x10 | uVar2 & 0xff00) << 8;
  if (uVar2 == param_4 - 0x1cU) {
    if (((uVar3 & 0xff0000 | uVar3 >> 0x10) >> 8 | (uVar3 << 0x10 | uVar3 & 0xff00) << 8) == 1) {
      _Dst = CoTaskMemAlloc(uVar2);
      if (_Dst == (LPVOID)0x0) {
        return -0x7ff8fff2;
      }
      memcpy(_Dst,param_3 + 7,uVar2);
      local_1c = 1;
      local_20 = &PTR_FUN_404810e0;
      iVar1 = FUN_40487c08(&local_20,_Dst,uVar2,2,param_2);
      if (iVar1 < 0) {
        CoTaskMemFree(_Dst);
      }
      if (param_5 == 1) {
        if (*param_2 != 0) {
          iVar1 = FUN_404abd34(param_2);
          return iVar1;
        }
        goto LAB_404ad240;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_404ad240:
    iVar1 = -0x7ff8ffa9;
  }
  return iVar1;
}



/* 404ad340 FUN_404ad340 */

/* Boundary evidence: original MIPS .pdata 404ad340..404ad557. Semantic name remains unreviewed. */

int FUN_404ad340(int *param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  char *pcVar4;
  byte *pbVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  
  *param_1 = 0;
  if (0xb < param_3) {
    uVar8 = 10;
    iVar1 = memcmp(param_2,"Photoshop ",10);
    if (iVar1 != 0) {
      uVar8 = 0xf;
      iVar1 = memcmp(param_2,"Adobe_Photoshop",0xf);
      if (iVar1 != 0) {
        return 0;
      }
    }
    for (pcVar4 = (char *)(uVar8 + (int)param_2); (uVar8 < param_3 && (*pcVar4 != '\0'));
        pcVar4 = pcVar4 + 1) {
      uVar8 = uVar8 + 1;
    }
    uVar9 = uVar8 + 1;
    pcVar4 = pcVar4 + 1;
    if (uVar9 < param_3) {
      uVar8 = uVar8 + 0xd;
      while ((uVar8 < param_3 && (iVar1 = memcmp(pcVar4,&DAT_404853dc,4), iVar1 == 0))) {
        pbVar5 = (byte *)(pcVar4 + 6);
        uVar7 = *(ushort *)(pcVar4 + 4) << 8 | *(ushort *)(pcVar4 + 4) >> 8;
        uVar8 = *pbVar5 + 1;
        if ((uVar8 & 1) == 1) {
          uVar8 = *pbVar5 + 2;
        }
        if ((param_3 - uVar9) - 0xc < uVar8) {
          return 0;
        }
        uVar6 = *(uint *)(pbVar5 + uVar8);
        puVar2 = (uint *)((int)(pbVar5 + uVar8) + 4);
        iVar1 = uVar8 + uVar9 + 10;
        uVar3 = (uVar6 & 0xff0000 | uVar6 >> 0x10) >> 8 | (uVar6 & 0xff00 | uVar6 << 0x10) << 8;
        if (param_3 - iVar1 < uVar3) {
          return 0;
        }
        if (uVar7 == 0x40c) {
          iVar1 = FUN_404ad1dc(0,param_1,puVar2,uVar3,0);
          return iVar1;
        }
        if (uVar7 == 0x409) {
          iVar1 = FUN_404ad1dc(0,param_1,puVar2,uVar3,1);
          return iVar1;
        }
        if ((uVar6 >> 0x10 & 0x100) != 0) {
          uVar3 = uVar3 + 1;
        }
        uVar9 = uVar3 + iVar1;
        uVar8 = uVar9 + 0xc;
        pcVar4 = (char *)(uVar3 + (int)puVar2);
      }
    }
  }
  return 0;
}



/* 404ad558 FUN_404ad558 */

/* Boundary evidence: original MIPS .pdata 404ad558..404ad69f. Semantic name remains unreviewed. */

int FUN_404ad558(int param_1,int *param_2,int *param_3,void *param_4,ushort param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  SIZE_T SVar4;
  int iVar5;
  SIZE_T SVar6;
  
  iVar3 = 0;
  SVar4 = 0;
  iVar5 = 0;
  if ((param_5 < 0xe) || (iVar2 = memcmp(param_4,"ICC_PROFILE",0xc), iVar2 != 0)) {
LAB_404ad668:
    iVar3 = 0;
  }
  else {
    cVar1 = *(char *)((int)param_4 + 0xc);
    if (cVar1 == '\x01') {
      if (*(char *)((int)param_4 + 0xd) < '\x01') {
        return -0x7fffbffb;
      }
      SVar6 = param_5 - 0xe;
      iVar3 = FUN_404904d0(param_1,0x8773,SVar6,1,(void *)((int)param_4 + 0xe));
      if (iVar3 == 0) {
        iVar5 = 1;
        SVar4 = SVar6;
      }
    }
    else if (((*(char *)((int)param_4 + 0xd) == '\0') && ('\0' < cVar1)) && (cVar1 < '\x01'))
    goto LAB_404ad668;
    *param_3 = *param_3 + iVar5;
    *param_2 = *param_2 + SVar4;
  }
  return iVar3;
}



/* 404ad6a0 FUN_404ad6a0 */

/* Boundary evidence: original MIPS .pdata 404ad6a0..404ad6d7. Semantic name remains unreviewed. */

void FUN_404ad6a0(int *param_1)

{
  (**(code **)(*param_1 + 8))(param_1);
  FUN_404b0788((int)param_1);
  return;
}



/* 404ad6d8 FUN_404ad6d8 */

/* Boundary evidence: original MIPS .pdata 404ad6d8..404ad70f. Semantic name remains unreviewed. */

void FUN_404ad6d8(int *param_1)

{
  undefined1 auStack_d8 [200];
  uint local_10;
  
  local_10 = DAT_404bd274;
  (**(code **)(*param_1 + 0xc))(param_1,auStack_d8);
  FUN_404a438c(local_10);
  return;
}



/* 404ad710 FUN_404ad710 */

/* Boundary evidence: original MIPS .pdata 404ad710..404ad787. Semantic name remains unreviewed. */

void FUN_404ad710(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 < 0) {
    if ((*(int *)(iVar1 + 0x6c) == 0) || (2 < *(int *)(iVar1 + 0x68))) {
      (**(code **)(iVar1 + 8))();
    }
    *(int *)(iVar1 + 0x6c) = *(int *)(iVar1 + 0x6c) + 1;
  }
  else if (param_2 <= *(int *)(iVar1 + 0x68)) {
    (**(code **)(iVar1 + 8))();
  }
  return;
}



/* 404ad854 FUN_404ad854 */

undefined4 * FUN_404ad854(undefined4 *param_1)

{
  *param_1 = FUN_404ad6a0;
  param_1[1] = FUN_404ad710;
  param_1[3] = &LAB_404ad788;
  param_1[4] = &LAB_404ad840;
  param_1[2] = FUN_404ad6d8;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[5] = 0;
  param_1[0x1c] = &PTR_s_Bogus_message_code__d_40486698;
  param_1[0x1d] = 0x7b;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  return param_1;
}



/* 404ad8c4 FUN_404ad8c4 */

/* Boundary evidence: original MIPS .pdata 404ad8c4..404ad967. Semantic name remains unreviewed. */

undefined4 FUN_404ad8c4(int *param_1)

{
  int iVar1;
  
  if (param_1[5] != 0xcc) {
    (**(code **)param_1[0x6a])(param_1);
    param_1[0x23] = 0;
    param_1[5] = 0xcc;
  }
  iVar1 = *(int *)(param_1[0x6a] + 8);
  while (iVar1 != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x30;
    (**(code **)*param_1)(param_1);
    iVar1 = *(int *)(param_1[0x6a] + 8);
  }
  iVar1 = 0xce;
  if (param_1[0x11] == 0) {
    iVar1 = 0xcd;
  }
  param_1[5] = iVar1;
  return 1;
}



/* 404ad968 FUN_404ad968 */

/* Boundary evidence: original MIPS .pdata 404ad968..404ada6b. Semantic name remains unreviewed. */

int FUN_404ad968(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int local_18 [2];
  
  if (param_1[5] != 0xcd) {
    *(undefined4 *)(*param_1 + 0x14) = 0x14;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  if ((uint)param_1[0x23] < (uint)param_1[0x1d]) {
    if (param_1[2] != 0) {
      *(int *)(param_1[2] + 4) = param_1[0x23];
      *(int *)(param_1[2] + 8) = param_1[0x1d];
      (**(code **)param_1[2])(param_1);
    }
    local_18[0] = 0;
    (**(code **)(param_1[0x6b] + 4))(param_1,param_2,local_18,param_3);
    param_1[0x23] = local_18[0] + param_1[0x23];
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x7b;
    (**(code **)(*param_1 + 4))(param_1,0xffffffff);
    local_18[0] = 0;
  }
  return local_18[0];
}



/* 404ada6c FUN_404ada6c */

/* Boundary evidence: original MIPS .pdata 404ada6c..404adbdf. Semantic name remains unreviewed. */

undefined4 FUN_404ada6c(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1[5] == 0xca) {
    FUN_404b11b8(param_1);
    if (param_1[0x10] != 0) {
      param_1[5] = 0xcf;
      return 1;
    }
    param_1[5] = 0xcb;
  }
  if (param_1[5] == 0xcb) {
    if (*(int *)(param_1[0x6e] + 0x10) != 0) {
      while( true ) {
        if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
          (**(code **)param_1[2])(param_1);
        }
        iVar1 = (**(code **)param_1[0x6e])(param_1);
        if (iVar1 == 0) {
          return 0;
        }
        if (iVar1 == 2) break;
        iVar3 = param_1[2];
        if ((iVar3 != 0) && ((iVar1 == 3 || (iVar1 == 1)))) {
          *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
          iVar1 = param_1[2];
          if (*(int *)(iVar1 + 8) <= *(int *)(iVar1 + 4)) {
            *(int *)(iVar1 + 8) = param_1[0x51] + *(int *)(iVar1 + 8);
          }
        }
      }
    }
    param_1[0x27] = param_1[0x25];
  }
  else if (param_1[5] != 0xcc) {
    *(undefined4 *)(*param_1 + 0x14) = 0x14;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  uVar2 = FUN_404ad8c4(param_1);
  return uVar2;
}



/* 404adbe0 FUN_404adbe0 */

/* Boundary evidence: original MIPS .pdata 404adbe0..404add07. Semantic name remains unreviewed. */

void FUN_404adbe0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  param_1[1] = 0;
  if (param_2 != 0x3e) {
    *(undefined4 *)(*param_1 + 0x14) = 0xc;
    *(undefined4 *)(*param_1 + 0x18) = 0x3e;
    *(int *)(*param_1 + 0x1c) = param_2;
    (**(code **)*param_1)(param_1);
  }
  if (param_3 != 0x1d8) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(undefined4 *)(*param_1 + 0x18) = 0x1d8;
    *(int *)(*param_1 + 0x1c) = param_3;
    (**(code **)*param_1)(param_1);
  }
  iVar2 = *param_1;
  iVar1 = param_1[3];
  memset(param_1,0,0x1d8);
  *param_1 = iVar2;
  param_1[3] = iVar1;
  param_1[4] = 1;
  FUN_404b2dc8(param_1);
  param_1[2] = 0;
  param_1[6] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x32] = 0;
  param_1[0x2f] = 0;
  param_1[0x33] = 0;
  param_1[0x30] = 0;
  param_1[0x34] = 0;
  param_1[0x31] = 0;
  param_1[0x35] = 0;
  param_1[0x4d] = 0;
  FUN_404b04bc((int)param_1);
  FUN_404b1a08((int)param_1);
  param_1[5] = 200;
  return;
}



/* 404add08 FUN_404add08 */

/* Boundary evidence: original MIPS .pdata 404add08..404add23. Semantic name remains unreviewed. */

void FUN_404add08(int param_1)

{
  FUN_404b0788(param_1);
  return;
}



/* 404add24 FUN_404add24 */

/* Boundary evidence: original MIPS .pdata 404add24..404add3f. Semantic name remains unreviewed. */

void FUN_404add24(int param_1)

{
  FUN_404b071c(param_1);
  return;
}



/* 404add40 FUN_404add40 */

/* Boundary evidence: original MIPS .pdata 404add40..404adf73. Semantic name remains unreviewed. */

void FUN_404add40(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_1[9];
  if (iVar1 == 1) {
    param_1[10] = 1;
    param_1[0xb] = 1;
    goto LAB_404adf0c;
  }
  if (iVar1 != 3) {
    if (iVar1 == 4) {
      if ((param_1[0x4a] == 0) || ((char)param_1[0x4b] == '\0')) {
        param_1[10] = 4;
        param_1[0xb] = 4;
      }
      else if ((char)param_1[0x4b] == '\x02') {
        param_1[10] = 5;
        param_1[0xb] = 4;
      }
      else {
        *(undefined4 *)(*param_1 + 0x14) = 0x72;
        *(uint *)(*param_1 + 0x18) = (uint)*(byte *)(param_1 + 0x4b);
        (**(code **)(*param_1 + 4))(param_1,0xffffffff);
        param_1[0xb] = 4;
        param_1[10] = 5;
      }
    }
    else {
      param_1[10] = 0;
      param_1[0xb] = 0;
    }
    goto LAB_404adf0c;
  }
  if (param_1[0x47] == 0) {
    if (param_1[0x4a] == 0) {
      piVar2 = (int *)param_1[0x37];
      iVar5 = *piVar2;
      iVar1 = piVar2[0x15];
      iVar4 = piVar2[0x2a];
      if (iVar5 == 1) {
        if ((iVar1 == 2) && (iVar4 == 3)) goto LAB_404adec8;
      }
      else if (((iVar5 == 0x52) && (iVar1 == 0x47)) && (iVar4 == 0x42)) goto LAB_404adef8;
      iVar3 = *param_1;
      *(int *)(iVar3 + 0x18) = iVar5;
      *(int *)(iVar3 + 0x1c) = iVar1;
      *(int *)(iVar3 + 0x20) = iVar4;
      *(undefined4 *)(*param_1 + 0x14) = 0x6f;
      (**(code **)(*param_1 + 4))(param_1,1);
    }
    else {
      if ((char)param_1[0x4b] == '\0') {
LAB_404adef8:
        param_1[10] = 2;
        param_1[0xb] = 2;
        goto LAB_404adf0c;
      }
      if ((char)param_1[0x4b] != '\x01') {
        *(undefined4 *)(*param_1 + 0x14) = 0x72;
        *(uint *)(*param_1 + 0x18) = (uint)*(byte *)(param_1 + 0x4b);
        (**(code **)(*param_1 + 4))(param_1,0xffffffff);
        param_1[10] = 3;
        param_1[0xb] = 2;
        goto LAB_404adf0c;
      }
    }
  }
LAB_404adec8:
  param_1[10] = 3;
  param_1[0xb] = 2;
LAB_404adf0c:
  param_1[0xf] = 0x3ff00000;
  param_1[0xc] = 1;
  param_1[0xd] = 1;
  param_1[0x13] = 1;
  param_1[0x14] = 1;
  param_1[0x16] = 2;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x15] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0x100;
  param_1[0x22] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  return;
}



/* 404adf74 FUN_404adf74 */

/* Boundary evidence: original MIPS .pdata 404adf74..404ae08f. Semantic name remains unreviewed. */

int FUN_404adf74(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  switch(param_1[5]) {
  case 200:
    (**(code **)(param_1[0x6e] + 4))(param_1);
    (**(code **)(param_1[6] + 8))(param_1);
    param_1[5] = 0xc9;
  case 0xc9:
    iVar1 = (**(code **)param_1[0x6e])(param_1);
    if (iVar1 == 1) {
      FUN_404add40(param_1);
      param_1[5] = 0xca;
    }
    break;
  case 0xca:
    iVar1 = 1;
    break;
  case 0xcb:
  case 0xcc:
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd2:
    iVar1 = (**(code **)param_1[0x6e])(param_1);
    break;
  default:
    *(undefined4 *)(*param_1 + 0x14) = 0x14;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  return iVar1;
}



/* 404ae090 FUN_404ae090 */

/* Boundary evidence: original MIPS .pdata 404ae090..404ae1d7. Semantic name remains unreviewed. */

undefined4 FUN_404ae090(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[5];
  if (((iVar1 == 0xcd) || (iVar1 == 0xce)) && (param_1[0x10] == 0)) {
    if ((uint)param_1[0x23] < (uint)param_1[0x1d]) {
      *(undefined4 *)(*param_1 + 0x14) = 0x43;
      (**(code **)*param_1)(param_1);
    }
    (**(code **)(param_1[0x6a] + 4))(param_1);
    param_1[5] = 0xd2;
  }
  else if (iVar1 == 0xcf) {
    param_1[5] = 0xd2;
  }
  else if (iVar1 != 0xd2) {
    *(undefined4 *)(*param_1 + 0x14) = 0x14;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  iVar1 = *(int *)(param_1[0x6e] + 0x14);
  while( true ) {
    if (iVar1 != 0) {
      (**(code **)(param_1[6] + 0x18))(param_1);
      FUN_404b071c((int)param_1);
      return 1;
    }
    iVar1 = (**(code **)param_1[0x6e])(param_1);
    if (iVar1 == 0) break;
    iVar1 = *(int *)(param_1[0x6e] + 0x14);
  }
  return 0;
}



/* 404ae1d8 FUN_404ae1d8 */

/* Boundary evidence: original MIPS .pdata 404ae1d8..404ae2a3. Semantic name remains unreviewed. */

int FUN_404ae1d8(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1[5] != 200) && (param_1[5] != 0xc9)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x14;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  iVar1 = FUN_404adf74(param_1);
  if (iVar1 == 1) {
    iVar1 = 1;
  }
  else if (iVar1 == 2) {
    if (param_2 != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x33;
      (**(code **)*param_1)(param_1);
    }
    FUN_404b071c((int)param_1);
    iVar1 = 2;
  }
  return iVar1;
}



/* 404ae2a4 FUN_404ae2a4 */

/* Boundary evidence: original MIPS .pdata 404ae2a4..404ae377. Semantic name remains unreviewed. */

undefined4 FUN_404ae2a4(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0x14) = 0x66;
  (**(code **)(*param_1 + 4))(param_1,1);
  if (*(int *)(param_1[0x6f] + 0xc) != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x3d;
    (**(code **)*param_1)(param_1);
  }
  piVar1 = param_1 + 0x3a;
  iVar2 = 0x10;
  do {
    *(undefined1 *)piVar1 = 0;
    *(undefined1 *)(piVar1 + 4) = 1;
    *(undefined1 *)(piVar1 + 8) = 5;
    iVar2 = iVar2 + -1;
    piVar1 = (int *)((int)piVar1 + 1);
  } while (iVar2 != 0);
  *(undefined1 *)(param_1 + 0x48) = 1;
  *(undefined1 *)((int)param_1 + 0x121) = 1;
  *(undefined2 *)(param_1 + 0x49) = 1;
  *(undefined2 *)((int)param_1 + 0x126) = 1;
  param_1[0x46] = 0;
  param_1[10] = 0;
  param_1[0x4c] = 0;
  param_1[0x47] = 0;
  *(undefined1 *)((int)param_1 + 0x122) = 0;
  param_1[0x4a] = 0;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  *(undefined4 *)(param_1[0x6f] + 0xc) = 1;
  return 1;
}



/* 404ae378 FUN_404ae378 */

/* Boundary evidence: original MIPS .pdata 404ae378..404ae7c3. Semantic name remains unreviewed. */

undefined4 FUN_404ae378(int *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  
  puVar7 = (undefined4 *)param_1[6];
  pbVar4 = (byte *)*puVar7;
  iVar3 = puVar7[1];
  param_1[0x38] = param_2;
  param_1[0x39] = param_3;
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar7[3])(param_1);
    if (iVar3 != 0) {
      pbVar4 = (byte *)*puVar7;
      iVar3 = puVar7[1];
      goto LAB_404ae3e0;
    }
LAB_404ae3d0:
    uVar8 = 0;
  }
  else {
LAB_404ae3e0:
    iVar3 = iVar3 + -1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar7[3])(param_1);
      if (iVar3 == 0) goto LAB_404ae3d0;
      pbVar4 = (byte *)*puVar7;
      iVar3 = puVar7[1];
    }
    bVar2 = *pbVar4;
    iVar3 = iVar3 + -1;
    pbVar4 = pbVar4 + 1;
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar7[3])(param_1);
      if (iVar3 == 0) goto LAB_404ae3d0;
      pbVar4 = (byte *)*puVar7;
      iVar3 = puVar7[1];
    }
    iVar3 = iVar3 + -1;
    pbVar5 = pbVar4 + 1;
    param_1[0x36] = (uint)*pbVar4;
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar7[3])(param_1);
      if (iVar3 == 0) goto LAB_404ae3d0;
      pbVar5 = (byte *)*puVar7;
      iVar3 = puVar7[1];
    }
    iVar3 = iVar3 + -1;
    param_1[8] = (uint)*pbVar5 << 8;
    pbVar5 = pbVar5 + 1;
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar7[3])(param_1);
      if (iVar3 == 0) goto LAB_404ae3d0;
      pbVar5 = (byte *)*puVar7;
      iVar3 = puVar7[1];
    }
    iVar3 = iVar3 + -1;
    pbVar4 = pbVar5 + 1;
    param_1[8] = (uint)*pbVar5 + param_1[8];
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar7[3])(param_1);
      if (iVar3 == 0) goto LAB_404ae3d0;
      pbVar4 = (byte *)*puVar7;
      iVar3 = puVar7[1];
    }
    iVar3 = iVar3 + -1;
    param_1[7] = (uint)*pbVar4 << 8;
    pbVar4 = pbVar4 + 1;
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar7[3])(param_1);
      if (iVar3 == 0) goto LAB_404ae3d0;
      pbVar4 = (byte *)*puVar7;
      iVar3 = puVar7[1];
    }
    iVar3 = iVar3 + -1;
    pbVar5 = pbVar4 + 1;
    param_1[7] = (uint)*pbVar4 + param_1[7];
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar7[3])(param_1);
      if (iVar3 == 0) goto LAB_404ae3d0;
      pbVar5 = (byte *)*puVar7;
      iVar3 = puVar7[1];
    }
    pbVar4 = pbVar5 + 1;
    param_1[9] = (uint)*pbVar5;
    iVar6 = *param_1;
    iVar3 = iVar3 + -1;
    *(int *)(iVar6 + 0x18) = param_1[0x69];
    *(int *)(iVar6 + 0x1c) = param_1[7];
    *(int *)(iVar6 + 0x20) = param_1[8];
    *(int *)(iVar6 + 0x24) = param_1[9];
    *(undefined4 *)(*param_1 + 0x14) = 100;
    uVar8 = 1;
    (**(code **)(*param_1 + 4))(param_1,1);
    if (*(int *)(param_1[0x6f] + 0x10) != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x3a;
      (**(code **)*param_1)(param_1);
    }
    if (((param_1[8] == 0) || (param_1[7] == 0)) || (param_1[9] < 1)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x20;
      (**(code **)*param_1)(param_1);
    }
    if ((uint)bVar2 + (uint)bVar1 * 0x100 + -8 != param_1[9] * 3) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[0x37] == 0) {
      iVar6 = (**(code **)param_1[1])(param_1,1,param_1[9] * 0x54);
      param_1[0x37] = iVar6;
    }
    puVar9 = (uint *)param_1[0x37];
    uVar10 = 0;
    if (0 < param_1[9]) {
      do {
        puVar9[1] = uVar10;
        if (iVar3 == 0) {
          iVar3 = (*(code *)puVar7[3])(param_1);
          if (iVar3 == 0) goto LAB_404ae3d0;
          pbVar4 = (byte *)*puVar7;
          iVar3 = puVar7[1];
        }
        iVar3 = iVar3 + -1;
        pbVar5 = pbVar4 + 1;
        *puVar9 = (uint)*pbVar4;
        if (iVar3 == 0) {
          iVar3 = (*(code *)puVar7[3])(param_1);
          if (iVar3 == 0) goto LAB_404ae3d0;
          pbVar5 = (byte *)*puVar7;
          iVar3 = puVar7[1];
        }
        bVar1 = *pbVar5;
        iVar3 = iVar3 + -1;
        pbVar5 = pbVar5 + 1;
        puVar9[2] = (int)(uint)bVar1 >> 4;
        puVar9[3] = bVar1 & 0xf;
        if (iVar3 == 0) {
          iVar3 = (*(code *)puVar7[3])(param_1);
          if (iVar3 == 0) goto LAB_404ae3d0;
          pbVar5 = (byte *)*puVar7;
          iVar3 = puVar7[1];
        }
        iVar3 = iVar3 + -1;
        puVar9[4] = (uint)*pbVar5;
        iVar6 = *param_1;
        *(uint *)(iVar6 + 0x18) = *puVar9;
        *(uint *)(iVar6 + 0x1c) = puVar9[2];
        *(uint *)(iVar6 + 0x20) = puVar9[3];
        *(uint *)(iVar6 + 0x24) = puVar9[4];
        *(undefined4 *)(*param_1 + 0x14) = 0x65;
        pbVar4 = pbVar5 + 1;
        (**(code **)(*param_1 + 4))(param_1,1);
        uVar10 = uVar10 + 1;
        puVar9 = puVar9 + 0x15;
      } while ((int)uVar10 < param_1[9]);
    }
    *(undefined4 *)(param_1[0x6f] + 0x10) = 1;
    *puVar7 = pbVar4;
    puVar7[1] = iVar3;
  }
  return uVar8;
}



/* 404ae7c4 FUN_404ae7c4 */

/* Boundary evidence: original MIPS .pdata 404ae7c4..404aebbb. Semantic name remains unreviewed. */

undefined4 FUN_404ae7c4(int *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  byte *pbVar9;
  undefined4 uVar10;
  int *local_30;
  int local_2c;
  
  puVar6 = (undefined4 *)param_1[6];
  pbVar9 = (byte *)*puVar6;
  iVar7 = puVar6[1];
  if (*(int *)(param_1[0x6f] + 0x10) == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x3e;
    (**(code **)*param_1)(param_1);
  }
  if (iVar7 == 0) {
    iVar7 = (*(code *)puVar6[3])(param_1);
    if (iVar7 != 0) {
      pbVar9 = (byte *)*puVar6;
      iVar7 = puVar6[1];
      goto LAB_404ae854;
    }
LAB_404ae844:
    uVar10 = 0;
  }
  else {
LAB_404ae854:
    bVar1 = *pbVar9;
    iVar7 = iVar7 + -1;
    pbVar9 = pbVar9 + 1;
    if (iVar7 == 0) {
      iVar7 = (*(code *)puVar6[3])(param_1);
      if (iVar7 == 0) goto LAB_404ae844;
      pbVar9 = (byte *)*puVar6;
      iVar7 = puVar6[1];
    }
    bVar2 = *pbVar9;
    iVar7 = iVar7 + -1;
    pbVar9 = pbVar9 + 1;
    if (iVar7 == 0) {
      iVar7 = (*(code *)puVar6[3])(param_1);
      if (iVar7 == 0) goto LAB_404ae844;
      pbVar9 = (byte *)*puVar6;
      iVar7 = puVar6[1];
    }
    uVar3 = (uint)*pbVar9;
    *(undefined4 *)(*param_1 + 0x14) = 0x67;
    *(uint *)(*param_1 + 0x18) = uVar3;
    iVar7 = iVar7 + -1;
    pbVar9 = pbVar9 + 1;
    uVar10 = 1;
    (**(code **)(*param_1 + 4))(param_1,1);
    if ((((uint)bVar2 + (uint)bVar1 * 0x100 != (uVar3 + 3) * 2) || (uVar3 == 0)) || (4 < uVar3)) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    param_1[0x53] = uVar3;
    local_2c = 0;
    if (uVar3 != 0) {
      local_30 = param_1 + 0x54;
      do {
        if (iVar7 == 0) {
          iVar7 = (*(code *)puVar6[3])(param_1);
          if (iVar7 == 0) goto LAB_404ae844;
          pbVar9 = (byte *)*puVar6;
          iVar7 = puVar6[1];
        }
        uVar4 = (uint)*pbVar9;
        iVar7 = iVar7 + -1;
        pbVar9 = pbVar9 + 1;
        if (iVar7 == 0) {
          iVar7 = (*(code *)puVar6[3])(param_1);
          if (iVar7 == 0) goto LAB_404ae844;
          pbVar9 = (byte *)*puVar6;
          iVar7 = puVar6[1];
        }
        bVar1 = *pbVar9;
        iVar7 = iVar7 + -1;
        puVar8 = (uint *)param_1[0x37];
        pbVar9 = pbVar9 + 1;
        iVar5 = 0;
        if (0 < param_1[9]) {
          do {
            if (uVar4 == *puVar8) goto LAB_404aea04;
            iVar5 = iVar5 + 1;
            puVar8 = puVar8 + 0x15;
          } while (iVar5 < param_1[9]);
        }
        *(undefined4 *)(*param_1 + 0x14) = 5;
        *(uint *)(*param_1 + 0x18) = uVar4;
        (**(code **)*param_1)(param_1);
LAB_404aea04:
        *local_30 = (int)puVar8;
        puVar8[5] = (int)(uint)bVar1 >> 4;
        puVar8[6] = bVar1 & 0xf;
        iVar5 = *param_1;
        *(uint *)(iVar5 + 0x18) = uVar4;
        *(uint *)(iVar5 + 0x1c) = puVar8[5];
        *(uint *)(iVar5 + 0x20) = puVar8[6];
        *(undefined4 *)(*param_1 + 0x14) = 0x68;
        (**(code **)(*param_1 + 4))(param_1,1);
        local_2c = local_2c + 1;
        local_30 = local_30 + 1;
      } while (local_2c < (int)uVar3);
    }
    if (iVar7 == 0) {
      iVar7 = (*(code *)puVar6[3])(param_1);
      if (iVar7 == 0) goto LAB_404ae844;
      pbVar9 = (byte *)*puVar6;
      iVar7 = puVar6[1];
    }
    iVar7 = iVar7 + -1;
    param_1[0x65] = (uint)*pbVar9;
    pbVar9 = pbVar9 + 1;
    if (iVar7 == 0) {
      iVar7 = (*(code *)puVar6[3])(param_1);
      if (iVar7 == 0) goto LAB_404ae844;
      pbVar9 = (byte *)*puVar6;
      iVar7 = puVar6[1];
    }
    iVar7 = iVar7 + -1;
    param_1[0x66] = (uint)*pbVar9;
    pbVar9 = pbVar9 + 1;
    if (iVar7 == 0) {
      iVar7 = (*(code *)puVar6[3])(param_1);
      if (iVar7 == 0) goto LAB_404ae844;
      pbVar9 = (byte *)*puVar6;
      iVar7 = puVar6[1];
    }
    bVar1 = *pbVar9;
    iVar5 = *param_1;
    param_1[0x67] = (int)(uint)bVar1 >> 4;
    param_1[0x68] = bVar1 & 0xf;
    *(int *)(iVar5 + 0x18) = param_1[0x65];
    *(int *)(iVar5 + 0x1c) = param_1[0x66];
    *(int *)(iVar5 + 0x20) = param_1[0x67];
    *(int *)(iVar5 + 0x24) = param_1[0x68];
    *(undefined4 *)(*param_1 + 0x14) = 0x69;
    (**(code **)(*param_1 + 4))(param_1,1);
    *(undefined4 *)(param_1[0x6f] + 0x14) = 0;
    param_1[0x25] = param_1[0x25] + 1;
    *puVar6 = pbVar9 + 1;
    puVar6[1] = iVar7 + -1;
  }
  return uVar10;
}



/* 404aebbc FUN_404aebbc */

/* Boundary evidence: original MIPS .pdata 404aebbc..404aefcf. Semantic name remains unreviewed. */

undefined4 FUN_404aebbc(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  undefined4 local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  byte local_138;
  byte local_130 [256];
  uint local_30;
  
  local_30 = DAT_404bd274;
  puVar9 = (undefined4 *)param_1[6];
  iVar4 = puVar9[1];
  pbVar6 = (byte *)*puVar9;
  if (iVar4 == 0) {
    iVar4 = (*(code *)puVar9[3])(param_1);
    if (iVar4 != 0) {
      pbVar6 = (byte *)*puVar9;
      iVar4 = puVar9[1];
      goto LAB_404aec34;
    }
LAB_404aec1c:
    FUN_404a438c(local_30);
    uVar3 = 0;
  }
  else {
LAB_404aec34:
    iVar4 = iVar4 + -1;
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    if (iVar4 == 0) {
      iVar4 = (*(code *)puVar9[3])(param_1);
      if (iVar4 == 0) goto LAB_404aec1c;
      pbVar6 = (byte *)*puVar9;
      iVar4 = puVar9[1];
    }
    iVar13 = (uint)*pbVar6 + (uint)bVar1 * 0x100 + -2;
    iVar4 = iVar4 + -1;
    pbVar6 = pbVar6 + 1;
    while (0x10 < iVar13) {
      if (iVar4 == 0) {
        iVar4 = (*(code *)puVar9[3])(param_1);
        if (iVar4 == 0) goto LAB_404aec1c;
        pbVar6 = (byte *)*puVar9;
        iVar4 = puVar9[1];
      }
      bVar1 = *pbVar6;
      uVar5 = (uint)bVar1;
      *(undefined4 *)(*param_1 + 0x14) = 0x50;
      *(uint *)(*param_1 + 0x18) = uVar5;
      iVar4 = iVar4 + -1;
      pbVar6 = pbVar6 + 1;
      (**(code **)(*param_1 + 4))(param_1,1);
      iVar12 = 0;
      iVar10 = 1;
      local_148 = local_148 & 0xffffff00;
      do {
        if (iVar4 == 0) {
          iVar4 = (*(code *)puVar9[3])(param_1);
          if (iVar4 == 0) goto LAB_404aec1c;
          pbVar6 = (byte *)*puVar9;
          iVar4 = puVar9[1];
        }
        pbVar7 = (byte *)((int)&local_148 + iVar10);
        bVar2 = *pbVar6;
        iVar10 = iVar10 + 1;
        *pbVar7 = bVar2;
        iVar4 = iVar4 + -1;
        pbVar6 = pbVar6 + 1;
        iVar12 = (uint)bVar2 + iVar12;
      } while (iVar10 < 0x11);
      iVar10 = *param_1;
      *(uint *)(iVar10 + 0x18) = local_148 >> 8 & 0xff;
      *(uint *)(iVar10 + 0x1c) = local_148 >> 0x10 & 0xff;
      *(uint *)(iVar10 + 0x20) = local_148 >> 0x18;
      *(uint *)(iVar10 + 0x24) = local_144 & 0xff;
      *(uint *)(iVar10 + 0x28) = local_144 >> 8 & 0xff;
      *(uint *)(iVar10 + 0x2c) = local_144 >> 0x10 & 0xff;
      *(uint *)(iVar10 + 0x30) = local_144 >> 0x18;
      *(uint *)(iVar10 + 0x34) = local_140 & 0xff;
      *(undefined4 *)(*param_1 + 0x14) = 0x56;
      (**(code **)(*param_1 + 4))(param_1,2);
      bVar2 = local_138;
      iVar10 = *param_1;
      *(uint *)(iVar10 + 0x18) = local_140 >> 8 & 0xff;
      *(uint *)(iVar10 + 0x1c) = local_140 >> 0x10 & 0xff;
      *(uint *)(iVar10 + 0x24) = local_13c & 0xff;
      *(uint *)(iVar10 + 0x20) = local_140 >> 0x18;
      *(uint *)(iVar10 + 0x28) = local_13c >> 8 & 0xff;
      *(uint *)(iVar10 + 0x2c) = local_13c >> 0x10 & 0xff;
      *(uint *)(iVar10 + 0x30) = local_13c >> 0x18;
      *(uint *)(iVar10 + 0x34) = (uint)local_138;
      *(undefined4 *)(*param_1 + 0x14) = 0x56;
      (**(code **)(*param_1 + 4))(param_1,2);
      if ((0x100 < iVar12) || (iVar13 + -0x11 < iVar12)) {
        *(undefined4 *)(*param_1 + 0x14) = 8;
        (**(code **)*param_1)(param_1);
      }
      iVar10 = 0;
      if (0 < iVar12) {
        do {
          if (iVar4 == 0) {
            iVar4 = (*(code *)puVar9[3])(param_1);
            if (iVar4 == 0) goto LAB_404aec1c;
            pbVar6 = (byte *)*puVar9;
            iVar4 = puVar9[1];
          }
          pbVar7 = local_130 + iVar10;
          iVar10 = iVar10 + 1;
          *pbVar7 = *pbVar6;
          iVar4 = iVar4 + -1;
          pbVar6 = pbVar6 + 1;
        } while (iVar10 < iVar12);
      }
      iVar13 = (iVar13 + -0x11) - iVar12;
      if ((bVar1 & 0x10) == 0) {
        iVar10 = uVar5 + 0x2e;
      }
      else {
        iVar10 = uVar5 + 0x22;
        uVar5 = uVar5 - 0x10;
      }
      piVar11 = param_1 + iVar10;
      if (((int)uVar5 < 0) || (3 < (int)uVar5)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x1e;
        *(uint *)(*param_1 + 0x18) = uVar5;
        (**(code **)*param_1)(param_1);
      }
      if (*piVar11 == 0) {
        iVar10 = FUN_404b07f4((int)param_1);
        *piVar11 = iVar10;
      }
      puVar8 = (uint *)*piVar11;
      *puVar8 = local_148;
      puVar8[1] = local_144;
      puVar8[2] = local_140;
      puVar8[3] = local_13c;
      *(byte *)(puVar8 + 4) = bVar2;
      memcpy((void *)(*piVar11 + 0x11),local_130,0x100);
    }
    if (iVar13 != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    *puVar9 = pbVar6;
    puVar9[1] = iVar4;
    FUN_404a438c(local_30);
    uVar3 = 1;
  }
  return uVar3;
}



/* 404aefd0 FUN_404aefd0 */

/* Boundary evidence: original MIPS .pdata 404aefd0..404af323. Semantic name remains unreviewed. */

undefined4 FUN_404aefd0(int *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  ushort *puVar14;
  int iVar15;
  
  puVar9 = (undefined4 *)param_1[6];
  pbVar7 = (byte *)*puVar9;
  iVar6 = puVar9[1];
  if (iVar6 == 0) {
    iVar6 = (*(code *)puVar9[3])(param_1);
    if (iVar6 != 0) {
      pbVar7 = (byte *)*puVar9;
      iVar6 = puVar9[1];
      goto LAB_404af038;
    }
LAB_404af028:
    uVar3 = 0;
  }
  else {
LAB_404af038:
    iVar6 = iVar6 + -1;
    bVar1 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    if (iVar6 == 0) {
      iVar6 = (*(code *)puVar9[3])(param_1);
      if (iVar6 == 0) goto LAB_404af028;
      pbVar7 = (byte *)*puVar9;
      iVar6 = puVar9[1];
    }
    iVar6 = iVar6 + -1;
    pbVar10 = pbVar7 + 1;
    iVar4 = (uint)*pbVar7 + (uint)bVar1 * 0x100 + -2;
    while (iVar2 = iVar4, 0 < iVar2) {
      piVar13 = &DAT_4048689c;
      if (iVar6 == 0) {
        iVar6 = (*(code *)puVar9[3])(param_1);
        if (iVar6 == 0) goto LAB_404af028;
        pbVar10 = (byte *)*puVar9;
        iVar6 = puVar9[1];
      }
      iVar15 = (int)(uint)*pbVar10 >> 4;
      uVar11 = *pbVar10 & 0xf;
      *(undefined4 *)(*param_1 + 0x14) = 0x51;
      *(uint *)(*param_1 + 0x18) = uVar11;
      *(int *)(*param_1 + 0x1c) = iVar15;
      iVar6 = iVar6 + -1;
      pbVar10 = pbVar10 + 1;
      (**(code **)(*param_1 + 4))(param_1,1);
      if (3 < uVar11) {
        *(undefined4 *)(*param_1 + 0x14) = 0x1f;
        *(uint *)(*param_1 + 0x18) = uVar11;
        (**(code **)*param_1)(param_1);
      }
      piVar12 = param_1 + uVar11 + 0x2a;
      if (*piVar12 == 0) {
        iVar4 = FUN_404b07c8((int)param_1);
        *piVar12 = iVar4;
      }
      iVar4 = *piVar12;
      do {
        if (iVar15 == 0) {
          if (iVar6 == 0) {
            iVar6 = (*(code *)puVar9[3])(param_1);
            if (iVar6 == 0) goto LAB_404af028;
            pbVar10 = (byte *)*puVar9;
            iVar6 = puVar9[1];
          }
          uVar5 = (ushort)*pbVar10;
        }
        else {
          if (iVar6 == 0) {
            iVar6 = (*(code *)puVar9[3])(param_1);
            if (iVar6 == 0) goto LAB_404af028;
            pbVar10 = (byte *)*puVar9;
            iVar6 = puVar9[1];
          }
          bVar1 = *pbVar10;
          iVar6 = iVar6 + -1;
          pbVar10 = pbVar10 + 1;
          if (iVar6 == 0) {
            iVar6 = (*(code *)puVar9[3])(param_1);
            if (iVar6 == 0) goto LAB_404af028;
            pbVar10 = (byte *)*puVar9;
            iVar6 = puVar9[1];
          }
          uVar5 = (ushort)*pbVar10 + (ushort)bVar1 * 0x100;
        }
        pbVar10 = pbVar10 + 1;
        iVar6 = iVar6 + -1;
        *(ushort *)(*piVar13 * 2 + iVar4) = uVar5;
        piVar13 = piVar13 + 1;
      } while ((int)piVar13 < 0x4048699c);
      if (1 < *(int *)(*param_1 + 0x68)) {
        puVar14 = (ushort *)(iVar4 + 8);
        iVar4 = 8;
        do {
          iVar8 = *param_1;
          *(uint *)(iVar8 + 0x18) = (uint)puVar14[-4];
          *(uint *)(iVar8 + 0x1c) = (uint)puVar14[-3];
          *(uint *)(iVar8 + 0x20) = (uint)puVar14[-2];
          *(uint *)(iVar8 + 0x24) = (uint)puVar14[-1];
          *(uint *)(iVar8 + 0x28) = (uint)*puVar14;
          *(uint *)(iVar8 + 0x2c) = (uint)puVar14[1];
          *(uint *)(iVar8 + 0x30) = (uint)puVar14[2];
          *(uint *)(iVar8 + 0x34) = (uint)puVar14[3];
          *(undefined4 *)(*param_1 + 0x14) = 0x5d;
          (**(code **)(*param_1 + 4))(param_1,2);
          iVar4 = iVar4 + -1;
          puVar14 = puVar14 + 8;
        } while (iVar4 != 0);
      }
      iVar4 = iVar2 + -0x41;
      if (iVar15 != 0) {
        iVar4 = iVar2 + -0x81;
      }
    }
    if (iVar2 != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    *puVar9 = pbVar10;
    uVar3 = 1;
    puVar9[1] = iVar6;
  }
  return uVar3;
}



/* 404af324 FUN_404af324 */

/* Boundary evidence: original MIPS .pdata 404af324..404af497. Semantic name remains unreviewed. */

undefined4 FUN_404af324(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  
  puVar7 = (undefined4 *)param_1[6];
  iVar4 = puVar7[1];
  pbVar5 = (byte *)*puVar7;
  if (iVar4 == 0) {
    iVar4 = (*(code *)puVar7[3])(param_1);
    if (iVar4 != 0) {
      pbVar5 = (byte *)*puVar7;
      iVar4 = puVar7[1];
      goto LAB_404af378;
    }
LAB_404af368:
    uVar3 = 0;
  }
  else {
LAB_404af378:
    iVar4 = iVar4 + -1;
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    if (iVar4 == 0) {
      iVar4 = (*(code *)puVar7[3])(param_1);
      if (iVar4 == 0) goto LAB_404af368;
      pbVar5 = (byte *)*puVar7;
      iVar4 = puVar7[1];
    }
    iVar4 = iVar4 + -1;
    pbVar8 = pbVar5 + 1;
    if ((uint)*pbVar5 + (uint)bVar1 * 0x100 != 4) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    if (iVar4 == 0) {
      iVar4 = (*(code *)puVar7[3])(param_1);
      if (iVar4 == 0) goto LAB_404af368;
      pbVar8 = (byte *)*puVar7;
      iVar4 = puVar7[1];
    }
    bVar1 = *pbVar8;
    iVar4 = iVar4 + -1;
    pbVar8 = pbVar8 + 1;
    if (iVar4 == 0) {
      iVar4 = (*(code *)puVar7[3])(param_1);
      if (iVar4 == 0) goto LAB_404af368;
      pbVar8 = (byte *)*puVar7;
      iVar4 = puVar7[1];
    }
    bVar2 = *pbVar8;
    *(undefined4 *)(*param_1 + 0x14) = 0x52;
    iVar6 = (uint)bVar2 + (uint)bVar1 * 0x100;
    *(int *)(*param_1 + 0x18) = iVar6;
    (**(code **)(*param_1 + 4))(param_1,1);
    param_1[0x46] = iVar6;
    uVar3 = 1;
    *puVar7 = pbVar8 + 1;
    puVar7[1] = iVar4 + -1;
  }
  return uVar3;
}



/* 404af498 FUN_404af498 */

/* Boundary evidence: original MIPS .pdata 404af498..404af78b. Semantic name remains unreviewed. */

void FUN_404af498(int *param_1,char *param_2,uint param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_3 + param_4;
  if ((((param_3 < 0xe) || (*param_2 != 'J')) || (param_2[1] != 'F')) ||
     (((param_2[2] != 'I' || (param_2[3] != 'F')) || (param_2[4] != '\0')))) {
    if (((param_3 < 6) || (*param_2 != 'J')) ||
       ((param_2[1] != 'F' || (((param_2[2] != 'X' || (param_2[3] != 'X')) || (param_2[4] != '\0')))
        ))) {
      uVar2 = 0x4d;
    }
    else {
      cVar1 = param_2[5];
      if (cVar1 != '\x10') {
        if (cVar1 == '\x11') {
          *(undefined4 *)(*param_1 + 0x14) = 0x6d;
          *(int *)(*param_1 + 0x18) = iVar4;
        }
        else {
          if (cVar1 != '\x13') {
            *(undefined4 *)(*param_1 + 0x14) = 0x59;
            *(uint *)(*param_1 + 0x18) = (uint)(byte)param_2[5];
            *(int *)(*param_1 + 0x1c) = iVar4;
            (**(code **)(*param_1 + 4))(param_1,1);
            return;
          }
          *(undefined4 *)(*param_1 + 0x14) = 0x6e;
          *(int *)(*param_1 + 0x18) = iVar4;
        }
        goto LAB_404af764;
      }
      uVar2 = 0x6c;
    }
    *(undefined4 *)(*param_1 + 0x14) = uVar2;
    *(int *)(*param_1 + 0x18) = iVar4;
  }
  else {
    param_1[0x47] = 1;
    *(char *)(param_1 + 0x48) = param_2[5];
    *(char *)((int)param_1 + 0x121) = param_2[6];
    *(char *)((int)param_1 + 0x122) = param_2[7];
    *(ushort *)(param_1 + 0x49) = (ushort)(byte)param_2[8] * 0x100 + (ushort)(byte)param_2[9];
    *(ushort *)((int)param_1 + 0x126) =
         (ushort)(byte)param_2[10] * 0x100 + (ushort)(byte)param_2[0xb];
    if ((char)param_1[0x48] != '\x01') {
      *(undefined4 *)(*param_1 + 0x14) = 0x77;
      *(uint *)(*param_1 + 0x18) = (uint)*(byte *)(param_1 + 0x48);
      *(uint *)(*param_1 + 0x1c) = (uint)*(byte *)((int)param_1 + 0x121);
      (**(code **)(*param_1 + 4))(param_1,0xffffffff);
    }
    iVar3 = *param_1;
    *(uint *)(iVar3 + 0x18) = (uint)*(byte *)(param_1 + 0x48);
    *(uint *)(iVar3 + 0x1c) = (uint)*(byte *)((int)param_1 + 0x121);
    *(uint *)(iVar3 + 0x20) = (uint)*(ushort *)(param_1 + 0x49);
    *(uint *)(iVar3 + 0x24) = (uint)*(ushort *)((int)param_1 + 0x126);
    *(uint *)(iVar3 + 0x28) = (uint)*(byte *)((int)param_1 + 0x122);
    *(undefined4 *)(*param_1 + 0x14) = 0x57;
    (**(code **)(*param_1 + 4))(param_1,1);
    if (param_2[0xd] != '\0' || param_2[0xc] != '\0') {
      *(undefined4 *)(*param_1 + 0x14) = 0x5a;
      *(uint *)(*param_1 + 0x18) = (uint)(byte)param_2[0xc];
      *(uint *)(*param_1 + 0x1c) = (uint)(byte)param_2[0xd];
      (**(code **)(*param_1 + 4))(param_1,1);
    }
    if (iVar4 + -0xe == (uint)(byte)param_2[0xd] * (uint)(byte)param_2[0xc] * 3) {
      return;
    }
    *(undefined4 *)(*param_1 + 0x14) = 0x58;
    *(int *)(*param_1 + 0x18) = iVar4 + -0xe;
  }
LAB_404af764:
  (**(code **)(*param_1 + 4))(param_1,1);
  return;
}



/* 404af78c FUN_404af78c */

/* Boundary evidence: original MIPS .pdata 404af78c..404af8bb. Semantic name remains unreviewed. */

void FUN_404af78c(int *param_1,char *param_2,uint param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  
  if ((((param_3 < 0xc) || (*param_2 != 'A')) || (param_2[1] != 'd')) ||
     (((param_2[2] != 'o' || (param_2[3] != 'b')) || (param_2[4] != 'e')))) {
    *(undefined4 *)(*param_1 + 0x14) = 0x4e;
    *(uint *)(*param_1 + 0x18) = param_3 + param_4;
    (**(code **)(*param_1 + 4))(param_1,1);
  }
  else {
    bVar1 = param_2[7];
    bVar2 = param_2[8];
    bVar3 = param_2[9];
    bVar4 = param_2[10];
    bVar5 = param_2[0xb];
    iVar6 = *param_1;
    *(uint *)(iVar6 + 0x18) = (uint)(byte)param_2[5] * 0x100 + (uint)(byte)param_2[6];
    *(uint *)(iVar6 + 0x1c) = (uint)bVar1 * 0x100 + (uint)bVar2;
    *(uint *)(iVar6 + 0x20) = (uint)bVar3 * 0x100 + (uint)bVar4;
    *(uint *)(iVar6 + 0x24) = (uint)bVar5;
    *(undefined4 *)(*param_1 + 0x14) = 0x4c;
    (**(code **)(*param_1 + 4))(param_1,1);
    param_1[0x4a] = 1;
    *(byte *)(param_1 + 0x4b) = bVar5;
  }
  return;
}



/* 404af8bc FUN_404af8bc */

/* Boundary evidence: original MIPS .pdata 404af8bc..404afaa7. Semantic name remains unreviewed. */

undefined4 FUN_404af8bc(int *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte local_38 [16];
  uint local_28;
  
  local_28 = DAT_404bd274;
  puVar6 = (undefined4 *)param_1[6];
  iVar3 = puVar6[1];
  pbVar4 = (byte *)*puVar6;
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar6[3])(param_1);
    if (iVar3 != 0) {
      pbVar4 = (byte *)*puVar6;
      iVar3 = puVar6[1];
      goto LAB_404af92c;
    }
LAB_404af914:
    FUN_404a438c(local_28);
    uVar2 = 0;
  }
  else {
LAB_404af92c:
    iVar3 = iVar3 + -1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar6[3])(param_1);
      if (iVar3 == 0) goto LAB_404af914;
      pbVar4 = (byte *)*puVar6;
      iVar3 = puVar6[1];
    }
    uVar10 = ((uint)*pbVar4 + (uint)bVar1 * 0x100) - 2;
    iVar3 = iVar3 + -1;
    pbVar4 = pbVar4 + 1;
    if ((int)uVar10 < 0xe) {
      uVar7 = uVar10;
      if ((int)uVar10 < 1) {
        uVar7 = 0;
      }
    }
    else {
      uVar7 = 0xe;
    }
    uVar8 = 0;
    if (uVar7 != 0) {
      do {
        if (iVar3 == 0) {
          iVar3 = (*(code *)puVar6[3])(param_1);
          if (iVar3 == 0) goto LAB_404af914;
          pbVar4 = (byte *)*puVar6;
          iVar3 = puVar6[1];
        }
        pbVar5 = local_38 + uVar8;
        uVar8 = uVar8 + 1;
        *pbVar5 = *pbVar4;
        iVar3 = iVar3 + -1;
        pbVar4 = pbVar4 + 1;
      } while (uVar8 < uVar7);
    }
    iVar9 = uVar10 - uVar7;
    if (param_1[0x69] == 0xe0) {
      FUN_404af498(param_1,(char *)local_38,uVar7,iVar9);
    }
    else if (param_1[0x69] == 0xee) {
      FUN_404af78c(param_1,(char *)local_38,uVar7,iVar9);
    }
    else {
      *(undefined4 *)(*param_1 + 0x14) = 0x44;
      *(int *)(*param_1 + 0x18) = param_1[0x69];
      (**(code **)*param_1)();
    }
    *puVar6 = pbVar4;
    puVar6[1] = iVar3;
    if (0 < iVar9) {
      (**(code **)(param_1[6] + 0x10))(param_1,iVar9);
    }
    FUN_404a438c(local_28);
    uVar2 = 1;
  }
  return uVar2;
}



/* 404afaa8 FUN_404afaa8 */

/* Boundary evidence: original MIPS .pdata 404afaa8..404afbb7. Semantic name remains unreviewed. */

undefined4 FUN_404afaa8(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  int iVar7;
  
  puVar6 = (undefined4 *)param_1[6];
  iVar4 = puVar6[1];
  pbVar5 = (byte *)*puVar6;
  if (iVar4 == 0) {
    iVar4 = (*(code *)puVar6[3])(param_1);
    if (iVar4 != 0) {
      pbVar5 = (byte *)*puVar6;
      iVar4 = puVar6[1];
      goto LAB_404afafc;
    }
LAB_404afaec:
    uVar3 = 0;
  }
  else {
LAB_404afafc:
    iVar4 = iVar4 + -1;
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    if (iVar4 == 0) {
      iVar4 = (*(code *)puVar6[3])(param_1);
      if (iVar4 == 0) goto LAB_404afaec;
      pbVar5 = (byte *)*puVar6;
      iVar4 = puVar6[1];
    }
    bVar2 = *pbVar5;
    *(undefined4 *)(*param_1 + 0x14) = 0x5b;
    *(int *)(*param_1 + 0x18) = param_1[0x69];
    iVar7 = (uint)bVar2 + (uint)bVar1 * 0x100 + -2;
    *(int *)(*param_1 + 0x1c) = iVar7;
    (**(code **)(*param_1 + 4))(param_1,1);
    *puVar6 = pbVar5 + 1;
    puVar6[1] = iVar4 + -1;
    if (0 < iVar7) {
      (**(code **)(param_1[6] + 0x10))(param_1,iVar7);
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* 404afbb8 FUN_404afbb8 */

/* Boundary evidence: original MIPS .pdata 404afbb8..404afd57. Semantic name remains unreviewed. */

undefined4 FUN_404afbb8(int *param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  
  puVar3 = (undefined4 *)param_1[6];
  pbVar5 = (byte *)*puVar3;
  iVar4 = puVar3[1];
  while( true ) {
    if (iVar4 == 0) {
      iVar4 = (*(code *)puVar3[3])(param_1);
      if (iVar4 == 0) {
        return 0;
      }
      pbVar5 = (byte *)*puVar3;
      iVar4 = puVar3[1];
    }
    bVar1 = *pbVar5;
    while( true ) {
      pbVar5 = pbVar5 + 1;
      iVar4 = iVar4 + -1;
      if (bVar1 == 0xff) break;
      *(int *)(param_1[0x6f] + 0x18) = *(int *)(param_1[0x6f] + 0x18) + 1;
      *puVar3 = pbVar5;
      puVar3[1] = iVar4;
      if (iVar4 == 0) {
        iVar4 = (*(code *)puVar3[3])(param_1);
        if (iVar4 == 0) {
          return 0;
        }
        pbVar5 = (byte *)*puVar3;
        iVar4 = puVar3[1];
      }
      bVar1 = *pbVar5;
    }
    do {
      if (iVar4 == 0) {
        iVar4 = (*(code *)puVar3[3])(param_1);
        if (iVar4 == 0) {
          return 0;
        }
        pbVar5 = (byte *)*puVar3;
        iVar4 = puVar3[1];
      }
      uVar2 = (uint)*pbVar5;
      iVar4 = iVar4 + -1;
      pbVar5 = pbVar5 + 1;
    } while (uVar2 == 0xff);
    if (uVar2 != 0) break;
    *(int *)(param_1[0x6f] + 0x18) = *(int *)(param_1[0x6f] + 0x18) + 2;
    *puVar3 = pbVar5;
    puVar3[1] = iVar4;
  }
  if (*(int *)(param_1[0x6f] + 0x18) != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x74;
    *(undefined4 *)(*param_1 + 0x18) = *(undefined4 *)(param_1[0x6f] + 0x18);
    *(uint *)(*param_1 + 0x1c) = uVar2;
    (**(code **)(*param_1 + 4))(param_1,0xffffffff);
    *(undefined4 *)(param_1[0x6f] + 0x18) = 0;
  }
  param_1[0x69] = uVar2;
  *puVar3 = pbVar5;
  puVar3[1] = iVar4;
  return 1;
}



/* 404afd58 FUN_404afd58 */

/* Boundary evidence: original MIPS .pdata 404afd58..404afe63. Semantic name remains unreviewed. */

undefined4 FUN_404afd58(int *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)param_1[6];
  iVar3 = puVar6[1];
  pbVar5 = (byte *)*puVar6;
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar6[3])(param_1);
    if (iVar3 != 0) {
      pbVar5 = (byte *)*puVar6;
      iVar3 = puVar6[1];
      goto LAB_404afdb0;
    }
LAB_404afda0:
    uVar2 = 0;
  }
  else {
LAB_404afdb0:
    iVar3 = iVar3 + -1;
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    if (iVar3 == 0) {
      iVar3 = (*(code *)puVar6[3])(param_1);
      if (iVar3 == 0) goto LAB_404afda0;
      pbVar5 = (byte *)*puVar6;
      iVar3 = puVar6[1];
    }
    uVar4 = (uint)*pbVar5;
    if ((bVar1 != 0xff) || (uVar4 != 0xd8)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x35;
      *(uint *)(*param_1 + 0x18) = (uint)bVar1;
      *(uint *)(*param_1 + 0x1c) = uVar4;
      (**(code **)*param_1)(param_1);
    }
    param_1[0x69] = uVar4;
    uVar2 = 1;
    *puVar6 = pbVar5 + 1;
    puVar6[1] = iVar3 + -1;
  }
  return uVar2;
}



/* 404afe64 FUN_404afe64 */

/* Boundary evidence: original MIPS .pdata 404afe64..404b022f. Semantic name remains unreviewed. */

undefined4 FUN_404afe64(int *param_1)

{
  int iVar1;
  
LAB_404afeb4:
  if (param_1[0x69] == 0) {
    if (*(int *)(param_1[0x6f] + 0xc) == 0) {
      iVar1 = FUN_404afd58(param_1);
    }
    else {
      iVar1 = FUN_404afbb8(param_1);
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = param_1[0x69];
  if (iVar1 < 0xd0) {
    if (0xcc < iVar1) {
switchD_404affe0_caseD_cb:
      *(undefined4 *)(*param_1 + 0x14) = 0x3c;
      *(int *)(*param_1 + 0x18) = param_1[0x69];
      (**(code **)*param_1)(param_1);
      param_1[0x69] = 0;
      goto LAB_404afeb4;
    }
    if (iVar1 < 0xc9) {
      if (0xc4 < iVar1) goto switchD_404affe0_caseD_cb;
      if (iVar1 < 0xc3) {
        if (iVar1 == 0xc2) {
          iVar1 = FUN_404ae378(param_1,1,0);
        }
        else {
          if (iVar1 == 1) goto switchD_404b0094_caseD_d0;
          if ((iVar1 < 0xc0) || (0xc1 < iVar1)) goto switchD_404affe0_default;
          iVar1 = FUN_404ae378(param_1,0,0);
        }
      }
      else {
        if (iVar1 == 0xc3) goto switchD_404affe0_caseD_cb;
        if (iVar1 != 0xc4) goto switchD_404affe0_default;
        iVar1 = FUN_404aebbc(param_1);
      }
    }
    else {
      switch(iVar1) {
      case 0xc9:
        iVar1 = FUN_404ae378(param_1,0,1);
        break;
      case 0xca:
        iVar1 = FUN_404ae378(param_1,1,1);
        break;
      case 0xcb:
        goto switchD_404affe0_caseD_cb;
      case 0xcc:
switchD_404affe0_caseD_cc:
        iVar1 = FUN_404afaa8(param_1);
        break;
      default:
        goto switchD_404affe0_default;
      }
    }
  }
  else if (iVar1 < 0xdc) {
    if (iVar1 == 0xdb) {
      iVar1 = FUN_404aefd0(param_1);
      goto LAB_404b01a4;
    }
    switch(iVar1) {
    case 0xd0:
    case 0xd1:
    case 0xd2:
    case 0xd3:
    case 0xd4:
    case 0xd5:
    case 0xd6:
    case 0xd7:
switchD_404b0094_caseD_d0:
      *(undefined4 *)(*param_1 + 0x14) = 0x5c;
      *(int *)(*param_1 + 0x18) = param_1[0x69];
      (**(code **)(*param_1 + 4))(param_1,1);
      param_1[0x69] = 0;
      goto LAB_404afeb4;
    case 0xd8:
      iVar1 = FUN_404ae2a4(param_1);
      break;
    case 0xd9:
      *(undefined4 *)(*param_1 + 0x14) = 0x55;
      (**(code **)(*param_1 + 4))(param_1,1);
      param_1[0x69] = 0;
      return 2;
    case 0xda:
      iVar1 = FUN_404ae7c4(param_1);
      if (iVar1 == 0) {
        return 0;
      }
      param_1[0x69] = 0;
      return 1;
    default:
switchD_404affe0_default:
      *(undefined4 *)(*param_1 + 0x14) = 0x44;
      *(int *)(*param_1 + 0x18) = param_1[0x69];
      (**(code **)*param_1)(param_1);
      param_1[0x69] = 0;
      goto LAB_404afeb4;
    }
  }
  else if (iVar1 < 0xf0) {
    if (iVar1 < 0xe0) {
      if (iVar1 == 0xdc) goto switchD_404affe0_caseD_cc;
      if (iVar1 != 0xdd) goto switchD_404affe0_default;
      iVar1 = FUN_404af324(param_1);
    }
    else {
      iVar1 = (**(code **)((iVar1 + -0xd8) * 4 + param_1[0x6f]))(param_1);
    }
  }
  else {
    if (iVar1 != 0xfe) goto switchD_404affe0_default;
    iVar1 = (**(code **)(param_1[0x6f] + 0x1c))(param_1);
  }
LAB_404b01a4:
  if (iVar1 == 0) {
    return 0;
  }
  param_1[0x69] = 0;
  goto LAB_404afeb4;
}



/* 404b0230 FUN_404b0230 */

/* Boundary evidence: original MIPS .pdata 404b0230..404b02fb. Semantic name remains unreviewed. */

undefined4 FUN_404b0230(int *param_1)

{
  int iVar1;
  
  if ((param_1[0x69] == 0) && (iVar1 = FUN_404afbb8(param_1), iVar1 == 0)) {
    return 0;
  }
  if (param_1[0x69] == *(int *)(param_1[0x6f] + 0x14) + 0xd0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x62;
    *(undefined4 *)(*param_1 + 0x18) = *(undefined4 *)(param_1[0x6f] + 0x14);
    (**(code **)(*param_1 + 4))(param_1,3);
    param_1[0x69] = 0;
  }
  else {
    iVar1 = (**(code **)(param_1[6] + 0x14))(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  *(uint *)(param_1[0x6f] + 0x14) = *(int *)(param_1[0x6f] + 0x14) + 1U & 7;
  return 1;
}



/* 404b02fc FUN_404b02fc */

/* Boundary evidence: original MIPS .pdata 404b02fc..404b0497. Semantic name remains unreviewed. */

undefined4 FUN_404b02fc(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[0x69];
  *(undefined4 *)(*param_1 + 0x14) = 0x79;
  *(int *)(*param_1 + 0x18) = iVar2;
  *(int *)(*param_1 + 0x1c) = param_2;
  (**(code **)(*param_1 + 4))(param_1,0xffffffff);
  do {
    if (iVar2 < 0xc0) {
LAB_404b037c:
      iVar1 = 2;
    }
    else if ((((iVar2 < 0xd0) || (0xd7 < iVar2)) || (iVar2 == (param_2 + 1U & 7) + 0xd0)) ||
            (iVar2 == (param_2 + 2U & 7) + 0xd0)) {
      iVar1 = 3;
    }
    else {
      if ((iVar2 == (param_2 - 1U & 7) + 0xd0) || (iVar2 == (param_2 - 2U & 7) + 0xd0))
      goto LAB_404b037c;
      iVar1 = 1;
    }
    *(undefined4 *)(*param_1 + 0x14) = 0x61;
    *(int *)(*param_1 + 0x18) = iVar2;
    *(int *)(*param_1 + 0x1c) = iVar1;
    (**(code **)(*param_1 + 4))(param_1,4);
    if (iVar1 == 1) {
      param_1[0x69] = 0;
      return 1;
    }
    if (iVar1 == 2) {
      iVar2 = FUN_404afbb8(param_1);
      if (iVar2 == 0) {
        return 0;
      }
      iVar2 = param_1[0x69];
    }
    else if (iVar1 == 3) {
      return 1;
    }
  } while( true );
}



/* 404b04bc FUN_404b04bc */

/* Boundary evidence: original MIPS .pdata 404b04bc..404b057b. Semantic name remains unreviewed. */

void FUN_404b04bc(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0xac);
  *(undefined4 **)(param_1 + 0x1bc) = puVar1;
  *puVar1 = &LAB_404b0498;
  puVar1[1] = FUN_404afe64;
  iVar3 = 0x10;
  puVar1[2] = FUN_404b0230;
  puVar1[7] = FUN_404afaa8;
  puVar1[0x18] = 0;
  puVar2 = puVar1 + 8;
  do {
    *puVar2 = FUN_404afaa8;
    puVar2[0x11] = 0;
    iVar3 = iVar3 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 0);
  puVar1[8] = FUN_404af8bc;
  puVar1[0x16] = FUN_404af8bc;
  iVar3 = *(int *)(param_1 + 0x1bc);
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(iVar3 + 0xc) = 0;
  *(undefined4 *)(iVar3 + 0x10) = 0;
  *(undefined4 *)(iVar3 + 0x18) = 0;
  *(undefined4 *)(iVar3 + 0xa4) = 0;
  return;
}



/* 404b057c FUN_404b057c */

/* Boundary evidence: original MIPS .pdata 404b057c..404b0697. Semantic name remains unreviewed. */

void FUN_404b057c(int *param_1,int param_2,uint param_3,undefined *param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(int *)(param_1[1] + 0x30) - 0x14;
  iVar2 = param_1[0x6f];
  if ((int)uVar1 < (int)param_3) {
    param_3 = uVar1;
  }
  if (param_3 == 0) {
    if ((param_2 == 0xe0) || (param_4 = FUN_404afaa8, param_2 == 0xee)) {
      param_4 = FUN_404af8bc;
    }
  }
  else {
    if (param_2 == 0xe0) {
      if (param_3 < 0xe) {
        param_3 = 0xe;
      }
      goto LAB_404b063c;
    }
    if (param_2 == 0xee) {
      if (param_3 < 0xc) {
        param_3 = 0xc;
      }
      goto LAB_404b063c;
    }
  }
  if (param_2 == 0xfe) {
    *(undefined **)(iVar2 + 0x1c) = param_4;
    *(uint *)(iVar2 + 0x60) = param_3;
    return;
  }
  if ((param_2 < 0xe0) || (0xef < param_2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x44;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)();
    return;
  }
LAB_404b063c:
  *(undefined **)((param_2 + -0xd8) * 4 + iVar2) = param_4;
  *(uint *)((param_2 + -199) * 4 + iVar2) = param_3;
  return;
}



/* 404b0698 FUN_404b0698 */

/* Boundary evidence: original MIPS .pdata 404b0698..404b071b. Semantic name remains unreviewed. */

void FUN_404b0698(int *param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 0xfe) {
    *(undefined4 *)(param_1[0x6f] + 0x1c) = param_3;
    return;
  }
  if ((0xdf < param_2) && (param_2 < 0xf0)) {
    *(undefined4 *)((param_2 + -0xd8) * 4 + param_1[0x6f]) = param_3;
    return;
  }
  *(undefined4 *)(*param_1 + 0x14) = 0x44;
  *(int *)(*param_1 + 0x18) = param_2;
  (**(code **)*param_1)();
  return;
}



/* 404b071c FUN_404b071c */

/* Boundary evidence: original MIPS .pdata 404b071c..404b0787. Semantic name remains unreviewed. */

void FUN_404b071c(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    (**(code **)(*(int *)(param_1 + 4) + 0x24))(param_1,1);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0x14) = 200;
      *(undefined4 *)(param_1 + 0x134) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x14) = 100;
  }
  return;
}



/* 404b0788 FUN_404b0788 */

/* Boundary evidence: original MIPS .pdata 404b0788..404b07c7. Semantic name remains unreviewed. */

void FUN_404b0788(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    (**(code **)(*(int *)(param_1 + 4) + 0x28))(param_1);
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



/* 404b07c8 FUN_404b07c8 */

/* Boundary evidence: original MIPS .pdata 404b07c8..404b07f3. Semantic name remains unreviewed. */

void FUN_404b07c8(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x84);
  *(undefined4 *)(iVar1 + 0x80) = 0;
  return;
}



/* 404b07f4 FUN_404b07f4 */

/* Boundary evidence: original MIPS .pdata 404b07f4..404b081f. Semantic name remains unreviewed. */

void FUN_404b07f4(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x118);
  *(undefined4 *)(iVar1 + 0x114) = 0;
  return;
}



/* 404b0820 FUN_404b0820 */

undefined4 FUN_404b0820(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (((((*(int *)(param_1 + 0x4c) != 0) || (*(int *)(param_1 + 0x130) != 0)) ||
       (*(int *)(param_1 + 0x28) != 3)) ||
      (((*(int *)(param_1 + 0x24) != 3 || (*(int *)(param_1 + 0x2c) != 2)) ||
       ((*(int *)(param_1 + 0x78) != 3 ||
        ((iVar2 = *(int *)(param_1 + 0xdc), *(int *)(iVar2 + 8) != 2 ||
         (*(int *)(iVar2 + 0x5c) != 1)))))))) ||
     ((*(int *)(iVar2 + 0xb0) != 1 ||
      (((((2 < *(int *)(iVar2 + 0xc) || (*(int *)(iVar2 + 0x60) != 1)) ||
         (*(int *)(iVar2 + 0xb4) != 1)) ||
        ((iVar3 = *(int *)(param_1 + 0x140), *(int *)(iVar2 + 0x24) != iVar3 ||
         (*(int *)(iVar2 + 0x78) != iVar3)))) || (uVar1 = 1, *(int *)(iVar2 + 0xcc) != iVar3)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 404b08f8 FUN_404b08f8 */

/* Boundary evidence: original MIPS .pdata 404b08f8..404b0c0b. Semantic name remains unreviewed. */

void FUN_404b08f8(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1[5] != 0xca) {
    *(undefined4 *)(*param_1 + 0x14) = 0x14;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  iVar1 = param_1[0xc];
  uVar2 = param_1[0xd];
  if (uVar2 < (uint)(iVar1 << 3)) {
    if (uVar2 < (uint)(iVar1 << 2)) {
      if (uVar2 < (uint)(iVar1 << 1)) {
        param_1[0x1c] = param_1[7];
        param_1[0x1d] = param_1[8];
        param_1[0x50] = 8;
      }
      else {
        iVar1 = FUN_404b2f08(param_1[7],2);
        param_1[0x1c] = iVar1;
        iVar1 = FUN_404b2f08(param_1[8],2);
        param_1[0x1d] = iVar1;
        param_1[0x50] = 4;
      }
    }
    else {
      iVar1 = FUN_404b2f08(param_1[7],4);
      param_1[0x1c] = iVar1;
      iVar1 = FUN_404b2f08(param_1[8],4);
      param_1[0x1d] = iVar1;
      param_1[0x50] = 2;
    }
  }
  else {
    iVar1 = FUN_404b2f08(param_1[7],8);
    param_1[0x1c] = iVar1;
    iVar1 = FUN_404b2f08(param_1[8],8);
    param_1[0x1d] = iVar1;
    param_1[0x50] = 1;
  }
  iVar1 = 0;
  if (0 < param_1[9]) {
    piVar4 = (int *)(param_1[0x37] + 8);
    do {
      iVar5 = param_1[0x50];
      iVar3 = iVar5;
      if (iVar5 < 8) {
        do {
          if ((param_1[0x4e] * iVar5 < *piVar4 * iVar3 * 2) ||
             (param_1[0x4f] * iVar5 < piVar4[1] * iVar3 * 2)) break;
          iVar3 = iVar3 << 1;
        } while (iVar3 < 8);
      }
      piVar4[7] = iVar3;
      iVar1 = iVar1 + 1;
      piVar4 = piVar4 + 0x15;
    } while (iVar1 < param_1[9]);
  }
  iVar1 = 0;
  if (0 < param_1[9]) {
    piVar4 = (int *)(param_1[0x37] + 8);
    do {
      iVar3 = FUN_404b2f08(*piVar4 * piVar4[7] * param_1[7],param_1[0x4e] << 3);
      piVar4[8] = iVar3;
      iVar3 = FUN_404b2f08(piVar4[1] * param_1[8] * piVar4[7],param_1[0x4f] << 3);
      iVar1 = iVar1 + 1;
      piVar4[9] = iVar3;
      piVar4 = piVar4 + 0x15;
    } while (iVar1 < param_1[9]);
  }
  switch(param_1[0xb]) {
  case 1:
    param_1[0x1e] = 1;
    goto LAB_404b0bb8;
  case 2:
  case 3:
    iVar1 = 3;
    break;
  case 4:
  case 5:
    param_1[0x1e] = 4;
    goto LAB_404b0bb8;
  default:
    iVar1 = param_1[9];
  }
  param_1[0x1e] = iVar1;
LAB_404b0bb8:
  iVar1 = 1;
  if (param_1[0x15] == 0) {
    iVar1 = param_1[0x1e];
  }
  param_1[0x1f] = iVar1;
  iVar1 = FUN_404b0820((int)param_1);
  if (iVar1 == 0) {
    param_1[0x20] = 1;
  }
  else {
    param_1[0x20] = param_1[0x4f];
  }
  return;
}



/* 404b0c0c FUN_404b0c0c */

/* Boundary evidence: original MIPS .pdata 404b0c0c..404b0f7b. Semantic name remains unreviewed. */

void FUN_404b0c0c(int *param_1)

{
  void *_Dst;
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_1[0x6a];
  FUN_404b08f8(param_1);
  iVar4 = 1;
  _Dst = (void *)(**(code **)param_1[1])(param_1,1,0x580);
  param_1[0x52] = (int)_Dst + 0x100;
  memset(_Dst,0,0x100);
  iVar2 = 0;
  do {
    *(char *)(iVar2 + (int)_Dst + 0x100) = (char)iVar2;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x100);
  puVar3 = (undefined1 *)((int)_Dst + 0x200);
  do {
    *puVar3 = 0xff;
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined1 *)((int)_Dst + 0x380));
  memset((void *)((int)_Dst + 0x380),0,0x180);
  memcpy((void *)((int)_Dst + 0x500),(void *)param_1[0x52],0x80);
  *(undefined4 *)(iVar5 + 0xc) = 0;
  uVar1 = FUN_404b0820((int)param_1);
  *(undefined4 *)(iVar5 + 0x10) = uVar1;
  *(undefined4 *)(iVar5 + 0x14) = 0;
  *(undefined4 *)(iVar5 + 0x18) = 0;
  if ((param_1[0x15] == 0) || (param_1[0x10] == 0)) {
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    param_1[0x1b] = 0;
  }
  uVar1 = 3;
  if (param_1[0x15] == 0) goto LAB_404b0da4;
  if (param_1[0x11] != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x2f;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x1e] == 3) {
    if (param_1[0x22] == 0) {
      if (param_1[0x17] == 0) goto LAB_404b0d4c;
      param_1[0x1b] = 1;
    }
    else {
      param_1[0x1a] = 1;
    }
  }
  else {
    param_1[0x1a] = 0;
    param_1[0x1b] = 0;
    param_1[0x22] = 0;
LAB_404b0d4c:
    param_1[0x19] = 1;
  }
  if (param_1[0x19] != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x30;
    (**(code **)*param_1)(param_1);
  }
  if ((param_1[0x1b] != 0) || (param_1[0x1a] != 0)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x30;
    (**(code **)*param_1)(param_1);
  }
LAB_404b0da4:
  if (param_1[0x11] == 0) {
    if (*(int *)(iVar5 + 0x10) == 0) {
      FUN_404b96dc(param_1);
      FUN_404b8190(param_1);
    }
    else {
      FUN_404ba1f0((int)param_1);
    }
    FUN_404b79d8(param_1,param_1[0x1b]);
  }
  FUN_404b77ac((int)param_1);
  if (param_1[0x39] == 0) {
    if (param_1[0x38] == 0) {
      FUN_404b5f80((int)param_1);
    }
    else {
      FUN_404b7064((int)param_1);
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 1;
    (**(code **)*param_1)(param_1);
  }
  if ((*(int *)(param_1[0x6e] + 0x10) == 0) && (param_1[0x10] == 0)) {
    iVar4 = 0;
  }
  FUN_404b4ea8((int)param_1,iVar4);
  if (param_1[0x11] == 0) {
    FUN_404b38ec(param_1,0);
  }
  (**(code **)(param_1[1] + 0x18))(param_1);
  (**(code **)(param_1[0x6e] + 8))(param_1);
  if (((param_1[2] != 0) && (param_1[0x10] == 0)) && (*(int *)(param_1[0x6e] + 0x10) != 0)) {
    if (param_1[0x38] == 0) {
      iVar2 = param_1[9];
    }
    else {
      iVar2 = param_1[9] * 3 + 2;
    }
    *(undefined4 *)(param_1[2] + 4) = 0;
    *(int *)(param_1[2] + 8) = param_1[0x51] * iVar2;
    *(undefined4 *)(param_1[2] + 0xc) = 0;
    if (param_1[0x1b] == 0) {
      uVar1 = 2;
    }
    *(undefined4 *)(param_1[2] + 0x10) = uVar1;
    *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;
  }
  return;
}



/* 404b0f7c FUN_404b0f7c */

/* Boundary evidence: original MIPS .pdata 404b0f7c..404b1173. Semantic name remains unreviewed. */

void FUN_404b0f7c(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1[0x6a];
  if (*(int *)(iVar4 + 8) == 0) {
    if ((param_1[0x15] != 0) && (param_1[0x22] == 0)) {
      if ((param_1[0x17] == 0) || (param_1[0x1b] == 0)) {
        if (param_1[0x19] == 0) {
          *(undefined4 *)(*param_1 + 0x14) = 0x2e;
          (**(code **)*param_1)(param_1);
        }
        else {
          param_1[0x74] = *(int *)(iVar4 + 0x14);
        }
      }
      else {
        param_1[0x74] = *(int *)(iVar4 + 0x18);
        *(undefined4 *)(iVar4 + 8) = 1;
      }
    }
    (**(code **)param_1[0x71])(param_1);
    (**(code **)(param_1[0x6c] + 8))(param_1);
    if (param_1[0x11] == 0) {
      if (*(int *)(iVar4 + 0x10) == 0) {
        (**(code **)param_1[0x73])(param_1);
      }
      (**(code **)param_1[0x72])(param_1);
      if (param_1[0x15] != 0) {
        (**(code **)param_1[0x74])(param_1,*(undefined4 *)(iVar4 + 8));
      }
      uVar1 = 3;
      if (*(int *)(iVar4 + 8) == 0) {
        uVar1 = 0;
      }
      (**(code **)param_1[0x6d])(param_1,uVar1);
      (**(code **)param_1[0x6b])(param_1,0);
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x30;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[2] != 0) {
    iVar3 = 2;
    *(undefined4 *)(param_1[2] + 0xc) = *(undefined4 *)(iVar4 + 0xc);
    iVar2 = 2;
    if (*(int *)(iVar4 + 8) == 0) {
      iVar2 = 1;
    }
    *(int *)(param_1[2] + 0x10) = *(int *)(iVar4 + 0xc) + iVar2;
    if ((param_1[0x10] != 0) && (*(int *)(param_1[0x6e] + 0x14) == 0)) {
      if (param_1[0x1b] == 0) {
        iVar3 = 1;
      }
      *(int *)(param_1[2] + 0x10) = *(int *)(param_1[2] + 0x10) + iVar3;
    }
  }
  return;
}



/* 404b1174 FUN_404b1174 */

/* Boundary evidence: original MIPS .pdata 404b1174..404b11b7. Semantic name remains unreviewed. */

void FUN_404b1174(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1a8);
  if (*(int *)(param_1 + 0x54) != 0) {
    (**(code **)(*(int *)(param_1 + 0x1d0) + 8))();
  }
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
  return;
}



/* 404b11b8 FUN_404b11b8 */

/* Boundary evidence: original MIPS .pdata 404b11b8..404b1217. Semantic name remains unreviewed. */

void FUN_404b11b8(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x1c);
  param_1[0x6a] = (int)puVar1;
  *puVar1 = FUN_404b0f7c;
  puVar1[1] = FUN_404b1174;
  puVar1[2] = 0;
  FUN_404b0c0c(param_1);
  return;
}



/* 404b1218 FUN_404b1218 */

/* Boundary evidence: original MIPS .pdata 404b1218..404b14d3. Semantic name remains unreviewed. */

void FUN_404b1218(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((0xffdc < param_1[8]) || (0xffdc < param_1[7])) {
    *(undefined4 *)(*param_1 + 0x14) = 0x29;
    *(undefined4 *)(*param_1 + 0x18) = 0xffdc;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x36] != 8) {
    *(undefined4 *)(*param_1 + 0x14) = 0xf;
    *(int *)(*param_1 + 0x18) = param_1[0x36];
    (**(code **)*param_1)(param_1);
  }
  if (10 < param_1[9]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x1a;
    *(int *)(*param_1 + 0x18) = param_1[9];
    *(undefined4 *)(*param_1 + 0x1c) = 10;
    (**(code **)*param_1)(param_1);
  }
  iVar3 = 0;
  param_1[0x4e] = 1;
  param_1[0x4f] = 1;
  if (0 < param_1[9]) {
    piVar2 = (int *)(param_1[0x37] + 8);
    do {
      if ((((*piVar2 < 1) || (4 < *piVar2)) || (piVar2[1] < 1)) || (4 < piVar2[1])) {
        *(undefined4 *)(*param_1 + 0x14) = 0x12;
        (**(code **)*param_1)(param_1);
      }
      iVar1 = param_1[0x4e];
      if (param_1[0x4e] <= *piVar2) {
        iVar1 = *piVar2;
      }
      param_1[0x4e] = iVar1;
      iVar1 = param_1[0x4f];
      if (param_1[0x4f] <= piVar2[1]) {
        iVar1 = piVar2[1];
      }
      param_1[0x4f] = iVar1;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0x15;
    } while (iVar3 < param_1[9]);
  }
  iVar3 = 0;
  param_1[0x50] = 8;
  if (0 < param_1[9]) {
    piVar2 = (int *)(param_1[0x37] + 0x20);
    do {
      piVar2[1] = 8;
      iVar1 = FUN_404b2f08(piVar2[-6] * param_1[7],param_1[0x4e] << 3);
      piVar2[-1] = iVar1;
      iVar1 = FUN_404b2f08(piVar2[-5] * param_1[8],param_1[0x4f] << 3);
      *piVar2 = iVar1;
      iVar1 = FUN_404b2f08(piVar2[-6] * param_1[7],param_1[0x4e]);
      piVar2[2] = iVar1;
      iVar1 = FUN_404b2f08(piVar2[-5] * param_1[8],param_1[0x4f]);
      iVar3 = iVar3 + 1;
      piVar2[3] = iVar1;
      piVar2[4] = 1;
      piVar2[0xb] = 0;
      piVar2 = piVar2 + 0x15;
    } while (iVar3 < param_1[9]);
  }
  iVar3 = FUN_404b2f08(param_1[8],param_1[0x4f] << 3);
  param_1[0x51] = iVar3;
  if ((param_1[0x53] < param_1[9]) || (param_1[0x38] != 0)) {
    *(undefined4 *)(param_1[0x6e] + 0x10) = 1;
  }
  else {
    *(undefined4 *)(param_1[0x6e] + 0x10) = 0;
  }
  return;
}



/* 404b14d4 FUN_404b14d4 */

/* Boundary evidence: original MIPS .pdata 404b14d4..404b16fb. Semantic name remains unreviewed. */

void FUN_404b14d4(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  
  iVar1 = param_1[0x53];
  if (iVar1 == 1) {
    iVar1 = param_1[0x54];
    param_1[0x58] = *(int *)(iVar1 + 0x1c);
    param_1[0x59] = *(int *)(iVar1 + 0x20);
    uVar3 = *(uint *)(iVar1 + 0xc);
    uVar7 = *(uint *)(iVar1 + 0x20) % uVar3;
    *(undefined4 *)(iVar1 + 0x34) = 1;
    *(undefined4 *)(iVar1 + 0x38) = 1;
    *(undefined4 *)(iVar1 + 0x3c) = 1;
    *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar1 + 0x24);
    *(undefined4 *)(iVar1 + 0x44) = 1;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    if (uVar7 == 0) {
      uVar7 = uVar3;
    }
    *(uint *)(iVar1 + 0x48) = uVar7;
    param_1[0x5a] = 1;
    param_1[0x5b] = 0;
  }
  else {
    if ((iVar1 < 1) || (4 < iVar1)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1a;
      *(int *)(*param_1 + 0x18) = param_1[0x53];
      *(undefined4 *)(*param_1 + 0x1c) = 4;
      (**(code **)*param_1)(param_1);
    }
    iVar1 = FUN_404b2f08(param_1[7],param_1[0x4e] << 3);
    param_1[0x58] = iVar1;
    iVar1 = FUN_404b2f08(param_1[8],param_1[0x4f] << 3);
    iVar5 = 0;
    param_1[0x59] = iVar1;
    param_1[0x5a] = 0;
    if (0 < param_1[0x53]) {
      piVar6 = param_1 + 0x54;
      do {
        iVar2 = *piVar6;
        uVar4 = *(uint *)(iVar2 + 8);
        uVar3 = *(uint *)(iVar2 + 0xc);
        iVar1 = uVar3 * uVar4;
        *(uint *)(iVar2 + 0x34) = uVar4;
        *(uint *)(iVar2 + 0x38) = uVar3;
        *(int *)(iVar2 + 0x3c) = iVar1;
        *(uint *)(iVar2 + 0x40) = *(int *)(iVar2 + 0x24) * uVar4;
        uVar7 = *(uint *)(iVar2 + 0x1c) % uVar4;
        if (uVar4 == 0) {
          trap(0x1c00);
        }
        if (uVar7 == 0) {
          uVar7 = uVar4;
        }
        uVar4 = *(uint *)(iVar2 + 0x20) % uVar3;
        *(uint *)(iVar2 + 0x44) = uVar7;
        if (uVar3 == 0) {
          trap(0x1c00);
        }
        if (uVar4 == 0) {
          uVar4 = uVar3;
        }
        *(uint *)(iVar2 + 0x48) = uVar4;
        if (10 < param_1[0x5a] + iVar1) {
          *(undefined4 *)(*param_1 + 0x14) = 0xd;
          (**(code **)*param_1)(param_1);
        }
        for (; 0 < iVar1; iVar1 = iVar1 + -1) {
          param_1[param_1[0x5a] + 0x5b] = iVar5;
          param_1[0x5a] = param_1[0x5a] + 1;
        }
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar5 < param_1[0x53]);
    }
  }
  return;
}



/* 404b16fc FUN_404b16fc */

/* Boundary evidence: original MIPS .pdata 404b16fc..404b180f. Semantic name remains unreviewed. */

void FUN_404b16fc(int *param_1)

{
  void *_Dst;
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < param_1[0x53]) {
    piVar3 = param_1 + 0x54;
    do {
      iVar2 = *piVar3;
      if (*(int *)(iVar2 + 0x4c) == 0) {
        iVar1 = *(int *)(iVar2 + 0x10);
        if (((iVar1 < 0) || (3 < iVar1)) || (param_1[iVar1 + 0x2a] == 0)) {
          *(undefined4 *)(*param_1 + 0x14) = 0x34;
          *(int *)(*param_1 + 0x18) = iVar1;
          (**(code **)*param_1)(param_1);
        }
        _Dst = (void *)(**(code **)param_1[1])(param_1,1,0x84);
        memcpy(_Dst,(void *)param_1[iVar1 + 0x2a],0x84);
        *(void **)(iVar2 + 0x4c) = _Dst;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < param_1[0x53]);
  }
  return;
}



/* 404b1810 FUN_404b1810 */

/* Boundary evidence: original MIPS .pdata 404b1810..404b186f. Semantic name remains unreviewed. */

void FUN_404b1810(int *param_1)

{
  FUN_404b14d4(param_1);
  FUN_404b16fc(param_1);
  (**(code **)param_1[0x70])(param_1);
  (**(code **)param_1[0x6c])(param_1);
  *(undefined4 *)param_1[0x6e] = *(undefined4 *)(param_1[0x6c] + 4);
  return;
}



/* 404b1870 FUN_404b1870 */

/* Boundary evidence: original MIPS .pdata 404b1870..404b198f. Semantic name remains unreviewed. */

int FUN_404b1870(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[0x6e];
  if (*(int *)(iVar2 + 0x14) == 0) {
    iVar1 = (**(code **)(param_1[0x6f] + 4))(param_1);
    if (iVar1 == 1) {
      if (*(int *)(iVar2 + 0x18) == 0) {
        if (*(int *)(iVar2 + 0x10) == 0) {
          *(undefined4 *)(*param_1 + 0x14) = 0x23;
          (**(code **)*param_1)(param_1);
        }
        FUN_404b1810(param_1);
      }
      else {
        FUN_404b1218(param_1);
        *(undefined4 *)(iVar2 + 0x18) = 0;
      }
    }
    else if (iVar1 == 2) {
      *(undefined4 *)(iVar2 + 0x14) = 1;
      if (*(int *)(iVar2 + 0x18) == 0) {
        if (param_1[0x25] < param_1[0x27]) {
          param_1[0x27] = param_1[0x25];
        }
      }
      else if (*(int *)(param_1[0x6f] + 0x10) != 0) {
        *(undefined4 *)(*param_1 + 0x14) = 0x3b;
        (**(code **)*param_1)(param_1);
      }
    }
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}



/* 404b1990 FUN_404b1990 */

/* Boundary evidence: original MIPS .pdata 404b1990..404b19f3. Semantic name remains unreviewed. */

void FUN_404b1990(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[0x6e];
  *puVar1 = FUN_404b1870;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 1;
  (**(code **)(*param_1 + 0x10))(param_1);
  (**(code **)param_1[0x6f])(param_1);
  param_1[0x29] = 0;
  return;
}



/* 404b1a08 FUN_404b1a08 */

/* Boundary evidence: original MIPS .pdata 404b1a08..404b1a83. Semantic name remains unreviewed. */

void FUN_404b1a08(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x1c);
  *(undefined4 **)(param_1 + 0x1b8) = puVar1;
  *puVar1 = FUN_404b1870;
  puVar1[1] = FUN_404b1990;
  puVar1[2] = FUN_404b1810;
  puVar1[3] = &LAB_404b19f4;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 1;
  return;
}



/* 404b1a84 FUN_404b1a84 */

/* Boundary evidence: original MIPS .pdata 404b1a84..404b1cb7. Semantic name remains unreviewed. */

int FUN_404b1a84(int *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar7 = param_1[1];
  iVar5 = 0;
  if (0x3b9ac9f0 < param_3) {
    *(undefined4 *)(*param_1 + 0x14) = 0x36;
    *(undefined4 *)(*param_1 + 0x18) = 1;
    (**(code **)*param_1)(param_1);
  }
  if ((param_3 & 7) != 0) {
    param_3 = (param_3 - (param_3 & 7)) + 8;
  }
  if ((param_2 < 0) || (1 < param_2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0xe;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  else {
    puVar6 = (undefined4 *)((param_2 + 0xd) * 4 + iVar7);
    puVar2 = (undefined4 *)*puVar6;
    puVar1 = (undefined4 *)0x0;
    while (puVar3 = puVar2, puVar3 != (undefined4 *)0x0) {
      if (param_3 <= (uint)puVar3[2]) goto LAB_404b1c3c;
      puVar1 = puVar3;
      puVar2 = (undefined4 *)*puVar3;
    }
    iVar5 = param_3 + 0x10;
    if (puVar1 == (undefined4 *)0x0) {
      uVar4 = *(uint *)(&DAT_4048688c + param_2 * 4);
    }
    else {
      uVar4 = *(uint *)(&DAT_40486894 + param_2 * 4);
    }
    if (1000000000U - iVar5 < uVar4) {
      uVar4 = 1000000000U - iVar5;
    }
    puVar3 = (undefined4 *)FUN_404bc4a8(param_1,uVar4 + iVar5);
    while (puVar3 == (undefined4 *)0x0) {
      uVar4 = uVar4 >> 1;
      if (uVar4 < 0x32) {
        *(undefined4 *)(*param_1 + 0x14) = 0x36;
        *(undefined4 *)(*param_1 + 0x18) = 2;
        (**(code **)*param_1)(param_1);
      }
      puVar3 = (undefined4 *)FUN_404bc4a8(param_1,uVar4 + iVar5);
    }
    *(uint *)(iVar7 + 0x4c) = *(int *)(iVar7 + 0x4c) + uVar4 + iVar5;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = uVar4 + param_3;
    if (puVar1 == (undefined4 *)0x0) {
      *puVar6 = puVar3;
    }
    else {
      *puVar1 = puVar3;
    }
LAB_404b1c3c:
    iVar5 = (int)puVar3 + puVar3[1] + 0x10;
    puVar3[1] = puVar3[1] + param_3;
    puVar3[2] = puVar3[2] - param_3;
  }
  return iVar5;
}



/* 404b1cb8 FUN_404b1cb8 */

/* Boundary evidence: original MIPS .pdata 404b1cb8..404b1dff. Semantic name remains unreviewed. */

uint * FUN_404b1cb8(int *param_1,int param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = param_1[1];
  if (0x3b9ac9f0 < param_3) {
    *(undefined4 *)(*param_1 + 0x14) = 0x36;
    *(undefined4 *)(*param_1 + 0x18) = 3;
    (**(code **)*param_1)(param_1);
  }
  if ((param_3 & 7) != 0) {
    param_3 = (param_3 - (param_3 & 7)) + 8;
  }
  if ((param_2 < 0) || (1 < param_2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0xe;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  puVar1 = (uint *)FUN_404bc44c(param_1,param_3 + 0x10);
  if (puVar1 == (uint *)0x0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x36;
    *(undefined4 *)(*param_1 + 0x18) = 4;
    (**(code **)*param_1)(param_1);
  }
  puVar3 = (uint *)((param_2 + 0xf) * 4 + iVar4);
  *(uint *)(iVar4 + 0x4c) = *(int *)(iVar4 + 0x4c) + param_3 + 0x10;
  uVar2 = *puVar3;
  puVar1[1] = param_3;
  *puVar1 = uVar2;
  puVar1[2] = 0;
  *puVar3 = (uint)puVar1;
  return puVar1 + 4;
}



/* 404b1e00 FUN_404b1e00 */

/* Boundary evidence: original MIPS .pdata 404b1e00..404b1f2b. Semantic name remains unreviewed. */

int FUN_404b1e00(int *param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = param_1[1];
  uVar6 = 0x3b9ac9f0 / param_3;
  if (param_3 == 0) {
    trap(0x1c00);
  }
  if (uVar6 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x46;
    (**(code **)*param_1)(param_1);
  }
  if ((int)param_4 <= (int)uVar6) {
    uVar6 = param_4;
  }
  *(uint *)(iVar4 + 0x50) = uVar6;
  iVar4 = FUN_404b1a84(param_1,param_2,param_4 << 2);
  uVar5 = 0;
  if (param_4 != 0) {
    do {
      if (param_4 - uVar5 <= uVar6) {
        uVar6 = param_4 - uVar5;
      }
      puVar1 = FUN_404b1cb8(param_1,param_2,uVar6 * param_3);
      if (uVar6 != 0) {
        puVar2 = (undefined4 *)(uVar5 * 4 + iVar4);
        uVar5 = uVar5 + uVar6;
        uVar3 = uVar6;
        do {
          *puVar2 = puVar1;
          puVar2 = puVar2 + 1;
          uVar3 = uVar3 - 1;
          puVar1 = (uint *)((int)puVar1 + param_3);
        } while (uVar3 != 0);
      }
    } while (uVar5 < param_4);
  }
  return iVar4;
}



/* 404b1f2c FUN_404b1f2c */

/* Boundary evidence: original MIPS .pdata 404b1f2c..404b20d3. Semantic name remains unreviewed. */

int FUN_404b1f2c(int *param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = param_1[1];
  if (param_3 == 0) {
    trap(0x1c00);
  }
  uVar4 = 0x3b9ac9f0 / param_3 >> 7;
  if (uVar4 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x46;
    (**(code **)*param_1)(param_1);
  }
  if ((int)param_4 <= (int)uVar4) {
    uVar4 = param_4;
  }
  *(uint *)(iVar5 + 0x50) = uVar4;
  iVar5 = FUN_404b1a84(param_1,param_2,param_4 << 2);
  uVar6 = 0;
  if (param_4 != 0) {
    if (param_3 == 0) {
      trap(0x1c00);
    }
    do {
      if (param_4 - uVar6 <= uVar4) {
        uVar4 = param_4 - uVar6;
      }
      if (1000000000 / param_3 >> 7 < uVar4) {
LAB_404b2034:
        *(undefined4 *)(*param_1 + 0x14) = 0x46;
        (**(code **)*param_1)(param_1);
      }
      else {
        if (uVar4 == 0) {
          trap(0x1c00);
        }
        if (1000000000 / uVar4 >> 7 < param_3) goto LAB_404b2034;
      }
      puVar1 = FUN_404b1cb8(param_1,param_2,uVar4 * param_3 * 0x80);
      if (uVar4 != 0) {
        puVar2 = (undefined4 *)(uVar6 * 4 + iVar5);
        uVar6 = uVar6 + uVar4;
        uVar3 = uVar4;
        do {
          *puVar2 = puVar1;
          puVar2 = puVar2 + 1;
          uVar3 = uVar3 - 1;
          puVar1 = puVar1 + param_3 * 0x20;
        } while (uVar3 != 0);
      }
    } while (uVar6 < param_4);
  }
  return iVar5;
}



/* 404b20d4 FUN_404b20d4 */

/* Boundary evidence: original MIPS .pdata 404b20d4..404b218b. Semantic name remains unreviewed. */

void FUN_404b20d4(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  if (param_2 != 1) {
    *(undefined4 *)(*param_1 + 0x14) = 0xe;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  puVar1 = (undefined4 *)FUN_404b1a84(param_1,param_2,0x248);
  puVar1[2] = param_4;
  puVar1[8] = param_3;
  *puVar1 = 0;
  puVar1[1] = param_5;
  puVar1[3] = param_6;
  puVar1[10] = 0;
  puVar1[0xb] = *(undefined4 *)(iVar2 + 0x44);
  *(undefined4 **)(iVar2 + 0x44) = puVar1;
  return;
}



/* 404b218c FUN_404b218c */

/* Boundary evidence: original MIPS .pdata 404b218c..404b2243. Semantic name remains unreviewed. */

void FUN_404b218c(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  if (param_2 != 1) {
    *(undefined4 *)(*param_1 + 0x14) = 0xe;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  puVar1 = (undefined4 *)FUN_404b1a84(param_1,param_2,0x248);
  puVar1[2] = param_4;
  puVar1[8] = param_3;
  *puVar1 = 0;
  puVar1[1] = param_5;
  puVar1[3] = param_6;
  puVar1[10] = 0;
  puVar1[0xb] = *(undefined4 *)(iVar2 + 0x48);
  *(undefined4 **)(iVar2 + 0x48) = puVar1;
  return;
}



/* 404b2244 FUN_404b2244 */

/* Boundary evidence: original MIPS .pdata 404b2244..404b250b. Semantic name remains unreviewed. */

void FUN_404b2244(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_1[1];
  iVar4 = 0;
  iVar5 = 0;
  for (piVar2 = *(int **)(iVar6 + 0x44); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0xb]) {
    if (*piVar2 == 0) {
      iVar4 = piVar2[3] * piVar2[2] + iVar4;
      iVar5 = piVar2[1] * piVar2[2] + iVar5;
    }
  }
  for (piVar2 = *(int **)(iVar6 + 0x48); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0xb]) {
    if (*piVar2 == 0) {
      iVar4 = piVar2[3] * piVar2[2] * 0x80 + iVar4;
      iVar5 = piVar2[1] * piVar2[2] * 0x80 + iVar5;
    }
  }
  if (0 < iVar4) {
    iVar1 = FUN_404bc504(param_1,iVar4,iVar5);
    if (iVar1 < iVar5) {
      iVar5 = iVar1 / iVar4;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      if (iVar5 < 1) {
        iVar5 = 1;
      }
    }
    else {
      iVar5 = 1000000000;
    }
    for (piVar2 = *(int **)(iVar6 + 0x44); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0xb]) {
      if (*piVar2 == 0) {
        uVar3 = piVar2[3];
        if (uVar3 == 0) {
          trap(0x1c00);
        }
        if (iVar5 < (int)((piVar2[1] - 1U) / uVar3 + 1)) {
          piVar2[4] = uVar3 * iVar5;
          FUN_404bc50c();
          piVar2[10] = 1;
        }
        else {
          piVar2[4] = piVar2[1];
        }
        iVar4 = FUN_404b1e00(param_1,1,piVar2[2],piVar2[4]);
        *piVar2 = iVar4;
        piVar2[5] = *(int *)(iVar6 + 0x50);
        piVar2[6] = 0;
        piVar2[7] = 0;
        piVar2[9] = 0;
      }
    }
    for (piVar2 = *(int **)(iVar6 + 0x48); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0xb]) {
      if (*piVar2 == 0) {
        uVar3 = piVar2[3];
        if (uVar3 == 0) {
          trap(0x1c00);
        }
        if (iVar5 < (int)((piVar2[1] - 1U) / uVar3 + 1)) {
          piVar2[4] = uVar3 * iVar5;
          FUN_404bc50c();
          piVar2[10] = 1;
        }
        else {
          piVar2[4] = piVar2[1];
        }
        iVar4 = FUN_404b1f2c(param_1,1,piVar2[2],piVar2[4]);
        *piVar2 = iVar4;
        piVar2[5] = *(int *)(iVar6 + 0x50);
        piVar2[6] = 0;
        piVar2[7] = 0;
        piVar2[9] = 0;
      }
    }
  }
  return;
}



/* 404b250c FUN_404b250c */

/* Boundary evidence: original MIPS .pdata 404b250c..404b263f. Semantic name remains unreviewed. */

void FUN_404b250c(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_2[2];
  iVar5 = param_2[6] * iVar6;
  iVar2 = param_2[4];
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = param_2[5];
      if (iVar2 - iVar4 <= param_2[5]) {
        iVar3 = iVar2 - iVar4;
      }
      iVar2 = param_2[7] - (param_2[6] + iVar4);
      if (iVar2 <= iVar3) {
        iVar3 = iVar2;
      }
      iVar2 = param_2[1] - (param_2[6] + iVar4);
      if (iVar2 <= iVar3) {
        iVar3 = iVar2;
      }
      if (iVar3 < 1) {
        return;
      }
      iVar3 = iVar3 * iVar6;
      uVar1 = *(undefined4 *)(iVar4 * 4 + *param_2);
      if (param_3 == 0) {
        (*(code *)param_2[0xc])(param_1,param_2 + 0xc,uVar1,iVar5,iVar3);
      }
      else {
        (*(code *)param_2[0xd])(param_1,param_2 + 0xc,uVar1,iVar5,iVar3);
      }
      iVar2 = param_2[4];
      iVar4 = param_2[5] + iVar4;
      iVar5 = iVar3 + iVar5;
    } while (iVar4 < iVar2);
  }
  return;
}



/* 404b2640 FUN_404b2640 */

/* Boundary evidence: original MIPS .pdata 404b2640..404b2777. Semantic name remains unreviewed. */

void FUN_404b2640(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = param_2[2];
  iVar6 = iVar2 * 0x80 * param_2[6];
  iVar3 = param_2[4];
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      iVar4 = param_2[5];
      if (iVar3 - iVar5 <= param_2[5]) {
        iVar4 = iVar3 - iVar5;
      }
      iVar3 = param_2[7] - (iVar5 + param_2[6]);
      if (iVar3 <= iVar4) {
        iVar4 = iVar3;
      }
      iVar3 = param_2[1] - (iVar5 + param_2[6]);
      if (iVar3 <= iVar4) {
        iVar4 = iVar3;
      }
      if (iVar4 < 1) {
        return;
      }
      iVar4 = iVar4 * iVar2 * 0x80;
      uVar1 = *(undefined4 *)(iVar5 * 4 + *param_2);
      if (param_3 == 0) {
        (*(code *)param_2[0xc])(param_1,param_2 + 0xc,uVar1,iVar6,iVar4);
      }
      else {
        (*(code *)param_2[0xd])(param_1,param_2 + 0xc,uVar1,iVar6,iVar4);
      }
      iVar5 = param_2[5] + iVar5;
      iVar3 = param_2[4];
      iVar6 = iVar4 + iVar6;
    } while (iVar5 < iVar3);
  }
  return;
}



/* 404b2778 FUN_404b2778 */

/* Boundary evidence: original MIPS .pdata 404b2778..404b29a3. Semantic name remains unreviewed. */

int FUN_404b2778(int *param_1,int *param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  
  uVar3 = param_3 + param_4;
  if ((((uint)param_2[1] < uVar3) || ((uint)param_2[3] < param_4)) || (*param_2 == 0)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x16;
    (**(code **)*param_1)(param_1);
  }
  if ((param_3 < (uint)param_2[6]) || ((uint)(param_2[4] + param_2[6]) < uVar3)) {
    if (param_2[10] == 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x45;
      (**(code **)*param_1)(param_1);
    }
    if (param_2[9] != 0) {
      FUN_404b250c(param_1,param_2,1);
      param_2[9] = 0;
    }
    if ((uint)param_2[6] < param_3) {
      param_2[6] = param_3;
    }
    else {
      iVar2 = uVar3 - param_2[4];
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      param_2[6] = iVar2;
    }
    FUN_404b250c(param_1,param_2,0);
  }
  uVar1 = param_2[7];
  if (uVar1 < uVar3) {
    if ((uVar1 < param_3) && (uVar1 = param_3, param_5 != 0)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x16;
      (**(code **)*param_1)(param_1);
    }
    if (param_5 != 0) {
      param_2[7] = uVar3;
    }
    if (param_2[8] != 0) {
      uVar1 = uVar1 - param_2[6];
      uVar3 = uVar3 - param_2[6];
      sVar5 = param_2[2];
      if (uVar1 < uVar3) {
        iVar2 = uVar1 * 4;
        iVar4 = uVar3 - uVar1;
        do {
          FUN_404b301c(*(void **)(*param_2 + iVar2),sVar5);
          iVar4 = iVar4 + -1;
          iVar2 = iVar2 + 4;
        } while (iVar4 != 0);
      }
      goto LAB_404b2934;
    }
    if (param_5 == 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x16;
      (**(code **)*param_1)(param_1);
      goto LAB_404b2940;
    }
  }
  else {
LAB_404b2934:
    if (param_5 == 0) goto LAB_404b2940;
  }
  param_2[9] = 1;
LAB_404b2940:
  return (param_3 - param_2[6]) * 4 + *param_2;
}



/* 404b29a4 FUN_404b29a4 */

/* Boundary evidence: original MIPS .pdata 404b29a4..404b2bd3. Semantic name remains unreviewed. */

int FUN_404b29a4(int *param_1,int *param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = param_3 + param_4;
  if ((((uint)param_2[1] < uVar4) || ((uint)param_2[3] < param_4)) || (*param_2 == 0)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x16;
    (**(code **)*param_1)(param_1);
  }
  if ((param_3 < (uint)param_2[6]) || ((uint)(param_2[4] + param_2[6]) < uVar4)) {
    if (param_2[10] == 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x45;
      (**(code **)*param_1)(param_1);
    }
    if (param_2[9] != 0) {
      FUN_404b2640(param_1,param_2,1);
      param_2[9] = 0;
    }
    if ((uint)param_2[6] < param_3) {
      param_2[6] = param_3;
    }
    else {
      iVar1 = uVar4 - param_2[4];
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      param_2[6] = iVar1;
    }
    FUN_404b2640(param_1,param_2,0);
  }
  uVar2 = param_2[7];
  if (uVar2 < uVar4) {
    if ((uVar2 < param_3) && (uVar2 = param_3, param_5 != 0)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x16;
      (**(code **)*param_1)(param_1);
    }
    if (param_5 != 0) {
      param_2[7] = uVar4;
    }
    if (param_2[8] != 0) {
      iVar1 = param_2[2];
      uVar2 = uVar2 - param_2[6];
      uVar4 = uVar4 - param_2[6];
      if (uVar2 < uVar4) {
        iVar3 = uVar2 * 4;
        iVar5 = uVar4 - uVar2;
        do {
          FUN_404b301c(*(void **)(*param_2 + iVar3),iVar1 << 7);
          iVar5 = iVar5 + -1;
          iVar3 = iVar3 + 4;
        } while (iVar5 != 0);
      }
      goto LAB_404b2b64;
    }
    if (param_5 == 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x16;
      (**(code **)*param_1)(param_1);
      goto LAB_404b2b70;
    }
  }
  else {
LAB_404b2b64:
    if (param_5 == 0) goto LAB_404b2b70;
  }
  param_2[9] = 1;
LAB_404b2b70:
  return (param_3 - param_2[6]) * 4 + *param_2;
}



/* 404b2bd4 FUN_404b2bd4 */

/* Boundary evidence: original MIPS .pdata 404b2bd4..404b2d67. Semantic name remains unreviewed. */

void FUN_404b2bd4(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_1[1];
  if ((param_2 < 0) || (1 < param_2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0xe;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  if (param_2 == 1) {
    for (iVar4 = *(int *)(iVar6 + 0x44); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x2c)) {
      if (*(int *)(iVar4 + 0x28) != 0) {
        *(undefined4 *)(iVar4 + 0x28) = 0;
        (**(code **)(iVar4 + 0x38))(param_1,iVar4 + 0x30);
      }
    }
    iVar4 = *(int *)(iVar6 + 0x48);
    *(undefined4 *)(iVar6 + 0x44) = 0;
    for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x2c)) {
      if (*(int *)(iVar4 + 0x28) != 0) {
        *(undefined4 *)(iVar4 + 0x28) = 0;
        (**(code **)(iVar4 + 0x38))(param_1,iVar4 + 0x30);
      }
    }
    *(undefined4 *)(iVar6 + 0x48) = 0;
  }
  piVar3 = (int *)((param_2 + 0xf) * 4 + iVar6);
  piVar1 = (int *)*piVar3;
  *piVar3 = 0;
  while (piVar1 != (int *)0x0) {
    iVar2 = piVar1[2];
    iVar4 = piVar1[1];
    iVar5 = *piVar1;
    FUN_404bc48c(param_1,(int)piVar1);
    *(int *)(iVar6 + 0x4c) = *(int *)(iVar6 + 0x4c) - (iVar2 + iVar4 + 0x10);
    piVar1 = (int *)iVar5;
  }
  piVar3 = (int *)((param_2 + 0xd) * 4 + iVar6);
  piVar1 = (int *)*piVar3;
  *piVar3 = 0;
  while (piVar1 != (int *)0x0) {
    iVar2 = piVar1[2];
    iVar4 = piVar1[1];
    iVar5 = *piVar1;
    FUN_404bc4e8(param_1,(int)piVar1);
    *(int *)(iVar6 + 0x4c) = *(int *)(iVar6 + 0x4c) - (iVar2 + iVar4 + 0x10);
    piVar1 = (int *)iVar5;
  }
  return;
}



/* 404b2d68 FUN_404b2d68 */

/* Boundary evidence: original MIPS .pdata 404b2d68..404b2dc7. Semantic name remains unreviewed. */

void FUN_404b2d68(int *param_1)

{
  int iVar1;
  
  iVar1 = 1;
  do {
    FUN_404b2bd4(param_1,iVar1);
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  FUN_404bc4e8(param_1,param_1[1]);
  param_1[1] = 0;
  FUN_4049d5c4();
  return;
}



/* 404b2dc8 FUN_404b2dc8 */

/* Boundary evidence: original MIPS .pdata 404b2dc8..404b2f07. Semantic name remains unreviewed. */

void FUN_404b2dc8(int *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  param_1[1] = 0;
  uVar1 = FUN_404a3c98();
  puVar2 = (undefined4 *)FUN_404bc4a8(param_1,0x54);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_4049d5c4();
    *(undefined4 *)(*param_1 + 0x14) = 0x36;
    *(undefined4 *)(*param_1 + 0x18) = 0;
    (**(code **)*param_1)(param_1);
  }
  else {
    puVar2[2] = FUN_404b1e00;
    *puVar2 = FUN_404b1a84;
    puVar2[1] = FUN_404b1cb8;
    puVar2[5] = FUN_404b218c;
    puVar2[3] = FUN_404b1f2c;
    puVar2[4] = FUN_404b20d4;
    puVar2[8] = FUN_404b29a4;
    puVar2[6] = FUN_404b2244;
    puVar2[7] = FUN_404b2778;
    puVar2[9] = FUN_404b2bd4;
    puVar2[10] = FUN_404b2d68;
    puVar2[0xc] = 1000000000;
    puVar2[0xb] = uVar1;
    puVar2[0xe] = 0;
    puVar2[0x10] = 0;
    puVar2[0xd] = 0;
    puVar2[0xf] = 0;
    puVar2[0x11] = 0;
    puVar2[0x12] = 0;
    puVar2[0x13] = 0x54;
    param_1[1] = (int)puVar2;
  }
  return;
}



/* 404b2f08 FUN_404b2f08 */

int FUN_404b2f08(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 + param_2 + -1;
  if (param_2 == 0) {
    trap(0x1c00);
  }
  if ((param_2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return iVar1 / param_2;
}



/* 404b2f44 FUN_404b2f44 */

int FUN_404b2f44(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 + param_2 + -1;
  if (param_2 == 0) {
    trap(0x1c00);
  }
  if ((param_2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return iVar1 - iVar1 % param_2;
}



/* 404b2f80 FUN_404b2f80 */

/* Boundary evidence: original MIPS .pdata 404b2f80..404b2ff3. Semantic name remains unreviewed. */

void FUN_404b2f80(int param_1,int param_2,int param_3,int param_4,int param_5,size_t param_6)

{
  void *_Dst;
  void *_Src;
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)(param_2 * 4 + param_1);
  puVar2 = (undefined4 *)(param_4 * 4 + param_3);
  for (; 0 < param_5; param_5 = param_5 + -1) {
    _Src = (void *)*puVar1;
    _Dst = (void *)*puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
    memcpy(_Dst,_Src,param_6);
  }
  return;
}



/* 404b2ff4 FUN_404b2ff4 */

/* Boundary evidence: original MIPS .pdata 404b2ff4..404b301b. Semantic name remains unreviewed. */

void FUN_404b2ff4(void *param_1,void *param_2,int param_3)

{
  memcpy(param_2,param_1,param_3 << 7);
  return;
}



/* 404b301c FUN_404b301c */

/* Boundary evidence: original MIPS .pdata 404b301c..404b303b. Semantic name remains unreviewed. */

void FUN_404b301c(void *param_1,size_t param_2)

{
  memset(param_1,0,param_2);
  return;
}



/* 404b303c FUN_404b303c */

/* Boundary evidence: original MIPS .pdata 404b303c..404b3193. Semantic name remains unreviewed. */

void FUN_404b303c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  
  iVar5 = *(int *)(param_1 + 0x1ac);
  iVar4 = *(int *)(param_1 + 0x140);
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,*(int *)(param_1 + 0x24) << 3);
  *(int *)(iVar5 + 0x38) = iVar1;
  *(int *)(iVar5 + 0x3c) = *(int *)(param_1 + 0x24) * 4 + iVar1;
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    iVar6 = 0;
    piVar7 = (int *)(*(int *)(param_1 + 0xdc) + 0xc);
    do {
      iVar3 = *(int *)(param_1 + 0x140);
      iVar8 = (piVar7[6] * *piVar7) / iVar3;
      if (iVar3 == 0) {
        trap(0x1c00);
      }
      if ((iVar3 == -1) && (piVar7[6] * *piVar7 == -0x80000000)) {
        trap(0x1800);
      }
      iVar3 = (iVar4 + 4) * iVar8;
      iVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,iVar3 * 8);
      iVar2 = iVar2 + iVar8 * 4;
      *(int *)(*(int *)(iVar5 + 0x38) + iVar6) = iVar2;
      *(int *)(iVar6 + *(int *)(iVar5 + 0x3c)) = iVar3 * 4 + iVar2;
      iVar1 = iVar1 + 1;
      iVar6 = iVar6 + 4;
      piVar7 = piVar7 + 0x15;
    } while (iVar1 < *(int *)(param_1 + 0x24));
  }
  return;
}



/* 404b3194 FUN_404b3194 */

/* Boundary evidence: original MIPS .pdata 404b3194..404b3343. Semantic name remains unreviewed. */

void FUN_404b3194(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  
  iVar12 = *(int *)(param_1 + 0x1ac);
  iVar11 = *(int *)(param_1 + 0x140);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    iVar2 = 0;
    piVar9 = (int *)(*(int *)(param_1 + 0xdc) + 0xc);
    piVar10 = (int *)(iVar12 + 8);
    do {
      iVar5 = *(int *)(param_1 + 0x140);
      iVar14 = (piVar9[6] * *piVar9) / iVar5;
      if (iVar5 == 0) {
        trap(0x1c00);
      }
      if ((iVar5 == -1) && (piVar9[6] * *piVar9 == -0x80000000)) {
        trap(0x1800);
      }
      iVar5 = (iVar11 + 2) * iVar14;
      puVar13 = *(undefined4 **)(iVar2 + *(int *)(iVar12 + 0x38));
      puVar1 = *(undefined4 **)(iVar2 + *(int *)(iVar12 + 0x3c));
      iVar4 = *piVar10;
      if (0 < iVar5) {
        puVar7 = puVar1;
        do {
          uVar6 = *(undefined4 *)((iVar4 - (int)puVar1) + (int)puVar7);
          *puVar7 = uVar6;
          *(undefined4 *)(((int)puVar13 - (int)puVar1) + (int)puVar7) = uVar6;
          iVar5 = iVar5 + -1;
          puVar7 = puVar7 + 1;
        } while (iVar5 != 0);
      }
      iVar5 = iVar14 << 1;
      if (0 < iVar5) {
        puVar7 = puVar1 + iVar14 * iVar11;
        puVar8 = (undefined4 *)((iVar11 + -2) * iVar14 * 4 + iVar4);
        do {
          *(undefined4 *)(((int)puVar1 - iVar4) + (int)puVar8) =
               *(undefined4 *)((int)puVar7 + (iVar4 - (int)puVar1));
          iVar5 = iVar5 + -1;
          *puVar7 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar5 != 0);
      }
      if (0 < iVar14) {
        puVar1 = puVar13 + -iVar14;
        do {
          iVar14 = iVar14 + -1;
          *puVar1 = *puVar13;
          puVar1 = puVar1 + 1;
        } while (iVar14 != 0);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
      piVar10 = piVar10 + 1;
      piVar9 = piVar9 + 0x15;
    } while (iVar3 < *(int *)(param_1 + 0x24));
  }
  return;
}



/* 404b3344 FUN_404b3344 */

void FUN_404b3344(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  
  iVar4 = *(int *)(param_1 + 0x1ac);
  iVar3 = *(int *)(param_1 + 0x140);
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    iVar7 = 0;
    piVar8 = (int *)(*(int *)(param_1 + 0xdc) + 0xc);
    do {
      iVar5 = *(int *)(param_1 + 0x140);
      iVar12 = (piVar8[6] * *piVar8) / iVar5;
      if (iVar5 == 0) {
        trap(0x1c00);
      }
      if ((iVar5 == -1) && (piVar8[6] * *piVar8 == -0x80000000)) {
        trap(0x1800);
      }
      puVar10 = *(undefined4 **)(iVar7 + *(int *)(iVar4 + 0x3c));
      if (0 < iVar12) {
        puVar2 = puVar10 + -iVar12;
        iVar5 = *(int *)(iVar7 + *(int *)(iVar4 + 0x38)) - (int)puVar10;
        puVar11 = puVar10 + (iVar3 + 2) * iVar12;
        puVar1 = puVar10 + (iVar3 + 1) * iVar12;
        do {
          *(undefined4 *)(iVar5 + (int)puVar2) = *(undefined4 *)(iVar5 + (int)puVar1);
          *puVar2 = *puVar1;
          *(undefined4 *)(iVar5 + (int)puVar11) = *(undefined4 *)(iVar5 + (int)puVar10);
          uVar6 = *puVar10;
          puVar10 = puVar10 + 1;
          iVar12 = iVar12 + -1;
          *puVar11 = uVar6;
          puVar1 = puVar1 + 1;
          puVar2 = puVar2 + 1;
          puVar11 = puVar11 + 1;
        } while (iVar12 != 0);
      }
      iVar9 = iVar9 + 1;
      iVar7 = iVar7 + 4;
      piVar8 = piVar8 + 0x15;
    } while (iVar9 < *(int *)(param_1 + 0x24));
  }
  return;
}



/* 404b3470 FUN_404b3470 */

void FUN_404b3470(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  iVar3 = *(int *)(param_1 + 0x1ac);
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    piVar2 = (int *)(*(int *)(param_1 + 0xdc) + 0xc);
    do {
      uVar1 = piVar2[6] * *piVar2;
      iVar4 = *(int *)(param_1 + 0x140);
      iVar9 = (int)uVar1 / iVar4;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (uVar1 == 0x80000000)) {
        trap(0x1800);
      }
      if (uVar1 == 0) {
        trap(0x1c00);
      }
      uVar8 = (uint)piVar2[8] % uVar1;
      if ((uint)piVar2[8] % uVar1 == 0) {
        uVar8 = uVar1;
      }
      if (iVar7 == 0) {
        if (iVar9 == 0) {
          trap(0x1c00);
        }
        if ((iVar9 == -1) && (uVar8 - 1 == -0x80000000)) {
          trap(0x1800);
        }
        *(int *)(iVar3 + 0x48) = (int)(uVar8 - 1) / iVar9 + 1;
      }
      iVar9 = iVar9 << 1;
      if (0 < iVar9) {
        puVar6 = (undefined4 *)
                 (uVar8 * 4 +
                 *(int *)(*(int *)((*(int *)(iVar3 + 0x40) + 0xe) * 4 + iVar3) + iVar7 * 4));
        puVar5 = puVar6 + -1;
        do {
          iVar9 = iVar9 + -1;
          *puVar6 = *puVar5;
          puVar6 = puVar6 + 1;
        } while (iVar9 != 0);
      }
      iVar7 = iVar7 + 1;
      piVar2 = piVar2 + 0x15;
    } while (iVar7 < *(int *)(param_1 + 0x24));
  }
  return;
}



/* 404b3598 FUN_404b3598 */

/* Boundary evidence: original MIPS .pdata 404b3598..404b366b. Semantic name remains unreviewed. */

void FUN_404b3598(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  
  iVar3 = *(int *)(param_1 + 0x1ac);
  if (*(int *)(iVar3 + 0x30) == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x1b0) + 0xc))(param_1,iVar3 + 8);
    if (iVar1 == 0) {
      return;
    }
    *(undefined4 *)(iVar3 + 0x30) = 1;
  }
  uVar2 = *(uint *)(param_1 + 0x140);
  puVar4 = (uint *)(iVar3 + 0x34);
  (**(code **)(*(int *)(param_1 + 0x1b4) + 4))
            (param_1,iVar3 + 8,puVar4,uVar2,param_2,param_3,param_4);
  if (uVar2 <= *puVar4) {
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *puVar4 = 0;
  }
  return;
}



/* 404b366c FUN_404b366c */

/* Boundary evidence: original MIPS .pdata 404b366c..404b3857. Semantic name remains unreviewed. */

void FUN_404b366c(int param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1ac);
  if (*(int *)(iVar3 + 0x30) == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x1b0) + 0xc))
                      (param_1,*(undefined4 *)((*(int *)(iVar3 + 0x40) + 0xe) * 4 + iVar3));
    if (iVar1 == 0) {
      return;
    }
    *(undefined4 *)(iVar3 + 0x30) = 1;
    *(int *)(iVar3 + 0x4c) = *(int *)(iVar3 + 0x4c) + 1;
  }
  iVar1 = *(int *)(iVar3 + 0x44);
  if (iVar1 != 0) {
    if (iVar1 == 1) goto LAB_404b379c;
    if (iVar1 != 2) {
      return;
    }
    (**(code **)(*(int *)(param_1 + 0x1b4) + 4))
              (param_1,*(undefined4 *)((*(int *)(iVar3 + 0x40) + 0xe) * 4 + iVar3),
               (uint *)(iVar3 + 0x34),*(undefined4 *)(iVar3 + 0x48),param_2,param_3,param_4);
    if (*(uint *)(iVar3 + 0x34) < *(uint *)(iVar3 + 0x48)) {
      return;
    }
    *(undefined4 *)(iVar3 + 0x44) = 0;
    if (param_4 <= *param_3) {
      return;
    }
  }
  *(undefined4 *)(iVar3 + 0x34) = 0;
  *(int *)(iVar3 + 0x48) = *(int *)(param_1 + 0x140) + -1;
  if (*(int *)(iVar3 + 0x4c) == *(int *)(param_1 + 0x144)) {
    FUN_404b3470(param_1);
  }
  *(undefined4 *)(iVar3 + 0x44) = 1;
LAB_404b379c:
  puVar2 = (uint *)(iVar3 + 0x34);
  (**(code **)(*(int *)(param_1 + 0x1b4) + 4))
            (param_1,*(undefined4 *)((*(int *)(iVar3 + 0x40) + 0xe) * 4 + iVar3),puVar2,
             *(undefined4 *)(iVar3 + 0x48),param_2,param_3,param_4);
  if (*(uint *)(iVar3 + 0x48) <= *puVar2) {
    if (*(int *)(iVar3 + 0x4c) == 1) {
      FUN_404b3344(param_1);
    }
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) ^ 1;
    *puVar2 = *(int *)(param_1 + 0x140) + 1;
    iVar1 = *(int *)(param_1 + 0x140);
    *(undefined4 *)(iVar3 + 0x44) = 2;
    *(int *)(iVar3 + 0x48) = iVar1 + 2;
  }
  return;
}



/* 404b3858 FUN_404b3858 */

/* Boundary evidence: original MIPS .pdata 404b3858..404b38eb. Semantic name remains unreviewed. */

void FUN_404b3858(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[0x6b];
  if (param_2 != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 4;
    (**(code **)*param_1)();
    return;
  }
  if (*(int *)(param_1[0x72] + 8) == 0) {
    *(code **)(iVar1 + 4) = FUN_404b3598;
  }
  else {
    *(code **)(iVar1 + 4) = FUN_404b366c;
    FUN_404b3194((int)param_1);
    *(undefined4 *)(iVar1 + 0x40) = 0;
    *(undefined4 *)(iVar1 + 0x44) = 0;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
  }
  *(undefined4 *)(iVar1 + 0x30) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  return;
}



/* 404b38ec FUN_404b38ec */

/* Boundary evidence: original MIPS .pdata 404b38ec..404b3a7f. Semantic name remains unreviewed. */

void FUN_404b38ec(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  puVar2 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x50);
  param_1[0x6b] = (int)puVar2;
  *puVar2 = FUN_404b3858;
  if (param_2 != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 4;
    (**(code **)*param_1)(param_1);
  }
  if (*(int *)(param_1[0x72] + 8) == 0) {
    iVar5 = param_1[0x50];
  }
  else {
    if (param_1[0x50] < 2) {
      *(undefined4 *)(*param_1 + 0x14) = 0x2f;
      (**(code **)*param_1)(param_1);
    }
    FUN_404b303c((int)param_1);
    iVar5 = param_1[0x50] + 2;
  }
  iVar7 = 0;
  if (0 < param_1[9]) {
    piVar6 = (int *)(param_1[0x37] + 0xc);
    puVar2 = puVar2 + 2;
    do {
      iVar1 = *piVar6 * piVar6[6];
      iVar4 = param_1[0x50];
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      uVar3 = (**(code **)(param_1[1] + 8))(param_1,1,piVar6[4] * piVar6[6],(iVar1 / iVar4) * iVar5)
      ;
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 0x15;
      *puVar2 = uVar3;
      puVar2 = puVar2 + 1;
    } while (iVar7 < param_1[9]);
  }
  return;
}



/* 404b3a80 FUN_404b3a80 */

void FUN_404b3a80(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1b0);
  if (1 < *(int *)(param_1 + 0x14c)) {
    *(undefined4 *)(iVar1 + 0x1c) = 1;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    return;
  }
  if (*(uint *)(param_1 + 0x98) < *(int *)(param_1 + 0x144) - 1U) {
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0x150) + 0xc);
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    return;
  }
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0x150) + 0x48);
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return;
}



/* 404b3af4 FUN_404b3af4 */

/* Boundary evidence: original MIPS .pdata 404b3af4..404b3b0f. Semantic name remains unreviewed. */

void FUN_404b3af4(int param_1)

{
  *(undefined4 *)(param_1 + 0x98) = 0;
  FUN_404b3a80(param_1);
  return;
}



/* 404b3b10 FUN_404b3b10 */

/* Boundary evidence: original MIPS .pdata 404b3b10..404b3e43. Semantic name remains unreviewed. */

undefined4 FUN_404b3b10(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int local_48;
  
  iVar11 = *(int *)(param_1 + 0x1b0);
  iVar3 = *(int *)(param_1 + 0x144);
  uVar13 = *(int *)(param_1 + 0x160) - 1;
  iVar8 = *(int *)(iVar11 + 0x18);
  if (iVar8 < *(int *)(iVar11 + 0x1c)) {
    do {
      for (uVar16 = *(uint *)(iVar11 + 0x14); uVar16 <= uVar13; uVar16 = uVar16 + 1) {
        FUN_404b301c(*(void **)(iVar11 + 0x20),*(int *)(param_1 + 0x168) << 7);
        iVar1 = (**(code **)(*(int *)(param_1 + 0x1c0) + 4))(param_1,(undefined4 *)(iVar11 + 0x20));
        if (iVar1 == 0) {
          *(int *)(iVar11 + 0x18) = iVar8;
          *(uint *)(iVar11 + 0x14) = uVar16;
          return 0;
        }
        iVar1 = 0;
        local_48 = 0;
        if (0 < *(int *)(param_1 + 0x14c)) {
          piVar6 = (int *)(param_1 + 0x150);
          do {
            iVar7 = *piVar6;
            if (*(int *)(iVar7 + 0x30) == 0) {
              iVar1 = *(int *)(iVar7 + 0x3c) + iVar1;
            }
            else {
              iVar5 = *(int *)(iVar7 + 4) * 4;
              pcVar4 = *(code **)(*(int *)(param_1 + 0x1c4) + iVar5 + 4);
              if (uVar16 < uVar13) {
                iVar15 = *(int *)(iVar7 + 0x34);
              }
              else {
                iVar15 = *(int *)(iVar7 + 0x44);
              }
              iVar14 = *(int *)(iVar5 + param_2) + iVar8 * *(int *)(iVar7 + 0x24) * 4;
              iVar5 = *(int *)(iVar7 + 0x40);
              iVar17 = 0;
              if (0 < *(int *)(iVar7 + 0x38)) {
                do {
                  if (((*(uint *)(param_1 + 0x98) < iVar3 - 1U) ||
                      (iVar17 + iVar8 < *(int *)(iVar7 + 0x48))) && (0 < iVar15)) {
                    puVar10 = (undefined4 *)((iVar1 + 8) * 4 + iVar11);
                    iVar9 = iVar5 * uVar16;
                    iVar12 = iVar15;
                    do {
                      (*pcVar4)(param_1,iVar7,*puVar10,iVar14,iVar9);
                      iVar9 = iVar9 + *(int *)(iVar7 + 0x24);
                      iVar12 = iVar12 + -1;
                      puVar10 = puVar10 + 1;
                    } while (iVar12 != 0);
                  }
                  iVar1 = *(int *)(iVar7 + 0x34) + iVar1;
                  iVar17 = iVar17 + 1;
                  iVar14 = *(int *)(iVar7 + 0x24) * 4 + iVar14;
                } while (iVar17 < *(int *)(iVar7 + 0x38));
              }
            }
            local_48 = local_48 + 1;
            piVar6 = piVar6 + 1;
          } while (local_48 < *(int *)(param_1 + 0x14c));
        }
      }
      *(undefined4 *)(iVar11 + 0x14) = 0;
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(iVar11 + 0x1c));
  }
  uVar13 = *(int *)(param_1 + 0x98) + 1;
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
  *(uint *)(param_1 + 0x98) = uVar13;
  if (uVar13 < *(uint *)(param_1 + 0x144)) {
    iVar3 = *(int *)(param_1 + 0x1b0);
    if (*(int *)(param_1 + 0x14c) < 2) {
      if (uVar13 < *(uint *)(param_1 + 0x144) - 1) {
        uVar2 = 3;
        *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0x150) + 0xc);
        *(undefined4 *)(iVar3 + 0x14) = 0;
        *(undefined4 *)(iVar3 + 0x18) = 0;
      }
      else {
        uVar2 = 3;
        *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0x150) + 0x48);
        *(undefined4 *)(iVar3 + 0x14) = 0;
        *(undefined4 *)(iVar3 + 0x18) = 0;
      }
    }
    else {
      *(undefined4 *)(iVar3 + 0x1c) = 1;
      *(undefined4 *)(iVar3 + 0x14) = 0;
      uVar2 = 3;
      *(undefined4 *)(iVar3 + 0x18) = 0;
    }
  }
  else {
    (**(code **)(*(int *)(param_1 + 0x1b8) + 0xc))(param_1);
    uVar2 = 4;
  }
  return uVar2;
}



/* 404b3e44 FUN_404b3e44 */

/* Boundary evidence: original MIPS .pdata 404b3e44..404b40cf. Semantic name remains unreviewed. */

undefined4 FUN_404b3e44(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int *piVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  int local_30 [4];
  
  iVar15 = *(int *)(param_1 + 0x1b0);
  iVar12 = 0;
  if (0 < *(int *)(param_1 + 0x14c)) {
    piVar2 = local_30;
    piVar14 = (int *)(param_1 + 0x150);
    do {
      iVar4 = *(int *)(*piVar14 + 0xc);
      iVar4 = (**(code **)(*(int *)(param_1 + 4) + 0x20))
                        (param_1,*(undefined4 *)((*(int *)(*piVar14 + 4) + 0x12) * 4 + iVar15),
                         iVar4 * *(int *)(param_1 + 0x98),iVar4,1);
      iVar5 = *(int *)(param_1 + 0x14c);
      iVar12 = iVar12 + 1;
      *piVar2 = iVar4;
      piVar14 = piVar14 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar12 < iVar5);
  }
  iVar12 = *(int *)(iVar15 + 0x18);
  if (iVar12 < *(int *)(iVar15 + 0x1c)) {
    iVar4 = iVar12 << 2;
    do {
      uVar13 = *(uint *)(iVar15 + 0x14);
      if (uVar13 < *(uint *)(param_1 + 0x160)) {
        do {
          iVar11 = 0;
          iVar5 = 0;
          if (0 < *(int *)(param_1 + 0x14c)) {
            piVar2 = local_30;
            piVar14 = (int *)(param_1 + 0x150);
            do {
              iVar10 = *piVar14;
              iVar17 = 0;
              iVar6 = *(int *)(iVar10 + 0x34);
              iVar1 = iVar6 * uVar13;
              if (0 < *(int *)(iVar10 + 0x38)) {
                piVar16 = (int *)(iVar4 + *piVar2);
                do {
                  iVar8 = *piVar16 + iVar1 * 0x80;
                  iVar9 = 0;
                  if (0 < iVar6) {
                    piVar7 = (int *)((iVar11 + 8) * 4 + iVar15);
                    do {
                      *piVar7 = iVar8;
                      iVar6 = *(int *)(iVar10 + 0x34);
                      iVar9 = iVar9 + 1;
                      iVar11 = iVar11 + 1;
                      piVar7 = piVar7 + 1;
                      iVar8 = iVar8 + 0x80;
                    } while (iVar9 < iVar6);
                  }
                  iVar17 = iVar17 + 1;
                  piVar16 = piVar16 + 1;
                } while (iVar17 < *(int *)(iVar10 + 0x38));
              }
              iVar5 = iVar5 + 1;
              piVar14 = piVar14 + 1;
              piVar2 = piVar2 + 1;
            } while (iVar5 < *(int *)(param_1 + 0x14c));
          }
          iVar5 = (**(code **)(*(int *)(param_1 + 0x1c0) + 4))(param_1,iVar15 + 0x20);
          if (iVar5 == 0) {
            *(int *)(iVar15 + 0x18) = iVar12;
            *(uint *)(iVar15 + 0x14) = uVar13;
            return 0;
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < *(uint *)(param_1 + 0x160));
      }
      *(undefined4 *)(iVar15 + 0x14) = 0;
      iVar12 = iVar12 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar12 < *(int *)(iVar15 + 0x1c));
  }
  uVar13 = *(int *)(param_1 + 0x98) + 1;
  *(uint *)(param_1 + 0x98) = uVar13;
  if (uVar13 < *(uint *)(param_1 + 0x144)) {
    iVar12 = *(int *)(param_1 + 0x1b0);
    if (*(int *)(param_1 + 0x14c) < 2) {
      if (uVar13 < *(uint *)(param_1 + 0x144) - 1) {
        uVar3 = 3;
        *(undefined4 *)(iVar12 + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0x150) + 0xc);
        *(undefined4 *)(iVar12 + 0x14) = 0;
        *(undefined4 *)(iVar12 + 0x18) = 0;
      }
      else {
        uVar3 = 3;
        *(undefined4 *)(iVar12 + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0x150) + 0x48);
        *(undefined4 *)(iVar12 + 0x14) = 0;
        *(undefined4 *)(iVar12 + 0x18) = 0;
      }
    }
    else {
      *(undefined4 *)(iVar12 + 0x1c) = 1;
      uVar3 = 3;
      *(undefined4 *)(iVar12 + 0x14) = 0;
      *(undefined4 *)(iVar12 + 0x18) = 0;
    }
  }
  else {
    (**(code **)(*(int *)(param_1 + 0x1b8) + 0xc))(param_1);
    uVar3 = 4;
  }
  return uVar3;
}



/* 404b40d0 FUN_404b40d0 */

/* Boundary evidence: original MIPS .pdata 404b40d0..404b430b. Semantic name remains unreviewed. */

undefined4 FUN_404b40d0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  code *pcVar11;
  int local_38;
  int local_34;
  
  iVar3 = *(int *)(param_1 + 0x144);
  iVar6 = *(int *)(param_1 + 0x1b0);
  while( true ) {
    if ((*(int *)(param_1 + 0x9c) <= *(int *)(param_1 + 0x94)) &&
       ((*(int *)(param_1 + 0x94) != *(int *)(param_1 + 0x9c) ||
        (*(uint *)(param_1 + 0xa0) < *(uint *)(param_1 + 0x98))))) break;
    iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x1b8))(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = *(int *)(param_1 + 0xdc);
  local_38 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    puVar7 = (undefined4 *)(iVar6 + 0x48);
    local_34 = 0;
    do {
      if (*(int *)(iVar1 + 0x30) != 0) {
        piVar2 = (int *)(**(code **)(*(int *)(param_1 + 4) + 0x20))
                                  (param_1,*puVar7,*(int *)(iVar1 + 0xc) * *(int *)(param_1 + 0xa0),
                                   *(int *)(iVar1 + 0xc),0);
        if (*(uint *)(param_1 + 0xa0) < iVar3 - 1U) {
          uVar4 = *(uint *)(iVar1 + 0xc);
        }
        else {
          uVar5 = *(uint *)(iVar1 + 0xc);
          uVar4 = *(uint *)(iVar1 + 0x20) % uVar5;
          if (uVar5 == 0) {
            trap(0x1c00);
          }
          if (uVar4 == 0) {
            uVar4 = uVar5;
          }
        }
        pcVar11 = *(code **)(*(int *)(param_1 + 0x1c4) + local_34 + 4);
        iVar6 = *(int *)(local_34 + param_2);
        if (0 < (int)uVar4) {
          uVar5 = *(uint *)(iVar1 + 0x1c);
          do {
            iVar8 = *piVar2;
            iVar9 = 0;
            uVar10 = 0;
            if (uVar5 != 0) {
              do {
                (*pcVar11)(param_1,iVar1,iVar8,iVar6,iVar9);
                uVar5 = *(uint *)(iVar1 + 0x1c);
                uVar10 = uVar10 + 1;
                iVar8 = iVar8 + 0x80;
                iVar9 = *(int *)(iVar1 + 0x24) + iVar9;
              } while (uVar10 < uVar5);
            }
            piVar2 = piVar2 + 1;
            uVar4 = uVar4 - 1;
            iVar6 = *(int *)(iVar1 + 0x24) * 4 + iVar6;
          } while (uVar4 != 0);
        }
      }
      local_38 = local_38 + 1;
      local_34 = local_34 + 4;
      puVar7 = puVar7 + 1;
      iVar1 = iVar1 + 0x54;
    } while (local_38 < *(int *)(param_1 + 0x24));
  }
  uVar4 = *(int *)(param_1 + 0xa0) + 1;
  *(uint *)(param_1 + 0xa0) = uVar4;
  if (uVar4 < *(uint *)(param_1 + 0x144)) {
    return 3;
  }
  return 4;
}



/* 404b430c FUN_404b430c */

/* Boundary evidence: original MIPS .pdata 404b430c..404b44af. Semantic name remains unreviewed. */

undefined4 FUN_404b430c(int param_1)

{
  undefined4 uVar1;
  short *psVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = *(int *)(param_1 + 0x1b0);
  uVar5 = 0;
  if ((*(int *)(param_1 + 0xe0) == 0) || (*(int *)(param_1 + 0xa4) == 0)) {
LAB_404b4494:
    uVar5 = 0;
  }
  else {
    if (*(int *)(iVar6 + 0x70) == 0) {
      uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,*(int *)(param_1 + 0x24) * 0x18);
      *(undefined4 *)(iVar6 + 0x70) = uVar1;
    }
    iVar6 = *(int *)(iVar6 + 0x70);
    iVar8 = 0;
    if (0 < *(int *)(param_1 + 0x24)) {
      iVar7 = 0;
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0xdc) + 0x4c);
      do {
        psVar2 = (short *)*puVar4;
        if (((((psVar2 == (short *)0x0) || (*psVar2 == 0)) || (psVar2[1] == 0)) ||
            ((psVar2[8] == 0 || (psVar2[0x10] == 0)))) ||
           ((psVar2[9] == 0 ||
            ((psVar2[2] == 0 || (piVar3 = (int *)(*(int *)(param_1 + 0xa4) + iVar7), *piVar3 < 0))))
           )) goto LAB_404b4494;
        *(int *)(iVar6 + 4) = piVar3[1];
        if (piVar3[1] != 0) {
          uVar5 = 1;
        }
        *(int *)(iVar6 + 8) = piVar3[2];
        if (piVar3[2] != 0) {
          uVar5 = 1;
        }
        *(int *)(iVar6 + 0xc) = piVar3[3];
        if (piVar3[3] != 0) {
          uVar5 = 1;
        }
        *(int *)(iVar6 + 0x10) = piVar3[4];
        if (piVar3[4] != 0) {
          uVar5 = 1;
        }
        *(int *)(iVar6 + 0x14) = piVar3[5];
        if (piVar3[5] != 0) {
          uVar5 = 1;
        }
        iVar8 = iVar8 + 1;
        iVar6 = iVar6 + 0x18;
        iVar7 = iVar7 + 0x100;
        puVar4 = puVar4 + 0x15;
      } while (iVar8 < *(int *)(param_1 + 0x24));
    }
  }
  return uVar5;
}



/* 404b44b0 FUN_404b44b0 */

/* Boundary evidence: original MIPS .pdata 404b44b0..404b4e33. Semantic name remains unreviewed. */

undefined4 FUN_404b44b0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  ushort *puVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  bool bVar23;
  undefined4 *puVar24;
  int iVar25;
  int iVar26;
  short *psVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  short *local_114;
  uint local_110;
  int local_10c;
  int local_108;
  int local_104;
  uint local_100;
  short *local_fc;
  int *local_f8;
  int local_dc;
  int local_d4;
  int local_c8;
  undefined1 auStack_b0 [2];
  short local_ae;
  short local_ac;
  short local_a0;
  short local_9e;
  short local_90;
  uint local_30;
  
  local_30 = DAT_404bd274;
  iVar6 = *(int *)(param_1 + 0x144);
  iVar21 = *(int *)(param_1 + 0x1b0);
  if (*(int *)(param_1 + 0x94) <= *(int *)(param_1 + 0x9c)) {
    do {
      if (((*(undefined4 **)(param_1 + 0x1b8))[5] != 0) ||
         ((*(int *)(param_1 + 0x94) == *(int *)(param_1 + 0x9c) &&
          (*(int *)(param_1 + 0xa0) + (uint)(*(int *)(param_1 + 0x194) == 0) <
           *(uint *)(param_1 + 0x98))))) break;
      iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x1b8))(param_1);
      if (iVar2 == 0) {
        FUN_404a438c(local_30);
        return 0;
      }
    } while (*(int *)(param_1 + 0x94) <= *(int *)(param_1 + 0x9c));
  }
  iVar2 = *(int *)(param_1 + 0xdc);
  local_dc = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    puVar24 = (undefined4 *)(iVar21 + 0x48);
    local_d4 = 0;
    local_f8 = param_2;
    do {
      if (*(int *)(iVar2 + 0x30) != 0) {
        uVar14 = *(uint *)(param_1 + 0xa0);
        uVar11 = *(uint *)(iVar2 + 0xc);
        if (uVar14 < iVar6 - 1U) {
          uVar5 = uVar11 << 1;
          bVar23 = false;
          local_100 = uVar11;
        }
        else {
          uVar5 = *(uint *)(iVar2 + 0x20) % uVar11;
          if (uVar11 == 0) {
            trap(0x1c00);
          }
          if (uVar5 == 0) {
            uVar5 = uVar11;
          }
          bVar23 = true;
          local_100 = uVar5;
        }
        if (uVar14 == 0) {
          iVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x20))(param_1,*puVar24,0,uVar5,0);
        }
        else {
          iVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x20))
                            (param_1,*puVar24,(uVar14 - 1) * uVar11,uVar11 + uVar5,0);
          iVar3 = *(int *)(iVar2 + 0xc) * 4 + iVar3;
        }
        puVar19 = *(ushort **)(iVar2 + 0x4c);
        iVar22 = *(int *)(iVar21 + 0x70) + local_d4;
        uVar12 = (uint)puVar19[1];
        uVar11 = (uint)puVar19[8];
        uVar5 = (uint)*puVar19;
        uVar15 = (uint)puVar19[0x10];
        uVar17 = (uint)puVar19[9];
        uVar9 = (uint)puVar19[2];
        pcVar7 = *(code **)((int)puVar24 + (*(int *)(param_1 + 0x1c4) - iVar21) + -0x44);
        local_108 = *local_f8;
        local_c8 = 0;
        if (0 < (int)local_100) {
          do {
            puVar10 = (undefined4 *)(local_c8 * 4 + iVar3);
            psVar27 = (short *)*puVar10;
            if ((uVar14 != 0) || (local_114 = psVar27, local_c8 != 0)) {
              local_114 = (short *)puVar10[-1];
            }
            if ((!bVar23) || (local_fc = psVar27, local_c8 != local_100 - 1)) {
              local_fc = (short *)puVar10[1];
            }
            local_10c = (int)*local_fc;
            uVar8 = *(int *)(iVar2 + 0x1c) - 1;
            local_104 = 0;
            local_110 = 0;
            iVar31 = (int)*local_114;
            iVar16 = local_10c;
            iVar13 = (int)*psVar27;
            iVar25 = (int)*psVar27;
            iVar28 = (int)*local_114;
            do {
              iVar1 = local_10c;
              local_fc = local_fc + 0x40;
              local_114 = local_114 + 0x40;
              FUN_404b2ff4(psVar27,auStack_b0,1);
              iVar26 = iVar25;
              iVar29 = iVar28;
              if (local_110 < uVar8) {
                local_10c = (int)*local_fc;
                iVar26 = (int)psVar27[0x40];
                iVar29 = (int)*local_114;
              }
              uVar20 = *(uint *)(iVar22 + 4);
              if ((uVar20 != 0) && (local_ae == 0)) {
                iVar30 = (iVar13 - iVar26) * uVar5;
                iVar18 = iVar30 * 0x24;
                if (iVar18 < 0) {
                  iVar18 = uVar12 * 0x80 + iVar30 * -0x24;
                  iVar30 = iVar18 / (int)(uVar12 << 8);
                  if (uVar12 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar12 << 8 == -1) && (iVar18 == -0x80000000)) {
                    trap(0x1800);
                  }
                  if ((0 < (int)uVar20) && (iVar18 = 1 << (uVar20 & 0x1f), iVar18 <= iVar30)) {
                    iVar30 = iVar18 + -1;
                  }
                  iVar30 = -iVar30;
                }
                else {
                  iVar18 = uVar12 * 0x80 + iVar18;
                  iVar30 = iVar18 / (int)(uVar12 << 8);
                  if (uVar12 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar12 << 8 == -1) && (iVar18 == -0x80000000)) {
                    trap(0x1800);
                  }
                  if ((0 < (int)uVar20) && (iVar18 = 1 << (uVar20 & 0x1f), iVar18 <= iVar30)) {
                    iVar30 = iVar18 + -1;
                  }
                }
                local_ae = (short)iVar30;
              }
              uVar20 = *(uint *)(iVar22 + 8);
              if ((uVar20 != 0) && (local_a0 == 0)) {
                iVar30 = (iVar28 - iVar1) * uVar5;
                iVar18 = iVar30 * 0x24;
                if (iVar18 < 0) {
                  iVar18 = uVar11 * 0x80 + iVar30 * -0x24;
                  iVar30 = iVar18 / (int)(uVar11 << 8);
                  if (uVar11 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar11 << 8 == -1) && (iVar18 == -0x80000000)) {
                    trap(0x1800);
                  }
                  if ((0 < (int)uVar20) && (iVar18 = 1 << (uVar20 & 0x1f), iVar18 <= iVar30)) {
                    iVar30 = iVar18 + -1;
                  }
                  iVar30 = -iVar30;
                }
                else {
                  iVar18 = uVar11 * 0x80 + iVar18;
                  iVar30 = iVar18 / (int)(uVar11 << 8);
                  if (uVar11 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar11 << 8 == -1) && (iVar18 == -0x80000000)) {
                    trap(0x1800);
                  }
                  if ((0 < (int)uVar20) && (iVar18 = 1 << (uVar20 & 0x1f), iVar18 <= iVar30)) {
                    iVar30 = iVar18 + -1;
                  }
                }
                local_a0 = (short)iVar30;
              }
              uVar20 = *(uint *)(iVar22 + 0xc);
              if ((uVar20 != 0) && (local_90 == 0)) {
                iVar30 = (iVar1 + iVar25 * -2 + iVar28) * uVar5;
                iVar18 = iVar30 * 9;
                if (iVar18 < 0) {
                  iVar18 = uVar15 * 0x80 + iVar30 * -9;
                  iVar30 = iVar18 / (int)(uVar15 << 8);
                  if (uVar15 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar15 << 8 == -1) && (iVar18 == -0x80000000)) {
                    trap(0x1800);
                  }
                  if ((0 < (int)uVar20) && (iVar18 = 1 << (uVar20 & 0x1f), iVar18 <= iVar30)) {
                    iVar30 = iVar18 + -1;
                  }
                  iVar30 = -iVar30;
                }
                else {
                  iVar18 = uVar15 * 0x80 + iVar18;
                  iVar30 = iVar18 / (int)(uVar15 << 8);
                  if (uVar15 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar15 << 8 == -1) && (iVar18 == -0x80000000)) {
                    trap(0x1800);
                  }
                  if ((0 < (int)uVar20) && (iVar18 = 1 << (uVar20 & 0x1f), iVar18 <= iVar30)) {
                    iVar30 = iVar18 + -1;
                  }
                }
                local_90 = (short)iVar30;
              }
              uVar20 = *(uint *)(iVar22 + 0x10);
              if ((uVar20 != 0) && (local_9e == 0)) {
                iVar31 = (((local_10c - iVar16) - iVar29) + iVar31) * uVar5;
                iVar16 = iVar31 * 5;
                if (iVar16 < 0) {
                  iVar16 = uVar17 * 0x80 + iVar31 * -5;
                  iVar31 = iVar16 / (int)(uVar17 << 8);
                  if (uVar17 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar17 << 8 == -1) && (iVar16 == -0x80000000)) {
                    trap(0x1800);
                  }
                  if ((0 < (int)uVar20) && (iVar16 = 1 << (uVar20 & 0x1f), iVar16 <= iVar31)) {
                    iVar31 = iVar16 + -1;
                  }
                  iVar31 = -iVar31;
                }
                else {
                  iVar16 = uVar17 * 0x80 + iVar16;
                  iVar31 = iVar16 / (int)(uVar17 << 8);
                  if (uVar17 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar17 << 8 == -1) && (iVar16 == -0x80000000)) {
                    trap(0x1800);
                  }
                  if ((0 < (int)uVar20) && (iVar16 = 1 << (uVar20 & 0x1f), iVar16 <= iVar31)) {
                    iVar31 = iVar16 + -1;
                  }
                }
                local_9e = (short)iVar31;
              }
              uVar20 = *(uint *)(iVar22 + 0x14);
              if ((uVar20 != 0) && (local_ac == 0)) {
                iVar31 = (iVar26 + iVar25 * -2 + iVar13) * uVar5;
                iVar16 = iVar31 * 9;
                iVar13 = uVar9 << 8;
                if (iVar16 < 0) {
                  iVar16 = uVar9 * 0x80 + iVar31 * -9;
                  iVar31 = iVar16 / iVar13;
                  if (uVar9 == 0) {
                    trap(0x1c00);
                  }
                  if ((iVar13 == -1) && (iVar16 == -0x80000000)) {
                    trap(0x1800);
                  }
                  if ((0 < (int)uVar20) && (iVar16 = 1 << (uVar20 & 0x1f), iVar16 <= iVar31)) {
                    iVar31 = iVar16 + -1;
                  }
                  iVar31 = -iVar31;
                }
                else {
                  iVar16 = uVar9 * 0x80 + iVar16;
                  iVar31 = iVar16 / iVar13;
                  if (uVar9 == 0) {
                    trap(0x1c00);
                  }
                  if ((iVar13 == -1) && (iVar16 == -0x80000000)) {
                    trap(0x1800);
                  }
                  if ((0 < (int)uVar20) && (iVar16 = 1 << (uVar20 & 0x1f), iVar16 <= iVar31)) {
                    iVar31 = iVar16 + -1;
                  }
                }
                local_ac = (short)iVar31;
              }
              (*pcVar7)(param_1,iVar2,auStack_b0,local_108,local_104);
              psVar27 = psVar27 + 0x40;
              local_104 = *(int *)(iVar2 + 0x24) + local_104;
              local_110 = local_110 + 1;
              iVar31 = iVar28;
              iVar16 = iVar1;
              iVar13 = iVar25;
              iVar25 = iVar26;
              iVar28 = iVar29;
            } while (local_110 <= uVar8);
            local_108 = *(int *)(iVar2 + 0x24) * 4 + local_108;
            local_c8 = local_c8 + 1;
          } while (local_c8 < (int)local_100);
        }
      }
      local_f8 = local_f8 + 1;
      local_dc = local_dc + 1;
      local_d4 = local_d4 + 0x18;
      puVar24 = puVar24 + 1;
      iVar2 = iVar2 + 0x54;
    } while (local_dc < *(int *)(param_1 + 0x24));
  }
  uVar11 = *(int *)(param_1 + 0xa0) + 1;
  *(uint *)(param_1 + 0xa0) = uVar11;
  if (uVar11 < *(uint *)(param_1 + 0x144)) {
    FUN_404a438c(local_30);
    uVar4 = 3;
  }
  else {
    FUN_404a438c(local_30);
    uVar4 = 4;
  }
  return uVar4;
}



/* 404b4e34 FUN_404b4e34 */

/* Boundary evidence: original MIPS .pdata 404b4e34..404b4ea7. Semantic name remains unreviewed. */

void FUN_404b4e34(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1b0);
  if (*(int *)(iVar2 + 0x10) != 0) {
    if ((*(int *)(param_1 + 0x50) == 0) || (iVar1 = FUN_404b430c(param_1), iVar1 == 0)) {
      *(code **)(iVar2 + 0xc) = FUN_404b40d0;
    }
    else {
      *(code **)(iVar2 + 0xc) = FUN_404b44b0;
    }
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return;
}



/* 404b4ea8 FUN_404b4ea8 */

/* Boundary evidence: original MIPS .pdata 404b4ea8..404b506f. Semantic name remains unreviewed. */

void FUN_404b4ea8(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x74);
  *(undefined4 **)(param_1 + 0x1b0) = puVar1;
  *puVar1 = FUN_404b3af4;
  puVar1[2] = FUN_404b4e34;
  puVar1[0x1c] = 0;
  if (param_2 == 0) {
    iVar8 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,0x500);
    puVar1[10] = iVar8 + 0x100;
    puVar1[9] = iVar8 + 0x80;
    puVar1[0xf] = iVar8 + 0x380;
    puVar1[0xd] = iVar8 + 0x280;
    puVar1[0xb] = iVar8 + 0x180;
    puVar1[0xc] = iVar8 + 0x200;
    puVar1[0xe] = iVar8 + 0x300;
    puVar1[8] = iVar8;
    puVar1[0x10] = iVar8 + 0x400;
    puVar1[0x11] = iVar8 + 0x480;
    puVar1[1] = FUN_404a3c98;
    puVar1[3] = FUN_404b3b10;
    puVar1[4] = 0;
  }
  else {
    iVar8 = 0;
    if (0 < *(int *)(param_1 + 0x24)) {
      piVar7 = (int *)(*(int *)(param_1 + 0xdc) + 0x20);
      puVar9 = puVar1 + 0x12;
      do {
        iVar4 = piVar7[-5];
        iVar6 = iVar4;
        if (*(int *)(param_1 + 0xe0) != 0) {
          iVar6 = iVar4 * 3;
        }
        iVar5 = *(int *)(param_1 + 4);
        iVar4 = FUN_404b2f44(*piVar7,iVar4);
        iVar2 = FUN_404b2f44(piVar7[-1],piVar7[-6]);
        uVar3 = (**(code **)(iVar5 + 0x14))(param_1,1,1,iVar2,iVar4,iVar6);
        iVar8 = iVar8 + 1;
        piVar7 = piVar7 + 0x15;
        *puVar9 = uVar3;
        puVar9 = puVar9 + 1;
      } while (iVar8 < *(int *)(param_1 + 0x24));
    }
    puVar1[3] = FUN_404b40d0;
    puVar1[1] = FUN_404b3e44;
    puVar1[4] = puVar1 + 0x12;
  }
  return;
}



/* 404b5070 FUN_404b5070 */

/* Boundary evidence: original MIPS .pdata 404b5070..404b5473. Semantic name remains unreviewed. */

void FUN_404b5070(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  int iVar7;
  undefined1 *puVar8;
  int *piVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  int aiStack_53c [259];
  char local_130 [260];
  uint local_2c;
  
  local_2c = DAT_404bd274;
  iVar12 = 0;
  if ((param_3 < 0) || (3 < param_3)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x32;
    *(int *)(*param_1 + 0x18) = param_3;
    (**(code **)*param_1)(param_1);
  }
  if (param_2 == 0) {
    iVar13 = param_1[param_3 + 0x32];
  }
  else {
    iVar13 = param_1[param_3 + 0x2e];
  }
  if (iVar13 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x32;
    *(int *)(*param_1 + 0x18) = param_3;
    (**(code **)*param_1)(param_1);
  }
  if (*param_4 == 0) {
    iVar1 = (**(code **)param_1[1])(param_1,1,0x590);
    *param_4 = iVar1;
  }
  piVar14 = (int *)*param_4;
  iVar1 = 1;
  piVar14[0x23] = iVar13;
  do {
    uVar4 = (uint)*(byte *)(iVar1 + iVar13);
    if (((0x100 < iVar12) || (0x100 < uVar4)) || (0x100 < (int)(uVar4 + iVar12))) {
      *(undefined4 *)(*param_1 + 0x14) = 8;
      (**(code **)*param_1)(param_1);
    }
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      local_130[iVar12] = (char)iVar1;
      iVar12 = iVar12 + 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x11);
  local_130[iVar12] = '\0';
  uVar4 = (uint)local_130[0];
  iVar1 = 0;
  iVar11 = 0;
  if (uVar4 != 0) {
    pcVar5 = local_130;
    do {
      if ((int)*pcVar5 == uVar4) {
        piVar6 = aiStack_53c + iVar11 + 1;
        iVar3 = iVar11;
        do {
          iVar11 = iVar3 + 1;
          iVar2 = iVar3 + 1;
          *piVar6 = iVar1;
          piVar6 = piVar6 + 1;
          iVar1 = iVar1 + 1;
          iVar3 = iVar11;
        } while ((int)local_130[iVar2] == uVar4);
      }
      if (1 << (uVar4 & 0x1f) <= iVar1) {
        *(undefined4 *)(*param_1 + 0x14) = 8;
        (**(code **)*param_1)(param_1);
      }
      pcVar5 = local_130 + iVar11;
      iVar1 = iVar1 << 1;
      uVar4 = uVar4 + 1;
    } while (*pcVar5 != '\0');
  }
  iVar11 = 0;
  iVar1 = 1;
  piVar6 = piVar14;
  do {
    piVar9 = piVar6 + 1;
    if (*(byte *)(iVar1 + iVar13) == 0) {
      *piVar9 = -1;
    }
    else {
      piVar6[0x13] = iVar11 - aiStack_53c[iVar11 + 1];
      iVar11 = (uint)*(byte *)(iVar1 + iVar13) + iVar11;
      *piVar9 = aiStack_53c[iVar11];
    }
    iVar1 = iVar1 + 1;
    piVar6 = piVar9;
  } while (iVar1 < 0x11);
  piVar14[0x11] = 0xfffff;
  memset(piVar14 + 0x24,0,0x400);
  iVar1 = 0;
  iVar11 = 1;
  uVar4 = 7;
  do {
    iVar3 = 1;
    if (*(byte *)(iVar11 + iVar13) != 0) {
      iVar2 = 1 << (uVar4 & 0x1f);
      puVar10 = (undefined1 *)(iVar13 + iVar1 + 0x11);
      piVar6 = aiStack_53c + iVar1 + 1;
      do {
        iVar7 = *piVar6 << (uVar4 & 0x1f);
        if (0 < iVar2) {
          puVar8 = (undefined1 *)((int)piVar14 + iVar7 + 0x490);
          piVar9 = piVar14 + iVar7 + 0x24;
          iVar7 = iVar2;
          do {
            *piVar9 = iVar11;
            piVar9 = piVar9 + 1;
            *puVar8 = *puVar10;
            iVar7 = iVar7 + -1;
            puVar8 = puVar8 + 1;
          } while (0 < iVar7);
        }
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + 1;
        piVar6 = piVar6 + 1;
        puVar10 = puVar10 + 1;
      } while (iVar3 <= (int)(uint)*(byte *)(iVar11 + iVar13));
    }
    uVar4 = uVar4 - 1;
    iVar11 = iVar11 + 1;
  } while (-1 < (int)uVar4);
  if ((param_2 != 0) && (iVar1 = 0, 0 < iVar12)) {
    do {
      if (0xf < *(byte *)(iVar13 + 0x11 + iVar1)) {
        *(undefined4 *)(*param_1 + 0x14) = 8;
        (**(code **)*param_1)(param_1);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar12);
  }
  FUN_404a438c(local_2c);
  return;
}



/* 404b5474 FUN_404b5474 */

/* Boundary evidence: original MIPS .pdata 404b5474..404b5627. Semantic name remains unreviewed. */

undefined4 FUN_404b5474(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  
  piVar3 = (int *)param_1[4];
  pbVar4 = (byte *)*param_1;
  iVar2 = param_1[1];
  if (piVar3[0x69] == 0) {
    for (; param_3 < 0x19; param_3 = param_3 + 8) {
      if (iVar2 == 0) {
        iVar2 = (**(code **)(piVar3[6] + 0xc))(piVar3);
        if (iVar2 == 0) {
          return 0;
        }
        pbVar4 = *(byte **)piVar3[6];
        iVar2 = ((undefined4 *)piVar3[6])[1];
      }
      uVar1 = (uint)*pbVar4;
      iVar2 = iVar2 + -1;
      pbVar4 = pbVar4 + 1;
      if (uVar1 == 0xff) {
        do {
          if (iVar2 == 0) {
            iVar2 = (**(code **)(piVar3[6] + 0xc))(piVar3);
            if (iVar2 == 0) {
              return 0;
            }
            pbVar4 = *(byte **)piVar3[6];
            iVar2 = ((undefined4 *)piVar3[6])[1];
          }
          uVar1 = (uint)*pbVar4;
          iVar2 = iVar2 + -1;
          pbVar4 = pbVar4 + 1;
        } while (uVar1 == 0xff);
        if (uVar1 != 0) {
          piVar3[0x69] = uVar1;
          goto LAB_404b5590;
        }
        uVar1 = 0xff;
      }
      param_2 = param_2 << 8 | uVar1;
    }
  }
  else {
LAB_404b5590:
    if (param_3 < param_4) {
      if (*(int *)(piVar3[0x70] + 8) == 0) {
        *(undefined4 *)(*piVar3 + 0x14) = 0x75;
        (**(code **)(*piVar3 + 4))(piVar3,0xffffffff);
        *(undefined4 *)(piVar3[0x70] + 8) = 1;
      }
      param_2 = param_2 << (0x19U - param_3 & 0x1f);
      param_3 = 0x19;
    }
  }
  *param_1 = pbVar4;
  param_1[1] = iVar2;
  param_1[2] = param_2;
  param_1[3] = param_3;
  return 1;
}



/* 404b5628 FUN_404b5628 */

/* Boundary evidence: original MIPS .pdata 404b5628..404b577b. Semantic name remains unreviewed. */

uint FUN_404b5628(undefined4 *param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  if (param_3 < (int)param_5) {
    iVar1 = FUN_404b5474(param_1,param_2,param_3,param_5);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    param_2 = param_1[2];
    param_3 = param_1[3];
  }
  uVar2 = param_3 - param_5;
  uVar3 = (int)param_2 >> (uVar2 & 0x1f) & (1 << (param_5 & 0x1f)) - 1U;
  piVar4 = (int *)(param_5 * 4 + param_4);
  if (*piVar4 < (int)uVar3) {
    do {
      if ((int)uVar2 < 1) {
        iVar1 = FUN_404b5474(param_1,param_2,uVar2,1);
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        param_2 = param_1[2];
        uVar2 = param_1[3];
      }
      uVar2 = uVar2 - 1;
      piVar4 = piVar4 + 1;
      uVar3 = (int)param_2 >> (uVar2 & 0x1f) & 1U | uVar3 << 1;
      param_5 = param_5 + 1;
    } while (*piVar4 < (int)uVar3);
  }
  param_1[2] = param_2;
  param_1[3] = uVar2;
  if ((int)param_5 < 0x11) {
    uVar2 = (uint)*(byte *)(*(int *)((param_5 + 0x12) * 4 + param_4) + *(int *)(param_4 + 0x8c) +
                            uVar3 + 0x11);
  }
  else {
    *(undefined4 *)(*(int *)param_1[4] + 0x14) = 0x76;
    (**(code **)(*(int *)param_1[4] + 4))((int *)param_1[4],0xffffffff);
    uVar2 = 0;
  }
  return uVar2;
}



/* 404b577c FUN_404b577c */

/* Boundary evidence: original MIPS .pdata 404b577c..404b5843. Semantic name remains unreviewed. */

undefined4 FUN_404b577c(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1c0);
  iVar1 = *(int *)(iVar3 + 0x10);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 7;
  }
  *(int *)(*(int *)(param_1 + 0x1bc) + 0x18) =
       (iVar1 >> 3) + *(int *)(*(int *)(param_1 + 0x1bc) + 0x18);
  *(undefined4 *)(iVar3 + 0x10) = 0;
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1bc) + 8))(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x14c)) {
    puVar2 = (undefined4 *)(iVar3 + 0x14);
    do {
      *puVar2 = 0;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x14c));
  }
  *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(param_1 + 0x118);
  if (*(int *)(param_1 + 0x1a4) == 0) {
    *(undefined4 *)(iVar3 + 8) = 0;
  }
  return 1;
}



/* 404b5844 FUN_404b5844 */

/* Boundary evidence: original MIPS .pdata 404b5844..404b5daf. Semantic name remains unreviewed. */

undefined4 FUN_404b5844(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  undefined2 *puVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  undefined4 *local_60;
  int local_5c;
  int local_50 [4];
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  
  iVar11 = *(int *)(param_1 + 0x1c0);
  if (((*(int *)(param_1 + 0x118) == 0) || (*(int *)(iVar11 + 0x24) != 0)) ||
     (iVar1 = FUN_404b577c(param_1), iVar1 != 0)) {
    uVar7 = 1;
    if (*(int *)(iVar11 + 8) == 0) {
      local_40 = **(undefined4 **)(param_1 + 0x18);
      local_3c = (*(undefined4 **)(param_1 + 0x18))[1];
      local_50[0] = *(int *)(iVar11 + 0x14);
      local_50[1] = *(undefined4 *)(iVar11 + 0x18);
      local_50[2] = *(undefined4 *)(iVar11 + 0x1c);
      local_50[3] = *(undefined4 *)(iVar11 + 0x20);
      uVar5 = *(uint *)(iVar11 + 0xc);
      uVar4 = *(uint *)(iVar11 + 0x10);
      local_30 = param_1;
      local_5c = 0;
      if (0 < *(int *)(param_1 + 0x168)) {
        piVar6 = (int *)(param_1 + 0x16c);
        piVar10 = (int *)(iVar11 + 0x70);
        local_60 = param_2;
        do {
          puVar9 = (undefined2 *)*local_60;
          iVar1 = piVar10[-10];
          iVar8 = *piVar10;
          if ((int)uVar4 < 8) {
            iVar2 = FUN_404b5474(&local_40,uVar5,uVar4,0);
            if (iVar2 == 0) goto LAB_404b58a4;
            uVar4 = local_34;
            uVar5 = local_38;
            if (7 < (int)local_34) goto LAB_404b5964;
            uVar3 = 1;
LAB_404b59a0:
            uVar3 = FUN_404b5628(&local_40,uVar5,uVar4,iVar1,uVar3);
            uVar4 = local_34;
            uVar5 = local_38;
            if ((int)uVar3 < 0) goto LAB_404b58a4;
          }
          else {
LAB_404b5964:
            uVar3 = (int)uVar5 >> (uVar4 - 8 & 0x1f) & 0xff;
            iVar2 = *(int *)((uVar3 + 0x24) * 4 + iVar1);
            if (iVar2 == 0) {
              uVar3 = 9;
              goto LAB_404b59a0;
            }
            uVar3 = (uint)*(byte *)(uVar3 + iVar1 + 0x490);
            uVar4 = uVar4 - iVar2;
          }
          uVar12 = 0;
          if (uVar3 != 0) {
            if (((int)uVar4 < (int)uVar3) &&
               (iVar1 = FUN_404b5474(&local_40,uVar5,uVar4,uVar3), uVar4 = local_34,
               uVar5 = local_38, iVar1 == 0)) goto LAB_404b58a4;
            uVar4 = uVar4 - uVar3;
            uVar12 = (1 << (uVar3 & 0x1f)) - 1U & (int)uVar5 >> (uVar4 & 0x1f);
            if ((int)uVar12 < *(int *)(&LAB_404869dc + uVar3 * 4)) {
              uVar12 = *(int *)(&DAT_40486a1c + uVar3 * 4) + uVar12;
            }
          }
          if (piVar10[10] != 0) {
            iVar1 = local_50[*piVar6] + uVar12;
            local_50[*piVar6] = iVar1;
            *puVar9 = (short)iVar1;
          }
          iVar1 = 1;
          if (piVar10[0x14] == 0) {
            do {
              if ((int)uVar4 < 8) {
                iVar2 = FUN_404b5474(&local_40,uVar5,uVar4,0);
                if (iVar2 == 0) goto LAB_404b58a4;
                uVar4 = local_34;
                uVar5 = local_38;
                if (7 < (int)local_34) goto LAB_404b5c2c;
                uVar3 = 1;
LAB_404b5c68:
                uVar3 = FUN_404b5628(&local_40,uVar5,uVar4,iVar8,uVar3);
                uVar4 = local_34;
                uVar5 = local_38;
                if ((int)uVar3 < 0) goto LAB_404b58a4;
              }
              else {
LAB_404b5c2c:
                uVar3 = (int)uVar5 >> (uVar4 - 8 & 0x1f) & 0xff;
                iVar2 = *(int *)((uVar3 + 0x24) * 4 + iVar8);
                if (iVar2 == 0) {
                  uVar3 = 9;
                  goto LAB_404b5c68;
                }
                uVar3 = (uint)*(byte *)(uVar3 + iVar8 + 0x490);
                uVar4 = uVar4 - iVar2;
              }
              uVar12 = uVar3 & 0xf;
              if (uVar12 == 0) {
                if ((int)uVar3 >> 4 != 0xf) break;
                iVar1 = iVar1 + 0xf;
              }
              else {
                iVar1 = iVar1 + ((int)uVar3 >> 4);
                if (((int)uVar4 < (int)uVar12) &&
                   (iVar2 = FUN_404b5474(&local_40,uVar5,uVar4,uVar12), uVar4 = local_34,
                   uVar5 = local_38, iVar2 == 0)) goto LAB_404b58a4;
                uVar4 = uVar4 - uVar12;
              }
              iVar1 = iVar1 + 1;
            } while (iVar1 < 0x40);
          }
          else {
            do {
              if ((int)uVar4 < 8) {
                iVar2 = FUN_404b5474(&local_40,uVar5,uVar4,0);
                if (iVar2 == 0) goto LAB_404b58a4;
                uVar4 = local_34;
                uVar5 = local_38;
                if (7 < (int)local_34) goto LAB_404b5ac0;
                uVar3 = 1;
LAB_404b5afc:
                uVar3 = FUN_404b5628(&local_40,uVar5,uVar4,iVar8,uVar3);
                uVar4 = local_34;
                uVar5 = local_38;
                if ((int)uVar3 < 0) goto LAB_404b58a4;
              }
              else {
LAB_404b5ac0:
                uVar3 = (int)uVar5 >> (uVar4 - 8 & 0x1f) & 0xff;
                iVar2 = *(int *)((uVar3 + 0x24) * 4 + iVar8);
                if (iVar2 == 0) {
                  uVar3 = 9;
                  goto LAB_404b5afc;
                }
                uVar3 = (uint)*(byte *)(uVar3 + iVar8 + 0x490);
                uVar4 = uVar4 - iVar2;
              }
              uVar12 = uVar3 & 0xf;
              if (uVar12 == 0) {
                if ((int)uVar3 >> 4 != 0xf) break;
                iVar1 = iVar1 + 0xf;
              }
              else {
                iVar1 = iVar1 + ((int)uVar3 >> 4);
                if (((int)uVar4 < (int)uVar12) &&
                   (iVar2 = FUN_404b5474(&local_40,uVar5,uVar4,uVar12), uVar4 = local_34,
                   uVar5 = local_38, iVar2 == 0)) goto LAB_404b58a4;
                uVar4 = uVar4 - uVar12;
                uVar3 = (1 << uVar12) - 1U & (int)uVar5 >> (uVar4 & 0x1f);
                if ((int)uVar3 < *(int *)(&LAB_404869dc + uVar12 * 4)) {
                  uVar3 = *(int *)(&DAT_40486a1c + uVar12 * 4) + uVar3;
                }
                puVar9[(&DAT_4048689c)[iVar1]] = (short)uVar3;
              }
              iVar1 = iVar1 + 1;
            } while (iVar1 < 0x40);
          }
          local_60 = local_60 + 1;
          local_5c = local_5c + 1;
          piVar6 = piVar6 + 1;
          piVar10 = piVar10 + 1;
        } while (local_5c < *(int *)(param_1 + 0x168));
      }
      **(undefined4 **)(param_1 + 0x18) = local_40;
      *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = local_3c;
      *(uint *)(iVar11 + 0xc) = uVar5;
      *(uint *)(iVar11 + 0x10) = uVar4;
      *(int *)(iVar11 + 0x14) = local_50[0];
      *(int *)(iVar11 + 0x18) = local_50[1];
      *(int *)(iVar11 + 0x1c) = local_50[2];
      *(int *)(iVar11 + 0x20) = local_50[3];
    }
    *(int *)(iVar11 + 0x24) = *(int *)(iVar11 + 0x24) + -1;
  }
  else {
LAB_404b58a4:
    uVar7 = 0;
  }
  return uVar7;
}



/* 404b5db0 FUN_404b5db0 */

/* Boundary evidence: original MIPS .pdata 404b5db0..404b5f7f. Semantic name remains unreviewed. */

void FUN_404b5db0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar4 = param_1[0x70];
  if ((((param_1[0x65] != 0) || (param_1[0x66] != 0x3f)) || (param_1[0x67] != 0)) ||
     (param_1[0x68] != 0)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x7a;
    (**(code **)(*param_1 + 4))(param_1,0xffffffff);
  }
  iVar5 = 0;
  if (0 < param_1[0x53]) {
    puVar6 = (undefined4 *)(iVar4 + 0x14);
    piVar1 = param_1 + 0x54;
    do {
      iVar2 = *(int *)(*piVar1 + 0x14);
      iVar3 = *(int *)(*piVar1 + 0x18);
      FUN_404b5070(param_1,1,iVar2,(int *)((iVar2 + 10) * 4 + iVar4));
      FUN_404b5070(param_1,0,iVar3,(int *)((iVar3 + 0xe) * 4 + iVar4));
      iVar5 = iVar5 + 1;
      piVar1 = piVar1 + 1;
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    } while (iVar5 < param_1[0x53]);
  }
  iVar5 = 0;
  if (0 < param_1[0x5a]) {
    puVar6 = (undefined4 *)(iVar4 + 0x70);
    piVar1 = param_1 + 0x5b;
    do {
      iVar2 = param_1[*piVar1 + 0x54];
      puVar6[-10] = *(undefined4 *)((*(int *)(iVar2 + 0x14) + 10) * 4 + iVar4);
      *puVar6 = *(undefined4 *)((*(int *)(iVar2 + 0x18) + 0xe) * 4 + iVar4);
      if (*(int *)(iVar2 + 0x30) == 0) {
        puVar6[0x14] = 0;
        puVar6[10] = 0;
      }
      else {
        puVar6[10] = 1;
        puVar6[0x14] = (uint)(1 < *(int *)(iVar2 + 0x24));
      }
      iVar5 = iVar5 + 1;
      piVar1 = piVar1 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar5 < param_1[0x5a]);
  }
  *(undefined4 *)(iVar4 + 0x10) = 0;
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(undefined4 *)(iVar4 + 8) = 0;
  *(int *)(iVar4 + 0x24) = param_1[0x46];
  return;
}



/* 404b5f80 FUN_404b5f80 */

/* Boundary evidence: original MIPS .pdata 404b5f80..404b5ff3. Semantic name remains unreviewed. */

void FUN_404b5f80(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0xe8);
  *(undefined4 **)(param_1 + 0x1c0) = puVar1;
  *puVar1 = FUN_404b5db0;
  puVar1[1] = FUN_404b5844;
  puVar1[0xe] = 0;
  puVar1[10] = 0;
  puVar1[0xf] = 0;
  puVar1[0xb] = 0;
  puVar1[0x10] = 0;
  puVar1[0xc] = 0;
  puVar1[0x11] = 0;
  puVar1[0xd] = 0;
  return;
}



/* 404b5ff4 FUN_404b5ff4 */

/* Boundary evidence: original MIPS .pdata 404b5ff4..404b60bf. Semantic name remains unreviewed. */

undefined4 FUN_404b5ff4(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1c0);
  iVar1 = *(int *)(iVar3 + 0x10);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 7;
  }
  *(int *)(*(int *)(param_1 + 0x1bc) + 0x18) =
       (iVar1 >> 3) + *(int *)(*(int *)(param_1 + 0x1bc) + 0x18);
  *(undefined4 *)(iVar3 + 0x10) = 0;
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1bc) + 8))(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x14c)) {
    puVar2 = (undefined4 *)(iVar3 + 0x18);
    do {
      *puVar2 = 0;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x14c));
  }
  *(undefined4 *)(iVar3 + 0x14) = 0;
  *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(param_1 + 0x118);
  if (*(int *)(param_1 + 0x1a4) == 0) {
    *(undefined4 *)(iVar3 + 8) = 0;
  }
  return 1;
}



/* 404b60c0 FUN_404b60c0 */

/* Boundary evidence: original MIPS .pdata 404b60c0..404b63b3. Semantic name remains unreviewed. */

undefined4 FUN_404b60c0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined2 *puVar11;
  uint uVar12;
  uint uVar13;
  undefined4 local_58;
  undefined4 local_54;
  uint local_50;
  uint local_4c;
  int local_48;
  undefined4 local_40;
  int local_3c [5];
  
  uVar4 = *(uint *)(param_1 + 0x1a0);
  iVar8 = *(int *)(param_1 + 0x1c0);
  if (((*(int *)(param_1 + 0x118) == 0) || (*(int *)(iVar8 + 0x28) != 0)) ||
     (iVar1 = FUN_404b5ff4(param_1), iVar1 != 0)) {
    if (*(int *)(iVar8 + 8) == 0) {
      local_58 = **(undefined4 **)(param_1 + 0x18);
      iVar1 = 0;
      local_54 = (*(undefined4 **)(param_1 + 0x18))[1];
      local_40 = *(undefined4 *)(iVar8 + 0x14);
      local_3c[0] = *(int *)(iVar8 + 0x18);
      local_3c[1] = *(undefined4 *)(iVar8 + 0x1c);
      local_3c[2] = *(undefined4 *)(iVar8 + 0x20);
      local_3c[3] = *(undefined4 *)(iVar8 + 0x24);
      uVar13 = *(uint *)(iVar8 + 0xc);
      uVar12 = *(uint *)(iVar8 + 0x10);
      if (0 < *(int *)(param_1 + 0x168)) {
        piVar10 = (int *)(param_1 + 0x16c);
        local_48 = param_1;
        do {
          iVar9 = *piVar10;
          puVar11 = (undefined2 *)*param_2;
          iVar7 = *(int *)((*(int *)(*(int *)((iVar9 + 0x54) * 4 + param_1) + 0x14) + 0xb) * 4 +
                          iVar8);
          if ((int)uVar12 < 8) {
            iVar3 = FUN_404b5474(&local_58,uVar13,uVar12,0);
            if (iVar3 == 0) goto LAB_404b6124;
            uVar12 = local_4c;
            uVar13 = local_50;
            if (7 < (int)local_4c) goto LAB_404b6204;
            uVar5 = 1;
LAB_404b6240:
            uVar5 = FUN_404b5628(&local_58,uVar13,uVar12,iVar7,uVar5);
            uVar12 = local_4c;
            uVar13 = local_50;
            if ((int)uVar5 < 0) goto LAB_404b6124;
          }
          else {
LAB_404b6204:
            uVar5 = (int)uVar13 >> (uVar12 - 8 & 0x1f) & 0xff;
            iVar3 = *(int *)((uVar5 + 0x24) * 4 + iVar7);
            if (iVar3 == 0) {
              uVar5 = 9;
              goto LAB_404b6240;
            }
            uVar5 = (uint)*(byte *)(uVar5 + iVar7 + 0x490);
            uVar12 = uVar12 - iVar3;
          }
          uVar6 = 0;
          if (uVar5 != 0) {
            if (((int)uVar12 < (int)uVar5) &&
               (iVar7 = FUN_404b5474(&local_58,uVar13,uVar12,uVar5), uVar12 = local_4c,
               uVar13 = local_50, iVar7 == 0)) goto LAB_404b6124;
            uVar12 = uVar12 - uVar5;
            uVar6 = (1 << (uVar5 & 0x1f)) - 1U & (int)uVar13 >> (uVar12 & 0x1f);
            if ((int)uVar6 < *(int *)(&LAB_40486a5c + uVar5 * 4)) {
              uVar6 = *(int *)(&DAT_40486a9c + uVar5 * 4) + uVar6;
            }
          }
          iVar7 = local_3c[iVar9] + uVar6;
          local_3c[iVar9] = iVar7;
          *puVar11 = (short)(iVar7 << (uVar4 & 0x1f));
          iVar1 = iVar1 + 1;
          param_2 = param_2 + 1;
          piVar10 = piVar10 + 1;
        } while (iVar1 < *(int *)(param_1 + 0x168));
      }
      **(undefined4 **)(param_1 + 0x18) = local_58;
      *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = local_54;
      *(uint *)(iVar8 + 0xc) = uVar13;
      *(uint *)(iVar8 + 0x10) = uVar12;
      *(undefined4 *)(iVar8 + 0x14) = local_40;
      *(int *)(iVar8 + 0x18) = local_3c[0];
      *(int *)(iVar8 + 0x1c) = local_3c[1];
      *(int *)(iVar8 + 0x20) = local_3c[2];
      *(int *)(iVar8 + 0x24) = local_3c[3];
    }
    *(int *)(iVar8 + 0x28) = *(int *)(iVar8 + 0x28) + -1;
    uVar2 = 1;
  }
  else {
LAB_404b6124:
    uVar2 = 0;
  }
  return uVar2;
}



/* 404b63b4 FUN_404b63b4 */

/* Boundary evidence: original MIPS .pdata 404b63b4..404b66b3. Semantic name remains unreviewed. */

undefined4 FUN_404b63b4(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  
  uVar4 = *(uint *)(param_1 + 0x1a0);
  iVar11 = *(int *)(param_1 + 0x1c0);
  iVar13 = *(int *)(param_1 + 0x198);
  if (((*(int *)(param_1 + 0x118) == 0) || (*(int *)(iVar11 + 0x28) != 0)) ||
     (iVar1 = FUN_404b5ff4(param_1), iVar1 != 0)) {
    if (*(int *)(iVar11 + 8) == 0) {
      if (*(int *)(iVar11 + 0x14) == 0) {
        local_40 = **(undefined4 **)(param_1 + 0x18);
        iVar5 = *param_2;
        local_3c = (*(undefined4 **)(param_1 + 0x18))[1];
        uVar8 = *(uint *)(iVar11 + 0xc);
        uVar7 = *(uint *)(iVar11 + 0x10);
        iVar12 = *(int *)(iVar11 + 0x3c);
        iVar1 = 0;
        local_30 = param_1;
        for (iVar10 = *(int *)(param_1 + 0x194); iVar10 <= iVar13; iVar10 = iVar10 + 1) {
          if ((int)uVar7 < 8) {
            iVar3 = FUN_404b5474(&local_40,uVar8,uVar7,0);
            if (iVar3 == 0) goto LAB_404b641c;
            uVar7 = local_34;
            uVar8 = local_38;
            if (7 < (int)local_34) goto LAB_404b64c4;
            uVar6 = 1;
LAB_404b6500:
            uVar6 = FUN_404b5628(&local_40,uVar8,uVar7,iVar12,uVar6);
            uVar7 = local_34;
            uVar8 = local_38;
            if ((int)uVar6 < 0) goto LAB_404b641c;
          }
          else {
LAB_404b64c4:
            uVar6 = (int)uVar8 >> (uVar7 - 8 & 0x1f) & 0xff;
            iVar3 = *(int *)((uVar6 + 0x24) * 4 + iVar12);
            if (iVar3 == 0) {
              uVar6 = 9;
              goto LAB_404b6500;
            }
            uVar6 = (uint)*(byte *)(uVar6 + iVar12 + 0x490);
            uVar7 = uVar7 - iVar3;
          }
          uVar9 = uVar6 & 0xf;
          uVar6 = (int)uVar6 >> 4;
          if (uVar9 == 0) {
            if (uVar6 != 0xf) {
              iVar1 = 1 << (uVar6 & 0x1f);
              if (uVar6 != 0) {
                if (((int)uVar7 < (int)uVar6) &&
                   (iVar13 = FUN_404b5474(&local_40,uVar8,uVar7,uVar6), uVar7 = local_34,
                   uVar8 = local_38, iVar13 == 0)) goto LAB_404b641c;
                uVar7 = uVar7 - uVar6;
                iVar1 = ((int)uVar8 >> (uVar7 & 0x1f) & iVar1 - 1U) + iVar1;
              }
              iVar1 = iVar1 + -1;
              break;
            }
            iVar10 = iVar10 + 0xf;
          }
          else {
            iVar10 = uVar6 + iVar10;
            if (((int)uVar7 < (int)uVar9) &&
               (iVar3 = FUN_404b5474(&local_40,uVar8,uVar7,uVar9), uVar7 = local_34,
               uVar8 = local_38, iVar3 == 0)) goto LAB_404b641c;
            uVar7 = uVar7 - uVar9;
            uVar6 = (1 << uVar9) - 1U & (int)uVar8 >> (uVar7 & 0x1f);
            if ((int)uVar6 < *(int *)(&LAB_40486a5c + uVar9 * 4)) {
              uVar6 = *(int *)(&DAT_40486a9c + uVar9 * 4) + uVar6;
            }
            *(short *)((&DAT_4048689c)[iVar10] * 2 + iVar5) = (short)(uVar6 << (uVar4 & 0x1f));
          }
        }
        **(undefined4 **)(param_1 + 0x18) = local_40;
        *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = local_3c;
        *(uint *)(iVar11 + 0xc) = uVar8;
        *(uint *)(iVar11 + 0x10) = uVar7;
      }
      else {
        iVar1 = *(int *)(iVar11 + 0x14) + -1;
      }
      *(int *)(iVar11 + 0x14) = iVar1;
    }
    *(int *)(iVar11 + 0x28) = *(int *)(iVar11 + 0x28) + -1;
    uVar2 = 1;
  }
  else {
LAB_404b641c:
    uVar2 = 0;
  }
  return uVar2;
}



/* 404b66b4 FUN_404b66b4 */

/* Boundary evidence: original MIPS .pdata 404b66b4..404b67ff. Semantic name remains unreviewed. */

undefined4 FUN_404b66b4(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  int local_28;
  
  uVar4 = *(uint *)(param_1 + 0x1a0);
  iVar8 = *(int *)(param_1 + 0x1c0);
  if (((*(int *)(param_1 + 0x118) == 0) || (*(int *)(iVar8 + 0x28) != 0)) ||
     (iVar1 = FUN_404b5ff4(param_1), iVar1 != 0)) {
    local_38 = **(undefined4 **)(param_1 + 0x18);
    local_34 = (*(undefined4 **)(param_1 + 0x18))[1];
    uVar6 = *(uint *)(iVar8 + 0xc);
    uVar5 = *(uint *)(iVar8 + 0x10);
    iVar1 = 0;
    local_28 = param_1;
    if (0 < *(int *)(param_1 + 0x168)) {
      do {
        puVar7 = (ushort *)*param_2;
        if (((int)uVar5 < 1) &&
           (iVar3 = FUN_404b5474(&local_38,uVar6,uVar5,1), uVar5 = local_2c, uVar6 = local_30,
           iVar3 == 0)) goto LAB_404b6710;
        uVar5 = uVar5 - 1;
        if (((int)uVar6 >> (uVar5 & 0x1f) & 1U) != 0) {
          *puVar7 = *puVar7 | (ushort)(1 << (uVar4 & 0x1f));
        }
        iVar1 = iVar1 + 1;
        param_2 = param_2 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x168));
    }
    uVar2 = 1;
    **(undefined4 **)(param_1 + 0x18) = local_38;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = local_34;
    *(uint *)(iVar8 + 0xc) = uVar6;
    *(uint *)(iVar8 + 0x10) = uVar5;
    *(int *)(iVar8 + 0x28) = *(int *)(iVar8 + 0x28) + -1;
  }
  else {
LAB_404b6710:
    uVar2 = 0;
  }
  return uVar2;
}



/* 404b6800 FUN_404b6800 */

/* Boundary evidence: original MIPS .pdata 404b6800..404b6d27. Semantic name remains unreviewed. */

undefined4 FUN_404b6800(int *param_1,int *param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  short *psVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int local_15c;
  undefined4 local_150;
  undefined4 local_14c;
  uint local_148;
  uint local_144;
  int *local_140;
  int *local_13c;
  int *local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128 [64];
  
  uVar15 = 1 << (param_1[0x68] & 0x1fU);
  iVar10 = param_1[0x70];
  iVar13 = param_1[0x66];
  uVar14 = -1 << (param_1[0x68] & 0x1fU);
  local_13c = param_1;
  local_134 = iVar13;
  local_130 = iVar10;
  if (((param_1[0x46] != 0) && (*(int *)(iVar10 + 0x28) == 0)) &&
     (iVar3 = FUN_404b5ff4((int)param_1), iVar3 == 0)) {
    return 0;
  }
  if (*(int *)(iVar10 + 8) == 0) {
    local_150 = *(undefined4 *)local_13c[6];
    iVar16 = 0;
    local_14c = ((undefined4 *)local_13c[6])[1];
    local_15c = *(int *)(iVar10 + 0x14);
    uVar12 = *(uint *)(iVar10 + 0xc);
    uVar8 = *(uint *)(iVar10 + 0x10);
    iVar3 = *param_2;
    local_12c = *(int *)(iVar10 + 0x3c);
    iVar10 = local_13c[0x65];
    sVar2 = (short)uVar14;
    local_140 = local_13c;
    if (local_15c == 0) {
      if (iVar10 <= iVar13) {
        local_138 = local_128;
        do {
          iVar5 = local_12c;
          if ((int)uVar8 < 8) {
            iVar4 = FUN_404b5474(&local_150,uVar12,uVar8,0);
            if (iVar4 == 0) goto LAB_404b6c7c;
            uVar8 = local_144;
            uVar12 = local_148;
            if (7 < (int)local_144) goto LAB_404b693c;
            uVar6 = 1;
LAB_404b6978:
            uVar6 = FUN_404b5628(&local_150,uVar12,uVar8,iVar5,uVar6);
            uVar8 = local_144;
            uVar12 = local_148;
            if ((int)uVar6 < 0) goto LAB_404b6c7c;
          }
          else {
LAB_404b693c:
            uVar6 = (int)uVar12 >> (uVar8 - 8 & 0x1f) & 0xff;
            iVar4 = *(int *)((uVar6 + 0x24) * 4 + iVar5);
            if (iVar4 == 0) {
              uVar6 = 9;
              goto LAB_404b6978;
            }
            uVar6 = (uint)*(byte *)(uVar6 + iVar5 + 0x490);
            uVar8 = uVar8 - iVar4;
          }
          uVar11 = (int)uVar6 >> 4;
          if ((uVar6 & 0xf) == 0) {
            uVar6 = 0;
            if (uVar11 != 0xf) {
              local_15c = 1 << (uVar11 & 0x1f);
              if (uVar11 == 0) goto LAB_404b6bb8;
              if (((int)uVar8 < (int)uVar11) &&
                 (iVar5 = FUN_404b5474(&local_150,uVar12,uVar8,uVar11), uVar8 = local_144,
                 uVar12 = local_148, iVar5 == 0)) goto LAB_404b6c7c;
              uVar8 = uVar8 - uVar11;
              local_15c = ((int)uVar12 >> (uVar8 & 0x1f) & local_15c - 1U) + local_15c;
              goto LAB_404b6bb8;
            }
          }
          else {
            if ((uVar6 & 0xf) != 1) {
              *(undefined4 *)(*local_13c + 0x14) = 0x76;
              (**(code **)(*local_13c + 4))(local_13c,0xffffffff);
            }
            if (((int)uVar8 < 1) &&
               (iVar13 = FUN_404b5474(&local_150,uVar12,uVar8,1), uVar8 = local_144,
               uVar12 = local_148, iVar13 == 0)) goto LAB_404b6c7c;
            uVar8 = uVar8 - 1;
            uVar6 = uVar14;
            if (((int)uVar12 >> (uVar8 & 0x1f) & 1U) != 0) {
              uVar6 = uVar15;
            }
          }
          piVar7 = &DAT_4048689c + iVar10;
          do {
            psVar9 = (short *)(*piVar7 * 2 + iVar3);
            if (*psVar9 == 0) {
              uVar11 = uVar11 - 1;
              if ((int)uVar11 < 0) break;
            }
            else {
              if (((int)uVar8 < 1) &&
                 (iVar13 = FUN_404b5474(&local_150,uVar12,uVar8,1), uVar8 = local_144,
                 uVar12 = local_148, iVar13 == 0)) goto LAB_404b6c7c;
              uVar8 = uVar8 - 1;
              if (((int)uVar12 >> (uVar8 & 0x1f) & 1U) != 0) {
                sVar1 = *psVar9;
                if (((int)sVar1 & uVar15) == 0) {
                  if (sVar1 < 0) {
                    *psVar9 = sVar1 + sVar2;
                  }
                  else {
                    *psVar9 = sVar1 + (short)uVar15;
                  }
                }
              }
            }
            iVar10 = iVar10 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar10 <= local_134);
          if (uVar6 != 0) {
            iVar13 = (&DAT_4048689c)[iVar10];
            *local_138 = iVar13;
            local_138 = local_138 + 1;
            iVar16 = iVar16 + 1;
            *(short *)(iVar13 * 2 + iVar3) = (short)uVar6;
          }
          iVar10 = iVar10 + 1;
          iVar13 = local_134;
        } while (iVar10 <= local_134);
      }
    }
    else {
LAB_404b6bb8:
      if (local_15c != 0) {
        if (iVar10 <= iVar13) {
          piVar7 = &DAT_4048689c + iVar10;
          do {
            psVar9 = (short *)(*piVar7 * 2 + iVar3);
            if (*psVar9 != 0) {
              if (((int)uVar8 < 1) &&
                 (iVar5 = FUN_404b5474(&local_150,uVar12,uVar8,1), uVar8 = local_144,
                 uVar12 = local_148, iVar5 == 0)) {
LAB_404b6c7c:
                if (iVar16 < 1) {
                  return 0;
                }
                piVar7 = local_128 + iVar16;
                do {
                  piVar7 = piVar7 + -1;
                  iVar16 = iVar16 + -1;
                  *(undefined2 *)(*piVar7 * 2 + iVar3) = 0;
                } while (0 < iVar16);
                return 0;
              }
              uVar8 = uVar8 - 1;
              if (((int)uVar12 >> (uVar8 & 0x1f) & 1U) != 0) {
                sVar1 = *psVar9;
                if (((int)sVar1 & uVar15) == 0) {
                  if (sVar1 < 0) {
                    *psVar9 = sVar1 + sVar2;
                  }
                  else {
                    *psVar9 = sVar1 + (short)uVar15;
                  }
                }
              }
            }
            iVar10 = iVar10 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar10 <= iVar13);
        }
        local_15c = local_15c + -1;
      }
    }
    *(undefined4 *)local_13c[6] = local_150;
    *(undefined4 *)(local_13c[6] + 4) = local_14c;
    *(uint *)(local_130 + 0xc) = uVar12;
    *(uint *)(local_130 + 0x10) = uVar8;
    *(int *)(local_130 + 0x14) = local_15c;
    iVar10 = local_130;
  }
  *(int *)(iVar10 + 0x28) = *(int *)(iVar10 + 0x28) + -1;
  return 1;
}



/* 404b6d28 FUN_404b6d28 */

/* Boundary evidence: original MIPS .pdata 404b6d28..404b7063. Semantic name remains unreviewed. */

void FUN_404b6d28(int *param_1)

{
  bool bVar1;
  bool bVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  
  iVar10 = param_1[0x70];
  bVar1 = param_1[0x65] != 0;
  bVar2 = false;
  if (bVar1) {
    if ((param_1[0x66] < param_1[0x65]) || (0x3f < param_1[0x66])) {
      bVar2 = true;
    }
    if (param_1[0x53] != 1) goto LAB_404b6db8;
  }
  else if (param_1[0x66] != 0) {
LAB_404b6db8:
    bVar2 = true;
  }
  if ((param_1[0x67] != 0) && (param_1[0x68] != param_1[0x67] + -1)) {
    bVar2 = true;
  }
  if ((0xd < param_1[0x68]) || (bVar2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x10;
    *(int *)(*param_1 + 0x18) = param_1[0x65];
    *(int *)(*param_1 + 0x1c) = param_1[0x66];
    *(int *)(*param_1 + 0x20) = param_1[0x67];
    *(int *)(*param_1 + 0x24) = param_1[0x68];
    (**(code **)*param_1)(param_1);
  }
  iVar11 = 0;
  if (0 < param_1[0x53]) {
    piVar7 = param_1 + 0x54;
    do {
      iVar8 = *(int *)(*piVar7 + 4);
      piVar5 = (int *)(iVar8 * 0x100 + param_1[0x29]);
      if ((bVar1) && (*piVar5 < 0)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x73;
        *(int *)(*param_1 + 0x18) = iVar8;
        *(undefined4 *)(*param_1 + 0x1c) = 0;
        (**(code **)(*param_1 + 4))(param_1,0xffffffff);
      }
      iVar6 = param_1[0x65];
      if (iVar6 <= param_1[0x66]) {
        piVar5 = piVar5 + iVar6;
        do {
          iVar4 = *piVar5;
          if (iVar4 < 0) {
            iVar4 = 0;
          }
          if (param_1[0x67] != iVar4) {
            *(undefined4 *)(*param_1 + 0x14) = 0x73;
            *(int *)(*param_1 + 0x18) = iVar8;
            *(int *)(*param_1 + 0x1c) = iVar6;
            (**(code **)(*param_1 + 4))(param_1,0xffffffff);
          }
          iVar6 = iVar6 + 1;
          *piVar5 = param_1[0x68];
          piVar5 = piVar5 + 1;
        } while (iVar6 <= param_1[0x66]);
      }
      iVar11 = iVar11 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar11 < param_1[0x53]);
  }
  if (param_1[0x67] == 0) {
    if (!bVar1) {
      *(code **)(iVar10 + 4) = FUN_404b60c0;
      goto LAB_404b6f8c;
    }
    pcVar3 = FUN_404b63b4;
  }
  else {
    if (!bVar1) {
      *(code **)(iVar10 + 4) = FUN_404b66b4;
      goto LAB_404b6f8c;
    }
    pcVar3 = FUN_404b6800;
  }
  *(code **)(iVar10 + 4) = pcVar3;
LAB_404b6f8c:
  iVar11 = 0;
  if (0 < param_1[0x53]) {
    puVar9 = (undefined4 *)(iVar10 + 0x18);
    piVar7 = param_1 + 0x54;
    do {
      if (bVar1) {
        iVar8 = *(int *)(*piVar7 + 0x18);
        piVar5 = (int *)((iVar8 + 0xb) * 4 + iVar10);
        FUN_404b5070(param_1,0,iVar8,piVar5);
        *(int *)(iVar10 + 0x3c) = *piVar5;
      }
      else if (param_1[0x67] == 0) {
        iVar8 = *(int *)(*piVar7 + 0x14);
        FUN_404b5070(param_1,1,iVar8,(int *)((iVar8 + 0xb) * 4 + iVar10));
      }
      *puVar9 = 0;
      iVar11 = iVar11 + 1;
      piVar7 = piVar7 + 1;
      puVar9 = puVar9 + 1;
    } while (iVar11 < param_1[0x53]);
  }
  *(undefined4 *)(iVar10 + 0x10) = 0;
  *(undefined4 *)(iVar10 + 0xc) = 0;
  *(undefined4 *)(iVar10 + 8) = 0;
  *(undefined4 *)(iVar10 + 0x14) = 0;
  *(int *)(iVar10 + 0x28) = param_1[0x46];
  return;
}



/* 404b7064 FUN_404b7064 */

/* Boundary evidence: original MIPS .pdata 404b7064..404b7117. Semantic name remains unreviewed. */

void FUN_404b7064(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x40);
  *(undefined4 **)(param_1 + 0x1c0) = puVar1;
  *puVar1 = FUN_404b6d28;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1 = (undefined4 *)
           (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,*(int *)(param_1 + 0x24) << 8);
  iVar3 = 0;
  *(undefined4 **)(param_1 + 0xa4) = puVar1;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      puVar2 = puVar1;
      do {
        *puVar2 = 0xffffffff;
        puVar2 = puVar2 + 1;
      } while (puVar2 != puVar1 + 0x40);
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 0x40;
    } while (iVar3 < *(int *)(param_1 + 0x24));
  }
  return;
}



/* 404b7118 FUN_404b7118 */

/* Boundary evidence: original MIPS .pdata 404b7118..404b77ab. Semantic name remains unreviewed. */

void FUN_404b7118(int *param_1)

{
  ushort *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  code *pcVar11;
  ushort *puVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined8 uVar15;
  int local_58;
  code *local_54;
  int local_50;
  
  iVar9 = 0;
  pcVar11 = (code *)0x0;
  local_58 = 0;
  local_54 = (code *)0x0;
  local_50 = 0;
  if (0 < param_1[9]) {
    piVar8 = (int *)(param_1[0x37] + 0x30);
    puVar2 = (undefined4 *)param_1[0x71];
    do {
      switch(piVar8[-3]) {
      case 1:
        iVar9 = 0;
        local_54 = (code *)&LAB_404baec8;
        local_58 = 0;
        pcVar11 = (code *)&LAB_404baec8;
        break;
      case 2:
        iVar9 = 0;
        local_54 = FUN_404ba784;
        local_58 = 0;
        pcVar11 = FUN_404ba784;
        break;
      default:
        *(undefined4 *)(*param_1 + 0x14) = 7;
        *(int *)(*param_1 + 0x18) = piVar8[-3];
        (**(code **)*param_1)(param_1);
        break;
      case 4:
        iVar9 = 0;
        local_58 = 0;
        pcVar11 = FUN_404ba2c8;
        local_54 = FUN_404ba2c8;
        break;
      case 8:
        switch(param_1[0x12]) {
        case 0:
        case 3:
        case 5:
          iVar9 = 0;
          local_54 = FUN_404baf08;
          local_58 = 0;
          pcVar11 = FUN_404baf08;
          break;
        case 1:
        case 4:
        case 6:
          iVar9 = 1;
          local_54 = FUN_404bb588;
          local_58 = 1;
          pcVar11 = FUN_404bb588;
          break;
        case 2:
          iVar9 = 2;
          local_54 = FUN_404bbc2c;
          local_58 = 2;
          pcVar11 = FUN_404bbc2c;
          break;
        default:
          *(undefined4 *)(*param_1 + 0x14) = 0x30;
          (**(code **)*param_1)(param_1);
        }
      }
      puVar2[1] = pcVar11;
      if (((*piVar8 != 0) && (puVar2[0xb] != iVar9)) &&
         (puVar12 = (ushort *)piVar8[7], puVar12 != (ushort *)0x0)) {
        puVar2[0xb] = iVar9;
        if (iVar9 == 0) {
          puVar7 = (undefined2 *)piVar8[8];
          iVar4 = (int)puVar12 - (int)puVar7;
          iVar6 = 0x40;
          do {
            iVar6 = iVar6 + -1;
            *puVar7 = *(undefined2 *)(iVar4 + (int)puVar7);
            puVar7 = puVar7 + 1;
          } while (iVar6 != 0);
        }
        else if (iVar9 == 1) {
          iVar5 = piVar8[8];
          puVar7 = (undefined2 *)(iVar5 + 4);
          iVar4 = (int)puVar12 - iVar5;
          iVar6 = -(int)puVar12;
          iVar13 = 0x10;
          do {
            iVar13 = iVar13 + -1;
            puVar7[-2] = (short)((int)((int)*(short *)((int)puVar12 + (int)&UNK_40486ae0 + iVar6) *
                                       (uint)*puVar12 + 0x800) >> 0xc);
            puVar7[-1] = (short)((int)((uint)*(ushort *)((int)(puVar7 + -1) + iVar4) *
                                       (int)*(short *)((int)puVar12 + (int)&UNK_40486ae2 + iVar6) +
                                      0x800) >> 0xc);
            *puVar7 = (short)((int)((int)*(short *)((int)&UNK_40486ae0 + -iVar5 + (int)puVar7) *
                                    (uint)*(ushort *)(iVar4 + (int)puVar7) + 0x800) >> 0xc);
            puVar1 = puVar12 + 3;
            puVar12 = puVar12 + 4;
            puVar7[1] = (short)((int)((int)*(short *)((int)&UNK_40486ae2 + -iVar5 + (int)puVar7) *
                                      (uint)*puVar1 + 0x800) >> 0xc);
            puVar7 = puVar7 + 4;
          } while (iVar13 != 0);
        }
        else if (iVar9 == 2) {
          puVar14 = (undefined4 *)(piVar8[8] + 0x10);
          puVar12 = puVar12 + 4;
          puVar10 = &DAT_40486b60;
          do {
            uVar15 = __ultodp(puVar12[-4]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),*puVar10,puVar10[1]);
            uVar3 = __dptofp((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
            puVar14[-4] = uVar3;
            uVar15 = __ultodp(puVar12[-3]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),*puVar10,puVar10[1]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0xb14861ef,0x3ff63150);
            uVar3 = __dptofp((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
            puVar14[-3] = uVar3;
            uVar15 = __ultodp(puVar12[-2]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),*puVar10,puVar10[1]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0x914d6fca,0x3ff4e7ae);
            uVar3 = __dptofp((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
            puVar14[-2] = uVar3;
            uVar15 = __ultodp(puVar12[-1]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),*puVar10,puVar10[1]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0xef6c11aa,0x3ff2d062);
            uVar3 = __dptofp((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
            puVar14[-1] = uVar3;
            uVar15 = __ultodp(*puVar12);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),*puVar10,puVar10[1]);
            uVar3 = __dptofp((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
            *puVar14 = uVar3;
            uVar15 = __ultodp(puVar12[1]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),*puVar10,puVar10[1]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0xc0a7bf3b,0x3fe92469);
            uVar3 = __dptofp((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
            puVar14[1] = uVar3;
            uVar15 = __ultodp(puVar12[2]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),*puVar10,puVar10[1]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0x7bc720bb,0x3fe1517a);
            uVar3 = __dptofp((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
            puVar14[2] = uVar3;
            uVar15 = __ultodp(puVar12[3]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),*puVar10,puVar10[1]);
            uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0xde72ab5d,0x3fd1a855);
            uVar3 = __dptofp((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
            puVar10 = puVar10 + 2;
            puVar14[3] = uVar3;
            puVar12 = puVar12 + 8;
            puVar14 = puVar14 + 8;
            iVar9 = local_58;
            pcVar11 = local_54;
          } while ((int)puVar10 < 0x40486ba0);
        }
        else {
          *(undefined4 *)(*param_1 + 0x14) = 0x30;
          (**(code **)*param_1)(param_1);
        }
      }
      local_50 = local_50 + 1;
      piVar8 = piVar8 + 0x15;
      puVar2 = puVar2 + 1;
    } while (local_50 < param_1[9]);
  }
  return;
}



/* 404b77ac FUN_404b77ac */

/* Boundary evidence: original MIPS .pdata 404b77ac..404b7877. Semantic name remains unreviewed. */

void FUN_404b77ac(int param_1)

{
  undefined4 *puVar1;
  void *_Dst;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x54);
  *(undefined4 **)(param_1 + 0x1c4) = puVar1;
  *puVar1 = FUN_404b7118;
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0xdc) + 0x50);
    puVar1 = puVar1 + 0xb;
    do {
      _Dst = (void *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x100);
      *puVar2 = _Dst;
      memset(_Dst,0,0x100);
      *puVar1 = 0xffffffff;
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 0x15;
    } while (iVar3 < *(int *)(param_1 + 0x24));
  }
  return;
}



/* 404b7878 FUN_404b7878 */

/* Boundary evidence: original MIPS .pdata 404b7878..404b792f. Semantic name remains unreviewed. */

void FUN_404b7878(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_stack_00000010;
  int *in_stack_00000014;
  int in_stack_00000018;
  int *piVar4;
  int local_18 [2];
  
  iVar3 = *(int *)(param_1 + 0x1b4);
  uVar2 = in_stack_00000018 - *in_stack_00000014;
  if (*(uint *)(iVar3 + 0x10) < (uint)(in_stack_00000018 - *in_stack_00000014)) {
    uVar2 = *(uint *)(iVar3 + 0x10);
  }
  piVar4 = local_18;
  local_18[0] = 0;
  uVar1 = *(undefined4 *)(iVar3 + 0xc);
  (**(code **)(*(int *)(param_1 + 0x1c8) + 4))(param_1);
  (**(code **)(*(int *)(param_1 + 0x1d0) + 4))
            (param_1,*(undefined4 *)(iVar3 + 0xc),*in_stack_00000014 * 4 + in_stack_00000010,
             local_18[0],uVar1,piVar4,uVar2);
  *in_stack_00000014 = *in_stack_00000014 + local_18[0];
  return;
}



/* 404b7930 FUN_404b7930 */

/* Boundary evidence: original MIPS .pdata 404b7930..404b79d7. Semantic name remains unreviewed. */

void FUN_404b7930(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1[0x6d];
  if (param_2 == 0) {
    if (param_1[0x15] == 0) {
      *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1[0x72] + 4);
    }
    else {
      *(code **)(iVar2 + 4) = FUN_404b7878;
      if (*(int *)(iVar2 + 0xc) == 0) {
        uVar1 = (**(code **)(param_1[1] + 0x1c))
                          (param_1,*(undefined4 *)(iVar2 + 8),0,*(undefined4 *)(iVar2 + 0x10),1);
        *(undefined4 *)(iVar2 + 0xc) = uVar1;
      }
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 4;
    (**(code **)*param_1)();
  }
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  return;
}



/* 404b79d8 FUN_404b79d8 */

/* Boundary evidence: original MIPS .pdata 404b79d8..404b7aa3. Semantic name remains unreviewed. */

void FUN_404b79d8(int *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x1c);
  param_1[0x6d] = (int)puVar1;
  *puVar1 = FUN_404b7930;
  puVar1[2] = 0;
  puVar1[3] = 0;
  if (param_1[0x15] != 0) {
    puVar1[4] = param_1[0x4f];
    if (param_2 == 0) {
      uVar2 = (**(code **)(param_1[1] + 8))(param_1,1,param_1[0x1e] * param_1[0x1c]);
      puVar1[3] = uVar2;
    }
    else {
      *(undefined4 *)(*param_1 + 0x14) = 4;
      (**(code **)*param_1)();
    }
  }
  return;
}



/* 404b7abc FUN_404b7abc */

/* Boundary evidence: original MIPS .pdata 404b7abc..404b7c37. Semantic name remains unreviewed. */

void FUN_404b7abc(int param_1,int *param_2,int *param_3,undefined4 param_4,int param_5,int *param_6,
                 int param_7)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *(int *)(param_1 + 0x1c8);
  if (*(int *)(param_1 + 0x13c) <= *(int *)(iVar2 + 0x5c)) {
    iVar6 = *(int *)(param_1 + 0xdc);
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x24)) {
      iVar3 = iVar2 + 0xc;
      do {
        (**(code **)(iVar3 + 0x28))
                  (param_1,iVar6,*(int *)(iVar3 + 0x58) * *param_3 * 4 + *param_2,iVar3);
        iVar5 = iVar5 + 1;
        param_2 = param_2 + 1;
        iVar3 = iVar3 + 4;
        iVar6 = iVar6 + 0x54;
      } while (iVar5 < *(int *)(param_1 + 0x24));
    }
    *(undefined4 *)(iVar2 + 0x5c) = 0;
  }
  uVar4 = *(int *)(param_1 + 0x13c) - *(int *)(iVar2 + 0x5c);
  if (*(uint *)(iVar2 + 0x60) < uVar4) {
    uVar4 = *(uint *)(iVar2 + 0x60);
  }
  uVar1 = param_7 - *param_6;
  if (uVar1 < uVar4) {
    uVar4 = uVar1;
  }
  (**(code **)(*(int *)(param_1 + 0x1cc) + 4))
            (param_1,iVar2 + 0xc,*(undefined4 *)(iVar2 + 0x5c),*param_6 * 4 + param_5,uVar4);
  *param_6 = *param_6 + uVar4;
  iVar5 = uVar4 + *(int *)(iVar2 + 0x5c);
  *(uint *)(iVar2 + 0x60) = *(int *)(iVar2 + 0x60) - uVar4;
  *(int *)(iVar2 + 0x5c) = iVar5;
  if (*(int *)(param_1 + 0x13c) <= iVar5) {
    *param_3 = *param_3 + 1;
  }
  return;
}



/* 404b7c48 FUN_404b7c48 */

/* Boundary evidence: original MIPS .pdata 404b7c48..404b7d7f. Semantic name remains unreviewed. */

void FUN_404b7c48(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  puVar10 = (undefined4 *)*param_4;
  iVar4 = *(int *)(param_2 + 4) + *(int *)(param_1 + 0x1c8);
  uVar3 = (uint)*(byte *)(iVar4 + 0x8c);
  uVar5 = (uint)*(byte *)(iVar4 + 0x96);
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x13c)) {
    puVar9 = puVar10;
    do {
      puVar6 = (undefined1 *)*puVar9;
      puVar8 = puVar6 + *(int *)(param_1 + 0x70);
      puVar7 = (undefined1 *)*param_3;
      while (puVar6 < puVar8) {
        uVar1 = *puVar7;
        puVar7 = puVar7 + 1;
        if (uVar3 != 0) {
          if (uVar3 != 0) {
            puVar2 = puVar6;
            do {
              *puVar2 = uVar1;
              puVar2 = puVar2 + 1;
            } while (puVar2 != puVar6 + uVar3);
          }
          puVar6 = puVar6 + uVar3;
        }
      }
      if (1 < uVar5) {
        FUN_404b2f80((int)puVar10,iVar4,(int)puVar10,iVar4 + 1,uVar5 - 1,*(size_t *)(param_1 + 0x70)
                    );
      }
      param_3 = param_3 + 1;
      iVar4 = iVar4 + uVar5;
      puVar9 = puVar9 + uVar5;
    } while (iVar4 < *(int *)(param_1 + 0x13c));
  }
  return;
}



/* 404b7df0 FUN_404b7df0 */

/* Boundary evidence: original MIPS .pdata 404b7df0..404b7ec7. Semantic name remains unreviewed. */

void FUN_404b7df0(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  puVar6 = (undefined4 *)*param_4;
  iVar7 = 0;
  puVar5 = puVar6;
  if (0 < *(int *)(param_1 + 0x13c)) {
    do {
      puVar2 = (undefined1 *)*puVar5;
      puVar4 = puVar2 + *(int *)(param_1 + 0x70);
      puVar3 = (undefined1 *)*param_3;
      for (; puVar2 < puVar4; puVar2 = puVar2 + 2) {
        uVar1 = *puVar3;
        *puVar2 = uVar1;
        puVar2[1] = uVar1;
        puVar3 = puVar3 + 1;
      }
      FUN_404b2f80((int)puVar6,iVar7,(int)puVar6,iVar7 + 1,1,*(size_t *)(param_1 + 0x70));
      param_3 = param_3 + 1;
      iVar7 = iVar7 + 2;
      puVar5 = puVar5 + 2;
    } while (iVar7 < *(int *)(param_1 + 0x13c));
  }
  return;
}



/* 404b7ec8 FUN_404b7ec8 */

void FUN_404b7ec8(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  
  puVar4 = (undefined4 *)*param_4;
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x13c)) {
    iVar5 = param_3 - (int)puVar4;
    do {
      pbVar6 = *(byte **)(iVar5 + (int)puVar4);
      bVar1 = *pbVar6;
      pbVar7 = (byte *)*puVar4;
      pbVar6 = pbVar6 + 1;
      *pbVar7 = bVar1;
      pbVar7[1] = (byte)((int)((uint)bVar1 * 3 + (uint)*pbVar6 + 2) >> 2);
      for (iVar8 = *(int *)(param_2 + 0x28) + -2; pbVar2 = pbVar7 + 2, iVar8 != 0;
          iVar8 = iVar8 + -1) {
        bVar1 = *pbVar6;
        *pbVar2 = (byte)((int)((uint)pbVar6[-1] + (uint)bVar1 * 3 + 1) >> 2);
        pbVar7[3] = (byte)((int)((uint)pbVar6[1] + (uint)bVar1 * 3 + 2) >> 2);
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar2;
      }
      bVar1 = *pbVar6;
      *pbVar2 = (byte)((int)((uint)pbVar6[-1] + (uint)bVar1 * 3 + 1) >> 2);
      pbVar7[3] = bVar1;
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x13c));
  }
  return;
}



/* 404b7fbc FUN_404b7fbc */

/* Boundary evidence: original MIPS .pdata 404b7fbc..404b8157. Semantic name remains unreviewed. */

void FUN_404b7fbc(int param_1,int param_2,undefined4 *param_3,int *param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar9 = *param_4;
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x13c)) {
    do {
      iVar4 = 0;
      puVar8 = (undefined4 *)(iVar2 * 4 + iVar9);
      do {
        pbVar6 = (byte *)*param_3;
        if (iVar4 == 0) {
          pbVar5 = (byte *)param_3[-1];
        }
        else {
          pbVar5 = (byte *)param_3[1];
        }
        puVar7 = (undefined1 *)*puVar8;
        iVar3 = (uint)*pbVar6 * 3 + (uint)*pbVar5;
        iVar10 = (uint)pbVar6[1] * 3 + (uint)pbVar5[1];
        *puVar7 = (char)((iVar3 + 2) * 4 >> 4);
        pbVar5 = pbVar5 + 2;
        puVar7[1] = (char)(iVar3 * 3 + iVar10 + 7 >> 4);
        pbVar6 = pbVar6 + 2;
        iVar2 = iVar2 + 1;
        puVar8 = puVar8 + 1;
        for (iVar12 = *(int *)(param_2 + 0x28) + -2; puVar1 = puVar7 + 2, iVar12 != 0;
            iVar12 = iVar12 + -1) {
          iVar11 = (uint)*pbVar6 * 3 + (uint)*pbVar5;
          *puVar1 = (char)(iVar10 * 3 + iVar3 + 8 >> 4);
          puVar7[3] = (char)(iVar10 * 3 + iVar11 + 7 >> 4);
          pbVar5 = pbVar5 + 1;
          pbVar6 = pbVar6 + 1;
          iVar3 = iVar10;
          iVar10 = iVar11;
          puVar7 = puVar1;
        }
        *puVar1 = (char)(iVar10 * 3 + iVar3 + 8 >> 4);
        iVar4 = iVar4 + 1;
        puVar7[3] = (char)(iVar10 * 4 + 7 >> 4);
      } while (iVar4 < 2);
      param_3 = param_3 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x13c));
  }
  return;
}



/* 404b8158 FUN_404b8158 */

/* Boundary evidence: original MIPS .pdata 404b8158..404b8173. Semantic name remains unreviewed. */

void FUN_404b8158(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  FUN_404b7ec8(param_1,param_2,param_3,param_4);
  return;
}



/* 404b8174 FUN_404b8174 */

/* Boundary evidence: original MIPS .pdata 404b8174..404b818f. Semantic name remains unreviewed. */

void FUN_404b8174(int param_1,int param_2,undefined4 *param_3,int *param_4)

{
  FUN_404b7fbc(param_1,param_2,param_3,param_4);
  return;
}



/* 404b8190 FUN_404b8190 */

/* Boundary evidence: original MIPS .pdata 404b8190..404b856b. Semantic name remains unreviewed. */

void FUN_404b8190(int *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  puVar2 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0xa0);
  param_1[0x72] = (int)puVar2;
  *puVar2 = &LAB_404b7aa4;
  puVar2[1] = FUN_404b7abc;
  puVar2[2] = 0;
  if (param_1[0x4c] != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x19;
    (**(code **)*param_1)(param_1);
  }
  if ((param_1[0x13] == 0) || (bVar1 = true, param_1[0x50] < 2)) {
    bVar1 = false;
  }
  iVar8 = 0;
  if (0 < param_1[9]) {
    piVar7 = (int *)(param_1[0x37] + 0x30);
    puVar6 = puVar2 + 3;
    do {
      iVar5 = piVar7[-3] * piVar7[-10];
      iVar4 = param_1[0x50];
      iVar9 = iVar5 / iVar4;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar5 == -0x80000000)) {
        trap(0x1800);
      }
      iVar5 = piVar7[-9] * piVar7[-3];
      iVar10 = iVar5 / iVar4;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar5 == -0x80000000)) {
        trap(0x1800);
      }
      iVar4 = param_1[0x4e];
      iVar5 = param_1[0x4f];
      puVar6[0x16] = iVar10;
      if (*piVar7 == 0) {
        puVar6[10] = &LAB_404b7c40;
      }
      else if ((iVar9 == iVar4) && (iVar10 == iVar5)) {
        puVar6[10] = &LAB_404b7c38;
      }
      else {
        if (iVar9 << 1 == iVar4) {
          if (iVar10 == iVar5) {
            if ((bVar1) && (2 < (uint)piVar7[-2])) {
              puVar6[10] = FUN_404b8158;
            }
            else {
              puVar6[10] = &LAB_404b7d80;
            }
          }
          else {
            if ((iVar9 << 1 != iVar4) || (iVar10 << 1 != iVar5)) goto LAB_404b83ec;
            if ((bVar1) && (2 < (uint)piVar7[-2])) {
              puVar6[10] = FUN_404b8174;
              puVar2[2] = 1;
            }
            else {
              puVar6[10] = FUN_404b7df0;
            }
          }
        }
        else {
LAB_404b83ec:
          if (iVar9 == 0) {
            trap(0x1c00);
          }
          if ((iVar9 == -1) && (iVar4 == -0x80000000)) {
            trap(0x1800);
          }
          if (iVar4 % iVar9 == 0) {
            if (iVar10 == 0) {
              trap(0x1c00);
            }
            if ((iVar10 == -1) && (iVar5 == -0x80000000)) {
              trap(0x1800);
            }
            if (iVar5 % iVar10 == 0) {
              puVar6[10] = FUN_404b7c48;
              if (iVar9 == 0) {
                trap(0x1c00);
              }
              if ((iVar9 == -1) && (iVar4 == -0x80000000)) {
                trap(0x1800);
              }
              *(char *)((int)puVar2 + iVar8 + 0x8c) = (char)(iVar4 / iVar9);
              if (iVar10 == 0) {
                trap(0x1c00);
              }
              if ((iVar10 == -1) && (iVar5 == -0x80000000)) {
                trap(0x1800);
              }
              *(char *)((int)puVar2 + iVar8 + 0x96) = (char)(iVar5 / iVar10);
              goto LAB_404b84dc;
            }
          }
          *(undefined4 *)(*param_1 + 0x14) = 0x26;
          (**(code **)*param_1)(param_1);
        }
LAB_404b84dc:
        iVar4 = param_1[1];
        iVar5 = FUN_404b2f44(param_1[0x1c],param_1[0x4e]);
        uVar3 = (**(code **)(iVar4 + 8))(param_1,1,iVar5,param_1[0x4f]);
        *puVar6 = uVar3;
      }
      iVar8 = iVar8 + 1;
      puVar6 = puVar6 + 1;
      piVar7 = piVar7 + 0x15;
    } while (iVar8 < param_1[9]);
  }
  return;
}



/* 404b856c FUN_404b856c */

/* Boundary evidence: original MIPS .pdata 404b856c..404b869b. Semantic name remains unreviewed. */

void FUN_404b856c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = *(int *)(param_1 + 0x1cc);
  uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar5 + 8) = uVar1;
  uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar5 + 0xc) = uVar1;
  uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar5 + 0x10) = uVar1;
  uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar5 + 0x14) = uVar1;
  iVar3 = 0;
  iVar6 = 0x5b6900;
  iVar7 = -0xe25100;
  iVar2 = -0xb2f480;
  iVar4 = 0x2c8d00;
  do {
    *(int *)(iVar3 + *(int *)(iVar5 + 8)) = iVar2 >> 0x10;
    *(int *)(*(int *)(iVar5 + 0xc) + iVar3) = iVar7 >> 0x10;
    *(int *)(iVar3 + *(int *)(iVar5 + 0x10)) = iVar6;
    *(int *)(*(int *)(iVar5 + 0x14) + iVar3) = iVar4;
    iVar4 = iVar4 + -0x581a;
    iVar2 = iVar2 + 0x166e9;
    iVar7 = iVar7 + 0x1c5a2;
    iVar6 = iVar6 + -0xb6d2;
    iVar3 = iVar3 + 4;
  } while (-0x2b34e7 < iVar4);
  return;
}



/* 404b869c FUN_404b869c */

/* Boundary evidence: original MIPS .pdata 404b869c..404b880f. Semantic name remains unreviewed. */

void FUN_404b869c(int param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  undefined1 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  iVar6 = *(int *)(param_1 + 0x1cc);
  iVar16 = *(int *)(iVar6 + 8);
  iVar17 = *(int *)(iVar6 + 0xc);
  iVar18 = *(int *)(iVar6 + 0x10);
  iVar7 = *(int *)(iVar6 + 0x14);
  iVar14 = *(int *)(param_1 + 0x70);
  iVar15 = *(int *)(param_1 + 0x148);
  iVar6 = param_5 + -1;
  if (-1 < iVar6) {
    iVar4 = param_3 << 2;
    do {
      piVar9 = (int *)(*param_2 + iVar4);
      piVar8 = (int *)(param_2[2] + iVar4);
      puVar11 = (undefined1 *)*param_4;
      pbVar5 = *(byte **)(iVar4 + param_2[1]);
      iVar4 = iVar4 + 4;
      param_4 = param_4 + 1;
      if (iVar14 != 0) {
        iVar12 = *piVar9 - (int)pbVar5;
        iVar13 = *piVar8 - (int)pbVar5;
        iVar3 = iVar14;
        do {
          bVar1 = pbVar5[iVar13];
          bVar2 = *pbVar5;
          uVar10 = (uint)pbVar5[iVar12];
          *puVar11 = *(undefined1 *)(*(int *)((uint)bVar1 * 4 + iVar16) + uVar10 + iVar15);
          puVar11[1] = *(undefined1 *)
                        ((*(int *)((uint)bVar2 * 4 + iVar7) + *(int *)((uint)bVar1 * 4 + iVar18) >>
                         0x10) + uVar10 + iVar15);
          pbVar5 = pbVar5 + 1;
          puVar11[2] = *(undefined1 *)(*(int *)((uint)bVar2 * 4 + iVar17) + uVar10 + iVar15);
          puVar11 = puVar11 + 3;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      iVar6 = iVar6 + -1;
    } while (-1 < iVar6);
  }
  return;
}



/* 404b8890 FUN_404b8890 */

/* Boundary evidence: original MIPS .pdata 404b8890..404b88d3. Semantic name remains unreviewed. */

void FUN_404b8890(int param_1,int *param_2,int param_3,int param_4,int param_5)

{
  FUN_404b2f80(*param_2,param_3,param_4,0,param_5,*(size_t *)(param_1 + 0x70));
  return;
}



/* 404b8940 FUN_404b8940 */

/* Boundary evidence: original MIPS .pdata 404b8940..404b8adf. Semantic name remains unreviewed. */

void FUN_404b8940(int param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  byte *pbVar13;
  undefined1 *puVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  
  iVar6 = *(int *)(param_1 + 0x1cc);
  iVar9 = *(int *)(iVar6 + 0x10);
  iVar20 = *(int *)(iVar6 + 8);
  iVar21 = *(int *)(iVar6 + 0xc);
  iVar7 = *(int *)(iVar6 + 0x14);
  iVar18 = *(int *)(param_1 + 0x70);
  iVar19 = *(int *)(param_1 + 0x148);
  iVar6 = param_5 + -1;
  if (-1 < iVar6) {
    iVar4 = param_3 << 2;
    do {
      piVar10 = (int *)(*param_2 + iVar4);
      piVar8 = (int *)(param_2[2] + iVar4);
      piVar12 = (int *)(iVar4 + param_2[3]);
      pbVar3 = *(byte **)(iVar4 + param_2[1]);
      puVar14 = (undefined1 *)*param_4;
      iVar4 = iVar4 + 4;
      param_4 = param_4 + 1;
      if (iVar18 != 0) {
        iVar15 = *piVar10 - (int)pbVar3;
        iVar16 = *piVar8 - (int)pbVar3;
        iVar17 = *piVar12 - (int)pbVar3;
        iVar5 = iVar18;
        do {
          bVar1 = pbVar3[iVar16];
          bVar2 = *pbVar3;
          uVar11 = (uint)pbVar3[iVar15];
          *puVar14 = *(undefined1 *)
                      (((iVar19 - *(int *)((uint)bVar1 * 4 + iVar20)) - uVar11) + 0xff);
          puVar14[1] = *(undefined1 *)
                        (((iVar19 - (*(int *)((uint)bVar2 * 4 + iVar7) +
                                     *(int *)((uint)bVar1 * 4 + iVar9) >> 0x10)) - uVar11) + 0xff);
          pbVar13 = pbVar3 + iVar17;
          puVar14[2] = *(undefined1 *)
                        (((iVar19 - *(int *)((uint)bVar2 * 4 + iVar21)) - uVar11) + 0xff);
          pbVar3 = pbVar3 + 1;
          puVar14[3] = *pbVar13;
          puVar14 = puVar14 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar6 = iVar6 + -1;
    } while (-1 < iVar6);
  }
  return;
}



/* 404b8ae0 FUN_404b8ae0 */

/* Boundary evidence: original MIPS .pdata 404b8ae0..404b90f7. Semantic name remains unreviewed. */

void FUN_404b8ae0(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar13 = *(int *)(param_1 + 0x1cc);
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar13 + 0x18) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar13 + 0x1c) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar13 + 0x20) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar13 + 0x24) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar13 + 0x28) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar13 + 0x2c) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar13 + 0x30) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar13 + 0x34) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar13 + 0x38) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  iVar15 = 0;
  iVar11 = 0;
  iVar4 = -0x4a24e1;
  iVar16 = 0xfe81;
  iVar14 = -0x447a1;
  iVar17 = 0xfe81;
  *(undefined4 *)(iVar13 + 0x3c) = uVar2;
  iVar12 = -0x2153e1;
  iVar18 = 0xfe81;
  iVar5 = -0x569fe1;
  iVar19 = 0xfe81;
  iVar6 = -0x165be1;
  iVar21 = 0xfe81;
  iVar7 = -0x8f6e1;
  iVar8 = -0x1812a1;
  iVar3 = -0x4b5fe1;
  iVar20 = -0x41cfe1;
  local_34 = 0xfe81;
  local_38 = 0xfe81;
  local_30 = 0xfe81;
  do {
    bVar1 = 0xbf < iVar15;
    iVar9 = local_30;
    if (bVar1) {
      iVar9 = 0x57c0 - iVar20 / 0x3f;
    }
    *(int *)(iVar11 + *(int *)(iVar13 + 0x18)) = iVar9;
    iVar9 = local_38;
    if (bVar1) {
      iVar9 = 0x6480 - iVar3 / 0x3f;
    }
    *(int *)(*(int *)(iVar13 + 0x1c) + iVar11) = iVar9;
    puVar10 = (uint *)(*(int *)(iVar13 + 0x1c) + iVar11);
    *puVar10 = *puVar10 * 0x10101 >> 0x10;
    iVar9 = local_34;
    if (bVar1) {
      iVar9 = 0xb880 - iVar8 / 0x3f;
    }
    *(int *)(iVar11 + *(int *)(iVar13 + 0x20)) = iVar9;
    puVar10 = (uint *)(iVar11 + *(int *)(iVar13 + 0x20));
    *puVar10 = *puVar10 * 0x10101 >> 0x10;
    if (bVar1) {
      iVar9 = 0xff00 - iVar7 / 0x3f;
    }
    else {
      iVar9 = 0xfe81;
    }
    *(int *)(*(int *)(iVar13 + 0x24) + iVar11) = iVar9;
    puVar10 = (uint *)(*(int *)(iVar13 + 0x24) + iVar11);
    *puVar10 = *puVar10 * 0x10101 >> 0x10;
    iVar9 = iVar21;
    if (bVar1) {
      iVar9 = 0xed00 - iVar6 / 0x3f;
    }
    *(int *)(iVar11 + *(int *)(iVar13 + 0x28)) = iVar9;
    puVar10 = (uint *)(iVar11 + *(int *)(iVar13 + 0x28));
    *puVar10 = *puVar10 * 0x10101 >> 0x10;
    iVar9 = iVar19;
    if (bVar1) {
      iVar9 = 0x7380 - iVar5 / 0x3f;
    }
    *(int *)(*(int *)(iVar13 + 0x2c) + iVar11) = iVar9;
    puVar10 = (uint *)(*(int *)(iVar13 + 0x2c) + iVar11);
    *puVar10 = *puVar10 * 0x10101 >> 0x10;
    iVar9 = iVar18;
    if (bVar1) {
      iVar9 = 0x9c00 - iVar12 / 0x3f;
    }
    *(int *)(iVar11 + *(int *)(iVar13 + 0x30)) = iVar9;
    puVar10 = (uint *)(iVar11 + *(int *)(iVar13 + 0x30));
    *puVar10 = *puVar10 * 0x10101 >> 0x10;
    if (bVar1) {
      uVar2 = 0xff00;
    }
    else {
      uVar2 = 0xfe81;
    }
    *(undefined4 *)(*(int *)(iVar13 + 0x34) + iVar11) = uVar2;
    puVar10 = (uint *)(*(int *)(iVar13 + 0x34) + iVar11);
    *puVar10 = *puVar10 * 0x10101 >> 0x10;
    iVar9 = iVar17;
    if (bVar1) {
      iVar9 = 0xf9c0 - iVar14 / 0x3f;
    }
    *(int *)(iVar11 + *(int *)(iVar13 + 0x38)) = iVar9;
    puVar10 = (uint *)(iVar11 + *(int *)(iVar13 + 0x38));
    *puVar10 = *puVar10 * 0x10101 >> 0x10;
    iVar9 = iVar16;
    if (bVar1) {
      iVar9 = 0x7ec0 - iVar4 / 0x3f;
    }
    *(int *)(*(int *)(iVar13 + 0x3c) + iVar11) = iVar9;
    puVar10 = (uint *)(*(int *)(iVar13 + 0x3c) + iVar11);
    iVar20 = iVar20 + 0x57c0;
    local_30 = local_30 + -0xdf;
    iVar15 = iVar15 + 1;
    iVar3 = iVar3 + 0x6480;
    iVar8 = iVar8 + 0x2019;
    iVar7 = iVar7 + 0xbf4;
    iVar6 = iVar6 + 0x1dd0;
    local_38 = local_38 + -0xce;
    local_34 = local_34 + -0x5e;
    iVar5 = iVar5 + 0x7380;
    iVar12 = iVar12 + 0x2c70;
    iVar14 = iVar14 + 0x5b5;
    iVar4 = iVar4 + 0x62dc;
    *puVar10 = *puVar10 * 0x10101 >> 0x10;
    iVar21 = iVar21 + -0x18;
    iVar19 = iVar19 + -0xba;
    iVar18 = iVar18 + -0x84;
    iVar17 = iVar17 + -7;
    iVar16 = iVar16 + -0xab;
    iVar11 = iVar11 + 4;
  } while (iVar20 < 0x159860);
  return;
}



/* 404b90f8 FUN_404b90f8 */

/* Boundary evidence: original MIPS .pdata 404b90f8..404b9393. Semantic name remains unreviewed. */

void FUN_404b90f8(int param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  undefined4 *puVar17;
  int iVar18;
  int iVar19;
  undefined1 *puVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  
  iVar5 = *(int *)(param_1 + 0x1cc);
  iVar8 = *(int *)(iVar5 + 0x20);
  iVar9 = *(int *)(iVar5 + 0x24);
  iVar10 = *(int *)(iVar5 + 0x28);
  iVar11 = *(int *)(iVar5 + 0x2c);
  iVar12 = *(int *)(iVar5 + 0x30);
  iVar13 = *(int *)(iVar5 + 0x34);
  iVar14 = *(int *)(iVar5 + 0x38);
  iVar24 = *(int *)(iVar5 + 0x18);
  iVar26 = *(int *)(iVar5 + 0x1c);
  iVar6 = *(int *)(iVar5 + 0x3c);
  iVar18 = *(int *)(param_1 + 0x70);
  iVar5 = param_5 + -1;
  if (-1 < iVar5) {
    iVar4 = param_3 << 2;
    do {
      piVar15 = (int *)(iVar4 + *param_2);
      puVar17 = (undefined4 *)(iVar4 + param_2[1]);
      piVar7 = (int *)(iVar4 + param_2[2]);
      piVar16 = (int *)(iVar4 + param_2[3]);
      puVar20 = (undefined1 *)*param_4;
      param_4 = param_4 + 1;
      iVar4 = iVar4 + 4;
      pbVar3 = (byte *)*puVar17;
      if (iVar18 != 0) {
        iVar21 = *piVar15 - (int)pbVar3;
        iVar22 = *piVar7 - (int)pbVar3;
        iVar23 = *piVar16 - (int)pbVar3;
        iVar19 = iVar18;
        do {
          iVar2 = (0xff - (uint)pbVar3[iVar21]) * 4;
          piVar7 = (int *)((0xff - (uint)pbVar3[iVar23]) * 4 + iVar24);
          iVar1 = (0xff - (uint)*pbVar3) * 4;
          iVar25 = (0xff - (uint)pbVar3[iVar22]) * 4;
          iVar19 = iVar19 + -1;
          *puVar20 = (char)((((uint)(*(int *)(iVar2 + iVar26) * *piVar7) >> 0x10) *
                             *(int *)(iVar1 + iVar10) >> 0x10) * *(int *)(iVar25 + iVar13) >> 0x18);
          puVar20[1] = (char)((((uint)(*(int *)(iVar1 + iVar11) * *piVar7) >> 0x10) *
                               *(int *)(iVar25 + iVar14) >> 0x10) * *(int *)(iVar2 + iVar8) >> 0x18)
          ;
          pbVar3 = pbVar3 + 1;
          puVar20[2] = (char)((((uint)(*(int *)(iVar25 + iVar6) * *piVar7) >> 0x10) *
                               *(int *)(iVar2 + iVar9) >> 0x10) * *(int *)(iVar1 + iVar12) >> 0x18);
          puVar20 = puVar20 + 3;
        } while (iVar19 != 0);
      }
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
  }
  return;
}



/* 404b9394 FUN_404b9394 */

/* Boundary evidence: original MIPS .pdata 404b9394..404b96db. Semantic name remains unreviewed. */

void FUN_404b9394(int param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int *piVar20;
  uint uVar21;
  int *piVar22;
  undefined4 *puVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  undefined1 *puVar32;
  
  iVar6 = *(int *)(param_1 + 0x1cc);
  iVar8 = *(int *)(iVar6 + 0x18);
  iVar9 = *(int *)(iVar6 + 0x1c);
  iVar10 = *(int *)(iVar6 + 0x20);
  iVar11 = *(int *)(iVar6 + 0x24);
  iVar12 = *(int *)(iVar6 + 0x28);
  iVar13 = *(int *)(iVar6 + 0x2c);
  iVar14 = *(int *)(iVar6 + 0x30);
  iVar15 = *(int *)(iVar6 + 0x34);
  iVar16 = *(int *)(iVar6 + 0x38);
  iVar17 = *(int *)(iVar6 + 0x3c);
  iVar18 = *(int *)(iVar6 + 0xc);
  iVar31 = *(int *)(iVar6 + 8);
  iVar1 = *(int *)(iVar6 + 0x10);
  iVar6 = *(int *)(iVar6 + 0x14);
  iVar26 = *(int *)(param_1 + 0x70);
  iVar19 = *(int *)(param_1 + 0x148);
  iVar25 = param_5 + -1;
  if (-1 < iVar25) {
    iVar3 = param_3 << 2;
    do {
      piVar20 = (int *)(iVar3 + *param_2);
      puVar23 = (undefined4 *)(param_2[1] + iVar3);
      piVar7 = (int *)(iVar3 + param_2[2]);
      piVar22 = (int *)(param_2[3] + iVar3);
      puVar32 = (undefined1 *)*param_4;
      param_4 = param_4 + 1;
      iVar3 = iVar3 + 4;
      pbVar2 = (byte *)*puVar23;
      if (iVar26 != 0) {
        iVar28 = *piVar20 - (int)pbVar2;
        iVar29 = *piVar7 - (int)pbVar2;
        iVar30 = *piVar22 - (int)pbVar2;
        iVar27 = iVar26;
        do {
          uVar21 = (uint)pbVar2[iVar28];
          iVar5 = (uint)*(byte *)(*(int *)((uint)pbVar2[iVar29] * 4 + iVar31) + uVar21 + iVar19) * 4
          ;
          piVar7 = (int *)((0xff - (uint)pbVar2[iVar30]) * 4 + iVar8);
          iVar4 = (uint)*(byte *)((*(int *)((uint)*pbVar2 * 4 + iVar6) +
                                   *(int *)((uint)pbVar2[iVar29] * 4 + iVar1) >> 0x10) + uVar21 +
                                 iVar19) * 4;
          iVar24 = (uint)*(byte *)(*(int *)((uint)*pbVar2 * 4 + iVar18) + uVar21 + iVar19) * 4;
          *puVar32 = (char)((((uint)(*(int *)(iVar5 + iVar9) * *piVar7) >> 0x10) *
                             *(int *)(iVar4 + iVar12) >> 0x10) * *(int *)(iVar24 + iVar15) >> 0x18);
          puVar32[1] = (char)((((uint)(*(int *)(iVar4 + iVar13) * *piVar7) >> 0x10) *
                               *(int *)(iVar24 + iVar16) >> 0x10) * *(int *)(iVar5 + iVar10) >> 0x18
                             );
          iVar27 = iVar27 + -1;
          pbVar2 = pbVar2 + 1;
          puVar32[2] = (char)((((uint)(*(int *)(iVar24 + iVar17) * *piVar7) >> 0x10) *
                               *(int *)(iVar5 + iVar11) >> 0x10) * *(int *)(iVar4 + iVar14) >> 0x18)
          ;
          puVar32 = puVar32 + 3;
        } while (iVar27 != 0);
      }
      iVar25 = iVar25 + -1;
    } while (-1 < iVar25);
  }
  return;
}



/* 404b96dc FUN_404b96dc */

/* Boundary evidence: original MIPS .pdata 404b96dc..404b9a2f. Semantic name remains unreviewed. */

void FUN_404b96dc(int *param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x40);
  param_1[0x73] = (int)puVar1;
  *puVar1 = FUN_4049d5c4;
  switch(param_1[10]) {
  case 1:
    if (param_1[9] != 1) {
      *(undefined4 *)(*param_1 + 0x14) = 10;
      pcVar2 = *(code **)*param_1;
LAB_404b9810:
      (*pcVar2)(param_1);
    }
    break;
  case 2:
  case 3:
    if (param_1[9] != 3) {
      *(undefined4 *)(*param_1 + 0x14) = 10;
      (**(code **)*param_1)(param_1);
    }
    break;
  case 4:
  case 5:
    if (param_1[9] != 4) {
      *(undefined4 *)(*param_1 + 0x14) = 10;
      (**(code **)*param_1)(param_1);
    }
    break;
  default:
    if (param_1[9] < 1) {
      *(undefined4 *)(*param_1 + 0x14) = 10;
      pcVar2 = *(code **)*param_1;
      goto LAB_404b9810;
    }
  }
  iVar4 = param_1[0xb];
  iVar3 = param_1[10];
  if (iVar4 == 1) {
    param_1[0x1e] = 1;
    if ((iVar3 == 1) || (iVar3 == 3)) {
      puVar1[1] = FUN_404b8890;
      iVar3 = 1;
      if (1 < param_1[9]) {
        iVar4 = 0x54;
        do {
          *(undefined4 *)(iVar4 + param_1[0x37] + 0x30) = 0;
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x54;
        } while (iVar3 < param_1[9]);
      }
      goto LAB_404b99f4;
    }
  }
  else {
    if (iVar4 == 2) {
      param_1[0x1e] = 3;
      if (iVar3 == 3) {
        puVar1[1] = FUN_404b869c;
        FUN_404b856c((int)param_1);
      }
      else if (iVar3 == 1) {
        puVar1[1] = &LAB_404b88d4;
      }
      else if (iVar3 == 2) {
        puVar1[1] = &LAB_404b8810;
      }
      else if (iVar3 == 4) {
        puVar1[1] = FUN_404b90f8;
        FUN_404b8ae0((int)param_1);
      }
      else if (iVar3 == 5) {
        puVar1[1] = FUN_404b9394;
        FUN_404b856c((int)param_1);
        FUN_404b8ae0((int)param_1);
      }
      else {
        *(undefined4 *)(*param_1 + 0x14) = 0x1b;
        (**(code **)*param_1)();
      }
      goto LAB_404b99f4;
    }
    if (iVar4 == 4) {
      param_1[0x1e] = 4;
      if (iVar3 == 5) {
        puVar1[1] = FUN_404b8940;
        FUN_404b856c((int)param_1);
      }
      else if (iVar3 == 4) {
        puVar1[1] = &LAB_404b8810;
      }
      else {
        *(undefined4 *)(*param_1 + 0x14) = 0x1b;
        (**(code **)*param_1)(param_1);
      }
      goto LAB_404b99f4;
    }
    if (iVar4 == iVar3) {
      param_1[0x1e] = param_1[9];
      puVar1[1] = &LAB_404b8810;
      goto LAB_404b99f4;
    }
  }
  *(undefined4 *)(*param_1 + 0x14) = 0x1b;
  (**(code **)*param_1)(param_1);
LAB_404b99f4:
  if (param_1[0x15] == 0) {
    param_1[0x1f] = param_1[0x1e];
  }
  else {
    param_1[0x1f] = 1;
  }
  return;
}



/* 404b9a30 FUN_404b9a30 */

/* Boundary evidence: original MIPS .pdata 404b9a30..404b9b5f. Semantic name remains unreviewed. */

void FUN_404b9a30(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = *(int *)(param_1 + 0x1c8);
  uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar5 + 0x10) = uVar1;
  uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar5 + 0x14) = uVar1;
  uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar5 + 0x18) = uVar1;
  uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x400);
  *(undefined4 *)(iVar5 + 0x1c) = uVar1;
  iVar3 = 0;
  iVar6 = 0x5b6900;
  iVar7 = -0xe25100;
  iVar2 = -0xb2f480;
  iVar4 = 0x2c8d00;
  do {
    *(int *)(iVar3 + *(int *)(iVar5 + 0x10)) = iVar2 >> 0x10;
    *(int *)(*(int *)(iVar5 + 0x14) + iVar3) = iVar7 >> 0x10;
    *(int *)(iVar3 + *(int *)(iVar5 + 0x18)) = iVar6;
    *(int *)(*(int *)(iVar5 + 0x1c) + iVar3) = iVar4;
    iVar4 = iVar4 + -0x581a;
    iVar2 = iVar2 + 0x166e9;
    iVar7 = iVar7 + 0x1c5a2;
    iVar6 = iVar6 + -0xb6d2;
    iVar3 = iVar3 + 4;
  } while (-0x2b34e7 < iVar4);
  return;
}



/* 404b9b74 FUN_404b9b74 */

/* Boundary evidence: original MIPS .pdata 404b9b74..404b9c9b. Semantic name remains unreviewed. */

void FUN_404b9b74(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,int param_5,
                 int *param_6,int param_7)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar3 = *(int *)(param_1 + 0x1c8);
  if (*(int *)(iVar3 + 0x24) == 0) {
    uVar4 = 2;
    if (*(uint *)(iVar3 + 0x2c) < 2) {
      uVar4 = *(uint *)(iVar3 + 0x2c);
    }
    uVar1 = param_7 - *param_6;
    if (uVar1 < uVar4) {
      uVar4 = uVar1;
    }
    puVar2 = (undefined4 *)(*param_6 * 4 + param_5);
    local_20 = *puVar2;
    if (uVar4 < 2) {
      local_1c = *(undefined4 *)(iVar3 + 0x20);
      *(undefined4 *)(iVar3 + 0x24) = 1;
    }
    else {
      local_1c = puVar2[1];
    }
    (**(code **)(iVar3 + 0xc))(param_1,param_2,*param_3,&local_20);
  }
  else {
    uVar4 = 1;
    FUN_404b2f80(iVar3 + 0x20,0,*param_6 * 4 + param_5,0,1,*(size_t *)(iVar3 + 0x28));
    *(undefined4 *)(iVar3 + 0x24) = 0;
  }
  *param_6 = *param_6 + uVar4;
  *(uint *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) - uVar4;
  if (*(int *)(iVar3 + 0x24) == 0) {
    *param_3 = *param_3 + 1;
  }
  return;
}



/* 404b9c9c FUN_404b9c9c */

/* Boundary evidence: original MIPS .pdata 404b9c9c..404b9cff. Semantic name remains unreviewed. */

void FUN_404b9c9c(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,int param_5,
                 int *param_6)

{
  (**(code **)(*(int *)(param_1 + 0x1c8) + 0xc))(param_1,param_2,*param_3,*param_6 * 4 + param_5);
  *param_6 = *param_6 + 1;
  *param_3 = *param_3 + 1;
  return;
}



/* 404b9d00 FUN_404b9d00 */

/* Boundary evidence: original MIPS .pdata 404b9d00..404b9eeb. Semantic name remains unreviewed. */

void FUN_404b9d00(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  byte *pbVar14;
  
  iVar5 = *(int *)(param_1 + 0x1c8);
  iVar7 = param_3 * 4;
  iVar10 = *(int *)(iVar5 + 0x10);
  iVar11 = *(int *)(iVar5 + 0x14);
  iVar12 = *(int *)(iVar5 + 0x18);
  iVar13 = *(int *)(iVar5 + 0x1c);
  pbVar14 = *(byte **)(*param_2 + iVar7);
  iVar5 = *(int *)(param_1 + 0x148);
  pbVar8 = *(byte **)(param_2[1] + iVar7);
  pbVar9 = *(byte **)(param_2[2] + iVar7);
  puVar1 = (undefined1 *)*param_4;
  for (uVar3 = *(uint *)(param_1 + 0x70) >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
    iVar4 = *(int *)((uint)*pbVar9 * 4 + iVar10);
    uVar6 = (uint)*pbVar14;
    iVar2 = *(int *)((uint)*pbVar8 * 4 + iVar13) + *(int *)((uint)*pbVar9 * 4 + iVar12) >> 0x10;
    iVar7 = *(int *)((uint)*pbVar8 * 4 + iVar11);
    *puVar1 = *(undefined1 *)(uVar6 + iVar4 + iVar5);
    puVar1[1] = *(undefined1 *)(uVar6 + iVar2 + iVar5);
    puVar1[2] = *(undefined1 *)(uVar6 + iVar7 + iVar5);
    uVar6 = (uint)pbVar14[1];
    puVar1[3] = *(undefined1 *)(uVar6 + iVar4 + iVar5);
    puVar1[4] = *(undefined1 *)(uVar6 + iVar2 + iVar5);
    pbVar8 = pbVar8 + 1;
    pbVar9 = pbVar9 + 1;
    pbVar14 = pbVar14 + 2;
    puVar1[5] = *(undefined1 *)(uVar6 + iVar7 + iVar5);
    puVar1 = puVar1 + 6;
  }
  if ((*(uint *)(param_1 + 0x70) & 1) != 0) {
    iVar13 = *(int *)((uint)*pbVar8 * 4 + iVar13);
    iVar12 = *(int *)((uint)*pbVar9 * 4 + iVar12);
    uVar3 = (uint)*pbVar14;
    iVar7 = *(int *)((uint)*pbVar8 * 4 + iVar11);
    *puVar1 = *(undefined1 *)(*(int *)((uint)*pbVar9 * 4 + iVar10) + uVar3 + iVar5);
    puVar1[1] = *(undefined1 *)(uVar3 + (iVar13 + iVar12 >> 0x10) + iVar5);
    puVar1[2] = *(undefined1 *)(uVar3 + iVar7 + iVar5);
  }
  return;
}



/* 404b9eec FUN_404b9eec */

/* Boundary evidence: original MIPS .pdata 404b9eec..404ba1d3. Semantic name remains unreviewed. */

void FUN_404b9eec(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  byte *pbVar16;
  int iVar17;
  
  iVar6 = *(int *)(param_1 + 0x1c8);
  iVar13 = *(int *)(iVar6 + 0x10);
  iVar14 = *(int *)(iVar6 + 0x14);
  iVar15 = *(int *)(iVar6 + 0x18);
  iVar17 = *(int *)(iVar6 + 0x1c);
  iVar6 = *(int *)(param_1 + 0x148);
  puVar7 = (undefined4 *)(param_3 * 8 + *param_2);
  pbVar16 = (byte *)*puVar7;
  pbVar2 = (byte *)puVar7[1];
  pbVar11 = *(byte **)(param_2[1] + param_3 * 4);
  pbVar12 = *(byte **)(param_2[2] + param_3 * 4);
  puVar3 = (undefined1 *)*param_4;
  puVar9 = (undefined1 *)param_4[1];
  for (uVar10 = *(uint *)(param_1 + 0x70) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
    iVar4 = *(int *)((uint)*pbVar12 * 4 + iVar13);
    uVar8 = (uint)*pbVar16;
    iVar1 = *(int *)((uint)*pbVar11 * 4 + iVar17) + *(int *)((uint)*pbVar12 * 4 + iVar15) >> 0x10;
    iVar5 = *(int *)((uint)*pbVar11 * 4 + iVar14);
    *puVar3 = *(undefined1 *)(uVar8 + iVar4 + iVar6);
    puVar3[1] = *(undefined1 *)(uVar8 + iVar1 + iVar6);
    puVar3[2] = *(undefined1 *)(uVar8 + iVar5 + iVar6);
    uVar8 = (uint)pbVar16[1];
    puVar3[3] = *(undefined1 *)(uVar8 + iVar4 + iVar6);
    puVar3[4] = *(undefined1 *)(uVar8 + iVar1 + iVar6);
    pbVar16 = pbVar16 + 2;
    puVar3[5] = *(undefined1 *)(uVar8 + iVar5 + iVar6);
    uVar8 = (uint)*pbVar2;
    *puVar9 = *(undefined1 *)(uVar8 + iVar4 + iVar6);
    puVar9[1] = *(undefined1 *)(uVar8 + iVar1 + iVar6);
    puVar9[2] = *(undefined1 *)(uVar8 + iVar5 + iVar6);
    uVar8 = (uint)pbVar2[1];
    puVar3 = puVar3 + 6;
    puVar9[3] = *(undefined1 *)(uVar8 + iVar4 + iVar6);
    puVar9[4] = *(undefined1 *)(uVar8 + iVar1 + iVar6);
    pbVar11 = pbVar11 + 1;
    pbVar12 = pbVar12 + 1;
    pbVar2 = pbVar2 + 2;
    puVar9[5] = *(undefined1 *)(uVar8 + iVar5 + iVar6);
    puVar9 = puVar9 + 6;
  }
  if ((*(uint *)(param_1 + 0x70) & 1) != 0) {
    iVar13 = *(int *)((uint)*pbVar12 * 4 + iVar13);
    uVar10 = (uint)*pbVar16;
    iVar15 = *(int *)((uint)*pbVar11 * 4 + iVar17) + *(int *)((uint)*pbVar12 * 4 + iVar15) >> 0x10;
    iVar14 = *(int *)((uint)*pbVar11 * 4 + iVar14);
    *puVar3 = *(undefined1 *)(uVar10 + iVar13 + iVar6);
    puVar3[1] = *(undefined1 *)(uVar10 + iVar15 + iVar6);
    puVar3[2] = *(undefined1 *)(uVar10 + iVar14 + iVar6);
    uVar10 = (uint)*pbVar2;
    *puVar9 = *(undefined1 *)(uVar10 + iVar13 + iVar6);
    puVar9[1] = *(undefined1 *)(uVar10 + iVar15 + iVar6);
    puVar9[2] = *(undefined1 *)(uVar10 + iVar14 + iVar6);
  }
  return;
}



/* 404ba1d4 FUN_404ba1d4 */

/* Boundary evidence: original MIPS .pdata 404ba1d4..404ba1ef. Semantic name remains unreviewed. */

void FUN_404ba1d4(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  FUN_404b9eec(param_1,param_2,param_3,param_4);
  return;
}



/* 404ba1f0 FUN_404ba1f0 */

/* Boundary evidence: original MIPS .pdata 404ba1f0..404ba2c7. Semantic name remains unreviewed. */

void FUN_404ba1f0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x30);
  *(undefined4 **)(param_1 + 0x1c8) = puVar1;
  *puVar1 = &LAB_404b9b60;
  puVar1[2] = 0;
  puVar1[10] = *(int *)(param_1 + 0x78) * *(int *)(param_1 + 0x70);
  if (*(int *)(param_1 + 0x13c) == 2) {
    puVar1[1] = FUN_404b9b74;
    puVar1[3] = FUN_404ba1d4;
    uVar2 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,puVar1[10]);
    puVar1[8] = uVar2;
  }
  else {
    puVar1[1] = FUN_404b9c9c;
    puVar1[3] = FUN_404b9d00;
    puVar1[8] = 0;
  }
  FUN_404b9a30(param_1);
  return;
}



/* 404ba2c8 FUN_404ba2c8 */

/* Boundary evidence: original MIPS .pdata 404ba2c8..404ba783. Semantic name remains unreviewed. */

void FUN_404ba2c8(int param_1,int param_2,int param_3,int *param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  short *psVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  int iVar11;
  int iVar12;
  int local_a8 [16];
  int local_68 [8];
  int local_48 [8];
  
  iVar11 = *(int *)(param_1 + 0x148) + 0x80;
  psVar10 = *(short **)(param_2 + 0x50);
  psVar3 = (short *)(param_3 + 0x10);
  piVar4 = local_a8;
  iVar6 = 8;
  iVar9 = 4;
  do {
    if (iVar6 != 4) {
      if ((((*psVar3 == 0) && (psVar3[8] == 0)) && (psVar3[0x10] == 0)) &&
         (((psVar3[0x20] == 0 && (psVar3[0x28] == 0)) && (psVar3[0x30] == 0)))) {
        iVar7 = (int)psVar3[-8] * (int)*psVar10 * 4;
        *piVar4 = iVar7;
        piVar4[8] = iVar7;
        piVar4[0x10] = iVar7;
        piVar4[0x18] = iVar7;
      }
      else {
        iVar7 = (int)psVar3[-8] * (int)*psVar10 * 0x4000;
        iVar12 = (int)psVar10[0x10] * (int)psVar3[8] * 0x3b21 +
                 (int)psVar10[0x30] * (int)psVar3[0x28] * -0x187e;
        iVar2 = iVar7 - iVar12;
        iVar12 = iVar12 + iVar7;
        iVar7 = (int)psVar10[8] * (int)*psVar3;
        iVar8 = (int)psVar10[0x28] * (int)psVar3[0x20] * 0x2e75 +
                (int)psVar10[0x18] * (int)psVar3[0x10] * -0x4587 + iVar7 * 0x21f9 +
                (int)psVar10[0x38] * (int)psVar3[0x30] * -0x6c2;
        iVar7 = iVar7 * 0x5203 + (int)psVar10[0x18] * (int)psVar3[0x10] * 0x1ccd +
                (int)psVar10[0x28] * (int)psVar3[0x20] * -0x133e +
                (int)psVar10[0x38] * (int)psVar3[0x30] * -0x1050;
        *piVar4 = iVar12 + iVar7 + 0x800 >> 0xc;
        piVar4[0x18] = (iVar12 - iVar7) + 0x800 >> 0xc;
        piVar4[8] = iVar2 + iVar8 + 0x800 >> 0xc;
        piVar4[0x10] = (iVar2 - iVar8) + 0x800 >> 0xc;
      }
    }
    psVar10 = psVar10 + 1;
    psVar3 = psVar3 + 1;
    iVar6 = iVar6 + -1;
    piVar4 = piVar4 + 1;
  } while (0 < iVar6);
  piVar4 = local_a8;
  do {
    iVar6 = piVar4[1];
    puVar5 = (undefined1 *)(*param_4 + param_5);
    if (((iVar6 == 0) && (piVar4[2] == 0)) &&
       ((piVar4[3] == 0 && (((piVar4[5] == 0 && (piVar4[6] == 0)) && (piVar4[7] == 0)))))) {
      uVar1 = *(undefined1 *)((*piVar4 + 0x10 >> 5 & 0x3ffU) + iVar11);
      *puVar5 = uVar1;
      puVar5[1] = uVar1;
      puVar5[2] = uVar1;
      puVar5[3] = uVar1;
    }
    else {
      iVar7 = piVar4[2] * 0x3b21 + piVar4[6] * -0x187e;
      iVar2 = iVar7 + *piVar4 * 0x4000;
      iVar7 = *piVar4 * 0x4000 - iVar7;
      iVar12 = piVar4[5] * 0x2e75 + piVar4[3] * -0x4587 + iVar6 * 0x21f9 + piVar4[7] * -0x6c2;
      iVar6 = iVar6 * 0x5203 + piVar4[3] * 0x1ccd + piVar4[5] * -0x133e + piVar4[7] * -0x1050;
      *puVar5 = *(undefined1 *)((iVar2 + iVar6 + 0x40000 >> 0x13 & 0x3ffU) + iVar11);
      puVar5[3] = *(undefined1 *)(((iVar2 - iVar6) + 0x40000 >> 0x13 & 0x3ffU) + iVar11);
      puVar5[1] = *(undefined1 *)((iVar7 + iVar12 + 0x40000 >> 0x13 & 0x3ffU) + iVar11);
      puVar5[2] = *(undefined1 *)(((iVar7 - iVar12) + 0x40000 >> 0x13 & 0x3ffU) + iVar11);
    }
    param_4 = param_4 + 1;
    piVar4 = piVar4 + 8;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  return;
}



/* 404ba784 FUN_404ba784 */

/* Boundary evidence: original MIPS .pdata 404ba784..404baec7. Semantic name remains unreviewed. */

void FUN_404ba784(int param_1,int param_2,int param_3,int *param_4,int param_5)

{
  undefined1 uVar1;
  short *psVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  int *piVar10;
  int local_58 [7];
  int local_3c;
  int local_38 [7];
  int local_1c;
  
  piVar10 = local_58;
  psVar2 = *(short **)(param_2 + 0x50);
  psVar9 = (short *)(param_3 + 0x10);
  iVar8 = *(int *)(param_1 + 0x148) + 0x80;
  iVar4 = 8;
  do {
    if (((iVar4 != 6) && (iVar4 != 4)) && (iVar4 != 2)) {
      if (((*psVar9 == 0) && (psVar9[0x10] == 0)) && ((psVar9[0x20] == 0 && (psVar9[0x30] == 0)))) {
        iVar5 = (int)psVar9[-8] * (int)*psVar2 * 4;
        piVar10[8] = iVar5;
      }
      else {
        iVar7 = (int)psVar9[-8] * (int)*psVar2 * 0x8000;
        iVar6 = (int)psVar2[0x28] * (int)psVar9[0x20] * 0x1b37 +
                (int)psVar2[0x38] * (int)psVar9[0x30] * -0x1712 +
                (int)psVar2[0x18] * (int)psVar9[0x10] * -0x28ba +
                (int)psVar2[8] * (int)*psVar9 * 0x73fc;
        iVar5 = iVar6 + iVar7 + 0x1000 >> 0xd;
        piVar10[8] = (iVar7 - iVar6) + 0x1000 >> 0xd;
      }
      *piVar10 = iVar5;
    }
    if (((iVar4 != 7) && (iVar4 != 5)) && (iVar4 != 3)) {
      if ((((psVar9[1] == 0) && (psVar9[0x11] == 0)) && (psVar9[0x21] == 0)) && (psVar9[0x31] == 0))
      {
        iVar5 = (int)psVar9[-7] * (int)psVar2[1] * 4;
        piVar10[9] = iVar5;
      }
      else {
        iVar7 = (int)psVar2[1] * (int)psVar9[-7] * 0x8000;
        iVar6 = (int)psVar2[0x29] * (int)psVar9[0x21] * 0x1b37 +
                (int)psVar2[0x39] * (int)psVar9[0x31] * -0x1712 +
                (int)psVar2[0x19] * (int)psVar9[0x11] * -0x28ba +
                (int)psVar2[9] * (int)psVar9[1] * 0x73fc;
        iVar5 = iVar6 + iVar7 + 0x1000 >> 0xd;
        piVar10[9] = (iVar7 - iVar6) + 0x1000 >> 0xd;
      }
      piVar10[1] = iVar5;
    }
    if (((iVar4 != 8) && (iVar4 != 6)) && (iVar4 != 4)) {
      if (((psVar9[2] == 0) && (psVar9[0x12] == 0)) && ((psVar9[0x22] == 0 && (psVar9[0x32] == 0))))
      {
        iVar5 = (int)psVar9[-6] * (int)psVar2[2] * 4;
        piVar10[10] = iVar5;
      }
      else {
        iVar7 = (int)psVar2[2] * (int)psVar9[-6] * 0x8000;
        iVar6 = (int)psVar2[0x2a] * (int)psVar9[0x22] * 0x1b37 +
                (int)psVar2[0x3a] * (int)psVar9[0x32] * -0x1712 +
                (int)psVar2[0x1a] * (int)psVar9[0x12] * -0x28ba +
                (int)psVar2[10] * (int)psVar9[2] * 0x73fc;
        iVar5 = iVar6 + iVar7 + 0x1000 >> 0xd;
        piVar10[10] = (iVar7 - iVar6) + 0x1000 >> 0xd;
      }
      piVar10[2] = iVar5;
    }
    if (((iVar4 != 9) && (iVar4 != 7)) && (iVar4 != 5)) {
      if (((psVar9[3] == 0) && (psVar9[0x13] == 0)) && ((psVar9[0x23] == 0 && (psVar9[0x33] == 0))))
      {
        iVar5 = (int)psVar9[-5] * (int)psVar2[3] * 4;
        piVar10[0xb] = iVar5;
      }
      else {
        iVar7 = (int)psVar2[3] * (int)psVar9[-5] * 0x8000;
        iVar6 = (int)psVar2[0x2b] * (int)psVar9[0x23] * 0x1b37 +
                (int)psVar2[0x3b] * (int)psVar9[0x33] * -0x1712 +
                (int)psVar2[0x1b] * (int)psVar9[0x13] * -0x28ba +
                (int)psVar2[0xb] * (int)psVar9[3] * 0x73fc;
        iVar5 = iVar6 + iVar7 + 0x1000 >> 0xd;
        piVar10[0xb] = (iVar7 - iVar6) + 0x1000 >> 0xd;
      }
      piVar10[3] = iVar5;
    }
    iVar4 = iVar4 + -4;
    psVar9 = psVar9 + 4;
    psVar2 = psVar2 + 4;
    piVar10 = piVar10 + 4;
  } while (0 < iVar4);
  puVar3 = (undefined1 *)(*param_4 + param_5);
  if (((local_58[1] == 0) && (local_58[3] == 0)) && ((local_58[5] == 0 && (local_3c == 0)))) {
    uVar1 = *(undefined1 *)((local_58[0] + 0x10 >> 5 & 0x3ffU) + iVar8);
    *puVar3 = uVar1;
    puVar3[1] = uVar1;
  }
  else {
    iVar4 = local_58[1] * 0x73fc + local_58[3] * -0x28ba + local_58[5] * 0x1b37 + local_3c * -0x1712
    ;
    *puVar3 = *(undefined1 *)((iVar4 + local_58[0] * 0x8000 + 0x80000 >> 0x14 & 0x3ffU) + iVar8);
    puVar3[1] = *(undefined1 *)(((local_58[0] * 0x8000 - iVar4) + 0x80000 >> 0x14 & 0x3ffU) + iVar8)
    ;
  }
  puVar3 = (undefined1 *)(param_4[1] + param_5);
  if ((((local_38[1] == 0) && (local_38[3] == 0)) && (local_38[5] == 0)) && (local_1c == 0)) {
    uVar1 = *(undefined1 *)((local_38[0] + 0x10 >> 5 & 0x3ffU) + iVar8);
    *puVar3 = uVar1;
    puVar3[1] = uVar1;
  }
  else {
    iVar4 = local_38[5] * 0x1b37 + local_38[1] * 0x73fc + local_1c * -0x1712 + local_38[3] * -0x28ba
    ;
    *puVar3 = *(undefined1 *)((iVar4 + local_38[0] * 0x8000 + 0x80000 >> 0x14 & 0x3ffU) + iVar8);
    puVar3[1] = *(undefined1 *)(((local_38[0] * 0x8000 - iVar4) + 0x80000 >> 0x14 & 0x3ffU) + iVar8)
    ;
  }
  return;
}



/* 404baf08 FUN_404baf08 */

/* Boundary evidence: original MIPS .pdata 404baf08..404bb587. Semantic name remains unreviewed. */

void FUN_404baf08(int param_1,int param_2,short *param_3,int *param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined1 *puVar14;
  short *psVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int local_134;
  int local_128 [16];
  int local_e8 [8];
  int local_c8 [8];
  int local_a8 [8];
  int local_88 [8];
  int local_68 [8];
  int local_48 [8];
  
  iVar5 = *(int *)(param_1 + 0x148) + 0x80;
  psVar15 = *(short **)(param_2 + 0x50);
  iVar16 = 8;
  local_134 = 8;
  piVar13 = local_128;
  do {
    if ((((param_3[8] == 0) && (param_3[0x10] == 0)) && (param_3[0x18] == 0)) &&
       (((param_3[0x20] == 0 && (param_3[0x28] == 0)) &&
        ((param_3[0x30] == 0 && (param_3[0x38] == 0)))))) {
      iVar6 = (int)*param_3 * (int)*psVar15 * 4;
      *piVar13 = iVar6;
      piVar13[8] = iVar6;
      piVar13[0x10] = iVar6;
      piVar13[0x18] = iVar6;
      piVar13[0x20] = iVar6;
      piVar13[0x28] = iVar6;
      piVar13[0x30] = iVar6;
      piVar13[0x38] = iVar6;
    }
    else {
      iVar6 = ((int)psVar15[0x30] * (int)param_3[0x30] + (int)psVar15[0x10] * (int)param_3[0x10]) *
              0x1151;
      iVar18 = iVar6 + (int)psVar15[0x30] * (int)param_3[0x30] * -0x3b21;
      iVar6 = (int)psVar15[0x10] * (int)param_3[0x10] * 0x187e + iVar6;
      iVar8 = ((int)psVar15[0x20] * (int)param_3[0x20] + (int)*param_3 * (int)*psVar15) * 0x2000;
      iVar10 = (int)psVar15[0x38] * (int)param_3[0x38];
      iVar9 = ((int)*param_3 * (int)*psVar15 - (int)psVar15[0x20] * (int)param_3[0x20]) * 0x2000;
      iVar7 = iVar8 + iVar6;
      iVar8 = iVar8 - iVar6;
      iVar11 = iVar9 + iVar18;
      iVar9 = iVar9 - iVar18;
      iVar6 = (int)psVar15[0x28] * (int)param_3[0x28];
      iVar18 = (int)psVar15[0x18] * (int)param_3[0x18];
      iVar2 = (int)psVar15[8] * (int)param_3[8];
      iVar3 = (iVar6 + iVar2 + iVar10 + iVar18) * 0x25a1;
      iVar17 = (iVar10 + iVar2) * -0x1ccd;
      iVar4 = (iVar6 + iVar18) * -0x5203;
      iVar12 = iVar3 + (iVar10 + iVar18) * -0x3ec5;
      iVar3 = iVar3 + (iVar6 + iVar2) * -0xc7c;
      iVar10 = iVar10 * 0x98e + iVar17 + iVar12;
      iVar6 = iVar6 * 0x41b3 + iVar3 + iVar4;
      iVar4 = iVar18 * 0x6254 + iVar12 + iVar4;
      iVar17 = iVar2 * 0x300b + iVar3 + iVar17;
      *piVar13 = iVar7 + iVar17 + 0x400 >> 0xb;
      piVar13[0x38] = (iVar7 - iVar17) + 0x400 >> 0xb;
      piVar13[8] = iVar11 + iVar4 + 0x400 >> 0xb;
      piVar13[0x30] = (iVar11 - iVar4) + 0x400 >> 0xb;
      piVar13[0x10] = iVar9 + iVar6 + 0x400 >> 0xb;
      piVar13[0x18] = iVar8 + iVar10 + 0x400 >> 0xb;
      piVar13[0x28] = (iVar9 - iVar6) + 0x400 >> 0xb;
      piVar13[0x20] = (iVar8 - iVar10) + 0x400 >> 0xb;
    }
    piVar13 = piVar13 + 1;
    psVar15 = psVar15 + 1;
    iVar16 = iVar16 + -1;
    param_3 = param_3 + 1;
  } while (0 < iVar16);
  piVar13 = local_128;
  do {
    iVar16 = piVar13[1];
    puVar14 = (undefined1 *)(param_5 + *param_4);
    if ((((iVar16 == 0) && (piVar13[2] == 0)) &&
        ((piVar13[3] == 0 && (((piVar13[4] == 0 && (piVar13[5] == 0)) && (piVar13[6] == 0)))))) &&
       (piVar13[7] == 0)) {
      uVar1 = *(undefined1 *)((*piVar13 + 0x10 >> 5 & 0x3ffU) + iVar5);
      *puVar14 = uVar1;
      puVar14[1] = uVar1;
      puVar14[2] = uVar1;
      puVar14[3] = uVar1;
      puVar14[4] = uVar1;
      puVar14[5] = uVar1;
      puVar14[6] = uVar1;
      puVar14[7] = uVar1;
    }
    else {
      iVar17 = piVar13[7];
      iVar6 = (piVar13[6] + piVar13[2]) * 0x1151;
      iVar2 = piVar13[5];
      iVar4 = piVar13[3];
      iVar10 = iVar6 + piVar13[6] * -0x3b21;
      iVar6 = piVar13[2] * 0x187e + iVar6;
      iVar8 = (*piVar13 - piVar13[4]) * 0x2000;
      iVar12 = iVar8 + iVar10;
      iVar8 = iVar8 - iVar10;
      iVar10 = (iVar2 + iVar16 + iVar17 + iVar4) * 0x25a1;
      iVar7 = (*piVar13 + piVar13[4]) * 0x2000;
      iVar3 = iVar7 + iVar6;
      iVar7 = iVar7 - iVar6;
      iVar6 = (iVar17 + iVar16) * -0x1ccd;
      iVar18 = (iVar2 + iVar4) * -0x5203;
      iVar9 = iVar10 + (iVar17 + iVar4) * -0x3ec5;
      iVar10 = iVar10 + (iVar2 + iVar16) * -0xc7c;
      iVar17 = iVar17 * 0x98e + iVar6 + iVar9;
      iVar2 = iVar2 * 0x41b3 + iVar10 + iVar18;
      iVar18 = iVar4 * 0x6254 + iVar9 + iVar18;
      iVar6 = iVar16 * 0x300b + iVar10 + iVar6;
      *puVar14 = *(undefined1 *)((iVar3 + iVar6 + 0x20000 >> 0x12 & 0x3ffU) + iVar5);
      puVar14[7] = *(undefined1 *)(((iVar3 - iVar6) + 0x20000 >> 0x12 & 0x3ffU) + iVar5);
      puVar14[1] = *(undefined1 *)((iVar12 + iVar18 + 0x20000 >> 0x12 & 0x3ffU) + iVar5);
      puVar14[6] = *(undefined1 *)(((iVar12 - iVar18) + 0x20000 >> 0x12 & 0x3ffU) + iVar5);
      puVar14[2] = *(undefined1 *)((iVar8 + iVar2 + 0x20000 >> 0x12 & 0x3ffU) + iVar5);
      puVar14[5] = *(undefined1 *)(((iVar8 - iVar2) + 0x20000 >> 0x12 & 0x3ffU) + iVar5);
      puVar14[3] = *(undefined1 *)((iVar7 + iVar17 + 0x20000 >> 0x12 & 0x3ffU) + iVar5);
      puVar14[4] = *(undefined1 *)(((iVar7 - iVar17) + 0x20000 >> 0x12 & 0x3ffU) + iVar5);
    }
    param_4 = param_4 + 1;
    piVar13 = piVar13 + 8;
    local_134 = local_134 + -1;
  } while (local_134 != 0);
  return;
}



/* 404bb588 FUN_404bb588 */

/* Boundary evidence: original MIPS .pdata 404bb588..404bbc2b. Semantic name remains unreviewed. */

void FUN_404bb588(int param_1,int param_2,short *param_3,int *param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  undefined1 *puVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int local_130;
  int local_128 [16];
  int local_e8 [8];
  int local_c8 [8];
  int local_a8 [8];
  int local_88 [8];
  int local_68 [8];
  int local_48 [8];
  
  iVar15 = *(int *)(param_1 + 0x148) + 0x80;
  iVar13 = 8;
  local_130 = 8;
  psVar12 = *(short **)(param_2 + 0x50);
  piVar10 = local_128;
  do {
    if ((((((param_3[8] == 0 && param_3[0x10] == 0) && param_3[0x18] == 0) && param_3[0x20] == 0) &&
         param_3[0x28] == 0) && param_3[0x30] == 0) && param_3[0x38] == 0) {
      iVar2 = (int)*param_3 * (int)*psVar12;
      *piVar10 = iVar2;
      piVar10[8] = iVar2;
      piVar10[0x10] = iVar2;
      piVar10[0x18] = iVar2;
      piVar10[0x20] = iVar2;
      piVar10[0x30] = iVar2;
      piVar10[0x38] = iVar2;
    }
    else {
      iVar8 = (int)(short)(psVar12[0x10] * param_3[0x10]);
      iVar2 = (int)(short)(psVar12[0x20] * param_3[0x20]);
      iVar9 = ((short)(*param_3 * *psVar12) + iVar2) * 0x10000 >> 0x10;
      iVar17 = ((short)(*param_3 * *psVar12) - iVar2) * 0x10000 >> 0x10;
      iVar4 = (int)(short)(psVar12[0x30] * param_3[0x30]);
      iVar2 = (iVar8 + iVar4) * 0x10000 >> 0x10;
      iVar3 = (iVar9 + iVar2) * 0x10000 >> 0x10;
      iVar11 = (iVar9 - iVar2) * 0x10000 >> 0x10;
      iVar2 = (((iVar8 - iVar4) * 0x16a >> 8) - iVar2) * 0x10000 >> 0x10;
      iVar4 = (iVar17 + iVar2) * 0x10000 >> 0x10;
      iVar2 = (iVar17 - iVar2) * 0x10000 >> 0x10;
      iVar7 = (int)(short)(psVar12[8] * param_3[8]);
      iVar5 = (int)(short)(psVar12[0x18] * param_3[0x18]);
      iVar8 = (int)(short)(psVar12[0x28] * param_3[0x28]);
      iVar6 = (iVar5 + iVar8) * 0x10000 >> 0x10;
      iVar17 = (int)(short)(psVar12[0x38] * param_3[0x38]);
      iVar9 = (iVar7 - iVar17) * 0x10000 >> 0x10;
      iVar5 = (iVar8 - iVar5) * 0x10000 >> 0x10;
      iVar17 = (iVar7 + iVar17) * 0x10000 >> 0x10;
      iVar7 = (iVar6 + iVar17) * 0x10000 >> 0x10;
      iVar8 = (int)(short)((uint)((iVar5 + iVar9) * 0x1d9) >> 8);
      iVar5 = (((iVar5 * -0x29d >> 8) - iVar7) + iVar8) * 0x10000 >> 0x10;
      iVar17 = (((iVar17 - iVar6) * 0x16a >> 8) - iVar5) * 0x10000 >> 0x10;
      iVar8 = (((iVar9 * 0x115 >> 8) - iVar8) + iVar17) * 0x10000 >> 0x10;
      *piVar10 = iVar7 + iVar3;
      piVar10[8] = iVar5 + iVar4;
      piVar10[0x30] = iVar4 - iVar5;
      piVar10[0x38] = iVar3 - iVar7;
      piVar10[0x10] = iVar17 + iVar2;
      piVar10[0x20] = iVar8 + iVar11;
      piVar10[0x18] = iVar11 - iVar8;
      iVar2 = iVar2 - iVar17;
    }
    piVar10[0x28] = iVar2;
    piVar10 = piVar10 + 1;
    psVar12 = psVar12 + 1;
    iVar13 = iVar13 + -1;
    param_3 = param_3 + 1;
  } while (0 < iVar13);
  piVar10 = local_128;
  do {
    iVar4 = piVar10[2];
    iVar3 = piVar10[1];
    iVar13 = piVar10[3];
    puVar14 = (undefined1 *)(*param_4 + param_5);
    iVar9 = piVar10[4];
    iVar2 = piVar10[5];
    iVar8 = piVar10[6];
    iVar17 = piVar10[7];
    if ((((((iVar3 == 0 && iVar4 == 0) && iVar13 == 0) && iVar9 == 0) && iVar2 == 0) && iVar8 == 0)
        && iVar17 == 0) {
      uVar1 = *(undefined1 *)((*piVar10 >> 5 & 0x3ffU) + iVar15);
      *puVar14 = uVar1;
      puVar14[1] = uVar1;
      puVar14[2] = uVar1;
      puVar14[3] = uVar1;
      puVar14[4] = uVar1;
      puVar14[5] = uVar1;
      puVar14[6] = uVar1;
      puVar14[7] = uVar1;
    }
    else {
      iVar5 = (iVar4 + iVar8) * 0x10000 >> 0x10;
      iVar6 = (*piVar10 + iVar9) * 0x10000 >> 0x10;
      iVar16 = (*piVar10 - iVar9) * 0x10000 >> 0x10;
      iVar7 = (iVar13 + iVar2) * 0x10000 >> 0x10;
      iVar9 = (iVar6 + iVar5) * 0x10000 >> 0x10;
      iVar11 = (iVar6 - iVar5) * 0x10000 >> 0x10;
      iVar8 = ((((int)(short)iVar4 - (int)(short)iVar8) * 0x16a >> 8) - iVar5) * 0x10000 >> 0x10;
      iVar4 = (iVar3 - iVar17) * 0x10000 >> 0x10;
      iVar5 = (iVar2 - iVar13) * 0x10000 >> 0x10;
      iVar2 = (iVar3 + iVar17) * 0x10000 >> 0x10;
      iVar17 = (iVar7 + iVar2) * 0x10000 >> 0x10;
      iVar6 = (iVar16 + iVar8) * 0x10000 >> 0x10;
      iVar8 = (iVar16 - iVar8) * 0x10000 >> 0x10;
      iVar13 = (int)(short)((uint)((iVar5 + iVar4) * 0x1d9) >> 8);
      iVar3 = (((iVar5 * -0x29d >> 8) - iVar17) + iVar13) * 0x10000 >> 0x10;
      iVar2 = (((iVar2 - iVar7) * 0x16a >> 8) - iVar3) * 0x10000 >> 0x10;
      *puVar14 = *(undefined1 *)((iVar17 + iVar9 >> 5 & 0x3ffU) + iVar15);
      puVar14[7] = *(undefined1 *)((iVar9 - iVar17 >> 5 & 0x3ffU) + iVar15);
      puVar14[1] = *(undefined1 *)((iVar3 + iVar6 >> 5 & 0x3ffU) + iVar15);
      puVar14[6] = *(undefined1 *)((iVar6 - iVar3 >> 5 & 0x3ffU) + iVar15);
      iVar13 = (((iVar4 * 0x115 >> 8) - iVar13) + iVar2) * 0x10000 >> 0x10;
      puVar14[2] = *(undefined1 *)((iVar2 + iVar8 >> 5 & 0x3ffU) + iVar15);
      puVar14[5] = *(undefined1 *)((iVar8 - iVar2 >> 5 & 0x3ffU) + iVar15);
      puVar14[4] = *(undefined1 *)((iVar13 + iVar11 >> 5 & 0x3ffU) + iVar15);
      puVar14[3] = *(undefined1 *)((iVar11 - iVar13 >> 5 & 0x3ffU) + iVar15);
    }
    param_4 = param_4 + 1;
    piVar10 = piVar10 + 8;
    local_130 = local_130 + -1;
  } while (local_130 != 0);
  return;
}



/* 404bbc2c FUN_404bbc2c */

/* Boundary evidence: original MIPS .pdata 404bbc2c..404bc403. Semantic name remains unreviewed. */

void FUN_404bbc2c(int param_1,int param_2,short *param_3,int *param_4,int param_5)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  int local_150;
  int *local_148;
  int local_130;
  undefined4 local_128 [64];
  
  puVar11 = *(undefined4 **)(param_2 + 0x50);
  iVar5 = *(int *)(param_1 + 0x148) + 0x80;
  puVar16 = local_128;
  local_130 = 8;
  local_150 = 8;
  do {
    sVar1 = param_3[8];
    if ((((sVar1 == 0) && (param_3[0x10] == 0)) && (param_3[0x18] == 0)) &&
       (((param_3[0x20] == 0 && (param_3[0x28] == 0)) &&
        ((param_3[0x30] == 0 && (param_3[0x38] == 0)))))) {
      uVar2 = __litofp((int)*param_3);
      uVar2 = __fpmul(uVar2,*puVar11);
      *puVar16 = uVar2;
      puVar16[8] = uVar2;
      puVar16[0x10] = uVar2;
      puVar16[0x20] = uVar2;
      puVar16[0x28] = uVar2;
      puVar16[0x30] = uVar2;
      puVar16[0x38] = uVar2;
    }
    else {
      uVar2 = __litofp((int)*param_3);
      uVar2 = __fpmul(uVar2,*puVar11);
      uVar7 = __litofp((int)param_3[0x10]);
      uVar7 = __fpmul(uVar7,puVar11[0x10]);
      uVar12 = __litofp((int)param_3[0x20]);
      uVar12 = __fpmul(uVar12,puVar11[0x20]);
      uVar8 = __litofp((int)param_3[0x30]);
      uVar8 = __fpmul(uVar8,puVar11[0x30]);
      uVar13 = __fpadd(uVar12,uVar2);
      uVar2 = __fpsub(uVar2,uVar12);
      uVar12 = __fpadd(uVar8,uVar7);
      uVar7 = __fpsub(uVar7,uVar8);
      uVar7 = __fpmul(uVar7,0x3fb504f3);
      uVar7 = __fpsub(uVar7,uVar12);
      uVar8 = __fpadd(uVar12,uVar13);
      uVar12 = __fpsub(uVar13,uVar12);
      uVar13 = __fpadd(uVar7,uVar2);
      uVar2 = __fpsub(uVar2,uVar7);
      uVar7 = __litofp((int)sVar1);
      uVar7 = __fpmul(puVar11[8],uVar7);
      uVar9 = __litofp((int)param_3[0x18]);
      uVar9 = __fpmul(uVar9,puVar11[0x18]);
      uVar14 = __litofp((int)param_3[0x28]);
      uVar14 = __fpmul(uVar14,puVar11[0x28]);
      uVar10 = __litofp((int)param_3[0x38]);
      uVar10 = __fpmul(uVar10,puVar11[0x38]);
      uVar15 = __fpadd(uVar14,uVar9);
      uVar9 = __fpsub(uVar14,uVar9);
      uVar14 = __fpadd(uVar10,uVar7);
      uVar7 = __fpsub(uVar7,uVar10);
      uVar10 = __fpadd(uVar14,uVar15);
      uVar3 = __fpadd(uVar7,uVar9);
      uVar3 = __fpmul(uVar3,0x3fec835e);
      uVar9 = __fpmul(uVar9,0x40273d75);
      uVar9 = __fpsub(uVar3,uVar9);
      uVar9 = __fpsub(uVar9,uVar10);
      uVar14 = __fpsub(uVar14,uVar15);
      uVar14 = __fpmul(uVar14,0x3fb504f3);
      uVar14 = __fpsub(uVar14,uVar9);
      uVar7 = __fpmul(uVar7,0x3f8a8bd4);
      uVar7 = __fpsub(uVar7,uVar3);
      uVar7 = __fpadd(uVar7,uVar14);
      uVar15 = __fpadd(uVar10,uVar8);
      *puVar16 = uVar15;
      uVar8 = __fpsub(uVar8,uVar10);
      puVar16[0x38] = uVar8;
      uVar8 = __fpadd(uVar9,uVar13);
      puVar16[8] = uVar8;
      uVar8 = __fpsub(uVar13,uVar9);
      puVar16[0x30] = uVar8;
      uVar8 = __fpadd(uVar14,uVar2);
      puVar16[0x10] = uVar8;
      uVar2 = __fpsub(uVar2,uVar14);
      puVar16[0x28] = uVar2;
      uVar2 = __fpadd(uVar7,uVar12);
      puVar16[0x20] = uVar2;
      uVar2 = __fpsub(uVar12,uVar7);
    }
    puVar16[0x18] = uVar2;
    puVar16 = puVar16 + 1;
    puVar11 = puVar11 + 1;
    param_3 = param_3 + 1;
    local_150 = local_150 + -1;
  } while (0 < local_150);
  puVar11 = local_128;
  local_148 = param_4;
  do {
    uVar12 = puVar11[4];
    uVar7 = *puVar11;
    puVar6 = (undefined1 *)(*local_148 + param_5);
    uVar2 = __fpadd(uVar7,uVar12);
    uVar7 = __fpsub(uVar7,uVar12);
    uVar13 = puVar11[6];
    uVar8 = puVar11[2];
    uVar12 = __fpadd(uVar8,uVar13);
    uVar8 = __fpsub(uVar8,uVar13);
    uVar8 = __fpmul(uVar8,0x3fb504f3);
    uVar8 = __fpsub(uVar8,uVar12);
    uVar13 = __fpadd(uVar12,uVar2);
    uVar2 = __fpsub(uVar2,uVar12);
    uVar12 = __fpadd(uVar8,uVar7);
    uVar7 = __fpsub(uVar7,uVar8);
    uVar14 = puVar11[5];
    uVar9 = puVar11[3];
    uVar8 = __fpadd(uVar9,uVar14);
    uVar9 = __fpsub(uVar14,uVar9);
    uVar15 = puVar11[7];
    uVar10 = puVar11[1];
    uVar14 = __fpadd(uVar10,uVar15);
    uVar10 = __fpsub(uVar10,uVar15);
    uVar15 = __fpadd(uVar14,uVar8);
    uVar3 = __fpadd(uVar10,uVar9);
    uVar3 = __fpmul(uVar3,0x3fec835e);
    uVar9 = __fpmul(uVar9,0x40273d75);
    uVar9 = __fpsub(uVar3,uVar9);
    uVar9 = __fpsub(uVar9,uVar15);
    uVar8 = __fpsub(uVar14,uVar8);
    uVar8 = __fpmul(uVar8,0x3fb504f3);
    uVar8 = __fpsub(uVar8,uVar9);
    uVar14 = __fpmul(uVar10,0x3f8a8bd4);
    uVar14 = __fpsub(uVar14,uVar3);
    uVar14 = __fpadd(uVar14,uVar8);
    uVar10 = __fpadd(uVar15,uVar13);
    iVar4 = __fptoli(uVar10);
    *puVar6 = *(undefined1 *)((iVar4 + 4 >> 3 & 0x3ffU) + iVar5);
    uVar13 = __fpsub(uVar13,uVar15);
    iVar4 = __fptoli(uVar13);
    puVar6[7] = *(undefined1 *)((iVar4 + 4 >> 3 & 0x3ffU) + iVar5);
    uVar13 = __fpadd(uVar9,uVar12);
    iVar4 = __fptoli(uVar13);
    puVar6[1] = *(undefined1 *)((iVar4 + 4 >> 3 & 0x3ffU) + iVar5);
    uVar12 = __fpsub(uVar12,uVar9);
    iVar4 = __fptoli(uVar12);
    puVar6[6] = *(undefined1 *)((iVar4 + 4 >> 3 & 0x3ffU) + iVar5);
    uVar12 = __fpadd(uVar8,uVar7);
    iVar4 = __fptoli(uVar12);
    puVar6[2] = *(undefined1 *)((iVar4 + 4 >> 3 & 0x3ffU) + iVar5);
    uVar7 = __fpsub(uVar7,uVar8);
    iVar4 = __fptoli(uVar7);
    puVar6[5] = *(undefined1 *)((iVar4 + 4 >> 3 & 0x3ffU) + iVar5);
    uVar7 = __fpadd(uVar14,uVar2);
    iVar4 = __fptoli(uVar7);
    puVar6[4] = *(undefined1 *)((iVar4 + 4 >> 3 & 0x3ffU) + iVar5);
    uVar2 = __fpsub(uVar2,uVar14);
    iVar4 = __fptoli(uVar2);
    local_148 = local_148 + 1;
    puVar11 = puVar11 + 8;
    local_130 = local_130 + -1;
    puVar6[3] = *(undefined1 *)((iVar4 + 4 >> 3 & 0x3ffU) + iVar5);
  } while (local_130 != 0);
  return;
}



/* 404bc404 FUN_404bc404 */

/* Boundary evidence: original MIPS .pdata 404bc404..404bc44b. Semantic name remains unreviewed. */

void FUN_404bc404(void)

{
  int iVar1;
  
  iVar1 = __GetUserKData(0);
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 2;
  RaiseException(0,1,0,(ULONG_PTR *)0x0);
  return;
}



/* 404bc44c FUN_404bc44c */

/* Boundary evidence: original MIPS .pdata 404bc44c..404bc48b. Semantic name remains unreviewed. */

uint FUN_404bc44c(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_404962c4(param_2 + 8);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = iVar1 + 8U & 0xfffffff8;
    *(int *)(uVar2 - 4) = iVar1;
  }
  return uVar2;
}



/* 404bc48c FUN_404bc48c */

/* Boundary evidence: original MIPS .pdata 404bc48c..404bc4a7. Semantic name remains unreviewed. */

void FUN_404bc48c(undefined4 param_1,int param_2)

{
  FUN_404962ec(*(LPVOID *)(param_2 + -4));
  return;
}



/* 404bc4a8 FUN_404bc4a8 */

/* Boundary evidence: original MIPS .pdata 404bc4a8..404bc4e7. Semantic name remains unreviewed. */

uint FUN_404bc4a8(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_404962c4(param_2 + 8);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = iVar1 + 8U & 0xfffffff8;
    *(int *)(uVar2 - 4) = iVar1;
  }
  return uVar2;
}



/* 404bc4e8 FUN_404bc4e8 */

/* Boundary evidence: original MIPS .pdata 404bc4e8..404bc503. Semantic name remains unreviewed. */

void FUN_404bc4e8(undefined4 param_1,int param_2)

{
  FUN_404962ec(*(LPVOID *)(param_2 + -4));
  return;
}



/* 404bc504 FUN_404bc504 */

undefined4 FUN_404bc504(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  return param_3;
}



/* 404bc50c FUN_404bc50c */

/* Boundary evidence: original MIPS .pdata 404bc50c..404bc527. Semantic name remains unreviewed. */

void FUN_404bc50c(void)

{
  FUN_404bc404();
  return;
}



/* 404bc588 FUN_404bc588 */

/* Boundary evidence: original MIPS .pdata 404bc588..404bc5b3. Semantic name remains unreviewed. */

void FUN_404bc588(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2f0);
  FUN_404a4618(FUN_404bc5d0);
  return;
}



/* 404bc5b4 FUN_404bc5b4 */

/* Boundary evidence: original MIPS .pdata 404bc5b4..404bc5cf. Semantic name remains unreviewed. */

void FUN_404bc5b4(void)

{
  FUN_40489408();
  return;
}



/* 404bc5d0 FUN_404bc5d0 */

/* Boundary evidence: original MIPS .pdata 404bc5d0..404bc5ef. Semantic name remains unreviewed. */

void FUN_404bc5d0(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_404bd2f0);
  return;
}



/* 404bc5f0 FUN_404bc5f0 */

/* Boundary evidence: original MIPS .pdata 404bc5f0..404bc60f. Semantic name remains unreviewed. */

void FUN_404bc5f0(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_404bd304);
  return;
}


