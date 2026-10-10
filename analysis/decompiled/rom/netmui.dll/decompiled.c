/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40241060 entry */

/* Boundary evidence: original MIPS .pdata 40241060..402410d3. Semantic name remains unreviewed. */

undefined4 entry(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_402412a8();
    FUN_4024126c();
  }
  uVar1 = FUN_4024133c();
  if (param_2 == 0) {
    FUN_402411f4();
  }
  return uVar1;
}



/* 402410d4 FUN_402410d4 */

/* Boundary evidence: original MIPS .pdata 402410d4..402411f3. Semantic name remains unreviewed. */

void FUN_402410d4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_40242020 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40242028;
    if (DAT_40242028 != (undefined4 *)0x0) {
      while (DAT_40242024 = DAT_40242024 + -1, _Memory <= DAT_40242024) {
        if ((code *)*DAT_40242024 != (code *)0x0) {
          (*(code *)*DAT_40242024)();
          _Memory = DAT_40242028;
        }
      }
      free(_Memory);
      DAT_40242024 = (undefined4 *)0x0;
      DAT_40242028 = (undefined4 *)0x0;
    }
    FUN_40241218((undefined4 *)&DAT_40241010,(undefined4 *)&DAT_40241014);
  }
  FUN_40241218((undefined4 *)&DAT_40241018,(undefined4 *)&DAT_4024101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_4024202c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 402411f4 FUN_402411f4 */

/* Boundary evidence: original MIPS .pdata 402411f4..40241217. Semantic name remains unreviewed. */

void FUN_402411f4(void)

{
  FUN_402410d4(0,0,1);
  return;
}



/* 40241218 FUN_40241218 */

/* Boundary evidence: original MIPS .pdata 40241218..4024126b. Semantic name remains unreviewed. */

void FUN_40241218(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4024126c FUN_4024126c */

/* Boundary evidence: original MIPS .pdata 4024126c..402412a7. Semantic name remains unreviewed. */

void FUN_4024126c(void)

{
  FUN_40241218((undefined4 *)&DAT_40241008,(undefined4 *)&DAT_4024100c);
  FUN_40241218((undefined4 *)&DAT_40241000,(undefined4 *)&DAT_40241004);
  return;
}



/* 402412a8 FUN_402412a8 */

/* Boundary evidence: original MIPS .pdata 402412a8..4024131b. Semantic name remains unreviewed. */

void FUN_402412a8(void)

{
  uint uVar1;
  
  if ((DAT_40242018 == 0) || (DAT_40242018 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40242018 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40242018 == 0) {
      DAT_40242018 = 0xb064;
    }
  }
  DAT_4024201c = ~DAT_40242018;
  return;
}



/* 4024133c FUN_4024133c */

undefined4 FUN_4024133c(void)

{
  return 1;
}


