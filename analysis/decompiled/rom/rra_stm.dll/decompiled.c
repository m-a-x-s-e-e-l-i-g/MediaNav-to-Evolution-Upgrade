/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 408411c8 FUN_408411c8 */

undefined4 FUN_408411c8(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_40844084 = param_1;
  }
  return 1;
}



/* 408411e4 DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0x11e4  1  DllCanUnloadNow */
  if ((DAT_40844080 != 0) || (HVar1 = 0, DAT_40844088 != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40841224 FUN_40841224 */

/* Boundary evidence: original MIPS .pdata 40841224..40841263. Semantic name remains unreviewed. */

undefined4 FUN_40841224(int *param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  
  *param_3 = (int)param_1;
  if (param_1 == (int *)0x0) {
    uVar1 = 0x80004002;
  }
  else {
    (**(code **)(*param_1 + 4))();
    uVar1 = 0;
  }
  return uVar1;
}



/* 40841264 FUN_40841264 */

void FUN_40841264(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return;
}



/* 408412a8 FUN_408412a8 */

/* Boundary evidence: original MIPS .pdata 408412a8..408412e7. Semantic name remains unreviewed. */

int FUN_408412a8(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    *param_1 = &PTR_FUN_4084103c;
    operator_delete(param_1);
  }
  return iVar1;
}



/* 408412e8 FUN_408412e8 */

/* Boundary evidence: original MIPS .pdata 408412e8..408413cf. Semantic name remains unreviewed. */

int FUN_408412e8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  *param_4 = 0;
  iVar3 = -0x7ff8fff2;
  puVar1 = operator_new(0x170);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40841558(puVar1,param_2,&LAB_40841210,DAT_40844084);
  }
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_40841ac0((int)puVar1);
    if ((iVar2 == 0) || (iVar3 = (**(code **)*puVar1)(puVar1,param_3,param_4), iVar3 < 0)) {
      FUN_40841944(puVar1);
      operator_delete(puVar1);
    }
    else {
      DAT_40844080 = DAT_40844080 + 1;
    }
  }
  return iVar3;
}



/* 408413d0 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 408413d0..40841467. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int *piVar3;
  
                    /* 0x13d0  2  DllGetClassObject */
  iVar1 = memcmp(rclsid,&DAT_40841060,0x10);
  if (iVar1 == 0) {
    piVar3 = operator_new(8);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      *piVar3 = (int)&PTR_FUN_4084103c;
      piVar3[1] = 0;
    }
    *ppv = piVar3;
    if (piVar3 == (int *)0x0) {
      HVar2 = -0x7ff8fff2;
    }
    else {
      (**(code **)(*piVar3 + 4))(piVar3);
      HVar2 = 0;
    }
  }
  else {
    HVar2 = -0x7fffbffb;
  }
  return HVar2;
}



/* 40841468 FUN_40841468 */

/* Boundary evidence: original MIPS .pdata 40841468..4084148f. Semantic name remains unreviewed. */

void FUN_40841468(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc))();
  return;
}



/* 40841490 FUN_40841490 */

/* Boundary evidence: original MIPS .pdata 40841490..408414b7. Semantic name remains unreviewed. */

void FUN_40841490(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))();
  return;
}



/* 408414b8 FUN_408414b8 */

/* Boundary evidence: original MIPS .pdata 408414b8..408414df. Semantic name remains unreviewed. */

void FUN_408414b8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 8))();
  return;
}



/* 408414e0 FUN_408414e0 */

/* Boundary evidence: original MIPS .pdata 408414e0..40841507. Semantic name remains unreviewed. */

void FUN_408414e0(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc))();
  return;
}



/* 40841508 FUN_40841508 */

/* Boundary evidence: original MIPS .pdata 40841508..4084152f. Semantic name remains unreviewed. */

void FUN_40841508(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))();
  return;
}



/* 40841530 FUN_40841530 */

/* Boundary evidence: original MIPS .pdata 40841530..40841557. Semantic name remains unreviewed. */

void FUN_40841530(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 8))();
  return;
}



/* 40841558 FUN_40841558 */

/* Boundary evidence: original MIPS .pdata 40841558..4084166b. Semantic name remains unreviewed. */

undefined4 *
FUN_40841558(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HANDLE pvVar1;
  
  *param_1 = &PTR_FUN_40841178;
  param_1[5] = 0xffffffff;
  param_1[6] = 0xffffffff;
  param_1[0x10] = param_4;
  param_1[0x12] = param_2;
  param_1[0x13] = param_3;
  param_1[0x11] = 0;
  param_1[0x14] = 0;
  param_1[0xe] = 1;
  param_1[0x56] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0x15] = 0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  param_1[1] = pvVar1;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  param_1[2] = pvVar1;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
  param_1[4] = pvVar1;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
  param_1[3] = pvVar1;
  param_1[0x59] = 0;
  param_1[0x57] = 0;
  param_1[0xf] = 0;
  param_1[0x58] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4084408c);
  return param_1;
}



/* 4084166c FUN_4084166c */

/* Boundary evidence: original MIPS .pdata 4084166c..408416ef. Semantic name remains unreviewed. */

void FUN_4084166c(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4084408c);
  if (*(SOCKET *)(param_1 + 0x18) == 0xffffffff) {
    if (*(SOCKET *)(param_1 + 0x14) != 0xffffffff) {
      closesocket(*(SOCKET *)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
    }
  }
  else {
    closesocket(*(SOCKET *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4084408c);
  return;
}



/* 408416f0 FUN_408416f0 */

/* Boundary evidence: original MIPS .pdata 408416f0..408417c3. Semantic name remains unreviewed. */

undefined4 FUN_408416f0(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_3 = 0;
  iVar1 = memcmp(param_2,&DAT_40841184,0x10);
  if (iVar1 == 0) {
    *param_3 = param_1;
  }
  iVar1 = memcmp(param_2,&DAT_408410a0,0x10);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x15c);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40841100,0x10);
    if (iVar1 != 0) goto LAB_4084177c;
    iVar1 = *(int *)(param_1 + 0x160);
  }
  *param_3 = iVar1;
LAB_4084177c:
  if ((int *)*param_3 == (int *)0x0) {
    uVar2 = 0x80004002;
  }
  else {
    (**(code **)(*(int *)*param_3 + 4))();
    uVar2 = 0;
  }
  return uVar2;
}



/* 408417c4 FUN_408417c4 */

/* Boundary evidence: original MIPS .pdata 408417c4..408417df. Semantic name remains unreviewed. */

void FUN_408417c4(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x44));
  return;
}



/* 408417e0 FUN_408417e0 */

/* Boundary evidence: original MIPS .pdata 408417e0..4084185b. Semantic name remains unreviewed. */

undefined4 FUN_408417e0(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x54) = 1;
    EventModify(*(undefined4 *)(param_1 + 4),3);
    piVar1 = *(int **)(param_1 + 0x168);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x20))(piVar1,0);
    }
    piVar1 = *(int **)(param_1 + 0x15c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(piVar1,1);
    }
  }
  return 0;
}



/* 4084185c FUN_4084185c */

/* Boundary evidence: original MIPS .pdata 4084185c..40841943. Semantic name remains unreviewed. */

void FUN_4084185c(int param_1)

{
  undefined4 *puVar1;
  
  if (*(void **)(param_1 + 0x28) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  if (*(void **)(param_1 + 0x30) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x15c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_40841140;
    operator_delete(puVar1);
  }
  puVar1 = *(undefined4 **)(param_1 + 0x160);
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_40841158;
    operator_delete(puVar1);
    *(undefined4 *)(param_1 + 0x160) = 0;
  }
  if (*(int **)(param_1 + 0x168) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x168) + 8))();
    *(undefined4 *)(param_1 + 0x168) = 0;
  }
  if (*(int **)(param_1 + 0x16c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x16c) + 8))();
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  return;
}



/* 40841944 FUN_40841944 */

/* Boundary evidence: original MIPS .pdata 40841944..408419c7. Semantic name remains unreviewed. */

void FUN_40841944(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40841178;
  CloseHandle((HANDLE)param_1[1]);
  CloseHandle((HANDLE)param_1[2]);
  CloseHandle((HANDLE)param_1[3]);
  CloseHandle((HANDLE)param_1[4]);
  FUN_4084166c((int)param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4084408c);
  FUN_4084185c((int)param_1);
  return;
}



/* 408419c8 FUN_408419c8 */

/* Boundary evidence: original MIPS .pdata 408419c8..40841a4f. Semantic name remains unreviewed. */

undefined4 FUN_408419c8(int param_1,char *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_3 + 0xfffcU & 0xffff;
  param_2[2] = (char)uVar2;
  param_2[3] = (char)(uVar2 >> 8);
  if (*(SOCKET *)(param_1 + 0x14) != 0xffffffff) {
    iVar1 = send(*(SOCKET *)(param_1 + 0x14),param_2,param_3,0);
    if (iVar1 != -1) {
      return 0;
    }
    FUN_408417e0(param_1,1);
  }
  return 0x80004005;
}



/* 40841a50 FUN_40841a50 */

/* Boundary evidence: original MIPS .pdata 40841a50..40841abf. Semantic name remains unreviewed. */

undefined4 FUN_40841a50(int param_1,char *param_2,int param_3)

{
  int iVar1;
  
  if (*(SOCKET *)(param_1 + 0x18) != 0xffffffff) {
    iVar1 = send(*(SOCKET *)(param_1 + 0x18),param_2,param_3,0);
    if (iVar1 != -1) {
      return 0;
    }
    FUN_408417e0(param_1,1);
  }
  return 0x80004005;
}



/* 40841ac0 FUN_40841ac0 */

/* Boundary evidence: original MIPS .pdata 40841ac0..40841b73. Semantic name remains unreviewed. */

undefined4 FUN_40841ac0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 0x48) != 0) {
    iVar2 = *(int *)(param_1 + 0x48);
  }
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_40841140;
    puVar1[1] = 0;
    puVar1[2] = param_1;
    puVar1[3] = iVar2;
  }
  *(undefined4 **)(param_1 + 0x15c) = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1 = operator_new(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_40841158;
      puVar1[1] = 0;
      puVar1[2] = param_1;
      puVar1[3] = iVar2;
    }
    *(undefined4 **)(param_1 + 0x160) = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      return 1;
    }
  }
  return 0;
}



/* 40841b74 FUN_40841b74 */

/* Boundary evidence: original MIPS .pdata 40841b74..40841bcb. Semantic name remains unreviewed. */

LONG FUN_40841b74(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0x11);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_40841944(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



/* 40841bcc FUN_40841bcc */

/* Boundary evidence: original MIPS .pdata 40841bcc..40841c0f. Semantic name remains unreviewed. */

int FUN_40841bcc(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(int *)(param_1 + 0x158) != 0) &&
     (iVar1 = FUN_408419c8(param_1,(char *)(param_1 + 0x58),*(int *)(param_1 + 0x158)), -1 < iVar1))
  {
    *(undefined4 *)(param_1 + 0x158) = 0;
  }
  return iVar1;
}



/* 40841c10 FUN_40841c10 */

/* Boundary evidence: original MIPS .pdata 40841c10..40841d37. Semantic name remains unreviewed. */

int FUN_40841c10(int param_1,undefined4 *param_2,undefined4 param_3)

{
  DWORD DVar1;
  int iVar2;
  
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 8),0);
  if (DVar1 == 0) {
    iVar2 = -0x7fffbffc;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      if (*(int *)(param_1 + 0x1c) - 0xcU <= *(uint *)(param_1 + 0x34)) {
        iVar2 = FUN_40841a50(param_1,*(char **)(param_1 + 0x30),*(uint *)(param_1 + 0x34));
        if (iVar2 < 0) {
          return iVar2;
        }
        *(undefined4 *)(param_1 + 0x34) = 0;
      }
      *(undefined4 *)(*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x34)) = 0xffffffff;
      iVar2 = *(int *)(param_1 + 0x34) + 4;
      *(int *)(param_1 + 0x34) = iVar2;
      *(undefined4 *)(*(int *)(param_1 + 0x30) + iVar2) = *param_2;
      iVar2 = *(int *)(param_1 + 0x34) + 4;
      *(int *)(param_1 + 0x34) = iVar2;
      *(undefined4 *)(*(int *)(param_1 + 0x30) + iVar2) = param_3;
      *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 4;
    }
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar2 = FUN_40841a50(param_1,*(char **)(param_1 + 0x30),*(int *)(param_1 + 0x34));
      if (iVar2 < 0) {
        return iVar2;
      }
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    iVar2 = FUN_40841bcc(param_1);
  }
  return iVar2;
}



/* 40841d38 FUN_40841d38 */

/* Boundary evidence: original MIPS .pdata 40841d38..4084228f. Semantic name remains unreviewed. */

undefined4 FUN_40841d38(int *param_1,int param_2,int *param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  LPMEMORYSTATUS lpBuffer;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  size_t local_38;
  void *local_34;
  char acStack_30 [3];
  undefined1 auStack_2d [4];
  undefined1 auStack_29 [4];
  undefined1 uStack_25;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  
  uVar2 = DAT_40844078;
  local_1c = DAT_40844078;
  uVar8 = 0;
  if (param_2 == 0) {
    *param_3 = 0;
    FUN_408432a0(uVar2);
    return 0;
  }
  if (DAT_408440a0 == 0) {
    DAT_408440a0 = *param_1;
  }
  switch(DAT_408440a0) {
  case 0x65:
    piVar4 = *(int **)(param_4 + 0x168);
    if (piVar4 != (int *)0x0) {
      uVar8 = (**(code **)(*piVar4 + 0x14))(piVar4,param_1[1],param_1[2],param_1[2],param_1[4]);
    }
    iVar5 = 0x14;
    goto LAB_40841e38;
  case 0x66:
    (**(code **)(**(int **)(param_4 + 0x168) + 0x18))
              (*(int **)(param_4 + 0x168),param_1[2],param_1[3],param_1[4]);
    *param_3 = 0x14;
    goto LAB_40841e3c;
  case 0x67:
    uVar8 = (**(code **)(**(int **)(param_4 + 0x168) + 0x1c))
                      (*(int **)(param_4 + 0x168),param_1[2],param_1[3],param_1 + 4,param_1[1]);
    *param_3 = (param_1[3] + 4) * 4;
    goto LAB_40842260;
  case 0x68:
    uVar8 = (**(code **)(**(int **)(param_4 + 0x168) + 0xc))
                      (*(int **)(param_4 + 0x168),param_1[2],param_1[3],param_1[1]);
    iVar5 = 0x10;
    break;
  default:
    goto switchD_40841dc8_caseD_40842264;
  case 0x6b:
    piVar4 = *(int **)(param_4 + 0x16c);
    if (piVar4 == (int *)0x0) {
      register0x00000008 = 0x80004002;
    }
    else {
      register0x00000008 =
           (**(code **)(*piVar4 + 0x24))(piVar4,(char)param_1[1],*(undefined1 *)((int)param_1 + 5));
    }
    iVar5 = param_1[1];
    pcVar3 = acStack_30 + 3;
    uVar2 = (uint)pcVar3 & 3;
    *(uint *)(pcVar3 + -uVar2) =
         *(uint *)(pcVar3 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x6cU >> (3 - uVar2) * 8;
    uVar2 = (uint)auStack_29 & 3;
    puVar1 = (uint *)(auStack_29 + -uVar2);
    *puVar1 = *puVar1 & -1 << (uVar2 + 1) * 8 | 0x6bU >> (3 - uVar2) * 8;
    uVar2 = (uint)&uStack_25 & 3;
    puVar1 = (uint *)(&uStack_25 + -uVar2);
    *puVar1 = *puVar1 & -1 << (uVar2 + 1) * 8 | register0x00000008 >> (3 - uVar2) * 8;
    *(uint *)(param_4 + 0x38) = (uint)((char)iVar5 == '\0');
    _acStack_30 = 0x6c;
    stack0xffffffd4 = 0x6b;
    uVar8 = FUN_408419c8(param_4,acStack_30,0x14);
    *param_3 = 6;
    goto LAB_40842260;
  case 0x6f:
    piVar4 = *(int **)(param_4 + 0x16c);
    local_38 = 0;
    local_34 = (void *)0x0;
    if (piVar4 == (int *)0x0) {
      uVar8 = 0x80004002;
    }
    else {
      uVar8 = (**(code **)(*piVar4 + 0xc))(piVar4,&local_38,&local_34,param_1[1]);
    }
    pcVar3 = operator_new(local_38 + 0x14);
    if (pcVar3 == (char *)0x0) {
      uVar8 = 0x8007000e;
    }
    else {
      pcVar3[0] = 'l';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3[4] = 'o';
      pcVar3[5] = '\0';
      pcVar3[6] = '\0';
      pcVar3[7] = '\0';
      *(undefined4 *)(pcVar3 + 8) = uVar8;
      *(size_t *)(pcVar3 + 0xc) = local_38;
      if (local_38 != 0) {
        memcpy(pcVar3 + 0x14,local_34,local_38);
      }
      uVar8 = FUN_408419c8(param_4,pcVar3,local_38 + 0x14);
    }
    if (local_34 != (void *)0x0) {
      operator_delete(local_34);
    }
    if (pcVar3 != (char *)0x0) {
      operator_delete(pcVar3);
    }
    iVar5 = 8;
LAB_40841e38:
    *param_3 = iVar5;
LAB_40841e3c:
    DAT_408440a0 = 0;
    goto switchD_40841dc8_caseD_40842264;
  case 0x70:
    piVar4 = *(int **)(param_4 + 0x16c);
    if (piVar4 == (int *)0x0) {
      register0x00000008 = 0x80004002;
    }
    else {
      register0x00000008 = (**(code **)(*piVar4 + 0x10))(piVar4,param_1[1],param_1 + 2);
    }
    pcVar3 = acStack_30 + 3;
    uVar2 = (uint)pcVar3 & 3;
    *(uint *)(pcVar3 + -uVar2) =
         *(uint *)(pcVar3 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x6cU >> (3 - uVar2) * 8;
    uVar2 = (uint)auStack_29 & 3;
    puVar1 = (uint *)(auStack_29 + -uVar2);
    *puVar1 = *puVar1 & -1 << (uVar2 + 1) * 8 | 0x70U >> (3 - uVar2) * 8;
    uVar2 = (uint)&uStack_25 & 3;
    puVar1 = (uint *)(&uStack_25 + -uVar2);
    *puVar1 = *puVar1 & -1 << (uVar2 + 1) * 8 | register0x00000008 >> (3 - uVar2) * 8;
    _acStack_30 = 0x6c;
    stack0xffffffd4 = 0x70;
    uVar8 = FUN_408419c8(param_4,acStack_30,0x14);
    iVar5 = param_1[1] + 8;
    break;
  case 0x71:
    piVar4 = *(int **)(param_4 + 0x16c);
    local_24 = 0;
    if (piVar4 == (int *)0x0) {
      uVar2 = 0x80004002;
    }
    else {
      uVar2 = (**(code **)(*piVar4 + 0x14))(piVar4,param_1[1],param_1[2],&local_24,&local_20);
    }
    lpBuffer = operator_new(0x20);
    if (lpBuffer != (LPMEMORYSTATUS)0x0) {
      GlobalMemoryStatus(lpBuffer);
      uVar7 = lpBuffer->dwTotalPhys >> 10;
      uVar6 = lpBuffer->dwAvailPhys >> 10;
      local_20 = uVar6 << 0x10 | uVar7 & 0xffff;
      lpBuffer->dwTotalPhys = uVar7;
      lpBuffer->dwAvailPhys = uVar6;
      operator_delete(lpBuffer);
    }
    pcVar3 = acStack_30 + 3;
    uVar6 = (uint)pcVar3 & 3;
    *(uint *)(pcVar3 + -uVar6) =
         *(uint *)(pcVar3 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x6cU >> (3 - uVar6) * 8;
    uVar6 = (uint)auStack_29 & 3;
    puVar1 = (uint *)(auStack_29 + -uVar6);
    *puVar1 = *puVar1 & -1 << (uVar6 + 1) * 8 | 0x71U >> (3 - uVar6) * 8;
    uVar6 = (uint)&uStack_25 & 3;
    puVar1 = (uint *)(&uStack_25 + -uVar6);
    *puVar1 = *puVar1 & -1 << (uVar6 + 1) * 8 | uVar2 >> (3 - uVar6) * 8;
    _acStack_30 = 0x6c;
    stack0xffffffd4 = 0x71;
    unique0x1000026f = uVar2;
    uVar8 = FUN_408419c8(param_4,acStack_30,0x14);
    iVar5 = 0xc;
    break;
  case 0x72:
    piVar4 = *(int **)(param_4 + 0x16c);
    if (piVar4 == (int *)0x0) {
      register0x00000008 = 0x80004002;
    }
    else {
      register0x00000008 = (**(code **)(*piVar4 + 0x2c))(piVar4,param_1[1]);
    }
    pcVar3 = acStack_30 + 3;
    uVar2 = (uint)pcVar3 & 3;
    *(uint *)(pcVar3 + -uVar2) =
         *(uint *)(pcVar3 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x6cU >> (3 - uVar2) * 8;
    uVar2 = (uint)auStack_29 & 3;
    puVar1 = (uint *)(auStack_29 + -uVar2);
    *puVar1 = *puVar1 & -1 << (uVar2 + 1) * 8 | 0x72U >> (3 - uVar2) * 8;
    uVar2 = (uint)&uStack_25 & 3;
    puVar1 = (uint *)(&uStack_25 + -uVar2);
    *puVar1 = *puVar1 & -1 << (uVar2 + 1) * 8 | register0x00000008 >> (3 - uVar2) * 8;
    _acStack_30 = 0x6c;
    stack0xffffffd4 = 0x72;
    uVar8 = FUN_408419c8(param_4,acStack_30,0x14);
    iVar5 = 8;
  }
  *param_3 = iVar5;
LAB_40842260:
  DAT_408440a0 = 0;
switchD_40841dc8_caseD_40842264:
  FUN_408432a0(local_1c);
  return uVar8;
}



/* 40842290 FUN_40842290 */

/* Boundary evidence: original MIPS .pdata 40842290..408424cb. Semantic name remains unreviewed. */

int FUN_40842290(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  char local_28 [2];
  ushort local_26;
  int iStack_24;
  
  iVar7 = -0x7fff0001;
  EventModify(*(undefined4 *)(param_1 + 4),3);
  iVar3 = *(int *)(param_1 + 0x54);
  do {
    if (iVar3 != 0) {
LAB_40842474:
      FUN_408417e0(param_1,1);
      SetThreadPriority((HANDLE)0x41,1);
      EventModify(*(undefined4 *)(param_1 + 0xc),3);
      return iVar7;
    }
    local_28[0] = '\0';
    local_28[1] = '\0';
    local_26 = 0;
    iVar3 = 0;
    do {
      iVar1 = recv(*(SOCKET *)(param_1 + 0x14),local_28 + iVar3,4 - iVar3,0);
      if ((iVar1 == -1) || (iVar1 == 0)) goto LAB_40842474;
      iVar3 = iVar1 + iVar3;
    } while (iVar3 != 4);
    uVar4 = (uint)local_26;
    if (*(uint *)(param_1 + 0x20) < uVar4 + 4) {
      operator_delete(*(void **)(param_1 + 0x28));
      *(undefined4 *)(param_1 + 0x20) = 0;
      pvVar2 = operator_new(local_26 + 4);
      *(void **)(param_1 + 0x28) = pvVar2;
      if (pvVar2 == (void *)0x0) {
        iVar7 = 0xe;
        goto LAB_40842474;
      }
      uVar4 = (uint)local_26;
      *(uint *)(param_1 + 0x20) = uVar4 + 4;
    }
    iVar3 = *(int *)(param_1 + 0x28);
    uVar6 = 0;
    if (uVar4 == 0) goto LAB_40842474;
    do {
      iVar1 = recv(*(SOCKET *)(param_1 + 0x14),(char *)(uVar6 + iVar3 + 4),uVar4 - uVar6,0);
      if ((iVar1 == -1) || (iVar1 == 0)) goto LAB_40842474;
      uVar6 = iVar1 + uVar6;
    } while (uVar6 != uVar4);
    if (uVar6 == 0) goto LAB_40842474;
    pcVar5 = *(char **)(param_1 + 0x28);
    *pcVar5 = local_28[0];
    pcVar5[1] = local_28[1];
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    iVar7 = FUN_40841d38(*(int **)(param_1 + 0x28),local_26 + 4,&iStack_24,param_1);
    if (iVar7 < 0) goto LAB_40842474;
    iVar3 = *(int *)(param_1 + 0x54);
  } while( true );
}



/* 408424cc FUN_408424cc */

/* Boundary evidence: original MIPS .pdata 408424cc..4084275b. Semantic name remains unreviewed. */

int FUN_408424cc(int param_1)

{
  int iVar1;
  int *piVar2;
  size_t _Size;
  undefined4 *_Src;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  int *local_30;
  int local_2c;
  undefined4 *local_28 [2];
  
  iVar3 = -0x7fff0001;
  sVar4 = 0;
  local_30 = (int *)0x0;
  iVar1 = recv(*(SOCKET *)(param_1 + 0x18),*(char **)(param_1 + 0x2c),*(int *)(param_1 + 0x24),0);
  if (iVar1 != -1) {
    while (iVar1 != 0) {
      _Size = iVar1 + sVar4;
      _Src = *(undefined4 **)(param_1 + 0x2c);
      sVar5 = 0;
      sVar4 = _Size;
      if ((int)_Size % 4 == 0) {
        while (sVar4 = sVar5, _Size != 0) {
          if (local_30 == (int *)0x0) {
            if (((int)_Size < 0xc) || (((uint)_Src & 3) != 0)) {
              sVar4 = _Size;
              if (*(undefined4 **)(param_1 + 0x2c) != _Src) {
                memmove(*(undefined4 **)(param_1 + 0x2c),_Src,_Size);
              }
              break;
            }
            piVar2 = *(int **)(param_1 + 0x168);
            if (piVar2 == (int *)0x0) goto LAB_40842710;
            local_28[0] = (undefined4 *)0x0;
            iVar3 = (**(code **)(*piVar2 + 0x10))(piVar2,_Src[1],*_Src,local_28,_Src[2]);
            if (iVar3 < 0) goto LAB_40842710;
            iVar3 = (**(code **)*local_28[0])(local_28[0],&UNK_40841194,&local_30);
            if (iVar3 < 0) {
              return iVar3;
            }
            _Src = _Src + 3;
            _Size = _Size - 0xc;
          }
          local_2c = 0;
          iVar3 = (**(code **)(*local_30 + 0x10))(local_30,_Src,_Size,&local_2c);
          piVar2 = *(int **)(param_1 + 0x164);
          if ((piVar2 != (int *)0x0) && (local_2c != 0)) {
            (**(code **)(*piVar2 + 0x24))(piVar2,1,local_2c);
          }
          if (-1 < iVar3) break;
          _Size = _Size - local_2c;
          _Src = (undefined4 *)(local_2c + (int)_Src);
          if (iVar3 != -0x7ffcff90) {
            trap(0x400);
            if (local_2c == 0) {
              (**(code **)(*local_30 + 8))();
              goto LAB_40842710;
            }
            break;
          }
          (**(code **)(*local_30 + 8))();
          local_30 = (int *)0x0;
        }
      }
      if ((*(int *)(param_1 + 0x54) != 0) ||
         (iVar1 = recv(*(SOCKET *)(param_1 + 0x18),(char *)(sVar4 + *(int *)(param_1 + 0x2c)),
                       *(int *)(param_1 + 0x24) - sVar4,0), iVar1 == -1)) break;
    }
  }
LAB_40842710:
  SetThreadPriority((HANDLE)0x41,1);
  EventModify(*(undefined4 *)(param_1 + 0x10),3);
  return iVar3;
}



/* 4084275c FUN_4084275c */

/* Boundary evidence: original MIPS .pdata 4084275c..40842957. Semantic name remains unreviewed. */

int FUN_4084275c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *local_20;
  int local_1c;
  
  iVar1 = (*(code *)**(undefined4 **)*param_4)((undefined4 *)*param_4,&UNK_40841194,&local_20);
  if ((-1 < iVar1) &&
     ((*(int *)(*(int *)(param_1 + 8) + 0x34) + 0xcU < *(uint *)(*(int *)(param_1 + 8) + 0x1c) ||
      (iVar1 = FUN_40841c10(*(int *)(param_1 + 8),(undefined4 *)0x0,0), -1 < iVar1)))) {
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x34) + *(int *)(*(int *)(param_1 + 8) + 0x30))
         = param_3;
    *(undefined4 *)
     (*(int *)(*(int *)(param_1 + 8) + 0x34) + *(int *)(*(int *)(param_1 + 8) + 0x30) + 4) = param_2
    ;
    *(undefined4 *)
     (*(int *)(*(int *)(param_1 + 8) + 0x34) + *(int *)(*(int *)(param_1 + 8) + 0x30) + 8) = param_5
    ;
    *(int *)(*(int *)(param_1 + 8) + 0x34) = *(int *)(*(int *)(param_1 + 8) + 0x34) + 0xc;
    do {
      iVar1 = *(int *)(param_1 + 8);
      iVar3 = *(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x34);
      iVar1 = (**(code **)(*local_20 + 0xc))
                        (local_20,*(int *)(iVar1 + 0x30) + *(int *)(iVar1 + 0x34),iVar3,&local_1c);
      if (*(int *)(*(int *)(param_1 + 8) + 0x164) != 0) {
        piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x164);
        (**(code **)(*piVar2 + 0x24))(piVar2,0,local_1c);
      }
      if ((iVar1 < 0) || (local_1c != iVar3)) {
        *(int *)(*(int *)(param_1 + 8) + 0x34) = *(int *)(*(int *)(param_1 + 8) + 0x34) + local_1c;
        (**(code **)(*local_20 + 8))();
        if (*(int *)(*(int *)(param_1 + 8) + 0x38) != 0) {
          return iVar1;
        }
        iVar3 = FUN_40841c10(*(int *)(param_1 + 8),(undefined4 *)0x0,0);
        if (-1 < iVar3) {
          return iVar1;
        }
        return iVar3;
      }
      *(undefined4 *)(*(int *)(param_1 + 8) + 0x34) = *(undefined4 *)(*(int *)(param_1 + 8) + 0x1c);
      iVar1 = FUN_40841c10(*(int *)(param_1 + 8),(undefined4 *)0x0,0);
    } while (-1 < iVar1);
    (**(code **)(*local_20 + 8))();
  }
  return iVar1;
}



/* 40842958 FUN_40842958 */

/* Boundary evidence: original MIPS .pdata 40842958..40842a13. Semantic name remains unreviewed. */

undefined4
FUN_40842958(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = operator_new(0x14);
  if (pcVar1 == (char *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    pcVar1[0] = 'e';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    *(undefined4 *)(pcVar1 + 0x10) = param_5;
    *(undefined4 *)(pcVar1 + 4) = param_2;
    *(undefined4 *)(pcVar1 + 8) = param_3;
    *(undefined4 *)(pcVar1 + 0xc) = param_4;
    uVar2 = FUN_408419c8(*(int *)(param_1 + 8),pcVar1,0x14);
    operator_delete(pcVar1);
  }
  return uVar2;
}



/* 40842a14 FUN_40842a14 */

/* Boundary evidence: original MIPS .pdata 40842a14..40842acf. Semantic name remains unreviewed. */

undefined4
FUN_40842a14(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = operator_new(0x14);
  if (pcVar1 == (char *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    pcVar1[0] = 'n';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    *(undefined4 *)(pcVar1 + 0x10) = param_5;
    *(undefined4 *)(pcVar1 + 4) = param_2;
    *(undefined4 *)(pcVar1 + 8) = param_3;
    *(undefined4 *)(pcVar1 + 0xc) = param_4;
    uVar2 = FUN_408419c8(*(int *)(param_1 + 8),pcVar1,0x14);
    operator_delete(pcVar1);
  }
  return uVar2;
}



/* 40842ad0 FUN_40842ad0 */

/* Boundary evidence: original MIPS .pdata 40842ad0..40842af3. Semantic name remains unreviewed. */

void FUN_40842ad0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_res4 [3];
  
  local_res4[0] = param_2;
  FUN_40841c10(*(int *)(param_1 + 8),local_res4,param_3);
  return;
}



/* 40842af4 FUN_40842af4 */

/* Boundary evidence: original MIPS .pdata 40842af4..40842bd7. Semantic name remains unreviewed. */

undefined4
FUN_40842af4(int param_1,undefined4 param_2,uint param_3,int param_4,void *param_5,
            undefined4 param_6)

{
  char *pcVar1;
  size_t _Size;
  undefined4 uVar2;
  
  _Size = (param_3 + param_4) * 4;
  pcVar1 = operator_new(_Size + 0x14);
  if (pcVar1 == (char *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    pcVar1[0] = 'i';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    *(undefined4 *)(pcVar1 + 4) = param_6;
    *(undefined4 *)(pcVar1 + 8) = param_2;
    *(uint *)(pcVar1 + 0xc) = param_3 & 0xffff;
    *(size_t *)(pcVar1 + 0x10) = _Size;
    if (_Size != 0) {
      memcpy(pcVar1 + 0x14,param_5,_Size);
    }
    uVar2 = FUN_408419c8(*(int *)(param_1 + 8),pcVar1,_Size + 0x14);
    operator_delete(pcVar1);
  }
  return uVar2;
}



/* 40842bd8 FUN_40842bd8 */

/* Boundary evidence: original MIPS .pdata 40842bd8..40842ecf. Semantic name remains unreviewed. */

void FUN_40842bd8(int param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  HANDLE hObject;
  HANDLE hObject_00;
  DWORD DStack_30;
  DWORD DStack_2c;
  undefined2 local_28;
  undefined2 local_26;
  undefined4 local_24;
  
  hObject_00 = (HANDLE)0x0;
  hObject = (HANDLE)0x0;
  if (param_2 == (int *)0x0) {
    return;
  }
  *(int **)(*(int *)(param_1 + 8) + 0x164) = param_2;
  (**(code **)(**(int **)(param_1 + 8) + 4))();
  FUN_408417e0(*(int *)(param_1 + 8),0);
  local_28 = 2;
  iVar1 = (**(code **)*param_2)(param_2,&UNK_408410c0,*(int *)(param_1 + 8) + 0x168);
  if (((iVar1 < 0) ||
      (iVar1 = (**(code **)*param_2)(param_2,&UNK_408410e0,*(int *)(param_1 + 8) + 0x16c), iVar1 < 0
      )) || (piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x168),
            iVar1 = (**(code **)(*piVar3 + 0x20))
                              (piVar3,*(undefined4 *)(*(int *)(param_1 + 8) + 0x160)), iVar1 < 0)) {
    (**(code **)(**(int **)(param_1 + 8) + 8))();
    return;
  }
  piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x164);
  iVar1 = (**(code **)(*piVar3 + 0x10))(piVar3,*(int *)(param_1 + 8) + 0x14);
  if ((-1 < iVar1) &&
     (piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x164),
     iVar1 = (**(code **)(*piVar3 + 0x10))(piVar3,*(int *)(param_1 + 8) + 0x18), -1 < iVar1)) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x20) = 0x800;
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x24) = 0x800;
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x1c) = 0x800;
    pvVar2 = operator_new(*(uint *)(*(int *)(param_1 + 8) + 0x20));
    *(void **)(*(int *)(param_1 + 8) + 0x28) = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_40842e38;
    pvVar2 = operator_new(*(uint *)(*(int *)(param_1 + 8) + 0x24));
    *(void **)(*(int *)(param_1 + 8) + 0x2c) = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_40842e38;
    pvVar2 = operator_new(*(uint *)(*(int *)(param_1 + 8) + 0x1c));
    *(void **)(*(int *)(param_1 + 8) + 0x30) = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_40842e38;
    local_28 = 3;
    local_26 = 1;
    (**(code **)(*param_2 + 0xc))(param_2,&local_28);
    hObject_00 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40842290,*(LPVOID *)(param_1 + 8),0,
                              &DStack_30);
    if (hObject_00 != (HANDLE)0x0) {
      EventModify(*(undefined4 *)(*(int *)(param_1 + 8) + 0xc),2);
      hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_408424cc,*(LPVOID *)(param_1 + 8),0,
                             &DStack_2c);
      if (hObject != (HANDLE)0x0) {
        EventModify(*(undefined4 *)(*(int *)(param_1 + 8) + 0x10),2);
        WaitForSingleObject(*(HANDLE *)(*(int *)(param_1 + 8) + 0x10),0xffffffff);
        goto LAB_40842e38;
      }
    }
  }
  FUN_408417e0(*(int *)(param_1 + 8),1);
LAB_40842e38:
  FUN_4084166c(*(int *)(param_1 + 8));
  WaitForSingleObject(*(HANDLE *)(*(int *)(param_1 + 8) + 0xc),0xffffffff);
  local_28 = 1;
  local_24 = 0;
  if (hObject_00 != (HANDLE)0x0) {
    CloseHandle(hObject_00);
  }
  if (hObject != (HANDLE)0x0) {
    CloseHandle(hObject);
  }
  (**(code **)(**(int **)(param_1 + 8) + 8))();
  (**(code **)(*param_2 + 0xc))(param_2,&local_28);
  return;
}



/* 40842ed0 FUN_40842ed0 */

/* Boundary evidence: original MIPS .pdata 40842ed0..40842f1f. Semantic name remains unreviewed. */

undefined4 FUN_40842ed0(int param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_4084166c(*(int *)(param_1 + 8));
  }
  else if ((param_2 == 2) || (param_2 == 3)) {
    return 0x80004001;
  }
  return 0;
}



/* 40842fec FUN_40842fec */

/* Boundary evidence: original MIPS .pdata 40842fec..40843127. Semantic name remains unreviewed. */

int FUN_40842fec(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_408440b4 != (code *)0x0) {
      iVar2 = (*DAT_408440b4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_4084309c;
    FUN_40843480();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_408411c8(param_1,param_2);
  }
LAB_4084309c:
  if (((param_2 == 0) && (FUN_40843408(), iVar1 != 0)) && (DAT_408440b4 != (code *)0x0)) {
    iVar1 = (*DAT_408440b4)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40843128 FUN_40843128 */

/* Boundary evidence: original MIPS .pdata 40843128..40843153. Semantic name remains unreviewed. */

void FUN_40843128(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40843154 entry */

/* Boundary evidence: original MIPS .pdata 40843154..408431ab. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_408431ac();
  }
  FUN_40842fec(param_1,param_2,param_3);
  return;
}



/* 408431ac FUN_408431ac */

/* Boundary evidence: original MIPS .pdata 408431ac..4084321f. Semantic name remains unreviewed. */

void FUN_408431ac(void)

{
  uint uVar1;
  
  if ((DAT_40844078 == 0) || (DAT_40844078 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40844078 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40844078 == 0) {
      DAT_40844078 = 0xb064;
    }
  }
  DAT_4084407c = ~DAT_40844078;
  return;
}



/* 40843220 FUN_40843220 */

/* Boundary evidence: original MIPS .pdata 40843220..40843273. Semantic name remains unreviewed. */

void FUN_40843220(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_408432a0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40843274 FUN_40843274 */

/* Boundary evidence: original MIPS .pdata 40843274..4084329f. Semantic name remains unreviewed. */

undefined4 FUN_40843274(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40843220(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 408432a0 FUN_408432a0 */

/* Boundary evidence: original MIPS .pdata 408432a0..408432e7. Semantic name remains unreviewed. */

void FUN_408432a0(uint param_1)

{
  if ((param_1 == DAT_40844078) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 408432e8 FUN_408432e8 */

/* Boundary evidence: original MIPS .pdata 408432e8..40843407. Semantic name remains unreviewed. */

void FUN_408432e8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_408440a4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_408440ac;
    if (DAT_408440ac != (undefined4 *)0x0) {
      while (DAT_408440a8 = DAT_408440a8 + -1, _Memory <= DAT_408440a8) {
        if ((code *)*DAT_408440a8 != (code *)0x0) {
          (*(code *)*DAT_408440a8)();
          _Memory = DAT_408440ac;
        }
      }
      free(_Memory);
      DAT_408440a8 = (undefined4 *)0x0;
      DAT_408440ac = (undefined4 *)0x0;
    }
    FUN_4084342c((undefined4 *)&DAT_40841010,(undefined4 *)&DAT_40841014);
  }
  FUN_4084342c((undefined4 *)&DAT_40841018,(undefined4 *)&DAT_4084101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_408440b0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40843408 FUN_40843408 */

/* Boundary evidence: original MIPS .pdata 40843408..4084342b. Semantic name remains unreviewed. */

void FUN_40843408(void)

{
  FUN_408432e8(0,0,1);
  return;
}



/* 4084342c FUN_4084342c */

/* Boundary evidence: original MIPS .pdata 4084342c..4084347f. Semantic name remains unreviewed. */

void FUN_4084342c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40843480 FUN_40843480 */

/* Boundary evidence: original MIPS .pdata 40843480..408434bb. Semantic name remains unreviewed. */

void FUN_40843480(void)

{
  FUN_4084342c((undefined4 *)&DAT_40841008,(undefined4 *)&DAT_4084100c);
  FUN_4084342c((undefined4 *)&DAT_40841000,(undefined4 *)&DAT_40841004);
  return;
}


