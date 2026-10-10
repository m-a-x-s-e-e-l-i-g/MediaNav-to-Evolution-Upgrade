/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 4065108c FUN_4065108c */

undefined4 FUN_4065108c(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_40652038 = param_1;
  }
  return 1;
}



/* 406510a8 CPlApplet */

/* Boundary evidence: original MIPS .pdata 406510a8..406511f7. Semantic name remains unreviewed. */

undefined4 CPlApplet(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  HICON pHVar1;
  BOOL BVar2;
  undefined4 uVar3;
  _PROCESS_INFORMATION local_20;
  
                    /* 0x10a8  1  CPlApplet */
  uVar3 = 1;
  if ((param_2 != 1) && (param_2 != 2)) {
    if (param_2 == 5) {
      local_20.hProcess = (HANDLE)0x0;
      memset(&local_20.hThread,0,0xc);
      BVar2 = CreateProcessW(L"\\Windows\\connmc.exe",(LPWSTR)0x0,(LPSECURITY_ATTRIBUTES)0x0,
                             (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                             (LPSTARTUPINFOW)0x0,&local_20);
      if (BVar2 == 0) {
        return 1;
      }
      CloseHandle(local_20.hThread);
      CloseHandle(local_20.hProcess);
    }
    else if (param_2 == 8) {
      if (param_4 == (undefined4 *)0x0) {
        return 1;
      }
      *param_4 = 0x1d4;
      param_4[1] = 0;
      param_4[2] = 0;
      param_4[3] = 3000;
      pHVar1 = LoadIconW(DAT_40652038,(LPCWSTR)0xbb8);
      param_4[4] = pHVar1;
      LoadStringW(DAT_40652038,6000,(LPWSTR)(param_4 + 5),0x20);
      LoadStringW(DAT_40652038,0x1771,(LPWSTR)(param_4 + 0x15),0x40);
      wcscpy((wchar_t *)(param_4 + 0x35),L"");
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* 40651228 entry */

/* Boundary evidence: original MIPS .pdata 40651228..4065129b. Semantic name remains unreviewed. */

undefined4 entry(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_40651470();
    FUN_40651434();
  }
  uVar1 = FUN_4065108c(param_1,param_2);
  if (param_2 == 0) {
    FUN_406513bc();
  }
  return uVar1;
}



/* 4065129c FUN_4065129c */

/* Boundary evidence: original MIPS .pdata 4065129c..406513bb. Semantic name remains unreviewed. */

void FUN_4065129c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_4065203c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40652044;
    if (DAT_40652044 != (undefined4 *)0x0) {
      while (DAT_40652040 = DAT_40652040 + -1, _Memory <= DAT_40652040) {
        if ((code *)*DAT_40652040 != (code *)0x0) {
          (*(code *)*DAT_40652040)();
          _Memory = DAT_40652044;
        }
      }
      free(_Memory);
      DAT_40652040 = (undefined4 *)0x0;
      DAT_40652044 = (undefined4 *)0x0;
    }
    FUN_406513e0((undefined4 *)&DAT_40651010,(undefined4 *)&DAT_40651014);
  }
  FUN_406513e0((undefined4 *)&DAT_40651018,(undefined4 *)&DAT_4065101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_40652048,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 406513bc FUN_406513bc */

/* Boundary evidence: original MIPS .pdata 406513bc..406513df. Semantic name remains unreviewed. */

void FUN_406513bc(void)

{
  FUN_4065129c(0,0,1);
  return;
}



/* 406513e0 FUN_406513e0 */

/* Boundary evidence: original MIPS .pdata 406513e0..40651433. Semantic name remains unreviewed. */

void FUN_406513e0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40651434 FUN_40651434 */

/* Boundary evidence: original MIPS .pdata 40651434..4065146f. Semantic name remains unreviewed. */

void FUN_40651434(void)

{
  FUN_406513e0((undefined4 *)&DAT_40651008,(undefined4 *)&DAT_4065100c);
  FUN_406513e0((undefined4 *)&DAT_40651000,(undefined4 *)&DAT_40651004);
  return;
}



/* 40651470 FUN_40651470 */

/* Boundary evidence: original MIPS .pdata 40651470..406514e3. Semantic name remains unreviewed. */

void FUN_40651470(void)

{
  uint uVar1;
  
  if ((DAT_40652030 == 0) || (DAT_40652030 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40652030 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40652030 == 0) {
      DAT_40652030 = 0xb064;
    }
  }
  DAT_40652034 = ~DAT_40652030;
  return;
}


