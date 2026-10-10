/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 10001000 FUN_10001000 */

/* Boundary evidence: original MIPS .pdata 10001000..10001083. Semantic name remains unreviewed. */

undefined4 FUN_10001000(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  if (((param_2 != 0) && (param_2 < 3)) && (DAT_10009000 == 0)) {
    puVar1 = &DAT_1000a000;
    DAT_10009000 = param_1;
    do {
      *puVar1 = 2;
      puVar1 = puVar1 + 1;
    } while (puVar1 != (undefined4 *)0x1000a0a8);
    FUN_100015ec(0x26,1);
    FUN_100015ec(0x28,1);
    FUN_100015ec(0x27,1);
  }
  return 1;
}



/* 10001084 FUN_10001084 */

/* Boundary evidence: original MIPS .pdata 10001084..100011d3. Semantic name remains unreviewed. */

void FUN_10001084(int param_1,int param_2,wchar_t *param_3,undefined4 param_4)

{
  DWORD DVar1;
  DWORD DVar2;
  undefined *puVar3;
  undefined4 local_resc;
  _SYSTEMTIME _Stack_1028;
  wchar_t awStack_1018 [1024];
  WCHAR aWStack_818 [1024];
  uint local_18;
  
  local_18 = DAT_1000768c;
  local_resc = param_4;
  if ((param_2 == 3) ||
     (((&DAT_100076c0)[param_1] != 0 && ((int)(&DAT_1000a000)[param_1] <= param_2)))) {
    vswprintf_s(awStack_1018,0x400,param_3,(va_list)&local_resc);
    GetLocalTime(&_Stack_1028);
    puVar3 = PTR_u_MgrDbg_100070a4;
    if (param_1 < 0x2a) {
      puVar3 = (&PTR_u_MgrDbg_100070a4)[param_1];
    }
    DVar1 = GetTickCount();
    DVar2 = GetTickCount();
    wsprintfW(aWStack_818,L"[%02d:%02d:%02d:%d,%05d][%s] %s\r\n",(uint)_Stack_1028.wHour,
              (uint)_Stack_1028.wMinute,(uint)_Stack_1028.wSecond,DVar2 % 1000,DVar1 / 10,puVar3,
              awStack_1018);
    OutputDebugStringW(aWStack_818);
  }
  FUN_10003e34(local_18);
  return;
}



/* 100011d4 DbgPrintDLLVersion */

/* Boundary evidence: original MIPS .pdata 100011d4..1000120f. Semantic name remains unreviewed. */

void DbgPrintDLLVersion(void)

{
                    /* 0x11d4  6  DbgPrintDLLVersion */
  FUN_10001084(0x24,0,L"[CmnDll] Compiled Date=%S:%S\t\n","Nov  5 2012");
  return;
}



/* 10001210 DbgGetModuleName */

undefined * DbgGetModuleName(int param_1)

{
  undefined *puVar1;
  
                    /* 0x1210  5  DbgGetModuleName */
  puVar1 = PTR_u_MgrDbg_100070a4;
  if (param_1 < 0x2a) {
    puVar1 = (&PTR_u_MgrDbg_100070a4)[param_1];
  }
  return puVar1;
}



/* 10001244 DbgSetDebugOnOff */

void DbgSetDebugOnOff(int param_1,undefined4 param_2)

{
                    /* 0x1244  10  DbgSetDebugOnOff */
  if (param_1 < 0x2a) {
    (&DAT_100076c0)[param_1] = param_2;
  }
  return;
}



/* 1000126c DbgGetDebugOnOff */

undefined4 DbgGetDebugOnOff(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x126c  4  DbgGetDebugOnOff */
  uVar1 = DAT_100076c0;
  if (param_1 < 0x2a) {
    uVar1 = (&DAT_100076c0)[param_1];
  }
  return uVar1;
}



/* 100012a0 DbgSetDebugLevel */

/* Boundary evidence: original MIPS .pdata 100012a0..100012eb. Semantic name remains unreviewed. */

void DbgSetDebugLevel(int param_1,int param_2)

{
                    /* 0x12a0  9  DbgSetDebugLevel */
  if (param_1 < 0x2a) {
    (&DAT_1000a000)[param_1] = param_2;
  }
  FUN_10001084(0x14,1,L"DbgSetDebugLevel -> [%d]\r\n",param_2 + 1);
  return;
}



/* 100012ec DbgGetDebugLevel */

undefined4 DbgGetDebugLevel(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x12ec  3  DbgGetDebugLevel */
  uVar1 = DAT_1000a000;
  if (param_1 < 0x2a) {
    uVar1 = (&DAT_1000a000)[param_1];
  }
  return uVar1;
}



/* 10001320 DbgSetAllDebugOnOff */

void DbgSetAllDebugOnOff(undefined4 param_1)

{
  undefined4 *puVar1;
  
                    /* 0x1320  8  DbgSetAllDebugOnOff */
  puVar1 = &DAT_100076c0;
  do {
    *puVar1 = param_1;
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined4 *)0x10007768);
  return;
}



/* 10001344 DbgSetAllDebugLevel */

/* Boundary evidence: original MIPS .pdata 10001344..1000138b. Semantic name remains unreviewed. */

void DbgSetAllDebugLevel(int param_1)

{
  int *piVar1;
  
                    /* 0x1344  7  DbgSetAllDebugLevel */
  piVar1 = &DAT_1000a000;
  do {
    *piVar1 = param_1;
    piVar1 = piVar1 + 1;
  } while (piVar1 != (int *)0x1000a0a8);
  FUN_10001084(0x14,1,L"DbgSetAllDebugLevel -> [%d]\r\n",param_1 + 1);
  return;
}



/* 1000138c DbgDebugPrint2File */

/* Boundary evidence: original MIPS .pdata 1000138c..100015eb. Semantic name remains unreviewed. */

void DbgDebugPrint2File(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  HANDLE hFile;
  wchar_t *lpFileName;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  DWORD aDStack_828 [2];
  wchar_t local_820;
  undefined1 auStack_81e [2046];
  uint local_20;
  
                    /* 0x138c  2  DbgDebugPrint2File */
  local_20 = DAT_1000768c;
  local_820 = L'\n';
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memset(auStack_81e,0,0x7fe);
  vswprintf_s(&local_820,0x400,param_1,(va_list)&local_res4);
  sVar1 = wcslen(&local_820);
  DAT_10007778 = sVar1 + DAT_10007778;
  FUN_10001084(0x14,1,L"DbgDebugPrint2File Size = [%d]\r\n",DAT_10007778);
  lpFileName = L"debugfile_2.log";
  if (0x14fff < DAT_10007778) {
    if (DAT_100070a0 == 0) {
      lpFileName = L"debugfile_1.log";
    }
    DeleteFileW(lpFileName);
    DAT_100070a0 = (DAT_100070a0 + 1) % 2;
    DAT_10007778 = 0;
  }
  if (DAT_100070a0 == 0) {
    if (DAT_10007770 == 0) {
      hFile = CreateFileW(L"debugfile_2.log",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,
                          (HANDLE)0x0);
      DAT_10007770 = DAT_10007770 + 1;
    }
    else {
      hFile = CreateFileW(L"debugfile_2.log",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,
                          (HANDLE)0x0);
    }
  }
  else if (DAT_1000776c == 0) {
    hFile = CreateFileW(L"debugfile_1.log",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,
                        (HANDLE)0x0);
    DAT_1000776c = DAT_1000776c + 1;
  }
  else {
    hFile = CreateFileW(L"debugfile_1.log",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,
                        (HANDLE)0x0);
  }
  SetFilePointer(hFile,0,(PLONG)0x0,2);
  sVar1 = wcslen(&local_820);
  WriteFile(hFile,&local_820,sVar1 << 1,aDStack_828,(LPOVERLAPPED)0x0);
  CloseHandle(hFile);
  FUN_10003e34(local_20);
  return;
}



/* 100015ec FUN_100015ec */

/* Boundary evidence: original MIPS .pdata 100015ec..10001657. Semantic name remains unreviewed. */

void FUN_100015ec(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_u_MgrDbg_100070a4;
  if (param_1 < 0x2a) {
    (&DAT_1000a000)[param_1] = param_2;
    puVar1 = (&PTR_u_MgrDbg_100070a4)[param_1];
  }
  FUN_10001084(0x14,1,L"IntDbgSetDebugLevel -> [%s][%d]\r\n",puVar1);
  return;
}



/* 10001658 DbgDebugPrint */

/* Boundary evidence: original MIPS .pdata 10001658..10001833. Semantic name remains unreviewed. */

void DbgDebugPrint(int param_1,int param_2,wchar_t *param_3,undefined4 param_4)

{
  wchar_t wVar1;
  size_t sVar2;
  DWORD DVar3;
  DWORD DVar4;
  wchar_t *pwVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  undefined4 local_resc;
  _SYSTEMTIME _Stack_1030;
  wchar_t local_1020 [1024];
  WCHAR aWStack_820 [1024];
  uint local_20;
  
                    /* 0x1658  1  DbgDebugPrint */
  local_20 = DAT_1000768c;
  local_resc = param_4;
  if ((int)(&DAT_1000a000)[param_1] <= param_2) {
    vswprintf_s(local_1020,0x400,param_3,(va_list)&local_resc);
    sVar2 = wcslen(local_1020);
    iVar7 = sVar2 * 2;
    if (iVar7 != 0) {
      pwVar5 = local_1020;
      iVar8 = iVar7;
      do {
        if (*pwVar5 == L'%') {
          *pwVar5 = L'*';
        }
        iVar8 = iVar8 + -1;
        pwVar5 = pwVar5 + 1;
      } while (iVar8 != 0);
    }
    if ((local_1020[sVar2 * 2 + -1] == L'\n') || (local_1020[sVar2 * 2 + -1] == L'\r')) {
      local_1020[sVar2 * 2 + -1] = L'\0';
    }
    wVar1 = local_1020[iVar7 + -2];
    if ((wVar1 == L'\r') || (wVar1 == L'\n')) {
      local_1020[iVar7 + -2] = L'\0';
    }
    GetLocalTime(&_Stack_1030);
    puVar6 = PTR_u_MgrDbg_100070a4;
    if (param_1 < 0x2a) {
      puVar6 = (&PTR_u_MgrDbg_100070a4)[param_1];
    }
    DVar3 = GetTickCount();
    DVar4 = GetTickCount();
    iVar7 = param_2 + 1;
    pwVar5 = L"[%s][LV:%d][%02d:%02d:%02d:%d,%05d]%s\r\n";
    wsprintfW(aWStack_820,L"[%s][LV:%d][%02d:%02d:%02d:%d,%05d]%s\r\n",puVar6,iVar7,
              (uint)_Stack_1030.wHour,(uint)_Stack_1030.wMinute,(uint)_Stack_1030.wSecond,
              DVar4 % 1000,DVar3 / 10,local_1020);
    OutputDebugStringW(aWStack_820);
    DbgDebugPrint2File(aWStack_820,pwVar5,puVar6,iVar7);
  }
  FUN_10003e34(local_20);
  return;
}



/* 10001834 MFA_Dll_Read */

/* Boundary evidence: original MIPS .pdata 10001834..10001a67. Semantic name remains unreviewed. */

undefined4 MFA_Dll_Read(int param_1,int param_2,LPVOID param_3,DWORD param_4,LPDWORD param_5)

{
  HANDLE hFile;
  BOOL BVar1;
  wchar_t *pwVar2;
  wchar_t awStack_228 [256];
  uint local_28;
  
                    /* 0x1834  19  MFA_Dll_Read */
  local_28 = DAT_1000768c;
  if (param_1 == 0) {
    pwVar2 = L"%S ptchPath is NULL";
  }
  else if (param_2 == 0) {
    pwVar2 = L"%S ptchFilename is NULL";
  }
  else {
    if ((param_5 != (LPDWORD)0x0) && (param_3 != (LPVOID)0x0)) {
      swprintf_s(awStack_228,0x100,L"%s\\%s",param_1,param_2);
      FUN_10001084(0x24,3,L"%S szPath=%s","MFA_Dll_Read");
      hFile = CreateFileW(awStack_228,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
      if (hFile == (HANDLE)0xffffffff) {
        GetLastError();
        FUN_10001084(0x24,3,L"%S CreateFile fail, error=%d","MFA_Dll_Read");
      }
      else {
        BVar1 = ReadFile(hFile,param_3,param_4,param_5,(LPOVERLAPPED)0x0);
        if (BVar1 == 0) {
          GetLastError();
          FUN_10001084(0x24,3,L"%S ReadFile fail, error=%d","MFA_Dll_Read");
        }
        else {
          if (*param_5 != 0) {
            CloseHandle(hFile);
            FUN_10003e34(local_28);
            return 1;
          }
          FUN_10001084(0x24,3,L"%S### Fail =>You are at the End Of File ###","MFA_Dll_Read");
        }
        CloseHandle(hFile);
      }
      goto LAB_10001a34;
    }
    pwVar2 = L"%S pdwByteRead or dat is NULL";
  }
  FUN_10001084(0x24,3,pwVar2,"MFA_Dll_Read");
LAB_10001a34:
  FUN_10003e34(local_28);
  return 0;
}



/* 10001a68 MFA_Dll_Write */

/* Boundary evidence: original MIPS .pdata 10001a68..10001cb3. Semantic name remains unreviewed. */

undefined4 MFA_Dll_Write(LPCWSTR param_1,int param_2,LPCVOID param_3,DWORD param_4,LPDWORD param_5)

{
  BOOL BVar1;
  HANDLE hFile;
  wchar_t *pwVar2;
  wchar_t awStack_228 [256];
  uint local_28;
  
                    /* 0x1a68  20  MFA_Dll_Write */
  local_28 = DAT_1000768c;
  if (param_1 == (LPCWSTR)0x0) {
    pwVar2 = L"%S ptchPath is NULL";
  }
  else if (param_2 == 0) {
    pwVar2 = L"%S ptchFilename is NULL";
  }
  else {
    if ((param_5 != (LPDWORD)0x0) && (param_3 != (LPCVOID)0x0)) {
      BVar1 = CreateDirectoryW(param_1,(LPSECURITY_ATTRIBUTES)0x0);
      if (BVar1 == 0) {
        GetLastError();
        FUN_10001084(0x24,3,L"%S CreateDirectory fail, error=%d","MFA_Dll_Write");
      }
      swprintf_s(awStack_228,0x100,L"%s\\%s",param_1,param_2);
      FUN_10001084(0x24,3,L"%S szPath=%s","MFA_Dll_Write");
      hFile = CreateFileW(awStack_228,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
      if (hFile == (HANDLE)0xffffffff) {
        GetLastError();
        FUN_10001084(0x24,3,L"%S CreateFile fail, error=%d","MFA_Dll_Write");
      }
      else {
        BVar1 = WriteFile(hFile,param_3,param_4,param_5,(LPOVERLAPPED)0x0);
        if (BVar1 != 0) {
          CloseHandle(hFile);
          FUN_10003e34(local_28);
          return 1;
        }
        GetLastError();
        FUN_10001084(0x24,3,L"%S WriteFile fail, error=%d","MFA_Dll_Write");
        CloseHandle(hFile);
      }
      goto LAB_10001c80;
    }
    pwVar2 = L"%S pdwByteRead or dat is NULL";
  }
  FUN_10001084(0x24,3,pwVar2,"MFA_Dll_Write");
LAB_10001c80:
  FUN_10003e34(local_28);
  return 0;
}



/* 10001cb4 FUN_10001cb4 */

/* Boundary evidence: original MIPS .pdata 10001cb4..10001d53. Semantic name remains unreviewed. */

bool FUN_10001cb4(undefined4 *param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateFileW(param_2,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *param_1 = pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    GetLastError();
    FUN_10001084(0x27,3,L"%S CreateFile fail, errCode=%d","CDriverI2C::openI2C");
  }
  return pvVar1 != (HANDLE)0xffffffff;
}



/* 10001d54 FUN_10001d54 */

/* Boundary evidence: original MIPS .pdata 10001d54..10001f27. Semantic name remains unreviewed. */

BOOL FUN_10001d54(undefined4 *param_1,undefined1 param_2,undefined1 param_3,void *param_4,
                 uint param_5)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD aDStack_30 [2];
  
  BVar2 = 0;
  if (param_5 < 0x200) {
    DVar1 = WaitForSingleObject((HANDLE)param_1[1],0xffffffff);
    if (DVar1 == 0) {
      DAT_10007790 = param_5;
      DAT_1000778c = param_2;
      DAT_10007794 = param_3;
      BVar2 = DeviceIoControl((HANDLE)*param_1,0x80002002,&DAT_1000778c,0x208,&DAT_10007795,param_5,
                              aDStack_30,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        GetLastError();
        FUN_10001084(0x27,3,L"%S DeviceIoControl fail, errCode=%d","CDriverI2C::readI2C");
      }
      else {
        memcpy(param_4,&DAT_10007795,DAT_10007790);
      }
    }
    else if (DVar1 == 0xffffffff) {
      GetLastError();
      FUN_10001084(0x27,3,L"%S WaitForSingleObject fail(WAIT_FAILED), errCode=%d",
                   "CDriverI2C::readI2C");
    }
    else {
      GetLastError();
      FUN_10001084(0x27,3,L"%S WaitForSingleObject fail(dw=%d), errCode=%d","CDriverI2C::readI2C");
    }
    ReleaseMutex((HANDLE)param_1[1]);
  }
  else {
    BVar2 = 0;
  }
  return BVar2;
}



/* 10001f28 FUN_10001f28 */

/* Boundary evidence: original MIPS .pdata 10001f28..10002113. Semantic name remains unreviewed. */

BOOL FUN_10001f28(undefined4 *param_1,undefined1 param_2,int param_3,void *param_4,uint param_5)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD aDStack_30 [2];
  
  BVar2 = 0;
  if (param_5 < 0x200) {
    DVar1 = WaitForSingleObject((HANDLE)param_1[1],0xffffffff);
    if (DVar1 == 0) {
      DAT_10007994 = param_2;
      if (param_3 == 0xff) {
        memcpy(&DAT_1000799c,param_4,param_5);
      }
      else {
        DAT_1000799c = (undefined1)param_3;
        memcpy(&DAT_1000799d,param_4,param_5);
        param_5 = param_5 + 1;
      }
      DAT_10007998 = param_5;
      BVar2 = DeviceIoControl((HANDLE)*param_1,0x80002001,&DAT_10007994,param_5 + 0x207,(LPVOID)0x0,
                              0,aDStack_30,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        GetLastError();
        FUN_10001084(0x27,3,L"%S DeviceIoControl fail, errCode=%d","CDriverI2C::writeI2C");
      }
    }
    else if (DVar1 == 0xffffffff) {
      GetLastError();
      FUN_10001084(0x27,3,L"%S WaitForSingleObject fail(WAIT_FAILED), errCode=%d",
                   "CDriverI2C::writeI2C");
    }
    else {
      GetLastError();
      FUN_10001084(0x27,3,L"%S WaitForSingleObject fail(dw=%d), errCode=%d","CDriverI2C::writeI2C");
    }
    ReleaseMutex((HANDLE)param_1[1]);
  }
  else {
    BVar2 = 0;
  }
  return BVar2;
}



/* 10002114 FUN_10002114 */

/* Boundary evidence: original MIPS .pdata 10002114..10002183. Semantic name remains unreviewed. */

void FUN_10002114(undefined4 *param_1)

{
  BOOL BVar1;
  
  BVar1 = CloseHandle((HANDLE)*param_1);
  if (BVar1 == 0) {
    GetLastError();
    FUN_10001084(0x27,3,L"%S CloseHandle fail, errCode=%d","CDriverI2C::closeI2C");
  }
  *param_1 = 0xffffffff;
  return;
}



/* 10002184 FUN_10002184 */

/* Boundary evidence: original MIPS .pdata 10002184..1000224f. Semantic name remains unreviewed. */

undefined4 FUN_10002184(int param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,param_2);
  *(HANDLE *)(param_1 + 4) = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    DVar2 = GetLastError();
    if (DVar2 == 0xb7) {
      FUN_10001084(0x27,3,L"%S CreateMutex(%s) fail, already exists","CDriverI2C::openMutex");
    }
    else {
      GetLastError();
      FUN_10001084(0x27,3,L"%S CreateMutex(%s) fail, errCode=%d","CDriverI2C::openMutex");
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* 10002250 FUN_10002250 */

/* Boundary evidence: original MIPS .pdata 10002250..100022cb. Semantic name remains unreviewed. */

void FUN_10002250(int param_1)

{
  BOOL BVar1;
  
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0x0) {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 4));
    if (BVar1 == 0) {
      GetLastError();
      FUN_10001084(0x27,3,L"%S CloseHandle fail, errCode=%d","CDriverI2C::closeMutex");
    }
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
  }
  return;
}



/* 100022cc MI2C_Dll_Read */

/* Boundary evidence: original MIPS .pdata 100022cc..100022eb. Semantic name remains unreviewed. */

void MI2C_Dll_Read(undefined4 *param_1,undefined1 param_2,undefined1 param_3,void *param_4,
                  uint param_5)

{
                    /* 0x22cc  23  MI2C_Dll_Read */
  FUN_10001d54(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 100022ec MI2C_Dll_Write */

/* Boundary evidence: original MIPS .pdata 100022ec..1000230b. Semantic name remains unreviewed. */

void MI2C_Dll_Write(undefined4 *param_1,undefined1 param_2,int param_3,void *param_4,uint param_5)

{
                    /* 0x22ec  24  MI2C_Dll_Write */
  FUN_10001f28(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 1000230c MI2C_Dll_Close */

/* Boundary evidence: original MIPS .pdata 1000230c..1000234b. Semantic name remains unreviewed. */

void MI2C_Dll_Close(undefined4 *param_1)

{
                    /* 0x230c  21  MI2C_Dll_Close */
  if (param_1 != (undefined4 *)0x0) {
    FUN_10002250((int)param_1);
    FUN_10002114(param_1);
    __3_YAXPAX_Z(param_1);
  }
  return;
}



/* 1000234c MI2C_Dll_Init */

/* Boundary evidence: original MIPS .pdata 1000234c..10002433. Semantic name remains unreviewed. */

undefined4 * MI2C_Dll_Init(void)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined3 extraout_var;
  int iVar3;
  wchar_t *pwVar4;
  
                    /* 0x234c  22  MI2C_Dll_Init */
  puVar2 = (undefined4 *)__2_YAPAXI_Z(8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0xffffffff;
    puVar2[1] = 0xffffffff;
  }
  if (puVar2 == (undefined4 *)0x0) {
    FUN_10001084(0x27,3,L"%S not created","MI2C_Dll_Init");
  }
  else {
    bVar1 = FUN_10001cb4(puVar2,L"SMB1:");
    if (CONCAT31(extraout_var,bVar1) == 0) {
      pwVar4 = L"%S openI2C fail";
    }
    else {
      iVar3 = FUN_10002184((int)puVar2,L"MUTEXI2C");
      if (iVar3 != 0) {
        return puVar2;
      }
      pwVar4 = L"%S openMutex fail";
    }
    FUN_10001084(0x27,3,pwVar4,"MI2C_Dll_Init");
    FUN_10002250((int)puVar2);
    FUN_10002114(puVar2);
    __3_YAXPAX_Z(puVar2);
  }
  return (undefined4 *)0x0;
}



/* 10002434 FUN_10002434 */

/* Boundary evidence: original MIPS .pdata 10002434..100024d3. Semantic name remains unreviewed. */

bool FUN_10002434(undefined4 *param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateFileW(param_2,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *param_1 = pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    GetLastError();
    FUN_10001084(0x28,3,L"%S CreateFile fail, errCode=%d","CDriverIoCtl::openIoCtl");
  }
  return pvVar1 != (HANDLE)0xffffffff;
}



/* 100024d4 FUN_100024d4 */

/* Boundary evidence: original MIPS .pdata 100024d4..10002653. Semantic name remains unreviewed. */

BOOL FUN_100024d4(undefined4 *param_1,DWORD param_2,LPVOID param_3,DWORD param_4)

{
  DWORD DVar1;
  BOOL BVar2;
  
  BVar2 = 0;
  DVar1 = WaitForSingleObject((HANDLE)param_1[1],0xffffffff);
  if (DVar1 == 0) {
    BVar2 = DeviceIoControl((HANDLE)*param_1,param_2,(LPVOID)0x0,0,param_3,param_4,(LPDWORD)0x0,
                            (LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      GetLastError();
      FUN_10001084(0x28,3,L"%S DeviceIoControl fail, errCode=%d","CDriverIoCtl::readIoCtl");
    }
  }
  else if (DVar1 == 0xffffffff) {
    GetLastError();
    FUN_10001084(0x28,3,L"%S WaitForSingleObject fail(WAIT_FAILED), errCode=%d",
                 "CDriverIoCtl::readIoCtl");
  }
  else {
    GetLastError();
    FUN_10001084(0x28,3,L"%S WaitForSingleObject fail(dw=%d), errCode=%d","CDriverIoCtl::readIoCtl")
    ;
  }
  ReleaseMutex((HANDLE)param_1[1]);
  return BVar2;
}



/* 10002654 FUN_10002654 */

/* Boundary evidence: original MIPS .pdata 10002654..100027d3. Semantic name remains unreviewed. */

BOOL FUN_10002654(undefined4 *param_1,DWORD param_2,LPVOID param_3,DWORD param_4)

{
  DWORD DVar1;
  BOOL BVar2;
  
  BVar2 = 0;
  DVar1 = WaitForSingleObject((HANDLE)param_1[1],0xffffffff);
  if (DVar1 == 0) {
    BVar2 = DeviceIoControl((HANDLE)*param_1,param_2,param_3,param_4,(LPVOID)0x0,0,(LPDWORD)0x0,
                            (LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      GetLastError();
      FUN_10001084(0x28,3,L"%S DeviceIoControl fail, errCode=%d","CDriverIoCtl::writeIoCtl");
    }
  }
  else if (DVar1 == 0xffffffff) {
    GetLastError();
    FUN_10001084(0x28,3,L"%S WaitForSingleObject fail(WAIT_FAILED), errCode=%d",
                 "CDriverIoCtl::writeIoCtl");
  }
  else {
    GetLastError();
    FUN_10001084(0x28,3,L"%S WaitForSingleObject fail(dw=%d), errCode=%d","CDriverIoCtl::writeIoCtl"
                );
  }
  ReleaseMutex((HANDLE)param_1[1]);
  return BVar2;
}



/* 100027d4 FUN_100027d4 */

/* Boundary evidence: original MIPS .pdata 100027d4..10002843. Semantic name remains unreviewed. */

void FUN_100027d4(undefined4 *param_1)

{
  BOOL BVar1;
  
  BVar1 = CloseHandle((HANDLE)*param_1);
  if (BVar1 == 0) {
    GetLastError();
    FUN_10001084(0x28,3,L"%S CloseHandle fail, errCode=%d","CDriverIoCtl::closeIoCtl");
  }
  *param_1 = 0xffffffff;
  return;
}



/* 10002844 FUN_10002844 */

/* Boundary evidence: original MIPS .pdata 10002844..1000290f. Semantic name remains unreviewed. */

undefined4 FUN_10002844(int param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,param_2);
  *(HANDLE *)(param_1 + 4) = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    DVar2 = GetLastError();
    if (DVar2 == 0xb7) {
      FUN_10001084(0x28,3,L"%S CreateMutex(%s) fail, already exists","CDriverIoCtl::openMutex");
    }
    else {
      GetLastError();
      FUN_10001084(0x28,3,L"%S CreateMutex(%s) fail, errCode=%d","CDriverIoCtl::openMutex");
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* 10002910 FUN_10002910 */

/* Boundary evidence: original MIPS .pdata 10002910..1000298b. Semantic name remains unreviewed. */

void FUN_10002910(int param_1)

{
  BOOL BVar1;
  
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0x0) {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 4));
    if (BVar1 == 0) {
      GetLastError();
      FUN_10001084(0x28,3,L"%S CloseHandle fail, errCode=%d","CDriverIoCtl::closeMutex");
    }
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
  }
  return;
}



/* 1000298c MIOCTL_Dll_Read */

/* Boundary evidence: original MIPS .pdata 1000298c..100029a7. Semantic name remains unreviewed. */

void MIOCTL_Dll_Read(undefined4 *param_1,DWORD param_2,LPVOID param_3,DWORD param_4)

{
                    /* 0x298c  27  MIOCTL_Dll_Read */
  FUN_100024d4(param_1,param_2,param_3,param_4);
  return;
}



/* 100029a8 MIOCTL_Dll_Write */

/* Boundary evidence: original MIPS .pdata 100029a8..100029c3. Semantic name remains unreviewed. */

void MIOCTL_Dll_Write(undefined4 *param_1,DWORD param_2,LPVOID param_3,DWORD param_4)

{
                    /* 0x29a8  28  MIOCTL_Dll_Write */
  FUN_10002654(param_1,param_2,param_3,param_4);
  return;
}



/* 100029c4 MIOCTL_Dll_Close */

/* Boundary evidence: original MIPS .pdata 100029c4..10002a03. Semantic name remains unreviewed. */

void MIOCTL_Dll_Close(undefined4 *param_1)

{
                    /* 0x29c4  25  MIOCTL_Dll_Close */
  if (param_1 != (undefined4 *)0x0) {
    FUN_10002910((int)param_1);
    FUN_100027d4(param_1);
    __3_YAXPAX_Z(param_1);
  }
  return;
}



/* 10002a04 MIOCTL_Dll_Init */

/* Boundary evidence: original MIPS .pdata 10002a04..10002aeb. Semantic name remains unreviewed. */

undefined4 * MIOCTL_Dll_Init(void)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined3 extraout_var;
  int iVar3;
  wchar_t *pwVar4;
  
                    /* 0x2a04  26  MIOCTL_Dll_Init */
  puVar2 = (undefined4 *)__2_YAPAXI_Z(8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0xffffffff;
    puVar2[1] = 0xffffffff;
  }
  if (puVar2 == (undefined4 *)0x0) {
    FUN_10001084(0x28,3,L"%S not created","MIOCTL_Dll_Init");
  }
  else {
    bVar1 = FUN_10002434(puVar2,L"MGR1:");
    if (CONCAT31(extraout_var,bVar1) == 0) {
      pwVar4 = L"%S openIoCtl fail";
    }
    else {
      iVar3 = FUN_10002844((int)puVar2,L"MUTEXIOCTL");
      if (iVar3 != 0) {
        return puVar2;
      }
      pwVar4 = L"%S openMutex fail";
    }
    FUN_10001084(0x28,3,pwVar4,"MIOCTL_Dll_Init");
    FUN_10002910((int)puVar2);
    FUN_100027d4(puVar2);
    __3_YAXPAX_Z(puVar2);
  }
  return (undefined4 *)0x0;
}



/* 10002aec IpcTest */

/* Boundary evidence: original MIPS .pdata 10002aec..10002b1b. Semantic name remains unreviewed. */

void IpcTest(void)

{
                    /* 0x2aec  18  IpcTest */
  FUN_10001084(0x25,0,L"%S","IpcTest");
  return;
}



/* 10002b1c IpcGetProcessHandle */

/* Boundary evidence: original MIPS .pdata 10002b1c..10002b67. Semantic name remains unreviewed. */

void IpcGetProcessHandle(int param_1)

{
                    /* 0x2b1c  13  IpcGetProcessHandle */
  if (0x29 < param_1) {
    FUN_10001084(0x25,3,L"%S overflow, pid=%d","IpcGetProcessHandle");
    param_1 = 0;
  }
  FUN_10003260(param_1);
  return;
}



/* 10002b68 IpcSetProcessHandle */

/* Boundary evidence: original MIPS .pdata 10002b68..10002bb7. Semantic name remains unreviewed. */

void IpcSetProcessHandle(int param_1,undefined4 param_2)

{
                    /* 0x2b68  17  IpcSetProcessHandle */
  if (param_1 < 0x2a) {
    FUN_10003248(param_1,param_2);
  }
  else {
    FUN_10001084(0x25,3,L"%S overflow, pid=%d","IpcSetProcessHandle");
  }
  return;
}



/* 10002bb8 IpcGetProcessName */

/* Boundary evidence: original MIPS .pdata 10002bb8..10002c03. Semantic name remains unreviewed. */

void IpcGetProcessName(int param_1)

{
                    /* 0x2bb8  14  IpcGetProcessName */
  if (0x29 < param_1) {
    FUN_10001084(0x25,3,L"%S overflow, pid=%d","IpcGetProcessName");
    param_1 = 0;
  }
  FUN_100031ec(param_1);
  return;
}



/* 10002c04 IpcGetProcessFullName */

/* Boundary evidence: original MIPS .pdata 10002c04..10002c7b. Semantic name remains unreviewed. */

undefined * IpcGetProcessFullName(int param_1)

{
  wchar_t *pwVar1;
  
                    /* 0x2c04  12  IpcGetProcessFullName */
  if (0x29 < param_1) {
    FUN_10001084(0x25,3,L"%S overflow, pid=%d","IpcGetProcessFullName");
    param_1 = 0;
  }
  pwVar1 = FUN_100031ec(param_1);
  swprintf_s((wchar_t *)&DAT_10007b9c,0x100,L"%s.exe",pwVar1);
  return &DAT_10007b9c;
}



/* 10002c7c IpcPostMsg */

/* Boundary evidence: original MIPS .pdata 10002c7c..10002ecf. Semantic name remains unreviewed. */

undefined4 IpcPostMsg(uint param_1,int param_2,int param_3,uint param_4,LPARAM *param_5)

{
  int *piVar1;
  BOOL BVar2;
  DWORD DVar3;
  LPARAM lParam;
  HWND hWnd;
  LPARAM local_28 [2];
  
                    /* 0x2c7c  15  IpcPostMsg */
  local_28[0] = 0;
  piVar1 = FUN_10003260(param_2);
  hWnd = (HWND)*piVar1;
  if (hWnd == (HWND)0x0) {
    FUN_100031ec(param_2);
    FUN_10001084(0x25,3,L"%S IntGetProcessHandle fail, proc=%s, src=%d, dst=%d, cmd=%d","IpcPostMsg"
                );
  }
  else {
    if (param_4 < 5) {
      memcpy(local_28,param_5,param_4);
      lParam = local_28[0];
    }
    else {
      FUN_10001084(0x25,3,L"%S extra data overflow, size=%d","IpcPostMsg");
      lParam = *param_5;
    }
    BVar2 = PostMessageW(hWnd,0x8064,(param_3 << 8 | param_1) << 8 | param_4,lParam);
    if (BVar2 != 0) {
      FUN_100031ec(param_2);
      FUN_100031ec(param_1);
      FUN_10001084(0x25,0,L"%S %s -> %s, cmd=%d, size=%d","IpcPostMsg");
      return 1;
    }
    DVar3 = GetLastError();
    if (DVar3 == 6) {
      FUN_10001084(0x25,3,L"%S PostMessage fail, src=%d, dst=%d, cmd=%d, invalid handle",
                   "IpcPostMsg");
    }
    else if (DVar3 == 0x578) {
      FUN_10001084(0x25,3,L"%S PostMessage fail, src=%d, dst=%d, cmd=%d, invalid window handle",
                   "IpcPostMsg");
    }
    else if (DVar3 == 0x583) {
      FUN_10001084(0x25,3,L"%S PostMessage fail, src=%d, dst=%d, cmd=%d, class does not exist",
                   "IpcPostMsg");
    }
    else if (DVar3 == 0x5b4) {
      FUN_10001084(0x25,3,L"%S PostMessage fail, src=%d, dst=%d, cmd=%d, timed out","IpcPostMsg");
    }
    else {
      FUN_10001084(0x25,3,L"%S PostMessage fail, src=%d, dst=%d, cmd=%d, errCode=%d","IpcPostMsg");
    }
  }
  return 0;
}



/* 10002ed0 IpcSendMsg */

/* Boundary evidence: original MIPS .pdata 10002ed0..10003173. Semantic name remains unreviewed. */

undefined4 IpcSendMsg(uint param_1,int param_2,int param_3,uint param_4,void *param_5)

{
  int *piVar1;
  int iVar2;
  DWORD local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  void *local_28;
  
                    /* 0x2ed0  16  IpcSendMsg */
  local_38 = 0;
  local_34 = 0;
  piVar1 = FUN_10003260(param_2);
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    FUN_100031ec(param_2);
    FUN_10001084(0x25,3,L"%S IntGetProcessHandle fail, proc=%s, src=%d, dst=%d, cmd=%d","IpcSendMsg"
                );
  }
  else {
    if (param_4 < 5) {
      memcpy(&local_34,param_5,param_4);
      iVar2 = SendMessageTimeout(iVar2,0x8064,(param_3 << 8 | param_1) << 8 | param_4 & 0xff,
                                 local_34,0,0x9c4,&local_38);
    }
    else {
      FUN_10001084(0x25,3,L"%S extra data send using wm_copydata, size=%d","IpcSendMsg");
      memset(&local_30,0,0xc);
      local_28 = param_5;
      local_30 = param_1 * 100 + param_2 + 0x8000 | param_3 << 0x10;
      local_2c = param_4;
      iVar2 = SendMessageTimeout(iVar2,0x4a,0,&local_30,0,0x9c4,&local_38);
    }
    if (iVar2 != 0) {
      FUN_100031ec(param_2);
      FUN_100031ec(param_1);
      FUN_10001084(0x25,0,L"%S %s -> %s, cmd=%d, size=%d","IpcSendMsg");
      return 1;
    }
    local_38 = GetLastError();
    if (local_38 == 0) {
      FUN_10001084(0x25,3,L"%S SendMessageTimeout fail, src=%d, dst=%d, cmd=%d, timeout",
                   "IpcSendMsg");
    }
    else if (local_38 == 6) {
      FUN_10001084(0x25,3,L"%S SendMessageTimeout fail, src=%d, dst=%d, cmd=%d, invalid handle",
                   "IpcSendMsg");
    }
    else if (local_38 == 0x578) {
      FUN_10001084(0x25,3,
                   L"%S SendMessageTimeout fail, src=%d, dst=%d, cmd=%d, invalid window handle",
                   "IpcSendMsg");
    }
    else {
      FUN_10001084(0x25,3,L"%S SendMessageTimeout fail, src=%d, dst=%d, cmd=%d, errCode=%d",
                   "IpcSendMsg");
    }
  }
  return 0;
}



/* 10003174 IpcGetMsg */

ushort * IpcGetMsg(ushort *param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
                    /* 0x3174  11  IpcGetMsg */
  if (param_2 == 0x4a) {
    puVar3 = (uint *)*param_4;
    uVar1 = *puVar3;
    uVar2 = puVar3[2];
    *(uint *)(param_1 + 4) = puVar3[1];
    *(uint *)(param_1 + 6) = uVar2;
    *param_1 = (ushort)((uVar1 & 0x7fff) / 100);
    param_1[2] = *(ushort *)((int)puVar3 + 2);
  }
  else if (param_2 == 0x8064) {
    param_1[2] = (ushort)(param_3 >> 0x10);
    *param_1 = (ushort)(param_3 >> 8) & 0xff;
    *(uint *)(param_1 + 4) = param_3 & 0xff;
    *(undefined4 **)(param_1 + 6) = param_4;
  }
  return param_1;
}



/* 100031ec FUN_100031ec */

/* Boundary evidence: original MIPS .pdata 100031ec..10003247. Semantic name remains unreviewed. */

wchar_t * FUN_100031ec(int param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 < 0x2a) {
    pwVar1 = u_MgrDbg_1000714c + param_1 * 0x10;
  }
  else {
    FUN_10001084(0x25,3,L"%S fail iPid=%d","IntGetProcessName");
    pwVar1 = u_MgrDbg_1000714c;
  }
  return pwVar1;
}



/* 10003248 FUN_10003248 */

void FUN_10003248(int param_1,undefined4 param_2)

{
  *(undefined4 *)(&DAT_10007d9c + param_1 * 4) = param_2;
  return;
}



/* 10003260 FUN_10003260 */

/* Boundary evidence: original MIPS .pdata 10003260..1000330f. Semantic name remains unreviewed. */

int * FUN_10003260(int param_1)

{
  wchar_t *lpClassName;
  HWND pHVar1;
  int *piVar2;
  
  piVar2 = (int *)(&DAT_10007d9c + param_1 * 4);
  if (*piVar2 == 0) {
    lpClassName = FUN_100031ec(param_1);
    pHVar1 = FindWindowW(lpClassName,(LPCWSTR)0x0);
    *piVar2 = (int)pHVar1;
    if (pHVar1 == (HWND)0x0) {
      GetLastError();
      FUN_100031ec(param_1);
      FUN_10001084(0x25,3,L"%S FindWindow fail, %s(%d), errCode=%d","IntGetProcessHandle");
    }
  }
  return piVar2;
}



/* 10003310 FUN_10003310 */

undefined4 * FUN_10003310(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



/* 10003324 FUN_10003324 */

/* Boundary evidence: original MIPS .pdata 10003324..100033bf. Semantic name remains unreviewed. */

void FUN_10003324(int param_1,void *param_2,int param_3,size_t param_4)

{
  if (*(int *)(param_1 + 8) == 0) {
    FUN_10001084(0x26,3,L"%S m_lpvMapView=NULL","CSharedMem::read");
  }
  else {
    memcpy(param_2,(void *)(*(int *)(param_1 + 8) + param_3),param_4);
  }
  return;
}



/* 100033c0 FUN_100033c0 */

/* Boundary evidence: original MIPS .pdata 100033c0..100033cb. Semantic name remains unreviewed. */

undefined4 FUN_100033c0(void)

{
  return 1;
}



/* 100033cc FUN_100033cc */

/* Boundary evidence: original MIPS .pdata 100033cc..1000345f. Semantic name remains unreviewed. */

void FUN_100033cc(int param_1,void *param_2,int param_3,size_t param_4)

{
  if (*(int *)(param_1 + 8) == 0) {
    FUN_10001084(0x26,3,L"%S m_lpvMapView=NULL","CSharedMem::write");
  }
  else {
    memcpy((void *)(*(int *)(param_1 + 8) + param_3),param_2,param_4);
  }
  return;
}



/* 10003460 FUN_10003460 */

/* Boundary evidence: original MIPS .pdata 10003460..1000346b. Semantic name remains unreviewed. */

undefined4 FUN_10003460(void)

{
  return 1;
}



/* 1000346c FUN_1000346c */

/* Boundary evidence: original MIPS .pdata 1000346c..10003503. Semantic name remains unreviewed. */

undefined4 FUN_1000346c(undefined4 param_1,HANDLE param_2)

{
  BOOL BVar1;
  
  FUN_10001084(0x26,0,L"%S invoked","CSharedMem::releaseShmMutex");
  if ((param_2 != (HANDLE)0x0) && (BVar1 = ReleaseMutex(param_2), BVar1 == 0)) {
    GetLastError();
    FUN_10001084(0x26,3,L"%S ReleaseMutex fail, error=%d","CSharedMem::releaseShmMutex");
  }
  return 1;
}



/* 10003504 FUN_10003504 */

/* Boundary evidence: original MIPS .pdata 10003504..100035db. Semantic name remains unreviewed. */

undefined4 FUN_10003504(undefined4 *param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,1,param_2);
  *param_1 = pvVar1;
  DVar2 = GetLastError();
  if ((HANDLE)*param_1 == (HANDLE)0x0) {
    FUN_10001084(0x26,3,L"%S CreateMutex(%s) error = %d","CSharedMem::createShmMutex");
    uVar3 = 0;
  }
  else if (DVar2 == 0xb7) {
    FUN_10001084(0x26,0,L"%S CreateMutex(%s) already exist","CSharedMem::createShmMutex");
  }
  else {
    FUN_1000346c(param_1,(HANDLE)*param_1);
  }
  return uVar3;
}



/* 100035dc FUN_100035dc */

/* Boundary evidence: original MIPS .pdata 100035dc..100037eb. Semantic name remains unreviewed. */

bool FUN_100035dc(undefined4 *param_1,LPCWSTR param_2,DWORD param_3,HANDLE param_4)

{
  DWORD DVar1;
  HANDLE hFileMappingObject;
  LPVOID pvVar2;
  
  if ((HANDLE)*param_1 == (HANDLE)0x0) {
    FUN_10001084(0x26,3,L"%S lpName=%s, m_hxMutex=NULL","CSharedMem::createShmMappingReadWrite");
  }
  else {
    DVar1 = WaitForSingleObject((HANDLE)*param_1,0xffffffff);
    if (DVar1 == 0) {
      hFileMappingObject =
           CreateFileMappingW(param_4,(LPSECURITY_ATTRIBUTES)0x0,4,0,param_3,param_2);
      param_1[1] = hFileMappingObject;
      if (hFileMappingObject != (HANDLE)0x0) {
        pvVar2 = MapViewOfFile(hFileMappingObject,0xf001f,0,0,0);
        param_1[2] = pvVar2;
        if (pvVar2 != (LPVOID)0x0) {
          FUN_10001084(0x26,0,L"%S lpName=%s success","CSharedMem::createShmMappingReadWrite");
        }
        else {
          GetLastError();
          FUN_10001084(0x26,3,L"%S lpName=%s, MapViewOfFile fail, error=%d",
                       "CSharedMem::createShmMappingReadWrite");
          CloseHandle((HANDLE)param_1[1]);
          param_1[1] = 0;
        }
        FUN_1000346c(param_1,(HANDLE)*param_1);
        return pvVar2 != (LPVOID)0x0;
      }
      DVar1 = GetLastError();
      FUN_10001084(0x26,3,L"%S lpName=%s, CreateFileMapping fail, error=%d",
                   "CSharedMem::createShmMappingReadWrite");
      if (DVar1 == 0xb7) {
        FUN_10001084(0x26,3,L"%S has already been made","CSharedMem::createShmMappingReadWrite");
      }
      FUN_1000346c(param_1,(HANDLE)*param_1);
    }
    else {
      GetLastError();
      FUN_10001084(0x26,3,L"%S lpName=%s, WaitForSingleObject fail, error=%d",
                   "CSharedMem::createShmMappingReadWrite");
    }
  }
  return false;
}



/* 100037ec FUN_100037ec */

/* Boundary evidence: original MIPS .pdata 100037ec..100039eb. Semantic name remains unreviewed. */

bool FUN_100037ec(undefined4 *param_1,LPCWSTR param_2,HANDLE param_3)

{
  DWORD DVar1;
  HANDLE hFileMappingObject;
  LPVOID pvVar2;
  
  if ((HANDLE)*param_1 == (HANDLE)0x0) {
    FUN_10001084(0x26,3,L"%S lpName=%s, m_hxMutex=NULL","CSharedMem::createShmMappingReadOnly");
  }
  else {
    DVar1 = WaitForSingleObject((HANDLE)*param_1,0xffffffff);
    if (DVar1 == 0) {
      hFileMappingObject = CreateFileMappingW(param_3,(LPSECURITY_ATTRIBUTES)0x0,2,0,0,param_2);
      param_1[1] = hFileMappingObject;
      if (hFileMappingObject != (HANDLE)0x0) {
        pvVar2 = MapViewOfFile(hFileMappingObject,4,0,0,0);
        param_1[2] = pvVar2;
        if (pvVar2 != (LPVOID)0x0) {
          FUN_10001084(0x26,0,L"%S lpName=%s success","CSharedMem::createShmMappingReadOnly");
        }
        else {
          GetLastError();
          FUN_10001084(0x26,3,L"%S lpName=%s, MapViewOfFile fail, error=%d",
                       "CSharedMem::createShmMappingReadOnly");
          CloseHandle((HANDLE)param_1[1]);
          param_1[1] = 0;
        }
        FUN_1000346c(param_1,(HANDLE)*param_1);
        return pvVar2 != (LPVOID)0x0;
      }
      DVar1 = GetLastError();
      FUN_10001084(0x26,3,L"%S lpName=%s, CreateFileMapping fail, error=%d",
                   "CSharedMem::createShmMappingReadOnly");
      if (DVar1 == 0xb7) {
        FUN_10001084(0x26,3,L"%S has already been made","CSharedMem::createShmMappingReadOnly");
      }
      FUN_1000346c(param_1,(HANDLE)*param_1);
    }
    else {
      GetLastError();
      FUN_10001084(0x26,3,L"%S lpName=%s, WaitForSingleObject fail, error=%d",
                   "CSharedMem::createShmMappingReadOnly");
    }
  }
  return false;
}



/* 100039ec MSHM_Dll_MakeMappingReadWrite */

/* Boundary evidence: original MIPS .pdata 100039ec..10003a1b. Semantic name remains unreviewed. */

bool MSHM_Dll_MakeMappingReadWrite(undefined4 *param_1,LPCWSTR param_2,DWORD param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  
                    /* 0x39ec  32  MSHM_Dll_MakeMappingReadWrite */
  bVar1 = FUN_100035dc(param_1,param_2,param_3,(HANDLE)0xffffffff);
  return CONCAT31(extraout_var,bVar1) != 0;
}



/* 10003a1c MSHM_Dll_MakeMappingReadOnly */

/* Boundary evidence: original MIPS .pdata 10003a1c..10003a4b. Semantic name remains unreviewed. */

bool MSHM_Dll_MakeMappingReadOnly(undefined4 *param_1,LPCWSTR param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  
                    /* 0x3a1c  31  MSHM_Dll_MakeMappingReadOnly */
  bVar1 = FUN_100037ec(param_1,param_2,(HANDLE)0xffffffff);
  return CONCAT31(extraout_var,bVar1) != 0;
}



/* 10003a4c MSHM_Dll_Read */

/* Boundary evidence: original MIPS .pdata 10003a4c..10003a67. Semantic name remains unreviewed. */

void MSHM_Dll_Read(int param_1,void *param_2,int param_3,size_t param_4)

{
                    /* 0x3a4c  33  MSHM_Dll_Read */
  FUN_10003324(param_1,param_2,param_3,param_4);
  return;
}



/* 10003a68 MSHM_Dll_Write */

/* Boundary evidence: original MIPS .pdata 10003a68..10003a83. Semantic name remains unreviewed. */

void MSHM_Dll_Write(int param_1,void *param_2,int param_3,size_t param_4)

{
                    /* 0x3a68  34  MSHM_Dll_Write */
  FUN_100033cc(param_1,param_2,param_3,param_4);
  return;
}



/* 10003a84 FUN_10003a84 */

/* Boundary evidence: original MIPS .pdata 10003a84..10003bb3. Semantic name remains unreviewed. */

void FUN_10003a84(undefined4 *param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
  if ((HANDLE)*param_1 == (HANDLE)0x0) {
    FUN_10001084(0x26,3,L"%S already mutex=NULL","CSharedMem::closeShmMapping");
  }
  else {
    DVar1 = WaitForSingleObject((HANDLE)*param_1,0xffffffff);
    if (DVar1 == 0) {
      FUN_1000346c(param_1,(HANDLE)*param_1);
    }
    else {
      GetLastError();
      FUN_10001084(0x26,3,L"%S WaitForSingleObject fail, error=%d","CSharedMem::closeShmMapping");
    }
    CloseHandle((HANDLE)*param_1);
  }
  if (((LPCVOID)param_1[2] != (LPCVOID)0x0) &&
     (BVar2 = UnmapViewOfFile((LPCVOID)param_1[2]), BVar2 == 0)) {
    GetLastError();
    FUN_10001084(0x26,3,L"%S UnmapViewOfFile fail, error=%d","CSharedMem::closeShmMapping");
  }
  if ((HANDLE)param_1[1] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[1]);
  }
  return;
}



/* 10003bb4 FUN_10003bb4 */

/* Boundary evidence: original MIPS .pdata 10003bb4..10003bcf. Semantic name remains unreviewed. */

void FUN_10003bb4(undefined4 *param_1)

{
  FUN_10003a84(param_1);
  return;
}



/* 10003bd0 MSHM_Dll_DestoryShmClassObj */

/* Boundary evidence: original MIPS .pdata 10003bd0..10003c07. Semantic name remains unreviewed. */

void MSHM_Dll_DestoryShmClassObj(undefined4 *param_1)

{
                    /* 0x3bd0  30  MSHM_Dll_DestoryShmClassObj */
  if (param_1 != (undefined4 *)0x0) {
    FUN_10003a84(param_1);
    __3_YAXPAX_Z(param_1);
  }
  return;
}



/* 10003c08 MSHM_Dll_CreateShmClassObj */

/* Boundary evidence: original MIPS .pdata 10003c08..10003caf. Semantic name remains unreviewed. */

undefined4 * MSHM_Dll_CreateShmClassObj(LPCWSTR param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x3c08  29  MSHM_Dll_CreateShmClassObj */
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_10001084(0x26,3,L"%S not created","MSHM_Dll_CreateShmClassObj");
  }
  else {
    iVar2 = FUN_10003504(puVar1,param_1);
    if (iVar2 == 0) {
      FUN_10003a84(puVar1);
      __3_YAXPAX_Z(puVar1);
      puVar1 = (undefined4 *)0x0;
    }
  }
  return puVar1;
}



/* 10003d40 FUN_10003d40 */

/* Boundary evidence: original MIPS .pdata 10003d40..10003db3. Semantic name remains unreviewed. */

void FUN_10003d40(void)

{
  uint uVar1;
  
  if ((DAT_1000768c == 0) || (DAT_1000768c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_1000768c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_1000768c == 0) {
      DAT_1000768c = 0xb064;
    }
  }
  DAT_10007690 = ~DAT_1000768c;
  return;
}



/* 10003db4 FUN_10003db4 */

/* Boundary evidence: original MIPS .pdata 10003db4..10003e07. Semantic name remains unreviewed. */

void FUN_10003db4(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_10003e34(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 10003e08 FUN_10003e08 */

/* Boundary evidence: original MIPS .pdata 10003e08..10003e33. Semantic name remains unreviewed. */

undefined4 FUN_10003e08(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_10003db4(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 10003e34 FUN_10003e34 */

/* Boundary evidence: original MIPS .pdata 10003e34..10003e7b. Semantic name remains unreviewed. */

void FUN_10003e34(uint param_1)

{
  if ((param_1 == DAT_1000768c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 10003e9c FUN_10003e9c */

/* Boundary evidence: original MIPS .pdata 10003e9c..10003fa7. Semantic name remains unreviewed. */

undefined4 FUN_10003e9c(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_10007e50;
  puVar3 = DAT_10007e4c;
  iVar4 = (int)DAT_10007e4c - (int)DAT_10007e50;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_10003ee0:
    param_1 = 0;
  }
  else {
    if (DAT_10007e50 != (void *)0x0) {
      uVar1 = _msize(DAT_10007e50);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_10003f54:
        if (pvVar2 == (void *)0x0) goto LAB_10003ee0;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_10003f54;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_10007e4c = puVar3 + 1;
    *puVar3 = param_1;
    DAT_10007e50 = pvVar2;
  }
  return param_1;
}



/* 10003fa8 FUN_10003fa8 */

/* Boundary evidence: original MIPS .pdata 10003fa8..10003fd7. Semantic name remains unreviewed. */

undefined4 FUN_10003fa8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_10003e9c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 10004028 FUN_10004028 */

/* Boundary evidence: original MIPS .pdata 10004028..10004163. Semantic name remains unreviewed. */

int FUN_10004028(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_10007e48 != (code *)0x0) {
      iVar2 = (*DAT_10007e48)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_100040d8;
    FUN_100043ac();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_10001000(param_1,param_2);
  }
LAB_100040d8:
  if (((param_2 == 0) && (FUN_10004334(), iVar1 != 0)) && (DAT_10007e48 != (code *)0x0)) {
    iVar1 = (*DAT_10007e48)(param_1,0,param_3);
  }
  return iVar1;
}



/* 10004164 FUN_10004164 */

/* Boundary evidence: original MIPS .pdata 10004164..1000418f. Semantic name remains unreviewed. */

void FUN_10004164(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 10004190 entry */

/* Boundary evidence: original MIPS .pdata 10004190..100041e7. Semantic name remains unreviewed. */

void entry(int param_1,uint param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_10003d40();
  }
  FUN_10004028(param_1,param_2,param_3);
  return;
}



/* 10004248 FUN_10004248 */

/* Boundary evidence: original MIPS .pdata 10004248..10004333. Semantic name remains unreviewed. */

void FUN_10004248(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_10007e44 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_10007e50;
    if (DAT_10007e50 != (undefined4 *)0x0) {
      while (DAT_10007e4c = DAT_10007e4c + -1, _Memory <= DAT_10007e4c) {
        if ((code *)*DAT_10007e4c != (code *)0x0) {
          (*(code *)*DAT_10007e4c)();
          _Memory = DAT_10007e50;
        }
      }
      free(_Memory);
      DAT_10007e4c = (undefined4 *)0x0;
      DAT_10007e50 = (undefined4 *)0x0;
    }
    FUN_10004358((undefined4 *)&DAT_10005014,(undefined4 *)&DAT_10005018);
  }
  FUN_10004358((undefined4 *)&DAT_1000501c,(undefined4 *)&DAT_10005020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 10004334 FUN_10004334 */

/* Boundary evidence: original MIPS .pdata 10004334..10004357. Semantic name remains unreviewed. */

void FUN_10004334(void)

{
  FUN_10004248(0,0,1);
  return;
}



/* 10004358 FUN_10004358 */

/* Boundary evidence: original MIPS .pdata 10004358..100043ab. Semantic name remains unreviewed. */

void FUN_10004358(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 100043ac FUN_100043ac */

/* Boundary evidence: original MIPS .pdata 100043ac..100043e7. Semantic name remains unreviewed. */

void FUN_100043ac(void)

{
  FUN_10004358((undefined4 *)&DAT_1000500c,(undefined4 *)&DAT_10005010);
  FUN_10004358((undefined4 *)&DAT_10005000,(undefined4 *)&DAT_10005008);
  return;
}



/* 10004408 FUN_10004408 */

/* Boundary evidence: original MIPS .pdata 10004408..10004433. Semantic name remains unreviewed. */

void FUN_10004408(void)

{
  FUN_10003310((undefined4 *)&DAT_10007780);
  FUN_10003fa8(FUN_10004434);
  return;
}



/* 10004434 FUN_10004434 */

/* Boundary evidence: original MIPS .pdata 10004434..10004453. Semantic name remains unreviewed. */

void FUN_10004434(void)

{
  FUN_10003bb4((undefined4 *)&DAT_10007780);
  return;
}


