/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 0001108c FUN_0001108c */

/* Boundary evidence: original MIPS .pdata 0001108c..0001111f. Semantic name remains unreviewed. */

void FUN_0001108c(undefined4 param_1,undefined4 param_2,wchar_t *param_3)

{
  UINT UVar1;
  
  FUN_0001139c();
  UVar1 = FUN_000114bc(param_1,param_2,param_3);
  FUN_000112dc(UVar1);
  FUN_000112fc(UVar1);
  return;
}



/* 00011120 FUN_00011120 */

/* Boundary evidence: original MIPS .pdata 00011120..0001115f. Semantic name remains unreviewed. */

void FUN_00011120(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00011160 entry */

/* Boundary evidence: original MIPS .pdata 00011160..000111bb. Semantic name remains unreviewed. */

void entry(undefined4 param_1,undefined4 param_2,wchar_t *param_3)

{
  FUN_000113d8();
  FUN_0001108c(param_1,param_2,param_3);
  return;
}



/* 000111bc FUN_000111bc */

/* Boundary evidence: original MIPS .pdata 000111bc..000112db. Semantic name remains unreviewed. */

void FUN_000111bc(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00012048 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00012050;
    if (DAT_00012050 != (undefined4 *)0x0) {
      while (DAT_0001204c = DAT_0001204c + -1, _Memory <= DAT_0001204c) {
        if ((code *)*DAT_0001204c != (code *)0x0) {
          (*(code *)*DAT_0001204c)();
          _Memory = DAT_00012050;
        }
      }
      free(_Memory);
      DAT_0001204c = (undefined4 *)0x0;
      DAT_00012050 = (undefined4 *)0x0;
    }
    FUN_00011348((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_00011348((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_00012054,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 000112dc FUN_000112dc */

/* Boundary evidence: original MIPS .pdata 000112dc..000112fb. Semantic name remains unreviewed. */

void FUN_000112dc(UINT param_1)

{
  FUN_000111bc(param_1,0,0);
  return;
}



/* 000112fc FUN_000112fc */

/* Boundary evidence: original MIPS .pdata 000112fc..00011347. Semantic name remains unreviewed. */

void FUN_000112fc(UINT param_1)

{
  DAT_00012048 = 0;
  FUN_00011348((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00011348 FUN_00011348 */

/* Boundary evidence: original MIPS .pdata 00011348..0001139b. Semantic name remains unreviewed. */

void FUN_00011348(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 0001139c FUN_0001139c */

/* Boundary evidence: original MIPS .pdata 0001139c..000113d7. Semantic name remains unreviewed. */

void FUN_0001139c(void)

{
  FUN_00011348((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_00011348((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 000113d8 FUN_000113d8 */

/* Boundary evidence: original MIPS .pdata 000113d8..0001144b. Semantic name remains unreviewed. */

void FUN_000113d8(void)

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



/* 000114bc FUN_000114bc */

/* Boundary evidence: original MIPS .pdata 000114bc..00011623. Semantic name remains unreviewed. */

undefined4 FUN_000114bc(undefined4 param_1,undefined4 param_2,wchar_t *param_3)

{
  LSTATUS LVar1;
  long lVar2;
  int iVar3;
  DWORD local_240;
  HKEY local_23c;
  DWORD local_238 [2];
  wchar_t *local_230;
  BYTE *local_22c;
  DWORD local_228;
  undefined4 local_224;
  BYTE aBStack_220 [510];
  undefined2 local_22;
  uint local_20;
  
  local_20 = DAT_00012040;
  iVar3 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Services",0,0,&local_23c);
  if (LVar1 == 0) {
    local_240 = 0x200;
    LVar1 = RegQueryValueExW(local_23c,L"BusName",(LPDWORD)0x0,local_238,aBStack_220,&local_240);
    if ((LVar1 == 0) && (local_238[0] == 1)) {
      local_22c = aBStack_220;
      iVar3 = 1;
      local_22 = 0;
      local_230 = L"BusName";
      local_224 = 1;
      local_228 = local_240;
    }
    RegCloseKey(local_23c);
    if (iVar3 != 0) {
      ActivateDeviceEx(L"Services",&local_230,iVar3,0);
      goto LAB_000115d4;
    }
  }
  ActivateDevice(L"Services",0);
LAB_000115d4:
  if (param_3 == (wchar_t *)0x0) {
    lVar2 = 0x3c;
  }
  else {
    lVar2 = _wtol(param_3);
  }
  SignalStarted(lVar2);
  FUN_000116a4(local_20);
  return 1;
}



/* 00011624 FUN_00011624 */

/* Boundary evidence: original MIPS .pdata 00011624..00011677. Semantic name remains unreviewed. */

void FUN_00011624(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_000116a4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00011678 FUN_00011678 */

/* Boundary evidence: original MIPS .pdata 00011678..000116a3. Semantic name remains unreviewed. */

undefined4 FUN_00011678(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00011624(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 000116a4 FUN_000116a4 */

/* Boundary evidence: original MIPS .pdata 000116a4..000116eb. Semantic name remains unreviewed. */

void FUN_000116a4(uint param_1)

{
  if ((param_1 == DAT_00012040) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


