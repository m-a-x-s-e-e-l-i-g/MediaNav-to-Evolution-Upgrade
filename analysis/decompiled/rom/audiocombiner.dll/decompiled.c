/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40b31000 DllRegisterServer */

/* Boundary evidence: original MIPS .pdata 40b31000..40b3101b. Semantic name remains unreviewed. */

void DllRegisterServer(void)

{
                    /* 0x1000  3  DllRegisterServer */
  FUN_40b357d4(1);
  return;
}



/* 40b3101c DllUnregisterServer */

/* Boundary evidence: original MIPS .pdata 40b3101c..40b31037. Semantic name remains unreviewed. */

void DllUnregisterServer(void)

{
                    /* 0x101c  4  DllUnregisterServer */
  FUN_40b357d4(0);
  return;
}



/* 40b31038 FUN_40b31038 */

/* Boundary evidence: original MIPS .pdata 40b31038..40b31053. Semantic name remains unreviewed. */

void FUN_40b31038(HMODULE param_1,int param_2)

{
  FUN_40b358cc(param_1,param_2);
  return;
}



/* 40b31054 FUN_40b31054 */

/* Boundary evidence: original MIPS .pdata 40b31054..40b31077. Semantic name remains unreviewed. */

void FUN_40b31054(exception *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_40b3dde0;
  std::exception::~exception(param_1);
  return;
}



/* 40b31078 FUN_40b31078 */

/* Boundary evidence: original MIPS .pdata 40b31078..40b310cf. Semantic name remains unreviewed. */

exception * FUN_40b31078(exception *param_1,uint param_2)

{
  *(undefined ***)param_1 = &PTR_FUN_40b3dde0;
  std::exception::~exception(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b310d0 FUN_40b310d0 */

/* Boundary evidence: original MIPS .pdata 40b310d0..40b31137. Semantic name remains unreviewed. */

exception * FUN_40b310d0(exception *param_1,undefined4 param_2)

{
  std::exception::exception(param_1);
  *(undefined ***)param_1 = &PTR_FUN_40b3ddec;
  FUN_40b33c4c((int)(param_1 + 0xc),param_2);
  return param_1;
}



/* 40b31138 FUN_40b31138 */

/* Boundary evidence: original MIPS .pdata 40b31138..40b31167. Semantic name remains unreviewed. */

void FUN_40b31138(void)

{
  undefined4 *in_v0;
  
  std::exception::~exception((exception *)*in_v0);
  return;
}



/* 40b31190 FUN_40b31190 */

/* Boundary evidence: original MIPS .pdata 40b31190..40b311f7. Semantic name remains unreviewed. */

exception * FUN_40b31190(exception *param_1,uint param_2)

{
  *(undefined ***)param_1 = &PTR_FUN_40b3ddec;
  FUN_40b34108((int)(param_1 + 0xc),1,0);
  std::exception::~exception(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b311f8 FUN_40b311f8 */

/* Boundary evidence: original MIPS .pdata 40b311f8..40b3123b. Semantic name remains unreviewed. */

void FUN_40b311f8(exception *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_40b3ddec;
  FUN_40b34108((int)(param_1 + 0xc),1,0);
  std::exception::~exception(param_1);
  return;
}



/* 40b3123c FUN_40b3123c */

/* Boundary evidence: original MIPS .pdata 40b3123c..40b31257. Semantic name remains unreviewed. */

void FUN_40b3123c(int *param_1)

{
  FUN_40b35fa8(param_1);
  return;
}



/* 40b31258 FUN_40b31258 */

/* Boundary evidence: original MIPS .pdata 40b31258..40b31273. Semantic name remains unreviewed. */

void FUN_40b31258(int param_1)

{
  FUN_40b35f6c(param_1);
  return;
}



/* 40b31274 FUN_40b31274 */

/* Boundary evidence: original MIPS .pdata 40b31274..40b3129b. Semantic name remains unreviewed. */

void FUN_40b31274(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc))();
  return;
}



/* 40b3129c FUN_40b3129c */

/* Boundary evidence: original MIPS .pdata 40b3129c..40b312c3. Semantic name remains unreviewed. */

void FUN_40b3129c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))();
  return;
}



/* 40b312c4 FUN_40b312c4 */

/* Boundary evidence: original MIPS .pdata 40b312c4..40b312eb. Semantic name remains unreviewed. */

void FUN_40b312c4(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 8))();
  return;
}



/* 40b312ec FUN_40b312ec */

/* Boundary evidence: original MIPS .pdata 40b312ec..40b31363. Semantic name remains unreviewed. */

void FUN_40b312ec(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,&DAT_40b3e200,0x10);
  if (iVar1 == 0) {
    FUN_40b35e4c(param_1 + -2,param_3);
  }
  else {
    FUN_40b36e24(param_1,param_2,param_3);
  }
  return;
}



/* 40b31364 FUN_40b31364 */

/* Boundary evidence: original MIPS .pdata 40b31364..40b3138b. Semantic name remains unreviewed. */

void FUN_40b31364(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b3138c FUN_40b3138c */

/* Boundary evidence: original MIPS .pdata 40b3138c..40b313b3. Semantic name remains unreviewed. */

void FUN_40b3138c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b313c0 FUN_40b313c0 */

/* Boundary evidence: original MIPS .pdata 40b313c0..40b3142f. Semantic name remains unreviewed. */

undefined4 * FUN_40b313c0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x90);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40b31460(puVar1,param_1,param_2);
  }
  return puVar1;
}



/* 40b31430 FUN_40b31430 */

/* Boundary evidence: original MIPS .pdata 40b31430..40b3145f. Semantic name remains unreviewed. */

void FUN_40b31430(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40b31460 FUN_40b31460 */

/* Boundary evidence: original MIPS .pdata 40b31460..40b315bb. Semantic name remains unreviewed. */

undefined4 * FUN_40b31460(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x14);
  FUN_40b394d4(param_1,0,param_2,lpCriticalSection,&DAT_40b3ded8);
  *param_1 = &PTR_FUN_40b3dfb8;
  param_1[3] = &PTR_FUN_40b3dfdc;
  param_1[4] = &PTR_LAB_40b3e018;
  InitializeCriticalSection(lpCriticalSection);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1a));
  FUN_40b342a4(param_1 + 0x1f);
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  puVar1 = operator_new(0xa8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_40b3942c(puVar1,0,param_1,lpCriticalSection,param_3,L"Audio Out");
    *puVar1 = &PTR_FUN_40b3e0f8;
    puVar1[3] = &PTR_FUN_40b3e154;
    puVar1[4] = &PTR_LAB_40b3e19c;
    puVar1[0x28] = &PTR_LAB_40b3e1b0;
    puVar1[0x29] = param_1;
  }
  param_1[0x19] = puVar1;
  FUN_40b31a04((int)param_1);
  return param_1;
}



/* 40b315bc FUN_40b315bc */

/* Boundary evidence: original MIPS .pdata 40b315bc..40b315eb. Semantic name remains unreviewed. */

void FUN_40b315bc(void)

{
  int *in_v0;
  
  FUN_40b37914(*in_v0);
  return;
}



/* 40b315ec FUN_40b315ec */

/* Boundary evidence: original MIPS .pdata 40b315ec..40b3161f. Semantic name remains unreviewed. */

void FUN_40b315ec(void)

{
  int *in_v0;
  
  FUN_40b34fa8((LPCRITICAL_SECTION)(*in_v0 + 0x50));
  return;
}



/* 40b31620 FUN_40b31620 */

/* Boundary evidence: original MIPS .pdata 40b31620..40b31653. Semantic name remains unreviewed. */

void FUN_40b31620(void)

{
  int *in_v0;
  
  FUN_40b34fa8((LPCRITICAL_SECTION)(*in_v0 + 0x68));
  return;
}



/* 40b31654 FUN_40b31654 */

/* Boundary evidence: original MIPS .pdata 40b31654..40b31687. Semantic name remains unreviewed. */

void FUN_40b31654(void)

{
  int *in_v0;
  
  FUN_40b33ccc(*in_v0 + 0x7c);
  return;
}



/* 40b31688 FUN_40b31688 */

/* Boundary evidence: original MIPS .pdata 40b31688..40b316b7. Semantic name remains unreviewed. */

void FUN_40b31688(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x1c));
  return;
}



/* 40b316b8 FUN_40b316b8 */

/* Boundary evidence: original MIPS .pdata 40b316b8..40b31703. Semantic name remains unreviewed. */

undefined4 * FUN_40b316b8(undefined4 *param_1,uint param_2)

{
  FUN_40b31704(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b31704 FUN_40b31704 */

/* Boundary evidence: original MIPS .pdata 40b31704..40b31843. Semantic name remains unreviewed. */

void FUN_40b31704(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  *param_1 = &PTR_FUN_40b3dfb8;
  param_1[3] = &PTR_FUN_40b3dfdc;
  param_1[4] = &PTR_LAB_40b3e018;
  piVar1 = (int *)param_1[0x19];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
  }
  iVar3 = 0;
  for (uVar2 = 0;
      (param_1[0x20] != 0 && (uVar2 < (uint)((int)(param_1[0x21] - param_1[0x20]) >> 2)));
      uVar2 = uVar2 + 1) {
    if ((param_1[0x20] == 0) || ((uint)((int)(param_1[0x21] - param_1[0x20]) >> 2) <= uVar2)) {
      FUN_40b3a7b4();
    }
    (**(code **)(**(int **)(param_1[0x20] + iVar3) + 8))();
    iVar3 = iVar3 + 4;
  }
  if ((void *)param_1[0x20] != (void *)0x0) {
    operator_delete((void *)param_1[0x20]);
  }
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1a));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_40b37914((int)param_1);
  return;
}



/* 40b31844 FUN_40b31844 */

/* Boundary evidence: original MIPS .pdata 40b31844..40b31873. Semantic name remains unreviewed. */

void FUN_40b31844(void)

{
  int *in_v0;
  
  FUN_40b37914(*in_v0);
  return;
}



/* 40b31874 FUN_40b31874 */

/* Boundary evidence: original MIPS .pdata 40b31874..40b318a7. Semantic name remains unreviewed. */

void FUN_40b31874(void)

{
  int *in_v0;
  
  FUN_40b34fa8((LPCRITICAL_SECTION)(*in_v0 + 0x50));
  return;
}



/* 40b318a8 FUN_40b318a8 */

/* Boundary evidence: original MIPS .pdata 40b318a8..40b318db. Semantic name remains unreviewed. */

void FUN_40b318a8(void)

{
  int *in_v0;
  
  FUN_40b34fa8((LPCRITICAL_SECTION)(*in_v0 + 0x68));
  return;
}



/* 40b318dc FUN_40b318dc */

/* Boundary evidence: original MIPS .pdata 40b318dc..40b3190f. Semantic name remains unreviewed. */

void FUN_40b318dc(void)

{
  int *in_v0;
  
  FUN_40b33ccc(*in_v0 + 0x7c);
  return;
}



/* 40b31938 FUN_40b31938 */

/* Boundary evidence: original MIPS .pdata 40b31938..40b31a03. Semantic name remains unreviewed. */

int FUN_40b31938(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x80) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2;
  }
  if (param_2 == uVar2) {
    iVar1 = *(int *)(param_1 + 100);
  }
  else {
    if (*(int *)(param_1 + 0x80) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2;
    }
    if ((int)param_2 < iVar1) {
      if ((*(int *)(param_1 + 0x80) == 0) ||
         ((uint)(*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2) <= param_2)) {
        FUN_40b3a7b4();
      }
      iVar1 = *(int *)(param_2 * 4 + *(int *)(param_1 + 0x80));
      if (iVar1 != 0) {
        return iVar1 + 8;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b31a04 FUN_40b31a04 */

/* Boundary evidence: original MIPS .pdata 40b31a04..40b31c07. Semantic name remains unreviewed. */

void FUN_40b31a04(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *local_138;
  undefined4 local_134;
  int aiStack_130 [2];
  wchar_t awStack_128 [128];
  uint local_28;
  
  local_28 = DAT_40b3f10c;
  if (*(int *)(param_1 + 0x80) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2;
  }
  StringCbPrintfW(awStack_128,0x100,L"Input %d",iVar2 + 1);
  local_134 = 0;
  piVar1 = operator_new(0xf0);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    if (*(int *)(param_1 + 0x80) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2;
    }
    local_138 = piVar1;
    FUN_40b39478(piVar1 + 2,0,param_1,param_1 + 0x50,&local_134,awStack_128);
    *piVar1 = (int)&PTR_FUN_40b3e02c;
    piVar1[2] = (int)&PTR_FUN_40b3e03c;
    piVar1[5] = (int)&PTR_LAB_40b3e078;
    piVar1[6] = (int)&PTR_LAB_40b3e0c0;
    piVar1[0x28] = (int)&PTR_LAB_40b3e0d4;
    piVar1[0x38] = param_1;
    piVar1[0x39] = iVar2;
    *(undefined1 *)(piVar1 + 0x3a) = 0;
    *(undefined1 *)((int)piVar1 + 0xe9) = 0;
  }
  local_138 = piVar1;
  (**(code **)(*piVar1 + 4))(piVar1);
  puVar3 = *(undefined4 **)(param_1 + 0x80);
  if ((puVar3 == (undefined4 *)0x0) ||
     ((uint)(*(int *)(param_1 + 0x88) - (int)puVar3 >> 2) <=
      (uint)(*(int *)(param_1 + 0x84) - (int)puVar3 >> 2))) {
    puVar4 = *(undefined4 **)(param_1 + 0x84);
    if (puVar4 < puVar3) {
      FUN_40b3a7b4();
    }
    FUN_40b3418c(param_1 + 0x7c,aiStack_130,param_1 + 0x7c,puVar4,&local_138);
  }
  else {
    puVar3 = *(undefined4 **)(param_1 + 0x84);
    *puVar3 = piVar1;
    *(undefined4 **)(param_1 + 0x84) = puVar3 + 1;
  }
  FUN_40b3611c(param_1);
  FUN_40b39e00(local_28);
  return;
}



/* 40b31c08 FUN_40b31c08 */

/* Boundary evidence: original MIPS .pdata 40b31c08..40b31c37. Semantic name remains unreviewed. */

void FUN_40b31c08(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x138));
  return;
}



/* 40b31c38 FUN_40b31c38 */

/* Boundary evidence: original MIPS .pdata 40b31c38..40b31da3. Semantic name remains unreviewed. */

void FUN_40b31c38(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x80) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2;
  }
  if (param_2 == iVar2 + -2) {
    if (*(int *)(param_1 + 0x80) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2;
    }
    if ((*(int *)(param_1 + 0x80) == 0) ||
       ((uint)(*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2) <= iVar2 - 1U)) {
      FUN_40b3a7b4();
    }
    iVar3 = *(int *)(param_1 + 0x80);
    if (*(int *)(*(int *)((iVar2 - 1U) * 4 + iVar3) + 0x20) == 0) {
      if (iVar3 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x84) - iVar3 >> 2;
      }
      if ((*(int *)(param_1 + 0x80) == 0) ||
         ((uint)(*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2) <= iVar2 - 1U)) {
        FUN_40b3a7b4();
      }
      (**(code **)(**(int **)((iVar2 - 1U) * 4 + *(int *)(param_1 + 0x80)) + 8))();
      if ((*(int *)(param_1 + 0x80) == 0) ||
         (bVar1 = false, *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x80) >> 2 == 0)) {
        bVar1 = true;
      }
      if (!bVar1) {
        *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -4;
      }
      FUN_40b3611c(param_1);
    }
  }
  return;
}



/* 40b31da4 FUN_40b31da4 */

/* Boundary evidence: original MIPS .pdata 40b31da4..40b31edf. Semantic name remains unreviewed. */

undefined4 FUN_40b31da4(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x68));
  if (*(int *)(param_1 + 0x8c) == 0) {
    piVar2 = *(int **)(param_1 + 0x80);
    if (*(int **)(param_1 + 0x84) < piVar2) {
      FUN_40b3a7b4();
    }
    while( true ) {
      piVar3 = *(int **)(param_1 + 0x84);
      if (piVar3 < *(int **)(param_1 + 0x80)) {
        FUN_40b3a7b4();
      }
      if (param_1 == -0x7c) {
        FUN_40b3a7b4();
      }
      if (piVar2 == piVar3) break;
      if (param_1 == -0x7c) {
        FUN_40b3a7b4();
      }
      if (*(int **)(param_1 + 0x84) <= piVar2) {
        FUN_40b3a7b4();
      }
      if (*(int *)(*piVar2 + 0x20) != 0) {
        *(int *)(param_1 + 0x8c) = *piVar2;
      }
      if (*(int **)(param_1 + 0x84) <= piVar2) {
        FUN_40b3a7b4();
      }
      piVar2 = piVar2 + 1;
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 0x8c);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x68));
  return uVar1;
}



/* 40b31ee0 FUN_40b31ee0 */

/* Boundary evidence: original MIPS .pdata 40b31ee0..40b31f37. Semantic name remains unreviewed. */

void * FUN_40b31ee0(void *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1 + 8;
  if (param_1 == (void *)0x0) {
    iVar1 = 0;
  }
  FUN_40b36ddc(iVar1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b31f38 FUN_40b31f38 */

/* Boundary evidence: original MIPS .pdata 40b31f38..40b31ff7. Semantic name remains unreviewed. */

undefined4 FUN_40b31f38(int param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = memcmp(param_2,&DAT_40b3c3a8,0x10);
  if (((iVar1 == 0) &&
      (iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40b3cf68,0x10), iVar1 == 0)) &&
     (**(short **)((int)param_2 + 0x44) == 1)) {
    piVar3 = *(int **)(*(int *)(*(int *)(param_1 + 0xd8) + 100) + 0x18);
    uVar2 = 0;
    if (piVar3 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar3 + 0x2c))(piVar3,param_2);
    }
  }
  else {
    uVar2 = 0x8004022a;
  }
  return uVar2;
}



/* 40b3202c FUN_40b3202c */

/* Boundary evidence: original MIPS .pdata 40b3202c..40b32463. Semantic name remains unreviewed. */

int FUN_40b3202c(int param_1,int *param_2)

{
  size_t _Size;
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  int *piVar5;
  uint uVar6;
  void *pvVar7;
  int iVar8;
  longlong lVar9;
  int *local_a8;
  void *local_a4;
  void *local_a0 [2];
  undefined8 local_98;
  undefined8 local_90;
  void *local_88 [2];
  undefined1 auStack_80 [8];
  undefined1 auStack_78 [72];
  uint local_30;
  
  local_30 = DAT_40b3f10c;
  iVar2 = FUN_40b3700c(param_1,param_2);
  if (iVar2 == 0) {
    iVar3 = (**(code **)(*param_2 + 0x34))(param_2,local_a0);
    if (iVar3 == 0) {
      FUN_40b39768(auStack_78,local_a0[0]);
      FUN_40b39a68(local_a0[0]);
      (**(code **)(*(int *)(param_1 + -0x98) + 0x24))((int *)(param_1 + -0x98),auStack_78);
      FUN_40b3970c((int)auStack_78);
    }
    if (*(char *)(param_1 + 0x48) != '\0') {
      iVar8 = *(int *)(param_1 + -0x38);
      (**(code **)(*param_2 + 0xc))(param_2,&local_a4);
      iVar3 = (**(code **)(*param_2 + 0x2c))(param_2);
      iVar4 = (**(code **)(*param_2 + 0x14))(param_2,&local_98,auStack_80);
      while (iVar3 != 0) {
        piVar5 = *(int **)(*(int *)(param_1 + 0x40) + 100);
        local_a8 = (int *)0x0;
        iVar2 = (**(code **)(*piVar5 + 0x40))(piVar5,&local_a8,0,0,0);
        if (iVar2 != 0) {
LAB_40b3240c:
          if (local_a8 != (int *)0x0) {
            (**(code **)(*local_a8 + 8))();
          }
          break;
        }
        if (local_a8 == (int *)0x0) {
          FUN_40b3a3ec(0x80004003);
        }
        (**(code **)(*local_a8 + 0xc))(local_a8,local_88);
        if (local_a8 == (int *)0x0) {
          FUN_40b3a3ec(0x80004003);
        }
        iVar2 = (**(code **)(*local_a8 + 0x10))();
        if (iVar3 <= iVar2) {
          iVar2 = iVar3;
        }
        uVar6 = (uint)*(ushort *)(iVar8 + 0xc);
        if (uVar6 == 0) {
          trap(0x1c00);
        }
        if ((uVar6 == 0xffffffff) && (iVar2 == -0x80000000)) {
          trap(0x1800);
        }
        _Size = (iVar2 / (int)uVar6) * uVar6;
        memcpy(local_88[0],local_a4,_Size);
        if (local_a8 == (int *)0x0) {
          FUN_40b3a3ec(0x80004003);
        }
        (**(code **)(*local_a8 + 0x30))(local_a8,_Size);
        if (iVar4 == 0) {
          lVar9 = __ll_div((int)((ulonglong)_Size * 10000000),
                           ((int)_Size >> 0x1f) * 10000000 +
                           (int)((ulonglong)_Size * 10000000 >> 0x20),*(undefined4 *)(iVar8 + 8),0);
          local_90 = lVar9 + local_98;
          if (local_a8 == (int *)0x0) {
            FUN_40b3a3ec(0x80004003);
          }
          (**(code **)(*local_a8 + 0x18))(local_a8,&local_98,&local_90);
          local_98 = local_90;
        }
        local_a4 = (void *)(_Size + (int)local_a4);
        iVar3 = iVar3 - _Size;
        if (*(char *)(param_1 + 0x49) != '\0') {
          if (local_a8 == (int *)0x0) {
            FUN_40b3a3ec(0x80004003);
          }
          (**(code **)(*local_a8 + 0x40))(local_a8,1);
          pvVar7 = (void *)(param_1 + -0x7c);
          bVar1 = FUN_40b398b8(pvVar7,(void *)(*(int *)(*(int *)(param_1 + 0x40) + 100) + 0x1c));
          if (CONCAT31(extraout_var,bVar1) != 0) {
            if (local_a8 == (int *)0x0) {
              FUN_40b3a3ec(0x80004003);
            }
            (**(code **)(*local_a8 + 0x38))(local_a8,pvVar7);
            piVar5 = *(int **)(*(int *)(param_1 + 0x40) + 100);
            (**(code **)(*piVar5 + 0x24))(piVar5,pvVar7);
          }
        }
        piVar5 = *(int **)(*(int *)(param_1 + 0x40) + 100);
        iVar2 = (**(code **)(*piVar5 + 0x44))(piVar5,local_a8);
        if (iVar2 < 0) goto LAB_40b3240c;
        *(undefined1 *)(param_1 + 0x49) = 0;
        if (local_a8 != (int *)0x0) {
          (**(code **)(*local_a8 + 8))();
        }
      }
    }
  }
  FUN_40b39e00(local_30);
  return iVar2;
}



/* 40b32464 FUN_40b32464 */

/* Boundary evidence: original MIPS .pdata 40b32464..40b32493. Semantic name remains unreviewed. */

void FUN_40b32464(void)

{
  int in_v0;
  
  FUN_40b3970c(in_v0 + -0x78);
  return;
}



/* 40b32494 FUN_40b32494 */

/* Boundary evidence: original MIPS .pdata 40b32494..40b324c3. Semantic name remains unreviewed. */

void FUN_40b32494(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0xa8));
  return;
}



/* 40b324c4 FUN_40b324c4 */

/* Boundary evidence: original MIPS .pdata 40b324c4..40b324fb. Semantic name remains unreviewed. */

undefined4 FUN_40b324c4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0xd4) != '\0') {
    uVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0xcc) + 100) + 0x4c))();
  }
  return uVar1;
}



/* 40b324fc FUN_40b324fc */

/* Boundary evidence: original MIPS .pdata 40b324fc..40b3254f. Semantic name remains unreviewed. */

void FUN_40b324fc(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40b37490(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 0xd4) != '\0')) {
    (**(code **)(**(int **)(*(int *)(param_1 + 0xcc) + 100) + 0x50))();
  }
  return;
}



/* 40b32550 FUN_40b32550 */

/* Boundary evidence: original MIPS .pdata 40b32550..40b325a3. Semantic name remains unreviewed. */

void FUN_40b32550(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40b374d8(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 0xd4) != '\0')) {
    (**(code **)(**(int **)(*(int *)(param_1 + 0xcc) + 100) + 0x54))();
  }
  return;
}



/* 40b325a4 FUN_40b325a4 */

/* Boundary evidence: original MIPS .pdata 40b325a4..40b325e7. Semantic name remains unreviewed. */

undefined4 FUN_40b325a4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_40b365e0();
  FUN_40b31c38(*(int *)(param_1 + 0xd8),*(int *)(param_1 + 0xdc));
  return uVar1;
}



/* 40b325e8 FUN_40b325e8 */

/* Boundary evidence: original MIPS .pdata 40b325e8..40b3265f. Semantic name remains unreviewed. */

int FUN_40b325e8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_40b365e0();
  if (-1 < iVar1) {
    iVar2 = *(int *)(param_1 + 0xd8);
    if (*(int *)(iVar2 + 0x80) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x84) - *(int *)(iVar2 + 0x80) >> 2;
    }
    if (*(int *)(param_1 + 0xdc) == iVar3 + -1) {
      FUN_40b31a04(iVar2);
    }
  }
  return iVar1;
}



/* 40b32660 FUN_40b32660 */

/* Boundary evidence: original MIPS .pdata 40b32660..40b326ab. Semantic name remains unreviewed. */

void * FUN_40b32660(void *param_1,uint param_2)

{
  FUN_40b3649c((int)param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b326ac FUN_40b326ac */

/* Boundary evidence: original MIPS .pdata 40b326ac..40b3272b. Semantic name remains unreviewed. */

void FUN_40b326ac(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b3e210,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x28;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40b35e4c(piVar2,param_3);
  }
  else {
    FUN_40b364e0(param_1,param_2,param_3);
  }
  return;
}



/* 40b3272c FUN_40b3272c */

/* Boundary evidence: original MIPS .pdata 40b3272c..40b327f3. Semantic name remains unreviewed. */

undefined4 FUN_40b3272c(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,&DAT_40b3c3a8,0x10);
  if (((iVar1 == 0) &&
      (iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40b3cf68,0x10), iVar1 == 0)) &&
     (**(short **)((int)param_2 + 0x44) == 1)) {
    iVar1 = FUN_40b31da4(*(int *)(param_1 + 0xa4));
    if (iVar1 == 0) {
      return 0x80040209;
    }
    iVar1 = FUN_40b3980c((void *)(iVar1 + 0x24),param_2);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 0x8004022a;
}



/* 40b327f4 FUN_40b327f4 */

/* Boundary evidence: original MIPS .pdata 40b327f4..40b3285f. Semantic name remains unreviewed. */

undefined4 FUN_40b327f4(int param_1,int param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40b31da4(*(int *)(param_1 + 0xa4));
  if (iVar1 == 0) {
    uVar2 = 0x80040209;
  }
  else if (param_2 == 0) {
    FUN_40b397e0(param_3,(void *)(iVar1 + 0x24));
    uVar2 = 0;
  }
  else {
    uVar2 = 0x40103;
  }
  return uVar2;
}



/* 40b32860 FUN_40b32860 */

/* Boundary evidence: original MIPS .pdata 40b32860..40b3295f. Semantic name remains unreviewed. */

int FUN_40b32860(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int *local_30 [2];
  undefined1 auStack_28 [16];
  
  iVar1 = FUN_40b31da4(*(int *)(param_1 + 0xa4));
  if (iVar1 == 0) {
    iVar1 = -0x7ffbfdf7;
  }
  else {
    local_30[0] = (int *)0x0;
    iVar1 = (**(code **)(*(int *)(iVar1 + 0xa0) + 0xc))((int *)(iVar1 + 0xa0),local_30);
    if (-1 < iVar1) {
      if (local_30[0] == (int *)0x0) {
        FUN_40b3a3ec(0x80004003);
      }
      iVar1 = (**(code **)(*local_30[0] + 0x10))(local_30[0],param_3);
    }
    if (local_30[0] != (int *)0x0) {
      (**(code **)(*local_30[0] + 8))();
    }
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*param_2 + 0xc))(param_2,param_3,auStack_28);
    }
  }
  return iVar1;
}



/* 40b32960 FUN_40b32960 */

/* Boundary evidence: original MIPS .pdata 40b32960..40b3298f. Semantic name remains unreviewed. */

void FUN_40b32960(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x30));
  return;
}



/* 40b32990 FUN_40b32990 */

/* Boundary evidence: original MIPS .pdata 40b32990..40b32ba7. Semantic name remains unreviewed. */

char * FUN_40b32990(char *param_1,int *param_2,char param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *local_3c;
  int local_38;
  int *local_34;
  int *local_30 [2];
  
  *param_1 = param_3;
  FUN_40b342e4(param_1 + 4);
  uVar2 = FUN_40b342ac();
  *(undefined4 *)(param_1 + 8) = uVar2;
  param_1[0xc] = '\0';
  param_1[0xd] = '\0';
  param_1[0xe] = '\0';
  param_1[0xf] = '\0';
  iVar5 = 0;
  iVar3 = (**(code **)(*param_2 + 0x18))(param_2);
  if (0 < iVar3) {
    do {
      iVar3 = (**(code **)(*param_2 + 0x1c))(param_2,iVar5);
      (**(code **)(*(int *)(iVar3 + 0xc) + 0x24))((int *)(iVar3 + 0xc),&local_38);
      if (local_38 == 0) {
        puVar4 = *(undefined4 **)(iVar3 + 0x18);
        local_3c = (int *)0x0;
        iVar3 = -0x7fffbffe;
        if ((puVar4 != (undefined4 *)0x0) &&
           (iVar3 = (**(code **)*puVar4)(puVar4,&DAT_40b3e210,&local_34), local_3c = local_34,
           iVar3 < 0)) {
          local_3c = (int *)0x0;
        }
        piVar1 = local_3c;
        if ((iVar3 < 0) && (iVar3 != -0x7fffbffe)) {
          FUN_40b3a3ec(iVar3);
        }
        if (local_3c != (int *)0x0) {
          if (*param_1 != '\0') {
            if (local_3c == (int *)0x0) {
              FUN_40b3a3ec(0x80004003);
            }
            iVar3 = (**(code **)(*local_3c + 0x24))(local_3c,&DAT_40b3d558);
            if (iVar3 < 0) goto LAB_40b32b34;
          }
          local_3c = (int *)0x0;
          local_30[0] = piVar1;
          FUN_40b33da4((int)(param_1 + 4),local_30);
        }
LAB_40b32b34:
        if (local_3c != (int *)0x0) {
          (**(code **)(*local_3c + 8))(local_3c);
        }
      }
      iVar5 = iVar5 + 1;
      iVar3 = (**(code **)(*param_2 + 0x18))(param_2);
    } while (iVar5 < iVar3);
  }
  return param_1;
}



/* 40b32ba8 FUN_40b32ba8 */

/* Boundary evidence: original MIPS .pdata 40b32ba8..40b32bdb. Semantic name remains unreviewed. */

void FUN_40b32ba8(void)

{
  int *in_v0;
  
  FUN_40b33d3c(*in_v0 + 4);
  return;
}



/* 40b32bdc FUN_40b32bdc */

/* Boundary evidence: original MIPS .pdata 40b32bdc..40b32c0b. Semantic name remains unreviewed. */

void FUN_40b32bdc(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x3c));
  return;
}



/* 40b32c0c FUN_40b32c0c */

/* Boundary evidence: original MIPS .pdata 40b32c0c..40b32d8b. Semantic name remains unreviewed. */

void FUN_40b32c0c(char *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int *piVar3;
  void *pvVar4;
  char *local_38;
  undefined4 local_34;
  char *local_30;
  undefined4 local_2c;
  int aiStack_28 [2];
  
  local_38 = param_1 + 4;
  local_34 = **(undefined4 **)(param_1 + 8);
  local_30 = local_38;
  while( true ) {
    local_2c = *(undefined4 *)(param_1 + 8);
    bVar1 = FUN_40b33f78((int *)&local_38,(int *)&local_30);
    if (CONCAT31(extraout_var,bVar1) == 0) break;
    puVar2 = (undefined4 *)FUN_40b33ea8((int *)&local_38);
    piVar3 = (int *)*puVar2;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))(piVar3);
    }
    if (*param_1 != '\0') {
      if (piVar3 == (int *)0x0) {
        FUN_40b3a3ec(0x80004003);
      }
      (**(code **)(*piVar3 + 0x24))(piVar3,&DAT_40b3d508);
    }
    if (piVar3 == (int *)0x0) {
      FUN_40b3a3ec(0x80004003);
    }
    (**(code **)(*piVar3 + 8))(piVar3);
    (**(code **)(*piVar3 + 8))(piVar3);
    FUN_40b33f00((int *)&local_38,aiStack_28);
  }
  piVar3 = *(int **)(param_1 + 8);
  puVar2 = (undefined4 *)*piVar3;
  *piVar3 = (int)piVar3;
  *(int *)(*(int *)(param_1 + 8) + 4) = *(int *)(param_1 + 8);
  param_1[0xc] = '\0';
  param_1[0xd] = '\0';
  param_1[0xe] = '\0';
  param_1[0xf] = '\0';
  if (puVar2 != *(void **)(param_1 + 8)) {
    do {
      pvVar4 = (void *)*puVar2;
      operator_delete(puVar2);
      puVar2 = pvVar4;
    } while (pvVar4 != *(void **)(param_1 + 8));
  }
  operator_delete(*(void **)(param_1 + 8));
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
  return;
}



/* 40b32d8c FUN_40b32d8c */

/* Boundary evidence: original MIPS .pdata 40b32d8c..40b32dbf. Semantic name remains unreviewed. */

void FUN_40b32d8c(void)

{
  int *in_v0;
  
  FUN_40b33d3c(*in_v0 + 4);
  return;
}



/* 40b32dc0 FUN_40b32dc0 */

/* Boundary evidence: original MIPS .pdata 40b32dc0..40b32def. Semantic name remains unreviewed. */

void FUN_40b32dc0(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x40));
  return;
}



/* 40b32df0 FUN_40b32df0 */

/* Boundary evidence: original MIPS .pdata 40b32df0..40b32f1b. Semantic name remains unreviewed. */

undefined4 FUN_40b32df0(int param_1,uint *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint local_48;
  int *local_44;
  undefined1 *local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined4 *local_34;
  int aiStack_30 [2];
  char acStack_28 [4];
  undefined1 auStack_24 [4];
  undefined4 *local_20;
  
  uVar5 = 8;
  FUN_40b32990(acStack_28,*(int **)(param_1 + 4),'\0');
  local_40 = auStack_24;
  local_3c = *local_20;
  local_38 = auStack_24;
  while( true ) {
    local_34 = local_20;
    bVar1 = FUN_40b33f78((int *)&local_40,(int *)&local_38);
    if (CONCAT31(extraout_var,bVar1) == 0) break;
    puVar2 = (undefined4 *)FUN_40b33ea8((int *)&local_40);
    piVar4 = (int *)*puVar2;
    local_44 = piVar4;
    if (piVar4 == (int *)0x0) {
      FUN_40b3a3ec(0x80004003);
    }
    else {
      (**(code **)(*piVar4 + 4))(piVar4);
    }
    iVar3 = (**(code **)(*piVar4 + 0xc))(piVar4,&local_48);
    if (-1 < iVar3) {
      uVar5 = local_48 | uVar5;
    }
    (**(code **)(*piVar4 + 8))(piVar4);
    FUN_40b33f00((int *)&local_40,aiStack_30);
  }
  *param_2 = uVar5;
  FUN_40b32c0c(acStack_28);
  return 0;
}



/* 40b32f1c FUN_40b32f1c */

/* Boundary evidence: original MIPS .pdata 40b32f1c..40b32f4b. Semantic name remains unreviewed. */

void FUN_40b32f1c(void)

{
  int in_v0;
  
  FUN_40b32c0c((char *)(in_v0 + -0x28));
  return;
}



/* 40b32f4c FUN_40b32f4c */

/* Boundary evidence: original MIPS .pdata 40b32f4c..40b32f7b. Semantic name remains unreviewed. */

void FUN_40b32f4c(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x44));
  return;
}



/* 40b32f7c FUN_40b32f7c */

/* Boundary evidence: original MIPS .pdata 40b32f7c..40b32fc7. Semantic name remains unreviewed. */

bool FUN_40b32f7c(int *param_1,uint *param_2)

{
  uint local_10 [2];
  
  (**(code **)(*param_1 + 0xc))(param_1,local_10);
  return (~local_10[0] & *param_2) != 0;
}



/* 40b32fc8 FUN_40b32fc8 */

/* Boundary evidence: original MIPS .pdata 40b32fc8..40b33003. Semantic name remains unreviewed. */

bool FUN_40b32fc8(undefined4 param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,&DAT_40b3d558,0x10);
  return iVar1 != 0;
}



/* 40b33034 FUN_40b33034 */

/* Boundary evidence: original MIPS .pdata 40b33034..40b3309b. Semantic name remains unreviewed. */

undefined4 FUN_40b33034(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b3d558,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40b3d508,0x10), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80040261;
  }
  return uVar2;
}



/* 40b3309c FUN_40b3309c */

/* Boundary evidence: original MIPS .pdata 40b3309c..40b331f3. Semantic name remains unreviewed. */

undefined4 FUN_40b3309c(int param_1,uint *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined4 *local_3c;
  uint local_38;
  uint local_34;
  int aiStack_30 [2];
  char acStack_28 [4];
  undefined1 auStack_24 [4];
  undefined4 *local_20;
  
  FUN_40b32990(acStack_28,*(int **)(param_1 + 4),'\0');
  local_48 = auStack_24;
  local_44 = *local_20;
  local_40 = auStack_24;
  uVar5 = 0;
  uVar4 = 0;
  while( true ) {
    local_3c = local_20;
    bVar1 = FUN_40b33f78((int *)&local_48,(int *)&local_40);
    if (CONCAT31(extraout_var,bVar1) == 0) break;
    puVar2 = (undefined4 *)FUN_40b33ea8((int *)&local_48);
    piVar3 = (int *)*puVar2;
    if (piVar3 == (int *)0x0) {
      FUN_40b3a3ec(0x80004003);
    }
    else {
      (**(code **)(*piVar3 + 4))(piVar3);
    }
    (**(code **)(*piVar3 + 0x28))(piVar3,&local_38);
    if (((int)uVar4 <= (int)local_34) && ((local_34 != uVar4 || (uVar5 < local_38)))) {
      uVar4 = local_34;
      uVar5 = local_38;
    }
    (**(code **)(*piVar3 + 8))(piVar3);
    FUN_40b33f00((int *)&local_48,aiStack_30);
  }
  *param_2 = uVar5;
  param_2[1] = uVar4;
  FUN_40b32c0c(acStack_28);
  return 0;
}



/* 40b331f4 FUN_40b331f4 */

/* Boundary evidence: original MIPS .pdata 40b331f4..40b33223. Semantic name remains unreviewed. */

void FUN_40b331f4(void)

{
  int in_v0;
  
  FUN_40b32c0c((char *)(in_v0 + -0x28));
  return;
}



/* 40b33224 FUN_40b33224 */

/* Boundary evidence: original MIPS .pdata 40b33224..40b33253. Semantic name remains unreviewed. */

void FUN_40b33224(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x50));
  return;
}



/* 40b33254 FUN_40b33254 */

/* Boundary evidence: original MIPS .pdata 40b33254..40b33353. Semantic name remains unreviewed. */

undefined4 FUN_40b33254(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int *local_28;
  int local_24;
  char acStack_20 [4];
  int iStack_1c;
  int *local_18;
  
  FUN_40b32990(acStack_20,*(int **)(param_1 + 4),'\0');
  if ((int *)*local_18 == local_18) {
    uVar3 = 0x80004002;
  }
  else {
    local_28 = &iStack_1c;
    local_24 = *local_18;
    puVar1 = (undefined4 *)FUN_40b33ea8((int *)&local_28);
    piVar2 = (int *)*puVar1;
    local_28 = piVar2;
    if (piVar2 == (int *)0x0) {
      FUN_40b3a3ec(0x80004003);
    }
    else {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    uVar3 = (**(code **)(*piVar2 + 0x2c))(piVar2,param_2);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  FUN_40b32c0c(acStack_20);
  return uVar3;
}



/* 40b33354 FUN_40b33354 */

/* Boundary evidence: original MIPS .pdata 40b33354..40b33383. Semantic name remains unreviewed. */

void FUN_40b33354(void)

{
  int in_v0;
  
  FUN_40b32c0c((char *)(in_v0 + -0x20));
  return;
}



/* 40b33384 FUN_40b33384 */

/* Boundary evidence: original MIPS .pdata 40b33384..40b333b3. Semantic name remains unreviewed. */

void FUN_40b33384(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x28));
  return;
}



/* 40b333b4 FUN_40b333b4 */

/* Boundary evidence: original MIPS .pdata 40b333b4..40b3343f. Semantic name remains unreviewed. */

undefined4
FUN_40b333b4(undefined4 param_1,undefined4 *param_2,void *param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,void *param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_3 == (void *)0x0) || (iVar1 = memcmp(param_3,&DAT_40b3d558,0x10), iVar1 == 0)) &&
     ((param_7 == (void *)0x0 || (iVar1 = memcmp(param_7,&DAT_40b3d558,0x10), iVar1 == 0)))) {
    uVar2 = 0;
    *param_2 = param_5;
    param_2[1] = param_6;
  }
  else {
    uVar2 = 0x80040261;
  }
  return uVar2;
}



/* 40b33440 FUN_40b33440 */

/* Boundary evidence: original MIPS .pdata 40b33440..40b3359b. Semantic name remains unreviewed. */

int FUN_40b33440(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined1 *local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined4 *local_3c;
  int aiStack_38 [2];
  char acStack_30 [4];
  undefined1 auStack_2c [4];
  undefined4 *local_28;
  
  FUN_40b32990(acStack_30,*(int **)(param_1 + 4),'\x01');
  local_48 = auStack_2c;
  local_44 = *local_28;
  local_40 = auStack_2c;
  iVar5 = 0;
  while( true ) {
    local_3c = local_28;
    bVar1 = FUN_40b33f78((int *)&local_48,(int *)&local_40);
    if (CONCAT31(extraout_var,bVar1) == 0) break;
    puVar2 = (undefined4 *)FUN_40b33ea8((int *)&local_48);
    piVar4 = (int *)*puVar2;
    if (piVar4 == (int *)0x0) {
      FUN_40b3a3ec(0x80004003);
    }
    else {
      (**(code **)(*piVar4 + 4))(piVar4);
    }
    iVar3 = (**(code **)(*piVar4 + 0x38))(piVar4,param_2,param_3,param_4,param_5);
    if ((iVar3 < 0) && (-1 < iVar5)) {
      iVar5 = iVar3;
    }
    (**(code **)(*piVar4 + 8))(piVar4);
    FUN_40b33f00((int *)&local_48,aiStack_38);
  }
  FUN_40b32c0c(acStack_30);
  return iVar5;
}



/* 40b3359c FUN_40b3359c */

/* Boundary evidence: original MIPS .pdata 40b3359c..40b335cb. Semantic name remains unreviewed. */

void FUN_40b3359c(void)

{
  int in_v0;
  
  FUN_40b32c0c((char *)(in_v0 + -0x30));
  return;
}



/* 40b335cc FUN_40b335cc */

/* Boundary evidence: original MIPS .pdata 40b335cc..40b335fb. Semantic name remains unreviewed. */

void FUN_40b335cc(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x50));
  return;
}



/* 40b335fc FUN_40b335fc */

/* Boundary evidence: original MIPS .pdata 40b335fc..40b3370b. Semantic name remains unreviewed. */

undefined4 FUN_40b335fc(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int *local_30;
  int local_2c;
  char acStack_28 [4];
  int iStack_24;
  int *local_20;
  
  FUN_40b32990(acStack_28,*(int **)(param_1 + 4),'\0');
  if ((int *)*local_20 == local_20) {
    uVar3 = 0x80004002;
  }
  else {
    local_30 = &iStack_24;
    local_2c = *local_20;
    puVar1 = (undefined4 *)FUN_40b33ea8((int *)&local_30);
    piVar2 = (int *)*puVar1;
    local_30 = piVar2;
    if (piVar2 == (int *)0x0) {
      FUN_40b3a3ec(0x80004003);
    }
    else {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    uVar3 = (**(code **)(*piVar2 + 0x3c))(piVar2,param_2,param_3);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  FUN_40b32c0c(acStack_28);
  return uVar3;
}



/* 40b3370c FUN_40b3370c */

/* Boundary evidence: original MIPS .pdata 40b3370c..40b3373b. Semantic name remains unreviewed. */

void FUN_40b3370c(void)

{
  int in_v0;
  
  FUN_40b32c0c((char *)(in_v0 + -0x28));
  return;
}



/* 40b3373c FUN_40b3373c */

/* Boundary evidence: original MIPS .pdata 40b3373c..40b3376b. Semantic name remains unreviewed. */

void FUN_40b3373c(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x30));
  return;
}



/* 40b3376c FUN_40b3376c */

/* Boundary evidence: original MIPS .pdata 40b3376c..40b33797. Semantic name remains unreviewed. */

void FUN_40b3376c(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  *param_2 = 0;
  param_2[1] = 0;
  (**(code **)(*param_1 + 0x28))(param_1,param_3);
  return;
}



/* 40b33798 FUN_40b33798 */

/* Boundary evidence: original MIPS .pdata 40b33798..40b338d3. Semantic name remains unreviewed. */

int FUN_40b33798(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined1 *local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined4 *local_34;
  int aiStack_30 [2];
  char acStack_28 [4];
  undefined1 auStack_24 [4];
  undefined4 *local_20;
  
  FUN_40b32990(acStack_28,*(int **)(param_1 + 4),'\x01');
  local_40 = auStack_24;
  local_3c = *local_20;
  local_38 = auStack_24;
  iVar5 = 0;
  while( true ) {
    local_34 = local_20;
    bVar1 = FUN_40b33f78((int *)&local_40,(int *)&local_38);
    if (CONCAT31(extraout_var,bVar1) == 0) break;
    puVar2 = (undefined4 *)FUN_40b33ea8((int *)&local_40);
    piVar4 = (int *)*puVar2;
    if (piVar4 == (int *)0x0) {
      FUN_40b3a3ec(0x80004003);
    }
    else {
      (**(code **)(*piVar4 + 4))(piVar4);
    }
    iVar3 = (**(code **)(*piVar4 + 0x44))(piVar4);
    if ((iVar3 < 0) && (-1 < iVar5)) {
      iVar5 = iVar3;
    }
    (**(code **)(*piVar4 + 8))(piVar4);
    FUN_40b33f00((int *)&local_40,aiStack_30);
  }
  FUN_40b32c0c(acStack_28);
  return iVar5;
}



/* 40b338d4 FUN_40b338d4 */

/* Boundary evidence: original MIPS .pdata 40b338d4..40b33903. Semantic name remains unreviewed. */

void FUN_40b338d4(void)

{
  int in_v0;
  
  FUN_40b32c0c((char *)(in_v0 + -0x28));
  return;
}



/* 40b33904 FUN_40b33904 */

/* Boundary evidence: original MIPS .pdata 40b33904..40b33933. Semantic name remains unreviewed. */

void FUN_40b33904(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x48));
  return;
}



/* 40b33934 FUN_40b33934 */

/* Boundary evidence: original MIPS .pdata 40b33934..40b33a33. Semantic name remains unreviewed. */

undefined4 FUN_40b33934(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int *local_28;
  int local_24;
  char acStack_20 [4];
  int iStack_1c;
  int *local_18;
  
  FUN_40b32990(acStack_20,*(int **)(param_1 + 4),'\0');
  if ((int *)*local_18 == local_18) {
    uVar3 = 0x80004002;
  }
  else {
    local_28 = &iStack_1c;
    local_24 = *local_18;
    puVar1 = (undefined4 *)FUN_40b33ea8((int *)&local_28);
    piVar2 = (int *)*puVar1;
    local_28 = piVar2;
    if (piVar2 == (int *)0x0) {
      FUN_40b3a3ec(0x80004003);
    }
    else {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    uVar3 = (**(code **)(*piVar2 + 0x48))(piVar2,param_2);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  FUN_40b32c0c(acStack_20);
  return uVar3;
}



/* 40b33a34 FUN_40b33a34 */

/* Boundary evidence: original MIPS .pdata 40b33a34..40b33a63. Semantic name remains unreviewed. */

void FUN_40b33a34(void)

{
  int in_v0;
  
  FUN_40b32c0c((char *)(in_v0 + -0x20));
  return;
}



/* 40b33a64 FUN_40b33a64 */

/* Boundary evidence: original MIPS .pdata 40b33a64..40b33a93. Semantic name remains unreviewed. */

void FUN_40b33a64(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x28));
  return;
}



/* 40b33a94 FUN_40b33a94 */

/* Boundary evidence: original MIPS .pdata 40b33a94..40b33beb. Semantic name remains unreviewed. */

undefined4 FUN_40b33a94(int param_1,uint *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined4 *local_3c;
  uint local_38;
  uint local_34;
  int aiStack_30 [2];
  char acStack_28 [4];
  undefined1 auStack_24 [4];
  undefined4 *local_20;
  
  FUN_40b32990(acStack_28,*(int **)(param_1 + 4),'\0');
  local_48 = auStack_24;
  local_44 = *local_20;
  local_40 = auStack_24;
  uVar5 = 0;
  uVar4 = 0;
  while( true ) {
    local_3c = local_20;
    bVar1 = FUN_40b33f78((int *)&local_48,(int *)&local_40);
    if (CONCAT31(extraout_var,bVar1) == 0) break;
    puVar2 = (undefined4 *)FUN_40b33ea8((int *)&local_48);
    piVar3 = (int *)*puVar2;
    if (piVar3 == (int *)0x0) {
      FUN_40b3a3ec(0x80004003);
    }
    else {
      (**(code **)(*piVar3 + 4))(piVar3);
    }
    (**(code **)(*piVar3 + 0x4c))(piVar3,&local_38);
    if (((int)uVar4 <= (int)local_34) && ((local_34 != uVar4 || (uVar5 < local_38)))) {
      uVar4 = local_34;
      uVar5 = local_38;
    }
    (**(code **)(*piVar3 + 8))(piVar3);
    FUN_40b33f00((int *)&local_48,aiStack_30);
  }
  *param_2 = uVar5;
  param_2[1] = uVar4;
  FUN_40b32c0c(acStack_28);
  return 0;
}



/* 40b33bec FUN_40b33bec */

/* Boundary evidence: original MIPS .pdata 40b33bec..40b33c1b. Semantic name remains unreviewed. */

void FUN_40b33bec(void)

{
  int in_v0;
  
  FUN_40b32c0c((char *)(in_v0 + -0x28));
  return;
}



/* 40b33c1c FUN_40b33c1c */

/* Boundary evidence: original MIPS .pdata 40b33c1c..40b33c4b. Semantic name remains unreviewed. */

void FUN_40b33c1c(void)

{
  int in_v0;
  
  FUN_40b33d0c((int *)(in_v0 + -0x50));
  return;
}



/* 40b33c4c FUN_40b33c4c */

/* Boundary evidence: original MIPS .pdata 40b33c4c..40b33cab. Semantic name remains unreviewed. */

int FUN_40b33c4c(int param_1,int param_2)

{
  FUN_40b342a4(param_1);
  FUN_40b34108(param_1,0,0);
  FUN_40b33fec(param_1,param_2,0,0xffffffff);
  return param_1;
}



/* 40b33cac FUN_40b33cac */

/* Boundary evidence: original MIPS .pdata 40b33cac..40b33ccb. Semantic name remains unreviewed. */

void FUN_40b33cac(int param_1)

{
  FUN_40b34108(param_1,1,0);
  return;
}



/* 40b33ccc FUN_40b33ccc */

/* Boundary evidence: original MIPS .pdata 40b33ccc..40b33d0b. Semantic name remains unreviewed. */

void FUN_40b33ccc(int param_1)

{
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}



/* 40b33d0c FUN_40b33d0c */

/* Boundary evidence: original MIPS .pdata 40b33d0c..40b33d3b. Semantic name remains unreviewed. */

void FUN_40b33d0c(int *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 8))();
  }
  return;
}



/* 40b33d3c FUN_40b33d3c */

/* Boundary evidence: original MIPS .pdata 40b33d3c..40b33da3. Semantic name remains unreviewed. */

void FUN_40b33d3c(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  void *pvVar3;
  
  piVar2 = *(int **)(param_1 + 4);
  puVar1 = (undefined4 *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  if (puVar1 != *(void **)(param_1 + 4)) {
    do {
      pvVar3 = (void *)*puVar1;
      operator_delete(puVar1);
      puVar1 = pvVar3;
    } while (pvVar3 != *(void **)(param_1 + 4));
  }
  operator_delete(*(void **)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



/* 40b33da4 FUN_40b33da4 */

/* Boundary evidence: original MIPS .pdata 40b33da4..40b33e77. Semantic name remains unreviewed. */

void FUN_40b33da4(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [32];
  undefined **appuStack_40 [10];
  uint local_18;
  
  local_18 = DAT_40b3f10c;
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = FUN_40b348b8(param_1,iVar2,*(undefined4 *)(iVar2 + 4),param_2);
  if (*(int *)(param_1 + 8) == 0x3fffffff) {
    FUN_40b34a2c((int)auStack_60,"list<T> too long");
    FUN_40b310d0((exception *)appuStack_40,auStack_60);
                    /* WARNING: Subroutine does not return */
    appuStack_40[0] = &PTR_FUN_40b3ddf8;
    __CxxThrowException(appuStack_40,(ThrowInfo *)&DAT_40b3ed30);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  *(int *)(iVar2 + 4) = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  FUN_40b39e00(local_18);
  return;
}



/* 40b33e78 FUN_40b33e78 */

/* Boundary evidence: original MIPS .pdata 40b33e78..40b33ea7. Semantic name remains unreviewed. */

void FUN_40b33e78(void)

{
  int in_v0;
  
  FUN_40b33cac(in_v0 + -0x60);
  return;
}



/* 40b33ea8 FUN_40b33ea8 */

/* Boundary evidence: original MIPS .pdata 40b33ea8..40b33eff. Semantic name remains unreviewed. */

int FUN_40b33ea8(int *param_1)

{
  if (*param_1 == 0) {
    FUN_40b3a7b4();
  }
  if (param_1[1] == *(int *)(*param_1 + 4)) {
    FUN_40b3a7b4();
  }
  return param_1[1] + 8;
}



/* 40b33f00 FUN_40b33f00 */

/* Boundary evidence: original MIPS .pdata 40b33f00..40b33f77. Semantic name remains unreviewed. */

int * FUN_40b33f00(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = param_1[1];
  *param_2 = iVar1;
  param_2[1] = iVar2;
  if (iVar1 == 0) {
    FUN_40b3a7b4();
  }
  if (param_1[1] == *(int *)(*param_1 + 4)) {
    FUN_40b3a7b4();
  }
  param_1[1] = *(int *)param_1[1];
  return param_2;
}



/* 40b33f78 FUN_40b33f78 */

/* Boundary evidence: original MIPS .pdata 40b33f78..40b33feb. Semantic name remains unreviewed. */

bool FUN_40b33f78(int *param_1,int *param_2)

{
  if ((*param_1 == 0) || (*param_1 != *param_2)) {
    FUN_40b3a7b4();
  }
  return param_1[1] != param_2[1];
}



/* 40b33fec FUN_40b33fec */

/* Boundary evidence: original MIPS .pdata 40b33fec..40b34107. Semantic name remains unreviewed. */

int FUN_40b33fec(int param_1,int param_2,uint param_3,uint param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *_Dst;
  int iVar2;
  undefined4 *puVar3;
  uint _MaxCount;
  
  if (*(uint *)(param_2 + 0x14) < param_3) {
    FUN_40b3a6dc();
  }
  _MaxCount = *(int *)(param_2 + 0x14) - param_3;
  if (param_4 < _MaxCount) {
    _MaxCount = param_4;
  }
  if (param_1 == param_2) {
    FUN_40b34314(param_1,_MaxCount + param_3,0xffffffff);
    FUN_40b34314(param_1,0,param_3);
  }
  else {
    bVar1 = FUN_40b343f8(param_1,_MaxCount,0);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        iVar2 = param_2 + 4;
      }
      else {
        iVar2 = *(int *)(param_2 + 4);
      }
      puVar3 = (undefined4 *)(param_1 + 4);
      _Dst = puVar3;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        _Dst = (undefined4 *)*puVar3;
      }
      memcpy_s(_Dst,*(uint *)(param_1 + 0x18),(void *)(iVar2 + param_3),_MaxCount);
      *(uint *)(param_1 + 0x14) = _MaxCount;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      *(undefined1 *)((int)puVar3 + _MaxCount) = 0;
    }
  }
  return param_1;
}



/* 40b34108 FUN_40b34108 */

/* Boundary evidence: original MIPS .pdata 40b34108..40b3418b. Semantic name remains unreviewed. */

void FUN_40b34108(int param_1,int param_2,rsize_t param_3)

{
  void *_Src;
  
  if ((param_2 != 0) && (0xf < *(uint *)(param_1 + 0x18))) {
    _Src = *(void **)(param_1 + 4);
    if (param_3 != 0) {
      memcpy_s((undefined4 *)(param_1 + 4),0x10,_Src,param_3);
    }
    operator_delete(_Src);
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(rsize_t *)(param_1 + 0x14) = param_3;
  *(undefined1 *)(param_1 + 4 + param_3) = 0;
  return;
}



/* 40b3418c FUN_40b3418c */

/* Boundary evidence: original MIPS .pdata 40b3418c..40b342a3. Semantic name remains unreviewed. */

int * FUN_40b3418c(int param_1,int *param_2,int param_3,undefined4 *param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 4);
  if ((uVar1 == 0) || ((int)(*(uint *)(param_1 + 8) - uVar1) >> 2 == 0)) {
    iVar2 = 0;
  }
  else {
    if (*(uint *)(param_1 + 8) < uVar1) {
      FUN_40b3a7b4();
    }
    if ((param_3 == 0) || (param_3 != param_1)) {
      FUN_40b3a7b4();
    }
    iVar2 = (int)((int)param_4 - uVar1) >> 2;
  }
  FUN_40b344e8(param_1,param_3,param_4,1,param_5);
  uVar1 = *(uint *)(param_1 + 4);
  if (*(uint *)(param_1 + 8) < uVar1) {
    FUN_40b3a7b4();
  }
  uVar1 = iVar2 * 4 + uVar1;
  if ((*(uint *)(param_1 + 8) < uVar1) || (uVar1 < *(uint *)(param_1 + 4))) {
    FUN_40b3a7b4();
  }
  *param_2 = param_1;
  param_2[1] = uVar1;
  return param_2;
}



/* 40b342a4 FUN_40b342a4 */

undefined4 FUN_40b342a4(undefined4 param_1)

{
  return param_1;
}



/* 40b342ac FUN_40b342ac */

/* Boundary evidence: original MIPS .pdata 40b342ac..40b342e3. Semantic name remains unreviewed. */

void FUN_40b342ac(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  return;
}



/* 40b342e4 FUN_40b342e4 */

/* Boundary evidence: original MIPS .pdata 40b342e4..40b34313. Semantic name remains unreviewed. */

undefined4 FUN_40b342e4(undefined4 param_1)

{
  FUN_40b34928(param_1);
  return param_1;
}



/* 40b34314 FUN_40b34314 */

/* Boundary evidence: original MIPS .pdata 40b34314..40b343f7. Semantic name remains unreviewed. */

int FUN_40b34314(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  if (*(uint *)(param_1 + 0x14) < param_2) {
    FUN_40b3a6dc();
  }
  uVar3 = *(int *)(param_1 + 0x14) - param_2;
  if (uVar3 < param_3) {
    param_3 = uVar3;
  }
  if (param_3 != 0) {
    piVar5 = (int *)(param_1 + 4);
    piVar2 = piVar5;
    piVar1 = piVar5;
    if (0xf < *(uint *)(param_1 + 0x18)) {
      piVar2 = (int *)*piVar5;
      piVar1 = (int *)*piVar5;
    }
    memmove_s((void *)((int)piVar2 + param_2),*(uint *)(param_1 + 0x18) - param_2,
              (void *)((int)piVar1 + param_3 + param_2),uVar3 - param_3);
    iVar4 = *(int *)(param_1 + 0x14) - param_3;
    *(int *)(param_1 + 0x14) = iVar4;
    if (0xf < *(uint *)(param_1 + 0x18)) {
      piVar5 = (int *)*piVar5;
    }
    *(undefined1 *)((int)piVar5 + iVar4) = 0;
  }
  return param_1;
}



/* 40b343f8 FUN_40b343f8 */

/* Boundary evidence: original MIPS .pdata 40b343f8..40b344e7. Semantic name remains unreviewed. */

bool FUN_40b343f8(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  
  if (param_2 == 0xffffffff) {
    FUN_40b3a64c();
  }
  if (*(uint *)(param_1 + 0x18) < param_2) {
    FUN_40b34a90(param_1,param_2,*(rsize_t *)(param_1 + 0x14));
  }
  else if ((param_3 == 0) || (0xf < param_2)) {
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        puVar2 = (undefined1 *)(param_1 + 4);
      }
      else {
        puVar2 = *(undefined1 **)(param_1 + 4);
      }
      *puVar2 = 0;
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x14);
    if (param_2 < *(uint *)(param_1 + 0x14)) {
      uVar1 = param_2;
    }
    FUN_40b34108(param_1,1,uVar1);
  }
  return param_2 != 0;
}



/* 40b344e8 FUN_40b344e8 */

/* WARNING: Removing unreachable block (ram,0x40b34778) */
/* Boundary evidence: original MIPS .pdata 40b344e8..40b34887. Semantic name remains unreviewed. */

void FUN_40b344e8(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  void *pvVar1;
  void *pvVar2;
  rsize_t rVar3;
  rsize_t _DstSize;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined **local_80 [4];
  undefined1 auStack_70 [32];
  undefined **appuStack_50 [10];
  uint local_28;
  
  local_28 = DAT_40b3f10c;
  iVar7 = *(int *)(param_1 + 4);
  uVar10 = *param_5;
  if (iVar7 == 0) {
    uVar8 = 0;
    iVar5 = 0;
  }
  else {
    uVar8 = *(int *)(param_1 + 0xc) - iVar7 >> 2;
    iVar5 = *(int *)(param_1 + 8) - iVar7 >> 2;
  }
  if (iVar5 == 0x3fffffff) {
    FUN_40b34a2c((int)auStack_70,"vector<T> too long");
    FUN_40b310d0((exception *)appuStack_50,auStack_70);
                    /* WARNING: Subroutine does not return */
    appuStack_50[0] = &PTR_FUN_40b3ddf8;
    __CxxThrowException(appuStack_50,(ThrowInfo *)&DAT_40b3ed30);
  }
  if (iVar7 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 8) - iVar7 >> 2;
  }
  if (uVar8 < iVar5 + 1U) {
    uVar9 = 0;
    if (uVar8 <= 0x3fffffff - (uVar8 >> 1)) {
      uVar9 = (uVar8 >> 1) + uVar8;
    }
    if (iVar7 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(param_1 + 8) - iVar7 >> 2;
    }
    if (uVar9 < iVar5 + 1U) {
      if (iVar7 == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(param_1 + 8) - iVar7 >> 2;
      }
      uVar9 = iVar7 + 1;
    }
    if (uVar9 == 0) {
      uVar8 = 0;
    }
    else {
      if (uVar9 == 0) {
        trap(0x1c00);
      }
      uVar8 = uVar9;
      if (0xffffffff / uVar9 < 4) {
        std::exception::exception((exception *)local_80,(char *)0x0);
        local_80[0] = &PTR_FUN_40b3dde0;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException(local_80,(ThrowInfo *)&DAT_40b3ed68);
      }
    }
    pvVar1 = operator_new(uVar8 << 2);
    iVar7 = (int)param_3 - (int)*(void **)(param_1 + 4) >> 2;
    rVar3 = iVar7 * 4;
    if (iVar7 != 0) {
      memmove_s(pvVar1,rVar3,*(void **)(param_1 + 4),rVar3);
    }
    *(undefined4 *)(rVar3 + (int)pvVar1) = uVar10;
    iVar7 = *(int *)(param_1 + 8) - (int)param_3 >> 2;
    if (iVar7 != 0) {
      _DstSize = iVar7 << 2;
      memmove_s((undefined4 *)(rVar3 + (int)pvVar1) + 1,_DstSize,param_3,_DstSize);
    }
    pvVar2 = *(void **)(param_1 + 4);
    if (pvVar2 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(param_1 + 8) - (int)pvVar2 >> 2;
    }
    if (pvVar2 != (void *)0x0) {
      operator_delete(pvVar2);
    }
    *(void **)(param_1 + 0xc) = (void *)(uVar9 * 4 + (int)pvVar1);
    *(void **)(param_1 + 8) = (void *)((iVar7 + 1) * 4 + (int)pvVar1);
    *(void **)(param_1 + 4) = pvVar1;
  }
  else {
    pvVar1 = *(void **)(param_1 + 8);
    if ((int)pvVar1 - (int)param_3 >> 2 == 0) {
      puVar6 = *(undefined4 **)(param_1 + 8);
      iVar7 = 1 - ((int)puVar6 - (int)param_3 >> 2);
      if (iVar7 != 0) {
        puVar4 = puVar6 + iVar7;
        do {
          *puVar6 = uVar10;
          puVar6 = puVar6 + 1;
        } while (puVar6 != puVar4);
      }
      puVar6 = *(undefined4 **)(param_1 + 8);
      *(undefined4 **)(param_1 + 8) = puVar6 + 1;
      for (; param_3 != puVar6; param_3 = param_3 + 1) {
        *param_3 = uVar10;
      }
    }
    else {
      pvVar2 = (void *)((int)pvVar1 + -4);
      iVar7 = (int)pvVar1 - (int)pvVar2 >> 2;
      rVar3 = iVar7 * 4;
      if (iVar7 != 0) {
        memmove_s(pvVar1,rVar3,pvVar2,rVar3);
      }
      iVar7 = (int)pvVar2 - (int)param_3 >> 2;
      *(void **)(param_1 + 8) = (void *)(rVar3 + (int)pvVar1);
      if (0 < iVar7) {
        memmove_s((void *)((int)pvVar1 + iVar7 * -4),iVar7 * 4,param_3,iVar7 * 4);
      }
      puVar6 = param_3 + 1;
      for (; param_3 != puVar6; param_3 = param_3 + 1) {
        *param_3 = uVar10;
      }
    }
  }
  FUN_40b39e00(local_28);
  return;
}



/* 40b34888 FUN_40b34888 */

/* Boundary evidence: original MIPS .pdata 40b34888..40b348b7. Semantic name remains unreviewed. */

void FUN_40b34888(void)

{
  int in_v0;
  
  FUN_40b33cac(in_v0 + -0x70);
  return;
}



/* 40b348b8 FUN_40b348b8 */

/* Boundary evidence: original MIPS .pdata 40b348b8..40b34927. Semantic name remains unreviewed. */

void FUN_40b348b8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_4;
  }
  return;
}



/* 40b34928 FUN_40b34928 */

/* Boundary evidence: original MIPS .pdata 40b34928..40b34957. Semantic name remains unreviewed. */

undefined4 FUN_40b34928(undefined4 param_1)

{
  FUN_40b342a4(param_1);
  return param_1;
}



/* 40b34958 FUN_40b34958 */

/* Boundary evidence: original MIPS .pdata 40b34958..40b3498f. Semantic name remains unreviewed. */

exception * FUN_40b34958(exception *param_1,exception *param_2)

{
  FUN_40b34990(param_1,param_2);
  *(undefined ***)param_1 = &PTR_FUN_40b3ddf8;
  return param_1;
}



/* 40b34990 FUN_40b34990 */

/* Boundary evidence: original MIPS .pdata 40b34990..40b349fb. Semantic name remains unreviewed. */

exception * FUN_40b34990(exception *param_1,exception *param_2)

{
  std::exception::exception(param_1,param_2);
  *(undefined ***)param_1 = &PTR_FUN_40b3ddec;
  FUN_40b33c4c((int)(param_1 + 0xc),param_2 + 0xc);
  return param_1;
}



/* 40b349fc FUN_40b349fc */

/* Boundary evidence: original MIPS .pdata 40b349fc..40b34a2b. Semantic name remains unreviewed. */

void FUN_40b349fc(void)

{
  undefined4 *in_v0;
  
  std::exception::~exception((exception *)*in_v0);
  return;
}



/* 40b34a2c FUN_40b34a2c */

/* Boundary evidence: original MIPS .pdata 40b34a2c..40b34a8f. Semantic name remains unreviewed. */

int FUN_40b34a2c(int param_1,char *param_2)

{
  size_t sVar1;
  
  FUN_40b342a4(param_1);
  FUN_40b34108(param_1,0,0);
  sVar1 = strlen(param_2);
  FUN_40b34c50(param_1,(undefined4 *)param_2,sVar1);
  return param_1;
}



/* 40b34a90 FUN_40b34a90 */

/* Boundary evidence: original MIPS .pdata 40b34a90..40b34bd3. Semantic name remains unreviewed. */

void FUN_40b34a90(int param_1,uint param_2,rsize_t param_3)

{
  undefined4 *_Dst;
  void *_Src;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2 | 0xf;
  if (uVar3 != 0xffffffff) {
    uVar1 = *(uint *)(param_1 + 0x18);
    uVar2 = uVar1 >> 1;
    param_2 = uVar3;
    if ((uVar3 / 3 < uVar2) && (uVar1 <= -uVar2 - 2)) {
      param_2 = uVar2 + uVar1;
    }
  }
  _Dst = (undefined4 *)FUN_40b34d90(param_2 + 1);
  if (param_3 != 0) {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      _Src = (void *)(param_1 + 4);
    }
    else {
      _Src = *(void **)(param_1 + 4);
    }
    memcpy_s(_Dst,param_2 + 1,_Src,param_3);
  }
  FUN_40b34108(param_1,1,0);
  *(undefined4 *)(param_1 + 4) = _Dst;
  *(uint *)(param_1 + 0x18) = param_2;
  *(rsize_t *)(param_1 + 0x14) = param_3;
  if (param_2 < 0x10) {
    _Dst = (undefined4 *)(param_1 + 4);
  }
  *(undefined1 *)((int)_Dst + param_3) = 0;
  return;
}



/* 40b34bd4 FUN_40b34bd4 */

/* Boundary evidence: original MIPS .pdata 40b34bd4..40b34c07. Semantic name remains unreviewed. */

void FUN_40b34bd4(void)

{
  int in_v0;
  
  FUN_40b34108(**(int **)(in_v0 + -4),1,0);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



/* 40b34c08 FUN_40b34c08 */

/* Boundary evidence: original MIPS .pdata 40b34c08..40b34c4f. Semantic name remains unreviewed. */

undefined * FUN_40b34c08(void)

{
  int in_v0;
  undefined4 uVar1;
  
  *(int *)(in_v0 + -0x20) = *(int *)(in_v0 + 4);
  uVar1 = FUN_40b34d90(*(int *)(in_v0 + 4) + 1);
  *(undefined4 *)(in_v0 + -0x1c) = uVar1;
  return &DAT_40b34b38;
}



/* 40b34c50 FUN_40b34c50 */

/* Boundary evidence: original MIPS .pdata 40b34c50..40b34d3b. Semantic name remains unreviewed. */

int FUN_40b34c50(int param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 *_Dst;
  undefined4 *puVar3;
  
  iVar2 = FUN_40b34d3c(param_1,param_2);
  if (iVar2 == 0) {
    bVar1 = FUN_40b343f8(param_1,param_3,0);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      puVar3 = (undefined4 *)(param_1 + 4);
      _Dst = puVar3;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        _Dst = (undefined4 *)*puVar3;
      }
      memcpy_s(_Dst,*(uint *)(param_1 + 0x18),param_2,param_3);
      *(uint *)(param_1 + 0x14) = param_3;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      *(undefined1 *)((int)puVar3 + param_3) = 0;
    }
  }
  else {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      iVar2 = param_1 + 4;
    }
    else {
      iVar2 = *(int *)(param_1 + 4);
    }
    param_1 = FUN_40b33fec(param_1,param_1,(int)param_2 - iVar2,param_3);
  }
  return param_1;
}



/* 40b34d3c FUN_40b34d3c */

undefined4 FUN_40b34d3c(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  bVar1 = 0xf < *(uint *)(param_1 + 0x18);
  puVar2 = (undefined4 *)(param_1 + 4);
  puVar3 = puVar2;
  if (bVar1) {
    puVar3 = (undefined4 *)*puVar2;
  }
  if (puVar3 <= param_2) {
    if (bVar1) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (param_2 < (undefined4 *)(*(int *)(param_1 + 0x14) + (int)puVar2)) {
      return 1;
    }
  }
  return 0;
}



/* 40b34d90 FUN_40b34d90 */

/* Boundary evidence: original MIPS .pdata 40b34d90..40b34e07. Semantic name remains unreviewed. */

void FUN_40b34d90(uint param_1)

{
  undefined **appuStack_18 [4];
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    if (param_1 == 0) {
      trap(0x1c00);
    }
    if (0xffffffff / param_1 == 0) {
      std::exception::exception((exception *)appuStack_18,(char *)0x0);
                    /* WARNING: Subroutine does not return */
      appuStack_18[0] = &PTR_FUN_40b3dde0;
      __CxxThrowException(appuStack_18,(ThrowInfo *)&DAT_40b3ed68);
    }
  }
  operator_new(param_1);
  return;
}



/* 40b34e08 FUN_40b34e08 */

/* Boundary evidence: original MIPS .pdata 40b34e08..40b34e3f. Semantic name remains unreviewed. */

exception * FUN_40b34e08(exception *param_1,exception *param_2)

{
  std::exception::exception(param_1,param_2);
  *(undefined ***)param_1 = &PTR_FUN_40b3dde0;
  return param_1;
}



/* 40b34f80 FUN_40b34f80 */

/* Boundary evidence: original MIPS .pdata 40b34f80..40b34fa7. Semantic name remains unreviewed. */

void FUN_40b34f80(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b34fa8 FUN_40b34fa8 */

/* Boundary evidence: original MIPS .pdata 40b34fa8..40b34fc3. Semantic name remains unreviewed. */

void FUN_40b34fa8(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



/* 40b34fc4 FUN_40b34fc4 */

/* Boundary evidence: original MIPS .pdata 40b34fc4..40b3510f. Semantic name remains unreviewed. */

undefined4 FUN_40b34fc4(HKEY param_1,wchar_t *param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  LSTATUS LVar3;
  int iVar4;
  HKEY local_238;
  DWORD local_234;
  _FILETIME _Stack_230;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_40b3f10c;
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    FUN_40b39e00(local_20);
    uVar2 = 0x80004005;
  }
  else {
    LVar3 = RegOpenKeyExW(param_1,param_2,0,0x2000000,&local_238);
    if (LVar3 == 0) {
      local_234 = 0x104;
      iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,&_Stack_230);
      while (iVar4 == 0) {
        FUN_40b34fc4(local_238,aWStack_228);
        local_234 = 0x104;
        iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,&_Stack_230);
      }
      RegCloseKey(local_238);
      RegDeleteKeyW(param_1,param_2);
    }
    FUN_40b39e00(local_20);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b35110 FUN_40b35110 */

/* Boundary evidence: original MIPS .pdata 40b35110..40b3539f. Semantic name remains unreviewed. */

uint FUN_40b35110(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  size_t sVar2;
  HKEY local_2a8;
  HKEY local_2a4;
  DWORD aDStack_2a0 [2];
  GUID local_298;
  OLECHAR aOStack_288 [40];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40b3f10c;
  local_298.Data1 = param_1;
  local_298._4_4_ = param_2;
  local_298.Data4._0_4_ = param_3;
  local_298.Data4._4_4_ = param_4;
  StringFromGUID2(&local_298,aOStack_288,0x27);
  wsprintfW(aWStack_238,L"CLSID\\%ls",aOStack_288);
  uVar1 = RegCreateKeyExW((HKEY)0x80000000,aWStack_238,0,L"",0,0,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_2a8,aDStack_2a0);
  if (uVar1 == 0) {
    wsprintfW(aWStack_238,L"%ls",param_5);
    sVar2 = wcslen(aWStack_238);
    uVar1 = RegSetValueExW(local_2a8,L"",0,1,(BYTE *)aWStack_238,(sVar2 + 1) * 2);
    if (uVar1 == 0) {
      wsprintfW(aWStack_238,L"%ls",param_8);
      uVar1 = RegCreateKeyExW(local_2a8,aWStack_238,0,L"",0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_2a4,
                              aDStack_2a0);
      if (uVar1 == 0) {
        wsprintfW(aWStack_238,L"%ls",param_6);
        sVar2 = wcslen(aWStack_238);
        uVar1 = RegSetValueExW(local_2a4,L"",0,1,(BYTE *)aWStack_238,(sVar2 + 1) * 2);
        if (uVar1 == 0) {
          wsprintfW(aWStack_238,L"%ls",param_7);
          sVar2 = wcslen(aWStack_238);
          uVar1 = RegSetValueExW(local_2a4,L"ThreadingModel",0,1,(BYTE *)aWStack_238,(sVar2 + 1) * 2
                                );
        }
        RegCloseKey(local_2a8);
        local_2a8 = local_2a4;
      }
    }
    RegCloseKey(local_2a8);
  }
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  FUN_40b39e00(local_30);
  return uVar1;
}



/* 40b353a0 FUN_40b353a0 */

/* Boundary evidence: original MIPS .pdata 40b353a0..40b35413. Semantic name remains unreviewed. */

undefined4 FUN_40b353a0(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GUID local_278;
  OLECHAR aOStack_268 [40];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40b3f10c;
  local_278.Data1 = param_1;
  local_278._4_4_ = param_2;
  local_278.Data4._0_4_ = param_3;
  local_278.Data4._4_4_ = param_4;
  StringFromGUID2(&local_278,aOStack_268,0x27);
  wsprintfW(aWStack_218,L"CLSID\\%ls",aOStack_268);
  FUN_40b34fc4((HKEY)0x80000000,aWStack_218);
  FUN_40b39e00(local_10);
  return 0;
}



/* 40b35414 FUN_40b35414 */

/* Boundary evidence: original MIPS .pdata 40b35414..40b3564b. Semantic name remains unreviewed. */

DWORD FUN_40b35414(void)

{
  DWORD DVar1;
  ulong *puVar2;
  DWORD DVar3;
  int iVar4;
  undefined **ppuVar5;
  int *local_240 [2];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40b3f10c;
  DVar3 = 0;
  DVar1 = GetModuleFileNameW(DAT_40b3f30c,aWStack_238,0x104);
  if (DVar1 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
  }
  else {
    iVar4 = 0;
    if (0 < DAT_40b3f164) {
      ppuVar5 = &PTR_u_Audio_Combiner_40b3f168;
      do {
        puVar2 = (ulong *)ppuVar5[1];
        DVar3 = FUN_40b35110(*puVar2,puVar2[1],puVar2[2],puVar2[3],*ppuVar5,aWStack_238,L"Both",
                             L"InprocServer32");
        if ((int)DVar3 < 0) break;
        if (ppuVar5[2] != (undefined *)0x0) {
          CoInitializeEx((LPVOID)0x0,0);
          DVar3 = CoCreateInstance((IID *)ppuVar5[1],(LPUNKNOWN)0x0,1,(IID *)&DAT_40b3d918,local_240
                                  );
          if ((int)DVar3 < 0) {
            if ((DVar3 == 0x80004002) || (DVar3 == 0x80040202)) {
              DVar3 = 0;
            }
          }
          else {
            DVar3 = (**(code **)(*local_240[0] + 0x10))();
            if (-1 < (int)DVar3) {
              DVar3 = (**(code **)(*local_240[0] + 0xc))();
            }
            (**(code **)(*local_240[0] + 8))();
          }
          CoFreeUnusedLibraries();
          CoUninitialize();
        }
        if ((int)DVar3 < 0) break;
        iVar4 = iVar4 + 1;
        ppuVar5 = ppuVar5 + 5;
      } while (iVar4 < DAT_40b3f164);
    }
  }
  FUN_40b39e00(local_30);
  return DVar3;
}



/* 40b3564c FUN_40b3564c */

/* Boundary evidence: original MIPS .pdata 40b3564c..40b357d3. Semantic name remains unreviewed. */

int FUN_40b3564c(void)

{
  ulong *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined **ppuVar4;
  int *local_30 [2];
  undefined **ppuVar5;
  
  HVar2 = 0;
  if (DAT_40b3f164 != 0) {
    iVar3 = DAT_40b3f164;
    ppuVar4 = &PTR_DAT_40b3f16c + DAT_40b3f164 * 5;
    while( true ) {
      ppuVar5 = ppuVar4 + -5;
      iVar3 = iVar3 + -1;
      if (ppuVar4[-4] != (undefined *)0x0) {
        CoInitializeEx((LPVOID)0x0,0);
        HVar2 = CoCreateInstance((IID *)*ppuVar5,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b3d918,local_30);
        if (HVar2 < 0) {
          if ((HVar2 == -0x7fffbffe) || (HVar2 == -0x7ffbfdfe)) {
            HVar2 = 0;
          }
        }
        else {
          HVar2 = (**(code **)(*local_30[0] + 0x10))();
          (**(code **)(*local_30[0] + 8))();
        }
        CoFreeUnusedLibraries();
        CoUninitialize();
      }
      if (HVar2 < 0) break;
      puVar1 = (ulong *)*ppuVar5;
      HVar2 = FUN_40b353a0(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      if (HVar2 < 0) {
        return HVar2;
      }
      ppuVar4 = ppuVar5;
      if (iVar3 == 0) {
        return HVar2;
      }
    }
  }
  return HVar2;
}



/* 40b357d4 FUN_40b357d4 */

/* Boundary evidence: original MIPS .pdata 40b357d4..40b35807. Semantic name remains unreviewed. */

void FUN_40b357d4(int param_1)

{
  if (param_1 == 0) {
    FUN_40b3564c();
  }
  else {
    FUN_40b35414();
  }
  return;
}



/* 40b3584c FUN_40b3584c */

/* Boundary evidence: original MIPS .pdata 40b3584c..40b358cb. Semantic name remains unreviewed. */

void FUN_40b3584c(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_40b3f164) {
    ppuVar2 = &PTR_DAT_40b3f16c;
    iVar1 = DAT_40b3f164;
    do {
      if ((code *)ppuVar2[2] != (code *)0x0) {
        (*(code *)ppuVar2[2])(param_1,*ppuVar2);
        iVar1 = DAT_40b3f164;
      }
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 5;
    } while (iVar3 < iVar1);
  }
  return;
}



/* 40b358cc FUN_40b358cc */

/* Boundary evidence: original MIPS .pdata 40b358cc..40b3596b. Semantic name remains unreviewed. */

undefined4 FUN_40b358cc(HMODULE param_1,int param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    if (param_2 != 1) {
      return 1;
    }
    DisableThreadLibraryCalls(param_1);
    DAT_40b3f308 = 1;
    DAT_40b3f1f4 = 0x114;
    BVar1 = GetVersionExW((LPOSVERSIONINFOW)&DAT_40b3f1f4);
    if (BVar1 != 0) {
      DAT_40b3f308 = DAT_40b3f204;
    }
    uVar2 = 1;
    DAT_40b3f30c = param_1;
  }
  FUN_40b3584c(uVar2);
  return 1;
}



/* 40b3596c FUN_40b3596c */

undefined4 FUN_40b3596c(int param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 4);
  if ((((*piVar2 != *param_2) || (piVar2[1] != param_2[1])) || (piVar2[2] != param_2[2])) ||
     (uVar1 = 1, piVar2[3] != param_2[3])) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b359bc FUN_40b359bc */

/* Boundary evidence: original MIPS .pdata 40b359bc..40b35a67. Semantic name remains unreviewed. */

undefined4 FUN_40b359bc(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40b3ddb8,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40b3dda8,0x10), iVar2 == 0)) {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      uVar1 = 0;
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b35a68 FUN_40b35a68 */

/* Boundary evidence: original MIPS .pdata 40b35a68..40b35abf. Semantic name remains unreviewed. */

void * FUN_40b35a68(void *param_1,uint param_2)

{
  FUN_40b35df4();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b35ac0 FUN_40b35ac0 */

/* Boundary evidence: original MIPS .pdata 40b35ac0..40b35be3. Semantic name remains unreviewed. */

int FUN_40b35ac0(int param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int local_20 [2];
  
  if (param_4 == 0) {
    local_20[0] = -0x7fffbffd;
  }
  else if ((param_2 == 0) || (iVar1 = memcmp(param_3,&DAT_40b3ddb8,0x10), iVar1 == 0)) {
    local_20[0] = 0;
    piVar2 = (int *)(**(code **)(*(int *)(param_1 + 4) + 8))(param_2,local_20);
    if (piVar2 == (int *)0x0) {
      if (-1 < local_20[0]) {
        local_20[0] = -0x7ff8fff2;
      }
    }
    else if (local_20[0] < 0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,1);
    }
    else {
      (**(code **)(*piVar2 + 4))(piVar2);
      local_20[0] = (**(code **)*piVar2)(piVar2,param_3,param_4);
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  else {
    local_20[0] = -0x7fffbffe;
  }
  return local_20[0];
}



/* 40b35be4 DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0x5be4  1  DllCanUnloadNow */
  if ((0 < DAT_40b3f310) || (HVar1 = 0, DAT_40b3f318 != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40b35c10 FUN_40b35c10 */

/* Boundary evidence: original MIPS .pdata 40b35c10..40b35c6b. Semantic name remains unreviewed. */

undefined4 * FUN_40b35c10(undefined4 *param_1,undefined4 param_2)

{
  FUN_40b35dc4(param_1 + 1);
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_40b3c0a8;
  param_1[2] = 0;
  return param_1;
}



/* 40b35c6c FUN_40b35c6c */

/* Boundary evidence: original MIPS .pdata 40b35c6c..40b35c9b. Semantic name remains unreviewed. */

int FUN_40b35c6c(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8) + -1;
  *(int *)((int)param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_40b35a68(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b35c9c DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40b35c9c..40b35dc3. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  int iVar7;
  
                    /* 0x5c9c  2  DllGetClassObject */
  iVar1 = memcmp(riid,&DAT_40b3ddb8,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(riid,&DAT_40b3dda8,0x10), iVar1 == 0)) {
    iVar1 = DAT_40b3f164;
    iVar7 = 0;
    if (0 < DAT_40b3f164) {
      ppuVar6 = &PTR_u_Audio_Combiner_40b3f168;
      do {
        iVar3 = FUN_40b3596c((int)ppuVar6,(int *)rclsid);
        if (iVar3 != 0) {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = FUN_40b35c10(puVar4,ppuVar6);
          }
          *ppv = piVar5;
          if (piVar5 == (int *)0x0) {
            return -0x7ff8fff2;
          }
          (**(code **)(*piVar5 + 4))(piVar5);
          return 0;
        }
        iVar7 = iVar7 + 1;
        ppuVar6 = ppuVar6 + 5;
      } while (iVar7 < iVar1);
    }
    HVar2 = -0x7ffbfeef;
  }
  else {
    HVar2 = -0x7fffbffe;
  }
  return HVar2;
}



/* 40b35dc4 FUN_40b35dc4 */

/* Boundary evidence: original MIPS .pdata 40b35dc4..40b35df3. Semantic name remains unreviewed. */

undefined4 FUN_40b35dc4(undefined4 param_1)

{
  InterlockedIncrement(&DAT_40b3f318);
  return param_1;
}



/* 40b35df4 FUN_40b35df4 */

/* Boundary evidence: original MIPS .pdata 40b35df4..40b35e4b. Semantic name remains unreviewed. */

void FUN_40b35df4(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(&DAT_40b3f318);
  if ((LVar1 == 0) && (DAT_40b3f314 != 0)) {
    FreeLibrary((HMODULE)DAT_40b3f314);
    DAT_40b3f314 = 0;
  }
  return;
}



/* 40b35e4c FUN_40b35e4c */

/* Boundary evidence: original MIPS .pdata 40b35e4c..40b35e8b. Semantic name remains unreviewed. */

undefined4 FUN_40b35e4c(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = param_1;
    (**(code **)(*param_1 + 4))();
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b35e8c FUN_40b35e8c */

/* Boundary evidence: original MIPS .pdata 40b35e8c..40b35ee7. Semantic name remains unreviewed. */

undefined4 * FUN_40b35e8c(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40b3c0d8;
  InterlockedIncrement(&DAT_40b3f318);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40b35ee8 FUN_40b35ee8 */

/* Boundary evidence: original MIPS .pdata 40b35ee8..40b35f6b. Semantic name remains unreviewed. */

undefined4 FUN_40b35ee8(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40b3ddb8,0x10);
    if (iVar2 == 0) {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      uVar1 = 0;
    }
    else {
      *param_3 = 0;
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b35f6c FUN_40b35f6c */

/* Boundary evidence: original MIPS .pdata 40b35f6c..40b35fa7. Semantic name remains unreviewed. */

uint FUN_40b35f6c(int param_1)

{
  uint uVar1;
  
  InterlockedIncrement((LONG *)(param_1 + 8));
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 2) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 40b35fa8 FUN_40b35fa8 */

/* Boundary evidence: original MIPS .pdata 40b35fa8..40b3601f. Semantic name remains unreviewed. */

uint FUN_40b35fa8(int *param_1)

{
  LONG LVar1;
  uint uVar2;
  uint *lpAddend;
  
  lpAddend = (uint *)(param_1 + 2);
  LVar1 = InterlockedDecrement((LONG *)lpAddend);
  if (LVar1 == 0) {
    *lpAddend = *lpAddend + 1;
    (**(code **)(*param_1 + 0xc))(param_1,1);
    uVar2 = 0;
  }
  else {
    uVar2 = *lpAddend;
    if (uVar2 < 2) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 40b36088 FUN_40b36088 */

/* Boundary evidence: original MIPS .pdata 40b36088..40b36113. Semantic name remains unreviewed. */

undefined4 FUN_40b36088(int param_1,short *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if (*(short **)(param_1 + 0x30) == (short *)0x0) {
      *param_2 = 0;
    }
    else {
      FUN_40b39aa8(param_2,*(short **)(param_1 + 0x30),0x80);
    }
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x34);
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x34) + 4))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b3611c FUN_40b3611c */

/* Boundary evidence: original MIPS .pdata 40b3611c..40b36137. Semantic name remains unreviewed. */

void FUN_40b3611c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x48));
  return;
}



/* 40b36138 FUN_40b36138 */

/* Boundary evidence: original MIPS .pdata 40b36138..40b36183. Semantic name remains unreviewed. */

void FUN_40b36138(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40b3c0e4;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 8))();
  FUN_40b39d28(param_1 + 6);
  return;
}



/* 40b36184 FUN_40b36184 */

/* Boundary evidence: original MIPS .pdata 40b36184..40b3621b. Semantic name remains unreviewed. */

undefined4 FUN_40b36184(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40b3d848,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40b3ddb8,0x10), iVar2 == 0)) {
      uVar1 = FUN_40b35e4c(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b3621c FUN_40b3621c */

/* Boundary evidence: original MIPS .pdata 40b3621c..40b36237. Semantic name remains unreviewed. */

void FUN_40b3621c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



/* 40b36238 FUN_40b36238 */

/* Boundary evidence: original MIPS .pdata 40b36238..40b36293. Semantic name remains unreviewed. */

LONG FUN_40b36238(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40b36294 FUN_40b36294 */

/* Boundary evidence: original MIPS .pdata 40b36294..40b362f3. Semantic name remains unreviewed. */

undefined4 FUN_40b36294(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_40b39b94((undefined4 *)(param_1 + 0x18));
  return 0;
}



/* 40b362f4 FUN_40b362f4 */

/* Boundary evidence: original MIPS .pdata 40b362f4..40b3634b. Semantic name remains unreviewed. */

undefined4 FUN_40b362f4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  return 0;
}



/* 40b3634c FUN_40b3634c */

/* Boundary evidence: original MIPS .pdata 40b3634c..40b363e3. Semantic name remains unreviewed. */

undefined4 FUN_40b3634c(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40b3d858,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40b3ddb8,0x10), iVar2 == 0)) {
      uVar1 = FUN_40b35e4c(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b363e4 FUN_40b363e4 */

/* Boundary evidence: original MIPS .pdata 40b363e4..40b363ff. Semantic name remains unreviewed. */

void FUN_40b363e4(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



/* 40b36400 FUN_40b36400 */

/* Boundary evidence: original MIPS .pdata 40b36400..40b3645b. Semantic name remains unreviewed. */

LONG FUN_40b36400(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40b3645c FUN_40b3645c */

/* Boundary evidence: original MIPS .pdata 40b3645c..40b3649b. Semantic name remains unreviewed. */

undefined4 FUN_40b3645c(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return 0;
}



/* 40b3649c FUN_40b3649c */

/* Boundary evidence: original MIPS .pdata 40b3649c..40b364df. Semantic name remains unreviewed. */

void FUN_40b3649c(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x14));
  }
  FUN_40b3970c(param_1 + 0x1c);
  FUN_40b35df4();
  return;
}



/* 40b364e0 FUN_40b364e0 */

/* Boundary evidence: original MIPS .pdata 40b364e0..40b36587. Semantic name remains unreviewed. */

void FUN_40b364e0(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b3d838,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b3d978,0x10);
    if (iVar1 != 0) {
      FUN_40b35ee8(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40b35e4c(piVar2,param_3);
  return;
}



/* 40b36588 FUN_40b36588 */

/* Boundary evidence: original MIPS .pdata 40b36588..40b365b3. Semantic name remains unreviewed. */

void FUN_40b36588(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 4))();
  return;
}



/* 40b365b4 FUN_40b365b4 */

/* Boundary evidence: original MIPS .pdata 40b365b4..40b365df. Semantic name remains unreviewed. */

void FUN_40b365b4(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 8))();
  return;
}



/* 40b365e0 FUN_40b365e0 */

undefined4 FUN_40b365e0(void)

{
  return 0;
}



/* 40b365e8 FUN_40b365e8 */

/* Boundary evidence: original MIPS .pdata 40b365e8..40b36607. Semantic name remains unreviewed. */

undefined4 FUN_40b365e8(int param_1,void *param_2)

{
  FUN_40b397e0((void *)(param_1 + 0x1c),param_2);
  return 0;
}



/* 40b36608 FUN_40b36608 */

/* Boundary evidence: original MIPS .pdata 40b36608..40b3665f. Semantic name remains unreviewed. */

undefined4 FUN_40b36608(int param_1,int *param_2)

{
  undefined4 uVar1;
  int local_10 [2];
  
  (**(code **)(*param_2 + 0x24))(param_2,local_10);
  if (local_10[0] == *(int *)(param_1 + 100)) {
    uVar1 = 0x80040208;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b36660 FUN_40b36660 */

/* Boundary evidence: original MIPS .pdata 40b36660..40b366b3. Semantic name remains unreviewed. */

undefined4 FUN_40b36660(int param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = *(int **)(param_1 + 0xc);
    *param_2 = (int)piVar2;
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x80040209;
    }
    else {
      (**(code **)(*piVar2 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40b366b4 FUN_40b366b4 */

/* Boundary evidence: original MIPS .pdata 40b366b4..40b3675f. Semantic name remains unreviewed. */

undefined4 FUN_40b366b4(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if (*(int *)(param_1 + 100) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 100) + 0xc;
    }
    *param_2 = iVar2;
    if (*(int *)(param_1 + 100) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 100) + 0xc) + 4))();
    }
    if (*(short **)(param_1 + 8) == (short *)0x0) {
      *(undefined2 *)(param_2 + 2) = 0;
    }
    else {
      FUN_40b39aa8((short *)(param_2 + 2),*(short **)(param_1 + 8),0x80);
    }
    uVar1 = 0;
    param_2[1] = *(int *)(param_1 + 0x58);
  }
  return uVar1;
}



/* 40b36788 FUN_40b36788 */

/* Boundary evidence: original MIPS .pdata 40b36788..40b367cf. Semantic name remains unreviewed. */

int FUN_40b36788(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x20))();
    if (iVar1 < 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}



/* 40b367d8 FUN_40b367d8 */

/* Boundary evidence: original MIPS .pdata 40b367d8..40b36827. Semantic name remains unreviewed. */

undefined4 FUN_40b367d8(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x58);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 100) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b36858 FUN_40b36858 */

/* Boundary evidence: original MIPS .pdata 40b36858..40b3687f. Semantic name remains unreviewed. */

void FUN_40b36858(int *param_1)

{
  (**(code **)(*param_1 + 0x38))(param_1,param_1[0x27],param_1 + 0x26);
  return;
}



/* 40b36880 FUN_40b36880 */

/* Boundary evidence: original MIPS .pdata 40b36880..40b368e7. Semantic name remains unreviewed. */

int FUN_40b36880(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b36608(param_1,param_2);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)*param_2)(param_2,&DAT_40b3d908,param_1 + 0x9c), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b368e8 FUN_40b368e8 */

/* Boundary evidence: original MIPS .pdata 40b368e8..40b3694b. Semantic name remains unreviewed. */

undefined4 FUN_40b368e8(int param_1)

{
  if (*(int **)(param_1 + 0x98) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x98) + 8))();
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  return 0;
}



/* 40b3694c FUN_40b3694c */

/* Boundary evidence: original MIPS .pdata 40b3694c..40b36987. Semantic name remains unreviewed. */

void FUN_40b3694c(undefined4 param_1,LPVOID *param_2)

{
  CoCreateInstance((IID *)&DAT_40b3ceb8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b3d8e8,param_2);
  return;
}



/* 40b36988 FUN_40b36988 */

/* Boundary evidence: original MIPS .pdata 40b36988..40b36b13. Semantic name remains unreviewed. */

int FUN_40b36988(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined1 auStack_28 [8];
  int local_20;
  
  *param_3 = 0;
  memset(auStack_28,0,0x10);
  (**(code **)(*param_2 + 0x14))(param_2,auStack_28);
  if (local_20 == 0) {
    local_20 = 1;
  }
  iVar1 = (**(code **)(*param_2 + 0xc))(param_2,param_3);
  if (((iVar1 < 0) ||
      (iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,*param_3,auStack_28), iVar1 < 0)) ||
     (iVar1 = (**(code **)(*param_2 + 0x10))(param_2,*param_3,0), iVar1 < 0)) {
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 8))();
      *param_3 = 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x48))(param_1,param_3);
    if (((iVar1 < 0) ||
        (iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,*param_3,auStack_28), iVar1 < 0)) ||
       (iVar1 = (**(code **)(*param_2 + 0x10))(param_2,*param_3,0), iVar1 < 0)) {
      if ((int *)*param_3 == (int *)0x0) {
        return iVar1;
      }
      (**(code **)(*(int *)*param_3 + 8))();
      *param_3 = 0;
      return iVar1;
    }
  }
  return 0;
}



/* 40b36b14 FUN_40b36b14 */

/* Boundary evidence: original MIPS .pdata 40b36b14..40b36b5b. Semantic name remains unreviewed. */

undefined4 FUN_40b36b14(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x98) == (int *)0x0) {
    uVar1 = 0x80004002;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x1c))();
  }
  return uVar1;
}



/* 40b36b5c FUN_40b36b5c */

/* Boundary evidence: original MIPS .pdata 40b36b5c..40b36b9b. Semantic name remains unreviewed. */

undefined4 FUN_40b36b5c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x9c) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x9c) + 0x18))();
  }
  return uVar1;
}



/* 40b36b9c FUN_40b36b9c */

/* Boundary evidence: original MIPS .pdata 40b36b9c..40b36bdb. Semantic name remains unreviewed. */

undefined4 FUN_40b36b9c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x38))();
  }
  return uVar1;
}



/* 40b36bdc FUN_40b36bdc */

/* Boundary evidence: original MIPS .pdata 40b36bdc..40b36c1b. Semantic name remains unreviewed. */

undefined4 FUN_40b36bdc(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x98) == 0) {
    uVar1 = 0x8004020a;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x14))();
  }
  return uVar1;
}



/* 40b36c1c FUN_40b36c1c */

/* Boundary evidence: original MIPS .pdata 40b36c1c..40b36c5b. Semantic name remains unreviewed. */

undefined4 FUN_40b36c1c(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x6c) = 0;
  if (*(int **)(param_1 + 0x98) == (int *)0x0) {
    uVar1 = 0x8004020a;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x18))();
  }
  return uVar1;
}



/* 40b36c5c FUN_40b36c5c */

/* Boundary evidence: original MIPS .pdata 40b36c5c..40b36ca7. Semantic name remains unreviewed. */

bool FUN_40b36c5c(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  return iVar1 != *(int *)(param_1 + 0x10);
}



/* 40b36cb4 FUN_40b36cb4 */

/* Boundary evidence: original MIPS .pdata 40b36cb4..40b36cff. Semantic name remains unreviewed. */

bool FUN_40b36cb4(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  return iVar1 != *(int *)(param_1 + 0xc);
}



/* 40b36d00 FUN_40b36d00 */

/* Boundary evidence: original MIPS .pdata 40b36d00..40b36d3f. Semantic name remains unreviewed. */

undefined4 FUN_40b36d00(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x3c))();
  }
  return uVar1;
}



/* 40b36d40 FUN_40b36d40 */

/* Boundary evidence: original MIPS .pdata 40b36d40..40b36d7f. Semantic name remains unreviewed. */

undefined4 FUN_40b36d40(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x40))();
  }
  return uVar1;
}



/* 40b36d80 FUN_40b36d80 */

/* Boundary evidence: original MIPS .pdata 40b36d80..40b36ddb. Semantic name remains unreviewed. */

undefined4 FUN_40b36d80(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x44))();
  }
  return uVar1;
}



/* 40b36ddc FUN_40b36ddc */

/* Boundary evidence: original MIPS .pdata 40b36ddc..40b36e23. Semantic name remains unreviewed. */

void FUN_40b36ddc(int param_1)

{
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40b3649c(param_1);
  return;
}



/* 40b36e24 FUN_40b36e24 */

/* Boundary evidence: original MIPS .pdata 40b36e24..40b36ea3. Semantic name remains unreviewed. */

void FUN_40b36e24(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b3d908,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x26;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40b35e4c(piVar2,param_3);
  }
  else {
    FUN_40b364e0(param_1,param_2,param_3);
  }
  return;
}



/* 40b36ea4 FUN_40b36ea4 */

/* Boundary evidence: original MIPS .pdata 40b36ea4..40b36f6b. Semantic name remains unreviewed. */

HRESULT FUN_40b36ea4(int param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 != (undefined4 *)0x0) {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    ppv = (LPVOID *)(param_1 + 4);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_40b3ceb8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b3d8e8,ppv),
       -1 < HVar1)) {
      *param_2 = *ppv;
      (**(code **)(*(int *)*ppv + 4))();
      HVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
    return HVar1;
  }
  return -0x7fffbffd;
}



/* 40b36f6c FUN_40b36f6c */

/* Boundary evidence: original MIPS .pdata 40b36f6c..40b3700b. Semantic name remains unreviewed. */

undefined4 FUN_40b36f6c(int param_1,int *param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    piVar2 = *(int **)(param_1 + 4);
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 4) = param_2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(undefined1 *)(param_1 + 8) = param_3;
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b3700c FUN_40b3700c */

/* Boundary evidence: original MIPS .pdata 40b3700c..40b37293. Semantic name remains unreviewed. */

int FUN_40b3700c(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *local_20 [2];
  
  if (param_2 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    piVar3 = (int *)(param_1 + -0x98);
    iVar2 = (**(code **)(*piVar3 + 0x38))(piVar3);
    if (iVar2 == 0) {
      iVar2 = (**(code **)*param_2)(param_2,&UNK_40b3d8d8,local_20);
      if (iVar2 < 0) {
        *(undefined4 *)(param_1 + 0x10) = 0x30;
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined4 *)(param_1 + 0x30) = 0;
        *(undefined4 *)(param_1 + 0x18) = 0;
        iVar2 = (**(code **)(*param_2 + 0x3c))(param_2);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 4;
        }
        iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 2;
        }
        iVar2 = (**(code **)(*param_2 + 0x1c))(param_2);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 1;
        }
        iVar2 = (**(code **)(*param_2 + 0x14))
                          (param_2,(undefined4 *)(param_1 + 0x20),(undefined4 *)(param_1 + 0x28));
        if (iVar2 < 0) {
          *(undefined4 *)(param_1 + 0x20) = 0;
          *(undefined4 *)(param_1 + 0x24) = 0;
          *(undefined4 *)(param_1 + 0x28) = 0;
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        else {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x110;
        }
        iVar2 = (**(code **)(*param_2 + 0x34))(param_2,param_1 + 0x34);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
        }
        (**(code **)(*param_2 + 0xc))(param_2,param_1 + 0x38);
        uVar1 = (**(code **)(*param_2 + 0x2c))(param_2);
        *(undefined4 *)(param_1 + 0x1c) = uVar1;
        uVar1 = (**(code **)(*param_2 + 0x10))(param_2);
        *(undefined4 *)(param_1 + 0x3c) = uVar1;
      }
      else {
        iVar2 = (**(code **)(*local_20[0] + 0x4c))(local_20[0],0x30,param_1 + 0x10);
        (**(code **)(*local_20[0] + 8))();
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      if (((*(uint *)(param_1 + 0x18) & 8) == 0) ||
         (iVar2 = (**(code **)(*piVar3 + 0x20))(piVar3,*(undefined4 *)(param_1 + 0x34)), iVar2 == 0)
         ) {
        iVar2 = 0;
      }
      else {
        *(undefined4 *)(param_1 + -0x2c) = 1;
        (**(code **)(*(int *)(param_1 + -0x8c) + 0x38))();
        piVar3 = *(int **)(*(int *)(param_1 + -0x28) + 0x44);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0xc))(piVar3,3,0x8004022a,0);
        }
        iVar2 = -0x7ffbfe00;
      }
    }
  }
  return iVar2;
}



/* 40b37294 FUN_40b37294 */

/* Boundary evidence: original MIPS .pdata 40b37294..40b3732f. Semantic name remains unreviewed. */

int FUN_40b37294(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    while (iVar1 = 0, 0 < param_3) {
      param_3 = param_3 + -1;
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,*(undefined4 *)(*param_4 * 4 + param_2));
      if (iVar1 != 0) {
        return iVar1;
      }
      *param_4 = *param_4 + 1;
    }
  }
  return iVar1;
}



/* 40b37330 FUN_40b37330 */

/* Boundary evidence: original MIPS .pdata 40b37330..40b3748f. Semantic name remains unreviewed. */

int FUN_40b37330(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *local_30;
  int *local_2c;
  int local_28 [2];
  
  iVar1 = (**(code **)(**(int **)(param_1 + -0x28) + 0x18))();
  iVar5 = 0;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = (**(code **)(**(int **)(param_1 + -0x28) + 0x1c))(*(int **)(param_1 + -0x28),iVar4);
      piVar3 = (int *)(iVar2 + 0xc);
      iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,local_28);
      if (iVar2 < 0) {
        return iVar2;
      }
      if ((local_28[0] == 1) &&
         (iVar2 = (**(code **)(*piVar3 + 0x18))(piVar3,&local_30), -1 < iVar2)) {
        iVar5 = iVar5 + 1;
        iVar2 = (**(code **)*local_30)(local_30,&DAT_40b3d908,&local_2c);
        (**(code **)(*local_30 + 8))();
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = (**(code **)(*local_2c + 0x20))();
        (**(code **)(*local_2c + 8))();
        if (iVar2 != 1) {
          return 0;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
    if (iVar5 != 0) {
      return 1;
    }
  }
  return 0;
}



/* 40b37490 FUN_40b37490 */

/* Boundary evidence: original MIPS .pdata 40b37490..40b374d7. Semantic name remains unreviewed. */

undefined4 FUN_40b37490(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b374d8 FUN_40b374d8 */

/* Boundary evidence: original MIPS .pdata 40b374d8..40b3751b. Semantic name remains unreviewed. */

undefined4 FUN_40b374d8(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b3753c FUN_40b3753c */

/* Boundary evidence: original MIPS .pdata 40b3753c..40b3757b. Semantic name remains unreviewed. */

undefined4 FUN_40b3753c(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x9c);
  *(undefined4 *)(param_1 + 0x6c) = 0;
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x8004020a;
  }
  else {
    *(undefined1 *)(param_1 + 0xa1) = 0;
    uVar1 = (**(code **)(*piVar2 + 0x18))(piVar2);
  }
  return uVar1;
}



/* 40b375dc FUN_40b375dc */

/* Boundary evidence: original MIPS .pdata 40b375dc..40b37833. Semantic name remains unreviewed. */

int FUN_40b375dc(undefined4 *param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 1;
  }
  else {
    puVar2 = (undefined4 *)*param_1;
    iVar1 = (**(code **)(*param_2 + 0x1c))(param_2,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    if (param_3 != 0) {
      puVar2 = (undefined4 *)*param_1;
      iVar1 = (**(code **)(*param_2 + 0xc))
                        (param_2,*puVar2,puVar2[1],puVar2[2],puVar2[3],param_1[1],param_1[2]);
      if ((-1 < iVar1) && (uVar7 = 0, param_1[3] != 0)) {
        iVar6 = 0;
        while( true ) {
          puVar5 = (undefined4 *)*param_1;
          iVar1 = param_1[4] + iVar6;
          puVar2 = *(undefined4 **)(iVar1 + 0x14);
          puVar4 = (undefined4 *)(param_1[4] + iVar6);
          iVar1 = (**(code **)(*param_2 + 0x14))
                            (param_2,*puVar5,puVar5[1],puVar5[2],puVar5[3],*puVar4,puVar4[1],
                             puVar4[2],puVar4[3],puVar4[4],*puVar2,puVar2[1],puVar2[2],puVar2[3],
                             *(undefined4 *)(iVar1 + 0x18));
          if (iVar1 < 0) break;
          iVar3 = param_1[4];
          uVar8 = 0;
          if (*(int *)(iVar6 + iVar3 + 0x1c) != 0) {
            iVar9 = 0;
            do {
              puVar5 = (undefined4 *)*param_1;
              puVar2 = (undefined4 *)(((undefined4 *)(iVar6 + iVar3))[8] + iVar9);
              puVar4 = (undefined4 *)puVar2[1];
              puVar2 = (undefined4 *)*puVar2;
              iVar1 = (**(code **)(*param_2 + 0x18))
                                (param_2,*puVar5,puVar5[1],puVar5[2],puVar5[3],
                                 *(undefined4 *)(iVar6 + iVar3),*puVar2,puVar2[1],puVar2[2],
                                 puVar2[3],*puVar4,puVar4[1],puVar4[2],puVar4[3]);
              if (iVar1 < 0) goto LAB_40b377fc;
              iVar3 = param_1[4];
              uVar8 = uVar8 + 1;
              iVar9 = iVar9 + 8;
            } while (uVar8 < *(uint *)(iVar6 + iVar3 + 0x1c));
          }
          uVar7 = uVar7 + 1;
          iVar6 = iVar6 + 0x24;
          if ((uint)param_1[3] <= uVar7) break;
        }
      }
    }
LAB_40b377fc:
    if (iVar1 == -0x7ff8fffe) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40b37834 FUN_40b37834 */

/* Boundary evidence: original MIPS .pdata 40b37834..40b37913. Semantic name remains unreviewed. */

void FUN_40b37834(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b3d898,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40b3d888,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40b3ddc8,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b3d918,0x10);
    if (iVar1 != 0) {
      FUN_40b35ee8(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40b35e4c(piVar2,param_3);
  return;
}



/* 40b37914 FUN_40b37914 */

/* Boundary evidence: original MIPS .pdata 40b37914..40b3796f. Semantic name remains unreviewed. */

void FUN_40b37914(int param_1)

{
  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x3c));
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  FUN_40b35df4();
  return;
}



/* 40b37970 FUN_40b37970 */

/* Boundary evidence: original MIPS .pdata 40b37970..40b379f3. Semantic name remains unreviewed. */

undefined4 FUN_40b37970(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  EnterCriticalSection(lpCriticalSection);
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  if (*(int **)(param_1 + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xc) + 8))();
  }
  *(int **)(param_1 + 0xc) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b379f4 FUN_40b379f4 */

/* Boundary evidence: original MIPS .pdata 40b379f4..40b37a77. Semantic name remains unreviewed. */

undefined4 FUN_40b379f4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
    EnterCriticalSection(lpCriticalSection);
    if (*(int **)(param_1 + 0xc) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 4))();
    }
    *param_2 = *(undefined4 *)(param_1 + 0xc);
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b37a78 FUN_40b37a78 */

/* Boundary evidence: original MIPS .pdata 40b37a78..40b37b5b. Semantic name remains unreviewed. */

int FUN_40b37a78(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar6;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  EnterCriticalSection(lpCriticalSection);
  iVar4 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    piVar6 = (int *)(param_1 + -0xc);
    iVar1 = (**(code **)(*piVar6 + 0x18))(piVar6);
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        piVar2 = (int *)(**(code **)(*piVar6 + 0x1c))(piVar6,iVar5);
        if (((piVar2[6] != 0) && (iVar3 = (**(code **)(*piVar2 + 0x18))(piVar2), iVar3 < 0)) &&
           (-1 < iVar4)) {
          iVar4 = iVar3;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
  }
  *(undefined4 *)(param_1 + 8) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return iVar4;
}



/* 40b37b5c FUN_40b37b5c */

/* Boundary evidence: original MIPS .pdata 40b37b5c..40b37c3f. Semantic name remains unreviewed. */

int FUN_40b37b5c(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar5;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) == 0) {
    piVar5 = (int *)(param_1 + -0xc);
    iVar1 = (**(code **)(*piVar5 + 0x18))(piVar5);
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        piVar2 = (int *)(**(code **)(*piVar5 + 0x1c))(piVar5,iVar4);
        if ((piVar2[6] != 0) && (iVar3 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar3 < 0))
        goto LAB_40b37c10;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  *(undefined4 *)(param_1 + 8) = 1;
  iVar3 = 0;
LAB_40b37c10:
  LeaveCriticalSection(lpCriticalSection);
  return iVar3;
}



/* 40b37c40 FUN_40b37c40 */

/* Boundary evidence: original MIPS .pdata 40b37c40..40b37d7b. Semantic name remains unreviewed. */

int FUN_40b37c40(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)param_1[0xb];
  EnterCriticalSection(lpCriticalSection);
  param_1[5] = param_3;
  param_1[6] = param_4;
  if ((param_1[2] != 0) || (iVar1 = (**(code **)(*param_1 + 0x14))(param_1), -1 < iVar1)) {
    if (param_1[2] != 2) {
      piVar5 = param_1 + -3;
      iVar2 = (**(code **)(*piVar5 + 0x18))(piVar5);
      iVar4 = 0;
      if (0 < iVar2) {
        do {
          piVar3 = (int *)(**(code **)(*piVar5 + 0x1c))(piVar5,iVar4);
          if ((piVar3[6] != 0) && (iVar1 = (**(code **)(*piVar3 + 0x1c))(piVar3), iVar1 < 0))
          goto LAB_40b37d40;
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar2);
      }
    }
    param_1[2] = 2;
    iVar1 = 0;
  }
LAB_40b37d40:
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40b37d7c FUN_40b37d7c */

/* Boundary evidence: original MIPS .pdata 40b37d7c..40b37e03. Semantic name remains unreviewed. */

int FUN_40b37d7c(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar1 = -0x7ffbfded;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0xc))(*(int **)(param_1 + 0x18),param_2);
    if (-1 < iVar1) {
      uVar2 = *(uint *)(param_1 + 0x20);
      uVar3 = *param_2;
      iVar4 = *(int *)(param_1 + 0x24);
      iVar1 = 0;
      *param_2 = uVar3 - uVar2;
      param_2[1] = (param_2[1] - iVar4) - (uint)(uVar3 < uVar2);
    }
  }
  return iVar1;
}



/* 40b37e04 FUN_40b37e04 */

/* Boundary evidence: original MIPS .pdata 40b37e04..40b37f1b. Semantic name remains unreviewed. */

undefined4 FUN_40b37e04(int param_1,LPCWSTR param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar6;
  
  if (param_3 == (int *)0x0) {
    uVar4 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
    EnterCriticalSection(lpCriticalSection);
    piVar6 = (int *)(param_1 + -0xc);
    iVar1 = (**(code **)(*piVar6 + 0x18))(piVar6);
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        iVar2 = (**(code **)(*piVar6 + 0x1c))(piVar6,iVar5);
        iVar3 = lstrcmpW(*(LPCWSTR *)(iVar2 + 0x14),param_2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar4 = 0;
          goto LAB_40b37ec4;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    *param_3 = 0;
    uVar4 = 0x80040216;
LAB_40b37ec4:
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar4;
}



/* 40b37f1c FUN_40b37f1c */

/* Boundary evidence: original MIPS .pdata 40b37f1c..40b38037. Semantic name remains unreviewed. */

undefined4 FUN_40b37f1c(int param_1,undefined4 *param_2,wchar_t *param_3)

{
  int iVar1;
  size_t sVar2;
  void *_Dst;
  uint uVar3;
  uint uVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 **)(param_1 + 0x34) = param_2;
  if (param_2 == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  else {
    iVar1 = (**(code **)*param_2)(param_2,&DAT_40b3d9a8,(undefined4 *)(param_1 + 0x38));
    if (-1 < iVar1) {
      (**(code **)(**(int **)(param_1 + 0x38) + 8))();
    }
  }
  if (*(void **)(param_1 + 0x30) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (param_3 != (wchar_t *)0x0) {
    sVar2 = wcslen(param_3);
    uVar4 = sVar2 + 1;
    if (uVar4 < 0x80000000) {
      uVar3 = uVar4 * 2;
    }
    else {
      uVar3 = 0xffffffff;
    }
    _Dst = operator_new(uVar3);
    *(void **)(param_1 + 0x30) = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_3,uVar4 * 2);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b38038 FUN_40b38038 */

/* Boundary evidence: original MIPS .pdata 40b38038..40b3810b. Semantic name remains unreviewed. */

undefined4 FUN_40b38038(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  HRESULT HVar3;
  int *local_10 [2];
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(param_1 + -0x10) + 0x20))();
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 1;
  }
  else {
    CoInitializeEx((LPVOID)0x0,0);
    HVar3 = CoCreateInstance((IID *)&DAT_40b3c978,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b3d968,local_10);
    if (-1 < HVar3) {
      FUN_40b375dc(puVar1,local_10[0],1);
      (**(code **)(*local_10[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b3810c FUN_40b3810c */

/* Boundary evidence: original MIPS .pdata 40b3810c..40b381ff. Semantic name remains unreviewed. */

int FUN_40b3810c(int param_1)

{
  undefined4 *puVar1;
  HRESULT HVar2;
  int *local_18 [2];
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(param_1 + -0x10) + 0x20))();
  if (puVar1 == (undefined4 *)0x0) {
    HVar2 = 1;
  }
  else {
    CoInitializeEx((LPVOID)0x0,0);
    HVar2 = CoCreateInstance((IID *)&DAT_40b3c978,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b3d968,local_18);
    if (-1 < HVar2) {
      HVar2 = FUN_40b375dc(puVar1,local_18[0],0);
      (**(code **)(*local_18[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    if (HVar2 == -0x7ff8fffe) {
      HVar2 = 0;
    }
  }
  return HVar2;
}



/* 40b38200 FUN_40b38200 */

/* Boundary evidence: original MIPS .pdata 40b38200..40b3824b. Semantic name remains unreviewed. */

undefined4 * FUN_40b38200(undefined4 *param_1,uint param_2)

{
  FUN_40b36138(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b3824c FUN_40b3824c */

/* Boundary evidence: original MIPS .pdata 40b3824c..40b383e3. Semantic name remains unreviewed. */

undefined4 FUN_40b3824c(int param_1,uint param_2,int *param_3,uint *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_3 == (int *)0x0) {
    uVar4 = 0x80004003;
  }
  else {
    if (param_4 == (uint *)0x0) {
      if (1 < param_2) {
        return 0x80070057;
      }
    }
    else {
      *param_4 = 0;
    }
    uVar6 = 0;
    bVar1 = FUN_40b36c5c(param_1);
    uVar4 = 1;
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40b362f4(param_1);
    }
    uVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
    if ((int)param_2 <= (int)uVar5) {
      uVar5 = param_2;
    }
    if (uVar5 != 0) {
      do {
        if (*(int *)(param_1 + 8) == *(int *)(param_1 + 4)) break;
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))();
        if (iVar2 == 0) {
          return 0x80040203;
        }
        iVar3 = FUN_40b39be8((int *)(param_1 + 0x18),iVar2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar6 = uVar6 + 1;
          param_3 = param_3 + 1;
          FUN_40b39c2c((int *)(param_1 + 0x18),iVar2);
          uVar5 = uVar5 - 1;
        }
      } while (uVar5 != 0);
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar6;
      }
      if (param_2 == uVar6) {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}



/* 40b383e4 FUN_40b383e4 */

/* Boundary evidence: original MIPS .pdata 40b383e4..40b3845f. Semantic name remains unreviewed. */

undefined4 FUN_40b383e4(int param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_40b36c5c(param_1);
  uVar2 = 1;
  if (CONCAT31(extraout_var,bVar1) == 1) {
    uVar2 = 0x80040203;
  }
  else if ((uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) < param_2) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 8);
  }
  else {
    *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b38460 FUN_40b38460 */

/* Boundary evidence: original MIPS .pdata 40b38460..40b384c3. Semantic name remains unreviewed. */

undefined4 * FUN_40b38460(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40b3c104;
  (**(code **)(*(int *)(param_1[2] + 0xc) + 8))();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b384c4 FUN_40b384c4 */

/* Boundary evidence: original MIPS .pdata 40b384c4..40b38657. Semantic name remains unreviewed. */

uint FUN_40b384c4(int param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  LPVOID _Dst;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_70 [60];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  local_28 = DAT_40b3f10c;
  if (param_3 == (undefined4 *)0x0) {
    FUN_40b39e00(DAT_40b3f10c);
    uVar3 = 0x80004003;
  }
  else {
    bVar1 = FUN_40b36cb4(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40b39e00(local_28);
      uVar3 = 0x80040203;
    }
    else {
      if (param_4 == (int *)0x0) {
        if (1 < param_2) {
          FUN_40b39e00(local_28);
          return 0x80070057;
        }
      }
      else {
        *param_4 = 0;
      }
      iVar4 = 0;
      for (; param_2 != 0; param_2 = param_2 - 1) {
        FUN_40b39728(auStack_70);
        iVar2 = *(int *)(param_1 + 4);
        *(int *)(param_1 + 4) = iVar2 + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                          (*(int **)(param_1 + 8),iVar2,auStack_70);
        if (iVar2 != 0) {
LAB_40b38604:
          FUN_40b3970c((int)auStack_70);
          break;
        }
        _Dst = CoTaskMemAlloc(0x48);
        *param_3 = _Dst;
        if (_Dst == (LPVOID)0x0) goto LAB_40b38604;
        memcpy(_Dst,auStack_70,0x48);
        local_2c = 0;
        local_30 = 0;
        local_34 = 0;
        param_3 = param_3 + 1;
        iVar4 = iVar4 + 1;
        FUN_40b3970c((int)auStack_70);
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar4;
      }
      uVar3 = (uint)(param_2 != 0);
      FUN_40b39e00(local_28);
    }
  }
  return uVar3;
}



/* 40b38658 FUN_40b38658 */

/* Boundary evidence: original MIPS .pdata 40b38658..40b3870f. Semantic name remains unreviewed. */

uint FUN_40b38658(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  undefined1 auStack_60 [72];
  uint local_18;
  
  local_18 = DAT_40b3f10c;
  bVar1 = FUN_40b36cb4(param_1);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_40b39e00(local_18);
    uVar3 = 0x80040203;
  }
  else {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    FUN_40b39728(auStack_60);
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                      (*(int **)(param_1 + 8),*(int *)(param_1 + 4) + -1,auStack_60);
    uVar3 = (uint)(iVar2 != 0);
    FUN_40b3970c((int)auStack_60);
    FUN_40b39e00(local_18);
  }
  return uVar3;
}



/* 40b38710 FUN_40b38710 */

/* Boundary evidence: original MIPS .pdata 40b38710..40b38887. Semantic name remains unreviewed. */

int FUN_40b38710(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2);
  if (iVar1 < 0) {
    (**(code **)(*param_1 + 0x2c))();
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x20))(param_1,param_3);
    if (iVar1 == 0) {
      param_1[6] = (int)param_2;
      (**(code **)(*param_2 + 4))(param_2);
      (**(code **)(*param_1 + 0x24))(param_1,param_3);
      iVar1 = (**(code **)(*param_2 + 0x10))(param_2,param_1 + 3,param_3);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*param_1 + 0x30))(param_1,param_2);
        if (-1 < iVar1) {
          return iVar1;
        }
        (**(code **)(*param_2 + 0x14))(param_2);
      }
    }
    else if (((-1 < iVar1) || (iVar1 == -0x7fffbffb)) || (iVar1 == -0x7ff8ffa9)) {
      iVar1 = -0x7ffbfdd6;
    }
    (**(code **)(*param_1 + 0x2c))(param_1);
    if ((int *)param_1[6] != (int *)0x0) {
      (**(code **)(*(int *)param_1[6] + 8))();
      param_1[6] = 0;
    }
  }
  return iVar1;
}



/* 40b38888 FUN_40b38888 */

/* Boundary evidence: original MIPS .pdata 40b38888..40b389fb. Semantic name remains unreviewed. */

int FUN_40b38888(int *param_1,int *param_2,void *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *local_28;
  undefined4 local_24;
  
  iVar1 = (**(code **)(*param_4 + 0x14))(param_4);
  if (-1 < iVar1) {
    iVar1 = 0;
    local_28 = (void *)0x0;
    local_24 = 0;
    iVar2 = (**(code **)(*param_4 + 0xc))(param_4,1,&local_28,&local_24);
    if (iVar2 == 0) {
      do {
        if ((((param_3 == (void *)0x0) ||
             (iVar3 = FUN_40b39954(local_28,param_3), iVar2 = -0x7ffbfdf9, iVar3 != 0)) &&
            (iVar2 = FUN_40b38710(param_1,param_2,local_28), iVar2 < 0)) &&
           (((-1 < iVar1 && (iVar2 != -0x7fffbffb)) &&
            ((iVar2 != -0x7ff8ffa9 && (iVar2 != -0x7ffbfdd6)))))) {
          iVar1 = iVar2;
        }
        FUN_40b39a68(local_28);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = (**(code **)(*param_4 + 0xc))(param_4,1,&local_28,&local_24);
      } while (iVar2 == 0);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = -0x7ffbfdf9;
  }
  return iVar1;
}



/* 40b389fc FUN_40b389fc */

/* Boundary evidence: original MIPS .pdata 40b389fc..40b38b83. Semantic name remains unreviewed. */

int FUN_40b389fc(int *param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int *local_30 [2];
  
  local_30[0] = (int *)0x0;
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_40b398e8(param_3), iVar1 == 0)) {
    iVar1 = FUN_40b38710(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = -0x7ffbfdf9;
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,local_30);
  if (-1 < iVar2) {
    iVar2 = FUN_40b38888(param_1,param_2,param_3,local_30[0]);
    (**(code **)(*local_30[0] + 8))();
    if (-1 < iVar2) {
      return 0;
    }
    if (((iVar2 != -0x7fffbffb) && (iVar2 != -0x7ff8ffa9)) && (iVar2 != -0x7ffbfdd6)) {
      iVar1 = iVar2;
    }
  }
  iVar2 = (**(code **)(param_1[3] + 0x30))(param_1 + 3,local_30);
  if (iVar2 < 0) {
    return iVar1;
  }
  iVar2 = FUN_40b38888(param_1,param_2,param_3,local_30[0]);
  (**(code **)(*local_30[0] + 8))();
  if (-1 < iVar2) {
    return 0;
  }
  if (iVar2 == -0x7fffbffb) {
    return iVar1;
  }
  if (iVar2 == -0x7ff8ffa9) {
    return iVar1;
  }
  if (iVar2 != -0x7ffbfdd6) {
    return iVar2;
  }
  return iVar1;
}



/* 40b38b84 FUN_40b38b84 */

/* Boundary evidence: original MIPS .pdata 40b38b84..40b38d4b. Semantic name remains unreviewed. */

int FUN_40b38b84(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if ((param_2 == (int *)0x0) || (param_3 == 0)) {
    return -0x7fffbffd;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 0xc) == 0) {
    if (*(int *)(*(int *)(param_1 + 100) + 0x14) == 0) {
      piVar3 = (int *)(param_1 + -0xc);
      iVar2 = (**(code **)(*piVar3 + 0x28))(piVar3,param_2);
      iVar1 = *piVar3;
      if (-1 < iVar2) {
        iVar2 = (**(code **)(iVar1 + 0x20))(piVar3,param_3);
        if (iVar2 != 0) {
          (**(code **)(*piVar3 + 0x2c))(piVar3);
          if (((-1 < iVar2) || (iVar2 == -0x7fffbffb)) || (iVar2 == -0x7ff8ffa9)) {
            iVar2 = -0x7ffbfdd6;
          }
          goto LAB_40b38d1c;
        }
        *(int **)(param_1 + 0xc) = param_2;
        (**(code **)(*param_2 + 4))(param_2);
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,param_3);
        if ((-1 < iVar2) && (iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,param_2), -1 < iVar2)) {
          iVar2 = 0;
          goto LAB_40b38d1c;
        }
        (**(code **)(**(int **)(param_1 + 0xc) + 8))();
        iVar1 = *piVar3;
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
      (**(code **)(iVar1 + 0x2c))(piVar3);
    }
    else {
      iVar2 = -0x7ffbfddc;
    }
  }
  else {
    iVar2 = -0x7ffbfdfc;
  }
LAB_40b38d1c:
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40b38d4c FUN_40b38d4c */

/* Boundary evidence: original MIPS .pdata 40b38d4c..40b38deb. Semantic name remains unreviewed. */

undefined4 FUN_40b38d4c(int param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(*(int *)(param_1 + 100) + 0x14) == 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
      uVar1 = 1;
    }
    else {
      (**(code **)(*(int *)(param_1 + -0xc) + 0x2c))();
      (**(code **)(**(int **)(param_1 + 0xc) + 8))();
      *(undefined4 *)(param_1 + 0xc) = 0;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80040224;
  }
  LeaveCriticalSection(lpCriticalSection);
  return uVar1;
}



/* 40b38dec FUN_40b38dec */

/* Boundary evidence: original MIPS .pdata 40b38dec..40b38e77. Semantic name remains unreviewed. */

undefined4 FUN_40b38dec(int param_1,void *param_2)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (void *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
    EnterCriticalSection(lpCriticalSection);
    if (*(int *)(param_1 + 0xc) == 0) {
      FUN_40b395d8(param_2);
      uVar1 = 0x80040209;
    }
    else {
      FUN_40b39614(param_2,(void *)(param_1 + 0x10));
      uVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40b38e78 FUN_40b38e78 */

/* Boundary evidence: original MIPS .pdata 40b38e78..40b38e93. Semantic name remains unreviewed. */

void FUN_40b38e78(int param_1,undefined4 *param_2)

{
  FUN_40b39ae4(*(wchar_t **)(param_1 + 8),param_2);
  return;
}



/* 40b38e94 FUN_40b38e94 */

/* Boundary evidence: original MIPS .pdata 40b38e94..40b38f0f. Semantic name remains unreviewed. */

int FUN_40b38e94(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40b38d4c(param_1);
  if ((iVar1 == 0) && (*(int **)(param_1 + 0x90) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x90) + 8))();
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40b38f10 FUN_40b38f10 */

/* Boundary evidence: original MIPS .pdata 40b38f10..40b38fef. Semantic name remains unreviewed. */

undefined4 * FUN_40b38f10(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_40b3c0e4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 1;
  FUN_40b39b70(param_1 + 6);
  (**(code **)(*(int *)(param_1[3] + 0xc) + 4))();
  if (param_3 == 0) {
    uVar1 = (**(code **)(*(int *)param_1[3] + 0x14))();
    param_1[4] = uVar1;
    uVar1 = (**(code **)(*(int *)param_1[3] + 0x18))();
    param_1[2] = uVar1;
  }
  else {
    param_1[1] = *(undefined4 *)(param_3 + 4);
    param_1[2] = *(undefined4 *)(param_3 + 8);
    param_1[4] = *(undefined4 *)(param_3 + 0x10);
    FUN_40b39cc8(param_1 + 6,(int *)(param_3 + 0x18));
  }
  return param_1;
}



/* 40b38ff0 FUN_40b38ff0 */

/* Boundary evidence: original MIPS .pdata 40b38ff0..40b3909b. Semantic name remains unreviewed. */

undefined4 FUN_40b38ff0(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    uVar3 = 0;
    bVar1 = FUN_40b36c5c(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      uVar3 = 0x80040203;
      *param_2 = 0;
    }
    else {
      puVar2 = operator_new(0x30);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_40b38f10(puVar2,*(undefined4 *)(param_1 + 0xc),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40b3909c FUN_40b3909c */

/* Boundary evidence: original MIPS .pdata 40b3909c..40b3912b. Semantic name remains unreviewed. */

undefined4 * FUN_40b3909c(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_40b3c104;
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[4] = 1;
  (**(code **)(*(int *)(param_2 + 0xc) + 4))();
  if (param_3 == 0) {
    uVar1 = (**(code **)(*(int *)param_1[2] + 0x10))();
    param_1[3] = uVar1;
  }
  else {
    param_1[1] = *(undefined4 *)(param_3 + 4);
    param_1[3] = *(undefined4 *)(param_3 + 0xc);
  }
  return param_1;
}



/* 40b3912c FUN_40b3912c */

/* Boundary evidence: original MIPS .pdata 40b3912c..40b391d7. Semantic name remains unreviewed. */

undefined4 FUN_40b3912c(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    uVar3 = 0;
    bVar1 = FUN_40b36cb4(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      uVar3 = 0x80040203;
      *param_2 = 0;
    }
    else {
      puVar2 = operator_new(0x14);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_40b3909c(puVar2,*(int *)(param_1 + 8),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40b391d8 FUN_40b391d8 */

/* Boundary evidence: original MIPS .pdata 40b391d8..40b392cb. Semantic name remains unreviewed. */

undefined4 *
FUN_40b391d8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6,undefined4 param_7)

{
  size_t sVar1;
  void *_Dst;
  uint uVar2;
  uint uVar3;
  
  FUN_40b35e8c(param_1,param_2,(undefined4 *)0x0);
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_40b39728(param_1 + 7);
  param_1[0x1c] = param_3;
  param_1[0x1e] = 1;
  param_1[0x19] = param_7;
  param_1[0x1a] = param_4;
  param_1[0x1b] = 0;
  param_1[0x1d] = 0;
  uVar3 = 0xffffffff;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0xffffffff;
  param_1[0x23] = 0x7fffffff;
  param_1[0x24] = 0;
  param_1[0x25] = 0x3ff00000;
  if (param_6 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_6);
    uVar2 = sVar1 + 1;
    if (uVar2 < 0x80000000) {
      uVar3 = uVar2 * 2;
    }
    _Dst = operator_new(uVar3);
    param_1[5] = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_6,uVar2 * 2);
    }
  }
  return param_1;
}



/* 40b392cc FUN_40b392cc */

/* Boundary evidence: original MIPS .pdata 40b392cc..40b393ab. Semantic name remains unreviewed. */

int FUN_40b392cc(int param_1,int *param_2,void *param_3)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar2;
  
  if (param_2 == (int *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
    EnterCriticalSection(lpCriticalSection);
    if (*(int *)(param_1 + 0xc) == 0) {
      if (*(int *)(*(int *)(param_1 + 100) + 0x14) == 0) {
        piVar2 = (int *)(param_1 + -0xc);
        iVar1 = FUN_40b389fc(piVar2,param_2,param_3);
        if (iVar1 < 0) {
          (**(code **)(*piVar2 + 0x2c))(piVar2);
        }
        else {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -0x7ffbfddc;
      }
    }
    else {
      iVar1 = -0x7ffbfdfc;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40b393ac FUN_40b393ac */

/* Boundary evidence: original MIPS .pdata 40b393ac..40b3942b. Semantic name remains unreviewed. */

undefined4 FUN_40b393ac(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    puVar2 = operator_new(0x14);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_40b3909c(puVar2,param_1 + -0xc,0);
    }
    *param_2 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40b3942c FUN_40b3942c */

/* Boundary evidence: original MIPS .pdata 40b3942c..40b39477. Semantic name remains unreviewed. */

undefined4 *
FUN_40b3942c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40b391d8(param_1,param_2,param_3,param_4,param_5,param_6,1);
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  return param_1;
}



/* 40b39478 FUN_40b39478 */

/* Boundary evidence: original MIPS .pdata 40b39478..40b394d3. Semantic name remains unreviewed. */

undefined4 *
FUN_40b39478(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40b391d8(param_1,param_2,param_3,param_4,param_5,param_6,0);
  param_1[0x27] = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)((int)param_1 + 0xa1) = 0;
  memset(param_1 + 0x2a,0,0x30);
  return param_1;
}



/* 40b394d4 FUN_40b394d4 */

/* Boundary evidence: original MIPS .pdata 40b394d4..40b39557. Semantic name remains unreviewed. */

undefined4 *
FUN_40b394d4(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  FUN_40b35e8c(param_1,param_2,param_3);
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = *param_5;
  param_1[0xb] = param_5[1];
  param_1[0xc] = param_5[2];
  uVar1 = param_5[3];
  param_1[0xe] = param_4;
  param_1[0xd] = uVar1;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 1;
  return param_1;
}



/* 40b39558 FUN_40b39558 */

/* Boundary evidence: original MIPS .pdata 40b39558..40b395d7. Semantic name remains unreviewed. */

undefined4 FUN_40b39558(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    puVar2 = operator_new(0x30);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_40b38f10(puVar2,param_1 + -0xc,0);
    }
    *param_2 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40b395d8 FUN_40b395d8 */

/* Boundary evidence: original MIPS .pdata 40b395d8..40b39613. Semantic name remains unreviewed. */

void FUN_40b395d8(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return;
}



/* 40b39614 FUN_40b39614 */

/* Boundary evidence: original MIPS .pdata 40b39614..40b396a7. Semantic name remains unreviewed. */

void FUN_40b39614(void *param_1,void *param_2)

{
  LPVOID _Dst;
  
  memcpy(param_1,param_2,0x48);
  if (*(SIZE_T *)((int)param_2 + 0x40) != 0) {
    _Dst = CoTaskMemAlloc(*(SIZE_T *)((int)param_2 + 0x40));
    *(LPVOID *)((int)param_1 + 0x44) = _Dst;
    if (_Dst == (LPVOID)0x0) {
      *(undefined4 *)((int)param_1 + 0x40) = 0;
    }
    else {
      memcpy(_Dst,*(void **)((int)param_2 + 0x44),*(size_t *)((int)param_1 + 0x40));
    }
  }
  if (*(int **)((int)param_1 + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)((int)param_1 + 0x3c) + 4))();
  }
  return;
}



/* 40b396a8 FUN_40b396a8 */

/* Boundary evidence: original MIPS .pdata 40b396a8..40b3970b. Semantic name remains unreviewed. */

void FUN_40b396a8(int param_1)

{
  if (*(int *)(param_1 + 0x40) != 0) {
    CoTaskMemFree(*(LPVOID *)(param_1 + 0x44));
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (*(int **)(param_1 + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x3c) + 8))();
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 40b3970c FUN_40b3970c */

/* Boundary evidence: original MIPS .pdata 40b3970c..40b39727. Semantic name remains unreviewed. */

void FUN_40b3970c(int param_1)

{
  FUN_40b396a8(param_1);
  return;
}



/* 40b39728 FUN_40b39728 */

/* Boundary evidence: original MIPS .pdata 40b39728..40b39767. Semantic name remains unreviewed. */

void * FUN_40b39728(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return param_1;
}



/* 40b39768 FUN_40b39768 */

/* Boundary evidence: original MIPS .pdata 40b39768..40b39793. Semantic name remains unreviewed. */

void * FUN_40b39768(void *param_1,void *param_2)

{
  FUN_40b39614(param_1,param_2);
  return param_1;
}



/* 40b39794 FUN_40b39794 */

/* Boundary evidence: original MIPS .pdata 40b39794..40b397df. Semantic name remains unreviewed. */

void * FUN_40b39794(void *param_1,void *param_2)

{
  if (param_2 != param_1) {
    FUN_40b396a8((int)param_1);
    FUN_40b39614(param_1,param_2);
  }
  return param_1;
}



/* 40b397e0 FUN_40b397e0 */

/* Boundary evidence: original MIPS .pdata 40b397e0..40b3980b. Semantic name remains unreviewed. */

void * FUN_40b397e0(void *param_1,void *param_2)

{
  FUN_40b39794(param_1,param_2);
  return param_1;
}



/* 40b3980c FUN_40b3980c */

/* Boundary evidence: original MIPS .pdata 40b3980c..40b398b7. Semantic name remains unreviewed. */

undefined4 FUN_40b3980c(void *param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  size_t _Size;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  if ((((iVar1 == 0) &&
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) && (iVar1 = memcmp((void *)((int)param_1 + 0x2c),(void *)((int)param_2 + 0x2c),0x10),
             iVar1 == 0)) &&
     ((_Size = *(size_t *)((int)param_1 + 0x40), _Size == *(size_t *)((int)param_2 + 0x40) &&
      ((_Size == 0 ||
       (iVar1 = memcmp(*(void **)((int)param_1 + 0x44),*(void **)((int)param_2 + 0x44),_Size),
       iVar1 == 0)))))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b398b8 FUN_40b398b8 */

/* Boundary evidence: original MIPS .pdata 40b398b8..40b398e7. Semantic name remains unreviewed. */

bool FUN_40b398b8(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b3980c(param_1,param_2);
  return iVar1 == 0;
}



/* 40b398e8 FUN_40b398e8 */

/* Boundary evidence: original MIPS .pdata 40b398e8..40b39953. Semantic name remains unreviewed. */

undefined4 FUN_40b398e8(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,&DAT_40b3dd98,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp((void *)((int)param_1 + 0x2c),&DAT_40b3dd98,0x10), iVar1 == 0)
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b39954 FUN_40b39954 */

/* Boundary evidence: original MIPS .pdata 40b39954..40b39a67. Semantic name remains unreviewed. */

undefined4 FUN_40b39954(void *param_1,void *param_2)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = memcmp(param_2,&DAT_40b3dd98,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,param_2,0x10), iVar1 == 0)) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40b3dd98,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) {
      iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40b3dd98,0x10);
      if ((iVar1 == 0) ||
         (((iVar1 = memcmp((void *)((int)param_1 + 0x2c),(void *)((int)param_2 + 0x2c),0x10),
           iVar1 == 0 &&
           (_Size = *(size_t *)((int)param_1 + 0x40), _Size == *(size_t *)((int)param_2 + 0x40))) &&
          ((_Size == 0 ||
           (iVar1 = memcmp(*(void **)((int)param_1 + 0x44),*(void **)((int)param_2 + 0x44),_Size),
           iVar1 == 0)))))) {
        return 1;
      }
    }
  }
  return 0;
}



/* 40b39a68 FUN_40b39a68 */

/* Boundary evidence: original MIPS .pdata 40b39a68..40b39aa7. Semantic name remains unreviewed. */

void FUN_40b39a68(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_40b396a8((int)param_1);
    CoTaskMemFree(param_1);
  }
  return;
}



/* 40b39aa8 FUN_40b39aa8 */

short * FUN_40b39aa8(short *param_1,short *param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = param_1;
  if (param_3 != 0) {
    do {
      param_3 = param_3 + -1;
      if (param_3 == 0) {
        *psVar2 = 0;
        return param_1;
      }
      sVar1 = *param_2;
      param_2 = param_2 + 1;
      *psVar2 = sVar1;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
  }
  return param_1;
}



/* 40b39ae4 FUN_40b39ae4 */

/* Boundary evidence: original MIPS .pdata 40b39ae4..40b39b6f. Semantic name remains unreviewed. */

undefined4 FUN_40b39ae4(wchar_t *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  LPVOID _Dst;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    sVar2 = wcslen(param_1);
    sVar2 = (sVar2 + 1) * 2;
    _Dst = CoTaskMemAlloc(sVar2);
    *param_2 = _Dst;
    if (_Dst == (LPVOID)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      memcpy(_Dst,param_1,sVar2);
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40b39b70 FUN_40b39b70 */

undefined4 * FUN_40b39b70(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 10;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40b39b94 FUN_40b39b94 */

/* Boundary evidence: original MIPS .pdata 40b39b94..40b39be7. Semantic name remains unreviewed. */

void FUN_40b39b94(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = (void *)*param_1;
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}



/* 40b39be8 FUN_40b39be8 */

int FUN_40b39be8(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while( true ) {
    iVar1 = iVar2;
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(iVar1 + 8) == param_2) break;
    iVar2 = *param_1;
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 4);
    }
  }
  return iVar1;
}



/* 40b39c2c FUN_40b39c2c */

/* Boundary evidence: original MIPS .pdata 40b39c2c..40b39cc7. Semantic name remains unreviewed. */

undefined4 * FUN_40b39c2c(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[5];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[5] = puVar1[1];
    param_1[4] = param_1[4] + -1;
    if (puVar1 != (undefined4 *)0x0) goto LAB_40b39c7c;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_40b39c7c:
  puVar1[2] = param_2;
  puVar1[1] = 0;
  *puVar1 = param_1[1];
  if (param_1[1] == 0) {
    *param_1 = puVar1;
  }
  else {
    *(undefined4 **)(param_1[1] + 4) = puVar1;
  }
  param_1[1] = puVar1;
  param_1[2] = param_1[2] + 1;
  return puVar1;
}



/* 40b39cc8 FUN_40b39cc8 */

/* Boundary evidence: original MIPS .pdata 40b39cc8..40b39d27. Semantic name remains unreviewed. */

undefined4 FUN_40b39cc8(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *param_2;
  do {
    if (iVar2 == 0) {
      return 1;
    }
    puVar1 = (undefined4 *)(iVar2 + 8);
    iVar2 = *(int *)(iVar2 + 4);
    puVar1 = FUN_40b39c2c(param_1,*puVar1);
  } while (puVar1 != (undefined4 *)0x0);
  return 0;
}



/* 40b39d28 FUN_40b39d28 */

/* Boundary evidence: original MIPS .pdata 40b39d28..40b39d6f. Semantic name remains unreviewed. */

void FUN_40b39d28(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_40b39b94(param_1);
  pvVar1 = (void *)param_1[5];
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* 40b39e00 FUN_40b39e00 */

/* Boundary evidence: original MIPS .pdata 40b39e00..40b39e47. Semantic name remains unreviewed. */

void FUN_40b39e00(uint param_1)

{
  if ((param_1 == DAT_40b3f10c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40b39ee8 FUN_40b39ee8 */

/* Boundary evidence: original MIPS .pdata 40b39ee8..40b3a023. Semantic name remains unreviewed. */

int FUN_40b39ee8(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40b3f33c != (code *)0x0) {
      iVar2 = (*DAT_40b3f33c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40b39f98;
    FUN_40b3a380();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40b31038(param_1,param_2);
  }
LAB_40b39f98:
  if (((param_2 == 0) && (FUN_40b3a308(), iVar1 != 0)) && (DAT_40b3f33c != (code *)0x0)) {
    iVar1 = (*DAT_40b3f33c)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40b3a024 FUN_40b3a024 */

/* Boundary evidence: original MIPS .pdata 40b3a024..40b3a04f. Semantic name remains unreviewed. */

void FUN_40b3a024(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40b3a050 entry */

/* Boundary evidence: original MIPS .pdata 40b3a050..40b3a0a7. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40b3a0a8();
  }
  FUN_40b39ee8(param_1,param_2,param_3);
  return;
}



/* 40b3a0a8 FUN_40b3a0a8 */

/* Boundary evidence: original MIPS .pdata 40b3a0a8..40b3a11b. Semantic name remains unreviewed. */

void FUN_40b3a0a8(void)

{
  uint uVar1;
  
  if ((DAT_40b3f10c == 0) || (DAT_40b3f10c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40b3f10c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40b3f10c == 0) {
      DAT_40b3f10c = 0xb064;
    }
  }
  DAT_40b3f110 = ~DAT_40b3f10c;
  return;
}



/* 40b3a11c FUN_40b3a11c */

/* Boundary evidence: original MIPS .pdata 40b3a11c..40b3a16f. Semantic name remains unreviewed. */

void FUN_40b3a11c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40b39e00(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40b3a170 FUN_40b3a170 */

/* Boundary evidence: original MIPS .pdata 40b3a170..40b3a19b. Semantic name remains unreviewed. */

undefined4 FUN_40b3a170(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40b3a11c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40b3a21c FUN_40b3a21c */

/* Boundary evidence: original MIPS .pdata 40b3a21c..40b3a307. Semantic name remains unreviewed. */

void FUN_40b3a21c(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40b3f32c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40b3f338;
    if (DAT_40b3f338 != (undefined4 *)0x0) {
      while (DAT_40b3f334 = DAT_40b3f334 + -1, _Memory <= DAT_40b3f334) {
        if ((code *)*DAT_40b3f334 != (code *)0x0) {
          (*(code *)*DAT_40b3f334)();
          _Memory = DAT_40b3f338;
        }
      }
      free(_Memory);
      DAT_40b3f334 = (undefined4 *)0x0;
      DAT_40b3f338 = (undefined4 *)0x0;
    }
    FUN_40b3a32c((undefined4 *)&DAT_40b3c010,(undefined4 *)&DAT_40b3c014);
  }
  FUN_40b3a32c((undefined4 *)&DAT_40b3c018,(undefined4 *)&DAT_40b3c01c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 40b3a308 FUN_40b3a308 */

/* Boundary evidence: original MIPS .pdata 40b3a308..40b3a32b. Semantic name remains unreviewed. */

void FUN_40b3a308(void)

{
  FUN_40b3a21c(0,0,1);
  return;
}



/* 40b3a32c FUN_40b3a32c */

/* Boundary evidence: original MIPS .pdata 40b3a32c..40b3a37f. Semantic name remains unreviewed. */

void FUN_40b3a32c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40b3a380 FUN_40b3a380 */

/* Boundary evidence: original MIPS .pdata 40b3a380..40b3a3bb. Semantic name remains unreviewed. */

void FUN_40b3a380(void)

{
  FUN_40b3a32c((undefined4 *)&DAT_40b3c008,(undefined4 *)&DAT_40b3c00c);
  FUN_40b3a32c((undefined4 *)&DAT_40b3c000,(undefined4 *)&DAT_40b3c004);
  return;
}



/* 40b3a3ec FUN_40b3a3ec */

/* Boundary evidence: original MIPS .pdata 40b3a3ec..40b3a40f. Semantic name remains unreviewed. */

void FUN_40b3a3ec(undefined4 param_1)

{
  (*(code *)PTR_FUN_40b3f114)(param_1,0);
  return;
}



/* 40b3a410 FUN_40b3a410 */

/* Boundary evidence: original MIPS .pdata 40b3a410..40b3a467. Semantic name remains unreviewed. */

undefined4 * FUN_40b3a410(undefined4 *param_1,undefined4 param_2,int *param_3,int param_4)

{
  *param_1 = &PTR_FUN_40b3ddd8;
  param_1[1] = param_2;
  param_1[2] = param_3;
  param_1[3] = 0;
  if ((param_3 != (int *)0x0) && (param_4 != 0)) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  return param_1;
}



/* 40b3a468 FUN_40b3a468 */

/* Boundary evidence: original MIPS .pdata 40b3a468..40b3a4bf. Semantic name remains unreviewed. */

void FUN_40b3a468(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40b3ddd8;
  if ((int *)param_1[2] != (int *)0x0) {
    (**(code **)(*(int *)param_1[2] + 8))();
  }
  if ((HLOCAL)param_1[3] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[3]);
  }
  return;
}



/* 40b3a4c0 FUN_40b3a4c0 */

/* Boundary evidence: original MIPS .pdata 40b3a4c0..40b3a4f7. Semantic name remains unreviewed. */

void FUN_40b3a4c0(undefined4 param_1,int *param_2)

{
  undefined4 auStack_18 [4];
  
  FUN_40b3a410(auStack_18,param_1,param_2,0);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException(auStack_18,(ThrowInfo *)&DAT_40b3ec5c);
}



/* 40b3a4f8 FUN_40b3a4f8 */

/* Boundary evidence: original MIPS .pdata 40b3a4f8..40b3a553. Semantic name remains unreviewed. */

undefined4 * FUN_40b3a4f8(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40b3ddd8;
  param_1[1] = *(undefined4 *)(param_2 + 4);
  piVar1 = *(int **)(param_2 + 8);
  param_1[2] = piVar1;
  param_1[3] = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return param_1;
}



/* 40b3a554 FUN_40b3a554 */

/* Boundary evidence: original MIPS .pdata 40b3a554..40b3a59f. Semantic name remains unreviewed. */

undefined4 * FUN_40b3a554(undefined4 *param_1,uint param_2)

{
  FUN_40b3a468(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b3a5a0 FUN_40b3a5a0 */

/* Boundary evidence: original MIPS .pdata 40b3a5a0..40b3a5e3. Semantic name remains unreviewed. */

void FUN_40b3a5a0(exception *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_40b3ddec;
  FUN_40b34108((int)(param_1 + 0xc),1,0);
  std::exception::~exception(param_1);
  return;
}



/* 40b3a5e4 FUN_40b3a5e4 */

/* Boundary evidence: original MIPS .pdata 40b3a5e4..40b3a64b. Semantic name remains unreviewed. */

exception * FUN_40b3a5e4(exception *param_1,uint param_2)

{
  *(undefined ***)param_1 = &PTR_FUN_40b3ddec;
  FUN_40b34108((int)(param_1 + 0xc),1,0);
  std::exception::~exception(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b3a64c FUN_40b3a64c */

/* Boundary evidence: original MIPS .pdata 40b3a64c..40b3a6ab. Semantic name remains unreviewed. */

void FUN_40b3a64c(void)

{
  undefined1 auStack_50 [32];
  undefined **local_30 [10];
  
  FUN_40b34a2c((int)auStack_50,"string too long");
  FUN_40b310d0((exception *)local_30,auStack_50);
  local_30[0] = &PTR_FUN_40b3ddf8;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException(local_30,(ThrowInfo *)&DAT_40b3ed30);
}



/* 40b3a6ac FUN_40b3a6ac */

/* Boundary evidence: original MIPS .pdata 40b3a6ac..40b3a6db. Semantic name remains unreviewed. */

void FUN_40b3a6ac(void)

{
  int in_v0;
  
  FUN_40b33cac(in_v0 + -0x50);
  return;
}



/* 40b3a6dc FUN_40b3a6dc */

/* Boundary evidence: original MIPS .pdata 40b3a6dc..40b3a73b. Semantic name remains unreviewed. */

void FUN_40b3a6dc(void)

{
  undefined1 auStack_50 [32];
  undefined **local_30 [10];
  
  FUN_40b34a2c((int)auStack_50,"invalid string position");
  FUN_40b310d0((exception *)local_30,auStack_50);
  local_30[0] = &PTR_FUN_40b3de04;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException(local_30,(ThrowInfo *)&DAT_40b3ec90);
}



/* 40b3a73c FUN_40b3a73c */

/* Boundary evidence: original MIPS .pdata 40b3a73c..40b3a76b. Semantic name remains unreviewed. */

void FUN_40b3a73c(void)

{
  int in_v0;
  
  FUN_40b33cac(in_v0 + -0x50);
  return;
}



/* 40b3a76c FUN_40b3a76c */

/* Boundary evidence: original MIPS .pdata 40b3a76c..40b3a7b3. Semantic name remains unreviewed. */

exception * FUN_40b3a76c(exception *param_1,exception *param_2)

{
  FUN_40b34990(param_1,param_2);
  *(undefined ***)param_1 = &PTR_FUN_40b3de04;
  return param_1;
}



/* 40b3a7b4 FUN_40b3a7b4 */

/* Boundary evidence: original MIPS .pdata 40b3a7b4..40b3a7df. Semantic name remains unreviewed. */

void FUN_40b3a7b4(void)

{
  FUN_40b3b828();
  return;
}



/* 40b3a7e0 FUN_40b3a7e0 */

/* Boundary evidence: original MIPS .pdata 40b3a7e0..40b3a813. Semantic name remains unreviewed. */

void FUN_40b3a7e0(void)

{
  RaiseException(0xc000000d,0,0,(ULONG_PTR *)0x0);
  return;
}



/* 40b3a814 FUN_40b3a814 */

/* Boundary evidence: original MIPS .pdata 40b3a814..40b3a963. Semantic name remains unreviewed. */

void FUN_40b3a814(int param_1,uint *param_2,int param_3,uint param_4)

{
  uint uVar1;
  HLOCAL pvVar2;
  undefined *puVar3;
  
  uVar1 = FUN_40b3b934(param_1,param_2,param_3);
  pvVar2 = FUN_40b3b848();
  *(int *)((int)pvVar2 + 0x1c) = *(int *)((int)pvVar2 + 0x1c) + 1;
  pvVar2 = FUN_40b3b848();
  if (param_1 == *(int *)((int)pvVar2 + 0xc)) {
    pvVar2 = FUN_40b3b848();
    uVar1 = *(uint *)((int)pvVar2 + 0x10);
  }
  pvVar2 = FUN_40b3b848();
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  for (; (uVar1 != param_4 && (uVar1 != 0xffffffff));
      uVar1 = *(uint *)(uVar1 * 8 + *(int *)(param_3 + 8))) {
    puVar3 = *(undefined **)(uVar1 * 8 + *(int *)(param_3 + 8) + 4);
    if (puVar3 != (undefined *)0x0) {
      FUN_40b3b904(puVar3,param_1,param_2[3],0);
    }
  }
  FUN_40b3a964();
  return;
}



/* 40b3a964 FUN_40b3a964 */

/* Boundary evidence: original MIPS .pdata 40b3a964..40b3a9bb. Semantic name remains unreviewed. */

void FUN_40b3a964(void)

{
  HLOCAL pvVar1;
  
  pvVar1 = FUN_40b3b848();
  if (0 < *(int *)((int)pvVar1 + 0x1c)) {
    pvVar1 = FUN_40b3b848();
    *(int *)((int)pvVar1 + 0x1c) = *(int *)((int)pvVar1 + 0x1c) + -1;
  }
  return;
}



/* 40b3a9bc FUN_40b3a9bc */

/* Boundary evidence: original MIPS .pdata 40b3a9bc..40b3aa23. Semantic name remains unreviewed. */

undefined4 FUN_40b3a9bc(undefined4 param_1)

{
  int in_v0;
  HLOCAL pvVar1;
  
  *(undefined4 *)(in_v0 + -0x24) = param_1;
  *(undefined4 *)(in_v0 + -0x20) = **(undefined4 **)(in_v0 + -0x24);
  if (**(int **)(in_v0 + -0x20) == -0x1f928c9d) {
    pvVar1 = FUN_40b3b848();
    *(undefined4 *)((int)pvVar1 + 0x1c) = 0;
    std::terminate();
  }
  *(undefined4 *)(in_v0 + -0x1c) = 0;
  return *(undefined4 *)(in_v0 + -0x1c);
}



/* 40b3aa24 FUN_40b3aa24 */

/* Boundary evidence: original MIPS .pdata 40b3aa24..40b3ab8f. Semantic name remains unreviewed. */

undefined4 FUN_40b3aa24(int param_1,int param_2)

{
  HLOCAL pvVar1;
  int *piVar2;
  
  if (param_2 == 0) {
    pvVar1 = FUN_40b3b848();
    if ((*(int *)((int)pvVar1 + 0x18) != 0) &&
       ((pvVar1 = FUN_40b3b848(), param_1 != *(int *)((int)pvVar1 + 0x18) ||
        ((((param_1 != 0 && (piVar2 = FUN_40b3b848(), *piVar2 != 0)) &&
          (piVar2 = FUN_40b3b848(), param_1 != *piVar2)) &&
         ((piVar2 = FUN_40b3b848(), *(int *)(param_1 + 0x18) == *(int *)(*piVar2 + 0x18) &&
          (piVar2 = FUN_40b3b848(), *(int *)(param_1 + 0x1c) == *(int *)(*piVar2 + 0x1c))))))))) {
      pvVar1 = FUN_40b3b848();
      if (*(int *)((int)pvVar1 + 0x18) == 0) {
        return 0;
      }
      if (param_1 == 0) {
        return 0;
      }
      pvVar1 = FUN_40b3b848();
      if (*(int *)((int)pvVar1 + 0x18) == param_1) {
        return 0;
      }
      pvVar1 = FUN_40b3b848();
      if (*(int *)(*(int *)((int)pvVar1 + 0x18) + 0x18) != *(int *)(param_1 + 0x18)) {
        return 0;
      }
      pvVar1 = FUN_40b3b848();
      if (*(int *)(*(int *)((int)pvVar1 + 0x18) + 0x1c) != *(int *)(param_1 + 0x1c)) {
        return 0;
      }
      pvVar1 = FUN_40b3b848();
      piVar2 = FUN_40b3b848();
      if (*(int *)((int)pvVar1 + 0x18) == *piVar2) {
        return 0;
      }
    }
  }
  else {
    pvVar1 = FUN_40b3b848();
    if (param_1 == *(int *)((int)pvVar1 + 0x18)) {
      return 0;
    }
  }
  return 1;
}



/* 40b3ab90 FUN_40b3ab90 */

/* Boundary evidence: original MIPS .pdata 40b3ab90..40b3abef. Semantic name remains unreviewed. */

void FUN_40b3ab90(int param_1)

{
  code *pcVar1;
  
  if ((param_1 != 0) && (pcVar1 = *(code **)(*(int *)(param_1 + 0x1c) + 4), pcVar1 != (code *)0x0))
  {
    (*pcVar1)(*(undefined4 *)(param_1 + 0x18));
  }
  return;
}



/* 40b3abf0 FUN_40b3abf0 */

/* Boundary evidence: original MIPS .pdata 40b3abf0..40b3ac1f. Semantic name remains unreviewed. */

bool FUN_40b3abf0(void)

{
  int in_v0;
  
  return *(char *)(in_v0 + 4) != '\0';
}



/* 40b3ac20 FUN_40b3ac20 */

/* Boundary evidence: original MIPS .pdata 40b3ac20..40b3ac67. Semantic name remains unreviewed. */

void FUN_40b3ac20(int param_1)

{
  HLOCAL pvVar1;
  int iVar2;
  
  pvVar1 = FUN_40b3b848();
  for (iVar2 = *(int *)((int)pvVar1 + 0x14); (iVar2 != 0 && (*(int *)(iVar2 + 4) != param_1));
      iVar2 = *(int *)(iVar2 + 0x10)) {
  }
  return;
}



/* 40b3ac68 FUN_40b3ac68 */

/* Boundary evidence: original MIPS .pdata 40b3ac68..40b3acaf. Semantic name remains unreviewed. */

void FUN_40b3ac68(int param_1)

{
  HLOCAL pvVar1;
  int *piVar2;
  
  pvVar1 = FUN_40b3b848();
  for (piVar2 = *(int **)((int)pvVar1 + 0x14); (piVar2 != (int *)0x0 && (*piVar2 != param_1));
      piVar2 = (int *)piVar2[4]) {
  }
  return;
}



/* 40b3acb0 FUN_40b3acb0 */

int * FUN_40b3acb0(int param_1,undefined4 param_2,int param_3,uint *param_4,int *param_5)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(uint *)(param_1 + 0xc) != 0) {
    piVar1 = *(int **)(param_1 + 0x10);
    do {
      if ((*piVar1 <= param_3) && (param_3 <= piVar1[1])) {
        *param_4 = uVar2;
        *param_5 = piVar1[2] + 1;
        return piVar1;
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 5;
    } while (uVar2 < *(uint *)(param_1 + 0xc));
  }
  *param_5 = 0;
  *param_4 = 0;
  return (int *)0x0;
}



/* 40b3ad20 FUN_40b3ad20 */

/* Boundary evidence: original MIPS .pdata 40b3ad20..40b3aed7. Semantic name remains unreviewed. */

undefined4
FUN_40b3ad20(undefined4 param_1,uint param_2,undefined4 param_3,int param_4,undefined *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  HLOCAL pvVar4;
  undefined4 uVar5;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  FUN_40b3b848();
  FUN_40b3b848();
  FUN_40b3b848();
  puVar3 = FUN_40b3b848();
  *puVar3 = param_1;
  pvVar4 = FUN_40b3b848();
  *(undefined4 *)((int)pvVar4 + 4) = param_3;
  local_38 = 0;
  local_34 = param_2;
  pvVar4 = FUN_40b3b848();
  local_30 = *(undefined4 *)(**(int **)((int)pvVar4 + 8) * 8 + *(int *)(param_4 + 8));
  pvVar4 = FUN_40b3b848();
  local_2c = *(undefined4 *)(*(int *)(*(int *)((int)pvVar4 + 8) + 0x10) + 0xc);
  pvVar4 = FUN_40b3b848();
  local_28 = *(undefined4 *)((int)pvVar4 + 0x14);
  pvVar4 = FUN_40b3b848();
  *(undefined4 **)((int)pvVar4 + 0x14) = &local_38;
  uVar5 = FUN_40b3b904(param_5,param_2,param_3,(int)&local_38);
  FUN_40b3aed8(0);
  pvVar4 = FUN_40b3b848();
  iVar1 = 0;
  for (iVar2 = *(int *)((int)pvVar4 + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {
    if (*(uint *)(iVar2 + 4) <= local_34) {
      pvVar4 = FUN_40b3b848();
      if (iVar2 == *(int *)((int)pvVar4 + 0x14)) {
        pvVar4 = FUN_40b3b848();
        *(undefined4 *)((int)pvVar4 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
      }
      else {
        *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
      }
    }
    iVar1 = iVar2;
  }
  return uVar5;
}



/* 40b3aed8 FUN_40b3aed8 */

/* Boundary evidence: original MIPS .pdata 40b3aed8..40b3b00b. Semantic name remains unreviewed. */

void FUN_40b3aed8(uint param_1)

{
  undefined4 *in_v0;
  undefined4 *puVar1;
  HLOCAL pvVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = FUN_40b3b848();
  *puVar1 = in_v0[-0x11];
  pvVar2 = FUN_40b3b848();
  *(undefined4 *)((int)pvVar2 + 4) = in_v0[-0x10];
  piVar4 = (int *)*in_v0;
  if ((((*piVar4 == -0x1f928c9d) && (piVar4[4] == 3)) &&
      ((iVar3 = piVar4[5], iVar3 == 0x19930520 || ((iVar3 == 0x19930521 || (iVar3 == 0x19930522)))))
      ) && ((piVar4[7] != 0 && (iVar3 = FUN_40b3aa24((int)piVar4,param_1 & 0xff), iVar3 != 0)))) {
    FUN_40b3ab90((int)piVar4);
  }
  pvVar2 = FUN_40b3b848();
  *(undefined4 *)((int)pvVar2 + 0x18) = in_v0[-0xf];
  if (param_1 != 0) {
    pvVar2 = FUN_40b3b848();
    *(undefined4 *)((int)pvVar2 + 0xc) = in_v0[-0xd];
    pvVar2 = FUN_40b3b848();
    *(undefined4 *)((int)pvVar2 + 0x10) = in_v0[-0xc];
  }
  return;
}



/* 40b3b00c FUN_40b3b00c */

/* Boundary evidence: original MIPS .pdata 40b3b00c..40b3b283. Semantic name remains unreviewed. */

void FUN_40b3b00c(int param_1,int param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  void *_Src;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  int *_Dst;
  
  if (((param_3[1] != 0) && (*(char *)(param_3[1] + 8) != '\0')) && (param_3[2] != 0)) {
    if (1 < param_3[3]) {
      iVar1 = param_3[3] - 1;
      do {
        param_2 = *(int *)(param_2 + -4);
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    _Dst = (int *)(param_3[2] + param_2);
    if ((*param_3 & 8) == 0) {
      if ((*param_4 & 1) == 0) {
        pcVar3 = (code *)param_4[6];
        iVar1 = *(int *)(param_1 + 0x18);
        if (pcVar3 == (code *)0x0) {
          _Src = (void *)(param_4[2] + iVar1);
          uVar4 = param_4[3];
          if (-1 < (int)uVar4) {
            _Src = (void *)((int)_Src + uVar4 + *(int *)(*(int *)(uVar4 + iVar1) + param_4[4]));
          }
          memmove(_Dst,_Src,param_4[5]);
        }
        else if ((*param_4 & 4) == 0) {
          iVar2 = param_4[2] + iVar1;
          uVar4 = param_4[3];
          if (-1 < (int)uVar4) {
            iVar2 = uVar4 + *(int *)(*(int *)(uVar4 + iVar1) + param_4[4]) + iVar2;
          }
          (*pcVar3)(_Dst,iVar2);
        }
        else {
          iVar2 = param_4[2] + iVar1;
          uVar4 = param_4[3];
          if (-1 < (int)uVar4) {
            iVar2 = uVar4 + *(int *)(*(int *)(uVar4 + iVar1) + param_4[4]) + iVar2;
          }
          (*pcVar3)(_Dst,iVar2,1);
        }
      }
      else {
        memmove(_Dst,*(void **)(param_1 + 0x18),param_4[5]);
        if ((param_4[5] == 4) && (iVar1 = *_Dst, iVar1 != 0)) {
          iVar2 = param_4[2] + iVar1;
          uVar4 = param_4[3];
          if (-1 < (int)uVar4) {
            iVar2 = uVar4 + *(int *)(*(int *)(uVar4 + iVar1) + param_4[4]) + iVar2;
          }
          *_Dst = iVar2;
        }
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x18);
      *_Dst = iVar1;
      iVar2 = iVar1 + param_4[2];
      uVar4 = param_4[3];
      if (-1 < (int)uVar4) {
        iVar2 = uVar4 + *(int *)(*(int *)(uVar4 + iVar1) + param_4[4]) + iVar2;
      }
      *_Dst = iVar2;
    }
  }
  return;
}



/* 40b3b284 FUN_40b3b284 */

/* Boundary evidence: original MIPS .pdata 40b3b284..40b3b28f. Semantic name remains unreviewed. */

undefined4 FUN_40b3b284(void)

{
  return 1;
}



/* 40b3b290 FUN_40b3b290 */

/* Boundary evidence: original MIPS .pdata 40b3b290..40b3b6a3. Semantic name remains unreviewed. */

undefined4
FUN_40b3b290(int *param_1,int param_2,undefined4 param_3,uint *param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  HLOCAL pvVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int *local_34;
  int *local_30;
  
  bVar1 = false;
  local_34 = (int *)0x0;
  local_30 = param_1;
  local_44 = FUN_40b3b934(param_2,param_4,param_5);
  if ((((*param_1 == -0x1f928c9d) && (param_1[4] == 3)) &&
      ((iVar2 = param_1[5], iVar2 == 0x19930520 || ((iVar2 == 0x19930521 || (iVar2 == 0x19930522))))
      )) && (param_1[7] == 0)) {
    piVar3 = FUN_40b3b848();
    if (*piVar3 == 0) {
      return 0;
    }
    FUN_40b3b848();
    puVar4 = FUN_40b3b848();
    param_1 = (int *)*puVar4;
    FUN_40b3b848();
    local_34 = param_1;
  }
  iVar2 = FUN_40b3ac20(param_2);
  if (iVar2 == 0) {
    iVar2 = FUN_40b3ac68(param_2);
    if (iVar2 != 0) {
      param_6 = *(int *)(iVar2 + 0xc);
    }
  }
  else {
    local_44 = *(uint *)(iVar2 + 8);
    param_6 = *(int *)(iVar2 + 0xc) + -1;
  }
  piVar3 = FUN_40b3acb0(param_5,param_6,local_44,&local_40,(int *)&local_38);
  if (local_40 < local_38) {
    do {
      if ((((*piVar3 <= (int)local_44) && ((int)local_44 <= piVar3[1])) &&
          (puVar5 = (uint *)piVar3[4], param_6 < (int)puVar5[3])) && (local_3c = 0, 0 < piVar3[3]))
      {
        do {
          if (((*param_1 == -0x1f928c9d) && (param_1[4] == 3)) &&
             ((iVar2 = param_1[5], iVar2 == 0x19930520 ||
              ((iVar2 == 0x19930521 || (iVar2 == 0x19930522)))))) {
            puVar10 = (uint *)param_1[7];
            iVar11 = 0;
            piVar6 = (int *)puVar10[3];
            iVar2 = *piVar6;
            piVar6 = piVar6 + 1;
            if (0 < iVar2) {
              uVar12 = puVar5[1];
              do {
                puVar13 = (uint *)*piVar6;
                if (((uVar12 == 0) || (*(char *)(uVar12 + 8) == '\0')) ||
                   (((((uVar7 = puVar13[1], uVar12 == uVar7 ||
                       (iVar8 = strcmp((char *)(uVar12 + 8),(char *)(uVar7 + 8)), iVar8 == 0)) &&
                      (((*puVar13 & 2) == 0 || ((*puVar5 & 8) != 0)))) &&
                     ((uVar7 = *puVar10, (uVar7 & 1) == 0 || ((*puVar5 & 1) != 0)))) &&
                    ((((uVar7 & 4) == 0 || ((*puVar5 & 4) != 0)) &&
                     (((uVar7 & 2) == 0 || ((*puVar5 & 2) != 0)))))))) {
                  bVar1 = true;
                  break;
                }
                iVar11 = iVar11 + 1;
                piVar6 = piVar6 + 1;
              } while (iVar11 < iVar2);
            }
          }
          else {
            if (((puVar5[1] == 0) || (*(char *)(puVar5[1] + 8) == '\0')) && ((*puVar5 & 0x40) == 0))
            {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
            piVar6 = (int *)0x0;
          }
          if (bVar1) {
            pvVar9 = FUN_40b3b848();
            *(int **)((int)pvVar9 + 0x18) = local_34;
            if (local_34 != (int *)0x0) {
              local_30[6] = param_1[6];
              local_30[7] = param_1[7];
            }
            pvVar9 = FUN_40b3b848();
            *(int **)((int)pvVar9 + 8) = piVar3;
            *param_4 = puVar5[4];
            if ((piVar6 != (int *)0x0) && ((uint *)*piVar6 != (uint *)0x0)) {
              FUN_40b3b00c((int)param_1,param_2,puVar5,(uint *)*piVar6);
            }
            return 1;
          }
          local_3c = local_3c + 1;
          puVar5 = puVar5 + 5;
        } while (local_3c < piVar3[3]);
      }
      local_40 = local_40 + 1;
      piVar3 = piVar3 + 5;
    } while (local_40 < local_38);
  }
  return 0;
}



/* 40b3b6a4 FUN_40b3b6a4 */

/* Boundary evidence: original MIPS .pdata 40b3b6a4..40b3b7ff. Semantic name remains unreviewed. */

undefined4
FUN_40b3b6a4(int *param_1,uint param_2,int param_3,uint *param_4,uint *param_5,int param_6)

{
  HLOCAL pvVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (((*param_1 == -0x1f928c9d) || (*param_5 < 0x19930522)) || ((param_5[8] & 1) == 0)) {
    if ((param_1[1] & 0x66U) == 0) {
      if ((param_5[3] != 0) &&
         (iVar3 = FUN_40b3b290(param_1,param_2,param_3,param_4,(int)param_5,param_6), iVar3 != 0)) {
        return 4;
      }
    }
    else if ((param_1[1] & 0x20U) == 0) {
      if (param_5[1] != 0) {
        FUN_40b3a814(param_2,param_4,(int)param_5,0xffffffff);
      }
    }
    else {
      pvVar1 = FUN_40b3b848();
      FUN_40b3a814(param_2,param_4,(int)param_5,**(uint **)((int)pvVar1 + 8));
      uVar2 = FUN_40b3ad20(param_1,param_2,param_3,(int)param_5,*(undefined **)(param_3 + 0x11c));
      *(undefined4 *)(param_3 + 0x11c) = uVar2;
    }
  }
  return 1;
}



/* 40b3b800 FUN_40b3b800 */

/* Boundary evidence: original MIPS .pdata 40b3b800..40b3b827. Semantic name remains unreviewed. */

void FUN_40b3b800(int *param_1,uint param_2,int param_3,uint *param_4)

{
  FUN_40b3b6a4(param_1,param_2,param_3,param_4,*(uint **)(param_4[1] + 0xc),0);
  return;
}



/* 40b3b828 FUN_40b3b828 */

/* Boundary evidence: original MIPS .pdata 40b3b828..40b3b847. Semantic name remains unreviewed. */

void FUN_40b3b828(void)

{
  FUN_40b3a7e0();
  return;
}



/* 40b3b848 FUN_40b3b848 */

/* Boundary evidence: original MIPS .pdata 40b3b848..40b3b903. Semantic name remains unreviewed. */

HLOCAL FUN_40b3b848(void)

{
  DWORD dwTlsIndex;
  LONG Exchange;
  LONG LVar1;
  LPVOID lpTlsValue;
  
  if (DAT_40b3f158 == 0xffffffff) {
    Exchange = TlsCall(0,0);
    LVar1 = InterlockedCompareExchange((LONG *)&DAT_40b3f158,Exchange,-1);
    if (LVar1 != -1) {
      TlsCall(1,Exchange);
    }
  }
  dwTlsIndex = DAT_40b3f158;
  lpTlsValue = TlsGetValue(DAT_40b3f158);
  if ((lpTlsValue != (LPVOID)0x0) || (lpTlsValue = LocalAlloc(0x40,0x20), lpTlsValue != (HLOCAL)0x0)
     ) {
    TlsSetValue(dwTlsIndex,lpTlsValue);
  }
  return lpTlsValue;
}



/* 40b3b904 FUN_40b3b904 */

/* Boundary evidence: original MIPS .pdata 40b3b904..40b3b933. Semantic name remains unreviewed. */

void FUN_40b3b904(undefined *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 auStack_18 [20];
  
  if (param_4 != 0) {
    *(undefined1 **)param_4 = auStack_18;
  }
  (*(code *)param_1)();
  return;
}



/* 40b3b934 FUN_40b3b934 */

uint FUN_40b3b934(undefined4 param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = 0;
  if (*(uint *)(param_3 + 0x14) != 0) {
    puVar2 = *(uint **)(param_3 + 0x18);
    do {
      if (*param_2 < *puVar2) break;
      uVar1 = uVar1 + 1;
      puVar2 = puVar2 + 2;
    } while (uVar1 < *(uint *)(param_3 + 0x14));
    if (uVar1 != 0) {
      return (*(uint **)(param_3 + 0x18))[uVar1 * 2 + -1];
    }
  }
  return 0xffffffff;
}



/* 40b3ba40 FUN_40b3ba40 */

/* Boundary evidence: original MIPS .pdata 40b3ba40..40b3baaf. Semantic name remains unreviewed. */

void FUN_40b3ba40(int *param_1,uint param_2,int param_3,uint *param_4)

{
  FUN_40b3a11c(param_2,param_4,(uint *)(*(int *)(param_4[1] + 0xc) + 0x24));
  FUN_40b3b800(param_1,param_2,param_3,param_4);
  return;
}


