/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 10001000 FUN_10001000 */

undefined4 FUN_10001000(void)

{
  return 1;
}



/* 10001008 FUN_10001008 */

/* Boundary evidence: original MIPS .pdata 10001008..10001143. Semantic name remains unreviewed. */

int FUN_10001008(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_10003038 != (code *)0x0) {
      iVar2 = (*DAT_10003038)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_100010b8;
    FUN_10001370();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_10001000();
  }
LAB_100010b8:
  if (((param_2 == 0) && (FUN_100012f8(), iVar1 != 0)) && (DAT_10003038 != (code *)0x0)) {
    iVar1 = (*DAT_10003038)(param_1,0,param_3);
  }
  return iVar1;
}



/* 10001144 FUN_10001144 */

/* Boundary evidence: original MIPS .pdata 10001144..1000116f. Semantic name remains unreviewed. */

void FUN_10001144(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 10001170 entry */

/* Boundary evidence: original MIPS .pdata 10001170..100011c7. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_100013bc();
  }
  FUN_10001008(param_1,param_2,param_3);
  return;
}



/* 100011d8 FUN_100011d8 */

/* Boundary evidence: original MIPS .pdata 100011d8..100012f7. Semantic name remains unreviewed. */

void FUN_100011d8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_10003028 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_10003030;
    if (DAT_10003030 != (undefined4 *)0x0) {
      while (DAT_1000302c = DAT_1000302c + -1, _Memory <= DAT_1000302c) {
        if ((code *)*DAT_1000302c != (code *)0x0) {
          (*(code *)*DAT_1000302c)();
          _Memory = DAT_10003030;
        }
      }
      free(_Memory);
      DAT_1000302c = (undefined4 *)0x0;
      DAT_10003030 = (undefined4 *)0x0;
    }
    FUN_1000131c((undefined4 *)&DAT_10002010,(undefined4 *)&DAT_10002014);
  }
  FUN_1000131c((undefined4 *)&DAT_10002018,(undefined4 *)&DAT_1000201c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_10003034,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 100012f8 FUN_100012f8 */

/* Boundary evidence: original MIPS .pdata 100012f8..1000131b. Semantic name remains unreviewed. */

void FUN_100012f8(void)

{
  FUN_100011d8(0,0,1);
  return;
}



/* 1000131c FUN_1000131c */

/* Boundary evidence: original MIPS .pdata 1000131c..1000136f. Semantic name remains unreviewed. */

void FUN_1000131c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 10001370 FUN_10001370 */

/* Boundary evidence: original MIPS .pdata 10001370..100013ab. Semantic name remains unreviewed. */

void FUN_10001370(void)

{
  FUN_1000131c((undefined4 *)&DAT_10002008,(undefined4 *)&DAT_1000200c);
  FUN_1000131c((undefined4 *)&DAT_10002000,(undefined4 *)&DAT_10002004);
  return;
}



/* 100013bc FUN_100013bc */

/* Boundary evidence: original MIPS .pdata 100013bc..1000142f. Semantic name remains unreviewed. */

void FUN_100013bc(void)

{
  uint uVar1;
  
  if ((DAT_10003020 == 0) || (DAT_10003020 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_10003020 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_10003020 == 0) {
      DAT_10003020 = 0xb064;
    }
  }
  DAT_10003024 = ~DAT_10003020;
  return;
}


