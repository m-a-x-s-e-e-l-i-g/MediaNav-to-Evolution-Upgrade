/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c07f1060 FUN_c07f1060 */

/* Boundary evidence: original MIPS .pdata c07f1060..c07f1093. Semantic name remains unreviewed. */

undefined4 FUN_c07f1060(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c07f1094 GPINTR_Deinit */

/* Boundary evidence: original MIPS .pdata c07f1094..c07f10c7. Semantic name remains unreviewed. */

undefined4 GPINTR_Deinit(HLOCAL param_1)

{
                    /* 0x1094  2  GPINTR_Deinit */
  DeleteCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 4));
  LocalFree(param_1);
  return 1;
}



/* c07f10c8 GPINTR_Init */

/* Boundary evidence: original MIPS .pdata c07f10c8..c07f1107. Semantic name remains unreviewed. */

HLOCAL GPINTR_Init(void)

{
  HLOCAL pvVar1;
  
                    /* 0x10c8  7  GPINTR_Init */
  pvVar1 = LocalAlloc(0x40,0x18);
  if (pvVar1 != (HLOCAL)0x0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 4));
  }
  return pvVar1;
}



/* c07f1108 GPINTR_Open */

undefined4 GPINTR_Open(undefined4 param_1)

{
                    /* 0x1108  8  GPINTR_Open */
  return param_1;
}



/* c07f1110 GPINTR_Close */

undefined4 GPINTR_Close(void)

{
                    /* 0x1110  1  GPINTR_Close
                       0x1110  6  GPINTR_IOControl
                       0x1110  11  GPINTR_Read
                       0x1110  12  GPINTR_Seek
                       0x1110  15  GPINTR_Write */
  return 0;
}



/* c07f1118 GPINTR_PowerDown */

void GPINTR_PowerDown(void)

{
                    /* 0x1118  9  GPINTR_PowerDown
                       0x1118  10  GPINTR_PowerUp */
  return;
}



/* c07f1120 GPINTR_SetPinOutputState */

/* Boundary evidence: original MIPS .pdata c07f1120..c07f1177. Semantic name remains unreviewed. */

void GPINTR_SetPinOutputState(undefined4 param_1,int param_2)

{
  undefined1 auStack_20 [8];
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1120  14  GPINTR_SetPinOutputState */
  if (param_2 == 1) {
    local_14 = 4;
  }
  else {
    local_14 = 2;
  }
  local_18 = param_1;
  KernelIoControl(0x1032c87,&local_18,0x10,0,0,auStack_20);
  return;
}



/* c07f1178 GPINTR_SetPinConfiguration */

/* Boundary evidence: original MIPS .pdata c07f1178..c07f11bf. Semantic name remains unreviewed. */

void GPINTR_SetPinConfiguration(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_20 [8];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* 0x1178  13  GPINTR_SetPinConfiguration */
  local_14 = 0x10;
  local_18 = param_1;
  local_10 = param_2;
  KernelIoControl(0x1032c87,&local_18,0x10,0,0,auStack_20);
  return;
}



/* c07f11c0 GPINTR_GetPinConfiguration */

/* Boundary evidence: original MIPS .pdata c07f11c0..c07f1207. Semantic name remains unreviewed. */

void GPINTR_GetPinConfiguration(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_20 [8];
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x11c0  3  GPINTR_GetPinConfiguration */
  local_14 = 8;
  local_18 = param_1;
  KernelIoControl(0x1032c87,&local_18,0x10,param_2,4,auStack_20);
  return;
}



/* c07f1208 GPINTR_GetPinState */

/* Boundary evidence: original MIPS .pdata c07f1208..c07f124f. Semantic name remains unreviewed. */

void GPINTR_GetPinState(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_20 [8];
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1208  5  GPINTR_GetPinState */
  local_14 = 1;
  local_18 = param_1;
  KernelIoControl(0x1032c87,&local_18,0x10,param_2,4,auStack_20);
  return;
}



/* c07f1250 GPINTR_GetPinResetValue */

/* Boundary evidence: original MIPS .pdata c07f1250..c07f1297. Semantic name remains unreviewed. */

void GPINTR_GetPinResetValue(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_20 [8];
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1250  4  GPINTR_GetPinResetValue */
  local_14 = 0x20;
  local_18 = param_1;
  KernelIoControl(0x1032c87,&local_18,0x10,param_2,4,auStack_20);
  return;
}



/* c07f12e8 FUN_c07f12e8 */

/* Boundary evidence: original MIPS .pdata c07f12e8..c07f1423. Semantic name remains unreviewed. */

int FUN_c07f12e8(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c07f204c != (code *)0x0) {
      iVar2 = (*DAT_c07f204c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c07f1398;
    FUN_c07f1640();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c07f1060(param_1,param_2);
  }
LAB_c07f1398:
  if (((param_2 == 0) && (FUN_c07f15c8(), iVar1 != 0)) && (DAT_c07f204c != (code *)0x0)) {
    iVar1 = (*DAT_c07f204c)(param_1,0,param_3);
  }
  return iVar1;
}



/* c07f1424 FUN_c07f1424 */

/* Boundary evidence: original MIPS .pdata c07f1424..c07f144f. Semantic name remains unreviewed. */

void FUN_c07f1424(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c07f1450 entry */

/* Boundary evidence: original MIPS .pdata c07f1450..c07f14a7. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c07f167c();
  }
  FUN_c07f12e8(param_1,param_2,param_3);
  return;
}



/* c07f14a8 FUN_c07f14a8 */

/* Boundary evidence: original MIPS .pdata c07f14a8..c07f15c7. Semantic name remains unreviewed. */

void FUN_c07f14a8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c07f203c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c07f2044;
    if (DAT_c07f2044 != (undefined4 *)0x0) {
      while (DAT_c07f2040 = DAT_c07f2040 + -1, _Memory <= DAT_c07f2040) {
        if ((code *)*DAT_c07f2040 != (code *)0x0) {
          (*(code *)*DAT_c07f2040)();
          _Memory = DAT_c07f2044;
        }
      }
      free(_Memory);
      DAT_c07f2040 = (undefined4 *)0x0;
      DAT_c07f2044 = (undefined4 *)0x0;
    }
    FUN_c07f15ec((undefined4 *)&DAT_c07f1010,(undefined4 *)&DAT_c07f1014);
  }
  FUN_c07f15ec((undefined4 *)&DAT_c07f1018,(undefined4 *)&DAT_c07f101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c07f2048,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c07f15c8 FUN_c07f15c8 */

/* Boundary evidence: original MIPS .pdata c07f15c8..c07f15eb. Semantic name remains unreviewed. */

void FUN_c07f15c8(void)

{
  FUN_c07f14a8(0,0,1);
  return;
}



/* c07f15ec FUN_c07f15ec */

/* Boundary evidence: original MIPS .pdata c07f15ec..c07f163f. Semantic name remains unreviewed. */

void FUN_c07f15ec(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c07f1640 FUN_c07f1640 */

/* Boundary evidence: original MIPS .pdata c07f1640..c07f167b. Semantic name remains unreviewed. */

void FUN_c07f1640(void)

{
  FUN_c07f15ec((undefined4 *)&DAT_c07f1008,(undefined4 *)&DAT_c07f100c);
  FUN_c07f15ec((undefined4 *)&DAT_c07f1000,(undefined4 *)&DAT_c07f1004);
  return;
}



/* c07f167c FUN_c07f167c */

/* Boundary evidence: original MIPS .pdata c07f167c..c07f16ef. Semantic name remains unreviewed. */

void FUN_c07f167c(void)

{
  uint uVar1;
  
  if ((DAT_c07f2034 == 0) || (DAT_c07f2034 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c07f2034 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c07f2034 == 0) {
      DAT_c07f2034 = 0xb064;
    }
  }
  DAT_c07f2038 = ~DAT_c07f2034;
  return;
}


