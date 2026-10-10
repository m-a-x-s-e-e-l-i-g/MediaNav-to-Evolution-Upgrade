/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 000110ec FUN_000110ec */

/* Boundary evidence: original MIPS .pdata 000110ec..0001117f. Semantic name remains unreviewed. */

void FUN_000110ec(void)

{
  UINT UVar1;
  
  FUN_000113fc();
  UVar1 = FUN_0001151c();
  FUN_0001133c(UVar1);
  FUN_0001135c(UVar1);
  return;
}



/* 00011180 FUN_00011180 */

/* Boundary evidence: original MIPS .pdata 00011180..000111bf. Semantic name remains unreviewed. */

void FUN_00011180(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 000111c0 entry */

/* Boundary evidence: original MIPS .pdata 000111c0..0001121b. Semantic name remains unreviewed. */

void entry(void)

{
  FUN_00011438();
  FUN_000110ec();
  return;
}



/* 0001121c FUN_0001121c */

/* Boundary evidence: original MIPS .pdata 0001121c..0001133b. Semantic name remains unreviewed. */

void FUN_0001121c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00012050 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00012058;
    if (DAT_00012058 != (undefined4 *)0x0) {
      while (DAT_00012054 = DAT_00012054 + -1, _Memory <= DAT_00012054) {
        if ((code *)*DAT_00012054 != (code *)0x0) {
          (*(code *)*DAT_00012054)();
          _Memory = DAT_00012058;
        }
      }
      free(_Memory);
      DAT_00012054 = (undefined4 *)0x0;
      DAT_00012058 = (undefined4 *)0x0;
    }
    FUN_000113a8((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_000113a8((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_0001205c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 0001133c FUN_0001133c */

/* Boundary evidence: original MIPS .pdata 0001133c..0001135b. Semantic name remains unreviewed. */

void FUN_0001133c(UINT param_1)

{
  FUN_0001121c(param_1,0,0);
  return;
}



/* 0001135c FUN_0001135c */

/* Boundary evidence: original MIPS .pdata 0001135c..000113a7. Semantic name remains unreviewed. */

void FUN_0001135c(UINT param_1)

{
  DAT_00012050 = 0;
  FUN_000113a8((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000113a8 FUN_000113a8 */

/* Boundary evidence: original MIPS .pdata 000113a8..000113fb. Semantic name remains unreviewed. */

void FUN_000113a8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 000113fc FUN_000113fc */

/* Boundary evidence: original MIPS .pdata 000113fc..00011437. Semantic name remains unreviewed. */

void FUN_000113fc(void)

{
  FUN_000113a8((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_000113a8((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00011438 FUN_00011438 */

/* Boundary evidence: original MIPS .pdata 00011438..000114ab. Semantic name remains unreviewed. */

void FUN_00011438(void)

{
  uint uVar1;
  
  if ((DAT_00012048 == 0) || (DAT_00012048 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00012048 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00012048 == 0) {
      DAT_00012048 = 0xb064;
    }
  }
  DAT_0001204c = ~DAT_00012048;
  return;
}



/* 0001151c FUN_0001151c */

/* Boundary evidence: original MIPS .pdata 0001151c..00011647. Semantic name remains unreviewed. */

undefined4 FUN_0001151c(void)

{
  HMODULE hLibModule;
  code *pcVar1;
  int iVar2;
  DWORD DVar3;
  wchar_t local_220 [260];
  uint local_18;
  
  local_18 = DAT_00012048;
  local_220[0] = L'\0';
  hLibModule = LoadLibraryW(L"coredll.dll");
  if (((hLibModule == (HMODULE)0x0) ||
      (pcVar1 = (code *)GetProcAddressW(hLibModule,L"SHGetSpecialFolderPath"), pcVar1 == (code *)0x0
      )) || (iVar2 = (*pcVar1)(0,local_220,7,0), iVar2 == 0)) {
    wcscpy(local_220,L"\\Windows\\StartUp");
  }
  wcscat(local_220,L"\\EventRst.Lnk");
  DVar3 = GetFileAttributesW(local_220);
  if (DVar3 != 0xffffffff) {
    CeEventHasOccurred(10,0);
    SetFileAttributesW(local_220,0x80);
    DeleteFileW(local_220);
  }
  if (hLibModule != (HMODULE)0x0) {
    FreeLibrary(hLibModule);
  }
  FUN_000116c8(local_18);
  return 0;
}



/* 00011648 FUN_00011648 */

/* Boundary evidence: original MIPS .pdata 00011648..0001169b. Semantic name remains unreviewed. */

void FUN_00011648(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_000116c8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 0001169c FUN_0001169c */

/* Boundary evidence: original MIPS .pdata 0001169c..000116c7. Semantic name remains unreviewed. */

undefined4 FUN_0001169c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00011648(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 000116c8 FUN_000116c8 */

/* Boundary evidence: original MIPS .pdata 000116c8..0001170f. Semantic name remains unreviewed. */

void FUN_000116c8(uint param_1)

{
  if ((param_1 == DAT_00012048) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


