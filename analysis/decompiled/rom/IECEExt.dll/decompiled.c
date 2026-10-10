/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 405010cc FUN_405010cc */

/* Boundary evidence: original MIPS .pdata 405010cc..4050114f. Semantic name remains unreviewed. */

undefined4 FUN_405010cc(undefined4 param_1,int param_2)

{
  DAT_40504104 = param_1;
  if (param_2 == 0) {
    if (DAT_40504108 != (HMODULE)0x0) {
      FreeLibrary(DAT_40504108);
      DAT_40504108 = (HMODULE)0x0;
    }
  }
  else if ((param_2 == 1) && (DAT_40504108 == (HMODULE)0x0)) {
    DAT_40504108 = LoadLibraryW(L"coredll.dll");
  }
  return 1;
}



/* 40501150 FUN_40501150 */

/* Boundary evidence: original MIPS .pdata 40501150..405011b7. Semantic name remains unreviewed. */

LPSTR FUN_40501150(LPSTR param_1,LPCWSTR param_2,int param_3)

{
  if ((param_1 == (LPSTR)0x0) || (param_2 == (LPCWSTR)0x0)) {
    param_1 = (LPSTR)0x0;
  }
  else {
    *param_1 = '\0';
    WideCharToMultiByte(0,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
  }
  return param_1;
}



/* 405011b8 FUN_405011b8 */

/* Boundary evidence: original MIPS .pdata 405011b8..4050124f. Semantic name remains unreviewed. */

LPWSTR FUN_405011b8(LPCSTR param_1)

{
  int iVar1;
  LPWSTR lpWideCharStr;
  
  lpWideCharStr = (LPWSTR)0x0;
  if (param_1 != (LPCSTR)0x0) {
    iVar1 = MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)0x0,0);
    if (iVar1 != 0) {
      lpWideCharStr = LocalAlloc(0,(iVar1 + 1) * 2);
      if (lpWideCharStr != (LPWSTR)0x0) {
        MultiByteToWideChar(0,0,param_1,-1,lpWideCharStr,iVar1 + 1);
      }
    }
  }
  return lpWideCharStr;
}



/* 40501250 FUN_40501250 */

/* Boundary evidence: original MIPS .pdata 40501250..405012f7. Semantic name remains unreviewed. */

LPSTR FUN_40501250(LPCWSTR param_1)

{
  int iVar1;
  LPSTR lpMultiByteStr;
  
  lpMultiByteStr = (LPSTR)0x0;
  if (param_1 != (LPCWSTR)0x0) {
    iVar1 = WideCharToMultiByte(0,0,param_1,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 != 0) {
      lpMultiByteStr = LocalAlloc(0,iVar1 + 1U);
      if (lpMultiByteStr != (LPSTR)0x0) {
        WideCharToMultiByte(0,0,param_1,-1,lpMultiByteStr,iVar1 + 1U,(LPCSTR)0x0,(LPBOOL)0x0);
      }
    }
  }
  return lpMultiByteStr;
}



/* 405012f8 OutputDebugStringA */

/* Boundary evidence: original MIPS .pdata 405012f8..40501337. Semantic name remains unreviewed. */

void OutputDebugStringA(LPCSTR lpOutputString)

{
  LPWSTR lpOutputString_00;
  
                    /* 0x12f8  38  OutputDebugStringA */
  lpOutputString_00 = FUN_405011b8(lpOutputString);
  if (lpOutputString_00 != (LPWSTR)0x0) {
    OutputDebugStringW(lpOutputString_00);
    LocalFree(lpOutputString_00);
  }
  return;
}



/* 40501338 CharUpperA */

/* Boundary evidence: original MIPS .pdata 40501338..40501407. Semantic name remains unreviewed. */

LPSTR CharUpperA(LPSTR lpsz)

{
  bool bVar1;
  LPWSTR pWVar2;
  LPSTR _Source;
  LPSTR local_20 [2];
  
                    /* 0x1338  1  CharUpperA */
  bVar1 = (uint)lpsz >> 0x10 == 0;
  if (bVar1) {
    local_20[0]._0_2_ = (ushort)(byte)lpsz;
    lpsz = (LPSTR)local_20;
  }
  pWVar2 = FUN_405011b8(lpsz);
  _Source = local_20[0];
  if (pWVar2 != (LPWSTR)0x0) {
    pWVar2 = CharUpperW(pWVar2);
    _Source = FUN_40501250(pWVar2);
    strcpy(lpsz,_Source);
    if (pWVar2 != (LPWSTR)0x0) {
      LocalFree(pWVar2);
    }
  }
  if (_Source != (LPSTR)0x0) {
    LocalFree(_Source);
  }
  if (bVar1) {
    lpsz = (LPSTR)(int)*lpsz;
  }
  return (LPSTR)(LPSTR *)lpsz;
}



/* 40501408 LoadCursorA */

/* Boundary evidence: original MIPS .pdata 40501408..40501423. Semantic name remains unreviewed. */

HCURSOR LoadCursorA(HINSTANCE hInstance,LPCSTR lpCursorName)

{
  HCURSOR pHVar1;
  
                    /* 0x1408  29  LoadCursorA */
  pHVar1 = LoadCursorW(hInstance,(LPCWSTR)lpCursorName);
  return pHVar1;
}



/* 40501424 GetWindowLongA */

/* Boundary evidence: original MIPS .pdata 40501424..4050143f. Semantic name remains unreviewed. */

LONG GetWindowLongA(HWND hWnd,int nIndex)

{
  LONG LVar1;
  
                    /* 0x1424  26  GetWindowLongA */
  LVar1 = GetWindowLongW(hWnd,nIndex);
  return LVar1;
}



/* 40501440 SetWindowLongA */

/* Boundary evidence: original MIPS .pdata 40501440..4050145b. Semantic name remains unreviewed. */

LONG SetWindowLongA(HWND hWnd,int nIndex,LONG dwNewLong)

{
  LONG LVar1;
  
                    /* 0x1440  40  SetWindowLongA */
  LVar1 = SetWindowLongW(hWnd,nIndex,dwNewLong);
  return LVar1;
}



/* 4050145c LoadStringA */

/* Boundary evidence: original MIPS .pdata 4050145c..40501513. Semantic name remains unreviewed. */

int LoadStringA(HINSTANCE hInstance,UINT uID,LPSTR lpBuffer,int cchBufferMax)

{
  int iVar1;
  int iVar2;
  int aiStack_30 [4];
  uint local_20 [2];
  
                    /* 0x145c  31  LoadStringA */
  local_20[0] = DAT_405040fc;
  iVar2 = cchBufferMax * 2 + 7 >> 3;
  iVar1 = LoadStringW(hInstance,uID,(LPWSTR)(local_20 + iVar2 * -2),cchBufferMax);
  if (0 < iVar1) {
    aiStack_30[iVar2 * -2 + 3] = 0;
    aiStack_30[iVar2 * -2 + 2] = 0;
    aiStack_30[iVar2 * -2 + 1] = cchBufferMax;
    aiStack_30[iVar2 * -2] = (int)lpBuffer;
    WideCharToMultiByte(0,0,(LPCWSTR)(local_20 + iVar2 * -2),iVar1 + 1,(LPSTR)aiStack_30[iVar2 * -2]
                        ,aiStack_30[iVar2 * -2 + 1],(LPCSTR)aiStack_30[iVar2 * -2 + 2],
                        (LPBOOL)aiStack_30[iVar2 * -2 + 3]);
  }
  FUN_40502aac(local_20[0]);
  return iVar1;
}



/* 40501514 GetVersionExA */

/* Boundary evidence: original MIPS .pdata 40501514..405015f7. Semantic name remains unreviewed. */

BOOL GetVersionExA(LPOSVERSIONINFOA lpVersionInformation)

{
  BOOL BVar1;
  _OSVERSIONINFOW local_128;
  uint local_14;
  
                    /* 0x1514  25  GetVersionExA */
  local_14 = DAT_405040fc;
  if (lpVersionInformation->dwOSVersionInfoSize < 0x94) {
    BVar1 = 0;
    SetLastError(0x57);
  }
  else {
    local_128.dwOSVersionInfoSize = 0x114;
    BVar1 = GetVersionExW(&local_128);
    if (BVar1 != 0) {
      lpVersionInformation->dwOSVersionInfoSize = local_128.dwOSVersionInfoSize;
      lpVersionInformation->dwMajorVersion = local_128.dwMajorVersion;
      lpVersionInformation->dwMinorVersion = local_128.dwMinorVersion;
      lpVersionInformation->dwBuildNumber = local_128.dwBuildNumber;
      lpVersionInformation->dwPlatformId = local_128.dwPlatformId;
      if (local_128.szCSDVersion[0] == L'\0') {
        lpVersionInformation->szCSDVersion[0] = '\0';
      }
      else {
        WideCharToMultiByte(0,0,local_128.szCSDVersion,-1,lpVersionInformation->szCSDVersion,0x80,
                            (LPCSTR)0x0,(LPBOOL)0x0);
      }
    }
  }
  FUN_40502aac(local_14);
  return BVar1;
}



/* 405015f8 GetWindowsDirectoryA */

/* Boundary evidence: original MIPS .pdata 405015f8..40501637. Semantic name remains unreviewed. */

UINT GetWindowsDirectoryA(LPSTR lpBuffer,UINT uSize)

{
  size_t sVar1;
  
                    /* 0x15f8  27  GetWindowsDirectoryA */
  builtin_memcpy(lpBuffer,"\\Windows",9);
  sVar1 = strlen(lpBuffer);
  return sVar1;
}



/* 40501638 GetTempPathA */

/* Boundary evidence: original MIPS .pdata 40501638..405016df. Semantic name remains unreviewed. */

DWORD GetTempPathA(DWORD nBufferLength,LPSTR lpBuffer)

{
  size_t sVar1;
  DWORD DVar2;
  LPWSTR lpBuffer_00;
  uint local_20 [2];
  
                    /* 0x1638  24  GetTempPathA */
  local_20[0] = DAT_405040fc;
  DVar2 = 0;
  if (nBufferLength != 0) {
    lpBuffer_00 = (LPWSTR)(local_20 + ((int)(nBufferLength * 2 + 7) >> 3) * -2);
    DVar2 = GetTempPathW(nBufferLength,lpBuffer_00);
    if (DVar2 != 0) {
      sVar1 = wcslen(lpBuffer_00);
      FUN_40501150(lpBuffer,lpBuffer_00,sVar1 * 2 + 1);
    }
  }
  FUN_40502aac(local_20[0]);
  return DVar2;
}



/* 405016e0 DeleteFileA */

/* Boundary evidence: original MIPS .pdata 405016e0..4050178f. Semantic name remains unreviewed. */

BOOL DeleteFileA(LPCSTR lpFileName)

{
  size_t sVar1;
  BOOL BVar2;
  int iVar3;
  LPCWSTR lpFileName_00;
  int aiStack_20 [2];
  uint local_18 [2];
  
                    /* 0x16e0  14  DeleteFileA */
  local_18[0] = DAT_405040fc;
  if (lpFileName == (LPCSTR)0x0) {
    lpFileName_00 = (LPCWSTR)0x0;
  }
  else {
    sVar1 = strlen(lpFileName);
    iVar3 = (int)((sVar1 + 1) * 2 + 7) >> 3;
    lpFileName_00 = (LPCWSTR)(local_18 + iVar3 * -2);
    *lpFileName_00 = L'\0';
    aiStack_20[iVar3 * -2 + 1] = sVar1 + 1;
    aiStack_20[iVar3 * -2] = (int)lpFileName_00;
    MultiByteToWideChar(0,0,lpFileName,-1,(LPWSTR)aiStack_20[iVar3 * -2],aiStack_20[iVar3 * -2 + 1])
    ;
  }
  BVar2 = DeleteFileW(lpFileName_00);
  FUN_40502aac(local_18[0]);
  return BVar2;
}



/* 40501790 FindResourceA */

/* Boundary evidence: original MIPS .pdata 40501790..40501857. Semantic name remains unreviewed. */

HRSRC FindResourceA(HMODULE hModule,LPCSTR lpName,LPCSTR lpType)

{
  HRSRC pHVar1;
  
                    /* 0x1790  17  FindResourceA */
  pHVar1 = (HRSRC)0x0;
  if ((uint)lpName >> 0x10 != 0) {
    lpName = (LPCSTR)FUN_405011b8(lpName);
  }
  if ((uint)lpType >> 0x10 != 0) {
    lpType = (LPCSTR)FUN_405011b8(lpType);
  }
  if ((LPCWSTR)lpName != (LPCWSTR)0x0) {
    if ((LPCWSTR)lpType != (LPCWSTR)0x0) {
      pHVar1 = FindResourceW(hModule,(LPCWSTR)lpName,(LPCWSTR)lpType);
    }
    if ((uint)lpName >> 0x10 != 0) {
      LocalFree(lpName);
    }
  }
  if (((LPCWSTR)lpType != (LPCWSTR)0x0) && ((uint)lpType >> 0x10 != 0)) {
    LocalFree(lpType);
  }
  return pHVar1;
}



/* 40501858 CompareStringA */

/* Boundary evidence: original MIPS .pdata 40501858..4050190f. Semantic name remains unreviewed. */

int CompareStringA(LCID Locale,DWORD dwCmpFlags,PCNZCH lpString1,int cchCount1,PCNZCH lpString2,
                  int cchCount2)

{
  LPWSTR lpString1_00;
  LPWSTR lpString2_00;
  int iVar1;
  
                    /* 0x1858  10  CompareStringA */
  iVar1 = 0;
  lpString1_00 = FUN_405011b8(lpString1);
  lpString2_00 = FUN_405011b8(lpString2);
  if (lpString1_00 != (LPWSTR)0x0) {
    if (lpString2_00 != (LPWSTR)0x0) {
      iVar1 = CompareStringW(Locale,dwCmpFlags,lpString1_00,cchCount1,lpString2_00,cchCount2);
    }
    LocalFree(lpString1_00);
  }
  if (lpString2_00 != (LPWSTR)0x0) {
    LocalFree(lpString2_00);
  }
  return iVar1;
}



/* 40501910 CreateFileA */

/* Boundary evidence: original MIPS .pdata 40501910..405019a7. Semantic name remains unreviewed. */

HANDLE CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,
                  LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,
                  DWORD dwFlagsAndAttributes,HANDLE hTemplateFile)

{
  LPWSTR lpFileName_00;
  HANDLE pvVar1;
  
                    /* 0x1910  12  CreateFileA */
  pvVar1 = (HANDLE)0xffffffff;
  lpFileName_00 = FUN_405011b8(lpFileName);
  if (lpFileName_00 != (LPWSTR)0x0) {
    pvVar1 = CreateFileW(lpFileName_00,dwDesiredAccess,dwShareMode,lpSecurityAttributes,
                         dwCreationDisposition,dwFlagsAndAttributes,hTemplateFile);
    LocalFree(lpFileName_00);
  }
  return pvVar1;
}



/* 405019a8 GetFileAttributesA */

/* Boundary evidence: original MIPS .pdata 405019a8..405019f7. Semantic name remains unreviewed. */

DWORD GetFileAttributesA(LPCSTR lpFileName)

{
  LPWSTR lpFileName_00;
  DWORD DVar1;
  
                    /* 0x19a8  20  GetFileAttributesA */
  DVar1 = 0;
  lpFileName_00 = FUN_405011b8(lpFileName);
  if (lpFileName_00 != (LPWSTR)0x0) {
    DVar1 = GetFileAttributesW(lpFileName_00);
    LocalFree(lpFileName_00);
  }
  return DVar1;
}



/* 405019f8 GetModuleHandleA */

/* Boundary evidence: original MIPS .pdata 405019f8..40501a47. Semantic name remains unreviewed. */

HMODULE GetModuleHandleA(LPCSTR lpModuleName)

{
  LPWSTR lpModuleName_00;
  HMODULE pHVar1;
  
                    /* 0x19f8  22  GetModuleHandleA */
  pHVar1 = (HMODULE)0x0;
  lpModuleName_00 = FUN_405011b8(lpModuleName);
  if (lpModuleName_00 != (LPWSTR)0x0) {
    pHVar1 = GetModuleHandleW(lpModuleName_00);
    LocalFree(lpModuleName_00);
  }
  return pHVar1;
}



/* 40501a48 GetTempFileNameA */

/* Boundary evidence: original MIPS .pdata 40501a48..40501b27. Semantic name remains unreviewed. */

UINT GetTempFileNameA(LPCSTR lpPathName,LPCSTR lpPrefixString,UINT uUnique,LPSTR lpTempFileName)

{
  LPWSTR lpPathName_00;
  LPWSTR lpPrefixString_00;
  UINT UVar1;
  WCHAR aWStack_228 [260];
  uint local_20;
  
                    /* 0x1a48  23  GetTempFileNameA */
  local_20 = DAT_405040fc;
  lpPathName_00 = FUN_405011b8(lpPathName);
  lpPrefixString_00 = FUN_405011b8(lpPrefixString);
  UVar1 = GetTempFileNameW(lpPathName_00,lpPrefixString_00,uUnique,aWStack_228);
  if (UVar1 == 0) {
    *lpTempFileName = '\0';
  }
  else {
    WideCharToMultiByte(0,0,aWStack_228,-1,lpTempFileName,0x104,(LPCSTR)0x0,(LPBOOL)0x0);
  }
  if (lpPathName_00 != (LPWSTR)0x0) {
    LocalFree(lpPathName_00);
  }
  if (lpPrefixString_00 != (LPWSTR)0x0) {
    LocalFree(lpPrefixString_00);
  }
  FUN_40502aac(local_20);
  return UVar1;
}



/* 40501b28 LoadLibraryA */

/* Boundary evidence: original MIPS .pdata 40501b28..40501b77. Semantic name remains unreviewed. */

HMODULE LoadLibraryA(LPCSTR lpLibFileName)

{
  LPWSTR lpLibFileName_00;
  HMODULE pHVar1;
  
                    /* 0x1b28  30  LoadLibraryA */
  pHVar1 = (HMODULE)0x0;
  lpLibFileName_00 = FUN_405011b8(lpLibFileName);
  if (lpLibFileName_00 != (LPWSTR)0x0) {
    pHVar1 = LoadLibraryW(lpLibFileName_00);
    LocalFree(lpLibFileName_00);
  }
  return pHVar1;
}



/* 40501b78 CreateEventA */

/* Boundary evidence: original MIPS .pdata 40501b78..40501bfb. Semantic name remains unreviewed. */

HANDLE CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes,BOOL bManualReset,BOOL bInitialState,
                   LPCSTR lpName)

{
  LPWSTR lpName_00;
  HANDLE pvVar1;
  
                    /* 0x1b78  11  CreateEventA */
  pvVar1 = (HANDLE)0x0;
  lpName_00 = FUN_405011b8(lpName);
  if (lpName_00 != (LPWSTR)0x0) {
    pvVar1 = CreateEventW(lpEventAttributes,bManualReset,bInitialState,lpName_00);
    LocalFree(lpName_00);
  }
  return pvVar1;
}



/* 40501bfc lstrlenA */

/* Boundary evidence: original MIPS .pdata 40501bfc..40501c17. Semantic name remains unreviewed. */

int lstrlenA(LPCSTR lpString)

{
  size_t sVar1;
  
                    /* 0x1bfc  42  lstrlenA */
  sVar1 = strlen(lpString);
  return sVar1;
}



/* 40501c18 OleUninitialize */

/* Boundary evidence: original MIPS .pdata 40501c18..40501c33. Semantic name remains unreviewed. */

void OleUninitialize(void)

{
                    /* 0x1c18  37  OleUninitialize */
  CoUninitialize();
  return;
}



/* 40501c34 CoInitialize */

/* Boundary evidence: original MIPS .pdata 40501c34..40501c4f. Semantic name remains unreviewed. */

HRESULT CoInitialize(LPVOID pvReserved)

{
  HRESULT HVar1;
  
                    /* 0x1c34  4  CoInitialize */
  HVar1 = CoInitializeEx(pvReserved,0);
  return HVar1;
}



/* 40501c50 CoGetInterfaceAndReleaseStream */

HRESULT CoGetInterfaceAndReleaseStream(IID *riid,LPUNKNOWN pUnk,LPSTREAM *ppStm)

{
                    /* 0x1c50  2  CoGetInterfaceAndReleaseStream
                       0x1c50  3  CoGetMarshalSizeMax
                       0x1c50  5  CoMarshalInterThreadInterfaceInStream
                       0x1c50  6  CoMarshalInterface
                       0x1c50  9  CoUnmarshalInterface
                       0x1c50  32  MkParseDisplayName */
  return -0x7fffbffb;
}



/* 40501c5c CoRegisterClassObject */

HRESULT CoRegisterClassObject(void)

{
                    /* 0x1c5c  7  CoRegisterClassObject
                       0x1c5c  8  CoRevokeClassObject
                       0x1c5c  18  FormatMessageA
                       0x1c5c  28  IEUsesDCOM
                       0x1c5c  33  OleFlushClipboard
                       0x1c5c  35  OleIsCurrentClipboard
                       0x1c5c  39  SetErrorMode */
  return 0;
}



/* 40501c64 CreateMutexA */

/* Boundary evidence: original MIPS .pdata 40501c64..40501d33. Semantic name remains unreviewed. */

HANDLE CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes,BOOL bInitialOwner,LPCSTR lpName)

{
  size_t sVar1;
  HANDLE pvVar2;
  int iVar3;
  LPCWSTR lpName_00;
  int aiStack_28 [2];
  uint local_20 [2];
  
                    /* 0x1c64  13  CreateMutexA */
  local_20[0] = DAT_405040fc;
  if (lpName == (LPCSTR)0x0) {
    lpName_00 = (LPCWSTR)0x0;
  }
  else {
    sVar1 = strlen(lpName);
    iVar3 = (int)((sVar1 + 1) * 2 + 7) >> 3;
    lpName_00 = (LPCWSTR)(local_20 + iVar3 * -2);
    *lpName_00 = L'\0';
    aiStack_28[iVar3 * -2 + 1] = sVar1 + 1;
    aiStack_28[iVar3 * -2] = (int)lpName_00;
    MultiByteToWideChar(0,0,lpName,-1,(LPWSTR)aiStack_28[iVar3 * -2],aiStack_28[iVar3 * -2 + 1]);
  }
  pvVar2 = CreateMutexW(lpMutexAttributes,bInitialOwner,lpName_00);
  FUN_40502aac(local_20[0]);
  return pvVar2;
}



/* 40501d34 GetLastActivePopup */

HWND GetLastActivePopup(HWND hWnd)

{
                    /* 0x1d34  21  GetLastActivePopup */
  return hWnd;
}



/* 40501d3c FUN_40501d3c */

/* Boundary evidence: original MIPS .pdata 40501d3c..40501e0b. Semantic name remains unreviewed. */

undefined4 FUN_40501d3c(HWND param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  HWND hWnd;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  
  if ((int)param_2[2] < 1) {
LAB_40501d60:
    uVar1 = 0;
  }
  else {
    hWnd = GetWindow(param_1,5);
    for (iVar4 = 0x400; ((hWnd != (HWND)0x0 && (BVar2 = IsWindow(hWnd), BVar2 != 0)) && (0 < iVar4))
        ; iVar4 = iVar4 + -1) {
      iVar3 = (*(code *)*param_2)(hWnd,param_2[1]);
      if (iVar3 == 0) goto LAB_40501d60;
      param_2[2] = param_2[2] + -1;
      iVar3 = FUN_40501d3c(hWnd,param_2);
      param_2[3] = iVar3;
      param_2[2] = param_2[2] + 1;
      if (iVar3 == 0) goto LAB_40501d60;
      hWnd = GetWindow(hWnd,2);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 40501e0c EnumChildWindows */

/* Boundary evidence: original MIPS .pdata 40501e0c..40501e7f. Semantic name remains unreviewed. */

BOOL EnumChildWindows(HWND hWndParent,WNDENUMPROC lpEnumFunc,LPARAM lParam)

{
  BOOL BVar1;
  WNDENUMPROC local_20;
  LPARAM local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1e0c  15  EnumChildWindows */
  BVar1 = IsWindow(hWndParent);
  if (BVar1 == 0) {
    BVar1 = 0;
  }
  else {
    local_18 = 0x40;
    local_14 = 0;
    local_20 = lpEnumFunc;
    local_1c = lParam;
    BVar1 = FUN_40501d3c(hWndParent,&local_20);
  }
  return BVar1;
}



/* 40501e80 GetDIBits */

/* Boundary evidence: original MIPS .pdata 40501e80..40501f47. Semantic name remains unreviewed. */

int GetDIBits(HDC hdc,HBITMAP hbm,UINT start,UINT cLines,LPVOID lpvBits,LPBITMAPINFO lpbmi,
             UINT usage)

{
  RGBQUAD RVar1;
  DWORD DVar2;
  LONG LVar3;
  undefined1 auStack_20 [4];
  LONG local_1c;
  LONG local_18;
  WORD local_10;
  ushort local_e;
  
                    /* 0x1e80  19  GetDIBits */
  GetObjectW(hbm,0x18,auStack_20);
  (lpbmi->bmiHeader).biWidth = local_1c;
  (lpbmi->bmiHeader).biSize = 0x28;
  (lpbmi->bmiHeader).biHeight = local_18;
  (lpbmi->bmiHeader).biPlanes = local_10;
  (lpbmi->bmiHeader).biBitCount = local_e;
  if (local_e < 0x10) {
    (lpbmi->bmiHeader).biCompression = 0;
  }
  else {
    (lpbmi->bmiHeader).biCompression = 3;
  }
  (lpbmi->bmiHeader).biSizeImage = 0;
  (lpbmi->bmiHeader).biXPelsPerMeter = 0;
  (lpbmi->bmiHeader).biYPelsPerMeter = 0;
  (lpbmi->bmiHeader).biClrUsed = 0;
  (lpbmi->bmiHeader).biClrImportant = 0;
  if (local_e == 0x10) {
    RVar1.rgbBlue = '\0';
    RVar1.rgbGreen = 0xf8;
    RVar1.rgbRed = '\0';
    RVar1.rgbReserved = '\0';
    DVar2 = 0x7e0;
    LVar3 = 0x1f;
  }
  else {
    if (local_e < 0x18) {
      return 0;
    }
    RVar1.rgbBlue = '\0';
    RVar1.rgbGreen = '\0';
    RVar1.rgbRed = 0xff;
    RVar1.rgbReserved = '\0';
    DVar2 = 0xff00;
    LVar3 = 0xff;
  }
  lpbmi[1].bmiHeader.biWidth = LVar3;
  lpbmi[1].bmiHeader.biSize = DVar2;
  lpbmi->bmiColors[0].rgbBlue = RVar1.rgbBlue;
  lpbmi->bmiColors[0].rgbGreen = RVar1.rgbGreen;
  lpbmi->bmiColors[0].rgbRed = RVar1.rgbRed;
  lpbmi->bmiColors[0].rgbReserved = RVar1.rgbReserved;
  return 0;
}



/* 40501f48 ExtSelectClipRgn */

/* Boundary evidence: original MIPS .pdata 40501f48..40502023. Semantic name remains unreviewed. */

int ExtSelectClipRgn(HDC hdc,HRGN hrgn,int mode)

{
  HRGN hrgnDst;
  HRGN hrgn_00;
  int iVar1;
  int iVar2;
  
                    /* 0x1f48  16  ExtSelectClipRgn */
  iVar2 = 0;
  hrgnDst = CreateRectRgn(0,0,0,0);
  hrgn_00 = CreateRectRgn(0,0,0,0);
  iVar1 = GetClipRgn(hdc,hrgn_00);
  if (iVar1 == 1) {
    iVar2 = CombineRgn(hrgnDst,hrgn_00,hrgn,mode);
    hrgn = hrgnDst;
  }
  SelectClipRgn(hdc,hrgn);
  DeleteObject(hrgn_00);
  DeleteObject(hrgnDst);
  return iVar2;
}



/* 40502024 FUN_40502024 */

/* Boundary evidence: original MIPS .pdata 40502024..4050206b. Semantic name remains unreviewed. */

void FUN_40502024(void)

{
  UINT UVar1;
  
  if (DAT_4050410c == 0) {
    DAT_4050410c = 1;
    UVar1 = RegisterClipboardFormatW(L"HTML Format");
    DAT_405040f8 = UVar1 & 0xffff;
  }
  return;
}



/* 4050206c OleSetClipboard */

/* Boundary evidence: original MIPS .pdata 4050206c..4050220b. Semantic name remains unreviewed. */

HRESULT OleSetClipboard(LPDATAOBJECT pDataObj)

{
  BOOL BVar1;
  HRESULT HVar2;
  HANDLE pvVar3;
  DWORD DVar4;
  UINT *pUVar5;
  STGMEDIUM SStack_40;
  FORMATETC local_30;
  
                    /* 0x206c  36  OleSetClipboard */
  DVar4 = 1;
  BVar1 = OpenClipboard((HWND)0x0);
  if (BVar1 == 0) {
    DVar4 = GetLastError();
    if ((int)DVar4 < 1) {
      DVar4 = GetLastError();
    }
    else {
      DVar4 = GetLastError();
      DVar4 = DVar4 & 0xffff | 0x80070000;
    }
  }
  else {
    BVar1 = EmptyClipboard();
    if (BVar1 == 0) {
      GetLastError();
      GetLastError();
    }
    else {
      FUN_40502024();
      pUVar5 = &DAT_405040f0;
      do {
        if (*pUVar5 != 0) {
          local_30.cfFormat = (CLIPFORMAT)*pUVar5;
          local_30.ptd = (DVTARGETDEVICE *)0x0;
          local_30.dwAspect = 1;
          local_30.lindex = -1;
          local_30.tymed = 1;
          HVar2 = (*pDataObj->lpVtbl->GetData)(pDataObj,&local_30,&SStack_40);
          if (HVar2 == 0) {
            pvVar3 = SetClipboardData(*pUVar5,SStack_40.u.hMetaFilePict);
            if (pvVar3 == (HANDLE)0x0) {
              DVar4 = GetLastError();
              if ((int)DVar4 < 1) {
                DVar4 = GetLastError();
              }
              else {
                DVar4 = GetLastError();
                DVar4 = DVar4 & 0xffff | 0x80070000;
              }
              break;
            }
            DVar4 = 0;
          }
        }
        pUVar5 = pUVar5 + 1;
      } while ((int)pUVar5 < 0x405040fc);
    }
    CloseClipboard();
  }
  return DVar4;
}



/* 4050221c FUN_4050221c */

/* Boundary evidence: original MIPS .pdata 4050221c..40502253. Semantic name remains unreviewed. */

int FUN_4050221c(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 4) + -1;
  *(int *)((int)param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    operator_delete(param_1);
  }
  return iVar1;
}



/* 40502254 FUN_40502254 */

/* Boundary evidence: original MIPS .pdata 40502254..40502397. Semantic name remains unreviewed. */

DWORD FUN_40502254(undefined4 param_1,ushort *param_2,undefined4 *param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  HANDLE hMem;
  SIZE_T uBytes;
  HLOCAL _Dst;
  
  BVar1 = OpenClipboard((HWND)0x0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if ((int)DVar2 < 1) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = GetLastError();
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
  }
  else {
    hMem = GetClipboardData((uint)*param_2);
    if (hMem == (HANDLE)0x0) {
      DVar2 = GetLastError();
      if ((int)DVar2 < 1) {
        DVar2 = GetLastError();
      }
      else {
        DVar2 = GetLastError();
        DVar2 = DVar2 & 0xffff | 0x80070000;
      }
    }
    else {
      uBytes = LocalSize(hMem);
      _Dst = LocalAlloc(0,uBytes);
      if (_Dst == (HLOCAL)0x0) {
        DVar2 = 0x8007000e;
      }
      else {
        memcpy(_Dst,hMem,uBytes);
        param_3[1] = _Dst;
        *param_3 = 1;
        param_3[2] = 0;
        DVar2 = 0;
      }
    }
    CloseClipboard();
  }
  return DVar2;
}



/* 405023a4 OleGetClipboard */

/* Boundary evidence: original MIPS .pdata 405023a4..40502423. Semantic name remains unreviewed. */

HRESULT OleGetClipboard(LPDATAOBJECT *ppDataObj)

{
  LPDATAOBJECT pIVar1;
  HRESULT HVar2;
  
                    /* 0x23a4  34  OleGetClipboard */
  if (ppDataObj == (LPDATAOBJECT *)0x0) {
    HVar2 = -0x7ff8ffa9;
  }
  else {
    pIVar1 = operator_new(8);
    if (pIVar1 == (LPDATAOBJECT)0x0) {
      pIVar1 = (LPDATAOBJECT)0x0;
    }
    else {
      pIVar1->lpVtbl = (IDataObjectVtbl *)&PTR_LAB_40501078;
      pIVar1[1].lpVtbl = (IDataObjectVtbl *)0x1;
    }
    *ppDataObj = pIVar1;
    if (pIVar1 == (LPDATAOBJECT)0x0) {
      HVar2 = -0x7ff8fff2;
    }
    else {
      FUN_40502024();
      HVar2 = 0;
    }
  }
  return HVar2;
}



/* 40502424 bsearch */

/* Boundary evidence: original MIPS .pdata 40502424..40502533. Semantic name remains unreviewed. */

void * bsearch(void *_Key,void *_Base,size_t _NumOfElements,size_t _SizeOfElements,
              _PtFuncCompare *_PtFuncCompare)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  void *pvVar5;
  
                    /* 0x2424  41  bsearch */
  pvVar5 = (void *)((_NumOfElements - 1) * _SizeOfElements + (int)_Base);
  if (_Base <= pvVar5) {
    do {
      uVar4 = _NumOfElements >> 1;
      if (uVar4 == 0) {
        if (_NumOfElements == 0) {
          return (void *)0x0;
        }
        iVar1 = (*_PtFuncCompare)(_Key,_Base);
        if (iVar1 != 0) {
          return (void *)0x0;
        }
        return _Base;
      }
      uVar2 = uVar4;
      if ((_NumOfElements & 1) == 0) {
        uVar2 = uVar4 - 1;
      }
      pvVar3 = (void *)(uVar2 * _SizeOfElements + (int)_Base);
      iVar1 = (*_PtFuncCompare)(_Key,pvVar3);
      if (iVar1 == 0) {
        return pvVar3;
      }
      if (iVar1 < 0) {
        pvVar5 = (void *)((int)pvVar3 - _SizeOfElements);
        if ((_NumOfElements & 1) == 0) {
          uVar4 = uVar4 - 1;
        }
      }
      else {
        _Base = (void *)((int)pvVar3 + _SizeOfElements);
      }
      _NumOfElements = uVar4;
    } while (_Base <= pvVar5);
  }
  return (void *)0x0;
}



/* 40502534 time */

/* Boundary evidence: original MIPS .pdata 40502534..40502577. Semantic name remains unreviewed. */

time_t time(time_t *_Time)

{
  DWORD DVar1;
  undefined4 extraout_v1;
  
                    /* 0x2534  43  time */
  DVar1 = GetTickCount();
  if (_Time != (time_t *)0x0) {
    *(uint *)_Time = DVar1 / 1000;
  }
  return CONCAT44(extraout_v1,DVar1 / 1000);
}



/* 405027f8 FUN_405027f8 */

/* Boundary evidence: original MIPS .pdata 405027f8..40502933. Semantic name remains unreviewed. */

int FUN_405027f8(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40504120 != (code *)0x0) {
      iVar2 = (*DAT_40504120)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_405028a8;
    FUN_40502c8c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_405010cc(param_1,param_2);
  }
LAB_405028a8:
  if (((param_2 == 0) && (FUN_40502c14(), iVar1 != 0)) && (DAT_40504120 != (code *)0x0)) {
    iVar1 = (*DAT_40504120)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40502934 FUN_40502934 */

/* Boundary evidence: original MIPS .pdata 40502934..4050295f. Semantic name remains unreviewed. */

void FUN_40502934(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40502960 entry */

/* Boundary evidence: original MIPS .pdata 40502960..405029b7. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_405029b8();
  }
  FUN_405027f8(param_1,param_2,param_3);
  return;
}



/* 405029b8 FUN_405029b8 */

/* Boundary evidence: original MIPS .pdata 405029b8..40502a2b. Semantic name remains unreviewed. */

void FUN_405029b8(void)

{
  uint uVar1;
  
  if ((DAT_405040fc == 0) || (DAT_405040fc == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_405040fc = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_405040fc == 0) {
      DAT_405040fc = 0xb064;
    }
  }
  DAT_40504100 = ~DAT_405040fc;
  return;
}



/* 40502a2c FUN_40502a2c */

/* Boundary evidence: original MIPS .pdata 40502a2c..40502a7f. Semantic name remains unreviewed. */

void FUN_40502a2c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40502aac(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40502a80 FUN_40502a80 */

/* Boundary evidence: original MIPS .pdata 40502a80..40502aab. Semantic name remains unreviewed. */

undefined4 FUN_40502a80(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40502a2c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40502aac FUN_40502aac */

/* Boundary evidence: original MIPS .pdata 40502aac..40502af3. Semantic name remains unreviewed. */

void FUN_40502aac(uint param_1)

{
  if ((param_1 == DAT_405040fc) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40502af4 FUN_40502af4 */

/* Boundary evidence: original MIPS .pdata 40502af4..40502c13. Semantic name remains unreviewed. */

void FUN_40502af4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_40504110 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40504118;
    if (DAT_40504118 != (undefined4 *)0x0) {
      while (DAT_40504114 = DAT_40504114 + -1, _Memory <= DAT_40504114) {
        if ((code *)*DAT_40504114 != (code *)0x0) {
          (*(code *)*DAT_40504114)();
          _Memory = DAT_40504118;
        }
      }
      free(_Memory);
      DAT_40504114 = (undefined4 *)0x0;
      DAT_40504118 = (undefined4 *)0x0;
    }
    FUN_40502c38((undefined4 *)&DAT_40501010,(undefined4 *)&DAT_40501014);
  }
  FUN_40502c38((undefined4 *)&DAT_40501018,(undefined4 *)&DAT_4050101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_4050411c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40502c14 FUN_40502c14 */

/* Boundary evidence: original MIPS .pdata 40502c14..40502c37. Semantic name remains unreviewed. */

void FUN_40502c14(void)

{
  FUN_40502af4(0,0,1);
  return;
}



/* 40502c38 FUN_40502c38 */

/* Boundary evidence: original MIPS .pdata 40502c38..40502c8b. Semantic name remains unreviewed. */

void FUN_40502c38(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40502c8c FUN_40502c8c */

/* Boundary evidence: original MIPS .pdata 40502c8c..40502cc7. Semantic name remains unreviewed. */

void FUN_40502c8c(void)

{
  FUN_40502c38((undefined4 *)&DAT_40501008,(undefined4 *)&DAT_4050100c);
  FUN_40502c38((undefined4 *)&DAT_40501000,(undefined4 *)&DAT_40501004);
  return;
}


