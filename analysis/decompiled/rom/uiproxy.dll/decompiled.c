/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 403e1060 UIP_Close */

undefined4 UIP_Close(void)

{
                    /* 0x1060  1  UIP_Close
                       0x1060  2  UIP_Deinit
                       0x1060  4  UIP_Init
                       0x1060  5  UIP_Open */
  return 1;
}



/* 403e1068 UIP_Read */

undefined4 UIP_Read(void)

{
                    /* 0x1068  8  UIP_Read
                       0x1068  9  UIP_Seek
                       0x1068  10  UIP_Write */
  return 0;
}



/* 403e1070 UIP_PowerDown */

void UIP_PowerDown(void)

{
                    /* 0x1070  6  UIP_PowerDown
                       0x1070  7  UIP_PowerUp */
  return;
}



/* 403e1078 FUN_403e1078 */

/* Boundary evidence: original MIPS .pdata 403e1078..403e1237. Semantic name remains unreviewed. */

DWORD FUN_403e1078(undefined4 *param_1)

{
  code *pcVar1;
  LPCWSTR lpLibFileName;
  DWORD DVar2;
  HMODULE hLibModule;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  hLibModule = (HMODULE)0x0;
  DVar2 = 0;
  piVar4 = (int *)*param_1;
  lpLibFileName = (LPCWSTR)(piVar4 + 3);
  iVar3 = *piVar4 + (int)lpLibFileName;
  uVar5 = piVar4[1] + iVar3 + 7U & 0xfffffff8;
  if ((((lpLibFileName == (LPCWSTR)0x0) || (iVar3 == 0)) || (uVar5 == 0)) ||
     ((uint)param_1[3] < (uint)piVar4[2])) {
LAB_403e11c0:
    DVar2 = 0x57;
  }
  else {
    hLibModule = LoadLibraryW(lpLibFileName);
    if ((hLibModule != (HMODULE)0x0) &&
       (pcVar1 = (code *)GetProcAddressW(hLibModule,iVar3), pcVar1 != (code *)0x0)) {
      *(undefined4 *)param_1[4] = 0;
      iVar3 = (*pcVar1)(uVar5,piVar4[2],param_1[2],param_1[3],param_1[4]);
      if ((iVar3 != 0) && (*(uint *)param_1[4] <= (uint)param_1[3])) goto LAB_403e11c8;
      DVar2 = GetLastError();
      if (DVar2 == 0) goto LAB_403e11c0;
    }
    DVar2 = GetLastError();
  }
LAB_403e11c8:
  if (hLibModule != (HMODULE)0x0) {
    FreeLibrary(hLibModule);
  }
  return DVar2;
}



/* 403e1238 FUN_403e1238 */

/* Boundary evidence: original MIPS .pdata 403e1238..403e1243. Semantic name remains unreviewed. */

undefined4 FUN_403e1238(void)

{
  return 1;
}



/* 403e1244 UIP_IOControl */

/* Boundary evidence: original MIPS .pdata 403e1244..403e12e7. Semantic name remains unreviewed. */

bool UIP_IOControl(undefined4 param_1,int param_2,int param_3,uint param_4,int param_5,
                  undefined4 param_6,int param_7)

{
  DWORD dwErrCode;
  int local_28;
  uint local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  
                    /* 0x1244  3  UIP_IOControl */
  if ((((param_3 == 0) || (param_5 == 0)) || (param_7 == 0)) || ((param_2 != 1 || (param_4 < 0xc))))
  {
    dwErrCode = 0x57;
  }
  else {
    local_20 = param_5;
    local_1c = param_6;
    local_18 = param_7;
    local_28 = param_3;
    local_24 = param_4;
    dwErrCode = FUN_403e1078(&local_28);
  }
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* 403e12f8 FUN_403e12f8 */

/* Boundary evidence: original MIPS .pdata 403e12f8..403e1323. Semantic name remains unreviewed. */

undefined4 FUN_403e12f8(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 403e1324 FUN_403e1324 */

/* Boundary evidence: original MIPS .pdata 403e1324..403e145f. Semantic name remains unreviewed. */

int FUN_403e1324(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_403e2050 != (code *)0x0) {
      iVar2 = (*DAT_403e2050)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_403e13d4;
    FUN_403e167c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_403e12f8(param_1,param_2);
  }
LAB_403e13d4:
  if (((param_2 == 0) && (FUN_403e1604(), iVar1 != 0)) && (DAT_403e2050 != (code *)0x0)) {
    iVar1 = (*DAT_403e2050)(param_1,0,param_3);
  }
  return iVar1;
}



/* 403e1460 FUN_403e1460 */

/* Boundary evidence: original MIPS .pdata 403e1460..403e148b. Semantic name remains unreviewed. */

void FUN_403e1460(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 403e148c entry */

/* Boundary evidence: original MIPS .pdata 403e148c..403e14e3. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_403e16b8();
  }
  FUN_403e1324(param_1,param_2,param_3);
  return;
}



/* 403e14e4 FUN_403e14e4 */

/* Boundary evidence: original MIPS .pdata 403e14e4..403e1603. Semantic name remains unreviewed. */

void FUN_403e14e4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_403e2040 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_403e2048;
    if (DAT_403e2048 != (undefined4 *)0x0) {
      while (DAT_403e2044 = DAT_403e2044 + -1, _Memory <= DAT_403e2044) {
        if ((code *)*DAT_403e2044 != (code *)0x0) {
          (*(code *)*DAT_403e2044)();
          _Memory = DAT_403e2048;
        }
      }
      free(_Memory);
      DAT_403e2044 = (undefined4 *)0x0;
      DAT_403e2048 = (undefined4 *)0x0;
    }
    FUN_403e1628((undefined4 *)&DAT_403e1010,(undefined4 *)&DAT_403e1014);
  }
  FUN_403e1628((undefined4 *)&DAT_403e1018,(undefined4 *)&DAT_403e101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_403e204c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 403e1604 FUN_403e1604 */

/* Boundary evidence: original MIPS .pdata 403e1604..403e1627. Semantic name remains unreviewed. */

void FUN_403e1604(void)

{
  FUN_403e14e4(0,0,1);
  return;
}



/* 403e1628 FUN_403e1628 */

/* Boundary evidence: original MIPS .pdata 403e1628..403e167b. Semantic name remains unreviewed. */

void FUN_403e1628(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 403e167c FUN_403e167c */

/* Boundary evidence: original MIPS .pdata 403e167c..403e16b7. Semantic name remains unreviewed. */

void FUN_403e167c(void)

{
  FUN_403e1628((undefined4 *)&DAT_403e1008,(undefined4 *)&DAT_403e100c);
  FUN_403e1628((undefined4 *)&DAT_403e1000,(undefined4 *)&DAT_403e1004);
  return;
}



/* 403e16b8 FUN_403e16b8 */

/* Boundary evidence: original MIPS .pdata 403e16b8..403e172b. Semantic name remains unreviewed. */

void FUN_403e16b8(void)

{
  uint uVar1;
  
  if ((DAT_403e2038 == 0) || (DAT_403e2038 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_403e2038 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_403e2038 == 0) {
      DAT_403e2038 = 0xb064;
    }
  }
  DAT_403e203c = ~DAT_403e2038;
  return;
}


