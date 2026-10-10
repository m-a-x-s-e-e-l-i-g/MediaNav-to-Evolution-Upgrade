/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011268 FUN_00011268 */

/* Boundary evidence: original MIPS .pdata 00011268..000112d7. Semantic name remains unreviewed. */

bool FUN_00011268(LPCWSTR param_1)

{
  HANDLE hObject;
  
  hObject = CreateFileW(param_1,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  CloseHandle(hObject);
  return hObject != (HANDLE)0xffffffff;
}



/* 000112d8 FUN_000112d8 */

/* Boundary evidence: original MIPS .pdata 000112d8..0001134b. Semantic name remains unreviewed. */

bool FUN_000112d8(LPCWSTR param_1)

{
  BOOL BVar1;
  _PROCESS_INFORMATION _Stack_18;
  
  memset(&_Stack_18,0,0x10);
  BVar1 = CreateProcessW(param_1,(LPWSTR)0x0,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0
                         ,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,&_Stack_18);
  return BVar1 != 0;
}



/* 0001134c FUN_0001134c */

/* Boundary evidence: original MIPS .pdata 0001134c..000113f3. Semantic name remains unreviewed. */

void FUN_0001134c(void)

{
  HANDLE hDevice;
  undefined1 local_10 [8];
  
  hDevice = CreateFileW(L"MGR1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hDevice != (HANDLE)0xffffffff) {
    local_10[0] = 1;
    DeviceIoControl(hDevice,3,local_10,1,(LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  return;
}



/* 000113f4 FUN_000113f4 */

/* Boundary evidence: original MIPS .pdata 000113f4..000114df. Semantic name remains unreviewed. */

void FUN_000113f4(void)

{
  bool bVar1;
  undefined3 extraout_var;
  char cVar2;
  wchar_t *pwVar3;
  
  cVar2 = -0x38;
  FUN_0001134c();
  NKDbgPrintfW(L"[LAUNCHER] Searching Startup...");
  pwVar3 = L"\\Storage Card\\System\\dboot.exe";
  do {
    cVar2 = cVar2 + -1;
    bVar1 = FUN_00011268(L"\\Storage Card\\System\\dboot.exe");
    if (CONCAT31(extraout_var,bVar1) != 0) {
      NKDbgPrintfW(L"Found Startup\r\n");
      break;
    }
    Sleep(10);
    NKDbgPrintfW(&DAT_0001117c);
  } while (cVar2 != '\0');
  if (cVar2 == '\0') {
    NKDbgPrintfW(L"[LAUNCHER] Launching UpgMgr\r\n");
    Sleep(10);
    pwVar3 = L"\\Storage Card\\System\\UpgradeManager.exe";
  }
  else {
    NKDbgPrintfW(L"[LAUNCHER] Launching startup.\r\n");
  }
  FUN_000112d8(pwVar3);
  return;
}



/* 000114e0 FUN_000114e0 */

/* Boundary evidence: original MIPS .pdata 000114e0..0001150b. Semantic name remains unreviewed. */

undefined4 FUN_000114e0(void)

{
  NKDbgPrintfW(L"[LAUNCHER] ULC launcher started. (Nov 27 2014 at 15:50:14)\r\n");
  FUN_000113f4();
  return 1;
}



/* 0001152c FUN_0001152c */

/* Boundary evidence: original MIPS .pdata 0001152c..000115bf. Semantic name remains unreviewed. */

void FUN_0001152c(void)

{
  UINT UVar1;
  
  FUN_000118f8();
  UVar1 = FUN_000114e0();
  FUN_00011838(UVar1);
  FUN_00011858(UVar1);
  return;
}



/* 000115c0 FUN_000115c0 */

/* Boundary evidence: original MIPS .pdata 000115c0..000115ff. Semantic name remains unreviewed. */

void FUN_000115c0(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00011600 entry */

/* Boundary evidence: original MIPS .pdata 00011600..0001165b. Semantic name remains unreviewed. */

void entry(void)

{
  FUN_0001165c();
  FUN_0001152c();
  return;
}



/* 0001165c FUN_0001165c */

/* Boundary evidence: original MIPS .pdata 0001165c..000116cf. Semantic name remains unreviewed. */

void FUN_0001165c(void)

{
  uint uVar1;
  
  if ((DAT_00012040 == 0) || (DAT_00012040 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00012040 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00012040 == 0) {
      DAT_00012040 = 0xb064;
    }
  }
  DAT_00012044 = ~DAT_00012040;
  return;
}



/* 000116d0 FUN_000116d0 */

/* Boundary evidence: original MIPS .pdata 000116d0..00011717. Semantic name remains unreviewed. */

void FUN_000116d0(uint param_1)

{
  if ((param_1 == DAT_00012040) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00011718 FUN_00011718 */

/* Boundary evidence: original MIPS .pdata 00011718..00011837. Semantic name remains unreviewed. */

void FUN_00011718(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0001209c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000120a4;
    if (DAT_000120a4 != (undefined4 *)0x0) {
      while (DAT_000120a0 = DAT_000120a0 + -1, _Memory <= DAT_000120a0) {
        if ((code *)*DAT_000120a0 != (code *)0x0) {
          (*(code *)*DAT_000120a0)();
          _Memory = DAT_000120a4;
        }
      }
      free(_Memory);
      DAT_000120a0 = (undefined4 *)0x0;
      DAT_000120a4 = (undefined4 *)0x0;
    }
    FUN_000118a4((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_000118a4((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_000120a8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011838 FUN_00011838 */

/* Boundary evidence: original MIPS .pdata 00011838..00011857. Semantic name remains unreviewed. */

void FUN_00011838(UINT param_1)

{
  FUN_00011718(param_1,0,0);
  return;
}



/* 00011858 FUN_00011858 */

/* Boundary evidence: original MIPS .pdata 00011858..000118a3. Semantic name remains unreviewed. */

void FUN_00011858(UINT param_1)

{
  DAT_0001209c = 0;
  FUN_000118a4((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000118a4 FUN_000118a4 */

/* Boundary evidence: original MIPS .pdata 000118a4..000118f7. Semantic name remains unreviewed. */

void FUN_000118a4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 000118f8 FUN_000118f8 */

/* Boundary evidence: original MIPS .pdata 000118f8..00011933. Semantic name remains unreviewed. */

void FUN_000118f8(void)

{
  FUN_000118a4((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_000118a4((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}


