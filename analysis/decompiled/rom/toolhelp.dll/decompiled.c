/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40131064 DllMain */

/* Boundary evidence: original MIPS .pdata 40131064..40131097. Semantic name remains unreviewed. */

undefined4 DllMain(HMODULE param_1,int param_2)

{
                    /* 0x1064  3  DllMain */
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 40131098 CreateToolhelp32Snapshot */

/* Boundary evidence: original MIPS .pdata 40131098..40131113. Semantic name remains unreviewed. */

int CreateToolhelp32Snapshot(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1098  2  CreateToolhelp32Snapshot */
  iVar1 = THCreateSnapshot(param_1,param_2);
  if (((param_1 & 1) != 0) && ((param_2 == 0 || (iVar2 = __GetUserKData(0xc), iVar2 == param_2)))) {
    GetHeapSnapshot(iVar1);
  }
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  return iVar1;
}



/* 40131114 CloseToolhelp32Snapshot */

/* Boundary evidence: original MIPS .pdata 40131114..40131147. Semantic name remains unreviewed. */

undefined4 CloseToolhelp32Snapshot(LPVOID param_1)

{
                    /* 0x1114  1  CloseToolhelp32Snapshot */
  if (param_1 != (LPVOID)0xffffffff) {
    VirtualFree(param_1,0,0x8000);
  }
  return 1;
}



/* 40131148 Toolhelp32ReadProcessMemory */

/* Boundary evidence: original MIPS .pdata 40131148..4013122f. Semantic name remains unreviewed. */

BOOL Toolhelp32ReadProcessMemory
               (HANDLE param_1,LPCVOID param_2,LPVOID param_3,SIZE_T param_4,SIZE_T *param_5)

{
  HANDLE hProcess;
  BOOL BVar1;
  
                    /* 0x1148  14  Toolhelp32ReadProcessMemory */
  if (param_1 == (HANDLE)0x0) {
    param_1 = (HANDLE)__GetUserKData(0xc);
  }
  if (param_5 != (SIZE_T *)0x0) {
    *param_5 = 0;
  }
  hProcess = OpenProcess(0,0,(DWORD)param_1);
  if ((hProcess == (HANDLE)0x0) && (hProcess = param_1, ((uint)param_1 & 3) == 0)) {
    SetLastError(0x57);
    BVar1 = 0;
  }
  else {
    BVar1 = ReadProcessMemory(hProcess,param_2,param_3,param_4,param_5);
    if (hProcess != param_1) {
      CloseHandle(hProcess);
    }
  }
  return BVar1;
}



/* 40131230 Process32First */

/* Boundary evidence: original MIPS .pdata 40131230..401312cb. Semantic name remains unreviewed. */

undefined4 Process32First(int param_1,uint *param_2)

{
  DWORD dwErrCode;
  
                    /* 0x1230  10  Process32First */
  if ((((param_1 == 0) || (param_1 == -1)) || (param_2 == (uint *)0x0)) || (*param_2 < 0x234)) {
    dwErrCode = 0x57;
  }
  else {
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0x24) = 1;
      memcpy(param_2,(void *)(param_1 + 0x3c),0x234);
      return 1;
    }
    dwErrCode = 0x12;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 401312cc Process32Next */

/* Boundary evidence: original MIPS .pdata 401312cc..4013139b. Semantic name remains unreviewed. */

undefined4 Process32Next(int param_1,uint *param_2)

{
  DWORD dwErrCode;
  uint uVar1;
  
                    /* 0x12cc  11  Process32Next */
  if ((((param_1 == 0) || (param_1 == -1)) || (*(uint *)(param_1 + 0x10) == 0)) ||
     (((uVar1 = *(uint *)(param_1 + 0x24), uVar1 == 0 || (param_2 == (uint *)0x0)) ||
      (*param_2 < 0x234)))) {
    dwErrCode = 0x57;
  }
  else {
    if (uVar1 < *(uint *)(param_1 + 0x10)) {
      memcpy(param_2,(void *)(uVar1 * 0x234 + param_1 + 0x3c),0x234);
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
      return 1;
    }
    dwErrCode = 0x12;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 4013139c Thread32First */

/* Boundary evidence: original MIPS .pdata 4013139c..40131463. Semantic name remains unreviewed. */

undefined4 Thread32First(int param_1,uint *param_2)

{
  DWORD dwErrCode;
  
                    /* 0x139c  12  Thread32First */
  if ((((param_1 == 0) || (param_1 == -1)) || (param_2 == (uint *)0x0)) || (*param_2 < 0x24)) {
    dwErrCode = 0x57;
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0) {
      memcpy(param_2,(void *)(*(int *)(param_1 + 0x14) * 0x434 + *(int *)(param_1 + 0x10) * 0x234 +
                              param_1 + 0x3c),0x24);
      *(undefined4 *)(param_1 + 0x2c) = 1;
      return 1;
    }
    dwErrCode = 0x12;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 40131464 Thread32Next */

/* Boundary evidence: original MIPS .pdata 40131464..4013156b. Semantic name remains unreviewed. */

undefined4 Thread32Next(int param_1,uint *param_2)

{
  DWORD dwErrCode;
  uint uVar1;
  
                    /* 0x1464  13  Thread32Next */
  if ((((param_1 == 0) || (param_1 == -1)) || (*(uint *)(param_1 + 0x18) == 0)) ||
     (((uVar1 = *(uint *)(param_1 + 0x2c), uVar1 == 0 || (param_2 == (uint *)0x0)) ||
      (*param_2 < 0x24)))) {
    dwErrCode = 0x57;
  }
  else {
    if (uVar1 < *(uint *)(param_1 + 0x18)) {
      memcpy(param_2,(void *)(*(int *)(param_1 + 0x14) * 0x434 + *(int *)(param_1 + 0x10) * 0x234 +
                              uVar1 * 0x24 + param_1 + 0x3c),0x24);
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
      return 1;
    }
    dwErrCode = 0x12;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 4013156c Module32First */

/* Boundary evidence: original MIPS .pdata 4013156c..40131617. Semantic name remains unreviewed. */

undefined4 Module32First(int param_1,uint *param_2)

{
  DWORD dwErrCode;
  
                    /* 0x156c  8  Module32First */
  if ((((param_1 == 0) || (param_1 == -1)) || (param_2 == (uint *)0x0)) || (*param_2 < 0x434)) {
    dwErrCode = 0x57;
  }
  else {
    if (*(int *)(param_1 + 0x14) != 0) {
      memcpy(param_2,(void *)(*(int *)(param_1 + 0x10) * 0x234 + param_1 + 0x3c),0x434);
      *(undefined4 *)(param_1 + 0x28) = 1;
      return 1;
    }
    dwErrCode = 0x12;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 40131618 Module32Next */

/* Boundary evidence: original MIPS .pdata 40131618..40131703. Semantic name remains unreviewed. */

undefined4 Module32Next(int param_1,uint *param_2)

{
  DWORD dwErrCode;
  uint uVar1;
  
                    /* 0x1618  9  Module32Next */
  if ((((param_1 == 0) || (param_1 == -1)) || (*(uint *)(param_1 + 0x14) == 0)) ||
     (((uVar1 = *(uint *)(param_1 + 0x28), uVar1 == 0 || (param_2 == (uint *)0x0)) ||
      (*param_2 < 0x434)))) {
    dwErrCode = 0x57;
  }
  else {
    if (uVar1 < *(uint *)(param_1 + 0x14)) {
      memcpy(param_2,(void *)(*(int *)(param_1 + 0x10) * 0x234 + uVar1 * 0x434 + param_1 + 0x3c),
             0x434);
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
      return 1;
    }
    dwErrCode = 0x12;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 40131704 FUN_40131704 */

undefined4 FUN_40131704(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 + 0x14);
  if ((((uVar3 < 0x18) || (uVar2 = *(uint *)(param_1 + 4), uVar2 <= uVar3)) ||
      (uVar2 <= (uint)(param_2 - param_1))) || (uVar1 = 1, uVar2 < uVar3 + (param_2 - param_1))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4013174c Heap32ListFirst */

/* Boundary evidence: original MIPS .pdata 4013174c..401318c7. Semantic name remains unreviewed. */

undefined4 Heap32ListFirst(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  DWORD dwErrCode;
  uint *puVar4;
  
                    /* 0x174c  5  Heap32ListFirst */
  dwErrCode = 0;
  if ((((param_1 == 0) || (param_1 == -1)) || (param_2 == (uint *)0x0)) || (*param_2 < 0x10)) {
    dwErrCode = 0x57;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x14) * 0x434 + *(int *)(param_1 + 0x10) * 0x234 +
            *(int *)(param_1 + 0x18) * 0x24 + param_1;
    puVar4 = (uint *)(iVar3 + 0x3c);
    if ((*(int *)(param_1 + 0x20) == 0) || (iVar1 = FUN_40131704(param_1,(int)puVar4), iVar1 == 0))
    {
      dwErrCode = 0x12;
    }
    else {
      *param_2 = *puVar4;
      param_2[1] = *(uint *)(iVar3 + 0x40);
      param_2[2] = *(uint *)(iVar3 + 0x44);
      param_2[3] = *(uint *)(iVar3 + 0x48);
      *(int *)(param_1 + 0x30) = (int)puVar4 - param_1;
    }
  }
  if ((dwErrCode == 0) || (SetLastError(dwErrCode), dwErrCode == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 401318c8 FUN_401318c8 */

/* Boundary evidence: original MIPS .pdata 401318c8..401318d3. Semantic name remains unreviewed. */

undefined4 FUN_401318c8(void)

{
  return 1;
}



/* 401318d4 Heap32ListNext */

/* Boundary evidence: original MIPS .pdata 401318d4..40131a27. Semantic name remains unreviewed. */

undefined4 Heap32ListNext(int param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  DWORD dwErrCode;
  uint *puVar3;
  
                    /* 0x18d4  6  Heap32ListNext */
  dwErrCode = 0;
  if (((((param_1 == 0) || (param_1 == -1)) || (*(int *)(param_1 + 0x20) == 0)) ||
      ((*(int *)(param_1 + 0x30) == 0 || (param_2 == (uint *)0x0)))) || (*param_2 < 0x10)) {
    dwErrCode = 0x57;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x30) + param_1;
    puVar3 = (uint *)(*(int *)(iVar2 + 0x14) + iVar2);
    iVar2 = FUN_40131704(param_1,(int)puVar3);
    if (iVar2 == 0) {
      dwErrCode = 0x12;
    }
    else {
      *param_2 = *puVar3;
      param_2[1] = puVar3[1];
      param_2[2] = puVar3[2];
      param_2[3] = puVar3[3];
      *(int *)(param_1 + 0x30) = (int)puVar3 - param_1;
    }
  }
  if ((dwErrCode == 0) || (SetLastError(dwErrCode), dwErrCode == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40131a28 FUN_40131a28 */

/* Boundary evidence: original MIPS .pdata 40131a28..40131a33. Semantic name remains unreviewed. */

undefined4 FUN_40131a28(void)

{
  return 1;
}



/* 40131a34 FUN_40131a34 */

int FUN_40131a34(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = *(uint *)(param_1 + 0x20);
  iVar1 = *(int *)(param_1 + 0x14) * 0x434 + *(int *)(param_1 + 0x10) * 0x234 +
          *(int *)(param_1 + 0x18) * 0x24 + param_1 + 0x3c;
  if (uVar3 != 0) {
    do {
      if (*(uint *)(param_1 + 4) < (uint)(iVar1 - param_1)) {
        iVar1 = 0;
        break;
      }
      if ((param_2 == *(int *)(iVar1 + 4)) && (param_3 == *(int *)(iVar1 + 8))) break;
      uVar2 = uVar2 + 1;
      iVar1 = *(int *)(iVar1 + 0x14) + iVar1;
    } while (uVar2 < uVar3);
  }
  if (uVar3 <= uVar2) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40131aec Heap32First */

/* Boundary evidence: original MIPS .pdata 40131aec..40131c23. Semantic name remains unreviewed. */

undefined4 Heap32First(int param_1,uint *param_2,int param_3,int param_4)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 uVar2;
  
                    /* 0x1aec  4  Heap32First */
  dwErrCode = 0;
  if ((((param_1 == 0) || (param_1 == -1)) || (param_2 == (uint *)0x0)) ||
     ((*param_2 < 0x24 || (iVar1 = FUN_40131a34(param_1,param_3,param_4), iVar1 == 0)))) {
    dwErrCode = 0x57;
  }
  else {
    *(int *)(param_1 + 0x34) = iVar1 - param_1;
    if (*(int *)(iVar1 + 0x10) == 0) {
      dwErrCode = 0x12;
    }
    else {
      memcpy(param_2,(void *)(iVar1 + 0x18),0x24);
      *(undefined4 *)(param_1 + 0x38) = 1;
    }
  }
  uVar2 = 1;
  if ((dwErrCode != 0) && (SetLastError(dwErrCode), dwErrCode != 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40131c24 FUN_40131c24 */

/* Boundary evidence: original MIPS .pdata 40131c24..40131c2f. Semantic name remains unreviewed. */

undefined4 FUN_40131c24(void)

{
  return 1;
}



/* 40131c30 Heap32Next */

/* Boundary evidence: original MIPS .pdata 40131c30..40131d77. Semantic name remains unreviewed. */

undefined4 Heap32Next(int param_1,uint *param_2)

{
  undefined4 uVar1;
  void *_Src;
  uint uVar2;
  int iVar3;
  DWORD dwErrCode;
  
                    /* 0x1c30  7  Heap32Next */
  dwErrCode = 0;
  if ((((param_1 == 0) || (param_1 == -1)) || (uVar2 = *(uint *)(param_1 + 0x38), uVar2 == 0)) ||
     ((param_2 == (uint *)0x0 || (*param_2 < 0x24)))) {
    dwErrCode = 0x57;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x34) + param_1;
    _Src = (void *)(uVar2 * 0x24 + iVar3 + 0x18);
    if (((uint)((int)_Src - param_1) < *(uint *)(param_1 + 4)) && (uVar2 < *(uint *)(iVar3 + 0x10)))
    {
      memcpy(param_2,_Src,0x24);
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
    }
    else {
      dwErrCode = 0x12;
    }
  }
  if ((dwErrCode == 0) || (SetLastError(dwErrCode), dwErrCode == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40131d78 FUN_40131d78 */

/* Boundary evidence: original MIPS .pdata 40131d78..40131d83. Semantic name remains unreviewed. */

undefined4 FUN_40131d78(void)

{
  return 1;
}



/* 40131de4 FUN_40131de4 */

/* Boundary evidence: original MIPS .pdata 40131de4..40131f1f. Semantic name remains unreviewed. */

int FUN_40131de4(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40133060 != (code *)0x0) {
      iVar2 = (*DAT_40133060)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40131e94;
    FUN_4013213c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = DllMain(param_1,param_2);
  }
LAB_40131e94:
  if (((param_2 == 0) && (FUN_401320c4(), iVar1 != 0)) && (DAT_40133060 != (code *)0x0)) {
    iVar1 = (*DAT_40133060)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40131f20 FUN_40131f20 */

/* Boundary evidence: original MIPS .pdata 40131f20..40131f4b. Semantic name remains unreviewed. */

void FUN_40131f20(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40131f4c entry */

/* Boundary evidence: original MIPS .pdata 40131f4c..40131fa3. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40132178();
  }
  FUN_40131de4(param_1,param_2,param_3);
  return;
}



/* 40131fa4 FUN_40131fa4 */

/* Boundary evidence: original MIPS .pdata 40131fa4..401320c3. Semantic name remains unreviewed. */

void FUN_40131fa4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_40133050 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40133058;
    if (DAT_40133058 != (undefined4 *)0x0) {
      while (DAT_40133054 = DAT_40133054 + -1, _Memory <= DAT_40133054) {
        if ((code *)*DAT_40133054 != (code *)0x0) {
          (*(code *)*DAT_40133054)();
          _Memory = DAT_40133058;
        }
      }
      free(_Memory);
      DAT_40133054 = (undefined4 *)0x0;
      DAT_40133058 = (undefined4 *)0x0;
    }
    FUN_401320e8((undefined4 *)&DAT_40131010,(undefined4 *)&DAT_40131014);
  }
  FUN_401320e8((undefined4 *)&DAT_40131018,(undefined4 *)&DAT_4013101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_4013305c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 401320c4 FUN_401320c4 */

/* Boundary evidence: original MIPS .pdata 401320c4..401320e7. Semantic name remains unreviewed. */

void FUN_401320c4(void)

{
  FUN_40131fa4(0,0,1);
  return;
}



/* 401320e8 FUN_401320e8 */

/* Boundary evidence: original MIPS .pdata 401320e8..4013213b. Semantic name remains unreviewed. */

void FUN_401320e8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4013213c FUN_4013213c */

/* Boundary evidence: original MIPS .pdata 4013213c..40132177. Semantic name remains unreviewed. */

void FUN_4013213c(void)

{
  FUN_401320e8((undefined4 *)&DAT_40131008,(undefined4 *)&DAT_4013100c);
  FUN_401320e8((undefined4 *)&DAT_40131000,(undefined4 *)&DAT_40131004);
  return;
}



/* 40132178 FUN_40132178 */

/* Boundary evidence: original MIPS .pdata 40132178..401321eb. Semantic name remains unreviewed. */

void FUN_40132178(void)

{
  uint uVar1;
  
  if ((DAT_40133048 == 0) || (DAT_40133048 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40133048 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40133048 == 0) {
      DAT_40133048 = 0xb064;
    }
  }
  DAT_4013304c = ~DAT_40133048;
  return;
}


