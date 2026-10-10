/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c05e1178 FUN_c05e1178 */

/* Boundary evidence: original MIPS .pdata c05e1178..c05e1233. Semantic name remains unreviewed. */

undefined4 FUN_c05e1178(undefined4 param_1,undefined4 param_2)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"WaitForAPIReady");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c05e1234 FUN_c05e1234 */

/* Boundary evidence: original MIPS .pdata c05e1234..c05e1323. Semantic name remains unreviewed. */

undefined4
FUN_c05e1234(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"CeCallUserProc");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c05e1324 FUN_c05e1324 */

/* Boundary evidence: original MIPS .pdata c05e1324..c05e1487. Semantic name remains unreviewed. */

undefined4 FUN_c05e1324(undefined4 param_1,void *param_2,uint *param_3)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 local_5d8 [2];
  DWORD local_5d0;
  undefined4 local_5cc;
  undefined1 auStack_5c8 [1456];
  uint local_18;
  uint local_14;
  
  local_14 = DAT_c05e5230;
  local_5d8[0] = 0;
  local_5d0 = 0;
  local_18 = (uint)(param_3 != (uint *)0x0);
  local_5cc = param_1;
  memcpy(auStack_5c8,param_2,0x5b0);
  iVar1 = FUN_c05e1178(0x51,60000);
  if (iVar1 == 0) {
    iVar1 = FUN_c05e1234(L"netui.dll",L"GetUsernamePasswordExExt",&local_5d0,0x5bc,&local_5d0,0x5bc,
                         local_5d8);
    if (iVar1 == 0) {
      dwErrCode = GetLastError();
      if (dwErrCode == 0) {
        dwErrCode = 0x57;
      }
    }
    else {
      dwErrCode = local_5d0;
      if (local_5d0 == 0) {
        memcpy(param_2,auStack_5c8,0x5b0);
        if (param_3 != (uint *)0x0) {
          *param_3 = local_18;
        }
        SetLastError(0);
        FUN_c05e3c00(local_14);
        return 1;
      }
    }
  }
  else {
    dwErrCode = GetLastError();
    if (dwErrCode == 0) {
      dwErrCode = 0x1f;
    }
  }
  SetLastError(dwErrCode);
  FUN_c05e3c00(local_14);
  return 0;
}



/* c05e1488 FUN_c05e1488 */

/* Boundary evidence: original MIPS .pdata c05e1488..c05e15a3. Semantic name remains unreviewed. */

undefined4 FUN_c05e1488(undefined4 param_1,void *param_2,uint *param_3)

{
  int iVar1;
  undefined4 local_230 [2];
  DWORD local_228;
  undefined4 local_224;
  undefined1 auStack_220 [516];
  uint local_1c;
  uint local_18;
  
  local_18 = DAT_c05e5230;
  local_230[0] = 0;
  local_228 = 0;
  local_1c = (uint)(param_3 != (uint *)0x0);
  local_224 = param_1;
  memcpy(auStack_220,param_2,0x202);
  iVar1 = FUN_c05e1178(0x51,60000);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_c05e1234(L"netui.dll",L"GetNewPasswordExExt",&local_228,0x210,&local_228,0x210,
                           local_230), iVar1 != 0)) {
    if (local_228 == 0) {
      memcpy(param_2,auStack_220,0x202);
      if (param_3 != (uint *)0x0) {
        *param_3 = local_1c;
      }
      FUN_c05e3c00(local_18);
      return 1;
    }
    SetLastError(local_228);
  }
  FUN_c05e3c00(local_18);
  return 0;
}



/* c05e15a4 FUN_c05e15a4 */

/* Boundary evidence: original MIPS .pdata c05e15a4..c05e15db. Semantic name remains unreviewed. */

void FUN_c05e15a4(LPCSTR param_1,int param_2,LPWSTR param_3,int param_4)

{
  MultiByteToWideChar(1,0,param_1,param_2,param_3,param_4);
  return;
}



/* c05e15dc FUN_c05e15dc */

/* Boundary evidence: original MIPS .pdata c05e15dc..c05e1667. Semantic name remains unreviewed. */

DWORD FUN_c05e15dc(int param_1,LPCWSTR param_2)

{
  int iVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  iVar1 = WideCharToMultiByte(1,0,param_2,-1,(LPSTR)(param_1 + 5),0x111,(LPCSTR)0x0,(LPBOOL)0x0);
  if (0 < iVar1) {
    iVar1 = iVar1 + -1;
  }
  *(int *)(param_1 + 0x118) = iVar1;
  if (iVar1 == 0) {
    DVar2 = GetLastError();
  }
  return DVar2;
}



/* c05e1668 FUN_c05e1668 */

/* Boundary evidence: original MIPS .pdata c05e1668..c05e1713. Semantic name remains unreviewed. */

DWORD FUN_c05e1668(int param_1,LPCWSTR param_2)

{
  int iVar1;
  byte *lpMultiByteStr;
  DWORD DVar2;
  
  lpMultiByteStr = (byte *)(param_1 + 0x11c);
  *(undefined4 *)(param_1 + 0x220) = 0;
  *lpMultiByteStr = 0;
  DVar2 = 0;
  if (param_2 != (LPCWSTR)0x0) {
    iVar1 = WideCharToMultiByte(1,0,param_2,-1,(LPSTR)lpMultiByteStr,0x101,(LPCSTR)0x0,(LPBOOL)0x0);
    if (0 < iVar1) {
      iVar1 = iVar1 + -1;
    }
    *(int *)(param_1 + 0x220) = iVar1;
    if (lpMultiByteStr == (byte *)0x0) {
      DVar2 = GetLastError();
    }
  }
  FUN_c05e2090((uint)*(byte *)(param_1 + 4),lpMultiByteStr);
  return DVar2;
}



/* c05e1714 FUN_c05e1714 */

/* Boundary evidence: original MIPS .pdata c05e1714..c05e17cf. Semantic name remains unreviewed. */

DWORD FUN_c05e1714(undefined4 param_1,undefined4 *param_2,int param_3)

{
  undefined4 *_Dst;
  DWORD DVar1;
  int iVar2;
  
  _Dst = LocalAlloc(0x40,0x638);
  if (_Dst == (undefined4 *)0x0) {
    DVar1 = 0xe;
  }
  else {
    memset(_Dst,0,0x638);
    iVar2 = rand();
    *_Dst = param_1;
    *(char *)(_Dst + 1) = (char)(iVar2 % 0xfa) + '\x01';
    DVar1 = FUN_c05e15dc((int)_Dst,*(LPCWSTR *)(param_3 + 0xc));
    if ((DVar1 == 0) && (DVar1 = FUN_c05e1668((int)_Dst,*(LPCWSTR *)(param_3 + 0x10)), DVar1 == 0))
    {
      *param_2 = _Dst;
    }
  }
  return DVar1;
}



/* c05e17d0 FUN_c05e17d0 */

/* Boundary evidence: original MIPS .pdata c05e17d0..c05e17f3. Semantic name remains unreviewed. */

void FUN_c05e17d0(undefined4 *param_1,int param_2)

{
  FUN_c05e1714(4,param_1,param_2);
  return;
}



/* c05e17f4 FUN_c05e17f4 */

/* Boundary evidence: original MIPS .pdata c05e17f4..c05e1817. Semantic name remains unreviewed. */

void FUN_c05e17f4(undefined4 *param_1,int param_2)

{
  FUN_c05e1714(0x1a,param_1,param_2);
  return;
}



/* c05e1818 FUN_c05e1818 */

/* Boundary evidence: original MIPS .pdata c05e1818..c05e185b. Semantic name remains unreviewed. */

undefined4 FUN_c05e1818(void *param_1)

{
  FUN_c05e3a1c(*(int **)((int)param_1 + 0x634));
  memset(param_1,0,0x638);
  LocalFree(param_1);
  return 0;
}



/* c05e185c FUN_c05e185c */

/* Boundary evidence: original MIPS .pdata c05e185c..c05e199b. Semantic name remains unreviewed. */

DWORD FUN_c05e185c(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  wchar_t *_Str1;
  DWORD DVar3;
  wchar_t awStack_248 [274];
  uint local_24;
  
  local_24 = DAT_c05e5230;
  DVar3 = 0;
  if (*(int *)(param_1 + 0x428) == 0) {
    iVar2 = *(int *)(param_3 + 0x30);
    *(uint *)(param_1 + 0x42c) = (uint)((*(uint *)(iVar2 + 0x424) & 1) != 0);
    if (*(short *)(iVar2 + 0x404) == 0) {
      puVar1 = &DAT_c05e1128;
    }
    else {
      puVar1 = &DAT_c05e112c;
    }
    StringCchPrintfW(awStack_248,0x111,L"%s%s%s",(short *)(iVar2 + 0x404),puVar1,iVar2);
    DVar3 = FUN_c05e15dc(param_1,awStack_248);
    if (DVar3 == 0) {
      _Str1 = (wchar_t *)(iVar2 + 0x202);
      DVar3 = FUN_c05e1668(param_1,_Str1);
      if ((DVar3 == 0) && (iVar2 = wcscmp(_Str1,*(wchar_t **)(param_3 + 0x10)), iVar2 != 0)) {
        *(undefined4 *)(param_2 + 0x34) = 1;
        *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 0x42c);
        *(wchar_t **)(param_2 + 0x3c) = _Str1;
      }
    }
  }
  else {
    wcscpy((wchar_t *)(param_1 + 0x430),*(wchar_t **)(param_3 + 0x30));
  }
  FUN_c05e3c00(local_24);
  return DVar3;
}



/* c05e199c FUN_c05e199c */

/* Boundary evidence: original MIPS .pdata c05e199c..c05e1c5b. Semantic name remains unreviewed. */

DWORD FUN_c05e199c(int *param_1,char *param_2,undefined1 *param_3,int param_4,int param_5,
                  int param_6)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  uint local_30 [2];
  
  *(undefined4 *)(param_5 + 4) = 0;
  if ((*(int *)(param_6 + 0x2c) != 0) &&
     (DVar2 = FUN_c05e185c((int)param_1,param_5,param_6), DVar2 != 0)) {
    return DVar2;
  }
  DVar2 = 0;
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar3 = FUN_c05e2120((byte *)(param_2 + 2));
  cVar1 = *param_2;
  if (cVar1 == '\x01') {
    uVar4 = (iVar3 + 0xfffcU & 0xffff) + 0xffff & 0xffff;
    *(char *)(param_1 + 0x89) = param_2[1];
    if (*param_1 == 4) {
      local_30[0] = param_4 - 5;
      DVar2 = FUN_c05e2270((int)param_1,(uint)(byte)param_2[1],(byte *)(param_2 + 5),uVar4);
    }
    else {
      if (*param_1 != 0x1a) goto LAB_c05e1a5c;
      local_30[0] = param_4 - 5;
      DVar2 = FUN_c05e3394((int)param_1,*(int *)(param_6 + 0x2c),param_2 + 5,uVar4,param_3 + 5,
                           local_30);
      if ((param_1[0xa6] == 4) && (param_1[0x10a] != 0)) {
        *(undefined4 *)(param_5 + 0x34) = 1;
        *(int *)(param_5 + 0x38) = param_1[0x10b];
        *(int **)(param_5 + 0x3c) = param_1 + 0x10c;
      }
    }
    if (DVar2 == 0x2bf) {
      *(undefined4 *)(param_5 + 0x10) = 1;
      *(int **)(param_5 + 0x14) = param_1;
      DVar2 = 0;
      *(undefined4 *)(param_5 + 0x18) = 0x638;
    }
    else if (DVar2 == 0) {
      *param_3 = 2;
      param_3[1] = param_2[1];
      FUN_c05e2138(local_30[0] + 5 & 0xffff,param_3 + 2);
      param_3[4] = (char)*param_1;
      *(undefined4 *)(param_5 + 4) = 4;
    }
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x03') {
        if (*param_1 == 4) {
          DVar2 = FUN_c05e22d4();
        }
        else if (*param_1 == 0x1a) {
          DVar2 = FUN_c05e3678((int)param_1);
        }
        *(undefined4 *)(param_5 + 4) = 2;
        *(DWORD *)(param_5 + 8) = DVar2;
        *(int *)(param_5 + 0xc) = param_1[0x18d];
        return DVar2;
      }
      if (cVar1 == '\x04') {
        if (*param_1 == 4) {
          DVar2 = FUN_c05e22d4();
        }
        else if (*param_1 == 0x1a) {
          DVar2 = FUN_c05e36a8((int)param_1);
        }
        if (DVar2 != 0) {
          return DVar2;
        }
        *(undefined4 *)(param_5 + 4) = 2;
        *(undefined4 *)(param_5 + 8) = 0x2b3;
        return 0;
      }
    }
LAB_c05e1a5c:
    DVar2 = 0x2d2;
  }
  return DVar2;
}



/* c05e1c5c RasEapGetInfo */

/* Boundary evidence: original MIPS .pdata c05e1c5c..c05e1d1f. Semantic name remains unreviewed. */

undefined4 RasEapGetInfo(int param_1,void *param_2)

{
                    /* 0x1c5c  3  RasEapGetInfo */
  memset(param_2,0,0x18);
  *(int *)((int)param_2 + 4) = param_1;
  if (param_1 == 4) {
    *(code **)((int)param_2 + 8) = FUN_c05e22d4;
    *(code **)((int)param_2 + 0xc) = FUN_c05e17d0;
    *(code **)((int)param_2 + 0x14) = FUN_c05e199c;
  }
  else {
    if (param_1 != 0x1a) {
      return 0x32;
    }
    *(code **)((int)param_2 + 8) = FUN_c05e22d4;
    *(code **)((int)param_2 + 0xc) = FUN_c05e17f4;
    *(code **)((int)param_2 + 0x14) = FUN_c05e199c;
  }
  *(code **)((int)param_2 + 0x10) = FUN_c05e1818;
  return 0;
}



/* c05e1d20 FUN_c05e1d20 */

/* Boundary evidence: original MIPS .pdata c05e1d20..c05e1e17. Semantic name remains unreviewed. */

undefined4 FUN_c05e1d20(undefined4 param_1,wchar_t *param_2,wchar_t *param_3)

{
  wchar_t *pwVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  memset(param_3,0,0x5b0);
  pwVar1 = wcschr(param_2,L'\\');
  if (pwVar1 != (wchar_t *)0x0) {
    uVar4 = (int)pwVar1 - (int)param_2 >> 1;
    if (0xf < uVar4) {
      return 0x4bc;
    }
    memcpy(param_3 + 0x202,param_2,uVar4 << 1);
    param_2 = pwVar1 + 1;
  }
  sVar2 = wcslen(param_2);
  if (sVar2 < 0x101) {
    wcscpy(param_3,param_2);
    *(uint *)(param_3 + 0x212) = *(uint *)(param_3 + 0x212) | 2;
    iVar3 = FUN_c05e1324(param_1,param_3,(uint *)0x0);
    if (iVar3 == 0) {
      uVar5 = 0x4c7;
    }
  }
  else {
    uVar5 = 0x89a;
  }
  return uVar5;
}



/* c05e1e18 FUN_c05e1e18 */

/* Boundary evidence: original MIPS .pdata c05e1e18..c05e1e7f. Semantic name remains unreviewed. */

undefined4 FUN_c05e1e18(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  memset(param_2,0,0x202);
  iVar1 = FUN_c05e1488(param_1,param_2,(uint *)0x0);
  if (iVar1 == 0) {
    uVar2 = 0x4c7;
  }
  return uVar2;
}



/* c05e1e80 RasEapInvokeInteractiveUI */

/* Boundary evidence: original MIPS .pdata c05e1e80..c05e1fe3. Semantic name remains unreviewed. */

int RasEapInvokeInteractiveUI
              (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
              undefined4 *param_5,undefined4 *param_6)

{
  HLOCAL hMem;
  wchar_t *hMem_00;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  WCHAR aWStack_248 [274];
  uint local_24;
  
                    /* 0x1e80  4  RasEapInvokeInteractiveUI */
  local_24 = DAT_c05e5230;
  uVar3 = 0;
  uVar2 = 0;
  MultiByteToWideChar(1,0,(LPCSTR)(param_3 + 5),-1,aWStack_248,0x111);
  if (*(int *)(param_3 + 0x428) == 0) {
    hMem_00 = LocalAlloc(0x40,0x5b0);
    if (hMem_00 == (wchar_t *)0x0) {
      iVar1 = 8;
    }
    else {
      uVar3 = 0x5b0;
      iVar1 = FUN_c05e1d20(param_2,aWStack_248,hMem_00);
      if (iVar1 != 0) {
        LocalFree(hMem_00);
        hMem_00 = (wchar_t *)0x0;
        uVar3 = 0;
      }
    }
    *param_5 = hMem_00;
    *param_6 = uVar3;
  }
  else {
    hMem = LocalAlloc(0x40,0x202);
    if (hMem == (HLOCAL)0x0) {
      iVar1 = 8;
    }
    else {
      uVar2 = 0x202;
      iVar1 = FUN_c05e1e18(param_2,hMem);
      if (iVar1 != 0) {
        LocalFree(hMem);
        hMem = (HLOCAL)0x0;
        uVar2 = 0;
      }
    }
    *param_5 = hMem;
    *param_6 = uVar2;
  }
  FUN_c05e3c00(local_24);
  return iVar1;
}



/* c05e1fe4 RasEapFreeMemory */

/* Boundary evidence: original MIPS .pdata c05e1fe4..c05e2003. Semantic name remains unreviewed. */

undefined4 RasEapFreeMemory(HLOCAL param_1)

{
                    /* 0x1fe4  2  RasEapFreeMemory */
  LocalFree(param_1);
  return 0;
}



/* c05e2004 DllEntry */

/* Boundary evidence: original MIPS .pdata c05e2004..c05e2037. Semantic name remains unreviewed. */

undefined4 DllEntry(HMODULE param_1,int param_2)

{
                    /* 0x2004  1  DllEntry */
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c05e2038 FUN_c05e2038 */

/* Boundary evidence: original MIPS .pdata c05e2038..c05e208f. Semantic name remains unreviewed. */

void FUN_c05e2038(char *param_1)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  
  sVar2 = strlen(param_1);
  pcVar3 = param_1 + sVar2;
  for (; pcVar3 = pcVar3 + -1, param_1 < pcVar3; param_1 = param_1 + 1) {
    cVar1 = *param_1;
    *param_1 = *pcVar3;
    *pcVar3 = cVar1;
  }
  return;
}



/* c05e2090 FUN_c05e2090 */

/* Boundary evidence: original MIPS .pdata c05e2090..c05e2103. Semantic name remains unreviewed. */

byte * FUN_c05e2090(int param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  
  if (param_2 != (byte *)0x0) {
    FUN_c05e2038((char *)param_2);
    bVar1 = *param_2;
    pbVar2 = param_2;
    while (bVar1 != 0) {
      if ((char)*pbVar2 != param_1) {
        *pbVar2 = (byte)param_1 ^ *pbVar2;
      }
      pbVar2 = pbVar2 + 1;
      bVar1 = *pbVar2;
    }
  }
  return param_2;
}



/* c05e2104 FUN_c05e2104 */

/* Boundary evidence: original MIPS .pdata c05e2104..c05e211f. Semantic name remains unreviewed. */

void FUN_c05e2104(int param_1,byte *param_2)

{
  FUN_c05e2090(param_1,param_2);
  return;
}



/* c05e2120 FUN_c05e2120 */

int FUN_c05e2120(byte *param_1)

{
  return (uint)*param_1 * 0x100 + (uint)param_1[1];
}



/* c05e2138 FUN_c05e2138 */

void FUN_c05e2138(undefined4 param_1,undefined1 *param_2)

{
  *param_2 = (char)((uint)param_1 >> 8);
  param_2[1] = (char)param_1;
  return;
}



/* c05e2148 FUN_c05e2148 */

/* Boundary evidence: original MIPS .pdata c05e2148..c05e226f. Semantic name remains unreviewed. */

undefined4 FUN_c05e2148(int param_1)

{
  undefined4 uVar1;
  uint _Size;
  uint *in_stack_00000010;
  undefined1 *in_stack_00000014;
  
  if (*in_stack_00000010 < 0x11) {
    uVar1 = 8;
  }
  else {
    FUN_c05e2104((uint)*(byte *)(param_1 + 4),(byte *)(param_1 + 0x11c));
    FUN_c05e37ec();
    FUN_c05e37dc();
    FUN_c05e37dc();
    FUN_c05e37dc();
    FUN_c05e37cc();
    FUN_c05e2090((uint)*(byte *)(param_1 + 4),(byte *)(param_1 + 0x11c));
    *in_stack_00000014 = 0x10;
    memcpy(in_stack_00000014 + 1,(void *)(param_1 + 0x288),0x10);
    _Size = *(uint *)(param_1 + 0x118);
    if (*in_stack_00000010 - 0x11 < _Size) {
      _Size = 0;
    }
    else {
      memcpy(in_stack_00000014 + 0x11,(void *)(param_1 + 5),_Size);
    }
    *in_stack_00000010 = _Size + 0x11;
    uVar1 = 0;
  }
  return uVar1;
}



/* c05e2270 FUN_c05e2270 */

/* Boundary evidence: original MIPS .pdata c05e2270..c05e22d3. Semantic name remains unreviewed. */

undefined4 FUN_c05e2270(int param_1,undefined4 param_2,byte *param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_4 == 0) || ((param_4 + 0xffffU & 0xffff) < (uint)*param_3)) {
    uVar1 = 0x2d2;
  }
  else {
    uVar1 = FUN_c05e2148(param_1);
  }
  return uVar1;
}



/* c05e22d4 FUN_c05e22d4 */

undefined4 FUN_c05e22d4(void)

{
  return 0;
}



/* c05e22dc FUN_c05e22dc */

uint FUN_c05e22dc(int param_1)

{
  uint uVar1;
  
  if ((param_1 < 0x30) || (0x39 < param_1)) {
    if ((param_1 < 0x41) || (0x46 < param_1)) {
      if ((param_1 < 0x61) || (0x66 < param_1)) {
        return 0xff;
      }
      uVar1 = param_1 + 0xa9;
    }
    else {
      uVar1 = param_1 + 0xc9;
    }
  }
  else {
    uVar1 = param_1 + 0xd0;
  }
  return uVar1 & 0xff;
}



/* c05e2350 FUN_c05e2350 */

undefined4 FUN_c05e2350(char *param_1,int param_2,int param_3,char *param_4,int param_5)

{
  int iVar1;
  char *pcVar2;
  
  do {
    iVar1 = param_2;
    pcVar2 = param_1;
    param_2 = iVar1 + -1;
    if (param_2 == 0) {
      return 0;
    }
    param_1 = pcVar2 + 1;
  } while ((*pcVar2 != param_3) || (*param_1 != '='));
  pcVar2 = pcVar2 + 2;
  iVar1 = iVar1 + -2;
  while (iVar1 != 0) {
    param_5 = param_5 + -1;
    iVar1 = iVar1 + -1;
    if ((*pcVar2 == ' ') || (param_5 == 0)) break;
    *param_4 = *pcVar2;
    param_4 = param_4 + 1;
    pcVar2 = pcVar2 + 1;
  }
  *param_4 = '\0';
  return 1;
}



/* c05e23e0 FUN_c05e23e0 */

/* Boundary evidence: original MIPS .pdata c05e23e0..c05e2483. Semantic name remains unreviewed. */

void FUN_c05e23e0(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined1 auStack_38 [24];
  uint local_20;
  
  local_20 = DAT_c05e5230;
  memset(auStack_38,0,0x15);
  memcpy(auStack_38,param_2,0x10);
  iVar1 = 3;
  do {
    FUN_c05e37fc();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_c05e3c00(local_20);
  return;
}



/* c05e2484 FUN_c05e2484 */

/* Boundary evidence: original MIPS .pdata c05e2484..c05e24f7. Semantic name remains unreviewed. */

void FUN_c05e2484(undefined4 param_1,undefined4 param_2,void *param_3)

{
  undefined1 auStack_30 [28];
  uint local_14;
  
  local_14 = DAT_c05e5230;
  FUN_c05e381c();
  FUN_c05e380c();
  memcpy(param_3,auStack_30,0x10);
  FUN_c05e3c00(local_14);
  return;
}



/* c05e24f8 FUN_c05e24f8 */

/* Boundary evidence: original MIPS .pdata c05e24f8..c05e25bb. Semantic name remains unreviewed. */

void FUN_c05e24f8(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar1 = DAT_c05e5230;
  FUN_c05e384c();
  FUN_c05e383c();
  FUN_c05e383c();
  strlen(param_3);
  FUN_c05e383c();
  FUN_c05e382c();
  *param_4 = local_30;
  param_4[1] = local_2c;
  FUN_c05e3c00(uVar1);
  return;
}



/* c05e25bc FUN_c05e25bc */

/* Boundary evidence: original MIPS .pdata c05e25bc..c05e2637. Semantic name remains unreviewed. */

void FUN_c05e25bc(undefined4 param_1,undefined4 param_2,char *param_3,wchar_t *param_4)

{
  size_t sVar1;
  undefined4 auStack_30 [2];
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_c05e5230;
  FUN_c05e24f8(param_2,param_1,param_3,auStack_30);
  sVar1 = wcslen(param_4);
  FUN_c05e2484(param_4,sVar1 << 1,auStack_28);
  FUN_c05e23e0(auStack_30,auStack_28);
  FUN_c05e3c00(local_18);
  return;
}



/* c05e2638 FUN_c05e2638 */

/* Boundary evidence: original MIPS .pdata c05e2638..c05e26bf. Semantic name remains unreviewed. */

void FUN_c05e2638(void *param_1,size_t param_2,undefined4 param_3,undefined4 param_4,void *param_5)

{
  uint uVar1;
  
  uVar1 = DAT_c05e5230;
  memcpy(param_5,param_1,param_2);
  FUN_c05e386c();
  FUN_c05e385c();
  FUN_c05e3c00(uVar1);
  return;
}



/* c05e26c0 FUN_c05e26c0 */

/* Boundary evidence: original MIPS .pdata c05e26c0..c05e275b. Semantic name remains unreviewed. */

void FUN_c05e26c0(wchar_t *param_1,undefined4 param_2,void *param_3)

{
  size_t sVar1;
  BYTE aBStack_220 [512];
  size_t local_20;
  uint local_1c;
  
  local_1c = DAT_c05e5230;
  FUN_c05e36b8(0x200,aBStack_220);
  sVar1 = wcslen(param_1);
  memcpy((void *)((int)&local_20 + sVar1 * -2),param_1,sVar1 * 2);
  local_20 = sVar1 * 2;
  FUN_c05e2638(aBStack_220,0x204,param_2,0x10,param_3);
  FUN_c05e3c00(local_1c);
  return;
}



/* c05e275c FUN_c05e275c */

/* Boundary evidence: original MIPS .pdata c05e275c..c05e27cf. Semantic name remains unreviewed. */

void FUN_c05e275c(wchar_t *param_1,wchar_t *param_2,void *param_3)

{
  size_t sVar1;
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_c05e5230;
  sVar1 = wcslen(param_2);
  FUN_c05e2484(param_2,sVar1 << 1,auStack_28);
  FUN_c05e26c0(param_1,auStack_28,param_3);
  FUN_c05e3c00(local_18);
  return;
}



/* c05e27d0 FUN_c05e27d0 */

/* Boundary evidence: original MIPS .pdata c05e27d0..c05e282f. Semantic name remains unreviewed. */

void FUN_c05e27d0(void)

{
  FUN_c05e37fc();
  FUN_c05e37fc();
  return;
}



/* c05e2830 FUN_c05e2830 */

/* Boundary evidence: original MIPS .pdata c05e2830..c05e28bb. Semantic name remains unreviewed. */

void FUN_c05e2830(wchar_t *param_1,wchar_t *param_2)

{
  size_t sVar1;
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  uint local_18;
  
  local_18 = DAT_c05e5230;
  sVar1 = wcslen(param_2);
  FUN_c05e2484(param_2,sVar1 << 1,auStack_28);
  sVar1 = wcslen(param_1);
  FUN_c05e2484(param_1,sVar1 << 1,auStack_38);
  FUN_c05e27d0();
  FUN_c05e3c00(local_18);
  return;
}



/* c05e28bc FUN_c05e28bc */

/* Boundary evidence: original MIPS .pdata c05e28bc..c05e291f. Semantic name remains unreviewed. */

void FUN_c05e28bc(int param_1,LPWSTR param_2)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_1 + 0x11c);
  FUN_c05e2104((uint)*(byte *)(param_1 + 4),pbVar1);
  FUN_c05e15a4((LPCSTR)pbVar1,-1,param_2,0x101);
  FUN_c05e2090((uint)*(byte *)(param_1 + 4),pbVar1);
  return;
}



/* c05e2920 FUN_c05e2920 */

/* Boundary evidence: original MIPS .pdata c05e2920..c05e2a73. Semantic name remains unreviewed. */

undefined4
FUN_c05e2920(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,void *param_5)

{
  char *pcVar1;
  undefined4 uVar2;
  char *_Str;
  wchar_t *pwVar3;
  WCHAR aWStack_230 [258];
  uint local_2c;
  
  local_2c = DAT_c05e5230;
  if (*param_4 < 0x246) {
    uVar2 = 8;
  }
  else {
    memset(param_5,0,0x246);
    FUN_c05e28bc(param_1,aWStack_230);
    pwVar3 = (wchar_t *)(param_1 + 0x430);
    FUN_c05e275c(pwVar3,aWStack_230,param_5);
    FUN_c05e2830(pwVar3,aWStack_230);
    memset(aWStack_230,0,0x202);
    FUN_c05e36b8(0x10,(BYTE *)(param_1 + 0x39e));
    memcpy((void *)((int)param_5 + 0x214),(BYTE *)(param_1 + 0x39e),0x10);
    _Str = (char *)(param_1 + 5);
    pcVar1 = strchr(_Str,0x5c);
    if (pcVar1 != (char *)0x0) {
      _Str = pcVar1 + 1;
    }
    FUN_c05e25bc(param_1 + 0x29d,(void *)((int)param_5 + 0x214),_Str,pwVar3);
    memcpy((void *)((int)param_5 + 0x22c),(void *)(param_1 + 0x3b6),0x18);
    *param_4 = 0x246;
    uVar2 = 0;
  }
  FUN_c05e3c00(local_2c);
  return uVar2;
}



/* c05e2a74 FUN_c05e2a74 */

/* Boundary evidence: original MIPS .pdata c05e2a74..c05e2bd7. Semantic name remains unreviewed. */

undefined4
FUN_c05e2a74(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,undefined1 *param_5)

{
  char *pcVar1;
  int iVar2;
  WCHAR *pWVar3;
  undefined4 uVar4;
  uint _Size;
  char *_Str;
  char *pcVar5;
  BYTE *_Src;
  uint uVar6;
  WCHAR local_230 [258];
  uint local_2c;
  
  local_2c = DAT_c05e5230;
  uVar6 = *param_4;
  if (uVar6 < 0x32) {
    uVar4 = 8;
  }
  else {
    _Src = (BYTE *)(param_1 + 0x39e);
    *param_5 = 0x31;
    FUN_c05e36b8(0x10,_Src);
    memset((void *)(param_1 + 0x3ae),0,8);
    _Str = (char *)(param_1 + 5);
    pcVar1 = strchr(_Str,0x5c);
    pcVar5 = _Str;
    if (pcVar1 != (char *)0x0) {
      pcVar5 = pcVar1 + 1;
    }
    FUN_c05e28bc(param_1,local_230);
    FUN_c05e25bc(param_1 + 0x29d,_Src,pcVar5,local_230);
    iVar2 = 0x202;
    pWVar3 = local_230;
    do {
      *(undefined1 *)pWVar3 = 0;
      iVar2 = iVar2 + -1;
      pWVar3 = (WCHAR *)((int)pWVar3 + 1);
    } while (iVar2 != 0);
    *(undefined1 *)(param_1 + 0x3ce) = 0;
    *(undefined1 *)(param_1 + 0x41e) = 0x31;
    memcpy(param_5 + 1,_Src,0x31);
    _Size = *(uint *)(param_1 + 0x118);
    if (uVar6 - 0x32 < _Size) {
      _Size = 0;
    }
    else {
      memcpy(param_5 + 0x32,_Str,_Size);
    }
    *param_4 = _Size + 0x32;
    uVar4 = 0;
  }
  FUN_c05e3c00(local_2c);
  return uVar4;
}



/* c05e2bd8 FUN_c05e2bd8 */

/* Boundary evidence: original MIPS .pdata c05e2bd8..c05e2d6b. Semantic name remains unreviewed. */

void FUN_c05e2bd8(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5,undefined1 *param_6)

{
  size_t sVar1;
  int iVar2;
  byte *pbVar3;
  char *_Dest;
  int iVar4;
  undefined4 auStack_68 [2];
  byte local_60 [24];
  undefined1 auStack_48 [16];
  undefined1 auStack_38 [16];
  uint local_28;
  
  local_28 = DAT_c05e5230;
  sVar1 = wcslen(param_1);
  FUN_c05e2484(param_1,sVar1 << 1,auStack_38);
  FUN_c05e2484(auStack_38,0x10,auStack_48);
  FUN_c05e384c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e382c();
  FUN_c05e24f8(param_3,param_4,param_5,auStack_68);
  FUN_c05e384c();
  iVar4 = 0x14;
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e382c();
  pbVar3 = local_60;
  *param_6 = 0x53;
  param_6[1] = 0x3d;
  param_6[2] = 0;
  _Dest = param_6 + 2;
  do {
    iVar4 = iVar4 + -1;
    iVar2 = sprintf(_Dest,"%02X",(uint)*pbVar3);
    _Dest = _Dest + iVar2;
    pbVar3 = pbVar3 + 1;
  } while (iVar4 != 0);
  FUN_c05e3c00(local_28);
  return;
}



/* c05e2d6c FUN_c05e2d6c */

/* Boundary evidence: original MIPS .pdata c05e2d6c..c05e2dd3. Semantic name remains unreviewed. */

void FUN_c05e2d6c(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5,void *param_6,undefined4 param_7)

{
  int iVar1;
  undefined1 auStack_38 [44];
  uint local_c;
  
  local_c = DAT_c05e5230;
  FUN_c05e2bd8(param_1,param_2,param_3,param_4,param_5,auStack_38);
  iVar1 = memcmp(param_6,auStack_38,0x2a);
  *(bool *)param_7 = iVar1 == 0;
  FUN_c05e3c00(local_c);
  return;
}



/* c05e2dd4 FUN_c05e2dd4 */

/* Boundary evidence: original MIPS .pdata c05e2dd4..c05e2fe7. Semantic name remains unreviewed. */

int FUN_c05e2dd4(int param_1,char *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  byte *pbVar7;
  uint uVar8;
  char local_230 [516];
  uint local_2c;
  
  local_2c = DAT_c05e5230;
  lVar6 = 0x2b3;
  iVar2 = FUN_c05e2350(param_2,param_3,0x45,local_230,0x201);
  if (iVar2 != 0) {
    lVar6 = strtol(local_230,(char **)0x0,10);
  }
  *(undefined4 *)(param_1 + 0x420) = 0;
  iVar2 = FUN_c05e2350(param_2,param_3,0x52,local_230,0x201);
  if ((iVar2 != 0) && (local_230[0] == '1')) {
    *(undefined4 *)(param_1 + 0x420) = 1;
  }
  bVar1 = false;
  iVar2 = FUN_c05e2350(param_2,param_3,0x43,local_230,0x201);
  if ((iVar2 != 0) && (sVar3 = strlen(local_230), sVar3 == 0x20)) {
    pbVar7 = (byte *)(param_1 + 0x29d);
    uVar8 = 0;
    do {
      uVar4 = FUN_c05e22dc((int)local_230[uVar8]);
      if ((uVar8 & 1) == 0) {
        *pbVar7 = (byte)(uVar4 << 4);
      }
      else {
        *pbVar7 = *pbVar7 | (byte)uVar4;
        pbVar7 = pbVar7 + 1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x20);
    *(undefined1 *)(param_1 + 0x39d) = 0x10;
    bVar1 = true;
  }
  *(undefined4 *)(param_1 + 0x424) = 1;
  iVar2 = FUN_c05e2350(param_2,param_3,0x56,local_230,0x201);
  if (iVar2 != 0) {
    lVar5 = strtol(local_230,(char **)0x0,10);
    *(long *)(param_1 + 0x424) = lVar5;
  }
  *(undefined4 *)(param_1 + 0x428) = 0;
  if (lVar6 == 0x288) {
    *(undefined4 *)(param_1 + 0x428) = 1;
    lVar6 = 0;
    if (!bVar1) {
      *(char *)(param_1 + 0x29d) = *(char *)(param_1 + 0x29d) + '\x17';
    }
  }
  else if (((lVar6 == 0x2b3) && (*(int *)(param_1 + 0x420) != 0)) && (lVar6 = 0, !bVar1)) {
    *(char *)(param_1 + 0x29d) = *(char *)(param_1 + 0x29d) + '\x17';
  }
  FUN_c05e3c00(local_2c);
  return lVar6;
}



/* c05e2fe8 FUN_c05e2fe8 */

/* Boundary evidence: original MIPS .pdata c05e2fe8..c05e307f. Semantic name remains unreviewed. */

undefined4 FUN_c05e2fe8(int param_1,byte *param_2,int param_3,undefined1 *param_4,uint *param_5)

{
  byte bVar1;
  undefined4 uVar2;
  uint _Size;
  
  if (param_3 != 0) {
    bVar1 = *param_2;
    _Size = (uint)bVar1;
    if (_Size <= (param_3 + 0xffffU & 0xffff)) {
      memcpy((void *)(param_1 + 0x29d),param_2 + 1,_Size);
      *(byte *)(param_1 + 0x39d) = bVar1;
      uVar2 = FUN_c05e2a74(param_1,_Size,param_2 + 1,param_5,param_4);
      return uVar2;
    }
  }
  return 0x2d2;
}



/* c05e3080 FUN_c05e3080 */

/* Boundary evidence: original MIPS .pdata c05e3080..c05e321b. Semantic name remains unreviewed. */

undefined4 FUN_c05e3080(void)

{
  void *in_stack_00000010;
  void *in_stack_00000014;
  undefined1 auStack_50 [44];
  uint local_24;
  
  local_24 = DAT_c05e5230;
  FUN_c05e384c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e382c();
  FUN_c05e384c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e382c();
  memcpy(in_stack_00000014,auStack_50,0x10);
  FUN_c05e384c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e383c();
  FUN_c05e382c();
  memcpy(in_stack_00000010,auStack_50,0x10);
  FUN_c05e3c00(local_24);
  return 0;
}



/* c05e321c FUN_c05e321c */

/* Boundary evidence: original MIPS .pdata c05e321c..c05e3393. Semantic name remains unreviewed. */

int FUN_c05e321c(int param_1)

{
  HLOCAL pvVar1;
  size_t sVar2;
  int iVar3;
  undefined1 auStack_288 [16];
  undefined1 auStack_278 [16];
  undefined1 auStack_268 [2];
  undefined1 local_266;
  undefined1 auStack_265 [37];
  undefined1 auStack_240 [16];
  undefined1 auStack_230 [16];
  WCHAR aWStack_220 [258];
  uint local_1c;
  
  local_1c = DAT_c05e5230;
  iVar3 = 0;
  memset(auStack_268,0,0x22);
  memset(auStack_288,0,0x10);
  memset(auStack_278,0,0x10);
  pvVar1 = FUN_c05e39bc(2);
  if (pvVar1 != (HLOCAL)0x0) {
    *(HLOCAL *)(param_1 + 0x634) = pvVar1;
    FUN_c05e28bc(param_1,aWStack_220);
    sVar2 = wcslen(aWStack_220);
    FUN_c05e2484(aWStack_220,sVar2 << 1,auStack_240);
    FUN_c05e2484(auStack_240,0x10,auStack_230);
    FUN_c05e3080();
    local_266 = 0x10;
    memcpy(auStack_265,auStack_278,0x10);
    iVar3 = FUN_c05e38dc(0,(int)pvVar1,0x137,0x10,auStack_268,0x22);
    if (iVar3 == 0) {
      memcpy(auStack_265,auStack_288,0x10);
      iVar3 = FUN_c05e38dc(1,(int)pvVar1,0x137,0x11,auStack_268,0x22);
    }
  }
  FUN_c05e3c00(local_1c);
  return iVar3;
}



/* c05e3394 FUN_c05e3394 */

/* Boundary evidence: original MIPS .pdata c05e3394..c05e3677. Semantic name remains unreviewed. */

DWORD FUN_c05e3394(int param_1,int param_2,char *param_3,uint param_4,undefined1 *param_5,
                  uint *param_6)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  WCHAR *pWVar4;
  DWORD DVar5;
  undefined1 uVar6;
  char cVar7;
  char *_Str;
  uint uVar8;
  byte *pbVar9;
  char local_238 [4];
  uint local_234;
  WCHAR local_230 [258];
  uint local_2c;
  
  local_2c = DAT_c05e5230;
  if (3 < param_4) {
    cVar7 = param_3[1];
    pbVar9 = (byte *)(param_3 + 4);
    uVar8 = CONCAT11(param_3[2],param_3[3]) + 0xfffc & 0xffff;
    if ((CONCAT11(param_3[2],param_3[3]) <= param_4) && (3 < *param_6)) {
      cVar1 = *param_3;
      if (cVar1 == '\x01') {
        *(char *)(param_1 + 0x29c) = cVar7;
        local_234 = *param_6 - 4;
        DVar5 = FUN_c05e2fe8(param_1,pbVar9,uVar8,param_5 + 4,&local_234);
        if (DVar5 != 0) goto LAB_c05e363c;
        *param_6 = local_234 + 4;
        *param_5 = 2;
LAB_c05e3620:
        param_5[1] = cVar7;
        param_5[2] = (char)(*param_6 >> 8);
        param_5[3] = (char)*param_6;
        *(undefined4 *)(param_1 + 0x298) = 1;
        goto LAB_c05e363c;
      }
      uVar6 = 3;
      if (cVar1 == '\x03') {
        if (*(int *)(param_1 + 0x298) == 1) {
          DVar5 = 0x2b3;
          if (*(int *)(param_1 + 0x428) != 0) {
            DVar5 = FUN_c05e1668(param_1,(LPCWSTR)(param_1 + 0x430));
          }
          _Str = (char *)(param_1 + 5);
          pcVar2 = strchr(_Str,0x5c);
          if (pcVar2 != (char *)0x0) {
            _Str = pcVar2 + 1;
          }
          if (0x29 < uVar8) {
            FUN_c05e28bc(param_1,local_230);
            FUN_c05e2d6c(local_230,param_1 + 0x3b6,param_1 + 0x39e,param_1 + 0x29d,_Str,pbVar9,
                         local_238);
            iVar3 = 0x202;
            pWVar4 = local_230;
            do {
              *(undefined1 *)pWVar4 = 0;
              iVar3 = iVar3 + -1;
              pWVar4 = (WCHAR *)((int)pWVar4 + 1);
            } while (iVar3 != 0);
            if (local_238[0] != '\0') {
              DVar5 = 0;
            }
          }
          *param_6 = 1;
          if (DVar5 != 0) {
            uVar6 = 4;
          }
          *param_5 = uVar6;
          if (DVar5 == 0) {
            FUN_c05e321c(param_1);
            *(undefined4 *)(param_1 + 0x298) = 4;
          }
          goto LAB_c05e363c;
        }
      }
      else if (cVar1 == '\x04') {
        uVar6 = 2;
        if ((*(int *)(param_1 + 0x298) != 2) || (param_2 == 0)) {
          *(undefined4 *)(param_1 + 0x298) = 2;
          DVar5 = FUN_c05e2dd4(param_1,(char *)pbVar9,uVar8);
          if (DVar5 == 0) {
            DVar5 = 0x2bf;
          }
          goto LAB_c05e363c;
        }
        cVar7 = cVar7 + '\x01';
        *(char *)(param_1 + 0x29c) = cVar7;
        local_234 = *param_6 - 4;
        if (*(int *)(param_1 + 0x428) == 0) {
          DVar5 = FUN_c05e2a74(param_1,(uint)*(byte *)(param_1 + 0x39d),param_1 + 0x29d,&local_234,
                               param_5 + 4);
        }
        else {
          DVar5 = FUN_c05e2920(param_1,(uint)*(byte *)(param_1 + 0x39d),param_1 + 0x29d,&local_234,
                               param_5 + 4);
          uVar6 = 7;
        }
        if (DVar5 != 0) goto LAB_c05e363c;
        *param_6 = local_234 + 4;
        *param_5 = uVar6;
        goto LAB_c05e3620;
      }
    }
  }
  DVar5 = 0x2d2;
LAB_c05e363c:
  FUN_c05e3c00(local_2c);
  return DVar5;
}



/* c05e3678 FUN_c05e3678 */

undefined4 FUN_c05e3678(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 0x298) == 4) || (*(int *)(param_1 + 0x298) == 6)) {
    *(undefined4 *)(param_1 + 0x298) = 6;
  }
  else {
    uVar1 = 0x2d2;
  }
  return uVar1;
}



/* c05e36a8 FUN_c05e36a8 */

undefined4 FUN_c05e36a8(int param_1)

{
  *(undefined4 *)(param_1 + 0x298) = 5;
  return 0;
}



/* c05e36b8 FUN_c05e36b8 */

/* Boundary evidence: original MIPS .pdata c05e36b8..c05e376b. Semantic name remains unreviewed. */

BOOL FUN_c05e36b8(DWORD param_1,BYTE *param_2)

{
  BOOL BVar1;
  HCRYPTPROV local_18 [2];
  
  local_18[0] = 0;
  BVar1 = CryptAcquireContextW(local_18,(LPCWSTR)0x0,(LPCWSTR)0x0,1,0xf0000040);
  if (BVar1 == 0) {
    if (local_18[0] != 0) {
      CryptReleaseContext(local_18[0],0);
    }
    BVar1 = 0;
  }
  else {
    BVar1 = CryptGenRandom(local_18[0],param_1,param_2);
    if (local_18[0] != 0) {
      CryptReleaseContext(local_18[0],0);
    }
  }
  return BVar1;
}



/* c05e376c FUN_c05e376c */

/* Boundary evidence: original MIPS .pdata c05e376c..c05e37cb. Semantic name remains unreviewed. */

undefined * FUN_c05e376c(void)

{
  if ((DAT_c05e5274 & 1) == 0) {
    DAT_c05e5274 = DAT_c05e5274 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05e5260);
    FUN_c05e3e8c(FUN_c05e422c);
  }
  return &DAT_c05e5260;
}



/* c05e37cc FUN_c05e37cc */

void FUN_c05e37cc(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e37d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50cc)();
  return;
}



/* c05e37dc FUN_c05e37dc */

void FUN_c05e37dc(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e37e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50c8)();
  return;
}



/* c05e37ec FUN_c05e37ec */

void FUN_c05e37ec(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e37f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50c4)();
  return;
}



/* c05e37fc FUN_c05e37fc */

void FUN_c05e37fc(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e3804. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50c0)();
  return;
}



/* c05e380c FUN_c05e380c */

void FUN_c05e380c(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e3814. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50bc)();
  return;
}



/* c05e381c FUN_c05e381c */

void FUN_c05e381c(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e3824. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50b8)();
  return;
}



/* c05e382c FUN_c05e382c */

void FUN_c05e382c(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e3834. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50b4)();
  return;
}



/* c05e383c FUN_c05e383c */

void FUN_c05e383c(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e3844. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50b0)();
  return;
}



/* c05e384c FUN_c05e384c */

void FUN_c05e384c(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e3854. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50ac)();
  return;
}



/* c05e385c FUN_c05e385c */

void FUN_c05e385c(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e3864. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50a8)();
  return;
}



/* c05e386c FUN_c05e386c */

void FUN_c05e386c(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05e3874. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05e50a4)();
  return;
}



/* c05e38dc FUN_c05e38dc */

/* Boundary evidence: original MIPS .pdata c05e38dc..c05e39bb. Semantic name remains unreviewed. */

undefined4
FUN_c05e38dc(int param_1,int param_2,undefined4 param_3,undefined1 param_4,void *param_5,
            byte param_6)

{
  undefined1 *puVar1;
  SIZE_T uBytes;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 * 0xc + param_2);
  *puVar3 = 0x1a;
  uBytes = param_6 + 6;
  puVar3[1] = uBytes;
  uVar2 = 0;
  puVar1 = LocalAlloc(0x40,uBytes);
  puVar3[2] = puVar1;
  if (puVar1 == (undefined1 *)0x0) {
    uVar2 = 0xe;
  }
  else {
    *puVar1 = (char)((uint)param_3 >> 0x18);
    *(char *)(puVar3[2] + 1) = (char)((uint)param_3 >> 0x10);
    *(char *)(puVar3[2] + 2) = (char)((uint)param_3 >> 8);
    *(char *)(puVar3[2] + 3) = (char)param_3;
    *(undefined1 *)(puVar3[2] + 4) = param_4;
    *(byte *)(puVar3[2] + 5) = param_6 + 2;
    memcpy((void *)(puVar3[2] + 6),param_5,(uint)param_6);
  }
  return uVar2;
}



/* c05e39bc FUN_c05e39bc */

/* Boundary evidence: original MIPS .pdata c05e39bc..c05e3a1b. Semantic name remains unreviewed. */

HLOCAL FUN_c05e39bc(uint param_1)

{
  SIZE_T uBytes;
  HLOCAL pvVar1;
  
  if (param_1 < 0x10000) {
    uBytes = (param_1 + 1) * 0xc;
    pvVar1 = LocalAlloc(0x40,uBytes);
    if (pvVar1 != (HLOCAL)0x0) {
      *(undefined4 *)((int)pvVar1 + (uBytes - 0xc)) = 0;
    }
  }
  else {
    pvVar1 = (HLOCAL)0x0;
  }
  return pvVar1;
}



/* c05e3a1c FUN_c05e3a1c */

/* Boundary evidence: original MIPS .pdata c05e3a1c..c05e3a97. Semantic name remains unreviewed. */

void FUN_c05e3a1c(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 != (int *)0x0) {
    iVar2 = 0;
    iVar1 = *param_1;
    piVar3 = param_1;
    while (iVar1 != 0) {
      LocalFree((HLOCAL)piVar3[2]);
      iVar2 = iVar2 + 1;
      piVar3[2] = 0;
      piVar3 = param_1 + iVar2 * 3;
      iVar1 = *piVar3;
    }
    LocalFree(param_1);
  }
  return;
}



/* c05e3a98 entry */

/* Boundary evidence: original MIPS .pdata c05e3a98..c05e3b0b. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c05e3b0c();
    FUN_c05e4054();
  }
  uVar1 = DllEntry(param_1,param_2);
  if (param_2 == 0) {
    FUN_c05e3fdc();
  }
  return uVar1;
}



/* c05e3b0c FUN_c05e3b0c */

/* Boundary evidence: original MIPS .pdata c05e3b0c..c05e3b7f. Semantic name remains unreviewed. */

void FUN_c05e3b0c(void)

{
  uint uVar1;
  
  if ((DAT_c05e5230 == 0) || (DAT_c05e5230 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c05e5230 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c05e5230 == 0) {
      DAT_c05e5230 = 0xb064;
    }
  }
  DAT_c05e5234 = ~DAT_c05e5230;
  return;
}



/* c05e3b80 FUN_c05e3b80 */

/* Boundary evidence: original MIPS .pdata c05e3b80..c05e3bd3. Semantic name remains unreviewed. */

void FUN_c05e3b80(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c05e3c00(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c05e3bd4 FUN_c05e3bd4 */

/* Boundary evidence: original MIPS .pdata c05e3bd4..c05e3bff. Semantic name remains unreviewed. */

undefined4 FUN_c05e3bd4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c05e3b80(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c05e3c00 FUN_c05e3c00 */

/* Boundary evidence: original MIPS .pdata c05e3c00..c05e3c47. Semantic name remains unreviewed. */

void FUN_c05e3c00(uint param_1)

{
  if ((param_1 == DAT_c05e5230) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c05e3c48 FUN_c05e3c48 */

/* Boundary evidence: original MIPS .pdata c05e3c48..c05e3d53. Semantic name remains unreviewed. */

undefined4 FUN_c05e3c48(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c05e5280;
  puVar3 = DAT_c05e527c;
  iVar4 = (int)DAT_c05e527c - (int)DAT_c05e5280;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c05e3c8c:
    param_1 = 0;
  }
  else {
    if (DAT_c05e5280 != (void *)0x0) {
      uVar1 = _msize(DAT_c05e5280);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c05e3d00:
        if (pvVar2 == (void *)0x0) goto LAB_c05e3c8c;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c05e3d00;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c05e527c = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c05e5280 = pvVar2;
  }
  return param_1;
}



/* c05e3d54 FUN_c05e3d54 */

/* Boundary evidence: original MIPS .pdata c05e3d54..c05e3e3f. Semantic name remains unreviewed. */

undefined4 FUN_c05e3d54(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c05e5284 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c05e5284,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c05e5284 == (LPCRITICAL_SECTION)0x0) goto LAB_c05e3df8;
  }
  EnterCriticalSection(DAT_c05e5284);
LAB_c05e3df8:
  uVar2 = FUN_c05e3c48(param_1);
  FUN_c05e3e40();
  return uVar2;
}



/* c05e3e40 FUN_c05e3e40 */

/* Boundary evidence: original MIPS .pdata c05e3e40..c05e3e8b. Semantic name remains unreviewed. */

void FUN_c05e3e40(void)

{
  if (DAT_c05e5284 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c05e5284);
  }
  return;
}



/* c05e3e8c FUN_c05e3e8c */

/* Boundary evidence: original MIPS .pdata c05e3e8c..c05e3ebb. Semantic name remains unreviewed. */

undefined4 FUN_c05e3e8c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c05e3d54(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c05e3ebc FUN_c05e3ebc */

/* Boundary evidence: original MIPS .pdata c05e3ebc..c05e3fdb. Semantic name remains unreviewed. */

void FUN_c05e3ebc(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c05e5279 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c05e5280;
    if (DAT_c05e5280 != (undefined4 *)0x0) {
      while (DAT_c05e527c = DAT_c05e527c + -1, _Memory <= DAT_c05e527c) {
        if ((code *)*DAT_c05e527c != (code *)0x0) {
          (*(code *)*DAT_c05e527c)();
          _Memory = DAT_c05e5280;
        }
      }
      free(_Memory);
      DAT_c05e527c = (undefined4 *)0x0;
      DAT_c05e5280 = (undefined4 *)0x0;
    }
    FUN_c05e4000((undefined4 *)&DAT_c05e1014,(undefined4 *)&DAT_c05e1018);
  }
  FUN_c05e4000((undefined4 *)&DAT_c05e101c,(undefined4 *)&DAT_c05e1020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c05e5284,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c05e3fdc FUN_c05e3fdc */

/* Boundary evidence: original MIPS .pdata c05e3fdc..c05e3fff. Semantic name remains unreviewed. */

void FUN_c05e3fdc(void)

{
  FUN_c05e3ebc(0,0,1);
  return;
}



/* c05e4000 FUN_c05e4000 */

/* Boundary evidence: original MIPS .pdata c05e4000..c05e4053. Semantic name remains unreviewed. */

void FUN_c05e4000(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c05e4054 FUN_c05e4054 */

/* Boundary evidence: original MIPS .pdata c05e4054..c05e408f. Semantic name remains unreviewed. */

void FUN_c05e4054(void)

{
  FUN_c05e4000((undefined4 *)&DAT_c05e100c,(undefined4 *)&DAT_c05e1010);
  FUN_c05e4000((undefined4 *)&DAT_c05e1000,(undefined4 *)&DAT_c05e1008);
  return;
}



/* c05e4210 FUN_c05e4210 */

/* Boundary evidence: original MIPS .pdata c05e4210..c05e422b. Semantic name remains unreviewed. */

void FUN_c05e4210(void)

{
  FUN_c05e376c();
  return;
}



/* c05e422c FUN_c05e422c */

/* Boundary evidence: original MIPS .pdata c05e422c..c05e424b. Semantic name remains unreviewed. */

void FUN_c05e422c(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c05e5260);
  return;
}


