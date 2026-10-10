/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40631908 FUN_40631908 */

/* Boundary evidence: original MIPS .pdata 40631908..40631963. Semantic name remains unreviewed. */

undefined4 FUN_40631908(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_4063a980 = param_1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4063a9c0);
  }
  if (param_2 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4063a9c0);
  }
  return 1;
}



/* 40631964 FUN_40631964 */

/* Boundary evidence: original MIPS .pdata 40631964..40631eeb. Semantic name remains unreviewed. */

LRESULT FUN_40631964(HWND param_1,UINT param_2,uint param_3,LPARAM param_4)

{
  bool bVar1;
  LRESULT LVar2;
  BOOL BVar3;
  int iVar4;
  HCURSOR pHVar5;
  LPWSTR lpCommandLine;
  int *piVar6;
  undefined *puVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  WPARAM wParam;
  tagMSG tStack_150;
  WCHAR aWStack_130 [128];
  uint local_30;
  
  local_30 = DAT_4063a758;
  if (param_2 == 2) {
    PostQuitMessage(0);
    DAT_4063a8e4 = (HWND)0x0;
    goto LAB_40631eac;
  }
  if (param_2 == 6) {
    if ((param_3 & 0xffff) == 0) {
      DAT_4063a768 = GetFocus();
    }
    else if (DAT_4063a768 != (HWND)0x0) {
      SetFocus(DAT_4063a768);
    }
    goto LAB_40631eac;
  }
  if (param_2 == 0x10) {
    if (DAT_4063a76c != 0) {
      SetLocaleInfoW(DAT_4063a978,0x1009,(LPCWSTR)&DAT_4063a988);
      DAT_4063a76c = 0;
    }
    if (DAT_4063a8d4 == (HWND)0x0) goto LAB_40631a58;
    DestroyWindow(DAT_4063a8d4);
    DAT_4063a8d4 = (HWND)0x0;
    iVar4 = 0;
    puVar7 = PTR_DAT_4063a6a0;
    do {
      if (*(HWND *)(puVar7 + iVar4 + 0x1c) != (HWND)0x0) {
        ShowWindow(*(HWND *)(puVar7 + iVar4 + 0x1c),0);
        puVar7 = PTR_DAT_4063a6a0;
      }
      iVar4 = iVar4 + 0x24;
    } while (iVar4 < 0x90);
    ShowWindow(DAT_4063a8dc,5);
    ShowWindow(*(HWND *)(PTR_DAT_4063a69c + 0x1c),5);
    goto LAB_40631eac;
  }
  if (param_2 == 0x53) {
    if (DAT_4063a8d4 == (HWND)0x0) {
      LVar2 = SendMessageW(DAT_4063a8dc,0x130b,0,0);
      lpCommandLine = (LPWSTR)(&PTR_u_file_ctpnl_htm_adjust_the_langua_40631164)[LVar2];
    }
    else {
      LVar2 = SendMessageW(DAT_4063a8d4,0x130b,0,0);
      lpCommandLine = (LPWSTR)(&PTR_u_file_ctpnl_htm_regional_settings_40631170)[LVar2];
    }
    CreateProcessW(L"peghelp",lpCommandLine,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,
                   0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
    goto LAB_40631eac;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x464) {
LAB_40631a58:
      LVar2 = DefWindowProcW(param_1,param_2,param_3,param_4);
      FUN_40639164(local_30);
      return LVar2;
    }
    FUN_40634294(param_3);
    LoadStringW(DAT_4063a980,0x2f44,aWStack_130,0x80);
    MessageBoxW(DAT_4063a8e4,aWStack_130,(LPCWSTR)PTR_DAT_4063a6a4,0x10);
    goto LAB_40631eac;
  }
  if ((param_3 & 0xffff) == 1) {
    if (DAT_4063a8d4 == (HWND)0x0) {
      piVar11 = (int *)(PTR_DAT_4063a69c + 0x6c);
      piVar8 = (int *)PTR_DAT_4063a69c;
    }
    else {
      piVar11 = (int *)(PTR_DAT_4063a6a0 + 0x90);
      piVar8 = (int *)PTR_DAT_4063a6a0;
    }
    bVar1 = false;
    if (piVar8 != piVar11) {
      piVar9 = piVar8 + 4;
      do {
        if (bVar1) goto LAB_40631eac;
        wParam = piVar9[1];
        if (wParam != *piVar9 * 0x24 + wParam) {
          do {
            iVar4 = FUN_4063551c(wParam);
            if (iVar4 != 0) {
              bVar1 = true;
              PostMessageW(DAT_4063a8e4,0x464,wParam,0);
              break;
            }
            wParam = wParam + 0x24;
          } while (wParam != *piVar9 * 0x24 + piVar9[1]);
        }
        piVar6 = piVar9 + 5;
        piVar9 = piVar9 + 9;
      } while (piVar6 != piVar11);
      if (bVar1) goto LAB_40631eac;
    }
    iVar4 = FUN_40632cbc();
    pHVar5 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar5 = SetCursor(pHVar5);
    if (iVar4 == 0) {
      if (piVar8 != piVar11) {
        piVar8 = piVar8 + 4;
        do {
          if ((piVar8[3] != 0) && (iVar10 = piVar8[1], iVar10 != *piVar8 * 0x24 + iVar10)) {
            do {
              if ((*(int *)(iVar10 + 0x1c) != 0) && (*(int *)(iVar10 + 0x20) != 0)) {
                if (iVar4 == 0) {
                  iVar4 = 1;
                }
                FUN_40634810(iVar10);
              }
              iVar10 = iVar10 + 0x24;
            } while (iVar10 != *piVar8 * 0x24 + piVar8[1]);
          }
          piVar9 = piVar8 + 5;
          piVar8 = piVar8 + 9;
        } while (piVar9 != piVar11);
        goto LAB_40631cbc;
      }
    }
    else {
      if (DAT_4063a8d4 == (HWND)0x0) {
        while (piVar9 = piVar8, piVar8 = piVar9 + 9, piVar8 != piVar11) {
          if ((piVar9[0x10] != 0) && (iVar10 = piVar9[0xe], iVar10 != piVar9[0xd] * 0x24 + iVar10))
          {
            do {
              if ((*(int *)(iVar10 + 0x1c) != 0) && (*(int *)(iVar10 + 0x20) != 0)) {
                FUN_40634810(iVar10);
              }
              iVar10 = iVar10 + 0x24;
            } while (iVar10 != piVar9[0xd] * 0x24 + piVar9[0xe]);
          }
        }
      }
LAB_40631cbc:
      if (iVar4 != 0) {
        PostMessageW((HWND)0xffff,0x1a,0,1);
      }
    }
    SetCursor(pHVar5);
    DAT_4063a76c = 0;
  }
  else {
    if ((param_3 & 0xffff) != 2) {
      param_2 = 0x111;
      goto LAB_40631a58;
    }
    do {
      BVar3 = PeekMessageW(&tStack_150,DAT_4063a8e4,0x464,0x464,1);
    } while (BVar3 != 0);
  }
  PostMessageW(param_1,0x10,0,0);
LAB_40631eac:
  FUN_40639164(local_30);
  return 0;
}



/* 40631eec FUN_40631eec */

/* Boundary evidence: original MIPS .pdata 40631eec..40631f8f. Semantic name remains unreviewed. */

undefined4 FUN_40631eec(void)

{
  DWORD DVar1;
  HWND pHVar2;
  undefined4 uVar3;
  
  DAT_4063a9b4 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,L"CPL_Regional Settings");
  if ((DAT_4063a9b4 == (HANDLE)0x0) || (DVar1 = GetLastError(), DVar1 != 0xb7)) {
    uVar3 = 0;
  }
  else {
    CloseHandle(DAT_4063a9b4);
    pHVar2 = FindWindowW(L"CPL_Regional Settings",(LPCWSTR)0x0);
    if (pHVar2 != (HWND)0x0) {
      SetForegroundWindow((HWND)((uint)pHVar2 | 1));
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* 40631f90 FUN_40631f90 */

/* Boundary evidence: original MIPS .pdata 40631f90..40632057. Semantic name remains unreviewed. */

void FUN_40631f90(HINSTANCE param_1,int param_2)

{
  INITCOMMONCONTROLSEX local_40;
  WNDCLASSW local_38;
  
  local_40.dwSize = 8;
  local_40.dwICC = 0x3000;
  InitCommonControlsEx(&local_40);
  local_38.lpfnWndProc = FUN_40631964;
  local_38.style = 0;
  local_38.cbClsExtra = 0;
  local_38.cbWndExtra = 0;
  local_38.hInstance = param_1;
  local_38.hIcon = LoadIconW(param_1,(LPCWSTR)(uint)*(ushort *)(PTR_DAT_4063a69c + param_2 * 0x24));
  local_38.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
  local_38.hbrBackground = GetStockObject(0);
  local_38.lpszMenuName = (LPCWSTR)0x0;
  local_38.lpszClassName = L"CPL_Regional Settings";
  RegisterClassW(&local_38);
  return;
}



/* 40632058 FUN_40632058 */

/* WARNING: Removing unreachable block (ram,0x406320b8) */
/* WARNING: Removing unreachable block (ram,0x406320f0) */
/* Boundary evidence: original MIPS .pdata 40632058..4063220b. Semantic name remains unreviewed. */

bool FUN_40632058(HINSTANCE param_1,int param_2,HWND param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  HANDLE lParam;
  
  uVar2 = GetDialogBaseUnits();
  iVar3 = GetSystemMetrics(5);
  iVar4 = GetSystemMetrics(6);
  iVar5 = GetSystemMetrics(4);
  LoadStringW(DAT_4063a980,0x2faf,(LPWSTR)PTR_DAT_4063a6a4,0x3c);
  DAT_4063a8e4 = CreateWindowExW(0x80000500,L"CPL_Regional Settings",(LPCWSTR)PTR_DAT_4063a6a4,
                                 0xc80000,0,0,iVar3 * 2 + ((int)((uVar2 & 0xffff) * 0x10a) >> 2),
                                 iVar5 + ((int)((uVar2 >> 0x10) * 99) >> 3) + iVar4 * 2,param_3,
                                 (HMENU)0x0,param_1,(LPVOID)0x0);
  bVar1 = DAT_4063a8e4 != (HWND)0x0;
  if (bVar1) {
    CenterWindow(DAT_4063a8e4,0);
    lParam = LoadImageW(param_1,(LPCWSTR)(uint)*(ushort *)(PTR_DAT_4063a69c + param_4 * 0x24),1,0x10
                        ,0x10,0);
    SendMessageW(DAT_4063a8e4,0x80,0,(LPARAM)lParam);
    ShowWindow(DAT_4063a8e4,param_2);
    UpdateWindow(DAT_4063a8e4);
  }
  return bVar1;
}



/* 4063220c CPlApplet */

/* Boundary evidence: original MIPS .pdata 4063220c..4063266b. Semantic name remains unreviewed. */

undefined4 CPlApplet(HWND param_1,int param_2,WPARAM param_3,undefined4 *param_4)

{
  bool bVar1;
  HICON pHVar2;
  int iVar3;
  undefined3 extraout_var;
  BOOL BVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  HWND hWnd;
  tagMSG tStack_48;
  
                    /* 0x220c  1  CPlApplet */
  uVar7 = 1;
  if (param_2 == 1) {
    if (DAT_4063a760 == 0) {
      iVar8 = 0;
      iVar3 = 0;
      do {
        iVar6 = iVar3 + 0x24;
        *(int *)(PTR_DAT_4063a69c + iVar3 + 0x20) = iVar8;
        iVar8 = iVar8 + 1;
        iVar3 = iVar6;
      } while (iVar6 < 0x6c);
    }
    DAT_4063a760 = DAT_4063a760 + 1;
  }
  else if (param_2 != 2) {
    if (param_2 == 5) {
      iVar3 = FUN_40631eec();
      if (iVar3 != 0) {
        return 1;
      }
      DAT_4063a764 = LoadLibraryW(L"COREDLL.DLL");
      if ((((DAT_4063a764 == (HMODULE)0x0) ||
           (DAT_4063a9b8 = GetProcAddressW(DAT_4063a764,L"EnumUILanguagesW"), DAT_4063a9b8 == 0)) ||
          (DAT_4063a9d4 = GetProcAddressW(DAT_4063a764,L"GetSystemDefaultUILanguage"),
          DAT_4063a9d4 == 0)) ||
         ((DAT_4063a98c = GetProcAddressW(DAT_4063a764,L"GetUserDefaultUILanguage"),
          DAT_4063a98c == 0 ||
          (DAT_4063a990 = GetProcAddressW(DAT_4063a764,L"SetUserDefaultUILanguage"),
          DAT_4063a990 == 0)))) {
        DAT_4063a9b8 = 0;
        DAT_4063a9d4 = 0;
        DAT_4063a98c = 0;
        DAT_4063a990 = 0;
      }
      FUN_40636ca8();
      FUN_40631f90(DAT_4063a980,param_3);
      LoadStringW(DAT_4063a980,0x2f4e,&DAT_4063a9a0,10);
      bVar1 = FUN_40632058(DAT_4063a980,5,param_1,param_3);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        if (DAT_4063a9b4 == 0) {
          return 1;
        }
        CloseHandle((HANDLE)DAT_4063a9b4);
        return 1;
      }
      DAT_4063a8e0 = GetUserDefaultLCID();
      iVar3 = FUN_406342d4(param_3);
      if (iVar3 == 0) {
        PostMessageW(DAT_4063a8e4,0x10,0,0);
      }
      iVar3 = GetMessageW(&tStack_48,(HWND)0x0,0,0);
      while (iVar3 != 0) {
        BVar4 = FUN_40634170(&tStack_48);
        if (BVar4 == 0) {
          if (DAT_4063a8d4 == 0) {
            iVar3 = 3;
            puVar5 = PTR_DAT_4063a69c;
          }
          else {
            iVar3 = 4;
            puVar5 = PTR_DAT_4063a6a0;
          }
          iVar8 = 0;
          if (iVar3 != 0) {
            puVar9 = (undefined4 *)(puVar5 + 0x1c);
            do {
              hWnd = (HWND)*puVar9;
              BVar4 = IsWindow(hWnd);
              if ((BVar4 != 0) && (BVar4 = IsDialogMessageW(hWnd,&tStack_48), BVar4 != 0)) break;
              iVar8 = iVar8 + 1;
              puVar9 = puVar9 + 9;
            } while (iVar8 < iVar3);
            if (iVar8 < iVar3) goto LAB_40632578;
          }
          TranslateMessage(&tStack_48);
          DispatchMessageW(&tStack_48);
        }
LAB_40632578:
        iVar3 = GetMessageW(&tStack_48,(HWND)0x0,0,0);
      }
      UnregisterClassW(L"CPL_Regional Settings",DAT_4063a980);
      if (DAT_4063a9b4 != 0) {
        CloseHandle((HANDLE)DAT_4063a9b4);
      }
      if (DAT_4063a764 != (HMODULE)0x0) {
        FreeLibrary(DAT_4063a764);
        DAT_4063a764 = (HMODULE)0x0;
      }
      FUN_40636d4c();
    }
    else if (param_2 == 7) {
      DAT_4063a760 = DAT_4063a760 + -1;
    }
    else if (param_2 == 8) {
      iVar3 = param_3 * 0x24;
      *param_4 = 0x1d4;
      param_4[1] = 0;
      param_4[2] = 0;
      param_4[3] = (uint)*(ushort *)(PTR_DAT_4063a69c + iVar3);
      pHVar2 = LoadIconW(DAT_4063a980,(LPCWSTR)(uint)*(ushort *)(PTR_DAT_4063a69c + iVar3));
      param_4[4] = pHVar2;
      *(undefined1 *)(param_4 + 0x35) = 0;
      *(undefined1 *)((int)param_4 + 0xd5) = 0;
      LoadStringW(DAT_4063a980,0x2ee1,(LPWSTR)(param_4 + 5),0x20);
      LoadStringW(DAT_4063a980,(uint)*(ushort *)(PTR_DAT_4063a69c + iVar3 + 4),
                  (LPWSTR)(param_4 + 0x15),0x40);
    }
    uVar7 = 0;
  }
  return uVar7;
}



/* 4063266c FUN_4063266c */

/* Boundary evidence: original MIPS .pdata 4063266c..40632797. Semantic name remains unreviewed. */

HFONT FUN_4063266c(HWND param_1)

{
  LSTATUS LVar1;
  HANDLE h;
  HFONT pHVar2;
  uint local_80;
  DWORD local_7c;
  DWORD local_78 [2];
  LOGFONTW local_70;
  uint local_14;
  
  local_14 = DAT_4063a758;
  local_80 = 700;
  local_7c = 4;
  LVar1 = RegQueryValueExW((HKEY)0x80000002,L"FontWeight",(LPDWORD)L"SYSTEM\\GWE\\Button",local_78,
                           (LPBYTE)&local_80,&local_7c);
  if (((LVar1 != 0) || (local_78[0] != 4)) || (400 < local_80)) {
    memset(&local_70,0,0x5c);
    h = (HANDLE)SendMessageW(param_1,0x31,0,0);
    if (h == (HANDLE)0x0) {
      h = GetStockObject(0xd);
    }
    GetObjectW(h,0x5c,&local_70);
    if (local_70.lfHeight != 0) {
      local_70.lfWeight = local_80;
      pHVar2 = CreateFontIndirectW(&local_70);
      if (pHVar2 != (HFONT)0x0) {
        FUN_40639164(local_14);
        return pHVar2;
      }
    }
  }
  FUN_40639164(local_14);
  return (HFONT)0x0;
}



/* 40632798 FUN_40632798 */

/* Boundary evidence: original MIPS .pdata 40632798..406328a3. Semantic name remains unreviewed. */

undefined4 FUN_40632798(int param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  HCURSOR pHVar5;
  
  piVar3 = *(int **)(param_1 + 0x14);
  pHVar5 = (HCURSOR)0x0;
  uVar4 = 1;
  bVar1 = false;
  if (piVar3 != piVar3 + *(int *)(param_1 + 0x10) * 9) {
    do {
      if (piVar3[7] == 0) {
        if (!bVar1) {
          bVar1 = true;
          pHVar5 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
          pHVar5 = SetCursor(pHVar5);
        }
        piVar3[7] = 1;
        piVar3[8] = 0;
        iVar2 = FUN_40635b78(piVar3);
        if (iVar2 == 0) {
          uVar4 = 0;
          piVar3[7] = 0;
        }
      }
      piVar3 = piVar3 + 9;
    } while (piVar3 != (int *)(*(int *)(param_1 + 0x10) * 0x24 + *(int *)(param_1 + 0x14)));
  }
  (**(code **)(param_1 + 0x18))(param_1);
  if (bVar1) {
    SetCursor(pHVar5);
  }
  return uVar4;
}



/* 406328a4 FUN_406328a4 */

/* Boundary evidence: original MIPS .pdata 406328a4..4063290b. Semantic name remains unreviewed. */

HGLOBAL FUN_406328a4(LPCWSTR param_1,undefined4 *param_2)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  
  *param_2 = 0;
  hResInfo = FindResourceW(DAT_4063a980,(LPCWSTR)((uint)param_1 & 0xffff),(LPCWSTR)0x5);
  if ((hResInfo == (HRSRC)0x0) ||
     (pvVar1 = LoadResource(DAT_4063a980,hResInfo), pvVar1 == (HGLOBAL)0x0)) {
    pvVar1 = (HGLOBAL)0x0;
  }
  return pvVar1;
}



/* 4063290c FUN_4063290c */

/* Boundary evidence: original MIPS .pdata 4063290c..40632a7b. Semantic name remains unreviewed. */

undefined4 FUN_4063290c(int param_1)

{
  LPCDLGTEMPLATEW lpTemplate;
  undefined4 uVar1;
  HWND hWnd;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_28 [2];
  
  if (DAT_4063a8d4 == 0) {
    iVar4 = 3;
    puVar3 = PTR_DAT_4063a69c;
  }
  else {
    iVar4 = 4;
    puVar3 = PTR_DAT_4063a6a0;
  }
  iVar2 = 0;
  if (iVar4 != 0) {
    puVar5 = (undefined4 *)(puVar3 + 0x1c);
    do {
      if ((iVar2 != param_1) && ((HWND)*puVar5 != (HWND)0x0)) {
        ShowWindow((HWND)*puVar5,0);
      }
      iVar2 = iVar2 + 1;
      puVar5 = puVar5 + 9;
    } while (iVar2 < iVar4);
  }
  puVar3 = puVar3 + param_1 * 0x24;
  if (*(int *)(puVar3 + 0x1c) == 0) {
    local_28[0] = 0;
    lpTemplate = FUN_406328a4((LPCWSTR)(uint)*(ushort *)(puVar3 + 6),local_28);
    if (lpTemplate != (LPCDLGTEMPLATEW)0x0) {
      hWnd = CreateDialogIndirectParamW
                       (DAT_4063a980,lpTemplate,DAT_4063a788,*(DLGPROC *)(puVar3 + 8),(LPARAM)puVar3
                       );
      if (local_28[0] != 0) {
        LocalFree(lpTemplate);
      }
      if (hWnd != (HWND)0x0) {
        SetWindowPos(hWnd,(HWND)0x0,0,0,0,0,3);
        goto LAB_40632a34;
      }
    }
    uVar1 = 0;
  }
  else {
LAB_40632a34:
    ShowWindow(*(HWND *)(puVar3 + 0x1c),5);
    FUN_40632798((int)puVar3);
    (**(code **)(puVar3 + 0xc))(puVar3);
    uVar1 = 1;
  }
  return uVar1;
}



/* 40632a7c FUN_40632a7c */

/* Boundary evidence: original MIPS .pdata 40632a7c..40632b4f. Semantic name remains unreviewed. */

void FUN_40632a7c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar1 = PTR_DAT_4063a6a0;
  puVar2 = PTR_DAT_4063a6a0;
  if (PTR_DAT_4063a6a0 != PTR_DAT_4063a6a0 + 0x90) {
    do {
      if ((*(int *)(puVar1 + 0x1c) != 0) &&
         (iVar3 = *(int *)(puVar1 + 0x14), iVar3 != *(int *)(puVar1 + 0x10) * 0x24 + iVar3)) {
        do {
          *(undefined4 *)(iVar3 + 0x1c) = 0;
          *(undefined4 *)(iVar3 + 0x20) = 0;
          iVar3 = iVar3 + 0x24;
          puVar2 = PTR_DAT_4063a6a0;
        } while (iVar3 != *(int *)(puVar1 + 0x10) * 0x24 + *(int *)(puVar1 + 0x14));
      }
      puVar1 = puVar1 + 0x24;
    } while (puVar1 != puVar2 + 0x90);
  }
  if (DAT_4063a76c != 0) {
    SetLocaleInfoW(DAT_4063a978,0x1009,(LPCWSTR)&DAT_4063a988);
    DAT_4063a76c = 0;
  }
  return;
}



/* 40632b50 FUN_40632b50 */

/* Boundary evidence: original MIPS .pdata 40632b50..40632b8f. Semantic name remains unreviewed. */

void FUN_40632b50(int param_1)

{
  if ((param_1 != 0) && (*(HWND *)(param_1 + 0x1c) != (HWND)0x0)) {
    SendDlgItemMessageW(*(HWND *)(param_1 + 0x1c),0x411,0x30,DAT_4063a8d8,0);
  }
  return;
}



/* 40632b90 FUN_40632b90 */

/* Boundary evidence: original MIPS .pdata 40632b90..40632bfb. Semantic name remains unreviewed. */

void FUN_40632b90(int param_1)

{
  if ((param_1 != 0) && (*(HWND *)(param_1 + 0x1c) != (HWND)0x0)) {
    SendDlgItemMessageW(*(HWND *)(param_1 + 0x1c),0x428,0x30,DAT_4063a8d8,0);
    SendDlgItemMessageW(*(HWND *)(param_1 + 0x1c),0x427,0x30,DAT_4063a8d8,0);
  }
  return;
}



/* 40632bfc FUN_40632bfc */

/* Boundary evidence: original MIPS .pdata 40632bfc..40632cbb. Semantic name remains unreviewed. */

void FUN_40632bfc(int param_1)

{
  HWND hWnd;
  LRESULT LVar1;
  
  if ((param_1 != 0) && (*(HWND *)(param_1 + 0x1c) != (HWND)0x0)) {
    SendDlgItemMessageW(*(HWND *)(param_1 + 0x1c),0x438,0x30,DAT_4063a8d8,0);
    SendDlgItemMessageW(*(HWND *)(param_1 + 0x1c),0x43c,0x30,DAT_4063a8d8,0);
    SendDlgItemMessageW(*(HWND *)(param_1 + 0x1c),0x442,0x30,DAT_4063a8d8,0);
    hWnd = GetDlgItem(*(HWND *)(param_1 + 0x1c),0x449);
    LVar1 = SendMessageW(hWnd,0x146,0,0);
    EnableWindow(hWnd,(uint)(1 < LVar1));
  }
  return;
}



/* 40632cbc FUN_40632cbc */

/* Boundary evidence: original MIPS .pdata 40632cbc..40632def. Semantic name remains unreviewed. */

undefined4 FUN_40632cbc(void)

{
  LCID LVar1;
  HCURSOR pHVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int iVar6;
  
  uVar4 = 0;
  LVar1 = GetUserDefaultLCID();
  if (DAT_4063a8e0 != LVar1) {
    pHVar2 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar2 = SetCursor(pHVar2);
    puVar3 = PTR_DAT_4063a6a0;
    puVar5 = PTR_DAT_4063a6a0;
    if (PTR_DAT_4063a6a0 != PTR_DAT_4063a6a0 + 0x90) {
      do {
        iVar6 = *(int *)(puVar5 + 0x14);
        if (iVar6 != *(int *)(puVar5 + 0x10) * 0x24 + iVar6) {
          do {
            SetLocaleInfoW(0x400,*(LCTYPE *)(iVar6 + 4),(LPCWSTR)0x0);
            *(undefined4 *)(iVar6 + 0x20) = 0;
            iVar6 = iVar6 + 0x24;
            puVar3 = PTR_DAT_4063a6a0;
          } while (iVar6 != *(int *)(puVar5 + 0x10) * 0x24 + *(int *)(puVar5 + 0x14));
        }
        puVar5 = puVar5 + 0x24;
      } while (puVar5 != puVar3 + 0x90);
    }
    SetUserDefaultLCID(DAT_4063a8e0);
    uVar4 = 1;
    PostMessageW((HWND)0xffff,0x1a,0,1);
    SetCursor(pHVar2);
  }
  return uVar4;
}



/* 40632df0 FUN_40632df0 */

/* Boundary evidence: original MIPS .pdata 40632df0..40632eeb. Semantic name remains unreviewed. */

void FUN_40632df0(wchar_t *param_1,size_t param_2,undefined4 param_3,uint param_4,undefined4 param_5
                 ,int param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  wchar_t *_Dest;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  uVar4 = param_3;
  uVar5 = param_3;
  uVar6 = param_3;
  uVar7 = param_3;
  uVar8 = param_3;
  uVar9 = param_3;
  iVar1 = _snwprintf(param_1,param_2,(wchar_t *)(&PTR_u_123456789_40631484)[param_4 % 10],param_3,
                     param_3,param_3,param_3,param_3,param_3,param_3,param_3);
  _Dest = param_1 + iVar1;
  if (param_6 != 0) {
    iVar2 = _snwprintf(_Dest,param_2 - iVar1,L"%s",param_5,param_3,uVar4,uVar5,uVar6,uVar7,uVar8,
                       uVar9);
    uVar3 = (param_2 - iVar1) - iVar2;
    if (param_6 + 1U <= uVar3) {
      uVar3 = param_6 + 1U;
    }
    wcsncpy(_Dest + iVar2,L"000000000",uVar3 - 1);
    (_Dest + iVar2)[uVar3 - 1] = L'\0';
  }
  return;
}



/* 40632eec FUN_40632eec */

/* Boundary evidence: original MIPS .pdata 40632eec..4063356b. Semantic name remains unreviewed. */

void FUN_40632eec(int param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  LRESULT LVar3;
  uint uVar4;
  LRESULT LVar5;
  LRESULT LVar6;
  WPARAM wParam;
  int *piVar7;
  wchar_t *pwVar8;
  HWND hDlg;
  WCHAR aWStack_210 [20];
  WCHAR local_1e8 [20];
  WCHAR aWStack_1c0 [80];
  wchar_t awStack_120 [80];
  WCHAR aWStack_80 [20];
  WCHAR aWStack_58 [20];
  uint local_30;
  
  local_30 = DAT_4063a758;
  hDlg = *(HWND *)(param_1 + 0x1c);
  if (hDlg == (HWND)0x0) goto LAB_40633538;
  pWVar1 = FUN_40635650(param_1,0x42d,aWStack_80,0x14);
  if (((pWVar1 == (LPWSTR)0x0) ||
      (pWVar1 = FUN_40635650(param_1,0x426,aWStack_58,0x14), pWVar1 == (LPWSTR)0x0)) ||
     (pWVar1 = FUN_40635650(param_1,0x41a,aWStack_210,0x14), pWVar1 == (LPWSTR)0x0)) {
    SetDlgItemTextW(hDlg,0x3fb,L"????");
LAB_4063352c:
    SetDlgItemTextW(hDlg,0x3fd,L"????");
  }
  else {
    if (*(int *)(param_1 + -8) == 0) {
      iVar2 = GetLocaleInfoW(DAT_4063a8e0,0x51,local_1e8,0x14);
      if (iVar2 == 0) {
        local_1e8[0] = L'-';
        local_1e8[1] = 0;
      }
    }
    else {
      pWVar1 = FUN_40635650(param_1 + -0x24,0x419,local_1e8,0x14);
      if (pWVar1 == (LPWSTR)0x0) goto LAB_4063352c;
    }
    LVar3 = FUN_406355bc(param_1,0x430);
    uVar4 = FUN_406355bc(param_1,0x432);
    LVar5 = FUN_406355bc(param_1,0x41d);
    LVar6 = FUN_406355bc(param_1,0x422);
    FUN_40632df0(awStack_120,0x50,aWStack_58,uVar4,aWStack_80,LVar3);
    pwVar8 = aWStack_1c0;
    if (LVar5 == 0) {
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s",aWStack_210,awStack_120);
    }
    else if (LVar5 == 1) {
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s",awStack_120,aWStack_210);
    }
    else if (LVar5 == 2) {
      StringCchPrintfW(aWStack_1c0,0x50,L"%s %s",aWStack_210,awStack_120);
    }
    else if (LVar5 == 3) {
      StringCchPrintfW(aWStack_1c0,0x50,L"%s %s",awStack_120,aWStack_210);
    }
    else {
      pwVar8 = L"123456789.00";
    }
    SetDlgItemTextW(hDlg,0x3fb,pwVar8);
    pwVar8 = aWStack_1c0;
    switch(LVar6) {
    case 0:
      StringCchPrintfW(aWStack_1c0,0x50,L"(%s%s)",aWStack_210,awStack_120);
      break;
    case 1:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s%s",local_1e8,aWStack_210,awStack_120);
      break;
    case 2:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s%s",aWStack_210,local_1e8,awStack_120);
      break;
    case 3:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s%s",aWStack_210,awStack_120,local_1e8);
      break;
    case 4:
      StringCchPrintfW(aWStack_1c0,0x50,L"(%s%s)",awStack_120,aWStack_210);
      break;
    case 5:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s%s",local_1e8,awStack_120,aWStack_210);
      break;
    case 6:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s%s",awStack_120,local_1e8,aWStack_210);
      break;
    case 7:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s%s",awStack_120,aWStack_210,local_1e8);
      break;
    case 8:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s %s",local_1e8,awStack_120,aWStack_210);
      break;
    case 9:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s %s",local_1e8,aWStack_210,awStack_120);
      break;
    case 10:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s %s%s",awStack_120,aWStack_210,local_1e8);
      break;
    case 0xb:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s %s%s",aWStack_210,awStack_120,local_1e8);
      break;
    case 0xc:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s %s%s",aWStack_210,local_1e8,awStack_120);
      break;
    case 0xd:
      StringCchPrintfW(aWStack_1c0,0x50,L"%s%s %s",awStack_120,local_1e8,aWStack_210);
      break;
    case 0xe:
      StringCchPrintfW(aWStack_1c0,0x50,L"(%s %s)",aWStack_210,awStack_120);
      break;
    case 0xf:
      StringCchPrintfW(aWStack_1c0,0x50,L"(%s %s)",awStack_120,aWStack_210);
      break;
    default:
      pwVar8 = L"-123456789.00";
    }
    SetDlgItemTextW(hDlg,0x3fd,pwVar8);
    piVar7 = *(int **)(param_1 + 0x14);
    if (piVar7 != piVar7 + *(int *)(param_1 + 0x10) * 9) {
      do {
        if ((piVar7 != (int *)0x0) && ((*piVar7 == 0x422 || (*piVar7 == 0x41d)))) {
          wParam = SendMessageW((HWND)piVar7[6],0x147,0,0);
          iVar2 = FUN_40635b78(piVar7);
          if (iVar2 == 0) {
            piVar7[7] = 0;
          }
          SendMessageW((HWND)piVar7[6],0x14e,wParam,0);
        }
        piVar7 = piVar7 + 9;
      } while (piVar7 != (int *)(*(int *)(param_1 + 0x10) * 0x24 + *(int *)(param_1 + 0x14)));
    }
  }
LAB_40633538:
  FUN_40639164(local_30);
  return;
}



/* 4063356c FUN_4063356c */

/* Boundary evidence: original MIPS .pdata 4063356c..40633877. Semantic name remains unreviewed. */

void FUN_4063356c(int param_1)

{
  LPWSTR pWVar1;
  LRESULT LVar2;
  uint uVar3;
  LRESULT LVar4;
  WPARAM wParam;
  int iVar5;
  wchar_t *lpString;
  int *piVar6;
  HWND hDlg;
  WCHAR aWStack_1e0 [20];
  WCHAR aWStack_1b8 [20];
  WCHAR aWStack_190 [20];
  wchar_t awStack_168 [80];
  WCHAR aWStack_c8 [80];
  uint local_28;
  
  local_28 = DAT_4063a758;
  hDlg = *(HWND *)(param_1 + 0x1c);
  if (hDlg != (HWND)0x0) {
    pWVar1 = FUN_40635650(param_1,0x414,aWStack_190,0x14);
    if ((pWVar1 == (LPWSTR)0x0) ||
       (pWVar1 = FUN_40635650(param_1,0x417,aWStack_1b8,0x14), pWVar1 == (LPWSTR)0x0)) {
      SetDlgItemTextW(hDlg,0x3f7,L"????");
    }
    else {
      pWVar1 = FUN_40635650(param_1,0x419,aWStack_1e0,0x14);
      if (pWVar1 != (LPWSTR)0x0) {
        LVar2 = FUN_406355bc(param_1,0x416);
        uVar3 = FUN_406355bc(param_1,0x418);
        LVar4 = FUN_406355bc(param_1,0x41b);
        FUN_40632df0(awStack_168,0x50,aWStack_1b8,uVar3,aWStack_190,LVar2);
        SetDlgItemTextW(hDlg,0x3f7,awStack_168);
        lpString = aWStack_c8;
        if (LVar4 == 0) {
          StringCchPrintfW(aWStack_c8,0x50,L"(%s)",awStack_168);
        }
        else if (LVar4 == 1) {
          StringCchPrintfW(aWStack_c8,0x50,L"%s%s",aWStack_1e0,awStack_168);
        }
        else if (LVar4 == 2) {
          StringCchPrintfW(aWStack_c8,0x50,L"%s %s",aWStack_1e0,awStack_168);
        }
        else if (LVar4 == 3) {
          StringCchPrintfW(aWStack_c8,0x50,L"%s%s",awStack_168,aWStack_1e0);
        }
        else if (LVar4 == 4) {
          StringCchPrintfW(aWStack_c8,0x50,L"%s %s",awStack_168,aWStack_1e0);
        }
        else {
          lpString = L"-123456789.00";
        }
        SetDlgItemTextW(hDlg,0x3f9,lpString);
        piVar6 = *(int **)(param_1 + 0x14);
        if (piVar6 != piVar6 + *(int *)(param_1 + 0x10) * 9) {
          do {
            if ((piVar6 != (int *)0x0) && ((*piVar6 == 0x41b || (*piVar6 == 0x41e)))) {
              wParam = SendMessageW((HWND)piVar6[6],0x147,0,0);
              iVar5 = FUN_40635b78(piVar6);
              if (iVar5 == 0) {
                piVar6[7] = 0;
              }
              SendMessageW((HWND)piVar6[6],0x14e,wParam,0);
            }
            piVar6 = piVar6 + 9;
          } while (piVar6 != (int *)(*(int *)(param_1 + 0x10) * 0x24 + *(int *)(param_1 + 0x14)));
        }
        goto LAB_4063384c;
      }
    }
    SetDlgItemTextW(hDlg,0x3f9,L"????");
  }
LAB_4063384c:
  FUN_40639164(local_28);
  return;
}



/* 40633878 FUN_40633878 */

/* Boundary evidence: original MIPS .pdata 40633878..4063391b. Semantic name remains unreviewed. */

void FUN_40633878(int param_1)

{
  LPWSTR pWVar1;
  HWND hDlg;
  WCHAR aWStack_b8 [40];
  WCHAR aWStack_68 [40];
  uint local_18;
  
  local_18 = DAT_4063a758;
  hDlg = *(HWND *)(param_1 + 0x1c);
  if ((hDlg != (HWND)0x0) &&
     (pWVar1 = FUN_40635650(param_1,0x43f,aWStack_b8,0x28), pWVar1 != (LPWSTR)0x0)) {
    FUN_40634784(aWStack_b8);
    GetDateFormatW(DAT_4063a8e0,0,(SYSTEMTIME *)0x0,aWStack_b8,aWStack_68,0x28);
    SetDlgItemTextW(hDlg,0x3f3,aWStack_68);
  }
  FUN_40639164(local_18);
  return;
}



/* 4063391c FUN_4063391c */

/* Boundary evidence: original MIPS .pdata 4063391c..406339bf. Semantic name remains unreviewed. */

void FUN_4063391c(int param_1)

{
  LPWSTR pWVar1;
  HWND hDlg;
  WCHAR aWStack_428 [260];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_4063a758;
  hDlg = *(HWND *)(param_1 + 0x1c);
  if ((hDlg != (HWND)0x0) &&
     (pWVar1 = FUN_40635650(param_1,0x444,aWStack_428,0x104), pWVar1 != (LPWSTR)0x0)) {
    FUN_40634784(aWStack_428);
    GetDateFormatW(DAT_4063a8e0,0,(SYSTEMTIME *)0x0,aWStack_428,aWStack_220,0x104);
    SetDlgItemTextW(hDlg,0x3f5,aWStack_220);
  }
  FUN_40639164(local_18);
  return;
}



/* 406339c0 FUN_406339c0 */

/* Boundary evidence: original MIPS .pdata 406339c0..40633c2f. Semantic name remains unreviewed. */

void FUN_406339c0(int param_1)

{
  wchar_t *pwVar1;
  size_t sVar2;
  size_t sVar3;
  LCTYPE LCType;
  UINT uID;
  int iVar4;
  size_t _Count;
  _SYSTEMTIME _Stack_200;
  WCHAR local_1f0;
  undefined1 auStack_1ee [22];
  WCHAR local_1d8;
  undefined1 auStack_1d6 [22];
  WCHAR aWStack_1c0 [40];
  WCHAR aWStack_170 [40];
  wchar_t awStack_120 [128];
  uint local_20;
  
  local_20 = DAT_4063a758;
  GetLocalTime(&_Stack_200);
  FUN_40635650(param_1,0x42a,aWStack_170,0x28);
  FUN_40634784(aWStack_170);
  GetTimeFormatW(DAT_4063a8e0,0,&_Stack_200,aWStack_170,aWStack_1c0,0x28);
  pwVar1 = wcschr(aWStack_170,L't');
  if ((pwVar1 != (wchar_t *)0x0) && (pwVar1[-1] != L'\'')) {
    local_1f0 = L'\0';
    memset(auStack_1ee,0,0x10);
    local_1d8 = L'\0';
    memset(auStack_1d6,0,0x10);
    LCType = 0x29;
    iVar4 = 0x431;
    if (_Stack_200.wHour < 0xc) {
      LCType = 0x28;
      iVar4 = 0x42e;
    }
    GetLocaleInfoW(0x800,LCType,&local_1f0,9);
    FUN_40635650(param_1,iVar4,&local_1d8,9);
    if (local_1f0 == L'\0') {
      if (_Stack_200.wHour < 0xc) {
        uID = 0x2f45;
      }
      else {
        uID = 0x2f46;
      }
      LoadStringW(DAT_4063a980,uID,&local_1f0,9);
    }
    iVar4 = wcscmp(&local_1f0,&local_1d8);
    if (iVar4 != 0) {
      if (pwVar1[1] == L't') {
        pwVar1 = wcsstr(aWStack_1c0,&local_1f0);
        if (pwVar1 != (wchar_t *)0x0) {
          _Count = (int)pwVar1 - (int)aWStack_1c0 >> 1;
          wcsncpy(awStack_120,aWStack_1c0,_Count);
          wcscpy(awStack_120 + _Count,&local_1d8);
          sVar2 = wcslen(&local_1f0);
          sVar3 = wcslen(&local_1d8);
          wcscpy(awStack_120 + sVar3 + _Count,aWStack_1c0 + sVar2 + _Count);
          StringCbCopyExW(aWStack_1c0,0x50,awStack_120,(STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800);
        }
      }
      else {
        pwVar1 = wcschr(aWStack_1c0,local_1f0);
        if (pwVar1 != (wchar_t *)0x0) {
          *pwVar1 = local_1d8;
        }
      }
    }
  }
  SetDlgItemTextW(*(HWND *)(param_1 + 0x1c),0x44c,aWStack_1c0);
  FUN_40639164(local_20);
  return;
}



/* 40633c38 FUN_40633c38 */

/* Boundary evidence: original MIPS .pdata 40633c38..40633c57. Semantic name remains unreviewed. */

void FUN_40633c38(wchar_t *param_1)

{
  wcspbrk(param_1,L"\'Hhmst0123456789");
  return;
}



/* 40633c58 FUN_40633c58 */

/* Boundary evidence: original MIPS .pdata 40633c58..40633c77. Semantic name remains unreviewed. */

void FUN_40633c58(wchar_t *param_1)

{
  wcspbrk(param_1,L"gyMd0123456789");
  return;
}



/* 40633c78 FUN_40633c78 */

/* Boundary evidence: original MIPS .pdata 40633c78..40633e0f. Semantic name remains unreviewed. */

wint_t * FUN_40633c78(wchar_t *param_1,size_t *param_2,int param_3)

{
  wint_t wVar1;
  bool bVar2;
  int iVar3;
  size_t _Count;
  wint_t *pwVar4;
  size_t *psVar5;
  int iVar6;
  wchar_t *_Source;
  
  _Count = 0;
  _Source = (wchar_t *)0x0;
  bVar2 = false;
  if (*param_1 != L'\0') {
    do {
      iVar6 = 0;
      psVar5 = param_2;
      if (0 < param_3) {
LAB_40633cd8:
        iVar3 = wcsncmp(param_1,(wchar_t *)psVar5[1],*psVar5);
        if (iVar3 != 0) goto code_r0x40633cf0;
        if (_Source == (wchar_t *)0x0) goto LAB_40633d88;
        if (_Count == 0) break;
        wcsncpy((wchar_t *)&DAT_4063a77c,_Source,_Count);
        (&DAT_4063a77c)[_Count] = 0;
        pwVar4 = &DAT_4063a77c;
        wVar1 = DAT_4063a77c;
        while ((wVar1 != 0 && (iVar3 = iswctype(*pwVar4,8), iVar3 != 0))) {
          pwVar4 = pwVar4 + 1;
          wVar1 = *pwVar4;
        }
        if (*pwVar4 != 0) {
          return &DAT_4063a77c;
        }
        if (!bVar2) {
          wcscpy((wchar_t *)&DAT_4063a770,(wchar_t *)&DAT_4063a77c);
          bVar2 = true;
        }
LAB_40633d88:
        param_1 = param_1 + param_2[iVar6 * 2];
        _Count = 0;
        _Source = param_1;
LAB_40633da4:
        if (param_3 <= iVar6) goto LAB_40633db0;
        goto LAB_40633db8;
      }
LAB_40633db0:
      param_1 = param_1 + 1;
      _Count = _Count + 1;
LAB_40633db8:
    } while (*param_1 != L'\0');
    if (bVar2) {
      return (wint_t *)&DAT_4063a770;
    }
  }
  return (wint_t *)&DAT_406315a8;
code_r0x40633cf0:
  iVar6 = iVar6 + 1;
  psVar5 = psVar5 + 2;
  if (param_3 <= iVar6) goto LAB_40633da4;
  goto LAB_40633cd8;
}



/* 40633e10 FUN_40633e10 */

/* Boundary evidence: original MIPS .pdata 40633e10..40633f7f. Semantic name remains unreviewed. */

undefined4 FUN_40633e10(HWND param_1,uint param_2)

{
  LRESULT LVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  HWND hWnd;
  
  hWnd = DAT_4063a8d4;
  if (DAT_4063a8d4 == (HWND)0x0) {
    hWnd = DAT_4063a8dc;
  }
  if (param_2 == 0xfffffdd8) {
    iVar4 = SendMessageW(hWnd,0x130b,0,0);
  }
  else if (param_2 == 0xfffffdd9) {
    LVar1 = SendMessageW(hWnd,0x130b,0,0);
    iVar3 = FUN_4063290c(LVar1);
    iVar4 = DAT_4063a6ac;
    if (iVar3 == 0) {
      return 0;
    }
  }
  else {
    iVar4 = DAT_4063a6ac;
    if (((0xfffffffc < param_2) && (param_2 != 0xffffffff)) &&
       ((LVar1 = SendMessageW(hWnd,0x130b,0,0), param_1 != (HWND)0x0 ||
        ((iVar4 = DAT_4063a6ac, LVar1 != DAT_4063a6ac &&
         (param_1 = GetNextDlgTabItem(DAT_4063a788,hWnd,0), iVar4 = LVar1, param_1 != (HWND)0x0)))))
       ) {
      SetFocus(param_1);
      uVar2 = SendMessageW(param_1,0x87,0,0);
      iVar4 = LVar1;
      if ((uVar2 & 8) != 0) {
        SendMessageW(param_1,0xb1,0,-1);
      }
    }
  }
  DAT_4063a6ac = iVar4;
  return 1;
}



/* 40633f80 FUN_40633f80 */

/* Boundary evidence: original MIPS .pdata 40633f80..40633faf. Semantic name remains unreviewed. */

void FUN_40633f80(int param_1)

{
  FUN_40633878(param_1);
  FUN_4063391c(param_1);
  return;
}



/* 40633fb0 FUN_40633fb0 */

/* Boundary evidence: original MIPS .pdata 40633fb0..40633fd3. Semantic name remains unreviewed. */

void FUN_40633fb0(wchar_t *param_1)

{
  FUN_40633c78(param_1,(size_t *)&DAT_4063a6b0,10);
  return;
}



/* 40633fd4 FUN_40633fd4 */

/* Boundary evidence: original MIPS .pdata 40633fd4..40633ff7. Semantic name remains unreviewed. */

void FUN_40633fd4(wchar_t *param_1)

{
  FUN_40633c78(param_1,(size_t *)&DAT_4063a700,0xb);
  return;
}



/* 40633ff8 FUN_40633ff8 */

/* Boundary evidence: original MIPS .pdata 40633ff8..406340ff. Semantic name remains unreviewed. */

undefined4 FUN_40633ff8(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  if (param_2 == 2) {
    if (DAT_4063a8d8 != (HGDIOBJ)0x0) {
      DeleteObject(DAT_4063a8d8);
      DAT_4063a8d8 = (HGDIOBJ)0x0;
    }
    DAT_4063a8dc = 0;
  }
  else if (param_2 == 0x4e) {
    FUN_40633e10((HWND)0x0,*(uint *)(param_4 + 8));
  }
  else if (param_2 == 0x53) {
    PostMessageW(DAT_4063a8e4,0x53,param_3,param_4);
  }
  else if (param_2 == 0x111) {
    if (((param_3 & 0xffff) != 0) && ((param_3 & 0xffff) < 3)) {
      SetFocus(DAT_4063a8e4);
      PostMessageW(DAT_4063a8e4,0x111,param_3,param_4);
    }
    return 1;
  }
  return 0;
}



/* 40634100 FUN_40634100 */

/* Boundary evidence: original MIPS .pdata 40634100..4063416f. Semantic name remains unreviewed. */

undefined4 FUN_40634100(WPARAM param_1,HWND param_2)

{
  int iVar1;
  undefined4 uVar2;
  HWND hWnd;
  
  hWnd = DAT_4063a8d4;
  if (DAT_4063a8d4 == (HWND)0x0) {
    hWnd = DAT_4063a8dc;
  }
  SendMessageW(hWnd,0x130c,param_1,0);
  iVar1 = FUN_40633e10((HWND)0x0,0xfffffdd9);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_40633e10(param_2,0xfffffffe);
  }
  return uVar2;
}



/* 40634170 FUN_40634170 */

/* Boundary evidence: original MIPS .pdata 40634170..40634293. Semantic name remains unreviewed. */

BOOL FUN_40634170(LPMSG param_1)

{
  SHORT SVar1;
  BOOL BVar2;
  undefined2 extraout_var;
  LRESULT LVar3;
  undefined2 extraout_var_00;
  WPARAM WVar4;
  int iVar5;
  HWND hWnd;
  
  if ((DAT_4063a788 == (HWND)0x0) || (BVar2 = IsWindow(DAT_4063a788), BVar2 == 0)) {
    BVar2 = 0;
  }
  else {
    if (DAT_4063a8d4 == (HWND)0x0) {
      iVar5 = 3;
      hWnd = DAT_4063a8dc;
    }
    else {
      iVar5 = 4;
      hWnd = DAT_4063a8d4;
    }
    if (((param_1->wParam == 9) && (param_1->message == 0x100)) &&
       (SVar1 = GetAsyncKeyState(0x11), CONCAT22(extraout_var,SVar1) != 0)) {
      LVar3 = SendMessageW(hWnd,0x130b,0,0);
      SVar1 = GetAsyncKeyState(0x10);
      if (CONCAT22(extraout_var_00,SVar1) == 0) {
        WVar4 = LVar3 + 1;
        if (iVar5 <= (int)WVar4) {
          WVar4 = 0;
        }
      }
      else {
        WVar4 = LVar3 - 1;
        if ((int)WVar4 < 0) {
          WVar4 = iVar5 - 1;
        }
      }
      FUN_40634100(WVar4,(HWND)0x0);
      BVar2 = 1;
    }
    else {
      BVar2 = IsDialogMessageW(DAT_4063a788,param_1);
    }
  }
  return BVar2;
}



/* 40634294 FUN_40634294 */

/* Boundary evidence: original MIPS .pdata 40634294..406342d3. Semantic name remains unreviewed. */

void FUN_40634294(int param_1)

{
  HWND hWnd;
  LONG LVar1;
  
  hWnd = GetParent(*(HWND *)(param_1 + 0x18));
  LVar1 = GetWindowLongW(hWnd,8);
  FUN_40634100(*(WPARAM *)(LVar1 + 0x20),*(HWND *)(param_1 + 0x18));
  return;
}



/* 406342d4 FUN_406342d4 */

/* Boundary evidence: original MIPS .pdata 406342d4..406344b3. Semantic name remains unreviewed. */

undefined4 FUN_406342d4(WPARAM param_1)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  undefined4 uVar1;
  int iVar2;
  WPARAM wParam;
  tagRECT local_158;
  undefined4 local_148 [3];
  WCHAR *local_13c;
  undefined4 local_134;
  WCHAR aWStack_128 [128];
  uint local_28;
  
  local_28 = DAT_4063a758;
  hResInfo = FindResourceW(DAT_4063a980,(LPCWSTR)0x8ae,(LPCWSTR)0x5);
  lpTemplate = LoadResource(DAT_4063a980,hResInfo);
  DAT_4063a788 = CreateDialogIndirectParamW(DAT_4063a980,lpTemplate,DAT_4063a8e4,FUN_40633ff8,0);
  if (DAT_4063a788 == (HWND)0x0) {
    FUN_40639164(local_28);
    uVar1 = 0;
  }
  else {
    DAT_4063a8dc = GetDlgItem(DAT_4063a788,0x81b);
    DAT_4063a8d8 = FUN_4063266c(DAT_4063a788);
    GetClientRect(DAT_4063a8dc,&local_158);
    SendMessageW(DAT_4063a8dc,0x1329,0,(local_158.right - local_158.left) / 3 & 0xffffU | 0x140000);
    SendMessageW(DAT_4063a8dc,0x132b,0,0x30014);
    local_148[0] = 3;
    wParam = 0;
    iVar2 = 0;
    local_134 = 0xffffffff;
    do {
      LoadStringW(DAT_4063a980,(uint)*(ushort *)(PTR_DAT_4063a69c + iVar2 + 2),aWStack_128,0x80);
      local_13c = aWStack_128;
      SendMessageW(DAT_4063a8dc,0x133e,wParam,(LPARAM)local_148);
      iVar2 = iVar2 + 0x24;
      wParam = wParam + 1;
    } while (iVar2 < 0x6c);
    SendMessageW(DAT_4063a8dc,0x130c,param_1,0);
    FUN_40634100(param_1,(HWND)0x0);
    uVar1 = 1;
    InvalidateRect(DAT_4063a8dc,(RECT *)0x0,1);
    FUN_40639164(local_28);
  }
  return uVar1;
}



/* 406344b4 FUN_406344b4 */

/* Boundary evidence: original MIPS .pdata 406344b4..4063468b. Semantic name remains unreviewed. */

undefined4 FUN_406344b4(void)

{
  undefined4 uVar1;
  int iVar2;
  WPARAM wParam;
  tagRECT local_158;
  undefined4 local_148 [3];
  WCHAR *local_13c;
  undefined4 local_134;
  WCHAR aWStack_128 [128];
  uint local_28;
  
  local_28 = DAT_4063a758;
  GetClientRect(DAT_4063a8dc,&local_158);
  DAT_4063a8d4 = CreateWindowExW(0,L"SysTabControl32",(LPCWSTR)0x0,0x30000,0,0,
                                 local_158.right - local_158.left,local_158.bottom - local_158.top,
                                 DAT_4063a788,(HMENU)0x0,DAT_4063a980,(LPVOID)0x0);
  if (DAT_4063a8d4 == (HWND)0x0) {
    FUN_40639164(local_28);
    uVar1 = 0;
  }
  else {
    iVar2 = local_158.right - local_158.left;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 3;
    }
    SendMessageW(DAT_4063a8d4,0x1329,0,iVar2 >> 2 & 0xffffU | 0x140000);
    SendMessageW(DAT_4063a8d4,0x132b,0,0x30014);
    local_148[0] = 3;
    local_134 = 0xffffffff;
    wParam = 0;
    iVar2 = 0;
    do {
      LoadStringW(DAT_4063a980,(uint)*(ushort *)(PTR_DAT_4063a6a0 + iVar2 + 2),aWStack_128,0x80);
      local_13c = aWStack_128;
      SendMessageW(DAT_4063a8d4,0x133e,wParam,(LPARAM)local_148);
      iVar2 = iVar2 + 0x24;
      wParam = wParam + 1;
    } while (iVar2 < 0x90);
    SendMessageW(DAT_4063a8d4,0x130c,0,0);
    FUN_40634100(0,(HWND)0x0);
    ShowWindow(DAT_4063a8d4,5);
    ShowWindow(DAT_4063a8dc,0);
    FUN_40639164(local_28);
    uVar1 = 1;
  }
  return uVar1;
}



/* 4063468c FUN_4063468c */

void FUN_4063468c(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *param_1;
  do {
    if (uVar1 == 0) {
      return;
    }
    uVar1 = *param_1;
    if (uVar1 < 0x69) {
      uVar2 = DAT_4063a9a8;
      if (uVar1 != 0x68) {
        uVar2 = DAT_4063a9aa;
        if (uVar1 == 0x48) goto LAB_40634768;
        uVar2 = DAT_4063a9a2;
        if (uVar1 != 0x4d) {
          uVar2 = DAT_4063a9a0;
          if (uVar1 == 100) goto LAB_40634768;
          uVar2 = DAT_4063a9a6;
          if (uVar1 != 0x67) goto LAB_4063476c;
        }
      }
LAB_40634704:
      *param_1 = uVar2;
    }
    else {
      uVar2 = DAT_4063a9ac;
      if (uVar1 == 0x6d) {
LAB_40634768:
        *param_1 = uVar2;
      }
      else {
        uVar2 = DAT_4063a9ae;
        if (uVar1 == 0x73) goto LAB_40634704;
        uVar2 = DAT_4063a9b0;
        if (uVar1 == 0x74) goto LAB_40634768;
        uVar2 = DAT_4063a9a4;
        if (uVar1 == 0x79) goto LAB_40634704;
      }
    }
LAB_4063476c:
    param_1 = param_1 + 1;
    uVar1 = *param_1;
  } while( true );
}



/* 40634784 FUN_40634784 */

void FUN_40634784(short *param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  sVar1 = *param_1;
  sVar2 = DAT_4063a9a0;
  do {
    if (sVar1 == 0) {
      return;
    }
    iVar3 = 0;
    if (sVar2 != 0) {
      sVar1 = sVar2;
      do {
        if (*param_1 == sVar1) {
          *param_1 = *(short *)(&UNK_406315cc + iVar3 * 2);
          sVar2 = DAT_4063a9a0;
          break;
        }
        iVar3 = iVar3 + 1;
        sVar1 = (&DAT_4063a9a0)[iVar3];
      } while (sVar1 != 0);
    }
    param_1 = param_1 + 1;
    sVar1 = *param_1;
  } while( true );
}



/* 40634810 FUN_40634810 */

/* Boundary evidence: original MIPS .pdata 40634810..40634f2b. Semantic name remains unreviewed. */

undefined4 FUN_40634810(int param_1)

{
  bool bVar1;
  LSTATUS LVar2;
  LRESULT LVar3;
  LRESULT LVar4;
  wchar_t *pwVar5;
  HKL pHVar6;
  undefined3 extraout_var;
  size_t sVar7;
  uint uVar8;
  LCTYPE LCType;
  LPCWSTR lpLCData;
  ushort uVar9;
  HWND hWnd;
  int iVar10;
  WPARAM WVar11;
  uint local_538;
  HKEY local_534;
  HKEY local_530;
  HKEY local_52c;
  wchar_t local_528 [3];
  undefined2 local_522;
  wchar_t awStack_520 [12];
  WCHAR aWStack_508 [100];
  WCHAR local_440;
  undefined1 auStack_43e [518];
  WCHAR local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
  local_30 = DAT_4063a758;
  local_440 = L'\0';
  memset(auStack_43e,0,0x206);
  local_238 = L'\0';
  memset(auStack_236,0,0x206);
  hWnd = *(HWND *)(param_1 + 0x18);
  if (hWnd == (HWND)0x0) {
    FUN_40639164(local_30);
    return 0;
  }
  uVar9 = *(ushort *)(param_1 + 8);
  if (uVar9 == 0) {
    GetWindowTextW(hWnd,aWStack_508,100);
LAB_40634ed0:
    LCType = *(LCTYPE *)(param_1 + 4);
    lpLCData = aWStack_508;
  }
  else {
    if (uVar9 == 1) {
LAB_40634e5c:
      WVar11 = SendMessageW(hWnd,0x147,0,0);
      LVar3 = SendMessageW(hWnd,0x150,WVar11,0);
      if ((*(ushort *)(param_1 + 0xc) & 1) == 0) {
        pwVar5 = L"%d";
      }
      else {
        pwVar5 = L"%d;0";
      }
      StringCchPrintfW(aWStack_508,100,pwVar5,LVar3);
      goto LAB_40634ed0;
    }
    if (uVar9 < 3) goto LAB_40634ef0;
    if (5 < uVar9) {
      if (uVar9 != 6) {
        if (uVar9 == 7) {
          if (((DAT_4063a990 != (code *)0x0) && (DAT_4063a984 != 0)) &&
             (DAT_4063a97c != DAT_4063a794)) {
            WVar11 = SendMessageW(hWnd,0x147,0,0);
            uVar8 = SendMessageW(hWnd,0x150,WVar11,0);
            (*DAT_4063a990)(uVar8 & 0xffff);
            LoadStringW(DAT_4063a980,0x2f13,&local_440,0x104);
            LoadStringW(DAT_4063a980,0x2f14,&local_238,0x104);
            MessageBoxW(DAT_4063a8e4,&local_238,&local_440,0);
          }
        }
        else if (uVar9 == 8) {
          local_52c = (HKEY)0x0;
          LVar2 = RegOpenKeyExW((HKEY)0x80000001,L"Keyboard Layout\\Preload",0,0,&local_52c);
          if (LVar2 == 0) {
            iVar10 = 0;
            local_530 = (HKEY)0x0;
            local_534 = (HKEY)0x0;
            do {
              iVar10 = iVar10 + 1;
              _snwprintf(local_528,4,L"%u",iVar10);
              local_522 = 0;
              RegDeleteKeyW(local_52c,local_528);
            } while (iVar10 < 0xf);
            LVar2 = RegCreateKeyExW((HKEY)0x80000002,L"System\\Ime",0,(LPWSTR)0x0,0,0,
                                    (LPSECURITY_ATTRIBUTES)0x0,&local_530,&local_538);
            if ((LVar2 == 0) && (local_538 == 2)) {
              RegDeleteValueW(local_530,L"Settings");
            }
            LVar2 = RegCreateKeyExW((HKEY)0x80000002,L"System\\GWE\\Edit",0,(LPWSTR)0x0,0,0,
                                    (LPSECURITY_ATTRIBUTES)0x0,&local_534,&local_538);
            if ((LVar2 == 0) && (local_538 == 2)) {
              RegDeleteValueW(local_534,L"IMELEVEL");
            }
            LVar3 = SendMessageW(*(HWND *)(param_1 + 0x18),0x146,0,0);
            WVar11 = 0;
            if (0 < LVar3) {
              do {
                LVar4 = SendMessageW(*(HWND *)(param_1 + 0x18),0x150,WVar11,0);
                pwVar5 = FUN_40637818(LVar4,awStack_520);
                if (pwVar5 != (wchar_t *)0x0) {
                  pHVar6 = LoadKeyboardLayoutW(awStack_520,0);
                  bVar1 = FUN_40637868((uint)pHVar6);
                  if (CONCAT31(extraout_var,bVar1) != 0) {
                    if (pHVar6 == (HKL)0xe0010412) {
                      iVar10 = FUN_40637888(-0x1ffefbee,L"mshime97.dll");
                      if (iVar10 != 0) {
                        if (local_530 != (HKEY)0x0) {
                          local_528[0] = L',';
                          local_528[1] = L'\0';
                          RegSetValueExW(local_530,L"Settings",0,4,(BYTE *)local_528,4);
                        }
                        if (local_534 != (HKEY)0x0) {
                          local_528[0] = L'\x03';
                          local_528[1] = L'\0';
                          RegSetValueExW(local_534,L"IMELEVEL",0,4,(BYTE *)local_528,4);
                        }
                      }
                    }
                    else if (((pHVar6 == (HKL)0xe0010804) &&
                             (iVar10 = FUN_40637888(-0x1ffef7fc,L"chsime03.dll"), iVar10 != 0)) &&
                            (local_534 != (HKEY)0x0)) {
                      local_528[0] = L'\x03';
                      local_528[1] = L'\0';
                      RegSetValueExW(local_534,L"IMELEVEL",0,4,(BYTE *)local_528,4);
                    }
                  }
                }
                WVar11 = WVar11 + 1;
              } while ((int)WVar11 < LVar3);
            }
            WVar11 = SendMessageW(*(HWND *)(param_1 + 0x18),0x147,0,0);
            LVar3 = SendMessageW(*(HWND *)(param_1 + 0x18),0x150,WVar11,0);
            if ((DAT_4063a8c4 != LVar3) &&
               (pwVar5 = FUN_40637818(LVar3,awStack_520), pwVar5 != (wchar_t *)0x0)) {
              sVar7 = wcslen(awStack_520);
              RegSetValueExW(local_52c,(LPCWSTR)0x0,0,1,(BYTE *)awStack_520,(sVar7 + 1) * 2);
              LoadStringW(DAT_4063a980,0x2f15,&local_440,0x104);
              LoadStringW(DAT_4063a980,0x2f16,&local_238,0x104);
              MessageBoxW(DAT_4063a8e4,&local_238,&local_440,0);
            }
            if (local_530 != (HKEY)0x0) {
              RegCloseKey(local_530);
            }
            if (local_534 != (HKEY)0x0) {
              RegCloseKey(local_534);
            }
          }
          if (local_52c != (HKEY)0x0) {
            RegCloseKey(local_52c);
          }
        }
        goto LAB_40634ef0;
      }
      goto LAB_40634e5c;
    }
    GetWindowTextW(hWnd,aWStack_508,100);
    FUN_40634784(aWStack_508);
    SetLocaleInfoW(DAT_4063a8e0,*(LCTYPE *)(param_1 + 4),aWStack_508);
    if (*(int *)(param_1 + 4) != 0x1f) goto LAB_40634ef0;
    iVar10 = 0;
    pwVar5 = wcschr(aWStack_508,L'y');
    if ((pwVar5 == (wchar_t *)0x0) || (*pwVar5 != L'y')) {
LAB_40634e3c:
      uVar9 = 0x30;
    }
    else {
      do {
        pwVar5 = pwVar5 + 1;
        iVar10 = iVar10 + 1;
      } while (*pwVar5 == L'y');
      uVar9 = 0x31;
      if (iVar10 < 3) goto LAB_40634e3c;
    }
    lpLCData = (LPCWSTR)&local_538;
    LCType = 0x24;
    local_538 = (uint)uVar9;
  }
  SetLocaleInfoW(DAT_4063a8e0,LCType,lpLCData);
LAB_40634ef0:
  FUN_40639164(local_30);
  return 1;
}



/* 40634f2c FUN_40634f2c */

uint FUN_40634f2c(ushort *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  if (param_1 != (ushort *)0x0) {
    for (; uVar2 = (uint)*param_1, uVar2 != 0; param_1 = param_1 + 1) {
      uVar3 = uVar2 - 0x30;
      if ((0xf < uVar3) && (uVar3 = uVar2 - 0x37, 0xf < uVar3)) {
        uVar3 = uVar2 - 0x57;
      }
      uVar1 = uVar3 & 0xf | uVar1 << 4;
    }
  }
  return uVar1;
}



/* 40634f84 FUN_40634f84 */

/* Boundary evidence: original MIPS .pdata 40634f84..406350eb. Semantic name remains unreviewed. */

undefined4 FUN_40634f84(ushort *param_1)

{
  uint Locale;
  int iVar1;
  int iVar2;
  WPARAM wParam;
  WCHAR aWStack_158 [162];
  uint local_14;
  
  local_14 = DAT_4063a758;
  Locale = FUN_40634f2c(param_1);
  if (Locale != 0x7f) {
    iVar1 = GetLocaleInfoW(Locale,2,aWStack_158,0xa2);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoW(Locale,0x1001,aWStack_158,0x50);
      if (iVar1 == 0) {
        FUN_40639164(local_14);
        return 0;
      }
      aWStack_158[iVar1 + -1] = L' ';
      aWStack_158[iVar1] = L'(';
      iVar2 = GetLocaleInfoW(Locale,0x1002,aWStack_158 + iVar1 + 1,0x50);
      iVar2 = iVar2 + iVar1 + 1;
      aWStack_158[iVar2 + -1] = L')';
      aWStack_158[iVar2] = L'\0';
    }
    wParam = SendMessageW(DAT_4063a790,0x143,0,(LPARAM)aWStack_158);
    SendMessageW(DAT_4063a790,0x151,wParam,Locale);
    DAT_4063a798 = DAT_4063a798 + 1;
  }
  FUN_40639164(local_14);
  return 1;
}



/* 406350ec FUN_406350ec */

/* Boundary evidence: original MIPS .pdata 406350ec..40635193. Semantic name remains unreviewed. */

undefined4 FUN_406350ec(STRSAFE_LPCWSTR param_1)

{
  undefined4 uVar1;
  HRESULT HVar2;
  WPARAM wParam;
  wchar_t awStack_d8 [100];
  uint local_10;
  
  local_10 = DAT_4063a758;
  if ((param_1 == (STRSAFE_LPCWSTR)0x0) ||
     (HVar2 = StringCbCopyW(awStack_d8,200,param_1), HVar2 < 0)) {
    FUN_40639164(local_10);
    uVar1 = 0;
  }
  else {
    FUN_4063468c((ushort *)awStack_d8);
    wParam = SendMessageW(DAT_4063a790,0x143,0,(LPARAM)awStack_d8);
    SendMessageW(DAT_4063a790,0x151,wParam,0);
    DAT_4063a798 = DAT_4063a798 + 1;
    FUN_40639164(local_10);
    uVar1 = 1;
  }
  return uVar1;
}



/* 40635194 FUN_40635194 */

/* Boundary evidence: original MIPS .pdata 40635194..40635233. Semantic name remains unreviewed. */

bool FUN_40635194(STRSAFE_LPCWSTR param_1)

{
  WPARAM wParam;
  wchar_t awStack_d8 [100];
  uint local_10;
  
  local_10 = DAT_4063a758;
  if (param_1 != (STRSAFE_LPCWSTR)0x0) {
    StringCbCopyW(awStack_d8,200,param_1);
    FUN_4063468c((ushort *)awStack_d8);
    wParam = SendMessageW(DAT_4063a790,0x143,0,(LPARAM)awStack_d8);
    SendMessageW(DAT_4063a790,0x151,wParam,0);
    DAT_4063a798 = DAT_4063a798 + 1;
    FUN_40639164(local_10);
  }
  else {
    FUN_40639164(DAT_4063a758);
  }
  return param_1 != (STRSAFE_LPCWSTR)0x0;
}



/* 40635234 FUN_40635234 */

/* Boundary evidence: original MIPS .pdata 40635234..40635273. Semantic name remains unreviewed. */

undefined4 FUN_40635234(LPARAM param_1)

{
  DAT_4063a78c = SendMessageW(DAT_4063a790,0x143,0,param_1);
  return 0;
}



/* 40635274 FUN_40635274 */

/* Boundary evidence: original MIPS .pdata 40635274..406352f7. Semantic name remains unreviewed. */

undefined2 * FUN_40635274(int param_1)

{
  wint_t wVar1;
  int iVar2;
  wint_t *pwVar3;
  
  if (*(HWND *)(param_1 + 0x18) != (HWND)0x0) {
    pwVar3 = &DAT_4063a79c;
    GetWindowTextW(*(HWND *)(param_1 + 0x18),(LPWSTR)&DAT_4063a79c,100);
    wVar1 = DAT_4063a79c;
    while (wVar1 != 0) {
      iVar2 = iswctype(*pwVar3,4);
      if (iVar2 != 0) {
        *pwVar3 = 0;
        return &DAT_4063a79c;
      }
      pwVar3 = pwVar3 + 1;
      wVar1 = *pwVar3;
    }
  }
  return (undefined2 *)0x0;
}



/* 40635300 FUN_40635300 */

/* Boundary evidence: original MIPS .pdata 40635300..406353f3. Semantic name remains unreviewed. */

WPARAM FUN_40635300(HWND param_1,WPARAM param_2,wchar_t *param_3)

{
  WPARAM WVar1;
  int iVar2;
  WPARAM WVar3;
  wchar_t awStack_120 [128];
  uint local_20;
  
  local_20 = DAT_4063a758;
  WVar1 = SendMessageW(param_1,0x146,0,0);
  if (0 < (int)WVar1) {
    if (((int)param_2 < 0) || (WVar3 = param_2, (int)WVar1 <= (int)param_2)) {
      param_2 = 0;
      WVar3 = param_2;
    }
    do {
      SendMessageW(param_1,0x148,param_2,(LPARAM)awStack_120);
      iVar2 = wcscmp(param_3,awStack_120);
      if (iVar2 == 0) {
        FUN_40639164(local_20);
        return param_2;
      }
      param_2 = param_2 + 1;
      if (param_2 == WVar1) {
        param_2 = 0;
      }
    } while (param_2 != WVar3);
  }
  FUN_40639164(local_20);
  return 0xffffffff;
}



/* 406353f4 FUN_406353f4 */

/* Boundary evidence: original MIPS .pdata 406353f4..4063546f. Semantic name remains unreviewed. */

void FUN_406353f4(HWND param_1,LPARAM param_2)

{
  SendMessageW(param_1,0xb,0,0);
  SendMessageW(param_1,0x14a,0,param_2);
  SendMessageW(param_1,0x14e,0,0);
  SendMessageW(param_1,0xb,1,0);
  return;
}



/* 40635470 FUN_40635470 */

/* Boundary evidence: original MIPS .pdata 40635470..4063551b. Semantic name remains unreviewed. */

undefined4 FUN_40635470(int param_1)

{
  LPCWSTR lpString;
  size_t sVar1;
  undefined4 uVar2;
  
  if (((*(ushort *)(param_1 + 0xc) & 4) == 0) ||
     (lpString = (LPCWSTR)(**(code **)(param_1 + 0x10))(param_1), lpString == (LPCWSTR)0x0)) {
    uVar2 = 1;
  }
  else {
    MessageBeep(0x10);
    SendMessageW(*(HWND *)(param_1 + 0x18),0x14e,0xffffffff,0);
    SetWindowTextW(*(HWND *)(param_1 + 0x18),lpString);
    sVar1 = wcslen(lpString);
    if (sVar1 != 0) {
      SendMessageW(*(HWND *)(param_1 + 0x18),0x142,0,sVar1 << 0x10);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 4063551c FUN_4063551c */

/* Boundary evidence: original MIPS .pdata 4063551c..4063556b. Semantic name remains unreviewed. */

undefined4 FUN_4063551c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(HWND *)(param_1 + 0x18) == (HWND)0x0) || ((*(ushort *)(param_1 + 0xc) & 4) == 0)) ||
     (iVar1 = GetWindowTextLengthW(*(HWND *)(param_1 + 0x18)), 0 < iVar1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 4063556c FUN_4063556c */

int * FUN_4063556c(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 == 0x42a) {
LAB_406355b0:
    piVar1 = param_1 + 9;
  }
  else {
    if (iVar2 != 0x42b) {
      if (iVar2 == 0x43f) goto LAB_406355b0;
      if (iVar2 != 0x440) {
        return (int *)0x0;
      }
    }
    piVar1 = param_1 + -9;
  }
  return piVar1;
}



/* 406355bc FUN_406355bc */

/* Boundary evidence: original MIPS .pdata 406355bc..4063564f. Semantic name remains unreviewed. */

LRESULT FUN_406355bc(int param_1,int param_2)

{
  WPARAM wParam;
  LRESULT LVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x14);
  piVar2 = piVar3 + *(int *)(param_1 + 0x10) * 9;
  while( true ) {
    if (piVar3 == piVar2) {
      return 0;
    }
    if ((*piVar3 == param_2) && (piVar3[6] != 0)) break;
    piVar3 = piVar3 + 9;
  }
  wParam = SendMessageW((HWND)piVar3[6],0x147,0,0);
  LVar1 = SendMessageW((HWND)piVar3[6],0x150,wParam,0);
  return LVar1;
}



/* 40635650 FUN_40635650 */

/* Boundary evidence: original MIPS .pdata 40635650..40635713. Semantic name remains unreviewed. */

LPWSTR FUN_40635650(int param_1,int param_2,LPWSTR param_3,int param_4)

{
  LRESULT LVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x14);
  piVar2 = piVar3 + *(int *)(param_1 + 0x10) * 9;
  do {
    if (piVar3 == piVar2) {
LAB_406356ac:
      *param_3 = L'\0';
      return (LPWSTR)0x0;
    }
    if ((*piVar3 == param_2) && (piVar3[6] != 0)) {
      if (((*(ushort *)(piVar3 + 3) & 0x20) != 0) ||
         (LVar1 = SendMessageW((HWND)piVar3[6],0x147,0,0), -1 < LVar1)) {
        GetWindowTextW((HWND)piVar3[6],param_3,param_4);
        return param_3;
      }
      goto LAB_406356ac;
    }
    piVar3 = piVar3 + 9;
  } while( true );
}



/* 40635714 FUN_40635714 */

/* Boundary evidence: original MIPS .pdata 40635714..406357eb. Semantic name remains unreviewed. */

void FUN_40635714(int param_1,STRSAFE_LPWSTR param_2,int param_3)

{
  size_t sVar1;
  STRSAFE_LPWSTR pwVar2;
  int iVar3;
  wchar_t local_20;
  undefined1 auStack_1e [10];
  uint local_14;
  
  local_14 = DAT_4063a758;
  local_20 = L'\0';
  memset(auStack_1e,0,8);
  _itow(param_1,&local_20,param_3);
  sVar1 = wcslen(&local_20);
  if ((int)sVar1 < 4) {
    iVar3 = 4 - sVar1;
    if (0 < iVar3) {
      if (iVar3 != 0) {
        pwVar2 = param_2;
        do {
          *pwVar2 = L'0';
          pwVar2 = pwVar2 + 1;
        } while (pwVar2 != param_2 + iVar3);
      }
      param_2 = param_2 + iVar3;
    }
    sVar1 = sVar1 + 1;
  }
  else {
    sVar1 = 5;
  }
  StringCchCopyW(param_2,sVar1,&local_20);
  FUN_40639164(local_14);
  return;
}



/* 406357ec FUN_406357ec */

/* Boundary evidence: original MIPS .pdata 406357ec..40635957. Semantic name remains unreviewed. */

undefined4 FUN_406357ec(ushort *param_1,WPARAM *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  WPARAM wParam;
  WCHAR aWStack_160 [162];
  uint local_1c;
  
  local_1c = DAT_4063a758;
  uVar1 = FUN_40634f2c(param_1);
  uVar1 = uVar1 & 0xffff;
  iVar2 = GetLocaleInfoW(uVar1,2,aWStack_160,0xa2);
  if (iVar2 == 0) {
    iVar2 = GetLocaleInfoW(uVar1,0x1001,aWStack_160,0x50);
    if (iVar2 == 0) {
      FUN_40639164(local_1c);
      return 0;
    }
    aWStack_160[iVar2 + -1] = L' ';
    aWStack_160[iVar2] = L'(';
    iVar3 = GetLocaleInfoW(uVar1,0x1002,aWStack_160 + iVar2 + 1,0x50);
    iVar3 = iVar3 + iVar2 + 1;
    aWStack_160[iVar3 + -1] = L')';
    aWStack_160[iVar3] = L'\0';
  }
  wParam = SendMessageW(DAT_4063a790,0x143,0,(LPARAM)aWStack_160);
  SendMessageW(DAT_4063a790,0x151,wParam,uVar1);
  *param_2 = wParam;
  FUN_40639164(local_1c);
  return 1;
}



/* 40635958 FUN_40635958 */

/* Boundary evidence: original MIPS .pdata 40635958..40635a27. Semantic name remains unreviewed. */

WPARAM FUN_40635958(HWND param_1,LCTYPE param_2)

{
  int iVar1;
  WPARAM WVar2;
  WCHAR aWStack_e0 [100];
  uint local_18;
  
  local_18 = DAT_4063a758;
  iVar1 = GetLocaleInfoW(DAT_4063a8e0,param_2,aWStack_e0,100);
  if (iVar1 == 0) {
    FUN_40639164(local_18);
    WVar2 = 0;
  }
  else {
    FUN_4063468c((ushort *)aWStack_e0);
    WVar2 = FUN_40635300(param_1,0xffffffff,aWStack_e0);
    if (WVar2 == 0xffffffff) {
      SendMessageW(param_1,0x14a,0,(LPARAM)aWStack_e0);
      SendMessageW(param_1,0x151,0,1);
      WVar2 = 0;
    }
    FUN_40639164(local_18);
  }
  return WVar2;
}



/* 40635a28 FUN_40635a28 */

/* Boundary evidence: original MIPS .pdata 40635a28..40635a9f. Semantic name remains unreviewed. */

undefined4 FUN_40635a28(wchar_t *param_1)

{
  CALID Calendar;
  
  Calendar = _wtol(param_1);
  EnumCalendarInfoW(FUN_40635234,DAT_4063a8e0,Calendar,2);
  SendMessageW(DAT_4063a790,0x151,DAT_4063a78c,Calendar);
  DAT_4063a798 = DAT_4063a798 + 1;
  return 1;
}



/* 40635aa0 FUN_40635aa0 */

/* Boundary evidence: original MIPS .pdata 40635aa0..40635b3b. Semantic name remains unreviewed. */

WPARAM FUN_40635aa0(HWND param_1,wchar_t *param_2)

{
  WPARAM wParam;
  
  SendMessageW(param_1,0xb,0,0);
  wParam = FUN_40635300(param_1,0xffffffff,param_2);
  SendMessageW(param_1,0x14e,0xffffffff,0);
  if (-1 < (int)wParam) {
    SendMessageW(param_1,0x144,wParam,0);
  }
  SendMessageW(param_1,0xb,1,0);
  return wParam;
}



/* 40635b3c FUN_40635b3c */

/* Boundary evidence: original MIPS .pdata 40635b3c..40635b77. Semantic name remains unreviewed. */

undefined4 FUN_40635b3c(ushort *param_1)

{
  int iVar1;
  WPARAM local_10 [2];
  
  local_10[0] = 0;
  iVar1 = FUN_406357ec(param_1,local_10);
  if (iVar1 != 0) {
    DAT_4063a798 = DAT_4063a798 + 1;
  }
  return 1;
}



/* 40635b78 FUN_40635b78 */

/* Boundary evidence: original MIPS .pdata 40635b78..40636733. Semantic name remains unreviewed. */

undefined4 FUN_40635b78(int *param_1)

{
  ushort uVar1;
  LANGID LVar2;
  LSTATUS LVar3;
  size_t sVar4;
  size_t sVar5;
  undefined2 extraout_var;
  uint uVar6;
  uint uVar7;
  LCID LVar8;
  int iVar9;
  long lVar10;
  LRESULT LVar11;
  wchar_t *_Str;
  CALTYPE CalType;
  WCHAR *pWVar12;
  WPARAM WVar13;
  HWND hWnd;
  int iVar14;
  undefined4 *puVar15;
  WPARAM WVar16;
  int iVar17;
  WCHAR WVar18;
  DWORD local_278;
  undefined4 *local_274;
  wchar_t local_270;
  undefined1 auStack_26e [14];
  WCHAR local_260 [20];
  WCHAR local_238;
  wchar_t awStack_236 [99];
  WCHAR local_170 [20];
  wchar_t local_148;
  undefined2 local_146;
  wchar_t local_120;
  undefined2 local_11e;
  wchar_t awStack_f8 [100];
  uint local_30;
  
  local_30 = DAT_4063a758;
  local_148 = L'.';
  hWnd = (HWND)param_1[6];
  iVar14 = 0;
  local_260[0] = L'\0';
  local_170[0] = L'\0';
  local_146 = 0;
  local_120 = L'-';
  local_11e = 0;
  if (hWnd == (HWND)0x0) {
    FUN_40639164(DAT_4063a758);
    return 0;
  }
  SendMessageW(hWnd,0x141,(uint)*(ushort *)((int)param_1 + 0xe),0);
  SendMessageW(hWnd,0x14b,0,0);
  WVar13 = 0;
  puVar15 = &DAT_4063a798;
  local_278 = 0;
  local_274 = &DAT_4063a798;
  switch((short)param_1[2]) {
  case 0:
    LoadStringW(DAT_4063a980,(uint)*(ushort *)((int)param_1 + 10),&local_238,100);
    WVar13 = SendMessageW(hWnd,0x14a,0,(LPARAM)&local_238);
    SendMessageW(hWnd,0x151,WVar13,0);
    if (*param_1 == 0x41a) {
      local_278 = 200;
      local_238 = L'\0';
      LVar3 = RegQueryValueExW((HKEY)0x80000002,L"ExtraCurrency",(LPDWORD)&DAT_406316e0,
                               (LPDWORD)&local_274,(LPBYTE)&local_238,&local_278);
      if ((LVar3 == 0) && (local_238 != L'\0')) {
        SendMessageW(hWnd,0x14a,0xffffffff,(LPARAM)&local_238);
      }
    }
    iVar17 = GetLocaleInfoW(DAT_4063a8e0,param_1[1] | 0x80000000,&local_238,100);
    if (iVar17 == 0) {
      local_238 = L'\0';
    }
    WVar13 = FUN_40635300(hWnd,0xffffffff,&local_238);
    if (WVar13 == 0xffffffff) {
      WVar13 = SendMessageW(hWnd,0x14a,0,(LPARAM)&local_238);
      SendMessageW(hWnd,0x151,WVar13,0);
    }
    iVar17 = GetLocaleInfoW(DAT_4063a8e0,param_1[1],&local_238,100);
    if (iVar17 == 0) {
      local_238 = L'\0';
    }
    WVar13 = FUN_40635300(hWnd,0xffffffff,&local_238);
    if (WVar13 == 0xffffffff) {
      WVar13 = SendMessageW(hWnd,0x14a,0,(LPARAM)&local_238);
      SendMessageW(hWnd,0x151,WVar13,0);
    }
    SendMessageW(hWnd,0x14e,WVar13,0);
    InvalidateRect(hWnd,(RECT *)0x0,1);
    break;
  case 1:
    if ((*(ushort *)(param_1 + 3) & 2) == 0) {
      iVar14 = 0;
      do {
        StringCchPrintfW(&local_238,100,L"%d",iVar14);
        WVar16 = SendMessageW(hWnd,0x143,0,(LPARAM)&local_238);
        SendMessageW(hWnd,0x151,WVar16,WVar16);
        iVar14 = iVar14 + 1;
      } while (iVar14 <= (int)(uint)*(ushort *)((int)param_1 + 10));
    }
    else {
      uVar6 = (uint)*(ushort *)((int)param_1 + 10);
      LoadStringW(DAT_4063a980,uVar6,&local_238,100);
      while (local_238 != L'\n') {
        iVar14 = GetLocaleInfoW(DAT_4063a8e0,0xe,local_260,0x14);
        if ((iVar14 != 0) &&
           (iVar14 = GetLocaleInfoW(DAT_4063a8e0,0x51,local_170,0x14), WVar18 = local_260[0],
           iVar14 != 0)) {
          iVar14 = *param_1;
          if ((((iVar14 == 0x41b) || (iVar14 == 0x422)) &&
              ((local_170[0] != L'\0' && (local_260[0] != L'\0')))) &&
             ((iVar17 = wcscmp(&local_120,local_170), iVar17 != 0 ||
              (iVar17 = wcscmp(&local_148,local_260), iVar17 != 0)))) {
            sVar5 = 0;
            do {
              if (awStack_236[sVar5 - 1] == L'-') {
                memset(awStack_f8,0,200);
                wcsncpy(awStack_f8,&local_238,sVar5);
                wcscat(awStack_f8,local_170);
                wcscat(awStack_f8,awStack_236 + sVar5);
                memcpy(&local_238,awStack_f8,200);
                _Str = local_170;
LAB_40636018:
                sVar4 = wcslen(_Str);
                sVar5 = (sVar4 + sVar5) - 1;
              }
              else if (awStack_236[sVar5 - 1] == L'.') {
                memset(awStack_f8,0,200);
                wcsncpy(awStack_f8,&local_238,sVar5);
                wcscat(awStack_f8,local_260);
                wcscat(awStack_f8,awStack_236 + sVar5);
                memcpy(&local_238,awStack_f8,200);
                _Str = local_260;
                goto LAB_40636018;
              }
              sVar5 = sVar5 + 1;
            } while (sVar5 < 100);
            iVar14 = *param_1;
            WVar18 = local_260[0];
          }
          if ((((iVar14 == 0x41e) || (iVar14 == 0x41d)) && (WVar18 != L'\0')) &&
             (iVar14 = wcscmp(&local_148,local_260), iVar14 != 0)) {
            sVar5 = 0;
            pWVar12 = &local_238;
            do {
              if (*pWVar12 == L'.') {
                memset(awStack_f8,0,200);
                wcsncpy(awStack_f8,&local_238,sVar5);
                wcscat(awStack_f8,local_260);
                wcscat(awStack_f8,awStack_236 + sVar5);
                memcpy(&local_238,awStack_f8,200);
                break;
              }
              sVar5 = sVar5 + 1;
              pWVar12 = pWVar12 + 1;
            } while (sVar5 < 100);
          }
        }
        WVar13 = SendMessageW(hWnd,0x143,0,(LPARAM)&local_238);
        SendMessageW(hWnd,0x151,WVar13,WVar13);
        uVar6 = uVar6 + 1;
        LoadStringW(DAT_4063a980,uVar6,&local_238,100);
        WVar13 = local_278;
        puVar15 = local_274;
      }
      iVar14 = uVar6 - *(ushort *)((int)param_1 + 10);
      local_238 = L'\n';
    }
    break;
  case 2:
    FUN_40632a7c();
    param_1[7] = 1;
    DAT_4063a798 = 0;
    DAT_4063a790 = hWnd;
    EnumSystemLocalesW(FUN_40634f84,2);
    iVar14 = DAT_4063a798;
    break;
  case 3:
    DAT_4063a798 = 0;
    DAT_4063a790 = hWnd;
    EnumTimeFormatsW(FUN_406350ec,DAT_4063a8e0,0);
    goto LAB_406363c8;
  case 4:
    CalType = 5;
    goto LAB_406363e0;
  case 5:
    CalType = 6;
LAB_406363e0:
    DAT_4063a798 = 0;
    DAT_4063a790 = hWnd;
    EnumCalendarInfoW(FUN_40635194,DAT_4063a8e0,DAT_4063a6a8,CalType);
LAB_406363c8:
    WVar13 = FUN_40635958(hWnd,param_1[1]);
    break;
  case 6:
    DAT_4063a798 = 0;
    DAT_4063a790 = hWnd;
    EnumCalendarInfoW(FUN_40635a28,DAT_4063a8e0,0xffffffff,1);
    iVar14 = DAT_4063a798;
    break;
  case 7:
    local_270 = L'\0';
    memset(auStack_26e,0,8);
    local_278 = 0;
    iVar17 = 0;
    DAT_4063a798 = 0;
    DAT_4063a790 = hWnd;
    if (DAT_4063a9b8 != (code *)0x0) {
      (*DAT_4063a9b8)(FUN_40635b3c,0);
    }
    iVar14 = DAT_4063a798;
    param_1[7] = 1;
    DAT_4063a984 = 0;
    if (DAT_4063a9d4 == (code *)0x0) {
      if (iVar14 == 0) {
        LVar2 = GetSystemDefaultLangID();
        iVar17 = CONCAT22(extraout_var,LVar2);
        if (DAT_4063a9d4 != (code *)0x0) goto LAB_40636338;
      }
    }
    else {
      if (iVar14 != 0) {
        uVar6 = (*DAT_4063a9d4)();
        WVar16 = 0;
        if (iVar14 < 1) {
LAB_406362c4:
          FUN_40635714(uVar6,&local_270,0x10);
          sVar5 = wcslen(&local_270);
          if ((sVar5 < 5) && (iVar17 = FUN_406357ec((ushort *)&local_270,&local_278), iVar17 != 0))
          {
            iVar14 = iVar14 + 1;
          }
        }
        else {
          do {
            uVar7 = SendMessageW(hWnd,0x150,WVar16,0);
            if ((uVar7 & 0xffff) == uVar6) break;
            WVar16 = WVar16 + 1;
          } while ((int)WVar16 < iVar14);
          if (iVar14 <= (int)WVar16) goto LAB_406362c4;
        }
        EnableWindow(hWnd,1);
        break;
      }
LAB_40636338:
      iVar17 = (*DAT_4063a9d4)();
    }
    FUN_40635714(iVar17,&local_270,0x10);
    sVar5 = wcslen(&local_270);
    WVar16 = 0;
    if (sVar5 < 5) {
      FUN_406357ec((ushort *)&local_270,&local_278);
      WVar16 = local_278;
    }
    EnableWindow(hWnd,0);
    SendMessageW(hWnd,0x14e,WVar16,0);
    DAT_4063a794 = WVar16;
  }
  iVar17 = 100;
  uVar1 = *(ushort *)(param_1 + 2);
  if (uVar1 == 0) {
LAB_406366dc:
    if ((int)WVar13 < 0) goto LAB_406366f8;
  }
  else {
    if (uVar1 == 1) {
LAB_40636604:
      iVar9 = GetLocaleInfoW(DAT_4063a8e0,param_1[1],&local_238,100);
      if (iVar9 == 0) {
LAB_406366ac:
        WVar13 = 0;
      }
      else {
        if ((*(ushort *)(param_1 + 3) & 1) != 0) {
          pWVar12 = &local_238;
          do {
            if (*pWVar12 == L';') {
              *pWVar12 = L'\0';
            }
            iVar17 = iVar17 + -1;
            pWVar12 = pWVar12 + 1;
          } while (iVar17 != 0);
        }
        lVar10 = _wtol(&local_238);
        WVar13 = 0;
        if (iVar14 < 1) goto LAB_406366ac;
        do {
          LVar11 = SendMessageW(hWnd,0x150,WVar13,0);
          if (LVar11 == lVar10) break;
          WVar13 = WVar13 + 1;
        } while ((int)WVar13 < iVar14);
        if (iVar14 <= (int)WVar13) goto LAB_406366ac;
      }
      if ((short)param_1[2] == 6) {
        DAT_4063a6a8 = SendMessageW(hWnd,0x150,WVar13,0);
      }
      goto LAB_406366dc;
    }
    if (uVar1 == 2) {
      DAT_4063a8e0 = GetUserDefaultLCID();
      WVar13 = 0;
      if (0 < iVar14) {
        do {
          LVar8 = SendMessageW(hWnd,0x150,WVar13,0);
          if (LVar8 == DAT_4063a8e0) break;
          WVar13 = WVar13 + 1;
        } while ((int)WVar13 < iVar14);
        if ((int)WVar13 < iVar14) goto LAB_406366dc;
      }
      WVar13 = 0;
      DAT_4063a8e0 = SendMessageW(hWnd,0x150,0,0);
      goto LAB_406366dc;
    }
    if (2 < uVar1) {
      if (uVar1 < 6) goto LAB_406366dc;
      if (uVar1 == 6) goto LAB_40636604;
      if (uVar1 != 7) goto LAB_40636530;
      if ((iVar14 == 0) || (DAT_4063a98c == (code *)0x0)) goto LAB_406366dc;
      uVar6 = (*DAT_4063a98c)();
      WVar13 = 0;
      if (iVar14 < 1) {
LAB_40636504:
        WVar13 = iVar14 - 1;
        EnableWindow(hWnd,0);
      }
      else {
        do {
          uVar7 = SendMessageW(hWnd,0x150,WVar13,0);
          if ((uVar7 & 0xffff) == uVar6) break;
          WVar13 = WVar13 + 1;
        } while ((int)WVar13 < iVar14);
        if (iVar14 <= (int)WVar13) goto LAB_40636504;
      }
      SendMessageW(hWnd,0x14e,WVar13,0);
      puVar15[-1] = WVar13;
      goto LAB_406366dc;
    }
LAB_40636530:
    iVar14 = GetLocaleInfoW(DAT_4063a8e0,param_1[1],&local_238,100);
    if (iVar14 != 0) {
      WVar13 = SendMessageW(hWnd,0x158,0xffffffff,(LPARAM)&local_238);
      if (WVar13 == 0xffffffff) {
        WVar13 = 0;
      }
      goto LAB_406366dc;
    }
    WVar13 = 0;
  }
  SendMessageW(hWnd,0x14e,WVar13,0);
LAB_406366f8:
  FUN_40639164(local_30);
  return 1;
}



/* 40636734 FUN_40636734 */

/* Boundary evidence: original MIPS .pdata 40636734..40636877. Semantic name remains unreviewed. */

void FUN_40636734(int *param_1,undefined *param_2)

{
  int *piVar1;
  wchar_t *lpString;
  WPARAM WVar2;
  LRESULT LVar3;
  HWND hWnd;
  HWND hWnd_00;
  WCHAR aWStack_c0 [80];
  uint local_20;
  
  local_20 = DAT_4063a758;
  hWnd_00 = (HWND)param_1[6];
  piVar1 = FUN_4063556c(param_1);
  if (piVar1 != (int *)0x0) {
    hWnd = (HWND)piVar1[6];
    GetWindowTextW(hWnd_00,aWStack_c0,0x50);
    FUN_40634784(aWStack_c0);
    lpString = (wchar_t *)(*(code *)param_2)(aWStack_c0);
    SendMessageW(hWnd,0x14e,0xffffffff,0);
    WVar2 = SendMessageW(hWnd,0x146,0,0);
    while (WVar2 = WVar2 - 1, -1 < (int)WVar2) {
      LVar3 = SendMessageW(hWnd,0x150,WVar2,0);
      if (LVar3 != 0) {
        SendMessageW(hWnd,0x144,WVar2,0);
      }
    }
    WVar2 = FUN_40635aa0(hWnd,lpString);
    if ((int)WVar2 < 0) {
      SetWindowTextW(hWnd,lpString);
    }
    else {
      FUN_406353f4(hWnd,(LPARAM)lpString);
      SendMessageW(hWnd,0x151,0,0);
    }
    piVar1[8] = 1;
  }
  FUN_40639164(local_20);
  return;
}



/* 40636878 FUN_40636878 */

/* Boundary evidence: original MIPS .pdata 40636878..40636c03. Semantic name remains unreviewed. */

void FUN_40636878(int *param_1,undefined *param_2,undefined *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  LRESULT LVar3;
  WPARAM WVar4;
  undefined2 *puVar5;
  size_t sVar6;
  wchar_t *_Str;
  wchar_t *pwVar7;
  HWND hWnd;
  HWND hWnd_00;
  wchar_t *_Source;
  WCHAR local_178;
  undefined1 auStack_176 [14];
  wchar_t local_168;
  undefined1 auStack_166 [158];
  WCHAR local_c8;
  undefined1 auStack_c6 [158];
  uint local_28;
  
  local_28 = DAT_4063a758;
  local_178 = L'\0';
  memset(auStack_176,0,10);
  local_c8 = L'\0';
  memset(auStack_c6,0,0x9e);
  local_168 = L'\0';
  memset(auStack_166,0,0x9e);
  hWnd_00 = (HWND)param_1[6];
  piVar1 = FUN_4063556c(param_1);
  if (piVar1 != (int *)0x0) {
    hWnd = (HWND)piVar1[6];
    SendMessageW(hWnd,0xb,0,0);
    if (param_4 == 0) {
      WVar4 = SendMessageW(hWnd_00,0x147,0,0);
      iVar2 = SendMessageW(hWnd_00,0x148,WVar4,(LPARAM)&local_178);
    }
    else {
      iVar2 = GetWindowTextW(hWnd_00,&local_178,6);
    }
    if ((iVar2 == -1) && (LVar3 = SendMessageW(hWnd_00,0x148,0,(LPARAM)&local_178), LVar3 != -1)) {
      SendMessageW(hWnd_00,0x14e,0,0);
    }
    LVar3 = SendMessageW(hWnd,0x147,0,0);
    if (LVar3 == -1) {
      SendMessageW(hWnd,0x14e,0,0);
    }
    GetWindowTextW(hWnd,&local_c8,0x50);
    SendMessageW(hWnd,0x14e,0xffffffff,0);
    WVar4 = SendMessageW(hWnd,0x146,0,0);
    while (WVar4 = WVar4 - 1, -1 < (int)WVar4) {
      LVar3 = SendMessageW(hWnd,0x150,WVar4,0);
      if (LVar3 != 0) {
        SendMessageW(hWnd,0x144,WVar4,0);
      }
    }
    if ((local_178 != L'\0') &&
       (puVar5 = (undefined2 *)(*(code *)param_2)(&local_178), puVar5 != (undefined2 *)0x0)) {
      MessageBeep(0x10);
      *puVar5 = 0;
      SendMessageW(hWnd_00,0x14e,0xffffffff,0);
      SetWindowTextW(hWnd_00,&local_178);
      sVar6 = wcslen(&local_178);
      if (sVar6 != 0) {
        SendMessageW(hWnd_00,0x142,0,sVar6 << 0x10);
      }
    }
    FUN_40634784(&local_c8);
    _Str = (wchar_t *)(*(code *)param_3)(&local_c8);
    local_168 = L'\0';
    _Source = &local_c8;
    if (((_Str != (wchar_t *)0x0) && (*_Str != L'\0')) && (local_178 != L'\0')) {
      sVar6 = wcslen(_Str);
      pwVar7 = wcsstr(&local_c8,_Str);
      while (pwVar7 != (wchar_t *)0x0) {
        *pwVar7 = L'\0';
        wcscat(&local_168,_Source);
        wcscat(&local_168,&local_178);
        _Source = pwVar7 + sVar6;
        pwVar7 = wcsstr(_Source,_Str);
      }
    }
    wcscat(&local_168,_Source);
    FUN_4063468c((ushort *)&local_168);
    WVar4 = FUN_40635aa0(hWnd,&local_168);
    FUN_406353f4(hWnd,(LPARAM)&local_168);
    SendMessageW(hWnd,0x151,0,(uint)((int)WVar4 < 0));
    SendMessageW(hWnd,0xb,1,0);
    piVar1[8] = 1;
    InvalidateRect(hWnd,(RECT *)0x0,0);
  }
  FUN_40639164(local_28);
  return;
}



/* 40636c04 FUN_40636c04 */

/* Boundary evidence: original MIPS .pdata 40636c04..40636ca7. Semantic name remains unreviewed. */

void FUN_40636c04(int param_1)

{
  WPARAM wParam;
  WCHAR aWStack_b8 [82];
  uint local_14;
  
  local_14 = DAT_4063a758;
  wParam = SendMessageW(*(HWND *)(param_1 + 0x18),0x147,0,0);
  if (-1 < (int)wParam) {
    SendMessageW(*(HWND *)(param_1 + 0x18),0x148,wParam,(LPARAM)aWStack_b8);
    SendMessageW(*(HWND *)(param_1 + 0x18),0x14e,0xffffffff,0);
    SetWindowTextW(*(HWND *)(param_1 + 0x18),aWStack_b8);
    SendMessageW(*(HWND *)(param_1 + 0x18),0x14e,wParam,0);
  }
  FUN_40639164(local_14);
  return;
}



/* 40636ca8 FUN_40636ca8 */

/* Boundary evidence: original MIPS .pdata 40636ca8..40636d4b. Semantic name remains unreviewed. */

undefined4 FUN_40636ca8(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4063a9c0);
  if (DAT_4063a8d0 == (HMODULE)0x0) {
    DAT_4063a8d0 = LoadLibraryW(L"aygshell.dll");
    if (DAT_4063a8d0 != (HMODULE)0x0) {
      DAT_4063a8c8 = DAT_4063a8c8 + 1;
      uVar1 = 1;
      DAT_4063a864 = 1;
    }
  }
  else {
    DAT_4063a8c8 = DAT_4063a8c8 + 1;
    uVar1 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4063a9c0);
  return uVar1;
}



/* 40636d4c FUN_40636d4c */

/* Boundary evidence: original MIPS .pdata 40636d4c..40636de3. Semantic name remains unreviewed. */

undefined4 FUN_40636d4c(void)

{
  undefined4 uVar1;
  
  if (DAT_4063a864 == 0) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4063a9c0);
    DAT_4063a8c8 = DAT_4063a8c8 + -1;
    if (DAT_4063a8c8 < 1) {
      FreeLibrary(DAT_4063a8d0);
      DAT_4063a8d0 = (HMODULE)0x0;
      DAT_4063a8cc = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4063a9c0);
    uVar1 = 1;
  }
  return uVar1;
}



/* 40636de4 FUN_40636de4 */

/* Boundary evidence: original MIPS .pdata 40636de4..40636e97. Semantic name remains unreviewed. */

undefined4 FUN_40636de4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = 0;
  uVar3 = 0;
  memset(&local_1c,0,8);
  iVar1 = FUN_40636ca8();
  if (iVar1 != 0) {
    local_20 = 1;
    local_1c = param_1;
    local_18 = param_2;
    pcVar2 = (code *)GetProcAddressW(DAT_4063a8d0,L"SHInitDialog");
    if (pcVar2 != (code *)0x0) {
      uVar3 = (*pcVar2)(&local_20);
    }
    iVar1 = FUN_40636d4c();
    if (iVar1 != 0) {
      return uVar3;
    }
  }
  return 0;
}



/* 40636e98 FUN_40636e98 */

/* Boundary evidence: original MIPS .pdata 40636e98..40636f1b. Semantic name remains unreviewed. */

int FUN_40636e98(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = DAT_4063a8cc;
  if (DAT_4063a8d0 == 0) {
    iVar3 = 0;
  }
  else if (DAT_4063a8cc == 0) {
    pcVar2 = (code *)GetProcAddressW(DAT_4063a8d0,L"SHInitExtraControls");
    iVar1 = iVar3;
    if (pcVar2 != (code *)0x0) {
      iVar3 = (*pcVar2)();
      iVar1 = iVar3;
    }
  }
  else {
    iVar3 = 1;
  }
  DAT_4063a8cc = iVar1;
  return iVar3;
}



/* 40636f1c FUN_40636f1c */

/* Boundary evidence: original MIPS .pdata 40636f1c..40636fd7. Semantic name remains unreviewed. */

undefined4 FUN_40636f1c(HWND param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  tagWNDCLASSW tStack_38;
  
  if (((DAT_4063a8d0 == 0) || (iVar1 = FUN_40636e98(), iVar1 == 0)) ||
     (BVar2 = GetClassInfoW(DAT_4063a980,L"SIPPREF",&tStack_38), BVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    CreateWindowExW(0,L"SIPPREF",(LPCWSTR)0x0,0x40000000,-10,-10,5,5,param_1,(HMENU)0x0,DAT_4063a980
                    ,(LPVOID)0x0);
    uVar3 = 1;
  }
  return uVar3;
}



/* 40636fd8 FUN_40636fd8 */

/* Boundary evidence: original MIPS .pdata 40636fd8..4063746b. Semantic name remains unreviewed. */

undefined4 FUN_40636fd8(int *param_1,uint param_2)

{
  undefined *puVar1;
  WPARAM WVar2;
  int *piVar3;
  HWND pHVar4;
  LONG LVar5;
  code *pcVar6;
  code *pcVar7;
  int iVar8;
  int *piVar9;
  WCHAR aWStack_38 [4];
  uint local_30;
  
  local_30 = DAT_4063a758;
  if (param_2 >> 0x10 == 1) {
    iVar8 = *param_1;
    if (iVar8 == 0x3fe) {
      pHVar4 = (HWND)param_1[6];
      FUN_40632a7c();
      param_1[7] = 1;
      WVar2 = SendMessageW(pHVar4,0x147,0,0);
      DAT_4063a8e0 = SendMessageW(pHVar4,0x150,WVar2,0);
      puVar1 = PTR_DAT_4063a69c;
      if ((*(int *)(PTR_DAT_4063a69c + 0x1c) != 0) &&
         (piVar9 = *(int **)(PTR_DAT_4063a69c + 0x14),
         piVar9 != piVar9 + *(int *)(PTR_DAT_4063a69c + 0x10) * 9)) {
        do {
          if (*piVar9 == 0x3ff) {
            piVar9[7] = 1;
            piVar9[8] = 1;
          }
          piVar9 = piVar9 + 9;
        } while (piVar9 != (int *)(*(int *)(puVar1 + 0x10) * 0x24 + *(int *)(puVar1 + 0x14)));
      }
    }
    else if (iVar8 == 0x3ff) {
      FUN_40636c04((int)param_1);
      DAT_4063a97c = SendMessageW((HWND)param_1[6],0x147,0,0);
      DAT_4063a984 = 1;
    }
    else if (iVar8 == 0x42a) {
      FUN_40636c04((int)param_1);
      pcVar6 = FUN_40633fb0;
LAB_406372f4:
      FUN_40636734(param_1,pcVar6);
    }
    else {
      if (iVar8 == 0x42b) {
        FUN_40636c04((int)param_1);
        pcVar7 = FUN_40633fb0;
        pcVar6 = FUN_40633c38;
      }
      else {
        if (iVar8 == 0x43f) {
          FUN_40636c04((int)param_1);
          pcVar6 = FUN_40633fd4;
          goto LAB_406372f4;
        }
        if (iVar8 != 0x440) {
          if (iVar8 == 0x449) {
            if (DAT_4063a76c == 0) {
              DAT_4063a978 = DAT_4063a8e0;
              GetLocaleInfoW(DAT_4063a8e0,0x1009,(LPWSTR)&DAT_4063a988,2);
              DAT_4063a76c = 1;
            }
            pHVar4 = (HWND)param_1[6];
            WVar2 = SendMessageW(pHVar4,0x147,0,0);
            DAT_4063a6a8 = SendMessageW(pHVar4,0x150,WVar2,0);
            puVar1 = PTR_DAT_4063a6a0;
            if ((*(int *)(PTR_DAT_4063a6a0 + 0x88) != 0) &&
               (piVar9 = *(int **)(PTR_DAT_4063a6a0 + 0x80),
               piVar9 != piVar9 + *(int *)(PTR_DAT_4063a6a0 + 0x7c) * 9)) {
              do {
                if (((*piVar9 == 0x43f) || (*piVar9 == 0x444)) &&
                   (pHVar4 = (HWND)piVar9[6], pHVar4 != (HWND)0x0)) {
                  iVar8 = FUN_40635b78(piVar9);
                  if (iVar8 == 0) {
                    param_1[7] = 0;
                  }
                  else {
                    if (*piVar9 == 0x43f) {
                      piVar3 = FUN_4063556c(piVar9);
                      if (piVar3 == (int *)0x0) goto LAB_40637244;
                      FUN_40636878(piVar3,FUN_40633c58,FUN_40633fd4,1);
                    }
                    piVar9[8] = 1;
                    pHVar4 = GetParent(pHVar4);
                    LVar5 = GetWindowLongW(pHVar4,8);
                    (*(code *)piVar9[5])(LVar5);
                  }
                }
LAB_40637244:
                piVar9 = piVar9 + 9;
              } while (piVar9 != (int *)(*(int *)(puVar1 + 0x7c) * 0x24 + *(int *)(puVar1 + 0x80)));
            }
            wsprintfW(aWStack_38,L"%d",DAT_4063a6a8 & 0xff);
            SetLocaleInfoW(DAT_4063a8e0,0x1009,aWStack_38);
            PostMessageW((HWND)0xffff,0x1a,0,1);
          }
          else {
            FUN_40636c04((int)param_1);
          }
          goto LAB_4063740c;
        }
        FUN_40636c04((int)param_1);
        pcVar7 = FUN_40633fd4;
        pcVar6 = FUN_40633c58;
      }
      FUN_40636878(param_1,pcVar6,pcVar7,0);
    }
LAB_4063740c:
    param_1[8] = 1;
  }
  else {
    if (param_2 >> 0x10 != 5) goto LAB_40637430;
    param_1[8] = 1;
    if (*param_1 == 0x42b) {
      pcVar7 = FUN_40633fb0;
      pcVar6 = FUN_40633c38;
    }
    else {
      if (*param_1 != 0x440) {
        FUN_40635470((int)param_1);
        goto LAB_40637410;
      }
      pcVar7 = FUN_40633fd4;
      pcVar6 = FUN_40633c58;
    }
    FUN_40636878(param_1,pcVar6,pcVar7,1);
  }
LAB_40637410:
  pHVar4 = GetParent((HWND)param_1[6]);
  LVar5 = GetWindowLongW(pHVar4,8);
  (*(code *)param_1[5])(LVar5);
LAB_40637430:
  FUN_40639164(local_30);
  return 1;
}



/* 4063746c FUN_4063746c */

/* Boundary evidence: original MIPS .pdata 4063746c..40637623. Semantic name remains unreviewed. */

undefined4 FUN_4063746c(HWND param_1,int param_2,uint param_3,int param_4)

{
  LONG LVar1;
  HWND pHVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  
  if (param_2 == 2) {
    LVar1 = GetWindowLongW(param_1,8);
    if (LVar1 != 0) {
      *(undefined4 *)(LVar1 + 0x1c) = 0;
    }
    FUN_40636d4c();
  }
  else {
    if (param_2 == 0x110) {
      *(HWND *)(param_4 + 0x1c) = param_1;
      FUN_40636ca8();
      FUN_40636f1c(param_1);
      SetWindowLongW(param_1,8,param_4);
      piVar6 = *(int **)(param_4 + 0x14);
      if (piVar6 != piVar6 + *(int *)(param_4 + 0x10) * 9) {
        do {
          pHVar2 = GetDlgItem(param_1,*piVar6);
          piVar6[6] = (int)pHVar2;
          piVar6 = piVar6 + 9;
        } while (piVar6 != (int *)(*(int *)(param_4 + 0x10) * 0x24 + *(int *)(param_4 + 0x14)));
      }
      FUN_40632798(param_4);
      (**(code **)(param_4 + 0xc))(param_4);
      return 1;
    }
    if (param_2 == 0x111) {
      uVar5 = param_3 & 0xffff;
      if ((uVar5 != 0) && (uVar5 < 3)) {
        PostMessageW(DAT_4063a8e4,0x111,param_3,param_4);
        return 1;
      }
      LVar1 = GetWindowLongW(param_1,8);
      if (LVar1 != 0) {
        puVar3 = *(uint **)(LVar1 + 0x14);
        puVar4 = puVar3 + *(int *)(LVar1 + 0x10) * 9;
        for (; puVar3 != puVar4; puVar3 = puVar3 + 9) {
          if (*puVar3 == uVar5) {
            FUN_40636fd8((int *)puVar3,param_3);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}



/* 40637624 FUN_40637624 */

/* Boundary evidence: original MIPS .pdata 40637624..40637713. Semantic name remains unreviewed. */

void FUN_40637624(HWND param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_2 == 0x110) {
    FUN_40636de4(param_1,8);
  }
  else if (((param_2 == 0x111) && ((param_3 & 0xffff) == 0x4b0)) &&
          (iVar1 = FUN_406344b4(), iVar1 != 0)) {
    iVar1 = 0;
    puVar2 = PTR_DAT_4063a69c;
    do {
      if (*(HWND *)(puVar2 + iVar1 + 0x1c) != (HWND)0x0) {
        ShowWindow(*(HWND *)(puVar2 + iVar1 + 0x1c),0);
        puVar2 = PTR_DAT_4063a69c;
      }
      iVar1 = iVar1 + 0x24;
    } while (iVar1 < 0x6c);
    FUN_40632cbc();
  }
  FUN_4063746c(param_1,param_2,param_3,param_4);
  return;
}



/* 40637714 FUN_40637714 */

/* Boundary evidence: original MIPS .pdata 40637714..4063778b. Semantic name remains unreviewed. */

void FUN_40637714(HWND param_1,int param_2,uint param_3,int param_4)

{
  HWND hWnd;
  
  if (param_2 == 0x110) {
    hWnd = GetDlgItem(param_1,0x3ff);
    EnableWindow(hWnd,0);
  }
  FUN_4063746c(param_1,param_2,param_3,param_4);
  return;
}



/* 4063778c FUN_4063778c */

/* Boundary evidence: original MIPS .pdata 4063778c..406377a7. Semantic name remains unreviewed. */

void FUN_4063778c(HWND param_1,int param_2,uint param_3,int param_4)

{
  FUN_4063746c(param_1,param_2,param_3,param_4);
  return;
}



/* 406377a8 FUN_406377a8 */

/* Boundary evidence: original MIPS .pdata 406377a8..40637817. Semantic name remains unreviewed. */

ulong FUN_406377a8(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  ulong uVar2;
  size_t local_18;
  wchar_t *pwStack_14;
  
  uVar2 = 0;
  if (((param_1 != (STRSAFE_PCNZWCH)0x0) &&
      (HVar1 = StringCchLengthW(param_1,9,&local_18), -1 < HVar1)) && (local_18 == 8)) {
    uVar2 = wcstoul(param_1,&pwStack_14,0x10);
  }
  return uVar2;
}



/* 40637818 FUN_40637818 */

/* Boundary evidence: original MIPS .pdata 40637818..40637867. Semantic name remains unreviewed. */

wchar_t * FUN_40637818(int param_1,wchar_t *param_2)

{
  wchar_t *pwVar1;
  
  pwVar1 = (wchar_t *)0x0;
  if ((param_1 != 0) && (param_2 != (wchar_t *)0x0)) {
    param_2[8] = L'\0';
    _snwprintf(param_2,8,L"%08X",param_1);
    pwVar1 = param_2;
  }
  return pwVar1;
}



/* 40637868 FUN_40637868 */

bool FUN_40637868(uint param_1)

{
  return (param_1 & 0xff000000) == 0xe0000000;
}



/* 40637888 FUN_40637888 */

/* Boundary evidence: original MIPS .pdata 40637888..40637a03. Semantic name remains unreviewed. */

undefined4 FUN_40637888(int param_1,wchar_t *param_2)

{
  LSTATUS LVar1;
  wchar_t *pwVar2;
  int iVar3;
  undefined4 uVar4;
  HKEY local_250;
  HKEY local_24c;
  DWORD local_248;
  DWORD local_244;
  wchar_t awStack_240 [12];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_4063a758;
  uVar4 = 0;
  local_250 = (HKEY)0x0;
  local_24c = (HKEY)0x0;
  if ((param_1 != 0) && (param_2 != (wchar_t *)0x0)) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\CurrentControlSet\\Control\\Layouts",0,0,
                          &local_250);
    if ((LVar1 == 0) && (pwVar2 = FUN_40637818(param_1,awStack_240), pwVar2 != (wchar_t *)0x0)) {
      LVar1 = RegOpenKeyExW(local_250,awStack_240,0,0,&local_24c);
      if (LVar1 == 0) {
        local_248 = 0x208;
        LVar1 = RegQueryValueExW(local_24c,L"Ime File",(LPDWORD)0x0,&local_244,(LPBYTE)awStack_228,
                                 &local_248);
        if (((LVar1 == 0) && (local_244 == 1)) && (iVar3 = wcscmp(awStack_228,param_2), iVar3 == 0))
        {
          uVar4 = 1;
        }
      }
    }
    if (local_250 != (HKEY)0x0) {
      RegCloseKey(local_250);
    }
    if (local_24c != (HKEY)0x0) {
      RegCloseKey(local_24c);
    }
  }
  FUN_40639164(local_20);
  return uVar4;
}



/* 40637a04 FUN_40637a04 */

/* Boundary evidence: original MIPS .pdata 40637a04..40637a7b. Semantic name remains unreviewed. */

undefined4 FUN_40637a04(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == -0x1ffef7fc) && (iVar1 = FUN_40637888(-0x1ffef7fc,L"msimesp.dll"), iVar1 != 0))
     || ((param_1 == -0x1ffdf7fc && (iVar1 = FUN_40637888(-0x1ffdf7fc,L"msimepy.dll"), iVar1 != 0)))
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40637a7c FUN_40637a7c */

/* Boundary evidence: original MIPS .pdata 40637a7c..40637af3. Semantic name remains unreviewed. */

undefined4 FUN_40637a7c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == -0x1ffefbfc) && (iVar1 = FUN_40637888(-0x1ffefbfc,L"msimeph.dll"), iVar1 != 0))
     || ((param_1 == -0x1ffdfbfc && (iVar1 = FUN_40637888(-0x1ffdfbfc,L"msimecj.dll"), iVar1 != 0)))
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40637af4 FUN_40637af4 */

uint FUN_40637af4(uint param_1)

{
  uint uVar1;
  
  if ((((param_1 & 0xff000000) != 0xe0000000) || (DAT_4063a8b0 == param_1)) ||
     (DAT_4063a868 == param_1)) {
    uVar1 = 0;
    if (0 < DAT_4063a8b4) {
      do {
        if (0xe < (uVar1 & 0xffff)) {
          return 0xffffffff;
        }
        if (param_1 == (&DAT_4063a874)[uVar1]) {
          return uVar1;
        }
        uVar1 = (int)((uVar1 + 1) * 0x10000) >> 0x10;
      } while ((int)uVar1 < (int)DAT_4063a8b4);
    }
  }
  return 0xffffffff;
}



/* 40637b84 FUN_40637b84 */

/* Boundary evidence: original MIPS .pdata 40637b84..40637deb. Semantic name remains unreviewed. */

undefined4 FUN_40637b84(int param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  LSTATUS LVar1;
  wchar_t *pwVar2;
  HRESULT HVar3;
  uint uVar4;
  STRSAFE_LPCWSTR pszSrc;
  undefined4 uVar5;
  HKEY local_260;
  DWORD local_25c;
  HKEY local_258;
  DWORD local_254;
  wchar_t awStack_250 [12];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_4063a758;
  uVar5 = 0;
  local_258 = (HKEY)0x0;
  pszSrc = (STRSAFE_LPCWSTR)0x0;
  local_260 = (HKEY)0x0;
  if ((param_2 == (STRSAFE_LPWSTR)0x0) || (param_3 == 0)) goto LAB_40637db4;
  uVar4 = 0;
  do {
    if (param_1 == (&DAT_406318a0)[uVar4]) {
      pszSrc = (STRSAFE_LPCWSTR)LoadStringW(DAT_4063a980,uVar4 + 0x4000,(LPWSTR)0x0,0);
      if (pszSrc != (STRSAFE_LPCWSTR)0x0) goto LAB_40637d60;
      break;
    }
    uVar4 = (int)((uVar4 + 1) * 0x10000) >> 0x10;
  } while ((uVar4 & 0xffff) < 0xe);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SYSTEM\\CurrentControlSet\\Control\\Layouts",0,0,
                        &local_258);
  if (((LVar1 == 0) && (pwVar2 = FUN_40637818(param_1,awStack_250), pwVar2 != (wchar_t *)0x0)) &&
     (LVar1 = RegOpenKeyExW(local_258,awStack_250,0,0,&local_260), LVar1 == 0)) {
    local_254 = 0x208;
    LVar1 = RegQueryValueExW(local_260,L"Layout Display Name",(LPDWORD)0x0,&local_25c,
                             (LPBYTE)aWStack_238,&local_254);
    if (((LVar1 != 0) || (local_25c != 1)) ||
       (HVar3 = SHLoadIndirectString(aWStack_238,aWStack_238,0x104,(void **)0x0), HVar3 < 0)) {
      local_254 = 0x208;
      LVar1 = RegQueryValueExW(local_260,L"Layout Text",(LPDWORD)0x0,&local_25c,(LPBYTE)aWStack_238,
                               &local_254);
      if ((LVar1 != 0) || (local_25c != 1)) goto LAB_40637d60;
    }
    pszSrc = aWStack_238;
  }
LAB_40637d60:
  if (local_260 != (HKEY)0x0) {
    RegCloseKey(local_260);
  }
  if (local_258 != (HKEY)0x0) {
    RegCloseKey(local_258);
  }
  if (pszSrc != (STRSAFE_LPCWSTR)0x0) {
    HVar3 = StringCchCopyW(param_2,param_3,pszSrc);
    uVar5 = 1;
    if (HVar3 < 0) {
      uVar5 = 0;
    }
  }
LAB_40637db4:
  FUN_40639164(local_30);
  return uVar5;
}



/* 40637dec FUN_40637dec */

/* Boundary evidence: original MIPS .pdata 40637dec..406384ab. Semantic name remains unreviewed. */

void FUN_40637dec(HWND param_1)

{
  bool bVar1;
  HKEY pHVar2;
  ulong uVar3;
  uint uVar4;
  LSTATUS LVar5;
  int iVar6;
  HWND hWnd;
  wchar_t *pwVar7;
  WPARAM wParam;
  HWND hWnd_00;
  WPARAM WVar8;
  LONG LVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  WPARAM WVar14;
  int iVar15;
  DWORD dwIndex;
  HKEY local_2c8;
  HKEY local_2c4;
  DWORD local_2c0;
  HWND local_2bc;
  DWORD local_2b8;
  HWND local_2b4;
  undefined4 local_2b0 [2];
  undefined4 local_2a8;
  wchar_t *local_29c;
  undefined4 local_298;
  ulong local_290;
  undefined1 auStack_280 [12];
  undefined4 local_274;
  undefined4 local_270;
  wchar_t awStack_250 [8];
  undefined2 local_240;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_4063a758;
  bVar1 = false;
  local_2c4 = (HKEY)0x0;
  local_2c8 = (HKEY)0x406317ac;
  local_2bc = param_1;
  LVar5 = RegOpenKeyExW((HKEY)0x80000001,L"Keyboard Layout\\Preload",0,0,&local_2c4);
  if (LVar5 == 0) {
    local_2c0 = 0x12;
    LVar5 = RegQueryValueExW(local_2c4,(LPCWSTR)0x0,(LPDWORD)0x0,&local_2b8,(LPBYTE)awStack_250,
                             &local_2c0);
    if ((LVar5 == 0) && (local_2b8 == 1)) {
      DAT_4063a8c4 = FUN_406377a8(awStack_250);
    }
  }
  memset(&DAT_4063a874,0,0x3c);
  iVar6 = GetKeyboardLayoutList(0xf,(HKL *)&DAT_4063a874);
  DAT_4063a8b4 = (short)iVar6;
  if (0 < DAT_4063a8b4) {
    iVar6 = 0;
    do {
      if ((((&DAT_4063a874)[iVar6] & 0xff000000) == 0xe0000000) &&
         ((uVar10 = (&DAT_4063a874)[iVar6] & 0xffff, uVar10 == 0x411 || (uVar10 == 0x412)))) {
        bVar1 = true;
      }
      iVar6 = (iVar6 + 1) * 0x10000 >> 0x10;
    } while (iVar6 < DAT_4063a8b4);
  }
  DAT_4063a8b0 = 0;
  DAT_4063a868 = 0;
  hWnd = GetDlgItem(param_1,0x400);
  local_2b4 = hWnd;
  if (hWnd != (HWND)0x0) {
    iVar6 = (int)DAT_4063a8b4;
    if (0 < iVar6) {
      iVar15 = 0;
      uVar10 = DAT_4063a8b0;
      uVar11 = DAT_4063a868;
      uVar12 = DAT_4063a8c4;
      WVar8 = 0xffffffff;
      do {
        puVar13 = &DAT_4063a874 + iVar15;
        WVar14 = WVar8;
        if ((*puVar13 & 0xff000000) == 0xe0000000) {
          if (uVar10 == 0) {
            if (((uVar12 & 0xff000000) == 0xe0000000) && (uVar12 != *puVar13)) {
              iVar6 = FUN_40637a04(uVar12);
              if (((iVar6 == 0) || (iVar6 = FUN_40637a04(*puVar13), iVar6 == 0)) &&
                 ((iVar6 = FUN_40637a7c(DAT_4063a8c4), iVar6 == 0 ||
                  (iVar6 = FUN_40637a7c(*puVar13), iVar6 == 0)))) {
                iVar6 = (int)DAT_4063a8b4;
                uVar10 = DAT_4063a8b0;
                uVar11 = DAT_4063a868;
                uVar12 = DAT_4063a8c4;
                goto LAB_40638040;
              }
LAB_40638088:
              iVar6 = (int)DAT_4063a8b4;
              uVar10 = DAT_4063a8b0;
              uVar11 = DAT_4063a868;
              uVar12 = DAT_4063a8c4;
            }
            goto LAB_4063809c;
          }
LAB_40638040:
          uVar4 = DAT_4063a868;
          if (uVar11 == 0) {
            iVar6 = FUN_40637a04(uVar10);
            if (((iVar6 != 0) && (iVar6 = FUN_40637a04(*puVar13), iVar6 != 0)) ||
               ((iVar6 = FUN_40637a7c(DAT_4063a8b0), iVar6 != 0 &&
                (iVar6 = FUN_40637a7c(*puVar13), iVar6 != 0)))) goto LAB_40638088;
            goto LAB_406381a8;
          }
        }
        else {
LAB_4063809c:
          if ((!bVar1) || ((uVar4 = DAT_4063a868, *puVar13 != 0x411 && (*puVar13 != 0x412)))) {
            iVar6 = FUN_40637b84(*puVar13,awStack_238,0x104);
            if (iVar6 == 0) {
LAB_406381a8:
              iVar6 = (int)DAT_4063a8b4;
              WVar14 = WVar8;
              uVar11 = DAT_4063a8b0;
            }
            else {
              pwVar7 = wcschr(awStack_238,L'$');
              if (pwVar7 != (wchar_t *)0x0) {
                *pwVar7 = L'-';
              }
              wParam = SendMessageW(hWnd,0x143,0,(LPARAM)awStack_238);
              if (wParam == 0xffffffff) goto LAB_406381a8;
              SendMessageW(hWnd,0x151,wParam,*puVar13);
              uVar11 = *puVar13;
              WVar14 = wParam;
              if (((DAT_4063a8c4 != uVar11) && (WVar14 = WVar8, WVar8 != 0xffffffff)) &&
                 ((int)wParam <= (int)WVar8)) {
                WVar14 = WVar8 + 1;
              }
              WVar8 = WVar14;
              if ((uVar11 & 0xff000000) != 0xe0000000) goto LAB_406381a8;
              iVar6 = (int)DAT_4063a8b4;
              uVar10 = DAT_4063a8b0;
              uVar12 = DAT_4063a8c4;
              uVar4 = uVar11;
              if (DAT_4063a8b0 != 0) goto LAB_406381b0;
            }
            DAT_4063a8b0 = uVar11;
            uVar10 = DAT_4063a8b0;
            uVar11 = DAT_4063a868;
            uVar12 = DAT_4063a8c4;
            uVar4 = DAT_4063a868;
          }
        }
LAB_406381b0:
        DAT_4063a868 = uVar4;
        param_1 = local_2bc;
        iVar15 = (iVar15 + 1) * 0x10000 >> 0x10;
        WVar8 = WVar14;
      } while (iVar15 < iVar6);
      if (WVar14 != 0xffffffff) {
        SendMessageW(hWnd,0x14e,WVar14,0);
      }
    }
  }
  hWnd_00 = GetDlgItem(param_1,0x514);
  pHVar2 = local_2c8;
  if (hWnd_00 != (HWND)0x0) {
    local_2c8 = (HKEY)0x0;
    uVar10 = GetWindowLongW(hWnd_00,-0x10);
    SetWindowLongW(hWnd_00,-0x10,uVar10 & 0xfffffffe | 0x200002);
    SendMessageW(hWnd_00,0x101e,0,0xffff);
    SendMessageW(hWnd_00,0x1036,0x10000004,0x10000004);
    LVar5 = RegOpenKeyExW((HKEY)0x80000002,(LPCWSTR)(pHVar2 + -0x15),0,0,&local_2c8);
    if (LVar5 == 0) {
      local_2b0[0] = 5;
      dwIndex = 0;
      local_2a8 = 0;
      while( true ) {
        local_2c0 = 9;
        LVar5 = RegEnumKeyExW(local_2c8,dwIndex,awStack_250,&local_2c0,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,(PFILETIME)0x0);
        hWnd = local_2b4;
        param_1 = local_2bc;
        if (LVar5 != 0) break;
        local_240 = 0;
        dwIndex = dwIndex + 1;
        local_290 = FUN_406377a8(awStack_250);
        if (((local_290 != 0) && (local_290 != 0x411)) &&
           ((local_290 != 0x412 && (iVar6 = FUN_40637b84(local_290,awStack_238,0x104), iVar6 != 0)))
           ) {
          pwVar7 = wcschr(awStack_238,L'$');
          if (pwVar7 != (wchar_t *)0x0) {
            *pwVar7 = L'-';
          }
          local_29c = awStack_238;
          local_298 = 0x104;
          WVar8 = SendMessageW(hWnd_00,0x104d,0,(LPARAM)local_2b0);
          uVar3 = local_290;
          if ((WVar8 != 0xffffffff) && (uVar10 = FUN_40637af4(local_290), uVar10 != 0xffffffff)) {
            if (DAT_4063a8b0 == uVar3) {
              DAT_4063a870 = SendMessageW(hWnd_00,0x10b4,WVar8,0);
            }
            else if (DAT_4063a868 == uVar3) {
              DAT_4063a86c = SendMessageW(hWnd_00,0x10b4,WVar8,0);
            }
            local_270 = 0xf000;
            local_274 = 0x2000;
            SendMessageW(hWnd_00,0x102b,WVar8,(LPARAM)auStack_280);
          }
        }
      }
    }
    if (local_2c8 != (HKEY)0x0) {
      RegCloseKey(local_2c8);
    }
  }
  LVar9 = GetWindowLongW(param_1,8);
  if (LVar9 != 0) {
    *(HWND *)(LVar9 + 0x1c) = param_1;
    *(HWND *)(*(int *)(LVar9 + 0x14) + 0x18) = hWnd;
    *(undefined4 *)(*(int *)(LVar9 + 0x14) + 0x1c) = 1;
  }
  if (local_2c4 != (HKEY)0x0) {
    RegCloseKey(local_2c4);
  }
  FUN_40639164(local_30);
  return;
}



/* 406384ac FUN_406384ac */

/* Boundary evidence: original MIPS .pdata 406384ac..40638503. Semantic name remains unreviewed. */

undefined4 FUN_406384ac(HWND param_1,uint param_2)

{
  LONG LVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((((param_2 & 0xffff) == 0x400) && (uVar2 = 1, param_2 >> 0x10 == 1)) &&
     (LVar1 = GetWindowLongW(param_1,8), LVar1 != 0)) {
    *(undefined4 *)(*(int *)(LVar1 + 0x14) + 0x20) = 1;
  }
  return uVar2;
}



/* 40638504 FUN_40638504 */

/* Boundary evidence: original MIPS .pdata 40638504..40638a7b. Semantic name remains unreviewed. */

undefined4 FUN_40638504(HWND param_1,undefined4 param_2,undefined4 *param_3)

{
  HWND hWnd;
  LONG LVar1;
  LRESULT LVar2;
  LRESULT LVar3;
  int iVar4;
  WPARAM WVar5;
  BOOL bEnable;
  uint uVar6;
  WPARAM WVar7;
  undefined4 uVar8;
  int dwNewLong;
  undefined1 auStack_470 [8];
  undefined4 local_468;
  undefined4 local_464;
  undefined4 local_460;
  WCHAR *local_45c;
  undefined4 local_458;
  WCHAR local_440;
  undefined1 auStack_43e [516];
  undefined2 local_23a;
  WCHAR local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
  local_30 = DAT_4063a758;
  uVar8 = 0;
  if ((param_3 == (undefined4 *)0x0) || (param_3[1] != 0x514)) goto LAB_40638a40;
  if (param_3[2] == -0x65) {
    if ((DAT_4063a8b8 != 0) && (DAT_4063a8bc == 0)) {
      local_238 = L'\0';
      memset(auStack_236,0,0x206);
      local_440 = L'\0';
      memset(auStack_43e,0,0x206);
      LoadStringW(DAT_4063a980,0x2f15,&local_238,0x104);
      LoadStringW(DAT_4063a980,0x2f17,&local_440,0x104);
      MessageBoxW(DAT_4063a8e4,&local_440,&local_238,0);
      DAT_4063a8b8 = 0;
    }
    goto LAB_40638a40;
  }
  if (param_3[2] != -100) {
    uVar8 = 0;
    goto LAB_40638a40;
  }
  dwNewLong = 0;
  if (((param_3[7] & 8) == 0) || (hWnd = GetDlgItem(param_1,0x400), hWnd == (HWND)0x0))
  goto LAB_40638a40;
  uVar8 = 1;
  LVar1 = GetWindowLongW(param_1,8);
  LVar2 = SendMessageW(hWnd,0x146,0,0);
  if (((param_3[6] & 0xf000) == 0x1000) && ((param_3[5] & 0xf000) == 0x2000)) {
    dwNewLong = 1;
    if (LVar2 < 0xf) {
      WVar7 = 0;
      if (0 < LVar2) {
        do {
          LVar3 = SendMessageW(hWnd,0x150,WVar7,0);
          if (param_3[10] == LVar3) {
            dwNewLong = 0;
            goto LAB_40638974;
          }
          WVar7 = WVar7 + 1;
        } while ((int)WVar7 < LVar2);
      }
      local_45c = &local_440;
      local_468 = 0;
      local_458 = 0x104;
      SendMessageW((HWND)*param_3,0x1073,param_3[3],(LPARAM)auStack_470);
      local_23a = 0x4c00;
      WVar7 = SendMessageW(hWnd,0x143,0,(LPARAM)&local_440);
      if (WVar7 != 0xffffffff) {
        SendMessageW(hWnd,0x151,WVar7,param_3[10]);
        DAT_4063a8b8 = (uint)((param_3[10] & 0xff000000) == 0xe0000000);
        dwNewLong = 0;
        LVar2 = LVar2 + 1;
        if (DAT_4063a8b8 != 0) {
          if (DAT_4063a8b0 != 0) {
            iVar4 = FUN_40637a04(DAT_4063a8b0);
            if (((iVar4 != 0) && (iVar4 = FUN_40637a04(param_3[10]), iVar4 != 0)) ||
               ((iVar4 = FUN_40637a7c(DAT_4063a8b0), iVar4 != 0 &&
                (iVar4 = FUN_40637a7c(param_3[10]), iVar4 != 0)))) {
              DAT_4063a868 = param_3[10];
              DAT_4063a86c = SendMessageW((HWND)*param_3,0x10b4,param_3[3],0);
              goto LAB_40638800;
            }
            DAT_4063a8bc = 1;
            if (DAT_4063a868 != 0) {
              WVar7 = SendMessageW((HWND)*param_3,0x10b5,DAT_4063a86c,0);
              local_460 = 0xf000;
              local_464 = 0x1000;
              SendMessageW((HWND)*param_3,0x102b,WVar7,(LPARAM)auStack_470);
            }
            WVar7 = SendMessageW((HWND)*param_3,0x10b5,DAT_4063a870,0);
            local_460 = 0xf000;
            local_464 = 0x1000;
            SendMessageW((HWND)*param_3,0x102b,WVar7,(LPARAM)auStack_470);
            DAT_4063a8bc = 0;
          }
          DAT_4063a8b0 = param_3[10];
          DAT_4063a870 = SendMessageW((HWND)*param_3,0x10b4,param_3[3],0);
        }
LAB_40638800:
        if (LVar1 != 0) {
          *(undefined4 *)(*(int *)(LVar1 + 0x14) + 0x20) = 1;
        }
      }
    }
LAB_40638974:
    bEnable = 1;
    if (LVar2 < 2) goto LAB_40638980;
  }
  else {
    if (((param_3[6] & 0xf000) != 0x2000) || ((param_3[5] & 0xf000) != 0x1000)) goto LAB_40638974;
    dwNewLong = 1;
    if (1 < LVar2) {
      WVar7 = 0;
      if (0 < LVar2) {
        do {
          LVar3 = SendMessageW(hWnd,0x150,WVar7,0);
          if (param_3[10] == LVar3) {
            WVar5 = SendMessageW(hWnd,0x147,0,0);
            LVar3 = SendMessageW(hWnd,0x144,WVar7,0);
            if (LVar3 != -1) {
              uVar6 = param_3[10];
              DAT_4063a8b8 = (uint)((uVar6 & 0xff000000) == 0xe0000000);
              dwNewLong = 0;
              LVar2 = LVar2 + -1;
              if (DAT_4063a8b8 != 0) {
                if (DAT_4063a8b0 == uVar6) {
                  if (DAT_4063a868 == 0) {
                    DAT_4063a8b0 = 0;
                  }
                  else {
                    DAT_4063a8b0 = DAT_4063a868;
                    DAT_4063a870 = DAT_4063a86c;
LAB_40638940:
                    DAT_4063a868 = 0;
                  }
                }
                else if (DAT_4063a868 == uVar6) goto LAB_40638940;
              }
              if (LVar1 != 0) {
                *(undefined4 *)(*(int *)(LVar1 + 0x14) + 0x20) = 1;
              }
              if (WVar7 == WVar5) {
                SendMessageW(hWnd,0x14e,0,0);
              }
            }
            break;
          }
          WVar7 = WVar7 + 1;
        } while ((int)WVar7 < LVar2);
      }
      goto LAB_40638974;
    }
LAB_40638980:
    bEnable = 0;
  }
  EnableWindow(hWnd,bEnable);
  if (dwNewLong != 0) {
    SetWindowLongW(param_1,0,dwNewLong);
  }
LAB_40638a40:
  FUN_40639164(local_30);
  return uVar8;
}



/* 40638a7c FUN_40638a7c */

/* Boundary evidence: original MIPS .pdata 40638a7c..40638bab. Semantic name remains unreviewed. */

undefined4 FUN_40638a7c(HWND param_1,int param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  LONG LVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  if (param_2 == 2) {
    LVar2 = GetWindowLongW(param_1,8);
    if (LVar2 != 0) {
      *(undefined4 *)(LVar2 + 0x1c) = 0;
    }
    SetWindowLongW(param_1,8,0);
  }
  else if (param_2 == 0x4e) {
    uVar3 = FUN_40638504(param_1,param_3,param_4);
  }
  else if (param_2 == 0x110) {
    SetWindowLongW(param_1,8,(LONG)param_4);
    FUN_40637dec(param_1);
  }
  else {
    if (param_2 == 0x111) {
      iVar1 = FUN_406384ac(param_1,param_3);
      if (iVar1 != 0) {
        return 1;
      }
      if (((param_3 & 0xffff) != 0) && ((param_3 & 0xffff) < 3)) {
        PostMessageW(DAT_4063a8e4,0x111,param_3,(LPARAM)param_4);
        return 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* 40638ffc entry */

/* Boundary evidence: original MIPS .pdata 40638ffc..4063906f. Semantic name remains unreviewed. */

undefined4 entry(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_40639070();
    FUN_40639344();
  }
  uVar1 = FUN_40631908(param_1,param_2);
  if (param_2 == 0) {
    FUN_406392cc();
  }
  return uVar1;
}



/* 40639070 FUN_40639070 */

/* Boundary evidence: original MIPS .pdata 40639070..406390e3. Semantic name remains unreviewed. */

void FUN_40639070(void)

{
  uint uVar1;
  
  if ((DAT_4063a758 == 0) || (DAT_4063a758 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4063a758 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4063a758 == 0) {
      DAT_4063a758 = 0xb064;
    }
  }
  DAT_4063a75c = ~DAT_4063a758;
  return;
}



/* 406390e4 FUN_406390e4 */

/* Boundary evidence: original MIPS .pdata 406390e4..40639137. Semantic name remains unreviewed. */

void FUN_406390e4(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40639164(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40639138 FUN_40639138 */

/* Boundary evidence: original MIPS .pdata 40639138..40639163. Semantic name remains unreviewed. */

undefined4 FUN_40639138(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_406390e4(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40639164 FUN_40639164 */

/* Boundary evidence: original MIPS .pdata 40639164..406391ab. Semantic name remains unreviewed. */

void FUN_40639164(uint param_1)

{
  if ((param_1 == DAT_4063a758) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 406391ac FUN_406391ac */

/* Boundary evidence: original MIPS .pdata 406391ac..406392cb. Semantic name remains unreviewed. */

void FUN_406391ac(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_4063a8c0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_4063a9dc;
    if (DAT_4063a9dc != (undefined4 *)0x0) {
      while (DAT_4063a9d8 = DAT_4063a9d8 + -1, _Memory <= DAT_4063a9d8) {
        if ((code *)*DAT_4063a9d8 != (code *)0x0) {
          (*(code *)*DAT_4063a9d8)();
          _Memory = DAT_4063a9dc;
        }
      }
      free(_Memory);
      DAT_4063a9d8 = (undefined4 *)0x0;
      DAT_4063a9dc = (undefined4 *)0x0;
    }
    FUN_406392f0((undefined4 *)&DAT_40631010,(undefined4 *)&DAT_40631014);
  }
  FUN_406392f0((undefined4 *)&DAT_40631018,(undefined4 *)&DAT_4063101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_4063a9e0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 406392cc FUN_406392cc */

/* Boundary evidence: original MIPS .pdata 406392cc..406392ef. Semantic name remains unreviewed. */

void FUN_406392cc(void)

{
  FUN_406391ac(0,0,1);
  return;
}



/* 406392f0 FUN_406392f0 */

/* Boundary evidence: original MIPS .pdata 406392f0..40639343. Semantic name remains unreviewed. */

void FUN_406392f0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40639344 FUN_40639344 */

/* Boundary evidence: original MIPS .pdata 40639344..4063937f. Semantic name remains unreviewed. */

void FUN_40639344(void)

{
  FUN_406392f0((undefined4 *)&DAT_40631008,(undefined4 *)&DAT_4063100c);
  FUN_406392f0((undefined4 *)&DAT_40631000,(undefined4 *)&DAT_40631004);
  return;
}


