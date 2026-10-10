/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c00110b4 DllMain */

/* Boundary evidence: original MIPS .pdata c00110b4..c00110f7. Semantic name remains unreviewed. */

undefined4 DllMain(HMODULE param_1,int param_2,undefined4 param_3)

{
                    /* 0x10b4  1  DllMain */
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    DAT_c0012048 = param_3;
  }
  return 1;
}



/* c00110f8 FUN_c00110f8 */

/* Boundary evidence: original MIPS .pdata c00110f8..c00112ab. Semantic name remains unreviewed. */

bool FUN_c00110f8(undefined4 *param_1)

{
  bool bVar1;
  LSTATUS LVar2;
  HKEY local_38;
  DWORD local_34 [3];
  BYTE local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  uint local_18;
  
  local_18 = DAT_c0012040;
  local_34[0] = 3;
  bVar1 = false;
  local_38 = (HKEY)0x0;
  LVar2 = RegCreateKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,L"",0,0x20019,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_38,local_34 + 2);
  if (LVar2 == 0) {
    local_34[1] = 0x10;
    LVar2 = RegQueryValueExW(local_38,L"UUID",(LPDWORD)0x0,local_34,&local_28,local_34 + 1);
    bVar1 = LVar2 == 0;
    RegCloseKey(local_38);
  }
  if (!bVar1) {
    FUN_c00118c8(local_18);
  }
  else {
    *(ushort *)(param_1 + 1) = CONCAT11(local_24,local_23);
    *param_1 = CONCAT31(CONCAT21(CONCAT11(local_28,local_27),local_26),local_25);
    *(ushort *)((int)param_1 + 6) = CONCAT11(local_22,local_21);
    *(undefined1 *)(param_1 + 2) = local_20;
    *(undefined1 *)((int)param_1 + 9) = local_1f;
    *(undefined1 *)((int)param_1 + 10) = local_1e;
    *(undefined1 *)((int)param_1 + 0xb) = local_1d;
    *(undefined1 *)(param_1 + 3) = local_1c;
    *(undefined1 *)((int)param_1 + 0xd) = local_1b;
    *(undefined1 *)((int)param_1 + 0xe) = local_1a;
    *(undefined1 *)((int)param_1 + 0xf) = local_19;
    FUN_c00118c8(local_18);
  }
  return bVar1;
}



/* c00112ac FUN_c00112ac */

/* Boundary evidence: original MIPS .pdata c00112ac..c001136b. Semantic name remains unreviewed. */

LSTATUS FUN_c00112ac(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,LPBYTE param_4)

{
  LSTATUS LVar1;
  HKEY local_20 [2];
  
  local_20[0] = (HKEY)0x0;
  LVar1 = RegOpenKeyExW(param_1,param_2,0,1,local_20);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_20[0],param_3,(LPDWORD)0x0,(LPDWORD)0x0,param_4,
                             (LPDWORD)&stack0x00000010);
    RegCloseKey(local_20[0]);
  }
  RegCloseKey(param_1);
  return LVar1;
}



/* c001136c FUN_c001136c */

/* Boundary evidence: original MIPS .pdata c001136c..c00114cf. Semantic name remains unreviewed. */

bool FUN_c001136c(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  bool bVar1;
  int iVar2;
  BYTE *_Src;
  BYTE aBStack_98 [64];
  BYTE aBStack_58 [64];
  uint local_18;
  
  local_18 = DAT_c0012040;
  bVar1 = false;
  if (param_1 == 0x1012068) {
    iVar2 = FUN_c00112ac((HKEY)0x80000002,L"LGE\\SystemInfo",L"DEVCODE",aBStack_98);
    _Src = aBStack_98;
  }
  else {
    if (param_1 != 0x101206c) {
      switch(*param_2) {
      case 0x104:
        *param_4 = 0x434c55;
        *param_6 = 4;
      case 0x102:
      case 0x105:
        bVar1 = true;
        break;
      case 0x107:
        bVar1 = FUN_c00110f8(param_4);
        *param_6 = 4;
      }
      goto switchD_c0011464_caseD_101;
    }
    iVar2 = FUN_c00112ac((HKEY)0x80000002,L"LGE\\SystemInfo",L"MAPCODE",aBStack_58);
    _Src = aBStack_58;
  }
  bVar1 = iVar2 == 0;
  memcpy(param_4,_Src,0x40);
switchD_c0011464_caseD_101:
  FUN_c00118c8(local_18);
  return bVar1;
}



/* c00114d0 IOControl */

/* Boundary evidence: original MIPS .pdata c00114d0..c0011613. Semantic name remains unreviewed. */

undefined1
IOControl(uint param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,undefined4 param_5
         ,undefined4 *param_6)

{
  bool bVar1;
  undefined1 uVar2;
  
                    /* 0x14d0  2  IOControl */
  if (param_1 < 0x1032c84) {
    if (param_1 != 0x1032c83) {
      if (param_1 != 0x1010004) {
        if (((param_1 == 0x1010034) || (param_1 == 0x1010054)) ||
           ((param_1 == 0x1010064 || (param_1 == 0x1010108)))) goto LAB_c00115e0;
        if ((param_1 != 0x1012068) && (param_1 != 0x101206c)) goto LAB_c00115c8;
      }
      bVar1 = FUN_c001136c(param_1,param_2,param_3,param_4,param_5,param_6);
      return bVar1;
    }
  }
  else if (((((param_1 != 0x1032c87) && (param_1 != 0x1032c93)) && (param_1 != 0x1032c97)) &&
           ((param_1 != 0x1032c9f && (param_1 != 0x1032ca3)))) && (param_1 != 0x1032ca7)) {
LAB_c00115c8:
    SetLastError(0x32);
    return 0;
  }
LAB_c00115e0:
  uVar2 = (*DAT_c0012048)();
  return uVar2;
}



/* c0011614 FUN_c0011614 */

/* Boundary evidence: original MIPS .pdata c0011614..c001174f. Semantic name remains unreviewed. */

int FUN_c0011614(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c001205c != (code *)0x0) {
      iVar2 = (*DAT_c001205c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c00116c4;
    FUN_c0011aa8();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = DllMain(param_1,param_2,param_3);
  }
LAB_c00116c4:
  if (((param_2 == 0) && (FUN_c0011a30(), iVar1 != 0)) && (DAT_c001205c != (code *)0x0)) {
    iVar1 = (*DAT_c001205c)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0011750 FUN_c0011750 */

/* Boundary evidence: original MIPS .pdata c0011750..c001177b. Semantic name remains unreviewed. */

void FUN_c0011750(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c001177c entry */

/* Boundary evidence: original MIPS .pdata c001177c..c00117d3. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c00117d4();
  }
  FUN_c0011614(param_1,param_2,param_3);
  return;
}



/* c00117d4 FUN_c00117d4 */

/* Boundary evidence: original MIPS .pdata c00117d4..c0011847. Semantic name remains unreviewed. */

void FUN_c00117d4(void)

{
  uint uVar1;
  
  if ((DAT_c0012040 == 0) || (DAT_c0012040 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0012040 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0012040 == 0) {
      DAT_c0012040 = 0xb064;
    }
  }
  DAT_c0012044 = ~DAT_c0012040;
  return;
}



/* c0011848 FUN_c0011848 */

/* Boundary evidence: original MIPS .pdata c0011848..c001189b. Semantic name remains unreviewed. */

void FUN_c0011848(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c00118c8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c001189c FUN_c001189c */

/* Boundary evidence: original MIPS .pdata c001189c..c00118c7. Semantic name remains unreviewed. */

undefined4 FUN_c001189c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0011848(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c00118c8 FUN_c00118c8 */

/* Boundary evidence: original MIPS .pdata c00118c8..c001190f. Semantic name remains unreviewed. */

void FUN_c00118c8(uint param_1)

{
  if ((param_1 == DAT_c0012040) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0011910 FUN_c0011910 */

/* Boundary evidence: original MIPS .pdata c0011910..c0011a2f. Semantic name remains unreviewed. */

void FUN_c0011910(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c001204c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c0012054;
    if (DAT_c0012054 != (undefined4 *)0x0) {
      while (DAT_c0012050 = DAT_c0012050 + -1, _Memory <= DAT_c0012050) {
        if ((code *)*DAT_c0012050 != (code *)0x0) {
          (*(code *)*DAT_c0012050)();
          _Memory = DAT_c0012054;
        }
      }
      free(_Memory);
      DAT_c0012050 = (undefined4 *)0x0;
      DAT_c0012054 = (undefined4 *)0x0;
    }
    FUN_c0011a54((undefined4 *)&DAT_c0011010,(undefined4 *)&DAT_c0011014);
  }
  FUN_c0011a54((undefined4 *)&DAT_c0011018,(undefined4 *)&DAT_c001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c0012058,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0011a30 FUN_c0011a30 */

/* Boundary evidence: original MIPS .pdata c0011a30..c0011a53. Semantic name remains unreviewed. */

void FUN_c0011a30(void)

{
  FUN_c0011910(0,0,1);
  return;
}



/* c0011a54 FUN_c0011a54 */

/* Boundary evidence: original MIPS .pdata c0011a54..c0011aa7. Semantic name remains unreviewed. */

void FUN_c0011a54(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0011aa8 FUN_c0011aa8 */

/* Boundary evidence: original MIPS .pdata c0011aa8..c0011ae3. Semantic name remains unreviewed. */

void FUN_c0011aa8(void)

{
  FUN_c0011a54((undefined4 *)&DAT_c0011008,(undefined4 *)&DAT_c001100c);
  FUN_c0011a54((undefined4 *)&DAT_c0011000,(undefined4 *)&DAT_c0011004);
  return;
}


