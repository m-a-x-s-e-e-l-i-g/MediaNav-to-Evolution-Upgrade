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
    FUN_10001898(0x26,1);
    FUN_10001898(0x28,1);
    FUN_10001898(0x27,1);
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
  WCHAR aWStack_1018 [1024];
  wchar_t awStack_818 [1026];
  uint local_14;
  
  local_14 = DAT_10007684;
  local_resc = param_4;
  if ((param_2 == 3) ||
     (((&DAT_1000768c)[param_1] != 0 && ((int)(&DAT_1000a000)[param_1] <= param_2)))) {
    vswprintf_s(awStack_818,0x400,param_3,(va_list)&local_resc);
    GetLocalTime(&_Stack_1028);
    puVar3 = PTR_u_MgrDbg_1000709c;
    if (param_1 < 0x2a) {
      puVar3 = (&PTR_u_MgrDbg_1000709c)[param_1];
    }
    DVar1 = GetTickCount();
    DVar2 = GetTickCount();
    wsprintfW(aWStack_1018,L"[%02d:%02d:%02d:%d,%05d][%s] %s\r\n",(uint)_Stack_1028.wHour,
              (uint)_Stack_1028.wMinute,(uint)_Stack_1028.wSecond,DVar2 % 1000,DVar1 / 10,puVar3,
              awStack_818);
    OutputDebugStringW(aWStack_1018);
  }
  FUN_10003bb4(local_14);
  return;
}



/* 100011d4 DbgPrintDLLVersion */

/* Boundary evidence: original MIPS .pdata 100011d4..1000120f. Semantic name remains unreviewed. */

void DbgPrintDLLVersion(void)

{
                    /* 0x11d4  7  DbgPrintDLLVersion */
  FUN_10001084(0x24,0,L"[CmnDll] Compiled Date=%S:%S\t\n","Dec 23 2014");
  return;
}



/* 10001210 DbgGetModuleName */

undefined * DbgGetModuleName(int param_1)

{
  undefined *puVar1;
  
                    /* 0x1210  6  DbgGetModuleName */
  puVar1 = PTR_u_MgrDbg_1000709c;
  if (param_1 < 0x2a) {
    puVar1 = (&PTR_u_MgrDbg_1000709c)[param_1];
  }
  return puVar1;
}



/* 10001244 DbgSetDebugOnOff */

void DbgSetDebugOnOff(int param_1,undefined4 param_2)

{
                    /* 0x1244  11  DbgSetDebugOnOff */
  if (param_1 < 0x2a) {
    (&DAT_1000768c)[param_1] = param_2;
  }
  return;
}



/* 1000126c DbgGetDebugOnOff */

undefined4 DbgGetDebugOnOff(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x126c  5  DbgGetDebugOnOff */
  uVar1 = DAT_1000768c;
  if (param_1 < 0x2a) {
    uVar1 = (&DAT_1000768c)[param_1];
  }
  return uVar1;
}



/* 100012a0 DbgSetDebugLevel */

/* Boundary evidence: original MIPS .pdata 100012a0..100012eb. Semantic name remains unreviewed. */

void DbgSetDebugLevel(int param_1,int param_2)

{
                    /* 0x12a0  10  DbgSetDebugLevel */
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
  
                    /* 0x12ec  4  DbgGetDebugLevel */
  uVar1 = DAT_1000a000;
  if (param_1 < 0x2a) {
    uVar1 = (&DAT_1000a000)[param_1];
  }
  return uVar1;
}



/* 10001320 SaveDabLogString */

/* Boundary evidence: original MIPS .pdata 10001320..100013e7. Semantic name remains unreviewed.
   void __cdecl SaveDabLogString(wchar_t *) */

void SaveDabLogString(wchar_t *param_1)

{
  HANDLE hFile;
  size_t sVar1;
  DWORD local_18 [2];
  
                    /* 0x1320  1  ?SaveDabLogString@@YAXPA_W@Z */
  hFile = CreateFileW(L"\\Storage Card3\\TestLog.log",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80
                      ,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    local_18[0] = 0;
    SetFilePointer(hFile,0,(PLONG)0x0,2);
    sVar1 = wcslen(param_1);
    WriteFile(hFile,param_1,sVar1 << 1,local_18,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
  }
  return;
}



/* 100013e8 DbgDebugPrint */

/* Boundary evidence: original MIPS .pdata 100013e8..100015bb. Semantic name remains unreviewed. */

void DbgDebugPrint(int param_1,int param_2,wchar_t *param_3,undefined4 param_4)

{
  wchar_t wVar1;
  size_t sVar2;
  DWORD DVar3;
  DWORD DVar4;
  wchar_t *pwVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  undefined4 local_resc;
  _SYSTEMTIME _Stack_1030;
  wchar_t local_1020 [1024];
  WCHAR aWStack_820 [1024];
  uint local_20;
  
                    /* 0x13e8  2  DbgDebugPrint */
  local_20 = DAT_10007684;
  local_resc = param_4;
  if ((int)(&DAT_1000a000)[param_1] <= param_2) {
    vswprintf_s(local_1020,0x400,param_3,(va_list)&local_resc);
    sVar2 = wcslen(local_1020);
    iVar6 = sVar2 * 2;
    if (iVar6 != 0) {
      pwVar5 = local_1020;
      iVar7 = iVar6;
      do {
        if (*pwVar5 == L'%') {
          *pwVar5 = L'*';
        }
        iVar7 = iVar7 + -1;
        pwVar5 = pwVar5 + 1;
      } while (iVar7 != 0);
    }
    if ((local_1020[sVar2 * 2 + -1] == L'\n') || (local_1020[sVar2 * 2 + -1] == L'\r')) {
      local_1020[sVar2 * 2 + -1] = L'\0';
    }
    wVar1 = local_1020[iVar6 + -2];
    if ((wVar1 == L'\r') || (wVar1 == L'\n')) {
      local_1020[iVar6 + -2] = L'\0';
    }
    GetLocalTime(&_Stack_1030);
    puVar8 = PTR_u_MgrDbg_1000709c;
    if (param_1 < 0x2a) {
      puVar8 = (&PTR_u_MgrDbg_1000709c)[param_1];
    }
    DVar3 = GetTickCount();
    DVar4 = GetTickCount();
    wsprintfW(aWStack_820,L"[%s][LV:%d][%02d:%02d:%02d:%d,%05d]%s\r\n",puVar8,param_2 + 1,
              (uint)_Stack_1030.wHour,(uint)_Stack_1030.wMinute,(uint)_Stack_1030.wSecond,
              DVar4 % 1000,DVar3 / 10,local_1020);
    OutputDebugStringW(aWStack_820);
  }
  FUN_10003bb4(local_20);
  return;
}



/* 100015bc DbgSetAllDebugOnOff */

void DbgSetAllDebugOnOff(undefined4 param_1)

{
  undefined4 *puVar1;
  
                    /* 0x15bc  9  DbgSetAllDebugOnOff */
  puVar1 = &DAT_1000768c;
  do {
    *puVar1 = param_1;
    puVar1 = puVar1 + 1;
  } while (puVar1 != &DAT_10007734);
  return;
}



/* 100015e0 DbgSetAllDebugLevel */

/* Boundary evidence: original MIPS .pdata 100015e0..10001627. Semantic name remains unreviewed. */

void DbgSetAllDebugLevel(int param_1)

{
  int *piVar1;
  
                    /* 0x15e0  8  DbgSetAllDebugLevel */
  piVar1 = &DAT_1000a000;
  do {
    *piVar1 = param_1;
    piVar1 = piVar1 + 1;
  } while (piVar1 != (int *)0x1000a0a8);
  FUN_10001084(0x14,1,L"DbgSetAllDebugLevel -> [%d]\r\n",param_1 + 1);
  return;
}



/* 10001628 DbgDebugPrint2File */

/* Boundary evidence: original MIPS .pdata 10001628..10001897. Semantic name remains unreviewed. */

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
  
                    /* 0x1628  3  DbgDebugPrint2File */
  local_20 = DAT_10007684;
  local_820 = L'\n';
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memset(auStack_81e,0,0x7fe);
  vswprintf_s(&local_820,0x400,param_1,(va_list)&local_res4);
  sVar1 = wcslen(&local_820);
  DAT_1000773c = sVar1 + DAT_1000773c;
  FUN_10001084(0x14,1,L"DbgDebugPrint2File Size = [%d]\r\n",DAT_1000773c);
  lpFileName = L"debugfile_2.log";
  if (0x14fff < DAT_1000773c) {
    if (DAT_10007098 == 0) {
      lpFileName = L"debugfile_1.log";
    }
    DeleteFileW(lpFileName);
    DAT_10007098 = (DAT_10007098 + 1) % 2;
    DAT_1000773c = 0;
  }
  if (DAT_10007098 == 0) {
    if (DAT_10007738 == 0) {
      hFile = CreateFileW(L"debugfile_2.log",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,
                          (HANDLE)0x0);
      DAT_10007738 = DAT_10007738 + 1;
    }
    else {
      hFile = CreateFileW(L"debugfile_2.log",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,
                          (HANDLE)0x0);
    }
  }
  else if (DAT_10007734 == 0) {
    hFile = CreateFileW(L"debugfile_1.log",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,
                        (HANDLE)0x0);
    DAT_10007734 = DAT_10007734 + 1;
  }
  else {
    hFile = CreateFileW(L"debugfile_1.log",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,
                        (HANDLE)0x0);
  }
  if (hFile != (HANDLE)0xffffffff) {
    SetFilePointer(hFile,0,(PLONG)0x0,2);
    sVar1 = wcslen(&local_820);
    WriteFile(hFile,&local_820,sVar1 << 1,aDStack_828,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
  }
  FUN_10003bb4(local_20);
  return;
}



/* 10001898 FUN_10001898 */

/* Boundary evidence: original MIPS .pdata 10001898..10001903. Semantic name remains unreviewed. */

void FUN_10001898(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_u_MgrDbg_1000709c;
  if (param_1 < 0x2a) {
    (&DAT_1000a000)[param_1] = param_2;
    puVar1 = (&PTR_u_MgrDbg_1000709c)[param_1];
  }
  FUN_10001084(0x14,1,L"IntDbgSetDebugLevel -> [%s][%d]\r\n",puVar1);
  return;
}



/* 10001904 MFA_Dll_Read */

/* Boundary evidence: original MIPS .pdata 10001904..10001b37. Semantic name remains unreviewed. */

undefined4 MFA_Dll_Read(int param_1,int param_2,LPVOID param_3,DWORD param_4,LPDWORD param_5)

{
  HANDLE hFile;
  BOOL BVar1;
  wchar_t *pwVar2;
  wchar_t awStack_228 [256];
  uint local_28;
  
                    /* 0x1904  20  MFA_Dll_Read */
  local_28 = DAT_10007684;
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
            FUN_10003bb4(local_28);
            return 1;
          }
          FUN_10001084(0x24,3,L"%S### Fail =>You are at the End Of File ###","MFA_Dll_Read");
        }
        CloseHandle(hFile);
      }
      goto LAB_10001b04;
    }
    pwVar2 = L"%S pdwByteRead or dat is NULL";
  }
  FUN_10001084(0x24,3,pwVar2,"MFA_Dll_Read");
LAB_10001b04:
  FUN_10003bb4(local_28);
  return 0;
}



/* 10001b38 MFA_Dll_Write */

/* Boundary evidence: original MIPS .pdata 10001b38..10001d83. Semantic name remains unreviewed. */

undefined4 MFA_Dll_Write(LPCWSTR param_1,int param_2,LPCVOID param_3,DWORD param_4,LPDWORD param_5)

{
  BOOL BVar1;
  HANDLE hFile;
  wchar_t *pwVar2;
  wchar_t awStack_228 [256];
  uint local_28;
  
                    /* 0x1b38  21  MFA_Dll_Write */
  local_28 = DAT_10007684;
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
          FUN_10003bb4(local_28);
          return 1;
        }
        GetLastError();
        FUN_10001084(0x24,3,L"%S WriteFile fail, error=%d","MFA_Dll_Write");
        CloseHandle(hFile);
      }
      goto LAB_10001d50;
    }
    pwVar2 = L"%S pdwByteRead or dat is NULL";
  }
  FUN_10001084(0x24,3,pwVar2,"MFA_Dll_Write");
LAB_10001d50:
  FUN_10003bb4(local_28);
  return 0;
}



/* 10001d84 FUN_10001d84 */

/* Boundary evidence: original MIPS .pdata 10001d84..10001e23. Semantic name remains unreviewed. */

bool FUN_10001d84(undefined4 *param_1,LPCWSTR param_2)

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



/* 10001e24 FUN_10001e24 */

/* Boundary evidence: original MIPS .pdata 10001e24..10001ff7. Semantic name remains unreviewed. */

BOOL FUN_10001e24(undefined4 *param_1,undefined1 param_2,undefined1 param_3,void *param_4,
                 uint param_5)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD aDStack_30 [2];
  
  BVar2 = 0;
  if (param_5 < 0x200) {
    DVar1 = WaitForSingleObject((HANDLE)param_1[1],0xffffffff);
    if (DVar1 == 0) {
      DAT_10007744 = param_5;
      DAT_10007740 = param_2;
      DAT_10007748 = param_3;
      BVar2 = DeviceIoControl((HANDLE)*param_1,0x80002002,&DAT_10007740,0x208,&DAT_10007749,param_5,
                              aDStack_30,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        GetLastError();
        FUN_10001084(0x27,3,L"%S DeviceIoControl fail, errCode=%d","CDriverI2C::readI2C");
      }
      else {
        memcpy(param_4,&DAT_10007749,DAT_10007744);
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



/* 10001ff8 FUN_10001ff8 */

/* Boundary evidence: original MIPS .pdata 10001ff8..100021e3. Semantic name remains unreviewed. */

BOOL FUN_10001ff8(undefined4 *param_1,undefined1 param_2,int param_3,void *param_4,uint param_5)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD aDStack_30 [2];
  
  BVar2 = 0;
  if (param_5 < 0x200) {
    DVar1 = WaitForSingleObject((HANDLE)param_1[1],0xffffffff);
    if (DVar1 == 0) {
      DAT_10007948 = param_2;
      if (param_3 == 0xff) {
        memcpy(&DAT_10007950,param_4,param_5);
      }
      else {
        DAT_10007950 = (undefined1)param_3;
        memcpy(&DAT_10007951,param_4,param_5);
        param_5 = param_5 + 1;
      }
      DAT_1000794c = param_5;
      BVar2 = DeviceIoControl((HANDLE)*param_1,0x80002001,&DAT_10007948,param_5 + 0x207,(LPVOID)0x0,
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



/* 100021e4 FUN_100021e4 */

/* Boundary evidence: original MIPS .pdata 100021e4..1000226b. Semantic name remains unreviewed. */

void FUN_100021e4(undefined4 *param_1)

{
  BOOL BVar1;
  
  if ((HANDLE)*param_1 != (HANDLE)0xffffffff) {
    BVar1 = CloseHandle((HANDLE)*param_1);
    if (BVar1 == 0) {
      GetLastError();
      FUN_10001084(0x27,3,L"%S CloseHandle fail, errCode=%d","CDriverI2C::closeI2C");
    }
    *param_1 = 0xffffffff;
  }
  return;
}



/* 1000226c FUN_1000226c */

/* Boundary evidence: original MIPS .pdata 1000226c..10002337. Semantic name remains unreviewed. */

undefined4 FUN_1000226c(int param_1,LPCWSTR param_2)

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



/* 10002338 FUN_10002338 */

/* Boundary evidence: original MIPS .pdata 10002338..100023af. Semantic name remains unreviewed. */

void FUN_10002338(int param_1)

{
  BOOL BVar1;
  
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0x0) {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 4));
    if (BVar1 == 0) {
      GetLastError();
      FUN_10001084(0x27,3,L"%S CloseHandle fail, errCode=%d","CDriverI2C::closeMutex");
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



/* 100023b0 MI2C_Dll_Read */

/* Boundary evidence: original MIPS .pdata 100023b0..100023cf. Semantic name remains unreviewed. */

void MI2C_Dll_Read(undefined4 *param_1,undefined1 param_2,undefined1 param_3,void *param_4,
                  uint param_5)

{
                    /* 0x23b0  24  MI2C_Dll_Read */
  FUN_10001e24(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 100023d0 MI2C_Dll_Write */

/* Boundary evidence: original MIPS .pdata 100023d0..100023ef. Semantic name remains unreviewed. */

void MI2C_Dll_Write(undefined4 *param_1,undefined1 param_2,int param_3,void *param_4,uint param_5)

{
                    /* 0x23d0  25  MI2C_Dll_Write */
  FUN_10001ff8(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 100023f0 MI2C_Dll_Close */

/* Boundary evidence: original MIPS .pdata 100023f0..1000242f. Semantic name remains unreviewed. */

void MI2C_Dll_Close(undefined4 *param_1)

{
                    /* 0x23f0  22  MI2C_Dll_Close */
  if (param_1 != (undefined4 *)0x0) {
    FUN_10002338((int)param_1);
    FUN_100021e4(param_1);
    __3_YAXPAX_Z(param_1);
  }
  return;
}



/* 10002430 MI2C_Dll_Init */

/* Boundary evidence: original MIPS .pdata 10002430..10002517. Semantic name remains unreviewed. */

undefined4 * MI2C_Dll_Init(void)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined3 extraout_var;
  int iVar3;
  wchar_t *pwVar4;
  
                    /* 0x2430  23  MI2C_Dll_Init */
  puVar2 = (undefined4 *)__2_YAPAXI_Z(8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0xffffffff;
    puVar2[1] = 0;
  }
  if (puVar2 == (undefined4 *)0x0) {
    FUN_10001084(0x27,3,L"%S not created","MI2C_Dll_Init");
  }
  else {
    bVar1 = FUN_10001d84(puVar2,L"SMB1:");
    if (CONCAT31(extraout_var,bVar1) == 0) {
      pwVar4 = L"%S openI2C fail";
    }
    else {
      iVar3 = FUN_1000226c((int)puVar2,L"MUTEXI2C");
      if (iVar3 != 0) {
        return puVar2;
      }
      pwVar4 = L"%S openMutex fail";
    }
    FUN_10001084(0x27,3,pwVar4,"MI2C_Dll_Init");
    FUN_10002338((int)puVar2);
    FUN_100021e4(puVar2);
    __3_YAXPAX_Z(puVar2);
  }
  return (undefined4 *)0x0;
}



/* 10002518 FUN_10002518 */

/* Boundary evidence: original MIPS .pdata 10002518..100025b7. Semantic name remains unreviewed. */

bool FUN_10002518(undefined4 *param_1,LPCWSTR param_2)

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



/* 100025b8 FUN_100025b8 */

/* Boundary evidence: original MIPS .pdata 100025b8..10002737. Semantic name remains unreviewed. */

BOOL FUN_100025b8(undefined4 *param_1,DWORD param_2,LPVOID param_3,DWORD param_4)

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



/* 10002738 FUN_10002738 */

/* Boundary evidence: original MIPS .pdata 10002738..100028b7. Semantic name remains unreviewed. */

BOOL FUN_10002738(undefined4 *param_1,DWORD param_2,LPVOID param_3,DWORD param_4)

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



/* 100028b8 FUN_100028b8 */

/* Boundary evidence: original MIPS .pdata 100028b8..10002927. Semantic name remains unreviewed. */

void FUN_100028b8(undefined4 *param_1)

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



/* 10002928 FUN_10002928 */

/* Boundary evidence: original MIPS .pdata 10002928..100029f3. Semantic name remains unreviewed. */

undefined4 FUN_10002928(int param_1,LPCWSTR param_2)

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



/* 100029f4 FUN_100029f4 */

/* Boundary evidence: original MIPS .pdata 100029f4..10002a6f. Semantic name remains unreviewed. */

void FUN_100029f4(int param_1)

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



/* 10002a70 MIOCTL_Dll_Read */

/* Boundary evidence: original MIPS .pdata 10002a70..10002a8b. Semantic name remains unreviewed. */

void MIOCTL_Dll_Read(undefined4 *param_1,DWORD param_2,LPVOID param_3,DWORD param_4)

{
                    /* 0x2a70  28  MIOCTL_Dll_Read */
  FUN_100025b8(param_1,param_2,param_3,param_4);
  return;
}



/* 10002a8c MIOCTL_Dll_Write */

/* Boundary evidence: original MIPS .pdata 10002a8c..10002aa7. Semantic name remains unreviewed. */

void MIOCTL_Dll_Write(undefined4 *param_1,DWORD param_2,LPVOID param_3,DWORD param_4)

{
                    /* 0x2a8c  29  MIOCTL_Dll_Write */
  FUN_10002738(param_1,param_2,param_3,param_4);
  return;
}



/* 10002aa8 MIOCTL_Dll_Close */

/* Boundary evidence: original MIPS .pdata 10002aa8..10002ae7. Semantic name remains unreviewed. */

void MIOCTL_Dll_Close(undefined4 *param_1)

{
                    /* 0x2aa8  26  MIOCTL_Dll_Close */
  if (param_1 != (undefined4 *)0x0) {
    FUN_100029f4((int)param_1);
    FUN_100028b8(param_1);
    __3_YAXPAX_Z(param_1);
  }
  return;
}



/* 10002ae8 MIOCTL_Dll_Init */

/* Boundary evidence: original MIPS .pdata 10002ae8..10002bcf. Semantic name remains unreviewed. */

undefined4 * MIOCTL_Dll_Init(void)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined3 extraout_var;
  int iVar3;
  wchar_t *pwVar4;
  
                    /* 0x2ae8  27  MIOCTL_Dll_Init */
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
    bVar1 = FUN_10002518(puVar2,L"MGR1:");
    if (CONCAT31(extraout_var,bVar1) == 0) {
      pwVar4 = L"%S openIoCtl fail";
    }
    else {
      iVar3 = FUN_10002928((int)puVar2,L"MUTEXIOCTL");
      if (iVar3 != 0) {
        return puVar2;
      }
      pwVar4 = L"%S openMutex fail";
    }
    FUN_10001084(0x28,3,pwVar4,"MIOCTL_Dll_Init");
    FUN_100029f4((int)puVar2);
    FUN_100028b8(puVar2);
    __3_YAXPAX_Z(puVar2);
  }
  return (undefined4 *)0x0;
}



/* 10002bd0 IpcTest */

/* Boundary evidence: original MIPS .pdata 10002bd0..10002bff. Semantic name remains unreviewed. */

void IpcTest(void)

{
                    /* 0x2bd0  19  IpcTest */
  FUN_10001084(0x25,0,L"%S","IpcTest");
  return;
}



/* 10002c00 IpcGetProcessHandle */

/* Boundary evidence: original MIPS .pdata 10002c00..10002c4b. Semantic name remains unreviewed. */

void IpcGetProcessHandle(int param_1)

{
                    /* 0x2c00  14  IpcGetProcessHandle */
  if (0x29 < param_1) {
    FUN_10001084(0x25,3,L"%S overflow, pid=%d","IpcGetProcessHandle");
    param_1 = 0;
  }
  FUN_100033a4(param_1);
  return;
}



/* 10002c4c IpcSetProcessHandle */

/* Boundary evidence: original MIPS .pdata 10002c4c..10002c9b. Semantic name remains unreviewed. */

void IpcSetProcessHandle(int param_1,undefined4 param_2)

{
                    /* 0x2c4c  18  IpcSetProcessHandle */
  if (param_1 < 0x2a) {
    FUN_1000338c(param_1,param_2);
  }
  else {
    FUN_10001084(0x25,3,L"%S overflow, pid=%d","IpcSetProcessHandle");
  }
  return;
}



/* 10002c9c IpcGetProcessName */

/* Boundary evidence: original MIPS .pdata 10002c9c..10002ce7. Semantic name remains unreviewed. */

void IpcGetProcessName(int param_1)

{
                    /* 0x2c9c  15  IpcGetProcessName */
  if (0x29 < param_1) {
    FUN_10001084(0x25,3,L"%S overflow, pid=%d","IpcGetProcessName");
    param_1 = 0;
  }
  FUN_10003330(param_1);
  return;
}



/* 10002ce8 IpcGetProcessFullName */

/* Boundary evidence: original MIPS .pdata 10002ce8..10002d5f. Semantic name remains unreviewed. */

undefined * IpcGetProcessFullName(int param_1)

{
  wchar_t *pwVar1;
  
                    /* 0x2ce8  13  IpcGetProcessFullName */
  if (0x29 < param_1) {
    FUN_10001084(0x25,3,L"%S overflow, pid=%d","IpcGetProcessFullName");
    param_1 = 0;
  }
  pwVar1 = FUN_10003330(param_1);
  swprintf_s((wchar_t *)&DAT_10007b50,0x100,L"%s.exe",pwVar1);
  return &DAT_10007b50;
}



/* 10002d60 IpcPostMsg */

/* Boundary evidence: original MIPS .pdata 10002d60..10002feb. Semantic name remains unreviewed. */

undefined4 IpcPostMsg(uint param_1,uint param_2,int param_3,uint param_4,LPARAM *param_5)

{
  int *piVar1;
  BOOL BVar2;
  DWORD DVar3;
  LPARAM lParam;
  HWND hWnd;
  LPARAM local_28 [2];
  
                    /* 0x2d60  16  IpcPostMsg */
  local_28[0] = 0;
  if (param_2 < 0x2a) {
    piVar1 = FUN_100033a4(param_2);
    hWnd = (HWND)*piVar1;
    if (hWnd == (HWND)0x0) {
      FUN_10003330(param_2);
      FUN_10001084(0x25,3,L"%S IntGetProcessHandle fail, proc=%s, src=%d, dst=%d, cmd=%d",
                   "IpcPostMsg");
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
        FUN_10003330(param_2);
        FUN_10003330(param_1);
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
        FUN_10001084(0x25,3,L"%S PostMessage fail, src=%d, dst=%d, cmd=%d, errCode=%d","IpcPostMsg")
        ;
      }
    }
  }
  else {
    FUN_10001084(0x25,3,L"%S IpcPostMsg fail, overflow, src=%d, dst=%d, cmd=%d","IpcPostMsg");
  }
  return 0;
}



/* 10002fec IpcSendMsg */

/* Boundary evidence: original MIPS .pdata 10002fec..100032b7. Semantic name remains unreviewed. */

undefined4 IpcSendMsg(uint param_1,uint param_2,int param_3,uint param_4,void *param_5)

{
  int *piVar1;
  int iVar2;
  DWORD local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  void *local_28;
  
                    /* 0x2fec  17  IpcSendMsg */
  local_38 = 0;
  local_34 = 0;
  if (param_2 < 0x2a) {
    piVar1 = FUN_100033a4(param_2);
    iVar2 = *piVar1;
    if (iVar2 == 0) {
      FUN_10003330(param_2);
      FUN_10001084(0x25,3,L"%S IntGetProcessHandle fail, proc=%s, src=%d, dst=%d, cmd=%d",
                   "IpcSendMsg");
    }
    else {
      if (param_4 < 5) {
        memcpy(&local_34,param_5,param_4);
        iVar2 = SendMessageTimeout(iVar2,0x8064,(param_3 << 8 | param_1) << 8 | param_4 & 0xff,
                                   local_34,0,0x9c4,&local_38);
      }
      else {
        FUN_10001084(0x25,3,L"%S extra data send using wm_copydata, size=%d","IpcSendMsg");
        local_28 = param_5;
        local_30 = param_1 * 100 + param_2 + 0x8000 | param_3 << 0x10;
        local_2c = param_4;
        iVar2 = SendMessageTimeout(iVar2,0x4a,0,&local_30,0,0x9c4,&local_38);
      }
      if (iVar2 != 0) {
        FUN_10003330(param_2);
        FUN_10003330(param_1);
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
  }
  else {
    FUN_10001084(0x25,3,L"%S IpcSendMsg fail, overflow, src=%d, dst=%d, cmd=%d","IpcSendMsg");
  }
  return 0;
}



/* 100032b8 IpcGetMsg */

ushort * IpcGetMsg(ushort *param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
                    /* 0x32b8  12  IpcGetMsg */
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



/* 10003330 FUN_10003330 */

/* Boundary evidence: original MIPS .pdata 10003330..1000338b. Semantic name remains unreviewed. */

wchar_t * FUN_10003330(int param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 < 0x2a) {
    pwVar1 = u_MgrDbg_10007144 + param_1 * 0x10;
  }
  else {
    FUN_10001084(0x25,3,L"%S fail iPid=%d","IntGetProcessName");
    pwVar1 = u_MgrDbg_10007144;
  }
  return pwVar1;
}



/* 1000338c FUN_1000338c */

void FUN_1000338c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(&DAT_10007d50 + param_1 * 4) = param_2;
  return;
}



/* 100033a4 FUN_100033a4 */

/* Boundary evidence: original MIPS .pdata 100033a4..10003453. Semantic name remains unreviewed. */

int * FUN_100033a4(int param_1)

{
  wchar_t *lpClassName;
  HWND pHVar1;
  int *piVar2;
  
  piVar2 = (int *)(&DAT_10007d50 + param_1 * 4);
  if (*piVar2 == 0) {
    lpClassName = FUN_10003330(param_1);
    pHVar1 = FindWindowW(lpClassName,(LPCWSTR)0x0);
    *piVar2 = (int)pHVar1;
    if (pHVar1 == (HWND)0x0) {
      GetLastError();
      FUN_10003330(param_1);
      FUN_10001084(0x25,3,L"%S FindWindow fail, %s(%d), errCode=%d","IntGetProcessHandle");
    }
  }
  return piVar2;
}



/* 10003454 FUN_10003454 */

/* Boundary evidence: original MIPS .pdata 10003454..100034e3. Semantic name remains unreviewed. */

void FUN_10003454(undefined4 *param_1)

{
  BOOL BVar1;
  
  if ((LPCVOID)param_1[1] != (LPCVOID)0x0) {
    BVar1 = UnmapViewOfFile((LPCVOID)param_1[1]);
    if (BVar1 == 0) {
      GetLastError();
      FUN_10001084(0x26,3,L"%S UnmapViewOfFile fail, error=%d","CSharedMem::closeShmMapping");
    }
    param_1[1] = 0;
  }
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
    *param_1 = 0;
  }
  return;
}



/* 100034e4 FUN_100034e4 */

/* Boundary evidence: original MIPS .pdata 100034e4..1000357f. Semantic name remains unreviewed. */

void FUN_100034e4(int param_1,void *param_2,int param_3,size_t param_4)

{
  if (*(int *)(param_1 + 4) == 0) {
    FUN_10001084(0x26,3,L"%S m_lpvMapView=NULL","CSharedMem::read");
  }
  else {
    memcpy(param_2,(void *)(*(int *)(param_1 + 4) + param_3),param_4);
  }
  return;
}



/* 10003580 FUN_10003580 */

/* Boundary evidence: original MIPS .pdata 10003580..1000358b. Semantic name remains unreviewed. */

undefined4 FUN_10003580(void)

{
  return 1;
}



/* 1000358c FUN_1000358c */

/* Boundary evidence: original MIPS .pdata 1000358c..1000361f. Semantic name remains unreviewed. */

void FUN_1000358c(int param_1,void *param_2,int param_3,size_t param_4)

{
  if (*(int *)(param_1 + 4) == 0) {
    FUN_10001084(0x26,3,L"%S m_lpvMapView=NULL","CSharedMem::write");
  }
  else {
    memcpy((void *)(*(int *)(param_1 + 4) + param_3),param_2,param_4);
  }
  return;
}



/* 10003620 FUN_10003620 */

/* Boundary evidence: original MIPS .pdata 10003620..1000362b. Semantic name remains unreviewed. */

undefined4 FUN_10003620(void)

{
  return 1;
}



/* 1000362c FUN_1000362c */

/* Boundary evidence: original MIPS .pdata 1000362c..10003783. Semantic name remains unreviewed. */

undefined4 FUN_1000362c(undefined4 *param_1,LPCWSTR param_2,DWORD param_3,HANDLE param_4)

{
  HANDLE hFileMappingObject;
  DWORD DVar1;
  LPVOID pvVar2;
  
  hFileMappingObject = CreateFileMappingW(param_4,(LPSECURITY_ATTRIBUTES)0x0,4,0,param_3,param_2);
  *param_1 = hFileMappingObject;
  if (hFileMappingObject == (HANDLE)0x0) {
    DVar1 = GetLastError();
    FUN_10001084(0x26,3,L"%S lpName=%s, CreateFileMapping fail, error=%d",
                 "CSharedMem::createShmMappingReadWrite");
    if (DVar1 == 0xb7) {
      FUN_10001084(0x26,3,L"%S has already been made","CSharedMem::createShmMappingReadWrite");
    }
  }
  else {
    pvVar2 = MapViewOfFile(hFileMappingObject,0xf001f,0,0,0);
    param_1[1] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      FUN_10001084(0x26,0,L"%S lpName=%s success","CSharedMem::createShmMappingReadWrite");
      return 1;
    }
    GetLastError();
    FUN_10001084(0x26,3,L"%S lpName=%s, MapViewOfFile fail, error=%d",
                 "CSharedMem::createShmMappingReadWrite");
    CloseHandle((HANDLE)*param_1);
    *param_1 = 0;
  }
  return 0;
}



/* 10003784 FUN_10003784 */

/* Boundary evidence: original MIPS .pdata 10003784..100038d7. Semantic name remains unreviewed. */

undefined4 FUN_10003784(undefined4 *param_1,LPCWSTR param_2,HANDLE param_3)

{
  HANDLE hFileMappingObject;
  DWORD DVar1;
  LPVOID pvVar2;
  
  hFileMappingObject = CreateFileMappingW(param_3,(LPSECURITY_ATTRIBUTES)0x0,2,0,0,param_2);
  *param_1 = hFileMappingObject;
  if (hFileMappingObject == (HANDLE)0x0) {
    DVar1 = GetLastError();
    FUN_10001084(0x26,3,L"%S lpName=%s, CreateFileMapping fail, error=%d",
                 "CSharedMem::createShmMappingReadOnly");
    if (DVar1 == 0xb7) {
      FUN_10001084(0x26,3,L"%S has already been made","CSharedMem::createShmMappingReadOnly");
    }
  }
  else {
    pvVar2 = MapViewOfFile(hFileMappingObject,4,0,0,0);
    param_1[1] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      FUN_10001084(0x26,0,L"%S lpName=%s success","CSharedMem::createShmMappingReadOnly");
      return 1;
    }
    GetLastError();
    FUN_10001084(0x26,3,L"%S lpName=%s, MapViewOfFile fail, error=%d",
                 "CSharedMem::createShmMappingReadOnly");
    CloseHandle((HANDLE)*param_1);
    *param_1 = 0;
  }
  return 0;
}



/* 100038d8 MSHM_Dll_MakeMappingReadWrite */

/* Boundary evidence: original MIPS .pdata 100038d8..1000390f. Semantic name remains unreviewed. */

undefined4 MSHM_Dll_MakeMappingReadWrite(undefined4 *param_1,LPCWSTR param_2,DWORD param_3)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x38d8  33  MSHM_Dll_MakeMappingReadWrite */
  if ((param_1 == (undefined4 *)0x0) ||
     (iVar1 = FUN_1000362c(param_1,param_2,param_3,(HANDLE)0xffffffff), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 10003910 MSHM_Dll_MakeMappingReadOnly */

/* Boundary evidence: original MIPS .pdata 10003910..10003947. Semantic name remains unreviewed. */

undefined4 MSHM_Dll_MakeMappingReadOnly(undefined4 *param_1,LPCWSTR param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x3910  32  MSHM_Dll_MakeMappingReadOnly */
  if ((param_1 == (undefined4 *)0x0) ||
     (iVar1 = FUN_10003784(param_1,param_2,(HANDLE)0xffffffff), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 10003948 MSHM_Dll_Read */

/* Boundary evidence: original MIPS .pdata 10003948..1000396b. Semantic name remains unreviewed. */

void MSHM_Dll_Read(int param_1,void *param_2,int param_3,size_t param_4)

{
                    /* 0x3948  34  MSHM_Dll_Read */
  if (param_1 != 0) {
    FUN_100034e4(param_1,param_2,param_3,param_4);
  }
  return;
}



/* 1000396c MSHM_Dll_Write */

/* Boundary evidence: original MIPS .pdata 1000396c..1000398f. Semantic name remains unreviewed. */

void MSHM_Dll_Write(int param_1,void *param_2,int param_3,size_t param_4)

{
                    /* 0x396c  35  MSHM_Dll_Write */
  if (param_1 != 0) {
    FUN_1000358c(param_1,param_2,param_3,param_4);
  }
  return;
}



/* 10003990 MSHM_Dll_DestoryShmClassObj */

/* Boundary evidence: original MIPS .pdata 10003990..100039c7. Semantic name remains unreviewed. */

void MSHM_Dll_DestoryShmClassObj(undefined4 *param_1)

{
                    /* 0x3990  31  MSHM_Dll_DestoryShmClassObj */
  if (param_1 != (undefined4 *)0x0) {
    FUN_10003454(param_1);
    __3_YAXPAX_Z(param_1);
  }
  return;
}



/* 100039c8 MSHM_Dll_CreateShmClassObj */

/* Boundary evidence: original MIPS .pdata 100039c8..10003a2f. Semantic name remains unreviewed. */

undefined4 * MSHM_Dll_CreateShmClassObj(void)

{
  undefined4 *puVar1;
  
                    /* 0x39c8  30  MSHM_Dll_CreateShmClassObj */
  puVar1 = (undefined4 *)__2_YAPAXI_Z(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_10001084(0x26,3,L"%S not created","MSHM_Dll_CreateShmClassObj");
  }
  return puVar1;
}



/* 10003ac0 FUN_10003ac0 */

/* Boundary evidence: original MIPS .pdata 10003ac0..10003b33. Semantic name remains unreviewed. */

void FUN_10003ac0(void)

{
  uint uVar1;
  
  if ((DAT_10007684 == 0) || (DAT_10007684 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_10007684 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_10007684 == 0) {
      DAT_10007684 = 0xb064;
    }
  }
  DAT_10007688 = ~DAT_10007684;
  return;
}



/* 10003b34 FUN_10003b34 */

/* Boundary evidence: original MIPS .pdata 10003b34..10003b87. Semantic name remains unreviewed. */

void FUN_10003b34(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_10003bb4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 10003b88 FUN_10003b88 */

/* Boundary evidence: original MIPS .pdata 10003b88..10003bb3. Semantic name remains unreviewed. */

undefined4 FUN_10003b88(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_10003b34(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 10003bb4 FUN_10003bb4 */

/* Boundary evidence: original MIPS .pdata 10003bb4..10003bfb. Semantic name remains unreviewed. */

void FUN_10003bb4(uint param_1)

{
  if ((param_1 == DAT_10007684) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 10003c6c FUN_10003c6c */

/* Boundary evidence: original MIPS .pdata 10003c6c..10003da7. Semantic name remains unreviewed. */

int FUN_10003c6c(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_10007e08 != (code *)0x0) {
      iVar2 = (*DAT_10007e08)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_10003d1c;
    FUN_10003ff4();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_10001000(param_1,param_2);
  }
LAB_10003d1c:
  if (((param_2 == 0) && (FUN_10003f7c(), iVar1 != 0)) && (DAT_10007e08 != (code *)0x0)) {
    iVar1 = (*DAT_10007e08)(param_1,0,param_3);
  }
  return iVar1;
}



/* 10003da8 FUN_10003da8 */

/* Boundary evidence: original MIPS .pdata 10003da8..10003dd3. Semantic name remains unreviewed. */

void FUN_10003da8(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 10003dd4 entry */

/* Boundary evidence: original MIPS .pdata 10003dd4..10003e2b. Semantic name remains unreviewed. */

void entry(int param_1,uint param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_10003ac0();
  }
  FUN_10003c6c(param_1,param_2,param_3);
  return;
}



/* 10003e5c FUN_10003e5c */

/* Boundary evidence: original MIPS .pdata 10003e5c..10003f7b. Semantic name remains unreviewed. */

void FUN_10003e5c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_10007df8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_10007e00;
    if (DAT_10007e00 != (undefined4 *)0x0) {
      while (DAT_10007dfc = DAT_10007dfc + -1, _Memory <= DAT_10007dfc) {
        if ((code *)*DAT_10007dfc != (code *)0x0) {
          (*(code *)*DAT_10007dfc)();
          _Memory = DAT_10007e00;
        }
      }
      free(_Memory);
      DAT_10007dfc = (undefined4 *)0x0;
      DAT_10007e00 = (undefined4 *)0x0;
    }
    FUN_10003fa0((undefined4 *)&DAT_10005010,(undefined4 *)&DAT_10005014);
  }
  FUN_10003fa0((undefined4 *)&DAT_10005018,(undefined4 *)&DAT_1000501c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_10007e04,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 10003f7c FUN_10003f7c */

/* Boundary evidence: original MIPS .pdata 10003f7c..10003f9f. Semantic name remains unreviewed. */

void FUN_10003f7c(void)

{
  FUN_10003e5c(0,0,1);
  return;
}



/* 10003fa0 FUN_10003fa0 */

/* Boundary evidence: original MIPS .pdata 10003fa0..10003ff3. Semantic name remains unreviewed. */

void FUN_10003fa0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 10003ff4 FUN_10003ff4 */

/* Boundary evidence: original MIPS .pdata 10003ff4..1000402f. Semantic name remains unreviewed. */

void FUN_10003ff4(void)

{
  FUN_10003fa0((undefined4 *)&DAT_10005008,(undefined4 *)&DAT_1000500c);
  FUN_10003fa0((undefined4 *)&DAT_10005000,(undefined4 *)&DAT_10005004);
  return;
}


