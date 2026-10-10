/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0841394 FUN_c0841394 */

/* Boundary evidence: original MIPS .pdata c0841394..c08413c7. Semantic name remains unreviewed. */

void * FUN_c0841394(int param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0x20),0x30);
  return param_2;
}



/* c08413c8 FUN_c08413c8 */

/* Boundary evidence: original MIPS .pdata c08413c8..c08413ff. Semantic name remains unreviewed. */

void FUN_c08413c8(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = 2;
  }
  (**(code **)(*param_1 + 0x40))(param_1,uVar1);
  return;
}



/* c0841400 register_usb_stack */

void register_usb_stack(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
                    /* 0x1400  1  register_usb_stack */
  iVar1 = DAT_c08470fc;
  *(undefined4 *)(DAT_c08470fc + 0xfc) = param_1;
  *(undefined4 *)(iVar1 + 0x100) = *param_2;
  *(undefined4 *)(iVar1 + 0x104) = param_2[1];
  *(undefined4 *)(iVar1 + 0x108) = param_2[2];
  *param_3 = PTR_FUN_c08470ec;
  param_3[1] = PTR_FUN_c08470f0;
  return;
}



/* c0841440 unregister_usb_stack */

void unregister_usb_stack(void)

{
                    /* 0x1440  2  unregister_usb_stack */
  *(undefined4 *)(DAT_c08470fc + 0xfc) = 0;
  return;
}



/* c0841458 FUN_c0841458 */

/* Boundary evidence: original MIPS .pdata c0841458..c084148b. Semantic name remains unreviewed. */

bool FUN_c0841458(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x80))();
  return (uVar1 & 0x10) == 0;
}



/* c084148c FUN_c084148c */

/* Boundary evidence: original MIPS .pdata c084148c..c08414bf. Semantic name remains unreviewed. */

bool FUN_c084148c(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x80))();
  return (uVar1 & 0x20) == 0;
}



/* c08414f4 FUN_c08414f4 */

/* Boundary evidence: original MIPS .pdata c08414f4..c0841513. Semantic name remains unreviewed. */

undefined4 FUN_c08414f4(int *param_1)

{
  FUN_c0843354(param_1);
  return 1;
}



/* c0841514 FUN_c0841514 */

/* Boundary evidence: original MIPS .pdata c0841514..c0841563. Semantic name remains unreviewed. */

bool FUN_c0841514(int *param_1)

{
  bool bVar1;
  
  if (*(int *)(DAT_c08470fc + 0xfc) == 0) {
    bVar1 = false;
  }
  else {
    (*(code *)param_1[0x42])(param_1[0x3f],1);
    bVar1 = FUN_c0841ea0(param_1);
  }
  return bVar1;
}



/* c0841564 FUN_c0841564 */

/* Boundary evidence: original MIPS .pdata c0841564..c08415ab. Semantic name remains unreviewed. */

bool FUN_c0841564(int *param_1)

{
  bool bVar1;
  
  bVar1 = FUN_c0841f48(param_1);
  (*(code *)param_1[0x42])(param_1[0x3f],0);
  return bVar1;
}



/* c08415ac FUN_c08415ac */

/* Boundary evidence: original MIPS .pdata c08415ac..c08415c7. Semantic name remains unreviewed. */

void FUN_c08415ac(int *param_1)

{
  FUN_c0841e58(param_1);
  return;
}



/* c08415c8 FUN_c08415c8 */

/* Boundary evidence: original MIPS .pdata c08415c8..c08415f7. Semantic name remains unreviewed. */

void FUN_c08415c8(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
                 ,uint param_6,undefined4 *param_7)

{
  FUN_c0841fe0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* c08415f8 FUN_c08415f8 */

/* Boundary evidence: original MIPS .pdata c08415f8..c0841613. Semantic name remains unreviewed. */

void FUN_c08415f8(int param_1)

{
  FUN_c084215c(param_1);
  return;
}



/* c0841614 FUN_c0841614 */

/* Boundary evidence: original MIPS .pdata c0841614..c084162f. Semantic name remains unreviewed. */

void FUN_c0841614(int *param_1)

{
  FUN_c08421cc(param_1);
  return;
}



/* c0841630 FUN_c0841630 */

/* Boundary evidence: original MIPS .pdata c0841630..c084164b. Semantic name remains unreviewed. */

void FUN_c0841630(int *param_1)

{
  FUN_c0842224(param_1);
  return;
}



/* c084164c FUN_c084164c */

/* Boundary evidence: original MIPS .pdata c084164c..c0841667. Semantic name remains unreviewed. */

void FUN_c084164c(int *param_1,int param_2)

{
  FUN_c08422a4(param_1,param_2);
  return;
}



/* c0841670 FUN_c0841670 */

/* Boundary evidence: original MIPS .pdata c0841670..c08416a3. Semantic name remains unreviewed. */

void * FUN_c0841670(int param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0x20),0x30);
  return param_2;
}



/* c08416a4 FUN_c08416a4 */

/* Boundary evidence: original MIPS .pdata c08416a4..c08416bf. Semantic name remains unreviewed. */

void FUN_c08416a4(int param_1)

{
  FUN_c08423b0(param_1);
  return;
}



/* c08416c0 FUN_c08416c0 */

/* Boundary evidence: original MIPS .pdata c08416c0..c08416db. Semantic name remains unreviewed. */

void FUN_c08416c0(int *param_1,byte *param_2,int param_3)

{
  FUN_c0842518(param_1,param_2,param_3);
  return;
}



/* c08416e4 FUN_c08416e4 */

/* Boundary evidence: original MIPS .pdata c08416e4..c0841727. Semantic name remains unreviewed. */

void FUN_c08416e4(int param_1,int param_2,int param_3)

{
  if (((*(int *)(DAT_c08470fc + 0xfc) != 0) && (param_2 != 0)) && (param_3 != 0)) {
    (**(code **)(param_1 + 0x100))(*(undefined4 *)(param_1 + 0xfc));
  }
  return;
}



/* c0841728 FUN_c0841728 */

/* Boundary evidence: original MIPS .pdata c0841728..c0841777. Semantic name remains unreviewed. */

undefined4 FUN_c0841728(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(DAT_c08470fc + 0xfc) == 0) {
    uVar1 = 0;
  }
  else if ((param_2 != 0) && (param_3 != 0)) {
    uVar1 = (**(code **)(param_1 + 0x104))(*(undefined4 *)(param_1 + 0xfc));
  }
  return uVar1;
}



/* c08417a8 FUN_c08417a8 */

/* Boundary evidence: original MIPS .pdata c08417a8..c0841873. Semantic name remains unreviewed. */

int FUN_c08417a8(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (*(int *)(DAT_c08470fc + 0xfc) == 0) {
    iVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    uVar3 = param_1[0x44] ^ param_1[0x43];
    param_1[0x44] = param_1[0x43];
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    if ((uVar3 & 0x20) != 0) {
      uVar2 = 0x10;
    }
    if ((uVar3 & 0x80) != 0) {
      uVar2 = uVar2 | 0x20;
    }
    if ((uVar3 & 0x10) != 0) {
      uVar2 = uVar2 | 8;
    }
    if (uVar2 != 0) {
      (**(code **)(*param_1 + 0x48))(param_1,uVar2,param_1[0x43]);
    }
    iVar1 = param_1[0x43];
  }
  return iVar1;
}



/* c0841874 FUN_c0841874 */

/* Boundary evidence: original MIPS .pdata c0841874..c08418ab. Semantic name remains unreviewed. */

void FUN_c0841874(int *param_1)

{
  if (*(int *)(DAT_c08470fc + 0xfc) != 0) {
    (**(code **)(*param_1 + 0x80))();
  }
  return;
}



/* c08418ac FUN_c08418ac */

/* Boundary evidence: original MIPS .pdata c08418ac..c084191b. Semantic name remains unreviewed. */

void FUN_c08418ac(int *param_1,int param_2)

{
  if (*(int *)(DAT_c08470fc + 0xfc) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    param_1[0x43] = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    (**(code **)(*param_1 + 0x40))(param_1,8);
  }
  return;
}



/* c084191c FUN_c084191c */

/* Boundary evidence: original MIPS .pdata c084191c..c0841a87. Semantic name remains unreviewed. */

int * FUN_c084191c(LPCWSTR param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  LSTATUS LVar2;
  HKEY local_48;
  DWORD local_44;
  BYTE aBStack_40 [32];
  uint local_20;
  
  local_20 = DAT_c08470f4;
  piVar1 = operator_new(0x114);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    FUN_c0841d54(piVar1,(int)param_1,param_2,param_3);
    *piVar1 = (int)&PTR_FUN_c084103c;
    piVar1[0x43] = 0;
    piVar1[0x44] = 0;
  }
  if (piVar1 != (int *)0x0) {
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,&local_48);
    if (LVar2 == 0) {
      local_44 = 0x20;
      LVar2 = RegQueryValueExW(local_48,L"Name",(LPDWORD)0x0,(LPDWORD)0x0,aBStack_40,&local_44);
      RegCloseKey(local_48);
      if (LVar2 == 0) {
        (**(code **)(*piVar1 + 4))(piVar1);
        DAT_c08470fc = piVar1;
        piVar1[0x3f] = 0;
        FUN_c0846590(local_20);
        return piVar1;
      }
    }
    (**(code **)*piVar1)(piVar1,1);
  }
  FUN_c0846590(local_20);
  return (int *)0x0;
}



/* c0841a88 FUN_c0841a88 */

/* Boundary evidence: original MIPS .pdata c0841a88..c0841abb. Semantic name remains unreviewed. */

void FUN_c0841a88(undefined4 *param_1)

{
  DAT_c08470fc = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,1);
  }
  return;
}



/* c0841abc FUN_c0841abc */

/* Boundary evidence: original MIPS .pdata c0841abc..c0841ad7. Semantic name remains unreviewed. */

void FUN_c0841abc(int *param_1,int param_2)

{
  FUN_c08418ac(param_1,param_2);
  return;
}



/* c0841ad8 FUN_c0841ad8 */

/* Boundary evidence: original MIPS .pdata c0841ad8..c0841b2f. Semantic name remains unreviewed. */

undefined4 * FUN_c0841ad8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c084103c;
  FUN_c0843490(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0841b30 FUN_c0841b30 */

/* Boundary evidence: original MIPS .pdata c0841b30..c0841b8b. Semantic name remains unreviewed. */

undefined4 FUN_c0841b30(int param_1)

{
  DWORD DVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    DVar1 = ResumeThread(*(HANDLE *)(param_1 + 8));
    if (DVar1 == 0xffffffff) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 1;
}



/* c0841b8c FUN_c0841b8c */

/* Boundary evidence: original MIPS .pdata c0841b8c..c0841c0b. Semantic name remains unreviewed. */

undefined4 FUN_c0841b8c(int param_1,DWORD param_2)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  if (((*(int *)(param_1 + 8) == 0) || (iVar1 = FUN_c0841b30(param_1), iVar1 == 0)) ||
     (DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 8),param_2), DVar2 != 0)) {
    uVar3 = 0;
  }
  else {
    CloseHandle(*(HANDLE *)(param_1 + 8));
    uVar3 = 1;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return uVar3;
}



/* c0841c0c FUN_c0841c0c */

/* Boundary evidence: original MIPS .pdata c0841c0c..c0841c7f. Semantic name remains unreviewed. */

BOOL FUN_c0841c0c(int param_1)

{
  BOOL BVar1;
  
  if (*(HANDLE *)(param_1 + 8) == (HANDLE)0x0) {
    BVar1 = 1;
  }
  else {
    BVar1 = TerminateThread(*(HANDLE *)(param_1 + 8),0xffffffff);
    *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
    CloseHandle(*(HANDLE *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return BVar1;
}



/* c0841c80 FUN_c0841c80 */

/* Boundary evidence: original MIPS .pdata c0841c80..c0841cbf. Semantic name remains unreviewed. */

void FUN_c0841c80(undefined4 *param_1)

{
  DWORD dwExitCode;
  
  dwExitCode = (**(code **)*param_1)(param_1);
                    /* WARNING: Subroutine does not return */
  param_1[5] = dwExitCode;
  ExitThread(dwExitCode);
}



/* c0841cc0 FUN_c0841cc0 */

/* Boundary evidence: original MIPS .pdata c0841cc0..c0841d53. Semantic name remains unreviewed. */

undefined4 FUN_c0841cc0(int param_1)

{
  DWORD DVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  while( true ) {
    if (iVar2 != 0) {
      return 0;
    }
    if (*(HANDLE *)(param_1 + 0x1c) == (HANDLE)0x0) break;
    if (*(int *)(param_1 + 0x18) == 0) {
      return 0;
    }
    DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x1c),0xffffffff);
    if (DVar1 == 0) {
      if (*(int *)(param_1 + 4) != 0) {
        return 0;
      }
      (**(code **)(**(int **)(param_1 + 0x18) + 0x40))(*(int **)(param_1 + 0x18),0);
    }
    iVar2 = *(int *)(param_1 + 4);
  }
  return 0;
}



/* c0841d54 FUN_c0841d54 */

/* Boundary evidence: original MIPS .pdata c0841d54..c0841e57. Semantic name remains unreviewed. */

undefined4 * FUN_c0841d54(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  LSTATUS LVar2;
  LPBYTE lpData;
  DWORD local_20 [2];
  
  param_1[1] = 0;
  if (param_2 != 0) {
    uVar1 = OpenDeviceKey(param_2);
    param_1[1] = uVar1;
  }
  *param_1 = &PTR_FUN_c08411a4;
  param_1[2] = param_3;
  param_1[3] = param_4;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1e));
  uVar1 = CreateBusAccessHandle(param_2);
  param_1[4] = uVar1;
  param_1[0x16] = 0xffffffff;
  param_1[0x17] = 0;
  param_1[5] = 0;
  param_1[0x3e] = 0;
  param_1[0x15] = 0;
  param_1[0x3d] = 0;
  memset(param_1 + 8,0,0x30);
  local_20[0] = 4;
  lpData = (LPBYTE)(param_1 + 0x23);
  local_20[1] = 0;
  LVar2 = RegQueryValueExW((HKEY)param_1[1],L"Priority256",(LPDWORD)0x0,local_20 + 1,lpData,local_20
                          );
  if (LVar2 != 0) {
    lpData[0] = 0x9f;
    lpData[1] = '\0';
    lpData[2] = '\0';
    lpData[3] = '\0';
  }
  return param_1;
}



/* c0841e58 FUN_c0841e58 */

/* Boundary evidence: original MIPS .pdata c0841e58..c0841e9f. Semantic name remains unreviewed. */

void FUN_c0841e58(int *param_1)

{
  (**(code **)(*param_1 + 0x3c))(param_1,1);
  (**(code **)(*param_1 + 0x78))(param_1,1);
  return;
}



/* c0841ea0 FUN_c0841ea0 */

/* Boundary evidence: original MIPS .pdata c0841ea0..c0841f47. Semantic name remains unreviewed. */

bool FUN_c0841ea0(int *param_1)

{
  LONG LVar1;
  int iVar2;
  code *pcVar3;
  
  LVar1 = InterlockedExchange(param_1 + 5,1);
  if (LVar1 == 0) {
    iVar2 = DDKPwr_RequestLevel(param_1[0x16],0);
    pcVar3 = *(code **)(*param_1 + 0xb4);
    param_1[0x17] = iVar2;
    (*pcVar3)(param_1);
    (**(code **)(*param_1 + 0x94))(param_1,1);
    (**(code **)(*param_1 + 0x68))(param_1,1);
    (**(code **)(*param_1 + 0x54))(param_1,1);
  }
  return LVar1 == 0;
}



/* c0841f48 FUN_c0841f48 */

/* Boundary evidence: original MIPS .pdata c0841f48..c0841fdf. Semantic name remains unreviewed. */

bool FUN_c0841f48(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedExchange(param_1 + 5,0);
  if (LVar1 == 1) {
    (**(code **)(*param_1 + 0x54))(param_1,0);
    (**(code **)(*param_1 + 0x68))(param_1,0);
    (**(code **)(*param_1 + 0x94))(param_1,0);
    DDKPwr_ReleaseLevel(param_1[0x16],param_1[0x17]);
    param_1[0x17] = 0;
  }
  return LVar1 == 1;
}



/* c0841fe0 FUN_c0841fe0 */

/* Boundary evidence: original MIPS .pdata c0841fe0..c084215b. Semantic name remains unreviewed. */

int FUN_c0841fe0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
                uint param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  void *_Src;
  code *pcVar3;
  undefined1 auStack_48 [48];
  
  if (param_2 == 0x321000) {
    if (((param_5 != (undefined4 *)0x0) && (0x2f < param_6)) && (param_7 != (undefined4 *)0x0)) {
      pcVar3 = *(code **)(*param_1 + 0x38);
      param_1[7] = 1;
      _Src = (void *)(*pcVar3)(param_1,auStack_48);
      memcpy(param_5,_Src,0x30);
      *param_7 = 0x30;
      return 1;
    }
  }
  else {
    if (param_2 != 0x321008) {
      SetLastError(0x57);
      return 0;
    }
    if (((param_5 != (undefined4 *)0x0) && (3 < param_6)) &&
       ((param_7 != (undefined4 *)0x0 && (param_1[0x16] != -1)))) {
      param_1[7] = 1;
      iVar1 = DDKPwr_SetDeviceLevel(param_1[0x16],*param_5,0);
      if (iVar1 != 1) {
        SetLastError(0x57);
        return iVar1;
      }
      uVar2 = DDKPwr_GetDeviceLevel(param_1[0x16]);
      *param_5 = uVar2;
      *param_7 = 4;
      return 1;
    }
  }
  SetLastError(0x57);
  return 0;
}



/* c084215c FUN_c084215c */

undefined4 FUN_c084215c(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0x19;
  return 1;
}



/* c0842174 FUN_c0842174 */

/* Boundary evidence: original MIPS .pdata c0842174..c08421cb. Semantic name remains unreviewed. */

undefined4 FUN_c0842174(int *param_1,undefined4 param_2)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x28))(param_1);
    param_2 = (**(code **)(*param_1 + 0x34))(param_1);
  }
  return param_2;
}



/* c08421cc FUN_c08421cc */

/* Boundary evidence: original MIPS .pdata c08421cc..c0842223. Semantic name remains unreviewed. */

undefined4 FUN_c08421cc(int *param_1)

{
  if (param_1[7] == 0) {
    (**(code **)(*param_1 + 0x2c))(param_1);
    if (param_1[4] != 0) {
      SetDevicePowerState(param_1[4],4,0);
    }
  }
  return 1;
}



/* c0842224 FUN_c0842224 */

/* Boundary evidence: original MIPS .pdata c0842224..c08422a3. Semantic name remains unreviewed. */

undefined4 FUN_c0842224(int *param_1)

{
  int iVar1;
  
  if (param_1[7] == 0) {
    if (param_1[4] != 0) {
      SetDevicePowerState(param_1[4],0,0);
    }
    (**(code **)(*param_1 + 0x30))(param_1);
  }
  param_1[0x14] = 1;
  if ((param_1[0x15] != 0) && (iVar1 = *(int *)(param_1[0x15] + 0x1c), iVar1 != 0)) {
    EventModify(iVar1,3);
  }
  return 1;
}



/* c08422a4 FUN_c08422a4 */

/* Boundary evidence: original MIPS .pdata c08422a4..c08423af. Semantic name remains unreviewed. */

undefined4 FUN_c08422a4(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1[6];
  if ((iVar1 == param_2) || (param_2 == -1)) {
    uVar2 = 1;
  }
  else {
    if (((iVar1 != 3) && (iVar1 != 4)) && ((param_2 == 3 || (param_2 == 4)))) {
      (**(code **)(*param_1 + 0x2c))(param_1);
    }
    if ((param_1[4] == 0) || (iVar1 = SetDevicePowerState(param_1[4],param_2,0), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      param_1[6] = param_2;
      uVar2 = 1;
    }
    if ((((param_1[6] == 3) || (param_1[6] == 4)) && (param_2 != 3)) && (param_2 != 4)) {
      (**(code **)(*param_1 + 0x30))(param_1);
      param_1[0x14] = 1;
    }
  }
  return uVar2;
}



/* c08423b0 FUN_c08423b0 */

/* Boundary evidence: original MIPS .pdata c08423b0..c08423f3. Semantic name remains unreviewed. */

undefined4 FUN_c08423b0(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x78));
  *(undefined4 *)(param_1 + 0x74) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x78));
  return 1;
}



/* c08423f4 FUN_c08423f4 */

/* Boundary evidence: original MIPS .pdata c08423f4..c08424c7. Semantic name remains unreviewed. */

undefined4 FUN_c08423f4(int *param_1,uint param_2)

{
  LONG LVar1;
  uint uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1e);
  EnterCriticalSection(lpCriticalSection);
  param_1[0x1d] = param_1[0x1d] | param_2;
  LeaveCriticalSection(lpCriticalSection);
  LVar1 = InterlockedExchange(param_1 + 0x14,0);
  if (LVar1 != 0) {
    if (param_1[5] == 0) {
      uVar2 = (**(code **)(*param_1 + 0x80))(param_1);
      if ((uVar2 & 0x80) != 0) {
        CeEventHasOccurred(9,0);
      }
    }
    else {
      (**(code **)(*param_1 + 0x48))(param_1,0x2000,0);
    }
  }
  EnterCriticalSection(lpCriticalSection);
  FUN_c0845300(param_1[2]);
  LeaveCriticalSection(lpCriticalSection);
  return 1;
}



/* c08424c8 FUN_c08424c8 */

/* Boundary evidence: original MIPS .pdata c08424c8..c0842517. Semantic name remains unreviewed. */

undefined4 FUN_c08424c8(int param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x78));
  uVar1 = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0x74) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x78));
  return uVar1;
}



/* c0842518 FUN_c0842518 */

/* Boundary evidence: original MIPS .pdata c0842518..c08425f3. Semantic name remains unreviewed. */

undefined4 FUN_c0842518(int *param_1,byte *param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_2 != (byte *)0x0) {
    bVar2 = *param_2;
    if ((((param_1[0x26] & 0x40U) == 0) ||
        (iVar1 = (**(code **)(*param_1 + 0x90))(param_1), iVar1 == 0)) &&
       ((bVar2 != 0 || ((param_1[0x26] & 0x800U) == 0)))) {
      uVar3 = 1;
      if (((param_1[0x26] & 0x400U) == 0) || (param_3 == 0)) {
        if ((uint)bVar2 == (int)*(char *)((int)param_1 + 0xa9)) {
          (**(code **)(*param_1 + 0x48))(param_1,2,0);
        }
      }
      else {
        bVar2 = *(byte *)((int)param_1 + 0xa7);
      }
      *param_2 = bVar2;
    }
  }
  return uVar3;
}



/* c08425f4 FUN_c08425f4 */

/* Boundary evidence: original MIPS .pdata c08425f4..c084266b. Semantic name remains unreviewed. */

undefined4 FUN_c08425f4(int param_1,uint param_2,uint param_3)

{
  FUN_c08447a4(*(int *)(param_1 + 8),param_2);
  if (((*(int *)(param_1 + 0x14) == 0) && ((param_2 & 0x20) != 0)) && ((param_3 & 0x80) != 0)) {
    CeEventHasOccurred(9,0);
  }
  return 1;
}



/* c084266c FUN_c084266c */

/* Boundary evidence: original MIPS .pdata c084266c..c08426cf. Semantic name remains unreviewed. */

undefined4 FUN_c084266c(int *param_1,uint param_2)

{
  if ((param_2 & 8) != 0) {
    (**(code **)(*param_1 + 0x74))(param_1);
  }
  if ((param_2 & 4) != 0) {
    (**(code **)(*param_1 + 100))(param_1);
  }
  return 1;
}



/* c08426d0 FUN_c08426d0 */

/* Boundary evidence: original MIPS .pdata c08426d0..c084273f. Semantic name remains unreviewed. */

void FUN_c08426d0(int *param_1,uint param_2)

{
  if (param_2 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    param_1[0x3e] = param_1[0x3e] | param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    (**(code **)(*param_1 + 0x48))(param_1,0x80,0);
  }
  return;
}



/* c0842740 FUN_c0842740 */

/* Boundary evidence: original MIPS .pdata c0842740..c084278f. Semantic name remains unreviewed. */

undefined4 FUN_c0842740(int param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x60));
  uVar1 = *(undefined4 *)(param_1 + 0xf8);
  *(undefined4 *)(param_1 + 0xf8) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x60));
  return uVar1;
}



/* c0842790 FUN_c0842790 */

/* Boundary evidence: original MIPS .pdata c0842790..c0842897. Semantic name remains unreviewed. */

void FUN_c0842790(int *param_1)

{
  code *pcVar1;
  
  *(undefined2 *)(param_1 + 0x2b) = 0xffff;
  *(undefined2 *)((int)param_1 + 0xae) = 0xffff;
  param_1[0x30] = 0x20000;
  param_1[0x2c] = 1;
  param_1[0x31] = 1;
  *(undefined2 *)(param_1 + 0x35) = 0xf;
  param_1[0x2e] = 0x10;
  param_1[0x2f] = 0x10;
  pcVar1 = *(code **)(*param_1 + 0xbc);
  param_1[0x2d] = 0;
  param_1[0x32] = 0x1ff;
  param_1[0x34] = 0x1007fffb;
  param_1[0x33] = 0x7f;
  *(undefined2 *)((int)param_1 + 0xd6) = 0x1f05;
  (*pcVar1)(param_1,0,1);
  param_1[0x25] = 0x2580;
  param_1[0x24] = 0x1c;
  (**(code **)(*param_1 + 0xa0))(param_1,0x2580,0);
  *(undefined1 *)((int)param_1 + 0xa2) = 8;
  (**(code **)(*param_1 + 0xa4))(param_1,8);
  pcVar1 = *(code **)(*param_1 + 0xa8);
  *(undefined1 *)((int)param_1 + 0xa3) = 0;
  (*pcVar1)(param_1,0);
  pcVar1 = *(code **)(*param_1 + 0xac);
  *(undefined1 *)(param_1 + 0x29) = 0;
  (*pcVar1)(param_1,0);
  return;
}



/* c0842898 FUN_c0842898 */

/* Boundary evidence: original MIPS .pdata c0842898..c0842a23. Semantic name remains unreviewed. */

undefined4 FUN_c0842898(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_38 [4];
  int local_34;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  
  uVar2 = 1;
  if (((param_1[5] == 0) || (param_2 == (int *)0x0)) || (*param_2 != 0x1c)) {
    uVar2 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    memcpy(auStack_38,param_2,0x1c);
    iVar1 = param_2[1];
    if ((iVar1 != param_1[0x25]) &&
       ((iVar1 == 0 ||
        (iVar1 = (**(code **)(*param_1 + 0xa0))(param_1,iVar1,param_1[0x3b]), iVar1 == 0)))) {
      local_34 = param_1[0x25];
      uVar2 = 0;
    }
    if ((*(char *)((int)param_2 + 0x12) != *(char *)((int)param_1 + 0xa2)) &&
       (iVar1 = (**(code **)(*param_1 + 0xa4))(param_1), iVar1 == 0)) {
      local_26 = *(undefined1 *)((int)param_1 + 0xa2);
      uVar2 = 0;
    }
    if ((*(char *)((int)param_2 + 0x13) != *(char *)((int)param_1 + 0xa3)) &&
       (iVar1 = (**(code **)(*param_1 + 0xa8))(param_1), iVar1 == 0)) {
      local_25 = *(undefined1 *)((int)param_1 + 0xa3);
      uVar2 = 0;
    }
    if (((char)param_2[5] != (char)param_1[0x29]) &&
       (iVar1 = (**(code **)(*param_1 + 0xac))(param_1), iVar1 == 0)) {
      local_24 = (undefined1)param_1[0x29];
      uVar2 = 0;
    }
    memcpy(param_1 + 0x24,auStack_38,0x1c);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  }
  return uVar2;
}



/* c0842a8c FUN_c0842a8c */

/* Boundary evidence: original MIPS .pdata c0842a8c..c0842ae3. Semantic name remains unreviewed. */

int * FUN_c0842a8c(LPCWSTR param_1,undefined4 param_2,HLOCAL param_3)

{
  int *piVar1;
  
  if (param_3 != (HLOCAL)0x0) {
    *(undefined4 *)((int)param_3 + 4) = 0;
    piVar1 = FUN_c084191c(param_1,param_2,param_3);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  LocalFree(param_3);
  return (int *)0x0;
}



/* c0842ae4 FUN_c0842ae4 */

/* Boundary evidence: original MIPS .pdata c0842ae4..c0842b2b. Semantic name remains unreviewed. */

undefined4 FUN_c0842ae4(undefined4 *param_1)

{
  undefined4 uVar1;
  HLOCAL hMem;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    hMem = (HLOCAL)param_1[3];
    FUN_c0841a88(param_1);
    if (hMem != (HLOCAL)0x0) {
      LocalFree(hMem);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* c0842b2c FUN_c0842b2c */

/* Boundary evidence: original MIPS .pdata c0842b2c..c0842b5b. Semantic name remains unreviewed. */

undefined4 FUN_c0842b2c(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  return 1;
}



/* c0842b5c FUN_c0842b5c */

/* Boundary evidence: original MIPS .pdata c0842b5c..c0842b87. Semantic name remains unreviewed. */

undefined4 FUN_c0842b5c(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x10))();
  }
  return uVar1;
}



/* c0842b88 FUN_c0842b88 */

/* Boundary evidence: original MIPS .pdata c0842b88..c0842bb3. Semantic name remains unreviewed. */

undefined4 FUN_c0842b88(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x14))();
  }
  return uVar1;
}



/* c0842bb4 FUN_c0842bb4 */

/* Boundary evidence: original MIPS .pdata c0842bb4..c0842bdf. Semantic name remains unreviewed. */

undefined4 FUN_c0842bb4(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x44))();
  }
  return uVar1;
}



/* c0842be0 FUN_c0842be0 */

/* Boundary evidence: original MIPS .pdata c0842be0..c0842c0b. Semantic name remains unreviewed. */

undefined4 FUN_c0842be0(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x70))();
  }
  return uVar1;
}



/* c0842c0c FUN_c0842c0c */

/* Boundary evidence: original MIPS .pdata c0842c0c..c0842c37. Semantic name remains unreviewed. */

void FUN_c0842c0c(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x58))();
  }
  return;
}



/* c0842c38 FUN_c0842c38 */

/* Boundary evidence: original MIPS .pdata c0842c38..c0842c67. Semantic name remains unreviewed. */

void FUN_c0842c38(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x7c))();
  }
  return;
}



/* c0842c68 FUN_c0842c68 */

/* Boundary evidence: original MIPS .pdata c0842c68..c0842c97. Semantic name remains unreviewed. */

void FUN_c0842c68(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x98))();
  }
  return;
}



/* c0842c98 FUN_c0842c98 */

/* Boundary evidence: original MIPS .pdata c0842c98..c0842cc7. Semantic name remains unreviewed. */

undefined4 FUN_c0842c98(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x6c))();
  }
  return uVar1;
}



/* c0842cc8 FUN_c0842cc8 */

/* Boundary evidence: original MIPS .pdata c0842cc8..c0842cf7. Semantic name remains unreviewed. */

undefined4 FUN_c0842cc8(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x20))();
  }
  return uVar1;
}



/* c0842cf8 FUN_c0842cf8 */

/* Boundary evidence: original MIPS .pdata c0842cf8..c0842d27. Semantic name remains unreviewed. */

undefined4 FUN_c0842cf8(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x24))();
  }
  return uVar1;
}



/* c0842d28 FUN_c0842d28 */

/* Boundary evidence: original MIPS .pdata c0842d28..c0842d57. Semantic name remains unreviewed. */

void FUN_c0842d28(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x84))(param_1,0);
  }
  return;
}



/* c0842d58 FUN_c0842d58 */

/* Boundary evidence: original MIPS .pdata c0842d58..c0842d87. Semantic name remains unreviewed. */

void FUN_c0842d58(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x84))(param_1,1);
  }
  return;
}



/* c0842d88 FUN_c0842d88 */

/* Boundary evidence: original MIPS .pdata c0842d88..c0842db7. Semantic name remains unreviewed. */

void FUN_c0842d88(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x88))(param_1,0);
  }
  return;
}



/* c0842db8 FUN_c0842db8 */

/* Boundary evidence: original MIPS .pdata c0842db8..c0842de7. Semantic name remains unreviewed. */

void FUN_c0842db8(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x88))(param_1,1);
  }
  return;
}



/* c0842de8 FUN_c0842de8 */

/* Boundary evidence: original MIPS .pdata c0842de8..c0842e4b. Semantic name remains unreviewed. */

undefined4 FUN_c0842de8(int *param_1,undefined4 param_2)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0xbc))(param_1,1,0);
    (**(code **)(*param_1 + 0xa0))(param_1,param_2,1);
  }
  return 1;
}



/* c0842e4c FUN_c0842e4c */

/* Boundary evidence: original MIPS .pdata c0842e4c..c0842e7f. Semantic name remains unreviewed. */

undefined4 FUN_c0842e4c(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0xbc))(param_1,0,1);
  }
  return 1;
}



/* c0842e80 FUN_c0842e80 */

/* Boundary evidence: original MIPS .pdata c0842e80..c0842eaf. Semantic name remains unreviewed. */

void FUN_c0842e80(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x9c))(param_1,0);
  }
  return;
}



/* c0842eb0 FUN_c0842eb0 */

/* Boundary evidence: original MIPS .pdata c0842eb0..c0842edf. Semantic name remains unreviewed. */

void FUN_c0842eb0(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x9c))(param_1,1);
  }
  return;
}



/* c0842ee0 FUN_c0842ee0 */

/* Boundary evidence: original MIPS .pdata c0842ee0..c0842f13. Semantic name remains unreviewed. */

undefined4 FUN_c0842ee0(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x5c))();
  }
  return 1;
}



/* c0842f14 FUN_c0842f14 */

/* Boundary evidence: original MIPS .pdata c0842f14..c084302b. Semantic name remains unreviewed. */

undefined4 FUN_c0842f14(int *param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_38 [8];
  uint local_30;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == (uint *)0x0) {
    return 0xffffffff;
  }
  memcpy(auStack_38,param_1 + 0x24,0x1c);
  iVar4 = 1;
  if ((local_30 & 4) != 0) {
    iVar1 = (**(code **)(*param_1 + 0x8c))(param_1);
    uVar3 = 1;
    if (iVar1 != 0) goto LAB_c0842f88;
  }
  uVar3 = 0;
LAB_c0842f88:
  *param_2 = (*param_2 ^ uVar3) & 1 ^ *param_2;
  memcpy(auStack_38,param_1 + 0x24,0x1c);
  if (((local_30 & 8) == 0) || (iVar1 = (**(code **)(*param_1 + 0x90))(param_1), iVar1 == 0)) {
    iVar4 = 0;
  }
  *param_2 = (iVar4 << 1 ^ *param_2) & 2 ^ *param_2;
  param_2[1] = 0;
  param_2[2] = 0;
  uVar2 = (**(code **)(*param_1 + 200))(param_1);
  return uVar2;
}



/* c084302c FUN_c084302c */

/* Boundary evidence: original MIPS .pdata c084302c..c084305b. Semantic name remains unreviewed. */

void FUN_c084302c(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0xc))();
  }
  return;
}



/* c084305c FUN_c084305c */

/* Boundary evidence: original MIPS .pdata c084305c..c084309f. Semantic name remains unreviewed. */

void FUN_c084305c(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (param_2 != (undefined4 *)0x0)) {
    uVar1 = (**(code **)(*param_1 + 0x80))();
    *param_2 = uVar1;
  }
  return;
}



/* c08430a0 FUN_c08430a0 */

/* Boundary evidence: original MIPS .pdata c08430a0..c08430d3. Semantic name remains unreviewed. */

void FUN_c08430a0(int param_1,void *param_2)

{
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    memcpy(param_2,(void *)(param_1 + 0xac),0x40);
  }
  return;
}



/* c08430d4 FUN_c08430d4 */

/* Boundary evidence: original MIPS .pdata c08430d4..c0843103. Semantic name remains unreviewed. */

void FUN_c08430d4(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x50))();
  }
  return;
}



/* c0843104 FUN_c0843104 */

/* Boundary evidence: original MIPS .pdata c0843104..c084313b. Semantic name remains unreviewed. */

undefined4 FUN_c0843104(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    uVar1 = (**(code **)(*param_1 + 0xb0))();
  }
  return uVar1;
}



/* c084313c FUN_c084313c */

/* Boundary evidence: original MIPS .pdata c084313c..c084317f. Semantic name remains unreviewed. */

undefined4 FUN_c084313c(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0x18))();
  }
  return uVar1;
}



/* c0843180 FUN_c0843180 */

/* Boundary evidence: original MIPS .pdata c0843180..c08431cf. Semantic name remains unreviewed. */

undefined4 * FUN_c0843180(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = LocalAlloc(0x40,0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = param_1;
    puVar1[2] = &PTR_FUN_c0841114;
  }
  return puVar1;
}



/* c08431d0 FUN_c08431d0 */

/* Boundary evidence: original MIPS .pdata c08431d0..c084324f. Semantic name remains unreviewed. */

undefined4 * FUN_c08431d0(undefined4 *param_1,SIZE_T param_2,int param_3)

{
  HANDLE pvVar1;
  DWORD dwCreationFlags;
  
  param_1[5] = 0xffffffff;
  *param_1 = &PTR_LAB_c0841328;
  dwCreationFlags = 4;
  param_1[1] = 0;
  if (param_3 == 0) {
    dwCreationFlags = 0;
  }
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,param_2,FUN_c0841c80,param_1,dwCreationFlags,
                        param_1 + 3);
  param_1[2] = pvVar1;
  param_1[4] = param_3;
  return param_1;
}



/* c0843250 FUN_c0843250 */

/* Boundary evidence: original MIPS .pdata c0843250..c08432c7. Semantic name remains unreviewed. */

undefined4 * FUN_c0843250(undefined4 *param_1,undefined4 param_2)

{
  HANDLE pvVar1;
  
  FUN_c08431d0(param_1,0,1);
  *param_1 = &PTR_FUN_c084132c;
  param_1[6] = param_2;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[7] = pvVar1;
  FUN_c0841b30((int)param_1);
  return param_1;
}



/* c08432c8 FUN_c08432c8 */

/* Boundary evidence: original MIPS .pdata c08432c8..c0843353. Semantic name remains unreviewed. */

void FUN_c08432c8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c084132c;
  param_1[1] = 1;
  if (param_1[7] != 0) {
    EventModify(param_1[7],3);
  }
  param_1[1] = 1;
  FUN_c0841b8c((int)param_1,1000);
  if ((HANDLE)param_1[7] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[7]);
  }
  *param_1 = &PTR_LAB_c0841328;
  FUN_c0841c0c((int)param_1);
  return;
}



/* c0843354 FUN_c0843354 */

/* Boundary evidence: original MIPS .pdata c0843354..c084348f. Semantic name remains unreviewed. */

undefined4 FUN_c0843354(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined4 uVar4;
  DWORD local_18 [2];
  
  uVar4 = 1;
  (**(code **)(*param_1 + 0x1c))(param_1,1);
  if (param_1[0x15] == 0) {
    puVar1 = operator_new(0x20);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_c0843250(puVar1,param_1);
    }
    param_1[0x15] = (int)puVar1;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1[7] == 0)) {
      FUN_c08432c8(puVar1);
      operator_delete(puVar1);
      param_1[0x15] = 0;
    }
  }
  iVar2 = DDKPwr_Initialize(FUN_c0842174,param_1,1,1000);
  local_18[0] = 4;
  param_1[0x16] = iVar2;
  local_18[1] = 0;
  LVar3 = RegQueryValueExW((HKEY)param_1[1],L"RxBufferSize",(LPDWORD)0x0,local_18 + 1,
                           (LPBYTE)(param_1 + 0x3d),local_18);
  if (LVar3 != 0) {
    param_1[0x3d] = 0;
  }
  if (((param_1[1] == 0) || (param_1[0x15] == 0)) || (param_1[0x16] == -1)) {
    uVar4 = 0;
  }
  return uVar4;
}



/* c0843490 FUN_c0843490 */

/* Boundary evidence: original MIPS .pdata c0843490..c084356b. Semantic name remains unreviewed. */

void FUN_c0843490(undefined4 *param_1)

{
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1e);
  *param_1 = &PTR_FUN_c08411a4;
  EnterCriticalSection(lpCriticalSection);
  param_1[0x1d] = 0;
  LeaveCriticalSection(lpCriticalSection);
  if (param_1[0x16] != -1) {
    DDKPwr_Deinitialize();
  }
  if (param_1[4] != 0) {
    CloseBusAccessHandle();
  }
  puVar1 = (undefined4 *)param_1[0x15];
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c08432c8(puVar1);
    operator_delete(puVar1);
  }
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 0x19;
  DeleteCriticalSection(lpCriticalSection);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  if ((HKEY)param_1[1] != (HKEY)0x0) {
    RegCloseKey((HKEY)param_1[1]);
  }
  return;
}



/* c084356c FUN_c084356c */

/* Boundary evidence: original MIPS .pdata c084356c..c08435b7. Semantic name remains unreviewed. */

undefined4 * FUN_c084356c(undefined4 *param_1,uint param_2)

{
  FUN_c0843490(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c08435b8 DllEntry */

/* Boundary evidence: original MIPS .pdata c08435b8..c08435eb. Semantic name remains unreviewed. */

undefined4 DllEntry(HMODULE param_1,int param_2)

{
                    /* 0x35b8  15  DllEntry */
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c08435ec FUN_c08435ec */

/* Boundary evidence: original MIPS .pdata c08435ec..c084373b. Semantic name remains unreviewed. */

void FUN_c08435ec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_20 [2];
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x28) + 8);
  uVar2 = *(undefined4 *)(param_1 + 0x2c);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd0));
  if (*(int *)(param_1 + 0x90) == 0) {
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
  }
  if ((*(int *)(param_1 + 0xcc) == 0) || (*(int *)(param_1 + 200) == *(int *)(param_1 + 0xc4))) {
    local_20[0] = 0;
    (**(code **)(iVar1 + 0x1c))(uVar2,0,local_20);
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    EventModify(*(undefined4 *)(param_1 + 0x3c),3);
  }
  else {
    if ((*(uint *)(param_1 + 0x68) & 0x3000) == 0x3000) {
      (**(code **)(iVar1 + 0x40))(uVar2);
    }
    if ((*(uint *)(param_1 + 0x94) & 4) == 0) {
      local_20[0] = *(int *)(param_1 + 200) - *(int *)(param_1 + 0xc4);
    }
    else {
      local_20[0] = 0;
    }
    (**(code **)(iVar1 + 0x1c))(uVar2,*(int *)(param_1 + 0xcc) + *(int *)(param_1 + 0xc4),local_20);
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + local_20[0];
    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + local_20[0];
    *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + local_20[0];
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd0));
  return;
}



/* c084373c FUN_c084373c */

/* Boundary evidence: original MIPS .pdata c084373c..c08437ff. Semantic name remains unreviewed. */

undefined4 FUN_c084373c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x40) != 0) {
    uVar1 = CeGetThreadPriority(0x41);
    CeSetThreadPriority(*(undefined4 *)(param_1 + 0x40),uVar1);
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 1;
    EventModify(*(undefined4 *)(param_1 + 0x30),3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x38),3000);
    Sleep(10);
    CloseHandle(*(HANDLE *)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    InterruptDone(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
    InterruptDisable(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
  }
  return 1;
}



/* c0843800 FUN_c0843800 */

/* Boundary evidence: original MIPS .pdata c0843800..c0843b3b. Semantic name remains unreviewed. */

undefined4 FUN_c0843800(int param_1,void *param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x28);
  if ((((*(uint *)(param_1 + 0xa4) <= (uint)*(ushort *)((int)param_2 + 0x10)) ||
       (*(uint *)(param_1 + 0xa4) - (uint)*(ushort *)((int)param_2 + 0x10) <=
        (uint)*(ushort *)((int)param_2 + 0xe))) ||
      ((((*(uint *)((int)param_2 + 8) & 0x100) != 0 || ((*(uint *)((int)param_2 + 8) & 0x200) != 0))
       && (*(char *)((int)param_2 + 0x15) == *(char *)((int)param_2 + 0x16))))) ||
     (iVar1 = (**(code **)(*(int *)(iVar5 + 8) + 0x6c))(*(undefined4 *)(param_1 + 0x2c),param_2),
     iVar1 == 0)) {
    return 0;
  }
  if (param_3 == 0) {
    return 1;
  }
  memcpy((void *)(param_1 + 0x60),param_2,0x1c);
  uVar3 = *(uint *)(param_1 + 0x68) >> 4 & 3;
  if (uVar3 == 0) {
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x34);
LAB_c08438e8:
    (*pcVar2)(*(undefined4 *)(param_1 + 0x2c));
  }
  else if (uVar3 == 1) {
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x38);
    goto LAB_c08438e8;
  }
  uVar3 = *(uint *)(param_1 + 0x68) >> 0xc & 3;
  if (uVar3 == 0) {
    (**(code **)(*(int *)(iVar5 + 8) + 0x3c))(*(undefined4 *)(param_1 + 0x2c));
  }
  else if (uVar3 == 1) {
    (**(code **)(*(int *)(iVar5 + 8) + 0x40))(*(undefined4 *)(param_1 + 0x2c));
  }
  if ((*(uint *)(param_1 + 0x68) & 0x30) == 0x20) {
    uVar3 = *(uint *)(param_1 + 0x94);
    if ((uVar3 & 0x10) == 0) {
      uVar4 = *(uint *)(param_1 + 0x9c);
      if (*(uint *)(param_1 + 0xa0) < uVar4) {
        iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
      }
      else {
        iVar1 = -uVar4;
      }
      if ((uint)*(ushort *)(param_1 + 0x70) <
          *(int *)(param_1 + 0xa4) - (*(uint *)(param_1 + 0xa0) + iVar1)) goto LAB_c08439ac;
      *(uint *)(param_1 + 0x94) = uVar3 | 0x10;
      pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x34);
    }
    else {
LAB_c08439ac:
      uVar4 = *(uint *)(param_1 + 0x9c);
      if (*(uint *)(param_1 + 0xa0) < uVar4) {
        iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
      }
      else {
        iVar1 = -uVar4;
      }
      if ((uint)*(ushort *)(param_1 + 0x6e) < *(uint *)(param_1 + 0xa0) + iVar1) goto LAB_c0843a04;
      *(uint *)(param_1 + 0x94) = uVar3 & 0xffffffef;
      pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x38);
    }
    (*pcVar2)(*(undefined4 *)(param_1 + 0x2c));
  }
LAB_c0843a04:
  if ((*(uint *)(param_1 + 0x68) & 0x3000) != 0x2000) goto LAB_c0843ad4;
  uVar3 = *(uint *)(param_1 + 0x94);
  if ((uVar3 & 0x20) == 0) {
    uVar4 = *(uint *)(param_1 + 0x9c);
    if (*(uint *)(param_1 + 0xa0) < uVar4) {
      iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
    }
    else {
      iVar1 = -uVar4;
    }
    if ((uint)*(ushort *)(param_1 + 0x70) <
        *(int *)(param_1 + 0xa4) - (*(uint *)(param_1 + 0xa0) + iVar1)) goto LAB_c0843a7c;
    *(uint *)(param_1 + 0x94) = uVar3 | 0x20;
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x3c);
  }
  else {
LAB_c0843a7c:
    uVar4 = *(uint *)(param_1 + 0x9c);
    if (*(uint *)(param_1 + 0xa0) < uVar4) {
      iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
    }
    else {
      iVar1 = -uVar4;
    }
    if ((uint)*(ushort *)(param_1 + 0x6e) < *(uint *)(param_1 + 0xa0) + iVar1) goto LAB_c0843ad4;
    *(uint *)(param_1 + 0x94) = uVar3 & 0xffffffdf;
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x40);
  }
  (*pcVar2)(*(undefined4 *)(param_1 + 0x2c));
LAB_c0843ad4:
  if (((*(uint *)(param_1 + 0x68) & 0x100) == 0) && ((*(uint *)(param_1 + 0x68) & 0x200) == 0)) {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfffffffd;
  }
  else {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 2;
  }
  return 1;
}



/* c0843b3c COM_PreClose */

/* Boundary evidence: original MIPS .pdata c0843b3c..c0843c47. Semantic name remains unreviewed. */

undefined4 COM_PreClose(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x3b3c  10  COM_PreClose */
  iVar1 = *param_1;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xec));
    uVar2 = 1;
    if ((param_1[1] & 0x100U) == 0) {
      if (*(int *)(iVar1 + 0x90) == 0) {
        SetLastError(6);
      }
      else {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        param_1[5] = 0;
        param_1[7] = 1;
        EventModify(param_1[4],3);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        if ((param_1[1] & 0xc0000000U) != 0) {
          *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) | 0x40;
          EventModify(*(undefined4 *)(iVar1 + 0x34),3);
          *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) | 0x80;
          EventModify(*(undefined4 *)(iVar1 + 0x3c),3);
        }
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xec));
  }
  return uVar2;
}



/* c0843c48 COM_Close */

/* Boundary evidence: original MIPS .pdata c0843c48..c0843def. Semantic name remains unreviewed. */

undefined4 COM_Close(int *param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  
                    /* 0x3c48  3  COM_Close */
  iVar2 = *param_1;
  uVar4 = 1;
  if (iVar2 == 0) {
    SetLastError(6);
    return 0;
  }
  puVar3 = *(uint **)(iVar2 + 0x28);
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xec));
  if ((param_1[1] & 0x100U) == 0) {
    if (*(int *)(iVar2 + 0x90) == 0) {
      SetLastError(6);
      uVar4 = 0;
      goto LAB_c0843dc4;
    }
    iVar1 = *(int *)(iVar2 + 0x90) + -1;
    *(int *)(iVar2 + 0x90) = iVar1;
    if ((((puVar3 != (uint *)0x0) && (iVar1 == 0)) && ((*puVar3 & 3) != 0)) &&
       (*(HANDLE *)(iVar2 + 0x40) != (HANDLE)0x0)) {
      SetThreadPriority(*(HANDLE *)(iVar2 + 0x40),3);
    }
    if (*(int *)(iVar2 + 0x90) == 0) {
      if (puVar3 != (uint *)0x0) {
        (**(code **)(puVar3[2] + 0x10))(*(undefined4 *)(iVar2 + 0x2c));
      }
      if ((**(uint **)(iVar2 + 0x28) & 2) != 0) {
        FUN_c084373c(iVar2);
      }
    }
    if (param_1 == *(int **)(iVar2 + 0x100)) {
      *(undefined4 *)(iVar2 + 0x100) = 0;
    }
    *(int *)param_1[0xe] = param_1[0xd];
    *(int *)(param_1[0xd] + 4) = param_1[0xe];
  }
  else {
    *(int *)param_1[0xe] = param_1[0xd];
    *(int *)(param_1[0xd] + 4) = param_1[0xe];
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if ((HANDLE)param_1[4] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[4]);
  }
  LocalFree(param_1);
LAB_c0843dc4:
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xec));
  return uVar4;
}



/* c0843df0 FUN_c0843df0 */

/* Boundary evidence: original MIPS .pdata c0843df0..c0843e33. Semantic name remains unreviewed. */

bool FUN_c0843df0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    COM_PreClose(param_1);
  }
  else {
    SetLastError(6);
  }
  return iVar1 != 0;
}



/* c0843e34 COM_PreDeinit */

/* Boundary evidence: original MIPS .pdata c0843e34..c0843f03. Semantic name remains unreviewed. */

undefined4 COM_PreDeinit(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
                    /* 0x3e34  11  COM_PreDeinit */
  if (param_1 == 0) {
    SetLastError(6);
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x90) != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xec));
      piVar4 = *(int **)(param_1 + 0xe4);
      while (piVar4 != (int *)(param_1 + 0xe4)) {
        piVar2 = piVar4 + -0xd;
        piVar4 = (int *)*piVar4;
        COM_PreClose(piVar2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xec));
    }
    if (((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0x28) != 0)) &&
       (iVar3 = *(int *)(*(int *)(param_1 + 0x28) + 8), iVar3 != 0)) {
      (**(code **)(iVar3 + 0x5c))();
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* c0843f04 COM_Deinit */

/* Boundary evidence: original MIPS .pdata c0843f04..c084409b. Semantic name remains unreviewed. */

undefined4 COM_Deinit(LPCRITICAL_SECTION param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  ULONG_PTR *lpCriticalSection;
  
                    /* 0x3f04  4  COM_Deinit */
  if (param_1 == (LPCRITICAL_SECTION)0x0) {
    SetLastError(6);
    uVar1 = 0;
  }
  else {
    if ((param_1[1].LockSemaphore != (uint *)0x0) && ((*(uint *)param_1[1].LockSemaphore & 3) != 0))
    {
      FUN_c084373c((int)param_1);
    }
    lpCriticalSection = &param_1[9].SpinCount;
    EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
    if (param_1[6].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
      piVar4 = param_1[9].OwningThread;
      while ((HANDLE *)piVar4 != &param_1[9].OwningThread) {
        piVar2 = piVar4 + -0xd;
        piVar4 = (int *)*piVar4;
        COM_Close(piVar2);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
    if (param_1[2].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
      CloseHandle(param_1[2].DebugInfo);
    }
    if ((HANDLE)param_1[2].RecursionCount != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[2].RecursionCount);
    }
    if (param_1[2].OwningThread != (HANDLE)0x0) {
      CloseHandle(param_1[2].OwningThread);
    }
    if ((HANDLE)param_1[2].LockCount != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[2].LockCount);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&param_1->SpinCount);
    DeleteCriticalSection(param_1);
    DeleteCriticalSection((LPCRITICAL_SECTION)&param_1[7].RecursionCount);
    DeleteCriticalSection((LPCRITICAL_SECTION)&param_1[8].LockSemaphore);
    DeleteCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
    if ((HLOCAL)param_1[7].LockCount != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[7].LockCount);
    }
    if (((param_1[1].SpinCount != 0) && (param_1[1].LockSemaphore != (HANDLE)0x0)) &&
       (iVar3 = *(int *)((int)param_1[1].LockSemaphore + 8), iVar3 != 0)) {
      (**(code **)(iVar3 + 8))();
    }
    LocalFree(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



/* c084409c COM_Read */

/* Boundary evidence: original MIPS .pdata c084409c..c0844533. Semantic name remains unreviewed. */

int COM_Read(int *param_1,int param_2,uint param_3)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
                    /* 0x409c  12  COM_Read */
  iVar11 = 0;
  uVar14 = 0;
  if (((param_1 == (int *)0x0) || (iVar9 = *param_1, iVar9 == 0)) || (*(int *)(iVar9 + 0x90) == 0))
  {
    DVar1 = 6;
  }
  else {
    iVar3 = *(int *)(*(int *)(iVar9 + 0x28) + 8);
    uVar4 = *(undefined4 *)(iVar9 + 0x2c);
    if ((param_1[1] & 0x80000000U) == 0) {
      SetLastError(0xc);
      return -1;
    }
    if ((param_2 != 0) && (param_3 != 0)) {
      InterlockedIncrement(param_1 + 3);
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0x14));
      iVar5 = *(int *)(iVar9 + 0x80);
      *(uint *)(iVar9 + 0x94) = *(uint *)(iVar9 + 0x94) & 0xffffffbf;
      if (iVar5 == -1) {
        uVar13 = *(uint *)(iVar9 + 0x84);
        iVar6 = 0;
      }
      else {
        iVar6 = iVar5 << 3;
        uVar13 = iVar5 * param_3 + *(int *)(iVar9 + 0x84);
      }
      uVar12 = *(uint *)(iVar9 + 0x7c);
      if ((uVar12 < -iVar6 - 1U) && (uVar12 != 0)) {
        uVar12 = uVar12 + iVar6;
      }
      do {
        uVar8 = 0xffffffff;
        uVar7 = *(uint *)(iVar9 + 0x9c);
        if (*(uint *)(iVar9 + 0xa0) < uVar7) {
          iVar5 = *(int *)(iVar9 + 0xa4) - uVar7;
        }
        else {
          iVar5 = -uVar7;
        }
        if (*(uint *)(iVar9 + 0xa0) + iVar5 == 0) {
          if ((uVar12 == 0xffffffff) && ((uVar13 == 0 || (iVar11 != 0)))) goto LAB_c08444c4;
          uVar7 = uVar13;
          if (uVar13 == 0) {
            uVar7 = uVar8;
          }
          if (uVar7 <= uVar14) goto LAB_c08444c4;
          uVar7 = uVar7 - uVar14;
          if (iVar11 != 0) {
            uVar10 = uVar12;
            if (uVar12 == 0) {
              uVar10 = uVar8;
            }
            if ((uVar10 <= uVar7) && (uVar7 = uVar12, uVar12 == 0)) {
              uVar7 = uVar8;
            }
          }
          DVar1 = GetTickCount();
          DVar2 = WaitForSingleObject(*(HANDLE *)(iVar9 + 0x34),uVar7);
          if (DVar2 == 0x102) goto LAB_c08444c4;
          DVar2 = GetTickCount();
          uVar14 = DVar2 + (uVar14 - DVar1);
          if ((*(uint *)(iVar9 + 0x94) & 0x40) != 0) goto LAB_c08444c4;
          if (*(int *)(iVar9 + 0x90) == 0) {
            SetLastError(6);
            goto LAB_c08444c4;
          }
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0xb0));
          uVar7 = *(uint *)(iVar9 + 0xa0);
          uVar8 = *(uint *)(iVar9 + 0x9c);
          if (uVar7 < uVar8) {
            iVar5 = *(int *)(iVar9 + 0xa4) - uVar8;
          }
          else {
            iVar5 = -uVar8;
          }
          uVar10 = *(int *)(iVar9 + 0xa4) - uVar8;
          if (uVar7 + iVar5 < uVar10) {
            if (uVar7 < uVar8) {
              uVar10 = (*(int *)(iVar9 + 0xa4) - uVar8) + uVar7;
            }
            else {
              uVar10 = uVar7 - uVar8;
            }
          }
          if (param_3 <= uVar10) {
            uVar10 = param_3;
          }
          CeSafeCopyMemory(param_2,*(int *)(iVar9 + 0xac) + uVar8,uVar10);
          uVar7 = *(int *)(iVar9 + 0x9c) + uVar10;
          if (*(uint *)(iVar9 + 0xa4) <= uVar7) {
            uVar7 = (*(int *)(iVar9 + 0x9c) - *(uint *)(iVar9 + 0xa4)) + uVar10;
          }
          *(uint *)(iVar9 + 0x9c) = uVar7;
          param_3 = param_3 - uVar10;
          param_2 = uVar10 + param_2;
          iVar11 = uVar10 + iVar11;
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0xb0));
        }
        uVar7 = *(uint *)(iVar9 + 0x9c);
        if (*(uint *)(iVar9 + 0xa0) < uVar7) {
          iVar5 = *(int *)(iVar9 + 0xa4) - uVar7;
        }
        else {
          iVar5 = -uVar7;
        }
        if (*(uint *)(iVar9 + 0xa0) + iVar5 <= (uint)*(ushort *)(iVar9 + 0x6e)) {
          if (((*(uint *)(iVar9 + 0x68) & 0x200) != 0) &&
             (uVar7 = *(uint *)(iVar9 + 0x94), (uVar7 & 8) != 0)) {
            *(uint *)(iVar9 + 0x94) = uVar7 & 0xfffffff7;
            if ((*(uint *)(iVar9 + 0x68) & 0x80) == 0) {
              *(uint *)(iVar9 + 0x94) = uVar7 & 0xfffffff3;
            }
            (**(code **)(*(int *)(*(int *)(iVar9 + 0x28) + 8) + 0x54))
                      (*(undefined4 *)(iVar9 + 0x2c),*(undefined1 *)(iVar9 + 0x75));
          }
          if (((*(uint *)(iVar9 + 0x94) & 0x20) != 0) &&
             ((*(uint *)(iVar9 + 0x68) & 0x3000) == 0x2000)) {
            *(uint *)(iVar9 + 0x94) = *(uint *)(iVar9 + 0x94) & 0xffffffdf;
            (**(code **)(iVar3 + 0x40))(uVar4);
          }
          if (((*(uint *)(iVar9 + 0x94) & 0x10) != 0) && ((*(uint *)(iVar9 + 0x68) & 0x30) == 0x20))
          {
            *(uint *)(iVar9 + 0x94) = *(uint *)(iVar9 + 0x94) & 0xffffffef;
            (**(code **)(iVar3 + 0x38))(uVar4);
          }
        }
        if (param_3 == 0) {
LAB_c08444c4:
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0x14));
          InterlockedDecrement(param_1 + 3);
          return iVar11;
        }
      } while( true );
    }
    DVar1 = 0x57;
  }
  SetLastError(DVar1);
  return -1;
}



/* c0844534 COM_Seek */

undefined4 COM_Seek(void)

{
                    /* 0x4534  13  COM_Seek */
  return 0xffffffff;
}



/* c084453c COM_PowerUp */

/* Boundary evidence: original MIPS .pdata c084453c..c084457f. Semantic name remains unreviewed. */

undefined4 COM_PowerUp(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x453c  9  COM_PowerUp */
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x28) + 8) + 0x30))
                      (*(undefined4 *)(param_1 + 0x2c));
  }
  return uVar1;
}



/* c0844580 COM_PowerDown */

/* Boundary evidence: original MIPS .pdata c0844580..c08445c3. Semantic name remains unreviewed. */

undefined4 COM_PowerDown(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x4580  8  COM_PowerDown */
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x28) + 8) + 0x2c))
                      (*(undefined4 *)(param_1 + 0x2c));
  }
  return uVar1;
}



/* c08445c4 FUN_c08445c4 */

/* Boundary evidence: original MIPS .pdata c08445c4..c0844797. Semantic name remains unreviewed. */

undefined4 FUN_c08445c4(int *param_1,uint *param_2)

{
  uint uVar1;
  DWORD dwErrCode;
  int iVar2;
  
  iVar2 = *param_1;
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x90) != 0)) {
    if (param_1[5] == 0) {
      dwErrCode = 0x57;
      goto LAB_c0844758;
    }
    InterlockedIncrement(param_1 + 3);
    param_1[7] = 0;
    if (*(int *)(iVar2 + 0x90) != 0) {
      do {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        EventModify(param_1[4],2);
        uVar1 = InterlockedExchange(param_1 + 6,0);
        if (((param_1[5] & uVar1) != 0) || (param_1[5] == 0)) {
          *param_2 = param_1[5] & uVar1;
          LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        WaitForSingleObject((HANDLE)param_1[4],0xffffffff);
        if (param_1[7] != 0) {
          *param_2 = 0;
          break;
        }
      } while (*(int *)(iVar2 + 0x90) != 0);
    }
    InterlockedDecrement(param_1 + 3);
    if (*(int *)(iVar2 + 0x90) != 0) {
      return 1;
    }
  }
  dwErrCode = 6;
LAB_c0844758:
  *param_2 = 0;
  SetLastError(dwErrCode);
  return 0;
}



/* c0844798 FUN_c0844798 */

/* Boundary evidence: original MIPS .pdata c0844798..c08447a3. Semantic name remains unreviewed. */

undefined4 FUN_c0844798(void)

{
  return 1;
}



/* c08447a4 FUN_c08447a4 */

/* Boundary evidence: original MIPS .pdata c08447a4..c0844893. Semantic name remains unreviewed. */

void FUN_c08447a4(int param_1,uint param_2)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  if (*(int *)(param_1 + 0x90) == 0) {
    SetLastError(6);
  }
  else if ((*(uint *)(param_1 + 0x98) & param_2) != 0) {
    piVar2 = (int *)*(int *)(param_1 + 0xe4);
    while (piVar2 != (int *)(param_1 + 0xe4)) {
      piVar5 = (int *)*piVar2;
      EnterCriticalSection((LPCRITICAL_SECTION)(piVar2 + -5));
      if ((piVar2[-8] & param_2) != 0) {
        uVar3 = piVar2[-7];
        do {
          uVar4 = InterlockedExchange(piVar2 + -7,uVar3 | param_2);
          bVar1 = uVar3 != uVar4;
          uVar3 = uVar4;
        } while (bVar1);
        EventModify(piVar2[-9],3);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + -5));
      piVar2 = piVar5;
    }
  }
  return;
}



/* c0844894 COM_IOControl */

/* Boundary evidence: original MIPS .pdata c0844894..c08452ff. Semantic name remains unreviewed. */

bool COM_IOControl(int *param_1,int param_2,uint *param_3,uint param_4,uint *param_5,uint param_6,
                  undefined4 *param_7)

{
  DWORD DVar1;
  undefined1 *_Src;
  size_t _Size;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  uint uVar11;
  int iVar12;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar13;
  uint local_a0;
  int *local_9c;
  LONG *local_98;
  uint local_90;
  uint local_8c [7];
  undefined1 auStack_70 [64];
  uint local_30;
  
                    /* 0x4894  5  COM_IOControl */
  local_30 = DAT_c08470f4;
  bVar9 = true;
  bVar10 = true;
  local_a0 = param_4;
  local_9c = param_1;
  if ((param_1 == (int *)0x0) || (iVar7 = *param_1, iVar7 == 0)) {
    SetLastError(6);
    goto LAB_c08452c4;
  }
  iVar12 = *(int *)(*(int *)(iVar7 + 0x28) + 8);
  uVar13 = *(undefined4 *)(iVar7 + 0x2c);
  if ((param_1[1] & 0x100U) != 0) {
    if ((((param_2 == 0x321000) || (param_2 == 0x321004)) || (param_2 == 0x321008)) ||
       ((param_2 == 0x32100c || (param_2 == 0x321018)))) {
      if ((*(code **)(iVar12 + 0x74) != (code *)0x0) &&
         (iVar7 = (**(code **)(iVar12 + 0x74))
                            (uVar13,param_2,param_3,param_4,param_5,param_6,param_7), iVar7 != 0))
      goto LAB_c08449bc;
      SetLastError(0x57);
    }
    else {
      SetLastError(6);
    }
    bVar10 = false;
    goto LAB_c08449bc;
  }
  if (*(int *)(iVar7 + 0x90) == 0) {
    DVar1 = 6;
LAB_c08449e4:
    SetLastError(DVar1);
LAB_c08452c4:
    FUN_c0846590(local_30);
    return false;
  }
  if (param_2 == 0x10303ff) {
    if ((*param_3 == 0x10) && (param_3[1] == 4)) {
      FUN_c0843df0(param_1);
    }
    goto LAB_c08449bc;
  }
  if ((((param_2 != 0x1b0024) && (param_2 != 0x1b0028)) && (param_2 != 0x1b002c)) &&
     (((((param_2 != 0x1b0034 && (param_2 != 0x1b0038)) &&
        ((param_2 != 0x1b0040 && ((param_2 != 0x321000 && (param_2 != 0x32100c)))))) &&
       (param_2 != 0x321008)) && ((param_1[1] & 0xc0000000U) == 0)))) {
    DVar1 = 0xc;
    goto LAB_c08449e4;
  }
  local_98 = param_1 + 3;
  InterlockedIncrement(local_98);
  piVar4 = local_9c;
  bVar10 = bVar9;
  switch(param_2) {
  case 0x1b0004:
    (**(code **)(iVar12 + 0x50))(uVar13);
    break;
  default:
    if (*(code **)(iVar12 + 0x74) != (code *)0x0) {
      iVar7 = (**(code **)(iVar12 + 0x74))(uVar13,param_2,param_3,local_a0,param_5,param_6,param_7);
LAB_c0845284:
      if (iVar7 != 0) break;
    }
    goto LAB_c0845294;
  case 0x1b0008:
    pcVar3 = *(code **)(iVar12 + 0x4c);
    goto LAB_c0844bf8;
  case 0x1b000c:
    if ((*(uint *)(iVar7 + 0x68) & 0x30) == 0x20) goto LAB_c0845294;
    pcVar3 = *(code **)(iVar12 + 0x38);
LAB_c0844c20:
    (*pcVar3)(uVar13);
    break;
  case 0x1b0010:
    if ((*(uint *)(iVar7 + 0x68) & 0x30) != 0x20) {
      pcVar3 = *(code **)(iVar12 + 0x34);
      goto LAB_c0844c20;
    }
    goto LAB_c0845294;
  case 0x1b0014:
    if ((*(uint *)(iVar7 + 0x68) & 0x3000) != 0x2000) {
      pcVar3 = *(code **)(iVar12 + 0x40);
      goto LAB_c0844c20;
    }
    goto LAB_c0845294;
  case 0x1b0018:
    if ((*(uint *)(iVar7 + 0x68) & 0x3000) != 0x2000) {
      pcVar3 = *(code **)(iVar12 + 0x3c);
      goto LAB_c0844c20;
    }
    goto LAB_c0845294;
  case 0x1b001c:
    if ((*(uint *)(iVar7 + 0x94) & 2) != 0) {
      uVar11 = *(uint *)(iVar7 + 0x94) | 0xc;
LAB_c0844c98:
      *(uint *)(iVar7 + 0x94) = uVar11;
    }
    break;
  case 0x1b0020:
    if ((*(uint *)(iVar7 + 0x94) & 2) != 0) {
      uVar11 = *(uint *)(iVar7 + 0x94) & 0xfffffff3;
      goto LAB_c0844c98;
    }
    break;
  case 0x1b0024:
    if (((param_6 < 4) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0845294;
    *param_5 = local_9c[5];
    *param_7 = 4;
    break;
  case 0x1b0028:
    if ((local_a0 < 4) || (param_3 == (uint *)0x0)) goto LAB_c0845294;
    uVar11 = *param_3;
    lpCriticalSection = (LPCRITICAL_SECTION)(local_9c + 8);
    EnterCriticalSection(lpCriticalSection);
    piVar4[5] = uVar11;
    piVar4[7] = 1;
    EventModify(piVar4[4],3);
    uVar11 = 0;
    for (piVar4 = *(int **)(iVar7 + 0xe4); piVar4 != (int *)(iVar7 + 0xe4); piVar4 = (int *)*piVar4)
    {
      uVar11 = piVar4[-8] | uVar11;
    }
    *(uint *)(iVar7 + 0x98) = uVar11;
    LeaveCriticalSection(lpCriticalSection);
    break;
  case 0x1b002c:
    if (((param_6 < 4) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0845294;
    local_a0 = 0;
    iVar7 = FUN_c08445c4(local_9c,&local_a0);
    *param_5 = local_a0;
    *param_7 = 4;
    bVar10 = iVar7 != 0;
    break;
  case 0x1b0030:
    if (((param_6 < 0x10) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0845294;
    memset(local_8c,0,0xc);
    local_90 = InterlockedExchange((LONG *)(iVar7 + 0x104),0);
    uVar11 = (**(code **)(iVar12 + 0x58))(uVar13,local_8c);
    uVar6 = *(uint *)(iVar7 + 0xa0);
    uVar5 = *(uint *)(iVar7 + 0x9c);
    if (uVar6 < uVar5) {
      iVar12 = *(int *)(iVar7 + 0xa4) - uVar5;
    }
    else {
      iVar12 = -uVar5;
    }
    iVar2 = *(int *)(iVar7 + 0x94);
    uVar5 = *(uint *)(iVar7 + 0x58);
    *param_5 = uVar11 | local_90;
    param_5[1] = (iVar2 << 1 ^ local_8c[0]) & 0x18 ^ local_8c[0];
    param_5[2] = uVar6 + iVar12;
    param_5[3] = uVar5;
    *param_7 = 0x10;
    break;
  case 0x1b0034:
    local_9c = (int *)0x0;
    if (((param_6 < 4) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0845294;
    (**(code **)(iVar12 + 0x60))(uVar13,&local_9c);
    *param_7 = 4;
    *param_5 = (uint)local_9c;
    break;
  case 0x1b0038:
    if (((param_6 < 0x40) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0845294;
    uVar8 = 0x40;
    memset(auStack_70,0,0x40);
    (**(code **)(iVar12 + 100))(uVar13,auStack_70);
    _Src = auStack_70;
    _Size = 0x40;
LAB_c0844f24:
    memcpy(param_5,_Src,_Size);
    *param_7 = uVar8;
    break;
  case 0x1b003c:
    if ((local_a0 < 0x14) || (param_3 == (uint *)0x0)) goto LAB_c0845294;
    *(uint *)(iVar7 + 0x7c) = *param_3;
    *(uint *)(iVar7 + 0x80) = param_3[1];
    *(uint *)(iVar7 + 0x84) = param_3[2];
    *(uint *)(iVar7 + 0x88) = param_3[3];
    *(uint *)(iVar7 + 0x8c) = param_3[4];
    (**(code **)(iVar12 + 0x70))(uVar13);
    break;
  case 0x1b0040:
    if (((param_6 < 0x14) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0845294;
    memset(param_5,0,0x14);
    *param_5 = *(uint *)(iVar7 + 0x7c);
    param_5[1] = *(uint *)(iVar7 + 0x80);
    param_5[2] = *(uint *)(iVar7 + 0x84);
    param_5[3] = *(uint *)(iVar7 + 0x88);
    param_5[4] = *(uint *)(iVar7 + 0x8c);
    *param_7 = 0x14;
    break;
  case 0x1b0044:
    if ((local_a0 < 4) || (param_3 == (uint *)0x0)) goto LAB_c0845294;
    uVar11 = *param_3;
    (**(code **)(iVar12 + 0x68))(uVar13,uVar11);
    if ((uVar11 & 8) != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar7 + 0xb0));
      *(undefined4 *)(iVar7 + 0x9c) = *(undefined4 *)(iVar7 + 0xa0);
      memset(*(void **)(iVar7 + 0xac),0,*(size_t *)(iVar7 + 0xa4));
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar7 + 0xb0));
      if (((*(uint *)(iVar7 + 0x68) & 0x200) != 0) &&
         (uVar5 = *(uint *)(iVar7 + 0x94), (uVar5 & 8) != 0)) {
        *(uint *)(iVar7 + 0x94) = uVar5 & 0xfffffff7;
        if ((*(uint *)(iVar7 + 0x68) & 0x80) == 0) {
          *(uint *)(iVar7 + 0x94) = uVar5 & 0xfffffff3;
        }
        (**(code **)(iVar12 + 0x54))(*(undefined4 *)(iVar7 + 0x2c),*(undefined1 *)(iVar7 + 0x75));
      }
      if (((*(uint *)(iVar7 + 0x94) & 0x20) != 0) && ((*(uint *)(iVar7 + 0x68) & 0x3000) == 0x2000))
      {
        *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) & 0xffffffdf;
        (**(code **)(iVar12 + 0x40))(*(undefined4 *)(iVar7 + 0x2c));
      }
      if (((*(uint *)(iVar7 + 0x94) & 0x10) != 0) && ((*(uint *)(iVar7 + 0x68) & 0x30) == 0x20)) {
        *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) & 0xffffffef;
        (**(code **)(iVar12 + 0x38))(uVar13);
      }
    }
    if ((uVar11 & 2) != 0) {
      *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) | 0x40;
      EventModify(*(undefined4 *)(iVar7 + 0x34),1);
    }
    if ((uVar11 & 1) != 0) {
      *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) | 0x80;
      EventModify(*(undefined4 *)(iVar7 + 0x3c),3);
    }
    break;
  case 0x1b0048:
    DVar1 = 0x32;
    goto LAB_c0845298;
  case 0x1b004c:
    if ((local_a0 == 0) || (param_3 == (uint *)0x0)) goto LAB_c0845294;
    (**(code **)(iVar12 + 0x54))(uVar13,(char)*param_3);
    break;
  case 0x1b0050:
    if (((0x1b < param_6) && (param_5 != (uint *)0x0)) && (param_7 != (undefined4 *)0x0)) {
      _Src = (undefined1 *)(iVar7 + 0x60);
      uVar8 = 0x1c;
      _Size = 0x1c;
      goto LAB_c0844f24;
    }
    goto LAB_c0845294;
  case 0x1b0054:
    if ((0x1b < local_a0) && (param_3 != (uint *)0x0)) {
      memcpy(&local_90,param_3,0x1c);
      iVar7 = FUN_c0843800(iVar7,&local_90,1);
      goto LAB_c0845284;
    }
LAB_c0845294:
    DVar1 = 0x57;
LAB_c0845298:
    SetLastError(DVar1);
LAB_c08452a0:
    bVar10 = false;
    break;
  case 0x1b0058:
    iVar7 = (**(code **)(iVar12 + 0x44))(uVar13,*(undefined4 *)(iVar7 + 100));
    if (iVar7 != 0) break;
    goto LAB_c08452a0;
  case 0x1b005c:
    pcVar3 = *(code **)(iVar12 + 0x48);
LAB_c0844bf8:
    (*pcVar3)(uVar13);
  }
  InterlockedDecrement(local_98);
LAB_c08449bc:
  FUN_c0846590(local_30);
  return bVar10;
}



/* c0845300 FUN_c0845300 */

/* Boundary evidence: original MIPS .pdata c0845300..c08456f3. Semantic name remains unreviewed. */

void FUN_c0845300(int param_1)

{
  bool bVar1;
  uint uVar2;
  byte *_Dst;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint local_40 [2];
  undefined1 auStack_38 [16];
  uint local_28;
  
  local_28 = DAT_c08470f4;
  iVar7 = *(int *)(*(int *)(param_1 + 0x28) + 8);
  uVar8 = *(undefined4 *)(param_1 + 0x2c);
  bVar1 = false;
  local_40[0] = 0;
  if (((*(uint *)(param_1 + 0x94) & 1) != 0) || (*(int *)(param_1 + 0x30) == 0)) {
    EventModify(*(undefined4 *)(param_1 + 0x38),3);
                    /* WARNING: Subroutine does not return */
    ExitThread(0);
  }
  if (*(int *)(param_1 + 0x100) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(param_1 + 0x100) + 0xc));
  }
  uVar2 = (**(code **)(iVar7 + 0x14))(uVar8);
  if (uVar2 != 0) {
    do {
      if ((uVar2 & 2) != 0) {
        uVar4 = *(uint *)(param_1 + 0xa0);
        uVar5 = *(uint *)(param_1 + 0x9c);
        if (uVar5 == 0) {
          iVar3 = *(int *)(param_1 + 0xa4) - uVar4;
LAB_c08453e0:
          local_40[0] = iVar3 - 1;
        }
        else {
          local_40[0] = *(int *)(param_1 + 0xa4) - uVar4;
          if (uVar4 < uVar5) {
            iVar3 = uVar5 - uVar4;
            goto LAB_c08453e0;
          }
        }
        if (local_40[0] == 0) {
          local_40[0] = 0x10;
          (**(code **)(iVar7 + 0x18))(uVar8,auStack_38,local_40);
          uVar4 = local_40[0];
          local_40[0] = 0;
          *(uint *)(param_1 + 0x48) = uVar4 + *(int *)(param_1 + 0x48);
          do {
            uVar5 = *(uint *)(param_1 + 0x104);
            uVar4 = InterlockedCompareExchange((LONG *)(param_1 + 0x104),uVar5 | 1,uVar5);
          } while (uVar5 != uVar4);
        }
        else {
          iVar3 = (**(code **)(iVar7 + 0x18))(uVar8,*(int *)(param_1 + 0xac) + uVar4);
          *(int *)(param_1 + 0x4c) = iVar3 + *(int *)(param_1 + 0x4c);
        }
        uVar4 = local_40[0];
        if (((*(uint *)(param_1 + 0x94) & 2) != 0) && (uVar5 = 0, local_40[0] != 0)) {
          do {
            _Dst = (byte *)(*(int *)(param_1 + 0xac) + uVar5 + *(int *)(param_1 + 0xa0));
            if ((uint)*_Dst == (int)*(char *)(param_1 + 0x76)) {
              *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 4;
              memmove(_Dst,_Dst + 1,uVar4 - uVar5);
              uVar4 = local_40[0] - 1;
              local_40[0] = uVar4;
            }
            else if ((uint)*_Dst == (int)*(char *)(param_1 + 0x75)) {
              *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfffffffb;
              memmove(_Dst,_Dst + 1,uVar4 - uVar5);
              uVar2 = uVar2 | 4;
              uVar4 = local_40[0] - 1;
              local_40[0] = uVar4;
            }
            else {
              uVar5 = uVar5 + 1;
            }
          } while (uVar5 < uVar4);
        }
        uVar6 = *(uint *)(param_1 + 0xa4);
        uVar5 = *(int *)(param_1 + 0xa0) + uVar4;
        *(uint *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + uVar4;
        if (uVar6 <= uVar5) {
          uVar5 = (*(int *)(param_1 + 0xa0) - uVar6) + uVar4;
        }
        *(uint *)(param_1 + 0xa0) = uVar5;
        if (uVar4 != 0) {
          bVar1 = true;
        }
        uVar4 = *(uint *)(param_1 + 0x9c);
        if (uVar5 < uVar4) {
          iVar3 = uVar6 - uVar4;
        }
        else {
          iVar3 = -uVar4;
        }
        if (uVar6 - (uVar5 + iVar3) <= (uint)*(ushort *)(param_1 + 0x70)) {
          if (((*(uint *)(param_1 + 0x68) & 0x30) == 0x20) &&
             ((*(uint *)(param_1 + 0x94) & 0x10) == 0)) {
            *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x10;
            (**(code **)(iVar7 + 0x34))(uVar8);
          }
          if (((*(uint *)(param_1 + 0x68) & 0x3000) == 0x2000) &&
             ((*(uint *)(param_1 + 0x94) & 0x20) == 0)) {
            *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x20;
            (**(code **)(iVar7 + 0x3c))(uVar8);
          }
          if (((*(uint *)(param_1 + 0x68) & 0x200) != 0) && ((*(uint *)(param_1 + 0x94) & 8) == 0))
          {
            (**(code **)(iVar7 + 0x54))(uVar8,*(undefined1 *)(param_1 + 0x76));
            uVar4 = *(uint *)(param_1 + 0x94);
            *(uint *)(param_1 + 0x94) = uVar4 | 8;
            if ((*(uint *)(param_1 + 0x68) & 0x80) == 0) {
              *(uint *)(param_1 + 0x94) = uVar4 | 0xc;
            }
          }
        }
      }
      if ((uVar2 & 4) != 0) {
        FUN_c08435ec(param_1);
      }
      if ((uVar2 & 8) != 0) {
        (**(code **)(iVar7 + 0x20))(uVar8);
      }
      if ((uVar2 & 1) != 0) {
        (**(code **)(iVar7 + 0x24))(uVar8);
      }
      uVar2 = (**(code **)(iVar7 + 0x14))(uVar8);
    } while (uVar2 != 0);
    if (bVar1) {
      EventModify(*(undefined4 *)(param_1 + 0x34),3);
      FUN_c08447a4(param_1,1);
    }
  }
  if (*(int *)(param_1 + 0x100) != 0) {
    InterlockedDecrement((LONG *)(*(int *)(param_1 + 0x100) + 0xc));
  }
  FUN_c0846590(local_28);
  return;
}



/* c08456f4 FUN_c08456f4 */

/* Boundary evidence: original MIPS .pdata c08456f4..c08457a3. Semantic name remains unreviewed. */

undefined4 FUN_c08456f4(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((**(uint **)(param_1 + 0x28) & 3) != 0) {
    iVar2 = *(int *)(param_1 + 0x40);
    while (iVar2 == 0) {
      Sleep(0x14);
      iVar2 = *(int *)(param_1 + 0x40);
    }
  }
  uVar1 = *(uint *)(param_1 + 0x94);
  while ((uVar1 & 1) == 0) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x30),0xffffffff);
    FUN_c0845300(param_1);
    InterruptDone(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
    uVar1 = *(uint *)(param_1 + 0x94);
  }
  return 0;
}



/* c08457a4 FUN_c08457a4 */

/* Boundary evidence: original MIPS .pdata c08457a4..c084583b. Semantic name remains unreviewed. */

undefined4 FUN_c08457a4(LPVOID param_1)

{
  int iVar1;
  HANDLE pvVar2;
  
  iVar1 = InterruptInitialize(*(undefined4 *)(*(int *)((int)param_1 + 0x28) + 4),
                              *(undefined4 *)((int)param_1 + 0x30),0,0);
  if (iVar1 != 0) {
    InterruptDone(*(undefined4 *)(*(int *)((int)param_1 + 0x28) + 4));
    *(uint *)((int)param_1 + 0x94) = *(uint *)((int)param_1 + 0x94) & 0xfffffffe;
    *(undefined4 *)((int)param_1 + 0x40) = 0;
    pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c08456f4,param_1,0,(LPDWORD)0x0);
    *(HANDLE *)((int)param_1 + 0x40) = pvVar2;
    if (pvVar2 != (HANDLE)0x0) {
      return 1;
    }
  }
  return 0;
}



/* c084583c COM_Init */

/* Boundary evidence: original MIPS .pdata c084583c..c0845b17. Semantic name remains unreviewed. */

LPCRITICAL_SECTION COM_Init(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  PRTL_CRITICAL_SECTION_DEBUG p_Var1;
  HANDLE pvVar2;
  HKEY hKey;
  LSTATUS LVar3;
  undefined4 *puVar4;
  ULONG_PTR UVar5;
  int iVar6;
  HLOCAL pvVar7;
  HANDLE *ppvVar8;
  SIZE_T uBytes;
  uint *puVar9;
  DWORD local_28;
  DWORD DStack_24;
  undefined4 local_20 [2];
  
                    /* 0x583c  6  COM_Init */
  local_28 = 4;
  lpCriticalSection = LocalAlloc(0x40,0x108);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    memset(lpCriticalSection,0,0x108);
    ppvVar8 = &lpCriticalSection[9].OwningThread;
    lpCriticalSection[9].LockSemaphore = ppvVar8;
    *ppvVar8 = ppvVar8;
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection[9].SpinCount);
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection->SpinCount);
    InitializeCriticalSection(lpCriticalSection);
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection[7].RecursionCount);
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection[8].LockSemaphore);
    lpCriticalSection[5].LockCount = 0xfa;
    lpCriticalSection[10].LockSemaphore = (HANDLE)0x0;
    lpCriticalSection[6].RecursionCount = 0;
    lpCriticalSection[5].RecursionCount = 10;
    lpCriticalSection[5].OwningThread = (HANDLE)0x64;
    lpCriticalSection[5].LockSemaphore = (HANDLE)0x0;
    lpCriticalSection[5].SpinCount = 0;
    p_Var1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].DebugInfo = p_Var1;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].RecursionCount = (LONG)pvVar2;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].OwningThread = pvVar2;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].LockCount = (LONG)pvVar2;
    if ((((lpCriticalSection[2].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) &&
         (lpCriticalSection[2].RecursionCount != 0)) &&
        (lpCriticalSection[2].OwningThread != (HANDLE)0x0)) &&
       ((pvVar2 != (HANDLE)0x0 && (hKey = (HKEY)OpenDeviceKey(param_1), hKey != (HKEY)0x0)))) {
      local_28 = 4;
      LVar3 = RegQueryValueExW(hKey,L"DeviceArrayIndex",(LPDWORD)0x0,&DStack_24,(LPBYTE)local_20,
                               &local_28);
      if (LVar3 == 0) {
        local_28 = 4;
        LVar3 = RegQueryValueExW(hKey,L"Priority256",(LPDWORD)0x0,&DStack_24,
                                 (LPBYTE)&lpCriticalSection[2].SpinCount,&local_28);
        if (LVar3 != 0) {
          lpCriticalSection[2].SpinCount = 0x67;
        }
        RegCloseKey(hKey);
        puVar4 = FUN_c0843180(local_20[0]);
        lpCriticalSection[1].LockSemaphore = puVar4;
        if (puVar4 != (undefined4 *)0x0) {
          UVar5 = (**(code **)puVar4[2])(param_1,lpCriticalSection,puVar4);
          lpCriticalSection[1].SpinCount = UVar5;
          if (UVar5 != 0) {
            iVar6 = (**(code **)(*(int *)((int)lpCriticalSection[1].LockSemaphore + 8) + 0x28))
                              (UVar5);
            uBytes = iVar6 << 1;
            if (uBytes < 0x801) {
              uBytes = 0x800;
            }
            lpCriticalSection[6].SpinCount = uBytes;
            pvVar7 = LocalAlloc(0x40,uBytes);
            lpCriticalSection[7].LockCount = (LONG)pvVar7;
            if (pvVar7 != (HLOCAL)0x0) {
              puVar9 = lpCriticalSection[1].LockSemaphore;
              lpCriticalSection[6].OwningThread = (HANDLE)0x0;
              lpCriticalSection[6].LockSemaphore = (HANDLE)0x0;
              if (((*puVar9 & 1) == 0) || (iVar6 = FUN_c08457a4(lpCriticalSection), iVar6 != 0)) {
                (**(code **)(*(int *)((int)lpCriticalSection[1].LockSemaphore + 8) + 4))(UVar5);
                return lpCriticalSection;
              }
            }
          }
        }
      }
      else {
        RegCloseKey(hKey);
      }
    }
    COM_Deinit(lpCriticalSection);
  }
  return (LPCRITICAL_SECTION)0x0;
}



/* c0845b18 COM_Open */

/* Boundary evidence: original MIPS .pdata c0845b18..c0845e53. Semantic name remains unreviewed. */

undefined4 * COM_Open(LPVOID param_1,uint param_2,undefined4 param_3)

{
  undefined4 *hMem;
  HANDLE pvVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar7;
  
                    /* 0x5b18  7  COM_Open */
  puVar7 = *(uint **)((int)param_1 + 0x28);
  if ((param_2 & 0x100) != 0) {
    param_2 = param_2 & 0xfffffff;
  }
  if (((param_2 & 0xc0000000) != 0) && (*(int *)((int)param_1 + 0x100) != 0)) {
    SetLastError(0xc);
    return (undefined4 *)0x0;
  }
  hMem = LocalAlloc(0x40,0x3c);
  if (hMem == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *hMem = param_1;
  hMem[3] = 0;
  hMem[1] = param_2;
  hMem[2] = param_3;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  hMem[4] = pvVar1;
  hMem[5] = 0;
  hMem[6] = 0;
  hMem[7] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(hMem + 8));
  if ((param_2 & 0xc0000000) != 0) {
    *(undefined4 **)((int)param_1 + 0x100) = hMem;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0xec);
  EnterCriticalSection(lpCriticalSection);
  piVar2 = (int *)((int)param_1 + 0xe4);
  iVar3 = *piVar2;
  piVar6 = hMem + 0xd;
  *piVar6 = iVar3;
  hMem[0xe] = piVar2;
  *(int **)(iVar3 + 4) = piVar6;
  *piVar2 = (int)piVar6;
  if ((hMem[1] & 0x100) == 0) {
    if (*(int *)((int)param_1 + 0x90) == 0) {
      if (((**(uint **)((int)param_1 + 0x28) & 2) != 0) &&
         (iVar3 = FUN_c08457a4(param_1), iVar3 == 0)) {
LAB_c0845d54:
        SetLastError(0x6e);
        if (hMem == *(undefined4 **)((int)param_1 + 0x100)) {
          *(undefined4 *)((int)param_1 + 0x100) = 0;
        }
        *(int *)hMem[0xe] = *piVar6;
        *(undefined4 *)(*piVar6 + 4) = hMem[0xe];
        LeaveCriticalSection(lpCriticalSection);
        if ((HANDLE)hMem[4] != (HANDLE)0x0) {
          CloseHandle((HANDLE)hMem[4]);
        }
        DeleteCriticalSection((LPCRITICAL_SECTION)(hMem + 8));
        LocalFree(hMem);
        return (undefined4 *)0x0;
      }
      *(undefined4 *)((int)param_1 + 0x60) = 0x1c;
      uVar4 = *(uint *)((int)param_1 + 0xa4);
      *(undefined4 *)((int)param_1 + 100) = 0x2580;
      *(uint *)((int)param_1 + 0x68) = *(uint *)((int)param_1 + 0x68) & 0xffff9011 | 0x1011;
      uVar5 = uVar4 - (uVar4 >> 3 & 0xffff);
      *(short *)((int)param_1 + 0x70) = (short)(uVar4 >> 3);
      *(undefined4 *)((int)param_1 + 0x50) = 0;
      *(undefined4 *)((int)param_1 + 0x54) = 0;
      *(undefined4 *)((int)param_1 + 0x58) = 0;
      *(undefined4 *)((int)param_1 + 0x48) = 0;
      *(undefined4 *)((int)param_1 + 0x4c) = 0;
      *(short *)((int)param_1 + 0x6e) = (short)(uVar4 >> 1);
      if (uVar5 <= (uVar4 >> 1 & 0xffff)) {
        *(short *)((int)param_1 + 0x6e) = (short)uVar5 + -1;
      }
      *(undefined1 *)((int)param_1 + 0x72) = 8;
      *(undefined1 *)((int)param_1 + 0x76) = 0x13;
      *(undefined1 *)((int)param_1 + 0x75) = 0x11;
      *(undefined1 *)((int)param_1 + 0x73) = 0;
      *(undefined1 *)((int)param_1 + 0x74) = 0;
      *(undefined1 *)((int)param_1 + 0x77) = 0xd;
      *(undefined1 *)((int)param_1 + 0x78) = 0xd;
      *(undefined1 *)((int)param_1 + 0x79) = 0xd;
      *(uint *)((int)param_1 + 0x94) = *(uint *)((int)param_1 + 0x94) & 0xffffffc3;
      FUN_c0843800((int)param_1,(undefined4 *)((int)param_1 + 0x60),0);
      (**(code **)(puVar7[2] + 0x70))(*(undefined4 *)((int)param_1 + 0x2c),(int)param_1 + 0x7c);
      iVar3 = (**(code **)(puVar7[2] + 0xc))(*(undefined4 *)((int)param_1 + 0x2c));
      if (iVar3 == 0) goto LAB_c0845d54;
      (**(code **)(puVar7[2] + 0x68))(*(undefined4 *)((int)param_1 + 0x2c),8);
      memset(*(void **)((int)param_1 + 0xac),0,*(size_t *)((int)param_1 + 0xa4));
      if ((*puVar7 & 3) != 0) {
        CeSetThreadPriority(*(undefined4 *)((int)param_1 + 0x40),
                            *(undefined4 *)((int)param_1 + 0x44));
      }
      *(undefined4 *)((int)param_1 + 0x9c) = 0;
      *(undefined4 *)((int)param_1 + 0xa0) = 0;
    }
    *(int *)((int)param_1 + 0x90) = *(int *)((int)param_1 + 0x90) + 1;
  }
  LeaveCriticalSection(lpCriticalSection);
  return hMem;
}



/* c0845e54 COM_Write */

/* Boundary evidence: original MIPS .pdata c0845e54..c08460af. Semantic name remains unreviewed. */

ULONG_PTR COM_Write(undefined4 *param_1,int param_2,HANDLE param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  HANDLE *lpCriticalSection_00;
  ULONG_PTR UVar4;
  HANDLE local_30 [2];
  
                    /* 0x5e54  14  COM_Write */
  lpCriticalSection = (LPCRITICAL_SECTION)*param_1;
  local_30[0] = (HANDLE)0x0;
  if ((lpCriticalSection == (LPCRITICAL_SECTION)0x0) ||
     (lpCriticalSection[6].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0)) {
    DVar2 = 6;
  }
  else if ((param_1[1] & 0x40000000) == 0) {
    DVar2 = 0xc;
  }
  else {
    if ((param_2 != 0) && (param_3 != (HANDLE)0x0)) {
      iVar1 = CeAllocAsynchronousBuffer(local_30,param_2,param_3,4);
      if (iVar1 < 0) {
        return 0xffffffff;
      }
      if (local_30[0] == (HANDLE)0x0) {
        return 0xffffffff;
      }
      InterlockedIncrement(param_1 + 3);
      UVar4 = lpCriticalSection[1].SpinCount;
      iVar1 = *(int *)((int)lpCriticalSection[1].LockSemaphore + 8);
      EnterCriticalSection(lpCriticalSection);
      lpCriticalSection_00 = &lpCriticalSection[8].LockSemaphore;
      EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      lpCriticalSection[6].LockCount = lpCriticalSection[6].LockCount & 0xffffff7f;
      WaitForSingleObject(lpCriticalSection[2].OwningThread,0);
      pvVar3 = lpCriticalSection[2].OwningThread;
      lpCriticalSection[8].OwningThread = local_30[0];
      lpCriticalSection[8].RecursionCount = (LONG)param_3;
      lpCriticalSection[8].LockCount = 0;
      lpCriticalSection[3].SpinCount = 0;
      lpCriticalSection[3].LockSemaphore = param_3;
      EventModify(pvVar3,2);
      LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      FUN_c08435ec((int)lpCriticalSection);
      DVar2 = (int)lpCriticalSection[5].LockSemaphore * (int)param_3 +
              lpCriticalSection[5].SpinCount;
      if (DVar2 == 0) {
        DVar2 = 0xffffffff;
      }
      WaitForSingleObject(lpCriticalSection[2].OwningThread,DVar2);
      if (((lpCriticalSection[6].LockCount & 0x80U) == 0) &&
         (lpCriticalSection[6].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0)) {
        SetLastError(6);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      lpCriticalSection[8].OwningThread = (HANDLE)0x0;
      lpCriticalSection[8].RecursionCount = 0;
      lpCriticalSection[3].LockSemaphore = (HANDLE)0x0;
      lpCriticalSection[8].LockCount = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      LeaveCriticalSection(lpCriticalSection);
      FUN_c08447a4((int)lpCriticalSection,4);
      if ((lpCriticalSection[4].RecursionCount & 0x3000U) == 0x3000) {
        (**(code **)(iVar1 + 0x3c))(UVar4);
      }
      InterlockedDecrement(param_1 + 3);
      if (local_30[0] != (HANDLE)0x0) {
        CeFreeAsynchronousBuffer(local_30[0],param_2,param_3,4);
      }
      return lpCriticalSection[3].SpinCount;
    }
    DVar2 = 0x57;
  }
  SetLastError(DVar2);
  return 0xffffffff;
}



/* c08462b0 FUN_c08462b0 */

/* Boundary evidence: original MIPS .pdata c08462b0..c08462db. Semantic name remains unreviewed. */

undefined4 FUN_c08462b0(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c08462dc FUN_c08462dc */

/* Boundary evidence: original MIPS .pdata c08462dc..c0846417. Semantic name remains unreviewed. */

int FUN_c08462dc(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c0847114 != (code *)0x0) {
      iVar2 = (*DAT_c0847114)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c084638c;
    FUN_c0846770();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c08462b0(param_1,param_2);
  }
LAB_c084638c:
  if (((param_2 == 0) && (FUN_c08466f8(), iVar1 != 0)) && (DAT_c0847114 != (code *)0x0)) {
    iVar1 = (*DAT_c0847114)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0846418 FUN_c0846418 */

/* Boundary evidence: original MIPS .pdata c0846418..c0846443. Semantic name remains unreviewed. */

void FUN_c0846418(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c0846444 entry */

/* Boundary evidence: original MIPS .pdata c0846444..c084649b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c084649c();
  }
  FUN_c08462dc(param_1,param_2,param_3);
  return;
}



/* c084649c FUN_c084649c */

/* Boundary evidence: original MIPS .pdata c084649c..c084650f. Semantic name remains unreviewed. */

void FUN_c084649c(void)

{
  uint uVar1;
  
  if ((DAT_c08470f4 == 0) || (DAT_c08470f4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c08470f4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c08470f4 == 0) {
      DAT_c08470f4 = 0xb064;
    }
  }
  DAT_c08470f8 = ~DAT_c08470f4;
  return;
}



/* c0846510 FUN_c0846510 */

/* Boundary evidence: original MIPS .pdata c0846510..c0846563. Semantic name remains unreviewed. */

void FUN_c0846510(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0846590(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0846564 FUN_c0846564 */

/* Boundary evidence: original MIPS .pdata c0846564..c084658f. Semantic name remains unreviewed. */

undefined4 FUN_c0846564(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0846510(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0846590 FUN_c0846590 */

/* Boundary evidence: original MIPS .pdata c0846590..c08465d7. Semantic name remains unreviewed. */

void FUN_c0846590(uint param_1)

{
  if ((param_1 == DAT_c08470f4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c08465d8 FUN_c08465d8 */

/* Boundary evidence: original MIPS .pdata c08465d8..c08466f7. Semantic name remains unreviewed. */

void FUN_c08465d8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c0847104 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c084710c;
    if (DAT_c084710c != (undefined4 *)0x0) {
      while (DAT_c0847108 = DAT_c0847108 + -1, _Memory <= DAT_c0847108) {
        if ((code *)*DAT_c0847108 != (code *)0x0) {
          (*(code *)*DAT_c0847108)();
          _Memory = DAT_c084710c;
        }
      }
      free(_Memory);
      DAT_c0847108 = (undefined4 *)0x0;
      DAT_c084710c = (undefined4 *)0x0;
    }
    FUN_c084671c((undefined4 *)&DAT_c0841010,(undefined4 *)&DAT_c0841014);
  }
  FUN_c084671c((undefined4 *)&DAT_c0841018,(undefined4 *)&DAT_c084101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c0847110,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c08466f8 FUN_c08466f8 */

/* Boundary evidence: original MIPS .pdata c08466f8..c084671b. Semantic name remains unreviewed. */

void FUN_c08466f8(void)

{
  FUN_c08465d8(0,0,1);
  return;
}



/* c084671c FUN_c084671c */

/* Boundary evidence: original MIPS .pdata c084671c..c084676f. Semantic name remains unreviewed. */

void FUN_c084671c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0846770 FUN_c0846770 */

/* Boundary evidence: original MIPS .pdata c0846770..c08467ab. Semantic name remains unreviewed. */

void FUN_c0846770(void)

{
  FUN_c084671c((undefined4 *)&DAT_c0841008,(undefined4 *)&DAT_c084100c);
  FUN_c084671c((undefined4 *)&DAT_c0841000,(undefined4 *)&DAT_c0841004);
  return;
}


