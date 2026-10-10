/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0151084 FUN_c0151084 */

/* Boundary evidence: original MIPS .pdata c0151084..c0151167. Semantic name remains unreviewed. */

wchar_t * FUN_c0151084(wchar_t *param_1,size_t *param_2)

{
  size_t sVar1;
  int iVar2;
  wchar_t *pwVar3;
  
  for (; (*param_1 == L'\\' || (*param_1 == L'/')); param_1 = param_1 + 1) {
  }
  sVar1 = wcslen(param_1);
  if ((7 < sVar1) && (iVar2 = _wcsnicmp(param_1,L"Windows",7), iVar2 == 0)) {
    pwVar3 = param_1 + 7;
    if ((*pwVar3 == L'\\') || (*pwVar3 == L'/')) {
      for (; (*pwVar3 == L'\\' || (param_1 = pwVar3, *pwVar3 == L'/')); pwVar3 = pwVar3 + 1) {
      }
    }
  }
  sVar1 = wcslen(param_1);
  *param_2 = sVar1;
  return param_1;
}



/* c0151168 FUN_c0151168 */

/* Boundary evidence: original MIPS .pdata c0151168..c015122f. Semantic name remains unreviewed. */

undefined4 FUN_c0151168(int param_1,wchar_t *param_2,size_t param_3)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_250 [40];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c0154070;
  iVar3 = 0;
  while( true ) {
    iVar2 = GetRomFileInfo(2,auStack_250,iVar3);
    if (iVar2 == 0) {
      FUN_c0152de4(local_20);
      return 0;
    }
    sVar1 = wcslen(awStack_228);
    if ((param_3 == sVar1) && (iVar2 = _wcsnicmp(param_2,awStack_228,param_3), iVar2 == 0)) break;
    iVar3 = iVar3 + 1;
  }
  *(undefined4 *)(param_1 + 4) = 1;
  *(int *)(param_1 + 8) = iVar3;
  FUN_c0152de4(local_20);
  return 1;
}



/* c0151230 FSD_MountDisk */

/* Boundary evidence: original MIPS .pdata c0151230..c0151287. Semantic name remains unreviewed. */

undefined4 FSD_MountDisk(undefined4 param_1)

{
                    /* 0x1230  14  FSD_MountDisk */
  if ((DAT_c0154090 == 0) &&
     (DAT_c0154078 = param_1, DAT_c0154090 = FSDMGR_RegisterVolume(param_1,&DAT_c015104c,param_1),
     DAT_c0154090 == 0)) {
    return 0;
  }
  return 1;
}



/* c0151288 FSD_UnmountDisk */

/* Boundary evidence: original MIPS .pdata c0151288..c01512ab. Semantic name remains unreviewed. */

undefined4 FSD_UnmountDisk(void)

{
                    /* 0x1288  24  FSD_UnmountDisk */
  FSDMGR_DeregisterVolume(DAT_c0154090);
  return 1;
}



/* c01512ac FSD_CreateDirectoryW */

/* Boundary evidence: original MIPS .pdata c01512ac..c01512d3. Semantic name remains unreviewed. */

undefined4 FSD_CreateDirectoryW(void)

{
                    /* 0x12ac  2  FSD_CreateDirectoryW */
  SetLastError(5);
  return 0;
}



/* c01512d4 FSD_RemoveDirectoryW */

/* Boundary evidence: original MIPS .pdata c01512d4..c01512fb. Semantic name remains unreviewed. */

undefined4 FSD_RemoveDirectoryW(void)

{
                    /* 0x12d4  19  FSD_RemoveDirectoryW */
  SetLastError(5);
  return 0;
}



/* c01512fc FSD_GetFileAttributesW */

/* Boundary evidence: original MIPS .pdata c01512fc..c015152f. Semantic name remains unreviewed. */

int FSD_GetFileAttributesW
              (undefined4 param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  wchar_t *_Str1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t local_268 [2];
  int local_260 [10];
  wchar_t awStack_238 [260];
  uint local_30;
  
                    /* 0x12fc  10  FSD_GetFileAttributesW */
  local_30 = DAT_c0154070;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  _Str1 = FUN_c0151084(param_2,local_268);
  SetLastError(0);
  iVar6 = 0;
  while (iVar2 = GetRomFileInfo(1,local_260,iVar6), iVar4 = -1, iVar2 != 0) {
    sVar3 = wcslen(awStack_238);
    if (local_268[0] == sVar3) {
      iVar4 = _wcsnicmp(_Str1,awStack_238,local_268[0]);
      bVar1 = true;
      if (iVar4 != 0) goto LAB_c01513e4;
    }
    else {
LAB_c01513e4:
      bVar1 = false;
    }
    iVar4 = local_260[0];
    if (bVar1) break;
    iVar6 = iVar6 + 1;
  }
  iVar6 = iVar4;
  if (iVar4 == -1) {
    iVar2 = 0;
    while (iVar5 = GetRomFileInfo(2,local_260,iVar2), iVar6 = iVar4, iVar5 != 0) {
      sVar3 = wcslen(awStack_238);
      if (local_268[0] == sVar3) {
        iVar6 = _wcsnicmp(_Str1,awStack_238,local_268[0]);
        bVar1 = true;
        if (iVar6 != 0) goto LAB_c0151468;
      }
      else {
LAB_c0151468:
        bVar1 = false;
      }
      iVar6 = local_260[0];
      if (bVar1) break;
      iVar2 = iVar2 + 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  if (iVar6 == -1) {
    SetLastError(2);
  }
  FUN_c0152de4(local_30);
  return iVar6;
}



/* c0151530 FUN_c0151530 */

/* Boundary evidence: original MIPS .pdata c0151530..c015153b. Semantic name remains unreviewed. */

undefined4 FUN_c0151530(void)

{
  return 1;
}



/* c015153c FSD_SetFileAttributesW */

/* Boundary evidence: original MIPS .pdata c015153c..c0151563. Semantic name remains unreviewed. */

undefined4 FSD_SetFileAttributesW(void)

{
                    /* 0x153c  21  FSD_SetFileAttributesW */
  SetLastError(5);
  return 0;
}



/* c0151564 FSD_DeleteFileW */

/* Boundary evidence: original MIPS .pdata c0151564..c015158b. Semantic name remains unreviewed. */

undefined4 FSD_DeleteFileW(void)

{
                    /* 0x1564  5  FSD_DeleteFileW */
  SetLastError(5);
  return 0;
}



/* c015158c FSD_MoveFileW */

/* Boundary evidence: original MIPS .pdata c015158c..c01515b3. Semantic name remains unreviewed. */

undefined4 FSD_MoveFileW(void)

{
                    /* 0x158c  15  FSD_MoveFileW */
  SetLastError(5);
  return 0;
}



/* c01515b4 FSD_RegisterFileSystemFunction */

undefined4 FSD_RegisterFileSystemFunction(void)

{
                    /* 0x15b4  18  FSD_RegisterFileSystemFunction */
  return 1;
}



/* c01515bc FSD_DeleteAndRenameFileW */

/* Boundary evidence: original MIPS .pdata c01515bc..c01515e3. Semantic name remains unreviewed. */

undefined4 FSD_DeleteAndRenameFileW(void)

{
                    /* 0x15bc  4  FSD_DeleteAndRenameFileW */
  SetLastError(5);
  return 0;
}



/* c01515e4 FSD_FlushFileBuffers */

/* Boundary evidence: original MIPS .pdata c01515e4..c015160b. Semantic name remains unreviewed. */

undefined4 FSD_FlushFileBuffers(void)

{
                    /* 0x15e4  9  FSD_FlushFileBuffers */
  SetLastError(5);
  return 0;
}



/* c015160c FSD_GetFileTime */

/* Boundary evidence: original MIPS .pdata c015160c..c015177b. Semantic name remains unreviewed. */

undefined4 FSD_GetFileTime(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined1 auStack_258 [4];
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  uint local_28;
  
                    /* 0x160c  13  FSD_GetFileTime */
  local_28 = DAT_c0154070;
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  if ((*(uint *)(param_1 + 4) & 1) == 0) {
    SetLastError(5);
  }
  else {
    GetRomFileInfo(2,auStack_258,*(undefined4 *)(param_1 + 8));
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = local_254;
      param_2[1] = local_250;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = local_24c;
      param_3[1] = local_248;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_244;
      param_4[1] = local_240;
    }
    uVar1 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  FUN_c0152de4(local_28);
  return uVar1;
}



/* c015177c FUN_c015177c */

/* Boundary evidence: original MIPS .pdata c015177c..c0151787. Semantic name remains unreviewed. */

undefined4 FUN_c015177c(void)

{
  return 1;
}



/* c0151788 FSD_SetFileTime */

/* Boundary evidence: original MIPS .pdata c0151788..c01517af. Semantic name remains unreviewed. */

undefined4 FSD_SetFileTime(void)

{
                    /* 0x1788  23  FSD_SetFileTime */
  SetLastError(5);
  return 0;
}



/* c01517b0 FSD_SetEndOfFile */

/* Boundary evidence: original MIPS .pdata c01517b0..c01517d7. Semantic name remains unreviewed. */

undefined4 FSD_SetEndOfFile(void)

{
                    /* 0x17b0  20  FSD_SetEndOfFile */
  SetLastError(5);
  return 0;
}



/* c01517d8 FSD_CreateFileW */

/* Boundary evidence: original MIPS .pdata c01517d8..c01519c3. Semantic name remains unreviewed. */

undefined4 FSD_CreateFileW(undefined4 param_1,undefined4 param_2,wchar_t *param_3,uint param_4)

{
  wchar_t *pwVar1;
  int iVar2;
  DWORD dwErrCode;
  undefined4 *hMem;
  undefined4 uVar3;
  size_t local_30 [2];
  
                    /* 0x17d8  3  FSD_CreateFileW */
  hMem = (undefined4 *)0x0;
  uVar3 = 0xffffffff;
  local_30[1] = 0xffffffff;
  dwErrCode = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  pwVar1 = FUN_c0151084(param_3,local_30);
  if (local_30[0] == 0) {
    dwErrCode = 0x7b;
  }
  else {
    hMem = LocalAlloc(0,0xc);
    if (hMem == (undefined4 *)0x0) {
      dwErrCode = 0xe;
    }
    else {
      iVar2 = FUN_c0151168((int)hMem,pwVar1,local_30[0]);
      if (iVar2 == 0) {
        dwErrCode = 2;
      }
      else {
        if ((param_4 & 0x40000000) == 0) {
          *hMem = 0;
          goto LAB_c01518f8;
        }
        dwErrCode = 5;
      }
      LocalFree(hMem);
    }
  }
LAB_c01518f8:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  if ((hMem != (undefined4 *)0x0) && (dwErrCode == 0)) {
    uVar3 = FSDMGR_CreateFileHandle(DAT_c0154090,param_2,hMem);
  }
  SetLastError(dwErrCode);
  return uVar3;
}



/* c01519c4 FUN_c01519c4 */

/* Boundary evidence: original MIPS .pdata c01519c4..c01519cf. Semantic name remains unreviewed. */

undefined4 FUN_c01519c4(void)

{
  return 1;
}



/* c01519d0 FUN_c01519d0 */

/* Boundary evidence: original MIPS .pdata c01519d0..c0151a7b. Semantic name remains unreviewed. */

undefined4 FUN_c01519d0(undefined4 param_1,uint param_2,wchar_t *param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_250 [40];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c0154070;
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      iVar1 = GetRomFileInfo(param_1,auStack_250,uVar2);
      if (iVar1 == 0) break;
      iVar1 = wcscmp(param_3,awStack_228);
      if (iVar1 == 0) {
        FUN_c0152de4(local_20);
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  FUN_c0152de4(local_20);
  return 0;
}



/* c0151a7c FUN_c0151a7c */

/* Boundary evidence: original MIPS .pdata c0151a7c..c0151cab. Semantic name remains unreviewed. */

undefined4 FUN_c0151a7c(uint *param_1,int param_2)

{
  int iVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  
  if ((*param_1 & 0x80000000) == 0) {
    if ((*param_1 & 1) != 0) {
      iVar1 = GetRomFileInfo(1,param_2,param_1[1]);
      if (iVar1 != 0) {
        pwVar3 = (wchar_t *)(param_2 + 0x28);
        do {
          *(uint *)(param_2 + 0x24) = param_1[1] & 0xfff | 0x10001000;
          param_1[1] = param_1[1] + 1;
          sVar2 = wcslen(pwVar3);
          iVar1 = MatchesWildcardMask(param_1[2],param_1 + 3,sVar2,pwVar3);
          if ((iVar1 != 0) && (iVar1 = FUN_c01519d0(1,param_1[1] - 1,pwVar3), iVar1 == 0)) {
            return 1;
          }
          iVar1 = GetRomFileInfo(1,param_2,param_1[1]);
        } while (iVar1 != 0);
      }
      *param_1 = *param_1 & 0xfffffffe | 2;
      param_1[1] = 0;
    }
    if ((*param_1 & 2) != 0) {
      iVar1 = GetRomFileInfo(2,param_2,param_1[1]);
      if (iVar1 != 0) {
        pwVar3 = (wchar_t *)(param_2 + 0x28);
        do {
          *(uint *)(param_2 + 0x24) = param_1[1] & 0xfff | 0x10002000;
          param_1[1] = param_1[1] + 1;
          sVar2 = wcslen(pwVar3);
          iVar1 = MatchesWildcardMask(param_1[2],param_1 + 3,sVar2,pwVar3);
          if (((iVar1 != 0) && (iVar1 = FUN_c01519d0(1,0xffffffff,pwVar3), iVar1 == 0)) &&
             (iVar1 = FUN_c01519d0(2,param_1[1] - 1,pwVar3), iVar1 == 0)) {
            return 1;
          }
          iVar1 = GetRomFileInfo(2,param_2,param_1[1]);
        } while (iVar1 != 0);
      }
      param_1[1] = 0;
      *param_1 = *param_1 & 0xfffffffd | 0x80000000;
    }
    SetLastError(0x12);
  }
  else {
    SetLastError(0x12);
  }
  return 0;
}



/* c0151cac FSD_FindFirstFileW */

/* Boundary evidence: original MIPS .pdata c0151cac..c0151e6f. Semantic name remains unreviewed. */

undefined4 FSD_FindFirstFileW(undefined4 param_1,undefined4 param_2,wchar_t *param_3,int param_4)

{
  wchar_t *_Src;
  uint *hMem;
  int iVar1;
  size_t _Size;
  undefined4 uVar2;
  uint *local_2c;
  undefined4 local_28;
  
                    /* 0x1cac  7  FSD_FindFirstFileW */
  uVar2 = 0xffffffff;
  local_28 = 0xffffffff;
  _Src = FUN_c0151084(param_3,(size_t *)&local_2c);
  if (local_2c < (uint *)0x105) {
    hMem = LocalAlloc(0,0x214);
    if (hMem == (uint *)0x0) {
      local_2c = hMem;
      SetLastError(0xe);
    }
    else {
      *hMem = 1;
      hMem[2] = (uint)local_2c & 0xffff;
      _Size = (int)local_2c << 1;
      local_2c = hMem;
      memcpy(hMem + 3,_Src,_Size);
      hMem[1] = 0;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
      iVar1 = FUN_c0151a7c(hMem,param_4);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
      if (iVar1 == 0) {
        LocalFree(hMem);
      }
      else {
        uVar2 = FSDMGR_CreateSearchHandle(DAT_c0154090,param_2,hMem);
      }
    }
  }
  else {
    SetLastError(0x7b);
  }
  return uVar2;
}



/* c0151e70 FUN_c0151e70 */

/* Boundary evidence: original MIPS .pdata c0151e70..c0151e7b. Semantic name remains unreviewed. */

undefined4 FUN_c0151e70(void)

{
  return 1;
}



/* c0151e7c FSD_FindNextFileW */

/* Boundary evidence: original MIPS .pdata c0151e7c..c0151f37. Semantic name remains unreviewed. */

undefined4 FSD_FindNextFileW(uint *param_1,int param_2)

{
  undefined4 uVar1;
  
                    /* 0x1e7c  8  FSD_FindNextFileW */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  uVar1 = FUN_c0151a7c(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  return uVar1;
}



/* c0151f38 FUN_c0151f38 */

/* Boundary evidence: original MIPS .pdata c0151f38..c0151f43. Semantic name remains unreviewed. */

undefined4 FUN_c0151f38(void)

{
  return 1;
}



/* c0151f44 FSD_FindClose */

/* Boundary evidence: original MIPS .pdata c0151f44..c0151fdf. Semantic name remains unreviewed. */

undefined4 FSD_FindClose(HLOCAL param_1)

{
                    /* 0x1f44  6  FSD_FindClose */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  LocalFree(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  return 1;
}



/* c0151fe0 FUN_c0151fe0 */

/* Boundary evidence: original MIPS .pdata c0151fe0..c0151feb. Semantic name remains unreviewed. */

undefined4 FUN_c0151fe0(void)

{
  return 1;
}



/* c0151fec FSD_CloseFile */

/* Boundary evidence: original MIPS .pdata c0151fec..c0152087. Semantic name remains unreviewed. */

undefined4 FSD_CloseFile(HLOCAL param_1)

{
                    /* 0x1fec  1  FSD_CloseFile */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  LocalFree(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  return 1;
}



/* c0152088 FUN_c0152088 */

/* Boundary evidence: original MIPS .pdata c0152088..c0152093. Semantic name remains unreviewed. */

undefined4 FUN_c0152088(void)

{
  return 1;
}



/* c0152094 FSD_ReadFile */

/* Boundary evidence: original MIPS .pdata c0152094..c015220f. Semantic name remains unreviewed. */

undefined4 FSD_ReadFile(uint *param_1,int param_2,undefined4 param_3,int *param_4,int param_5)

{
  int iVar1;
  DWORD dwErrCode;
  uint uVar2;
  undefined4 uVar3;
  
                    /* 0x2094  16  FSD_ReadFile */
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  if (((param_4 == (int *)0x0) || (*param_4 = 0, param_2 == 0)) || (param_5 != 0)) {
    dwErrCode = 0x57;
  }
  else {
    if ((param_1[1] & 1) != 0) {
      iVar1 = GetRomFileBytes(2,param_1[2],*param_1,param_2,param_3);
      uVar2 = *param_1 + iVar1;
      if (uVar2 < *param_1) {
        *param_1 = 0xffffffff;
      }
      else {
        *param_1 = uVar2;
      }
      *param_4 = iVar1;
      uVar3 = 1;
      goto LAB_c015219c;
    }
    dwErrCode = 5;
  }
  SetLastError(dwErrCode);
LAB_c015219c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  return uVar3;
}



/* c0152210 FUN_c0152210 */

/* Boundary evidence: original MIPS .pdata c0152210..c015221b. Semantic name remains unreviewed. */

undefined4 FUN_c0152210(void)

{
  return 1;
}



/* c015221c FSD_ReadFileWithSeek */

/* Boundary evidence: original MIPS .pdata c015221c..c01523d7. Semantic name remains unreviewed. */

undefined4
FSD_ReadFileWithSeek
          (uint *param_1,int param_2,int param_3,int *param_4,int param_5,uint param_6,int param_7)

{
  int iVar1;
  DWORD dwErrCode;
  uint uVar2;
  undefined4 uVar3;
  
                    /* 0x221c  17  FSD_ReadFileWithSeek */
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  if ((((param_2 == 0) && (param_3 == 0)) && (param_4 == (int *)0x0)) &&
     ((param_6 == 0 && (param_7 == 0)))) {
LAB_c01522a0:
    uVar3 = 1;
  }
  else {
    if (((param_4 == (int *)0x0) || ((param_2 == 0 || (param_5 != 0)))) || (param_7 != 0)) {
      dwErrCode = 0x57;
    }
    else {
      *param_4 = 0;
      if ((param_1[1] & 1) != 0) {
        *param_1 = param_6;
        iVar1 = GetRomFileBytes(2,param_1[2],param_6,param_2,param_3);
        uVar2 = *param_1 + iVar1;
        if (uVar2 < *param_1) {
          *param_1 = 0xffffffff;
        }
        else {
          *param_1 = uVar2;
        }
        *param_4 = iVar1;
        goto LAB_c01522a0;
      }
      dwErrCode = 5;
    }
    SetLastError(dwErrCode);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  return uVar3;
}



/* c01523d8 FUN_c01523d8 */

/* Boundary evidence: original MIPS .pdata c01523d8..c01523e3. Semantic name remains unreviewed. */

undefined4 FUN_c01523d8(void)

{
  return 1;
}



/* c01523e4 FSD_WriteFile */

/* Boundary evidence: original MIPS .pdata c01523e4..c015240b. Semantic name remains unreviewed. */

undefined4 FSD_WriteFile(void)

{
                    /* 0x23e4  25  FSD_WriteFile */
  SetLastError(5);
  return 0;
}



/* c015240c FSD_WriteFileWithSeek */

/* Boundary evidence: original MIPS .pdata c015240c..c0152433. Semantic name remains unreviewed. */

undefined4 FSD_WriteFileWithSeek(void)

{
                    /* 0x240c  26  FSD_WriteFileWithSeek */
  SetLastError(5);
  return 0;
}



/* c0152434 FSD_SetFilePointer */

/* Boundary evidence: original MIPS .pdata c0152434..c015278b. Semantic name remains unreviewed. */

uint FSD_SetFilePointer(uint *param_1,uint param_2,int *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  DWORD dwErrCode;
  undefined1 auStack_260 [32];
  uint local_240;
  uint local_30;
  
                    /* 0x2434  22  FSD_SetFilePointer */
  local_30 = DAT_c0154070;
  uVar2 = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  dwErrCode = 0;
  if ((param_1[1] & 1) == 0) {
    dwErrCode = 5;
  }
  else if (param_4 == 0) {
    if ((int)param_2 < 0) {
      dwErrCode = 0x83;
    }
    else if ((param_3 == (int *)0x0) || (*param_3 == 0)) {
      *param_1 = param_2;
      uVar2 = param_2;
    }
    else {
      dwErrCode = 0x57;
    }
  }
  else {
    if (param_4 == 1) {
      if ((((-1 < (int)param_2) || (param_3 == (int *)0x0)) || (*param_3 == -1)) &&
         ((((int)param_2 < 0 || (param_3 == (int *)0x0)) || (*param_3 == 0)))) {
        if (((int)param_2 < 0) && (*param_1 < -param_2)) {
          dwErrCode = 0x83;
        }
        else if (((int)param_2 < 1) || (*param_1 <= *param_1 + param_2)) {
          uVar2 = *param_1;
          *param_1 = uVar2 + param_2;
          uVar2 = uVar2 + param_2;
        }
        else {
          *param_1 = 0xffffffff;
        }
        goto LAB_c01526e4;
      }
    }
    else {
      if (param_4 != 2) {
        SetLastError(0x57);
        goto LAB_c01526e4;
      }
      iVar1 = GetRomFileInfo(2,auStack_260,param_1[2]);
      if (iVar1 == 0) {
        local_240 = uVar2;
      }
      if ((((-1 < (int)param_2) || (param_3 == (int *)0x0)) || (*param_3 == -1)) &&
         (((((int)param_2 < 0 || (param_3 == (int *)0x0)) || (*param_3 == 0)) &&
          (local_240 != 0xffffffff)))) {
        if (((int)param_2 < 0) && (local_240 < -param_2)) {
          dwErrCode = 0x83;
        }
        else if (((int)param_2 < 1) || (*param_1 <= *param_1 + param_2)) {
          *param_1 = local_240 + param_2;
          uVar2 = local_240 + param_2;
        }
        else {
          *param_1 = 0xffffffff;
        }
        goto LAB_c01526e4;
      }
    }
    dwErrCode = 0x57;
  }
LAB_c01526e4:
  if ((dwErrCode == 0) && (param_3 != (int *)0x0)) {
    *param_3 = 0;
  }
  SetLastError(dwErrCode);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  FUN_c0152de4(local_30);
  return uVar2;
}



/* c015278c FUN_c015278c */

/* Boundary evidence: original MIPS .pdata c015278c..c0152797. Semantic name remains unreviewed. */

undefined4 FUN_c015278c(void)

{
  return 1;
}



/* c0152798 FSD_GetFileInformationByHandle */

/* Boundary evidence: original MIPS .pdata c0152798..c01528f3. Semantic name remains unreviewed. */

undefined4
FSD_GetFileInformationByHandle
          (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  uint local_20;
  
                    /* 0x2798  11  FSD_GetFileInformationByHandle */
  local_20 = DAT_c0154070;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  param_2[7] = 0;
  param_2[10] = 1;
  param_2[0xb] = 0;
  GetRomFileInfo(2,&local_250,*(undefined4 *)(param_1 + 8));
  *param_2 = local_250;
  param_2[1] = local_24c;
  param_2[2] = local_248;
  param_2[3] = local_244;
  param_2[4] = local_240;
  param_2[5] = local_23c;
  param_2[6] = local_238;
  param_2[8] = local_234;
  param_2[9] = local_230;
  param_2[0xc] = *(uint *)(param_1 + 8) & 0xfff | 0x10002000;
  param_2[0xd] = *(uint *)(param_1 + 8) & 0xfff | 0x10002000;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  FUN_c0152de4(local_20);
  return 1;
}



/* c01528f4 FUN_c01528f4 */

/* Boundary evidence: original MIPS .pdata c01528f4..c01528ff. Semantic name remains unreviewed. */

undefined4 FUN_c01528f4(void)

{
  return 1;
}



/* c0152900 FSD_GetFileSize */

/* Boundary evidence: original MIPS .pdata c0152900..c01529fb. Semantic name remains unreviewed. */

undefined4 FSD_GetFileSize(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_250 [32];
  undefined4 local_230;
  uint local_20;
  
                    /* 0x2900  12  FSD_GetFileSize */
  local_20 = DAT_c0154070;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  iVar1 = GetRomFileInfo(2,auStack_250,*(undefined4 *)(param_1 + 8));
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    uVar2 = local_230;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  FUN_c0152de4(local_20);
  return uVar2;
}



/* c01529fc FUN_c01529fc */

/* Boundary evidence: original MIPS .pdata c01529fc..c0152a07. Semantic name remains unreviewed. */

undefined4 FUN_c01529fc(void)

{
  return 1;
}



/* c0152a08 FUN_c0152a08 */

/* Boundary evidence: original MIPS .pdata c0152a08..c0152a5f. Semantic name remains unreviewed. */

undefined4 FUN_c0152a08(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c015407c);
  }
  return 1;
}



/* c0152b30 FUN_c0152b30 */

/* Boundary evidence: original MIPS .pdata c0152b30..c0152c6b. Semantic name remains unreviewed. */

int FUN_c0152b30(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c01540a4 != (code *)0x0) {
      iVar2 = (*DAT_c01540a4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0152be0;
    FUN_c0153040();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0152a08(param_1,param_2);
  }
LAB_c0152be0:
  if (((param_2 == 0) && (FUN_c0152fc8(), iVar1 != 0)) && (DAT_c01540a4 != (code *)0x0)) {
    iVar1 = (*DAT_c01540a4)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0152c6c FUN_c0152c6c */

/* Boundary evidence: original MIPS .pdata c0152c6c..c0152c97. Semantic name remains unreviewed. */

void FUN_c0152c6c(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c0152c98 entry */

/* Boundary evidence: original MIPS .pdata c0152c98..c0152cef. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c0152cf0();
  }
  FUN_c0152b30(param_1,param_2,param_3);
  return;
}



/* c0152cf0 FUN_c0152cf0 */

/* Boundary evidence: original MIPS .pdata c0152cf0..c0152d63. Semantic name remains unreviewed. */

void FUN_c0152cf0(void)

{
  uint uVar1;
  
  if ((DAT_c0154070 == 0) || (DAT_c0154070 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0154070 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0154070 == 0) {
      DAT_c0154070 = 0xb064;
    }
  }
  DAT_c0154074 = ~DAT_c0154070;
  return;
}



/* c0152d64 FUN_c0152d64 */

/* Boundary evidence: original MIPS .pdata c0152d64..c0152db7. Semantic name remains unreviewed. */

void FUN_c0152d64(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0152de4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0152db8 FUN_c0152db8 */

/* Boundary evidence: original MIPS .pdata c0152db8..c0152de3. Semantic name remains unreviewed. */

undefined4 FUN_c0152db8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0152d64(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0152de4 FUN_c0152de4 */

/* Boundary evidence: original MIPS .pdata c0152de4..c0152e2b. Semantic name remains unreviewed. */

void FUN_c0152de4(uint param_1)

{
  if ((param_1 == DAT_c0154070) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0152e2c FUN_c0152e2c */

/* Boundary evidence: original MIPS .pdata c0152e2c..c0152ea7. Semantic name remains unreviewed. */

void FUN_c0152e2c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c0152d64(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c0152ea8 FUN_c0152ea8 */

/* Boundary evidence: original MIPS .pdata c0152ea8..c0152fc7. Semantic name remains unreviewed. */

void FUN_c0152ea8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c0154094 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c015409c;
    if (DAT_c015409c != (undefined4 *)0x0) {
      while (DAT_c0154098 = DAT_c0154098 + -1, _Memory <= DAT_c0154098) {
        if ((code *)*DAT_c0154098 != (code *)0x0) {
          (*(code *)*DAT_c0154098)();
          _Memory = DAT_c015409c;
        }
      }
      free(_Memory);
      DAT_c0154098 = (undefined4 *)0x0;
      DAT_c015409c = (undefined4 *)0x0;
    }
    FUN_c0152fec((undefined4 *)&DAT_c0151010,(undefined4 *)&DAT_c0151014);
  }
  FUN_c0152fec((undefined4 *)&DAT_c0151018,(undefined4 *)&DAT_c015101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c01540a0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0152fc8 FUN_c0152fc8 */

/* Boundary evidence: original MIPS .pdata c0152fc8..c0152feb. Semantic name remains unreviewed. */

void FUN_c0152fc8(void)

{
  FUN_c0152ea8(0,0,1);
  return;
}



/* c0152fec FUN_c0152fec */

/* Boundary evidence: original MIPS .pdata c0152fec..c015303f. Semantic name remains unreviewed. */

void FUN_c0152fec(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0153040 FUN_c0153040 */

/* Boundary evidence: original MIPS .pdata c0153040..c015307b. Semantic name remains unreviewed. */

void FUN_c0153040(void)

{
  FUN_c0152fec((undefined4 *)&DAT_c0151008,(undefined4 *)&DAT_c015100c);
  FUN_c0152fec((undefined4 *)&DAT_c0151000,(undefined4 *)&DAT_c0151004);
  return;
}


