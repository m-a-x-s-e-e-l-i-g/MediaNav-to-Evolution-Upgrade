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
    if (DAT_1000302c != (code *)0x0) {
      iVar2 = (*DAT_1000302c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_100010b8;
    FUN_1000133c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_10001000();
  }
LAB_100010b8:
  if (((param_2 == 0) && (FUN_100012c4(), iVar1 != 0)) && (DAT_1000302c != (code *)0x0)) {
    iVar1 = (*DAT_1000302c)(param_1,0,param_3);
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
    FUN_10001388();
  }
  FUN_10001008(param_1,param_2,param_3);
  return;
}



/* 100011d8 FUN_100011d8 */

/* Boundary evidence: original MIPS .pdata 100011d8..100012c3. Semantic name remains unreviewed. */

void FUN_100011d8(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_10003020 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_10003028;
    if (DAT_10003028 != (undefined4 *)0x0) {
      while (DAT_10003024 = DAT_10003024 + -1, _Memory <= DAT_10003024) {
        if ((code *)*DAT_10003024 != (code *)0x0) {
          (*(code *)*DAT_10003024)();
          _Memory = DAT_10003028;
        }
      }
      free(_Memory);
      DAT_10003024 = (undefined4 *)0x0;
      DAT_10003028 = (undefined4 *)0x0;
    }
    FUN_100012e8((undefined4 *)&DAT_10002010,(undefined4 *)&DAT_10002014);
  }
  FUN_100012e8((undefined4 *)&DAT_10002018,(undefined4 *)&DAT_1000201c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 100012c4 FUN_100012c4 */

/* Boundary evidence: original MIPS .pdata 100012c4..100012e7. Semantic name remains unreviewed. */

void FUN_100012c4(void)

{
  FUN_100011d8(0,0,1);
  return;
}



/* 100012e8 FUN_100012e8 */

/* Boundary evidence: original MIPS .pdata 100012e8..1000133b. Semantic name remains unreviewed. */

void FUN_100012e8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 1000133c FUN_1000133c */

/* Boundary evidence: original MIPS .pdata 1000133c..10001377. Semantic name remains unreviewed. */

void FUN_1000133c(void)

{
  FUN_100012e8((undefined4 *)&DAT_10002008,(undefined4 *)&DAT_1000200c);
  FUN_100012e8((undefined4 *)&DAT_10002000,(undefined4 *)&DAT_10002004);
  return;
}



/* 10001388 FUN_10001388 */

/* Boundary evidence: original MIPS .pdata 10001388..100013fb. Semantic name remains unreviewed. */

void FUN_10001388(void)

{
  uint uVar1;
  
  if ((DAT_10003018 == 0) || (DAT_10003018 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_10003018 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_10003018 == 0) {
      DAT_10003018 = 0xb064;
    }
  }
  DAT_1000301c = ~DAT_10003018;
  return;
}


