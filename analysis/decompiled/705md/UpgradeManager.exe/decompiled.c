/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..00011043. Semantic name remains unreviewed. */

undefined4 * FUN_00011000(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002e89c;
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
  
  local_30 = DAT_000372d0;
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
    iVar2 = RequestDeviceNotifications(&DAT_0002e684,hHandle,1);
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
  FUN_0002a4f0(local_30);
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
  __CxxThrowException(local_10,(ThrowInfo *)&DAT_0003621c);
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
  
  DAT_00038f60 = &PTR_LAB_00034718;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00038f70);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00038f84);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00038f98);
  DAT_00038fac = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  DAT_00038fb0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_00038fb4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  DAT_00038fc4 = 0;
  DAT_00038fc8 = 0;
  DAT_00038fcc = 0;
  DAT_00038fd0 = 0;
  DAT_00038fd4 = 0;
  DAT_00038fd8 = 10;
  DAT_00038f64 = 0;
  DAT_00038f6c = 0;
  DAT_00038f68 = 0;
  DAT_00038fb8 = 0;
  DAT_00038fbc = 0;
  DAT_00038fc0 = 0;
  DAT_00038fdc = 0;
  EventModify(DAT_00038fb4,3);
  DAT_00038f60 = &PTR_FUN_0002e8ec;
  DAT_00038fe0 = &PTR_FUN_0002e8f4;
  FUN_0001ac38(&DAT_00038fe4);
  iVar1 = (**(code **)(PTR_PTR_000372d8 + 0xc))(&PTR_PTR_000372d8);
  DAT_000397f0 = iVar1 + 0x10;
  iVar1 = (**(code **)(PTR_PTR_000372d8 + 0xc))(&PTR_PTR_000372d8);
  DAT_000397f4 = iVar1 + 0x10;
  iVar1 = (**(code **)(PTR_PTR_000372d8 + 0xc))(&PTR_PTR_000372d8);
  DAT_00039850 = iVar1 + 0x10;
  memset(&DAT_00039800,0,0x48);
  DAT_00039848 = 0;
  DAT_0003984c = 0;
  FUN_0001246c(&DAT_00039850);
  DAT_00039854 = 0;
  DAT_00039858 = 0;
  DAT_0003985c = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00039860);
  DAT_000397f8 = 0;
  DAT_000397fc = 0;
  DAT_00039874 = 0;
  DAT_00039878 = 0;
  memset(&DAT_00039800,0,0x48);
  DAT_00039848 = 0;
  DAT_0003984c = 0;
  FUN_0001246c(&DAT_00039850);
  DAT_00039854 = 0;
  DAT_00039858 = 0;
  DAT_0003985c = 0;
  DAT_00039880 = 0;
  DAT_00039884 = 0;
  DAT_00039888 = 0;
  DAT_0003987c = 1;
  DAT_0003988c = 0;
  return &DAT_00038f60;
}



/* 0001166c Unwind@0001166c */

/* Boundary evidence: original MIPS .pdata 0001166c..0001169b. Semantic name remains unreviewed. */

void Unwind_0001166c(void)

{
  undefined4 *in_v0;
  
  FUN_0001afa8((undefined4 *)*in_v0);
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

/* Boundary evidence: original MIPS .pdata 00011730..0001186b. Semantic name remains unreviewed. */

void FUN_00011730(undefined4 *param_1)

{
  DWORD DVar1;
  LONG LVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  *param_1 = &PTR_FUN_0002e8ec;
  param_1[0x20] = &PTR_FUN_0002e8f4;
  if (((HANDLE)param_1[1] != (HANDLE)0x0) &&
     (DVar1 = WaitForSingleObject((HANDLE)param_1[1],0), DVar1 == 0x102)) {
    FUN_00012260((int)param_1);
  }
  if ((void *)param_1[0x24b] != (void *)0x0) {
    free((void *)param_1[0x24b]);
    param_1[0x24b] = 0;
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
  FUN_0001adac((int)(param_1 + 0x21));
  FUN_0001afa8(param_1);
  return;
}



/* 0001186c Unwind@0001186c */

/* Boundary evidence: original MIPS .pdata 0001186c..0001189b. Semantic name remains unreviewed. */

void Unwind_0001186c(void)

{
  undefined4 *in_v0;
  
  FUN_0001afa8((undefined4 *)*in_v0);
  return;
}



/* 0001189c FUN_0001189c */

/* Boundary evidence: original MIPS .pdata 0001189c..00011a3f. Semantic name remains unreviewed. */

int FUN_0001189c(undefined4 param_1,LPCWSTR param_2,void *param_3)

{
  DWORD DVar1;
  HANDLE hObject;
  size_t sVar2;
  int iVar3;
  uint local_20 [2];
  
  if ((DAT_00038f64 == (HANDLE)0x0) || (DVar1 = WaitForSingleObject(DAT_00038f64,0), DVar1 != 0x102)
     ) {
    memset(&DAT_00039800,0,0x48);
    DAT_00039848 = 0;
    DAT_0003984c = 0;
    FUN_0001246c(&DAT_00039850);
    DAT_00039854 = 0;
    DAT_00039858 = 0;
    DAT_0003985c = 0;
    (**(code **)(*DAT_000397dc + 0xc))();
    hObject = CreateFileW(param_2,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
    if (hObject == (HANDLE)0xffffffff) {
      GetLastError();
      iVar3 = 1;
    }
    else {
      CloseHandle(hObject);
      local_20[0] = 0;
      NKDbgPrintfW(L"[Upd Manager] [INFO]GetfileCRC (%s)\r\n",param_2);
      iVar3 = FUN_00011c50(0x38f60,param_2,local_20,0x400);
      if (iVar3 == 0) {
        iVar3 = 0xd;
      }
      else {
        iVar3 = FUN_0001ae4c((int *)&DAT_00038fe4,param_2);
        if (iVar3 == 0) {
          memcpy(param_3,&DAT_00038fe4,0x7f8);
        }
        if (param_2 == (LPCWSTR)0x0) {
          sVar2 = 0;
        }
        else {
          sVar2 = wcslen(param_2);
        }
        FUN_0001267c(&DAT_000397f0,param_2,sVar2);
      }
    }
  }
  else {
    iVar3 = 10;
  }
  return iVar3;
}



/* 00011a40 FUN_00011a40 */

/* Boundary evidence: original MIPS .pdata 00011a40..00011b83. Semantic name remains unreviewed. */

undefined4 FUN_00011a40(int param_1)

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
    if (*(int *)(param_1 + 0x920) == 0) goto LAB_00011b1c;
    pcVar4 = *(code **)(iVar3 + 0x28);
  }
  else {
    if (*(int *)(param_1 + 0x920) != 0) {
      iVar1 = (**(code **)(*piVar2 + 0x28))();
      goto LAB_00011ae0;
    }
    iVar3 = *piVar2;
LAB_00011b1c:
    pcVar4 = *(code **)(iVar3 + 0x44);
  }
  iVar1 = (*pcVar4)(piVar2,iVar1);
LAB_00011ae0:
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



/* 00011b84 FUN_00011b84 */

/* Boundary evidence: original MIPS .pdata 00011b84..00011c4f. Semantic name remains unreviewed. */

void FUN_00011b84(int param_1)

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



/* 00011c50 FUN_00011c50 */

/* Boundary evidence: original MIPS .pdata 00011c50..00011db7. Semantic name remains unreviewed. */

undefined4 FUN_00011c50(int param_1,LPCWSTR param_2,uint *param_3,LONG param_4)

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
      uVar4 = FUN_0001a900(uVar4,lpBuffer,local_28[0]);
      iVar2 = ReadFile(hFile,lpBuffer,0x20000,local_28,(LPOVERLAPPED)0x0);
    }
    CloseHandle(hFile);
    *param_3 = uVar4;
  }
  return uVar3;
}



/* 00011db8 FUN_00011db8 */

/* Boundary evidence: original MIPS .pdata 00011db8..00011f93. Semantic name remains unreviewed. */

void FUN_00011db8(int param_1,int param_2,LPCWSTR param_3,undefined4 *param_4,undefined4 *param_5)

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
  
  FUN_00011b84(param_1 + -0x80);
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
          lVar5 != *(longlong *)(param_2 + 8))))) goto LAB_00011f1c;
    }
    else {
      DVar2 = GetFileAttributesW(param_3);
      if ((((DVar2 == 0xffffffff) || ((DVar2 & 0x10) != 0)) ||
          (iVar3 = FUN_00011c50(param_1 + -0x80,param_3,&local_28,0), iVar3 == 0)) ||
         (local_28 != *(DWORD *)(param_2 + 0x28))) goto LAB_00011f1c;
    }
    *param_4 = 1;
  }
LAB_00011f1c:
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x880));
  _Str = *(wchar_t **)(param_2 + 4);
  if (_Str == (wchar_t *)0x0) {
    sVar4 = 0;
  }
  else {
    sVar4 = wcslen(_Str);
  }
  FUN_0001267c((int *)(param_1 + 0x870),_Str,sVar4);
  *(undefined4 *)(param_1 + 0x874) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_1 + 0x878) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x87c) = *(undefined4 *)(param_2 + 0x1c);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x880));
  return;
}



/* 00011f94 FUN_00011f94 */

/* Boundary evidence: original MIPS .pdata 00011f94..00012013. Semantic name remains unreviewed. */

void FUN_00011f94(int param_1,void *param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_00011b84(param_1 + -0x80);
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



/* 00012014 FUN_00012014 */

/* Boundary evidence: original MIPS .pdata 00012014..00012147. Semantic name remains unreviewed. */

void FUN_00012014(int param_1,void *param_2,int param_3)

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
    FUN_00012328((int *)&local_20,(int *)(param_1 + 0x814),(undefined4 *)(param_1 + 0x870));
    local_1c = 0;
    iVar1 = FUN_00011c50(param_1 + -0x80,local_20,&local_1c,0);
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



/* 00012148 FUN_00012148 */

/* Boundary evidence: original MIPS .pdata 00012148..0001225f. Semantic name remains unreviewed. */

void * FUN_00012148(void *param_1,void *param_2)

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
      FUN_0001267c(piVar6,pvVar4,*(int *)((int)pvVar4 + -0xc));
    }
    else {
      puVar1 = FUN_000127a0(piVar3);
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



/* 00012260 FUN_00012260 */

/* Boundary evidence: original MIPS .pdata 00012260..0001231b. Semantic name remains unreviewed. */

void FUN_00012260(int param_1)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
  pvVar2 = *(HANDLE *)(param_1 + 4);
  if ((pvVar2 != (HANDLE)0x0) && (DVar1 = WaitForSingleObject(pvVar2,0), DVar1 == 0x102)) {
    FUN_0001b0e4(param_1);
    pvVar2 = (HANDLE)InterlockedExchange((LONG *)(param_1 + 4),0);
    if (pvVar2 != (HANDLE)0x0) {
      WaitForSingleObject(pvVar2,0xffffffff);
      CloseHandle(pvVar2);
    }
  }
  return;
}



/* 00012328 FUN_00012328 */

/* Boundary evidence: original MIPS .pdata 00012328..0001241b. Semantic name remains unreviewed. */

int * FUN_00012328(int *param_1,int *param_2,undefined4 *param_3)

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
     (piVar1 = (int *)(**(code **)(PTR_PTR_000372d8 + 0x10))(&PTR_PTR_000372d8),
     piVar1 == (int *)0x0)) {
    piVar1 = (int *)FUN_00011314(0x80004005);
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1);
  *param_1 = iVar2 + 0x10;
  FUN_0001257c(param_1,(void *)*param_2,*(int *)(*param_2 + -0xc),(void *)*param_3,
               *(int *)((int)*param_3 + -0xc));
  return param_1;
}



/* 0001241c Unwind@0001241c */

/* Boundary evidence: original MIPS .pdata 0001241c..0001246b. Semantic name remains unreviewed. */

void Unwind_0001241c(void)

{
  undefined4 *in_v0;
  
  if ((in_v0[-8] & 1) != 0) {
    in_v0[-8] = in_v0[-8] & 0xfffffffe;
    FUN_00012534((int *)*in_v0);
  }
  return;
}



/* 0001246c FUN_0001246c */

/* Boundary evidence: original MIPS .pdata 0001246c..00012533. Semantic name remains unreviewed. */

void FUN_0001246c(int *param_1)

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



/* 00012534 FUN_00012534 */

/* Boundary evidence: original MIPS .pdata 00012534..0001257b. Semantic name remains unreviewed. */

void FUN_00012534(int *param_1)

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



/* 0001257c FUN_0001257c */

/* Boundary evidence: original MIPS .pdata 0001257c..0001267b. Semantic name remains unreviewed. */

void FUN_0001257c(int *param_1,void *param_2,int param_3,void *param_4,int param_5)

{
  rsize_t _DstSize;
  void *_Dst;
  int iVar1;
  
  iVar1 = param_3 + param_5;
  if ((int)(1U - *(int *)(*param_1 + -4) | *(int *)(*param_1 + -8) - iVar1) < 0) {
    FUN_0001288c(param_1,iVar1);
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



/* 0001267c FUN_0001267c */

/* Boundary evidence: original MIPS .pdata 0001267c..0001279f. Semantic name remains unreviewed. */

void FUN_0001267c(int *param_1,void *param_2,int param_3)

{
  void *_Dst;
  int iVar1;
  uint uVar2;
  rsize_t _MaxCount;
  uint uVar3;
  
  if (param_3 == 0) {
    FUN_0001246c(param_1);
  }
  else {
    if (param_2 == (void *)0x0) {
      FUN_00011314(0x80070057);
    }
    iVar1 = *param_1;
    uVar3 = (int)param_2 - iVar1 >> 1;
    uVar2 = *(uint *)(iVar1 + -0xc);
    if ((int)(1U - *(int *)(iVar1 + -4) | *(int *)(iVar1 + -8) - param_3) < 0) {
      FUN_0001288c(param_1,param_3);
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



/* 000127a0 FUN_000127a0 */

/* Boundary evidence: original MIPS .pdata 000127a0..0001286b. Semantic name remains unreviewed. */

undefined4 * FUN_000127a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  rsize_t _DstSize;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)*param_1 + 0x10))();
  if (((int)param_1[3] < 0) || (puVar1 != (undefined4 *)*param_1)) {
    puVar1 = (undefined4 *)(**(code **)*puVar1)(puVar1,param_1[1],2);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_0001286c();
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



/* 0001286c FUN_0001286c */

/* Boundary evidence: original MIPS .pdata 0001286c..0001288b. Semantic name remains unreviewed. */

void FUN_0001286c(void)

{
  FUN_00011314(0x8007000e);
  return;
}



/* 0001288c FUN_0001288c */

/* Boundary evidence: original MIPS .pdata 0001288c..0001291f. Semantic name remains unreviewed. */

void FUN_0001288c(int *param_1,int param_2)

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
      FUN_00012a04(param_1,iVar1);
    }
  }
  else {
    FUN_00012920(param_1,param_2);
  }
  return;
}



/* 00012920 FUN_00012920 */

/* Boundary evidence: original MIPS .pdata 00012920..00012a03. Semantic name remains unreviewed. */

void FUN_00012920(undefined4 *param_1,int param_2)

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
    FUN_0001286c();
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



/* 00012a04 FUN_00012a04 */

/* Boundary evidence: original MIPS .pdata 00012a04..00012a7f. Semantic name remains unreviewed. */

void FUN_00012a04(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(*param_1 + -0x10);
  piVar2 = (int *)*puVar3;
  if ((*(int *)(*param_1 + -8) < param_2) && (0 < param_2)) {
    iVar1 = (**(code **)(*piVar2 + 8))(piVar2,puVar3,param_2,2);
    if (iVar1 == 0) {
      iVar1 = FUN_0001286c();
    }
    *param_1 = iVar1 + 0x10;
  }
  else {
    FUN_0001286c();
  }
  return;
}



/* 00012a80 FUN_00012a80 */

/* Boundary evidence: original MIPS .pdata 00012a80..00012b4f. Semantic name remains unreviewed. */

PHKEY FUN_00012a80(PHKEY param_1,LPCWSTR param_2)

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



/* 00012b50 FUN_00012b50 */

/* Boundary evidence: original MIPS .pdata 00012b50..00012bf3. Semantic name remains unreviewed. */

undefined4 FUN_00012b50(void *param_1)

{
  HANDLE local_20;
  HANDLE local_1c;
  
  memcpy(&local_20,param_1,0x10);
  WaitForSingleObject(local_20,0xffffffff);
  NKDbgPrintfW(L"[Upd Manager]SyncTool.exe is terminated\r\n");
  CloseHandle(local_20);
  CloseHandle(local_1c);
  if (DAT_00038f2c != 0) {
    CloseHandle((HANDLE)DAT_00038f2c);
    DAT_00038f2c = 0;
  }
  return 0;
}



/* 00012bf4 FUN_00012bf4 */

/* Boundary evidence: original MIPS .pdata 00012bf4..00012d7f. Semantic name remains unreviewed. */

void FUN_00012bf4(void)

{
  DWORD DVar1;
  undefined1 local_30 [8];
  
  DAT_00038f3c = 0;
  do {
    DVar1 = WaitForSingleObject(DAT_00038f34,300000);
    if (DVar1 == 0) {
      DAT_00038f3c = 1;
      break;
    }
    if (DVar1 == 0x102) {
      if (DAT_00037854 != -1) {
        local_30[0] = 0;
        FUN_00016a6c(1,1,7,(int)local_30,1);
        NKDbgPrintfW(L"= In Monitor Thread =- COM2 close succeed!!!\r\n");
        if (DAT_00037854 != -1) {
          CloseHandle((HANDLE)DAT_00037854);
          DAT_00037854 = -1;
        }
      }
      DAT_00038f3c = 1;
    }
  } while (DAT_00038f3c == 0);
  DVar1 = GetTickCount();
  NKDbgPrintfW(L"***** [Upd Manager ] Thread_Monitor Ended ~~~ [%d] ****\r\n",DVar1);
  if (DAT_00038f34 != (HANDLE)0x0) {
    CloseHandle(DAT_00038f34);
    DAT_00038f34 = (HANDLE)0x0;
  }
  if (DAT_00038f38 != 0) {
    CloseHandle((HANDLE)DAT_00038f38);
    DAT_00038f38 = 0;
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00012d80 FUN_00012d80 */

/* Boundary evidence: original MIPS .pdata 00012d80..00012f8b. Semantic name remains unreviewed. */

void FUN_00012d80(undefined4 *param_1)

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
  iVar1 = FUN_00016b6c(1);
  if (iVar1 == 1) {
    NKDbgPrintfW(L"***** [Upd Manager ] DELAY 1500 ****\r\n");
  }
  iVar1 = FUN_00016b6c(2);
  if (iVar1 == 1) {
    NKDbgPrintfW(L"***** [Upd Manager ] Storage Card3 Mount error ~~~ ****\r\n");
  }
  DAT_00038f34 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_00038f38 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00012bf4,(LPVOID)0x0,4,(LPDWORD)0x0);
  if (DAT_00038f38 != (HANDLE)0x0) {
    CeSetThreadPriority(DAT_00038f38,0x58);
    ResumeThread(DAT_00038f38);
  }
  FUN_00014eb0();
  if (DAT_00038f34 != (HANDLE)0x0) {
    EventModify(DAT_00038f34,3);
  }
  memset(&_Stack_20,0,0x10);
  BVar2 = CreateProcessW(L"\\Storage Card\\system\\MicomManager.exe",L"er10q4c$=4G2g-H2tq9X@mid",
                         (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,
                         (LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,&_Stack_20);
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
  DAT_00037994 = 0x7e8;
  DAT_0003798c = hWnd;
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00011044,&PTR_PTR_00037988,0,(LPDWORD)0x0)
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



/* 00012f8c FUN_00012f8c */

/* Boundary evidence: original MIPS .pdata 00012f8c..0001335b. Semantic name remains unreviewed. */

undefined4 FUN_00012f8c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if ((((param_1 == 0) || (param_1 == 3)) || (param_1 == 6)) ||
     ((((param_1 == 9 || (param_1 == 10)) ||
       ((param_1 == 0xb || ((param_1 == 0x12 || (param_1 == 0x16)))))) ||
      (((param_1 == 0x1a ||
        ((((param_1 == 0x1e || (param_1 == 0x20)) || (param_1 == 0x22)) ||
         ((param_1 == 0x39 || (param_1 == 0x3d)))))) ||
       ((((param_1 == 0x41 || ((param_1 == 0x45 || (param_1 == 0x47)))) || (param_1 == 0x49)) ||
        (((((param_1 == 0x24 || (param_1 == 0x28)) || (param_1 == 0x2c)) ||
          ((param_1 == 0x30 || (param_1 == 0x33)))) || (param_1 == 0x36)))))))))) {
    uVar1 = 0;
  }
  else if (((((((param_1 == 0xc) || (param_1 == 0xd)) ||
              ((param_1 == 0xe || (((param_1 == 0xf || (param_1 == 0x10)) || (param_1 == 0x11))))))
             || ((param_1 == 0x13 || (param_1 == 0x17)))) ||
            ((param_1 == 0x1b ||
             (((param_1 == 0x1f || (param_1 == 0x21)) ||
              ((param_1 == 0x23 || (((param_1 == 0x3a || (param_1 == 0x3e)) || (param_1 == 0x42)))))
              ))))) || (((param_1 == 0x46 || (param_1 == 0x48)) || (param_1 == 0x4a)))) ||
          (((param_1 == 0x25 || (param_1 == 0x29)) ||
           ((param_1 == 0x2d || (((param_1 == 0x31 || (param_1 == 0x34)) || (param_1 == 0x37))))))))
  {
    uVar1 = 1;
  }
  else if (((param_1 == 1) || (param_1 == 4)) ||
          ((((param_1 == 7 || ((param_1 == 0x14 || (param_1 == 0x18)))) ||
            ((param_1 == 0x1c ||
             ((((param_1 == 0x3b || (param_1 == 0x3f)) || (param_1 == 0x43)) ||
              ((param_1 == 0x26 || (param_1 == 0x2a)))))))) || (param_1 == 0x2e)))) {
    uVar1 = 2;
  }
  else if (((((param_1 == 2) || (param_1 == 5)) ||
            ((param_1 == 8 || (((param_1 == 0x15 || (param_1 == 0x19)) || (param_1 == 0x1d)))))) ||
           ((param_1 == 0x3c || (param_1 == 0x40)))) ||
          ((param_1 == 0x44 ||
           (((param_1 == 0x27 || (param_1 == 0x2b)) ||
            ((param_1 == 0x2f || (((param_1 == 0x32 || (param_1 == 0x35)) || (param_1 == 0x38)))))))
           ))) {
    uVar1 = 3;
  }
  else {
    NKDbgPrintfW(L"[xxxxxxx] GetMapRegion() dwSkuRegion %d....Unknown !!!\r\n",param_1);
  }
  return uVar1;
}



/* 0001335c FUN_0001335c */

/* Boundary evidence: original MIPS .pdata 0001335c..000136bb. Semantic name remains unreviewed. */

undefined4 FUN_0001335c(void)

{
  PHKEY ppHVar1;
  LSTATUS LVar2;
  DWORD DVar3;
  int iVar4;
  wchar_t *pwVar5;
  undefined4 uVar6;
  int iVar7;
  int local_28 [4];
  
  uVar6 = 0xffffffff;
  iVar7 = -1;
  ppHVar1 = (PHKEY)__2_YAPAXI_Z(4);
  if (ppHVar1 == (PHKEY)0x0) {
    ppHVar1 = (PHKEY)0x0;
  }
  else {
    ppHVar1 = FUN_00012a80(ppHVar1,L"LGE\\SystemInfo");
  }
  if (ppHVar1 != (PHKEY)0x0) {
    if (*ppHVar1 != (HKEY)0x0) {
      local_28[0] = 0;
      local_28[1] = 4;
      LVar2 = RegQueryValueExW(*ppHVar1,L"SKU_REGION",(LPDWORD)0x0,(LPDWORD)(local_28 + 2),
                               (LPBYTE)local_28,(LPDWORD)(local_28 + 1));
      if ((LVar2 == 0) && (local_28[2] == 4)) {
        iVar7 = local_28[0];
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
          DVar3 = GetFileAttributesW(L"\\MD\\navigation_content_license.lgu");
          if (DVar3 == 0xffffffff) {
            iVar4 = FUN_00012f8c(iVar7);
            if (iVar4 == 0) {
              DVar3 = GetFileAttributesW(L"\\MD\\navigation_restore_weu.lgu");
              if (DVar3 == 0xffffffff) {
                DVar3 = GetFileAttributesW(L"\\MD\\navigation_content_license_weu.lgu");
                if (DVar3 != 0xffffffff) {
                  uVar6 = 9;
                }
              }
              else {
                uVar6 = 4;
              }
              pwVar5 = L"[WEU] dwSkuRegion %d....detected type [%d]!!!\r\n";
            }
            else {
              iVar4 = FUN_00012f8c(iVar7);
              if (iVar4 == 1) {
                DVar3 = GetFileAttributesW(L"\\MD\\navigation_restore_eeu.lgu");
                if (DVar3 == 0xffffffff) {
                  DVar3 = GetFileAttributesW(L"\\MD\\navigation_content_license_eeu.lgu");
                  if (DVar3 != 0xffffffff) {
                    uVar6 = 10;
                  }
                }
                else {
                  uVar6 = 5;
                }
                pwVar5 = L"[EEU] dwSkuRegion %d....detected type [%d]!!!\r\n";
              }
              else {
                iVar4 = FUN_00012f8c(iVar7);
                if (iVar4 == 2) {
                  DVar3 = GetFileAttributesW(L"\\MD\\navigation_restore_amr.lgu");
                  if (DVar3 == 0xffffffff) {
                    DVar3 = GetFileAttributesW(L"\\MD\\navigation_content_license_amr.lgu");
                    if (DVar3 != 0xffffffff) {
                      uVar6 = 0xb;
                    }
                  }
                  else {
                    uVar6 = 6;
                  }
                  pwVar5 = L"[AMR] dwSkuRegion %d....detected type [%d]!!!\r\n";
                }
                else {
                  iVar4 = FUN_00012f8c(iVar7);
                  if (iVar4 != 3) {
                    NKDbgPrintfW(L"[INFO] CheckLguFile() dwSkuRegion %d....unknown....!!!\r\n",iVar7
                                );
                    return 0xffffffff;
                  }
                  DVar3 = GetFileAttributesW(L"\\MD\\navigation_restore_oth.lgu");
                  if (DVar3 == 0xffffffff) {
                    DVar3 = GetFileAttributesW(L"\\MD\\navigation_content_license_oth.lgu");
                    if (DVar3 != 0xffffffff) {
                      uVar6 = 0xc;
                    }
                  }
                  else {
                    uVar6 = 7;
                  }
                  pwVar5 = L"[OTH] dwSkuRegion %d....detected type [%d]!!!\r\n";
                }
              }
            }
            NKDbgPrintfW(pwVar5,iVar7,uVar6);
          }
          else {
            uVar6 = 8;
          }
        }
        else {
          uVar6 = 3;
        }
      }
      else {
        uVar6 = 2;
      }
    }
    else {
      uVar6 = 1;
    }
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}



/* 000136bc FUN_000136bc */

/* Boundary evidence: original MIPS .pdata 000136bc..00013833. Semantic name remains unreviewed. */

undefined4 FUN_000136bc(void)

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
  
  local_20 = DAT_000372d0;
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
  FUN_0002a4f0(local_20);
  return uVar3;
}



/* 00013834 FUN_00013834 */

/* Boundary evidence: original MIPS .pdata 00013834..00013993. Semantic name remains unreviewed. */

undefined4 FUN_00013834(void)

{
  HWND hWnd;
  BOOL BVar1;
  DWORD DVar2;
  wchar_t *pwVar3;
  LPARAM local_18 [2];
  
  local_18[0] = 0;
  hWnd = FindWindowW((LPCWSTR)PTR_u_AppMain_000378b4,(LPCWSTR)0x0);
  if (hWnd == (HWND)0x0) {
    NKDbgPrintfW(L"%S IntGetProcessHandle fail, src=%d, dst=%d, cmd=%d","IpcPostMsg",0x11,0x15,0x27e
                );
  }
  else {
    memcpy(local_18,(void *)0x0,0);
    BVar1 = PostMessageW(hWnd,0x8064,0x27e1100,local_18[0]);
    if (BVar1 != 0) {
      return 1;
    }
    DVar2 = GetLastError();
    if (DVar2 == 0) {
      return 1;
    }
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



/* 00013994 FUN_00013994 */

/* Boundary evidence: original MIPS .pdata 00013994..00013b1f. Semantic name remains unreviewed. */

undefined4 FUN_00013994(undefined4 param_1,undefined4 param_2,int param_3)

{
  HWND pHVar1;
  int iVar2;
  undefined4 local_18;
  DWORD local_14;
  
  local_18 = 0;
  local_14 = 0;
  pHVar1 = FindWindowW((LPCWSTR)PTR_u_AppMain_000378b4,(LPCWSTR)0x0);
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



/* 00013b20 FUN_00013b20 */

/* Boundary evidence: original MIPS .pdata 00013b20..00013c3b. Semantic name remains unreviewed. */

DWORD FUN_00013b20(void)

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



/* 00013c3c FUN_00013c3c */

/* Boundary evidence: original MIPS .pdata 00013c3c..00013cd7. Semantic name remains unreviewed. */

WPARAM FUN_00013c3c(HINSTANCE param_1)

{
  int iVar1;
  BOOL BVar2;
  MSG MStack_30;
  
  iVar1 = FUN_00013cd8(param_1);
  if (iVar1 == 0) {
    MStack_30.wParam = 0;
  }
  else {
    while (BVar2 = GetMessageW(&MStack_30,(HWND)0x0,0,0), BVar2 != 0) {
      TranslateMessage(&MStack_30);
      DispatchMessageW(&MStack_30);
    }
  }
  return MStack_30.wParam;
}



/* 00013cd8 FUN_00013cd8 */

/* Boundary evidence: original MIPS .pdata 00013cd8..00013db7. Semantic name remains unreviewed. */

undefined4 FUN_00013cd8(HINSTANCE param_1)

{
  ATOM AVar1;
  undefined2 extraout_var;
  HWND hWnd;
  WNDCLASSW local_38;
  
  local_38.style = 3;
  local_38.lpfnWndProc = FUN_00013db8;
  local_38.cbClsExtra = 0;
  local_38.cbWndExtra = 0;
  local_38.hIcon = (HICON)0x0;
  local_38.hCursor = (HCURSOR)0x0;
  local_38.hbrBackground = (HBRUSH)0x0;
  local_38.lpszMenuName = (LPCWSTR)0x0;
  local_38.lpszClassName = L"UPGRADEMANAGER";
  DAT_00038adc = param_1;
  local_38.hInstance = param_1;
  AVar1 = RegisterClassW(&local_38);
  if ((CONCAT22(extraout_var,AVar1) != 0) &&
     (hWnd = CreateWindowExW(0,L"UPGRADEMANAGER",L"UpgradeManager",0x80000000,-0x80000000,
                             -0x80000000,-0x80000000,-0x80000000,(HWND)0x0,(HMENU)0x0,param_1,
                             (LPVOID)0x0), hWnd != (HWND)0x0)) {
    ShowWindow(hWnd,0);
    UpdateWindow(hWnd);
    return 1;
  }
  return 0;
}



/* 00013db8 FUN_00013db8 */

/* Boundary evidence: original MIPS .pdata 00013db8..00014c77. Semantic name remains unreviewed. */

LRESULT FUN_00013db8(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  BOOL BVar2;
  DWORD DVar3;
  HWND pHVar4;
  int iVar5;
  HDC pHVar6;
  HANDLE hFile;
  size_t cchWideChar;
  LSTATUS LVar7;
  undefined3 extraout_var;
  LRESULT LVar8;
  PHKEY ppHVar9;
  wchar_t *pwVar10;
  UINT_PTR uIDEvent;
  uint uVar11;
  uint uVar12;
  byte local_610 [4];
  int local_60c;
  HKEY local_608;
  DWORD local_604;
  FILE *local_600;
  DWORD local_5fc;
  DWORD local_5f8 [2];
  _PROCESS_INFORMATION _Stack_5f0;
  _PROCESS_INFORMATION _Stack_5e0;
  tagPAINTSTRUCT tStack_5d0;
  undefined1 auStack_590 [92];
  int local_534;
  int local_530;
  wchar_t local_510;
  undefined1 auStack_50e [8];
  ushort local_506;
  ushort local_504;
  undefined1 auStack_500 [184];
  char acStack_448 [264];
  CHAR aCStack_340 [264];
  wchar_t local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
  local_30 = DAT_000372d0;
  uVar12 = 1;
  uVar11 = DAT_00038ef4;
  if (0x201 < param_2) {
    if (param_2 == 0x202) {
      FUN_00016394(param_4 & 0xffff,param_4 >> 0x10);
      uVar11 = DAT_00038ef4;
      goto LAB_00014c3c;
    }
    if (param_2 == 0x620) {
      iVar5 = 0;
      pHVar4 = FindWindowW(L"CodeChecker",L"CodeChecker");
      ppHVar9 = (PHKEY)__2_YAPAXI_Z(4);
      if (ppHVar9 == (PHKEY)0x0) {
        ppHVar9 = (PHKEY)0x0;
      }
      else {
        ppHVar9 = FUN_00012a80(ppHVar9,L"LGE\\SystemStatus\\BTCall");
      }
      if (ppHVar9 != (PHKEY)0x0) {
        if (*ppHVar9 != (HKEY)0x0) {
          local_60c = 0;
          local_5fc = 4;
          LVar7 = RegQueryValueExW(*ppHVar9,L"CallState",(LPDWORD)0x0,local_5f8,(LPBYTE)&local_60c,
                                   &local_5fc);
          if ((LVar7 == 0) && (local_5f8[0] == 4)) {
            iVar5 = local_60c;
          }
          if (*ppHVar9 != (HKEY)0x0) {
            RegCloseKey(*ppHVar9);
          }
        }
        __3_YAXPAX_Z(ppHVar9);
        uVar11 = DAT_00038ef4;
        if (iVar5 != 0) goto LAB_00014c3c;
      }
      uVar11 = DAT_00038ef4;
      if ((DAT_00038f24 == 0) && (pHVar4 == (HWND)0x0)) {
        *(undefined4 *)(DAT_00038f18 + 0x628) = 1;
        FUN_00013994(0x11,0x15,0x279);
        if (DAT_00038f28 == 0) {
          SetWindowPos(DAT_00038efc,(HWND)0xffffffff,0,0,800,0x1e0,0x40);
          InvalidateRect(DAT_00038efc,(RECT *)0x0,0);
          uVar11 = DAT_00038ef4;
        }
        else {
          SetWindowPos(param_1,(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
          SetWindowPos(param_1,(HWND)0x1,0,0,800,0x1e0,0x80);
          DAT_00038f24 = 1;
          uVar11 = DAT_00038ef4;
        }
      }
      goto LAB_00014c3c;
    }
    if (param_2 == 0x7e8) {
      FUN_000158fc(param_3,param_4);
      uVar11 = DAT_00038ef4;
      goto LAB_00014c3c;
    }
    if (param_2 == 0x8064) {
      if ((((param_3 >> 8 & 0xff) == 9) && (param_3 >> 0x10 == 0)) && (DAT_00038f1c != 0)) {
        EventModify(DAT_00038f1c,3);
        uVar11 = DAT_00038ef4;
      }
      goto LAB_00014c3c;
    }
    if (param_2 == 0x9e62) goto LAB_00014c3c;
LAB_000147d4:
    if (DAT_00038f4c == param_2) {
      if (0x1f < (int)param_4) {
        param_4 = 2;
      }
      FUN_00014d58(param_4);
      uVar11 = DAT_00038ef4;
      goto LAB_00014c3c;
    }
    if (DAT_00038f50 == param_2) {
      if (param_4 == 1) {
        BVar2 = IsWindowVisible(param_1);
        if (BVar2 != 0) {
          SetWindowPos(param_1,(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
          SetWindowPos(param_1,(HWND)0x1,0,0,800,0x1e0,0x80);
          DAT_00038f24 = 1;
        }
        DAT_00038f28 = 1;
        uVar11 = DAT_00038ef4;
      }
      else {
        if (DAT_00038f24 == 0) {
          ShowWindow(param_1,0);
        }
        else {
          DAT_00038f24 = 0;
          SetWindowPos(param_1,(HWND)0xffffffff,0,0,800,0x1e0,0x40);
        }
        DAT_00038f28 = 0;
        uVar11 = DAT_00038ef4;
      }
      goto LAB_00014c3c;
    }
    uVar11 = param_4;
    if (DAT_00038f54 == param_2) goto LAB_00014c3c;
    if (DAT_00038f58 == param_2) {
      if ((param_4 != 0) && (param_4 == 1)) {
        uVar12 = 2;
      }
      uVar11 = DAT_00038ef4;
      if (DAT_00038ef8 != uVar12) {
        DAT_00038ef8 = uVar12;
      }
      goto LAB_00014c3c;
    }
    if (DAT_00038f5c != param_2) {
      LVar8 = DefWindowProcW(param_1,param_2,param_3,param_4);
      FUN_0002a4f0(local_30);
      return LVar8;
    }
    DVar3 = GetTickCount();
    NKDbgPrintfW(L"[Upd Manager] Storage Card Format Start!! [%d, %d, %d]\r\n",param_3,param_4,DVar3
                );
    if (param_3 == 1) {
      if (DAT_00038f30 == (HANDLE)0x0) {
        DAT_00038f30 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"Storage Card2 Mount Event~~~");
      }
      FUN_0001a3a4(1,(uint)(param_4 != 0),(uint)(param_4 != 0));
    }
    DVar3 = GetTickCount();
    pwVar10 = L"[Upd Manager] Storage Card Format End!! [%d]\r\n";
LAB_000149e8:
    NKDbgPrintfW(pwVar10,DVar3);
    uVar11 = DAT_00038ef4;
    goto LAB_00014c3c;
  }
  if (param_2 == 0x201) {
    if ((DAT_0003784c == 3000) &&
       (iVar5 = FUN_00016300(param_4 & 0xffff,param_4 >> 0x10), uVar11 = DAT_00038ef4, iVar5 != -1))
    {
      DAT_0003785c = iVar5;
      if (iVar5 == 0) {
        FUN_00015f48(1);
        uVar11 = DAT_00038ef4;
      }
      else if (iVar5 == 1) {
        FUN_00016064(1);
        uVar11 = DAT_00038ef4;
      }
    }
    goto LAB_00014c3c;
  }
  if (param_2 == 1) {
    iVar5 = FUN_0001688c(local_610);
    if (iVar5 != 0) {
      uVar11 = (uint)local_610[0];
      if (1 < uVar11) {
        NKDbgPrintfW(L"[UpGradeMGR]        [error] ui = 0x%d\r\n");
        uVar11 = 0;
      }
      DAT_00038ef8 = uVar11;
      NKDbgPrintfW(L"[UpGradeMGR]        ui = 0x%d\r\n");
    }
    NKDbgPrintfW(L"[Upd Manager ] start!! [%d]\r\n",DAT_00038ef8);
    iVar5 = 2;
    if (DAT_00038ef8 != 0) {
      local_604 = 0;
      hFile = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                          0x80,(HANDLE)0x0);
      if (hFile != (HANDLE)0xffffffff) {
        memset(auStack_590,0,0x80);
        BVar2 = ReadFile(hFile,auStack_590,0x80,&local_604,(LPOVERLAPPED)0x0);
        if ((BVar2 == 0) || (local_604 != 0x80)) {
          NKDbgPrintfW(L"~~~[Error]+_+_+_+_+_+_ [[UPG]-bRet[%d], Size[%d, %d]\r\n",BVar2,local_604,
                       0x80);
        }
        if (BVar2 == 0) {
          NKDbgPrintfW(L"~~~+_+_+_+_+_+_ [[UPG]] Opss\r\n");
          iVar5 = 2;
        }
        else {
          if ((local_534 < 0) || (iVar5 = local_534, 0x1f < local_534)) {
            iVar5 = 2;
          }
          if (local_530 != 0) {
            DAT_00038ef8 = 2;
          }
          NKDbgPrintfW(L"~~~+_+_ [[UPG]] [%d], g_dwUIType[%d]\r\n",local_534,DAT_00038ef8);
        }
        CloseHandle(hFile);
      }
    }
    NKDbgPrintfW(L"~~~+_+_+_+_+_+_ [[UPG]] Language ID [%d, %d][%d]\r\n",DAT_0003780c,iVar5);
    FUN_00014d58(iVar5);
    local_510 = L'\0';
    memset(auStack_50e,0,0xc6);
    local_238 = L'\0';
    memset(auStack_236,0,0x206);
    memset(aCStack_340,0,0x104);
    memset(acStack_448,0,0x104);
    wcscpy(&local_510,L"2016-02-18");
    _snwprintf(&local_238,0x103,L"%c%c.%s.%s",(uint)local_506,(uint)local_504,auStack_500,L"17222");
    cchWideChar = wcslen(&local_238);
    WideCharToMultiByte(0,0,&local_238,cchWideChar,aCStack_340,cchWideChar,(LPCSTR)0x0,(LPBOOL)0x0);
    sprintf_s(acStack_448,0x20,"\\UPG %s.ver",aCStack_340);
    fopen_s(&local_600,acStack_448,"wt");
    fclose(local_600);
    LVar7 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_608);
    if (LVar7 == 0) {
      RegSetValueExW(local_608,L"VerUpgradeManager",0,1,(BYTE *)&local_238,(cchWideChar + 1) * 2);
      RegCloseKey(local_608);
    }
    DAT_00038efc = param_1;
    bVar1 = FUN_00014c78(param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      NKDbgPrintfW(L"[Upd Manager ] WM_CREATE:: Upgrade Init fail!!\r\n");
      uVar11 = DAT_00038ef4;
    }
    else {
      DAT_00038f38 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00012d80,&DAT_00038efc,0,
                                  (LPDWORD)0x0);
      uVar11 = DAT_00038ef4;
    }
    goto LAB_00014c3c;
  }
  if (param_2 == 2) {
    DAT_00037998 = 1;
    if (DAT_00037990 != 0) {
      EventModify(DAT_00037990,3);
    }
    if (DAT_00038f18 != 0) {
      __3_YAXPAX_Z();
      DAT_00038f18 = 0;
    }
    PostQuitMessage(0);
    uVar11 = DAT_00038ef4;
    goto LAB_00014c3c;
  }
  if (param_2 == 8) goto LAB_00014c3c;
  if (param_2 == 0xf) {
    pHVar6 = BeginPaint(param_1,&tStack_5d0);
    if (DAT_00038f18 != 0) {
      if (*(int *)(DAT_00038f18 + 0x628) == 1) {
        FUN_000188f8(DAT_00038f18,pHVar6);
      }
      else if (*(int *)(DAT_00038f18 + 0x628) == 2) {
        FUN_00018e88(DAT_00038f18,pHVar6);
      }
    }
    EndPaint(param_1,&tStack_5d0);
    uVar11 = DAT_00038ef4;
    goto LAB_00014c3c;
  }
  if (param_2 != 0x113) goto LAB_000147d4;
  if (param_3 == 1) {
    uIDEvent = 1;
  }
  else {
    if (param_3 != 2) {
      if (param_3 == 1000) {
        NKDbgPrintfW(L"~!@#$ Upgrade Manager 1600msec delay excute micom manager\r\n");
        memset(&_Stack_5f0,0,0x10);
        BVar2 = CreateProcessW(L"\\Storage Card\\system\\MicomManager.exe",
                               L"er10q4c$=4G2g-H2tq9X@mid",(LPSECURITY_ATTRIBUTES)0x0,
                               (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                               (LPSTARTUPINFOW)0x0,&_Stack_5f0);
        if (BVar2 == 0) {
          NKDbgPrintfW(L"[Upd Manager] FAIL!!! RunProgram(MICOM_MANAGER)\r\n");
          DVar3 = GetFileAttributesW(L"\\MD\\MicomManager.exe");
          uVar11 = DAT_00038ef4;
          if (DVar3 != 0xffffffff) {
            CopyFileW(L"\\MD\\MicomManager.exe",L"\\Storage Card\\system\\MicomManager.exe",0);
            uVar11 = DAT_00038ef4;
          }
        }
        else {
          KillTimer(param_1,1000);
          SetTimer(param_1,2,5000,(TIMERPROC)0x0);
          SetTimer(param_1,0x3ea,500,(TIMERPROC)0x0);
          uVar11 = DAT_00038ef4;
        }
        goto LAB_00014c3c;
      }
      if (param_3 != 0x3ea) {
        if (param_3 != 0x3eb) goto LAB_00014c3c;
        BVar2 = CreateProcessW(L"\\MD\\Special_tool.exe",L"er10q4c$=4G2g-H2tq9X@mid",
                               (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0
                               ,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,&_Stack_5e0);
        if (BVar2 == 0) {
          DVar3 = GetLastError();
          pwVar10 = L"[Upd Manager]SPECIAL_FILE_PATH did not excute!! 0x%x\r\n";
          goto LAB_000149e8;
        }
        NKDbgPrintfW(L"[Upd Manager] CreateProcess Successed!!!!\r\n");
        uIDEvent = 0x3eb;
        goto LAB_000142fc;
      }
      pHVar4 = FindWindowW(L"CodeChecker",L"CodeChecker");
      uVar11 = DAT_00038ef4;
      if (pHVar4 != (HWND)0x0) goto LAB_00014c3c;
      if (0x28 < DAT_00038f20) {
        DAT_00038f44 = 1;
        KillTimer(param_1,0x3ea);
        if (((((DAT_00038f40 & 1) != 0) && (DAT_00038f40 = DAT_00038f40 | 1, DAT_00038f44 != 0)) &&
            (DAT_00038ef4 != 1)) &&
           ((DAT_00038f18 != 0 &&
            (NKDbgPrintfW(L"[Upd Manager] MD directory exists.... g_bUpgrade %d\r\n",DAT_00038f10),
            DAT_00038f10 == 0)))) {
          iVar5 = FUN_000136bc();
          if (iVar5 != 0) {
            SetTimer(DAT_00038efc,0x3eb,0xdac,(TIMERPROC)0x0);
          }
          iVar5 = FUN_00017964(DAT_00038f18,(LPCWSTR)(DAT_00038f18 + 0x208));
          if (iVar5 == 0) {
            DAT_00037858 = FUN_0001335c();
            iVar5 = 0;
            if ((DAT_00037858 != -1) && (DAT_00037858 < 0xd)) {
              if (DAT_00037858 == 0) {
                pwVar10 = L"\\MD\\upgrade_root.lgu";
LAB_00014128:
                swprintf_s((wchar_t *)(DAT_00038f18 + 0x208),0x104,L"%s",pwVar10);
              }
              else {
                if (DAT_00037858 == 1) {
                  pwVar10 = L"\\MD\\navigation_restore.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 2) {
                  pwVar10 = L"\\MD\\navigation_restore_fat32.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 3) {
                  pwVar10 = L"\\MD\\navigation_restore_tfat.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 4) {
                  pwVar10 = L"\\MD\\navigation_restore_weu.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 5) {
                  pwVar10 = L"\\MD\\navigation_restore_eeu.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 6) {
                  pwVar10 = L"\\MD\\navigation_restore_amr.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 7) {
                  pwVar10 = L"\\MD\\navigation_restore_oth.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 8) {
                  pwVar10 = L"\\MD\\navigation_content_license.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 9) {
                  pwVar10 = L"\\MD\\navigation_content_license_weu.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 10) {
                  pwVar10 = L"\\MD\\navigation_content_license_eeu.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 0xb) {
                  pwVar10 = L"\\MD\\navigation_content_license_amr.lgu";
                  goto LAB_00014128;
                }
                if (DAT_00037858 == 0xc) {
                  pwVar10 = L"\\MD\\navigation_content_license_oth.lgu";
                  goto LAB_00014128;
                }
              }
              swprintf_s((wchar_t *)(DAT_00038f18 + 0x410),0x104,L"%s",&DAT_00031cfc);
              iVar5 = FUN_00017964(DAT_00038f18,(LPCWSTR)(DAT_00038f18 + 0x208));
            }
            NKDbgPrintfW(L"[Upd Manager] No upgrade.lgu file in the MD (DEV_NOTIFY_MSG) -- g_bMapUpdate = %d, SearchUpgradeFiles = %d\r\n"
                         ,DAT_00038f44,iVar5);
            if (((iVar5 == 0) &&
                (DVar3 = GetFileAttributesW(L"\\MD\\update_checksum.md5"), DVar3 != 0xffffffff)) &&
               (pHVar4 = FindWindowW(L"CodeChecker",L"CodeChecker"), pHVar4 == (HWND)0x0)) {
              FUN_00015dbc();
            }
          }
        }
      }
      DAT_00038f20 = DAT_00038f20 + 1;
      uVar11 = DAT_00038ef4;
      goto LAB_00014c3c;
    }
    pHVar4 = FindWindowW(L"APPMAIN",(LPCWSTR)0x0);
    uVar11 = DAT_00038ef4;
    if ((pHVar4 != (HWND)0x0) || (DAT_0003784c == 0xbbd)) goto LAB_00014c3c;
    uIDEvent = 2;
  }
LAB_000142fc:
  KillTimer(param_1,uIDEvent);
  uVar11 = DAT_00038ef4;
LAB_00014c3c:
  DAT_00038ef4 = uVar11;
  FUN_0002a4f0(local_30);
  return 0;
}



/* 00014c78 FUN_00014c78 */

/* Boundary evidence: original MIPS .pdata 00014c78..00014d57. Semantic name remains unreviewed. */

bool FUN_00014c78(undefined4 param_1)

{
  bool bVar1;
  
  DAT_00038f18 = (wchar_t *)__2_YAPAXI_Z(0x634);
  if (DAT_00038f18 == (wchar_t *)0x0) {
    DAT_00038f18 = (wchar_t *)0x0;
  }
  else {
    *DAT_00038f18 = L'\0';
    DAT_00038f18[0x104] = L'\0';
    DAT_00038f18[0x208] = L'\0';
    DAT_00038f18[0x30c] = L'\0';
    DAT_00038f18[0x30d] = L'\0';
    DAT_00038f18[0x30e] = L'\0';
    DAT_00038f18[0x30f] = L'\0';
    DAT_00038f18[0x310] = L'\x01';
    DAT_00038f18[0x311] = L'\0';
    DAT_00038f18[0x312] = L'\0';
    DAT_00038f18[0x313] = L'\0';
    DAT_00038f18[0x314] = L'\0';
    DAT_00038f18[0x315] = L'\0';
    DAT_00038f18[0x316] = L'\0';
    DAT_00038f18[0x317] = L'\0';
    *(undefined4 *)(DAT_00038f18 + 0x318) = param_1;
  }
  bVar1 = DAT_00038f18 != (wchar_t *)0x0;
  if (bVar1) {
    swprintf_s(DAT_00038f18,0x104,L"%s",&DAT_000313b4);
    swprintf_s(DAT_00038f18 + 0x104,0x104,L"%s",L"\\MD\\upgrade.lgu");
    swprintf_s(DAT_00038f18 + 0x208,0x104,L"%s",L"\\Storage Card3\\");
  }
  return bVar1;
}



/* 00014d58 FUN_00014d58 */

/* Boundary evidence: original MIPS .pdata 00014d58..00014eaf. Semantic name remains unreviewed. */

void FUN_00014d58(int param_1)

{
  HINSTANCE hInstance;
  
  if (param_1 != DAT_0003780c) {
    if (param_1 < 0x20) {
      hInstance = LoadLibraryW((LPCWSTR)(&PTR_u__Storage_Card_system_data_LangDl_00037908)[param_1])
      ;
      DAT_0003780c = param_1;
    }
    else {
      hInstance = LoadLibraryW((LPCWSTR)PTR_u__Storage_Card_system_data_LangDl_00037910);
    }
    if (hInstance != (HINSTANCE)0x0) {
      LoadStringW(hInstance,0x4b5,(LPWSTR)&DAT_000388d4,0x104);
      LoadStringW(hInstance,0x4b6,(LPWSTR)&DAT_000386cc,0x104);
      LoadStringW(hInstance,0x4b7,(LPWSTR)&DAT_000384c4,0x104);
      LoadStringW(hInstance,0x4b8,(LPWSTR)&DAT_000382bc,0x104);
      LoadStringW(hInstance,0x4b9,(LPWSTR)&DAT_000380b4,0x104);
      LoadStringW(hInstance,0x4ba,(LPWSTR)&DAT_00037eac,0x104);
      LoadStringW(hInstance,0x4bb,(LPWSTR)&DAT_00037ca4,0x104);
      LoadStringW(hInstance,0x59a,(LPWSTR)&DAT_00037a9c,0x104);
      FreeLibrary(hInstance);
    }
  }
  return;
}



/* 00014eb0 FUN_00014eb0 */

/* Boundary evidence: original MIPS .pdata 00014eb0..0001565f. Semantic name remains unreviewed. */

void FUN_00014eb0(void)

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
  
  local_30 = DAT_000372d0;
  if (DAT_00038f18 != 0) {
    iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card3\\upgrade",0,1);
    if (iVar3 == 1) {
      iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card3\\upgrade\\filecopy_success.bin",0,0);
      if (iVar3 == 1) {
        hWnd = FindWindowW((LPCWSTR)PTR_u_MgrMcm_0003786c,(LPCWSTR)0x0);
        if (DAT_00038f14 == 0) {
          if (hWnd == (HWND)0x0) {
            NKDbgPrintfW(L"MicomManger is NOT running!!!\r\n");
            bVar2 = FUN_00016978();
            if (CONCAT31(extraout_var,bVar2) != 0) {
              local_23f = 1;
              FUN_00016a6c(1,1,0xfd,0,0);
              FUN_00016a6c(1,1,7,(int)&local_23f,1);
              NKDbgPrintfW(L"COM2 open succeed!!!\r\n");
            }
          }
          else {
            PostMessageW(hWnd,0x8064,0xb90300,1);
          }
          DAT_00038f14 = 1;
        }
        iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\synctool",
                             0,1);
        if (iVar3 == 1) {
          FUN_00017fe0(DAT_00038f18,L"\\Storage Card4\\NNG\\synctool");
        }
        iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\data.zip",
                             0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card4\\NNG\\data.zip");
        }
        iVar3 = FUN_00017454(DAT_00038f18,
                             L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\nngnavi.exe",0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card4\\NNG\\nngnavi.exe");
        }
        iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card3\\upgrade\\Storage Card4\\NNG\\sys.txt",0
                             ,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card4\\NNG\\sys.txt");
        }
        NKDbgPrintfW(L"[Upd Manager] Upgrade files [SC3 -> SC]\r\n");
        iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card2\\scan_done_flag.bin",0,0);
        if (iVar3 == 1) {
          FUN_0001a3a4(1,0,0);
          FUN_00017fe0(DAT_00038f18,L"\\Storage Card3\\TFAT");
        }
        else {
          DeleteFileW(L"\\Storage card2\\pwr_count.bin");
          pvVar4 = CreateFileW(L"\\Storage Card2\\scan_done_flag.bin",0x40000000,0,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
          if (pvVar4 != (HANDLE)0xffffffff) {
            CloseHandle(pvVar4);
          }
          FUN_000170fc();
          FUN_00018460(DAT_00038f18,L"\\Storage Card2",L"\\Storage Card3\\TFAT");
          FUN_0001a3a4(1,0,0);
          FUN_00018698(DAT_00038f18,L"\\Storage Card3\\TFAT",L"\\Storage Card2");
          DVar5 = GetFileAttributesW(L"\\Storage Card2\\scan_done_flag.bin");
          if (DVar5 != 0xffffffff) {
            DeleteFileW(L"\\Storage Card2\\scan_done_flag.bin");
          }
        }
        iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card\\system\\OLD_UpgradeManager.exe",0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card\\system\\OLD_UpgradeManager.exe");
        }
        iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card3\\upgrade\\firmware.hex",0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card3\\upgrade\\firmware.hex");
        }
        iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card3\\upgrade\\ulc_dab_bc_LGe.bin",0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card3\\upgrade\\ulc_dab_bc_LGe.bin");
        }
        iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card3\\upgrade\\ulc_dab_uc_LGe.bin",0,0);
        if (iVar3 == 1) {
          DeleteFileW(L"\\Storage Card3\\upgrade\\ulc_dab_uc_LGe.bin");
        }
        swprintf_s(awStack_238,0x104,L"%s",&DAT_0002fca4);
        DAT_0003784c = 0xbbd;
        FUN_00019714(DAT_00038f18);
        iVar3 = DAT_00038f18;
        *(undefined4 *)(DAT_00038f18 + 0x620) = 0;
        FUN_00017dd4(iVar3,L"\\Storage Card3\\upgrade");
        FUN_000181b4(DAT_00038f18,L"\\Storage Card3\\upgrade",awStack_238);
        iVar3 = DAT_00038f18;
        puVar1 = (undefined4 *)(DAT_00038f18 + 0x630);
        *(undefined4 *)(DAT_00038f18 + 0x628) = 0;
        SetWindowPos((HWND)*puVar1,(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
        SetWindowPos(*(HWND *)(iVar3 + 0x630),(HWND)0x1,0,0,800,0x1e0,0x80);
        ShowWindow(*(HWND *)(iVar3 + 0x630),0);
        DAT_0003784c = 3000;
        if (DAT_00038f14 == 1) {
          if (hWnd != (HWND)0x0) {
            PostMessageW(hWnd,0x8064,0xb90300,0);
          }
          NKDbgPrintfW(L"[UPG]          PostMSG    [0]    !@#+_!+@)$+)!@+$)  \r\n");
          DAT_00038f14 = 0;
        }
        NKDbgPrintfW(L"[Upd Manager ] upgrade files move complete!!\r\n");
      }
      FUN_00017fe0(DAT_00038f18,L"\\Storage Card3\\upgrade");
      if (DAT_00037854 != -1) {
        local_23d[0] = 0;
        FUN_00016a6c(1,1,7,(int)local_23d,1);
        if (DAT_00037854 != -1) {
          CloseHandle((HANDLE)DAT_00037854);
          DAT_00037854 = -1;
        }
        NKDbgPrintfW(L"COM2 close succeed!!!\r\n");
      }
    }
    else {
      DVar5 = FUN_00013b20();
      if (0xaf < DVar5) {
        DeleteFileW(L"\\Storage card2\\pwr_count.bin");
        iVar3 = FUN_00017454(DAT_00038f18,L"\\Storage Card2\\scan_done_flag.bin",0,0);
        if (iVar3 == 1) {
          FUN_0001a3a4(1,0,0);
        }
        else {
          DVar5 = GetTickCount();
          bVar2 = FUN_00016978();
          if (CONCAT31(extraout_var_00,bVar2) != 0) {
            local_240 = 1;
            FUN_00016a6c(1,1,0xfd,0,0);
            FUN_00016a6c(1,1,7,(int)&local_240,1);
            NKDbgPrintfW(L"=-=- COM2 open succeed!!!\r\n");
          }
          pvVar4 = CreateFileW(L"\\Storage Card2\\scan_done_flag.bin",0x40000000,0,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
          if (pvVar4 != (HANDLE)0xffffffff) {
            CloseHandle(pvVar4);
          }
          FUN_000170fc();
          FUN_00018460(DAT_00038f18,L"\\Storage Card2",L"\\Storage Card3\\TFAT");
          FUN_0001a3a4(1,0,0);
          FUN_00018698(DAT_00038f18,L"\\Storage Card3\\TFAT",L"\\Storage Card2");
          DVar6 = GetFileAttributesW(L"\\Storage Card2\\scan_done_flag.bin");
          if (DVar6 != 0xffffffff) {
            DeleteFileW(L"\\Storage Card2\\scan_done_flag.bin");
          }
          if (DAT_00037854 != -1) {
            local_23e = 0;
            FUN_00016a6c(1,1,7,(int)&local_23e,1);
            if (DAT_00037854 != -1) {
              CloseHandle((HANDLE)DAT_00037854);
              DAT_00037854 = -1;
            }
            DVar6 = GetTickCount();
            NKDbgPrintfW(L"=-=- COM2 close succeed!!![%d]\r\n",DVar6 - DVar5);
          }
        }
      }
    }
  }
  FUN_0002a4f0(local_30);
  return;
}



/* 00015660 FUN_00015660 */

/* Boundary evidence: original MIPS .pdata 00015660..0001587f. Semantic name remains unreviewed. */

undefined4 FUN_00015660(void)

{
  HWND hWnd;
  int iVar1;
  
  NKDbgPrintfW(L"Uncompressed Start +_+_+_+_+_+_+_+_+_ \r\n");
  FUN_00019714(DAT_00038f18);
  DAT_00038f10 = 0;
  DAT_00038f0c = 1;
  DAT_00038f48 = 0;
  if (DAT_00037858 == -1) {
    iVar1 = 2;
  }
  else {
    if (DAT_00037858 == 0) goto LAB_000157ec;
    if ((((DAT_00037858 == 8) || (DAT_00037858 == 9)) || (DAT_00037858 == 10)) ||
       ((DAT_00037858 == 0xb || (DAT_00037858 == 0xc)))) {
      iVar1 = FUN_00017454(DAT_00038f18,L"\\Storage Card4\\NNG\\license",0,1);
      if (iVar1 == 1) {
        FUN_00017fe0(DAT_00038f18,L"\\Storage Card4\\NNG\\license");
      }
      goto LAB_000157ec;
    }
    hWnd = FindWindowW(L"NAVI",(LPCWSTR)0x0);
    if (hWnd != (HWND)0x0) {
      PostMessageW(hWnd,0x10,0,0);
      NKDbgPrintfW(L"[Upd Manager] [INFO] [0x%08X] %s close.... DetectFileType[%d]\r\n",hWnd,L"NAVI"
                   ,DAT_00037858);
      Sleep(0x9c4);
    }
    FUN_0001a3a4(3,(uint)(DAT_00037858 == 3),(uint)(DAT_00037858 == 3));
    iVar1 = 1;
  }
  FUN_0001a3a4(iVar1,0,0);
LAB_000157ec:
  DAT_00038f48 = FUN_000197a8(DAT_00038f18);
  if (DAT_00037850 == 1) {
    DAT_00038f48 = 0;
  }
  EventModify(DAT_00038f08,3);
  NKDbgPrintfW(L"Uncompressed End [%d]+_+_+_+_+_+_+_+_+_ \r\n",DAT_00038f48);
  if (DAT_00038f00 != 0) {
    CloseHandle((HANDLE)DAT_00038f00);
    DAT_00038f00 = 0;
  }
  return 0;
}



/* 00015880 FUN_00015880 */

/* Boundary evidence: original MIPS .pdata 00015880..000158fb. Semantic name remains unreviewed. */

undefined4 FUN_00015880(void)

{
  WaitForSingleObject(DAT_00038f08,0xffffffff);
  if (DAT_00038f48 != 0) {
    FUN_00017530(DAT_00038f18);
  }
  if (DAT_00038f04 != 0) {
    CloseHandle((HANDLE)DAT_00038f04);
    DAT_00038f04 = 0;
  }
  return 0;
}



/* 000158fc FUN_000158fc */

/* Boundary evidence: original MIPS .pdata 000158fc..00015dbb. Semantic name remains unreviewed. */

void FUN_000158fc(int param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  HWND pHVar3;
  wchar_t *pwVar4;
  
  if (param_2 != 0) {
    if (param_2 != 4) {
      return;
    }
    if (param_1 == 0) {
      return;
    }
    if (DAT_00038f30 == 0) {
      return;
    }
    EventModify(DAT_00038f30,3);
    return;
  }
  if (param_1 == 0) {
    DAT_00038f40 = DAT_00038f40 & 0xfffffffe;
  }
  else {
    DAT_00038f40 = DAT_00038f40 | 1;
  }
  if (DAT_00038f44 == 0) {
    return;
  }
  if ((DAT_00038ef4 == 1) && (param_1 != 0)) {
    return;
  }
  if (param_1 == 0) {
    if (DAT_00038f10 == 0) {
      DAT_00038f0c = 0;
      DAT_0003784c = 3000;
      if (DAT_00038f00 != (HANDLE)0x0) {
        DAT_00037850 = 1;
        WaitForSingleObject(DAT_00038f00,0xffffffff);
        if (DAT_00038f00 != (HANDLE)0x0) {
          CloseHandle(DAT_00038f00);
          DAT_00038f00 = (HANDLE)0x0;
        }
      }
      DAT_00038f24 = 0;
      if (DAT_00037858 != -1) {
        DAT_00037858 = -1;
        swprintf_s((wchar_t *)(DAT_00038f18 + 0x208),0x104,L"%s",L"\\MD\\upgrade.lgu");
        swprintf_s((wchar_t *)(DAT_00038f18 + 0x410),0x104,L"%s",L"\\Storage Card3\\");
      }
      *(undefined4 *)(DAT_00038f18 + 0x628) = 0;
      ShowWindow(DAT_00038efc,0);
      if (DAT_00038f14 == 1) {
        pHVar3 = FindWindowW((LPCWSTR)PTR_u_MgrMcm_0003786c,(LPCWSTR)0x0);
        if (pHVar3 != (HWND)0x0) {
          PostMessageW(pHVar3,0x8064,0xb90300,0);
        }
        NKDbgPrintfW(L"[UPG]          PostMSG    [0]  hMcmWnd[0x%08X] g_bUpgrade %d  !@#+_!+@)$+)!@+$)  \r\n"
                     ,pHVar3,DAT_00038f10);
        DAT_00038f14 = 0;
      }
    }
    KillTimer(DAT_00038efc,0x3eb);
    FUN_00013994(0x11,0x15,0x27a);
    return;
  }
  if (DAT_00038f18 == 0) {
    return;
  }
  NKDbgPrintfW(L"[Upd Manager] MD directory exists.... g_bUpgrade %d\r\n",DAT_00038f10);
  if (DAT_00038f10 != 0) {
    return;
  }
  iVar1 = FUN_000136bc();
  if (iVar1 != 0) {
    SetTimer(DAT_00038efc,0x3eb,0xdac,(TIMERPROC)0x0);
  }
  iVar1 = FUN_00017964(DAT_00038f18,(LPCWSTR)(DAT_00038f18 + 0x208));
  if (iVar1 != 0) {
    return;
  }
  DAT_00037858 = FUN_0001335c();
  iVar1 = 0;
  if ((DAT_00037858 == -1) || (0xc < DAT_00037858)) goto LAB_00015b90;
  if (DAT_00037858 == 0) {
    pwVar4 = L"\\MD\\upgrade_root.lgu";
LAB_00015b50:
    swprintf_s((wchar_t *)(DAT_00038f18 + 0x208),0x104,L"%s",pwVar4);
  }
  else {
    if (DAT_00037858 == 1) {
      pwVar4 = L"\\MD\\navigation_restore.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 2) {
      pwVar4 = L"\\MD\\navigation_restore_fat32.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 3) {
      pwVar4 = L"\\MD\\navigation_restore_tfat.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 4) {
      pwVar4 = L"\\MD\\navigation_restore_weu.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 5) {
      pwVar4 = L"\\MD\\navigation_restore_eeu.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 6) {
      pwVar4 = L"\\MD\\navigation_restore_amr.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 7) {
      pwVar4 = L"\\MD\\navigation_restore_oth.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 8) {
      pwVar4 = L"\\MD\\navigation_content_license.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 9) {
      pwVar4 = L"\\MD\\navigation_content_license_weu.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 10) {
      pwVar4 = L"\\MD\\navigation_content_license_eeu.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 0xb) {
      pwVar4 = L"\\MD\\navigation_content_license_amr.lgu";
      goto LAB_00015b50;
    }
    if (DAT_00037858 == 0xc) {
      pwVar4 = L"\\MD\\navigation_content_license_oth.lgu";
      goto LAB_00015b50;
    }
  }
  swprintf_s((wchar_t *)(DAT_00038f18 + 0x410),0x104,L"%s",&DAT_00031cfc);
  iVar1 = FUN_00017964(DAT_00038f18,(LPCWSTR)(DAT_00038f18 + 0x208));
LAB_00015b90:
  NKDbgPrintfW(L"[Upd Manager] No upgrade.lgu file in the MD (DEV_NOTIFY_MSG) -- g_bMapUpdate = %d, SearchUpgradeFiles = %d\r\n"
               ,DAT_00038f44,iVar1);
  if (((iVar1 == 0) &&
      (DVar2 = GetFileAttributesW(L"\\MD\\update_checksum.md5"), DVar2 != 0xffffffff)) &&
     (pHVar3 = FindWindowW(L"CodeChecker",L"CodeChecker"), pHVar3 == (HWND)0x0)) {
    FUN_00015dbc();
  }
  return;
}



/* 00015dbc FUN_00015dbc */

/* Boundary evidence: original MIPS .pdata 00015dbc..00015f47. Semantic name remains unreviewed. */

undefined4 FUN_00015dbc(void)

{
  BOOL BVar1;
  DWORD DVar2;
  HWND hWnd;
  wchar_t *pwVar3;
  _PROCESS_INFORMATION local_20;
  
  if (DAT_00038f2c == (HANDLE)0x0) {
    BVar1 = CreateProcessW(L"\\Storage Card4\\NNG\\Synctool\\Synctool.exe",
                           L"kk9r2a@=4F2g-J2tw6X@navi",(LPSECURITY_ATTRIBUTES)0x0,
                           (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                           (LPSTARTUPINFOW)0x0,&local_20);
    if (BVar1 != 0) {
      CloseHandle(local_20.hProcess);
      CloseHandle(local_20.hThread);
      if (DAT_00038f14 == 0) {
        hWnd = FindWindowW((LPCWSTR)PTR_u_MgrMcm_0003786c,(LPCWSTR)0x0);
        if (hWnd != (HWND)0x0) {
          PostMessageW(hWnd,0x8064,0xb90300,2);
          FUN_00013834();
          NKDbgPrintfW(L"[Upd Manager] SYNCTool.exe is excuted!! and sended msg\r\n");
        }
        NKDbgPrintfW(L"[UPG]          PostMSG    [0]  hMcmWnd[0x%08X]  !@#+_!+@)$+)!@+$)  \r\n",hWnd
                    );
        DAT_00038f14 = 0;
      }
      DAT_00038f2c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00012b50,&local_20,0,(LPDWORD)0x0
                                 );
      NKDbgPrintfW(L"[Upd Manager]SYNCTool.exe normally excute!!! 0x%08X\r\n",DAT_00038f2c);
      return 1;
    }
    DVar2 = GetLastError();
    pwVar3 = L"[Upd Manager]SYNCTool.exe did not excute!! 0x%x\r\n";
  }
  else {
    pwVar3 = L"[Upd Manager][ERROR]SYNCTool.exe already excute!!! 0x%08X\r\n";
    DVar2 = (DWORD)DAT_00038f2c;
  }
  NKDbgPrintfW(pwVar3,DVar2);
  return 0;
}



/* 00015f48 FUN_00015f48 */

/* Boundary evidence: original MIPS .pdata 00015f48..00016063. Semantic name remains unreviewed. */

void FUN_00015f48(int param_1)

{
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  
  hdc = GetDC(DAT_00038efc);
  hdc_00 = CreateCompatibleDC(hdc);
  pvVar1 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_etc__00037810)
                                   [DAT_00038ef8 * 5]);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  if (param_1 == 0) {
    BitBlt(hdc,0,0x1a3,0x6c,0x3d,hdc_00,0,0,0xcc0020);
  }
  else {
    BitBlt(hdc,0,0x1a3,0x6c,0x3d,hdc_00,0x6c,0,0xcc0020);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  DeleteObject(pvVar1);
  DeleteDC(hdc_00);
  ReleaseDC(DAT_00038efc,hdc);
  return;
}



/* 00016064 FUN_00016064 */

/* Boundary evidence: original MIPS .pdata 00016064..000162ff. Semantic name remains unreviewed. */

void FUN_00016064(int param_1)

{
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  HFONT h;
  COLORREF color;
  tagRECT local_90;
  LOGFONTW local_80;
  uint local_24;
  
  local_24 = DAT_000372d0;
  hdc = GetDC(DAT_00038efc);
  hdc_00 = CreateCompatibleDC(hdc);
  pvVar1 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_etc__00037818)
                                   [DAT_00038ef8 * 5]);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  if (param_1 == 0) {
    BitBlt(hdc,0x6d,0x1a3,0x2b3,0x3d,hdc_00,0,0,0xcc0020);
  }
  else {
    BitBlt(hdc,0x6d,0x1a3,0x2b3,0x3d,hdc_00,0x2b3,0,0xcc0020);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  DeleteObject(pvVar1);
  DeleteDC(hdc_00);
  memset(&local_80,0,0x5c);
  SetBkMode(hdc,1);
  if ((DAT_00038ef8 == 2) || (param_1 != 0)) {
    color = 0;
  }
  else {
    color = 0xffffff;
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
  local_90.left = 0x6c;
  local_90.top = 0x1a3;
  local_90.right = 800;
  local_90.bottom = 0x1e0;
  if (((DAT_0003780c == 0) || (DAT_0003780c == 0x1f)) || (DAT_0003780c == 0x15)) {
    DrawTextW(hdc,(LPCWSTR)&DAT_000380b4,-1,&local_90,0x20005);
  }
  else {
    DrawTextW(hdc,(LPCWSTR)&DAT_000380b4,-1,&local_90,5);
  }
  SelectObject(hdc,pvVar1);
  DeleteObject(h);
  ReleaseDC(DAT_00038efc,hdc);
  FUN_0002a4f0(local_24);
  return;
}



/* 00016300 FUN_00016300 */

undefined4 FUN_00016300(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_0003784c == 3000) {
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



/* 00016394 FUN_00016394 */

/* Boundary evidence: original MIPS .pdata 00016394..0001688b. Semantic name remains unreviewed. */

void FUN_00016394(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  HDC hDC;
  HBRUSH hbr;
  HFONT h;
  HGDIOBJ h_00;
  HWND pHVar3;
  DWORD DVar4;
  COLORREF color;
  tagRECT local_a8;
  RECT local_98;
  LOGFONTW local_88;
  uint local_2c;
  
  local_2c = DAT_000372d0;
  iVar2 = FUN_00016300(param_1,param_2);
  if (DAT_0003784c == 3000) {
    if (iVar2 == DAT_0003785c) {
      if (DAT_0003785c == 0) {
        FUN_00015f48(0);
        Sleep(500);
        DAT_0003784c = 3000;
        if (DAT_00037858 != -1) {
          DAT_00037858 = -1;
          swprintf_s((wchar_t *)(DAT_00038f18 + 0x208),0x104,L"%s",L"\\MD\\upgrade.lgu");
          swprintf_s((wchar_t *)(DAT_00038f18 + 0x410),0x104,L"%s",L"\\Storage Card3\\");
        }
        ShowWindow(DAT_00038efc,0);
        FUN_00013994(0x11,0x15,0x27a);
        DVar4 = GetFileAttributesW(L"\\MD\\update_checksum.md5");
        if ((DVar4 != 0xffffffff) &&
           (pHVar3 = FindWindowW(L"CodeChecker",L"CodeChecker"), pHVar3 == (HWND)0x0)) {
          FUN_00015dbc();
        }
      }
      else if (DAT_0003785c == 1) {
        FUN_00016064(0);
        iVar1 = DAT_00038f18;
        *(undefined4 *)(DAT_00038f18 + 0x628) = 2;
        *(undefined4 *)(iVar1 + 0x618) = 0;
        *(undefined4 *)(iVar1 + 0x61c) = 0;
        *(undefined4 *)(iVar1 + 0x620) = 1;
        *(undefined4 *)(iVar1 + 0x624) = 0;
        if (DAT_00037858 == -1) {
          DAT_0003784c = 0xbb9;
        }
        else {
          DAT_0003784c = 0xbbe;
        }
        if (DAT_00038f00 != (HANDLE)0x0) {
          local_98.right = 800;
          local_98.left = 0;
          local_98.top = 0;
          local_98.bottom = 0x1e0;
          hDC = GetDC(DAT_00038efc);
          hbr = GetStockObject(4);
          FillRect(hDC,&local_98,hbr);
          memset(&local_88,0,0x5c);
          SetBkMode(hDC,1);
          NKDbgPrintfW(L"\r\n[UPG_BTN_START()] %d\r\n",DAT_00038ef8);
          if (DAT_00038ef8 == 2) {
            color = 0;
          }
          else {
            color = 0xffffff;
          }
          SetTextColor(hDC,color);
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
          local_a8.right = 800;
          local_a8.left = 0;
          local_a8.top = 0;
          local_a8.bottom = 0x1e0;
          if (((DAT_0003780c == 0) || (DAT_0003780c == 0x1f)) || (DAT_0003780c == 0x15)) {
            DrawTextW(hDC,(LPCWSTR)&DAT_00037a9c,-1,&local_a8,0x20005);
          }
          else {
            DrawTextW(hDC,(LPCWSTR)&DAT_00037a9c,-1,&local_a8,5);
          }
          SelectObject(hDC,h_00);
          DeleteObject(h);
          ReleaseDC(DAT_00038efc,hDC);
          DAT_00037850 = 1;
          WaitForSingleObject(DAT_00038f00,0xffffffff);
          if (DAT_00038f00 != (HANDLE)0x0) {
            CloseHandle(DAT_00038f00);
            DAT_00038f00 = (HANDLE)0x0;
          }
        }
        if (DAT_00038f14 == 0) {
          pHVar3 = FindWindowW((LPCWSTR)PTR_u_MgrMcm_0003786c,(LPCWSTR)0x0);
          if (pHVar3 != (HWND)0x0) {
            PostMessageW(pHVar3,0x8064,0xb90300,1);
          }
          NKDbgPrintfW(L"[UPG] PostMSG [1] !@#+_!+@)$+)!@+$)\r\n");
          DAT_00038f14 = 1;
        }
        DAT_00037850 = 0;
        if (DAT_00038f08 != (HANDLE)0x0) {
          CloseHandle(DAT_00038f08);
        }
        DAT_00038f08 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        DAT_00038f00 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00015660,(LPVOID)0x0,0,
                                    (LPDWORD)0x0);
        DAT_00038f04 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00015880,(LPVOID)0x0,0,
                                    (LPDWORD)0x0);
      }
    }
    else if (DAT_0003785c == 0) {
      FUN_00015f48(0);
    }
    else if (DAT_0003785c == 1) {
      FUN_00016064(0);
    }
    DAT_0003785c = -1;
    if (iVar2 != -1) {
      InvalidateRect(DAT_00038efc,(RECT *)0x0,0);
    }
  }
  FUN_0002a4f0(local_2c);
  return;
}



/* 0001688c FUN_0001688c */

/* Boundary evidence: original MIPS .pdata 0001688c..00016977. Semantic name remains unreviewed. */

undefined4 FUN_0001688c(byte *param_1)

{
  HANDLE hFile;
  undefined4 uVar1;
  DWORD aDStack_28 [2];
  undefined1 auStack_20 [7];
  byte local_19;
  uint local_14;
  
  local_14 = DAT_000372d0;
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
  FUN_0002a4f0(local_14);
  return uVar1;
}



/* 00016978 FUN_00016978 */

/* Boundary evidence: original MIPS .pdata 00016978..00016a6b. Semantic name remains unreviewed. */

bool FUN_00016978(void)

{
  HANDLE hFile;
  _COMMTIMEOUTS local_48;
  _DCB _Stack_30;
  
  hFile = CreateFileW(L"COM2:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  DAT_00037854 = hFile;
  if (hFile != (HANDLE)0xffffffff) {
    memset(&local_48,0,0x14);
    GetCommState(hFile,&_Stack_30);
    _Stack_30.BaudRate = 300000;
    _Stack_30.fNull = 0;
    _Stack_30.fParity = 0;
    _Stack_30.ByteSize = '\b';
    _Stack_30.Parity = '\0';
    _Stack_30.StopBits = '\0';
    SetCommState(DAT_00037854,&_Stack_30);
    local_48.ReadIntervalTimeout = 0;
    local_48.ReadTotalTimeoutMultiplier = 0;
    local_48.ReadTotalTimeoutConstant = 0;
    local_48.WriteTotalTimeoutMultiplier = 0;
    local_48.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(DAT_00037854,&local_48);
  }
  return hFile != (HANDLE)0xffffffff;
}



/* 00016a6c FUN_00016a6c */

/* Boundary evidence: original MIPS .pdata 00016a6c..00016b6b. Semantic name remains unreviewed. */

BOOL FUN_00016a6c(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,byte param_5)

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
  
  local_c = DAT_000372d0;
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
  BVar1 = WriteFile(DAT_00037854,&local_98,((uVar3 | param_3 & 0xffff) >> 8) + 5,aDStack_a0,
                    (LPOVERLAPPED)0x0);
  FUN_0002a4f0(local_c);
  return BVar1;
}



/* 00016b6c FUN_00016b6c */

/* Boundary evidence: original MIPS .pdata 00016b6c..000170fb. Semantic name remains unreviewed. */

undefined4 FUN_00016b6c(uint param_1)

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
  
  local_30 = DAT_000372d0;
  uVar12 = 0;
  local_120[0] = 0xf0;
  local_248 = 0x128;
  hObject = (HANDLE)OpenStore(u_DSK1__000377dc);
  if (hObject != (HANDLE)0xffffffff) {
    GetStoreInfo(hObject,local_120);
    ppuVar10 = &PTR_u_PART00_000377e8 + param_1;
    hObject_00 = (HANDLE)OpenPartition(hObject,*ppuVar10);
    if (hObject_00 != (HANDLE)0xffffffff) {
      iVar2 = GetPartitionInfo(hObject_00,&local_248);
      uVar1 = local_124;
      DVar3 = GetLastError();
      iVar7 = local_140;
      NKDbgPrintfW(L"[%d] - PartitionName[%s], VolumeName[%s], snNumSectors[%d], dwAttributes 0x%04X, bPartType 0x%04X \r\n"
                   ,DVar3,auStack_244,awStack_1c4,local_140,local_13c,local_128,uVar1);
      ppuVar11 = &PTR_u_Storage_Card_000377f8 + param_1;
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
            hObject_02 = (HANDLE)OpenPartition(hObject,PTR_u_PART02_000377f0);
          }
          if (param_1 < 3) {
            hObject_01 = (HANDLE)OpenPartition(hObject,PTR_u_PART03_000377f4);
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
              if (param_1 == 3) {
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
                  NKDbgPrintfW(L"SUCCESSED VOLUME FORMAT dwFlags[%04X]dwNumFats[%d][%d]!!!\n",
                               local_250,local_254,local_260);
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
  FUN_0002a4f0(local_30);
  return uVar12;
}



/* 000170fc FUN_000170fc */

/* Boundary evidence: original MIPS .pdata 000170fc..00017453. Semantic name remains unreviewed. */

undefined4 FUN_000170fc(void)

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
  hObject = (HANDLE)OpenStore(u_DSK1__000377dc);
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
            puVar7 = (undefined4 *)((int)&PTR_u_PART00_000377e8 + uVar5);
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



/* 00017454 FUN_00017454 */

/* Boundary evidence: original MIPS .pdata 00017454..0001752f. Semantic name remains unreviewed. */

undefined4 FUN_00017454(undefined4 param_1,LPCWSTR param_2,undefined4 param_3,int param_4)

{
  HANDLE hFindFile;
  undefined4 uVar1;
  uint local_248;
  uint local_18;
  
  local_18 = DAT_000372d0;
  uVar1 = 0;
  hFindFile = FindFirstFileW(param_2,(LPWIN32_FIND_DATAW)&local_248);
  if (hFindFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"-%s- Not found... [%s]\r\n","UpgradeMgr::IsExistDirFile",param_2);
    goto LAB_0001750c;
  }
  if (param_4 == 1) {
    if ((local_248 & 0x10) != 0) {
LAB_000174d8:
      uVar1 = 1;
    }
  }
  else if ((local_248 & 0x10) == 0) goto LAB_000174d8;
  FindClose(hFindFile);
LAB_0001750c:
  FUN_0002a4f0(local_18);
  return uVar1;
}



/* 00017530 FUN_00017530 */

/* Boundary evidence: original MIPS .pdata 00017530..00017963. Semantic name remains unreviewed. */

void FUN_00017530(int param_1)

{
  HWND pHVar1;
  int iVar2;
  BOOL BVar3;
  DWORD DVar4;
  DWORD DVar5;
  wchar_t *pwVar6;
  
  DAT_00038f10 = 1;
  InvalidateRect(*(HWND *)(param_1 + 0x630),(RECT *)0x0,0);
  FUN_00019714(param_1);
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
  iVar2 = FUN_00017454(param_1,L"\\Storage Card3\\upgrade\\booter_standalone.bin",0,0);
  if (iVar2 == 1) {
    NKDbgPrintfW(L"BootLoader Upgrade Start!!       -------              ---------");
    FUN_0001a14c(param_1);
    pwVar6 = L"BootLoader Upgrade Done!!       -------              ---------";
  }
  else {
    pwVar6 = L"BootLoader Upgrade File is not found\r\n";
  }
  NKDbgPrintfW(pwVar6);
  iVar2 = FUN_00017454(param_1,L"\\Storage Card3\\upgrade\\Storage Card\\NK.bin",0,0);
  if (iVar2 == 1) {
    NKDbgPrintfW(L"[Upd Manager] NK.bin exists in SC3 \r\n");
    iVar2 = FUN_00017454(param_1,L"\\Storage Card\\NK.bin",0,0);
    if ((iVar2 == 1) &&
       (BVar3 = CopyFileW(L"\\Storage Card\\NK.bin",L"\\Storage Card\\NA.bin",0), BVar3 == 0)) {
      NKDbgPrintfW(
                  L"[Upd Manager] FAIL!!!CopyFile(_T(Storage Card\\NK.bin),_T(Storage Card\\NA.bin),TRUE)\r\n"
                  );
    }
    BVar3 = CopyFileW(L"\\Storage Card3\\upgrade\\Storage Card\\NK.bin",L"\\Storage Card\\NK.bin",0)
    ;
    if (BVar3 == 1) {
      DeleteFileW(L"\\Storage Card3\\upgrade\\Storage Card\\NK.bin");
      NKDbgPrintfW(L"[Upd Manager] NK.bin copy complete\r\n");
    }
  }
  iVar2 = FUN_00017454(param_1,L"\\Storage Card3\\upgrade\\Storage Card\\system\\UpgradeManager.exe"
                       ,0,0);
  if (iVar2 == 1) {
    MoveFileW(L"\\Storage Card\\system\\UpgradeManager.exe",
              L"\\Storage Card\\system\\OLD_UpgradeManager.exe");
    MoveFileW(L"\\Storage Card3\\upgrade\\Storage Card\\system\\UpgradeManager.exe",
              L"\\Storage Card\\system\\UpgradeManager.exe");
  }
  NKDbgPrintfW(L"[Upd Manager] [INFO] upgrade files copy complete. \r\n");
  iVar2 = wcscmp((wchar_t *)(param_1 + 0x208),L"\\MD\\upgrade_root.lgu");
  if ((iVar2 == 0) && (DVar4 = GetFileAttributesW(L"\\MD\\upgrade_root.lgu"), DVar4 != 0xffffffff))
  {
    BVar3 = DeleteFileW(L"\\MD\\upgrade_root.lgu");
    NKDbgPrintfW(L"[Upd Manager] [INFO] %s delete [%d]\r\n",L"\\MD\\upgrade_root.lgu",BVar3);
  }
  DVar4 = GetFileAttributesW(L"\\Storage card3\\upgrade\\ulc_dab_bc_LGe.bin");
  if ((DVar4 == 0xffffffff) &&
     (DVar4 = GetFileAttributesW(L"\\Storage card3\\upgrade\\ulc_dab_uc_LGe.bin"),
     DVar4 == 0xffffffff)) {
    DVar4 = GetFileAttributesW(L"\\Storage card3\\upgrade\\ulc_dab_uc_LGe.bin");
    DVar5 = GetFileAttributesW(L"\\Storage card3\\upgrade\\ulc_dab_bc_LGe.bin");
    NKDbgPrintfW(L"[Upd Manager] [INFO] DAB Firmware Not found!!![0x%08x, 0x%08x] \r\n",DVar5,DVar4)
    ;
  }
  else {
    pHVar1 = FindWindowW(L"MgrDab",(LPCWSTR)0x0);
    if (pHVar1 == (HWND)0x0) {
      NKDbgPrintfW(L"[Upd Manager] [INFO] MgrDAB Not Found!!! \r\n");
    }
    else {
      DAT_00038f1c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      NKDbgPrintfW(L"[Upd Manager] [INFO] Start DAB Firmware upgrade. \r\n");
      PostMessageW(pHVar1,0x8064,0x1100,0);
      DVar4 = WaitForSingleObject(DAT_00038f1c,900000);
      if (DVar4 == 0x102) {
        pwVar6 = L"[Upd Manager] [INFO] DAB Firmware upgrade Timeout Fail. \r\n";
      }
      else {
        pwVar6 = L"[Upd Manager] [INFO] Done DAB Firmware upgrade. \r\n";
      }
      NKDbgPrintfW(pwVar6);
      CloseHandle(DAT_00038f1c);
      DAT_00038f1c = (HANDLE)0x0;
    }
  }
  NKDbgPrintfW(L"[Upd Manager] [INFO] Start MICOM Firmware upgrade. \r\n");
  pHVar1 = FindWindowW(L"MgrMcm",(LPCWSTR)0x0);
  if (pHVar1 != (HWND)0x0) {
    PostMessageW(pHVar1,0x8064,0xc70300,0x1234);
  }
  return;
}



/* 00017964 FUN_00017964 */

/* Boundary evidence: original MIPS .pdata 00017964..00017dd3. Semantic name remains unreviewed. */

undefined4 FUN_00017964(int param_1,LPCWSTR param_2)

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
  DWORD local_92c;
  int local_928;
  int local_924;
  int local_920;
  wchar_t awStack_688 [30];
  undefined1 auStack_64c [1308];
  CHAR aCStack_130 [260];
  uint local_2c;
  
  local_2c = DAT_000372d0;
  *(undefined4 *)(param_1 + 0x62c) = 0;
  iVar10 = 0;
  bVar1 = false;
  iVar2 = FUN_00017454(param_1,param_2,0,0);
  uVar9 = 1;
  if (iVar2 != 0) {
    memset(&DAT_00038ce8,0,0x208);
    memset(&DAT_00038ae0,0,0x208);
    NKDbgPrintfW(L"[Upd Manager] [INFO] upgrade file exists. \r\n");
    pvVar3 = CreateFileW(L"\\Storage Card\\system\\Version_Info.txt",0x80000000,0,
                         (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (pvVar3 == (HANDLE)0xffffffff) {
      bVar1 = true;
      wcscpy_s((wchar_t *)&DAT_00038ce8,0x10,L"No Version Info");
    }
    else {
      ReadFile(pvVar3,aCStack_130,0x104,&local_92c,(LPOVERLAPPED)0x0);
      if (0x103 < local_92c) {
        local_92c = 0x103;
      }
      MultiByteToWideChar(0,0,aCStack_130,local_92c,(LPWSTR)&DAT_00038ce8,local_92c);
      NKDbgPrintfW(L"=====>  %s [%s][%d] <=====\r\n","UpgradeMgr::SearchUpgradeFiles",&DAT_00038ce8,
                   local_92c);
      CloseHandle(pvVar3);
    }
    pvVar3 = CreateFileW((LPCWSTR)(param_1 + 0x208),0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                         (HANDLE)0x0);
    if (pvVar3 != (HANDLE)0xffffffff) {
      ReadFile(pvVar3,&local_928,0x7f8,&local_92c,(LPOVERLAPPED)0x0);
      iVar2 = wcscmp(awStack_688,L"*MEDIA-NAV*");
      if ((((iVar2 == 0) && (local_928 == 0x3055474c)) && (local_924 == 7)) && (local_920 == 0x400))
      {
        iVar10 = 1;
      }
      iVar2 = wcscmp(awStack_688,L"*MEDIA-NAV*");
      NKDbgPrintfW(L"-=-=-=-=- [%d], %d[%s/%s] %s  [%d / %d, %d, %d, %d]=-=-=-=-\r\n",iVar10,iVar2,
                   awStack_688,L"*MEDIA-NAV*",auStack_64c,local_928,0x3055474c,local_924,local_920,
                   0x7f8);
      memcpy(&DAT_00038ae0,auStack_64c,0x28);
      CloseHandle(pvVar3);
      if (iVar10 != 0) {
        iVar2 = wcscmp((wchar_t *)&DAT_00038ae0,(wchar_t *)&DAT_00038ce8);
        if (iVar2 == 0) {
          NKDbgPrintfW(L"[Upd Manager] CUR and NEW versions are same\r\n");
        }
        else {
          iVar10 = wcscmp(param_2,L"\\MD\\upgrade_root.lgu");
          iVar4 = wcscmp((wchar_t *)&DAT_00038ae0,L"nng_content");
          iVar5 = wcscmp(param_2,L"\\MD\\navigation_restore.lgu");
          iVar6 = wcscmp(param_2,L"\\MD\\navigation_restore_fat32.lgu");
          iVar7 = wcscmp((wchar_t *)&DAT_00038ae0,L"nng_restore");
          NKDbgPrintfW(L"[Upd Manager] CUR and NEW versions are NOT same [%d][%d]... Restore [%d][%d], bNNGRestoreFile2[%d]\r\n"
                       ,iVar4,iVar10,iVar5,iVar7,iVar6);
          if (((iVar10 == 0) && (iVar4 != 0)) || (((iVar5 == 0 || (iVar6 == 0)) && (iVar7 != 0)))) {
            FUN_0002a4f0(local_2c);
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
  FUN_0002a4f0(local_2c);
  return uVar9;
}



/* 00017dd4 FUN_00017dd4 */

/* Boundary evidence: original MIPS .pdata 00017dd4..00017fdf. Semantic name remains unreviewed. */

void FUN_00017dd4(int param_1,undefined4 param_2)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_670;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d0;
  memset(awStack_238,0,0x104);
  swprintf_s(awStack_238,0x103,L"%s\\*.*",param_2);
  hFindFile = FindFirstFileW(awStack_238,&local_670);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      if ((local_670.dwFileAttributes & 0x10) == 0) {
        if ((DAT_0003784c != 0xbbd) ||
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
          FUN_00017dd4(param_1,local_670.cFileName + 0x102);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_670);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  FUN_0002a4f0(local_30);
  return;
}



/* 00017fe0 FUN_00017fe0 */

/* Boundary evidence: original MIPS .pdata 00017fe0..000181b3. Semantic name remains unreviewed. */

void FUN_00017fe0(undefined4 param_1,LPCWSTR param_2)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_670;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d0;
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
          FUN_00017fe0(param_1,local_670.cFileName + 0x102);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_670);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  RemoveDirectoryW(param_2);
  FUN_0002a4f0(local_30);
  return;
}



/* 000181b4 FUN_000181b4 */

/* Boundary evidence: original MIPS .pdata 000181b4..0001845f. Semantic name remains unreviewed. */

void FUN_000181b4(int param_1,LPCWSTR param_2,undefined4 param_3)

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
  
  local_30 = DAT_000372d0;
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
            FUN_00019714(param_1);
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
          FUN_000181b4(param_1,local_878.cFileName + 0x102,awStack_440);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_878);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  RemoveDirectoryW(param_2);
  FUN_0002a4f0(local_30);
  return;
}



/* 00018460 FUN_00018460 */

/* Boundary evidence: original MIPS .pdata 00018460..00018697. Semantic name remains unreviewed. */

void FUN_00018460(undefined4 param_1,undefined4 param_2,LPCWSTR param_3)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_878;
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d0;
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
          FUN_00018460(param_1,local_878.cFileName + 0x102,awStack_440);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_878);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  FUN_0002a4f0(local_30);
  return;
}



/* 00018698 FUN_00018698 */

/* Boundary evidence: original MIPS .pdata 00018698..000188f7. Semantic name remains unreviewed. */

void FUN_00018698(undefined4 param_1,LPCWSTR param_2,undefined4 param_3)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_878;
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d0;
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
          FUN_00018698(param_1,local_878.cFileName + 0x102,awStack_440);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_878);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  RemoveDirectoryW(param_2);
  FUN_0002a4f0(local_30);
  return;
}



/* 000188f8 FUN_000188f8 */

/* Boundary evidence: original MIPS .pdata 000188f8..00018e87. Semantic name remains unreviewed. */

void FUN_000188f8(undefined4 param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ pvVar1;
  HDC pHVar2;
  HGDIOBJ pvVar3;
  HFONT h_00;
  HGDIOBJ pvVar4;
  COLORREF color;
  UINT format;
  tagRECT local_4b0;
  LOGFONTW local_4a0;
  WCHAR aWStack_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_000372d0;
  format = 1;
  if (((DAT_0003780c == 0) || (DAT_0003780c == 0x1f)) || (DAT_0003780c == 0x15)) {
    format = 0x20001;
  }
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  pvVar1 = SelectObject(hdc,h);
  pHVar2 = CreateCompatibleDC(param_2);
  pvVar3 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_comm_0003781c)
                                   [DAT_00038ef8 * 5]);
  pvVar3 = SelectObject(pHVar2,pvVar3);
  BitBlt(hdc,0,0,800,0x1e0,pHVar2,0,0,0xcc0020);
  pvVar3 = SelectObject(pHVar2,pvVar3);
  DeleteObject(pvVar3);
  DeleteDC(pHVar2);
  memset(&local_4a0,0,0x5c);
  SetBkMode(hdc,1);
  if (DAT_00038ef8 == 2) {
    color = 0;
  }
  else {
    color = 0xffffff;
  }
  SetTextColor(hdc,color);
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
  wsprintfW(aWStack_440,L"%s : %s",&DAT_000384c4,&DAT_00038ce8);
  wsprintfW(aWStack_238,L"%s : %s",&DAT_000384c4,&DAT_00038ae0);
  local_4b0.right = 800;
  local_4b0.top = 0x15;
  local_4b0.left = 0;
  local_4b0.bottom = 0x42;
  DrawTextW(hdc,(LPCWSTR)&DAT_000388d4,-1,&local_4b0,format);
  local_4b0.top = 0x87;
  local_4b0.bottom = 0xaf;
  DrawTextW(hdc,(LPCWSTR)&DAT_000386cc,-1,&local_4b0,format);
  local_4b0.top = 0xaf;
  local_4b0.bottom = 0xd7;
  DrawTextW(hdc,aWStack_440,-1,&local_4b0,format);
  local_4b0.top = 0xff;
  local_4b0.bottom = 0x127;
  DrawTextW(hdc,(LPCWSTR)&DAT_000382bc,-1,&local_4b0,format);
  local_4b0.top = 0x127;
  local_4b0.bottom = 0x14f;
  DrawTextW(hdc,aWStack_238,-1,&local_4b0,format);
  pHVar2 = CreateCompatibleDC(param_2);
  pvVar4 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_etc__00037810)
                                   [DAT_00038ef8 * 5]);
  pvVar4 = SelectObject(pHVar2,pvVar4);
  BitBlt(hdc,0,0x1a3,0x6c,0x3d,pHVar2,0,0,0xcc0020);
  pvVar4 = SelectObject(pHVar2,pvVar4);
  DeleteObject(pvVar4);
  pvVar4 = (HGDIOBJ)SHLoadDIBitmap(*(undefined4 *)(DAT_00038ef8 * 0x14 + 0x37814));
  pvVar4 = SelectObject(pHVar2,pvVar4);
  BitBlt(hdc,0x6c,0x1a3,1,0x3d,pHVar2,0,0,0xcc0020);
  pvVar4 = SelectObject(pHVar2,pvVar4);
  DeleteObject(pvVar4);
  pvVar4 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_etc__00037818)
                                   [DAT_00038ef8 * 5]);
  pvVar4 = SelectObject(pHVar2,pvVar4);
  BitBlt(hdc,0x6d,0x1a3,0x2b3,0x3d,pHVar2,0,0,0xcc0020);
  pvVar4 = SelectObject(pHVar2,pvVar4);
  DeleteObject(pvVar4);
  local_4b0.right = 800;
  local_4b0.top = 0x1a3;
  local_4b0.left = 0x6c;
  local_4b0.bottom = 0x1e0;
  if (((DAT_0003780c == 0) || (DAT_0003780c == 0x1f)) || (DAT_0003780c == 0x15)) {
    DrawTextW(hdc,(LPCWSTR)&DAT_000380b4,-1,&local_4b0,0x20005);
  }
  else {
    DrawTextW(hdc,(LPCWSTR)&DAT_000380b4,-1,&local_4b0,5);
  }
  DeleteDC(pHVar2);
  SelectObject(hdc,pvVar3);
  DeleteObject(h_00);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  pvVar1 = SelectObject(hdc,pvVar1);
  DeleteObject(pvVar1);
  DeleteDC(hdc);
  FUN_0002a4f0(local_30);
  return;
}



/* 00018e88 FUN_00018e88 */

/* Boundary evidence: original MIPS .pdata 00018e88..00019713. Semantic name remains unreviewed. */

void FUN_00018e88(int param_1,HDC param_2)

{
  HGDIOBJ pvVar1;
  HGDIOBJ h;
  HDC hdc;
  HBITMAP h_00;
  HDC pHVar2;
  HFONT h_01;
  COLORREF color;
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
  
  local_2c = DAT_000372d0;
  pvVar1 = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_comm_0003781c)
                                   [DAT_00038ef8 * 5]);
  local_90 = pvVar1;
  h = (HGDIOBJ)SHLoadDIBitmap((&PTR_u__Storage_Card_system_Img_m0_popu_00037820)[DAT_00038ef8 * 5]);
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
  if (DAT_00038ef8 == 2) {
    color = 0;
  }
  else {
    color = 0xffffff;
  }
  SetTextColor(hdc,color);
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
  local_a8.right = 800;
  local_a8.bottom = 0x42;
  local_a8.left = 0;
  local_a8.top = 0x15;
  if (((DAT_0003780c == 0) || (DAT_0003780c == 0x1f)) || (DAT_0003780c == 0x15)) {
    DrawTextW(hdc,(LPCWSTR)&DAT_00037eac,-1,&local_a8,0x20001);
  }
  else {
    DrawTextW(hdc,(LPCWSTR)&DAT_00037eac,-1,&local_a8,1);
  }
  local_a8.top = 0x8b;
  local_a8.bottom = 0x103;
  if (((DAT_0003780c == 0) || (DAT_0003780c == 0x1f)) || (DAT_0003780c == 0x15)) {
    DrawTextW(hdc,(LPCWSTR)&DAT_00037ca4,-1,&local_a8,0x20001);
  }
  else {
    DrawTextW(hdc,(LPCWSTR)&DAT_00037ca4,-1,&local_a8,1);
  }
  SelectObject(hdc,pvVar1);
  DeleteObject(h_01);
  pHVar2 = CreateCompatibleDC(param_2);
  local_98 = SelectObject(pHVar2,h);
  if (DAT_0003784c == 0xbb9) {
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
  else if (DAT_0003784c == 0xbba) {
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
  else if (DAT_0003784c == 0xbbb) {
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
  else if (DAT_0003784c == 0xbbc) {
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
  else if (DAT_0003784c == 0xbbd) {
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
  else if (DAT_0003784c == 0xbbe) {
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
  FUN_0002a4f0(local_2c);
  return;
}



/* 00019714 FUN_00019714 */

/* Boundary evidence: original MIPS .pdata 00019714..000197a7. Semantic name remains unreviewed. */

void FUN_00019714(int param_1)

{
  if (*(int *)(param_1 + 0x628) == 2) {
    NKDbgPrintfW(L" \r\n\r\n ShowSWUpgrade     [%d]   \r\n\r\n",1);
  }
  else {
    *(undefined4 *)(param_1 + 0x628) = 2;
    SetWindowPos(*(HWND *)(param_1 + 0x630),(HWND)0xffffffff,0,0,800,0x1e0,0x10);
    ShowWindow(*(HWND *)(param_1 + 0x630),5);
  }
  InvalidateRect(*(HWND *)(param_1 + 0x630),(RECT *)0x0,0);
  return;
}



/* 000197a8 FUN_000197a8 */

/* Boundary evidence: original MIPS .pdata 000197a8..00019d47. Semantic name remains unreviewed. */

undefined4 FUN_000197a8(int param_1)

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
  
  local_30 = DAT_000372d0;
  uVar11 = 0;
  NKDbgPrintfW(L"[Upd Manager] [INFO] CALL ExtractUpdateFile() \r\n");
  _Str1 = (wchar_t *)(param_1 + 0x208);
  do {
    NKDbgPrintfW(L"[Upd Manager] [INFO] Opening LGU File\r\n");
    FUN_00012260(0x38f60);
    iVar1 = FUN_0001189c(&DAT_00038f60,_Str1,auStack_828);
    if (iVar1 != 0) {
      NKDbgPrintfW(L"[Upd Manager] [INFO] LGU Open error : %d  Path(%s)\r\n",iVar1,_Str1);
      (**(code **)(*DAT_000397dc + 0xc))();
LAB_00019cf8:
      NKDbgPrintfW(L"[Upd Manager] [INFO] Extract complete... [%d]\r\n",uVar11);
      FUN_0002a4f0(local_30);
      return uVar11;
    }
    local_838[0] = (**(code **)(PTR_PTR_000372d8 + 0xc))(&PTR_PTR_000372d8);
    local_838[0] = local_838[0] + 0x10;
    memset(auStack_888,0,0x48);
    local_840 = 0;
    local_83c = 0;
    FUN_0001246c(local_838);
    local_838[1] = 0;
    local_838[2] = 0;
    local_838[3] = 0;
    iVar1 = 0;
    NKDbgPrintfW(L"[Upd Manager] [INFO] Extract start...\r\n");
    DAT_00039878 = 1;
    _Str = (wchar_t *)(param_1 + 0x410);
    if ((DAT_00038f64 == (HANDLE)0x0) ||
       (DVar2 = WaitForSingleObject(DAT_00038f64,0), DVar2 != 0x102)) {
      memset(&DAT_00039800,0,0x48);
      DAT_00039848 = 0;
      DAT_0003984c = 0;
      FUN_0001246c(&DAT_00039850);
      DAT_00039854 = 0;
      DAT_00039858 = 0;
      DAT_0003985c = 0;
      if (_Str == (wchar_t *)0x0) {
        sVar3 = 0;
      }
      else {
        sVar3 = wcslen(_Str);
      }
      FUN_0001267c(&DAT_000397f4,_Str,sVar3);
      DAT_00039880 = 1;
      DAT_00039884 = 1;
      DAT_00039888 = 0;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00038f70);
      if ((DAT_00038f64 != (HANDLE)0x0) &&
         (DVar2 = WaitForSingleObject(DAT_00038f64,0), DVar2 == 0x102)) {
LAB_000199d4:
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00038f70);
        uVar7 = 8;
        goto LAB_000199e0;
      }
      EventModify(DAT_00038fac,2);
      EventModify(DAT_00038fb0,2);
      DAT_00038f68 = 0;
      DAT_00038f64 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001b038,&DAT_00038f60,0,
                                  &DAT_00038f6c);
      if (DAT_00038f64 == (HANDLE)0x0) goto LAB_000199d4;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00038f70);
      NKDbgPrintfW(L"[Upd Manager] [INFO] SUCCESS - Extract Start\r\n");
      iVar8 = DAT_00037850;
      iVar9 = DAT_00038f0c;
      iVar5 = local_83c;
      do {
        if (iVar8 == 1) {
          NKDbgPrintfW(L"g_bUncompresDone abort !!!! ++++++++++++++ \r\n");
          (**(code **)(*DAT_000397dc + 0xc))();
          puVar10 = (undefined4 *)(local_838[0] + -0x10);
          LVar4 = InterlockedDecrement((LONG *)(local_838[0] + -4));
          if (LVar4 < 1) {
            piVar6 = (int *)*puVar10;
            (**(code **)(*piVar6 + 4))(piVar6,puVar10);
          }
          FUN_0002a4f0(local_30);
          return 0;
        }
        if (iVar9 != 0) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00039860);
          FUN_00012148(auStack_888,&DAT_00039800);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00039860);
          iVar5 = __fptoli(local_844);
          if (iVar1 != iVar5) {
            NKDbgPrintfW(L"[Upd Manager] [INFO]  g_upgradeflag [%d], g_bUncompresDone [%d], Percent(%d) Current:%I64d   Total:%I64d\r\n"
                         ,DAT_00038f0c,DAT_00037850,iVar5,local_850 + local_860,
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
          Sleep(200);
          iVar8 = DAT_00037850;
          iVar9 = DAT_00038f0c;
        }
      } while (local_840 == 0);
      if (iVar5 == 0) {
        DAT_00038f0c = 0;
        (**(code **)(*DAT_000397dc + 0xc))();
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
        goto LAB_00019cf8;
      }
      NKDbgPrintfW(L"[Upd Manager] [ERROR]   : Extract Error ( 0x%x ) \r\n",iVar5);
      iVar1 = local_838[0];
      NKDbgPrintfW(L"[Upd Manager] [ERROR]   : %s \r\n",local_838[0]);
    }
    else {
      uVar7 = 10;
LAB_000199e0:
      NKDbgPrintfW(L"[Upd Manager] [INFO] Start failed.. lgu error code: %d\r\n",uVar7);
      (**(code **)(*DAT_000397dc + 0xc))();
      iVar1 = local_838[0];
    }
    LVar4 = InterlockedDecrement((LONG *)(iVar1 + -4));
    if (LVar4 < 1) {
      piVar6 = *(int **)(iVar1 + -0x10);
      (**(code **)(*piVar6 + 4))(piVar6,(undefined4 *)(iVar1 + -0x10));
    }
  } while( true );
}



/* 00019d48 Unwind@00019d48 */

/* Boundary evidence: original MIPS .pdata 00019d48..00019d77. Semantic name remains unreviewed. */

void Unwind_00019d48(void)

{
  int in_v0;
  
  FUN_000116e8(in_v0 + -0x888);
  return;
}



/* 00019d78 FUN_00019d78 */

/* Boundary evidence: original MIPS .pdata 00019d78..0001a14b. Semantic name remains unreviewed. */

undefined4 FUN_00019d78(void)

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
      goto LAB_0001a0c8;
    }
    if (pwVar7 < (wchar_t *)0x3e0001) {
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
        BVar3 = DeviceIoControl(DAT_00037808,0,auStack_38,0xc,(LPVOID)0x0,0,aDStack_60,
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
            goto LAB_0001a0c8;
          }
          if (local_6c == 0) {
            pwVar7 = L"Bootloader\'s update is complete\r\n";
            goto LAB_0001a0bc;
          }
          if (local_6c < 0x10000) {
            local_48 = _Dst;
            local_40 = local_6c;
            local_44 = iVar10;
            BVar3 = DeviceIoControl(DAT_00037808,1,&local_48,0xc,(LPVOID)0x0,0,(LPDWORD)&local_68,
                                    (LPOVERLAPPED)0x0);
            if (BVar3 == 0) {
              pwVar7 = L"[NORW] Writing Fail-2\r\n";
              goto LAB_0001a008;
            }
          }
          else {
            local_50 = 0x10000;
            local_58 = _Dst;
            local_54 = iVar10;
            BVar3 = DeviceIoControl(DAT_00037808,1,&local_58,0xc,(LPVOID)0x0,0,(LPDWORD)&local_64,
                                    (LPOVERLAPPED)0x0);
            if (BVar3 == 0) {
              pwVar7 = L"[NORW] Writing Fail-1\r\n";
LAB_0001a008:
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
LAB_0001a0bc:
      NKDbgPrintfW(pwVar7);
      uVar5 = 1;
      goto LAB_0001a0c8;
    }
    pwVar4 = L"The file of size is too big!! dwFileSize %d\r\n";
  }
  NKDbgPrintfW(pwVar4,pwVar7);
LAB_0001a0c8:
  free(_Dst);
  if (hFile != (HANDLE)0xffffffff) {
    CloseHandle(hFile);
  }
  return uVar5;
}



/* 0001a14c FUN_0001a14c */

/* Boundary evidence: original MIPS .pdata 0001a14c..0001a3a3. Semantic name remains unreviewed. */

int FUN_0001a14c(int param_1)

{
  bool bVar1;
  bool bVar2;
  HDC hDC;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  hDC = GetDC((HWND)0x0);
  DAT_0003784c = 0xbba;
  if (DAT_00037808 == (HANDLE)0xffffffff) {
    DAT_00037808 = CreateFileW(L"PHM1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (DAT_00037808 != (HANDLE)0xffffffff) {
      pwVar3 = L"[NORW] NOR flash driver\r\n";
      goto LAB_0001a210;
    }
    NKDbgPrintfW(L"[NORW] can\'t open NOR flash driver\r\n");
    bVar2 = false;
  }
  else {
    pwVar3 = L"[NORW] NOR flash driver is already opened\r\n";
LAB_0001a210:
    NKDbgPrintfW(pwVar3);
    bVar2 = true;
  }
  if (*(int *)(param_1 + 0x628) == 1) {
    FUN_000188f8(param_1,hDC);
  }
  else if (*(int *)(param_1 + 0x628) == 2) {
    FUN_00018e88(param_1,hDC);
  }
  if (bVar2) {
    DAT_0003784c = 0xbbb;
    if (*(int *)(param_1 + 0x628) == 1) {
      FUN_000188f8(param_1,hDC);
    }
    else if (*(int *)(param_1 + 0x628) == 2) {
      FUN_00018e88(param_1,hDC);
    }
    iVar5 = 0;
    do {
      iVar4 = FUN_00019d78();
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
      DAT_0003784c = 0xbbc;
      if (*(int *)(param_1 + 0x628) == 1) {
        FUN_000188f8(param_1,hDC);
        goto LAB_0001a334;
      }
      if (*(int *)(param_1 + 0x628) == 2) {
        FUN_00018e88(param_1,hDC);
      }
    }
  }
  else {
LAB_0001a334:
    if (!bVar2) goto LAB_0001a368;
  }
  if (DAT_00037808 != (HANDLE)0xffffffff) {
    CloseHandle(DAT_00037808);
    DAT_00037808 = (HANDLE)0xffffffff;
  }
LAB_0001a368:
  ReleaseDC((HWND)0x0,hDC);
  return iVar4;
}



/* 0001a3a4 FUN_0001a3a4 */

/* Boundary evidence: original MIPS .pdata 0001a3a4..0001a7ff. Semantic name remains unreviewed. */

undefined4 FUN_0001a3a4(int param_1,int param_2,int param_3)

{
  HANDLE hObject;
  HANDLE hObject_00;
  int iVar1;
  DWORD DVar2;
  HMODULE hLibModule;
  code *pcVar3;
  int iVar4;
  wchar_t *pwVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined **ppuVar8;
  undefined4 uVar9;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  uint local_250;
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
  
  local_30 = DAT_000372d0;
  local_120[0] = 0xf0;
  uVar7 = 0;
  local_248 = 0x128;
  hObject = (HANDLE)OpenStore(u_DSK1__000377dc);
  if (hObject != (HANDLE)0x0) {
    GetStoreInfo(hObject,local_120);
    ppuVar8 = &PTR_u_PART00_000377e8 + param_1;
    hObject_00 = (HANDLE)OpenPartition(hObject,*ppuVar8);
    if (hObject_00 != (HANDLE)0x0) {
      iVar1 = GetPartitionInfo(hObject_00,&local_248);
      uVar6 = (uint)local_124;
      DVar2 = GetLastError();
      uVar9 = local_13c;
      NKDbgPrintfW(L"[%d] - PartitionName[%s]VolumeName[%s], snNumSectors[%d], dwAttributes 0x%04X, bPartType 0x%04X \r\n"
                   ,DVar2,auStack_244,auStack_1c4,local_140,local_13c,local_128,uVar6);
      if (iVar1 == 1) {
        DVar2 = GetLastError();
        NKDbgPrintfW(L"[%s], [%s] [%d][%d]\r\n",auStack_244,auStack_1c4,1,DVar2,uVar9,local_128,
                     uVar6);
        iVar1 = _wcsicmp(awStack_204,L"FATFSD.DLL");
        if (((iVar1 == 0) || (iVar1 = _wcsicmp(awStack_204,L"EXFAT.DLL"), iVar1 == 0)) &&
           (hLibModule = LoadLibraryW(L"FATUTIL.DLL"), hLibModule != (HMODULE)0x0)) {
          pcVar3 = (code *)GetProcAddressW(hLibModule,L"FormatVolume");
          if (pcVar3 == (code *)0x0) {
            uVar7 = 0;
          }
          else {
            uVar6 = 0;
            local_250 = 0;
            if (param_1 == 3) {
              local_260 = 0x2000;
            }
            else {
              local_260 = 0x200;
            }
            local_25c = 0x200;
            local_254 = 1;
            local_258 = 0x20;
            if (param_2 != 0) {
              uVar6 = 0x10;
              local_258 = 0x40;
              local_250 = 0x10;
            }
            if (param_3 != 0) {
              local_250 = uVar6 | 2;
              local_254 = 2;
            }
            iVar1 = DismountPartition(hObject_00);
            if (iVar1 == 1) {
              pwVar5 = L"SUCCESSED DismountPartition() [%s][%s]!!!\n";
            }
            else {
              pwVar5 = L"Failed DismountPartition() [%s][%s]!!!\n";
            }
            NKDbgPrintfW(pwVar5,auStack_244,auStack_1c4);
            iVar1 = (*pcVar3)(hObject_00,0,&local_260,0,0);
            if (iVar1 == 0) {
              NKDbgPrintfW(L"SUCCESSED VOLUME FORMAT dwFlags[%04X]dwNumFats[%d][%d]!!!\n",local_250,
                           local_254,local_260);
            }
            else {
              DVar2 = GetLastError();
              NKDbgPrintfW(L"FAILED VOLUME FORMAT !!![%d][%d] / dwFlags[%04X]dwNumFats[%d]!!!\n",
                           iVar1,DVar2,local_250,local_254);
              CloseHandle(hObject_00);
              uVar7 = DeletePartition(hObject,*ppuVar8);
              NKDbgPrintfW(L"!!!===> DeletePartition[%d] <===!!!\n",uVar7);
              uVar7 = CreatePartition(hObject,*ppuVar8,local_140,local_13c);
              NKDbgPrintfW(L"!!!===> CreatePartition[%d] <===!!!\n",uVar7);
              hObject_00 = (HANDLE)OpenPartition(hObject,*ppuVar8);
              if (hObject_00 == (HANDLE)0xffffffff) {
                NKDbgPrintfW(L"Cannot open [%s] partition\n",*ppuVar8);
              }
              else {
                GetPartitionInfo(hObject_00,&local_248);
                uVar7 = DismountPartition(hObject_00);
                NKDbgPrintfW(L"**** DismountPartition[%d]**** \r\n",uVar7);
                uVar7 = FormatPartition(hObject_00);
                NKDbgPrintfW(L"**** FormatPartition[%d]**** \r\n",uVar7);
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
            uVar7 = 1;
          }
          FreeLibrary(hLibModule);
        }
      }
      CloseHandle(hObject_00);
    }
    CloseHandle(hObject);
  }
  FUN_0002a4f0(local_30);
  return uVar7;
}



/* 0001a800 FUN_0001a800 */

void FUN_0001a800(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_000346d8;
  return;
}



/* 0001a874 FUN_0001a874 */

/* Boundary evidence: original MIPS .pdata 0001a874..0001a8bb. Semantic name remains unreviewed. */

void FUN_0001a874(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  uVar1 = __ll_rem(param_3 - uVar2,(param_4 - ((int)uVar2 >> 0x1f)) - (uint)(param_3 < uVar2),0x400,
                   0);
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}



/* 0001a8bc FUN_0001a8bc */

/* Boundary evidence: original MIPS .pdata 0001a8bc..0001a8ff. Semantic name remains unreviewed. */

undefined4 * FUN_0001a8bc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_000346d8;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001a900 FUN_0001a900 */

uint FUN_0001a900(uint param_1,byte *param_2,uint param_3)

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
        uVar1 = *(uint *)(&DAT_0002e1c8 + ((*param_2 ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e1c8 + ((param_2[1] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e1c8 + ((param_2[2] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e1c8 + ((param_2[3] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e1c8 + ((param_2[4] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e1c8 + ((param_2[5] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e1c8 + ((param_2[6] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        uVar1 = *(uint *)(&DAT_0002e1c8 + ((param_2[7] ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
        param_2 = param_2 + 8;
        uVar2 = uVar2 - 1;
        param_3 = param_3 - 8;
      } while (uVar2 != 0);
    }
    for (; param_3 != 0; param_3 = param_3 - 1) {
      uVar1 = *(uint *)(&DAT_0002e1c8 + ((*param_2 ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
      param_2 = param_2 + 1;
    }
    uVar1 = ~uVar1;
  }
  return uVar1;
}



/* 0001aa94 FUN_0001aa94 */

/* Boundary evidence: original MIPS .pdata 0001aa94..0001ac37. Semantic name remains unreviewed. */

undefined4 FUN_0001aa94(LPCWSTR param_1,int *param_2)

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
    if (*param_2 != 0x3055474c) {
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
      FUN_0001b2f4(0x3466c,lpFileSizeHigh,param_2[3],(va_list)param_2[4]);
    }
    CloseHandle(hFile);
  }
  return uVar3;
}



/* 0001ac38 FUN_0001ac38 */

/* Boundary evidence: original MIPS .pdata 0001ac38..0001ad77. Semantic name remains unreviewed. */

void * FUN_0001ac38(void *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  *(undefined ***)((int)param_1 + 0x7fc) = &PTR_LAB_000346d8;
  *(undefined4 *)((int)param_1 + 0x800) = 0;
  *(undefined4 *)((int)param_1 + 0x804) = 0;
  *(undefined4 *)((int)param_1 + 0x808) = 0;
  puVar3 = (undefined4 *)__2_YAPAXI_Z(0x58);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_000348ec;
    puVar3[0xf] = &PTR_FUN_000348e4;
    puVar3[0x10] = 0;
    puVar3[0x11] = 0;
    puVar3[0x12] = 0;
    puVar3[0x13] = 4;
    puVar3[10] = 0xffffffff;
    puVar3[0xb] = 0xffffffff;
    puVar3[2] = 0;
    puVar3[6] = 0;
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[7] = 0;
    puVar3[0xc] = 0;
    puVar3[0xd] = 0;
    puVar3[0xe] = 0;
    puVar3[1] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[0x14] = 0;
    puVar3[5] = FUN_0001e17c;
  }
  *(undefined4 **)((int)param_1 + 0x7f8) = puVar3;
  memset(param_1,0,0x7f8);
  puVar3 = (undefined4 *)&DAT_000373dc;
  uVar4 = 0;
  do {
    uVar1 = *(undefined1 *)((int)puVar3 + 2);
    uVar2 = *(undefined1 *)((int)puVar3 + 1);
    uVar6 = *puVar3;
    uVar5 = uVar4 + 4;
    (&DAT_000373df)[uVar4] = *(undefined1 *)((int)puVar3 + 3);
    puVar3 = puVar3 + 1;
    (&DAT_000373de)[uVar4] = uVar1;
    (&DAT_000373dd)[uVar4] = uVar2;
    (&DAT_000373dc)[uVar4] = (char)uVar6;
    uVar4 = uVar5;
  } while (uVar5 < 0x400);
  return param_1;
}



/* 0001ad78 Unwind@0001ad78 */

/* Boundary evidence: original MIPS .pdata 0001ad78..0001adab. Semantic name remains unreviewed. */

void Unwind_0001ad78(void)

{
  int *in_v0;
  
  FUN_0001a800((undefined4 *)(*in_v0 + 0x7fc));
  return;
}



/* 0001adac FUN_0001adac */

/* Boundary evidence: original MIPS .pdata 0001adac..0001ae17. Semantic name remains unreviewed. */

void FUN_0001adac(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x7f8) + 0xc))();
  (**(code **)**(undefined4 **)(param_1 + 0x7f8))();
  *(undefined4 *)(param_1 + 0x7f8) = 0;
  *(undefined ***)(param_1 + 0x7fc) = &PTR_LAB_000346d8;
  return;
}



/* 0001ae18 Unwind@0001ae18 */

/* Boundary evidence: original MIPS .pdata 0001ae18..0001ae4b. Semantic name remains unreviewed. */

void Unwind_0001ae18(void)

{
  int *in_v0;
  
  FUN_0001a800((undefined4 *)(*in_v0 + 0x7fc));
  return;
}



/* 0001ae4c FUN_0001ae4c */

/* Boundary evidence: original MIPS .pdata 0001ae4c..0001af5b. Semantic name remains unreviewed. */

int FUN_0001ae4c(int *param_1,LPCWSTR param_2)

{
  int iVar1;
  
  (**(code **)(*(int *)param_1[0x1fe] + 0xc))();
  iVar1 = FUN_0001aa94(param_2,param_1);
  if (iVar1 == 0) {
    param_1[0x200] = 0;
    param_1[0x201] = 0;
    param_1[0x202] = 0;
    param_1[0x200] = param_1[5];
    param_1[0x202] = 0x400;
    (**(code **)(*(int *)param_1[0x1fe] + 0x60))();
    iVar1 = (**(code **)(*(int *)param_1[0x1fe] + 4))((int *)param_1[0x1fe],param_2,&UNK_000346bc);
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



/* 0001af5c FUN_0001af5c */

/* Boundary evidence: original MIPS .pdata 0001af5c..0001afa7. Semantic name remains unreviewed. */

undefined4 * FUN_0001af5c(undefined4 *param_1,uint param_2)

{
  FUN_0001afa8(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001afa8 FUN_0001afa8 */

/* Boundary evidence: original MIPS .pdata 0001afa8..0001b037. Semantic name remains unreviewed. */

void FUN_0001afa8(undefined4 *param_1)

{
  HANDLE hHandle;
  
  *param_1 = &PTR_LAB_00034718;
  hHandle = (HANDLE)InterlockedExchange(param_1 + 1,0);
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
    CloseHandle(hHandle);
  }
  FUN_0001b224(param_1 + 0x19);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 9));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



/* 0001b038 FUN_0001b038 */

/* Boundary evidence: original MIPS .pdata 0001b038..0001b0e3. Semantic name remains unreviewed. */

undefined4 FUN_0001b038(undefined4 *param_1)

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



/* 0001b0e4 FUN_0001b0e4 */

/* Boundary evidence: original MIPS .pdata 0001b0e4..0001b223. Semantic name remains unreviewed. */

undefined4 FUN_0001b0e4(int param_1)

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
          goto LAB_0001b1d8;
        }
      } while ((*(HANDLE *)(param_1 + 4) != (HANDLE)0x0) &&
              (DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 4),0), DVar1 == 0x102));
      uVar2 = 0x80004005;
LAB_0001b1d8:
      LeaveCriticalSection(lpCriticalSection);
      return uVar2;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0x80004005;
}



/* 0001b224 FUN_0001b224 */

/* Boundary evidence: original MIPS .pdata 0001b224..0001b2bb. Semantic name remains unreviewed. */

void FUN_0001b224(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = param_1[2];
  do {
    if (iVar2 == 0) {
LAB_0001b280:
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
      goto LAB_0001b280;
    }
    *param_1 = *puVar1;
    FUN_0001b2bc((int)param_1,puVar1);
    iVar2 = param_1[2];
  } while( true );
}



/* 0001b2bc FUN_0001b2bc */

/* Boundary evidence: original MIPS .pdata 0001b2bc..0001b2f3. Semantic name remains unreviewed. */

void FUN_0001b2bc(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 **)(param_1 + 0x10) = param_2;
  iVar1 = *(int *)(param_1 + 8) + -1;
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_0001b224((undefined4 *)param_1);
  }
  return;
}



/* 0001b2f4 FUN_0001b2f4 */

/* Boundary evidence: original MIPS .pdata 0001b2f4..0001b5c3. Semantic name remains unreviewed. */

void FUN_0001b2f4(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

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
  
  local_20 = DAT_000372d0;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf(awStack_2020,param_1,(wchar_t *)&local_res4,param_4);
  local_24a8 = auStack_24a4;
  FUN_0001b624((int *)&local_24a8,awStack_2020);
  iVar1 = (**(code **)(PTR_PTR_000372d8 + 0xc))(&PTR_PTR_000372d8);
  local_24bc = (wchar_t *)(iVar1 + 0x10);
  GetLocalTime(&local_24b8);
  sprintf_s(acStack_2420,0x400,"%d-%02d-%02d %02d-%02d-%02d [%s]",(uint)local_24b8.wYear,
            (uint)local_24b8.wMonth,(uint)local_24b8.wDay,(uint)local_24b8.wHour,
            (uint)local_24b8.wMinute,(uint)local_24b8.wSecond,&DAT_0002e908);
  uVar4 = (uint)local_24b8.wDay;
  FUN_0001b78c((int *)&local_24bc,L"%s\\ark_log%04d%02d%02d.txt",L"\\MD\\",(uint)local_24b8.wYear);
  pwVar6 = local_24bc;
  _wfopen_s(&local_24c0,local_24bc,L"a+");
  if (local_24c0 == (FILE *)0x0) {
    FUN_0001b78c((int *)&local_24bc,L"%s\\ark_log%04d%02d%02d.txt",L"\\Hard Disk\\",
                 (uint)local_24b8.wYear);
    pwVar6 = local_24bc;
    _wfopen_s(&local_24c0,local_24bc,L"a+");
    if (local_24c0 == (FILE *)0x0) {
      FUN_0001b78c((int *)&local_24bc,L"%s\\ark_log%04d%02d%02d.txt",L"\\Storage Card2\\",
                   (uint)local_24b8.wYear);
      pwVar6 = local_24bc;
      _wfopen_s(&local_24c0,local_24bc,L"a+");
      if (local_24c0 == (FILE *)0x0) {
        FUN_00012534((int *)&local_24bc);
        if (local_24a8 != auStack_24a4) {
          free(local_24a8);
        }
        goto LAB_0001b598;
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
LAB_0001b598:
  FUN_0002a4f0(local_20);
  return;
}



/* 0001b5c4 Unwind@0001b5c4 */

/* Boundary evidence: original MIPS .pdata 0001b5c4..0001b5f3. Semantic name remains unreviewed. */

void Unwind_0001b5c4(void)

{
  int in_v0;
  
  FUN_0001da4c((undefined4 *)(in_v0 + -0x24a8));
  return;
}



/* 0001b5f4 Unwind@0001b5f4 */

/* Boundary evidence: original MIPS .pdata 0001b5f4..0001b623. Semantic name remains unreviewed. */

void Unwind_0001b5f4(void)

{
  int in_v0;
  
  FUN_00012534((int *)(in_v0 + -0x24bc));
  return;
}



/* 0001b624 FUN_0001b624 */

/* Boundary evidence: original MIPS .pdata 0001b624..0001b78b. Semantic name remains unreviewed. */

void FUN_0001b624(int *param_1,LPCWSTR param_2)

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
    FUN_0001b7b4(param_1,cchWideChar << 2,param_1 + 1);
    iVar2 = WideCharToMultiByte(0x3b5,0,param_2,cchWideChar,(LPSTR)*param_1,cchWideChar << 2,
                                (LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      if (DVar3 == 0x7a) {
        cbMultiByte = WideCharToMultiByte(0x3b5,0,param_2,cchWideChar,(LPSTR)0x0,0,(LPCSTR)0x0,
                                          (LPBOOL)0x0);
        FUN_0001b7b4(param_1,cbMultiByte,param_1 + 1);
        iVar2 = WideCharToMultiByte(0x3b5,0,param_2,cchWideChar,(LPSTR)*param_1,cbMultiByte,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar2 != 0) {
          return;
        }
      }
      FUN_0001bb24();
    }
  }
  return;
}



/* 0001b78c FUN_0001b78c */

/* Boundary evidence: original MIPS .pdata 0001b78c..0001b7b3. Semantic name remains unreviewed. */

void FUN_0001b78c(int *param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res8 = param_3;
  local_resc = param_4;
  FUN_0001b898(param_1,param_2,(va_list)&local_res8);
  return;
}



/* 0001b7b4 FUN_0001b7b4 */

/* Boundary evidence: original MIPS .pdata 0001b7b4..0001b897. Semantic name remains unreviewed. */

void FUN_0001b7b4(int *param_1,size_t param_2,void *param_3)

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
      goto LAB_0001b850;
    }
  }
  else {
    if (0x80 < (int)param_2) {
      pvVar1 = _recalloc(pvVar1,param_2,1);
      if (pvVar1 == (void *)0x0) {
        pvVar1 = (void *)FUN_00011314(0x8007000e);
      }
      *param_1 = (int)pvVar1;
      goto LAB_0001b850;
    }
    free(pvVar1);
  }
  *param_1 = (int)param_3;
LAB_0001b850:
  if (*param_1 == 0) {
    FUN_00011314(0x8007000e);
  }
  return;
}



/* 0001b898 FUN_0001b898 */

/* Boundary evidence: original MIPS .pdata 0001b898..0001b9af. Semantic name remains unreviewed. */

void FUN_0001b898(int *param_1,wchar_t *param_2,va_list param_3)

{
  int iVar1;
  wchar_t awStack_828 [1024];
  undefined2 local_28;
  uint local_20;
  
  local_20 = DAT_000372d0;
  if (param_2 == (wchar_t *)0x0) {
    FUN_00011314(0x80070057);
  }
  iVar1 = _vsnwprintf(awStack_828,0x400,param_2,param_3);
  if (iVar1 < 0) {
    iVar1 = 0x400;
  }
  local_28 = 0;
  if ((int)(1U - *(int *)(*param_1 + -4) | *(int *)(*param_1 + -8) - iVar1) < 0) {
    FUN_0001288c(param_1,iVar1);
  }
  FUN_0001b9b0((wchar_t *)*param_1,iVar1 + 1,param_2,param_3);
  if ((iVar1 < 0) || (*(int *)(*param_1 + -8) < iVar1)) {
    FUN_00011314(0x80070057);
  }
  else {
    *(int *)(*param_1 + -0xc) = iVar1;
    *(undefined2 *)(iVar1 * 2 + *param_1) = 0;
    FUN_0002a4f0(local_20);
  }
  return;
}



/* 0001b9b0 FUN_0001b9b0 */

/* Boundary evidence: original MIPS .pdata 0001b9b0..0001ba97. Semantic name remains unreviewed. */

uint FUN_0001b9b0(wchar_t *param_1,uint param_2,wchar_t *param_3,va_list param_4)

{
  wchar_t wVar1;
  uint uVar2;
  errno_t eVar3;
  wchar_t *pwVar4;
  wchar_t local_820 [1024];
  undefined2 local_20;
  uint local_18;
  
  local_18 = DAT_000372d0;
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
  FUN_0001ba98(eVar3);
  FUN_0002a4f0(local_18);
  return uVar2;
}



/* 0001ba98 FUN_0001ba98 */

/* Boundary evidence: original MIPS .pdata 0001ba98..0001bb23. Semantic name remains unreviewed. */

undefined4 FUN_0001ba98(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x17) {
    if (param_1 == 0x16) goto LAB_0001bb0c;
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 != 0xc) goto LAB_0001baf0;
    param_1 = -0x7ff8fff2;
    FUN_00011314(0x8007000e);
  }
  if (param_1 != 0x22) {
    if (param_1 == 0x50) {
      return 0x50;
    }
LAB_0001baf0:
    uVar1 = 0x80004005;
    FUN_00011314(0x80004005);
    return uVar1;
  }
LAB_0001bb0c:
  uVar1 = FUN_00011314(0x80070057);
  return uVar1;
}



/* 0001bb24 FUN_0001bb24 */

/* Boundary evidence: original MIPS .pdata 0001bb24..0001bb67. Semantic name remains unreviewed. */

void FUN_0001bb24(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  FUN_00011314(DVar1);
  return;
}



/* 0001bb88 FUN_0001bb88 */

/* Boundary evidence: original MIPS .pdata 0001bb88..0001bba3. Semantic name remains unreviewed. */

void FUN_0001bb88(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 0001bba4 FUN_0001bba4 */

/* Boundary evidence: original MIPS .pdata 0001bba4..0001bc17. Semantic name remains unreviewed. */

LONG FUN_0001bba4(int *param_1)

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



/* 0001bc18 FUN_0001bc18 */

/* Boundary evidence: original MIPS .pdata 0001bc18..0001bc47. Semantic name remains unreviewed. */

void FUN_0001bc18(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  (**(code **)**(undefined4 **)(param_1 + 8))();
  return;
}



/* 0001bc48 FUN_0001bc48 */

/* Boundary evidence: original MIPS .pdata 0001bc48..0001bccf. Semantic name remains unreviewed. */

undefined4 FUN_0001bc48(int param_1,undefined4 param_2,uint param_3,uint *param_4)

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



/* 0001bcd0 FUN_0001bcd0 */

/* Boundary evidence: original MIPS .pdata 0001bcd0..0001bcf7. Semantic name remains unreviewed. */

void FUN_0001bcd0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))();
  return;
}



/* 0001bcf8 FUN_0001bcf8 */

/* Boundary evidence: original MIPS .pdata 0001bcf8..0001bd1f. Semantic name remains unreviewed. */

void FUN_0001bcf8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 0xc))();
  return;
}



/* 0001bd34 FUN_0001bd34 */

/* Boundary evidence: original MIPS .pdata 0001bd34..0001bd93. Semantic name remains unreviewed. */

undefined4 * FUN_0001bd34(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00034950;
  (**(code **)(*(int *)param_1[2] + 8))();
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001bd94 FUN_0001bd94 */

/* Boundary evidence: original MIPS .pdata 0001bd94..0001be3f. Semantic name remains unreviewed. */

int * FUN_0001bd94(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)__2_YAPAXI_Z(0x18);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 0;
    *piVar1 = (int)&PTR_FUN_00034950;
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



/* 0001be40 FUN_0001be40 */

/* Boundary evidence: original MIPS .pdata 0001be40..0001be93. Semantic name remains unreviewed. */

void FUN_0001be40(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000348e4;
  FUN_0001df24((int)param_1,0,param_1[2]);
  __3_YAXPAX_Z(param_1[3]);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}



/* 0001be94 FUN_0001be94 */

/* Boundary evidence: original MIPS .pdata 0001be94..0001beb7. Semantic name remains unreviewed. */

void FUN_0001be94(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_0001beb8(param_1);
  }
  return;
}



/* 0001beb8 FUN_0001beb8 */

/* Boundary evidence: original MIPS .pdata 0001beb8..0001bf53. Semantic name remains unreviewed. */

undefined4 * FUN_0001beb8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000348ec;
  FUN_0001ce24((int)param_1);
  param_1[0xf] = &PTR_FUN_000348e4;
  FUN_0001df24((int)(param_1 + 0xf),0,param_1[0x11]);
  __3_YAXPAX_Z(param_1[0x12]);
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  __3_YAXPAX_Z(param_1);
  return param_1;
}



/* 0001bf54 Unwind@0001bf54 */

/* Boundary evidence: original MIPS .pdata 0001bf54..0001bf87. Semantic name remains unreviewed. */

void Unwind_0001bf54(void)

{
  int *in_v0;
  
  FUN_0001be40((undefined4 *)(*in_v0 + 0x3c));
  return;
}



/* 0001bf88 FUN_0001bf88 */

/* Boundary evidence: original MIPS .pdata 0001bf88..0001c29b. Semantic name remains unreviewed. */

int FUN_0001bf88(undefined4 param_1,int *param_2,wchar_t *param_3)

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
  
  local_28 = DAT_000372d0;
  (**(code **)(*param_2 + 0x20))(param_2);
  iVar1 = (**(code **)(*param_2 + 0x14))(param_2,&local_460,0x14);
  if (iVar1 == 0) {
LAB_0001c28c:
    FUN_0002a4f0(local_28);
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0001c384(param_1,&local_460);
    if (iVar1 == 0) {
      if ((local_460 != 'M') || (local_45f != 'Z')) {
        if (param_3 != (wchar_t *)0x0) {
          iVar1 = _wcsnicmp(param_3,L".tar",4);
          if (iVar1 == 0) {
            FUN_0002a4f0(local_28);
            return 7;
          }
          iVar1 = _wcsnicmp(param_3,L".iso",4);
          if (((((iVar1 == 0) && (lVar3 = (**(code **)(*param_2 + 0x1c))(param_2), lVar3 == 0x8000))
               && (iVar1 = (**(code **)(*param_2 + 0x14))(param_2,&local_460,0x14), iVar1 != 0)) &&
              (((local_460 == '\x01' && (local_45f == 'C')) &&
               ((local_45e == 'D' && ((local_45d == '0' && (local_45c == '0')))))))) &&
             ((char)local_45b == '1')) {
            FUN_0002a4f0(local_28);
            return 9;
          }
          iVar1 = _wcsnicmp(param_3,L".001",4);
          if (iVar1 == 0) goto LAB_0001c040;
        }
        uVar4 = 0;
        (**(code **)(*param_2 + 0x1c))(param_2);
        iVar1 = (**(code **)(*param_2 + 0x14))(param_2,acStack_448,0x41e,*param_2,uVar4);
        if (iVar1 != 0) {
          iVar2 = 0;
          do {
            iVar1 = FUN_0001c384(param_1,acStack_448 + iVar2);
            if (iVar1 != 0) goto LAB_0001c094;
            iVar2 = iVar2 + 1;
          } while (iVar2 < 0x40a);
        }
        goto LAB_0001c28c;
      }
      iVar1 = FUN_0001c830(param_1,param_2);
    }
    else if (iVar1 == 6) {
      if ((param_3 != (wchar_t *)0x0) && (iVar2 = _wcsnicmp(param_3,L".001",4), iVar2 == 0)) {
LAB_0001c040:
        FUN_0002a4f0(local_28);
        return 10;
      }
    }
    else if (((iVar1 == 4) && (local_45b == 7)) &&
            (iVar2 = FUN_0001c29c((int)&local_460,param_3), iVar2 != 0)) {
      iVar1 = 5;
    }
LAB_0001c094:
    FUN_0002a4f0(local_28);
  }
  return iVar1;
}



/* 0001c29c FUN_0001c29c */

undefined4 FUN_0001c29c(int param_1,short *param_2)

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



/* 0001c384 FUN_0001c384 */

/* Boundary evidence: original MIPS .pdata 0001c384..0001c82f. Semantic name remains unreviewed. */

undefined4 FUN_0001c384(undefined4 param_1,char *param_2)

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
  
  local_20 = DAT_000372d0;
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
    FUN_0002a4f0(DAT_000372d0);
    uVar4 = 1;
  }
  else if ((((cVar1 == 'A') && (param_2[1] == 'L')) && (param_2[2] == 'Z')) &&
          (param_2[3] == '\x01')) {
    FUN_0002a4f0(DAT_000372d0);
    uVar4 = 2;
  }
  else if (((cVar1 == 'R') && (param_2[1] == 'a')) && ((param_2[2] == 'r' && (param_2[3] == '!'))))
  {
    FUN_0002a4f0(DAT_000372d0);
  }
  else if (((cVar1 == '7') && (param_2[1] == 'z')) &&
          ((param_2[2] == -0x44 &&
           (((param_2[3] == -0x51 && (param_2[4] == '\'')) && (param_2[5] == '\x1c')))))) {
    FUN_0002a4f0(DAT_000372d0);
    uVar4 = 6;
  }
  else if (((cVar1 == 'H') && (param_2[1] == 'V')) && ((param_2[2] == '3' && (param_2[3] == '0'))))
  {
    FUN_0002a4f0(DAT_000372d0);
    uVar4 = 0xb;
  }
  else {
    cVar2 = param_2[2];
    if ((((cVar2 == '-') && (param_2[3] == 'l')) && (param_2[4] == 'h')) && (param_2[6] == '-')) {
      FUN_0002a4f0(DAT_000372d0);
      uVar4 = 3;
    }
    else if ((((cVar1 == 'M') && (param_2[1] == 'S')) && (cVar2 == 'C')) && (param_2[3] == 'F')) {
      FUN_0002a4f0(DAT_000372d0);
      uVar4 = 8;
    }
    else if (((cVar1 == '\x1f') && (param_2[1] == -0x75)) && (cVar2 == '\b')) {
      FUN_0002a4f0(DAT_000372d0);
      uVar4 = 0xc;
    }
    else {
      if (cVar1 == 'B') {
        if ((param_2[1] == 'Z') && (cVar2 == 'h')) {
          FUN_0002a4f0(DAT_000372d0);
          return 0xd;
        }
        if (((param_2[1] == 'H') && (cVar2 == '\x05')) && (param_2[3] == '\a')) {
          FUN_0002a4f0(DAT_000372d0);
          return 0xf;
        }
      }
      if (((cVar1 == 'E') && (param_2[1] == 'G')) && ((cVar2 == 'G' && (param_2[3] == 'A')))) {
        FUN_0002a4f0(DAT_000372d0);
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
          FUN_0002a4f0(local_20);
          uVar4 = 0xe;
        }
        else {
          FUN_0002a4f0(local_20);
          uVar4 = 0;
        }
      }
    }
  }
  return uVar4;
}



/* 0001c830 FUN_0001c830 */

/* WARNING: Removing unreachable block (ram,0x0001c8b8) */
/* Boundary evidence: original MIPS .pdata 0001c830..0001c973. Semantic name remains unreviewed. */

int FUN_0001c830(undefined4 param_1,int *param_2)

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
          iVar1 = FUN_0001c384(param_1,(char *)(iVar2 + (int)_Memory));
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



/* 0001c974 FUN_0001c974 */

/* Boundary evidence: original MIPS .pdata 0001c974..0001ca17. Semantic name remains unreviewed. */

undefined4 FUN_0001c974(int *param_1,LPCSTR param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *local_118;
  undefined1 auStack_114 [256];
  uint local_14;
  
  local_14 = DAT_000372d0;
  local_118 = auStack_114;
  FUN_0001dbc4((int *)&local_118,param_2,param_1[0xe]);
  uVar1 = (**(code **)(*param_1 + 4))(param_1,local_118,param_3);
  if (local_118 != auStack_114) {
    free(local_118);
  }
  FUN_0002a4f0(local_14);
  return uVar1;
}



/* 0001ca18 Unwind@0001ca18 */

/* Boundary evidence: original MIPS .pdata 0001ca18..0001ca47. Semantic name remains unreviewed. */

void Unwind_0001ca18(void)

{
  int in_v0;
  
  FUN_0001da4c((undefined4 *)(in_v0 + -0x118));
  return;
}



/* 0001ca48 FUN_0001ca48 */

/* Boundary evidence: original MIPS .pdata 0001ca48..0001cb2b. Semantic name remains unreviewed. */

undefined4 FUN_0001ca48(int *param_1,wchar_t *param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  (**(code **)(*param_1 + 0xc))(param_1);
  param_1[0xd] = 0;
  piVar1 = FUN_0001f09c(param_2);
  if (piVar1 == (int *)0x0) {
    param_1[0xd] = 1;
    uVar2 = 0;
  }
  else {
    iVar3 = (**(code **)*piVar1)(piVar1,&DAT_0002e198,param_1 + 1);
    if (iVar3 < 0) {
      __3_YAXPAX_Z(piVar1);
      uVar2 = 0;
    }
    else {
      uVar4 = (**(code **)(*(int *)param_1[1] + 0x24))();
      *(undefined8 *)(param_1 + 10) = uVar4;
      uVar2 = FUN_0001cb2c(param_1,param_2,param_3);
    }
  }
  return uVar2;
}



/* 0001cb2c FUN_0001cb2c */

/* Boundary evidence: original MIPS .pdata 0001cb2c..0001cdf3. Semantic name remains unreviewed. */

undefined4 FUN_0001cb2c(int *param_1,wchar_t *param_2,int param_3)

{
  wchar_t *pwVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 != (wchar_t *)0x0) {
    (**(code **)(*(int *)param_1[1] + 0x34))((int *)param_1[1],param_1[0x14]);
    pwVar1 = wcsrchr(param_2,L'.');
    (**(code **)(*(int *)param_1[1] + 0x20))();
    iVar2 = FUN_0001bf88(param_1,(int *)param_1[1],pwVar1);
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
        piVar3 = FUN_0001ff3c(piVar3);
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



/* 0001cdf4 Unwind@0001cdf4 */

/* Boundary evidence: original MIPS .pdata 0001cdf4..0001ce23. Semantic name remains unreviewed. */

void Unwind_0001cdf4(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x28));
  return;
}



/* 0001ce24 FUN_0001ce24 */

/* Boundary evidence: original MIPS .pdata 0001ce24..0001cee7. Semantic name remains unreviewed. */

void FUN_0001ce24(int param_1)

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



/* 0001cee8 FUN_0001cee8 */

/* Boundary evidence: original MIPS .pdata 0001cee8..0001cf1b. Semantic name remains unreviewed. */

void FUN_0001cee8(int param_1)

{
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x24))();
  }
  return;
}



/* 0001cf1c FUN_0001cf1c */

/* Boundary evidence: original MIPS .pdata 0001cf1c..0001cfe3. Semantic name remains unreviewed. */

undefined4 FUN_0001cf1c(int *param_1,uint param_2)

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
  FUN_0001daec((int)(param_1 + 0xf),iVar2,param_2);
  return 1;
}



/* 0001cfe4 FUN_0001cfe4 */

/* Boundary evidence: original MIPS .pdata 0001cfe4..0001d077. Semantic name remains unreviewed. */

undefined4 FUN_0001cfe4(int *param_1,LPCSTR param_2)

{
  undefined4 uVar1;
  undefined1 *local_118;
  undefined1 auStack_114 [256];
  uint local_14;
  
  local_14 = DAT_000372d0;
  local_118 = auStack_114;
  FUN_0001dbc4((int *)&local_118,param_2,param_1[0xe]);
  uVar1 = (**(code **)(*param_1 + 0x44))(param_1,local_118);
  if (local_118 != auStack_114) {
    free(local_118);
  }
  FUN_0002a4f0(local_14);
  return uVar1;
}



/* 0001d078 Unwind@0001d078 */

/* Boundary evidence: original MIPS .pdata 0001d078..0001d0a7. Semantic name remains unreviewed. */

void Unwind_0001d078(void)

{
  int in_v0;
  
  FUN_0001da4c((undefined4 *)(in_v0 + -0x118));
  return;
}



/* 0001d0a8 FUN_0001d0a8 */

/* Boundary evidence: original MIPS .pdata 0001d0a8..0001d167. Semantic name remains unreviewed. */

int FUN_0001d0a8(int param_1,undefined4 param_2)

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



/* 0001d168 FUN_0001d168 */

/* Boundary evidence: original MIPS .pdata 0001d168..0001d1df. Semantic name remains unreviewed. */

undefined4 FUN_0001d168(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],FUN_0001bd94,param_2);
  uVar1 = (**(code **)(*param_1 + 0x44))(param_1,0);
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],param_1[5],0);
  return uVar1;
}



/* 0001d1e0 FUN_0001d1e0 */

/* Boundary evidence: original MIPS .pdata 0001d1e0..0001d28b. Semantic name remains unreviewed. */

undefined4 FUN_0001d1e0(int *param_1,undefined4 param_2,LPCSTR param_3)

{
  undefined4 uVar1;
  undefined1 *local_118;
  undefined1 auStack_114 [256];
  uint local_14;
  
  local_14 = DAT_000372d0;
  local_118 = auStack_114;
  FUN_0001dbc4((int *)&local_118,param_3,param_1[0xe]);
  uVar1 = (**(code **)(*param_1 + 0x38))(param_1,param_2,local_118);
  if (local_118 != auStack_114) {
    free(local_118);
  }
  FUN_0002a4f0(local_14);
  return uVar1;
}



/* 0001d28c Unwind@0001d28c */

/* Boundary evidence: original MIPS .pdata 0001d28c..0001d2bb. Semantic name remains unreviewed. */

void Unwind_0001d28c(void)

{
  int in_v0;
  
  FUN_0001da4c((undefined4 *)(in_v0 + -0x118));
  return;
}



/* 0001d2bc FUN_0001d2bc */

/* Boundary evidence: original MIPS .pdata 0001d2bc..0001d40b. Semantic name remains unreviewed. */

int FUN_0001d2bc(int *param_1,int param_2,undefined4 param_3)

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
      local_30 = &PTR_FUN_000348e4;
      FUN_0001de00((int)&local_30,1);
      *(int *)(local_28 * 4 + local_24) = param_2;
      param_1[0xd] = 0;
      local_28 = local_28 + 1;
      iVar1 = (**(code **)(*piVar3 + 0x14))(piVar3,local_24,local_28,param_3);
      if (iVar1 == 0) {
        iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3);
        param_1[0xd] = iVar2;
      }
      local_30 = &PTR_FUN_000348e4;
      FUN_0001df24((int)&local_30,0,local_28);
      __3_YAXPAX_Z(local_24);
    }
    else {
      param_1[0xd] = 0x37;
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 0001d40c Unwind@0001d40c */

/* Boundary evidence: original MIPS .pdata 0001d40c..0001d43b. Semantic name remains unreviewed. */

void Unwind_0001d40c(void)

{
  int in_v0;
  
  FUN_0001be40((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 0001d43c FUN_0001d43c */

/* Boundary evidence: original MIPS .pdata 0001d43c..0001d4b7. Semantic name remains unreviewed. */

undefined4 FUN_0001d43c(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],FUN_0001bd94);
  uVar1 = (**(code **)(*param_1 + 0x38))(param_1,param_2,0);
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],param_1[5],0);
  return uVar1;
}



/* 0001d4b8 FUN_0001d4b8 */

/* Boundary evidence: original MIPS .pdata 0001d4b8..0001d54b. Semantic name remains unreviewed. */

undefined4 FUN_0001d4b8(int *param_1,LPCSTR param_2)

{
  undefined4 uVar1;
  undefined1 *local_118;
  undefined1 auStack_114 [256];
  uint local_14;
  
  local_14 = DAT_000372d0;
  local_118 = auStack_114;
  FUN_0001dbc4((int *)&local_118,param_2,param_1[0xe]);
  uVar1 = (**(code **)(*param_1 + 0x28))(param_1,local_118);
  if (local_118 != auStack_114) {
    free(local_118);
  }
  FUN_0002a4f0(local_14);
  return uVar1;
}



/* 0001d54c Unwind@0001d54c */

/* Boundary evidence: original MIPS .pdata 0001d54c..0001d57b. Semantic name remains unreviewed. */

void Unwind_0001d54c(void)

{
  int in_v0;
  
  FUN_0001da4c((undefined4 *)(in_v0 + -0x118));
  return;
}



/* 0001d57c FUN_0001d57c */

/* Boundary evidence: original MIPS .pdata 0001d57c..0001d5ff. Semantic name remains unreviewed. */

int FUN_0001d57c(int param_1)

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



/* 0001d600 FUN_0001d600 */

/* Boundary evidence: original MIPS .pdata 0001d600..0001d677. Semantic name remains unreviewed. */

undefined4 FUN_0001d600(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],FUN_0001bd94,param_2);
  uVar1 = (**(code **)(*param_1 + 0x28))(param_1,0);
  (**(code **)(*(int *)param_1[2] + 0x2c))((int *)param_1[2],param_1[5],0);
  return uVar1;
}



/* 0001d678 FUN_0001d678 */

/* Boundary evidence: original MIPS .pdata 0001d678..0001d6af. Semantic name remains unreviewed. */

undefined4 FUN_0001d678(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x20))();
  }
  return 1;
}



/* 0001d6b0 FUN_0001d6b0 */

/* Boundary evidence: original MIPS .pdata 0001d6b0..0001d6f3. Semantic name remains unreviewed. */

undefined4 FUN_0001d6b0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x34))();
  return *(undefined4 *)(iVar1 + 8);
}



/* 0001d6f4 FUN_0001d6f4 */

/* Boundary evidence: original MIPS .pdata 0001d6f4..0001d7af. Semantic name remains unreviewed. */

undefined4 FUN_0001d6f4(int *param_1,int param_2)

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



/* 0001d7b0 FUN_0001d7b0 */

/* Boundary evidence: original MIPS .pdata 0001d7b0..0001d89f. Semantic name remains unreviewed. */

wchar_t * FUN_0001d7b0(undefined4 param_1,int param_2)

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



/* 0001d8a0 FUN_0001d8a0 */

/* Boundary evidence: original MIPS .pdata 0001d8a0..0001da43. Semantic name remains unreviewed. */

wchar_t * FUN_0001d8a0(undefined4 param_1,int param_2)

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



/* 0001da4c FUN_0001da4c */

/* Boundary evidence: original MIPS .pdata 0001da4c..0001da77. Semantic name remains unreviewed. */

void FUN_0001da4c(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != param_1 + 1) {
    free((undefined4 *)*param_1);
  }
  return;
}



/* 0001da78 FUN_0001da78 */

/* Boundary evidence: original MIPS .pdata 0001da78..0001daeb. Semantic name remains unreviewed. */

undefined4 * FUN_0001da78(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000348e4;
  FUN_0001df24((int)param_1,0,param_1[2]);
  __3_YAXPAX_Z(param_1[3]);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001daec FUN_0001daec */

/* Boundary evidence: original MIPS .pdata 0001daec..0001dbc3. Semantic name remains unreviewed. */

void FUN_0001daec(int param_1,int param_2,undefined4 param_3)

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
    FUN_0001de00(param_1,uVar1 + uVar2);
  }
  iVar3 = *(int *)(param_1 + 0x10);
  memmove((void *)((param_2 + 1) * iVar3 + *(int *)(param_1 + 0xc)),
          (void *)(iVar3 * param_2 + *(int *)(param_1 + 0xc)),
          (*(int *)(param_1 + 8) - param_2) * iVar3);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0xc)) = param_3;
  return;
}



/* 0001dbc4 FUN_0001dbc4 */

/* Boundary evidence: original MIPS .pdata 0001dbc4..0001dd1b. Semantic name remains unreviewed. */

void FUN_0001dbc4(int *param_1,LPCSTR param_2,UINT param_3)

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
    FUN_0001dd1c(param_1,cbMultiByte,param_1 + 1);
    iVar4 = MultiByteToWideChar(param_3,0,param_2,cbMultiByte,(LPWSTR)*param_1,cbMultiByte);
    if (iVar4 == 0) {
      DVar2 = GetLastError();
      if (DVar2 == 0x7a) {
        cchWideChar = MultiByteToWideChar(param_3,0,param_2,cbMultiByte,(LPWSTR)0x0,0);
        FUN_0001dd1c(param_1,cchWideChar,param_1 + 1);
        iVar4 = MultiByteToWideChar(param_3,0,param_2,cbMultiByte,(LPWSTR)*param_1,cchWideChar);
        if (iVar4 != 0) {
          return;
        }
      }
      FUN_0001bb24();
    }
  }
  return;
}



/* 0001dd1c FUN_0001dd1c */

/* Boundary evidence: original MIPS .pdata 0001dd1c..0001ddff. Semantic name remains unreviewed. */

void FUN_0001dd1c(int *param_1,size_t param_2,void *param_3)

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
      goto LAB_0001ddb8;
    }
  }
  else {
    if (0x80 < (int)param_2) {
      pvVar1 = _recalloc(pvVar1,param_2,2);
      if (pvVar1 == (void *)0x0) {
        pvVar1 = (void *)FUN_00011314(0x8007000e);
      }
      *param_1 = (int)pvVar1;
      goto LAB_0001ddb8;
    }
    free(pvVar1);
  }
  *param_1 = (int)param_3;
LAB_0001ddb8:
  if (*param_1 == 0) {
    FUN_00011314(0x8007000e);
  }
  return;
}



/* 0001de00 FUN_0001de00 */

/* Boundary evidence: original MIPS .pdata 0001de00..0001df23. Semantic name remains unreviewed. */

void FUN_0001de00(int param_1,uint param_2)

{
  uint uVar1;
  void *_Dst;
  undefined4 auStack_18 [2];
  
  if (param_2 != *(uint *)(param_1 + 4)) {
    if (0x7fffffff < param_2) {
                    /* WARNING: Subroutine does not return */
      auStack_18[0] = 0x100ec1;
      __CxxThrowException(auStack_18,(ThrowInfo *)&DAT_00036250);
    }
    uVar1 = *(uint *)(param_1 + 0x10);
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    if ((uVar1 * param_2) / uVar1 != param_2) {
                    /* WARNING: Subroutine does not return */
      auStack_18[0] = 0x100ec2;
      __CxxThrowException(auStack_18,(ThrowInfo *)&DAT_00036250);
    }
    _Dst = (void *)0x0;
    if (uVar1 * param_2 != 0) {
      _Dst = (void *)__2_YAPAXI_Z();
      if (_Dst == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        auStack_18[0] = 0x100ec3;
        __CxxThrowException(auStack_18,(ThrowInfo *)&DAT_00036250);
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



/* 0001df24 FUN_0001df24 */

/* Boundary evidence: original MIPS .pdata 0001df24..0001dfc3. Semantic name remains unreviewed. */

void FUN_0001df24(int param_1,int param_2,int param_3)

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



/* 0001dfc4 FUN_0001dfc4 */

/* Boundary evidence: original MIPS .pdata 0001dfc4..0001e043. Semantic name remains unreviewed. */

undefined4 FUN_0001dfc4(int *param_1,void *param_2,undefined4 *param_3)

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



/* 0001e044 FUN_0001e044 */

/* Boundary evidence: original MIPS .pdata 0001e044..0001e17b. Semantic name remains unreviewed. */

int * FUN_0001e044(wchar_t *param_1)

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
      *piVar1 = (int)&PTR_FUN_000349a8;
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
    FUN_00024414(param_1);
    iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1,param_1);
    if (iVar4 != 0) {
      return piVar1;
    }
    FUN_00024414(param_1);
    iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1,param_1);
    if (iVar4 != 0) {
      return piVar1;
    }
    __3_YAXPAX_Z(piVar1);
  }
  return (int *)0x0;
}



/* 0001e17c FUN_0001e17c */

/* Boundary evidence: original MIPS .pdata 0001e17c..0001e1bf. Semantic name remains unreviewed. */

int * FUN_0001e17c(wchar_t *param_1)

{
  int *piVar1;
  
  piVar1 = FUN_0001e044(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return piVar1;
}



/* 0001e1c0 FUN_0001e1c0 */

/* Boundary evidence: original MIPS .pdata 0001e1c0..0001e23f. Semantic name remains unreviewed. */

undefined4 * FUN_0001e1c0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000349a8;
  FUN_0001e618((int)param_1,param_2,0,0);
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



/* 0001e240 FUN_0001e240 */

/* Boundary evidence: original MIPS .pdata 0001e240..0001e2d3. Semantic name remains unreviewed. */

undefined4 FUN_0001e240(int *param_1,char *param_2)

{
  uint uVar1;
  char *_Memory;
  
  uVar1 = DAT_000372d0;
  _Memory = FUN_00024258(param_2);
  if (_Memory != (char *)0x0) {
    if (param_1[0x13] != -1) {
      (**(code **)(*param_1 + 0x18))(param_1);
    }
    param_1[0x13] = -1;
    free(_Memory);
  }
  FUN_0002a4f0(uVar1);
  return 0;
}



/* 0001e2d4 FUN_0001e2d4 */

/* Boundary evidence: original MIPS .pdata 0001e2d4..0001e4bf. Semantic name remains unreviewed. */

undefined4 FUN_0001e2d4(int *param_1,wchar_t *param_2)

{
  wchar_t *lpFileName;
  undefined4 uVar1;
  HANDLE pvVar2;
  int *piVar3;
  LONG LVar4;
  wchar_t *pwVar5;
  LPCWSTR local_30;
  int local_2c;
  
  lpFileName = FUN_00024324(param_2);
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
      piVar3 = FUN_0001ea50(&local_2c,lpFileName);
      FUN_0001eb38((int *)&local_30,piVar3);
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
        FUN_00012534((int *)&local_30);
        return 0;
      }
      FUN_00012534((int *)&local_30);
    }
    pwVar5 = _wcsdup(lpFileName);
    param_1[0x14] = (int)pwVar5;
    free(lpFileName);
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[3] = 0;
    FUN_0001e7c4(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001e4c0 Unwind@0001e4c0 */

/* Boundary evidence: original MIPS .pdata 0001e4c0..0001e4ef. Semantic name remains unreviewed. */

void Unwind_0001e4c0(void)

{
  int in_v0;
  
  FUN_00012534((int *)(in_v0 + -0x2c));
  return;
}



/* 0001e4f0 FUN_0001e4f0 */

/* Boundary evidence: original MIPS .pdata 0001e4f0..0001e617. Semantic name remains unreviewed. */

undefined4 FUN_0001e4f0(int param_1,void *param_2,size_t param_3)

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
    FUN_00024b30((int *)(param_1 + 0x10),param_2,param_3);
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



/* 0001e618 FUN_0001e618 */

/* Boundary evidence: original MIPS .pdata 0001e618..0001e79f. Semantic name remains unreviewed. */

bool FUN_0001e618(int param_1,undefined4 param_2,int param_3,int param_4)

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



/* 0001e7a0 FUN_0001e7a0 */

/* Boundary evidence: original MIPS .pdata 0001e7a0..0001e7c3. Semantic name remains unreviewed. */

void FUN_0001e7a0(int param_1,DWORD param_2)

{
  SetFileAttributesW(*(LPCWSTR *)(param_1 + 0x50),param_2);
  return;
}



/* 0001e7c4 FUN_0001e7c4 */

/* Boundary evidence: original MIPS .pdata 0001e7c4..0001e833. Semantic name remains unreviewed. */

undefined4 FUN_0001e7c4(LPVOID param_1)

{
  HANDLE pvVar1;
  DWORD local_10 [2];
  
  if (*(int *)((int)param_1 + 8) != 0) {
    return 0;
  }
  local_10[0] = 0;
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0001e834,param_1,0,local_10);
  *(HANDLE *)((int)param_1 + 8) = pvVar1;
  return 1;
}



/* 0001e834 FUN_0001e834 */

/* Boundary evidence: original MIPS .pdata 0001e834..0001e853. Semantic name remains unreviewed. */

undefined4 FUN_0001e834(int param_1)

{
  FUN_0001e854(param_1);
  return 0;
}



/* 0001e854 FUN_0001e854 */

/* Boundary evidence: original MIPS .pdata 0001e854..0001e9fb. Semantic name remains unreviewed. */

void FUN_0001e854(int param_1)

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
      if (0xffff < (int)DVar5) goto LAB_0001e8dc;
      DVar5 = 0;
LAB_0001e900:
      if (*(int *)(param_1 + 0xc) != 0) {
        bVar1 = true;
      }
    }
    else {
      if (0xffff < (int)DVar5) {
LAB_0001e8dc:
        DVar5 = 0x10000;
      }
      else if (DVar5 == 0) goto LAB_0001e900;
      FUN_00024c78(param_1 + 0x10,lpBuffer,DVar5,1);
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
        FUN_0001b2f4(0x3498c,DVar5,DVar3,(va_list)lpNumberOfBytesWritten);
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



/* 0001e9fc FUN_0001e9fc */

/* Boundary evidence: original MIPS .pdata 0001e9fc..0001ea4f. Semantic name remains unreviewed. */

undefined8 FUN_0001e9fc(int param_1)

{
  undefined8 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  uVar1 = *(undefined8 *)(param_1 + 0x28);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return uVar1;
}



/* 0001ea50 FUN_0001ea50 */

/* Boundary evidence: original MIPS .pdata 0001ea50..0001eb07. Semantic name remains unreviewed. */

int * FUN_0001ea50(int *param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  iVar2 = (**(code **)(PTR_PTR_000372d8 + 0xc))(&PTR_PTR_000372d8);
  *param_1 = iVar2 + 0x10;
  iVar2 = FUN_0001ec84(param_1,(uint)param_2);
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
    FUN_0001267c(param_1,param_2,iVar2);
  }
  return param_1;
}



/* 0001eb08 Unwind@0001eb08 */

/* Boundary evidence: original MIPS .pdata 0001eb08..0001eb37. Semantic name remains unreviewed. */

void Unwind_0001eb08(void)

{
  undefined4 *in_v0;
  
  FUN_00012534((int *)*in_v0);
  return;
}



/* 0001eb38 FUN_0001eb38 */

/* Boundary evidence: original MIPS .pdata 0001eb38..0001ec33. Semantic name remains unreviewed. */

int * FUN_0001eb38(int *param_1,int *param_2)

{
  short *psVar1;
  int *piVar2;
  int iVar3;
  short *psVar4;
  
  if (((*(int **)(*param_2 + -0x10) == (int *)0x0) ||
      (piVar2 = (int *)(**(code **)(**(int **)(*param_2 + -0x10) + 0x10))(), piVar2 == (int *)0x0))
     && (piVar2 = (int *)(**(code **)(PTR_PTR_000372d8 + 0x10))(&PTR_PTR_000372d8),
        piVar2 == (int *)0x0)) {
    piVar2 = (int *)FUN_00011314(0x80004005);
  }
  iVar3 = (**(code **)(*piVar2 + 0xc))(piVar2);
  *param_1 = iVar3 + 0x10;
  psVar1 = &DAT_00034980;
  do {
    psVar4 = psVar1;
    psVar1 = psVar4 + 1;
  } while (*psVar4 != 0);
  FUN_0001257c(param_1,(void *)*param_2,*(int *)(*param_2 + -0xc),&DAT_00034980,
               ((int)(psVar4 + -0x1a4bf) >> 1) + -1);
  return param_1;
}



/* 0001ec34 Unwind@0001ec34 */

/* Boundary evidence: original MIPS .pdata 0001ec34..0001ec83. Semantic name remains unreviewed. */

void Unwind_0001ec34(void)

{
  undefined4 *in_v0;
  
  if ((in_v0[-6] & 1) != 0) {
    in_v0[-6] = in_v0[-6] & 0xfffffffe;
    FUN_00012534((int *)*in_v0);
  }
  return;
}



/* 0001ec84 FUN_0001ec84 */

/* Boundary evidence: original MIPS .pdata 0001ec84..0001ed5f. Semantic name remains unreviewed. */

undefined4 FUN_0001ec84(int *param_1,uint param_2)

{
  HMODULE pHVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if ((param_2 != 0) && ((param_2 & 0xffff0000) == 0)) {
    pHVar1 = (HMODULE)FUN_0002b548(0x37a58,0);
    uVar4 = 1;
    iVar3 = 1;
    while (pHVar1 != (HMODULE)0x0) {
      puVar2 = FUN_0001eea0(pHVar1,param_2 & 0xffff);
      if (puVar2 != (ushort *)0x0) {
        if (pHVar1 == (HMODULE)0x0) {
          return 1;
        }
        FUN_0001ed60(param_1,pHVar1,param_2 & 0xffff);
        return 1;
      }
      pHVar1 = (HMODULE)FUN_0002b548(0x37a58,iVar3);
      iVar3 = iVar3 + 1;
    }
  }
  return uVar4;
}



/* 0001ed60 FUN_0001ed60 */

/* Boundary evidence: original MIPS .pdata 0001ed60..0001ee9f. Semantic name remains unreviewed. */

undefined4 FUN_0001ed60(int *param_1,HMODULE param_2,uint param_3)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  errno_t eVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  
  puVar2 = FUN_0001eea0(param_2,param_3);
  if (puVar2 == (ushort *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar5 = (uint)*puVar2;
    if ((int)(1U - *(int *)(*param_1 + -4) | *(int *)(*param_1 + -8) - uVar5) < 0) {
      FUN_0001288c(param_1,uVar5);
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
    FUN_0001ba98(eVar4);
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



/* 0001eea0 FUN_0001eea0 */

/* Boundary evidence: original MIPS .pdata 0001eea0..0001ef97. Semantic name remains unreviewed. */

ushort * FUN_0001eea0(HMODULE param_1,uint param_2)

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



/* 0001ef98 FUN_0001ef98 */

/* Boundary evidence: original MIPS .pdata 0001ef98..0001f017. Semantic name remains unreviewed. */

undefined4 FUN_0001ef98(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,&DAT_0002e198,0x10);
  if (iVar1 == 0) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    return 0;
  }
  return 0x80004002;
}



/* 0001f018 FUN_0001f018 */

/* Boundary evidence: original MIPS .pdata 0001f018..0001f08b. Semantic name remains unreviewed. */

LONG FUN_0001f018(int *param_1)

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



/* 0001f09c FUN_0001f09c */

/* Boundary evidence: original MIPS .pdata 0001f09c..0001f15b. Semantic name remains unreviewed. */

int * FUN_0001f09c(undefined4 param_1)

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
    *piVar1 = (int)&PTR_FUN_00034a40;
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



/* 0001f15c FUN_0001f15c */

/* Boundary evidence: original MIPS .pdata 0001f15c..0001f1fb. Semantic name remains unreviewed. */

undefined4 * FUN_0001f15c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00034a40;
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



/* 0001f1fc FUN_0001f1fc */

/* Boundary evidence: original MIPS .pdata 0001f1fc..0001f263. Semantic name remains unreviewed. */

undefined4 FUN_0001f1fc(int *param_1)

{
  uint uVar1;
  
  uVar1 = DAT_000372d0;
  if (param_1[2] != -1) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  param_1[2] = -1;
  FUN_0002a4f0(uVar1);
  return 0;
}



/* 0001f264 FUN_0001f264 */

/* Boundary evidence: original MIPS .pdata 0001f264..0001f417. Semantic name remains unreviewed. */

undefined4 FUN_0001f264(int *param_1,wchar_t *param_2)

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
    FUN_0001b2f4(0x349d4,param_2,DVar2,pcVar5);
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



/* 0001f418 FUN_0001f418 */

/* Boundary evidence: original MIPS .pdata 0001f418..0001f4a7. Semantic name remains unreviewed. */

int FUN_0001f418(int param_1,void *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint local_20 [2];
  
  local_20[0] = 0;
  if (param_4 == (uint *)0x0) {
    param_4 = local_20;
  }
  iVar1 = FUN_0001f4a8(param_1,param_2,param_3,param_4);
  if ((iVar1 != 0) && (puVar2 = *(undefined4 **)(param_1 + 0x34), puVar2 != (undefined4 *)0x0)) {
    (**(code **)*puVar2)(puVar2,param_2,*param_4);
  }
  return iVar1;
}



/* 0001f4a8 FUN_0001f4a8 */

/* Boundary evidence: original MIPS .pdata 0001f4a8..0001f6e7. Semantic name remains unreviewed. */

undefined4 FUN_0001f4a8(int param_1,void *param_2,uint param_3,uint *param_4)

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
      if (BVar1 == 0) goto LAB_0001f5c8;
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
        goto LAB_0001f6c0;
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
        goto LAB_0001f6c0;
      }
LAB_0001f5c8:
      DVar2 = GetLastError();
      FUN_0001b2f4(0x34a1c,DVar2,uVar5,(va_list)lpNumberOfBytesRead);
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
LAB_0001f6c0:
    uVar3 = 1;
  }
  return uVar3;
}



/* 0001f6e8 FUN_0001f6e8 */

/* Boundary evidence: original MIPS .pdata 0001f6e8..0001f733. Semantic name remains unreviewed. */

undefined4 FUN_0001f6e8(int *param_1,undefined4 param_2,int param_3)

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



/* 0001f734 FUN_0001f734 */

/* Boundary evidence: original MIPS .pdata 0001f734..0001f933. Semantic name remains unreviewed. */

undefined8 FUN_0001f734(int *param_1,undefined4 param_2,uint param_3,int param_4,int param_5)

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
LAB_0001f8c8:
    param_1[6] = 0;
    param_1[5] = 0;
  }
  else {
    if (param_5 == 1) {
      if (param_3 == 0 && param_4 == 0) goto LAB_0001f914;
      if ((-1 < param_4) && ((param_4 != 0 || (param_3 != 0)))) {
        uVar3 = param_1[5] - param_1[6];
        iVar2 = (int)uVar3 >> 0x1f;
        if ((param_4 <= iVar2) && ((param_4 != iVar2 || (param_3 < uVar3)))) {
          uVar3 = param_1[8];
          uVar4 = uVar3 + param_3;
          param_1[6] = param_3 + param_1[6];
          param_1[8] = uVar4;
          param_1[9] = param_1[9] + param_4 + (uint)(uVar4 < uVar3);
          goto LAB_0001f914;
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
          goto LAB_0001f914;
        }
      }
      uVar3 = param_1[8];
      uVar4 = uVar3 + param_3;
      param_1[8] = uVar4;
      param_1[9] = param_1[9] + param_4 + (uint)(uVar4 < uVar3);
      goto LAB_0001f8c8;
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
LAB_0001f914:
  return *(undefined8 *)(param_1 + 8);
}



/* 0001f94c FUN_0001f94c */

/* Boundary evidence: original MIPS .pdata 0001f94c..0001f9bb. Semantic name remains unreviewed. */

undefined4 FUN_0001f94c(int param_1)

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



/* 0001f9e4 FUN_0001f9e4 */

/* Boundary evidence: original MIPS .pdata 0001f9e4..0001fa07. Semantic name remains unreviewed. */

void FUN_0001f9e4(undefined4 *param_1)

{
  *param_1 = std::bad_alloc::vftable;
  __1exception_std__UAA_XZ();
  return;
}



/* 0001fa08 FUN_0001fa08 */

/* Boundary evidence: original MIPS .pdata 0001fa08..0001fa5f. Semantic name remains unreviewed. */

undefined4 * FUN_0001fa08(undefined4 *param_1,uint param_2)

{
  *param_1 = std::bad_alloc::vftable;
  __1exception_std__UAA_XZ(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001fa60 FUN_0001fa60 */

/* Boundary evidence: original MIPS .pdata 0001fa60..0001fadf. Semantic name remains unreviewed. */

undefined4 * FUN_0001fa60(undefined4 *param_1,int param_2)

{
  __0exception_std__QAA_XZ(param_1);
  *param_1 = std::logic_error::vftable;
  param_1[9] = 0xf;
  param_1[8] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_0002230c((int)(param_1 + 3),param_2,0,0xffffffff);
  return param_1;
}



/* 0001fae0 Unwind@0001fae0 */

/* Boundary evidence: original MIPS .pdata 0001fae0..0001fb0f. Semantic name remains unreviewed. */

void Unwind_0001fae0(void)

{
  undefined4 *in_v0;
  
  __1exception_std__UAA_XZ(*in_v0);
  return;
}



/* 0001fb10 FUN_0001fb10 */

int FUN_0001fb10(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x24)) {
    return *(int *)(param_1 + 0x10);
  }
  return param_1 + 0x10;
}



/* 0001fb38 FUN_0001fb38 */

/* Boundary evidence: original MIPS .pdata 0001fb38..0001fbb3. Semantic name remains unreviewed. */

undefined4 * FUN_0001fb38(undefined4 *param_1,uint param_2)

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



/* 0001fbb4 FUN_0001fbb4 */

/* Boundary evidence: original MIPS .pdata 0001fbb4..0001fc0f. Semantic name remains unreviewed. */

void FUN_0001fbb4(undefined4 *param_1)

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



/* 0001fc10 FUN_0001fc10 */

/* Boundary evidence: original MIPS .pdata 0001fc10..0001fe33. Semantic name remains unreviewed. */

undefined4 FUN_0001fc10(undefined4 *param_1,char *param_2,UINT param_3)

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
      if (iVar3 != 0) goto LAB_0001fde4;
      free(lpWideCharStr);
    }
  }
  lpWideCharStr = (LPWSTR)0x0;
LAB_0001fde4:
  param_1[1] = lpWideCharStr;
  if (lpWideCharStr == (LPWSTR)0x0) {
    puVar2 = malloc(4);
    param_1[1] = puVar2;
    *puVar2 = 0x3f;
    *(undefined2 *)(param_1[1] + 2) = 0;
  }
  return 1;
}



/* 0001fe68 FUN_0001fe68 */

/* Boundary evidence: original MIPS .pdata 0001fe68..0001fedb. Semantic name remains unreviewed. */

void FUN_0001fe68(int param_1)

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



/* 0001fedc FUN_0001fedc */

/* Boundary evidence: original MIPS .pdata 0001fedc..0001ff0b. Semantic name remains unreviewed. */

void FUN_0001fedc(int param_1)

{
  if (*(void **)(param_1 + 0x12) != (void *)0x0) {
    free(*(void **)(param_1 + 0x12));
  }
  return;
}



/* 0001ff0c FUN_0001ff0c */

/* Boundary evidence: original MIPS .pdata 0001ff0c..0001ff3b. Semantic name remains unreviewed. */

void FUN_0001ff0c(int param_1)

{
  if (*(void **)(param_1 + 0x34) != (void *)0x0) {
    free(*(void **)(param_1 + 0x34));
  }
  return;
}



/* 0001ff3c FUN_0001ff3c */

/* Boundary evidence: original MIPS .pdata 0001ff3c..00020067. Semantic name remains unreviewed. */

int * FUN_0001ff3c(int *param_1)

{
  int iVar1;
  
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[2] = 0;
  param_1[10] = (int)&PTR_FUN_00034bb8;
  param_1[0x91] = (int)&DAT_0002c198;
  param_1[0x8e] = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[0x8b] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[1] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  *param_1 = (int)&PTR_FUN_00034aac;
  FUN_000231d8(param_1 + 0xb1);
  iVar1 = FUN_00023b6c();
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



/* 00020068 Unwind@00020068 */

/* Boundary evidence: original MIPS .pdata 00020068..00020097. Semantic name remains unreviewed. */

void Unwind_00020068(void)

{
  undefined4 *in_v0;
  
  FUN_0002534c((undefined4 *)*in_v0);
  return;
}



/* 00020098 Unwind@00020098 */

/* Boundary evidence: original MIPS .pdata 00020098..000200c7. Semantic name remains unreviewed. */

void Unwind_00020098(void)

{
  int in_v0;
  
  FUN_000222f0(*(undefined4 **)(in_v0 + -0x14));
  return;
}



/* 000200c8 Unwind@000200c8 */

/* Boundary evidence: original MIPS .pdata 000200c8..000200fb. Semantic name remains unreviewed. */

void Unwind_000200c8(void)

{
  int *in_v0;
  
  FUN_00020148((int *)(*in_v0 + 0x2c4));
  return;
}



/* 000200fc FUN_000200fc */

/* Boundary evidence: original MIPS .pdata 000200fc..00020147. Semantic name remains unreviewed. */

int * FUN_000200fc(int *param_1,uint param_2)

{
  FUN_00020164(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00020148 FUN_00020148 */

/* Boundary evidence: original MIPS .pdata 00020148..00020163. Semantic name remains unreviewed. */

void FUN_00020148(int *param_1)

{
  FUN_000220d4(param_1);
  return;
}



/* 00020164 FUN_00020164 */

/* Boundary evidence: original MIPS .pdata 00020164..000201c7. Semantic name remains unreviewed. */

void FUN_00020164(int *param_1)

{
  *param_1 = (int)&PTR_FUN_00034aac;
  FUN_000255c4(param_1);
  FUN_000220d4(param_1 + 0xb1);
  FUN_0002534c(param_1);
  return;
}



/* 000201c8 Unwind@000201c8 */

/* Boundary evidence: original MIPS .pdata 000201c8..000201f7. Semantic name remains unreviewed. */

void Unwind_000201c8(void)

{
  undefined4 *in_v0;
  
  FUN_0002534c((undefined4 *)*in_v0);
  return;
}



/* 000201f8 Unwind@000201f8 */

/* Boundary evidence: original MIPS .pdata 000201f8..0002022b. Semantic name remains unreviewed. */

void Unwind_000201f8(void)

{
  int *in_v0;
  
  FUN_00020148((int *)(*in_v0 + 0x2c4));
  return;
}



/* 0002022c FUN_0002022c */

void FUN_0002022c(int param_1)

{
  *(undefined4 *)(param_1 + 0x2b0) = 0;
  *(undefined4 *)(param_1 + 0x2b4) = 0;
  *(undefined4 *)(param_1 + 0x2b8) = 0;
  *(undefined4 *)(param_1 + 700) = 0;
  *(undefined4 *)(param_1 + 0x2c0) = 0;
  return;
}



/* 00020244 FUN_00020244 */

/* Boundary evidence: original MIPS .pdata 00020244..00020593. Semantic name remains unreviewed. */

undefined4 FUN_00020244(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int local_30 [2];
  
  (**(code **)**(undefined4 **)(param_1 + 0x20))
            (*(undefined4 **)(param_1 + 0x20),&DAT_0002e1a8,param_1 + 0x2c0);
  iVar3 = FUN_00020594(param_1);
  if (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 0x2b8);
    bVar1 = false;
    if (((((iVar3 == 0) || (iVar3 == 4)) || (iVar3 == 0x400)) &&
        ((bVar2 = FUN_00021b10(param_1), CONCAT31(extraout_var,bVar2) == 1 &&
         (iVar3 = FUN_0002084c(param_1), iVar3 == 0x6054b50)))) &&
       ((iVar3 = FUN_00021608(param_1), iVar3 == 1 &&
        ((*(int *)(param_1 + 0x2b0) != -1 || (*(int *)(param_1 + 0x2b4) != 0)))))) {
      (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
      iVar3 = FUN_0002084c(param_1);
      if (iVar3 == 0x4034b50) {
        (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
        while( true ) {
          while( true ) {
            while (iVar3 = FUN_0002084c(param_1), iVar3 == 0x2014b50) {
              FUN_0002106c(param_1,1);
            }
            if (iVar3 != 0x6064b50) break;
            FUN_00021828(param_1);
          }
          if (iVar3 != 0x7064b50) break;
          FUN_00021918(param_1);
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
        if (local_30[0] == 0) goto LAB_0002057c;
        if (local_30[0] == 0x4034b50) {
          iVar3 = FUN_000208dc(param_1,(undefined4 *)0x0);
          bVar1 = true;
        }
        else if (local_30[0] == 0x2014b50) {
          iVar3 = FUN_0002106c(param_1,0);
        }
        else if (local_30[0] == 0x6054b50) {
          iVar3 = FUN_00021608(param_1);
        }
        else if (local_30[0] == 0x6064b50) {
          iVar3 = FUN_00021828(param_1);
        }
        else {
          if (local_30[0] != 0x7064b50) {
            if (bVar1) {
              return 0;
            }
            goto LAB_00020548;
          }
          iVar3 = FUN_00021918(param_1);
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
LAB_0002057c:
      if (bVar1) {
        *(undefined4 *)(param_1 + 600) = 0x100;
        return 0;
      }
    }
LAB_00020548:
    *(undefined4 *)(param_1 + 600) = 0x101;
  }
  return 0;
}



/* 00020594 FUN_00020594 */

/* WARNING: Removing unreachable block (ram,0x00020600) */
/* Boundary evidence: original MIPS .pdata 00020594..000207d3. Semantic name remains unreviewed. */

undefined4 FUN_00020594(int param_1)

{
  char *_Memory;
  wchar_t *pwVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  pwVar1 = L"ed msg\r\n";
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
                        (*(int **)(param_1 + 0x20),_Memory,pwVar1), iVar2 == 0)) goto LAB_000207ac;
  if (*_Memory == 'P') {
    if (((_Memory[1] != 'K') || (_Memory[2] != '\x03')) || (_Memory[3] != '\x04')) {
      if ((((_Memory[1] != 'K') || (_Memory[2] != '\a')) || (_Memory[3] != '\b')) &&
         (((_Memory[1] != 'K' || (_Memory[2] != '0')) ||
          ((_Memory[3] != '0' ||
           ((((_Memory[4] != 'P' || (_Memory[5] != 'K')) || (_Memory[6] != '\x03')) ||
            (_Memory[7] != '\x04')))))))) goto LAB_00020740;
      *(undefined4 *)(param_1 + 0x2b8) = 4;
    }
  }
  else {
LAB_00020740:
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
LAB_000207ac:
  free(_Memory);
  return uVar3;
}



/* 000207d4 FUN_000207d4 */

/* Boundary evidence: original MIPS .pdata 000207d4..0002084b. Semantic name remains unreviewed. */

void FUN_000207d4(int param_1)

{
  FUN_000228c0(param_1 + 0x2c4,*(int **)(*(int *)(param_1 + 0x2dc) + 4));
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



/* 0002084c FUN_0002084c */

/* Boundary evidence: original MIPS .pdata 0002084c..000208db. Semantic name remains unreviewed. */

undefined4 FUN_0002084c(int param_1)

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



/* 000208dc FUN_000208dc */

/* Boundary evidence: original MIPS .pdata 000208dc..00020bab. Semantic name remains unreviewed. */

undefined4 FUN_000208dc(int param_1,undefined4 *param_2)

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
  
  local_28 = DAT_000372d0;
  _Memory = (void *)0x0;
  uVar4 = 0;
  uVar5 = (**(code **)(**(int **)(param_1 + 0x20) + 0x20))();
  iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))
                    (*(int **)(param_1 + 0x20),auStack_150,0x1a);
  if (iVar1 == 0) {
    uVar4 = (**(code **)(**(int **)(param_1 + 0x20) + 0x2c))();
    *(undefined4 *)(param_1 + 0x1c) = uVar4;
    *(undefined4 *)(param_1 + 600) = 3;
    FUN_0002a4f0(local_28);
    return 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    param_2[0x12] = local_14a;
  }
  uVar2 = (uint)local_13a | ((int)local_139 << 0x18) >> 0x10;
  if (0x104 < uVar2 + 1) {
    *(undefined4 *)(param_1 + 600) = 4;
    goto LAB_00020b78;
  }
  uVar3 = 0;
  if (uVar2 != 0) {
    iVar1 = FUN_000219d8(param_1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 600) = 5;
      goto LAB_00020b78;
    }
    uVar3 = (uint)local_13a | ((int)local_139 << 0x18) >> 0x10;
  }
  uVar2 = (uint)(byte)local_138 | ((int)local_138._1_1_ << 0x18) >> 0x10;
  acStack_130[uVar3] = '\0';
  if (uVar2 == 0) {
LAB_00020a98:
    if ((param_2 != (undefined4 *)0x0) ||
       (param_2 = FUN_00020d64(param_1,(int)auStack_150,(uint)uVar5,(int)((ulonglong)uVar5 >> 0x20),
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
        FUN_00020bac((int)_Memory,(int)local_138,(int)param_2);
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
      if ((local_138 == 0) || (iVar1 = FUN_000219d8(param_1), iVar1 != 0)) goto LAB_00020a98;
      *(undefined4 *)(param_1 + 600) = 7;
    }
  }
  if (_Memory != (void *)0x0) {
    free(_Memory);
  }
LAB_00020b78:
  FUN_0002a4f0(local_28);
  return uVar4;
}



/* 00020bac FUN_00020bac */

/* Boundary evidence: original MIPS .pdata 00020bac..00020d63. Semantic name remains unreviewed. */

undefined4 FUN_00020bac(int param_1,int param_2,int param_3)

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



/* 00020d64 FUN_00020d64 */

/* Boundary evidence: original MIPS .pdata 00020d64..0002106b. Semantic name remains unreviewed. */

undefined4 * FUN_00020d64(int param_1,int param_2,uint param_3,undefined4 param_4,char *param_5)

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
  uVar8 = FUN_00024ea4(&local_48);
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
  iVar1 = FUN_0001fc10(_Dst,param_5,UVar4);
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
    FUN_00024a44((int *)(param_1 + 8),(int)_Dst);
    piVar2 = FUN_00021f90((int *)(param_1 + 0x2c4),_Dst + 0xe);
    *piVar2 = (int)_Dst;
  }
  return _Dst;
}



/* 0002106c FUN_0002106c */

/* Boundary evidence: original MIPS .pdata 0002106c..000215d7. Semantic name remains unreviewed. */

undefined4 FUN_0002106c(int param_1,int param_2)

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
LAB_000210d8:
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
      iVar1 = FUN_000219d8(param_1);
      if (iVar1 == 0) goto LAB_000210d8;
      uVar5 = (uint)local_30 | ((int)local_2f << 0x18) >> 0x10;
    }
    local_1e[uVar5] = '\0';
  }
  uVar5 = (uint)(byte)local_2e | ((int)local_2e._1_1_ << 0x18) >> 0x10;
  uVar6 = 0;
  if (uVar5 != 0) {
    local_1a = malloc(uVar5);
    if (local_1a == (void *)0x0) goto LAB_000210d8;
    uVar6 = 0;
    if ((byte)local_2e != '\0' || ((int)local_2e._1_1_ << 0x18) >> 0x10 != 0) {
      iVar1 = FUN_000219d8(param_1);
      if (iVar1 == 0) goto LAB_000210d8;
      uVar6 = local_2e & 0xff | (ushort)((uint)((int)local_2e._1_1_ << 0x18) >> 0x10);
    }
  }
  uVar5 = (uint)local_2c | ((int)local_2b << 0x18) >> 0x10;
  if (uVar5 != 0) {
    local_16 = malloc(uVar5 + 1);
    if (local_16 == (void *)0x0) goto LAB_000210d8;
    uVar5 = 0;
    if (local_2c != 0 || ((int)local_2b << 0x18) >> 0x10 != 0) {
      iVar1 = FUN_000219d8(param_1);
      if (iVar1 == 0) goto LAB_000210d8;
      uVar5 = (uint)local_2c | ((int)local_2b << 0x18) >> 0x10;
    }
    *(undefined1 *)(uVar5 + (int)local_16) = 0;
    uVar6 = local_2e & 0xff | (ushort)((uint)((int)local_2e._1_1_ << 0x18) >> 0x10);
  }
  if (param_2 == 0) {
    if (local_22 == 0) goto LAB_00021570;
    puVar3 = (undefined4 *)FUN_00021a44(param_1,local_22);
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
    puVar3 = FUN_00020d64(param_1,(int)&local_68,(uint)(lVar7 + (ulonglong)local_22),
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
      FUN_00020bac((int)local_1a,(int)(short)local_2e,(int)puVar3);
    }
  }
LAB_00021570:
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



/* 000215d8 Unwind@000215d8 */

/* Boundary evidence: original MIPS .pdata 000215d8..00021607. Semantic name remains unreviewed. */

void Unwind_000215d8(void)

{
  int in_v0;
  
  FUN_0001fe68(in_v0 + -0x48);
  return;
}



/* 00021608 FUN_00021608 */

/* Boundary evidence: original MIPS .pdata 00021608..000217f7. Semantic name remains unreviewed. */

undefined4 FUN_00021608(int param_1)

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
        iVar1 = FUN_000219d8(param_1);
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



/* 000217f8 Unwind@000217f8 */

/* Boundary evidence: original MIPS .pdata 000217f8..00021827. Semantic name remains unreviewed. */

void Unwind_000217f8(void)

{
  int in_v0;
  
  FUN_0001fedc(in_v0 + -0x28);
  return;
}



/* 00021828 FUN_00021828 */

/* Boundary evidence: original MIPS .pdata 00021828..000218e7. Semantic name remains unreviewed. */

undefined4 FUN_00021828(int param_1)

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



/* 000218e8 Unwind@000218e8 */

/* Boundary evidence: original MIPS .pdata 000218e8..00021917. Semantic name remains unreviewed. */

void Unwind_000218e8(void)

{
  int in_v0;
  
  FUN_0001ff0c(in_v0 + -0x48);
  return;
}



/* 00021918 FUN_00021918 */

/* Boundary evidence: original MIPS .pdata 00021918..000219d7. Semantic name remains unreviewed. */

undefined4 FUN_00021918(int param_1)

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



/* 000219d8 FUN_000219d8 */

/* Boundary evidence: original MIPS .pdata 000219d8..00021a43. Semantic name remains unreviewed. */

undefined4 FUN_000219d8(int param_1)

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



/* 00021a44 FUN_00021a44 */

/* Boundary evidence: original MIPS .pdata 00021a44..00021b0f. Semantic name remains unreviewed. */

undefined4 FUN_00021a44(int param_1,uint param_2)

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
  piVar2 = FUN_00022178((int *)(param_1 + 0x2c4),aiStack_18,&local_28);
  piVar5 = (int *)*piVar2;
  iVar6 = piVar2[1];
  local_24 = *(undefined4 *)(param_1 + 0x2dc);
  local_28 = *(uint *)(param_1 + 0x2c4);
  local_20 = piVar5;
  local_1c = iVar6;
  bVar1 = FUN_0002225c((int *)&local_20,(int *)&local_28);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (piVar5 == (int *)0x0) {
      FUN_0002b31c();
      iVar4 = 0;
    }
    else {
      iVar4 = *piVar5;
    }
    if (iVar6 == *(int *)(iVar4 + 0x18)) {
      FUN_0002b31c();
    }
    uVar3 = *(undefined4 *)(iVar6 + 0x18);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 00021b10 FUN_00021b10 */

/* WARNING: Removing unreachable block (ram,0x00021c00) */
/* WARNING: Removing unreachable block (ram,0x00021bd0) */
/* WARNING: Removing unreachable block (ram,0x00021ba0) */
/* WARNING: Removing unreachable block (ram,0x00021d60) */
/* Boundary evidence: original MIPS .pdata 00021b10..00021ddf. Semantic name remains unreviewed. */

bool FUN_00021b10(int param_1)

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
          if ((int)uVar6 < 1) goto LAB_00021d48;
          uVar5 = uVar6 - 1;
        } while ((((*(char *)(uVar5 + (int)_Memory) != 'P') ||
                  (*(char *)((int)_Memory + uVar6) != 'K')) ||
                 (*(char *)((int)_Memory + uVar6 + 1) != '\x05')) ||
                (*(char *)((int)_Memory + uVar6 + 2) != '\x06'));
        uVar11 = uVar5 + uVar10;
        local_34 = ((int)uVar5 >> 0x1f) + iVar9 + (uint)(uVar11 < uVar5);
        iVar8 = local_34;
        if (uVar11 != 0 || local_34 != 0) break;
LAB_00021d48:
        iVar8 = local_34;
      } while (lVar2 < lVar1);
    }
    free(_Memory);
    (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
    bVar3 = uVar11 != 0 || iVar8 != 0;
  }
  return bVar3;
}



/* 00021de0 FUN_00021de0 */

/* Boundary evidence: original MIPS .pdata 00021de0..00021f47. Semantic name remains unreviewed. */

undefined4 FUN_00021de0(int param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_3[0xc] == 0 && param_3[0xd] == 0) {
    uVar3 = 0;
    (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
    iVar1 = FUN_0002084c(param_1);
    if ((iVar1 != 0x4034b50) || (iVar1 = FUN_000208dc(param_1,param_3), iVar1 == 0)) {
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
    uVar3 = FUN_00025ac0(param_1,(int)param_3,*(int **)(param_1 + 0x20),param_4);
  }
  else if (param_3[0xb] == 8) {
    uVar3 = FUN_00025dd4(param_1,(int)param_3,*(int **)(param_1 + 0x20),param_4);
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



/* 00021f48 FUN_00021f48 */

/* Boundary evidence: original MIPS .pdata 00021f48..00021f8f. Semantic name remains unreviewed. */

void FUN_00021f48(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x18)) {
    __3_YAXPAX_Z(*(undefined4 *)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}



/* 00021f90 FUN_00021f90 */

/* Boundary evidence: original MIPS .pdata 00021f90..000220d3. Semantic name remains unreviewed. */

int * FUN_00021f90(int *param_1,uint *param_2)

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
  
  FUN_00022838(param_1,&local_38,param_2);
  local_2c = param_1[6];
  local_30 = *param_1;
  bVar1 = FUN_0002225c((int *)&local_38,&local_30);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if ((local_34[5] < (int)param_2[1]) ||
       ((param_2[1] == local_34[5] && ((uint)local_34[4] <= *param_2)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    piVar2 = local_34;
    if (!bVar1) goto LAB_0002206c;
  }
  local_28 = *param_2;
  local_24 = param_2[1];
  local_20 = 0;
  piVar2 = FUN_000224ac(param_1,&local_30,(int)local_38,local_34,&local_28);
  local_38 = (int *)*piVar2;
  piVar2 = (int *)piVar2[1];
LAB_0002206c:
  if (local_38 == (int *)0x0) {
    FUN_0002b31c();
    iVar3 = 0;
  }
  else {
    iVar3 = *local_38;
  }
  if (piVar2 == *(int **)(iVar3 + 0x18)) {
    FUN_0002b31c();
  }
  return piVar2 + 6;
}



/* 000220d4 FUN_000220d4 */

/* Boundary evidence: original MIPS .pdata 000220d4..00022147. Semantic name remains unreviewed. */

void FUN_000220d4(int *param_1)

{
  int aiStack_18 [2];
  
  FUN_00022cbc(param_1,aiStack_18,*param_1,*(int **)param_1[6],*param_1,(int *)param_1[6]);
  __3_YAXPAX_Z(param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  __3_YAXPAX_Z(*param_1);
  return;
}



/* 00022148 Unwind@00022148 */

/* Boundary evidence: original MIPS .pdata 00022148..00022177. Semantic name remains unreviewed. */

void Unwind_00022148(void)

{
  undefined4 *in_v0;
  
  FUN_000222f0((undefined4 *)*in_v0);
  return;
}



/* 00022178 FUN_00022178 */

/* Boundary evidence: original MIPS .pdata 00022178..0002225b. Semantic name remains unreviewed. */

int * FUN_00022178(int *param_1,int *param_2,uint *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int iStack_20;
  int local_1c;
  int local_18;
  int local_14;
  
  FUN_00022838(param_1,&iStack_20,param_3);
  local_14 = param_1[6];
  local_18 = *param_1;
  bVar1 = FUN_0002225c(&iStack_20,&local_18);
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
      goto LAB_00022230;
    }
  }
  local_14 = param_1[6];
  piVar2 = &local_18;
  local_18 = *param_1;
LAB_00022230:
  iVar3 = piVar2[1];
  *param_2 = *piVar2;
  param_2[1] = iVar3;
  return param_2;
}



/* 0002225c FUN_0002225c */

/* Boundary evidence: original MIPS .pdata 0002225c..000222ef. Semantic name remains unreviewed. */

bool FUN_0002225c(int *param_1,int *param_2)

{
  if ((*param_1 == 0) || (*param_1 != *param_2)) {
    FUN_0002b31c();
  }
  return param_1[1] == param_2[1];
}



/* 000222f0 FUN_000222f0 */

/* Boundary evidence: original MIPS .pdata 000222f0..0002230b. Semantic name remains unreviewed. */

void FUN_000222f0(undefined4 *param_1)

{
  __3_YAXPAX_Z(*param_1);
  return;
}



/* 0002230c FUN_0002230c */

/* Boundary evidence: original MIPS .pdata 0002230c..00022427. Semantic name remains unreviewed. */

int FUN_0002230c(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 *_Dst;
  undefined4 *puVar2;
  uint _MaxCount;
  
  if (*(uint *)(param_2 + 0x14) < param_3) {
    FUN_0002b040();
  }
  _MaxCount = *(int *)(param_2 + 0x14) - param_3;
  if (param_4 < _MaxCount) {
    _MaxCount = param_4;
  }
  if (param_1 == param_2) {
    FUN_00022924(param_1,_MaxCount + param_3,0xffffffff);
    FUN_00022924(param_1,0,param_3);
  }
  else {
    iVar1 = FUN_00022a08(param_1,_MaxCount,0);
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



/* 00022428 FUN_00022428 */

/* Boundary evidence: original MIPS .pdata 00022428..000224ab. Semantic name remains unreviewed. */

void FUN_00022428(int param_1,int param_2,rsize_t param_3)

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



/* 000224ac FUN_000224ac */

/* Boundary evidence: original MIPS .pdata 000224ac..00022837. Semantic name remains unreviewed. */

int * FUN_000224ac(int *param_1,int *param_2,int param_3,int *param_4,uint *param_5)

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
    FUN_00022e34(param_1,param_2,1,(int *)param_1[6],param_5);
    return param_2;
  }
  local_2c = *(int **)param_1[6];
  local_30 = *param_1;
  bVar1 = FUN_0002225c(&local_res8,&local_30);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    local_2c = (int *)param_1[6];
    local_30 = *param_1;
    bVar1 = FUN_0002225c(&local_res8,&local_30);
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
        FUN_00023c70(&local_30);
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
            FUN_00022e34(param_1,param_2,0,local_2c,param_5);
            return param_2;
          }
          FUN_00022e34(param_1,param_2,1,local_resc,param_5);
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
        FUN_00023d84(&local_30);
        bVar2 = FUN_0002225c(&local_30,&local_28);
        if (CONCAT31(extraout_var_01,bVar2) == 0) {
          if ((local_2c[5] < (int)param_5[1]) ||
             ((param_5[1] == local_2c[5] && ((uint)local_2c[4] <= *param_5)))) {
            bVar1 = false;
          }
          if (!bVar1) goto LAB_000227f8;
        }
        if (*(char *)(local_resc[2] + 0x21) != '\0') {
          FUN_00022e34(param_1,param_2,0,local_resc,param_5);
          return param_2;
        }
        FUN_00022e34(param_1,param_2,1,local_2c,param_5);
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
        FUN_00022e34(param_1,param_2,0,piVar3,param_5);
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
      FUN_00022e34(param_1,param_2,1,local_resc,param_5);
      return param_2;
    }
  }
LAB_000227f8:
  piVar3 = FUN_00022af8(param_1,&local_28,param_5);
  *param_2 = *piVar3;
  param_2[1] = piVar3[1];
  return param_2;
}



/* 00022838 FUN_00022838 */

undefined4 * FUN_00022838(undefined4 *param_1,undefined4 *param_2,uint *param_3)

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



/* 000228c0 FUN_000228c0 */

/* Boundary evidence: original MIPS .pdata 000228c0..00022923. Semantic name remains unreviewed. */

void FUN_000228c0(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_2 + 0x21);
  while (cVar1 == '\0') {
    FUN_000228c0(param_1,(int *)param_2[2]);
    piVar2 = (int *)*param_2;
    __3_YAXPAX_Z(param_2);
    param_2 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x21);
  }
  return;
}



/* 00022924 FUN_00022924 */

/* Boundary evidence: original MIPS .pdata 00022924..00022a07. Semantic name remains unreviewed. */

int FUN_00022924(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  if (*(uint *)(param_1 + 0x14) < param_2) {
    FUN_0002b040();
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



/* 00022a08 FUN_00022a08 */

/* Boundary evidence: original MIPS .pdata 00022a08..00022af7. Semantic name remains unreviewed. */

undefined4 FUN_00022a08(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 == 0xffffffff) {
    FUN_0002afb0();
  }
  if (*(uint *)(param_1 + 0x18) < param_2) {
    FUN_00023368(param_1,param_2,*(rsize_t *)(param_1 + 0x14));
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
    FUN_00022428(param_1,1,uVar1);
  }
  if (param_2 == 0) {
    return 0;
  }
  return 1;
}



/* 00022af8 FUN_00022af8 */

/* Boundary evidence: original MIPS .pdata 00022af8..00022cbb. Semantic name remains unreviewed. */

int * FUN_00022af8(int *param_1,int *param_2,uint *param_3)

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
    bVar1 = FUN_0002225c(&local_30,&local_28);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      piVar4 = FUN_00022e34(param_1,&local_28,1,piVar4,param_3);
      iVar3 = piVar4[1];
      *param_2 = *piVar4;
      param_2[1] = iVar3;
      *(undefined1 *)(param_2 + 2) = 1;
      return param_2;
    }
    FUN_00023c70(&local_30);
  }
  if (((int)param_3[1] < local_2c[5]) ||
     ((local_2c[5] == param_3[1] && (*param_3 <= (uint)local_2c[4])))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    piVar4 = FUN_00022e34(param_1,&local_28,iVar3,piVar4,param_3);
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



/* 00022cbc FUN_00022cbc */

/* Boundary evidence: original MIPS .pdata 00022cbc..00022e33. Semantic name remains unreviewed. */

int * FUN_00022cbc(int *param_1,int *param_2,int param_3,int *param_4,int param_5,int *param_6)

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
  bVar2 = FUN_0002225c(&local_res8,&local_20);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    local_1c = param_1[6];
    local_20 = *param_1;
    bVar2 = FUN_0002225c(&param_5,&local_20);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      FUN_000228c0(param_1,*(int **)(param_1[6] + 4));
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
      FUN_0002b31c();
    }
    piVar1 = local_resc;
    iVar3 = local_res8;
    if (local_resc == param_6) break;
    FUN_00023d84(&local_res8);
    FUN_000235bc(param_1,&local_20,iVar3,piVar1);
  }
  *param_2 = *param_1;
  param_2[1] = (int)local_resc;
  return param_2;
}



/* 00022e34 FUN_00022e34 */

/* Boundary evidence: original MIPS .pdata 00022e34..000231a7. Semantic name remains unreviewed. */

undefined4 *
FUN_00022e34(undefined4 *param_1,undefined4 *param_2,int param_3,int *param_4,undefined4 *param_5)

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
  
  local_28 = DAT_000372d0;
  if (0xffffffd < (uint)param_1[7]) {
    FUN_0002ae58(auStack_70);
    local_58 = 0xf;
    local_5c = 0;
    local_6c = 0;
    FUN_00023f68((int)auStack_70,(undefined4 *)"map/set<T> too long",0x13);
    FUN_0001fa60(appuStack_50,auStack_70);
                    /* WARNING: Subroutine does not return */
    appuStack_50[0] = std::length_error::vftable;
    __CxxThrowException(appuStack_50,(ThrowInfo *)&DAT_000362c4);
  }
  piVar2 = (int *)FUN_00023bc0(param_1,param_1[6],param_4,param_1[6],param_5);
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
      FUN_0002a4f0(local_28);
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
          FUN_00023a6c((int)param_1,(int)piVar4);
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
LAB_00023140:
        piVar7[1] = (int)piVar3;
      }
    }
    else {
      iVar6 = *piVar3;
      if (*(char *)(iVar6 + 0x20) != '\0') {
        if (piVar8 == (int *)*piVar4) {
          FUN_00023aec((int)param_1,piVar4);
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
        goto LAB_00023140;
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



/* 000231a8 Unwind@000231a8 */

/* Boundary evidence: original MIPS .pdata 000231a8..000231d7. Semantic name remains unreviewed. */

void Unwind_000231a8(void)

{
  int in_v0;
  
  FUN_00021f48(in_v0 + -0x70);
  return;
}



/* 000231d8 FUN_000231d8 */

/* Boundary evidence: original MIPS .pdata 000231d8..00023207. Semantic name remains unreviewed. */

int * FUN_000231d8(int *param_1)

{
  FUN_00023c40(param_1);
  return param_1;
}



/* 00023208 FUN_00023208 */

/* Boundary evidence: original MIPS .pdata 00023208..0002323f. Semantic name remains unreviewed. */

undefined4 * FUN_00023208(undefined4 *param_1,int param_2)

{
  FUN_00023240(param_1,param_2);
  *param_1 = std::length_error::vftable;
  return param_1;
}



/* 00023240 FUN_00023240 */

/* Boundary evidence: original MIPS .pdata 00023240..000232c3. Semantic name remains unreviewed. */

undefined4 * FUN_00023240(undefined4 *param_1,int param_2)

{
  __0exception_std__QAA_ABV01__Z(param_1,param_2);
  *param_1 = std::logic_error::vftable;
  param_1[9] = 0xf;
  param_1[8] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_0002230c((int)(param_1 + 3),param_2 + 0xc,0,0xffffffff);
  return param_1;
}



/* 000232c4 Unwind@000232c4 */

/* Boundary evidence: original MIPS .pdata 000232c4..000232f3. Semantic name remains unreviewed. */

void Unwind_000232c4(void)

{
  undefined4 *in_v0;
  
  __1exception_std__UAA_XZ(*in_v0);
  return;
}



/* 000232f4 FUN_000232f4 */

/* Boundary evidence: original MIPS .pdata 000232f4..00023367. Semantic name remains unreviewed. */

int FUN_000232f4(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  FUN_0002ae58(param_1);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00023f68(param_1,(undefined4 *)param_2,(uint)(pcVar2 + (-1 - (int)param_2)));
  return param_1;
}



/* 00023368 FUN_00023368 */

/* Boundary evidence: original MIPS .pdata 00023368..0002351f. Semantic name remains unreviewed. */

void FUN_00023368(int param_1,uint param_2,rsize_t param_3)

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
      __CxxThrowException(local_28,(ThrowInfo *)&DAT_00036338);
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



/* 00023520 FUN_00023520 */

/* Boundary evidence: original MIPS .pdata 00023520..00023573. Semantic name remains unreviewed. */

void FUN_00023520(void)

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



/* 00023574 FUN_00023574 */

/* Boundary evidence: original MIPS .pdata 00023574..000235bb. Semantic name remains unreviewed. */

undefined * FUN_00023574(void)

{
  undefined4 *in_v0;
  undefined4 uVar1;
  
  in_v0[-0xc] = in_v0[1];
  uVar1 = FUN_00023eac(*in_v0,in_v0[1] + 1);
  in_v0[-0xb] = uVar1;
  return &DAT_00023474;
}



/* 000235bc FUN_000235bc */

/* Boundary evidence: original MIPS .pdata 000235bc..00023a3b. Semantic name remains unreviewed. */

undefined4 * FUN_000235bc(undefined4 *param_1,undefined4 *param_2,int param_3,int *param_4)

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
  
  local_28 = DAT_000372d0;
  local_res8 = param_3;
  local_resc = param_4;
  if (*(char *)((int)param_4 + 0x21) != '\0') {
    FUN_0002ae58(auStack_70);
    local_58 = 0xf;
    local_5c = 0;
    local_6c = 0;
    FUN_00023f68((int)auStack_70,(undefined4 *)"invalid map/set<T> iterator",0x1b);
    FUN_0001fa60(appuStack_50,auStack_70);
                    /* WARNING: Subroutine does not return */
    appuStack_50[0] = std::out_of_range::vftable;
    __CxxThrowException(appuStack_50,(ThrowInfo *)&DAT_00036300);
  }
  FUN_00023d84(&local_res8);
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
      goto LAB_0002382c;
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
LAB_0002382c:
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
            FUN_00023a6c((int)param_1,(int)piVar6);
            piVar3 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar3 + 0x21) == '\0') {
            if ((*(char *)(*piVar3 + 0x20) != '\x01') || (*(char *)(piVar3[2] + 0x20) != '\x01')) {
              if (*(char *)(piVar3[2] + 0x20) == '\x01') {
                *(undefined1 *)(*piVar3 + 0x20) = 1;
                *(undefined1 *)(piVar3 + 8) = 0;
                FUN_00023aec((int)param_1,piVar3);
                piVar3 = (int *)piVar6[2];
              }
              *(char *)(piVar3 + 8) = (char)piVar6[8];
              *(undefined1 *)(piVar6 + 8) = 1;
              *(undefined1 *)(piVar3[2] + 0x20) = 1;
              FUN_00023a6c((int)param_1,(int)piVar6);
              break;
            }
            *(undefined1 *)(piVar3 + 8) = 0;
          }
        }
        else {
          if ((char)piVar3[8] == '\0') {
            *(undefined1 *)(piVar3 + 8) = 1;
            *(undefined1 *)(piVar6 + 8) = 0;
            FUN_00023aec((int)param_1,piVar6);
            piVar3 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar3 + 0x21) == '\0') {
            if ((*(char *)(piVar3[2] + 0x20) != '\x01') || (*(char *)(*piVar3 + 0x20) != '\x01')) {
              if (*(char *)(*piVar3 + 0x20) == '\x01') {
                *(undefined1 *)(piVar3[2] + 0x20) = 1;
                *(undefined1 *)(piVar3 + 8) = 0;
                FUN_00023a6c((int)param_1,(int)piVar3);
                piVar3 = (int *)*piVar6;
              }
              *(char *)(piVar3 + 8) = (char)piVar6[8];
              *(undefined1 *)(piVar6 + 8) = 1;
              *(undefined1 *)(*piVar3 + 0x20) = 1;
              FUN_00023aec((int)param_1,piVar6);
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
  FUN_0002a4f0(local_28);
  return param_2;
}



/* 00023a3c Unwind@00023a3c */

/* Boundary evidence: original MIPS .pdata 00023a3c..00023a6b. Semantic name remains unreviewed. */

void Unwind_00023a3c(void)

{
  int in_v0;
  
  FUN_00021f48(in_v0 + -0x70);
  return;
}



/* 00023a6c FUN_00023a6c */

void FUN_00023a6c(int param_1,int param_2)

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



/* 00023aec FUN_00023aec */

void FUN_00023aec(int param_1,int *param_2)

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



/* 00023b6c FUN_00023b6c */

/* Boundary evidence: original MIPS .pdata 00023b6c..00023bbf. Semantic name remains unreviewed. */

void FUN_00023b6c(void)

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



/* 00023bc0 FUN_00023bc0 */

/* Boundary evidence: original MIPS .pdata 00023bc0..00023c3f. Semantic name remains unreviewed. */

void FUN_00023bc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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



/* 00023c40 FUN_00023c40 */

/* Boundary evidence: original MIPS .pdata 00023c40..00023c6f. Semantic name remains unreviewed. */

int * FUN_00023c40(int *param_1)

{
  FUN_00023f34(param_1);
  return param_1;
}



/* 00023c70 FUN_00023c70 */

/* Boundary evidence: original MIPS .pdata 00023c70..00023d83. Semantic name remains unreviewed. */

void FUN_00023c70(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*param_1 == 0) {
    FUN_0002b31c();
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
  FUN_0002b31c();
  return;
}



/* 00023d84 FUN_00023d84 */

/* Boundary evidence: original MIPS .pdata 00023d84..00023e73. Semantic name remains unreviewed. */

void FUN_00023d84(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if (*param_1 == 0) {
    FUN_0002b31c();
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
  FUN_0002b31c();
  return;
}



/* 00023e74 FUN_00023e74 */

/* Boundary evidence: original MIPS .pdata 00023e74..00023eab. Semantic name remains unreviewed. */

undefined4 * FUN_00023e74(undefined4 *param_1,int param_2)

{
  FUN_00023240(param_1,param_2);
  *param_1 = std::out_of_range::vftable;
  return param_1;
}



/* 00023eac FUN_00023eac */

/* Boundary evidence: original MIPS .pdata 00023eac..00023f33. Semantic name remains unreviewed. */

void FUN_00023eac(undefined4 param_1,uint param_2)

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
    __CxxThrowException(appuStack_18,(ThrowInfo *)&DAT_00036338);
  }
  __2_YAPAXI_Z(param_2);
  return;
}



/* 00023f34 FUN_00023f34 */

/* Boundary evidence: original MIPS .pdata 00023f34..00023f67. Semantic name remains unreviewed. */

int * FUN_00023f34(int *param_1)

{
  FUN_00024098(param_1);
  return param_1;
}



/* 00023f68 FUN_00023f68 */

/* Boundary evidence: original MIPS .pdata 00023f68..00024097. Semantic name remains unreviewed. */

int FUN_00023f68(int param_1,undefined4 *param_2,uint param_3)

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
      if (param_2 < (undefined4 *)(*(int *)(param_1 + 0x14) + (int)puVar3)) goto LAB_00023fdc;
    }
  }
  bVar1 = false;
LAB_00023fdc:
  if (bVar1) {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      iVar4 = param_1 + 4;
    }
    else {
      iVar4 = *(int *)(param_1 + 4);
    }
    param_1 = FUN_0002230c(param_1,param_1,(int)param_2 - iVar4,param_3);
  }
  else {
    iVar4 = FUN_00022a08(param_1,param_3,0);
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



/* 00024098 FUN_00024098 */

/* Boundary evidence: original MIPS .pdata 00024098..000240cf. Semantic name remains unreviewed. */

int * FUN_00024098(int *param_1)

{
  FUN_000240d0(param_1);
  return param_1;
}



/* 000240d0 FUN_000240d0 */

/* Boundary evidence: original MIPS .pdata 000240d0..00024113. Semantic name remains unreviewed. */

int * FUN_000240d0(int *param_1)

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



/* 00024114 FUN_00024114 */

/* Boundary evidence: original MIPS .pdata 00024114..0002414b. Semantic name remains unreviewed. */

undefined4 * FUN_00024114(undefined4 *param_1)

{
  __0exception_std__QAA_ABV01__Z(param_1);
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}



/* 0002414c FUN_0002414c */

void FUN_0002414c(short *param_1)

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



/* 00024258 FUN_00024258 */

/* Boundary evidence: original MIPS .pdata 00024258..00024323. Semantic name remains unreviewed. */

char * FUN_00024258(char *param_1)

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
LAB_00024304:
        *pcVar3 = '_';
      }
    }
    else if (('=' < cVar1) && ((cVar1 < '@' || (cVar1 == '|')))) goto LAB_00024304;
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
    iVar4 = iVar4 + 1;
  } while( true );
}



/* 00024324 FUN_00024324 */

/* Boundary evidence: original MIPS .pdata 00024324..00024413. Semantic name remains unreviewed. */

wchar_t * FUN_00024324(wchar_t *param_1)

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
      FUN_0002414c(pwVar2);
      return pwVar2;
    }
    wVar1 = *pwVar3;
    if ((ushort)wVar1 < 0x3d) {
      if ((wVar1 == L'<') || ((wVar1 == L'*' || ((wVar1 == L':' && (2 < iVar4)))))) {
LAB_000243e4:
        *pwVar3 = L'_';
      }
    }
    else if ((0x3d < (ushort)wVar1) && (((ushort)wVar1 < 0x40 || (wVar1 == L'|'))))
    goto LAB_000243e4;
    pwVar3 = pwVar3 + 1;
    wVar1 = *pwVar3;
    iVar4 = iVar4 + 1;
  } while( true );
}



/* 00024414 FUN_00024414 */

/* Boundary evidence: original MIPS .pdata 00024414..0002479f. Semantic name remains unreviewed. */

undefined4 FUN_00024414(wchar_t *param_1)

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
  
  local_30 = DAT_000372d0;
  if (param_1 == (wchar_t *)0x0) {
    FUN_0002a4f0(DAT_000372d0);
    uVar2 = 0;
  }
  else {
    _Str = FUN_00024324(param_1);
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
            goto LAB_000246b4;
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
LAB_000246b4:
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
    FUN_0002a4f0(local_30);
  }
  return uVar2;
}



/* 000247a0 FUN_000247a0 */

/* Boundary evidence: original MIPS .pdata 000247a0..000248e7. Semantic name remains unreviewed. */

undefined4 FUN_000247a0(short *param_1,undefined4 param_2,short *param_3,short *param_4)

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
    FUN_000248e8(param_1);
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



/* 000248e8 FUN_000248e8 */

undefined4 FUN_000248e8(short *param_1)

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
    psVar4 = &DAT_00031cfc;
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



/* 00024974 FUN_00024974 */

/* Boundary evidence: original MIPS .pdata 00024974..00024a43. Semantic name remains unreviewed. */

void FUN_00024974(int *param_1)

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



/* 00024a44 FUN_00024a44 */

/* Boundary evidence: original MIPS .pdata 00024a44..00024b2f. Semantic name remains unreviewed. */

void FUN_00024a44(int *param_1,int param_2)

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



/* 00024b30 FUN_00024b30 */

/* Boundary evidence: original MIPS .pdata 00024b30..00024c77. Semantic name remains unreviewed. */

undefined4 FUN_00024b30(int *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  size_t _Size;
  
  if (0 < (int)param_3) {
    if ((param_1[2] - param_1[5] <= (int)param_3) &&
       (iVar1 = FUN_00024da8(param_1,(param_1[5] - param_1[2]) + param_3), iVar1 == 0)) {
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



/* 00024c78 FUN_00024c78 */

/* Boundary evidence: original MIPS .pdata 00024c78..00024da7. Semantic name remains unreviewed. */

undefined4 FUN_00024c78(int param_1,void *param_2,size_t param_3,int param_4)

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
    if ((int)param_3 <= (int)sVar3) goto LAB_00024d2c;
    _Src = *(void **)(param_1 + 4);
    param_2 = (void *)(sVar3 + (int)param_2);
    sVar3 = param_3 - sVar3;
  }
  else {
    _Src = (void *)(*(int *)(param_1 + 4) + iVar2);
    sVar3 = param_3;
  }
  memcpy(param_2,_Src,sVar3);
LAB_00024d2c:
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



/* 00024da8 FUN_00024da8 */

/* Boundary evidence: original MIPS .pdata 00024da8..00024ea3. Semantic name remains unreviewed. */

undefined4 FUN_00024da8(int *param_1,int param_2)

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
      FUN_00024c78((int)param_1,pvVar1,param_1[5],0);
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



/* 00024ea4 FUN_00024ea4 */

/* Boundary evidence: original MIPS .pdata 00024ea4..000252ab. Semantic name remains unreviewed. */

undefined8 FUN_00024ea4(uint *param_1)

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
  
  uVar11 = DAT_000372d0;
  local_2c = DAT_000372d0;
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
      goto LAB_0002526c;
    }
    uVar11 = param_1[4];
    uVar17 = *(uint *)(&DAT_00037390 + uVar11 * 4);
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
    FUN_0002a4f0(local_2c);
  }
  else {
LAB_0002526c:
    FUN_0002a4f0(uVar11);
    uVar11 = 0;
    iVar16 = 0;
  }
  return CONCAT44(iVar16,uVar11);
}



/* 000252ac FUN_000252ac */

void FUN_000252ac(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00034b24;
  return;
}



/* 000252bc FUN_000252bc */

/* Boundary evidence: original MIPS .pdata 000252bc..000252ff. Semantic name remains unreviewed. */

undefined4 * FUN_000252bc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00034b24;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00025300 FUN_00025300 */

/* Boundary evidence: original MIPS .pdata 00025300..0002534b. Semantic name remains unreviewed. */

undefined4 * FUN_00025300(undefined4 *param_1,uint param_2)

{
  FUN_0002534c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0002534c FUN_0002534c */

/* Boundary evidence: original MIPS .pdata 0002534c..000253af. Semantic name remains unreviewed. */

void FUN_0002534c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00034b64;
  param_1[10] = &PTR_FUN_00034bb8;
  FUN_00024974(param_1 + 2);
  *param_1 = &PTR_FUN_00034b24;
  return;
}



/* 000253b0 Unwind@000253b0 */

/* Boundary evidence: original MIPS .pdata 000253b0..000253df. Semantic name remains unreviewed. */

void Unwind_000253b0(void)

{
  undefined4 *in_v0;
  
  FUN_000252ac((undefined4 *)*in_v0);
  return;
}



/* 000253e0 FUN_000253e0 */

/* Boundary evidence: original MIPS .pdata 000253e0..000254db. Semantic name remains unreviewed. */

int FUN_000253e0(int *param_1,undefined4 param_2)

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
    *piVar1 = (int)&PTR_FUN_00034a40;
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



/* 000254dc FUN_000254dc */

/* Boundary evidence: original MIPS .pdata 000254dc..0002553b. Semantic name remains unreviewed. */

undefined4 FUN_000254dc(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_0001f09c(param_2);
  if (piVar1 == (int *)0x0) {
    param_1[0x96] = 1;
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 4))(param_1,piVar1);
  return uVar2;
}



/* 0002553c FUN_0002553c */

/* Boundary evidence: original MIPS .pdata 0002553c..000255c3. Semantic name remains unreviewed. */

undefined4 FUN_0002553c(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(*param_1 + 0x10))(param_1);
  iVar1 = (**(code **)*param_2)(param_2,&DAT_0002e198,param_1 + 8);
  if (iVar1 < 0) {
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  return uVar2;
}



/* 000255c4 FUN_000255c4 */

/* Boundary evidence: original MIPS .pdata 000255c4..0002565b. Semantic name remains unreviewed. */

void FUN_000255c4(int *param_1)

{
  if ((int *)param_1[8] != (int *)0x0) {
    (**(code **)(*(int *)param_1[8] + 8))();
    param_1[8] = 0;
  }
  FUN_00024974(param_1 + 2);
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



/* 0002565c FUN_0002565c */

/* Boundary evidence: original MIPS .pdata 0002565c..000256ab. Semantic name remains unreviewed. */

void FUN_0002565c(int param_1,char *param_2)

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



/* 000256ac FUN_000256ac */

/* Boundary evidence: original MIPS .pdata 000256ac..0002578f. Semantic name remains unreviewed. */

void FUN_000256ac(int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,int param_6)

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
    FUN_00025790(param_1);
    (**(code **)(**(int **)(param_1 + 0x264) + 4))
              (*(int **)(param_1 + 0x264),param_1 + 0x268,(int *)(param_1 + 0x25c),
               (int *)(param_1 + 0x260));
    if (*(int *)(param_1 + 0x25c) != 0 || *(int *)(param_1 + 0x260) != 0) {
      *(undefined4 *)(param_1 + 600) = 0x17;
    }
  }
  return;
}



/* 00025790 FUN_00025790 */

/* Boundary evidence: original MIPS .pdata 00025790..0002590f. Semantic name remains unreviewed. */

void FUN_00025790(int param_1)

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
      goto LAB_0002581c;
    }
    uVar1 = 0;
  }
  else if (uVar7 == 0 && uVar8 == 0) {
    uVar1 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x2a4);
    uVar1 = *(undefined4 *)(param_1 + 0x2a0);
LAB_0002581c:
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
    if (uVar7 == 0 && uVar8 == 0) goto LAB_00025894;
    uVar4 = *(uint *)(param_1 + 0x298);
    iVar6 = *(int *)(param_1 + 0x29c);
    iVar3 = *(int *)(param_1 + 0x288);
    iVar5 = *(int *)(param_1 + 0x28c);
  }
  else {
    if (uVar7 == 0 && uVar8 == 0) {
LAB_00025894:
      uVar1 = 0;
      goto LAB_000258e8;
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
LAB_000258e8:
  *(undefined4 *)(param_1 + 0x2ac) = uVar1;
  return;
}



/* 00025910 FUN_00025910 */

/* Boundary evidence: original MIPS .pdata 00025910..00025abf. Semantic name remains unreviewed. */

void FUN_00025910(int param_1,int *param_2,int param_3)

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



/* 00025ac0 FUN_00025ac0 */

/* Boundary evidence: original MIPS .pdata 00025ac0..00025dd3. Semantic name remains unreviewed. */

undefined4 FUN_00025ac0(int param_1,int param_2,int *param_3,int *param_4)

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
  
  local_30 = DAT_000372d0;
  local_2040 = *(uint *)(param_2 + 0x10);
  local_203c = *(uint *)(param_2 + 0x14);
  local_2048 = 0;
  local_2038 = param_4;
  iVar2 = FUN_00026894(param_1 + 0x28,param_2,param_3,&local_2040);
  if (iVar2 == 0) {
    piVar5 = *(int **)(param_1 + 0x264);
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x230);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0xc))(piVar5,*(undefined4 *)(param_1 + 0x230),param_2,param_1 + 0x260);
    }
    FUN_0002a4f0(local_30);
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
          FUN_000269b8(param_1 + 0x28,uVar7,(byte *)auStack_2030);
        }
        uVar4 = FUN_00026ecc(local_2048,auStack_2030,uVar7);
        puVar6 = auStack_2030;
        iVar2 = (**(code **)(*local_2038 + 0x14))(local_2038,puVar6,uVar7,0);
        local_2048 = uVar4;
        if (iVar2 == 0) {
          piVar5 = *(int **)(param_1 + 0x264);
          *(undefined4 *)(param_1 + 600) = 0x30;
          if (piVar5 != (int *)0x0) {
            uVar3 = 0x30;
            goto LAB_00025cdc;
          }
          goto LAB_00025d00;
        }
        bVar1 = uVar10 < uVar7;
        uVar10 = uVar10 - uVar7;
        uVar8 = (uVar8 - uVar9) - (uint)bVar1;
        if (*(int *)(param_1 + 0x254) == 0) {
          FUN_000256ac(param_1,puVar6,uVar7,uVar9,uVar7,uVar9);
        }
        if ((*(int *)(param_1 + 0x260) != 0 || *(int *)(param_1 + 0x25c) != 0) ||
           (uVar10 == 0 && uVar8 == 0)) goto LAB_00025d00;
      }
      piVar5 = *(int **)(param_1 + 0x264);
      *(undefined4 *)(param_1 + 600) = 0x15;
      uVar4 = local_2048;
      if (piVar5 != (int *)0x0) {
        uVar3 = 0x15;
LAB_00025cdc:
        (**(code **)(*piVar5 + 0xc))(piVar5,uVar3,param_2,param_1 + 0x260);
        uVar4 = local_2048;
      }
    }
LAB_00025d00:
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
    FUN_0002a4f0(local_30);
  }
  return uVar3;
}



/* 00025dd4 FUN_00025dd4 */

/* Boundary evidence: original MIPS .pdata 00025dd4..00026203. Semantic name remains unreviewed. */

undefined4 FUN_00025dd4(int param_1,int param_2,int *param_3,int *param_4)

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
  
  local_30 = DAT_000372d0;
  local_2078 = *(uint *)(param_2 + 0x10);
  local_2074 = *(int *)(param_2 + 0x14);
  local_207c = 0;
  local_2080 = 0;
  local_2070 = param_3;
  local_206c = param_4;
  iVar2 = FUN_00026894(param_1 + 0x28,param_2,param_3,&local_2078);
  if (iVar2 == 0) {
    piVar5 = *(int **)(param_1 + 0x264);
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x230);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0xc))(piVar5,*(undefined4 *)(param_1 + 0x230),param_2,param_1 + 0x260);
    }
    FUN_0002a4f0(local_30);
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
  FUN_000273e0((int)&local_2068);
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
      goto LAB_00026174;
      iVar3 = (**(code **)(*param_3 + 0x14))(param_3,abStack_2030,uVar8);
      if (iVar3 == 0) {
        piVar5 = *(int **)(param_1 + 0x264);
        *(undefined4 *)(param_1 + 600) = 0x15;
        if (piVar5 == (int *)0x0) goto LAB_000260b4;
        iVar2 = *piVar5;
        uVar7 = 0x15;
        goto LAB_000260a4;
      }
      iVar3 = *(int *)(param_1 + 0x22c);
      if ((iVar3 != 0) && ((iVar3 == 1 || (iVar3 == 5)))) {
        FUN_000269b8(param_1 + 0x28,uVar8,abStack_2030);
      }
      uVar9 = uVar10 - uVar8;
      local_2068 = abStack_2030;
      iVar2 = iVar2 - (uint)(uVar10 < uVar8);
      local_2064 = uVar8;
    }
    iVar3 = FUN_00027608((int *)&local_2068);
    if ((iVar3 != 0) && (iVar3 != 1)) {
      piVar5 = *(int **)(param_1 + 0x264);
      *(undefined4 *)(param_1 + 600) = 0x16;
      if (piVar5 == (int *)0x0) goto LAB_000260b4;
      iVar2 = *piVar5;
      uVar7 = 0x16;
      goto LAB_000260a4;
    }
    uVar10 = local_2054 - iVar4;
    local_207c = FUN_00026ecc(local_207c,auStack_1030,uVar10);
    puVar6 = auStack_1030;
    iVar4 = (**(code **)(*local_206c + 0x14))(local_206c,puVar6,uVar10,0);
    if (iVar4 == 0) break;
    local_205c = auStack_1030;
    local_2058 = 0x1000;
    if (*(int *)(param_1 + 0x254) == 0) {
      FUN_000256ac(param_1,puVar6,uVar8,0,uVar10,0);
    }
    if ((*(int *)(param_1 + 0x260) != 0 || *(int *)(param_1 + 0x25c) != 0) ||
       (param_3 = local_2070, uVar10 = uVar9, iVar3 == 1)) goto LAB_00026174;
  }
  piVar5 = *(int **)(param_1 + 0x264);
  *(undefined4 *)(param_1 + 600) = 0x30;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0xc))(piVar5,0x30,param_2,param_1 + 0x260);
  }
LAB_00026174:
  if (*(int *)(param_1 + 600) != 0) goto LAB_000260b4;
  iVar2 = *(int *)(param_1 + 0x22c);
  if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 5)) {
    if ((*(uint *)(param_2 + 0x28) == 0) || (*(uint *)(param_2 + 0x28) == local_207c)) {
      local_2080 = 1;
      goto LAB_000260b4;
    }
    piVar5 = *(int **)(param_1 + 0x264);
    *(undefined4 *)(param_1 + 600) = 0x18;
    if (piVar5 == (int *)0x0) goto LAB_000260b4;
    iVar2 = *piVar5;
    uVar7 = 0x18;
  }
  else {
    uVar7 = *(undefined4 *)(param_1 + 0x230);
    piVar5 = *(int **)(param_1 + 0x264);
    *(undefined4 *)(param_1 + 600) = uVar7;
    if (piVar5 == (int *)0x0) goto LAB_000260b4;
    iVar2 = *piVar5;
  }
LAB_000260a4:
  (**(code **)(iVar2 + 0xc))(piVar5,uVar7,param_2,param_1 + 0x260);
LAB_000260b4:
  uVar7 = local_2040;
  pcVar1 = local_2044;
  iVar2 = local_204c;
  if ((local_204c != 0) && (local_2044 != (code *)0x0)) {
    if (*(int *)(local_204c + 0x34) != 0) {
      (*local_2044)(local_2040);
    }
    (*pcVar1)(uVar7,iVar2);
  }
  FUN_0002a4f0(local_30);
  return local_2080;
}



/* 00026210 FUN_00026210 */

/* Boundary evidence: original MIPS .pdata 00026210..000262c3. Semantic name remains unreviewed. */

undefined4 FUN_00026210(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = param_1[4];
  piVar1 = (int *)FUN_0002b0d0();
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



/* 000262cc FUN_000262cc */

/* Boundary evidence: original MIPS .pdata 000262cc..000266c3. Semantic name remains unreviewed. */

undefined4 FUN_000262cc(int *param_1,int *param_2,uint param_3,short *param_4)

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
  
  local_30 = DAT_000372d0;
  if (param_2 == (int *)0x0) {
LAB_00026320:
    param_1[0x96] = 0x37;
LAB_00026328:
    FUN_0002a4f0(local_30);
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
      FUN_000248e8(local_440);
    }
    FUN_00025910((int)param_1,param_2,param_3);
    if (param_1[0x95] == 0) {
      local_860 = 0;
      uVar3 = 1;
      if (param_3 != 0) {
        piVar16 = param_1 + 0x98;
        do {
          if (*piVar16 != 0) goto LAB_00026328;
          iVar15 = *param_2;
          if (((iVar15 < 0) || (param_1[4] <= iVar15)) ||
             (iVar14 = *(int *)(iVar15 * 4 + param_1[2]), iVar14 == 0)) goto LAB_00026320;
          iVar4 = FUN_000247a0(local_850,0x208,local_440,*(short **)(iVar14 + 4));
          if (iVar4 == 0) goto LAB_00026328;
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
                iVar15 = FUN_000266c4(param_1,iVar15,iVar14,piVar5);
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
            FUN_000248e8(local_850);
            iVar15 = FUN_00024414(local_850);
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
            FUN_00025790((int)param_1);
            (**(code **)(*(int *)param_1[0x99] + 8))
                      ((int *)param_1[0x99],param_1 + 0x9a,param_1[0x96]);
          }
          local_860 = local_860 + 1;
          param_2 = param_2 + 1;
        } while (local_860 < param_3);
      }
      FUN_0002a4f0(local_30);
    }
    else {
      uVar3 = (**(code **)(*param_1 + 0x50))(param_1,param_2,param_3,param_4);
      FUN_0002a4f0(local_30);
    }
  }
  return uVar3;
}



/* 000266c4 FUN_000266c4 */

/* Boundary evidence: original MIPS .pdata 000266c4..00026893. Semantic name remains unreviewed. */

undefined4 FUN_000266c4(int *param_1,undefined4 param_2,int param_3,int *param_4)

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



/* 00026894 FUN_00026894 */

/* Boundary evidence: original MIPS .pdata 00026894..000269b7. Semantic name remains unreviewed. */

undefined4 FUN_00026894(int param_1,int param_2,int *param_3,uint *param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint auStack_28 [3];
  uint local_1c;
  
  local_1c = DAT_000372d0;
  *(undefined4 *)(param_1 + 0x208) = 0;
  iVar2 = *(int *)(param_2 + 0x20);
  *(int *)(param_1 + 0x204) = iVar2;
  *(int **)(param_1 + 0x20c) = param_3;
  if (iVar2 == 0) {
LAB_000268e0:
    FUN_0002a4f0(local_1c);
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
          FUN_00026a70(param_1,(char *)(param_1 + 4));
          iVar2 = FUN_00026b6c(param_1,auStack_28,(uint)*(byte *)(param_2 + 0x4c));
          if (iVar2 != 0) goto LAB_000268e0;
          uVar1 = 0x21;
        }
      }
      else {
        uVar1 = 0x46;
      }
      *(undefined4 *)(param_1 + 0x208) = uVar1;
    }
    FUN_0002a4f0(local_1c);
    uVar1 = 0;
  }
  return uVar1;
}



/* 000269b8 FUN_000269b8 */

void FUN_000269b8(int param_1,int param_2,byte *param_3)

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



/* 00026a70 FUN_00026a70 */

void FUN_00026a70(int param_1,char *param_2)

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



/* 00026b6c FUN_00026b6c */

/* Boundary evidence: original MIPS .pdata 00026b6c..00026e4f. Semantic name remains unreviewed. */

undefined4 FUN_00026b6c(int param_1,uint *param_2,uint param_3)

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
  
  local_c = DAT_000372d0;
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
    FUN_0002a4f0(local_c);
    return 1;
  }
  FUN_0002a4f0(local_c);
  return 0;
}



/* 00026e50 FUN_00026e50 */

/* Boundary evidence: original MIPS .pdata 00026e50..00026e93. Semantic name remains unreviewed. */

void FUN_00026e50(int param_1,byte *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x204);
  if ((iVar1 != 0) && ((iVar1 == 1 || (iVar1 == 5)))) {
    FUN_000269b8(param_1,param_3,param_2);
  }
  return;
}



/* 00026e9c FUN_00026e9c */

/* Boundary evidence: original MIPS .pdata 00026e9c..00026ecb. Semantic name remains unreviewed. */

uint FUN_00026e9c(uint param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  
  if (param_2 == (uint *)0x0) {
    return 0;
  }
  uVar1 = FUN_00026ecc(param_1,param_2,param_3);
  return uVar1;
}



/* 00026ecc FUN_00026ecc */

/* Boundary evidence: original MIPS .pdata 00026ecc..00027363. Semantic name remains unreviewed. */

uint FUN_00026ecc(uint param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ~param_1;
  for (; (param_3 != 0 && (((uint)param_2 & 3) != 0)); param_2 = (uint *)((int)param_2 + 1)) {
    uVar1 = *(uint *)(&DAT_0002c198 + (((byte)*param_2 ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
    param_3 = param_3 - 1;
  }
  if (0x1f < param_3) {
    uVar2 = param_3 >> 5;
    do {
      uVar1 = *param_2 ^ uVar1;
      uVar1 = *(uint *)(&DAT_0002c598 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c998 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c198 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cd98 + (uVar1 & 0xff) * 4) ^ param_2[1];
      uVar1 = *(uint *)(&DAT_0002c598 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c998 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c198 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cd98 + (uVar1 & 0xff) * 4) ^ param_2[2];
      uVar1 = *(uint *)(&DAT_0002c598 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c998 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c198 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cd98 + (uVar1 & 0xff) * 4) ^ param_2[3];
      uVar1 = *(uint *)(&DAT_0002c598 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c998 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c198 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cd98 + (uVar1 & 0xff) * 4) ^ param_2[4];
      uVar1 = *(uint *)(&DAT_0002c598 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c998 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c198 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cd98 + (uVar1 & 0xff) * 4) ^ param_2[5];
      uVar1 = *(uint *)(&DAT_0002c598 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c998 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c198 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cd98 + (uVar1 & 0xff) * 4) ^ param_2[6];
      uVar1 = *(uint *)(&DAT_0002c598 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c998 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c198 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cd98 + (uVar1 & 0xff) * 4) ^ param_2[7];
      param_2 = param_2 + 8;
      uVar1 = *(uint *)(&DAT_0002c598 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c998 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c198 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cd98 + (uVar1 & 0xff) * 4);
      uVar2 = uVar2 - 1;
      param_3 = param_3 - 0x20;
    } while (uVar2 != 0);
  }
  if (3 < param_3) {
    uVar2 = param_3 >> 2;
    do {
      uVar1 = *param_2 ^ uVar1;
      param_2 = param_2 + 1;
      uVar1 = *(uint *)(&DAT_0002c598 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c998 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0002c198 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_0002cd98 + (uVar1 & 0xff) * 4);
      uVar2 = uVar2 - 1;
      param_3 = param_3 - 4;
    } while (uVar2 != 0);
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    uVar1 = *(uint *)(&DAT_0002c198 + (((byte)*param_2 ^ uVar1) & 0xff) * 4) ^ uVar1 >> 8;
    param_2 = (uint *)((int)param_2 + 1);
  }
  return ~uVar1;
}



/* 00027364 FUN_00027364 */

undefined4 FUN_00027364(int param_1)

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



/* 000273e0 FUN_000273e0 */

/* Boundary evidence: original MIPS .pdata 000273e0..0002749b. Semantic name remains unreviewed. */

undefined4 FUN_000273e0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    return 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (*(int *)(param_1 + 0x20) == 0) {
    *(code **)(param_1 + 0x20) = FUN_000290c4;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    *(code **)(param_1 + 0x24) = FUN_000290f0;
  }
  iVar1 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x2530);
  if (iVar1 == 0) {
    return 0xfffffffc;
  }
  *(int *)(param_1 + 0x1c) = iVar1;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0xf;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  uVar2 = FUN_00027364(param_1);
  return uVar2;
}



/* 0002749c FUN_0002749c */

/* Boundary evidence: original MIPS .pdata 0002749c..00027607. Semantic name remains unreviewed. */

undefined4 FUN_0002749c(int param_1,int param_2)

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



/* 00027608 FUN_00027608 */

/* Boundary evidence: original MIPS .pdata 00027608..000290c3. Semantic name remains unreviewed. */

int FUN_00027608(int *param_1)

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
      local_58 = &DAT_000353c0;
      local_54 = &DAT_00034bc0;
      local_60 = &DAT_00035440;
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
        switch((int)&switchD_0002776c::switchdataD_00027774 +
               (int)(short)(&switchD_0002776c::switchdataD_00027774)[uVar9] & 0xfffffffe) {
        case 0x277b0:
          if (puVar18[2] != 0) {
            for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027d94;
              uVar16 = uVar16 - 1;
              uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
              _Src = (uint *)((int)_Src + 1);
            }
            if (((puVar18[2] & 2) != 0) && (uVar17 == 0x8b1f)) {
              uVar15 = FUN_00026e9c(0,(uint *)0x0,0);
              local_70 = 0x1f;
              puVar18[6] = uVar15;
              local_6f = 0x8b;
              uVar15 = FUN_00026ecc(uVar15,(uint *)&local_70,2);
              puVar18[6] = uVar15;
              uVar17 = 0;
              uVar15 = 0;
              uVar9 = 1;
              goto LAB_00028f0c;
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
            uVar15 = FUN_0002910c(0,(byte *)0x0,0);
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
            goto LAB_00028f10;
          }
          uVar9 = 0xc;
          goto LAB_00028f0c;
        case 0x27970:
          for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
            uVar10 = 0;
            if (uVar16 == 0) goto LAB_00027d94;
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
                uVar15 = FUN_00026ecc(puVar18[6],(uint *)&local_70,2);
                puVar18[6] = uVar15;
              }
              *puVar18 = 2;
              uVar17 = 0;
              uVar15 = 0;
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027d94;
                uVar19 = uVar15 & 0x1f;
                uVar15 = uVar15 + 8;
                uVar16 = uVar16 - 1;
                uVar17 = ((uint)(byte)*_Src << uVar19) + uVar17;
                _Src = (uint *)((int)_Src + 1);
joined_r0x00027a38:
              } while (uVar15 < 0x20);
              if (puVar18[8] != 0) {
                *(uint *)(puVar18[8] + 4) = uVar17;
              }
              if ((puVar18[4] & 0x200) != 0) {
                local_70 = (undefined1)uVar17;
                local_6f = (undefined1)(uVar17 >> 8);
                local_6e = (undefined1)(uVar17 >> 0x10);
                local_6d = (undefined1)(uVar17 >> 0x18);
                uVar15 = FUN_00026ecc(puVar18[6],(uint *)&local_70,4);
                puVar18[6] = uVar15;
              }
              *puVar18 = 3;
              uVar17 = 0;
              uVar15 = 0;
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027d94;
                uVar19 = uVar15 & 0x1f;
                uVar15 = uVar15 + 8;
                uVar16 = uVar16 - 1;
                uVar17 = ((uint)(byte)*_Src << uVar19) + uVar17;
                _Src = (uint *)((int)_Src + 1);
joined_r0x00027ad0:
              } while (uVar15 < 0x10);
              if (puVar18[8] != 0) {
                *(uint *)(puVar18[8] + 8) = uVar17 & 0xff;
                *(uint *)(puVar18[8] + 0xc) = uVar17 >> 8;
              }
              if ((puVar18[4] & 0x200) != 0) {
                local_70 = (undefined1)uVar17;
                local_6f = (undefined1)(uVar17 >> 8);
                uVar15 = FUN_00026ecc(puVar18[6],(uint *)&local_70,2);
                puVar18[6] = uVar15;
              }
              *puVar18 = 4;
              uVar17 = 0;
              uVar15 = 0;
              goto switchD_0002776c_caseD_27b60;
            }
            param_1[6] = (int)"unknown header flags set";
          }
          else {
            param_1[6] = (int)local_3c;
          }
          break;
        case 0x27a34:
          goto joined_r0x00027a38;
        case 0x27acc:
          goto joined_r0x00027ad0;
        case 0x27b60:
switchD_0002776c_caseD_27b60:
          if ((puVar18[4] & 0x400) == 0) {
            if (puVar18[8] != 0) {
              *(undefined4 *)(puVar18[8] + 0x10) = 0;
            }
          }
          else {
            for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027d94;
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
              uVar15 = FUN_00026ecc(puVar18[6],(uint *)&local_70,2);
              puVar18[6] = uVar15;
            }
            uVar17 = 0;
            uVar15 = 0;
          }
          *puVar18 = 5;
        case 0x27c08:
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
                  uVar9 = FUN_00026ecc(puVar18[6],_Src,uVar19);
                }
                puVar18[6] = uVar9;
              }
              uVar16 = uVar16 - uVar19;
              puVar18[0x10] = puVar18[0x10] - uVar19;
              _Src = (uint *)(uVar19 + (int)_Src);
            }
            uVar10 = uVar16;
            if (puVar18[0x10] != 0) goto LAB_00027d94;
          }
          puVar18[0x10] = 0;
          *puVar18 = 6;
switchD_0002776c_caseD_27cd8:
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
                  uVar9 = FUN_00026ecc(puVar18[6],_Src,uVar19);
                }
                puVar18[6] = uVar9;
              }
              uVar16 = uVar16 - uVar19;
              _Src = (uint *)(uVar19 + (int)_Src);
              uVar10 = uVar16;
              if (cVar1 == '\0') goto LAB_00027e08;
            }
            goto LAB_00027d94;
          }
          if (puVar18[8] != 0) {
            *(undefined4 *)(puVar18[8] + 0x1c) = 0;
          }
LAB_00027e08:
          puVar18[0x10] = 0;
          *puVar18 = 7;
switchD_0002776c_caseD_27e14:
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
                  uVar9 = FUN_00026ecc(puVar18[6],_Src,uVar19);
                }
                puVar18[6] = uVar9;
              }
              uVar16 = uVar16 - uVar19;
              _Src = (uint *)(uVar19 + (int)_Src);
              uVar10 = uVar16;
              if (cVar1 == '\0') goto LAB_00027ee4;
            }
            goto LAB_00027d94;
          }
          if (puVar18[8] != 0) {
            *(undefined4 *)(puVar18[8] + 0x24) = 0;
          }
LAB_00027ee4:
          *puVar18 = 8;
          uVar19 = local_6c;
switchD_0002776c_caseD_27ef0:
          if ((puVar18[4] & 0x200) != 0) {
            for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027d94;
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
          uVar9 = FUN_00026e9c(0,(uint *)0x0,0);
          puVar18[6] = uVar9;
          param_1[0xc] = uVar9;
LAB_00027f9c:
          uVar9 = 0xb;
          goto LAB_00028f0c;
        case 0x27cd8:
          goto switchD_0002776c_caseD_27cd8;
        case 0x27df0:
          goto LAB_00029094;
        case 0x27e14:
          goto switchD_0002776c_caseD_27e14;
        case 0x27ef0:
          goto switchD_0002776c_caseD_27ef0;
        case 0x27fa4:
          for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {
            uVar10 = 0;
            if (uVar16 == 0) goto LAB_00027d94;
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
        case 0x28014:
          if (puVar18[3] == 0) {
            param_1[3] = (int)_Dst;
            param_1[4] = uVar19;
            *param_1 = (int)_Src;
            param_1[1] = uVar16;
            puVar18[0xe] = uVar17;
            puVar18[0xf] = uVar15;
            return 2;
          }
          uVar9 = FUN_0002910c(0,(byte *)0x0,0);
          puVar18[6] = uVar9;
          param_1[0xc] = uVar9;
          *puVar18 = 0xb;
switchD_0002776c_caseD_28048:
          if (puVar18[1] == 0) {
            for (; uVar15 < 3; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027d94;
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
            goto LAB_00028f10;
          }
          uVar17 = uVar17 >> (uVar15 & 7);
          uVar15 = uVar15 - (uVar15 & 7);
          uVar9 = 0x18;
          goto LAB_00028f0c;
        case 0x28048:
          goto switchD_0002776c_caseD_28048;
        case 0x2814c:
          uVar17 = uVar17 >> (uVar15 & 7);
          for (uVar15 = uVar15 - (uVar15 & 7); uVar15 < 0x20; uVar15 = uVar15 + 8) {
            uVar10 = 0;
            if (uVar16 == 0) goto LAB_00027d94;
            uVar16 = uVar16 - 1;
            uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
            _Src = (uint *)((int)_Src + 1);
          }
          if ((uVar17 & 0xffff) == ~uVar17 >> 0x10) {
            puVar18[0x10] = uVar17 & 0xffff;
            uVar17 = 0;
            *puVar18 = 0xe;
            uVar15 = 0;
            goto switchD_0002776c_caseD_281bc;
          }
          param_1[6] = (int)local_30;
          break;
        case 0x281bc:
switchD_0002776c_caseD_281bc:
          uVar9 = puVar18[0x10];
          if (uVar9 != 0) {
            if (uVar16 < uVar9) {
              uVar9 = uVar16;
            }
            if (uVar19 < uVar9) {
              uVar9 = uVar19;
            }
            uVar10 = uVar16;
            if (uVar9 == 0) goto LAB_00027d94;
            memcpy(_Dst,_Src,uVar9);
            uVar19 = uVar19 - uVar9;
            puVar18[0x10] = puVar18[0x10] - uVar9;
            uVar16 = uVar16 - uVar9;
            _Src = (uint *)(uVar9 + (int)_Src);
            _Dst = _Dst + uVar9;
            local_6c = uVar19;
            goto LAB_00028f10;
          }
          goto LAB_00027f9c;
        case 0x28224:
          for (; uVar15 < 0xe; uVar15 = uVar15 + 8) {
            uVar10 = 0;
            if (uVar16 == 0) goto LAB_00027d94;
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
            goto switchD_0002776c_caseD_282b4;
          }
          param_1[6] = (int)local_34;
          break;
        case 0x282b4:
switchD_0002776c_caseD_282b4:
          if (puVar18[0x1a] < puVar18[0x17]) {
            do {
              for (; uVar15 < 3; uVar15 = uVar15 + 8) {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027d94;
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
          local_78 = FUN_00029478(0,(ushort *)(puVar18 + 0x1c),0x13,(int *)(puVar18 + 0x1b),
                                  puVar18 + 0x15,(ushort *)(puVar18 + 0xbc));
          if (local_78 == 0) {
            puVar18[0x1a] = 0;
            *puVar18 = 0x11;
            goto LAB_00028400;
          }
          param_1[6] = (int)pcVar4;
          break;
        case 0x283fc:
LAB_00028400:
          if (puVar18[0x1a] < puVar18[0x19] + puVar18[0x18]) {
            do {
              local_74 = *(uint *)(((1 << (puVar18[0x15] & 0x1f)) - 1U & uVar17) * 4 + puVar18[0x13]
                                  );
              uVar9 = local_74 >> 8 & 0xff;
              if (uVar15 < uVar9) {
                do {
                  uVar10 = 0;
                  if (uVar16 == 0) goto LAB_00027d94;
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
                    if (uVar16 == 0) goto LAB_00027d94;
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
                    goto LAB_00028664;
                  }
                }
                else {
                  if (local_74._2_2_ == 0x11) {
                    for (; uVar15 < uVar9 + 3; uVar15 = uVar15 + 8) {
                      uVar10 = 0;
                      if (uVar16 == 0) goto LAB_00027d94;
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
                      if (uVar16 == 0) goto LAB_00027d94;
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
LAB_00028664:
                  if (puVar18[0x1a] + iVar5 <= puVar18[0x19] + puVar18[0x18]) {
                    for (; iVar5 != 0; iVar5 = iVar5 + -1) {
                      *(undefined2 *)((puVar18[0x1a] + 0x38) * 2 + (int)puVar18) = uVar13;
                      puVar18[0x1a] = puVar18[0x1a] + 1;
                    }
                    goto LAB_000286b4;
                  }
                }
                param_1[6] = (int)local_5c;
                goto LAB_00028f08;
              }
              for (; uVar15 < uVar9; uVar15 = uVar15 + 8) {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027d94;
                uVar16 = uVar16 - 1;
                uVar17 = ((uint)(byte)*_Src << (uVar15 & 0x1f)) + uVar17;
                _Src = (uint *)((int)_Src + 1);
              }
              uVar17 = uVar17 >> (uVar9 & 0x1f);
              uVar15 = uVar15 - uVar9;
              *(ushort *)((puVar18[0x1a] + 0x38) * 2 + (int)puVar18) = local_74._2_2_;
              puVar18[0x1a] = puVar18[0x1a] + 1;
LAB_000286b4:
            } while (puVar18[0x1a] < puVar18[0x19] + puVar18[0x18]);
          }
          if (*puVar18 != 0x1b) {
            puVar6 = puVar18 + 0x1b;
            *puVar6 = (uint)(puVar18 + 0x14c);
            puVar18[0x13] = (uint)(puVar18 + 0x14c);
            puVar18[0x15] = 9;
            local_78 = FUN_00029478(1,(ushort *)(puVar18 + 0x1c),puVar18[0x18],(int *)puVar6,
                                    puVar18 + 0x15,(ushort *)(puVar18 + 0xbc));
            if (local_78 == 0) {
              puVar18[0x14] = *puVar6;
              puVar18[0x16] = 6;
              local_78 = FUN_00029478(2,(ushort *)((puVar18[0x18] + 0x38) * 2 + (int)puVar18),
                                      puVar18[0x19],(int *)puVar6,puVar18 + 0x16,
                                      (ushort *)(puVar18 + 0xbc));
              uVar19 = local_6c;
              if (local_78 == 0) {
                *puVar18 = 0x12;
                goto switchD_0002776c_caseD_287b4;
              }
              param_1[6] = (int)"invalid distances set";
            }
            else {
              param_1[6] = (int)"invalid literal/lengths set";
              uVar19 = local_6c;
            }
            break;
          }
          goto LAB_00028f10;
        case 0x287b4:
switchD_0002776c_caseD_287b4:
          if ((uVar16 < 6) || (uVar19 < 0x102)) {
            uVar14 = *(uint *)(((1 << (puVar18[0x15] & 0x1f)) - 1U & uVar17) * 4 + puVar18[0x13]);
            uVar9 = uVar14 >> 8 & 0xff;
            if (uVar15 < uVar9) {
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027d94;
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
                  if (uVar16 == 0) goto LAB_00027d94;
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
                  goto LAB_000289f8;
                }
                param_1[6] = (int)local_40;
                break;
              }
              uVar9 = 0xb;
            }
            goto LAB_00028f0c;
          }
          param_1[3] = (int)_Dst;
          param_1[4] = uVar19;
          *param_1 = (int)_Src;
          param_1[1] = uVar16;
          puVar18[0xe] = uVar17;
          puVar18[0xf] = uVar15;
          FUN_00029abc(param_1,local_64);
          uVar19 = param_1[4];
          _Dst = (undefined1 *)param_1[3];
          _Src = (uint *)*param_1;
          uVar16 = param_1[1];
          uVar17 = puVar18[0xe];
          uVar15 = puVar18[0xf];
          local_6c = uVar19;
          goto LAB_00028f10;
        case 0x289f4:
LAB_000289f8:
          uVar9 = puVar18[0x12];
          if (uVar9 != 0) {
            if (uVar15 < uVar9) {
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027d94;
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
          goto LAB_00028a6c;
        case 0x28a68:
LAB_00028a6c:
          uVar14 = *(uint *)(((1 << (puVar18[0x16] & 0x1f)) - 1U & uVar17) * 4 + puVar18[0x14]);
          uVar9 = uVar14 >> 8 & 0xff;
          if (uVar15 < uVar9) {
            do {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027d94;
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
                if (uVar16 == 0) goto LAB_00027d94;
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
LAB_00028c30:
          uVar9 = puVar18[0x12];
          if (uVar9 != 0) {
            if (uVar15 < uVar9) {
              do {
                uVar10 = 0;
                if (uVar16 == 0) goto LAB_00027d94;
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
switchD_0002776c_caseD_28cc0:
          uVar10 = uVar16;
          if (uVar19 == 0) goto LAB_00027d94;
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
            if (uVar10 < uVar9) goto LAB_00028d34;
          }
          else {
            uVar10 = puVar18[0x10];
            puVar12 = _Dst + -uVar9;
LAB_00028d34:
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
          if (puVar18[0x10] != 0) goto LAB_00028f10;
          uVar9 = 0x12;
          goto LAB_00028f0c;
        case 0x28c2c:
          goto LAB_00028c30;
        case 0x28cc0:
          goto switchD_0002776c_caseD_28cc0;
        case 0x28d84:
          if (uVar19 != 0) {
            uVar19 = uVar19 - 1;
            *_Dst = (char)puVar18[0x10];
            _Dst = _Dst + 1;
            uVar9 = 0x12;
            local_6c = uVar19;
            goto LAB_00028f0c;
          }
          goto LAB_00027d94;
        case 0x28da8:
          if (puVar18[2] != 0) {
            for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027d94;
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
                uVar9 = FUN_0002910c(puVar18[6],(byte *)puVar6,uVar9);
              }
              else if (puVar6 == (uint *)0x0) {
                uVar9 = 0;
              }
              else {
                uVar9 = FUN_00026ecc(puVar18[6],puVar6,uVar9);
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
        case 0x28eac:
          if ((puVar18[2] != 0) && (puVar18[4] != 0)) {
            for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {
              uVar10 = 0;
              if (uVar16 == 0) goto LAB_00027d94;
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
switchD_0002776c_caseD_28f8c:
          local_78 = 1;
          uVar10 = uVar16;
          goto LAB_00027d94;
        case 0x28f8c:
          goto switchD_0002776c_caseD_28f8c;
        case 0x28f98:
          local_78 = -3;
LAB_00027d94:
          uVar16 = local_64;
          puVar18[0xf] = uVar15;
          uVar15 = puVar18[10];
          param_1[3] = (int)_Dst;
          param_1[4] = local_6c;
          *param_1 = (int)_Src;
          param_1[1] = uVar10;
          puVar18[0xe] = uVar17;
          if (((uVar15 == 0) && ((0x17 < (int)*puVar18 || (local_64 == local_6c)))) ||
             (iVar5 = FUN_0002749c((int)param_1,local_64), iVar5 == 0)) {
            iVar5 = local_2c - param_1[1];
            uVar17 = puVar18[7];
            uVar16 = uVar16 - param_1[4];
            param_1[2] = param_1[2] + iVar5;
            uVar15 = puVar18[2];
            param_1[5] = param_1[5] + uVar16;
            puVar18[7] = uVar17 + uVar16;
            if ((uVar15 != 0) && (uVar16 != 0)) {
              if (puVar18[4] == 0) {
                uVar15 = FUN_0002910c(puVar18[6],(byte *)(param_1[3] - uVar16),uVar16);
              }
              else if ((uint *)(param_1[3] - uVar16) == (uint *)0x0) {
                uVar15 = 0;
              }
              else {
                uVar15 = FUN_00026ecc(puVar18[6],(uint *)(param_1[3] - uVar16),uVar16);
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
LAB_00029094:
          return -4;
        }
LAB_00028f08:
        uVar9 = 0x1b;
LAB_00028f0c:
        *puVar18 = uVar9;
LAB_00028f10:
        uVar9 = *puVar18;
      } while (uVar9 < 0x1d);
    }
  }
  return -2;
}



/* 000290c4 FUN_000290c4 */

/* Boundary evidence: original MIPS .pdata 000290c4..000290ef. Semantic name remains unreviewed. */

void FUN_000290c4(undefined4 param_1,int param_2,int param_3)

{
  malloc(param_2 * param_3);
  return;
}



/* 000290f0 FUN_000290f0 */

/* Boundary evidence: original MIPS .pdata 000290f0..0002910b. Semantic name remains unreviewed. */

void FUN_000290f0(undefined4 param_1,void *param_2)

{
  free(param_2);
  return;
}



/* 0002910c FUN_0002910c */

uint FUN_0002910c(uint param_1,byte *param_2,uint param_3)

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



/* 00029478 FUN_00029478 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 00029478..00029abb. Semantic name remains unreviewed. */

undefined4
FUN_00029478(int param_1,ushort *param_2,uint param_3,int *param_4,uint *param_5,ushort *param_6)

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
  
  local_30 = DAT_000372d0;
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
    FUN_0002a4f0(local_30);
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
      if (iVar6 < 0) goto LAB_00029a80;
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
        puVar5 = (ushort *)0x354a6;
        puVar20 = (ushort *)0x354e6;
      }
      else {
        iVar6 = -1;
        puVar5 = (ushort *)&DAT_00035728;
        puVar20 = (ushort *)&DAT_00035768;
      }
      uVar3 = 1 << (uVar17 & 0x1f);
      iVar18 = *param_4;
      uVar16 = 0;
      uVar9 = 0;
      uVar19 = uVar3 - 1;
      uVar4 = uVar3;
      uVar10 = 0xffffffff;
      if ((param_1 != 1) || (uVar3 < 0x5b0)) {
LAB_000297d4:
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
              goto joined_r0x000299d0;
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
          goto LAB_000297d4;
        }
      }
      FUN_0002a4f0(local_30);
      uVar2 = 1;
    }
    else {
LAB_00029a80:
      FUN_0002a4f0(local_30);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
joined_r0x000299d0:
  if (uVar16 == 0) {
LAB_00029a58:
    *param_4 = uVar3 * 4 + *param_4;
    *param_5 = uVar17;
    FUN_0002a4f0(local_30);
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
  if (uVar1 == 0) goto LAB_00029a58;
  uVar16 = (uVar1 - 1 & uVar16) + uVar1;
  goto joined_r0x000299d0;
}



/* 00029abc FUN_00029abc */

/* Boundary evidence: original MIPS .pdata 00029abc..0002a0bf. Semantic name remains unreviewed. */

void FUN_00029abc(int *param_1,int param_2)

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
LAB_00029b5c:
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
      goto joined_r0x00029d08;
    }
    if ((uVar12 & 0x40) != 0) {
      if ((uVar12 & 0x20) != 0) {
        *puVar21 = 0xb;
        goto LAB_0002a01c;
      }
      pcVar8 = "invalid literal/length code";
      *puVar21 = 0x1b;
      goto LAB_0002a018;
    }
    uVar12 = *(uint *)((((1 << (uVar12 & 0x1f)) - 1U & uVar1) + (uint)uStack_2e) * 4 + iVar3);
    uVar1 = uVar1 >> (uVar12 >> 8 & 0x1f);
    uVar26 = uVar26 - (uVar12 >> 8 & 0xff);
  }
  puVar18[1] = (char)(uVar12 >> 0x10);
  puVar19 = puVar18 + 1;
  goto LAB_00029c38;
joined_r0x00029d08:
  if ((uVar12 & 0x10) != 0) goto LAB_00029d6c;
  if ((uVar12 & 0x40) != 0) {
    param_1[6] = (int)"invalid distance code";
    *puVar21 = 0x1b;
    goto LAB_0002a01c;
  }
  uVar12 = *(uint *)((((1 << (uVar12 & 0x1f)) - 1U & uVar1) + (uVar12 >> 0x10)) * 4 + iVar2);
  uVar1 = uVar1 >> (uVar12 >> 8 & 0x1f);
  uVar26 = uVar26 - (uVar12 >> 8 & 0xff);
  goto joined_r0x00029d08;
LAB_00029d6c:
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
    goto LAB_00029c38;
  }
  uVar27 = uVar12 - ((int)puVar18 - (int)(puVar17 + (iVar10 - param_2)));
  if (uVar25 < uVar27) {
    pcVar8 = "invalid distance too far back";
    *puVar21 = 0x1b;
LAB_0002a018:
    param_1[6] = (int)pcVar8;
    pbVar11 = pbVar5;
LAB_0002a01c:
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
LAB_00029ec4:
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
        goto LAB_00029ec4;
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
      goto LAB_00029ec4;
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
LAB_00029c38:
  pbVar11 = pbVar5;
  puVar18 = puVar19;
  if ((pbVar22 <= pbVar5) || (puVar17 + iVar10 + -0x101 <= puVar19)) goto LAB_0002a01c;
  goto LAB_00029b5c;
}



/* 0002a4f0 FUN_0002a4f0 */

/* Boundary evidence: original MIPS .pdata 0002a4f0..0002a537. Semantic name remains unreviewed. */

void FUN_0002a4f0(uint param_1)

{
  if ((param_1 == DAT_000372d0) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 0002a5a8 FUN_0002a5a8 */

/* Boundary evidence: original MIPS .pdata 0002a5a8..0002a6b3. Semantic name remains unreviewed. */

undefined4 FUN_0002a5a8(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_00039894;
  puVar3 = DAT_00039890;
  iVar4 = (int)DAT_00039890 - (int)DAT_00039894;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_0002a5ec:
    param_1 = 0;
  }
  else {
    if (DAT_00039894 != (void *)0x0) {
      uVar1 = _msize(DAT_00039894);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_0002a660:
        if (pvVar2 == (void *)0x0) goto LAB_0002a5ec;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_0002a660;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_00039890 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_00039894 = pvVar2;
  }
  return param_1;
}



/* 0002a6b4 FUN_0002a6b4 */

/* Boundary evidence: original MIPS .pdata 0002a6b4..0002a79f. Semantic name remains unreviewed. */

undefined4 FUN_0002a6b4(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_00039898 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_00039898,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_00039898 == (LPCRITICAL_SECTION)0x0) goto LAB_0002a758;
  }
  EnterCriticalSection(DAT_00039898);
LAB_0002a758:
  uVar2 = FUN_0002a5a8(param_1);
  FUN_0002a7a0();
  return uVar2;
}



/* 0002a7a0 FUN_0002a7a0 */

/* Boundary evidence: original MIPS .pdata 0002a7a0..0002a7eb. Semantic name remains unreviewed. */

void FUN_0002a7a0(void)

{
  if (DAT_00039898 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_00039898);
  }
  return;
}



/* 0002a7ec FUN_0002a7ec */

/* Boundary evidence: original MIPS .pdata 0002a7ec..0002a81b. Semantic name remains unreviewed. */

undefined4 FUN_0002a7ec(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0002a6b4(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0002a89c FUN_0002a89c */

/* Boundary evidence: original MIPS .pdata 0002a89c..0002a92f. Semantic name remains unreviewed. */

void FUN_0002a89c(HINSTANCE param_1)

{
  WPARAM WVar1;
  
  FUN_0002ac70();
  WVar1 = FUN_00013c3c(param_1);
  FUN_0002abb0(WVar1);
  FUN_0002abd0(WVar1);
  return;
}



/* 0002a930 FUN_0002a930 */

/* Boundary evidence: original MIPS .pdata 0002a930..0002a96f. Semantic name remains unreviewed. */

void FUN_0002a930(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 0002a970 entry */

/* Boundary evidence: original MIPS .pdata 0002a970..0002a9cb. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1)

{
  FUN_0002a9dc();
  FUN_0002a89c(param_1);
  return;
}



/* 0002a9dc FUN_0002a9dc */

/* Boundary evidence: original MIPS .pdata 0002a9dc..0002aa4f. Semantic name remains unreviewed. */

void FUN_0002a9dc(void)

{
  uint uVar1;
  
  if ((DAT_000372d0 == 0) || (DAT_000372d0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000372d0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000372d0 == 0) {
      DAT_000372d0 = 0xb064;
    }
  }
  DAT_000372d4 = ~DAT_000372d0;
  return;
}



/* 0002aa90 FUN_0002aa90 */

/* Boundary evidence: original MIPS .pdata 0002aa90..0002abaf. Semantic name remains unreviewed. */

void FUN_0002aa90(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00037a40 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00039894;
    if (DAT_00039894 != (undefined4 *)0x0) {
      while (DAT_00039890 = DAT_00039890 + -1, _Memory <= DAT_00039890) {
        if ((code *)*DAT_00039890 != (code *)0x0) {
          (*(code *)*DAT_00039890)();
          _Memory = DAT_00039894;
        }
      }
      free(_Memory);
      DAT_00039890 = (undefined4 *)0x0;
      DAT_00039894 = (undefined4 *)0x0;
    }
    FUN_0002ac1c((undefined4 *)&DAT_0002c038,(undefined4 *)&DAT_0002c03c);
  }
  FUN_0002ac1c((undefined4 *)&DAT_0002c040,(undefined4 *)&DAT_0002c044);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_00039898,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 0002abb0 FUN_0002abb0 */

/* Boundary evidence: original MIPS .pdata 0002abb0..0002abcf. Semantic name remains unreviewed. */

void FUN_0002abb0(UINT param_1)

{
  FUN_0002aa90(param_1,0,0);
  return;
}



/* 0002abd0 FUN_0002abd0 */

/* Boundary evidence: original MIPS .pdata 0002abd0..0002ac1b. Semantic name remains unreviewed. */

void FUN_0002abd0(UINT param_1)

{
  DAT_00037a40 = 0;
  FUN_0002ac1c((undefined4 *)&DAT_0002c040,(undefined4 *)&DAT_0002c044);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 0002ac1c FUN_0002ac1c */

/* Boundary evidence: original MIPS .pdata 0002ac1c..0002ac6f. Semantic name remains unreviewed. */

void FUN_0002ac1c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 0002ac70 FUN_0002ac70 */

/* Boundary evidence: original MIPS .pdata 0002ac70..0002acab. Semantic name remains unreviewed. */

void FUN_0002ac70(void)

{
  FUN_0002ac1c((undefined4 *)&DAT_0002c030,(undefined4 *)&DAT_0002c034);
  FUN_0002ac1c((undefined4 *)&DAT_0002c000,(undefined4 *)&DAT_0002c02c);
  return;
}



/* 0002acbc FUN_0002acbc */

/* Boundary evidence: original MIPS .pdata 0002acbc..0002acdf. Semantic name remains unreviewed. */

void FUN_0002acbc(int param_1,SIZE_T param_2)

{
  HeapAlloc(*(HANDLE *)(param_1 + 4),0,param_2);
  return;
}



/* 0002ace0 FUN_0002ace0 */

/* Boundary evidence: original MIPS .pdata 0002ace0..0002ad0b. Semantic name remains unreviewed. */

void FUN_0002ace0(int param_1,LPVOID param_2)

{
  if (param_2 != (LPVOID)0x0) {
    HeapFree(*(HANDLE *)(param_1 + 4),0,param_2);
  }
  return;
}



/* 0002ad0c FUN_0002ad0c */

/* Boundary evidence: original MIPS .pdata 0002ad0c..0002ad73. Semantic name remains unreviewed. */

LPVOID FUN_0002ad0c(int *param_1,LPVOID param_2,SIZE_T param_3)

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



/* 0002ad74 FUN_0002ad74 */

/* Boundary evidence: original MIPS .pdata 0002ad74..0002ad97. Semantic name remains unreviewed. */

void FUN_0002ad74(int param_1,LPCVOID param_2)

{
  HeapSize(*(HANDLE *)(param_1 + 4),0,param_2);
  return;
}



/* 0002ad98 FUN_0002ad98 */

/* Boundary evidence: original MIPS .pdata 0002ad98..0002ae03. Semantic name remains unreviewed. */

undefined4 * FUN_0002ad98(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002c048;
  if ((*(char *)(param_1 + 2) != '\0') && ((HANDLE)param_1[1] != (HANDLE)0x0)) {
    HeapDestroy((HANDLE)param_1[1]);
  }
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0002ae04 FUN_0002ae04 */

/* Boundary evidence: original MIPS .pdata 0002ae04..0002ae2b. Semantic name remains unreviewed. */

void FUN_0002ae04(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 4))();
  return;
}



/* 0002ae2c FUN_0002ae2c */

/* Boundary evidence: original MIPS .pdata 0002ae2c..0002ae57. Semantic name remains unreviewed. */

int FUN_0002ae2c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return param_1 + 8;
}



/* 0002ae58 FUN_0002ae58 */

undefined4 FUN_0002ae58(undefined4 param_1)

{
  return param_1;
}



/* 0002ae60 FUN_0002ae60 */

/* Boundary evidence: original MIPS .pdata 0002ae60..0002aea3. Semantic name remains unreviewed. */

undefined4 * FUN_0002ae60(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002c05c;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0002aea4 FUN_0002aea4 */

/* Boundary evidence: original MIPS .pdata 0002aea4..0002af37. Semantic name remains unreviewed. */

int * FUN_0002aea4(int param_1,int param_2,uint param_3)

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



/* 0002af38 FUN_0002af38 */

/* Boundary evidence: original MIPS .pdata 0002af38..0002afaf. Semantic name remains unreviewed. */

int FUN_0002af38(int param_1,undefined4 param_2,int param_3,uint param_4)

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



/* 0002afb0 FUN_0002afb0 */

/* Boundary evidence: original MIPS .pdata 0002afb0..0002b00f. Semantic name remains unreviewed. */

void FUN_0002afb0(void)

{
  undefined1 auStack_50 [32];
  undefined **appuStack_30 [10];
  
  FUN_000232f4((int)auStack_50,"string too long");
  FUN_0001fa60(appuStack_30,auStack_50);
                    /* WARNING: Subroutine does not return */
  appuStack_30[0] = std::length_error::vftable;
  __CxxThrowException(appuStack_30,(ThrowInfo *)&DAT_000362c4);
}



/* 0002b010 Unwind@0002b010 */

/* Boundary evidence: original MIPS .pdata 0002b010..0002b03f. Semantic name remains unreviewed. */

void Unwind_0002b010(void)

{
  int in_v0;
  
  FUN_00021f48(in_v0 + -0x50);
  return;
}



/* 0002b040 FUN_0002b040 */

/* Boundary evidence: original MIPS .pdata 0002b040..0002b09f. Semantic name remains unreviewed. */

void FUN_0002b040(void)

{
  undefined1 auStack_50 [32];
  undefined **appuStack_30 [10];
  
  FUN_000232f4((int)auStack_50,"invalid string position");
  FUN_0001fa60(appuStack_30,auStack_50);
                    /* WARNING: Subroutine does not return */
  appuStack_30[0] = std::out_of_range::vftable;
  __CxxThrowException(appuStack_30,(ThrowInfo *)&DAT_00036300);
}



/* 0002b0a0 Unwind@0002b0a0 */

/* Boundary evidence: original MIPS .pdata 0002b0a0..0002b0cf. Semantic name remains unreviewed. */

void Unwind_0002b0a0(void)

{
  int in_v0;
  
  FUN_00021f48(in_v0 + -0x50);
  return;
}



/* 0002b0d0 FUN_0002b0d0 */

/* Boundary evidence: original MIPS .pdata 0002b0d0..0002b0eb. Semantic name remains unreviewed. */

void FUN_0002b0d0(void)

{
  __2_YAPAXI_Z();
  return;
}



/* 0002b31c FUN_0002b31c */

/* Boundary evidence: original MIPS .pdata 0002b31c..0002b347. Semantic name remains unreviewed. */

void FUN_0002b31c(void)

{
  FUN_0002b37c();
  return;
}



/* 0002b348 FUN_0002b348 */

/* Boundary evidence: original MIPS .pdata 0002b348..0002b37b. Semantic name remains unreviewed. */

void FUN_0002b348(void)

{
  RaiseException(0xc000000d,0,0,(ULONG_PTR *)0x0);
  return;
}



/* 0002b37c FUN_0002b37c */

/* Boundary evidence: original MIPS .pdata 0002b37c..0002b39b. Semantic name remains unreviewed. */

void FUN_0002b37c(void)

{
  FUN_0002b348();
  return;
}



/* 0002b39c FUN_0002b39c */

/* Boundary evidence: original MIPS .pdata 0002b39c..0002b423. Semantic name remains unreviewed. */

int FUN_0002b39c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == 1) {
    if (DAT_00037a8c == (code *)0x0) {
      DAT_00037a54 = param_1;
      return 1;
    }
    iVar3 = (*DAT_00037a8c)(param_1,1);
    uVar2 = param_1;
    uVar1 = DAT_00037a54;
  }
  else {
    if (param_2 != 0) {
      return 1;
    }
    if (DAT_00037a8c == (code *)0x0) {
      return 1;
    }
    iVar3 = (*DAT_00037a8c)(param_1,0);
    uVar2 = DAT_00037a54;
    uVar1 = DAT_00037a54;
  }
  DAT_00037a54 = uVar2;
  if (iVar3 == 0) {
    iVar3 = 0;
    DAT_00037a54 = uVar1;
  }
  return iVar3;
}



/* 0002b424 FUN_0002b424 */

/* Boundary evidence: original MIPS .pdata 0002b424..0002b47b. Semantic name remains unreviewed. */

void FUN_0002b424(LPCRITICAL_SECTION param_1)

{
  InitializeCriticalSection(param_1);
  return;
}



/* 0002b47c FUN_0002b47c */

/* Boundary evidence: original MIPS .pdata 0002b47c..0002b4a3. Semantic name remains unreviewed. */

bool FUN_0002b47c(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3fffffe9;
}



/* 0002b4a4 FUN_0002b4a4 */

/* Boundary evidence: original MIPS .pdata 0002b4a4..0002b4ff. Semantic name remains unreviewed. */

int FUN_0002b4a4(int *param_1,int param_2)

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



/* 0002b500 FUN_0002b500 */

/* Boundary evidence: original MIPS .pdata 0002b500..0002b547. Semantic name remains unreviewed. */

void FUN_0002b500(int param_1)

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



/* 0002b548 FUN_0002b548 */

/* Boundary evidence: original MIPS .pdata 0002b548..0002b5df. Semantic name remains unreviewed. */

undefined4 FUN_0002b548(int param_1,int param_2)

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
      puVar1 = (undefined4 *)FUN_0002b4a4((int *)(param_1 + 0x28),param_2);
      uVar2 = *puVar1;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar2;
}



/* 0002b5e0 FUN_0002b5e0 */

/* Boundary evidence: original MIPS .pdata 0002b5e0..0002b68b. Semantic name remains unreviewed. */

undefined4 * FUN_0002b5e0(undefined4 *param_1)

{
  HMODULE pHVar1;
  int iVar2;
  
  memset((LPCRITICAL_SECTION)(param_1 + 5),0,0x14);
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  *param_1 = 0x34;
  pHVar1 = DAT_00037a54;
  if (DAT_00037a54 == (HMODULE)0x0) {
    pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  }
  param_1[3] = 0x900;
  param_1[2] = pHVar1;
  param_1[1] = pHVar1;
  param_1[4] = &DAT_0002c150;
  iVar2 = FUN_0002b424((LPCRITICAL_SECTION)(param_1 + 5));
  if (iVar2 < 0) {
    DAT_00037a90 = 1;
  }
  return param_1;
}



/* 0002b6ac FUN_0002b6ac */

/* Boundary evidence: original MIPS .pdata 0002b6ac..0002b6ff. Semantic name remains unreviewed. */

void FUN_0002b6ac(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_0002a4f0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 0002b700 FUN_0002b700 */

/* Boundary evidence: original MIPS .pdata 0002b700..0002b72b. Semantic name remains unreviewed. */

undefined4 FUN_0002b700(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0002b6ac(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 0002b7cc FUN_0002b7cc */

/* Boundary evidence: original MIPS .pdata 0002b7cc..0002b83b. Semantic name remains unreviewed. */

void FUN_0002b7cc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0002b6ac(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 0002b85c FUN_0002b85c */

/* Boundary evidence: original MIPS .pdata 0002b85c..0002b883. Semantic name remains unreviewed. */

void FUN_0002b85c(void)

{
  DAT_00038f4c = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0002b884 FUN_0002b884 */

/* Boundary evidence: original MIPS .pdata 0002b884..0002b8ab. Semantic name remains unreviewed. */

void FUN_0002b884(void)

{
  DAT_00038f50 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0002b8ac FUN_0002b8ac */

/* Boundary evidence: original MIPS .pdata 0002b8ac..0002b8d3. Semantic name remains unreviewed. */

void FUN_0002b8ac(void)

{
  DAT_00038f54 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0002b8d4 FUN_0002b8d4 */

/* Boundary evidence: original MIPS .pdata 0002b8d4..0002b8fb. Semantic name remains unreviewed. */

void FUN_0002b8d4(void)

{
  DAT_00038f58 = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0002b8fc FUN_0002b8fc */

/* Boundary evidence: original MIPS .pdata 0002b8fc..0002b923. Semantic name remains unreviewed. */

void FUN_0002b8fc(void)

{
  DAT_00038f5c = RegisterWindowMessageW(L"Format Partition Disk!!!");
  return;
}



/* 0002b924 FUN_0002b924 */

/* Boundary evidence: original MIPS .pdata 0002b924..0002b943. Semantic name remains unreviewed. */

void FUN_0002b924(void)

{
  FUN_0002a7ec(&LAB_0002ba04);
  return;
}



/* 0002b944 FUN_0002b944 */

/* Boundary evidence: original MIPS .pdata 0002b944..0002b96f. Semantic name remains unreviewed. */

void FUN_0002b944(void)

{
  FUN_00011448();
  FUN_0002a7ec(FUN_0002ba18);
  return;
}



/* 0002b970 FUN_0002b970 */

/* Boundary evidence: original MIPS .pdata 0002b970..0002b9b7. Semantic name remains unreviewed. */

void FUN_0002b970(void)

{
  DAT_00037a48 = GetProcessHeap();
  DAT_00037a44 = &PTR_FUN_0002c048;
  DAT_00037a4c = 0;
  FUN_0002a7ec(FUN_0002ba38);
  return;
}



/* 0002b9b8 FUN_0002b9b8 */

/* Boundary evidence: original MIPS .pdata 0002b9b8..0002b9d7. Semantic name remains unreviewed. */

void FUN_0002b9b8(void)

{
  FUN_0002a7ec(&LAB_0002ba80);
  return;
}



/* 0002b9d8 FUN_0002b9d8 */

/* Boundary evidence: original MIPS .pdata 0002b9d8..0002ba03. Semantic name remains unreviewed. */

void FUN_0002b9d8(void)

{
  FUN_0002b5e0((undefined4 *)&DAT_00037a58);
  FUN_0002a7ec(FUN_0002ba94);
  return;
}



/* 0002ba18 FUN_0002ba18 */

/* Boundary evidence: original MIPS .pdata 0002ba18..0002ba37. Semantic name remains unreviewed. */

void FUN_0002ba18(void)

{
  FUN_00011730(&DAT_00038f60);
  return;
}



/* 0002ba38 FUN_0002ba38 */

/* Boundary evidence: original MIPS .pdata 0002ba38..0002ba7f. Semantic name remains unreviewed. */

void FUN_0002ba38(void)

{
  DAT_00037a44 = &PTR_FUN_0002c048;
  if ((DAT_00037a4c != '\0') && (DAT_00037a48 != (HANDLE)0x0)) {
    HeapDestroy(DAT_00037a48);
  }
  return;
}



/* 0002ba94 FUN_0002ba94 */

/* Boundary evidence: original MIPS .pdata 0002ba94..0002bab3. Semantic name remains unreviewed. */

void FUN_0002ba94(void)

{
  FUN_0002b500(0x37a58);
  return;
}


