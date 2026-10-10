/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..0001114b. Semantic name remains unreviewed. */

void FUN_00011000(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (DAT_0001b1f4 != 0) {
    (*DAT_0001b208)();
    DAT_0001b1f4 = 0;
  }
  if (DAT_0001b1e4 != 0) {
    uVar5 = 0;
    if (DAT_0001b1e0 != 0) {
      iVar4 = 0;
      iVar1 = DAT_0001b1e4;
      uVar3 = DAT_0001b1e0;
      do {
        if (*(int *)(iVar4 + iVar1) != 0) {
          __3_YAXPAX_Z(*(int *)(iVar4 + iVar1));
          *(undefined4 *)(iVar4 + DAT_0001b1e4) = 0;
          iVar1 = DAT_0001b1e4;
          uVar3 = DAT_0001b1e0;
        }
        iVar2 = *(int *)(iVar4 + iVar1 + 4);
        if (iVar2 != 0) {
          __3_YAXPAX_Z(iVar2);
          *(undefined4 *)(iVar4 + DAT_0001b1e4 + 4) = 0;
          iVar1 = DAT_0001b1e4;
          uVar3 = DAT_0001b1e0;
        }
        iVar2 = *(int *)(iVar4 + iVar1 + 8);
        if (iVar2 != 0) {
          __3_YAXPAX_Z(iVar2);
          *(undefined4 *)(iVar4 + DAT_0001b1e4 + 8) = 0;
          iVar1 = DAT_0001b1e4;
          uVar3 = DAT_0001b1e0;
        }
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 0xc;
      } while (uVar5 < uVar3);
    }
    ___V_YAXPAX_Z();
    DAT_0001b1e4 = 0;
  }
  if (DAT_0001b1f8 != 0) {
    FreeLibrary((HMODULE)DAT_0001b1f8);
    DAT_0001b1f8 = 0;
  }
  return;
}



/* 0001114c FUN_0001114c */

/* Boundary evidence: original MIPS .pdata 0001114c..0001119b. Semantic name remains unreviewed. */

undefined4 FUN_0001114c(LPCWSTR param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  DVar1 = GetFileAttributesW(param_1);
  if ((DVar1 != 0xffffffff) && ((DVar1 & 0x10) == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* 0001119c FUN_0001119c */

/* Boundary evidence: original MIPS .pdata 0001119c..0001123f. Semantic name remains unreviewed. */

undefined4 FUN_0001119c(LPCWSTR param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined1 auStack_40 [4];
  undefined4 local_3c;
  undefined4 local_34;
  
  if ((param_1 == (LPCWSTR)0x0) || (iVar3 = FUN_0001114c(param_1), iVar3 == 0)) {
    uVar4 = 0;
  }
  else {
    memset(local_50,0,0x3c);
    local_34 = 1;
    puVar1 = auStack_40 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)param_1 >> (3 - uVar2) * 8;
    local_50[0] = 0x3c;
    local_48 = 0;
    auStack_40 = (undefined1  [4])param_1;
    local_3c = param_2;
    uVar4 = ShellExecuteEx(local_50);
  }
  return uVar4;
}



/* 00011240 FUN_00011240 */

/* Boundary evidence: original MIPS .pdata 00011240..00011357. Semantic name remains unreviewed. */

undefined4 FUN_00011240(int param_1,char *param_2)

{
  HANDLE hFile;
  size_t sVar1;
  DWORD aDStack_330 [2];
  char acStack_328 [264];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_0001b1d4;
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    swprintf_s(awStack_220,0x104,L"\\Windows\\Desktop\\%s.lnk",param_1);
    hFile = CreateFileW(awStack_220,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,(HANDLE)0x0);
    if (hFile != (HANDLE)0xffffffff) {
      sVar1 = strlen(param_2);
      sprintf_s(acStack_328,0x104,"%d#\"%s\"",sVar1 + 2,param_2);
      sVar1 = strlen(acStack_328);
      WriteFile(hFile,acStack_328,sVar1,aDStack_330,(LPOVERLAPPED)0x0);
      CloseHandle(hFile);
      FUN_00017eb8(local_18);
      return 1;
    }
  }
  FUN_00017eb8(local_18);
  return 0;
}



/* 00011358 FUN_00011358 */

/* Boundary evidence: original MIPS .pdata 00011358..0001137b. Semantic name remains unreviewed. */

void FUN_00011358(undefined4 *param_1)

{
  *param_1 = std::bad_alloc::vftable;
  __1exception_std__UAA_XZ();
  return;
}



/* 0001137c FUN_0001137c */

/* Boundary evidence: original MIPS .pdata 0001137c..000113d3. Semantic name remains unreviewed. */

undefined4 * FUN_0001137c(undefined4 *param_1,uint param_2)

{
  *param_1 = std::bad_alloc::vftable;
  __1exception_std__UAA_XZ(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000113d4 FUN_000113d4 */

/* Boundary evidence: original MIPS .pdata 000113d4..0001143b. Semantic name remains unreviewed. */

undefined4 FUN_000113d4(void)

{
  DeleteFileW(L"\\Storage Card3\\StartWinCE");
  FUN_00011240(0x190e4,"\\Storage Card\\System\\cereboot.exe");
  FUN_00011240(0x190a0,"\\Storage Card\\System\\dmenu.exe");
  FUN_0001119c(L"\\Windows\\explorer.exe",0);
  return 1;
}



/* 0001143c FUN_0001143c */

void FUN_0001143c(void)

{
  return;
}



/* 00011444 FUN_00011444 */

/* Boundary evidence: original MIPS .pdata 00011444..000114c7. Semantic name remains unreviewed. */

void FUN_00011444(uint param_1)

{
  undefined **appuStack_18 [4];
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    if (param_1 == 0) {
      trap(0x1c00);
    }
    if (0xffffffff / param_1 < 0x14) {
      __0exception_std__QAA_PBD_Z(appuStack_18,0);
                    /* WARNING: Subroutine does not return */
      appuStack_18[0] = std::bad_alloc::vftable;
      __CxxThrowException(appuStack_18,(ThrowInfo *)&DAT_00019fe4);
    }
  }
  __2_YAPAXI_Z(param_1 * 0x14);
  return;
}



/* 000114c8 FUN_000114c8 */

/* Boundary evidence: original MIPS .pdata 000114c8..0001153f. Semantic name remains unreviewed. */

void FUN_000114c8(uint param_1)

{
  undefined **appuStack_18 [4];
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    if (param_1 == 0) {
      trap(0x1c00);
    }
    if (0xffffffff / param_1 < 4) {
      __0exception_std__QAA_PBD_Z(appuStack_18,0);
                    /* WARNING: Subroutine does not return */
      appuStack_18[0] = std::bad_alloc::vftable;
      __CxxThrowException(appuStack_18,(ThrowInfo *)&DAT_00019fe4);
    }
  }
  __2_YAPAXI_Z(param_1 << 2);
  return;
}



/* 00011540 FUN_00011540 */

void FUN_00011540(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_2 + 8);
  *(int *)(param_2 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x39) == '\0') {
    *(int *)(*piVar1 + 4) = param_2;
  }
  piVar1[1] = *(int *)(param_2 + 4);
  if (param_2 == *(int *)(*(int *)(param_1 + 0x18) + 4)) {
    *(int **)(*(int *)(param_1 + 0x18) + 4) = piVar1;
  }
  else {
    piVar2 = *(int **)(param_2 + 4);
    if (param_2 == *piVar2) {
      *piVar2 = (int)piVar1;
    }
    else {
      piVar2[2] = (int)piVar1;
    }
  }
  *piVar1 = param_2;
  *(int **)(param_2 + 4) = piVar1;
  return;
}



/* 000115a8 FUN_000115a8 */

void FUN_000115a8(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  *param_2 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x39) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_2;
  }
  *(int *)(iVar1 + 4) = param_2[1];
  if (param_2 == *(int **)(*(int *)(param_1 + 0x18) + 4)) {
    *(int *)(*(int *)(param_1 + 0x18) + 4) = iVar1;
  }
  else {
    piVar2 = (int *)param_2[1];
    if (param_2 == (int *)piVar2[2]) {
      piVar2[2] = iVar1;
    }
    else {
      *piVar2 = iVar1;
    }
  }
  *(int **)(iVar1 + 8) = param_2;
  param_2[1] = iVar1;
  return;
}



/* 00011610 FUN_00011610 */

/* Boundary evidence: original MIPS .pdata 00011610..00011693. Semantic name remains unreviewed. */

void FUN_00011610(uint param_1)

{
  undefined **appuStack_18 [4];
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    if (param_1 == 0) {
      trap(0x1c00);
    }
    if (0xffffffff / param_1 < 0x3c) {
      __0exception_std__QAA_PBD_Z(appuStack_18,0);
                    /* WARNING: Subroutine does not return */
      appuStack_18[0] = std::bad_alloc::vftable;
      __CxxThrowException(appuStack_18,(ThrowInfo *)&DAT_00019fe4);
    }
  }
  __2_YAPAXI_Z(param_1 * 0x3c);
  return;
}



/* 00011694 FUN_00011694 */

void FUN_00011694(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_2 + 8);
  *(int *)(param_2 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x1d) == '\0') {
    *(int *)(*piVar1 + 4) = param_2;
  }
  piVar1[1] = *(int *)(param_2 + 4);
  if (param_2 == *(int *)(*(int *)(param_1 + 0x18) + 4)) {
    *(int **)(*(int *)(param_1 + 0x18) + 4) = piVar1;
  }
  else {
    piVar2 = *(int **)(param_2 + 4);
    if (param_2 == *piVar2) {
      *piVar2 = (int)piVar1;
    }
    else {
      piVar2[2] = (int)piVar1;
    }
  }
  *piVar1 = param_2;
  *(int **)(param_2 + 4) = piVar1;
  return;
}



/* 000116fc FUN_000116fc */

void FUN_000116fc(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  *param_2 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x1d) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_2;
  }
  *(int *)(iVar1 + 4) = param_2[1];
  if (param_2 == *(int **)(*(int *)(param_1 + 0x18) + 4)) {
    *(int *)(*(int *)(param_1 + 0x18) + 4) = iVar1;
  }
  else {
    piVar2 = (int *)param_2[1];
    if (param_2 == (int *)piVar2[2]) {
      piVar2[2] = iVar1;
    }
    else {
      *piVar2 = iVar1;
    }
  }
  *(int **)(iVar1 + 8) = param_2;
  param_2[1] = iVar1;
  return;
}



/* 00011764 FUN_00011764 */

undefined4 FUN_00011764(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != (undefined4 *)0x0) {
    bVar1 = 0xf < *(uint *)(param_1 + 0x18);
    puVar2 = (undefined4 *)(param_1 + 4);
    puVar3 = puVar2;
    if (bVar1) {
      puVar3 = (undefined4 *)*puVar2;
    }
    if (puVar3 <= param_2) {
      if (bVar1) {
        puVar2 = (undefined4 *)*puVar2;
      }
      if (param_2 < (undefined4 *)(*(int *)(param_1 + 0x14) + (int)puVar2)) {
        return 1;
      }
    }
  }
  return 0;
}



/* 000117c0 FUN_000117c0 */

/* Boundary evidence: original MIPS .pdata 000117c0..00011837. Semantic name remains unreviewed. */

void FUN_000117c0(uint param_1)

{
  undefined **appuStack_18 [4];
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    if (param_1 == 0) {
      trap(0x1c00);
    }
    if (0xffffffff / param_1 == 0) {
      __0exception_std__QAA_PBD_Z(appuStack_18,0);
                    /* WARNING: Subroutine does not return */
      appuStack_18[0] = std::bad_alloc::vftable;
      __CxxThrowException(appuStack_18,(ThrowInfo *)&DAT_00019fe4);
    }
  }
  __2_YAPAXI_Z(param_1);
  return;
}



/* 00011838 FUN_00011838 */

/* Boundary evidence: original MIPS .pdata 00011838..0001186f. Semantic name remains unreviewed. */

undefined4 * FUN_00011838(undefined4 *param_1)

{
  __0exception_std__QAA_ABV01__Z(param_1);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}



/* 00011870 FUN_00011870 */

/* Boundary evidence: original MIPS .pdata 00011870..00011977. Semantic name remains unreviewed. */

void FUN_00011870(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*param_1 == 0) {
    FUN_0001859c();
  }
  piVar3 = (int *)param_1[1];
  if (*(char *)((int)piVar3 + 0x39) == '\0') {
    iVar4 = *piVar3;
    if (*(char *)(iVar4 + 0x39) == '\0') {
      cVar1 = *(char *)(*(int *)(iVar4 + 8) + 0x39);
      iVar2 = *(int *)(iVar4 + 8);
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x39);
        iVar4 = iVar2;
        iVar2 = *(int *)(iVar2 + 8);
      }
      param_1[1] = iVar4;
      return;
    }
    piVar3 = (int *)piVar3[1];
    cVar1 = *(char *)((int)piVar3 + 0x39);
    while ((cVar1 == '\0' && (param_1[1] == *piVar3))) {
      param_1[1] = (int)piVar3;
      piVar3 = (int *)piVar3[1];
      cVar1 = *(char *)((int)piVar3 + 0x39);
    }
    if (*(char *)(param_1[1] + 0x39) == '\0') {
      param_1[1] = (int)piVar3;
      return;
    }
  }
  else {
    iVar4 = piVar3[2];
    param_1[1] = iVar4;
    if (*(char *)(iVar4 + 0x39) == '\0') {
      return;
    }
  }
  FUN_0001859c();
  return;
}



/* 00011978 FUN_00011978 */

/* Boundary evidence: original MIPS .pdata 00011978..000119ef. Semantic name remains unreviewed. */

void FUN_00011978(uint param_1)

{
  undefined **appuStack_18 [4];
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    if (param_1 == 0) {
      trap(0x1c00);
    }
    if (0xffffffff / param_1 < 0x20) {
      __0exception_std__QAA_PBD_Z(appuStack_18,0);
                    /* WARNING: Subroutine does not return */
      appuStack_18[0] = std::bad_alloc::vftable;
      __CxxThrowException(appuStack_18,(ThrowInfo *)&DAT_00019fe4);
    }
  }
  __2_YAPAXI_Z(param_1 << 5);
  return;
}



/* 000119f0 FUN_000119f0 */

/* Boundary evidence: original MIPS .pdata 000119f0..00011b53. Semantic name remains unreviewed. */

void FUN_000119f0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == 0x200) {
    if (DAT_0001b1e8 != 0) {
      iVar1 = param_1 * 0xc;
      if ((*(int *)(iVar1 + DAT_0001b1e4 + 4) != 0) &&
         (uVar2 = DAT_0001b1ec - param_3 >> 0x1f,
         300 < (int)((DAT_0001b1ec - param_3 ^ uVar2) - uVar2))) {
        DAT_0001b1e8 = 0;
        NKDbgPrintfW(L"Horizontal move detected\n");
        FUN_0001119c(*(LPCWSTR *)(iVar1 + DAT_0001b1e4 + 4),0);
      }
      if ((*(int *)(iVar1 + DAT_0001b1e4 + 8) != 0) &&
         (uVar2 = DAT_0001b1f0 - param_4 >> 0x1f,
         200 < (int)((DAT_0001b1f0 - param_4 ^ uVar2) - uVar2))) {
        DAT_0001b1e8 = 0;
        NKDbgPrintfW(L"Vertical move detected\n");
        FUN_0001119c(*(LPCWSTR *)(iVar1 + DAT_0001b1e4 + 8),0);
      }
    }
  }
  else if (param_2 == 0x201) {
    DAT_0001b1e8 = 1;
    DAT_0001b1ec = param_3;
    DAT_0001b1f0 = param_4;
  }
  else if (param_2 == 0x202) {
    DAT_0001b1e8 = 0;
  }
  return;
}



/* 00011b54 FUN_00011b54 */

/* Boundary evidence: original MIPS .pdata 00011b54..00011c8f. Semantic name remains unreviewed. */

undefined4 FUN_00011b54(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  HWND hWnd;
  int iVar2;
  size_t _MaxCount;
  undefined4 uVar3;
  wchar_t *_Str;
  uint uVar4;
  undefined4 *puVar5;
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_0001b1d4;
  if ((param_1 == 0) && ((DAT_0001b1e8 != 0 || (param_2 == 0x201)))) {
    hWnd = GetForegroundWindow();
    iVar2 = GetClassNameW(hWnd,aWStack_230,0x104);
    uVar1 = DAT_0001b1e0;
    if ((0 < iVar2) && (uVar4 = 0, puVar5 = DAT_0001b1e4, DAT_0001b1e0 != 0)) {
      do {
        _Str = (wchar_t *)*puVar5;
        _MaxCount = wcslen(_Str);
        iVar2 = wcsncmp(aWStack_230,_Str,_MaxCount);
        if (iVar2 == 0) {
          FUN_000119f0(uVar4,param_2,*param_3,param_3[1]);
          break;
        }
        uVar4 = uVar4 + 1;
        puVar5 = puVar5 + 3;
      } while (uVar4 < uVar1);
    }
    param_1 = 0;
  }
  uVar3 = (*DAT_0001b204)(DAT_0001b1f4,param_1,param_2,param_3);
  FUN_00017eb8(local_28);
  return uVar3;
}



/* 00011c90 FUN_00011c90 */

/* Boundary evidence: original MIPS .pdata 00011c90..00011d13. Semantic name remains unreviewed. */

int * FUN_00011c90(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    FUN_0001859c();
  }
  if ((int *)*param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)*param_1;
  }
  if (param_1[1] == *(int *)(iVar1 + 0x14)) {
    FUN_0001859c();
  }
  param_1[1] = *(int *)param_1[1];
  return param_1;
}



/* 00011d14 FUN_00011d14 */

/* Boundary evidence: original MIPS .pdata 00011d14..00011d8f. Semantic name remains unreviewed. */

int FUN_00011d14(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    FUN_0001859c();
  }
  if ((int *)*param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)*param_1;
  }
  if (param_1[1] == *(int *)(iVar1 + 0x14)) {
    FUN_0001859c();
  }
  return param_1[1] + 8;
}



/* 00011d90 FUN_00011d90 */

/* Boundary evidence: original MIPS .pdata 00011d90..00011e23. Semantic name remains unreviewed. */

bool FUN_00011d90(int *param_1,int *param_2)

{
  if ((*param_1 == 0) || (*param_1 != *param_2)) {
    FUN_0001859c();
  }
  return param_1[1] == param_2[1];
}



/* 00011e24 FUN_00011e24 */

/* Boundary evidence: original MIPS .pdata 00011e24..00011e9f. Semantic name remains unreviewed. */

int FUN_00011e24(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    FUN_0001859c();
  }
  if ((int *)*param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)*param_1;
  }
  if (param_1[1] == *(int *)(iVar1 + 0x18)) {
    FUN_0001859c();
  }
  return param_1[1] + 0xc;
}



/* 00011ea0 FUN_00011ea0 */

/* Boundary evidence: original MIPS .pdata 00011ea0..00011f7b. Semantic name remains unreviewed. */

void FUN_00011ea0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if (*param_1 == 0) {
    FUN_0001859c();
  }
  iVar3 = param_1[1];
  if (*(char *)(iVar3 + 0x39) == '\0') {
    piVar4 = *(int **)(iVar3 + 8);
    if (*(char *)((int)piVar4 + 0x39) == '\0') {
      cVar1 = *(char *)(*piVar4 + 0x39);
      piVar2 = (int *)*piVar4;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x39);
        piVar4 = piVar2;
        piVar2 = (int *)*piVar2;
      }
      param_1[1] = (int)piVar4;
    }
    else {
      iVar3 = *(int *)(iVar3 + 4);
      cVar1 = *(char *)(iVar3 + 0x39);
      while ((cVar1 == '\0' && (param_1[1] == *(int *)(iVar3 + 8)))) {
        param_1[1] = iVar3;
        iVar3 = *(int *)(iVar3 + 4);
        cVar1 = *(char *)(iVar3 + 0x39);
      }
      param_1[1] = iVar3;
    }
  }
  else {
    FUN_0001859c();
  }
  return;
}



/* 00011fec FUN_00011fec */

bool FUN_00011fec(undefined4 param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  
  while( true ) {
    uVar2 = *param_2;
    if ((uVar2 == 0) || (uVar1 = *param_3, uVar1 == 0)) {
      return *param_3 != 0;
    }
    if ((uVar2 < 0x41) || (uVar3 = uVar2 + 0x20, 0x5a < uVar2)) {
      uVar3 = uVar2;
    }
    if ((uVar1 < 0x41) || (uVar2 = uVar1 + 0x20, 0x5a < uVar1)) {
      uVar2 = uVar1;
    }
    if ((uint)uVar3 != (uint)uVar2) break;
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
  }
  return (int)((uint)uVar3 - (uint)uVar2) < 0;
}



/* 00012028 FUN_00012028 */

undefined4 FUN_00012028(undefined4 param_1)

{
  return param_1;
}



/* 00012030 FUN_00012030 */

/* Boundary evidence: original MIPS .pdata 00012030..0001206b. Semantic name remains unreviewed. */

void FUN_00012030(void)

{
  int iVar1;
  
  iVar1 = FUN_00011444(1);
  if (iVar1 != 0) {
    *(int *)iVar1 = iVar1;
  }
  if ((int *)(iVar1 + 4) != (int *)0x0) {
    *(int *)(iVar1 + 4) = iVar1;
  }
  return;
}



/* 0001206c FUN_0001206c */

/* Boundary evidence: original MIPS .pdata 0001206c..000120c7. Semantic name remains unreviewed. */

void FUN_0001206c(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  piVar1 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (piVar1 != *(int **)(param_1 + 0x14)) {
    do {
      piVar1 = (int *)*piVar1;
      __3_YAXPAX_Z();
    } while (piVar1 != (int *)*(int *)(param_1 + 0x14));
  }
  return;
}



/* 000120c8 FUN_000120c8 */

/* Boundary evidence: original MIPS .pdata 000120c8..0001210f. Semantic name remains unreviewed. */

int * FUN_000120c8(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000114c8(1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
  }
  *param_1 = (int)puVar1;
  return param_1;
}



/* 00012110 FUN_00012110 */

/* Boundary evidence: original MIPS .pdata 00012110..000121eb. Semantic name remains unreviewed. */

void FUN_00012110(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if (*param_1 == 0) {
    FUN_0001859c();
  }
  iVar3 = param_1[1];
  if (*(char *)(iVar3 + 0x1d) == '\0') {
    piVar4 = *(int **)(iVar3 + 8);
    if (*(char *)((int)piVar4 + 0x1d) == '\0') {
      cVar1 = *(char *)(*piVar4 + 0x1d);
      piVar2 = (int *)*piVar4;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x1d);
        piVar4 = piVar2;
        piVar2 = (int *)*piVar2;
      }
      param_1[1] = (int)piVar4;
    }
    else {
      iVar3 = *(int *)(iVar3 + 4);
      cVar1 = *(char *)(iVar3 + 0x1d);
      while ((cVar1 == '\0' && (param_1[1] == *(int *)(iVar3 + 8)))) {
        param_1[1] = iVar3;
        iVar3 = *(int *)(iVar3 + 4);
        cVar1 = *(char *)(iVar3 + 0x1d);
      }
      param_1[1] = iVar3;
    }
  }
  else {
    FUN_0001859c();
  }
  return;
}



/* 000121ec FUN_000121ec */

/* Boundary evidence: original MIPS .pdata 000121ec..0001229f. Semantic name remains unreviewed. */

undefined4 * FUN_000121ec(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(param_1 + 0x18))[1];
  cVar1 = *(char *)((int)puVar4 + 0x39);
  puVar2 = *(undefined4 **)(param_1 + 0x18);
  uVar6 = DAT_0001b21c;
  while (cVar1 == '\0') {
    if ((uVar6 & 1) == 0) {
      uVar6 = uVar6 | 1;
      DAT_0001b21c = uVar6;
    }
    bVar3 = thunk_FUN_00011fec(&DAT_0001b218,(ushort *)puVar4[3],(ushort *)*param_2);
    if (CONCAT31(extraout_var,bVar3) == 0) {
      puVar5 = (undefined4 *)*puVar4;
    }
    else {
      puVar5 = (undefined4 *)puVar4[2];
      puVar4 = puVar2;
    }
    puVar2 = puVar4;
    puVar4 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0x39);
  }
  return puVar2;
}



/* 000122a0 FUN_000122a0 */

/* Boundary evidence: original MIPS .pdata 000122a0..00012353. Semantic name remains unreviewed. */

undefined4 * FUN_000122a0(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(param_1 + 0x18))[1];
  cVar1 = *(char *)((int)puVar4 + 0x1d);
  puVar2 = *(undefined4 **)(param_1 + 0x18);
  uVar6 = DAT_0001b21c;
  while (cVar1 == '\0') {
    if ((uVar6 & 1) == 0) {
      uVar6 = uVar6 | 1;
      DAT_0001b21c = uVar6;
    }
    bVar3 = thunk_FUN_00011fec(&DAT_0001b218,(ushort *)puVar4[3],(ushort *)*param_2);
    if (CONCAT31(extraout_var,bVar3) == 0) {
      puVar5 = (undefined4 *)*puVar4;
    }
    else {
      puVar5 = (undefined4 *)puVar4[2];
      puVar4 = puVar2;
    }
    puVar2 = puVar4;
    puVar4 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0x1d);
  }
  return puVar2;
}



/* 00012354 FUN_00012354 */

/* Boundary evidence: original MIPS .pdata 00012354..000123b3. Semantic name remains unreviewed. */

void FUN_00012354(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00011610(1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xe) = 1;
  *(undefined1 *)((int)puVar1 + 0x39) = 0;
  return;
}



/* 000123b4 FUN_000123b4 */

/* Boundary evidence: original MIPS .pdata 000123b4..000123eb. Semantic name remains unreviewed. */

int * FUN_000123b4(int *param_1)

{
  FUN_000120c8(param_1);
  return param_1;
}



/* 000123ec FUN_000123ec */

/* Boundary evidence: original MIPS .pdata 000123ec..0001246f. Semantic name remains unreviewed. */

void FUN_000123ec(int param_1,int param_2,rsize_t param_3)

{
  void *_Src;
  
  if ((param_2 != 0) && (0xf < *(uint *)(param_1 + 0x18))) {
    _Src = *(void **)(param_1 + 4);
    if (param_3 != 0) {
      memcpy_s((undefined4 *)(param_1 + 4),0x10,_Src,param_3);
    }
    __3_YAXPAX_Z(_Src);
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(rsize_t *)(param_1 + 0x14) = param_3;
  *(undefined1 *)(param_1 + 4 + param_3) = 0;
  return;
}



/* 00012470 FUN_00012470 */

/* Boundary evidence: original MIPS .pdata 00012470..000124d3. Semantic name remains unreviewed. */

void FUN_00012470(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_2 + 0x1d);
  while (cVar1 == '\0') {
    FUN_00012470(param_1,(int *)param_2[2]);
    piVar2 = (int *)*param_2;
    __3_YAXPAX_Z(param_2);
    param_2 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x1d);
  }
  return;
}



/* 000124d4 FUN_000124d4 */

/* Boundary evidence: original MIPS .pdata 000124d4..000125b7. Semantic name remains unreviewed. */

int FUN_000124d4(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  if (*(uint *)(param_1 + 0x14) < param_2) {
    FUN_0001850c();
  }
  uVar3 = *(int *)(param_1 + 0x14) - param_2;
  if (uVar3 < param_3) {
    param_3 = uVar3;
  }
  if (param_3 != 0) {
    piVar5 = (int *)(param_1 + 4);
    piVar2 = piVar5;
    piVar1 = piVar5;
    if (0xf < *(uint *)(param_1 + 0x18)) {
      piVar2 = (int *)*piVar5;
      piVar1 = (int *)*piVar5;
    }
    memmove_s((void *)((int)piVar2 + param_2),*(uint *)(param_1 + 0x18) - param_2,
              (void *)((int)piVar1 + param_3 + param_2),uVar3 - param_3);
    iVar4 = *(int *)(param_1 + 0x14) - param_3;
    *(int *)(param_1 + 0x14) = iVar4;
    if (0xf < *(uint *)(param_1 + 0x18)) {
      piVar5 = (int *)*piVar5;
    }
    *(undefined1 *)((int)piVar5 + iVar4) = 0;
  }
  return param_1;
}



/* 000125b8 FUN_000125b8 */

/* Boundary evidence: original MIPS .pdata 000125b8..000126fb. Semantic name remains unreviewed. */

void FUN_000125b8(int param_1,uint param_2,rsize_t param_3)

{
  undefined4 *_Dst;
  void *_Src;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2 | 0xf;
  if (uVar3 != 0xffffffff) {
    uVar1 = *(uint *)(param_1 + 0x18);
    uVar2 = uVar1 >> 1;
    param_2 = uVar3;
    if ((uVar3 / 3 < uVar2) && (uVar1 <= -uVar2 - 2)) {
      param_2 = uVar2 + uVar1;
    }
  }
  _Dst = (undefined4 *)FUN_000117c0(param_2 + 1);
  if (param_3 != 0) {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      _Src = (void *)(param_1 + 4);
    }
    else {
      _Src = *(void **)(param_1 + 4);
    }
    memcpy_s(_Dst,param_2 + 1,_Src,param_3);
  }
  FUN_000123ec(param_1,1,0);
  *(undefined4 *)(param_1 + 4) = _Dst;
  *(uint *)(param_1 + 0x18) = param_2;
  *(rsize_t *)(param_1 + 0x14) = param_3;
  if (param_2 < 0x10) {
    _Dst = (undefined4 *)(param_1 + 4);
  }
  *(undefined1 *)((int)_Dst + param_3) = 0;
  return;
}



/* 000126fc FUN_000126fc */

/* Boundary evidence: original MIPS .pdata 000126fc..0001272f. Semantic name remains unreviewed. */

void FUN_000126fc(void)

{
  int in_v0;
  
  FUN_000123ec(**(int **)(in_v0 + -4),1,0);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



/* 00012730 FUN_00012730 */

/* Boundary evidence: original MIPS .pdata 00012730..00012777. Semantic name remains unreviewed. */

undefined * FUN_00012730(void)

{
  int in_v0;
  undefined4 uVar1;
  
  *(int *)(in_v0 + -0x20) = *(int *)(in_v0 + 4);
  uVar1 = FUN_000117c0(*(int *)(in_v0 + 4) + 1);
  *(undefined4 *)(in_v0 + -0x1c) = uVar1;
  return &DAT_00012660;
}



/* 00012778 FUN_00012778 */

/* Boundary evidence: original MIPS .pdata 00012778..000127cf. Semantic name remains unreviewed. */

undefined4 * FUN_00012778(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_000121ec((int)param_1,param_3);
  *param_2 = 0;
  param_2[1] = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    FUN_0001859c();
  }
  *param_2 = *param_1;
  return param_2;
}



/* 000127d0 FUN_000127d0 */

/* Boundary evidence: original MIPS .pdata 000127d0..0001282f. Semantic name remains unreviewed. */

void FUN_000127d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00011978(1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 7) = 1;
  *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  return;
}



/* 00012830 FUN_00012830 */

/* Boundary evidence: original MIPS .pdata 00012830..00012bdb. Semantic name remains unreviewed. */

undefined4 FUN_00012830(undefined4 param_1,int *param_2,int *param_3,ushort *param_4,char param_5)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  bool bVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar5;
  ushort *puVar6;
  short *psVar7;
  int iVar8;
  short *psVar9;
  undefined4 uVar10;
  ushort *puVar11;
  ushort *_Dst;
  short sVar12;
  int iVar13;
  
  _Dst = (ushort *)*param_2;
  *param_3 = (int)_Dst;
  sVar12 = *(short *)*param_2;
  uVar10 = 1;
  iVar13 = 2;
LAB_0001289c:
  do {
    if (param_4 == (ushort *)0x0) {
      psVar7 = (short *)*param_2;
      if ((*psVar7 == 0x3b) || (*psVar7 == 0x23)) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      if (!bVar4) {
        if (param_5 == '\0') {
LAB_00012b48:
          if (*param_3 == *param_2) {
            *param_3 = 0;
            uVar10 = 0;
          }
          else {
            _Dst[-1] = 0;
            if ((param_4 != (ushort *)0x0) && (sVar12 != 0)) {
              *(short *)*param_2 = sVar12;
              psVar7 = (short *)*param_2;
              if ((*psVar7 != 0xd) || (psVar7[1] != 10)) {
                iVar13 = 1;
              }
              *param_2 = (int)(psVar7 + iVar13);
            }
          }
          return uVar10;
        }
        iVar8 = 0;
        while( true ) {
          sVar1 = *psVar7;
          if ((((sVar1 == 0x20) || (sVar1 == 9)) || (sVar1 == 0xd)) || (bVar4 = false, sVar1 == 10))
          {
            bVar4 = true;
          }
          if (!bVar4) break;
          if ((sVar1 == 10) || (bVar4 = false, sVar1 == 0xd)) {
            bVar4 = true;
          }
          if (bVar4) {
            iVar8 = iVar8 + 1;
            if ((sVar1 != 0xd) || (iVar5 = 2, psVar7[1] != 10)) {
              iVar5 = 1;
            }
            psVar7 = psVar7 + iVar5;
          }
          else {
            psVar7 = psVar7 + 1;
          }
        }
        if ((*psVar7 == 0x3b) || (*psVar7 == 0x23)) {
          bVar4 = true;
        }
        else {
          bVar4 = false;
        }
        if (!bVar4) goto LAB_00012b48;
        if (0 < iVar8) {
          if (iVar8 != 0) {
            puVar11 = _Dst;
            do {
              *puVar11 = 10;
              puVar11 = puVar11 + 1;
            } while (puVar11 != _Dst + iVar8);
          }
          _Dst = _Dst + iVar8;
        }
        *param_2 = (int)psVar7;
        goto LAB_0001289c;
      }
    }
    puVar11 = (ushort *)*param_2;
    uVar2 = *puVar11;
    while (uVar2 != 0) {
      sVar12 = *(short *)*param_2;
      if ((sVar12 == 10) || (bVar4 = false, sVar12 == 0xd)) {
        bVar4 = true;
      }
      if (bVar4) break;
      puVar6 = (ushort *)((short *)*param_2 + 1);
      *param_2 = (int)puVar6;
      uVar2 = *puVar6;
    }
    if (_Dst < puVar11) {
      iVar8 = *param_2 - (int)puVar11 >> 1;
      memmove(_Dst,puVar11,iVar8 * 2);
      _Dst[iVar8] = 0;
    }
    sVar12 = *(short *)*param_2;
    *(short *)*param_2 = 0;
    if (param_4 != (ushort *)0x0) {
      if ((DAT_0001b214 & 1) == 0) {
        DAT_0001b214 = DAT_0001b214 | 1;
      }
      uVar3 = DAT_0001b214;
      bVar4 = thunk_FUN_00011fec(&DAT_0001b210,_Dst,param_4);
      if (CONCAT31(extraout_var,bVar4) == 0) {
        if ((uVar3 & 1) == 0) {
          DAT_0001b214 = uVar3 | 1;
        }
        bVar4 = thunk_FUN_00011fec(&DAT_0001b210,param_4,_Dst);
        if (CONCAT31(extraout_var_00,bVar4) == 0) goto LAB_00012b48;
      }
    }
    if (sVar12 == 0) {
      return 1;
    }
    psVar7 = (short *)*param_2;
    *psVar7 = sVar12;
    psVar9 = (short *)*param_2;
    puVar11 = _Dst + ((int)psVar7 - (int)puVar11 >> 1);
    if ((*psVar9 != 0xd) || (iVar8 = 2, psVar9[1] != 10)) {
      iVar8 = 1;
    }
    *param_2 = (int)(psVar9 + iVar8);
    _Dst = puVar11 + 1;
    *puVar11 = 10;
  } while( true );
}



/* 00012bdc FUN_00012bdc */

/* Boundary evidence: original MIPS .pdata 00012bdc..00012c0b. Semantic name remains unreviewed. */

int * FUN_00012bdc(int *param_1)

{
  FUN_000120c8(param_1);
  return param_1;
}



/* 00012c0c FUN_00012c0c */

/* Boundary evidence: original MIPS .pdata 00012c0c..00012c63. Semantic name remains unreviewed. */

undefined4 * FUN_00012c0c(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_000122a0((int)param_1,param_3);
  *param_2 = 0;
  param_2[1] = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    FUN_0001859c();
  }
  *param_2 = *param_1;
  return param_2;
}



/* 00012c64 FUN_00012c64 */

/* Boundary evidence: original MIPS .pdata 00012c64..00012cb3. Semantic name remains unreviewed. */

void FUN_00012c64(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00012354();
  *(int *)(param_1 + 0x18) = iVar1;
  *(undefined1 *)(iVar1 + 0x39) = 1;
  *(int *)(*(int *)(param_1 + 0x18) + 4) = *(int *)(param_1 + 0x18);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(int *)(*(int *)(param_1 + 0x18) + 8) = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}



/* 00012cb4 FUN_00012cb4 */

/* Boundary evidence: original MIPS .pdata 00012cb4..00012cd3. Semantic name remains unreviewed. */

void FUN_00012cb4(int param_1)

{
  FUN_000123ec(param_1,1,0);
  return;
}



/* 00012cd4 FUN_00012cd4 */

/* Boundary evidence: original MIPS .pdata 00012cd4..00012d07. Semantic name remains unreviewed. */

int * FUN_00012cd4(int *param_1)

{
  FUN_000123b4(param_1);
  return param_1;
}



/* 00012d08 FUN_00012d08 */

/* Boundary evidence: original MIPS .pdata 00012d08..00012d5b. Semantic name remains unreviewed. */

undefined4 *
FUN_00012d08(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  *param_2 = 0;
  param_2[1] = param_4;
  if (param_1 == (undefined4 *)0x0) {
    FUN_0001859c();
  }
  *param_2 = *param_1;
  return param_2;
}



/* 00012d5c FUN_00012d5c */

/* Boundary evidence: original MIPS .pdata 00012d5c..00012df7. Semantic name remains unreviewed. */

undefined4 * FUN_00012d5c(undefined4 *param_1,undefined4 *param_2,int param_3,int *param_4)

{
  int local_res8;
  int *local_resc;
  
  local_res8 = param_3;
  local_resc = param_4;
  FUN_00011c90(&local_res8);
  if (param_4 != (int *)param_1[5]) {
    *(int *)param_4[1] = *param_4;
    *(int *)(*param_4 + 4) = param_4[1];
    __3_YAXPAX_Z(param_4);
    param_1[6] = param_1[6] + -1;
  }
  FUN_00012d08(param_1,param_2,local_res8,local_resc);
  return param_2;
}



/* 00012df8 FUN_00012df8 */

/* Boundary evidence: original MIPS .pdata 00012df8..00012e53. Semantic name remains unreviewed. */

undefined4 *
FUN_00012df8(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    FUN_0001859c();
  }
  uVar1 = *param_1;
  param_2[1] = param_4;
  *param_2 = uVar1;
  return param_2;
}



/* 00012e54 FUN_00012e54 */

/* Boundary evidence: original MIPS .pdata 00012e54..00012e9f. Semantic name remains unreviewed. */

void FUN_00012e54(int param_1)

{
  FUN_00012470(param_1,*(int **)(*(int *)(param_1 + 0x18) + 4));
  *(int *)(*(int *)(param_1 + 0x18) + 4) = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)*(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(int *)(*(int *)(param_1 + 0x18) + 8) = *(int *)(param_1 + 0x18);
  return;
}



/* 00012ea0 FUN_00012ea0 */

/* Boundary evidence: original MIPS .pdata 00012ea0..00012f8f. Semantic name remains unreviewed. */

bool FUN_00012ea0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  
  if (param_2 == 0xffffffff) {
    FUN_0001847c();
  }
  if (*(uint *)(param_1 + 0x18) < param_2) {
    FUN_000125b8(param_1,param_2,*(rsize_t *)(param_1 + 0x14));
  }
  else if ((param_3 == 0) || (0xf < param_2)) {
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        puVar2 = (undefined1 *)(param_1 + 4);
      }
      else {
        puVar2 = *(undefined1 **)(param_1 + 4);
      }
      *puVar2 = 0;
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x14);
    if (param_2 < *(uint *)(param_1 + 0x14)) {
      uVar1 = param_2;
    }
    FUN_000123ec(param_1,1,uVar1);
  }
  return param_2 != 0;
}



/* 00012f90 FUN_00012f90 */

/* Boundary evidence: original MIPS .pdata 00012f90..000135bf. Semantic name remains unreviewed. */

undefined4
FUN_00012f90(int param_1,int *param_2,int *param_3,undefined4 *param_4,int *param_5,int *param_6)

{
  short sVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  
  *param_6 = 0;
  sVar1 = *(short *)*param_2;
joined_r0x00012fd4:
  if (sVar1 == 0) {
    return 0;
  }
  sVar1 = *(short *)*param_2;
  while (sVar1 != 0) {
    sVar1 = *(short *)*param_2;
    if ((((sVar1 == 0x20) || (sVar1 == 9)) || (sVar1 == 0xd)) || (bVar2 = false, sVar1 == 10)) {
      bVar2 = true;
    }
    if (!bVar2) break;
    psVar5 = (short *)*param_2 + 1;
    *param_2 = (int)psVar5;
    sVar1 = *psVar5;
  }
  psVar5 = (short *)*param_2;
  sVar1 = *psVar5;
  if (sVar1 == 0) {
    return 0;
  }
  if ((sVar1 == 0x3b) || (bVar2 = false, sVar1 == 0x23)) {
    bVar2 = true;
  }
  if (bVar2) {
    FUN_00012830(param_1,param_2,param_6,(ushort *)0x0,'\x01');
  }
  else if (sVar1 == 0x5b) {
    psVar5 = psVar5 + 1;
    *param_2 = (int)psVar5;
    sVar1 = *psVar5;
    while (sVar1 != 0) {
      sVar1 = *psVar5;
      if ((((sVar1 == 0x20) || (sVar1 == 9)) || (sVar1 == 0xd)) || (bVar2 = false, sVar1 == 10)) {
        bVar2 = true;
      }
      if (!bVar2) break;
      psVar5 = psVar5 + 1;
      *param_2 = (int)psVar5;
      sVar1 = *psVar5;
    }
    *param_3 = *param_2;
    if (*(short *)*param_2 != 0) {
      while( true ) {
        sVar1 = *(short *)*param_2;
        if (sVar1 == 0x5d) break;
        if ((sVar1 == 10) || (sVar1 == 0xd)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if ((bVar2) || (psVar5 = (short *)*param_2 + 1, *param_2 = (int)psVar5, *psVar5 == 0))
        break;
      }
    }
    if (*(short *)*param_2 == 0x5d) {
      psVar5 = (short *)*param_2 + -1;
      if ((short *)*param_3 <= psVar5) {
        do {
          sVar1 = *psVar5;
          if ((((sVar1 == 0x20) || (sVar1 == 9)) || (sVar1 == 0xd)) || (bVar2 = false, sVar1 == 10))
          {
            bVar2 = true;
          }
        } while ((bVar2) && (psVar5 = psVar5 + -1, (short *)*param_3 <= psVar5));
      }
      psVar5[1] = 0;
      psVar5 = (short *)(*param_2 + 2);
      *param_2 = (int)psVar5;
      sVar1 = *psVar5;
      while (sVar1 != 0) {
        if ((*psVar5 == 10) || (*psVar5 == 0xd)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) break;
        psVar5 = psVar5 + 1;
        *param_2 = (int)psVar5;
        sVar1 = *psVar5;
      }
      *param_4 = 0;
      *param_5 = 0;
      return 1;
    }
  }
  else {
    *param_4 = psVar5;
    if (*(short *)*param_2 != 0) {
      while( true ) {
        sVar1 = *(short *)*param_2;
        if (sVar1 == 0x3d) break;
        if ((sVar1 == 10) || (sVar1 == 0xd)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if ((bVar2) || (psVar5 = (short *)*param_2 + 1, *param_2 = (int)psVar5, *psVar5 == 0))
        break;
      }
    }
    if (*(short *)*param_2 == 0x3d) {
      if ((short *)*param_4 != (short *)*param_2) {
        psVar5 = (short *)(*param_2 + -2);
        if ((short *)*param_4 <= psVar5) {
          do {
            sVar1 = *psVar5;
            if ((((sVar1 == 0x20) || (sVar1 == 9)) || (sVar1 == 0xd)) ||
               (bVar2 = false, sVar1 == 10)) {
              bVar2 = true;
            }
          } while ((bVar2) && (psVar5 = psVar5 + -1, (short *)*param_4 <= psVar5));
        }
        psVar5[1] = 0;
        psVar5 = (short *)(*param_2 + 2);
        *param_2 = (int)psVar5;
        sVar1 = *psVar5;
        while (sVar1 != 0) {
          sVar1 = *psVar5;
          if ((sVar1 == 10) || (sVar1 == 0xd)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (bVar2) break;
          if ((((sVar1 == 0x20) || (sVar1 == 9)) || (sVar1 == 0xd)) || (bVar2 = false, sVar1 == 10))
          {
            bVar2 = true;
          }
          if (!bVar2) break;
          psVar5 = psVar5 + 1;
          *param_2 = (int)psVar5;
          sVar1 = *psVar5;
        }
        *param_5 = *param_2;
        sVar1 = *(short *)*param_2;
        while (sVar1 != 0) {
          sVar1 = *(short *)*param_2;
          if ((sVar1 == 10) || (sVar1 == 0xd)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (bVar2) break;
          psVar5 = (short *)*param_2 + 1;
          *param_2 = (int)psVar5;
          sVar1 = *psVar5;
        }
        psVar6 = (short *)*param_2;
        psVar5 = psVar6 + -1;
        if (*psVar6 != 0) {
          if ((*psVar6 != 0xd) || (iVar4 = 2, psVar6[1] != 10)) {
            iVar4 = 1;
          }
          *param_2 = (int)(psVar6 + iVar4);
        }
        if ((short *)*param_5 <= psVar5) {
          do {
            sVar1 = *psVar5;
            if ((((sVar1 == 0x20) || (sVar1 == 9)) || (sVar1 == 0xd)) ||
               (bVar2 = false, sVar1 == 10)) {
              bVar2 = true;
            }
          } while ((bVar2) && (psVar5 = psVar5 + -1, (short *)*param_5 <= psVar5));
        }
        psVar5[1] = 0;
        if (*(char *)(param_1 + 0x4a) != '\0') {
          psVar5 = (short *)*param_5;
          if ((*psVar5 == 0x3c) && (psVar5[1] == 0x3c)) {
            bVar2 = false;
            if (psVar5[2] == 0x3c) {
              bVar2 = true;
            }
          }
          else {
            bVar2 = false;
          }
          if (bVar2) {
            uVar3 = FUN_00012830(param_1,param_2,param_5,(ushort *)(psVar5 + 3),'\0');
            return uVar3;
          }
          return 1;
        }
        return 1;
      }
      do {
        sVar1 = *(short *)*param_2;
        if ((sVar1 == 10) || (bVar2 = false, sVar1 == 0xd)) {
          bVar2 = true;
        }
      } while ((!bVar2) && (psVar5 = (short *)*param_2 + 1, *param_2 = (int)psVar5, *psVar5 != 0));
    }
  }
  sVar1 = *(short *)*param_2;
  goto joined_r0x00012fd4;
}



/* 000135c0 FUN_000135c0 */

/* Boundary evidence: original MIPS .pdata 000135c0..00013697. Semantic name remains unreviewed. */

int * FUN_000135c0(int *param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar2;
  int iVar3;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  FUN_00012778(param_1,&local_20,param_3);
  local_14 = param_1[6];
  local_18 = *param_1;
  bVar1 = FUN_00011d90(&local_20,&local_18);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if ((DAT_0001b21c & 1) == 0) {
      DAT_0001b21c = DAT_0001b21c | 1;
    }
    bVar1 = thunk_FUN_00011fec(&DAT_0001b218,(ushort *)*param_3,*(ushort **)(local_1c + 0xc));
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      piVar2 = &local_20;
      goto LAB_0001366c;
    }
  }
  local_14 = param_1[6];
  piVar2 = &local_18;
  local_18 = *param_1;
LAB_0001366c:
  iVar3 = piVar2[1];
  *param_2 = *piVar2;
  param_2[1] = iVar3;
  return param_2;
}



/* 00013698 FUN_00013698 */

/* Boundary evidence: original MIPS .pdata 00013698..000136e7. Semantic name remains unreviewed. */

void FUN_00013698(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_000127d0();
  *(int *)(param_1 + 0x18) = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(int *)(*(int *)(param_1 + 0x18) + 4) = *(int *)(param_1 + 0x18);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(int *)(*(int *)(param_1 + 0x18) + 8) = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}



/* 000136e8 FUN_000136e8 */

/* Boundary evidence: original MIPS .pdata 000136e8..0001376f. Semantic name remains unreviewed. */

void FUN_000136e8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5,undefined1 param_6)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00011978(1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = *param_5;
    puVar1[4] = param_5[1];
    puVar1[5] = param_5[2];
    puVar1[6] = param_5[3];
    *(undefined1 *)(puVar1 + 7) = param_6;
    *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  }
  return;
}



/* 00013770 FUN_00013770 */

/* Boundary evidence: original MIPS .pdata 00013770..0001379f. Semantic name remains unreviewed. */

int * FUN_00013770(int *param_1)

{
  FUN_00012bdc(param_1);
  return param_1;
}



/* 000137a0 FUN_000137a0 */

int FUN_000137a0(int param_1)

{
  int iVar1;
  
  if (*(uint *)(param_1 + 0x24) < 0x10) {
    iVar1 = param_1 + 0x10;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x10);
  }
  return iVar1;
}



/* 000137c8 FUN_000137c8 */

/* Boundary evidence: original MIPS .pdata 000137c8..0001389f. Semantic name remains unreviewed. */

int * FUN_000137c8(int *param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar2;
  int iVar3;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  FUN_00012c0c(param_1,&local_20,param_3);
  local_14 = param_1[6];
  local_18 = *param_1;
  bVar1 = FUN_00011d90(&local_20,&local_18);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if ((DAT_0001b21c & 1) == 0) {
      DAT_0001b21c = DAT_0001b21c | 1;
    }
    bVar1 = thunk_FUN_00011fec(&DAT_0001b218,(ushort *)*param_3,*(ushort **)(local_1c + 0xc));
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      piVar2 = &local_20;
      goto LAB_00013874;
    }
  }
  local_14 = param_1[6];
  piVar2 = &local_18;
  local_18 = *param_1;
LAB_00013874:
  iVar3 = piVar2[1];
  *param_2 = *piVar2;
  param_2[1] = iVar3;
  return param_2;
}



/* 000138a0 FUN_000138a0 */

/* Boundary evidence: original MIPS .pdata 000138a0..000138bb. Semantic name remains unreviewed. */

void FUN_000138a0(undefined4 *param_1)

{
  __3_YAXPAX_Z(*param_1);
  return;
}



/* 000138bc FUN_000138bc */

/* Boundary evidence: original MIPS .pdata 000138bc..0001393f. Semantic name remains unreviewed. */

void FUN_000138bc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00011444(1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_4;
    puVar1[3] = param_4[1];
    puVar1[4] = param_4[2];
  }
  return;
}



/* 00013940 FUN_00013940 */

/* Boundary evidence: original MIPS .pdata 00013940..0001396f. Semantic name remains unreviewed. */

int * FUN_00013940(int *param_1)

{
  FUN_00012cd4(param_1);
  return param_1;
}



/* 00013970 FUN_00013970 */

/* Boundary evidence: original MIPS .pdata 00013970..00013a67. Semantic name remains unreviewed. */

int * FUN_00013970(int *param_1,int *param_2,int param_3,int *param_4,int param_5,undefined4 param_6
                  )

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int *piVar2;
  int iVar3;
  int local_res8;
  int *local_resc;
  int local_18;
  int local_14;
  
  local_14 = *(int *)param_1[5];
  local_18 = *param_1;
  local_res8 = param_3;
  local_resc = param_4;
  bVar1 = FUN_00011d90(&local_res8,&local_18);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    local_14 = param_1[5];
    local_18 = *param_1;
    bVar1 = FUN_00011d90(&param_5,&local_18);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      FUN_0001206c((int)param_1);
      iVar3 = param_1[5];
      *param_2 = 0;
      param_2[1] = iVar3;
      *param_2 = *param_1;
      return param_2;
    }
  }
  while (bVar1 = FUN_00011d90(&local_res8,&param_5), CONCAT31(extraout_var_01,bVar1) == 0) {
    piVar2 = FUN_00012d5c(param_1,&local_18,local_res8,local_resc);
    local_res8 = *piVar2;
    local_resc = (int *)piVar2[1];
  }
  FUN_00012d08(param_1,param_2,param_5,param_6);
  return param_2;
}



/* 00013a68 FUN_00013a68 */

/* Boundary evidence: original MIPS .pdata 00013a68..00013b83. Semantic name remains unreviewed. */

int FUN_00013a68(int param_1,int param_2,uint param_3,uint param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *_Dst;
  int iVar2;
  undefined4 *puVar3;
  uint _MaxCount;
  
  if (*(uint *)(param_2 + 0x14) < param_3) {
    FUN_0001850c();
  }
  _MaxCount = *(int *)(param_2 + 0x14) - param_3;
  if (param_4 < _MaxCount) {
    _MaxCount = param_4;
  }
  if (param_1 == param_2) {
    FUN_000124d4(param_1,_MaxCount + param_3,0xffffffff);
    FUN_000124d4(param_1,0,param_3);
  }
  else {
    bVar1 = FUN_00012ea0(param_1,_MaxCount,0);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        iVar2 = param_2 + 4;
      }
      else {
        iVar2 = *(int *)(param_2 + 4);
      }
      puVar3 = (undefined4 *)(param_1 + 4);
      _Dst = puVar3;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        _Dst = (undefined4 *)*puVar3;
      }
      memcpy_s(_Dst,*(uint *)(param_1 + 0x18),(void *)(iVar2 + param_3),_MaxCount);
      *(uint *)(param_1 + 0x14) = _MaxCount;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      *(undefined1 *)((int)puVar3 + _MaxCount) = 0;
    }
  }
  return param_1;
}



/* 00013b84 FUN_00013b84 */

/* Boundary evidence: original MIPS .pdata 00013b84..00013c6f. Semantic name remains unreviewed. */

int FUN_00013b84(int param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 *_Dst;
  undefined4 *puVar3;
  
  iVar2 = FUN_00011764(param_1,param_2);
  if (iVar2 == 0) {
    bVar1 = FUN_00012ea0(param_1,param_3,0);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      puVar3 = (undefined4 *)(param_1 + 4);
      _Dst = puVar3;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        _Dst = (undefined4 *)*puVar3;
      }
      memcpy_s(_Dst,*(uint *)(param_1 + 0x18),param_2,param_3);
      *(uint *)(param_1 + 0x14) = param_3;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      *(undefined1 *)((int)puVar3 + param_3) = 0;
    }
  }
  else {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      iVar2 = param_1 + 4;
    }
    else {
      iVar2 = *(int *)(param_1 + 4);
    }
    param_1 = FUN_00013a68(param_1,param_1,(int)param_2 - iVar2,param_3);
  }
  return param_1;
}



/* 00013c70 FUN_00013c70 */

/* Boundary evidence: original MIPS .pdata 00013c70..00013d33. Semantic name remains unreviewed. */

undefined4 * FUN_00013c70(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0x18);
  if (*(char *)((int)param_2 + 0x1d) == '\0') {
    puVar1 = (undefined4 *)
             FUN_000136e8(param_1,puVar3,param_3,puVar3,param_2 + 3,*(undefined1 *)(param_2 + 7));
    if (*(char *)((int)puVar3 + 0x1d) != '\0') {
      puVar3 = puVar1;
    }
    puVar2 = FUN_00013c70(param_1,(undefined4 *)*param_2,puVar1);
    *puVar1 = puVar2;
    puVar2 = FUN_00013c70(param_1,(undefined4 *)param_2[2],puVar1);
    puVar1[2] = puVar2;
  }
  return puVar3;
}



/* 00013d34 FUN_00013d34 */

/* Boundary evidence: original MIPS .pdata 00013d34..00013d5f. Semantic name remains unreviewed. */

void FUN_00013d34(void)

{
  undefined4 *in_v0;
  
  FUN_00012470(*in_v0,(int *)in_v0[-8]);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



/* 00013d60 FUN_00013d60 */

/* Boundary evidence: original MIPS .pdata 00013d60..00013e3f. Semantic name remains unreviewed. */

void FUN_00013d60(uint *param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint local_20;
  int *local_1c;
  uint local_18;
  uint local_14;
  
  if ((param_2 < *param_1) || (param_1[1] * 2 + *param_1 <= param_2)) {
    puVar4 = param_1 + 0xb;
    local_1c = *(int **)param_1[0x10];
    local_20 = *puVar4;
    while( true ) {
      local_14 = param_1[0x10];
      local_18 = *puVar4;
      bVar1 = FUN_00011d90((int *)&local_20,(int *)&local_18);
      if (CONCAT31(extraout_var,bVar1) != 0) break;
      puVar2 = (uint *)FUN_00011d14((int *)&local_20);
      if (param_2 == *puVar2) {
        puVar3 = (undefined4 *)FUN_00011d14((int *)&local_20);
        ___V_YAXPAX_Z(*puVar3);
        FUN_00012d5c(puVar4,&local_18,local_20,local_1c);
        return;
      }
      FUN_00011c90((int *)&local_20);
    }
  }
  return;
}



/* 00013e40 FUN_00013e40 */

/* Boundary evidence: original MIPS .pdata 00013e40..00013e7b. Semantic name remains unreviewed. */

void FUN_00013e40(undefined4 *param_1)

{
  FUN_0001206c((int)param_1);
  __3_YAXPAX_Z(param_1[5]);
  param_1[5] = 0;
  __3_YAXPAX_Z(*param_1);
  return;
}



/* 00013e7c FUN_00013e7c */

/* Boundary evidence: original MIPS .pdata 00013e7c..00013eab. Semantic name remains unreviewed. */

int * FUN_00013e7c(int *param_1)

{
  FUN_00013770(param_1);
  return param_1;
}



/* 00013eac FUN_00013eac */

/* Boundary evidence: original MIPS .pdata 00013eac..00014063. Semantic name remains unreviewed. */

undefined4
FUN_00013eac(int param_1,ushort *param_2,ushort *param_3,undefined4 param_4,undefined1 *param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 *puVar3;
  undefined3 extraout_var_02;
  int local_40;
  undefined4 local_3c;
  ushort *local_38;
  undefined4 local_34;
  undefined4 local_30;
  ushort *local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_5 != (undefined1 *)0x0) {
    *param_5 = 0;
  }
  if ((param_2 != (ushort *)0x0) && (param_3 != (ushort *)0x0)) {
    local_24 = 0;
    local_20 = 0;
    local_28 = param_2;
    FUN_000135c0((int *)(param_1 + 0xc),&local_40,&local_28);
    local_24 = *(undefined4 *)(param_1 + 0x24);
    local_28 = *(ushort **)(param_1 + 0xc);
    bVar1 = FUN_00011d90(&local_40,(int *)&local_28);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      local_34 = 0;
      local_30 = 0;
      local_38 = param_3;
      iVar2 = FUN_00011e24(&local_40);
      FUN_000137c8((int *)(iVar2 + 0xc),(int *)&local_28,&local_38);
      iVar2 = FUN_00011e24(&local_40);
      local_34 = *(undefined4 *)(iVar2 + 0x24);
      local_38 = *(ushort **)(iVar2 + 0xc);
      bVar1 = FUN_00011d90((int *)&local_28,(int *)&local_38);
      if (CONCAT31(extraout_var_00,bVar1) == 0) {
        if ((*(char *)(param_1 + 0x49) != '\0') && (param_5 != (undefined1 *)0x0)) {
          local_38 = local_28;
          local_34 = local_24;
          iVar2 = FUN_00011e24(&local_40);
          local_3c = *(undefined4 *)(iVar2 + 0x24);
          local_40 = *(int *)(iVar2 + 0xc);
          FUN_00012110((int *)&local_38);
          bVar1 = FUN_00011d90((int *)&local_38,&local_40);
          if (CONCAT31(extraout_var_01,bVar1) == 0) {
            puVar3 = (undefined4 *)FUN_00011e24((int *)&local_38);
            if ((DAT_0001b214 & 1) == 0) {
              DAT_0001b214 = DAT_0001b214 | 1;
            }
            bVar1 = thunk_FUN_00011fec(&DAT_0001b210,param_3,(ushort *)*puVar3);
            if (CONCAT31(extraout_var_02,bVar1) == 0) {
              *param_5 = 1;
            }
          }
        }
        iVar2 = FUN_00011e24((int *)&local_28);
        param_4 = *(undefined4 *)(iVar2 + 0xc);
      }
    }
  }
  return param_4;
}



/* 00014064 FUN_00014064 */

/* Boundary evidence: original MIPS .pdata 00014064..000140b7. Semantic name remains unreviewed. */

int FUN_00014064(int param_1,int param_2)

{
  FUN_000123ec(param_1,0,0);
  FUN_00013a68(param_1,param_2,0,0xffffffff);
  return param_1;
}



/* 000140b8 FUN_000140b8 */

/* Boundary evidence: original MIPS .pdata 000140b8..0001418b. Semantic name remains unreviewed. */

void FUN_000140b8(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x18);
  puVar3 = FUN_00013c70(param_1,*(undefined4 **)(*(int *)(param_2 + 0x18) + 4),iVar7);
  *(undefined4 **)(iVar7 + 4) = puVar3;
  piVar6 = *(int **)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  piVar4 = (int *)piVar6[1];
  if (*(char *)((int)piVar4 + 0x1d) == '\0') {
    cVar1 = *(char *)(*piVar4 + 0x1d);
    piVar2 = (int *)*piVar4;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*piVar2 + 0x1d);
      piVar4 = piVar2;
      piVar2 = (int *)*piVar2;
    }
    *piVar6 = (int)piVar4;
    iVar7 = *(int *)(*(int *)(param_1 + 0x18) + 4);
    iVar5 = *(int *)(iVar7 + 8);
    cVar1 = *(char *)(iVar5 + 0x1d);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x1d);
      iVar7 = iVar5;
      iVar5 = *(int *)(iVar5 + 8);
    }
    *(int *)(*(int *)(param_1 + 0x18) + 8) = iVar7;
  }
  else {
    *piVar6 = (int)piVar6;
    *(int *)(*(int *)(param_1 + 0x18) + 8) = *(int *)(param_1 + 0x18);
  }
  return;
}



/* 0001418c FUN_0001418c */

/* Boundary evidence: original MIPS .pdata 0001418c..000141bb. Semantic name remains unreviewed. */

int * FUN_0001418c(int *param_1)

{
  FUN_00013940(param_1);
  return param_1;
}



/* 000141bc FUN_000141bc */

/* Boundary evidence: original MIPS .pdata 000141bc..00014213. Semantic name remains unreviewed. */

int * FUN_000141bc(int *param_1)

{
  int iVar1;
  
  FUN_00013e7c(param_1);
  iVar1 = FUN_00012030();
  param_1[5] = iVar1;
  param_1[6] = 0;
  return param_1;
}



/* 00014214 Unwind@00014214 */

/* Boundary evidence: original MIPS .pdata 00014214..00014243. Semantic name remains unreviewed. */

void Unwind_00014214(void)

{
  undefined4 *in_v0;
  
  FUN_000138a0((undefined4 *)*in_v0);
  return;
}



/* 00014244 FUN_00014244 */

/* Boundary evidence: original MIPS .pdata 00014244..000142ab. Semantic name remains unreviewed. */

undefined4 * FUN_00014244(undefined4 *param_1,undefined4 param_2)

{
  __0exception_std__QAA_XZ(param_1);
  *param_1 = std::logic_error::vftable;
  FUN_00014064((int)(param_1 + 3),param_2);
  return param_1;
}



/* 000142ac Unwind@000142ac */

/* Boundary evidence: original MIPS .pdata 000142ac..000142db. Semantic name remains unreviewed. */

void Unwind_000142ac(void)

{
  undefined4 *in_v0;
  
  __1exception_std__UAA_XZ(*in_v0);
  return;
}



/* 000142dc FUN_000142dc */

/* Boundary evidence: original MIPS .pdata 000142dc..0001431f. Semantic name remains unreviewed. */

void FUN_000142dc(undefined4 *param_1)

{
  *param_1 = std::logic_error::vftable;
  FUN_000123ec((int)(param_1 + 3),1,0);
  __1exception_std__UAA_XZ(param_1);
  return;
}



/* 00014320 FUN_00014320 */

/* Boundary evidence: original MIPS .pdata 00014320..00014387. Semantic name remains unreviewed. */

undefined4 * FUN_00014320(undefined4 *param_1,uint param_2)

{
  *param_1 = std::logic_error::vftable;
  FUN_000123ec((int)(param_1 + 3),1,0);
  __1exception_std__UAA_XZ(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00014388 FUN_00014388 */

/* Boundary evidence: original MIPS .pdata 00014388..000143d7. Semantic name remains unreviewed. */

int * FUN_00014388(int *param_1)

{
  FUN_0001418c(param_1);
  FUN_00012c64((int)param_1);
  return param_1;
}



/* 000143d8 Unwind@000143d8 */

/* Boundary evidence: original MIPS .pdata 000143d8..00014407. Semantic name remains unreviewed. */

void Unwind_000143d8(void)

{
  undefined4 *in_v0;
  
  FUN_000138a0((undefined4 *)*in_v0);
  return;
}



/* 00014408 FUN_00014408 */

/* Boundary evidence: original MIPS .pdata 00014408..0001446b. Semantic name remains unreviewed. */

int FUN_00014408(int param_1,char *param_2)

{
  size_t sVar1;
  
  FUN_00012028(param_1);
  FUN_000123ec(param_1,0,0);
  sVar1 = strlen(param_2);
  FUN_00013b84(param_1,(undefined4 *)param_2,sVar1);
  return param_1;
}



/* 0001446c FUN_0001446c */

/* Boundary evidence: original MIPS .pdata 0001446c..000148bf. Semantic name remains unreviewed. */

undefined4 * FUN_0001446c(undefined4 *param_1,undefined4 *param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int local_res8;
  int *local_resc;
  undefined1 auStack_70 [32];
  undefined **appuStack_50 [10];
  uint local_28;
  
  local_28 = DAT_0001b1d4;
  local_res8 = param_3;
  local_resc = param_4;
  if (*(char *)((int)param_4 + 0x1d) != '\0') {
    FUN_00014408((int)auStack_70,"invalid map/set<T> iterator");
    FUN_00014244(appuStack_50,auStack_70);
                    /* WARNING: Subroutine does not return */
    appuStack_50[0] = std::out_of_range::vftable;
    __CxxThrowException(appuStack_50,(ThrowInfo *)&DAT_0001a038);
  }
  FUN_00012110(&local_res8);
  piVar2 = (int *)*param_4;
  if (*(char *)((int)piVar2 + 0x1d) == '\0') {
    piVar6 = piVar2;
    if ((*(char *)(param_4[2] + 0x1d) != '\0') ||
       (piVar6 = (int *)local_resc[2], local_resc == param_4)) goto LAB_00014540;
    piVar2[1] = (int)local_resc;
    *local_resc = *param_4;
    piVar2 = local_resc;
    if (local_resc != (int *)param_4[2]) {
      piVar2 = (int *)local_resc[1];
      if (*(char *)((int)piVar6 + 0x1d) == '\0') {
        piVar6[1] = (int)piVar2;
      }
      *piVar2 = (int)piVar6;
      local_resc[2] = param_4[2];
      *(int **)(param_4[2] + 4) = local_resc;
    }
    if (*(int **)(param_1[6] + 4) == param_4) {
      *(int **)(param_1[6] + 4) = local_resc;
    }
    else {
      puVar4 = (undefined4 *)param_4[1];
      if ((int *)*puVar4 == param_4) {
        *puVar4 = local_resc;
      }
      else {
        puVar4[2] = local_resc;
      }
    }
    piVar3 = param_4 + 7;
    piVar5 = local_resc + 7;
    local_resc[1] = param_4[1];
    if (piVar5 != piVar3) {
      iVar1 = *piVar5;
      *(char *)piVar5 = (char)*piVar3;
      *(char *)piVar3 = (char)iVar1;
    }
  }
  else {
    piVar6 = (int *)param_4[2];
LAB_00014540:
    piVar2 = (int *)param_4[1];
    if (*(char *)((int)piVar6 + 0x1d) == '\0') {
      piVar6[1] = (int)piVar2;
    }
    if (*(int **)(param_1[6] + 4) == param_4) {
      *(int **)(param_1[6] + 4) = piVar6;
    }
    else if ((int *)*piVar2 == param_4) {
      *piVar2 = (int)piVar6;
    }
    else {
      piVar2[2] = (int)piVar6;
    }
    if (*(int **)param_1[6] == param_4) {
      piVar3 = piVar2;
      if (*(char *)((int)piVar6 + 0x1d) == '\0') {
        piVar3 = piVar6;
        for (piVar5 = (int *)*piVar6; *(char *)((int)piVar5 + 0x1d) == '\0'; piVar5 = (int *)*piVar5
            ) {
          piVar3 = piVar5;
        }
      }
      *(int **)param_1[6] = piVar3;
    }
    if (*(int **)(param_1[6] + 8) == param_4) {
      piVar3 = piVar2;
      if (*(char *)((int)piVar6 + 0x1d) == '\0') {
        piVar3 = piVar6;
        for (piVar5 = (int *)piVar6[2]; *(char *)((int)piVar5 + 0x1d) == '\0';
            piVar5 = (int *)piVar5[2]) {
          piVar3 = piVar5;
        }
      }
      *(int **)(param_1[6] + 8) = piVar3;
    }
  }
  if ((char)param_4[7] != '\x01') {
LAB_00014854:
    __3_YAXPAX_Z(param_4);
    if (param_1[7] != 0) {
      param_1[7] = param_1[7] + -1;
    }
    FUN_00012df8(param_1,param_2,local_res8,local_resc);
    FUN_00017eb8(local_28);
    return param_2;
  }
LAB_00014798:
  piVar3 = piVar2;
  if ((piVar6 == *(int **)(param_1[6] + 4)) || ((char)piVar6[7] != '\x01')) goto LAB_00014850;
  piVar2 = (int *)*piVar3;
  if (piVar6 == piVar2) {
    piVar2 = (int *)piVar3[2];
    if ((char)piVar2[7] == '\0') {
      *(undefined1 *)(piVar2 + 7) = 1;
      *(undefined1 *)(piVar3 + 7) = 0;
      FUN_00011694((int)param_1,(int)piVar3);
      piVar2 = (int *)piVar3[2];
    }
    if (*(char *)((int)piVar2 + 0x1d) == '\0') {
      if ((*(char *)(*piVar2 + 0x1c) != '\x01') || (*(char *)(piVar2[2] + 0x1c) != '\x01')) {
        if (*(char *)(piVar2[2] + 0x1c) == '\x01') {
          *(undefined1 *)(*piVar2 + 0x1c) = 1;
          *(undefined1 *)(piVar2 + 7) = 0;
          FUN_000116fc((int)param_1,piVar2);
          piVar2 = (int *)piVar3[2];
        }
        *(char *)(piVar2 + 7) = (char)piVar3[7];
        *(undefined1 *)(piVar3 + 7) = 1;
        *(undefined1 *)(piVar2[2] + 0x1c) = 1;
        FUN_00011694((int)param_1,(int)piVar3);
        goto LAB_00014850;
      }
      *(undefined1 *)(piVar2 + 7) = 0;
    }
  }
  else {
    if ((char)piVar2[7] == '\0') {
      *(undefined1 *)(piVar2 + 7) = 1;
      *(undefined1 *)(piVar3 + 7) = 0;
      FUN_000116fc((int)param_1,piVar3);
      piVar2 = (int *)*piVar3;
    }
    if (*(char *)((int)piVar2 + 0x1d) == '\0') {
      if ((*(char *)(piVar2[2] + 0x1c) != '\x01') || (*(char *)(*piVar2 + 0x1c) != '\x01')) {
        if (*(char *)(*piVar2 + 0x1c) == '\x01') {
          *(undefined1 *)(piVar2[2] + 0x1c) = 1;
          *(undefined1 *)(piVar2 + 7) = 0;
          FUN_00011694((int)param_1,(int)piVar2);
          piVar2 = (int *)*piVar3;
        }
        *(char *)(piVar2 + 7) = (char)piVar3[7];
        *(undefined1 *)(piVar3 + 7) = 1;
        *(undefined1 *)(*piVar2 + 0x1c) = 1;
        FUN_000116fc((int)param_1,piVar3);
LAB_00014850:
        *(undefined1 *)(piVar6 + 7) = 1;
        goto LAB_00014854;
      }
      *(undefined1 *)(piVar2 + 7) = 0;
    }
  }
  piVar2 = (int *)piVar3[1];
  piVar6 = piVar3;
  goto LAB_00014798;
}



/* 000148c0 Unwind@000148c0 */

/* Boundary evidence: original MIPS .pdata 000148c0..000148ef. Semantic name remains unreviewed. */

void Unwind_000148c0(void)

{
  int in_v0;
  
  FUN_00012cb4(in_v0 + -0x70);
  return;
}



/* 000148f0 FUN_000148f0 */

/* Boundary evidence: original MIPS .pdata 000148f0..0001495b. Semantic name remains unreviewed. */

undefined4 * FUN_000148f0(undefined4 *param_1,int param_2)

{
  __0exception_std__QAA_ABV01__Z(param_1,param_2);
  *param_1 = std::logic_error::vftable;
  FUN_00014064((int)(param_1 + 3),param_2 + 0xc);
  return param_1;
}



/* 0001495c Unwind@0001495c */

/* Boundary evidence: original MIPS .pdata 0001495c..0001498b. Semantic name remains unreviewed. */

void Unwind_0001495c(void)

{
  undefined4 *in_v0;
  
  __1exception_std__UAA_XZ(*in_v0);
  return;
}



/* 0001498c FUN_0001498c */

/* Boundary evidence: original MIPS .pdata 0001498c..000149c3. Semantic name remains unreviewed. */

undefined4 * FUN_0001498c(undefined4 *param_1,int param_2)

{
  FUN_000148f0(param_1,param_2);
  *param_1 = std::out_of_range::vftable;
  return param_1;
}



/* 000149c4 FUN_000149c4 */

/* Boundary evidence: original MIPS .pdata 000149c4..00014a13. Semantic name remains unreviewed. */

int * FUN_000149c4(int *param_1)

{
  FUN_0001418c(param_1);
  FUN_00013698((int)param_1);
  return param_1;
}



/* 00014a14 Unwind@00014a14 */

/* Boundary evidence: original MIPS .pdata 00014a14..00014a43. Semantic name remains unreviewed. */

void Unwind_00014a14(void)

{
  undefined4 *in_v0;
  
  FUN_000138a0((undefined4 *)*in_v0);
  return;
}



/* 00014a44 FUN_00014a44 */

/* Boundary evidence: original MIPS .pdata 00014a44..00014cd3. Semantic name remains unreviewed. */

undefined4 *
FUN_00014a44(undefined4 *param_1,undefined4 *param_2,int param_3,int *param_4,undefined4 *param_5)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined1 auStack_70 [32];
  undefined **appuStack_50 [10];
  uint local_28;
  
  local_28 = DAT_0001b1d4;
  if (0xffffffd < (uint)param_1[7]) {
    FUN_00014408((int)auStack_70,"map/set<T> too long");
    FUN_00014244(appuStack_50,auStack_70);
                    /* WARNING: Subroutine does not return */
    appuStack_50[0] = std::length_error::vftable;
    __CxxThrowException(appuStack_50,(ThrowInfo *)&DAT_0001a090);
  }
  piVar2 = (int *)FUN_000136e8(param_1,param_1[6],param_4,param_1[6],param_5,0);
  param_1[7] = param_1[7] + 1;
  if (param_4 == (int *)param_1[6]) {
    ((int *)param_1[6])[1] = (int)piVar2;
    *(int **)param_1[6] = piVar2;
    *(int **)(param_1[6] + 8) = piVar2;
  }
  else if (param_3 == 0) {
    param_4[2] = (int)piVar2;
    if (param_4 == *(int **)(param_1[6] + 8)) {
      *(int **)(param_1[6] + 8) = piVar2;
    }
  }
  else {
    *param_4 = (int)piVar2;
    if (param_4 == *(int **)param_1[6]) {
      *(int **)param_1[6] = piVar2;
    }
  }
  piVar6 = piVar2 + 1;
  cVar1 = *(char *)(*piVar6 + 0x1c);
  piVar7 = piVar2;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(param_1[6] + 4) + 0x1c) = 1;
      *param_2 = 0;
      param_2[1] = piVar2;
      *param_2 = *param_1;
      FUN_00017eb8(local_28);
      return param_2;
    }
    piVar4 = (int *)*piVar6;
    piVar3 = (int *)piVar4[1];
    if (piVar4 == (int *)*piVar3) {
      iVar5 = piVar3[2];
      if (*(char *)(iVar5 + 0x1c) == '\0') {
        *(undefined1 *)(piVar4 + 7) = 1;
        *(undefined1 *)(iVar5 + 0x1c) = 1;
        iVar5 = *(int *)(*piVar6 + 4);
LAB_00014c20:
        *(undefined1 *)(iVar5 + 0x1c) = 0;
        piVar7 = *(int **)(*piVar6 + 4);
      }
      else {
        if (piVar7 == (int *)piVar4[2]) {
          FUN_00011694((int)param_1,(int)piVar4);
          piVar7 = piVar4;
        }
        *(undefined1 *)(piVar7[1] + 0x1c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
        FUN_000116fc((int)param_1,*(int **)(piVar7[1] + 4));
      }
    }
    else {
      iVar5 = *piVar3;
      if (*(char *)(iVar5 + 0x1c) == '\0') {
        *(undefined1 *)(*piVar6 + 0x1c) = 1;
        *(undefined1 *)(iVar5 + 0x1c) = 1;
        iVar5 = *(int *)(*piVar6 + 4);
        goto LAB_00014c20;
      }
      if (piVar7 == (int *)*piVar4) {
        FUN_000116fc((int)param_1,piVar4);
        piVar7 = piVar4;
      }
      *(undefined1 *)(piVar7[1] + 0x1c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
      FUN_00011694((int)param_1,*(int *)(piVar7[1] + 4));
    }
    piVar6 = piVar7 + 1;
    cVar1 = *(char *)(*piVar6 + 0x1c);
  } while( true );
}



/* 00014cd4 Unwind@00014cd4 */

/* Boundary evidence: original MIPS .pdata 00014cd4..00014d03. Semantic name remains unreviewed. */

void Unwind_00014cd4(void)

{
  int in_v0;
  
  FUN_00012cb4(in_v0 + -0x70);
  return;
}



/* 00014d04 FUN_00014d04 */

/* Boundary evidence: original MIPS .pdata 00014d04..00014d9f. Semantic name remains unreviewed. */

void FUN_00014d04(int param_1,uint param_2)

{
  uint uVar1;
  undefined1 auStack_58 [32];
  undefined **appuStack_38 [10];
  uint local_10;
  
  uVar1 = DAT_0001b1d4;
  local_10 = DAT_0001b1d4;
  if (0x15555555U - *(int *)(param_1 + 0x18) < param_2) {
    FUN_00014408((int)auStack_58,"list<T> too long");
    FUN_00014244(appuStack_38,auStack_58);
                    /* WARNING: Subroutine does not return */
    appuStack_38[0] = std::length_error::vftable;
    __CxxThrowException(appuStack_38,(ThrowInfo *)&DAT_0001a090);
  }
  *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + param_2;
  FUN_00017eb8(uVar1);
  return;
}



/* 00014da0 Unwind@00014da0 */

/* Boundary evidence: original MIPS .pdata 00014da0..00014dcf. Semantic name remains unreviewed. */

void Unwind_00014da0(void)

{
  int in_v0;
  
  FUN_00012cb4(in_v0 + -0x58);
  return;
}



/* 00014dd0 FUN_00014dd0 */

/* Boundary evidence: original MIPS .pdata 00014dd0..00014e07. Semantic name remains unreviewed. */

undefined4 * FUN_00014dd0(undefined4 *param_1,int param_2)

{
  FUN_000148f0(param_1,param_2);
  *param_1 = std::length_error::vftable;
  return param_1;
}



/* 00014e08 FUN_00014e08 */

/* Boundary evidence: original MIPS .pdata 00014e08..00014f1f. Semantic name remains unreviewed. */

int * FUN_00014e08(int *param_1,int *param_2,int param_3,int *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar3;
  int local_res8;
  int *local_resc;
  int local_20;
  int local_1c;
  
  local_1c = *(int *)param_1[6];
  local_20 = *param_1;
  local_res8 = param_3;
  local_resc = param_4;
  bVar2 = FUN_00011d90(&local_res8,&local_20);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    local_1c = param_1[6];
    local_20 = *param_1;
    bVar2 = FUN_00011d90((int *)&stack0x00000010,&local_20);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      FUN_00012e54((int)param_1);
      iVar3 = *(int *)param_1[6];
      *param_2 = 0;
      param_2[1] = iVar3;
      *param_2 = *param_1;
      return param_2;
    }
  }
  while (bVar2 = FUN_00011d90(&local_res8,(int *)&stack0x00000010), piVar1 = local_resc,
        iVar3 = local_res8, CONCAT31(extraout_var_01,bVar2) == 0) {
    FUN_00012110(&local_res8);
    FUN_0001446c(param_1,&local_20,iVar3,piVar1);
  }
  FUN_00012df8(param_1,param_2,local_res8,local_resc);
  return param_2;
}



/* 00014f20 FUN_00014f20 */

/* Boundary evidence: original MIPS .pdata 00014f20..0001501f. Semantic name remains unreviewed. */

undefined4 * FUN_00014f20(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  undefined4 auStack_30 [2];
  
  piVar7 = (int *)((int *)param_1[6])[1];
  iVar4 = 1;
  cVar1 = *(char *)((int)piVar7 + 0x1d);
  piVar2 = (int *)param_1[6];
  uVar9 = DAT_0001b21c;
  while (cVar1 == '\0') {
    if ((uVar9 & 1) == 0) {
      uVar9 = uVar9 | 1;
      DAT_0001b21c = uVar9;
    }
    bVar3 = thunk_FUN_00011fec(&DAT_0001b218,(ushort *)*param_3,(ushort *)piVar7[3]);
    iVar4 = CONCAT31(extraout_var,bVar3);
    if (iVar4 == 0) {
      piVar8 = (int *)piVar7[2];
    }
    else {
      piVar8 = (int *)*piVar7;
    }
    piVar2 = piVar7;
    piVar7 = piVar8;
    cVar1 = *(char *)((int)piVar8 + 0x1d);
  }
  puVar5 = FUN_00014a44(param_1,auStack_30,iVar4,piVar2,param_3);
  uVar6 = puVar5[1];
  *param_2 = *puVar5;
  param_2[1] = uVar6;
  *(undefined1 *)(param_2 + 2) = 1;
  return param_2;
}



/* 00015020 FUN_00015020 */

/* Boundary evidence: original MIPS .pdata 00015020..00015087. Semantic name remains unreviewed. */

void FUN_00015020(int param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_000138bc(param_1,param_3,*(undefined4 *)(param_3 + 4),param_4);
  FUN_00014d04(param_1,1);
  *(int *)(param_3 + 4) = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  return;
}



/* 00015088 FUN_00015088 */

/* Boundary evidence: original MIPS .pdata 00015088..000150d7. Semantic name remains unreviewed. */

void FUN_00015088(int *param_1)

{
  int aiStack_10 [2];
  
  FUN_00014e08(param_1,aiStack_10,*param_1,*(int **)param_1[6]);
  __3_YAXPAX_Z(param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}



/* 000150d8 FUN_000150d8 */

/* Boundary evidence: original MIPS .pdata 000150d8..00015147. Semantic name remains unreviewed. */

int * FUN_000150d8(int *param_1,int param_2)

{
  FUN_0001418c(param_1);
  FUN_00013698((int)param_1);
  FUN_000140b8((int)param_1,param_2);
  return param_1;
}



/* 00015148 FUN_00015148 */

/* Boundary evidence: original MIPS .pdata 00015148..0001516f. Semantic name remains unreviewed. */

void FUN_00015148(void)

{
  undefined4 *in_v0;
  
  FUN_00015088((int *)*in_v0);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



/* 00015170 Unwind@00015170 */

/* Boundary evidence: original MIPS .pdata 00015170..0001519f. Semantic name remains unreviewed. */

void Unwind_00015170(void)

{
  undefined4 *in_v0;
  
  FUN_000138a0((undefined4 *)*in_v0);
  return;
}



/* 000151a0 FUN_000151a0 */

/* Boundary evidence: original MIPS .pdata 000151a0..000151e7. Semantic name remains unreviewed. */

void FUN_000151a0(int *param_1)

{
  FUN_00015088(param_1);
  __3_YAXPAX_Z(*param_1);
  return;
}



/* 000151e8 Unwind@000151e8 */

/* Boundary evidence: original MIPS .pdata 000151e8..00015217. Semantic name remains unreviewed. */

void Unwind_000151e8(void)

{
  undefined4 *in_v0;
  
  FUN_000138a0((undefined4 *)*in_v0);
  return;
}



/* 00015218 FUN_00015218 */

/* Boundary evidence: original MIPS .pdata 00015218..000152d7. Semantic name remains unreviewed. */

undefined4 FUN_00015218(int param_1,undefined4 *param_2)

{
  size_t sVar1;
  void *_Dst;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  void *local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  sVar1 = wcslen((wchar_t *)*param_2);
  uVar4 = sVar1 + 1;
  if (uVar4 < 0x80000000) {
    iVar3 = uVar4 * 2;
  }
  else {
    iVar3 = -1;
  }
  _Dst = (void *)___U_YAPAXIABUnothrow_t_std___Z(iVar3,&LAB_00018040);
  if (_Dst == (void *)0x0) {
    uVar2 = 0xfffffffe;
  }
  else {
    memcpy(_Dst,(void *)*param_2,uVar4 * 2);
    local_24 = 0;
    local_20 = 0;
    local_28 = _Dst;
    FUN_00015020(param_1 + 0x2c,*(undefined4 *)(param_1 + 0x2c),*(int *)(param_1 + 0x40),&local_28);
    *param_2 = _Dst;
    uVar2 = 0;
  }
  return uVar2;
}



/* 000152d8 FUN_000152d8 */

/* Boundary evidence: original MIPS .pdata 000152d8..0001537f. Semantic name remains unreviewed. */

void FUN_000152d8(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  FUN_0001206c((int)param_2);
  local_1c = **(undefined4 **)(param_1 + 0x24);
  local_20 = *(int *)(param_1 + 0xc);
  while( true ) {
    local_14 = *(undefined4 *)(param_1 + 0x24);
    local_18 = *(int *)(param_1 + 0xc);
    bVar1 = FUN_00011d90(&local_20,&local_18);
    if (CONCAT31(extraout_var,bVar1) != 0) break;
    puVar2 = (undefined4 *)FUN_00011e24(&local_20);
    FUN_00015020((int)param_2,*param_2,param_2[5],puVar2);
    FUN_00011ea0(&local_20);
  }
  return;
}



/* 00015380 FUN_00015380 */

/* Boundary evidence: original MIPS .pdata 00015380..0001539b. Semantic name remains unreviewed. */

void FUN_00015380(int *param_1)

{
  FUN_000151a0(param_1);
  return;
}



/* 0001539c FUN_0001539c */

/* Boundary evidence: original MIPS .pdata 0001539c..00015417. Semantic name remains unreviewed. */

int FUN_0001539c(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 8);
  if ((((*piVar2 == 0) &&
       (iVar1 = FUN_00012830(param_1,param_2,piVar2,(ushort *)0x0,'\0'), iVar1 != 0)) &&
      (param_3 != 0)) && (iVar1 = FUN_00015218(param_1,piVar2), iVar1 < 0)) {
    return iVar1;
  }
  return 0;
}



/* 00015418 FUN_00015418 */

/* Boundary evidence: original MIPS .pdata 00015418..00015433. Semantic name remains unreviewed. */

void FUN_00015418(int param_1)

{
  FUN_000151a0((int *)(param_1 + 0xc));
  return;
}



/* 00015434 FUN_00015434 */

/* Boundary evidence: original MIPS .pdata 00015434..0001549b. Semantic name remains unreviewed. */

undefined4 *
FUN_00015434(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,undefined1 param_6)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = *param_5;
  param_1[4] = param_5[1];
  param_1[5] = param_5[2];
  FUN_000150d8(param_1 + 6,(int)(param_5 + 3));
  *(undefined1 *)(param_1 + 0xe) = param_6;
  *(undefined1 *)((int)param_1 + 0x39) = 0;
  return param_1;
}



/* 0001549c FUN_0001549c */

/* Boundary evidence: original MIPS .pdata 0001549c..00015537. Semantic name remains unreviewed. */

undefined4 *
FUN_0001549c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,undefined1 param_6)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00011610(1);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00015434(puVar1,param_2,param_3,param_4,param_5,param_6);
  }
  return puVar1;
}



/* 00015538 FUN_00015538 */

/* Boundary evidence: original MIPS .pdata 00015538..0001555f. Semantic name remains unreviewed. */

void FUN_00015538(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x20));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



/* 00015560 Unwind@00015560 */

/* Boundary evidence: original MIPS .pdata 00015560..00015593. Semantic name remains unreviewed. */

void Unwind_00015560(void)

{
  FUN_0001143c();
  return;
}



/* 00015594 FUN_00015594 */

/* Boundary evidence: original MIPS .pdata 00015594..00015823. Semantic name remains unreviewed. */

undefined4 *
FUN_00015594(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined1 auStack_70 [32];
  undefined **appuStack_50 [10];
  uint local_28;
  
  local_28 = DAT_0001b1d4;
  if (0x5d1745b < (uint)param_1[7]) {
    FUN_00014408((int)auStack_70,"map/set<T> too long");
    FUN_00014244(appuStack_50,auStack_70);
                    /* WARNING: Subroutine does not return */
    appuStack_50[0] = std::length_error::vftable;
    __CxxThrowException(appuStack_50,(ThrowInfo *)&DAT_0001a090);
  }
  piVar2 = FUN_0001549c(param_1,param_1[6],param_4,param_1[6],param_5,0);
  param_1[7] = param_1[7] + 1;
  if (param_4 == (undefined4 *)param_1[6]) {
    ((undefined4 *)param_1[6])[1] = piVar2;
    *(int **)param_1[6] = piVar2;
    *(int **)(param_1[6] + 8) = piVar2;
  }
  else if (param_3 == 0) {
    param_4[2] = piVar2;
    if (param_4 == *(undefined4 **)(param_1[6] + 8)) {
      *(int **)(param_1[6] + 8) = piVar2;
    }
  }
  else {
    *param_4 = piVar2;
    if (param_4 == *(undefined4 **)param_1[6]) {
      *(int **)param_1[6] = piVar2;
    }
  }
  piVar6 = piVar2 + 1;
  cVar1 = *(char *)(*piVar6 + 0x38);
  piVar7 = piVar2;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(param_1[6] + 4) + 0x38) = 1;
      *param_2 = 0;
      param_2[1] = piVar2;
      *param_2 = *param_1;
      FUN_00017eb8(local_28);
      return param_2;
    }
    piVar4 = (int *)*piVar6;
    piVar3 = (int *)piVar4[1];
    if (piVar4 == (int *)*piVar3) {
      iVar5 = piVar3[2];
      if (*(char *)(iVar5 + 0x38) == '\0') {
        *(undefined1 *)(piVar4 + 0xe) = 1;
        *(undefined1 *)(iVar5 + 0x38) = 1;
        iVar5 = *(int *)(*piVar6 + 4);
LAB_00015770:
        *(undefined1 *)(iVar5 + 0x38) = 0;
        piVar7 = *(int **)(*piVar6 + 4);
      }
      else {
        if (piVar7 == (int *)piVar4[2]) {
          FUN_00011540((int)param_1,(int)piVar4);
          piVar7 = piVar4;
        }
        *(undefined1 *)(piVar7[1] + 0x38) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x38) = 0;
        FUN_000115a8((int)param_1,*(int **)(piVar7[1] + 4));
      }
    }
    else {
      iVar5 = *piVar3;
      if (*(char *)(iVar5 + 0x38) == '\0') {
        *(undefined1 *)(*piVar6 + 0x38) = 1;
        *(undefined1 *)(iVar5 + 0x38) = 1;
        iVar5 = *(int *)(*piVar6 + 4);
        goto LAB_00015770;
      }
      if (piVar7 == (int *)*piVar4) {
        FUN_000115a8((int)param_1,piVar4);
        piVar7 = piVar4;
      }
      *(undefined1 *)(piVar7[1] + 0x38) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x38) = 0;
      FUN_00011540((int)param_1,*(int *)(piVar7[1] + 4));
    }
    piVar6 = piVar7 + 1;
    cVar1 = *(char *)(*piVar6 + 0x38);
  } while( true );
}



/* 00015824 Unwind@00015824 */

/* Boundary evidence: original MIPS .pdata 00015824..00015853. Semantic name remains unreviewed. */

void Unwind_00015824(void)

{
  int in_v0;
  
  FUN_00012cb4(in_v0 + -0x70);
  return;
}



/* 00015854 FUN_00015854 */

/* Boundary evidence: original MIPS .pdata 00015854..00015a2b. Semantic name remains unreviewed. */

int * FUN_00015854(int *param_1,int *param_2,undefined4 *param_3)

{
  char cVar1;
  int *piVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 *puVar4;
  undefined3 extraout_var_01;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int *local_38;
  undefined4 local_34;
  int *local_30;
  undefined4 *local_2c;
  
  puVar7 = (undefined4 *)((undefined4 *)param_1[6])[1];
  iVar9 = 1;
  cVar1 = *(char *)((int)puVar7 + 0x39);
  puVar4 = (undefined4 *)param_1[6];
  uVar6 = DAT_0001b21c;
  while (cVar1 == '\0') {
    if ((uVar6 & 1) == 0) {
      uVar6 = uVar6 | 1;
      DAT_0001b21c = uVar6;
    }
    local_38 = param_2;
    local_30 = param_1;
    bVar3 = thunk_FUN_00011fec(&DAT_0001b218,(ushort *)*param_3,(ushort *)puVar7[3]);
    iVar9 = CONCAT31(extraout_var,bVar3);
    if (iVar9 == 0) {
      puVar8 = (undefined4 *)puVar7[2];
    }
    else {
      puVar8 = (undefined4 *)*puVar7;
    }
    puVar4 = puVar7;
    puVar7 = puVar8;
    param_1 = local_30;
    param_2 = local_38;
    cVar1 = *(char *)((int)puVar8 + 0x39);
  }
  local_38 = (int *)*param_1;
  piVar2 = param_2;
  local_30 = local_38;
  local_2c = puVar4;
  if (iVar9 != 0) {
    local_34 = *(undefined4 *)param_1[6];
    bVar3 = FUN_00011d90((int *)&local_30,(int *)&local_38);
    if (CONCAT31(extraout_var_00,bVar3) != 0) {
      puVar4 = FUN_00015594(param_1,&local_30,1,puVar4,param_3);
      goto LAB_00015970;
    }
    FUN_00011870((int *)&local_30);
    uVar6 = DAT_0001b21c;
    piVar2 = local_38;
  }
  local_38 = piVar2;
  puVar7 = local_2c;
  piVar2 = local_30;
  if ((uVar6 & 1) == 0) {
    DAT_0001b21c = uVar6 | 1;
  }
  bVar3 = thunk_FUN_00011fec(&DAT_0001b218,(ushort *)local_2c[3],(ushort *)*param_3);
  if (CONCAT31(extraout_var_01,bVar3) == 0) {
    *param_2 = (int)piVar2;
    param_2[1] = (int)puVar7;
    *(undefined1 *)(param_2 + 2) = 0;
    return param_2;
  }
  puVar4 = FUN_00015594(param_1,&local_30,iVar9,puVar4,param_3);
LAB_00015970:
  uVar5 = puVar4[1];
  *param_2 = *puVar4;
  param_2[1] = uVar5;
  *(undefined1 *)(param_2 + 2) = 1;
  return param_2;
}



/* 00015a2c FUN_00015a2c */

/* Boundary evidence: original MIPS .pdata 00015a2c..00015e87. Semantic name remains unreviewed. */

undefined4 * FUN_00015a2c(undefined4 *param_1,undefined4 *param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int local_res8;
  int *local_resc;
  undefined1 auStack_70 [32];
  undefined **appuStack_50 [10];
  uint local_28;
  
  local_28 = DAT_0001b1d4;
  local_res8 = param_3;
  local_resc = param_4;
  if (*(char *)((int)param_4 + 0x39) != '\0') {
    FUN_00014408((int)auStack_70,"invalid map/set<T> iterator");
    FUN_00014244(appuStack_50,auStack_70);
                    /* WARNING: Subroutine does not return */
    appuStack_50[0] = std::out_of_range::vftable;
    __CxxThrowException(appuStack_50,(ThrowInfo *)&DAT_0001a038);
  }
  FUN_00011ea0(&local_res8);
  piVar2 = (int *)*param_4;
  if (*(char *)((int)piVar2 + 0x39) == '\0') {
    piVar6 = piVar2;
    if ((*(char *)(param_4[2] + 0x39) != '\0') ||
       (piVar6 = (int *)local_resc[2], local_resc == param_4)) goto LAB_00015b00;
    piVar2[1] = (int)local_resc;
    *local_resc = *param_4;
    piVar2 = local_resc;
    if (local_resc != (int *)param_4[2]) {
      piVar2 = (int *)local_resc[1];
      if (*(char *)((int)piVar6 + 0x39) == '\0') {
        piVar6[1] = (int)piVar2;
      }
      *piVar2 = (int)piVar6;
      local_resc[2] = param_4[2];
      *(int **)(param_4[2] + 4) = local_resc;
    }
    if (*(int **)(param_1[6] + 4) == param_4) {
      *(int **)(param_1[6] + 4) = local_resc;
    }
    else {
      puVar4 = (undefined4 *)param_4[1];
      if ((int *)*puVar4 == param_4) {
        *puVar4 = local_resc;
      }
      else {
        puVar4[2] = local_resc;
      }
    }
    piVar3 = param_4 + 0xe;
    piVar5 = local_resc + 0xe;
    local_resc[1] = param_4[1];
    if (piVar5 != piVar3) {
      iVar1 = *piVar5;
      *(char *)piVar5 = (char)*piVar3;
      *(char *)piVar3 = (char)iVar1;
    }
  }
  else {
    piVar6 = (int *)param_4[2];
LAB_00015b00:
    piVar2 = (int *)param_4[1];
    if (*(char *)((int)piVar6 + 0x39) == '\0') {
      piVar6[1] = (int)piVar2;
    }
    if (*(int **)(param_1[6] + 4) == param_4) {
      *(int **)(param_1[6] + 4) = piVar6;
    }
    else if ((int *)*piVar2 == param_4) {
      *piVar2 = (int)piVar6;
    }
    else {
      piVar2[2] = (int)piVar6;
    }
    if (*(int **)param_1[6] == param_4) {
      piVar3 = piVar2;
      if (*(char *)((int)piVar6 + 0x39) == '\0') {
        piVar3 = piVar6;
        for (piVar5 = (int *)*piVar6; *(char *)((int)piVar5 + 0x39) == '\0'; piVar5 = (int *)*piVar5
            ) {
          piVar3 = piVar5;
        }
      }
      *(int **)param_1[6] = piVar3;
    }
    if (*(int **)(param_1[6] + 8) == param_4) {
      piVar3 = piVar2;
      if (*(char *)((int)piVar6 + 0x39) == '\0') {
        piVar3 = piVar6;
        for (piVar5 = (int *)piVar6[2]; *(char *)((int)piVar5 + 0x39) == '\0';
            piVar5 = (int *)piVar5[2]) {
          piVar3 = piVar5;
        }
      }
      *(int **)(param_1[6] + 8) = piVar3;
    }
  }
  if ((char)param_4[0xe] != '\x01') {
LAB_00015e14:
    FUN_000151a0(param_4 + 6);
    __3_YAXPAX_Z(param_4);
    if (param_1[7] != 0) {
      param_1[7] = param_1[7] + -1;
    }
    FUN_00012df8(param_1,param_2,local_res8,local_resc);
    FUN_00017eb8(local_28);
    return param_2;
  }
LAB_00015d58:
  piVar3 = piVar2;
  if ((piVar6 == *(int **)(param_1[6] + 4)) || ((char)piVar6[0xe] != '\x01')) goto LAB_00015e10;
  piVar2 = (int *)*piVar3;
  if (piVar6 == piVar2) {
    piVar2 = (int *)piVar3[2];
    if ((char)piVar2[0xe] == '\0') {
      *(undefined1 *)(piVar2 + 0xe) = 1;
      *(undefined1 *)(piVar3 + 0xe) = 0;
      FUN_00011540((int)param_1,(int)piVar3);
      piVar2 = (int *)piVar3[2];
    }
    if (*(char *)((int)piVar2 + 0x39) == '\0') {
      if ((*(char *)(*piVar2 + 0x38) != '\x01') || (*(char *)(piVar2[2] + 0x38) != '\x01')) {
        if (*(char *)(piVar2[2] + 0x38) == '\x01') {
          *(undefined1 *)(*piVar2 + 0x38) = 1;
          *(undefined1 *)(piVar2 + 0xe) = 0;
          FUN_000115a8((int)param_1,piVar2);
          piVar2 = (int *)piVar3[2];
        }
        *(char *)(piVar2 + 0xe) = (char)piVar3[0xe];
        *(undefined1 *)(piVar3 + 0xe) = 1;
        *(undefined1 *)(piVar2[2] + 0x38) = 1;
        FUN_00011540((int)param_1,(int)piVar3);
        goto LAB_00015e10;
      }
      *(undefined1 *)(piVar2 + 0xe) = 0;
    }
  }
  else {
    if ((char)piVar2[0xe] == '\0') {
      *(undefined1 *)(piVar2 + 0xe) = 1;
      *(undefined1 *)(piVar3 + 0xe) = 0;
      FUN_000115a8((int)param_1,piVar3);
      piVar2 = (int *)*piVar3;
    }
    if (*(char *)((int)piVar2 + 0x39) == '\0') {
      if ((*(char *)(piVar2[2] + 0x38) != '\x01') || (*(char *)(*piVar2 + 0x38) != '\x01')) {
        if (*(char *)(*piVar2 + 0x38) == '\x01') {
          *(undefined1 *)(piVar2[2] + 0x38) = 1;
          *(undefined1 *)(piVar2 + 0xe) = 0;
          FUN_00011540((int)param_1,(int)piVar2);
          piVar2 = (int *)*piVar3;
        }
        *(char *)(piVar2 + 0xe) = (char)piVar3[0xe];
        *(undefined1 *)(piVar3 + 0xe) = 1;
        *(undefined1 *)(*piVar2 + 0x38) = 1;
        FUN_000115a8((int)param_1,piVar3);
LAB_00015e10:
        *(undefined1 *)(piVar6 + 0xe) = 1;
        goto LAB_00015e14;
      }
      *(undefined1 *)(piVar2 + 0xe) = 0;
    }
  }
  piVar2 = (int *)piVar3[1];
  piVar6 = piVar3;
  goto LAB_00015d58;
}



/* 00015e88 Unwind@00015e88 */

/* Boundary evidence: original MIPS .pdata 00015e88..00015eb7. Semantic name remains unreviewed. */

void Unwind_00015e88(void)

{
  int in_v0;
  
  FUN_00012cb4(in_v0 + -0x70);
  return;
}



/* 00015eb8 FUN_00015eb8 */

/* Boundary evidence: original MIPS .pdata 00015eb8..00015f23. Semantic name remains unreviewed. */

void FUN_00015eb8(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_2 + 0x39);
  while (cVar1 == '\0') {
    FUN_00015eb8(param_1,(int *)param_2[2]);
    piVar2 = (int *)*param_2;
    FUN_000151a0(param_2 + 6);
    __3_YAXPAX_Z(param_2);
    param_2 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x39);
  }
  return;
}



/* 00015f24 FUN_00015f24 */

/* Boundary evidence: original MIPS .pdata 00015f24..0001627b. Semantic name remains unreviewed. */

undefined4 FUN_00015f24(uint *param_1,ushort *param_2,ushort *param_3,ushort *param_4,char param_5)

{
  undefined *puVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint *puVar6;
  undefined3 extraout_var_03;
  undefined4 *puVar7;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined *local_58;
  int *local_54;
  int local_50;
  int *local_4c;
  undefined *local_48;
  int *local_44;
  int local_40;
  undefined4 local_3c;
  ushort *local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  if (param_2 != (ushort *)0x0) {
    local_34 = 0;
    local_30 = 0;
    local_38 = param_2;
    FUN_000135c0((int *)(param_1 + 3),&local_50,&local_38);
    local_44 = (int *)param_1[9];
    local_48 = (undefined *)param_1[3];
    bVar3 = FUN_00011d90(&local_50,(int *)&local_48);
    if (CONCAT31(extraout_var,bVar3) == 0) {
      if (param_3 == (ushort *)0x0) {
        iVar5 = FUN_00011e24(&local_50);
        local_44 = (int *)**(undefined4 **)(iVar5 + 0x24);
        local_48 = *(undefined **)(iVar5 + 0xc);
        while( true ) {
          iVar5 = FUN_00011e24(&local_50);
          local_3c = *(undefined4 *)(iVar5 + 0x24);
          local_40 = *(int *)(iVar5 + 0xc);
          bVar3 = FUN_00011d90((int *)&local_48,&local_40);
          if (CONCAT31(extraout_var_05,bVar3) != 0) break;
          puVar6 = (uint *)FUN_00011e24((int *)&local_48);
          FUN_00013d60(param_1,*puVar6);
          iVar5 = FUN_00011e24((int *)&local_48);
          FUN_00013d60(param_1,*(uint *)(iVar5 + 0xc));
          FUN_00012110((int *)&local_48);
        }
LAB_0001618c:
        puVar6 = (uint *)FUN_00011e24(&local_50);
        FUN_00013d60(param_1,*puVar6);
        FUN_00015a2c(param_1 + 3,&local_38,local_50,local_4c);
        return 1;
      }
      local_34 = 0;
      local_30 = 0;
      local_38 = param_3;
      iVar5 = FUN_00011e24(&local_50);
      FUN_000137c8((int *)(iVar5 + 0xc),(int *)&local_48,&local_38);
      iVar5 = FUN_00011e24(&local_50);
      local_54 = *(int **)(iVar5 + 0x24);
      local_58 = *(undefined **)(iVar5 + 0xc);
      bVar3 = FUN_00011d90((int *)&local_48,(int *)&local_58);
      if (CONCAT31(extraout_var_00,bVar3) == 0) {
        if ((DAT_0001b224 & 1) == 0) {
          DAT_0001b224 = DAT_0001b224 | 1;
        }
        bVar3 = false;
        local_58 = &DAT_0001b220;
        do {
          piVar2 = local_44;
          puVar1 = local_48;
          FUN_00012110((int *)&local_48);
          local_58 = puVar1;
          local_54 = piVar2;
          if (param_4 == (ushort *)0x0) {
LAB_00016090:
            puVar6 = (uint *)FUN_00011e24((int *)&local_58);
            FUN_00013d60(param_1,*puVar6);
            iVar5 = FUN_00011e24((int *)&local_58);
            FUN_00013d60(param_1,*(uint *)(iVar5 + 0xc));
            iVar5 = FUN_00011e24(&local_50);
            FUN_0001446c((undefined4 *)(iVar5 + 0xc),&local_38,(int)puVar1,piVar2);
            bVar3 = true;
          }
          else {
            iVar5 = FUN_00011e24((int *)&local_58);
            bVar4 = thunk_FUN_00011fec(&DAT_0001b220,param_4,*(ushort **)(iVar5 + 0xc));
            if (CONCAT31(extraout_var_01,bVar4) == 0) {
              iVar5 = FUN_00011e24((int *)&local_58);
              bVar4 = thunk_FUN_00011fec(&DAT_0001b220,*(ushort **)(iVar5 + 0xc),param_4);
              if (CONCAT31(extraout_var_02,bVar4) == 0) goto LAB_00016090;
            }
          }
          iVar5 = FUN_00011e24(&local_50);
          local_3c = *(undefined4 *)(iVar5 + 0x24);
          local_40 = *(int *)(iVar5 + 0xc);
          bVar4 = FUN_00011d90((int *)&local_48,&local_40);
          if (CONCAT31(extraout_var_03,bVar4) != 0) break;
          puVar7 = (undefined4 *)FUN_00011e24((int *)&local_48);
          if ((DAT_0001b214 & 1) == 0) {
            DAT_0001b214 = DAT_0001b214 | 1;
          }
          bVar4 = thunk_FUN_00011fec(&DAT_0001b210,param_3,(ushort *)*puVar7);
        } while (CONCAT31(extraout_var_04,bVar4) == 0);
        if (bVar3) {
          if (param_5 == '\0') {
            return 1;
          }
          iVar5 = FUN_00011e24(&local_50);
          if (*(int *)(iVar5 + 0x28) != 0) {
            return 1;
          }
          goto LAB_0001618c;
        }
      }
    }
  }
  return 0;
}



/* 0001627c FUN_0001627c */

/* Boundary evidence: original MIPS .pdata 0001627c..000162c7. Semantic name remains unreviewed. */

void FUN_0001627c(int param_1)

{
  FUN_00015eb8(param_1,*(int **)(*(int *)(param_1 + 0x18) + 4));
  *(int *)(*(int *)(param_1 + 0x18) + 4) = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)*(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(int *)(*(int *)(param_1 + 0x18) + 8) = *(int *)(param_1 + 0x18);
  return;
}



/* 000162c8 FUN_000162c8 */

/* Boundary evidence: original MIPS .pdata 000162c8..000163df. Semantic name remains unreviewed. */

int * FUN_000162c8(int *param_1,int *param_2,int param_3,int *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar3;
  int local_res8;
  int *local_resc;
  int local_20;
  int local_1c;
  
  local_1c = *(int *)param_1[6];
  local_20 = *param_1;
  local_res8 = param_3;
  local_resc = param_4;
  bVar2 = FUN_00011d90(&local_res8,&local_20);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    local_1c = param_1[6];
    local_20 = *param_1;
    bVar2 = FUN_00011d90((int *)&stack0x00000010,&local_20);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      FUN_0001627c((int)param_1);
      iVar3 = *(int *)param_1[6];
      *param_2 = 0;
      param_2[1] = iVar3;
      *param_2 = *param_1;
      return param_2;
    }
  }
  while (bVar2 = FUN_00011d90(&local_res8,(int *)&stack0x00000010), piVar1 = local_resc,
        iVar3 = local_res8, CONCAT31(extraout_var_01,bVar2) == 0) {
    FUN_00011ea0(&local_res8);
    FUN_00015a2c(param_1,&local_20,iVar3,piVar1);
  }
  FUN_00012df8(param_1,param_2,local_res8,local_resc);
  return param_2;
}



/* 000163e0 FUN_000163e0 */

/* Boundary evidence: original MIPS .pdata 000163e0..00016503. Semantic name remains unreviewed. */

void FUN_000163e0(undefined4 *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int *piVar3;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  
  ___V_YAXPAX_Z(*param_1);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (param_1[10] != 0) {
    FUN_000162c8(param_1 + 3,&local_10,param_1[3],*(int **)param_1[9]);
  }
  if (param_1[0x11] != 0) {
    piVar3 = param_1 + 0xb;
    local_14 = *(undefined4 *)param_1[0x10];
    local_18 = *piVar3;
    while( true ) {
      local_c = param_1[0x10];
      local_10 = *piVar3;
      bVar1 = FUN_00011d90(&local_18,&local_10);
      if (CONCAT31(extraout_var,bVar1) != 0) break;
      puVar2 = (undefined4 *)FUN_00011d14(&local_18);
      ___V_YAXPAX_Z(*puVar2);
      FUN_00011c90(&local_18);
    }
    FUN_00013970(piVar3,&local_10,*piVar3,*(int **)param_1[0x10],*piVar3,(undefined4 *)param_1[0x10]
                );
  }
  return;
}



/* 00016504 FUN_00016504 */

/* Boundary evidence: original MIPS .pdata 00016504..00016983. Semantic name remains unreviewed. */

int FUN_00016504(uint *param_1,ushort *param_2,ushort *param_3,int param_4,uint param_5,char param_6
                ,byte param_7)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 *puVar5;
  undefined3 extraout_var_02;
  int iVar6;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  char cVar11;
  ushort *local_res4;
  ushort *local_res8;
  int local_resc;
  uint local_ac;
  ushort *local_a8;
  uint local_a4;
  uint local_a0;
  undefined4 local_9c;
  uint *local_98;
  int local_94;
  uint local_90;
  undefined4 local_8c;
  ushort *local_80;
  uint local_7c;
  int aiStack_78 [8];
  ushort *local_58;
  uint local_54;
  uint local_50;
  int aiStack_4c [9];
  
  uVar7 = (uint)param_7;
  bVar3 = false;
  bVar1 = false;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  local_98 = param_1;
  local_94 = param_4;
  local_90 = uVar7;
  if (((uVar7 != 0) && (param_5 != 0)) && (iVar4 = FUN_00015218((int)param_1,&param_5), iVar4 < 0))
  {
    return iVar4;
  }
  uVar9 = param_5;
  puVar10 = param_1 + 3;
  local_a4 = 0;
  local_a0 = 0;
  local_a8 = param_2;
  FUN_000135c0((int *)puVar10,(int *)&local_80,&local_a8);
  local_a4 = param_1[9];
  local_a8 = (ushort *)*puVar10;
  bVar2 = FUN_00011d90((int *)&local_80,(int *)&local_a8);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    if ((uVar7 != 0) &&
       (iVar4 = FUN_00015218((int)param_1,&local_res4), param_2 = local_res4, iVar4 < 0)) {
      return iVar4;
    }
    uVar8 = param_1[0x13];
    param_1[0x13] = uVar8 + 1;
    uVar7 = 0;
    if ((uVar9 != 0) && ((param_3 == (ushort *)0x0 || (param_4 == 0)))) {
      uVar7 = uVar9;
    }
    FUN_000149c4(aiStack_78);
    local_58 = param_2;
    local_54 = uVar7;
    local_50 = uVar8 + 1;
    FUN_000150d8(aiStack_4c,(int)aiStack_78);
    FUN_000151a0(aiStack_78);
    FUN_00015854((int *)puVar10,(int *)&local_a8,&local_58);
    bVar3 = true;
    local_80 = local_a8;
    local_7c = local_a4;
    bVar1 = true;
    FUN_000151a0(aiStack_4c);
  }
  if ((param_3 == (ushort *)0x0) || (param_4 == 0)) {
    if (!bVar3) {
      return 1;
    }
    return 2;
  }
  iVar4 = FUN_00011e24((int *)&local_80);
  puVar10 = (uint *)(iVar4 + 0xc);
  local_a4 = 0;
  local_a0 = 0;
  local_a8 = param_3;
  FUN_000137c8((int *)puVar10,(int *)&local_80,&local_a8);
  local_ac = param_1[0x13] + 1;
  param_1[0x13] = local_ac;
  local_a4 = *(uint *)(iVar4 + 0x24);
  local_a8 = (ushort *)*puVar10;
  bVar3 = FUN_00011d90((int *)&local_80,(int *)&local_a8);
  cVar11 = param_6;
  if (((CONCAT31(extraout_var_00,bVar3) == 0) && (*(char *)((int)param_1 + 0x49) != '\0')) &&
     (param_6 != '\0')) {
    uVar7 = 0;
    while( true ) {
      local_a4 = *(uint *)(iVar4 + 0x24);
      local_a8 = (ushort *)*puVar10;
      bVar3 = FUN_00011d90((int *)&local_80,(int *)&local_a8);
      if (CONCAT31(extraout_var_01,bVar3) != 0) break;
      puVar5 = (undefined4 *)FUN_00011e24((int *)&local_80);
      if ((DAT_0001b214 & 1) == 0) {
        DAT_0001b214 = DAT_0001b214 | 1;
      }
      bVar3 = thunk_FUN_00011fec(&DAT_0001b210,param_3,(ushort *)*puVar5);
      if (CONCAT31(extraout_var_02,bVar3) != 0) break;
      iVar6 = FUN_00011e24((int *)&local_80);
      if (*(int *)(iVar6 + 8) < (int)local_ac) {
        iVar6 = FUN_00011e24((int *)&local_80);
        local_ac = *(uint *)(iVar6 + 8);
        iVar6 = FUN_00011e24((int *)&local_80);
        uVar7 = *(uint *)(iVar6 + 4);
      }
      FUN_00012110((int *)&local_80);
    }
    param_4 = local_94;
    param_1 = local_98;
    cVar11 = param_6;
    if (uVar7 != 0) {
      FUN_00013d60(local_98,uVar9);
      param_5 = uVar7;
      FUN_00015218((int)param_1,&param_5);
      uVar9 = param_5;
    }
    FUN_00015f24(param_1,param_2,param_3,(ushort *)0x0,'\0');
    local_7c = *(uint *)(iVar4 + 0x24);
    local_80 = (ushort *)*puVar10;
  }
  if ((*(char *)((int)param_1 + 0x49) == '\0') || (bVar3 = true, cVar11 != '\0')) {
    bVar3 = false;
  }
  if (local_90 == 0) goto LAB_000168b4;
  if (bVar3) {
LAB_00016884:
    iVar6 = FUN_00015218((int)param_1,&local_res8);
    param_3 = local_res8;
    if (iVar6 < 0) {
      return iVar6;
    }
  }
  else {
    local_8c = *(undefined4 *)(iVar4 + 0x24);
    local_90 = *puVar10;
    bVar2 = FUN_00011d90((int *)&local_80,(int *)&local_90);
    if (CONCAT31(extraout_var_03,bVar2) != 0) goto LAB_00016884;
  }
  iVar6 = FUN_00015218((int)param_1,&local_resc);
  param_4 = local_resc;
  if (iVar6 < 0) {
    return iVar6;
  }
LAB_000168b4:
  local_8c = *(undefined4 *)(iVar4 + 0x24);
  local_90 = *puVar10;
  bVar2 = FUN_00011d90((int *)&local_80,(int *)&local_90);
  if ((CONCAT31(extraout_var_04,bVar2) != 0) || (bVar3)) {
    local_a4 = 0;
    if (uVar9 != 0) {
      local_a4 = uVar9;
    }
    local_a0 = local_ac;
    local_9c = 0;
    local_a8 = param_3;
    puVar10 = FUN_00014f20(puVar10,&local_90,&local_a8);
    local_80 = (ushort *)*puVar10;
    local_7c = puVar10[1];
    bVar1 = true;
  }
  iVar4 = FUN_00011e24((int *)&local_80);
  *(int *)(iVar4 + 0xc) = param_4;
  if (!bVar1) {
    return 1;
  }
  return 2;
}



/* 00016984 Unwind@00016984 */

/* Boundary evidence: original MIPS .pdata 00016984..000169b3. Semantic name remains unreviewed. */

void Unwind_00016984(void)

{
  int in_v0;
  
  FUN_00015380((int *)(in_v0 + -0x78));
  return;
}



/* 000169b4 Unwind@000169b4 */

/* Boundary evidence: original MIPS .pdata 000169b4..000169e3. Semantic name remains unreviewed. */

void Unwind_000169b4(void)

{
  int in_v0;
  
  FUN_00015418(in_v0 + -0x58);
  return;
}



/* 000169e4 FUN_000169e4 */

/* Boundary evidence: original MIPS .pdata 000169e4..00016a33. Semantic name remains unreviewed. */

void FUN_000169e4(int *param_1)

{
  int aiStack_10 [2];
  
  FUN_000162c8(param_1,aiStack_10,*param_1,*(int **)param_1[6]);
  __3_YAXPAX_Z(param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}



/* 00016a34 FUN_00016a34 */

/* Boundary evidence: original MIPS .pdata 00016a34..00016cb3. Semantic name remains unreviewed. */

int FUN_00016a34(uint *param_1,LPCSTR param_2,uint param_3)

{
  int iVar1;
  LPWSTR lpWideCharStr;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  UINT CodePage;
  uint local_40;
  int local_3c;
  ushort *local_38;
  ushort *local_34;
  LPWSTR local_30 [2];
  
  if ((char)param_1[0x12] == '\0') {
    CodePage = 0;
  }
  else {
    CodePage = 0xfde9;
    if ((2 < param_3) && (iVar1 = memcmp(param_2,&DAT_000197b4,3), iVar1 == 0)) {
      param_2 = param_2 + 3;
      param_3 = param_3 - 3;
    }
  }
  if (param_3 != 0) {
    iVar1 = MultiByteToWideChar(CodePage,0,param_2,param_3,(LPWSTR)0x0,0);
    if (iVar1 < 1) {
      iVar1 = -1;
    }
    if (iVar1 == -1) {
      return -1;
    }
    uVar5 = iVar1 + 1;
    iVar2 = uVar5 * 2;
    if (0x7fffffff < uVar5) {
      iVar2 = -1;
    }
    lpWideCharStr = (LPWSTR)___U_YAPAXIABUnothrow_t_std___Z(iVar2,&LAB_00018040);
    if (lpWideCharStr == (LPWSTR)0x0) {
      return -2;
    }
    memset(lpWideCharStr,0,(iVar1 + 1) * 2);
    iVar1 = MultiByteToWideChar(CodePage,0,param_2,param_3,lpWideCharStr,iVar1);
    if (iVar1 < 1) {
      ___V_YAXPAX_Z(lpWideCharStr);
      return -1;
    }
    local_34 = (ushort *)&DAT_000197b0;
    uVar4 = *param_1;
    local_38 = (ushort *)0x0;
    local_3c = 0;
    local_40 = 0;
    uVar3 = (uint)(uVar4 != 0);
    local_30[0] = lpWideCharStr;
    iVar1 = FUN_0001539c((int)param_1,(int *)local_30,uVar3);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_00012f90((int)param_1,(int *)local_30,(int *)&local_34,&local_38,&local_3c,
                         (int *)&local_40);
    while (iVar1 != 0) {
      iVar1 = FUN_00016504(param_1,local_34,local_38,local_3c,local_40,'\0',uVar4 != 0);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = FUN_00012f90((int)param_1,(int *)local_30,(int *)&local_34,&local_38,&local_3c,
                           (int *)&local_40);
    }
    if (uVar3 == 0) {
      *param_1 = (uint)lpWideCharStr;
      param_1[1] = uVar5;
    }
    else {
      ___V_YAXPAX_Z(lpWideCharStr);
    }
  }
  return 0;
}



/* 00016cb4 FUN_00016cb4 */

/* Boundary evidence: original MIPS .pdata 00016cb4..00016cfb. Semantic name remains unreviewed. */

void FUN_00016cb4(int *param_1)

{
  FUN_000169e4(param_1);
  __3_YAXPAX_Z(*param_1);
  return;
}



/* 00016cfc Unwind@00016cfc */

/* Boundary evidence: original MIPS .pdata 00016cfc..00016d2b. Semantic name remains unreviewed. */

void Unwind_00016cfc(void)

{
  undefined4 *in_v0;
  
  FUN_000138a0((undefined4 *)*in_v0);
  return;
}



/* 00016d2c FUN_00016d2c */

/* Boundary evidence: original MIPS .pdata 00016d2c..00016e2b. Semantic name remains unreviewed. */

int FUN_00016d2c(uint *param_1,FILE *param_2)

{
  int iVar1;
  size_t _Count;
  LPCSTR _DstBuf;
  size_t sVar2;
  
  iVar1 = fseek(param_2,0,2);
  if ((iVar1 == 0) && (_Count = ftell(param_2), -1 < (int)_Count)) {
    if (_Count == 0) {
      iVar1 = 0;
    }
    else {
      _DstBuf = (LPCSTR)___U_YAPAXIABUnothrow_t_std___Z(_Count + 1,&LAB_00018040);
      if (_DstBuf == (LPCSTR)0x0) {
        iVar1 = -2;
      }
      else {
        _DstBuf[_Count] = '\0';
        fseek(param_2,0,0);
        sVar2 = fread(_DstBuf,1,_Count,param_2);
        if (sVar2 == _Count) {
          iVar1 = FUN_00016a34(param_1,_DstBuf,sVar2);
        }
        else {
          iVar1 = -3;
        }
        ___V_YAXPAX_Z(_DstBuf);
      }
    }
  }
  else {
    iVar1 = -3;
  }
  return iVar1;
}



/* 00016e2c FUN_00016e2c */

/* Boundary evidence: original MIPS .pdata 00016e2c..00016e8b. Semantic name remains unreviewed. */

int FUN_00016e2c(uint *param_1,wchar_t *param_2)

{
  int iVar1;
  FILE *local_10 [2];
  
  local_10[0] = (FILE *)0x0;
  _wfopen_s(local_10,param_2,L"rb");
  if (local_10[0] == (FILE *)0x0) {
    iVar1 = -3;
  }
  else {
    iVar1 = FUN_00016d2c(param_1,local_10[0]);
    fclose(local_10[0]);
  }
  return iVar1;
}



/* 00016e8c FUN_00016e8c */

/* Boundary evidence: original MIPS .pdata 00016e8c..00016ea7. Semantic name remains unreviewed. */

void FUN_00016e8c(int *param_1)

{
  FUN_00016cb4(param_1);
  return;
}



/* 00016ea8 FUN_00016ea8 */

/* Boundary evidence: original MIPS .pdata 00016ea8..00016f43. Semantic name remains unreviewed. */

undefined4 *
FUN_00016ea8(undefined4 *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  FUN_00014388(param_1 + 3);
  FUN_000141bc(param_1 + 0xb);
  *(undefined1 *)(param_1 + 0x12) = param_2;
  *(undefined1 *)((int)param_1 + 0x49) = param_3;
  *(undefined1 *)((int)param_1 + 0x4a) = param_4;
  *(undefined1 *)((int)param_1 + 0x4b) = 1;
  param_1[0x13] = 0;
  return param_1;
}



/* 00016f44 Unwind@00016f44 */

/* Boundary evidence: original MIPS .pdata 00016f44..00016f77. Semantic name remains unreviewed. */

void Unwind_00016f44(void)

{
  int *in_v0;
  
  FUN_00016e8c((int *)(*in_v0 + 0xc));
  return;
}



/* 00016f78 FUN_00016f78 */

/* Boundary evidence: original MIPS .pdata 00016f78..00016feb. Semantic name remains unreviewed. */

void FUN_00016f78(undefined4 *param_1)

{
  FUN_000163e0(param_1);
  FUN_0001206c((int)(param_1 + 0xb));
  __3_YAXPAX_Z(param_1[0x10]);
  param_1[0x10] = 0;
  __3_YAXPAX_Z(param_1[0xb]);
  FUN_00016cb4(param_1 + 3);
  return;
}



/* 00016fec Unwind@00016fec */

/* Boundary evidence: original MIPS .pdata 00016fec..0001701f. Semantic name remains unreviewed. */

void Unwind_00016fec(void)

{
  int *in_v0;
  
  FUN_00016e8c((int *)(*in_v0 + 0xc));
  return;
}



/* 00017020 Unwind@00017020 */

/* Boundary evidence: original MIPS .pdata 00017020..00017053. Semantic name remains unreviewed. */

void Unwind_00017020(void)

{
  int *in_v0;
  
  FUN_00013e40((undefined4 *)(*in_v0 + 0x2c));
  return;
}



/* 00017054 FUN_00017054 */

/* Boundary evidence: original MIPS .pdata 00017054..00017407. Semantic name remains unreviewed. */

undefined4 FUN_00017054(void)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 *puVar3;
  wchar_t *_Str;
  wchar_t *_Str_00;
  size_t sVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int local_a8;
  undefined4 local_a4;
  int local_a0;
  undefined4 *local_9c;
  int local_98 [5];
  undefined4 *local_84;
  uint local_80;
  uint auStack_78 [20];
  
  DAT_0001b1e0 = 0;
  uVar7 = 1;
  FUN_00016ea8(auStack_78,1,0,0);
  iVar2 = FUN_00016e2c(auStack_78,L"\\Storage Card\\System\\dboot.ini");
  if (iVar2 < 0) {
    FUN_00016f78(auStack_78);
    uVar7 = 0;
  }
  else {
    FUN_000141bc(local_98);
    FUN_000152d8((int)auStack_78,local_98);
    if (local_80 == 0) {
      FUN_0001206c((int)local_98);
      __3_YAXPAX_Z(local_84);
      local_84 = (undefined4 *)0x0;
      __3_YAXPAX_Z(local_98[0]);
      uVar7 = 0;
    }
    else {
      iVar2 = -1;
      if (local_80 < 0x15555556) {
        iVar6 = local_80 * 0xc;
      }
      else {
        iVar6 = -1;
      }
      DAT_0001b1e4 = ___U_YAPAXI_Z(iVar6);
      local_a4 = *local_84;
      local_a8 = local_98[0];
      while( true ) {
        local_9c = local_84;
        local_a0 = local_98[0];
        bVar1 = FUN_00011d90(&local_a8,&local_a0);
        if (CONCAT31(extraout_var,bVar1) != 0) break;
        puVar3 = (undefined4 *)FUN_00011d14(&local_a8);
        _Str = (wchar_t *)
               FUN_00013eac((int)auStack_78,(ushort *)*puVar3,(ushort *)L"happ",0,(undefined1 *)0x0)
        ;
        puVar3 = (undefined4 *)FUN_00011d14(&local_a8);
        _Str_00 = (wchar_t *)
                  FUN_00013eac((int)auStack_78,(ushort *)*puVar3,(ushort *)L"vapp",0,
                               (undefined1 *)0x0);
        if ((_Str != (wchar_t *)0x0) || (_Str_00 != (wchar_t *)0x0)) {
          puVar3 = (undefined4 *)FUN_00011d14(&local_a8);
          sVar4 = wcslen((wchar_t *)*puVar3);
          iVar6 = (sVar4 + 1) * 2;
          if (0x7fffffff < sVar4 + 1) {
            iVar6 = iVar2;
          }
          uVar5 = ___U_YAPAXI_Z(iVar6);
          *(undefined4 *)(DAT_0001b1e0 * 0xc + DAT_0001b1e4) = uVar5;
          puVar3 = (undefined4 *)FUN_00011d14(&local_a8);
          sVar4 = wcslen((wchar_t *)*puVar3);
          puVar3 = (undefined4 *)FUN_00011d14(&local_a8);
          wcscpy_s(*(wchar_t **)(DAT_0001b1e0 * 0xc + DAT_0001b1e4),sVar4 + 1,(wchar_t *)*puVar3);
          if (_Str != (wchar_t *)0x0) {
            sVar4 = wcslen(_Str);
            iVar6 = (sVar4 + 1) * 2;
            if (0x7fffffff < sVar4 + 1) {
              iVar6 = iVar2;
            }
            uVar5 = ___U_YAPAXI_Z(iVar6);
            *(undefined4 *)(DAT_0001b1e0 * 0xc + DAT_0001b1e4 + 4) = uVar5;
            sVar4 = wcslen(_Str);
            wcscpy_s(*(wchar_t **)(DAT_0001b1e0 * 0xc + DAT_0001b1e4 + 4),sVar4 + 1,_Str);
          }
          if (_Str_00 != (wchar_t *)0x0) {
            sVar4 = wcslen(_Str_00);
            iVar6 = (sVar4 + 1) * 2;
            if (0x7fffffff < sVar4 + 1) {
              iVar6 = iVar2;
            }
            uVar5 = ___U_YAPAXI_Z(iVar6);
            *(undefined4 *)(DAT_0001b1e0 * 0xc + DAT_0001b1e4 + 8) = uVar5;
            sVar4 = wcslen(_Str_00);
            wcscpy_s(*(wchar_t **)(DAT_0001b1e0 * 0xc + DAT_0001b1e4 + 8),sVar4 + 1,_Str_00);
          }
          DAT_0001b1e0 = DAT_0001b1e0 + 1;
        }
        FUN_00011c90(&local_a8);
      }
      FUN_0001206c((int)local_98);
      __3_YAXPAX_Z(local_84);
      local_84 = (undefined4 *)0x0;
      __3_YAXPAX_Z(local_98[0]);
    }
    FUN_00016f78(auStack_78);
  }
  return uVar7;
}



/* 00017408 Unwind@00017408 */

/* Boundary evidence: original MIPS .pdata 00017408..00017437. Semantic name remains unreviewed. */

void Unwind_00017408(void)

{
  int in_v0;
  
  FUN_00016f78((undefined4 *)(in_v0 + -0x78));
  return;
}



/* 00017438 Unwind@00017438 */

/* Boundary evidence: original MIPS .pdata 00017438..00017467. Semantic name remains unreviewed. */

void Unwind_00017438(void)

{
  int in_v0;
  
  FUN_00013e40((undefined4 *)(in_v0 + -0x98));
  return;
}



/* 00017468 FUN_00017468 */

/* Boundary evidence: original MIPS .pdata 00017468..000175b7. Semantic name remains unreviewed. */

undefined4 FUN_00017468(void)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  
  if (DAT_0001b1f4 == 0) {
    iVar1 = FUN_00017054();
    if (iVar1 != 0) {
      if (DAT_0001b1f8 == (HMODULE)0x0) {
        DAT_0001b1f8 = LoadLibraryW(L"coredll.dll");
        if (DAT_0001b1f8 != (HMODULE)0x0) goto LAB_000174e4;
        pwVar3 = L"[Mouse hook] LoadLibrary core.dll failed\n";
      }
      else {
LAB_000174e4:
        DAT_0001b20c = (code *)GetProcAddressW(DAT_0001b1f8,L"SetWindowsHookExW");
        if (DAT_0001b20c == (code *)0x0) {
          pwVar3 = L"[Mouse hook] SetWindowsHookEx not found\n";
        }
        else {
          DAT_0001b204 = GetProcAddressW(DAT_0001b1f8,L"CallNextHookEx");
          if (DAT_0001b204 == 0) {
            pwVar3 = L"[Mouse hook] CallNextHookEx not found\n";
          }
          else {
            DAT_0001b208 = GetProcAddressW(DAT_0001b1f8,L"UnhookWindowsHookEx");
            if (DAT_0001b208 == 0) {
              pwVar3 = L"[Mouse hook] UnhookWindowsHookEx not found\n";
            }
            else {
              DAT_0001b1f4 = (*DAT_0001b20c)(0x15,FUN_00011b54,0,0);
              if (DAT_0001b1f4 != 0) goto LAB_00017598;
              pwVar3 = L"[Mouse hook] SetWindowsHookEx WH_MOUSE_LL failed\n";
            }
          }
        }
      }
      NKDbgPrintfW(pwVar3);
    }
    uVar2 = 0;
  }
  else {
LAB_00017598:
    uVar2 = 1;
  }
  return uVar2;
}



/* 000175b8 FUN_000175b8 */

/* Boundary evidence: original MIPS .pdata 000175b8..000177ef. Semantic name remains unreviewed. */

LRESULT FUN_000175b8(HWND param_1,UINT param_2,WPARAM param_3,uint param_4)

{
  LRESULT LVar1;
  int iVar2;
  HDC hdc;
  uint uVar3;
  uint uVar4;
  tagRECT tStack_68;
  tagPAINTSTRUCT tStack_58;
  uint local_18;
  
  local_18 = DAT_0001b1d4;
  if (param_2 != 2) {
    if (param_2 == 0xf) {
      if (DAT_0001b1fc == 0) {
        hdc = BeginPaint(param_1,&tStack_58);
        SetTextColor(hdc,0xf5f5f5);
        SetBkMode(hdc,1);
        SetRect(&tStack_68,0x14,0x1c2,200,0x1d6);
        DrawTextW(hdc,L"DBOOT 2.0 - 2017",0x10,&tStack_68,0);
        EndPaint(param_1,&tStack_58);
      }
      goto LAB_00017744;
    }
    if (param_2 != 0x113) {
      if (param_2 == 0x200) {
        if (((DAT_0001b1fc == 0) && (DAT_0001b1e8 != 0)) &&
           (uVar4 = DAT_0001b1ec - (param_4 & 0xffff), uVar3 = (int)uVar4 >> 0x1f,
           300 < (int)((uVar4 ^ uVar3) - uVar3))) {
          DAT_0001b1e8 = 0;
          FUN_0001119c(L"\\Storage Card\\System\\dmenu.exe",0);
          NKDbgPrintfW(L"Start dmenu\n");
        }
      }
      else if (param_2 == 0x201) {
        DAT_0001b1ec = param_4 & 0xffff;
        DAT_0001b1e8 = 1;
      }
      else {
        if (param_2 != 0x202) {
          LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
          FUN_00017eb8(local_18);
          return LVar1;
        }
        DAT_0001b1e8 = 0;
      }
      goto LAB_00017744;
    }
    if (param_3 != 0x65) goto LAB_00017744;
    DAT_0001b1fc = 1;
    SetWindowPos(param_1,(HWND)0x1,0,0,0,0,0);
    ShowWindow(param_1,0);
    KillTimer(param_1,0x65);
    iVar2 = FUN_00017468();
    if (iVar2 != 0) goto LAB_00017744;
  }
  FUN_00011000();
  PostQuitMessage(0);
LAB_00017744:
  FUN_00017eb8(local_18);
  return 0;
}



/* 000177f0 FUN_000177f0 */

/* Boundary evidence: original MIPS .pdata 000177f0..0001784f. Semantic name remains unreviewed. */

void FUN_000177f0(HINSTANCE param_1,LPCWSTR param_2)

{
  WNDCLASSW local_38;
  
  memset(&local_38,0,0x28);
  local_38.style = 3;
  local_38.lpfnWndProc = FUN_000175b8;
  local_38.hInstance = param_1;
  local_38.lpszClassName = param_2;
  RegisterClassW(&local_38);
  return;
}



/* 00017850 FUN_00017850 */

/* Boundary evidence: original MIPS .pdata 00017850..00017997. Semantic name remains unreviewed. */

undefined4 FUN_00017850(HINSTANCE param_1,int param_2)

{
  int iVar1;
  HWND hWnd;
  tagRECT tStack_20;
  
  DAT_0001b200 = param_1;
  iVar1 = FUN_000177f0(param_1,L"dboot");
  if ((iVar1 != 0) &&
     (hWnd = CreateWindowExW(0,L"dboot",L"dboot",0x10000000,-0x80000000,-0x80000000,-0x80000000,
                             -0x80000000,(HWND)0x0,(HMENU)0x0,param_1,(LPVOID)0x0),
     hWnd != (HWND)0x0)) {
    GetWindowRect(hWnd,&tStack_20);
    SetWindowPos(hWnd,(HWND)0xffffffff,0,0,800,0x1e0,0);
    SetForegroundWindow((HWND)((uint)hWnd | 1));
    ShowWindow(hWnd,param_2);
    UpdateWindow(hWnd);
    DAT_0001b1fc = 0;
    DAT_0001b1e4 = 0;
    DAT_0001b1f8 = 0;
    DAT_0001b1e8 = 0;
    DAT_0001b1f4 = 0;
    DAT_0001b20c = 0;
    DAT_0001b204 = 0;
    DAT_0001b208 = 0;
    SetTimer(hWnd,0x65,5000,(TIMERPROC)0x0);
    return 1;
  }
  return 0;
}



/* 00017998 FUN_00017998 */

/* Boundary evidence: original MIPS .pdata 00017998..00017bc3. Semantic name remains unreviewed. */

undefined4 FUN_00017998(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  LSTATUS LVar1;
  size_t sVar2;
  HANDLE hDevice;
  int iVar3;
  BOOL BVar4;
  undefined4 local_48;
  HKEY local_44;
  DWORD DStack_40;
  DWORD DStack_3c;
  MSG MStack_38;
  
  local_44 = (HKEY)0x0;
  LVar1 = RegCreateKeyExW((HKEY)0x80000001,L"ControlPanel\\Comm",0,(LPWSTR)0x0,0,0,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_44,&DStack_40);
  if (LVar1 == 0) {
    sVar2 = wcslen(L"`Default USB`");
    RegSetValueExW(local_44,L"Cnct",0,1,(BYTE *)L"`Default USB`",(sVar2 + 1) * 2);
    local_48 = 1;
    RegSetValueExW(local_44,L"AutoCnct",0,4,(BYTE *)&local_48,4);
    RegCloseKey(local_44);
  }
  hDevice = CreateFileW(L"MGR1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hDevice != (HANDLE)0xffffffff) {
    local_48 = CONCAT22((short)((uint)local_48 >> 0x10),0x100);
    DeviceIoControl(hDevice,2,&local_48,2,(LPVOID)0x0,0,&DStack_3c,(LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  iVar3 = FUN_0001114c(L"\\Storage Card3\\StartWinCE");
  if ((iVar3 == 0) &&
     (iVar3 = FUN_0001119c(L"\\Storage Card\\System\\UpgradeManager.exe",param_3), iVar3 != 0)) {
    iVar3 = FUN_00017850(param_1,param_4);
    if (iVar3 != 0) {
      while (BVar4 = GetMessageW(&MStack_38,(HWND)0x0,0,0), BVar4 != 0) {
        TranslateMessage(&MStack_38);
        DispatchMessageW(&MStack_38);
      }
      return MStack_38.wParam;
    }
  }
  else {
    FUN_000113d4();
  }
  return 0;
}



/* 00017db4 FUN_00017db4 */

/* Boundary evidence: original MIPS .pdata 00017db4..00017e27. Semantic name remains unreviewed. */

void FUN_00017db4(void)

{
  uint uVar1;
  
  if ((DAT_0001b1d4 == 0) || (DAT_0001b1d4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0001b1d4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0001b1d4 == 0) {
      DAT_0001b1d4 = 0xb064;
    }
  }
  DAT_0001b1d8 = ~DAT_0001b1d4;
  return;
}



/* 00017e28 FUN_00017e28 */

/* Boundary evidence: original MIPS .pdata 00017e28..00017e7b. Semantic name remains unreviewed. */

void FUN_00017e28(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00017eb8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00017e7c FUN_00017e7c */

/* Boundary evidence: original MIPS .pdata 00017e7c..00017ea7. Semantic name remains unreviewed. */

undefined4 FUN_00017e7c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00017e28(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00017eb8 FUN_00017eb8 */

/* Boundary evidence: original MIPS .pdata 00017eb8..00017eff. Semantic name remains unreviewed. */

void FUN_00017eb8(uint param_1)

{
  if ((param_1 == DAT_0001b1d4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00017fc0 FUN_00017fc0 */

/* Boundary evidence: original MIPS .pdata 00017fc0..0001802f. Semantic name remains unreviewed. */

void FUN_00017fc0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00017e28(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 000180e0 FUN_000180e0 */

/* Boundary evidence: original MIPS .pdata 000180e0..00018173. Semantic name remains unreviewed. */

void FUN_000180e0(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  UINT UVar1;
  
  FUN_00018420();
  UVar1 = FUN_00017998(param_1,param_2,param_3,param_4);
  FUN_00018360(UVar1);
  FUN_00018380(UVar1);
  return;
}



/* 00018174 FUN_00018174 */

/* Boundary evidence: original MIPS .pdata 00018174..000181b3. Semantic name remains unreviewed. */

void FUN_00018174(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 000181b4 entry */

/* Boundary evidence: original MIPS .pdata 000181b4..0001820f. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  FUN_00017db4();
  FUN_000180e0(param_1,param_2,param_3,param_4);
  return;
}



/* 00018240 FUN_00018240 */

/* Boundary evidence: original MIPS .pdata 00018240..0001835f. Semantic name remains unreviewed. */

void FUN_00018240(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0001b228 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_0001b230;
    if (DAT_0001b230 != (undefined4 *)0x0) {
      while (DAT_0001b22c = DAT_0001b22c + -1, _Memory <= DAT_0001b22c) {
        if ((code *)*DAT_0001b22c != (code *)0x0) {
          (*(code *)*DAT_0001b22c)();
          _Memory = DAT_0001b230;
        }
      }
      free(_Memory);
      DAT_0001b22c = (undefined4 *)0x0;
      DAT_0001b230 = (undefined4 *)0x0;
    }
    FUN_000183cc((undefined4 *)&DAT_00019010,(undefined4 *)&DAT_00019014);
  }
  FUN_000183cc((undefined4 *)&DAT_00019018,(undefined4 *)&DAT_0001901c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_0001b234,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00018360 FUN_00018360 */

/* Boundary evidence: original MIPS .pdata 00018360..0001837f. Semantic name remains unreviewed. */

void FUN_00018360(UINT param_1)

{
  FUN_00018240(param_1,0,0);
  return;
}



/* 00018380 FUN_00018380 */

/* Boundary evidence: original MIPS .pdata 00018380..000183cb. Semantic name remains unreviewed. */

void FUN_00018380(UINT param_1)

{
  DAT_0001b228 = 0;
  FUN_000183cc((undefined4 *)&DAT_00019018,(undefined4 *)&DAT_0001901c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000183cc FUN_000183cc */

/* Boundary evidence: original MIPS .pdata 000183cc..0001841f. Semantic name remains unreviewed. */

void FUN_000183cc(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00018420 FUN_00018420 */

/* Boundary evidence: original MIPS .pdata 00018420..0001845b. Semantic name remains unreviewed. */

void FUN_00018420(void)

{
  FUN_000183cc((undefined4 *)&DAT_00019008,(undefined4 *)&DAT_0001900c);
  FUN_000183cc((undefined4 *)&DAT_00019000,(undefined4 *)&DAT_00019004);
  return;
}



/* 0001847c FUN_0001847c */

/* Boundary evidence: original MIPS .pdata 0001847c..000184db. Semantic name remains unreviewed. */

void FUN_0001847c(void)

{
  undefined1 auStack_50 [32];
  undefined **appuStack_30 [10];
  
  FUN_00014408((int)auStack_50,"string too long");
  FUN_00014244(appuStack_30,auStack_50);
                    /* WARNING: Subroutine does not return */
  appuStack_30[0] = std::length_error::vftable;
  __CxxThrowException(appuStack_30,(ThrowInfo *)&DAT_0001a090);
}



/* 000184dc Unwind@000184dc */

/* Boundary evidence: original MIPS .pdata 000184dc..0001850b. Semantic name remains unreviewed. */

void Unwind_000184dc(void)

{
  int in_v0;
  
  FUN_00012cb4(in_v0 + -0x50);
  return;
}



/* 0001850c FUN_0001850c */

/* Boundary evidence: original MIPS .pdata 0001850c..0001856b. Semantic name remains unreviewed. */

void FUN_0001850c(void)

{
  undefined1 auStack_50 [32];
  undefined **appuStack_30 [10];
  
  FUN_00014408((int)auStack_50,"invalid string position");
  FUN_00014244(appuStack_30,auStack_50);
                    /* WARNING: Subroutine does not return */
  appuStack_30[0] = std::out_of_range::vftable;
  __CxxThrowException(appuStack_30,(ThrowInfo *)&DAT_0001a038);
}



/* 0001856c Unwind@0001856c */

/* Boundary evidence: original MIPS .pdata 0001856c..0001859b. Semantic name remains unreviewed. */

void Unwind_0001856c(void)

{
  int in_v0;
  
  FUN_00012cb4(in_v0 + -0x50);
  return;
}



/* 0001859c FUN_0001859c */

/* Boundary evidence: original MIPS .pdata 0001859c..000185c7. Semantic name remains unreviewed. */

void FUN_0001859c(void)

{
  FUN_000185fc();
  return;
}



/* 000185c8 FUN_000185c8 */

/* Boundary evidence: original MIPS .pdata 000185c8..000185fb. Semantic name remains unreviewed. */

void FUN_000185c8(void)

{
  RaiseException(0xc000000d,0,0,(ULONG_PTR *)0x0);
  return;
}



/* 000185fc FUN_000185fc */

/* Boundary evidence: original MIPS .pdata 000185fc..0001861b. Semantic name remains unreviewed. */

void FUN_000185fc(void)

{
  FUN_000185c8();
  return;
}


