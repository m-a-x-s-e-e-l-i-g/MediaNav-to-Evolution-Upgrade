/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40c11000 FUN_40c11000 */

/* Boundary evidence: original MIPS .pdata 40c11000..40c1101b. Semantic name remains unreviewed. */

void FUN_40c11000(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  return;
}



/* 40c1101c FUN_40c1101c */

/* Boundary evidence: original MIPS .pdata 40c1101c..40c11073. Semantic name remains unreviewed. */

void FUN_40c1101c(int param_1)

{
  HANDLE hHandle;
  
  hHandle = (HANDLE)InterlockedExchange((LONG *)(param_1 + 0x14),0);
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
    CloseHandle(hHandle);
  }
  return;
}



/* 40c11074 FUN_40c11074 */

/* Boundary evidence: original MIPS .pdata 40c11074..40c110bb. Semantic name remains unreviewed. */

undefined4 * FUN_40c11074(undefined4 *param_1)

{
  FUN_40c1a620((int)param_1);
  *param_1 = &PTR_FUN_40c21020;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 2;
  return param_1;
}



/* 40c110bc FUN_40c110bc */

/* Boundary evidence: original MIPS .pdata 40c110bc..40c111bb. Semantic name remains unreviewed. */

int FUN_40c110bc(LPVOID param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if ((*(int **)((int)param_1 + 0x44) == (int *)0x0) || (*(int *)((int)param_1 + 0x40) == 0)) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7fff0001;
  }
  if (*(int *)((int)param_1 + 0x14) == 0) {
    iVar2 = (**(code **)(**(int **)((int)param_1 + 0x44) + 0x14))();
    if (iVar2 < 0) {
      LeaveCriticalSection(lpCriticalSection);
      return iVar2;
    }
    bVar1 = FUN_40c1a70c(param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      LeaveCriticalSection(lpCriticalSection);
      return -0x7fffbffb;
    }
  }
  *(undefined4 *)((int)param_1 + 0x48) = 1;
  iVar2 = FUN_40c1a7c0((int)param_1,1);
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40c111bc FUN_40c111bc */

/* Boundary evidence: original MIPS .pdata 40c111bc..40c111eb. Semantic name remains unreviewed. */

void FUN_40c111bc(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c111ec FUN_40c111ec */

/* Boundary evidence: original MIPS .pdata 40c111ec..40c112df. Semantic name remains unreviewed. */

int FUN_40c111ec(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if (*(int **)(param_1 + 0x40) == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = -0x7fff0001;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = -0x7fff0001;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x40) + 0x24))();
    if (iVar1 < 0) {
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      *(undefined4 *)(param_1 + 0x48) = 0;
      iVar1 = FUN_40c1a7c0(param_1,0);
      (**(code **)(**(int **)(param_1 + 0x40) + 0x28))();
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar1;
}



/* 40c112e0 FUN_40c112e0 */

/* Boundary evidence: original MIPS .pdata 40c112e0..40c1130f. Semantic name remains unreviewed. */

void FUN_40c112e0(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c11310 FUN_40c11310 */

/* Boundary evidence: original MIPS .pdata 40c11310..40c11423. Semantic name remains unreviewed. */

int FUN_40c11310(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if (*(int **)(param_1 + 0x40) == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = -0x7fff0001;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = 1;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x40) + 0x24))();
    if (iVar1 < 0) {
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      *(undefined4 *)(param_1 + 0x48) = 2;
      FUN_40c1a7c0(param_1,2);
      (**(code **)(**(int **)(param_1 + 0x40) + 0x28))();
      FUN_40c1101c(param_1);
      if (*(int **)(param_1 + 0x44) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x44) + 0x18))();
      }
      LeaveCriticalSection(lpCriticalSection);
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40c11424 FUN_40c11424 */

/* Boundary evidence: original MIPS .pdata 40c11424..40c11453. Semantic name remains unreviewed. */

void FUN_40c11424(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c11454 FUN_40c11454 */

/* Boundary evidence: original MIPS .pdata 40c11454..40c114bf. Semantic name remains unreviewed. */

void FUN_40c11454(int *param_1)

{
  int iVar1;
  undefined4 auStack_10 [2];
  
  do {
    iVar1 = FUN_40c1a884((int)param_1,auStack_10);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(*param_1 + 8))(param_1,param_1[0x10]);
  } while (iVar1 == 0);
  if (iVar1 == 2) {
    (**(code **)(*param_1 + 0xc))(param_1);
  }
  return;
}



/* 40c114c0 FUN_40c114c0 */

/* Boundary evidence: original MIPS .pdata 40c114c0..40c1155f. Semantic name remains unreviewed. */

undefined4 FUN_40c114c0(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  FUN_40c11310(param_1);
  if (*(int **)(param_1 + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x40) + 8))();
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (*(int **)(param_1 + 0x44) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x44) + 8))();
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return 0;
}



/* 40c11560 FUN_40c11560 */

/* Boundary evidence: original MIPS .pdata 40c11560..40c1158f. Semantic name remains unreviewed. */

void FUN_40c11560(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40c11590 FUN_40c11590 */

/* Boundary evidence: original MIPS .pdata 40c11590..40c115ab. Semantic name remains unreviewed. */

void FUN_40c11590(LPVOID param_1)

{
  FUN_40c110bc(param_1);
  return;
}



/* 40c115ac FUN_40c115ac */

/* Boundary evidence: original MIPS .pdata 40c115ac..40c115cb. Semantic name remains unreviewed. */

undefined4 FUN_40c115ac(int param_1)

{
  FUN_40c11310(param_1);
  return 0;
}



/* 40c115cc FUN_40c115cc */

/* Boundary evidence: original MIPS .pdata 40c115cc..40c11667. Semantic name remains unreviewed. */

bool FUN_40c115cc(int *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  iVar1 = param_1[0x12];
  if (iVar1 == 1) {
    (**(code **)(*param_1 + 0x14))(param_1);
    FUN_40c111ec((int)param_1);
    (**(code **)(*param_1 + 0x18))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return iVar1 == 1;
}



/* 40c11668 FUN_40c11668 */

/* Boundary evidence: original MIPS .pdata 40c11668..40c11697. Semantic name remains unreviewed. */

void FUN_40c11668(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c11698 FUN_40c11698 */

/* Boundary evidence: original MIPS .pdata 40c11698..40c11733. Semantic name remains unreviewed. */

bool FUN_40c11698(int *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  iVar1 = param_1[0x12];
  if (iVar1 == 1) {
    (**(code **)(*param_1 + 0x14))(param_1);
    FUN_40c111ec((int)param_1);
    (**(code **)(*param_1 + 0x18))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return iVar1 == 1;
}



/* 40c11734 FUN_40c11734 */

/* Boundary evidence: original MIPS .pdata 40c11734..40c11763. Semantic name remains unreviewed. */

void FUN_40c11734(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c11764 FUN_40c11764 */

/* Boundary evidence: original MIPS .pdata 40c11764..40c1182f. Semantic name remains unreviewed. */

undefined4 FUN_40c11764(int *param_1)

{
  int iVar1;
  
  do {
    iVar1 = FUN_40c1a84c((int)param_1);
    if (iVar1 == 0) {
      FUN_40c1a8e8((int)param_1,0);
    }
    else if (iVar1 == 1) {
      FUN_40c1a8e8((int)param_1,0);
      FUN_40c11454(param_1);
    }
    else if (iVar1 == 2) {
      FUN_40c1a8e8((int)param_1,0);
      return 0;
    }
    if ((int *)param_1[0x10] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x10] + 0x24))();
      (**(code **)(*(int *)param_1[0x10] + 0x28))();
    }
  } while( true );
}



/* 40c11830 FUN_40c11830 */

/* Boundary evidence: original MIPS .pdata 40c11830..40c11887. Semantic name remains unreviewed. */

void FUN_40c11830(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40c21020;
  FUN_40c114c0((int)param_1);
  FUN_40c1a69c((int)param_1);
  return;
}



/* 40c11888 FUN_40c11888 */

/* Boundary evidence: original MIPS .pdata 40c11888..40c118b7. Semantic name remains unreviewed. */

void FUN_40c11888(void)

{
  int *in_v0;
  
  FUN_40c1a69c(*in_v0);
  return;
}



/* 40c118b8 FUN_40c118b8 */

/* Boundary evidence: original MIPS .pdata 40c118b8..40c11a17. Semantic name remains unreviewed. */

int FUN_40c118b8(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar3;
  LPCRITICAL_SECTION p_Var4;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x18);
  p_Var4 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  piVar3 = (int *)(param_1 + 0x40);
  if (*piVar3 != 0) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7ffbfdfc;
  }
  iVar1 = (**(code **)*param_2)(param_2,&DAT_40c236d8,piVar3);
  if (-1 < iVar1) {
    local_28 = 3;
    piVar2 = (int *)*piVar3;
    local_24 = 0x20000;
    local_20 = 0;
    local_1c = 0;
    if ((piVar2 != (int *)0x0) &&
       (iVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,0,&local_28,param_1 + 0x44,p_Var4), iVar1 < 0))
    {
      FUN_40c114c0(param_1);
      LeaveCriticalSection(lpCriticalSection);
      return iVar1;
    }
    iVar1 = (**(code **)(*(int *)*piVar3 + 0x20))((int *)*piVar3,auStack_30,auStack_38);
    if (iVar1 < 0) {
      FUN_40c114c0(param_1);
      LeaveCriticalSection(lpCriticalSection);
      return iVar1;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40c11a18 FUN_40c11a18 */

/* Boundary evidence: original MIPS .pdata 40c11a18..40c11a47. Semantic name remains unreviewed. */

void FUN_40c11a18(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x40));
  return;
}



/* 40c11a48 FUN_40c11a48 */

/* Boundary evidence: original MIPS .pdata 40c11a48..40c11a93. Semantic name remains unreviewed. */

undefined4 * FUN_40c11a48(undefined4 *param_1,uint param_2)

{
  FUN_40c11830(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c11a94 FUN_40c11a94 */

/* Boundary evidence: original MIPS .pdata 40c11a94..40c11aaf. Semantic name remains unreviewed. */

void FUN_40c11a94(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



/* 40c11ab0 FUN_40c11ab0 */

void FUN_40c11ab0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40c218e8;
  return;
}



/* 40c11ac0 FUN_40c11ac0 */

/* Boundary evidence: original MIPS .pdata 40c11ac0..40c11b03. Semantic name remains unreviewed. */

undefined4 * FUN_40c11ac0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40c218e8;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c11b04 FUN_40c11b04 */

/* Boundary evidence: original MIPS .pdata 40c11b04..40c11b2f. Semantic name remains unreviewed. */

void FUN_40c11b04(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x4c) + 0x98) + 0x18))();
  return;
}



/* 40c11b30 FUN_40c11b30 */

/* Boundary evidence: original MIPS .pdata 40c11b30..40c11b5b. Semantic name remains unreviewed. */

void FUN_40c11b30(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x4c) + 0xc) + 0x38))();
  return;
}



/* 40c11b5c FUN_40c11b5c */

/* Boundary evidence: original MIPS .pdata 40c11b5c..40c11b9f. Semantic name remains unreviewed. */

void FUN_40c11b5c(int param_1,int param_2)

{
  if ((param_2 != -0x7ffbfdd9) && (param_2 < 0)) {
    FUN_40c1aa18(*(int *)(*(int *)(param_1 + 0x4c) + 0x70));
  }
  return;
}



/* 40c11ba0 FUN_40c11ba0 */

/* Boundary evidence: original MIPS .pdata 40c11ba0..40c11bcb. Semantic name remains unreviewed. */

void FUN_40c11ba0(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x4c) + 0xc) + 0x3c))();
  return;
}



/* 40c11bcc FUN_40c11bcc */

/* Boundary evidence: original MIPS .pdata 40c11bcc..40c11bf7. Semantic name remains unreviewed. */

void FUN_40c11bcc(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x4c) + 0xc) + 0x40))();
  return;
}



/* 40c11bf8 FUN_40c11bf8 */

/* Boundary evidence: original MIPS .pdata 40c11bf8..40c11c3b. Semantic name remains unreviewed. */

undefined4 * FUN_40c11bf8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40c2193c;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c11c4c FUN_40c11c4c */

/* Boundary evidence: original MIPS .pdata 40c11c4c..40c11c9f. Semantic name remains unreviewed. */

void FUN_40c11c4c(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while (iVar2 != 0) {
    puVar1 = (undefined4 *)*param_1;
    *param_1 = puVar1[4];
    (**(code **)*puVar1)(puVar1,1);
    iVar2 = *param_1;
  }
  return;
}



/* 40c11ca0 FUN_40c11ca0 */

/* Boundary evidence: original MIPS .pdata 40c11ca0..40c11cbb. Semantic name remains unreviewed. */

void FUN_40c11ca0(HMODULE param_1,int param_2)

{
  FUN_40c1d834(param_1,param_2);
  return;
}



/* 40c11cbc DllRegisterServer */

/* Boundary evidence: original MIPS .pdata 40c11cbc..40c11cd7. Semantic name remains unreviewed. */

void DllRegisterServer(void)

{
                    /* 0x1cbc  3  DllRegisterServer */
  FUN_40c1e53c(1);
  return;
}



/* 40c11cd8 DllUnregisterServer */

/* Boundary evidence: original MIPS .pdata 40c11cd8..40c11cf3. Semantic name remains unreviewed. */

void DllUnregisterServer(void)

{
                    /* 0x1cd8  4  DllUnregisterServer */
  FUN_40c1e53c(0);
  return;
}



/* 40c11cf4 FUN_40c11cf4 */

/* Boundary evidence: original MIPS .pdata 40c11cf4..40c11e0b. Semantic name remains unreviewed. */

void FUN_40c11cf4(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40c238c8,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x44;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40c1e690(piVar2,param_3);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40c235a8,0x10);
    if ((((iVar1 == 0) && (param_1[0x3b] != 0)) ||
        ((iVar1 = memcmp(param_2,&DAT_40c24f48,0x10), iVar1 == 0 && (param_1[0x3b] != 0)))) ||
       ((iVar1 = memcmp(param_2,&DAT_40c25354,0x10), iVar1 == 0 && (param_1[0x3b] != 0)))) {
      (*(code *)**(undefined4 **)param_1[0x3b])((undefined4 *)param_1[0x3b],param_2,param_3);
    }
    else {
      FUN_40c1bcd0(param_1,param_2,param_3);
    }
  }
  return;
}



/* 40c11e0c FUN_40c11e0c */

/* Boundary evidence: original MIPS .pdata 40c11e0c..40c11f2f. Semantic name remains unreviewed. */

undefined4 FUN_40c11e0c(undefined4 param_1,void *param_2)

{
  int iVar1;
  void *_Buf1;
  
  iVar1 = memcmp(param_2,&DAT_40c25344,0x10);
  if ((iVar1 == 0) && (iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40c25344,0x10), iVar1 == 0)
     ) {
    return 0;
  }
  iVar1 = memcmp(param_2,&DAT_40c23b98,0x10);
  if (iVar1 == 0) {
    _Buf1 = (void *)((int)param_2 + 0x10);
    iVar1 = memcmp(_Buf1,&DAT_40c23e98,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40c23e68,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40c23f38,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40c23f58,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40c25344,0x10);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



/* 40c11f30 FUN_40c11f30 */

/* Boundary evidence: original MIPS .pdata 40c11f30..40c11f73. Semantic name remains unreviewed. */

undefined4 FUN_40c11f30(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x2c))();
  return uVar1;
}



/* 40c11f74 FUN_40c11f74 */

/* Boundary evidence: original MIPS .pdata 40c11f74..40c11fb7. Semantic name remains unreviewed. */

undefined4 FUN_40c11f74(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x30))();
  return uVar1;
}



/* 40c11fb8 FUN_40c11fb8 */

/* Boundary evidence: original MIPS .pdata 40c11fb8..40c1201f. Semantic name remains unreviewed. */

undefined4 FUN_40c11fb8(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x34))();
  return uVar1;
}



/* 40c12020 FUN_40c12020 */

/* Boundary evidence: original MIPS .pdata 40c12020..40c1203b. Semantic name remains unreviewed. */

void FUN_40c12020(int param_1)

{
  FUN_40c1c1d0(param_1);
  return;
}



/* 40c1203c FUN_40c1203c */

/* Boundary evidence: original MIPS .pdata 40c1203c..40c12057. Semantic name remains unreviewed. */

void FUN_40c1203c(int param_1)

{
  FUN_40c1c2a4(param_1);
  return;
}



/* 40c12058 FUN_40c12058 */

/* Boundary evidence: original MIPS .pdata 40c12058..40c12107. Semantic name remains unreviewed. */

undefined4 * FUN_40c12058(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_40c21940;
  _eh_vector_constructor_iterator_
            (param_1 + 2,8,1,(_func_void_void_ptr *)&LAB_40c11c3c,FUN_40c11c4c);
  param_1[6] = 0;
  param_1[8] = 0xffffffff;
  param_1[9] = 0xffffffff;
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 1;
  return param_1;
}



/* 40c12108 FUN_40c12108 */

/* Boundary evidence: original MIPS .pdata 40c12108..40c12137. Semantic name remains unreviewed. */

void FUN_40c12108(void)

{
  undefined4 *in_v0;
  
  FUN_40c11ab0((undefined4 *)*in_v0);
  return;
}



/* 40c12148 FUN_40c12148 */

undefined4 FUN_40c12148(char *param_1)

{
  char cVar1;
  char cVar2;
  
  cVar1 = *param_1;
  if ((((((((((cVar1 != 'F') || (param_1[1] != 'L')) || (param_1[2] != 'V')) &&
           ((cVar1 != 'w' || (param_1[1] != '\v')))) && ((cVar1 != '\v' || (param_1[1] != 'w')))) &&
         ((((cVar1 != 'R' || (param_1[1] != 'I')) || (param_1[2] != 'F')) || (param_1[3] != 'F'))))
        && ((((cVar1 != 'F' || (param_1[1] != 'O')) || (param_1[2] != 'R')) || (param_1[3] != 'M')))
        ) && ((((cVar1 != 'f' || (param_1[1] != 'L')) ||
               ((param_1[2] != 'a' || (param_1[3] != 'C')))) &&
              (((cVar1 != 'O' || (param_1[1] != 'g')) ||
               ((param_1[2] != 'g' || (param_1[3] != 'S')))))))) &&
      ((((((((cVar1 != 'A' || (param_1[1] != 'D')) || (param_1[2] != 'I')) || (param_1[3] != 'F'))
          && (((cVar1 != '.' || (param_1[1] != 's')) || ((param_1[2] != 'n' || (param_1[3] != 'd')))
              ))) &&
         (((cVar2 = param_1[2], cVar2 != 'A' || (param_1[3] != 'M')) || (param_1[4] != 'R')))) &&
        ((((param_1[4] != 'f' || (param_1[5] != 't')) || (param_1[6] != 'y')) || (param_1[7] != 'p')
         ))) && (((cVar1 != 'M' || (param_1[1] != 'A')) || (cVar2 != 'C')))))) &&
     (((param_1[1] != 'R' || (cVar2 != 'M')) || (param_1[3] != 'F')))) {
    return 0;
  }
  return 0x80004005;
}



/* 40c12394 FUN_40c12394 */

/* Boundary evidence: original MIPS .pdata 40c12394..40c1243f. Semantic name remains unreviewed. */

undefined4 FUN_40c12394(int *param_1)

{
  int iVar1;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  
  local_10 = DAT_40c2618c;
  local_20 = 0x7b785574;
  local_28 = 0;
  local_24 = 0;
  local_1c = 0x11cf8c82;
  local_18 = 0xaa000cbc;
  local_14 = 0xf674ac00;
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,&local_28,&local_20);
  if (-1 < iVar1) {
    if ((0 < local_24) || ((local_24 == 0 && (local_28 != 0)))) {
      FUN_40c20494(local_10);
      return 1;
    }
  }
  FUN_40c20494(local_10);
  return 0;
}



/* 40c12440 FUN_40c12440 */

/* Boundary evidence: original MIPS .pdata 40c12440..40c125bb. Semantic name remains unreviewed. */

undefined4 FUN_40c12440(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 extraout_v1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(int *)(*(int *)(param_1 + 0x10) + 0x44) == 0) {
    uVar3 = *(uint *)(param_1 + 0x24);
    *(uint *)(param_1 + 0x38) = param_3;
    *(uint *)(param_1 + 0x3c) = param_4;
    if (((int)uVar3 < 0) || ((uVar3 == 0 && (*(uint *)(param_1 + 0x20) == 0)))) {
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x18);
      iVar1 = FUN_40c1a178(*(uint *)(iVar1 + 8) - *(uint *)(iVar1 + 0x18),
                           (*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 0x1c)) -
                           (uint)(*(uint *)(iVar1 + 8) < *(uint *)(iVar1 + 0x18)),param_3,param_4,
                           *(uint *)(param_1 + 0x20),uVar3,0,0);
      *(int *)(param_1 + 0x30) = iVar1;
      *(undefined4 *)(param_1 + 0x34) = extraout_v1;
    }
    uVar3 = *(uint *)(*(int *)(param_1 + 0x18) + 0x18);
    uVar4 = uVar3 + *(int *)(param_1 + 0x30);
    *(uint *)(param_1 + 0x34) =
         *(int *)(*(int *)(param_1 + 0x18) + 0x1c) + *(int *)(param_1 + 0x34) +
         (uint)(uVar4 < uVar3);
    *(uint *)(param_1 + 0x30) = uVar4;
    *(uint *)(param_1 + 0x30) = uVar4 & 0xfffffffc;
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x34);
  }
  else {
    iVar1 = FUN_40c185d4(*(int *)(param_1 + 0x10),param_2,param_3,param_4);
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x4c) + iVar1 * 0x18;
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar2 + 0x14);
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x4c) + iVar1 * 0x18;
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(iVar1 + 0xc);
    FUN_40c185cc();
    FUN_40c185cc();
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  return 0;
}



/* 40c125bc FUN_40c125bc */

/* Boundary evidence: original MIPS .pdata 40c125bc..40c125ef. Semantic name remains unreviewed. */

undefined4 FUN_40c125bc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = __dptoli(param_3,param_4);
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  return 0;
}



/* 40c125f0 FUN_40c125f0 */

/* Boundary evidence: original MIPS .pdata 40c125f0..40c12653. Semantic name remains unreviewed. */

undefined4 FUN_40c125f0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x24))(param_1);
  *param_2 = iVar1 + iVar2;
  return 0;
}



/* 40c12654 FUN_40c12654 */

/* Boundary evidence: original MIPS .pdata 40c12654..40c126ff. Semantic name remains unreviewed. */

undefined4 FUN_40c12654(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x24))(param_1);
  if (iVar1 + iVar2 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
    iVar2 = (**(code **)(*param_1 + 0x24))(param_1);
    if (param_2 < iVar1 + iVar2) {
      return 0x80004001;
    }
  }
  return 0x80070057;
}



/* 40c12750 FUN_40c12750 */

/* Boundary evidence: original MIPS .pdata 40c12750..40c1276b. Semantic name remains unreviewed. */

void FUN_40c12750(int param_1)

{
  FUN_40c1ade0(param_1);
  return;
}



/* 40c1276c FUN_40c1276c */

/* Boundary evidence: original MIPS .pdata 40c1276c..40c12787. Semantic name remains unreviewed. */

void FUN_40c1276c(undefined4 *param_1)

{
  FUN_40c1eb20(param_1);
  return;
}



/* 40c12788 FUN_40c12788 */

/* Boundary evidence: original MIPS .pdata 40c12788..40c127a3. Semantic name remains unreviewed. */

void FUN_40c12788(int param_1)

{
  FUN_40c1e7b0(param_1);
  return;
}



/* 40c127a4 FUN_40c127a4 */

/* Boundary evidence: original MIPS .pdata 40c127a4..40c127bf. Semantic name remains unreviewed. */

void FUN_40c127a4(int *param_1)

{
  FUN_40c1e7ec(param_1);
  return;
}



/* 40c127c0 FUN_40c127c0 */

/* Boundary evidence: original MIPS .pdata 40c127c0..40c127db. Semantic name remains unreviewed. */

void FUN_40c127c0(int *param_1,void *param_2,undefined4 *param_3)

{
  FUN_40c1ae24(param_1,param_2,param_3);
  return;
}



/* 40c127dc FUN_40c127dc */

/* Boundary evidence: original MIPS .pdata 40c127dc..40c12847. Semantic name remains unreviewed. */

void FUN_40c127dc(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  undefined1 auStack_20 [16];
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x70) + 0xbc);
  (**(code **)(*piVar1 + 8))(piVar1,param_3 + 4,param_3);
  *(undefined4 *)(param_3 + 8) = 1;
  *(undefined4 *)(param_3 + 0xc) = 0;
  (**(code **)(*param_2 + 0xc))(param_2,param_3,auStack_20);
  return;
}



/* 40c12848 FUN_40c12848 */

/* Boundary evidence: original MIPS .pdata 40c12848..40c12863. Semantic name remains unreviewed. */

void FUN_40c12848(int param_1,int *param_2)

{
  FUN_40c1b1dc(param_1,param_2);
  return;
}



/* 40c12864 FUN_40c12864 */

/* Boundary evidence: original MIPS .pdata 40c12864..40c1287f. Semantic name remains unreviewed. */

void FUN_40c12864(int *param_1)

{
  FUN_40c1b1b4(param_1);
  return;
}



/* 40c12880 FUN_40c12880 */

/* Boundary evidence: original MIPS .pdata 40c12880..40c1289b. Semantic name remains unreviewed. */

void FUN_40c12880(undefined4 *param_1)

{
  FUN_40c1eb20(param_1);
  return;
}



/* 40c1289c FUN_40c1289c */

/* Boundary evidence: original MIPS .pdata 40c1289c..40c129ff. Semantic name remains unreviewed. */

int FUN_40c1289c(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar5;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if ((param_1[2] == 0) && (iVar1 = (**(code **)(*param_1 + 0x14))(param_1), iVar1 < 0)) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (param_1[2] != 2) {
      piVar5 = param_1 + -3;
      iVar1 = (**(code **)(*piVar5 + 0x18))(piVar5);
      iVar4 = 0;
      if (0 < iVar1) {
        do {
          piVar2 = (int *)(**(code **)(*piVar5 + 0x1c))(piVar5,iVar4);
          if ((piVar2[6] != 0) && (iVar3 = (**(code **)(*piVar2 + 0x1c))(piVar2), iVar3 < 0)) {
            LeaveCriticalSection(lpCriticalSection);
            return iVar3;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
      }
    }
    param_1[2] = 2;
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40c12a00 FUN_40c12a00 */

/* Boundary evidence: original MIPS .pdata 40c12a00..40c12a2f. Semantic name remains unreviewed. */

void FUN_40c12a00(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 40c12a30 FUN_40c12a30 */

/* Boundary evidence: original MIPS .pdata 40c12a30..40c12a93. Semantic name remains unreviewed. */

undefined4 FUN_40c12a30(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  if (*(int *)(param_1 + 0x18) != 0) {
    DAT_40c2659c = *(int *)(param_1 + 0x18);
  }
  if ((DAT_40c26598 != (int *)0x0) && (iVar1 = (**(code **)(*DAT_40c26598 + 0x10))(), -1 < iVar1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40c12a94 FUN_40c12a94 */

/* Boundary evidence: original MIPS .pdata 40c12a94..40c12c63. Semantic name remains unreviewed. */

int FUN_40c12a94(int *param_1,undefined4 param_2)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *local_20;
  LPCRITICAL_SECTION local_1c;
  
  if (((DAT_40c26598 == 0) && (DAT_40c2659c != 0)) &&
     (iVar1 = memcmp(*(void **)(DAT_40c2659c + 4),&DAT_40c24a88,0x10), iVar1 == 0)) {
    local_20 = (int *)0x0;
    (**(code **)(*(int *)param_1[0x10] + 0x14))((int *)param_1[0x10],&local_20);
    if (local_20 != (int *)0x0) {
      local_1c = (LPCRITICAL_SECTION)0x0;
      while ((DAT_40c26598 == 0 &&
             (iVar1 = (**(code **)(*local_20 + 0xc))(local_20,1,&local_1c,0), iVar1 == 0))) {
        (**(code **)local_1c->DebugInfo)(local_1c,&DAT_40c218d8,&DAT_40c26598);
        (*(code *)(local_1c->DebugInfo->ProcessLocksList).Flink)();
      }
      (**(code **)(*local_20 + 8))();
    }
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x25);
  local_1c = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  if (param_1[5] == 0) {
    iVar1 = -0x7fffbffc;
  }
  else {
    iVar1 = (**(code **)(*(int *)param_1[0x2f] + 0xc))((int *)param_1[0x2f],param_2);
    if ((iVar1 != 2) && (iVar1 < 0)) {
      if (iVar1 == -0x7ffbfda3) {
        LeaveCriticalSection(lpCriticalSection);
        return -0x7ffbfda3;
      }
      (**(code **)(*param_1 + 0x2c))(param_1);
      LeaveCriticalSection(lpCriticalSection);
      return 1;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40c12c64 FUN_40c12c64 */

/* Boundary evidence: original MIPS .pdata 40c12c64..40c12c93. Semantic name remains unreviewed. */

void FUN_40c12c64(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40c12c94 FUN_40c12c94 */

/* Boundary evidence: original MIPS .pdata 40c12c94..40c12cbb. Semantic name remains unreviewed. */

void FUN_40c12c94(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xbc) + 0x14))();
  return;
}



/* 40c12cbc FUN_40c12cbc */

/* Boundary evidence: original MIPS .pdata 40c12cbc..40c12ce3. Semantic name remains unreviewed. */

void FUN_40c12cbc(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xbc) + 0x10))();
  return;
}



/* 40c12ce4 FUN_40c12ce4 */

/* Boundary evidence: original MIPS .pdata 40c12ce4..40c12d2f. Semantic name remains unreviewed. */

undefined4 FUN_40c12ce4(undefined4 param_1,void *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_2 != (void *)0x0) {
    iVar2 = memcmp(param_2,&DAT_40c24cf8,0x10);
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 40c12d30 FUN_40c12d30 */

undefined4 FUN_40c12d30(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0xc0) = *param_2;
  *(undefined4 *)(param_1 + 0xc4) = param_2[1];
  *(undefined4 *)(param_1 + 200) = param_2[2];
  *(undefined4 *)(param_1 + 0xcc) = param_2[3];
  return 0;
}



/* 40c12d58 FUN_40c12d58 */

/* Boundary evidence: original MIPS .pdata 40c12d58..40c12ddf. Semantic name remains unreviewed. */

undefined4 FUN_40c12d58(int param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xd8);
  EnterCriticalSection(lpCriticalSection);
  if (*(int **)(param_1 + 0xbc) == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0xbc) + 0x18))();
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40c12de0 FUN_40c12de0 */

/* Boundary evidence: original MIPS .pdata 40c12de0..40c12e0f. Semantic name remains unreviewed. */

void FUN_40c12de0(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40c12e10 FUN_40c12e10 */

/* Boundary evidence: original MIPS .pdata 40c12e10..40c12ec7. Semantic name remains unreviewed. */

undefined4 * FUN_40c12e10(undefined4 *param_1,int param_2,undefined4 param_3)

{
  FUN_40c1d694(param_1,0,param_2,param_2 + 0x6c,param_3,L"Input");
  *param_1 = &PTR_FUN_40c21ae8;
  param_1[3] = &PTR_FUN_40c21aa0;
  param_1[4] = &PTR_LAB_40c21a8c;
  param_1[0x26] = &PTR_LAB_40c21a68;
  param_1[0x36] = 0;
  FUN_40c11074(param_1 + 0x37);
  param_1[0x37] = &PTR_FUN_40c21920;
  param_1[0x4a] = param_1;
  return param_1;
}



/* 40c12ec8 FUN_40c12ec8 */

/* Boundary evidence: original MIPS .pdata 40c12ec8..40c12ef7. Semantic name remains unreviewed. */

void FUN_40c12ec8(void)

{
  int *in_v0;
  
  FUN_40c1b66c(*in_v0);
  return;
}



/* 40c12ef8 FUN_40c12ef8 */

/* Boundary evidence: original MIPS .pdata 40c12ef8..40c12f1f. Semantic name remains unreviewed. */

void FUN_40c12ef8(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40c12f20 FUN_40c12f20 */

/* Boundary evidence: original MIPS .pdata 40c12f20..40c12f47. Semantic name remains unreviewed. */

void FUN_40c12f20(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40c12f48 FUN_40c12f48 */

/* Boundary evidence: original MIPS .pdata 40c12f48..40c12f6f. Semantic name remains unreviewed. */

void FUN_40c12f48(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40c12f70 FUN_40c12f70 */

/* Boundary evidence: original MIPS .pdata 40c12f70..40c12fdf. Semantic name remains unreviewed. */

undefined4 FUN_40c12f70(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40c23588,0x10);
  if (iVar1 == 0) {
    uVar2 = 0x80004002;
  }
  else {
    uVar2 = FUN_40c1b6b4(param_1,param_2,param_3);
  }
  return uVar2;
}



/* 40c12fe0 FUN_40c12fe0 */

/* Boundary evidence: original MIPS .pdata 40c12fe0..40c1302b. Semantic name remains unreviewed. */

void FUN_40c12fe0(int param_1)

{
  FUN_40c11830((undefined4 *)(param_1 + 0xdc));
  FUN_40c1b66c(param_1);
  return;
}



/* 40c1302c FUN_40c1302c */

/* Boundary evidence: original MIPS .pdata 40c1302c..40c1305b. Semantic name remains unreviewed. */

void FUN_40c1302c(void)

{
  int *in_v0;
  
  FUN_40c1b66c(*in_v0);
  return;
}



/* 40c13064 FUN_40c13064 */

/* Boundary evidence: original MIPS .pdata 40c13064..40c130af. Semantic name remains unreviewed. */

void FUN_40c13064(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40c1af44(param_1,param_2);
  if (-1 < iVar1) {
    FUN_40c118b8(param_1 + 0xdc,param_2);
  }
  return;
}



/* 40c130b0 FUN_40c130b0 */

/* Boundary evidence: original MIPS .pdata 40c130b0..40c130f3. Semantic name remains unreviewed. */

void FUN_40c130b0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x40))();
  FUN_40c114c0(param_1 + 0xdc);
  FUN_40c1b120();
  return;
}



/* 40c130f4 FUN_40c130f4 */

/* Boundary evidence: original MIPS .pdata 40c130f4..40c13197. Semantic name remains unreviewed. */

int FUN_40c130f4(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 100) + 0x80);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x38))();
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    (**(code **)(**(int **)(param_1 + 100) + 0x2c))();
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40c13198 FUN_40c13198 */

/* Boundary evidence: original MIPS .pdata 40c13198..40c131c7. Semantic name remains unreviewed. */

void FUN_40c13198(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c131c8 FUN_40c131c8 */

/* Boundary evidence: original MIPS .pdata 40c131c8..40c1323f. Semantic name remains unreviewed. */

undefined4 FUN_40c131c8(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 100) + 0x6c);
  EnterCriticalSection(lpCriticalSection);
  FUN_40c1b938(param_1);
  (**(code **)(**(int **)(param_1 + 100) + 0x24))();
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40c13240 FUN_40c13240 */

/* Boundary evidence: original MIPS .pdata 40c13240..40c1326f. Semantic name remains unreviewed. */

void FUN_40c13240(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40c13270 FUN_40c13270 */

/* Boundary evidence: original MIPS .pdata 40c13270..40c132e7. Semantic name remains unreviewed. */

undefined4 FUN_40c13270(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 100) + 0x80);
  EnterCriticalSection(lpCriticalSection);
  FUN_40c1b980(param_1);
  (**(code **)(**(int **)(param_1 + 100) + 0x28))();
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40c132e8 FUN_40c132e8 */

/* Boundary evidence: original MIPS .pdata 40c132e8..40c13317. Semantic name remains unreviewed. */

void FUN_40c132e8(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40c13318 FUN_40c13318 */

/* Boundary evidence: original MIPS .pdata 40c13318..40c1340b. Semantic name remains unreviewed. */

int FUN_40c13318(int param_1,undefined4 param_2)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + -0x28) + 0x80);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(*(int *)(param_1 + -0x98) + 0x38))();
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else if (iVar1 == 1) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = 1;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + -0x28) + 0x30))(*(int **)(param_1 + -0x28),param_2);
    if ((iVar1 != 0) && (iVar1 < 0)) {
      FUN_40c1aa18(*(int *)(param_1 + -0x28));
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40c1340c FUN_40c1340c */

/* Boundary evidence: original MIPS .pdata 40c1340c..40c1343b. Semantic name remains unreviewed. */

void FUN_40c1340c(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c1343c FUN_40c1343c */

/* Boundary evidence: original MIPS .pdata 40c1343c..40c1346b. Semantic name remains unreviewed. */

void FUN_40c1343c(int param_1)

{
  FUN_40c115ac(param_1 + 0xdc);
  FUN_40c1b9e4(param_1);
  return;
}



/* 40c1346c FUN_40c1346c */

/* Boundary evidence: original MIPS .pdata 40c1346c..40c13493. Semantic name remains unreviewed. */

void FUN_40c1346c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x34))();
  return;
}



/* 40c13494 FUN_40c13494 */

/* Boundary evidence: original MIPS .pdata 40c13494..40c134bb. Semantic name remains unreviewed. */

void FUN_40c13494(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x38))();
  return;
}



/* 40c134bc FUN_40c134bc */

/* Boundary evidence: original MIPS .pdata 40c134bc..40c13547. Semantic name remains unreviewed. */

undefined4 FUN_40c134bc(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1[0x1c];
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  uVar3 = 0;
  bVar1 = FUN_40c115cc(param_1 + 0x37);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    uVar3 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  return uVar3;
}



/* 40c13548 FUN_40c13548 */

/* Boundary evidence: original MIPS .pdata 40c13548..40c13577. Semantic name remains unreviewed. */

void FUN_40c13548(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c13578 FUN_40c13578 */

/* Boundary evidence: original MIPS .pdata 40c13578..40c13603. Semantic name remains unreviewed. */

undefined4 FUN_40c13578(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1[0x1c];
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  uVar3 = 0;
  bVar1 = FUN_40c11698(param_1 + 0x37);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    uVar3 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  return uVar3;
}



/* 40c13604 FUN_40c13604 */

/* Boundary evidence: original MIPS .pdata 40c13604..40c13633. Semantic name remains unreviewed. */

void FUN_40c13604(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c13634 FUN_40c13634 */

/* Boundary evidence: original MIPS .pdata 40c13634..40c136fb. Semantic name remains unreviewed. */

void FUN_40c13634(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  short *psVar4;
  undefined4 local_res4;
  undefined4 local_res8;
  va_list local_resc;
  
  psVar4 = &DAT_40c26394;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf(&DAT_40c26394,param_1,(wchar_t *)&local_res4,param_4);
  psVar3 = &DAT_40c21cf8;
  psVar2 = &DAT_40c26194;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
    *psVar2 = sVar1;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  psVar2 = &DAT_40c26194;
  do {
    psVar3 = psVar2;
    psVar2 = psVar3 + 1;
  } while (*psVar3 != 0);
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
    *psVar3 = sVar1;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  psVar3 = &DAT_40c21cf0;
  psVar2 = &DAT_40c26194;
  do {
    psVar4 = psVar2;
    psVar2 = psVar4 + 1;
  } while (*psVar4 != 0);
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
    *psVar4 = sVar1;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  OutputDebugStringW(&DAT_40c26194);
  return;
}



/* 40c13774 FUN_40c13774 */

/* Boundary evidence: original MIPS .pdata 40c13774..40c137bf. Semantic name remains unreviewed. */

undefined4 * FUN_40c13774(undefined4 *param_1,uint param_2)

{
  FUN_40c11830(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c137dc FUN_40c137dc */

/* Boundary evidence: original MIPS .pdata 40c137dc..40c13807. Semantic name remains unreviewed. */

void FUN_40c137dc(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x1c))();
  return;
}



/* 40c13818 FUN_40c13818 */

/* Boundary evidence: original MIPS .pdata 40c13818..40c1383f. Semantic name remains unreviewed. */

void FUN_40c13818(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 0x4c))();
  return;
}



/* 40c13840 FUN_40c13840 */

/* Boundary evidence: original MIPS .pdata 40c13840..40c1388b. Semantic name remains unreviewed. */

int FUN_40c13840(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(*(int *)(param_1 + 4) + 0x18) != 0) &&
     (piVar2 = *(int **)(*(int *)(param_1 + 4) + 0x98),
     iVar1 = (**(code **)(*piVar2 + 0x1c))(piVar2,param_2,0,0,0), -1 < iVar1)) {
    return iVar1;
  }
  return 1;
}



/* 40c1388c FUN_40c1388c */

/* Boundary evidence: original MIPS .pdata 40c1388c..40c138eb. Semantic name remains unreviewed. */

undefined4 * FUN_40c1388c(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x50);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40c12058(puVar1,param_2);
  }
  return puVar1;
}



/* 40c138ec FUN_40c138ec */

/* Boundary evidence: original MIPS .pdata 40c138ec..40c1391b. Semantic name remains unreviewed. */

void FUN_40c138ec(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40c1391c FUN_40c1391c */

/* Boundary evidence: original MIPS .pdata 40c1391c..40c139c7. Semantic name remains unreviewed. */

void FUN_40c1391c(undefined4 *param_1)

{
  void *pvVar1;
  
  *param_1 = &PTR_FUN_40c21940;
  if ((void *)param_1[6] != (void *)0x0) {
    free((void *)param_1[6]);
    param_1[6] = 0;
  }
  pvVar1 = (void *)param_1[4];
  if (pvVar1 != (void *)0x0) {
    FUN_40c16d08((int)pvVar1);
    operator_delete(pvVar1);
    param_1[4] = 0;
  }
  _eh_vector_destructor_iterator_(param_1 + 2,8,1,FUN_40c11c4c);
  *param_1 = &PTR_FUN_40c218e8;
  return;
}



/* 40c139c8 FUN_40c139c8 */

/* Boundary evidence: original MIPS .pdata 40c139c8..40c139f7. Semantic name remains unreviewed. */

void FUN_40c139c8(void)

{
  undefined4 *in_v0;
  
  FUN_40c11ab0((undefined4 *)*in_v0);
  return;
}



/* 40c139f8 FUN_40c139f8 */

/* Boundary evidence: original MIPS .pdata 40c139f8..40c13a3b. Semantic name remains unreviewed. */

void FUN_40c139f8(void)

{
  int *in_v0;
  
  _eh_vector_destructor_iterator_((void *)(*in_v0 + 8),8,1,FUN_40c11c4c);
  return;
}



/* 40c13a3c FUN_40c13a3c */

/* WARNING: Removing unreachable block (ram,0x40c13a9c) */
/* WARNING: Removing unreachable block (ram,0x40c13aac) */
/* WARNING: Removing unreachable block (ram,0x40c13ab4) */
/* WARNING: Removing unreachable block (ram,0x40c13abc) */
/* Boundary evidence: original MIPS .pdata 40c13a3c..40c13ba7. Semantic name remains unreviewed. */

undefined4 FUN_40c13a3c(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_3,&DAT_40c24cf8,0x10);
  if (iVar1 == 0) {
    FUN_40c12a30(param_1);
    iVar1 = *(int *)(param_1 + 0x24);
    if (-1 < iVar1) {
      *param_2 = *(undefined4 *)(param_1 + 0x20);
      param_2[1] = iVar1;
      if ((0 < *(int *)(param_1 + 0x24)) ||
         ((*(int *)(param_1 + 0x24) == 0 && (*(int *)(param_1 + 0x20) != 0)))) {
        return 0;
      }
    }
  }
  return 0x80040261;
}



/* 40c13ba8 FUN_40c13ba8 */

/* Boundary evidence: original MIPS .pdata 40c13ba8..40c13c43. Semantic name remains unreviewed. */

undefined4 FUN_40c13ba8(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_3,&DAT_40c24cf8,0x10);
  if (((iVar1 == 0) && (*(int *)(param_1 + 8) != 0)) &&
     (iVar1 = (**(code **)**(undefined4 **)(*(int *)(param_1 + 8) + 0xc))(), iVar1 != 0)) {
    *param_2 = 0;
    param_2[1] = 0;
    return 0;
  }
  return 0x80040261;
}



/* 40c13c44 FUN_40c13c44 */

/* Boundary evidence: original MIPS .pdata 40c13c44..40c140cb. Semantic name remains unreviewed. */

uint FUN_40c13c44(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  size_t _Size;
  size_t sVar4;
  va_list pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *local_30;
  void *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar8 = *(int *)(param_1 + 8);
  local_30 = (int *)0x0;
  local_2c = (void *)0x0;
  if ((iVar8 == 0) || (iVar2 = (**(code **)**(undefined4 **)(iVar8 + 0xc))(), iVar2 == 0))
  goto LAB_40c14070;
  uVar3 = (**(code **)(**(int **)(iVar8 + 0xc) + 4))(*(int **)(iVar8 + 0xc),&local_30);
  if (uVar3 != 0) {
    return uVar3;
  }
  if (local_30 == (int *)0x0) {
    return 0;
  }
  uVar3 = (**(code **)(*local_30 + 0xc))(local_30,&local_2c);
  if ((int)uVar3 < 0) {
    FUN_40c13634(0x40c2208c,uVar3,param_3,param_4);
    (**(code **)(*local_30 + 8))();
    return uVar3;
  }
  _Size = (**(code **)(*local_30 + 0x10))();
  iVar2 = *(int *)(param_1 + 0x10);
  if ((*(int *)(iVar2 + 0x20) == 0) || (*(int *)(iVar2 + 0x1c) == 0)) {
LAB_40c13db8:
    param_4 = *(va_list *)(param_1 + 0x34);
    sVar4 = *(size_t *)(param_1 + 0x30);
    uVar3 = (**(code **)(*param_2 + 0x1c))(param_2);
  }
  else {
    iVar6 = *(int *)(iVar2 + 0x14);
    if ((*(int *)(iVar2 + 0x10) != *(int *)(param_1 + 0x30)) ||
       ((iVar6 != *(int *)(param_1 + 0x34) || (*(uint *)(iVar2 + 0x18) < 0x800))))
    goto LAB_40c13db8;
    *(int *)(param_1 + 0x30) = *(int *)(iVar2 + 0x10);
    *(int *)(param_1 + 0x34) = iVar6;
    _Size = *(size_t *)(iVar2 + 0x18);
    sVar4 = _Size;
    memcpy(local_2c,*(void **)(iVar2 + 0x1c),_Size);
    operator_delete(*(void **)(*(int *)(param_1 + 0x10) + 0x1c));
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x1c) = 0;
    iVar2 = *(int *)(param_1 + 0x10);
    *(undefined4 *)(iVar2 + 0x10) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x14) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x18) = 0;
  }
  if ((int)uVar3 < 0) {
    uVar7 = uVar3 & 0xfff;
    if (uVar7 == 0x3ee) {
      FUN_40c13634(0x40c22050,uVar3,sVar4,param_4);
    }
    if (uVar7 == 0x651) {
      FUN_40c13634(0x40c22010,uVar3,sVar4,param_4);
    }
    if (uVar7 == 0x456) {
      FUN_40c13634(0x40c21fd4,uVar3,sVar4,param_4);
    }
    bVar1 = uVar7 == 0x456 || (uVar7 == 0x651 || uVar7 == 0x3ee);
    if (((*(uint *)(*(int *)(param_1 + 0x10) + 0x40) & 1) != 0) && (uVar7 == 0x649)) {
      FUN_40c13634(0x40c21f88,uVar3,sVar4,param_4);
      bVar1 = true;
    }
    if (((*(uint *)(*(int *)(param_1 + 0x10) + 0x40) & 2) != 0) && (uVar7 == 0x1f)) {
      FUN_40c13634(0x40c21f50,uVar3,sVar4,param_4);
      bVar1 = true;
    }
    if ((*(uint *)(*(int *)(param_1 + 0x10) + 0x40) & 4) != 0) {
      FUN_40c13634(0x40c21ef0,uVar3,sVar4,param_4);
    }
    if (bVar1) {
      FUN_40c13634(0x40c21db0,uVar3,sVar4,param_4);
      (**(code **)(*local_30 + 8))();
      return uVar3;
    }
    FUN_40c13634(0x40c21e94,uVar3,*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x3c),
                 *(va_list *)(*(int *)(param_1 + 0x18) + 0x20));
    pcVar5 = *(va_list *)(*(int *)(param_1 + 0x18) + 0x20);
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x3c);
    if (pcVar5 == (va_list)0x0) {
      _Size = iVar2 * 0xa4;
    }
    else {
      _Size = (uint)(iVar2 * (int)pcVar5) / 8000;
    }
    FUN_40c13634(0x40c21dec,_Size,iVar2,pcVar5);
    memset(local_2c,0,_Size);
  }
  else if (uVar3 == 1) {
    uVar7 = _Size + *(int *)(param_1 + 0x30);
    iVar6 = *(int *)(*(int *)(param_1 + 0x18) + 0xc);
    uVar3 = *(uint *)(*(int *)(param_1 + 0x18) + 8);
    iVar2 = *(int *)(param_1 + 0x34) + (uint)(uVar7 < _Size);
    if ((iVar6 <= iVar2) && ((iVar2 != iVar6 || (uVar3 < uVar7)))) {
      _Size = uVar3 - *(int *)(param_1 + 0x30);
    }
  }
  (**(code **)(*local_30 + 0x30))(local_30,_Size);
  uVar3 = _Size + *(int *)(param_1 + 0x30);
  *(uint *)(param_1 + 0x30) = uVar3;
  *(uint *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + (uint)(uVar3 < _Size);
  if (*(int *)(param_1 + 0x28) == 0) {
    local_28 = 0;
    local_24 = 0;
    (**(code **)(*local_30 + 0x18))(local_30,&local_28,0);
    *(undefined4 *)(param_1 + 0x28) = 1;
  }
  (**(code **)(*local_30 + 0x40))(local_30,0);
  uVar3 = (**(code **)(**(int **)(iVar8 + 0xc) + 8))(*(int **)(iVar8 + 0xc),local_30);
  if (uVar3 != 0) {
    return uVar3;
  }
LAB_40c14070:
  uVar3 = 0;
  iVar8 = *(int *)(*(int *)(param_1 + 0x18) + 0xc);
  if ((iVar8 <= *(int *)(param_1 + 0x34)) &&
     ((*(int *)(param_1 + 0x34) != iVar8 ||
      (*(uint *)(*(int *)(param_1 + 0x18) + 8) <= *(uint *)(param_1 + 0x30))))) {
    uVar3 = 2;
  }
  return uVar3;
}



/* 40c140cc FUN_40c140cc */

/* Boundary evidence: original MIPS .pdata 40c140cc..40c141bf. Semantic name remains unreviewed. */

undefined4 FUN_40c140cc(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  va_list pcVar4;
  
  piVar3 = param_3;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x24))(param_1);
  pcVar4 = (va_list)(iVar1 + iVar2);
  if (pcVar4 != (va_list)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
    iVar2 = (**(code **)(*param_1 + 0x24))(param_1);
    if (param_2 < iVar1 + iVar2) {
      if (param_3 != (int *)0x0) {
        iVar1 = *param_3;
        (**(code **)(**(int **)(param_1[2] + 0xc) + 0x10))();
        if (*param_3 == 0) {
          FUN_40c13634(0x40c220f8,iVar1,piVar3,pcVar4);
          return 0x80004005;
        }
      }
      return 0;
    }
  }
  return 1;
}



/* 40c141c0 FUN_40c141c0 */

/* Boundary evidence: original MIPS .pdata 40c141c0..40c1428f. Semantic name remains unreviewed. */

undefined4 FUN_40c141c0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)((param_2 + 1) * 8 + param_1);
  puVar1 = operator_new(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    *(char *)(puVar1 + 1) = (char)param_2;
    puVar3 = puVar1 + 3;
    *puVar1 = &PTR_FUN_40c2193c;
    puVar1[2] = 0;
    *puVar3 = 0;
    puVar1[4] = 0;
    puVar1[4] = *puVar4;
    *puVar4 = puVar1;
    (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 **)(param_1 + 4),param_3,puVar3);
    (**(code **)(*(int *)*puVar3 + 0xc))((int *)*puVar3,param_4);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40c14290 FUN_40c14290 */

/* Boundary evidence: original MIPS .pdata 40c14290..40c14333. Semantic name remains unreviewed. */

undefined4 * FUN_40c14290(undefined4 *param_1,int param_2,undefined4 param_3,wchar_t *param_4)

{
  FUN_40c1d648(param_1,0,param_2,param_2 + 0x6c,param_3,param_4);
  *param_1 = &PTR_FUN_40c2218c;
  param_1[3] = &PTR_FUN_40c22144;
  param_1[4] = &PTR_LAB_40c22130;
  param_1[0x28] = &PTR_LAB_40c21d14;
  param_1[0x29] = param_1;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  FUN_40c1e884(param_1 + 0x2c);
  return param_1;
}



/* 40c14334 FUN_40c14334 */

/* Boundary evidence: original MIPS .pdata 40c14334..40c14363. Semantic name remains unreviewed. */

void FUN_40c14334(void)

{
  int *in_v0;
  
  FUN_40c12750(*in_v0);
  return;
}



/* 40c14364 FUN_40c14364 */

/* Boundary evidence: original MIPS .pdata 40c14364..40c1438b. Semantic name remains unreviewed. */

void FUN_40c14364(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40c1438c FUN_40c1438c */

/* Boundary evidence: original MIPS .pdata 40c1438c..40c143b3. Semantic name remains unreviewed. */

void FUN_40c1438c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40c143b4 FUN_40c143b4 */

/* Boundary evidence: original MIPS .pdata 40c143b4..40c143db. Semantic name remains unreviewed. */

void FUN_40c143b4(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40c143dc FUN_40c143dc */

/* Boundary evidence: original MIPS .pdata 40c143dc..40c143fb. Semantic name remains unreviewed. */

undefined4 FUN_40c143dc(int param_1)

{
  FUN_40c1fab0(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40c143fc FUN_40c143fc */

/* Boundary evidence: original MIPS .pdata 40c143fc..40c1441b. Semantic name remains unreviewed. */

undefined4 FUN_40c143fc(int param_1)

{
  FUN_40c1f1b8(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40c1441c FUN_40c1441c */

/* Boundary evidence: original MIPS .pdata 40c1441c..40c14443. Semantic name remains unreviewed. */

undefined4 FUN_40c1441c(int param_1)

{
  *(undefined4 *)(param_1 + 0xa8) = 1;
  FUN_40c1fb50(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40c14480 FUN_40c14480 */

/* Boundary evidence: original MIPS .pdata 40c14480..40c144db. Semantic name remains unreviewed. */

int FUN_40c14480(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  
  iVar1 = FUN_40c1b538(param_1);
  if (-1 < iVar1) {
    p_Var2 = *(LPCRITICAL_SECTION *)(param_1 + 0xac);
    if (p_Var2 != (LPCRITICAL_SECTION)0x0) {
      FUN_40c1f66c(p_Var2);
      operator_delete(p_Var2);
    }
    *(undefined4 *)(param_1 + 0xac) = 0;
    iVar1 = 0;
  }
  return iVar1;
}



/* 40c144dc FUN_40c144dc */

/* Boundary evidence: original MIPS .pdata 40c144dc..40c14633. Semantic name remains unreviewed. */

DWORD FUN_40c144dc(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  LPCRITICAL_SECTION p_Var3;
  DWORD local_70;
  LPCRITICAL_SECTION local_6c;
  undefined1 auStack_68 [72];
  uint local_20;
  
  uVar1 = DAT_40c2618c;
  local_20 = DAT_40c2618c;
  *(undefined4 *)(param_1 + 0xa8) = 1;
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_40c20494(uVar1);
    DVar2 = 0;
  }
  else {
    DVar2 = FUN_40c1b4f8(param_1);
    if ((int)DVar2 < 0) {
      FUN_40c20494(local_20);
    }
    else {
      local_70 = 0;
      (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))((int *)(param_1 + 0xc),auStack_68);
      FUN_40c1ed14((int)auStack_68);
      local_6c = operator_new(0x54);
      if (local_6c == (LPCRITICAL_SECTION)0x0) {
        p_Var3 = (LPCRITICAL_SECTION)0x0;
      }
      else {
        p_Var3 = FUN_40c1fc80(local_6c,*(undefined4 **)(param_1 + 0x18),&local_70,0,1,1,0,200,3);
      }
      *(LPCRITICAL_SECTION *)(param_1 + 0xac) = p_Var3;
      if (p_Var3 == (LPCRITICAL_SECTION)0x0) {
        FUN_40c20494(local_20);
        DVar2 = 0x8007000e;
      }
      else {
        if ((int)local_70 < 0) {
          FUN_40c1f66c(p_Var3);
          operator_delete(p_Var3);
          *(undefined4 *)(param_1 + 0xac) = 0;
        }
        DVar2 = local_70;
        FUN_40c20494(local_20);
      }
    }
  }
  return DVar2;
}



/* 40c14634 FUN_40c14634 */

/* Boundary evidence: original MIPS .pdata 40c14634..40c14663. Semantic name remains unreviewed. */

void FUN_40c14634(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x6c));
  return;
}



/* 40c14664 FUN_40c14664 */

/* Boundary evidence: original MIPS .pdata 40c14664..40c14727. Semantic name remains unreviewed. */

void FUN_40c14664(undefined4 *param_1)

{
  void *pvVar1;
  
  *param_1 = &PTR_FUN_40c2218c;
  param_1[3] = &PTR_FUN_40c22144;
  param_1[4] = &PTR_LAB_40c22130;
  if (param_1[0x2e] != 0) {
    do {
      pvVar1 = (void *)FUN_40c1eb68(param_1 + 0x2c);
      if (pvVar1 != (void *)0x0) {
        FUN_40c1ed78((int)pvVar1);
        operator_delete(pvVar1);
      }
    } while (param_1[0x2e] != 0);
  }
  FUN_40c1eb20(param_1 + 0x2c);
  FUN_40c1ade0((int)param_1);
  return;
}



/* 40c14728 FUN_40c14728 */

/* Boundary evidence: original MIPS .pdata 40c14728..40c14757. Semantic name remains unreviewed. */

void FUN_40c14728(void)

{
  int *in_v0;
  
  FUN_40c12750(*in_v0);
  return;
}



/* 40c14758 FUN_40c14758 */

/* Boundary evidence: original MIPS .pdata 40c14758..40c1478b. Semantic name remains unreviewed. */

void FUN_40c14758(void)

{
  int *in_v0;
  
  FUN_40c1276c((undefined4 *)(*in_v0 + 0xb0));
  return;
}



/* 40c1478c FUN_40c1478c */

/* Boundary evidence: original MIPS .pdata 40c1478c..40c1480b. Semantic name remains unreviewed. */

undefined4 FUN_40c1478c(int param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  int local_18 [2];
  
  local_18[0] = *(int *)(param_1 + 0xb0);
  do {
    if (local_18[0] == 0) {
      return 1;
    }
    pvVar1 = (void *)FUN_40c1e8fc((int *)(param_1 + 0xb0),local_18);
    iVar2 = FUN_40c1eee4(pvVar1,param_2);
  } while (iVar2 == 0);
  return 0;
}



/* 40c1480c FUN_40c1480c */

/* Boundary evidence: original MIPS .pdata 40c1480c..40c1488f. Semantic name remains unreviewed. */

undefined4 FUN_40c1480c(int param_1,int param_2,void *param_3)

{
  bool bVar1;
  void *pvVar2;
  int local_18 [2];
  
  local_18[0] = *(int *)(param_1 + 0xb0);
  do {
    if (local_18[0] == 0) {
      return 0x40103;
    }
    pvVar2 = (void *)FUN_40c1e8fc((int *)(param_1 + 0xb0),local_18);
    bVar1 = param_2 != 0;
    param_2 = param_2 + -1;
  } while (bVar1);
  FUN_40c1eeb8(param_3,pvVar2);
  return 0;
}



/* 40c14890 FUN_40c14890 */

/* Boundary evidence: original MIPS .pdata 40c14890..40c1493b. Semantic name remains unreviewed. */

undefined4 FUN_40c14890(int param_1,void *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  pvVar1 = operator_new(0x48);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = FUN_40c1ee40(pvVar1,param_2);
  }
  if (pvVar1 != (void *)0x0) {
    puVar2 = FUN_40c1ea24((undefined4 *)(param_1 + 0xb0),pvVar1);
    if (puVar2 != (undefined4 *)0x0) {
      return 0;
    }
    FUN_40c1ed78((int)pvVar1);
    operator_delete(pvVar1);
  }
  return 0x8007000e;
}



/* 40c1493c FUN_40c1493c */

/* Boundary evidence: original MIPS .pdata 40c1493c..40c1496b. Semantic name remains unreviewed. */

void FUN_40c1493c(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40c1496c FUN_40c1496c */

/* Boundary evidence: original MIPS .pdata 40c1496c..40c14a1f. Semantic name remains unreviewed. */

undefined4 FUN_40c1496c(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_40c13634(0x40c22310,*param_2,param_3,param_4);
    (**(code **)(*param_2 + 8))(param_2);
    return 1;
  }
  iVar1 = (**(code **)(*param_2 + 0x3c))(param_2);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0xa8) != 0)) {
    *(undefined4 *)(param_1 + 0xa8) = 0;
    (**(code **)(*param_2 + 0x40))(param_2,1);
  }
  uVar2 = FUN_40c1fc04(*(LPCRITICAL_SECTION *)(param_1 + 0xac),param_2);
  return uVar2;
}



/* 40c14a20 FUN_40c14a20 */

/* Boundary evidence: original MIPS .pdata 40c14a20..40c14a9b. Semantic name remains unreviewed. */

void FUN_40c14a20(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x98) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x18))();
    if (iVar1 < 0) {
      return;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 8))();
    if (iVar1 != 0) {
      FUN_40c13634(0x40c2234c,iVar1,param_3,param_4);
    }
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  FUN_40c1b244(param_1);
  return;
}



/* 40c14a9c FUN_40c14a9c */

/* Boundary evidence: original MIPS .pdata 40c14a9c..40c14bb3. Semantic name remains unreviewed. */

undefined4 *
FUN_40c14a9c(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  FUN_40c1d0a8(param_1,param_2,param_3,(LPCRITICAL_SECTION)(param_1 + 0x1b),param_4);
  *param_1 = &PTR_FUN_40c22438;
  param_1[3] = &PTR_FUN_40c223fc;
  param_1[4] = &PTR_LAB_40c223e8;
  param_1[0x14] = 0;
  FUN_40c1e884(param_1 + 0x15);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1b));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2a));
  param_1[0x2f] = 0;
  param_1[0x30] = 0x7b785574;
  param_1[0x31] = 0x11cf8c82;
  param_1[0x32] = 0xaa000cbc;
  param_1[0x33] = 0xf674ac00;
  param_1[0x34] = &PTR_FUN_40c21d10;
  param_1[0x35] = param_1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 1;
  return param_1;
}



/* 40c14bb4 FUN_40c14bb4 */

/* Boundary evidence: original MIPS .pdata 40c14bb4..40c14be3. Semantic name remains unreviewed. */

void FUN_40c14bb4(void)

{
  int *in_v0;
  
  FUN_40c1bdb0(*in_v0);
  return;
}



/* 40c14be4 FUN_40c14be4 */

/* Boundary evidence: original MIPS .pdata 40c14be4..40c14c0b. Semantic name remains unreviewed. */

void FUN_40c14be4(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40c14c0c FUN_40c14c0c */

/* Boundary evidence: original MIPS .pdata 40c14c0c..40c14c33. Semantic name remains unreviewed. */

void FUN_40c14c0c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40c14c34 FUN_40c14c34 */

/* Boundary evidence: original MIPS .pdata 40c14c34..40c14c5b. Semantic name remains unreviewed. */

void FUN_40c14c34(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40c14c98 FUN_40c14c98 */

/* Boundary evidence: original MIPS .pdata 40c14c98..40c14d97. Semantic name remains unreviewed. */

undefined4 FUN_40c14c98(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  int local_28;
  LPCRITICAL_SECTION local_24;
  LPCRITICAL_SECTION local_20;
  
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0x60);
  local_24 = lpCriticalSection_00;
  EnterCriticalSection(lpCriticalSection_00);
  if (*(int *)(param_1 + 8) == 0) {
    local_28 = *(int *)(param_1 + 0x48);
    while (local_28 != 0) {
      piVar1 = (int *)FUN_40c1e8fc((int *)(param_1 + 0x48),&local_28);
      if (piVar1[6] != 0) {
        (**(code **)(*piVar1 + 0x14))(piVar1);
      }
    }
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x74);
    local_20 = lpCriticalSection;
    EnterCriticalSection(lpCriticalSection);
    if ((*(int **)(param_1 + 0x44))[6] != 0) {
      (**(code **)(**(int **)(param_1 + 0x44) + 0x14))();
    }
    *(undefined4 *)(param_1 + 8) = 1;
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    *(undefined4 *)(param_1 + 8) = 1;
  }
  LeaveCriticalSection(lpCriticalSection_00);
  return 0;
}



/* 40c14d98 FUN_40c14d98 */

/* Boundary evidence: original MIPS .pdata 40c14d98..40c14dc7. Semantic name remains unreviewed. */

void FUN_40c14d98(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40c14dc8 FUN_40c14dc8 */

/* Boundary evidence: original MIPS .pdata 40c14dc8..40c14df7. Semantic name remains unreviewed. */

void FUN_40c14dc8(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c14df8 FUN_40c14df8 */

/* Boundary evidence: original MIPS .pdata 40c14df8..40c14ef7. Semantic name remains unreviewed. */

undefined4 FUN_40c14df8(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  int local_28;
  LPCRITICAL_SECTION local_24;
  LPCRITICAL_SECTION local_20;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x60);
  local_24 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) == 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (*(int **)(param_1 + 0x44) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x44) + 0x18))();
    }
    lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0x74);
    local_20 = lpCriticalSection_00;
    EnterCriticalSection(lpCriticalSection_00);
    local_28 = *(int *)(param_1 + 0x48);
    while (local_28 != 0) {
      piVar1 = (int *)FUN_40c1e8fc((int *)(param_1 + 0x48),&local_28);
      if (piVar1[6] != 0) {
        (**(code **)(*piVar1 + 0x18))(piVar1);
      }
    }
    *(undefined4 *)(param_1 + 8) = 0;
    LeaveCriticalSection(lpCriticalSection_00);
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* 40c14ef8 FUN_40c14ef8 */

/* Boundary evidence: original MIPS .pdata 40c14ef8..40c14f27. Semantic name remains unreviewed. */

void FUN_40c14ef8(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40c14f28 FUN_40c14f28 */

/* Boundary evidence: original MIPS .pdata 40c14f28..40c14f57. Semantic name remains unreviewed. */

void FUN_40c14f28(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c14f58 FUN_40c14f58 */

/* Boundary evidence: original MIPS .pdata 40c14f58..40c14fb3. Semantic name remains unreviewed. */

int FUN_40c14f58(int param_1)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa8));
  iVar1 = *(int *)(param_1 + 0x50);
  iVar2 = *(int *)(param_1 + 0x5c);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa8));
  return (uint)(iVar1 != 0) + iVar2;
}



/* 40c14fb4 FUN_40c14fb4 */

/* Boundary evidence: original MIPS .pdata 40c14fb4..40c150b3. Semantic name remains unreviewed. */

int FUN_40c14fb4(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int local_20;
  LPCRITICAL_SECTION local_1c;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa8);
  local_1c = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  if ((param_2 == 0) && (iVar2 = *(int *)(param_1 + 0x50), iVar2 != 0)) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (*(int *)(param_1 + 0x50) != 0) {
      param_2 = param_2 + -1;
    }
    if ((param_2 < 0) || (*(int *)(param_1 + 0x5c) <= param_2)) {
      LeaveCriticalSection(lpCriticalSection);
      iVar2 = 0;
    }
    else {
      piVar1 = (int *)(param_1 + 0x54);
      local_20 = *piVar1;
      for (; 0 < param_2; param_2 = param_2 + -1) {
        FUN_40c1e8fc(piVar1,&local_20);
      }
      iVar2 = FUN_40c1e8fc(piVar1,&local_20);
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar2;
}



/* 40c150b4 FUN_40c150b4 */

/* Boundary evidence: original MIPS .pdata 40c150b4..40c150e3. Semantic name remains unreviewed. */

void FUN_40c150b4(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40c150e4 FUN_40c150e4 */

/* Boundary evidence: original MIPS .pdata 40c150e4..40c151c3. Semantic name remains unreviewed. */

bool FUN_40c150e4(int param_1,int *param_2)

{
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x6c);
  EnterCriticalSection(lpCriticalSection);
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0xa8);
  EnterCriticalSection(lpCriticalSection_00);
  FUN_40c1aa60(param_1);
  (**(code **)(param_2[3] + 4))();
  puVar1 = FUN_40c1ea24((undefined4 *)(param_1 + 0x54),param_2);
  if (puVar1 != (undefined4 *)0x0) {
    LeaveCriticalSection(lpCriticalSection_00);
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    (**(code **)(*param_2 + 0xc))(param_2,1);
    LeaveCriticalSection(lpCriticalSection_00);
    LeaveCriticalSection(lpCriticalSection);
  }
  return puVar1 != (undefined4 *)0x0;
}



/* 40c151c4 FUN_40c151c4 */

/* Boundary evidence: original MIPS .pdata 40c151c4..40c151f3. Semantic name remains unreviewed. */

void FUN_40c151c4(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c151f4 FUN_40c151f4 */

/* Boundary evidence: original MIPS .pdata 40c151f4..40c15223. Semantic name remains unreviewed. */

void FUN_40c151f4(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40c15224 FUN_40c15224 */

/* Boundary evidence: original MIPS .pdata 40c15224..40c1531f. Semantic name remains unreviewed. */

void FUN_40c15224(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa8));
  iVar1 = FUN_40c1eb68((int *)(param_1 + 0x54));
  while (iVar1 != 0) {
    FUN_40c1aa60(param_1);
    if (*(int **)(iVar1 + 0x18) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x18) + 0x14))();
      (**(code **)(*(int *)(iVar1 + 0xc) + 0x14))();
    }
    (**(code **)(*(int *)(iVar1 + 0xc) + 8))();
    iVar1 = FUN_40c1eb68((int *)(param_1 + 0x54));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa8));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return;
}



/* 40c15320 FUN_40c15320 */

/* Boundary evidence: original MIPS .pdata 40c15320..40c1534f. Semantic name remains unreviewed. */

void FUN_40c15320(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40c15350 FUN_40c15350 */

/* Boundary evidence: original MIPS .pdata 40c15350..40c1537f. Semantic name remains unreviewed. */

void FUN_40c15350(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40c15380 FUN_40c15380 */

/* Boundary evidence: original MIPS .pdata 40c15380..40c15497. Semantic name remains unreviewed. */

int FUN_40c15380(int param_1,wchar_t *param_2,int *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int local_20;
  undefined4 *local_1c;
  
  local_20 = 0;
  local_1c = operator_new(200);
  if (local_1c == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_40c14290(local_1c,param_1,&local_20,param_2);
  }
  if (local_20 < 0) {
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,1);
    }
  }
  else if (piVar2 == (int *)0x0) {
    local_20 = -0x7ff8fff2;
  }
  else {
    bVar1 = FUN_40c150e4(param_1,piVar2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,1);
      local_20 = -0x7ff8fff2;
    }
    else {
      *param_3 = (int)(piVar2 + 0x28);
      local_20 = 0;
    }
  }
  return local_20;
}



/* 40c15498 FUN_40c15498 */

/* Boundary evidence: original MIPS .pdata 40c15498..40c154c7. Semantic name remains unreviewed. */

void FUN_40c15498(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x1c));
  return;
}



/* 40c154c8 FUN_40c154c8 */

/* Boundary evidence: original MIPS .pdata 40c154c8..40c1567b. Semantic name remains unreviewed. */

int FUN_40c154c8(int *param_1,undefined4 param_2,int *param_3,va_list param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x25);
  EnterCriticalSection(lpCriticalSection);
  if ((int *)param_1[0x3c] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x3c] + 8))();
    param_1[0x3c] = 0;
  }
  iVar3 = param_1[0x14];
  piVar4 = *(int **)(iVar3 + 0x11c);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))();
  }
  pcVar5 = *(code **)(*param_1 + 0x3c);
  param_1[0x3c] = *(int *)(iVar3 + 0x11c);
  piVar4 = (int *)(*pcVar5)(param_1,param_1 + 0x34);
  param_1[0x2f] = (int)piVar4;
  if (piVar4 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar3 = -0x7ff8fff2;
  }
  else {
    piVar2 = (int *)param_1[0x3c];
    iVar3 = (**(code **)(*piVar4 + 4))(piVar4);
    if (-1 < iVar3) {
      param_3 = param_1 + 0x30;
      piVar2 = param_1 + 0x40;
      (**(code **)(*(int *)param_1[0x2f] + 0x14))();
    }
    if (param_1[0x3b] != 0) {
      FUN_40c13634(0x40c22660,piVar2,param_3,param_4);
      piVar4 = (int *)param_1[0x3b];
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0xc))(piVar4,1);
      }
      param_1[0x3b] = 0;
    }
    if (param_1[0x3b] == 0) {
      puVar1 = operator_new(0x50);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = FUN_40c19bfc(puVar1,param_1,(undefined4 *)param_1[1]);
      }
      param_1[0x3b] = (int)puVar1;
    }
    if (-1 < iVar3) {
      *(int *)(param_1[0x14] + 0xd8) = param_1[0x2f];
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar3;
}



/* 40c1567c FUN_40c1567c */

/* Boundary evidence: original MIPS .pdata 40c1567c..40c156ab. Semantic name remains unreviewed. */

void FUN_40c1567c(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40c156ac FUN_40c156ac */

/* Boundary evidence: original MIPS .pdata 40c156ac..40c156db. Semantic name remains unreviewed. */

void FUN_40c156ac(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x20));
  return;
}



/* 40c156dc FUN_40c156dc */

/* Boundary evidence: original MIPS .pdata 40c156dc..40c156f7. Semantic name remains unreviewed. */

void FUN_40c156dc(int *param_1,undefined4 param_2)

{
  FUN_40c12a94(param_1,param_2);
  return;
}



/* 40c156f8 FUN_40c156f8 */

/* Boundary evidence: original MIPS .pdata 40c156f8..40c15757. Semantic name remains unreviewed. */

void FUN_40c156f8(int param_1)

{
  int *piVar1;
  int local_10 [2];
  
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40c1e8fc((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x4c))(piVar1);
    }
  }
  return;
}



/* 40c15758 FUN_40c15758 */

/* Boundary evidence: original MIPS .pdata 40c15758..40c157bb. Semantic name remains unreviewed. */

undefined4 FUN_40c15758(int param_1)

{
  int *piVar1;
  int local_10 [2];
  
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40c1e8fc((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x50))(piVar1);
    }
  }
  return 0;
}



/* 40c157bc FUN_40c157bc */

/* Boundary evidence: original MIPS .pdata 40c157bc..40c1581f. Semantic name remains unreviewed. */

undefined4 FUN_40c157bc(int param_1)

{
  int *piVar1;
  int local_10 [2];
  
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40c1e8fc((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x54))(piVar1);
    }
  }
  return 0;
}



/* 40c15820 FUN_40c15820 */

/* Boundary evidence: original MIPS .pdata 40c15820..40c158c3. Semantic name remains unreviewed. */

void FUN_40c15820(int param_1)

{
  undefined4 *puVar1;
  
  if (DAT_40c26598 != (int *)0x0) {
    (**(code **)(*DAT_40c26598 + 8))();
    DAT_40c26598 = (int *)0x0;
    DAT_40c2659c = 0;
  }
  puVar1 = *(undefined4 **)(param_1 + 0xbc);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    *(undefined4 *)(param_1 + 0xbc) = 0;
  }
  FUN_40c15224(param_1);
  if (*(int **)(param_1 + 0xf0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xf0) + 8))();
    *(undefined4 *)(param_1 + 0xf0) = 0;
  }
  return;
}



/* 40c158c4 FUN_40c158c4 */

/* Boundary evidence: original MIPS .pdata 40c158c4..40c15a37. Semantic name remains unreviewed. */

undefined4 FUN_40c158c4(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int local_28;
  LPCRITICAL_SECTION local_24;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x94);
  local_24 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  iVar3 = *(int *)(param_1 + 0x50);
  piVar4 = *(int **)(iVar3 + 0x11c);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))();
  }
  local_28 = *(int *)(param_1 + 0x54);
  piVar4 = *(int **)(iVar3 + 0x11c);
  while (local_28 != 0) {
    piVar1 = (int *)FUN_40c1e8fc((int *)(param_1 + 0x54),&local_28);
    if (piVar1[6] != 0) {
      iVar3 = *piVar1;
      __litodp(*(undefined4 *)(param_1 + 0x108));
      (**(code **)(iVar3 + 0x58))(piVar1);
    }
  }
  (**(code **)(**(int **)(param_1 + 0xbc) + 0x1c))
            (*(int **)(param_1 + 0xbc),piVar4,*(undefined4 *)(param_1 + 0xf8),
             *(undefined4 *)(param_1 + 0xfc),*(undefined4 *)(param_1 + 0x100),
             *(undefined4 *)(param_1 + 0x104));
  piVar1 = *(int **)(param_1 + 0xbc);
  iVar3 = *piVar1;
  __litodp(*(undefined4 *)(param_1 + 0x108));
  uVar2 = (**(code **)(iVar3 + 0x20))(piVar1);
  (**(code **)(*piVar4 + 8))(piVar4);
  LeaveCriticalSection(lpCriticalSection);
  return uVar2;
}



/* 40c15a38 FUN_40c15a38 */

/* Boundary evidence: original MIPS .pdata 40c15a38..40c15a67. Semantic name remains unreviewed. */

void FUN_40c15a38(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40c15a68 FUN_40c15a68 */

/* Boundary evidence: original MIPS .pdata 40c15a68..40c15af7. Semantic name remains unreviewed. */

undefined4
FUN_40c15a68(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd8));
  *(undefined4 *)(param_1 + 0xf8) = param_3;
  *(undefined4 *)(param_1 + 0xfc) = param_4;
  *(undefined4 *)(param_1 + 0x100) = param_5;
  *(undefined4 *)(param_1 + 0x104) = param_6;
  FUN_40c134bc(*(int **)(param_1 + 0x50));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd8));
  return 0;
}



/* 40c15af8 FUN_40c15af8 */

/* Boundary evidence: original MIPS .pdata 40c15af8..40c15b27. Semantic name remains unreviewed. */

void FUN_40c15af8(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40c15b28 FUN_40c15b28 */

/* Boundary evidence: original MIPS .pdata 40c15b28..40c15bbf. Semantic name remains unreviewed. */

undefined4 FUN_40c15b28(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd8));
  piVar2 = *(int **)(param_1 + 0x50);
  uVar1 = __dptoli(param_3,param_4);
  *(undefined4 *)(param_1 + 0x108) = uVar1;
  FUN_40c13578(piVar2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd8));
  return 0;
}



/* 40c15bc0 FUN_40c15bc0 */

/* Boundary evidence: original MIPS .pdata 40c15bc0..40c15bef. Semantic name remains unreviewed. */

void FUN_40c15bc0(void)

{
  int in_v0;
  
  FUN_40c11000((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40c15bf0 FUN_40c15bf0 */

/* Boundary evidence: original MIPS .pdata 40c15bf0..40c15c3b. Semantic name remains unreviewed. */

void * FUN_40c15bf0(void *param_1,uint param_2)

{
  FUN_40c12fe0((int)param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c15c3c FUN_40c15c3c */

/* Boundary evidence: original MIPS .pdata 40c15c3c..40c15cc3. Semantic name remains unreviewed. */

int FUN_40c15c3c(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  iVar1 = FUN_40c1b120();
  if (iVar1 < 0) {
    FUN_40c13634(0x40c227d8,param_2,param_3,param_4);
  }
  else {
    iVar1 = FUN_40c158c4(*(int *)(param_1 + 0x70));
    if (iVar1 < 0) {
      FUN_40c13634(0x40c2282c,iVar1,param_3,param_4);
    }
    else {
      FUN_40c11590((LPVOID)(param_1 + 0xdc));
    }
  }
  return iVar1;
}



/* 40c15cc4 FUN_40c15cc4 */

/* Boundary evidence: original MIPS .pdata 40c15cc4..40c15cdf. Semantic name remains unreviewed. */

void FUN_40c15cc4(int param_1,wchar_t *param_2,int *param_3)

{
  FUN_40c15380(*(int *)(param_1 + 4),param_2,param_3);
  return;
}



/* 40c15ce0 FUN_40c15ce0 */

/* Boundary evidence: original MIPS .pdata 40c15ce0..40c15cfb. Semantic name remains unreviewed. */

void FUN_40c15ce0(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  FUN_40c1496c(*(int *)(param_1 + 4),param_2,param_3,param_4);
  return;
}



/* 40c15cfc FUN_40c15cfc */

/* Boundary evidence: original MIPS .pdata 40c15cfc..40c15d17. Semantic name remains unreviewed. */

void FUN_40c15cfc(int param_1,void *param_2)

{
  FUN_40c14890(*(int *)(param_1 + 4),param_2);
  return;
}



/* 40c15d18 FUN_40c15d18 */

/* Boundary evidence: original MIPS .pdata 40c15d18..40c15d63. Semantic name remains unreviewed. */

undefined4 * FUN_40c15d18(undefined4 *param_1,uint param_2)

{
  FUN_40c1391c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c15d64 FUN_40c15d64 */

/* Boundary evidence: original MIPS .pdata 40c15d64..40c15ea7. Semantic name remains unreviewed. */

int FUN_40c15d64(int param_1)

{
  int iVar1;
  LPVOID _Dst;
  undefined4 auStack_60 [4];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_18;
  
  local_18 = DAT_40c2618c;
  FUN_40c1edd4(auStack_60,(undefined4 *)&DAT_40c23b48);
  iVar1 = memcmp(*(void **)(*(int *)(param_1 + 0x18) + 4),&DAT_40c24a88,0x10);
  if (iVar1 == 0) {
    local_50 = 0xe06d802b;
    local_4c = 0x11cfdb46;
    local_48 = 0x8000d1b4;
    local_44 = 0xeabb6c5f;
    FUN_40c1eb84((int)auStack_60,&DAT_40c24708);
    FUN_40c1ef90((int)auStack_60,*(int *)(*(int *)(param_1 + 0x18) + 0x28));
    _Dst = FUN_40c1eba8((int)auStack_60,*(uint *)(*(int *)(param_1 + 0x18) + 0x40));
    memcpy(_Dst,*(void **)(*(int *)(param_1 + 0x18) + 0x44),
           *(size_t *)(*(int *)(param_1 + 0x18) + 0x40));
    iVar1 = FUN_40c141c0(param_1,0,L"Audio",auStack_60);
    if (-1 < iVar1) {
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    }
    FUN_40c1ed78((int)auStack_60);
    FUN_40c20494(local_18);
  }
  else {
    FUN_40c1ed78((int)auStack_60);
    FUN_40c20494(local_18);
    iVar1 = -0x7fffbffb;
  }
  return iVar1;
}



/* 40c15ea8 FUN_40c15ea8 */

/* Boundary evidence: original MIPS .pdata 40c15ea8..40c15ed7. Semantic name remains unreviewed. */

void FUN_40c15ea8(void)

{
  int in_v0;
  
  FUN_40c1ed78(in_v0 + -0x60);
  return;
}



/* 40c15ed8 FUN_40c15ed8 */

/* Boundary evidence: original MIPS .pdata 40c15ed8..40c15f23. Semantic name remains unreviewed. */

undefined4 * FUN_40c15ed8(undefined4 *param_1,uint param_2)

{
  FUN_40c14664(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c15f24 FUN_40c15f24 */

/* Boundary evidence: original MIPS .pdata 40c15f24..40c15fe7. Semantic name remains unreviewed. */

void FUN_40c15f24(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40c22438;
  param_1[3] = &PTR_FUN_40c223fc;
  param_1[4] = &PTR_LAB_40c223e8;
  piVar1 = (int *)param_1[0x14];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
  }
  param_1[0x14] = 0;
  FUN_40c15224((int)param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2a));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1b));
  FUN_40c1eb20(param_1 + 0x15);
  FUN_40c1bdb0((int)param_1);
  return;
}



/* 40c15fe8 FUN_40c15fe8 */

/* Boundary evidence: original MIPS .pdata 40c15fe8..40c16017. Semantic name remains unreviewed. */

void FUN_40c15fe8(void)

{
  int *in_v0;
  
  FUN_40c1bdb0(*in_v0);
  return;
}



/* 40c16018 FUN_40c16018 */

/* Boundary evidence: original MIPS .pdata 40c16018..40c1604b. Semantic name remains unreviewed. */

void FUN_40c16018(void)

{
  int *in_v0;
  
  FUN_40c12880((undefined4 *)(*in_v0 + 0x54));
  return;
}



/* 40c1604c FUN_40c1604c */

/* Boundary evidence: original MIPS .pdata 40c1604c..40c1607f. Semantic name remains unreviewed. */

void FUN_40c1604c(void)

{
  int *in_v0;
  
  FUN_40c11a94((LPCRITICAL_SECTION)(*in_v0 + 0x6c));
  return;
}



/* 40c16080 FUN_40c16080 */

/* Boundary evidence: original MIPS .pdata 40c16080..40c160b3. Semantic name remains unreviewed. */

void FUN_40c16080(void)

{
  int *in_v0;
  
  FUN_40c11a94((LPCRITICAL_SECTION)(*in_v0 + 0x80));
  return;
}



/* 40c160b4 FUN_40c160b4 */

/* Boundary evidence: original MIPS .pdata 40c160b4..40c160e7. Semantic name remains unreviewed. */

void FUN_40c160b4(void)

{
  int *in_v0;
  
  FUN_40c11a94((LPCRITICAL_SECTION)(*in_v0 + 0x94));
  return;
}



/* 40c160e8 FUN_40c160e8 */

/* Boundary evidence: original MIPS .pdata 40c160e8..40c1611b. Semantic name remains unreviewed. */

void FUN_40c160e8(void)

{
  int *in_v0;
  
  FUN_40c11a94((LPCRITICAL_SECTION)(*in_v0 + 0xa8));
  return;
}



/* 40c1611c FUN_40c1611c */

/* Boundary evidence: original MIPS .pdata 40c1611c..40c1614f. Semantic name remains unreviewed. */

void FUN_40c1611c(void)

{
  int *in_v0;
  
  FUN_40c11a94((LPCRITICAL_SECTION)(*in_v0 + 0xd8));
  return;
}



/* 40c16150 FUN_40c16150 */

/* Boundary evidence: original MIPS .pdata 40c16150..40c1622b. Semantic name remains unreviewed. */

undefined4 * FUN_40c16150(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  wchar_t *pwVar2;
  va_list pcVar3;
  
  pcVar3 = (va_list)&DAT_40c21418;
  pwVar2 = L"CMP3DemuxFilter";
  FUN_40c14a9c(param_1,L"CMP3DemuxFilter",param_2,&DAT_40c21418);
  *param_1 = &PTR_FUN_40c229f8;
  param_1[3] = &PTR_FUN_40c229bc;
  param_1[4] = &PTR_LAB_40c229a8;
  param_1[0x44] = &PTR_LAB_40c22990;
  FUN_40c13634(0x40c22968,pwVar2,param_2,pcVar3);
  puVar1 = operator_new(0x130);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40c12e10(puVar1,(int)param_1,param_3);
  }
  param_1[0x14] = puVar1;
  return param_1;
}



/* 40c1622c FUN_40c1622c */

/* Boundary evidence: original MIPS .pdata 40c1622c..40c1625b. Semantic name remains unreviewed. */

void FUN_40c1622c(void)

{
  undefined4 *in_v0;
  
  FUN_40c15f24((undefined4 *)*in_v0);
  return;
}



/* 40c1625c FUN_40c1625c */

/* Boundary evidence: original MIPS .pdata 40c1625c..40c1628b. Semantic name remains unreviewed. */

void FUN_40c1625c(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40c1628c FUN_40c1628c */

/* Boundary evidence: original MIPS .pdata 40c1628c..40c162b3. Semantic name remains unreviewed. */

void FUN_40c1628c(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40c162b4 FUN_40c162b4 */

/* Boundary evidence: original MIPS .pdata 40c162b4..40c162db. Semantic name remains unreviewed. */

void FUN_40c162b4(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40c162dc FUN_40c162dc */

/* Boundary evidence: original MIPS .pdata 40c162dc..40c16303. Semantic name remains unreviewed. */

void FUN_40c162dc(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40c1637c FUN_40c1637c */

/* Boundary evidence: original MIPS .pdata 40c1637c..40c1647f. Semantic name remains unreviewed. */

void FUN_40c1637c(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_40c229f8;
  param_1[3] = &PTR_FUN_40c229bc;
  param_1[4] = &PTR_LAB_40c229a8;
  param_1[0x44] = &PTR_LAB_40c22990;
  puVar1 = (undefined4 *)param_1[0x2f];
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    param_1[0x2f] = 0;
  }
  piVar2 = (int *)param_1[0x14];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2,1);
    param_1[0x14] = 0;
  }
  piVar2 = (int *)param_1[0x3b];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2,1);
    param_1[0x3b] = 0;
  }
  if (DAT_40c26594 != 0) {
    CloseHandle((HANDLE)DAT_40c26594);
    DAT_40c26594 = 0;
  }
  FUN_40c15f24(param_1);
  return;
}



/* 40c16480 FUN_40c16480 */

/* Boundary evidence: original MIPS .pdata 40c16480..40c164af. Semantic name remains unreviewed. */

void FUN_40c16480(void)

{
  undefined4 *in_v0;
  
  FUN_40c15f24((undefined4 *)*in_v0);
  return;
}



/* 40c164b0 FUN_40c164b0 */

/* Boundary evidence: original MIPS .pdata 40c164b0..40c16a2b. Semantic name remains unreviewed. */

int FUN_40c164b0(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  longlong lVar5;
  undefined4 *puVar6;
  uint uVar7;
  void *pvVar8;
  uint **ppuVar9;
  uint *puVar10;
  int iVar11;
  uint *local_c0;
  int local_bc;
  uint *local_b8;
  undefined4 *local_b4;
  char local_b0 [128];
  uint local_30;
  
  local_30 = DAT_40c2618c;
  iVar11 = 0;
  local_bc = 0;
  local_b8 = (uint *)0x0;
  local_b4 = operator_new(0x70);
  if (local_b4 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6 = FUN_40c16c58(local_b4,param_2,&local_bc);
  }
  *(undefined4 **)(param_1 + 0x10) = puVar6;
  FUN_40c17838((int)puVar6);
  puVar10 = (uint *)0x100;
  ppuVar9 = &local_c0;
  uVar7 = FUN_40c17564(*(uint **)(param_1 + 0x10),ppuVar9,0x100);
  if ((local_c0 == (uint *)0x0) && (uVar7 == 0)) {
    FUN_40c13634(0x40c22b4c,ppuVar9,puVar10,param_4);
  }
  else {
    puVar6 = *(undefined4 **)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x14) = 0;
    *puVar6 = 0;
    puVar6[1] = 0;
    if (((char)*local_c0 != 'I') ||
       ((*(char *)((int)local_c0 + 1) != 'D' || (*(char *)((int)local_c0 + 2) != '3')))) {
      local_bc = 0;
      if (((char)*local_c0 == -1) && ((*local_c0 & 0xf000) == 0xf000)) {
        iVar11 = 1;
      }
      local_bc = FUN_40c12148((char *)local_c0);
      puVar6 = *(undefined4 **)(param_1 + 0x10);
      *puVar6 = 0;
      puVar6[1] = 0;
      if (-1 < local_bc) {
        operator_delete(local_c0);
        param_4 = (va_list)FUN_40c17564(*(uint **)(param_1 + 0x10),&local_c0,0x10000);
        ppuVar9 = &local_b8;
        puVar10 = local_c0;
        local_bc = FUN_40c18980(*(uint **)(param_1 + 0x10),ppuVar9,local_c0,param_4,
                                *(va_list *)(param_1 + 0x14),iVar11);
        iVar11 = *(int *)(param_1 + 0x10);
        *(undefined4 *)(iVar11 + 0x10) = 0;
        *(undefined4 *)(iVar11 + 0x14) = 0;
      }
LAB_40c1684c:
      if (*(int *)(*(int *)(param_1 + 0x10) + 8) == 0) {
        operator_delete(local_c0);
        iVar11 = *(int *)(param_1 + 0x10);
        *(undefined4 *)(iVar11 + 0x10) = 0xffffffff;
        *(undefined4 *)(iVar11 + 0x14) = 0xffffffff;
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x18) = 0xffffffff;
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x1c) = 0;
        if ((-1 < local_bc) && (local_b8 != (uint *)0x0)) {
          pvVar8 = malloc(local_b8[0x10] + 0x48);
          *(void **)(param_1 + 0x18) = pvVar8;
          memcpy(pvVar8,local_b8,local_b8[0x10] + 0x48);
          pvVar8 = *(void **)(*(int *)(param_1 + 0x18) + 4);
          iVar11 = memcmp(pvVar8,&DAT_40c24a88,0x10);
          if (iVar11 == 0) {
            FUN_40c15d64(param_1);
            iVar11 = *(int *)(*(int *)(param_1 + 0x18) + 0x14);
            uVar7 = *(uint *)(*(int *)(param_1 + 0x18) + 0x10);
            *(undefined4 *)(param_1 + 0x28) = 0;
            lVar5 = (ulonglong)uVar7 * 10000;
            *(int *)(param_1 + 0x20) = (int)lVar5;
            *(int *)(param_1 + 0x24) = iVar11 * 10000 + (int)((ulonglong)lVar5 >> 0x20);
            free(local_b8);
            FUN_40c20494(local_30);
            return local_bc;
          }
          iVar11 = memcmp(pvVar8,&DAT_40c21808,0x10);
          if ((((iVar11 != 0) && (iVar11 = memcmp(pvVar8,&DAT_40c23ea8,0x10), iVar11 != 0)) &&
              (iVar11 = memcmp(pvVar8,&DAT_40c24a78,0x10), iVar11 != 0)) &&
             (iVar11 = memcmp(pvVar8,&DAT_40c24a68,0x10), iVar11 != 0)) {
            memcmp(pvVar8,&DAT_40c23e68,0x10);
          }
          free(local_b8);
        }
      }
      else {
        FUN_40c13634(0x40c22ae8,ppuVar9,puVar10,param_4);
      }
      FUN_40c20494(local_30);
      return -0x7ffbfdd6;
    }
    bVar1 = *(byte *)((int)local_c0 + 6);
    bVar2 = *(byte *)((int)local_c0 + 7);
    uVar7 = local_c0[2];
    bVar3 = *(byte *)((int)local_c0 + 9);
    operator_delete(local_c0);
    uVar7 = *(int *)(param_1 + 0x14) +
            ((((uint)bVar1 << 7 | (uint)bVar2) << 7 | (uint)(byte)uVar7) << 7 | (uint)bVar3) + 10;
    *(uint *)(param_1 + 0x14) = uVar7;
    puVar10 = *(uint **)(param_1 + 0x10);
    *puVar10 = uVar7 & 0xfffffffc;
    puVar10[1] = (int)uVar7 >> 0x1f;
    puVar6 = *(undefined4 **)(param_1 + 0x10);
    puVar6[4] = *puVar6;
    puVar6[5] = puVar6[1];
    param_4 = (va_list)FUN_40c17564(*(uint **)(param_1 + 0x10),&local_c0,0x10000);
    puVar10 = local_c0;
    while (param_4 != (va_list)0x0) {
      local_c0 = puVar10;
      memcpy(local_b0,puVar10,0x7f);
      iVar11 = 0;
      do {
        if (local_b0[iVar11] < ' ') {
          local_b0[iVar11] = '.';
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < 0x80);
      iVar11 = 0;
      while( true ) {
        if (0x77 < iVar11) {
          ppuVar9 = &local_b8;
          local_bc = FUN_40c18980(*(uint **)(param_1 + 0x10),ppuVar9,puVar10,param_4,
                                  *(va_list *)(param_1 + 0x14),1);
          goto LAB_40c1684c;
        }
        if (((*(char *)(iVar11 + (int)puVar10) == 'I') &&
            (*(char *)((int)puVar10 + iVar11 + 1) == 'D')) &&
           (*(char *)((int)puVar10 + iVar11 + 2) == '3')) break;
        iVar11 = iVar11 + 1;
      }
      bVar1 = *(byte *)((int)puVar10 + iVar11 + 6);
      bVar2 = *(byte *)((int)puVar10 + iVar11 + 7);
      local_b0[iVar11 + 0xf] = '\0';
      bVar3 = *(byte *)((int)puVar10 + iVar11 + 8);
      bVar4 = *(byte *)((int)puVar10 + iVar11 + 9);
      operator_delete(puVar10);
      uVar7 = *(int *)(param_1 + 0x14) +
              ((((uint)bVar1 << 7 | (uint)bVar2) << 7 | (uint)bVar3) << 7 | (uint)bVar4) + 10;
      *(uint *)(param_1 + 0x14) = uVar7;
      puVar10 = *(uint **)(param_1 + 0x10);
      *puVar10 = uVar7 & 0xfffffffc;
      puVar10[1] = (int)uVar7 >> 0x1f;
      puVar6 = *(undefined4 **)(param_1 + 0x10);
      puVar6[4] = *puVar6;
      puVar6[5] = puVar6[1];
      param_4 = (va_list)FUN_40c17564(*(uint **)(param_1 + 0x10),&local_c0,0x10000);
      puVar10 = local_c0;
    }
  }
  FUN_40c20494(local_30);
  return -0x7fffbffb;
}



/* 40c16a2c FUN_40c16a2c */

/* Boundary evidence: original MIPS .pdata 40c16a2c..40c16a5b. Semantic name remains unreviewed. */

void FUN_40c16a2c(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0xb4));
  return;
}



/* 40c16a5c FUN_40c16a5c */

/* Boundary evidence: original MIPS .pdata 40c16a5c..40c16aa7. Semantic name remains unreviewed. */

undefined4 * FUN_40c16a5c(undefined4 *param_1,uint param_2)

{
  FUN_40c15f24(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c16aa8 FUN_40c16aa8 */

/* Boundary evidence: original MIPS .pdata 40c16aa8..40c16bdb. Semantic name remains unreviewed. */

undefined4 *
FUN_40c16aa8(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,va_list param_4)

{
  DWORD DVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  
  if (DAT_40c26594 == 0) {
    pwVar4 = L"ALCHEMYMP3DEMUXSINGLEMUTEX";
    uVar3 = 1;
    DAT_40c26594 = (int)CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,1,L"ALCHEMYMP3DEMUXSINGLEMUTEX");
    if (((HANDLE)DAT_40c26594 != (HANDLE)0x0) && (DVar1 = GetLastError(), DVar1 != 0xb7)) {
      puVar2 = operator_new(0x118);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_40c16150(puVar2,param_1,param_2);
      }
      *param_2 = 0;
      return puVar2;
    }
    FUN_40c13634(0x40c22c48,uVar3,pwVar4,param_4);
    if (DAT_40c26594 != 0) {
      CloseHandle((HANDLE)DAT_40c26594);
    }
    DAT_40c26594 = 0;
    *param_2 = 0x80004005;
  }
  else {
    FUN_40c13634(0x40c22d50,param_2,param_3,param_4);
    *param_2 = 0x80004005;
  }
  return (undefined4 *)0x0;
}



/* 40c16bdc FUN_40c16bdc */

/* Boundary evidence: original MIPS .pdata 40c16bdc..40c16c0b. Semantic name remains unreviewed. */

void FUN_40c16bdc(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x20));
  return;
}



/* 40c16c0c FUN_40c16c0c */

/* Boundary evidence: original MIPS .pdata 40c16c0c..40c16c57. Semantic name remains unreviewed. */

undefined4 * FUN_40c16c0c(undefined4 *param_1,uint param_2)

{
  FUN_40c1637c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c16c58 FUN_40c16c58 */

/* Boundary evidence: original MIPS .pdata 40c16c58..40c16d07. Semantic name remains unreviewed. */

undefined4 * FUN_40c16c58(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80040216;
  }
  else {
    param_1[0x17] = param_2;
    (**(code **)(*param_2 + 4))(param_2);
    uVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))
                      ((int *)param_1[0x17],param_1 + 0x18,param_1 + 0x1a);
  }
  *param_3 = uVar1;
  return param_1;
}



/* 40c16d08 FUN_40c16d08 */

/* Boundary evidence: original MIPS .pdata 40c16d08..40c16d5f. Semantic name remains unreviewed. */

void FUN_40c16d08(int param_1)

{
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x5c) + 8))();
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  if (*(void **)(param_1 + 0x4c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x4c));
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  return;
}



/* 40c16d60 FUN_40c16d60 */

uint FUN_40c16d60(undefined1 *param_1,uint param_2,uint *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  
  *(undefined1 *)param_3 = 0;
  *(undefined1 *)((int)param_3 + 1) = 0;
  *(undefined1 *)((int)param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 3) = 0;
  *(undefined1 *)(param_3 + 1) = 0;
  *(undefined1 *)((int)param_3 + 5) = 0;
  *(undefined1 *)((int)param_3 + 6) = 0;
  *(undefined1 *)((int)param_3 + 7) = 0;
  *(undefined1 *)(param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 9) = 0;
  *(undefined1 *)((int)param_3 + 10) = 0;
  *(undefined1 *)((int)param_3 + 0xb) = 0;
  *(undefined1 *)(param_3 + 3) = 0;
  *(undefined1 *)((int)param_3 + 0xd) = 0;
  *(undefined1 *)((int)param_3 + 0xe) = 0;
  *(undefined1 *)((int)param_3 + 0xf) = 0;
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  if ((param_2 < 6) ||
     (uVar5 = (uint)(byte)param_1[4] * 0x100 + (uint)(byte)param_1[5] + 6, param_2 < uVar5)) {
    return 0;
  }
  param_3[1] = uVar5;
  uVar7 = 6;
  if (CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4) == 0xbf) {
LAB_40c16e8c:
    *param_3 = uVar7;
    return uVar5;
  }
  if (uVar5 < 7) {
    return 4;
  }
  do {
    bVar6 = param_1[uVar7];
    if ((bVar6 & 0x80) == 0) {
      if ((bVar6 & 0x40) == 0) {
        if (param_1[uVar7] == 0xf) {
          uVar7 = uVar7 + 1;
        }
        else {
          bVar6 = param_1[uVar7] & 0xf0;
          if (bVar6 == 0x20) {
            uVar7 = uVar7 + 5;
          }
          else {
            if (bVar6 != 0x30) {
              return 4;
            }
            uVar7 = uVar7 + 10;
          }
          if (uVar5 < uVar7) {
            return 4;
          }
        }
        goto LAB_40c16e8c;
      }
      uVar7 = uVar7 + 2;
    }
    else {
      if (bVar6 != 0xff) {
        return 4;
      }
      uVar7 = uVar7 + 1;
    }
    if (uVar5 <= uVar7) {
      return 4;
    }
  } while( true );
}



/* 40c16ee0 FUN_40c16ee0 */

uint FUN_40c16ee0(int param_1,uint param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined1 *)param_3 = 0;
  *(undefined1 *)((int)param_3 + 1) = 0;
  *(undefined1 *)((int)param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 3) = 0;
  *(undefined1 *)(param_3 + 1) = 0;
  *(undefined1 *)((int)param_3 + 5) = 0;
  *(undefined1 *)((int)param_3 + 6) = 0;
  *(undefined1 *)((int)param_3 + 7) = 0;
  *(undefined1 *)(param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 9) = 0;
  *(undefined1 *)((int)param_3 + 10) = 0;
  *(undefined1 *)((int)param_3 + 0xb) = 0;
  *(undefined1 *)(param_3 + 3) = 0;
  *(undefined1 *)((int)param_3 + 0xd) = 0;
  *(undefined1 *)((int)param_3 + 0xe) = 0;
  *(undefined1 *)((int)param_3 + 0xf) = 0;
  if (param_2 < 6) {
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 3);
  uVar2 = (uint)*(byte *)(param_1 + 4) * 0x100 + (uint)*(byte *)(param_1 + 5) + 6;
  if (bVar1 < 0xf3) {
    if (((0xef < bVar1) || (bVar1 == 0xbc)) || ((0xbd < bVar1 && (bVar1 < 0xc0))))
    goto LAB_40c16f84;
LAB_40c16fc0:
    if (param_2 < 9) {
      param_3[1] = 0;
      goto LAB_40c16f90;
    }
    uVar3 = *(byte *)(param_1 + 8) + 9;
    *param_3 = uVar3;
    if (param_2 < uVar3) goto LAB_40c16f90;
    if (uVar2 < 9) {
      return 4;
    }
    *param_3 = *(byte *)(param_1 + 8) + 9;
  }
  else {
    if ((bVar1 != 0xf8) && (bVar1 != 0xff)) goto LAB_40c16fc0;
LAB_40c16f84:
    *param_3 = 6;
  }
  param_3[1] = uVar2;
LAB_40c16f90:
  if (param_2 < uVar2) {
    return 0;
  }
  return uVar2;
}



/* 40c1700c FUN_40c1700c */

/* Boundary evidence: original MIPS .pdata 40c1700c..40c171db. Semantic name remains unreviewed. */

undefined4 FUN_40c1700c(undefined1 *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint auStack_38 [4];
  
  iVar3 = 0;
  while( true ) {
    if (param_2 < 5) {
      return 0;
    }
    if ((CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]) == 0x1ba) &&
       ((param_1[4] & 0xc0) == 0x40)) break;
LAB_40c17190:
    param_2 = param_2 - 1;
    param_1 = param_1 + 1;
  }
joined_r0x40c170b0:
  do {
    if (param_2 < 5) goto LAB_40c17190;
    bVar1 = param_1[3];
    uVar2 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),bVar1);
    if ((0x1bb < uVar2) && (uVar2 < 0x200)) {
      uVar2 = FUN_40c16ee0((int)param_1,param_2,auStack_38);
      if (4 < uVar2) {
        if ((bVar1 & 0xf0) == 0xe0) {
          iVar3 = iVar3 + 1;
        }
        if (10 < iVar3) {
          return 1;
        }
        param_2 = param_2 - uVar2;
        param_1 = param_1 + uVar2;
        goto joined_r0x40c170b0;
      }
      if (uVar2 == 0) goto LAB_40c17190;
    }
    param_2 = param_2 - 1;
    param_1 = param_1 + 1;
  } while( true );
}



/* 40c171dc FUN_40c171dc */

/* Boundary evidence: original MIPS .pdata 40c171dc..40c17497. Semantic name remains unreviewed. */

undefined4 FUN_40c171dc(uint *param_1,uint param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint auStack_38 [4];
  
  bVar3 = false;
  bVar2 = false;
  if (param_2 < 0x18001) {
    for (; 4 < param_2; param_2 = param_2 - 1) {
      if ((CONCAT31(CONCAT21(CONCAT11((char)*param_1,*(undefined1 *)((int)param_1 + 1)),
                             *(undefined1 *)((int)param_1 + 2)),*(undefined1 *)((int)param_1 + 3))
           == 0x1ba) && ((param_1[1] & 0xf0) == 0x20)) {
joined_r0x40c1738c:
        do {
          if (param_2 < 5) break;
          bVar1 = *(byte *)((int)param_1 + 3);
          uVar5 = CONCAT31(CONCAT21(CONCAT11((char)*param_1,*(undefined1 *)((int)param_1 + 1)),
                                    *(undefined1 *)((int)param_1 + 2)),bVar1);
          if ((0x1bb < uVar5) && (uVar5 < 0x200)) {
            uVar5 = FUN_40c16d60((undefined1 *)param_1,param_2,auStack_38);
            if (4 < uVar5) {
              if ((bVar1 & 0xf0) == 0xe0) {
                bVar2 = true;
LAB_40c17430:
                if (bVar3) {
                  return 1;
                }
              }
              else {
                if (((bVar1 & 0xe0) == 0xc0) || (bVar1 == 0xbd)) {
                  bVar3 = true;
                }
                if (bVar2) goto LAB_40c17430;
              }
              param_2 = param_2 - uVar5;
              param_1 = (uint *)(uVar5 + (int)param_1);
              if (param_2 == 0) {
                return 0;
              }
              goto joined_r0x40c1738c;
            }
            if (uVar5 == 0) break;
          }
          param_2 = param_2 - 1;
          param_1 = (uint *)((int)param_1 + 1);
        } while( true );
      }
      param_1 = (uint *)((int)param_1 + 1);
    }
  }
  else {
    for (puVar6 = param_1; puVar6 < param_1 + 0x6000; puVar6 = (uint *)((int)puVar6 + 1)) {
      if (((((*puVar6 & 0xffffff) == 0x10000) &&
           (uVar5 = CONCAT31(CONCAT21(CONCAT11((char)*puVar6,*(undefined1 *)((int)puVar6 + 1)),
                                      *(undefined1 *)((int)puVar6 + 2)),
                             *(undefined1 *)((int)puVar6 + 3)), 0x1bb < uVar5)) && (uVar5 < 0x200))
         && ((puVar4 = (uint *)((int)puVar6 +
                               (uint)(byte)puVar6[1] * 0x100 + (uint)*(byte *)((int)puVar6 + 5) + 6)
             , puVar4 < param_1 + 0x5fff && ((*puVar4 & 0xffffff) == 0x10000)))) {
        return 1;
      }
    }
  }
  return 0;
}



/* 40c17498 FUN_40c17498 */

/* Boundary evidence: original MIPS .pdata 40c17498..40c17563. Semantic name remains unreviewed. */

uint FUN_40c17498(uint param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  if ((param_1 & 0xffffff00) == 0x49443300) {
    FUN_40c13634(0x40c22f58,param_2,param_3,param_4);
    return 0xfffffffd;
  }
  if ((param_1 & 0xffffff00) == 0x54414700) {
    FUN_40c13634(0x40c22f44,param_2,param_3,param_4);
    return 0xfffffffe;
  }
  if ((((param_1 & 0xffe00000) == 0xffe00000) && ((param_1 & 0xc00) != 0xc00)) &&
     ((param_1 & 0x60000) != 0)) {
    return (uint)((param_1 & 0xf000) == 0xf000);
  }
  return 1;
}



/* 40c17564 FUN_40c17564 */

/* Boundary evidence: original MIPS .pdata 40c17564..40c17837. Semantic name remains unreviewed. */

uint FUN_40c17564(uint *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  va_list pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_2c;
  
  local_38 = param_1[0x18];
  local_34 = param_1[0x19];
  local_40 = param_1[0x1a];
  local_3c = param_1[0x1b];
  uVar8 = *param_1;
  uVar9 = param_1[1];
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    iVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))((int *)param_1[0x17],&local_38,&local_40);
    if (-1 < iVar2) {
      bVar1 = local_38 < uVar8;
      local_38 = local_38 - uVar8;
      local_34 = (local_34 - uVar9) - (uint)bVar1;
      bVar1 = local_40 < uVar8;
      local_40 = local_40 - uVar8;
      local_3c = (local_3c - uVar9) - (uint)bVar1;
      if (((0 < (int)local_34) || ((uVar8 = local_38, local_34 == 0 && (param_3 <= local_38)))) &&
         ((uVar8 = param_3, (int)local_3c < 1 &&
          (((local_3c != 0 || (local_40 < param_3)) &&
           ((0 < (int)local_3c || ((uVar8 = 0x20000, local_3c == 0 && (0x1ffff < local_40))))))))))
      {
        uVar8 = local_40;
      }
      pvVar3 = operator_new(uVar8);
      if (pvVar3 != (void *)0x0) {
        uVar9 = 0;
        iVar2 = 4;
        do {
          if (((int)local_3c < 1) && ((local_3c != 0 || (local_40 < uVar8)))) {
            local_2c = local_3c;
            uVar10 = local_40;
          }
          else {
            local_2c = 0;
            uVar10 = uVar8;
          }
          iVar4 = (**(code **)(*(int *)param_1[0x17] + 0x1c))();
          while (iVar4 != 0) {
            if (((int)local_3c < 0) || ((local_3c == 0 && (local_40 <= uVar9)))) goto LAB_40c177ec;
            iVar2 = iVar2 + -1;
            if (iVar2 < 1) {
              operator_delete(pvVar3);
              return 0;
            }
            uVar7 = param_1[0xe];
            uVar6 = uVar7 + *param_1;
            pcVar5 = (va_list)(((int)uVar7 >> 0x1f) + param_1[1] + (uint)(uVar6 < uVar7));
            *param_1 = uVar6;
            param_1[1] = (uint)pcVar5;
            FUN_40c13634(0x40c22f88,uVar10,uVar6,pcVar5);
            iVar4 = (**(code **)(*(int *)param_1[0x17] + 0x1c))();
          }
          uVar6 = *param_1;
          uVar9 = uVar10 + uVar9;
          *param_1 = uVar10 + uVar6;
          param_1[1] = param_1[1] + (uint)(uVar10 + uVar6 < uVar10);
        } while (uVar9 < uVar8);
LAB_40c177ec:
        *param_2 = pvVar3;
        return uVar9;
      }
    }
  }
  return 0;
}



/* 40c17838 FUN_40c17838 */

/* Boundary evidence: original MIPS .pdata 40c17838..40c17b3f. Semantic name remains unreviewed. */

void FUN_40c17838(int param_1)

{
  wchar_t wVar1;
  wchar_t wVar2;
  WCHAR WVar3;
  WCHAR WVar4;
  LSTATUS LVar5;
  wchar_t *pwVar6;
  WCHAR *pWVar7;
  wchar_t *pwVar8;
  DWORD dwIndex;
  HKEY local_240;
  DWORD local_23c;
  undefined4 local_238;
  DWORD local_234;
  WCHAR local_230 [256];
  uint local_30;
  
  local_30 = DAT_40c2618c;
  *(undefined4 *)(param_1 + 0x24) = 0x80;
  *(undefined4 *)(param_1 + 0x28) = 0xc00000;
  *(undefined4 *)(param_1 + 0x38) = 0x2000;
  *(undefined4 *)(param_1 + 0x34) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 100;
  LVar5 = RegOpenKeyExW((HKEY)0x80000000,
                        L"CLSID\\{DC56E099-C9EA-49c8-9FA2-0A173D1522F1}\\Pins\\Input",0,0x20019,
                        &local_240);
  if (LVar5 == 0) {
    local_234 = 4;
    dwIndex = 0;
    do {
      local_23c = 0x100;
      LVar5 = RegEnumValueW(local_240,dwIndex,local_230,&local_23c,(LPDWORD)0x0,(LPDWORD)0x0,
                            (LPBYTE)&local_238,&local_234);
      if (LVar5 != 0) break;
      pwVar8 = local_230;
      pwVar6 = L"ForceShortVbrScan";
      do {
        wVar1 = *pwVar6;
        wVar2 = *pwVar8;
        if (wVar1 == L'\0') break;
        pwVar6 = pwVar6 + 1;
        pwVar8 = pwVar8 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        *(undefined4 *)(param_1 + 0x20) = local_238;
      }
      pWVar7 = local_230;
      pwVar6 = L"Mp3CbrLimit";
      do {
        WVar3 = *pwVar6;
        WVar4 = *pWVar7;
        if (WVar3 == L'\0') break;
        pwVar6 = pwVar6 + 1;
        pWVar7 = pWVar7 + 1;
      } while (WVar3 == WVar4);
      if (WVar3 == WVar4) {
        *(undefined4 *)(param_1 + 0x24) = local_238;
      }
      pwVar8 = local_230;
      pwVar6 = L"Mp3FullFileScanSize";
      do {
        wVar1 = *pwVar6;
        wVar2 = *pwVar8;
        if (wVar1 == L'\0') break;
        pwVar6 = pwVar6 + 1;
        pwVar8 = pwVar8 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        *(undefined4 *)(param_1 + 0x28) = local_238;
        *(undefined4 *)(param_1 + 0x2c) = 0;
      }
      pwVar8 = local_230;
      pwVar6 = L"Mp3FileScanWithin";
      do {
        wVar1 = *pwVar6;
        wVar2 = *pwVar8;
        if (wVar1 == L'\0') break;
        pwVar6 = pwVar6 + 1;
        pwVar8 = pwVar8 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        *(undefined4 *)(param_1 + 0x30) = local_238;
        *(undefined4 *)(param_1 + 0x34) = 0;
      }
      pwVar8 = local_230;
      pwVar6 = L"Mp3InitErrorSkipBytes";
      do {
        wVar1 = *pwVar6;
        wVar2 = *pwVar8;
        if (wVar1 == L'\0') break;
        pwVar6 = pwVar6 + 1;
        pwVar8 = pwVar8 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        *(undefined4 *)(param_1 + 0x38) = local_238;
      }
      pwVar8 = local_230;
      pwVar6 = L"Mp3PlayErrorSkipMS";
      do {
        wVar1 = *pwVar6;
        wVar2 = *pwVar8;
        if (wVar1 == L'\0') break;
        pwVar6 = pwVar6 + 1;
        pwVar8 = pwVar8 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        *(undefined4 *)(param_1 + 0x3c) = local_238;
      }
      pwVar8 = local_230;
      pwVar6 = L"Mp3PlayErrorAbortType";
      do {
        wVar1 = *pwVar6;
        wVar2 = *pwVar8;
        if (wVar1 == L'\0') break;
        pwVar6 = pwVar6 + 1;
        pwVar8 = pwVar8 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        *(undefined4 *)(param_1 + 0x40) = local_238;
      }
      dwIndex = dwIndex + 1;
    } while ((int)dwIndex < 0xc);
    RegCloseKey(local_240);
  }
  FUN_40c20494(local_30);
  return;
}



/* 40c17b40 FUN_40c17b40 */

/* Boundary evidence: original MIPS .pdata 40c17b40..40c185cb. Semantic name remains unreviewed. */

int FUN_40c17b40(uint *param_1,byte *param_2,uint param_3,va_list param_4,uint param_5,uint param_6,
                undefined1 *param_7,int param_8)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  void *pvVar5;
  uint uVar6;
  void *pvVar7;
  int iVar8;
  byte **ppbVar9;
  va_list pcVar10;
  undefined1 uVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  byte *pbVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  byte *pbVar23;
  uint uVar24;
  int iVar25;
  uint local_50;
  int local_4c;
  byte *local_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  undefined *local_34;
  uint local_30;
  uint local_2c;
  
  local_40 = 0;
  uVar19 = 0;
  uVar21 = 0;
  iVar22 = 0;
  local_30 = 0;
  local_50 = 0;
  local_4c = 0;
  local_2c = 0;
  local_48 = (byte *)0x0;
  local_38 = 0x10000;
  local_44 = 0;
  local_3c = 0;
  pvVar5 = operator_new(0x60008);
  if (param_8 == 2) {
    uVar14 = 0x80000;
    local_38 = 0x80000;
  }
  else {
    uVar14 = 0x10000;
  }
  param_1[0x11] = 0;
  ppbVar9 = (byte **)0x1;
  if (param_3 < uVar14) {
    ppbVar9 = &local_48;
    *param_1 = param_5;
    param_1[1] = param_6;
    uVar6 = FUN_40c17564(param_1,ppbVar9,uVar14);
  }
  else {
    uVar6 = uVar14;
    if (((int)param_6 < 1) && ((param_6 != 0 || (param_5 < 100)))) {
      param_2 = param_2 + param_5;
      uVar6 = uVar14 - param_5;
    }
    *param_1 = uVar14 + param_5;
    param_1[1] = param_6 + (uVar14 + param_5 < uVar14);
    local_44 = 1;
    local_48 = param_2;
  }
  if ((local_48 == (byte *)0x0) && (uVar6 == 0)) {
    FUN_40c13634(0x40c231d4,ppbVar9,param_8,param_4);
    param_1[2] = 1;
    operator_delete(pvVar5);
    return 0;
  }
  pbVar23 = local_48;
  if (0x1ff < (int)uVar6) {
    local_34 = &DAT_40c22e88;
    pbVar18 = local_48;
    do {
      pcVar10 = (va_list)0x3;
      iVar20 = 0;
      if ((int)uVar6 < 0x1000) {
        if (param_1[8] != 0) break;
        if (local_44 == 0) {
          operator_delete(pbVar23);
        }
        uVar14 = local_38;
        local_44 = 0;
        ppbVar9 = &local_48;
        *param_1 = param_5;
        param_1[1] = param_6;
        uVar6 = FUN_40c17564(param_1,ppbVar9,local_38);
        pbVar23 = local_48;
        if ((param_8 != 2) && (uVar6 != uVar14)) break;
        pbVar18 = local_48;
        if ((local_48 == (byte *)0x0) && (uVar6 == 0)) {
          FUN_40c13634(0x40c231d4,ppbVar9,param_8,pcVar10);
          operator_delete(pvVar5);
          return 0;
        }
      }
      for (; 0x1ff < (int)uVar6; uVar6 = uVar6 - 1) {
        bVar2 = pbVar18[1];
        uVar4 = CONCAT11(*pbVar18,bVar2);
        bVar3 = pbVar18[2];
        uVar19 = CONCAT31(CONCAT21(uVar4,bVar3),pbVar18[3]);
        if ((uVar4 & 0xffe0) == 0xffe0) {
          uVar21 = 4 - (uVar4 >> 1 & 3);
          if (((((bVar2 & 0x18) != 8) && (uVar21 != 4)) && (bVar3 >> 4 != 0xf)) &&
             ((bVar3 & 0xc) != 0xc)) {
            iVar20 = 0;
            break;
          }
          iVar20 = iVar20 + 1;
        }
        param_6 = param_6 + (param_5 + 1 < param_5);
        pbVar18 = pbVar18 + 1;
        param_5 = param_5 + 1;
      }
      if (((int)param_1[0xd] < (int)param_6) ||
         ((param_6 == param_1[0xd] && (param_1[0xc] < param_5)))) {
        local_3c = 0;
        break;
      }
      if ((((uVar19 & 0xffe00000) == 0xffe00000) && ((uVar19 >> 0x13 & 3) != 1)) &&
         ((uVar21 = 4 - (uVar19 >> 0x11 & 3), uVar21 != 4 &&
          ((uVar14 = uVar19 >> 0xc & 0xf, uVar14 != 0xf && (uVar17 = uVar19 >> 10 & 3, uVar17 != 3))
          )))) {
        if (uVar14 == 0) {
          uVar14 = param_5 + 1;
          param_6 = param_6 + (uVar14 < param_5);
          pbVar18 = pbVar18 + 1;
          uVar6 = uVar6 - 1;
          param_5 = uVar14;
          if ((param_8 != 2) || (param_1[8] != 0)) {
            local_50 = 0;
            local_4c = 0;
            iVar22 = 0;
            param_1[0x14] = 0;
            param_1[0x16] = 0;
          }
        }
        else {
          bVar1 = (uVar19 & 0x100000) == 0;
          if (bVar1) {
            uVar15 = 1;
          }
          else {
            uVar15 = (uint)((uVar19 & 0x80000) == 0);
          }
          local_2c = (uint)(*(ushort *)(local_34 + uVar17 * 2) >> bVar1 + uVar15);
          if (param_1[0x15] == uVar14) {
            param_1[0x14] = param_1[0x14] + 1;
          }
          else {
            param_1[0x15] = uVar14;
            param_1[0x14] = 0;
            if (iVar20 == 0) {
              param_1[0x16] = param_1[0x16] + 1;
            }
          }
          uVar24 = (uint)*(ushort *)
                          (local_34 + ((uVar15 * 3 + uVar21) * 0xf + uVar14 + -0xf) * 2 + 8);
          local_50 = uVar24 + local_50;
          local_4c = local_4c + (uint)(local_50 < uVar24);
          local_30 = uVar19 >> 6 & 3;
          uVar17 = uVar19 >> 9 & 1;
          if (uVar14 != 0) {
            if (uVar21 == 1) {
              if (local_2c == 0) {
                trap(0x1c00);
              }
              if ((local_2c == 0xffffffff) && (uVar24 * 12000 == 0x80000000)) {
                trap(0x1800);
              }
              local_40 = ((uVar24 * 12000) / local_2c + uVar17) * 4;
            }
            else {
              iVar20 = uVar24 * 0x23280;
              if (uVar21 == 2) {
                if (local_2c == 0) {
                  trap(0x1c00);
                }
                if ((local_2c == 0xffffffff) && (iVar20 == -0x80000000)) {
                  trap(0x1800);
                }
                local_40 = iVar20 / (int)local_2c + uVar17;
              }
              else {
                iVar12 = local_2c << uVar15;
                if (iVar12 == 0) {
                  trap(0x1c00);
                }
                if ((iVar12 == -1) && (iVar20 == -0x80000000)) {
                  trap(0x1800);
                }
                local_40 = iVar20 / iVar12 + uVar17;
              }
            }
          }
          if (0x7fff < iVar22) {
            local_3c = 0;
            break;
          }
          *(ushort *)((iVar22 + 0x8004) * 2 + (int)pvVar5) =
               *(ushort *)(local_34 + ((uVar15 * 3 + uVar21) * 0xf + uVar14 + -0xf) * 2 + 8);
          puVar13 = (uint *)((iVar22 + 0x4001) * 8 + (int)pvVar5);
          *(short *)((iVar22 + 4) * 2 + (int)pvVar5) = (short)local_40;
          *puVar13 = param_5;
          puVar13[1] = param_6;
          *(int *)((int)pvVar5 + 4) = iVar22;
          local_3c = 1;
          iVar22 = iVar22 + 1;
          if ((int)local_40 < (int)uVar6) {
            uVar14 = local_40 + param_5;
            pbVar18 = pbVar18 + local_40;
            param_6 = ((int)local_40 >> 0x1f) + param_6 + (uint)(uVar14 < local_40);
            uVar4 = CONCAT11(*pbVar18,pbVar18[1]);
            uVar6 = uVar6 - local_40;
            uVar19 = CONCAT31(CONCAT21(uVar4,pbVar18[2]),pbVar18[3]);
            param_5 = uVar14;
            if ((uVar4 & 0xffe0) != 0xffe0) {
              if ((param_8 == 2) && (param_1[8] == 0)) {
                param_5 = uVar14 + 1;
                param_6 = param_6 + (param_5 < uVar14);
                uVar6 = uVar6 - 1;
                pbVar18 = pbVar18 + 1;
              }
              else {
                if (0x14 < iVar22) break;
                local_50 = 0;
                local_4c = 0;
                iVar22 = 0;
              }
            }
          }
          else {
            if (0x14 < iVar22) break;
            param_6 = param_6 + (param_5 + 1 < param_5);
            uVar6 = uVar6 - 1;
            pbVar18 = pbVar18 + 1;
            param_5 = param_5 + 1;
          }
        }
        if (((((int)(param_1[9] + 5) < iVar22) && (param_8 == 0)) ||
            ((10 < iVar22 && (param_8 == 1)))) ||
           (((int)param_1[9] < (int)param_1[0x14] && ((int)param_1[0x16] < 5)))) break;
      }
    } while (0x1ff < (int)uVar6);
    if (iVar22 != 0) {
      uVar11 = 1;
      if (local_30 != 3) {
        uVar11 = 2;
      }
      param_7[2] = uVar11;
      param_7[3] = 0;
      pcVar10 = (va_list)(iVar22 >> 0x1f);
      *(uint *)(param_7 + 4) = local_2c;
      param_7[0xe] = 0x10;
      param_7[0xf] = 0;
      iVar20 = __ll_div((int)((ulonglong)local_50 * 0x7d),
                        local_4c * 0x7d + (int)((ulonglong)local_50 * 0x7d >> 0x20));
      *(int *)(param_7 + 8) = iVar20;
      if ((iVar20 == 0) || (720000 < (uint)(iVar20 << 3))) {
        FUN_40c13634(0x40c23168,iVar20,iVar22,pcVar10);
        *(undefined4 *)(param_7 + 8) = 0;
      }
      else {
        if (uVar21 < 4) {
          *param_7 = 0x50;
          param_7[1] = 0;
          iVar22 = 1;
          goto LAB_40c183c4;
        }
        *(undefined4 *)(param_7 + 8) = 0;
      }
    }
  }
  iVar22 = 0;
LAB_40c183c4:
  if (param_7[2] == '\0' && param_7[3] == '\0') {
    iVar22 = 0;
  }
  if (local_44 == 0) {
    operator_delete(pbVar23);
  }
  if ((((local_3c != 0) && (param_8 == 2)) && (iVar22 == 1)) &&
     ((*(int *)(param_7 + 8) != 0 && (5 < (int)param_1[0x16])))) {
    uVar19 = *(uint *)((int)pvVar5 + 4);
    param_1[0x12] = uVar19;
    if (uVar19 < 0xaaaaaab) {
      uVar19 = uVar19 * 0x18;
    }
    else {
      uVar19 = 0xffffffff;
    }
    pvVar7 = operator_new(uVar19);
    iVar20 = 0;
    param_1[0x13] = (uint)pvVar7;
    if (0 < (int)param_1[0x12]) {
      do {
        iVar12 = (uint)*(ushort *)((iVar20 + 4) * 2 + (int)pvVar5) * 80000;
        iVar8 = iVar20 * 0x18;
        uVar19 = (uint)*(ushort *)((iVar20 + 0x8004) * 2 + (int)pvVar5);
        iVar25 = iVar12 / (int)uVar19;
        if (uVar19 == 0) {
          trap(0x1c00);
        }
        if ((uVar19 == 0xffffffff) && (iVar12 == -0x80000000)) {
          trap(0x1800);
        }
        uVar19 = param_1[0x13];
        *(int *)(iVar8 + uVar19) = iVar25;
        ((int *)(iVar8 + uVar19))[1] = iVar25 >> 0x1f;
        if (iVar20 == 0) {
          uVar19 = param_1[0x13];
          *(undefined4 *)(uVar19 + 8) = 0;
          *(undefined4 *)(uVar19 + 0xc) = 0;
        }
        else {
          iVar12 = iVar8 + param_1[0x13];
          uVar19 = *(uint *)(iVar12 + -0x18) + *(int *)(iVar12 + -0x10);
          *(uint *)(iVar12 + 8) = uVar19;
          *(uint *)(iVar12 + 0xc) =
               *(int *)(iVar12 + -0x14) + *(int *)(iVar12 + -0xc) +
               (uint)(uVar19 < *(uint *)(iVar12 + -0x18));
        }
        uVar19 = param_1[0x13];
        puVar16 = (undefined4 *)((iVar20 + 0x4001) * 8 + (int)pvVar5);
        *(undefined4 *)(iVar8 + uVar19 + 0x10) = *puVar16;
        iVar20 = iVar20 + 1;
        *(undefined4 *)(iVar8 + uVar19 + 0x14) = puVar16[1];
      } while (iVar20 < (int)param_1[0x12]);
    }
    param_1[0x11] = 1;
  }
  operator_delete(pvVar5);
  return iVar22;
}



/* 40c185cc FUN_40c185cc */

void FUN_40c185cc(void)

{
  return;
}



/* 40c185d4 FUN_40c185d4 */

int FUN_40c185d4(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x48);
  iVar1 = 0;
  if (0 < iVar3) {
    puVar2 = (uint *)(*(int *)(param_1 + 0x4c) + 8);
    do {
      if (((int)param_4 < (int)puVar2[1]) || ((param_4 == puVar2[1] && (param_3 <= *puVar2))))
      break;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 6;
    } while (iVar1 < iVar3);
  }
  if (iVar3 <= iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40c18634 FUN_40c18634 */

/* Boundary evidence: original MIPS .pdata 40c18634..40c188bb. Semantic name remains unreviewed. */

undefined4
FUN_40c18634(uint *param_1,byte *param_2,uint param_3,va_list param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  undefined1 uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  if ((param_1[8] == 0) && (((int)param_1[0x14] <= (int)param_1[9] || (4 < (int)param_1[0x16])))) {
    param_1[0x14] = 0;
    param_1[0x15] = 0xffffffff;
    param_1[0x16] = 0;
    if ((undefined4 *)param_5[1] == &DAT_40c24a88) {
      memset(param_6,0,0x12);
      iVar3 = FUN_40c17b40(param_1,param_2,param_3,param_4,param_5[6],param_5[7],
                           (undefined1 *)param_6,2);
      if (iVar3 == 0) {
        return 0x80040240;
      }
      uVar4 = param_6[2];
      param_5[8] = uVar4 << 3;
      param_6[2] = uVar4 & 0x1fffffff;
      *param_5 = &DAT_40c23b98;
      uVar4 = param_5[8];
      param_5[1] = &DAT_40c24a88;
      param_5[9] = uVar4;
      if (uVar4 < 32000) {
        param_5[10] = 0x200;
      }
      else if (uVar4 < 64000) {
        param_5[10] = 0x400;
      }
      else {
        param_5[10] = 0x800;
      }
      param_5[0xb] = 0x40;
      uVar4 = param_1[0x18];
      param_5[2] = uVar4;
      uVar5 = param_1[0x19];
      param_5[3] = uVar5;
      lVar2 = (ulonglong)(uVar4 - param_5[6]) * 8000;
      uVar6 = __ll_div((int)lVar2,
                       ((uVar5 - param_5[7]) - (uint)(uVar4 < (uint)param_5[6])) * 8000 +
                       (int)((ulonglong)lVar2 >> 0x20),param_5[8],0);
      *(undefined8 *)(param_5 + 4) = uVar6;
      param_5[0xc] = 0x5589f81;
      param_5[0xd] = 0x11cec356;
      param_5[0xe] = 0xaa0001bf;
      param_5[0xf] = 0x5a595500;
      param_5[0x10] = 0x12;
      param_5[0x11] = param_5 + 0x12;
      param_5[0x12] = *param_6;
      param_5[0x13] = param_6[1];
      param_5[0x14] = param_6[2];
      param_5[0x15] = param_6[3];
      uVar1 = *(undefined1 *)((int)param_6 + 0x11);
      *(undefined1 *)(param_5 + 0x16) = *(undefined1 *)(param_6 + 4);
      *(undefined1 *)((int)param_5 + 0x59) = uVar1;
      *param_1 = 0;
      param_1[1] = 0;
    }
  }
  return 0;
}



/* 40c188bc FUN_40c188bc */

/* Boundary evidence: original MIPS .pdata 40c188bc..40c1897f. Semantic name remains unreviewed. */

void FUN_40c188bc(uint *param_1,byte *param_2,uint param_3,va_list param_4,undefined1 *param_5,
                 int param_6)

{
  int iVar1;
  va_list pcVar2;
  
  param_1[0x14] = 0;
  param_1[0x15] = 0xffffffff;
  param_1[0x16] = 0;
  pcVar2 = param_4;
  iVar1 = FUN_40c17b40(param_1,param_2,param_3,param_4,(uint)param_4,0,param_5,0);
  if ((param_6 != 0) && (iVar1 == 0)) {
    FUN_40c17b40(param_1,param_2,param_3,pcVar2,(uint)param_4,0,param_5,2);
  }
  return;
}



/* 40c18980 FUN_40c18980 */

/* Boundary evidence: original MIPS .pdata 40c18980..40c18e03. Semantic name remains unreviewed. */

undefined4
FUN_40c18980(uint *param_1,undefined4 *param_2,uint *param_3,va_list param_4,va_list param_5,
            int param_6)

{
  longlong lVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  va_list pcVar5;
  uint *puVar6;
  undefined4 uVar7;
  va_list pcVar8;
  int iVar9;
  undefined1 *puVar10;
  va_list pcVar11;
  undefined8 uVar12;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined1 local_30;
  undefined1 local_2f;
  
  uVar7 = 0x12;
  uVar4 = 0;
  pcVar8 = param_4;
  memset(&local_40,0,0x12);
  if ((param_3 == (uint *)0x0) && (param_4 == (va_list)0x0)) {
    FUN_40c13634(0x40c23338,uVar4,uVar7,pcVar8);
    return 0x80004005;
  }
  pcVar5 = (va_list)0x758;
  if ((int)param_4 < 0x759) {
    pcVar5 = param_4;
  }
  iVar9 = 0;
  if (0 < (int)(pcVar5 + -0xbc)) {
    do {
      if ((((*(char *)(iVar9 + (int)param_3) == 'G') &&
           (*(char *)((int)param_3 + iVar9 + 0xbc) == 'G')) &&
          (*(char *)((int)param_3 + iVar9 + 0x178) == 'G')) &&
         (*(char *)((int)param_3 + iVar9 + 0x234) == 'G')) {
        return 0x80040240;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)(pcVar5 + -0xbc));
  }
  iVar9 = FUN_40c1700c((undefined1 *)param_3,(uint)param_4);
  if (iVar9 != 0) {
    return 0x80040240;
  }
  pcVar5 = param_4;
  iVar9 = FUN_40c171dc(param_3,(uint)param_4);
  if (iVar9 != 0) {
    return 0x80040240;
  }
  if (param_5 != (va_list)0x0) {
    pcVar11 = (va_list)0x0;
    if (param_4 != (va_list)0x8) {
      puVar10 = (undefined1 *)((int)param_3 + 2);
      do {
        uVar2 = FUN_40c17498(CONCAT31(CONCAT21(CONCAT11(puVar10[-2],puVar10[-1]),*puVar10),
                                      puVar10[1]),pcVar5,uVar7,pcVar8);
        if (uVar2 == 0) break;
        pcVar11 = pcVar11 + 1;
        puVar10 = puVar10 + 1;
      } while (pcVar11 < param_4 + -8);
    }
    param_5 = pcVar11 + (int)param_5;
  }
  if (param_6 != 0) {
    puVar6 = param_3;
    pcVar5 = param_4;
    pcVar8 = param_5;
    iVar9 = FUN_40c188bc(param_1,(byte *)param_3,(uint)param_4,param_5,(undefined1 *)&local_40,
                         param_6);
    if (iVar9 != 0) {
      puVar3 = malloc(0x5a);
      *puVar3 = &DAT_40c23b98;
      puVar3[1] = &DAT_40c24a88;
      puVar3[6] = param_5;
      puVar3[7] = 0;
      FUN_40c18634(param_1,(byte *)param_3,(uint)param_4,param_5,puVar3,&local_40);
      iVar9 = local_38 << 3;
      puVar3[9] = iVar9;
      puVar3[8] = iVar9;
      puVar3[10] = 0x10000;
      puVar3[0xb] = 0x40;
      puVar3[2] = param_1[0x18];
      puVar3[3] = param_1[0x19];
      if (iVar9 == 0) {
        FUN_40c13634(0x40c232e0,0,0,param_5);
        return 0x80040240;
      }
      goto LAB_40c18bc4;
    }
    if (param_1[2] != 0) {
      FUN_40c13634(0x40c2328c,puVar6,pcVar5,pcVar8);
      return 0x80040240;
    }
  }
  if (param_5 == (va_list)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  param_1[0x14] = 0;
  param_1[0x15] = 0xffffffff;
  param_1[0x16] = 0;
  iVar9 = FUN_40c17b40(param_1,(byte *)param_3,(uint)param_4,pcVar8,(uint)param_5,0,
                       (undefined1 *)&local_40,0);
  if (iVar9 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    puVar3 = malloc(0x5a);
    *puVar3 = &DAT_40c23b98;
    puVar3[1] = &DAT_40c24a88;
    puVar3[6] = param_5;
    puVar3[7] = 0;
    FUN_40c18634(param_1,(byte *)param_3,(uint)param_4,param_5,puVar3,&local_40);
    iVar9 = local_38 << 3;
    puVar3[9] = iVar9;
    puVar3[8] = iVar9;
    puVar3[10] = 0x10000;
    puVar3[0xb] = 0x40;
    puVar3[2] = param_1[0x18];
    puVar3[3] = param_1[0x19];
    if (iVar9 != 0) {
LAB_40c18bc4:
      lVar1 = (ulonglong)(uint)(puVar3[2] - puVar3[6]) * 8000;
      uVar12 = __ll_div((int)lVar1,
                        ((puVar3[3] - puVar3[7]) - (uint)((uint)puVar3[2] < (uint)puVar3[6])) * 8000
                        + (int)((ulonglong)lVar1 >> 0x20),iVar9,0);
      *(undefined8 *)(puVar3 + 4) = uVar12;
      puVar3[0xc] = 0x5589f81;
      puVar3[0xd] = 0x11cec356;
      puVar3[0xe] = 0xaa0001bf;
      puVar3[0xf] = 0x5a595500;
      puVar3[0x10] = 0x12;
      puVar3[0x11] = puVar3 + 0x12;
      puVar3[0x12] = local_40;
      puVar3[0x13] = local_3c;
      puVar3[0x14] = local_38;
      puVar3[0x15] = local_34;
      *(undefined1 *)(puVar3 + 0x16) = local_30;
      *(undefined1 *)((int)puVar3 + 0x59) = local_2f;
      *param_2 = puVar3;
      *param_1 = 0;
      param_1[1] = 0;
      return 0;
    }
    FUN_40c13634(0x40c2322c,0,0,param_5);
  }
  return 0x80040240;
}



/* 40c18e04 FUN_40c18e04 */

/* Boundary evidence: original MIPS .pdata 40c18e04..40c18e3b. Semantic name remains unreviewed. */

void FUN_40c18e04(int param_1)

{
  if (param_1 != 0) {
    FUN_40c1e5a0();
    return;
  }
  FUN_40c1e5a0();
  return;
}



/* 40c18e3c FUN_40c18e3c */

/* Boundary evidence: original MIPS .pdata 40c18e3c..40c18eab. Semantic name remains unreviewed. */

void FUN_40c18e3c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40c233f8;
  param_1[3] = &PTR_FUN_40c233a8;
  param_1[4] = &PTR_LAB_40c23370;
  FUN_40c1fec4(param_1 + 0xf);
  FUN_40c1e5a0();
  return;
}



/* 40c18eac FUN_40c18eac */

/* Boundary evidence: original MIPS .pdata 40c18eac..40c18edb. Semantic name remains unreviewed. */

void FUN_40c18eac(void)

{
  int *in_v0;
  
  FUN_40c18e04(*in_v0);
  return;
}



/* 40c18edc FUN_40c18edc */

/* Boundary evidence: original MIPS .pdata 40c18edc..40c18f03. Semantic name remains unreviewed. */

void FUN_40c18edc(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40c18f04 FUN_40c18f04 */

/* Boundary evidence: original MIPS .pdata 40c18f04..40c18f2b. Semantic name remains unreviewed. */

void FUN_40c18f04(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40c18f2c FUN_40c18f2c */

/* Boundary evidence: original MIPS .pdata 40c18f2c..40c18f53. Semantic name remains unreviewed. */

void FUN_40c18f2c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40c18f54 FUN_40c18f54 */

/* Boundary evidence: original MIPS .pdata 40c18f54..40c19043. Semantic name remains unreviewed. */

void FUN_40c18f54(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40c235a8,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40c1e690(piVar2,param_3);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40c24f48,0x10);
    if (iVar1 == 0) {
      piVar2 = param_1 + 4;
      if (param_1 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      FUN_40c1e690(piVar2,param_3);
    }
    else {
      iVar1 = memcmp(param_2,&DAT_40c25354,0x10);
      if (iVar1 == 0) {
        piVar2 = param_1 + 4;
        if (param_1 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        FUN_40c1e690(piVar2,param_3);
      }
      else {
        FUN_40c1e72c(param_1,param_2,param_3);
      }
    }
  }
  return;
}



/* 40c19044 FUN_40c19044 */

/* Boundary evidence: original MIPS .pdata 40c19044..40c1908f. Semantic name remains unreviewed. */

bool FUN_40c19044(int *param_1,uint *param_2)

{
  uint local_10 [2];
  
  (**(code **)(*param_1 + 0xc))(param_1,local_10);
  return (~local_10[0] & *param_2) != 0;
}



/* 40c190b8 FUN_40c190b8 */

/* Boundary evidence: original MIPS .pdata 40c190b8..40c19147. Semantic name remains unreviewed. */

undefined4 FUN_40c190b8(int *param_1,int *param_2)

{
  int iVar1;
  undefined1 auStack_20 [16];
  uint local_10;
  
  local_10 = DAT_40c2618c;
  if (param_2 == (int *)0x0) {
    param_2 = param_1 + 0xd;
  }
  iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,auStack_20);
  if ((-1 < iVar1) && (iVar1 = memcmp(auStack_20,param_2,0x10), iVar1 == 0)) {
    FUN_40c20494(local_10);
    return 0;
  }
  FUN_40c20494(local_10);
  return 1;
}



/* 40c19148 FUN_40c19148 */

/* Boundary evidence: original MIPS .pdata 40c19148..40c191a7. Semantic name remains unreviewed. */

undefined4 FUN_40c19148(int param_1,int *param_2)

{
  if (*(int *)(param_1 + 0x24) == 0 && *(int *)(param_1 + 0x28) == 0) {
    FUN_40c12c94(*(int *)(param_1 + 0x2c));
  }
  *param_2 = *(int *)(param_1 + 0x24);
  param_2[1] = *(int *)(param_1 + 0x28);
  return 0;
}



/* 40c191a8 FUN_40c191a8 */

/* Boundary evidence: original MIPS .pdata 40c191a8..40c191df. Semantic name remains unreviewed. */

undefined4 FUN_40c191a8(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    return 0x80004003;
  }
  uVar1 = FUN_40c12cbc(*(int *)(param_1 + 0x2c));
  return uVar1;
}



/* 40c19208 FUN_40c19208 */

/* Boundary evidence: original MIPS .pdata 40c19208..40c1922b. Semantic name remains unreviewed. */

void FUN_40c19208(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  FUN_40c15b28(*(int *)(param_1 + 0x2c),param_2,param_3,param_4);
  return;
}



/* 40c1926c FUN_40c1926c */

/* Boundary evidence: original MIPS .pdata 40c1926c..40c192bf. Semantic name remains unreviewed. */

undefined4 FUN_40c1926c(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40c12d58(*(int *)(param_1 + 0x28));
  if (iVar1 != 0) {
    *param_2 = 1;
    return 0;
  }
  *param_2 = 0;
  return 0;
}



/* 40c192c0 FUN_40c192c0 */

/* Boundary evidence: original MIPS .pdata 40c192c0..40c192e7. Semantic name remains unreviewed. */

void FUN_40c192c0(int param_1)

{
  (**(code **)(*(int *)(param_1 + -4) + 0x44))();
  return;
}



/* 40c192e8 FUN_40c192e8 */

/* Boundary evidence: original MIPS .pdata 40c192e8..40c1930f. Semantic name remains unreviewed. */

void FUN_40c192e8(int param_1)

{
  (**(code **)(*(int *)(param_1 + -4) + 0x48))();
  return;
}



/* 40c19310 FUN_40c19310 */

/* Boundary evidence: original MIPS .pdata 40c19310..40c1932b. Semantic name remains unreviewed. */

void FUN_40c19310(int param_1,undefined4 *param_2)

{
  FUN_40c1fef4(param_1 + 0x2c,param_2);
  return;
}



/* 40c1932c FUN_40c1932c */

/* Boundary evidence: original MIPS .pdata 40c1932c..40c1935b. Semantic name remains unreviewed. */

void FUN_40c1932c(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  FUN_40c1ff1c((int *)(param_1 + 0x2c),&DAT_40c235a8,param_2,param_3,param_4);
  return;
}



/* 40c1935c FUN_40c1935c */

/* Boundary evidence: original MIPS .pdata 40c1935c..40c1938f. Semantic name remains unreviewed. */

void FUN_40c1935c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_40c200b8((int *)(param_1 + 0x2c),&DAT_40c235a8,param_3,param_4,param_5,param_6);
  return;
}



/* 40c19390 FUN_40c19390 */

/* Boundary evidence: original MIPS .pdata 40c19390..40c19477. Semantic name remains unreviewed. */

int FUN_40c19390(int *param_1,undefined4 param_2,void *param_3,undefined4 param_4,undefined2 param_5
                ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  int *piVar2;
  int *local_18 [2];
  
  iVar1 = memcmp(&DAT_40c25344,param_3,0x10);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_1 + 0x10))(param_1,0,param_4,local_18);
    if (-1 < iVar1) {
      piVar2 = param_1 + -1;
      if (param_1 == (int *)0x10) {
        piVar2 = (int *)0x0;
      }
      iVar1 = (**(code **)(*local_18[0] + 0x2c))
                        (local_18[0],piVar2,param_2,param_5,param_6,param_7,param_8,param_9);
      (**(code **)(*local_18[0] + 8))();
    }
  }
  else {
    iVar1 = -0x7ffdffff;
  }
  return iVar1;
}



/* 40c194b4 FUN_40c194b4 */

/* Boundary evidence: original MIPS .pdata 40c194b4..40c194ff. Semantic name remains unreviewed. */

undefined4 * FUN_40c194b4(undefined4 *param_1,uint param_2)

{
  FUN_40c18e3c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c19500 FUN_40c19500 */

/* Boundary evidence: original MIPS .pdata 40c19500..40c19553. Semantic name remains unreviewed. */

undefined4 FUN_40c19500(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40c12d58(*(int *)(param_1 + 0x2c));
  if (iVar1 != 0) {
    *param_2 = 0x37;
    return 0;
  }
  *param_2 = 0;
  return 0;
}



/* 40c19554 FUN_40c19554 */

/* Boundary evidence: original MIPS .pdata 40c19554..40c195c7. Semantic name remains unreviewed. */

undefined4 FUN_40c19554(int param_1,void *param_2)

{
  int iVar1;
  
  if (param_2 == (void *)0x0) {
    param_2 = (void *)(param_1 + 0x34);
  }
  iVar1 = FUN_40c12d58(*(int *)(param_1 + 0x2c));
  if ((iVar1 != 0) && (iVar1 = FUN_40c12ce4(*(undefined4 *)(param_1 + 0x2c),param_2), iVar1 == 0)) {
    return 0;
  }
  return 1;
}



/* 40c195c8 FUN_40c195c8 */

/* Boundary evidence: original MIPS .pdata 40c195c8..40c1964b. Semantic name remains unreviewed. */

undefined4 FUN_40c195c8(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40c12d58(*(int *)(param_1 + 0x2c));
  if (iVar1 == 0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    uVar2 = 0;
  }
  else {
    *param_2 = 0x7b785574;
    param_2[1] = 0x11cf8c82;
    param_2[2] = 0xaa000cbc;
    uVar2 = 0xf674ac00;
  }
  param_2[3] = uVar2;
  return 0;
}



/* 40c1964c FUN_40c1964c */

/* Boundary evidence: original MIPS .pdata 40c1964c..40c197a3. Semantic name remains unreviewed. */

undefined4 FUN_40c1964c(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    param_2 = param_1 + 0xd;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = memcmp(param_2,param_1 + 0xd,0x10);
    if (iVar1 != 0) {
      iVar1 = FUN_40c12d58(param_1[0xb]);
      if ((iVar1 == 0) || (iVar1 = FUN_40c12d30(param_1[0xb],param_2), iVar1 != 0)) {
        return 0x80004005;
      }
      (**(code **)(*param_1 + 0x34))(param_1,param_1 + 5,param_2);
      (**(code **)(*param_1 + 0x34))(param_1,param_1 + 7,param_2);
      param_1[0xd] = *param_2;
      param_1[0xe] = param_2[1];
      param_1[0xf] = param_2[2];
      param_1[0x10] = param_2[3];
      FUN_40c1b120();
    }
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40c24ca8,0x10);
    if (iVar1 != 0) {
      return 0x80004001;
    }
  }
  return 0;
}



/* 40c197a4 FUN_40c197a4 */

/* Boundary evidence: original MIPS .pdata 40c197a4..40c1980f. Semantic name remains unreviewed. */

undefined4 FUN_40c197a4(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40c12d58(*(int *)(param_1 + 0x2c));
  if (iVar1 == 0) {
    *param_2 = 0xffffffff;
    param_2[1] = 0x7fffffff;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x14);
    param_2[1] = *(undefined4 *)(param_1 + 0x18);
  }
  return 0;
}



/* 40c19810 FUN_40c19810 */

/* Boundary evidence: original MIPS .pdata 40c19810..40c19a17. Semantic name remains unreviewed. */

undefined4
FUN_40c19810(int *param_1,uint *param_2,int *param_3,undefined4 param_4,uint param_5,uint param_6,
            int *param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_v1;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  iVar1 = FUN_40c12d58(param_1[0xb]);
  if (iVar1 == 0) {
    return 1;
  }
  if (param_3 == (int *)0x0) {
    param_3 = param_1 + 0xd;
  }
  if (param_7 == (int *)0x0) {
    param_7 = param_1 + 0xd;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_3);
  if ((iVar1 != 0) || (iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_7), iVar1 != 0)) {
    return 0x80004005;
  }
  iVar1 = memcmp(param_3,param_7,0x10);
  if (iVar1 == 0) {
    *param_2 = param_5;
    param_2[1] = param_6;
    return 0;
  }
  FUN_40c12c94(param_1[0xb]);
  FUN_40c12c94(param_1[0xb]);
  if ((param_5 != local_20) || (uVar2 = local_28, uVar3 = local_24, param_6 != local_1c)) {
    if (param_5 == 0 && param_6 == 0) {
      uVar2 = 0;
      uVar3 = 0;
      goto LAB_40c1993c;
    }
    if (((int)local_24 < (int)local_1c) || ((local_24 == local_1c && (local_28 <= local_20)))) {
      uVar2 = 0;
      uVar3 = 0;
    }
    else {
      uVar2 = local_20 - 1;
      uVar3 = local_1c - (local_20 == 0);
    }
    uVar2 = FUN_40c1a178(param_5,param_6,local_28,local_24,local_20,local_1c,uVar2,uVar3);
    uVar3 = extraout_v1;
  }
  if (((int)uVar3 < 1) && (uVar3 != 0)) {
    *param_2 = 0;
    param_2[1] = 0;
    return 0;
  }
LAB_40c1993c:
  if (((int)local_24 <= (int)uVar3) && ((uVar3 != local_24 || (local_28 < uVar2)))) {
    uVar2 = local_28;
    uVar3 = local_24;
  }
  *param_2 = uVar2;
  param_2[1] = uVar3;
  return 0;
}



/* 40c19a18 FUN_40c19a18 */

/* Boundary evidence: original MIPS .pdata 40c19a18..40c19b6b. Semantic name remains unreviewed. */

undefined4 FUN_40c19a18(int *param_1,int *param_2,uint param_3,int *param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar3 = param_2;
  iVar1 = FUN_40c12d58(param_1[0xb]);
  if (iVar1 != 0) {
    iVar1 = param_1[7];
    iVar5 = param_1[8];
    uVar4 = param_3 & 3;
    if (uVar4 == 1) {
      iVar1 = *param_2;
      iVar5 = param_2[1];
    }
    else {
      if (uVar4 == 2) {
        return 0x80004001;
      }
      if (uVar4 == 3) {
        return 0x80004001;
      }
    }
    iVar6 = param_1[5];
    uVar4 = param_5 & 3;
    iVar7 = param_1[6];
    if ((uVar4 == 1) || ((uVar4 != 2 && (uVar4 != 3)))) {
      if ((param_3 & 8) != 0) {
        (**(code **)(*param_1 + 0x34))(param_1,param_2,&DAT_40c24cf8);
        piVar3 = param_2;
      }
      if ((param_5 & 8) != 0) {
        (**(code **)(*param_1 + 0x34))(param_1,param_4,&DAT_40c24cf8);
        piVar3 = param_4;
      }
      uVar2 = FUN_40c15a68(param_1[0xb],piVar3,iVar1,iVar5,iVar6,iVar7);
      return uVar2;
    }
  }
  return 0x80004001;
}



/* 40c19b6c FUN_40c19b6c */

/* Boundary evidence: original MIPS .pdata 40c19b6c..40c19bfb. Semantic name remains unreviewed. */

undefined4 FUN_40c19b6c(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_40c12d58(param_1[0xb]);
  *param_2 = 0;
  param_2[1] = 0;
  if (iVar1 == 0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0x7fffffff;
  }
  else {
    uVar2 = (**(code **)(*param_1 + 0x28))(param_1,param_3);
  }
  return uVar2;
}



/* 40c19bfc FUN_40c19bfc */

/* Boundary evidence: original MIPS .pdata 40c19bfc..40c19d0f. Semantic name remains unreviewed. */

undefined4 * FUN_40c19bfc(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  FUN_40c1e634(param_1,0,param_3);
  param_1[3] = &PTR_FUN_40c233a8;
  param_1[4] = &PTR_LAB_40c23370;
  *param_1 = &PTR_FUN_40c233f8;
  param_1[6] = 0;
  param_1[7] = 0x3ff00000;
  param_1[8] = 0xffffffff;
  param_1[9] = 0x7fffffff;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = param_2;
  param_1[0xf] = 0;
  param_1[0x10] = 0x7b785574;
  param_1[0x11] = 0x11cf8c82;
  param_1[0x12] = 0xaa000cbc;
  param_1[0x13] = 0xf674ac00;
  FUN_40c12c94(param_1[0xe]);
  iVar1 = param_1[0xc];
  if (iVar1 != 0 || param_1[0xd] != 0) {
    param_1[8] = iVar1;
    param_1[9] = param_1[0xd];
  }
  return param_1;
}



/* 40c19d10 FUN_40c19d10 */

/* Boundary evidence: original MIPS .pdata 40c19d10..40c19d3f. Semantic name remains unreviewed. */

void FUN_40c19d10(void)

{
  int *in_v0;
  
  FUN_40c18e04(*in_v0);
  return;
}



/* 40c19d40 FUN_40c19d40 */

/* Boundary evidence: original MIPS .pdata 40c19d40..40c19d73. Semantic name remains unreviewed. */

void FUN_40c19d40(void)

{
  int *in_v0;
  
  FUN_40c1fec4((int *)(*in_v0 + 0x3c));
  return;
}



/* 40c19d74 FUN_40c19d74 */

/* Boundary evidence: original MIPS .pdata 40c19d74..40c1a033. Semantic name remains unreviewed. */

void FUN_40c19d74(undefined4 param_1,int param_2)

{
  LSTATUS LVar1;
  uint uVar2;
  DWORD local_38;
  DWORD local_34;
  HKEY local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20 [2];
  
  if (DAT_40c2617c == 0xffffffff) {
    DAT_40c26180 = 0xfa;
    DAT_40c2617c = 0xf9;
    DAT_40c26184 = 0xfb;
    DAT_40c26188 = 0xfc;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SOFTWARE\\Microsoft\\DirectShow\\ThreadPriority",0,0,
                          &local_30);
    if (LVar1 == 0) {
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Highest",(LPDWORD)0x0,&local_34,(LPBYTE)&local_28,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_28)) {
        local_28 = DAT_40c2617c;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"AboveNormal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_2c,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_2c)) {
        local_2c = DAT_40c26180;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Normal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_24,&local_38
                              );
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_24)) {
        local_24 = DAT_40c26184;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"BelowNormal",(LPDWORD)0x0,&local_34,(LPBYTE)local_20,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_20[0])) {
        local_20[0] = DAT_40c26188;
      }
      if (((local_28 <= local_2c) && (local_2c <= local_24)) && (local_24 <= local_20[0])) {
        DAT_40c2617c = local_28;
        DAT_40c26180 = local_2c;
        DAT_40c26184 = local_24;
        DAT_40c26188 = local_20[0];
      }
      RegCloseKey(local_30);
    }
  }
  uVar2 = DAT_40c2617c;
  if (((param_2 != 1) && (uVar2 = DAT_40c26180, param_2 != 2)) &&
     (uVar2 = DAT_40c26188, param_2 != 4)) {
    uVar2 = DAT_40c26184;
  }
  CeSetThreadPriority(param_1,uVar2);
  return;
}



/* 40c1a034 FUN_40c1a034 */

/* Boundary evidence: original MIPS .pdata 40c1a034..40c1a073. Semantic name remains unreviewed. */

undefined4 * FUN_40c1a034(undefined4 *param_1,BOOL param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,param_2,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return param_1;
}



/* 40c1a074 FUN_40c1a074 */

/* Boundary evidence: original MIPS .pdata 40c1a074..40c1a0a3. Semantic name remains unreviewed. */

void FUN_40c1a074(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
  }
  return;
}



/* 40c1a0a4 FUN_40c1a0a4 */

/* Boundary evidence: original MIPS .pdata 40c1a0a4..40c1a0c7. Semantic name remains unreviewed. */

void FUN_40c1a0a4(undefined4 *param_1)

{
  (**(code **)*param_1)();
  return;
}



/* 40c1a0c8 FUN_40c1a0c8 */

/* Boundary evidence: original MIPS .pdata 40c1a0c8..40c1a13b. Semantic name remains unreviewed. */

undefined4 FUN_40c1a0c8(void)

{
  HMODULE pHVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  uVar3 = 0x80004005;
  pHVar1 = GetModuleHandleW(L"ole32.dll");
  if ((pHVar1 != (HMODULE)0x0) &&
     (pcVar2 = (code *)GetProcAddressW(pHVar1,L"CoInitializeEx"), pcVar2 != (code *)0x0)) {
    uVar3 = (*pcVar2)(0,0);
  }
  return uVar3;
}



/* 40c1a13c FUN_40c1a13c */

short * FUN_40c1a13c(short *param_1,short *param_2,int param_3)

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



/* 40c1a178 FUN_40c1a178 */

/* WARNING: Removing unreachable block (ram,0x40c1a3ec) */
/* Boundary evidence: original MIPS .pdata 40c1a178..40c1a593. Semantic name remains unreviewed. */

int FUN_40c1a178(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                uint param_7,uint param_8)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  uVar15 = param_2;
  if ((int)param_2 < 0) {
    bVar2 = param_1 != 0;
    param_1 = -param_1;
    uVar15 = -(uint)bVar2 - param_2;
  }
  uVar12 = param_4;
  if ((int)param_4 < 0) {
    bVar2 = param_3 != 0;
    param_3 = -param_3;
    uVar12 = -(uint)bVar2 - param_4;
  }
  uVar14 = param_6;
  if ((int)param_6 < 0) {
    uVar14 = -(uint)(param_5 != 0) - param_6;
    param_5 = -param_5;
  }
  if ((0 < (int)param_2) || (bVar3 = 1, param_2 == 0)) {
    bVar3 = 0;
  }
  if ((0 < (int)param_4) || (bVar4 = 1, param_4 == 0)) {
    bVar4 = 0;
  }
  uVar13 = (uint)((ulonglong)param_1 * (ulonglong)param_3);
  bVar2 = (bool)(bVar4 ^ bVar3);
  uVar5 = (ulonglong)param_1 * (ulonglong)uVar12 +
          (ulonglong)uVar15 * (ulonglong)param_3 + ((ulonglong)param_1 * (ulonglong)param_3 >> 0x20)
  ;
  uVar16 = (uint)uVar5;
  uVar5 = (ulonglong)uVar15 * (ulonglong)uVar12 + (uVar5 >> 0x20);
  iVar8 = -1;
  uVar15 = uVar13;
  if (param_7 == 0 && param_8 == 0) goto LAB_40c1a3b4;
  iVar11 = iVar8;
  if (bVar2) {
    uVar15 = -param_7;
    uVar12 = -(uint)(param_7 != 0) - param_8;
    if ((int)param_8 < 0) goto LAB_40c1a2fc;
    bVar1 = param_8 == 0;
    param_8 = param_7;
    if (bVar1) goto joined_r0x40c1a364;
  }
  else {
    uVar15 = param_7;
    uVar12 = param_8;
    if ((int)param_8 < 1) {
joined_r0x40c1a364:
      if (param_8 != 0) goto LAB_40c1a304;
    }
LAB_40c1a2fc:
    iVar11 = 0;
  }
LAB_40c1a304:
  uVar15 = uVar13 + uVar15;
  uVar10 = uVar12 + uVar16;
  uVar16 = uVar10 + (uVar15 < uVar13);
  uVar13 = (uint)(uVar10 < uVar12) + (uint)(uVar16 < uVar10);
  uVar12 = uVar13 + iVar11;
  lVar6 = CONCAT44(iVar11 + (uint)(uVar12 < uVar13),uVar12);
  lVar7 = uVar5 + lVar6;
  uVar5 = uVar5 + lVar6;
  if (lVar7 < 0) {
    bVar2 = !bVar2;
    uVar12 = ~uVar15;
    uVar15 = uVar12 + 1;
    uVar16 = ~uVar16 + (uint)(uVar15 < uVar12);
    uVar12 = (uint)(uVar15 == 0 && uVar16 == 0);
    uVar13 = uVar12 + ~(uint)lVar7;
    uVar5 = CONCAT44(~(uint)((ulonglong)lVar7 >> 0x20) + (uint)(uVar13 < uVar12),uVar13);
  }
LAB_40c1a3b4:
  if (((int)param_6 < 1) && (param_6 != 0)) {
    if (bVar2) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
  }
  if (uVar5 < CONCAT44(uVar14,param_5)) {
    if (uVar5 == 0) {
      iVar8 = __ull_div(uVar15,uVar16,param_5,uVar14);
    }
    else {
      if (uVar14 == 0) {
        __ull_div(uVar16,(int)uVar5,param_5,0);
        uVar9 = __ull_rem(uVar16,(int)uVar5,param_5,0);
        iVar8 = __ull_div(uVar15,uVar9,param_5,0);
        if (!bVar2) {
          return iVar8;
        }
        return -iVar8;
      }
      iVar8 = 0;
      iVar11 = 0x40;
      do {
        iVar8 = iVar8 * 2;
        uVar13 = (uint)uVar5 * 2;
        uVar12 = (int)(uVar5 >> 0x20) << 1 | (uint)uVar5 >> 0x1f;
        if ((uVar16 & 0x80000000) != 0) {
          uVar13 = uVar13 + 1;
        }
        uVar10 = uVar15 >> 0x1f;
        uVar15 = uVar15 << 1;
        uVar16 = uVar16 << 1 | uVar10;
        uVar10 = uVar13;
        if ((uVar14 <= uVar12) && ((uVar14 != uVar12 || (param_5 <= uVar13)))) {
          iVar8 = iVar8 + 1;
          uVar10 = uVar13 - param_5;
          uVar12 = (uVar12 - uVar14) - (uint)(uVar13 < param_5);
        }
        uVar5 = CONCAT44(uVar12,uVar10);
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    if (bVar2) {
      iVar8 = -iVar8;
    }
  }
  else if (bVar2) {
    iVar8 = 0;
  }
  return iVar8;
}



/* 40c1a594 FUN_40c1a594 */

/* Boundary evidence: original MIPS .pdata 40c1a594..40c1a61f. Semantic name remains unreviewed. */

undefined4 FUN_40c1a594(wchar_t *param_1,undefined4 *param_2)

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



/* 40c1a620 FUN_40c1a620 */

/* Boundary evidence: original MIPS .pdata 40c1a620..40c1a69b. Semantic name remains unreviewed. */

int FUN_40c1a620(int param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  *(HANDLE *)(param_1 + 4) = pvVar1;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)(param_1 + 8) = pvVar1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x14) = 0;
  return param_1;
}



/* 40c1a69c FUN_40c1a69c */

/* Boundary evidence: original MIPS .pdata 40c1a69c..40c1a70b. Semantic name remains unreviewed. */

void FUN_40c1a69c(int param_1)

{
  FUN_40c1101c(param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  if (*(HANDLE *)(param_1 + 8) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 8));
  }
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 4));
  }
  return;
}



/* 40c1a70c FUN_40c1a70c */

/* Boundary evidence: original MIPS .pdata 40c1a70c..40c1a7bf. Semantic name remains unreviewed. */

bool FUN_40c1a70c(LPVOID param_1)

{
  HANDLE pvVar1;
  bool bVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD aDStack_18 [2];
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)param_1 + 0x14) == 0) {
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40c1a0a4,param_1,0,aDStack_18);
    if (pvVar1 != (HANDLE)0x0) {
      FUN_40c19d74(pvVar1,3);
    }
    bVar2 = pvVar1 != (HANDLE)0x0;
    *(HANDLE *)((int)param_1 + 0x14) = pvVar1;
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
    bVar2 = false;
  }
  return bVar2;
}



/* 40c1a7c0 FUN_40c1a7c0 */

/* Boundary evidence: original MIPS .pdata 40c1a7c0..40c1a84b. Semantic name remains unreviewed. */

undefined4 FUN_40c1a7c0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = param_2;
    EventModify(*(undefined4 *)(param_1 + 4),3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 8),0xffffffff);
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return uVar1;
}



/* 40c1a84c FUN_40c1a84c */

/* Boundary evidence: original MIPS .pdata 40c1a84c..40c1a883. Semantic name remains unreviewed. */

undefined4 FUN_40c1a84c(int param_1)

{
  WaitForSingleObject(*(HANDLE *)(param_1 + 4),0xffffffff);
  return *(undefined4 *)(param_1 + 0xc);
}



/* 40c1a884 FUN_40c1a884 */

/* Boundary evidence: original MIPS .pdata 40c1a884..40c1a8e7. Semantic name remains unreviewed. */

undefined4 FUN_40c1a884(int param_1,undefined4 *param_2)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 4),0);
  if (DVar1 == 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0xc);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40c1a8e8 FUN_40c1a8e8 */

/* Boundary evidence: original MIPS .pdata 40c1a8e8..40c1a923. Semantic name remains unreviewed. */

void FUN_40c1a8e8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  EventModify(*(undefined4 *)(param_1 + 4),2);
  EventModify(*(undefined4 *)(param_1 + 8),3);
  return;
}



/* 40c1a98c FUN_40c1a98c */

/* Boundary evidence: original MIPS .pdata 40c1a98c..40c1aa17. Semantic name remains unreviewed. */

undefined4 FUN_40c1a98c(int param_1,short *param_2)

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
      FUN_40c1a13c(param_2,*(short **)(param_1 + 0x30),0x80);
    }
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x34);
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x34) + 4))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40c1aa18 FUN_40c1aa18 */

/* Boundary evidence: original MIPS .pdata 40c1aa18..40c1aa57. Semantic name remains unreviewed. */

undefined4 FUN_40c1aa18(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x44) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x44) + 0xc))();
  }
  return uVar1;
}



/* 40c1aa60 FUN_40c1aa60 */

/* Boundary evidence: original MIPS .pdata 40c1aa60..40c1aa7b. Semantic name remains unreviewed. */

void FUN_40c1aa60(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x48));
  return;
}



/* 40c1aa7c FUN_40c1aa7c */

/* Boundary evidence: original MIPS .pdata 40c1aa7c..40c1aac7. Semantic name remains unreviewed. */

void FUN_40c1aa7c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40c250b8;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 8))();
  FUN_40c1eb20(param_1 + 6);
  return;
}



/* 40c1aac8 FUN_40c1aac8 */

/* Boundary evidence: original MIPS .pdata 40c1aac8..40c1ab5f. Semantic name remains unreviewed. */

undefined4 FUN_40c1aac8(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40c234c8,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40c25364,0x10), iVar2 == 0)) {
      uVar1 = FUN_40c1e690(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40c1ab60 FUN_40c1ab60 */

/* Boundary evidence: original MIPS .pdata 40c1ab60..40c1ab7b. Semantic name remains unreviewed. */

void FUN_40c1ab60(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



/* 40c1ab7c FUN_40c1ab7c */

/* Boundary evidence: original MIPS .pdata 40c1ab7c..40c1abd7. Semantic name remains unreviewed. */

LONG FUN_40c1ab7c(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40c1abd8 FUN_40c1abd8 */

/* Boundary evidence: original MIPS .pdata 40c1abd8..40c1ac37. Semantic name remains unreviewed. */

undefined4 FUN_40c1abd8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_40c1e8a8((undefined4 *)(param_1 + 0x18));
  return 0;
}



/* 40c1ac38 FUN_40c1ac38 */

/* Boundary evidence: original MIPS .pdata 40c1ac38..40c1ac8f. Semantic name remains unreviewed. */

undefined4 FUN_40c1ac38(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  return 0;
}



/* 40c1ac90 FUN_40c1ac90 */

/* Boundary evidence: original MIPS .pdata 40c1ac90..40c1ad27. Semantic name remains unreviewed. */

undefined4 FUN_40c1ac90(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40c234d8,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40c25364,0x10), iVar2 == 0)) {
      uVar1 = FUN_40c1e690(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40c1ad28 FUN_40c1ad28 */

/* Boundary evidence: original MIPS .pdata 40c1ad28..40c1ad43. Semantic name remains unreviewed. */

void FUN_40c1ad28(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



/* 40c1ad44 FUN_40c1ad44 */

/* Boundary evidence: original MIPS .pdata 40c1ad44..40c1ad9f. Semantic name remains unreviewed. */

LONG FUN_40c1ad44(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40c1ada0 FUN_40c1ada0 */

/* Boundary evidence: original MIPS .pdata 40c1ada0..40c1addf. Semantic name remains unreviewed. */

undefined4 FUN_40c1ada0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return 0;
}



/* 40c1ade0 FUN_40c1ade0 */

/* Boundary evidence: original MIPS .pdata 40c1ade0..40c1ae23. Semantic name remains unreviewed. */

void FUN_40c1ade0(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x14));
  }
  FUN_40c1ed78(param_1 + 0x1c);
  FUN_40c1e5a0();
  return;
}



/* 40c1ae24 FUN_40c1ae24 */

/* Boundary evidence: original MIPS .pdata 40c1ae24..40c1aecb. Semantic name remains unreviewed. */

void FUN_40c1ae24(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40c234b8,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40c235f8,0x10);
    if (iVar1 != 0) {
      FUN_40c1e72c(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40c1e690(piVar2,param_3);
  return;
}



/* 40c1aecc FUN_40c1aecc */

/* Boundary evidence: original MIPS .pdata 40c1aecc..40c1aef7. Semantic name remains unreviewed. */

void FUN_40c1aecc(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 4))();
  return;
}



/* 40c1aef8 FUN_40c1aef8 */

/* Boundary evidence: original MIPS .pdata 40c1aef8..40c1af23. Semantic name remains unreviewed. */

void FUN_40c1aef8(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 8))();
  return;
}



/* 40c1af24 FUN_40c1af24 */

/* Boundary evidence: original MIPS .pdata 40c1af24..40c1af43. Semantic name remains unreviewed. */

undefined4 FUN_40c1af24(int param_1,void *param_2)

{
  FUN_40c1eeb8((void *)(param_1 + 0x1c),param_2);
  return 0;
}



/* 40c1af44 FUN_40c1af44 */

/* Boundary evidence: original MIPS .pdata 40c1af44..40c1af9b. Semantic name remains unreviewed. */

undefined4 FUN_40c1af44(int param_1,int *param_2)

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



/* 40c1af9c FUN_40c1af9c */

/* Boundary evidence: original MIPS .pdata 40c1af9c..40c1afef. Semantic name remains unreviewed. */

undefined4 FUN_40c1af9c(int param_1,int *param_2)

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



/* 40c1aff0 FUN_40c1aff0 */

/* Boundary evidence: original MIPS .pdata 40c1aff0..40c1b09b. Semantic name remains unreviewed. */

undefined4 FUN_40c1aff0(int param_1,int *param_2)

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
      FUN_40c1a13c((short *)(param_2 + 2),*(short **)(param_1 + 8),0x80);
    }
    uVar1 = 0;
    param_2[1] = *(int *)(param_1 + 0x58);
  }
  return uVar1;
}



/* 40c1b0c4 FUN_40c1b0c4 */

/* Boundary evidence: original MIPS .pdata 40c1b0c4..40c1b10b. Semantic name remains unreviewed. */

int FUN_40c1b0c4(int param_1,int param_2)

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



/* 40c1b120 FUN_40c1b120 */

undefined4 FUN_40c1b120(void)

{
  return 0;
}



/* 40c1b128 FUN_40c1b128 */

/* Boundary evidence: original MIPS .pdata 40c1b128..40c1b177. Semantic name remains unreviewed. */

undefined4 FUN_40c1b128(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x58);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 100) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40c1b1b4 FUN_40c1b1b4 */

/* Boundary evidence: original MIPS .pdata 40c1b1b4..40c1b1db. Semantic name remains unreviewed. */

void FUN_40c1b1b4(int *param_1)

{
  (**(code **)(*param_1 + 0x38))(param_1,param_1[0x27],param_1 + 0x26);
  return;
}



/* 40c1b1dc FUN_40c1b1dc */

/* Boundary evidence: original MIPS .pdata 40c1b1dc..40c1b243. Semantic name remains unreviewed. */

int FUN_40c1b1dc(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40c1af44(param_1,param_2);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)*param_2)(param_2,&DAT_40c23588,param_1 + 0x9c), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40c1b244 FUN_40c1b244 */

/* Boundary evidence: original MIPS .pdata 40c1b244..40c1b2a7. Semantic name remains unreviewed. */

undefined4 FUN_40c1b244(int param_1)

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



/* 40c1b2a8 FUN_40c1b2a8 */

/* Boundary evidence: original MIPS .pdata 40c1b2a8..40c1b2e3. Semantic name remains unreviewed. */

void FUN_40c1b2a8(undefined4 param_1,LPVOID *param_2)

{
  CoCreateInstance((IID *)&DAT_40c24658,(LPUNKNOWN)0x0,1,(IID *)&DAT_40c23568,param_2);
  return;
}



/* 40c1b2e4 FUN_40c1b2e4 */

/* Boundary evidence: original MIPS .pdata 40c1b2e4..40c1b46f. Semantic name remains unreviewed. */

int FUN_40c1b2e4(int *param_1,int *param_2,int *param_3)

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



/* 40c1b470 FUN_40c1b470 */

/* Boundary evidence: original MIPS .pdata 40c1b470..40c1b4b7. Semantic name remains unreviewed. */

undefined4 FUN_40c1b470(int param_1)

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



/* 40c1b4b8 FUN_40c1b4b8 */

/* Boundary evidence: original MIPS .pdata 40c1b4b8..40c1b4f7. Semantic name remains unreviewed. */

undefined4 FUN_40c1b4b8(int param_1)

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



/* 40c1b4f8 FUN_40c1b4f8 */

/* Boundary evidence: original MIPS .pdata 40c1b4f8..40c1b537. Semantic name remains unreviewed. */

undefined4 FUN_40c1b4f8(int param_1)

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



/* 40c1b538 FUN_40c1b538 */

/* Boundary evidence: original MIPS .pdata 40c1b538..40c1b577. Semantic name remains unreviewed. */

undefined4 FUN_40c1b538(int param_1)

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



/* 40c1b578 FUN_40c1b578 */

/* Boundary evidence: original MIPS .pdata 40c1b578..40c1b5c3. Semantic name remains unreviewed. */

bool FUN_40c1b578(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  return iVar1 != *(int *)(param_1 + 0x10);
}



/* 40c1b5c4 FUN_40c1b5c4 */

/* Boundary evidence: original MIPS .pdata 40c1b5c4..40c1b60f. Semantic name remains unreviewed. */

bool FUN_40c1b5c4(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  return iVar1 != *(int *)(param_1 + 0xc);
}



/* 40c1b610 FUN_40c1b610 */

/* Boundary evidence: original MIPS .pdata 40c1b610..40c1b66b. Semantic name remains unreviewed. */

undefined4 FUN_40c1b610(int param_1)

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



/* 40c1b66c FUN_40c1b66c */

/* Boundary evidence: original MIPS .pdata 40c1b66c..40c1b6b3. Semantic name remains unreviewed. */

void FUN_40c1b66c(int param_1)

{
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40c1ade0(param_1);
  return;
}



/* 40c1b6b4 FUN_40c1b6b4 */

/* Boundary evidence: original MIPS .pdata 40c1b6b4..40c1b733. Semantic name remains unreviewed. */

void FUN_40c1b6b4(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40c23588,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x26;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40c1e690(piVar2,param_3);
  }
  else {
    FUN_40c1ae24(param_1,param_2,param_3);
  }
  return;
}



/* 40c1b734 FUN_40c1b734 */

/* Boundary evidence: original MIPS .pdata 40c1b734..40c1b7fb. Semantic name remains unreviewed. */

HRESULT FUN_40c1b734(int param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 != (undefined4 *)0x0) {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    ppv = (LPVOID *)(param_1 + 4);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_40c24658,(LPUNKNOWN)0x0,1,(IID *)&DAT_40c23568,ppv),
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



/* 40c1b7fc FUN_40c1b7fc */

/* Boundary evidence: original MIPS .pdata 40c1b7fc..40c1b89b. Semantic name remains unreviewed. */

undefined4 FUN_40c1b7fc(int param_1,int *param_2,undefined1 param_3)

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



/* 40c1b89c FUN_40c1b89c */

/* Boundary evidence: original MIPS .pdata 40c1b89c..40c1b937. Semantic name remains unreviewed. */

int FUN_40c1b89c(int *param_1,int param_2,int param_3,int *param_4)

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



/* 40c1b938 FUN_40c1b938 */

/* Boundary evidence: original MIPS .pdata 40c1b938..40c1b97f. Semantic name remains unreviewed. */

undefined4 FUN_40c1b938(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40c1b980 FUN_40c1b980 */

/* Boundary evidence: original MIPS .pdata 40c1b980..40c1b9c3. Semantic name remains unreviewed. */

undefined4 FUN_40c1b980(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40c1b9e4 FUN_40c1b9e4 */

/* Boundary evidence: original MIPS .pdata 40c1b9e4..40c1ba23. Semantic name remains unreviewed. */

undefined4 FUN_40c1b9e4(int param_1)

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



/* 40c1ba78 FUN_40c1ba78 */

/* Boundary evidence: original MIPS .pdata 40c1ba78..40c1bccf. Semantic name remains unreviewed. */

int FUN_40c1ba78(undefined4 *param_1,int *param_2,int param_3)

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
              if (iVar1 < 0) goto LAB_40c1bc98;
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
LAB_40c1bc98:
    if (iVar1 == -0x7ff8fffe) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40c1bcd0 FUN_40c1bcd0 */

/* Boundary evidence: original MIPS .pdata 40c1bcd0..40c1bdaf. Semantic name remains unreviewed. */

void FUN_40c1bcd0(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40c23518,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40c23508,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40c25374,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40c23598,0x10);
    if (iVar1 != 0) {
      FUN_40c1e72c(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40c1e690(piVar2,param_3);
  return;
}



/* 40c1bdb0 FUN_40c1bdb0 */

/* Boundary evidence: original MIPS .pdata 40c1bdb0..40c1be0b. Semantic name remains unreviewed. */

void FUN_40c1bdb0(int param_1)

{
  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x3c));
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  FUN_40c1e5a0();
  return;
}



/* 40c1be0c FUN_40c1be0c */

/* Boundary evidence: original MIPS .pdata 40c1be0c..40c1be8f. Semantic name remains unreviewed. */

undefined4 FUN_40c1be0c(int param_1,int *param_2)

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



/* 40c1be90 FUN_40c1be90 */

/* Boundary evidence: original MIPS .pdata 40c1be90..40c1bf13. Semantic name remains unreviewed. */

undefined4 FUN_40c1be90(int param_1,undefined4 *param_2)

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



/* 40c1bf14 FUN_40c1bf14 */

/* Boundary evidence: original MIPS .pdata 40c1bf14..40c1bf9b. Semantic name remains unreviewed. */

int FUN_40c1bf14(int param_1,uint *param_2)

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



/* 40c1bf9c FUN_40c1bf9c */

/* Boundary evidence: original MIPS .pdata 40c1bf9c..40c1c0b3. Semantic name remains unreviewed. */

undefined4 FUN_40c1bf9c(int param_1,LPCWSTR param_2,int *param_3)

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
          goto LAB_40c1c05c;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    *param_3 = 0;
    uVar4 = 0x80040216;
LAB_40c1c05c:
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar4;
}



/* 40c1c0b4 FUN_40c1c0b4 */

/* Boundary evidence: original MIPS .pdata 40c1c0b4..40c1c1cf. Semantic name remains unreviewed. */

undefined4 FUN_40c1c0b4(int param_1,undefined4 *param_2,wchar_t *param_3)

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
    iVar1 = (**(code **)*param_2)(param_2,&DAT_40c23628,(undefined4 *)(param_1 + 0x38));
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



/* 40c1c1d0 FUN_40c1c1d0 */

/* Boundary evidence: original MIPS .pdata 40c1c1d0..40c1c2a3. Semantic name remains unreviewed. */

undefined4 FUN_40c1c1d0(int param_1)

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
    HVar3 = CoCreateInstance((IID *)&DAT_40c24118,(LPUNKNOWN)0x0,1,(IID *)&DAT_40c235e8,local_10);
    if (-1 < HVar3) {
      FUN_40c1ba78(puVar1,local_10[0],1);
      (**(code **)(*local_10[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    uVar2 = 0;
  }
  return uVar2;
}



/* 40c1c2a4 FUN_40c1c2a4 */

/* Boundary evidence: original MIPS .pdata 40c1c2a4..40c1c397. Semantic name remains unreviewed. */

int FUN_40c1c2a4(int param_1)

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
    HVar2 = CoCreateInstance((IID *)&DAT_40c24118,(LPUNKNOWN)0x0,1,(IID *)&DAT_40c235e8,local_18);
    if (-1 < HVar2) {
      HVar2 = FUN_40c1ba78(puVar1,local_18[0],0);
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



/* 40c1c398 FUN_40c1c398 */

/* Boundary evidence: original MIPS .pdata 40c1c398..40c1c3e3. Semantic name remains unreviewed. */

undefined4 * FUN_40c1c398(undefined4 *param_1,uint param_2)

{
  FUN_40c1aa7c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c1c3e4 FUN_40c1c3e4 */

/* Boundary evidence: original MIPS .pdata 40c1c3e4..40c1c57b. Semantic name remains unreviewed. */

undefined4 FUN_40c1c3e4(int param_1,uint param_2,int *param_3,uint *param_4)

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
    bVar1 = FUN_40c1b578(param_1);
    uVar4 = 1;
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40c1ac38(param_1);
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
        iVar3 = FUN_40c1e924((int *)(param_1 + 0x18),iVar2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar6 = uVar6 + 1;
          param_3 = param_3 + 1;
          FUN_40c1ea24((int *)(param_1 + 0x18),iVar2);
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



/* 40c1c57c FUN_40c1c57c */

/* Boundary evidence: original MIPS .pdata 40c1c57c..40c1c5f7. Semantic name remains unreviewed. */

undefined4 FUN_40c1c57c(int param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_40c1b578(param_1);
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



/* 40c1c5f8 FUN_40c1c5f8 */

/* Boundary evidence: original MIPS .pdata 40c1c5f8..40c1c65b. Semantic name remains unreviewed. */

undefined4 * FUN_40c1c5f8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40c250d8;
  (**(code **)(*(int *)(param_1[2] + 0xc) + 8))();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c1c65c FUN_40c1c65c */

/* Boundary evidence: original MIPS .pdata 40c1c65c..40c1c7ef. Semantic name remains unreviewed. */

uint FUN_40c1c65c(int param_1,uint param_2,undefined4 *param_3,int *param_4)

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
  
  local_28 = DAT_40c2618c;
  if (param_3 == (undefined4 *)0x0) {
    FUN_40c20494(DAT_40c2618c);
    uVar3 = 0x80004003;
  }
  else {
    bVar1 = FUN_40c1b5c4(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40c20494(local_28);
      uVar3 = 0x80040203;
    }
    else {
      if (param_4 == (int *)0x0) {
        if (1 < param_2) {
          FUN_40c20494(local_28);
          return 0x80070057;
        }
      }
      else {
        *param_4 = 0;
      }
      iVar4 = 0;
      for (; param_2 != 0; param_2 = param_2 - 1) {
        FUN_40c1ed94(auStack_70);
        iVar2 = *(int *)(param_1 + 4);
        *(int *)(param_1 + 4) = iVar2 + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                          (*(int **)(param_1 + 8),iVar2,auStack_70);
        if (iVar2 != 0) {
LAB_40c1c79c:
          FUN_40c1ed78((int)auStack_70);
          break;
        }
        _Dst = CoTaskMemAlloc(0x48);
        *param_3 = _Dst;
        if (_Dst == (LPVOID)0x0) goto LAB_40c1c79c;
        memcpy(_Dst,auStack_70,0x48);
        local_2c = 0;
        local_30 = 0;
        local_34 = 0;
        param_3 = param_3 + 1;
        iVar4 = iVar4 + 1;
        FUN_40c1ed78((int)auStack_70);
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar4;
      }
      uVar3 = (uint)(param_2 != 0);
      FUN_40c20494(local_28);
    }
  }
  return uVar3;
}



/* 40c1c7f0 FUN_40c1c7f0 */

/* Boundary evidence: original MIPS .pdata 40c1c7f0..40c1c8a7. Semantic name remains unreviewed. */

uint FUN_40c1c7f0(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  undefined1 auStack_60 [72];
  uint local_18;
  
  local_18 = DAT_40c2618c;
  bVar1 = FUN_40c1b5c4(param_1);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_40c20494(local_18);
    uVar3 = 0x80040203;
  }
  else {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    FUN_40c1ed94(auStack_60);
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                      (*(int **)(param_1 + 8),*(int *)(param_1 + 4) + -1,auStack_60);
    uVar3 = (uint)(iVar2 != 0);
    FUN_40c1ed78((int)auStack_60);
    FUN_40c20494(local_18);
  }
  return uVar3;
}



/* 40c1c8a8 FUN_40c1c8a8 */

/* Boundary evidence: original MIPS .pdata 40c1c8a8..40c1ca1f. Semantic name remains unreviewed. */

int FUN_40c1c8a8(int *param_1,int *param_2,undefined4 param_3)

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



/* 40c1ca20 FUN_40c1ca20 */

/* Boundary evidence: original MIPS .pdata 40c1ca20..40c1cb93. Semantic name remains unreviewed. */

int FUN_40c1ca20(int *param_1,int *param_2,void *param_3,int *param_4)

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
             (iVar3 = FUN_40c1f020(local_28,param_3), iVar2 = -0x7ffbfdf9, iVar3 != 0)) &&
            (iVar2 = FUN_40c1c8a8(param_1,param_2,local_28), iVar2 < 0)) &&
           (((-1 < iVar1 && (iVar2 != -0x7fffbffb)) &&
            ((iVar2 != -0x7ff8ffa9 && (iVar2 != -0x7ffbfdd6)))))) {
          iVar1 = iVar2;
        }
        FUN_40c1f134(local_28);
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



/* 40c1cb94 FUN_40c1cb94 */

/* Boundary evidence: original MIPS .pdata 40c1cb94..40c1cd1b. Semantic name remains unreviewed. */

int FUN_40c1cb94(int *param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int *local_30 [2];
  
  local_30[0] = (int *)0x0;
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_40c1efb4(param_3), iVar1 == 0)) {
    iVar1 = FUN_40c1c8a8(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = -0x7ffbfdf9;
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,local_30);
  if (-1 < iVar2) {
    iVar2 = FUN_40c1ca20(param_1,param_2,param_3,local_30[0]);
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
  iVar2 = FUN_40c1ca20(param_1,param_2,param_3,local_30[0]);
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



/* 40c1cd1c FUN_40c1cd1c */

/* Boundary evidence: original MIPS .pdata 40c1cd1c..40c1cee3. Semantic name remains unreviewed. */

int FUN_40c1cd1c(int param_1,int *param_2,int param_3)

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
          goto LAB_40c1ceb4;
        }
        *(int **)(param_1 + 0xc) = param_2;
        (**(code **)(*param_2 + 4))(param_2);
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,param_3);
        if ((-1 < iVar2) && (iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,param_2), -1 < iVar2)) {
          iVar2 = 0;
          goto LAB_40c1ceb4;
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
LAB_40c1ceb4:
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40c1cee4 FUN_40c1cee4 */

/* Boundary evidence: original MIPS .pdata 40c1cee4..40c1cf83. Semantic name remains unreviewed. */

undefined4 FUN_40c1cee4(int param_1)

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



/* 40c1cf84 FUN_40c1cf84 */

/* Boundary evidence: original MIPS .pdata 40c1cf84..40c1d00f. Semantic name remains unreviewed. */

undefined4 FUN_40c1cf84(int param_1,void *param_2)

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
      FUN_40c1ec44(param_2);
      uVar1 = 0x80040209;
    }
    else {
      FUN_40c1ec80(param_2,(void *)(param_1 + 0x10));
      uVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40c1d010 FUN_40c1d010 */

/* Boundary evidence: original MIPS .pdata 40c1d010..40c1d02b. Semantic name remains unreviewed. */

void FUN_40c1d010(int param_1,undefined4 *param_2)

{
  FUN_40c1a594(*(wchar_t **)(param_1 + 8),param_2);
  return;
}



/* 40c1d02c FUN_40c1d02c */

/* Boundary evidence: original MIPS .pdata 40c1d02c..40c1d0a7. Semantic name remains unreviewed. */

int FUN_40c1d02c(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40c1cee4(param_1);
  if ((iVar1 == 0) && (*(int **)(param_1 + 0x90) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x90) + 8))();
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40c1d0a8 FUN_40c1d0a8 */

/* Boundary evidence: original MIPS .pdata 40c1d0a8..40c1d12b. Semantic name remains unreviewed. */

undefined4 *
FUN_40c1d0a8(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  FUN_40c1e6d0(param_1,param_2,param_3);
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



/* 40c1d12c FUN_40c1d12c */

/* Boundary evidence: original MIPS .pdata 40c1d12c..40c1d20b. Semantic name remains unreviewed. */

undefined4 * FUN_40c1d12c(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_40c250b8;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 1;
  FUN_40c1e884(param_1 + 6);
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
    FUN_40c1eac0(param_1 + 6,(int *)(param_3 + 0x18));
  }
  return param_1;
}



/* 40c1d20c FUN_40c1d20c */

/* Boundary evidence: original MIPS .pdata 40c1d20c..40c1d2b7. Semantic name remains unreviewed. */

undefined4 FUN_40c1d20c(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40c1b578(param_1);
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
        puVar2 = FUN_40c1d12c(puVar2,*(undefined4 *)(param_1 + 0xc),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40c1d2b8 FUN_40c1d2b8 */

/* Boundary evidence: original MIPS .pdata 40c1d2b8..40c1d347. Semantic name remains unreviewed. */

undefined4 * FUN_40c1d2b8(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_40c250d8;
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



/* 40c1d348 FUN_40c1d348 */

/* Boundary evidence: original MIPS .pdata 40c1d348..40c1d3f3. Semantic name remains unreviewed. */

undefined4 FUN_40c1d348(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40c1b5c4(param_1);
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
        puVar2 = FUN_40c1d2b8(puVar2,*(int *)(param_1 + 8),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40c1d3f4 FUN_40c1d3f4 */

/* Boundary evidence: original MIPS .pdata 40c1d3f4..40c1d4e7. Semantic name remains unreviewed. */

undefined4 *
FUN_40c1d3f4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6,undefined4 param_7)

{
  size_t sVar1;
  void *_Dst;
  uint uVar2;
  uint uVar3;
  
  FUN_40c1e6d0(param_1,param_2,(undefined4 *)0x0);
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_40c1ed94(param_1 + 7);
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



/* 40c1d4e8 FUN_40c1d4e8 */

/* Boundary evidence: original MIPS .pdata 40c1d4e8..40c1d5c7. Semantic name remains unreviewed. */

int FUN_40c1d4e8(int param_1,int *param_2,void *param_3)

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
        iVar1 = FUN_40c1cb94(piVar2,param_2,param_3);
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



/* 40c1d5c8 FUN_40c1d5c8 */

/* Boundary evidence: original MIPS .pdata 40c1d5c8..40c1d647. Semantic name remains unreviewed. */

undefined4 FUN_40c1d5c8(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40c1d2b8(puVar2,param_1 + -0xc,0);
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



/* 40c1d648 FUN_40c1d648 */

/* Boundary evidence: original MIPS .pdata 40c1d648..40c1d693. Semantic name remains unreviewed. */

undefined4 *
FUN_40c1d648(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40c1d3f4(param_1,param_2,param_3,param_4,param_5,param_6,1);
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  return param_1;
}



/* 40c1d694 FUN_40c1d694 */

/* Boundary evidence: original MIPS .pdata 40c1d694..40c1d6ef. Semantic name remains unreviewed. */

undefined4 *
FUN_40c1d694(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40c1d3f4(param_1,param_2,param_3,param_4,param_5,param_6,0);
  param_1[0x27] = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)((int)param_1 + 0xa1) = 0;
  memset(param_1 + 0x2a,0,0x30);
  return param_1;
}



/* 40c1d6f0 FUN_40c1d6f0 */

/* Boundary evidence: original MIPS .pdata 40c1d6f0..40c1d76f. Semantic name remains unreviewed. */

undefined4 FUN_40c1d6f0(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40c1d12c(puVar2,param_1 + -0xc,0);
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



/* 40c1d7b4 FUN_40c1d7b4 */

/* Boundary evidence: original MIPS .pdata 40c1d7b4..40c1d833. Semantic name remains unreviewed. */

void FUN_40c1d7b4(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_40c26178) {
    ppuVar2 = &PTR_DAT_40c26168;
    iVar1 = DAT_40c26178;
    do {
      if ((code *)ppuVar2[2] != (code *)0x0) {
        (*(code *)ppuVar2[2])(param_1,*ppuVar2);
        iVar1 = DAT_40c26178;
      }
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 5;
    } while (iVar3 < iVar1);
  }
  return;
}



/* 40c1d834 FUN_40c1d834 */

/* Boundary evidence: original MIPS .pdata 40c1d834..40c1d8d3. Semantic name remains unreviewed. */

undefined4 FUN_40c1d834(HMODULE param_1,int param_2)

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
    DAT_40c266c0 = 1;
    DAT_40c265ac = 0x114;
    BVar1 = GetVersionExW((LPOSVERSIONINFOW)&DAT_40c265ac);
    if (BVar1 != 0) {
      DAT_40c266c0 = DAT_40c265bc;
    }
    uVar2 = 1;
    DAT_40c266c4 = param_1;
  }
  FUN_40c1d7b4(uVar2);
  return 1;
}



/* 40c1d8d4 FUN_40c1d8d4 */

undefined4 FUN_40c1d8d4(int param_1,int *param_2)

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



/* 40c1d924 FUN_40c1d924 */

/* Boundary evidence: original MIPS .pdata 40c1d924..40c1d9cf. Semantic name remains unreviewed. */

undefined4 FUN_40c1d924(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40c25364,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40c25384,0x10), iVar2 == 0)) {
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



/* 40c1d9d0 FUN_40c1d9d0 */

/* Boundary evidence: original MIPS .pdata 40c1d9d0..40c1da27. Semantic name remains unreviewed. */

void * FUN_40c1d9d0(void *param_1,uint param_2)

{
  FUN_40c1e5a0();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c1da28 FUN_40c1da28 */

/* Boundary evidence: original MIPS .pdata 40c1da28..40c1db4b. Semantic name remains unreviewed. */

int FUN_40c1da28(int param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int local_20 [2];
  
  if (param_4 == 0) {
    local_20[0] = -0x7fffbffd;
  }
  else if ((param_2 == 0) || (iVar1 = memcmp(param_3,&DAT_40c25364,0x10), iVar1 == 0)) {
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



/* 40c1db4c DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0xdb4c  1  DllCanUnloadNow */
  if ((0 < DAT_40c266c8) || (HVar1 = 0, DAT_40c266d0 != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40c1db78 FUN_40c1db78 */

/* Boundary evidence: original MIPS .pdata 40c1db78..40c1dbd3. Semantic name remains unreviewed. */

undefined4 * FUN_40c1db78(undefined4 *param_1,undefined4 param_2)

{
  FUN_40c1e570(param_1 + 1);
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_40c250f8;
  param_1[2] = 0;
  return param_1;
}



/* 40c1dbd4 FUN_40c1dbd4 */

/* Boundary evidence: original MIPS .pdata 40c1dbd4..40c1dc03. Semantic name remains unreviewed. */

int FUN_40c1dbd4(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8) + -1;
  *(int *)((int)param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_40c1d9d0(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40c1dc04 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40c1dc04..40c1dd2b. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  int iVar7;
  
                    /* 0xdc04  2  DllGetClassObject */
  iVar1 = memcmp(riid,&DAT_40c25364,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(riid,&DAT_40c25384,0x10), iVar1 == 0)) {
    iVar1 = DAT_40c26178;
    iVar7 = 0;
    if (0 < DAT_40c26178) {
      ppuVar6 = &PTR_u_Alchemy_MP3_Demux_Filter_40c26164;
      do {
        iVar3 = FUN_40c1d8d4((int)ppuVar6,(int *)rclsid);
        if (iVar3 != 0) {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = FUN_40c1db78(puVar4,ppuVar6);
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



/* 40c1dd2c FUN_40c1dd2c */

/* Boundary evidence: original MIPS .pdata 40c1dd2c..40c1de77. Semantic name remains unreviewed. */

undefined4 FUN_40c1dd2c(HKEY param_1,wchar_t *param_2)

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
  
  local_20 = DAT_40c2618c;
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    FUN_40c20494(local_20);
    uVar2 = 0x80004005;
  }
  else {
    LVar3 = RegOpenKeyExW(param_1,param_2,0,0x2000000,&local_238);
    if (LVar3 == 0) {
      local_234 = 0x104;
      iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,&_Stack_230);
      while (iVar4 == 0) {
        FUN_40c1dd2c(local_238,aWStack_228);
        local_234 = 0x104;
        iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,&_Stack_230);
      }
      RegCloseKey(local_238);
      RegDeleteKeyW(param_1,param_2);
    }
    FUN_40c20494(local_20);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40c1de78 FUN_40c1de78 */

/* Boundary evidence: original MIPS .pdata 40c1de78..40c1e107. Semantic name remains unreviewed. */

uint FUN_40c1de78(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  
  local_30 = DAT_40c2618c;
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
  FUN_40c20494(local_30);
  return uVar1;
}



/* 40c1e108 FUN_40c1e108 */

/* Boundary evidence: original MIPS .pdata 40c1e108..40c1e17b. Semantic name remains unreviewed. */

undefined4 FUN_40c1e108(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GUID local_278;
  OLECHAR aOStack_268 [40];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40c2618c;
  local_278.Data1 = param_1;
  local_278._4_4_ = param_2;
  local_278.Data4._0_4_ = param_3;
  local_278.Data4._4_4_ = param_4;
  StringFromGUID2(&local_278,aOStack_268,0x27);
  wsprintfW(aWStack_218,L"CLSID\\%ls",aOStack_268);
  FUN_40c1dd2c((HKEY)0x80000000,aWStack_218);
  FUN_40c20494(local_10);
  return 0;
}



/* 40c1e17c FUN_40c1e17c */

/* Boundary evidence: original MIPS .pdata 40c1e17c..40c1e3b3. Semantic name remains unreviewed. */

DWORD FUN_40c1e17c(void)

{
  DWORD DVar1;
  ulong *puVar2;
  DWORD DVar3;
  int iVar4;
  undefined **ppuVar5;
  int *local_240 [2];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40c2618c;
  DVar3 = 0;
  DVar1 = GetModuleFileNameW(DAT_40c266c4,aWStack_238,0x104);
  if (DVar1 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
  }
  else {
    iVar4 = 0;
    if (0 < DAT_40c26178) {
      ppuVar5 = &PTR_u_Alchemy_MP3_Demux_Filter_40c26164;
      do {
        puVar2 = (ulong *)ppuVar5[1];
        DVar3 = FUN_40c1de78(*puVar2,puVar2[1],puVar2[2],puVar2[3],*ppuVar5,aWStack_238,L"Both",
                             L"InprocServer32");
        if ((int)DVar3 < 0) break;
        if (ppuVar5[2] != (undefined *)0x0) {
          CoInitializeEx((LPVOID)0x0,0);
          DVar3 = CoCreateInstance((IID *)ppuVar5[1],(LPUNKNOWN)0x0,1,(IID *)&DAT_40c23598,local_240
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
      } while (iVar4 < DAT_40c26178);
    }
  }
  FUN_40c20494(local_30);
  return DVar3;
}



/* 40c1e3b4 FUN_40c1e3b4 */

/* Boundary evidence: original MIPS .pdata 40c1e3b4..40c1e53b. Semantic name remains unreviewed. */

int FUN_40c1e3b4(void)

{
  ulong *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined **ppuVar4;
  int *local_30 [2];
  undefined **ppuVar5;
  
  HVar2 = 0;
  if (DAT_40c26178 != 0) {
    iVar3 = DAT_40c26178;
    ppuVar4 = &PTR_DAT_40c26168 + DAT_40c26178 * 5;
    while( true ) {
      ppuVar5 = ppuVar4 + -5;
      iVar3 = iVar3 + -1;
      if (ppuVar4[-4] != (undefined *)0x0) {
        CoInitializeEx((LPVOID)0x0,0);
        HVar2 = CoCreateInstance((IID *)*ppuVar5,(LPUNKNOWN)0x0,1,(IID *)&DAT_40c23598,local_30);
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
      HVar2 = FUN_40c1e108(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
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



/* 40c1e53c FUN_40c1e53c */

/* Boundary evidence: original MIPS .pdata 40c1e53c..40c1e56f. Semantic name remains unreviewed. */

void FUN_40c1e53c(int param_1)

{
  if (param_1 == 0) {
    FUN_40c1e3b4();
  }
  else {
    FUN_40c1e17c();
  }
  return;
}



/* 40c1e570 FUN_40c1e570 */

/* Boundary evidence: original MIPS .pdata 40c1e570..40c1e59f. Semantic name remains unreviewed. */

undefined4 FUN_40c1e570(undefined4 param_1)

{
  InterlockedIncrement(&DAT_40c266d0);
  return param_1;
}



/* 40c1e5a0 FUN_40c1e5a0 */

/* Boundary evidence: original MIPS .pdata 40c1e5a0..40c1e5f7. Semantic name remains unreviewed. */

void FUN_40c1e5a0(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(&DAT_40c266d0);
  if ((LVar1 == 0) && (DAT_40c266cc != 0)) {
    FreeLibrary((HMODULE)DAT_40c266cc);
    DAT_40c266cc = 0;
  }
  return;
}



/* 40c1e5f8 FUN_40c1e5f8 */

/* Boundary evidence: original MIPS .pdata 40c1e5f8..40c1e633. Semantic name remains unreviewed. */

void FUN_40c1e5f8(void)

{
  if (DAT_40c266cc == (HMODULE)0x0) {
    DAT_40c266cc = LoadLibraryW(L"OleAut32.dll");
  }
  return;
}



/* 40c1e634 FUN_40c1e634 */

/* Boundary evidence: original MIPS .pdata 40c1e634..40c1e68f. Semantic name remains unreviewed. */

undefined4 * FUN_40c1e634(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40c25194;
  InterlockedIncrement(&DAT_40c266d0);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40c1e690 FUN_40c1e690 */

/* Boundary evidence: original MIPS .pdata 40c1e690..40c1e6cf. Semantic name remains unreviewed. */

undefined4 FUN_40c1e690(int *param_1,undefined4 *param_2)

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



/* 40c1e6d0 FUN_40c1e6d0 */

/* Boundary evidence: original MIPS .pdata 40c1e6d0..40c1e72b. Semantic name remains unreviewed. */

undefined4 * FUN_40c1e6d0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40c25194;
  InterlockedIncrement(&DAT_40c266d0);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40c1e72c FUN_40c1e72c */

/* Boundary evidence: original MIPS .pdata 40c1e72c..40c1e7af. Semantic name remains unreviewed. */

undefined4 FUN_40c1e72c(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40c25364,0x10);
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



/* 40c1e7b0 FUN_40c1e7b0 */

/* Boundary evidence: original MIPS .pdata 40c1e7b0..40c1e7eb. Semantic name remains unreviewed. */

uint FUN_40c1e7b0(int param_1)

{
  uint uVar1;
  
  InterlockedIncrement((LONG *)(param_1 + 8));
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 2) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 40c1e7ec FUN_40c1e7ec */

/* Boundary evidence: original MIPS .pdata 40c1e7ec..40c1e863. Semantic name remains unreviewed. */

uint FUN_40c1e7ec(int *param_1)

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



/* 40c1e864 FUN_40c1e864 */

undefined4 * FUN_40c1e864(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_3;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40c1e884 FUN_40c1e884 */

undefined4 * FUN_40c1e884(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 10;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40c1e8a8 FUN_40c1e8a8 */

/* Boundary evidence: original MIPS .pdata 40c1e8a8..40c1e8fb. Semantic name remains unreviewed. */

void FUN_40c1e8a8(undefined4 *param_1)

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



/* 40c1e8fc FUN_40c1e8fc */

undefined4 FUN_40c1e8fc(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    *param_2 = *(int *)(iVar2 + 4);
    uVar1 = *(undefined4 *)(iVar2 + 8);
  }
  return uVar1;
}



/* 40c1e924 FUN_40c1e924 */

int FUN_40c1e924(int *param_1,int param_2)

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



/* 40c1e968 FUN_40c1e968 */

/* Boundary evidence: original MIPS .pdata 40c1e968..40c1ea23. Semantic name remains unreviewed. */

int FUN_40c1e968(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    if (*param_2 == 0) {
      *param_1 = param_2[1];
    }
    else {
      *(int *)(*param_2 + 4) = param_2[1];
    }
    if ((int *)param_2[1] == (int *)0x0) {
      param_1[1] = *param_2;
    }
    else {
      *(int *)param_2[1] = *param_2;
    }
    iVar1 = param_2[2];
    if (param_1[4] < param_1[3]) {
      param_2[1] = param_1[5];
      param_1[5] = (int)param_2;
      param_1[4] = param_1[4] + 1;
    }
    else {
      operator_delete(param_2);
    }
    param_1[2] = param_1[2] + -1;
  }
  return iVar1;
}



/* 40c1ea24 FUN_40c1ea24 */

/* Boundary evidence: original MIPS .pdata 40c1ea24..40c1eabf. Semantic name remains unreviewed. */

undefined4 * FUN_40c1ea24(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[5];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[5] = puVar1[1];
    param_1[4] = param_1[4] + -1;
    if (puVar1 != (undefined4 *)0x0) goto LAB_40c1ea74;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_40c1ea74:
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



/* 40c1eac0 FUN_40c1eac0 */

/* Boundary evidence: original MIPS .pdata 40c1eac0..40c1eb1f. Semantic name remains unreviewed. */

undefined4 FUN_40c1eac0(undefined4 *param_1,int *param_2)

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
    puVar1 = FUN_40c1ea24(param_1,*puVar1);
  } while (puVar1 != (undefined4 *)0x0);
  return 0;
}



/* 40c1eb20 FUN_40c1eb20 */

/* Boundary evidence: original MIPS .pdata 40c1eb20..40c1eb67. Semantic name remains unreviewed. */

void FUN_40c1eb20(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_40c1e8a8(param_1);
  pvVar1 = (void *)param_1[5];
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* 40c1eb68 FUN_40c1eb68 */

/* Boundary evidence: original MIPS .pdata 40c1eb68..40c1eb83. Semantic name remains unreviewed. */

void FUN_40c1eb68(int *param_1)

{
  FUN_40c1e968(param_1,(int *)*param_1);
  return;
}



/* 40c1eb84 FUN_40c1eb84 */

void FUN_40c1eb84(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x2c) = *param_2;
  *(undefined4 *)(param_1 + 0x30) = param_2[1];
  *(undefined4 *)(param_1 + 0x34) = param_2[2];
  *(undefined4 *)(param_1 + 0x38) = param_2[3];
  return;
}



/* 40c1eba8 FUN_40c1eba8 */

/* Boundary evidence: original MIPS .pdata 40c1eba8..40c1ec43. Semantic name remains unreviewed. */

LPVOID FUN_40c1eba8(int param_1,uint param_2)

{
  LPVOID pvVar1;
  
  if (*(uint *)(param_1 + 0x40) != param_2) {
    pvVar1 = CoTaskMemAlloc(param_2);
    if (pvVar1 != (LPVOID)0x0) {
      if (*(uint *)(param_1 + 0x40) != 0) {
        CoTaskMemFree(*(LPVOID *)(param_1 + 0x44));
      }
      *(uint *)(param_1 + 0x40) = param_2;
      *(LPVOID *)(param_1 + 0x44) = pvVar1;
      return pvVar1;
    }
    if (*(uint *)(param_1 + 0x40) < param_2) {
      return (LPVOID)0x0;
    }
  }
  return *(LPVOID *)(param_1 + 0x44);
}



/* 40c1ec44 FUN_40c1ec44 */

/* Boundary evidence: original MIPS .pdata 40c1ec44..40c1ec7f. Semantic name remains unreviewed. */

void FUN_40c1ec44(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return;
}



/* 40c1ec80 FUN_40c1ec80 */

/* Boundary evidence: original MIPS .pdata 40c1ec80..40c1ed13. Semantic name remains unreviewed. */

void FUN_40c1ec80(void *param_1,void *param_2)

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



/* 40c1ed14 FUN_40c1ed14 */

/* Boundary evidence: original MIPS .pdata 40c1ed14..40c1ed77. Semantic name remains unreviewed. */

void FUN_40c1ed14(int param_1)

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



/* 40c1ed78 FUN_40c1ed78 */

/* Boundary evidence: original MIPS .pdata 40c1ed78..40c1ed93. Semantic name remains unreviewed. */

void FUN_40c1ed78(int param_1)

{
  FUN_40c1ed14(param_1);
  return;
}



/* 40c1ed94 FUN_40c1ed94 */

/* Boundary evidence: original MIPS .pdata 40c1ed94..40c1edd3. Semantic name remains unreviewed. */

void * FUN_40c1ed94(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return param_1;
}



/* 40c1edd4 FUN_40c1edd4 */

/* Boundary evidence: original MIPS .pdata 40c1edd4..40c1ee3f. Semantic name remains unreviewed. */

undefined4 * FUN_40c1edd4(undefined4 *param_1,undefined4 *param_2)

{
  memset(param_1,0,0x48);
  param_1[10] = 1;
  param_1[8] = 1;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return param_1;
}



/* 40c1ee40 FUN_40c1ee40 */

/* Boundary evidence: original MIPS .pdata 40c1ee40..40c1ee6b. Semantic name remains unreviewed. */

void * FUN_40c1ee40(void *param_1,void *param_2)

{
  FUN_40c1ec80(param_1,param_2);
  return param_1;
}



/* 40c1ee6c FUN_40c1ee6c */

/* Boundary evidence: original MIPS .pdata 40c1ee6c..40c1eeb7. Semantic name remains unreviewed. */

void * FUN_40c1ee6c(void *param_1,void *param_2)

{
  if (param_2 != param_1) {
    FUN_40c1ed14((int)param_1);
    FUN_40c1ec80(param_1,param_2);
  }
  return param_1;
}



/* 40c1eeb8 FUN_40c1eeb8 */

/* Boundary evidence: original MIPS .pdata 40c1eeb8..40c1eee3. Semantic name remains unreviewed. */

void * FUN_40c1eeb8(void *param_1,void *param_2)

{
  FUN_40c1ee6c(param_1,param_2);
  return param_1;
}



/* 40c1eee4 FUN_40c1eee4 */

/* Boundary evidence: original MIPS .pdata 40c1eee4..40c1ef8f. Semantic name remains unreviewed. */

undefined4 FUN_40c1eee4(void *param_1,void *param_2)

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



/* 40c1ef90 FUN_40c1ef90 */

void FUN_40c1ef90(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 1;
    *(int *)(param_1 + 0x28) = param_2;
  }
  return;
}



/* 40c1efb4 FUN_40c1efb4 */

/* Boundary evidence: original MIPS .pdata 40c1efb4..40c1f01f. Semantic name remains unreviewed. */

undefined4 FUN_40c1efb4(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,&DAT_40c25344,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp((void *)((int)param_1 + 0x2c),&DAT_40c25344,0x10), iVar1 == 0)
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40c1f020 FUN_40c1f020 */

/* Boundary evidence: original MIPS .pdata 40c1f020..40c1f133. Semantic name remains unreviewed. */

undefined4 FUN_40c1f020(void *param_1,void *param_2)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = memcmp(param_2,&DAT_40c25344,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,param_2,0x10), iVar1 == 0)) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40c25344,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) {
      iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40c25344,0x10);
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



/* 40c1f134 FUN_40c1f134 */

/* Boundary evidence: original MIPS .pdata 40c1f134..40c1f173. Semantic name remains unreviewed. */

void FUN_40c1f134(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_40c1ed14((int)param_1);
    CoTaskMemFree(param_1);
  }
  return;
}



/* 40c1f174 FUN_40c1f174 */

/* Boundary evidence: original MIPS .pdata 40c1f174..40c1f1b7. Semantic name remains unreviewed. */

void FUN_40c1f174(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    ReleaseSemaphore(*(HANDLE *)(param_1 + 0x28),*(int *)(param_1 + 0x3c),(LPLONG)0x0);
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 40c1f1b8 FUN_40c1f1b8 */

/* Boundary evidence: original MIPS .pdata 40c1f1b8..40c1f27b. Semantic name remains unreviewed. */

void FUN_40c1f1b8(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    (**(code **)(*(int *)param_1->SpinCount + 0x3c))();
    EnterCriticalSection(param_1);
    iVar1 = param_1[3].RecursionCount;
    param_1[2].LockSemaphore = (HANDLE)0x1;
    if (iVar1 == 0) {
      param_1[3].RecursionCount = 1;
    }
  }
  else {
    EnterCriticalSection(param_1);
    iVar1 = param_1[3].RecursionCount;
    param_1[2].LockSemaphore = (HANDLE)0x1;
    if (iVar1 == 0) {
      param_1[3].RecursionCount = 1;
    }
    if (param_1[2].SpinCount == 0) {
      EventModify(param_1[1].SpinCount,2);
      FUN_40c1f174((int)param_1);
      LeaveCriticalSection(param_1);
      (**(code **)(*(int *)param_1->SpinCount + 0x3c))();
      return;
    }
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40c1f27c FUN_40c1f27c */

/* Boundary evidence: original MIPS .pdata 40c1f27c..40c1f2d3. Semantic name remains unreviewed. */

void FUN_40c1f27c(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_40c1ea24(*(undefined4 **)(param_1 + 0x24),param_2);
  if ((puVar1 == (undefined4 *)0x0) && (param_2 < (int *)0xfffffff1)) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}



/* 40c1f2d4 FUN_40c1f2d4 */

/* Boundary evidence: original MIPS .pdata 40c1f2d4..40c1f573. Semantic name remains unreviewed. */

LONG FUN_40c1f2d4(LPCRITICAL_SECTION param_1,undefined4 *param_2,int param_3,int *param_4)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_30 [2];
  
  EnterCriticalSection(param_1);
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      iVar3 = 0;
      iVar2 = 0;
      do {
        if (iVar2 < param_3) {
          *(undefined4 *)(param_1[2].RecursionCount * 4 + param_1[2].LockCount) = *param_2;
          param_2 = param_2 + 1;
          iVar2 = iVar2 + 1;
          param_1[2].RecursionCount = param_1[2].RecursionCount + 1;
        }
        else if ((param_1[2].RecursionCount == 0) || (param_1[3].LockCount == 0)) goto LAB_40c1f394;
        if ((param_1[2].RecursionCount == param_1[1].RecursionCount) ||
           ((param_3 == 0 && ((param_1[3].LockCount != 0 || (param_1[1].LockCount == 0)))))) {
          if (param_1[3].RecursionCount == 0) {
            LVar1 = (**(code **)(*(int *)param_1[1].DebugInfo + 0x1c))
                              (param_1[1].DebugInfo,param_1[2].LockCount,param_1[2].RecursionCount,
                               local_30);
            param_1[3].RecursionCount = LVar1;
          }
          else {
            local_30[0] = 0;
          }
          iVar3 = (param_1[2].RecursionCount - local_30[0]) + iVar3;
          iVar5 = 0;
          if (0 < param_1[2].RecursionCount) {
            iVar4 = 0;
            do {
              (**(code **)(**(int **)(iVar4 + param_1[2].LockCount) + 8))();
              iVar5 = iVar5 + 1;
              iVar4 = iVar4 + 4;
            } while (iVar5 < param_1[2].RecursionCount);
          }
          param_1[2].RecursionCount = 0;
        }
      } while( true );
    }
    *param_4 = 0;
    if (0 < param_3) {
      do {
        (**(code **)(*(int *)*param_2 + 8))();
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  else {
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      iVar2 = param_3;
      if (0 < param_3) {
        do {
          FUN_40c1f27c((int)param_1,(int *)*param_2);
          param_2 = param_2 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      *param_4 = param_3;
      if ((param_1[1].LockCount == 0) ||
         (param_1[1].RecursionCount <=
          param_1[2].RecursionCount + *(int *)((int)param_1[1].OwningThread + 8))) {
        FUN_40c1f174((int)param_1);
      }
      LVar1 = 0;
      goto LAB_40c1f53c;
    }
    *param_4 = 0;
    if (0 < param_3) {
      do {
        (**(code **)(*(int *)*param_2 + 8))();
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  goto LAB_40c1f3a4;
LAB_40c1f394:
  *param_4 = iVar2 - iVar3;
  if (iVar2 - iVar3 < 0) {
    *param_4 = 0;
  }
LAB_40c1f3a4:
  LVar1 = param_1[3].RecursionCount;
LAB_40c1f53c:
  LeaveCriticalSection(param_1);
  return LVar1;
}



/* 40c1f574 FUN_40c1f574 */

/* Boundary evidence: original MIPS .pdata 40c1f574..40c1f66b. Semantic name remains unreviewed. */

void FUN_40c1f574(LPCRITICAL_SECTION param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  EnterCriticalSection(param_1);
  piVar2 = param_1[1].OwningThread;
  if (piVar2 != (int *)0x0) {
    while (piVar2 = (int *)FUN_40c1eb68(piVar2), piVar2 != (int *)0x0) {
      if (piVar2 < (int *)0xfffffff1) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      else if (piVar2 == (int *)0xfffffffb) {
        pvVar1 = (void *)FUN_40c1eb68(param_1[1].OwningThread);
        operator_delete(pvVar1);
      }
      piVar2 = param_1[1].OwningThread;
    }
  }
  iVar3 = 0;
  if (0 < param_1[2].RecursionCount) {
    iVar4 = 0;
    do {
      (**(code **)(**(int **)(iVar4 + param_1[2].LockCount) + 8))();
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar3 < param_1[2].RecursionCount);
  }
  param_1[2].RecursionCount = 0;
  LeaveCriticalSection(param_1);
  return;
}



/* 40c1f66c FUN_40c1f66c */

/* Boundary evidence: original MIPS .pdata 40c1f66c..40c1f767. Semantic name remains unreviewed. */

void FUN_40c1f66c(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  
  if (param_1[1].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    (**(code **)(*(int *)param_1[1].DebugInfo + 8))();
  }
  if (param_1[2].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    FUN_40c1f574(param_1);
  }
  else {
    EnterCriticalSection(param_1);
    param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x1;
    param_1[3].RecursionCount = 1;
    FUN_40c1f174((int)param_1);
    LeaveCriticalSection(param_1);
    WaitForSingleObject(param_1[2].DebugInfo,0xffffffff);
    CloseHandle(param_1[2].DebugInfo);
    puVar1 = param_1[1].OwningThread;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_40c1eb20(puVar1);
      operator_delete(puVar1);
    }
  }
  if (param_1[1].LockSemaphore != (HANDLE)0x0) {
    CloseHandle(param_1[1].LockSemaphore);
  }
  operator_delete((void *)param_1[2].LockCount);
  FUN_40c1a074(&param_1[1].SpinCount);
  DeleteCriticalSection(param_1);
  return;
}



/* 40c1f768 FUN_40c1f768 */

/* Boundary evidence: original MIPS .pdata 40c1f768..40c1fa3f. Semantic name remains unreviewed. */

undefined4 FUN_40c1f768(LPCRITICAL_SECTION param_1)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  LONG LVar4;
  ULONG_PTR UVar5;
  void *pvVar6;
  int iVar7;
  void *local_28 [2];
  
  pvVar6 = local_28[0];
  pvVar3 = local_28[0];
LAB_40c1f7a4:
  do {
    bVar1 = false;
    EnterCriticalSection(param_1);
    do {
      while( true ) {
        if (param_1[3].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
          FUN_40c1f574(param_1);
          LeaveCriticalSection(param_1);
          return 0;
        }
        if (param_1[2].LockSemaphore != (HANDLE)0x0) {
          FUN_40c1f574(param_1);
          EventModify(param_1[1].SpinCount,3);
        }
        uVar2 = FUN_40c1eb68(param_1[1].OwningThread);
        if (uVar2 != 0) break;
        if ((param_1[1].LockCount != 0) || (param_1[2].RecursionCount == 0)) {
          param_1[2].OwningThread = (HANDLE)((int)param_1[2].OwningThread + 1);
          bVar1 = true;
          goto LAB_40c1f8b8;
        }
LAB_40c1f864:
        if (uVar2 != 0xfffffffe) {
          if (uVar2 == 0xfffffffb) {
            pvVar3 = (void *)FUN_40c1eb68(param_1[1].OwningThread);
          }
          goto LAB_40c1f89c;
        }
        if (param_1[2].RecursionCount != 0) goto LAB_40c1f89c;
      }
      if (0xfffffff0 < uVar2) goto LAB_40c1f864;
      if (param_1[2].RecursionCount < param_1[1].RecursionCount) {
        *(uint *)(param_1[2].RecursionCount * 4 + param_1[2].LockCount) = uVar2;
        param_1[2].RecursionCount = param_1[2].RecursionCount + 1;
      }
    } while (param_1[2].RecursionCount != param_1[1].RecursionCount);
LAB_40c1f89c:
    pvVar6 = (void *)param_1[2].RecursionCount;
    param_1[2].RecursionCount = 0;
LAB_40c1f8b8:
    LeaveCriticalSection(param_1);
    if (!bVar1) {
      if (pvVar6 != (void *)0x0) {
        if (param_1[3].RecursionCount == 0) {
          LVar4 = (**(code **)(*(int *)param_1[1].DebugInfo + 0x1c))
                            (param_1[1].DebugInfo,param_1[2].LockCount,pvVar6,local_28);
          EnterCriticalSection(param_1);
          if (param_1[3].RecursionCount == 0) {
            param_1[3].RecursionCount = LVar4;
          }
          LeaveCriticalSection(param_1);
        }
        iVar7 = (int)pvVar6 << 2;
        do {
          iVar7 = iVar7 + -4;
          pvVar6 = (void *)((int)pvVar6 + -1);
          (**(code **)(**(int **)(param_1[2].LockCount + iVar7) + 8))();
        } while (pvVar6 != (void *)0x0);
      }
      if (uVar2 == 0xfffffffd) {
        if (param_1[3].RecursionCount != 0) goto LAB_40c1f7a4;
        (**(code **)(*(int *)param_1->SpinCount + 0x38))();
      }
      if (uVar2 == 0xfffffffc) {
        UVar5 = param_1[1].SpinCount;
        param_1[3].RecursionCount = 0;
        EventModify(UVar5,3);
      }
      if (uVar2 == 0xfffffffb) {
        (**(code **)(*(int *)param_1->SpinCount + 0x44))();
        operator_delete(pvVar3);
      }
      goto LAB_40c1f7a4;
    }
    WaitForSingleObject(param_1[1].LockSemaphore,0xffffffff);
  } while( true );
}



/* 40c1fa40 FUN_40c1fa40 */

/* Boundary evidence: original MIPS .pdata 40c1fa40..40c1faaf. Semantic name remains unreviewed. */

void FUN_40c1fa40(LPCRITICAL_SECTION param_1)

{
  int aiStack_10 [2];
  
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    param_1[3].LockCount = 1;
    FUN_40c1f2d4(param_1,(undefined4 *)0x0,0,aiStack_10);
    param_1[3].LockCount = 0;
  }
  else {
    EnterCriticalSection(param_1);
    FUN_40c1f27c((int)param_1,(int *)0xfffffffe);
    FUN_40c1f174((int)param_1);
    LeaveCriticalSection(param_1);
  }
  return;
}



/* 40c1fab0 FUN_40c1fab0 */

/* Boundary evidence: original MIPS .pdata 40c1fab0..40c1fb4f. Semantic name remains unreviewed. */

void FUN_40c1fab0(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    if (param_1[1].LockCount != 0) {
      FUN_40c1fa40(param_1);
    }
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      (**(code **)(*(int *)param_1->SpinCount + 0x38))();
    }
  }
  else if (param_1[3].RecursionCount == 0) {
    param_1[2].SpinCount = 0;
    FUN_40c1f27c((int)param_1,(int *)0xfffffffd);
    FUN_40c1f174((int)param_1);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40c1fb50 FUN_40c1fb50 */

/* Boundary evidence: original MIPS .pdata 40c1fb50..40c1fc03. Semantic name remains unreviewed. */

void FUN_40c1fb50(LPCRITICAL_SECTION param_1)

{
  int *piVar1;
  
  EnterCriticalSection(param_1);
  if ((param_1[2].SpinCount == 0) || (param_1[1].OwningThread == (HANDLE)0x0)) {
    LeaveCriticalSection(param_1);
    if (param_1[1].OwningThread == (HANDLE)0x0) {
      FUN_40c1f574(param_1);
    }
    else {
      WaitForSingleObject((HANDLE)param_1[1].SpinCount,0xffffffff);
    }
    piVar1 = (int *)param_1->SpinCount;
    param_1[2].SpinCount = 1;
    param_1[2].LockSemaphore = (HANDLE)0x0;
    (**(code **)(*piVar1 + 0x40))();
    param_1[3].RecursionCount = 0;
  }
  else {
    param_1[2].LockSemaphore = (HANDLE)0x0;
    param_1[3].RecursionCount = 0;
    LeaveCriticalSection(param_1);
  }
  return;
}



/* 40c1fc04 FUN_40c1fc04 */

/* Boundary evidence: original MIPS .pdata 40c1fc04..40c1fc2b. Semantic name remains unreviewed. */

void FUN_40c1fc04(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  undefined4 local_res4 [3];
  int aiStack_10 [2];
  
  local_res4[0] = param_2;
  FUN_40c1f2d4(param_1,local_res4,1,aiStack_10);
  return;
}



/* 40c1fc2c FUN_40c1fc2c */

/* Boundary evidence: original MIPS .pdata 40c1fc2c..40c1fc7f. Semantic name remains unreviewed. */

undefined4 FUN_40c1fc2c(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40c1a0c8();
  uVar2 = FUN_40c1f768(param_1);
  if (-1 < iVar1) {
    CoUninitialize();
  }
  return uVar2;
}



/* 40c1fc80 FUN_40c1fc80 */

/* Boundary evidence: original MIPS .pdata 40c1fc80..40c1fec3. Semantic name remains unreviewed. */

LPCRITICAL_SECTION
FUN_40c1fc80(LPCRITICAL_SECTION param_1,undefined4 *param_2,DWORD *param_3,int param_4,int param_5,
            int param_6,int param_7,undefined4 param_8,int param_9)

{
  DWORD DVar1;
  int iVar2;
  void *pvVar3;
  HANDLE pvVar4;
  undefined4 *puVar5;
  PRTL_CRITICAL_SECTION_DEBUG p_Var6;
  uint uVar7;
  LONG LVar8;
  LPCRITICAL_SECTION p_Var9;
  DWORD aDStack_28 [2];
  
  InitializeCriticalSection(param_1);
  p_Var9 = param_1 + 1;
  param_1->SpinCount = (ULONG_PTR)param_2;
  p_Var9->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  if ((param_7 == 0) || (LVar8 = 1, param_6 < 2)) {
    LVar8 = 0;
  }
  param_1[1].LockCount = LVar8;
  param_1[1].RecursionCount = param_6;
  param_1[1].OwningThread = (HANDLE)0x0;
  param_1[1].LockSemaphore = (HANDLE)0x0;
  FUN_40c1a034(&param_1[1].SpinCount,0);
  param_1[2].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  param_1[2].LockCount = 0;
  param_1[2].RecursionCount = 0;
  param_1[2].OwningThread = (HANDLE)0x0;
  param_1[2].LockSemaphore = (HANDLE)0x0;
  param_1[2].SpinCount = 1;
  param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  param_1[3].LockCount = 0;
  param_1[3].RecursionCount = 0;
  if ((int)*param_3 < 0) {
    return param_1;
  }
  DVar1 = (**(code **)*param_2)(param_2,&DAT_40c23588,p_Var9);
  *param_3 = DVar1;
  if ((int)DVar1 < 0) {
    return param_1;
  }
  if (((param_4 != 0) && (iVar2 = (**(code **)(*(int *)p_Var9->DebugInfo + 0x20))(), -1 < iVar2)) &&
     (param_5 = 1, iVar2 != 0)) {
    param_5 = 0;
  }
  if ((uint)param_1[1].RecursionCount < 0x40000000) {
    uVar7 = param_1[1].RecursionCount << 2;
  }
  else {
    uVar7 = 0xffffffff;
  }
  pvVar3 = operator_new(uVar7);
  param_1[2].LockCount = (LONG)pvVar3;
  if (pvVar3 == (void *)0x0) {
LAB_40c1fdc0:
    DVar1 = 0x8007000e;
  }
  else {
    if (param_5 == 0) {
      return param_1;
    }
    pvVar4 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,0,0x7fffffff,(LPCWSTR)0x0);
    param_1[1].LockSemaphore = pvVar4;
    if (pvVar4 != (HANDLE)0x0) {
      puVar5 = operator_new(0x18);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        FUN_40c1e864(puVar5,0,param_8);
      }
      param_1[1].OwningThread = puVar5;
      if (puVar5 == (undefined4 *)0x0) goto LAB_40c1fdc0;
      p_Var6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40c1fc2c,param_1,0,aDStack_28);
      param_1[2].DebugInfo = p_Var6;
      if (p_Var6 != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
        FUN_40c19d74(p_Var6,param_9);
        return param_1;
      }
    }
    DVar1 = GetLastError();
    if (0 < (int)DVar1) {
      DVar1 = DVar1 & 0xffff | 0x80070000;
    }
  }
  *param_3 = DVar1;
  return param_1;
}



/* 40c1fec4 FUN_40c1fec4 */

/* Boundary evidence: original MIPS .pdata 40c1fec4..40c1fef3. Semantic name remains unreviewed. */

void FUN_40c1fec4(int *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 8))();
  }
  return;
}



/* 40c1fef4 FUN_40c1fef4 */

undefined4 FUN_40c1fef4(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 1;
    uVar1 = 0;
  }
  return uVar1;
}



/* 40c1ff1c FUN_40c1ff1c */

/* Boundary evidence: original MIPS .pdata 40c1ff1c..40c200b7. Semantic name remains unreviewed. */

uint FUN_40c1ff1c(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  DWORD DVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int *local_28 [2];
  
  if (param_5 == (int *)0x0) {
    return 0x80004003;
  }
  *param_5 = 0;
  if (param_3 != 0) {
    return 0x8002802b;
  }
  if (*param_1 == 0) {
    iVar1 = FUN_40c1e5f8();
    if ((iVar1 == 0) ||
       (pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadRegTypeLib"), pcVar3 == (code *)0x0)) {
LAB_40c1ff90:
      DVar2 = GetLastError();
      if ((int)DVar2 < 1) {
        return DVar2;
      }
      return DVar2 & 0xffff | 0x80070000;
    }
    iVar4 = (*pcVar3)(&UNK_40c23a18,1,0,param_4,local_28);
    if (iVar4 < 0) {
      pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadTypeLib");
      if (pcVar3 == (code *)0x0) goto LAB_40c1ff90;
      uVar5 = (*pcVar3)(L"control.tlb",local_28);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
    }
    uVar5 = (**(code **)(*local_28[0] + 0x18))(local_28[0],param_2,param_1);
    (**(code **)(*local_28[0] + 8))();
    if ((int)uVar5 < 0) {
      return uVar5;
    }
  }
  *param_5 = *param_1;
  (**(code **)(*(int *)*param_1 + 4))();
  return 0;
}



/* 40c200b8 FUN_40c200b8 */

/* Boundary evidence: original MIPS .pdata 40c200b8..40c2027f. Semantic name remains unreviewed. */

DWORD FUN_40c200b8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  DWORD DVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  undefined1 auStackX_0 [16];
  int *local_28 [2];
  
  piVar5 = (int *)0x0;
  if (auStackX_0 == (undefined1 *)0x28) {
    return 0x80004003;
  }
  if (*param_1 == 0) {
    iVar1 = FUN_40c1e5f8();
    if ((iVar1 == 0) ||
       (pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadRegTypeLib"), pcVar3 == (code *)0x0)) {
LAB_40c20124:
      DVar2 = GetLastError();
      if (0 < (int)DVar2) {
        DVar2 = DVar2 & 0xffff | 0x80070000;
      }
      goto LAB_40c2021c;
    }
    iVar4 = (*pcVar3)(&UNK_40c23a18,1,0,param_5,local_28);
    if (iVar4 < 0) {
      pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadTypeLib");
      if (pcVar3 == (code *)0x0) goto LAB_40c20124;
      DVar2 = (*pcVar3)(L"control.tlb",local_28);
      if ((int)DVar2 < 0) goto LAB_40c2021c;
    }
    DVar2 = (**(code **)(*local_28[0] + 0x18))(local_28[0],param_2,param_1);
    (**(code **)(*local_28[0] + 8))();
    if ((int)DVar2 < 0) goto LAB_40c2021c;
  }
  piVar5 = (int *)*param_1;
  (**(code **)(*piVar5 + 4))(piVar5);
  DVar2 = 0;
LAB_40c2021c:
  if (-1 < (int)DVar2) {
    DVar2 = (**(code **)(*piVar5 + 0x28))(piVar5,param_3,param_4,param_6);
    (**(code **)(*piVar5 + 8))(piVar5);
  }
  return DVar2;
}



/* 40c203a0 FUN_40c203a0 */

/* Boundary evidence: original MIPS .pdata 40c203a0..40c20413. Semantic name remains unreviewed. */

void FUN_40c203a0(void)

{
  uint uVar1;
  
  if ((DAT_40c2618c == 0) || (DAT_40c2618c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40c2618c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40c2618c == 0) {
      DAT_40c2618c = 0xb064;
    }
  }
  DAT_40c26190 = ~DAT_40c2618c;
  return;
}



/* 40c20414 FUN_40c20414 */

/* Boundary evidence: original MIPS .pdata 40c20414..40c20467. Semantic name remains unreviewed. */

void FUN_40c20414(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40c20494(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40c20468 FUN_40c20468 */

/* Boundary evidence: original MIPS .pdata 40c20468..40c20493. Semantic name remains unreviewed. */

undefined4 FUN_40c20468(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40c20414(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40c20494 FUN_40c20494 */

/* Boundary evidence: original MIPS .pdata 40c20494..40c204db. Semantic name remains unreviewed. */

void FUN_40c20494(uint param_1)

{
  if ((param_1 == DAT_40c2618c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40c2055c FUN_40c2055c */

/* Boundary evidence: original MIPS .pdata 40c2055c..40c205cb. Semantic name remains unreviewed. */

void FUN_40c2055c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40c20414(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 40c205ec FUN_40c205ec */

/* Boundary evidence: original MIPS .pdata 40c205ec..40c20727. Semantic name remains unreviewed. */

int FUN_40c205ec(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40c266e4 != (code *)0x0) {
      iVar2 = (*DAT_40c266e4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40c2069c;
    FUN_40c20970();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40c11ca0(param_1,param_2);
  }
LAB_40c2069c:
  if (((param_2 == 0) && (FUN_40c208f8(), iVar1 != 0)) && (DAT_40c266e4 != (code *)0x0)) {
    iVar1 = (*DAT_40c266e4)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40c20728 FUN_40c20728 */

/* Boundary evidence: original MIPS .pdata 40c20728..40c20753. Semantic name remains unreviewed. */

void FUN_40c20728(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40c20754 entry */

/* Boundary evidence: original MIPS .pdata 40c20754..40c207ab. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40c203a0();
  }
  FUN_40c205ec(param_1,param_2,param_3);
  return;
}



/* 40c2080c FUN_40c2080c */

/* Boundary evidence: original MIPS .pdata 40c2080c..40c208f7. Semantic name remains unreviewed. */

void FUN_40c2080c(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40c266d8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40c266e0;
    if (DAT_40c266e0 != (undefined4 *)0x0) {
      while (DAT_40c266dc = DAT_40c266dc + -1, _Memory <= DAT_40c266dc) {
        if ((code *)*DAT_40c266dc != (code *)0x0) {
          (*(code *)*DAT_40c266dc)();
          _Memory = DAT_40c266e0;
        }
      }
      free(_Memory);
      DAT_40c266dc = (undefined4 *)0x0;
      DAT_40c266e0 = (undefined4 *)0x0;
    }
    FUN_40c2091c((undefined4 *)&DAT_40c21010,(undefined4 *)&DAT_40c21014);
  }
  FUN_40c2091c((undefined4 *)&DAT_40c21018,(undefined4 *)&DAT_40c2101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 40c208f8 FUN_40c208f8 */

/* Boundary evidence: original MIPS .pdata 40c208f8..40c2091b. Semantic name remains unreviewed. */

void FUN_40c208f8(void)

{
  FUN_40c2080c(0,0,1);
  return;
}



/* 40c2091c FUN_40c2091c */

/* Boundary evidence: original MIPS .pdata 40c2091c..40c2096f. Semantic name remains unreviewed. */

void FUN_40c2091c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40c20970 FUN_40c20970 */

/* Boundary evidence: original MIPS .pdata 40c20970..40c209ab. Semantic name remains unreviewed. */

void FUN_40c20970(void)

{
  FUN_40c2091c((undefined4 *)&DAT_40c21008,(undefined4 *)&DAT_40c2100c);
  FUN_40c2091c((undefined4 *)&DAT_40c21000,(undefined4 *)&DAT_40c21004);
  return;
}


