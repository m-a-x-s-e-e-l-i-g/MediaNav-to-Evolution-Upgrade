/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 400e16b0 FUN_400e16b0 */

/* WARNING: Removing unreachable block (ram,0x400e1788) */
/* Boundary evidence: original MIPS .pdata 400e16b0..400e17e3. Semantic name remains unreviewed. */

int * FUN_400e16b0(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  
  memset(param_1,0,4);
  param_1[0x1c] = param_2;
  param_1[0x19] = param_3;
  param_1[0x13] = 0;
  iVar3 = 0;
  iVar4 = 0;
  iVar2 = FUN_400e38d0((int)param_1);
  if ((((iVar2 == 0) || (iVar3 = FUN_400e3b64(param_1), iVar3 == 0)) ||
      (iVar4 = FUN_400e6128(param_1), iVar4 == 0)) ||
     (bVar1 = FUN_400e5874(param_1), CONCAT31(extraout_var,bVar1) == 0)) {
    if (param_1[1] != 0) {
      EventModify(param_1[1],3);
    }
    if (iVar4 != 0) {
      FUN_400e5e4c((int)param_1);
    }
    if (iVar3 != 0) {
      FUN_400e3c74(param_1);
    }
    if (iVar2 != 0) {
      FUN_400e3bfc((int)param_1);
    }
  }
  else {
    param_1[0x1a] = 1;
    EventModify(*param_1,3);
  }
  return param_1;
}



/* 400e17e4 FUN_400e17e4 */

/* Boundary evidence: original MIPS .pdata 400e17e4..400e184b. Semantic name remains unreviewed. */

void FUN_400e17e4(undefined4 *param_1)

{
  if (param_1[0x1a] != 0) {
    if (param_1[1] != 0) {
      EventModify(param_1[1],3);
    }
    FUN_400e3cb8((int)param_1);
    FUN_400e3d20((int)param_1);
    FUN_400e5e4c((int)param_1);
    FUN_400e3c74(param_1);
    FUN_400e3bfc((int)param_1);
  }
  return;
}



/* 400e184c FUN_400e184c */

/* Boundary evidence: original MIPS .pdata 400e184c..400e18c7. Semantic name remains unreviewed. */

void FUN_400e184c(undefined4 *param_1,FILETIME *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  if (param_2 == (FILETIME *)0x0) {
    param_1[0x13] = 0;
  }
  else {
    param_1[0x13] = 1;
    LocalFileTimeToFileTime(param_2,(LPFILETIME)(param_1 + 0x11));
  }
  EventModify(*param_1,3);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



/* 400e18c8 FUN_400e18c8 */

/* Boundary evidence: original MIPS .pdata 400e18c8..400e1933. Semantic name remains unreviewed. */

void FUN_400e18c8(int param_1,uint param_2)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  for (piVar1 = *(int **)(param_1 + 0x40); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    piVar1[2] = piVar1[2] & param_2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return;
}



/* 400e1934 FUN_400e1934 */

/* Boundary evidence: original MIPS .pdata 400e1934..400e1a47. Semantic name remains unreviewed. */

wchar_t * FUN_400e1934(undefined4 param_1)

{
  wchar_t *pwVar1;
  
  switch(param_1) {
  case 1:
    pwVar1 = L"AppRunAfterTimeChange";
    break;
  case 2:
    pwVar1 = L"AppRunAfterSync";
    break;
  case 3:
    pwVar1 = L"AppRunAtAcPowerOn";
    break;
  case 4:
    pwVar1 = L"AppRunAtAcPowerOff";
    break;
  case 5:
    pwVar1 = L"AppRunAtNetConnect";
    break;
  case 6:
    pwVar1 = L"AppRunAtNetDisconnect";
    break;
  case 7:
    pwVar1 = L"AppRunDeviceChange";
    break;
  case 8:
    pwVar1 = L"AppRunAtIrDiscovery";
    break;
  case 9:
    pwVar1 = L"AppRunAtRs232Detect";
    break;
  case 10:
    pwVar1 = L"AppRunAfterRestore";
    break;
  case 0xb:
    pwVar1 = L"AppRunAfterWakeup";
    break;
  case 0xc:
    pwVar1 = L"AppRunAfterTzChange";
    break;
  default:
    pwVar1 = L"AppRunAfterExtendedEvent";
    break;
  case 0xe:
    pwVar1 = L"AppRunAfterRndisFnDetected";
    break;
  case 0xf:
    pwVar1 = L"AppRunAfterInternetProxyChange";
  }
  return pwVar1;
}



/* 400e1a48 FUN_400e1a48 */

/* Boundary evidence: original MIPS .pdata 400e1a48..400e1b73. Semantic name remains unreviewed. */

int FUN_400e1a48(undefined4 param_1,int *param_2,uint *param_3)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea1cc != 1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    WaitForSingleObject(DAT_400ea480,DAT_400ea490);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    if (DAT_400ea1cc != 1) {
      SetLastError(0x426);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
      return 0;
    }
  }
  InterlockedIncrement(&DAT_400ea468);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (param_2 == (int *)0x0) {
    SetLastError(0x57);
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_400e58d0(DAT_400ea488,param_1,param_2,param_3);
  }
  InterlockedDecrement(&DAT_400ea468);
  return iVar1;
}



/* 400e1b74 FUN_400e1b74 */

/* Boundary evidence: original MIPS .pdata 400e1b74..400e1c83. Semantic name remains unreviewed. */

bool FUN_400e1b74(int param_1)

{
  bool bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea1cc != 1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    WaitForSingleObject(DAT_400ea480,DAT_400ea490);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    if (DAT_400ea1cc != 1) {
      SetLastError(0x426);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
      return false;
    }
  }
  InterlockedIncrement(&DAT_400ea468);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  bVar1 = false;
  if (param_1 == 0) {
    SetLastError(0x57);
  }
  else {
    bVar1 = FUN_400e412c(DAT_400ea488,param_1,1);
  }
  InterlockedDecrement(&DAT_400ea468);
  return bVar1;
}



/* 400e1c84 FUN_400e1c84 */

/* Boundary evidence: original MIPS .pdata 400e1c84..400e1de3. Semantic name remains unreviewed. */

undefined4 FUN_400e1c84(wchar_t *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea1cc != 1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    WaitForSingleObject(DAT_400ea480,DAT_400ea490);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    if (DAT_400ea1cc != 1) {
      SetLastError(0x426);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
      return 0;
    }
  }
  InterlockedIncrement(&DAT_400ea468);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  uVar3 = 0;
  if (param_1 == (wchar_t *)0x0) {
    SetLastError(0x57);
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(DAT_400ea488 + 2));
    uVar3 = 1;
    do {
      iVar2 = FUN_400e42a8((int)DAT_400ea488,param_1);
      if (iVar2 == 0) goto LAB_400e1dac;
      bVar1 = FUN_400e412c(DAT_400ea488,iVar2,1);
    } while (CONCAT31(extraout_var,bVar1) != 0);
    LeaveCriticalSection((LPCRITICAL_SECTION)(DAT_400ea488 + 2));
    uVar3 = 0;
LAB_400e1dac:
    LeaveCriticalSection((LPCRITICAL_SECTION)(DAT_400ea488 + 2));
  }
  InterlockedDecrement(&DAT_400ea468);
  return uVar3;
}



/* 400e1de4 FUN_400e1de4 */

/* Boundary evidence: original MIPS .pdata 400e1de4..400e1f2b. Semantic name remains unreviewed. */

undefined4 FUN_400e1de4(HWND param_1,int param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea1cc != 1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    WaitForSingleObject(DAT_400ea480,DAT_400ea490);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    if (DAT_400ea1cc != 1) goto LAB_400e1ee8;
  }
  if (*(int *)(DAT_400ea488 + 0x6c) != 0) {
    InterlockedIncrement(&DAT_400ea468);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    uVar1 = 0;
    if (((param_2 == 0) || (*(uint *)(param_2 + 0x10) < 0x104)) || (*(int *)(param_2 + 0xc) == 0)) {
      SetLastError(0x57);
    }
    else {
      uVar1 = FUN_400e6f04(param_1,param_2,*(int *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x14));
    }
    InterlockedDecrement(&DAT_400ea468);
    return uVar1;
  }
LAB_400e1ee8:
  SetLastError(0x426);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  return 0;
}



/* 400e1f2c FUN_400e1f2c */

/* Boundary evidence: original MIPS .pdata 400e1f2c..400e20c7. Semantic name remains unreviewed. */

int FUN_400e1f2c(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  int local_58 [3];
  int local_4c;
  wchar_t *local_48;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea1cc != 1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    WaitForSingleObject(DAT_400ea480,DAT_400ea490);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    if (DAT_400ea1cc != 1) {
      SetLastError(0x426);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
      return 0;
    }
  }
  InterlockedIncrement(&DAT_400ea468);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  iVar3 = 0;
  if (param_1 == 0) {
    SetLastError(0x57);
  }
  else if (param_2 == 0) {
    iVar3 = 1;
    do {
      iVar2 = FUN_400e432c((int)DAT_400ea488,param_1);
      if (iVar2 == 0) goto LAB_400e2098;
      bVar1 = FUN_400e412c(DAT_400ea488,iVar2,0);
    } while (CONCAT31(extraout_var,bVar1) != 0);
    iVar3 = 0;
  }
  else {
    memset(local_58,0,0x34);
    local_58[0] = 0x34;
    local_58[1] = 1;
    local_58[2] = param_2;
    local_4c = param_1;
    local_48 = FUN_400e1934(param_2);
    iVar3 = FUN_400e58d0(DAT_400ea488,0,local_58,(uint *)0x0);
  }
LAB_400e2098:
  InterlockedDecrement(&DAT_400ea468);
  return iVar3;
}



/* 400e20c8 FUN_400e20c8 */

/* Boundary evidence: original MIPS .pdata 400e20c8..400e223f. Semantic name remains unreviewed. */

int FUN_400e20c8(wchar_t *param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  int local_58 [3];
  wchar_t *local_4c;
  wchar_t *local_48;
  undefined1 auStack_44 [36];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea1cc != 1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    WaitForSingleObject(DAT_400ea480,DAT_400ea490);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    if (DAT_400ea1cc != 1) {
      SetLastError(0x426);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
      return 0;
    }
  }
  InterlockedIncrement(&DAT_400ea468);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  iVar2 = 0;
  if (param_1 == (wchar_t *)0x0) {
    SetLastError(0x57);
  }
  else {
    iVar2 = FUN_400e5600(DAT_400ea488,param_1);
    if (param_2 != (void *)0x0) {
      memset(local_58,0,0x34);
      local_58[1] = 2;
      local_58[0] = 0x34;
      local_48 = L"AppRunAtTime";
      local_4c = param_1;
      memcpy(auStack_44,param_2,0x10);
      iVar1 = FUN_400e1a48(0,local_58,(uint *)0x0);
      iVar2 = 1;
      if (iVar1 == 0) {
        iVar2 = 0;
      }
    }
  }
  InterlockedDecrement(&DAT_400ea468);
  return iVar2;
}



/* 400e2240 FUN_400e2240 */

/* Boundary evidence: original MIPS .pdata 400e2240..400e234b. Semantic name remains unreviewed. */

undefined4 FUN_400e2240(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea1cc != 1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    WaitForSingleObject(DAT_400ea480,DAT_400ea490);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    if (DAT_400ea1cc != 1) {
      SetLastError(0x426);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
      return 0;
    }
  }
  InterlockedIncrement(&DAT_400ea468);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  uVar1 = FUN_400e4b74(DAT_400ea488,param_1,param_2,param_3);
  InterlockedDecrement(&DAT_400ea468);
  return uVar1;
}



/* 400e234c FUN_400e234c */

/* Boundary evidence: original MIPS .pdata 400e234c..400e2467. Semantic name remains unreviewed. */

undefined4 FUN_400e234c(int param_1,DWORD param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea1cc != 1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    WaitForSingleObject(DAT_400ea480,DAT_400ea490);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    if (DAT_400ea1cc != 1) {
      SetLastError(0x426);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
      return 0;
    }
  }
  InterlockedIncrement(&DAT_400ea468);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  uVar1 = FUN_400e4cf4(DAT_400ea488,param_1,param_2,param_3,param_4);
  InterlockedDecrement(&DAT_400ea468);
  return uVar1;
}



/* 400e2468 FUN_400e2468 */

/* Boundary evidence: original MIPS .pdata 400e2468..400e2563. Semantic name remains unreviewed. */

byte FUN_400e2468(int param_1,wchar_t *param_2)

{
  byte bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea1cc != 1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    WaitForSingleObject(DAT_400ea480,DAT_400ea48c);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    if (DAT_400ea1cc != 1) {
      SetLastError(0x426);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
      return 0;
    }
  }
  InterlockedIncrement(&DAT_400ea468);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  bVar1 = FUN_400e5bb0(DAT_400ea488,param_1,param_2);
  InterlockedDecrement(&DAT_400ea468);
  return bVar1;
}



/* 400e2564 FUN_400e2564 */

/* Boundary evidence: original MIPS .pdata 400e2564..400e25bf. Semantic name remains unreviewed. */

undefined4 FUN_400e2564(void)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea488 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(DAT_400ea488 + 0x74);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  return uVar1;
}



/* 400e25c0 FUN_400e25c0 */

/* Boundary evidence: original MIPS .pdata 400e25c0..400e25e3. Semantic name remains unreviewed. */

void FUN_400e25c0(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(DAT_400ea488 + 8));
  return;
}



/* 400e25e4 FUN_400e25e4 */

/* Boundary evidence: original MIPS .pdata 400e25e4..400e2607. Semantic name remains unreviewed. */

void FUN_400e25e4(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(DAT_400ea488 + 8));
  return;
}



/* 400e2608 FUN_400e2608 */

int FUN_400e2608(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(DAT_400ea488 + 0x40);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if (piVar1[3] == param_1) break;
    piVar1 = (int *)*piVar1;
  }
  return (int)piVar1;
}



/* 400e2640 FUN_400e2640 */

/* Boundary evidence: original MIPS .pdata 400e2640..400e2667. Semantic name remains unreviewed. */

void FUN_400e2640(int param_1,uint param_2)

{
  FUN_400e53b4(DAT_400ea488,param_1,param_2);
  return;
}



/* 400e2668 FUN_400e2668 */

/* Boundary evidence: original MIPS .pdata 400e2668..400e268f. Semantic name remains unreviewed. */

void FUN_400e2668(int param_1)

{
  FUN_400e412c(DAT_400ea488,param_1,0);
  return;
}



/* 400e2690 FUN_400e2690 */

/* Boundary evidence: original MIPS .pdata 400e2690..400e26b3. Semantic name remains unreviewed. */

void FUN_400e2690(FILETIME *param_1)

{
  FUN_400e184c(DAT_400ea488,param_1);
  return;
}



/* 400e26b4 FUN_400e26b4 */

/* Boundary evidence: original MIPS .pdata 400e26b4..400e2703. Semantic name remains unreviewed. */

void FUN_400e26b4(void)

{
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  puVar1 = DAT_400ea488;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_400ea488 + 2);
  EnterCriticalSection(lpCriticalSection);
  puVar1[0x13] = 0;
  EventModify(*puVar1,3);
  LeaveCriticalSection(lpCriticalSection);
  return;
}



/* 400e2704 FUN_400e2704 */

/* Boundary evidence: original MIPS .pdata 400e2704..400e2727. Semantic name remains unreviewed. */

void FUN_400e2704(uint param_1)

{
  FUN_400e18c8(DAT_400ea488,param_1);
  return;
}



/* 400e2728 FUN_400e2728 */

/* Boundary evidence: original MIPS .pdata 400e2728..400e281b. Semantic name remains unreviewed. */

undefined4 FUN_400e2728(void)

{
  undefined4 *hMem;
  
  EventModify(DAT_400ea480,2);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  hMem = DAT_400ea488;
  while( true ) {
    DAT_400ea488 = hMem;
    if (DAT_400ea1cc != 1) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
      return 0x426;
    }
    DAT_400ea1cc = 3;
    if (DAT_400ea468 == 0) break;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    Sleep(1000);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    hMem = DAT_400ea488;
  }
  DAT_400ea488 = (undefined4 *)0x0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (hMem != (undefined4 *)0x0) {
    FUN_400e17e4(hMem);
    LocalFree(hMem);
  }
  DAT_400ea1cc = 0;
  return 0;
}



/* 400e281c FUN_400e281c */

/* Boundary evidence: original MIPS .pdata 400e281c..400e28bb. Semantic name remains unreviewed. */

DWORD FUN_400e281c(LPTHREAD_START_ROUTINE param_1)

{
  HANDLE hHandle;
  DWORD local_10 [2];
  
  hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,param_1,(LPVOID)0x0,0,(LPDWORD)0x0);
  if (hHandle == (HANDLE)0x0) {
    local_10[0] = GetLastError();
  }
  else {
    WaitForSingleObject(hHandle,0xffffffff);
    local_10[0] = 0x54f;
    GetExitCodeThread(hHandle,local_10);
    CloseHandle(hHandle);
  }
  return local_10[0];
}



/* 400e28bc FUN_400e28bc */

/* Boundary evidence: original MIPS .pdata 400e28bc..400e299f. Semantic name remains unreviewed. */

undefined4 FUN_400e28bc(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    CloseHandle(DAT_400ea480);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    DAT_400ea1cc = 5;
    FUN_400e8764();
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    FUN_400e8764();
    DAT_400ea480 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,L"system/events/notify/APIReady");
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    DAT_400ea1cc = 0;
    DAT_400ea488 = 0;
    DAT_400ea468 = 0;
    DAT_400ea484 = param_1;
  }
  return 1;
}



/* 400e29a0 NFY_Deinit */

/* Boundary evidence: original MIPS .pdata 400e29a0..400e29c3. Semantic name remains unreviewed. */

undefined4 NFY_Deinit(void)

{
                    /* 0x29a0  2  NFY_Deinit */
  FUN_400e281c(FUN_400e2728);
  return 1;
}



/* 400e29c4 NFY_Close */

undefined4 NFY_Close(void)

{
                    /* 0x29c4  1  NFY_Close
                       0x29c4  5  NFY_Open */
  return 1;
}



/* 400e29cc NFY_Read */

undefined4 NFY_Read(void)

{
                    /* 0x29cc  6  NFY_Read
                       0x29cc  7  NFY_Seek
                       0x29cc  8  NFY_Write */
  return 0xffffffff;
}



/* 400e29d4 FUN_400e29d4 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 400e29d4..400e2e23. Semantic name remains unreviewed. */

undefined4 FUN_400e29d4(void)

{
  undefined4 uVar1;
  LSTATUS LVar2;
  int iVar3;
  HMODULE hLibModule;
  int *piVar4;
  DWORD local_40;
  DWORD local_3c;
  DWORD local_38;
  HKEY local_34;
  uint local_30 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
  if (DAT_400ea1cc == 0) {
    EventModify(DAT_400ea480,2);
    DAT_400ea1cc = 2;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    DAT_400ea490 = 15000;
    DAT_400ea48c = 5000;
    DAT_400ea494 = 20000;
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\GWE\\Notify",0,0x20019,&local_34);
    if (LVar2 == 0) {
      local_38 = 0;
      local_3c = 4;
      local_40 = 0;
      LVar2 = RegQueryValueExW(local_34,L"ShortApiTimeout",(LPDWORD)0x0,&local_40,(LPBYTE)&local_38,
                               &local_3c);
      if (((LVar2 == 0) && (local_40 == 4)) && (local_3c == 4)) {
        DAT_400ea48c = local_38;
      }
      local_38 = 0;
      local_3c = 4;
      local_40 = 0;
      LVar2 = RegQueryValueExW(local_34,L"LongApiTimeout",(LPDWORD)0x0,&local_40,(LPBYTE)&local_38,
                               &local_3c);
      if (((LVar2 == 0) && (local_40 == 4)) && (local_3c == 4)) {
        DAT_400ea490 = local_38;
      }
      local_38 = 0;
      local_3c = 4;
      local_40 = 0;
      LVar2 = RegQueryValueExW(local_34,L"MountTimeout",(LPDWORD)0x0,&local_40,(LPBYTE)&local_38,
                               &local_3c);
      if (((LVar2 == 0) && (local_40 == 4)) && (local_3c == 4)) {
        DAT_400ea494 = local_38;
      }
      RegCloseKey(local_34);
    }
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\GWE\\ThreadPriorities",0,0x20019,&local_34);
    if (LVar2 == 0) {
      local_38 = 4;
      RegQueryValueExW(local_34,L"NotifyUi",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&DAT_400ea1d8,
                       &local_38);
      local_38 = 4;
      RegQueryValueExW(local_34,L"NotifyAlarm",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&DAT_400ea1dc,
                       &local_38);
      RegCloseKey(local_34);
    }
    local_30[1] = 0;
    local_30[0] = 0;
    iVar3 = KernelLibIoControl(1,5,0,0,local_30,4,local_30 + 1);
    if (((iVar3 == 0) || (local_30[0] < 1000)) || (60000 < local_30[0])) {
      local_30[0] = 100000000;
    }
    else {
      local_30[0] = local_30[0] * 10000;
    }
    hLibModule = LoadLibraryW(L"coredll.dll");
    if (hLibModule != (HMODULE)0x0) {
      DAT_400ea498 = GetProcAddressW(hLibModule,L"SystemIdleTimerReset");
      FreeLibrary(hLibModule);
    }
    piVar4 = LocalAlloc(0x40,0x78);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = FUN_400e16b0(piVar4,DAT_400ea484,local_30[0]);
    }
    if (piVar4 == (int *)0x0) {
      DAT_400ea1cc = 0;
    }
    else if (piVar4[0x1a] == 0) {
      FUN_400e17e4(piVar4);
      LocalFree(piVar4);
      DAT_400ea1cc = 0;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
      DAT_400ea1cc = 1;
      DAT_400ea488 = piVar4;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    }
    uVar1 = 0;
    if (DAT_400ea488 == (int *)0x0) {
      uVar1 = 0x426;
    }
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_400ea46c);
    uVar1 = 0x420;
  }
  return uVar1;
}



/* 400e2e24 NFY_Init */

/* Boundary evidence: original MIPS .pdata 400e2e24..400e2e63. Semantic name remains unreviewed. */

undefined4 NFY_Init(uint param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  
                    /* 0x2e24  4  NFY_Init */
  if (((param_1 & 1) == 0) && (DVar1 = FUN_400e281c(FUN_400e29d4), DVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 400e2e64 NFY_IOControl */

/* Boundary evidence: original MIPS .pdata 400e2e64..400e365b. Semantic name remains unreviewed. */

bool NFY_IOControl(undefined4 param_1,uint param_2,wchar_t *param_3,uint param_4,int *param_5,
                  DWORD param_6,int *param_7)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  undefined3 extraout_var;
  DWORD DVar4;
  undefined3 extraout_var_00;
  code *pcVar5;
  wchar_t *pwVar6;
  DWORD dwErrCode;
  
                    /* 0x2e64  3  NFY_IOControl */
  GetCallerProcess();
  dwErrCode = 0x57;
  iVar3 = CeGetCallerTrust();
  bVar1 = iVar3 != 2;
  if (param_2 < 0x106000d) {
    if (param_2 == 0x106000c) {
      if ((param_3 == (wchar_t *)0x0) || (param_4 < 0x21c)) goto LAB_400e360c;
      pwVar6 = (wchar_t *)0x0;
      if (*(int *)(param_3 + 0x10c) == 0) {
        pwVar6 = param_3 + 0x104;
      }
      iVar3 = FUN_400e20c8(param_3,pwVar6);
      goto LAB_400e35e4;
    }
    if (param_2 == 0x1040004) {
      if (!bVar1) {
        dwErrCode = FUN_400e281c(FUN_400e29d4);
        if ((DAT_400ea1cc != 1) || (DAT_400ea480 == 0)) goto LAB_400e360c;
LAB_400e30a8:
        EventModify(DAT_400ea480,3);
        goto LAB_400e360c;
      }
LAB_400e326c:
      dwErrCode = 5;
      goto LAB_400e360c;
    }
    if (param_2 == 0x1040008) {
      if (!bVar1) {
        pcVar5 = FUN_400e2728;
LAB_400e3158:
        dwErrCode = FUN_400e281c(pcVar5);
        goto LAB_400e360c;
      }
      goto LAB_400e326c;
    }
    if (param_2 == 0x104000c) {
      if (!bVar1) {
        dwErrCode = FUN_400e281c(FUN_400e2728);
        if (dwErrCode != 0) goto LAB_400e360c;
        pcVar5 = FUN_400e29d4;
        goto LAB_400e3158;
      }
      goto LAB_400e326c;
    }
    if (param_2 != 0x1040020) {
      if (param_2 == 0x1040038) {
        if ((DAT_400ea1cc != 1) || (DAT_400ea480 == 0)) goto LAB_400e360c;
        dwErrCode = 0;
        goto LAB_400e30a8;
      }
      if (param_2 == 0x1060004) {
        if (((param_3 != (wchar_t *)0x0) && (param_5 != (int *)0x0)) && (0xf < param_4)) {
          if (*(int *)(param_3 + 4) != 0) {
            iVar3 = *(int *)(param_3 + 4) + (int)param_3;
            *(int *)(param_3 + 4) = iVar3;
            if (*(int *)(iVar3 + 0xc) != 0) {
              *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + (int)param_3;
            }
            iVar3 = *(int *)(*(int *)(param_3 + 4) + 0x10);
            if (iVar3 != 0) {
              *(int *)(*(int *)(param_3 + 4) + 0x10) = iVar3 + (int)param_3;
            }
          }
          if (*(int *)(param_3 + 6) != 0) {
            iVar3 = *(int *)(param_3 + 6) + (int)param_3;
            *(int *)(param_3 + 6) = iVar3;
            if (*(int *)(iVar3 + 4) != 0) {
              *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + (int)param_3;
            }
            iVar3 = *(int *)(*(int *)(param_3 + 6) + 8);
            if (iVar3 != 0) {
              *(int *)(*(int *)(param_3 + 6) + 8) = iVar3 + (int)param_3;
            }
            iVar3 = *(int *)(*(int *)(param_3 + 6) + 0xc);
            if (iVar3 != 0) {
              *(int *)(*(int *)(param_3 + 6) + 0xc) = iVar3 + (int)param_3;
            }
          }
          dwErrCode = 0;
          iVar3 = FUN_400e1a48(*(undefined4 *)param_3,*(int **)(param_3 + 4),*(uint **)(param_3 + 6)
                              );
          *(int *)param_3 = iVar3;
          if (iVar3 == 0) {
            dwErrCode = GetLastError();
            if (dwErrCode == 0) {
              dwErrCode = 0x54f;
            }
          }
          else {
            *param_5 = iVar3;
          }
        }
        goto LAB_400e360c;
      }
      if (((param_2 != 0x1060008) || (param_3 == (wchar_t *)0x0)) || (param_4 < 0x21c))
      goto LAB_400e360c;
      bVar1 = FUN_400e1b74(*(int *)param_3);
      iVar3 = CONCAT31(extraout_var,bVar1);
      goto LAB_400e35e4;
    }
    if (bVar1) goto LAB_400e326c;
    if ((param_5 != (int *)0x0) && (param_6 == 4)) {
      *param_5 = DAT_400ea1cc;
      if (param_7 != (int *)0x0) {
        *param_7 = 4;
      }
      dwErrCode = 0;
      goto LAB_400e360c;
    }
  }
  else {
    if (param_2 == 0x1060010) {
      if ((param_3 == (wchar_t *)0x0) || (param_4 < 0x21c)) goto LAB_400e360c;
      iVar3 = FUN_400e1f2c((int)param_3,*(int *)(param_3 + 0x104));
LAB_400e35e4:
      dwErrCode = 0;
      if (iVar3 != 0) goto LAB_400e360c;
LAB_400e35ec:
      dwErrCode = GetLastError();
      DVar4 = dwErrCode;
    }
    else {
      if (param_2 == 0x1060014) {
        if ((param_3 == (wchar_t *)0x0) || (param_4 < 0x21c)) goto LAB_400e360c;
        iVar3 = FUN_400e1c84(param_3);
        goto LAB_400e35e4;
      }
      if (param_2 == 0x1060018) {
        if (((param_3 == (wchar_t *)0x0) || (param_5 == (int *)0x0)) || (param_4 < 0x10))
        goto LAB_400e360c;
        if (*(int *)(param_3 + 6) != 0) {
          iVar3 = *(int *)(param_3 + 6) + (int)param_3;
          *(int *)(param_3 + 6) = iVar3;
          if (*(int *)(iVar3 + 4) != 0) {
            *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + (int)param_3;
          }
          iVar3 = *(int *)(*(int *)(param_3 + 6) + 8);
          if (iVar3 != 0) {
            *(int *)(*(int *)(param_3 + 6) + 8) = iVar3 + (int)param_3;
          }
          iVar3 = *(int *)(*(int *)(param_3 + 6) + 0xc);
          if (iVar3 != 0) {
            *(int *)(*(int *)(param_3 + 6) + 0xc) = iVar3 + (int)param_3;
          }
        }
        dwErrCode = 0;
        iVar3 = FUN_400e1de4(*(HWND *)param_3,*(int *)(param_3 + 6));
        if (iVar3 == 0) {
          dwErrCode = GetLastError();
          DVar4 = dwErrCode;
joined_r0x400e3574:
          if (DVar4 == 0) goto LAB_400e3608;
        }
        else {
          iVar3 = *(int *)(*(int *)(param_3 + 6) + 0xc);
          if (iVar3 != 0) {
            DVar4 = CeSafeCopyMemory(param_5,iVar3,*(undefined4 *)(*(int *)(param_3 + 6) + 0x10));
            goto joined_r0x400e3574;
          }
        }
        param_5[0x82] = **(int **)(param_3 + 6);
        goto LAB_400e360c;
      }
      if (param_2 == 0x106001c) {
        if (!bVar1) {
          pwVar6 = param_3 + 2;
          if ((pwVar6 == (wchar_t *)0x0) || (*pwVar6 == L'\0')) {
            pwVar6 = (wchar_t *)0x0;
          }
          if (((param_3 != (wchar_t *)0x0) && (0x21b < param_4)) &&
             (bVar2 = FUN_400e2468(*(int *)param_3,pwVar6), CONCAT31(extraout_var_00,bVar2) != 0)) {
            dwErrCode = 0;
          }
          goto LAB_400e360c;
        }
        goto LAB_400e326c;
      }
      if (param_2 != 0x1060020) {
        if (param_2 == 0x1060024) {
          if (((param_3 != (wchar_t *)0x0) && (param_7 != (int *)0x0)) && (3 < param_4)) {
            dwErrCode = 0;
            iVar3 = FUN_400e234c(*(int *)param_3,param_6,param_7,param_5);
            if (iVar3 == 0) {
              dwErrCode = GetLastError();
              if (dwErrCode == 0) {
                dwErrCode = 0x1f;
              }
            }
            else if (param_5 != (int *)0x0) {
              iVar3 = param_5[2];
              if (iVar3 != 0) {
                if (*(int *)(iVar3 + 0xc) != 0) {
                  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) - (int)param_5;
                }
                iVar3 = *(int *)(param_5[2] + 0x10);
                if (iVar3 != 0) {
                  *(int *)(param_5[2] + 0x10) = iVar3 - (int)param_5;
                }
                if (param_5[2] != 0) {
                  param_5[2] = param_5[2] - (int)param_5;
                }
              }
              iVar3 = param_5[3];
              if (iVar3 != 0) {
                if (*(int *)(iVar3 + 4) != 0) {
                  *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) - (int)param_5;
                }
                iVar3 = *(int *)(param_5[3] + 8);
                if (iVar3 != 0) {
                  *(int *)(param_5[3] + 8) = iVar3 - (int)param_5;
                }
                iVar3 = *(int *)(param_5[3] + 0xc);
                if (iVar3 != 0) {
                  *(int *)(param_5[3] + 0xc) = iVar3 - (int)param_5;
                }
                iVar3 = *(int *)(param_5[3] + 0x14);
                if (iVar3 != 0) {
                  *(int *)(param_5[3] + 0x14) = iVar3 - (int)param_5;
                }
                if (param_5[3] != 0) {
                  param_5[3] = param_5[3] - (int)param_5;
                }
              }
            }
          }
          goto LAB_400e360c;
        }
        if (param_2 != 0x1060028) goto LAB_400e360c;
        if (!bVar1) {
          if ((param_6 == 4) && (param_5 != (int *)0x0)) {
            iVar3 = FUN_400e2564();
            *param_5 = iVar3;
            return true;
          }
          goto LAB_400e3608;
        }
        goto LAB_400e326c;
      }
      dwErrCode = 0;
      iVar3 = FUN_400e2240((int)param_3,param_4 >> 2,param_7);
      if (iVar3 == 0) goto LAB_400e35ec;
      if ((param_3 == (wchar_t *)0x0) || (param_5 == (int *)0x0)) goto LAB_400e360c;
      DVar4 = CeSafeCopyMemory(param_5,param_3,(param_4 >> 2) << 2);
    }
    if (DVar4 != 0) goto LAB_400e360c;
  }
LAB_400e3608:
  dwErrCode = 0x57;
LAB_400e360c:
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* 400e365c FUN_400e365c */

/* Boundary evidence: original MIPS .pdata 400e365c..400e3667. Semantic name remains unreviewed. */

undefined4 FUN_400e365c(void)

{
  return 1;
}



/* 400e36b8 FUN_400e36b8 */

/* Boundary evidence: original MIPS .pdata 400e36b8..400e38cf. Semantic name remains unreviewed. */

void FUN_400e36b8(void *param_1,uint *param_2)

{
  LSTATUS LVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  DWORD local_248;
  HKEY local_244;
  DWORD local_240;
  int local_23c;
  BYTE aBStack_238 [518];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_400ea460;
  memset(param_1,-1,0x10);
  *param_2 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\GWE\\Notify",0,0x20019,&local_244);
  if (LVar1 == 0) {
    local_248 = 0x208;
    LVar1 = RegQueryValueExW(local_244,L"volume",(LPDWORD)0x0,&local_240,aBStack_238,&local_248);
    if (((LVar1 == 0) && (local_240 == 1)) && (local_248 < 0x208)) {
      uVar4 = DAT_400ea494 / 5000;
      local_32 = 0;
      if (uVar4 == 0) {
        uVar4 = 1;
      }
      iVar3 = 0;
      if (uVar4 != 0) {
        do {
          iVar2 = CeMountDBVol(param_1,aBStack_238,4);
          if (iVar2 != 0) {
            *param_2 = 1;
            local_23c = 0;
            local_248 = 4;
            LVar1 = RegQueryValueExW(local_244,L"flush",(LPDWORD)0x0,&local_240,(LPBYTE)&local_23c,
                                     &local_248);
            if (((LVar1 == 0) && (local_240 == 4)) && (local_248 == 4)) {
              *param_2 = (uint)(local_23c != 0);
            }
            break;
          }
          memset(param_1,-1,0x10);
          Sleep(5000);
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)uVar4);
      }
    }
    RegCloseKey(local_244);
  }
  FUN_400e8d68(local_30);
  return;
}



/* 400e38d0 FUN_400e38d0 */

/* Boundary evidence: original MIPS .pdata 400e38d0..400e3b63. Semantic name remains unreviewed. */

undefined4 FUN_400e38d0(int param_1)

{
  undefined *puVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  wchar_t awStack_a4 [35];
  undefined2 local_5e;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_30;
  
  local_30 = DAT_400ea460;
  puVar3 = (uint *)(param_1 + 0x54);
  FUN_400e36b8(puVar3,(uint *)(param_1 + 0x50));
  puVar1 = PTR_u_DB_notify_queue_400ea1d0;
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  iVar4 = 0;
  local_c0 = 0;
  iVar2 = CeOpenDatabaseEx(puVar3,&local_c0,puVar1,0x10040,0,0);
  while (*(int *)(param_1 + 0x30) = iVar2, iVar2 == -1) {
    if (0 < iVar4) goto LAB_400e3b54;
    local_b8 = 0x10040;
    local_b4 = 0;
    if ((*(uint *)(param_1 + 0x60) & *(uint *)(param_1 + 0x5c) & *(uint *)(param_1 + 0x58) & *puVar3
        ) == 0xffffffff) {
      local_c0 = CeCreateDatabase(PTR_u_DB_notify_queue_400ea1d0,0,1,&local_b8);
    }
    else {
      memset(&local_a8,0,0x78);
      local_a8 = 5;
      wcscpy(awStack_a4,(wchar_t *)PTR_u_DB_notify_queue_400ea1d0);
      local_5e = 1;
      local_50 = 0x10040;
      local_4c = 0;
      local_c0 = CeCreateDatabaseEx(puVar3,&local_a8);
    }
    iVar4 = iVar4 + 1;
    iVar2 = CeOpenDatabaseEx(puVar3,&local_c0,PTR_u_DB_notify_queue_400ea1d0,0x10040,0,0);
  }
  local_bc = 0;
  iVar4 = 0;
  iVar2 = CeOpenDatabaseEx(puVar3,&local_bc,PTR_u_DB_notify_events_400ea1d4,0x1001f,0,0);
  while( true ) {
    *(int *)(param_1 + 0x34) = iVar2;
    if (iVar2 != -1) {
      FUN_400e8d68(local_30);
      return 1;
    }
    if (0 < iVar4) break;
    local_b0 = 0x1001f;
    local_ac = 2;
    if ((*(uint *)(param_1 + 0x60) & *(uint *)(param_1 + 0x5c) & *(uint *)(param_1 + 0x58) & *puVar3
        ) == 0xffffffff) {
      local_bc = CeCreateDatabase(PTR_u_DB_notify_events_400ea1d4,0,1,&local_b0);
    }
    else {
      memset(&local_a8,0,0x78);
      local_a8 = 5;
      wcscpy(awStack_a4,(wchar_t *)PTR_u_DB_notify_events_400ea1d4);
      local_5e = 1;
      local_50 = 0x1001f;
      local_4c = 2;
      local_c0 = CeCreateDatabaseEx(puVar3,&local_a8);
    }
    iVar4 = iVar4 + 1;
    iVar2 = CeOpenDatabaseEx(puVar3,&local_bc,PTR_u_DB_notify_events_400ea1d4,0x1001f,0,0);
  }
  CloseHandle(*(HANDLE *)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
LAB_400e3b54:
  FUN_400e8d68(local_30);
  return 0;
}



/* 400e3b64 FUN_400e3b64 */

/* Boundary evidence: original MIPS .pdata 400e3b64..400e3bfb. Semantic name remains unreviewed. */

undefined4 FUN_400e3b64(int *param_1)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *param_1 = (int)pvVar1;
  uVar2 = 1;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  param_1[1] = (int)pvVar1;
  if ((*param_1 == 0) || (pvVar1 == (HANDLE)0x0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 400e3bfc FUN_400e3bfc */

/* Boundary evidence: original MIPS .pdata 400e3bfc..400e3c73. Semantic name remains unreviewed. */

void FUN_400e3bfc(int param_1)

{
  CloseHandle(*(HANDLE *)(param_1 + 0x30));
  CloseHandle(*(HANDLE *)(param_1 + 0x34));
  if ((*(uint *)(param_1 + 0x60) & *(uint *)(param_1 + 0x5c) & *(uint *)(param_1 + 0x58) &
      *(uint *)(param_1 + 0x54)) != 0xffffffff) {
    CeUnmountDBVol();
  }
  return;
}



/* 400e3c74 FUN_400e3c74 */

/* Boundary evidence: original MIPS .pdata 400e3c74..400e3cb7. Semantic name remains unreviewed. */

void FUN_400e3c74(undefined4 *param_1)

{
  CloseHandle((HANDLE)*param_1);
  CloseHandle((HANDLE)param_1[1]);
  return;
}



/* 400e3cb8 FUN_400e3cb8 */

/* Boundary evidence: original MIPS .pdata 400e3cb8..400e3d1f. Semantic name remains unreviewed. */

void FUN_400e3cb8(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x3c) != 0) {
    iVar1 = EventModify(*(undefined4 *)(param_1 + 4),3);
    if (iVar1 != 0) {
      WaitForSingleObject(*(HANDLE *)(param_1 + 0x3c),0xffffffff);
    }
    CloseHandle(*(HANDLE *)(param_1 + 0x3c));
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 400e3d20 FUN_400e3d20 */

/* Boundary evidence: original MIPS .pdata 400e3d20..400e3dbb. Semantic name remains unreviewed. */

void FUN_400e3d20(int param_1)

{
  int *hMem;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  while (*(int *)(param_1 + 0x40) != 0) {
    hMem = *(int **)(param_1 + 0x40);
    *(int *)(param_1 + 0x40) = *hMem;
    if (*hMem != 0) {
      *(int *)(*hMem + 4) = hMem[1];
    }
    hMem[1] = 0;
    *hMem = 0;
    if ((hMem[2] & 1U) == 0) {
      LocalFree(hMem);
    }
    else {
      FUN_400e868c((LPARAM)hMem);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return;
}



/* 400e3dbc FUN_400e3dbc */

/* Boundary evidence: original MIPS .pdata 400e3dbc..400e412b. Semantic name remains unreviewed. */

uint * FUN_400e3dbc(int param_1,uint *param_2,SIZE_T *param_3)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  size_t sVar4;
  size_t sVar5;
  uint *hMem;
  BOOL BVar6;
  LONG LVar7;
  SIZE_T uBytes;
  uint uVar8;
  size_t _Size;
  _FILETIME _Stack_30;
  
  if (*(wchar_t **)(param_1 + 0xc) == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = wcslen(*(wchar_t **)(param_1 + 0xc));
    sVar1 = (sVar1 + 1) * 2;
  }
  if (*(wchar_t **)(param_1 + 0x10) == (wchar_t *)0x0) {
    sVar2 = 0;
  }
  else {
    sVar2 = wcslen(*(wchar_t **)(param_1 + 0x10));
    sVar2 = (sVar2 + 1) * 2;
  }
  if (((param_2 == (uint *)0x0) || ((*param_2 & 4) == 0)) ||
     ((wchar_t *)param_2[2] == (wchar_t *)0x0)) {
    sVar3 = 0;
  }
  else {
    sVar3 = wcslen((wchar_t *)param_2[2]);
    sVar3 = (sVar3 + 1) * 2;
  }
  if (((param_2 == (uint *)0x0) || ((*param_2 & 4) == 0)) ||
     ((wchar_t *)param_2[1] == (wchar_t *)0x0)) {
    sVar4 = 0;
  }
  else {
    sVar4 = wcslen((wchar_t *)param_2[1]);
    sVar4 = (sVar4 + 1) * 2;
  }
  if (((param_2 == (uint *)0x0) || ((*param_2 & 8) == 0)) ||
     ((wchar_t *)param_2[3] == (wchar_t *)0x0)) {
    sVar5 = 0;
  }
  else {
    sVar5 = wcslen((wchar_t *)param_2[3]);
    sVar5 = (sVar5 + 1) * 2;
  }
  if ((param_2 == (uint *)0x0) || ((size_t *)param_2[5] == (size_t *)0x0)) {
    _Size = 0;
  }
  else {
    _Size = *(size_t *)param_2[5];
  }
  uBytes = _Size + sVar5 + sVar4 + sVar3 + sVar2 + sVar1 + 0x30;
  hMem = LocalAlloc(0x40,uBytes);
  if (hMem != (uint *)0x0) {
    if (param_2 == (uint *)0x0) {
      uVar8 = 0;
    }
    else {
      uVar8 = *param_2;
    }
    *hMem = uVar8;
    hMem[1] = *(uint *)(param_1 + 4);
    BVar6 = SystemTimeToFileTime((SYSTEMTIME *)(param_1 + 0x14),&_Stack_30);
    if (BVar6 != 0) {
      BVar6 = LocalFileTimeToFileTime(&_Stack_30,(LPFILETIME)(hMem + 2));
      if (BVar6 != 0) {
        if (*(int *)(param_1 + 4) != 3) {
          hMem[4] = 0;
          hMem[5] = 0;
LAB_400e4028:
          uVar8 = 0x30;
          if (sVar1 == 0) {
            hMem[6] = 0;
          }
          else {
            memcpy(hMem + 0xc,*(void **)(param_1 + 0xc),sVar1);
            hMem[6] = 0x30;
            uVar8 = sVar1 + 0x30;
          }
          if (sVar2 == 0) {
            hMem[7] = 0;
          }
          else {
            memcpy((void *)(uVar8 + (int)hMem),*(void **)(param_1 + 0x10),sVar2);
            hMem[7] = uVar8;
            uVar8 = uVar8 + sVar2;
          }
          if (sVar3 == 0) {
            hMem[9] = 0;
          }
          else {
            memcpy((void *)(uVar8 + (int)hMem),(void *)param_2[2],sVar3);
            hMem[9] = uVar8;
            uVar8 = uVar8 + sVar3;
          }
          if (sVar4 == 0) {
            hMem[8] = 0;
          }
          else {
            memcpy((void *)(uVar8 + (int)hMem),(void *)param_2[1],sVar4);
            hMem[8] = uVar8;
            uVar8 = uVar8 + sVar4;
          }
          if (sVar5 == 0) {
            hMem[10] = 0;
          }
          else {
            memcpy((void *)(uVar8 + (int)hMem),(void *)param_2[3],sVar5);
            hMem[10] = uVar8;
            uVar8 = uVar8 + sVar5;
          }
          if (_Size == 0) {
            hMem[0xb] = 0;
          }
          else {
            memcpy((void *)(uVar8 + (int)hMem),(void *)param_2[5],_Size);
            hMem[0xb] = uVar8;
          }
          *param_3 = uBytes;
          return hMem;
        }
        BVar6 = SystemTimeToFileTime((SYSTEMTIME *)(param_1 + 0x24),&_Stack_30);
        if (BVar6 != 0) {
          BVar6 = LocalFileTimeToFileTime(&_Stack_30,(LPFILETIME)(hMem + 4));
          if ((BVar6 != 0) &&
             (LVar7 = CompareFileTime((LPFILETIME)(hMem + 2),(LPFILETIME)(hMem + 4)), LVar7 < 0))
          goto LAB_400e4028;
        }
      }
    }
    LocalFree(hMem);
  }
  return (uint *)0x0;
}



/* 400e412c FUN_400e412c */

/* Boundary evidence: original MIPS .pdata 400e412c..400e42a7. Semantic name remains unreviewed. */

bool FUN_400e412c(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int *hMem;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 2);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = CeDeleteRecord(param_1[0xc],param_2);
  if ((iVar1 == 0) && (iVar1 = CeDeleteRecord(param_1[0xc],param_2), iVar1 == 0)) {
    LeaveCriticalSection(lpCriticalSection);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
    iVar1 = CeDeleteRecord(param_1[0xd],param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
    return iVar1 != 0;
  }
  hMem = (int *)param_1[0x10];
  if (hMem != (int *)0x0) {
    do {
      if (hMem[3] == param_2) break;
      hMem = (int *)*hMem;
    } while (hMem != (int *)0x0);
    if (hMem != (int *)0x0) {
      if ((int *)hMem[1] == (int *)0x0) {
        param_1[0x10] = *hMem;
      }
      else {
        *(int *)hMem[1] = *hMem;
      }
      if (*hMem != 0) {
        *(int *)(*hMem + 4) = hMem[1];
      }
      LeaveCriticalSection(lpCriticalSection);
      hMem[1] = 0;
      *hMem = 0;
      if ((hMem[2] & 1U) == 0) {
        LocalFree(hMem);
      }
      else {
        FUN_400e868c((LPARAM)hMem);
      }
      goto LAB_400e426c;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
LAB_400e426c:
  if (param_3 != 0) {
    EventModify(*param_1,3);
  }
  return true;
}



/* 400e42a8 FUN_400e42a8 */

/* Boundary evidence: original MIPS .pdata 400e42a8..400e432b. Semantic name remains unreviewed. */

undefined4 FUN_400e42a8(int param_1,wchar_t *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  piVar2 = *(int **)(param_1 + 0x40);
  do {
    if (piVar2 == (int *)0x0) {
      uVar3 = 0;
LAB_400e4300:
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
      return uVar3;
    }
    iVar1 = _wcsicmp((wchar_t *)piVar2[0xf],param_2);
    if (iVar1 == 0) {
      uVar3 = piVar2[3];
      goto LAB_400e4300;
    }
    piVar2 = (int *)*piVar2;
  } while( true );
}



/* 400e432c FUN_400e432c */

/* Boundary evidence: original MIPS .pdata 400e432c..400e43d7. Semantic name remains unreviewed. */

undefined4 FUN_400e432c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28 [2];
  undefined4 local_20 [2];
  undefined4 local_18;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  local_28[0] = 0;
  iVar1 = CeSeekDatabase(*(undefined4 *)(param_1 + 0x34),2,0,local_28);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    memset(local_20,0,0x10);
    local_20[0] = 0x1001f;
    local_18 = param_2;
    uVar2 = CeSeekDatabase(*(undefined4 *)(param_1 + 0x34),0x20,local_20,local_28);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return uVar2;
}



/* 400e43d8 FUN_400e43d8 */

undefined4 FUN_400e43d8(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
LAB_400e43e0:
    uVar1 = 1;
  }
  else {
    if (((param_1 & 1) == 0) && (0x2f < param_1)) {
      for (; (int)param_1 <= param_3 + -2; param_1 = param_1 + 2) {
        if ((*(char *)(param_1 + param_2) == '\0') && (*(char *)(param_1 + param_2 + 1) == '\0'))
        goto LAB_400e43e0;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 400e444c FUN_400e444c */

/* Boundary evidence: original MIPS .pdata 400e444c..400e46ff. Semantic name remains unreviewed. */

undefined4 * FUN_400e444c(undefined4 *param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 *_Dst;
  uint uVar2;
  void *_Dst_00;
  WCHAR *_Src;
  WCHAR aWStack_78 [40];
  uint local_28;
  
  local_28 = DAT_400ea460;
  _Src = (WCHAR *)0x0;
  iVar1 = FUN_400e43d8(*(uint *)((int)param_2 + 0x18),(int)param_2,param_3);
  if (((((iVar1 == 0) ||
        (iVar1 = FUN_400e43d8(*(uint *)((int)param_2 + 0x1c),(int)param_2,param_3), iVar1 == 0)) ||
       (iVar1 = FUN_400e43d8(*(uint *)((int)param_2 + 0x24),(int)param_2,param_3), iVar1 == 0)) ||
      ((iVar1 = FUN_400e43d8(*(uint *)((int)param_2 + 0x20),(int)param_2,param_3), iVar1 == 0 ||
       (iVar1 = FUN_400e43d8(*(uint *)((int)param_2 + 0x28),(int)param_2,param_3), iVar1 == 0)))) ||
     (iVar1 = FUN_400e43d8(*(uint *)((int)param_2 + 0x2c),(int)param_2,param_3), iVar1 == 0)) {
    FUN_400e412c(param_1,param_4,0);
  }
  else {
    iVar1 = 0x4e;
    if (*(int *)((int)param_2 + 4) == 4) {
      wsprintfW(aWStack_78,L"%s 0x%08x",L"AppRunToHandleNotification",param_4);
      _Src = aWStack_78;
    }
    else {
      iVar1 = 0;
    }
    uVar2 = param_3 + 0x24;
    if (((param_3 <= uVar2) && (uVar2 <= iVar1 + uVar2)) &&
       (_Dst = LocalAlloc(0x40,iVar1 + uVar2), _Dst != (undefined4 *)0x0)) {
      memset(_Dst,0,0x24);
      memcpy(_Dst + 9,param_2,param_3);
      _Dst[3] = param_4;
      *_Dst = param_1[0x10];
      if (param_1[0x10] != 0) {
        *(undefined4 **)(param_1[0x10] + 4) = _Dst;
      }
      param_1[0x10] = _Dst;
      _Dst_00 = (void *)0x0;
      if (_Src != (WCHAR *)0x0) {
        _Dst_00 = (void *)((int)_Dst + param_3 + 0x24);
        memcpy(_Dst_00,_Src,0x4e);
      }
      if (_Dst[0xf] == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (int)_Dst + _Dst[0xf] + 0x24;
      }
      _Dst[0xf] = iVar1;
      if (_Dst[0x10] != 0) {
        _Dst_00 = (void *)((int)_Dst + _Dst[0x10] + 0x24);
      }
      _Dst[0x10] = _Dst_00;
      if (_Dst[0x12] == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (int)_Dst + _Dst[0x12] + 0x24;
      }
      _Dst[0x12] = iVar1;
      if (_Dst[0x11] == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (int)_Dst + _Dst[0x11] + 0x24;
      }
      _Dst[0x11] = iVar1;
      if (_Dst[0x13] == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (int)_Dst + _Dst[0x13] + 0x24;
      }
      _Dst[0x13] = iVar1;
      if (_Dst[0x14] == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (int)_Dst + _Dst[0x14] + 0x24;
      }
      _Dst[0x14] = iVar1;
      _Dst[2] = (uint)(_Dst[9] != 0);
      FUN_400e8d68(local_28);
      return _Dst;
    }
  }
  FUN_400e8d68(local_28);
  return (undefined4 *)0x0;
}



/* 400e4700 FUN_400e4700 */

/* Boundary evidence: original MIPS .pdata 400e4700..400e4b0b. Semantic name remains unreviewed. */

void FUN_400e4700(undefined4 *param_1)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  LONG LVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  BOOL BVar8;
  undefined4 uVar9;
  _SYSTEMTIME *p_Var10;
  uint uVar11;
  int *piVar12;
  uint *puVar13;
  uint uVar14;
  void *pvVar15;
  ushort local_70 [2];
  HLOCAL local_6c;
  undefined4 local_68;
  undefined4 local_64;
  FILETIME local_60;
  _SYSTEMTIME _Stack_58;
  _SYSTEMTIME _Stack_48;
  FILETIME local_38;
  FILETIME local_30;
  _FILETIME local_28;
  
  bVar2 = false;
  GetSystemTime(&_Stack_58);
  SystemTimeToFileTime(&_Stack_58,&local_28);
  local_30.dwLowDateTime = param_1[0x19] + local_28.dwLowDateTime;
  local_30.dwHighDateTime = local_28.dwHighDateTime + (local_30.dwLowDateTime < (uint)param_1[0x19])
  ;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  if ((param_1[0x13] != 0) &&
     (LVar4 = CompareFileTime((FILETIME *)(param_1 + 0x11),&local_30), LVar4 < 1)) {
    FUN_400e86ec();
    param_1[0x13] = 0;
    if ((DAT_400ea498 != (code *)0x0) && (iVar5 = WaitForAPIReady(0x51,0), iVar5 == 0)) {
      (*DAT_400ea498)();
    }
  }
  local_68 = 0;
  iVar5 = CeSeekDatabase(param_1[0xc],2,0,&local_68);
  local_6c = (HLOCAL)0x0;
  local_64 = 0;
  if (iVar5 != 0) {
    do {
      piVar12 = (int *)param_1[0x10];
      if (piVar12 == (int *)0x0) {
LAB_400e4818:
        local_70[0] = 0;
        iVar6 = CeReadRecordProps(param_1[0xc],1,local_70,0,&local_6c,&local_64);
        if (iVar5 == iVar6) {
          uVar11 = (uint)local_70[0];
          pvVar15 = (void *)0x0;
          uVar14 = 0;
          bVar1 = false;
          if (uVar11 != 0) {
            puVar13 = (uint *)((int)local_6c + 8);
            do {
              if (puVar13[-2] == 0x10040) {
                local_60.dwLowDateTime = *puVar13;
                bVar1 = true;
                local_60.dwHighDateTime = puVar13[1];
              }
              else if (puVar13[-2] == 0x20041) {
                pvVar15 = (void *)puVar13[1];
                uVar14 = *puVar13;
              }
              uVar11 = uVar11 - 1;
              puVar13 = puVar13 + 4;
            } while (uVar11 != 0);
            if (((pvVar15 != (void *)0x0) && (bVar1)) && (0 < (int)uVar14)) {
              LVar4 = CompareFileTime(&local_60,&local_30);
              if (LVar4 < 1) {
                if (param_1[0x1b] != 0) {
                  puVar7 = FUN_400e444c(param_1,pvVar15,uVar14,iVar5);
                  if (((puVar7 != (undefined4 *)0x0) &&
                      (FUN_400e86bc(iVar5), DAT_400ea498 != (code *)0x0)) &&
                     (iVar5 = WaitForAPIReady(0x51,0), iVar5 == 0)) {
                    (*DAT_400ea498)();
                  }
                  goto LAB_400e4940;
                }
                local_38.dwLowDateTime = param_1[0x19] + local_30.dwLowDateTime;
                local_38.dwHighDateTime =
                     local_30.dwHighDateTime + (local_38.dwLowDateTime < (uint)param_1[0x19]);
              }
              else {
                local_38.dwLowDateTime = local_60.dwLowDateTime;
                local_38.dwHighDateTime = local_60.dwHighDateTime;
              }
              bVar2 = true;
              break;
            }
          }
        }
      }
      else {
        do {
          if (piVar12[3] == iVar5) break;
          piVar12 = (int *)*piVar12;
        } while (piVar12 != (int *)0x0);
        if (piVar12 == (int *)0x0) goto LAB_400e4818;
      }
LAB_400e4940:
      iVar5 = CeSeekDatabase(param_1[0xc],8,1,&local_68);
    } while (iVar5 != 0);
    if (local_6c != (HLOCAL)0x0) {
      LocalFree(local_6c);
    }
  }
  piVar12 = (int *)param_1[0x10];
  while (piVar3 = piVar12, piVar3 != (int *)0x0) {
    piVar12 = (int *)*piVar3;
    if (piVar3[10] == 3) {
      LVar4 = CompareFileTime(&local_28,(FILETIME *)(piVar3 + 0xd));
      if (LVar4 < 1) {
        local_60.dwLowDateTime = param_1[0x19] + ((FILETIME *)(piVar3 + 0xd))->dwLowDateTime;
        local_60.dwHighDateTime = piVar3[0xe] + (uint)(local_60.dwLowDateTime < (uint)param_1[0x19])
        ;
        if ((!bVar2) || (LVar4 = CompareFileTime(&local_38,&local_60), 0 < LVar4)) {
          bVar2 = true;
          local_38.dwLowDateTime = local_60.dwLowDateTime;
          local_38.dwHighDateTime = local_60.dwHighDateTime;
        }
      }
      else {
        FUN_400e412c(param_1,piVar3[3],0);
      }
    }
  }
  if ((param_1[0x13] != 0) &&
     ((!bVar2 || (LVar4 = CompareFileTime((FILETIME *)(param_1 + 0x11),&local_38), LVar4 < 0)))) {
    local_38.dwLowDateTime = param_1[0x11];
    local_38.dwHighDateTime = param_1[0x12];
    bVar2 = true;
  }
  if (bVar2) {
    BVar8 = FileTimeToLocalFileTime(&local_38,&local_60);
    if ((BVar8 == 0) || (BVar8 = FileTimeToSystemTime(&local_60,&_Stack_48), BVar8 == 0))
    goto LAB_400e4adc;
    uVar9 = *param_1;
    p_Var10 = &_Stack_48;
  }
  else {
    p_Var10 = &_Stack_58;
    uVar9 = 0;
  }
  SetKernelAlarm(uVar9,p_Var10);
LAB_400e4adc:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



/* 400e4b0c FUN_400e4b0c */

/* Boundary evidence: original MIPS .pdata 400e4b0c..400e4b73. Semantic name remains unreviewed. */

void FUN_400e4b0c(undefined4 *param_1)

{
  DWORD DVar1;
  HANDLE local_18;
  undefined4 local_14;
  
  local_18 = (HANDLE)*param_1;
  local_14 = param_1[1];
  while (DVar1 = WaitForMultipleObjects(2,&local_18,0,0xffffffff), DVar1 == 0) {
    FUN_400e4700(param_1);
  }
  return;
}



/* 400e4b74 FUN_400e4b74 */

/* Boundary evidence: original MIPS .pdata 400e4b74..400e4cf3. Semantic name remains unreviewed. */

undefined4 FUN_400e4b74(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_28 [2];
  
  local_28[0] = 0;
  if (param_2 == 0) {
    if (param_3 != 0) goto LAB_400e4bb4;
  }
  else if (param_3 < 1) goto LAB_400e4bb4;
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    iVar1 = CeSeekDatabase(*(undefined4 *)(param_1 + 0x30),2,0,local_28);
    while (iVar1 != 0) {
      if ((param_2 != 0) && (*param_4 < param_3)) {
        *(int *)(*param_4 * 4 + param_2) = iVar1;
      }
      *param_4 = *param_4 + 1;
      iVar1 = CeSeekDatabase(*(undefined4 *)(param_1 + 0x30),8,1,local_28);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
    uVar3 = 0;
    uVar2 = 2;
    while (iVar1 = CeSeekDatabase(*(undefined4 *)(param_1 + 0x34),uVar2,uVar3,local_28), iVar1 != 0)
    {
      if ((param_2 != 0) && (*param_4 < param_3)) {
        *(int *)(*param_4 * 4 + param_2) = iVar1;
      }
      *param_4 = *param_4 + 1;
      uVar3 = 1;
      uVar2 = 8;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
    return 1;
  }
LAB_400e4bb4:
  SetLastError(0x57);
  return 0;
}



/* 400e4cf4 FUN_400e4cf4 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 400e4cf4..400e53b3. Semantic name remains unreviewed. */

undefined4 FUN_400e4cf4(int param_1,int param_2,DWORD param_3,int *param_4,int *param_5)

{
  int iVar1;
  size_t sVar2;
  void *_Dst;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  wchar_t *_Dest;
  int *piVar6;
  undefined4 uVar7;
  wchar_t *pwVar8;
  wchar_t *_Str;
  LPCRITICAL_SECTION lpCriticalSection;
  ushort local_48 [2];
  int *local_44;
  undefined4 local_40;
  int local_3c [3];
  _FILETIME local_30;
  
  local_30.dwLowDateTime = param_3;
  if ((param_2 == 0) || (param_4 == (int *)0x0)) {
LAB_400e536c:
    SetLastError(0x57);
    return 0;
  }
  if (param_5 == (int *)0x0) {
    if (0 < (int)param_3) goto LAB_400e536c;
  }
  else if ((int)param_3 < 1) goto LAB_400e536c;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 8);
  *param_4 = 0;
  local_40 = 0;
  EnterCriticalSection(lpCriticalSection);
  iVar1 = CeSeekDatabase(*(undefined4 *)(param_1 + 0x30),1,param_2,&local_40);
  if (param_2 == iVar1) {
    local_44 = (int *)0x0;
    local_3c[0] = 0;
    local_48[0] = 0;
    uVar7 = 0;
    iVar1 = CeReadRecordProps(*(undefined4 *)(param_1 + 0x30),1,local_48,0,&local_44,local_3c);
    piVar4 = local_44;
    if (param_2 != iVar1) goto LAB_400e5188;
    uVar3 = (uint)local_48[0];
    piVar5 = (int *)0x0;
    piVar6 = local_44;
    if (uVar3 == 0) goto LAB_400e5188;
    do {
      if (*piVar6 == 0x20041) {
        piVar5 = (int *)piVar6[3];
      }
      uVar3 = uVar3 - 1;
      piVar6 = piVar6 + 4;
    } while (uVar3 != 0);
    if (piVar5 == (int *)0x0) goto LAB_400e5188;
    iVar1 = *param_4;
    *param_4 = iVar1 + 0x44;
    if (*piVar5 != 0) {
      *param_4 = iVar1 + 0x5c;
    }
    if (piVar5[6] != 0) {
      sVar2 = wcslen((wchar_t *)(piVar5[6] + (int)piVar5));
      *param_4 = (sVar2 + 1) * 2 + *param_4;
    }
    if (piVar5[7] != 0) {
      sVar2 = wcslen((wchar_t *)(piVar5[7] + (int)piVar5));
      *param_4 = (sVar2 + 1) * 2 + *param_4;
    }
    if (piVar5[9] != 0) {
      sVar2 = wcslen((wchar_t *)(piVar5[9] + (int)piVar5));
      *param_4 = (sVar2 + 1) * 2 + *param_4;
    }
    if (piVar5[8] != 0) {
      sVar2 = wcslen((wchar_t *)(piVar5[8] + (int)piVar5));
      *param_4 = (sVar2 + 1) * 2 + *param_4;
    }
    if (piVar5[10] != 0) {
      sVar2 = wcslen((wchar_t *)(piVar5[10] + (int)piVar5));
      *param_4 = (sVar2 + 1) * 2 + *param_4;
    }
    if (piVar5[0xb] != 0) {
      *param_4 = *(int *)(piVar5[0xb] + (int)piVar5) + *param_4 + 10;
    }
    if ((int)param_3 < *param_4) goto LAB_400e5188;
    piVar6 = param_5 + 0x11;
    if (*piVar5 == 0) {
      piVar6 = (int *)0x0;
    }
    pwVar8 = (wchar_t *)(piVar6 + 6);
    if (piVar6 == (int *)0x0) {
      pwVar8 = (wchar_t *)(param_5 + 0x11);
    }
    *param_5 = param_2;
    param_5[1] = 0;
    for (piVar4 = *(int **)(param_1 + 0x40); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      if (piVar4[3] == param_2) {
        param_5[1] = 1;
        break;
      }
    }
    param_5[2] = (int)(param_5 + 4);
    param_5[3] = (int)piVar6;
    param_5[4] = 0x34;
    param_5[5] = piVar5[1];
    param_5[6] = 0;
    if (piVar5[6] == 0) {
      param_5[7] = 0;
    }
    else {
      param_5[7] = (int)pwVar8;
      wcscpy(pwVar8,(wchar_t *)(piVar5[6] + (int)piVar5));
      sVar2 = wcslen(pwVar8);
      pwVar8 = pwVar8 + sVar2 + 1;
    }
    if (piVar5[7] == 0) {
      param_5[8] = 0;
    }
    else {
      param_5[8] = (int)pwVar8;
      wcscpy(pwVar8,(wchar_t *)(piVar5[7] + (int)piVar5));
      sVar2 = wcslen(pwVar8);
      pwVar8 = pwVar8 + sVar2 + 1;
    }
    FileTimeToLocalFileTime((FILETIME *)(piVar5 + 2),&local_30);
    FileTimeToSystemTime(&local_30,(LPSYSTEMTIME)(param_5 + 9));
    if (piVar5[1] == 3) {
      FileTimeToLocalFileTime((FILETIME *)(piVar5 + 4),&local_30);
      FileTimeToSystemTime(&local_30,(LPSYSTEMTIME)(param_5 + 0xd));
    }
    else {
      memset(param_5 + 0xd,0,0x10);
    }
    piVar4 = local_44;
    if (*piVar5 != 0) {
      *piVar6 = *piVar5;
      if (piVar5[9] == 0) {
        piVar6[2] = 0;
      }
      else {
        piVar6[2] = (int)pwVar8;
        wcscpy(pwVar8,(wchar_t *)(piVar5[9] + (int)piVar5));
        sVar2 = wcslen(pwVar8);
        pwVar8 = pwVar8 + sVar2 + 1;
      }
      if (piVar5[8] == 0) {
        piVar6[1] = 0;
      }
      else {
        piVar6[1] = (int)pwVar8;
        wcscpy(pwVar8,(wchar_t *)(piVar5[8] + (int)piVar5));
        sVar2 = wcslen(pwVar8);
        pwVar8 = pwVar8 + sVar2 + 1;
      }
      if (piVar5[10] == 0) {
        piVar6[3] = 0;
        piVar6[4] = 0;
      }
      else {
        piVar6[3] = (int)pwVar8;
        wcscpy(pwVar8,(wchar_t *)(piVar5[10] + (int)piVar5));
        sVar2 = wcslen(pwVar8);
        piVar6[4] = (sVar2 + 1) * 2;
        pwVar8 = pwVar8 + sVar2 + 1;
      }
      if (piVar5[0xb] == 0) {
        piVar6[5] = 0;
        piVar4 = local_44;
      }
      else {
        _Dst = (void *)((int)pwVar8 + 7U & 0xfffffff8);
        sVar2 = *(size_t *)(piVar5[0xb] + (int)piVar5);
        piVar6[5] = (int)_Dst;
        memcpy(_Dst,(void *)(piVar5[0xb] + (int)piVar5),sVar2);
        piVar4 = local_44;
      }
    }
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1c);
    EnterCriticalSection(lpCriticalSection);
    iVar1 = CeSeekDatabase(*(undefined4 *)(param_1 + 0x34),1,param_2,&local_40);
    if (param_2 != iVar1) {
      LeaveCriticalSection(lpCriticalSection);
      goto LAB_400e536c;
    }
    local_44 = (int *)0x0;
    local_3c[1] = 0;
    local_48[0] = 0;
    uVar7 = 0;
    iVar1 = CeReadRecordProps(*(undefined4 *)(param_1 + 0x34),1,local_48,0,&local_44,local_3c + 1);
    piVar4 = local_44;
    if (param_2 != iVar1) goto LAB_400e5188;
    uVar3 = (uint)local_48[0];
    _Str = (wchar_t *)0x0;
    local_3c[0] = 0;
    pwVar8 = (wchar_t *)0x0;
    piVar6 = local_44;
    if (uVar3 == 0) goto LAB_400e5188;
    do {
      iVar1 = *piVar6;
      if (iVar1 == 0x1001f) {
        _Str = (wchar_t *)piVar6[2];
      }
      else if (iVar1 == 0x2001f) {
        pwVar8 = (wchar_t *)piVar6[2];
      }
      else if (iVar1 == 0x30013) {
        local_3c[0] = piVar6[2];
      }
      uVar3 = uVar3 - 1;
      piVar6 = piVar6 + 4;
    } while (uVar3 != 0);
    if (_Str == (wchar_t *)0x0) goto LAB_400e5188;
    iVar1 = *param_4;
    *param_4 = iVar1 + 0x44;
    sVar2 = wcslen(_Str);
    iVar1 = (sVar2 + 1) * 2 + iVar1 + 0x44;
    *param_4 = iVar1;
    if (pwVar8 != (wchar_t *)0x0) {
      sVar2 = wcslen(pwVar8);
      *param_4 = (sVar2 + 1) * 2 + iVar1;
    }
    if ((int)local_30.dwLowDateTime < *param_4) goto LAB_400e5188;
    piVar6 = param_5 + 4;
    *param_5 = param_2;
    param_5[1] = 0;
    param_5[3] = 0;
    param_5[2] = (int)piVar6;
    _Dest = (wchar_t *)(param_5 + 0x11);
    memset(piVar6,0,0x34);
    *piVar6 = 0x34;
    param_5[5] = 1;
    param_5[6] = local_3c[0];
    param_5[7] = (int)_Dest;
    wcscpy(_Dest,_Str);
    sVar2 = wcslen(_Dest);
    if (pwVar8 != (wchar_t *)0x0) {
      param_5[8] = (int)(_Dest + sVar2 + 1);
      wcscpy(_Dest + sVar2 + 1,pwVar8);
      piVar4 = local_44;
    }
  }
  uVar7 = 1;
LAB_400e5188:
  if (piVar4 != (int *)0x0) {
    LocalFree(piVar4);
  }
  LeaveCriticalSection(lpCriticalSection);
  return uVar7;
}



/* 400e53b4 FUN_400e53b4 */

/* Boundary evidence: original MIPS .pdata 400e53b4..400e55bb. Semantic name remains unreviewed. */

undefined4 FUN_400e53b4(undefined4 *param_1,int param_2,uint param_3)

{
  uint uVar1;
  DWORD DVar2;
  DWORD DVar3;
  BOOL BVar4;
  LONG LVar5;
  int iVar6;
  int *hMem;
  undefined4 uVar7;
  LPCRITICAL_SECTION lpCriticalSection;
  _FILETIME local_48;
  undefined4 local_40 [2];
  uint local_38;
  DWORD local_34;
  _SYSTEMTIME _Stack_30;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 2);
  EnterCriticalSection(lpCriticalSection);
  for (hMem = (int *)param_1[0x10]; hMem != (int *)0x0; hMem = (int *)*hMem) {
    if (hMem[3] == param_2) goto LAB_400e5414;
  }
  hMem = (int *)0x0;
LAB_400e5414:
  if (hMem != (int *)0x0) {
    GetSystemTime(&_Stack_30);
    BVar4 = SystemTimeToFileTime(&_Stack_30,&local_48);
    if (BVar4 != 0) {
      uVar1 = (uint)((ulonglong)param_3 * 10000000);
      local_48.dwLowDateTime = uVar1 + local_48.dwLowDateTime;
      local_48.dwHighDateTime =
           ((int)param_3 >> 0x1f) * 10000000 + (int)((ulonglong)param_3 * 10000000 >> 0x20) +
           local_48.dwHighDateTime + (uint)(local_48.dwLowDateTime < uVar1);
      if ((hMem[10] != 3) ||
         (LVar5 = CompareFileTime(&local_48,(FILETIME *)(hMem + 0xd)), LVar5 < 1)) {
        DVar3 = local_48.dwHighDateTime;
        DVar2 = local_48.dwLowDateTime;
        memset(local_40,0,0x10);
        local_40[0] = 0x10040;
        uVar7 = 1;
        local_38 = DVar2;
        local_34 = DVar3;
        iVar6 = CeWriteRecordProps(param_1[0xc],param_2,1,local_40);
        if (iVar6 == 0) {
          uVar7 = 0;
        }
        else {
          if (param_1[0x14] != 0) {
            CeFlushDBVol(param_1 + 0x15);
          }
          if ((int *)hMem[1] == (int *)0x0) {
            param_1[0x10] = *hMem;
          }
          else {
            *(int *)hMem[1] = *hMem;
          }
          if (*hMem != 0) {
            *(int *)(*hMem + 4) = hMem[1];
          }
          hMem[1] = 0;
          *hMem = 0;
          if ((hMem[2] & 1U) == 0) {
            LocalFree(hMem);
          }
          else {
            FUN_400e868c((LPARAM)hMem);
          }
          FUN_400e4700(param_1);
        }
        LeaveCriticalSection(lpCriticalSection);
        return uVar7;
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 400e55bc FUN_400e55bc */

/* Boundary evidence: original MIPS .pdata 400e55bc..400e55ff. Semantic name remains unreviewed. */

undefined4 FUN_400e55bc(undefined4 *param_1)

{
  CeSetThreadPriority(0x41,DAT_400ea1dc);
  FUN_400e4b0c(param_1);
  return 0;
}



/* 400e5600 FUN_400e5600 */

/* Boundary evidence: original MIPS .pdata 400e5600..400e5873. Semantic name remains unreviewed. */

int FUN_400e5600(undefined4 *param_1,wchar_t *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  wchar_t *_Str2;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  wchar_t *_Str1;
  int iVar9;
  ushort local_30 [2];
  undefined4 local_2c;
  HLOCAL local_28;
  undefined4 local_24;
  
  iVar9 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  local_2c = 0;
  iVar2 = CeSeekDatabase(param_1[0xc],2,0,&local_2c);
  local_28 = (HLOCAL)0x0;
  local_24 = 0;
  if (iVar2 != 0) {
    do {
      local_30[0] = 0;
      iVar3 = CeReadRecordProps(param_1[0xc],1,local_30,0,&local_28,&local_24);
      if (iVar2 == iVar3) {
        uVar6 = (uint)local_30[0];
        piVar7 = (int *)0x0;
        iVar3 = 0;
        bVar1 = false;
        if (uVar6 == 0) goto LAB_400e57fc;
        piVar8 = (int *)((int)local_28 + 8);
        do {
          if (piVar8[-2] == 0x10040) {
            bVar1 = true;
          }
          else if (piVar8[-2] == 0x20041) {
            piVar7 = (int *)piVar8[1];
            iVar3 = *piVar8;
          }
          uVar6 = uVar6 - 1;
          piVar8 = piVar8 + 4;
        } while (uVar6 != 0);
        if (((piVar7 == (int *)0x0) || (!bVar1)) || (iVar3 < 1)) goto LAB_400e57fc;
        _Str2 = (wchar_t *)(piVar7[6] + (int)piVar7);
        if (piVar7[6] == 0) {
          _Str2 = (wchar_t *)0x0;
        }
        _Str1 = (wchar_t *)(piVar7[7] + (int)piVar7);
        if (piVar7[7] == 0) {
          _Str1 = (wchar_t *)0x0;
        }
        if (((*piVar7 != 0) || (_Str2 == (wchar_t *)0x0)) ||
           ((_Str1 == (wchar_t *)0x0 ||
            ((iVar3 = _wcsicmp(param_2,_Str2), iVar3 != 0 ||
             (iVar3 = _wcsicmp(_Str1,L"AppRunAtTime"), iVar3 != 0)))))) goto LAB_400e57fc;
        CeDeleteRecord(param_1[0xc],iVar2);
        piVar7 = (int *)param_1[0x10];
        if (piVar7 != (int *)0x0) {
          do {
            if (piVar7[3] == iVar2) break;
            piVar7 = (int *)*piVar7;
          } while (piVar7 != (int *)0x0);
          if (piVar7 != (int *)0x0) {
            if ((int *)piVar7[1] == (int *)0x0) {
              param_1[0x10] = *piVar7;
            }
            else {
              *(int *)piVar7[1] = *piVar7;
            }
            if (*piVar7 != 0) {
              *(int *)(*piVar7 + 4) = piVar7[1];
            }
            piVar7[1] = 0;
            *piVar7 = 0;
            LocalFree(piVar7);
          }
        }
        iVar9 = iVar9 + 1;
        uVar4 = 2;
        uVar5 = local_2c;
      }
      else {
LAB_400e57fc:
        uVar5 = 1;
        uVar4 = 8;
      }
      iVar2 = CeSeekDatabase(param_1[0xc],uVar4,uVar5,&local_2c);
    } while (iVar2 != 0);
    if (local_28 != (HLOCAL)0x0) {
      LocalFree(local_28);
    }
    if (0 < iVar9) {
      FUN_400e4700(param_1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  return iVar9;
}



/* 400e5874 FUN_400e5874 */

/* Boundary evidence: original MIPS .pdata 400e5874..400e58cf. Semantic name remains unreviewed. */

bool FUN_400e5874(LPVOID param_1)

{
  HANDLE pvVar1;
  DWORD local_10 [2];
  
  local_10[0] = 0;
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_400e55bc,param_1,0,local_10);
  *(HANDLE *)((int)param_1 + 0x3c) = pvVar1;
  return pvVar1 != (HANDLE)0x0;
}



/* 400e58d0 FUN_400e58d0 */

/* Boundary evidence: original MIPS .pdata 400e58d0..400e5baf. Semantic name remains unreviewed. */

int FUN_400e58d0(undefined4 *param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  uint *hMem;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar3;
  SIZE_T local_78 [2];
  undefined4 local_70 [2];
  uint local_68;
  uint local_64;
  undefined4 local_60;
  SIZE_T local_58;
  uint *local_54;
  int local_50 [4];
  undefined4 local_40;
  int local_38;
  
  if ((param_3 == (int *)0x0) || (*param_3 != 0x34)) goto LAB_400e5b7c;
  iVar2 = param_3[1];
  iVar3 = 1;
  if (iVar2 != 1) {
    if (((iVar2 != 2) && (iVar2 != 3)) && (iVar2 != 4)) goto LAB_400e5b7c;
    if (iVar2 != 1) {
      if ((((iVar2 != 4) || ((param_3[4] == 0 && (param_3[3] != 0)))) &&
          ((param_3[3] != 0 ||
           (((param_3[4] == 0 && (param_4 != (uint *)0x0)) && ((*param_4 & 4) != 0)))))) &&
         ((param_4 == (uint *)0x0 || (iVar2 = FUN_400e8628(param_4), iVar2 != 0)))) {
        local_78[0] = 0;
        hMem = FUN_400e3dbc((int)param_3,param_4,local_78);
        if (hMem == (uint *)0x0) goto LAB_400e5b7c;
        memset(local_70,0,0x20);
        local_70[0] = 0x10040;
        local_68 = hMem[2];
        local_64 = hMem[3];
        local_60 = 0x20041;
        lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 2);
        local_58 = local_78[0];
        local_54 = hMem;
        EnterCriticalSection(lpCriticalSection);
        iVar2 = CeWriteRecordProps(param_1[0xc],param_2,2,local_70);
        LocalFree(hMem);
        if (iVar2 == 0) {
          LeaveCriticalSection(lpCriticalSection);
          return 0;
        }
        if (param_1[0x14] != 0) {
          CeFlushDBVol(param_1 + 0x15);
        }
        FUN_400e4700(param_1);
        goto LAB_400e5b64;
      }
      goto LAB_400e5b7c;
    }
  }
  memset(local_50,0,0x30);
  if (((param_3[3] != 0) && (param_4 == (uint *)0x0)) &&
     (bVar1 = FUN_400e8610(param_3[2]), CONCAT31(extraout_var,bVar1) != 0)) {
    local_50[0] = 0x1001f;
    local_50[2] = param_3[3];
    if (param_3[4] != 0) {
      iVar3 = 2;
      local_40 = 0x2001f;
      local_38 = param_3[4];
    }
    local_50[iVar3 * 4] = 0x30013;
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 7);
    local_50[iVar3 * 4 + 2] = param_3[2];
    EnterCriticalSection(lpCriticalSection);
    iVar2 = CeWriteRecordProps(param_1[0xd],param_2,iVar3 + 1,local_50);
    if ((iVar2 != 0) && (param_1[0x14] != 0)) {
      CeFlushDBVol(param_1 + 0x15);
    }
LAB_400e5b64:
    LeaveCriticalSection(lpCriticalSection);
    return iVar2;
  }
LAB_400e5b7c:
  SetLastError(0x57);
  return 0;
}



/* 400e5bb0 FUN_400e5bb0 */

/* Boundary evidence: original MIPS .pdata 400e5bb0..400e5e4b. Semantic name remains unreviewed. */

byte FUN_400e5bb0(undefined4 *param_1,int param_2,wchar_t *param_3)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  wchar_t *_Dst;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  wchar_t *_Str;
  byte bVar8;
  LPCRITICAL_SECTION lpCriticalSection;
  ushort local_78 [2];
  int *local_74;
  undefined4 local_70;
  undefined4 local_6c;
  LPCRITICAL_SECTION local_68;
  int local_60 [3];
  int local_54;
  wchar_t *local_50;
  _SYSTEMTIME a_Stack_4c [2];
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 7);
  local_68 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  if ((param_2 == 1) || (param_2 == 0xc)) {
    EventModify(*param_1,3);
  }
  local_70 = 0;
  iVar1 = CeSeekDatabase(param_1[0xd],2,0,&local_70);
  bVar8 = 0;
  local_74 = (int *)0x0;
  local_6c = 0;
  if (iVar1 != 0) {
    do {
      local_78[0] = 0;
      iVar1 = CeReadRecordProps(param_1[0xd],1,local_78,0,&local_74,&local_6c);
      if (iVar1 != 0) {
        iVar1 = 0;
        _Str = (wchar_t *)0x0;
        iVar7 = 0;
        piVar5 = local_74;
        for (uVar4 = (uint)local_78[0]; uVar4 != 0; uVar4 = uVar4 - 1) {
          iVar6 = *piVar5;
          if (iVar6 == 0x1001f) {
            iVar1 = piVar5[2];
          }
          else if (iVar6 == 0x2001f) {
            _Str = (wchar_t *)piVar5[2];
          }
          else if (iVar6 == 0x30013) {
            iVar7 = piVar5[2];
          }
          piVar5 = piVar5 + 4;
        }
        if (iVar7 == param_2) {
          _Dst = param_3;
          if ((_Str != (wchar_t *)0x0) && (_Dst = _Str, param_3 != (wchar_t *)0x0)) {
            sVar2 = wcslen(param_3);
            sVar3 = wcslen(_Str);
            _Dst = LocalAlloc(0x40,(sVar3 + sVar2 + 1 + 1) * 2);
            if (_Dst == (wchar_t *)0x0) break;
            memcpy(_Dst,_Str,sVar3 * 2);
            _Dst[sVar3] = L' ';
            memcpy(_Dst + sVar3 + 1,param_3,(sVar2 + 1) * 2);
          }
          memset(local_60,0,0x34);
          local_60[0] = 0x34;
          local_60[1] = 2;
          local_54 = iVar1;
          local_50 = _Dst;
          GetLocalTime(a_Stack_4c);
          iVar1 = FUN_400e58d0(param_1,0,local_60,(uint *)0x0);
          bVar8 = iVar1 != 0 | bVar8;
          if ((_Dst != param_3) && (_Dst != _Str)) {
            LocalFree(_Dst);
          }
        }
      }
      iVar1 = CeSeekDatabase(param_1[0xd],8,1,&local_70);
    } while (iVar1 != 0);
    lpCriticalSection = local_68;
    if (local_74 != (int *)0x0) {
      LocalFree(local_74);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return bVar8;
}



/* 400e5e4c FUN_400e5e4c */

/* Boundary evidence: original MIPS .pdata 400e5e4c..400e5ebb. Semantic name remains unreviewed. */

void FUN_400e5e4c(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x38) != 0) {
    iVar1 = EventModify(*(undefined4 *)(param_1 + 4),3);
    if (iVar1 != 0) {
      WaitForSingleObject(*(HANDLE *)(param_1 + 0x38),0xffffffff);
    }
    CloseHandle(*(HANDLE *)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  FUN_400e8718();
  return;
}



/* 400e5ebc FUN_400e5ebc */

/* Boundary evidence: original MIPS .pdata 400e5ebc..400e6127. Semantic name remains unreviewed. */

int FUN_400e5ebc(LPVOID param_1)

{
  ATOM AVar1;
  HANDLE hObject;
  DWORD DVar2;
  undefined2 extraout_var;
  int iVar3;
  HWND hWnd;
  LONG LVar4;
  BOOL BVar5;
  HANDLE local_68;
  undefined4 local_64;
  tagMSG local_60;
  WNDCLASSW WStack_40;
  
  CeSetThreadPriority(0x41,DAT_400ea1d8);
  hObject = OpenEventW(0x1f0003,0,L"SYSTEM/GweApiSetReady");
  if (hObject != (HANDLE)0x0) {
    local_64 = *(undefined4 *)((int)param_1 + 4);
    local_68 = hObject;
    DVar2 = WaitForMultipleObjects(2,&local_68,0,0xffffffff);
    CloseHandle(hObject);
    if (DVar2 == 0) {
      memset(&WStack_40,0,0x28);
      WStack_40.lpfnWndProc = FUN_400e819c;
      WStack_40.hInstance = *(HINSTANCE *)((int)param_1 + 0x70);
      WStack_40.lpszClassName = (LPCWSTR)PTR_u_WinCENotify_400ea1e0;
      AVar1 = RegisterClassW(&WStack_40);
      if (CONCAT22(extraout_var,AVar1) != 0) {
        DAT_400ea49c = CreateWindowExW(0,(LPCWSTR)PTR_u_WinCENotify_400ea1e0,
                                       (LPCWSTR)PTR_u_WinCENotify_400ea1e0,0x8000000,-0x80000000,
                                       -0x80000000,-0x80000000,-0x80000000,(HWND)0x0,(HMENU)0x0,
                                       *(HINSTANCE *)((int)param_1 + 0x70),param_1);
        if (DAT_400ea49c != (HWND)0x0) {
          iVar3 = FUN_400e8530(*(HMODULE *)((int)param_1 + 0x70),DAT_400ea49c);
          if (iVar3 != 0) {
            *(undefined4 *)((int)param_1 + 0x6c) = 1;
LAB_400e60e0:
            while( true ) {
              BVar5 = GetMessageW(&local_60,(HWND)0x0,0,0);
              if (BVar5 == 0) {
                UnregisterClassW((LPCWSTR)PTR_u_WinCENotify_400ea1e0,
                                 *(HINSTANCE *)((int)param_1 + 0x70));
                return local_60.wParam;
              }
              if ((local_60.message != 0x218) || (local_60.wParam != 7)) break;
              FUN_400e2468(0xb,(wchar_t *)0x0);
            }
            hWnd = GetParent(local_60.hwnd);
            if (hWnd != (HWND)0x0) goto LAB_400e6084;
            goto LAB_400e60d0;
          }
          DestroyWindow(DAT_400ea49c);
        }
        UnregisterClassW((LPCWSTR)PTR_u_WinCENotify_400ea1e0,*(HINSTANCE *)((int)param_1 + 0x70));
      }
    }
  }
  return 0;
LAB_400e6084:
  do {
    LVar4 = GetWindowLongW(hWnd,-0x15);
    if (LVar4 == 0x53565320) break;
    hWnd = GetParent(hWnd);
  } while (hWnd != (HWND)0x0);
  if ((hWnd == (HWND)0x0) || (BVar5 = IsDialogMessageW(hWnd,&local_60), BVar5 == 0)) {
LAB_400e60d0:
    TranslateMessage(&local_60);
    DispatchMessageW(&local_60);
  }
  goto LAB_400e60e0;
}



/* 400e6128 FUN_400e6128 */

/* Boundary evidence: original MIPS .pdata 400e6128..400e618b. Semantic name remains unreviewed. */

undefined4 FUN_400e6128(LPVOID param_1)

{
  int iVar1;
  HANDLE pvVar2;
  
  iVar1 = NFY_Close();
  if (iVar1 != 0) {
    pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_400e5ebc,param_1,0,
                          (LPDWORD)((int)param_1 + 0x74));
    *(HANDLE *)((int)param_1 + 0x38) = pvVar2;
    if (pvVar2 != (HANDLE)0x0) {
      return 1;
    }
  }
  return 0;
}



/* 400e61bc FUN_400e61bc */

/* Boundary evidence: original MIPS .pdata 400e61bc..400e6257. Semantic name remains unreviewed. */

void FUN_400e61bc(void)

{
  HMODULE pHVar1;
  
  pHVar1 = LoadLibraryW(L"coredll.dll");
  if (pHVar1 != (HMODULE)0x0) {
    DAT_400ea4c8 = GetProcAddressW(pHVar1,L"sndPlaySoundW");
    DAT_400ea4cc = GetProcAddressW(pHVar1,L"waveOutSetVolume");
    DAT_400ea4d0 = GetProcAddressW(pHVar1,L"waveOutGetVolume");
  }
  DAT_400ea4c4 = 1;
  return;
}



/* 400e6258 FUN_400e6258 */

/* Boundary evidence: original MIPS .pdata 400e6258..400e62c7. Semantic name remains unreviewed. */

undefined4 FUN_400e6258(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (DAT_400ea4c4 == 0) {
    FUN_400e61bc();
  }
  if (DAT_400ea4cc == (code *)0x0) {
    uVar1 = 8;
  }
  else {
    uVar1 = (*DAT_400ea4cc)(param_1,param_2);
  }
  return uVar1;
}



/* 400e62c8 FUN_400e62c8 */

/* Boundary evidence: original MIPS .pdata 400e62c8..400e6337. Semantic name remains unreviewed. */

undefined4 FUN_400e62c8(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (DAT_400ea4c4 == 0) {
    FUN_400e61bc();
  }
  if (DAT_400ea4d0 == (code *)0x0) {
    uVar1 = 8;
  }
  else {
    uVar1 = (*DAT_400ea4d0)(param_1,param_2);
  }
  return uVar1;
}



/* 400e6338 FUN_400e6338 */

/* Boundary evidence: original MIPS .pdata 400e6338..400e63a7. Semantic name remains unreviewed. */

undefined4 FUN_400e6338(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (DAT_400ea4c4 == 0) {
    FUN_400e61bc();
  }
  if (DAT_400ea4c8 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_400ea4c8)(param_1,param_2);
  }
  return uVar1;
}



/* 400e63a8 FUN_400e63a8 */

/* Boundary evidence: original MIPS .pdata 400e63a8..400e641b. Semantic name remains unreviewed. */

HLOCAL FUN_400e63a8(wchar_t *param_1)

{
  size_t sVar1;
  HLOCAL _Dst;
  SIZE_T uBytes;
  
  sVar1 = wcslen(param_1);
  uBytes = (sVar1 + 1) * 2;
  _Dst = LocalAlloc(0x40,uBytes);
  if (_Dst == (HLOCAL)0x0) {
    _Dst = (HLOCAL)0x0;
  }
  else {
    memcpy(_Dst,param_1,uBytes);
  }
  return _Dst;
}



/* 400e641c FUN_400e641c */

/* Boundary evidence: original MIPS .pdata 400e641c..400e64d7. Semantic name remains unreviewed. */

undefined4 FUN_400e641c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    if (DAT_400ea4d4 != 0) {
      if (DAT_400ea4d4 == 1) {
LAB_400e6484:
        uVar2 = (*(code *)&SUB_fffe67ea)(param_1,param_2,0x98);
      }
      else {
LAB_400e64b0:
        DAT_400ea4d4 = 2;
        uVar2 = 0;
      }
      return uVar2;
    }
    if (3 < iVar3) goto LAB_400e64b0;
    iVar1 = WaitForAPIReady(0x55,1000);
    if (iVar1 == 0) {
      DAT_400ea4d4 = 1;
      goto LAB_400e6484;
    }
    iVar3 = iVar3 + 1;
  } while( true );
}



/* 400e64d8 FUN_400e64d8 */

/* Boundary evidence: original MIPS .pdata 400e64d8..400e666b. Semantic name remains unreviewed. */

BOOL FUN_400e64d8(int param_1)

{
  int iVar1;
  HANDLE hObject;
  int iVar2;
  BOOL BVar3;
  int *piVar4;
  _PROCESS_INFORMATION local_28;
  
  piVar4 = (int *)(param_1 + 0x10);
  iVar1 = _wcsnicmp((wchar_t *)*piVar4,L"\\\\.\\Notifications\\NamedEvents\\",0x1e);
  if (iVar1 == 0) {
    hObject = OpenEventW(0x1f0003,0,(LPCWSTR)(*piVar4 + 0x3c));
    if (hObject == (HANDLE)0x0) {
      BVar3 = 0;
    }
    else {
      EventModify(hObject,3);
      CloseHandle(hObject);
      BVar3 = 1;
    }
  }
  else {
    iVar1 = 0;
    while (DAT_400ea4d4 == 0) {
      if (3 < iVar1) goto LAB_400e65e0;
      iVar2 = WaitForAPIReady(0x55,1000);
      if (iVar2 == 0) {
        DAT_400ea4d4 = 1;
        goto LAB_400e65bc;
      }
      iVar1 = iVar1 + 1;
    }
    if (DAT_400ea4d4 == 1) {
LAB_400e65bc:
      BVar3 = ShellExecuteEx(param_1);
    }
    else {
LAB_400e65e0:
      DAT_400ea4d4 = 2;
      BVar3 = CreateProcessW((LPCWSTR)*piVar4,*(LPWSTR *)(param_1 + 0x14),(LPSECURITY_ATTRIBUTES)0x0
                             ,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                             (LPSTARTUPINFOW)0x0,&local_28);
      if (BVar3 != 0) {
        CloseHandle(local_28.hProcess);
        CloseHandle(local_28.hThread);
      }
    }
  }
  return BVar3;
}



/* 400e666c FUN_400e666c */

/* Boundary evidence: original MIPS .pdata 400e666c..400e673f. Semantic name remains unreviewed. */

void FUN_400e666c(HWND param_1)

{
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  GetWindowRect(param_1,&local_28);
  SystemParametersInfoW(0x30,0,&local_18,0);
  local_10 = ((local_28.left - local_28.right) - local_18) + local_10;
  if (local_10 < 0) {
    local_10 = local_10 + 1;
  }
  local_10 = local_10 >> 1;
  local_c = ((local_28.top - local_28.bottom) - local_14) + local_c;
  if (local_c < 0) {
    local_c = local_c + 1;
  }
  local_c = local_c >> 1;
  if (local_10 < 0) {
    local_10 = 0;
  }
  if (local_c < 0) {
    local_c = 0;
  }
  SetWindowPos(param_1,(HWND)0x0,local_18 + local_10,local_14 + local_c,0,0,5);
  return;
}



/* 400e6740 FUN_400e6740 */

/* Boundary evidence: original MIPS .pdata 400e6740..400e6f03. Semantic name remains unreviewed. */

BOOL FUN_400e6740(HWND param_1,int param_2,uint param_3,HWND param_4)

{
  undefined4 *puVar1;
  WPARAM WVar2;
  LRESULT LVar3;
  wchar_t *_Dest;
  int iVar4;
  HWND pHVar5;
  HANDLE hFindFile;
  LPCWSTR lpsz;
  BOOL BVar6;
  WCHAR WVar7;
  uint uVar8;
  LPCWSTR pWVar9;
  LPCWSTR pWVar10;
  BOOL BVar11;
  WCHAR local_238 [260];
  uint local_30;
  
  local_30 = DAT_400ea460;
  puVar1 = (undefined4 *)GetWindowLongW(param_1,8);
  if (param_2 == 2) {
    if ((puVar1 != (undefined4 *)0x0) && ((HICON)puVar1[10] != (HICON)0x0)) {
      DestroyIcon((HICON)puVar1[10]);
    }
    PostMessageW(param_1,0,0,0);
LAB_400e6ec8:
    FUN_400e8d68(local_30);
    return 1;
  }
  if (param_2 == 0x10) {
LAB_400e6950:
    BVar11 = EndDialog(param_1,0);
    goto LAB_400e6e4c;
  }
  if (param_2 == 0x53) {
    CreateProcessW(L"peghelp.exe",L"file:ctpnl.htm#set_an_alarm",(LPSECURITY_ATTRIBUTES)0x0,
                   (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,
                   (LPPROCESS_INFORMATION)0x0);
    goto LAB_400e6ec8;
  }
  if (param_2 != 0x110) {
    if (param_2 != 0x111) {
LAB_400e6ae8:
      FUN_400e8d68(local_30);
      return 0;
    }
    uVar8 = param_3 & 0xffff;
    BVar11 = 1;
    if (uVar8 == 1) {
      puVar1[0xb] = 1;
      *(undefined4 *)*puVar1 = 0;
      pHVar5 = GetDlgItem(param_1,0x2013);
      LVar3 = SendMessageW(pHVar5,0xf0,0,0);
      if (LVar3 != 0) {
        *(uint *)*puVar1 = *(uint *)*puVar1 | 4;
      }
      pHVar5 = GetDlgItem(param_1,0x2014);
      LVar3 = SendMessageW(pHVar5,0xf0,0,0);
      if (LVar3 != 0) {
        *(uint *)*puVar1 = *(uint *)*puVar1 | 1;
      }
      pHVar5 = GetDlgItem(param_1,0x2016);
      LVar3 = SendMessageW(pHVar5,0xf0,0,0);
      if (LVar3 != 0) {
        *(uint *)*puVar1 = *(uint *)*puVar1 | 2;
      }
      pHVar5 = GetDlgItem(param_1,0x2012);
      LVar3 = SendMessageW(pHVar5,0xf0,0,0);
      if (LVar3 != 0) {
        *(uint *)*puVar1 = *(uint *)*puVar1 | 0x10;
      }
      pHVar5 = GetDlgItem(param_1,0x2011);
      LVar3 = SendMessageW(pHVar5,0xf0,0,0);
      if (LVar3 != 0) {
        *(uint *)*puVar1 = *(uint *)*puVar1 | 8;
        pHVar5 = GetDlgItem(param_1,0x2015);
        WVar2 = SendMessageW(pHVar5,0x147,0,0);
        pHVar5 = GetDlgItem(param_1,0x2015);
        SendMessageW(pHVar5,0x148,WVar2,puVar1[1]);
      }
      PostMessageW(param_1,0x10,0,0);
      goto LAB_400e6e4c;
    }
    if (uVar8 != 2) {
      if (uVar8 == 0x2011) {
        pHVar5 = GetDlgItem(param_1,0x2011);
        LVar3 = SendMessageW(pHVar5,0xf0,0,0);
        pHVar5 = GetDlgItem(param_1,0x2015);
        EnableWindow(pHVar5,LVar3);
        pHVar5 = GetDlgItem(param_1,0x2012);
        EnableWindow(pHVar5,LVar3);
      }
      else {
        if (uVar8 != 0x2015) goto LAB_400e6ae8;
        if (param_3 >> 0x10 == 1) {
          WVar2 = SendMessageW(param_4,0x147,0,0);
          LVar3 = SendMessageW(param_4,0x149,WVar2,0);
          _Dest = LocalAlloc(0x40,(LVar3 + 10) * 2);
          if (_Dest != (wchar_t *)0x0) {
            SendMessageW(param_4,0x148,WVar2,(LPARAM)_Dest);
            iVar4 = FUN_400e6338(_Dest,0x20001);
            if (iVar4 == 0) {
              wcscpy(_Dest,L"Default");
              pHVar5 = GetDlgItem(param_1,0x2015);
              WVar2 = SendMessageW(pHVar5,0x14c,0,(LPARAM)_Dest);
              pHVar5 = GetDlgItem(param_1,0x2015);
              SendMessageW(pHVar5,0x14e,WVar2,0);
              FUN_400e6338(_Dest,0x20001);
            }
            LocalFree(_Dest);
          }
        }
      }
      goto LAB_400e6e4c;
    }
    goto LAB_400e6950;
  }
  SetWindowLongW(param_1,8,(LONG)param_4);
  FUN_400e666c(param_1);
  BVar11 = 1;
  if (((DAT_400ea450 & 8) == 0) ||
     (hFindFile = FindFirstFileW(L"\\Windows\\*.wav",(LPWIN32_FIND_DATAW)&stack0xfffffda0),
     hFindFile == (HANDLE)0xffffffff)) {
    pHVar5 = GetDlgItem(param_1,0x2011);
    EnableWindow(pHVar5,0);
  }
  else {
    uVar8 = *(uint *)param_4->unused;
    pHVar5 = GetDlgItem(param_1,0x2011);
    SendMessageW(pHVar5,0xf1,(uint)((uVar8 & 8) != 0),0);
    uVar8 = *(uint *)param_4->unused;
    pHVar5 = GetDlgItem(param_1,0x2012);
    SendMessageW(pHVar5,0xf1,(uint)((uVar8 & 0x10) != 0),0);
    do {
      lpsz = local_238;
      pWVar9 = (LPCWSTR)0x0;
      WVar7 = local_238[0];
      if (local_238[0] == L'\0') {
LAB_400e6c1c:
        pWVar10 = lpsz;
      }
      else {
        do {
          if ((WVar7 == L' ') ||
             ((pWVar10 = lpsz, WVar7 != L'.' && (pWVar10 = pWVar9, WVar7 == L'\\')))) {
            pWVar10 = (LPCWSTR)0x0;
          }
          lpsz = CharNextW(lpsz);
          WVar7 = *lpsz;
          pWVar9 = pWVar10;
        } while (WVar7 != L'\0');
        if (pWVar10 == (LPCWSTR)0x0) goto LAB_400e6c1c;
      }
      *pWVar10 = L'\0';
      pHVar5 = GetDlgItem(param_1,0x2015);
      SendMessageW(pHVar5,0x143,0,(LPARAM)local_238);
      BVar6 = FindNextFileW(hFindFile,(LPWIN32_FIND_DATAW)&stack0xfffffda0);
    } while (BVar6 != 0);
    FindClose(hFindFile);
    iVar4 = param_4[1].unused;
    if (iVar4 == 0) {
LAB_400e6ca4:
      WVar2 = 0;
    }
    else {
      pHVar5 = GetDlgItem(param_1,0x2015);
      WVar2 = SendMessageW(pHVar5,0x14c,0,iVar4);
      if (WVar2 == 0xffffffff) goto LAB_400e6ca4;
    }
    pHVar5 = GetDlgItem(param_1,0x2015);
    SendMessageW(pHVar5,0x14e,WVar2,0);
  }
  pHVar5 = GetDlgItem(param_1,0x2011);
  LVar3 = SendMessageW(pHVar5,0xf0,0,0);
  pHVar5 = GetDlgItem(param_1,0x2015);
  EnableWindow(pHVar5,LVar3);
  pHVar5 = GetDlgItem(param_1,0x2012);
  EnableWindow(pHVar5,LVar3);
  if ((DAT_400ea450 & 1) == 0) {
    pHVar5 = GetDlgItem(param_1,0x2014);
    EnableWindow(pHVar5,0);
  }
  else {
    uVar8 = *(uint *)param_4->unused;
    pHVar5 = GetDlgItem(param_1,0x2014);
    SendMessageW(pHVar5,0xf1,(uint)((uVar8 & 1) != 0),0);
  }
  if ((DAT_400ea450 & 2) == 0) {
    pHVar5 = GetDlgItem(param_1,0x2016);
    EnableWindow(pHVar5,0);
  }
  else {
    uVar8 = *(uint *)param_4->unused;
    pHVar5 = GetDlgItem(param_1,0x2016);
    SendMessageW(pHVar5,0xf1,(uint)((uVar8 & 2) != 0),0);
  }
  uVar8 = *(uint *)param_4->unused;
  pHVar5 = GetDlgItem(param_1,0x2013);
  SendMessageW(pHVar5,0xf1,(uint)((uVar8 & 4) != 0),0);
LAB_400e6e4c:
  FUN_400e8d68(local_30);
  return BVar11;
}



/* 400e6f04 FUN_400e6f04 */

/* Boundary evidence: original MIPS .pdata 400e6f04..400e6fb7. Semantic name remains unreviewed. */

undefined4 FUN_400e6f04(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_1c;
  
  memset(&local_48,0,0x30);
  local_48 = param_2;
  local_44 = param_3;
  local_40 = param_4;
  hResInfo = FindResourceW(DAT_400ea4b8,(LPCWSTR)0x2009,(LPCWSTR)0x5);
  hDialogTemplate = LoadResource(DAT_400ea4b8,hResInfo);
  DialogBoxIndirectParamW(DAT_400ea4b8,hDialogTemplate,param_1,FUN_400e6740,(LPARAM)&local_48);
  return local_1c;
}



/* 400e6fb8 FUN_400e6fb8 */

/* Boundary evidence: original MIPS .pdata 400e6fb8..400e7167. Semantic name remains unreviewed. */

void FUN_400e6fb8(HINSTANCE param_1,undefined *param_2)

{
  HRESULT HVar1;
  LSTATUS LVar2;
  size_t local_5b0;
  HKEY local_5ac;
  int local_5a8 [4];
  WCHAR local_598;
  undefined1 auStack_596 [254];
  WCHAR aWStack_498 [64];
  wchar_t local_418;
  undefined1 auStack_416 [1022];
  uint local_18;
  
  local_18 = DAT_400ea460;
  local_5b0 = 0;
  local_598 = L'\0';
  memset(auStack_596,0,0xfe);
  LoadStringW(param_1,0xa2a,&local_598,0x80);
  local_418 = L'\0';
  memset(auStack_416,0,0x3fe);
  HVar1 = StringCchLengthW(&local_598,0x80,&local_5b0);
  if ((-1 < HVar1) && (local_5b0 != 0)) {
    if (param_2 == (undefined *)0x0) {
      param_2 = &DAT_400e1678;
    }
    HVar1 = StringCchPrintfW(&local_418,0x200,&local_598,param_2);
    if (-1 < HVar1) {
      LoadStringW(param_1,0xa28,aWStack_498,0x40);
      LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\GWE\\Notify",0,0x20019,&local_5ac);
      if (LVar2 == 0) {
        local_5a8[1] = 4;
        LVar2 = RegQueryValueExW(local_5ac,L"ShowErrorUI",(LPDWORD)0x0,(LPDWORD)(local_5a8 + 2),
                                 (LPBYTE)local_5a8,(LPDWORD)(local_5a8 + 1));
        if ((LVar2 == 0) && (local_5a8[0] != 0)) {
          DAT_400ea4b0 = DAT_400ea4b0 + 1;
          if (DAT_400ea4b0 < 5) {
            MessageBoxW((HWND)0x0,&local_418,aWStack_498,0x50000);
          }
          DAT_400ea4b0 = DAT_400ea4b0 - 1;
        }
        RegCloseKey(local_5ac);
      }
    }
  }
  FUN_400e8d68(local_18);
  return;
}



/* 400e7168 FUN_400e7168 */

/* Boundary evidence: original MIPS .pdata 400e7168..400e728f. Semantic name remains unreviewed. */

void FUN_400e7168(HINSTANCE param_1)

{
  LSTATUS LVar1;
  HKEY local_1a0;
  int local_19c [3];
  WCHAR aWStack_190 [64];
  WCHAR aWStack_110 [128];
  uint local_10;
  
  local_10 = DAT_400ea460;
  LoadStringW(param_1,0xa2b,aWStack_110,0x80);
  LoadStringW(param_1,0xa28,aWStack_190,0x40);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\GWE\\Notify",0,0x20019,&local_1a0);
  if (LVar1 == 0) {
    local_19c[1] = 4;
    LVar1 = RegQueryValueExW(local_1a0,L"ShowErrorUI",(LPDWORD)0x0,(LPDWORD)(local_19c + 2),
                             (LPBYTE)local_19c,(LPDWORD)(local_19c + 1));
    if ((LVar1 == 0) && (local_19c[0] != 0)) {
      DAT_400ea4b0 = DAT_400ea4b0 + 1;
      if (DAT_400ea4b0 < 5) {
        MessageBoxW((HWND)0x0,aWStack_110,aWStack_190,0x50000);
      }
      DAT_400ea4b0 = DAT_400ea4b0 - 1;
    }
    RegCloseKey(local_1a0);
  }
  FUN_400e8d68(local_10);
  return;
}



/* 400e7290 FUN_400e7290 */

/* Boundary evidence: original MIPS .pdata 400e7290..400e7317. Semantic name remains unreviewed. */

void FUN_400e7290(void)

{
  FUN_400e26b4();
  FUN_400e2704(0xffffff0f);
  DAT_400ea4a4 = 0;
  DAT_400ea4ac = 0;
  FUN_400e6338(0,0);
  if (-1 < DAT_400ea244) {
    FUN_400e6258(0,DAT_400ea244);
  }
  DAT_400ea244 = 0xffffffff;
  DAT_400ea240 = 0xffffffff;
  DAT_400ea4a0 = 0;
  DAT_400ea4a8 = 0;
  return;
}



/* 400e7318 FUN_400e7318 */

/* Boundary evidence: original MIPS .pdata 400e7318..400e73eb. Semantic name remains unreviewed. */

void FUN_400e7318(uint param_1)

{
  if (((param_1 & 0x40) != 0) && (0 < DAT_400ea4ac)) {
    DAT_400ea4ac = DAT_400ea4ac + -1;
  }
  if (((param_1 & 0x10) != 0) && (0 < DAT_400ea4a4)) {
    DAT_400ea4a4 = DAT_400ea4a4 + -1;
  }
  if ((((param_1 & 0x20) != 0) && (0 < DAT_400ea4a8)) &&
     (DAT_400ea4a8 = DAT_400ea4a8 + -1, DAT_400ea4a8 == 0)) {
    FUN_400e26b4();
    FUN_400e6338(0,0);
    if (-1 < DAT_400ea244) {
      FUN_400e6258(0,DAT_400ea244);
    }
    DAT_400ea240 = 0xffffffff;
    DAT_400ea244 = -1;
    DAT_400ea4a0 = 0;
  }
  return;
}



/* 400e73ec FUN_400e73ec */

/* Boundary evidence: original MIPS .pdata 400e73ec..400e760f. Semantic name remains unreviewed. */

undefined4 FUN_400e73ec(int param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined *hMem;
  HLOCAL hMem_00;
  BOOL BVar4;
  DWORD DVar5;
  undefined4 uVar6;
  undefined1 auStack_1e8 [4];
  undefined1 auStack_1e4 [4];
  undefined1 auStack_1e0 [8];
  undefined1 auStack_1d8 [4];
  undefined1 auStack_1d4 [4];
  undefined1 auStack_1d0 [4];
  undefined1 auStack_1cc [36];
  WCHAR aWStack_1a8 [64];
  WCHAR aWStack_128 [128];
  uint local_28;
  
  local_28 = DAT_400ea460;
  FUN_400e7290();
  FUN_400e25c0();
  iVar3 = FUN_400e2608(param_1);
  if (iVar3 == 0) {
    FUN_400e25e4();
  }
  else {
    if (*(wchar_t **)(iVar3 + 0x3c) == (wchar_t *)0x0) {
      hMem = (undefined *)0x0;
    }
    else {
      hMem = FUN_400e63a8(*(wchar_t **)(iVar3 + 0x3c));
    }
    if (*(wchar_t **)(iVar3 + 0x40) == (wchar_t *)0x0) {
      hMem_00 = (HLOCAL)0x0;
    }
    else {
      hMem_00 = FUN_400e63a8(*(wchar_t **)(iVar3 + 0x40));
    }
    FUN_400e25e4();
    if ((hMem != (undefined *)0x0) || (hMem_00 != (HLOCAL)0x0)) {
      memset(auStack_1e8,0,0x3c);
      puVar1 = auStack_1e8 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x3cU >> (3 - uVar2) * 8;
      puVar1 = auStack_1e4 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x400U >> (3 - uVar2) * 8;
      puVar1 = auStack_1e0 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
      puVar1 = auStack_1d8 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)hMem >> (3 - uVar2) * 8;
      puVar1 = auStack_1d4 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)hMem_00 >> (3 - uVar2) * 8;
      puVar1 = auStack_1d0 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
      puVar1 = auStack_1cc + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 1U >> (3 - uVar2) * 8;
      auStack_1e8 = (undefined1  [4])0x3c;
      auStack_1e4 = (undefined1  [4])0x400;
      auStack_1e0._0_4_ = 0;
      auStack_1d0 = (undefined1  [4])0x0;
      auStack_1cc._0_4_ = 1;
      auStack_1d8 = (undefined1  [4])hMem;
      auStack_1d4 = (undefined1  [4])hMem_00;
      BVar4 = FUN_400e64d8((int)auStack_1e8);
      if (BVar4 == 0) {
        DVar5 = GetLastError();
        if (DVar5 == 8) {
          uVar6 = FUN_400e2640(param_1,0x1e);
          if (DAT_400ea4bc == 0) {
            DAT_400ea4bc = 1;
            LoadStringW(DAT_400ea4b8,0xa29,aWStack_128,0x80);
            LoadStringW(DAT_400ea4b8,0xa28,aWStack_1a8,0x40);
            MessageBoxW(DAT_400ea4b4,aWStack_128,aWStack_1a8,0x10000);
            DAT_400ea4bc = 0;
          }
        }
        else {
          FUN_400e6fb8(DAT_400ea4b8,hMem);
          uVar6 = 0;
        }
      }
      else {
        uVar6 = 0;
      }
      if (hMem != (undefined *)0x0) {
        LocalFree(hMem);
      }
      if (hMem_00 != (HLOCAL)0x0) {
        LocalFree(hMem_00);
      }
      FUN_400e8d68(local_28);
      return uVar6;
    }
  }
  FUN_400e8d68(local_28);
  return 0;
}



/* 400e7610 FUN_400e7610 */

/* Boundary evidence: original MIPS .pdata 400e7610..400e79cf. Semantic name remains unreviewed. */

undefined4 FUN_400e7610(HWND param_1,int param_2,uint param_3,undefined4 *param_4)

{
  LONG LVar1;
  LRESULT LVar2;
  int iVar3;
  HWND pHVar4;
  int iVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  tagRECT local_28;
  
  if (param_2 == 0x7f) {
    LVar1 = GetWindowLongW(param_1,8);
    FUN_400e25c0();
    iVar3 = FUN_400e2608(LVar1);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else if (param_3 == 1) {
      iVar3 = *(int *)(iVar3 + 0x14);
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x10);
    }
    FUN_400e25e4();
    SetWindowLongW(param_1,0,iVar3);
    if (iVar3 != 0) {
      return 1;
    }
  }
  else if (param_2 == 0x110) {
    SetWindowLongW(param_1,8,param_4[3]);
    pHVar4 = GetDlgItem(param_1,0x200d);
    iVar3 = 0;
    do {
      iVar5 = LoadStringW(DAT_400ea4b8,iVar3 + 0xa32,(LPWSTR)0x0,0);
      SendMessageW(pHVar4,0x143,0,iVar5);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 9);
    SetWindowTextW(param_1,(LPCWSTR)*param_4);
    SetDlgItemTextW(param_1,0x200f,(LPCWSTR)param_4[1]);
    SendDlgItemMessageW(param_1,0x200d,0x14e,0,0);
    if (param_4[2] != 0) {
      SendDlgItemMessageW(param_1,0x200e,0x172,1,param_4[2]);
    }
    if (param_4[4] == 0) {
      pHVar4 = GetDlgItem(param_1,0x2010);
      ShowWindow(pHVar4,0);
      EnableWindow(pHVar4,0);
    }
    pHVar4 = GetForegroundWindow();
    if (((pHVar4 != (HWND)0x0) && (LVar1 = GetWindowLongW(pHVar4,-0x15), LVar1 == 0x53565320)) &&
       (BVar6 = GetWindowRect(pHVar4,&local_28), BVar6 != 0)) {
      iVar3 = GetSystemMetrics(5);
      iVar5 = GetSystemMetrics(4);
      iVar3 = iVar3 + iVar5;
      uVar8 = GetSystemMetrics(0);
      uVar7 = GetSystemMetrics(1);
      if (((uint)(local_28.bottom + iVar3) < uVar7) && ((uint)(local_28.right + iVar3) < uVar8)) {
        SetWindowPos(param_1,(HWND)0x0,local_28.left + iVar3,local_28.top + iVar3,0,0,0x15);
      }
    }
    pHVar4 = GetDlgItem(param_1,0x200c);
    SetFocus(pHVar4);
  }
  else if ((param_2 == 0x111) && (LVar1 = GetWindowLongW(param_1,8), LVar1 != 0)) {
    uVar8 = param_3 & 0xffff;
    if (uVar8 != 1) {
      if ((uVar8 == 2) || (uVar8 == 0x200b)) {
        FUN_400e7290();
        FUN_400e25c0();
        iVar3 = FUN_400e2608(LVar1);
        FUN_400e25e4();
        if (iVar3 == 0) {
          DestroyWindow(param_1);
        }
        FUN_400e2668(LVar1);
        return 1;
      }
      if (uVar8 == 0x200c) {
        FUN_400e7290();
        LVar2 = SendDlgItemMessageW(param_1,0x200d,0x147,0,0);
        if (LVar2 < 0) {
          return 1;
        }
        if (LVar2 < 10) {
          iVar3 = FUN_400e2640(LVar1,*(int *)(&DAT_400ea1e4 + LVar2 * 4) * 0x3c);
          if (iVar3 == 0) {
            FUN_400e7168(DAT_400ea4b8);
            return 1;
          }
          return 1;
        }
        return 1;
      }
      if (uVar8 != 0x2010) {
        return 0;
      }
    }
    FUN_400e73ec(LVar1);
    return 1;
  }
  return 0;
}



/* 400e79d0 FUN_400e79d0 */

/* Boundary evidence: original MIPS .pdata 400e79d0..400e7ab7. Semantic name remains unreviewed. */

void FUN_400e79d0(HLOCAL param_1)

{
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  uint local_18;
  
  local_18 = DAT_400ea460;
  if ((*(uint *)((int)param_1 + 8) & 0xf0) != 0) {
    FUN_400e7318(*(uint *)((int)param_1 + 8));
  }
  if (*(HWND *)((int)param_1 + 0x1c) != (HWND)0x0) {
    DestroyWindow(*(HWND *)((int)param_1 + 0x1c));
  }
  if (*(int *)((int)param_1 + 0x18) != 0) {
    memset(&local_b0,0,0x98);
    local_ac = DAT_400ea4b4;
    local_a8 = *(undefined4 *)((int)param_1 + 0xc);
    local_b0 = 0x98;
    FUN_400e641c(2,&local_b0);
  }
  if (*(HICON *)((int)param_1 + 0x14) != (HICON)0x0) {
    DestroyIcon(*(HICON *)((int)param_1 + 0x14));
  }
  if (*(HICON *)((int)param_1 + 0x10) != (HICON)0x0) {
    DestroyIcon(*(HICON *)((int)param_1 + 0x10));
  }
  LocalFree(param_1);
  FUN_400e8d68(local_18);
  return;
}



/* 400e7ab8 FUN_400e7ab8 */

/* Boundary evidence: original MIPS .pdata 400e7ab8..400e819b. Semantic name remains unreviewed. */

void FUN_400e7ab8(uint param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  HICON pHVar3;
  int iVar4;
  wchar_t *_Str;
  HLOCAL hMem;
  wchar_t *hMem_00;
  HLOCAL hMem_01;
  HLOCAL hMem_02;
  size_t sVar5;
  int iVar6;
  BOOL BVar7;
  DWORD DVar8;
  wchar_t *_Source;
  HWND hWnd;
  uint uVar9;
  HICON local_244;
  HICON local_240 [2];
  _FILETIME local_238;
  HLOCAL local_230;
  HLOCAL local_22c;
  HICON local_228;
  uint local_224;
  uint local_220;
  undefined1 auStack_218 [4];
  undefined1 auStack_214 [4];
  undefined1 auStack_210 [8];
  undefined1 auStack_208 [4];
  undefined1 auStack_204 [4];
  undefined1 auStack_200 [4];
  undefined1 auStack_1fc [36];
  _SYSTEMTIME _Stack_1d8;
  WCHAR local_1c8 [2];
  undefined1 auStack_1c4 [4];
  undefined1 auStack_1c0 [4];
  undefined4 local_1bc;
  undefined1 auStack_1b8 [4];
  undefined1 auStack_1b4 [132];
  WCHAR aWStack_130 [128];
  uint local_30;
  
  local_30 = DAT_400ea460;
  FUN_400e25c0();
  iVar4 = FUN_400e2608(param_1);
  if (iVar4 == 0) {
    FUN_400e25e4();
    goto LAB_400e8164;
  }
  if (*(wchar_t **)(iVar4 + 0x3c) == (wchar_t *)0x0) {
    _Str = (wchar_t *)0x0;
  }
  else {
    _Str = FUN_400e63a8(*(wchar_t **)(iVar4 + 0x3c));
  }
  if (*(wchar_t **)(iVar4 + 0x40) == (wchar_t *)0x0) {
    hMem = (HLOCAL)0x0;
  }
  else {
    hMem = FUN_400e63a8(*(wchar_t **)(iVar4 + 0x40));
  }
  if ((*(uint *)(iVar4 + 8) & 1) == 0) {
    FUN_400e25e4();
LAB_400e802c:
    if ((_Str == (wchar_t *)0x0) && (hMem == (HLOCAL)0x0)) goto LAB_400e8164;
    memset(auStack_218,0,0x3c);
    puVar1 = auStack_218 + 3;
    uVar9 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar9) =
         *(uint *)(puVar1 + -uVar9) & -1 << (uVar9 + 1) * 8 | 0x3cU >> (3 - uVar9) * 8;
    puVar1 = auStack_214 + 3;
    uVar9 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar9) =
         *(uint *)(puVar1 + -uVar9) & -1 << (uVar9 + 1) * 8 | 0x400U >> (3 - uVar9) * 8;
    puVar1 = auStack_210 + 3;
    uVar9 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar9) =
         *(uint *)(puVar1 + -uVar9) & -1 << (uVar9 + 1) * 8 | 0U >> (3 - uVar9) * 8;
    puVar1 = auStack_208 + 3;
    uVar9 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar9) =
         *(uint *)(puVar1 + -uVar9) & -1 << (uVar9 + 1) * 8 | (uint)_Str >> (3 - uVar9) * 8;
    puVar1 = auStack_204 + 3;
    uVar9 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar9) =
         *(uint *)(puVar1 + -uVar9) & -1 << (uVar9 + 1) * 8 | (uint)hMem >> (3 - uVar9) * 8;
    puVar1 = auStack_200 + 3;
    uVar9 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar9) =
         *(uint *)(puVar1 + -uVar9) & -1 << (uVar9 + 1) * 8 | 0U >> (3 - uVar9) * 8;
    puVar1 = auStack_1fc + 3;
    uVar9 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar9) =
         *(uint *)(puVar1 + -uVar9) & -1 << (uVar9 + 1) * 8 | 1U >> (3 - uVar9) * 8;
    auStack_218 = (undefined1  [4])0x3c;
    auStack_214 = (undefined1  [4])0x400;
    auStack_210._0_4_ = 0;
    auStack_200 = (undefined1  [4])0x0;
    auStack_1fc._0_4_ = 1;
    auStack_208 = (undefined1  [4])_Str;
    auStack_204 = (undefined1  [4])hMem;
    BVar7 = FUN_400e64d8((int)auStack_218);
    if (BVar7 == 0) {
      DVar8 = GetLastError();
      if (DVar8 == 8) {
        iVar4 = FUN_400e2640(param_1,0x1e);
        if (iVar4 == 0) {
          FUN_400e2668(param_1);
        }
        if (DAT_400ea4bc == 0) {
          DAT_400ea4bc = 1;
          LoadStringW(DAT_400ea4b8,0xa29,aWStack_130,0x80);
          LoadStringW(DAT_400ea4b8,0xa28,local_1c8,0x40);
          MessageBoxW(DAT_400ea4b4,aWStack_130,local_1c8,0x10000);
          DAT_400ea4bc = 0;
        }
        goto LAB_400e8144;
      }
      FUN_400e6fb8(DAT_400ea4b8,(undefined *)_Str);
    }
    FUN_400e2668(param_1);
  }
  else {
    uVar9 = *(uint *)(iVar4 + 0x24);
    hWnd = (HWND)0x0;
    local_240[0] = (HICON)0x0;
    local_244 = (HICON)0x0;
    if (*(wchar_t **)(iVar4 + 0x4c) == (wchar_t *)0x0) {
      hMem_00 = (wchar_t *)0x0;
    }
    else {
      hMem_00 = FUN_400e63a8(*(wchar_t **)(iVar4 + 0x4c));
    }
    if (*(wchar_t **)(iVar4 + 0x44) == (wchar_t *)0x0) {
      hMem_01 = (HLOCAL)0x0;
    }
    else {
      hMem_01 = FUN_400e63a8(*(wchar_t **)(iVar4 + 0x44));
    }
    if (*(wchar_t **)(iVar4 + 0x48) == (wchar_t *)0x0) {
      hMem_02 = (HLOCAL)0x0;
    }
    else {
      hMem_02 = FUN_400e63a8(*(wchar_t **)(iVar4 + 0x48));
    }
    FUN_400e25e4();
    if ((_Str != (wchar_t *)0x0) &&
       ((sVar5 = wcslen(_Str), sVar5 < 0x1e ||
        (iVar6 = _wcsnicmp(_Str,L"\\\\.\\Notifications\\NamedEvents\\",0x1e), iVar6 != 0)))) {
      ExtractIconExW(_Str,0,local_240,&local_244,1);
    }
    if (local_244 == (HICON)0x0) {
      local_244 = LoadImageW(DAT_400ea4b8,(LPCWSTR)0x2008,1,0x10,0x10,0);
    }
    pHVar3 = local_244;
    memset(local_1c8,0,0x98);
    local_1bc = 3;
    local_1c8[0] = L'\x98';
    local_1c8[1] = L'\0';
    puVar1 = auStack_1c4 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)DAT_400ea4b4 >> (3 - uVar2) * 8;
    puVar1 = auStack_1c0 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_1 >> (3 - uVar2) * 8;
    puVar1 = auStack_1b8 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x401U >> (3 - uVar2) * 8;
    puVar1 = auStack_1b4 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)pHVar3 >> (3 - uVar2) * 8;
    auStack_1c4 = (undefined1  [4])DAT_400ea4b4;
    auStack_1b8 = (undefined1  [4])0x401;
    auStack_1b4._0_4_ = pHVar3;
    auStack_1c0 = (undefined1  [4])param_1;
    iVar6 = FUN_400e641c(0,local_1c8);
    if ((uVar9 & 1) != 0) {
      *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) | 0x40;
      DAT_400ea4ac = DAT_400ea4ac + 1;
    }
    if ((uVar9 & 2) != 0) {
      *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) | 0x10;
      DAT_400ea4a4 = DAT_400ea4a4 + 1;
    }
    if ((uVar9 & 8) != 0) {
      if ((uVar9 & 0x10) == 0) {
        FUN_400e6338(hMem_00,0x20001);
      }
      else {
        *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) | 0x20;
        DAT_400ea4a8 = DAT_400ea4a8 + 1;
        if (0xd < DAT_400ea240) {
          DAT_400ea240 = 0;
          DAT_400ea4a0 = 6;
          _Source = hMem_00;
          if (hMem_00 == (wchar_t *)0x0) {
            _Source = L"default";
          }
          wcscpy(u_default_400ea248,_Source);
          GetLocalTime(&_Stack_1d8);
          SystemTimeToFileTime(&_Stack_1d8,&local_238);
          local_238 = (_FILETIME)
                      ((ulonglong)(uint)(&DAT_400ea208)[DAT_400ea240] * 600000000 +
                      (longlong)local_238);
          FUN_400e2690(&local_238);
          if (DAT_400ea244 < 0) {
            FUN_400e62c8(0,&DAT_400ea244);
          }
          FUN_400e6258(0,0x8000);
          FUN_400e6338(hMem_00,0x20009);
          SetTimer(DAT_400ea4b4,1,5000,(TIMERPROC)0x0);
        }
      }
    }
    local_228 = local_240[0];
    local_220 = (uint)(_Str != (wchar_t *)0x0);
    local_230 = hMem_01;
    local_22c = hMem_02;
    local_224 = param_1;
    if ((((uVar9 & 4) != 0) && (hMem_01 != (HLOCAL)0x0)) && (hMem_02 != (HLOCAL)0x0)) {
      if ((uVar9 & 0x20) == 0) {
        DAT_400ea4c0->dwExtendedStyle = DAT_400ea4c0->dwExtendedStyle | 0x20000000;
      }
      else {
        DAT_400ea4c0->dwExtendedStyle = DAT_400ea4c0->dwExtendedStyle & 0xdfffffff;
      }
      hWnd = CreateDialogIndirectParamW
                       (DAT_400ea4b8,DAT_400ea4c0,DAT_400ea4b4,FUN_400e7610,(LPARAM)&local_230);
      if (hWnd != (HWND)0x0) {
        SetWindowLongW(hWnd,-0x15,0x53565320);
        SetForegroundWindow(hWnd);
        ShowWindow(hWnd,1);
      }
    }
    if (hMem_00 != (wchar_t *)0x0) {
      LocalFree(hMem_00);
    }
    if (hMem_01 != (HLOCAL)0x0) {
      LocalFree(hMem_01);
    }
    if (hMem_02 != (HLOCAL)0x0) {
      LocalFree(hMem_02);
    }
    if ((hWnd == (HWND)0x0) && (iVar6 == 0)) goto LAB_400e802c;
    FUN_400e25c0();
    iVar4 = FUN_400e2608(param_1);
    if (iVar4 != 0) {
      *(HWND *)(iVar4 + 0x1c) = hWnd;
      *(HICON *)(iVar4 + 0x10) = local_244;
      *(HICON *)(iVar4 + 0x14) = local_240[0];
      *(int *)(iVar4 + 0x18) = iVar6;
    }
    FUN_400e25e4();
  }
LAB_400e8144:
  if (_Str != (wchar_t *)0x0) {
    LocalFree(_Str);
  }
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
LAB_400e8164:
  FUN_400e8d68(local_30);
  return;
}



/* 400e819c FUN_400e819c */

/* Boundary evidence: original MIPS .pdata 400e819c..400e852f. Semantic name remains unreviewed. */

LRESULT FUN_400e819c(HWND param_1,UINT param_2,WPARAM param_3,HLOCAL param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  LRESULT LVar3;
  int iVar4;
  undefined4 uVar5;
  HWND hWnd;
  _FILETIME local_c8;
  _SYSTEMTIME _Stack_c0;
  undefined4 local_b0;
  HWND local_ac;
  undefined1 auStack_a8 [144];
  uint local_18;
  
  local_18 = DAT_400ea460;
  if (param_2 != 1) {
    if (param_2 == 2) {
      PostQuitMessage(0);
    }
    else if (param_2 == 0x113) {
      if (param_3 == 1) {
        DAT_400ea4a0 = DAT_400ea4a0 - 1;
        if ((DAT_400ea4a0 & 1) == 0) {
          SetTimer(DAT_400ea4b4,1,5000,(TIMERPROC)0x0);
          if (DAT_400ea244 < 0) {
            FUN_400e62c8(0,&DAT_400ea244);
          }
          uVar5 = 0xc000;
          if (DAT_400ea4a0 != 4) {
            uVar5 = 0xffff;
          }
          FUN_400e6258(0,uVar5);
          FUN_400e6338(u_default_400ea248,0x20009);
        }
        else {
          if ((int)DAT_400ea4a0 < 2) {
            KillTimer(param_1,1);
          }
          else {
            SetTimer(DAT_400ea4b4,1,10000,(TIMERPROC)0x0);
          }
          FUN_400e6338(0,0);
          if (-1 < DAT_400ea244) {
            FUN_400e6258(0,DAT_400ea244);
          }
          DAT_400ea244 = -1;
        }
      }
    }
    else if (param_2 == 0x401) {
      FUN_400e7290();
      if (param_4 == (HLOCAL)0x201) {
        FUN_400e25c0();
        iVar4 = FUN_400e2608(param_3);
        if (iVar4 == 0) {
          FUN_400e25e4();
          memset(&local_b0,0,0x98);
          puVar1 = auStack_a8 + 3;
          uVar2 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar2) =
               *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_3 >> (3 - uVar2) * 8;
          local_b0 = 0x98;
          local_ac = DAT_400ea4b4;
          auStack_a8._0_4_ = param_3;
          FUN_400e641c(2,&local_b0);
        }
        else {
          hWnd = *(HWND *)(iVar4 + 0x1c);
          FUN_400e25e4();
          if (hWnd == (HWND)0x0) {
            iVar4 = FUN_400e73ec(param_3);
            if (iVar4 == 0) {
              FUN_400e2668(param_3);
            }
          }
          else {
            SetForegroundWindow(hWnd);
          }
        }
      }
    }
    else if (param_2 == 0x402) {
      if (param_3 == 0x53565320) {
        FUN_400e79d0(param_4);
      }
    }
    else if (param_2 == 0x403) {
      if (param_3 == 0x53565320) {
        FUN_400e7ab8((uint)param_4);
      }
    }
    else {
      if (param_2 != 0x404) {
        LVar3 = DefWindowProcW(param_1,param_2,param_3,(LPARAM)param_4);
        FUN_400e8d68(local_18);
        return LVar3;
      }
      DAT_400ea240 = DAT_400ea240 + 1;
      if (DAT_400ea240 < 0xe) {
        if (DAT_400ea244 < 0) {
          FUN_400e62c8(0,&DAT_400ea244);
        }
        FUN_400e6258(0,0x8000);
        FUN_400e6338(u_default_400ea248,0x20009);
        DAT_400ea4a0 = 6;
        GetLocalTime(&_Stack_c0);
        SystemTimeToFileTime(&_Stack_c0,&local_c8);
        local_c8 = (_FILETIME)
                   ((ulonglong)(uint)(&DAT_400ea208)[DAT_400ea240] * 600000000 + (longlong)local_c8)
        ;
        FUN_400e2690(&local_c8);
        SetTimer(DAT_400ea4b4,1,5000,(TIMERPROC)0x0);
      }
    }
  }
  FUN_400e8d68(local_18);
  return 0;
}



/* 400e8530 FUN_400e8530 */

/* Boundary evidence: original MIPS .pdata 400e8530..400e860f. Semantic name remains unreviewed. */

undefined4 FUN_400e8530(HMODULE param_1,undefined4 param_2)

{
  HRSRC hResInfo;
  HGLOBAL _Src;
  DWORD uBytes;
  
  DAT_400ea240 = 0xffffffff;
  DAT_400ea4b4 = param_2;
  DAT_400ea4b8 = param_1;
  hResInfo = FindResourceW(param_1,(LPCWSTR)0x200a,(LPCWSTR)0x5);
  if ((((hResInfo != (HRSRC)0x0) &&
       (_Src = LoadResource(DAT_400ea4b8,hResInfo), _Src != (HGLOBAL)0x0)) &&
      (uBytes = SizeofResource(DAT_400ea4b8,hResInfo), 0 < (int)uBytes)) &&
     (DAT_400ea4c0 = LocalAlloc(0,uBytes), DAT_400ea4c0 != (HLOCAL)0x0)) {
    memcpy(DAT_400ea4c0,_Src,uBytes);
    return 1;
  }
  return 0;
}



/* 400e8610 FUN_400e8610 */

bool FUN_400e8610(uint param_1)

{
  return param_1 < 0x10;
}



/* 400e8628 FUN_400e8628 */

undefined4 FUN_400e8628(uint *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (((param_1[5] == 0) && (uVar2 = *param_1, (uVar2 & 0xffffffc0) == 0)) &&
     (((uVar2 & 8) == 0 || (param_1[3] != 0)))) {
    if (((uVar2 & 0x10) == 0) || (uVar1 = 0, (uVar2 & 8) != 0)) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 400e868c FUN_400e868c */

/* Boundary evidence: original MIPS .pdata 400e868c..400e86bb. Semantic name remains unreviewed. */

void FUN_400e868c(LPARAM param_1)

{
  PostMessageW(DAT_400ea4b4,0x402,0x53565320,param_1);
  return;
}



/* 400e86bc FUN_400e86bc */

/* Boundary evidence: original MIPS .pdata 400e86bc..400e86eb. Semantic name remains unreviewed. */

void FUN_400e86bc(LPARAM param_1)

{
  PostMessageW(DAT_400ea4b4,0x403,0x53565320,param_1);
  return;
}



/* 400e86ec FUN_400e86ec */

/* Boundary evidence: original MIPS .pdata 400e86ec..400e8717. Semantic name remains unreviewed. */

void FUN_400e86ec(void)

{
  PostMessageW(DAT_400ea4b4,0x404,0,0);
  return;
}



/* 400e8718 FUN_400e8718 */

/* Boundary evidence: original MIPS .pdata 400e8718..400e8753. Semantic name remains unreviewed. */

void FUN_400e8718(void)

{
  if (DAT_400ea4c0 != (HLOCAL)0x0) {
    LocalFree(DAT_400ea4c0);
  }
  DAT_400ea4c0 = (HLOCAL)0x0;
  return;
}



/* 400e8764 FUN_400e8764 */

void FUN_400e8764(void)

{
  return;
}



/* 400e876c FUN_400e876c */

/* Boundary evidence: original MIPS .pdata 400e876c..400e8787. Semantic name remains unreviewed. */

void FUN_400e876c(size_t param_1)

{
  malloc(param_1);
  return;
}



/* 400e8788 FUN_400e8788 */

/* Boundary evidence: original MIPS .pdata 400e8788..400e87a3. Semantic name remains unreviewed. */

void FUN_400e8788(void *param_1,size_t param_2)

{
  realloc(param_1,param_2);
  return;
}



/* 400e87a4 FUN_400e87a4 */

/* Boundary evidence: original MIPS .pdata 400e87a4..400e87bf. Semantic name remains unreviewed. */

void FUN_400e87a4(void *param_1)

{
  free(param_1);
  return;
}



/* 400e8c00 entry */

/* Boundary evidence: original MIPS .pdata 400e8c00..400e8c73. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_400e8c74();
    FUN_400e8f48();
  }
  uVar1 = FUN_400e28bc(param_1,param_2);
  if (param_2 == 0) {
    FUN_400e8ed0();
  }
  return uVar1;
}



/* 400e8c74 FUN_400e8c74 */

/* Boundary evidence: original MIPS .pdata 400e8c74..400e8ce7. Semantic name remains unreviewed. */

void FUN_400e8c74(void)

{
  uint uVar1;
  
  if ((DAT_400ea460 == 0) || (DAT_400ea460 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_400ea460 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_400ea460 == 0) {
      DAT_400ea460 = 0xb064;
    }
  }
  DAT_400ea464 = ~DAT_400ea460;
  return;
}



/* 400e8ce8 FUN_400e8ce8 */

/* Boundary evidence: original MIPS .pdata 400e8ce8..400e8d3b. Semantic name remains unreviewed. */

void FUN_400e8ce8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_400e8d68(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 400e8d3c FUN_400e8d3c */

/* Boundary evidence: original MIPS .pdata 400e8d3c..400e8d67. Semantic name remains unreviewed. */

undefined4 FUN_400e8d3c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_400e8ce8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 400e8d68 FUN_400e8d68 */

/* Boundary evidence: original MIPS .pdata 400e8d68..400e8daf. Semantic name remains unreviewed. */

void FUN_400e8d68(uint param_1)

{
  if ((param_1 == DAT_400ea460) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 400e8db0 FUN_400e8db0 */

/* Boundary evidence: original MIPS .pdata 400e8db0..400e8ecf. Semantic name remains unreviewed. */

void FUN_400e8db0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_400ea4e0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_400ea4e8;
    if (DAT_400ea4e8 != (undefined4 *)0x0) {
      while (DAT_400ea4e4 = DAT_400ea4e4 + -1, _Memory <= DAT_400ea4e4) {
        if ((code *)*DAT_400ea4e4 != (code *)0x0) {
          (*(code *)*DAT_400ea4e4)();
          _Memory = DAT_400ea4e8;
        }
      }
      free(_Memory);
      DAT_400ea4e4 = (undefined4 *)0x0;
      DAT_400ea4e8 = (undefined4 *)0x0;
    }
    FUN_400e8ef4((undefined4 *)&DAT_400e1010,(undefined4 *)&DAT_400e1014);
  }
  FUN_400e8ef4((undefined4 *)&DAT_400e1018,(undefined4 *)&DAT_400e101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_400ea4ec,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 400e8ed0 FUN_400e8ed0 */

/* Boundary evidence: original MIPS .pdata 400e8ed0..400e8ef3. Semantic name remains unreviewed. */

void FUN_400e8ed0(void)

{
  FUN_400e8db0(0,0,1);
  return;
}



/* 400e8ef4 FUN_400e8ef4 */

/* Boundary evidence: original MIPS .pdata 400e8ef4..400e8f47. Semantic name remains unreviewed. */

void FUN_400e8ef4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 400e8f48 FUN_400e8f48 */

/* Boundary evidence: original MIPS .pdata 400e8f48..400e8f83. Semantic name remains unreviewed. */

void FUN_400e8f48(void)

{
  FUN_400e8ef4((undefined4 *)&DAT_400e1008,(undefined4 *)&DAT_400e100c);
  FUN_400e8ef4((undefined4 *)&DAT_400e1000,(undefined4 *)&DAT_400e1004);
  return;
}


