/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c02b1060 DevMainEntry */

/* Boundary evidence: original MIPS .pdata c02b1060..c02b1083. Semantic name remains unreviewed. */

void DevMainEntry(undefined4 param_1)

{
                    /* 0x1060  2  DevMainEntry */
  StartDeviceManager(param_1,0,0,0);
  return;
}



/* c02b10a4 FUN_c02b10a4 */

/* Boundary evidence: original MIPS .pdata c02b10a4..c02b10cf. Semantic name remains unreviewed. */

undefined4 FUN_c02b10a4(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c02b10d0 FUN_c02b10d0 */

/* Boundary evidence: original MIPS .pdata c02b10d0..c02b120b. Semantic name remains unreviewed. */

int FUN_c02b10d0(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c02b2044 != (code *)0x0) {
      iVar2 = (*DAT_c02b2044)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c02b1180;
    FUN_c02b1428();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c02b10a4(param_1,param_2);
  }
LAB_c02b1180:
  if (((param_2 == 0) && (FUN_c02b13b0(), iVar1 != 0)) && (DAT_c02b2044 != (code *)0x0)) {
    iVar1 = (*DAT_c02b2044)(param_1,0,param_3);
  }
  return iVar1;
}



/* c02b120c FUN_c02b120c */

/* Boundary evidence: original MIPS .pdata c02b120c..c02b1237. Semantic name remains unreviewed. */

void FUN_c02b120c(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c02b1238 entry */

/* Boundary evidence: original MIPS .pdata c02b1238..c02b128f. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c02b1464();
  }
  FUN_c02b10d0(param_1,param_2,param_3);
  return;
}



/* c02b1290 FUN_c02b1290 */

/* Boundary evidence: original MIPS .pdata c02b1290..c02b13af. Semantic name remains unreviewed. */

void FUN_c02b1290(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c02b2034 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c02b203c;
    if (DAT_c02b203c != (undefined4 *)0x0) {
      while (DAT_c02b2038 = DAT_c02b2038 + -1, _Memory <= DAT_c02b2038) {
        if ((code *)*DAT_c02b2038 != (code *)0x0) {
          (*(code *)*DAT_c02b2038)();
          _Memory = DAT_c02b203c;
        }
      }
      free(_Memory);
      DAT_c02b2038 = (undefined4 *)0x0;
      DAT_c02b203c = (undefined4 *)0x0;
    }
    FUN_c02b13d4((undefined4 *)&DAT_c02b1010,(undefined4 *)&DAT_c02b1014);
  }
  FUN_c02b13d4((undefined4 *)&DAT_c02b1018,(undefined4 *)&DAT_c02b101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c02b2040,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c02b13b0 FUN_c02b13b0 */

/* Boundary evidence: original MIPS .pdata c02b13b0..c02b13d3. Semantic name remains unreviewed. */

void FUN_c02b13b0(void)

{
  FUN_c02b1290(0,0,1);
  return;
}



/* c02b13d4 FUN_c02b13d4 */

/* Boundary evidence: original MIPS .pdata c02b13d4..c02b1427. Semantic name remains unreviewed. */

void FUN_c02b13d4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c02b1428 FUN_c02b1428 */

/* Boundary evidence: original MIPS .pdata c02b1428..c02b1463. Semantic name remains unreviewed. */

void FUN_c02b1428(void)

{
  FUN_c02b13d4((undefined4 *)&DAT_c02b1008,(undefined4 *)&DAT_c02b100c);
  FUN_c02b13d4((undefined4 *)&DAT_c02b1000,(undefined4 *)&DAT_c02b1004);
  return;
}



/* c02b1464 FUN_c02b1464 */

/* Boundary evidence: original MIPS .pdata c02b1464..c02b14d7. Semantic name remains unreviewed. */

void FUN_c02b1464(void)

{
  uint uVar1;
  
  if ((DAT_c02b202c == 0) || (DAT_c02b202c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c02b202c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c02b202c == 0) {
      DAT_c02b202c = 0xb064;
    }
  }
  DAT_c02b2030 = ~DAT_c02b202c;
  return;
}


