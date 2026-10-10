/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 000111b0 FUN_000111b0 */

/* Boundary evidence: original MIPS .pdata 000111b0..00011243. Semantic name remains unreviewed. */

void FUN_000111b0(HINSTANCE param_1,int param_2,undefined4 param_3,int param_4)

{
  UINT UVar1;
  
  FUN_000114c0();
  UVar1 = FUN_000130b4(param_1,param_2,param_3,param_4);
  FUN_00011400(UVar1);
  FUN_00011420(UVar1);
  return;
}



/* 00011244 FUN_00011244 */

/* Boundary evidence: original MIPS .pdata 00011244..00011283. Semantic name remains unreviewed. */

void FUN_00011244(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00011284 entry */

/* Boundary evidence: original MIPS .pdata 00011284..000112df. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_000114fc();
  FUN_000111b0(param_1,param_2,param_3,param_4);
  return;
}



/* 000112e0 FUN_000112e0 */

/* Boundary evidence: original MIPS .pdata 000112e0..000113ff. Semantic name remains unreviewed. */

void FUN_000112e0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0001414c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00014170;
    if (DAT_00014170 != (undefined4 *)0x0) {
      while (DAT_0001416c = DAT_0001416c + -1, _Memory <= DAT_0001416c) {
        if ((code *)*DAT_0001416c != (code *)0x0) {
          (*(code *)*DAT_0001416c)();
          _Memory = DAT_00014170;
        }
      }
      free(_Memory);
      DAT_0001416c = (undefined4 *)0x0;
      DAT_00014170 = (undefined4 *)0x0;
    }
    FUN_0001146c((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_0001146c((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_00014174,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011400 FUN_00011400 */

/* Boundary evidence: original MIPS .pdata 00011400..0001141f. Semantic name remains unreviewed. */

void FUN_00011400(UINT param_1)

{
  FUN_000112e0(param_1,0,0);
  return;
}



/* 00011420 FUN_00011420 */

/* Boundary evidence: original MIPS .pdata 00011420..0001146b. Semantic name remains unreviewed. */

void FUN_00011420(UINT param_1)

{
  DAT_0001414c = 0;
  FUN_0001146c((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 0001146c FUN_0001146c */

/* Boundary evidence: original MIPS .pdata 0001146c..000114bf. Semantic name remains unreviewed. */

void FUN_0001146c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 000114c0 FUN_000114c0 */

/* Boundary evidence: original MIPS .pdata 000114c0..000114fb. Semantic name remains unreviewed. */

void FUN_000114c0(void)

{
  FUN_0001146c((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_0001146c((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 000114fc FUN_000114fc */

/* Boundary evidence: original MIPS .pdata 000114fc..0001156f. Semantic name remains unreviewed. */

void FUN_000114fc(void)

{
  uint uVar1;
  
  if ((DAT_00014144 == 0) || (DAT_00014144 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00014144 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00014144 == 0) {
      DAT_00014144 = 0xb064;
    }
  }
  DAT_00014148 = ~DAT_00014144;
  return;
}



/* 000115e0 FUN_000115e0 */

/* Boundary evidence: original MIPS .pdata 000115e0..00011643. Semantic name remains unreviewed. */

LRESULT FUN_000115e0(HWND param_1,WPARAM param_2,uint param_3)

{
  LRESULT LVar1;
  BOOL BVar2;
  
  LVar1 = SendMessageW(param_1,0x100c,param_2,param_3 & 0xffff);
  if ((LVar1 == 0) && (BVar2 = IsWindow(param_1), BVar2 == 0)) {
    LVar1 = -1;
  }
  return LVar1;
}



/* 00011644 FUN_00011644 */

/* Boundary evidence: original MIPS .pdata 00011644..0001173b. Semantic name remains unreviewed. */

bool FUN_00011644(HINSTANCE param_1,int param_2)

{
  LPCWSTR lpWindowName;
  HWND hWnd;
  HANDLE lParam;
  
  DAT_00014160 = param_1;
  lpWindowName = (LPCWSTR)LoadStringW(param_1,0x2904,(LPWSTR)0x0,0);
  hWnd = CreateWindowExW(0,L"CONTROLEXE_MAIN",lpWindowName,0x10800000,-0x80000000,-0x80000000,
                         -0x80000000,-0x80000000,(HWND)0x0,(HMENU)0x0,param_1,(LPVOID)0x0);
  lParam = LoadImageW(param_1,(LPCWSTR)0x32,1,0x10,0x10,0);
  SendMessageW(hWnd,0x80,0,(LPARAM)lParam);
  if (hWnd != (HWND)0x0) {
    ShowWindow(hWnd,param_2);
    UpdateWindow(hWnd);
  }
  return hWnd != (HWND)0x0;
}



/* 0001173c FUN_0001173c */

/* Boundary evidence: original MIPS .pdata 0001173c..0001180b. Semantic name remains unreviewed. */

undefined4 FUN_0001173c(int param_1)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  undefined2 local_10;
  undefined1 uStack_e;
  undefined1 uStack_d;
  HKEY local_c;
  
  uVar2 = 0;
  uStack_d = (undefined1)*(undefined4 *)(param_1 + 0x14);
  _local_10 = CONCAT12((char)*(undefined4 *)(param_1 + 0x10),
                       CONCAT11((char)*(undefined4 *)(param_1 + 0x18),
                                (char)*(undefined4 *)(param_1 + 0xc) + -3));
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"ControlPanel",0,0xf003f,&local_c);
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_c,L"PanelState",0,4,(BYTE *)&local_10,4);
    if (LVar1 == 0) {
      uVar2 = 1;
    }
  }
  RegCloseKey(local_c);
  return uVar2;
}



/* 0001180c FUN_0001180c */

/* Boundary evidence: original MIPS .pdata 0001180c..000118ef. Semantic name remains unreviewed. */

undefined4 FUN_0001180c(int param_1)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  uint local_20;
  HKEY local_1c;
  DWORD local_18 [2];
  
  local_18[0] = 4;
  uVar2 = 0;
  local_20 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"ControlPanel",0,0xf003f,&local_1c);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_1c,L"PanelState",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_20,
                             local_18);
    if (LVar1 == 0) {
      uVar2 = 1;
      *(uint *)(param_1 + 0xc) = (local_20 & 0xff) + 3;
      *(uint *)(param_1 + 0x14) = local_20 >> 0x18;
      *(uint *)(param_1 + 0x10) = local_20 >> 0x10 & 0xff;
      *(uint *)(param_1 + 0x18) = local_20 >> 8 & 0xff;
    }
  }
  RegCloseKey(local_1c);
  return uVar2;
}



/* 000118f0 FUN_000118f0 */

/* Boundary evidence: original MIPS .pdata 000118f0..000119a7. Semantic name remains unreviewed. */

void FUN_000118f0(HWND param_1,HWND param_2)

{
  LRESULT LVar1;
  HMENU hMenu;
  HMENU pHVar2;
  DWORD DVar3;
  
  LVar1 = FUN_000115e0(param_2,0xffffffff,3);
  if (LVar1 != -1) {
    hMenu = LoadMenuW(DAT_00014160,(LPCWSTR)0x458);
  }
  else {
    hMenu = LoadMenuW(DAT_00014160,(LPCWSTR)0x457);
  }
  pHVar2 = GetSubMenu(hMenu,(uint)(LVar1 == -1));
  DVar3 = GetMessagePos();
  TrackPopupMenuEx(pHVar2,0,DVar3 & 0xffff,DVar3 >> 0x10,param_1,(LPTPMPARAMS)0x0);
  DestroyMenu(hMenu);
  return;
}



/* 000119a8 FUN_000119a8 */

/* Boundary evidence: original MIPS .pdata 000119a8..00011ba3. Semantic name remains unreviewed. */

void FUN_000119a8(HWND param_1,HWND param_2)

{
  WCHAR WVar1;
  LRESULT LVar2;
  int iVar3;
  LPCWSTR pWVar4;
  int iVar5;
  DWORD DVar6;
  LPCWSTR lpText;
  WCHAR *pWVar7;
  UINT uID;
  undefined4 local_470;
  int local_46c;
  undefined4 local_468;
  uint local_464;
  undefined4 local_460;
  int local_450;
  WCHAR local_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00014144;
  LVar2 = SendMessageW(param_2,0x1004,0,0);
  local_468 = 0;
  local_470 = 0xc;
  local_460 = 0xffff;
  local_46c = 0;
  if (0 < LVar2) {
    do {
      SendMessageW(param_2,0x104b,0,(LPARAM)&local_470);
      iVar5 = local_450;
      if ((local_464 & 2) != 0) {
        iVar3 = SHGetSpecialFolderPath(0,awStack_238,0x10,0);
        if (iVar3 != 0) {
          pWVar4 = (LPCWSTR)LoadStringW(DAT_00014160,0x2908,(LPWSTR)0x0,0);
          wsprintfW(local_440,pWVar4,iVar5);
          pWVar7 = local_440;
          WVar1 = local_440[0];
          while (WVar1 != L'\0') {
            if (*pWVar7 == L'/') {
              *pWVar7 = L'-';
            }
            pWVar7 = pWVar7 + 1;
            WVar1 = *pWVar7;
          }
          wcscat(awStack_238,local_440);
          wsprintfW(local_440,L"ctlpnl.exe %s,%d",iVar5 + 0x140,(uint)*(byte *)(iVar5 + 0x240));
          iVar5 = SHCreateShortcut(awStack_238,local_440);
          if (iVar5 != 0) goto LAB_00011b58;
        }
        uID = 0x290a;
        DVar6 = GetLastError();
        if (DVar6 == 0x50) {
          uID = 0x2909;
        }
        pWVar4 = (LPCWSTR)LoadStringW(DAT_00014160,0x2904,(LPWSTR)0x0,0);
        lpText = (LPCWSTR)LoadStringW(DAT_00014160,uID,(LPWSTR)0x0,0);
        MessageBoxW(param_1,lpText,pWVar4,0x30);
      }
LAB_00011b58:
      local_46c = local_46c + 1;
    } while (local_46c < LVar2);
  }
  FUN_000131f8(local_30);
  return;
}



/* 00011ba4 FUN_00011ba4 */

/* Boundary evidence: original MIPS .pdata 00011ba4..00011ccf. Semantic name remains unreviewed. */

void FUN_00011ba4(HWND param_1)

{
  int iVar1;
  
  iVar1 = 2;
  do {
    SendMessageW(param_1,0x101c,0,0);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  SendMessageW(param_1,0x1009,0,0);
  if (DAT_00014150 != 0) {
    ImageList_Destroy((HIMAGELIST)DAT_00014150);
  }
  if (DAT_00014158 != 0) {
    ImageList_Destroy((HIMAGELIST)DAT_00014158);
  }
  DAT_00014150 = 0;
  DAT_00014158 = 0;
  if (DAT_00014154 != 0) {
    SendMessageW(param_1,0x1003,0,DAT_00014154);
  }
  if (DAT_00014168 != 0) {
    SendMessageW(param_1,0x1003,1,DAT_00014168);
  }
  DAT_00014168 = 0;
  DAT_00014154 = 0;
  DAT_00014164 = 0;
  if (DAT_0001415c != (HLOCAL)0x0) {
    LocalFree(DAT_0001415c);
    DAT_0001415c = (HLOCAL)0x0;
  }
  return;
}



/* 00011cd0 FUN_00011cd0 */

/* Boundary evidence: original MIPS .pdata 00011cd0..00011d7f. Semantic name remains unreviewed. */

undefined4 FUN_00011cd0(void)

{
  longlong lVar1;
  HLOCAL pvVar2;
  SIZE_T SVar3;
  
  if (DAT_0001415c == (HLOCAL)0x0) {
    pvVar2 = LocalAlloc(0x40,0x2420);
    DAT_0001415c = pvVar2;
  }
  else {
    SVar3 = LocalSize(DAT_0001415c);
    if ((DAT_00014164 + 1) * 0x242 <= SVar3) {
      return 1;
    }
    if (DAT_00014164 + 4 < DAT_00014164) {
      return 0;
    }
    lVar1 = (ulonglong)(DAT_00014164 + 4) * 0x242;
    if ((int)((ulonglong)lVar1 >> 0x20) != 0) {
      return 0;
    }
    pvVar2 = LocalReAlloc(DAT_0001415c,(SIZE_T)lVar1,0x42);
  }
  if (pvVar2 != (HLOCAL)0x0) {
    DAT_0001415c = pvVar2;
    return 1;
  }
  return 0;
}



/* 00011d80 FUN_00011d80 */

/* Boundary evidence: original MIPS .pdata 00011d80..00011de3. Semantic name remains unreviewed. */

void FUN_00011d80(HMENU param_1,undefined4 param_2,int param_3)

{
  BOOL BVar1;
  
  BVar1 = CheckMenuRadioItem(param_1,3,5,*(UINT *)(param_3 + 0xc),0);
  if (BVar1 == 0) {
    CheckMenuRadioItem(param_1,6,7,*(UINT *)(param_3 + 0x10),0);
  }
  return;
}



/* 00011de4 FUN_00011de4 */

/* Boundary evidence: original MIPS .pdata 00011de4..00011ea7. Semantic name remains unreviewed. */

undefined4 FUN_00011de4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  SendMessageW(*(HWND *)(param_2 + 4),0xb,0,0);
  uVar1 = GetWindowLongW(*(HWND *)(param_2 + 4),-0x10);
  uVar2 = 1;
  if (param_1 != 3) {
    if (param_1 == 4) {
      uVar2 = 2;
      goto LAB_00011e44;
    }
    if (param_1 == 5) goto LAB_00011e44;
  }
  uVar2 = 0;
LAB_00011e44:
  SetWindowLongW(*(HWND *)(param_2 + 4),-0x10,uVar1 & 0xfffffffc | uVar2);
  SendMessageW(*(HWND *)(param_2 + 4),0x1016,0,0);
  SendMessageW(*(HWND *)(param_2 + 4),0xb,1,0);
  *(int *)(param_2 + 0xc) = param_1;
  return 1;
}



/* 00011ea8 FUN_00011ea8 */

/* Boundary evidence: original MIPS .pdata 00011ea8..00011fab. Semantic name remains unreviewed. */

void FUN_00011ea8(undefined4 *param_1)

{
  int iVar1;
  HWND hWndTo;
  tagPOINT local_20;
  int local_18;
  int local_14;
  
  SystemParametersInfoW(0x30,0,&local_20,0);
  SetWindowPos((HWND)*param_1,(HWND)0x0,local_20.x,local_20.y,local_18 - local_20.x,
               local_14 - local_20.y,0x14);
  SendMessageW((HWND)param_1[2],0x421,0,0);
  CommandBar_AlignAdornments(param_1[2]);
  iVar1 = CommandBar_Height(param_1[2]);
  local_20.y = iVar1 + local_20.y;
  hWndTo = GetParent((HWND)param_1[1]);
  MapWindowPoints((HWND)0x0,hWndTo,&local_20,2);
  SetWindowPos((HWND)param_1[1],(HWND)0x0,local_20.x + 1,local_20.y + 1,local_18 - local_20.x,
               local_14 - local_20.y,0x14);
  return;
}



/* 00011fac FUN_00011fac */

/* Boundary evidence: original MIPS .pdata 00011fac..00012083. Semantic name remains unreviewed. */

int FUN_00011fac(LPCWSTR param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  LPCWSTR lpString1;
  LPCWSTR lpString2;
  
  iVar1 = 1;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (LPCWSTR)0x0)) {
    lpString1 = param_1;
    lpString2 = param_2;
    if (*(int *)(param_3 + 0x14) != 0) {
      if (*(int *)(param_3 + 0x14) != 1) {
        return 0;
      }
      lpString1 = param_1 + 0x20;
      lpString2 = param_2 + 0x20;
    }
    iVar1 = lstrcmpiW(lpString1,lpString2);
    if (iVar1 == 0) {
      if (*(int *)(param_3 + 0x14) == 0) {
        iVar1 = lstrcmpiW(param_1,param_2);
      }
      else {
        iVar1 = lstrcmpiW(param_1 + 0x20,param_2 + 0x20);
      }
    }
  }
  return *(int *)(param_3 + 0x18) * iVar1;
}



/* 00012084 FUN_00012084 */

/* Boundary evidence: original MIPS .pdata 00012084..00012157. Semantic name remains unreviewed. */

undefined4 FUN_00012084(uint param_1,int param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  HRESULT HVar3;
  undefined4 uVar4;
  undefined1 auStack_260 [8];
  undefined1 auStack_258 [8];
  wchar_t *local_250;
  undefined1 auStack_24c [4];
  undefined1 auStack_248 [4];
  undefined1 auStack_244 [36];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_00014144;
  uVar4 = 0;
  HVar3 = StringCbPrintfW(awStack_220,0x208,L"%s,%d",param_2 + 0x140,
                          (uint)*(byte *)(param_2 + 0x240));
  if (-1 < HVar3) {
    memset(auStack_260,0,0x3c);
    local_250 = L"CTLPNL.EXE";
    puVar1 = auStack_260 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x3cU >> (3 - uVar2) * 8;
    puVar1 = auStack_258 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_1 >> (3 - uVar2) * 8;
    puVar1 = auStack_24c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)awStack_220 >> (3 - uVar2) * 8;
    puVar1 = auStack_248 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    puVar1 = auStack_244 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 1U >> (3 - uVar2) * 8;
    auStack_260._0_4_ = 0x3c;
    auStack_248 = (undefined1  [4])0x0;
    auStack_244._0_4_ = 1;
    auStack_258._0_4_ = param_1;
    auStack_24c = (undefined1  [4])awStack_220;
    uVar4 = ShellExecuteEx(auStack_260);
  }
  FUN_000131f8(local_18);
  return uVar4;
}



/* 00012158 FUN_00012158 */

/* Boundary evidence: original MIPS .pdata 00012158..000124fb. Semantic name remains unreviewed. */

undefined4 FUN_00012158(HWND param_1,LPCWSTR param_2,HIMAGELIST param_3,HIMAGELIST param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  HICON hicon;
  uint uVar3;
  uint uVar4;
  HMODULE hInst;
  code *pcVar5;
  int iVar6;
  HICON hicon_00;
  DWORD DVar7;
  LPCWSTR lpCaption;
  LPCWSTR lpText;
  undefined4 uVar8;
  int iVar9;
  undefined1 local_200 [4];
  undefined1 auStack_1fc [8];
  uint local_1f4;
  HICON local_1f0;
  wchar_t awStack_1ec [32];
  wchar_t awStack_1ac [192];
  uint local_2c;
  
  local_2c = DAT_00014144;
  uVar3 = GetSystemMetrics(0x31);
  uVar4 = GetSystemMetrics(0x32);
  hInst = LoadLibraryW(param_2);
  if ((hInst == (HMODULE)0x0) ||
     (pcVar5 = (code *)GetProcAddressW(hInst,L"CPlApplet"), pcVar5 == (code *)0x0)) {
LAB_00012450:
    DVar7 = GetLastError();
    if ((DVar7 == 8) || (DVar7 == 0xe)) {
      lpCaption = (LPCWSTR)LoadStringW(DAT_00014160,0x2904,(LPWSTR)0x0,0);
      lpText = (LPCWSTR)LoadStringW(DAT_00014160,0x2907,(LPWSTR)0x0,0);
      MessageBoxW(param_1,lpText,lpCaption,0x30);
    }
    FUN_000131f8(local_2c);
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
    (*pcVar5)(0,1,0,0);
    iVar9 = 0;
    iVar6 = (*pcVar5)(0,2,0,0);
    if (0 < iVar6) {
      do {
        puVar1 = local_200 + 3;
        uVar2 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar2) =
             *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
        puVar1 = auStack_1fc + 3;
        uVar2 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar2) =
             *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
        local_200 = (undefined1  [4])0x0;
        auStack_1fc._0_4_ = 0;
        iVar6 = (*pcVar5)(0,8,iVar9,local_200);
        hicon = local_1f0;
        if (iVar6 != -1) {
          if (local_200 != (undefined1  [4])0x1d4) goto LAB_00012450;
          if (((local_1f4 == 0) ||
              (hicon_00 = LoadImageW(hInst,(LPCWSTR)(local_1f4 & 0xffff),1,uVar3 & 0xffff,
                                     uVar4 & 0xffff,0), hicon_00 == (HICON)0x0)) ||
             (hicon == (HICON)0x1)) {
            hicon_00 = hicon;
          }
          if ((hicon != (HICON)0x0) && (hicon != (HICON)0x1)) {
            iVar6 = ImageList_ReplaceIcon(param_3,-1,hicon);
            if ((iVar6 == -1) || (iVar6 = ImageList_ReplaceIcon(param_4,-1,hicon_00), iVar6 == -1))
            goto LAB_00012450;
            DestroyIcon(hicon);
            DestroyIcon(hicon_00);
            iVar6 = FUN_00011cd0();
            if (iVar6 == 0) goto LAB_00012450;
            *(char *)(DAT_00014164 * 0x242 + DAT_0001415c + 0x240) = (char)iVar9;
            wcscpy((wchar_t *)(DAT_00014164 * 0x242 + DAT_0001415c),awStack_1ec);
            wcscpy((wchar_t *)(DAT_00014164 * 0x242 + DAT_0001415c + 0x40),awStack_1ac);
            wcscpy((wchar_t *)(DAT_00014164 * 0x242 + DAT_0001415c + 0x140),param_2);
            DAT_00014164 = DAT_00014164 + 1;
            (*pcVar5)(0,6,iVar9,local_1f4);
          }
        }
        iVar9 = iVar9 + 1;
        iVar6 = (*pcVar5)(0,2,0,0);
      } while (iVar9 < iVar6);
    }
    (*pcVar5)(0,7,0,0);
    FreeLibrary(hInst);
    FUN_000131f8(local_2c);
  }
  return uVar8;
}



/* 000124fc FUN_000124fc */

/* Boundary evidence: original MIPS .pdata 000124fc..0001281f. Semantic name remains unreviewed. */

undefined4
FUN_000124fc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  short sVar1;
  LRESULT LVar2;
  short extraout_var;
  short extraout_var_00;
  HWND hWnd;
  UINT Msg;
  wchar_t *_Source;
  undefined4 *wParam;
  code *lParam;
  uint uVar3;
  int iVar4;
  undefined4 local_78;
  undefined4 *local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  int local_58;
  undefined1 auStack_48 [12];
  undefined4 local_3c;
  undefined4 local_38;
  
  uVar3 = param_4[2];
  if (uVar3 < 0xffffff9c) {
    if (uVar3 == 0xffffff9b) {
      LVar2 = SendMessageW((HWND)param_1[1],0x102c,param_4[3],1);
      if (LVar2 == 0) {
        return 0;
      }
      local_74 = (undefined4 *)param_4[3];
      lParam = (code *)&local_78;
      local_70 = 0;
      Msg = 0x104b;
      local_78 = 4;
      wParam = (undefined4 *)0x0;
LAB_00012738:
      hWnd = (HWND)param_1[1];
      goto LAB_00012790;
    }
    if (uVar3 == 1) {
LAB_0001260c:
      LVar2 = SendMessageW((HWND)param_1[1],0x1004,0,0);
      local_70 = 0;
      local_78 = 0xc;
      local_68 = 0xffff;
      local_74 = (undefined4 *)0x0;
      if (LVar2 < 1) {
        return 0;
      }
      do {
        SendMessageW((HWND)param_1[1],0x104b,0,(LPARAM)&local_78);
        if ((local_6c & 2) != 0) {
          FUN_00012084(param_1[1],local_58);
          local_38 = 0xffff;
          local_3c = 1;
          SendMessageW((HWND)param_1[1],0x102b,(WPARAM)local_74,(LPARAM)auStack_48);
        }
        local_74 = (undefined4 *)((int)local_74 + 1);
      } while ((int)local_74 < LVar2);
      return 0;
    }
    if (uVar3 == 0xffffff4f) {
      _Source = (wchar_t *)param_4[0xb];
      if ((param_4[3] & 1) == 0) {
        return 0;
      }
      if ((wchar_t *)param_4[8] == (wchar_t *)0x0) {
        return 0;
      }
      if ((int)param_4[9] < 1) {
        return 0;
      }
      if (param_4[5] != 0) {
        if (param_4[5] != 1) {
          return 0;
        }
        _Source = _Source + 0x20;
      }
      wcsncpy((wchar_t *)param_4[8],_Source,param_4[9]);
      return 0;
    }
    if (uVar3 != 0xffffff65) {
      if (uVar3 != 0xffffff94) {
        return 0;
      }
      iVar4 = param_4[4];
      if (param_1[5] == iVar4) {
        param_1[6] = -param_1[6];
      }
      else {
        param_1[5] = iVar4;
        param_1[4] = iVar4 + 6;
        param_1[6] = 1;
      }
      hWnd = (HWND)*param_4;
      lParam = FUN_00011fac;
      Msg = 0x1030;
      wParam = param_1;
      goto LAB_00012790;
    }
    sVar1 = *(short *)(param_4 + 3);
    if (((sVar1 != 0x48) && (sVar1 != 0x68)) || ((param_4[4] & 0x2000) == 0)) {
      if (sVar1 != 0xd) {
        return 0;
      }
      goto LAB_0001260c;
    }
    wParam = (undefined4 *)0x0;
    Msg = 0x53;
  }
  else {
    if (uVar3 != 0xfffffffb) {
      if (uVar3 == 0xfffffffd) {
        GetKeyState(0x12);
        if (-1 < extraout_var_00) {
          local_74 = (undefined4 *)param_4[3];
          if ((int)local_74 < 0) {
            return 0;
          }
          local_70 = 0;
          local_78 = 4;
          SendMessageW((HWND)param_1[1],0x104b,0,(LPARAM)&local_78);
          FUN_00012084(param_1[1],local_58);
          lParam = (code *)auStack_48;
          Msg = 0x102b;
          local_38 = 0xffff;
          local_3c = 1;
          wParam = local_74;
          goto LAB_00012738;
        }
      }
      else {
        if (uVar3 != 0xfffffffe) {
          return 0;
        }
        GetKeyState(0x12);
        if (-1 < extraout_var) {
          return 0;
        }
      }
    }
    wParam = (undefined4 *)0xa;
    Msg = 0x111;
  }
  hWnd = (HWND)*param_1;
  lParam = (code *)0x0;
LAB_00012790:
  SendMessageW(hWnd,Msg,(WPARAM)wParam,(LPARAM)lParam);
  return 0;
}



/* 00012820 FUN_00012820 */

/* Boundary evidence: original MIPS .pdata 00012820..0001299b. Semantic name remains unreviewed. */

undefined4 FUN_00012820(HWND param_1,HWND param_2)

{
  HANDLE hFindFile;
  BOOL BVar1;
  _WIN32_FIND_DATAW _Stack_460;
  uint local_28;
  
  local_28 = DAT_00014144;
  DAT_00014150 = ImageList_Create(0x10,0x10,1,0xc,0);
  DAT_00014158 = ImageList_Create(0x20,0x20,1,0xc,0);
  hFindFile = FindFirstFileW(L"\\Windows\\*.cpl",&_Stack_460);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      wcscpy(_Stack_460.cFileName + 0x102,L"\\Windows\\");
      wcscat(_Stack_460.cFileName + 0x102,(wchar_t *)&_Stack_460.dwReserved1);
      FUN_00012158(param_1,_Stack_460.cFileName + 0x102,DAT_00014158,DAT_00014150);
      BVar1 = FindNextFileW(hFindFile,&_Stack_460);
    } while (BVar1 != 0);
    FindClose(hFindFile);
  }
  DAT_00014154 = SendMessageW(param_2,0x1003,0,(LPARAM)DAT_00014158);
  DAT_00014168 = SendMessageW(param_2,0x1003,1,(LPARAM)DAT_00014150);
  FUN_000131f8(local_28);
  return 1;
}



/* 0001299c FUN_0001299c */

/* Boundary evidence: original MIPS .pdata 0001299c..00012d0f. Semantic name remains unreviewed. */

undefined4 FUN_0001299c(HWND param_1)

{
  undefined4 *wParam;
  int iVar1;
  undefined4 uVar2;
  HWND pHVar3;
  LRESULT LVar4;
  WPARAM wParam_00;
  uint uVar5;
  int iVar6;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a8;
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  tagRECT local_90;
  undefined4 local_80;
  uint local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  uint local_64;
  int local_60;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  undefined4 local_40;
  
  wParam = LocalAlloc(0x40,0x1c);
  *wParam = param_1;
  iVar1 = FUN_0001180c((int)wParam);
  if (iVar1 == 0) {
    wParam[3] = 3;
    wParam[4] = 6;
    wParam[6] = 1;
  }
  iVar1 = wParam[3];
  if (iVar1 != 3) {
    if (iVar1 == 4) {
      uVar5 = 2;
      goto LAB_00012a34;
    }
    if (iVar1 == 5) {
      uVar5 = 1;
      goto LAB_00012a34;
    }
  }
  uVar5 = 0;
LAB_00012a34:
  SetWindowLongW(param_1,0,(LONG)wParam);
  uVar2 = CommandBar_Create(DAT_00014160,param_1,1);
  wParam[2] = uVar2;
  CommandBar_InsertMenubar(uVar2,DAT_00014160,0x457,0);
  CommandBar_AddAdornments(wParam[2],0x53,0);
  GetClientRect((HWND)*wParam,&local_90);
  iVar1 = CommandBar_Height(wParam[2]);
  local_90.top = iVar1 + local_90.top;
  pHVar3 = CreateWindowExW(0x20,L"SysListView32",L"",uVar5 | 0x50200140,local_90.left,local_90.top,
                           local_90.right - local_90.left,local_90.bottom - local_90.top,
                           (HWND)*wParam,(HMENU)0x0,DAT_00014160,(LPVOID)0x0);
  wParam[1] = pHVar3;
  FUN_00011ea8(wParam);
  DAT_00014164 = 0;
  FUN_00012820((HWND)*wParam,(HWND)wParam[1]);
  iVar1 = GetSystemMetrics(0);
  if (iVar1 == 0x1e0) {
    iVar6 = 0;
  }
  else {
    iVar6 = iVar1 + -0x1e0 >> 2;
    if (iVar1 + -0x1e0 < 0) {
      iVar6 = iVar1 + -0x1dd >> 2;
    }
  }
  local_a8 = iVar6 + 0x78;
  local_b0 = 0xf;
  local_ac = 0;
  local_9c = 0;
  local_a4 = LoadStringW(DAT_00014160,0x2905,(LPWSTR)0x0,0);
  local_a0 = 0x20;
  LVar4 = SendMessageW((HWND)wParam[1],0x1061,0,(LPARAM)&local_b0);
  if (LVar4 != -1) {
    local_a8 = iVar6 + 0x154;
    local_9c = 1;
    local_a4 = LoadStringW(DAT_00014160,0x2906,(LPWSTR)0x0,0);
    local_a0 = 0x80;
    LVar4 = SendMessageW((HWND)wParam[1],0x1061,1,(LPARAM)&local_b0);
    if (LVar4 != -1) {
      local_70 = 0xf000;
      local_68 = 0x80;
      uVar5 = 0;
      local_80 = 0xf;
      local_74 = 0;
      local_78 = 0;
      local_6c = 0xffffffff;
      if (DAT_00014164 != 0) {
        iVar1 = 0;
        do {
          local_60 = iVar1 + DAT_0001415c;
          local_7c = uVar5;
          local_64 = uVar5;
          LVar4 = SendMessageW((HWND)wParam[1],0x104d,0,(LPARAM)&local_80);
          if (LVar4 == -1) {
            return 0xffffffff;
          }
          uVar5 = uVar5 + 1;
          iVar1 = iVar1 + 0x242;
        } while (uVar5 < DAT_00014164);
      }
      SendMessageW((HWND)wParam[1],0x1030,(WPARAM)wParam,0x11fac);
      local_40 = 0xffff;
      local_44 = 1;
      wParam_00 = SendMessageW((HWND)wParam[1],0x1027,0,0);
      SendMessageW((HWND)wParam[1],0x102b,wParam_00,(LPARAM)auStack_50);
      SetFocus((HWND)wParam[1]);
      return 1;
    }
  }
  return 0;
}



/* 00012d10 FUN_00012d10 */

/* Boundary evidence: original MIPS .pdata 00012d10..0001301b. Semantic name remains unreviewed. */

LRESULT FUN_00012d10(HWND param_1,UINT param_2,HMENU param_3,undefined *param_4)

{
  HMENU hMem;
  LRESULT LVar1;
  UINT Msg;
  uint uVar2;
  undefined4 auStack_30 [2];
  undefined4 local_28;
  undefined2 local_24;
  
  hMem = (HMENU)GetWindowLongW(param_1,0);
  if (param_2 < 0x1b) {
    if (param_2 == 0x1a) {
      if ((param_3 != (HMENU)0xe0) && (param_3 != (HMENU)0x2f)) {
        return 0;
      }
      FUN_00011ea8(hMem);
      return 0;
    }
    if (param_2 == 1) {
      FUN_0001299c(param_1);
      return 0;
    }
    if (param_2 == 2) {
      PostQuitMessage(0);
      return 0;
    }
    if (param_2 == 7) {
      SetFocus((HWND)hMem[1].unused);
      return 0;
    }
    if (param_2 == 0x10) {
      FUN_0001173c((int)hMem);
      FUN_00011ba4((HWND)hMem[1].unused);
      DestroyWindow((HWND)hMem[2].unused);
      LocalFree(hMem);
      DestroyWindow(param_1);
      return 0;
    }
    if (param_2 != 0x15) goto LAB_00012f94;
    Msg = 0x15;
LAB_00012da8:
    SendMessageW((HWND)hMem[1].unused,Msg,(WPARAM)param_3,(LPARAM)param_4);
  }
  else {
    if (param_2 == 0x4e) {
      LVar1 = FUN_000124fc(hMem,0x4e,param_3,(undefined4 *)param_4);
      return LVar1;
    }
    if (param_2 == 0x53) {
      CreateProcessW(L"peghelp",L"file:ctpnl.htm#Main_Contents",(LPSECURITY_ATTRIBUTES)0x0,
                     (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,
                     (LPPROCESS_INFORMATION)0x0);
      return 0;
    }
    if (param_2 != 0x111) {
      if (param_2 == 0x117) {
        FUN_00011d80(param_3,param_4,(int)hMem);
        return 0;
      }
LAB_00012f94:
      LVar1 = DefWindowProcW(param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
      return LVar1;
    }
    uVar2 = (uint)param_3 & 0xffff;
    switch(uVar2) {
    case 1:
      local_28 = 0xffffff65;
      local_24 = 0xd;
      FUN_000124fc(hMem,0,param_3,auStack_30);
      break;
    case 2:
      PostMessageW(param_1,0x10,0,0);
      break;
    case 3:
    case 4:
    case 5:
      FUN_00011de4(uVar2,(int)hMem);
      break;
    case 6:
    case 7:
      hMem[6].unused = 1;
      hMem[4].unused = uVar2;
      hMem[5].unused = uVar2 - 6;
      Msg = 0x1030;
      param_3 = hMem;
      param_4 = FUN_00011fac;
      goto LAB_00012da8;
    default:
      param_2 = 0x111;
      goto LAB_00012f94;
    case 10:
      FUN_000118f0(param_1,(HWND)hMem[1].unused);
      break;
    case 0xb:
      FUN_000119a8(param_1,(HWND)hMem[1].unused);
    }
  }
  return 0;
}



/* 0001301c FUN_0001301c */

/* Boundary evidence: original MIPS .pdata 0001301c..000130b3. Semantic name remains unreviewed. */

void FUN_0001301c(HINSTANCE param_1)

{
  INITCOMMONCONTROLSEX local_38;
  WNDCLASSW local_30;
  
  local_38.dwSize = 8;
  local_38.dwICC = 1;
  InitCommonControlsEx(&local_38);
  local_30.style = 0;
  local_30.lpfnWndProc = FUN_00012d10;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 4;
  local_30.hIcon = (HICON)0x0;
  local_30.hInstance = param_1;
  local_30.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
  local_30.hbrBackground = (HBRUSH)0x40000006;
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.lpszClassName = L"CONTROLEXE_MAIN";
  RegisterClassW(&local_30);
  return;
}



/* 000130b4 FUN_000130b4 */

/* Boundary evidence: original MIPS .pdata 000130b4..00013177. Semantic name remains unreviewed. */

undefined4 FUN_000130b4(HINSTANCE param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  HWND hWnd;
  int iVar2;
  undefined3 extraout_var;
  BOOL BVar3;
  MSG MStack_30;
  
  hWnd = FindWindowW(L"CONTROLEXE_MAIN",(LPCWSTR)0x0);
  if (hWnd == (HWND)0x0) {
    if (((param_2 != 0) || (iVar2 = FUN_0001301c(param_1), iVar2 != 0)) &&
       (bVar1 = FUN_00011644(param_1,param_4), CONCAT31(extraout_var,bVar1) != 0)) {
      while (BVar3 = GetMessageW(&MStack_30,(HWND)0x0,0,0), BVar3 != 0) {
        TranslateMessage(&MStack_30);
        DispatchMessageW(&MStack_30);
      }
      return MStack_30.wParam;
    }
  }
  else {
    SetForegroundWindow(hWnd);
  }
  return 0;
}



/* 00013178 FUN_00013178 */

/* Boundary evidence: original MIPS .pdata 00013178..000131cb. Semantic name remains unreviewed. */

void FUN_00013178(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_000131f8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 000131cc FUN_000131cc */

/* Boundary evidence: original MIPS .pdata 000131cc..000131f7. Semantic name remains unreviewed. */

undefined4 FUN_000131cc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00013178(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 000131f8 FUN_000131f8 */

/* Boundary evidence: original MIPS .pdata 000131f8..0001323f. Semantic name remains unreviewed. */

void FUN_000131f8(uint param_1)

{
  if ((param_1 == DAT_00014144) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


