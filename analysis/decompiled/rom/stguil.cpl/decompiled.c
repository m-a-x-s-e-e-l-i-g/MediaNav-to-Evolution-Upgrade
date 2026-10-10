/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40661330 FUN_40661330 */

/* Boundary evidence: original MIPS .pdata 40661330..40661443. Semantic name remains unreviewed. */

undefined4 FUN_40661330(undefined4 param_1,undefined4 param_2,wchar_t *param_3,size_t param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar4 = __ll_to_d();
  for (uVar3 = 0;
      (uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20), iVar1 = __ged((int)uVar4,uVar2,0,0x40900000),
      iVar1 != 0 && (uVar3 < 4)); uVar3 = uVar3 + 1) {
    uVar4 = __dpmul((int)uVar4,uVar2,0,0x3f500000);
  }
  _snwprintf(param_3,param_4,L"%.2f %s\n");
  return 1;
}



/* 40661444 FUN_40661444 */

/* Boundary evidence: original MIPS .pdata 40661444..4066154f. Semantic name remains unreviewed. */

void FUN_40661444(HWND param_1,UINT param_2,DWORD param_3)

{
  DWORD DVar1;
  LPCWSTR local_228 [2];
  WCHAR local_220;
  undefined1 auStack_21e [518];
  uint local_18;
  
  local_18 = DAT_40664144;
  local_220 = L'\0';
  memset(auStack_21e,0,0x206);
  local_228[0] = (LPCWSTR)0x0;
  DVar1 = FormatMessageW(0x1100,(LPCVOID)0x0,param_3,0x409,(LPWSTR)local_228,500,(va_list *)0x0);
  if ((local_228[0] == (LPCWSTR)0x0) || (DVar1 == 0)) {
    local_228[0] = L"";
  }
  else {
    local_228[0][DVar1] = L'\0';
  }
  LoadStringW(DAT_4066414c,param_2,&local_220,0x104);
  MessageBoxW(param_1,local_228[0],&local_220,0);
  if ((local_228[0] != (LPCWSTR)0x0) && (DVar1 != 0)) {
    LocalFree(local_228[0]);
  }
  FUN_40663a20(local_18);
  return;
}



/* 40661550 FUN_40661550 */

/* Boundary evidence: original MIPS .pdata 40661550..40661643. Semantic name remains unreviewed. */

void FUN_40661550(HWND param_1)

{
  HDC hdc;
  int iVar1;
  int iVar2;
  tagRECT local_28;
  
  local_28.left = 0;
  memset(&local_28.top,0,0xc);
  hdc = GetDC(param_1);
  if (hdc != (HDC)0x0) {
    iVar1 = GetDeviceCaps(hdc,8);
    iVar2 = GetDeviceCaps(hdc,10);
    GetWindowRect(param_1,&local_28);
    iVar2 = (local_28.top - local_28.bottom) + iVar2;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 1;
    }
    iVar1 = (iVar1 - local_28.right) + local_28.left;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 1;
    }
    MoveWindow(param_1,iVar1 >> 1,iVar2 >> 1,local_28.right - local_28.left,
               local_28.bottom - local_28.top,1);
    ReleaseDC(param_1,hdc);
  }
  return;
}



/* 40661644 FUN_40661644 */

/* Boundary evidence: original MIPS .pdata 40661644..40661753. Semantic name remains unreviewed. */

INT_PTR FUN_40661644(void)

{
  LPCWSTR lpWindowName;
  HWND pHVar1;
  INT_PTR IVar2;
  PROPSHEETHEADERW_V2 local_60;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  code *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  lpWindowName = (LPCWSTR)LoadStringW(DAT_4066414c,0x232a,(LPWSTR)0x0,0);
  pHVar1 = FindWindowW(L"Dialog",lpWindowName);
  if (pHVar1 == (HWND)0x0) {
    local_2c = 0x66;
    local_60.u4 = (_union_1967)0x28;
    local_60.hplWatermark = (HPALETTE)0x28;
    local_60.u5.hbmHeader = (HBITMAP)DAT_4066414c;
    local_28 = 0;
    local_20 = FUN_406629ec;
    local_24 = LoadStringW(DAT_4066414c,8000,(LPWSTR)0x0,0);
    local_18 = 0;
    local_1c = 0;
    local_60.dwSize = 0x28;
    local_60.dwFlags = 0x30c;
    local_60.hwndParent = (HWND)0x0;
    local_60.hInstance = DAT_4066414c;
    local_60.u.hIcon = (HICON)0x1b58;
    local_60.pszCaption = (LPCWSTR)LoadStringW(DAT_4066414c,0x232a,(LPWSTR)0x0,0);
    local_60.nPages = 1;
    local_60.pfnCallback = (PFNPROPSHEETCALLBACK)&LAB_40662928;
    local_60.u3.ppsp = (LPCPROPSHEETPAGEW)&local_60.u4;
    local_60.u2.nStartPage = 0;
    IVar2 = PropertySheetW(&local_60);
  }
  else {
    SetForegroundWindow((HWND)((uint)pHVar1 | 1));
    IVar2 = 0;
  }
  return IVar2;
}



/* 40661754 FUN_40661754 */

undefined4 FUN_40661754(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_4066414c = param_1;
  }
  return 1;
}



/* 40661770 CPlApplet */

/* Boundary evidence: original MIPS .pdata 40661770..4066188f. Semantic name remains unreviewed. */

undefined4 CPlApplet(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  HICON pHVar1;
  
                    /* 0x1770  1  CPlApplet */
  if (param_2 == 1) {
    if (DAT_40664150 == 0) {
      DAT_40664150 = 1;
      return 1;
    }
  }
  else {
    if (param_2 == 2) {
      return 1;
    }
    if (param_2 == 5) {
      FUN_40661644();
    }
    else if (5 < param_2) {
      if (param_2 < 8) {
        DAT_40664150 = DAT_40664150 + -1;
      }
      else if (param_2 == 8) {
        *param_4 = 0x1d4;
        param_4[1] = 0;
        param_4[2] = 0;
        param_4[3] = 7000;
        pHVar1 = LoadIconW(DAT_4066414c,(LPCWSTR)0x1b58);
        param_4[4] = pHVar1;
        *(undefined1 *)(param_4 + 0x35) = 0;
        *(undefined1 *)((int)param_4 + 0xd5) = 0;
        LoadStringW(DAT_4066414c,8000,(LPWSTR)(param_4 + 5),0x20);
        LoadStringW(DAT_4066414c,0x2329,(LPWSTR)(param_4 + 0x15),0x40);
      }
    }
  }
  return 0;
}



/* 40661890 FUN_40661890 */

/* Boundary evidence: original MIPS .pdata 40661890..4066198b. Semantic name remains unreviewed. */

bool FUN_40661890(int param_1,LPBYTE param_2,int param_3)

{
  LSTATUS LVar1;
  bool bVar2;
  HKEY local_230;
  DWORD local_22c;
  DWORD aDStack_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_40664144;
  bVar2 = false;
  local_230 = (HKEY)0x0;
  if (param_1 != 0) {
    StringCbPrintfW(awStack_220,0x208,L"System\\StorageManager\\Profiles\\%s",param_1);
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,awStack_220,0,0xf003f,&local_230);
    if ((LVar1 == 0) && (local_230 != (HKEY)0x0)) {
      local_22c = param_3 << 1;
      LVar1 = RegQueryValueExW(local_230,L"Name",(LPDWORD)0x0,aDStack_228,param_2,&local_22c);
      bVar2 = LVar1 == 0;
      RegCloseKey(local_230);
    }
  }
  FUN_40663a20(local_18);
  return bVar2;
}



/* 4066198c FUN_4066198c */

/* Boundary evidence: original MIPS .pdata 4066198c..40661a63. Semantic name remains unreviewed. */

undefined4 FUN_4066198c(HWND param_1)

{
  WPARAM wParam;
  LRESULT LVar1;
  wchar_t *pwVar2;
  HCURSOR pHVar3;
  undefined4 uVar4;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_40664144;
  uVar4 = 0xffffffff;
  wParam = SendDlgItemMessageW(param_1,0x3e9,0x147,0,0);
  if (wParam != 0xffffffff) {
    LVar1 = SendDlgItemMessageW(param_1,0x3e9,0x148,wParam,(LPARAM)awStack_220);
    if ((LVar1 != -1) && (pwVar2 = wcstok(awStack_220,L" "), pwVar2 != (wchar_t *)0x0)) {
      pHVar3 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
      pHVar3 = SetCursor(pHVar3);
      uVar4 = OpenStore(pwVar2);
      SetCursor(pHVar3);
    }
  }
  FUN_40663a20(local_18);
  return uVar4;
}



/* 40661a64 FUN_40661a64 */

/* Boundary evidence: original MIPS .pdata 40661a64..40661b83. Semantic name remains unreviewed. */

undefined4 FUN_40661a64(HWND param_1)

{
  WPARAM wParam;
  HANDLE hObject;
  LRESULT LVar1;
  HCURSOR pHVar2;
  size_t sVar3;
  undefined4 uVar4;
  wchar_t local_60;
  undefined1 auStack_5e [62];
  uint local_20;
  
  local_20 = DAT_40664144;
  local_60 = L'\0';
  memset(auStack_5e,0,0x3e);
  uVar4 = 0xffffffff;
  wParam = SendDlgItemMessageW(param_1,0x3eb,0x188,0,0);
  if ((wParam != 0xffffffff) &&
     (hObject = (HANDLE)FUN_4066198c(param_1), hObject != (HANDLE)0xffffffff)) {
    LVar1 = SendDlgItemMessageW(param_1,0x3eb,0x189,wParam,(LPARAM)&local_60);
    if (LVar1 != -1) {
      pHVar2 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
      pHVar2 = SetCursor(pHVar2);
      sVar3 = wcslen(&local_60);
      *(undefined2 *)(auStack_5e + (sVar3 - 2) * 2 + -2) = 0;
      uVar4 = OpenPartition(hObject,&local_60);
      SetCursor(pHVar2);
    }
    CloseHandle(hObject);
  }
  FUN_40663a20(local_20);
  return uVar4;
}



/* 40661b84 FUN_40661b84 */

/* Boundary evidence: original MIPS .pdata 40661b84..40661d7b. Semantic name remains unreviewed. */

void FUN_40661b84(HWND param_1)

{
  bool bVar1;
  WPARAM wParam;
  LRESULT LVar2;
  HANDLE hFindFile;
  undefined3 extraout_var;
  int iVar3;
  HWND pHVar4;
  undefined4 local_520;
  wchar_t awStack_51c [46];
  undefined1 auStack_4c0 [144];
  wchar_t awStack_430 [260];
  BYTE aBStack_228 [520];
  uint local_20;
  
  local_20 = DAT_40664144;
  local_520 = 0;
  memset(awStack_51c,0,0xec);
  wParam = SendDlgItemMessageW(param_1,0x3e9,0x147,0,0);
  if (wParam == 0xffffffff) {
    wParam = 0;
  }
  local_520 = 0xf0;
  do {
    LVar2 = SendDlgItemMessageW(param_1,0x3e9,0x144,0,0);
  } while (LVar2 != -1);
  hFindFile = (HANDLE)FindFirstStore(&local_520);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      bVar1 = FUN_40661890((int)auStack_4c0,aBStack_228,0x104);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        wcscpy(awStack_430,awStack_51c);
      }
      else {
        swprintf(awStack_430,0x406610ec,awStack_51c,aBStack_228);
      }
      SendDlgItemMessageW(param_1,0x3e9,0x143,0,(LPARAM)awStack_430);
      iVar3 = FindNextStore(hFindFile,&local_520);
    } while (iVar3 != 0);
    FindClose(hFindFile);
    SendDlgItemMessageW(param_1,0x3e9,0x14e,wParam,0);
  }
  LVar2 = SendDlgItemMessageW(param_1,0x3e9,0x147,0,0);
  pHVar4 = GetDlgItem(param_1,0x3fa);
  EnableWindow(pHVar4,(uint)(LVar2 != -1));
  pHVar4 = GetDlgItem(param_1,0x3fb);
  EnableWindow(pHVar4,(uint)(LVar2 != -1));
  pHVar4 = GetDlgItem(param_1,0x3ec);
  EnableWindow(pHVar4,(uint)(LVar2 != -1));
  FUN_40663a20(local_20);
  return;
}



/* 40661d7c FUN_40661d7c */

/* Boundary evidence: original MIPS .pdata 40661d7c..40661ee7. Semantic name remains unreviewed. */

void FUN_40661d7c(HWND param_1)

{
  HANDLE hObject;
  int iVar1;
  undefined4 local_310;
  undefined1 auStack_30c [172];
  uint local_260;
  int local_25c;
  uint local_258;
  uint local_248;
  int local_244;
  wchar_t local_220;
  undefined1 auStack_21e [518];
  uint local_18;
  
  local_18 = DAT_40664144;
  local_220 = L'\0';
  memset(auStack_21e,0,0x206);
  memset(auStack_30c,0,0xec);
  local_310 = 0xf0;
  hObject = (HANDLE)FUN_4066198c(param_1);
  if (hObject != (HANDLE)0xffffffff) {
    GetStoreInfo(hObject,&local_310);
    CloseHandle(hObject);
  }
  iVar1 = FUN_40661330((int)((ulonglong)local_258 * (ulonglong)local_260),
                       local_258 * local_25c +
                       (int)((ulonglong)local_258 * (ulonglong)local_260 >> 0x20),&local_220,0x104);
  if (iVar1 != 0) {
    SetDlgItemTextW(param_1,0x3f7,&local_220);
  }
  iVar1 = FUN_40661330((int)((ulonglong)local_258 * (ulonglong)local_248),
                       local_258 * local_244 +
                       (int)((ulonglong)local_258 * (ulonglong)local_248 >> 0x20),&local_220,0x104);
  if (iVar1 != 0) {
    SetDlgItemTextW(param_1,0x3f8,&local_220);
  }
  iVar1 = FUN_40661330(local_258,0,&local_220,0x104);
  if (iVar1 != 0) {
    SetDlgItemTextW(param_1,0x3f9,&local_220);
  }
  FUN_40663a20(local_18);
  return;
}



/* 40661ee8 FUN_40661ee8 */

/* Boundary evidence: original MIPS .pdata 40661ee8..406620a7. Semantic name remains unreviewed. */

void FUN_40661ee8(HWND param_1)

{
  LRESULT LVar1;
  HANDLE hObject;
  int iVar2;
  int iVar3;
  HWND pHVar4;
  wchar_t *pszFormat;
  undefined4 local_358;
  undefined1 auStack_354 [284];
  uint local_238;
  wchar_t awStack_230 [259];
  undefined2 local_2a;
  uint local_28;
  
  local_28 = DAT_40664144;
  memset(auStack_354,0,0x124);
  local_358 = 0x128;
  do {
    LVar1 = SendDlgItemMessageW(param_1,0x3eb,0x182,0,0);
  } while (LVar1 != -1);
  hObject = (HANDLE)FUN_4066198c(param_1);
  if (hObject != (HANDLE)0xffffffff) {
    iVar2 = FindFirstPartition(hObject,&local_358);
    if (iVar2 != -1) {
      do {
        pszFormat = L"%s *";
        if ((local_238 & 0x10) == 0) {
          pszFormat = L"%s  ";
        }
        StringCbPrintfW(awStack_230,0x208,pszFormat,auStack_354);
        local_2a = 0;
        SendDlgItemMessageW(param_1,0x3eb,0x180,0,(LPARAM)awStack_230);
        iVar3 = FindNextPartition(iVar2,&local_358);
      } while (iVar3 != 0);
    }
    SendDlgItemMessageW(param_1,0x3eb,0x186,0,0);
    CloseHandle(hObject);
  }
  LVar1 = SendDlgItemMessageW(param_1,0x3eb,0x188,0,0);
  pHVar4 = GetDlgItem(param_1,0x3ed);
  EnableWindow(pHVar4,(uint)(LVar1 != -1));
  pHVar4 = GetDlgItem(param_1,0x3ee);
  EnableWindow(pHVar4,(uint)(LVar1 != -1));
  FUN_40663a20(local_28);
  return;
}



/* 406620a8 FUN_406620a8 */

/* Boundary evidence: original MIPS .pdata 406620a8..40662127. Semantic name remains unreviewed. */

void FUN_406620a8(HWND param_1)

{
  EventModify(DAT_40664154,3);
  WaitForSingleObject(DAT_40664158,5000);
  CloseHandle(DAT_40664154);
  CloseHandle(DAT_40664158);
  EndDialog(param_1,1);
  return;
}



/* 40662128 FUN_40662128 */

/* Boundary evidence: original MIPS .pdata 40662128..406622d3. Semantic name remains unreviewed. */

void FUN_40662128(HWND param_1)

{
  HANDLE hObject;
  HCURSOR pHVar1;
  int iVar2;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar3;
  DWORD DVar4;
  undefined4 local_318;
  undefined1 auStack_314 [196];
  undefined4 local_250;
  undefined4 local_228;
  undefined1 auStack_224 [520];
  uint local_1c;
  
  local_1c = DAT_40664144;
  local_228 = 0;
  memset(auStack_224,0,0x208);
  memset(auStack_314,0,0xec);
  local_318 = 0xf0;
  hObject = (HANDLE)FUN_4066198c(param_1);
  if (hObject != (HANDLE)0xffffffff) {
    pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar1 = SetCursor(pHVar1);
    iVar2 = GetStoreInfo(hObject,&local_318);
    SetCursor(pHVar1);
    if (iVar2 != 0) {
      local_228 = local_250;
      hResInfo = FindResourceW(DAT_4066414c,(LPCWSTR)0x67,(LPCWSTR)0x5);
      hDialogTemplate = LoadResource(DAT_4066414c,hResInfo);
      IVar3 = DialogBoxIndirectParamW
                        (DAT_4066414c,hDialogTemplate,param_1,FUN_40662c2c,(LPARAM)&local_228);
      if (IVar3 != 0) {
        pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
        pHVar1 = SetCursor(pHVar1);
        iVar2 = CreatePartition(hObject,auStack_224,local_228,0);
        SetCursor(pHVar1);
        if (iVar2 == 0) {
          DVar4 = GetLastError();
          FUN_40661444(param_1,0x1771,DVar4);
        }
        FUN_40661d7c(param_1);
        FUN_40661ee8(param_1);
      }
    }
    CloseHandle(hObject);
  }
  FUN_40663a20(local_1c);
  return;
}



/* 406622d4 FUN_406622d4 */

/* Boundary evidence: original MIPS .pdata 406622d4..40662467. Semantic name remains unreviewed. */

void FUN_406622d4(HWND param_1)

{
  WPARAM wParam;
  LRESULT LVar1;
  size_t sVar2;
  HANDLE hObject;
  int iVar3;
  HCURSOR pHVar4;
  DWORD DVar5;
  wchar_t local_470;
  undefined1 auStack_46e [62];
  WCHAR aWStack_430 [260];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_40664144;
  local_470 = L'\0';
  memset(auStack_46e,0,0x3e);
  wParam = SendDlgItemMessageW(param_1,0x3eb,0x188,0,0);
  LVar1 = SendDlgItemMessageW(param_1,0x3eb,0x189,wParam,(LPARAM)&local_470);
  if (LVar1 != -1) {
    sVar2 = wcslen(&local_470);
    *(undefined2 *)(auStack_46e + (sVar2 - 2) * 2 + -2) = 0;
    hObject = (HANDLE)FUN_4066198c(param_1);
    if (hObject != (HANDLE)0xffffffff) {
      LoadStringW(DAT_4066414c,0x1779,aWStack_430,0x104);
      LoadStringW(DAT_4066414c,0x1778,aWStack_228,0x104);
      iVar3 = MessageBoxW(param_1,aWStack_228,aWStack_430,4);
      if (iVar3 == 6) {
        pHVar4 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
        pHVar4 = SetCursor(pHVar4);
        iVar3 = DeletePartition(hObject,&local_470);
        SetCursor(pHVar4);
        if (iVar3 == 0) {
          DVar5 = GetLastError();
          FUN_40661444(param_1,0x1772,DVar5);
        }
      }
      CloseHandle(hObject);
      FUN_40661d7c(param_1);
      FUN_40661ee8(param_1);
    }
  }
  FUN_40663a20(local_20);
  return;
}



/* 40662468 FUN_40662468 */

/* Boundary evidence: original MIPS .pdata 40662468..4066252b. Semantic name remains unreviewed. */

void FUN_40662468(HWND param_1)

{
  uint uVar1;
  HANDLE hObject;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  
  uVar1 = DAT_40664144;
  hObject = (HANDLE)FUN_40661a64(param_1);
  if (hObject != (HANDLE)0xffffffff) {
    hResInfo = FindResourceW(DAT_4066414c,(LPCWSTR)0x68,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_4066414c,hResInfo);
    DialogBoxIndirectParamW(DAT_4066414c,hDialogTemplate,param_1,FUN_406633ec,(LPARAM)hObject);
    CloseHandle(hObject);
    FUN_40661ee8(param_1);
  }
  FUN_40663a20(uVar1);
  return;
}



/* 4066252c FUN_4066252c */

/* Boundary evidence: original MIPS .pdata 4066252c..4066269f. Semantic name remains unreviewed. */

void FUN_4066252c(HWND param_1)

{
  HANDLE hObject;
  int iVar1;
  HCURSOR pHVar2;
  DWORD DVar3;
  WCHAR aWStack_430 [260];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_40664144;
  hObject = (HANDLE)FUN_4066198c(param_1);
  if (hObject != (HANDLE)0xffffffff) {
    LoadStringW(DAT_4066414c,0x177b,aWStack_430,0x104);
    LoadStringW(DAT_4066414c,0x177a,aWStack_228,0x104);
    iVar1 = MessageBoxW(param_1,aWStack_228,aWStack_430,4);
    if (iVar1 == 6) {
      pHVar2 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
      pHVar2 = SetCursor(pHVar2);
      iVar1 = FormatStore(hObject);
      SetCursor(pHVar2);
      if (iVar1 == 0) {
        DVar3 = GetLastError();
        FUN_40661444(param_1,0x1776,DVar3);
      }
      else {
        LoadStringW(DAT_4066414c,0x1781,aWStack_430,0x104);
        LoadStringW(DAT_4066414c,0x1780,aWStack_228,0x104);
        MessageBoxW(param_1,aWStack_228,aWStack_430,0);
      }
    }
    CloseHandle(hObject);
    FUN_40661d7c(param_1);
    FUN_40661ee8(param_1);
  }
  FUN_40663a20(local_20);
  return;
}



/* 406626a0 FUN_406626a0 */

/* Boundary evidence: original MIPS .pdata 406626a0..40662767. Semantic name remains unreviewed. */

void FUN_406626a0(HWND param_1)

{
  HANDLE hObject;
  HCURSOR pHVar1;
  int iVar2;
  DWORD DVar3;
  
  hObject = (HANDLE)FUN_4066198c(param_1);
  if (hObject != (HANDLE)0xffffffff) {
    pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar1 = SetCursor(pHVar1);
    iVar2 = DismountStore(hObject);
    SetCursor(pHVar1);
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      FUN_40661444(param_1,0x1777,DVar3);
    }
    CloseHandle(hObject);
    FUN_40661d7c(param_1);
    FUN_40661ee8(param_1);
  }
  return;
}



/* 40662768 FUN_40662768 */

/* Boundary evidence: original MIPS .pdata 40662768..40662927. Semantic name remains unreviewed. */

void FUN_40662768(HWND param_1)

{
  undefined4 uVar1;
  DWORD DVar2;
  int iVar3;
  HANDLE local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined1 auStack_124 [4];
  undefined1 auStack_120 [8];
  undefined4 local_118;
  undefined1 auStack_114 [12];
  undefined1 local_108;
  undefined1 auStack_107 [231];
  undefined4 local_20;
  
  local_20 = DAT_40664144;
  memset(&local_134,0,0x10);
  local_108 = 0;
  memset(auStack_107,0,0xe7);
  local_118 = 0;
  memset(auStack_114,0,0xc);
  local_140 = (HANDLE)0x0;
  memset(&local_13c,0,4);
  local_138 = 0x14;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0xe8;
  local_128 = 1;
  local_140 = (HANDLE)CreateMsgQueue(0,&local_138);
  local_13c = DAT_40664154;
  uVar1 = RequestDeviceNotifications(&local_118,local_140,1);
  DVar2 = WaitForMultipleObjects(2,&local_140,0,0xffffffff);
  while (DVar2 == 0) {
    iVar3 = ReadMsgQueue(local_140,&local_108,0xe8,auStack_120,0xffffffff,auStack_124);
    if ((iVar3 != 0) && (iVar3 = memcmp(&local_108,&DAT_40661088,0x10), iVar3 == 0)) {
      FUN_40661b84(param_1);
      FUN_40661d7c(param_1);
      FUN_40661ee8(param_1);
    }
    DVar2 = WaitForMultipleObjects(2,&local_140,0,0xffffffff);
  }
  StopDeviceNotifications(uVar1);
  CloseHandle(local_140);
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 40662958 FUN_40662958 */

/* Boundary evidence: original MIPS .pdata 40662958..406629eb. Semantic name remains unreviewed. */

void FUN_40662958(HWND param_1)

{
  DAT_40664154 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  DAT_40664158 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40662768,param_1,0,(LPDWORD)0x0);
  FUN_40661550(param_1);
  FUN_40661b84(param_1);
  FUN_40661d7c(param_1);
  FUN_40661ee8(param_1);
  return;
}



/* 406629ec FUN_406629ec */

/* Boundary evidence: original MIPS .pdata 406629ec..40662bbf. Semantic name remains unreviewed. */

undefined4 FUN_406629ec(HWND param_1,int param_2,short param_3,int param_4)

{
  INT_PTR nResult;
  int iVar1;
  
  if ((param_2 == 2) || (param_2 == 0x10)) {
    FUN_406620a8(param_1);
  }
  else {
    if (param_2 == 0x4e) {
      iVar1 = *(int *)(param_4 + 8);
      if (iVar1 == -0xcd) {
        CreateProcessW(L"peghelp",L"file:ctpnl.htm#storage_manager",(LPSECURITY_ATTRIBUTES)0x0,
                       (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,
                       (LPPROCESS_INFORMATION)0x0);
        return 1;
      }
      if (iVar1 == -0xcb) {
        nResult = 0;
      }
      else {
        if (iVar1 != -0xca) {
          return 1;
        }
        nResult = 1;
      }
      EndDialog(param_1,nResult);
      return 1;
    }
    if (param_2 == 0x110) {
      FUN_40662958(param_1);
    }
    else {
      if (param_2 != 0x111) {
        return 0;
      }
      if (param_3 == 0x3e9) {
        FUN_40661b84(param_1);
        FUN_40661d7c(param_1);
        FUN_40661ee8(param_1);
      }
      else if (param_3 == 0x3ec) {
        FUN_40662128(param_1);
      }
      else if (param_3 == 0x3ed) {
        FUN_406622d4(param_1);
      }
      else if (param_3 == 0x3ee) {
        FUN_40662468(param_1);
      }
      else if (param_3 == 0x3fa) {
        FUN_4066252c(param_1);
      }
      else if (param_3 == 0x3fb) {
        FUN_406626a0(param_1);
      }
    }
  }
  return 1;
}



/* 40662bc0 FUN_40662bc0 */

/* Boundary evidence: original MIPS .pdata 40662bc0..40662c2b. Semantic name remains unreviewed. */

long FUN_40662bc0(HWND param_1)

{
  long lVar1;
  WCHAR local_218;
  undefined1 auStack_216 [518];
  uint local_10;
  
  local_10 = DAT_40664144;
  local_218 = L'\0';
  memset(auStack_216,0,0x206);
  GetDlgItemTextW(param_1,0x7d3,&local_218,0x104);
  lVar1 = _wtol(&local_218);
  FUN_40663a20(local_10);
  return lVar1;
}



/* 40662c2c FUN_40662c2c */

/* Boundary evidence: original MIPS .pdata 40662c2c..40662e17. Semantic name remains unreviewed. */

undefined4 FUN_40662c2c(HWND param_1,int param_2,short param_3,int param_4)

{
  LRESULT LVar1;
  HWND pHVar2;
  long lVar3;
  long *plVar4;
  
  if (param_2 == 0x10) {
    EndDialog(param_1,0);
  }
  else {
    if (param_2 == 0x53) {
      CreateProcessW(L"peghelp",L"file:ctpnl.htm#create_partition",(LPSECURITY_ATTRIBUTES)0x0,
                     (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,
                     (LPPROCESS_INFORMATION)0x0);
      return 1;
    }
    if (param_2 == 0x110) {
      FUN_40661550(param_1);
      DAT_4066415c = (long *)param_4;
      if (param_4 == 0) {
        EndDialog(param_1,0);
      }
      pHVar2 = GetDlgItem(param_1,0x7d3);
      EnableWindow(pHVar2,0);
      SendDlgItemMessageW(param_1,0x7d5,0xf1,1,0);
      return 1;
    }
    if (param_2 == 0x111) {
      if (param_3 == 1) {
        if (DAT_4066415c != (long *)0x0) {
          LVar1 = SendDlgItemMessageW(param_1,0x7d5,0xf0,0,0);
          plVar4 = DAT_4066415c;
          if (LVar1 == 0) {
            lVar3 = FUN_40662bc0(param_1);
            plVar4 = DAT_4066415c;
            *DAT_4066415c = lVar3;
          }
          GetDlgItemTextW(param_1,0x7d4,(LPWSTR)(plVar4 + 1),0x104);
        }
        EndDialog(param_1,1);
        return 1;
      }
      if (param_3 == 0x7d5) {
        LVar1 = SendDlgItemMessageW(param_1,0x7d5,0xf0,0,0);
        if (LVar1 == 0) {
          pHVar2 = GetDlgItem(param_1,0x7d3);
        }
        else {
          pHVar2 = GetDlgItem(param_1,0x7d3);
        }
        EnableWindow(pHVar2,(uint)(LVar1 == 0));
        return 1;
      }
    }
  }
  return 0;
}



/* 40662e18 FUN_40662e18 */

/* Boundary evidence: original MIPS .pdata 40662e18..40662efb. Semantic name remains unreviewed. */

void FUN_40662e18(HWND param_1,int param_2,int param_3)

{
  HCURSOR pHVar1;
  int iVar2;
  DWORD DVar3;
  UINT UVar4;
  
  if (param_2 != -1) {
    if (param_3 == 0) {
      pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
      pHVar1 = SetCursor(pHVar1);
      iVar2 = DismountPartition(param_2);
      SetCursor(pHVar1);
      if (iVar2 != 0) {
        return;
      }
      DVar3 = GetLastError();
      UVar4 = 0x1774;
    }
    else {
      pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
      pHVar1 = SetCursor(pHVar1);
      iVar2 = MountPartition(param_2);
      SetCursor(pHVar1);
      if (iVar2 != 0) {
        return;
      }
      DVar3 = GetLastError();
      UVar4 = 0x1773;
    }
    FUN_40661444(param_1,UVar4,DVar3);
  }
  return;
}



/* 40662efc FUN_40662efc */

/* Boundary evidence: original MIPS .pdata 40662efc..40662fb7. Semantic name remains unreviewed. */

void FUN_40662efc(undefined4 param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_140;
  undefined1 auStack_13c [292];
  uint local_18;
  
  local_18 = DAT_40664144;
  memset(auStack_13c,0,0x124);
  local_140 = 0x128;
  if ((param_2 != -1) && (iVar1 = GetPartitionInfo(param_2,&local_140), iVar1 != 0)) {
    pcVar2 = (code *)GetProcAddressW(DAT_40664160,L"FormatVolumeUI");
    if (pcVar2 == (code *)0x0) {
      NKDbgPrintfW(L"GetProcAddress failed \r\n");
    }
    else {
      (*pcVar2)(param_2,param_1);
    }
  }
  FUN_40663a20(local_18);
  return;
}



/* 40662fb8 FUN_40662fb8 */

/* Boundary evidence: original MIPS .pdata 40662fb8..40663073. Semantic name remains unreviewed. */

void FUN_40662fb8(undefined4 param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_140;
  undefined1 auStack_13c [292];
  uint local_18;
  
  local_18 = DAT_40664144;
  memset(auStack_13c,0,0x124);
  local_140 = 0x128;
  if ((param_2 != -1) && (iVar1 = GetPartitionInfo(param_2,&local_140), iVar1 != 0)) {
    pcVar2 = (code *)GetProcAddressW(DAT_40664160,L"ScanVolumeUI");
    if (pcVar2 == (code *)0x0) {
      NKDbgPrintfW(L"GetProcAddress failed \r\n");
    }
    else {
      (*pcVar2)(param_2,param_1);
    }
  }
  FUN_40663a20(local_18);
  return;
}



/* 40663074 FUN_40663074 */

/* Boundary evidence: original MIPS .pdata 40663074..4066312f. Semantic name remains unreviewed. */

void FUN_40663074(undefined4 param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_140;
  undefined1 auStack_13c [292];
  uint local_18;
  
  local_18 = DAT_40664144;
  memset(auStack_13c,0,0x124);
  local_140 = 0x128;
  if ((param_2 != -1) && (iVar1 = GetPartitionInfo(param_2,&local_140), iVar1 != 0)) {
    pcVar2 = (code *)GetProcAddressW(DAT_40664160,L"DefragVolumeUI");
    if (pcVar2 == (code *)0x0) {
      NKDbgPrintfW(L"GetProcAddress failed \r\n");
    }
    else {
      (*pcVar2)(param_2,param_1);
    }
  }
  FUN_40663a20(local_18);
  return;
}



/* 40663130 FUN_40663130 */

/* Boundary evidence: original MIPS .pdata 40663130..4066335f. Semantic name remains unreviewed. */

void FUN_40663130(HWND param_1,undefined4 param_2)

{
  HWND pHVar1;
  BOOL bEnable;
  uint bEnable_00;
  BOOL BVar2;
  undefined4 local_558;
  WCHAR aWStack_554 [32];
  WCHAR aWStack_514 [98];
  wchar_t *local_450;
  undefined4 local_44c;
  wchar_t *local_438;
  byte local_434;
  wchar_t local_430;
  undefined1 auStack_42e [518];
  WCHAR local_228;
  undefined1 auStack_226 [518];
  uint local_20;
  
  local_20 = DAT_40664144;
  local_430 = L'\0';
  memset(auStack_42e,0,0x206);
  local_228 = L'\0';
  memset(auStack_226,0,0x206);
  local_558 = 0x128;
  GetPartitionInfo(param_2,&local_558);
  SetDlgItemTextW(param_1,0xbbe,aWStack_554);
  SetDlgItemTextW(param_1,0xbc0,aWStack_514);
  LoadStringW(DAT_4066414c,0x1389,&local_228,0x104);
  swprintf(&local_430,(size_t)&local_228,local_450,local_44c);
  SetDlgItemTextW(param_1,0xbbf,&local_430);
  swprintf(&local_430,0x40661270,(wchar_t *)(uint)local_434);
  SetDlgItemTextW(param_1,0xbc1,&local_430);
  swprintf(&local_430,0x40661260,local_438);
  SetDlgItemTextW(param_1,0xbc2,&local_430);
  if (DAT_40664160 == 0) {
    NKDbgPrintfW(L"LoadLibrary failed \r\n");
  }
  bEnable_00 = (uint)local_438 & 0x10;
  pHVar1 = GetDlgItem(param_1,0x3f0);
  EnableWindow(pHVar1,bEnable_00);
  bEnable = 1;
  pHVar1 = GetDlgItem(param_1,0x3ef);
  EnableWindow(pHVar1,(uint)(bEnable_00 == 0));
  if ((DAT_40664160 == 0) || (BVar2 = 1, bEnable_00 != 0)) {
    BVar2 = 0;
  }
  pHVar1 = GetDlgItem(param_1,0x3f1);
  EnableWindow(pHVar1,BVar2);
  if ((DAT_40664160 == 0) || (BVar2 = 1, bEnable_00 != 0)) {
    BVar2 = 0;
  }
  pHVar1 = GetDlgItem(param_1,0x3fc);
  EnableWindow(pHVar1,BVar2);
  if ((DAT_40664160 == 0) || (bEnable_00 != 0)) {
    bEnable = 0;
  }
  pHVar1 = GetDlgItem(param_1,0x3fd);
  EnableWindow(pHVar1,bEnable);
  FUN_40663a20(local_20);
  return;
}



/* 40663360 FUN_40663360 */

/* Boundary evidence: original MIPS .pdata 40663360..406633eb. Semantic name remains unreviewed. */

HMODULE FUN_40663360(undefined4 param_1)

{
  int iVar1;
  HMODULE pHVar2;
  undefined4 local_138 [17];
  wchar_t awStack_f4 [114];
  uint local_10;
  
  local_10 = DAT_40664144;
  local_138[0] = 0x128;
  GetPartitionInfo(param_1,local_138);
  iVar1 = _wcsicmp(awStack_f4,L"FATFSD.DLL");
  if ((iVar1 == 0) || (iVar1 = _wcsicmp(awStack_f4,L"EXFAT.DLL"), iVar1 == 0)) {
    pHVar2 = LoadLibraryW(L"FATUTIL.DLL");
  }
  else {
    pHVar2 = (HMODULE)0x0;
  }
  FUN_40663a20(local_10);
  return pHVar2;
}



/* 406633ec FUN_406633ec */

/* Boundary evidence: original MIPS .pdata 406633ec..406635e7. Semantic name remains unreviewed. */

undefined4 FUN_406633ec(HWND param_1,int param_2,short param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 == 2) || (param_2 == 0x10)) {
    if (DAT_40664160 != (HMODULE)0x0) {
      FreeLibrary(DAT_40664160);
    }
LAB_406635c0:
    EndDialog(param_1,1);
    return 1;
  }
  if (param_2 == 0x53) {
    CreateProcessW(L"peghelp",L"file:ctpnl.htm#advanced_partition",(LPSECURITY_ATTRIBUTES)0x0,
                   (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,
                   (LPPROCESS_INFORMATION)0x0);
    return 1;
  }
  if (param_2 == 0x110) {
    FUN_40661550(param_1);
    if (param_4 == 0) {
      EndDialog(param_1,0);
      return 1;
    }
    DAT_40664140 = param_4;
    DAT_40664160 = FUN_40663360(param_4);
    FUN_40663130(param_1,DAT_40664140);
    return 1;
  }
  if (param_2 != 0x111) {
    return 0;
  }
  if (param_3 == 1) goto LAB_406635c0;
  if (param_3 == 0x3ef) {
    iVar1 = 1;
  }
  else {
    if (param_3 != 0x3f0) {
      if (param_3 == 0x3f1) {
        FUN_40662efc(param_1,DAT_40664140);
      }
      else if (param_3 == 0x3fc) {
        FUN_40662fb8(param_1,DAT_40664140);
      }
      else {
        if (param_3 != 0x3fd) {
          return 0;
        }
        FUN_40663074(param_1,DAT_40664140);
      }
      goto LAB_406634fc;
    }
    iVar1 = 0;
  }
  FUN_40662e18(param_1,DAT_40664140,iVar1);
LAB_406634fc:
  FUN_40663130(param_1,DAT_40664140);
  return 1;
}



/* 406638b8 entry */

/* Boundary evidence: original MIPS .pdata 406638b8..4066392b. Semantic name remains unreviewed. */

undefined4 entry(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_4066392c();
    FUN_40663c00();
  }
  uVar1 = FUN_40661754(param_1,param_2);
  if (param_2 == 0) {
    FUN_40663b88();
  }
  return uVar1;
}



/* 4066392c FUN_4066392c */

/* Boundary evidence: original MIPS .pdata 4066392c..4066399f. Semantic name remains unreviewed. */

void FUN_4066392c(void)

{
  uint uVar1;
  
  if ((DAT_40664144 == 0) || (DAT_40664144 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40664144 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40664144 == 0) {
      DAT_40664144 = 0xb064;
    }
  }
  DAT_40664148 = ~DAT_40664144;
  return;
}



/* 406639a0 FUN_406639a0 */

/* Boundary evidence: original MIPS .pdata 406639a0..406639f3. Semantic name remains unreviewed. */

void FUN_406639a0(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40663a20(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 406639f4 FUN_406639f4 */

/* Boundary evidence: original MIPS .pdata 406639f4..40663a1f. Semantic name remains unreviewed. */

undefined4 FUN_406639f4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_406639a0(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40663a20 FUN_40663a20 */

/* Boundary evidence: original MIPS .pdata 40663a20..40663a67. Semantic name remains unreviewed. */

void FUN_40663a20(uint param_1)

{
  if ((param_1 == DAT_40664144) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40663a68 FUN_40663a68 */

/* Boundary evidence: original MIPS .pdata 40663a68..40663b87. Semantic name remains unreviewed. */

void FUN_40663a68(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_40664164 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_4066416c;
    if (DAT_4066416c != (undefined4 *)0x0) {
      while (DAT_40664168 = DAT_40664168 + -1, _Memory <= DAT_40664168) {
        if ((code *)*DAT_40664168 != (code *)0x0) {
          (*(code *)*DAT_40664168)();
          _Memory = DAT_4066416c;
        }
      }
      free(_Memory);
      DAT_40664168 = (undefined4 *)0x0;
      DAT_4066416c = (undefined4 *)0x0;
    }
    FUN_40663bac((undefined4 *)&DAT_40661010,(undefined4 *)&DAT_40661014);
  }
  FUN_40663bac((undefined4 *)&DAT_40661018,(undefined4 *)&DAT_4066101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_40664170,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40663b88 FUN_40663b88 */

/* Boundary evidence: original MIPS .pdata 40663b88..40663bab. Semantic name remains unreviewed. */

void FUN_40663b88(void)

{
  FUN_40663a68(0,0,1);
  return;
}



/* 40663bac FUN_40663bac */

/* Boundary evidence: original MIPS .pdata 40663bac..40663bff. Semantic name remains unreviewed. */

void FUN_40663bac(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40663c00 FUN_40663c00 */

/* Boundary evidence: original MIPS .pdata 40663c00..40663c3b. Semantic name remains unreviewed. */

void FUN_40663c00(void)

{
  FUN_40663bac((undefined4 *)&DAT_40661008,(undefined4 *)&DAT_4066100c);
  FUN_40663bac((undefined4 *)&DAT_40661000,(undefined4 *)&DAT_40661004);
  return;
}


