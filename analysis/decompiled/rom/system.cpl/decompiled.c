/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40851064 KillAllApps */

undefined4 KillAllApps(void)

{
                    /* 0x1064  1  KillAllApps */
  return 1;
}



/* 4085106c FUN_4085106c */

/* Boundary evidence: original MIPS .pdata 4085106c..408511a7. Semantic name remains unreviewed. */

int FUN_4085106c(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40852038 != (code *)0x0) {
      iVar2 = (*DAT_40852038)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_4085111c;
    FUN_408513c4();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = KillAllApps();
  }
LAB_4085111c:
  if (((param_2 == 0) && (FUN_4085134c(), iVar1 != 0)) && (DAT_40852038 != (code *)0x0)) {
    iVar1 = (*DAT_40852038)(param_1,0,param_3);
  }
  return iVar1;
}



/* 408511a8 FUN_408511a8 */

/* Boundary evidence: original MIPS .pdata 408511a8..408511d3. Semantic name remains unreviewed. */

void FUN_408511a8(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 408511d4 entry */

/* Boundary evidence: original MIPS .pdata 408511d4..4085122b. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40851400();
  }
  FUN_4085106c(param_1,param_2,param_3);
  return;
}



/* 4085122c FUN_4085122c */

/* Boundary evidence: original MIPS .pdata 4085122c..4085134b. Semantic name remains unreviewed. */

void FUN_4085122c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_40852028 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40852030;
    if (DAT_40852030 != (undefined4 *)0x0) {
      while (DAT_4085202c = DAT_4085202c + -1, _Memory <= DAT_4085202c) {
        if ((code *)*DAT_4085202c != (code *)0x0) {
          (*(code *)*DAT_4085202c)();
          _Memory = DAT_40852030;
        }
      }
      free(_Memory);
      DAT_4085202c = (undefined4 *)0x0;
      DAT_40852030 = (undefined4 *)0x0;
    }
    FUN_40851370((undefined4 *)&DAT_40851010,(undefined4 *)&DAT_40851014);
  }
  FUN_40851370((undefined4 *)&DAT_40851018,(undefined4 *)&DAT_4085101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_40852034,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 4085134c FUN_4085134c */

/* Boundary evidence: original MIPS .pdata 4085134c..4085136f. Semantic name remains unreviewed. */

void FUN_4085134c(void)

{
  FUN_4085122c(0,0,1);
  return;
}



/* 40851370 FUN_40851370 */

/* Boundary evidence: original MIPS .pdata 40851370..408513c3. Semantic name remains unreviewed. */

void FUN_40851370(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 408513c4 FUN_408513c4 */

/* Boundary evidence: original MIPS .pdata 408513c4..408513ff. Semantic name remains unreviewed. */

void FUN_408513c4(void)

{
  FUN_40851370((undefined4 *)&DAT_40851008,(undefined4 *)&DAT_4085100c);
  FUN_40851370((undefined4 *)&DAT_40851000,(undefined4 *)&DAT_40851004);
  return;
}



/* 40851400 FUN_40851400 */

/* Boundary evidence: original MIPS .pdata 40851400..40851473. Semantic name remains unreviewed. */

void FUN_40851400(void)

{
  uint uVar1;
  
  if ((DAT_40852020 == 0) || (DAT_40852020 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40852020 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40852020 == 0) {
      DAT_40852020 = 0xb064;
    }
  }
  DAT_40852024 = ~DAT_40852020;
  return;
}


