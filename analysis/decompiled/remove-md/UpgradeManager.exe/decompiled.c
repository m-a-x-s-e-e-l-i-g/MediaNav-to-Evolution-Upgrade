/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..00011043. Semantic name remains unreviewed. */

undefined4 * FUN_00011000(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002ecb8;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00011044 FUN_00011044 */

/* Boundary evidence: original MIPS .pdata 00011044..0001122f. Semantic name remains unreviewed. */

undefined4 FUN_00011044(int param_1)

{
  HANDLE hHandle;
  DWORD DVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined1 auStack_fc [4];
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [192];
  uint local_30;
  
  local_30 = DAT_000372d4;
  local_110 = 0x14;
  local_10c = 1;
  local_108 = 0;
  local_104 = 0xc0;
  local_100 = 1;
  hHandle = (HANDLE)CreateMsgQueue(0,&local_110);
  if (hHandle == (HANDLE)0x0) {
    DVar1 = GetLastError();
    NKDbgPrintfW(L"ERROR(%d): Can\'t Create Msg Q.\n",DVar1);
  }
  else {
    iVar2 = RequestDeviceNotifications(&DAT_0002eaa0,hHandle,1);
    if (iVar2 != 0) {
      *(HANDLE *)(param_1 + 8) = hHandle;
      if (*(int *)(param_1 + 0x10) == 0) {
        do {
          DVar1 = WaitForSingleObject(hHandle,0xffffffff);
          if (DVar1 == 0) {
            iVar3 = ReadMsgQueue(hHandle,auStack_f0,0xc0,auStack_fc,1,auStack_f8);
            if (iVar3 == 0) {
              DVar1 = GetLastError();
              pwVar4 = L"ERROR(%d): Fail to Read Q\n";
              goto LAB_000111c8;
            }
            FUN_00011230(param_1,(int)auStack_f0);
          }
          else {
            DVar1 = GetLastError();
            pwVar4 = L"ERROR(%d): Invalid result from \'hBlockQueue\'\n";
LAB_000111c8:
            NKDbgPrintfW(pwVar4,DVar1);
          }
        } while (*(int *)(param_1 + 0x10) == 0);
      }
      StopDeviceNotifications(iVar2);
      CloseMsgQueue(hHandle);
                    /* WARNING: Subroutine does not return */
      *(undefined4 *)(param_1 + 8) = 0;
      ExitThread(0);
    }
    DVar1 = GetLastError();
    NKDbgPrintfW(L"ERROR(%d): Can\'t Request Device Notifications\n",DVar1);
    CloseMsgQueue(hHandle);
  }
  FUN_0002a0c4(local_30);
  return 0;
}



/* 00011230 FUN_00011230 */

/* Boundary evidence: original MIPS .pdata 00011230..00011313. Semantic name remains unreviewed. */

void FUN_00011230(int param_1,int param_2)

{
  int iVar1;
  LPARAM lParam;
  wchar_t *_Str2;
  
  _Str2 = (wchar_t *)(param_2 + 0x1c);
  iVar1 = wcscmp(L"MD",_Str2);
  if (iVar1 == 0) {
    lParam = 0;
  }
  else {
    iVar1 = wcscmp(L"Storage Card",_Str2);
    if (iVar1 == 0) {
      lParam = 3;
    }
    else {
      iVar1 = wcscmp(L"Storage Card2",_Str2);
      if (iVar1 == 0) {
        lParam = 4;
      }
      else {
        iVar1 = wcscmp(L"Storage Card3",_Str2);
        if (iVar1 == 0) {
          lParam = 5;
        }
        else {
          iVar1 = wcscmp(L"Storage Card4",_Str2);
          if (iVar1 != 0) {
            return;
          }
          lParam = 6;
        }
      }
    }
  }
  PostMessageW(*(HWND *)(param_1 + 4),*(UINT *)(param_1 + 0xc),*(WPARAM *)(param_2 + 0x14),lParam);
  return;
}



/* 00011314 FUN_00011314 */

/* Boundary evidence: original MIPS .pdata 00011314..0001133b. Semantic name remains unreviewed. */

void FUN_00011314(undefined4 param_1)

{
  undefined4 local_10 [2];
  
  local_10[0] = param_1;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException(local_10,(ThrowInfo *)&DAT_000362f4);
}



/* 0001133c FUN_0001133c */

/* Boundary evidence: original MIPS .pdata 0001133c..00011447. Semantic name remains unreviewed. */

BOOL FUN_0001133c(LPCWSTR param_1,LPFILETIME param_2,DWORD *param_3)

{
  HANDLE hFile;
  DWORD DVar1;
  DWORD DVar2;
  BOOL BVar3;
  DWORD local_20 [2];
  
  hFile = CreateFileW(param_1,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x20,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    BVar3 = 0;
  }
  else {
    BVar3 = GetFileTime(hFile,(LPFILETIME)0x0,(LPFILETIME)0x0,param_2);
    DVar1 = GetFileSize(hFile,local_20);
    if ((DVar1 == 0xffffffff) && (DVar2 = GetLastError(), DVar2 != 0)) {
      BVar3 = 0;
    }
    else {
      *param_3 = DVar1;
      param_3[1] = local_20[0];
    }
    CloseHandle(hFile);
  }
  return BVar3;
}



/* 00011448 FUN_00011448 */

/* Boundary evidence: original MIPS .pdata 00011448..0001166b. Semantic name remains unreviewed. */

undefined4 * FUN_00011448(void)

{
  int iVar1;
  
  DAT_00038b48 = &PTR_LAB_00034768;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00038b58);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00038b6c);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00038b80);
  DAT_00038b94 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  DAT_00038b98 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_00038b9c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  DAT_00038bac = 0;
  DAT_00038bb0 = 0;
  DAT_00038bb4 = 0;
  DAT_00038bb8 = 0;
  DAT_00038bbc = 0;
  DAT_00038bc0 = 10;
  DAT_00038b4c = 0;
  DAT_00038b54 = 0;
  DAT_00038b50 = 0;
  DAT_00038ba0 = 0;
  DAT_00038ba4 = 0;
  DAT_00038ba8 = 0;
  DAT_00038bc4 = 0;
  EventModify(DAT_00038b9c,3);
  DAT_00038b48 = &PTR_FUN_0002ed08;
  DAT_00038bc8 = &PTR_FUN_0002ed10;
  FUN_0001a844(&DAT_00038bcc);
  iVar1 = (**(code **)(PTR_PTR_000372dc + 0xc))(&PTR_PTR_000372dc);
  DAT_000393d8 = iVar1 + 0x10;
  iVar1 = (**(code **)(PTR_PTR_000372dc + 0xc))(&PTR_PTR_000372dc);
  DAT_000393dc = iVar1 + 0x10;
  iVar1 = (**(code **)(PTR_PTR_000372dc + 0xc))(&PTR_PTR_000372dc);
  DAT_00039438 = iVar1 + 0x10;
  memset(&DAT_000393e8,0,0x48);
  DAT_00039430 = 0;
  DAT_00039434 = 0;
  FUN_000124b0(&DAT_00039438);
  DAT_0003943c = 0;
  DAT_00039440 = 0;
  DAT_00039444 = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00039448);
  DAT_000393e0 = 0;
  DAT_000393e4 = 0;
  DAT_0003945c = 0;
  DAT_00039460 = 0;
  memset(&DAT_000393e8,0,0x48);
  DAT_00039430 = 0;
  DAT_00039434 = 0;
  FUN_000124b0(&DAT_00039438);
  DAT_0003943c = 0;
  DAT_00039440 = 0;
  DAT_00039444 = 0;
  DAT_00039468 = 0;
  DAT_0003946c = 0;
  DAT_00039470 = 0;
  DAT_00039464 = 1;
  DAT_00039474 = 0;
  return &DAT_00038b48;
}



/* 0001166c Unwind@0001166c */

/* Boundary evidence: original MIPS .pdata 0001166c..0001169b. Semantic name remains unreviewed. */

void Unwind_0001166c(void)

{
  undefined4 *in_v0;
  
  FUN_0001ab6c((undefined4 *)*in_v0);
  return;
}



/* 0001169c FUN_0001169c */

/* Boundary evidence: original MIPS .pdata 0001169c..000116e7. Semantic name remains unreviewed. */

undefined4 * FUN_0001169c(undefined4 *param_1,uint param_2)

{
  FUN_00011730(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000116e8 FUN_000116e8 */

/* Boundary evidence: original MIPS .pdata 000116e8..0001172f. Semantic name remains unreviewed. */

void FUN_000116e8(int param_1)

{
  LONG LVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x50) + -0x10);
  LVar1 = InterlockedDecrement((LONG *)(*(int *)(param_1 + 0x50) + -4));
  if (LVar1 < 1) {
    piVar2 = (int *)*puVar3;
    (**(code **)(*piVar2 + 4))(piVar2,puVar3);
  }
  return;
}



/* 00011730 FUN_00011730 */

/* Boundary evidence: original MIPS .pdata 00011730..00011867. Semantic name remains unreviewed. */

void FUN_00011730(undefined4 *param_1)

{
  DWORD DVar1;
  LONG LVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  *param_1 = &PTR_FUN_0002ed08;
  param_1[0x20] = &PTR_FUN_0002ed10;
  if (((HANDLE)param_1[1] != (HANDLE)0x0) &&
     (DVar1 = WaitForSingleObject((HANDLE)param_1[1],0), DVar1 == 0x102)) {
    FUN_0001225c((int)param_1);
  }
  if ((void *)param_1[0x24b] != (void *)0x0) {
    free((void *)param_1[0x24b]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x240));
  puVar4 = (undefined4 *)(param_1[0x23c] + -0x10);
  LVar2 = InterlockedDecrement((LONG *)(param_1[0x23c] + -4));
  if (LVar2 < 1) {
    piVar3 = (int *)*puVar4;
    (**(code **)(*piVar3 + 4))(piVar3,puVar4);
  }
  puVar4 = (undefined4 *)(param_1[0x225] + -0x10);
  LVar2 = InterlockedDecrement((LONG *)(param_1[0x225] + -4));
  if (LVar2 < 1) {
    piVar3 = (int *)*puVar4;
    (**(code **)(*piVar3 + 4))(piVar3,puVar4);
  }
  puVar4 = (undefined4 *)(param_1[0x224] + -0x10);
  LVar2 = InterlockedDecrement((LONG *)(param_1[0x224] + -4));
  if (LVar2 < 1) {
    piVar3 = (int *)*puVar4;
    (**(code **)(*piVar3 + 4))(piVar3,puVar4);
  }
  FUN_0001a970((int)(param_1 + 0x21));
  FUN_0001ab6c(param_1);
  return;
}



/* 00011868 Unwind@00011868 */

/* Boundary evidence: original MIPS .pdata 00011868..00011897. Semantic name remains unreviewed. */

void Unwind_00011868(void)

{
  undefined4 *in_v0;
  
  FUN_0001ab6c((undefined4 *)*in_v0);
  return;
}



/* 00011898 FUN_00011898 */

/* Boundary evidence: original MIPS .pdata 00011898..00011a3b. Semantic name remains unreviewed. */

int FUN_00011898(undefined4 param_1,LPCWSTR param_2,void *param_3)

{
  DWORD DVar1;
  HANDLE hObject;
  size_t sVar2;
  int iVar3;
  uint local_20 [2];
  
  if ((DAT_00038b4c == (HANDLE)0x0) || (DVar1 = WaitForSingleObject(DAT_00038b4c,0), DVar1 != 0x102)
     ) {
    memset(&DAT_000393e8,0,0x48);
    DAT_00039430 = 0;
    DAT_00039434 = 0;
    FUN_000124b0(&DAT_00039438);
    DAT_0003943c = 0;
    DAT_00039440 = 0;
    DAT_00039444 = 0;
    (**(code **)(*DAT_000393c4 + 0xc))();
    hObject = CreateFileW(param_2,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
    if (hObject == (HANDLE)0xffffffff) {
      GetLastError();
      iVar3 = 1;
    }
    else {
      CloseHandle(hObject);
      local_20[0] = 0;
      NKDbgPrintfW(L"[Upd Manager] [INFO]GetfileCRC (%s)\r\n",param_2);
      iVar3 = FUN_00011c4c(0x38b48,param_2,local_20,0x400);
      if (iVar3 == 0) {
        iVar3 = 0xd;
      }
      else {
        iVar3 = FUN_0001aa10((int *)&DAT_00038bcc,param_2);
        if (iVar3 == 0) {
          memcpy(param_3,&DAT_00038bcc,0x7f8);
        }
        if (param_2 == (LPCWSTR)0x0) {
          sVar2 = 0;
        }
        else {
          sVar2 = wcslen(param_2);
        }
        FUN_00012678(&DAT_000393d8,param_2,sVar2);
      }
    }
  }
  else {
    iVar3 = 10;
  }
  return iVar3;
}



/* 00011a3c FUN_00011a3c */

/* Boundary evidence: original MIPS .pdata 00011a3c..00011b7f. Semantic name remains unreviewed. */

undefined4 FUN_00011a3c(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  
  *(undefined4 *)(param_1 + 0x89c) = 0;
  piVar2 = *(int **)(param_1 + 0x87c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x4c))(piVar2,param_1 + 0x80);
  }
  iVar1 = *(int *)(param_1 + 0x894);
  piVar2 = *(int **)(param_1 + 0x87c);
  if (*(int *)(iVar1 + -0xc) == 0) {
    iVar3 = *piVar2;
    iVar1 = 0;
    if (*(int *)(param_1 + 0x920) == 0) goto LAB_00011b18;
    pcVar4 = *(code **)(iVar3 + 0x28);
  }
  else {
    if (*(int *)(param_1 + 0x920) != 0) {
      iVar1 = (**(code **)(*piVar2 + 0x28))();
      goto LAB_00011adc;
    }
    iVar3 = *piVar2;
LAB_00011b18:
    pcVar4 = *(code **)(iVar3 + 0x44);
  }
  iVar1 = (*pcVar4)(piVar2,iVar1);
LAB_00011adc:
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x87c) + 0x50))();
    if (iVar1 == 0x17) {
      uVar5 = 9;
    }
    else {
      uVar5 = 7;
    }
  }
  else {
    uVar5 = 0;
  }
  *(undefined4 *)(param_1 + 0x898) = uVar5;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x900));
  uVar5 = (**(code **)(**(int **)(param_1 + 0x87c) + 0x50))();
  *(undefined4 *)(param_1 + 0x8ec) = uVar5;
  if (*(int *)(param_1 + 0x928) != 0) {
    *(int *)(param_1 + 0x8ec) = *(int *)(param_1 + 0x928);
  }
  *(undefined4 *)(param_1 + 0x8e8) = 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x900));
  return 0;
}



/* 00011b80 FUN_00011b80 */

/* Boundary evidence: original MIPS .pdata 00011b80..00011c4b. Semantic name remains unreviewed. */

void FUN_00011b80(int param_1)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  if (*(int *)(param_1 + 0x914) + 100U <= DVar1) {
    DVar1 = GetTickCount();
    *(DWORD *)(param_1 + 0x914) = DVar1;
    DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x4c),0);
    if (DVar1 != 0x102) {
      EventModify(*(undefined4 *)(param_1 + 0x54),2);
      if (*(int *)(param_1 + 0x58) == 1) {
        *(undefined4 *)(param_1 + 0x7c) = 0;
        EventModify(*(undefined4 *)(param_1 + 0x4c),2);
        EventModify(*(undefined4 *)(param_1 + 0x50),3);
        EventModify(*(undefined4 *)(param_1 + 0x54),3);
        *(undefined4 *)(param_1 + 0x89c) = 1;
      }
    }
  }
  return;
}



/* 00011c4c FUN_00011c4c */

/* Boundary evidence: original MIPS .pdata 00011c4c..00011db3. Semantic name remains unreviewed. */

undefined4 FUN_00011c4c(int param_1,LPCWSTR param_2,uint *param_3,LONG param_4)

{
  HANDLE hFile;
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *lpBuffer;
  uint local_28 [2];
  
  uVar3 = 1;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x92c) == 0) {
      pvVar1 = malloc(0x20000);
      *(void **)(param_1 + 0x92c) = pvVar1;
    }
    lpBuffer = *(byte **)(param_1 + 0x92c);
    SetFilePointer(hFile,param_4,(PLONG)0x0,0);
    uVar4 = 0;
    iVar2 = ReadFile(hFile,lpBuffer,0x20000,local_28,(LPOVERLAPPED)0x0);
    while ((iVar2 != 0 && (local_28[0] != 0))) {
      uVar4 = FUN_0001a4fc(uVar4,lpBuffer,local_28[0]);
      iVar2 = ReadFile(hFile,lpBuffer,0x20000,local_28,(LPOVERLAPPED)0x0);
    }
    CloseHandle(hFile);
    *param_3 = uVar4;
  }
  return uVar3;
}



/* 00011db4 FUN_00011db4 */

/* Boundary evidence: original MIPS .pdata 00011db4..00011f8f. Semantic name remains unreviewed. */

void FUN_00011db4(int param_1,int param_2,LPCWSTR param_3,undefined4 *param_4,undefined4 *param_5)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  size_t sVar4;
  wchar_t *_Str;
  longlong lVar5;
  DWORD local_28;
  int local_24;
  _FILETIME local_20;
  
  FUN_00011b80(param_1 + -0x80);
  if (*(int *)(param_1 + 0x81c) != 0) {
    *param_5 = 1;
    return;
  }
  if ((*(int *)(param_1 + 0x898) != 0) &&
     (*(int *)(param_2 + 0x18) != 0 || *(int *)(param_2 + 0x1c) != 0)) {
    if (*(int *)(param_1 + 0x89c) == 0) {
      BVar1 = FUN_0001133c(param_3,&local_20,&local_28);
      if (((BVar1 == 0) || (local_28 != *(DWORD *)(param_2 + 0x18))) ||
         ((local_24 != *(int *)(param_2 + 0x1c) ||
          (lVar5 = __ll_div(local_20.dwLowDateTime + 0x2ac18000,
                            (local_20.dwHighDateTime + 0xfe624e22) -
                            (uint)(local_20.dwLowDateTime < 0xd53e8000),10000000,0),
          lVar5 != *(longlong *)(param_2 + 8))))) goto LAB_00011f18;
    }
    else {
      DVar2 = GetFileAttributesW(param_3);
      if ((((DVar2 == 0xffffffff) || ((DVar2 & 0x10) != 0)) ||
          (iVar3 = FUN_00011c4c(param_1 + -0x80,param_3,&local_28,0), iVar3 == 0)) ||
         (local_28 != *(DWORD *)(param_2 + 0x28))) goto LAB_00011f18;
    }
    *param_4 = 1;
  }
LAB_00011f18:
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x880));
  _Str = *(wchar_t **)(param_2 + 4);
  if (_Str == (wchar_t *)0x0) {
    sVar4 = 0;
  }
  else {
    sVar4 = wcslen(_Str);
  }
  FUN_00012678((int *)(param_1 + 0x870),_Str,sVar4);
  *(undefined4 *)(param_1 + 0x874) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_1 + 0x878) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x87c) = *(undefined4 *)(param_2 + 0x1c);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x880));
  return;
}



/* 00011f90 FUN_00011f90 */

/* Boundary evidence: original MIPS .pdata 00011f90..0001200f. Semantic name remains unreviewed. */

void FUN_00011f90(int param_1,void *param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_00011b80(param_1 + -0x80);
  if (*(int *)(param_1 + 0x81c) != 0) {
    *param_4 = 1;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x880));
  if (param_2 != (void *)0x0) {
    memcpy((void *)(param_1 + 0x820),param_2,0x48);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x880));
  return;
}



/* 00012010 FUN_00012010 */

/* Boundary evidence: original MIPS .pdata 00012010..00012143. Semantic name remains unreviewed. */

void FUN_00012010(int param_1,void *param_2,int param_3)

{
  int iVar1;
  LONG LVar2;
  int *piVar3;
  LPCWSTR local_20;
  uint local_1c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x880));
  if (param_2 != (void *)0x0) {
    memcpy((void *)(param_1 + 0x820),param_2,0x48);
  }
  if (((param_3 == 0) && (*(int *)(param_1 + 0x8a4) != 0)) &&
     (*(int *)(param_1 + 0x878) != 0 || *(int *)(param_1 + 0x87c) != 0)) {
    FUN_0001236c((int *)&local_20,(int *)(param_1 + 0x814),(undefined4 *)(param_1 + 0x870));
    local_1c = 0;
    iVar1 = FUN_00011c4c(param_1 + -0x80,local_20,&local_1c,0);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x8a8) = 0x400;
      *(undefined4 *)(param_1 + 0x81c) = 1;
    }
    else if (local_1c != *(uint *)(param_1 + 0x874)) {
      *(undefined4 *)(param_1 + 0x8a8) = 0x401;
      *(undefined4 *)(param_1 + 0x81c) = 1;
      DeleteFileW(local_20);
    }
    LVar2 = InterlockedDecrement((LONG *)(local_20 + -2));
    if (LVar2 < 1) {
      piVar3 = *(int **)(local_20 + -8);
      (**(code **)(*piVar3 + 4))(piVar3,local_20 + -8);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x880));
  return;
}



/* 00012144 FUN_00012144 */

/* Boundary evidence: original MIPS .pdata 00012144..0001225b. Semantic name remains unreviewed. */

void * FUN_00012144(void *param_1,void *param_2)

{
  undefined4 *puVar1;
  LONG LVar2;
  int *piVar3;
  void *pvVar4;
  int *piVar5;
  LONG *lpAddend;
  int *piVar6;
  
  memcpy(param_1,param_2,0x48);
  piVar6 = (int *)((int)param_1 + 0x50);
  *(undefined4 *)((int)param_1 + 0x48) = *(undefined4 *)((int)param_2 + 0x48);
  *(undefined4 *)((int)param_1 + 0x4c) = *(undefined4 *)((int)param_2 + 0x4c);
  pvVar4 = *(void **)((int)param_2 + 0x50);
  piVar3 = (int *)((int)pvVar4 + -0x10);
  piVar5 = (int *)(*piVar6 + -0x10);
  if (piVar3 != piVar5) {
    lpAddend = (LONG *)(*piVar6 + -4);
    if ((*lpAddend < 0) || (*piVar3 != *piVar5)) {
      FUN_00012678(piVar6,pvVar4,*(int *)((int)pvVar4 + -0xc));
    }
    else {
      puVar1 = FUN_0001279c(piVar3);
      LVar2 = InterlockedDecrement(lpAddend);
      if (LVar2 < 1) {
        (**(code **)(*(int *)*piVar5 + 4))((int *)*piVar5,piVar5);
      }
      *piVar6 = (int)(puVar1 + 4);
    }
  }
  *(undefined4 *)((int)param_1 + 0x54) = *(undefined4 *)((int)param_2 + 0x54);
  *(undefined4 *)((int)param_1 + 0x58) = *(undefined4 *)((int)param_2 + 0x58);
  *(undefined4 *)((int)param_1 + 0x5c) = *(undefined4 *)((int)param_2 + 0x5c);
  return param_1;
}



/* 0001225c FUN_0001225c */

/* Boundary evidence: original MIPS .pdata 0001225c..00012317. Semantic name remains unreviewed. */

void FUN_0001225c(int param_1)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
  pvVar2 = *(HANDLE *)(param_1 + 4);
  if ((pvVar2 != (HANDLE)0x0) && (DVar1 = WaitForSingleObject(pvVar2,0), DVar1 == 0x102)) {
    FUN_0001aca8(param_1);
    pvVar2 = (HANDLE)InterlockedExchange((LONG *)(param_1 + 4),0);
    if (pvVar2 != (HANDLE)0x0) {
      WaitForSingleObject(pvVar2,0xffffffff);
      CloseHandle(pvVar2);
    }
  }
  return;
}



/* 00012324 FUN_00012324 */

/* Boundary evidence: original MIPS .pdata 00012324..0001236b. Semantic name remains unreviewed. */

void FUN_00012324(int *param_1)

{
  LONG LVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(*param_1 + -0x10);
  LVar1 = InterlockedDecrement((LONG *)(*param_1 + -4));
  if (LVar1 < 1) {
    piVar2 = (int *)*puVar3;
    (**(code **)(*piVar2 + 4))(piVar2,puVar3);
  }
  return;
}



/* 0001236c FUN_0001236c */

/* Boundary evidence: original MIPS .pdata 0001236c..0001245f. Semantic name remains unreviewed. */

int * FUN_0001236c(int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  
  if (*(int **)(*param_2 + -0x10) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(*param_2 + -0x10) + 0x10))();
  }
  if ((piVar1 == (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(PTR_PTR_000372dc + 0x10))(&PTR_PTR_000372dc),
     piVar1 == (int *)0x0)) {
    piVar1 = (int *)FUN_00011314(0x80004005);
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1);
  *param_1 = iVar2 + 0x10;
  FUN_00012578(param_1,(void *)*param_2,*(int *)(*param_2 + -0xc),(void *)*param_3,
               *(int *)((int)*param_3 + -0xc));
  return param_1;
}



/* 00012460 Unwind@00012460 */

/* Boundary evidence: original MIPS .pdata 00012460..000124af. Semantic name remains unreviewed. */

void Unwind_00012460(void)

{
  undefined4 *in_v0;
  
  if ((in_v0[-8] & 1) != 0) {
    in_v0[-8] = in_v0[-8] & 0xfffffffe;
    FUN_00012324((int *)*in_v0);
  }
  return;
}



/* 000124b0 FUN_000124b0 */

/* Boundary evidence: original MIPS .pdata 000124b0..00012577. Semantic name remains unreviewed. */

void FUN_000124b0(int *param_1)

{
  LONG LVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar2 = *param_1;
  puVar3 = (undefined4 *)(iVar2 + -0x10);
  piVar4 = (int *)*puVar3;
  if (*(int *)(iVar2 + -0xc) != 0) {
    if (*(LONG *)(iVar2 + -4) < 0) {
      if (*(int *)(iVar2 + -8) < 0) {
        FUN_00011314(0x80070057);
      }
      *(undefined4 *)(iVar2 + -0xc) = 0;
      *(undefined2 *)*param_1 = 0;
    }
    else {
      LVar1 = InterlockedDecrement((LONG *)(iVar2 + -4));
      if (LVar1 < 1) {
        (**(code **)(*(int *)*puVar3 + 4))((int *)*puVar3,puVar3);
      }
      iVar2 = (**(code **)(*piVar4 + 0xc))(piVar4);
      *param_1 = iVar2 + 0x10;
    }
  }
  return;
}



/* 00012578 FUN_00012578 */

/* Boundary evidence: original MIPS .pdata 00012578..00012677. Semantic name remains unreviewed. */

void FUN_00012578(int *param_1,void *param_2,int param_3,void *param_4,int param_5)

{
  rsize_t _DstSize;
  void *_Dst;
  int iVar1;
  
  iVar1 = param_3 + param_5;
  if ((int)(1U - *(int *)(*param_1 + -4) | *(int *)(*param_1 + -8) - iVar1) < 0) {
    FUN_00012888(param_1,iVar1);
  }
  _Dst = (void *)*param_1;
  _DstSize = param_3 * 2;
  memcpy_s(_Dst,_DstSize,param_2,_DstSize);
  memcpy_s((void *)(_DstSize + (int)_Dst),param_5 << 1,param_4,param_5 << 1);
  if ((iVar1 < 0) || (*(int *)(*param_1 + -8) < iVar1)) {
    FUN_00011314(0x80070057);
  }
  else {
    *(int *)(*param_1 + -0xc) = iVar1;
    *(undefined2 *)(iVar1 * 2 + *param_1) = 0;
  }
  return;
}



/* 00012678 FUN_00012678 */

/* Boundary evidence: original MIPS .pdata 00012678..0001279b. Semantic name remains unreviewed. */

void FUN_00012678(int *param_1,void *param_2,int param_3)

{
  void *_Dst;
  int iVar1;
  uint uVar2;
  rsize_t _MaxCount;
  uint uVar3;
  
  if (param_3 == 0) {
    FUN_000124b0(param_1);
  }
  else {
    if (param_2 == (void *)0x0) {
      FUN_00011314(0x80070057);
    }
    iVar1 = *param_1;
    uVar3 = (int)param_2 - iVar1 >> 1;
    uVar2 = *(uint *)(iVar1 + -0xc);
    if ((int)(1U - *(int *)(iVar1 + -4) | *(int *)(iVar1 + -8) - param_3) < 0) {
      FUN_00012888(param_1,param_3);
    }
    _MaxCount = param_3 * 2;
    _Dst = (void *)*param_1;
    if (uVar2 < uVar3) {
      memcpy_s(_Dst,*(int *)((int)_Dst + -8) << 1,param_2,_MaxCount);
    }
    else {
      memmove_s(_Dst,*(int *)((int)_Dst + -8) << 1,(void *)(uVar3 * 2 + (int)_Dst),_MaxCount);
    }
    if ((param_3 < 0) || (*(int *)(*param_1 + -8) < param_3)) {
      FUN_00011314(0x80070057);
    }
    else {
      *(int *)(*param_1 + -0xc) = param_3;
      *(undefined2 *)(_MaxCount + *param_1) = 0;
    }
  }
  return;
}



/* 0001279c FUN_0001279c */

/* Boundary evidence: original MIPS .pdata 0001279c..00012867. Semantic name remains unreviewed. */

undefined4 * FUN_0001279c(undefined4 *param_1)

{
  undefined4 *puVar1;
  rsize_t _DstSize;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)*param_1 + 0x10))();
  if (((int)param_1[3] < 0) || (puVar1 != (undefined4 *)*param_1)) {
    puVar1 = (undefined4 *)(**(code **)*puVar1)(puVar1,param_1[1],2);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_00012868();
    }
    puVar1[1] = param_1[1];
    _DstSize = (param_1[1] + 1) * 2;
    memcpy_s(puVar1 + 4,_DstSize,param_1 + 4,_DstSize);
  }
  else {
    InterlockedIncrement(param_1 + 3);
    puVar1 = param_1;
  }
  return puVar1;
}



/* 00012868 FUN_00012868 */

/* Boundary evidence: original MIPS .pdata 00012868..00012887. Semantic name remains unreviewed. */

void FUN_00012868(void)

{
  FUN_00011314(0x8007000e);
  return;
}



/* 00012888 FUN_00012888 */

/* Boundary evidence: original MIPS .pdata 00012888..0001291b. Semantic name remains unreviewed. */

void FUN_00012888(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (param_2 < *(int *)(iVar2 + -0xc)) {
    param_2 = *(int *)(iVar2 + -0xc);
  }
  if (*(int *)(iVar2 + -4) < 2) {
    iVar2 = *(int *)(iVar2 + -8);
    if (iVar2 < param_2) {
      iVar1 = iVar2 + 0x400;
      if (iVar2 < 0x401) {
        iVar1 = iVar2 << 1;
      }
      if (iVar1 < param_2) {
        iVar1 = param_2;
      }
      FUN_00012a00(param_1,iVar1);
    }
  }
  else {
    FUN_0001291c(param_1,param_2);
  }
  return;
}



/* 0001291c FUN_0001291c */

/* Boundary evidence: original MIPS .pdata 0001291c..000129ff. Semantic name remains unreviewed. */

void FUN_0001291c(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  LONG LVar3;
  rsize_t _DstSize;
  void *_Src;
  int iVar4;
  undefined4 *puVar5;
  
  _Src = (void *)*param_1;
  puVar5 = (undefined4 *)((int)_Src + -0x10);
  iVar4 = *(int *)((int)_Src + -0xc);
  puVar1 = (undefined4 *)(**(code **)(*(int *)*puVar5 + 0x10))();
  iVar2 = (**(code **)*puVar1)(puVar1,param_2,2);
  if (iVar2 == 0) {
    FUN_00012868();
  }
  if (iVar4 < param_2) {
    param_2 = iVar4;
  }
  _DstSize = (param_2 + 1) * 2;
  memcpy_s((void *)(iVar2 + 0x10),_DstSize,_Src,_DstSize);
  *(int *)(iVar2 + 4) = iVar4;
  LVar3 = InterlockedDecrement((LONG *)((int)_Src + -4));
  if (LVar3 < 1) {
    (**(code **)(*(int *)*puVar5 + 4))((int *)*puVar5,puVar5);
  }
  *param_1 = (void *)(iVar2 + 0x10);
  return;
}



/* 00012a00 FUN_00012a00 */

/* Boundary evidence: original MIPS .pdata 00012a00..00012a7b. Semantic name remains unreviewed. */

void FUN_00012a00(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(*param_1 + -0x10);
  piVar2 = (int *)*puVar3;
  if ((*(int *)(*param_1 + -8) < param_2) && (0 < param_2)) {
    iVar1 = (**(code **)(*piVar2 + 8))(piVar2,puVar3,param_2,2);
    if (iVar1 == 0) {
      iVar1 = FUN_00012868();
    }
    *param_1 = iVar1 + 0x10;
  }
  else {
    FUN_00012868();
  }
  return;
}



/* 00012a7c FUN_00012a7c */

/* Boundary evidence: original MIPS .pdata 00012a7c..00012b4b. Semantic name remains unreviewed. */

PHKEY FUN_00012a7c(PHKEY param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  HKEY local_20;
  DWORD DStack_1c;
  
  *param_1 = (HKEY)0x0;
  if (param_2 != (LPCWSTR)0x0) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,param_2,0,0x2001f,param_1);
    if (LVar1 != 0) {
      LVar1 = RegCreateKeyExW((HKEY)0x80000002,param_2,0,(LPWSTR)0x0,0,0x2001f,
                              (LPSECURITY_ATTRIBUTES)0x0,&local_20,&DStack_1c);
      if (LVar1 == 0) {
        *param_1 = local_20;
      }
      else {
        *param_1 = (HKEY)0x0;
      }
    }
  }
  return param_1;
}



/* 00012b4c FUN_00012b4c */

/* Boundary evidence: original MIPS .pdata 00012b4c..00012c57. Semantic name remains unreviewed. */

undefined4 FUN_00012b4c(void *param_1)

{
  HWND hWnd;
  HANDLE local_20;
  HANDLE local_1c;
  
  memcpy(&local_20,param_1,0x10);
  WaitForSingleObject(local_20,0xffffffff);
  NKDbgPrintfW(L"[Upd Manager]SyncTool.exe is terminated\r\n");
  if ((DAT_00038ae0 == 0) && (DAT_00038b00 == 1)) {
    hWnd = FindWindowW(L"MGRMCM",(LPCWSTR)0x0);
    if (hWnd != (HWND)0x0) {
      PostMessageW(hWnd,0x8064,0xb90300,0);
    }
    NKDbgPrintfW(L"[UPG]          PostMSG    [1]    !@#+_!+@)$+)!@+$)  \r\n");
    DAT_00038b00 = 0;
  }
  CloseHandle(local_20);
  CloseHandle(local_1c);
  if (DAT_00038b1c != 0) {
    CloseHandle((HANDLE)DAT_00038b1c);
    DAT_00038b1c = 0;
  }
  return 0;
}



/* 00012c58 FUN_00012c58 */

/* Boundary evidence: original MIPS .pdata 00012c58..00012de3. Semantic name remains unreviewed. */

void FUN_00012c58(void)

{
  DWORD DVar1;
  undefined1 local_30 [8];
  
  DAT_00038b2c = 0;
  do {
    DVar1 = WaitForSingleObject(DAT_00038b20,300000);
    if (DVar1 == 0) {
      DAT_00038b2c = 1;
      break;
    }
    if (DVar1 == 0x102) {
      if (DAT_00037444 != -1) {
        local_30[0] = 0;
        FUN_000165b8(1,1,7,(int)local_30,1);
        NKDbgPrintfW(L"= In Monitor Thread =- COM2 close succeed!!!\r\n");
        if (DAT_00037444 != -1) {
          CloseHandle((HANDLE)DAT_00037444);
          DAT_00037444 = -1;
        }
      }
      DAT_00038b2c = 1;
    }
  } while (DAT_00038b2c == 0);
  DVar1 = GetTickCount();
  NKDbgPrintfW(L"***** [Upd Manager ] Thread_Monitor Ended ~~~ [%d] ****\r\n",DVar1);
  if (DAT_00038b20 != (HANDLE)0x0) {
    CloseHandle(DAT_00038b20);
    DAT_00038b20 = (HANDLE)0x0;
  }
  if (DAT_00038b24 != 0) {
    CloseHandle((HANDLE)DAT_00038b24);
    DAT_00038b24 = 0;
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00012de4 FUN_00012de4 */

/* Boundary evidence: original MIPS .pdata 00012de4..00012fef. Semantic name remains unreviewed. */

void FUN_00012de4(undefined4 *param_1)

{
  int iVar1;
  BOOL BVar2;
  HANDLE hObject;
  DWORD DVar3;
  UINT_PTR nIDEvent;
  UINT uElapse;
  HWND hWnd;
  _PROCESS_INFORMATION _Stack_20;
  
  hWnd = (HWND)*param_1;
  iVar1 = FUN_000167f4(1);
  if (iVar1 == 1) {
    NKDbgPrintfW(L"***** [Upd Manager ] DELAY 1500 ****\r\n");
  }
  iVar1 = FUN_000167f4(2);
  if (iVar1 == 1) {
    NKDbgPrintfW(L"***** [Upd Manager ] Storage Card3 Mount error ~~~ ****\r\n");
  }
  DAT_00038b20 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_00038b24 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00012c58,(LPVOID)0x0,4,(LPDWORD)0x0);
  if (DAT_00038b24 != (HANDLE)0x0) {
    CeSetThreadPriority(DAT_00038b24,0x58);
    ResumeThread(DAT_00038b24);
  }
  FUN_00014974();
  if (DAT_00038b20 != (HANDLE)0x0) {
    EventModify(DAT_00038b20,3);
  }
  memset(&_Stack_20,0,0x10);
  BVar2 = CreateProcessW(L"\\Storage Card\\system\\MicomManager.exe",
                         L"$er10q4c$=4G2g1.5_-H2tq9X@mid",(LPSECURITY_ATTRIBUTES)0x0,
                         (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0
                         ,&_Stack_20);
  if (BVar2 == 0) {
    NKDbgPrintfW(L"[Upd Manager] FAIL!!! RunProgram(MICOM_MANAGER)\r\n");
    uElapse = 1000;
    nIDEvent = 1000;
  }
  else {
    SetTimer(hWnd,2,5000,(TIMERPROC)0x0);
    uElapse = 500;
    nIDEvent = 0x3ea;
  }
  SetTimer(hWnd,nIDEvent,uElapse,(TIMERPROC)0x0);
  DAT_00037578 = 0x7e8;
  DAT_00037570 = hWnd;
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00011044,&PTR_PTR_0003756c,0,(LPDWORD)0x0)
  ;
  if (hObject == (HANDLE)0x0) {
    DVar3 = GetLastError();
    NKDbgPrintfW(L"ERROR(%d): Can\'t create ThreadProcDevNotify\n",DVar3);
  }
  else {
    CloseHandle(hObject);
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00012ff0 FUN_00012ff0 */

/* Boundary evidence: original MIPS .pdata 00012ff0..0001336f. Semantic name remains unreviewed. */

undefined4 FUN_00012ff0(void)

{
  PHKEY ppHVar1;
  LSTATUS LVar2;
  DWORD DVar3;
  int iVar4;
  undefined4 uVar5;
  int local_28 [4];
  
  uVar5 = 0xffffffff;
  iVar4 = -1;
  ppHVar1 = (PHKEY)__2_YAPAXI_Z(4);
  if (ppHVar1 == (PHKEY)0x0) {
    ppHVar1 = (PHKEY)0x0;
  }
  else {
    ppHVar1 = FUN_00012a7c(ppHVar1,L"LGE\\SystemInfo");
  }
  if (ppHVar1 != (PHKEY)0x0) {
    if (*ppHVar1 != (HKEY)0x0) {
      local_28[0] = 0;
      local_28[1] = 4;
      LVar2 = RegQueryValueExW(*ppHVar1,L"SKU_REGION",(LPDWORD)0x0,(LPDWORD)(local_28 + 2),
                               (LPBYTE)local_28,(LPDWORD)(local_28 + 1));
      if ((LVar2 == 0) && (local_28[2] == 4)) {
        iVar4 = local_28[0];
      }
      if (*ppHVar1 != (HKEY)0x0) {
        RegCloseKey(*ppHVar1);
      }
    }
    __3_YAXPAX_Z(ppHVar1);
  }
  DVar3 = GetFileAttributesW(L"\\MD\\upgrade_root.lgu");
  if (DVar3 == 0xffffffff) {
    DVar3 = GetFileAttributesW(L"\\MD\\navigation_restore.lgu");
    if (DVar3 == 0xffffffff) {
      DVar3 = GetFileAttributesW(L"\\MD\\navigation_restore_fat32.lgu");
      if (DVar3 == 0xffffffff) {
        DVar3 = GetFileAttributesW(L"\\MD\\navigation_restore_tfat.lgu");
        if (DVar3 == 0xffffffff) {
          if ((((((iVar4 == 0) || (iVar4 == 3)) || (iVar4 == 6)) || ((iVar4 == 9 || (iVar4 == 0xc)))
               ) || (iVar4 == 0xf)) ||
             (((iVar4 == 0x12 || (iVar4 == 0x15)) || ((iVar4 == 0x18 || (iVar4 == 0x1b)))))) {
            DVar3 = GetFileAttributesW(L"\\MD\\navigation_restore_feu.lgu");
            if (DVar3 != 0xffffffff) {
              return 4;
            }
          }
          else if ((((((iVar4 == 1) || (iVar4 == 4)) || (iVar4 == 7)) ||
                    ((iVar4 == 10 || (iVar4 == 0xd)))) ||
                   (((iVar4 == 0x10 || ((iVar4 == 0x13 || (iVar4 == 0x16)))) || (iVar4 == 0x19))))
                  || (iVar4 == 0x1c)) {
            DVar3 = GetFileAttributesW(L"\\MD\\navigation_restore_amr.lgu");
            if (DVar3 != 0xffffffff) {
              return 5;
            }
          }
          else {
            if (((((iVar4 != 2) && (iVar4 != 5)) && (iVar4 != 8)) &&
                (((iVar4 != 0xb && (iVar4 != 0xe)) &&
                 ((iVar4 != 0x11 && ((iVar4 != 0x14 && (iVar4 != 0x17)))))))) &&
               ((iVar4 != 0x1a && ((iVar4 != 0x1d && (iVar4 != 0x1e)))))) {
              return 0xffffffff;
            }
            DVar3 = GetFileAttributesW(L"\\MD\\navigation_restore_oth.lgu");
            if (DVar3 != 0xffffffff) {
              return 6;
            }
          }
          NKDbgPrintfW(L"[xxxxxxx] dwSkuRegion %d....Not detected!!!\r\n",iVar4);
        }
        else {
          uVar5 = 3;
        }
      }
      else {
        uVar5 = 2;
      }
    }
    else {
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



/* 00013370 FUN_00013370 */

/* Boundary evidence: original MIPS .pdata 00013370..000134e7. Semantic name remains unreviewed. */

undefined4 FUN_00013370(void)

{
  DWORD DVar1;
  HANDLE hFile;
  int iVar2;
  undefined4 uVar3;
  DWORD aDStack_820 [2];
  int local_818;
  int local_814;
  int local_810;
  wchar_t awStack_53c [654];
  uint local_20;
  
  local_20 = DAT_000372d4;
  uVar3 = 0;
  NKDbgPrintfW(L"[Upd Manager] IsSpecialFileInUSB()\r\n");
  DVar1 = GetFileAttributesW(L"\\MD\\special_file.ini");
  if (DVar1 != 0xffffffff) {
    hFile = CreateFileW(L"\\MD\\special_file.ini",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                        (HANDLE)0x0);
    if (hFile == (HANDLE)0xffffffff) {
      NKDbgPrintfW(L"[Upd Manager] IsSpecialFileInUSB() File Not found!!! %s\r\n",
                   L"\\MD\\special_file.ini");
    }
    else {
      ReadFile(hFile,&local_818,0x7f8,aDStack_820,(LPOVERLAPPED)0x0);
      if ((((local_818 == 0x3055474c) && (local_814 == 7)) && (local_810 == 0x400)) &&
         (iVar2 = wcscmp(awStack_53c,L"SPECIAL FILE"), iVar2 == 0)) {
        uVar3 = 1;
      }
      NKDbgPrintfW(L"-=-=-=-=- [%d], %s =-=-=-=-\r\n",uVar3,awStack_53c);
      CloseHandle(hFile);
    }
  }
  FUN_0002a0c4(local_20);
  return uVar3;
}



/* 000134e8 FUN_000134e8 */

/* Boundary evidence: original MIPS .pdata 000134e8..00013637. Semantic name remains unreviewed. */

undefined4 FUN_000134e8(void)

{
  HWND hWnd;
  BOOL BVar1;
  DWORD DVar2;
  wchar_t *pwVar3;
  LPARAM local_10 [2];
  
  local_10[0] = 0;
  hWnd = FindWindowW((LPCWSTR)PTR_u_AppMain_000374a4,(LPCWSTR)0x0);
  if (hWnd == (HWND)0x0) {
    NKDbgPrintfW(L"%S IntGetProcessHandle fail, src=%d, dst=%d, cmd=%d","IpcPostMsg",0x11,0x15,0x27e
                );
  }
  else {
    memcpy(local_10,(void *)0x0,0);
    BVar1 = PostMessageW(hWnd,0x8064,0x27e1100,local_10[0]);
    if (BVar1 != 0) {
      return 1;
    }
    DVar2 = GetLastError();
    if (DVar2 == 6) {
      pwVar3 = L"%S invalid handle";
    }
    else if (DVar2 == 0x578) {
      pwVar3 = L"%S invalid window handle";
    }
    else if (DVar2 == 0x583) {
      pwVar3 = L"%S class does not exist";
    }
    else {
      if (DVar2 != 0x5b4) {
        NKDbgPrintfW(L"%S PostMessage fail, src=%d, dst=%d, cmd=%d, errCode=%d","IpcPostMsg",0x11,
                     0x15,0x27e,DVar2);
        return 0;
      }
      pwVar3 = L"%S timed out";
    }
    NKDbgPrintfW(pwVar3,"IpcPostMsg");
  }
  return 0;
}



/* 00013638 FUN_00013638 */

/* Boundary evidence: original MIPS .pdata 00013638..000137bb. Semantic name remains unreviewed. */

undefined4 FUN_00013638(undefined4 param_1,undefined4 param_2,int param_3)

{
  HWND pHVar1;
  int iVar2;
  undefined4 local_18;
  DWORD local_14;
  
  local_14 = 0;
  local_18 = 0;
  pHVar1 = FindWindowW((LPCWSTR)PTR_u_AppMain_000374a4,(LPCWSTR)0x0);
  if (pHVar1 == (HWND)0x0) {
    NKDbgPrintfW(L"%S FindWindow fail, dest=%d, src=%d, dst=%d, cmd=%d","IpcSendMsg",0x15,0x11,0x15,
                 param_3);
  }
  else {
    memcpy(&local_18,(void *)0x0,0);
    iVar2 = SendMessageTimeout(pHVar1,0x8064,param_3 << 0x10 | 0x1100,local_18,0,0x5dc,&local_14);
    if (iVar2 != 0) {
      return 1;
    }
    local_14 = GetLastError();
    if (local_14 == 0) {
      NKDbgPrintfW(L"%S SendMessageTimeout fail, src=%d, dst=%d, cmd=%d, timeout","IpcSendMsg",0x11,
                   0x15,param_3);
    }
    else if (local_14 == 6) {
      NKDbgPrintfW(L"%S SendMessageTimeout fail, src=%d, dst=%d, cmd=%d, invalid handle",
                   "IpcSendMsg",0x11,0x15,param_3);
    }
    else if (local_14 == 0x578) {
      NKDbgPrintfW(L"%S SendMessageTimeout fail, src=%d, dst=%d, cmd=%d, invalid window handle",
                   "IpcSendMsg",0x11,0x15,param_3);
    }
    else {
      NKDbgPrintfW(L"%S SendMessageTimeout fail, src=%d, dst=%d, cmd=%d, errCode=%d","IpcSendMsg",
                   0x11,0x15,param_3,local_14);
    }
  }
  return 0;
}



/* 000137bc FUN_000137bc */

/* Boundary evidence: original MIPS .pdata 000137bc..000138d7. Semantic name remains unreviewed. */

DWORD FUN_000137bc(void)

{
  HANDLE hFile;
  BOOL BVar1;
  wchar_t *pwVar2;
  DWORD DVar3;
  DWORD local_20;
  DWORD local_1c;
  
  DVar3 = 0;
  hFile = CreateFileW(L"\\Storage card2\\pwr_count.bin",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                      0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    BVar1 = ReadFile(hFile,&local_1c,4,&local_20,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      local_1c = GetLastError();
      pwVar2 = L"[%S][%s] file read error [0x%08X]\r\n";
    }
    else if (local_20 == 4) {
      pwVar2 = L"[%S][%s] file read OK : count value [%d] \r\n";
      DVar3 = local_1c;
    }
    else {
      pwVar2 = L"[%S][%s] file read error : wrong file size [%d] \r\n";
      local_1c = local_20;
    }
    NKDbgPrintfW(pwVar2,"GetOnOffCount",L"\\Storage card2\\pwr_count.bin",local_1c);
    CloseHandle(hFile);
  }
  return DVar3;
}



/* 000138d8 FUN_000138d8 */

/* Boundary evidence: original MIPS .pdata 000138d8..000139f3. Semantic name remains unreviewed. */

WPARAM FUN_000138d8(HINSTANCE param_1)

{
  ATOM AVar1;
  undefined2 extraout_var;
  HWND hWnd;
  BOOL BVar2;
  MSG MStack_58;
  WNDCLASSW local_38;
  
  local_38.style = 3;
  local_38.lpfnWndProc = FUN_000139f4;
  local_38.cbClsExtra = 0;
  local_38.cbWndExtra = 0;
  local_38.hIcon = (HICON)0x0;
  local_38.hCursor = (HCURSOR)0x0;
  DAT_000386c4 = param_1;
  local_38.hInstance = param_1;
  local_38.hbrBackground = GetStockObject(5);
  local_38.lpszMenuName = (LPCWSTR)0x0;
  local_38.lpszClassName = L"UPGRADEMANAGER";
  AVar1 = RegisterClassW(&local_38);
  if ((CONCAT22(extraout_var,AVar1) == 0) ||
     (hWnd = CreateWindowExW(0,L"UPGRADEMANAGER",L"UpgradeManager",0x80000000,-0x80000000,
                             -0x80000000,-0x80000000,-0x80000000,(HWND)0x0,(HMENU)0x0,param_1,
                             (LPVOID)0x0), hWnd == (HWND)0x0)) {
    MStack_58.wParam = 0;
  }
  else {
    ShowWindow(hWnd,0);
    UpdateWindow(hWnd);
    while (BVar2 = GetMessageW(&MStack_58,(HWND)0x0,0,0), BVar2 != 0) {
      TranslateMessage(&MStack_58);
      DispatchMessageW(&MStack_58);
    }
  }
  return MStack_58.wParam;
}



/* 000139f4 FUN_000139f4 */

/* Boundary evidence: original MIPS .pdata 000139f4..0001473b. Semantic name remains unreviewed. */

LRESULT FUN_000139f4(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  bool bVar1;
  BOOL BVar2;
  DWORD DVar3;
  HWND pHVar4;
  int iVar5;
  HDC pHVar6;
  HANDLE hFile;
  LSTATUS LVar7;
  size_t sVar8;
  undefined3 extraout_var;
  LRESULT LVar9;
  PHKEY ppHVar10;
  wchar_t *pwVar11;
  UINT_PTR uIDEvent;
  uint uVar12;
  byte local_190 [4];
  HKEY local_18c;
  HKEY local_188;
  int local_184;
  int local_180 [5];
  FILE *local_16c;
  DWORD aDStack_168 [2];
  _PROCESS_INFORMATION _Stack_160;
  _PROCESS_INFORMATION _Stack_150;
  undefined1 auStack_140 [80];
  int local_f0;
  tagPAINTSTRUCT tStack_e8;
  char acStack_a8 [16];
  undefined1 local_98;
  char acStack_90 [32];
  WCHAR aWStack_70 [32];
  uint local_30;
  
  local_30 = DAT_000372d4;
  uVar12 = DAT_00038adc;
  if (0x201 < param_2) {
    if (param_2 == 0x202) {
      FUN_00015f10(param_4 & 0xffff,param_4 >> 0x10);
      uVar12 = DAT_00038adc;
      goto LAB_00014700;
    }
    if (param_2 == 0x620) {
      iVar5 = 0;
      pHVar4 = FindWindowW(L"CodeChecker",L"CodeChecker");
      ppHVar10 = (PHKEY)__2_YAPAXI_Z(4);
      if (ppHVar10 == (PHKEY)0x0) {
        ppHVar10 = (PHKEY)0x0;
      }
      else {
        ppHVar10 = FUN_00012a7c(ppHVar10,L"LGE\\SystemStatus\\BTCall");
      }
      if (ppHVar10 != (PHKEY)0x0) {
        if (*ppHVar10 != (HKEY)0x0) {
          local_180[0] = 0;
          local_180[1] = 4;
          LVar7 = RegQueryValueExW(*ppHVar10,L"CallState",(LPDWORD)0x0,(LPDWORD)(local_180 + 4),
                                   (LPBYTE)local_180,(LPDWORD)(local_180 + 1));
          if ((LVar7 == 0) && (local_180[4] == 4)) {
            iVar5 = local_180[0];
          }
          if (*ppHVar10 != (HKEY)0x0) {
            RegCloseKey(*ppHVar10);
          }
        }
        __3_YAXPAX_Z(ppHVar10);
        uVar12 = DAT_00038adc;
        if (iVar5 != 0) goto LAB_00014700;
      }
      uVar12 = DAT_00038adc;
      if ((DAT_00038b0c == 0) && (pHVar4 == (HWND)0x0)) {
        *(undefined4 *)(DAT_00038b04 + 0x628) = 1;
        FUN_00013638(0x11,0x15,0x279);
        if (DAT_00038b10 == 0) {
          SetWindowPos(DAT_00038ae8,(HWND)0xffffffff,0,0,800,0x1e0,0x40);
          InvalidateRect(DAT_00038ae8,(RECT *)0x0,0);
          uVar12 = DAT_00038adc;
        }
        else {
          SetWindowPos(param_1,(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
          SetWindowPos(param_1,(HWND)0x1,0,0,800,0x1e0,0x80);
          DAT_00038b0c = 1;
          uVar12 = DAT_00038adc;
        }
      }
      goto LAB_00014700;
    }
    if (param_2 == 0x7e8) {
      FUN_000154cc(param_3,param_4);
      uVar12 = DAT_00038adc;
      goto LAB_00014700;
    }
    if (param_2 == 0x9e62) goto LAB_00014700;
LAB_00014310:
    if (DAT_00038b34 == param_2) {
      if (0x1c < (int)param_4) {
        param_4 = 2;
      }
      FUN_0001481c(param_4);
      uVar12 = DAT_00038adc;
      goto LAB_00014700;
    }
    if (DAT_00038b38 == param_2) {
      if (param_4 == 1) {
        BVar2 = IsWindowVisible(param_1);
        if (BVar2 != 0) {
          SetWindowPos(param_1,(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
          SetWindowPos(param_1,(HWND)0x1,0,0,800,0x1e0,0x80);
          DAT_00038b0c = 1;
        }
        DAT_00038b10 = 1;
        uVar12 = DAT_00038adc;
      }
      else {
        if (DAT_00038b0c == 0) {
          ShowWindow(param_1,0);
        }
        else {
          DAT_00038b0c = 0;
          SetWindowPos(param_1,(HWND)0xffffffff,0,0,800,0x1e0,0x40);
        }
        DAT_00038b10 = 0;
        uVar12 = DAT_00038adc;
      }
      goto LAB_00014700;
    }
    uVar12 = param_4;
    if (DAT_00038b3c == param_2) goto LAB_00014700;
    if (DAT_00038b40 != param_2) {
      LVar9 = DefWindowProcW(param_1,param_2,param_3,param_4);
      FUN_0002a0c4(local_30);
      return LVar9;
    }
    DVar3 = GetTickCount();
    NKDbgPrintfW(L"[Upd Manager] Storage Card Format Start!! [%d, %d, %d]\r\n",param_3,param_4,DVar3
                );
    if (param_3 == 1) {
      if (DAT_00038b28 == (HANDLE)0x0) {
        DAT_00038b28 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"Storage Card2 Mount Event~~~");
      }
      FUN_00019fbc(1,(uint)(param_4 != 0),(uint)(param_4 != 0));
    }
    DVar3 = GetTickCount();
    pwVar11 = L"[Upd Manager] Storage Card Format End!! [%d]\r\n";
LAB_000144ec:
    NKDbgPrintfW(pwVar11,DVar3);
    uVar12 = DAT_00038adc;
    goto LAB_00014700;
  }
  if (param_2 == 0x201) {
    if ((DAT_0003743c == 3000) &&
       (iVar5 = FUN_00015e7c(param_4 & 0xffff,param_4 >> 0x10), uVar12 = DAT_00038adc, iVar5 != -1))
    {
      DAT_00037448 = iVar5;
      if (iVar5 == 0) {
        FUN_00015abc(1);
        uVar12 = DAT_00038adc;
      }
      else if (iVar5 == 1) {
        FUN_00015be8(1);
        uVar12 = DAT_00038adc;
      }
    }
    goto LAB_00014700;
  }
  if (param_2 == 1) {
    iVar5 = FUN_000163d8(local_190);
    if (iVar5 != 0) {
      uVar12 = (uint)local_190[0];
      if (1 < uVar12) {
        NKDbgPrintfW(L"[UpGradeMGR]        [error] ui = 0x%d\r\n");
        uVar12 = 0;
      }
      DAT_00038ae4 = uVar12;
      NKDbgPrintfW(L"[UpGradeMGR]        ui = 0x%d\r\n");
    }
    FUN_000166b8();
    NKDbgPrintfW(L"[Upd Manager ] start!! [g_bBeforeULC12 %d]\r\n",DAT_00038ae0);
    local_180[3] = 4;
    local_180[2] = 4;
    hFile = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                        0x80,(HANDLE)0x0);
    if (hFile == (HANDLE)0xffffffff) {
      iVar5 = 2;
    }
    else {
      ReadFile(hFile,auStack_140,0x55,aDStack_168,(LPOVERLAPPED)0x0);
      LVar7 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_18c);
      if (LVar7 == 0) {
        LVar7 = RegQueryValueExW(local_18c,L"SYS_LANG_TYPE",(LPDWORD)0x0,(LPDWORD)(local_180 + 3),
                                 (LPBYTE)&local_184,(LPDWORD)(local_180 + 2));
        if (LVar7 == 0) {
          NKDbgPrintfW(L"~~~+_+_+_+_+_+_ [[UPG]] Load Reg ~~~~~~~~ [%d, %d]",local_f0,local_184);
          local_f0 = local_184;
        }
        RegCloseKey(local_18c);
      }
      iVar5 = local_f0;
      if (0x1c < local_f0) {
        iVar5 = 2;
      }
      CloseHandle(hFile);
    }
    FUN_0001481c(iVar5);
    local_98 = 0;
    sprintf_s(acStack_a8,0x10,"4.0.5");
    sprintf_s(acStack_90,0x20,"\\UPG %s.ver",acStack_a8);
    fopen_s(&local_16c,acStack_90,"wt");
    fclose(local_16c);
    LVar7 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_188);
    if (LVar7 == 0) {
      wsprintfW(aWStack_70,L"%S",acStack_a8);
      sVar8 = wcslen(aWStack_70);
      RegSetValueExW(local_188,L"VerUpgradeManager",0,1,(BYTE *)aWStack_70,sVar8 << 1);
      RegCloseKey(local_188);
    }
    DAT_00038ae8 = param_1;
    bVar1 = FUN_0001473c(param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      NKDbgPrintfW(L"[Upd Manager ] WM_CREATE:: Upgrade Init fail!!\r\n");
      uVar12 = DAT_00038adc;
    }
    else {
      DAT_00038b24 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00012de4,&DAT_00038ae8,0,
                                  (LPDWORD)0x0);
      uVar12 = DAT_00038adc;
    }
    goto LAB_00014700;
  }
  if (param_2 == 2) {
    DAT_0003757c = 1;
    if (DAT_00037574 != 0) {
      EventModify(DAT_00037574,3);
    }
    if (DAT_00038b04 != 0) {
      __3_YAXPAX_Z();
      DAT_00038b04 = 0;
    }
    PostQuitMessage(0);
    uVar12 = DAT_00038adc;
    goto LAB_00014700;
  }
  if (param_2 == 8) goto LAB_00014700;
  if (param_2 == 0xf) {
    pHVar6 = BeginPaint(param_1,&tStack_e8);
    if (DAT_00038b04 != 0) {
      if (*(int *)(DAT_00038b04 + 0x628) == 1) {
        FUN_00018540(DAT_00038b04,pHVar6);
      }
      else if (*(int *)(DAT_00038b04 + 0x628) == 2) {
        FUN_00018acc(DAT_00038b04,pHVar6);
      }
    }
    EndPaint(param_1,&tStack_e8);
    uVar12 = DAT_00038adc;
    goto LAB_00014700;
  }
  if (param_2 != 0x113) goto LAB_00014310;
  if (param_3 == 1) {
    uIDEvent = 1;
  }
  else {
    if (param_3 != 2) {
      if (param_3 == 1000) {
        NKDbgPrintfW(L"~!@#$ Upgrade Manager 1600msec delay excute micom manager\r\n");
        memset(&_Stack_160,0,0x10);
        BVar2 = CreateProcessW(L"\\Storage Card\\system\\MicomManager.exe",
                               L"$er10q4c$=4G2g1.5_-H2tq9X@mid",(LPSECURITY_ATTRIBUTES)0x0,
                               (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                               (LPSTARTUPINFOW)0x0,&_Stack_160);
        if (BVar2 == 0) {
          NKDbgPrintfW(L"[Upd Manager] FAIL!!! RunProgram(MICOM_MANAGER)\r\n");
          DVar3 = GetFileAttributesW(L"\\MD\\MicomManager.exe");
          uVar12 = DAT_00038adc;
          if (DVar3 != 0xffffffff) {
            CopyFileW(L"\\MD\\MicomManager.exe",L"\\Storage Card\\system\\MicomManager.exe",0);
            uVar12 = DAT_00038adc;
          }
        }
        else {
          KillTimer(param_1,1000);
          SetTimer(param_1,2,5000,(TIMERPROC)0x0);
          SetTimer(param_1,0x3ea,500,(TIMERPROC)0x0);
          uVar12 = DAT_00038adc;
        }
        goto LAB_00014700;
      }
      if (param_3 != 0x3ea) {
        if (param_3 != 0x3eb) goto LAB_00014700;
        BVar2 = CreateProcessW(L"\\MD\\Special_tool.exe",L"$er10q4c$=4G2g1.5_-H2tq9X@mid",
                               (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0
                               ,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,&_Stack_150);
        if (BVar2 == 0) {
          DVar3 = GetLastError();
          pwVar11 = L"[Upd Manager]SPECIAL_FILE_PATH did not excute!! 0x%x\r\n";
          goto LAB_000144ec;
        }
        NKDbgPrintfW(L"[Upd Manager] CreateProcess Successed!!!!\r\n");
        uIDEvent = 0x3eb;
        goto LAB_00013ee0;
      }
      pHVar4 = FindWindowW(L"CodeChecker",L"CodeChecker");
      uVar12 = DAT_00038adc;
      if (pHVar4 != (HWND)0x0) goto LAB_00014700;
      if (0x28 < DAT_00038b08) {
        DAT_00038b18 = 1;
        KillTimer(param_1,0x3ea);
        if ((DAT_00038b14 & 1) != 0) {
          NKDbgPrintfW(L"====> [0x%08X]   [%s]  [%d]   [Update %d, Acc %d] g_hMountEvent[0x%08x] +_+_\r\n"
                       ,DAT_00038b14,L"Attatch",0,DAT_00038b18,DAT_00038adc,DAT_00038b28);
          DAT_00038b14 = DAT_00038b14 | 1;
          if ((((DAT_00038b18 != 0) && (DAT_00038adc != 1)) && (DAT_00038b04 != 0)) &&
             (NKDbgPrintfW(L"[Upd Manager] MD directory exists.... g_bUpgrade %d\r\n",DAT_00038afc),
             DAT_00038afc == 0)) {
            iVar5 = FUN_00013370();
            if (iVar5 != 0) {
              SetTimer(DAT_00038ae8,0x3eb,0xdac,(TIMERPROC)0x0);
            }
            iVar5 = FUN_00017598(DAT_00038b04,(LPCWSTR)(DAT_00038b04 + 0x208));
            if (iVar5 == 0) {
              DAT_0003744c = FUN_00012ff0();
              iVar5 = 0;
              if ((DAT_0003744c != -1) && (DAT_0003744c < 7)) {
                if (DAT_0003744c == 0) {
                  pwVar11 = L"\\MD\\upgrade_root.lgu";
LAB_00013d0c:
                  swprintf_s((wchar_t *)(DAT_00038b04 + 0x208),0x104,L"%s",pwVar11);
                }
                else {
                  if (DAT_0003744c == 1) {
                    pwVar11 = L"\\MD\\navigation_restore.lgu";
                    goto LAB_00013d0c;
                  }
                  if (DAT_0003744c == 2) {
                    pwVar11 = L"\\MD\\navigation_restore_fat32.lgu";
                    goto LAB_00013d0c;
                  }
                  if (DAT_0003744c == 3) {
                    pwVar11 = L"\\MD\\navigation_restore_tfat.lgu";
                    goto LAB_00013d0c;
                  }
                  if (DAT_0003744c == 4) {
                    pwVar11 = L"\\MD\\navigation_restore_feu.lgu";
                    goto LAB_00013d0c;
                  }
                  if (DAT_0003744c == 5) {
                    pwVar11 = L"\\MD\\navigation_restore_amr.lgu";
                    goto LAB_00013d0c;
                  }
                  if (DAT_0003744c == 6) {
                    pwVar11 = L"\\MD\\navigation_restore_oth.lgu";
                    goto LAB_00013d0c;
                  }
                }
                swprintf_s((wchar_t *)(DAT_00038b04 + 0x410),0x104,L"%s",&DAT_00031f0c);
                iVar5 = FUN_00017598(DAT_00038b04,(LPCWSTR)(DAT_00038b04 + 0x208));
              }
              NKDbgPrintfW(L"[Upd Manager] No upgrade.lgu file in the MD (DEV_NOTIFY_MSG) -- g_bMapUpdate = %d, SearchUpgradeFiles = %d\r\n"
                           ,DAT_00038b18,iVar5);
              if (((iVar5 == 0) &&
                  (DVar3 = GetFileAttributesW(L"\\MD\\update_checksum.md5"), DVar3 != 0xffffffff))
                 && (pHVar4 = FindWindowW(L"CodeChecker",L"CodeChecker"), pHVar4 == (HWND)0x0)) {
                FUN_0001594c();
              }
            }
          }
        }
      }
      DAT_00038b08 = DAT_00038b08 + 1;
      uVar12 = DAT_00038adc;
      goto LAB_00014700;
    }
    pHVar4 = FindWindowW(L"APPMAIN",(LPCWSTR)0x0);
    uVar12 = DAT_00038adc;
    if ((pHVar4 != (HWND)0x0) || (DAT_0003743c == 0xbbd)) goto LAB_00014700;
    uIDEvent = 2;
  }
LAB_00013ee0:
  KillTimer(param_1,uIDEvent);
  uVar12 = DAT_00038adc;
LAB_00014700:
  DAT_00038adc = uVar12;
  FUN_0002a0c4(local_30);
  return 0;
}



/* 0001473c FUN_0001473c */

/* Boundary evidence: original MIPS .pdata 0001473c..0001481b. Semantic name remains unreviewed. */

bool FUN_0001473c(undefined4 param_1)

{
  bool bVar1;
  
  DAT_00038b04 = (wchar_t *)__2_YAPAXI_Z(0x634);
  if (DAT_00038b04 == (wchar_t *)0x0) {
    DAT_00038b04 = (wchar_t *)0x0;
  }
  else {
    *DAT_00038b04 = L'\0';
    DAT_00038b04[0x104] = L'\0';
    DAT_00038b04[0x208] = L'\0';
    DAT_00038b04[0x30c] = L'\0';
    DAT_00038b04[0x30d] = L'\0';
    DAT_00038b04[0x30e] = L'\0';
    DAT_00038b04[0x30f] = L'\0';
    DAT_00038b04[0x310] = L'\x01';
    DAT_00038b04[0x311] = L'\0';
    DAT_00038b04[0x312] = L'\0';
    DAT_00038b04[0x313] = L'\0';
    DAT_00038b04[0x314] = L'\0';
    DAT_00038b04[0x315] = L'\0';
    DAT_00038b04[0x316] = L'\0';
    DAT_00038b04[0x317] = L'\0';
    *(undefined4 *)(DAT_00038b04 + 0x318) = param_1;
  }
  bVar1 = DAT_00038b04 != (wchar_t *)0x0;
  if (bVar1) {
    swprintf_s(DAT_00038b04,0x104,L"%s",&DAT_00031024);
    swprintf_s(DAT_00038b04 + 0x104,0x104,L"%s",L"\\MD\\upgrade.lgu");
    swprintf_s(DAT_00038b04 + 0x208,0x104,L"%s",L"\\Storage Card3\\");
  }
  return bVar1;
}



/* 0001481c FUN_0001481c */

/* Boundary evidence: original MIPS .pdata 0001481c..00014973. Semantic name remains unreviewed. */

void FUN_0001481c(int param_1)

{
  HINSTANCE hInstance;
  
  if (param_1 != DAT_00037410) {
    if (param_1 < 0x1d) {
      hInstance = LoadLibraryW((LPCWSTR)(&PTR_u__Storage_Card_system_data_LangDl_000374f8)[param_1])
      ;
      DAT_00037410 = param_1;
    }
    else {
      hInstance = LoadLibraryW((LPCWSTR)PTR_u__Storage_Card_system_data_LangDl_00037500);
    }
    if (hInstance != (HINSTANCE)0x0) {
      LoadStringW(hInstance,0x4b5,(LPWSTR)&DAT_000384bc,0x104);
      LoadStringW(hInstance,0x4b6,(LPWSTR)&DAT_000382b4,0x104);
      LoadStringW(hInstance,0x4b7,(LPWSTR)&DAT_000380ac,0x104);
      LoadStringW(hInstance,0x4b8,(LPWSTR)&DAT_00037ea4,0x104);
      LoadStringW(hInstance,0x4b9,(LPWSTR)&DAT_00037c9c,0x104);
      LoadStringW(hInstance,0x4ba,(LPWSTR)&DAT_00037a94,0x104);
      LoadStringW(hInstance,0x4bb,(LPWSTR)&DAT_0003788c,0x104);
      LoadStringW(hInstance,0x59a,(LPWSTR)&DAT_00037684,0x104);
      FreeLibrary(hInstance);
    }
  }
  return;
}



/* 00014974 FUN_00014974 */

/* Boundary evidence: original MIPS .pdata 00014974..00015217. Semantic name remains unreviewed. */

void FUN_00014974(void)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  HWND hWnd;
  undefined3 extraout_var;
  HANDLE pvVar4;
  DWORD DVar5;
  undefined3 extraout_var_00;
  DWORD DVar6;
  undefined1 local_240;
  undefined1 local_23f;
  undefined1 local_23e;
  undefined1 local_23d [5];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d4;
  if (DAT_00038b04 != 0) {
    iVar3 = FUN_000170e0(DAT_00038b04,
                         L"\\Storage Card4\\NNG\\CONTENT\\USERDATA\\POI\\Renault_Dealers.kml",0,0);
    if (iVar3 == 1) {
      DeleteFileW(L"\\Storage Card4\\NNG\\CONTENT\\USERDATA\\POI\\Renault_Dealers.kml");
      NKDbgPrintfW(L"\r\n DeleteFile(%s) \r\n",
                   L"\\Storage Card4\\NNG\\CONTENT\\USERDATA\\POI\\Renault_Dealers.kml");
    }
    iVar3 = FUN_000170e0(DAT_00038b04,L"\\Storage Card3\\upgrade",0,1);
    if (iVar3 == 1) {
      iVar3 = FUN_000170e0(DAT_00038b04,L"\\Storage Card3\\upgrade\\filecopy_success.bin",0,0);
      if ((iVar3 == 1) ||
         (iVar3 = FUN_000170e0(DAT_00038b04,
                               L"\\Storage Card3\\upgrade\\Storage Card\\system\\filecopy_success.bin"
                               ,0,0), iVar3 == 1)) {
        hWnd = FindWindowW((LPCWSTR)PTR_u_MgrMcm_0003745c,(LPCWSTR)0x0);
        if (DAT_00038b00 == 0) {
          if (hWnd == (HWND)0x0) {
            NKDbgPrintfW(L"MicomManger is NOT running!!!\r\n");
            bVar2 = FUN_000164c4();
            if (CONCAT31(extraout_var,bVar2) != 0) {
              local_23f = 1;
              FUN_000165b8(1,1,0xfd,0,0);
              FUN_000165b8(1,1,7,(int)&local_23f,1);
              NKDbgPrintfW(L"COM2 open succeed!!!\r\n");
            }
          }
          else {
            PostMessageW(hWnd,0x8064,0xb90300,1);
          }
          DAT_00038b00 = 1;
        }
        iVar3 = FUN_000170e0(DAT_00038b04,
                             L"\\Storage Card3\\upgrade\\Storage Card\\system\\Img\\RVC",0,1);
        if (iVar3 == 1) {
          FUN_00017c28(DAT_00038b04,L"\\Storage Card\\system\\Img\\RVC");
        }
        iVar3 = FUN_000170e0(DAT_00038b04,
                             L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\content\\speedcam",0,1)
        ;
        if (iVar3 == 1) {
          FUN_00017c28(DAT_00038b04,L"\\Storage Card4\\NNG\\content\\speedcam");
        }
        iVar3 = FUN_000170e0(DAT_00038b04,
                             L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\content\\userdata\\POI\\RenaultDealers.zip"
                             ,0,0);
        if (iVar3 == 1) {
          FUN_00017c28(DAT_00038b04,L"\\Storage Card4\\NNG\\content\\userdata\\POI");
        }
        iVar3 = FUN_000170e0(DAT_00038b04,L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\synctool",
                             0,1);
        if (iVar3 == 1) {
          FUN_00017c28(DAT_00038b04,L"\\Storage Card4\\NNG\\synctool");
        }
        iVar3 = FUN_000170e0(DAT_00038b04,L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\shaders",0
                             ,1);
        if (iVar3 == 1) {
          FUN_00017c28(DAT_00038b04,L"\\Storage Card4\\NNG\\shaders");
        }
        iVar3 = FUN_000170e0(DAT_00038b04,L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\data.zip",
                             0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card4\\NNG\\data.zip");
        }
        iVar3 = FUN_000170e0(DAT_00038b04,
                             L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\nngnavi.exe",0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card4\\NNG\\nngnavi.exe");
        }
        iVar3 = FUN_000170e0(DAT_00038b04,
                             L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\raster.dll",0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card4\\NNG\\raster.dll");
        }
        iVar3 = FUN_000170e0(DAT_00038b04,L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\sys.txt",0
                             ,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card4\\NNG\\sys.txt");
        }
        NKDbgPrintfW(L"[Upd Manager] Upgrade files [SC3 -> SC][0x%08X]\r\n",DAT_00038b04);
        iVar3 = FUN_000170e0(DAT_00038b04,L"\\Storage Card2\\scan_done_flag.bin",0,0);
        if (iVar3 == 1) {
          FUN_00019fbc(1,0,0);
          FUN_00017c28(DAT_00038b04,L"\\Storage Card3\\TFAT");
        }
        else {
          DeleteFileW(L"\\Storage card2\\pwr_count.bin");
          pvVar4 = CreateFileW(L"\\Storage Card2\\scan_done_flag.bin",0x40000000,0,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
          if (pvVar4 != (HANDLE)0xffffffff) {
            CloseHandle(pvVar4);
          }
          FUN_00016d88();
          FUN_000180a8(DAT_00038b04,L"\\Storage Card2",L"\\Storage Card3\\TFAT");
          FUN_00019fbc(1,0,0);
          FUN_000182e0(DAT_00038b04,L"\\Storage Card3\\TFAT",L"\\Storage Card2");
          DVar5 = GetFileAttributesW(L"\\Storage Card2\\scan_done_flag.bin");
          if (DVar5 != 0xffffffff) {
            DeleteFileW(L"\\Storage Card2\\scan_done_flag.bin");
          }
        }
        iVar3 = FUN_000170e0(DAT_00038b04,L"\\Storage Card\\system\\OLD_UpgradeManager.exe",0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card\\system\\OLD_UpgradeManager.exe");
        }
        iVar3 = FUN_000170e0(DAT_00038b04,L"\\Storage Card3\\upgrade\\firmware.hex",0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card3\\upgrade\\firmware.hex");
        }
        swprintf_s(awStack_238,0x104,L"%s",&DAT_000303d8);
        DAT_0003743c = 0xbbd;
        FUN_00019330(DAT_00038b04);
        iVar3 = DAT_00038b04;
        *(undefined4 *)(DAT_00038b04 + 0x620) = 0;
        FUN_00017a1c(iVar3,L"\\Storage Card3\\upgrade");
        FUN_00017dfc(DAT_00038b04,L"\\Storage Card3\\upgrade",awStack_238);
        iVar3 = DAT_00038b04;
        puVar1 = (undefined4 *)(DAT_00038b04 + 0x630);
        *(undefined4 *)(DAT_00038b04 + 0x628) = 0;
        SetWindowPos((HWND)*puVar1,(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
        SetWindowPos(*(HWND *)(iVar3 + 0x630),(HWND)0x1,0,0,800,0x1e0,0x80);
        ShowWindow(*(HWND *)(iVar3 + 0x630),0);
        DAT_0003743c = 3000;
        if (DAT_00038b00 == 1) {
          if (hWnd != (HWND)0x0) {
            PostMessageW(hWnd,0x8064,0xb90300,0);
          }
          NKDbgPrintfW(L"[UPG]          PostMSG    [0]    !@#+_!+@)$+)!@+$)  \r\n");
          DAT_00038b00 = 0;
        }
        NKDbgPrintfW(L"[Upd Manager ] upgrade files move complete!!\r\n");
      }
      FUN_00017c28(DAT_00038b04,L"\\Storage Card3\\upgrade");
      if (DAT_00037444 != -1) {
        local_23d[0] = 0;
        FUN_000165b8(1,1,7,(int)local_23d,1);
        if (DAT_00037444 != -1) {
          CloseHandle((HANDLE)DAT_00037444);
          DAT_00037444 = -1;
        }
        NKDbgPrintfW(L"COM2 close succeed!!!\r\n");
      }
    }
    else {
      DVar5 = FUN_000137bc();
      if (0xaf < DVar5) {
        DeleteFileW(L"\\Storage card2\\pwr_count.bin");
        iVar3 = FUN_000170e0(DAT_00038b04,L"\\Storage Card2\\scan_done_flag.bin",0,0);
        if (iVar3 == 1) {
          FUN_00019fbc(1,0,0);
        }
        else {
          DVar5 = GetTickCount();
          bVar2 = FUN_000164c4();
          if (CONCAT31(extraout_var_00,bVar2) != 0) {
            local_240 = 1;
            FUN_000165b8(1,1,0xfd,0,0);
            FUN_000165b8(1,1,7,(int)&local_240,1);
            NKDbgPrintfW(L"=-=- COM2 open succeed!!!\r\n");
          }
          pvVar4 = CreateFileW(L"\\Storage Card2\\scan_done_flag.bin",0x40000000,0,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
          if (pvVar4 != (HANDLE)0xffffffff) {
            CloseHandle(pvVar4);
          }
          FUN_00016d88();
          FUN_000180a8(DAT_00038b04,L"\\Storage Card2",L"\\Storage Card3\\TFAT");
          FUN_00019fbc(1,0,0);
          FUN_000182e0(DAT_00038b04,L"\\Storage Card3\\TFAT",L"\\Storage Card2");
          DVar6 = GetFileAttributesW(L"\\Storage Card2\\scan_done_flag.bin");
          if (DVar6 != 0xffffffff) {
            DeleteFileW(L"\\Storage Card2\\scan_done_flag.bin");
          }
          if (DAT_00037444 != -1) {
            local_23e = 0;
            FUN_000165b8(1,1,7,(int)&local_23e,1);
            if (DAT_00037444 != -1) {
              CloseHandle((HANDLE)DAT_00037444);
              DAT_00037444 = -1;
            }
            DVar6 = GetTickCount();
            NKDbgPrintfW(L"=-=- COM2 close succeed!!![%d]\r\n",DVar6 - DVar5);
          }
        }
      }
    }
  }
  FUN_0002a0c4(local_30);
  return;
}



/* 00015218 FUN_00015218 */

/* Boundary evidence: original MIPS .pdata 00015218..0001544f. Semantic name remains unreviewed. */

undefined4 FUN_00015218(void)

{
  HWND hWnd;
  
  NKDbgPrintfW(L"Uncompressed Start +_+_+_+_+_+_+_+_+_ \r\n");
  FUN_00019330(DAT_00038b04);
  DAT_00038afc = 0;
  DAT_00038af8 = 1;
  DAT_00038b30 = 0;
  if (DAT_0003744c == -1) {
    FUN_00019fbc(2,0,0);
  }
  else if (DAT_0003744c != 0) {
    hWnd = FindWindowW(L"NAVI",(LPCWSTR)0x0);
    if (hWnd != (HWND)0x0) {
      PostMessageW(hWnd,0x10,0,0);
      NKDbgPrintfW(L"[Upd Manager] [INFO] [0x%08X] %s close.... DetectFileType[%d]\r\n",hWnd,L"NAVI"
                   ,DAT_0003744c);
      Sleep(0x9c4);
    }
    FUN_00019fbc(3,(uint)(DAT_0003744c == 3),(uint)(DAT_0003744c == 3));
    CopyFileW(L"\\Storage Card2\\mgrmcm2.cfg",L"\\Storage Card3\\mgrmcm2.cfg",0);
    CopyFileW(L"\\Storage Card2\\mgrmcm2_backup.cfg",L"\\Storage Card3\\mgrmcm2_backup.cfg",0);
    FUN_00019fbc(1,0,0);
    CopyFileW(L"\\Storage Card3\\mgrmcm2.cfg",L"\\Storage Card2\\mgrmcm2.cfg",0);
    CopyFileW(L"\\Storage Card3\\mgrmcm2_backup.cfg",L"\\Storage Card2\\mgrmcm2_backup.cfg",0);
  }
  DAT_00038b30 = FUN_000193c0(DAT_00038b04);
  if (DAT_00037440 == 1) {
    DAT_00038b30 = 0;
  }
  EventModify(DAT_00038af4,3);
  NKDbgPrintfW(L"Uncompressed End [%d]+_+_+_+_+_+_+_+_+_ \r\n",DAT_00038b30);
  if (DAT_00038aec != 0) {
    CloseHandle((HANDLE)DAT_00038aec);
    DAT_00038aec = 0;
  }
  return 0;
}



/* 00015450 FUN_00015450 */

/* Boundary evidence: original MIPS .pdata 00015450..000154cb. Semantic name remains unreviewed. */

undefined4 FUN_00015450(void)

{
  WaitForSingleObject(DAT_00038af4,0xffffffff);
  if (DAT_00038b30 != 0) {
    FUN_000171bc(DAT_00038b04);
  }
  if (DAT_00038af0 != 0) {
    CloseHandle((HANDLE)DAT_00038af0);
    DAT_00038af0 = 0;
  }
  return 0;
}



/* 000154cc FUN_000154cc */

/* Boundary evidence: original MIPS .pdata 000154cc..0001594b. Semantic name remains unreviewed. */

void FUN_000154cc(int param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  HWND pHVar3;
  wchar_t *pwVar4;
  
  if (param_1 == 0) {
    pwVar4 = L"Detach";
  }
  else {
    pwVar4 = L"Attatch";
  }
  NKDbgPrintfW(L"====> [0x%08X]   [%s]  [%d]   [Update %d, Acc %d] g_hMountEvent[0x%08x] +_+_\r\n",
               DAT_00038b14,pwVar4,param_2,DAT_00038b18,DAT_00038adc,DAT_00038b28);
  if (param_2 != 0) {
    if (param_2 != 4) {
      return;
    }
    if (param_1 == 0) {
      return;
    }
    if (DAT_00038b28 == 0) {
      return;
    }
    EventModify(DAT_00038b28,3);
    return;
  }
  if (param_1 == 0) {
    DAT_00038b14 = DAT_00038b14 & 0xfffffffe;
  }
  else {
    DAT_00038b14 = DAT_00038b14 | 1;
  }
  if (DAT_00038b18 == 0) {
    return;
  }
  if ((DAT_00038adc == 1) && (param_1 != 0)) {
    return;
  }
  if (param_1 == 0) {
    if (DAT_00038afc == 0) {
      DAT_00038af8 = 0;
      DAT_0003743c = 3000;
      if (DAT_00038aec != (HANDLE)0x0) {
        DAT_00037440 = 1;
        WaitForSingleObject(DAT_00038aec,0xffffffff);
        if (DAT_00038aec != (HANDLE)0x0) {
          CloseHandle(DAT_00038aec);
          DAT_00038aec = (HANDLE)0x0;
        }
      }
      DAT_00038b0c = 0;
      if (DAT_0003744c != -1) {
        DAT_0003744c = -1;
        swprintf_s((wchar_t *)(DAT_00038b04 + 0x208),0x104,L"%s",L"\\MD\\upgrade.lgu");
        swprintf_s((wchar_t *)(DAT_00038b04 + 0x410),0x104,L"%s",L"\\Storage Card3\\");
      }
      *(undefined4 *)(DAT_00038b04 + 0x628) = 0;
      ShowWindow(DAT_00038ae8,0);
      if (DAT_00038b00 == 1) {
        pHVar3 = FindWindowW((LPCWSTR)PTR_u_MgrMcm_0003745c,(LPCWSTR)0x0);
        if (pHVar3 != (HWND)0x0) {
          PostMessageW(pHVar3,0x8064,0xb90300,0);
        }
        NKDbgPrintfW(L"[UPG]          PostMSG    [0]  hMcmWnd[0x%08X] g_bUpgrade %d  !@#+_!+@)$+)!@+$)  \r\n"
                     ,pHVar3,DAT_00038afc);
        DAT_00038b00 = 0;
      }
    }
    KillTimer(DAT_00038ae8,0x3eb);
    FUN_00013638(0x11,0x15,0x27a);
    return;
  }
  if (DAT_00038b04 == 0) {
    return;
  }
  NKDbgPrintfW(L"[Upd Manager] MD directory exists.... g_bUpgrade %d\r\n",DAT_00038afc);
  if (DAT_00038afc != 0) {
    return;
  }
  iVar1 = FUN_00013370();
  if (iVar1 != 0) {
    SetTimer(DAT_00038ae8,0x3eb,0xdac,(TIMERPROC)0x0);
  }
  iVar1 = FUN_00017598(DAT_00038b04,(LPCWSTR)(DAT_00038b04 + 0x208));
  if (iVar1 != 0) {
    return;
  }
  DAT_0003744c = FUN_00012ff0();
  iVar1 = 0;
  if ((DAT_0003744c == -1) || (6 < DAT_0003744c)) goto LAB_00015720;
  if (DAT_0003744c == 0) {
    pwVar4 = L"\\MD\\upgrade_root.lgu";
LAB_000156e0:
    swprintf_s((wchar_t *)(DAT_00038b04 + 0x208),0x104,L"%s",pwVar4);
  }
  else {
    if (DAT_0003744c == 1) {
      pwVar4 = L"\\MD\\navigation_restore.lgu";
      goto LAB_000156e0;
    }
    if (DAT_0003744c == 2) {
      pwVar4 = L"\\MD\\navigation_restore_fat32.lgu";
      goto LAB_000156e0;
    }
    if (DAT_0003744c == 3) {
      pwVar4 = L"\\MD\\navigation_restore_tfat.lgu";
      goto LAB_000156e0;
    }
    if (DAT_0003744c == 4) {
      pwVar4 = L"\\MD\\navigation_restore_feu.lgu";
      goto LAB_000156e0;
    }
    if (DAT_0003744c == 5) {
      pwVar4 = L"\\MD\\navigation_restore_amr.lgu";
      goto LAB_000156e0;
    }
    if (DAT_0003744c == 6) {
      pwVar4 = L"\\MD\\navigation_restore_oth.lgu";
      goto LAB_000156e0;
    }
  }
  swprintf_s((wchar_t *)(DAT_00038b04 + 0x410),0x104,L"%s",&DAT_00031f0c);
  iVar1 = FUN_00017598(DAT_00038b04,(LPCWSTR)(DAT_00038b04 + 0x208));
LAB_00015720:
  NKDbgPrintfW(L"[Upd Manager] No upgrade.lgu file in the MD (DEV_NOTIFY_MSG) -- g_bMapUpdate = %d, SearchUpgradeFiles = %d\r\n"
               ,DAT_00038b18,iVar1);
  if (((iVar1 == 0) &&
      (DVar2 = GetFileAttributesW(L"\\MD\\update_checksum.md5"), DVar2 != 0xffffffff)) &&
     (pHVar3 = FindWindowW(L"CodeChecker",L"CodeChecker"), pHVar3 == (HWND)0x0)) {
    FUN_0001594c();
  }
  return;
}



/* 0001594c FUN_0001594c */

/* Boundary evidence: original MIPS .pdata 0001594c..00015abb. Semantic name remains unreviewed. */

undefined4 FUN_0001594c(void)

{
  BOOL BVar1;
  HANDLE pvVar2;
  HWND hWnd;
  wchar_t *pwVar3;
  undefined4 uVar4;
  _PROCESS_INFORMATION _Stack_28;
  
  uVar4 = 0;
  if (DAT_00038b1c == (HANDLE)0x0) {
    BVar1 = CreateProcessW(L"\\Storage Card4\\NNG\\Synctool\\Synctool.exe",
                           L"^kk9r2a@=4F2g-1.5_J2tw6X@navi",(LPSECURITY_ATTRIBUTES)0x0,
                           (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                           (LPSTARTUPINFOW)0x0,&_Stack_28);
    if (BVar1 == 0) {
      pvVar2 = (HANDLE)GetLastError();
      pwVar3 = L"[Upd Manager]SYNCTool.exe did not excute!! 0x%x\r\n";
    }
    else {
      uVar4 = 1;
      if (DAT_00038b00 == 0) {
        hWnd = FindWindowW((LPCWSTR)PTR_u_MgrMcm_0003745c,(LPCWSTR)0x0);
        if (hWnd != (HWND)0x0) {
          PostMessageW(hWnd,0x8064,0xb90300,1);
          FUN_000134e8();
          NKDbgPrintfW(L"[Upd Manager] SYNCTool.exe is excuted!! and sended msg\r\n");
        }
        NKDbgPrintfW(L"[UPG]          PostMSG    [0]  hMcmWnd[0x%08X]  !@#+_!+@)$+)!@+$)  \r\n",hWnd
                    );
        DAT_00038b00 = 0;
      }
      DAT_00038b1c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00012b4c,&_Stack_28,0,
                                  (LPDWORD)0x0);
      pwVar3 = L"[Upd Manager]SYNCTool.exe normally excute!!! 0x%08X\r\n";
      pvVar2 = DAT_00038b1c;
    }
  }
  else {
    pwVar3 = L"[Upd Manager][ERROR]SYNCTool.exe already excute!!! 0x%08X\r\n";
    pvVar2 = DAT_00038b1c;
  }
  NKDbgPrintfW(pwVar3,pvVar2);
  return uVar4;
}



/* 00015abc FUN_00015abc */

/* Boundary evidence: original MIPS .pdata 00015abc..00015be7. Semantic name remains unreviewed. */

void FUN_00015abc(int param_1)

{
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  
  hdc = GetDC(DAT_00038ae8);
  hdc_00 = CreateCompatibleDC(hdc);
  pvVar1 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_comm_00037414)
                                   [DAT_00038ae4 * 5]);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  if (param_1 == 0) {
    TransparentImage(hdc,0xd,0x191,0xa2,0x4f,hdc_00,0,0,0xa2,0x4f,0xffff00);
  }
  else {
    TransparentImage(hdc,0xd,0x191,0xa2,0x4f,hdc_00,0xa2,0,0xa2,0x4f,0xffff00);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  DeleteObject(pvVar1);
  DeleteDC(hdc_00);
  ReleaseDC(DAT_00038ae8,hdc);
  return;
}



/* 00015be8 FUN_00015be8 */

/* Boundary evidence: original MIPS .pdata 00015be8..00015e7b. Semantic name remains unreviewed. */

void FUN_00015be8(int param_1)

{
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  HFONT h;
  COLORREF color;
  tagRECT local_90;
  LOGFONTW local_80;
  uint local_24;
  
  local_24 = DAT_000372d4;
  hdc = GetDC(DAT_00038ae8);
  hdc_00 = CreateCompatibleDC(hdc);
  pvVar1 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_comm_00037418)
                                   [DAT_00038ae4 * 5]);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  if (param_1 == 0) {
    TransparentImage(hdc,0xb2,0x191,0x261,0x4f,hdc_00,0,0,0x261,0x4f,0xffff00);
  }
  else {
    TransparentImage(hdc,0xb2,0x191,0x261,0x4f,hdc_00,0x261,0,0x261,0x4f,0xffff00);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  DeleteObject(pvVar1);
  DeleteDC(hdc_00);
  memset(&local_80,0,0x5c);
  SetBkMode(hdc,1);
  if (param_1 == 0) {
    color = 0xe1e1e1;
  }
  else {
    color = 0;
  }
  SetTextColor(hdc,color);
  local_80.lfHeight = 0x24;
  local_80.lfWidth = 0;
  local_80.lfEscapement = 0;
  local_80.lfOrientation = 0;
  local_80.lfWeight = 0;
  local_80.lfItalic = '\0';
  local_80.lfUnderline = '\0';
  local_80.lfStrikeOut = '\0';
  local_80.lfCharSet = '\0';
  local_80.lfOutPrecision = '\0';
  local_80.lfQuality = '\x06';
  local_80.lfPitchAndFamily = '\x02';
  local_80.lfClipPrecision = '\0';
  wsprintfW(local_80.lfFaceName,L"Tahoma");
  h = CreateFontIndirectW(&local_80);
  pvVar1 = SelectObject(hdc,h);
  local_90.right = 0x313;
  local_90.left = 0xb2;
  local_90.top = 0x191;
  local_90.bottom = 0x1e0;
  if ((DAT_00037410 == 0) || (DAT_00037410 == 0x15)) {
    DrawTextW(hdc,(LPCWSTR)&DAT_00037c9c,-1,&local_90,0x20005);
  }
  else {
    DrawTextW(hdc,(LPCWSTR)&DAT_00037c9c,-1,&local_90,5);
  }
  SelectObject(hdc,pvVar1);
  DeleteObject(h);
  ReleaseDC(DAT_00038ae8,hdc);
  FUN_0002a0c4(local_24);
  return;
}



/* 00015e7c FUN_00015e7c */

undefined4 FUN_00015e7c(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_0003743c == 3000) {
    if ((((param_1 < 0xd) || (0xaf < param_1)) || (param_2 < 0x191)) || (0x1e0 < param_2)) {
      if (((0xb1 < param_1) && (param_1 < 0x314)) && ((400 < param_2 && (param_2 < 0x1e1)))) {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 00015f10 FUN_00015f10 */

/* Boundary evidence: original MIPS .pdata 00015f10..000163d7. Semantic name remains unreviewed. */

void FUN_00015f10(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  HDC hDC;
  HBRUSH hbr;
  HFONT h;
  HGDIOBJ h_00;
  HWND pHVar3;
  DWORD DVar4;
  tagRECT local_a8;
  RECT local_98;
  LOGFONTW local_88;
  uint local_2c;
  
  local_2c = DAT_000372d4;
  iVar2 = FUN_00015e7c(param_1,param_2);
  if (DAT_0003743c == 3000) {
    if (iVar2 == DAT_00037448) {
      if (DAT_00037448 == 0) {
        FUN_00015abc(0);
        Sleep(500);
        DAT_0003743c = 3000;
        if (DAT_0003744c != -1) {
          DAT_0003744c = -1;
          swprintf_s((wchar_t *)(DAT_00038b04 + 0x208),0x104,L"%s",L"\\MD\\upgrade.lgu");
          swprintf_s((wchar_t *)(DAT_00038b04 + 0x410),0x104,L"%s",L"\\Storage Card3\\");
        }
        ShowWindow(DAT_00038ae8,0);
        FUN_00013638(0x11,0x15,0x27a);
        DVar4 = GetFileAttributesW(L"\\MD\\update_checksum.md5");
        if ((DVar4 != 0xffffffff) &&
           (pHVar3 = FindWindowW(L"CodeChecker",L"CodeChecker"), pHVar3 == (HWND)0x0)) {
          FUN_0001594c();
        }
      }
      else if (DAT_00037448 == 1) {
        FUN_00015be8(0);
        iVar1 = DAT_00038b04;
        *(undefined4 *)(DAT_00038b04 + 0x628) = 2;
        *(undefined4 *)(iVar1 + 0x618) = 0;
        *(undefined4 *)(iVar1 + 0x61c) = 0;
        *(undefined4 *)(iVar1 + 0x620) = 1;
        *(undefined4 *)(iVar1 + 0x624) = 0;
        if (DAT_0003744c == -1) {
          DAT_0003743c = 0xbb9;
        }
        else {
          DAT_0003743c = 0xbbe;
        }
        if (DAT_00038aec != (HANDLE)0x0) {
          local_98.left = 0;
          local_98.top = 0;
          local_98.right = 800;
          local_98.bottom = 0x1e0;
          hDC = GetDC(DAT_00038ae8);
          hbr = GetStockObject(4);
          FillRect(hDC,&local_98,hbr);
          memset(&local_88,0,0x5c);
          SetBkMode(hDC,1);
          SetTextColor(hDC,0xfefefe);
          local_88.lfWeight = 0x2ee;
          local_88.lfHeight = 0x28;
          local_88.lfWidth = 0;
          local_88.lfEscapement = 0;
          local_88.lfOrientation = 0;
          local_88.lfItalic = '\0';
          local_88.lfUnderline = '\0';
          local_88.lfStrikeOut = '\0';
          local_88.lfCharSet = '\0';
          local_88.lfOutPrecision = '\0';
          local_88.lfQuality = '\x06';
          local_88.lfPitchAndFamily = '\x02';
          local_88.lfClipPrecision = '\0';
          wsprintfW(local_88.lfFaceName,L"Tahoma");
          h = CreateFontIndirectW(&local_88);
          h_00 = SelectObject(hDC,h);
          local_a8.left = 0;
          local_a8.top = 0;
          local_a8.right = 800;
          local_a8.bottom = 0x1e0;
          if ((DAT_00037410 == 0) || (DAT_00037410 == 0x15)) {
            DrawTextW(hDC,(LPCWSTR)&DAT_00037684,-1,&local_a8,0x20005);
          }
          else {
            DrawTextW(hDC,(LPCWSTR)&DAT_00037684,-1,&local_a8,5);
          }
          SelectObject(hDC,h_00);
          DeleteObject(h);
          ReleaseDC(DAT_00038ae8,hDC);
          DAT_00037440 = 1;
          WaitForSingleObject(DAT_00038aec,0xffffffff);
          if (DAT_00038aec != (HANDLE)0x0) {
            CloseHandle(DAT_00038aec);
            DAT_00038aec = (HANDLE)0x0;
          }
        }
        if (DAT_00038b00 == 0) {
          pHVar3 = FindWindowW((LPCWSTR)PTR_u_MgrMcm_0003745c,(LPCWSTR)0x0);
          if (pHVar3 != (HWND)0x0) {
            PostMessageW(pHVar3,0x8064,0xb90300,1);
          }
          NKDbgPrintfW(L"[UPG]          PostMSG    [1]    !@#+_!+@)$+)!@+$)  \r\n");
          DAT_00038b00 = 1;
        }
        DAT_00037440 = 0;
        if (DAT_00038af4 != (HANDLE)0x0) {
          CloseHandle(DAT_00038af4);
        }
        DAT_00038af4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        DAT_00038aec = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00015218,(LPVOID)0x0,0,
                                    (LPDWORD)0x0);
        DAT_00038af0 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00015450,(LPVOID)0x0,0,
                                    (LPDWORD)0x0);
      }
    }
    else if (DAT_00037448 == 0) {
      FUN_00015abc(0);
    }
    else if (DAT_00037448 == 1) {
      FUN_00015be8(0);
    }
    DAT_00037448 = -1;
    if (iVar2 != -1) {
      InvalidateRect(DAT_00038ae8,(RECT *)0x0,0);
    }
  }
  FUN_0002a0c4(local_2c);
  return;
}



/* 000163d8 FUN_000163d8 */

/* Boundary evidence: original MIPS .pdata 000163d8..000164c3. Semantic name remains unreviewed. */

undefined4 FUN_000163d8(byte *param_1)

{
  HANDLE hFile;
  undefined4 uVar1;
  DWORD aDStack_28 [2];
  undefined1 auStack_20 [7];
  byte local_19;
  uint local_14;
  
  local_14 = DAT_000372d4;
  uVar1 = 0;
  memset(auStack_20,0,0xc);
  hFile = CreateFileW(L"\\Storage Card\\system\\DSI_config.bsd",0x80000000,0,
                      (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    ReadFile(hFile,auStack_20,0xc,aDStack_28,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
    if (param_1 != (byte *)0x0) {
      *param_1 = local_19 >> 6;
    }
    uVar1 = 1;
  }
  FUN_0002a0c4(local_14);
  return uVar1;
}



/* 000164c4 FUN_000164c4 */

/* Boundary evidence: original MIPS .pdata 000164c4..000165b7. Semantic name remains unreviewed. */

bool FUN_000164c4(void)

{
  HANDLE hFile;
  _COMMTIMEOUTS local_48;
  _DCB _Stack_30;
  
  hFile = CreateFileW(L"COM2:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  DAT_00037444 = hFile;
  if (hFile != (HANDLE)0xffffffff) {
    memset(&local_48,0,0x14);
    GetCommState(hFile,&_Stack_30);
    _Stack_30.BaudRate = 300000;
    _Stack_30.fNull = 0;
    _Stack_30.fParity = 0;
    _Stack_30.ByteSize = '\b';
    _Stack_30.Parity = '\0';
    _Stack_30.StopBits = '\0';
    SetCommState(DAT_00037444,&_Stack_30);
    local_48.ReadIntervalTimeout = 0;
    local_48.ReadTotalTimeoutMultiplier = 0;
    local_48.ReadTotalTimeoutConstant = 0;
    local_48.WriteTotalTimeoutMultiplier = 0;
    local_48.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(DAT_00037444,&local_48);
  }
  return hFile != (HANDLE)0xffffffff;
}



/* 000165b8 FUN_000165b8 */

/* Boundary evidence: original MIPS .pdata 000165b8..000166b7. Semantic name remains unreviewed. */

BOOL FUN_000165b8(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,byte param_5)

{
  BOOL BVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  DWORD aDStack_a0 [2];
  undefined4 local_98;
  byte local_94 [136];
  uint local_c;
  
  local_c = DAT_000372d4;
  uVar2 = (uint)param_5;
  uVar3 = uVar2 << 8;
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      local_94[uVar4] = *(byte *)(uVar4 + param_4);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < uVar2);
  }
  uVar4 = (uVar3 | param_3 & 0xffff) >> 8;
  uVar2 = uVar4 + 4;
  local_98._0_1_ = 0xaa;
  iVar5 = 1;
  if (1 < uVar2) {
    do {
      local_98._0_1_ = local_94[iVar5 + -4] ^ (byte)local_98;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar2);
  }
  local_94[uVar4] = (byte)local_98;
  local_98 = (uVar3 | param_3) << 0x10 | 0x11aa;
  BVar1 = WriteFile(DAT_00037444,&local_98,((uVar3 | param_3 & 0xffff) >> 8) + 5,aDStack_a0,
                    (LPOVERLAPPED)0x0);
  FUN_0002a0c4(local_c);
  return BVar1;
}



/* 000166b8 FUN_000166b8 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 000166b8..000167f3. Semantic name remains unreviewed. */

void FUN_000166b8(void)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  FILE *local_248 [2];
  char acStack_240 [38];
  ushort auStack_21a [257];
  uint local_18;
  
  local_18 = DAT_000372d4;
  memcpy(acStack_240,"\\Storage Card\\system\\Version_Info.txt",0x26);
  uVar2 = 0;
  memset(auStack_21a + 1,0,0x200);
  fopen_s(local_248,acStack_240,"r");
  if (local_248[0] == (FILE *)0x0) {
    NKDbgPrintfW(L"[Upd Manager] [INFO] CUR SW version file NOT exists. \r\n");
  }
  else {
    iVar1 = feof(local_248[0]);
    if (iVar1 == 0) {
      puVar3 = auStack_21a;
      do {
        puVar3 = (ushort *)((int)puVar3 + 2);
        if (0xff < uVar2) break;
        iVar1 = fgetc(local_248[0]);
        uVar2 = uVar2 + 1;
        *puVar3 = (ushort)iVar1;
        iVar1 = feof(local_248[0]);
      } while (iVar1 == 0);
      if (uVar2 != 0) {
        auStack_21a[uVar2] = 0;
      }
    }
    fclose(local_248[0]);
  }
  DAT_00038ae0 = (uint)(0x32 < auStack_21a[1]);
  NKDbgPrintfW(L"[Upd Manager] [INFO]OnCheckPackageVersion() [%s][%c] g_bBeforeULC12 %d\r\n",
               auStack_21a + 1,auStack_21a[1]);
  FUN_0002a0c4(local_18);
  return;
}



/* 000167f4 FUN_000167f4 */

/* Boundary evidence: original MIPS .pdata 000167f4..00016d87. Semantic name remains unreviewed. */

undefined4 FUN_000167f4(uint param_1)

{
  undefined1 uVar1;
  HANDLE hObject;
  HANDLE hObject_00;
  int iVar2;
  DWORD DVar3;
  size_t sVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  HMODULE hLibModule;
  code *pcVar8;
  wchar_t *pwVar9;
  undefined **ppuVar10;
  HANDLE hObject_01;
  undefined **ppuVar11;
  HANDLE hObject_02;
  undefined4 uVar12;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_248;
  undefined1 auStack_244 [64];
  wchar_t awStack_204 [32];
  wchar_t awStack_1c4 [66];
  int local_140;
  undefined4 local_13c;
  undefined4 local_128;
  undefined1 local_124;
  undefined4 local_120 [60];
  uint local_30;
  
  local_30 = DAT_000372d4;
  uVar12 = 0;
  local_120[0] = 0xf0;
  local_248 = 0x128;
  hObject = (HANDLE)OpenStore(u_DSK1__000373e0);
  if (hObject != (HANDLE)0xffffffff) {
    GetStoreInfo(hObject,local_120);
    ppuVar10 = &PTR_u_PART00_000373ec + param_1;
    hObject_00 = (HANDLE)OpenPartition(hObject,*ppuVar10);
    if (hObject_00 != (HANDLE)0xffffffff) {
      iVar2 = GetPartitionInfo(hObject_00,&local_248);
      uVar1 = local_124;
      DVar3 = GetLastError();
      iVar7 = local_140;
      NKDbgPrintfW(L"[%d] - PartitionName[%s], VolumeName[%s], snNumSectors[%d], dwAttributes 0x%04X, bPartType 0x%04X \r\n"
                   ,DVar3,auStack_244,awStack_1c4,local_140,local_13c,local_128,uVar1);
      ppuVar11 = &PTR_u_Storage_Card_000373fc + param_1;
      pwVar9 = (wchar_t *)*ppuVar11;
      sVar4 = wcslen(pwVar9);
      iVar5 = wcsncmp(awStack_1c4,pwVar9,sVar4);
      NKDbgPrintfW(L"bRet[%d] [%d]-[%d] \r\n",iVar2,iVar5);
      if ((iVar2 == 1) && (sVar4 = wcslen(awStack_1c4), sVar4 == 0)) {
        pwVar9 = (wchar_t *)*ppuVar11;
        sVar4 = wcslen(pwVar9);
        iVar2 = wcsncmp(awStack_1c4,pwVar9,sVar4);
        if (iVar2 != 0) {
          CloseHandle(hObject_00);
          DeletePartition(hObject,*ppuVar10);
          CreatePartition(hObject,*ppuVar10,local_140,local_13c);
          hObject_00 = (HANDLE)OpenPartition(hObject,*ppuVar10);
          uVar6 = 1;
          if (hObject_00 != (HANDLE)0xffffffff) {
            uVar6 = GetPartitionInfo(hObject_00,&local_248);
            uVar1 = local_124;
            DVar3 = GetLastError();
            NKDbgPrintfW(L"[%d] - PartitionName[%s], VolumeName[%s], snNumSectors[%d], dwAttributes 0x%04X, bPartType 0x%04X \r\n"
                         ,DVar3,auStack_244,awStack_1c4,local_140,local_13c,local_128,uVar1);
            pwVar9 = (wchar_t *)*ppuVar11;
            sVar4 = wcslen(pwVar9);
            iVar7 = wcsncmp(awStack_1c4,pwVar9,sVar4);
            sVar4 = wcslen(awStack_1c4);
            NKDbgPrintfW(L"bRet[%d] [%d][%d],[%d] \r\n",uVar6,local_124,sVar4,iVar7);
          }
          DVar3 = GetLastError();
          NKDbgPrintfW(L"**** OpenPartition[0x%08X][%d] - [%s]**** \r\n",hObject_00,DVar3,*ppuVar10,
                       iVar7);
          hObject_02 = (HANDLE)0xffffffff;
          hObject_01 = (HANDLE)0xffffffff;
          if (param_1 < 2) {
            hObject_02 = (HANDLE)OpenPartition(hObject,PTR_u_PART02_000373f4);
          }
          if (param_1 < 3) {
            hObject_01 = (HANDLE)OpenPartition(hObject,PTR_u_PART03_000373f8);
          }
          if (hObject_02 != (HANDLE)0xffffffff) {
            DismountPartition(hObject_02);
          }
          if (hObject_01 != (HANDLE)0xffffffff) {
            DismountPartition(hObject_01);
          }
          DVar3 = GetLastError();
          NKDbgPrintfW(L"[%s],[%s],[%s] [%d][%d]\r\n",auStack_244,awStack_204,awStack_1c4,uVar6,
                       DVar3);
          iVar7 = _wcsicmp(awStack_204,L"FATFSD.DLL");
          if (((iVar7 == 0) || (iVar7 = _wcsicmp(awStack_204,L"EXFAT.DLL"), iVar7 == 0)) &&
             (hLibModule = LoadLibraryW(L"FATUTIL.DLL"), hLibModule != (HMODULE)0x0)) {
            pcVar8 = (code *)GetProcAddressW(hLibModule,L"FormatVolume");
            if (pcVar8 == (code *)0x0) {
              uVar12 = 0;
            }
            else {
              local_250 = 0;
              if ((param_1 == 0) || (param_1 == 3)) {
                local_260 = 0x2000;
              }
              else {
                local_260 = 0x200;
              }
              local_25c = 0x200;
              local_254 = 1;
              local_258 = 0x20;
              uVar6 = DismountPartition(hObject_00);
              NKDbgPrintfW(L"**** DismountPartition[%d]**** \r\n",uVar6);
              iVar7 = FormatPartition(hObject_00);
              NKDbgPrintfW(L"**** FormatPartition[%d]**** \r\n",iVar7);
              if (iVar7 == 1) {
                iVar7 = (*pcVar8)(hObject_00,0,&local_260,0,0);
                if (iVar7 == 0) {
                  NKDbgPrintfW(L"SUCCESSED VOLUME FORMAT dwFlags[%04X]dwNumFats[%d]!!!\n",local_250,
                               local_254);
                }
                else {
                  DVar3 = GetLastError();
                  NKDbgPrintfW(L"FAILED VOLUME FORMAT !!![%d][%d]\n",iVar7,DVar3);
                }
                iVar2 = MountPartition(hObject_00);
                if (iVar2 == 0) {
                  DVar3 = GetLastError();
                  NKDbgPrintfW(L"Mount Partition Error -- Retry !!![%d][%d]\n",iVar7,DVar3);
                  iVar7 = MountPartition(hObject_00);
                  if (iVar7 == 0) {
                    DVar3 = GetLastError();
                    NKDbgPrintfW(L"***** [Upd Manager ] SYSTEM MOUNT PARTITION [%d, %d] [%d] ****\r\n"
                                 ,0,DVar3);
                  }
                }
                uVar12 = 1;
              }
            }
            FreeLibrary(hLibModule);
          }
          if (hObject_02 != (HANDLE)0xffffffff) {
            MountPartition(hObject_02);
            CloseHandle(hObject_02);
          }
          if (hObject_01 != (HANDLE)0xffffffff) {
            MountPartition(hObject_01);
            CloseHandle(hObject_01);
          }
        }
      }
      CloseHandle(hObject_00);
    }
    CloseHandle(hObject);
  }
  FUN_0002a0c4(local_30);
  return uVar12;
}



/* 00016d88 FUN_00016d88 */

/* Boundary evidence: original MIPS .pdata 00016d88..000170df. Semantic name remains unreviewed. */

undefined4 FUN_00016d88(void)

{
  DWORD DVar1;
  HANDLE hObject;
  HMODULE hLibModule;
  code *pcVar2;
  HANDLE hObject_00;
  int iVar3;
  DWORD DVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  code *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78 [6];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  uVar6 = 0;
  DVar1 = GetTickCount();
  hObject = (HANDLE)OpenStore(u_DSK1__000373e0);
  if (hObject != (HANDLE)0xffffffff) {
    hLibModule = LoadLibraryW(L"FATUTIL.DLL");
    if (hLibModule != (HMODULE)0x0) {
      pcVar8 = (code *)0x0;
      pcVar2 = (code *)GetProcAddressW(hLibModule,L"ScanVolume");
      if ((pcVar2 == (code *)0x0) &&
         (pcVar8 = (code *)GetProcAddressW(hLibModule,L"ScanVolumeEx"), pcVar8 == (code *)0x0)) {
        uVar6 = 0;
      }
      else {
        uVar6 = 1;
        local_78[0] = 0;
        local_78[1] = 1;
        local_78[2] = 0;
        local_78[3] = 0;
        memset(&local_80,0,8);
        memset(local_78 + 4,0,0x3c);
        local_78[4] = 0x3c;
        local_60 = 1;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 1;
        uVar9 = 0;
        NKDbgPrintfW(L"***** [ %s ] DISKSCAN START [0x%08X, 0x%08X][%d, %d, %d, %d] ****\r\n",
                     "DoDiskScan",pcVar2,pcVar8,0,1,0,0);
        uVar5 = 0;
        do {
          if (*(int *)((int)local_78 + uVar5) == 1) {
            puVar7 = (undefined4 *)((int)&PTR_u_PART00_000373ec + uVar5);
            hObject_00 = (HANDLE)OpenPartition(hObject,*puVar7);
            if (hObject_00 == (HANDLE)0xffffffff) {
              DVar4 = GetLastError();
              NKDbgPrintfW(L"***** [ %s ] Partition open error [%s][0x%08X] ****\r\n","DoDiskScan",
                           *puVar7,DVar4,uVar9,uVar10,uVar11,uVar12);
            }
            else {
              DismountPartition(hObject_00);
              if (pcVar2 == (code *)0x0) {
                iVar3 = (*pcVar8)(hObject_00,local_78 + 4);
              }
              else {
                iVar3 = (*pcVar2)(hObject_00,0,&local_80,0,0);
              }
              if (iVar3 == 0) {
                DVar4 = GetLastError();
                uVar9 = local_7c;
                uVar10 = local_80;
                NKDbgPrintfW(L"***** [ %s ] Partition ScanVolume error [%s][0x%08X] [0x%08X, 0x%08X]****\r\n"
                             ,"DoDiskScan",*puVar7,DVar4,local_7c,local_80);
              }
              else {
                uVar9 = local_7c;
                uVar10 = local_5c;
                uVar11 = local_58;
                uVar12 = local_54;
                NKDbgPrintfW(L"***** [ %s ] ScanVolumeEx Result [%s] - option.dwFlags[0x%08X], option.dwFatToUse[0x%08X], dwLostClusters %d,dwInvalidClusters %d,dwLostChains %d,dwInvalidDirs %d,dwInvalidFiles %d,dwTotalErrors %d,dwPercentFrag %d,fConsistentFats %d,fErrorNotFixed %d \r\n"
                             ,"DoDiskScan",*puVar7,local_80,local_7c,local_5c,local_58,local_54,
                             local_50,local_4c,local_48,local_44,local_40,local_3c);
              }
              MountPartition(hObject_00);
              CloseHandle(hObject_00);
              Sleep(100);
            }
          }
          uVar5 = uVar5 + 4;
        } while (uVar5 < 0x10);
      }
      FreeLibrary(hLibModule);
    }
    CloseHandle(hObject);
    DVar4 = GetTickCount();
    NKDbgPrintfW(L"***** [ %s ] Total time [%d] ****\r\n","DoDiskScan",DVar4 - DVar1);
  }
  return uVar6;
}



/* 000170e0 FUN_000170e0 */

/* Boundary evidence: original MIPS .pdata 000170e0..000171bb. Semantic name remains unreviewed. */

undefined4 FUN_000170e0(undefined4 param_1,LPCWSTR param_2,undefined4 param_3,int param_4)

{
  HANDLE hFindFile;
  undefined4 uVar1;
  uint local_248;
  uint local_18;
  
  local_18 = DAT_000372d4;
  uVar1 = 0;
  hFindFile = FindFirstFileW(param_2,(LPWIN32_FIND_DATAW)&local_248);
  if (hFindFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"-%s- Not found... [%s]\r\n","UpgradeMgr::IsExistDirFile",param_2);
    goto LAB_00017198;
  }
  if (param_4 == 1) {
    if ((local_248 & 0x10) != 0) {
LAB_00017164:
      uVar1 = 1;
    }
  }
  else if ((local_248 & 0x10) == 0) goto LAB_00017164;
  FindClose(hFindFile);
LAB_00017198:
  FUN_0002a0c4(local_18);
  return uVar1;
}



/* 000171bc FUN_000171bc */

/* Boundary evidence: original MIPS .pdata 000171bc..00017597. Semantic name remains unreviewed. */

void FUN_000171bc(int param_1)

{
  HWND pHVar1;
  LSTATUS LVar2;
  int iVar3;
  BOOL BVar4;
  DWORD DVar5;
  wchar_t *pwVar6;
  DWORD local_38;
  HKEY local_34;
  int local_30 [4];
  
  DAT_00038afc = 1;
  InvalidateRect(*(HWND *)(param_1 + 0x630),(RECT *)0x0,0);
  FUN_00019330(param_1);
  pHVar1 = FindWindowW(L"Blue",(LPCWSTR)0x0);
  if (pHVar1 != (HWND)0x0) {
    PostMessageW(pHVar1,0x10,0,0);
    NKDbgPrintfW(L"[Upd Manager] WM_CLOSE message send from Updmgr ro BLUE...\r\n");
  }
  pHVar1 = FindWindowW(L"NAVI",(LPCWSTR)0x0);
  if (pHVar1 != (HWND)0x0) {
    PostMessageW(pHVar1,0x10,0,0);
    NKDbgPrintfW(L"==> [Upd Manager] [INFO] [0x%08X] %s close....\r\n",pHVar1,L"NAVI");
    Sleep(1000);
  }
  local_30[1] = 4;
  local_38 = 4;
  local_30[0] = 0;
  LVar2 = RegCreateKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,(LPWSTR)0x0,0,0x20019,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_34,(LPDWORD)(local_30 + 2));
  if (LVar2 == 0) {
    LVar2 = RegQueryValueExW(local_34,L"SupportUpgradeBootloader",(LPDWORD)0x0,
                             (LPDWORD)(local_30 + 1),(LPBYTE)local_30,&local_38);
    if (LVar2 != 0) {
      NKDbgPrintfW(L"SupportUpgradeBootloader Open FAILED!!! [%d]\r\n",local_38);
    }
    RegCloseKey(local_34);
  }
  else {
    NKDbgPrintfW(L"Reg Open error (SupportUpgradeBootloader)!!!\r\n");
  }
  if (local_30[0] == 1) {
    iVar3 = FUN_000170e0(param_1,L"\\Storage Card3\\upgrade\\booter_standalone.bin",0,0);
    if (iVar3 == 1) {
      NKDbgPrintfW(L"BootLoader Upgrade Start!!       -------              ---------");
      FUN_00019d64(param_1);
      pwVar6 = L"BootLoader Upgrade Done!!       -------              ---------";
    }
    else {
      pwVar6 = L"BootLoader Upgrade File is not found\r\n";
    }
    NKDbgPrintfW(pwVar6);
  }
  iVar3 = FUN_000170e0(param_1,L"\\Storage Card3\\upgrade\\Storage Card\\NK.bin",0,0);
  if (iVar3 == 1) {
    NKDbgPrintfW(L"[Upd Manager] NK.bin exists in SC3 \r\n");
    iVar3 = FUN_000170e0(param_1,L"\\Storage Card\\NK.bin",0,0);
    if ((iVar3 == 1) &&
       (BVar4 = CopyFileW(L"\\Storage Card\\NK.bin",L"\\Storage Card\\NA.bin",0), BVar4 == 0)) {
      NKDbgPrintfW(
                  L"[Upd Manager] FAIL!!!CopyFile(_T(Storage Card\\NK.bin),_T(Storage Card\\NA.bin),TRUE)\r\n"
                  );
    }
    BVar4 = CopyFileW(L"\\Storage Card3\\upgrade\\Storage Card\\NK.bin",L"\\Storage Card\\NK.bin",0)
    ;
    if (BVar4 == 1) {
      DeleteFileW(L"\\Storage Card3\\upgrade\\Storage Card\\NK.bin");
      NKDbgPrintfW(L"[Upd Manager] NK.bin copy complete\r\n");
    }
  }
  iVar3 = FUN_000170e0(param_1,L"\\Storage Card3\\upgrade\\Storage Card\\system\\UpgradeManager.exe"
                       ,0,0);
  if (iVar3 == 1) {
    MoveFileW(L"\\Storage Card\\system\\UpgradeManager.exe",
              L"\\Storage Card\\system\\OLD_UpgradeManager.exe");
    MoveFileW(L"\\Storage Card3\\upgrade\\Storage Card\\system\\UpgradeManager.exe",
              L"\\Storage Card\\system\\UpgradeManager.exe");
  }
  NKDbgPrintfW(L"[Upd Manager] [INFO] upgrade files copy complete. \r\n");
  iVar3 = wcscmp((wchar_t *)(param_1 + 0x208),L"\\MD\\upgrade_root.lgu");
  if ((iVar3 == 0) && (DVar5 = GetFileAttributesW(L"\\MD\\upgrade_root.lgu"), DVar5 != 0xffffffff))
  {
    BVar4 = DeleteFileW(L"\\MD\\upgrade_root.lgu");
    NKDbgPrintfW(L"[Upd Manager] [INFO] %s delete [%d]\r\n",L"\\MD\\upgrade_root.lgu",BVar4);
  }
  NKDbgPrintfW(L"[Upd Manager] [INFO] Start MICOM Firmware upgrade. \r\n");
  pHVar1 = FindWindowW(L"MgrMcm",(LPCWSTR)0x0);
  if (pHVar1 != (HWND)0x0) {
    PostMessageW(pHVar1,0x8064,0xc70300,0x1234);
  }
  return;
}



/* 00017598 FUN_00017598 */

/* Boundary evidence: original MIPS .pdata 00017598..00017a1b. Semantic name remains unreviewed. */

undefined4 FUN_00017598(int param_1,LPCWSTR param_2)

{
  bool bVar1;
  int iVar2;
  HANDLE pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  wchar_t *pwVar8;
  undefined4 uVar9;
  int iVar10;
  DWORD local_934;
  int local_930;
  int local_928;
  int iStack_924;
  int local_920;
  wchar_t awStack_688 [30];
  undefined1 auStack_64c [1308];
  CHAR aCStack_130 [260];
  uint local_2c;
  
  local_2c = DAT_000372d4;
  *(undefined4 *)(param_1 + 0x62c) = 0;
  iVar10 = 0;
  bVar1 = false;
  iVar2 = FUN_000170e0(param_1,param_2,0,0);
  uVar9 = 1;
  if (iVar2 != 0) {
    memset(&DAT_000388d0,0,0x208);
    memset(&DAT_000386c8,0,0x208);
    NKDbgPrintfW(L"[Upd Manager] [INFO] upgrade file exists. \r\n");
    pvVar3 = CreateFileW(L"\\Storage Card\\system\\Version_Info.txt",0x80000000,0,
                         (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (pvVar3 == (HANDLE)0xffffffff) {
      bVar1 = true;
      wcscpy_s((wchar_t *)&DAT_000388d0,0x10,L"No Version Info");
    }
    else {
      ReadFile(pvVar3,aCStack_130,0x104,&local_934,(LPOVERLAPPED)0x0);
      if (0x103 < local_934) {
        local_934 = 0x103;
      }
      MultiByteToWideChar(0,0,aCStack_130,local_934,(LPWSTR)&DAT_000388d0,local_934);
      NKDbgPrintfW(L"=====>  %s [%s][%d] <=====\r\n","UpgradeMgr::SearchUpgradeFiles",&DAT_000388d0,
                   local_934);
      CloseHandle(pvVar3);
    }
    pvVar3 = CreateFileW((LPCWSTR)(param_1 + 0x208),0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                         (HANDLE)0x0);
    if (pvVar3 != (HANDLE)0xffffffff) {
      ReadFile(pvVar3,&local_928,0x7f8,&local_934,(LPOVERLAPPED)0x0);
      if (((local_928 == 0x3055474c) && (iStack_924 == 7)) && (local_920 == 0x400)) {
        iVar10 = 1;
      }
      iVar2 = wcscmp(awStack_688,L"*MEDIA-NAV*");
      NKDbgPrintfW(L"-=-=-=-=- [%d], %d[%s/%s] %s  [%d / %d, %d, %d, %d]=-=-=-=-\r\n",iVar10,iVar2,
                   awStack_688,L"*MEDIA-NAV*",auStack_64c,local_928,0x3055474c,iStack_924,local_920,
                   0x7f8);
      memcpy(&DAT_000386c8,auStack_64c,0x28);
      CloseHandle(pvVar3);
      if (iVar10 != 0) {
        iVar2 = wcscmp((wchar_t *)&DAT_000386c8,(wchar_t *)&DAT_000388d0);
        if (iVar2 == 0) {
          NKDbgPrintfW(L"[Upd Manager] CUR and NEW versions are same\r\n");
        }
        else {
          iVar10 = wcscmp(param_2,L"\\MD\\upgrade_root.lgu");
          iVar4 = wcscmp((wchar_t *)&DAT_000386c8,L"nng_content");
          iVar5 = wcscmp(param_2,L"\\MD\\navigation_restore.lgu");
          iVar6 = wcscmp(param_2,L"\\MD\\navigation_restore_fat32.lgu");
          local_930 = wcscmp((wchar_t *)&DAT_000386c8,L"nng_restore");
          iVar7 = wcscmp((wchar_t *)&DAT_000386c8,L"patch_first");
          NKDbgPrintfW(L"[Upd Manager][%d] CUR and NEW versions are NOT same [%d][%d]... Restore [%d][%d], bNNGRestoreFile2[%d]\r\n"
                       ,iVar7,iVar4,iVar10,iVar5,local_930,iVar6);
          if ((((iVar10 == 0) && (iVar4 != 0)) ||
              (((iVar5 == 0 || (iVar6 == 0)) && (local_930 != 0)))) || (iVar7 == 0)) {
            FUN_0002a0c4(local_2c);
            return 0;
          }
          if (iVar2 < 1) {
            pwVar8 = L"[Upd Manager] [%d] Old version detected!!! \r\n";
          }
          else {
            pwVar8 = L"[Upd Manager] [%d] New version detected!!! \r\n";
            *(undefined4 *)(param_1 + 0x62c) = 1;
          }
          NKDbgPrintfW(pwVar8,iVar2);
        }
        if ((*(int *)(param_1 + 0x62c) != 0) || (bVar1)) {
          PostMessageW(*(HWND *)(param_1 + 0x630),0x620,0,1);
        }
      }
    }
  }
  if ((*(int *)(param_1 + 0x62c) == 0) && (!bVar1)) {
    uVar9 = 0;
  }
  FUN_0002a0c4(local_2c);
  return uVar9;
}



/* 00017a1c FUN_00017a1c */

/* Boundary evidence: original MIPS .pdata 00017a1c..00017c27. Semantic name remains unreviewed. */

void FUN_00017a1c(int param_1,undefined4 param_2)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_670;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d4;
  memset(awStack_238,0,0x104);
  swprintf_s(awStack_238,0x103,L"%s\\*.*",param_2);
  hFindFile = FindFirstFileW(awStack_238,&local_670);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      if ((local_670.dwFileAttributes & 0x10) == 0) {
        if ((DAT_0003743c != 0xbbd) ||
           ((iVar1 = _wcsicmp((wchar_t *)&local_670.dwReserved1,L"upgrade.lgu"), iVar1 != 0 &&
            (iVar1 = _wcsicmp((wchar_t *)&local_670.dwReserved1,L"firmware.hex"), iVar1 != 0)))) {
          memset(local_670.cFileName + 0x102,0,0x104);
          swprintf_s(local_670.cFileName + 0x102,0x104,L"%s\\%s",param_2,&local_670.dwReserved1);
          *(DWORD *)(param_1 + 0x624) = local_670.nFileSizeLow + *(int *)(param_1 + 0x624);
        }
      }
      else {
        iVar1 = wcscmp((wchar_t *)&local_670.dwReserved1,L".");
        if ((iVar1 != 0) && (iVar1 = wcscmp((wchar_t *)&local_670.dwReserved1,L".."), iVar1 != 0)) {
          memset(local_670.cFileName + 0x102,0,0x104);
          swprintf_s(local_670.cFileName + 0x102,0x103,L"%s\\%s\\",param_2,&local_670.dwReserved1);
          FUN_00017a1c(param_1,local_670.cFileName + 0x102);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_670);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  FUN_0002a0c4(local_30);
  return;
}



/* 00017c28 FUN_00017c28 */

/* Boundary evidence: original MIPS .pdata 00017c28..00017dfb. Semantic name remains unreviewed. */

void FUN_00017c28(undefined4 param_1,LPCWSTR param_2)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_670;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d4;
  NKDbgPrintfW(L"[Upd Manager] [INFO] DoDeleteFile() \r\n");
  memset(awStack_238,0,0x104);
  swprintf_s(awStack_238,0x103,L"%s\\*.*",param_2);
  hFindFile = FindFirstFileW(awStack_238,&local_670);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      if ((local_670.dwFileAttributes & 0x10) == 0) {
        swprintf_s(local_670.cFileName + 0x102,0x104,L"%s\\%s",param_2,&local_670.dwReserved1);
        DeleteFileW(local_670.cFileName + 0x102);
      }
      else {
        iVar1 = wcscmp((wchar_t *)&local_670.dwReserved1,L".");
        if ((iVar1 != 0) && (iVar1 = wcscmp((wchar_t *)&local_670.dwReserved1,L".."), iVar1 != 0)) {
          memset(local_670.cFileName + 0x102,0,0x104);
          swprintf_s(local_670.cFileName + 0x102,0x103,L"%s\\%s\\",param_2,&local_670.dwReserved1);
          FUN_00017c28(param_1,local_670.cFileName + 0x102);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_670);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  RemoveDirectoryW(param_2);
  FUN_0002a0c4(local_30);
  return;
}



/* 00017dfc FUN_00017dfc */

/* Boundary evidence: original MIPS .pdata 00017dfc..000180a7. Semantic name remains unreviewed. */

void FUN_00017dfc(int param_1,LPCWSTR param_2,undefined4 param_3)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  uint uVar3;
  uint uVar4;
  _WIN32_FIND_DATAW local_878;
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d4;
  NKDbgPrintfW(L"[Upd Manager] [INFO] DoMoveFile() \r\n");
  memset(awStack_238,0,0x104);
  swprintf_s(awStack_238,0x103,L"%s\\*.*",param_2);
  hFindFile = FindFirstFileW(awStack_238,&local_878);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      if ((local_878.dwFileAttributes & 0x10) == 0) {
        swprintf_s(local_878.cFileName + 0x102,0x104,L"%s\\%s",param_2,&local_878.dwReserved1);
        swprintf_s(awStack_440,0x104,L"%s\\%s",param_3,&local_878.dwReserved1);
        CopyFileW(local_878.cFileName + 0x102,awStack_440,0);
        *(DWORD *)(param_1 + 0x61c) = *(int *)(param_1 + 0x61c) + local_878.nFileSizeLow;
        DeleteFileW(local_878.cFileName + 0x102);
        uVar3 = *(uint *)(param_1 + 0x624);
        if (uVar3 != 0) {
          uVar4 = (uint)(*(int *)(param_1 + 0x61c) * 10) / uVar3;
          if (uVar3 == 0) {
            trap(0x1c00);
          }
          if (uVar4 != *(uint *)(param_1 + 0x620)) {
            *(uint *)(param_1 + 0x620) = uVar4;
            FUN_00019330(param_1);
          }
        }
      }
      else {
        iVar1 = wcscmp((wchar_t *)&local_878.dwReserved1,L".");
        if ((iVar1 != 0) && (iVar1 = wcscmp((wchar_t *)&local_878.dwReserved1,L".."), iVar1 != 0)) {
          memset(local_878.cFileName + 0x102,0,0x104);
          swprintf_s(local_878.cFileName + 0x102,0x103,L"%s\\%s\\",param_2,&local_878.dwReserved1);
          memset(awStack_440,0,0x104);
          swprintf_s(awStack_440,0x103,L"%s\\%s",param_3,&local_878.dwReserved1);
          CreateDirectoryW(awStack_440,(LPSECURITY_ATTRIBUTES)0x0);
          FUN_00017dfc(param_1,local_878.cFileName + 0x102,awStack_440);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_878);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  RemoveDirectoryW(param_2);
  FUN_0002a0c4(local_30);
  return;
}



/* 000180a8 FUN_000180a8 */

/* Boundary evidence: original MIPS .pdata 000180a8..000182df. Semantic name remains unreviewed. */

void FUN_000180a8(undefined4 param_1,undefined4 param_2,LPCWSTR param_3)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_878;
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d4;
  NKDbgPrintfW(L"[Upd Manager] [INFO] DoCopyFile2() [%s -> %s]\r\n",param_2,param_3);
  memset(awStack_238,0,0x104);
  swprintf_s(awStack_238,0x103,L"%s\\*.*",param_2);
  hFindFile = FindFirstFileW(awStack_238,&local_878);
  if (hFindFile != (HANDLE)0xffffffff) {
    CreateDirectoryW(param_3,(LPSECURITY_ATTRIBUTES)0x0);
    do {
      if ((local_878.dwFileAttributes & 0x10) == 0) {
        swprintf_s(local_878.cFileName + 0x102,0x104,L"%s\\%s",param_2,&local_878.dwReserved1);
        swprintf_s(awStack_440,0x104,L"%s\\%s",param_3,&local_878.dwReserved1);
        CopyFileW(local_878.cFileName + 0x102,awStack_440,0);
      }
      else {
        iVar1 = wcscmp((wchar_t *)&local_878.dwReserved1,L".");
        if ((iVar1 != 0) && (iVar1 = wcscmp((wchar_t *)&local_878.dwReserved1,L".."), iVar1 != 0)) {
          memset(local_878.cFileName + 0x102,0,0x104);
          swprintf_s(local_878.cFileName + 0x102,0x103,L"%s\\%s\\",param_2,&local_878.dwReserved1);
          memset(awStack_440,0,0x104);
          swprintf_s(awStack_440,0x103,L"%s\\%s",param_3,&local_878.dwReserved1);
          FUN_000180a8(param_1,local_878.cFileName + 0x102,awStack_440);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_878);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  FUN_0002a0c4(local_30);
  return;
}



/* 000182e0 FUN_000182e0 */

/* Boundary evidence: original MIPS .pdata 000182e0..0001853f. Semantic name remains unreviewed. */

void FUN_000182e0(undefined4 param_1,LPCWSTR param_2,undefined4 param_3)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_878;
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d4;
  NKDbgPrintfW(L"[%s] [INFO] DoMoveFile22() [%s -> %s]\r\n","UpgradeMgr::DoMoveFile2",param_2,
               param_3);
  memset(awStack_238,0,0x104);
  swprintf_s(awStack_238,0x103,L"%s\\*.*",param_2);
  hFindFile = FindFirstFileW(awStack_238,&local_878);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      if ((local_878.dwFileAttributes & 0x10) == 0) {
        swprintf_s(local_878.cFileName + 0x102,0x104,L"%s\\%s",param_2,&local_878.dwReserved1);
        swprintf_s(awStack_440,0x104,L"%s\\%s",param_3,&local_878.dwReserved1);
        CopyFileW(local_878.cFileName + 0x102,awStack_440,0);
        DeleteFileW(local_878.cFileName + 0x102);
      }
      else {
        iVar1 = wcscmp((wchar_t *)&local_878.dwReserved1,L".");
        if ((iVar1 != 0) && (iVar1 = wcscmp((wchar_t *)&local_878.dwReserved1,L".."), iVar1 != 0)) {
          memset(local_878.cFileName + 0x102,0,0x104);
          swprintf_s(local_878.cFileName + 0x102,0x103,L"%s\\%s\\",param_2,&local_878.dwReserved1);
          memset(awStack_440,0,0x104);
          swprintf_s(awStack_440,0x103,L"%s\\%s",param_3,&local_878.dwReserved1);
          CreateDirectoryW(awStack_440,(LPSECURITY_ATTRIBUTES)0x0);
          FUN_000182e0(param_1,local_878.cFileName + 0x102,awStack_440);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_878);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  RemoveDirectoryW(param_2);
  FUN_0002a0c4(local_30);
  return;
}



/* 00018540 FUN_00018540 */

/* Boundary evidence: original MIPS .pdata 00018540..00018acb. Semantic name remains unreviewed. */

void FUN_00018540(undefined4 param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ pvVar1;
  HDC pHVar2;
  HGDIOBJ pvVar3;
  HFONT h_00;
  HGDIOBJ pvVar4;
  HGDIOBJ pvVar5;
  UINT format;
  tagRECT local_4b0;
  LOGFONTW local_4a0;
  WCHAR aWStack_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d4;
  format = 1;
  if ((DAT_00037410 == 0) || (DAT_00037410 == 0x15)) {
    format = 0x20001;
  }
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  pvVar1 = SelectObject(hdc,h);
  pHVar2 = CreateCompatibleDC(param_2);
  pvVar3 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_comm_0003741c)
                                   [DAT_00038ae4 * 5]);
  pvVar3 = SelectObject(pHVar2,pvVar3);
  BitBlt(hdc,0,0,800,0x1e0,pHVar2,0,0,0xcc0020);
  pvVar3 = SelectObject(pHVar2,pvVar3);
  DeleteObject(pvVar3);
  DeleteDC(pHVar2);
  pHVar2 = CreateCompatibleDC(param_2);
  pvVar3 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_sett_00037420)
                                   [DAT_00038ae4 * 5]);
  pvVar3 = SelectObject(pHVar2,pvVar3);
  BitBlt(hdc,0x7d,0xe8,0x227,2,pHVar2,0,0,0xcc0020);
  pvVar3 = SelectObject(pHVar2,pvVar3);
  DeleteObject(pvVar3);
  DeleteDC(pHVar2);
  memset(&local_4a0,0,0x5c);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xe1e1e1);
  local_4a0.lfHeight = 0x24;
  local_4a0.lfWidth = 0;
  local_4a0.lfEscapement = 0;
  local_4a0.lfOrientation = 0;
  local_4a0.lfWeight = 0;
  local_4a0.lfItalic = '\0';
  local_4a0.lfUnderline = '\0';
  local_4a0.lfStrikeOut = '\0';
  local_4a0.lfCharSet = '\0';
  local_4a0.lfOutPrecision = '\0';
  local_4a0.lfQuality = '\x06';
  local_4a0.lfPitchAndFamily = '\x02';
  local_4a0.lfClipPrecision = '\0';
  wsprintfW(local_4a0.lfFaceName,L"Tahoma");
  h_00 = CreateFontIndirectW(&local_4a0);
  pvVar3 = SelectObject(hdc,h_00);
  wsprintfW(aWStack_440,L"%s : %s",&DAT_000380ac,&DAT_000388d0);
  wsprintfW(aWStack_238,L"%s : %s",&DAT_000380ac,&DAT_000386c8);
  local_4b0.top = 0x15;
  local_4b0.right = 800;
  local_4b0.left = 0;
  local_4b0.bottom = 0x42;
  DrawTextW(hdc,(LPCWSTR)&DAT_000384bc,-1,&local_4b0,format);
  local_4b0.top = 0x87;
  local_4b0.bottom = 0xaf;
  DrawTextW(hdc,(LPCWSTR)&DAT_000382b4,-1,&local_4b0,format);
  local_4b0.top = 0xaf;
  local_4b0.bottom = 0xd7;
  DrawTextW(hdc,aWStack_440,-1,&local_4b0,format);
  local_4b0.top = 0xff;
  local_4b0.bottom = 0x127;
  DrawTextW(hdc,(LPCWSTR)&DAT_00037ea4,-1,&local_4b0,format);
  local_4b0.top = 0x127;
  local_4b0.bottom = 0x14f;
  DrawTextW(hdc,aWStack_238,-1,&local_4b0,format);
  pHVar2 = CreateCompatibleDC(param_2);
  pvVar4 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_comm_00037414)
                                   [DAT_00038ae4 * 5]);
  pvVar4 = SelectObject(pHVar2,pvVar4);
  TransparentImage(hdc,0xd,0x191,0xa2,0x4f,pHVar2,0,0,0xa2,0x4f,0xffff00);
  pvVar5 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_comm_00037418)
                                   [DAT_00038ae4 * 5]);
  pvVar5 = SelectObject(pHVar2,pvVar5);
  TransparentImage(hdc,0xb2,0x191,0x261,0x4f,pHVar2,0,0,0x261,0x4f,0xffff00);
  local_4b0.left = 0xb2;
  local_4b0.right = 0x313;
  local_4b0.top = 0x191;
  local_4b0.bottom = 0x1e0;
  if ((DAT_00037410 == 0) || (DAT_00037410 == 0x15)) {
    DrawTextW(hdc,(LPCWSTR)&DAT_00037c9c,-1,&local_4b0,0x20005);
  }
  else {
    DrawTextW(hdc,(LPCWSTR)&DAT_00037c9c,-1,&local_4b0,5);
  }
  pvVar4 = SelectObject(pHVar2,pvVar4);
  DeleteObject(pvVar4);
  pvVar4 = SelectObject(pHVar2,pvVar5);
  DeleteObject(pvVar4);
  DeleteDC(pHVar2);
  SelectObject(hdc,pvVar3);
  DeleteObject(h_00);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  pvVar1 = SelectObject(hdc,pvVar1);
  DeleteObject(pvVar1);
  DeleteDC(hdc);
  FUN_0002a0c4(local_30);
  return;
}



/* 00018acc FUN_00018acc */

/* Boundary evidence: original MIPS .pdata 00018acc..0001932f. Semantic name remains unreviewed. */

void FUN_00018acc(int param_1,HDC param_2)

{
  HGDIOBJ pvVar1;
  HGDIOBJ h;
  HDC hdc;
  HBITMAP h_00;
  HDC pHVar2;
  HFONT h_01;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  tagRECT local_a8;
  HGDIOBJ local_98;
  HGDIOBJ local_94;
  HGDIOBJ local_90;
  LOGFONTW local_88;
  uint local_2c;
  
  local_2c = DAT_000372d4;
  pvVar1 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_comm_0003741c)
                                   [DAT_00038ae4 * 5]);
  local_90 = pvVar1;
  h = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_popu_00037424)[DAT_00038ae4 * 5]);
  hdc = CreateCompatibleDC(param_2);
  h_00 = CreateCompatibleBitmap(param_2,800,0x1e0);
  local_94 = SelectObject(hdc,h_00);
  pHVar2 = CreateCompatibleDC(param_2);
  pvVar1 = SelectObject(pHVar2,pvVar1);
  BitBlt(hdc,0,0,800,0x1e0,pHVar2,0,0,0xcc0020);
  SelectObject(pHVar2,pvVar1);
  DeleteDC(pHVar2);
  memset(&local_88,0,0x5c);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xe1e1e1);
  local_88.lfHeight = 0x24;
  local_88.lfWidth = 0;
  local_88.lfEscapement = 0;
  local_88.lfOrientation = 0;
  local_88.lfWeight = 0;
  local_88.lfItalic = '\0';
  local_88.lfUnderline = '\0';
  local_88.lfStrikeOut = '\0';
  local_88.lfCharSet = '\0';
  local_88.lfOutPrecision = '\0';
  local_88.lfQuality = '\x06';
  local_88.lfPitchAndFamily = '\x02';
  local_88.lfClipPrecision = '\0';
  wsprintfW(local_88.lfFaceName,L"Tahoma");
  h_01 = CreateFontIndirectW(&local_88);
  pvVar1 = SelectObject(hdc,h_01);
  local_a8.bottom = 0x42;
  local_a8.left = 0;
  local_a8.top = 0x15;
  local_a8.right = 800;
  if ((DAT_00037410 == 0) || (DAT_00037410 == 0x15)) {
    DrawTextW(hdc,(LPCWSTR)&DAT_00037a94,-1,&local_a8,0x20001);
  }
  else {
    DrawTextW(hdc,(LPCWSTR)&DAT_00037a94,-1,&local_a8,1);
  }
  local_a8.top = 0x8b;
  local_a8.bottom = 0x103;
  if ((DAT_00037410 == 0) || (DAT_00037410 == 0x15)) {
    DrawTextW(hdc,(LPCWSTR)&DAT_0003788c,-1,&local_a8,0x20001);
  }
  else {
    DrawTextW(hdc,(LPCWSTR)&DAT_0003788c,-1,&local_a8,1);
  }
  SelectObject(hdc,pvVar1);
  DeleteObject(h_01);
  pHVar2 = CreateCompatibleDC(param_2);
  local_98 = SelectObject(pHVar2,h);
  if (DAT_0003743c == 0xbb9) {
    if (*(uint *)(param_1 + 0x618) < 0x19) {
      iVar5 = 0xd8;
      iVar6 = 10;
      do {
        BitBlt(hdc,iVar5,0x128,0x24,0x12,pHVar2,0,0,0xcc0020);
        iVar6 = iVar6 + -1;
        iVar5 = iVar5 + 0x25;
      } while (iVar6 != 0);
    }
    else {
      uVar4 = 0;
      if (*(uint *)(param_1 + 0x618) / 0x19 != 0) {
        iVar5 = 0xd8;
        do {
          BitBlt(hdc,iVar5,0x128,0x24,0x12,pHVar2,0x24,0,0xcc0020);
          iVar5 = iVar5 + 0x25;
          if (uVar4 < 9) {
            iVar7 = 9 - uVar4;
            iVar6 = iVar5;
            do {
              BitBlt(hdc,iVar6,0x128,0x24,0x12,pHVar2,0,0,0xcc0020);
              iVar7 = iVar7 + -1;
              iVar6 = iVar6 + 0x25;
            } while (iVar7 != 0);
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(param_1 + 0x618) / 0x19);
      }
    }
  }
  else if (DAT_0003743c == 0xbba) {
    uVar4 = 0;
    iVar5 = 0xd8;
    do {
      BitBlt(hdc,iVar5,0x128,0x24,0x12,pHVar2,0x24,0,0xcc0020);
      iVar5 = iVar5 + 0x25;
      if (uVar4 < 9) {
        iVar7 = 9 - uVar4;
        iVar6 = iVar5;
        do {
          BitBlt(hdc,iVar6,0x128,0x24,0x12,pHVar2,0,0,0xcc0020);
          iVar7 = iVar7 + -1;
          iVar6 = iVar6 + 0x25;
        } while (iVar7 != 0);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 5);
  }
  else if (DAT_0003743c == 0xbbb) {
    uVar4 = 0;
    iVar5 = 0xd8;
    do {
      BitBlt(hdc,iVar5,0x128,0x24,0x12,pHVar2,0x24,0,0xcc0020);
      iVar5 = iVar5 + 0x25;
      if (uVar4 < 9) {
        iVar7 = 9 - uVar4;
        iVar6 = iVar5;
        do {
          BitBlt(hdc,iVar6,0x128,0x24,0x12,pHVar2,0,0,0xcc0020);
          iVar7 = iVar7 + -1;
          iVar6 = iVar6 + 0x25;
        } while (iVar7 != 0);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 6);
  }
  else if (DAT_0003743c == 0xbbc) {
    uVar4 = 0;
    iVar5 = 0xd8;
    do {
      BitBlt(hdc,iVar5,0x128,0x24,0x12,pHVar2,0x24,0,0xcc0020);
      iVar5 = iVar5 + 0x25;
      if (uVar4 < 9) {
        iVar7 = 9 - uVar4;
        iVar6 = iVar5;
        do {
          BitBlt(hdc,iVar6,0x128,0x24,0x12,pHVar2,0,0,0xcc0020);
          iVar7 = iVar7 + -1;
          iVar6 = iVar6 + 0x25;
        } while (iVar7 != 0);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 7);
  }
  else if (DAT_0003743c == 0xbbd) {
    uVar4 = 0;
    iVar5 = 0;
    do {
      iVar6 = iVar5;
      BitBlt(hdc,iVar6 + 0xd8,0x128,0x24,0x12,pHVar2,0x24,0,0xcc0020);
      uVar3 = *(uint *)(param_1 + 0x620);
      uVar4 = uVar4 + 1;
      iVar5 = iVar6 + 0x25;
    } while (uVar4 <= uVar3);
    if (uVar3 < 10) {
      iVar6 = iVar6 + 0xfd;
      iVar5 = 10 - uVar3;
      do {
        BitBlt(hdc,iVar6,0x128,0x24,0x12,pHVar2,0,0,0xcc0020);
        iVar5 = iVar5 + -1;
        iVar6 = iVar6 + 0x25;
      } while (iVar5 != 0);
    }
  }
  else if (DAT_0003743c == 0xbbe) {
    iVar5 = 0xd8;
    uVar4 = 10;
    iVar6 = 0xd8;
    iVar7 = 10;
    do {
      BitBlt(hdc,iVar6,0x128,0x24,0x12,pHVar2,0,0,0xcc0020);
      iVar7 = iVar7 + -1;
      iVar6 = iVar6 + 0x25;
    } while (iVar7 != 0);
    if (*(uint *)(param_1 + 0x618) < 0x65) {
      uVar4 = *(uint *)(param_1 + 0x618) / 10;
    }
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      BitBlt(hdc,iVar5,0x128,0x24,0x12,pHVar2,0x24,0,0xcc0020);
      iVar5 = iVar5 + 0x25;
    }
  }
  SelectObject(pHVar2,local_98);
  DeleteDC(pHVar2);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  pvVar1 = SelectObject(hdc,local_94);
  DeleteObject(pvVar1);
  DeleteDC(hdc);
  DeleteObject(local_90);
  DeleteObject(h);
  FUN_0002a0c4(local_2c);
  return;
}



/* 00019330 FUN_00019330 */

/* Boundary evidence: original MIPS .pdata 00019330..000193bf. Semantic name remains unreviewed. */

void FUN_00019330(int param_1)

{
  if (*(int *)(param_1 + 0x628) == 2) {
    NKDbgPrintfW(L" \r\n\r\n ShowSWUpgrade     [2]   \r\n\r\n");
  }
  else {
    *(undefined4 *)(param_1 + 0x628) = 2;
    SetWindowPos(*(HWND *)(param_1 + 0x630),(HWND)0xffffffff,0,0,800,0x1e0,0x10);
    ShowWindow(*(HWND *)(param_1 + 0x630),5);
  }
  InvalidateRect(*(HWND *)(param_1 + 0x630),(RECT *)0x0,0);
  return;
}



/* 000193c0 FUN_000193c0 */

/* Boundary evidence: original MIPS .pdata 000193c0..0001995f. Semantic name remains unreviewed. */

undefined4 FUN_000193c0(int param_1)

{
  int iVar1;
  DWORD DVar2;
  size_t sVar3;
  LONG LVar4;
  int iVar5;
  HANDLE hObject;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  wchar_t *_Str;
  undefined4 *puVar10;
  undefined4 uVar11;
  wchar_t *_Str1;
  undefined1 auStack_888 [8];
  undefined4 local_880;
  undefined4 local_87c;
  int local_860;
  int local_85c;
  uint local_850;
  int local_84c;
  undefined4 local_844;
  int local_840;
  int local_83c;
  int local_838 [4];
  undefined1 auStack_828 [2040];
  uint local_30;
  
  local_30 = DAT_000372d4;
  uVar11 = 0;
  NKDbgPrintfW(L"[Upd Manager] [INFO] CALL ExtractUpdateFile() \r\n");
  _Str1 = (wchar_t *)(param_1 + 0x208);
  do {
    NKDbgPrintfW(L"[Upd Manager] [INFO] Opening LGU File\r\n");
    FUN_0001225c(0x38b48);
    iVar1 = FUN_00011898(&DAT_00038b48,_Str1,auStack_828);
    if (iVar1 != 0) {
      NKDbgPrintfW(L"[Upd Manager] [INFO] LGU Open error : %d  Path(%s)\r\n",iVar1,_Str1);
      (**(code **)(*DAT_000393c4 + 0xc))();
LAB_00019910:
      NKDbgPrintfW(L"[Upd Manager] [INFO] Extract complete... [%d]\r\n",uVar11);
      FUN_0002a0c4(local_30);
      return uVar11;
    }
    local_838[0] = (**(code **)(PTR_PTR_000372dc + 0xc))(&PTR_PTR_000372dc);
    local_838[0] = local_838[0] + 0x10;
    memset(auStack_888,0,0x48);
    local_840 = 0;
    local_83c = 0;
    FUN_000124b0(local_838);
    local_838[1] = 0;
    local_838[2] = 0;
    local_838[3] = 0;
    iVar1 = 0;
    NKDbgPrintfW(L"[Upd Manager] [INFO] Extract start...\r\n");
    DAT_00039460 = 1;
    _Str = (wchar_t *)(param_1 + 0x410);
    if ((DAT_00038b4c == (HANDLE)0x0) ||
       (DVar2 = WaitForSingleObject(DAT_00038b4c,0), DVar2 != 0x102)) {
      memset(&DAT_000393e8,0,0x48);
      DAT_00039430 = 0;
      DAT_00039434 = 0;
      FUN_000124b0(&DAT_00039438);
      DAT_0003943c = 0;
      DAT_00039440 = 0;
      DAT_00039444 = 0;
      if (_Str == (wchar_t *)0x0) {
        sVar3 = 0;
      }
      else {
        sVar3 = wcslen(_Str);
      }
      FUN_00012678(&DAT_000393dc,_Str,sVar3);
      DAT_00039468 = 1;
      DAT_0003946c = 1;
      DAT_00039470 = 0;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00038b58);
      if ((DAT_00038b4c != (HANDLE)0x0) &&
         (DVar2 = WaitForSingleObject(DAT_00038b4c,0), DVar2 == 0x102)) {
LAB_000195ec:
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00038b58);
        uVar7 = 8;
        goto LAB_000195f8;
      }
      EventModify(DAT_00038b94,2);
      EventModify(DAT_00038b98,2);
      DAT_00038b50 = 0;
      DAT_00038b4c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001abfc,&DAT_00038b48,0,
                                  &DAT_00038b54);
      if (DAT_00038b4c == (HANDLE)0x0) goto LAB_000195ec;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00038b58);
      NKDbgPrintfW(L"[Upd Manager] [INFO] SUCCESS - Extract Start\r\n");
      iVar8 = DAT_00037440;
      iVar9 = DAT_00038af8;
      iVar5 = local_83c;
      do {
        if (iVar8 == 1) {
          NKDbgPrintfW(L"g_bUncompresDone abort !!!! ++++++++++++++ \r\n");
          (**(code **)(*DAT_000393c4 + 0xc))();
          puVar10 = (undefined4 *)(local_838[0] + -0x10);
          LVar4 = InterlockedDecrement((LONG *)(local_838[0] + -4));
          if (LVar4 < 1) {
            piVar6 = (int *)*puVar10;
            (**(code **)(*piVar6 + 4))(piVar6,puVar10);
          }
          FUN_0002a0c4(local_30);
          return 0;
        }
        if (iVar9 != 0) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00039448);
          FUN_00012144(auStack_888,&DAT_000393e8);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00039448);
          iVar5 = __fptoli(local_844);
          if (iVar1 != iVar5) {
            NKDbgPrintfW(L"[Upd Manager] [INFO]  g_upgradeflag [%d], g_bUncompresDone [%d], Percent(%d) Current:%I64d   Total:%I64d\r\n"
                         ,DAT_00038af8,DAT_00037440,iVar5,local_850 + local_860,
                         local_84c + local_85c + (uint)(local_850 + local_860 < local_850),local_880
                         ,local_87c);
            InvalidateRect(*(HWND *)(param_1 + 0x630),(RECT *)0x0,0);
            iVar1 = iVar5;
          }
          iVar5 = local_83c;
          *(int *)(param_1 + 0x618) = iVar1;
          if (local_83c != 0) {
            NKDbgPrintfW(L"[Upd Manager] [ERROR] => Extract Error ( 0x%x ) \r\n",local_83c);
            break;
          }
          Sleep(300);
          iVar8 = DAT_00037440;
          iVar9 = DAT_00038af8;
        }
      } while (local_840 == 0);
      if (iVar5 == 0) {
        DAT_00038af8 = 0;
        (**(code **)(*DAT_000393c4 + 0xc))();
        iVar1 = wcscmp(_Str1,L"\\MD\\upgrade.lgu");
        if (iVar1 == 0) {
          hObject = CreateFileW(L"\\Storage Card3\\upgrade\\filecopy_success.bin",0x40000000,0,
                                (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
          CloseHandle(hObject);
        }
        NKDbgPrintfW(L"[Upd Manager] [INFO] File Extract Successfully End\r\n");
        uVar11 = 1;
        puVar10 = (undefined4 *)(local_838[0] + -0x10);
        LVar4 = InterlockedDecrement((LONG *)(local_838[0] + -4));
        if (LVar4 < 1) {
          piVar6 = (int *)*puVar10;
          (**(code **)(*piVar6 + 4))(piVar6,puVar10);
        }
        goto LAB_00019910;
      }
      NKDbgPrintfW(L"[Upd Manager] [ERROR]   : Extract Error ( 0x%x ) \r\n",iVar5);
      iVar1 = local_838[0];
      NKDbgPrintfW(L"[Upd Manager] [ERROR]   : %s \r\n",local_838[0]);
    }
    else {
      uVar7 = 10;
LAB_000195f8:
      NKDbgPrintfW(L"[Upd Manager] [INFO] Start failed.. lgu error code: %d\r\n",uVar7);
      (**(code **)(*DAT_000393c4 + 0xc))();
      iVar1 = local_838[0];
    }
    LVar4 = InterlockedDecrement((LONG *)(iVar1 + -4));
    if (LVar4 < 1) {
      piVar6 = *(int **)(iVar1 + -0x10);
      (**(code **)(*piVar6 + 4))(piVar6,(undefined4 *)(iVar1 + -0x10));
    }
  } while( true );
}



/* 00019960 Unwind@00019960 */

/* Boundary evidence: original MIPS .pdata 00019960..0001998f. Semantic name remains unreviewed. */

void Unwind_00019960(void)

{
  int in_v0;
  
  FUN_000116e8(in_v0 + -0x888);
  return;
}



/* 00019990 FUN_00019990 */

/* Boundary evidence: original MIPS .pdata 00019990..00019d63. Semantic name remains unreviewed. */

undefined4 FUN_00019990(void)

{
  bool bVar1;
  void *_Dst;
  DWORD DVar2;
  HANDLE hFile;
  BOOL BVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  uint uVar6;
  wchar_t *pwVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_70;
  DWORD local_6c;
  void *local_68;
  HANDLE local_64;
  DWORD aDStack_60 [2];
  void *local_58;
  int local_54;
  undefined4 local_50;
  void *local_48;
  int local_44;
  uint local_40;
  undefined1 auStack_38 [4];
  undefined4 local_34;
  int local_30;
  
  local_70 = 0;
  uVar5 = 0;
  local_6c = 0;
  _Dst = malloc(0x10000);
  local_68 = _Dst;
  if (_Dst == (void *)0x0) {
    DVar2 = GetLastError();
    NKDbgPrintfW(L"[AB::NorWrite] write_bin malloc failed %d \r\n",DVar2);
    return 0;
  }
  pwVar7 = L"\\Storage Card3\\upgrade\\booter_standalone.bin";
  hFile = CreateFileW(L"\\Storage Card3\\upgrade\\booter_standalone.bin",0x80000000,1,
                      (LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  local_64 = hFile;
  if (hFile == (HANDLE)0xffffffff) {
    pwVar4 = L"Failed to open file(%s)\r\n";
  }
  else {
    pwVar7 = (wchar_t *)GetFileSize(hFile,(LPDWORD)0x0);
    if (pwVar7 == (wchar_t *)0x0) {
      NKDbgPrintfW(L"The file of size is zero\r\n");
      goto LAB_00019ce0;
    }
    if (pwVar7 < (wchar_t *)0x1ff001) {
      uVar6 = (uint)pwVar7 >> 0x10;
      if (((uint)pwVar7 & 0xffff) != 0) {
        uVar6 = uVar6 + 1;
      }
      NKDbgPrintfW(L"[NORW] %s, Max Sector Size %d \r\n",
                   L"\\Storage Card3\\upgrade\\booter_standalone.bin",uVar6);
      iVar8 = 0;
      iVar10 = -0x40400000;
      do {
        local_34 = 0xbfc00000;
        local_30 = uVar6 << 0x10;
        BVar3 = DeviceIoControl(DAT_0003740c,0,auStack_38,0xc,(LPVOID)0x0,0,aDStack_60,
                                (LPOVERLAPPED)0x0);
        if (BVar3 == 0) {
          NKDbgPrintfW(L"[AB::NorWrite] %d, Erase Fail\r\n",iVar8);
        }
        hFile = local_64;
        _Dst = local_68;
        bVar1 = iVar8 < 5;
        iVar8 = iVar8 + 1;
      } while ((bVar1) && (BVar3 == 0));
      iVar8 = 0;
      if (uVar6 != 0) {
        iVar9 = 100;
        do {
          memset(_Dst,0,0x10000);
          BVar3 = ReadFile(hFile,_Dst,0x10000,&local_6c,(LPOVERLAPPED)0x0);
          if (BVar3 == 0) {
            NKDbgPrintfW(L"Failed to read booter loader\r\n");
            uVar5 = 0;
            goto LAB_00019ce0;
          }
          if (local_6c == 0) {
            pwVar7 = L"Bootloader\'s update is complete\r\n";
            goto LAB_00019cd4;
          }
          if (local_6c < 0x10000) {
            local_48 = _Dst;
            local_40 = local_6c;
            local_44 = iVar10;
            BVar3 = DeviceIoControl(DAT_0003740c,1,&local_48,0xc,(LPVOID)0x0,0,(LPDWORD)&local_68,
                                    (LPOVERLAPPED)0x0);
            if (BVar3 == 0) {
              pwVar7 = L"[NORW] Writing Fail-2\r\n";
              goto LAB_00019c20;
            }
          }
          else {
            local_50 = 0x10000;
            local_58 = _Dst;
            local_54 = iVar10;
            BVar3 = DeviceIoControl(DAT_0003740c,1,&local_58,0xc,(LPVOID)0x0,0,(LPDWORD)&local_64,
                                    (LPOVERLAPPED)0x0);
            if (BVar3 == 0) {
              pwVar7 = L"[NORW] Writing Fail-1\r\n";
LAB_00019c20:
              NKDbgPrintfW(pwVar7);
              return 0;
            }
          }
          if (uVar6 == 0) {
            trap(0x1c00);
          }
          if ((uVar6 == 0xffffffff) && (iVar9 == -0x80000000)) {
            trap(0x1800);
          }
          if (iVar9 / (int)uVar6 != local_70) {
            NKDbgPrintfW(L"[NORW] written status %d%%\r\n");
            local_70 = iVar9 / (int)uVar6;
          }
          iVar8 = iVar8 + 1;
          iVar10 = iVar10 + 0x10000;
          iVar9 = iVar9 + 100;
        } while (iVar8 < (int)uVar6);
      }
      pwVar7 = L"[NORW] end of flash fusing\r\n";
LAB_00019cd4:
      NKDbgPrintfW(pwVar7);
      uVar5 = 1;
      goto LAB_00019ce0;
    }
    pwVar4 = L"The file of size is too big!! dwFileSize %d\r\n";
  }
  NKDbgPrintfW(pwVar4,pwVar7);
LAB_00019ce0:
  free(_Dst);
  if (hFile != (HANDLE)0xffffffff) {
    CloseHandle(hFile);
  }
  return uVar5;
}



/* 00019d64 FUN_00019d64 */

/* Boundary evidence: original MIPS .pdata 00019d64..00019fbb. Semantic name remains unreviewed. */

int FUN_00019d64(int param_1)

{
  bool bVar1;
  bool bVar2;
  HDC hDC;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  hDC = GetDC((HWND)0x0);
  DAT_0003743c = 0xbba;
  if (DAT_0003740c == (HANDLE)0xffffffff) {
    DAT_0003740c = CreateFileW(L"PHM1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (DAT_0003740c != (HANDLE)0xffffffff) {
      pwVar3 = L"[NORW] NOR flash driver\r\n";
      goto LAB_00019e28;
    }
    NKDbgPrintfW(L"[NORW] can\'t open NOR flash driver\r\n");
    bVar2 = false;
  }
  else {
    pwVar3 = L"[NORW] NOR flash driver is already opened\r\n";
LAB_00019e28:
    NKDbgPrintfW(pwVar3);
    bVar2 = true;
  }
  if (*(int *)(param_1 + 0x628) == 1) {
    FUN_00018540(param_1,hDC);
  }
  else if (*(int *)(param_1 + 0x628) == 2) {
    FUN_00018acc(param_1,hDC);
  }
  if (bVar2) {
    DAT_0003743c = 0xbbb;
    if (*(int *)(param_1 + 0x628) == 1) {
      FUN_00018540(param_1,hDC);
    }
    else if (*(int *)(param_1 + 0x628) == 2) {
      FUN_00018acc(param_1,hDC);
    }
    iVar5 = 0;
    do {
      iVar4 = FUN_00019990();
      if (iVar4 == 0) {
        NKDbgPrintfW(L"[NORW] Write bin Fail %d \r\n",iVar5);
      }
      bVar1 = iVar5 < 10;
      iVar5 = iVar5 + 1;
    } while ((bVar1) && (iVar4 == 0));
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      DAT_0003743c = 0xbbc;
      if (*(int *)(param_1 + 0x628) == 1) {
        FUN_00018540(param_1,hDC);
        goto LAB_00019f4c;
      }
      if (*(int *)(param_1 + 0x628) == 2) {
        FUN_00018acc(param_1,hDC);
      }
    }
  }
  else {
LAB_00019f4c:
    if (!bVar2) goto LAB_00019f80;
  }
  if (DAT_0003740c != (HANDLE)0xffffffff) {
    CloseHandle(DAT_0003740c);
    DAT_0003740c = (HANDLE)0xffffffff;
  }
LAB_00019f80:
  ReleaseDC((HWND)0x0,hDC);
  return iVar4;
}



/* 00019fbc FUN_00019fbc */

/* Boundary evidence: original MIPS .pdata 00019fbc..0001a3fb. Semantic name remains unreviewed. */

undefined4 FUN_00019fbc(int param_1,int param_2,int param_3)

{
  HANDLE hObject;
  HANDLE hObject_00;
  int iVar1;
  DWORD DVar2;
  HMODULE hLibModule;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined **ppuVar7;
  undefined4 uVar8;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  uint local_250;
  int local_24c;
  undefined4 local_248;
  undefined1 auStack_244 [64];
  wchar_t awStack_204 [32];
  undefined1 auStack_1c4 [132];
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_128;
  byte local_124;
  undefined4 local_120 [60];
  uint local_30;
  
  local_30 = DAT_000372d4;
  uVar6 = 0;
  local_120[0] = 0xf0;
  local_248 = 0x128;
  local_24c = param_3;
  hObject = (HANDLE)OpenStore(u_DSK1__000373e0);
  if (hObject == (HANDLE)0x0) goto LAB_0001a3c0;
  GetStoreInfo(hObject,local_120);
  ppuVar7 = &PTR_u_PART00_000373ec + param_1;
  hObject_00 = (HANDLE)OpenPartition(hObject,*ppuVar7);
  if (hObject_00 != (HANDLE)0x0) {
    iVar1 = GetPartitionInfo(hObject_00,&local_248);
    uVar5 = (uint)local_124;
    DVar2 = GetLastError();
    uVar8 = local_13c;
    NKDbgPrintfW(L"[%d] - PartitionName[%s]VolumeName[%s], snNumSectors[%d], dwAttributes 0x%04X, bPartType 0x%04X \r\n"
                 ,DVar2,auStack_244,auStack_1c4,local_140,local_13c,local_128,uVar5);
    if (iVar1 == 1) {
      DVar2 = GetLastError();
      NKDbgPrintfW(L"[%s], [%s] [%d][%d]\r\n",auStack_244,auStack_1c4,1,DVar2,uVar8,local_128,uVar5)
      ;
      iVar1 = _wcsicmp(awStack_204,L"FATFSD.DLL");
      if (((iVar1 == 0) || (iVar1 = _wcsicmp(awStack_204,L"EXFAT.DLL"), iVar1 == 0)) &&
         (hLibModule = LoadLibraryW(L"FATUTIL.DLL"), hLibModule != (HMODULE)0x0)) {
        pcVar3 = (code *)GetProcAddressW(hLibModule,L"FormatVolume");
        if (pcVar3 == (code *)0x0) {
LAB_0001a158:
          uVar6 = 0;
        }
        else {
          uVar5 = 0;
          local_250 = 0;
          if ((param_1 == 0) || (param_1 == 3)) {
            local_260 = 0x2000;
          }
          else {
            local_260 = 0x200;
          }
          local_25c = 0x200;
          local_254 = 1;
          local_258 = 0x20;
          if (param_2 != 0) {
            uVar5 = 0x10;
            local_258 = 0x40;
            local_250 = 0x10;
          }
          if (local_24c != 0) {
            local_250 = uVar5 | 2;
            local_254 = 2;
          }
          iVar1 = DismountPartition(hObject_00);
          if (iVar1 != 1) goto LAB_0001a158;
          iVar1 = (*pcVar3)(hObject_00,0,&local_260,0,0);
          if (iVar1 == 0) {
            NKDbgPrintfW(L"SUCCESSED VOLUME FORMAT dwFlags[%04X]dwNumFats[%d]!!!\n",local_250,
                         local_254);
          }
          else {
            DVar2 = GetLastError();
            NKDbgPrintfW(L"FAILED VOLUME FORMAT !!![%d][%d] / dwFlags[%04X]dwNumFats[%d]!!!\n",iVar1
                         ,DVar2,local_250,local_254);
            CloseHandle(hObject_00);
            uVar6 = DeletePartition(hObject,*ppuVar7);
            NKDbgPrintfW(L"!!!===> DeletePartition[%d] <===!!!\n",uVar6);
            uVar6 = CreatePartition(hObject,*ppuVar7,local_140,local_13c);
            NKDbgPrintfW(L"!!!===> CreatePartition[%d] <===!!!\n",uVar6);
            hObject_00 = (HANDLE)OpenPartition(hObject,*ppuVar7);
            if (hObject_00 == (HANDLE)0xffffffff) {
              NKDbgPrintfW(L"Cannot open [%s] partition\n",*ppuVar7);
            }
            else {
              GetPartitionInfo(hObject_00,&local_248);
              uVar6 = DismountPartition(hObject_00);
              NKDbgPrintfW(L"**** DismountPartition[%d]**** \r\n",uVar6);
              uVar6 = FormatPartition(hObject_00);
              NKDbgPrintfW(L"**** FormatPartition[%d]**** \r\n",uVar6);
              iVar1 = (*pcVar3)(hObject_00,0,&local_260,0,0);
              DVar2 = GetLastError();
              NKDbgPrintfW(L"Retry VOLUME FORMAT !!![%d][%d]\n",iVar1,DVar2);
            }
          }
          iVar4 = MountPartition(hObject_00);
          if (iVar4 == 0) {
            DVar2 = GetLastError();
            NKDbgPrintfW(L"Mount Partition Error -- Retry !!![%d][%d]\n",iVar1,DVar2);
            MountPartition(hObject_00);
          }
          uVar6 = 1;
        }
        FreeLibrary(hLibModule);
      }
    }
    CloseHandle(hObject_00);
  }
  CloseHandle(hObject);
LAB_0001a3c0:
  FUN_0002a0c4(local_30);
  return uVar6;
}



/* 0001a3fc FUN_0001a3fc */

void FUN_0001a3fc(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_00034728;
  return;
}



/* 0001a470 FUN_0001a470 */

/* Boundary evidence: original MIPS .pdata 0001a470..0001a4b7. Semantic name remains unreviewed. */

void FUN_0001a470(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  uVar1 = __ll_rem(param_3 - uVar2,(param_4 - ((int)uVar2 >> 0x1f)) - (uint)(param_3 < uVar2),0x400,
                   0);
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}



/* 0001a4b8 FUN_0001a4b8 */

/* Boundary evidence: original MIPS .pdata 0001a4b8..0001a4fb. Semantic name remains unreviewed. */

undefined4 * FUN_0001a4b8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_00034728;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001a4fc FUN_0001a4fc */

uint FUN_0001a4fc(uint param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == (byte *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = ~param_1;
    if (7 < param_3) {
      uVar2 = param_3 >> 3;
      do {
        uVar1 = *(uint *)(&DAT_0002e5e8 + ((*param_2 ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e5e8 + ((param_2[1] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e5e8 + ((param_2[2] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e5e8 + ((param_2[3] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e5e8 + ((param_2[4] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e5e8 + ((param_2[5] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e5e8 + ((param_2[6] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e5e8 + ((param_2[7] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        param_2 = param_2 + 8;
        uVar2 = uVar2 - 1;
        param_3 = param_3 - 8;
      } while (uVar2 != 0);
    }
    for (; param_3 != 0; param_3 = param_3 - 1) {
      uVar1 = *(uint *)(&DAT_0002e5e8 + ((*param_2 ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
      param_2 = param_2 + 1;
    }
    uVar1 = ~uVar1;
  }
  return uVar1;
}



/* 0001a690 FUN_0001a690 */

/* Boundary evidence: original MIPS .pdata 0001a690..0001a843. Semantic name remains unreviewed. */

undefined4 FUN_0001a690(LPCWSTR param_1,int *param_2)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  LPDWORD lpFileSizeHigh;
  undefined4 uVar3;
  DWORD local_20;
  DWORD DStack_1c;
  
  hFile = CreateFileW(param_1,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  uVar3 = 0;
  if (hFile == (HANDLE)0xffffffff) {
    GetLastError();
    uVar3 = 1;
  }
  else {
    BVar1 = ReadFile(hFile,param_2,0x400,&DStack_1c,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      uVar3 = 2;
    }
    if ((*param_2 != 0x31434c55) && (*param_2 != 0x3055474c)) {
      uVar3 = 2;
    }
    if (param_2[1] != 7) {
      uVar3 = 3;
    }
    if (param_2[2] != 0x400) {
      uVar3 = 4;
    }
    local_20 = 0;
    DVar2 = GetFileSize(hFile,&local_20);
    if ((param_2[3] != DVar2) || (param_2[4] != local_20)) {
      lpFileSizeHigh = &local_20;
      uVar3 = 5;
      local_20 = 0;
      GetFileSize(hFile,lpFileSizeHigh);
      FUN_0001aeb8(0x346cc,lpFileSizeHigh,param_2[3],(va_list)param_2[4]);
    }
    CloseHandle(hFile);
  }
  return uVar3;
}



/* 0001a844 FUN_0001a844 */

/* Boundary evidence: original MIPS .pdata 0001a844..0001a93b. Semantic name remains unreviewed. */

void * FUN_0001a844(void *param_1)

{
  undefined4 *puVar1;
  
  *(undefined ***)((int)param_1 + 0x7fc) = &PTR_LAB_00034728;
  *(undefined4 *)((int)param_1 + 0x800) = 0;
  *(undefined4 *)((int)param_1 + 0x804) = 0;
  *(undefined4 *)((int)param_1 + 0x808) = 0;
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0x58);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_0003493c;
    puVar1[0xf] = &PTR_FUN_00034934;
    puVar1[0x10] = 0;
    puVar1[0x11] = 0;
    puVar1[0x12] = 0;
    puVar1[0x13] = 4;
    puVar1[10] = 0xffffffff;
    puVar1[0xb] = 0xffffffff;
    puVar1[2] = 0;
    puVar1[6] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[7] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[1] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[0x14] = 0;
    puVar1[5] = FUN_0001dd24;
  }
  *(undefined4 **)((int)param_1 + 0x7f8) = puVar1;
  memset(param_1,0,0x7f8);
  return param_1;
}



/* 0001a93c Unwind@0001a93c */

/* Boundary evidence: original MIPS .pdata 0001a93c..0001a96f. Semantic name remains unreviewed. */

void Unwind_0001a93c(void)

{
  int *in_v0;
  
  FUN_0001a3fc((undefined4 *)(*in_v0 + 0x7fc));
  return;
}



/* 0001a970 FUN_0001a970 */

/* Boundary evidence: original MIPS .pdata 0001a970..0001a9db. Semantic name remains unreviewed. */

void FUN_0001a970(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x7f8) + 0xc))();
  (**(code **)**(undefined4 **)(param_1 + 0x7f8))();
  *(undefined4 *)(param_1 + 0x7f8) = 0;
  *(undefined ***)(param_1 + 0x7fc) = &PTR_LAB_00034728;
  return;
}



/* 0001a9dc Unwind@0001a9dc */

/* Boundary evidence: original MIPS .pdata 0001a9dc..0001aa0f. Semantic name remains unreviewed. */

void Unwind_0001a9dc(void)

{
  int *in_v0;
  
  FUN_0001a3fc((undefined4 *)(*in_v0 + 0x7fc));
  return;
}



/* 0001aa10 FUN_0001aa10 */

/* Boundary evidence: original MIPS .pdata 0001aa10..0001ab1f. Semantic name remains unreviewed. */

int FUN_0001aa10(int *param_1,LPCWSTR param_2)

{
  int iVar1;
  
  (**(code **)(*(int *)param_1[0x1fe] + 0xc))();
  iVar1 = FUN_0001a690(param_2,param_1);
  if (iVar1 == 0) {
    param_1[0x200] = 0;
    param_1[0x201] = 0;
    param_1[0x202] = 0;
    param_1[0x200] = param_1[5];
    param_1[0x202] = 0x400;
    (**(code **)(*(int *)param_1[0x1fe] + 0x60))();
    iVar1 = (**(code **)(*(int *)param_1[0x1fe] + 4))((int *)param_1[0x1fe],param_2,&UNK_0003471c);
    if (iVar1 == 0) {
      iVar1 = 6;
    }
    else {
      iVar1 = (**(code **)(*(int *)param_1[0x1fe] + 0x50))();
      if (iVar1 != 0x100) {
        return 0;
      }
      iVar1 = 0xb;
    }
  }
  (**(code **)(*(int *)param_1[0x1fe] + 0xc))();
  return iVar1;
}



/* 0001ab20 FUN_0001ab20 */

/* Boundary evidence: original MIPS .pdata 0001ab20..0001ab6b. Semantic name remains unreviewed. */

undefined4 * FUN_0001ab20(undefined4 *param_1,uint param_2)

{
  FUN_0001ab6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001ab6c FUN_0001ab6c */

/* Boundary evidence: original MIPS .pdata 0001ab6c..0001abfb. Semantic name remains unreviewed. */

void FUN_0001ab6c(undefined4 *param_1)

{
  HANDLE hHandle;
  
  *param_1 = &PTR_LAB_00034768;
  hHandle = (HANDLE)InterlockedExchange(param_1 + 1,0);
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
    CloseHandle(hHandle);
  }
  FUN_0001ade8(param_1 + 0x19);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 9));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



/* 0001abfc FUN_0001abfc */

/* Boundary evidence: original MIPS .pdata 0001abfc..0001aca7. Semantic name remains unreviewed. */

undefined4 FUN_0001abfc(undefined4 *param_1)

{
  HMODULE pHVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = -0x7fffbffb;
  pHVar1 = GetModuleHandleW(L"ole32.dll");
  if ((pHVar1 != (HMODULE)0x0) &&
     (pcVar2 = (code *)GetProcAddressW(pHVar1,L"CoInitializeEx"), pcVar2 != (code *)0x0)) {
    iVar4 = (*pcVar2)(0,4);
  }
  uVar3 = (**(code **)*param_1)(param_1,param_1[2]);
  if (-1 < iVar4) {
    CoUninitialize();
  }
  return uVar3;
}



/* 0001aca8 FUN_0001aca8 */

/* Boundary evidence: original MIPS .pdata 0001aca8..0001ade7. Semantic name remains unreviewed. */

undefined4 FUN_0001aca8(int param_1)

{
  DWORD DVar1;
  HANDLE hHandle;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *in_stack_00000014;
  
  hHandle = *(HANDLE *)(param_1 + 0x54);
  *in_stack_00000014 = 0;
  DVar1 = WaitForSingleObject(hHandle,0xffffffff);
  if (DVar1 == 0x102) {
    *in_stack_00000014 = 2;
  }
  else {
    EventModify(*(undefined4 *)(param_1 + 0x50),2);
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x10);
    EnterCriticalSection(lpCriticalSection);
    if ((*(HANDLE *)(param_1 + 4) != (HANDLE)0x0) &&
       (DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 4),0), DVar1 == 0x102)) {
      *(undefined4 *)(param_1 + 0x58) = 1;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x60) = 0;
      EventModify(*(undefined4 *)(param_1 + 0x4c),3);
      do {
        DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x50),1000);
        if (DVar1 != 0x102) {
          EventModify(*(undefined4 *)(param_1 + 0x50),2);
          uVar2 = *(undefined4 *)(param_1 + 0x7c);
          goto LAB_0001ad9c;
        }
      } while ((*(HANDLE *)(param_1 + 4) != (HANDLE)0x0) &&
              (DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 4),0), DVar1 == 0x102));
      uVar2 = 0x80004005;
LAB_0001ad9c:
      LeaveCriticalSection(lpCriticalSection);
      return uVar2;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0x80004005;
}



/* 0001ade8 FUN_0001ade8 */

/* Boundary evidence: original MIPS .pdata 0001ade8..0001ae7f. Semantic name remains unreviewed. */

void FUN_0001ade8(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = param_1[2];
  do {
    if (iVar2 == 0) {
LAB_0001ae44:
      *param_1 = 0;
      param_1[1] = 0;
      param_1[4] = 0;
      puVar1 = (void *)param_1[3];
      if ((void *)param_1[3] != (void *)0x0) {
        do {
          pvVar3 = (void *)*puVar1;
          free(puVar1);
          puVar1 = pvVar3;
        } while (pvVar3 != (void *)0x0);
        param_1[3] = 0;
      }
      return;
    }
    puVar1 = (undefined4 *)*param_1;
    if (puVar1 == (undefined4 *)0x0) {
      FUN_00011314(0x80004005);
      goto LAB_0001ae44;
    }
    *param_1 = *puVar1;
    FUN_0001ae80((int)param_1,puVar1);
    iVar2 = param_1[2];
  } while( true );
}



/* 0001ae80 FUN_0001ae80 */

/* Boundary evidence: original MIPS .pdata 0001ae80..0001aeb7. Semantic name remains unreviewed. */

void FUN_0001ae80(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 **)(param_1 + 0x10) = param_2;
  iVar1 = *(int *)(param_1 + 8) + -1;
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_0001ade8((undefined4 *)param_1);
  }
  return;
}



/* 0001aeb8 FUN_0001aeb8 */

/* Boundary evidence: original MIPS .pdata 0001aeb8..0001b187. Semantic name remains unreviewed. */

void FUN_0001aeb8(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  LONG LVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  undefined4 local_res4;
  undefined4 local_res8;
  va_list local_resc;
  FILE *local_24c0;
  wchar_t *local_24bc;
  _SYSTEMTIME local_24b8;
  undefined1 *local_24a8;
  undefined1 auStack_24a4 [132];
  char acStack_2420 [1024];
  wchar_t awStack_2020 [4096];
  uint local_20;
  
  local_20 = DAT_000372d4;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf(awStack_2020,param_1,(wchar_t *)&local_res4,param_4);
  local_24a8 = auStack_24a4;
  FUN_0001b214((int *)&local_24a8,awStack_2020);
  iVar1 = (**(code **)(PTR_PTR_000372dc + 0xc))(&PTR_PTR_000372dc);
  local_24bc = (wchar_t *)(iVar1 + 0x10);
  GetLocalTime(&local_24b8);
  sprintf_s(acStack_2420,0x400,"%d-%02d-%02d %02d-%02d-%02d [%s]",(uint)local_24b8.wYear,
            (uint)local_24b8.wMonth,(uint)local_24b8.wDay,(uint)local_24b8.wHour,
            (uint)local_24b8.wMinute,(uint)local_24b8.wSecond,&DAT_0002ed24);
  uVar4 = (uint)local_24b8.wDay;
  FUN_0001b37c((int *)&local_24bc,L"%s\\ark_log%04d%02d%02d.txt",L"\\MD\\",(uint)local_24b8.wYear);
  pwVar6 = local_24bc;
  _wfopen_s(&local_24c0,local_24bc,L"a+");
  if (local_24c0 == (FILE *)0x0) {
    FUN_0001b37c((int *)&local_24bc,L"%s\\ark_log%04d%02d%02d.txt",L"\\Hard Disk\\",
                 (uint)local_24b8.wYear);
    pwVar6 = local_24bc;
    _wfopen_s(&local_24c0,local_24bc,L"a+");
    if (local_24c0 == (FILE *)0x0) {
      FUN_0001b37c((int *)&local_24bc,L"%s\\ark_log%04d%02d%02d.txt",L"\\Storage Card2\\",
                   (uint)local_24b8.wYear);
      pwVar6 = local_24bc;
      _wfopen_s(&local_24c0,local_24bc,L"a+");
      if (local_24c0 == (FILE *)0x0) {
        FUN_00012324((int *)&local_24bc);
        if (local_24a8 != auStack_24a4) {
          free(local_24a8);
        }
        goto LAB_0001b15c;
      }
    }
    LVar2 = InterlockedDecrement((LONG *)(pwVar6 + -2));
    if (LVar2 < 1) {
      piVar5 = *(int **)(pwVar6 + -8);
      (**(code **)(*piVar5 + 4))(piVar5,pwVar6 + -8);
    }
  }
  else {
    uVar3 = __GetUserKData(0xc);
    fprintf(local_24c0,"%s %s (PID:%d)\n",acStack_2420,local_24a8,uVar3,uVar4);
    fflush(local_24c0);
    fclose(local_24c0);
    pwVar7 = pwVar6 + -8;
    LVar2 = InterlockedDecrement((LONG *)(pwVar6 + -2));
    if (LVar2 < 1) {
      piVar5 = *(int **)pwVar7;
      (**(code **)(*piVar5 + 4))(piVar5,pwVar7);
    }
  }
  if (local_24a8 != auStack_24a4) {
    free(local_24a8);
  }
LAB_0001b15c:
  FUN_0002a0c4(local_20);
  return;
}



/* 0001b188 Unwind@0001b188 */

/* Boundary evidence: original MIPS .pdata 0001b188..0001b1b7. Semantic name remains unreviewed. */

void Unwind_0001b188(void)

{
  int in_v0;
  
  FUN_0001b1e8((undefined4 *)(in_v0 + -0x24a8));
  return;
}



/* 0001b1b8 Unwind@0001b1b8 */

/* Boundary evidence: original MIPS .pdata 0001b1b8..0001b1e7. Semantic name remains unreviewed. */

void Unwind_0001b1b8(void)

{
  int in_v0;
  
  FUN_00012324((int *)(in_v0 + -0x24bc));
  return;
}



/* 0001b1e8 FUN_0001b1e8 */

/* Boundary evidence: original MIPS .pdata 0001b1e8..0001b213. Semantic name remains unreviewed. */

void FUN_0001b1e8(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != param_1 + 1) {
    free((undefined4 *)*param_1);
  }
  return;
}



/* 0001b214 FUN_0001b214 */

/* Boundary evidence: original MIPS .pdata 0001b214..0001b37b. Semantic name remains unreviewed. */

void FUN_0001b214(int *param_1,LPCWSTR param_2)

{
  WCHAR WVar1;
  int iVar2;
  DWORD DVar3;
  size_t cbMultiByte;
  LPCWSTR pWVar4;
  uint cchWideChar;
  
  pWVar4 = param_2;
  if (param_2 == (LPCWSTR)0x0) {
    *param_1 = 0;
  }
  else {
    do {
      WVar1 = *pWVar4;
      pWVar4 = pWVar4 + 1;
    } while (WVar1 != L'\0');
    cchWideChar = (uint)((int)pWVar4 - (int)param_2) >> 1;
    FUN_0001b3a4(param_1,cchWideChar << 2,param_1 + 1);
    iVar2 = WideCharToMultiByte(0x3b5,0,param_2,cchWideChar,(LPSTR)*param_1,cchWideChar << 2,
                                (LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      if (DVar3 == 0x7a) {
        cbMultiByte = WideCharToMultiByte(0x3b5,0,param_2,cchWideChar,(LPSTR)0x0,0,(LPCSTR)0x0,
                                          (LPBOOL)0x0);
        FUN_0001b3a4(param_1,cbMultiByte,param_1 + 1);
        iVar2 = WideCharToMultiByte(0x3b5,0,param_2,cchWideChar,(LPSTR)*param_1,cbMultiByte,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar2 != 0) {
          return;
        }
      }
      FUN_0001b714();
    }
  }
  return;
}



/* 0001b37c FUN_0001b37c */

/* Boundary evidence: original MIPS .pdata 0001b37c..0001b3a3. Semantic name remains unreviewed. */

void FUN_0001b37c(int *param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res8 = param_3;
  local_resc = param_4;
  FUN_0001b488(param_1,param_2,(va_list)&local_res8);
  return;
}



/* 0001b3a4 FUN_0001b3a4 */

/* Boundary evidence: original MIPS .pdata 0001b3a4..0001b487. Semantic name remains unreviewed. */

void FUN_0001b3a4(int *param_1,size_t param_2,void *param_3)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
    FUN_00011314(0x80070057);
  }
  if ((int)param_2 < 0) {
    FUN_00011314(0x80070057);
  }
  if (param_3 == (void *)0x0) {
    FUN_00011314(0x80070057);
  }
  pvVar1 = (void *)*param_1;
  if (pvVar1 == param_3) {
    if (0x80 < (int)param_2) {
      pvVar1 = calloc(param_2,1);
      *param_1 = (int)pvVar1;
      goto LAB_0001b440;
    }
  }
  else {
    if (0x80 < (int)param_2) {
      pvVar1 = _recalloc(pvVar1,param_2,1);
      if (pvVar1 == (void *)0x0) {
        pvVar1 = (void *)FUN_00011314(0x8007000e);
      }
      *param_1 = (int)pvVar1;
      goto LAB_0001b440;
    }
    free(pvVar1);
  }
  *param_1 = (int)param_3;
LAB_0001b440:
  if (*param_1 == 0) {
    FUN_00011314(0x8007000e);
  }
  return;
}



/* 0001b488 FUN_0001b488 */

/* Boundary evidence: original MIPS .pdata 0001b488..0001b59f. Semantic name remains unreviewed. */

void FUN_0001b488(int *param_1,wchar_t *param_2,va_list param_3)

{
  int iVar1;
  wchar_t awStack_828 [1024];
  undefined2 local_28;
  uint local_20;
  
  local_20 = DAT_000372d4;
  if (param_2 == (wchar_t *)0x0) {
    FUN_00011314(0x80070057);
  }
  iVar1 = _vsnwprintf(awStack_828,0x400,param_2,param_3);
  if (iVar1 < 0) {
    iVar1 = 0x400;
  }
  local_28 = 0;
  if ((int)(1U - *(int *)(*param_1 + -4) | *(int *)(*param_1 + -8) - iVar1) < 0) {
    FUN_00012888(param_1,iVar1);
  }
  FUN_0001b5a0((wchar_t *)*param_1,iVar1 + 1,param_2,param_3);
  if ((iVar1 < 0) || (*(int *)(*param_1 + -8) < iVar1)) {
    FUN_00011314(0x80070057);
  }
  else {
    *(int *)(*param_1 + -0xc) = iVar1;
    *(undefined2 *)(iVar1 * 2 + *param_1) = 0;
    FUN_0002a0c4(local_20);
  }
  return;
}



/* 0001b5a0 FUN_0001b5a0 */

/* Boundary evidence: original MIPS .pdata 0001b5a0..0001b687. Semantic name remains unreviewed. */

uint FUN_0001b5a0(wchar_t *param_1,uint param_2,wchar_t *param_3,va_list param_4)

{
  wchar_t wVar1;
  uint uVar2;
  errno_t eVar3;
  wchar_t *pwVar4;
  wchar_t local_820 [1024];
  undefined2 local_20;
  uint local_18;
  
  local_18 = DAT_000372d4;
  uVar2 = _vsnwprintf(local_820,0x400,param_3,param_4);
  if ((int)uVar2 < 0) {
    uVar2 = 0x400;
  }
  local_20 = 0;
  if (0x400 < (int)uVar2) {
    FUN_00011314(0x80004005);
  }
  if (param_2 <= uVar2) {
    FUN_00011314(0x80070057);
  }
  pwVar4 = local_820;
  do {
    wVar1 = *pwVar4;
    pwVar4 = pwVar4 + 1;
  } while (wVar1 != L'\0');
  if (param_2 <= ((int)pwVar4 - (int)local_820 >> 1) - 1U) {
    FUN_00011314(0x80070057);
  }
  eVar3 = wcscpy_s(param_1,param_2,local_820);
  FUN_0001b688(eVar3);
  FUN_0002a0c4(local_18);
  return uVar2;
}



/* 0001b688 FUN_0001b688 */

/* Boundary evidence: original MIPS .pdata 0001b688..0001b713. Semantic name remains unreviewed. */

undefined4 FUN_0001b688(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x17) {
    if (param_1 == 0x16) goto LAB_0001b6fc;
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 != 0xc) goto LAB_0001b6e0;
    param_1 = -0x7ff8fff2;
    FUN_00011314(0x8007000e);
  }
  if (param_1 != 0x22) {
    if (param_1 == 0x50) {
      return 0x50;
    }
LAB_0001b6e0:
    uVar1 = 0x80004005;
    FUN_00011314(0x80004005);
    return uVar1;
  }
LAB_0001b6fc:
  uVar1 = FUN_00011314(0x80070057);
  return uVar1;
}



/* 0001b714 FUN_0001b714 */

/* Boundary evidence: original MIPS .pdata 0001b714..0001b757. Semantic name remains unreviewed. */

void FUN_0001b714(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  FUN_00011314(DVar1);
  return;
}



/* 0001b778 FUN_0001b778 */

/* Boundary evidence: original MIPS .pdata 0001b778..0001b7f7. Semantic name remains unreviewed. */

undefined4 FUN_0001b778(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,&DAT_0002e1d8,0x10);
  if (iVar1 == 0) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    return 0;
  }
  return 0x80004002;
}



/* 0001b7f8 FUN_0001b7f8 */

/* Boundary evidence: original MIPS .pdata 0001b7f8..0001b86b. Semantic name remains unreviewed. */

LONG FUN_0001b7f8(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 != 0) {
    return param_1[1];
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x28))(param_1,1);
  }
  return 0;
}



/* 0001b86c FUN_0001b86c */

/* Boundary evidence: original MIPS .pdata 0001b86c..0001b89b. Semantic name remains unreviewed. */

void FUN_0001b86c(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  (**(code **)**(undefined4 **)(param_1 + 8))();
  return;
}



/* 0001b89c FUN_0001b89c */

/* Boundary evidence: original MIPS .pdata 0001b89c..0001b923. Semantic name remains unreviewed. */

undefined4 FUN_0001b89c(int param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 4))(*(int **)(param_1 + 8),param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (param_4 != (uint *)0x0) {
      *param_4 = param_3;
    }
    uVar3 = param_3 + *(int *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x10) = uVar3;
    uVar2 = 1;
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (uint)(uVar3 < param_3);
  }
  return uVar2;
}



/* 0001b924 FUN_0001b924 */

/* Boundary evidence: original MIPS .pdata 0001b924..0001b94b. Semantic name remains unreviewed. */

void FUN_0001b924(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))();
  return;
}



/* 0001b94c FUN_0001b94c */

/* Boundary evidence: original MIPS .pdata 0001b94c..0001b973. Semantic name remains unreviewed. */

void FUN_0001b94c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 0xc))();
  return;
}



/* 0001b988 FUN_0001b988 */

/* Boundary evidence: original MIPS .pdata 0001b988..0001b9e7. Semantic name remains unreviewed. */

undefined4 * FUN_0001b988(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000349a0;
  (**(code **)(*(int *)param_1[2] + 8))();
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001b9e8 FUN_0001b9e8 */

/* Boundary evidence: original MIPS .pdata 0001b9e8..0001ba93. Semantic name remains unreviewed. */

int * FUN_0001b9e8(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)__2_YAPAXI_Z(0x18);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    *piVar1 = (int)&PTR_FUN_000349a0;
    piVar1[2] = param_2;
    piVar1[4] = 0;
    piVar1[5] = 0;
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_1);
  if (iVar2 == 0) {
    __3_YAXPAX_Z();
    piVar1 = (int *)0x0;
  }
  else {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return piVar1;
}



/* 0001ba94 FUN_0001ba94 */

/* Boundary evidence: original MIPS .pdata 0001ba94..0001bae7. Semantic name remains unreviewed. */

void FUN_0001ba94(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00034934;
  FUN_0001db4c((int)param_1,0,param_1[2]);
  __3_YAXPAX_Z(param_1[3]);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}



/* 0001bae8 FUN_0001bae8 */

/* Boundary evidence: original MIPS .pdata 0001bae8..0001bb0b. Semantic name remains unreviewed. */

void FUN_0001bae8(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_0001bb0c(param_1);
  }
  return;
}



/* 0001bb0c FUN_0001bb0c */

/* Boundary evidence: original MIPS .pdata 0001bb0c..0001bba7. Semantic name remains unreviewed. */

undefined4 * FUN_0001bb0c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0003493c;
  FUN_0001ca78((int)param_1);
  param_1[0xf] = &PTR_FUN_00034934;
  FUN_0001db4c((int)(param_1 + 0xf),0,param_1[0x11]);
  __3_YAXPAX_Z(param_1[0x12]);
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  __3_YAXPAX_Z(param_1);
  return param_1;
}



/* 0001bba8 Unwind@0001bba8 */

/* Boundary evidence: original MIPS .pdata 0001bba8..0001bbdb. Semantic name remains unreviewed. */

void Unwind_0001bba8(void)

{
  int *in_v0;
  
  FUN_0001ba94((undefined4 *)(*in_v0 + 0x3c));
  return;
}



/* 0001bbdc FUN_0001bbdc */

/* Boundary evidence: original MIPS .pdata 0001bbdc..0001beef. Semantic name remains unreviewed. */

int FUN_0001bbdc(undefined4 param_1,int *param_2,wchar_t *param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  char local_460;
  char local_45f;
  char local_45e;
  char local_45d;
  char local_45c;
  short local_45b;
  char acStack_448 [1056];
  uint local_28;
  
  local_28 = DAT_000372d4;
  (**(code **)(*param_2 + 0x20))(param_2);
  iVar1 = (**(code **)(*param_2 + 0x14))(param_2,&local_460,0x14);
  if (iVar1 == 0) {
LAB_0001bee0:
    FUN_0002a0c4(local_28);
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0001bfd8(param_1,&local_460);
    if (iVar1 == 0) {
      if ((local_460 != 'M') || (local_45f != 'Z')) {
        if (param_3 != (wchar_t *)0x0) {
          iVar1 = _wcsnicmp(param_3,L".tar",4);
          if (iVar1 == 0) {
            FUN_0002a0c4(local_28);
            return 7;
          }
          iVar1 = _wcsnicmp(param_3,L".iso",4);
          if (((((iVar1 == 0) && (lVar3 = (**(code **)(*param_2 + 0x1c))(param_2), lVar3 == 0x8000))
               && (iVar1 = (**(code **)(*param_2 + 0x14))(param_2,&local_460,0x14), iVar1 != 0)) &&
              (((local_460 == '\x01' && (local_45f == 'C')) &&
               ((local_45e == 'D' && ((local_45d == '0' && (local_45c == '0')))))))) &&
             ((char)local_45b == '1')) {
            FUN_0002a0c4(local_28);
            return 9;
          }
          iVar1 = _wcsnicmp(param_3,L".001",4);
          if (iVar1 == 0) goto LAB_0001bc94;
        }
        uVar4 = 0;
        (**(code **)(*param_2 + 0x1c))(param_2);
        iVar1 = (**(code **)(*param_2 + 0x14))(param_2,acStack_448,0x41e,*param_2,uVar4);
        if (iVar1 != 0) {
          iVar2 = 0;
          do {
            iVar1 = FUN_0001bfd8(param_1,acStack_448 + iVar2);
            if (iVar1 != 0) goto LAB_0001bce8;
            iVar2 = iVar2 + 1;
          } while (iVar2 < 0x40a);
        }
        goto LAB_0001bee0;
      }
      iVar1 = FUN_0001c484(param_1,param_2);
    }
    else if (iVar1 == 6) {
      if ((param_3 != (wchar_t *)0x0) && (iVar2 = _wcsnicmp(param_3,L".001",4), iVar2 == 0)) {
LAB_0001bc94:
        FUN_0002a0c4(local_28);
        return 10;
      }
    }
    else if (((iVar1 == 4) && (local_45b == 7)) &&
            (iVar2 = FUN_0001bef0((int)&local_460,param_3), iVar2 != 0)) {
      iVar1 = 5;
    }
LAB_0001bce8:
    FUN_0002a0c4(local_28);
  }
  return iVar1;
}



/* 0001bef0 FUN_0001bef0 */

undefined4 FUN_0001bef0(int param_1,short *param_2)

{
  ushort uVar1;
  
  if ((*(char *)(param_1 + 9) == 's') && (uVar1 = *(ushort *)(param_1 + 10), (uVar1 & 1) != 0)) {
    if ((uVar1 & 0x10) == 0) {
      if ((((param_2 != (short *)0x0) && (*param_2 == 0x2e)) &&
          ((param_2[1] == 0x52 || (param_2[1] == 0x72)))) &&
         ((((0x2f < (ushort)param_2[2] && ((ushort)param_2[2] < 0x3a)) &&
           (0x2f < (ushort)param_2[3])) && (((ushort)param_2[3] < 0x3a && (param_2[4] == 0)))))) {
        return 1;
      }
    }
    else if ((uVar1 & 0x100) == 0) {
      return 1;
    }
  }
  return 0;
}



/* 0001bfd8 FUN_0001bfd8 */

/* Boundary evidence: original MIPS .pdata 0001bfd8..0001c483. Semantic name remains unreviewed. */

undefined4 FUN_0001bfd8(undefined4 param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  uint local_20;
  
  local_20 = DAT_000372d4;
  cVar1 = *param_2;
  uVar4 = 4;
  if (((((((cVar1 == 'P') && (param_2[1] == 'K')) && (param_2[2] == '\x03')) &&
        (param_2[3] == '\x04')) ||
       (((cVar1 == 'P' && (param_2[1] == 'K')) && ((param_2[2] == '\x05' && (param_2[3] == '\x06')))
        ))) || (((cVar1 == 'P' && (param_2[1] == 'K')) &&
                ((param_2[2] == '\a' && (param_2[3] == '\b')))))) ||
     (((((cVar1 == 'P' && (param_2[1] == 'K')) && (param_2[2] == '0')) &&
       ((param_2[3] == '0' && (param_2[4] == 'P')))) &&
      ((param_2[5] == 'K' && ((param_2[6] == '\x03' && (param_2[7] == '\x04')))))))) {
    FUN_0002a0c4(DAT_000372d4);
    uVar4 = 1;
  }
  else if ((((cVar1 == 'A') && (param_2[1] == 'L')) && (param_2[2] == 'Z')) &&
          (param_2[3] == '\x01')) {
    FUN_0002a0c4(DAT_000372d4);
    uVar4 = 2;
  }
  else if (((cVar1 == 'R') && (param_2[1] == 'a')) && ((param_2[2] == 'r' && (param_2[3] == '!'))))
  {
    FUN_0002a0c4(DAT_000372d4);
  }
  else if (((cVar1 == '7') && (param_2[1] == 'z')) &&
          ((param_2[2] == -0x44 &&
           (((param_2[3] == -0x51 && (param_2[4] == '\'')) && (param_2[5] == '\x1c')))))) {
    FUN_0002a0c4(DAT_000372d4);
    uVar4 = 6;
  }
  else if (((cVar1 == 'H') && (param_2[1] == 'V')) && ((param_2[2] == '3' && (param_2[3] == '0'))))
  {
    FUN_0002a0c4(DAT_000372d4);
    uVar4 = 0xb;
  }
  else {
    cVar2 = param_2[2];
    if ((((cVar2 == '-') && (param_2[3] == 'l')) && (param_2[4] == 'h')) && (param_2[6] == '-')) {
      FUN_0002a0c4(DAT_000372d4);
      uVar4 = 3;
    }
    else if ((((cVar1 == 'M') && (param_2[1] == 'S')) && (cVar2 == 'C')) && (param_2[3] == 'F')) {
      FUN_0002a0c4(DAT_000372d4);
      uVar4 = 8;
    }
    else if (((cVar1 == '\x1f') && (param_2[1] == -0x75)) && (cVar2 == '\b')) {
      FUN_0002a0c4(DAT_000372d4);
      uVar4 = 0xc;
    }
    else {
      if (cVar1 == 'B') {
        if ((param_2[1] == 'Z') && (cVar2 == 'h')) {
          FUN_0002a0c4(DAT_000372d4);
          return 0xd;
        }
        if (((param_2[1] == 'H') && (cVar2 == '\x05')) && (param_2[3] == '\a')) {
          FUN_0002a0c4(DAT_000372d4);
          return 0xf;
        }
      }
      if (((cVar1 == 'E') && (param_2[1] == 'G')) && ((cVar2 == 'G' && (param_2[3] == 'A')))) {
        FUN_0002a0c4(DAT_000372d4);
        uVar4 = 0x10;
      }
      else {
        local_30 = 0xef;
        local_2f = 0xbe;
        local_2e = 0xad;
        local_2d = 0xde;
        local_2b = 0x75;
        local_27 = 0x6f;
        local_2c = 0x4e;
        local_2a = 0x6c;
        local_29 = 0x6c;
        local_28 = 0x73;
        local_26 = 0x66;
        local_25 = 0x74;
        local_24 = 0x49;
        local_23 = 0x6e;
        local_22 = 0x73;
        local_21 = 0x74;
        iVar3 = memcmp(param_2,&local_30,0x10);
        if (iVar3 == 0) {
          FUN_0002a0c4(local_20);
          uVar4 = 0xe;
        }
        else {
          FUN_0002a0c4(local_20);
          uVar4 = 0;
        }
      }
    }
  }
  return uVar4;
}



/* 0001c484 FUN_0001c484 */

/* WARNING: Removing unreachable block (ram,0x0001c50c) */
/* Boundary evidence: original MIPS .pdata 0001c484..0001c5c7. Semantic name remains unreviewed. */

int FUN_0001c484(undefined4 param_1,int *param_2)

{
  void *_Memory;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  (**(code **)(*param_2 + 0x1c))(param_2,param_2,0,0,0);
  iVar3 = 0x96000;
  iVar4 = 0;
  _Memory = malloc(0x96000);
  if (_Memory == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    lVar5 = (**(code **)(*param_2 + 0x24))(param_2);
    if (lVar5 < 0x96001) {
      iVar3 = (**(code **)(*param_2 + 0x24))(param_2);
    }
    iVar2 = (**(code **)(*param_2 + 0x14))(param_2,_Memory,iVar3);
    iVar1 = iVar4;
    if (iVar2 != 0) {
      iVar2 = 0;
      if (0 < iVar3 + -0x15) {
        do {
          iVar1 = FUN_0001bfd8(param_1,(char *)(iVar2 + (int)_Memory));
          if (iVar1 != 0) break;
          iVar2 = iVar2 + 1;
          iVar1 = iVar4;
        } while (iVar2 < iVar3 + -0x15);
      }
    }
    free(_Memory);
  }
  return iVar1;
}



/* 0001c5c8 FUN_0001c5c8 */

/* Boundary evidence: original MIPS .pdata 0001c5c8..0001c66b. Semantic name remains unreviewed. */

undefined4 FUN_0001c5c8(int *param_1,LPCSTR param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *local_118;
  undefined1 auStack_114 [256];
  uint local_14;
  
  local_14 = DAT_000372d4;
  local_118 = auStack_114;
  FUN_0001d7ec((int *)&local_118,param_2,param_1[0xe]);
  uVar1 = (**(code **)(*param_1 + 4))(param_1,local_118,param_3);
  if (local_118 != auStack_114) {
    free(local_118);
  }
  FUN_0002a0c4(local_14);
  return uVar1;
}



/* 0001c66c Unwind@0001c66c */

/* Boundary evidence: original MIPS .pdata 0001c66c..0001c69b. Semantic name remains unreviewed. */

void Unwind_0001c66c(void)

{
  int in_v0;
  
  FUN_0001b1e8((undefined4 *)(in_v0 + -0x118));
  return;
}



/* 0001c69c FUN_0001c69c */

/* Boundary evidence: original MIPS .pdata 0001c69c..0001c77f. Semantic name remains unreviewed. */

undefined4 FUN_0001c69c(int *param_1,wchar_t *param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  (**(code **)(*param_1 + 0xc))(param_1);
  param_1[0xd] = 0;
  piVar1 = FUN_0001ec60(param_2);
  if (piVar1 == (int *)0x0) {
    param_1[0xd] = 1;
    uVar2 = 0;
  }
  else {
    iVar3 = (**(code **)*piVar1)(piVar1,&DAT_0002e1b8,param_1 + 1);
    if (iVar3 < 0) {
      __3_YAXPAX_Z(piVar1);
      uVar2 = 0;
    }
    else {
      uVar4 = (**(code **)(*(int *)param_1[1] + 0x24))();
      *(undefined8 *)(param_1 + 10) = uVar4;
      uVar2 = FUN_0001c780(param_1,param_2,param_3);
    }
  }
  return uVar2;
}



/* 0001c780 FUN_0001c780 */

/* Boundary evidence: original MIPS .pdata 0001c780..0001ca47. Semantic name remains unreviewed. */

undefined4 FUN_0001c780(int *param_1,wchar_t *param_2,int param_3)

{
  wchar_t *pwVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 != (wchar_t *)0x0) {
    (**(code **)(*(int *)param_1[1] + 0x34))((int *)param_1[1],param_1[0x14]);
    pwVar1 = wcsrchr(param_2,L'.');
    (**(code **)(*(int *)param_1[1] + 0x20))();
    iVar2 = FUN_0001bbdc(param_1,(int *)param_1[1],pwVar1);
    param_1[0xc] = iVar2;
    (**(code **)(*(int *)param_1[1] + 0x1c))();
    iVar2 = param_1[0xc];
    if (iVar2 != 5) {
      if (iVar2 == 0) {
        param_1[0xd] = 0x49;
        return 0;
      }
      if (iVar2 != 1) {
        param_1[0xd] = 0x48;
        return 0;
      }
      piVar3 = (int *)__2_YAPAXI_Z(0x2e8);
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = FUN_0001fb00(piVar3);
      }
      param_1[2] = (int)piVar3;
      if (piVar3 == (int *)0x0) {
        return 0;
      }
      if (param_3 != 0) {
        (**(code **)(*piVar3 + 0x24))(piVar3,param_3);
      }
      (**(code **)(*(int *)param_1[2] + 0x1c))((int *)param_1[2],param_1[0xe]);
      (**(code **)(*(int *)param_1[2] + 0x28))((int *)param_1[2],param_1[0xc]);
      (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],param_1[5],0);
      iVar2 = (**(code **)(*(int *)param_1[2] + 4))((int *)param_1[2],param_1[1]);
      if ((int *)param_1[1] != (int *)0x0) {
        (**(code **)(*(int *)param_1[1] + 8))();
        param_1[1] = 0;
      }
      if ((iVar2 == 0) &&
         ((iVar2 = (**(code **)(*(int *)param_1[2] + 0x34))(), *(int *)(iVar2 + 0xc) != 0 ||
          (iVar2 = (**(code **)(*(int *)param_1[2] + 8))((int *)param_1[2],param_2), iVar2 == 0))))
      {
        iVar2 = (**(code **)(*(int *)param_1[2] + 0x30))();
        param_1[0xd] = iVar2;
        iVar2 = (**(code **)(*(int *)param_1[2] + 0x34))();
        if (*(int *)(iVar2 + 8) == 0) {
          (**(code **)(*param_1 + 0xc))(param_1);
          return 0;
        }
        param_1[8] = 1;
      }
      pwVar1 = _wcsdup(param_2);
      param_1[6] = (int)pwVar1;
      iVar2 = (**(code **)(*(int *)param_1[2] + 0x3c))();
      param_1[9] = iVar2;
      (**(code **)(*(int *)param_1[2] + 0x20))((int *)param_1[2],param_1[3]);
      return 1;
    }
    param_1[0xd] = 0x44;
  }
  return 0;
}



/* 0001ca48 Unwind@0001ca48 */

/* Boundary evidence: original MIPS .pdata 0001ca48..0001ca77. Semantic name remains unreviewed. */

void Unwind_0001ca48(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x28));
  return;
}



/* 0001ca78 FUN_0001ca78 */

/* Boundary evidence: original MIPS .pdata 0001ca78..0001cb3b. Semantic name remains unreviewed. */

void FUN_0001ca78(int param_1)

{
  undefined4 *puVar1;
  
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 4) + 8))();
    *(undefined4 *)(param_1 + 4) = 0;
  }
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x10))();
    puVar1 = *(undefined4 **)(param_1 + 8);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
  }
  *(undefined4 *)(param_1 + 8) = 0;
  if (*(void **)(param_1 + 0x18) != (void *)0x0) {
    free(*(void **)(param_1 + 0x18));
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (*(void **)(param_1 + 0x1c) != (void *)0x0) {
    free(*(void **)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  (**(code **)(*(int *)(param_1 + 0x3c) + 4))
            ((int *)(param_1 + 0x3c),0,*(undefined4 *)(param_1 + 0x44));
  return;
}



/* 0001cb3c FUN_0001cb3c */

/* Boundary evidence: original MIPS .pdata 0001cb3c..0001cb6f. Semantic name remains unreviewed. */

void FUN_0001cb3c(int param_1)

{
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x24))();
  }
  return;
}



/* 0001cb70 FUN_0001cb70 */

/* Boundary evidence: original MIPS .pdata 0001cb70..0001cc37. Semantic name remains unreviewed. */

undefined4 FUN_0001cb70(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = (**(code **)(*param_1 + 0x14))(param_1);
  if (uVar1 <= param_2) {
    return 0;
  }
  iVar2 = param_1[0x11];
  iVar4 = 0;
  if (iVar2 != 0) {
    iVar3 = iVar2;
    do {
      iVar2 = iVar3 + iVar4;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 1;
      }
      iVar2 = iVar2 >> 1;
      uVar1 = *(uint *)(iVar2 * 4 + param_1[0x12]);
      if (param_2 == uVar1) {
        return 1;
      }
      if (uVar1 <= param_2) {
        iVar4 = iVar2 + 1;
        iVar2 = iVar3;
      }
      iVar3 = iVar2;
    } while (iVar4 != iVar2);
  }
  FUN_0001d714((int)(param_1 + 0xf),iVar2,param_2);
  return 1;
}



/* 0001cc38 FUN_0001cc38 */

/* Boundary evidence: original MIPS .pdata 0001cc38..0001cccb. Semantic name remains unreviewed. */

undefined4 FUN_0001cc38(int *param_1,LPCSTR param_2)

{
  undefined4 uVar1;
  undefined1 *local_118;
  undefined1 auStack_114 [256];
  uint local_14;
  
  local_14 = DAT_000372d4;
  local_118 = auStack_114;
  FUN_0001d7ec((int *)&local_118,param_2,param_1[0xe]);
  uVar1 = (**(code **)(*param_1 + 0x44))(param_1,local_118);
  if (local_118 != auStack_114) {
    free(local_118);
  }
  FUN_0002a0c4(local_14);
  return uVar1;
}



/* 0001cccc Unwind@0001cccc */

/* Boundary evidence: original MIPS .pdata 0001cccc..0001ccfb. Semantic name remains unreviewed. */

void Unwind_0001cccc(void)

{
  int in_v0;
  
  FUN_0001b1e8((undefined4 *)(in_v0 + -0x118));
  return;
}



/* 0001ccfc FUN_0001ccfc */

/* Boundary evidence: original MIPS .pdata 0001ccfc..0001cdbb. Semantic name remains unreviewed. */

int FUN_0001ccfc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x34) = 0x45;
    iVar1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x34) = 0;
    if (*(int *)(param_1 + 0x44) == 0) {
      iVar1 = (**(code **)(*piVar3 + 0x18))(piVar3,param_2);
    }
    else {
      iVar1 = (**(code **)(*piVar3 + 0x14))
                        (piVar3,*(undefined4 *)(param_1 + 0x48),*(int *)(param_1 + 0x44),param_2);
    }
    if (iVar1 == 0) {
      uVar2 = (**(code **)(*piVar3 + 0x30))(piVar3);
      *(undefined4 *)(param_1 + 0x34) = uVar2;
    }
    (**(code **)(*(int *)(param_1 + 0x3c) + 4))
              ((int *)(param_1 + 0x3c),0,*(undefined4 *)(param_1 + 0x44));
  }
  return iVar1;
}



/* 0001cdbc FUN_0001cdbc */

/* Boundary evidence: original MIPS .pdata 0001cdbc..0001ce33. Semantic name remains unreviewed. */

undefined4 FUN_0001cdbc(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],FUN_0001b9e8,param_2);
  uVar1 = (**(code **)(*param_1 + 0x44))(param_1,0);
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],param_1[5],0);
  return uVar1;
}



/* 0001ce34 FUN_0001ce34 */

/* Boundary evidence: original MIPS .pdata 0001ce34..0001cedf. Semantic name remains unreviewed. */

undefined4 FUN_0001ce34(int *param_1,undefined4 param_2,LPCSTR param_3)

{
  undefined4 uVar1;
  undefined1 *local_118;
  undefined1 auStack_114 [256];
  uint local_14;
  
  local_14 = DAT_000372d4;
  local_118 = auStack_114;
  FUN_0001d7ec((int *)&local_118,param_3,param_1[0xe]);
  uVar1 = (**(code **)(*param_1 + 0x38))(param_1,param_2,local_118);
  if (local_118 != auStack_114) {
    free(local_118);
  }
  FUN_0002a0c4(local_14);
  return uVar1;
}



/* 0001cee0 Unwind@0001cee0 */

/* Boundary evidence: original MIPS .pdata 0001cee0..0001cf0f. Semantic name remains unreviewed. */

void Unwind_0001cee0(void)

{
  int in_v0;
  
  FUN_0001b1e8((undefined4 *)(in_v0 + -0x118));
  return;
}



/* 0001cf10 FUN_0001cf10 */

/* Boundary evidence: original MIPS .pdata 0001cf10..0001d05f. Semantic name remains unreviewed. */

int FUN_0001cf10(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined **local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  
  piVar3 = (int *)param_1[2];
  if (piVar3 == (int *)0x0) {
    param_1[0xd] = 0x45;
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    if (param_2 < iVar1) {
      local_20 = 4;
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_30 = &PTR_FUN_00034934;
      FUN_0001da28((int)&local_30,1);
      *(int *)(local_28 * 4 + local_24) = param_2;
      param_1[0xd] = 0;
      local_28 = local_28 + 1;
      iVar1 = (**(code **)(*piVar3 + 0x14))(piVar3,local_24,local_28,param_3);
      if (iVar1 == 0) {
        iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3);
        param_1[0xd] = iVar2;
      }
      local_30 = &PTR_FUN_00034934;
      FUN_0001db4c((int)&local_30,0,local_28);
      __3_YAXPAX_Z(local_24);
    }
    else {
      param_1[0xd] = 0x37;
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 0001d060 Unwind@0001d060 */

/* Boundary evidence: original MIPS .pdata 0001d060..0001d08f. Semantic name remains unreviewed. */

void Unwind_0001d060(void)

{
  int in_v0;
  
  FUN_0001ba94((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 0001d090 FUN_0001d090 */

/* Boundary evidence: original MIPS .pdata 0001d090..0001d10b. Semantic name remains unreviewed. */

undefined4 FUN_0001d090(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],FUN_0001b9e8);
  uVar1 = (**(code **)(*param_1 + 0x38))(param_1,param_2,0);
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],param_1[5],0);
  return uVar1;
}



/* 0001d10c FUN_0001d10c */

/* Boundary evidence: original MIPS .pdata 0001d10c..0001d19f. Semantic name remains unreviewed. */

undefined4 FUN_0001d10c(int *param_1,LPCSTR param_2)

{
  undefined4 uVar1;
  undefined1 *local_118;
  undefined1 auStack_114 [256];
  uint local_14;
  
  local_14 = DAT_000372d4;
  local_118 = auStack_114;
  FUN_0001d7ec((int *)&local_118,param_2,param_1[0xe]);
  uVar1 = (**(code **)(*param_1 + 0x28))(param_1,local_118);
  if (local_118 != auStack_114) {
    free(local_118);
  }
  FUN_0002a0c4(local_14);
  return uVar1;
}



/* 0001d1a0 Unwind@0001d1a0 */

/* Boundary evidence: original MIPS .pdata 0001d1a0..0001d1cf. Semantic name remains unreviewed. */

void Unwind_0001d1a0(void)

{
  int in_v0;
  
  FUN_0001b1e8((undefined4 *)(in_v0 + -0x118));
  return;
}



/* 0001d1d0 FUN_0001d1d0 */

/* Boundary evidence: original MIPS .pdata 0001d1d0..0001d253. Semantic name remains unreviewed. */

int FUN_0001d1d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x34) = 0x45;
    iVar1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x34) = 0;
    iVar1 = (**(code **)(*piVar3 + 0x18))(piVar3);
    if (iVar1 == 0) {
      uVar2 = (**(code **)(*piVar3 + 0x30))(piVar3);
      *(undefined4 *)(param_1 + 0x34) = uVar2;
    }
  }
  return iVar1;
}



/* 0001d254 FUN_0001d254 */

/* Boundary evidence: original MIPS .pdata 0001d254..0001d2cb. Semantic name remains unreviewed. */

undefined4 FUN_0001d254(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],FUN_0001b9e8,param_2);
  uVar1 = (**(code **)(*param_1 + 0x28))(param_1,0);
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],param_1[5],0);
  return uVar1;
}



/* 0001d2cc FUN_0001d2cc */

/* Boundary evidence: original MIPS .pdata 0001d2cc..0001d303. Semantic name remains unreviewed. */

undefined4 FUN_0001d2cc(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x20))();
  }
  return 1;
}



/* 0001d304 FUN_0001d304 */

/* Boundary evidence: original MIPS .pdata 0001d304..0001d347. Semantic name remains unreviewed. */

undefined4 FUN_0001d304(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x34))();
  return *(undefined4 *)(iVar1 + 8);
}



/* 0001d348 FUN_0001d348 */

/* Boundary evidence: original MIPS .pdata 0001d348..0001d403. Semantic name remains unreviewed. */

undefined4 FUN_0001d348(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (((param_1[2] != 0) && (-1 < param_2)) &&
     (iVar1 = (**(code **)(*param_1 + 0x14))(param_1), param_2 < iVar1)) {
    piVar2 = (int *)(**(code **)(*(int *)param_1[2] + 0x34))();
    if (param_2 < piVar2[2]) {
      return *(undefined4 *)(param_2 * 4 + *piVar2);
    }
    return 0;
  }
  return 0;
}



/* 0001d404 FUN_0001d404 */

/* Boundary evidence: original MIPS .pdata 0001d404..0001d4f3. Semantic name remains unreviewed. */

wchar_t * FUN_0001d404(undefined4 param_1,int param_2)

{
  if (param_2 < 0x9a) {
    if (param_2 == 0x99) {
      return L"Etc";
    }
    switch(param_2) {
    case 0:
      return L"";
    case 1:
    case 5:
      return L"ZipCrypto";
    case 2:
    case 6:
      return L"AES128";
    case 3:
      return L"AES192";
    case 4:
      return L"AES256";
    case 7:
      return L"AES256";
    }
  }
  return L"Unknown";
}



/* 0001d4f4 FUN_0001d4f4 */

/* Boundary evidence: original MIPS .pdata 0001d4f4..0001d697. Semantic name remains unreviewed. */

wchar_t * FUN_0001d4f4(undefined4 param_1,int param_2)

{
  if (param_2 < 0x61) {
    if (param_2 == 0x60) {
      return L"JPEG";
    }
    switch(param_2) {
    case 0:
      return L"Store";
    case 8:
      return L"Deflate";
    case 9:
      return L"Deflate64";
    case 0xc:
      return L"Bzip2";
    case 0xe:
      return L"LZMA";
    }
  }
  else if (param_2 < 0x12d) {
    if (param_2 == 300) {
      return L"Fuse";
    }
    if (param_2 == 0x62) {
      return L"PPMD";
    }
    if (param_2 == 99) {
      return L"AES";
    }
  }
  else {
    if (param_2 == 0x12e) {
      return L"AZO";
    }
    if (param_2 == 999) {
      return L"Etc";
    }
  }
  return L"Unknown";
}



/* 0001d6a0 FUN_0001d6a0 */

/* Boundary evidence: original MIPS .pdata 0001d6a0..0001d713. Semantic name remains unreviewed. */

undefined4 * FUN_0001d6a0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00034934;
  FUN_0001db4c((int)param_1,0,param_1[2]);
  __3_YAXPAX_Z(param_1[3]);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001d714 FUN_0001d714 */

/* Boundary evidence: original MIPS .pdata 0001d714..0001d7eb. Semantic name remains unreviewed. */

void FUN_0001d714(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_1 + 4);
  if (*(uint *)(param_1 + 8) == uVar1) {
    uVar2 = 1;
    if ((int)uVar1 < 0x40) {
      if (7 < (int)uVar1) {
        uVar2 = 8;
      }
    }
    else {
      uVar2 = uVar1 >> 2;
    }
    FUN_0001da28(param_1,uVar1 + uVar2);
  }
  iVar3 = *(int *)(param_1 + 0x10);
  memmove((void *)((param_2 + 1) * iVar3 + *(int *)(param_1 + 0xc)),
          (void *)(iVar3 * param_2 + *(int *)(param_1 + 0xc)),
          (*(int *)(param_1 + 8) - param_2) * iVar3);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0xc)) = param_3;
  return;
}



/* 0001d7ec FUN_0001d7ec */

/* Boundary evidence: original MIPS .pdata 0001d7ec..0001d943. Semantic name remains unreviewed. */

void FUN_0001d7ec(int *param_1,LPCSTR param_2,UINT param_3)

{
  char cVar1;
  DWORD DVar2;
  size_t cchWideChar;
  char *pcVar3;
  int iVar4;
  size_t cbMultiByte;
  
  if (param_2 == (LPCSTR)0x0) {
    *param_1 = 0;
  }
  else {
    iVar4 = 0;
    cVar1 = *param_2;
    pcVar3 = param_2;
    while (cVar1 != '\0') {
      pcVar3 = pcVar3 + 1;
      iVar4 = iVar4 + 1;
      cVar1 = *pcVar3;
    }
    cbMultiByte = iVar4 + 1;
    FUN_0001d944(param_1,cbMultiByte,param_1 + 1);
    iVar4 = MultiByteToWideChar(param_3,0,param_2,cbMultiByte,(LPWSTR)*param_1,cbMultiByte);
    if (iVar4 == 0) {
      DVar2 = GetLastError();
      if (DVar2 == 0x7a) {
        cchWideChar = MultiByteToWideChar(param_3,0,param_2,cbMultiByte,(LPWSTR)0x0,0);
        FUN_0001d944(param_1,cchWideChar,param_1 + 1);
        iVar4 = MultiByteToWideChar(param_3,0,param_2,cbMultiByte,(LPWSTR)*param_1,cchWideChar);
        if (iVar4 != 0) {
          return;
        }
      }
      FUN_0001b714();
    }
  }
  return;
}



/* 0001d944 FUN_0001d944 */

/* Boundary evidence: original MIPS .pdata 0001d944..0001da27. Semantic name remains unreviewed. */

void FUN_0001d944(int *param_1,size_t param_2,void *param_3)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
    FUN_00011314(0x80070057);
  }
  if ((int)param_2 < 0) {
    FUN_00011314(0x80070057);
  }
  if (param_3 == (void *)0x0) {
    FUN_00011314(0x80070057);
  }
  pvVar1 = (void *)*param_1;
  if (pvVar1 == param_3) {
    if (0x80 < (int)param_2) {
      pvVar1 = calloc(param_2,2);
      *param_1 = (int)pvVar1;
      goto LAB_0001d9e0;
    }
  }
  else {
    if (0x80 < (int)param_2) {
      pvVar1 = _recalloc(pvVar1,param_2,2);
      if (pvVar1 == (void *)0x0) {
        pvVar1 = (void *)FUN_00011314(0x8007000e);
      }
      *param_1 = (int)pvVar1;
      goto LAB_0001d9e0;
    }
    free(pvVar1);
  }
  *param_1 = (int)param_3;
LAB_0001d9e0:
  if (*param_1 == 0) {
    FUN_00011314(0x8007000e);
  }
  return;
}



/* 0001da28 FUN_0001da28 */

/* Boundary evidence: original MIPS .pdata 0001da28..0001db4b. Semantic name remains unreviewed. */

void FUN_0001da28(int param_1,uint param_2)

{
  uint uVar1;
  void *_Dst;
  undefined4 auStack_18 [2];
  
  if (param_2 != *(uint *)(param_1 + 4)) {
    if (0x7fffffff < param_2) {
                    /* WARNING: Subroutine does not return */
      auStack_18[0] = 0x100ec1;
      __CxxThrowException(auStack_18,(ThrowInfo *)&DAT_00036328);
    }
    uVar1 = *(uint *)(param_1 + 0x10);
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    if ((uVar1 * param_2) / uVar1 != param_2) {
                    /* WARNING: Subroutine does not return */
      auStack_18[0] = 0x100ec2;
      __CxxThrowException(auStack_18,(ThrowInfo *)&DAT_00036328);
    }
    _Dst = (void *)0x0;
    if (uVar1 * param_2 != 0) {
      _Dst = (void *)__2_YAPAXI_Z();
      if (_Dst == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        auStack_18[0] = 0x100ec3;
        __CxxThrowException(auStack_18,(ThrowInfo *)&DAT_00036328);
      }
      uVar1 = *(uint *)(param_1 + 8);
      if ((int)param_2 <= (int)*(uint *)(param_1 + 8)) {
        uVar1 = param_2;
      }
      memcpy(_Dst,*(void **)(param_1 + 0xc),*(int *)(param_1 + 0x10) * uVar1);
    }
    __3_YAXPAX_Z(*(undefined4 *)(param_1 + 0xc));
    *(void **)(param_1 + 0xc) = _Dst;
    *(uint *)(param_1 + 4) = param_2;
  }
  return;
}



/* 0001db4c FUN_0001db4c */

/* Boundary evidence: original MIPS .pdata 0001db4c..0001dbeb. Semantic name remains unreviewed. */

void FUN_0001db4c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 < param_2 + param_3) {
    param_3 = iVar2 - param_2;
  }
  if (0 < param_3) {
    iVar1 = *(int *)(param_1 + 0x10);
    memmove((void *)(iVar1 * param_2 + *(int *)(param_1 + 0xc)),
            (void *)(iVar1 * (param_2 + param_3) + *(int *)(param_1 + 0xc)),
            (iVar2 - (param_2 + param_3)) * iVar1);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) - param_3;
  }
  return;
}



/* 0001dbec FUN_0001dbec */

/* Boundary evidence: original MIPS .pdata 0001dbec..0001dd23. Semantic name remains unreviewed. */

int * FUN_0001dbec(wchar_t *param_1)

{
  int *piVar1;
  LPVOID pvVar2;
  HANDLE pvVar3;
  int iVar4;
  
  if (param_1 != (wchar_t *)0x0) {
    piVar1 = (int *)__2_YAPAXI_Z(0x58);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1[1] = 0;
      *piVar1 = (int)&PTR_FUN_000349f8;
      piVar1[4] = 0x10000;
      pvVar2 = VirtualAlloc((LPVOID)0x0,0x10000,0x1000,4);
      piVar1[5] = (int)pvVar2;
      piVar1[6] = 0x10000;
      piVar1[7] = 0;
      piVar1[8] = 0;
      piVar1[9] = 0;
      InitializeCriticalSection((LPCRITICAL_SECTION)(piVar1 + 0xc));
      pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      piVar1[0x11] = (int)pvVar3;
      piVar1[0x13] = -1;
      piVar1[0x14] = 0;
      piVar1[10] = 0;
      piVar1[0xb] = 0;
      piVar1[2] = 0;
      piVar1[3] = 0;
      piVar1[0x12] = 0;
    }
    FUN_00023fd8(param_1);
    iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1,param_1);
    if (iVar4 != 0) {
      return piVar1;
    }
    FUN_00023fd8(param_1);
    iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1,param_1);
    if (iVar4 != 0) {
      return piVar1;
    }
    __3_YAXPAX_Z(piVar1);
  }
  return (int *)0x0;
}



/* 0001dd24 FUN_0001dd24 */

/* Boundary evidence: original MIPS .pdata 0001dd24..0001dd67. Semantic name remains unreviewed. */

int * FUN_0001dd24(wchar_t *param_1)

{
  int *piVar1;
  
  piVar1 = FUN_0001dbec(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return piVar1;
}



/* 0001dd68 FUN_0001dd68 */

/* Boundary evidence: original MIPS .pdata 0001dd68..0001dde7. Semantic name remains unreviewed. */

undefined4 * FUN_0001dd68(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000349f8;
  FUN_0001e1c0((int)param_1,param_2,0,0);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if ((LPVOID)param_1[5] != (LPVOID)0x0) {
    VirtualFree((LPVOID)param_1[5],0,0x8000);
  }
  param_1[5] = 0;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001dde8 FUN_0001dde8 */

/* Boundary evidence: original MIPS .pdata 0001dde8..0001de7b. Semantic name remains unreviewed. */

undefined4 FUN_0001dde8(int *param_1,char *param_2)

{
  uint uVar1;
  char *_Memory;
  
  uVar1 = DAT_000372d4;
  _Memory = FUN_00023e1c(param_2);
  if (_Memory != (char *)0x0) {
    if (param_1[0x13] != -1) {
      (**(code **)(*param_1 + 0x18))(param_1);
    }
    param_1[0x13] = -1;
    free(_Memory);
  }
  FUN_0002a0c4(uVar1);
  return 0;
}



/* 0001de7c FUN_0001de7c */

/* Boundary evidence: original MIPS .pdata 0001de7c..0001e067. Semantic name remains unreviewed. */

undefined4 FUN_0001de7c(int *param_1,wchar_t *param_2)

{
  wchar_t *lpFileName;
  undefined4 uVar1;
  HANDLE pvVar2;
  int *piVar3;
  LONG LVar4;
  wchar_t *pwVar5;
  LPCWSTR local_30;
  int local_2c;
  
  lpFileName = FUN_00023ee8(param_2);
  if (lpFileName == (wchar_t *)0x0) {
    uVar1 = 0;
  }
  else {
    if (param_1[0x13] != -1) {
      (**(code **)(*param_1 + 0x18))(param_1);
    }
    pvVar2 = CreateFileW(lpFileName,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x20,(HANDLE)0x0);
    param_1[0x13] = (int)pvVar2;
    if (pvVar2 == (HANDLE)0xffffffff) {
      piVar3 = FUN_0001e5f8(&local_2c,lpFileName);
      FUN_0001e6e0((int *)&local_30,piVar3);
      LVar4 = InterlockedDecrement((LONG *)(local_2c + -4));
      if (LVar4 < 1) {
        piVar3 = *(int **)(local_2c + -0x10);
        (**(code **)(*piVar3 + 4))(piVar3,(undefined4 *)(local_2c + -0x10));
      }
      DeleteFileW(local_30);
      MoveFileW(lpFileName,local_30);
      pvVar2 = CreateFileW(lpFileName,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x20,(HANDLE)0x0);
      param_1[0x13] = (int)pvVar2;
      if (pvVar2 == (HANDLE)0xffffffff) {
        GetLastError();
        free(lpFileName);
        FUN_00012324((int *)&local_30);
        return 0;
      }
      FUN_00012324((int *)&local_30);
    }
    pwVar5 = _wcsdup(lpFileName);
    param_1[0x14] = (int)pwVar5;
    free(lpFileName);
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[3] = 0;
    FUN_0001e36c(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001e068 Unwind@0001e068 */

/* Boundary evidence: original MIPS .pdata 0001e068..0001e097. Semantic name remains unreviewed. */

void Unwind_0001e068(void)

{
  int in_v0;
  
  FUN_00012324((int *)(in_v0 + -0x2c));
  return;
}



/* 0001e098 FUN_0001e098 */

/* Boundary evidence: original MIPS .pdata 0001e098..0001e1bf. Semantic name remains unreviewed. */

undefined4 FUN_0001e098(int param_1,void *param_2,size_t param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (*(int *)(param_1 + 0x48) == 1) {
    uVar2 = 0;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x30);
    EnterCriticalSection(lpCriticalSection);
    FUN_000246f4((int *)(param_1 + 0x10),param_2,param_3);
    EventModify(*(undefined4 *)(param_1 + 0x44),3);
    uVar3 = *(uint *)(param_1 + 0x24);
    LeaveCriticalSection(lpCriticalSection);
    iVar4 = 300;
    if (0x80000 < uVar3) {
      do {
        if (iVar4 == 0) break;
        Sleep(10);
        EnterCriticalSection(lpCriticalSection);
        bVar1 = 0x80000 < *(uint *)(param_1 + 0x24);
        if (bVar1) {
          iVar4 = iVar4 + -1;
        }
        LeaveCriticalSection(lpCriticalSection);
      } while (bVar1);
      if (iVar4 < 1) {
        return 0;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 0001e1c0 FUN_0001e1c0 */

/* Boundary evidence: original MIPS .pdata 0001e1c0..0001e347. Semantic name remains unreviewed. */

bool FUN_0001e1c0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  DWORD DVar2;
  FILETIME local_30;
  
  if (*(int *)(param_1 + 0x4c) == -1) {
    bVar1 = true;
  }
  else {
    if (*(HANDLE *)(param_1 + 8) != (HANDLE)0x0) {
      DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 8),0);
      if (DVar2 == 0x102) {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
        *(undefined4 *)(param_1 + 0xc) = 1;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
        WaitForSingleObject(*(HANDLE *)(param_1 + 8),0xffffffff);
        CloseHandle(*(HANDLE *)(param_1 + 8));
      }
      *(undefined4 *)(param_1 + 8) = 0;
    }
    bVar1 = *(int *)(param_1 + 0x48) != 1;
    *(undefined4 *)(param_1 + 0x48) = 0;
    if (*(HANDLE *)(param_1 + 0x4c) != (HANDLE)0xffffffff) {
      if ((bVar1) && (param_3 != 0 || param_4 != 0)) {
        local_30 = (FILETIME)((longlong)param_3 * 10000000 + 0x19db1ded53e8000);
        SetFileTime(*(HANDLE *)(param_1 + 0x4c),(FILETIME *)0x0,(FILETIME *)0x0,&local_30);
      }
      CloseHandle(*(HANDLE *)(param_1 + 0x4c));
    }
    *(undefined4 *)(param_1 + 0x4c) = 0xffffffff;
    if (*(void **)(param_1 + 0x50) != (void *)0x0) {
      free(*(void **)(param_1 + 0x50));
    }
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  return bVar1;
}



/* 0001e348 FUN_0001e348 */

/* Boundary evidence: original MIPS .pdata 0001e348..0001e36b. Semantic name remains unreviewed. */

void FUN_0001e348(int param_1,DWORD param_2)

{
  SetFileAttributesW(*(LPCWSTR *)(param_1 + 0x50),param_2);
  return;
}



/* 0001e36c FUN_0001e36c */

/* Boundary evidence: original MIPS .pdata 0001e36c..0001e3db. Semantic name remains unreviewed. */

undefined4 FUN_0001e36c(LPVOID param_1)

{
  HANDLE pvVar1;
  DWORD local_10 [2];
  
  if (*(int *)((int)param_1 + 8) != 0) {
    return 0;
  }
  local_10[0] = 0;
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001e3dc,param_1,0,local_10);
  *(HANDLE *)((int)param_1 + 8) = pvVar1;
  return 1;
}



/* 0001e3dc FUN_0001e3dc */

/* Boundary evidence: original MIPS .pdata 0001e3dc..0001e3fb. Semantic name remains unreviewed. */

undefined4 FUN_0001e3dc(int param_1)

{
  FUN_0001e3fc(param_1);
  return 0;
}



/* 0001e3fc FUN_0001e3fc */

/* Boundary evidence: original MIPS .pdata 0001e3fc..0001e5a3. Semantic name remains unreviewed. */

void FUN_0001e3fc(int param_1)

{
  bool bVar1;
  void *lpBuffer;
  BOOL BVar2;
  DWORD DVar3;
  LPDWORD lpNumberOfBytesWritten;
  uint uVar4;
  DWORD DVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD local_30 [2];
  
  bVar1 = false;
  lpBuffer = malloc(0x10000);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x30);
  do {
    EnterCriticalSection(lpCriticalSection);
    DVar5 = *(size_t *)(param_1 + 0x24);
    if (*(int *)(param_1 + 0xc) == 0) {
      if (0xffff < (int)DVar5) goto LAB_0001e484;
      DVar5 = 0;
LAB_0001e4a8:
      if (*(int *)(param_1 + 0xc) != 0) {
        bVar1 = true;
      }
    }
    else {
      if (0xffff < (int)DVar5) {
LAB_0001e484:
        DVar5 = 0x10000;
      }
      else if (DVar5 == 0) goto LAB_0001e4a8;
      FUN_0002483c(param_1 + 0x10,lpBuffer,DVar5,1);
    }
    LeaveCriticalSection(lpCriticalSection);
    if (DVar5 == 0) {
      WaitForSingleObject(*(HANDLE *)(param_1 + 0x44),10);
    }
    else {
      lpNumberOfBytesWritten = local_30;
      DVar3 = DVar5;
      BVar2 = WriteFile(*(HANDLE *)(param_1 + 0x4c),lpBuffer,DVar5,lpNumberOfBytesWritten,
                        (LPOVERLAPPED)0x0);
      if ((BVar2 == 0) || (local_30[0] != DVar5)) {
        DVar5 = GetLastError();
        FUN_0001aeb8(0x349dc,DVar5,DVar3,(va_list)lpNumberOfBytesWritten);
        *(undefined4 *)(param_1 + 0x48) = 1;
      }
      else {
        EnterCriticalSection(lpCriticalSection);
        uVar4 = local_30[0] + *(int *)(param_1 + 0x28);
        *(uint *)(param_1 + 0x28) = uVar4;
        *(uint *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (uint)(uVar4 < local_30[0]);
        LeaveCriticalSection(lpCriticalSection);
      }
    }
    if (bVar1) {
      free(lpBuffer);
      return;
    }
  } while( true );
}



/* 0001e5a4 FUN_0001e5a4 */

/* Boundary evidence: original MIPS .pdata 0001e5a4..0001e5f7. Semantic name remains unreviewed. */

undefined8 FUN_0001e5a4(int param_1)

{
  undefined8 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  uVar1 = *(undefined8 *)(param_1 + 0x28);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return uVar1;
}



/* 0001e5f8 FUN_0001e5f8 */

/* Boundary evidence: original MIPS .pdata 0001e5f8..0001e6af. Semantic name remains unreviewed. */

int * FUN_0001e5f8(int *param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  iVar2 = (**(code **)(PTR_PTR_000372dc + 0xc))(&PTR_PTR_000372dc);
  *param_1 = iVar2 + 0x10;
  iVar2 = FUN_0001e82c(param_1,(uint)param_2);
  if (iVar2 == 0) {
    psVar3 = param_2;
    if (param_2 == (short *)0x0) {
      iVar2 = 0;
    }
    else {
      do {
        sVar1 = *psVar3;
        psVar3 = psVar3 + 1;
      } while (sVar1 != 0);
      iVar2 = ((uint)((int)psVar3 - (int)param_2) >> 1) - 1;
    }
    FUN_00012678(param_1,param_2,iVar2);
  }
  return param_1;
}



/* 0001e6b0 Unwind@0001e6b0 */

/* Boundary evidence: original MIPS .pdata 0001e6b0..0001e6df. Semantic name remains unreviewed. */

void Unwind_0001e6b0(void)

{
  undefined4 *in_v0;
  
  FUN_00012324((int *)*in_v0);
  return;
}



/* 0001e6e0 FUN_0001e6e0 */

/* Boundary evidence: original MIPS .pdata 0001e6e0..0001e7db. Semantic name remains unreviewed. */

int * FUN_0001e6e0(int *param_1,int *param_2)

{
  short *psVar1;
  int *piVar2;
  int iVar3;
  short *psVar4;
  
  if (((*(int **)(*param_2 + -0x10) == (int *)0x0) ||
      (piVar2 = (int *)(**(code **)(**(int **)(*param_2 + -0x10) + 0x10))(), piVar2 == (int *)0x0))
     && (piVar2 = (int *)(**(code **)(PTR_PTR_000372dc + 0x10))(&PTR_PTR_000372dc),
        piVar2 == (int *)0x0)) {
    piVar2 = (int *)FUN_00011314(0x80004005);
  }
  iVar3 = (**(code **)(*piVar2 + 0xc))(piVar2);
  *param_1 = iVar3 + 0x10;
  psVar1 = &DAT_000349d0;
  do {
    psVar4 = psVar1;
    psVar1 = psVar4 + 1;
  } while (*psVar4 != 0);
  FUN_00012578(param_1,(void *)*param_2,*(int *)(*param_2 + -0xc),&DAT_000349d0,
               ((int)(psVar4 + -0x1a4e7) >> 1) + -1);
  return param_1;
}



/* 0001e7dc Unwind@0001e7dc */

/* Boundary evidence: original MIPS .pdata 0001e7dc..0001e82b. Semantic name remains unreviewed. */

void Unwind_0001e7dc(void)

{
  undefined4 *in_v0;
  
  if ((in_v0[-6] & 1) != 0) {
    in_v0[-6] = in_v0[-6] & 0xfffffffe;
    FUN_00012324((int *)*in_v0);
  }
  return;
}



/* 0001e82c FUN_0001e82c */

/* Boundary evidence: original MIPS .pdata 0001e82c..0001e907. Semantic name remains unreviewed. */

undefined4 FUN_0001e82c(int *param_1,uint param_2)

{
  HMODULE pHVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if ((param_2 != 0) && ((param_2 & 0xffff0000) == 0)) {
    pHVar1 = (HMODULE)FUN_0002b12c(0x37640,0);
    uVar4 = 1;
    iVar3 = 1;
    while (pHVar1 != (HMODULE)0x0) {
      puVar2 = FUN_0001ea48(pHVar1,param_2 & 0xffff);
      if (puVar2 != (ushort *)0x0) {
        if (pHVar1 == (HMODULE)0x0) {
          return 1;
        }
        FUN_0001e908(param_1,pHVar1,param_2 & 0xffff);
        return 1;
      }
      pHVar1 = (HMODULE)FUN_0002b12c(0x37640,iVar3);
      iVar3 = iVar3 + 1;
    }
  }
  return uVar4;
}



/* 0001e908 FUN_0001e908 */

/* Boundary evidence: original MIPS .pdata 0001e908..0001ea47. Semantic name remains unreviewed. */

undefined4 FUN_0001e908(int *param_1,HMODULE param_2,uint param_3)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  errno_t eVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  
  puVar2 = FUN_0001ea48(param_2,param_3);
  if (puVar2 == (ushort *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar5 = (uint)*puVar2;
    if ((int)(1U - *(int *)(*param_1 + -4) | *(int *)(*param_1 + -8) - uVar5) < 0) {
      FUN_00012888(param_1,uVar5);
    }
    uVar6 = (uint)*puVar2;
    puVar2 = puVar2 + 1;
    if (uVar6 == 0xffffffff) {
      puVar7 = puVar2;
      if (puVar2 == (ushort *)0x0) {
        iVar8 = 0;
      }
      else {
        do {
          uVar1 = *puVar7;
          puVar7 = puVar7 + 1;
        } while (uVar1 != 0);
        iVar8 = ((uint)((int)puVar7 - (int)puVar2) >> 1) - 1;
      }
      uVar6 = iVar8 + 1;
    }
    eVar4 = memcpy_s((void *)*param_1,uVar5 * 2,puVar2,uVar6 << 1);
    FUN_0001b688(eVar4);
    if (*(int *)(*param_1 + -8) < (int)uVar5) {
      uVar3 = FUN_00011314(0x80070057);
    }
    else {
      *(uint *)(*param_1 + -0xc) = uVar5;
      uVar3 = 1;
      *(undefined2 *)(uVar5 * 2 + *param_1) = 0;
    }
  }
  return uVar3;
}



/* 0001ea48 FUN_0001ea48 */

/* Boundary evidence: original MIPS .pdata 0001ea48..0001eb3f. Semantic name remains unreviewed. */

ushort * FUN_0001ea48(HMODULE param_1,uint param_2)

{
  HRSRC hResInfo;
  ushort *puVar1;
  DWORD DVar2;
  ushort *puVar3;
  uint uVar4;
  
  hResInfo = FindResourceW(param_1,(LPCWSTR)((param_2 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
  if ((hResInfo != (HRSRC)0x0) && (puVar1 = LoadResource(param_1,hResInfo), puVar1 != (ushort *)0x0)
     ) {
    DVar2 = SizeofResource(param_1,hResInfo);
    puVar3 = (ushort *)(DVar2 + (int)puVar1);
    for (uVar4 = param_2 & 0xf; uVar4 != 0; uVar4 = uVar4 - 1) {
      if (puVar3 <= puVar1) {
        return (ushort *)0x0;
      }
      puVar1 = puVar1 + *puVar1 + 1;
    }
    if ((puVar1 < puVar3) && (*puVar1 != 0)) {
      return puVar1;
    }
  }
  return (ushort *)0x0;
}



/* 0001eb40 FUN_0001eb40 */

/* Boundary evidence: original MIPS .pdata 0001eb40..0001ebbf. Semantic name remains unreviewed. */

undefined4 FUN_0001eb40(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,&DAT_0002e1b8,0x10);
  if (iVar1 == 0) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    return 0;
  }
  return 0x80004002;
}



/* 0001ebc0 FUN_0001ebc0 */

/* Boundary evidence: original MIPS .pdata 0001ebc0..0001ebdb. Semantic name remains unreviewed. */

void FUN_0001ebc0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 0001ebdc FUN_0001ebdc */

/* Boundary evidence: original MIPS .pdata 0001ebdc..0001ec4f. Semantic name remains unreviewed. */

LONG FUN_0001ebdc(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 != 0) {
    return param_1[1];
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x38))(param_1,1);
  }
  return 0;
}



/* 0001ec60 FUN_0001ec60 */

/* Boundary evidence: original MIPS .pdata 0001ec60..0001ed1f. Semantic name remains unreviewed. */

int * FUN_0001ec60(undefined4 param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  
  piVar1 = (int *)__2_YAPAXI_Z(0x38);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    *piVar1 = (int)&PTR_FUN_00034a90;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[8] = 0;
    piVar1[9] = 0;
    piVar1[2] = -1;
    pvVar2 = malloc(0x10000);
    piVar1[3] = (int)pvVar2;
    piVar1[4] = 0x10000;
    piVar1[0xc] = 0;
    piVar1[0xd] = 0;
  }
  iVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,param_1);
  if (iVar3 == 0) {
    __3_YAXPAX_Z(piVar1);
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



/* 0001ed20 FUN_0001ed20 */

/* Boundary evidence: original MIPS .pdata 0001ed20..0001edbf. Semantic name remains unreviewed. */

undefined4 * FUN_0001ed20(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00034a90;
  if ((HANDLE)param_1[2] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)param_1[2]);
    param_1[2] = 0xffffffff;
    param_1[5] = 0;
    param_1[6] = 0;
    if ((void *)param_1[0xc] != (void *)0x0) {
      free((void *)param_1[0xc]);
    }
    param_1[0xc] = 0;
  }
  free((void *)param_1[3]);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001edc0 FUN_0001edc0 */

/* Boundary evidence: original MIPS .pdata 0001edc0..0001ee27. Semantic name remains unreviewed. */

undefined4 FUN_0001edc0(int *param_1)

{
  uint uVar1;
  
  uVar1 = DAT_000372d4;
  if (param_1[2] != -1) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  param_1[2] = -1;
  FUN_0002a0c4(uVar1);
  return 0;
}



/* 0001ee28 FUN_0001ee28 */

/* Boundary evidence: original MIPS .pdata 0001ee28..0001efdb. Semantic name remains unreviewed. */

undefined4 FUN_0001ee28(int *param_1,wchar_t *param_2)

{
  HANDLE pvVar1;
  DWORD DVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  va_list pcVar5;
  DWORD local_28 [2];
  
  if (param_1[2] != -1) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  pcVar5 = (va_list)0x0;
  pvVar1 = CreateFileW(param_2,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
  param_1[2] = (int)pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    pcVar5 = (va_list)0x0;
    pvVar1 = CreateFileW(param_2,0x80000000,2,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
    param_1[2] = (int)pvVar1;
  }
  if (param_1[2] == -1) {
    pcVar5 = (va_list)0x0;
    pvVar1 = CreateFileW(param_2,0x80000000,2,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
    param_1[2] = (int)pvVar1;
  }
  if (param_1[2] == -1) {
    pcVar5 = (va_list)0x0;
    pvVar1 = CreateFileW(param_2,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    param_1[2] = (int)pvVar1;
  }
  if ((HANDLE)param_1[2] == (HANDLE)0xffffffff) {
    DVar2 = GetLastError();
    FUN_0001aeb8(0x34a24,param_2,DVar2,pcVar5);
    uVar3 = 0;
  }
  else {
    DVar2 = GetFileSize((HANDLE)param_1[2],local_28);
    param_1[10] = DVar2;
    param_1[0xb] = local_28[0];
    if ((void *)param_1[0xc] != (void *)0x0) {
      free((void *)param_1[0xc]);
    }
    pwVar4 = _wcsdup(param_2);
    param_1[0xc] = (int)pwVar4;
    uVar3 = 1;
  }
  return uVar3;
}



/* 0001efdc FUN_0001efdc */

/* Boundary evidence: original MIPS .pdata 0001efdc..0001f06b. Semantic name remains unreviewed. */

int FUN_0001efdc(int param_1,void *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint local_20 [2];
  
  local_20[0] = 0;
  if (param_4 == (uint *)0x0) {
    param_4 = local_20;
  }
  iVar1 = FUN_0001f06c(param_1,param_2,param_3,param_4);
  if ((iVar1 != 0) && (puVar2 = *(undefined4 **)(param_1 + 0x34), puVar2 != (undefined4 *)0x0)) {
    (**(code **)*puVar2)(puVar2,param_2,*param_4);
  }
  return iVar1;
}



/* 0001f06c FUN_0001f06c */

/* Boundary evidence: original MIPS .pdata 0001f06c..0001f2ab. Semantic name remains unreviewed. */

undefined4 FUN_0001f06c(int param_1,void *param_2,uint param_3,uint *param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 uVar3;
  LPDWORD lpNumberOfBytesRead;
  uint uVar4;
  LPDWORD lpNumberOfBytesRead_00;
  uint uVar5;
  DWORD local_28 [2];
  
  lpNumberOfBytesRead_00 = (LPDWORD)(param_1 + 0x14);
  uVar5 = *lpNumberOfBytesRead_00 - *(int *)(param_1 + 0x18);
  if ((int)uVar5 < (int)param_3) {
    *param_4 = 0;
    if (uVar5 != 0) {
      memcpy(param_2,(void *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x18)),uVar5);
      param_2 = (void *)(uVar5 + (int)param_2);
      *lpNumberOfBytesRead_00 = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *param_4 = *param_4 + uVar5;
      uVar4 = uVar5 + *(int *)(param_1 + 0x20);
      param_3 = param_3 - uVar5;
      *(uint *)(param_1 + 0x20) = uVar4;
      *(uint *)(param_1 + 0x24) =
           ((int)uVar5 >> 0x1f) + *(int *)(param_1 + 0x24) + (uint)(uVar4 < uVar5);
    }
    uVar5 = *(uint *)(param_1 + 0x10);
    if (param_3 < uVar5) {
      *lpNumberOfBytesRead_00 = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      lpNumberOfBytesRead = lpNumberOfBytesRead_00;
      BVar1 = ReadFile(*(HANDLE *)(param_1 + 8),*(LPVOID *)(param_1 + 0xc),uVar5,
                       lpNumberOfBytesRead_00,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) goto LAB_0001f18c;
      uVar5 = *lpNumberOfBytesRead_00;
      if (uVar5 != 0) {
        if (uVar5 <= param_3) {
          param_3 = uVar5;
        }
        if (param_3 != 0) {
          memcpy(param_2,(void *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x18)),param_3);
          uVar5 = param_3 + *(int *)(param_1 + 0x20);
          *(uint *)(param_1 + 0x18) = param_3 + *(int *)(param_1 + 0x18);
          *(uint *)(param_1 + 0x20) = uVar5;
          *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(uVar5 < param_3);
          *param_4 = *param_4 + param_3;
        }
        goto LAB_0001f284;
      }
    }
    else {
      lpNumberOfBytesRead = local_28;
      BVar1 = ReadFile(*(HANDLE *)(param_1 + 8),param_2,param_3,lpNumberOfBytesRead,
                       (LPOVERLAPPED)0x0);
      uVar5 = param_3;
      if (BVar1 != 0) {
        DVar2 = SetFilePointer(*(HANDLE *)(param_1 + 8),0,(PLONG)0x0,1);
        *(DWORD *)(param_1 + 0x20) = DVar2;
        *(undefined4 *)(param_1 + 0x24) = 0;
        *param_4 = *param_4 + local_28[0];
        goto LAB_0001f284;
      }
LAB_0001f18c:
      DVar2 = GetLastError();
      FUN_0001aeb8(0x34a6c,DVar2,uVar5,(va_list)lpNumberOfBytesRead);
    }
    uVar3 = 0;
  }
  else {
    memcpy(param_2,(void *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x18)),param_3);
    uVar5 = param_3 + *(int *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x18) = param_3 + *(int *)(param_1 + 0x18);
    *(uint *)(param_1 + 0x20) = uVar5;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(uVar5 < param_3);
    *param_4 = param_3;
LAB_0001f284:
    uVar3 = 1;
  }
  return uVar3;
}



/* 0001f2ac FUN_0001f2ac */

/* Boundary evidence: original MIPS .pdata 0001f2ac..0001f2f7. Semantic name remains unreviewed. */

undefined4 FUN_0001f2ac(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_10 [2];
  
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1,param_2,param_3,local_10);
  if ((iVar1 == 0) || (uVar2 = 1, local_10[0] != param_3)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0001f2f8 FUN_0001f2f8 */

/* Boundary evidence: original MIPS .pdata 0001f2f8..0001f4f7. Semantic name remains unreviewed. */

undefined8 FUN_0001f2f8(int *param_1,undefined4 param_2,uint param_3,int param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  int local_18 [2];
  
  if (param_5 == 0) {
    param_1[8] = param_3;
    param_1[9] = param_4;
LAB_0001f48c:
    param_1[6] = 0;
    param_1[5] = 0;
  }
  else {
    if (param_5 == 1) {
      if (param_3 == 0 && param_4 == 0) goto LAB_0001f4d8;
      if ((-1 < param_4) && ((param_4 != 0 || (param_3 != 0)))) {
        uVar3 = param_1[5] - param_1[6];
        iVar2 = (int)uVar3 >> 0x1f;
        if ((param_4 <= iVar2) && ((param_4 != iVar2 || (param_3 < uVar3)))) {
          uVar3 = param_1[8];
          uVar4 = uVar3 + param_3;
          param_1[6] = param_3 + param_1[6];
          param_1[8] = uVar4;
          param_1[9] = param_1[9] + param_4 + (uint)(uVar4 < uVar3);
          goto LAB_0001f4d8;
        }
      }
      if ((param_4 < 1) && (param_4 != 0)) {
        uVar3 = param_1[6];
        iVar2 = -(uint)(param_3 != 0) - param_4;
        if ((iVar2 <= (int)uVar3 >> 0x1f) && ((iVar2 != (int)uVar3 >> 0x1f || (-param_3 <= uVar3))))
        {
          uVar4 = param_1[8];
          uVar5 = uVar4 + param_3;
          param_1[6] = param_3 + uVar3;
          param_1[8] = uVar5;
          param_1[9] = param_1[9] + param_4 + (uint)(uVar5 < uVar4);
          goto LAB_0001f4d8;
        }
      }
      uVar3 = param_1[8];
      uVar4 = uVar3 + param_3;
      param_1[8] = uVar4;
      param_1[9] = param_1[9] + param_4 + (uint)(uVar4 < uVar3);
      goto LAB_0001f48c;
    }
    if (param_5 == 2) {
      pcVar1 = *(code **)(*param_1 + 0x24);
      param_1[5] = 0;
      param_1[6] = 0;
      lVar6 = (*pcVar1)(param_1);
      *(longlong *)(param_1 + 8) = lVar6 - CONCAT44(param_4,param_3);
    }
  }
  local_18[0] = param_1[9];
  SetFilePointer((HANDLE)param_1[2],param_1[8],local_18,0);
  if ((int *)param_1[0xd] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xd] + 4))();
  }
LAB_0001f4d8:
  return *(undefined8 *)(param_1 + 8);
}



/* 0001f510 FUN_0001f510 */

/* Boundary evidence: original MIPS .pdata 0001f510..0001f57f. Semantic name remains unreviewed. */

undefined4 FUN_0001f510(int param_1)

{
  if (*(HANDLE *)(param_1 + 8) != (HANDLE)0xffffffff) {
    CloseHandle(*(HANDLE *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (*(void **)(param_1 + 0x30) != (void *)0x0) {
      free(*(void **)(param_1 + 0x30));
    }
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  return 1;
}



/* 0001f5a8 FUN_0001f5a8 */

/* Boundary evidence: original MIPS .pdata 0001f5a8..0001f5cb. Semantic name remains unreviewed. */

void FUN_0001f5a8(undefined4 *param_1)

{
  *param_1 = std::bad_alloc::vftable;
  __1exception_std__UAA_XZ();
  return;
}



/* 0001f5cc FUN_0001f5cc */

/* Boundary evidence: original MIPS .pdata 0001f5cc..0001f623. Semantic name remains unreviewed. */

undefined4 * FUN_0001f5cc(undefined4 *param_1,uint param_2)

{
  *param_1 = std::bad_alloc::vftable;
  __1exception_std__UAA_XZ(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001f624 FUN_0001f624 */

/* Boundary evidence: original MIPS .pdata 0001f624..0001f6a3. Semantic name remains unreviewed. */

undefined4 * FUN_0001f624(undefined4 *param_1,int param_2)

{
  __0exception_std__QAA_XZ(param_1);
  *param_1 = std::logic_error::vftable;
  param_1[9] = 0xf;
  param_1[8] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00021ed0((int)(param_1 + 3),param_2,0,0xffffffff);
  return param_1;
}



/* 0001f6a4 Unwind@0001f6a4 */

/* Boundary evidence: original MIPS .pdata 0001f6a4..0001f6d3. Semantic name remains unreviewed. */

void Unwind_0001f6a4(void)

{
  undefined4 *in_v0;
  
  __1exception_std__UAA_XZ(*in_v0);
  return;
}



/* 0001f6d4 FUN_0001f6d4 */

int FUN_0001f6d4(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x24)) {
    return *(int *)(param_1 + 0x10);
  }
  return param_1 + 0x10;
}



/* 0001f6fc FUN_0001f6fc */

/* Boundary evidence: original MIPS .pdata 0001f6fc..0001f757. Semantic name remains unreviewed. */

void FUN_0001f6fc(undefined4 *param_1)

{
  *param_1 = std::logic_error::vftable;
  if (0xf < (uint)param_1[9]) {
    __3_YAXPAX_Z(param_1[4]);
  }
  param_1[9] = 0xf;
  param_1[8] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  __1exception_std__UAA_XZ(param_1);
  return;
}



/* 0001f758 FUN_0001f758 */

/* Boundary evidence: original MIPS .pdata 0001f758..0001f7d3. Semantic name remains unreviewed. */

undefined4 * FUN_0001f758(undefined4 *param_1,uint param_2)

{
  *param_1 = std::logic_error::vftable;
  if (0xf < (uint)param_1[9]) {
    __3_YAXPAX_Z(param_1[4]);
  }
  param_1[9] = 0xf;
  param_1[8] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  __1exception_std__UAA_XZ(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001f7d4 FUN_0001f7d4 */

/* Boundary evidence: original MIPS .pdata 0001f7d4..0001f9f7. Semantic name remains unreviewed. */

undefined4 FUN_0001f7d4(undefined4 *param_1,char *param_2,UINT param_3)

{
  char cVar1;
  LPWSTR lpWideCharStr;
  undefined2 *puVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  LPCSTR lpMultiByteStr;
  
  pcVar4 = param_2;
  if (param_2 == (char *)0x0) {
    return 0;
  }
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if ((int)pcVar4 - (int)param_2 == 1) {
    return 0;
  }
  pcVar4 = strstr(param_2,"../");
  if (pcVar4 != (char *)0x0) {
    return 0;
  }
  pcVar4 = strstr(param_2,"..\\");
  if (pcVar4 != (char *)0x0) {
    return 0;
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
  }
  pcVar4 = _strdup(param_2);
  *param_1 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    return 0;
  }
  cVar1 = *pcVar4;
  while (cVar1 != '\0') {
    if (*pcVar4 == '/') {
      *pcVar4 = '\\';
    }
    pcVar4 = pcVar4 + 1;
    cVar1 = *pcVar4;
  }
  pcVar6 = (char *)*param_1;
  pcVar4 = pcVar6;
  if (pcVar6 != (char *)0x0) {
    do {
      pcVar5 = pcVar4;
      pcVar4 = pcVar5 + 1;
    } while (*pcVar5 != '\0');
    while ((pcVar5 = pcVar5 + -1, pcVar6 <= pcVar5 && ((*pcVar5 == '\r' || (*pcVar5 == '\n'))))) {
      *pcVar5 = '\0';
    }
  }
  lpMultiByteStr = (LPCSTR)*param_1;
  pcVar4 = lpMultiByteStr;
  if (lpMultiByteStr != (LPCSTR)0x0) {
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    iVar3 = (int)pcVar4 - (int)lpMultiByteStr;
    lpWideCharStr = malloc(iVar3 * 2);
    if (lpWideCharStr != (LPWSTR)0x0) {
      iVar3 = MultiByteToWideChar(param_3,0,lpMultiByteStr,-1,lpWideCharStr,iVar3);
      if (iVar3 != 0) goto LAB_0001f9a8;
      free(lpWideCharStr);
    }
  }
  lpWideCharStr = (LPWSTR)0x0;
LAB_0001f9a8:
  param_1[1] = lpWideCharStr;
  if (lpWideCharStr == (LPWSTR)0x0) {
    puVar2 = malloc(4);
    param_1[1] = puVar2;
    *puVar2 = 0x3f;
    *(undefined2 *)(param_1[1] + 2) = 0;
  }
  return 1;
}



/* 0001fa2c FUN_0001fa2c */

/* Boundary evidence: original MIPS .pdata 0001fa2c..0001fa9f. Semantic name remains unreviewed. */

void FUN_0001fa2c(int param_1)

{
  if (*(void **)(param_1 + 0x2a) != (void *)0x0) {
    free(*(void **)(param_1 + 0x2a));
  }
  if (*(void **)(param_1 + 0x2e) != (void *)0x0) {
    free(*(void **)(param_1 + 0x2e));
  }
  if (*(void **)(param_1 + 0x32) != (void *)0x0) {
    free(*(void **)(param_1 + 0x32));
  }
  return;
}



/* 0001faa0 FUN_0001faa0 */

/* Boundary evidence: original MIPS .pdata 0001faa0..0001facf. Semantic name remains unreviewed. */

void FUN_0001faa0(int param_1)

{
  if (*(void **)(param_1 + 0x12) != (void *)0x0) {
    free(*(void **)(param_1 + 0x12));
  }
  return;
}



/* 0001fad0 FUN_0001fad0 */

/* Boundary evidence: original MIPS .pdata 0001fad0..0001faff. Semantic name remains unreviewed. */

void FUN_0001fad0(int param_1)

{
  if (*(void **)(param_1 + 0x34) != (void *)0x0) {
    free(*(void **)(param_1 + 0x34));
  }
  return;
}



/* 0001fb00 FUN_0001fb00 */

/* Boundary evidence: original MIPS .pdata 0001fb00..0001fc2b. Semantic name remains unreviewed. */

int * FUN_0001fb00(int *param_1)

{
  int iVar1;
  
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[2] = 0;
  param_1[10] = (int)&PTR_FUN_00034c08;
  param_1[0x91] = (int)&DAT_0002c1b8;
  param_1[0x8e] = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[0x8b] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[1] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  *param_1 = (int)&PTR_FUN_00034afc;
  FUN_00022d9c(param_1 + 0xb1);
  iVar1 = FUN_00023730();
  param_1[0xb7] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(param_1[0xb7] + 4) = param_1[0xb7];
  *(int *)param_1[0xb7] = param_1[0xb7];
  *(int *)(param_1[0xb7] + 8) = param_1[0xb7];
  param_1[0xb8] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x96] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0x95] = 0;
  memset(param_1 + 0x9a,0,0x48);
  (**(code **)(*param_1 + 0x48))(param_1);
  return param_1;
}



/* 0001fc2c Unwind@0001fc2c */

/* Boundary evidence: original MIPS .pdata 0001fc2c..0001fc5b. Semantic name remains unreviewed. */

void Unwind_0001fc2c(void)

{
  undefined4 *in_v0;
  
  FUN_00024f10((undefined4 *)*in_v0);
  return;
}



/* 0001fc5c Unwind@0001fc5c */

/* Boundary evidence: original MIPS .pdata 0001fc5c..0001fc8b. Semantic name remains unreviewed. */

void Unwind_0001fc5c(void)

{
  int in_v0;
  
  FUN_00021eb4(*(undefined4 **)(in_v0 + -0x14));
  return;
}



/* 0001fc8c Unwind@0001fc8c */

/* Boundary evidence: original MIPS .pdata 0001fc8c..0001fcbf. Semantic name remains unreviewed. */

void Unwind_0001fc8c(void)

{
  int *in_v0;
  
  FUN_0001fd0c((int *)(*in_v0 + 0x2c4));
  return;
}



/* 0001fcc0 FUN_0001fcc0 */

/* Boundary evidence: original MIPS .pdata 0001fcc0..0001fd0b. Semantic name remains unreviewed. */

int * FUN_0001fcc0(int *param_1,uint param_2)

{
  FUN_0001fd28(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001fd0c FUN_0001fd0c */

/* Boundary evidence: original MIPS .pdata 0001fd0c..0001fd27. Semantic name remains unreviewed. */

void FUN_0001fd0c(int *param_1)

{
  FUN_00021c98(param_1);
  return;
}



/* 0001fd28 FUN_0001fd28 */

/* Boundary evidence: original MIPS .pdata 0001fd28..0001fd8b. Semantic name remains unreviewed. */

void FUN_0001fd28(int *param_1)

{
  *param_1 = (int)&PTR_FUN_00034afc;
  FUN_00025188(param_1);
  FUN_00021c98(param_1 + 0xb1);
  FUN_00024f10(param_1);
  return;
}



/* 0001fd8c Unwind@0001fd8c */

/* Boundary evidence: original MIPS .pdata 0001fd8c..0001fdbb. Semantic name remains unreviewed. */

void Unwind_0001fd8c(void)

{
  undefined4 *in_v0;
  
  FUN_00024f10((undefined4 *)*in_v0);
  return;
}



/* 0001fdbc Unwind@0001fdbc */

/* Boundary evidence: original MIPS .pdata 0001fdbc..0001fdef. Semantic name remains unreviewed. */

void Unwind_0001fdbc(void)

{
  int *in_v0;
  
  FUN_0001fd0c((int *)(*in_v0 + 0x2c4));
  return;
}



/* 0001fdf0 FUN_0001fdf0 */

void FUN_0001fdf0(int param_1)

{
  *(undefined4 *)(param_1 + 0x2b0) = 0;
  *(undefined4 *)(param_1 + 0x2b4) = 0;
  *(undefined4 *)(param_1 + 0x2b8) = 0;
  *(undefined4 *)(param_1 + 700) = 0;
  *(undefined4 *)(param_1 + 0x2c0) = 0;
  return;
}



/* 0001fe08 FUN_0001fe08 */

/* Boundary evidence: original MIPS .pdata 0001fe08..00020157. Semantic name remains unreviewed. */

undefined4 FUN_0001fe08(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int local_30 [2];
  
  (**(code **)**(undefined4 **)(param_1 + 0x20))
            (*(undefined4 **)(param_1 + 0x20),&DAT_0002e1c8,param_1 + 0x2c0);
  iVar3 = FUN_00020158(param_1);
  if (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 0x2b8);
    bVar1 = false;
    if (((((iVar3 == 0) || (iVar3 == 4)) || (iVar3 == 0x400)) &&
        ((bVar2 = FUN_000216d4(param_1), CONCAT31(extraout_var,bVar2) == 1 &&
         (iVar3 = FUN_00020410(param_1), iVar3 == 0x6054b50)))) &&
       ((iVar3 = FUN_000211cc(param_1), iVar3 == 1 &&
        ((*(int *)(param_1 + 0x2b0) != -1 || (*(int *)(param_1 + 0x2b4) != 0)))))) {
      (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
      iVar3 = FUN_00020410(param_1);
      if (iVar3 == 0x4034b50) {
        (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
        while( true ) {
          while( true ) {
            while (iVar3 = FUN_00020410(param_1), iVar3 == 0x2014b50) {
              FUN_00020c30(param_1,1);
            }
            if (iVar3 != 0x6064b50) break;
            FUN_000213ec(param_1);
          }
          if (iVar3 != 0x7064b50) break;
          FUN_000214dc(param_1);
        }
        if (iVar3 != 0x6054b50) {
          if (iVar3 != 0x5054b50) {
            return 0;
          }
          return 1;
        }
        return 1;
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
      while (iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))
                               (*(int **)(param_1 + 0x20),local_30,4), iVar3 != 0) {
        if (local_30[0] == -1) {
          return 1;
        }
        if (local_30[0] == 0) goto LAB_00020140;
        if (local_30[0] == 0x4034b50) {
          iVar3 = FUN_000204a0(param_1,(undefined4 *)0x0);
          bVar1 = true;
        }
        else if (local_30[0] == 0x2014b50) {
          iVar3 = FUN_00020c30(param_1,0);
        }
        else if (local_30[0] == 0x6054b50) {
          iVar3 = FUN_000211cc(param_1);
        }
        else if (local_30[0] == 0x6064b50) {
          iVar3 = FUN_000213ec(param_1);
        }
        else {
          if (local_30[0] != 0x7064b50) {
            if (bVar1) {
              return 0;
            }
            goto LAB_0002010c;
          }
          iVar3 = FUN_000214dc(param_1);
        }
        if (iVar3 == 0) {
          return 0;
        }
        iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))();
        if (iVar3 != 0) {
          return 1;
        }
      }
      iVar3 = (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))();
      *(int *)(param_1 + 0x1c) = iVar3;
      if (iVar3 != 0) {
        return 1;
      }
      *(undefined4 *)(param_1 + 600) = 2;
LAB_00020140:
      if (bVar1) {
        *(undefined4 *)(param_1 + 600) = 0x100;
        return 0;
      }
    }
LAB_0002010c:
    *(undefined4 *)(param_1 + 600) = 0x101;
  }
  return 0;
}



/* 00020158 FUN_00020158 */

/* WARNING: Removing unreachable block (ram,0x000201c4) */
/* Boundary evidence: original MIPS .pdata 00020158..00020397. Semantic name remains unreviewed. */

undefined4 FUN_00020158(int param_1)

{
  char *_Memory;
  wchar_t *pwVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  pwVar1 = L"     PostMSG    [0]  hMcmWnd[0x%08X] g_bUpgrade %d  !@#+_!+@)$+)!@+$)  \r\n";
  uVar3 = 0;
  _Memory = malloc(0x32000);
  if (_Memory == (char *)0x0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x2b8) = 0;
  lVar4 = (**(code **)(**(int **)(param_1 + 0x20) + 0x24))();
  if (lVar4 < 0x32001) {
    pwVar1 = (wchar_t *)(**(code **)(**(int **)(param_1 + 0x20) + 0x24))();
  }
  if (((int)pwVar1 < 4) ||
     (iVar2 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))
                        (*(int **)(param_1 + 0x20),_Memory,pwVar1), iVar2 == 0)) goto LAB_00020370;
  if (*_Memory == 'P') {
    if (((_Memory[1] != 'K') || (_Memory[2] != '\x03')) || (_Memory[3] != '\x04')) {
      if ((((_Memory[1] != 'K') || (_Memory[2] != '\a')) || (_Memory[3] != '\b')) &&
         (((_Memory[1] != 'K' || (_Memory[2] != '0')) ||
          ((_Memory[3] != '0' ||
           ((((_Memory[4] != 'P' || (_Memory[5] != 'K')) || (_Memory[6] != '\x03')) ||
            (_Memory[7] != '\x04')))))))) goto LAB_00020304;
      *(undefined4 *)(param_1 + 0x2b8) = 4;
    }
  }
  else {
LAB_00020304:
    iVar2 = 0;
    if (0 < (int)pwVar1 + -5) {
      do {
        if (((_Memory[iVar2] == 'P') && (_Memory[iVar2 + 1] == 'K')) &&
           ((_Memory[iVar2 + 2] == '\x03' && (_Memory[iVar2 + 3] == '\x04')))) {
          *(int *)(param_1 + 0x2b8) = iVar2;
          break;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)pwVar1 + -5);
    }
  }
  uVar3 = 1;
LAB_00020370:
  free(_Memory);
  return uVar3;
}



/* 00020398 FUN_00020398 */

/* Boundary evidence: original MIPS .pdata 00020398..0002040f. Semantic name remains unreviewed. */

void FUN_00020398(int param_1)

{
  FUN_00022484(param_1 + 0x2c4,*(int **)(*(int *)(param_1 + 0x2dc) + 4));
  *(int *)(*(int *)(param_1 + 0x2dc) + 4) = *(int *)(param_1 + 0x2dc);
  *(undefined4 *)(param_1 + 0x2e0) = 0;
  *(undefined4 *)*(undefined4 *)(param_1 + 0x2dc) = *(undefined4 *)(param_1 + 0x2dc);
  *(int *)(*(int *)(param_1 + 0x2dc) + 8) = *(int *)(param_1 + 0x2dc);
  if (*(int **)(param_1 + 0x2c0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x2c0) + 8))();
    *(undefined4 *)(param_1 + 0x2c0) = 0;
  }
  return;
}



/* 00020410 FUN_00020410 */

/* Boundary evidence: original MIPS .pdata 00020410..0002049f. Semantic name remains unreviewed. */

undefined4 FUN_00020410(int param_1)

{
  int iVar1;
  undefined4 local_10 [2];
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))(*(int **)(param_1 + 0x20),local_10,4);
  if (iVar1 != 0) {
    return local_10[0];
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))();
  *(int *)(param_1 + 0x1c) = iVar1;
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 600) = 2;
  return 0;
}



/* 000204a0 FUN_000204a0 */

/* Boundary evidence: original MIPS .pdata 000204a0..0002076f. Semantic name remains unreviewed. */

undefined4 FUN_000204a0(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  void *_Memory;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 auStack_150 [2];
  byte local_14e;
  undefined4 local_14a;
  byte local_13a;
  char local_139;
  undefined2 local_138;
  char acStack_130 [264];
  uint local_28;
  
  local_28 = DAT_000372d4;
  _Memory = (void *)0x0;
  uVar4 = 0;
  uVar5 = (**(code **)(**(int **)(param_1 + 0x20) + 0x20))();
  iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))
                    (*(int **)(param_1 + 0x20),auStack_150,0x1a);
  if (iVar1 == 0) {
    uVar4 = (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))();
    *(undefined4 *)(param_1 + 0x1c) = uVar4;
    *(undefined4 *)(param_1 + 600) = 3;
    FUN_0002a0c4(local_28);
    return 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    param_2[0x12] = local_14a;
  }
  uVar2 = (uint)local_13a | ((int)local_139 << 0x18) >> 0x10;
  if (0x104 < uVar2 + 1) {
    *(undefined4 *)(param_1 + 600) = 4;
    goto LAB_0002073c;
  }
  uVar3 = 0;
  if (uVar2 != 0) {
    iVar1 = FUN_0002159c(param_1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 600) = 5;
      goto LAB_0002073c;
    }
    uVar3 = (uint)local_13a | ((int)local_139 << 0x18) >> 0x10;
  }
  uVar2 = (uint)(byte)local_138 | ((int)local_138._1_1_ << 0x18) >> 0x10;
  acStack_130[uVar3] = '\0';
  if (uVar2 == 0) {
LAB_0002065c:
    if ((param_2 != (undefined4 *)0x0) ||
       (param_2 = FUN_00020928(param_1,(int)auStack_150,(uint)uVar5,(int)((ulonglong)uVar5 >> 0x20),
                               acStack_130), param_2 != (undefined4 *)0x0)) {
      uVar4 = 1;
    }
    if (param_2 != (undefined4 *)0x0) {
      if ((local_14e & 8) == 0) {
        *(undefined1 *)(param_2 + 0x13) = *(undefined1 *)((int)param_2 + 0x2b);
      }
      else {
        *(undefined1 *)(param_2 + 0x13) = *(undefined1 *)((int)param_2 + 0x49);
      }
      if (_Memory != (void *)0x0) {
        FUN_00020770((int)_Memory,(int)local_138,(int)param_2);
      }
      uVar5 = (**(code **)(**(int **)(param_1 + 0x20) + 0x20))();
      *(undefined8 *)(param_2 + 0xc) = uVar5;
    }
    (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
  }
  else {
    _Memory = malloc(uVar2);
    if (_Memory == (void *)0x0) {
      *(undefined4 *)(param_1 + 600) = 6;
    }
    else {
      if ((local_138 == 0) || (iVar1 = FUN_0002159c(param_1), iVar1 != 0)) goto LAB_0002065c;
      *(undefined4 *)(param_1 + 600) = 7;
    }
  }
  if (_Memory != (void *)0x0) {
    free(_Memory);
  }
LAB_0002073c:
  FUN_0002a0c4(local_28);
  return uVar4;
}



/* 00020770 FUN_00020770 */

/* Boundary evidence: original MIPS .pdata 00020770..00020927. Semantic name remains unreviewed. */

undefined4 FUN_00020770(int param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  short *psVar4;
  int iVar5;
  
  if ((param_2 < 5) || (param_3 == 0)) {
    uVar3 = 0;
  }
  else {
    iVar5 = 0;
    if (0 < param_2) {
      do {
        psVar4 = (short *)(iVar5 + param_1);
        sVar2 = *psVar4;
        if (sVar2 == 1) {
          if (7 < (ushort)psVar4[1]) {
            *(undefined4 *)(param_3 + 0x18) = *(undefined4 *)(psVar4 + 2);
            *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(psVar4 + 4);
          }
          if (0xf < (ushort)psVar4[1]) {
            *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(psVar4 + 6);
            *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(psVar4 + 8);
          }
        }
        else if ((((sVar2 != 10) && (sVar2 != 0x7075)) && (sVar2 != -0x1a86)) && (sVar2 == -0x66ff))
        {
          cVar1 = (char)psVar4[4];
          if (cVar1 == '\x01') {
            *(undefined4 *)(param_3 + 0x20) = 2;
          }
          else if (cVar1 == '\x02') {
            *(undefined4 *)(param_3 + 0x20) = 3;
          }
          else if (cVar1 == '\x03') {
            *(undefined4 *)(param_3 + 0x20) = 4;
          }
          if (*(int *)(param_3 + 0x2c) == 99) {
            *(uint *)(param_3 + 0x2c) = (uint)*(ushort *)((int)psVar4 + 9);
          }
        }
        iVar5 = (uint)(ushort)psVar4[1] + iVar5 + 4;
      } while (iVar5 < param_2);
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* 00020928 FUN_00020928 */

/* Boundary evidence: original MIPS .pdata 00020928..00020c2f. Semantic name remains unreviewed. */

undefined4 * FUN_00020928(int param_1,int param_2,uint param_3,undefined4 param_4,char *param_5)

{
  undefined4 *_Dst;
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  UINT UVar4;
  char *pcVar5;
  char cVar6;
  uint uVar7;
  undefined8 uVar8;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  _Dst = (undefined4 *)__2_YAPAXI_Z(0x58);
  if (_Dst == (undefined4 *)0x0) {
    _Dst = (undefined4 *)0x0;
  }
  else {
    memset(_Dst,0,0x58);
  }
  _Dst[0xe] = param_3;
  _Dst[0xf] = param_4;
  _Dst[0xc] = 0;
  _Dst[0xd] = 0;
  _Dst[9] = 0;
  _Dst[4] = *(undefined4 *)(param_2 + 0xe);
  _Dst[5] = 0;
  _Dst[6] = *(undefined4 *)(param_2 + 0x12);
  _Dst[7] = 0;
  uVar7 = *(uint *)(param_2 + 6);
  local_30 = 0;
  local_2c = 0;
  local_48 = (uVar7 & 0x1f) << 1;
  local_40 = (int)uVar7 >> 0xb & 0x1f;
  local_44 = (int)uVar7 >> 5 & 0x3f;
  local_3c = uVar7 >> 0x10 & 0x1f;
  local_38 = (uVar7 >> 0x15 & 0xf) - 1;
  local_34 = (uVar7 >> 0x19) + 0x50;
  local_28 = 0xffffffff;
  if (0x3b < local_44) {
    local_44 = 0x3b;
  }
  uVar8 = FUN_00024a68(&local_48);
  *(undefined8 *)(_Dst + 2) = uVar8;
  _Dst[10] = *(undefined4 *)(param_2 + 10);
  if ((_Dst[6] == -1) && (_Dst[7] == 0)) {
    *(undefined4 *)(param_1 + 700) = 1;
  }
  _Dst[0xb] = (int)*(short *)(param_2 + 4);
  *(undefined2 *)(_Dst + 0x11) = *(undefined2 *)(param_2 + 2);
  pcVar5 = param_5;
  if (param_5 == (char *)0x0) {
    cVar6 = '\0';
  }
  else {
    do {
      cVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar6 != '\0');
    if (pcVar5 + (-1 - (int)param_5) == (char *)0x0) {
      cVar6 = '\0';
    }
    else {
      cVar6 = param_5[(int)(pcVar5 + (-1 - (int)param_5) + -1)];
    }
  }
  if ((cVar6 == '\\') || (cVar6 == '/')) {
    _Dst[9] = _Dst[9] | 0x10;
  }
  if ((*(byte *)(param_2 + 2) & 1) != 0) {
    *(undefined4 *)(param_1 + 0x24) = 1;
    _Dst[8] = 1;
  }
  UVar4 = *(UINT *)(param_1 + 4);
  if ((UVar4 == 0) && ((*(byte *)(param_2 + 3) & 8) != 0)) {
    UVar4 = 0xfde9;
  }
  iVar1 = FUN_0001f7d4(_Dst,param_5,UVar4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 600) = 4;
    if ((void *)*_Dst != (void *)0x0) {
      free((void *)*_Dst);
    }
    *_Dst = 0;
    if ((void *)_Dst[1] != (void *)0x0) {
      free((void *)_Dst[1]);
    }
    puVar3 = (undefined4 *)_Dst[0x14];
    _Dst[1] = 0;
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(puVar3,1);
    }
    _Dst[0x14] = 0;
    __3_YAXPAX_Z(_Dst);
    _Dst = (undefined4 *)0x0;
  }
  else {
    FUN_00024608((int *)(param_1 + 8),(int)_Dst);
    piVar2 = FUN_00021b54((int *)(param_1 + 0x2c4),_Dst + 0xe);
    *piVar2 = (int)_Dst;
  }
  return _Dst;
}



/* 00020c30 FUN_00020c30 */

/* Boundary evidence: original MIPS .pdata 00020c30..0002119b. Semantic name remains unreviewed. */

undefined4 FUN_00020c30(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  ushort uVar6;
  longlong lVar7;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66;
  undefined1 local_65;
  undefined1 local_64;
  undefined1 local_63;
  int local_62;
  undefined4 local_5e;
  undefined4 local_5a;
  undefined4 local_56;
  byte local_52;
  char local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 auStack_48 [2];
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  undefined1 local_3f;
  short local_3e;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  byte local_30;
  char local_2f;
  undefined2 local_2e;
  byte local_2c;
  char local_2b;
  short local_2a;
  uint local_26;
  uint local_22;
  char *local_1e;
  void *local_1a;
  void *local_16;
  
  memset(auStack_48,0,0x36);
  iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))
                    (*(int **)(param_1 + 0x20),auStack_48,0x2a);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))();
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
LAB_00020c9c:
    *(undefined4 *)(param_1 + 600) = 8;
    if (local_1e != (char *)0x0) {
      free(local_1e);
    }
    if (local_1a != (void *)0x0) {
      free(local_1a);
    }
    if (local_16 != (void *)0x0) {
      free(local_16);
    }
    return 0;
  }
  uVar5 = (uint)local_30 | ((int)local_2f << 0x18) >> 0x10;
  if (uVar5 != 0) {
    local_1e = malloc(uVar5 + 1);
    if (local_1e == (char *)0x0) {
      *(undefined4 *)(param_1 + 600) = 9;
      if (local_1a != (void *)0x0) {
        free(local_1a);
      }
      if (local_16 != (void *)0x0) {
        free(local_16);
      }
      return 0;
    }
    uVar5 = 0;
    if (local_30 != 0 || ((int)local_2f << 0x18) >> 0x10 != 0) {
      iVar1 = FUN_0002159c(param_1);
      if (iVar1 == 0) goto LAB_00020c9c;
      uVar5 = (uint)local_30 | ((int)local_2f << 0x18) >> 0x10;
    }
    local_1e[uVar5] = '\0';
  }
  uVar5 = (uint)(byte)local_2e | ((int)local_2e._1_1_ << 0x18) >> 0x10;
  uVar6 = 0;
  if (uVar5 != 0) {
    local_1a = malloc(uVar5);
    if (local_1a == (void *)0x0) goto LAB_00020c9c;
    uVar6 = 0;
    if ((byte)local_2e != '\0' || ((int)local_2e._1_1_ << 0x18) >> 0x10 != 0) {
      iVar1 = FUN_0002159c(param_1);
      if (iVar1 == 0) goto LAB_00020c9c;
      uVar6 = local_2e & 0xff | (ushort)((uint)((int)local_2e._1_1_ << 0x18) >> 0x10);
    }
  }
  uVar5 = (uint)local_2c | ((int)local_2b << 0x18) >> 0x10;
  if (uVar5 != 0) {
    local_16 = malloc(uVar5 + 1);
    if (local_16 == (void *)0x0) goto LAB_00020c9c;
    uVar5 = 0;
    if (local_2c != 0 || ((int)local_2b << 0x18) >> 0x10 != 0) {
      iVar1 = FUN_0002159c(param_1);
      if (iVar1 == 0) goto LAB_00020c9c;
      uVar5 = (uint)local_2c | ((int)local_2b << 0x18) >> 0x10;
    }
    *(undefined1 *)(uVar5 + (int)local_16) = 0;
    uVar6 = local_2e & 0xff | (ushort)((uint)((int)local_2e._1_1_ << 0x18) >> 0x10);
  }
  if (param_2 == 0) {
    if (local_22 == 0) goto LAB_00021134;
    puVar3 = (undefined4 *)FUN_00021608(param_1,local_22);
  }
  else {
    local_68 = local_46;
    local_66 = local_44;
    local_67 = local_45;
    local_65 = local_43;
    local_64 = local_42;
    local_63 = local_41;
    local_62 = local_3e * 0x10000 + (int)CONCAT11(local_3f,local_40);
    local_5e = local_3c;
    local_5a = local_38;
    local_56 = local_34;
    piVar4 = *(int **)(param_1 + 0x2c0);
    local_52 = local_30;
    local_51 = local_2f;
    local_50 = (undefined1)uVar6;
    local_4f = (undefined1)(uVar6 >> 8);
    if (piVar4 == (int *)0x0) {
      lVar7 = 0;
    }
    else {
      lVar7 = (**(code **)(*piVar4 + 0x40))(piVar4,(int)local_2a);
    }
    puVar3 = FUN_00020928(param_1,(int)&local_68,(uint)(lVar7 + (ulonglong)local_22),
                          (int)(lVar7 + (ulonglong)local_22 >> 0x20),local_1e);
  }
  if (puVar3 != (undefined4 *)0x0) {
    if ((local_26 & 1) != 0) {
      puVar3[9] = puVar3[9] | 1;
    }
    if ((local_26 & 2) != 0) {
      puVar3[9] = puVar3[9] | 2;
    }
    if ((local_26 & 0x10) != 0) {
      puVar3[9] = puVar3[9] | 0x10;
    }
    if ((local_26 & 0x20) != 0) {
      puVar3[9] = puVar3[9] | 0x20;
    }
    if (local_1a != (void *)0x0) {
      FUN_00020770((int)local_1a,(int)(short)local_2e,(int)puVar3);
    }
  }
LAB_00021134:
  if (local_1e != (char *)0x0) {
    free(local_1e);
  }
  if (local_1a != (void *)0x0) {
    free(local_1a);
  }
  if (local_16 != (void *)0x0) {
    free(local_16);
  }
  return 1;
}



/* 0002119c Unwind@0002119c */

/* Boundary evidence: original MIPS .pdata 0002119c..000211cb. Semantic name remains unreviewed. */

void Unwind_0002119c(void)

{
  int in_v0;
  
  FUN_0001fa2c(in_v0 + -0x48);
  return;
}



/* 000211cc FUN_000211cc */

/* Boundary evidence: original MIPS .pdata 000211cc..000213bb. Semantic name remains unreviewed. */

undefined4 FUN_000211cc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStack_28 [2];
  short local_26;
  uint local_1c;
  byte local_18;
  char local_17;
  void *local_16;
  
  memset(auStack_28,0,0x16);
  iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))
                    (*(int **)(param_1 + 0x20),auStack_28,0x12);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))();
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    *(undefined4 *)(param_1 + 600) = 0x12;
    if (local_16 != (void *)0x0) {
      free(local_16);
    }
    uVar2 = 0;
  }
  else {
    uVar4 = (uint)local_18 | ((int)local_17 << 0x18) >> 0x10;
    if (uVar4 != 0) {
      local_16 = malloc(uVar4 + 1);
      if (local_16 == (void *)0x0) {
        *(undefined4 *)(param_1 + 600) = 0x11;
        return 0;
      }
      uVar4 = 0;
      if (local_18 != 0 || ((int)local_17 << 0x18) >> 0x10 != 0) {
        iVar1 = FUN_0002159c(param_1);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 600) = 0x12;
          if (local_16 != (void *)0x0) {
            free(local_16);
          }
          return 0;
        }
        uVar4 = (uint)local_18 | ((int)local_17 << 0x18) >> 0x10;
      }
      *(undefined1 *)(uVar4 + (int)local_16) = 0;
    }
    piVar3 = *(int **)(param_1 + 0x2c0);
    if (piVar3 == (int *)0x0) {
      *(uint *)(param_1 + 0x2b0) = local_1c;
      *(undefined4 *)(param_1 + 0x2b4) = 0;
    }
    else {
      lVar5 = (**(code **)(*piVar3 + 0x40))(piVar3,(int)local_26);
      *(ulonglong *)(param_1 + 0x2b0) = lVar5 + (ulonglong)local_1c;
    }
    if (local_16 != (void *)0x0) {
      free(local_16);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 000213bc Unwind@000213bc */

/* Boundary evidence: original MIPS .pdata 000213bc..000213eb. Semantic name remains unreviewed. */

void Unwind_000213bc(void)

{
  int in_v0;
  
  FUN_0001faa0(in_v0 + -0x28);
  return;
}



/* 000213ec FUN_000213ec */

/* Boundary evidence: original MIPS .pdata 000213ec..000214ab. Semantic name remains unreviewed. */

undefined4 FUN_000213ec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_48 [52];
  void *local_14;
  
  memset(auStack_48,0,0x38);
  iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))
                    (*(int **)(param_1 + 0x20),auStack_48,0x34);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))();
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    *(undefined4 *)(param_1 + 600) = 0x12;
    if (local_14 != (void *)0x0) {
      free(local_14);
    }
    uVar2 = 0;
  }
  else {
    if (local_14 != (void *)0x0) {
      free(local_14);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 000214ac Unwind@000214ac */

/* Boundary evidence: original MIPS .pdata 000214ac..000214db. Semantic name remains unreviewed. */

void Unwind_000214ac(void)

{
  int in_v0;
  
  FUN_0001fad0(in_v0 + -0x48);
  return;
}



/* 000214dc FUN_000214dc */

/* Boundary evidence: original MIPS .pdata 000214dc..0002159b. Semantic name remains unreviewed. */

undefined4 FUN_000214dc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  local_18 = 0;
  local_17 = 0;
  local_16 = 0;
  local_15 = 0;
  local_14 = 0;
  local_13 = 0;
  local_12 = 0;
  local_11 = 0;
  local_10 = 0;
  local_f = 0;
  local_e = 0;
  local_d = 0;
  local_c = 0;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))(*(int **)(param_1 + 0x20),&local_18,0x10)
  ;
  if (iVar1 == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))();
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    *(undefined4 *)(param_1 + 600) = 0x12;
    return 0;
  }
  return 1;
}



/* 0002159c FUN_0002159c */

/* Boundary evidence: original MIPS .pdata 0002159c..00021607. Semantic name remains unreviewed. */

undefined4 FUN_0002159c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))();
  if (iVar1 == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))();
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    return 0;
  }
  return 1;
}



/* 00021608 FUN_00021608 */

/* Boundary evidence: original MIPS .pdata 00021608..000216d3. Semantic name remains unreviewed. */

undefined4 FUN_00021608(int param_1,uint param_2)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint local_28;
  undefined4 local_24;
  int *local_20;
  int local_1c;
  int aiStack_18 [2];
  
  local_24 = 0;
  local_28 = param_2;
  piVar2 = FUN_00021d3c((int *)(param_1 + 0x2c4),aiStack_18,&local_28);
  piVar5 = (int *)*piVar2;
  iVar6 = piVar2[1];
  local_24 = *(undefined4 *)(param_1 + 0x2dc);
  local_28 = *(uint *)(param_1 + 0x2c4);
  local_20 = piVar5;
  local_1c = iVar6;
  bVar1 = FUN_00021e20((int *)&local_20,(int *)&local_28);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (piVar5 == (int *)0x0) {
      FUN_0002af00();
      iVar4 = 0;
    }
    else {
      iVar4 = *piVar5;
    }
    if (iVar6 == *(int *)(iVar4 + 0x18)) {
      FUN_0002af00();
    }
    uVar3 = *(undefined4 *)(iVar6 + 0x18);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 000216d4 FUN_000216d4 */

/* WARNING: Removing unreachable block (ram,0x000217c4) */
/* WARNING: Removing unreachable block (ram,0x00021794) */
/* WARNING: Removing unreachable block (ram,0x00021764) */
/* WARNING: Removing unreachable block (ram,0x00021924) */
/* Boundary evidence: original MIPS .pdata 000216d4..000219a3. Semantic name remains unreviewed. */

bool FUN_000216d4(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  void *_Memory;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  longlong lVar13;
  int local_34;
  
  _Memory = malloc(0x404);
  if (_Memory == (void *)0x0) {
    bVar3 = false;
  }
  else {
    lVar12 = (**(code **)(**(int **)(param_1 + 0x20) + 0x24))();
    uVar11 = 0;
    local_34 = 0;
    lVar1 = 0xffff;
    if (lVar12 < 0xffff) {
      lVar1 = lVar12;
    }
    lVar2 = 4;
    iVar8 = 0;
    if (4 < lVar1) {
      do {
        lVar2 = lVar2 + 0x400;
        if (lVar1 < lVar2) {
          lVar2 = lVar1;
        }
        uVar10 = (uint)(lVar12 - lVar2);
        iVar9 = (int)((ulonglong)(lVar12 - lVar2) >> 0x20);
        uVar7 = (uint)lVar12 - uVar10;
        uVar6 = (uint)((uint)lVar12 < uVar10);
        uVar5 = (int)((ulonglong)lVar12 >> 0x20) - iVar9;
        if ((-1 < (int)(uVar5 - uVar6)) && ((uVar5 != uVar6 || (0x404 < uVar7)))) {
          uVar7 = 0x404;
        }
        lVar13 = (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
        iVar8 = local_34;
        if ((lVar13 != lVar12 - lVar2) ||
           (iVar4 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))
                              (*(int **)(param_1 + 0x20),_Memory,uVar7), iVar4 != 1)) break;
        uVar5 = uVar7 - 3;
        do {
          uVar6 = uVar5;
          if ((int)uVar6 < 1) goto LAB_0002190c;
          uVar5 = uVar6 - 1;
        } while ((((*(char *)(uVar5 + (int)_Memory) != 'P') ||
                  (*(char *)((int)_Memory + uVar6) != 'K')) ||
                 (*(char *)((int)_Memory + uVar6 + 1) != '\x05')) ||
                (*(char *)((int)_Memory + uVar6 + 2) != '\x06'));
        uVar11 = uVar5 + uVar10;
        local_34 = ((int)uVar5 >> 0x1f) + iVar9 + (uint)(uVar11 < uVar5);
        iVar8 = local_34;
        if (uVar11 != 0 || local_34 != 0) break;
LAB_0002190c:
        iVar8 = local_34;
      } while (lVar2 < lVar1);
    }
    free(_Memory);
    (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
    bVar3 = uVar11 != 0 || iVar8 != 0;
  }
  return bVar3;
}



/* 000219a4 FUN_000219a4 */

/* Boundary evidence: original MIPS .pdata 000219a4..00021b0b. Semantic name remains unreviewed. */

undefined4 FUN_000219a4(int param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_3[0xc] == 0 && param_3[0xd] == 0) {
    uVar3 = 0;
    (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
    iVar1 = FUN_00020410(param_1);
    if ((iVar1 != 0x4034b50) || (iVar1 = FUN_000204a0(param_1,param_3), iVar1 == 0)) {
      piVar2 = *(int **)(param_1 + 0x264);
      *(undefined4 *)(param_1 + 600) = 0x100;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0xc))(piVar2,0x100,param_3,param_1 + 0x260,uVar3);
      }
      return 0;
    }
  }
  uVar3 = 0;
  (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
  if (param_3[0xb] == 0) {
    uVar3 = FUN_00025684(param_1,(int)param_3,*(int **)(param_1 + 0x20),param_4);
  }
  else if (param_3[0xb] == 8) {
    uVar3 = FUN_00025998(param_1,(int)param_3,*(int **)(param_1 + 0x20),param_4);
  }
  else {
    piVar2 = *(int **)(param_1 + 0x264);
    *(undefined4 *)(param_1 + 600) = 0x19;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,0x19,param_3,param_1 + 0x260,uVar3);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* 00021b0c FUN_00021b0c */

/* Boundary evidence: original MIPS .pdata 00021b0c..00021b53. Semantic name remains unreviewed. */

void FUN_00021b0c(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x18)) {
    __3_YAXPAX_Z(*(undefined4 *)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}



/* 00021b54 FUN_00021b54 */

/* Boundary evidence: original MIPS .pdata 00021b54..00021c97. Semantic name remains unreviewed. */

int * FUN_00021b54(int *param_1,uint *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int *local_38;
  int *local_34;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  
  FUN_000223fc(param_1,&local_38,param_2);
  local_2c = param_1[6];
  local_30 = *param_1;
  bVar1 = FUN_00021e20((int *)&local_38,&local_30);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if ((local_34[5] < (int)param_2[1]) ||
       ((param_2[1] == local_34[5] && ((uint)local_34[4] <= *param_2)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    piVar2 = local_34;
    if (!bVar1) goto LAB_00021c30;
  }
  local_28 = *param_2;
  local_24 = param_2[1];
  local_20 = 0;
  piVar2 = FUN_00022070(param_1,&local_30,(int)local_38,local_34,&local_28);
  local_38 = (int *)*piVar2;
  piVar2 = (int *)piVar2[1];
LAB_00021c30:
  if (local_38 == (int *)0x0) {
    FUN_0002af00();
    iVar3 = 0;
  }
  else {
    iVar3 = *local_38;
  }
  if (piVar2 == *(int **)(iVar3 + 0x18)) {
    FUN_0002af00();
  }
  return piVar2 + 6;
}



/* 00021c98 FUN_00021c98 */

/* Boundary evidence: original MIPS .pdata 00021c98..00021d0b. Semantic name remains unreviewed. */

void FUN_00021c98(int *param_1)

{
  int aiStack_18 [2];
  
  FUN_00022880(param_1,aiStack_18,*param_1,*(int **)param_1[6],*param_1,(int *)param_1[6]);
  __3_YAXPAX_Z(param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  __3_YAXPAX_Z(*param_1);
  return;
}



/* 00021d0c Unwind@00021d0c */

/* Boundary evidence: original MIPS .pdata 00021d0c..00021d3b. Semantic name remains unreviewed. */

void Unwind_00021d0c(void)

{
  undefined4 *in_v0;
  
  FUN_00021eb4((undefined4 *)*in_v0);
  return;
}



/* 00021d3c FUN_00021d3c */

/* Boundary evidence: original MIPS .pdata 00021d3c..00021e1f. Semantic name remains unreviewed. */

int * FUN_00021d3c(int *param_1,int *param_2,uint *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int iStack_20;
  int local_1c;
  int local_18;
  int local_14;
  
  FUN_000223fc(param_1,&iStack_20,param_3);
  local_14 = param_1[6];
  local_18 = *param_1;
  bVar1 = FUN_00021e20(&iStack_20,&local_18);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (((int)*(uint *)(local_1c + 0x14) < (int)param_3[1]) ||
       ((param_3[1] == *(uint *)(local_1c + 0x14) && (*(uint *)(local_1c + 0x10) <= *param_3)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      piVar2 = &iStack_20;
      goto LAB_00021df4;
    }
  }
  local_14 = param_1[6];
  piVar2 = &local_18;
  local_18 = *param_1;
LAB_00021df4:
  iVar3 = piVar2[1];
  *param_2 = *piVar2;
  param_2[1] = iVar3;
  return param_2;
}



/* 00021e20 FUN_00021e20 */

/* Boundary evidence: original MIPS .pdata 00021e20..00021eb3. Semantic name remains unreviewed. */

bool FUN_00021e20(int *param_1,int *param_2)

{
  if ((*param_1 == 0) || (*param_1 != *param_2)) {
    FUN_0002af00();
  }
  return param_1[1] == param_2[1];
}



/* 00021eb4 FUN_00021eb4 */

/* Boundary evidence: original MIPS .pdata 00021eb4..00021ecf. Semantic name remains unreviewed. */

void FUN_00021eb4(undefined4 *param_1)

{
  __3_YAXPAX_Z(*param_1);
  return;
}



/* 00021ed0 FUN_00021ed0 */

/* Boundary evidence: original MIPS .pdata 00021ed0..00021feb. Semantic name remains unreviewed. */

int FUN_00021ed0(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 *_Dst;
  undefined4 *puVar2;
  uint _MaxCount;
  
  if (*(uint *)(param_2 + 0x14) < param_3) {
    FUN_0002ac24();
  }
  _MaxCount = *(int *)(param_2 + 0x14) - param_3;
  if (param_4 < _MaxCount) {
    _MaxCount = param_4;
  }
  if (param_1 == param_2) {
    FUN_000224e8(param_1,_MaxCount + param_3,0xffffffff);
    FUN_000224e8(param_1,0,param_3);
  }
  else {
    iVar1 = FUN_000225cc(param_1,_MaxCount,0);
    if (iVar1 != 0) {
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        iVar1 = param_2 + 4;
      }
      else {
        iVar1 = *(int *)(param_2 + 4);
      }
      puVar2 = (undefined4 *)(param_1 + 4);
      _Dst = puVar2;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        _Dst = (undefined4 *)*puVar2;
      }
      memcpy_s(_Dst,*(uint *)(param_1 + 0x18),(void *)(iVar1 + param_3),_MaxCount);
      *(uint *)(param_1 + 0x14) = _MaxCount;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        puVar2 = (undefined4 *)*puVar2;
      }
      *(undefined1 *)((int)puVar2 + _MaxCount) = 0;
    }
  }
  return param_1;
}



/* 00021fec FUN_00021fec */

/* Boundary evidence: original MIPS .pdata 00021fec..0002206f. Semantic name remains unreviewed. */

void FUN_00021fec(int param_1,int param_2,rsize_t param_3)

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



/* 00022070 FUN_00022070 */

/* Boundary evidence: original MIPS .pdata 00022070..000223fb. Semantic name remains unreviewed. */

int * FUN_00022070(int *param_1,int *param_2,int param_3,int *param_4,uint *param_5)

{
  bool bVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int local_res8;
  int *local_resc;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24;
  
  local_res8 = param_3;
  local_resc = param_4;
  if (param_1[7] == 0) {
    FUN_000229f8(param_1,param_2,1,(int *)param_1[6],param_5);
    return param_2;
  }
  local_2c = *(int **)param_1[6];
  local_30 = *param_1;
  bVar1 = FUN_00021e20(&local_res8,&local_30);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    local_2c = (int *)param_1[6];
    local_30 = *param_1;
    bVar1 = FUN_00021e20(&local_res8,&local_30);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      uVar4 = param_5[1];
      uVar5 = *param_5;
      bVar1 = true;
      if ((local_resc[5] < (int)uVar4) ||
         ((uVar4 == local_resc[5] && ((uint)local_resc[4] <= uVar5)))) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_30 = local_res8;
        local_2c = local_resc;
        FUN_00023834(&local_30);
        uVar4 = param_5[1];
        uVar5 = *param_5;
        if (((int)uVar4 < local_2c[5]) || ((local_2c[5] == uVar4 && (uVar5 <= (uint)local_2c[4]))))
        {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          if (*(char *)(local_2c[2] + 0x21) != '\0') {
            FUN_000229f8(param_1,param_2,0,local_2c,param_5);
            return param_2;
          }
          FUN_000229f8(param_1,param_2,1,local_resc,param_5);
          return param_2;
        }
      }
      if (((int)uVar4 < local_resc[5]) ||
         ((local_resc[5] == uVar4 && (uVar5 <= (uint)local_resc[4])))) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_24 = param_1[6];
        local_28 = *param_1;
        local_30 = local_res8;
        local_2c = local_resc;
        FUN_00023948(&local_30);
        bVar2 = FUN_00021e20(&local_30,&local_28);
        if (CONCAT31(extraout_var_01,bVar2) == 0) {
          if ((local_2c[5] < (int)param_5[1]) ||
             ((param_5[1] == local_2c[5] && ((uint)local_2c[4] <= *param_5)))) {
            bVar1 = false;
          }
          if (!bVar1) goto LAB_000223bc;
        }
        if (*(char *)(local_resc[2] + 0x21) != '\0') {
          FUN_000229f8(param_1,param_2,0,local_resc,param_5);
          return param_2;
        }
        FUN_000229f8(param_1,param_2,1,local_2c,param_5);
        return param_2;
      }
    }
    else {
      piVar3 = *(int **)(param_1[6] + 8);
      if (((int)param_5[1] < piVar3[5]) ||
         ((piVar3[5] == param_5[1] && (*param_5 <= (uint)piVar3[4])))) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        FUN_000229f8(param_1,param_2,0,piVar3,param_5);
        return param_2;
      }
    }
  }
  else {
    bVar1 = true;
    if ((local_resc[5] < (int)param_5[1]) ||
       ((param_5[1] == local_resc[5] && ((uint)local_resc[4] <= *param_5)))) {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_000229f8(param_1,param_2,1,local_resc,param_5);
      return param_2;
    }
  }
LAB_000223bc:
  piVar3 = FUN_000226bc(param_1,&local_28,param_5);
  *param_2 = *piVar3;
  param_2[1] = piVar3[1];
  return param_2;
}



/* 000223fc FUN_000223fc */

undefined4 * FUN_000223fc(undefined4 *param_1,undefined4 *param_2,uint *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)param_1[6];
  if (*(char *)((int)puVar5[1] + 0x21) == '\0') {
    puVar3 = (undefined4 *)puVar5[1];
    do {
      if (((int)param_3[1] < (int)puVar3[5]) ||
         ((puVar3[5] == param_3[1] && (*param_3 <= (uint)puVar3[4])))) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = (undefined4 *)puVar3[2];
      }
      else {
        puVar4 = (undefined4 *)*puVar3;
        puVar5 = puVar3;
      }
      puVar3 = puVar4;
    } while (*(char *)((int)puVar4 + 0x21) == '\0');
  }
  uVar2 = *param_1;
  param_2[1] = puVar5;
  *param_2 = uVar2;
  return param_2;
}



/* 00022484 FUN_00022484 */

/* Boundary evidence: original MIPS .pdata 00022484..000224e7. Semantic name remains unreviewed. */

void FUN_00022484(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_2 + 0x21);
  while (cVar1 == '\0') {
    FUN_00022484(param_1,(int *)param_2[2]);
    piVar2 = (int *)*param_2;
    __3_YAXPAX_Z(param_2);
    param_2 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x21);
  }
  return;
}



/* 000224e8 FUN_000224e8 */

/* Boundary evidence: original MIPS .pdata 000224e8..000225cb. Semantic name remains unreviewed. */

int FUN_000224e8(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  if (*(uint *)(param_1 + 0x14) < param_2) {
    FUN_0002ac24();
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



/* 000225cc FUN_000225cc */

/* Boundary evidence: original MIPS .pdata 000225cc..000226bb. Semantic name remains unreviewed. */

undefined4 FUN_000225cc(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 == 0xffffffff) {
    FUN_0002ab94();
  }
  if (*(uint *)(param_1 + 0x18) < param_2) {
    FUN_00022f2c(param_1,param_2,*(rsize_t *)(param_1 + 0x14));
  }
  else if ((param_3 == 0) || (0xf < param_2)) {
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        **(undefined1 **)(param_1 + 4) = 0;
        return 0;
      }
      *(undefined1 *)(param_1 + 4) = 0;
      return 0;
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x14);
    if (param_2 < *(uint *)(param_1 + 0x14)) {
      uVar1 = param_2;
    }
    FUN_00021fec(param_1,1,uVar1);
  }
  if (param_2 == 0) {
    return 0;
  }
  return 1;
}



/* 000226bc FUN_000226bc */

/* Boundary evidence: original MIPS .pdata 000226bc..0002287f. Semantic name remains unreviewed. */

int * FUN_000226bc(int *param_1,int *param_2,uint *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_30;
  int *local_2c;
  int local_28;
  undefined4 local_24;
  
  piVar4 = (int *)param_1[6];
  iVar3 = 1;
  if (*(char *)(piVar4[1] + 0x21) == '\0') {
    piVar2 = (int *)piVar4[1];
    do {
      piVar4 = piVar2;
      if ((piVar4[5] < (int)param_3[1]) ||
         ((param_3[1] == piVar4[5] && ((uint)piVar4[4] <= *param_3)))) {
        iVar3 = 0;
      }
      else {
        iVar3 = 1;
      }
      if (iVar3 == 0) {
        piVar2 = (int *)piVar4[2];
      }
      else {
        piVar2 = (int *)*piVar4;
      }
    } while (*(char *)((int)piVar2 + 0x21) == '\0');
  }
  local_30 = *param_1;
  local_2c = piVar4;
  if (iVar3 != 0) {
    local_24 = *(undefined4 *)param_1[6];
    local_28 = local_30;
    bVar1 = FUN_00021e20(&local_30,&local_28);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      piVar4 = FUN_000229f8(param_1,&local_28,1,piVar4,param_3);
      iVar3 = piVar4[1];
      *param_2 = *piVar4;
      param_2[1] = iVar3;
      *(undefined1 *)(param_2 + 2) = 1;
      return param_2;
    }
    FUN_00023834(&local_30);
  }
  if (((int)param_3[1] < local_2c[5]) ||
     ((local_2c[5] == param_3[1] && (*param_3 <= (uint)local_2c[4])))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    piVar4 = FUN_000229f8(param_1,&local_28,iVar3,piVar4,param_3);
    iVar3 = piVar4[1];
    *param_2 = *piVar4;
    param_2[1] = iVar3;
    *(undefined1 *)(param_2 + 2) = 1;
  }
  else {
    *param_2 = local_30;
    param_2[1] = (int)local_2c;
    *(undefined1 *)(param_2 + 2) = 0;
  }
  return param_2;
}



/* 00022880 FUN_00022880 */

/* Boundary evidence: original MIPS .pdata 00022880..000229f7. Semantic name remains unreviewed. */

int * FUN_00022880(int *param_1,int *param_2,int param_3,int *param_4,int param_5,int *param_6)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  int local_res8;
  int *local_resc;
  int local_20;
  int local_1c;
  
  local_1c = *(int *)param_1[6];
  local_20 = *param_1;
  local_res8 = param_3;
  local_resc = param_4;
  bVar2 = FUN_00021e20(&local_res8,&local_20);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    local_1c = param_1[6];
    local_20 = *param_1;
    bVar2 = FUN_00021e20(&param_5,&local_20);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      FUN_00022484(param_1,*(int **)(param_1[6] + 4));
      *(int *)(param_1[6] + 4) = param_1[6];
      param_1[7] = 0;
      *(int *)param_1[6] = param_1[6];
      *(int *)(param_1[6] + 8) = param_1[6];
      iVar3 = *param_1;
      param_2[1] = *(int *)param_1[6];
      *param_2 = iVar3;
      return param_2;
    }
  }
  while( true ) {
    if ((local_res8 == 0) || (local_res8 != param_5)) {
      FUN_0002af00();
    }
    piVar1 = local_resc;
    iVar3 = local_res8;
    if (local_resc == param_6) break;
    FUN_00023948(&local_res8);
    FUN_00023180(param_1,&local_20,iVar3,piVar1);
  }
  *param_2 = *param_1;
  param_2[1] = (int)local_resc;
  return param_2;
}



/* 000229f8 FUN_000229f8 */

/* Boundary evidence: original MIPS .pdata 000229f8..00022d6b. Semantic name remains unreviewed. */

undefined4 *
FUN_000229f8(undefined4 *param_1,undefined4 *param_2,int param_3,int *param_4,undefined4 *param_5)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined1 auStack_70 [4];
  undefined1 local_6c;
  undefined4 local_5c;
  undefined4 local_58;
  undefined **appuStack_50 [10];
  uint local_28;
  
  local_28 = DAT_000372d4;
  if (0xffffffd < (uint)param_1[7]) {
    FUN_0002aa3c(auStack_70);
    local_58 = 0xf;
    local_5c = 0;
    local_6c = 0;
    FUN_00023b2c((int)auStack_70,(undefined4 *)"map/set<T> too long",0x13);
    FUN_0001f624(appuStack_50,auStack_70);
                    /* WARNING: Subroutine does not return */
    appuStack_50[0] = std::length_error::vftable;
    __CxxThrowException(appuStack_50,(ThrowInfo *)&DAT_0003639c);
  }
  piVar2 = (int *)FUN_00023784(param_1,param_1[6],param_4,param_1[6],param_5);
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
  piVar7 = piVar2 + 1;
  cVar1 = *(char *)(*piVar7 + 0x20);
  piVar8 = piVar2;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(param_1[6] + 4) + 0x20) = 1;
      *param_2 = 0;
      param_2[1] = piVar2;
      *param_2 = *param_1;
      FUN_0002a0c4(local_28);
      return param_2;
    }
    piVar4 = (int *)*piVar7;
    piVar3 = (int *)piVar4[1];
    if (piVar4 == (int *)*piVar3) {
      iVar6 = piVar3[2];
      if (*(char *)(iVar6 + 0x20) == '\0') {
        *(undefined1 *)(piVar4 + 8) = 1;
        *(undefined1 *)(iVar6 + 0x20) = 1;
        *(undefined1 *)(*(int *)(*piVar7 + 4) + 0x20) = 0;
        piVar8 = *(int **)(*piVar7 + 4);
      }
      else {
        if (piVar8 == (int *)piVar4[2]) {
          FUN_00023630((int)param_1,(int)piVar4);
          piVar8 = piVar4;
        }
        *(undefined1 *)(piVar8[1] + 0x20) = 1;
        *(undefined1 *)(*(int *)(piVar8[1] + 4) + 0x20) = 0;
        piVar7 = *(int **)(piVar8[1] + 4);
        piVar3 = (int *)*piVar7;
        *piVar7 = piVar3[2];
        if (*(char *)(piVar3[2] + 0x21) == '\0') {
          *(int **)(piVar3[2] + 4) = piVar7;
        }
        piVar3[1] = piVar7[1];
        if (piVar7 == *(int **)(param_1[6] + 4)) {
          *(int **)(param_1[6] + 4) = piVar3;
          piVar3[2] = (int)piVar7;
        }
        else {
          puVar5 = (undefined4 *)piVar7[1];
          if (piVar7 == (int *)puVar5[2]) {
            puVar5[2] = piVar3;
            piVar3[2] = (int)piVar7;
          }
          else {
            *puVar5 = piVar3;
            piVar3[2] = (int)piVar7;
          }
        }
LAB_00022d04:
        piVar7[1] = (int)piVar3;
      }
    }
    else {
      iVar6 = *piVar3;
      if (*(char *)(iVar6 + 0x20) != '\0') {
        if (piVar8 == (int *)*piVar4) {
          FUN_000236b0((int)param_1,piVar4);
          piVar8 = piVar4;
        }
        *(undefined1 *)(piVar8[1] + 0x20) = 1;
        *(undefined1 *)(*(int *)(piVar8[1] + 4) + 0x20) = 0;
        piVar7 = *(int **)(piVar8[1] + 4);
        piVar3 = (int *)piVar7[2];
        piVar7[2] = *piVar3;
        if (*(char *)(*piVar3 + 0x21) == '\0') {
          *(int **)(*piVar3 + 4) = piVar7;
        }
        piVar3[1] = piVar7[1];
        if (piVar7 == *(int **)(param_1[6] + 4)) {
          *(int **)(param_1[6] + 4) = piVar3;
        }
        else {
          puVar5 = (undefined4 *)piVar7[1];
          if (piVar7 == (int *)*puVar5) {
            *puVar5 = piVar3;
          }
          else {
            puVar5[2] = piVar3;
          }
        }
        *piVar3 = (int)piVar7;
        goto LAB_00022d04;
      }
      *(undefined1 *)(*piVar7 + 0x20) = 1;
      *(undefined1 *)(iVar6 + 0x20) = 1;
      *(undefined1 *)(*(int *)(*piVar7 + 4) + 0x20) = 0;
      piVar8 = *(int **)(*piVar7 + 4);
    }
    piVar7 = piVar8 + 1;
    cVar1 = *(char *)(*piVar7 + 0x20);
  } while( true );
}



/* 00022d6c Unwind@00022d6c */

/* Boundary evidence: original MIPS .pdata 00022d6c..00022d9b. Semantic name remains unreviewed. */

void Unwind_00022d6c(void)

{
  int in_v0;
  
  FUN_00021b0c(in_v0 + -0x70);
  return;
}



/* 00022d9c FUN_00022d9c */

/* Boundary evidence: original MIPS .pdata 00022d9c..00022dcb. Semantic name remains unreviewed. */

int * FUN_00022d9c(int *param_1)

{
  FUN_00023804(param_1);
  return param_1;
}



/* 00022dcc FUN_00022dcc */

/* Boundary evidence: original MIPS .pdata 00022dcc..00022e03. Semantic name remains unreviewed. */

undefined4 * FUN_00022dcc(undefined4 *param_1,int param_2)

{
  FUN_00022e04(param_1,param_2);
  *param_1 = std::length_error::vftable;
  return param_1;
}



/* 00022e04 FUN_00022e04 */

/* Boundary evidence: original MIPS .pdata 00022e04..00022e87. Semantic name remains unreviewed. */

undefined4 * FUN_00022e04(undefined4 *param_1,int param_2)

{
  __0exception_std__QAA_ABV01__Z(param_1,param_2);
  *param_1 = std::logic_error::vftable;
  param_1[9] = 0xf;
  param_1[8] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00021ed0((int)(param_1 + 3),param_2 + 0xc,0,0xffffffff);
  return param_1;
}



/* 00022e88 Unwind@00022e88 */

/* Boundary evidence: original MIPS .pdata 00022e88..00022eb7. Semantic name remains unreviewed. */

void Unwind_00022e88(void)

{
  undefined4 *in_v0;
  
  __1exception_std__UAA_XZ(*in_v0);
  return;
}



/* 00022eb8 FUN_00022eb8 */

/* Boundary evidence: original MIPS .pdata 00022eb8..00022f2b. Semantic name remains unreviewed. */

int FUN_00022eb8(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  FUN_0002aa3c(param_1);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00023b2c(param_1,(undefined4 *)param_2,(uint)(pcVar2 + (-1 - (int)param_2)));
  return param_1;
}



/* 00022f2c FUN_00022f2c */

/* Boundary evidence: original MIPS .pdata 00022f2c..000230e3. Semantic name remains unreviewed. */

void FUN_00022f2c(int param_1,uint param_2,rsize_t param_3)

{
  undefined4 *_Dst;
  void *_Src;
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined **local_28 [4];
  
  uVar4 = param_2 | 0xf;
  if (uVar4 != 0xffffffff) {
    uVar2 = *(uint *)(param_1 + 0x18);
    uVar3 = uVar2 >> 1;
    param_2 = uVar4;
    if ((uVar4 / 3 < uVar3) && (uVar2 <= -uVar3 - 2)) {
      param_2 = uVar3 + uVar2;
    }
  }
  uVar4 = param_2 + 1;
  if (uVar4 == 0) {
    uVar4 = 0;
  }
  else {
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    if (0xffffffff / uVar4 == 0) {
      __0exception_std__QAA_PBD_Z(local_28,0);
      local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException(local_28,(ThrowInfo *)&DAT_00036410);
    }
  }
  _Dst = (undefined4 *)__2_YAPAXI_Z(uVar4);
  if (param_3 != 0) {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      _Src = (void *)(param_1 + 4);
    }
    else {
      _Src = *(void **)(param_1 + 4);
    }
    memcpy_s(_Dst,param_2 + 1,_Src,param_3);
  }
  if (0xf < *(uint *)(param_1 + 0x18)) {
    __3_YAXPAX_Z(*(undefined4 *)(param_1 + 4));
  }
  puVar1 = (undefined4 *)(param_1 + 4);
  *(undefined1 *)puVar1 = 0;
  *puVar1 = _Dst;
  *(uint *)(param_1 + 0x18) = param_2;
  *(rsize_t *)(param_1 + 0x14) = param_3;
  if (param_2 < 0x10) {
    _Dst = puVar1;
  }
  *(undefined1 *)((int)_Dst + param_3) = 0;
  return;
}



/* 000230e4 FUN_000230e4 */

/* Boundary evidence: original MIPS .pdata 000230e4..00023137. Semantic name remains unreviewed. */

void FUN_000230e4(void)

{
  int in_v0;
  int iVar1;
  
  iVar1 = **(int **)(in_v0 + -4);
  if (0xf < *(uint *)(iVar1 + 0x18)) {
    __3_YAXPAX_Z(*(undefined4 *)(iVar1 + 4));
  }
  *(undefined4 *)(iVar1 + 0x18) = 0xf;
  *(undefined4 *)(iVar1 + 0x14) = 0;
                    /* WARNING: Subroutine does not return */
  *(undefined1 *)(iVar1 + 4) = 0;
  __CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



/* 00023138 FUN_00023138 */

/* Boundary evidence: original MIPS .pdata 00023138..0002317f. Semantic name remains unreviewed. */

undefined * FUN_00023138(void)

{
  undefined4 *in_v0;
  undefined4 uVar1;
  
  in_v0[-0xc] = in_v0[1];
  uVar1 = FUN_00023a70(*in_v0,in_v0[1] + 1);
  in_v0[-0xb] = uVar1;
  return &DAT_00023038;
}



/* 00023180 FUN_00023180 */

/* Boundary evidence: original MIPS .pdata 00023180..000235ff. Semantic name remains unreviewed. */

undefined4 * FUN_00023180(undefined4 *param_1,undefined4 *param_2,int param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int local_res8;
  int *local_resc;
  undefined1 auStack_70 [4];
  undefined1 local_6c;
  undefined4 local_5c;
  undefined4 local_58;
  undefined **appuStack_50 [10];
  uint local_28;
  
  local_28 = DAT_000372d4;
  local_res8 = param_3;
  local_resc = param_4;
  if (*(char *)((int)param_4 + 0x21) != '\0') {
    FUN_0002aa3c(auStack_70);
    local_58 = 0xf;
    local_5c = 0;
    local_6c = 0;
    FUN_00023b2c((int)auStack_70,(undefined4 *)"invalid map/set<T> iterator",0x1b);
    FUN_0001f624(appuStack_50,auStack_70);
                    /* WARNING: Subroutine does not return */
    appuStack_50[0] = std::out_of_range::vftable;
    __CxxThrowException(appuStack_50,(ThrowInfo *)&DAT_000363d8);
  }
  FUN_00023948(&local_res8);
  piVar3 = (int *)*param_4;
  if (*(char *)((int)piVar3 + 0x21) == '\0') {
    piVar8 = piVar3;
    if ((*(char *)(param_4[2] + 0x21) == '\0') &&
       (piVar8 = (int *)local_resc[2], local_resc != param_4)) {
      piVar3[1] = (int)local_resc;
      *local_resc = *param_4;
      piVar3 = local_resc;
      if (local_resc != (int *)param_4[2]) {
        piVar3 = (int *)local_resc[1];
        if (*(char *)((int)piVar8 + 0x21) == '\0') {
          piVar8[1] = (int)piVar3;
        }
        *piVar3 = (int)piVar8;
        local_resc[2] = param_4[2];
        *(int **)(param_4[2] + 4) = local_resc;
      }
      if (*(int **)(param_1[6] + 4) == param_4) {
        *(int **)(param_1[6] + 4) = local_resc;
      }
      else {
        puVar5 = (undefined4 *)param_4[1];
        if ((int *)*puVar5 == param_4) {
          *puVar5 = local_resc;
        }
        else {
          puVar5[2] = local_resc;
        }
      }
      piVar6 = param_4 + 8;
      piVar4 = local_resc + 8;
      local_resc[1] = param_4[1];
      if (piVar4 != piVar6) {
        iVar7 = *piVar4;
        *(char *)piVar4 = (char)*piVar6;
        *(char *)piVar6 = (char)iVar7;
      }
      goto LAB_000233f0;
    }
  }
  else {
    piVar8 = (int *)param_4[2];
  }
  piVar3 = (int *)param_4[1];
  if (*(char *)((int)piVar8 + 0x21) == '\0') {
    piVar8[1] = (int)piVar3;
  }
  if (*(int **)(param_1[6] + 4) == param_4) {
    *(int **)(param_1[6] + 4) = piVar8;
  }
  else if ((int *)*piVar3 == param_4) {
    *piVar3 = (int)piVar8;
  }
  else {
    piVar3[2] = (int)piVar8;
  }
  if (*(int **)param_1[6] == param_4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar8 + 0x21) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x21);
      piVar4 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar2 = piVar4, cVar1 == '\0') {
        piVar4 = (int *)*piVar2;
        cVar1 = *(char *)((int)piVar4 + 0x21);
        piVar6 = piVar2;
      }
    }
    *(int **)param_1[6] = piVar6;
  }
  iVar7 = param_1[6];
  if (*(int **)(iVar7 + 8) == param_4) {
    if (*(char *)((int)piVar8 + 0x21) == '\0') {
      cVar1 = *(char *)(piVar8[2] + 0x21);
      piVar4 = (int *)piVar8[2];
      piVar6 = piVar8;
      while (piVar2 = piVar4, cVar1 == '\0') {
        piVar4 = (int *)piVar2[2];
        cVar1 = *(char *)((int)piVar4 + 0x21);
        piVar6 = piVar2;
      }
      *(int **)(iVar7 + 8) = piVar6;
    }
    else {
      *(int **)(iVar7 + 8) = piVar3;
    }
  }
LAB_000233f0:
  if ((char)param_4[8] == '\x01') {
    if (piVar8 != *(int **)(param_1[6] + 4)) {
      do {
        piVar6 = piVar3;
        if ((char)piVar8[8] != '\x01') break;
        piVar3 = (int *)*piVar6;
        if (piVar8 == piVar3) {
          piVar3 = (int *)piVar6[2];
          if ((char)piVar3[8] == '\0') {
            *(undefined1 *)(piVar3 + 8) = 1;
            *(undefined1 *)(piVar6 + 8) = 0;
            FUN_00023630((int)param_1,(int)piVar6);
            piVar3 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar3 + 0x21) == '\0') {
            if ((*(char *)(*piVar3 + 0x20) != '\x01') || (*(char *)(piVar3[2] + 0x20) != '\x01')) {
              if (*(char *)(piVar3[2] + 0x20) == '\x01') {
                *(undefined1 *)(*piVar3 + 0x20) = 1;
                *(undefined1 *)(piVar3 + 8) = 0;
                FUN_000236b0((int)param_1,piVar3);
                piVar3 = (int *)piVar6[2];
              }
              *(char *)(piVar3 + 8) = (char)piVar6[8];
              *(undefined1 *)(piVar6 + 8) = 1;
              *(undefined1 *)(piVar3[2] + 0x20) = 1;
              FUN_00023630((int)param_1,(int)piVar6);
              break;
            }
            *(undefined1 *)(piVar3 + 8) = 0;
          }
        }
        else {
          if ((char)piVar3[8] == '\0') {
            *(undefined1 *)(piVar3 + 8) = 1;
            *(undefined1 *)(piVar6 + 8) = 0;
            FUN_000236b0((int)param_1,piVar6);
            piVar3 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar3 + 0x21) == '\0') {
            if ((*(char *)(piVar3[2] + 0x20) != '\x01') || (*(char *)(*piVar3 + 0x20) != '\x01')) {
              if (*(char *)(*piVar3 + 0x20) == '\x01') {
                *(undefined1 *)(piVar3[2] + 0x20) = 1;
                *(undefined1 *)(piVar3 + 8) = 0;
                FUN_00023630((int)param_1,(int)piVar3);
                piVar3 = (int *)*piVar6;
              }
              *(char *)(piVar3 + 8) = (char)piVar6[8];
              *(undefined1 *)(piVar6 + 8) = 1;
              *(undefined1 *)(*piVar3 + 0x20) = 1;
              FUN_000236b0((int)param_1,piVar6);
              break;
            }
            *(undefined1 *)(piVar3 + 8) = 0;
          }
        }
        piVar3 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != *(int **)(param_1[6] + 4));
    }
    *(undefined1 *)(piVar8 + 8) = 1;
  }
  __3_YAXPAX_Z(param_4);
  if (param_1[7] != 0) {
    param_1[7] = param_1[7] + -1;
  }
  *param_2 = *param_1;
  param_2[1] = local_resc;
  FUN_0002a0c4(local_28);
  return param_2;
}



/* 00023600 Unwind@00023600 */

/* Boundary evidence: original MIPS .pdata 00023600..0002362f. Semantic name remains unreviewed. */

void Unwind_00023600(void)

{
  int in_v0;
  
  FUN_00021b0c(in_v0 + -0x70);
  return;
}



/* 00023630 FUN_00023630 */

void FUN_00023630(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_2 + 8);
  *(int *)(param_2 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x21) == '\0') {
    *(int *)(*piVar1 + 4) = param_2;
  }
  piVar1[1] = *(int *)(param_2 + 4);
  if (param_2 == *(int *)(*(int *)(param_1 + 0x18) + 4)) {
    *(int **)(*(int *)(param_1 + 0x18) + 4) = piVar1;
    *piVar1 = param_2;
    *(int **)(param_2 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_2 + 4);
  if (param_2 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_2;
    *(int **)(param_2 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_2;
  *(int **)(param_2 + 4) = piVar1;
  return;
}



/* 000236b0 FUN_000236b0 */

void FUN_000236b0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  *param_2 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x21) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_2;
  }
  *(int *)(iVar1 + 4) = param_2[1];
  if (param_2 == *(int **)(*(int *)(param_1 + 0x18) + 4)) {
    *(int *)(*(int *)(param_1 + 0x18) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_2;
    param_2[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_2[1];
  if (param_2 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_2;
    param_2[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_2;
  param_2[1] = iVar1;
  return;
}



/* 00023730 FUN_00023730 */

/* Boundary evidence: original MIPS .pdata 00023730..00023783. Semantic name remains unreviewed. */

void FUN_00023730(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 8) = 1;
  *(undefined1 *)((int)puVar1 + 0x21) = 0;
  return;
}



/* 00023784 FUN_00023784 */

/* Boundary evidence: original MIPS .pdata 00023784..00023803. Semantic name remains unreviewed. */

void FUN_00023784(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[4] = *param_5;
    puVar1[5] = param_5[1];
    puVar1[6] = param_5[2];
    puVar1[7] = param_5[3];
    *(undefined1 *)(puVar1 + 8) = 0;
    *(undefined1 *)((int)puVar1 + 0x21) = 0;
  }
  return;
}



/* 00023804 FUN_00023804 */

/* Boundary evidence: original MIPS .pdata 00023804..00023833. Semantic name remains unreviewed. */

int * FUN_00023804(int *param_1)

{
  FUN_00023af8(param_1);
  return param_1;
}



/* 00023834 FUN_00023834 */

/* Boundary evidence: original MIPS .pdata 00023834..00023947. Semantic name remains unreviewed. */

void FUN_00023834(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*param_1 == 0) {
    FUN_0002af00();
  }
  piVar3 = (int *)param_1[1];
  if (*(char *)((int)piVar3 + 0x21) == '\0') {
    iVar4 = *piVar3;
    if (*(char *)(iVar4 + 0x21) == '\0') {
      cVar1 = *(char *)(*(int *)(iVar4 + 8) + 0x21);
      iVar2 = *(int *)(iVar4 + 8);
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x21);
        iVar4 = iVar2;
        iVar2 = *(int *)(iVar2 + 8);
      }
      param_1[1] = iVar4;
      return;
    }
    piVar3 = (int *)piVar3[1];
    cVar1 = *(char *)((int)piVar3 + 0x21);
    while ((cVar1 == '\0' && (param_1[1] == *piVar3))) {
      param_1[1] = (int)piVar3;
      piVar3 = (int *)piVar3[1];
      cVar1 = *(char *)((int)piVar3 + 0x21);
    }
    if (*(char *)(param_1[1] + 0x21) == '\0') {
      param_1[1] = (int)piVar3;
      return;
    }
  }
  else {
    iVar4 = piVar3[2];
    param_1[1] = iVar4;
    if (*(char *)(iVar4 + 0x21) == '\0') {
      return;
    }
  }
  FUN_0002af00();
  return;
}



/* 00023948 FUN_00023948 */

/* Boundary evidence: original MIPS .pdata 00023948..00023a37. Semantic name remains unreviewed. */

void FUN_00023948(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if (*param_1 == 0) {
    FUN_0002af00();
  }
  iVar3 = param_1[1];
  if (*(char *)(iVar3 + 0x21) == '\0') {
    piVar4 = *(int **)(iVar3 + 8);
    if (*(char *)((int)piVar4 + 0x21) != '\0') {
      iVar3 = *(int *)(iVar3 + 4);
      cVar1 = *(char *)(iVar3 + 0x21);
      while ((cVar1 == '\0' && (param_1[1] == *(int *)(iVar3 + 8)))) {
        param_1[1] = iVar3;
        iVar3 = *(int *)(iVar3 + 4);
        cVar1 = *(char *)(iVar3 + 0x21);
      }
      param_1[1] = iVar3;
      return;
    }
    cVar1 = *(char *)(*piVar4 + 0x21);
    piVar2 = (int *)*piVar4;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*piVar2 + 0x21);
      piVar4 = piVar2;
      piVar2 = (int *)*piVar2;
    }
    param_1[1] = (int)piVar4;
    return;
  }
  FUN_0002af00();
  return;
}



/* 00023a38 FUN_00023a38 */

/* Boundary evidence: original MIPS .pdata 00023a38..00023a6f. Semantic name remains unreviewed. */

undefined4 * FUN_00023a38(undefined4 *param_1,int param_2)

{
  FUN_00022e04(param_1,param_2);
  *param_1 = std::out_of_range::vftable;
  return param_1;
}



/* 00023a70 FUN_00023a70 */

/* Boundary evidence: original MIPS .pdata 00023a70..00023af7. Semantic name remains unreviewed. */

void FUN_00023a70(undefined4 param_1,uint param_2)

{
  undefined **appuStack_18 [4];
  
  if (param_2 == 0) {
    __2_YAPAXI_Z(0);
    return;
  }
  if (param_2 == 0) {
    trap(0x1c00);
  }
  if (0xffffffff / param_2 == 0) {
    __0exception_std__QAA_PBD_Z(appuStack_18,0);
                    /* WARNING: Subroutine does not return */
    appuStack_18[0] = std::bad_alloc::vftable;
    __CxxThrowException(appuStack_18,(ThrowInfo *)&DAT_00036410);
  }
  __2_YAPAXI_Z(param_2);
  return;
}



/* 00023af8 FUN_00023af8 */

/* Boundary evidence: original MIPS .pdata 00023af8..00023b2b. Semantic name remains unreviewed. */

int * FUN_00023af8(int *param_1)

{
  FUN_00023c5c(param_1);
  return param_1;
}



/* 00023b2c FUN_00023b2c */

/* Boundary evidence: original MIPS .pdata 00023b2c..00023c5b. Semantic name remains unreviewed. */

int FUN_00023b2c(int param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (param_2 != (undefined4 *)0x0) {
    bVar1 = 0xf < *(uint *)(param_1 + 0x18);
    puVar3 = (undefined4 *)(param_1 + 4);
    puVar2 = puVar3;
    if (bVar1) {
      puVar2 = (undefined4 *)*puVar3;
    }
    if (puVar2 <= param_2) {
      if (bVar1) {
        puVar3 = (undefined4 *)*puVar3;
      }
      bVar1 = true;
      if (param_2 < (undefined4 *)(*(int *)(param_1 + 0x14) + (int)puVar3)) goto LAB_00023ba0;
    }
  }
  bVar1 = false;
LAB_00023ba0:
  if (bVar1) {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      iVar4 = param_1 + 4;
    }
    else {
      iVar4 = *(int *)(param_1 + 4);
    }
    param_1 = FUN_00021ed0(param_1,param_1,(int)param_2 - iVar4,param_3);
  }
  else {
    iVar4 = FUN_000225cc(param_1,param_3,0);
    if (iVar4 != 0) {
      puVar3 = (undefined4 *)(param_1 + 4);
      puVar2 = puVar3;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        puVar2 = (undefined4 *)*puVar3;
      }
      memcpy_s(puVar2,*(uint *)(param_1 + 0x18),param_2,param_3);
      *(uint *)(param_1 + 0x14) = param_3;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      *(undefined1 *)((int)puVar3 + param_3) = 0;
    }
  }
  return param_1;
}



/* 00023c5c FUN_00023c5c */

/* Boundary evidence: original MIPS .pdata 00023c5c..00023c93. Semantic name remains unreviewed. */

int * FUN_00023c5c(int *param_1)

{
  FUN_00023c94(param_1);
  return param_1;
}



/* 00023c94 FUN_00023c94 */

/* Boundary evidence: original MIPS .pdata 00023c94..00023cd7. Semantic name remains unreviewed. */

int * FUN_00023c94(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)__2_YAPAXI_Z(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
  }
  *param_1 = (int)puVar1;
  return param_1;
}



/* 00023cd8 FUN_00023cd8 */

/* Boundary evidence: original MIPS .pdata 00023cd8..00023d0f. Semantic name remains unreviewed. */

undefined4 * FUN_00023cd8(undefined4 *param_1)

{
  __0exception_std__QAA_ABV01__Z(param_1);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}



/* 00023d10 FUN_00023d10 */

void FUN_00023d10(short *param_1)

{
  short sVar1;
  bool bVar2;
  short *psVar3;
  short *psVar4;
  
  if (param_1 != (short *)0x0) {
    bVar2 = true;
    psVar3 = param_1;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    for (psVar3 = param_1 + (((uint)((int)psVar3 - (int)param_1) >> 1) - 2); param_1 < psVar3;
        psVar3 = psVar3 + -1) {
      sVar1 = *psVar3;
      if ((((sVar1 == 0x20) || (sVar1 == 9)) || (sVar1 == 10)) || (sVar1 == 0xd)) {
        if (bVar2) {
          *psVar3 = 0x5f;
        }
      }
      else if (sVar1 == 0x5c) {
        psVar4 = psVar3 + 1;
        sVar1 = *psVar4;
        bVar2 = true;
        while ((sVar1 != 0 &&
               (((sVar1 = *psVar4, sVar1 == 0x20 || (sVar1 == 9)) ||
                ((sVar1 == 10 || (sVar1 == 0xd))))))) {
          *psVar4 = 0x5f;
          psVar4 = psVar4 + 1;
          sVar1 = *psVar4;
        }
      }
      else {
        bVar2 = false;
      }
    }
  }
  return;
}



/* 00023e1c FUN_00023e1c */

/* Boundary evidence: original MIPS .pdata 00023e1c..00023ee7. Semantic name remains unreviewed. */

char * FUN_00023e1c(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar2 = _strdup(param_1);
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  cVar1 = *pcVar2;
  iVar4 = 0;
  pcVar3 = pcVar2;
  do {
    if (cVar1 == '\0') {
      return pcVar2;
    }
    cVar1 = *pcVar3;
    if (cVar1 < '=') {
      if ((cVar1 == '<') || ((cVar1 == '*' || ((cVar1 == ':' && (2 < iVar4)))))) {
LAB_00023ec8:
        *pcVar3 = '_';
      }
    }
    else if (('=' < cVar1) && ((cVar1 < '@' || (cVar1 == '|')))) goto LAB_00023ec8;
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
    iVar4 = iVar4 + 1;
  } while( true );
}



/* 00023ee8 FUN_00023ee8 */

/* Boundary evidence: original MIPS .pdata 00023ee8..00023fd7. Semantic name remains unreviewed. */

wchar_t * FUN_00023ee8(wchar_t *param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  int iVar4;
  
  if ((param_1 == (wchar_t *)0x0) || (pwVar2 = _wcsdup(param_1), pwVar2 == (wchar_t *)0x0)) {
    return (wchar_t *)0x0;
  }
  wVar1 = *pwVar2;
  iVar4 = 0;
  pwVar3 = pwVar2;
  do {
    if (wVar1 == L'\0') {
      FUN_00023d10(pwVar2);
      return pwVar2;
    }
    wVar1 = *pwVar3;
    if ((ushort)wVar1 < 0x3d) {
      if ((wVar1 == L'<') || ((wVar1 == L'*' || ((wVar1 == L':' && (2 < iVar4)))))) {
LAB_00023fa8:
        *pwVar3 = L'_';
      }
    }
    else if ((0x3d < (ushort)wVar1) && (((ushort)wVar1 < 0x40 || (wVar1 == L'|'))))
    goto LAB_00023fa8;
    pwVar3 = pwVar3 + 1;
    wVar1 = *pwVar3;
    iVar4 = iVar4 + 1;
  } while( true );
}



/* 00023fd8 FUN_00023fd8 */

/* Boundary evidence: original MIPS .pdata 00023fd8..00024363. Semantic name remains unreviewed. */

undefined4 FUN_00023fd8(wchar_t *param_1)

{
  wchar_t wVar1;
  undefined4 uVar2;
  wchar_t *_Str;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  BOOL BVar5;
  DWORD DVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  int iVar9;
  wchar_t *pwVar10;
  wchar_t *local_248;
  wchar_t local_244 [6];
  wchar_t local_238;
  undefined1 local_236 [518];
  uint local_30;
  
  local_30 = DAT_000372d4;
  if (param_1 == (wchar_t *)0x0) {
    FUN_0002a0c4(DAT_000372d4);
    uVar2 = 0;
  }
  else {
    _Str = FUN_00023ee8(param_1);
    pwVar3 = _Str;
    if (_Str == (wchar_t *)0x0) {
      iVar9 = 0;
    }
    else {
      do {
        wVar1 = *pwVar3;
        pwVar3 = pwVar3 + 1;
      } while (wVar1 != L'\0');
      iVar9 = ((uint)((int)pwVar3 - (int)_Str) >> 1) - 1;
    }
    for (pwVar3 = _Str + iVar9; pwVar3 != _Str; pwVar3 = pwVar3 + -1) {
      if ((*pwVar3 == L'/') || (*pwVar3 == L'\\')) {
        *pwVar3 = L'\0';
        break;
      }
    }
    pwVar3 = _wcsdup(_Str);
    local_244[0] = L'/';
    local_244[1] = L'\\';
    local_244[2] = 0;
    local_238 = L'\0';
    memset(local_236,0,0x206);
    local_248 = (wchar_t *)0x0;
    pwVar4 = wcstok_s(pwVar3,local_244,&local_248);
    if (pwVar4 != (wchar_t *)0x0) {
      do {
        pwVar8 = &local_238;
        do {
          wVar1 = *pwVar8;
          pwVar8 = pwVar8 + 1;
        } while (wVar1 != L'\0');
        if ((int)pwVar8 - (int)&local_238 >> 1 == 1) {
          wVar1 = *_Str;
          if ((wVar1 != L'\\') || (_Str[1] != L'\\')) {
            if (wVar1 == L'/') {
              pwVar7 = &local_238;
              pwVar8 = L"/";
              do {
                wVar1 = *pwVar8;
                pwVar8 = pwVar8 + 1;
                *pwVar7 = wVar1;
                pwVar7 = pwVar7 + 1;
              } while (wVar1 != L'\0');
            }
            else if (wVar1 == L'\\') {
              pwVar7 = &local_238;
              pwVar8 = L"\\";
              do {
                wVar1 = *pwVar8;
                pwVar8 = pwVar8 + 1;
                *pwVar7 = wVar1;
                pwVar7 = pwVar7 + 1;
              } while (wVar1 != L'\0');
            }
            pwVar8 = &local_238;
            do {
              pwVar7 = pwVar8;
              pwVar8 = pwVar7 + 1;
            } while (*pwVar7 != L'\0');
            do {
              wVar1 = *pwVar4;
              pwVar4 = pwVar4 + 1;
              *pwVar7 = wVar1;
              pwVar7 = pwVar7 + 1;
            } while (wVar1 != L'\0');
            goto LAB_00024278;
          }
          pwVar7 = &local_238;
          pwVar8 = L"\\\\";
          do {
            wVar1 = *pwVar8;
            pwVar8 = pwVar8 + 1;
            *pwVar7 = wVar1;
            pwVar7 = pwVar7 + 1;
          } while (wVar1 != L'\0');
          pwVar8 = &local_238;
          do {
            pwVar7 = pwVar8;
            pwVar8 = pwVar7 + 1;
          } while (*pwVar7 != L'\0');
          do {
            wVar1 = *pwVar4;
            pwVar4 = pwVar4 + 1;
            *pwVar7 = wVar1;
            pwVar7 = pwVar7 + 1;
          } while (wVar1 != L'\0');
        }
        else {
          pwVar8 = &local_238;
          do {
            pwVar10 = pwVar8;
            pwVar8 = pwVar10 + 1;
            pwVar7 = L"\\";
          } while (*pwVar10 != L'\0');
          do {
            wVar1 = *pwVar7;
            *pwVar10 = wVar1;
            pwVar10 = pwVar10 + 1;
            pwVar7 = pwVar7 + 1;
          } while (wVar1 != L'\0');
          pwVar8 = &local_238;
          do {
            pwVar7 = pwVar8;
            pwVar8 = pwVar7 + 1;
          } while (*pwVar7 != L'\0');
          do {
            wVar1 = *pwVar4;
            pwVar4 = pwVar4 + 1;
            *pwVar7 = wVar1;
            pwVar7 = pwVar7 + 1;
          } while (wVar1 != L'\0');
LAB_00024278:
          DVar6 = GetFileAttributesW(&local_238);
          if (((DVar6 == 0xffffffff) || ((DVar6 & 0x10) == 0)) &&
             (BVar5 = CreateDirectoryW(&local_238,(LPSECURITY_ATTRIBUTES)0x0), BVar5 == 0)) {
            GetLastError();
            break;
          }
        }
        pwVar4 = wcstok_s((wchar_t *)0x0,local_244,&local_248);
      } while (pwVar4 != (wchar_t *)0x0);
    }
    uVar2 = 1;
    DVar6 = GetFileAttributesW(_Str);
    if ((DVar6 == 0xffffffff) || ((DVar6 & 0x10) == 0)) {
      uVar2 = 0;
    }
    free(pwVar3);
    free(_Str);
    FUN_0002a0c4(local_30);
  }
  return uVar2;
}



/* 00024364 FUN_00024364 */

/* Boundary evidence: original MIPS .pdata 00024364..000244ab. Semantic name remains unreviewed. */

undefined4 FUN_00024364(short *param_1,undefined4 param_2,short *param_3,short *param_4)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  psVar2 = param_4;
  if ((param_3 == (short *)0x0) || (psVar3 = param_3, *param_3 == 0)) {
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
    if (0x207 < (uint)((int)psVar2 - (int)param_4) >> 1) {
      return 0;
    }
    do {
      sVar1 = *param_4;
      param_4 = param_4 + 1;
      *param_1 = sVar1;
      param_1 = param_1 + 1;
    } while (sVar1 != 0);
  }
  else {
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
    if (0x207 < (((uint)((int)psVar2 - (int)param_4) >> 1) +
                ((uint)((int)psVar3 - (int)param_3) >> 1)) - 1) {
      return 0;
    }
    *param_1 = 0;
    psVar2 = param_1;
    do {
      sVar1 = *param_3;
      param_3 = param_3 + 1;
      *psVar2 = sVar1;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
    FUN_000244ac(param_1);
    if (param_4 != (short *)0x0) {
      do {
        psVar2 = param_1;
        param_1 = psVar2 + 1;
      } while (*psVar2 != 0);
      do {
        sVar1 = *param_4;
        param_4 = param_4 + 1;
        *psVar2 = sVar1;
        psVar2 = psVar2 + 1;
      } while (sVar1 != 0);
    }
  }
  return 1;
}



/* 000244ac FUN_000244ac */

undefined4 FUN_000244ac(short *param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  short *psVar4;
  
  psVar4 = param_1;
  if (param_1 == (short *)0x0) {
    sVar1 = 0;
  }
  else {
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    uVar2 = (uint)((int)psVar4 - (int)param_1) >> 1;
    if (uVar2 == 1) {
      sVar1 = 0;
    }
    else {
      sVar1 = param_1[uVar2 - 2];
    }
  }
  if (sVar1 != 0x5c) {
    psVar4 = &DAT_00031f0c;
    do {
      psVar3 = param_1;
      param_1 = psVar3 + 1;
    } while (*psVar3 != 0);
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
      *psVar3 = sVar1;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
  }
  return 1;
}



/* 00024538 FUN_00024538 */

/* Boundary evidence: original MIPS .pdata 00024538..00024607. Semantic name remains unreviewed. */

void FUN_00024538(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < param_1[2]) {
    iVar3 = 0;
    do {
      puVar2 = *(undefined4 **)(iVar3 + *param_1);
      if ((void *)*puVar2 != (void *)0x0) {
        free((void *)*puVar2);
      }
      *puVar2 = 0;
      if ((void *)puVar2[1] != (void *)0x0) {
        free((void *)puVar2[1]);
      }
      puVar1 = (undefined4 *)puVar2[0x14];
      puVar2[1] = 0;
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(puVar1,1);
      }
      puVar2[0x14] = 0;
      __3_YAXPAX_Z(puVar2);
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar4 < param_1[2]);
  }
  free((void *)*param_1);
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



/* 00024608 FUN_00024608 */

/* Boundary evidence: original MIPS .pdata 00024608..000246f3. Semantic name remains unreviewed. */

void FUN_00024608(int *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  
  if (param_2 != 0) {
    if (*param_1 == 0) {
      param_1[1] = 0x400;
      pvVar1 = calloc(0x400,4);
      *param_1 = (int)pvVar1;
    }
    iVar2 = param_1[1];
    if (iVar2 <= param_1[2]) {
      param_1[1] = iVar2 << 1;
      pvVar1 = realloc((void *)*param_1,iVar2 << 3);
      if (pvVar1 == (void *)0x0) {
        return;
      }
      *param_1 = (int)pvVar1;
    }
    if (*param_1 != 0) {
      *(int *)(param_1[2] * 4 + *param_1) = param_2;
      param_1[2] = param_1[2] + 1;
      if ((*(uint *)(param_2 + 0x24) & 0x10) != 0) {
        param_1[4] = param_1[4] + 1;
        return;
      }
      param_1[3] = param_1[3] + 1;
    }
  }
  return;
}



/* 000246f4 FUN_000246f4 */

/* Boundary evidence: original MIPS .pdata 000246f4..0002483b. Semantic name remains unreviewed. */

undefined4 FUN_000246f4(int *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  size_t _Size;
  
  if (0 < (int)param_3) {
    if ((param_1[2] - param_1[5] <= (int)param_3) &&
       (iVar1 = FUN_0002496c(param_1,(param_1[5] - param_1[2]) + param_3), iVar1 == 0)) {
      return 0;
    }
    iVar1 = param_1[4];
    if (iVar1 < param_1[3]) {
      memcpy((void *)(param_1[1] + iVar1),param_2,param_3);
      param_1[4] = param_1[4] + param_3;
    }
    else {
      _Size = param_1[2] - iVar1;
      if ((int)param_3 < param_1[2] - iVar1) {
        _Size = param_3;
      }
      memcpy((void *)(param_1[1] + iVar1),param_2,_Size);
      if ((int)_Size < (int)param_3) {
        memcpy((void *)param_1[1],(void *)(_Size + (int)param_2),param_3 - _Size);
      }
      iVar1 = param_1[2];
      if (iVar1 == 0) {
        trap(0x1c00);
      }
      if ((iVar1 == -1) && (param_1[4] + param_3 == -0x80000000)) {
        trap(0x1800);
      }
      param_1[4] = (int)(param_1[4] + param_3) % iVar1;
    }
    param_1[5] = param_1[5] + param_3;
  }
  return 1;
}



/* 0002483c FUN_0002483c */

/* Boundary evidence: original MIPS .pdata 0002483c..0002496b. Semantic name remains unreviewed. */

undefined4 FUN_0002483c(int param_1,void *param_2,size_t param_3,int param_4)

{
  void *_Src;
  int iVar1;
  int iVar2;
  size_t sVar3;
  
  if ((*(int *)(param_1 + 0x14) < (int)param_3) || ((int)param_3 < 1)) {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0x10) < iVar2) {
    sVar3 = *(int *)(param_1 + 8) - iVar2;
    if ((int)param_3 <= (int)sVar3) {
      sVar3 = param_3;
    }
    memcpy(param_2,(void *)(iVar2 + *(int *)(param_1 + 4)),sVar3);
    if ((int)param_3 <= (int)sVar3) goto LAB_000248f0;
    _Src = *(void **)(param_1 + 4);
    param_2 = (void *)(sVar3 + (int)param_2);
    sVar3 = param_3 - sVar3;
  }
  else {
    _Src = (void *)(*(int *)(param_1 + 4) + iVar2);
    sVar3 = param_3;
  }
  memcpy(param_2,_Src,sVar3);
LAB_000248f0:
  if (param_4 != 0) {
    iVar2 = *(int *)(param_1 + 8);
    iVar1 = *(int *)(param_1 + 0xc) + param_3;
    if (iVar2 == 0) {
      trap(0x1c00);
    }
    if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    *(int *)(param_1 + 0xc) = iVar1 % iVar2;
    *(size_t *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - param_3;
  }
  return 1;
}



/* 0002496c FUN_0002496c */

/* Boundary evidence: original MIPS .pdata 0002496c..00024a67. Semantic name remains unreviewed. */

undefined4 FUN_0002496c(int *param_1,int param_2)

{
  LPVOID pvVar1;
  undefined4 uVar2;
  int iVar3;
  SIZE_T dwSize;
  
  iVar3 = *param_1;
  if (param_2 < iVar3) {
    dwSize = iVar3 + param_1[2];
  }
  else {
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (param_2 == -0x80000000)) {
      trap(0x1800);
    }
    dwSize = (param_2 / iVar3 + 1) * iVar3 + param_1[2];
  }
  pvVar1 = VirtualAlloc((LPVOID)0x0,dwSize,0x1000,4);
  if (pvVar1 == (LPVOID)0x0) {
    uVar2 = 0;
  }
  else {
    if (param_1[5] != 0) {
      FUN_0002483c((int)param_1,pvVar1,param_1[5],0);
    }
    VirtualFree((LPVOID)param_1[1],0,0x8000);
    param_1[1] = (int)pvVar1;
    uVar2 = 1;
    param_1[3] = 0;
    param_1[4] = param_1[5];
    param_1[2] = dwSize;
  }
  return uVar2;
}



/* 00024a68 FUN_00024a68 */

/* Boundary evidence: original MIPS .pdata 00024a68..00024e6f. Semantic name remains unreviewed. */

undefined8 FUN_00024a68(uint *param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  longlong lVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  _TIME_ZONE_INFORMATION local_d8;
  uint local_2c;
  
  uVar11 = DAT_000372d4;
  local_2c = DAT_000372d4;
  uVar14 = param_1[5];
  iVar16 = (int)uVar14 >> 0x1f;
  if ((iVar16 + -1 + (uint)(uVar14 - 0x45 < uVar14) == 0) && (uVar14 - 0x45 < 0x409)) {
    uVar7 = param_1[4];
    if (((int)uVar7 < 0) || (0xb < (int)uVar7)) {
      uVar17 = (int)uVar7 / 0xc;
      uVar15 = uVar17 + uVar14;
      iVar16 = ((int)uVar17 >> 0x1f) + iVar16 + (uint)(uVar15 < uVar17);
      uVar7 = (int)uVar7 % 0xc;
      param_1[4] = uVar7;
      uVar14 = uVar15;
      if ((int)uVar7 < 0) {
        uVar14 = uVar15 - 1;
        param_1[4] = uVar7 + 0xc;
        iVar16 = iVar16 - (uint)(uVar15 == 0);
      }
      if ((iVar16 + -1 + (uint)(uVar14 - 0x45 < uVar14) != 0) || (0x408 < uVar14 - 0x45))
      goto LAB_00024e30;
    }
    uVar11 = param_1[4];
    uVar17 = *(uint *)(&DAT_00037394 + uVar11 * 4);
    iVar20 = (int)uVar17 >> 0x1f;
    lVar21 = __ll_rem(uVar14,iVar16,4,0);
    uVar7 = uVar17;
    if ((((lVar21 == 0) && (lVar21 = __ll_rem(uVar14,iVar16,100,0), lVar21 != 0)) ||
        (lVar21 = __ll_rem(uVar14 + 0x76c,iVar16 + (uint)(uVar14 + 0x76c < uVar14),400,0),
        lVar21 == 0)) && (1 < (int)uVar11)) {
      uVar7 = uVar17 + 1;
      iVar20 = iVar20 + (uint)(uVar7 < uVar17);
    }
    iVar13 = iVar16 - (uint)(uVar14 == 0);
    uVar22 = __ll_div(uVar14 + 299,iVar16 + (uint)(uVar14 + 299 < uVar14),400,0);
    uVar15 = param_1[3];
    uVar12 = (uint)uVar22 + uVar15;
    uVar23 = __ll_div(uVar14 - 1,iVar13,100,0);
    uVar11 = (uint)(iVar13 >> 1) >> 0x1e;
    uVar17 = uVar11 + (uVar14 - 1);
    iVar13 = iVar13 + (uint)(uVar17 < uVar11);
    uVar19 = uVar12 - (uint)uVar23;
    uVar18 = uVar19 + (iVar13 * 0x40000000 | uVar17 >> 2);
    uVar8 = uVar18 + (int)((ulonglong)uVar14 * 0x16d);
    uVar7 = uVar8 + uVar7;
    uVar5 = param_1[2];
    lVar21 = (ulonglong)(uVar7 - 0x63df) * 0x18;
    uVar10 = uVar5 + (int)lVar21;
    uVar3 = param_1[1];
    lVar1 = (ulonglong)uVar10 * 0x3c;
    uVar6 = uVar3 + (int)lVar1;
    uVar4 = *param_1;
    lVar2 = (ulonglong)uVar6 * 0x3c;
    uVar9 = uVar4 + (int)lVar2;
    GetTimeZoneInformation(&local_d8);
    uVar17 = local_d8.Bias * 0x3c;
    uVar11 = uVar17 + uVar9;
    iVar16 = ((int)uVar17 >> 0x1f) +
             ((int)uVar4 >> 0x1f) +
             (((int)uVar3 >> 0x1f) +
              (((int)uVar5 >> 0x1f) +
               ((((((int)((ulonglong)uVar22 >> 0x20) + ((int)uVar15 >> 0x1f) +
                   (uint)(uVar12 < (uint)uVar22)) - (int)((ulonglong)uVar23 >> 0x20)) -
                 (uint)(uVar12 < (uint)uVar23)) + (iVar13 >> 2) + (uint)(uVar18 < uVar19) +
                 iVar16 * 0x16d + (int)((ulonglong)uVar14 * 0x16d >> 0x20) + (uint)(uVar8 < uVar18)
                 + iVar20 + (uint)(uVar7 < uVar8)) - (uint)(uVar7 < 0x63df)) * 0x18 +
               (int)((ulonglong)lVar21 >> 0x20) + (uint)(uVar10 < uVar5)) * 0x3c +
              (int)((ulonglong)lVar1 >> 0x20) + (uint)(uVar6 < uVar3)) * 0x3c +
             (int)((ulonglong)lVar2 >> 0x20) + (uint)(uVar9 < uVar4) + (uint)(uVar11 < uVar17);
    FUN_0002a0c4(local_2c);
  }
  else {
LAB_00024e30:
    FUN_0002a0c4(uVar11);
    uVar11 = 0;
    iVar16 = 0;
  }
  return CONCAT44(iVar16,uVar11);
}



/* 00024e70 FUN_00024e70 */

void FUN_00024e70(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00034b74;
  return;
}



/* 00024e80 FUN_00024e80 */

/* Boundary evidence: original MIPS .pdata 00024e80..00024ec3. Semantic name remains unreviewed. */

undefined4 * FUN_00024e80(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00034b74;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00024ec4 FUN_00024ec4 */

/* Boundary evidence: original MIPS .pdata 00024ec4..00024f0f. Semantic name remains unreviewed. */

undefined4 * FUN_00024ec4(undefined4 *param_1,uint param_2)

{
  FUN_00024f10(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00024f10 FUN_00024f10 */

/* Boundary evidence: original MIPS .pdata 00024f10..00024f73. Semantic name remains unreviewed. */

void FUN_00024f10(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00034bb4;
  param_1[10] = &PTR_FUN_00034c08;
  FUN_00024538(param_1 + 2);
  *param_1 = &PTR_FUN_00034b74;
  return;
}



/* 00024f74 Unwind@00024f74 */

/* Boundary evidence: original MIPS .pdata 00024f74..00024fa3. Semantic name remains unreviewed. */

void Unwind_00024f74(void)

{
  undefined4 *in_v0;
  
  FUN_00024e70((undefined4 *)*in_v0);
  return;
}



/* 00024fa4 FUN_00024fa4 */

/* Boundary evidence: original MIPS .pdata 00024fa4..0002509f. Semantic name remains unreviewed. */

int FUN_00024fa4(int *param_1,undefined4 param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  
  piVar1 = (int *)__2_YAPAXI_Z(0x38);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    *piVar1 = (int)&PTR_FUN_00034a90;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[8] = 0;
    piVar1[9] = 0;
    piVar1[2] = -1;
    pvVar2 = malloc(0x10000);
    piVar1[3] = (int)pvVar2;
    piVar1[4] = 0x10000;
    piVar1[0xc] = 0;
    piVar1[0xd] = 0;
  }
  iVar3 = (**(code **)(*piVar1 + 0x10))(piVar1,param_2);
  if (iVar3 == 0) {
    __3_YAXPAX_Z(piVar1);
    param_1[0x96] = 1;
    iVar3 = 0;
  }
  else {
    iVar3 = (**(code **)(*param_1 + 4))(param_1,piVar1);
    if (iVar3 == 0) {
      __3_YAXPAX_Z(piVar1);
    }
  }
  return iVar3;
}



/* 000250a0 FUN_000250a0 */

/* Boundary evidence: original MIPS .pdata 000250a0..000250ff. Semantic name remains unreviewed. */

undefined4 FUN_000250a0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_0001ec60(param_2);
  if (piVar1 == (int *)0x0) {
    param_1[0x96] = 1;
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 4))(param_1,piVar1);
  return uVar2;
}



/* 00025100 FUN_00025100 */

/* Boundary evidence: original MIPS .pdata 00025100..00025187. Semantic name remains unreviewed. */

undefined4 FUN_00025100(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(*param_1 + 0x10))(param_1);
  iVar1 = (**(code **)*param_2)(param_2,&DAT_0002e1b8,param_1 + 8);
  if (iVar1 < 0) {
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  return uVar2;
}



/* 00025188 FUN_00025188 */

/* Boundary evidence: original MIPS .pdata 00025188..0002521f. Semantic name remains unreviewed. */

void FUN_00025188(int *param_1)

{
  if ((int *)param_1[8] != (int *)0x0) {
    (**(code **)(*(int *)param_1[8] + 8))();
    param_1[8] = 0;
  }
  FUN_00024538(param_1 + 2);
  (**(code **)(*param_1 + 0x44))(param_1);
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x96] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0x95] = 0;
  memset(param_1 + 0x9a,0,0x48);
  (**(code **)(*param_1 + 0x48))(param_1);
  return;
}



/* 00025220 FUN_00025220 */

/* Boundary evidence: original MIPS .pdata 00025220..0002526f. Semantic name remains unreviewed. */

void FUN_00025220(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  *(char *)(param_1 + 0x2c) = '\0';
  pcVar2 = param_2;
  if (param_2 != (char *)0x0) {
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if ((int)pcVar2 - (int)param_2 != 1) {
      strcpy((char *)(param_1 + 0x2c),param_2);
    }
  }
  return;
}



/* 00025270 FUN_00025270 */

/* Boundary evidence: original MIPS .pdata 00025270..00025353. Semantic name remains unreviewed. */

void FUN_00025270(int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_3 & param_4) == 0xffffffff) {
    *(undefined4 *)(param_1 + 0x298) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x29c) = 0xffffffff;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x298);
    uVar2 = uVar1 + param_3;
    *(uint *)(param_1 + 0x298) = uVar2;
    *(uint *)(param_1 + 0x29c) = *(int *)(param_1 + 0x29c) + param_4 + (uint)(uVar2 < uVar1);
  }
  uVar2 = *(uint *)(param_1 + 0x2a0);
  uVar1 = uVar2 + param_5;
  *(uint *)(param_1 + 0x2a0) = uVar1;
  *(uint *)(param_1 + 0x2a4) = *(int *)(param_1 + 0x2a4) + param_6 + (uint)(uVar1 < uVar2);
  if (*(int *)(param_1 + 0x264) != 0) {
    FUN_00025354(param_1);
    (**(code **)(**(int **)(param_1 + 0x264) + 4))
              (*(int **)(param_1 + 0x264),param_1 + 0x268,(int *)(param_1 + 0x25c),
               (int *)(param_1 + 0x260));
    if (*(int *)(param_1 + 0x25c) != 0 || *(int *)(param_1 + 0x260) != 0) {
      *(undefined4 *)(param_1 + 600) = 0x17;
    }
  }
  return;
}



/* 00025354 FUN_00025354 */

/* Boundary evidence: original MIPS .pdata 00025354..000254d3. Semantic name remains unreviewed. */

void FUN_00025354(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = *(uint *)(param_1 + 0x280);
  uVar8 = *(uint *)(param_1 + 0x284);
  *(undefined4 *)(param_1 + 0x2ac) = 0;
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  if ((uVar7 & uVar8) == 0xffffffff) {
    uVar7 = *(uint *)(param_1 + 0x278);
    uVar8 = *(uint *)(param_1 + 0x27c);
    if (uVar7 != 0 || uVar8 != 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x29c);
      uVar1 = *(undefined4 *)(param_1 + 0x298);
      goto LAB_000253e0;
    }
    uVar1 = 0;
  }
  else if (uVar7 == 0 && uVar8 == 0) {
    uVar1 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x2a4);
    uVar1 = *(undefined4 *)(param_1 + 0x2a0);
LAB_000253e0:
    uVar1 = __ll_to_f(uVar1,uVar2);
    uVar1 = __fpmul(uVar1,0x42c80000);
    uVar2 = __ll_to_f(uVar7,uVar8);
    uVar1 = __fpdiv(uVar1,uVar2);
  }
  uVar7 = *(uint *)(param_1 + 0x270);
  uVar8 = *(uint *)(param_1 + 0x274);
  *(undefined4 *)(param_1 + 0x2a8) = uVar1;
  if ((uVar7 & uVar8) == 0xffffffff) {
    uVar7 = *(uint *)(param_1 + 0x268);
    uVar8 = *(uint *)(param_1 + 0x26c);
    if (uVar7 == 0 && uVar8 == 0) goto LAB_00025458;
    uVar4 = *(uint *)(param_1 + 0x298);
    iVar6 = *(int *)(param_1 + 0x29c);
    iVar3 = *(int *)(param_1 + 0x288);
    iVar5 = *(int *)(param_1 + 0x28c);
  }
  else {
    if (uVar7 == 0 && uVar8 == 0) {
LAB_00025458:
      uVar1 = 0;
      goto LAB_000254ac;
    }
    uVar4 = *(uint *)(param_1 + 0x2a0);
    iVar6 = *(int *)(param_1 + 0x2a4);
    iVar3 = *(int *)(param_1 + 0x290);
    iVar5 = *(int *)(param_1 + 0x294);
  }
  uVar1 = __ll_to_f(uVar4 + iVar3,iVar6 + iVar5 + (uint)(uVar4 + iVar3 < uVar4));
  uVar1 = __fpmul(uVar1,0x42c80000);
  uVar2 = __ll_to_f(uVar7,uVar8);
  uVar1 = __fpdiv(uVar1,uVar2);
LAB_000254ac:
  *(undefined4 *)(param_1 + 0x2ac) = uVar1;
  return;
}



/* 000254d4 FUN_000254d4 */

/* Boundary evidence: original MIPS .pdata 000254d4..00025683. Semantic name remains unreviewed. */

void FUN_000254d4(int param_1,int *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *_Dst;
  int iVar6;
  
  _Dst = (uint *)(param_1 + 0x268);
  *(undefined4 *)(param_1 + 0x25c) = 0;
  *(undefined4 *)(param_1 + 0x260) = 0;
  memset(_Dst,0,0x48);
  if (*(int *)(param_1 + 0x254) == 0) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      iVar6 = *param_2;
      if ((iVar6 < 0) || (*(int *)(param_1 + 0x10) <= iVar6)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(iVar6 * 4 + *(int *)(param_1 + 8));
      }
      uVar5 = *(uint *)(iVar6 + 0x10);
      iVar4 = *(int *)(iVar6 + 0x14);
      uVar1 = uVar5 + *_Dst;
      *_Dst = uVar1;
      *(uint *)(param_1 + 0x26c) = iVar4 + *(int *)(param_1 + 0x26c) + (uint)(uVar1 < uVar5);
      uVar1 = *(uint *)(iVar6 + 0x18);
      iVar6 = *(int *)(iVar6 + 0x1c);
      uVar5 = uVar1 + *(int *)(param_1 + 0x270);
      param_2 = param_2 + 1;
      *(uint *)(param_1 + 0x270) = uVar5;
      *(uint *)(param_1 + 0x274) = iVar6 + *(int *)(param_1 + 0x274) + (uint)(uVar5 < uVar1);
    }
  }
  else {
    uVar5 = 0;
    iVar6 = 0;
    do {
      if (((int)uVar5 < 0) || (*(int *)(param_1 + 0x10) <= (int)uVar5)) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(iVar6 + *(int *)(param_1 + 8));
      }
      uVar1 = *(uint *)(iVar4 + 0x10);
      iVar2 = *(int *)(iVar4 + 0x14);
      uVar3 = uVar1 + *_Dst;
      *_Dst = uVar3;
      *(uint *)(param_1 + 0x26c) = iVar2 + *(int *)(param_1 + 0x26c) + (uint)(uVar3 < uVar1);
      uVar3 = *(uint *)(iVar4 + 0x18);
      iVar4 = *(int *)(iVar4 + 0x1c);
      uVar1 = uVar3 + *(int *)(param_1 + 0x270);
      *(uint *)(param_1 + 0x270) = uVar1;
      *(uint *)(param_1 + 0x274) = iVar4 + *(int *)(param_1 + 0x274) + (uint)(uVar1 < uVar3);
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar5 <= (uint)param_2[param_3 + -1]);
  }
  return;
}



/* 00025684 FUN_00025684 */

/* Boundary evidence: original MIPS .pdata 00025684..00025997. Semantic name remains unreviewed. */

undefined4 FUN_00025684(int param_1,int param_2,int *param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_2048;
  uint local_2040;
  uint local_203c;
  int *local_2038;
  uint auStack_2030 [2048];
  uint local_30;
  
  local_30 = DAT_000372d4;
  local_2040 = *(uint *)(param_2 + 0x10);
  local_203c = *(uint *)(param_2 + 0x14);
  local_2048 = 0;
  local_2038 = param_4;
  iVar2 = FUN_00026458(param_1 + 0x28,param_2,param_3,&local_2040);
  if (iVar2 == 0) {
    piVar5 = *(int **)(param_1 + 0x264);
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x230);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0xc))(piVar5,*(undefined4 *)(param_1 + 0x230),param_2,param_1 + 0x260);
    }
    FUN_0002a0c4(local_30);
    uVar3 = 0;
  }
  else {
    uVar8 = local_203c;
    uVar4 = 0;
    uVar10 = local_2040;
    if (local_2040 != 0 || local_203c != 0) {
      while( true ) {
        if ((0 < (int)uVar8) || ((uVar7 = uVar10, uVar9 = uVar8, uVar8 == 0 && (0x1fff < uVar10))))
        {
          uVar7 = 0x2000;
          uVar9 = 0;
        }
        iVar2 = (**(code **)(*param_3 + 0x14))(param_3,auStack_2030,uVar7);
        if (iVar2 == 0) break;
        iVar2 = *(int *)(param_1 + 0x22c);
        if ((iVar2 != 0) && ((iVar2 == 1 || (iVar2 == 5)))) {
          FUN_0002657c(param_1 + 0x28,uVar7,(byte *)auStack_2030);
        }
        uVar4 = FUN_00026a90(local_2048,auStack_2030,uVar7);
        puVar6 = auStack_2030;
        iVar2 = (**(code **)(*local_2038 + 0x14))(local_2038,puVar6,uVar7,0);
        local_2048 = uVar4;
        if (iVar2 == 0) {
          piVar5 = *(int **)(param_1 + 0x264);
          *(undefined4 *)(param_1 + 600) = 0x30;
          if (piVar5 != (int *)0x0) {
            uVar3 = 0x30;
            goto LAB_000258a0;
          }
          goto LAB_000258c4;
        }
        bVar1 = uVar10 < uVar7;
        uVar10 = uVar10 - uVar7;
        uVar8 = (uVar8 - uVar9) - (uint)bVar1;
        if (*(int *)(param_1 + 0x254) == 0) {
          FUN_00025270(param_1,puVar6,uVar7,uVar9,uVar7,uVar9);
        }
        if ((*(int *)(param_1 + 0x260) != 0 || *(int *)(param_1 + 0x25c) != 0) ||
           (uVar10 == 0 && uVar8 == 0)) goto LAB_000258c4;
      }
      piVar5 = *(int **)(param_1 + 0x264);
      *(undefined4 *)(param_1 + 600) = 0x15;
      uVar4 = local_2048;
      if (piVar5 != (int *)0x0) {
        uVar3 = 0x15;
LAB_000258a0:
        (**(code **)(*piVar5 + 0xc))(piVar5,uVar3,param_2,param_1 + 0x260);
        uVar4 = local_2048;
      }
    }
LAB_000258c4:
    uVar3 = 0;
    if (*(int *)(param_1 + 600) == 0) {
      iVar2 = *(int *)(param_1 + 0x22c);
      if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 5)) {
        if ((*(uint *)(param_2 + 0x28) == 0) || (*(uint *)(param_2 + 0x28) == uVar4)) {
          uVar3 = 1;
        }
        else {
          piVar5 = *(int **)(param_1 + 0x264);
          *(undefined4 *)(param_1 + 600) = 0x18;
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0xc))(piVar5,0x18,param_2,param_1 + 0x260);
          }
        }
      }
      else {
        piVar5 = *(int **)(param_1 + 0x264);
        *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x230);
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0xc))
                    (piVar5,*(undefined4 *)(param_1 + 0x230),param_2,param_1 + 0x260);
        }
      }
    }
    FUN_0002a0c4(local_30);
  }
  return uVar3;
}



/* 00025998 FUN_00025998 */

/* Boundary evidence: original MIPS .pdata 00025998..00025dc7. Semantic name remains unreviewed. */

undefined4 FUN_00025998(int param_1,int param_2,int *param_3,int *param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_2080;
  uint local_207c;
  uint local_2078;
  int local_2074;
  int *local_2070;
  int *local_206c;
  byte *local_2068;
  uint local_2064;
  undefined4 local_2060;
  uint *local_205c;
  undefined4 local_2058;
  int local_2054;
  undefined4 local_2050;
  int local_204c;
  undefined4 local_2048;
  code *local_2044;
  undefined4 local_2040;
  undefined4 local_203c;
  undefined4 local_2038;
  undefined4 local_2034;
  byte abStack_2030 [4096];
  uint auStack_1030 [1024];
  uint local_30;
  
  local_30 = DAT_000372d4;
  local_2078 = *(uint *)(param_2 + 0x10);
  local_2074 = *(int *)(param_2 + 0x14);
  local_207c = 0;
  local_2080 = 0;
  local_2070 = param_3;
  local_206c = param_4;
  iVar2 = FUN_00026458(param_1 + 0x28,param_2,param_3,&local_2078);
  if (iVar2 == 0) {
    piVar5 = *(int **)(param_1 + 0x264);
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x230);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0xc))(piVar5,*(undefined4 *)(param_1 + 0x230),param_2,param_1 + 0x260);
    }
    FUN_0002a0c4(local_30);
    return 0;
  }
  local_2068 = (byte *)0x0;
  local_2064 = 0;
  local_2060 = 0;
  local_205c = (uint *)0x0;
  local_2058 = 0;
  local_2054 = 0;
  local_2050 = 0;
  local_204c = 0;
  local_2048 = 0;
  local_2044 = (code *)0x0;
  local_2040 = 0;
  local_203c = 0;
  local_2038 = 0;
  local_2034 = 0;
  FUN_00026fa4((int)&local_2068);
  local_205c = auStack_1030;
  local_2058 = 0x1000;
  iVar2 = local_2074;
  uVar10 = local_2078;
  while( true ) {
    iVar4 = local_2054;
    uVar8 = 0;
    uVar9 = uVar10;
    if (((local_2064 == 0) && (-1 < iVar2)) && ((iVar2 != 0 || (uVar10 != 0)))) {
      uVar8 = 0x1000;
      if ((iVar2 < 1) && (((iVar2 != 0 || (uVar10 < 0x1000)) && (uVar8 = uVar10, uVar10 == 0))))
      goto LAB_00025d38;
      iVar3 = (**(code **)(*param_3 + 0x14))(param_3,abStack_2030,uVar8);
      if (iVar3 == 0) {
        piVar5 = *(int **)(param_1 + 0x264);
        *(undefined4 *)(param_1 + 600) = 0x15;
        if (piVar5 == (int *)0x0) goto LAB_00025c78;
        iVar2 = *piVar5;
        uVar7 = 0x15;
        goto LAB_00025c68;
      }
      iVar3 = *(int *)(param_1 + 0x22c);
      if ((iVar3 != 0) && ((iVar3 == 1 || (iVar3 == 5)))) {
        FUN_0002657c(param_1 + 0x28,uVar8,abStack_2030);
      }
      uVar9 = uVar10 - uVar8;
      local_2068 = abStack_2030;
      iVar2 = iVar2 - (uint)(uVar10 < uVar8);
      local_2064 = uVar8;
    }
    iVar3 = FUN_000271cc((int *)&local_2068);
    if ((iVar3 != 0) && (iVar3 != 1)) {
      piVar5 = *(int **)(param_1 + 0x264);
      *(undefined4 *)(param_1 + 600) = 0x16;
      if (piVar5 == (int *)0x0) goto LAB_00025c78;
      iVar2 = *piVar5;
      uVar7 = 0x16;
      goto LAB_00025c68;
    }
    uVar10 = local_2054 - iVar4;
    local_207c = FUN_00026a90(local_207c,auStack_1030,uVar10);
    puVar6 = auStack_1030;
    iVar4 = (**(code **)(*local_206c + 0x14))(local_206c,puVar6,uVar10,0);
    if (iVar4 == 0) break;
    local_205c = auStack_1030;
    local_2058 = 0x1000;
    if (*(int *)(param_1 + 0x254) == 0) {
      FUN_00025270(param_1,puVar6,uVar8,0,uVar10,0);
    }
    if ((*(int *)(param_1 + 0x260) != 0 || *(int *)(param_1 + 0x25c) != 0) ||
       (param_3 = local_2070, uVar10 = uVar9, iVar3 == 1)) goto LAB_00025d38;
  }
  piVar5 = *(int **)(param_1 + 0x264);
  *(undefined4 *)(param_1 + 600) = 0x30;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0xc))(piVar5,0x30,param_2,param_1 + 0x260);
  }
LAB_00025d38:
  if (*(int *)(param_1 + 600) != 0) goto LAB_00025c78;
  iVar2 = *(int *)(param_1 + 0x22c);
  if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 5)) {
    if ((*(uint *)(param_2 + 0x28) == 0) || (*(uint *)(param_2 + 0x28) == local_207c)) {
      local_2080 = 1;
      goto LAB_00025c78;
    }
    piVar5 = *(int **)(param_1 + 0x264);
    *(undefined4 *)(param_1 + 600) = 0x18;
    if (piVar5 == (int *)0x0) goto LAB_00025c78;
    iVar2 = *piVar5;
    uVar7 = 0x18;
  }
  else {
    uVar7 = *(undefined4 *)(param_1 + 0x230);
    piVar5 = *(int **)(param_1 + 0x264);
    *(undefined4 *)(param_1 + 600) = uVar7;
    if (piVar5 == (int *)0x0) goto LAB_00025c78;
    iVar2 = *piVar5;
  }
LAB_00025c68:
  (**(code **)(iVar2 + 0xc))(piVar5,uVar7,param_2,param_1 + 0x260);
LAB_00025c78:
  uVar7 = local_2040;
  pcVar1 = local_2044;
  iVar2 = local_204c;
  if ((local_204c != 0) && (local_2044 != (code *)0x0)) {
    if (*(int *)(local_204c + 0x34) != 0) {
      (*local_2044)(local_2040);
    }
    (*pcVar1)(uVar7,iVar2);
  }
  FUN_0002a0c4(local_30);
  return local_2080;
}



/* 00025dd4 FUN_00025dd4 */

/* Boundary evidence: original MIPS .pdata 00025dd4..00025e87. Semantic name remains unreviewed. */

undefined4 FUN_00025dd4(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = param_1[4];
  piVar1 = (int *)FUN_0002acb4();
  iVar3 = 0;
  piVar4 = piVar1;
  if (0 < iVar5) {
    do {
      *piVar4 = iVar3;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < iVar5);
  }
  uVar2 = (**(code **)(*param_1 + 0x14))(param_1,piVar1,param_1[4],param_2);
  ___V_YAXPAX_Z(piVar1);
  return uVar2;
}



/* 00025e90 FUN_00025e90 */

/* Boundary evidence: original MIPS .pdata 00025e90..00026287. Semantic name remains unreviewed. */

undefined4 FUN_00025e90(int *param_1,int *param_2,uint param_3,short *param_4)

{
  short sVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  short *psVar8;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  longlong lVar17;
  uint local_860;
  wchar_t local_850 [520];
  short local_440 [520];
  uint local_30;
  
  local_30 = DAT_000372d4;
  if (param_2 == (int *)0x0) {
LAB_00025ee4:
    param_1[0x96] = 0x37;
LAB_00025eec:
    FUN_0002a0c4(local_30);
    uVar3 = 0;
  }
  else {
    param_1[0x96] = 0;
    if (param_4 == (short *)0x0) {
      local_440[0] = 0;
      local_850[0] = L'\0';
    }
    else {
      psVar8 = local_440;
      psVar10 = param_4;
      do {
        sVar1 = *psVar10;
        psVar10 = psVar10 + 1;
        *psVar8 = sVar1;
        psVar8 = psVar8 + 1;
      } while (sVar1 != 0);
      FUN_000244ac(local_440);
    }
    FUN_000254d4((int)param_1,param_2,param_3);
    if (param_1[0x95] == 0) {
      local_860 = 0;
      uVar3 = 1;
      if (param_3 != 0) {
        piVar16 = param_1 + 0x98;
        do {
          if (*piVar16 != 0) goto LAB_00025eec;
          iVar15 = *param_2;
          if (((iVar15 < 0) || (param_1[4] <= iVar15)) ||
             (iVar14 = *(int *)(iVar15 * 4 + param_1[2]), iVar14 == 0)) goto LAB_00025ee4;
          iVar4 = FUN_00024364(local_850,0x208,local_440,*(short **)(iVar14 + 4));
          if (iVar4 == 0) goto LAB_00025eec;
          if ((*(uint *)(iVar14 + 0x24) & 0x10) == 0) {
            piVar5 = param_1 + 0x97;
            *piVar5 = 0;
            param_1[0x96] = 0;
            bVar2 = false;
            param_1[0x9e] = *(int *)(iVar14 + 0x10);
            param_1[0x9f] = *(int *)(iVar14 + 0x14);
            param_1[0xa0] = *(int *)(iVar14 + 0x18);
            puVar6 = (undefined4 *)param_1[0x99];
            param_1[0xa1] = *(int *)(iVar14 + 0x1c);
            param_1[0xa6] = 0;
            param_1[0xa7] = 0;
            param_1[0xa8] = 0;
            param_1[0xa9] = 0;
            if ((puVar6 == (undefined4 *)0x0) ||
               ((**(code **)*puVar6)(puVar6,iVar14,local_850,piVar5,piVar16),
               *piVar16 == 0 && *piVar5 == 0)) {
              piVar5 = (int *)(*(code *)param_1[0x93])(local_850,param_1[0x94]);
              if (piVar5 == (int *)0x0) {
                piVar7 = (int *)param_1[0x99];
                param_1[0x96] = 0x31;
                if (piVar7 != (int *)0x0) {
                  (**(code **)(*piVar7 + 0xc))(piVar7,0x31,iVar14,piVar16);
                }
                uVar3 = 0;
              }
              else {
                iVar15 = FUN_00026288(param_1,iVar15,iVar14,piVar5);
                if (iVar15 == 0) {
                  uVar3 = 0;
                  lVar17 = (**(code **)(*piVar5 + 0x24))(piVar5);
                  if (lVar17 == 0) {
                    bVar2 = true;
                  }
                }
              }
              if (piVar5 != (int *)0x0) {
                (**(code **)(*piVar5 + 8))(piVar5);
              }
              if (bVar2) {
                DeleteFileW(local_850);
              }
            }
            else {
              param_1[0x96] = 0x17;
            }
          }
          else if (param_4 != (short *)0x0) {
            FUN_000244ac(local_850);
            iVar15 = FUN_00023fd8(local_850);
            if (iVar15 == 0) {
              piVar5 = (int *)param_1[0x99];
              param_1[0x96] = 0x34;
              if (piVar5 != (int *)0x0) {
                (**(code **)(*piVar5 + 0xc))(piVar5,0x34,iVar14,piVar16);
              }
              uVar3 = 0;
            }
          }
          if (param_1[0x99] != 0) {
            uVar11 = param_1[0xa2];
            uVar12 = uVar11 + param_1[0x9e];
            uVar9 = param_1[0xa4];
            param_1[0xa2] = uVar12;
            uVar13 = uVar9 + param_1[0xa0];
            param_1[0xa3] = param_1[0xa3] + param_1[0x9f] + (uint)(uVar12 < uVar11);
            param_1[0xa4] = uVar13;
            param_1[0xa5] = param_1[0xa5] + param_1[0xa1] + (uint)(uVar13 < uVar9);
            param_1[0xa0] = 0;
            param_1[0xa1] = 0;
            param_1[0x9e] = 0;
            param_1[0x9f] = 0;
            param_1[0xa8] = 0;
            param_1[0xa9] = 0;
            param_1[0xa6] = 0;
            param_1[0xa7] = 0;
            FUN_00025354((int)param_1);
            (**(code **)(*(int *)param_1[0x99] + 8))
                      ((int *)param_1[0x99],param_1 + 0x9a,param_1[0x96]);
          }
          local_860 = local_860 + 1;
          param_2 = param_2 + 1;
        } while (local_860 < param_3);
      }
      FUN_0002a0c4(local_30);
    }
    else {
      uVar3 = (**(code **)(*param_1 + 0x50))(param_1,param_2,param_3,param_4);
      FUN_0002a0c4(local_30);
    }
  }
  return uVar3;
}



/* 00026288 FUN_00026288 */

/* Boundary evidence: original MIPS .pdata 00026288..00026457. Semantic name remains unreviewed. */

undefined4 FUN_00026288(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  byte bVar3;
  undefined4 uVar4;
  code *pcVar5;
  longlong lVar6;
  
  if (*(int *)(param_3 + 0x18) == 0 && *(int *)(param_3 + 0x1c) == 0) {
    return 1;
  }
  if (param_1[0x97] == 0 && param_1[0x98] == 0) {
    iVar1 = (**(code **)(*param_4 + 0x1c))(param_4);
    if (iVar1 == 0) {
      piVar2 = (int *)param_1[0x99];
      param_1[0x96] = 0x42;
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      uVar4 = 0x42;
    }
    else {
      pcVar5 = *(code **)(*param_1 + 0x4c);
      param_1[0x96] = 0;
      iVar1 = (*pcVar5)(param_1,param_2,param_3,param_4);
      if (iVar1 == 0) {
        return 0;
      }
      bVar3 = (*(uint *)(param_3 + 0x24) & 1) != 0;
      if ((*(uint *)(param_3 + 0x24) & 2) != 0) {
        bVar3 = bVar3 | 2;
      }
      if (bVar3 != 0) {
        (**(code **)(*param_4 + 0x20))(param_4);
      }
      iVar1 = (**(code **)(*param_4 + 0x18))(param_4);
      if (iVar1 == 0) {
        piVar2 = (int *)param_1[0x99];
        param_1[0x96] = 0x30;
        if (piVar2 == (int *)0x0) {
          return 0;
        }
        uVar4 = 0x30;
      }
      else {
        if (param_1[0x92] == 0xc) {
          return 1;
        }
        if (param_1[0x92] == 0xd) {
          return 1;
        }
        if ((*(uint *)(param_3 + 0x18) & *(uint *)(param_3 + 0x1c)) == 0xffffffff) {
          return 1;
        }
        lVar6 = (**(code **)(*param_4 + 0x24))(param_4);
        if (lVar6 == *(longlong *)(param_3 + 0x18)) {
          return 1;
        }
        piVar2 = (int *)param_1[0x99];
        param_1[0x96] = 0x43;
        if (piVar2 == (int *)0x0) {
          return 0;
        }
        uVar4 = 0x43;
      }
    }
    (**(code **)(*piVar2 + 0xc))(piVar2,uVar4,param_3,param_1 + 0x98);
  }
  return 0;
}



/* 00026458 FUN_00026458 */

/* Boundary evidence: original MIPS .pdata 00026458..0002657b. Semantic name remains unreviewed. */

undefined4 FUN_00026458(int param_1,int param_2,int *param_3,uint *param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint auStack_28 [3];
  uint local_1c;
  
  local_1c = DAT_000372d4;
  *(undefined4 *)(param_1 + 0x208) = 0;
  iVar2 = *(int *)(param_2 + 0x20);
  *(int *)(param_1 + 0x204) = iVar2;
  *(int **)(param_1 + 0x20c) = param_3;
  if (iVar2 == 0) {
LAB_000264a4:
    FUN_0002a0c4(local_1c);
    uVar1 = 1;
  }
  else {
    if (*(char *)(param_1 + 4) == '\0') {
      *(undefined4 *)(param_1 + 0x208) = 0x20;
    }
    else {
      if (iVar2 == 1) {
        iVar2 = (**(code **)(*param_3 + 0x14))(param_3,auStack_28,0xc);
        if (iVar2 == 0) {
          uVar1 = 0x15;
        }
        else {
          uVar3 = *param_4;
          *param_4 = uVar3 - 0xc;
          param_4[1] = param_4[1] - (uint)(uVar3 < 0xc);
          FUN_00026634(param_1,(char *)(param_1 + 4));
          iVar2 = FUN_00026730(param_1,auStack_28,(uint)*(byte *)(param_2 + 0x4c));
          if (iVar2 != 0) goto LAB_000264a4;
          uVar1 = 0x21;
        }
      }
      else {
        uVar1 = 0x46;
      }
      *(undefined4 *)(param_1 + 0x208) = uVar1;
    }
    FUN_0002a0c4(local_1c);
    uVar1 = 0;
  }
  return uVar1;
}



/* 0002657c FUN_0002657c */

void FUN_0002657c(int param_1,int param_2,byte *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar1 = *(uint *)(param_1 + 0x218);
    uVar2 = uVar1 & 0xffff | 2;
    uVar2 = (int)((uVar2 ^ 1) * uVar2) >> 8 ^ (uint)*param_3;
    uVar3 = *(uint *)(((uVar2 & 0xff ^ *(uint *)(param_1 + 0x210)) & 0xff) * 4 +
                     *(int *)(param_1 + 0x21c)) ^ *(uint *)(param_1 + 0x210) >> 8;
    *(uint *)(param_1 + 0x210) = uVar3;
    uVar3 = ((uVar3 & 0xff) + *(int *)(param_1 + 0x214)) * 0x8088405 + 1;
    *(uint *)(param_1 + 0x214) = uVar3;
    *(uint *)(param_1 + 0x218) =
         *(uint *)(((uVar3 >> 0x18 ^ uVar1) & 0xff) * 4 + *(int *)(param_1 + 0x21c)) ^ uVar1 >> 8;
    *param_3 = (byte)uVar2;
    param_3 = param_3 + 1;
  }
  return;
}



/* 00026634 FUN_00026634 */

void FUN_00026634(int param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x214) = 0x23456789;
  *(undefined4 *)(param_1 + 0x218) = 0x34567890;
  iVar4 = 0;
  *(undefined4 *)(param_1 + 0x210) = 0x12345678;
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(pcVar3 + (-1 - (int)param_2))) {
    do {
      uVar2 = *(uint *)((((uint)(byte)param_2[iVar4] ^ *(uint *)(param_1 + 0x210)) & 0xff) * 4 +
                       *(int *)(param_1 + 0x21c)) ^ *(uint *)(param_1 + 0x210) >> 8;
      *(uint *)(param_1 + 0x210) = uVar2;
      iVar4 = iVar4 + 1;
      uVar2 = ((uVar2 & 0xff) + *(int *)(param_1 + 0x214)) * 0x8088405 + 1;
      *(uint *)(param_1 + 0x214) = uVar2;
      *(uint *)(param_1 + 0x218) =
           *(uint *)(((uVar2 >> 0x18 ^ *(uint *)(param_1 + 0x218)) & 0xff) * 4 +
                    *(int *)(param_1 + 0x21c)) ^ *(uint *)(param_1 + 0x218) >> 8;
      pcVar3 = param_2;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    } while (iVar4 < (int)(pcVar3 + (-1 - (int)param_2)));
  }
  return;
}



/* 00026730 FUN_00026730 */

/* Boundary evidence: original MIPS .pdata 00026730..00026a13. Semantic name remains unreviewed. */

undefined4 FUN_00026730(int param_1,uint *param_2,uint param_3)

{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 local_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  uint local_c;
  
  local_c = DAT_000372d4;
  local_18 = (undefined1  [4])*param_2;
  uVar5 = param_2[1];
  uVar8 = param_2[2];
  puVar1 = local_18 + 3;
  uVar9 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar9) =
       *(uint *)(puVar1 + -uVar9) & -1 << (uVar9 + 1) * 8 | (uint)local_18 >> (3 - uVar9) * 8;
  puVar1 = auStack_14 + 3;
  uVar9 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar9) =
       *(uint *)(puVar1 + -uVar9) & -1 << (uVar9 + 1) * 8 | uVar5 >> (3 - uVar9) * 8;
  puVar1 = auStack_10 + 3;
  uVar9 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar9) =
       *(uint *)(puVar1 + -uVar9) & -1 << (uVar9 + 1) * 8 | uVar8 >> (3 - uVar9) * 8;
  iVar4 = *(int *)(param_1 + 0x21c);
  auStack_14 = (undefined1  [4])uVar5;
  auStack_10 = (undefined1  [4])uVar8;
  iVar3 = 0;
  do {
    uVar9 = *(uint *)(param_1 + 0x218) & 0xffff | 2;
    uVar8 = *(uint *)(param_1 + 0x218);
    uVar9 = (int)((uVar9 ^ 1) * uVar9) >> 8 ^ (uint)(byte)local_18[iVar3];
    uVar5 = *(uint *)(((uVar9 & 0xff ^ *(uint *)(param_1 + 0x210)) & 0xff) * 4 + iVar4) ^
            *(uint *)(param_1 + 0x210) >> 8;
    iVar6 = *(int *)(param_1 + 0x214);
    *(uint *)(param_1 + 0x210) = uVar5;
    local_18[iVar3] = (byte)uVar9;
    uVar9 = ((uVar5 & 0xff) + iVar6) * 0x8088405 + 1;
    *(uint *)(param_1 + 0x214) = uVar9;
    uVar5 = *(uint *)(((uVar9 >> 0x18 ^ uVar8) & 0xff) * 4 + iVar4) ^ uVar8 >> 8;
    uVar9 = uVar5 & 0xffff | 2;
    bVar2 = local_18[iVar3 + 1];
    *(uint *)(param_1 + 0x218) = uVar5;
    uVar9 = (int)((uVar9 ^ 1) * uVar9) >> 8 ^ (uint)bVar2;
    uVar8 = *(uint *)(((uVar9 & 0xff ^ *(uint *)(param_1 + 0x210)) & 0xff) * 4 + iVar4) ^
            *(uint *)(param_1 + 0x210) >> 8;
    iVar6 = *(int *)(param_1 + 0x214);
    uVar5 = *(uint *)(param_1 + 0x218);
    *(uint *)(param_1 + 0x210) = uVar8;
    local_18[iVar3 + 1] = (char)uVar9;
    uVar9 = ((uVar8 & 0xff) + iVar6) * 0x8088405 + 1;
    *(uint *)(param_1 + 0x214) = uVar9;
    uVar5 = *(uint *)(((uVar9 >> 0x18 ^ uVar5) & 0xff) * 4 + iVar4) ^ uVar5 >> 8;
    uVar9 = uVar5 & 0xffff | 2;
    *(uint *)(param_1 + 0x218) = uVar5;
    uVar9 = (int)((uVar9 ^ 1) * uVar9) >> 8 ^ (uint)(byte)local_18[iVar3 + 2];
    uVar8 = *(uint *)(((uVar9 & 0xff ^ *(uint *)(param_1 + 0x210)) & 0xff) * 4 + iVar4) ^
            *(uint *)(param_1 + 0x210) >> 8;
    iVar7 = *(int *)(param_1 + 0x214);
    uVar5 = *(uint *)(param_1 + 0x218);
    *(uint *)(param_1 + 0x210) = uVar8;
    local_18[iVar3 + 2] = (char)uVar9;
    iVar6 = iVar3 + 4;
    uVar9 = ((uVar8 & 0xff) + iVar7) * 0x8088405 + 1;
    *(uint *)(param_1 + 0x214) = uVar9;
    uVar5 = *(uint *)(((uVar9 >> 0x18 ^ uVar5) & 0xff) * 4 + iVar4) ^ uVar5 >> 8;
    uVar9 = uVar5 & 0xffff | 2;
    bVar2 = local_18[iVar3 + 3];
    *(uint *)(param_1 + 0x218) = uVar5;
    uVar9 = (int)((uVar9 ^ 1) * uVar9) >> 8 ^ (uint)bVar2;
    uVar10 = uVar9 & 0xff;
    uVar8 = *(uint *)(((uVar10 ^ *(uint *)(param_1 + 0x210)) & 0xff) * 4 + iVar4) ^
            *(uint *)(param_1 + 0x210) >> 8;
    iVar7 = *(int *)(param_1 + 0x214);
    uVar5 = *(uint *)(param_1 + 0x218);
    *(uint *)(param_1 + 0x210) = uVar8;
    local_18[iVar3 + 3] = (char)uVar9;
    uVar9 = ((uVar8 & 0xff) + iVar7) * 0x8088405 + 1;
    *(uint *)(param_1 + 0x214) = uVar9;
    *(uint *)(param_1 + 0x218) =
         *(uint *)(((uVar9 >> 0x18 ^ uVar5) & 0xff) * 4 + iVar4) ^ uVar5 >> 8;
    iVar3 = iVar6;
  } while (iVar6 < 0xc);
  if (uVar10 == param_3) {
    FUN_0002a0c4(local_c);
    return 1;
  }
  FUN_0002a0c4(local_c);
  return 0;
}



/* 00026a14 FUN_00026a14 */

/* Boundary evidence: original MIPS .pdata 00026a14..00026a57. Semantic name remains unreviewed. */

void FUN_00026a14(int param_1,byte *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x204);
  if ((iVar1 != 0) && ((iVar1 == 1 || (iVar1 == 5)))) {
    FUN_0002657c(param_1,param_3,param_2);
  }
  return;
}



/* 00026a60 FUN_00026a60 */

/* Boundary evidence: original MIPS .pdata 00026a60..00026a8f. Semantic name remains unreviewed. */

uint FUN_00026a60(uint param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  
  if (param_2 == (uint *)0x0) {
    return 0;
  }
  uVar1 = FUN_00026a90(param_1,param_2,param_3);
  return uVar1;
}



/* 00026a90 FUN_00026a90 */

/* Boundary evidence: original MIPS .pdata 00026a90..00026f27. Semantic name remains unreviewed. */

uint FUN_00026a90(uint param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ~param_1;
  for (; (param_3 != 0 && (((uint)param_2 & 3) != 0)); param_2 = (uint *)((int)param_2 + 1)) {
    uVar1 = *(uint *)(&DAT_0002c1b8 + (((byte)*param_2 ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
    param_3 = param_3 - 1;
  }
  if (0x1f < param_3) {
    uVar2 = param_3 >> 5;
    do {
      uVar1 = *param_2 ^ uVar1;
      uVar1 = *(uint *)(&DAT_0002c5b8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c9b8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c1b8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cdb8 + (uVar1 & 0xff) * 4) ^ param_2[1];
      uVar1 = *(uint *)(&DAT_0002c5b8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c9b8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c1b8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cdb8 + (uVar1 & 0xff) * 4) ^ param_2[2];
      uVar1 = *(uint *)(&DAT_0002c5b8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c9b8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c1b8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cdb8 + (uVar1 & 0xff) * 4) ^ param_2[3];
      uVar1 = *(uint *)(&DAT_0002c5b8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c9b8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c1b8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cdb8 + (uVar1 & 0xff) * 4) ^ param_2[4];
      uVar1 = *(uint *)(&DAT_0002c5b8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c9b8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c1b8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cdb8 + (uVar1 & 0xff) * 4) ^ param_2[5];
      uVar1 = *(uint *)(&DAT_0002c5b8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c9b8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c1b8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cdb8 + (uVar1 & 0xff) * 4) ^ param_2[6];
      uVar1 = *(uint *)(&DAT_0002c5b8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c9b8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c1b8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cdb8 + (uVar1 & 0xff) * 4) ^ param_2[7];
      param_2 = param_2 + 8;
      uVar1 = *(uint *)(&DAT_0002c5b8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c9b8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c1b8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cdb8 + (uVar1 & 0xff) * 4);
      uVar2 = uVar2 - 1;
      param_3 = param_3 - 0x20;
    } while (uVar2 != 0);
  }
  if (3 < param_3) {
    uVar2 = param_3 >> 2;
    do {
      uVar1 = *param_2 ^ uVar1;
      param_2 = param_2 + 1;
      uVar1 = *(uint *)(&DAT_0002c5b8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c9b8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c1b8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cdb8 + (uVar1 & 0xff) * 4);
      uVar2 = uVar2 - 1;
      param_3 = param_3 - 4;
    } while (uVar2 != 0);
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    uVar1 = *(uint *)(&DAT_0002c1b8 + (((byte)*param_2 ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
    param_2 = (uint *)((int)param_2 + 1);
  }
  return ~uVar1;
}



/* 00026f28 FUN_00026f28 */

undefined4 FUN_00026f28(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if ((param_1 != 0) && (puVar2 = *(undefined4 **)(param_1 + 0x1c), puVar2 != (undefined4 *)0x0)) {
    *(undefined4 *)(param_1 + 0x30) = 1;
    puVar1 = puVar2 + 0x14c;
    puVar2[7] = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[3] = 0;
    puVar2[5] = 0x8000;
    puVar2[8] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    puVar2[0xc] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0x1b] = puVar1;
    puVar2[0x14] = puVar1;
    puVar2[0x13] = puVar1;
    return 0;
  }
  return 0xfffffffe;
}



/* 00026fa4 FUN_00026fa4 */

/* Boundary evidence: original MIPS .pdata 00026fa4..0002705f. Semantic name remains unreviewed. */

undefined4 FUN_00026fa4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    return 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (*(int *)(param_1 + 0x20) == 0) {
    *(code **)(param_1 + 0x20) = FUN_00028c88;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    *(code **)(param_1 + 0x24) = FUN_00028cb4;
  }
  iVar1 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x2530);
  if (iVar1 == 0) {
    return 0xfffffffc;
  }
  *(int *)(param_1 + 0x1c) = iVar1;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0xf;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  uVar2 = FUN_00026f28(param_1);
  return uVar2;
}



/* 00027060 FUN_00027060 */

/* Boundary evidence: original MIPS .pdata 00027060..000271cb. Semantic name remains unreviewed. */

undefined4 FUN_00027060(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  size_t _Size;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  if (*(int *)(iVar3 + 0x34) == 0) {
    iVar1 = (**(code **)(param_1 + 0x20))
                      (*(undefined4 *)(param_1 + 0x28),1 << (*(uint *)(iVar3 + 0x24) & 0x1f),1);
    *(int *)(iVar3 + 0x34) = iVar1;
    if (iVar1 == 0) {
      return 1;
    }
  }
  if (*(int *)(iVar3 + 0x28) == 0) {
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *(int *)(iVar3 + 0x28) = 1 << (*(uint *)(iVar3 + 0x24) & 0x1f);
    *(undefined4 *)(iVar3 + 0x2c) = 0;
  }
  uVar2 = *(uint *)(iVar3 + 0x28);
  uVar4 = param_2 - *(int *)(param_1 + 0x10);
  if (uVar4 < uVar2) {
    uVar2 = uVar2 - *(int *)(iVar3 + 0x30);
    if (uVar4 < uVar2) {
      uVar2 = uVar4;
    }
    iVar1 = *(int *)(param_1 + 0xc);
    memcpy((void *)(*(int *)(iVar3 + 0x34) + *(int *)(iVar3 + 0x30)),(void *)(iVar1 - uVar4),uVar2);
    _Size = uVar4 - uVar2;
    if (_Size == 0) {
      uVar4 = *(int *)(iVar3 + 0x30) + uVar2;
      *(uint *)(iVar3 + 0x30) = uVar4;
      if (uVar4 == *(uint *)(iVar3 + 0x28)) {
        *(undefined4 *)(iVar3 + 0x30) = 0;
      }
      if (*(uint *)(iVar3 + 0x2c) < *(uint *)(iVar3 + 0x28)) {
        *(uint *)(iVar3 + 0x2c) = *(uint *)(iVar3 + 0x2c) + uVar2;
      }
    }
    else {
      memcpy(*(void **)(iVar3 + 0x34),(void *)(iVar1 - _Size),_Size);
      *(size_t *)(iVar3 + 0x30) = _Size;
      *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 0x28);
    }
  }
  else {
    memcpy(*(void **)(iVar3 + 0x34),(void *)(*(int *)(param_1 + 0xc) - uVar2),uVar2);
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 0x28);
  }
  return 0;
}



/* 000271cc FUN_000271cc */

/* Boundary evidence: original MIPS .pdata 000271cc..00028c87. Semantic name remains unreviewed. */

int FUN_000271cc(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  uint *puVar6;
  size_t _Size;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined2 uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint *_Src;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  undefined1 *_Dst;
  int local_78;
  undefined4 local_74;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_6d;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined *local_60;
  char *local_5c;
  undefined *local_58;
  undefined *local_54;
  char *local_50;
  char *local_4c;
  char *local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  uint local_2c;
  
  if ((((param_1 != (int *)0x0) && (puVar18 = (uint *)param_1[7], puVar18 != (uint *)0x0)) &&
      (_Dst = (undefined1 *)param_1[3], _Dst != (undefined1 *)0x0)) &&
     ((_Src = (uint *)*param_1, _Src != (uint *)0x0 || (param_1[1] == 0)))) {
    if (*puVar18 == 0xb) {
      *puVar18 = 0xc;
    }
    uVar19 = param_1[4];
    uVar16 = param_1[1];
    uVar9 = *puVar18;
    uVar17 = puVar18[0xe];
    uVar15 = puVar18[0xf];
    local_78 = 0;
    if (uVar9 < 0x1d) {
      local_58 = &DAT_00035410;
      local_54 = &DAT_00034c10;
      local_60 = &DAT_00035490;
      local_50 = "incorrect length check";
      local_4c = "incorrect data check";
      local_48 = "invalid distance too far back";
      local_44 = "invalid distance code";
      local_40 = "invalid literal/length code";
      local_5c = "invalid bit length repeat";
      local_38 = "invalid code lengths set";
      local_34 = "too many length or distance symbols";
      local_30 = "invalid stored block lengths";
      local_3c = "unknown compression method";
      local_6c = uVar19;
      local_64 = uVar19;
      local_2c = uVar16;
      do {
        pcVar4 = local_38;
        uVar10 = uVar16;
        switch((int)&switchD_00027330::switchdataD_00027338 +
               (int)(short)(&switchD_00027330::switchdataD_00027338)[uVar9] & 0xfffffffe) {
        case 0x27374:
          if (puVar18[2] != 0) {
            for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027958;
              uVar16 = uVar16 - 1;
              uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
              _Src = (uint *)((int)_Src + 1);
            }
            if (((puVar18[2] & 2) != 0) && (uVar17 == 0x8b1f)) {
              uVar15 = FUN_00026a60(0,(uint *)0x0,0);
              local_70 = 0x1f;
              puVar18[6] = uVar15;
              local_6f = 0x8b;
              uVar15 = FUN_00026a90(uVar15,(uint *)&local_70,2);
              puVar18[6] = uVar15;
              uVar17 = 0;
              uVar15 = 0;
              uVar9 = 1;
              goto LAB_00028ad0;
            }
            puVar18[4] = 0;
            if (puVar18[8] != 0) {
              *(undefined4 *)(puVar18[8] + 0x30) = 0xffffffff;
            }
            if (((puVar18[2] & 1) == 0) ||
               (uVar9 = (uVar17 & 0xff) * 0x100 + (uVar17 >> 8),
               uVar9 + ((uVar9 - uVar9 / 0x1f >> 1) + uVar9 / 0x1f >> 4) * -0x1f != 0)) {
              param_1[6] = (int)"incorrect header check";
              break;
            }
            if ((uVar17 & 0xf) != 8) {
              param_1[6] = (int)local_3c;
              break;
            }
            uVar17 = uVar17 >> 4;
            uVar9 = (uVar17 & 0xf) + 8;
            uVar15 = uVar15 - 4;
            if (puVar18[9] < uVar9) {
              param_1[6] = (int)"invalid window size";
              break;
            }
            puVar18[5] = 1 << uVar9;
            uVar15 = FUN_00028cd0(0,(byte *)0x0,0);
            puVar18[6] = uVar15;
            param_1[0xc] = uVar15;
            if ((uVar17 & 0x200) == 0) {
              *puVar18 = 0xb;
              uVar17 = 0;
              uVar15 = 0;
            }
            else {
              *puVar18 = 9;
              uVar17 = 0;
              uVar15 = 0;
            }
            goto LAB_00028ad4;
          }
          uVar9 = 0xc;
          goto LAB_00028ad0;
        case 0x27534:
          for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
            uVar10 = 0;
            if (uVar16 == 0) goto LAB_00027958;
            uVar16 = uVar16 - 1;
            uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
            _Src = (uint *)((int)_Src + 1);
          }
          puVar18[4] = uVar17;
          if ((uVar17 & 0xff) == 8) {
            if ((uVar17 & 0xe000) == 0) {
              if ((uint *)puVar18[8] != (uint *)0x0) {
                *(uint *)puVar18[8] = uVar17 >> 8 & 1;
              }
              if ((puVar18[4] & 0x200) != 0) {
                local_70 = (undefined1)uVar17;
                local_6f = (undefined1)(uVar17 >> 8);
                uVar15 = FUN_00026a90(puVar18[6],(uint *)&local_70,2);
                puVar18[6] = uVar15;
              }
              *puVar18 = 2;
              uVar17 = 0;
              uVar15 = 0;
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027958;
                uVar19 = uVar15 & 0x1f;
                uVar15 = uVar15 + 8;
                uVar16 = uVar16 - 1;
                uVar17 = ((uint)(byte)*_Src << uVar19) + uVar17;
                _Src = (uint *)((int)_Src + 1);
joined_r0x000275fc:
              } while (uVar15 < 0x20);
              if (puVar18[8] != 0) {
                *(uint *)(puVar18[8] + 4) = uVar17;
              }
              if ((puVar18[4] & 0x200) != 0) {
                local_70 = (undefined1)uVar17;
                local_6f = (undefined1)(uVar17 >> 8);
                local_6e = (undefined1)(uVar17 >> 0x10);
                local_6d = (undefined1)(uVar17 >> 0x18);
                uVar15 = FUN_00026a90(puVar18[6],(uint *)&local_70,4);
                puVar18[6] = uVar15;
              }
              *puVar18 = 3;
              uVar17 = 0;
              uVar15 = 0;
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027958;
                uVar19 = uVar15 & 0x1f;
                uVar15 = uVar15 + 8;
                uVar16 = uVar16 - 1;
                uVar17 = ((uint)(byte)*_Src << uVar19) + uVar17;
                _Src = (uint *)((int)_Src + 1);
joined_r0x00027694:
              } while (uVar15 < 0x10);
              if (puVar18[8] != 0) {
                *(uint *)(puVar18[8] + 8) = uVar17 & 0xff;
                *(uint *)(puVar18[8] + 0xc) = uVar17 >> 8;
              }
              if ((puVar18[4] & 0x200) != 0) {
                local_70 = (undefined1)uVar17;
                local_6f = (undefined1)(uVar17 >> 8);
                uVar15 = FUN_00026a90(puVar18[6],(uint *)&local_70,2);
                puVar18[6] = uVar15;
              }
              *puVar18 = 4;
              uVar17 = 0;
              uVar15 = 0;
              goto switchD_00027330_caseD_27724;
            }
            param_1[6] = (int)"unknown header flags set";
          }
          else {
            param_1[6] = (int)local_3c;
          }
          break;
        case 0x275f8:
          goto joined_r0x000275fc;
        case 0x27690:
          goto joined_r0x00027694;
        case 0x27724:
switchD_00027330_caseD_27724:
          if ((puVar18[4] & 0x400) == 0) {
            if (puVar18[8] != 0) {
              *(undefined4 *)(puVar18[8] + 0x10) = 0;
            }
          }
          else {
            for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027958;
              uVar16 = uVar16 - 1;
              uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
              _Src = (uint *)((int)_Src + 1);
            }
            puVar18[0x10] = uVar17;
            if (puVar18[8] != 0) {
              *(uint *)(puVar18[8] + 0x14) = uVar17;
            }
            if ((puVar18[4] & 0x200) != 0) {
              local_70 = (undefined1)uVar17;
              local_6f = (undefined1)(uVar17 >> 8);
              uVar15 = FUN_00026a90(puVar18[6],(uint *)&local_70,2);
              puVar18[6] = uVar15;
            }
            uVar17 = 0;
            uVar15 = 0;
          }
          *puVar18 = 5;
        case 0x277cc:
          if ((puVar18[4] & 0x400) != 0) {
            uVar9 = puVar18[0x10];
            uVar19 = uVar9;
            if (uVar16 < uVar9) {
              uVar19 = uVar16;
            }
            if (uVar19 != 0) {
              uVar10 = puVar18[8];
              if ((uVar10 != 0) && (*(int *)(uVar10 + 0x10) != 0)) {
                iVar5 = *(int *)(uVar10 + 0x14) - uVar9;
                _Size = *(uint *)(uVar10 + 0x18) - iVar5;
                if (uVar19 + iVar5 <= *(uint *)(uVar10 + 0x18)) {
                  _Size = uVar19;
                }
                memcpy((void *)(*(int *)(uVar10 + 0x10) + iVar5),_Src,_Size);
              }
              if ((puVar18[4] & 0x200) != 0) {
                if (_Src == (uint *)0x0) {
                  uVar9 = 0;
                }
                else {
                  uVar9 = FUN_00026a90(puVar18[6],_Src,uVar19);
                }
                puVar18[6] = uVar9;
              }
              uVar16 = uVar16 - uVar19;
              puVar18[0x10] = puVar18[0x10] - uVar19;
              _Src = (uint *)(uVar19 + (int)_Src);
            }
            uVar10 = uVar16;
            if (puVar18[0x10] != 0) goto LAB_00027958;
          }
          puVar18[0x10] = 0;
          *puVar18 = 6;
switchD_00027330_caseD_2789c:
          if ((puVar18[4] & 0x800) != 0) {
            uVar10 = uVar16;
            if (uVar16 != 0) {
              uVar19 = 0;
              do {
                cVar1 = *(char *)(uVar19 + (int)_Src);
                uVar9 = puVar18[8];
                uVar19 = uVar19 + 1;
                if (((uVar9 != 0) && (*(int *)(uVar9 + 0x1c) != 0)) &&
                   (puVar18[0x10] < *(uint *)(uVar9 + 0x20))) {
                  *(char *)(*(int *)(uVar9 + 0x1c) + puVar18[0x10]) = cVar1;
                  puVar18[0x10] = puVar18[0x10] + 1;
                }
              } while ((cVar1 != '\0') && (uVar19 < uVar16));
              if ((puVar18[4] & 0x200) != 0) {
                if (_Src == (uint *)0x0) {
                  uVar9 = 0;
                }
                else {
                  uVar9 = FUN_00026a90(puVar18[6],_Src,uVar19);
                }
                puVar18[6] = uVar9;
              }
              uVar16 = uVar16 - uVar19;
              _Src = (uint *)(uVar19 + (int)_Src);
              uVar10 = uVar16;
              if (cVar1 == '\0') goto LAB_000279cc;
            }
            goto LAB_00027958;
          }
          if (puVar18[8] != 0) {
            *(undefined4 *)(puVar18[8] + 0x1c) = 0;
          }
LAB_000279cc:
          puVar18[0x10] = 0;
          *puVar18 = 7;
switchD_00027330_caseD_279d8:
          if ((puVar18[4] & 0x1000) != 0) {
            uVar10 = uVar16;
            if (uVar16 != 0) {
              uVar19 = 0;
              do {
                cVar1 = *(char *)(uVar19 + (int)_Src);
                uVar9 = puVar18[8];
                uVar19 = uVar19 + 1;
                if (((uVar9 != 0) && (*(int *)(uVar9 + 0x24) != 0)) &&
                   (puVar18[0x10] < *(uint *)(uVar9 + 0x28))) {
                  *(char *)(*(int *)(uVar9 + 0x24) + puVar18[0x10]) = cVar1;
                  puVar18[0x10] = puVar18[0x10] + 1;
                }
              } while ((cVar1 != '\0') && (uVar19 < uVar16));
              if ((puVar18[4] & 0x200) != 0) {
                if (_Src == (uint *)0x0) {
                  uVar9 = 0;
                }
                else {
                  uVar9 = FUN_00026a90(puVar18[6],_Src,uVar19);
                }
                puVar18[6] = uVar9;
              }
              uVar16 = uVar16 - uVar19;
              _Src = (uint *)(uVar19 + (int)_Src);
              uVar10 = uVar16;
              if (cVar1 == '\0') goto LAB_00027aa8;
            }
            goto LAB_00027958;
          }
          if (puVar18[8] != 0) {
            *(undefined4 *)(puVar18[8] + 0x24) = 0;
          }
LAB_00027aa8:
          *puVar18 = 8;
          uVar19 = local_6c;
switchD_00027330_caseD_27ab4:
          if ((puVar18[4] & 0x200) != 0) {
            for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027958;
              uVar16 = uVar16 - 1;
              uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
              _Src = (uint *)((int)_Src + 1);
            }
            if (uVar17 != (puVar18[6] & 0xffff)) {
              param_1[6] = (int)"header crc mismatch";
              break;
            }
            uVar17 = 0;
            uVar15 = 0;
          }
          if (puVar18[8] != 0) {
            *(uint *)(puVar18[8] + 0x2c) = (int)puVar18[4] >> 9 & 1;
            *(undefined4 *)(puVar18[8] + 0x30) = 1;
          }
          uVar9 = FUN_00026a60(0,(uint *)0x0,0);
          puVar18[6] = uVar9;
          param_1[0xc] = uVar9;
LAB_00027b60:
          uVar9 = 0xb;
          goto LAB_00028ad0;
        case 0x2789c:
          goto switchD_00027330_caseD_2789c;
        case 0x279b4:
          goto LAB_00028c58;
        case 0x279d8:
          goto switchD_00027330_caseD_279d8;
        case 0x27ab4:
          goto switchD_00027330_caseD_27ab4;
        case 0x27b68:
          for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {
            uVar10 = 0;
            if (uVar16 == 0) goto LAB_00027958;
            uVar16 = uVar16 - 1;
            uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
            _Src = (uint *)((int)_Src + 1);
          }
          uVar15 = ((uVar17 & 0xff00) + uVar17 * 0x10000) * 0x100 + (uVar17 >> 8 & 0xff00) +
                   (uVar17 >> 0x18);
          puVar18[6] = uVar15;
          param_1[0xc] = uVar15;
          *puVar18 = 10;
          uVar17 = 0;
          uVar15 = 0;
        case 0x27bd8:
          if (puVar18[3] == 0) {
            param_1[3] = (int)_Dst;
            param_1[4] = uVar19;
            *param_1 = (int)_Src;
            param_1[1] = uVar16;
            puVar18[0xe] = uVar17;
            puVar18[0xf] = uVar15;
            return 2;
          }
          uVar9 = FUN_00028cd0(0,(byte *)0x0,0);
          puVar18[6] = uVar9;
          param_1[0xc] = uVar9;
          *puVar18 = 0xb;
switchD_00027330_caseD_27c0c:
          if (puVar18[1] == 0) {
            for (; uVar15 < 3; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027958;
              uVar16 = uVar16 - 1;
              uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
              _Src = (uint *)((int)_Src + 1);
            }
            puVar18[1] = uVar17 & 1;
            switch(uVar17 >> 1 & 3) {
            case 0:
              *puVar18 = 0xd;
              uVar17 = uVar17 >> 3;
              uVar15 = uVar15 - 3;
              break;
            case 1:
              puVar18[0x15] = 9;
              puVar18[0x16] = 5;
              puVar18[0x13] = (uint)local_54;
              puVar18[0x14] = (uint)local_58;
              uVar17 = uVar17 >> 3;
              *puVar18 = 0x12;
              uVar15 = uVar15 - 3;
              break;
            case 2:
              *puVar18 = 0xf;
              uVar17 = uVar17 >> 3;
              uVar15 = uVar15 - 3;
              break;
            case 3:
              param_1[6] = (int)"invalid block type";
              *puVar18 = 0x1b;
            default:
              uVar17 = uVar17 >> 3;
              uVar15 = uVar15 - 3;
            }
            goto LAB_00028ad4;
          }
          uVar17 = uVar17 >> (uVar15 & 7);
          uVar15 = uVar15 - (uVar15 & 7);
          uVar9 = 0x18;
          goto LAB_00028ad0;
        case 0x27c0c:
          goto switchD_00027330_caseD_27c0c;
        case 0x27d10:
          uVar17 = uVar17 >> (uVar15 & 7);
          for (uVar15 = uVar15 - (uVar15 & 7); uVar15 < 0x20; uVar15 = uVar15 + 8) {
            uVar10 = 0;
            if (uVar16 == 0) goto LAB_00027958;
            uVar16 = uVar16 - 1;
            uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
            _Src = (uint *)((int)_Src + 1);
          }
          if ((uVar17 & 0xffff) == ~uVar17 >> 0x10) {
            puVar18[0x10] = uVar17 & 0xffff;
            uVar17 = 0;
            *puVar18 = 0xe;
            uVar15 = 0;
            goto switchD_00027330_caseD_27d80;
          }
          param_1[6] = (int)local_30;
          break;
        case 0x27d80:
switchD_00027330_caseD_27d80:
          uVar9 = puVar18[0x10];
          if (uVar9 != 0) {
            if (uVar16 < uVar9) {
              uVar9 = uVar16;
            }
            if (uVar19 < uVar9) {
              uVar9 = uVar19;
            }
            uVar10 = uVar16;
            if (uVar9 == 0) goto LAB_00027958;
            memcpy(_Dst,_Src,uVar9);
            uVar19 = uVar19 - uVar9;
            puVar18[0x10] = puVar18[0x10] - uVar9;
            uVar16 = uVar16 - uVar9;
            _Src = (uint *)(uVar9 + (int)_Src);
            _Dst = _Dst + uVar9;
            local_6c = uVar19;
            goto LAB_00028ad4;
          }
          goto LAB_00027b60;
        case 0x27de8:
          for (; uVar15 < 0xe; uVar15 = uVar15 + 8) {
            uVar10 = 0;
            if (uVar16 == 0) goto LAB_00027958;
            uVar16 = uVar16 - 1;
            uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
            _Src = (uint *)((int)_Src + 1);
          }
          puVar18[0x18] = (uVar17 & 0x1f) + 0x101;
          puVar18[0x19] = (uVar17 >> 5 & 0x1f) + 1;
          puVar18[0x17] = (uVar17 >> 10 & 0xf) + 4;
          uVar17 = uVar17 >> 0xe;
          uVar15 = uVar15 - 0xe;
          if ((puVar18[0x18] < 0x11f) && (puVar18[0x19] < 0x1f)) {
            puVar18[0x1a] = 0;
            *puVar18 = 0x10;
            goto switchD_00027330_caseD_27e78;
          }
          param_1[6] = (int)local_34;
          break;
        case 0x27e78:
switchD_00027330_caseD_27e78:
          if (puVar18[0x1a] < puVar18[0x17]) {
            do {
              for (; uVar15 < 3; uVar15 = uVar15 + 8) {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027958;
                uVar16 = uVar16 - 1;
                uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
                _Src = (uint *)((int)_Src + 1);
              }
              *(ushort *)((*(ushort *)(local_60 + puVar18[0x1a] * 2) + 0x38) * 2 + (int)puVar18) =
                   (ushort)uVar17 & 7;
              uVar9 = puVar18[0x1a];
              puVar18[0x1a] = uVar9 + 1;
              uVar17 = uVar17 >> 3;
              uVar15 = uVar15 - 3;
            } while (uVar9 + 1 < puVar18[0x17]);
          }
          uVar9 = puVar18[0x1a];
          while (uVar9 < 0x13) {
            *(undefined2 *)((*(ushort *)(local_60 + puVar18[0x1a] * 2) + 0x38) * 2 + (int)puVar18) =
                 0;
            uVar9 = puVar18[0x1a] + 1;
            puVar18[0x1a] = uVar9;
          }
          puVar18[0x15] = 7;
          puVar18[0x1b] = (uint)(puVar18 + 0x14c);
          puVar18[0x13] = (uint)(puVar18 + 0x14c);
          local_78 = FUN_0002903c(0,(ushort *)(puVar18 + 0x1c),0x13,(int *)(puVar18 + 0x1b),
                                  puVar18 + 0x15,(ushort *)(puVar18 + 0xbc));
          if (local_78 == 0) {
            puVar18[0x1a] = 0;
            *puVar18 = 0x11;
            goto LAB_00027fc4;
          }
          param_1[6] = (int)pcVar4;
          break;
        case 0x27fc0:
LAB_00027fc4:
          if (puVar18[0x1a] < puVar18[0x19] + puVar18[0x18]) {
            do {
              local_74 = *(uint *)(((1 << (puVar18[0x15] & 0x1f)) - 1U & uVar17) * 4 + puVar18[0x13]
                                  );
              uVar9 = local_74 >> 8 & 0xff;
              if (uVar15 < uVar9) {
                do {
                  uVar10 = 0;
                  if (uVar16 == 0) goto LAB_00027958;
                  uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
                  local_74 = *(uint *)(((1 << (puVar18[0x15] & 0x1f)) - 1U & uVar17) * 4 +
                                      puVar18[0x13]);
                  uVar15 = uVar15 + 8;
                  uVar9 = local_74 >> 8 & 0xff;
                  uVar16 = uVar16 - 1;
                  _Src = (uint *)((int)_Src + 1);
                } while (uVar15 < uVar9);
              }
              if (0xf < local_74._2_2_) {
                if (local_74._2_2_ == 0x10) {
                  for (; uVar15 < uVar9 + 2; uVar15 = uVar15 + 8) {
                    uVar10 = 0;
                    if (uVar16 == 0) goto LAB_00027958;
                    uVar16 = uVar16 - 1;
                    uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
                    _Src = (uint *)((int)_Src + 1);
                  }
                  uVar17 = uVar17 >> (uVar9 & 0x1f);
                  uVar15 = uVar15 - uVar9;
                  if (puVar18[0x1a] != 0) {
                    uVar13 = *(undefined2 *)((puVar18[0x1a] + 0x37) * 2 + (int)puVar18);
                    iVar5 = (uVar17 & 3) + 3;
                    uVar17 = uVar17 >> 2;
                    uVar15 = uVar15 - 2;
                    goto LAB_00028228;
                  }
                }
                else {
                  if (local_74._2_2_ == 0x11) {
                    for (; uVar15 < uVar9 + 3; uVar15 = uVar15 + 8) {
                      uVar10 = 0;
                      if (uVar16 == 0) goto LAB_00027958;
                      uVar16 = uVar16 - 1;
                      uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
                      _Src = (uint *)((int)_Src + 1);
                    }
                    uVar10 = uVar17 >> (uVar9 & 0x1f);
                    uVar17 = uVar10 >> 3;
                    iVar5 = (uVar10 & 7) + 3;
                    uVar15 = (uVar15 - uVar9) - 3;
                  }
                  else {
                    for (; uVar15 < uVar9 + 7; uVar15 = uVar15 + 8) {
                      uVar10 = 0;
                      if (uVar16 == 0) goto LAB_00027958;
                      uVar16 = uVar16 - 1;
                      uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
                      _Src = (uint *)((int)_Src + 1);
                    }
                    uVar10 = uVar17 >> (uVar9 & 0x1f);
                    uVar17 = uVar10 >> 7;
                    iVar5 = (uVar10 & 0x7f) + 0xb;
                    uVar15 = (uVar15 - uVar9) - 7;
                  }
                  uVar13 = 0;
LAB_00028228:
                  if (puVar18[0x1a] + iVar5 <= puVar18[0x19] + puVar18[0x18]) {
                    for (; iVar5 != 0; iVar5 = iVar5 + -1) {
                      *(undefined2 *)((puVar18[0x1a] + 0x38) * 2 + (int)puVar18) = uVar13;
                      puVar18[0x1a] = puVar18[0x1a] + 1;
                    }
                    goto LAB_00028278;
                  }
                }
                param_1[6] = (int)local_5c;
                goto LAB_00028acc;
              }
              for (; uVar15 < uVar9; uVar15 = uVar15 + 8) {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027958;
                uVar16 = uVar16 - 1;
                uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
                _Src = (uint *)((int)_Src + 1);
              }
              uVar17 = uVar17 >> (uVar9 & 0x1f);
              uVar15 = uVar15 - uVar9;
              *(ushort *)((puVar18[0x1a] + 0x38) * 2 + (int)puVar18) = local_74._2_2_;
              puVar18[0x1a] = puVar18[0x1a] + 1;
LAB_00028278:
            } while (puVar18[0x1a] < puVar18[0x19] + puVar18[0x18]);
          }
          if (*puVar18 != 0x1b) {
            puVar6 = puVar18 + 0x1b;
            *puVar6 = (uint)(puVar18 + 0x14c);
            puVar18[0x13] = (uint)(puVar18 + 0x14c);
            puVar18[0x15] = 9;
            local_78 = FUN_0002903c(1,(ushort *)(puVar18 + 0x1c),puVar18[0x18],(int *)puVar6,
                                    puVar18 + 0x15,(ushort *)(puVar18 + 0xbc));
            if (local_78 == 0) {
              puVar18[0x14] = *puVar6;
              puVar18[0x16] = 6;
              local_78 = FUN_0002903c(2,(ushort *)((puVar18[0x18] + 0x38) * 2 + (int)puVar18),
                                      puVar18[0x19],(int *)puVar6,puVar18 + 0x16,
                                      (ushort *)(puVar18 + 0xbc));
              uVar19 = local_6c;
              if (local_78 == 0) {
                *puVar18 = 0x12;
                goto switchD_00027330_caseD_28378;
              }
              param_1[6] = (int)"invalid distances set";
            }
            else {
              param_1[6] = (int)"invalid literal/lengths set";
              uVar19 = local_6c;
            }
            break;
          }
          goto LAB_00028ad4;
        case 0x28378:
switchD_00027330_caseD_28378:
          if ((uVar16 < 6) || (uVar19 < 0x102)) {
            uVar14 = *(uint *)(((1 << (puVar18[0x15] & 0x1f)) - 1U & uVar17) * 4 + puVar18[0x13]);
            uVar9 = uVar14 >> 8 & 0xff;
            if (uVar15 < uVar9) {
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027958;
                uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
                uVar14 = *(uint *)(((1 << (puVar18[0x15] & 0x1f)) - 1U & uVar17) * 4 + puVar18[0x13]
                                  );
                uVar15 = uVar15 + 8;
                uVar9 = uVar14 >> 8 & 0xff;
                uVar16 = uVar16 - 1;
                _Src = (uint *)((int)_Src + 1);
              } while (uVar15 < uVar9);
            }
            uVar10 = uVar14 & 0xff;
            local_74 = uVar14;
            if ((uVar10 != 0) && ((uVar14 & 0xf0) == 0)) {
              local_74._2_2_ = (ushort)(uVar14 >> 0x10);
              uVar10 = *(uint *)(((((1 << (uVar10 + uVar9 & 0x1f)) - 1U & uVar17) >> (uVar9 & 0x1f))
                                 + (uint)local_74._2_2_) * 4 + puVar18[0x13]);
              uVar3 = uVar14 >> 8;
              uVar7 = uVar3 & 0xff;
              uVar9 = uVar10 >> 8 & 0xff;
              local_68 = uVar14;
              if (uVar15 < uVar9 + uVar7) {
                do {
                  uVar10 = 0;
                  if (uVar16 == 0) goto LAB_00027958;
                  uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
                  uVar10 = *(uint *)(((((1 << ((uVar14 & 0xff) + uVar7 & 0x1f)) - 1U & uVar17) >>
                                      (uVar3 & 0x1f)) + (uint)local_74._2_2_) * 4 + puVar18[0x13]);
                  uVar15 = uVar15 + 8;
                  uVar9 = uVar10 >> 8 & 0xff;
                  uVar16 = uVar16 - 1;
                  _Src = (uint *)((int)_Src + 1);
                } while (uVar15 < uVar9 + uVar7);
              }
              local_74 = uVar10;
              uVar10 = local_74 & 0xff;
              uVar17 = uVar17 >> (uVar3 & 0x1f);
              uVar15 = uVar15 - uVar7;
            }
            uVar17 = uVar17 >> (uVar9 & 0x1f);
            uVar15 = uVar15 - uVar9;
            puVar18[0x10] = local_74 >> 0x10;
            if (uVar10 == 0) {
              uVar9 = 0x17;
            }
            else {
              if ((uVar10 & 0x20) == 0) {
                if ((uVar10 & 0x40) == 0) {
                  puVar18[0x12] = uVar10 & 0xf;
                  *puVar18 = 0x13;
                  goto LAB_000285bc;
                }
                param_1[6] = (int)local_40;
                break;
              }
              uVar9 = 0xb;
            }
            goto LAB_00028ad0;
          }
          param_1[3] = (int)_Dst;
          param_1[4] = uVar19;
          *param_1 = (int)_Src;
          param_1[1] = uVar16;
          puVar18[0xe] = uVar17;
          puVar18[0xf] = uVar15;
          FUN_00029680(param_1,local_64);
          uVar19 = param_1[4];
          _Dst = (undefined1 *)param_1[3];
          _Src = (uint *)*param_1;
          uVar16 = param_1[1];
          uVar17 = puVar18[0xe];
          uVar15 = puVar18[0xf];
          local_6c = uVar19;
          goto LAB_00028ad4;
        case 0x285b8:
LAB_000285bc:
          uVar9 = puVar18[0x12];
          if (uVar9 != 0) {
            if (uVar15 < uVar9) {
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027958;
                uVar10 = uVar15 & 0x1f;
                uVar15 = uVar15 + 8;
                uVar16 = uVar16 - 1;
                uVar17 = ((uint)(byte)*_Src << uVar10) + uVar17;
                _Src = (uint *)((int)_Src + 1);
              } while (uVar15 < puVar18[0x12]);
            }
            puVar18[0x10] = ((1 << (uVar9 & 0x1f)) - 1U & uVar17) + puVar18[0x10];
            uVar17 = uVar17 >> (uVar9 & 0x1f);
            uVar15 = uVar15 - uVar9;
          }
          *puVar18 = 0x14;
          goto LAB_00028630;
        case 0x2862c:
LAB_00028630:
          uVar14 = *(uint *)(((1 << (puVar18[0x16] & 0x1f)) - 1U & uVar17) * 4 + puVar18[0x14]);
          uVar9 = uVar14 >> 8 & 0xff;
          if (uVar15 < uVar9) {
            do {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027958;
              uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
              uVar14 = *(uint *)(((1 << (puVar18[0x16] & 0x1f)) - 1U & uVar17) * 4 + puVar18[0x14]);
              uVar15 = uVar15 + 8;
              uVar9 = uVar14 >> 8 & 0xff;
              uVar16 = uVar16 - 1;
              _Src = (uint *)((int)_Src + 1);
            } while (uVar15 < uVar9);
          }
          uVar10 = uVar14 & 0xff;
          local_74 = uVar14;
          if ((uVar14 & 0xf0) == 0) {
            local_74._2_2_ = (ushort)(uVar14 >> 0x10);
            uVar10 = *(uint *)(((((1 << (uVar10 + uVar9 & 0x1f)) - 1U & uVar17) >> (uVar9 & 0x1f)) +
                               (uint)local_74._2_2_) * 4 + puVar18[0x14]);
            uVar3 = uVar14 >> 8;
            uVar7 = uVar3 & 0xff;
            uVar9 = uVar10 >> 8 & 0xff;
            local_68 = uVar14;
            if (uVar15 < uVar9 + uVar7) {
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027958;
                uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
                uVar10 = *(uint *)(((((1 << ((uVar14 & 0xff) + uVar7 & 0x1f)) - 1U & uVar17) >>
                                    (uVar3 & 0x1f)) + (uint)local_74._2_2_) * 4 + puVar18[0x14]);
                uVar15 = uVar15 + 8;
                uVar9 = uVar10 >> 8 & 0xff;
                uVar16 = uVar16 - 1;
                _Src = (uint *)((int)_Src + 1);
              } while (uVar15 < uVar9 + uVar7);
            }
            local_74 = uVar10;
            uVar10 = local_74 & 0xff;
            uVar17 = uVar17 >> (uVar3 & 0x1f);
            uVar15 = uVar15 - uVar7;
          }
          uVar17 = uVar17 >> (uVar9 & 0x1f);
          uVar15 = uVar15 - uVar9;
          if ((uVar10 & 0x40) != 0) {
            param_1[6] = (int)local_44;
            break;
          }
          puVar18[0x12] = uVar10 & 0xf;
          puVar18[0x11] = local_74 >> 0x10;
          *puVar18 = 0x15;
LAB_000287f4:
          uVar9 = puVar18[0x12];
          if (uVar9 != 0) {
            if (uVar15 < uVar9) {
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027958;
                uVar10 = uVar15 & 0x1f;
                uVar15 = uVar15 + 8;
                uVar16 = uVar16 - 1;
                uVar17 = ((uint)(byte)*_Src << uVar10) + uVar17;
                _Src = (uint *)((int)_Src + 1);
              } while (uVar15 < puVar18[0x12]);
            }
            puVar18[0x11] = ((1 << (uVar9 & 0x1f)) - 1U & uVar17) + puVar18[0x11];
            uVar17 = uVar17 >> (uVar9 & 0x1f);
            uVar15 = uVar15 - uVar9;
          }
          if ((puVar18[0xb] - uVar19) + local_64 < puVar18[0x11]) {
            param_1[6] = (int)local_48;
            break;
          }
          *puVar18 = 0x16;
switchD_00027330_caseD_28884:
          uVar10 = uVar16;
          if (uVar19 == 0) goto LAB_00027958;
          uVar9 = puVar18[0x11];
          if (local_64 - uVar19 < uVar9) {
            uVar9 = uVar9 - (local_64 - uVar19);
            uVar10 = puVar18[0xc];
            if (uVar10 < uVar9) {
              uVar9 = uVar9 - uVar10;
              puVar12 = (undefined1 *)((puVar18[0xd] + puVar18[10]) - uVar9);
            }
            else {
              puVar12 = (undefined1 *)((puVar18[0xd] - uVar9) + uVar10);
            }
            uVar10 = puVar18[0x10];
            if (uVar10 < uVar9) goto LAB_000288f8;
          }
          else {
            uVar10 = puVar18[0x10];
            puVar12 = _Dst + -uVar9;
LAB_000288f8:
            uVar9 = uVar10;
          }
          if (uVar19 < uVar9) {
            uVar9 = uVar19;
          }
          uVar19 = uVar19 - uVar9;
          puVar18[0x10] = uVar10 - uVar9;
          do {
            uVar2 = *puVar12;
            puVar12 = puVar12 + 1;
            *_Dst = uVar2;
            uVar9 = uVar9 - 1;
            _Dst = _Dst + 1;
          } while (uVar9 != 0);
          local_6c = uVar19;
          if (puVar18[0x10] != 0) goto LAB_00028ad4;
          uVar9 = 0x12;
          goto LAB_00028ad0;
        case 0x287f0:
          goto LAB_000287f4;
        case 0x28884:
          goto switchD_00027330_caseD_28884;
        case 0x28948:
          if (uVar19 != 0) {
            uVar19 = uVar19 - 1;
            *_Dst = (char)puVar18[0x10];
            _Dst = _Dst + 1;
            uVar9 = 0x12;
            local_6c = uVar19;
            goto LAB_00028ad0;
          }
          goto LAB_00027958;
        case 0x2896c:
          if (puVar18[2] != 0) {
            for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027958;
              uVar16 = uVar16 - 1;
              uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
              _Src = (uint *)((int)_Src + 1);
            }
            uVar10 = puVar18[7];
            uVar9 = local_64 - uVar19;
            param_1[5] = param_1[5] + uVar9;
            puVar18[7] = uVar10 + uVar9;
            if (uVar9 != 0) {
              puVar6 = (uint *)(_Dst + -uVar9);
              if (puVar18[4] == 0) {
                uVar9 = FUN_00028cd0(puVar18[6],(byte *)puVar6,uVar9);
              }
              else if (puVar6 == (uint *)0x0) {
                uVar9 = 0;
              }
              else {
                uVar9 = FUN_00026a90(puVar18[6],puVar6,uVar9);
              }
              puVar18[6] = uVar9;
              param_1[0xc] = uVar9;
            }
            uVar9 = uVar17;
            if (puVar18[4] == 0) {
              uVar9 = ((uVar17 & 0xff00) + uVar17 * 0x10000) * 0x100 + (uVar17 >> 8 & 0xff00) +
                      (uVar17 >> 0x18);
            }
            local_64 = uVar19;
            if (uVar9 != puVar18[6]) {
              param_1[6] = (int)local_4c;
              break;
            }
            uVar17 = 0;
            uVar15 = 0;
          }
          *puVar18 = 0x19;
        case 0x28a70:
          if ((puVar18[2] != 0) && (puVar18[4] != 0)) {
            for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027958;
              uVar16 = uVar16 - 1;
              uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
              _Src = (uint *)((int)_Src + 1);
            }
            if (uVar17 != puVar18[7]) {
              param_1[6] = (int)local_50;
              break;
            }
            uVar17 = 0;
            uVar15 = 0;
          }
          *puVar18 = 0x1a;
switchD_00027330_caseD_28b50:
          local_78 = 1;
          uVar10 = uVar16;
          goto LAB_00027958;
        case 0x28b50:
          goto switchD_00027330_caseD_28b50;
        case 0x28b5c:
          local_78 = -3;
LAB_00027958:
          uVar16 = local_64;
          puVar18[0xf] = uVar15;
          uVar15 = puVar18[10];
          param_1[3] = (int)_Dst;
          param_1[4] = local_6c;
          *param_1 = (int)_Src;
          param_1[1] = uVar10;
          puVar18[0xe] = uVar17;
          if (((uVar15 == 0) && ((0x17 < (int)*puVar18 || (local_64 == local_6c)))) ||
             (iVar5 = FUN_00027060((int)param_1,local_64), iVar5 == 0)) {
            iVar5 = local_2c - param_1[1];
            uVar17 = puVar18[7];
            uVar16 = uVar16 - param_1[4];
            param_1[2] = param_1[2] + iVar5;
            uVar15 = puVar18[2];
            param_1[5] = param_1[5] + uVar16;
            puVar18[7] = uVar17 + uVar16;
            if ((uVar15 != 0) && (uVar16 != 0)) {
              if (puVar18[4] == 0) {
                uVar15 = FUN_00028cd0(puVar18[6],(byte *)(param_1[3] - uVar16),uVar16);
              }
              else if ((uint *)(param_1[3] - uVar16) == (uint *)0x0) {
                uVar15 = 0;
              }
              else {
                uVar15 = FUN_00026a90(puVar18[6],(uint *)(param_1[3] - uVar16),uVar16);
              }
              puVar18[6] = uVar15;
              param_1[0xc] = uVar15;
            }
            iVar11 = 0x40;
            if (puVar18[1] == 0) {
              iVar11 = 0;
            }
            if (*puVar18 == 0xb) {
              iVar8 = 0x80;
            }
            else {
              iVar8 = 0;
            }
            param_1[0xb] = iVar8 + iVar11 + puVar18[0xf];
            if (iVar5 != 0) {
              return local_78;
            }
            if (uVar16 != 0) {
              return local_78;
            }
            if (local_78 != 0) {
              return local_78;
            }
            return -5;
          }
          *puVar18 = 0x1c;
LAB_00028c58:
          return -4;
        }
LAB_00028acc:
        uVar9 = 0x1b;
LAB_00028ad0:
        *puVar18 = uVar9;
LAB_00028ad4:
        uVar9 = *puVar18;
      } while (uVar9 < 0x1d);
    }
  }
  return -2;
}



/* 00028c88 FUN_00028c88 */

/* Boundary evidence: original MIPS .pdata 00028c88..00028cb3. Semantic name remains unreviewed. */

void FUN_00028c88(undefined4 param_1,int param_2,int param_3)

{
  malloc(param_2 * param_3);
  return;
}



/* 00028cb4 FUN_00028cb4 */

/* Boundary evidence: original MIPS .pdata 00028cb4..00028ccf. Semantic name remains unreviewed. */

void FUN_00028cb4(undefined4 param_1,void *param_2)

{
  free(param_2);
  return;
}



/* 00028cd0 FUN_00028cd0 */

uint FUN_00028cd0(uint param_1,byte *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  
  uVar13 = param_1 >> 0x10;
  uVar14 = param_1 & 0xffff;
  if (param_3 == 1) {
    uVar14 = *param_2 + uVar14;
    if (0xfff0 < uVar14) {
      uVar14 = uVar14 - 0xfff1;
    }
    uVar13 = uVar13 + uVar14;
    if (0xfff0 < uVar13) {
      uVar13 = uVar13 - 0xfff1;
    }
    return uVar13 << 0x10 | uVar14;
  }
  if (param_2 != (byte *)0x0) {
    if (0xf < param_3) {
      if (0x15af < param_3) {
        uVar19 = param_3 / 0x15b0;
        do {
          param_3 = param_3 - 0x15b0;
          iVar1 = 0x15b;
          do {
            iVar2 = *param_2 + uVar14;
            iVar3 = (uint)param_2[1] + iVar2;
            iVar8 = (uint)param_2[2] + iVar3;
            iVar15 = (uint)param_2[3] + iVar8;
            iVar4 = (uint)param_2[4] + iVar15;
            iVar9 = (uint)param_2[5] + iVar4;
            iVar16 = (uint)param_2[6] + iVar9;
            iVar5 = (uint)param_2[7] + iVar16;
            iVar10 = (uint)param_2[8] + iVar5;
            iVar17 = (uint)param_2[9] + iVar10;
            iVar6 = (uint)param_2[10] + iVar17;
            iVar11 = (uint)param_2[0xb] + iVar6;
            iVar18 = (uint)param_2[0xc] + iVar11;
            iVar7 = (uint)param_2[0xd] + iVar18;
            iVar12 = (uint)param_2[0xe] + iVar7;
            uVar14 = (uint)param_2[0xf] + iVar12;
            uVar13 = uVar13 + iVar2 + iVar3 + iVar8 + iVar15 + iVar4 + iVar9 + iVar16 + iVar5 +
                     iVar10 + iVar17 + iVar6 + iVar11 + iVar18 + iVar7 + iVar12 + uVar14;
            iVar1 = iVar1 + -1;
            param_2 = param_2 + 0x10;
          } while (iVar1 != 0);
          uVar19 = uVar19 - 1;
          uVar14 = uVar14 % 0xfff1;
          uVar13 = uVar13 % 0xfff1;
        } while (uVar19 != 0);
      }
      if (param_3 != 0) {
        if (0xf < param_3) {
          uVar19 = param_3 >> 4;
          do {
            iVar1 = *param_2 + uVar14;
            iVar2 = (uint)param_2[1] + iVar1;
            iVar7 = (uint)param_2[2] + iVar2;
            iVar12 = (uint)param_2[3] + iVar7;
            iVar3 = (uint)param_2[4] + iVar12;
            iVar8 = (uint)param_2[5] + iVar3;
            iVar15 = (uint)param_2[6] + iVar8;
            iVar4 = (uint)param_2[7] + iVar15;
            iVar9 = (uint)param_2[8] + iVar4;
            iVar16 = (uint)param_2[9] + iVar9;
            iVar5 = (uint)param_2[10] + iVar16;
            iVar10 = (uint)param_2[0xb] + iVar5;
            iVar17 = (uint)param_2[0xc] + iVar10;
            iVar6 = (uint)param_2[0xd] + iVar17;
            iVar11 = (uint)param_2[0xe] + iVar6;
            uVar14 = (uint)param_2[0xf] + iVar11;
            param_3 = param_3 - 0x10;
            uVar13 = uVar13 + iVar1 + iVar2 + iVar7 + iVar12 + iVar3 + iVar8 + iVar15 + iVar4 +
                     iVar9 + iVar16 + iVar5 + iVar10 + iVar17 + iVar6 + iVar11 + uVar14;
            uVar19 = uVar19 - 1;
            param_2 = param_2 + 0x10;
          } while (uVar19 != 0);
        }
        for (; param_3 != 0; param_3 = param_3 - 1) {
          uVar14 = *param_2 + uVar14;
          param_2 = param_2 + 1;
          uVar13 = uVar13 + uVar14;
        }
        uVar14 = uVar14 % 0xfff1;
        uVar13 = uVar13 % 0xfff1;
      }
      return uVar13 << 0x10 | uVar14;
    }
    for (; param_3 != 0; param_3 = param_3 - 1) {
      uVar14 = *param_2 + uVar14;
      param_2 = param_2 + 1;
      uVar13 = uVar13 + uVar14;
    }
    if (0xfff0 < uVar14) {
      uVar14 = uVar14 - 0xfff1;
    }
    return ((uVar13 / 0xfff1) * 0xf + uVar13) * 0x10000 | uVar14;
  }
  return 1;
}



/* 0002903c FUN_0002903c */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 0002903c..0002967f. Semantic name remains unreviewed. */

undefined4
FUN_0002903c(int param_1,ushort *param_2,uint param_3,int *param_4,uint *param_5,ushort *param_6)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  ushort uVar7;
  ushort *puVar8;
  uint uVar9;
  uint uVar10;
  short sVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  ushort *puVar20;
  uint uVar21;
  undefined4 local_80;
  ushort local_70 [32];
  uint local_30;
  
  local_30 = DAT_000372d4;
  puVar5 = local_70;
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    puVar20 = param_2;
    uVar1 = param_3;
  } while (puVar5 != local_70 + 0x10);
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    local_70[*puVar20] = local_70[*puVar20] + 1;
    puVar20 = puVar20 + 1;
  }
  uVar1 = 0xf;
  puVar5 = local_70 + 0xf;
  do {
    if (*puVar5 != 0) break;
    uVar1 = uVar1 - 1;
    puVar5 = puVar5 + -1;
  } while (uVar1 != 0);
  uVar17 = *param_5;
  if (uVar1 < *param_5) {
    uVar17 = uVar1;
  }
  if (uVar1 == 0) {
    *(undefined4 *)*param_4 = 0x140;
    iVar6 = *param_4;
    *param_4 = iVar6 + 4;
    *(undefined4 *)(iVar6 + 4) = 0x140;
    *param_4 = *param_4 + 4;
    *param_5 = 1;
    FUN_0002a0c4(local_30);
    uVar2 = 0;
  }
  else {
    uVar21 = 1;
    puVar5 = local_70 + 4;
    do {
      if (puVar5[-3] != 0) break;
      if (puVar5[-2] != 0) {
        uVar21 = uVar21 + 1;
        break;
      }
      if (puVar5[-1] != 0) {
        uVar21 = uVar21 + 2;
        break;
      }
      if (*puVar5 != 0) {
        uVar21 = uVar21 + 3;
        break;
      }
      if (puVar5[1] != 0) {
        uVar21 = uVar21 + 4;
        break;
      }
      uVar21 = uVar21 + 5;
      puVar5 = puVar5 + 5;
    } while (uVar21 < 0x10);
    if (uVar17 < uVar21) {
      uVar17 = uVar21;
    }
    iVar6 = 1;
    uVar9 = 1;
    puVar5 = local_70;
    do {
      puVar5 = puVar5 + 1;
      iVar6 = iVar6 * 2 - (uint)*puVar5;
      if (iVar6 < 0) goto LAB_00029644;
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x10);
    if ((iVar6 < 1) || ((param_1 != 0 && (uVar1 == 1)))) {
      local_70[0x11] = 0;
      uVar9 = 2;
      do {
        iVar6 = uVar9 + 2;
        sVar11 = *(short *)((int)local_70 + uVar9 + 0x20) + *(short *)((int)local_70 + uVar9);
        iVar18 = uVar9 + 0x24;
        *(short *)((int)local_70 + uVar9 + 0x22) = sVar11;
        uVar9 = uVar9 + 4;
        *(short *)((int)local_70 + iVar18) = *(short *)((int)local_70 + iVar6) + sVar11;
      } while (uVar9 < 0x1e);
      uVar9 = 0;
      puVar5 = param_2;
      if (param_3 != 0) {
        do {
          if (*puVar5 != 0) {
            param_6[local_70[*puVar5 + 0x10]] = (ushort)uVar9;
            local_70[*puVar5 + 0x10] = local_70[*puVar5 + 0x10] + 1;
          }
          uVar9 = uVar9 + 1;
          puVar5 = puVar5 + 1;
        } while (uVar9 < param_3);
      }
      if (param_1 == 0) {
        iVar6 = 0x13;
        puVar5 = param_6;
        puVar20 = param_6;
      }
      else if (param_1 == 1) {
        iVar6 = 0x100;
        puVar5 = (ushort *)0x354f6;
        puVar20 = (ushort *)0x35536;
      }
      else {
        iVar6 = -1;
        puVar5 = (ushort *)&DAT_00035778;
        puVar20 = (ushort *)&DAT_000357b8;
      }
      uVar3 = 1 << (uVar17 & 0x1f);
      iVar18 = *param_4;
      uVar16 = 0;
      uVar9 = 0;
      uVar19 = uVar3 - 1;
      uVar4 = uVar3;
      uVar10 = 0xffffffff;
      if ((param_1 != 1) || (uVar3 < 0x5b0)) {
LAB_00029398:
        do {
          uVar7 = *param_6;
          uVar13 = uVar21 - uVar9;
          if ((int)(uint)uVar7 < iVar6) {
            local_80 = (uVar13 & 0xff) << 8;
            local_80 = CONCAT22(uVar7,(ushort)local_80);
          }
          else if (iVar6 < (int)(uint)uVar7) {
            local_80 = CONCAT22(puVar5[*param_6],
                                (short)CONCAT31((uint3)uVar13,(char)puVar20[*param_6]));
          }
          else {
            local_80 = CONCAT31((uint3)uVar13 & 0xff,0x60);
          }
          iVar14 = 1 << (uVar13 & 0x1f);
          puVar12 = (undefined4 *)(((uVar16 >> (uVar9 & 0x1f)) + uVar4) * 4 + iVar18);
          uVar13 = uVar4;
          do {
            puVar12 = puVar12 + -iVar14;
            uVar13 = uVar13 - iVar14;
            *puVar12 = local_80;
          } while (uVar13 != 0);
          for (uVar13 = 1 << (uVar21 - 1 & 0x1f); (uVar13 & uVar16) != 0; uVar13 = uVar13 >> 1) {
          }
          if (uVar13 == 0) {
            uVar16 = 0;
          }
          else {
            uVar16 = (uVar13 - 1 & uVar16) + uVar13;
          }
          param_6 = param_6 + 1;
          uVar7 = local_70[uVar21] - 1;
          local_70[uVar21] = uVar7;
          if (uVar7 == 0) {
            if (uVar21 == uVar1) {
              local_80._0_2_ = CONCAT11((char)uVar21 - (char)uVar9,0x40);
              local_80 = (uint)(ushort)local_80;
              goto joined_r0x00029594;
            }
            uVar21 = (uint)param_2[*param_6];
          }
        } while ((uVar21 <= uVar17) || (uVar13 = uVar19 & uVar16, uVar13 == uVar10));
        if (uVar9 == 0) {
          uVar9 = uVar17;
        }
        uVar15 = uVar21 - uVar9;
        uVar10 = uVar9 + uVar15;
        iVar18 = uVar4 * 4 + iVar18;
        iVar14 = 1 << (uVar15 & 0x1f);
        if (uVar10 < uVar1) {
          puVar8 = local_70 + uVar10;
          do {
            uVar7 = *puVar8;
            if ((int)(iVar14 - (uint)uVar7) < 1) break;
            uVar10 = uVar10 + 1;
            uVar15 = uVar15 + 1;
            puVar8 = puVar8 + 1;
            iVar14 = (iVar14 - (uint)uVar7) * 2;
          } while (uVar10 < uVar1);
        }
        uVar4 = 1 << (uVar15 & 0x1f);
        uVar3 = uVar4 + uVar3;
        if ((param_1 != 1) || (uVar3 < 0x5b0)) {
          iVar14 = uVar13 * 4;
          *(char *)(iVar14 + *param_4) = (char)uVar15;
          *(char *)(iVar14 + *param_4 + 1) = (char)uVar17;
          *(short *)(iVar14 + *param_4 + 2) = (short)(iVar18 - *param_4 >> 2);
          uVar10 = uVar13;
          goto LAB_00029398;
        }
      }
      FUN_0002a0c4(local_30);
      uVar2 = 1;
    }
    else {
LAB_00029644:
      FUN_0002a0c4(local_30);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
joined_r0x00029594:
  if (uVar16 == 0) {
LAB_0002961c:
    *param_4 = uVar3 * 4 + *param_4;
    *param_5 = uVar17;
    FUN_0002a0c4(local_30);
    return 0;
  }
  if ((uVar9 != 0) && ((uVar19 & uVar16) != uVar10)) {
    iVar18 = *param_4;
    uVar9 = 0;
    local_80._0_2_ = CONCAT11((char)uVar17,(undefined1)local_80);
    local_80 = (uint)(ushort)local_80;
    uVar21 = uVar17;
  }
  *(uint *)((uVar16 >> (uVar9 & 0x1f)) * 4 + iVar18) = local_80;
  for (uVar1 = 1 << (uVar21 - 1 & 0x1f); (uVar1 & uVar16) != 0; uVar1 = uVar1 >> 1) {
  }
  if (uVar1 == 0) goto LAB_0002961c;
  uVar16 = (uVar1 - 1 & uVar16) + uVar1;
  goto joined_r0x00029594;
}



/* 00029680 FUN_00029680 */

/* Boundary evidence: original MIPS .pdata 00029680..00029c83. Semantic name remains unreviewed. */

void FUN_00029680(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  int iVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined4 *puVar21;
  byte *pbVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  ushort uStack_2e;
  
  pbVar5 = (byte *)(*param_1 + -1);
  iVar10 = param_1[4];
  puVar17 = (undefined1 *)(param_1[3] + -1);
  puVar21 = (undefined4 *)param_1[7];
  pbVar22 = pbVar5 + param_1[1] + -5;
  uVar6 = puVar21[0x15];
  uVar9 = puVar21[0x16];
  iVar23 = puVar21[10];
  uVar25 = puVar21[0xb];
  uVar4 = puVar21[0xc];
  iVar24 = puVar21[0xd];
  uVar1 = puVar21[0xe];
  uVar26 = puVar21[0xf];
  iVar3 = puVar21[0x13];
  iVar2 = puVar21[0x14];
  puVar18 = puVar17;
LAB_00029720:
  if (uVar26 < 0xf) {
    pbVar11 = pbVar5 + 1;
    pbVar5 = pbVar5 + 2;
    uVar1 = ((uint)*pbVar5 << (uVar26 + 8 & 0x1f)) + ((uint)*pbVar11 << (uVar26 & 0x1f)) + uVar1;
    uVar26 = uVar26 + 0x10;
  }
  uVar12 = *(uint *)(((1 << (uVar6 & 0x1f)) - 1U & uVar1) * 4 + iVar3);
  uVar1 = uVar1 >> (uVar12 >> 8 & 0x1f);
  uVar26 = uVar26 - (uVar12 >> 8 & 0xff);
  while ((uVar12 & 0xff) != 0) {
    uStack_2e = (ushort)(uVar12 >> 0x10);
    pbVar11 = pbVar5;
    if ((uVar12 & 0x10) != 0) {
      uVar7 = (uint)uStack_2e;
      uVar12 = uVar12 & 0xf;
      if (uVar12 != 0) {
        if (uVar26 < uVar12) {
          pbVar5 = pbVar5 + 1;
          uVar1 = ((uint)*pbVar5 << (uVar26 & 0x1f)) + uVar1;
          uVar26 = uVar26 + 8;
        }
        uVar7 = ((1 << uVar12) - 1U & uVar1) + uVar7;
        uVar1 = uVar1 >> uVar12;
        uVar26 = uVar26 - uVar12;
        pbVar11 = pbVar5;
      }
      if (uVar26 < 0xf) {
        pbVar5 = pbVar11 + 1;
        pbVar11 = pbVar11 + 2;
        uVar1 = ((uint)*pbVar11 << (uVar26 + 8 & 0x1f)) + ((uint)*pbVar5 << (uVar26 & 0x1f)) + uVar1
        ;
        uVar26 = uVar26 + 0x10;
      }
      uVar12 = *(uint *)(((1 << (uVar9 & 0x1f)) - 1U & uVar1) * 4 + iVar2);
      uVar1 = uVar1 >> (uVar12 >> 8 & 0x1f);
      uVar26 = uVar26 - (uVar12 >> 8 & 0xff);
      goto joined_r0x000298cc;
    }
    if ((uVar12 & 0x40) != 0) {
      if ((uVar12 & 0x20) != 0) {
        *puVar21 = 0xb;
        goto LAB_00029be0;
      }
      pcVar8 = "invalid literal/length code";
      *puVar21 = 0x1b;
      goto LAB_00029bdc;
    }
    uVar12 = *(uint *)((((1 << (uVar12 & 0x1f)) - 1U & uVar1) + (uint)uStack_2e) * 4 + iVar3);
    uVar1 = uVar1 >> (uVar12 >> 8 & 0x1f);
    uVar26 = uVar26 - (uVar12 >> 8 & 0xff);
  }
  puVar18[1] = (char)(uVar12 >> 0x10);
  puVar19 = puVar18 + 1;
  goto LAB_000297fc;
joined_r0x000298cc:
  if ((uVar12 & 0x10) != 0) goto LAB_00029930;
  if ((uVar12 & 0x40) != 0) {
    param_1[6] = (int)"invalid distance code";
    *puVar21 = 0x1b;
    goto LAB_00029be0;
  }
  uVar12 = *(uint *)((((1 << (uVar12 & 0x1f)) - 1U & uVar1) + (uVar12 >> 0x10)) * 4 + iVar2);
  uVar1 = uVar1 >> (uVar12 >> 8 & 0x1f);
  uVar26 = uVar26 - (uVar12 >> 8 & 0xff);
  goto joined_r0x000298cc;
LAB_00029930:
  uVar13 = uVar12 & 0xf;
  pbVar5 = pbVar11;
  uVar27 = uVar26;
  if (uVar26 < uVar13) {
    pbVar5 = pbVar11 + 1;
    uVar27 = uVar26 + 8;
    uVar1 = ((uint)*pbVar5 << (uVar26 & 0x1f)) + uVar1;
    if (uVar27 < uVar13) {
      pbVar5 = pbVar11 + 2;
      uVar1 = ((uint)*pbVar5 << (uVar27 & 0x1f)) + uVar1;
      uVar27 = uVar26 + 0x10;
    }
  }
  uVar12 = ((1 << uVar13) - 1U & uVar1) + (uVar12 >> 0x10);
  uVar1 = uVar1 >> uVar13;
  uVar26 = uVar27 - uVar13;
  if (uVar12 <= (uint)((int)puVar18 - (int)(puVar17 + (iVar10 - param_2)))) {
    puVar15 = puVar18 + -uVar12;
    do {
      puVar20 = puVar18;
      puVar14 = puVar15;
      puVar20[1] = puVar14[1];
      puVar20[2] = puVar14[2];
      puVar19 = puVar20 + 3;
      uVar7 = uVar7 - 3;
      *puVar19 = puVar14[3];
      puVar15 = puVar14 + 3;
      puVar18 = puVar19;
    } while (2 < uVar7);
    if (uVar7 != 0) {
      puVar19 = puVar20 + 4;
      *puVar19 = puVar14[4];
      if (1 < uVar7) {
        puVar19 = puVar20 + 5;
        *puVar19 = puVar14[5];
      }
    }
    goto LAB_000297fc;
  }
  uVar27 = uVar12 - ((int)puVar18 - (int)(puVar17 + (iVar10 - param_2)));
  if (uVar25 < uVar27) {
    pcVar8 = "invalid distance too far back";
    *puVar21 = 0x1b;
LAB_00029bdc:
    param_1[6] = (int)pcVar8;
    pbVar11 = pbVar5;
LAB_00029be0:
    uVar4 = uVar26 + (uVar26 >> 3) * -8;
    *param_1 = (int)(pbVar11 + -(uVar26 >> 3) + 1);
    param_1[3] = (int)(puVar18 + 1);
    param_1[1] = (int)(pbVar22 + (5 - (int)(pbVar11 + -(uVar26 >> 3))));
    param_1[4] = (int)(puVar17 + iVar10 + -0x101 + (0x101 - (int)puVar18));
    puVar21[0xe] = (1 << (uVar4 & 0x1f)) - 1U & uVar1;
    puVar21[0xf] = uVar4;
    return;
  }
  puVar15 = (undefined1 *)(iVar24 + -1);
  if (uVar4 == 0) {
    puVar14 = puVar15 + (iVar23 - uVar27);
    if (uVar27 < uVar7) {
      uVar7 = uVar7 - uVar27;
      do {
        puVar14 = puVar14 + 1;
        puVar18 = puVar18 + 1;
        uVar27 = uVar27 - 1;
        *puVar18 = *puVar14;
      } while (uVar27 != 0);
LAB_00029a88:
      puVar14 = puVar18 + -uVar12;
    }
  }
  else if (uVar4 < uVar27) {
    uVar13 = uVar27 - uVar4;
    puVar14 = puVar15 + iVar23 + (uVar4 - uVar27);
    if (uVar13 < uVar7) {
      uVar7 = uVar7 - uVar13;
      do {
        puVar14 = puVar14 + 1;
        puVar18 = puVar18 + 1;
        uVar13 = uVar13 - 1;
        *puVar18 = *puVar14;
      } while (uVar13 != 0);
      puVar14 = puVar15;
      if (uVar4 < uVar7) {
        uVar7 = uVar7 - uVar4;
        uVar27 = uVar4;
        do {
          puVar15 = puVar15 + 1;
          puVar18 = puVar18 + 1;
          uVar27 = uVar27 - 1;
          *puVar18 = *puVar15;
        } while (uVar27 != 0);
        goto LAB_00029a88;
      }
    }
  }
  else {
    puVar14 = puVar15 + (uVar4 - uVar27);
    if (uVar27 < uVar7) {
      uVar7 = uVar7 - uVar27;
      do {
        puVar14 = puVar14 + 1;
        puVar18 = puVar18 + 1;
        uVar27 = uVar27 - 1;
        *puVar18 = *puVar14;
      } while (uVar27 != 0);
      goto LAB_00029a88;
    }
  }
  if (2 < uVar7) {
    iVar16 = (uVar7 - 3) / 3 + 1;
    do {
      puVar15 = puVar14 + 2;
      puVar18[1] = puVar14[1];
      puVar14 = puVar14 + 3;
      puVar18[2] = *puVar15;
      puVar18 = puVar18 + 3;
      uVar7 = uVar7 - 3;
      iVar16 = iVar16 + -1;
      *puVar18 = *puVar14;
    } while (iVar16 != 0);
  }
  puVar19 = puVar18;
  if (uVar7 != 0) {
    puVar19 = puVar18 + 1;
    *puVar19 = puVar14[1];
    if (1 < uVar7) {
      puVar19 = puVar18 + 2;
      *puVar19 = puVar14[2];
    }
  }
LAB_000297fc:
  pbVar11 = pbVar5;
  puVar18 = puVar19;
  if ((pbVar22 <= pbVar5) || (puVar17 + iVar10 + -0x101 <= puVar19)) goto LAB_00029be0;
  goto LAB_00029720;
}



/* 0002a0c4 FUN_0002a0c4 */

/* Boundary evidence: original MIPS .pdata 0002a0c4..0002a10b. Semantic name remains unreviewed. */

void FUN_0002a0c4(uint param_1)

{
  if ((param_1 == DAT_000372d4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 0002a17c FUN_0002a17c */

/* Boundary evidence: original MIPS .pdata 0002a17c..0002a287. Semantic name remains unreviewed. */

undefined4 FUN_0002a17c(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_0003947c;
  puVar3 = DAT_00039478;
  iVar4 = (int)DAT_00039478 - (int)DAT_0003947c;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_0002a1c0:
    param_1 = 0;
  }
  else {
    if (DAT_0003947c != (void *)0x0) {
      uVar1 = _msize(DAT_0003947c);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_0002a234:
        if (pvVar2 == (void *)0x0) goto LAB_0002a1c0;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_0002a234;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_00039478 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_0003947c = pvVar2;
  }
  return param_1;
}



/* 0002a288 FUN_0002a288 */

/* Boundary evidence: original MIPS .pdata 0002a288..0002a373. Semantic name remains unreviewed. */

undefined4 FUN_0002a288(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_00039480 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_00039480,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_00039480 == (LPCRITICAL_SECTION)0x0) goto LAB_0002a32c;
  }
  EnterCriticalSection(DAT_00039480);
LAB_0002a32c:
  uVar2 = FUN_0002a17c(param_1);
  FUN_0002a374();
  return uVar2;
}



/* 0002a374 FUN_0002a374 */

/* Boundary evidence: original MIPS .pdata 0002a374..0002a3bf. Semantic name remains unreviewed. */

void FUN_0002a374(void)

{
  if (DAT_00039480 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_00039480);
  }
  return;
}



/* 0002a3c0 FUN_0002a3c0 */

/* Boundary evidence: original MIPS .pdata 0002a3c0..0002a3ef. Semantic name remains unreviewed. */

undefined4 FUN_0002a3c0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0002a288(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0002a480 FUN_0002a480 */

/* Boundary evidence: original MIPS .pdata 0002a480..0002a513. Semantic name remains unreviewed. */

void FUN_0002a480(HINSTANCE param_1)

{
  WPARAM WVar1;
  
  FUN_0002a854();
  WVar1 = FUN_000138d8(param_1);
  FUN_0002a794(WVar1);
  FUN_0002a7b4(WVar1);
  return;
}



/* 0002a514 FUN_0002a514 */

/* Boundary evidence: original MIPS .pdata 0002a514..0002a553. Semantic name remains unreviewed. */

void FUN_0002a514(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 0002a554 entry */

/* Boundary evidence: original MIPS .pdata 0002a554..0002a5af. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1)

{
  FUN_0002a5c0();
  FUN_0002a480(param_1);
  return;
}



/* 0002a5c0 FUN_0002a5c0 */

/* Boundary evidence: original MIPS .pdata 0002a5c0..0002a633. Semantic name remains unreviewed. */

void FUN_0002a5c0(void)

{
  uint uVar1;
  
  if ((DAT_000372d4 == 0) || (DAT_000372d4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000372d4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000372d4 == 0) {
      DAT_000372d4 = 0xb064;
    }
  }
  DAT_000372d8 = ~DAT_000372d4;
  return;
}



/* 0002a674 FUN_0002a674 */

/* Boundary evidence: original MIPS .pdata 0002a674..0002a793. Semantic name remains unreviewed. */

void FUN_0002a674(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00037628 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_0003947c;
    if (DAT_0003947c != (undefined4 *)0x0) {
      while (DAT_00039478 = DAT_00039478 + -1, _Memory <= DAT_00039478) {
        if ((code *)*DAT_00039478 != (code *)0x0) {
          (*(code *)*DAT_00039478)();
          _Memory = DAT_0003947c;
        }
      }
      free(_Memory);
      DAT_00039478 = (undefined4 *)0x0;
      DAT_0003947c = (undefined4 *)0x0;
    }
    FUN_0002a800((undefined4 *)&DAT_0002c034,(undefined4 *)&DAT_0002c038);
  }
  FUN_0002a800((undefined4 *)&DAT_0002c03c,(undefined4 *)&DAT_0002c040);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_00039480,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 0002a794 FUN_0002a794 */

/* Boundary evidence: original MIPS .pdata 0002a794..0002a7b3. Semantic name remains unreviewed. */

void FUN_0002a794(UINT param_1)

{
  FUN_0002a674(param_1,0,0);
  return;
}



/* 0002a7b4 FUN_0002a7b4 */

/* Boundary evidence: original MIPS .pdata 0002a7b4..0002a7ff. Semantic name remains unreviewed. */

void FUN_0002a7b4(UINT param_1)

{
  DAT_00037628 = 0;
  FUN_0002a800((undefined4 *)&DAT_0002c03c,(undefined4 *)&DAT_0002c040);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 0002a800 FUN_0002a800 */

/* Boundary evidence: original MIPS .pdata 0002a800..0002a853. Semantic name remains unreviewed. */

void FUN_0002a800(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 0002a854 FUN_0002a854 */

/* Boundary evidence: original MIPS .pdata 0002a854..0002a88f. Semantic name remains unreviewed. */

void FUN_0002a854(void)

{
  FUN_0002a800((undefined4 *)&DAT_0002c02c,(undefined4 *)&DAT_0002c030);
  FUN_0002a800((undefined4 *)&DAT_0002c000,(undefined4 *)&DAT_0002c028);
  return;
}



/* 0002a8a0 FUN_0002a8a0 */

/* Boundary evidence: original MIPS .pdata 0002a8a0..0002a8c3. Semantic name remains unreviewed. */

void FUN_0002a8a0(int param_1,SIZE_T param_2)

{
  HeapAlloc(*(HANDLE *)(param_1 + 4),0,param_2);
  return;
}



/* 0002a8c4 FUN_0002a8c4 */

/* Boundary evidence: original MIPS .pdata 0002a8c4..0002a8ef. Semantic name remains unreviewed. */

void FUN_0002a8c4(int param_1,LPVOID param_2)

{
  if (param_2 != (LPVOID)0x0) {
    HeapFree(*(HANDLE *)(param_1 + 4),0,param_2);
  }
  return;
}



/* 0002a8f0 FUN_0002a8f0 */

/* Boundary evidence: original MIPS .pdata 0002a8f0..0002a957. Semantic name remains unreviewed. */

LPVOID FUN_0002a8f0(int *param_1,LPVOID param_2,SIZE_T param_3)

{
  LPVOID pvVar1;
  
  if (param_2 == (LPVOID)0x0) {
    pvVar1 = (LPVOID)(**(code **)*param_1)(param_1,param_3);
  }
  else if (param_3 == 0) {
    (**(code **)(*param_1 + 4))();
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = HeapReAlloc((HANDLE)param_1[1],0,param_2,param_3);
  }
  return pvVar1;
}



/* 0002a958 FUN_0002a958 */

/* Boundary evidence: original MIPS .pdata 0002a958..0002a97b. Semantic name remains unreviewed. */

void FUN_0002a958(int param_1,LPCVOID param_2)

{
  HeapSize(*(HANDLE *)(param_1 + 4),0,param_2);
  return;
}



/* 0002a97c FUN_0002a97c */

/* Boundary evidence: original MIPS .pdata 0002a97c..0002a9e7. Semantic name remains unreviewed. */

undefined4 * FUN_0002a97c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002c06c;
  if ((*(char *)(param_1 + 2) != '\0') && ((HANDLE)param_1[1] != (HANDLE)0x0)) {
    HeapDestroy((HANDLE)param_1[1]);
  }
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0002a9e8 FUN_0002a9e8 */

/* Boundary evidence: original MIPS .pdata 0002a9e8..0002aa0f. Semantic name remains unreviewed. */

void FUN_0002a9e8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 4))();
  return;
}



/* 0002aa10 FUN_0002aa10 */

/* Boundary evidence: original MIPS .pdata 0002aa10..0002aa3b. Semantic name remains unreviewed. */

int FUN_0002aa10(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return param_1 + 8;
}



/* 0002aa3c FUN_0002aa3c */

undefined4 FUN_0002aa3c(undefined4 param_1)

{
  return param_1;
}



/* 0002aa44 FUN_0002aa44 */

/* Boundary evidence: original MIPS .pdata 0002aa44..0002aa87. Semantic name remains unreviewed. */

undefined4 * FUN_0002aa44(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002c080;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0002aa88 FUN_0002aa88 */

/* Boundary evidence: original MIPS .pdata 0002aa88..0002ab1b. Semantic name remains unreviewed. */

int * FUN_0002aa88(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int *piVar3;
  uint uVar4;
  longlong lVar2;
  
  uVar4 = param_2 + 8U & 0xfffffff8;
  lVar2 = (ulonglong)uVar4 * (ulonglong)param_3;
  uVar1 = (uint)lVar2;
  if ((((int)((ulonglong)lVar2 >> 0x20) == 0) && (uVar1 < 0xfffffff0)) &&
     (piVar3 = (int *)(**(code **)**(undefined4 **)(param_1 + 4))
                                (*(undefined4 **)(param_1 + 4),uVar1 + 0x10), piVar3 != (int *)0x0))
  {
    piVar3[3] = 1;
    *piVar3 = param_1;
    piVar3[2] = uVar4 - 1;
    piVar3[1] = 0;
  }
  else {
    piVar3 = (int *)0x0;
  }
  return piVar3;
}



/* 0002ab1c FUN_0002ab1c */

/* Boundary evidence: original MIPS .pdata 0002ab1c..0002ab93. Semantic name remains unreviewed. */

int FUN_0002ab1c(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar3;
  uint uVar4;
  longlong lVar2;
  
  uVar4 = param_3 + 8U & 0xfffffff8;
  lVar2 = (ulonglong)uVar4 * (ulonglong)param_4;
  uVar1 = (uint)lVar2;
  if ((((int)((ulonglong)lVar2 >> 0x20) == 0) && (uVar1 < 0xfffffff0)) &&
     (iVar3 = (**(code **)(**(int **)(param_1 + 4) + 8))
                        (*(int **)(param_1 + 4),param_2,uVar1 + 0x10), iVar3 != 0)) {
    *(uint *)(iVar3 + 8) = uVar4 - 1;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



/* 0002ab94 FUN_0002ab94 */

/* Boundary evidence: original MIPS .pdata 0002ab94..0002abf3. Semantic name remains unreviewed. */

void FUN_0002ab94(void)

{
  undefined1 auStack_50 [32];
  undefined **appuStack_30 [10];
  
  FUN_00022eb8((int)auStack_50,"string too long");
  FUN_0001f624(appuStack_30,auStack_50);
                    /* WARNING: Subroutine does not return */
  appuStack_30[0] = std::length_error::vftable;
  __CxxThrowException(appuStack_30,(ThrowInfo *)&DAT_0003639c);
}



/* 0002abf4 Unwind@0002abf4 */

/* Boundary evidence: original MIPS .pdata 0002abf4..0002ac23. Semantic name remains unreviewed. */

void Unwind_0002abf4(void)

{
  int in_v0;
  
  FUN_00021b0c(in_v0 + -0x50);
  return;
}



/* 0002ac24 FUN_0002ac24 */

/* Boundary evidence: original MIPS .pdata 0002ac24..0002ac83. Semantic name remains unreviewed. */

void FUN_0002ac24(void)

{
  undefined1 auStack_50 [32];
  undefined **appuStack_30 [10];
  
  FUN_00022eb8((int)auStack_50,"invalid string position");
  FUN_0001f624(appuStack_30,auStack_50);
                    /* WARNING: Subroutine does not return */
  appuStack_30[0] = std::out_of_range::vftable;
  __CxxThrowException(appuStack_30,(ThrowInfo *)&DAT_000363d8);
}



/* 0002ac84 Unwind@0002ac84 */

/* Boundary evidence: original MIPS .pdata 0002ac84..0002acb3. Semantic name remains unreviewed. */

void Unwind_0002ac84(void)

{
  int in_v0;
  
  FUN_00021b0c(in_v0 + -0x50);
  return;
}



/* 0002acb4 FUN_0002acb4 */

/* Boundary evidence: original MIPS .pdata 0002acb4..0002accf. Semantic name remains unreviewed. */

void FUN_0002acb4(void)

{
  __2_YAPAXI_Z();
  return;
}



/* 0002af00 FUN_0002af00 */

/* Boundary evidence: original MIPS .pdata 0002af00..0002af2b. Semantic name remains unreviewed. */

void FUN_0002af00(void)

{
  FUN_0002af60();
  return;
}



/* 0002af2c FUN_0002af2c */

/* Boundary evidence: original MIPS .pdata 0002af2c..0002af5f. Semantic name remains unreviewed. */

void FUN_0002af2c(void)

{
  RaiseException(0xc000000d,0,0,(ULONG_PTR *)0x0);
  return;
}



/* 0002af60 FUN_0002af60 */

/* Boundary evidence: original MIPS .pdata 0002af60..0002af7f. Semantic name remains unreviewed. */

void FUN_0002af60(void)

{
  FUN_0002af2c();
  return;
}



/* 0002af80 FUN_0002af80 */

/* Boundary evidence: original MIPS .pdata 0002af80..0002b007. Semantic name remains unreviewed. */

int FUN_0002af80(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == 1) {
    if (DAT_00037674 == (code *)0x0) {
      DAT_0003763c = param_1;
      return 1;
    }
    iVar3 = (*DAT_00037674)(param_1,1);
    uVar2 = param_1;
    uVar1 = DAT_0003763c;
  }
  else {
    if (param_2 != 0) {
      return 1;
    }
    if (DAT_00037674 == (code *)0x0) {
      return 1;
    }
    iVar3 = (*DAT_00037674)(param_1,0);
    uVar2 = DAT_0003763c;
    uVar1 = DAT_0003763c;
  }
  DAT_0003763c = uVar2;
  if (iVar3 == 0) {
    iVar3 = 0;
    DAT_0003763c = uVar1;
  }
  return iVar3;
}



/* 0002b008 FUN_0002b008 */

/* Boundary evidence: original MIPS .pdata 0002b008..0002b05f. Semantic name remains unreviewed. */

void FUN_0002b008(LPCRITICAL_SECTION param_1)

{
  InitializeCriticalSection(param_1);
  return;
}



/* 0002b060 FUN_0002b060 */

/* Boundary evidence: original MIPS .pdata 0002b060..0002b087. Semantic name remains unreviewed. */

bool FUN_0002b060(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3fffffe9;
}



/* 0002b088 FUN_0002b088 */

/* Boundary evidence: original MIPS .pdata 0002b088..0002b0e3. Semantic name remains unreviewed. */

int FUN_0002b088(int *param_1,int param_2)

{
  int iVar1;
  int extraout_v0;
  
  if ((param_2 < 0) || (param_1[1] <= param_2)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar1 = extraout_v0;
  }
  else {
    iVar1 = param_2 * 4 + *param_1;
  }
  return iVar1;
}



/* 0002b0e4 FUN_0002b0e4 */

/* Boundary evidence: original MIPS .pdata 0002b0e4..0002b12b. Semantic name remains unreviewed. */

void FUN_0002b0e4(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  if (*(void **)(param_1 + 0x28) != (void *)0x0) {
    free(*(void **)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}



/* 0002b12c FUN_0002b12c */

/* Boundary evidence: original MIPS .pdata 0002b12c..0002b1c3. Semantic name remains unreviewed. */

undefined4 FUN_0002b12c(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x14);
  EnterCriticalSection(lpCriticalSection);
  if ((*(int *)(param_1 + 0x2c) < param_2) || (param_2 < 0)) {
    LeaveCriticalSection(lpCriticalSection);
    uVar2 = 0;
  }
  else {
    if (param_2 == *(int *)(param_1 + 0x2c)) {
      uVar2 = *(undefined4 *)(param_1 + 8);
    }
    else {
      puVar1 = (undefined4 *)FUN_0002b088((int *)(param_1 + 0x28),param_2);
      uVar2 = *puVar1;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar2;
}



/* 0002b1c4 FUN_0002b1c4 */

/* Boundary evidence: original MIPS .pdata 0002b1c4..0002b26f. Semantic name remains unreviewed. */

undefined4 * FUN_0002b1c4(undefined4 *param_1)

{
  HMODULE pHVar1;
  int iVar2;
  
  memset((LPCRITICAL_SECTION)(param_1 + 5),0,0x14);
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  *param_1 = 0x34;
  pHVar1 = DAT_0003763c;
  if (DAT_0003763c == (HMODULE)0x0) {
    pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  }
  param_1[3] = 0x900;
  param_1[2] = pHVar1;
  param_1[1] = pHVar1;
  param_1[4] = &DAT_0002c170;
  iVar2 = FUN_0002b008((LPCRITICAL_SECTION)(param_1 + 5));
  if (iVar2 < 0) {
    DAT_00037678 = 1;
  }
  return param_1;
}



/* 0002b290 FUN_0002b290 */

/* Boundary evidence: original MIPS .pdata 0002b290..0002b2e3. Semantic name remains unreviewed. */

void FUN_0002b290(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_0002a0c4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 0002b2e4 FUN_0002b2e4 */

/* Boundary evidence: original MIPS .pdata 0002b2e4..0002b30f. Semantic name remains unreviewed. */

undefined4 FUN_0002b2e4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0002b290(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 0002b3b0 FUN_0002b3b0 */

/* Boundary evidence: original MIPS .pdata 0002b3b0..0002b41f. Semantic name remains unreviewed. */

void FUN_0002b3b0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0002b290(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 0002b430 FUN_0002b430 */

/* Boundary evidence: original MIPS .pdata 0002b430..0002b457. Semantic name remains unreviewed. */

void FUN_0002b430(void)

{
  DAT_00038b34 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0002b458 FUN_0002b458 */

/* Boundary evidence: original MIPS .pdata 0002b458..0002b47f. Semantic name remains unreviewed. */

void FUN_0002b458(void)

{
  DAT_00038b38 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0002b480 FUN_0002b480 */

/* Boundary evidence: original MIPS .pdata 0002b480..0002b4a7. Semantic name remains unreviewed. */

void FUN_0002b480(void)

{
  DAT_00038b3c = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0002b4a8 FUN_0002b4a8 */

/* Boundary evidence: original MIPS .pdata 0002b4a8..0002b4cf. Semantic name remains unreviewed. */

void FUN_0002b4a8(void)

{
  DAT_00038b40 = RegisterWindowMessageW(L"Format Partition Disk!!!");
  return;
}



/* 0002b4d0 FUN_0002b4d0 */

/* Boundary evidence: original MIPS .pdata 0002b4d0..0002b4ef. Semantic name remains unreviewed. */

void FUN_0002b4d0(void)

{
  FUN_0002a3c0(&LAB_0002b5b0);
  return;
}



/* 0002b4f0 FUN_0002b4f0 */

/* Boundary evidence: original MIPS .pdata 0002b4f0..0002b51b. Semantic name remains unreviewed. */

void FUN_0002b4f0(void)

{
  FUN_00011448();
  FUN_0002a3c0(FUN_0002b5c4);
  return;
}



/* 0002b51c FUN_0002b51c */

/* Boundary evidence: original MIPS .pdata 0002b51c..0002b563. Semantic name remains unreviewed. */

void FUN_0002b51c(void)

{
  DAT_00037630 = GetProcessHeap();
  DAT_0003762c = &PTR_FUN_0002c06c;
  DAT_00037634 = 0;
  FUN_0002a3c0(FUN_0002b5e4);
  return;
}



/* 0002b564 FUN_0002b564 */

/* Boundary evidence: original MIPS .pdata 0002b564..0002b583. Semantic name remains unreviewed. */

void FUN_0002b564(void)

{
  FUN_0002a3c0(&LAB_0002b62c);
  return;
}



/* 0002b584 FUN_0002b584 */

/* Boundary evidence: original MIPS .pdata 0002b584..0002b5af. Semantic name remains unreviewed. */

void FUN_0002b584(void)

{
  FUN_0002b1c4((undefined4 *)&DAT_00037640);
  FUN_0002a3c0(FUN_0002b640);
  return;
}



/* 0002b5c4 FUN_0002b5c4 */

/* Boundary evidence: original MIPS .pdata 0002b5c4..0002b5e3. Semantic name remains unreviewed. */

void FUN_0002b5c4(void)

{
  FUN_00011730(&DAT_00038b48);
  return;
}



/* 0002b5e4 FUN_0002b5e4 */

/* Boundary evidence: original MIPS .pdata 0002b5e4..0002b62b. Semantic name remains unreviewed. */

void FUN_0002b5e4(void)

{
  DAT_0003762c = &PTR_FUN_0002c06c;
  if ((DAT_00037634 != '\0') && (DAT_00037630 != (HANDLE)0x0)) {
    HeapDestroy(DAT_00037630);
  }
  return;
}



/* 0002b640 FUN_0002b640 */

/* Boundary evidence: original MIPS .pdata 0002b640..0002b65f. Semantic name remains unreviewed. */

void FUN_0002b640(void)

{
  FUN_0002b0e4(0x37640);
  return;
}


