/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 402d3030 FUN_402d3030 */

/* Boundary evidence: original MIPS .pdata 402d3030..402d3683. Semantic name remains unreviewed. */

undefined4 FUN_402d3030(HWND param_1,int param_2,uint param_3,HWND param_4)

{
  LONG LVar1;
  HWND pHVar2;
  LRESULT LVar3;
  HWND pHVar4;
  uint uVar5;
  LPARAM lParam;
  int iVar6;
  int dwNewLong;
  LPARAM *lParam_00;
  WCHAR aWStack_420 [256];
  WCHAR aWStack_220 [256];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  if (param_2 == 0x4e) {
    if ((param_4[2].unused == -0xca) && (LVar1 = GetWindowLongW(param_1,-0x15), LVar1 != 0)) {
      pHVar2 = GetDlgItem(param_1,0x3eb);
      LVar3 = SendMessageW(pHVar2,0xf0,0,0);
      *(LRESULT *)(LVar1 + 4) = LVar3;
      if (LVar3 == 0) {
        pHVar2 = GetDlgItem(param_1,0x3e9);
        SendMessageW(pHVar2,0x466,0,(LPARAM)(LVar1 + 0xc));
        pHVar2 = GetDlgItem(param_1,0x3ee);
        SendMessageW(pHVar2,0x466,0,LVar1 + 0x10);
        pHVar2 = GetDlgItem(param_1,0x3f0);
        SendMessageW(pHVar2,0x466,0,LVar1 + 0x14);
        iVar6 = *(int *)(LVar1 + 0xc);
        if (((iVar6 == 0) || (iVar6 == 0x7f000001)) || (iVar6 == -1)) {
          LoadStringW(DAT_402fc3c4,2,aWStack_420,0x100);
          LoadStringW(DAT_402fc3c4,0x15,aWStack_220,0x100);
          MessageBoxW(param_1,aWStack_220,aWStack_420,0x30);
          SetWindowLongW(param_1,0,2);
          FUN_402f41d8(local_20);
          return 1;
        }
      }
      else {
        *(undefined4 *)(LVar1 + 0xc) = 0;
        *(undefined4 *)(LVar1 + 0x10) = 0;
        *(undefined4 *)(LVar1 + 0x14) = 0;
      }
      *(undefined4 *)(LVar1 + 8) = 1;
      SetWindowLongW(param_1,0,0);
    }
    goto LAB_402d3188;
  }
  if (param_2 == 0x110) {
    pHVar2 = GetParent(param_1);
    pHVar4 = GetWindow(pHVar2,4);
    if (pHVar4 == (HWND)0x0) {
      uVar5 = GetWindowLongW(pHVar2,-0x14);
      SetWindowLongW(pHVar2,-0x14,uVar5 | 8);
    }
    SetWindowLongW(param_1,-0x15,param_4[7].unused);
    dwNewLong = param_4[7].unused;
    SetWindowLongW(param_1,8,dwNewLong);
    iVar6 = *(int *)(dwNewLong + 4);
    pHVar2 = GetDlgItem(param_1,0x3e9);
    EnableWindow(pHVar2,(uint)(iVar6 == 0));
    iVar6 = *(int *)(dwNewLong + 4);
    pHVar2 = GetDlgItem(param_1,1000);
    EnableWindow(pHVar2,(uint)(iVar6 == 0));
    iVar6 = *(int *)(dwNewLong + 4);
    pHVar2 = GetDlgItem(param_1,0x3ee);
    EnableWindow(pHVar2,(uint)(iVar6 == 0));
    iVar6 = *(int *)(dwNewLong + 4);
    pHVar2 = GetDlgItem(param_1,0x3ed);
    EnableWindow(pHVar2,(uint)(iVar6 == 0));
    iVar6 = *(int *)(dwNewLong + 4);
    pHVar2 = GetDlgItem(param_1,0x3f0);
    EnableWindow(pHVar2,(uint)(iVar6 == 0));
    iVar6 = *(int *)(dwNewLong + 4);
    pHVar2 = GetDlgItem(param_1,0x3ef);
    EnableWindow(pHVar2,(uint)(iVar6 == 0));
    if (*(int *)(dwNewLong + 4) != 0) {
      CheckRadioButton(param_1,0x3eb,0x3ec,0x3eb);
      goto LAB_402d3188;
    }
    CheckRadioButton(param_1,0x3eb,0x3ec,0x3ec);
    iVar6 = *(int *)(dwNewLong + 0xc);
    if (iVar6 != 0) {
      pHVar2 = GetDlgItem(param_1,0x3e9);
      SendMessageW(pHVar2,0x465,0,iVar6);
    }
    iVar6 = *(int *)(dwNewLong + 0x10);
    if (iVar6 != 0) {
      pHVar2 = GetDlgItem(param_1,0x3ee);
      SendMessageW(pHVar2,0x465,0,iVar6);
    }
    lParam = *(int *)(dwNewLong + 0x14);
    if (lParam == 0) goto LAB_402d3188;
    pHVar2 = GetDlgItem(param_1,0x3f0);
  }
  else {
    if (param_2 != 0x111) {
      FUN_402f41d8(DAT_402f65fc);
      return 0;
    }
    LVar1 = GetWindowLongW(param_1,-0x15);
    if ((param_3 >> 0x10 != 0x100) || (pHVar2 = GetDlgItem(param_1,0x3ee), param_4 != pHVar2)) {
      if ((0x3ea < (param_3 & 0xffff)) && ((param_3 & 0xffff) < 0x3ed)) {
        pHVar2 = GetDlgItem(param_1,0x3ec);
        LVar3 = SendMessageW(pHVar2,0xf0,0,0);
        if (LVar3 == 0) {
          pHVar2 = GetDlgItem(param_1,0x3e9);
          SendMessageW(pHVar2,0x464,0,0);
          pHVar2 = GetDlgItem(param_1,0x3ee);
          SendMessageW(pHVar2,0x464,0,0);
          pHVar2 = GetDlgItem(param_1,0x3f0);
          SendMessageW(pHVar2,0x464,0,0);
          *(undefined4 *)(LVar1 + 0xc) = 0;
          *(undefined4 *)(LVar1 + 0x10) = 0;
          *(undefined4 *)(LVar1 + 0x14) = 0;
        }
        uVar5 = (uint)(LVar3 != 0);
        pHVar2 = GetDlgItem(param_1,0x3e9);
        EnableWindow(pHVar2,uVar5);
        pHVar2 = GetDlgItem(param_1,1000);
        EnableWindow(pHVar2,uVar5);
        pHVar2 = GetDlgItem(param_1,0x3ee);
        EnableWindow(pHVar2,uVar5);
        pHVar2 = GetDlgItem(param_1,0x3ed);
        EnableWindow(pHVar2,uVar5);
        pHVar2 = GetDlgItem(param_1,0x3f0);
        EnableWindow(pHVar2,uVar5);
        pHVar2 = GetDlgItem(param_1,0x3ef);
        EnableWindow(pHVar2,uVar5);
      }
      goto LAB_402d3188;
    }
    pHVar2 = GetDlgItem(param_1,0x3e9);
    SendMessageW(pHVar2,0x466,0,(LPARAM)(LVar1 + 0xc));
    lParam_00 = (LPARAM *)(LVar1 + 0x10);
    pHVar2 = GetDlgItem(param_1,0x3ee);
    SendMessageW(pHVar2,0x466,0,(LPARAM)lParam_00);
    uVar5 = *(uint *)(LVar1 + 0xc);
    if ((uVar5 == 0) || (*lParam_00 != 0)) goto LAB_402d3188;
    uVar5 = uVar5 >> 0x18;
    if (uVar5 < 0x80) {
      *lParam_00 = -0x1000000;
    }
    else if (uVar5 < 0xc0) {
      *lParam_00 = -0x10000;
    }
    else {
      *lParam_00 = -0x100;
    }
    pHVar2 = GetDlgItem(param_1,0x3ee);
    lParam = *lParam_00;
  }
  SendMessageW(pHVar2,0x465,0,lParam);
LAB_402d3188:
  FUN_402f41d8(local_20);
  return 1;
}



/* 402d3684 FUN_402d3684 */

/* Boundary evidence: original MIPS .pdata 402d3684..402d3897. Semantic name remains unreviewed. */

undefined4 FUN_402d3684(HWND param_1,int param_2,undefined4 param_3,int param_4)

{
  HWND pHVar1;
  LONG LVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0x4e) {
    if (*(int *)(param_4 + 8) == -0xca) {
      LVar2 = GetWindowLongW(param_1,-0x15);
      pHVar1 = GetDlgItem(param_1,0x3f2);
      SendMessageW(pHVar1,0x466,0,LVar2 + 0x18);
      pHVar1 = GetDlgItem(param_1,0x3f4);
      SendMessageW(pHVar1,0x466,0,LVar2 + 0x1c);
      pHVar1 = GetDlgItem(param_1,0x3f6);
      SendMessageW(pHVar1,0x466,0,LVar2 + 0x20);
      pHVar1 = GetDlgItem(param_1,0x3f8);
      SendMessageW(pHVar1,0x466,0,LVar2 + 0x24);
      SetWindowLongW(param_1,0,0);
    }
  }
  else if (param_2 == 0x110) {
    SetWindowLongW(param_1,-0x15,*(LONG *)(param_4 + 0x1c));
    iVar3 = *(int *)(param_4 + 0x1c);
    SetWindowLongW(param_1,8,iVar3);
    iVar4 = *(int *)(iVar3 + 0x18);
    if (iVar4 != 0) {
      pHVar1 = GetDlgItem(param_1,0x3f2);
      SendMessageW(pHVar1,0x465,0,iVar4);
    }
    iVar4 = *(int *)(iVar3 + 0x1c);
    if (iVar4 != 0) {
      pHVar1 = GetDlgItem(param_1,0x3f4);
      SendMessageW(pHVar1,0x465,0,iVar4);
    }
    iVar4 = *(int *)(iVar3 + 0x20);
    if (iVar4 != 0) {
      pHVar1 = GetDlgItem(param_1,0x3f6);
      SendMessageW(pHVar1,0x465,0,iVar4);
    }
    iVar3 = *(int *)(iVar3 + 0x24);
    if (iVar3 != 0) {
      pHVar1 = GetDlgItem(param_1,0x3f8);
      SendMessageW(pHVar1,0x465,0,iVar3);
    }
  }
  else {
    if (param_2 != 0x111) {
      return 0;
    }
    GetWindowLongW(param_1,-0x15);
  }
  return 1;
}



/* 402d38a0 FUN_402d38a0 */

undefined4 FUN_402d38a0(ushort *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (*param_1 != 0) {
    do {
      if (3 < iVar2) break;
      uVar3 = (uint)*param_1;
      iVar1 = 0;
      if (uVar3 != 0) {
        do {
          if (uVar3 == 0x2e) break;
          if (uVar3 < 0x30) {
            return 0;
          }
          if (0x39 < uVar3) {
            return 0;
          }
          param_1 = param_1 + 1;
          iVar1 = iVar1 * 10 + uVar3;
          uVar3 = (uint)*param_1;
          iVar1 = iVar1 + -0x30;
        } while (uVar3 != 0);
        if (0xff < iVar1) {
          return 0;
        }
      }
      *(char *)(iVar2 + (int)param_2) = (char)iVar1;
      if (*param_1 == 0x2e) {
        param_1 = param_1 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (*param_1 != 0);
    if (iVar2 == 4) {
      uVar3 = *param_2;
      *param_2 = (uVar3 << 0x10 | uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 |
                 (uint)*(byte *)((int)param_2 + 3);
      return 1;
    }
  }
  return 0;
}



/* 402d398c FUN_402d398c */

/* Boundary evidence: original MIPS .pdata 402d398c..402d3a8b. Semantic name remains unreviewed. */

void FUN_402d398c(HKEY param_1,LPCWSTR param_2,uint *param_3,uint *param_4)

{
  LSTATUS LVar1;
  ushort *puVar2;
  ushort *puVar3;
  DWORD local_220 [2];
  ushort local_218;
  ushort local_216 [255];
  uint local_18;
  
  local_18 = DAT_402f65fc;
  local_220[1] = 0x200;
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,local_220,(LPBYTE)&local_218,local_220 + 1);
  if ((LVar1 == 0) && ((local_220[0] == 1 || (local_220[0] == 7)))) {
    if ((param_3 != (uint *)0x0) && (local_218 != 0)) {
      FUN_402d38a0(&local_218,param_3);
    }
    if (((param_4 != (uint *)0x0) && (local_218 != 0)) && (local_220[0] == 7)) {
      puVar3 = &local_218;
      do {
        puVar2 = puVar3;
        puVar3 = puVar2 + 1;
      } while (*puVar3 != 0);
      puVar2 = puVar2 + 2;
      if (*puVar2 != 0) {
        FUN_402d38a0(puVar2,param_4);
      }
    }
  }
  FUN_402f41d8(local_18);
  return;
}



/* 402d3a8c AdapterIPProperties */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 402d3a8c..402d442f. Semantic name remains unreviewed. */

undefined4 AdapterIPProperties(undefined4 param_1,STRSAFE_LPCWSTR param_2)

{
  bool bVar1;
  uint uVar2;
  LSTATUS LVar3;
  int iVar4;
  size_t sVar5;
  STRSAFE_LPCWSTR pwVar6;
  HKEY hKey;
  undefined4 uVar7;
  HKEY local_928;
  DWORD local_924 [6];
  HINSTANCE local_90c;
  undefined4 local_908;
  WCHAR *local_904;
  undefined4 local_900;
  undefined4 local_8fc;
  DWORD *local_8f8;
  undefined1 *local_8f4;
  DWORD DStack_8f0;
  DWORD aDStack_8ec [3];
  HINSTANCE local_8e0;
  undefined4 local_8dc;
  undefined4 local_8d8;
  WCHAR *local_8d4;
  code *local_8d0;
  STRSAFE_LPCWSTR *local_8cc;
  undefined4 local_8c8;
  undefined4 local_8c0;
  undefined4 local_8bc;
  HINSTANCE local_8b8;
  undefined4 local_8b4;
  undefined4 local_8b0;
  WCHAR *local_8ac;
  code *local_8a8;
  STRSAFE_LPCWSTR *local_8a4;
  undefined4 local_8a0;
  STRSAFE_LPCWSTR local_870;
  int local_86c;
  int local_868;
  uint local_864;
  uint local_860;
  uint local_85c;
  uint local_858;
  uint local_854;
  uint local_850;
  uint local_84c;
  wchar_t local_848 [256];
  undefined1 auStack_648 [8];
  undefined4 local_640;
  wchar_t awStack_420 [256];
  WCHAR aWStack_220 [60];
  WCHAR aWStack_1a8 [60];
  WCHAR aWStack_130 [128];
  uint local_30;
  
                    /* 0x3a8c  1  AdapterIPProperties */
  local_30 = DAT_402f65fc;
  uVar7 = 0;
  uVar2 = GetSystemMetrics(0);
  if (param_2 == (STRSAFE_LPCWSTR)0x0) {
LAB_402d3ae0:
    FUN_402f41d8(local_30);
    return 0;
  }
  bVar1 = uVar2 < 0x1e0;
  if (bVar1) {
    local_924[1] = 8;
    local_924[2] = 0x3000;
    if (DAT_402fc384 == (code *)0x0) goto LAB_402d3ae0;
    (*DAT_402fc384)(local_924 + 1);
  }
  else {
    if (DAT_402fc380 == (code *)0x0) goto LAB_402d3ae0;
    (*DAT_402fc380)();
  }
  if (DAT_402fc3b4 == (code *)0x0) goto LAB_402d3ae0;
  RegisterIPClass(DAT_402fc3c4);
  memset(&local_870,0,0x228);
  local_86c = 1;
  local_870 = param_2;
  wcscpy(awStack_420,L"Comm\\");
  StringCchCatW(awStack_420,0x100,param_2);
  local_928 = (HKEY)0x0;
  LVar3 = RegOpenKeyExW((HKEY)0x80000002,awStack_420,0,0,&local_928);
  if (LVar3 == 0) {
    local_924[0] = 0x200;
    local_848[0] = L'\0';
    RegQueryValueExW(local_928,L"DisplayName",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_848,local_924)
    ;
    RegCloseKey(local_928);
  }
  wcscpy(awStack_420,L"Comm\\");
  StringCchCatW(awStack_420,0x100,param_2);
  StringCchCatW(awStack_420,0x100,L"\\Parms\\TcpIp");
  local_928 = (HKEY)0x0;
  LVar3 = RegOpenKeyExW((HKEY)0x80000002,awStack_420,0,0,&local_928);
  if (LVar3 == 0) {
    local_924[0] = 4;
    LVar3 = RegQueryValueExW(local_928,L"EnableDHCP",(LPDWORD)0x0,&DStack_8f0,(LPBYTE)&local_86c,
                             local_924);
    if ((LVar3 == 0) && (local_86c == 0)) {
      FUN_402d398c(local_928,L"IpAddress",&local_864,(uint *)0x0);
      FUN_402d398c(local_928,L"Subnetmask",&local_860,(uint *)0x0);
      FUN_402d398c(local_928,L"DefaultGateway",&local_85c,(uint *)0x0);
    }
    FUN_402d398c(local_928,L"DNS",&local_858,&local_854);
    FUN_402d398c(local_928,L"WINS",&local_850,&local_84c);
  }
  memcpy(auStack_648,&local_870,0x228);
  aDStack_8ec[1] = 0x28;
  aDStack_8ec[2] = 8;
  local_8e0 = DAT_402fc3c4;
  if (bVar1) {
    local_8dc = 0x73;
  }
  else {
    local_8dc = 0x70;
  }
  local_8d8 = 0;
  local_8d0 = FUN_402d3030;
  LoadStringW(DAT_402fc3c4,0x12,aWStack_220,0x3c);
  local_8cc = &local_870;
  local_8d4 = aWStack_220;
  local_8bc = 8;
  local_8c8 = 0;
  local_8c0 = 0x28;
  local_8b8 = DAT_402fc3c4;
  if (bVar1) {
    local_8b4 = 0x74;
  }
  else {
    local_8b4 = 0x71;
  }
  local_8b0 = 0;
  local_8a8 = FUN_402d3684;
  LoadStringW(DAT_402fc3c4,0x13,aWStack_1a8,0x3c);
  local_8a4 = &local_870;
  local_8ac = aWStack_1a8;
  local_924[3] = 0x28;
  local_8a0 = 0;
  local_924[4] = 0x108;
  local_90c = DAT_402fc3c4;
  local_908 = 0;
  local_924[5] = param_1;
  LoadStringW(DAT_402fc3c4,0x14,awStack_420,0x100);
  pwVar6 = local_848;
  if (local_848[0] == L'\0') {
    pwVar6 = local_870;
  }
  wsprintfW(aWStack_130,awStack_420,pwVar6);
  local_8f8 = aDStack_8ec + 1;
  local_904 = aWStack_130;
  local_8f4 = &LAB_402d3898;
  local_900 = 2;
  local_8fc = 0;
  (*DAT_402fc3b4)(local_924 + 3);
  hKey = local_928;
  local_640 = 1;
  if (local_868 != 0) {
    if (local_928 == (HKEY)0x0) {
      wcscpy(awStack_420,L"Comm\\");
      StringCchCatW(awStack_420,0x100,param_2);
      StringCchCatW(awStack_420,0x100,L"\\Parms\\TcpIp");
      RegCreateKeyExW((HKEY)0x80000002,awStack_420,0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,
                      &local_928,aDStack_8ec);
      hKey = local_928;
      if (local_928 == (HKEY)0x0) goto LAB_402d43f4;
    }
    else {
      iVar4 = memcmp(auStack_648,&local_870,0x228);
      if (iVar4 == 0) goto LAB_402d43dc;
    }
    uVar7 = 1;
    if (local_86c != 0) {
      local_86c = 1;
    }
    RegSetValueExW(hKey,L"EnableDHCP",0,4,(BYTE *)&local_86c,4);
    wsprintfW(awStack_420,L"%d.%d.%d.%d",local_864 >> 0x18,local_864 >> 0x10 & 0xff,
              local_864 >> 8 & 0xff,local_864 & 0xff);
    sVar5 = wcslen(awStack_420);
    awStack_420[sVar5 + 1] = L'\0';
    RegSetValueExW(local_928,L"IpAddress",0,7,(BYTE *)awStack_420,(sVar5 + 1) * 2 + 2);
    wsprintfW(awStack_420,L"%d.%d.%d.%d",local_860 >> 0x18,local_860 >> 0x10 & 0xff,
              local_860 >> 8 & 0xff,local_860 & 0xff);
    sVar5 = wcslen(awStack_420);
    awStack_420[sVar5 + 1] = L'\0';
    RegSetValueExW(local_928,L"Subnetmask",0,7,(BYTE *)awStack_420,(sVar5 + 1) * 2 + 2);
    wsprintfW(awStack_420,L"%d.%d.%d.%d",local_85c >> 0x18,local_85c >> 0x10 & 0xff,
              local_85c >> 8 & 0xff,local_85c & 0xff);
    sVar5 = wcslen(awStack_420);
    awStack_420[sVar5 + 1] = L'\0';
    RegSetValueExW(local_928,L"DefaultGateway",0,7,(BYTE *)awStack_420,(sVar5 + 1) * 2 + 2);
    if (local_858 == 0) {
      if (local_854 != 0) {
        wsprintfW(awStack_420,L"%d.%d.%d.%d",local_854 >> 0x18,local_854 >> 0x10 & 0xff,
                  local_854 >> 8 & 0xff,local_854 & 0xff);
        sVar5 = wcslen(awStack_420);
        awStack_420[sVar5 + 1] = L'\0';
        iVar4 = sVar5 + 2;
        goto LAB_402d4224;
      }
LAB_402d425c:
      RegSetValueExW(local_928,L"DNS",0,7,"",2);
    }
    else {
      wsprintfW(awStack_420,L"%d.%d.%d.%d",local_858 >> 0x18,local_858 >> 0x10 & 0xff,
                local_858 >> 8 & 0xff,local_858 & 0xff);
      sVar5 = wcslen(awStack_420);
      iVar4 = sVar5 + 1;
      if (local_854 != 0) {
        wsprintfW(awStack_420 + iVar4,L"%d.%d.%d.%d",local_854 >> 0x18,local_854 >> 0x10 & 0xff,
                  local_854 >> 8 & 0xff,local_854 & 0xff);
        sVar5 = wcslen(awStack_420 + iVar4);
        iVar4 = sVar5 + iVar4 + 1;
      }
      awStack_420[iVar4] = L'\0';
      iVar4 = iVar4 + 1;
LAB_402d4224:
      if (iVar4 == 0) goto LAB_402d425c;
      RegSetValueExW(local_928,L"DNS",0,7,(BYTE *)awStack_420,iVar4 << 1);
    }
    if (local_850 == 0) {
      if (local_84c != 0) {
        wsprintfW(awStack_420,L"%d.%d.%d.%d",local_84c >> 0x18,local_84c >> 0x10 & 0xff,
                  local_84c >> 8 & 0xff,local_84c & 0xff);
        sVar5 = wcslen(awStack_420);
        awStack_420[sVar5 + 1] = L'\0';
        iVar4 = sVar5 + 2;
        goto LAB_402d4380;
      }
    }
    else {
      wsprintfW(awStack_420,L"%d.%d.%d.%d",local_850 >> 0x18,local_850 >> 0x10 & 0xff,
                local_850 >> 8 & 0xff,local_850 & 0xff);
      sVar5 = wcslen(awStack_420);
      iVar4 = sVar5 + 1;
      if (local_84c != 0) {
        wsprintfW(awStack_420 + iVar4,L"%d.%d.%d.%d",local_84c >> 0x18,local_84c >> 0x10 & 0xff,
                  local_84c >> 8 & 0xff,local_84c & 0xff);
        sVar5 = wcslen(awStack_420 + iVar4);
        iVar4 = sVar5 + iVar4 + 1;
      }
      awStack_420[iVar4] = L'\0';
      iVar4 = iVar4 + 1;
LAB_402d4380:
      if (iVar4 != 0) {
        RegSetValueExW(local_928,L"WINS",0,7,(BYTE *)awStack_420,iVar4 << 1);
        hKey = local_928;
        goto LAB_402d43dc;
      }
    }
    RegSetValueExW(local_928,L"WINS",0,7,"",2);
    hKey = local_928;
  }
LAB_402d43dc:
  if (hKey != (HKEY)0x0) {
    RegCloseKey(hKey);
  }
LAB_402d43f4:
  FUN_402f41d8(local_30);
  return uVar7;
}



/* 402d4430 AdapterIPPropertiesExt */

/* Boundary evidence: original MIPS .pdata 402d4430..402d44d3. Semantic name remains unreviewed. */

undefined4
AdapterIPPropertiesExt(int param_1,uint param_2,int *param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
                    /* 0x4430  2  AdapterIPPropertiesExt */
  if (param_2 < 0x10) {
    SetLastError(0x57);
  }
  else {
    *param_5 = param_4;
    uVar3 = *(undefined4 *)(param_1 + 4);
    param_3[2] = 0;
    SetLastError(0);
    iVar1 = AdapterIPProperties(uVar3,(STRSAFE_LPCWSTR)(param_1 + 0xc));
    *param_3 = iVar1;
    if (iVar1 != 0) {
      return 1;
    }
    DVar2 = GetLastError();
    param_3[2] = DVar2;
  }
  return 0;
}



/* 402d44d4 FUN_402d44d4 */

void FUN_402d44d4(uint param_1,undefined4 *param_2)

{
  longlong lVar1;
  
  lVar1 = (ulonglong)(param_1 + 0xb6109100) * 10000000;
  *param_2 = (int)lVar1;
  param_2[1] = ((param_1 + 0xb6109100 < param_1) + 2) * 10000000 + (int)((ulonglong)lVar1 >> 0x20);
  return;
}



/* 402d451c FUN_402d451c */

/* Boundary evidence: original MIPS .pdata 402d451c..402d459b. Semantic name remains unreviewed. */

void FUN_402d451c(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402e8d78();
  if (DAT_402f6620 == (HANDLE)0x0) {
    DAT_402f6620 = CreateFileW(L"UIO1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,
                               (HANDLE)0xffffffff);
  }
  return;
}



/* 402d459c FUN_402d459c */

/* Boundary evidence: original MIPS .pdata 402d459c..402d4603. Semantic name remains unreviewed. */

void FUN_402d459c(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402e8d9c();
  if (DAT_402f6620 != 0) {
    CloseHandle((HANDLE)DAT_402f6620);
  }
  if (DAT_402fc228 != 0) {
    CloseHandle((HANDLE)DAT_402fc228);
  }
  return;
}



/* 402d4604 FUN_402d4604 */

/* Boundary evidence: original MIPS .pdata 402d4604..402d4667. Semantic name remains unreviewed. */

void FUN_402d4604(HWND param_1)

{
  BOOL BVar1;
  tagMSG tStack_28;
  
  while (BVar1 = GetMessageW(&tStack_28,(HWND)0x0,0,0), BVar1 != 0) {
    BVar1 = IsDialogMessageW(param_1,&tStack_28);
    if (BVar1 == 0) {
      TranslateMessage(&tStack_28);
      DispatchMessageW(&tStack_28);
    }
  }
  return;
}



/* 402d4668 RemoveNetUISystrayIcon */

/* Boundary evidence: original MIPS .pdata 402d4668..402d48fb. Semantic name remains unreviewed. */

undefined4 RemoveNetUISystrayIcon(wchar_t *param_1)

{
  wchar_t *_Str1;
  wchar_t *pwVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  
                    /* 0x4668  44  RemoveNetUISystrayIcon */
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pwVar3 = (wchar_t *)0x0;
  _Str1 = DAT_402fc3c8;
  do {
    pwVar1 = DAT_402fc3c8;
    if (_Str1 == (wchar_t *)0x0) {
LAB_402d46f4:
      DAT_402fc3c8 = pwVar1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      if (_Str1 == (wchar_t *)0x0) {
        uVar4 = 0x80004005;
      }
      else {
        if (*(int *)(_Str1 + 0x292) != 0) {
          FUN_402eb73c();
          EventModify(DAT_402fc228,3);
          WaitForSingleObject(*(HANDLE *)(_Str1 + 0x296),0xffffffff);
          CloseHandle(*(HANDLE *)(_Str1 + 0x296));
          _Str1[0x296] = L'\0';
          _Str1[0x297] = L'\0';
          FUN_402e93d8();
          if (*(int *)(_Str1 + 0x25a) != 0) {
            (*DAT_402fc214)(_Str1 + 0x232);
          }
          if (*(HIMAGELIST *)(_Str1 + 0x280) != (HIMAGELIST)0x0) {
            ImageList_Destroy(*(HIMAGELIST *)(_Str1 + 0x280));
            _Str1[0x280] = L'\0';
            _Str1[0x281] = L'\0';
          }
          iVar2 = *(int *)(_Str1 + 0x284);
          if (iVar2 != 0) {
            if (*(int *)(iVar2 + 4) != iVar2) {
              do {
                FUN_402e97fc(*(int **)(*(int *)(_Str1 + 0x284) + 4));
              } while (*(int *)(*(int *)(_Str1 + 0x284) + 4) != *(int *)(_Str1 + 0x284));
            }
            FUN_402e97fc(*(int **)(_Str1 + 0x284));
            _Str1[0x284] = L'\0';
            _Str1[0x285] = L'\0';
          }
          iVar2 = *(int *)(_Str1 + 0x286);
          if (iVar2 != 0) {
            if (*(int *)(iVar2 + 4) != iVar2) {
              do {
                FUN_402e97fc(*(int **)(*(int *)(_Str1 + 0x286) + 4));
              } while (*(int *)(*(int *)(_Str1 + 0x286) + 4) != *(int *)(_Str1 + 0x286));
            }
            FUN_402e97fc(*(int **)(_Str1 + 0x286));
            _Str1[0x286] = L'\0';
            _Str1[0x287] = L'\0';
          }
        }
        if (*(int *)(_Str1 + 0x294) != 0) {
          PostMessageW(*(HWND *)(_Str1 + 0x28a),0x433,0,*(LPARAM *)(_Str1 + 0x28c));
          _Str1[0x294] = L'\0';
          _Str1[0x295] = L'\0';
        }
        _Str1[0x28c] = L'\0';
        _Str1[0x28d] = L'\0';
        pwVar3 = _Str1 + 0x298;
        iVar2 = 2;
        do {
          if (*(HANDLE *)pwVar3 != (HANDLE)0x0) {
            WaitForSingleObject(*(HANDLE *)pwVar3,0xffffffff);
            CloseHandle(*(HANDLE *)pwVar3);
            pwVar3[0] = L'\0';
            pwVar3[1] = L'\0';
          }
          iVar2 = iVar2 + -1;
          pwVar3 = pwVar3 + 2;
        } while (iVar2 != 0);
        CloseHandle(*(HANDLE *)(_Str1 + 0x29c));
        Shell_NotifyIcon(2,*(undefined4 *)(_Str1 + 0x29e));
        DestroyIcon(*(HICON *)(*(int *)(_Str1 + 0x29e) + 0x14));
        PostMessageW(*(HWND *)(_Str1 + 0x28a),0x10,0,0);
        free(*(void **)(_Str1 + 0x29e));
        free(*(void **)(_Str1 + 0x208));
        free(_Str1);
      }
      return uVar4;
    }
    iVar2 = wcscmp(_Str1,param_1);
    if (iVar2 == 0) {
      pwVar1 = *(wchar_t **)(_Str1 + 0x2a0);
      if (pwVar3 != (wchar_t *)0x0) {
        *(wchar_t **)(pwVar3 + 0x2a0) = *(wchar_t **)(_Str1 + 0x2a0);
        pwVar1 = DAT_402fc3c8;
      }
      goto LAB_402d46f4;
    }
    pwVar3 = _Str1;
    _Str1 = *(wchar_t **)(_Str1 + 0x2a0);
  } while( true );
}



/* 402d48fc FUN_402d48fc */

/* Boundary evidence: original MIPS .pdata 402d48fc..402d49ab. Semantic name remains unreviewed. */

undefined4 FUN_402d48fc(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  if ((param_1 != 0) && (iVar1 = DAT_402fc3c8, DAT_402fc3c8 != 0)) {
    while (*(int *)(iVar1 + 0x514) != param_1) {
      if ((*(int *)(iVar1 + 0x518) == param_1) || (iVar1 = *(int *)(iVar1 + 0x540), iVar1 == 0))
      break;
    }
    if (iVar1 != 0) {
      *param_2 = iVar1;
      goto LAB_402d4984;
    }
  }
  uVar2 = 0x80004005;
LAB_402d4984:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return uVar2;
}



/* 402d49ac FUN_402d49ac */

/* Boundary evidence: original MIPS .pdata 402d49ac..402d4a57. Semantic name remains unreviewed. */

undefined4 FUN_402d49ac(wchar_t *param_1,undefined4 *param_2)

{
  int iVar1;
  wchar_t *_Str1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  _Str1 = DAT_402fc3c8;
  if (DAT_402fc3c8 != (wchar_t *)0x0) {
    do {
      iVar1 = wcscmp(_Str1,param_1);
      if (iVar1 == 0) break;
      _Str1 = *(wchar_t **)(_Str1 + 0x2a0);
    } while (_Str1 != (wchar_t *)0x0);
    if (_Str1 != (wchar_t *)0x0) {
      *param_2 = _Str1;
      goto LAB_402d4a2c;
    }
  }
  uVar2 = 0x80004005;
LAB_402d4a2c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return uVar2;
}



/* 402d4a58 FUN_402d4a58 */

/* Boundary evidence: original MIPS .pdata 402d4a58..402d4b1f. Semantic name remains unreviewed. */

undefined4 FUN_402d4a58(LPCWSTR param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_18;
  DWORD local_14;
  
  local_14 = 0x104;
  uVar2 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"Comm\\AdapterNameMappings",0,0x20019,&local_18);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_18,param_1,(LPDWORD)0x0,(LPDWORD)0x0,param_2,&local_14);
    if (LVar1 != 0) {
      uVar2 = 0x490;
    }
    RegCloseKey(local_18);
  }
  else {
    uVar2 = 0x490;
  }
  return uVar2;
}



/* 402d4b20 FUN_402d4b20 */

/* Boundary evidence: original MIPS .pdata 402d4b20..402d4b63. Semantic name remains unreviewed. */

bool FUN_402d4b20(void)

{
  int local_10 [2];
  
  local_10[0] = 0;
  GetAdaptersAddresses(0x17,0,0,0,local_10);
  return local_10[0] != 0;
}



/* 402d4b64 FUN_402d4b64 */

/* Boundary evidence: original MIPS .pdata 402d4b64..402d4e07. Semantic name remains unreviewed. */

undefined4 FUN_402d4b64(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  undefined4 uVar4;
  HINSTANCE pHVar5;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  HINSTANCE local_17c;
  undefined4 local_178;
  undefined4 local_174;
  int local_170;
  undefined4 local_16c;
  HINSTANCE *local_168;
  undefined1 *local_164;
  HINSTANCE local_160 [4];
  undefined4 local_150;
  WCHAR *local_14c;
  code *local_148 [4];
  HINSTANCE local_138 [6];
  code *local_120 [14];
  WCHAR aWStack_e8 [32];
  HINSTANCE__ aHStack_a8 [16];
  WCHAR aWStack_68 [30];
  uint local_2c;
  
  local_2c = DAT_402f65fc;
  uVar4 = 0;
  iVar2 = GetSystemMetrics(0);
  if (iVar2 < 0x1e0) {
    local_160[3] = (HINSTANCE)0x1838;
    uVar3 = 0x1839;
    pHVar5 = (HINSTANCE)0x183a;
  }
  else {
    local_160[3] = (HINSTANCE)0x1771;
    uVar3 = 0x17d4;
    pHVar5 = (HINSTANCE)0x7d1;
  }
  local_160[0] = (HINSTANCE)0x28;
  local_160[1] = (HINSTANCE)0x8;
  local_160[2] = DAT_402fc3c4;
  local_150 = 0;
  LoadStringW(DAT_402fc3c4,0x1785,aWStack_68,0x1e);
  local_148[0] = FUN_402ed0d0;
  local_14c = aWStack_68;
  local_148[2] = (code *)0x0;
  local_148[3] = (code *)0x0;
  local_170 = 1;
  local_16c = 0;
  local_148[1] = (code *)param_3;
  bVar1 = FUN_402d4b20();
  bVar1 = CONCAT31(extraout_var,bVar1) != 0;
  if (bVar1) {
    local_138[0] = (HINSTANCE)0x28;
    local_138[1] = (HINSTANCE)0x8;
    local_138[2] = DAT_402fc3c4;
    local_138[4] = (HINSTANCE)0x0;
    local_138[3] = (HINSTANCE)uVar3;
    LoadStringW(DAT_402fc3c4,0x17e5,aWStack_e8,0x1e);
    local_120[0] = FUN_402ec8a0;
    local_138[5] = (HINSTANCE)aWStack_e8;
    local_170 = local_170 + 1;
    local_120[1] = (code *)0x0;
    local_120[2] = (code *)0x0;
    local_120[3] = (code *)0x0;
  }
  if (param_4 != 0) {
    iVar2 = bVar1 + 1;
    local_160[iVar2 * 10] = (HINSTANCE)0x28;
    local_160[iVar2 * 10 + 1] = (HINSTANCE)0x8;
    local_160[iVar2 * 10 + 2] = DAT_402fc3c4;
    local_160[iVar2 * 10 + 3] = pHVar5;
    local_160[iVar2 * 10 + 4] = (HINSTANCE)0x0;
    LoadStringW(DAT_402fc3c4,0x1786,(LPWSTR)aHStack_a8,0x1e);
    local_160[iVar2 * 10 + 5] = aHStack_a8;
    local_148[iVar2 * 10] = FUN_402e8800;
    local_148[iVar2 * 10 + 1] = (code *)0x0;
    local_170 = local_170 + 1;
    local_148[iVar2 * 10 + 2] = (code *)0x0;
    local_148[iVar2 * 10 + 3] = (code *)0x0;
  }
  local_184 = 0x508;
  local_168 = local_160;
  local_17c = DAT_402fc3c4;
  local_164 = &LAB_402d3898;
  local_188 = 0x28;
  local_180 = 0;
  local_178 = 0;
  local_16c = 0;
  local_174 = param_3;
  (*DAT_402fc380)();
  iVar2 = (*DAT_402fc3b4)(&local_188);
  *param_1 = iVar2;
  if (iVar2 == -1) {
    uVar4 = 0x80004005;
  }
  FUN_402f41d8(local_2c);
  return uVar4;
}



/* 402d4e08 FUN_402d4e08 */

/* Boundary evidence: original MIPS .pdata 402d4e08..402d50c3. Semantic name remains unreviewed. */

undefined4 FUN_402d4e08(HWND param_1,int param_2,int param_3,HWND param_4)

{
  LPCWSTR pWVar1;
  int iVar2;
  LRESULT LVar3;
  HWND pHVar4;
  undefined4 uVar5;
  wchar_t *_Dest;
  LPCWSTR pWVar6;
  LPCWSTR local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  uVar5 = 0;
  local_238[0] = (LPCWSTR)0x0;
  if (param_2 == 2) {
    PostQuitMessage(0);
  }
  else if (param_2 == 0x10) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
    DestroyWindow(param_1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  }
  else if (param_2 == 0x1a) {
    iVar2 = FUN_402d48fc((int)param_1,(int *)local_238);
    pWVar1 = local_238[0];
    if (((-1 < iVar2) && (local_238[0] != (LPCWSTR)0x0)) &&
       (iVar2 = FUN_402d4a58(local_238[0],(LPBYTE)awStack_230), iVar2 == 0)) {
      _Dest = pWVar1 + 0x104;
      wcsncpy(_Dest,awStack_230,0x104);
      if (*(int *)(pWVar1 + 0x294) != 0) {
        SetWindowTextW(*(HWND *)(pWVar1 + 0x28c),_Dest);
      }
      wcsncpy((wchar_t *)(*(int *)(pWVar1 + 0x29e) + 0x18),_Dest,0x40);
      Shell_NotifyIcon(1,*(undefined4 *)(pWVar1 + 0x29e));
    }
  }
  else {
    if (param_2 == 0x110) {
      uVar5 = 1;
      goto LAB_402d5090;
    }
    if (param_2 != 0x433) {
      if ((param_2 == 0x8064) && (param_4 == (HWND)0x203)) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
        iVar2 = FUN_402d48fc((int)param_1,(int *)local_238);
        pWVar1 = local_238[0];
        if ((-1 < iVar2) && (local_238[0] != (LPCWSTR)0x0)) {
          if (*(int *)(local_238[0] + 0x294) == 0) {
            local_238[0][0x294] = L'\x01';
            local_238[0][0x295] = L'\0';
            pWVar6 = local_238[0] + 0x28c;
            iVar2 = FUN_402d4b64((int *)pWVar6,param_1,local_238[0] + 0x104,
                                 *(int *)(local_238[0] + 0x292));
            if (iVar2 < 0) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
              goto LAB_402d5090;
            }
            LVar3 = SendMessageW(*(HWND *)pWVar6,0x476,0,0);
            *(LRESULT *)(pWVar1 + 0x28e) = LVar3;
            if ((*(int *)(pWVar1 + 0x292) != 0) && (param_3 == 1)) {
              LVar3 = SendMessageW(*(HWND *)pWVar6,0x465,2,0);
              if (LVar3 == 0) {
                SendMessageW(*(HWND *)pWVar6,0x465,1,0);
              }
              LVar3 = SendMessageW(*(HWND *)pWVar6,0x476,0,0);
              *(LRESULT *)(pWVar1 + 0x290) = LVar3;
            }
            pHVar4 = (HWND)SendMessageW(*(HWND *)pWVar6,0x476,0,0);
            FUN_402ebaf0(pHVar4,0);
          }
          else {
            SetForegroundWindow(*(HWND *)(local_238[0] + 0x28c));
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      }
      uVar5 = 1;
      goto LAB_402d5090;
    }
    DestroyWindow(param_4);
  }
  uVar5 = 0;
LAB_402d5090:
  FUN_402f41d8(local_28);
  return uVar5;
}



/* 402d50c4 AddNetUISystrayIcon */

/* Boundary evidence: original MIPS .pdata 402d50c4..402d553f. Semantic name remains unreviewed. */

int AddNetUISystrayIcon(wchar_t *param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  wchar_t *_Dest;
  void *pvVar4;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  HWND pHVar5;
  HANDLE pvVar6;
  undefined4 uVar7;
  void *_Memory;
  int iVar8;
  wchar_t *_Dest_00;
  uint local_30;
  
                    /* 0x50c4  3  AddNetUISystrayIcon */
  iVar8 = 0;
  _Memory = (void *)0x0;
  do {
    iVar3 = WaitForAPIReady(0x55,500);
  } while (iVar3 != 0);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  _Dest = malloc(0x544);
  if (_Dest == (wchar_t *)0x0) {
    iVar8 = -0x7fffbffb;
    goto LAB_402d5504;
  }
  memset(_Dest,0,0x544);
  if (param_2 == 0) {
LAB_402d51d0:
    _Memory = malloc(0x98);
    if (_Memory != (void *)0x0) {
      pvVar4 = malloc(0x86);
      *(void **)(_Dest + 0x208) = pvVar4;
      if (pvVar4 != (void *)0x0) {
        hResInfo = FindResourceW(DAT_402fc3c4,(LPCWSTR)0x17a2,(LPCWSTR)0x5);
        lpTemplate = LoadResource(DAT_402fc3c4,hResInfo);
        pHVar5 = CreateDialogIndirectParamW(DAT_402fc3c4,lpTemplate,(HWND)0x0,FUN_402d4e08,0);
        *(HWND *)(_Dest + 0x28a) = pHVar5;
        if (pHVar5 != (HWND)0x0) {
          if (param_2 == 0) {
            pvVar6 = LoadImageW(DAT_402fc3c4,(LPCWSTR)0x17a7,1,0x10,0x10,0);
          }
          else {
            pvVar6 = LoadImageW(DAT_402fc3c4,(LPCWSTR)0x17a4,1,0x10,0x10,0);
          }
          *(HANDLE *)((int)_Memory + 0x14) = pvVar6;
          if (pvVar6 != (HANDLE)0x0) {
            wcscpy(_Dest,param_1);
            _Dest_00 = _Dest + 0x104;
            iVar3 = FUN_402d4a58(_Dest,(LPBYTE)_Dest_00);
            if (iVar3 != 0) {
              wcscpy(_Dest_00,_Dest);
            }
            uVar7 = *(undefined4 *)(_Dest + 0x28a);
            uVar1 = (int)_Memory + 3U & 3;
            puVar2 = (uint *)(((int)_Memory + 3U) - uVar1);
            *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0x98U >> (3 - uVar1) * 8;
            *(undefined4 *)((int)_Memory + 4) = uVar7;
            uVar1 = (uint)_Memory & 3;
            *(uint *)((int)_Memory - uVar1) =
                 *(uint *)((int)_Memory - uVar1) & 0xffffffffU >> (4 - uVar1) * 8 |
                 0x98 << uVar1 * 8;
            wcsncpy((wchar_t *)((int)_Memory + 0x18),_Dest_00,0x40);
            uVar1 = (int)_Memory + 0xbU & 3;
            puVar2 = (uint *)(((int)_Memory + 0xbU) - uVar1);
            *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0x3e9U >> (3 - uVar1) * 8;
            *(undefined4 *)((int)_Memory + 0x10) = 0x8064;
            *(undefined4 *)((int)_Memory + 0xc) = 7;
            uVar1 = (int)_Memory + 8U & 3;
            puVar2 = (uint *)(((int)_Memory + 8U) - uVar1);
            *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0x3e9 << uVar1 * 8;
            iVar3 = Shell_NotifyIcon(0,_Memory);
            if (iVar3 != 0) {
              *(void **)(_Dest + 0x29e) = _Memory;
              *(int *)(_Dest + 0x292) = param_2;
              _Dest[0x294] = L'\0';
              _Dest[0x295] = L'\0';
              uVar7 = __GetUserKData(8);
              *(undefined4 *)(_Dest + 0x288) = uVar7;
              _Dest[0x230] = L'\0';
              _Dest[0x231] = L'\0';
              *(wchar_t **)(_Dest + 0x2a0) = DAT_402fc3c8;
              DAT_402fc3c8 = _Dest;
              if (param_2 != 0) {
                LoadStringW(DAT_402fc3c4,0x17be,*(LPWSTR *)(_Dest + 0x208),0x43);
                wcscpy(_Dest + 0x20a,L"");
                _Dest[0x22c] = L'\0';
                _Dest[0x22d] = L'\0';
                pvVar6 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
                *(HANDLE *)(_Dest + 0x29c) = pvVar6;
                if (DAT_402fc228 == (HANDLE)0x0) {
                  DAT_402fc228 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
                }
                else {
                  EventModify(DAT_402fc228,2);
                }
                pvVar6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402e8608,(LPVOID)0x0,0,
                                      (LPDWORD)0x0);
                *(HANDLE *)(_Dest + 0x296) = pvVar6;
                if ((DAT_402fc228 == (HANDLE)0x0) || (pvVar6 == (HANDLE)0x0)) goto LAB_402d5284;
                if ((local_30 != 0) &&
                   ((DAT_402fc2a4 != 0 && (iVar3 = FUN_402e5f34((int)_Dest), iVar3 == 1)))) {
                  PostMessageW(*(HWND *)(_Dest + 0x28a),0x8064,1,0x203);
                }
              }
              *param_3 = *(undefined4 *)(_Dest + 0x28a);
              goto LAB_402d5504;
            }
          }
        }
      }
    }
LAB_402d5284:
    iVar8 = -0x7fffbffb;
  }
  else {
    iVar8 = FUN_402e9388();
    if (-1 < iVar8) {
      iVar3 = FUN_402e9450();
      if (iVar3 != 0) {
        memset(_Dest + 0x232,0,0xac);
        iVar3 = FUN_402e9698(param_1,(undefined4 *)(_Dest + 0x232));
        local_30 = (uint)(iVar3 != 0);
        FUN_402eb1f0(&DAT_402fc2a4,(undefined4 *)0x0);
        goto LAB_402d51d0;
      }
      goto LAB_402d5284;
    }
  }
  if (*(void **)(_Dest + 0x208) != (void *)0x0) {
    free(*(void **)(_Dest + 0x208));
  }
  if (*(HWND *)(_Dest + 0x28a) != (HWND)0x0) {
    DestroyWindow(*(HWND *)(_Dest + 0x28a));
  }
  if (*(HANDLE *)(_Dest + 0x29c) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(_Dest + 0x29c));
  }
  if (*(HANDLE *)(_Dest + 0x296) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(_Dest + 0x296));
  }
  free(_Dest);
  if (_Memory != (void *)0x0) {
    if (*(HICON *)((int)_Memory + 0x14) != (HICON)0x0) {
      DestroyIcon(*(HICON *)((int)_Memory + 0x14));
    }
    free(_Memory);
  }
LAB_402d5504:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return iVar8;
}



/* 402d5540 IsPropSheetDialogMessage */

/* Boundary evidence: original MIPS .pdata 402d5540..402d55ef. Semantic name remains unreviewed. */

LRESULT IsPropSheetDialogMessage(int param_1,LPARAM param_2)

{
  int iVar1;
  HWND hWnd;
  LRESULT LVar2;
  int local_20 [2];
  
                    /* 0x5540  29  IsPropSheetDialogMessage */
  local_20[0] = 0;
  LVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar1 = FUN_402d48fc(param_1,local_20);
  if ((-1 < iVar1) && (*(int *)(local_20[0] + 0x528) != 0)) {
    hWnd = *(HWND *)(local_20[0] + 0x518);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
    LVar2 = SendMessageW(hWnd,0x475,0,param_2);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return LVar2;
}



/* 402d55f0 FUN_402d55f0 */

/* Boundary evidence: original MIPS .pdata 402d55f0..402d5683. Semantic name remains unreviewed. */

int FUN_402d55f0(int param_1)

{
  int iVar1;
  int iVar2;
  int local_18 [2];
  
  local_18[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar2 = FUN_402d48fc(param_1,local_18);
  iVar1 = local_18[0];
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else {
    if (*(int *)(local_18[0] + 0x528) == 1) {
      DestroyWindow(*(HWND *)(local_18[0] + 0x518));
    }
    *(undefined4 *)(iVar1 + 0x528) = 0;
    *(undefined4 *)(iVar1 + 0x518) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return iVar2;
}



/* 402d5684 ClosePropSheetDialogIfReady */

/* Boundary evidence: original MIPS .pdata 402d5684..402d5727. Semantic name remains unreviewed. */

int ClosePropSheetDialogIfReady(int param_1)

{
  int iVar1;
  int iVar2;
  LRESULT LVar3;
  int local_18 [2];
  
                    /* 0x5684  4  ClosePropSheetDialogIfReady */
  local_18[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar2 = FUN_402d48fc(param_1,local_18);
  iVar1 = local_18[0];
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if ((*(int *)(local_18[0] + 0x528) != 0) &&
          (LVar3 = SendMessageW(*(HWND *)(local_18[0] + 0x518),0x476,0,0), LVar3 == 0)) {
    FUN_402d55f0(*(int *)(iVar1 + 0x514));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return iVar2;
}



/* 402d5728 FUN_402d5728 */

/* Boundary evidence: original MIPS .pdata 402d5728..402d57c3. Semantic name remains unreviewed. */

undefined4 FUN_402d5728(void)

{
  LSTATUS LVar1;
  HKEY local_18;
  undefined4 local_14;
  DWORD local_10;
  DWORD DStack_c;
  
  local_14 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Security",0,0x20019,&local_18);
  if (LVar1 == 0) {
    local_10 = 4;
    RegQueryValueExW(local_18,L"DisallowSavedNetworkPasswords",(LPDWORD)0x0,&DStack_c,
                     (LPBYTE)&local_14,&local_10);
    RegCloseKey(local_18);
  }
  return local_14;
}



/* 402d57c4 FUN_402d57c4 */

/* Boundary evidence: original MIPS .pdata 402d57c4..402d58d7. Semantic name remains unreviewed. */

undefined4 FUN_402d57c4(HWND param_1,int param_2,short param_3,undefined4 *param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (param_2 == 0x110) {
    if ((undefined4 *)param_4[2] != (undefined4 *)0x0) {
      *(undefined4 *)param_4[2] = param_1;
    }
    SetWindowLongW(param_1,8,(LONG)param_4);
    uVar2 = GetWindowLongW(param_1,-0x14);
    SetWindowLongW(param_1,-0x14,uVar2 | 0x80000008);
    iVar3 = param_4[1];
    pcVar4 = *(code **)*param_4;
LAB_402d58ac:
    uVar5 = (*pcVar4)(param_1,iVar3);
  }
  else {
    if (param_2 != 0x111) {
      return 0;
    }
    piVar1 = (int *)GetWindowLongW(param_1,8);
    if (param_3 == 1) {
      if (piVar1 != (int *)0x0) {
        iVar3 = piVar1[1];
        pcVar4 = *(code **)(*piVar1 + 4);
        goto LAB_402d58ac;
      }
    }
    else if (param_3 != 2) {
      return 0;
    }
    EndDialog(param_1,0);
  }
  return uVar5;
}



/* 402d58d8 FUN_402d58d8 */

/* Boundary evidence: original MIPS .pdata 402d58d8..402d5a1f. Semantic name remains unreviewed. */

undefined4
FUN_402d58d8(LPCWSTR param_1,LPCWSTR param_2,HWND param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  HRSRC pHVar2;
  HGLOBAL pvVar3;
  HCURSOR hCursor;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar4;
  undefined4 uVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar1 = GetSystemMetrics(0);
  if (0x1df < iVar1) {
    param_2 = param_1;
  }
  local_2c = param_5;
  uVar5 = 0;
  local_28 = param_6;
  local_30 = param_4;
  pHVar2 = FindResourceW(DAT_402fc3c4,(LPCWSTR)((uint)param_2 & 0xffff),(LPCWSTR)0x5);
  if ((pHVar2 != (HRSRC)0x0) && (pvVar3 = LoadResource(DAT_402fc3c4,pHVar2), pvVar3 != (HGLOBAL)0x0)
     ) {
    hCursor = SetCursor((HCURSOR)0x0);
    pHVar2 = FindResourceW(DAT_402fc3c4,(LPCWSTR)((uint)param_2 & 0xffff),(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_402fc3c4,pHVar2);
    IVar4 = DialogBoxIndirectParamW
                      (DAT_402fc3c4,hDialogTemplate,param_3,FUN_402d57c4,(LPARAM)&local_30);
    if ((IVar4 != -1) && (IVar4 != 0)) {
      uVar5 = 1;
    }
    SetCursor(hCursor);
  }
  return uVar5;
}



/* 402d5a20 FUN_402d5a20 */

/* Boundary evidence: original MIPS .pdata 402d5a20..402d5b5f. Semantic name remains unreviewed. */

undefined4
FUN_402d5a20(short *param_1,undefined2 *param_2,uint *param_3,void *param_4,uint *param_5)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  uint uVar4;
  
  sVar1 = *param_1;
  psVar2 = param_1;
  do {
    if (sVar1 == 0) {
      if (*param_3 != 0) {
        *param_2 = 0;
        uVar4 = 0;
LAB_402d5a90:
        sVar1 = *psVar2;
        while (sVar1 != 0) {
          psVar2 = psVar2 + 1;
          sVar1 = *psVar2;
        }
        uVar3 = (int)psVar2 - (int)param_1 >> 1;
        if (uVar3 + 1 <= *param_5) {
          memcpy(param_4,param_1,uVar3 * 2);
          *(undefined2 *)(uVar3 * 2 + (int)param_4) = 0;
          *param_3 = uVar4;
          *param_5 = uVar3;
          return 0;
        }
      }
      return 0x7a;
    }
    if (sVar1 == 0x5c) {
      uVar4 = (int)psVar2 - (int)param_1 >> 1;
      if (*param_3 < uVar4 + 1) {
        return 0x7a;
      }
      memcpy(param_2,param_1,uVar4 * 2);
      param_2[uVar4] = 0;
      param_1 = psVar2 + 1;
      goto LAB_402d5a90;
    }
    psVar2 = psVar2 + 1;
    sVar1 = *psVar2;
  } while( true );
}



/* 402d5b60 FUN_402d5b60 */

/* Boundary evidence: original MIPS .pdata 402d5b60..402d5c77. Semantic name remains unreviewed. */

undefined4
FUN_402d5b60(undefined2 *param_1,uint *param_2,void *param_3,uint param_4,void *param_5,int param_6)

{
  uint uVar1;
  undefined2 *_Dst;
  
  if ((param_5 == (void *)0x0) || (param_6 == 0)) {
    *param_1 = 0;
    *param_2 = 0;
  }
  else {
    uVar1 = param_4 + param_6;
    if ((uVar1 < param_4) || (uVar1 + 2 < uVar1)) {
      return 0x54f;
    }
    if (*param_2 < uVar1 + 2) {
      return 0x7a;
    }
    _Dst = param_1;
    if ((param_3 != (void *)0x0) && (param_4 != 0)) {
      memcpy(param_1,param_3,param_4 * 2);
      param_1[param_4] = 0x5c;
      _Dst = param_1 + param_4 + 1;
    }
    memcpy(_Dst,param_5,param_6 * 2);
    _Dst[param_6] = 0;
    *param_2 = (param_6 * 2 - (int)param_1) + (int)_Dst >> 1;
  }
  return 0;
}



/* 402d5c78 FUN_402d5c78 */

/* Boundary evidence: original MIPS .pdata 402d5c78..402d5d6f. Semantic name remains unreviewed. */

undefined4
FUN_402d5c78(undefined4 param_1,int param_2,undefined2 *param_3,uint *param_4,void *param_5,
            uint *param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  short *psVar3;
  int local_18 [2];
  
  local_18[0] = 0;
  iVar1 = CredRead(param_1,param_2 + 1,0x10001,0x1800,local_18);
  if ((iVar1 == 0) && (local_18[0] != 0)) {
    *param_7 = 1;
    psVar3 = *(short **)(local_18[0] + 8);
  }
  else {
    psVar3 = (short *)&DAT_402d1054;
    *param_7 = 0;
    iVar1 = CredRead(&DAT_402d1054,1,0x10001,0x1800,local_18);
    if ((iVar1 == 0) && (local_18[0] != 0)) {
      psVar3 = *(short **)(local_18[0] + 8);
    }
  }
  uVar2 = FUN_402d5a20(psVar3,param_3,param_4,param_5,param_6);
  if (local_18[0] != 0) {
    CredFree();
  }
  return uVar2;
}



/* 402d5d70 FUN_402d5d70 */

/* Boundary evidence: original MIPS .pdata 402d5d70..402d5e63. Semantic name remains unreviewed. */

int FUN_402d5d70(undefined4 param_1,int param_2,void *param_3,uint param_4,void *param_5,int param_6
                ,int param_7,int param_8)

{
  int iVar1;
  uint local_270 [2];
  undefined4 local_268;
  undefined4 local_264;
  undefined2 *local_260;
  int local_25c;
  undefined4 local_258;
  int local_254;
  int local_250;
  int local_24c;
  undefined4 local_248;
  undefined2 auStack_240 [274];
  uint local_1c;
  
  local_1c = DAT_402f65fc;
  local_270[0] = 0x111;
  iVar1 = FUN_402d5b60(auStack_240,local_270,param_3,param_4,param_5,param_6);
  if (iVar1 == 0) {
    local_264 = 0x10001;
    local_268 = 1;
    local_248 = 3;
    local_254 = param_2 + 1;
    local_260 = auStack_240;
    local_25c = local_270[0] + 1;
    local_250 = param_7;
    if (param_7 == 0) {
      local_24c = 0;
    }
    else {
      local_24c = (param_8 + 1) * 2;
    }
    local_258 = param_1;
    iVar1 = CredWrite(&local_268,0);
  }
  FUN_402f41d8(local_1c);
  return iVar1;
}



/* 402d5e64 FUN_402d5e64 */

void FUN_402d5e64(short *param_1,short *param_2,uint *param_3)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  
  if (*param_1 == 0x5c) {
    sVar1 = 0x5c;
    do {
      if (sVar1 == 0) break;
      param_1 = param_1 + 1;
      sVar1 = *param_1;
    } while (sVar1 == 0x5c);
  }
  sVar1 = *param_1;
  if (sVar1 == 0) {
    *param_2 = 0;
    *param_3 = 0;
  }
  else {
    psVar3 = param_2;
    for (uVar2 = 0; ((sVar1 != 0x5c && (sVar1 != 0)) && (uVar2 < *param_3 - 1)); uVar2 = uVar2 + 1)
    {
      param_1 = param_1 + 1;
      *psVar3 = sVar1;
      sVar1 = *param_1;
      psVar3 = psVar3 + 1;
    }
    param_2[uVar2] = 0;
    *param_3 = uVar2;
  }
  return;
}



/* 402d5f0c FUN_402d5f0c */

/* Boundary evidence: original MIPS .pdata 402d5f0c..402d62ff. Semantic name remains unreviewed. */

undefined4 FUN_402d5f0c(HWND param_1,LPCWSTR param_2)

{
  int iVar1;
  HWND pHVar2;
  UINT UVar3;
  LPCWSTR pWVar4;
  uint uVar5;
  uint local_2c0 [4];
  WCHAR aWStack_2b0 [100];
  short local_1e8;
  undefined1 auStack_1e6 [198];
  WCHAR aWStack_120 [128];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  local_1e8 = 0;
  memset(auStack_1e6,0,0xc2);
  pWVar4 = param_2 + 0x214;
  local_2c0[0] = 0x62;
  FUN_402d5e64(pWVar4,&local_1e8,local_2c0);
  uVar5 = *(uint *)(param_2 + 0x212);
  if ((uVar5 & 0x20) == 0) {
    if ((uVar5 & 4) == 0) goto LAB_402d60f0;
    UVar3 = 0x22;
    if ((uVar5 & 0x10) == 0) {
      UVar3 = 0xe;
    }
    iVar1 = LoadStringW(DAT_402fc3c4,UVar3,aWStack_2b0,100);
    if (iVar1 != 0) {
      SetWindowTextW(param_1,aWStack_2b0);
    }
    iVar1 = LoadStringW(DAT_402fc3c4,0xf,aWStack_2b0,100);
    if (iVar1 != 0) {
      wsprintfW(aWStack_120,aWStack_2b0,pWVar4);
      SetDlgItemTextW(param_1,0x3ee,aWStack_120);
    }
    iVar1 = LoadStringW(DAT_402fc3c4,0x10,aWStack_2b0,100);
    if (iVar1 == 0) goto LAB_402d60f0;
    pWVar4 = aWStack_2b0;
    iVar1 = 0x400;
  }
  else {
    iVar1 = LoadStringW(DAT_402fc3c4,0x23,aWStack_2b0,100);
    if (iVar1 != 0) {
      SetWindowTextW(param_1,aWStack_2b0);
    }
    pHVar2 = GetDlgItem(param_1,0x412);
    ShowWindow(pHVar2,5);
    UVar3 = 0x25;
    if ((*(uint *)(param_2 + 0x212) & 0x40) == 0) {
      UVar3 = 0x24;
    }
    iVar1 = LoadStringW(DAT_402fc3c4,UVar3,aWStack_2b0,100);
    if (iVar1 != 0) {
      SetDlgItemTextW(param_1,0x412,aWStack_2b0);
    }
    pHVar2 = GetDlgItem(param_1,0x411);
    ShowWindow(pHVar2,5);
    SetDlgItemTextW(param_1,0x411,pWVar4);
    if ((*(uint *)(param_2 + 0x212) & 0x80) == 0) goto LAB_402d60f0;
    pWVar4 = param_2 + 0x276;
    iVar1 = 0x414;
  }
  SetDlgItemTextW(param_1,iVar1,pWVar4);
LAB_402d60f0:
  uVar5 = GetWindowLongW(param_1,-0x14);
  SetWindowLongW(param_1,-0x14,uVar5 | 0x80000008);
  if ((((*(uint *)(param_2 + 0x212) & 0x80) == 0) && (*param_2 == L'\0')) &&
     (param_2[0x202] == L'\0')) {
    local_2c0[1] = 0x10;
    local_2c0[2] = 0x101;
    FUN_402d5c78(&local_1e8,local_2c0[0],param_2 + 0x202,local_2c0 + 1,param_2,local_2c0 + 2,
                 local_2c0);
  }
  SetDlgItemTextW(param_1,0x4c2,param_2);
  SetDlgItemTextW(param_1,0x4c3,param_2 + 0x101);
  if ((*(uint *)(param_2 + 0x212) & 0x80) == 0) {
    SetDlgItemTextW(param_1,0x3f2,param_2 + 0x202);
  }
  if ((*param_2 == L'\0') || ((*(uint *)(param_2 + 0x212) & 8) != 0)) {
    pHVar2 = GetDlgItem(param_1,0x4c2);
    SetFocus(pHVar2);
  }
  else {
    pHVar2 = GetDlgItem(param_1,0x4c3);
    SetFocus(pHVar2);
    pHVar2 = GetDlgItem(param_1,0x4c3);
    SendMessageW(pHVar2,0xb1,0,-1);
  }
  iVar1 = FUN_402d5728();
  if (iVar1 != 0) {
    *(uint *)(param_2 + 0x212) = *(uint *)(param_2 + 0x212) & 0xfffffffe;
  }
  if (((*(uint *)(param_2 + 0x212) & 2) == 0) || (iVar1 != 0)) {
    pHVar2 = GetDlgItem(param_1,0x400);
    EnableWindow(pHVar2,0);
  }
  else {
    if ((*(uint *)(param_2 + 0x212) & 1) != 0) {
      pHVar2 = GetDlgItem(param_1,0x400);
      SendMessageW(pHVar2,0xf1,1,0);
    }
    pHVar2 = GetDlgItem(param_1,0x400);
    uVar5 = GetWindowLongW(pHVar2,-0x10);
    SetWindowLongW(pHVar2,-0x10,uVar5 | 0x10000000);
  }
  FUN_402f41d8(local_20);
  return 0;
}



/* 402d6300 FUN_402d6300 */

/* Boundary evidence: original MIPS .pdata 402d6300..402d64eb. Semantic name remains unreviewed. */

undefined4 FUN_402d6300(HWND param_1,LPWSTR param_2)

{
  UINT UVar1;
  UINT UVar2;
  HWND hWnd;
  LRESULT LVar3;
  uint uVar4;
  UINT UVar5;
  LPWSTR lpString;
  uint local_f0 [2];
  short local_e8;
  undefined1 auStack_e6 [194];
  uint local_24;
  
  local_24 = DAT_402f65fc;
  local_e8 = 0;
  UVar5 = 0;
  memset(auStack_e6,0,0xc2);
  local_f0[0] = 0x62;
  FUN_402d5e64(param_2 + 0x214,&local_e8,local_f0);
  UVar1 = GetDlgItemTextW(param_1,0x4c2,param_2,0x101);
  lpString = param_2 + 0x101;
  UVar2 = GetDlgItemTextW(param_1,0x4c3,lpString,0x101);
  if ((*(uint *)(param_2 + 0x212) & 0x80) == 0) {
    UVar5 = GetDlgItemTextW(param_1,0x3f2,param_2 + 0x202,0x10);
  }
  hWnd = GetDlgItem(param_1,0x400);
  LVar3 = SendMessageW(hWnd,0xf0,0,0);
  uVar4 = *(uint *)(param_2 + 0x212);
  if (LVar3 == 0) {
    if (((uVar4 & 0x80) == 0) && (*param_2 != L'\0')) {
      FUN_402d5d70(&local_e8,local_f0[0],param_2 + 0x202,UVar5,param_2,UVar1,0,0);
    }
    *(uint *)(param_2 + 0x212) = *(uint *)(param_2 + 0x212) & 0xfffffffe;
  }
  else {
    *(uint *)(param_2 + 0x212) = uVar4 | 1;
    if ((*param_2 != L'\0') && ((uVar4 & 0x80) == 0)) {
      FUN_402d5d70(&local_e8,local_f0[0],param_2 + 0x202,UVar5,param_2,UVar1,(int)lpString,UVar2);
      FUN_402d5d70(&DAT_402d1054,0,param_2 + 0x202,UVar5,param_2,UVar1,(int)lpString,UVar2);
    }
  }
  EndDialog(param_1,1);
  FUN_402f41d8(local_24);
  return 1;
}



/* 402d64ec GetUsernamePasswordEx */

/* Boundary evidence: original MIPS .pdata 402d64ec..402d65cf. Semantic name remains unreviewed. */

undefined4 GetUsernamePasswordEx(HWND param_1,int param_2,undefined4 param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  LPCWSTR pWVar3;
  LPCWSTR pWVar4;
  
                    /* 0x64ec  27  GetUsernamePasswordEx */
  pWVar3 = (LPCWSTR)0xc8;
  pWVar4 = (LPCWSTR)0x7c;
  SetLastError(0);
  if ((param_1 == (HWND)0x0) || (BVar1 = IsWindow(param_1), BVar1 != 0)) {
    if ((*(uint *)(param_2 + 0x424) & 8) == 0) {
      if ((*(uint *)(param_2 + 0x424) & 0x80) != 0) {
        pWVar3 = (LPCWSTR)0xc9;
        pWVar4 = (LPCWSTR)0x7e;
      }
    }
    else {
      pWVar3 = (LPCWSTR)0x6d;
      pWVar4 = (LPCWSTR)0x6d;
    }
    uVar2 = FUN_402d58d8(pWVar4,pWVar3,param_1,&PTR_FUN_402d1150,param_2,param_3);
  }
  else {
    SetLastError(0x578);
    uVar2 = 0;
  }
  return uVar2;
}



/* 402d65d0 GetUsernamePassword */

/* Boundary evidence: original MIPS .pdata 402d65d0..402d65eb. Semantic name remains unreviewed. */

void GetUsernamePassword(HWND param_1,int param_2)

{
                    /* 0x65d0  26  GetUsernamePassword */
  GetUsernamePasswordEx(param_1,param_2,0);
  return;
}



/* 402d65ec FUN_402d65ec */

/* Boundary evidence: original MIPS .pdata 402d65ec..402d6683. Semantic name remains unreviewed. */

int FUN_402d65ec(HWND param_1,UINT param_2,UINT param_3,UINT param_4)

{
  int iVar1;
  WCHAR aWStack_420 [256];
  WCHAR aWStack_220 [256];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  LoadStringW(DAT_402fc3c4,param_2,aWStack_220,0x100);
  LoadStringW(DAT_402fc3c4,param_3,aWStack_420,0x100);
  iVar1 = MessageBoxW(param_1,aWStack_220,aWStack_420,param_4);
  FUN_402f41d8(local_20);
  return iVar1;
}



/* 402d6684 FUN_402d6684 */

/* Boundary evidence: original MIPS .pdata 402d6684..402d66ab. Semantic name remains unreviewed. */

undefined4 FUN_402d6684(HWND param_1)

{
  HWND hWnd;
  
  hWnd = GetDlgItem(param_1,0x4d1);
  SetFocus(hWnd);
  return 1;
}



/* 402d66ac FUN_402d66ac */

/* Boundary evidence: original MIPS .pdata 402d66ac..402d678b. Semantic name remains unreviewed. */

undefined4 FUN_402d66ac(HWND param_1,wchar_t *param_2)

{
  int iVar1;
  WCHAR *pWVar2;
  WCHAR local_218 [258];
  uint local_14;
  
  local_14 = DAT_402f65fc;
  GetDlgItemTextW(param_1,0x4d1,param_2,0x101);
  GetDlgItemTextW(param_1,0x4d2,local_218,0x101);
  iVar1 = wcscmp(param_2,local_218);
  if (iVar1 == 0) {
    EndDialog(param_1,1);
  }
  else {
    FUN_402d65ec(param_1,0x51,0x50,0);
    SetDlgItemTextW(param_1,0x4d1,L"");
    SetDlgItemTextW(param_1,0x4d2,L"");
  }
  iVar1 = 0x202;
  pWVar2 = local_218;
  do {
    *(undefined1 *)pWVar2 = 0;
    iVar1 = iVar1 + -1;
    pWVar2 = (WCHAR *)((int)pWVar2 + 1);
  } while (iVar1 != 0);
  FUN_402f41d8(local_14);
  return 1;
}



/* 402d678c GetNewPasswordEx */

/* Boundary evidence: original MIPS .pdata 402d678c..402d67bf. Semantic name remains unreviewed. */

void GetNewPasswordEx(HWND param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x678c  22  GetNewPasswordEx */
  FUN_402d58d8((LPCWSTR)0x7f,(LPCWSTR)0xcd,param_1,&PTR_FUN_402d1158,param_2,param_3);
  return;
}



/* 402d67c0 GetNewPassword */

/* Boundary evidence: original MIPS .pdata 402d67c0..402d67f3. Semantic name remains unreviewed. */

void GetNewPassword(HWND param_1,undefined4 param_2)

{
                    /* 0x67c0  21  GetNewPassword */
  FUN_402d58d8((LPCWSTR)0x7f,(LPCWSTR)0xcd,param_1,&PTR_FUN_402d1158,param_2,0);
  return;
}



/* 402d67f4 CloseUsernamePasswordDialog */

/* Boundary evidence: original MIPS .pdata 402d67f4..402d680f. Semantic name remains unreviewed. */

void CloseUsernamePasswordDialog(HWND param_1)

{
                    /* 0x67f4  5  CloseUsernamePasswordDialog */
  EndDialog(param_1,0);
  return;
}



/* 402d6810 GetUsernamePasswordExExt */

/* Boundary evidence: original MIPS .pdata 402d6810..402d68d7. Semantic name remains unreviewed. */

undefined4
GetUsernamePasswordExExt
          (int param_1,uint param_2,DWORD *param_3,undefined4 param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  HWND pHVar5;
  
                    /* 0x6810  28  GetUsernamePasswordExExt */
  if (param_2 < 0x5bc) {
    SetLastError(0x57);
    uVar1 = 0;
  }
  else {
    pDVar4 = param_3 + 0x16e;
    *param_5 = param_4;
    pHVar5 = *(HWND *)(param_1 + 4);
    if (*pDVar4 == 0) {
      pDVar4 = (DWORD *)0x0;
    }
    *param_3 = 0;
    SetLastError(0);
    iVar2 = GetUsernamePasswordEx(pHVar5,(int)(param_3 + 2),pDVar4);
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      *param_3 = DVar3;
      if (DVar3 == 0) {
        *param_3 = 0x4c7;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 402d68d8 GetNewPasswordExExt */

/* Boundary evidence: original MIPS .pdata 402d68d8..402d6997. Semantic name remains unreviewed. */

undefined4
GetNewPasswordExExt(int param_1,uint param_2,DWORD *param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  HWND pHVar4;
  
                    /* 0x68d8  23  GetNewPasswordExExt */
  if (param_2 < 0x210) {
    SetLastError(0x57);
  }
  else {
    pDVar3 = param_3 + 0x83;
    *param_5 = param_4;
    pHVar4 = *(HWND *)(param_1 + 4);
    if (*pDVar3 == 0) {
      pDVar3 = (DWORD *)0x0;
    }
    *param_3 = 0;
    SetLastError(0);
    iVar1 = GetNewPasswordEx(pHVar4,param_3 + 2,pDVar3);
    if (iVar1 != 0) {
      return 1;
    }
    DVar2 = GetLastError();
    *param_3 = DVar2;
  }
  return 0;
}



/* 402d6998 CloseUsernamePasswordDialogExt */

/* Boundary evidence: original MIPS .pdata 402d6998..402d6a2b. Semantic name remains unreviewed. */

undefined4
CloseUsernamePasswordDialogExt
          (int param_1,uint param_2,DWORD *param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  DWORD DVar2;
  HWND pHVar3;
  
                    /* 0x6998  6  CloseUsernamePasswordDialogExt */
  if (param_2 < 8) {
    SetLastError(0x57);
  }
  else {
    *param_5 = param_4;
    pHVar3 = *(HWND *)(param_1 + 4);
    *param_3 = 0;
    SetLastError(0);
    iVar1 = CloseUsernamePasswordDialog(pHVar3);
    if (iVar1 != 0) {
      return 1;
    }
    DVar2 = GetLastError();
    *param_3 = DVar2;
  }
  return 0;
}



/* 402d6a2c FUN_402d6a2c */

/* Boundary evidence: original MIPS .pdata 402d6a2c..402d6b97. Semantic name remains unreviewed. */

undefined4 FUN_402d6a2c(HWND param_1,int param_2,short param_3,LPCWSTR param_4)

{
  LPWSTR lpString;
  int iVar1;
  uint uVar2;
  HWND hWnd;
  INT_PTR nResult;
  WCHAR aWStack_1e8 [100];
  WCHAR aWStack_120 [128];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  if (param_2 != 2) {
    if (param_2 == 0x110) {
      SetWindowLongW(param_1,8,(LONG)param_4);
      iVar1 = LoadStringW(DAT_402fc3c4,0xf,aWStack_1e8,100);
      if (iVar1 != 0) {
        wsprintfW(aWStack_120,aWStack_1e8,param_4 + 0x101);
        SetDlgItemTextW(param_1,0x3ee,aWStack_120);
      }
      uVar2 = GetWindowLongW(param_1,-0x14);
      SetWindowLongW(param_1,-0x14,uVar2 | 0x80000008);
      SetDlgItemTextW(param_1,0x4c3,param_4);
      hWnd = GetDlgItem(param_1,0x4c3);
      SetFocus(hWnd);
    }
    else if (param_2 == 0x111) {
      lpString = (LPWSTR)GetWindowLongW(param_1,8);
      if (param_3 == 1) {
        GetDlgItemTextW(param_1,0x4c3,lpString,0x100);
        nResult = 1;
      }
      else {
        if (param_3 != 2) goto LAB_402d6b70;
        nResult = 0;
      }
      EndDialog(param_1,nResult);
    }
  }
LAB_402d6b70:
  FUN_402f41d8(local_20);
  return 0;
}



/* 402d6b98 FUN_402d6b98 */

/* Boundary evidence: original MIPS .pdata 402d6b98..402d6ce7. Semantic name remains unreviewed. */

undefined4 FUN_402d6b98(HWND param_1,int param_2,short param_3,LPCWSTR param_4)

{
  LPWSTR lpString;
  HWND pHVar1;
  INT_PTR nResult;
  int nIDDlgItem;
  
  if (param_2 != 2) {
    if (param_2 == 0x110) {
      if (param_4 != (LPCWSTR)0x0) {
        SetDlgItemTextW(param_1,0x3e9,param_4 + 0x6c);
        SetDlgItemTextW(param_1,1000,param_4);
        nIDDlgItem = 0x3e9;
        if (param_4[0x6c] != L'\0') {
          pHVar1 = GetDlgItem(param_1,0x3e9);
          SendMessageW(pHVar1,0xcf,*(WPARAM *)(param_4 + 0xce),0);
          nIDDlgItem = 1000;
        }
        pHVar1 = GetDlgItem(param_1,nIDDlgItem);
        SetFocus(pHVar1);
        SetWindowLongW(param_1,-0x15,(LONG)param_4);
      }
    }
    else if (param_2 == 0x111) {
      lpString = (LPWSTR)GetWindowLongW(param_1,-0x15);
      if (param_3 == 1) {
        GetDlgItemTextW(param_1,1000,lpString,0x6c);
        GetDlgItemTextW(param_1,0x3e9,lpString + 0x6c,0x62);
        nResult = 1;
      }
      else {
        if (param_3 != 2) {
          return 0;
        }
        nResult = 0;
      }
      EndDialog(param_1,nResult);
    }
  }
  return 0;
}



/* 402d6ce8 FUN_402d6ce8 */

/* Boundary evidence: original MIPS .pdata 402d6ce8..402d6db7. Semantic name remains unreviewed. */

void FUN_402d6ce8(HWND param_1,INT_PTR param_2)

{
  HWND hWnd;
  LRESULT LVar1;
  HLOCAL hMem;
  WPARAM wParam;
  
  hWnd = GetDlgItem(param_1,0x3e9);
  LVar1 = SendMessageW(hWnd,0x18b,0,0);
  if ((LVar1 != -1) && (wParam = 0, 0 < LVar1)) {
    do {
      hMem = (HLOCAL)SendMessageW(hWnd,0x199,wParam,0);
      if ((hMem != (HLOCAL)0xffffffff) && (hMem != (HLOCAL)0x0)) {
        LocalFree(hMem);
      }
      wParam = wParam + 1;
    } while ((int)wParam < LVar1);
  }
  EndDialog(param_1,param_2);
  return;
}



/* 402d6db8 FUN_402d6db8 */

/* Boundary evidence: original MIPS .pdata 402d6db8..402d70db. Semantic name remains unreviewed. */

undefined4 FUN_402d6db8(HWND param_1,int param_2,short param_3,undefined4 param_4)

{
  HWND hWnd;
  WPARAM WVar1;
  LRESULT LVar2;
  int iVar3;
  HLOCAL hMem;
  wchar_t *pwVar4;
  INT_PTR IVar5;
  int iVar6;
  undefined4 local_120;
  undefined4 local_11c;
  SIZE_T local_118 [2];
  undefined4 local_110;
  HWND local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  WCHAR aWStack_f8 [100];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  hWnd = GetDlgItem(param_1,0x3e9);
  if (param_2 != 2) {
    if (param_2 == 0x110) {
      iVar6 = 1;
      iVar3 = (*DAT_402f6624)(1,param_4,0,0,&local_120);
      if (iVar3 == 0) {
LAB_402d6f60:
        do {
          local_118[0] = 0;
          local_11c = 1;
          iVar3 = (*DAT_402f6628)(local_120,&local_11c,0,local_118);
          if (iVar3 != 0x103) {
            hMem = LocalAlloc(0,local_118[0]);
            if (hMem == (HLOCAL)0x0) {
              iVar3 = 8;
            }
            else {
              local_11c = 1;
              iVar3 = (*DAT_402f6628)(local_120,&local_11c,hMem,local_118);
              if (iVar3 == 0) {
                pwVar4 = *(wchar_t **)((int)hMem + 0x10);
                if (*(wchar_t **)((int)hMem + 0x10) == (wchar_t *)0x0) {
                  pwVar4 = L"(none)";
                }
                wsprintfW(aWStack_f8,L"%.49s\t%.49s",pwVar4,*(undefined4 *)((int)hMem + 0x14));
                LVar2 = SendMessageW(hWnd,399,0,(LPARAM)aWStack_f8);
                if (((LVar2 == -1) &&
                    (WVar1 = SendMessageW(hWnd,0x180,0,(LPARAM)aWStack_f8), WVar1 != 0xffffffff)) &&
                   (WVar1 != 0xfffffffe)) {
                  SendMessageW(hWnd,0x19a,WVar1,(LPARAM)hMem);
                }
                else {
                  LocalFree(hMem);
                }
                goto LAB_402d6f60;
              }
            }
          }
          (*DAT_402f6630)(local_120);
          if (iVar3 != 0x103) goto LAB_402d6e4c;
          if (iVar6 != 1) {
            SendMessageW(hWnd,0x186,0,0);
            break;
          }
          iVar6 = 3;
          iVar3 = (*DAT_402f6624)(3,param_4,0,0,&local_120);
        } while (iVar3 == 0);
      }
    }
    else if (param_2 == 0x111) {
      IVar5 = 1;
      if (param_3 == 1) {
        WVar1 = SendMessageW(hWnd,0x188,0,0);
        LVar2 = SendMessageW(hWnd,0x199,WVar1,0);
        if ((LVar2 != -1) && (LVar2 != 0)) {
          local_108 = *(undefined4 *)(LVar2 + 0x10);
          local_110 = 0x14;
          local_104 = *(undefined4 *)(LVar2 + 0x14);
          local_100 = 1;
          local_10c = param_1;
          iVar3 = (*DAT_402f662c)(&local_110);
          if (iVar3 != 0) {
            IVar5 = 0;
          }
        }
      }
      else {
        if (param_3 != 2) goto LAB_402d6e58;
LAB_402d6e4c:
        IVar5 = 0;
      }
      FUN_402d6ce8(param_1,IVar5);
    }
  }
LAB_402d6e58:
  FUN_402f41d8(local_30);
  return 0;
}



/* 402d70dc ConnectionDialog */

/* Boundary evidence: original MIPS .pdata 402d70dc..402d71f7. Semantic name remains unreviewed. */

INT_PTR ConnectionDialog(HWND param_1,LPARAM param_2)

{
  int iVar1;
  HRSRC pHVar2;
  HGLOBAL pvVar3;
  HCURSOR hCursor;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar4;
  LPCWSTR lpName;
  
                    /* 0x70dc  7  ConnectionDialog */
  iVar1 = GetSystemMetrics(0);
  lpName = (LPCWSTR)0xca;
  if (0x1df < iVar1) {
    lpName = (LPCWSTR)0x6a;
  }
  pHVar2 = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
  if ((pHVar2 != (HRSRC)0x0) && (pvVar3 = LoadResource(DAT_402fc3c4,pHVar2), pvVar3 != (HGLOBAL)0x0)
     ) {
    hCursor = SetCursor((HCURSOR)0x0);
    pHVar2 = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_402fc3c4,pHVar2);
    IVar4 = DialogBoxIndirectParamW(DAT_402fc3c4,hDialogTemplate,param_1,FUN_402d6b98,param_2);
    SetCursor(hCursor);
    if (IVar4 != -1) {
      return IVar4;
    }
  }
  return 0;
}



/* 402d71f8 DisconnectDialog */

/* Boundary evidence: original MIPS .pdata 402d71f8..402d73d7. Semantic name remains unreviewed. */

undefined4 DisconnectDialog(HWND param_1,LPARAM param_2)

{
  int iVar1;
  HMODULE hLibModule;
  HRSRC pHVar2;
  HGLOBAL pvVar3;
  HCURSOR hCursor;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar4;
  LPCWSTR lpName;
  
                    /* 0x71f8  10  DisconnectDialog */
  iVar1 = GetSystemMetrics(0);
  lpName = (LPCWSTR)0xcb;
  if (0x1df < iVar1) {
    lpName = (LPCWSTR)0x6b;
  }
  hLibModule = LoadLibraryW(L"coredll.dll");
  if (hLibModule != (HMODULE)0x0) {
    DAT_402f6624 = GetProcAddressW(hLibModule,L"WNetOpenEnumW");
    if ((((DAT_402f6624 == 0) ||
         (DAT_402f6628 = GetProcAddressW(hLibModule,L"WNetEnumResourceW"), DAT_402f6628 == 0)) ||
        (DAT_402f6630 = GetProcAddressW(hLibModule,L"WNetCloseEnum"), DAT_402f6630 == 0)) ||
       (DAT_402f662c = GetProcAddressW(hLibModule,L"WNetDisconnectDialog1W"), DAT_402f662c == 0)) {
      FreeLibrary(hLibModule);
    }
    else {
      pHVar2 = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
      if ((pHVar2 != (HRSRC)0x0) &&
         (pvVar3 = LoadResource(DAT_402fc3c4,pHVar2), pvVar3 != (HGLOBAL)0x0)) {
        hCursor = SetCursor((HCURSOR)0x0);
        pHVar2 = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
        hDialogTemplate = LoadResource(DAT_402fc3c4,pHVar2);
        IVar4 = DialogBoxIndirectParamW(DAT_402fc3c4,hDialogTemplate,param_1,FUN_402d6db8,param_2);
        SetCursor(hCursor);
        FreeLibrary(hLibModule);
        if (IVar4 != -1) {
          return 1;
        }
      }
    }
  }
  return 0;
}



/* 402d73d8 GetResourcePassword */

/* Boundary evidence: original MIPS .pdata 402d73d8..402d74f3. Semantic name remains unreviewed. */

INT_PTR GetResourcePassword(HWND param_1,LPARAM param_2)

{
  int iVar1;
  HRSRC pHVar2;
  HGLOBAL pvVar3;
  HCURSOR hCursor;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar4;
  LPCWSTR lpName;
  
                    /* 0x73d8  24  GetResourcePassword */
  iVar1 = GetSystemMetrics(0);
  lpName = (LPCWSTR)0xcc;
  if (0x1df < iVar1) {
    lpName = (LPCWSTR)0x6c;
  }
  pHVar2 = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
  if ((pHVar2 != (HRSRC)0x0) && (pvVar3 = LoadResource(DAT_402fc3c4,pHVar2), pvVar3 != (HGLOBAL)0x0)
     ) {
    hCursor = SetCursor((HCURSOR)0x0);
    pHVar2 = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_402fc3c4,pHVar2);
    IVar4 = DialogBoxIndirectParamW(DAT_402fc3c4,hDialogTemplate,param_1,FUN_402d6a2c,param_2);
    SetCursor(hCursor);
    if (IVar4 != -1) {
      return IVar4;
    }
  }
  return 0;
}



/* 402d74f4 GetResourcePasswordExt */

/* Boundary evidence: original MIPS .pdata 402d74f4..402d7543. Semantic name remains unreviewed. */

bool GetResourcePasswordExt
               (int param_1,int param_2,INT_PTR *param_3,undefined4 param_4,undefined4 *param_5)

{
  INT_PTR IVar1;
  
                    /* 0x74f4  25  GetResourcePasswordExt */
  if (param_2 == 0x2d0) {
    *param_5 = param_4;
    IVar1 = GetResourcePassword(*(HWND *)(param_1 + 4),param_1 + 8);
    *param_3 = IVar1;
  }
  return param_2 == 0x2d0;
}



/* 402d7544 ConnectionDialogExt */

/* Boundary evidence: original MIPS .pdata 402d7544..402d7593. Semantic name remains unreviewed. */

bool ConnectionDialogExt(int param_1,int param_2,INT_PTR *param_3,undefined4 param_4,
                        undefined4 *param_5)

{
  INT_PTR IVar1;
  
                    /* 0x7544  8  ConnectionDialogExt */
  if (param_2 == 0x1a8) {
    *param_5 = param_4;
    IVar1 = ConnectionDialog(*(HWND *)(param_1 + 4),param_1 + 8);
    *param_3 = IVar1;
  }
  return param_2 == 0x1a8;
}



/* 402d7594 DisconnectDialogExt */

/* Boundary evidence: original MIPS .pdata 402d7594..402d7607. Semantic name remains unreviewed. */

undefined4
DisconnectDialogExt(int param_1,int param_2,DWORD *param_3,undefined4 param_4,undefined4 *param_5)

{
  undefined4 *in_zero;
  undefined4 uVar1;
  int iVar2;
  DWORD DVar3;
  HWND pHVar4;
  LPARAM LVar5;
  
                    /* 0x7594  11  DisconnectDialogExt */
  if (param_2 == 0xc) {
    *param_5 = param_4;
    pHVar4 = *(HWND *)(param_1 + 4);
    LVar5 = *(LPARAM *)(param_1 + 8);
    *param_3 = 0;
    iVar2 = DisconnectDialog(pHVar4,LVar5);
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      *param_3 = DVar3;
    }
    uVar1 = 1;
  }
  else {
    *in_zero = 0x57;
    uVar1 = 0;
  }
  return uVar1;
}



/* 402d7608 FUN_402d7608 */

/* Boundary evidence: original MIPS .pdata 402d7608..402d766b. Semantic name remains unreviewed. */

LRESULT FUN_402d7608(HWND param_1,WPARAM param_2,uint param_3)

{
  LRESULT LVar1;
  BOOL BVar2;
  
  LVar1 = SendMessageW(param_1,0x100c,param_2,param_3 & 0xffff);
  if ((LVar1 == 0) && (BVar2 = IsWindow(param_1), BVar2 == 0)) {
    LVar1 = -1;
  }
  return LVar1;
}



/* 402d766c FUN_402d766c */

/* Boundary evidence: original MIPS .pdata 402d766c..402d76d7. Semantic name remains unreviewed. */

uint * FUN_402d766c(uint *param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5)

{
  memset(param_1,0,0x250);
  param_1[0x88] = param_3;
  param_1[0x89] = param_4;
  *(undefined1 *)(param_1 + 0x8b) = 0xfc;
  *param_1 = param_5;
  FUN_402f2fe0(param_5,(int)param_1);
  return param_1;
}



/* 402d76d8 FUN_402d76d8 */

/* Boundary evidence: original MIPS .pdata 402d76d8..402d778b. Semantic name remains unreviewed. */

DWORD FUN_402d76d8(HANDLE param_1,DWORD param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE local_res0 [4];
  tagMSG tStack_30;
  
  local_res0[0] = param_1;
  do {
    iVar1 = PeekMessageW(&tStack_30,(HWND)0x0,0,0,1);
    while (iVar1 != 0) {
      if (tStack_30.message == 0x12) {
        return 0xffffffff;
      }
      DispatchMessageW(&tStack_30);
      iVar1 = PeekMessageW(&tStack_30,(HWND)0x0,0,0,1);
    }
    DVar2 = MsgWaitForMultipleObjectsEx(1,local_res0,param_2,0x7f,0);
  } while (DVar2 == 1);
  return DVar2;
}



/* 402d77bc FUN_402d77bc */

/* Boundary evidence: original MIPS .pdata 402d77bc..402d789b. Semantic name remains unreviewed. */

undefined4 FUN_402d77bc(HWND param_1,int param_2,short param_3)

{
  HWND hWnd;
  wchar_t *nResult;
  WCHAR aWStack_90 [64];
  uint local_10;
  
  local_10 = DAT_402f65fc;
  if (param_2 != 2) {
    if (param_2 == 0x110) {
      SetForegroundWindow(param_1);
      hWnd = GetDlgItem(param_1,0x7df);
      SetFocus(hWnd);
      goto LAB_402d7830;
    }
    if (param_2 != 0x111) goto LAB_402d7830;
  }
  if (param_3 == 2) {
LAB_402d7824:
    nResult = (wchar_t *)0x0;
  }
  else {
    if (param_3 != 0x7e1) {
      if (param_3 != 0x7e2) goto LAB_402d7830;
      goto LAB_402d7824;
    }
    SetForegroundWindow(param_1);
    GetDlgItemTextW(param_1,0x7df,aWStack_90,0x40);
    nResult = _wcsdup(aWStack_90);
  }
  EndDialog(param_1,(INT_PTR)nResult);
LAB_402d7830:
  FUN_402f41d8(local_10);
  return 0;
}



/* 402d789c FUN_402d789c */

/* Boundary evidence: original MIPS .pdata 402d789c..402d7963. Semantic name remains unreviewed. */

undefined4 FUN_402d789c(HWND param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  LRESULT LVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  memset(param_2,0,0x2c);
  *param_2 = 6;
  param_2[4] = 0xffffffff;
  if (0 < param_4) {
    *param_2 = 7;
    param_2[5] = param_3;
    param_2[6] = param_4;
  }
  LVar1 = FUN_402d7608(param_1,0xffffffff,2);
  param_2[1] = LVar1;
  if (LVar1 == -1) {
    uVar2 = 0x490;
  }
  else {
    SendMessageW(param_1,0x104b,0,(LPARAM)param_2);
  }
  return uVar2;
}



/* 402d7964 FUN_402d7964 */

/* Boundary evidence: original MIPS .pdata 402d7964..402d7b7f. Semantic name remains unreviewed. */

undefined4 FUN_402d7964(void)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_48;
  wchar_t *local_44;
  size_t local_40;
  uint local_3c;
  int local_38;
  
  iVar6 = 0;
  iVar5 = 0;
  uVar4 = 0;
  if (DAT_402f892c != 0) {
    piVar3 = &DAT_402f683c;
    do {
      memset(&local_58,0,0x2c);
      iVar2 = *piVar3;
      local_58 = 7;
      local_44 = (wchar_t *)(iVar2 + 8);
      local_48 = 0xffffffff;
      local_40 = wcslen(local_44);
      if ((*(uint *)(iVar2 + 0x228) & 1) == 0) {
        local_3c = *(undefined4 *)(iVar2 + 0x254);
      }
      else {
        local_3c = *(undefined4 *)(iVar2 + 0x250);
      }
      local_38 = iVar2;
      if (((*(uint *)(iVar2 + 0x228) & 2) == 0) && (DAT_402f8930 == 0)) {
        local_54 = iVar6;
        SendMessageW(DAT_402f7f0c,0x104d,0,(LPARAM)&local_58);
        SendMessageW(DAT_402f7f0c,0x104c,0,(LPARAM)&local_58);
        iVar6 = iVar6 + 1;
      }
      else {
        local_54 = iVar5;
        SendMessageW(DAT_402f7f1c,0x104d,0,(LPARAM)&local_58);
        if (DAT_402f8930 != 0) {
          local_50 = 0;
          local_58 = 7;
          local_3c = (uint)((*(uint *)(*piVar3 + 0x228) & 2) == 0);
          SendMessageW(DAT_402f7f1c,0x104c,0,(LPARAM)&local_58);
          iVar2 = *piVar3;
          local_58 = 3;
          local_50 = 1;
          if ((*(uint *)(iVar2 + 0x228) & 1) == 0) {
            local_3c = *(undefined4 *)(iVar2 + 0x254);
          }
          else {
            local_3c = *(undefined4 *)(iVar2 + 0x250);
          }
        }
        SendMessageW(DAT_402f7f1c,0x104c,0,(LPARAM)&local_58);
        iVar5 = iVar5 + 1;
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar4 < DAT_402f892c);
  }
  bVar1 = DAT_402f8930 != 0;
  if (!bVar1) {
    SendMessageW(DAT_402f7f0c,0x101e,0,0xffff);
  }
  SendMessageW(DAT_402f7f1c,0x101e,(uint)bVar1,0xffff);
  return 1;
}



/* 402d7b80 FUN_402d7b80 */

/* Boundary evidence: original MIPS .pdata 402d7b80..402d7c6f. Semantic name remains unreviewed. */

HIMAGELIST FUN_402d7b80(void)

{
  HICON hicon;
  uint uVar1;
  
  if (DAT_402f8934 == (HIMAGELIST)0x0) {
    DAT_402f8934 = ImageList_Create(0x10,0x10,0,0,5);
    uVar1 = 0;
    do {
      hicon = LoadImageW(DAT_402f6eec,(LPCWSTR)(uint)*(ushort *)((int)&DAT_402f6378 + uVar1),1,0x10,
                         0x10,0);
      ImageList_ReplaceIcon(DAT_402f8934,-1,hicon);
      DestroyIcon(hicon);
      uVar1 = uVar1 + 4;
    } while (uVar1 < 100);
  }
  return DAT_402f8934;
}



/* 402d7c70 FUN_402d7c70 */

/* Boundary evidence: original MIPS .pdata 402d7c70..402d7e7b. Semantic name remains unreviewed. */

undefined4 FUN_402d7c70(HWND param_1,int param_2)

{
  HMENU hMenu;
  HMENU pHVar1;
  DWORD DVar2;
  LPCWSTR lpMenuName;
  undefined4 local_50;
  LRESULT local_4c;
  undefined4 local_40;
  int *local_30;
  
  memset(&local_50,0,0x2c);
  local_50 = 4;
  local_40 = 0xffffffff;
  local_4c = FUN_402d7608(DAT_402f7f1c,0xffffffff,1);
  if (local_4c == -1) {
    return 0;
  }
  SendMessageW(DAT_402f7f1c,0x104b,0,(LPARAM)&local_50);
  lpMenuName = (LPCWSTR)0x84a;
  if (param_2 == 0) {
    lpMenuName = (LPCWSTR)0x849;
  }
  hMenu = LoadMenuW(DAT_402f6eec,lpMenuName);
  if (hMenu == (HMENU)0x0) {
    return 0;
  }
  pHVar1 = GetSubMenu(hMenu,0);
  if (pHVar1 == (HMENU)0x0) goto LAB_402d7e4c;
  if (*local_30 == -1) {
    EnableMenuItem(hMenu,0x848,1);
  }
  if ((local_30[0x8a] & 2U) == 0) {
    EnableMenuItem(hMenu,0x848,1);
LAB_402d7e04:
    EnableMenuItem(hMenu,0x84d,1);
    EnableMenuItem(hMenu,0x84e,1);
  }
  else {
    if ((local_30[0x8a] & 1U) != 0) {
      CheckMenuItem(hMenu,0x848,8);
    }
    if ((local_30[0x8a] & 4U) != 0) {
      CheckMenuItem(hMenu,0x84d,8);
    }
    if ((local_30[0x8a] & 8U) != 0) {
      CheckMenuItem(hMenu,0x84e,8);
    }
    if (param_2 != 0) {
      CheckMenuItem(hMenu,0x84b,8);
    }
    if (((local_30[0x8a] & 1U) != 0) && (local_30[1] != 0)) goto LAB_402d7e04;
  }
  DVar2 = GetMessagePos();
  TrackPopupMenuEx(pHVar1,0,DVar2 & 0xffff,DVar2 >> 0x10,param_1,(LPTPMPARAMS)0x0);
LAB_402d7e4c:
  DestroyMenu(hMenu);
  return 0;
}



/* 402d7e7c FUN_402d7e7c */

/* Boundary evidence: original MIPS .pdata 402d7e7c..402d7f9f. Semantic name remains unreviewed. */

void FUN_402d7e7c(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  switch(*param_1) {
  case 0:
    param_1[0x95] = 3;
    uVar2 = 4;
    goto LAB_402d7ed4;
  case 1:
    param_1[0x95] = 5;
    uVar2 = 6;
    break;
  case 2:
    uVar2 = 7;
    uVar1 = 8;
    goto LAB_402d7ef4;
  case 3:
    param_1[0x95] = 9;
    uVar2 = 10;
    goto LAB_402d7ed4;
  case 4:
    param_1[0x95] = 0xb;
    uVar2 = 0xc;
    break;
  case 5:
    uVar2 = 0xd;
    uVar1 = 0xe;
    goto LAB_402d7ef4;
  case 6:
    param_1[0x95] = 0xf;
    uVar2 = 0x10;
    break;
  case 7:
    if ((param_1[0x8c] & 0x40) != 0) {
      param_1[0x95] = 0x11;
      param_1[0x94] = 0x12;
      return;
    }
    uVar2 = 0x13;
    uVar1 = 0x14;
    goto LAB_402d7ef4;
  case 8:
    uVar2 = 0x15;
    uVar1 = 0x16;
LAB_402d7ef4:
    param_1[0x95] = uVar2;
    param_1[0x94] = uVar1;
    return;
  case 9:
    param_1[0x95] = 0x17;
    uVar2 = 0x18;
LAB_402d7ed4:
    param_1[0x94] = uVar2;
    return;
  default:
    uVar2 = 2;
    param_1[0x95] = 2;
  }
  param_1[0x94] = uVar2;
  return;
}



/* 402d7fa0 FUN_402d7fa0 */

/* Boundary evidence: original MIPS .pdata 402d7fa0..402d8043. Semantic name remains unreviewed. */

bool FUN_402d7fa0(undefined4 param_1,void *param_2)

{
  undefined4 *_Dst;
  uint uVar1;
  
  _Dst = operator_new(600);
  if (_Dst == (undefined4 *)0x0) {
    _Dst = (undefined4 *)0x0;
  }
  else {
    memcpy(_Dst,param_2,0x250);
    _Dst[0x95] = 2;
    _Dst[0x94] = 2;
  }
  uVar1 = DAT_402f892c;
  (&DAT_402f683c)[DAT_402f892c] = _Dst;
  if (_Dst != (undefined4 *)0x0) {
    FUN_402d7e7c(_Dst);
    uVar1 = uVar1 + 1;
    DAT_402f892c = uVar1;
  }
  return uVar1 < 0x28;
}



/* 402d8044 FUN_402d8044 */

undefined4 FUN_402d8044(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x1103;
  }
  else if ((param_1 == 1) || (param_1 == 6)) {
    uVar1 = 0x1101;
  }
  else if (param_1 == 2) {
    uVar1 = 0x1102;
  }
  else if (param_1 == 3) {
    uVar1 = 0x1106;
  }
  else if (param_1 == 4) {
    uVar1 = 0x1105;
  }
  else if (param_1 == 5) {
    uVar1 = 0x1108;
  }
  else if (param_1 == 8) {
    uVar1 = 0xf;
  }
  else if (param_1 == 9) {
    uVar1 = 0x111e;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 402d80f8 FUN_402d80f8 */

/* Boundary evidence: original MIPS .pdata 402d80f8..402d82c3. Semantic name remains unreviewed. */

undefined4 FUN_402d80f8(wint_t *param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  *param_2 = 0;
  param_2[1] = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  iVar6 = 0;
  do {
    iVar1 = iswctype(*param_1,0x80);
    if (iVar1 == 0) goto LAB_402d82a0;
    uVar3 = (uint)*param_1;
    if (uVar3 < 0x61) {
      iVar1 = uVar3 - 0x37;
      if (uVar3 < 0x41) {
        iVar1 = uVar3 - 0x30;
      }
    }
    else {
      iVar1 = uVar3 - 0x57;
    }
    if ((iVar1 < 0) || (0x10 < iVar1)) goto LAB_402d82a0;
    uVar4 = *param_2;
    uVar3 = (uint)((ulonglong)uVar4 * 0x10);
    iVar6 = iVar6 + 1;
    param_1 = param_1 + 1;
    uVar5 = uVar3 + iVar1;
    *param_2 = uVar5;
    param_2[1] = param_2[1] * 0x10 + (int)((ulonglong)uVar4 * 0x10 >> 0x20) + (iVar1 >> 0x1f) +
                 (uint)(uVar5 < uVar3);
  } while (iVar6 < 4);
  iVar6 = 0;
  do {
    iVar1 = iswctype(*param_1,0x80);
    if (iVar1 == 0) goto LAB_402d82a0;
    uVar3 = (uint)*param_1;
    if (uVar3 < 0x61) {
      iVar1 = uVar3 - 0x37;
      if (uVar3 < 0x41) {
        iVar1 = uVar3 - 0x30;
      }
    }
    else {
      iVar1 = uVar3 - 0x57;
    }
    if ((iVar1 < 0) || (0x10 < iVar1)) goto LAB_402d82a0;
    uVar4 = *param_2;
    uVar3 = (uint)((ulonglong)uVar4 * 0x10);
    iVar6 = iVar6 + 1;
    param_1 = param_1 + 1;
    uVar5 = uVar3 + iVar1;
    *param_2 = uVar5;
    param_2[1] = param_2[1] * 0x10 + (int)((ulonglong)uVar4 * 0x10 >> 0x20) + (iVar1 >> 0x1f) +
                 (uint)(uVar5 < uVar3);
  } while (iVar6 < 8);
  if ((*param_1 == 0x20) || (*param_1 == 0)) {
    uVar2 = 1;
  }
  else {
LAB_402d82a0:
    uVar2 = 0;
  }
  return uVar2;
}



/* 402d82c4 FUN_402d82c4 */

/* Boundary evidence: original MIPS .pdata 402d82c4..402d8437. Semantic name remains unreviewed. */

int FUN_402d82c4(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_28;
  undefined1 auStack_24 [4];
  
  pcVar1 = DAT_402f7f10;
  *param_3 = 0;
  *param_4 = 0;
  local_28 = (int *)0x0;
  iVar2 = (*pcVar1)(&UNK_402d1574,0,1,&UNK_402d1584,&local_28);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*local_28 + 0xc))(local_28,param_1,param_2,auStack_24);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*local_28 + 0x68))(local_28,param_1,param_2,6,0,param_4);
      if ((-1 < iVar2) && (*param_4 != 0)) {
        uVar3 = (*DAT_402f7f14)(*param_4 << 2);
        *param_3 = uVar3;
        iVar2 = (**(code **)(*local_28 + 0x14))(local_28,param_1,param_2,uVar3,param_4);
        if (iVar2 < 0) {
          (*DAT_402f6ee4)(*param_3);
          *param_3 = 0;
          *param_4 = 0;
        }
      }
    }
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))();
    }
  }
  return iVar2;
}



/* 402d8438 FUN_402d8438 */

/* Boundary evidence: original MIPS .pdata 402d8438..402d8517. Semantic name remains unreviewed. */

int FUN_402d8438(int param_1,int param_2)

{
  LRESULT LVar1;
  int iVar2;
  undefined4 local_48;
  int local_44;
  undefined4 local_38;
  int local_28;
  
  LVar1 = SendMessageW(DAT_402f7f1c,0x1004,0,0);
  iVar2 = 0;
  if (0 < LVar1) {
    do {
      memset(&local_48,0,0x2c);
      local_48 = 4;
      local_38 = 0xffffffff;
      local_44 = iVar2;
      SendMessageW(DAT_402f7f1c,0x104b,0,(LPARAM)&local_48);
      if (((param_1 == *(int *)(local_28 + 0x220)) && (param_2 == *(int *)(local_28 + 0x224))) &&
         ((*(uint *)(local_28 + 0x228) & 2) != 0)) {
        return local_28;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < LVar1);
  }
  return 0;
}



/* 402d8518 FUN_402d8518 */

/* Boundary evidence: original MIPS .pdata 402d8518..402d8623. Semantic name remains unreviewed. */

int * FUN_402d8518(int param_1,int param_2,int param_3)

{
  LRESULT LVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_50;
  int local_4c;
  undefined4 local_40;
  int *local_30;
  
  LVar1 = SendMessageW(DAT_402f7f1c,0x1004,0,0);
  iVar3 = 0;
  if (0 < LVar1) {
    do {
      memset(&local_50,0,0x2c);
      local_50 = 4;
      local_40 = 0xffffffff;
      local_4c = iVar3;
      SendMessageW(DAT_402f7f1c,0x104b,0,(LPARAM)&local_50);
      if (((param_1 == local_30[0x88]) && (param_2 == local_30[0x89])) && (param_3 == *local_30)) {
        return local_30;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < LVar1);
  }
  if (param_3 == -1) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_402d8518(param_1,param_2,-1);
  }
  return piVar2;
}



/* 402d8624 FUN_402d8624 */

/* Boundary evidence: original MIPS .pdata 402d8624..402d872f. Semantic name remains unreviewed. */

void FUN_402d8624(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_48;
  int local_44;
  undefined4 local_38;
  int local_2c;
  int *local_28;
  
  iVar2 = SendMessageW(DAT_402f7f1c,0x1004,0,0);
  while (iVar2 = iVar2 + -1, -1 < iVar2) {
    memset(&local_48,0,0x2c);
    local_48 = 6;
    local_38 = 0xffffffff;
    local_44 = iVar2;
    SendMessageW(DAT_402f7f1c,0x104b,0,(LPARAM)&local_48);
    piVar1 = local_28;
    if (*local_28 == param_1) {
      if ((local_28[0x8a] & 1U) != 0) {
        FUN_402f23e4(local_28);
      }
      if ((piVar1[0x8a] & 1U) == 0) {
        local_2c = piVar1[0x95];
      }
      else {
        local_2c = piVar1[0x94];
      }
      SendMessageW(DAT_402f7f1c,0x104c,0,(LPARAM)&local_48);
      FUN_402f1d80(piVar1);
    }
  }
  return;
}



/* 402d8730 FUN_402d8730 */

/* Boundary evidence: original MIPS .pdata 402d8730..402d87f3. Semantic name remains unreviewed. */

void FUN_402d8730(HWND param_1,int param_2)

{
  WPARAM wParam;
  undefined4 local_40;
  WPARAM local_3c;
  undefined4 local_30;
  int local_20;
  
  wParam = SendMessageW(param_1,0x1004,0,0);
  do {
    wParam = wParam - 1;
    if ((int)wParam < 0) {
      return;
    }
    memset(&local_40,0,0x2c);
    local_40 = 4;
    local_30 = 0xffffffff;
    local_3c = wParam;
    SendMessageW(param_1,0x104b,0,(LPARAM)&local_40);
  } while (local_20 != param_2);
  SendMessageW(param_1,0x1008,wParam,0);
  return;
}



/* 402d87f4 FUN_402d87f4 */

/* Boundary evidence: original MIPS .pdata 402d87f4..402d884f. Semantic name remains unreviewed. */

void FUN_402d87f4(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x220);
  iVar1 = FUN_402d8438(*piVar2,*(int *)(param_1 + 0x224));
  if (iVar1 == 0) {
    (*DAT_402f6ef4)(piVar2);
    (*DAT_402f6838)(piVar2);
  }
  return;
}



/* 402d8850 FUN_402d8850 */

/* Boundary evidence: original MIPS .pdata 402d8850..402d88f3. Semantic name remains unreviewed. */

void FUN_402d8850(int *param_1)

{
  uint uVar1;
  DWORD DVar2;
  WCHAR aWStack_218 [262];
  uint local_c;
  
  local_c = DAT_402f65fc;
  if (*param_1 == 6) {
    FUN_402d8624(6);
  }
  uVar1 = FUN_402f2a40(param_1,1);
  if (uVar1 == 0) {
    DVar2 = GetLastError();
    wsprintfW(aWStack_218,L"%s %d",&DAT_402f68dc,DVar2 & 0xffff);
    MessageBoxW((HWND)0x0,aWStack_218,(LPCWSTR)&DAT_402f7b0c,0x40000);
  }
  FUN_402f41d8(local_c);
  return;
}



/* 402d88f4 FUN_402d88f4 */

/* Boundary evidence: original MIPS .pdata 402d88f4..402d8a0b. Semantic name remains unreviewed. */

undefined4 FUN_402d88f4(void)

{
  LRESULT LVar1;
  undefined4 uVar2;
  WPARAM wParam;
  tagRECT local_40;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_1c;
  
  wParam = 0;
  local_30 = 0xb;
  local_1c = 0;
  GetWindowRect(DAT_402f7f1c,&local_40);
  local_28 = (local_40.right - local_40.left) + 10;
  local_2c = 0x800;
  uVar2 = 0xffffffff;
  if (DAT_402f8930 != 0) {
    local_1c = 0;
    local_28 = 0x14;
    LVar1 = SendMessageW(DAT_402f7f1c,0x1061,0,(LPARAM)&local_30);
    if (LVar1 == -1) {
      return 0xffffffff;
    }
    wParam = 1;
    local_28 = (local_40.right - local_40.left) + -10;
    local_1c = 1;
  }
  local_30 = 9;
  LVar1 = SendMessageW(DAT_402f7f1c,0x1061,wParam,(LPARAM)&local_30);
  if ((LVar1 != -1) &&
     ((DAT_402f8930 != 0 ||
      (LVar1 = SendMessageW(DAT_402f7f0c,0x1061,wParam,(LPARAM)&local_30), LVar1 != -1)))) {
    uVar2 = FUN_402d7964();
  }
  return uVar2;
}



/* 402d8a0c FUN_402d8a0c */

/* Boundary evidence: original MIPS .pdata 402d8a0c..402d8d2b. Semantic name remains unreviewed. */

void FUN_402d8a0c(void)

{
  LSTATUS LVar1;
  int iVar2;
  uint *puVar3;
  undefined *puVar4;
  uint uVar5;
  int *piVar6;
  DWORD dwIndex;
  DWORD local_78;
  DWORD local_74;
  DWORD local_70;
  HKEY local_6c;
  uint local_68;
  uint local_64;
  WCHAR aWStack_60 [3];
  wint_t awStack_5a [13];
  BYTE aBStack_40 [16];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  DAT_402f892c = 0;
  FUN_402f30a8(0,FUN_402d7fa0);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"software\\microsoft\\bluetooth\\security",0,0x20019,
                        &local_6c);
  if (LVar1 == 0) {
    local_70 = 0x10;
    dwIndex = 0;
    local_78 = 0x10;
    local_74 = 0;
    iVar2 = RegEnumValueW(local_6c,0,aWStack_60,&local_70,(LPDWORD)0x0,&local_74,aBStack_40,
                          &local_78);
    if (iVar2 != 0x103) {
      do {
        local_68 = 0;
        local_64 = 0;
        if ((((((iVar2 == 0) && (local_74 == 3)) && (3 < local_70)) &&
             ((iVar2 = FUN_402d80f8(awStack_5a,&local_68), iVar2 != 0 && (local_78 == 0x10)))) &&
            (puVar4 = &DAT_402d15a0, iVar2 = _wcsnicmp(aWStack_60,L"key",3), iVar2 == 0)) ||
           (((local_78 < 0x11 && (local_78 != 0)) &&
            (puVar4 = &DAT_402d15a8, iVar2 = _wcsnicmp(aWStack_60,L"pin",3), iVar2 == 0)))) {
          uVar5 = 0;
          if (DAT_402f892c != 0) {
            piVar6 = &DAT_402f683c;
            do {
              if ((*(uint *)(*piVar6 + 0x220) == local_68) &&
                 (*(uint *)(*piVar6 + 0x224) == local_64)) break;
              uVar5 = uVar5 + 1;
              piVar6 = piVar6 + 1;
            } while (uVar5 < DAT_402f892c);
          }
          if (uVar5 != DAT_402f892c) goto LAB_402d8c90;
          puVar3 = operator_new(600);
          if (puVar3 == (uint *)0x0) {
            puVar3 = (uint *)0x0;
          }
          else {
            FUN_402d766c(puVar3,puVar4,local_68,local_64,0xffffffff);
            puVar3[0x95] = 2;
            puVar3[0x94] = 2;
          }
          piVar6 = &DAT_402f683c + DAT_402f892c;
          *piVar6 = (int)puVar3;
          if (puVar3 != (uint *)0x0) {
            puVar3[0x8a] = puVar3[0x8a] | 2;
            iVar2 = *piVar6;
            wsprintfW((LPWSTR)(iVar2 + 8),L"%s (%04x%08x)",&DAT_402f74fc,
                      (uint)*(ushort *)(iVar2 + 0x224),*(undefined4 *)(iVar2 + 0x220));
            FUN_402f1d80((int *)(&DAT_402f683c)[DAT_402f892c]);
            DAT_402f892c = DAT_402f892c + 1;
            goto LAB_402d8c90;
          }
        }
        else {
LAB_402d8c90:
          dwIndex = dwIndex + 1;
        }
        local_70 = 0x10;
        local_78 = 0x10;
        local_74 = 0;
        iVar2 = RegEnumValueW(local_6c,dwIndex,aWStack_60,&local_70,(LPDWORD)0x0,&local_74,
                              aBStack_40,&local_78);
      } while (iVar2 != 0x103);
    }
    RegCloseKey(local_6c);
  }
  FUN_402f41d8(local_30);
  return;
}



/* 402d8d2c FUN_402d8d2c */

/* Boundary evidence: original MIPS .pdata 402d8d2c..402d8f73. Semantic name remains unreviewed. */

undefined4 FUN_402d8d2c(void)

{
  short sVar1;
  HINSTANCE hModule;
  int iVar2;
  HWND pHVar3;
  HWND pHVar4;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  short *_Memory;
  short *psVar5;
  undefined4 uVar6;
  undefined2 local_70 [4];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 auStack_60 [8];
  int local_40;
  undefined1 local_30 [16];
  uint local_20;
  
  pHVar4 = DAT_402f7700;
  hModule = DAT_402f6eec;
  local_20 = DAT_402f65fc;
  if (DAT_402f6ee0 != 0) {
    DAT_402f6ee0 = 0;
    (*DAT_402f7f20)();
  }
  pHVar3 = DAT_402f7f0c;
  if (DAT_402f8930 != 0) {
    pHVar3 = DAT_402f7f1c;
  }
  iVar2 = FUN_402d789c(pHVar3,auStack_60,0,0);
  if (iVar2 == 0) {
    local_68 = *(undefined4 *)(local_40 + 0x220);
    local_64 = *(undefined4 *)(local_40 + 0x224);
    pHVar3 = GetParent(DAT_402f7700);
    iVar2 = MessageBoxW(pHVar3,(LPCWSTR)&DAT_402f72fc,(LPCWSTR)&DAT_402f7904,0x23);
    if (iVar2 == 6) {
      pHVar4 = GetParent(pHVar4);
      uVar6 = 5;
      hResInfo = FindResourceW(hModule,(LPCWSTR)0x838,(LPCWSTR)0x5);
      hDialogTemplate = LoadResource(hModule,hResInfo);
      _Memory = (short *)DialogBoxIndirectParamW(hModule,hDialogTemplate,pHVar4,FUN_402d77bc,0);
      if (_Memory == (short *)0x0) {
        FUN_402f41d8(local_20);
        return 4;
      }
      sVar1 = *_Memory;
      psVar5 = _Memory;
      for (iVar2 = 0; (sVar1 != 0 && (iVar2 < 0x10)); iVar2 = iVar2 + 1) {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
        local_30[iVar2] = (char)sVar1;
        sVar1 = *psVar5;
      }
      free(_Memory);
      (*DAT_402f6edc)(&local_68,iVar2,local_30);
      if (DAT_402f8928 != (HANDLE)0x0) {
        FUN_402d76d8(DAT_402f8928,0xffffffff);
        CloseHandle(DAT_402f8928);
        DAT_402f8928 = (HANDLE)0x0;
      }
      local_70[0] = 0;
      iVar2 = (*DAT_402f7b08)(&local_68,local_70);
      if (iVar2 == 0) {
        iVar2 = (*DAT_402f6ef8)(&local_68);
        (*DAT_402f8724)(local_70[0]);
        uVar6 = 4;
        if (iVar2 == 0) {
          uVar6 = 1;
        }
      }
    }
    else {
      uVar6 = 2;
      if ((iVar2 != 7) && (iVar2 == 2)) {
        FUN_402f41d8(local_20);
        return 3;
      }
    }
    FUN_402f41d8(local_20);
  }
  else {
    FUN_402f41d8(local_20);
    uVar6 = 0;
  }
  return uVar6;
}



/* 402d8f74 FUN_402d8f74 */

/* Boundary evidence: original MIPS .pdata 402d8f74..402d909f. Semantic name remains unreviewed. */

undefined4 FUN_402d8f74(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int local_40;
  undefined4 *local_3c;
  undefined1 auStack_38 [8];
  byte local_30;
  uint local_20;
  
  local_20 = DAT_402f65fc;
  local_40 = 0;
  *param_3 = 0;
  iVar1 = FUN_402d82c4(param_1,param_2,&local_3c,&local_40);
  if (iVar1 == 0) {
    uVar3 = 0;
    iVar1 = 0;
    puVar4 = local_3c;
    if (0 < local_40) {
      do {
        iVar2 = (**(code **)(*(int *)*puVar4 + 0x1c))((int *)*puVar4,0x202,auStack_38);
        if (iVar2 == 0) {
          uVar3 = 1;
          *param_3 = (uint)local_30;
          break;
        }
        iVar1 = iVar1 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar1 < local_40);
    }
    iVar1 = 0;
    puVar4 = local_3c;
    if (0 < local_40) {
      do {
        (**(code **)(*(int *)*puVar4 + 8))();
        iVar1 = iVar1 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar1 < local_40);
    }
    (*DAT_402f6ee4)(local_3c);
    FUN_402f41d8(local_20);
  }
  else {
    FUN_402f41d8(local_20);
    uVar3 = 0;
  }
  return uVar3;
}



/* 402d90a0 FUN_402d90a0 */

/* Boundary evidence: original MIPS .pdata 402d90a0..402d953b. Semantic name remains unreviewed. */

int FUN_402d90a0(undefined4 param_1,undefined4 param_2,char *param_3,void *param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *_Buf2;
  char cVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  undefined4 *local_d8;
  void *local_d4;
  uint local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined1 auStack_c0 [2];
  short local_be;
  undefined4 local_b8;
  short local_a8;
  short local_a6;
  int local_a0 [4];
  short local_90;
  short local_8e;
  uint local_88 [4];
  short local_78 [4];
  int *local_70;
  short local_60 [4];
  int *local_58;
  short local_48 [4];
  int *local_40;
  uint local_30;
  
  local_30 = DAT_402f65fc;
  bVar1 = false;
  local_e8 = 0;
  *param_3 = '\0';
  local_d4 = param_4;
  iVar3 = FUN_402d82c4(param_1,param_2,&local_d8,&local_e8);
  if (-1 < iVar3) {
    cVar7 = *param_3;
    puVar8 = local_d8;
    puVar10 = local_d8;
    for (iVar3 = 0; (cVar7 == '\0' && (iVar3 < local_e8)); iVar3 = iVar3 + 1) {
      piVar9 = (int *)*puVar8;
      if (param_4 == (void *)0x0) {
LAB_402d926c:
        iVar4 = (**(code **)(*piVar9 + 0x1c))(piVar9,4,local_60);
        piVar9 = local_58;
        if ((iVar4 == 0) && (local_60[0] == 0x20)) {
          local_dc = 0;
          (**(code **)(*local_58 + 0x30))(local_58,&local_dc);
          cVar7 = *param_3;
          param_4 = local_d4;
          for (iVar4 = 0;
              (local_d4 = param_4, cVar7 == '\0' && (puVar10 = local_d8, iVar4 < local_dc));
              iVar4 = iVar4 + 1) {
            (**(code **)(*piVar9 + 0x28))(piVar9,iVar4,local_48);
            piVar2 = local_40;
            if (local_48[0] == 0x20) {
              local_e4 = 0;
              (**(code **)(*local_40 + 0x30))(local_40,&local_e4);
              iVar5 = 0;
              do {
                if ((*param_3 != '\0') || (local_e4 <= iVar5)) break;
                (**(code **)(*piVar2 + 0x28))(piVar2,iVar5,&local_a8);
                if (local_a8 == 3) {
                  if (local_a6 == 0x130) {
                    if ((short)local_a0[0] == 3) goto LAB_402d9374;
                  }
                  else if (local_a6 == 0x230) {
                    if (local_a0[0] == 3) {
LAB_402d9374:
                      if (iVar5 + 1 != local_e4) {
                        (**(code **)(*piVar2 + 0x28))(piVar2,iVar5 + 1,auStack_c0);
                        cVar7 = (char)local_b8;
                        if ((((local_be != 0x10) && (local_be != 0x20)) && (local_be != 0x110)) &&
                           (((local_be != 0x120 && (local_be != 0x210)) && (local_be != 0x220)))) {
                          cVar7 = '\0';
                        }
                        *param_3 = cVar7;
                      }
                      break;
                    }
                  }
                  else if ((local_a6 == 0x430) &&
                          (iVar6 = memcmp(&DAT_402d12b4,local_a0,0x10), iVar6 == 0))
                  goto LAB_402d9374;
                }
                iVar5 = iVar5 + 1;
              } while( true );
            }
            cVar7 = *param_3;
            puVar10 = local_d8;
            param_4 = local_d4;
          }
        }
      }
      else {
        iVar4 = (**(code **)(*piVar9 + 0x1c))(piVar9,1,local_78);
        piVar2 = local_70;
        if ((iVar4 == 0) && (local_78[0] == 0x20)) {
          local_e0 = 0;
          (**(code **)(*local_70 + 0x30))(local_70,&local_e0);
          iVar4 = 0;
          if (0 < local_e0) {
            do {
              if (bVar1) goto LAB_402d926c;
              (**(code **)(*piVar2 + 0x28))(piVar2,iVar4,&local_90);
              if (local_90 == 3) {
                if (local_8e == 0x430) {
                  _Buf2 = local_88;
                }
                else {
                  local_cc = 0x10000000;
                  local_d0 = 0;
                  local_c8 = 0x80000080;
                  local_c4 = 0xfb349b5f;
                  if (local_8e == 0x130) {
                    local_d0 = local_88[0] & 0xffff;
                  }
                  else if (local_8e == 0x230) {
                    local_d0 = local_88[0];
                  }
                  _Buf2 = &local_d0;
                }
                iVar5 = memcmp(param_4,_Buf2,0x10);
                if (iVar5 == 0) {
                  bVar1 = true;
                }
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < local_e0);
          }
          if (bVar1) goto LAB_402d926c;
        }
      }
      cVar7 = *param_3;
      puVar8 = puVar8 + 1;
    }
    iVar3 = 0;
    puVar8 = puVar10;
    if (0 < local_e8) {
      do {
        (**(code **)(*(int *)*puVar8 + 8))();
        iVar3 = iVar3 + 1;
        puVar8 = puVar8 + 1;
      } while (iVar3 < local_e8);
    }
    (*DAT_402f6ee4)(puVar10);
    if (*param_3 == '\0') {
      iVar3 = -0x7fffbffb;
    }
    else {
      iVar3 = 0;
    }
  }
  FUN_402f41d8(local_30);
  return iVar3;
}



/* 402d953c FUN_402d953c */

/* Boundary evidence: original MIPS .pdata 402d953c..402d9793. Semantic name remains unreviewed. */

int FUN_402d953c(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_68;
  int local_64;
  short local_60;
  short local_5e;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  short local_48 [4];
  int *local_40;
  uint local_30;
  
  local_30 = DAT_402f65fc;
  bVar1 = false;
  local_64 = 0;
  iVar4 = FUN_402d82c4(param_1,param_2,&local_68,&local_64);
  puVar2 = local_68;
  if (-1 < iVar4) {
    iVar4 = 0;
    puVar7 = local_68;
    do {
      if (local_64 <= iVar4) break;
      iVar5 = (**(code **)(*(int *)*puVar7 + 0x1c))((int *)*puVar7,1,local_48);
      piVar3 = local_40;
      if ((iVar5 == 0) && (local_48[0] == 0x20)) {
        local_68 = (undefined4 *)0x0;
        (**(code **)(*local_40 + 0x30))(local_40,&local_68);
        for (iVar5 = 0; (!bVar1 && (iVar5 < (int)local_68)); iVar5 = iVar5 + 1) {
          (**(code **)(*piVar3 + 0x28))(piVar3,iVar5,&local_60);
          if (local_60 == 3) {
            if (local_5e == 0x130) {
              *param_3 = 0;
              param_3[1] = 0x10000000;
              param_3[2] = 0x80000080;
              uVar6 = local_58 & 0xffff;
LAB_402d9678:
              *param_3 = uVar6;
              uVar6 = 0xfb349b5f;
            }
            else {
              if (local_5e == 0x230) {
                *param_3 = 0;
                param_3[1] = 0x10000000;
                param_3[2] = 0x80000080;
                uVar6 = local_58;
                goto LAB_402d9678;
              }
              if (local_5e != 0x430) goto LAB_402d96e8;
              *param_3 = local_58;
              param_3[1] = local_54;
              param_3[2] = local_50;
              uVar6 = local_4c;
            }
            param_3[3] = uVar6;
            bVar1 = true;
          }
LAB_402d96e8:
        }
      }
      iVar4 = iVar4 + 1;
      puVar7 = puVar7 + 1;
    } while (!bVar1);
    iVar4 = 0;
    puVar7 = puVar2;
    if (0 < local_64) {
      do {
        (**(code **)(*(int *)*puVar7 + 8))();
        iVar4 = iVar4 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar4 < local_64);
    }
    (*DAT_402f6ee4)(puVar2);
    if (bVar1) {
      iVar4 = 0;
    }
    else {
      iVar4 = -0x7fffbffb;
    }
  }
  FUN_402f41d8(local_30);
  return iVar4;
}



/* 402d9794 FUN_402d9794 */

/* Boundary evidence: original MIPS .pdata 402d9794..402d996f. Semantic name remains unreviewed. */

void FUN_402d9794(void)

{
  void *pvVar1;
  LRESULT LVar2;
  LRESULT LVar3;
  HWND hWnd;
  HLOCAL hMem;
  WPARAM WVar4;
  undefined4 local_48;
  WPARAM local_44;
  undefined4 local_38;
  void *local_28;
  
  if (DAT_402f8930 == 0) {
    LVar2 = SendMessageW(DAT_402f7f0c,0x1004,0,0);
    if (0 < LVar2) {
      do {
        memset(&local_48,0,0x2c);
        local_48 = 4;
        local_38 = 0xffffffff;
        local_44 = 0;
        SendMessageW(DAT_402f7f0c,0x104b,0,(LPARAM)&local_48);
        pvVar1 = local_28;
        LVar3 = SendMessageW(DAT_402f7f0c,0x1008,0,0);
        if ((LVar3 != 0) && (pvVar1 != (void *)0x0)) {
          if (*(HLOCAL *)((int)pvVar1 + 0x248) != (HLOCAL)0x0) {
            LocalFree(*(HLOCAL *)((int)pvVar1 + 0x248));
          }
          operator_delete(pvVar1);
        }
        LVar2 = LVar2 + -1;
      } while (LVar2 != 0);
    }
    WVar4 = 0;
    hWnd = DAT_402f7f0c;
  }
  else {
    while( true ) {
      WVar4 = SendMessageW(DAT_402f7f1c,0x1004,0,0);
      do {
        WVar4 = WVar4 - 1;
        if ((int)WVar4 < 0) goto LAB_402d98fc;
        memset(&local_48,0,0x2c);
        local_48 = 4;
        local_38 = 0xffffffff;
        local_44 = WVar4;
        SendMessageW(DAT_402f7f1c,0x104b,0,(LPARAM)&local_48);
        pvVar1 = local_28;
      } while ((*(uint *)((int)local_28 + 0x228) & 2) != 0);
      LVar2 = SendMessageW(DAT_402f7f1c,0x1008,WVar4,0);
      if (LVar2 == 0) break;
      hMem = *(HLOCAL *)((int)pvVar1 + 0x248);
      if (hMem != (HLOCAL)0x0) {
        LocalFree(hMem);
      }
      operator_delete(pvVar1);
    }
LAB_402d98fc:
    WVar4 = 1;
    hWnd = DAT_402f7f1c;
  }
  SendMessageW(hWnd,0x101e,WVar4,0xffff);
  return;
}



/* 402d9970 FUN_402d9970 */

/* Boundary evidence: original MIPS .pdata 402d9970..402d9e1f. Semantic name remains unreviewed. */

int FUN_402d9970(undefined4 *param_1,int param_2,char *param_3,undefined4 *param_4,SIZE_T *param_5,
                uint *param_6,uint *param_7)

{
  undefined4 uVar1;
  HLOCAL _Dst;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_1568;
  undefined4 local_1564;
  uint *local_1560;
  undefined4 *local_155c;
  undefined4 *local_1558;
  SIZE_T *local_1554;
  undefined4 local_1550;
  undefined4 *local_154c;
  undefined1 auStack_1548 [8];
  undefined2 *local_1540;
  undefined4 local_153c;
  undefined4 local_1530 [5];
  undefined4 local_151c;
  undefined1 *local_1500;
  undefined4 *local_14f8;
  undefined4 local_14f0;
  undefined4 local_14ec;
  undefined4 local_14e8;
  undefined4 local_14e4;
  undefined2 local_14e0 [4];
  undefined4 local_14d8;
  undefined4 local_14d4;
  undefined4 local_14b8 [2];
  undefined4 local_14b0;
  undefined4 local_14ac;
  undefined4 local_14a8;
  undefined4 local_14a4;
  undefined2 local_14a0;
  undefined4 local_13c0;
  undefined2 local_13bc;
  undefined2 local_13ba;
  undefined4 local_13b8 [5];
  undefined4 local_13a4;
  SIZE_T *local_1380;
  uint local_30;
  
  local_30 = DAT_402f65fc;
  local_1554 = param_5;
  *param_3 = '\0';
  *param_4 = 0;
  *param_5 = 0;
  local_1560 = param_6;
  *param_6 = 0;
  local_155c = param_4;
  local_1558 = param_1;
  (*DAT_402f6ef0)(0,0);
  iVar3 = 0;
  iVar4 = 0;
  do {
    if ((param_2 != 6) || (iVar2 = 2, *param_3 != '\0')) {
      iVar2 = 1;
    }
    if (iVar2 <= iVar4) {
      (*DAT_402f76fc)();
      FUN_402f41d8(local_30);
      return iVar3;
    }
    memset(local_14b8,0,0x100);
    local_13ba = 1;
    local_14b8[0] = 3;
    local_13c0 = 1;
    if (param_2 == 7) {
      local_14b0 = 0x1124;
      local_14ac = 0x10000000;
      local_14a8 = 0x80000080;
      local_14a4 = 0xfb349b5f;
LAB_402d9ac0:
      local_13ba = 0xffff;
      local_14a0 = 0x430;
      local_13bc = 0;
    }
    else {
      if (param_2 == 6) {
        if (iVar4 == 0) {
          local_14b0 = 0x350278f;
          local_14ac = 0x4e623dca;
          local_14a8 = 0x11a41d83;
          local_14a4 = 0x6c90ff65;
          goto LAB_402d9ac0;
        }
LAB_402d9b08:
        local_13bc = 4;
LAB_402d9b1c:
        local_13ba = 4;
        iVar3 = param_2;
      }
      else {
        if (param_2 != 8) {
          if ((param_2 != 5) && (param_2 != 9)) goto LAB_402d9b08;
          local_13bc = 1;
          goto LAB_402d9b1c;
        }
        local_13bc = 1;
        iVar3 = 8;
      }
      local_14a0 = 0x130;
      uVar1 = FUN_402d8044(iVar3);
      local_14b0 = CONCAT22(local_14b0._2_2_,(short)uVar1);
    }
    local_1550 = 0x100;
    local_154c = local_14b8;
    memset(local_14e0,0,0x28);
    local_14d8 = *local_1558;
    local_14d4 = local_1558[1];
    local_14e0[0] = 0x20;
    memset(auStack_1548,0,0x18);
    local_1540 = local_14e0;
    local_153c = 0x28;
    memset(local_1530,0,0x3c);
    local_1530[0] = 0x3c;
    local_151c = 0x10;
    local_14f8 = &local_1550;
    local_1500 = auStack_1548;
    iVar3 = (*DAT_402f7f18)(local_1530,0,&local_1568);
    if (iVar3 == 0) {
      local_1564 = 5000;
      memset(local_13b8,0,0x3c);
      local_13b8[0] = 0x3c;
      local_13a4 = 0x10;
      local_1380 = (SIZE_T *)0x0;
      iVar3 = (*DAT_402f6834)(local_1568,0,&local_1564,local_13b8);
      if (iVar3 == 0) {
        if (local_1380 == (SIZE_T *)0x0) goto LAB_402d9dd0;
        if (param_2 == 5) {
          local_14f0 = 0x1108;
LAB_402d9d44:
          local_14e8 = 0x80000080;
          local_14ec = 0x10000000;
          local_14e4 = 0xfb349b5f;
          iVar2 = FUN_402d90a0(local_1380[1],*local_1380,param_3,&local_14f0);
          if (iVar2 == 0) {
            if (param_2 == 5) {
              *param_7 = 0x1108;
              param_7[1] = 0x10000000;
              param_7[2] = 0x80000080;
            }
            else {
              if (param_2 != 9) goto LAB_402d9dc4;
              *param_7 = 0x111e;
              param_7[1] = 0x10000000;
              param_7[2] = 0x80000080;
            }
            param_7[3] = 0xfb349b5f;
          }
          else {
LAB_402d9d64:
            *param_3 = '\0';
          }
        }
        else if (param_2 == 7) {
          iVar2 = FUN_402d8f74(local_1380[1],*local_1380,local_1560);
          if (iVar2 != 0) {
            _Dst = LocalAlloc(0,*local_1380);
            *local_155c = _Dst;
            if (_Dst != (HLOCAL)0x0) {
              memcpy(_Dst,(void *)local_1380[1],*local_1380);
              *local_1554 = *local_1380;
            }
          }
        }
        else if (param_2 == 8) {
          FUN_402d953c(local_1380[1],*local_1380,param_7);
        }
        else {
          if (param_2 == 9) {
            local_14f0 = 0x111e;
            goto LAB_402d9d44;
          }
          iVar2 = FUN_402d90a0(local_1380[1],*local_1380,param_3,(void *)0x0);
          if (iVar2 != 0) goto LAB_402d9d64;
        }
      }
LAB_402d9dc4:
      (*DAT_402f7f20)(local_1568);
    }
LAB_402d9dd0:
    iVar4 = iVar4 + 1;
  } while( true );
}



/* 402d9e20 FUN_402d9e20 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 402d9e20..402da493. Semantic name remains unreviewed. */

undefined4 FUN_402d9e20(void)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  HWND pHVar4;
  HWND hWnd;
  int iVar5;
  uint *puVar6;
  int iVar7;
  DWORD DVar8;
  HWND pHVar9;
  uint *_Buf2;
  undefined *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  wchar_t *pwVar16;
  char local_1858 [4];
  int local_1854;
  uint local_1850;
  uint *local_184c;
  wchar_t *local_1848;
  HWND local_1844;
  SIZE_T local_1840;
  uint local_183c;
  HWND local_1838;
  uint local_1834 [3];
  undefined4 local_1828 [5];
  undefined4 local_1814;
  undefined4 local_17f8;
  uint local_17e8;
  uint local_17e4;
  uint local_17e0;
  uint local_17dc;
  uint local_17d8;
  uint local_17d4;
  uint local_17d0;
  uint local_17cc;
  undefined4 local_17c8;
  undefined *local_17c4;
  undefined4 local_17b4;
  int local_179c;
  int local_1798;
  undefined4 local_1790;
  WCHAR aWStack_440 [520];
  uint local_30;
  
  pHVar9 = DAT_402f7700;
  local_30 = DAT_402f65fc;
  local_1838 = DAT_402f7700;
  memset(&local_17d8,0,0x10);
  pHVar4 = GetDlgItem(pHVar9,0x7d5);
  local_1844 = pHVar4;
  SetWindowTextW(pHVar4,(LPCWSTR)&DAT_402f8124);
  hWnd = GetParent(pHVar9);
  SetWindowTextW(hWnd,(LPCWSTR)&DAT_402f8524);
  memset(local_1828,0,0x3c);
  local_1828[0] = 0x3c;
  local_1814 = 0x10;
  local_17f8 = 0;
  local_1854 = 0;
  iVar5 = (*DAT_402f7f18)(local_1828,2,&local_1854);
  DAT_402f6ee0 = local_1854;
  if (iVar5 == 0) {
    pwVar16 = L"%s (%04x%08x)";
    local_1848 = L"%s (%04x%08x)";
    uVar11 = local_17cc;
    while (pHVar9 = local_1838, pHVar4 = local_1844, DAT_402f6ee0 != 0) {
      local_1834[1] = 5000;
      memset(&local_17c8,0,0x3c);
      local_17c8 = 0x3c;
      local_17b4 = 0x10;
      local_1790 = 0;
      iVar5 = (*DAT_402f6834)(local_1854,0x110,local_1834 + 1,&local_17c8);
      pHVar9 = local_1838;
      pHVar4 = local_1844;
      if (iVar5 != 0) goto LAB_402da308;
      if (local_179c == 1) {
        uVar13 = *(uint *)(*(int *)(local_1798 + 8) + 8);
        puVar14 = *(uint **)(*(int *)(local_1798 + 8) + 0xc);
        _Buf2 = puVar14;
        local_1850 = uVar13;
        local_184c = puVar14;
        iVar5 = FUN_402d8438(uVar13,(int)puVar14);
        bVar1 = false;
        puVar15 = (uint *)0x0;
        do {
          if (DAT_402f6ee0 == 0) break;
          _Buf2 = puVar14;
          puVar6 = (uint *)FUN_402d8518(uVar13,(int)puVar14,(int)puVar15);
          if ((puVar6 == (uint *)0x0) || (*puVar6 == 0xffffffff)) {
            local_17e8 = local_17d8;
            local_17e4 = local_17d4;
            local_1834[0] = 0;
            local_183c = 0;
            local_1840 = 0;
            local_1858[0] = '\0';
            local_17e0 = local_17d0;
            _Buf2 = puVar15;
            local_17dc = uVar11;
            iVar7 = FUN_402d9970(&local_1850,(int)puVar15,local_1858,&local_183c,&local_1840,
                                 local_1834,&local_17e8);
            uVar3 = local_183c;
            cVar2 = local_1858[0];
            uVar13 = local_1850;
            puVar14 = local_184c;
            if (iVar7 != 0) break;
            if ((local_1858[0] == '\0') && (local_183c == 0)) {
              _Buf2 = &local_17d8;
              iVar7 = memcmp(&local_17e8,_Buf2,0x10);
              uVar13 = local_1850;
              puVar14 = local_184c;
              pwVar16 = local_1848;
              uVar11 = local_17cc;
              if (iVar7 == 0) goto LAB_402da074;
            }
            puVar14 = local_184c;
            uVar13 = local_1850;
            if ((puVar6 == (uint *)0x0) || (*puVar6 != 0xffffffff)) {
              puVar6 = operator_new(600);
              if (puVar6 == (uint *)0x0) {
                puVar6 = (uint *)0x0;
              }
              else {
                FUN_402d766c(puVar6,_Buf2,uVar13,(uint)puVar14,(uint)puVar15);
                puVar6[0x95] = 2;
                puVar6[0x94] = 2;
              }
            }
            else {
              _Buf2 = puVar6;
              FUN_402d8730(DAT_402f7f1c,(int)puVar6);
              FUN_402f218c((int *)puVar6);
              *puVar6 = (uint)puVar15;
            }
            pwVar16 = local_1848;
            uVar11 = local_17cc;
            if (puVar6 != (uint *)0x0) {
              *(char *)(puVar6 + 0x8b) = cVar2;
              puVar6[0x8d] = local_17e8;
              puVar6[0x8e] = local_17e4;
              puVar6[0x8f] = local_17e0;
              puVar6[0x90] = local_17dc;
              puVar10 = local_17c4;
              if (local_17c4 == (undefined *)0x0) {
                puVar10 = &DAT_402f74fc;
              }
              wsprintfW((LPWSTR)(puVar6 + 2),local_1848,puVar10,(uint)(ushort)puVar6[0x89],
                        puVar6[0x88]);
              uVar11 = puVar6[0x8a];
              uVar12 = (uint)(iVar5 != 0) << 1;
              puVar6[0x8a] = uVar12 | uVar11 & 0xfffffffc;
              puVar6[0x92] = uVar3;
              puVar6[0x93] = local_1840;
              puVar6[0x8c] = local_1834[0];
              if (local_1834[0] == 0x80) {
                puVar6[0x8a] = uVar12 | uVar11 & 0xfffffff0;
              }
              FUN_402d7e7c(puVar6);
              if ((puVar6[0x8a] & 2) != 0) {
                FUN_402f1d80((int *)puVar6);
              }
              DAT_402f892c = 1;
              bVar1 = true;
              DAT_402f683c = puVar6;
              PostMessageW(DAT_402f7700,0x401,0,0);
              _Buf2 = (uint *)0xffffffff;
              WaitForSingleObject(DAT_402f6ee8,0xffffffff);
              uVar11 = local_17cc;
            }
          }
LAB_402da074:
          puVar15 = (uint *)((int)puVar15 + 1);
        } while ((int)puVar15 < 10);
        if ((!bVar1) && ((iVar5 != 0) == 0)) {
          puVar15 = operator_new(600);
          if (puVar15 == (uint *)0x0) {
            puVar15 = (uint *)0x0;
          }
          else {
            FUN_402d766c(puVar15,_Buf2,uVar13,(uint)puVar14,0xffffffff);
            puVar15[0x95] = 2;
            puVar15[0x94] = 2;
          }
          if (puVar15 != (uint *)0x0) {
            puVar10 = local_17c4;
            if (local_17c4 == (undefined *)0x0) {
              puVar10 = &DAT_402f74fc;
            }
            wsprintfW((LPWSTR)(puVar15 + 2),pwVar16,puVar10,(uint)(ushort)puVar15[0x89],
                      puVar15[0x88]);
            DAT_402f892c = 1;
            DAT_402f683c = puVar15;
            PostMessageW(DAT_402f7700,0x401,0,0);
            WaitForSingleObject(DAT_402f6ee8,0xffffffff);
          }
        }
      }
    }
  }
  else {
LAB_402da308:
    if ((iVar5 == -1) && (DVar8 = GetLastError(), DVar8 != 0x277e)) {
      if (DAT_402f6ee0 != 0) {
        SetWindowTextW(pHVar4,(LPCWSTR)&DAT_402f7f24);
        pHVar4 = GetParent(pHVar9);
        SetWindowTextW(pHVar4,(LPCWSTR)&DAT_402f7904);
        puVar10 = &DAT_402d1054;
        if (DVar8 == 8) {
          puVar10 = &DAT_402f6cdc;
        }
        else if (DVar8 == 0x426) {
LAB_402da3cc:
          puVar10 = &DAT_402f6efc;
        }
        else if (DVar8 == 0x2726) {
          puVar10 = &DAT_402f8728;
        }
        else {
          if (DVar8 == 0x2742) goto LAB_402da3cc;
          if (DVar8 == 0x2749) {
            puVar10 = &DAT_402f7704;
          }
          else {
            if (DVar8 == 0x277c) goto LAB_402da3cc;
            if (DVar8 == 0x277f) {
              puVar10 = &DAT_402f6634;
            }
          }
        }
        wsprintfW(aWStack_440,L"%s %d %s\n",&DAT_402f6adc,DVar8 & 0xffff,puVar10);
        MessageBoxW(pHVar9,aWStack_440,(LPCWSTR)&DAT_402f7b0c,0x40000);
        goto LAB_402da458;
      }
    }
    else if (DAT_402f6ee0 != 0) {
      (*DAT_402f7f20)(local_1854);
      DAT_402f6ee0 = 0;
    }
  }
  SetWindowTextW(pHVar4,(LPCWSTR)&DAT_402f7f24);
  pHVar9 = GetParent(pHVar9);
  SetWindowTextW(pHVar9,(LPCWSTR)&DAT_402f7904);
LAB_402da458:
  FUN_402f41d8(local_30);
  return 0;
}



/* 402da494 FUN_402da494 */

/* Boundary evidence: original MIPS .pdata 402da494..402dad7b. Semantic name remains unreviewed. */

undefined4 FUN_402da494(HWND param_1,int param_2,ushort param_3,int param_4)

{
  HWND hWnd;
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  LRESULT LVar4;
  BOOL BVar5;
  HGDIOBJ pvVar6;
  LRESULT LVar7;
  LPCWSTR lpText;
  UINT UVar8;
  WPARAM wParam;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  undefined4 local_2b8;
  WPARAM local_2b4;
  undefined4 local_2ac;
  undefined4 local_2a8;
  int local_29c;
  int *local_298;
  _PROCESS_INFORMATION local_288;
  wchar_t awStack_278 [52];
  undefined1 auStack_210 [496];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  if (param_2 == 2) {
    ImageList_Destroy(DAT_402f8934);
    DAT_402f8934 = (HIMAGELIST)0x0;
    pvVar6 = (HGDIOBJ)SendMessageW(DAT_402f7f1c,0x1002,1,0);
    DeleteObject(pvVar6);
    pvVar6 = (HGDIOBJ)SendMessageW(DAT_402f7f0c,0x1002,1,0);
    DeleteObject(pvVar6);
    LVar4 = SendMessageW(DAT_402f7f1c,0x1004,0,0);
    if (0 < LVar4) {
      do {
        memset(&local_2b8,0,0x2c);
        local_2b8 = 4;
        local_2a8 = 0xffffffff;
        local_2b4 = 0;
        SendMessageW(DAT_402f7f1c,0x104b,0,(LPARAM)&local_2b8);
        LVar7 = SendMessageW(DAT_402f7f1c,0x1008,0,0);
        piVar1 = local_298;
        if ((LVar7 != 0) && (local_298 != (int *)0x0)) {
          if ((HLOCAL)local_298[0x92] != (HLOCAL)0x0) {
            LocalFree((HLOCAL)local_298[0x92]);
          }
          operator_delete(piVar1);
        }
        LVar4 = LVar4 + -1;
      } while (LVar4 != 0);
    }
    LVar4 = SendMessageW(DAT_402f7f0c,0x1004,0,0);
    if (0 < LVar4) {
      do {
        memset(&local_2b8,0,0x2c);
        local_2b8 = 4;
        local_2a8 = 0xffffffff;
        local_2b4 = 0;
        SendMessageW(DAT_402f7f0c,0x104b,0,(LPARAM)&local_2b8);
        LVar7 = SendMessageW(DAT_402f7f0c,0x1008,0,0);
        piVar1 = local_298;
        if ((LVar7 != 0) && (local_298 != (int *)0x0)) {
          if ((HLOCAL)local_298[0x92] != (HLOCAL)0x0) {
            LocalFree((HLOCAL)local_298[0x92]);
          }
          operator_delete(piVar1);
        }
        LVar4 = LVar4 + -1;
      } while (LVar4 != 0);
    }
    goto LAB_402dad50;
  }
  if (param_2 == 0x4e) {
    iVar3 = *(int *)(param_4 + 8);
    if (iVar3 == -0xcd) {
      local_288.hProcess = (HANDLE)0x0;
      local_288.hThread = (HANDLE)0x0;
      memset(&local_288.dwProcessId,0,8);
      wcscpy(awStack_278,L"file:ctpnl.htm#bluetooth");
      BVar5 = CreateProcessW(L"peghelp",awStack_278,(LPSECURITY_ATTRIBUTES)0x0,
                             (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                             (LPSTARTUPINFOW)0x0,&local_288);
      if (BVar5 != 0) {
        CloseHandle(local_288.hThread);
        CloseHandle(local_288.hProcess);
      }
      goto LAB_402dad50;
    }
    if (iVar3 != -7) {
      if (((iVar3 == -5) || (iVar3 == -3)) && (param_3 == 0x7d2)) {
        FUN_402d7c70(param_1,0);
      }
      goto LAB_402dad50;
    }
    if (param_3 == 0x7d1) {
      wParam = FUN_402d7608(DAT_402f7f1c,0xffffffff,2);
      if (wParam == 0xffffffff) goto LAB_402dad50;
      puVar9 = &local_2b8;
      local_2a8 = 2;
      UVar8 = 0x102b;
      local_2ac = 0;
      param_1 = DAT_402f7f1c;
    }
    else {
      if ((param_3 != 0x7d2) ||
         (wParam = FUN_402d7608(DAT_402f7f0c,0xffffffff,2), wParam == 0xffffffff))
      goto LAB_402dad50;
      puVar9 = &local_2b8;
      local_2a8 = 2;
      UVar8 = 0x102b;
      local_2ac = 0;
      param_1 = DAT_402f7f0c;
    }
  }
  else {
    if (param_2 != 0x100) {
      if (param_2 == 0x110) {
        DAT_402f7700 = param_1;
        SetForegroundWindow(param_1);
        DAT_402f7f0c = GetDlgItem(param_1,0x7d1);
        DAT_402f7f1c = GetDlgItem(param_1,0x7d2);
        FUN_402d7b80();
        SendMessageW(DAT_402f7f0c,0x1003,1,(LPARAM)DAT_402f8934);
        SendMessageW(DAT_402f7f1c,0x1003,1,(LPARAM)DAT_402f8934);
        FUN_402d88f4();
        goto LAB_402dad50;
      }
      if (param_2 != 0x111) {
        if (param_2 != 0x401) goto LAB_402dad50;
        FUN_402d7964();
        EventModify(DAT_402f6ee8,3);
      }
      if (param_3 < 0x849) {
        if (param_3 == 0x848) {
          iVar3 = FUN_402d789c(DAT_402f7f1c,&local_2b8,0,0);
          if (iVar3 != 0) goto LAB_402dad50;
          if ((local_298[0x8a] & 1U) == 0) {
            FUN_402d8850(local_298);
          }
          else {
            FUN_402f23e4(local_298);
          }
          if ((local_298[0x8a] & 1U) == 0) {
            local_29c = local_298[0x95];
          }
          else {
            local_29c = local_298[0x94];
          }
          puVar9 = &local_2b8;
          UVar8 = 0x104c;
        }
        else {
          if (param_3 == 2) {
            EndDialog(param_1,0);
            goto LAB_402dad50;
          }
          if (param_3 != 0x7d3) {
            if (param_3 == 0x7d4) {
              iVar3 = FUN_402d789c(DAT_402f7f1c,&local_2b8,auStack_210,0xf8);
              if (iVar3 == 0) {
                uVar10 = local_298[0x8a];
                local_298[0x8a] = uVar10 & 0xfffffffd;
                if ((uVar10 & 1) != 0) {
                  FUN_402f23e4(local_298);
                  if ((local_298[0x8a] & 1U) == 0) {
                    local_29c = local_298[0x95];
                  }
                  else {
                    local_29c = local_298[0x94];
                  }
                }
                FUN_402d8730(DAT_402f7f1c,(int)local_298);
                local_2b4 = 0;
                SendMessageW(DAT_402f7f0c,0x104d,0,(LPARAM)&local_2b8);
                SendMessageW(DAT_402f7f0c,0x101e,0,0xffff);
                SendMessageW(DAT_402f7f1c,0x101e,0,0xffff);
                FUN_402f218c(local_298);
                FUN_402d87f4((int)local_298);
              }
            }
            else if (param_3 == 0x7d5) {
              if (DAT_402f6ee0 != 0) {
                DAT_402f6ee0 = 0;
                (*DAT_402f7f20)();
              }
              if (DAT_402f8928 != (HANDLE)0x0) {
                DVar2 = WaitForSingleObject(DAT_402f8928,0);
                if (DVar2 != 0) goto LAB_402dad50;
                if (DAT_402f8928 != (HANDLE)0x0) {
                  CloseHandle(DAT_402f8928);
                }
              }
              FUN_402d9794();
              DAT_402f8928 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402d9e20,(LPVOID)0x0,0,
                                          (LPDWORD)0x0);
            }
            goto LAB_402dad50;
          }
          iVar3 = FUN_402d789c(DAT_402f7f0c,&local_2b8,auStack_210,0xf8);
          if (iVar3 != 0) goto LAB_402dad50;
          iVar3 = FUN_402d8d2c();
          if ((iVar3 != 1) && (iVar3 != 2)) {
            if (iVar3 == 4) {
              lpText = (LPCWSTR)&DAT_402f8324;
            }
            else if (iVar3 == 5) {
              lpText = (LPCWSTR)&DAT_402f70fc;
            }
            else {
              if (iVar3 != 6) goto LAB_402dad50;
              lpText = (LPCWSTR)&DAT_402f7d0c;
            }
            MessageBoxW(param_1,lpText,(LPCWSTR)&DAT_402f7b0c,0x40000);
            goto LAB_402dad50;
          }
          FUN_402d8730(DAT_402f7f0c,(int)local_298);
          hWnd = DAT_402f7f1c;
          local_298[0x8a] = local_298[0x8a] | 2;
          local_2b4 = 0;
          SendMessageW(hWnd,0x104d,0,(LPARAM)&local_2b8);
          SendMessageW(DAT_402f7f0c,0x101e,0,0xffff);
          puVar9 = (undefined4 *)0xffff;
          UVar8 = 0x101e;
        }
        SendMessageW(DAT_402f7f1c,UVar8,0,(LPARAM)puVar9);
      }
      else {
        if (param_3 == 0x84c) {
          iVar3 = FUN_402d789c(DAT_402f7f1c,&local_2b8,0,0);
          if (iVar3 == 0) {
            FUN_402f23e4(local_298);
            LVar4 = SendMessageW(DAT_402f7f1c,0x1008,local_2b4,0);
            if (LVar4 != 0) {
              FUN_402f218c(local_298);
              FUN_402d87f4((int)local_298);
              if (local_298 != (int *)0x0) {
                if ((HLOCAL)local_298[0x92] != (HLOCAL)0x0) {
                  LocalFree((HLOCAL)local_298[0x92]);
                }
                operator_delete(local_298);
              }
            }
          }
          goto LAB_402dad50;
        }
        if (param_3 == 0x84d) {
          iVar3 = FUN_402d789c(DAT_402f7f1c,&local_2b8,0,0);
          if (iVar3 != 0) goto LAB_402dad50;
          uVar11 = local_298[0x8a];
          uVar10 = ((uint)((uVar11 & 4) == 0) << 2 ^ uVar11) & 4;
        }
        else {
          if ((param_3 != 0x84e) || (iVar3 = FUN_402d789c(DAT_402f7f1c,&local_2b8,0,0), iVar3 != 0))
          goto LAB_402dad50;
          uVar11 = local_298[0x8a];
          uVar10 = ((uint)((uVar11 & 8) == 0) << 3 ^ uVar11) & 8;
        }
        local_298[0x8a] = uVar10 ^ uVar11;
      }
      FUN_402f1d80(local_298);
      goto LAB_402dad50;
    }
    if (*(short *)(param_4 + 0xc) != 0x2e) goto LAB_402dad50;
    puVar9 = (undefined4 *)0x0;
    wParam = 0x84c;
    UVar8 = 0x111;
  }
  SendMessageW(param_1,UVar8,wParam,(LPARAM)puVar9);
LAB_402dad50:
  FUN_402f41d8(local_20);
  return 0;
}



/* 402dad7c FUN_402dad7c */

/* Boundary evidence: original MIPS .pdata 402dad7c..402db4d3. Semantic name remains unreviewed. */

undefined4 FUN_402dad7c(HWND param_1,int param_2,short param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  DWORD DVar3;
  BOOL BVar4;
  HGDIOBJ ho;
  LRESULT LVar5;
  LRESULT LVar6;
  LPCWSTR lpText;
  uint uVar7;
  uint uVar8;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e0;
  undefined4 local_d4;
  int *local_d0;
  _PROCESS_INFORMATION local_c0;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  int local_94;
  wchar_t awStack_80 [50];
  uint local_1c;
  
  local_1c = DAT_402f65fc;
  if (param_2 == 2) {
    ImageList_Destroy(DAT_402f8934);
    DAT_402f8934 = (HIMAGELIST)0x0;
    ho = (HGDIOBJ)SendMessageW(DAT_402f7f1c,0x1002,1,0);
    DeleteObject(ho);
    LVar5 = SendMessageW(DAT_402f7f1c,0x1004,0,0);
    if (0 < LVar5) {
      do {
        memset(&local_f0,0,0x2c);
        local_f0 = 4;
        local_e0 = 0xffffffff;
        local_ec = 0;
        SendMessageW(DAT_402f7f1c,0x104b,0,(LPARAM)&local_f0);
        LVar6 = SendMessageW(DAT_402f7f1c,0x1008,0,0);
        piVar1 = local_d0;
        if ((LVar6 != 0) && (local_d0 != (int *)0x0)) {
          if ((HLOCAL)local_d0[0x92] != (HLOCAL)0x0) {
            LocalFree((HLOCAL)local_d0[0x92]);
          }
          operator_delete(piVar1);
        }
        LVar5 = LVar5 + -1;
      } while (LVar5 != 0);
    }
    goto LAB_402db4a8;
  }
  if (param_2 == 0x4e) {
    iVar2 = *(int *)(param_4 + 8);
    if (iVar2 == -0xcd) {
      local_c0.hProcess = (HANDLE)0x0;
      local_c0.hThread = (HANDLE)0x0;
      memset(&local_c0.dwProcessId,0,8);
      wcscpy(awStack_80,L"file:ctpnl.htm#bluetooth");
      BVar4 = CreateProcessW(L"peghelp",awStack_80,(LPSECURITY_ATTRIBUTES)0x0,
                             (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                             (LPSTARTUPINFOW)0x0,&local_c0);
      if (BVar4 != 0) {
        CloseHandle(local_c0.hThread);
        CloseHandle(local_c0.hProcess);
      }
    }
    else if (((iVar2 == -5) || (iVar2 == -3)) && (param_3 == 0x7d2)) {
      FUN_402d7c70(param_1,1);
    }
    goto LAB_402db4a8;
  }
  if (param_2 == 0x110) {
    DAT_402f7700 = param_1;
    SetForegroundWindow(param_1);
    DAT_402f7f1c = GetDlgItem(param_1,0x7d2);
    FUN_402d7b80();
    SendMessageW(DAT_402f7f1c,0x1003,1,(LPARAM)DAT_402f8934);
    SendMessageW(DAT_402f7f1c,0x1036,0,0x22);
    FUN_402d88f4();
    goto LAB_402db4a8;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x401) goto LAB_402db4a8;
    FUN_402d7964();
    EventModify(DAT_402f6ee8,3);
  }
  if (param_3 == 2) {
    EndDialog(param_1,0);
    goto LAB_402db4a8;
  }
  if (param_3 == 0x7d5) {
    if (DAT_402f6ee0 != 0) {
      DAT_402f6ee0 = 0;
      (*DAT_402f7f20)();
    }
    if (DAT_402f8928 != (HANDLE)0x0) {
      DVar3 = WaitForSingleObject(DAT_402f8928,0);
      if (DVar3 != 0) goto LAB_402db4a8;
      if (DAT_402f8928 != (HANDLE)0x0) {
        CloseHandle(DAT_402f8928);
      }
    }
    FUN_402d9794();
    DAT_402f8928 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402d9e20,(LPVOID)0x0,0,(LPDWORD)0x0
                               );
    goto LAB_402db4a8;
  }
  if (param_3 == 0x848) {
    iVar2 = FUN_402d789c(DAT_402f7f1c,&local_f0,0,0);
    if (iVar2 != 0) goto LAB_402db4a8;
    if ((local_d0[0x8a] & 1U) == 0) {
      FUN_402d8850(local_d0);
    }
    else {
      FUN_402f23e4(local_d0);
    }
    memset(&local_b0,0,0x2c);
    local_a8 = 1;
    local_b0 = 2;
    local_e0 = 0xffffffff;
    local_ac = local_ec;
    SendMessageW(DAT_402f7f1c,0x104b,0,(LPARAM)&local_b0);
    if ((local_d0[0x8a] & 1U) == 0) {
      local_94 = local_d0[0x95];
    }
    else {
      local_94 = local_d0[0x94];
    }
    SendMessageW(DAT_402f7f1c,0x104c,0,(LPARAM)&local_b0);
  }
  else {
    if (param_3 == 0x84b) {
      iVar2 = FUN_402d789c(DAT_402f7f1c,&local_f0,0,0);
      if (iVar2 != 0) goto LAB_402db4a8;
      uVar7 = local_d0[0x8a];
      if ((uVar7 & 2) == 0) {
        iVar2 = FUN_402d8d2c();
        if ((iVar2 == 1) || (iVar2 == 2)) {
          local_d0[0x8a] = local_d0[0x8a] | 2;
          local_d4 = 0;
          FUN_402f1d80(local_d0);
        }
        else {
          if (iVar2 == 4) {
            lpText = (LPCWSTR)&DAT_402f8324;
          }
          else if (iVar2 == 5) {
            lpText = (LPCWSTR)&DAT_402f70fc;
          }
          else {
            if (iVar2 != 6) goto LAB_402db0e8;
            lpText = (LPCWSTR)&DAT_402f7d0c;
          }
          MessageBoxW(param_1,lpText,(LPCWSTR)&DAT_402f7b0c,0x40000);
        }
      }
      else {
        local_d0[0x8a] = uVar7 & 0xfffffffd;
        if ((uVar7 & 1) != 0) {
          memset(&local_b0,0,0x2c);
          local_e0 = 0xffffffff;
          local_b0 = 2;
          local_a8 = 1;
          local_ac = local_ec;
          FUN_402f23e4(local_d0);
          SendMessageW(DAT_402f7f1c,0x104b,0,(LPARAM)&local_b0);
          if ((local_d0[0x8a] & 1U) == 0) {
            local_94 = local_d0[0x95];
          }
          else {
            local_94 = local_d0[0x94];
          }
          SendMessageW(DAT_402f7f1c,0x104c,0,(LPARAM)&local_b0);
        }
        local_d0[0x8a] = local_d0[0x8a] & 0xfffffffe;
        local_d4 = 1;
        FUN_402f218c(local_d0);
        FUN_402d87f4((int)local_d0);
      }
LAB_402db0e8:
      SendMessageW(DAT_402f7f1c,0x104c,0,(LPARAM)&local_f0);
      SendMessageW(DAT_402f7f1c,0x101e,1,0xffff);
      goto LAB_402db4a8;
    }
    if (param_3 == 0x84c) {
      iVar2 = FUN_402d789c(DAT_402f7f1c,&local_f0,0,0);
      if (iVar2 == 0) {
        FUN_402f23e4(local_d0);
        FUN_402d8730(DAT_402f7f1c,(int)local_d0);
        FUN_402f218c(local_d0);
        FUN_402d87f4((int)local_d0);
        if (local_d0 != (int *)0x0) {
          if ((HLOCAL)local_d0[0x92] != (HLOCAL)0x0) {
            LocalFree((HLOCAL)local_d0[0x92]);
          }
          operator_delete(local_d0);
        }
      }
      goto LAB_402db4a8;
    }
    if (param_3 == 0x84d) {
      iVar2 = FUN_402d789c(DAT_402f7f1c,&local_f0,0,0);
      if (iVar2 != 0) goto LAB_402db4a8;
      uVar8 = local_d0[0x8a];
      uVar7 = ((uint)((uVar8 & 4) == 0) << 2 ^ uVar8) & 4;
    }
    else {
      if ((param_3 != 0x84e) || (iVar2 = FUN_402d789c(DAT_402f7f1c,&local_f0,0,0), iVar2 != 0))
      goto LAB_402db4a8;
      uVar8 = local_d0[0x8a];
      uVar7 = ((uint)((uVar8 & 8) == 0) << 3 ^ uVar8) & 8;
    }
    local_d0[0x8a] = uVar7 ^ uVar8;
  }
  FUN_402f1d80(local_d0);
LAB_402db4a8:
  FUN_402f41d8(local_1c);
  return 0;
}



/* 402db4d4 CreateScanDevice */

/* Boundary evidence: original MIPS .pdata 402db4d4..402dbbe3. Semantic name remains unreviewed. */

undefined4 CreateScanDevice(HINSTANCE param_1,int param_2)

{
  HANDLE hSemaphore;
  DWORD DVar1;
  HWND pHVar2;
  HMODULE hLibModule;
  HMODULE hLibModule_00;
  int iVar3;
  int iVar4;
  HMODULE hLibModule_01;
  code *pcVar5;
  undefined4 local_210;
  undefined4 local_20c;
  int local_208;
  HINSTANCE local_204;
  undefined4 local_200;
  WCHAR *local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 *local_1f0;
  undefined1 *local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  HINSTANCE local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  WCHAR *local_1d4;
  code *local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  WCHAR aWStack_1c0 [100];
  WCHAR aWStack_f8 [100];
  uint local_30;
  
                    /* 0xb4d4  9  CreateScanDevice */
  local_30 = DAT_402f65fc;
  DAT_402f7700 = 0;
  hSemaphore = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,0,1,L"bthmgmtui");
  if (hSemaphore == (HANDLE)0x0) {
LAB_402db54c:
    FUN_402f41d8(local_30);
    return 0xffffffff;
  }
  DVar1 = GetLastError();
  if (DVar1 == 0xb7) {
    ReleaseSemaphore(hSemaphore,1,(LPLONG)0x0);
    CloseHandle(hSemaphore);
    LoadStringW(param_1,0x7ee,aWStack_1c0,100);
    pHVar2 = FindWindowW(L"Dialog",aWStack_1c0);
    if (pHVar2 != (HWND)0x0) {
      SetForegroundWindow((HWND)((uint)pHVar2 | 1));
    }
    goto LAB_402db54c;
  }
  DAT_402f6ee8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (DAT_402f6ee8 == (HANDLE)0x0) {
    ReleaseSemaphore(hSemaphore,1,(LPLONG)0x0);
    CloseHandle(hSemaphore);
  }
  hLibModule = LoadLibraryW(L"btdrt.dll");
  if (hLibModule == (HMODULE)0x0) goto LAB_402dbb7c;
  DAT_402f7f20 = (code *)GetProcAddressW(hLibModule,L"BthNsLookupServiceEnd");
  DAT_402f7b04 = GetProcAddressW(hLibModule,L"BthGetLinkKey");
  DAT_402f6834 = GetProcAddressW(hLibModule,L"BthNsLookupServiceNext");
  DAT_402f7f18 = GetProcAddressW(hLibModule,L"BthNsLookupServiceBegin");
  DAT_402f6ef8 = GetProcAddressW(hLibModule,L"BthAuthenticate");
  DAT_402f6edc = GetProcAddressW(hLibModule,L"BthSetPIN");
  DAT_402f6ef4 = GetProcAddressW(hLibModule,L"BthRevokeLinkKey");
  DAT_402f6838 = GetProcAddressW(hLibModule,L"BthRevokePIN");
  DAT_402f7b08 = GetProcAddressW(hLibModule,L"BthCreateACLConnection");
  DAT_402f8724 = GetProcAddressW(hLibModule,L"BthCloseConnection");
  if ((((DAT_402f6ef8 != 0) && (DAT_402f6edc != 0)) && (DAT_402f7f20 != (code *)0x0)) &&
     (((DAT_402f7b04 != 0 && (DAT_402f6834 != 0)) &&
      ((DAT_402f7f18 != 0 && ((DAT_402f6ef4 != 0 && (DAT_402f6838 != 0)))))))) {
    hLibModule_00 = LoadLibraryW(L"ole32.dll");
    if (hLibModule_00 == (HMODULE)0x0) {
      hLibModule_00 = (HMODULE)0x0;
    }
    else {
      DAT_402f6ef0 = GetProcAddressW(hLibModule_00,L"CoInitializeEx");
      DAT_402f76fc = GetProcAddressW(hLibModule_00,L"CoUninitialize");
      DAT_402f7f10 = GetProcAddressW(hLibModule_00,L"CoCreateInstance");
      DAT_402f7f14 = GetProcAddressW(hLibModule_00,L"CoTaskMemAlloc");
      DAT_402f6ee4 = GetProcAddressW(hLibModule_00,L"CoTaskMemFree");
      if ((((DAT_402f6ef0 != 0) && (DAT_402f76fc != 0)) && (DAT_402f7f10 != 0)) &&
         ((DAT_402f7f14 != 0 && (DAT_402f6ee4 != 0)))) {
        DAT_402f6eec = param_1;
        LoadStringW(param_1,0x7e8,(LPWSTR)&DAT_402f74fc,0x100);
        LoadStringW(DAT_402f6eec,0x7e9,(LPWSTR)&DAT_402f8124,0x100);
        LoadStringW(DAT_402f6eec,0x7ea,(LPWSTR)&DAT_402f7f24,0x100);
        LoadStringW(DAT_402f6eec,0x7eb,(LPWSTR)&DAT_402f8524,0x100);
        LoadStringW(DAT_402f6eec,0x7ee,(LPWSTR)&DAT_402f7904,0x100);
        LoadStringW(DAT_402f6eec,0x7f6,(LPWSTR)&DAT_402f72fc,0x100);
        LoadStringW(DAT_402f6eec,0x7e6,(LPWSTR)&DAT_402f7b0c,0x100);
        LoadStringW(DAT_402f6eec,0x7e7,(LPWSTR)&DAT_402f8324,0x100);
        LoadStringW(DAT_402f6eec,0x7ec,(LPWSTR)&DAT_402f6adc,0x100);
        LoadStringW(DAT_402f6eec,0x7ed,(LPWSTR)&DAT_402f68dc,0x100);
        LoadStringW(DAT_402f6eec,0x7ef,(LPWSTR)&DAT_402f6efc,0x100);
        LoadStringW(DAT_402f6eec,0x7f0,(LPWSTR)&DAT_402f6634,0x100);
        LoadStringW(DAT_402f6eec,0x7f1,(LPWSTR)&DAT_402f8728,0x100);
        LoadStringW(DAT_402f6eec,0x7f2,(LPWSTR)&DAT_402f6cdc,0x100);
        LoadStringW(DAT_402f6eec,0x7f3,(LPWSTR)&DAT_402f7704,0x100);
        LoadStringW(DAT_402f6eec,0x7f4,(LPWSTR)&DAT_402f7d0c,0x100);
        LoadStringW(DAT_402f6eec,0x7f5,(LPWSTR)&DAT_402f70fc,0x100);
        DAT_402f7f0c = 0;
        DAT_402f7f1c = 0;
        FUN_402d8a0c();
        iVar3 = GetSystemMetrics(1);
        iVar4 = GetSystemMetrics(0);
        if (iVar4 < iVar3) {
          DAT_402f8930 = 1;
        }
        if (DAT_402f8930 == 0) {
          local_1d0 = FUN_402da494;
          local_1dc = 0xa2a;
        }
        else {
          local_1d0 = FUN_402dad7c;
          local_1dc = 0x837;
        }
        local_1e8 = 0x28;
        local_1e4 = 0x28;
        local_1e0 = DAT_402f6eec;
        local_1d8 = 0;
        LoadStringW(DAT_402f6eec,0x7e3,aWStack_1c0,100);
        local_1d4 = aWStack_1c0;
        local_1c8 = 0;
        local_1cc = 0;
        local_210 = 0x28;
        if (param_2 == 0) {
          local_20c = 0x30c;
          local_1ec = &LAB_402d778c;
        }
        else {
          local_20c = 0x20c;
        }
        local_204 = DAT_402f6eec;
        local_200 = 0x84a;
        local_208 = param_2;
        LoadStringW(DAT_402f6eec,0x7e4,aWStack_f8,100);
        local_1fc = aWStack_f8;
        local_1f8 = 1;
        local_1f0 = &local_1e8;
        local_1f4 = 0;
        hLibModule_01 = LoadLibraryW(L"commctrl.dll");
        if (hLibModule_01 != (HMODULE)0x0) {
          pcVar5 = (code *)GetProcAddressW(hLibModule_01,L"PropertySheetW");
          if (pcVar5 != (code *)0x0) {
            (*pcVar5)(&local_210);
          }
          FreeLibrary(hLibModule_01);
        }
        if (DAT_402f6ee0 != 0) {
          (*DAT_402f7f20)();
          DAT_402f6ee0 = 0;
        }
        if (DAT_402f8928 != (HANDLE)0x0) {
          FUN_402d76d8(DAT_402f8928,0xffffffff);
          CloseHandle(DAT_402f8928);
        }
        FreeLibrary(hLibModule_00);
        goto LAB_402dbb74;
      }
    }
    FreeLibrary(hLibModule_00);
  }
LAB_402dbb74:
  FreeLibrary(hLibModule);
LAB_402dbb7c:
  CloseHandle(DAT_402f6ee8);
  ReleaseSemaphore(hSemaphore,1,(LPLONG)0x0);
  CloseHandle(hSemaphore);
  FUN_402f41d8(local_30);
  return 0;
}



/* 402dbbe4 MsgWaitForMultipleObjectsExt */

/* Boundary evidence: original MIPS .pdata 402dbbe4..402dbcef. Semantic name remains unreviewed. */

undefined4
MsgWaitForMultipleObjectsExt
          (int param_1,uint param_2,DWORD *param_3,undefined4 param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  HANDLE pvVar2;
  HANDLE *pHandles;
  DWORD nCount;
  HANDLE *ppvVar3;
  DWORD DVar4;
  
                    /* 0xbbe4  35  MsgWaitForMultipleObjectsExt */
  if (param_2 < 0x1c) {
    uVar1 = 0;
  }
  else {
    *param_5 = param_4;
    nCount = *(DWORD *)(param_1 + 8);
    pHandles = (HANDLE *)(param_3 + 6);
    if (nCount != 0) {
      ppvVar3 = pHandles;
      DVar4 = nCount;
      do {
        pvVar2 = (HANDLE)CeDriverDuplicateCallerHandle
                                   (*(undefined4 *)
                                     (((param_1 + 0x18) - (int)pHandles) + (int)ppvVar3),0,0,2);
        DVar4 = DVar4 - 1;
        *ppvVar3 = pvVar2;
        ppvVar3 = ppvVar3 + 1;
      } while (DVar4 != 0);
    }
    DVar4 = MsgWaitForMultipleObjectsEx
                      (nCount,pHandles,*(DWORD *)(param_1 + 0xc),*(DWORD *)(param_1 + 0x10),
                       *(DWORD *)(param_1 + 0x14));
    *param_3 = DVar4;
    DVar4 = GetLastError();
    param_3[1] = DVar4;
    for (; nCount != 0; nCount = nCount - 1) {
      CloseHandle(*pHandles);
      pHandles = pHandles + 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 402dbcf0 PeekMessageWExt */

/* Boundary evidence: original MIPS .pdata 402dbcf0..402dbd5b. Semantic name remains unreviewed. */

bool PeekMessageWExt(int param_1,uint param_2,BOOL *param_3,undefined4 param_4,undefined4 *param_5)

{
  BOOL BVar1;
  DWORD DVar2;
  
                    /* 0xbcf0  38  PeekMessageWExt */
  if (0x33 < param_2) {
    *param_5 = param_4;
    BVar1 = PeekMessageW((LPMSG)(param_3 + 6),*(HWND *)(param_1 + 8),*(UINT *)(param_1 + 0xc),
                         *(UINT *)(param_1 + 0x10),*(UINT *)(param_1 + 0x14));
    *param_3 = BVar1;
    DVar2 = GetLastError();
    param_3[1] = DVar2;
  }
  return 0x33 < param_2;
}



/* 402dbd5c TranslateMessageExt */

/* Boundary evidence: original MIPS .pdata 402dbd5c..402dbdb3. Semantic name remains unreviewed. */

bool TranslateMessageExt(int param_1,uint param_2,BOOL *param_3,undefined4 param_4,
                        undefined4 *param_5)

{
  BOOL BVar1;
  DWORD DVar2;
  
                    /* 0xbd5c  47  TranslateMessageExt */
  if (0x23 < param_2) {
    *param_5 = param_4;
    BVar1 = TranslateMessage((MSG *)(param_1 + 8));
    *param_3 = BVar1;
    DVar2 = GetLastError();
    param_3[1] = DVar2;
  }
  return 0x23 < param_2;
}



/* 402dbdb4 DispatchMessageExt */

/* Boundary evidence: original MIPS .pdata 402dbdb4..402dbe0b. Semantic name remains unreviewed. */

bool DispatchMessageExt(int param_1,uint param_2,LRESULT *param_3,undefined4 param_4,
                       undefined4 *param_5)

{
  LRESULT LVar1;
  DWORD DVar2;
  
                    /* 0xbdb4  12  DispatchMessageExt */
  if (0x23 < param_2) {
    *param_5 = param_4;
    LVar1 = DispatchMessageW((MSG *)(param_1 + 8));
    *param_3 = LVar1;
    DVar2 = GetLastError();
    param_3[1] = DVar2;
  }
  return 0x23 < param_2;
}



/* 402dbe0c LoadLibraryExt */

/* Boundary evidence: original MIPS .pdata 402dbe0c..402dbe9f. Semantic name remains unreviewed. */

undefined4
LoadLibraryExt(int param_1,uint param_2,undefined4 *param_3,undefined4 param_4,undefined4 *param_5)

{
  HMODULE pHVar1;
  DWORD DVar2;
  
                    /* 0xbe0c  34  LoadLibraryExt */
  if (param_2 < 0xc) {
    SetLastError(0x57);
  }
  else {
    *param_5 = param_4;
    param_3[1] = 0;
    SetLastError(0);
    pHVar1 = LoadLibraryW((LPCWSTR)(param_1 + 8));
    *param_3 = pHVar1;
    if (pHVar1 != (HMODULE)0x0) {
      return 1;
    }
    DVar2 = GetLastError();
    param_3[1] = DVar2;
  }
  return 0;
}



/* 402dbea0 FreeLibraryExt */

/* Boundary evidence: original MIPS .pdata 402dbea0..402dbf3b. Semantic name remains unreviewed. */

undefined4
FreeLibraryExt(int param_1,uint param_2,BOOL *param_3,undefined4 param_4,undefined4 *param_5)

{
  BOOL BVar1;
  DWORD DVar2;
  HMODULE hLibModule;
  
                    /* 0xbea0  13  FreeLibraryExt */
  if (param_2 < 0xc) {
    SetLastError(0x57);
  }
  else {
    *param_5 = param_4;
    hLibModule = *(HMODULE *)(param_1 + 8);
    param_3[1] = 0;
    SetLastError(0);
    BVar1 = FreeLibrary(hLibModule);
    *param_3 = BVar1;
    if (BVar1 != 0) {
      return 1;
    }
    DVar2 = GetLastError();
    param_3[1] = DVar2;
  }
  return 0;
}



/* 402dbf3c FUN_402dbf3c */

/* Boundary evidence: original MIPS .pdata 402dbf3c..402dc1a3. Semantic name remains unreviewed. */

undefined4 FUN_402dbf3c(HWND param_1,int param_2,short param_3,LPCWSTR param_4)

{
  LPWSTR lpString;
  int iVar1;
  HWND pHVar2;
  INT_PTR nResult;
  UINT uID;
  uint uVar3;
  WCHAR *local_228;
  int local_224;
  WCHAR aWStack_220 [128];
  WCHAR aWStack_120 [128];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  if (param_2 != 2) {
    if (param_2 == 0x110) {
      uVar3 = *(uint *)(param_4 + 0x82);
      if ((uVar3 & 0x80000000) == 0) {
        uID = uVar3 + 0x16;
        if (8 < uVar3) {
          uID = 0x1f;
        }
        *param_4 = L'\0';
        iVar1 = LoadStringW(DAT_402fc3c4,uID,aWStack_120,0x80);
        if ((iVar1 != 0) && (iVar1 = LoadStringW(DAT_402fc3c4,0x20,aWStack_220,0x80), iVar1 != 0)) {
          local_228 = aWStack_120;
          local_224 = *(int *)(param_4 + 0x80) + 1;
          FormatMessageW(0x2400,aWStack_220,0x20,0,param_4,0x100,(va_list *)&local_228);
        }
      }
      else {
        iVar1 = LoadStringW(DAT_402fc3c4,0x46,aWStack_220,0x80);
        if (iVar1 != 0) {
          SetWindowTextW(param_1,aWStack_220);
        }
        iVar1 = LoadStringW(DAT_402fc3c4,0x47,aWStack_220,0x80);
        if (iVar1 != 0) {
          SetDlgItemTextW(param_1,0x3ee,aWStack_220);
        }
      }
      SetWindowLongW(param_1,8,(LONG)param_4);
      uVar3 = GetWindowLongW(param_1,-0x14);
      SetWindowLongW(param_1,-0x14,uVar3 | 0x80000008);
      SetDlgItemTextW(param_1,0x3ef,param_4);
      pHVar2 = GetDlgItem(param_1,0x3ef);
      SetFocus(pHVar2);
      SendDlgItemMessageW(param_1,0x3ef,0xc5,0x80,0);
      pHVar2 = GetDlgItem(param_1,0x3ef);
      SendMessageW(pHVar2,0xb1,0,-1);
    }
    else if (param_2 == 0x111) {
      lpString = (LPWSTR)GetWindowLongW(param_1,8);
      if (param_3 == 1) {
        GetDlgItemTextW(param_1,0x3ef,lpString,0x80);
        nResult = 1;
      }
      else {
        if (param_3 != 2) goto LAB_402dc17c;
        nResult = 0;
      }
      EndDialog(param_1,nResult);
    }
  }
LAB_402dc17c:
  FUN_402f41d8(local_20);
  return 0;
}



/* 402dc1a4 GetDriverName */

/* Boundary evidence: original MIPS .pdata 402dc1a4..402dc277. Semantic name remains unreviewed. */

INT_PTR GetDriverName(HWND param_1,LPARAM param_2)

{
  HRSRC pHVar1;
  HGLOBAL pvVar2;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar3;
  
                    /* 0xc1a4  14  GetDriverName */
  pHVar1 = FindResourceW(DAT_402fc3c4,(LPCWSTR)0x72,(LPCWSTR)0x5);
  if ((pHVar1 != (HRSRC)0x0) && (pvVar2 = LoadResource(DAT_402fc3c4,pHVar1), pvVar2 != (HGLOBAL)0x0)
     ) {
    pHVar1 = FindResourceW(DAT_402fc3c4,(LPCWSTR)0x72,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_402fc3c4,pHVar1);
    IVar3 = DialogBoxIndirectParamW(DAT_402fc3c4,hDialogTemplate,param_1,FUN_402dbf3c,param_2);
    if (IVar3 != -1) {
      return IVar3;
    }
  }
  return 0;
}



/* 402dc278 GetDriverNameExt */

/* Boundary evidence: original MIPS .pdata 402dc278..402dc30f. Semantic name remains unreviewed. */

undefined4
GetDriverNameExt(int param_1,uint param_2,INT_PTR *param_3,undefined4 param_4,undefined4 *param_5)

{
  INT_PTR IVar1;
  DWORD DVar2;
  HWND pHVar3;
  
                    /* 0xc278  15  GetDriverNameExt */
  if (param_2 < 0x114) {
    SetLastError(0x57);
  }
  else {
    *param_5 = param_4;
    pHVar3 = *(HWND *)(param_1 + 4);
    param_3[2] = 0;
    SetLastError(0);
    IVar1 = GetDriverName(pHVar3,(LPARAM)(param_3 + 3));
    *param_3 = IVar1;
    if (IVar1 != 0) {
      return 1;
    }
    DVar2 = GetLastError();
    param_3[2] = DVar2;
  }
  return 0;
}



/* 402dc310 FUN_402dc310 */

/* Boundary evidence: original MIPS .pdata 402dc310..402dc40f. Semantic name remains unreviewed. */

undefined4 FUN_402dc310(HWND param_1,int param_2,short param_3)

{
  HWND pHVar1;
  uint uVar2;
  INT_PTR local_10 [2];
  
  if (param_2 == 0x110) {
    uVar2 = GetWindowLongW(param_1,-0x14);
    SetWindowLongW(param_1,-0x14,uVar2 | 8);
    local_10[0] = 0;
    pHVar1 = GetDlgItem(param_1,0x3e9);
    SendMessageW(pHVar1,0x465,0,0);
    pHVar1 = GetDlgItem(param_1,0x3e9);
    EnableWindow(pHVar1,1);
    pHVar1 = GetDlgItem(param_1,0x3e9);
    SetFocus(pHVar1);
  }
  else if (param_2 == 0x111) {
    if (param_3 == 1) {
      pHVar1 = GetDlgItem(param_1,0x3e9);
      SendMessageW(pHVar1,0x466,0,(LPARAM)local_10);
    }
    else {
      if (param_3 != 2) {
        return 0;
      }
      local_10[0] = 0;
    }
    EndDialog(param_1,local_10[0]);
  }
  return 0;
}



/* 402dc410 GetIPAddress */

/* Boundary evidence: original MIPS .pdata 402dc410..402dc48b. Semantic name remains unreviewed. */

void GetIPAddress(HWND param_1)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  
                    /* 0xc410  16  GetIPAddress */
  RegisterIPClass(DAT_402fc3c4);
  hResInfo = FindResourceW(DAT_402fc3c4,(LPCWSTR)0x64,(LPCWSTR)0x5);
  hDialogTemplate = LoadResource(DAT_402fc3c4,hResInfo);
  DialogBoxIndirectParamW(DAT_402fc3c4,hDialogTemplate,param_1,FUN_402dc310,0);
  return;
}



/* 402dc48c GetIPAddressExt */

/* Boundary evidence: original MIPS .pdata 402dc48c..402dc51f. Semantic name remains unreviewed. */

undefined4
GetIPAddressExt(int param_1,uint param_2,DWORD *param_3,undefined4 param_4,undefined4 *param_5)

{
  DWORD DVar1;
  HWND pHVar2;
  
                    /* 0xc48c  17  GetIPAddressExt */
  if (param_2 < 0xc) {
    SetLastError(0x57);
  }
  else {
    *param_5 = param_4;
    pHVar2 = *(HWND *)(param_1 + 4);
    *param_3 = 0;
    SetLastError(0);
    DVar1 = GetIPAddress(pHVar2);
    param_3[2] = DVar1;
    if (DVar1 != 0) {
      return 1;
    }
    DVar1 = GetLastError();
    *param_3 = DVar1;
  }
  return 0;
}



/* 402dc520 FUN_402dc520 */

/* Boundary evidence: original MIPS .pdata 402dc520..402dc737. Semantic name remains unreviewed. */

undefined4 FUN_402dc520(void)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  int *piVar3;
  
  pHVar1 = LoadLibraryW(L"commctrl.dll");
  if (pHVar1 == (HMODULE)0x0) {
LAB_402dc71c:
    uVar2 = 0;
  }
  else {
    DAT_402fc380 = GetProcAddressW(pHVar1,L"InitCommonControls");
    piVar3 = &DAT_402fc380;
    DAT_402fc384 = GetProcAddressW(pHVar1,L"InitCommonControlsEx");
    DAT_402fc388 = GetProcAddressW(pHVar1,L"CreateStatusWindowW");
    DAT_402fc38c = GetProcAddressW(pHVar1,L"DrawStatusTextW");
    DAT_402fc390 = GetProcAddressW(pHVar1,L"CommandBar_Create");
    DAT_402fc394 = GetProcAddressW(pHVar1,L"CommandBar_Show");
    DAT_402fc398 = GetProcAddressW(pHVar1,L"CommandBar_AddBitmap");
    DAT_402fc39c = GetProcAddressW(pHVar1,L"CommandBar_InsertComboBox");
    DAT_402fc3a0 = GetProcAddressW(pHVar1,L"CommandBar_InsertMenubar");
    DAT_402fc3a4 = GetProcAddressW(pHVar1,L"CommandBar_GetMenu");
    DAT_402fc3a8 = GetProcAddressW(pHVar1,L"CommandBar_AddAdornments");
    DAT_402fc3ac = GetProcAddressW(pHVar1,L"CommandBar_Height");
    DAT_402fc3b0 = GetProcAddressW(pHVar1,L"IsCommandBarMessage");
    DAT_402fc3b4 = GetProcAddressW(pHVar1,L"PropertySheetW");
    DAT_402fc3b8 = GetProcAddressW(pHVar1,L"CreatePropertySheetPageW");
    DAT_402fc3bc = GetProcAddressW(pHVar1,L"DestroyPropertySheetPage");
    DAT_402fc3c0 = GetProcAddressW(pHVar1,L"CreateUpDownControl");
    do {
      if (*piVar3 == 0) goto LAB_402dc71c;
      piVar3 = piVar3 + 1;
    } while ((int)piVar3 < 0x402fc3c4);
    uVar2 = 1;
  }
  return uVar2;
}



/* 402dc738 FUN_402dc738 */

/* Boundary evidence: original MIPS .pdata 402dc738..402dc7bb. Semantic name remains unreviewed. */

undefined4 FUN_402dc738(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_402d459c();
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_402fc360);
  }
  else if (param_2 == 1) {
    DAT_402fc3c4 = param_1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_402fc360);
    FUN_402dc520();
    FUN_402d451c();
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 402dc7bc FUN_402dc7bc */

/* Boundary evidence: original MIPS .pdata 402dc7bc..402dc7ef. Semantic name remains unreviewed. */

undefined2 FUN_402dc7bc(int param_1)

{
  int iVar1;
  
  iVar1 = LoadStringW(DAT_402fc3c4,param_1 + 0x28,(LPWSTR)0x0,1);
  return *(undefined2 *)(iVar1 + -2);
}



/* 402dc7f0 GetNetString */

/* Boundary evidence: original MIPS .pdata 402dc7f0..402dc81f. Semantic name remains unreviewed. */

void GetNetString(int param_1,LPWSTR param_2,int param_3)

{
                    /* 0xc7f0  18  GetNetString */
  LoadStringW(DAT_402fc3c4,param_1 + 0x28,param_2,param_3);
  return;
}



/* 402dc820 NetMsgBox */

/* Boundary evidence: original MIPS .pdata 402dc820..402dc98f. Semantic name remains unreviewed. */

undefined4 NetMsgBox(HWND param_1,uint param_2,LPCWSTR param_3)

{
  BOOL BVar1;
  int iVar2;
  HCURSOR hCursor;
  UINT UVar3;
  undefined4 uVar4;
  WCHAR aWStack_1b0 [200];
  uint local_20;
  
                    /* 0xc820  36  NetMsgBox */
  local_20 = DAT_402f65fc;
  if ((param_1 != (HWND)0x0) && (BVar1 = IsWindow(param_1), BVar1 == 0)) {
    SetLastError(0x578);
LAB_402dc87c:
    FUN_402f41d8(local_20);
    return 0;
  }
  UVar3 = 0x46;
  if ((param_2 & 0x1000) == 0) {
    UVar3 = 0x11;
  }
  iVar2 = LoadStringW(DAT_402fc3c4,UVar3,aWStack_1b0,200);
  if (iVar2 == 0) goto LAB_402dc87c;
  UVar3 = 0x10000;
  if ((param_2 & 2) != 0) {
    UVar3 = 0x10030;
  }
  if ((param_2 & 0x20) != 0) {
    UVar3 = UVar3 | 0x40;
  }
  if ((param_2 & 4) != 0) {
    UVar3 = UVar3 | 4;
  }
  if ((param_2 & 8) != 0) {
    UVar3 = UVar3 | 0x40000;
  }
  if ((param_2 & 0x10) != 0) {
    UVar3 = UVar3 | 0x100;
  }
  hCursor = SetCursor((HCURSOR)0x0);
  iVar2 = MessageBoxW(param_1,param_3,aWStack_1b0,UVar3);
  SetCursor(hCursor);
  uVar4 = 1;
  if ((param_2 & 4) == 0) {
    if (iVar2 != 0) goto LAB_402dc964;
  }
  else if (iVar2 == 6) goto LAB_402dc964;
  uVar4 = 0;
LAB_402dc964:
  FUN_402f41d8(local_20);
  return uVar4;
}



/* 402dc990 GetNetStringSizeExt */

/* Boundary evidence: original MIPS .pdata 402dc990..402dc9d7. Semantic name remains unreviewed. */

bool GetNetStringSizeExt(int param_1,uint param_2,undefined4 *param_3,undefined4 param_4,
                        undefined4 *param_5)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  
                    /* 0xc990  20  GetNetStringSizeExt */
  if (7 < param_2) {
    *param_5 = param_4;
    uVar1 = FUN_402dc7bc(*(int *)(param_1 + 4));
    *param_3 = CONCAT22(extraout_var,uVar1);
  }
  return 7 < param_2;
}



/* 402dc9d8 GetNetStringExt */

/* Boundary evidence: original MIPS .pdata 402dc9d8..402dca2b. Semantic name remains unreviewed. */

bool GetNetStringExt(int param_1,uint param_2,undefined4 *param_3,undefined4 param_4,
                    undefined4 *param_5)

{
  undefined4 uVar1;
  
                    /* 0xc9d8  19  GetNetStringExt */
  if (0xf < param_2) {
    *param_5 = param_4;
    uVar1 = GetNetString(*(int *)(param_1 + 4),(LPWSTR)(param_3 + 3),*(int *)(param_1 + 8));
    *param_3 = uVar1;
  }
  return 0xf < param_2;
}



/* 402dca2c NetMsgBoxExt */

/* Boundary evidence: original MIPS .pdata 402dca2c..402dca7f. Semantic name remains unreviewed. */

bool NetMsgBoxExt(int param_1,uint param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  undefined4 uVar1;
  
                    /* 0xca2c  37  NetMsgBoxExt */
  if (0xf < param_2) {
    *param_5 = param_4;
    uVar1 = NetMsgBox(*(HWND *)(param_1 + 4),*(uint *)(param_1 + 8),(LPCWSTR)(param_1 + 0xc));
    *param_3 = uVar1;
  }
  return 0xf < param_2;
}



/* 402dca80 FUN_402dca80 */

/* Boundary evidence: original MIPS .pdata 402dca80..402dd6a3. Semantic name remains unreviewed. */

undefined4 FUN_402dca80(HWND param_1,int param_2,undefined4 param_3,int param_4)

{
  HWND pHVar1;
  uint uVar2;
  int iVar3;
  LRESULT LVar4;
  undefined4 uVar5;
  int *piVar6;
  WCHAR aWStack_270 [4];
  wchar_t awStack_268 [4];
  WCHAR aWStack_260 [32];
  wchar_t awStack_220 [256];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  if (param_2 != 0x4e) {
    if (param_2 != 0x110) goto LAB_402dd318;
    pHVar1 = GetParent(param_1);
    uVar2 = GetWindowLongW(pHVar1,-0x14);
    pHVar1 = GetParent(param_1);
    SetWindowLongW(pHVar1,-0x14,uVar2 | 0x40000000);
    piVar6 = *(int **)(param_4 + 0x1c);
    SetWindowLongW(param_1,-0x15,(LONG)piVar6);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c94);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c8c);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c84);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c78);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c6c);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c60);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c54);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c48);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c3c);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c30);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c24);
    SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x402d1c14);
    uVar2 = *(uint *)(*piVar6 + 4);
    if (uVar2 < 0x2581) {
      if (uVar2 == 0x2580) {
        SendDlgItemMessageW(param_1,0x3f1,0x14e,6,0);
      }
      else if (uVar2 == 0x6e) {
        SendDlgItemMessageW(param_1,0x3f1,0x14e,0,0);
      }
      else if (uVar2 == 300) {
        SendDlgItemMessageW(param_1,0x3f1,0x14e,1,0);
      }
      else if (uVar2 == 600) {
        SendDlgItemMessageW(param_1,0x3f1,0x14e,2,0);
      }
      else if (uVar2 == 0x4b0) {
        SendDlgItemMessageW(param_1,0x3f1,0x14e,3,0);
      }
      else if (uVar2 == 0x960) {
        SendDlgItemMessageW(param_1,0x3f1,0x14e,4,0);
      }
      else {
        if (uVar2 != 0x12c0) goto LAB_402dce18;
        SendDlgItemMessageW(param_1,0x3f1,0x14e,5,0);
      }
    }
    else if (uVar2 == 0x3840) {
      SendDlgItemMessageW(param_1,0x3f1,0x14e,7,0);
    }
    else if (uVar2 == 0x4b00) {
      SendDlgItemMessageW(param_1,0x3f1,0x14e,8,0);
    }
    else if (uVar2 == 0x9600) {
      SendDlgItemMessageW(param_1,0x3f1,0x14e,9,0);
    }
    else if (uVar2 == 0xe100) {
      SendDlgItemMessageW(param_1,0x3f1,0x14e,10,0);
    }
    else if (uVar2 == 0x1c200) {
      SendDlgItemMessageW(param_1,0x3f1,0x14e,0xb,0);
    }
    else {
LAB_402dce18:
      SendDlgItemMessageW(param_1,0x3f1,0x14e,6,0);
    }
    LoadStringW(DAT_402fc3c4,7,aWStack_260,0x20);
    SendDlgItemMessageW(param_1,0x3f3,0x143,0,(LPARAM)aWStack_260);
    LoadStringW(DAT_402fc3c4,8,aWStack_260,0x20);
    SendDlgItemMessageW(param_1,0x3f3,0x143,0,(LPARAM)aWStack_260);
    LoadStringW(DAT_402fc3c4,9,aWStack_260,0x20);
    SendDlgItemMessageW(param_1,0x3f3,0x143,0,(LPARAM)aWStack_260);
    LoadStringW(DAT_402fc3c4,10,aWStack_260,0x20);
    SendDlgItemMessageW(param_1,0x3f3,0x143,0,(LPARAM)aWStack_260);
    LoadStringW(DAT_402fc3c4,0xb,aWStack_260,0x20);
    SendDlgItemMessageW(param_1,0x3f3,0x143,0,(LPARAM)aWStack_260);
    SendDlgItemMessageW(param_1,0x3f3,0x14e,(uint)*(byte *)(*piVar6 + 0xd),0);
    LoadStringW(DAT_402fc3c4,0xc,aWStack_260,0x20);
    SendDlgItemMessageW(param_1,0x3f5,0x143,0,(LPARAM)aWStack_260);
    LoadStringW(DAT_402fc3c4,0xd,aWStack_260,0x20);
    SendDlgItemMessageW(param_1,0x3f5,0x143,0,(LPARAM)aWStack_260);
    LoadStringW(DAT_402fc3c4,7,aWStack_260,0x20);
    SendDlgItemMessageW(param_1,0x3f5,0x143,0,(LPARAM)aWStack_260);
    if ((*(uint *)(*piVar6 + 0x18) & 1) == 0) {
      if ((*(uint *)(*piVar6 + 0x18) & 2) == 0) {
        SendDlgItemMessageW(param_1,0x3f5,0x14e,2,0);
      }
      else {
        SendDlgItemMessageW(param_1,0x3f5,0x14e,1,0);
      }
    }
    else {
      SendDlgItemMessageW(param_1,0x3f5,0x14e,0,0);
    }
    SendDlgItemMessageW(param_1,0x3f2,0x143,0,0x402d1c10);
    SendDlgItemMessageW(param_1,0x3f2,0x143,0,0x402d1c0c);
    SendDlgItemMessageW(param_1,0x3f2,0x143,0,0x402d1c08);
    SendDlgItemMessageW(param_1,0x3f2,0x143,0,0x402d1c04);
    SendDlgItemMessageW(param_1,0x3f2,0x143,0,0x402d1c00);
    SendDlgItemMessageW(param_1,0x3f2,0x14e,*(byte *)(*piVar6 + 0xc) - 4,0);
    iVar3 = GetLocaleInfoW(0x400,0xe,aWStack_270,2);
    if (iVar3 == 0) {
      wcscpy(aWStack_270,L".");
    }
    wcscpy(awStack_268,L"1");
    wcscat(awStack_268,aWStack_270);
    wcscat(awStack_268,L"5");
    SendDlgItemMessageW(param_1,0x3f4,0x143,0,0x402d1bf8);
    SendDlgItemMessageW(param_1,0x3f4,0x143,0,(LPARAM)awStack_268);
    SendDlgItemMessageW(param_1,0x3f4,0x143,0,0x402d1bf4);
    SendDlgItemMessageW(param_1,0x3f4,0x14e,(uint)*(byte *)(*piVar6 + 0xe),0);
    if ((*(uint *)(*piVar6 + 0x1c) & 1) == 0) {
      SendDlgItemMessageW(param_1,0x3ee,0xf1,0,0);
    }
    else {
      SendDlgItemMessageW(param_1,0x3ee,0xf1,1,0);
    }
    if ((*(uint *)(*piVar6 + 0x1c) & 2) == 0) {
      SendDlgItemMessageW(param_1,0x3ef,0xf1,0,0);
    }
    else {
      SendDlgItemMessageW(param_1,0x3ef,0xf1,1,0);
    }
    if ((*(uint *)(*piVar6 + 0x1c) & 4) == 0) {
      SendDlgItemMessageW(param_1,0x3f0,0xf1,0,0);
    }
    else {
      SendDlgItemMessageW(param_1,0x3f0,0xf1,1,0);
    }
LAB_402dd318:
    FUN_402f41d8(local_20);
    return 0;
  }
  if (param_4 == 0) goto LAB_402dd67c;
  if (*(int *)(param_4 + 8) == -0xcd) {
    wcscpy(awStack_220,L"file:rnetw.htm#Main_Contents");
    CreateProcessW(L"peghelp",awStack_220,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,
                   (LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
    goto LAB_402dd67c;
  }
  if (*(int *)(param_4 + 8) != -0xca) goto LAB_402dd67c;
  piVar6 = (int *)GetWindowLongW(param_1,-0x15);
  piVar6[5] = 1;
  LVar4 = SendDlgItemMessageW(param_1,0x3f1,0x147,0,0);
  if (LVar4 < 7) {
    if (LVar4 == 6) {
      uVar5 = 0x2580;
LAB_402dd3fc:
      *(undefined4 *)(*piVar6 + 4) = uVar5;
    }
    else if (LVar4 == 0) {
      uVar5 = 0x6e;
LAB_402dd40c:
      *(undefined4 *)(*piVar6 + 4) = uVar5;
    }
    else {
      if (LVar4 == 1) {
        uVar5 = 300;
        goto LAB_402dd3fc;
      }
      if (LVar4 == 2) {
        uVar5 = 600;
        goto LAB_402dd40c;
      }
      if (LVar4 == 3) {
        uVar5 = 0x4b0;
        goto LAB_402dd3fc;
      }
      if (LVar4 == 4) {
        uVar5 = 0x960;
        goto LAB_402dd40c;
      }
      if (LVar4 != 5) goto LAB_402dd45c;
      *(undefined4 *)(*piVar6 + 4) = 0x12c0;
    }
  }
  else if (LVar4 == 7) {
    uVar5 = 0x3840;
LAB_402dd494:
    *(undefined4 *)(*piVar6 + 4) = uVar5;
  }
  else {
    if (LVar4 == 8) {
      uVar5 = 0x4b00;
    }
    else {
      if (LVar4 == 9) {
        uVar5 = 0x9600;
        goto LAB_402dd494;
      }
      if (LVar4 == 10) {
        uVar5 = 0xe100;
      }
      else {
        if (LVar4 == 0xb) {
          uVar5 = 0x1c200;
          goto LAB_402dd494;
        }
LAB_402dd45c:
        uVar5 = 0x2580;
      }
    }
    *(undefined4 *)(*piVar6 + 4) = uVar5;
  }
  LVar4 = SendDlgItemMessageW(param_1,0x3f3,0x147,0,0);
  *(char *)(*piVar6 + 0xd) = (char)LVar4;
  LVar4 = SendDlgItemMessageW(param_1,0x3f2,0x147,0,0);
  *(char *)(*piVar6 + 0xc) = (char)LVar4 + '\x04';
  LVar4 = SendDlgItemMessageW(param_1,0x3f4,0x147,0,0);
  *(char *)(*piVar6 + 0xe) = (char)LVar4;
  *(undefined4 *)(*piVar6 + 0x18) = 0;
  LVar4 = SendDlgItemMessageW(param_1,0x3f5,0x147,0,0);
  if (LVar4 == 0) {
    *(uint *)(*piVar6 + 0x18) = *(uint *)(*piVar6 + 0x18) | 1;
  }
  else if (LVar4 == 1) {
    *(uint *)(*piVar6 + 0x18) = *(uint *)(*piVar6 + 0x18) | 2;
  }
  LVar4 = SendDlgItemMessageW(param_1,0x3ee,0xf0,0,0);
  if (LVar4 == 1) {
    *(uint *)(*piVar6 + 0x1c) = *(uint *)(*piVar6 + 0x1c) | 1;
  }
  else {
    *(uint *)(*piVar6 + 0x1c) = *(uint *)(*piVar6 + 0x1c) & 0xfffffffe;
  }
  LVar4 = SendDlgItemMessageW(param_1,0x3ef,0xf0,0,0);
  if (LVar4 == 1) {
    *(uint *)(*piVar6 + 0x1c) = *(uint *)(*piVar6 + 0x1c) | 2;
  }
  else {
    *(uint *)(*piVar6 + 0x1c) = *(uint *)(*piVar6 + 0x1c) & 0xfffffffd;
  }
  LVar4 = SendDlgItemMessageW(param_1,0x3f0,0xf0,0,0);
  if (LVar4 == 1) {
    *(uint *)(*piVar6 + 0x1c) = *(uint *)(*piVar6 + 0x1c) | 4;
  }
  else {
    *(uint *)(*piVar6 + 0x1c) = *(uint *)(*piVar6 + 0x1c) & 0xfffffffb;
  }
LAB_402dd67c:
  FUN_402f41d8(local_20);
  return 1;
}



/* 402dd6a4 FUN_402dd6a4 */

/* Boundary evidence: original MIPS .pdata 402dd6a4..402ddd2b. Semantic name remains unreviewed. */

undefined4 FUN_402dd6a4(HWND param_1,int param_2,uint param_3,int param_4)

{
  LRESULT LVar1;
  HWND pHVar2;
  HDC hdc;
  HWND pHVar3;
  size_t sVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  int Y;
  int cx;
  int *piVar8;
  tagRECT local_728;
  tagRECT local_718;
  tagSIZE local_708;
  tagRECT local_700;
  tagRECT tStack_6f0;
  WCHAR local_6e0;
  undefined1 auStack_6de [46];
  WCHAR local_6b0;
  undefined1 auStack_6ae [62];
  WCHAR local_670;
  undefined1 auStack_66e [62];
  WCHAR aWStack_630 [256];
  WCHAR local_430;
  undefined1 auStack_42e [1026];
  uint local_2c;
  
  local_2c = DAT_402f65fc;
  local_6e0 = L'\0';
  memset(auStack_6de,0,0x28);
  local_430 = L'\0';
  memset(auStack_42e,0,0x402);
  local_6b0 = L'\0';
  memset(auStack_6ae,0,0x3e);
  local_670 = L'\0';
  memset(auStack_66e,0,0x3e);
  if (param_2 == 0x4e) {
    if (param_4 != 0) {
      if (*(int *)(param_4 + 8) == -0xcd) {
        wcscpy(aWStack_630,L"file:rnetw.htm#Main_Contents");
        CreateProcessW(L"peghelp",aWStack_630,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,
                       0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
      }
      else if (*(int *)(param_4 + 8) == -0xca) {
        piVar8 = (int *)GetWindowLongW(param_1,-0x15);
        piVar8[5] = 1;
        LVar1 = SendDlgItemMessageW(param_1,0x3f9,0xf0,0,0);
        if (LVar1 == 1) {
          *(uint *)(*piVar8 + 0x18) = *(uint *)(*piVar8 + 0x18) & 0xfffffffb;
        }
        else {
          *(uint *)(*piVar8 + 0x18) = *(uint *)(*piVar8 + 0x18) | 4;
        }
        GetDlgItemTextW(param_1,0x3fb,&local_430,0x202);
        sVar4 = wcslen(&local_430);
        LCMapStringW(0x800,0x400000,&local_430,sVar4 + 1,(LPWSTR)(*piVar8 + 0x28),
                     *(int *)(*piVar8 + 0x24) + 1);
        GetDlgItemTextW(param_1,0x3fa,&local_6b0,0x10);
        sVar4 = wcslen(&local_6b0);
        LCMapStringW(0x800,0x400000,&local_6b0,sVar4 + 1,&local_670,0x10);
        uVar5 = _wtol(&local_670);
        if (0xffff < uVar5) {
          uVar5 = 0xffff;
        }
        *(short *)(*piVar8 + 0x12) = (short)uVar5;
        LVar1 = SendDlgItemMessageW(param_1,0x3f6,0xf0,0,0);
        if (LVar1 == 1) {
          GetDlgItemTextW(param_1,0x3f8,&local_6b0,0x10);
          sVar4 = wcslen(&local_6b0);
          LCMapStringW(0x800,0x400000,&local_6b0,sVar4 + 1,&local_670,0x10);
          lVar6 = _wtol(&local_670);
          *(long *)(*piVar8 + 0x14) = lVar6;
        }
        else {
          *(undefined4 *)(*piVar8 + 0x14) = 0;
        }
      }
    }
  }
  else if (param_2 == 0x110) {
    piVar8 = *(int **)(param_4 + 0x1c);
    SetWindowLongW(param_1,-0x15,(LONG)piVar8);
    if (piVar8[6] == 0) {
      pHVar2 = GetDlgItem(param_1,0x3f6);
      hdc = GetWindowDC(pHVar2);
      GetWindowRect(param_1,&local_718);
      pHVar3 = GetDlgItem(param_1,0x3f8);
      GetWindowRect(pHVar3,&local_700);
      pHVar3 = GetDlgItem(param_1,0x3f6);
      GetWindowRect(pHVar3,&local_728);
      pHVar3 = GetDlgItem(param_1,0x3f7);
      GetWindowRect(pHVar3,&tStack_6f0);
      GetDlgItemTextW(param_1,0x3f6,aWStack_630,0x82);
      sVar4 = wcslen(aWStack_630);
      GetTextExtentExPointW(hdc,aWStack_630,sVar4,0,(LPINT)0x0,(LPINT)0x0,&local_708);
      cx = local_708.cx + 0x16;
      SetWindowPos(pHVar2,(HWND)0x0,0,0,cx,local_728.bottom - local_728.top,6);
      iVar7 = local_728.left - local_718.left;
      Y = local_728.top - local_718.top;
      pHVar3 = GetDlgItem(param_1,0x3f8);
      SetWindowPos(pHVar3,(HWND)0x0,iVar7 + cx + 4,Y,0,0,5);
      pHVar3 = GetDlgItem(param_1,0x3f7);
      SetWindowPos(pHVar3,(HWND)0x0,
                   ((local_700.right - local_700.left) - local_718.left) + local_728.left + cx + 8,
                   tStack_6f0.top - local_718.top,0,0,5);
      ReleaseDC(pHVar2,hdc);
    }
    if (*(int *)(*piVar8 + 0x14) == 0) {
      pHVar2 = GetDlgItem(param_1,0x3f8);
      EnableWindow(pHVar2,0);
      SendDlgItemMessageW(param_1,0x3f6,0xf1,0,0);
    }
    else {
      SendDlgItemMessageW(param_1,0x3f6,0xf1,1,0);
    }
    if ((*(uint *)(*piVar8 + 0x18) & 4) == 0) {
      SendDlgItemMessageW(param_1,0x3f9,0xf1,1,0);
    }
    else {
      SendDlgItemMessageW(param_1,0x3f9,0xf1,0,0);
    }
    pHVar2 = GetDlgItem(param_1,0x3fb);
    ImmAssociateContext(pHVar2,(HIMC)0x0);
    SendDlgItemMessageW(param_1,0x3fb,0xc5,*(WPARAM *)(*piVar8 + 0x24),0);
    SendDlgItemMessageW(param_1,0x3f8,0xc5,4,0);
    SendDlgItemMessageW(param_1,0x3fa,0xc5,4,0);
    SetDlgItemTextW(param_1,0x3fb,(LPCWSTR)(*piVar8 + 0x28));
    wsprintfW(&local_6e0,L"%d",(uint)*(ushort *)(*piVar8 + 0x12));
    SetDlgItemTextW(param_1,0x3fa,&local_6e0);
    wsprintfW(&local_6e0,L"%u",*(undefined4 *)(*piVar8 + 0x14));
    SetDlgItemTextW(param_1,0x3f8,&local_6e0);
  }
  else if (((param_2 == 0x111) && (param_3 >> 0x10 == 0)) && ((param_3 & 0xffff) == 0x3f6)) {
    LVar1 = SendDlgItemMessageW(param_1,0x3f6,0xf0,0,0);
    pHVar2 = GetDlgItem(param_1,0x3f8);
    EnableWindow(pHVar2,(uint)(LVar1 == 1));
  }
  FUN_402f41d8(local_2c);
  return 0;
}



/* 402ddd2c LineConfigEdit */

/* Boundary evidence: original MIPS .pdata 402ddd2c..402ddfa7. Semantic name remains unreviewed. */

bool LineConfigEdit(undefined4 param_1,undefined4 param_2)

{
  undefined4 *hMem;
  int iVar1;
  DWORD DVar2;
  undefined4 local_160;
  uint local_15c;
  undefined4 local_158;
  HINSTANCE local_154;
  undefined4 local_150;
  WCHAR *local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 *local_140;
  undefined1 *local_13c;
  undefined4 local_138;
  undefined4 local_134;
  HINSTANCE local_130;
  undefined4 local_12c;
  undefined4 local_128;
  WCHAR *local_124;
  code *local_120;
  undefined4 *local_11c;
  undefined4 local_118;
  undefined4 local_110;
  undefined4 local_10c;
  HINSTANCE local_108;
  undefined4 local_104;
  undefined4 local_100;
  WCHAR *local_fc;
  code *local_f8;
  undefined4 *local_f4;
  undefined4 local_f0;
  WCHAR aWStack_e8 [32];
  WCHAR aWStack_a8 [32];
  WCHAR aWStack_68 [30];
  uint local_2c;
  
                    /* 0xdd2c  30  LineConfigEdit */
  local_2c = DAT_402f65fc;
  if ((DAT_402fc380 != (code *)0x0) && ((*DAT_402fc380)(), DAT_402fc3b4 != (code *)0x0)) {
    hMem = LocalAlloc(0x40,0x1c);
    if (hMem != (undefined4 *)0x0) {
      *hMem = param_2;
      iVar1 = GetSystemMetrics(0);
      if (iVar1 < 0x1e0) {
        hMem[6] = 1;
      }
      else {
        hMem[6] = 0;
      }
      local_138 = 0x28;
      local_134 = 8;
      local_130 = DAT_402fc3c4;
      local_12c = 0x67;
      if (hMem[6] == 0) {
        local_12c = 0x66;
      }
      local_128 = 0;
      local_120 = FUN_402dca80;
      LoadStringW(DAT_402fc3c4,4,aWStack_68,0x1e);
      local_124 = aWStack_68;
      local_118 = 0;
      local_110 = 0x28;
      local_10c = 8;
      local_108 = DAT_402fc3c4;
      local_104 = 0x69;
      if (hMem[6] == 0) {
        local_104 = 0x68;
      }
      local_100 = 0;
      local_f8 = FUN_402dd6a4;
      local_11c = hMem;
      LoadStringW(DAT_402fc3c4,5,aWStack_e8,0x1e);
      local_fc = aWStack_e8;
      local_15c = 0x108;
      local_f0 = 0;
      local_160 = 0x28;
      local_f4 = hMem;
      DVar2 = GetFileAttributesW(L"\\Windows\\peghelp.exe");
      if ((DVar2 != 0xffffffff) &&
         (DVar2 = GetFileAttributesW(L"\\Windows\\rnetw.htm"), DVar2 != 0xffffffff)) {
        local_15c = local_15c | 0x200;
      }
      local_154 = DAT_402fc3c4;
      local_150 = 0;
      local_158 = param_1;
      LoadStringW(DAT_402fc3c4,6,aWStack_a8,0x1e);
      local_148 = 2;
      local_14c = aWStack_a8;
      local_13c = &LAB_402d3898;
      local_140 = &local_138;
      local_144 = 0;
      (*DAT_402fc3b4)(&local_160);
      iVar1 = hMem[5];
      LocalFree(hMem);
      FUN_402f41d8(local_2c);
      return iVar1 != 0;
    }
    SetLastError(8);
  }
  FUN_402f41d8(local_2c);
  return false;
}



/* 402ddfa8 LineConfigEditExt */

/* Boundary evidence: original MIPS .pdata 402ddfa8..402de06b. Semantic name remains unreviewed. */

undefined4
LineConfigEditExt(void *param_1,uint param_2,DWORD *param_3,size_t param_4,size_t *param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  DWORD DVar2;
  
                    /* 0xdfa8  31  LineConfigEditExt */
  if (param_3 != (DWORD *)0x0) {
    if ((((param_1 == (void *)0x0) || (param_5 == (size_t *)0x0)) || (param_2 < 0x234)) ||
       (param_2 != param_4)) {
      *param_3 = 0x57;
    }
    else {
      *param_5 = param_4;
      memcpy(param_3,param_1,param_4);
      DVar2 = param_3[1];
      *param_3 = 0;
      SetLastError(0);
      bVar1 = LineConfigEdit(DVar2,param_3 + 2);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        return 1;
      }
      DVar2 = GetLastError();
      *param_3 = DVar2;
    }
  }
  return 0;
}



/* 402de06c FUN_402de06c */

undefined4 FUN_402de06c(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (((DAT_402f8940 == 0) || (param_1 < 0)) || (DAT_402fc354 <= param_1)) {
    *param_2 = 0;
    uVar1 = 0;
  }
  else {
    *param_2 = param_1 * 0x210 + DAT_402f8940;
    uVar1 = 1;
  }
  return uVar1;
}



/* 402de0c4 FUN_402de0c4 */

/* Boundary evidence: original MIPS .pdata 402de0c4..402de173. Semantic name remains unreviewed. */

LRESULT FUN_402de0c4(HWND param_1)

{
  LRESULT LVar1;
  LRESULT LVar2;
  WPARAM wParam;
  int local_20 [2];
  
  LVar1 = SendMessageW(param_1,0x146,0,0);
  wParam = 0;
  if (0 < LVar1) {
    do {
      LVar2 = SendMessageW(param_1,0x150,wParam,0);
      FUN_402de06c(LVar2,local_20);
      if ((local_20[0] != 0) && (*(int *)(local_20[0] + 0x20c) != 3)) {
        return LVar2;
      }
      wParam = wParam + 1;
    } while ((int)wParam < LVar1);
  }
  return 0;
}



/* 402de174 FUN_402de174 */

/* Boundary evidence: original MIPS .pdata 402de174..402de1bf. Semantic name remains unreviewed. */

void FUN_402de174(HWND param_1)

{
  SendMessageW(param_1,0xb,1,0);
  InvalidateRect(param_1,(RECT *)0x0,1);
  UpdateWindow(param_1);
  return;
}



/* 402de1c0 FUN_402de1c0 */

/* Boundary evidence: original MIPS .pdata 402de1c0..402de3f3. Semantic name remains unreviewed. */

undefined4 FUN_402de1c0(HWND param_1,uint param_2,int param_3)

{
  HWND pHVar1;
  UINT UVar2;
  WPARAM WVar3;
  undefined4 uVar4;
  int lParam;
  int iVar5;
  int local_30 [2];
  
  WVar3 = 0xffffffff;
  if ((DAT_402f8940 == 0) || (param_1 == (HWND)0x0)) {
LAB_402de3ac:
    uVar4 = 100;
  }
  else {
    pHVar1 = GetDlgItem(param_1,param_2);
    SendMessageW(pHVar1,0xb,0,0);
    UVar2 = 0x184;
    if (param_3 == 0) {
      UVar2 = 0x14b;
    }
    SendDlgItemMessageW(param_1,param_2,UVar2,0,0);
    lParam = 0;
    iVar5 = DAT_402fc354;
    if (0 < DAT_402fc354) {
      do {
        FUN_402de06c(lParam,local_30);
        if ((local_30[0] != 0) && (*(int *)(local_30[0] + 0x20c) != 3)) {
          UVar2 = 0x180;
          if (param_3 == 0) {
            UVar2 = 0x143;
          }
          WVar3 = SendDlgItemMessageW(param_1,param_2,UVar2,0,local_30[0] + 4);
          if ((int)WVar3 < 0) break;
          UVar2 = 0x19a;
          if (param_3 == 0) {
            UVar2 = 0x151;
          }
          WVar3 = SendDlgItemMessageW(param_1,param_2,UVar2,WVar3,lParam);
          iVar5 = DAT_402fc354;
          if ((int)WVar3 < 0) break;
        }
        lParam = lParam + 1;
      } while (lParam < iVar5);
      if ((WVar3 != 0xfffffffe) && (WVar3 != 0xffffffff)) {
        FUN_402de06c(DAT_402fc348,local_30);
        if (local_30[0] != 0) {
          UVar2 = 399;
          if (param_3 == 0) {
            UVar2 = 0x14c;
          }
          WVar3 = SendDlgItemMessageW(param_1,param_2,UVar2,0,local_30[0] + 4);
          if (WVar3 != 0xffffffff) {
            UVar2 = 0x186;
            if (param_3 == 0) {
              UVar2 = 0x14e;
            }
            SendDlgItemMessageW(param_1,param_2,UVar2,WVar3,0);
            pHVar1 = GetDlgItem(param_1,param_2);
            PostMessageW(param_1,0x111,param_2 & 0xffff | 0x10000,(LPARAM)pHVar1);
            uVar4 = 0;
            goto LAB_402de3b0;
          }
        }
        goto LAB_402de3ac;
      }
    }
    uVar4 = 0x65;
  }
LAB_402de3b0:
  pHVar1 = GetDlgItem(param_1,param_2);
  FUN_402de174(pHVar1);
  return uVar4;
}



/* 402de3f4 FUN_402de3f4 */

/* Boundary evidence: original MIPS .pdata 402de3f4..402de493. Semantic name remains unreviewed. */

int FUN_402de3f4(wchar_t *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_20 [2];
  
  iVar2 = 0;
  iVar3 = DAT_402fc354;
  if (0 < DAT_402fc354) {
    do {
      FUN_402de06c(iVar2,local_20);
      if (((local_20[0] != 0) && (*(int *)(local_20[0] + 0x20c) != 3)) &&
         (iVar1 = _wcsicmp(param_1,(wchar_t *)(local_20[0] + 4)), iVar3 = DAT_402fc354, iVar1 == 0))
      {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return -1;
}



/* 402de494 FUN_402de494 */

/* Boundary evidence: original MIPS .pdata 402de494..402de72b. Semantic name remains unreviewed. */

undefined4 FUN_402de494(HWND param_1,short *param_2)

{
  HWND pHVar1;
  HWND hWnd;
  size_t sVar2;
  LRESULT LVar3;
  WPARAM WVar4;
  WPARAM wParam;
  short *lParam;
  wchar_t *_Str;
  LPARAM *pLVar5;
  LPARAM *pLVar6;
  int iVar7;
  
  pHVar1 = GetDlgItem(param_1,0x417);
  hWnd = GetDlgItem(param_1,0x40a);
  pLVar5 = (LPARAM *)&DAT_402f63dc;
  if (DAT_402f63dc == (undefined *)0x0) {
    DAT_402f63dc = &DAT_402f8950;
    iVar7 = 0;
    pLVar6 = pLVar5;
    do {
      LoadStringW(DAT_402fc3c4,iVar7 + 0x42f,(LPWSTR)*pLVar6,
                  0x84 - ((int)((LPWSTR)*pLVar6 + -0x2017c4a8) >> 1));
      _Str = (wchar_t *)*pLVar6;
      sVar2 = wcslen(_Str);
      iVar7 = iVar7 + 1;
      pLVar6[1] = (LPARAM)(_Str + sVar2 + 1);
      pLVar6 = pLVar6 + 1;
    } while (iVar7 < 3);
  }
  SendMessageW(pHVar1,0xb,0,0);
  SendMessageW(pHVar1,0x14b,0,0);
  LVar3 = SendDlgItemMessageW(param_1,0x420,0xf0,0,0);
  if (LVar3 == 0) {
    *param_2 = 0;
    EnableWindow(pHVar1,0);
    if (hWnd != (HWND)0x0) {
      EnableWindow(hWnd,0);
    }
    FUN_402de174(pHVar1);
  }
  else {
    if (hWnd != (HWND)0x0) {
      EnableWindow(hWnd,1);
    }
    EnableWindow(pHVar1,1);
    iVar7 = 0;
    do {
      WVar4 = SendMessageW(pHVar1,0x143,0,*pLVar5);
      SendMessageW(pHVar1,0x151,WVar4,iVar7);
      iVar7 = iVar7 + 1;
      pLVar5 = pLVar5 + 1;
    } while (iVar7 < 3);
    WVar4 = SendDlgItemMessageW(param_1,0x417,0x14c,0,(LPARAM)param_2);
    lParam = (short *)PTR_DAT_402f63e8;
    if ((WVar4 == 0xffffffff) && (*param_2 != 0)) {
      lParam = param_2;
    }
    wParam = SendMessageW(pHVar1,0x143,0,(LPARAM)lParam);
    SendMessageW(pHVar1,0x151,wParam,3);
    if ((WVar4 == 0xffffffff) && (WVar4 = wParam, *param_2 == 0)) {
      WVar4 = 0;
    }
    SendMessageW(pHVar1,0x14e,WVar4,0);
    FUN_402de174(pHVar1);
    pHVar1 = GetDlgItem(param_1,0x417);
    InvalidateRect(pHVar1,(RECT *)0x0,1);
  }
  return 0;
}



/* 402de72c FUN_402de72c */

/* Boundary evidence: original MIPS .pdata 402de72c..402de7df. Semantic name remains unreviewed. */

void FUN_402de72c(HWND param_1,int param_2)

{
  HWND hWnd;
  LRESULT LVar1;
  int iVar2;
  LPWSTR lpString;
  
  hWnd = GetDlgItem(param_1,0x417);
  LVar1 = SendDlgItemMessageW(param_1,0x420,0xf0,0,0);
  if (LVar1 == 0) {
    *(undefined2 *)(param_2 + 0x1de) = 0;
  }
  else {
    EnableWindow(hWnd,1);
    lpString = (LPWSTR)(param_2 + 0x1de);
    iVar2 = GetWindowTextW(hWnd,lpString,9);
    if (iVar2 == 0) {
      FUN_402de494(param_1,lpString);
      GetWindowTextW(hWnd,lpString,9);
    }
  }
  return;
}



/* 402de7e0 FUN_402de7e0 */

/* Boundary evidence: original MIPS .pdata 402de7e0..402de86b. Semantic name remains unreviewed. */

undefined4 FUN_402de7e0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = lstrcmpW((LPCWSTR)(param_1 + 0x42),(LPCWSTR)(param_2 + 0x42));
  if (((iVar1 == 0) &&
      (iVar1 = lstrcmpW((LPCWSTR)(param_1 + 0xc4),(LPCWSTR)(param_2 + 0xc4)), iVar1 == 0)) &&
     (iVar1 = lstrcmpW((LPCWSTR)(param_1 + 0x146),(LPCWSTR)(param_2 + 0x146)), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 402de86c FUN_402de86c */

/* Boundary evidence: original MIPS .pdata 402de86c..402de92b. Semantic name remains unreviewed. */

undefined4 FUN_402de86c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_402de7e0(param_1,param_2);
  if ((((iVar1 != 0) ||
       (iVar1 = lstrcmpW((LPCWSTR)(param_1 + 4),(LPCWSTR)(param_2 + 4)), iVar1 != 0)) ||
      (iVar1 = lstrcmpW((LPCWSTR)(param_1 + 0x1de),(LPCWSTR)(param_2 + 0x1de)), iVar1 != 0)) ||
     (((iVar1 = lstrcmpW((LPCWSTR)(param_1 + 0x1f0),(LPCWSTR)(param_2 + 0x1f0)), iVar1 != 0 ||
       (iVar1 = lstrcmpW((LPCWSTR)(param_1 + 0x1c8),(LPCWSTR)(param_2 + 0x1c8)), iVar1 != 0)) ||
      (uVar2 = 0, *(int *)(param_1 + 0x208) != *(int *)(param_2 + 0x208))))) {
    uVar2 = 1;
  }
  return uVar2;
}



/* 402de92c FUN_402de92c */

/* Boundary evidence: original MIPS .pdata 402de92c..402dea43. Semantic name remains unreviewed. */

undefined4 FUN_402de92c(HWND param_1,void *param_2,undefined4 *param_3)

{
  LRESULT LVar1;
  int iVar2;
  undefined1 auStack_228 [528];
  uint local_18;
  
  local_18 = DAT_402f65fc;
  GetDlgItem(param_1,0x418);
  *param_3 = 0;
  memcpy(auStack_228,param_2,0x210);
  FUN_402de72c(param_1,(int)param_2);
  GetDlgItemTextW(param_1,0x41b,(LPWSTR)((int)param_2 + 0x1f0),0xb);
  GetDlgItemTextW(param_1,0x41a,(LPWSTR)((int)param_2 + 0x1c8),0xb);
  LVar1 = SendDlgItemMessageW(param_1,0x421,0xf0,0,0);
  if (LVar1 == 0) {
    *(uint *)((int)param_2 + 0x208) = *(uint *)((int)param_2 + 0x208) & 0xfffffffe;
  }
  else {
    *(uint *)((int)param_2 + 0x208) = *(uint *)((int)param_2 + 0x208) | 1;
  }
  iVar2 = FUN_402de86c((int)param_2,(int)auStack_228);
  if ((iVar2 != 0) && (*(int *)((int)param_2 + 0x20c) != 1)) {
    *(undefined4 *)((int)param_2 + 0x20c) = 2;
    *param_3 = 2;
  }
  FUN_402f41d8(local_18);
  return 0;
}



/* 402dea44 FUN_402dea44 */

/* Boundary evidence: original MIPS .pdata 402dea44..402deae3. Semantic name remains unreviewed. */

undefined4 FUN_402dea44(void)

{
  longlong lVar1;
  HLOCAL pvVar2;
  undefined4 uVar3;
  
  if (((((int)(DAT_402fc354 + 1U) < DAT_402fc354) ||
       (lVar1 = (ulonglong)(DAT_402fc354 + 1U) * 0x210, (int)((ulonglong)lVar1 >> 0x20) != 0)) ||
      (0x7fffffff < (uint)lVar1)) ||
     (pvVar2 = LocalReAlloc(DAT_402f8940,(DAT_402fc354 + 1) * 0x210,0x42), pvVar2 == (HLOCAL)0x0)) {
    uVar3 = 0x65;
  }
  else {
    DAT_402fc354 = DAT_402fc354 + 1;
    uVar3 = 0;
    DAT_402f8940 = pvVar2;
  }
  return uVar3;
}



/* 402deae4 FUN_402deae4 */

/* Boundary evidence: original MIPS .pdata 402deae4..402deb2b. Semantic name remains unreviewed. */

undefined4 FUN_402deae4(void)

{
  undefined4 uVar1;
  
  if (DAT_402f8940 == (HLOCAL)0x0) {
    uVar1 = 100;
  }
  else {
    LocalFree(DAT_402f8940);
    DAT_402f8940 = (HLOCAL)0x0;
    uVar1 = 0;
  }
  return uVar1;
}



/* 402deb2c FUN_402deb2c */

/* Boundary evidence: original MIPS .pdata 402deb2c..402deedb. Semantic name remains unreviewed. */

undefined4 FUN_402deb2c(HWND param_1,int param_2,short param_3,void *param_4)

{
  size_t sVar1;
  int iVar2;
  HWND pHVar3;
  DWORD DVar4;
  uint uVar5;
  INT_PTR nResult;
  undefined1 auStack_340 [528];
  WCHAR aWStack_130 [132];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  if (param_2 == 0x53) {
    CreateProcessW(L"peghelp",L"ctpnl.htm#adjust_dialing_patterns",(LPSECURITY_ATTRIBUTES)0x0,
                   (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,
                   (LPPROCESS_INFORMATION)0x0);
  }
  else if (param_2 == 0x110) {
    DAT_402f8944 = param_4;
    SendDlgItemMessageW(param_1,0x41d,0xc5,0x40,0);
    SendDlgItemMessageW(param_1,0x41e,0xc5,0x40,0);
    SendDlgItemMessageW(param_1,0x41c,0xc5,0x40,0);
    SetDlgItemTextW(param_1,0x41d,(LPCWSTR)((int)DAT_402f8944 + 0x42));
    SetDlgItemTextW(param_1,0x41e,(LPCWSTR)((int)DAT_402f8944 + 0xc4));
    SetDlgItemTextW(param_1,0x41c,(LPCWSTR)((int)DAT_402f8944 + 0x146));
    pHVar3 = GetDlgItem(param_1,0x41d);
    SetWindowLongW(pHVar3,-4,0x402ed6f4);
    pHVar3 = GetDlgItem(param_1,0x41e);
    SetWindowLongW(pHVar3,-4,0x402ed6f4);
    pHVar3 = GetDlgItem(param_1,0x41c);
    SetWindowLongW(pHVar3,-4,0x402ed6f4);
    DVar4 = GetFileAttributesW(L"\\Windows\\peghelp.exe");
    if (DVar4 != 0xffffffff) {
      uVar5 = GetWindowLongW(param_1,-0x14);
      SetWindowLongW(param_1,-0x14,uVar5 | 0x400);
    }
    pHVar3 = GetDlgItem(param_1,0x41d);
    ImmAssociateContext(pHVar3,(HIMC)0x0);
    pHVar3 = GetDlgItem(param_1,0x41e);
    ImmAssociateContext(pHVar3,(HIMC)0x0);
    pHVar3 = GetDlgItem(param_1,0x41c);
    ImmAssociateContext(pHVar3,(HIMC)0x0);
    pHVar3 = GetDlgItem(param_1,0x41d);
    SetFocus(pHVar3);
    SendDlgItemMessageW(param_1,0x41d,0xb1,0,-1);
  }
  else if (param_2 == 0x111) {
    if (param_3 == 1) {
      memcpy(auStack_340,DAT_402f8944,0x210);
      GetDlgItemTextW(param_1,0x41d,aWStack_130,0x41);
      sVar1 = wcslen(aWStack_130);
      LCMapStringW(0x800,0x400000,aWStack_130,sVar1 + 1,(LPWSTR)((int)DAT_402f8944 + 0x42),0x41);
      GetDlgItemTextW(param_1,0x41e,aWStack_130,0x41);
      sVar1 = wcslen(aWStack_130);
      LCMapStringW(0x800,0x400000,aWStack_130,sVar1 + 1,(LPWSTR)((int)DAT_402f8944 + 0xc4),0x41);
      GetDlgItemTextW(param_1,0x41c,aWStack_130,0x41);
      sVar1 = wcslen(aWStack_130);
      LCMapStringW(0x800,0x400000,aWStack_130,sVar1 + 1,(LPWSTR)((int)DAT_402f8944 + 0x146),0x41);
      iVar2 = FUN_402de7e0((int)DAT_402f8944,(int)auStack_340);
      if ((iVar2 != 0) && (*(int *)((int)DAT_402f8944 + 0x20c) != 1)) {
        *(undefined4 *)((int)DAT_402f8944 + 0x20c) = 2;
      }
      nResult = 1;
    }
    else {
      if (param_3 != 2) goto LAB_402deeac;
      nResult = 0;
    }
    EndDialog(param_1,nResult);
  }
LAB_402deeac:
  FUN_402f41d8(local_28);
  return 0;
}



/* 402deedc FUN_402deedc */

/* Boundary evidence: original MIPS .pdata 402deedc..402df18b. Semantic name remains unreviewed. */

undefined4 FUN_402deedc(HWND param_1,int param_2,short param_3,int param_4)

{
  size_t sVar1;
  HWND pHVar2;
  int iVar3;
  INT_PTR nResult;
  WCHAR *pWVar4;
  int iVar5;
  WCHAR *pWVar6;
  undefined4 *local_268;
  void *local_264;
  WCHAR local_260 [32];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_402f65fc;
  if (param_2 == 0x110) {
    DAT_402f8938 = param_4;
    SendDlgItemMessageW(param_1,0x41f,0xc5,0x1e,0);
    pHVar2 = GetDlgItem(param_1,0x41f);
    SetFocus(pHVar2);
    goto LAB_402df168;
  }
  if (param_2 != 0x111) goto LAB_402df168;
  if (param_3 == 1) {
    GetDlgItemTextW(param_1,0x41f,local_260,0x1f);
    if (local_260[0] != L'\0') {
      pWVar4 = local_260;
      iVar5 = 0;
      do {
        iVar3 = iVar5;
        if (*pWVar4 != L' ') break;
        iVar3 = iVar5 + 1;
        pWVar4 = local_260 + iVar5 + 1;
        iVar5 = iVar3;
      } while (*pWVar4 != L'\0');
      if (iVar3 != 0) {
        pWVar4 = local_260 + iVar3;
        iVar5 = 0;
        if (*pWVar4 != L'\0') {
          pWVar6 = local_260;
          do {
            *pWVar6 = *pWVar4;
            pWVar4 = local_260 + iVar3 + 1;
            iVar5 = iVar5 + 1;
            pWVar6 = pWVar6 + 1;
            iVar3 = iVar3 + 1;
          } while (*pWVar4 != L'\0');
        }
        local_260[iVar5] = L'\0';
      }
    }
    sVar1 = wcslen(local_260);
    iVar5 = sVar1 - 1;
    if (0 < iVar5) {
      pWVar4 = local_260 + (sVar1 - 1);
      do {
        if (*pWVar4 != L' ') break;
        iVar5 = iVar5 + -1;
        pWVar4 = pWVar4 + -1;
      } while (0 < iVar5);
    }
    local_260[iVar5 + 1] = L'\0';
    if (local_260[0] == L'\0') goto LAB_402def38;
    iVar5 = FUN_402de3f4(local_260);
    if (-1 < iVar5) {
      LoadStringW(DAT_402fc3c4,0x425,aWStack_220,0x104);
      MessageBoxW(param_1,aWStack_220,(LPCWSTR)0x0,0x30);
      pHVar2 = GetDlgItem(param_1,0x41f);
      SetFocus(pHVar2);
      SendDlgItemMessageW(param_1,0x41f,0xb1,0,-1);
      goto LAB_402df168;
    }
    FUN_402dea44();
    FUN_402de06c(DAT_402f8938,(int *)&local_264);
    FUN_402de06c(DAT_402fc354 + -1,(int *)&local_268);
    if ((local_264 != (void *)0x0) && (local_268 != (undefined4 *)0x0)) {
      memcpy(local_268,local_264,0x210);
      wcscpy((wchar_t *)(local_268 + 1),local_260);
      local_268[0x83] = 1;
      *local_268 = 0xffffffff;
    }
    nResult = 1;
  }
  else {
    if (param_3 != 2) goto LAB_402df168;
LAB_402def38:
    nResult = 0;
  }
  EndDialog(param_1,nResult);
LAB_402df168:
  FUN_402f41d8(local_18);
  return 0;
}



/* 402df18c FUN_402df18c */

/* Boundary evidence: original MIPS .pdata 402df18c..402df213. Semantic name remains unreviewed. */

undefined4 FUN_402df18c(HWND param_1)

{
  HWND pHVar1;
  HWND pHVar2;
  
  pHVar1 = GetDlgItem(param_1,0x418);
  DAT_402f893c = 0;
  pHVar1 = GetWindow(pHVar1,5);
  pHVar2 = GetFocus();
  if ((pHVar2 == pHVar1) && (SendMessageW(param_1,0x111,0x40418,0), DAT_402f893c != 0)) {
    return 0;
  }
  return 1;
}



/* 402df214 FUN_402df214 */

/* Boundary evidence: original MIPS .pdata 402df214..402df277. Semantic name remains unreviewed. */

LSTATUS FUN_402df214(void)

{
  LSTATUS LVar1;
  int local_10 [2];
  
  DAT_402fc348 = 0;
  local_10[0] = 0;
  LVar1 = FUN_402edcf8(local_10);
  if (LVar1 == 0) {
    DAT_402f8940 = local_10[0];
    if (local_10[0] != 0) {
      return 0;
    }
    LVar1 = 0x65;
  }
  FUN_402deae4();
  return LVar1;
}



/* 402df278 FUN_402df278 */

/* Boundary evidence: original MIPS .pdata 402df278..402dfee3. Semantic name remains unreviewed. */

HANDLE FUN_402df278(HWND param_1,int param_2,uint param_3)

{
  LRESULT LVar1;
  int iVar2;
  HWND pHVar3;
  HRSRC pHVar4;
  LPCDLGTEMPLATEW pDVar5;
  INT_PTR IVar6;
  HCURSOR pHVar7;
  DWORD DVar8;
  LSTATUS LVar9;
  wchar_t *pwVar10;
  WPARAM WVar11;
  WPARAM WVar12;
  uint uVar13;
  LPCWSTR pWVar14;
  uint uVar15;
  int nIDDlgItem;
  HANDLE dwNewLong;
  HANDLE pvVar16;
  undefined4 auStack_140 [2];
  WCHAR local_138 [132];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  pvVar16 = (HANDLE)0x0;
  if (param_2 == 2) {
    pHVar3 = GetDlgItem(param_1,0x41a);
    if (pHVar3 != (HWND)0x0) {
      FUN_402ed320((int)pHVar3);
    }
    pHVar3 = GetDlgItem(param_1,0x41b);
    if (pHVar3 != (HWND)0x0) {
      FUN_402ed320((int)pHVar3);
    }
LAB_402dfe9c:
    FUN_402deae4();
    goto switchD_402df714_caseD_419;
  }
  dwNewLong = (HANDLE)0x1;
  if (param_2 == 0x10) goto switchD_402df714_caseD_423;
  if (param_2 == 0x53) {
    CreateProcessW(L"peghelp",L"ctpnl.htm#adjust_dialing_location_settings",
                   (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,
                   (LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
    goto switchD_402df714_caseD_419;
  }
  if (param_2 == 0x7f) {
    dwNewLong = LoadImageW(DAT_402fc3c4,(LPCWSTR)0x435,1,0x10,0x10,0);
    SetWindowLongW(param_1,0,(LONG)dwNewLong);
    goto LAB_402dfdfc;
  }
  if (param_2 == 0x110) {
    DAT_402fc34c = param_1;
    if (DAT_402fc358 != (undefined4 *)0x0) {
      *DAT_402fc358 = param_1;
    }
    DAT_402f8948 = GetDlgItem(param_1,0x418);
    SendMessageW(DAT_402f8948,0x141,0x1e,0);
    pHVar3 = GetDlgItem(param_1,0x417);
    SendMessageW(pHVar3,0x141,8,0);
    SendDlgItemMessageW(param_1,0x41a,0xc5,10,0);
    SendDlgItemMessageW(param_1,0x41b,0xc5,10,0);
    DVar8 = GetFileAttributesW(L"\\Windows\\peghelp.exe");
    if (DVar8 != 0xffffffff) {
      uVar15 = GetWindowLongW(param_1,-0x14);
      SetWindowLongW(param_1,-0x14,uVar15 | 0x400);
    }
    LVar9 = FUN_402df214();
    if (LVar9 != 0) goto LAB_402dfe9c;
    iVar2 = FUN_402de1c0(param_1,0x418,0);
    if (iVar2 != 0) goto LAB_402df904;
    pwVar10 = (wchar_t *)FUN_402ed584(param_1,0x418,0);
    iVar2 = FUN_402de3f4(pwVar10);
    if ((iVar2 < 0) || (FUN_402de06c(iVar2,(int *)&DAT_402f894c), DAT_402f894c == (void *)0x0))
    goto LAB_402df904;
    pHVar3 = GetDlgItem(param_1,0x418);
    ImmAssociateContext(pHVar3,(HIMC)0x0);
    pHVar3 = GetDlgItem(param_1,0x417);
    pHVar3 = GetWindow(pHVar3,5);
    ImmAssociateContext(pHVar3,(HIMC)0x0);
    DAT_402fc340 = SetWindowLongW(pHVar3,-4,0x402ed6f4);
    pHVar3 = GetDlgItem(param_1,0x41a);
    if (pHVar3 != (HWND)0x0) {
      FUN_402ed2d0(pHVar3);
      SetWindowLongW(pHVar3,-4,0x402ed6f4);
    }
    pHVar3 = GetDlgItem(param_1,0x41b);
    if (pHVar3 != (HWND)0x0) {
      FUN_402ed2d0(pHVar3);
      SetWindowLongW(pHVar3,-4,0x402ed6f4);
    }
LAB_402dfc04:
    WVar11 = SendMessageW(DAT_402f8948,0x14c,0xffffffff,(int)DAT_402f894c + 4);
    if (WVar11 == 0xffffffff) {
      pvVar16 = (HANDLE)0x64;
LAB_402df904:
      FUN_402f41d8(local_30);
      return pvVar16;
    }
    WVar12 = SendMessageW(DAT_402f8948,0x147,0,0);
    if (WVar11 != WVar12) {
      SendMessageW(DAT_402f8948,0x14e,WVar11,0);
    }
    SetDlgItemTextW(param_1,0x41a,(LPCWSTR)((int)DAT_402f894c + 0x1c8));
    SetDlgItemTextW(param_1,0x41b,(LPCWSTR)((int)DAT_402f894c + 0x1f0));
    nIDDlgItem = 0x421;
    iVar2 = 0x421;
    if ((*(uint *)((int)DAT_402f894c + 0x208) & 1) == 0) {
      iVar2 = 0x422;
    }
    SendDlgItemMessageW(param_1,iVar2,0xf1,1,0);
    if ((*(uint *)((int)DAT_402f894c + 0x208) & 1) != 0) {
      nIDDlgItem = 0x422;
    }
    SendDlgItemMessageW(param_1,nIDDlgItem,0xf1,0,0);
    SendDlgItemMessageW(param_1,0x420,0xf1,(uint)(*(short *)((int)DAT_402f894c + 0x1de) != 0),0);
    FUN_402de494(param_1,(short *)((int)DAT_402f894c + 0x1de));
    LVar1 = SendMessageW(DAT_402f8948,0x146,0,0);
    pHVar3 = GetDlgItem(param_1,0x415);
    EnableWindow(pHVar3,(uint)(1 < LVar1));
    pHVar3 = GetDlgItem(param_1,0x414);
    EnableWindow(pHVar3,(uint)(LVar1 < 0x10));
    goto LAB_402dfd84;
  }
  if ((param_2 != 0x111) || (uVar15 = param_3 >> 0x10, DAT_402fc34c == (HWND)0x0))
  goto switchD_402df714_caseD_419;
  uVar13 = param_3 & 0xffff;
  if (uVar13 < 0x418) {
    if (uVar13 != 0x417) {
      if (uVar13 == 1) {
        iVar2 = FUN_402df18c(param_1);
        if (iVar2 == 0) goto switchD_402df714_caseD_419;
        FUN_402de92c(param_1,DAT_402f894c,auStack_140);
        pHVar7 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
        pHVar7 = SetCursor(pHVar7);
        FUN_402ee2fc();
        SetCursor(pHVar7);
        IVar6 = 1;
      }
      else {
        if (uVar13 != 2) {
          if (uVar13 == 0x40c) goto switchD_402df714_caseD_423;
          if (uVar13 != 0x413) {
            if (uVar13 == 0x414) {
              iVar2 = FUN_402df18c(param_1);
              if (iVar2 == 0) goto switchD_402df714_caseD_419;
              pHVar3 = GetDlgItem(param_1,0x414);
              SetFocus(pHVar3);
              WVar11 = SendMessageW(DAT_402f8948,0x147,0,0);
              LVar1 = SendMessageW(DAT_402f8948,0x150,WVar11,0);
              pWVar14 = (LPCWSTR)0x44f;
              if (0x1df < DAT_402fc350) {
                pWVar14 = (LPCWSTR)0x44e;
              }
              pHVar4 = FindResourceW(DAT_402fc3c4,pWVar14,(LPCWSTR)0x5);
              pDVar5 = LoadResource(DAT_402fc3c4,pHVar4);
              IVar6 = DialogBoxIndirectParamW(DAT_402fc3c4,pDVar5,param_1,FUN_402deedc,LVar1);
              LVar1 = DAT_402fc348;
              if (IVar6 == 0) goto LAB_402df8ec;
              pHVar3 = GetDlgItem(param_1,0x41a);
              SetFocus(pHVar3);
              pHVar3 = GetDlgItem(param_1,0x41a);
              PostMessageW(pHVar3,0xb1,0,-1);
              pHVar3 = GetDlgItem(param_1,0x414);
              SendMessageW(pHVar3,0xf4,0,1);
              DAT_402fc348 = DAT_402fc354 + -1;
            }
            else {
              if (((uVar13 != 0x415) || (LVar1 = SendMessageW(DAT_402f8948,0x146,0,0), LVar1 < 2))
                 || (iVar2 = FUN_402df18c(param_1), iVar2 == 0)) goto switchD_402df714_caseD_419;
              pHVar3 = GetDlgItem(param_1,0x415);
              SetFocus(pHVar3);
              iVar2 = FUN_402ed3fc(param_1,0x429,0x42a,0x104);
              if (iVar2 != 6) goto switchD_402df714_caseD_419;
              *(undefined4 *)((int)DAT_402f894c + 0x20c) = 3;
              pHVar3 = GetDlgItem(param_1,0x418);
              SetFocus(pHVar3);
              pHVar3 = GetDlgItem(param_1,0x415);
              SendMessageW(pHVar3,0xf4,0,1);
              DAT_402fc348 = FUN_402de0c4(DAT_402f8948);
            }
            goto LAB_402df8c8;
          }
          iVar2 = FUN_402df18c(param_1);
          if (iVar2 == 0) goto switchD_402df714_caseD_419;
          pWVar14 = (LPCWSTR)0x44d;
          if (0x1df < DAT_402fc350) {
            pWVar14 = (LPCWSTR)0x44c;
          }
          pHVar4 = FindResourceW(DAT_402fc3c4,pWVar14,(LPCWSTR)0x5);
          pDVar5 = LoadResource(DAT_402fc3c4,pHVar4);
          DialogBoxIndirectParamW(DAT_402fc3c4,pDVar5,param_1,FUN_402deb2c,(LPARAM)DAT_402f894c);
          pHVar3 = GetDlgItem(param_1,0x413);
          SetFocus(pHVar3);
          goto LAB_402dfd84;
        }
        IVar6 = 0;
      }
      EndDialog(param_1,IVar6);
      goto switchD_402df714_caseD_419;
    }
    if (uVar15 != 5) {
      if (((uVar15 != 9) && (uVar15 != 1)) && (uVar15 != 4)) goto switchD_402df714_caseD_419;
      GetDlgItemTextW(param_1,0x417,local_138,0x84);
      if ((local_138[0] != L'\0') &&
         (LVar1 = SendDlgItemMessageW(param_1,0x417,0x14c,0,(LPARAM)local_138), LVar1 == -1)) {
        FUN_402de494(param_1,local_138);
      }
      if (uVar15 == 4) {
        FUN_402de72c(param_1,(int)DAT_402f894c);
      }
    }
LAB_402dfd84:
    SetDlgItemTextW(param_1,0x40b,(LPCWSTR)((int)DAT_402f894c + 0x42));
    SetDlgItemTextW(param_1,0x406,(LPCWSTR)((int)DAT_402f894c + 0xc4));
    SetDlgItemTextW(param_1,0x407,(LPCWSTR)((int)DAT_402f894c + 0x146));
LAB_402dfdfc:
    FUN_402f41d8(local_30);
    return dwNewLong;
  }
  switch(uVar13) {
  case 0x418:
    if (uVar15 != 4) {
      if (uVar15 == 1) {
        PostMessageW(param_1,0x111,0x90418,0);
        break;
      }
      if (uVar15 != 9) break;
      WVar11 = SendMessageW(DAT_402f8948,0x147,0,0);
      if (WVar11 == 0xffffffff) {
        GetWindowTextW(DAT_402f8948,local_138,0x84);
        iVar2 = lstrcmpW((LPCWSTR)((int)DAT_402f894c + 4),local_138);
        if (iVar2 != 0) goto LAB_402df830;
      }
      else {
        LVar1 = SendMessageW(DAT_402f8948,0x150,WVar11,0);
        if (LVar1 != DAT_402fc348) goto LAB_402df8ec;
        GetWindowTextW(DAT_402f8948,local_138,0x84);
      }
      WVar11 = SendMessageW(DAT_402f8948,0x14c,0xffffffff,(LPARAM)local_138);
      if (WVar11 != 0xffffffff) {
        SendMessageW(DAT_402f8948,0x14e,WVar11,0);
      }
      break;
    }
LAB_402df830:
    if (DAT_402f8a58 != 0) goto LAB_402dfdfc;
    DAT_402f8a58 = 1;
    GetWindowTextW(DAT_402f8948,local_138,0x84);
    iVar2 = lstrcmpW((LPCWSTR)((int)DAT_402f894c + 4),local_138);
    if (iVar2 == 0) {
      DAT_402f8a58 = 0;
      goto LAB_402dfdfc;
    }
    if ((local_138[0] == L'\0') ||
       ((iVar2 = FUN_402de3f4(local_138), -1 < iVar2 && (iVar2 != DAT_402fc348)))) {
      WVar11 = SendMessageW(DAT_402f8948,0x14c,0xffffffff,(int)DAT_402f894c + 4);
      if (WVar11 != 0xffffffff) {
        SendMessageW(DAT_402f8948,0x14e,WVar11,0);
      }
      SetFocus(DAT_402f8948);
      DAT_402f8a58 = 0;
      DAT_402f893c = 1;
      break;
    }
    if (*(int *)((int)DAT_402f894c + 0x20c) != 1) {
      *(undefined4 *)((int)DAT_402f894c + 0x20c) = 2;
    }
    StringCchCopyNW((STRSAFE_LPWSTR)((int)DAT_402f894c + 4),0x1f,local_138,0x1e);
    DAT_402f8a58 = 0;
LAB_402df8c8:
    pvVar16 = (HANDLE)FUN_402de1c0(param_1,0x418,0);
    LVar1 = DAT_402fc348;
    if (pvVar16 != (HANDLE)0x0) goto LAB_402df904;
LAB_402df8ec:
    DAT_402fc348 = LVar1;
    FUN_402de06c(DAT_402fc348,(int *)&DAT_402f894c);
    if (DAT_402f894c == (void *)0x0) goto LAB_402df904;
    goto LAB_402dfc04;
  case 0x41a:
  case 0x41b:
    if (uVar15 != 0x200) break;
  case 0x421:
  case 0x422:
    FUN_402de92c(param_1,DAT_402f894c,auStack_140);
    break;
  case 0x420:
    FUN_402de92c(param_1,DAT_402f894c,auStack_140);
    FUN_402de494(param_1,(short *)((int)DAT_402f894c + 0x1de));
    goto LAB_402dfd84;
  case 0x423:
switchD_402df714_caseD_423:
    FUN_402deae4();
    DAT_402fc34c = (HWND)0x0;
    DestroyWindow(param_1);
    goto LAB_402dfdfc;
  case 0x424:
    iVar2 = FUN_402df18c(param_1);
    if (iVar2 != 0) {
      FUN_402de92c(param_1,DAT_402f894c,auStack_140);
      pHVar7 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
      pHVar7 = SetCursor(pHVar7);
      FUN_402ee2fc();
      SetCursor(pHVar7);
      FUN_402f41d8(local_30);
      return (HANDLE)0x1;
    }
  }
switchD_402df714_caseD_419:
  FUN_402f41d8(local_30);
  return (HANDLE)0x0;
}



/* 402dfee4 LineTranslateDialog */

/* Boundary evidence: original MIPS .pdata 402dfee4..402dffb7. Semantic name remains unreviewed. */

void LineTranslateDialog(HWND param_1,undefined4 param_2)

{
  int iVar1;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  LPCWSTR lpName;
  
                    /* 0xfee4  32  LineTranslateDialog */
  FUN_402eda64();
  DAT_402fc350 = GetSystemMetrics(0);
  iVar1 = GetSystemMetrics(1);
  DAT_402fc344 = iVar1 + -0x1a;
  lpName = (LPCWSTR)0x434;
  if (0x1df < DAT_402fc350) {
    lpName = (LPCWSTR)0x433;
  }
  DAT_402fc358 = param_2;
  hResInfo = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
  hDialogTemplate = LoadResource(DAT_402fc3c4,hResInfo);
  DialogBoxIndirectParamW(DAT_402fc3c4,hDialogTemplate,param_1,FUN_402df278,0);
  DAT_402fc34c = 0;
  FUN_402edb2c();
  return;
}



/* 402dffb8 FUN_402dffb8 */

/* Boundary evidence: original MIPS .pdata 402dffb8..402dfff3. Semantic name remains unreviewed. */

undefined4 FUN_402dffb8(undefined4 *param_1)

{
  LineTranslateDialog((HWND)*param_1,param_1[1]);
  EventModify(param_1[2],3);
  return 0;
}



/* 402dfff4 LineTranslateDialogExt */

/* Boundary evidence: original MIPS .pdata 402dfff4..402e00bb. Semantic name remains unreviewed. */

bool LineTranslateDialogExt
               (int param_1,uint param_2,undefined4 *param_3,undefined4 param_4,undefined4 *param_5)

{
  undefined4 *in_zero;
  undefined4 local_18;
  int local_14;
  HANDLE local_10;
  
                    /* 0xfff4  33  LineTranslateDialogExt */
  if (0xb < param_2) {
    local_14 = param_1 + 8;
    *param_5 = param_4;
    local_18 = *(undefined4 *)(param_1 + 4);
    *param_3 = 0;
    SetLastError(0);
    local_10 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"NetUI transdialog wrapper event");
    CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402dffb8,&local_18,0,(LPDWORD)0x0);
    WaitForSingleObject(local_10,0xffffffff);
    CloseHandle(local_10);
  }
  else {
    *in_zero = 0x57;
  }
  return 0xb < param_2;
}



/* 402e00bc FUN_402e00bc */

/* Boundary evidence: original MIPS .pdata 402e00bc..402e056f. Semantic name remains unreviewed. */

undefined4 FUN_402e00bc(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)&DAT_402f8a74);
  if (LVar1 == 1) {
    DAT_402f8a78 = GetModuleHandleW(L"coredll.dll");
    DAT_402f8a7c = LoadLibraryW(L"crypt32.dll");
    if (DAT_402f8a78 != (HMODULE)0x0) {
      if (DAT_402f8a7c == (HMODULE)0x0) {
        return 0;
      }
      DAT_402f8a88 = GetProcAddressW(DAT_402f8a78,L"CryptEnumProvidersW");
      DAT_402f8a8c = GetProcAddressW(DAT_402f8a78,L"CryptGetProvParam");
      DAT_402f8a80 = GetProcAddressW(DAT_402f8a78,L"CryptAcquireContextW");
      DAT_402f8a60 = GetProcAddressW(DAT_402f8a78,L"CryptReleaseContext");
      DAT_402f8a98 = GetProcAddressW(DAT_402f8a78,L"CryptGetUserKey");
      DAT_402f8a9c = GetProcAddressW(DAT_402f8a78,L"CryptGetKeyParam");
      DAT_402f8ab8 = GetProcAddressW(DAT_402f8a78,L"CryptDestroyKey");
      DAT_402f8a68 = GetProcAddressW(DAT_402f8a7c,L"CertCreateCertificateContext");
      DAT_402f8a84 = GetProcAddressW(DAT_402f8a7c,L"CertFreeCertificateContext");
      DAT_402f8abc = GetProcAddressW(DAT_402f8a7c,L"CertDuplicateCertificateContext");
      DAT_402f8a64 = GetProcAddressW(DAT_402f8a7c,L"CertOpenStore");
      DAT_402f8aa0 = GetProcAddressW(DAT_402f8a7c,L"CertCloseStore");
      DAT_402f8aa4 = GetProcAddressW(DAT_402f8a7c,L"CertEnumCertificatesInStore");
      DAT_402f8aac = GetProcAddressW(DAT_402f8a7c,L"CertFindCertificateInStore");
      DAT_402f8a70 = GetProcAddressW(DAT_402f8a7c,L"CertGetNameStringW");
      DAT_402f8ab4 = GetProcAddressW(DAT_402f8a7c,L"CertGetCertificateContextProperty");
      DAT_402f8ab0 = GetProcAddressW(DAT_402f8a7c,L"CertSetCertificateContextProperty");
      DAT_402f8aa8 = GetProcAddressW(DAT_402f8a7c,L"CertAddEncodedCertificateToStore");
      DAT_402f8a5c = GetProcAddressW(DAT_402f8a7c,L"CertAddCertificateContextToStore");
      DAT_402f8ac0 = GetProcAddressW(DAT_402f8a7c,L"CertCompareCertificateName");
      DAT_402f8a6c = GetProcAddressW(DAT_402f8a7c,L"CertNameToStrW");
      DAT_402f8a94 = GetProcAddressW(DAT_402f8a7c,L"CertGetEnhancedKeyUsage");
      DAT_402f8a90 = GetProcAddressW(DAT_402f8a7c,L"CryptFindOIDInfo");
      if (((((((DAT_402f8a80 == 0) || (DAT_402f8a60 == 0)) || (DAT_402f8a98 == 0)) ||
            (((DAT_402f8a88 == 0 || (DAT_402f8a8c == 0)) ||
             ((DAT_402f8a9c == 0 || ((DAT_402f8ab8 == 0 || (DAT_402f8a68 == 0)))))))) ||
           ((DAT_402f8a84 == 0 ||
            (((DAT_402f8abc == 0 || (DAT_402f8a64 == 0)) || (DAT_402f8aa0 == 0)))))) ||
          (((DAT_402f8aa4 == 0 || (DAT_402f8a70 == 0)) ||
           (((DAT_402f8a6c == 0 || ((DAT_402f8ab4 == 0 || (DAT_402f8ab0 == 0)))) ||
            (DAT_402f8a5c == 0)))))) ||
         (((DAT_402f8ac0 == 0 || (DAT_402f8a94 == 0)) || (DAT_402f8a90 == 0)))) {
        FreeLibrary(DAT_402f8a7c);
        DAT_402f8a7c = (HMODULE)0x0;
      }
    }
  }
  if (DAT_402f8a7c == (HMODULE)0x0) {
    return 0;
  }
  return 1;
}



/* 402e0570 FUN_402e0570 */

/* Boundary evidence: original MIPS .pdata 402e0570..402e05ef. Semantic name remains unreviewed. */

void FUN_402e0570(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)&DAT_402f8a74);
  if ((LVar1 == 0) && (DAT_402f8a7c != 0)) {
    FreeLibrary((HMODULE)DAT_402f8a7c);
    DAT_402f8abc = 0;
    DAT_402f8a84 = 0;
    DAT_402f8a70 = 0;
    DAT_402f8ab4 = 0;
    DAT_402f8a7c = 0;
  }
  return;
}



/* 402e05f0 FUN_402e05f0 */

/* Boundary evidence: original MIPS .pdata 402e05f0..402e06f3. Semantic name remains unreviewed. */

undefined4 FUN_402e05f0(HWND param_1)

{
  LRESULT LVar1;
  WPARAM wParam;
  UINT *pUVar2;
  UINT local_258 [2];
  tagRECT local_250;
  undefined4 local_240;
  undefined4 local_23c;
  int local_238;
  WCHAR *local_234;
  WPARAM local_22c;
  WCHAR aWStack_220 [256];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  local_258[0] = 0x43a;
  local_258[1] = 0x439;
  local_240 = 0xf;
  GetClientRect(param_1,&local_250);
  wParam = 0;
  pUVar2 = local_258;
  while( true ) {
    local_238 = local_250.right - local_250.left;
    local_22c = wParam;
    if (local_238 < 0) {
      local_238 = local_238 + 1;
    }
    local_238 = local_238 >> 1;
    local_234 = aWStack_220;
    local_23c = 0;
    LoadStringW(DAT_402fc3c4,*pUVar2,aWStack_220,0x100);
    LVar1 = SendMessageW(param_1,0x1061,wParam,(LPARAM)&local_240);
    if (LVar1 == -1) break;
    wParam = wParam + 1;
    pUVar2 = pUVar2 + 1;
    if (1 < (int)wParam) {
      FUN_402f41d8(local_20);
      return 1;
    }
  }
  FUN_402f41d8(local_20);
  return 0;
}



/* 402e06f4 FUN_402e06f4 */

/* Boundary evidence: original MIPS .pdata 402e06f4..402e08b7. Semantic name remains unreviewed. */

undefined4 FUN_402e06f4(HWND param_1,WPARAM *param_2)

{
  LRESULT LVar1;
  WPARAM WVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_290;
  WPARAM local_28c;
  undefined4 local_288;
  undefined4 local_284;
  undefined4 local_280;
  undefined1 *local_27c;
  undefined4 local_274;
  WPARAM local_270;
  undefined1 auStack_260 [8];
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined1 *local_24c;
  undefined1 auStack_230 [512];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  WVar2 = 0;
  local_284 = 0;
  local_280 = 0;
  if (0 < (int)param_2[1]) {
    iVar3 = 0;
    do {
      uVar4 = *(undefined4 *)(param_2[3] + iVar3);
      local_290 = 0xc;
      local_274 = 0;
      local_288 = 0;
      local_28c = WVar2;
      local_270 = WVar2;
      LVar1 = SendMessageW(param_1,0x104d,0,(LPARAM)&local_290);
      if (LVar1 == -1) break;
      local_290 = 1;
      (*DAT_402f8a70)(uVar4,5,0,0,auStack_230,0x100);
      local_27c = auStack_230;
      local_24c = auStack_230;
      local_288 = 0;
      local_258 = 0;
      SendMessageW(param_1,0x1074,WVar2,(LPARAM)auStack_260);
      (*DAT_402f8a70)(uVar4,4,1,0,auStack_230,0x100);
      local_24c = auStack_230;
      local_288 = 1;
      local_258 = 1;
      SendMessageW(param_1,0x1074,WVar2,(LPARAM)auStack_260);
      WVar2 = WVar2 + 1;
      iVar3 = iVar3 + 4;
    } while ((int)WVar2 < (int)param_2[1]);
  }
  WVar2 = *param_2;
  if ((-1 < (int)WVar2) && ((int)WVar2 < (int)param_2[1])) {
    local_250 = 2;
    local_254 = 2;
    SendMessageW(param_1,0x102b,WVar2,(LPARAM)auStack_260);
  }
  FUN_402f41d8(local_30);
  return 1;
}



/* 402e08b8 FUN_402e08b8 */

/* Boundary evidence: original MIPS .pdata 402e08b8..402e0ac7. Semantic name remains unreviewed. */

int FUN_402e08b8(HWND param_1,int param_2,short param_3,WPARAM *param_4)

{
  HWND hWnd;
  LONG LVar1;
  int iVar2;
  INT_PTR nResult;
  undefined4 *puVar3;
  undefined4 local_50;
  LRESULT local_4c;
  undefined4 local_48;
  int local_30;
  
  hWnd = GetDlgItem(param_1,0x500);
  if (param_2 == 0x4e) {
    return 1;
  }
  if (param_2 == 0x110) {
    SetWindowLongW(param_1,8,(LONG)param_4);
    SendMessageW(hWnd,0x1036,0,0x20);
    if (param_4 != (WPARAM *)0x0) {
      iVar2 = FUN_402e05f0(hWnd);
      if (iVar2 != 0) {
        FUN_402e06f4(hWnd,param_4);
        return iVar2;
      }
      return 0;
    }
  }
  else if (param_2 == 0x111) {
    if (param_3 == 1) {
      local_4c = -1;
      local_30 = 0;
      local_48 = 0;
      local_50 = 4;
      if ((hWnd != (HWND)0x0) && (local_4c = FUN_402d7608(hWnd,0xffffffff,2), local_4c != -1)) {
        SendMessageW(hWnd,0x104b,0,(LPARAM)&local_50);
      }
      puVar3 = (undefined4 *)GetWindowLongW(param_1,8);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = local_30;
      }
      nResult = 1;
    }
    else {
      if (param_3 != 2) {
        if (param_3 != 0x501) {
          return 0;
        }
        local_4c = 0xffffffff;
        local_30 = 0;
        local_48 = 0;
        local_50 = 4;
        local_4c = FUN_402d7608(hWnd,0xffffffff,2);
        SendMessageW(hWnd,0x104b,0,(LPARAM)&local_50);
        LVar1 = GetWindowLongW(param_1,8);
        if (LVar1 == 0) {
          return 0;
        }
        if (local_4c == -1) {
          return 0;
        }
        puVar3 = *(undefined4 **)(local_30 * 4 + *(int *)(LVar1 + 0xc));
        if (puVar3 == (undefined4 *)0x0) {
          return 0;
        }
        ShowCertificate(param_1,puVar3);
        return 0;
      }
      nResult = 0;
    }
    EndDialog(param_1,nResult);
  }
  return 0;
}



/* 402e0ac8 PickCertificate */

/* Boundary evidence: original MIPS .pdata 402e0ac8..402e0c07. Semantic name remains unreviewed. */

undefined4 PickCertificate(HWND param_1,LPARAM param_2)

{
  HRSRC pHVar1;
  undefined4 uVar2;
  HGLOBAL pvVar3;
  int iVar4;
  HCURSOR hCursor;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar5;
  
                    /* 0x10ac8  39  PickCertificate */
  IVar5 = -1;
  pHVar1 = FindResourceW(DAT_402fc3c4,(LPCWSTR)0x4ff,(LPCWSTR)0x5);
  if (((pHVar1 == (HRSRC)0x0) ||
      (pvVar3 = LoadResource(DAT_402fc3c4,pHVar1), pvVar3 == (HGLOBAL)0x0)) ||
     (DAT_402fc380 == (code *)0x0)) {
    uVar2 = 0;
  }
  else {
    (*DAT_402fc380)();
    iVar4 = FUN_402e00bc();
    if (iVar4 != 0) {
      hCursor = SetCursor((HCURSOR)0x0);
      pHVar1 = FindResourceW(DAT_402fc3c4,(LPCWSTR)0x4ff,(LPCWSTR)0x5);
      hDialogTemplate = LoadResource(DAT_402fc3c4,pHVar1);
      IVar5 = DialogBoxIndirectParamW(DAT_402fc3c4,hDialogTemplate,param_1,FUN_402e08b8,param_2);
      SetCursor(hCursor);
    }
    FUN_402e0570();
    uVar2 = 0;
    if (IVar5 != -1) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 402e0c08 FUN_402e0c08 */

/* Boundary evidence: original MIPS .pdata 402e0c08..402e0c7b. Semantic name remains unreviewed. */

void FUN_402e0c08(undefined4 *param_1)

{
  if (param_1[3] != 0) {
    (*DAT_402f8a84)();
  }
  if (param_1[2] != 0) {
    (*DAT_402f8aa0)(param_1[2],0);
  }
  FUN_402e0570();
  if ((HLOCAL)*param_1 != (HLOCAL)0x0) {
    LocalFree((HLOCAL)*param_1);
  }
  return;
}



/* 402e0c7c FUN_402e0c7c */

/* Boundary evidence: original MIPS .pdata 402e0c7c..402e0d6b. Semantic name remains unreviewed. */

DWORD FUN_402e0c7c(undefined4 *param_1,void *param_2,uint param_3,uint param_4)

{
  undefined4 *_Dst;
  DWORD DVar1;
  
  DVar1 = 0;
  if (param_3 < 0x2c) {
    _Dst = LocalAlloc(0x40,0x2c);
    if (_Dst == (undefined4 *)0x0) {
LAB_402e0d00:
      DVar1 = GetLastError();
      goto LAB_402e0d3c;
    }
    *_Dst = 1;
    _Dst[1] = 0x2c;
    _Dst[2] = param_4 | 4;
  }
  else {
    _Dst = LocalAlloc(0x40,param_3);
    if (_Dst == (undefined4 *)0x0) goto LAB_402e0d00;
    memcpy(_Dst,param_2,param_3);
    _Dst[1] = param_3;
    *(undefined1 *)((int)_Dst + (param_3 - 2)) = 0;
    *(undefined1 *)((int)_Dst + (param_3 - 1)) = 0;
  }
  *param_1 = _Dst;
LAB_402e0d3c:
  LocalFree((HLOCAL)0x0);
  return DVar1;
}



/* 402e0d6c FUN_402e0d6c */

/* Boundary evidence: original MIPS .pdata 402e0d6c..402e0e27. Semantic name remains unreviewed. */

void FUN_402e0d6c(int *param_1)

{
  HWND hWnd;
  LRESULT LVar1;
  int iVar2;
  undefined4 local_10 [2];
  
  hWnd = GetDlgItem((HWND)param_1[4],0x505);
  LVar1 = SendMessageW(hWnd,0xf0,0,0);
  if (LVar1 == 1) {
    *(uint *)(*param_1 + 8) = *(uint *)(*param_1 + 8) & 0xfffffffd;
  }
  else {
    *(uint *)(*param_1 + 8) = *(uint *)(*param_1 + 8) | 2;
  }
  if (param_1[3] != 0) {
    local_10[0] = 0x14;
    iVar2 = (*DAT_402f8ab4)(param_1[3],3,*param_1 + 0x10,local_10);
    if (iVar2 != 0) {
      *(undefined4 *)(*param_1 + 0xc) = local_10[0];
    }
  }
  return;
}



/* 402e0e28 FUN_402e0e28 */

/* Boundary evidence: original MIPS .pdata 402e0e28..402e0f17. Semantic name remains unreviewed. */

void FUN_402e0e28(int param_1)

{
  uint uVar1;
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_402f65fc;
  uVar1 = (*DAT_402f8a70)(*(undefined4 *)(param_1 + 0xc),8,0,0,aWStack_220,0x104);
  if (uVar1 < 2) {
    (*DAT_402f8a70)(*(undefined4 *)(param_1 + 0xc),5,0,0,aWStack_220,0x104);
  }
  SetDlgItemTextW(*(HWND *)(param_1 + 0x10),0x507,aWStack_220);
  uVar1 = (*DAT_402f8a70)(*(undefined4 *)(param_1 + 0xc),5,1,0,aWStack_220,0x104);
  if (1 < uVar1) {
    SetDlgItemTextW(*(HWND *)(param_1 + 0x10),0x508,aWStack_220);
  }
  FUN_402f41d8(local_18);
  return;
}



/* 402e0f18 FUN_402e0f18 */

/* Boundary evidence: original MIPS .pdata 402e0f18..402e0fef. Semantic name remains unreviewed. */

LSTATUS FUN_402e0f18(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 *param_4)

{
  LSTATUS LVar1;
  HKEY local_28;
  DWORD local_24;
  DWORD local_20;
  undefined4 local_1c;
  
  LVar1 = RegOpenKeyExW(param_1,param_2,0,0xf003f,&local_28);
  if (LVar1 == 0) {
    local_24 = 4;
    LVar1 = RegQueryValueExW(local_28,param_3,(LPDWORD)0x0,&local_20,(LPBYTE)&local_1c,&local_24);
    if (LVar1 == 0) {
      if (local_20 == 4) {
        *param_4 = local_1c;
      }
      else {
        LVar1 = 0x3f1;
      }
    }
    RegCloseKey(local_28);
  }
  return LVar1;
}



/* 402e0ff0 FUN_402e0ff0 */

/* Boundary evidence: original MIPS .pdata 402e0ff0..402e10eb. Semantic name remains unreviewed. */

void FUN_402e0ff0(undefined4 *param_1)

{
  int local_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [2];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  param_1[5] = 0xc;
  param_1[4] = 0x2c;
  param_1[1] = 0x48;
  *param_1 = 1;
  param_1[3] = 1;
  local_38[0] = 1;
  local_28[0] = 0x1a;
  FUN_402e0f18((HKEY)0x80000002,L"Comm\\EAP\\Extension\\25",L"ValidateServerCert",local_38);
  FUN_402e0f18((HKEY)0x80000002,L"Comm\\EAP\\Extension\\25",L"TunneledExtensionType",local_28);
  if (local_38[0] == 0) {
    param_1[5] = param_1[5] | 2;
  }
  param_1[2] = 1;
  local_30 = 1;
  local_2c = 0x10;
  memcpy((void *)((int)param_1 + param_1[4] + 0xc),&local_30,0x10);
  FUN_402f41d8(local_20);
  return;
}



/* 402e10ec RasEapInvokeInteractiveUI */

/* Boundary evidence: original MIPS .pdata 402e10ec..402e12a7. Semantic name remains unreviewed. */

undefined4
RasEapInvokeInteractiveUI
          (int param_1,HWND param_2,int *param_3,undefined4 param_4,undefined4 *param_5,
          undefined4 *param_6)

{
  undefined4 *puVar1;
  UINT uID;
  int iVar2;
  undefined4 uVar3;
  UINT uType;
  WCHAR local_198 [80];
  WCHAR local_f8 [100];
  uint local_30;
  
                    /* 0x110ec  42  RasEapInvokeInteractiveUI */
  local_30 = DAT_402f65fc;
  uVar3 = 0x32;
  if (param_1 == 0xd) {
    *param_5 = 0;
    *param_6 = 0;
    if (((param_3 != (int *)0x0) && (*param_3 == 1)) && (0x17 < (uint)param_3[1])) {
      uType = 0;
      uVar3 = 0;
      if (param_3[3] == 1) {
        if ((param_3[2] & 4U) != 0) {
          uType = 4;
        }
        iVar2 = param_3[4];
        if (iVar2 == -0x7ff6fcdb) {
          uID = 0x1807;
        }
        else if (iVar2 == -0x7ff6fcd9) {
          uID = 0x1809;
        }
        else if (iVar2 == -0x7ff6fcd8) {
          uID = 0x1808;
        }
        else {
          uID = 0x180a;
        }
        local_f8[0] = L'\0';
        local_198[0] = L'\0';
        LoadStringW(DAT_402fc3c4,uID,local_f8,100);
        LoadStringW(DAT_402fc3c4,0x1806,local_198,0x50);
        iVar2 = MessageBoxW(param_2,local_f8,local_198,uType);
        if (((param_3[2] & 4U) != 0) &&
           (puVar1 = LocalAlloc(0x40,0x10), puVar1 != (undefined4 *)0x0)) {
          puVar1[1] = 0x10;
          *puVar1 = 1;
          puVar1[3] = iVar2;
          *param_5 = puVar1;
          *param_6 = puVar1[1];
        }
      }
      else if (param_3[3] != 2) {
        uVar3 = 0x32;
      }
    }
  }
  FUN_402f41d8(local_30);
  return uVar3;
}



/* 402e12a8 RasEapFreeMemory */

/* Boundary evidence: original MIPS .pdata 402e12a8..402e12c7. Semantic name remains unreviewed. */

undefined4 RasEapFreeMemory(HLOCAL param_1)

{
                    /* 0x112a8  40  RasEapFreeMemory */
  LocalFree(param_1);
  return 0;
}



/* 402e12c8 FUN_402e12c8 */

/* Boundary evidence: original MIPS .pdata 402e12c8..402e140f. Semantic name remains unreviewed. */

undefined4 FUN_402e12c8(int *param_1,HWND param_2)

{
  HWND pHVar1;
  int iVar2;
  uint uVar3;
  int local_18;
  int local_14;
  
  param_1[4] = (int)param_2;
  uVar3 = *(uint *)(*param_1 + 8);
  pHVar1 = GetDlgItem(param_2,0x505);
  SendMessageW(pHVar1,0xf1,(uint)((uVar3 & 2) == 0),0);
  if (param_1[1] != 0) {
    iVar2 = (*DAT_402f8a64)(10,1,0,0x10000,&DAT_402d22bc);
    param_1[2] = iVar2;
    if (iVar2 != 0) {
      local_14 = *param_1;
      if ((*(uint *)(local_14 + 8) & 8) != 0) {
        pHVar1 = GetDlgItem((HWND)param_1[4],0x506);
        EnableWindow(pHVar1,0);
        return 1;
      }
      local_18 = *(int *)(local_14 + 0xc);
      if (local_18 == 0) {
        return 1;
      }
      local_14 = local_14 + 0x10;
      iVar2 = (*DAT_402f8aac)(iVar2,1,0,0x10000,&local_18,0);
      param_1[3] = iVar2;
      if (iVar2 == 0) {
        return 1;
      }
      FUN_402e0e28((int)param_1);
      return 1;
    }
  }
  return 0;
}



/* 402e1410 FUN_402e1410 */

/* Boundary evidence: original MIPS .pdata 402e1410..402e1687. Semantic name remains unreviewed. */

undefined4 FUN_402e1410(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_b0;
  uint local_ac [2];
  undefined4 *local_a4;
  uint local_a0 [2];
  undefined4 local_98 [20];
  size_t local_48;
  undefined1 auStack_44 [20];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  uVar5 = 0;
  memset(local_ac,0,0xc);
  local_a4 = local_98;
  local_ac[0] = 0;
  local_b0 = 0;
  if (param_1[2] == 0) {
    FUN_402f41d8(local_30);
    uVar5 = 0;
  }
  else {
    iVar4 = 0;
    do {
      iVar4 = (*DAT_402f8aa4)(param_1[2],iVar4);
      if (iVar4 == 0) goto LAB_402e1558;
      local_a0[0] = 0x14;
      uVar2 = (*DAT_402f8abc)(iVar4);
      local_98[local_ac[0]] = uVar2;
      local_ac[0] = local_ac[0] + 1;
      (*DAT_402f8ab4)(iVar4,3,&local_48,local_a0);
      uVar1 = local_ac[0];
      if ((((local_a0[0] != 0) && (local_a0[0] == *(uint *)(*param_1 + 0xc))) &&
          (local_a0[0] < 0x15)) &&
         (iVar3 = memcmp(&local_48,(void *)(*param_1 + 0x10),local_a0[0]), iVar3 == 0)) {
        local_b0 = uVar1 - 1;
      }
    } while (uVar1 < 0x14);
    (*DAT_402f8a84)(iVar4);
LAB_402e1558:
    iVar4 = PickCertificate((HWND)param_1[4],(LPARAM)&local_b0);
    if ((iVar4 != 0) && (local_b0 < (int)local_ac[0])) {
      local_48 = 0x14;
      uVar2 = local_a4[local_b0];
      iVar4 = (*DAT_402f8ab4)(uVar2,3,auStack_44,&local_48);
      if (iVar4 != 0) {
        iVar3 = *param_1;
        iVar4 = memcmp(auStack_44,(void *)(iVar3 + 0x10),local_48);
        if (iVar4 != 0) {
          memcpy((void *)(iVar3 + 0xc),&local_48,0x18);
          if (param_1[3] != 0) {
            (*DAT_402f8a84)();
          }
          iVar4 = (*DAT_402f8abc)(uVar2);
          param_1[3] = iVar4;
          FUN_402e0e28((int)param_1);
          uVar5 = 1;
        }
      }
    }
    iVar4 = 0;
    if (0 < (int)local_ac[0]) {
      iVar3 = 0;
      do {
        (*DAT_402f8a84)(*(undefined4 *)((int)local_a4 + iVar3));
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 4;
      } while (iVar4 < (int)local_ac[0]);
    }
    FUN_402f41d8(local_30);
  }
  return uVar5;
}



/* 402e1688 FUN_402e1688 */

/* Boundary evidence: original MIPS .pdata 402e1688..402e17af. Semantic name remains unreviewed. */

undefined4 FUN_402e1688(HWND param_1,int param_2,short param_3,int *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  INT_PTR nResult;
  
  GetDlgItem(param_1,0x500);
  if (param_2 == 0x4e) {
    return 1;
  }
  if (param_2 == 0x110) {
    if (param_4 != (int *)0x0) {
      SetWindowLongW(param_1,8,(LONG)param_4);
      uVar2 = FUN_402e12c8(param_4,param_1);
      return uVar2;
    }
  }
  else if (param_2 == 0x111) {
    if (param_3 == 1) {
      piVar1 = (int *)GetWindowLongW(param_1,8);
      FUN_402e0d6c(piVar1);
      nResult = 1;
    }
    else {
      if (param_3 != 2) {
        if (param_3 != 0x506) {
          return 0;
        }
        piVar1 = (int *)GetWindowLongW(param_1,8);
        FUN_402e1410(piVar1);
        return 0;
      }
      nResult = 0;
    }
    EndDialog(param_1,nResult);
  }
  return 0;
}



/* 402e17b0 FUN_402e17b0 */

/* Boundary evidence: original MIPS .pdata 402e17b0..402e187f. Semantic name remains unreviewed. */

INT_PTR FUN_402e17b0(LPARAM param_1,HINSTANCE param_2,HWND param_3)

{
  int iVar1;
  HCURSOR hCursor;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar2;
  LPCWSTR lpName;
  
  iVar1 = GetSystemMetrics(0);
  hCursor = SetCursor((HCURSOR)0x0);
  lpName = (LPCWSTR)0x509;
  if (0x1df < iVar1) {
    lpName = (LPCWSTR)0x504;
  }
  hResInfo = FindResourceW(param_2,lpName,(LPCWSTR)0x5);
  hDialogTemplate = LoadResource(param_2,hResInfo);
  IVar2 = DialogBoxIndirectParamW(param_2,hDialogTemplate,param_3,FUN_402e1688,param_1);
  SetCursor(hCursor);
  return IVar2;
}



/* 402e1880 FUN_402e1880 */

/* Boundary evidence: original MIPS .pdata 402e1880..402e1a57. Semantic name remains unreviewed. */

DWORD FUN_402e1880(wchar_t *param_1,HWND param_2,undefined4 param_3,void *param_4,uint param_5,
                  undefined4 *param_6,SIZE_T *param_7)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  INT_PTR IVar3;
  HLOCAL _Dst;
  uint uVar4;
  SIZE_T uBytes;
  DWORD DVar5;
  void *_Src;
  int local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  *param_6 = 0;
  *param_7 = 0;
  puVar1 = operator_new(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    uVar2 = FUN_402e00bc();
    puVar1[1] = uVar2;
  }
  if (puVar1 == (undefined4 *)0x0) {
    DVar5 = 0xe;
  }
  else {
    uVar4 = 8;
    if (param_1 != (wchar_t *)0x19) {
      uVar4 = 0;
    }
    swprintf(awStack_230,0x402d22c4,param_1);
    local_238[0] = 1;
    FUN_402e0f18((HKEY)0x80000002,awStack_230,L"ValidateServerCert",local_238);
    if (local_238[0] == 0) {
      uVar4 = uVar4 | 2;
    }
    DVar5 = FUN_402e0c7c(puVar1,param_4,param_5,uVar4);
    if (DVar5 == 0) {
      IVar3 = FUN_402e17b0((LPARAM)puVar1,DAT_402fc3c4,param_2);
      if (IVar3 == 0) {
        DVar5 = 0x4c7;
      }
      else {
        _Src = (void *)*puVar1;
        if ((_Src != (void *)0x0) && (uBytes = *(SIZE_T *)((int)_Src + 4), uBytes != 0)) {
          _Dst = LocalAlloc(0,uBytes);
          *param_6 = _Dst;
          if (_Dst == (HLOCAL)0x0) {
            DVar5 = GetLastError();
          }
          else {
            memcpy(_Dst,_Src,uBytes);
            *param_7 = uBytes;
          }
        }
      }
    }
    FUN_402e0c08(puVar1);
    operator_delete(puVar1);
  }
  FUN_402f41d8(local_28);
  return DVar5;
}



/* 402e1a58 FUN_402e1a58 */

/* Boundary evidence: original MIPS .pdata 402e1a58..402e1c6f. Semantic name remains unreviewed. */

DWORD FUN_402e1a58(HWND param_1,undefined4 param_2,int *param_3,uint param_4,undefined4 *param_5,
                  SIZE_T *param_6)

{
  bool bVar1;
  void *_Src;
  DWORD DVar2;
  int *piVar3;
  uint uVar4;
  SIZE_T uBytes;
  uint uVar5;
  void *local_40;
  uint local_3c;
  void *local_38;
  SIZE_T *local_34;
  uint local_30;
  
  uVar5 = DAT_402f65fc;
  local_30 = DAT_402f65fc;
  *param_5 = 0;
  bVar1 = false;
  local_34 = param_6;
  local_40 = (void *)0x0;
  *param_6 = 0;
  if (((param_3 == (int *)0x0) || ((uint)param_3[1] < 0x38)) || (param_4 < (uint)param_3[1])) {
    param_3 = LocalAlloc(0x40,0x4a);
    if (param_3 == (int *)0x0) {
      FUN_402f41d8(local_30);
      return 0xe;
    }
    bVar1 = true;
    FUN_402e0ff0(param_3);
  }
  else if (*param_3 != 1) {
    FUN_402f41d8(uVar5);
    return 0x32;
  }
  local_38 = (void *)((int)param_3 + param_3[4] + 0xc);
  uVar5 = (param_3[1] - param_3[4]) - 0xc;
  DVar2 = FUN_402e1880((wchar_t *)0x19,param_1,param_2,param_3 + 3,param_3[4],&local_40,&local_3c);
  _Src = local_40;
  if (DVar2 == 0) {
    if (((local_3c < 0x2c) || (uVar4 = *(uint *)((int)local_40 + 4), local_3c != uVar4)) ||
       ((0xffffff < uVar4 || (0xffffff < uVar5)))) {
      DVar2 = 0x54f;
    }
    else {
      uBytes = uVar4 + uVar5 + 0xc;
      piVar3 = LocalAlloc(0,uBytes);
      *piVar3 = *param_3;
      piVar3[1] = uBytes;
      piVar3[2] = param_3[2];
      memcpy(piVar3 + 3,_Src,local_3c);
      memcpy((void *)((int)piVar3 + local_3c + 0xc),local_38,uVar5);
      *param_5 = piVar3;
      *local_34 = uBytes;
    }
  }
  LocalFree(_Src);
  if (bVar1) {
    LocalFree(param_3);
  }
  FUN_402f41d8(local_30);
  return DVar2;
}



/* 402e1c70 RasEapInvokeConfigUI */

/* Boundary evidence: original MIPS .pdata 402e1c70..402e1d03. Semantic name remains unreviewed. */

DWORD RasEapInvokeConfigUI
                (int param_1,HWND param_2,undefined4 param_3,int *param_4,uint param_5,
                undefined4 *param_6,SIZE_T *param_7)

{
  DWORD DVar1;
  
                    /* 0x11c70  41  RasEapInvokeConfigUI */
  if (param_1 == 0xd) {
    DVar1 = FUN_402e1880((wchar_t *)0xd,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else if (param_1 == 0x19) {
    DVar1 = FUN_402e1a58(param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    DVar1 = 0x32;
  }
  return DVar1;
}



/* 402e1d04 FUN_402e1d04 */

/* Boundary evidence: original MIPS .pdata 402e1d04..402e1e17. Semantic name remains unreviewed. */

int FUN_402e1d04(HWND param_1,HINSTANCE param_2,UINT param_3,UINT param_4,UINT param_5)

{
  LPWSTR lpBuffer;
  int iVar1;
  int iVar2;
  
  if (param_2 == (HINSTANCE)0x0) {
    param_2 = DAT_402fc3c4;
  }
  lpBuffer = LocalAlloc(0,0x500);
  if (lpBuffer == (LPWSTR)0x0) {
    iVar2 = 2;
  }
  else {
    if (param_4 == 0) {
      param_4 = 2;
    }
    iVar2 = LoadStringW(DAT_402fc3c4,param_4,lpBuffer,0x80);
    iVar2 = iVar2 + 1;
    iVar1 = LoadStringW(param_2,param_5,lpBuffer + iVar2,0x280 - iVar2);
    iVar1 = iVar1 + iVar2 + 1;
    StringCchVPrintfW(lpBuffer + iVar1,0x280 - iVar1,lpBuffer + iVar2,&stack0x00000014);
    iVar2 = MessageBoxW(param_1,lpBuffer + iVar1,lpBuffer,param_3);
    LocalFree(lpBuffer);
  }
  return iVar2;
}



/* 402e1e18 UnregisterIPClass */

/* Boundary evidence: original MIPS .pdata 402e1e18..402e1e3b. Semantic name remains unreviewed. */

void UnregisterIPClass(HINSTANCE param_1)

{
                    /* 0x11e18  48  UnregisterIPClass */
  UnregisterClassW(L"RNA_IPAddress",param_1);
  return;
}



/* 402e1e3c FUN_402e1e3c */

/* Boundary evidence: original MIPS .pdata 402e1e3c..402e1efb. Semantic name remains unreviewed. */

void FUN_402e1e3c(undefined4 *param_1,WPARAM param_2,LPARAM param_3)

{
  uint uVar1;
  long lVar2;
  wchar_t local_20 [4];
  uint local_18;
  
  local_18 = DAT_402f65fc;
  SetFocus((HWND)*param_1);
  SendMessageW((HWND)*param_1,0xb1,param_2,param_3);
  local_20[0] = L'\x03';
  local_20[1] = L'\0';
  uVar1 = SendMessageW((HWND)*param_1,0xc4,0,(LPARAM)local_20);
  if ((uVar1 == 0) || (3 < uVar1)) {
    param_1[3] = 0;
  }
  else {
    local_20[uVar1] = L'\0';
    lVar2 = _wtol(local_20);
    param_1[3] = lVar2;
  }
  FUN_402f41d8(local_18);
  return;
}



/* 402e1efc FUN_402e1efc */

/* Boundary evidence: original MIPS .pdata 402e1efc..402e1ff7. Semantic name remains unreviewed. */

void FUN_402e1efc(int param_1,int param_2)

{
  WCHAR WVar1;
  uint uVar2;
  int iVar3;
  WCHAR *pWVar4;
  WCHAR *pWVar5;
  undefined4 *puVar6;
  WCHAR local_18 [4];
  uint local_10;
  
  local_10 = DAT_402f65fc;
  if ((*(uint *)(param_1 + 0xc) & 8) != 0) {
    puVar6 = (undefined4 *)((param_2 + 2) * 0x10 + param_1);
    local_18[0] = L'\x03';
    local_18[1] = L'\0';
    uVar2 = SendMessageW((HWND)*puVar6,0xc4,0,(LPARAM)local_18);
    if ((uVar2 != 0) && (uVar2 < 3)) {
      local_18[uVar2] = L'\0';
      pWVar4 = local_18 + 2;
      pWVar5 = local_18 + (uVar2 - 1);
      iVar3 = 2 - uVar2;
      do {
        WVar1 = *pWVar5;
        pWVar5 = pWVar5 + -1;
        *pWVar4 = WVar1;
        uVar2 = uVar2 - 1;
        pWVar4 = pWVar4 + -1;
      } while (uVar2 != 0);
      if (-1 < iVar3) {
        pWVar4 = local_18 + iVar3;
        do {
          *pWVar4 = L'0';
          iVar3 = iVar3 + -1;
          pWVar4 = pWVar4 + -1;
        } while (-1 < iVar3);
      }
      local_18[3] = 0;
      SetWindowTextW((HWND)*puVar6,local_18);
    }
  }
  FUN_402f41d8(local_10);
  return;
}



/* 402e1ff8 FUN_402e1ff8 */

/* Boundary evidence: original MIPS .pdata 402e1ff8..402e20db. Semantic name remains unreviewed. */

long FUN_402e1ff8(undefined4 *param_1)

{
  uint uVar1;
  size_t sVar2;
  long lVar3;
  WCHAR local_20;
  undefined1 auStack_1e [6];
  wchar_t local_18 [4];
  uint local_10;
  
  local_10 = DAT_402f65fc;
  local_20 = L'\0';
  memset(auStack_1e,0,6);
  local_18[0] = L'\x03';
  uVar1 = SendMessageW((HWND)*param_1,0xc4,0,(LPARAM)local_18);
  sVar2 = wcslen(local_18);
  LCMapStringW(0x800,0x400000,local_18,sVar2 + 1,&local_20,4);
  if ((uVar1 == 0) || (3 < uVar1)) {
    FUN_402f41d8(local_10);
    lVar3 = -1;
  }
  else {
    *(undefined2 *)(auStack_1e + uVar1 * 2 + -2) = 0;
    lVar3 = _wtol(&local_20);
    FUN_402f41d8(local_10);
  }
  return lVar3;
}



/* 402e20dc FUN_402e20dc */

/* Boundary evidence: original MIPS .pdata 402e20dc..402e229b. Semantic name remains unreviewed. */

undefined4 FUN_402e20dc(int param_1,int param_2)

{
  uint uVar1;
  long lVar2;
  HWND pHVar3;
  undefined4 *puVar4;
  wchar_t local_30 [4];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  puVar4 = (undefined4 *)((param_2 + 2) * 0x10 + param_1);
  local_30[0] = L'\x03';
  local_30[1] = L'\0';
  uVar1 = SendMessageW((HWND)*puVar4,0xc4,0,(LPARAM)local_30);
  if ((uVar1 != 0) && (uVar1 < 4)) {
    local_30[uVar1] = L'\0';
    lVar2 = _wtol(local_30);
    if ((lVar2 < (int)(uint)*(byte *)(puVar4 + 2)) ||
       ((int)(uint)*(byte *)((int)puVar4 + 9) < lVar2)) {
      pHVar3 = GetParent((HWND)*puVar4);
      if ((pHVar3 != (HWND)0x0) && (pHVar3 = GetParent(pHVar3), pHVar3 != (HWND)0x0)) {
        *(undefined4 *)(param_1 + 0x18) = 1;
        FUN_402e1d04(pHVar3,(HINSTANCE)0x0,0x30,0,3);
        *(undefined4 *)(param_1 + 0x18) = 0;
        wsprintfW(local_30,L"%d",puVar4[3]);
        SetWindowTextW((HWND)*puVar4,local_30);
        SendMessageW((HWND)*puVar4,0xb1,0,3);
        FUN_402f41d8(local_28);
        return 0;
      }
      lVar2 = puVar4[3];
    }
    wsprintfW(local_30,L"%d",lVar2);
    SetWindowTextW((HWND)*puVar4,local_30);
    if (uVar1 < 3) {
      FUN_402e1efc(param_1,param_2);
    }
  }
  FUN_402f41d8(local_28);
  return 1;
}



/* 402e229c FUN_402e229c */

/* Boundary evidence: original MIPS .pdata 402e229c..402e2307. Semantic name remains unreviewed. */

bool FUN_402e229c(int param_1,int param_2,int param_3,WPARAM param_4,LPARAM param_5)

{
  int iVar1;
  
  iVar1 = FUN_402e20dc(param_1,param_2);
  if (iVar1 != 0) {
    FUN_402e1e3c((undefined4 *)((param_3 + 2) * 0x10 + param_1),param_4,param_5);
  }
  return iVar1 != 0;
}



/* 402e2308 FUN_402e2308 */

/* Boundary evidence: original MIPS .pdata 402e2308..402e28d3. Semantic name remains unreviewed. */

LRESULT FUN_402e2308(HWND param_1,UINT param_2,uint param_3,LPARAM param_4)

{
  bool bVar1;
  HWND hWnd;
  LONG LVar2;
  uint uVar3;
  LRESULT LVar4;
  int iVar5;
  undefined3 extraout_var;
  uint uVar6;
  short extraout_var_00;
  HIMC pHVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  hWnd = GetParent(param_1);
  if (hWnd != (HWND)0x0) {
    LVar2 = GetWindowLongW(hWnd,0);
    uVar3 = GetWindowLongW(param_1,-0xc);
    if (*(HWND *)((uVar3 + 2) * 0x10 + LVar2) == param_1) {
      if (param_2 == 8) {
        FUN_402e1efc(LVar2,uVar3);
        if (DAT_402f8ac4 == 1) {
          pHVar7 = ImmGetContext(param_1);
          ImmNotifyIME(pHVar7,0x15,4,0);
        }
      }
      else {
        if (param_2 == 0x87) {
          return 0x81;
        }
        if (param_2 == 0x100) {
          if (param_3 == 0x23) {
            if (uVar3 < 3) {
              FUN_402e229c(LVar2,uVar3,3,3,3);
              return 0;
            }
          }
          else if (param_3 == 0x24) {
            if (uVar3 != 0) {
              FUN_402e229c(LVar2,uVar3,0,0,0);
              return 0;
            }
          }
          else if ((0x24 < param_3) && (param_3 < 0x29)) {
            GetKeyState(0x11);
            if (extraout_var_00 < 0) {
              if (((param_3 == 0x25) || (param_3 == 0x26)) && (uVar3 != 0)) {
                FUN_402e229c(LVar2,uVar3,uVar3 - 1,0,3);
                return 0;
              }
              if (((param_3 == 0x27) || (param_3 == 0x28)) && (uVar3 < 3)) {
                FUN_402e229c(LVar2,uVar3,uVar3 + 1,0,3);
                return 0;
              }
            }
            else {
              uVar6 = SendMessageW(param_1,0xb0,0,0);
              uVar8 = uVar6 & 0xffff;
              if (uVar8 == uVar6 >> 0x10) {
                if (((param_3 == 0x25) || (param_3 == 0x26)) && ((uVar8 == 0 && (uVar3 != 0)))) {
                  FUN_402e229c(LVar2,uVar3,uVar3 - 1,3,3);
                  return 0;
                }
                if ((((param_3 == 0x27) || (param_3 == 0x28)) && (uVar3 < 3)) &&
                   (uVar6 = SendMessageW(param_1,0xc1,0,0), uVar6 <= uVar8)) {
                  FUN_402e229c(LVar2,uVar3,uVar3 + 1,0,0);
                  return 0;
                }
              }
              if (param_3 == 0x26) {
                param_3 = 0x25;
              }
              else if (param_3 == 0x28) {
                param_3 = 0x27;
              }
            }
          }
        }
        else if (param_2 == 0x102) {
          if ((0x2f < param_3) && (param_3 < 0x3a)) {
            CallWindowProcW(*(WNDPROC *)(uVar3 * 0x10 + LVar2 + 0x24),param_1,0x102,param_3,param_4)
            ;
            LVar4 = SendMessageW(param_1,0xb0,0,0);
            if (LVar4 != 0x30003) {
              return LVar4;
            }
            iVar5 = FUN_402e20dc(LVar2,uVar3);
            if (iVar5 == 0) {
              return 0x30003;
            }
            if (2 < uVar3) {
              return 0x30003;
            }
            FUN_402e1e3c((undefined4 *)((uVar3 + 3) * 0x10 + LVar2),0,3);
            return 0x30003;
          }
          if ((param_3 == 0x2e) || (param_3 == 0x20)) {
            uVar6 = SendMessageW(param_1,0xb0,0,0);
            if (uVar6 == 0) {
              return 0;
            }
            if (uVar6 >> 0x10 != (uVar6 & 0xffff)) {
              return 0;
            }
            iVar5 = FUN_402e20dc(LVar2,uVar3);
            if (iVar5 == 0) {
              return 0;
            }
            if (uVar3 < 3) {
              FUN_402e1e3c((undefined4 *)((uVar3 + 3) * 0x10 + LVar2),0,3);
              return 0;
            }
LAB_402e25e8:
            MessageBeep(0xffffffff);
            return 0;
          }
          if (param_3 == 8) {
            if ((uVar3 != 0) && (LVar4 = SendMessageW(param_1,0xb0,0,0), LVar4 == 0)) {
              bVar1 = FUN_402e229c(LVar2,uVar3,uVar3 - 1,3,3);
              if (CONCAT31(extraout_var,bVar1) == 0) {
                return 0;
              }
              puVar9 = (undefined4 *)((uVar3 + 1) * 0x10 + LVar2);
              LVar4 = SendMessageW((HWND)*puVar9,0xc1,0,0);
              if (LVar4 != 0) {
                SendMessageW((HWND)*puVar9,0x102,8,param_4);
                return 0;
              }
              return 0;
            }
          }
          else if (0x20 < param_3) goto LAB_402e25e8;
        }
        else if (param_2 == 0x10d) {
          DAT_402f8ac4 = 1;
        }
        else if (param_2 == 0x10e) {
          DAT_402f8ac4 = 0;
        }
        else if (param_2 == 0x302) {
          LVar4 = CallWindowProcW(*(WNDPROC *)(uVar3 * 0x10 + LVar2 + 0x24),param_1,0x302,param_3,
                                  param_4);
          FUN_402e20dc(LVar2,uVar3);
          return LVar4;
        }
      }
      LVar4 = CallWindowProcW(*(WNDPROC *)(uVar3 * 0x10 + LVar2 + 0x24),param_1,param_2,param_3,
                              param_4);
      return LVar4;
    }
  }
  return 0;
}



/* 402e28d4 FUN_402e28d4 */

/* Boundary evidence: original MIPS .pdata 402e28d4..402e3137. Semantic name remains unreviewed. */

LRESULT FUN_402e28d4(HWND param_1,uint param_2,uint param_3,int *param_4)

{
  LONG LVar1;
  DWORD DVar2;
  HBRUSH h;
  HGDIOBJ h_00;
  HPEN h_01;
  HGDIOBJ h_02;
  uint uVar3;
  HLOCAL hMem;
  int *dwNewLong;
  HDC hdc;
  HWND pHVar4;
  long lVar5;
  int iVar6;
  COLORREF color;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  LRESULT LVar11;
  int iVar12;
  uint uVar13;
  HMENU hMenu;
  tagSIZE local_90;
  tagRECT tStack_88;
  tagPAINTSTRUCT local_78;
  WCHAR aWStack_38 [4];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  LVar11 = 1;
  if (param_2 < 0x112) {
    if (param_2 == 0x111) {
      if (param_3 >> 0x10 == 0x100) {
        puVar10 = (undefined4 *)GetWindowLongW(param_1,0);
        if (puVar10[7] == 0) {
          puVar10[7] = 1;
          uVar3 = GetWindowLongW(param_1,-0xc);
          SendMessageW((HWND)*puVar10,0x111,uVar3 & 0xffff | 0x1000000,(LPARAM)param_1);
        }
      }
      else if ((param_3 >> 0x10 == 0x200) &&
              (puVar10 = (undefined4 *)GetWindowLongW(param_1,0), puVar10[6] == 0)) {
        pHVar4 = GetFocus();
        iVar12 = 0;
        puVar7 = puVar10 + 8;
        do {
          if ((HWND)*puVar7 == pHVar4) break;
          iVar12 = iVar12 + 1;
          puVar7 = puVar7 + 4;
        } while (iVar12 < 4);
        if (3 < iVar12) {
          uVar3 = GetWindowLongW(param_1,-0xc);
          SendMessageW((HWND)*puVar10,0x111,uVar3 & 0xffff | 0x2000000,(LPARAM)param_1);
          puVar10[7] = 0;
        }
      }
      goto LAB_402e30fc;
    }
    if (param_2 == 1) {
      dwNewLong = LocalAlloc(0x40,0x60);
      if (dwNewLong == (int *)0x0) {
        DestroyWindow(param_1);
      }
      else {
        dwNewLong[4] = 1;
        dwNewLong[5] = 0;
        dwNewLong[6] = 0;
        *dwNewLong = param_4[3];
        uVar3 = param_4[8];
        dwNewLong[3] = uVar3;
        if ((uVar3 & 2) == 0) {
          uVar13 = 1;
          if ((uVar3 & 4) == 0) {
            uVar13 = 0;
          }
        }
        else {
          uVar13 = 2;
        }
        hdc = GetDC(param_1);
        GetTextExtentExPointW(hdc,L".",1,0,(LPINT)0x0,(LPINT)0x0,&local_90);
        dwNewLong[2] = local_90.cx;
        ReleaseDC(param_1,hdc);
        iVar12 = 2;
        hMenu = (HMENU)0x0;
        piVar8 = dwNewLong + 8;
        dwNewLong[1] = (param_4[5] + dwNewLong[2] * -3) - 4U >> 2;
        do {
          *(undefined1 *)(piVar8 + 2) = 0;
          *(undefined1 *)((int)piVar8 + 9) = 0xff;
          pHVar4 = CreateWindowExW(0,L"Edit",(LPCWSTR)0x0,uVar13 | 0x50002000,iVar12,2,dwNewLong[1],
                                   param_4[4] + -4,param_1,hMenu,(HINSTANCE)param_4[1],(LPVOID)0x0);
          *piVar8 = (int)pHVar4;
          SendMessageW(pHVar4,0xc5,3,0);
          LVar1 = GetWindowLongW((HWND)*piVar8,-4);
          piVar8[1] = LVar1;
          SetWindowLongW((HWND)*piVar8,-4,0x402e2308);
          hMenu = (HMENU)((int)&hMenu->unused + 1);
          iVar12 = dwNewLong[2] + dwNewLong[1] + iVar12;
          piVar8 = piVar8 + 4;
        } while ((int)hMenu < 4);
        SetWindowLongW(param_1,0,(LONG)dwNewLong);
        LVar11 = 1;
      }
      goto LAB_402e30fc;
    }
    if (param_2 == 2) {
      hMem = (HLOCAL)GetWindowLongW(param_1,0);
      puVar10 = (undefined4 *)((int)hMem + 0x20);
      iVar12 = 4;
      do {
        SetWindowLongW((HWND)*puVar10,-4,puVar10[1]);
        iVar12 = iVar12 + -1;
        puVar10 = puVar10 + 4;
      } while (iVar12 != 0);
      LocalFree(hMem);
      goto LAB_402e30fc;
    }
    if (param_2 == 7) {
      LVar1 = GetWindowLongW(param_1,0);
      puVar10 = (undefined4 *)(LVar1 + 0x20);
LAB_402e2bf0:
      FUN_402e1e3c(puVar10,0,3);
      goto LAB_402e30fc;
    }
    if (param_2 == 10) {
      LVar1 = GetWindowLongW(param_1,0);
      *(uint *)(LVar1 + 0x10) = param_3;
      puVar10 = (undefined4 *)(LVar1 + 0x20);
      iVar12 = 4;
      do {
        EnableWindow((HWND)*puVar10,param_3);
        iVar12 = iVar12 + -1;
        puVar10 = puVar10 + 4;
      } while (iVar12 != 0);
      if ((*(uint *)(LVar1 + 0xc) & 0x10000) != 0) {
        uVar3 = GetWindowLongW(param_1,-0x10);
        if (param_3 == 0) {
          uVar3 = uVar3 & 0xfffeffff;
        }
        else {
          uVar3 = uVar3 | 0x10000;
        }
        SetWindowLongW(param_1,-0x10,uVar3);
      }
      if (*(int *)(LVar1 + 0x14) != 0) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      goto LAB_402e30fc;
    }
    if (param_2 == 0xf) {
      BeginPaint(param_1,&local_78);
      GetClientRect(param_1,&tStack_88);
      LVar1 = GetWindowLongW(param_1,0);
      DVar2 = GetSysColor(0x40000005);
      h = CreateSolidBrush(DVar2);
      h_00 = SelectObject(local_78.hdc,h);
      DVar2 = GetSysColor(0x40000005);
      if (DVar2 == 0) {
        color = 0xffffff;
      }
      else {
        color = 0;
      }
      h_01 = CreatePen(0,1,color);
      h_02 = SelectObject(local_78.hdc,h_01);
      Rectangle(local_78.hdc,0,0,tStack_88.right,tStack_88.bottom);
      SelectObject(local_78.hdc,h_00);
      DeleteObject(h);
      SelectObject(local_78.hdc,h_02);
      DeleteObject(h_01);
      if (*(int *)(LVar1 + 0x10) == 0) {
        iVar12 = 0x40000011;
      }
      else {
        iVar12 = 0x40000008;
      }
      DVar2 = GetSysColor(iVar12);
      if (DVar2 != 0) {
        SetTextColor(local_78.hdc,DVar2);
      }
      DVar2 = GetSysColor(0x40000005);
      SetBkColor(local_78.hdc,DVar2);
      iVar12 = *(int *)(LVar1 + 4) + 2;
      iVar9 = 3;
      do {
        ExtTextOutW(local_78.hdc,iVar12,2,0,(RECT *)0x0,L".",1,(INT *)0x0);
        iVar9 = iVar9 + -1;
        iVar12 = *(int *)(LVar1 + 8) + *(int *)(LVar1 + 4) + iVar12;
      } while (iVar9 != 0);
      *(undefined4 *)(LVar1 + 0x14) = 1;
      EndPaint(param_1,&local_78);
      goto LAB_402e30fc;
    }
    if (param_2 == 0x30) {
      LVar1 = GetWindowLongW(param_1,0);
      puVar10 = (undefined4 *)(LVar1 + 0x20);
      iVar12 = 4;
      do {
        SendMessageW((HWND)*puVar10,0x30,param_3,(LPARAM)param_4);
        iVar12 = iVar12 + -1;
        puVar10 = puVar10 + 4;
      } while (iVar12 != 0);
      goto LAB_402e30fc;
    }
  }
  else {
    if (param_2 == 0x201) {
      SetFocus(param_1);
      goto LAB_402e30fc;
    }
    if (param_2 == 0x464) {
      LVar1 = GetWindowLongW(param_1,0);
      puVar10 = (undefined4 *)(LVar1 + 0x20);
      iVar12 = 4;
      do {
        SetWindowTextW((HWND)*puVar10,L"");
        iVar12 = iVar12 + -1;
        puVar10 = puVar10 + 4;
      } while (iVar12 != 0);
      goto LAB_402e30fc;
    }
    if (param_2 == 0x465) {
      LVar1 = GetWindowLongW(param_1,0);
      puVar10 = (undefined4 *)(LVar1 + 0x20);
      iVar12 = 4;
      do {
        wsprintfW(aWStack_38,L"%d",(uint)param_4 >> 0x18);
        SetWindowTextW((HWND)*puVar10,aWStack_38);
        param_4 = (int *)((int)param_4 << 8);
        iVar12 = iVar12 + -1;
        puVar10 = puVar10 + 4;
      } while (iVar12 != 0);
      goto LAB_402e30fc;
    }
    if (param_2 == 0x466) {
      LVar1 = GetWindowLongW(param_1,0);
      LVar11 = 0;
      iVar12 = 0;
      puVar10 = (undefined4 *)(LVar1 + 0x20);
      iVar9 = 4;
      do {
        iVar6 = FUN_402e1ff8(puVar10);
        if (iVar6 == -1) {
          iVar6 = 0;
        }
        else {
          LVar11 = LVar11 + 1;
        }
        iVar12 = iVar12 * 0x100 + iVar6;
        iVar9 = iVar9 + -1;
        puVar10 = puVar10 + 4;
      } while (iVar9 != 0);
      *param_4 = iVar12;
      goto LAB_402e30fc;
    }
    if (param_2 == 0x467) {
      if (param_3 < 4) {
        LVar1 = GetWindowLongW(param_1,0);
        iVar12 = param_3 * 0x10 + LVar1;
        *(char *)(iVar12 + 0x28) = (char)param_4;
        *(char *)(iVar12 + 0x29) = (char)((uint)param_4 >> 8);
      }
      goto LAB_402e30fc;
    }
    if (param_2 == 0x468) {
      LVar1 = GetWindowLongW(param_1,0);
      if (3 < param_3) {
        param_3 = 0;
        puVar10 = (undefined4 *)(LVar1 + 0x20);
        do {
          lVar5 = FUN_402e1ff8(puVar10);
          if (lVar5 == -1) break;
          param_3 = param_3 + 1;
          puVar10 = puVar10 + 4;
        } while (param_3 < 4);
        if (3 < param_3) {
          param_3 = 0;
        }
      }
      puVar10 = (undefined4 *)((param_3 + 2) * 0x10 + LVar1);
      goto LAB_402e2bf0;
    }
  }
  LVar11 = DefWindowProcW(param_1,param_2,param_3,(LPARAM)param_4);
LAB_402e30fc:
  FUN_402f41d8(local_30);
  return LVar11;
}



/* 402e3138 RegisterIPClass */

/* Boundary evidence: original MIPS .pdata 402e3138..402e319b. Semantic name remains unreviewed. */

void RegisterIPClass(HINSTANCE param_1)

{
  WNDCLASSW local_30;
  
                    /* 0x13138  43  RegisterIPClass */
  local_30.style = 8;
  local_30.lpszClassName = L"RNA_IPAddress";
  local_30.hCursor = (HCURSOR)0x0;
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.lpfnWndProc = FUN_402e28d4;
  local_30.hIcon = (HICON)0x0;
  local_30.cbWndExtra = 4;
  local_30.cbClsExtra = 0;
  local_30.hbrBackground = (HBRUSH)0x40000006;
  local_30.hInstance = param_1;
  RegisterClassW(&local_30);
  return;
}



/* 402e319c FUN_402e319c */

/* Boundary evidence: original MIPS .pdata 402e319c..402e327f. Semantic name remains unreviewed. */

undefined4 * FUN_402e319c(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = &DAT_402f8ccc;
  if (DAT_402f8cc8 == 0) {
    iVar4 = 0;
    uVar3 = 0;
    do {
      iVar1 = LoadStringW(DAT_402fc3c4,*(UINT *)((int)&DAT_402d233c + uVar3),
                          (LPWSTR)(&DAT_402f8d54 + iVar4 * 2),0x1000 - iVar4);
      *(undefined2 *)(&DAT_402f8d54 + (iVar1 + iVar4) * 2) = 0;
      uVar3 = uVar3 + 4;
      *puVar2 = &DAT_402f8d54 + iVar4 * 2;
      iVar4 = iVar1 + iVar4 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 < 0x88);
    DAT_402f8cc8 = 1;
  }
  return &DAT_402f8ccc;
}



/* 402e3280 FUN_402e3280 */

/* Boundary evidence: original MIPS .pdata 402e3280..402e34f7. Semantic name remains unreviewed. */

LPWSTR FUN_402e3280(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  uint *hMem;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  LPWSTR lpBuffer;
  LPWSTR _Dest;
  uint uVar6;
  uint cchBufferMax;
  SIZE_T local_30 [2];
  
  cchBufferMax = 0x100;
  bVar1 = false;
  iVar2 = (*DAT_402f8a94)(param_1,0,0,local_30);
  if ((iVar2 == 0) || (hMem = LocalAlloc(0,local_30[0]), hMem == (uint *)0x0)) {
    return (LPWSTR)0x0;
  }
  iVar2 = (*DAT_402f8a94)(param_1,0,hMem,local_30);
  if (iVar2 != 0) {
    if ((*hMem == 0) && (DVar3 = GetLastError(), DVar3 == 0x80092004)) {
      bVar1 = true;
    }
    uVar6 = 0;
    cchBufferMax = 1;
    if (*hMem != 0) {
      iVar2 = 0;
      do {
        iVar4 = (*DAT_402f8a90)(1,*(undefined4 *)(hMem[1] + iVar2),7);
        if (iVar4 == 0) {
          sVar5 = strlen(*(char **)(hMem[1] + iVar2));
        }
        else {
          sVar5 = wcslen(*(wchar_t **)(iVar4 + 8));
        }
        cchBufferMax = sVar5 + cchBufferMax + 2;
        uVar6 = uVar6 + 1;
        iVar2 = iVar2 + 4;
      } while (uVar6 < *hMem);
    }
    if (bVar1) {
      cchBufferMax = 0x100;
    }
    if (0x7fffffff < cchBufferMax) {
      uVar6 = 0xffffffff;
      goto LAB_402e33e8;
    }
  }
  uVar6 = cchBufferMax << 1;
LAB_402e33e8:
  lpBuffer = operator_new(uVar6);
  if (lpBuffer != (LPWSTR)0x0) {
    *lpBuffer = L'\0';
    if (bVar1) {
      LoadStringW(DAT_402fc3c4,0x440,lpBuffer,cchBufferMax);
    }
    else {
      uVar6 = 0;
      if (*hMem != 0) {
        iVar2 = 0;
        _Dest = lpBuffer;
        do {
          iVar4 = (*DAT_402f8a90)(1,*(undefined4 *)(hMem[1] + iVar2),7);
          if (iVar4 == 0) {
            mbstowcs(_Dest,*(char **)(hMem[1] + iVar2),
                     cchBufferMax - ((int)_Dest - (int)lpBuffer >> 1));
          }
          else {
            wcscpy(_Dest,*(wchar_t **)(iVar4 + 8));
          }
          sVar5 = wcslen(_Dest);
          wcscpy(_Dest + sVar5,L"\r\n");
          uVar6 = uVar6 + 1;
          _Dest = _Dest + sVar5 + 2;
          iVar2 = iVar2 + 4;
        } while (uVar6 < *hMem);
      }
    }
  }
  LocalFree(hMem);
  return lpBuffer;
}



/* 402e34f8 FUN_402e34f8 */

void FUN_402e34f8(byte *param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  
  puVar2 = PTR_u_0123456789ABCDEF_402f64bc;
  if (param_5 == 0) {
    iVar4 = 1;
  }
  else {
    param_1 = param_1 + param_2 + -1;
    iVar4 = -1;
  }
  iVar3 = 0;
  if (param_2 != 0) {
    puVar5 = (undefined2 *)(param_3 + 4);
    do {
      if ((uint)(param_4 - iVar3) < 3) break;
      puVar5[-2] = *(undefined2 *)(puVar2 + (uint)(*param_1 >> 4) * 2);
      bVar1 = *param_1;
      param_1 = param_1 + iVar4;
      puVar5[-1] = *(undefined2 *)(puVar2 + (bVar1 & 0xf) * 2);
      *puVar5 = 0x20;
      iVar3 = iVar3 + 3;
      param_2 = param_2 + -1;
      puVar5 = puVar5 + 3;
    } while (param_2 != 0);
    if (iVar3 != 0) {
      *(undefined2 *)(iVar3 * 2 + param_3) = 0;
    }
  }
  return;
}



/* 402e35a4 FUN_402e35a4 */

/* Boundary evidence: original MIPS .pdata 402e35a4..402e36a7. Semantic name remains unreviewed. */

undefined4 FUN_402e35a4(HWND param_1,HWND param_2,int *param_3)

{
  HWND pHVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = *param_3;
  piVar4 = param_3;
  while (iVar3 != 0) {
    if (piVar4[2] == 0) {
      SendMessageW(param_2,0x180,0,*piVar4);
    }
    else {
      SetDlgItemTextW(param_1,piVar4[2],(LPCWSTR)piVar4[1]);
      pHVar1 = GetDlgItem(param_1,piVar4[2]);
      uVar2 = GetWindowLongW(pHVar1,-0x10);
      pHVar1 = GetDlgItem(param_1,piVar4[2]);
      SetWindowLongW(pHVar1,-0x10,uVar2 | 0x800);
    }
    iVar5 = iVar5 + 1;
    piVar4 = param_3 + iVar5 * 3;
    iVar3 = *piVar4;
  }
  SendMessageW(param_2,0x186,0,0);
  return 1;
}



/* 402e36a8 FUN_402e36a8 */

/* Boundary evidence: original MIPS .pdata 402e36a8..402e373f. Semantic name remains unreviewed. */

undefined4 FUN_402e36a8(HWND param_1,HWND param_2,int param_3)

{
  LRESULT LVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  LVar1 = SendMessageW(param_1,0x188,0,0);
  iVar3 = LVar1 + 1;
  if (iVar3 == -1) {
    iVar3 = 0;
  }
  piVar4 = (int *)(iVar3 * 0xc + param_3);
  if (*piVar4 != 0) {
    SetWindowTextW(param_2,(LPCWSTR)piVar4[1]);
    uVar2 = GetWindowLongW(param_2,-0x10);
    SetWindowLongW(param_2,-0x10,uVar2 | 0x800);
  }
  return 0;
}



/* 402e3740 FUN_402e3740 */

/* Boundary evidence: original MIPS .pdata 402e3740..402e38c3. Semantic name remains unreviewed. */

undefined4 FUN_402e3740(HWND param_1,int param_2,uint param_3,HWND param_4)

{
  LONG LVar1;
  HWND pHVar2;
  HWND pHVar3;
  INT_PTR nResult;
  uint uVar4;
  
  if (param_2 == 0x53) {
    return 1;
  }
  if (param_2 == 0x110) {
    SetWindowLongW(param_1,8,(LONG)param_4);
    pHVar2 = GetDlgItem(param_1,0x3ed);
    FUN_402e35a4(param_1,pHVar2,&param_4->unused);
    pHVar2 = GetDlgItem(param_1,0x3f3);
    pHVar3 = GetDlgItem(param_1,0x3ed);
    FUN_402e36a8(pHVar3,pHVar2,(int)param_4);
    return 1;
  }
  if (param_2 != 0x111) {
    return 0;
  }
  LVar1 = GetWindowLongW(param_1,8);
  uVar4 = param_3 & 0xffff;
  if (uVar4 == 1) {
LAB_402e3818:
    GetDlgItemTextW(param_1,0x515,&DAT_402f8ac8,0x100);
    nResult = 1;
  }
  else {
    if (uVar4 != 2) {
      if (uVar4 == 6) goto LAB_402e3818;
      if (uVar4 != 7) {
        if (uVar4 != 0x3ed) {
          return 1;
        }
        if (param_3 >> 0x10 == 1) {
          pHVar2 = GetDlgItem(param_1,0x3f3);
          FUN_402e36a8(param_4,pHVar2,LVar1);
          return 1;
        }
        return 1;
      }
    }
    nResult = 0;
  }
  EndDialog(param_1,nResult);
  return 1;
}



/* 402e38c4 FUN_402e38c4 */

undefined4 FUN_402e38c4(uint param_1,int param_2)

{
  if ((param_1 & 0x40) == 0) {
    if ((((param_1 & 1) != 0) || ((param_1 & 2) != 0)) || ((param_1 & 0x20000) != 0)) {
      return *(undefined4 *)(param_2 + 0x3c);
    }
    if ((((param_1 & 0x20) != 0) || ((param_1 & 0x400) != 0)) || ((param_1 & 0x10000) != 0)) {
      return *(undefined4 *)(param_2 + 0x48);
    }
    if ((param_1 & 4) != 0) {
      return *(undefined4 *)(param_2 + 0x50);
    }
    if ((param_1 & 0x10) != 0) {
      return *(undefined4 *)(param_2 + 0x28);
    }
    if ((((param_1 & 8) == 0) && ((param_1 & 0x80) == 0)) &&
       (((param_1 & 0x40000) == 0 && (((param_1 & 0x80000) == 0 && (param_1 == 0)))))) {
      return 0;
    }
  }
  return *(undefined4 *)(param_2 + 0x40);
}



/* 402e39ac FUN_402e39ac */

/* Boundary evidence: original MIPS .pdata 402e39ac..402e3a87. Semantic name remains unreviewed. */

undefined4 FUN_402e39ac(int param_1,uint param_2,undefined4 *param_3)

{
  LPWSTR pWVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_2 * 3 < 0x80000000) {
    uVar3 = param_2 * 6;
  }
  else {
    uVar3 = 0xffffffff;
  }
  pWVar1 = operator_new(uVar3);
  *param_3 = pWVar1;
  if (pWVar1 == (LPWSTR)0x0) {
    uVar2 = 0;
  }
  else {
    uVar3 = 0;
    if (param_2 != 0) {
      do {
        if (uVar3 != 0) {
          *pWVar1 = L':';
          pWVar1 = pWVar1 + 1;
        }
        wsprintfW(pWVar1,L"%02X",(uint)*(byte *)(uVar3 + param_1));
        uVar3 = uVar3 + 1;
        pWVar1 = pWVar1 + 2;
      } while (uVar3 < param_2);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 402e3a88 FUN_402e3a88 */

/* Boundary evidence: original MIPS .pdata 402e3a88..402e3bf7. Semantic name remains unreviewed. */

wchar_t * FUN_402e3a88(FILETIME *param_1)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  wchar_t *lpDateStr;
  size_t sVar4;
  uint uVar5;
  uint cchDate;
  SYSTEMTIME SStack_38;
  _SYSTEMTIME _Stack_28;
  
  BVar1 = FileTimeToSystemTime(param_1,&_Stack_28);
  if (BVar1 != 0) {
    memcpy(&SStack_38,&_Stack_28,0x10);
    iVar2 = GetDateFormatW(0x800,1,&SStack_38,(LPCWSTR)0x0,(LPWSTR)0x0,0);
    if ((0 < iVar2) &&
       (iVar3 = GetTimeFormatW(0x800,0,&SStack_38,(LPCWSTR)0x0,(LPWSTR)0x0,0), 0 < iVar3)) {
      cchDate = iVar3 + iVar2 + 8;
      if (cchDate < 0x80000000) {
        uVar5 = cchDate * 2;
      }
      else {
        uVar5 = 0xffffffff;
      }
      lpDateStr = operator_new(uVar5);
      if (lpDateStr != (wchar_t *)0x0) {
        iVar2 = GetDateFormatW(0x800,1,&SStack_38,(LPCWSTR)0x0,lpDateStr,cchDate);
        if (0 < iVar2) {
          wcscat(lpDateStr,L" ");
          sVar4 = wcslen(lpDateStr);
          iVar2 = GetTimeFormatW(0x800,0,&SStack_38,(LPCWSTR)0x0,lpDateStr + sVar4,cchDate - sVar4);
          if (0 < iVar2) {
            return lpDateStr;
          }
        }
        operator_delete(lpDateStr);
      }
    }
  }
  return (wchar_t *)0x0;
}



/* 402e3bf8 ShowCertificateEx */

/* Boundary evidence: original MIPS .pdata 402e3bf8..402e4733. Semantic name remains unreviewed. */

int ShowCertificateEx(HWND param_1,undefined4 *param_2,int param_3)

{
  HWND hWnd;
  int iVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  size_t sVar4;
  uint uVar5;
  wchar_t *pwVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  LPWSTR pWVar11;
  uint uVar12;
  wchar_t *pwVar13;
  int *piVar14;
  wchar_t *pwVar15;
  UINT UVar16;
  wchar_t *local_af0;
  uint local_aec;
  wchar_t *local_ae8;
  wchar_t *local_ae4;
  wchar_t *local_ae0;
  wchar_t *local_adc;
  wchar_t *local_ad8;
  wchar_t *local_ad4;
  LPCWSTR local_ad0;
  wchar_t *local_acc;
  HWND local_ac8;
  undefined2 *local_ac4;
  wchar_t *local_ac0 [60];
  WCHAR *local_9d0;
  uint local_9cc;
  undefined4 local_9c8;
  WCHAR aWStack_9c0 [100];
  WCHAR aWStack_8f8 [100];
  wchar_t local_830 [256];
  WCHAR local_630;
  undefined1 auStack_62e [510];
  WCHAR local_430;
  undefined1 auStack_42e [510];
  wchar_t awStack_230 [256];
  uint local_30;
  
                    /* 0x13bf8  46  ShowCertificateEx */
  local_30 = DAT_402f65fc;
  local_ac8 = param_1;
  iVar1 = GetSystemMetrics(0);
  if (iVar1 < 0x1e0) {
    local_ad0 = (LPCWSTR)0x51e;
  }
  else {
    local_ad0 = (LPCWSTR)0x515;
  }
  pwVar13 = (wchar_t *)0x0;
  pwVar15 = (wchar_t *)0x0;
  local_af0 = (wchar_t *)0x0;
  local_ae8 = (wchar_t *)0x0;
  local_ad8 = (wchar_t *)0x0;
  UVar16 = 0x736;
  local_ae0 = (wchar_t *)0x0;
  local_adc = (wchar_t *)0x0;
  pWVar11 = (LPWSTR)0x0;
  local_ad4 = (wchar_t *)0x0;
  local_ae4 = (wchar_t *)0x0;
  local_acc = (wchar_t *)0x0;
  iVar1 = FUN_402e00bc();
  if (iVar1 == 0) {
    FUN_402f41d8(local_30);
    iVar1 = 0;
  }
  else {
    iVar10 = param_2[3];
    pwVar6 = (wchar_t *)0x0;
    if ((iVar10 != 0) && (puVar2 = FUN_402e319c(), pwVar6 = local_af0, puVar2 != (undefined4 *)0x0))
    {
      local_ad4 = FUN_402e3a88((FILETIME *)(iVar10 + 0x20));
      local_ae4 = FUN_402e3a88((FILETIME *)(iVar10 + 0x28));
      local_830[0] = L'\0';
      (*DAT_402f8a70)(param_2,5,0,0,local_830,0x100);
      local_ac0[1] = local_830;
      local_ac0[0] = local_830;
      local_ac0[2] = (wchar_t *)0x515;
      iVar1 = 1;
      if (param_3 != 0) {
        local_ac0[4] = (wchar_t *)FUN_402e38c4(*(uint *)(param_3 + 4),(int)puVar2);
        local_ac0[3] = (wchar_t *)puVar2[0xe];
        local_ac0[5] = (wchar_t *)0x0;
        if (local_ac0[4] == (wchar_t *)0x0) {
          local_ac0[4] = (wchar_t *)puVar2[0x10];
        }
        iVar1 = 2;
      }
      piVar14 = (int *)(iVar10 + 0x30);
      uVar12 = 0xffffffff;
      iVar9 = iVar1;
      if (*piVar14 != 0) {
        local_aec = (*DAT_402f8a6c)(*param_2,piVar14,0x28000001,0,0);
        uVar5 = local_aec << 1;
        if (0x7fffffff < local_aec) {
          uVar5 = uVar12;
        }
        local_af0 = operator_new(uVar5);
        if (local_af0 != (wchar_t *)0x0) {
          (*DAT_402f8a6c)(*param_2,piVar14,0x28000001,local_af0,local_aec);
          iVar9 = iVar1 + 1;
          local_ac0[iVar1 * 3] = (wchar_t *)puVar2[5];
          local_ac0[iVar1 * 3 + 1] = local_af0;
          local_ac0[iVar1 * 3 + 2] = (wchar_t *)0x0;
        }
      }
      piVar14 = (int *)(iVar10 + 0x18);
      pwVar13 = local_ae8;
      if (*piVar14 != 0) {
        local_aec = (*DAT_402f8a6c)(*param_2,piVar14,0x28000001,0,0);
        if (local_aec < 0x80000000) {
          uVar12 = local_aec << 1;
        }
        pwVar13 = operator_new(uVar12);
        if (pwVar13 != (wchar_t *)0x0) {
          (*DAT_402f8a6c)(*param_2,piVar14,0x28000001,pwVar13,local_aec);
          local_ac0[iVar9 * 3] = (wchar_t *)puVar2[6];
          local_ac0[iVar9 * 3 + 1] = pwVar13;
          local_ac0[iVar9 * 3 + 2] = (wchar_t *)0x0;
          iVar9 = iVar9 + 1;
        }
      }
      iVar1 = iVar9;
      if (local_ad4 != (wchar_t *)0x0) {
        iVar1 = iVar9 + 1;
        local_ac0[iVar9 * 3] = (wchar_t *)puVar2[7];
        local_ac0[iVar9 * 3 + 1] = local_ad4;
        local_ac0[iVar9 * 3 + 2] = (wchar_t *)0x0;
      }
      iVar10 = iVar1;
      if (local_ae4 != (wchar_t *)0x0) {
        iVar10 = iVar1 + 1;
        local_ac0[iVar1 * 3] = (wchar_t *)puVar2[8];
        local_ac0[iVar1 * 3 + 1] = local_ae4;
        local_ac0[iVar1 * 3 + 2] = (wchar_t *)0x0;
      }
      local_ae8 = (wchar_t *)0x10;
      iVar9 = (*DAT_402f8ab4)(param_2,4,&local_9d0,&local_ae8);
      iVar1 = iVar10;
      if ((iVar9 != 0) &&
         (FUN_402e39ac((int)&local_9d0,(uint)local_ae8,&local_acc), pwVar15 = local_acc,
         local_acc != (wchar_t *)0x0)) {
        iVar1 = iVar10 + 1;
        local_ac0[iVar10 * 3] = (wchar_t *)puVar2[0x18];
        local_ac0[iVar10 * 3 + 1] = local_acc;
        local_ac0[iVar10 * 3 + 2] = (wchar_t *)0x0;
      }
      pWVar11 = FUN_402e3280(param_2);
      iVar10 = iVar1;
      if (pWVar11 != (LPWSTR)0x0) {
        iVar10 = iVar1 + 1;
        local_ac0[iVar1 * 3 + 1] = pWVar11;
        local_ac0[iVar1 * 3] = (wchar_t *)puVar2[0x20];
        local_ac0[iVar1 * 3 + 2] = (wchar_t *)0x0;
      }
      iVar1 = (*DAT_402f8ab4)(param_2,2,0,&local_aec);
      iVar9 = iVar10 + 1;
      local_ac0[iVar10 * 3] = (wchar_t *)puVar2[0x1d];
      if (iVar1 == 0) {
        pwVar6 = (wchar_t *)puVar2[0x1f];
      }
      else {
        pwVar6 = (wchar_t *)puVar2[0x1e];
      }
      local_ac0[iVar10 * 3 + 1] = pwVar6;
      iVar1 = param_2[3];
      local_ac0[iVar10 * 3 + 2] = (wchar_t *)0x0;
      FUN_402e34f8(*(byte **)(iVar1 + 8),*(int *)(iVar1 + 4),(int)awStack_230,0x100,1);
      iVar1 = iVar10 + 2;
      local_ac0[iVar9 * 3 + 1] = awStack_230;
      local_ac0[iVar9 * 3] = (wchar_t *)puVar2[0x21];
      local_ac0[iVar9 * 3 + 2] = (wchar_t *)0x0;
      if (param_3 != 0) {
        iVar9 = iVar1;
        if (*(int *)(param_3 + 8) != 0) {
          piVar14 = &DAT_402f63ec;
          iVar7 = 0;
          do {
            if (*piVar14 == *(int *)(param_3 + 8)) {
              UVar16 = *(UINT *)(iVar7 * 8 + 0x402f63f0);
              break;
            }
            iVar7 = iVar7 + 1;
            piVar14 = piVar14 + 2;
          } while (iVar7 < 4);
          iVar7 = LoadStringW(DAT_402fc3c4,UVar16,aWStack_8f8,100);
          if (iVar7 != 0) {
            iVar9 = iVar10 + 3;
            local_ac0[iVar1 * 3 + 1] = aWStack_8f8;
            local_ac0[iVar1 * 3] = (wchar_t *)puVar2[9];
            local_ac0[iVar1 * 3 + 2] = (wchar_t *)0x0;
          }
        }
        piVar14 = &DAT_402f640c;
        if (*(int *)(param_3 + 0xc) != 0) {
          iVar1 = 0;
          piVar8 = piVar14;
          do {
            if (*piVar8 == *(int *)(param_3 + 0xc)) {
              UVar16 = *(UINT *)(iVar1 * 8 + 0x402f6410);
              goto LAB_402e4208;
            }
            iVar1 = iVar1 + 1;
            piVar8 = piVar8 + 2;
          } while (iVar1 < 0x16);
          UVar16 = 0x73f;
LAB_402e4208:
          LoadStringW(DAT_402fc3c4,UVar16,aWStack_9c0,100);
          local_9cc = *(uint *)(param_3 + 0x10);
          local_9d0 = aWStack_9c0;
          if (local_9cc < 0x60) {
            if (*(uint *)(param_3 + 0x10) < 0x40) {
              local_9c8 = puVar2[4];
            }
            else {
              local_9c8 = puVar2[3];
            }
          }
          else {
            local_9c8 = puVar2[2];
          }
          DVar3 = FormatMessageW(0x2500,(LPCVOID)puVar2[0x15],0,0x400,(LPWSTR)&local_ad8,0,
                                 (va_list *)&local_9d0);
          if (DVar3 != 0) {
            local_ac0[iVar9 * 3 + 1] = local_ad8;
            local_ac0[iVar9 * 3] = (wchar_t *)puVar2[0xb];
            local_ac0[iVar9 * 3 + 2] = (wchar_t *)0x0;
            iVar9 = iVar9 + 1;
          }
        }
        iVar1 = iVar9;
        if (*(int *)(param_3 + 0x14) != 0) {
          iVar10 = 0;
          piVar8 = piVar14;
          do {
            if (*piVar8 == *(int *)(param_3 + 0x14)) {
              UVar16 = *(UINT *)(iVar10 * 8 + 0x402f6410);
              goto LAB_402e431c;
            }
            iVar10 = iVar10 + 1;
            piVar8 = piVar8 + 2;
          } while (iVar10 < 0x16);
          UVar16 = 0x740;
LAB_402e431c:
          LoadStringW(DAT_402fc3c4,UVar16,aWStack_9c0,100);
          local_9cc = *(uint *)(param_3 + 0x18);
          local_9d0 = aWStack_9c0;
          if (local_9cc < 0x60) {
            if (*(uint *)(param_3 + 0x18) < 0x40) {
              local_9c8 = puVar2[4];
            }
            else {
              local_9c8 = puVar2[3];
            }
          }
          else {
            local_9c8 = puVar2[2];
          }
          DVar3 = FormatMessageW(0x2500,(LPCVOID)puVar2[0x16],0,0x400,(LPWSTR)&local_ae0,0,
                                 (va_list *)&local_9d0);
          if (DVar3 != 0) {
            iVar1 = iVar9 + 1;
            local_ac0[iVar9 * 3 + 1] = local_ae0;
            local_ac0[iVar9 * 3] = (wchar_t *)puVar2[0xc];
            local_ac0[iVar9 * 3 + 2] = (wchar_t *)0x0;
          }
        }
        if (*(int *)(param_3 + 0x1c) != 0) {
          iVar10 = 0;
          do {
            if (*piVar14 == *(int *)(param_3 + 0x1c)) {
              UVar16 = *(UINT *)(iVar10 * 8 + 0x402f6410);
              goto LAB_402e4430;
            }
            iVar10 = iVar10 + 1;
            piVar14 = piVar14 + 2;
          } while (iVar10 < 0x16);
          UVar16 = 0x741;
LAB_402e4430:
          LoadStringW(DAT_402fc3c4,UVar16,aWStack_9c0,100);
          local_9cc = *(uint *)(param_3 + 0x20);
          local_9d0 = aWStack_9c0;
          if (local_9cc < 0x400) {
            local_9c8 = puVar2[4];
          }
          else {
            local_9c8 = puVar2[2];
          }
          DVar3 = FormatMessageW(0x2500,(LPCVOID)puVar2[0x17],0,0x400,(LPWSTR)&local_adc,0,
                                 (va_list *)&local_9d0);
          if (DVar3 != 0) {
            local_ac0[iVar1 * 3 + 1] = local_adc;
            local_ac0[iVar1 * 3] = (wchar_t *)puVar2[0xd];
            local_ac0[iVar1 * 3 + 2] = (wchar_t *)0x0;
            iVar1 = iVar1 + 1;
          }
        }
      }
      local_ac0[iVar1 * 3] = (wchar_t *)0x0;
      local_ac0[iVar1 * 3 + 1] = (wchar_t *)0x0;
      local_ac0[iVar1 * 3 + 2] = (wchar_t *)0x0;
      hResInfo = FindResourceW(DAT_402fc3c4,local_ad0,(LPCWSTR)0x5);
      hDialogTemplate = LoadResource(DAT_402fc3c4,hResInfo);
      hWnd = local_ac8;
      iVar1 = DialogBoxIndirectParamW
                        (DAT_402fc3c4,hDialogTemplate,local_ac8,FUN_402e3740,(LPARAM)local_ac0);
      pwVar6 = local_af0;
      if (iVar1 != 0) {
        iVar10 = wcsncmp(local_830,&DAT_402f8ac8,0x100);
        if (iVar10 != 0) {
          sVar4 = wcslen(&DAT_402f8ac8);
          local_ac8 = (HWND)((sVar4 + 1) * 2);
          local_ac4 = &DAT_402f8ac8;
          iVar10 = (*DAT_402f8ab0)(param_2,0xb,0,&local_ac8);
          if (iVar10 == 0) {
            local_430 = L'\0';
            memset(auStack_42e,0,0x1fe);
            local_630 = L'\0';
            memset(auStack_62e,0,0x1fe);
            LoadStringW(DAT_402fc3c4,0x742,&local_430,0xff);
            LoadStringW(DAT_402fc3c4,0x743,&local_630,0xff);
            MessageBoxW(hWnd,&local_430,&local_630,0x30);
          }
        }
        DAT_402f8ac8 = 0;
      }
    }
    FUN_402e0570();
    if (pwVar13 != (wchar_t *)0x0) {
      operator_delete(pwVar13);
    }
    if (pwVar6 != (wchar_t *)0x0) {
      operator_delete(pwVar6);
    }
    if (local_ad4 != (wchar_t *)0x0) {
      operator_delete(local_ad4);
    }
    if (local_ae4 != (wchar_t *)0x0) {
      operator_delete(local_ae4);
    }
    if (local_ad8 != (wchar_t *)0x0) {
      operator_delete(local_ad8);
    }
    if (local_ae0 != (wchar_t *)0x0) {
      operator_delete(local_ae0);
    }
    if (local_adc != (wchar_t *)0x0) {
      operator_delete(local_adc);
    }
    if (pwVar15 != (wchar_t *)0x0) {
      operator_delete(pwVar15);
    }
    if (pWVar11 != (LPWSTR)0x0) {
      operator_delete(pWVar11);
    }
    FUN_402f41d8(local_30);
  }
  return iVar1;
}



/* 402e4734 ShowCertificate */

/* Boundary evidence: original MIPS .pdata 402e4734..402e474f. Semantic name remains unreviewed. */

void ShowCertificate(HWND param_1,undefined4 *param_2)

{
                    /* 0x14734  45  ShowCertificate */
  ShowCertificateEx(param_1,param_2,0);
  return;
}



/* 402e4750 FUN_402e4750 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 402e4750..402e4897. Semantic name remains unreviewed. */

undefined4 FUN_402e4750(HWND param_1)

{
  HWND pHVar1;
  int iVar2;
  DWORD DVar3;
  BOOL BVar4;
  UINT uElapse;
  HANDLE hHandle;
  int local_18 [2];
  
  local_18[1] = 0;
  local_18[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pHVar1 = GetParent(param_1);
  iVar2 = FUN_402d48fc((int)pHVar1,local_18);
  if (((-1 < iVar2) && (local_18[0] != 0)) &&
     (iVar2 = (*DAT_402fc220)(0,0x8000000,local_18[0] + 0x464,local_18 + 1), iVar2 == 0)) {
    hHandle = *(HANDLE *)(local_18[0] + 0x538);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
    DVar3 = WaitForSingleObject(hHandle,3000);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
    if (DVar3 == 0x102) {
      local_18[0] = 0;
      pHVar1 = GetParent(param_1);
      FUN_402d48fc((int)pHVar1,local_18);
    }
  }
  PostMessageW(param_1,0x40a,0,0);
  BVar4 = IsWindow(param_1);
  if (BVar4 != 0) {
    if ((local_18[0] == 0) || (uElapse = 30000, *(int *)(local_18[0] + 0x45c) == 10)) {
      uElapse = 2000;
    }
    SetTimer(param_1,1,uElapse,(TIMERPROC)0x0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return 0;
}



/* 402e4898 FUN_402e4898 */

/* Boundary evidence: original MIPS .pdata 402e4898..402e4a6f. Semantic name remains unreviewed. */

int FUN_402e4898(int param_1,int param_2)

{
  wchar_t *_Str2;
  size_t _MaxCount;
  LRESULT LVar1;
  size_t sVar2;
  int iVar3;
  HWND hWnd;
  int iVar4;
  int iVar5;
  undefined4 local_128;
  int local_124 [4];
  wchar_t *local_114;
  undefined4 local_110;
  int local_10c;
  WCHAR aWStack_f8 [52];
  wchar_t awStack_90 [48];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  _MaxCount = MultiByteToWideChar(0,0,(LPCSTR)(param_2 + 0x24),*(int *)(param_2 + 0x20),aWStack_f8,
                                  0x30);
  hWnd = *(HWND *)(param_1 + 0x74);
  aWStack_f8[_MaxCount] = L'\0';
  LVar1 = SendMessageW(hWnd,0x1004,0,0);
  iVar5 = 1;
  iVar4 = -1;
  if (1 < LVar1) {
    do {
      memset(local_124,0,0x28);
      local_114 = awStack_90;
      local_128 = 3;
      local_110 = 0x30;
      local_124[0] = iVar5;
      SendMessageW(*(HWND *)(param_1 + 0x74),0x104b,0,(LPARAM)&local_128);
      _Str2 = local_114;
      sVar2 = wcslen(local_114);
      if (((local_10c == 3) || (local_10c == 2)) || (iVar4 = 0, local_10c == 4)) {
        iVar4 = 1;
      }
      if ((*(int *)(param_2 + 0x70) == iVar4) &&
         (iVar4 = wcsncmp(aWStack_f8,_Str2,_MaxCount), iVar4 == 0)) {
        iVar4 = iVar5;
        if (sVar2 == DAT_402fc300 + _MaxCount) {
          iVar3 = wcscmp(_Str2 + (sVar2 - DAT_402fc300),(wchar_t *)&DAT_402fc280);
          if (iVar3 == 0) break;
        }
        else if (sVar2 == _MaxCount) break;
      }
      iVar5 = iVar5 + 1;
      iVar4 = -1;
    } while (iVar5 < LVar1);
  }
  FUN_402f41d8(local_30);
  return iVar4;
}



/* 402e4a70 FUN_402e4a70 */

/* Boundary evidence: original MIPS .pdata 402e4a70..402e4bff. Semantic name remains unreviewed. */

undefined4 FUN_402e4a70(int param_1,wchar_t *param_2,int param_3)

{
  size_t _MaxCount;
  size_t sVar1;
  size_t _MaxCount_00;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  WCHAR aWStack_70 [34];
  uint local_2c;
  
  local_2c = DAT_402f65fc;
  uVar3 = 0;
  if (param_1 == 0) {
    FUN_402f41d8(DAT_402f65fc);
    uVar3 = 0;
  }
  else {
    sVar1 = wcslen(param_2);
    iVar4 = param_1;
    do {
      _MaxCount_00 = MultiByteToWideChar(0,0,(LPCSTR)(iVar4 + 0x24),*(int *)(iVar4 + 0x20),
                                         aWStack_70,0x20);
      aWStack_70[_MaxCount_00] = L'\0';
      if (param_3 == *(int *)(iVar4 + 0x70)) {
        if ((sVar1 == _MaxCount_00) &&
           (iVar2 = wcsncmp(aWStack_70,param_2,_MaxCount_00), iVar2 == 0)) {
          uVar3 = 1;
          break;
        }
        _MaxCount = DAT_402fc300;
        if (((sVar1 == DAT_402fc300 + _MaxCount_00) &&
            (iVar2 = wcsncmp(aWStack_70,param_2,_MaxCount_00), iVar2 == 0)) &&
           (iVar2 = wcsncmp(param_2 + (sVar1 - _MaxCount),(wchar_t *)&DAT_402fc280,_MaxCount),
           iVar2 == 0)) {
          FUN_402f41d8(local_2c);
          return 1;
        }
      }
      iVar4 = *(int *)(iVar4 + 4);
    } while (iVar4 != param_1);
    FUN_402f41d8(local_2c);
  }
  return uVar3;
}



/* 402e4c00 FUN_402e4c00 */

/* Boundary evidence: original MIPS .pdata 402e4c00..402e4e4b. Semantic name remains unreviewed. */

undefined4 FUN_402e4c00(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  WPARAM WVar3;
  int iVar4;
  int iVar5;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined4 local_f0;
  int local_ec [4];
  WCHAR *local_dc;
  undefined4 local_d8;
  undefined1 auStack_c0 [4];
  WPARAM local_bc;
  PCNZWCH local_ac;
  WCHAR aWStack_90 [48];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memcpy(auStack_c0,&local_res4,0x2c);
  iVar1 = SendMessageW(param_1,0x1004,0,0);
  iVar5 = iVar1 + -1;
  iVar4 = 1;
  if (1 < iVar5) {
    do {
      iVar2 = iVar5 + iVar4;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 1;
      }
      WVar3 = iVar2 >> 1;
      local_dc = aWStack_90;
      local_ec[1] = 0;
      local_d8 = 0x30;
      SendMessageW(param_1,0x1073,WVar3,(LPARAM)&local_f0);
      iVar2 = CompareStringW(0x400,1,local_ac,-1,aWStack_90,-1);
      if (iVar2 == 1) {
        iVar5 = WVar3 - 1;
      }
      else {
        iVar4 = WVar3 + 1;
      }
    } while (iVar4 < iVar5);
  }
  iVar5 = iVar5 + iVar4;
  if (iVar5 < 0) {
    iVar5 = iVar5 + 1;
  }
  WVar3 = iVar5 >> 1;
  local_dc = aWStack_90;
  local_ec[1] = 0;
  local_d8 = 0x30;
  SendMessageW(param_1,0x1073,WVar3,(LPARAM)&local_f0);
  iVar5 = CompareStringW(0x400,1,local_ac,-1,aWStack_90,-1);
  if (iVar5 == 3) {
    WVar3 = WVar3 + 1;
  }
  if (WVar3 == 0) {
    WVar3 = 1;
  }
  iVar5 = (iVar1 - WVar3) + 1;
  if (0 < iVar5) {
    do {
      iVar1 = iVar1 + -1;
      local_f0 = 0;
      memset(local_ec,0,0x28);
      local_ec[0] = iVar1;
      SendMessageW(param_1,0x104b,0,(LPARAM)&local_f0);
      local_ec[0] = local_ec[0] + 1;
      SendMessageW(param_1,0x104c,0,(LPARAM)&local_f0);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  local_bc = WVar3;
  SendMessageW(param_1,0x104d,0,(LPARAM)auStack_c0);
  FUN_402f41d8(local_30);
  return 0;
}



/* 402e4e4c FUN_402e4e4c */

/* Boundary evidence: original MIPS .pdata 402e4e4c..402e4efb. Semantic name remains unreviewed. */

void FUN_402e4e4c(HWND param_1)

{
  HWND pHVar1;
  int iVar2;
  LRESULT LVar3;
  int local_18 [2];
  
  local_18[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pHVar1 = GetParent(param_1);
  iVar2 = FUN_402d48fc((int)pHVar1,local_18);
  if ((-1 < iVar2) && (local_18[0] != 0)) {
    LVar3 = SendMessageW(*(HWND *)(local_18[0] + 0x4fc),0xf0,0,0);
    DAT_402fc2a4 = (uint)(LVar3 == 1);
    FUN_402eb408(DAT_402fc2a4,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402e4efc FUN_402e4efc */

/* Boundary evidence: original MIPS .pdata 402e4efc..402e5097. Semantic name remains unreviewed. */

int FUN_402e4efc(HWND param_1)

{
  HWND pHVar1;
  int iVar2;
  LRESULT LVar3;
  int iVar4;
  int local_78 [2];
  undefined4 local_70;
  int local_6c [7];
  int local_50;
  char acStack_40 [36];
  uint local_1c;
  
  local_1c = DAT_402f65fc;
  iVar4 = 0;
  local_78[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  if (DAT_402fc2a4 != 0) {
    pHVar1 = GetParent(param_1);
    iVar2 = FUN_402d48fc((int)pHVar1,local_78);
    if ((iVar2 < 0) || (local_78[0] == 0)) {
      iVar4 = -0x7fffbffb;
    }
    else {
      iVar2 = *(int *)(local_78[0] + 0x45c);
      if ((((iVar2 == 2) || (iVar2 == 7)) || (iVar2 == 8)) || ((iVar2 == 9 || (iVar2 == 10)))) {
        LVar3 = SendMessageW(*(HWND *)(local_78[0] + 0x4d8),0x1004,0,0);
        iVar2 = 1;
        if (1 < LVar3) {
          do {
            memset(local_6c,0,0x28);
            local_70 = 4;
            local_6c[0] = iVar2;
            SendMessageW(*(HWND *)(local_78[0] + 0x4d8),0x104b,0,(LPARAM)&local_70);
            iVar4 = local_50;
            strncpy(acStack_40,(char *)(local_50 + 0x24),*(size_t *)(local_50 + 0x20));
            acStack_40[*(int *)(iVar4 + 0x20)] = '\0';
            iVar4 = FUN_402eb51c(acStack_40,*(int *)(iVar4 + 0x70));
            if (iVar4 != 0) break;
            iVar2 = iVar2 + 1;
          } while (iVar2 < LVar3);
        }
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_1c);
  return iVar4;
}



/* 402e5098 FUN_402e5098 */

/* Boundary evidence: original MIPS .pdata 402e5098..402e517f. Semantic name remains unreviewed. */

undefined4 FUN_402e5098(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  size_t _Count;
  char acStack_40 [36];
  uint local_1c;
  
  local_1c = DAT_402f65fc;
  uVar3 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar2 = *(int *)(param_1 + 0xa4);
  if (iVar2 != 0) {
    do {
      if (iVar2 == 0) {
LAB_402e5148:
        uVar3 = 0;
        break;
      }
      _Count = *(uint *)(iVar2 + 0x20);
      if (0x1f < _Count) {
        _Count = 0x20;
      }
      strncpy(acStack_40,(char *)(iVar2 + 0x24),_Count);
      acStack_40[_Count] = '\0';
      iVar1 = FUN_402eb77c(acStack_40,*(int *)(iVar2 + 0x70));
      if (iVar1 == 0) goto LAB_402e5148;
      iVar2 = *(int *)(iVar2 + 4);
    } while (iVar2 != *(int *)(param_1 + 0xa4));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_1c);
  return uVar3;
}



/* 402e5180 FUN_402e5180 */

/* Boundary evidence: original MIPS .pdata 402e5180..402e529b. Semantic name remains unreviewed. */

void FUN_402e5180(HWND param_1)

{
  HWND pHVar1;
  int iVar2;
  HANDLE hHandle;
  HANDLE hHandle_00;
  int local_20 [2];
  
  local_20[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pHVar1 = GetParent(param_1);
  iVar2 = FUN_402d48fc((int)pHVar1,local_20);
  if (iVar2 < 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  }
  else {
    if (*(HIMAGELIST *)(local_20[0] + 0x500) != (HIMAGELIST)0x0) {
      ImageList_Destroy(*(HIMAGELIST *)(local_20[0] + 0x500));
      *(undefined4 *)(local_20[0] + 0x500) = 0;
    }
    EventModify(*(undefined4 *)(local_20[0] + 0x538),3);
    hHandle_00 = *(HANDLE *)(local_20[0] + 0x530);
    hHandle = *(HANDLE *)(local_20[0] + 0x534);
    *(undefined4 *)(local_20[0] + 0x530) = 0;
    *(undefined4 *)(local_20[0] + 0x534) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
    if (hHandle_00 != (HANDLE)0x0) {
      WaitForSingleObject(hHandle_00,0xffffffff);
      CloseHandle(hHandle_00);
    }
    if (hHandle != (HANDLE)0x0) {
      WaitForSingleObject(hHandle,0xffffffff);
      CloseHandle(hHandle);
    }
  }
  return;
}



/* 402e529c FUN_402e529c */

/* Boundary evidence: original MIPS .pdata 402e529c..402e537f. Semantic name remains unreviewed. */

undefined4 FUN_402e529c(HWND param_1)

{
  LRESULT LVar1;
  WPARAM wParam;
  undefined4 local_48;
  WPARAM local_44 [7];
  int local_28;
  
  local_48 = 0;
  memset(local_44,0,0x28);
  LVar1 = SendMessageW(param_1,0x1004,0,0);
  wParam = 1;
  if (1 < LVar1) {
    do {
      local_48 = 4;
      local_44[0] = wParam;
      SendMessageW(param_1,0x104b,0,(LPARAM)&local_48);
      if ((local_28 != 0) && ((*(uint *)(local_28 + 0xc) & 4) != 0)) {
        SendMessageW(param_1,0x1013,wParam,0);
        return 1;
      }
      wParam = wParam + 1;
    } while ((int)wParam < LVar1);
  }
  return 0;
}



/* 402e5380 FUN_402e5380 */

/* Boundary evidence: original MIPS .pdata 402e5380..402e5447. Semantic name remains unreviewed. */

bool FUN_402e5380(HWND param_1,undefined4 *param_2,LRESULT *param_3)

{
  LRESULT LVar1;
  undefined4 local_50;
  LRESULT local_4c [7];
  undefined4 local_30;
  
  local_50 = 0;
  memset(local_4c,0,0x28);
  LVar1 = FUN_402d7608(param_1,0xffffffff,2);
  if (LVar1 != -1) {
    local_50 = 4;
    local_4c[0] = LVar1;
    SendMessageW(param_1,0x104b,0,(LPARAM)&local_50);
    *param_2 = local_30;
  }
  if (param_3 != (LRESULT *)0x0) {
    *param_3 = LVar1;
  }
  return LVar1 != -1;
}



/* 402e5448 FUN_402e5448 */

/* Boundary evidence: original MIPS .pdata 402e5448..402e569b. Semantic name remains unreviewed. */

void FUN_402e5448(HWND param_1)

{
  bool bVar1;
  int iVar2;
  HWND pHVar3;
  undefined3 extraout_var;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  BOOL BVar4;
  uint uVar5;
  HWND hWnd;
  LPCWSTR lpName;
  void *_Src;
  int local_150;
  int local_14c;
  undefined4 auStack_148 [16];
  int local_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined1 auStack_f0 [200];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  local_150 = 0;
  local_14c = 0;
  iVar2 = GetSystemMetrics(0);
  lpName = (LPCWSTR)0x4db;
  if (0x1df < iVar2) {
    lpName = (LPCWSTR)0x4da;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pHVar3 = GetParent(param_1);
  iVar2 = FUN_402d48fc((int)pHVar3,&local_150);
  if (((-1 < iVar2) && (local_150 != 0)) && ((*(uint *)(local_150 + 0x504) & 0x8000) != 0)) {
    FUN_402ee6bc(auStack_148,0x32ff,lpName);
    bVar1 = FUN_402e5380(*(HWND *)(local_150 + 0x4d8),&local_14c,(LRESULT *)0x0);
    iVar2 = local_150;
    if (CONCAT31(extraout_var,bVar1) != 0) {
      uVar5 = *(uint *)(local_150 + 0x484) & 7;
      if ((uVar5 == 2) || (uVar5 == *(uint *)(local_14c + 0x70))) {
        _Src = (void *)(local_14c + 0x10);
        memcpy(auStack_f0,_Src,0xc4);
        DAT_402fc260 = 1;
        local_100 = *(undefined4 *)(iVar2 + 0x488);
        local_fc = FUN_402e9634(*(int **)(iVar2 + 0x4c4));
        local_108 = 0;
        hWnd = *(HWND *)(local_150 + 0x518);
        hResInfo = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
        lpTemplate = LoadResource(DAT_402fc3c4,hResInfo);
        pHVar3 = CreateDialogIndirectParamW
                           (DAT_402fc3c4,lpTemplate,param_1,FUN_402efcf0,(LPARAM)auStack_148);
        if (pHVar3 != (HWND)0x0) {
          EnableWindow(hWnd,0);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
          FUN_402d4604(pHVar3);
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
          DAT_402fc260 = 0;
          BVar4 = IsWindow(hWnd);
          if (BVar4 != 0) {
            EnableWindow(hWnd,1);
          }
          local_150 = 0;
          iVar2 = FUN_402d48fc((int)hWnd,&local_150);
          if (iVar2 < 0) goto LAB_402e5668;
        }
        DAT_402fc260 = 0;
        if (local_108 != 0) {
          memcpy(_Src,auStack_f0,0xc4);
          FUN_402ea444(local_150 + 0x464,local_150 + 0x464);
          FUN_402e9738(local_150 + 0x464);
        }
      }
    }
  }
LAB_402e5668:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_28);
  return;
}



/* 402e569c FUN_402e569c */

/* Boundary evidence: original MIPS .pdata 402e569c..402e5767. Semantic name remains unreviewed. */

undefined4 FUN_402e569c(uint param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  BOOL BVar3;
  undefined4 uVar4;
  DWORD local_30 [2];
  undefined4 local_28;
  undefined1 auStack_24 [4];
  undefined4 local_20;
  uint local_18;
  
  local_18 = DAT_402f65fc;
  puVar1 = auStack_24 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_1 >> (3 - uVar2) * 8;
  local_28 = 0xd010206;
  local_30[0] = 0;
  auStack_24 = (undefined1  [4])param_1;
  BVar3 = DeviceIoControl(DAT_402f6620,0x120804,&local_28,0x10,&local_28,0x10,local_30,
                          (LPOVERLAPPED)0x0);
  if ((BVar3 == 1) && (param_2 != (undefined4 *)0x0)) {
    uVar4 = 0;
    *param_2 = local_20;
  }
  else {
    uVar4 = 0x80004005;
  }
  FUN_402f41d8(local_18);
  return uVar4;
}



/* 402e5768 FUN_402e5768 */

/* Boundary evidence: original MIPS .pdata 402e5768..402e592b. Semantic name remains unreviewed. */

undefined4 FUN_402e5768(int param_1,int param_2)

{
  int iVar1;
  HWND pHVar2;
  UINT uID;
  undefined4 uVar3;
  int local_1f8 [2];
  WCHAR aWStack_1f0 [32];
  wchar_t awStack_1b0 [32];
  WCHAR aWStack_170 [32];
  WCHAR aWStack_130 [68];
  WCHAR aWStack_a8 [68];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  uVar3 = 1;
  local_1f8[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar1 = FUN_402d48fc(param_1,local_1f8);
  if (((iVar1 < 0) || (local_1f8[0] == 0)) || (*(int *)(local_1f8[0] + 0x528) == 0)) {
    uVar3 = 0;
  }
  else {
    LoadStringW(DAT_402fc3c4,0x17be,aWStack_130,0x43);
    pHVar2 = GetDlgItem(*(HWND *)(local_1f8[0] + 0x520),0x17a8);
    GetWindowTextW(pHVar2,aWStack_a8,0x43);
    iVar1 = wcscmp(aWStack_a8,aWStack_130);
    if (iVar1 == 0) {
      param_2 = 0;
    }
    pHVar2 = GetDlgItem(*(HWND *)(local_1f8[0] + 0x520),0x1780);
    if (pHVar2 != (HWND)0x0) {
      if (param_2 == 0) {
        uID = 0x17ae;
      }
      else if (param_2 == 1) {
        uID = 0x17af;
      }
      else if (param_2 == 2) {
        uID = 0x17b0;
      }
      else if (param_2 == 3) {
        uID = 0x17b1;
      }
      else {
        uID = 0x17b2;
        if (param_2 != 4) {
          uID = 0x17b3;
        }
      }
      LoadStringW(DAT_402fc3c4,uID,aWStack_1f0,0x20);
      wcscpy(awStack_1b0,aWStack_1f0);
      GetWindowTextW(pHVar2,aWStack_170,0x20);
      iVar1 = wcscmp(aWStack_170,awStack_1b0);
      if (iVar1 != 0) {
        SetWindowTextW(pHVar2,awStack_1b0);
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_20);
  return uVar3;
}



/* 402e592c FUN_402e592c */

/* Boundary evidence: original MIPS .pdata 402e592c..402e5ac7. Semantic name remains unreviewed. */

void FUN_402e592c(HWND param_1,LPCWSTR param_2)

{
  BOOL BVar1;
  HWND hWnd;
  HDC hdc;
  size_t cchString;
  size_t cchString_00;
  tagSIZE local_c8;
  tagRECT local_c0;
  wchar_t awStack_b0 [68];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  BVar1 = IsWindow(param_1);
  if (BVar1 == 0) goto LAB_402e5a9c;
  hWnd = GetDlgItem(param_1,0x17a8);
  GetWindowRect(hWnd,&local_c0);
  hdc = GetWindowDC(hWnd);
  cchString = wcslen(param_2);
  GetTextExtentExPointW(hdc,param_2,cchString,0,(LPINT)0x0,(LPINT)0x0,&local_c8);
  cchString_00 = cchString;
  if ((uint)(local_c0.right - local_c0.left) < (uint)local_c8.cx) {
    do {
      cchString_00 = cchString_00 - 1;
      GetTextExtentExPointW(hdc,param_2,cchString_00,0,(LPINT)0x0,(LPINT)0x0,&local_c8);
    } while ((uint)(local_c0.right - local_c0.left) < (uint)local_c8.cx);
    if (cchString <= cchString_00) goto LAB_402e5a88;
    if (0x41 < cchString_00) {
      cchString_00 = 0x42;
    }
    if (2 < cchString_00) {
      wcsncpy(awStack_b0,param_2,cchString_00 - 3);
      awStack_b0[cchString_00 - 3] = L'\0';
      wcscat(awStack_b0,L"...");
      param_2 = awStack_b0;
      goto LAB_402e5a88;
    }
  }
  else {
LAB_402e5a88:
    SetWindowTextW(hWnd,param_2);
  }
  ReleaseDC(hWnd,hdc);
LAB_402e5a9c:
  FUN_402f41d8(local_28);
  return;
}



/* 402e5ac8 FUN_402e5ac8 */

/* Boundary evidence: original MIPS .pdata 402e5ac8..402e5bc7. Semantic name remains unreviewed. */

void FUN_402e5ac8(wchar_t *param_1)

{
  size_t sVar1;
  int iVar2;
  wchar_t *pwVar3;
  size_t sVar4;
  WCHAR aWStack_b8 [12];
  wchar_t awStack_a0 [68];
  uint local_18;
  
  local_18 = DAT_402f65fc;
  sVar1 = wcslen(param_1);
  if (sVar1 != 0) {
    pwVar3 = param_1 + sVar1;
    sVar4 = sVar1;
    do {
      if (*pwVar3 == L'%') {
        if (((sVar4 != 0xffffffff) &&
            (iVar2 = LoadStringW(DAT_402fc3c4,0x4c2,aWStack_b8,10), iVar2 != 0)) &&
           (iVar2 + sVar1 < 0x43)) {
          wcscpy(awStack_a0,param_1 + sVar4);
          wcscpy(param_1 + sVar4,aWStack_b8);
          wcscat(param_1,L" ");
          wcscat(param_1,awStack_a0);
        }
        break;
      }
      sVar4 = sVar4 - 1;
      pwVar3 = pwVar3 + -1;
    } while (sVar4 != 0);
  }
  FUN_402f41d8(local_18);
  return;
}



/* 402e5bc8 FUN_402e5bc8 */

/* Boundary evidence: original MIPS .pdata 402e5bc8..402e5c8b. Semantic name remains unreviewed. */

undefined4 FUN_402e5bc8(int param_1,size_t *param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  size_t _MaxCount;
  
  if (param_1 != 0) {
    _MaxCount = *param_2;
    iVar2 = param_1;
    do {
      if (((_MaxCount == *(size_t *)(iVar2 + 0x20)) &&
          (iVar1 = strncmp((char *)(iVar2 + 0x24),(char *)(param_2 + 1),_MaxCount), iVar1 == 0)) &&
         (param_3 == *(int *)(iVar2 + 0x70))) {
        if (param_4 != (int *)0x0) {
          *param_4 = iVar2;
        }
        return 1;
      }
      iVar2 = *(int *)(iVar2 + 4);
    } while (iVar2 != param_1);
  }
  return 0;
}



/* 402e5c8c UpdateConnectionStatus */

/* Boundary evidence: original MIPS .pdata 402e5c8c..402e5f33. Semantic name remains unreviewed. */

void UpdateConnectionStatus(wchar_t *param_1,int param_2)

{
  int iVar1;
  HANDLE pvVar2;
  STRSAFE_LPCWSTR pszDest;
  size_t sVar3;
  BOOL BVar4;
  undefined4 *puVar5;
  wchar_t *_Str;
  int local_d8 [2];
  CHAR aCStack_d0 [40];
  WCHAR aWStack_a8 [68];
  uint local_20;
  
                    /* 0x15c8c  49  UpdateConnectionStatus */
  local_20 = DAT_402f65fc;
  local_d8[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar1 = FUN_402d49ac(param_1,local_d8);
  if ((-1 < iVar1) && (local_d8[0] != 0)) {
    if (param_2 == 0) {
      *(undefined4 *)(local_d8[0] + 0x460) = 0;
      if (*(int *)(local_d8[0] + 0x524) == 1) {
        pvVar2 = LoadImageW(DAT_402fc3c4,(LPCWSTR)0x17a4,1,0x10,0x10,0);
      }
      else {
        pvVar2 = LoadImageW(DAT_402fc3c4,(LPCWSTR)0x17a7,1,0x10,0x10,0);
      }
    }
    else {
      *(undefined4 *)(local_d8[0] + 0x460) = 1;
      if (*(int *)(local_d8[0] + 0x524) == 1) {
        pvVar2 = LoadImageW(DAT_402fc3c4,(LPCWSTR)0x17a3,1,0x10,0x10,0);
        iVar1 = wcscmp((wchar_t *)(local_d8[0] + 0x414),L"");
        if (iVar1 != 0) {
          pszDest = LocalAlloc(0,0x86);
          if (pszDest == (STRSAFE_LPCWSTR)0x0) goto LAB_402e5f08;
          LoadStringW(DAT_402fc3c4,0x17bb,aWStack_a8,0x43);
          _Str = (wchar_t *)(local_d8[0] + 0x414);
          sVar3 = wcslen(_Str);
          WideCharToMultiByte(0,0,_Str,sVar3 + 1,aCStack_d0,0x21,(LPCSTR)0x0,(LPBOOL)0x0);
          if (*(int *)(local_d8[0] + 0x458) == 0) {
            FUN_402e5ac8(aWStack_a8);
          }
          StringCchPrintfW(pszDest,0x43,aWStack_a8,local_d8[0] + 0x414);
          StringCchCopyW(*(STRSAFE_LPWSTR *)(local_d8[0] + 0x410),0x43,pszDest);
          if ((*(int *)(local_d8[0] + 0x528) == 0) ||
             (BVar4 = IsWindow(*(HWND *)(local_d8[0] + 0x520)), BVar4 == 0)) {
            LocalFree(pszDest);
          }
          else {
            PostMessageW(*(HWND *)(local_d8[0] + 0x520),0x40b,0,(LPARAM)pszDest);
          }
        }
      }
      else {
        pvVar2 = LoadImageW(DAT_402fc3c4,(LPCWSTR)0x17a6,1,0x10,0x10,0);
      }
    }
    puVar5 = (undefined4 *)(*(int *)(local_d8[0] + 0x53c) + 0x14);
    if (((HANDLE)*puVar5 != pvVar2) &&
       (*puVar5 = pvVar2, *(int *)(*(int *)(local_d8[0] + 0x53c) + 0x14) != 0)) {
      Shell_NotifyIcon(1);
    }
  }
LAB_402e5f08:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_20);
  return;
}



/* 402e5f34 FUN_402e5f34 */

/* Boundary evidence: original MIPS .pdata 402e5f34..402e5f9f. Semantic name remains unreviewed. */

undefined4 FUN_402e5f34(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  if ((*(int **)(param_1 + 0x4a8) == (int *)0x0) || (**(int **)(param_1 + 0x4a8) == 0)) {
    uVar1 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return uVar1;
}



/* 402e5fa0 FUN_402e5fa0 */

/* Boundary evidence: original MIPS .pdata 402e5fa0..402e61fb. Semantic name remains unreviewed. */

undefined4 FUN_402e5fa0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  size_t _Count;
  undefined4 local_f0;
  int local_ec;
  undefined4 local_e8;
  undefined1 auStack_e4 [8];
  WCHAR *local_dc;
  undefined4 local_d4;
  int local_d0;
  char acStack_c0 [48];
  WCHAR aWStack_90 [50];
  uint local_2c;
  
  local_2c = DAT_402f65fc;
  local_f0 = 0;
  memset(&local_ec,0,0x28);
  bVar2 = false;
  iVar3 = MultiByteToWideChar(0,0,(char *)(param_2 + 0x24),*(int *)(param_2 + 0x20),aWStack_90,0x30)
  ;
  iVar4 = *(int *)(param_2 + 0x70);
  aWStack_90[iVar3] = L'\0';
  if (iVar4 == 1) {
    if ((*(uint *)(param_2 + 0xc) & 4) == 0) {
      if ((*(uint *)(param_2 + 0xc) & 2) == 0) {
        uVar5 = 4;
      }
      else {
        uVar5 = 2;
      }
    }
    else {
      uVar5 = 3;
    }
  }
  else if ((*(uint *)(param_2 + 0xc) & 4) == 0) {
    uVar5 = 5;
    if ((*(uint *)(param_2 + 0xc) & 2) == 0) {
      uVar5 = 7;
    }
  }
  else {
    uVar5 = 6;
  }
  iVar3 = wcscmp(aWStack_90,L"");
  if (iVar3 != 0) {
    memset(&local_f0,0,0x2c);
    local_dc = aWStack_90;
    local_e8 = 0;
    local_f0 = 7;
    local_d4 = uVar5;
    local_d0 = param_2;
    local_ec = FUN_402e4898(param_1 + 0x464,param_2);
    bVar1 = local_ec != -1;
    if (!bVar1) {
      local_ec = 0;
    }
    _Count = *(uint *)(param_2 + 0x20);
    if (0x2e < _Count) {
      _Count = 0x2f;
    }
    strncpy(acStack_c0,(char *)(param_2 + 0x24),_Count);
    iVar3 = *(int *)(param_1 + 0x50c);
    acStack_c0[_Count] = '\0';
    iVar3 = FUN_402e988c(iVar3,param_2 + 0x10,(int *)0x0);
    if (param_3 == 0) {
      if (iVar3 != 0) {
        bVar2 = true;
      }
    }
    else {
      wcscat(local_dc,(wchar_t *)&DAT_402fc280);
    }
    if (bVar1) {
      if (!bVar2) {
        SendMessageW(*(HWND *)(param_1 + 0x4d8),0x104c,0,(LPARAM)&local_f0);
      }
    }
    else {
      memcpy(&stack0xfffffef0,auStack_e4,0x20);
      FUN_402e4c00(*(HWND *)(param_1 + 0x4d8),local_f0,local_ec,local_e8);
    }
  }
  FUN_402f41d8(local_2c);
  return 0;
}



/* 402e61fc FUN_402e61fc */

/* Boundary evidence: original MIPS .pdata 402e61fc..402e6327. Semantic name remains unreviewed. */

void FUN_402e61fc(int param_1)

{
  LRESULT LVar1;
  LRESULT LVar2;
  int iVar3;
  int iVar4;
  int local_b8 [2];
  undefined4 local_b0;
  int local_ac [4];
  undefined1 *local_9c;
  undefined4 local_98;
  int local_90;
  undefined1 auStack_80 [96];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  if (*(HWND *)(param_1 + 0x78) != (HWND)0x0) {
    LVar1 = SendMessageW(*(HWND *)(param_1 + 0x78),0x1004,0,0);
    iVar4 = 0;
    if (0 < LVar1) {
      do {
        memset(local_ac,0,0x28);
        local_b0 = 7;
        local_9c = auStack_80;
        local_ac[1] = 0;
        local_98 = 0x30;
        local_ac[0] = iVar4;
        LVar2 = SendMessageW(*(HWND *)(param_1 + 0x78),0x104b,0,(LPARAM)&local_b0);
        if (((LVar2 != 0) && (local_90 != 0)) &&
           (iVar3 = FUN_402e5bc8(*(int *)(param_1 + 0xa8),(size_t *)(local_90 + 0x20),
                                 *(int *)(local_90 + 0x70),local_b8), iVar3 != 0)) {
          local_90 = local_b8[0];
          SendMessageW(*(HWND *)(param_1 + 0x78),0x104c,0,(LPARAM)&local_b0);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < LVar1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_20);
  return;
}



/* 402e6328 FUN_402e6328 */

/* Boundary evidence: original MIPS .pdata 402e6328..402e64ef. Semantic name remains unreviewed. */

void FUN_402e6328(int param_1)

{
  LRESULT LVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_c0 [7];
  wchar_t *local_a4;
  undefined4 local_a0;
  int local_9c;
  wchar_t awStack_88 [48];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  iVar5 = 0;
  LVar1 = SendMessageW(*(HWND *)(param_1 + 0x4d8),0x1004,0,0);
  iVar4 = 1;
  if (1 < LVar1) {
    do {
      memset(local_c0 + 3,0,0x28);
      local_a4 = awStack_88;
      local_c0[2] = 3;
      local_a0 = 0x30;
      local_c0[3] = iVar4 - iVar5;
      SendMessageW(*(HWND *)(param_1 + 0x4d8),0x104b,0,(LPARAM)(local_c0 + 2));
      if (((local_9c == 3) || (local_9c == 2)) || (iVar3 = 0, local_9c == 4)) {
        iVar3 = 1;
      }
      if (((*(int *)(param_1 + 0x50c) == 0) ||
          (iVar2 = FUN_402e4a70(*(int *)(param_1 + 0x50c),local_a4,iVar3), iVar2 == 0)) &&
         ((*(int *)(param_1 + 0x508) == 0 ||
          (iVar3 = FUN_402e4a70(*(int *)(param_1 + 0x508),local_a4,iVar3), iVar3 == 0)))) {
        SendMessageW(*(HWND *)(param_1 + 0x4d8),0x1008,iVar4 - iVar5,0);
        iVar5 = iVar5 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < LVar1);
  }
  iVar4 = 0;
  local_c0[0] = *(int *)(param_1 + 0x50c);
  local_c0[1] = *(undefined4 *)(param_1 + 0x508);
  do {
    iVar3 = local_c0[iVar4];
    iVar5 = iVar3;
    if (iVar3 != 0) {
      do {
        FUN_402e5fa0(param_1,iVar5,(uint)(iVar4 == 0));
        iVar5 = *(int *)(iVar5 + 4);
      } while (iVar5 != iVar3);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  FUN_402f41d8(local_28);
  return;
}



/* 402e64f0 FUN_402e64f0 */

/* Boundary evidence: original MIPS .pdata 402e64f0..402e660b. Semantic name remains unreviewed. */

undefined4 FUN_402e64f0(int param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  if ((*(int *)(param_1 + 0x4dc) == 0) && (DAT_402fc260 == 0)) {
    if (*(int *)(param_1 + 0x4b4) != 0) {
      piVar4 = (int *)(param_1 + 0x464);
      (*DAT_402fc214)(piVar4);
      *piVar4 = param_1;
      iVar1 = (*DAT_402fc20c)(0,0x7fffffff,piVar4,param_1 + 0x4d4);
      if (iVar1 == 0) {
        FUN_402e9ce0((int)piVar4,*(uint **)(param_1 + 0x4a0));
        FUN_402e9e14((int)piVar4,*(uint **)(param_1 + 0x4a8));
        FUN_402e9f68((int)piVar4,(int)piVar4);
        if ((*(int *)(param_1 + 0x528) != 0) &&
           (BVar2 = IsWindow(*(HWND *)(param_1 + 0x520)), BVar2 != 0)) {
          FUN_402e6328(param_1);
          FUN_402e4efc(*(HWND *)(param_1 + 0x520));
        }
        goto LAB_402e65e4;
      }
    }
    uVar3 = 0x80004005;
  }
LAB_402e65e4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return uVar3;
}



/* 402e660c FUN_402e660c */

/* Boundary evidence: original MIPS .pdata 402e660c..402e678b. Semantic name remains unreviewed. */

int FUN_402e660c(HWND param_1)

{
  bool bVar1;
  HWND pHVar2;
  int iVar3;
  HWND hWnd;
  BOOL BVar4;
  LRESULT LVar5;
  undefined3 extraout_var;
  uint uVar6;
  int local_20;
  int local_1c;
  
  local_20 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pHVar2 = GetParent(param_1);
  iVar3 = FUN_402d48fc((int)pHVar2,&local_20);
  if (((iVar3 < 0) || (local_20 == 0)) || ((*(uint *)(local_20 + 0x504) & 0x8000) == 0))
  goto LAB_402e6760;
  pHVar2 = GetDlgItem(param_1,0x7d4);
  hWnd = GetDlgItem(param_1,0x1781);
  if ((pHVar2 == (HWND)0x0) || (hWnd == (HWND)0x0)) {
    iVar3 = -0x7fffbffb;
    goto LAB_402e6760;
  }
  BVar4 = IsWindowEnabled(pHVar2);
  if ((BVar4 == 0) && (BVar4 = IsWindowEnabled(hWnd), BVar4 == 0)) goto LAB_402e6760;
  LVar5 = FUN_402d7608(pHVar2,0xffffffff,2);
  if (LVar5 < 1) {
LAB_402e673c:
    BVar4 = 0;
  }
  else {
    if ((*(uint *)(local_20 + 0x504) & 0x8000) == 0) goto LAB_402e6760;
    local_1c = 0;
    bVar1 = FUN_402e5380(*(HWND *)(local_20 + 0x4d8),&local_1c,(LRESULT *)0x0);
    if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_402e6760;
    uVar6 = *(uint *)(local_20 + 0x484) & 7;
    if ((uVar6 != 2) && (uVar6 != *(uint *)(local_1c + 0x70))) goto LAB_402e673c;
    BVar4 = 1;
  }
  EnableWindow(hWnd,BVar4);
LAB_402e6760:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return iVar3;
}



/* 402e678c FUN_402e678c */

/* Boundary evidence: original MIPS .pdata 402e678c..402e697b. Semantic name remains unreviewed. */

void FUN_402e678c(HWND param_1)

{
  bool bVar1;
  HWND pHVar2;
  int iVar3;
  HCURSOR pHVar4;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  BOOL BVar5;
  HWND hWnd;
  int local_20 [2];
  
  local_20[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pHVar2 = GetParent(param_1);
  iVar3 = FUN_402d48fc((int)pHVar2,local_20);
  if ((-1 < iVar3) && (local_20[0] != 0)) {
    if (((*(uint *)(local_20[0] + 0x484) & 0x8000) != 0) &&
       ((*(uint *)(local_20[0] + 0x4d4) & 0x4000000) == 0)) {
      pHVar4 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
      SetCursor(pHVar4);
      FUN_402e64f0(local_20[0]);
      pHVar4 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
      SetCursor(pHVar4);
    }
    hWnd = *(HWND *)(local_20[0] + 0x518);
    iVar3 = local_20[0] + 0x464;
    hResInfo = FindResourceW(DAT_402fc3c4,(LPCWSTR)0x4f8,(LPCWSTR)0x5);
    lpTemplate = LoadResource(DAT_402fc3c4,hResInfo);
    pHVar2 = CreateDialogIndirectParamW(DAT_402fc3c4,lpTemplate,param_1,FUN_402eaf44,iVar3);
    if (pHVar2 != (HWND)0x0) {
      EnableWindow(hWnd,0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      FUN_402d4604(pHVar2);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      BVar5 = IsWindow(hWnd);
      if (BVar5 != 0) {
        EnableWindow(hWnd,1);
      }
      local_20[0] = 0;
      pHVar2 = GetParent(param_1);
      iVar3 = FUN_402d48fc((int)pHVar2,local_20);
      if ((-1 < iVar3) && (local_20[0] != 0)) {
        *(undefined4 *)(local_20[0] + 0x4dc) = 0;
        FUN_402e64f0(local_20[0]);
        bVar1 = (*(uint *)(local_20[0] + 0x504) & 0x8000) == 0;
        if (bVar1) {
          EnableWindow(*(HWND *)(local_20[0] + 0x4e0),0);
        }
        else {
          EnableWindow(*(HWND *)(local_20[0] + 0x4e0),1);
        }
        EnableWindow(*(HWND *)(local_20[0] + 0x4e4),(uint)!bVar1);
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402e697c FUN_402e697c */

/* Boundary evidence: original MIPS .pdata 402e697c..402e6bf7. Semantic name remains unreviewed. */

void FUN_402e697c(int param_1)

{
  int iVar1;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  HWND pHVar2;
  BOOL BVar3;
  uint uVar4;
  HWND hWnd;
  LPCWSTR lpName;
  int local_148;
  int local_144;
  undefined4 auStack_140 [16];
  int local_100;
  uint local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined1 auStack_e8 [52];
  uint local_b4;
  uint local_88;
  undefined4 local_24;
  uint local_20;
  
  local_20 = DAT_402f65fc;
  local_148 = 0;
  local_144 = 0;
  iVar1 = GetSystemMetrics(0);
  lpName = (LPCWSTR)0x4db;
  if (0x1df < iVar1) {
    lpName = (LPCWSTR)0x4da;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar1 = FUN_402d48fc(param_1,&local_148);
  if ((-1 < iVar1) && ((*(uint *)(local_148 + 0x504) & 0x8000) != 0)) {
    FUN_402ee6bc(auStack_140,0x31ff,lpName);
    uVar4 = *(uint *)(local_148 + 0x484) & 7;
    if (uVar4 != 2) {
      local_fc = local_fc & 0xfffffffd;
      local_88 = uVar4;
    }
    local_f8 = *(undefined4 *)(local_148 + 0x488);
    local_f4 = FUN_402e9634(*(int **)(local_148 + 0x4c4));
    local_b4 = *(uint *)(local_148 + 0x488) & 0xff;
    local_24 = *(undefined4 *)(local_148 + 0x50c);
    local_100 = 0;
    hWnd = *(HWND *)(local_148 + 0x518);
    hResInfo = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
    lpTemplate = LoadResource(DAT_402fc3c4,hResInfo);
    pHVar2 = CreateDialogIndirectParamW
                       (DAT_402fc3c4,lpTemplate,*(HWND *)(local_148 + 0x520),FUN_402efcf0,
                        (LPARAM)auStack_140);
    if (pHVar2 != (HWND)0x0) {
      EnableWindow(hWnd,0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      FUN_402d4604(pHVar2);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      BVar3 = IsWindow(hWnd);
      if (BVar3 != 0) {
        EnableWindow(hWnd,1);
      }
      local_148 = 0;
      iVar1 = FUN_402d48fc((int)hWnd,&local_148);
      if (iVar1 < 0) goto LAB_402e6bcc;
    }
    if (local_100 != 0) {
      uVar4 = 1;
      iVar1 = FUN_402e988c(*(int *)(local_148 + 0x508),(int)auStack_e8,(int *)0x0);
      if (iVar1 != 0) {
        uVar4 = 3;
      }
      local_144 = 0;
      iVar1 = FUN_402e9ae8(local_148 + 0x464,3,uVar4,auStack_e8,&local_144);
      FUN_402ea444(local_148 + 0x464,local_148 + 0x464);
      FUN_402e9738(local_148 + 0x464);
      if ((local_100 != 0) && (iVar1 == 0)) {
        FUN_402e5fa0(local_148,local_144,1);
      }
    }
  }
LAB_402e6bcc:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_20);
  return;
}



/* 402e6bf8 FUN_402e6bf8 */

/* Boundary evidence: original MIPS .pdata 402e6bf8..402e6d8f. Semantic name remains unreviewed. */

void FUN_402e6bf8(HWND param_1)

{
  HWND pHVar1;
  int iVar2;
  HMENU hMenu;
  UINT uFlags;
  int local_28 [2];
  tagPOINT local_20;
  int local_18 [2];
  
  local_28[0] = 0;
  pHVar1 = GetParent(param_1);
  iVar2 = FUN_402d48fc((int)pHVar1,local_28);
  if (iVar2 < 0) {
    return;
  }
  if (local_28[0] == 0) {
    return;
  }
  local_20.x = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402e5380(*(HWND *)(local_28[0] + 0x4d8),local_18,&local_20.x);
  if ((local_20.x < 1) || (hMenu = CreatePopupMenu(), hMenu == (HMENU)0x0)) goto LAB_402e6d70;
  if ((*(uint *)(local_28[0] + 0x504) & 0x8000) == 0) {
    AppendMenuW(hMenu,1,0x17ee,(LPCWSTR)&DAT_402fc2c0);
LAB_402e6d14:
    AppendMenuW(hMenu,1,0x17ed,(LPCWSTR)&DAT_402fc2e0);
    uFlags = 1;
  }
  else {
    AppendMenuW(hMenu,0,0x17ee,(LPCWSTR)&DAT_402fc2c0);
    iVar2 = FUN_402e988c(*(int *)(local_28[0] + 0x50c),local_18[0] + 0x10,(int *)0x0);
    if (iVar2 == 0) goto LAB_402e6d14;
    AppendMenuW(hMenu,0,0x17ed,(LPCWSTR)&DAT_402fc2e0);
    uFlags = 0;
  }
  AppendMenuW(hMenu,uFlags,0x17ef,(LPCWSTR)&DAT_402fc240);
  GetCursorPos(&local_20);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  TrackPopupMenuEx(hMenu,0,local_20.x,local_20.y,param_1,(LPTPMPARAMS)0x0);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  DestroyMenu(hMenu);
LAB_402e6d70:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402e6d90 FUN_402e6d90 */

/* Boundary evidence: original MIPS .pdata 402e6d90..402e6e8f. Semantic name remains unreviewed. */

void FUN_402e6d90(HWND param_1)

{
  bool bVar1;
  HWND pHVar2;
  int iVar3;
  undefined3 extraout_var;
  int local_18;
  int *local_14;
  
  local_18 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pHVar2 = GetParent(param_1);
  iVar3 = FUN_402d48fc((int)pHVar2,&local_18);
  if ((((-1 < iVar3) && (local_18 != 0)) && ((*(uint *)(local_18 + 0x504) & 0x8000) != 0)) &&
     (bVar1 = FUN_402e5380(*(HWND *)(local_18 + 0x4d8),&local_14,(LRESULT *)0x0),
     CONCAT31(extraout_var,bVar1) != 0)) {
    if ((local_14 == (int *)local_14[1]) && (local_14 == (int *)*local_14)) {
      *(undefined4 *)(local_18 + 0x50c) = 0;
    }
    else if (*(int **)(local_18 + 0x50c) == local_14) {
      *(int *)(local_18 + 0x50c) = local_14[1];
    }
    FUN_402e97fc(local_14);
    FUN_402ea444(local_18 + 0x464,local_18 + 0x464);
    FUN_402e9738(local_18 + 0x464);
    FUN_402e6328(local_18);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402e6e90 FUN_402e6e90 */

/* Boundary evidence: original MIPS .pdata 402e6e90..402e71bf. Semantic name remains unreviewed. */

void FUN_402e6e90(HWND param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  HWND pHVar4;
  undefined3 extraout_var;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  BOOL BVar5;
  uint uVar6;
  HWND hWnd;
  LPCWSTR lpName;
  int local_1e8;
  int local_1e4;
  int aiStack_1e0 [2];
  undefined4 auStack_1d8 [16];
  int local_198;
  uint local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined1 auStack_180 [96];
  uint local_120;
  undefined4 local_bc;
  WCHAR aWStack_b8 [68];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  local_1e4 = 0;
  local_1e8 = 0;
  iVar3 = GetSystemMetrics(0);
  lpName = (LPCWSTR)0x4db;
  if (0x1df < iVar3) {
    lpName = (LPCWSTR)0x4da;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pHVar4 = GetParent(param_1);
  iVar3 = FUN_402d48fc((int)pHVar4,&local_1e8);
  if (((-1 < iVar3) && (local_1e8 != 0)) && ((*(uint *)(local_1e8 + 0x504) & 0x8000) != 0)) {
    FUN_402ee6bc(auStack_1d8,0x36ff,lpName);
    bVar2 = FUN_402e5380(*(HWND *)(local_1e8 + 0x4d8),&local_1e4,(LRESULT *)0x0);
    iVar1 = local_1e4;
    iVar3 = local_1e8;
    if (CONCAT31(extraout_var,bVar2) != 0) {
      uVar6 = *(uint *)(local_1e8 + 0x484) & 7;
      if ((uVar6 == 2) || (uVar6 == *(uint *)(local_1e4 + 0x70))) {
        memcpy(auStack_180,(void *)(local_1e4 + 0x10),0xc4);
        iVar3 = FUN_402e5bc8(*(int *)(iVar3 + 0x50c),(size_t *)(iVar1 + 0x20),*(int *)(iVar1 + 0x70)
                             ,aiStack_1e0);
        if (iVar3 == 0) {
          uVar6 = *(uint *)(local_1e8 + 0x484) & 7;
          if (uVar6 != 2) {
            local_194 = local_194 & 0xfffffffd;
            local_120 = uVar6;
          }
          local_190 = *(undefined4 *)(local_1e8 + 0x488);
          local_18c = FUN_402e9634(*(int **)(local_1e8 + 0x4c4));
          local_bc = *(undefined4 *)(local_1e8 + 0x50c);
          local_198 = 0;
          hWnd = *(HWND *)(local_1e8 + 0x518);
          DAT_402fc260 = 1;
          hResInfo = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
          lpTemplate = LoadResource(DAT_402fc3c4,hResInfo);
          pHVar4 = CreateDialogIndirectParamW
                             (DAT_402fc3c4,lpTemplate,param_1,FUN_402efcf0,(LPARAM)auStack_1d8);
          if (pHVar4 != (HWND)0x0) {
            EnableWindow(hWnd,0);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
            FUN_402d4604(pHVar4);
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
            DAT_402fc260 = 0;
            BVar5 = IsWindow(hWnd);
            if (BVar5 != 0) {
              EnableWindow(hWnd,1);
            }
            local_1e8 = 0;
            iVar3 = FUN_402d48fc((int)hWnd,&local_1e8);
            if (iVar3 < 0) goto LAB_402e7184;
          }
          DAT_402fc260 = 0;
          if (local_198 == 0) goto LAB_402e7184;
        }
        LoadStringW(DAT_402fc3c4,0x17b8,aWStack_b8,0x43);
        FUN_402e592c(*(HWND *)(local_1e8 + 0x520),aWStack_b8);
        StringCchCopyW(*(STRSAFE_LPWSTR *)(local_1e8 + 0x410),0x43,aWStack_b8);
        local_1e4 = 0;
        FUN_402e9ae8(local_1e8 + 0x464,3,1,auStack_180,&local_1e4);
        FUN_402ea444(local_1e8 + 0x464,local_1e8 + 0x464);
        FUN_402e9738(local_1e8 + 0x464);
        EnableWindow(*(HWND *)(local_1e8 + 0x4e0),0);
        EnableWindow(*(HWND *)(local_1e8 + 0x4f4),0);
        EnableWindow(*(HWND *)(local_1e8 + 0x4d8),0);
        DAT_402fc2a0 = 1;
      }
    }
  }
LAB_402e7184:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_30);
  return;
}



/* 402e71c0 FUN_402e71c0 */

/* Boundary evidence: original MIPS .pdata 402e71c0..402e72a3. Semantic name remains unreviewed. */

undefined4 FUN_402e71c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint local_18;
  int local_14;
  
  local_18 = 0;
  local_14 = 0;
  uVar2 = 0x80004005;
  iVar1 = FUN_402d48fc(param_1,(int *)&local_18);
  if (((-1 < iVar1) && (local_18 != 0)) && (iVar1 = FUN_402e569c(local_18,&local_14), -1 < iVar1)) {
    if (local_14 < -0x5a) {
      iVar1 = 0;
    }
    else if (local_14 < -0x51) {
      iVar1 = 1;
    }
    else if (local_14 < -0x47) {
      iVar1 = 2;
    }
    else if (local_14 < -0x43) {
      iVar1 = 3;
    }
    else {
      iVar1 = 4;
      if (-0x3a < local_14) {
        iVar1 = 5;
      }
    }
    iVar1 = FUN_402e5768(param_1,iVar1);
    if (iVar1 != 0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* 402e72a4 FUN_402e72a4 */

/* Boundary evidence: original MIPS .pdata 402e72a4..402e74d7. Semantic name remains unreviewed. */

undefined4 FUN_402e72a4(int param_1)

{
  wchar_t *pwVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  BOOL BVar5;
  LPARAM lParam;
  int iVar6;
  int iVar7;
  HANDLE hHandle;
  undefined8 uVar8;
  undefined8 uVar9;
  wchar_t *local_90;
  int local_8c;
  wchar_t awStack_88 [47];
  undefined2 local_2a;
  uint local_28;
  
  local_28 = DAT_402f65fc;
  local_90 = (wchar_t *)0x0;
  local_8c = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar2 = FUN_402d48fc(param_1,(int *)&local_90);
  pwVar1 = local_90;
  if ((-1 < iVar2) && (local_90 != (wchar_t *)0x0)) {
    wcsncpy(awStack_88,local_90,0x30);
    local_2a = 0;
    hHandle = *(HANDLE *)(pwVar1 + 0x29c);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
    while( true ) {
      iVar7 = 0;
      iVar6 = 0;
      iVar2 = 0;
      do {
        DVar3 = WaitForSingleObject(hHandle,1000);
        if (DVar3 != 0x102) goto LAB_402e74a4;
        iVar4 = FUN_402e569c((uint)awStack_88,&local_8c);
        if (iVar4 == 0) {
          iVar7 = iVar7 + 1;
          iVar6 = iVar6 + local_8c;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 5);
      uVar8 = __litodp(iVar6);
      uVar9 = __ultodp(iVar7);
      uVar8 = __dpdiv((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar9,
                      (int)((ulonglong)uVar9 >> 0x20));
      iVar2 = __dptoli((int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
      if (iVar2 < -0x5a) {
        lParam = 0;
      }
      else if (iVar2 < -0x51) {
        lParam = 1;
      }
      else if (iVar2 < -0x47) {
        lParam = 2;
      }
      else if (iVar2 < -0x43) {
        lParam = 3;
      }
      else {
        lParam = 4;
        if (-0x3a < iVar2) {
          lParam = 5;
        }
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      local_90 = (wchar_t *)0x0;
      iVar2 = FUN_402d48fc(param_1,(int *)&local_90);
      if ((iVar2 < 0) || (local_90 == (wchar_t *)0x0)) break;
      if ((*(int *)(local_90 + 0x294) != 0) &&
         (BVar5 = IsWindow(*(HWND *)(local_90 + 0x290)), BVar5 != 0)) {
        PostMessageW(*(HWND *)(local_90 + 0x290),0x40c,0,lParam);
      }
      hHandle = *(HANDLE *)(local_90 + 0x29c);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
LAB_402e74a4:
  FUN_402f41d8(local_28);
  return 0;
}



/* 402e74d8 FUN_402e74d8 */

/* Boundary evidence: original MIPS .pdata 402e74d8..402e7e83. Semantic name remains unreviewed. */

void FUN_402e74d8(uint *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  wchar_t *_Dest;
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  uint uVar4;
  wchar_t *pwVar5;
  int local_100 [2];
  WCHAR aWStack_f8 [68];
  WCHAR aWStack_70 [34];
  uint local_2c;
  
  local_2c = DAT_402f65fc;
  bVar1 = false;
  local_100[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pwVar5 = (wchar_t *)(param_1 + 0x10);
  iVar2 = FUN_402d49ac(pwVar5,local_100);
  if (iVar2 < 0) goto LAB_402e7e44;
  sVar3 = strlen((char *)(param_1 + 2));
  MultiByteToWideChar(0,0,(LPCSTR)(param_1 + 2),sVar3 + 1,aWStack_70,0x21);
  _Dest = LocalAlloc(0,0x86);
  if (_Dest == (wchar_t *)0x0) goto LAB_402e7e44;
  wcscpy(_Dest,L"");
  if (*(int *)(local_100[0] + 0x528) == 0) {
    param_2 = 0;
  }
  uVar4 = *param_1;
  if (uVar4 < 9) {
    if (uVar4 == 8) {
      LoadStringW(DAT_402fc3c4,0x17b9,aWStack_f8,0x43);
      if (param_1[0xd] == 0) {
        FUN_402e5ac8(aWStack_f8);
      }
      StringCchPrintfW(_Dest,0x43,aWStack_f8,aWStack_70,param_1[0xc]);
      FUN_402e9160(pwVar5,(byte *)0x0,param_1[0xe],param_1[0xf],_Dest);
LAB_402e7688:
      *(uint *)(local_100[0] + 0x45c) = *param_1;
      if (param_2 == 0) goto LAB_402e7dec;
      Msg = 0x40a;
      hWnd = *(HWND *)(local_100[0] + 0x520);
    }
    else {
      if (uVar4 == 1) {
        LoadStringW(DAT_402fc3c4,0x17b4,aWStack_f8,0x43);
        if (param_1[0xd] == 0) {
          FUN_402e5ac8(aWStack_f8);
        }
        StringCchPrintfW(_Dest,0x43,aWStack_f8,aWStack_70);
        FUN_402e9160(pwVar5,(byte *)0x0,param_1[0xe],param_1[0xf],_Dest);
        goto LAB_402e7688;
      }
      if (uVar4 != 2) {
        if (uVar4 == 3) {
LAB_402e7a80:
          LoadStringW(DAT_402fc3c4,0x17b5,aWStack_f8,0x43);
          if (param_1[0xd] == 0) {
            FUN_402e5ac8(aWStack_f8);
          }
          StringCchPrintfW(_Dest,0x43,aWStack_f8,aWStack_70);
          FUN_402e9160(pwVar5,(byte *)((int)param_1 + 0x29),param_1[0xe],param_1[0xf],_Dest);
          *(uint *)(local_100[0] + 0x45c) = *param_1;
          FUN_402eb73c();
          if (param_2 != 0) {
            PostMessageW(*(HWND *)(local_100[0] + 0x520),0x40a,0,0);
            EnableWindow(*(HWND *)(local_100[0] + 0x4f4),1);
            EnableWindow(*(HWND *)(local_100[0] + 0x4d8),1);
            PostMessageW(*(HWND *)(local_100[0] + 0x520),0x40d,0,0);
          }
          wcscpy((wchar_t *)(local_100[0] + 0x414),aWStack_70);
          *(uint *)(local_100[0] + 0x458) = param_1[0xd];
          if ((*param_1 == 3) && (*(int *)(local_100[0] + 0x460) != 0)) goto LAB_402e7d98;
        }
        else {
          if (uVar4 != 4) {
            if (uVar4 == 5) {
              LoadStringW(DAT_402fc3c4,0x17b7,aWStack_f8,0x43);
              if (param_1[0xd] == 0) {
                FUN_402e5ac8(aWStack_f8);
              }
              StringCchPrintfW(_Dest,0x43,aWStack_f8,aWStack_70);
              FUN_402e9160(pwVar5,(byte *)((int)param_1 + 0x29),param_1[0xe],param_1[0xf],_Dest);
            }
            else {
              if (uVar4 == 6) {
                LoadStringW(DAT_402fc3c4,0x17ba,aWStack_f8,0x43);
                if (param_1[0xd] == 0) {
                  FUN_402e5ac8(aWStack_f8);
                }
                StringCchPrintfW(_Dest,0x43,aWStack_f8,aWStack_70);
                FUN_402e9160(pwVar5,(byte *)((int)param_1 + 0x29),param_1[0xe],param_1[0xf],_Dest);
                if (param_2 != 0) {
                  if ((*(int *)(local_100[0] + 0x45c) == 0xb) &&
                     (*(int *)(local_100[0] + 0x460) != 0)) {
                    bVar1 = true;
                  }
                  PostMessageW(*(HWND *)(local_100[0] + 0x520),0x40a,0,0);
                }
                *(uint *)(local_100[0] + 0x45c) = *param_1;
                wcscpy((wchar_t *)(local_100[0] + 0x414),aWStack_70);
                *(uint *)(local_100[0] + 0x458) = param_1[0xd];
                if (*(int *)(local_100[0] + 0x460) != 0) {
                  bVar1 = true;
                }
                goto LAB_402e7d90;
              }
              if (uVar4 != 7) goto LAB_402e7dec;
              LoadStringW(DAT_402fc3c4,0x17bd,aWStack_f8,0x43);
              if (param_1[0xd] == 0) {
                FUN_402e5ac8(aWStack_f8);
              }
              StringCchPrintfW(_Dest,0x43,aWStack_f8,aWStack_70);
              FUN_402e9160(pwVar5,(byte *)0x0,param_1[0xe],param_1[0xf],_Dest);
            }
            goto LAB_402e7688;
          }
          LoadStringW(DAT_402fc3c4,0x17c0,aWStack_f8,0x43);
          FUN_402e9160(pwVar5,(byte *)0x0,param_1[0xe],param_1[0xf],aWStack_f8);
        }
        goto LAB_402e7dec;
      }
      LoadStringW(DAT_402fc3c4,0x17b6,aWStack_f8,0x43);
      if (param_1[0xd] == 0) {
        FUN_402e5ac8(aWStack_f8);
      }
      StringCchPrintfW(_Dest,0x43,aWStack_f8,aWStack_70);
      FUN_402e9160(pwVar5,(byte *)0x0,param_1[0xe],param_1[0xf],_Dest);
      *(uint *)(local_100[0] + 0x45c) = *param_1;
      if (param_2 == 0) goto LAB_402e7dec;
      PostMessageW(*(HWND *)(local_100[0] + 0x520),0x40a,0,0);
      EnableWindow(*(HWND *)(local_100[0] + 0x4f4),1);
      EnableWindow(*(HWND *)(local_100[0] + 0x4d8),1);
      hWnd = *(HWND *)(local_100[0] + 0x520);
      Msg = 0x40d;
    }
    wParam = 0;
    lParam = 0;
LAB_402e76ac:
    PostMessageW(hWnd,Msg,wParam,lParam);
  }
  else if (uVar4 == 9) {
    LoadStringW(DAT_402fc3c4,0x17b9,aWStack_f8,0x43);
    if (param_1[0xd] == 0) {
      FUN_402e5ac8(aWStack_f8);
    }
    StringCchPrintfW(_Dest,0x43,aWStack_f8,aWStack_70,param_1[0xc]);
    FUN_402e9160(pwVar5,(byte *)0x0,param_1[0xe],param_1[0xf],_Dest);
    *(uint *)(local_100[0] + 0x45c) = *param_1;
    if (param_2 != 0) {
      PostMessageW(*(HWND *)(local_100[0] + 0x520),0x40a,0,0);
LAB_402e7d90:
      if (bVar1) {
LAB_402e7d98:
        if (*(int *)(local_100[0] + 0x460) != 0) {
          LoadStringW(DAT_402fc3c4,0x17bb,aWStack_f8,0x43);
          if (param_1[0xd] == 0) {
            FUN_402e5ac8(aWStack_f8);
          }
          StringCchPrintfW(_Dest,0x43,aWStack_f8,local_100[0] + 0x414);
        }
      }
    }
  }
  else {
    if (uVar4 != 10) {
      if (uVar4 == 0xb) {
        LoadStringW(DAT_402fc3c4,0x17bc,aWStack_f8,0x43);
        if (param_1[0xd] == 0) {
          FUN_402e5ac8(aWStack_f8);
        }
        StringCchPrintfW(_Dest,0x43,aWStack_f8,aWStack_70);
        FUN_402e9160(pwVar5,(byte *)((int)param_1 + 0x29),param_1[0xe],param_1[0xf],_Dest);
        goto LAB_402e7688;
      }
      if (uVar4 != 0xc) {
        if (uVar4 == 0xd) goto LAB_402e7a80;
        if (uVar4 == 0xe) {
          if (param_2 != 0) {
            EnableWindow(*(HWND *)(local_100[0] + 0x4f4),1);
            EnableWindow(*(HWND *)(local_100[0] + 0x4d8),1);
            PostMessageW(*(HWND *)(local_100[0] + 0x520),0x40d,0,0);
            goto LAB_402e7d98;
          }
        }
        else if (uVar4 == 0xffffffff) {
          LoadStringW(DAT_402fc3c4,0x17bf,aWStack_f8,0x43);
          FUN_402e9160(pwVar5,(byte *)0x0,param_1[0xe],param_1[0xf],aWStack_f8);
        }
        goto LAB_402e7dec;
      }
      if (((((DAT_402fc2a4 == 0) || (*(int *)(local_100[0] + 0x528) != 0)) ||
           (iVar2 = *(int *)(local_100[0] + 0x45c), iVar2 == 1)) || ((iVar2 == 3 || (iVar2 == 5))))
         || ((iVar2 == 6 || (iVar2 == 0xb)))) goto LAB_402e7dec;
      FUN_402e64f0(local_100[0]);
      iVar2 = FUN_402e5098(local_100[0] + 0x464);
      if (iVar2 != 0) goto LAB_402e7dec;
      lParam = 0x203;
      hWnd = *(HWND *)(local_100[0] + 0x514);
      wParam = 1;
      Msg = 0x8064;
      goto LAB_402e76ac;
    }
    LoadStringW(DAT_402fc3c4,0x17be,_Dest,0x43);
    *(uint *)(local_100[0] + 0x45c) = *param_1;
    if (param_2 != 0) {
      PostMessageW(*(HWND *)(local_100[0] + 0x520),0x40a,0,0);
      SetTimer(*(HWND *)(local_100[0] + 0x520),1,5000,(TIMERPROC)0x0);
    }
    LoadStringW(DAT_402fc3c4,0x17c1,aWStack_f8,0x43);
    FUN_402e9160(pwVar5,(byte *)0x0,param_1[0xe],param_1[0xf],aWStack_f8);
    wcscpy((wchar_t *)(local_100[0] + 0x414),L"");
    *(undefined4 *)(local_100[0] + 0x458) = 0;
  }
LAB_402e7dec:
  iVar2 = wcscmp(_Dest,L"");
  if ((iVar2 == 0) ||
     (StringCchCopyW(*(STRSAFE_LPWSTR *)(local_100[0] + 0x410),0x43,_Dest), param_2 == 0)) {
    LocalFree(_Dest);
  }
  else {
    PostMessageW(*(HWND *)(local_100[0] + 0x520),0x40b,0,(LPARAM)_Dest);
  }
LAB_402e7e44:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_2c);
  return;
}



/* 402e7e84 FUN_402e7e84 */

/* Boundary evidence: original MIPS .pdata 402e7e84..402e8027. Semantic name remains unreviewed. */

void FUN_402e7e84(void)

{
  int iVar1;
  STRSAFE_LPCWSTR pszDest;
  size_t sVar2;
  int iVar3;
  wchar_t *_Str1;
  CHAR aCStack_d8 [40];
  WCHAR aWStack_b0 [68];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  for (iVar3 = DAT_402fc3c8; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x540)) {
    if (((*(int *)(iVar3 + 0x524) != 0) && (*(int *)(iVar3 + 0x460) == 1)) &&
       ((*(int *)(iVar3 + 0x45c) == 6 || (*(int *)(iVar3 + 0x45c) == 3)))) {
      _Str1 = (wchar_t *)(iVar3 + 0x414);
      iVar1 = wcscmp(_Str1,L"");
      if (iVar1 != 0) {
        pszDest = LocalAlloc(0,0x86);
        if (pszDest == (STRSAFE_LPCWSTR)0x0) break;
        LoadStringW(DAT_402fc3c4,0x17bb,aWStack_b0,0x43);
        sVar2 = wcslen(_Str1);
        WideCharToMultiByte(0,0,_Str1,sVar2 + 1,aCStack_d8,0x21,(LPCSTR)0x0,(LPBOOL)0x0);
        if (*(int *)(iVar3 + 0x458) == 0) {
          FUN_402e5ac8(aWStack_b0);
        }
        StringCchPrintfW(pszDest,0x43,aWStack_b0,_Str1);
        StringCchCopyW(*(STRSAFE_LPWSTR *)(iVar3 + 0x410),0x43,pszDest);
        PostMessageW(*(HWND *)(iVar3 + 0x520),0x40b,0,(LPARAM)pszDest);
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_28);
  return;
}



/* 402e8028 FUN_402e8028 */

/* Boundary evidence: original MIPS .pdata 402e8028..402e815b. Semantic name remains unreviewed. */

void FUN_402e8028(HWND param_1)

{
  HWND pHVar1;
  int iVar2;
  LRESULT LVar3;
  int local_48 [2];
  undefined4 local_40;
  LRESULT local_3c [7];
  int local_20;
  
  local_48[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pHVar1 = GetParent(param_1);
  iVar2 = FUN_402d48fc((int)pHVar1,local_48);
  if (-1 < iVar2) {
    LVar3 = FUN_402d7608(*(HWND *)(local_48[0] + 0x4d8),0xffffffff,2);
    if (LVar3 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      pHVar1 = GetParent(param_1);
      FUN_402e697c((int)pHVar1);
    }
    else {
      if (LVar3 < 1) goto LAB_402e813c;
      memset(local_3c,0,0x28);
      local_40 = 4;
      local_3c[0] = LVar3;
      SendMessageW(*(HWND *)(local_48[0] + 0x4d8),0x104b,0,(LPARAM)&local_40);
      iVar2 = FUN_402e988c(*(int *)(local_48[0] + 0x50c),local_20 + 0x10,(int *)0x0);
      if (iVar2 == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
        FUN_402e6e90(param_1);
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
        FUN_402e5448(param_1);
      }
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  }
LAB_402e813c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402e815c FUN_402e815c */

/* Boundary evidence: original MIPS .pdata 402e815c..402e8607. Semantic name remains unreviewed. */

void FUN_402e815c(HWND param_1)

{
  HWND pHVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  WPARAM wParam;
  int iVar5;
  HANDLE pvVar6;
  int local_b8 [2];
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a8;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined *local_7c;
  undefined4 local_74;
  undefined4 local_70;
  tagRECT tStack_60;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  undefined4 local_40;
  
  local_b8[0] = 0;
  local_b0 = 0;
  memset(&local_ac,0,0x1c);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  DAT_402fc260 = 0;
  DAT_402fc2a0 = 0;
  LoadStringW(DAT_402fc3c4,0x17c8,(LPWSTR)&DAT_402fc2c0,0xf);
  LoadStringW(DAT_402fc3c4,0x17c9,(LPWSTR)&DAT_402fc2e0,0xf);
  LoadStringW(DAT_402fc3c4,0x17ca,(LPWSTR)&DAT_402fc240,0xf);
  LoadStringW(DAT_402fc3c4,0x17c3,(LPWSTR)&DAT_402fc320,0xf);
  DAT_402fc300 = LoadStringW(DAT_402fc3c4,0x17c2,(LPWSTR)&DAT_402fc280,0xf);
  pHVar1 = GetParent(param_1);
  iVar2 = FUN_402d48fc((int)pHVar1,local_b8);
  if (-1 < iVar2) {
    *(HWND *)(local_b8[0] + 0x520) = param_1;
    EventModify(*(undefined4 *)(local_b8[0] + 0x538),2);
    pHVar1 = GetDlgItem(param_1,0x7d4);
    *(HWND *)(local_b8[0] + 0x4d8) = pHVar1;
    pHVar1 = GetDlgItem(param_1,0x7d8);
    *(HWND *)(local_b8[0] + 0x4f4) = pHVar1;
    pHVar1 = GetDlgItem(param_1,0x1781);
    *(HWND *)(local_b8[0] + 0x4e0) = pHVar1;
    pHVar1 = GetDlgItem(param_1,0x4fe);
    *(HWND *)(local_b8[0] + 0x4fc) = pHVar1;
    pHVar1 = GetDlgItem(param_1,0x17c4);
    *(HWND *)(local_b8[0] + 0x4e4) = pHVar1;
    *(undefined4 *)(local_b8[0] + 0x4dc) = 0;
    uVar3 = GetWindowLongW(*(HWND *)(local_b8[0] + 0x4d8),-0x10);
    SetWindowLongW(*(HWND *)(local_b8[0] + 0x4d8),-0x10,uVar3 | 0x40);
    uVar4 = ImageList_LoadImage(DAT_402fc3c4,0x4f9,0x10,0,0xffffffff,0,0);
    *(undefined4 *)(local_b8[0] + 0x500) = uVar4;
    SendMessageW(*(HWND *)(local_b8[0] + 0x4d8),0x1003,1,*(LPARAM *)(local_b8[0] + 0x500));
    local_b0 = 3;
    local_ac = 0;
    GetClientRect(*(HWND *)(local_b8[0] + 0x4d8),&tStack_60);
    local_a8 = GetSystemMetrics(2);
    local_a8 = tStack_60.right - local_a8;
    SendMessageW(*(HWND *)(local_b8[0] + 0x4d8),0x1061,0,(LPARAM)&local_b0);
    SendMessageW(*(HWND *)(local_b8[0] + 0x4d8),0x1036,0x20,0x20);
    memset(&local_90,0,0x2c);
    local_90 = 7;
    local_8c = 0;
    local_88 = 0;
    local_7c = &DAT_402fc320;
    local_74 = 8;
    local_70 = 0;
    wParam = SendMessageW(*(HWND *)(local_b8[0] + 0x4d8),0x104d,0,(LPARAM)&local_90);
    if (wParam != 0xffffffff) {
      local_40 = 3;
      local_44 = 3;
      SendMessageW(*(HWND *)(local_b8[0] + 0x4d8),0x102b,wParam,(LPARAM)auStack_50);
    }
    if ((*(int *)(local_b8[0] + 0x4b4) != 0) ||
       (iVar2 = FUN_402e9698(local_b8[0],(undefined4 *)(local_b8[0] + 0x464)), iVar2 != 0)) {
      *(undefined4 *)(local_b8[0] + 0x504) = *(undefined4 *)(local_b8[0] + 0x484);
      if ((*(uint *)(local_b8[0] + 0x4d4) & 0x4000000) == 0) {
        pvVar6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402e4750,param_1,0,(LPDWORD)0x0);
        *(HANDLE *)(local_b8[0] + 0x534) = pvVar6;
        if (*(int *)(local_b8[0] + 0x534) == 0) goto LAB_402e85dc;
      }
      else {
        FUN_402e9ce0(local_b8[0] + 0x464,*(uint **)(local_b8[0] + 0x4a0));
        FUN_402e9e14(local_b8[0] + 0x464,*(uint **)(local_b8[0] + 0x4a8));
        FUN_402e9f68(local_b8[0] + 0x464,local_b8[0] + 0x464);
        FUN_402e6328(local_b8[0]);
        EnableWindow(*(HWND *)(local_b8[0] + 0x4d8),1);
        SetTimer(param_1,1,2000,(TIMERPROC)0x0);
      }
      SendMessageW(*(HWND *)(local_b8[0] + 0x4fc),0xf1,(uint)(DAT_402fc2a4 != 0),0);
      FUN_402e660c(param_1);
      if ((*(uint *)(local_b8[0] + 0x504) & 0x8000) == 0) {
        EnableWindow(*(HWND *)(local_b8[0] + 0x4e0),0);
        EnableWindow(*(HWND *)(local_b8[0] + 0x4e4),0);
      }
      FUN_402e529c(*(HWND *)(local_b8[0] + 0x4d8));
      iVar2 = local_b8[0];
      iVar5 = wcscmp(*(wchar_t **)(local_b8[0] + 0x410),L"");
      if (iVar5 != 0) {
        FUN_402e592c(param_1,*(LPCWSTR *)(iVar2 + 0x410));
      }
      pHVar1 = GetParent(param_1);
      FUN_402e71c0((int)pHVar1);
      pHVar1 = GetParent(param_1);
      pvVar6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402e72a4,pHVar1,0,(LPDWORD)0x0);
      *(HANDLE *)(local_b8[0] + 0x530) = pvVar6;
    }
  }
LAB_402e85dc:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402e8608 FUN_402e8608 */

/* Boundary evidence: original MIPS .pdata 402e8608..402e87ff. Semantic name remains unreviewed. */

undefined4 FUN_402e8608(void)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  undefined1 auStack_4d8 [4];
  undefined1 auStack_4d4 [4];
  HANDLE local_4d0;
  int local_4cc;
  undefined4 local_4c8;
  undefined4 local_4c4;
  undefined4 local_4c0;
  undefined4 local_4bc;
  undefined4 local_4b8;
  uint local_4b0;
  undefined1 auStack_4ac [580];
  undefined1 auStack_268 [584];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  local_4b0 = 0;
  memset(auStack_4ac,0,0x244);
  local_4c4 = 2;
  local_4c0 = 0x10;
  local_4c8 = 0x14;
  local_4bc = 0x248;
  local_4b8 = 1;
  iVar1 = CreateMsgQueue(L"WzcEventLoggingQueue",&local_4c8);
  if (iVar1 != 0) {
    iVar2 = ReadMsgQueue(iVar1,auStack_268,0x248,auStack_4d4,1,auStack_4d8);
    while (iVar2 != 0) {
      FUN_402e74d8(&local_4b0,0);
      memcpy(&local_4b0,auStack_268,0x248);
      iVar2 = ReadMsgQueue(iVar1,auStack_268,0x248,auStack_4d4,1,auStack_4d8);
    }
    if (local_4b0 != 0) {
      FUN_402e74d8(&local_4b0,1);
    }
    FUN_402e7e84();
    local_4d0 = DAT_402fc228;
    local_4cc = iVar1;
    DVar3 = WaitForMultipleObjects(2,&local_4d0,0,0xffffffff);
    while (DVar3 == 1) {
      iVar2 = ReadMsgQueue(iVar1,&local_4b0,0x248,auStack_4d4,1,auStack_4d8);
      while (iVar2 != 0) {
        FUN_402e74d8(&local_4b0,1);
        Sleep(500);
        iVar2 = ReadMsgQueue(iVar1,&local_4b0,0x248,auStack_4d4,1,auStack_4d8);
      }
      DVar3 = WaitForMultipleObjects(2,&local_4d0,0,0xffffffff);
    }
    CloseMsgQueue(iVar1);
  }
  FUN_402f41d8(local_20);
  return 0;
}



/* 402e8800 FUN_402e8800 */

/* Boundary evidence: original MIPS .pdata 402e8800..402e8bdb. Semantic name remains unreviewed. */

undefined4 FUN_402e8800(HWND param_1,uint param_2,short param_3,LPCWSTR param_4)

{
  HWND pHVar1;
  int iVar2;
  DWORD DVar3;
  HANDLE pvVar4;
  short extraout_var;
  int local_18 [2];
  
  local_18[0] = 0;
  if (param_2 < 0x40b) {
    if (param_2 == 0x40a) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      pHVar1 = GetParent(param_1);
      iVar2 = FUN_402d48fc((int)pHVar1,local_18);
      if ((-1 < iVar2) && (local_18[0] != 0)) {
        FUN_402e64f0(local_18[0]);
      }
    }
    else {
      if (param_2 == 0x4e) {
        iVar2 = *(int *)(param_4 + 4);
        if (iVar2 != -0xcb) {
          if (iVar2 != -0xca) {
            if (iVar2 == -0x65) {
              FUN_402e660c(param_1);
              return 0;
            }
            if (iVar2 != -5) {
              if (iVar2 == -3) {
                FUN_402e8028(param_1);
                return 0;
              }
              if (iVar2 != -2) {
                return 0;
              }
              GetKeyState(0x12);
              if (-1 < extraout_var) {
                return 0;
              }
            }
            FUN_402e6bf8(param_1);
            return 0;
          }
          FUN_402e4e4c(param_1);
        }
        FUN_402e4efc(param_1);
        FUN_402e5180(param_1);
        return 0;
      }
      if (param_2 == 0x110) {
        FUN_402e815c(param_1);
        return 1;
      }
      if (param_2 == 0x111) {
        if (param_3 == 0x7d8) {
          FUN_402e678c(param_1);
          return 0;
        }
        if (param_3 != 0x1781) {
          if (param_3 == 0x17c4) {
            FUN_402e9324();
            return 0;
          }
          if (param_3 == 0x17ed) {
            FUN_402e5448(param_1);
            return 0;
          }
          if (param_3 != 0x17ee) {
            if (param_3 != 0x17ef) {
              return 0;
            }
            FUN_402e6d90(param_1);
            return 0;
          }
        }
        FUN_402e6e90(param_1);
        return 0;
      }
      if (param_2 != 0x113) {
        return 0;
      }
      KillTimer(param_1,1);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      pHVar1 = GetParent(param_1);
      iVar2 = FUN_402d48fc((int)pHVar1,local_18);
      if ((-1 < iVar2) && (local_18[0] != 0)) {
        if (*(HANDLE *)(local_18[0] + 0x534) != (HANDLE)0x0) {
          DVar3 = WaitForSingleObject(*(HANDLE *)(local_18[0] + 0x534),0);
          if (DVar3 == 0x102) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
            SetTimer(param_1,1,2000,(TIMERPROC)0x0);
            return 0;
          }
          CloseHandle(*(HANDLE *)(local_18[0] + 0x534));
        }
        pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402e4750,param_1,0,(LPDWORD)0x0);
        *(HANDLE *)(local_18[0] + 0x534) = pvVar4;
        if (*(int *)(local_18[0] + 0x534) == 0) {
          return 0;
        }
      }
    }
  }
  else {
    if (param_2 == 0x40b) {
      FUN_402e592c(param_1,param_4);
      LocalFree(param_4);
      return 0;
    }
    if (param_2 == 0x40c) {
      pHVar1 = GetParent(param_1);
      FUN_402e5768((int)pHVar1,(int)param_4);
      return 0;
    }
    if (param_2 != 0x40d) {
      return 0;
    }
    FUN_402e660c(param_1);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
    if (DAT_402fc2a0 != 0) {
      DAT_402fc2a0 = 0;
      pHVar1 = GetParent(param_1);
      iVar2 = FUN_402d48fc((int)pHVar1,local_18);
      if ((-1 < iVar2) && (local_18[0] != 0)) {
        FUN_402e529c(*(HWND *)(local_18[0] + 0x4d8));
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return 0;
}



/* 402e8bdc FUN_402e8bdc */

/* Boundary evidence: original MIPS .pdata 402e8bdc..402e8c47. Semantic name remains unreviewed. */

LRESULT FUN_402e8bdc(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  
  if (param_2 == 2) {
    PostQuitMessage(0);
  }
  else {
    if (param_2 != 0x10) {
      if (param_2 != 0x110) {
        LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
        return LVar1;
      }
      return 1;
    }
    DestroyWindow(param_1);
  }
  return 0;
}



/* 402e8c48 FUN_402e8c48 */

/* Boundary evidence: original MIPS .pdata 402e8c48..402e8d77. Semantic name remains unreviewed. */

void FUN_402e8c48(void)

{
  HWND hWnd;
  wchar_t *_Dest;
  int iVar1;
  
  if (((DAT_402fbc40 != -1) && (hWnd = GetDlgItem(DAT_402fad54,0x17c6), hWnd != (HWND)0x0)) &&
     (_Dest = LocalAlloc(0,0xee2), _Dest != (wchar_t *)0x0)) {
    wcscpy(_Dest,L"");
    iVar1 = DAT_402fbc3c;
    if (DAT_402fbc3c == -1) {
      iVar1 = 0;
    }
    if (iVar1 != DAT_402fbc40) {
      do {
        if ((iVar1 == 0xf) && (iVar1 = 0, DAT_402fbc40 == 0)) break;
        wcscat(_Dest,(wchar_t *)(&DAT_402fad58 + iVar1 * 0xfe));
        wcscat(_Dest,L"\r\n");
        iVar1 = iVar1 + 1;
      } while (iVar1 != DAT_402fbc40);
    }
    wcscat(_Dest,(wchar_t *)(&DAT_402fad58 + DAT_402fbc40 * 0xfe));
    SetWindowTextW(hWnd,_Dest);
    LocalFree(_Dest);
  }
  return;
}



/* 402e8d78 FUN_402e8d78 */

/* Boundary evidence: original MIPS .pdata 402e8d78..402e8d9b. Semantic name remains unreviewed. */

void FUN_402e8d78(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  return;
}



/* 402e8d9c FUN_402e8d9c */

/* Boundary evidence: original MIPS .pdata 402e8d9c..402e8dbf. Semantic name remains unreviewed. */

void FUN_402e8d9c(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  return;
}



/* 402e8dc0 FUN_402e8dc0 */

/* Boundary evidence: original MIPS .pdata 402e8dc0..402e8edf. Semantic name remains unreviewed. */

undefined4 FUN_402e8dc0(void)

{
  int iVar1;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  BOOL BVar2;
  LPCWSTR lpName;
  MSG MStack_30;
  
  iVar1 = GetSystemMetrics(0);
  lpName = (LPCWSTR)0x183b;
  if (0x1df < iVar1) {
    lpName = (LPCWSTR)0x17c5;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  if (DAT_402fbc44 == 0) {
    DAT_402fbc44 = 1;
    hResInfo = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
    lpTemplate = LoadResource(DAT_402fc3c4,hResInfo);
    DAT_402fad54 = CreateDialogIndirectParamW(DAT_402fc3c4,lpTemplate,(HWND)0x0,FUN_402e8bdc,0);
    FUN_402e8c48();
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
    while (BVar2 = GetMessageW(&MStack_30,(HWND)0x0,0,0), BVar2 != 0) {
      TranslateMessage(&MStack_30);
      DispatchMessageW(&MStack_30);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
    DAT_402fbc44 = 0;
  }
  else if (DAT_402fbc44 == 1) {
    SetForegroundWindow(DAT_402fad54);
  }
  DAT_402fbc5c = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  return 0;
}



/* 402e8ee0 FUN_402e8ee0 */

/* Boundary evidence: original MIPS .pdata 402e8ee0..402e902f. Semantic name remains unreviewed. */

void FUN_402e8ee0(void)

{
  LSTATUS LVar1;
  DWORD local_20;
  HKEY local_1c;
  DWORD local_18 [2];
  
  local_20 = 0;
  local_18[0] = 0;
  local_1c = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\BuiltIn\\Ethman\\Log",0,0,&local_1c);
  if (LVar1 == 0) {
    local_20 = 0xee2;
    LVar1 = RegQueryValueExW(local_1c,L"QueueData",(LPDWORD)0x0,local_18,&DAT_402fad58,&local_20);
    if (LVar1 == 0) {
      local_20 = 4;
      LVar1 = RegQueryValueExW(local_1c,L"NewIndex",(LPDWORD)0x0,local_18,(LPBYTE)&DAT_402fbc40,
                               &local_20);
      if (LVar1 == 0) {
        local_20 = 4;
        LVar1 = RegQueryValueExW(local_1c,L"OldIndex",(LPDWORD)0x0,local_18,(LPBYTE)&DAT_402fbc3c,
                                 &local_20);
        if (LVar1 == 0) goto LAB_402e8ffc;
      }
      DAT_402fbc40 = 0xffffffff;
      DAT_402fbc3c = 0xffffffff;
    }
  }
LAB_402e8ffc:
  if (local_1c != (HKEY)0x0) {
    RegCloseKey(local_1c);
  }
  return;
}



/* 402e9030 FUN_402e9030 */

/* Boundary evidence: original MIPS .pdata 402e9030..402e915f. Semantic name remains unreviewed. */

void FUN_402e9030(void)

{
  LSTATUS LVar1;
  HKEY local_18 [2];
  
  local_18[0] = (HKEY)0x0;
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"Drivers\\BuiltIn\\Ethman\\Log",0,(LPWSTR)0x0,0,0x20006,
                          (LPSECURITY_ATTRIBUTES)0x0,local_18,(LPDWORD)0x0);
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_18[0],L"QueueData",0,3,&DAT_402fad58,0xee2);
    if (LVar1 == 0) {
      LVar1 = RegSetValueExW(local_18[0],L"NewIndex",0,4,(BYTE *)&DAT_402fbc40,4);
      if (LVar1 == 0) {
        RegSetValueExW(local_18[0],L"OldIndex",0,4,(BYTE *)&DAT_402fbc3c,4);
      }
    }
  }
  if (local_18[0] != (HKEY)0x0) {
    RegCloseKey(local_18[0]);
  }
  return;
}



/* 402e9160 FUN_402e9160 */

/* Boundary evidence: original MIPS .pdata 402e9160..402e9323. Semantic name remains unreviewed. */

undefined4
FUN_402e9160(undefined4 param_1,byte *param_2,DWORD param_3,DWORD param_4,undefined4 param_5)

{
  FILETIME local_res8;
  _FILETIME _Stack_28;
  _SYSTEMTIME _Stack_20;
  
  local_res8.dwLowDateTime = param_3;
  local_res8.dwHighDateTime = param_4;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  if (DAT_402fbc40 - DAT_402fbc3c == -1) {
    DAT_402fbc40 = DAT_402fbc3c;
    if (DAT_402fbc3c != 0xe) {
      DAT_402fbc3c = DAT_402fbc3c + 1;
      goto LAB_402e920c;
    }
LAB_402e91e0:
    DAT_402fbc3c = 0;
  }
  else {
    if (DAT_402fbc3c == -1) {
      if (DAT_402fbc40 != -1) {
        DAT_402fbc40 = DAT_402fbc40 + 1;
        goto LAB_402e91e0;
      }
    }
    else {
      if (DAT_402fbc40 != 0xe) {
        DAT_402fbc40 = DAT_402fbc40 + 1;
        goto LAB_402e920c;
      }
      DAT_402fbc3c = DAT_402fbc3c + 1;
    }
    DAT_402fbc40 = 0;
  }
LAB_402e920c:
  FileTimeToLocalFileTime(&local_res8,&_Stack_28);
  FileTimeToSystemTime(&_Stack_28,&_Stack_20);
  if (param_2 == (byte *)0x0) {
    _snwprintf((wchar_t *)(&DAT_402fad58 + DAT_402fbc40 * 0xfe),0x7f,L"[%02d:%02d:%02d - %s] %s",
               (uint)_Stack_20.wHour,(uint)_Stack_20.wMinute,(uint)_Stack_20.wSecond,param_1,param_5
              );
  }
  else {
    _snwprintf((wchar_t *)(&DAT_402fad58 + DAT_402fbc40 * 0xfe),0x7f,
               L"[%02d:%02d:%02d - %s] %s - AP [%02x-%02x-%02x-%02x-%02x-%02x]",
               (uint)_Stack_20.wHour,(uint)_Stack_20.wMinute,(uint)_Stack_20.wSecond,param_1,param_5
               ,(uint)*param_2,(uint)param_2[1],(uint)param_2[2],(uint)param_2[3],(uint)param_2[4],
               (uint)param_2[5]);
  }
  if (DAT_402fbc44 == 1) {
    FUN_402e8c48();
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  return 0;
}



/* 402e9324 FUN_402e9324 */

/* Boundary evidence: original MIPS .pdata 402e9324..402e9387. Semantic name remains unreviewed. */

void FUN_402e9324(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  if (DAT_402fbc5c == (HANDLE)0x0) {
    DAT_402fbc5c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402e8dc0,(LPVOID)0x0,0,(LPDWORD)0x0
                               );
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  return;
}



/* 402e9388 FUN_402e9388 */

/* Boundary evidence: original MIPS .pdata 402e9388..402e93d7. Semantic name remains unreviewed. */

undefined4 FUN_402e9388(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  DAT_402fbc40 = 0xffffffff;
  DAT_402fbc3c = 0xffffffff;
  FUN_402e8ee0();
  DAT_402fbc44 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  return 0;
}



/* 402e93d8 FUN_402e93d8 */

/* Boundary evidence: original MIPS .pdata 402e93d8..402e944f. Semantic name remains unreviewed. */

void FUN_402e93d8(void)

{
  HANDLE hHandle;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  FUN_402e9030();
  PostMessageW(DAT_402fad54,0x10,0,0);
  hHandle = DAT_402fbc5c;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fbc48);
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
  }
  return;
}



/* 402e9450 FUN_402e9450 */

/* Boundary evidence: original MIPS .pdata 402e9450..402e9633. Semantic name remains unreviewed. */

undefined4 FUN_402e9450(void)

{
  undefined4 uVar1;
  HMODULE hLibModule;
  
  if (DAT_402fbc68 == 0) {
    hLibModule = LoadLibraryW(L"wzcsapi.dll");
    if (hLibModule != (HMODULE)0x0) {
      DAT_402fc20c = GetProcAddressW(hLibModule,L"WZCQueryInterfaceEx");
      DAT_402fc224 = GetProcAddressW(hLibModule,L"WZCSetInterfaceEx");
      DAT_402fc220 = GetProcAddressW(hLibModule,L"WZCRefreshInterfaceEx");
      DAT_402fc210 = GetProcAddressW(hLibModule,L"WZCEnumEapExtensions");
      DAT_402fc214 = GetProcAddressW(hLibModule,L"WZCDeleteIntfObjEx");
      DAT_402fc218 = GetProcAddressW(hLibModule,L"WZCQueryContext");
      DAT_402fc21c = GetProcAddressW(hLibModule,L"WZCSetContext");
      DAT_402fc208 = GetProcAddressW(hLibModule,L"WZCPassword2Key");
      if ((((DAT_402fc20c != 0) && (DAT_402fc224 != 0)) && (DAT_402fc220 != 0)) &&
         (((DAT_402fc210 != 0 && (DAT_402fc214 != 0)) &&
          ((DAT_402fc21c != 0 && (DAT_402fc218 != 0)))))) {
        DAT_402fbc68 = 1;
        return 1;
      }
      FreeLibrary(hLibModule);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 402e9634 FUN_402e9634 */

undefined4 FUN_402e9634(int *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 != (int *)0x0) {
    puVar1 = (uint *)(param_1 + 1);
    uVar3 = 0;
    if (*puVar1 != 0) {
      do {
        iVar2 = param_1[2];
        if (((iVar2 == 3) || (iVar2 == 4)) && (param_1[3] == 6)) {
          return 1;
        }
        uVar3 = uVar3 + 1;
        param_1 = param_1 + 2;
      } while (uVar3 < *puVar1);
    }
  }
  return 0;
}



/* 402e9698 FUN_402e9698 */

/* Boundary evidence: original MIPS .pdata 402e9698..402e9737. Semantic name remains unreviewed. */

undefined4 FUN_402e9698(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  *param_2 = param_1;
  iVar1 = (*DAT_402fc20c)(0,0x7fffffff,param_2,param_2 + 0x1c);
  if (iVar1 == 0) {
    if ((param_2[8] & 0x2000) != 0) {
      if ((int)param_2[6] < 0) {
        param_2[6] = 0;
      }
      if ((int)param_2[5] < 0) {
        param_2[5] = 0;
      }
      return 1;
    }
    (*DAT_402fc214)(param_2);
  }
  return 0;
}



/* 402e9738 FUN_402e9738 */

/* Boundary evidence: original MIPS .pdata 402e9738..402e977f. Semantic name remains unreviewed. */

bool FUN_402e9738(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_10 [8];
  
  iVar1 = (*DAT_402fc224)(0,0x4ffff,param_1,auStack_10);
  return iVar1 == 0;
}



/* 402e9780 FUN_402e9780 */

/* Boundary evidence: original MIPS .pdata 402e9780..402e97fb. Semantic name remains unreviewed. */

HLOCAL FUN_402e9780(undefined4 param_1,void *param_2)

{
  HLOCAL pvVar1;
  
  pvVar1 = LocalAlloc(0x40,0xd4);
  if (pvVar1 == (HLOCAL)0x0) {
    pvVar1 = (HLOCAL)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 0xc) = param_1;
    memcpy((void *)((int)pvVar1 + 0x10),param_2,0xc4);
    *(HLOCAL *)((int)pvVar1 + 4) = pvVar1;
    *(HLOCAL *)pvVar1 = pvVar1;
    *(undefined4 *)((int)pvVar1 + 8) = 0xffffffff;
  }
  return pvVar1;
}



/* 402e97fc FUN_402e97fc */

/* Boundary evidence: original MIPS .pdata 402e97fc..402e982b. Semantic name remains unreviewed. */

void FUN_402e97fc(int *param_1)

{
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  LocalFree(param_1);
  return;
}



/* 402e982c FUN_402e982c */

/* Boundary evidence: original MIPS .pdata 402e982c..402e988b. Semantic name remains unreviewed. */

undefined4 FUN_402e982c(int param_1,int param_2)

{
  int iVar1;
  size_t _Size;
  undefined4 uVar2;
  
  if (((*(int *)(param_1 + 0x60) != *(int *)(param_2 + 0x60)) ||
      (_Size = *(size_t *)(param_1 + 0x10), _Size != *(size_t *)(param_2 + 0x10))) ||
     ((uVar2 = 1, _Size != 0 &&
      (iVar1 = memcmp((void *)(param_1 + 0x14),(void *)(param_2 + 0x14),_Size), iVar1 != 0)))) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 402e988c FUN_402e988c */

/* Boundary evidence: original MIPS .pdata 402e988c..402e991b. Semantic name remains unreviewed. */

undefined4 FUN_402e988c(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1;
  if (param_1 != 0) {
    do {
      iVar2 = FUN_402e982c(iVar3 + 0x10,param_2);
      if (iVar2 != 0) {
        if (param_3 != (int *)0x0) {
          *param_3 = iVar3;
        }
        return 1;
      }
      piVar1 = (int *)(iVar3 + 4);
      iVar3 = *piVar1;
    } while (*piVar1 != param_1);
  }
  return 0;
}



/* 402e991c FUN_402e991c */

/* Boundary evidence: original MIPS .pdata 402e991c..402e9ae7. Semantic name remains unreviewed. */

DWORD FUN_402e991c(int param_1,HWND param_2,undefined4 param_3)

{
  int iVar1;
  LRESULT LVar2;
  WCHAR *pWVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  DWORD DVar7;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  WCHAR *local_c4;
  undefined4 local_bc;
  int local_b8;
  WCHAR local_a8 [66];
  uint local_24;
  
  local_24 = DAT_402f65fc;
  DVar7 = 0;
  uVar5 = 0;
  iVar1 = strcmp((char *)(param_1 + 0x24),"");
  if (iVar1 != 0) {
    uVar5 = MultiByteToWideChar(0,0,(char *)(param_1 + 0x24),*(int *)(param_1 + 0x20),local_a8,0x42)
    ;
    if ((uVar5 == 0) && (DVar7 = GetLastError(), DVar7 != 0)) goto LAB_402e9ab8;
  }
  local_a8[uVar5] = L'\0';
  uVar4 = 0;
  if (uVar5 != 0) {
    pWVar3 = local_a8;
    do {
      if (*pWVar3 != L' ') break;
      uVar4 = uVar4 + 1;
      pWVar3 = pWVar3 + 1;
    } while (uVar4 < uVar5);
  }
  if (*(int *)(param_1 + 0x70) == 1) {
    if ((*(uint *)(param_1 + 0xc) & 4) == 0) {
      if ((*(uint *)(param_1 + 0xc) & 2) == 0) {
        uVar6 = 4;
      }
      else {
        uVar6 = 2;
      }
    }
    else {
      uVar6 = 3;
    }
  }
  else if ((*(uint *)(param_1 + 0xc) & 4) == 0) {
    uVar6 = 5;
    if ((*(uint *)(param_1 + 0xc) & 2) == 0) {
      uVar6 = 7;
    }
  }
  else {
    uVar6 = 6;
  }
  memset(&local_d8,0,0x2c);
  local_c4 = local_a8;
  local_d0 = 0;
  local_d8 = 7;
  local_d4 = param_3;
  local_bc = uVar6;
  local_b8 = param_1;
  LVar2 = SendMessageW(param_2,0x104d,0,(LPARAM)&local_d8);
  *(LRESULT *)(param_1 + 8) = LVar2;
LAB_402e9ab8:
  FUN_402f41d8(local_24);
  return DVar7;
}



/* 402e9ae8 FUN_402e9ae8 */

/* Boundary evidence: original MIPS .pdata 402e9ae8..402e9cdf. Semantic name remains unreviewed. */

int FUN_402e9ae8(int param_1,uint param_2,uint param_3,void *param_4,undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  if ((param_3 & 1) == 0) {
    piVar3 = *(int **)(param_1 + 0xa4);
  }
  else {
    piVar3 = *(int **)(param_1 + 0xa8);
  }
  piVar4 = piVar3;
  if (piVar3 == (int *)0x0) {
    piVar3 = FUN_402e9780(param_3,param_4);
    if (piVar3 == (int *)0x0) {
      iVar5 = 8;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = piVar3;
    }
  }
  else {
    do {
      iVar1 = FUN_402e982c((int)(piVar4 + 4),(int)param_4);
      if (iVar1 != 0) {
        piVar4[3] = piVar4[3] | param_3;
        if ((param_2 & 2) != 0) {
          piVar4[0x29] = *(int *)((int)param_4 + 0x94);
          piVar4[0x11] = *(int *)((int)param_4 + 0x34);
          if (((param_2 & 1) != 0) && (piVar4 != piVar3)) {
            *(int *)(*piVar4 + 4) = piVar4[1];
            *(int *)piVar4[1] = *piVar4;
            piVar4[1] = (int)piVar3;
            *piVar4 = *piVar3;
            *(int **)(*piVar3 + 4) = piVar4;
            *piVar3 = (int)piVar4;
            piVar3 = piVar4;
          }
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = piVar4;
        }
        iVar5 = 0x7de;
      }
      piVar4 = (int *)piVar4[1];
      if (iVar5 != 0) goto LAB_402e9c90;
    } while (piVar4 != piVar3);
    piVar2 = FUN_402e9780(param_3,param_4);
    if (piVar2 == (int *)0x0) {
      iVar5 = 8;
    }
    else {
      if ((param_2 & 1) != 0) {
        piVar4 = piVar3;
      }
      *piVar2 = *piVar4;
      piVar2[1] = (int)piVar4;
      *(int **)(*piVar4 + 4) = piVar2;
      *piVar4 = (int)piVar2;
      if ((param_2 & 1) != 0) {
        piVar3 = piVar2;
      }
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = piVar2;
    }
  }
LAB_402e9c90:
  if ((param_3 & 1) == 0) {
    *(int **)(param_1 + 0xa4) = piVar3;
  }
  else {
    *(int **)(param_1 + 0xa8) = piVar3;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return iVar5;
}



/* 402e9ce0 FUN_402e9ce0 */

/* Boundary evidence: original MIPS .pdata 402e9ce0..402e9e13. Semantic name remains unreviewed. */

int FUN_402e9ce0(int param_1,uint *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  
  iVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar2 = *(int *)(param_1 + 0xa4);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 4) != iVar2) {
      do {
        piVar1 = *(int **)(*(int *)(param_1 + 0xa4) + 4);
        *(int *)(*piVar1 + 4) = piVar1[1];
        *(int *)piVar1[1] = *piVar1;
        LocalFree(piVar1);
      } while (*(int *)(*(int *)(param_1 + 0xa4) + 4) != *(int *)(param_1 + 0xa4));
    }
    piVar1 = *(int **)(param_1 + 0xa4);
    *(int *)(*piVar1 + 4) = piVar1[1];
    *(int *)piVar1[1] = *piVar1;
    LocalFree(piVar1);
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  if ((param_2 != (uint *)0x0) && (uVar5 = 0, *param_2 != 0)) {
    puVar4 = param_2 + 2;
    do {
      iVar3 = FUN_402e9ae8(param_1,0,2,puVar4,(undefined4 *)0x0);
      if (iVar3 == 0x7de) {
        iVar3 = 0;
      }
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 0x31;
    } while (uVar5 < *param_2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return iVar3;
}



/* 402e9e14 FUN_402e9e14 */

/* Boundary evidence: original MIPS .pdata 402e9e14..402e9f67. Semantic name remains unreviewed. */

int FUN_402e9e14(int param_1,uint *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  iVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar2 = *(int *)(param_1 + 0xa8);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 4) != iVar2) {
      do {
        piVar1 = *(int **)(*(int *)(param_1 + 0xa8) + 4);
        *(int *)(*piVar1 + 4) = piVar1[1];
        *(int *)piVar1[1] = *piVar1;
        LocalFree(piVar1);
      } while (*(int *)(*(int *)(param_1 + 0xa8) + 4) != *(int *)(param_1 + 0xa8));
    }
    piVar1 = *(int **)(param_1 + 0xa8);
    *(int *)(*piVar1 + 4) = piVar1[1];
    *(int *)piVar1[1] = *piVar1;
    LocalFree(piVar1);
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  if ((param_2 != (uint *)0x0) && (uVar6 = 0, *param_2 != 0)) {
    puVar5 = param_2 + 2;
    do {
      uVar4 = 1;
      iVar3 = FUN_402e988c(*(int *)(param_1 + 0xa4),(int)puVar5,(int *)0x0);
      if (iVar3 != 0) {
        uVar4 = 3;
      }
      iVar3 = FUN_402e9ae8(param_1,2,uVar4,puVar5,(undefined4 *)0x0);
      if (iVar3 == 0x7de) {
        iVar3 = 0;
      }
      uVar6 = uVar6 + 1;
      puVar5 = puVar5 + 0x31;
    } while (uVar6 < *param_2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return iVar3;
}



/* 402e9f68 FUN_402e9f68 */

/* Boundary evidence: original MIPS .pdata 402e9f68..402ea06f. Semantic name remains unreviewed. */

undefined4 FUN_402e9f68(int param_1,int param_2)

{
  int iVar1;
  int local_e0 [2];
  undefined4 local_d8;
  undefined1 auStack_d4 [12];
  size_t local_c8;
  undefined1 auStack_c4 [32];
  undefined4 local_a4;
  undefined4 local_78;
  undefined4 local_44;
  uint local_14;
  
  local_14 = DAT_402f65fc;
  local_d8 = 0;
  memset(auStack_d4,0,0xc0);
  local_e0[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  local_78 = *(undefined4 *)(param_2 + 0x14);
  local_c8 = *(uint *)(param_2 + 0x28);
  if (0x20 < local_c8) {
    local_c8 = 0x20;
  }
  memcpy(auStack_c4,*(void **)(param_2 + 0x2c),local_c8);
  local_44 = *(undefined4 *)(param_2 + 0x18);
  local_a4 = *(undefined4 *)(param_2 + 0x1c);
  iVar1 = FUN_402e988c(*(int *)(param_1 + 0xa4),(int)&local_d8,local_e0);
  if (iVar1 != 0) {
    *(uint *)(local_e0[0] + 0xc) = *(uint *)(local_e0[0] + 0xc) | 4;
  }
  iVar1 = FUN_402e988c(*(int *)(param_1 + 0xa8),(int)&local_d8,local_e0);
  if (iVar1 != 0) {
    *(uint *)(local_e0[0] + 0xc) = *(uint *)(local_e0[0] + 0xc) | 4;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_14);
  return 0;
}



/* 402ea070 FUN_402ea070 */

/* Boundary evidence: original MIPS .pdata 402ea070..402ea14f. Semantic name remains unreviewed. */

undefined4 FUN_402ea070(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HWND hWnd;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  hWnd = *(HWND *)(param_1 + 0x78);
  iVar4 = *(int *)(param_1 + 0xa8);
  SendMessageW(hWnd,0x1009,0,0);
  if (iVar4 != 0) {
    iVar3 = 0;
    iVar2 = iVar4;
    do {
      uVar1 = *(uint *)(param_1 + 0xa0) & 7;
      if ((uVar1 == 2) || (uVar1 == *(uint *)(iVar2 + 0x70))) {
        *(int *)(iVar2 + 8) = iVar3;
        FUN_402e991c(iVar2,hWnd,iVar3);
        iVar3 = iVar3 + 1;
      }
      else {
        *(undefined4 *)(iVar2 + 8) = 0xffffffff;
      }
      iVar2 = *(int *)(iVar2 + 4);
    } while (iVar2 != iVar4);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return 0;
}



/* 402ea150 FUN_402ea150 */

/* Boundary evidence: original MIPS .pdata 402ea150..402ea273. Semantic name remains unreviewed. */

undefined4 FUN_402ea150(HWND param_1,int param_2)

{
  bool bVar1;
  LRESULT LVar2;
  LRESULT LVar3;
  LRESULT LVar4;
  BOOL BVar5;
  BOOL bEnable;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  LVar2 = FUN_402d7608(*(HWND *)(param_2 + 0x78),0xffffffff,2);
  LVar3 = SendMessageW(*(HWND *)(param_2 + 0x78),0x1004,0,0);
  LVar4 = SendDlgItemMessageW(param_1,0x4b0,0xf0,0,0);
  bEnable = 1;
  if (LVar4 == 1) {
    bVar1 = true;
    if (-1 < LVar2) {
      BVar5 = 1;
      goto LAB_402ea1f0;
    }
  }
  else {
    bVar1 = false;
  }
  BVar5 = 0;
LAB_402ea1f0:
  EnableWindow(*(HWND *)(param_2 + 0x84),BVar5);
  if ((!bVar1) || (BVar5 = 1, LVar2 < 1)) {
    BVar5 = 0;
  }
  EnableWindow(*(HWND *)(param_2 + 0x88),BVar5);
  if (((!bVar1) || (LVar2 < 0)) || (LVar3 + -1 <= LVar2)) {
    bEnable = 0;
  }
  EnableWindow(*(HWND *)(param_2 + 0x8c),bEnable);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return 0;
}



/* 402ea274 FUN_402ea274 */

/* Boundary evidence: original MIPS .pdata 402ea274..402ea443. Semantic name remains unreviewed. */

undefined4 FUN_402ea274(int param_1,WPARAM param_2,WPARAM param_3,int *param_4,int *param_5)

{
  LRESULT LVar1;
  undefined4 uVar2;
  undefined4 local_198;
  WPARAM local_194 [3];
  undefined4 local_188;
  undefined1 *local_184;
  undefined4 local_180;
  int local_178;
  undefined4 local_168;
  WPARAM local_164 [3];
  undefined4 local_158;
  undefined1 *local_154;
  undefined4 local_150;
  int local_148;
  undefined1 auStack_138 [136];
  undefined1 auStack_b0 [132];
  uint local_2c;
  
  local_2c = DAT_402f65fc;
  local_168 = 0;
  uVar2 = 0;
  memset(local_164,0,0x28);
  local_198 = 0;
  memset(local_194,0,0x28);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  local_154 = auStack_138;
  local_164[1] = 0;
  local_168 = 0xf;
  local_158 = 0xffffffff;
  local_150 = 0x42;
  local_164[0] = param_2;
  LVar1 = SendMessageW(*(HWND *)(param_1 + 0x78),0x104b,0,(LPARAM)&local_168);
  if (LVar1 != 0) {
    local_184 = auStack_b0;
    *param_4 = local_148;
    local_194[1] = 0;
    local_198 = 0xf;
    local_188 = 0xffffffff;
    local_180 = 0x42;
    local_194[0] = param_3;
    LVar1 = SendMessageW(*(HWND *)(param_1 + 0x78),0x104b,0,(LPARAM)&local_198);
    if (LVar1 != 0) {
      *param_5 = local_178;
      local_194[0] = param_2;
      local_164[0] = param_3;
      LVar1 = SendMessageW(*(HWND *)(param_1 + 0x78),0x104c,0,(LPARAM)&local_168);
      if ((LVar1 != 0) &&
         (LVar1 = SendMessageW(*(HWND *)(param_1 + 0x78),0x104c,0,(LPARAM)&local_198), LVar1 != 0))
      {
        *(WPARAM *)(*param_4 + 8) = param_3;
        *(WPARAM *)(*param_5 + 8) = param_2;
        SendMessageW(*(HWND *)(param_1 + 0x78),0x1013,param_2,0);
        goto LAB_402ea400;
      }
    }
  }
  uVar2 = 0x1f;
LAB_402ea400:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_2c);
  return uVar2;
}



/* 402ea444 FUN_402ea444 */

/* Boundary evidence: original MIPS .pdata 402ea444..402ea593. Semantic name remains unreviewed. */

DWORD FUN_402ea444(int param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  DWORD DVar6;
  SIZE_T uBytes;
  int iVar7;
  
  DVar6 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  iVar3 = *(int *)(param_1 + 0xa8);
  iVar7 = iVar3;
  uVar5 = 0;
  if (iVar3 != 0) {
    do {
      uVar4 = uVar5;
      piVar1 = (int *)(iVar7 + 4);
      uVar5 = uVar4 + 1;
      iVar7 = *piVar1;
    } while (*piVar1 != iVar3);
    if (uVar5 != 0) {
      uBytes = uVar4 * 0xc4 + 0xcc;
      puVar2 = LocalAlloc(0x40,uBytes);
      if (puVar2 == (uint *)0x0) {
        DVar6 = GetLastError();
      }
      else {
        *puVar2 = 0;
        iVar7 = *(int *)(param_1 + 0xa8);
        uVar4 = 0;
        do {
          *puVar2 = uVar4 + 1;
          memcpy(puVar2 + uVar4 * 0x31 + 2,(void *)(iVar7 + 0x10),0xc4);
          uVar4 = *puVar2;
          iVar7 = *(int *)(iVar7 + 4);
          if (uVar5 <= uVar4) break;
        } while (iVar7 != *(int *)(param_1 + 0xa8));
        *(SIZE_T *)(param_2 + 0x40) = uBytes;
        *(uint **)(param_2 + 0x44) = puVar2;
      }
      goto LAB_402ea558;
    }
  }
  *(undefined4 *)(param_2 + 0x40) = 0;
  *(undefined4 *)(param_2 + 0x44) = 0;
LAB_402ea558:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return DVar6;
}



/* 402ea594 FUN_402ea594 */

/* Boundary evidence: original MIPS .pdata 402ea594..402ea8b3. Semantic name remains unreviewed. */

void FUN_402ea594(HWND param_1,int param_2,uint *param_3)

{
  HWND pHVar1;
  LPARAM lParam;
  LRESULT LVar2;
  WPARAM wParam;
  uint uVar3;
  undefined4 local_180;
  undefined4 local_17c;
  int local_178;
  tagRECT tStack_160;
  WCHAR aWStack_150 [52];
  WCHAR aWStack_e8 [52];
  WCHAR aWStack_80 [50];
  uint local_1c;
  
  local_1c = DAT_402f65fc;
  local_180 = 0;
  memset(&local_17c,0,0x1c);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pHVar1 = GetDlgItem(param_1,0x502);
  *(HWND *)(param_2 + 0x94) = pHVar1;
  pHVar1 = GetDlgItem(param_1,0x4ee);
  *(HWND *)(param_2 + 0x78) = pHVar1;
  pHVar1 = GetDlgItem(param_1,0x4ef);
  *(HWND *)(param_2 + 0x88) = pHVar1;
  pHVar1 = GetDlgItem(param_1,0x4f0);
  *(HWND *)(param_2 + 0x8c) = pHVar1;
  pHVar1 = GetDlgItem(param_1,0x4f6);
  *(HWND *)(param_2 + 0x84) = pHVar1;
  *(undefined4 *)(param_2 + 0xa0) = *(undefined4 *)(param_2 + 0x20);
  LoadStringW(DAT_402fc3c4,0x17e7,aWStack_150,0x32);
  LoadStringW(DAT_402fc3c4,0x17e8,aWStack_e8,0x32);
  LoadStringW(DAT_402fc3c4,0x17e9,aWStack_80,0x32);
  SendMessageW(*(HWND *)(param_2 + 0x94),0x143,0,(LPARAM)aWStack_150);
  SendMessageW(*(HWND *)(param_2 + 0x94),0x143,0,(LPARAM)aWStack_e8);
  SendMessageW(*(HWND *)(param_2 + 0x94),0x143,0,(LPARAM)aWStack_80);
  uVar3 = *(uint *)(param_2 + 0xa0) & 7;
  *param_3 = uVar3;
  if (uVar3 == 0) {
    wParam = 2;
  }
  else if (uVar3 == 1) {
    wParam = 1;
  }
  else {
    wParam = 0;
  }
  SendMessageW(*(HWND *)(param_2 + 0x94),0x14e,wParam,0);
  uVar3 = GetWindowLongW(*(HWND *)(param_2 + 0x78),-0x10);
  SetWindowLongW(*(HWND *)(param_2 + 0x78),-0x10,uVar3 | 0x40);
  lParam = ImageList_LoadImage(DAT_402fc3c4,0x4f9,0x10,0,0xffffffff,0,0);
  SendMessageW(*(HWND *)(param_2 + 0x78),0x1003,1,lParam);
  local_180 = 3;
  local_17c = 0;
  GetClientRect(*(HWND *)(param_2 + 0x78),&tStack_160);
  local_178 = GetSystemMetrics(2);
  local_178 = tStack_160.right - local_178;
  SendMessageW(*(HWND *)(param_2 + 0x78),0x1061,0,(LPARAM)&local_180);
  SendMessageW(*(HWND *)(param_2 + 0x78),0x1036,0x20,0x20);
  EnableWindow(*(HWND *)(param_2 + 0x78),1);
  FUN_402ea070(param_2);
  SendDlgItemMessageW(param_1,0x4f7,0xf1,(uint)((*(uint *)(param_2 + 0xa0) & 0x4000) != 0),0);
  SendDlgItemMessageW(param_1,0x4b0,0xf1,(uint)((*(uint *)(param_2 + 0xa0) & 0x8000) != 0),0);
  FUN_402ea150(param_1,param_2);
  FUN_402e61fc(param_2);
  LVar2 = SendDlgItemMessageW(param_1,0x4b0,0xf0,0,0);
  if (LVar2 == 0) {
    EnableWindow(*(HWND *)(param_2 + 0x78),0);
    EnableWindow(*(HWND *)(param_2 + 0x94),0);
    pHVar1 = GetDlgItem(param_1,0x4f7);
    EnableWindow(pHVar1,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_1c);
  return;
}



/* 402ea8b4 FUN_402ea8b4 */

/* Boundary evidence: original MIPS .pdata 402ea8b4..402ea9f7. Semantic name remains unreviewed. */

void FUN_402ea8b4(HWND param_1,int param_2,int param_3)

{
  WPARAM WVar1;
  int *piVar2;
  WPARAM WVar3;
  int *local_28;
  int *local_24;
  
  WVar1 = FUN_402d7608(*(HWND *)(param_2 + 0x78),0xffffffff,2);
  WVar3 = WVar1 + 1;
  if (param_3 != 0) {
    WVar3 = WVar1 - 1;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402ea274(param_2,WVar1,WVar3,(int *)&local_28,(int *)&local_24);
  if (param_3 == 0) {
    *(int *)local_28[1] = *local_28;
    *(int *)(*local_28 + 4) = local_28[1];
    *local_28 = (int)local_24;
    local_28[1] = local_24[1];
    *(int **)local_24[1] = local_28;
    local_24[1] = (int)local_28;
    piVar2 = local_28;
  }
  else {
    *(int *)(*local_28 + 4) = local_28[1];
    *(int *)local_28[1] = *local_28;
    local_28[1] = (int)local_24;
    *local_28 = *local_24;
    *(int **)(*local_24 + 4) = local_28;
    *local_24 = (int)local_28;
    piVar2 = local_24;
    local_24 = local_28;
  }
  if (*(int **)(param_2 + 0xa8) == piVar2) {
    *(int **)(param_2 + 0xa8) = local_24;
  }
  FUN_402e61fc(param_2);
  FUN_402ea150(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402ea9f8 FUN_402ea9f8 */

/* Boundary evidence: original MIPS .pdata 402ea9f8..402eab5f. Semantic name remains unreviewed. */

void FUN_402ea9f8(HWND param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int *piVar3;
  int *local_50;
  WPARAM local_4c;
  undefined1 auStack_48 [12];
  undefined4 local_3c;
  undefined4 local_38;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  bVar1 = FUN_402e5380(*(HWND *)(param_2 + 0x78),&local_50,(LRESULT *)&local_4c);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = local_50[1];
    if (iVar2 != *(int *)(param_2 + 0xa8)) {
      do {
        if (*(int *)(iVar2 + 8) != -1) {
          *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -1;
        }
        iVar2 = *(int *)(iVar2 + 4);
      } while (iVar2 != *(int *)(param_2 + 0xa8));
    }
    if ((int *)local_50[1] == *(int **)(param_2 + 0xa8)) {
      piVar3 = (int *)*local_50;
    }
    else {
      piVar3 = (int *)local_50[1];
    }
    if (piVar3 == local_50) {
      piVar3 = (int *)0x0;
      *(undefined4 *)(param_2 + 0xa8) = 0;
    }
    else if (*(int **)(param_2 + 0xa8) == local_50) {
      *(int *)(param_2 + 0xa8) = local_50[1];
    }
    SendMessageW(*(HWND *)(param_2 + 0x78),0x1008,local_4c,0);
    *(int *)(*local_50 + 4) = local_50[1];
    *(int *)local_50[1] = *local_50;
    LocalFree(local_50);
    if (piVar3 != (int *)0x0) {
      local_38 = 2;
      local_3c = 2;
      SendMessageW(*(HWND *)(param_2 + 0x78),0x102b,piVar3[2],(LPARAM)auStack_48);
      SendMessageW(*(HWND *)(param_2 + 0x78),0x1013,piVar3[2],0);
    }
    FUN_402ea150(param_1,param_2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402eab60 FUN_402eab60 */

/* Boundary evidence: original MIPS .pdata 402eab60..402eac5f. Semantic name remains unreviewed. */

void FUN_402eab60(HWND param_1,int param_2)

{
  LRESULT LVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  *(uint *)(param_2 + 0xa0) = *(uint *)(param_2 + 0xa0) & 0xffffbfff;
  LVar1 = SendDlgItemMessageW(param_1,0x4f7,0xf0,0,0);
  if (LVar1 == 1) {
    *(uint *)(param_2 + 0xa0) = *(uint *)(param_2 + 0xa0) | 0x4000;
  }
  LVar1 = SendDlgItemMessageW(param_1,0x4b0,0xf0,0,0);
  if (LVar1 == 1) {
    *(uint *)(param_2 + 0xa0) = *(uint *)(param_2 + 0xa0) | 0x8000;
  }
  else {
    *(uint *)(param_2 + 0xa0) = *(uint *)(param_2 + 0xa0) & 0xffff7fff;
  }
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_2 + 0xa0);
  FUN_402ea444(param_2,param_2);
  FUN_402e9738(param_2);
  DestroyWindow(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402eac60 FUN_402eac60 */

/* Boundary evidence: original MIPS .pdata 402eac60..402ead17. Semantic name remains unreviewed. */

void FUN_402eac60(HWND param_1,int param_2)

{
  LRESULT LVar1;
  HWND hWnd;
  uint bEnable;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  LVar1 = SendDlgItemMessageW(param_1,0x4b0,0xf0,0,0);
  bEnable = (uint)(LVar1 == 1);
  EnableWindow(*(HWND *)(param_2 + 0x78),bEnable);
  EnableWindow(*(HWND *)(param_2 + 0x94),bEnable);
  hWnd = GetDlgItem(param_1,0x4f7);
  EnableWindow(hWnd,bEnable);
  FUN_402ea150(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402ead18 FUN_402ead18 */

/* Boundary evidence: original MIPS .pdata 402ead18..402eadab. Semantic name remains unreviewed. */

void FUN_402ead18(HWND param_1)

{
  HMENU hMenu;
  tagPOINT local_18;
  
  hMenu = CreatePopupMenu();
  if (hMenu != (HMENU)0x0) {
    AppendMenuW(hMenu,0,0x17ed,(LPCWSTR)&DAT_402fc2e0);
    AppendMenuW(hMenu,0,0x17ef,(LPCWSTR)&DAT_402fc240);
    GetCursorPos(&local_18);
    TrackPopupMenuEx(hMenu,0,local_18.x,local_18.y,param_1,(LPTPMPARAMS)0x0);
    DestroyMenu(hMenu);
  }
  return;
}



/* 402eadac FUN_402eadac */

/* Boundary evidence: original MIPS .pdata 402eadac..402eaf43. Semantic name remains unreviewed. */

void FUN_402eadac(HWND param_1,int param_2)

{
  int iVar1;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  HWND pHVar2;
  BOOL BVar3;
  LPCWSTR lpName;
  int local_148 [2];
  undefined4 auStack_140 [16];
  int local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined1 auStack_e8 [200];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  local_148[0] = 0;
  iVar1 = GetSystemMetrics(0);
  lpName = (LPCWSTR)0x4db;
  if (0x1df < iVar1) {
    lpName = (LPCWSTR)0x4da;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402ee6bc(auStack_140,0x32ff,lpName);
  FUN_402e5380(*(HWND *)(param_2 + 0x78),local_148,(LRESULT *)0x0);
  if (local_148[0] != 0) {
    memcpy(auStack_e8,(void *)(local_148[0] + 0x10),0xc4);
    local_f8 = *(undefined4 *)(param_2 + 0x24);
    local_f4 = FUN_402e9634(*(int **)(param_2 + 0x60));
    local_100 = 0;
    hResInfo = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
    lpTemplate = LoadResource(DAT_402fc3c4,hResInfo);
    pHVar2 = CreateDialogIndirectParamW
                       (DAT_402fc3c4,lpTemplate,param_1,FUN_402efcf0,(LPARAM)auStack_140);
    if (pHVar2 != (HWND)0x0) {
      EnableWindow(param_1,0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      FUN_402d4604(pHVar2);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      BVar3 = IsWindow(param_1);
      if (BVar3 != 0) {
        EnableWindow(param_1,1);
      }
    }
    if (local_100 != 0) {
      memcpy((void *)(local_148[0] + 0x10),auStack_e8,0xc4);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402f41d8(local_20);
  return;
}



/* 402eaf44 FUN_402eaf44 */

/* Boundary evidence: original MIPS .pdata 402eaf44..402eb1ef. Semantic name remains unreviewed. */

undefined4 FUN_402eaf44(HWND param_1,int param_2,ushort param_3,int param_4)

{
  LRESULT LVar1;
  short extraout_var;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 2) {
    PostQuitMessage(0);
    return 0;
  }
  if (param_2 == 0x10) {
LAB_402eb1c0:
    DestroyWindow(param_1);
  }
  else {
    if (param_2 == 0x4e) {
      iVar2 = *(int *)(param_4 + 8);
      if (iVar2 == -0x65) {
        FUN_402ea150(param_1,DAT_402fbc64);
        return 0;
      }
      if (iVar2 != -5) {
        if (iVar2 == -3) {
LAB_402eb080:
          FUN_402eadac(param_1,DAT_402fbc64);
          return 0;
        }
        if (iVar2 != -2) {
          return 0;
        }
        GetKeyState(0x12);
        if (-1 < extraout_var) {
          return 0;
        }
      }
      FUN_402ead18(param_1);
      return 0;
    }
    if (param_2 == 0x110) {
      if (param_4 == 0) {
        DAT_402fbc64 = param_4;
        return 0;
      }
      DAT_402fbc64 = param_4;
      FUN_402ea594(param_1,param_4,&DAT_402fbc60);
      return 0;
    }
    if (param_2 != 0x111) {
      return 0;
    }
    if (0x4f0 < param_3) {
      if (param_3 != 0x4f6) {
        if (param_3 == 0x502) {
          LVar1 = SendMessageW(*(HWND *)(DAT_402fbc64 + 0x94),0x147,0,0);
          iVar2 = DAT_402fbc64;
          if (LVar1 == 2) {
            DAT_402fbc60 = 0;
          }
          else if (LVar1 == 1) {
            DAT_402fbc60 = 1;
          }
          else if (LVar1 == 0) {
            DAT_402fbc60 = 2;
          }
          uVar3 = *(uint *)(DAT_402fbc64 + 0xa0) & 0xfffffff8;
          *(uint *)(DAT_402fbc64 + 0xa0) = uVar3;
          *(uint *)(iVar2 + 0xa0) = DAT_402fbc60 & 7 | uVar3;
          FUN_402ea070(iVar2);
          return 0;
        }
        if (param_3 == 0x17ed) goto LAB_402eb080;
        if (param_3 != 0x17ef) {
          return 0;
        }
      }
      FUN_402ea9f8(param_1,DAT_402fbc64);
      return 0;
    }
    if (param_3 == 0x4f0) {
      iVar2 = 0;
    }
    else {
      if (param_3 == 1) {
        FUN_402eab60(param_1,DAT_402fbc64);
        return 0;
      }
      if (param_3 == 2) goto LAB_402eb1c0;
      if (param_3 == 0x4b0) {
        FUN_402eac60(param_1,DAT_402fbc64);
        return 0;
      }
      if (param_3 != 0x4ef) {
        return 0;
      }
      iVar2 = 1;
    }
    FUN_402ea8b4(param_1,DAT_402fbc64,iVar2);
  }
  return 0;
}



/* 402eb1f0 FUN_402eb1f0 */

/* Boundary evidence: original MIPS .pdata 402eb1f0..402eb407. Semantic name remains unreviewed. */

LSTATUS FUN_402eb1f0(undefined4 *param_1,undefined4 *param_2)

{
  LSTATUS LVar1;
  HKEY local_30;
  undefined4 local_2c;
  DWORD local_28;
  DWORD local_24;
  
  local_30 = (HKEY)0x0;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0xe10;
  }
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"Drivers\\Builtin\\Ethman\\Popup",0,(LPWSTR)0x0,0,0,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_30,&local_24);
  if (LVar1 != 0) goto LAB_402eb3c4;
  if (local_24 == 1) {
    local_2c = 0xe10;
    LVar1 = RegSetValueExW(local_30,L"Timeout",0,4,(BYTE *)&local_2c,4);
    if (LVar1 != 0) goto LAB_402eb3c4;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = local_2c;
    }
    local_2c = 1;
    LVar1 = RegSetValueExW(local_30,L"Popup",0,4,(BYTE *)&local_2c,4);
    if ((LVar1 != 0) || (param_1 == (undefined4 *)0x0)) goto LAB_402eb3c4;
  }
  else {
    local_2c = 0;
    local_28 = 4;
    if (param_2 != (undefined4 *)0x0) {
      LVar1 = RegQueryValueExW(local_30,L"Timeout",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_2c,
                               &local_28);
      if (LVar1 != 0) goto LAB_402eb3c4;
      *param_2 = local_2c;
    }
    if (param_1 == (undefined4 *)0x0) goto LAB_402eb3c4;
    local_28 = 4;
    LVar1 = RegQueryValueExW(local_30,L"Popup",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_2c,&local_28
                            );
    if (LVar1 != 0) goto LAB_402eb3c4;
  }
  *param_1 = local_2c;
LAB_402eb3c4:
  if (local_30 != (HKEY)0x0) {
    RegCloseKey(local_30);
  }
  return LVar1;
}



/* 402eb408 FUN_402eb408 */

/* Boundary evidence: original MIPS .pdata 402eb408..402eb51b. Semantic name remains unreviewed. */

LSTATUS FUN_402eb408(undefined4 param_1,int param_2)

{
  LSTATUS LVar1;
  undefined4 local_res0;
  int local_res4 [3];
  HKEY local_18;
  DWORD DStack_14;
  
  local_18 = (HKEY)0x0;
  local_res0 = param_1;
  local_res4[0] = param_2;
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"Drivers\\Builtin\\Ethman\\Popup",0,(LPWSTR)0x0,0,0,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_18,&DStack_14);
  if (LVar1 == 0) {
    if (local_res4[0] != 0) {
      LVar1 = RegSetValueExW(local_18,L"Timeout",0,4,(BYTE *)local_res4,4);
      if (LVar1 != 0) goto LAB_402eb4e4;
    }
    LVar1 = RegSetValueExW(local_18,L"Popup",0,4,(BYTE *)&local_res0,4);
  }
LAB_402eb4e4:
  if (local_18 != (HKEY)0x0) {
    RegCloseKey(local_18);
  }
  return LVar1;
}



/* 402eb51c FUN_402eb51c */

/* Boundary evidence: original MIPS .pdata 402eb51c..402eb643. Semantic name remains unreviewed. */

undefined4 FUN_402eb51c(char *param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  pcVar3 = DAT_402fbc6c;
  do {
    if (pcVar3 == (char *)0x0) {
      pcVar3 = LocalAlloc(0,0x30);
      if (pcVar3 == (char *)0x0) {
        uVar4 = 0x80004005;
      }
      else {
        strcpy(pcVar3,param_1);
        *(int *)(pcVar3 + 0x24) = param_2;
        DVar2 = GetTickCount();
        *(uint *)(pcVar3 + 0x2c) = DVar2 / 1000;
        *(char **)(pcVar3 + 0x28) = DAT_402fbc6c;
        DAT_402fbc6c = pcVar3;
      }
LAB_402eb614:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      return uVar4;
    }
    iVar1 = strcmp(param_1,pcVar3);
    if ((iVar1 == 0) && (param_2 == *(int *)(pcVar3 + 0x24))) {
      DVar2 = GetTickCount();
      *(uint *)(pcVar3 + 0x2c) = DVar2 / 1000;
      goto LAB_402eb614;
    }
    pcVar3 = *(char **)(pcVar3 + 0x28);
  } while( true );
}



/* 402eb644 FUN_402eb644 */

/* Boundary evidence: original MIPS .pdata 402eb644..402eb73b. Semantic name remains unreviewed. */

void FUN_402eb644(void)

{
  HLOCAL pvVar1;
  HLOCAL pvVar2;
  DWORD DVar3;
  HLOCAL hMem;
  int iVar4;
  int local_20 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402eb1f0((undefined4 *)0x0,local_20);
  DVar3 = GetTickCount();
  pvVar1 = (HLOCAL)0x0;
  hMem = DAT_402fbc6c;
  pvVar2 = DAT_402fbc6c;
  while (hMem != (HLOCAL)0x0) {
    iVar4 = DVar3 / 1000 - *(int *)((int)hMem + 0x2c);
    if ((local_20[0] < iVar4) || (iVar4 < 0)) {
      if (pvVar1 == (HLOCAL)0x0) {
        DAT_402fbc6c = *(HLOCAL *)((int)pvVar2 + 0x28);
        LocalFree(hMem);
        hMem = DAT_402fbc6c;
        pvVar2 = DAT_402fbc6c;
      }
      else {
        *(undefined4 *)((int)pvVar1 + 0x28) = *(undefined4 *)((int)hMem + 0x28);
        LocalFree(hMem);
        hMem = *(HLOCAL *)((int)pvVar1 + 0x28);
        pvVar2 = DAT_402fbc6c;
      }
    }
    else {
      pvVar1 = hMem;
      hMem = *(HLOCAL *)((int)hMem + 0x28);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  return;
}



/* 402eb73c FUN_402eb73c */

/* Boundary evidence: original MIPS .pdata 402eb73c..402eb77b. Semantic name remains unreviewed. */

void FUN_402eb73c(void)

{
  HLOCAL hMem;
  
  while (hMem = DAT_402fbc6c, DAT_402fbc6c != (HLOCAL)0x0) {
    DAT_402fbc6c = *(HLOCAL *)((int)DAT_402fbc6c + 0x28);
    LocalFree(hMem);
  }
  return;
}



/* 402eb77c FUN_402eb77c */

/* Boundary evidence: original MIPS .pdata 402eb77c..402eb82f. Semantic name remains unreviewed. */

undefined4 FUN_402eb77c(char *param_1,int param_2)

{
  int iVar1;
  char *_Str2;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
  FUN_402eb644();
  _Str2 = DAT_402fbc6c;
  do {
    if (_Str2 == (char *)0x0) {
LAB_402eb804:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      return uVar2;
    }
    iVar1 = strcmp(param_1,_Str2);
    if ((iVar1 == 0) && (param_2 == *(int *)(_Str2 + 0x24))) {
      uVar2 = 1;
      goto LAB_402eb804;
    }
    _Str2 = *(char **)(_Str2 + 0x28);
  } while( true );
}



/* 402eb830 FUN_402eb830 */

/* Boundary evidence: original MIPS .pdata 402eb830..402eb8e3. Semantic name remains unreviewed. */

void FUN_402eb830(HWND param_1,WPARAM param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_78;
  WPARAM local_74 [7];
  undefined4 local_58;
  undefined1 auStack_48 [8];
  undefined4 local_40;
  undefined4 local_34;
  
  memset(local_74,0,0x28);
  local_78 = 4;
  local_58 = 0;
  local_74[0] = param_2;
  SendMessageW(param_1,0x104d,0,(LPARAM)&local_78);
  local_40 = 0;
  local_34 = param_3;
  SendMessageW(param_1,0x1074,param_2,(LPARAM)auStack_48);
  local_40 = 1;
  local_34 = param_4;
  SendMessageW(param_1,0x1074,param_2,(LPARAM)auStack_48);
  return;
}



/* 402eb8e4 FUN_402eb8e4 */

/* Boundary evidence: original MIPS .pdata 402eb8e4..402eb953. Semantic name remains unreviewed. */

undefined4 FUN_402eb8e4(HWND param_1,wchar_t *param_2,uint param_3)

{
  HWND pHVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t *local_18 [2];
  
  local_18[0] = (wchar_t *)0x0;
  pHVar1 = GetParent(param_1);
  iVar2 = FUN_402d48fc((int)pHVar1,(int *)local_18);
  if ((iVar2 < 0) || (local_18[0] == (wchar_t *)0x0)) {
    uVar3 = 0x80004005;
  }
  else {
    wcsncpy(param_2,local_18[0],param_3 >> 1);
    uVar3 = 0;
  }
  return uVar3;
}



/* 402eb954 FUN_402eb954 */

/* Boundary evidence: original MIPS .pdata 402eb954..402eb9df. Semantic name remains unreviewed. */

undefined4 FUN_402eb954(HWND param_1,char *param_2,size_t param_3)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  wchar_t awStack_78 [50];
  uint local_14;
  
  local_14 = DAT_402f65fc;
  iVar1 = FUN_402eb8e4(param_1,awStack_78,100);
  if (iVar1 == 0) {
    sVar2 = wcstombs(param_2,awStack_78,param_3);
    if (sVar2 == param_3) {
      param_2[param_3] = '\0';
    }
    FUN_402f41d8(local_14);
    uVar3 = 0;
  }
  else {
    FUN_402f41d8(local_14);
    uVar3 = 0x80004005;
  }
  return uVar3;
}



/* 402eb9e0 FUN_402eb9e0 */

/* Boundary evidence: original MIPS .pdata 402eb9e0..402ebaef. Semantic name remains unreviewed. */

undefined4 FUN_402eb9e0(HWND param_1,int *param_2,int *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  size_t local_58 [2];
  char acStack_50 [52];
  uint local_1c;
  
  local_1c = DAT_402f65fc;
  *param_2 = 0;
  uVar3 = 0;
  local_58[0] = 0;
  iVar1 = GetAdaptersInfo(*param_3,local_58);
  if (iVar1 == 0x6f) {
    pvVar2 = malloc(local_58[0]);
    *param_3 = (int)pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_402eba58;
    iVar1 = GetAdaptersInfo(pvVar2,local_58);
  }
  if ((iVar1 == 0) && (*param_3 != 0)) {
    *param_2 = *param_3;
    iVar1 = FUN_402eb954(param_1,acStack_50,0x32);
    if (iVar1 == 0) {
      iVar1 = *param_3;
      do {
        iVar1 = strcmp(acStack_50,(char *)(iVar1 + 8));
        if (iVar1 == 0) goto LAB_402eba60;
        iVar1 = *(int *)*param_3;
        *param_3 = iVar1;
      } while (iVar1 != 0);
    }
  }
LAB_402eba58:
  uVar3 = 0x80004005;
LAB_402eba60:
  FUN_402f41d8(local_1c);
  return uVar3;
}



/* 402ebaf0 FUN_402ebaf0 */

/* Boundary evidence: original MIPS .pdata 402ebaf0..402ebea3. Semantic name remains unreviewed. */

int FUN_402ebaf0(HWND param_1,int param_2)

{
  undefined *puVar1;
  HWND hWnd;
  HWND hWnd_00;
  HWND hWnd_01;
  HWND hWnd_02;
  int iVar2;
  int iVar3;
  HCURSOR pHVar4;
  size_t sVar5;
  int iVar6;
  wchar_t *pwVar7;
  LPCWSTR lpString;
  char *_Str;
  int *_Memory;
  size_t local_e28;
  undefined *local_e24;
  void *local_e20;
  int local_e1c;
  wchar_t awStack_e18 [32];
  wchar_t awStack_dd8 [32];
  wchar_t awStack_d98 [32];
  WCHAR aWStack_d58 [32];
  WCHAR aWStack_d18 [32];
  WCHAR aWStack_cd8 [32];
  wchar_t awStack_c98 [52];
  WCHAR aWStack_c30 [512];
  WCHAR aWStack_830 [512];
  WCHAR aWStack_430 [512];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  local_e24 = (undefined *)0x0;
  _Memory = (int *)0x0;
  local_e20 = (void *)0x0;
  local_e28 = 0;
  hWnd = GetDlgItem(param_1,0x177b);
  hWnd_00 = GetDlgItem(param_1,0x177c);
  hWnd_01 = GetDlgItem(param_1,0x177e);
  hWnd_02 = GetDlgItem(param_1,0x177d);
  iVar2 = FUN_402eb9e0(param_1,(int *)&local_e20,(int *)&local_e24);
  puVar1 = local_e24;
  local_e1c = iVar2;
  if (iVar2 < 0) goto LAB_402ebe54;
  if (param_2 == 0) {
    _Str = local_e24 + 0x1b0;
    sVar5 = strlen(_Str);
    mbstowcs(awStack_d98,_Str,sVar5 + 1);
    sVar5 = strlen(puVar1 + 0x1d8);
    mbstowcs(awStack_dd8,puVar1 + 0x1d8,sVar5 + 1);
    sVar5 = strlen(puVar1 + 0x1c0);
    mbstowcs(awStack_e18,puVar1 + 0x1c0,sVar5 + 1);
    LoadStringW(DAT_402fc3c4,0x178d,aWStack_830,0x200);
    LoadStringW(DAT_402fc3c4,0x178c,aWStack_c30,0x200);
    GetWindowTextW(hWnd,aWStack_430,0x200);
    iVar3 = *(int *)(puVar1 + 0x1a4);
    pwVar7 = aWStack_830;
    if (iVar3 == 0) {
      pwVar7 = aWStack_c30;
    }
    iVar6 = wcscmp(pwVar7,aWStack_430);
    if (iVar6 != 0) {
      lpString = aWStack_830;
      if (iVar3 == 0) {
        lpString = aWStack_c30;
      }
      SetWindowTextW(hWnd,lpString);
    }
    GetWindowTextW(hWnd_00,aWStack_cd8,0x1e);
    iVar3 = wcscmp(aWStack_cd8,awStack_d98);
    if (iVar3 != 0) {
      SetWindowTextW(hWnd_00,awStack_d98);
    }
    GetWindowTextW(hWnd_01,aWStack_d18,0x1e);
    iVar3 = wcscmp(aWStack_d18,awStack_dd8);
    if (iVar3 != 0) {
      SetWindowTextW(hWnd_01,awStack_dd8);
    }
    GetWindowTextW(hWnd_02,aWStack_d58,0x1e);
    iVar3 = wcscmp(aWStack_d58,awStack_e18);
    if (iVar3 == 0) goto LAB_402ebe54;
    SetWindowTextW(hWnd_02,awStack_e18);
  }
  else {
    local_e28 = 0;
    iVar3 = GetInterfaceInfo(0,&local_e28);
    if (iVar3 == 0x7a) {
      _Memory = malloc(local_e28);
      if (_Memory != (int *)0x0) {
        iVar3 = GetInterfaceInfo(_Memory,&local_e28);
        goto LAB_402ebbec;
      }
    }
    else {
LAB_402ebbec:
      if ((iVar3 == 0) && (local_e28 != 0)) {
        pHVar4 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
        SetCursor(pHVar4);
        iVar3 = FUN_402eb8e4(param_1,awStack_c98,100);
        if (iVar3 == 0) {
          iVar3 = 0;
          if (0 < *_Memory) {
            pwVar7 = (wchar_t *)(_Memory + 2);
            local_e24 = &DAT_402d1054;
            do {
              iVar2 = wcscmp(pwVar7,awStack_c98);
              if (iVar2 == 0) {
                iVar2 = IpReleaseAddress(pwVar7 + -2);
                if (iVar2 == 0) {
                  SetWindowTextW(hWnd_00,L"0.0.0.0");
                  SetWindowTextW(hWnd_02,L"0.0.0.0");
                  SetWindowTextW(hWnd_01,L"");
                  Sleep(500);
                }
                IpRenewAddress(pwVar7 + -2);
              }
              iVar3 = iVar3 + 1;
              pwVar7 = pwVar7 + 0x82;
              iVar2 = local_e1c;
            } while (iVar3 < *_Memory);
          }
          pHVar4 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
          SetCursor(pHVar4);
          goto LAB_402ebe44;
        }
      }
    }
    iVar2 = -0x7fffbffb;
  }
LAB_402ebe44:
  if (_Memory != (int *)0x0) {
    free(_Memory);
  }
LAB_402ebe54:
  if (local_e20 != (void *)0x0) {
    free(local_e20);
  }
  FUN_402f41d8(local_30);
  return iVar2;
}



/* 402ebea4 FUN_402ebea4 */

/* Boundary evidence: original MIPS .pdata 402ebea4..402ebf13. Semantic name remains unreviewed. */

void FUN_402ebea4(LPWSTR param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_10 [2];
  
  local_10[0] = 0x41;
  iVar1 = WSAAddressToStringW(param_2,0x1c,0,param_1,local_10);
  if (iVar1 != 0) {
    LoadStringW(DAT_402fc3c4,0x17e6,param_1,0x41);
  }
  return;
}



/* 402ebf14 FUN_402ebf14 */

/* Boundary evidence: original MIPS .pdata 402ebf14..402ec17b. Semantic name remains unreviewed. */

undefined4 FUN_402ebf14(int param_1,LPWSTR param_2)

{
  HANDLE hDevice;
  int iVar1;
  undefined4 uVar2;
  DWORD aDStack_120 [2];
  undefined1 auStack_118 [88];
  undefined2 local_c0;
  undefined2 local_be;
  uint local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 auStack_a0 [16];
  int local_90;
  int local_8c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 auStack_68 [20];
  int local_54;
  uint local_30;
  
  local_30 = DAT_402f65fc;
  uVar2 = 0;
  hDevice = CreateFileW(L"IP60:",0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (hDevice == (HANDLE)0xffffffff) {
    FUN_402f41d8(local_30);
    uVar2 = 0;
  }
  else {
    local_54 = 0;
    memcpy(auStack_a0,auStack_68,0x38);
    iVar1 = DeviceIoControl(hDevice,0x120034,auStack_a0,0x38,auStack_118,0x54,aDStack_120,
                            (LPOVERLAPPED)0x0);
    while (iVar1 != 0) {
      memcpy(auStack_68,auStack_118,0x38);
      iVar1 = local_8c;
      if (((local_8c != 0) && (memcpy(auStack_118,auStack_a0,0x38), local_90 == 0)) &&
         (*(int *)(param_1 + 0x48) == iVar1)) {
        local_c0 = 0x17;
        local_b8 = local_78;
        local_b0 = local_70;
        local_b4 = local_74;
        local_ac = local_6c;
        local_be = 0;
        if ((local_78 & 0xff) == 0xfe) {
          if ((local_78._1_1_ & 0xc0) == 0x80) {
            local_a8 = *(undefined4 *)(param_1 + 0x54);
          }
          else {
            if ((local_78._1_1_ & 0xc0) != 0xc0) goto LAB_402ec120;
            local_a8 = *(undefined4 *)(param_1 + 0x60);
          }
        }
        else {
LAB_402ec120:
          local_a8 = 0;
        }
        FUN_402ebea4(param_2,&local_c0);
        uVar2 = 1;
        break;
      }
      if (local_54 == 0) break;
      memcpy(auStack_a0,auStack_68,0x38);
      iVar1 = DeviceIoControl(hDevice,0x120034,auStack_a0,0x38,auStack_118,0x54,aDStack_120,
                              (LPOVERLAPPED)0x0);
    }
    CloseHandle(hDevice);
    FUN_402f41d8(local_30);
  }
  return uVar2;
}



/* 402ec17c FUN_402ec17c */

/* Boundary evidence: original MIPS .pdata 402ec17c..402ec357. Semantic name remains unreviewed. */

undefined4 FUN_402ec17c(HWND param_1)

{
  HINSTANCE hInstance;
  HWND hWnd;
  UINT UVar1;
  int iVar2;
  UINT *pUVar3;
  undefined4 local_128;
  undefined1 auStack_124 [8];
  WCHAR *local_11c;
  undefined4 local_108;
  int local_104 [4];
  WCHAR *local_f4;
  UINT local_e8;
  undefined1 auStack_d8 [8];
  undefined4 local_d0;
  WCHAR *local_c4;
  WCHAR aWStack_a8 [66];
  uint local_24;
  
  local_24 = DAT_402f65fc;
  hWnd = GetDlgItem(param_1,0x18a6);
  memset(auStack_124,0,0x1c);
  local_108 = 0;
  memset(local_104,0,0x28);
  local_128 = 4;
  LoadStringW(DAT_402fc3c4,0x189c,aWStack_a8,0x41);
  local_11c = aWStack_a8;
  SendMessageW(hWnd,0x1061,0,(LPARAM)&local_128);
  LoadStringW(DAT_402fc3c4,0x189d,aWStack_a8,0x41);
  local_11c = aWStack_a8;
  SendMessageW(hWnd,0x1061,1,(LPARAM)&local_128);
  memset(&local_108,0,0x2c);
  pUVar3 = &DAT_402f64c0;
  local_108 = 5;
  iVar2 = 0;
  do {
    local_104[0] = iVar2;
    LoadStringW(DAT_402fc3c4,*pUVar3,aWStack_a8,0x41);
    local_e8 = pUVar3[1];
    local_f4 = aWStack_a8;
    UVar1 = SendMessageW(hWnd,0x104d,0,(LPARAM)&local_108);
    hInstance = DAT_402fc3c4;
    pUVar3[2] = UVar1;
    LoadStringW(hInstance,0x17e6,aWStack_a8,0x41);
    local_c4 = aWStack_a8;
    local_d0 = 1;
    SendMessageW(hWnd,0x1074,pUVar3[2],(LPARAM)auStack_d8);
    pUVar3 = pUVar3 + 3;
    iVar2 = iVar2 + 1;
  } while ((int)pUVar3 < 0x402f6520);
  SendMessageW(hWnd,0x101e,0,0xffff);
  SendMessageW(hWnd,0x101e,1,300);
  DAT_402fbc70 = 1;
  FUN_402f41d8(local_24);
  return 1;
}



/* 402ec358 FUN_402ec358 */

/* Boundary evidence: original MIPS .pdata 402ec358..402ec477. Semantic name remains unreviewed. */

void FUN_402ec358(HWND param_1,int param_2,wchar_t *param_3)

{
  HWND hWnd;
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined1 auStack_d0 [8];
  undefined4 local_c8;
  wchar_t *local_bc;
  undefined4 local_b8;
  wchar_t awStack_a0 [66];
  uint local_1c;
  
  local_1c = DAT_402f65fc;
  hWnd = GetDlgItem(param_1,0x18a6);
  if (DAT_402fbc70 == 0) {
    FUN_402ec17c(param_1);
  }
  iVar3 = 0;
  piVar2 = &DAT_402f64c4;
  do {
    if (param_2 == *piVar2) {
      local_bc = awStack_a0;
      local_b8 = 0x41;
      local_c8 = 1;
      SendMessageW(hWnd,0x1073,(&DAT_402f64c8)[iVar3 * 3],(LPARAM)auStack_d0);
      iVar1 = wcscmp(awStack_a0,param_3);
      if (iVar1 != 0) {
        local_c8 = 1;
        local_bc = param_3;
        SendMessageW(hWnd,0x1074,(&DAT_402f64c8)[iVar3 * 3],(LPARAM)auStack_d0);
      }
      break;
    }
    piVar2 = piVar2 + 3;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x402f6524);
  FUN_402f41d8(local_1c);
  return;
}



/* 402ec478 FUN_402ec478 */

/* Boundary evidence: original MIPS .pdata 402ec478..402ec89f. Semantic name remains unreviewed. */

undefined4 FUN_402ec478(HWND param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  void *_Memory;
  int iVar8;
  int iVar9;
  size_t local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  int local_180;
  undefined4 local_17c;
  void *local_178;
  WCHAR aWStack_170 [68];
  char acStack_e8 [56];
  WCHAR aWStack_b0 [66];
  uint local_2c;
  
  local_2c = DAT_402f65fc;
  local_17c = 0;
  local_198 = 0;
  local_194 = 0;
  local_188 = 0;
  local_180 = 0;
  local_184 = 0;
  local_18c = 0;
  bVar2 = false;
  local_190 = 0;
  bVar3 = false;
  pvVar7 = (void *)0x0;
  iVar4 = GetAdaptersAddresses(0x17,6,0,0,&local_198);
  if ((((iVar4 == 0x6f) && (pvVar7 = malloc(local_198), local_178 = pvVar7, pvVar7 != (void *)0x0))
      && (iVar4 = GetAdaptersAddresses(0x17,6,0,pvVar7,&local_198), iVar4 == 0)) &&
     (iVar4 = FUN_402eb954(param_1,acStack_e8,0x32), iVar4 == 0)) {
    do {
      iVar4 = strcmp(acStack_e8,*(char **)((int)pvVar7 + 0xc));
      if (iVar4 == 0) {
        iVar4 = local_188;
        iVar5 = local_180;
        uVar6 = local_17c;
        _Memory = local_178;
        iVar8 = local_184;
        iVar9 = local_18c;
        if ((*(uint *)((int)pvVar7 + 0x44) & 1) == 0) break;
        bVar1 = true;
        iVar4 = FUN_402ebf14((int)pvVar7,aWStack_b0);
        if (iVar4 != 0) {
          FUN_402ec358(param_1,0x17de,aWStack_b0);
          local_194 = 1;
        }
LAB_402ec5ec:
        for (iVar4 = *(int *)((int)pvVar7 + 0x10); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
          iVar5 = *(int *)(iVar4 + 0xc);
          FUN_402ebea4(aWStack_b0,iVar5);
          if ((*(char *)(iVar5 + 8) == -2) && ((*(byte *)(iVar5 + 9) & 0xc0) == 0xc0)) {
            if (bVar1) {
              iVar5 = 0x17dc;
              bVar3 = true;
              goto LAB_402ec738;
            }
            if (((*(ushort *)(iVar5 + 0x10) & 0xfffd) == 0) && (*(short *)(iVar5 + 0x12) == -0x1a2))
            {
              local_18c = 1;
              iVar5 = 0x17e1;
              goto LAB_402ec738;
            }
          }
          else {
            if ((*(char *)(iVar5 + 8) == -2) && ((*(byte *)(iVar5 + 9) & 0xc0) == 0x80)) {
              if (bVar1) {
                local_188 = 1;
                iVar5 = 0x17dd;
              }
              else {
                if (((*(ushort *)(iVar5 + 0x10) & 0xfffd) != 0) ||
                   (*(short *)(iVar5 + 0x12) != -0x1a2)) goto LAB_402ec744;
                local_190 = 1;
                iVar5 = 0x17e2;
              }
            }
            else if (bVar1) {
              iVar5 = 0x17db;
              bVar2 = true;
            }
            else if ((*(char *)(iVar5 + 8) == ' ') && (*(char *)(iVar5 + 9) == '\x02')) {
              local_180 = 1;
              iVar5 = 0x17df;
            }
            else {
              if (((*(ushort *)(iVar5 + 0x10) & 0xfffd) != 0) ||
                 (*(short *)(iVar5 + 0x12) != -0x1a2)) goto LAB_402ec744;
              local_184 = 1;
              iVar5 = 0x17e0;
            }
LAB_402ec738:
            FUN_402ec358(param_1,iVar5,aWStack_b0);
          }
LAB_402ec744:
        }
      }
      else {
        bVar1 = false;
        if (*(int *)((int)pvVar7 + 0x40) == 0x83) goto LAB_402ec5ec;
      }
      pvVar7 = *(void **)((int)pvVar7 + 8);
      iVar4 = local_188;
      iVar5 = local_180;
      uVar6 = local_17c;
      _Memory = local_178;
      iVar8 = local_184;
      iVar9 = local_18c;
    } while (pvVar7 != (void *)0x0);
  }
  else {
    iVar4 = 0;
    iVar5 = 0;
    uVar6 = 0x80004005;
    _Memory = pvVar7;
    iVar8 = 0;
    iVar9 = 0;
  }
  LoadStringW(DAT_402fc3c4,0x17e6,aWStack_170,0x41);
  if (local_194 == 0) {
    FUN_402ec358(param_1,0x17de,aWStack_170);
  }
  if (!bVar2) {
    FUN_402ec358(param_1,0x17db,aWStack_170);
  }
  if (!bVar3) {
    FUN_402ec358(param_1,0x17dc,aWStack_170);
  }
  if (iVar4 == 0) {
    FUN_402ec358(param_1,0x17dd,aWStack_170);
  }
  if (iVar5 == 0) {
    FUN_402ec358(param_1,0x17df,aWStack_170);
  }
  if (iVar8 == 0) {
    FUN_402ec358(param_1,0x17e0,aWStack_170);
  }
  if (iVar9 == 0) {
    FUN_402ec358(param_1,0x17e1,aWStack_170);
  }
  if (local_190 == 0) {
    FUN_402ec358(param_1,0x17e2,aWStack_170);
  }
  if (_Memory != (void *)0x0) {
    free(_Memory);
  }
  FUN_402f41d8(local_2c);
  return uVar6;
}



/* 402ec8a0 FUN_402ec8a0 */

/* Boundary evidence: original MIPS .pdata 402ec8a0..402ec947. Semantic name remains unreviewed. */

undefined4 FUN_402ec8a0(HWND param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == 2) {
    DAT_402fbc70 = 0;
  }
  else if (param_2 == 0x110) {
    FUN_402ec17c(param_1);
    FUN_402ec478(param_1);
    uVar1 = 1;
    SetTimer(param_1,1,2000,(TIMERPROC)0x0);
  }
  else {
    if ((param_2 != 0x111) && (param_2 == 0x113)) {
      FUN_402ec478(param_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 402ec948 FUN_402ec948 */

/* Boundary evidence: original MIPS .pdata 402ec948..402ed043. Semantic name remains unreviewed. */

void FUN_402ec948(HWND param_1)

{
  HWND hWnd;
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  LRESULT LVar4;
  uint uVar5;
  char *_Str;
  int iVar6;
  byte *pbVar7;
  void *_Memory;
  WPARAM WVar8;
  size_t local_430;
  int local_42c;
  void *local_428 [2];
  undefined4 local_420;
  undefined4 local_41c;
  int local_418;
  wchar_t *local_414;
  _FILETIME _Stack_400;
  FILETIME FStack_3f8;
  _FILETIME _Stack_3f0;
  FILETIME FStack_3e8;
  tagRECT tStack_3e0;
  _SYSTEMTIME _Stack_3d0;
  _SYSTEMTIME _Stack_3c0;
  wchar_t awStack_3b0 [52];
  WCHAR local_348 [52];
  WCHAR local_2e0 [52];
  wchar_t local_278 [32];
  wchar_t local_238 [32];
  WCHAR aWStack_1f8 [40];
  wchar_t awStack_1a8 [32];
  wchar_t awStack_168 [32];
  wchar_t awStack_128 [32];
  wchar_t awStack_e8 [32];
  wchar_t awStack_a8 [32];
  wchar_t awStack_68 [30];
  uint local_2c;
  
  local_2c = DAT_402f65fc;
  local_42c = 0;
  _Memory = (void *)0x0;
  local_428[0] = (void *)0x0;
  local_430 = 0;
  local_420 = 0;
  memset(&local_41c,0,0x1c);
  WVar8 = 0;
  hWnd = GetDlgItem(param_1,0x17a1);
  iVar1 = FUN_402eb9e0(param_1,(int *)local_428,&local_42c);
  iVar6 = local_42c;
  if (-1 < iVar1) {
    pbVar7 = (byte *)(local_42c + 0x194);
    wsprintfW(aWStack_1f8,L"%02X",(uint)*pbVar7);
    uVar5 = 1;
    if (1 < *(uint *)(iVar6 + 400)) {
      do {
        wsprintfW(aWStack_1f8,L"%s %02X",aWStack_1f8,(uint)pbVar7[uVar5]);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(iVar6 + 400));
    }
    sVar2 = strlen((char *)(iVar6 + 0x1b0));
    mbstowcs(awStack_e8,(char *)(iVar6 + 0x1b0),sVar2 + 1);
    sVar2 = strlen((char *)(iVar6 + 0x1d8));
    mbstowcs(awStack_128,(char *)(iVar6 + 0x1d8),sVar2 + 1);
    sVar2 = strlen((char *)(iVar6 + 0x1c0));
    mbstowcs(awStack_68,(char *)(iVar6 + 0x1c0),sVar2 + 1);
    if (*(int *)(iVar6 + 0x1a4) == 0) {
      local_278[0] = L'\0';
    }
    else {
      sVar2 = strlen((char *)(iVar6 + 0x200));
      mbstowcs(local_278,(char *)(iVar6 + 0x200),sVar2 + 1);
    }
    sVar2 = strlen((char *)(iVar6 + 0x22c));
    mbstowcs(awStack_168,(char *)(iVar6 + 0x22c),sVar2 + 1);
    sVar2 = strlen((char *)(iVar6 + 0x254));
    mbstowcs(awStack_1a8,(char *)(iVar6 + 0x254),sVar2 + 1);
    if (*(int *)(iVar6 + 0x1a4) == 0) {
      local_2e0[0] = L'\0';
      local_348[0] = L'\0';
    }
    else {
      FUN_402d44d4(*(uint *)(iVar6 + 0x278),&FStack_3e8.dwLowDateTime);
      FileTimeToLocalFileTime(&FStack_3e8,&_Stack_3f0);
      FileTimeToSystemTime(&_Stack_3f0,&_Stack_3c0);
      GetDateFormatW(0x400,1,&_Stack_3c0,(LPCWSTR)0x0,local_2e0,0x32);
      wcscat(local_2e0,L" ");
      sVar2 = wcslen(local_2e0);
      sVar3 = wcslen(local_2e0 + sVar2);
      GetTimeFormatW(0x400,4,&_Stack_3c0,(LPCWSTR)0x0,local_2e0 + sVar2,0x32 - sVar3);
      FUN_402d44d4(*(uint *)(iVar6 + 0x27c),&FStack_3f8.dwLowDateTime);
      FileTimeToLocalFileTime(&FStack_3f8,&_Stack_400);
      FileTimeToSystemTime(&_Stack_400,&_Stack_3d0);
      GetDateFormatW(0x400,1,&_Stack_3d0,(LPCWSTR)0x0,local_348,0x32);
      wcscat(local_348,L" ");
      sVar2 = wcslen(local_348);
      sVar3 = wcslen(local_348 + sVar2);
      GetTimeFormatW(0x400,4,&_Stack_3d0,(LPCWSTR)0x0,local_348 + sVar2,0x32 - sVar3);
    }
    iVar1 = GetNetworkParams(0,&local_430);
    if (iVar1 == 0x6f) {
      _Memory = malloc(local_430);
      if (_Memory == (void *)0x0) goto LAB_402ecfe8;
      iVar1 = GetNetworkParams(_Memory,&local_430);
    }
    if ((iVar1 == 0) && (_Memory != (void *)0x0)) {
      sVar2 = strlen((char *)((int)_Memory + 0x110));
      mbstowcs(awStack_a8,(char *)((int)_Memory + 0x110),sVar2 + 1);
      if (*(int *)((int)_Memory + 0x10c) == 0) {
        local_238[0] = L'\0';
      }
      else {
        _Str = (char *)(*(int *)((int)_Memory + 0x10c) + 4);
        sVar2 = strlen(_Str);
        mbstowcs(local_238,_Str,sVar2 + 1);
      }
      sVar2 = strlen((char *)(iVar6 + 8));
      mbstowcs(awStack_3b0,(char *)(iVar6 + 8),sVar2 + 1);
      SetWindowTextW(param_1,awStack_3b0);
      GetClientRect(hWnd,&tStack_3e0);
      iVar6 = tStack_3e0.right;
      if (tStack_3e0.right < 0) {
        iVar6 = tStack_3e0.right + 1;
      }
      local_420 = 7;
      local_41c = 0;
      local_418 = iVar6 >> 1;
      iVar1 = LoadStringW(DAT_402fc3c4,0x1798,awStack_3b0,0x32);
      if (iVar1 != 0) {
        local_414 = awStack_3b0;
        LVar4 = SendMessageW(hWnd,0x1061,0,(LPARAM)&local_420);
        WVar8 = LVar4 + 1;
      }
      iVar1 = LoadStringW(DAT_402fc3c4,0x1799,awStack_3b0,0x32);
      if (iVar1 != 0) {
        local_418 = tStack_3e0.right - (iVar6 >> 1);
        local_414 = awStack_3b0;
        SendMessageW(hWnd,0x1061,WVar8,(LPARAM)&local_420);
      }
      SendMessageW(hWnd,0x1036,0,0x20);
      iVar6 = LoadStringW(DAT_402fc3c4,0x178f,awStack_3b0,0x32);
      if (iVar6 != 0) {
        FUN_402eb830(hWnd,0,awStack_3b0,aWStack_1f8);
      }
      WVar8 = (WPARAM)(iVar6 != 0);
      iVar6 = LoadStringW(DAT_402fc3c4,0x1790,awStack_3b0,0x32);
      if (iVar6 != 0) {
        FUN_402eb830(hWnd,WVar8,awStack_3b0,awStack_e8);
        WVar8 = WVar8 + 1;
      }
      iVar6 = LoadStringW(DAT_402fc3c4,0x1791,awStack_3b0,0x32);
      if (iVar6 != 0) {
        FUN_402eb830(hWnd,WVar8,awStack_3b0,awStack_68);
        WVar8 = WVar8 + 1;
      }
      iVar6 = LoadStringW(DAT_402fc3c4,0x1792,awStack_3b0,0x32);
      if (iVar6 != 0) {
        FUN_402eb830(hWnd,WVar8,awStack_3b0,awStack_128);
        WVar8 = WVar8 + 1;
      }
      iVar6 = LoadStringW(DAT_402fc3c4,0x1793,awStack_3b0,0x32);
      if (iVar6 != 0) {
        FUN_402eb830(hWnd,WVar8,awStack_3b0,local_278);
        WVar8 = WVar8 + 1;
      }
      iVar6 = LoadStringW(DAT_402fc3c4,0x1794,awStack_3b0,0x32);
      if (iVar6 != 0) {
        FUN_402eb830(hWnd,WVar8,awStack_3b0,local_2e0);
        WVar8 = WVar8 + 1;
      }
      iVar6 = LoadStringW(DAT_402fc3c4,0x1795,awStack_3b0,0x32);
      if (iVar6 != 0) {
        FUN_402eb830(hWnd,WVar8,awStack_3b0,local_348);
        WVar8 = WVar8 + 1;
      }
      iVar6 = LoadStringW(DAT_402fc3c4,0x1796,awStack_3b0,0x32);
      if (iVar6 != 0) {
        FUN_402eb830(hWnd,WVar8,awStack_3b0,awStack_a8);
        FUN_402eb830(hWnd,WVar8 + 1,&DAT_402d1054,local_238);
        WVar8 = WVar8 + 2;
      }
      iVar6 = LoadStringW(DAT_402fc3c4,0x1797,awStack_3b0,0x32);
      if (iVar6 != 0) {
        FUN_402eb830(hWnd,WVar8,awStack_3b0,awStack_168);
        FUN_402eb830(hWnd,WVar8 + 1,&DAT_402d1054,awStack_1a8);
      }
    }
  }
LAB_402ecfe8:
  if (local_428[0] != (void *)0x0) {
    free(local_428[0]);
  }
  if (_Memory != (void *)0x0) {
    free(_Memory);
  }
  FUN_402f41d8(local_2c);
  return;
}



/* 402ed044 FUN_402ed044 */

/* Boundary evidence: original MIPS .pdata 402ed044..402ed0cf. Semantic name remains unreviewed. */

undefined4 FUN_402ed044(HWND param_1,int param_2,ushort param_3)

{
  if (param_2 == 2) {
    PostQuitMessage(0);
  }
  else {
    if (param_2 != 0x10) {
      if (param_2 == 0x110) {
        FUN_402ec948(param_1);
        return 1;
      }
      if (param_2 != 0x111) {
        return 0;
      }
      if (param_3 == 0) {
        return 0;
      }
      if (2 < param_3) {
        return 0;
      }
    }
    DestroyWindow(param_1);
  }
  return 0;
}



/* 402ed0d0 FUN_402ed0d0 */

/* Boundary evidence: original MIPS .pdata 402ed0d0..402ed2cf. Semantic name remains unreviewed. */

undefined4 FUN_402ed0d0(HWND param_1,int param_2,short param_3)

{
  HWND pHVar1;
  int iVar2;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  BOOL BVar3;
  LPCWSTR lpName;
  HWND hWnd;
  undefined4 uVar4;
  int local_420 [2];
  WCHAR aWStack_418 [512];
  uint local_18;
  
  local_18 = DAT_402f65fc;
  local_420[0] = 0;
  if (param_2 == 0x110) {
    uVar4 = 1;
    SetTimer(param_1,1,2000,(TIMERPROC)0x0);
  }
  else {
    if (param_2 == 0x111) {
      if (param_3 == 0x1783) {
        iVar2 = FUN_402ebaf0(param_1,1);
        if (iVar2 < 0) {
          LoadStringW(DAT_402fc3c4,0x1787,aWStack_418,0x200);
          NetMsgBox(param_1,3,aWStack_418);
        }
      }
      else if (param_3 == 0x1784) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
        pHVar1 = GetParent(param_1);
        iVar2 = FUN_402d48fc((int)pHVar1,local_420);
        if ((-1 < iVar2) && (local_420[0] != 0)) {
          iVar2 = GetSystemMetrics(0);
          lpName = (LPCWSTR)0x17a0;
          if (0x1df < iVar2) {
            lpName = (LPCWSTR)0x178e;
          }
          hResInfo = FindResourceW(DAT_402fc3c4,lpName,(LPCWSTR)0x5);
          lpTemplate = LoadResource(DAT_402fc3c4,hResInfo);
          pHVar1 = CreateDialogIndirectParamW
                             (DAT_402fc3c4,lpTemplate,*(HWND *)(local_420[0] + 0x518),FUN_402ed044,0
                             );
          if (pHVar1 != (HWND)0x0) {
            hWnd = *(HWND *)(local_420[0] + 0x518);
            EnableWindow(hWnd,0);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
            FUN_402d4604(pHVar1);
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
            BVar3 = IsWindow(hWnd);
            if (BVar3 != 0) {
              EnableWindow(hWnd,1);
            }
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402fc3e0);
      }
    }
    else if (param_2 == 0x113) {
      FUN_402ebaf0(param_1,0);
    }
    uVar4 = 0;
  }
  FUN_402f41d8(local_18);
  return uVar4;
}



/* 402ed2d0 FUN_402ed2d0 */

undefined4 FUN_402ed2d0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &DAT_402fbe88;
  iVar2 = 0;
  do {
    if (*piVar1 == 0) {
      (&DAT_402fbe88)[iVar2] = param_1;
      return 1;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x402fbe9c);
  return 0;
}



/* 402ed320 FUN_402ed320 */

void FUN_402ed320(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &DAT_402fbe88;
  iVar2 = 0;
  do {
    if (param_1 == *piVar1) {
      (&DAT_402fbe88)[iVar2] = 0;
      return;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x402fbe9c);
  return;
}



/* 402ed36c FUN_402ed36c */

/* Boundary evidence: original MIPS .pdata 402ed36c..402ed3fb. Semantic name remains unreviewed. */

LPWSTR FUN_402ed36c(LPWSTR param_1,UINT param_2,int param_3)

{
  int iVar1;
  LPWSTR lpBuffer;
  
  if (param_3 == 0) {
    param_3 = 0x83;
  }
  lpBuffer = param_1;
  if (param_1 == (LPWSTR)0x0) {
    lpBuffer = (LPWSTR)&DAT_402fbd80;
  }
  iVar1 = LoadStringW(DAT_402fc3c4,param_2,lpBuffer,param_3);
  if (iVar1 == 0) {
    FUN_402ed4d0(0,0x67);
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = L'\0';
    }
    param_1 = (LPWSTR)0x0;
  }
  else if (param_1 == (LPWSTR)0x0) {
    param_1 = (LPWSTR)&DAT_402fbd80;
  }
  return param_1;
}



/* 402ed3fc FUN_402ed3fc */

/* Boundary evidence: original MIPS .pdata 402ed3fc..402ed4cf. Semantic name remains unreviewed. */

int FUN_402ed3fc(HWND param_1,UINT param_2,UINT param_3,uint param_4)

{
  LPWSTR lpCaption;
  LPWSTR lpText;
  int iVar1;
  WCHAR aWStack_128 [132];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  if (param_1 == (HWND)0x0) {
    param_1 = GetActiveWindow();
  }
  if ((((param_4 & 0x20) == 0) && ((param_4 & 0x10) == 0)) && ((param_4 & 0x40) == 0)) {
    param_4 = param_4 | 0x30;
  }
  lpCaption = FUN_402ed36c(aWStack_128,param_3,0x84);
  lpText = FUN_402ed36c((LPWSTR)0x0,param_2,0);
  iVar1 = MessageBoxW(param_1,lpText,lpCaption,param_4);
  FUN_402f41d8(local_20);
  return iVar1;
}



/* 402ed4d0 FUN_402ed4d0 */

/* Boundary evidence: original MIPS .pdata 402ed4d0..402ed583. Semantic name remains unreviewed. */

undefined4 FUN_402ed4d0(HWND param_1,int param_2)

{
  UINT UVar1;
  UINT UVar2;
  uint uVar3;
  undefined4 uVar4;
  
  UVar2 = 0x42e;
  uVar4 = 0;
  if (param_2 == 3) {
    return 1;
  }
  if (param_2 == 0x65) {
    UVar1 = 0x428;
LAB_402ed560:
    uVar4 = 1;
  }
  else if (param_2 == 0x69) {
    UVar1 = 0x425;
    UVar2 = 0x42c;
  }
  else {
    if (param_2 == 0x70) {
      uVar4 = 1;
      uVar3 = 0x104;
      UVar2 = 0x42e;
      UVar1 = 0x427;
      goto LAB_402ed540;
    }
    if (param_2 != 0xcf) {
      UVar1 = 0x426;
      goto LAB_402ed560;
    }
    UVar1 = 0x42b;
    UVar2 = 0x42d;
  }
  uVar3 = 0;
LAB_402ed540:
  FUN_402ed3fc(param_1,UVar1,UVar2,uVar3);
  return uVar4;
}



/* 402ed584 FUN_402ed584 */

/* Boundary evidence: original MIPS .pdata 402ed584..402ed693. Semantic name remains unreviewed. */

undefined * FUN_402ed584(HWND param_1,int param_2,int param_3)

{
  WPARAM wParam;
  LRESULT LVar1;
  UINT UVar2;
  
  UVar2 = 0x188;
  if (param_3 == 0) {
    UVar2 = 0x147;
  }
  wParam = SendDlgItemMessageW(param_1,param_2,UVar2,0,0);
  if (wParam == 0xffffffff) {
    if (param_3 == 0) {
      SendDlgItemMessageW(param_1,param_2,0xd,0x84,0x402fbc74);
      return &DAT_402fbc74;
    }
  }
  else {
    UVar2 = 0x18a;
    if (param_3 == 0) {
      UVar2 = 0x149;
    }
    LVar1 = SendDlgItemMessageW(param_1,param_2,UVar2,wParam,0);
    if (LVar1 + 2U < 0x108) {
      UVar2 = 0x189;
      if (param_3 == 0) {
        UVar2 = 0x148;
      }
      SendDlgItemMessageW(param_1,param_2,UVar2,wParam,0x402fbc74);
      return &DAT_402fbc74;
    }
  }
  FUN_402ed4d0(param_1,100);
  return (undefined *)0x0;
}



/* 402ed694 FUN_402ed694 */

/* Boundary evidence: original MIPS .pdata 402ed694..402ed6f3. Semantic name remains unreviewed. */

undefined * FUN_402ed694(HWND param_1)

{
  LONG LVar1;
  int iVar2;
  int *piVar3;
  
  LVar1 = GetWindowLongW(param_1,-0xc);
  piVar3 = &DAT_402f6520;
  iVar2 = 0;
  do {
    if (*piVar3 == LVar1) {
      return (&PTR_DAT_402f6524)[iVar2 * 2];
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 2;
  } while (iVar2 < 6);
  return (undefined *)0x0;
}



/* 402ed6f4 FUN_402ed6f4 */

/* Boundary evidence: original MIPS .pdata 402ed6f4..402eda63. Semantic name remains unreviewed. */

LRESULT FUN_402ed6f4(HWND param_1,UINT param_2,uint param_3,LPARAM param_4)

{
  ushort uVar1;
  bool bVar2;
  wint_t wVar3;
  HKL pHVar4;
  LRESULT LVar5;
  BOOL BVar6;
  wchar_t *_Str;
  size_t sVar7;
  int iVar8;
  HIMC pHVar9;
  LONG LVar10;
  ushort *puVar11;
  HWND pHVar12;
  ushort *puVar13;
  undefined2 extraout_var;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  uint local_38;
  DWORD local_34;
  undefined1 auStack_30 [8];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  pHVar4 = GetKeyboardLayout(0);
  if (param_2 == 0x102) {
    if (0x7f < param_3) goto LAB_402ed918;
    if ((0x1f < param_3) && (param_3 < 0x7f)) {
      puVar11 = (ushort *)FUN_402ed694(param_1);
      if (puVar11 == (ushort *)0x0) {
        pHVar12 = GetParent(param_1);
        puVar11 = (ushort *)FUN_402ed694(pHVar12);
        if (puVar11 == (ushort *)0x0) goto LAB_402eda10;
      }
      if ((param_3 < 0x30) || (0x39 < param_3)) {
        uVar14 = (uint)*puVar11;
        if (uVar14 != 0) {
          puVar13 = puVar11;
          do {
            puVar13 = puVar13 + 1;
            if ((param_3 & 0xffff) == uVar14) goto LAB_402eda10;
            uVar14 = (uint)*puVar13;
          } while (uVar14 != 0);
        }
        iVar16 = iswctype((wint_t)param_3,2);
        if (iVar16 != 0) {
          wVar3 = towupper((wint_t)param_3);
          param_3 = CONCAT22(extraout_var,wVar3);
          uVar1 = *puVar11;
          while (uVar1 != 0) {
            puVar11 = puVar11 + 1;
            if (param_3 == uVar1) goto LAB_402eda10;
            uVar1 = *puVar11;
          }
        }
LAB_402ed918:
        MessageBeep(0);
        FUN_402f41d8(local_28);
        return 1;
      }
    }
  }
  else if (param_2 == 0x10f) {
    BVar6 = ImmIsIME(pHVar4);
    if (((BVar6 != 0) && (((uint)pHVar4 & 0xffff) == 0x412)) &&
       (pHVar9 = ImmGetContext(param_1), pHVar9 != (HIMC)0x0)) {
      LVar10 = ImmGetCompositionStringW(pHVar9,8,auStack_30,4);
      if (0 < LVar10) {
        ImmNotifyIME(pHVar9,0x15,4,0);
        ImmGetConversionStatus(pHVar9,&local_38,&local_34);
        local_38 = local_38 & 0xfffffffe;
        ImmSetConversionStatus(pHVar9,local_38,local_34);
      }
      ImmReleaseContext(param_1,pHVar9);
      LVar5 = CallWindowProcW(DAT_402fc340,param_1,0x10f,param_3,param_4);
      goto LAB_402eda2c;
    }
  }
  else if (param_2 == 0x302) {
    puVar15 = &DAT_402fbe88;
    bVar2 = true;
    do {
      if (param_1 == (HWND)*puVar15) {
        BVar6 = OpenClipboard(param_1);
        if (BVar6 != 0) {
          _Str = GetClipboardData(0xd);
          if (_Str == (wchar_t *)0x0) goto LAB_402ed820;
          sVar7 = wcslen(_Str);
          iVar16 = 0;
          if ((int)sVar7 < 1) goto LAB_402ed820;
          goto LAB_402ed7ec;
        }
        break;
      }
      puVar15 = puVar15 + 1;
    } while ((int)puVar15 < 0x402fbe9c);
    goto LAB_402ed790;
  }
LAB_402eda10:
  LVar5 = CallWindowProcW(DAT_402fc340,param_1,param_2,param_3,param_4);
LAB_402eda2c:
  FUN_402f41d8(local_28);
  return LVar5;
  while( true ) {
    iVar8 = iswctype(*_Str,4);
    if (iVar8 == 0) {
      bVar2 = false;
    }
    iVar16 = iVar16 + 1;
    _Str = _Str + 1;
    if ((int)sVar7 <= iVar16) break;
LAB_402ed7ec:
    if (!bVar2) break;
  }
LAB_402ed820:
  CloseClipboard();
  if (!bVar2) {
    MessageBeep(0);
    FUN_402f41d8(local_28);
    return 0;
  }
LAB_402ed790:
  LVar5 = CallWindowProcW(DAT_402fc340,param_1,0x302,param_3,param_4);
  goto LAB_402eda2c;
}



/* 402eda64 FUN_402eda64 */

/* Boundary evidence: original MIPS .pdata 402eda64..402edb2b. Semantic name remains unreviewed. */

void FUN_402eda64(void)

{
  bool bVar1;
  DWORD DVar2;
  LPBYTE pBVar3;
  uint uVar4;
  LPBYTE hMem;
  
  DVar2 = FUN_402ee5d8((LPBYTE)0x0);
  if ((DVar2 != 0) && (pBVar3 = LocalAlloc(0x40,DVar2 + 2), pBVar3 != (LPBYTE)0x0)) {
    DVar2 = FUN_402ee5d8(pBVar3);
    hMem = DAT_402fbd7c;
    bVar1 = DAT_402fbd7c == (LPBYTE)0x0;
    (pBVar3 + (DVar2 & 0xfffffffe))[0] = 0xff;
    (pBVar3 + (DVar2 & 0xfffffffe))[1] = 0xff;
    if (bVar1) {
      hMem = "A";
    }
    else {
      LocalFree(hMem);
    }
    uVar4 = 0;
    DAT_402fbd7c = pBVar3;
    do {
      if (*(LPBYTE *)((int)&PTR_DAT_402f6524 + uVar4) == hMem) {
        *(LPBYTE *)((int)&PTR_DAT_402f6524 + uVar4) = pBVar3;
      }
      uVar4 = uVar4 + 8;
    } while (uVar4 < 0x30);
  }
  return;
}



/* 402edb2c FUN_402edb2c */

/* Boundary evidence: original MIPS .pdata 402edb2c..402edb67. Semantic name remains unreviewed. */

void FUN_402edb2c(void)

{
  if (DAT_402fbd7c != (HLOCAL)0x0) {
    LocalFree(DAT_402fbd7c);
    DAT_402fbd7c = (HLOCAL)0x0;
  }
  return;
}



/* 402edb68 FUN_402edb68 */

/* Boundary evidence: original MIPS .pdata 402edb68..402edcf7. Semantic name remains unreviewed. */

void FUN_402edb68(wchar_t *param_1,wchar_t *param_2,long *param_3)

{
  wchar_t wVar1;
  long lVar2;
  wchar_t *pwVar3;
  int iVar4;
  wchar_t *pwVar5;
  wchar_t *_Dest;
  
  if ((param_3 != (long *)0x0) && (param_2 != (wchar_t *)0x0)) {
    lVar2 = _wtol(param_1);
    *param_3 = lVar2;
    wcscpy((wchar_t *)(param_3 + 1),param_2);
    pwVar3 = wcschr(param_2,L'\0');
    wcscpy((wchar_t *)((int)param_3 + 0x42),pwVar3 + 1);
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    wcscpy((wchar_t *)(param_3 + 0x31),pwVar3 + 1);
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    wcscpy((wchar_t *)((int)param_3 + 0x146),pwVar3 + 1);
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    wcscpy((wchar_t *)(param_3 + 0x72),pwVar3 + 1);
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    _Dest = (wchar_t *)((int)param_3 + 0x1de);
    wcscpy(_Dest,pwVar3 + 1);
    iVar4 = lstrcmpW(L"noCW",_Dest);
    if (iVar4 == 0) {
      *_Dest = L'\0';
    }
    iVar4 = 0;
    wVar1 = *_Dest;
    pwVar5 = _Dest;
    while ((wVar1 != L'\0' && (wVar1 == L' '))) {
      pwVar5 = pwVar5 + 1;
      iVar4 = iVar4 + 1;
      wVar1 = *pwVar5;
    }
    if (*(short *)((iVar4 + 0xef) * 2 + (int)param_3) == 0) {
      *_Dest = L'\0';
    }
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    wcscpy((wchar_t *)(param_3 + 0x7c),pwVar3 + 1);
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    lVar2 = _wtol(pwVar3 + 1);
    param_3[0x82] = lVar2;
  }
  return;
}



/* 402edcf8 FUN_402edcf8 */

/* Boundary evidence: original MIPS .pdata 402edcf8..402ee177. Semantic name remains unreviewed. */

LSTATUS FUN_402edcf8(undefined4 *param_1)

{
  LSTATUS LVar1;
  uint *puVar2;
  uint uVar3;
  DWORD dwIndex;
  wchar_t *lpData;
  HKEY local_78;
  HKEY local_74;
  DWORD local_70;
  DWORD local_6c [4];
  DWORD DStack_5c;
  size_t local_58;
  DWORD local_54 [5];
  WCHAR local_40;
  undefined1 auStack_3e [18];
  uint local_2c;
  
  local_2c = DAT_402f65fc;
  lpData = (wchar_t *)0x0;
  local_78 = (HKEY)0x0;
  local_74 = (HKEY)0x0;
  local_40 = L'\0';
  memset(auStack_3e,0,0x12);
  local_54[1] = 0;
  local_54[0] = 0;
  local_54[3] = 0;
  local_6c[0] = 0;
  local_6c[2] = 0;
  local_70 = 0;
  LVar1 = RegCreateKeyExW((HKEY)0x80000001,L"ControlPanel\\Dial",0,(LPWSTR)0x0,0,0,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_78,local_6c + 3);
  if ((LVar1 == 0) && (local_6c[3] != 1)) {
    local_6c[1] = 4;
    LVar1 = RegQueryValueExW(local_78,L"CurrentLoc",(LPDWORD)0x0,&DStack_5c,(LPBYTE)&DAT_402fc204,
                             local_6c + 1);
    if (LVar1 != 0) {
      DAT_402fc204 = 0;
    }
    local_6c[1] = 4;
    LVar1 = RegQueryValueExW(local_78,L"HighLocID",(LPDWORD)0x0,&DStack_5c,(LPBYTE)&DAT_402fc200,
                             local_6c + 1);
    if (LVar1 != 0) {
      DAT_402fc200 = 0;
    }
  }
  else {
    DAT_402fc204 = 0;
    DAT_402fc200 = 1;
    if (local_78 != (HKEY)0x0) {
      RegCloseKey(local_78);
    }
    local_78 = (HKEY)0x0;
  }
  RegCreateKeyExW((HKEY)0x80000001,L"ControlPanel\\Dial\\Locations",0,(LPWSTR)0x0,0,0,
                  (LPSECURITY_ATTRIBUTES)0x0,&local_74,local_6c + 3);
  LVar1 = RegQueryInfoKeyW(local_74,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,local_54 + 1,local_54,
                           local_54 + 3,local_6c,local_6c + 2,&local_70,(LPDWORD)0x0,(PFILETIME)0x0)
  ;
  if ((local_74 == (HKEY)0x0) || (local_6c[2] == 0)) {
    LoadStringW(DAT_402fc3c4,0x432,(LPWSTR)&DAT_402fbe9c,0x32);
    local_70 = wcslen((wchar_t *)&DAT_402fbe9c);
    local_6c[0] = 1;
    DAT_402fc204 = 0;
    DAT_402fc200 = 1;
  }
  if ((HLOCAL)*param_1 == (HLOCAL)0x0) {
    puVar2 = LocalAlloc(0x40,local_6c[0] * 0x210);
  }
  else {
    puVar2 = LocalReAlloc((HLOCAL)*param_1,local_6c[0] * 0x210,0x42);
  }
  *param_1 = puVar2;
  if (puVar2 != (uint *)0x0) {
    if ((local_74 == (HKEY)0x0) || (local_6c[2] == 0)) {
      FUN_402edb68(L"0",(wchar_t *)&DAT_402fbe9c,(long *)puVar2);
      puVar2[0x83] = 1;
      DAT_402fc354 = 1;
      DAT_402fc348 = 0;
      dwIndex = DAT_402fc354;
    }
    else {
      local_70 = local_70 + 2;
      lpData = VirtualAlloc((LPVOID)0x0,local_70 * 2,0x3000,4);
      dwIndex = 0;
      if (0 < (int)local_6c[0]) {
        do {
          local_54[2] = 10;
          local_58 = local_70;
          LVar1 = RegEnumValueW(local_74,dwIndex,&local_40,local_54 + 2,(LPDWORD)0x0,&DStack_5c,
                                (LPBYTE)lpData,&local_58);
          if (LVar1 != 0) break;
          FUN_402edb68(&local_40,lpData,(long *)puVar2);
          for (uVar3 = local_58 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
            if (*puVar2 == DAT_402fc204) {
              DAT_402fc348 = dwIndex;
            }
          }
          if (DAT_402fc200 <= *puVar2) {
            DAT_402fc200 = *puVar2 + 1;
          }
          dwIndex = dwIndex + 1;
          puVar2 = puVar2 + 0x84;
        } while ((int)dwIndex < (int)local_6c[0]);
      }
    }
    DAT_402fc354 = dwIndex;
    LVar1 = 0;
    if (lpData != (wchar_t *)0x0) {
      VirtualFree(lpData,0,0x8000);
    }
  }
  if (local_78 != (HKEY)0x0) {
    RegCloseKey(local_78);
  }
  if (local_74 != (HKEY)0x0) {
    RegCloseKey(local_74);
  }
  FUN_402f41d8(local_2c);
  return LVar1;
}



/* 402ee178 FUN_402ee178 */

/* Boundary evidence: original MIPS .pdata 402ee178..402ee2fb. Semantic name remains unreviewed. */

int FUN_402ee178(int param_1,LPWSTR param_2,LPWSTR param_3)

{
  int iVar1;
  int iVar2;
  uint *local_20 [2];
  
  iVar2 = 0;
  FUN_402de06c(param_1,(int *)local_20);
  if (local_20[0] == (uint *)0x0) {
    iVar2 = 0;
  }
  else {
    wsprintfW(param_2,L"%d",*local_20[0] & 0xffff);
    if (param_3 != (LPWSTR)0x0) {
      iVar2 = wsprintfW(param_3,L"%s",local_20[0] + 1);
      iVar1 = wsprintfW(param_3 + iVar2 + 1,L"%s",(int)local_20[0] + 0x42);
      iVar1 = iVar1 + iVar2 + 1 + 1;
      iVar2 = wsprintfW(param_3 + iVar1,L"%s",local_20[0] + 0x31);
      iVar1 = iVar2 + iVar1 + 1;
      iVar2 = wsprintfW(param_3 + iVar1,L"%s",(int)local_20[0] + 0x146);
      iVar1 = iVar2 + iVar1 + 1;
      iVar2 = wsprintfW(param_3 + iVar1,L"%s",local_20[0] + 0x72);
      iVar1 = iVar2 + iVar1 + 1;
      iVar2 = wsprintfW(param_3 + iVar1,L"%s",(int)local_20[0] + 0x1de);
      iVar1 = iVar2 + iVar1 + 1;
      iVar2 = wsprintfW(param_3 + iVar1,L"%s",local_20[0] + 0x7c);
      iVar1 = iVar2 + iVar1 + 1;
      iVar2 = wsprintfW(param_3 + iVar1,L"%d",local_20[0][0x82]);
      iVar2 = iVar2 + iVar1 + 3;
    }
  }
  return iVar2;
}



/* 402ee2fc FUN_402ee2fc */

/* Boundary evidence: original MIPS .pdata 402ee2fc..402ee5d7. Semantic name remains unreviewed. */

LSTATUS FUN_402ee2fc(void)

{
  LSTATUS LVar1;
  LPWSTR lpData;
  int iVar2;
  int iVar3;
  int *local_58;
  HKEY local_54;
  HKEY local_50;
  int local_4c;
  uint *local_48 [2];
  WCHAR local_40;
  undefined1 auStack_3e [18];
  uint local_2c;
  
  local_2c = DAT_402f65fc;
  local_40 = L'\0';
  memset(auStack_3e,0,0x12);
  local_4c = DAT_402fc200;
  local_54 = (HKEY)0x0;
  local_50 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"ControlPanel\\Dial",0,0xf003f,&local_54);
  if ((LVar1 == 0) &&
     (LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"ControlPanel\\Dial\\Locations",0,0xf003f,&local_50),
     LVar1 == 0)) {
    lpData = VirtualAlloc((LPVOID)0x0,0x238,0x3000,4);
    if (lpData == (LPWSTR)0x0) {
      LVar1 = -0x7fffbffb;
    }
    else {
      iVar3 = 0;
      FUN_402de06c(0,(int *)&local_58);
      while (local_58 != (int *)0x0) {
        iVar2 = local_58[0x83];
        if (iVar2 != 0) {
          if (iVar2 == 3) {
            FUN_402de06c(iVar3,(int *)local_48);
            if (local_48[0] != (uint *)0x0) {
              wsprintfW(&local_40,L"%d",*local_48[0] & 0xffff);
            }
            LVar1 = RegDeleteValueW(local_50,&local_40);
          }
          else {
            if (iVar2 == 1) {
              *local_58 = local_4c;
              local_4c = local_4c + 1;
            }
            iVar2 = FUN_402ee178(iVar3,&local_40,lpData);
            LVar1 = RegSetValueExW(local_50,&local_40,0,7,(BYTE *)lpData,iVar2 << 1);
          }
        }
        iVar3 = iVar3 + 1;
        FUN_402de06c(iVar3,(int *)&local_58);
      }
      FUN_402de06c(DAT_402fc348,(int *)&local_58);
      if (local_58 != (int *)0x0) {
        RegSetValueExW(local_54,L"CurrentLoc",0,4,(BYTE *)local_58,4);
        LVar1 = RegSetValueExW(local_54,L"HighLocID",0,4,(BYTE *)&local_4c,4);
      }
    }
    if (lpData != (LPWSTR)0x0) {
      VirtualFree(lpData,0,0x8000);
    }
  }
  if (local_54 != (HKEY)0x0) {
    RegCloseKey(local_54);
  }
  if (local_50 != (HKEY)0x0) {
    RegCloseKey(local_50);
  }
  FUN_402f41d8(local_2c);
  return LVar1;
}



/* 402ee5d8 FUN_402ee5d8 */

/* Boundary evidence: original MIPS .pdata 402ee5d8..402ee6bb. Semantic name remains unreviewed. */

DWORD FUN_402ee5d8(LPBYTE param_1)

{
  LSTATUS LVar1;
  DWORD DVar2;
  DWORD local_28;
  HKEY local_24;
  DWORD aDStack_20 [2];
  
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"ControlPanel\\Dial",0,0,&local_24);
  DVar2 = 0;
  if (LVar1 == 0) {
    local_28 = 0;
    LVar1 = RegQueryValueExW(local_24,L"Digits",(LPDWORD)0x0,aDStack_20,(LPBYTE)0x0,&local_28);
    if ((LVar1 == 0) && (DVar2 = local_28, param_1 != (LPBYTE)0x0)) {
      RegQueryValueExW(local_24,L"Digits",(LPDWORD)0x0,aDStack_20,param_1,&local_28);
    }
    RegCloseKey(local_24);
  }
  return DVar2;
}



/* 402ee6bc FUN_402ee6bc */

/* Boundary evidence: original MIPS .pdata 402ee6bc..402ee737. Semantic name remains unreviewed. */

void FUN_402ee6bc(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  memset(param_1,0,0x120);
  param_1[0x11] = param_2;
  param_1[1] = 1;
  param_1[0x2e] = 1;
  *param_1 = param_3;
  param_1[0x10] = 0;
  param_1[0x16] = 0xc4;
  param_1[0x40] = 0xd;
  param_1[0x3f] = 0xc0000000;
  param_1[0x47] = 0;
  return;
}



/* 402ee738 FUN_402ee738 */

/* Boundary evidence: original MIPS .pdata 402ee738..402ee7af. Semantic name remains unreviewed. */

int FUN_402ee738(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x11c);
  iVar3 = 0;
  if (iVar2 != 0) {
    do {
      iVar1 = FUN_402e982c(iVar2 + 0x10,param_1 + 0x58);
      if (iVar1 != 0) {
        iVar3 = 1;
      }
      iVar2 = *(int *)(iVar2 + 4);
    } while ((iVar3 == 0) && (iVar2 != *(int *)(param_1 + 0x11c)));
  }
  return iVar3;
}



/* 402ee7b0 FUN_402ee7b0 */

/* Boundary evidence: original MIPS .pdata 402ee7b0..402ee8d3. Semantic name remains unreviewed. */

void FUN_402ee7b0(HWND param_1,UINT param_2,wchar_t *param_3,wchar_t *param_4)

{
  int iVar1;
  DWORD DVar2;
  LPCWSTR lpText;
  wchar_t *local_c28;
  wchar_t *local_c24;
  WCHAR aWStack_c20 [512];
  WCHAR aWStack_820 [512];
  WCHAR aWStack_420 [512];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  iVar1 = LoadStringW(DAT_402fc3c4,param_2,aWStack_c20,0x200);
  if ((iVar1 != 0) && (iVar1 = LoadStringW(DAT_402fc3c4,0x4d8,aWStack_820,0x200), iVar1 != 0)) {
    local_c28 = param_3;
    local_c24 = param_4;
    iVar1 = wcscmp(param_3,L"");
    if ((iVar1 == 0) && (iVar1 = wcscmp(param_4,L""), iVar1 == 0)) {
      lpText = aWStack_c20;
    }
    else {
      DVar2 = FormatMessageW(0x2400,aWStack_c20,0,0,aWStack_420,0x200,(va_list *)&local_c28);
      if (DVar2 == 0) goto LAB_402ee8ac;
      lpText = aWStack_420;
    }
    MessageBoxW(param_1,lpText,aWStack_820,0x10);
  }
LAB_402ee8ac:
  FUN_402f41d8(local_20);
  return;
}



/* 402ee8d4 FUN_402ee8d4 */

/* Boundary evidence: original MIPS .pdata 402ee8d4..402eeb1b. Semantic name remains unreviewed. */

int FUN_402ee8d4(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *lParam;
  WPARAM WVar3;
  HLOCAL _Dst;
  int *piVar4;
  SIZE_T uBytes;
  int *piVar5;
  int *lParam_00;
  int *lParam_01;
  void *_Src;
  
  bVar1 = false;
  if ((*(uint *)(param_2 + 0x5c) & 0x10) == 0) {
    SendMessageW(*(HWND *)(param_2 + 0x34),0xf1,(uint)(*(int *)(param_2 + 0xf8) != 0),0);
  }
  else {
    SendMessageW(*(HWND *)(param_2 + 0x34),0xf1,1,0);
    EnableWindow(*(HWND *)(param_2 + 0x34),0);
  }
  piVar4 = (int *)(param_2 + 0x54);
  if (*piVar4 == 0) {
    piVar5 = (int *)(param_2 + 0x50);
    iVar2 = (*DAT_402fc210)(piVar5,piVar4);
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((*piVar5 != 0) && (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0)) {
      lParam_00 = (int *)0x0;
      iVar2 = 0;
      if (0 < *piVar5) {
        lParam_01 = piVar4 + 0x209;
        do {
          lParam = LocalAlloc(0x40,0xc);
          if (lParam != (undefined4 *)0x0) {
            WVar3 = SendMessageW(*(HWND *)(param_2 + 0x38),0x143,0,(LPARAM)lParam_01);
            *lParam = piVar4;
            SendMessageW(*(HWND *)(param_2 + 0x38),0x151,WVar3,(LPARAM)lParam);
            if (*(int *)(param_2 + 0x100) == *piVar4) {
              uBytes = *(SIZE_T *)(param_2 + 0x104);
              _Src = *(void **)(param_2 + 0x108);
              lParam[1] = uBytes;
              if ((uBytes != 0) && (_Src != (void *)0x0)) {
                _Dst = LocalAlloc(0x40,uBytes);
                lParam[2] = _Dst;
                if (_Dst != (HLOCAL)0x0) {
                  memcpy(_Dst,_Src,uBytes);
                }
              }
              SendMessageW(*(HWND *)(param_2 + 0x38),0x14e,WVar3,0);
              bVar1 = true;
            }
            else if (*piVar4 == 0xd) {
              lParam_00 = lParam_01;
            }
          }
          iVar2 = iVar2 + 1;
          piVar4 = piVar4 + 0x312;
          lParam_01 = lParam_01 + 0x312;
        } while (iVar2 < *piVar5);
      }
      if ((*piVar5 != 0) && (!bVar1)) {
        WVar3 = 0;
        if ((lParam_00 != (int *)0x0) &&
           (WVar3 = SendMessageW(*(HWND *)(param_2 + 0x38),0x14c,0xffffffff,(LPARAM)lParam_00),
           WVar3 == 0xffffffff)) {
          WVar3 = 0;
        }
        SendMessageW(*(HWND *)(param_2 + 0x38),0x14e,WVar3,0);
      }
    }
  }
  return 0;
}



/* 402eeb1c FUN_402eeb1c */

/* Boundary evidence: original MIPS .pdata 402eeb1c..402eebe3. Semantic name remains unreviewed. */

void FUN_402eeb1c(int param_1)

{
  LRESULT LVar1;
  HLOCAL hMem;
  WPARAM wParam;
  
  LVar1 = SendMessageW(*(HWND *)(param_1 + 0x38),0x146,0,0);
  wParam = 0;
  if (0 < LVar1) {
    do {
      hMem = (HLOCAL)SendMessageW(*(HWND *)(param_1 + 0x38),0x150,wParam,0);
      if ((hMem != (HLOCAL)0x0) && (hMem != (HLOCAL)0xffffffff)) {
        if (*(HLOCAL *)((int)hMem + 8) != (HLOCAL)0x0) {
          LocalFree(*(HLOCAL *)((int)hMem + 8));
        }
        LocalFree(hMem);
      }
      wParam = wParam + 1;
    } while ((int)wParam < LVar1);
  }
  if (*(HLOCAL *)(param_1 + 0x54) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  return;
}



/* 402eebe4 FUN_402eebe4 */

/* Boundary evidence: original MIPS .pdata 402eebe4..402eecef. Semantic name remains unreviewed. */

void FUN_402eebe4(HWND param_1,int param_2)

{
  LRESULT LVar1;
  WPARAM wParam;
  uint bEnable;
  
  LVar1 = SendDlgItemMessageW(param_1,0x503,0xf0,0,0);
  bEnable = (uint)(LVar1 == 0);
  EnableWindow(*(HWND *)(param_2 + 0x34),bEnable);
  EnableWindow(*(HWND *)(param_2 + 0x38),bEnable);
  EnableWindow(*(HWND *)(param_2 + 0x3c),bEnable);
  if (bEnable == 0) {
    SendDlgItemMessageW(param_1,0x4fb,0xf1,0,0);
  }
  LVar1 = SendDlgItemMessageW(param_1,0x4fb,0xf0,0,0);
  EnableWindow(*(HWND *)(param_2 + 0x38),LVar1);
  EnableWindow(*(HWND *)(param_2 + 0x3c),LVar1);
  if ((LVar1 != 0) &&
     (wParam = SendMessageW(*(HWND *)(param_2 + 0x38),0x147,0,0), wParam != 0xffffffff)) {
    SendMessageW(*(HWND *)(param_2 + 0x38),0x150,wParam,0);
  }
  return;
}



/* 402eecf0 FUN_402eecf0 */

/* Boundary evidence: original MIPS .pdata 402eecf0..402eeddf. Semantic name remains unreviewed. */

undefined4 FUN_402eecf0(HWND param_1,int param_2)

{
  wchar_t *lpString;
  uint _Value;
  int iVar1;
  wchar_t awStack_38 [16];
  uint local_18;
  
  local_18 = DAT_402f65fc;
  SendDlgItemMessageW(param_1,0x4f3,0xf1,(uint)((*(uint *)(param_2 + 0x5c) & 1) == 0),0);
  iVar1 = 0;
  if (*(int *)(param_2 + 200) != 0) {
    iVar1 = 8;
  }
  u____________________________402f6550[iVar1] = L'\0';
  SetWindowTextW(*(HWND *)(param_2 + 0x2c),u____________________________402f6550);
  u____________________________402f6550[iVar1] = L'*';
  SendMessageW(*(HWND *)(param_2 + 0x30),0xc5,1,0);
  _Value = *(int *)(param_2 + 0xc4) + 1;
  if ((_Value == 0) || (4 < _Value)) {
    *(undefined4 *)(param_2 + 0xc4) = 0;
  }
  else {
    lpString = _itow(_Value,awStack_38,10);
    SetWindowTextW(*(HWND *)(param_2 + 0x30),lpString);
  }
  FUN_402f41d8(local_18);
  return 0;
}



/* 402eede0 FUN_402eede0 */

/* Boundary evidence: original MIPS .pdata 402eede0..402eefb7. Semantic name remains unreviewed. */

undefined4 FUN_402eede0(int param_1,char *param_2,int param_3)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  byte local_28 [16];
  uint local_18;
  
  local_18 = DAT_402f65fc;
  local_28[0] = 0x56;
  local_28[1] = 9;
  local_28[2] = 8;
  local_28[3] = 0x98;
  local_28[4] = 0x4d;
  local_28[5] = 8;
  local_28[6] = 0x11;
  local_28[7] = 0x66;
  local_28[8] = 0x42;
  local_28[9] = 3;
  local_28[10] = 1;
  local_28[0xb] = 0x67;
  local_28[0xc] = 0x66;
  if (param_3 == 0) {
    sVar2 = strlen(param_2);
    iVar3 = memcmp(param_2,s____________________________402f6588,sVar2);
    if (iVar3 == 0) goto LAB_402eef98;
    if ((*(uint *)(param_1 + 0x5c) & 2) == 0) {
      sVar2 = strlen(param_2);
      *(size_t *)(param_1 + 200) = sVar2;
      memcpy((void *)(param_1 + 0xcc),param_2,sVar2);
    }
    else {
      iVar3 = (int)*param_2;
      iVar5 = 0;
      if (iVar3 != 0) {
        do {
          if (iVar3 < 0x3a) {
            iVar3 = iVar3 + -0x30;
          }
          else if (iVar3 < 0x47) {
            iVar3 = iVar3 + -0x37;
          }
          else {
            iVar3 = iVar3 + -0x57;
          }
          pbVar8 = (byte *)(param_1 + 0xcc + iVar5);
          bVar6 = (byte)(iVar3 << 4);
          *pbVar8 = bVar6;
          cVar1 = param_2[1];
          if (cVar1 < ':') {
            bVar4 = cVar1 - 0x30;
          }
          else {
            bVar4 = cVar1 - 0x37;
            if ('F' < cVar1) {
              bVar4 = cVar1 + 0xa9;
            }
          }
          param_2 = param_2 + 2;
          *pbVar8 = bVar6 | bVar4;
          iVar3 = (int)*param_2;
          iVar5 = iVar5 + 1;
        } while (iVar3 != 0);
      }
      *(int *)(param_1 + 200) = iVar5;
    }
  }
  pbVar8 = (byte *)(param_1 + 0xcc);
  uVar7 = 0;
  iVar3 = 0x20;
  do {
    uVar9 = uVar7 % 0xd;
    uVar7 = uVar7 + 7;
    iVar3 = iVar3 + -1;
    *pbVar8 = local_28[uVar9] ^ *pbVar8;
    pbVar8 = pbVar8 + 1;
  } while (iVar3 != 0);
LAB_402eef98:
  FUN_402f41d8(local_18);
  return 0;
}



/* 402eefb8 FUN_402eefb8 */

/* Boundary evidence: original MIPS .pdata 402eefb8..402ef9df. Semantic name remains unreviewed. */

void FUN_402eefb8(HWND param_1,int param_2)

{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  WPARAM WVar4;
  int iVar5;
  LRESULT LVar6;
  HWND hWnd;
  BOOL BVar7;
  UINT Msg;
  undefined *lParam;
  wchar_t awStack_70 [16];
  wchar_t awStack_50 [16];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  bVar3 = false;
  bVar2 = 0;
  bVar1 = false;
  FUN_402eebe4(param_1,param_2);
  WVar4 = SendMessageW(*(HWND *)(param_2 + 0x20),0x147,0,0);
  if (WVar4 != 0xffffffff) {
    SendMessageW(*(HWND *)(param_2 + 0x20),0x148,WVar4,(LPARAM)awStack_50);
    iVar5 = wcscmp(awStack_50,(wchar_t *)&DAT_402fc0c0);
    if (iVar5 == 0) {
      SendDlgItemMessageW(param_1,0x4fb,0xf1,0,0);
      EnableWindow(*(HWND *)(param_2 + 0x34),0);
      EnableWindow(*(HWND *)(param_2 + 0x38),0);
      hWnd = *(HWND *)(param_2 + 0x3c);
    }
    else {
      hWnd = *(HWND *)(param_2 + 0x14);
    }
    EnableWindow(hWnd,(uint)(iVar5 != 0));
  }
  if (((*(uint *)(param_2 + 0x48) & 0x100) != 0) &&
     (LVar6 = SendMessageW(*(HWND *)(param_2 + 0x14),0x158,0,0x402fc0e0), LVar6 == -1)) {
    SendMessageW(*(HWND *)(param_2 + 0x14),0x143,0,0x402fc0e0);
  }
  if (((*(uint *)(param_2 + 0x48) & 0x200) != 0) &&
     (LVar6 = SendMessageW(*(HWND *)(param_2 + 0x14),0x158,0,0x402fc180), LVar6 == -1)) {
    SendMessageW(*(HWND *)(param_2 + 0x14),0x143,0,0x402fc180);
  }
  WVar4 = SendMessageW(*(HWND *)(param_2 + 0x14),0x147,0,0);
  if (WVar4 != 0xffffffff) {
    SendMessageW(*(HWND *)(param_2 + 0x14),0x148,WVar4,(LPARAM)awStack_70);
    LVar6 = SendMessageW(*(HWND *)(param_2 + 0x10),0xf0,0,0);
    if (LVar6 == 1) {
      iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc0e0);
      if ((((iVar5 == 0) || (iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc180), iVar5 == 0)) ||
          (iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc120), iVar5 == 0)) &&
         (WVar4 = SendMessageW(*(HWND *)(param_2 + 0x14),0x158,0,0x402fc160), WVar4 != 0xffffffff))
      {
        SendMessageW(*(HWND *)(param_2 + 0x14),0x14e,WVar4,0);
        wcscpy(awStack_70,(wchar_t *)&DAT_402fc160);
      }
      WVar4 = SendMessageW(*(HWND *)(param_2 + 0x14),0x158,0,0x402fc0e0);
      if (WVar4 != 0xffffffff) {
        SendMessageW(*(HWND *)(param_2 + 0x14),0x144,WVar4,0);
      }
      WVar4 = SendMessageW(*(HWND *)(param_2 + 0x14),0x158,0,0x402fc180);
      if (WVar4 != 0xffffffff) {
        SendMessageW(*(HWND *)(param_2 + 0x14),0x144,WVar4,0);
      }
      WVar4 = SendMessageW(*(HWND *)(param_2 + 0x14),0x158,0,0x402fc120);
      if (WVar4 != 0xffffffff) {
        SendMessageW(*(HWND *)(param_2 + 0x14),0x144,WVar4,0);
      }
    }
    iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc0e0);
    if ((((iVar5 == 0) || (iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc160), iVar5 == 0)) ||
        ((iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc180), iVar5 == 0 ||
         (iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc120), iVar5 == 0)))) &&
       (LVar6 = SendMessageW(*(HWND *)(param_2 + 0x10),0xf0,0,0), LVar6 != 1)) {
      iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc160);
      if (iVar5 == 0) {
LAB_402ef348:
        WVar4 = 0;
      }
      else {
        iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc120);
        WVar4 = 1;
        if (iVar5 == 0) goto LAB_402ef348;
      }
      SendMessageW(*(HWND *)(param_2 + 0x24),0xf1,WVar4,0);
      SetWindowTextW(*(HWND *)(param_2 + 0x30),L"1");
      WVar4 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc0c0);
      if (WVar4 != 0xffffffff) {
        SendMessageW(*(HWND *)(param_2 + 0x20),0x144,WVar4,0);
      }
      iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc0e0);
      if ((iVar5 == 0) || (iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc180), iVar5 == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      LVar6 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc100);
      if (LVar6 == -1) {
        SendMessageW(*(HWND *)(param_2 + 0x20),0x143,0,0x402fc100);
      }
      if ((((*(uint *)(param_2 + 0x48) & 0x200) != 0) || (*(int *)(param_2 + 0x4c) != 0)) &&
         (LVar6 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc1c0), LVar6 == -1)) {
        SendMessageW(*(HWND *)(param_2 + 0x20),0x143,0,0x402fc1c0);
      }
      WVar4 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc140);
      if (WVar4 != 0xffffffff) {
        SendMessageW(*(HWND *)(param_2 + 0x20),0x144,WVar4,0);
      }
      LVar6 = SendMessageW(*(HWND *)(param_2 + 0x20),0x147,0,0);
      if (LVar6 == -1) {
        SendMessageW(*(HWND *)(param_2 + 0x20),0x14e,0,0);
      }
      iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc160);
      if ((iVar5 == 0) || (iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc120), iVar5 == 0)) {
        SendDlgItemMessageW(param_1,0x4fb,0xf1,1,0);
        EnableWindow(*(HWND *)(param_2 + 0x34),0);
        EnableWindow(*(HWND *)(param_2 + 0x38),0);
        BVar7 = 0;
      }
      else {
        SendDlgItemMessageW(param_1,0x4fb,0xf1,1,0);
        EnableWindow(*(HWND *)(param_2 + 0x34),0);
        EnableWindow(*(HWND *)(param_2 + 0x38),1);
        BVar7 = 1;
      }
      EnableWindow(*(HWND *)(param_2 + 0x3c),BVar7);
    }
    else {
      iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc160);
      if ((iVar5 == 0) && (LVar6 = SendMessageW(*(HWND *)(param_2 + 0x10),0xf0,0,0), LVar6 == 1)) {
        bVar2 = 0;
        bVar1 = true;
        bVar3 = false;
        SendMessageW(*(HWND *)(param_2 + 0x24),0xf1,0,0);
        SetWindowTextW(*(HWND *)(param_2 + 0x30),L"1");
        WVar4 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc0c0);
        if (WVar4 != 0xffffffff) {
          SendMessageW(*(HWND *)(param_2 + 0x20),0x144,WVar4,0);
        }
        WVar4 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc140);
        if (WVar4 != 0xffffffff) {
          SendMessageW(*(HWND *)(param_2 + 0x20),0x144,WVar4,0);
        }
        LVar6 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc100);
        if (LVar6 == -1) {
          SendMessageW(*(HWND *)(param_2 + 0x20),0x143,0,0x402fc100);
        }
        if (*(int *)(param_2 + 0x4c) == 0) {
          WVar4 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc1c0);
          if (WVar4 != 0xffffffff) {
            lParam = (undefined *)0x0;
            Msg = 0x144;
            goto LAB_402ef740;
          }
        }
        else {
          lParam = &DAT_402fc1c0;
          LVar6 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc1c0);
          if (LVar6 == -1) {
            WVar4 = 0;
            Msg = 0x143;
LAB_402ef740:
            SendMessageW(*(HWND *)(param_2 + 0x20),Msg,WVar4,(LPARAM)lParam);
          }
        }
        LVar6 = SendMessageW(*(HWND *)(param_2 + 0x20),0x147,0,0);
        if (LVar6 == -1) {
          SendMessageW(*(HWND *)(param_2 + 0x20),0x14e,0,0);
        }
        goto LAB_402ef538;
      }
      iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc1a0);
      if ((iVar5 == 0) || (iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc1e0), iVar5 == 0)) {
        bVar2 = 1;
        bVar3 = true;
        WVar4 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc100);
        if (WVar4 != 0xffffffff) {
          SendMessageW(*(HWND *)(param_2 + 0x20),0x144,WVar4,0);
        }
        WVar4 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc1c0);
        if (WVar4 != 0xffffffff) {
          SendMessageW(*(HWND *)(param_2 + 0x20),0x144,WVar4,0);
        }
        LVar6 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc0c0);
        if (LVar6 == -1) {
          SendMessageW(*(HWND *)(param_2 + 0x20),0x143,0,0x402fc0c0);
        }
        LVar6 = SendMessageW(*(HWND *)(param_2 + 0x20),0x158,0,0x402fc140);
        if (LVar6 == -1) {
          SendMessageW(*(HWND *)(param_2 + 0x20),0x143,0,0x402fc140);
        }
        LVar6 = SendMessageW(*(HWND *)(param_2 + 0x20),0x147,0,0);
        if (LVar6 == -1) {
          SendMessageW(*(HWND *)(param_2 + 0x20),0x14d,0,0x402fc140);
        }
        LVar6 = SendDlgItemMessageW(param_1,0x4f3,0xf0,0,0);
        bVar1 = LVar6 != 1;
        iVar5 = wcscmp(awStack_70,(wchar_t *)&DAT_402fc1e0);
        if (iVar5 == 0) {
          SendDlgItemMessageW(param_1,0x4fb,0xf1,0,0);
          EnableWindow(*(HWND *)(param_2 + 0x34),0);
          EnableWindow(*(HWND *)(param_2 + 0x38),0);
          EnableWindow(*(HWND *)(param_2 + 0x3c),0);
        }
        goto LAB_402ef538;
      }
    }
    bVar3 = false;
    bVar2 = 0;
  }
LAB_402ef538:
  WVar4 = SendMessageW(*(HWND *)(param_2 + 0x20),0x147,0,0);
  if (WVar4 == 0xffffffff) goto LAB_402ef9a8;
  SendMessageW(*(HWND *)(param_2 + 0x20),0x148,WVar4,(LPARAM)awStack_50);
  iVar5 = wcscmp(awStack_50,(wchar_t *)&DAT_402fc0c0);
  if (iVar5 == 0) {
    EnableWindow(*(HWND *)(param_2 + 0x14),0);
    EnableWindow(*(HWND *)(param_2 + 0x24),0);
    EnableWindow(*(HWND *)(param_2 + 0x2c),0);
LAB_402ef99c:
    BVar7 = 0;
  }
  else {
    EnableWindow(*(HWND *)(param_2 + 0x24),(uint)bVar2);
    EnableWindow(*(HWND *)(param_2 + 0x2c),(uint)bVar1);
    if (!bVar3) goto LAB_402ef99c;
    LVar6 = SendDlgItemMessageW(param_1,0x4f3,0xf0,0,0);
    BVar7 = 1;
    if (LVar6 != 0) goto LAB_402ef99c;
  }
  EnableWindow(*(HWND *)(param_2 + 0x30),BVar7);
LAB_402ef9a8:
  FUN_402f41d8(local_30);
  return;
}



/* 402ef9e0 FUN_402ef9e0 */

/* Boundary evidence: original MIPS .pdata 402ef9e0..402efcef. Semantic name remains unreviewed. */

int FUN_402ef9e0(int param_1)

{
  uint uVar1;
  char *lpMultiByteStr;
  LPWSTR lpString;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  SIZE_T uBytes;
  WCHAR aWStack_28 [4];
  
  iVar5 = 0;
  GetWindowTextW(*(HWND *)(param_1 + 0x30),aWStack_28,2);
  aWStack_28[1] = 0;
  uVar1 = _wtol(aWStack_28);
  *(uint *)(param_1 + 0xc4) = uVar1 - 1;
  if ((uVar1 == 0) || (4 < uVar1)) {
    iVar5 = 0x4d3;
  }
  uVar1 = GetWindowTextLengthW(*(HWND *)(param_1 + 0x2c));
  if (uVar1 == 0) {
    return 0x4d4;
  }
  uBytes = uVar1 + 1;
  lpMultiByteStr = LocalAlloc(0,uBytes);
  lpString = LocalAlloc(0,(uVar1 + 1) * 2);
  if (lpMultiByteStr == (char *)0x0) goto LAB_402efcb8;
  if (lpString != (LPWSTR)0x0) {
    GetWindowTextW(*(HWND *)(param_1 + 0x2c),lpString,uBytes);
    WideCharToMultiByte(0,0,lpString,uBytes,lpMultiByteStr,uBytes,(LPCSTR)0x0,(LPBOOL)0x0);
    iVar2 = strncmp(lpMultiByteStr,s____________________________402f6588,uVar1);
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_1 + 0xec);
      if ((((iVar2 == 4) || (iVar2 == 7)) || ((iVar2 == 5 && (*(int *)(param_1 + 0x8c) == 4)))) ||
         (*(int *)(param_1 + 0x8c) == 6)) {
        uVar4 = *(uint *)(param_1 + 0x5c);
        *(uint *)(param_1 + 0x5c) = uVar4 | 2;
        if ((uVar1 < 8) || (0x3f < uVar1)) {
          if (uVar1 == 0x40) {
            *(undefined4 *)(param_1 + 200) = 0x20;
            *(uint *)(param_1 + 0x5c) = uVar4 | 3;
            uVar1 = 0;
            do {
              iVar2 = _isctype((int)lpMultiByteStr[uVar1],0x80);
              if (iVar2 == 0) goto LAB_402efc7c;
              uVar1 = uVar1 + 1;
            } while (uVar1 < 0x40);
            goto LAB_402efbe0;
          }
          iVar5 = 0x4d4;
        }
        else {
          (*DAT_402fc208)(param_1 + 0x58,lpMultiByteStr);
          uVar1 = 0x20;
        }
        if (iVar5 == 0) {
          *(uint *)(param_1 + 200) = uVar1;
          iVar2 = 1;
          *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | 1;
          pcVar3 = (char *)0x0;
          goto LAB_402efca8;
        }
      }
      else {
        if (uVar1 != 5) {
          if (uVar1 != 10) {
            if ((uVar1 == 0xd) || (uVar1 == 0x10)) goto LAB_402efb8c;
            if ((uVar1 != 0x1a) && (uVar1 != 0x20)) {
              iVar5 = 0x4d4;
              goto LAB_402efcb0;
            }
          }
          *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | 2;
        }
LAB_402efb8c:
        if (iVar5 == 0) {
          uVar4 = *(uint *)(param_1 + 0x5c);
          *(uint *)(param_1 + 0x5c) = uVar4 | 1;
          *(uint *)(param_1 + 200) = uVar1;
          if (((uVar4 & 2) != 0) && (uVar4 = 0, uVar1 != 0)) {
            do {
              iVar2 = _isctype((int)lpMultiByteStr[uVar4],0x80);
              if (iVar2 == 0) goto LAB_402efc7c;
              uVar4 = uVar4 + 1;
            } while (uVar4 < uVar1);
          }
LAB_402efbe0:
          iVar2 = 0;
          pcVar3 = lpMultiByteStr;
LAB_402efca8:
          FUN_402eede0(param_1,pcVar3,iVar2);
        }
      }
    }
  }
LAB_402efcb0:
  LocalFree(lpMultiByteStr);
LAB_402efcb8:
  if (lpString != (LPWSTR)0x0) {
    LocalFree(lpString);
  }
  return iVar5;
LAB_402efc7c:
  iVar5 = 0x4d5;
  goto LAB_402efcb0;
}



/* 402efcf0 FUN_402efcf0 */

/* Boundary evidence: original MIPS .pdata 402efcf0..402f0f27. Semantic name remains unreviewed. */

undefined4 FUN_402efcf0(HWND param_1,int param_2,uint param_3,int *param_4)

{
  bool bVar1;
  LRESULT LVar2;
  int iVar3;
  int iVar4;
  WPARAM WVar5;
  undefined4 *puVar6;
  HMODULE hLibModule;
  code *pcVar7;
  code *pcVar8;
  HLOCAL _Dst;
  HWND pHVar9;
  undefined *lParam;
  uint uVar10;
  UINT UVar11;
  undefined4 *puVar12;
  undefined *puVar13;
  SIZE_T local_18c;
  void *local_188;
  code *local_184;
  undefined4 *local_180;
  int local_17c;
  WCHAR aWStack_178 [16];
  WCHAR aWStack_158 [16];
  WCHAR aWStack_138 [36];
  WCHAR local_f0 [48];
  WCHAR local_90 [48];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  if (param_2 == 2) {
    PostQuitMessage(0);
    goto LAB_402f0ee0;
  }
  if (param_2 == 0x10) {
    DestroyWindow(param_1);
    goto LAB_402f0ee0;
  }
  if (param_2 == 0x4e) goto LAB_402f0ee0;
  if (param_2 == 0x110) {
    bVar1 = false;
    if (param_4 == (int *)0x0) goto LAB_402f0608;
    SetWindowLongW(param_1,-0x15,(LONG)param_4);
    memcpy(&DAT_402fbf00,param_4 + 0x16,0xc4);
    LoadStringW(DAT_402fc3c4,0x17f3,(LPWSTR)&DAT_402fc1e0,0x10);
    LoadStringW(DAT_402fc3c4,0x17f2,(LPWSTR)&DAT_402fc1a0,0x10);
    LoadStringW(DAT_402fc3c4,0x17f5,(LPWSTR)&DAT_402fc160,0x10);
    LoadStringW(DAT_402fc3c4,0x17f4,(LPWSTR)&DAT_402fc0e0,0x10);
    LoadStringW(DAT_402fc3c4,0x17f6,(LPWSTR)&DAT_402fc0c0,0x10);
    LoadStringW(DAT_402fc3c4,0x17f7,(LPWSTR)&DAT_402fc140,0x10);
    LoadStringW(DAT_402fc3c4,0x17f8,(LPWSTR)&DAT_402fc100,0x10);
    LoadStringW(DAT_402fc3c4,0x17f9,(LPWSTR)&DAT_402fc1c0,0x10);
    LoadStringW(DAT_402fc3c4,0x17fa,(LPWSTR)&DAT_402fc120,0x10);
    puVar13 = &DAT_402fc180;
    LoadStringW(DAT_402fc3c4,0x17fb,(LPWSTR)&DAT_402fc180,0x10);
    pHVar9 = GetDlgItem(param_1,0x4dc);
    param_4[3] = (int)pHVar9;
    pHVar9 = GetDlgItem(param_1,0x503);
    param_4[4] = (int)pHVar9;
    pHVar9 = GetDlgItem(param_1,0x4f2);
    param_4[8] = (int)pHVar9;
    pHVar9 = GetDlgItem(param_1,0x4f4);
    param_4[5] = (int)pHVar9;
    pHVar9 = GetDlgItem(param_1,0x4f3);
    param_4[9] = (int)pHVar9;
    pHVar9 = GetDlgItem(param_1,0x4fb);
    param_4[0xd] = (int)pHVar9;
    pHVar9 = GetDlgItem(param_1,0x4fc);
    param_4[0xe] = (int)pHVar9;
    pHVar9 = GetDlgItem(param_1,0x4fd);
    param_4[0xf] = (int)pHVar9;
    pHVar9 = GetDlgItem(param_1,0x4e6);
    param_4[0xb] = (int)pHVar9;
    pHVar9 = GetDlgItem(param_1,0x4e8);
    param_4[0xc] = (int)pHVar9;
    if (*param_4 == 0x4da) {
      if ((param_4[0x11] & 0x2000U) == 0) {
        pHVar9 = GetDlgItem(param_1,2);
      }
      else {
        pHVar9 = GetDlgItem(param_1,1);
      }
      uVar10 = GetWindowLongW(pHVar9,-0x10);
      SendMessageW(pHVar9,0xf4,uVar10 | 1,0);
    }
    iVar3 = strcmp((char *)(param_4 + 0x1b),"");
    if ((iVar3 != 0) &&
       (iVar3 = MultiByteToWideChar(0,0,(LPCSTR)(param_4 + 0x1b),param_4[0x1a],aWStack_138,0x21),
       iVar3 != 0)) {
      aWStack_138[iVar3] = L'\0';
      SetWindowTextW((HWND)param_4[3],aWStack_138);
    }
    SendMessageW((HWND)param_4[4],0xf1,(uint)(param_4[0x2e] == 0),0);
    SendMessageW((HWND)param_4[5],0x143,0,0x402fc1e0);
    SendMessageW((HWND)param_4[5],0x143,0,0x402fc1a0);
    if ((param_4[0x12] & 0x100U) != 0) {
      SendMessageW((HWND)param_4[5],0x143,0,0x402fc160);
      SendMessageW((HWND)param_4[5],0x143,0,0x402fc0e0);
    }
    if ((param_4[0x12] & 0x200U) != 0) {
      SendMessageW((HWND)param_4[5],0x143,0,0x402fc120);
      SendMessageW((HWND)param_4[5],0x143,0,0x402fc180);
    }
    uVar10 = param_4[0x11] & 0x100;
    if (uVar10 == 0) {
LAB_402f0aec:
      uVar10 = param_4[0x11] & 0x200;
      if (((uVar10 == 0) || ((param_4[0x12] & 0x200U) == 0)) || (param_4[0x3b] != 6)) {
        if (uVar10 == 0) {
LAB_402f0c6c:
          puVar13 = &DAT_402fc1a0;
LAB_402f0c74:
          SendMessageW((HWND)param_4[5],0x14d,0,(LPARAM)puVar13);
          goto LAB_402f0c8c;
        }
        if (((param_4[0x12] & 0x200U) != 0) && (param_4[0x3b] == 7)) {
          puVar13 = &DAT_402fc120;
          goto LAB_402f0c28;
        }
        if (uVar10 == 0) goto LAB_402f0c6c;
        if (((param_4[0x12] & 0x100U) != 0) && (param_4[0x3b] == 3)) {
          puVar13 = &DAT_402fc0e0;
          goto LAB_402f0c28;
        }
        if (uVar10 == 0) goto LAB_402f0c6c;
        if (((param_4[0x12] & 0x100U) == 0) || (param_4[0x3b] != 5)) {
          if (uVar10 == 0) goto LAB_402f0c6c;
          if (((param_4[0x12] & 0x100U) != 0) && (param_4[0x3b] == 4)) {
            puVar13 = &DAT_402fc160;
            goto LAB_402f0c28;
          }
          if ((uVar10 == 0) || (param_4[0x3b] != 1)) goto LAB_402f0c6c;
          puVar13 = &DAT_402fc1e0;
          goto LAB_402f0c74;
        }
        SendMessageW((HWND)param_4[5],0x14d,0,0x402fc160);
        puVar13 = (undefined *)0x0;
        WVar5 = 1;
        UVar11 = 0xf1;
        pHVar9 = (HWND)param_4[4];
      }
      else {
LAB_402f0c28:
        WVar5 = 0;
        UVar11 = 0x14d;
        pHVar9 = (HWND)param_4[5];
      }
      SendMessageW(pHVar9,UVar11,WVar5,(LPARAM)puVar13);
      bVar1 = true;
    }
    else {
      lParam = puVar13;
      if ((param_4[0x12] & 0x200U) == 0) {
        if (uVar10 == 0) goto LAB_402f0aec;
        lParam = &DAT_402fc0e0;
        if ((param_4[0x12] & 0x100U) != 0) goto LAB_402f0a98;
        if (uVar10 == 0) goto LAB_402f0aec;
        SendMessageW((HWND)param_4[5],0x14d,0,0x402fc1a0);
      }
      else {
LAB_402f0a98:
        SendMessageW((HWND)param_4[5],0x14d,0,(LPARAM)lParam);
        bVar1 = true;
      }
    }
LAB_402f0c8c:
    SendMessageW((HWND)param_4[8],0x143,0,0x402fc0c0);
    SendMessageW((HWND)param_4[8],0x143,0,0x402fc140);
    SendMessageW((HWND)param_4[8],0x143,0,0x402fc100);
    if (((param_4[0x12] & 0x200U) != 0) || (param_4[0x13] != 0)) {
      SendMessageW((HWND)param_4[8],0x143,0,0x402fc1c0);
    }
    puVar13 = &DAT_402fc1c0;
    if (((param_4[0x12] & 0x200U) == 0) || (!bVar1)) {
      if (((param_4[0x12] & 0x100U) == 0) || (!bVar1)) {
        if (param_4[0x23] == 1) {
          puVar13 = &DAT_402fc0c0;
        }
        else {
          puVar13 = &DAT_402fc140;
        }
      }
      else if ((param_4[0x13] == 0) || ((param_4[0x23] != 6 && ((param_4[0x11] & 0x100U) == 0)))) {
        puVar13 = &DAT_402fc100;
      }
    }
    else if ((param_4[0x23] == 6) || (puVar13 = &DAT_402fc100, (param_4[0x11] & 0x100U) != 0)) {
      puVar13 = &DAT_402fc1c0;
    }
    SendMessageW((HWND)param_4[8],0x14d,0,(LPARAM)puVar13);
    SendMessageW((HWND)param_4[3],0xc5,0x20,0);
    EnableWindow((HWND)param_4[3],param_4[0x11] & 1);
    EnableWindow((HWND)param_4[4],param_4[0x11] & 2);
    FUN_402eecf0(param_1,(int)param_4);
    iVar3 = FUN_402ee8d4(param_1,(int)param_4);
    if ((iVar3 == 0) && ((param_4[0x11] & 0x20U) != 0)) {
      FUN_402eebe4(param_1,(int)param_4);
    }
    else {
      EnableWindow((HWND)param_4[0xd],0);
      EnableWindow((HWND)param_4[0xe],0);
      EnableWindow((HWND)param_4[0xf],0);
    }
    param_4[1] = 0;
    param_4[0x10] = 0;
LAB_402f0ea4:
    FUN_402eefb8(param_1,(int)param_4);
    goto LAB_402f0ee0;
  }
  if (param_2 != 0x111) {
LAB_402f0608:
    FUN_402f41d8(local_30);
    return 0;
  }
  uVar10 = param_3 & 0xffff;
  param_4 = (int *)GetWindowLongW(param_1,-0x15);
  if (param_4 == (int *)0x0) goto LAB_402f0608;
  if (0x4f4 < uVar10) {
    if (uVar10 != 0x4fb) {
      if (uVar10 == 0x4fc) goto LAB_402f0360;
      if (uVar10 == 0x4fd) {
        puVar12 = (undefined4 *)0x0;
        WVar5 = SendMessageW((HWND)param_4[0xe],0x147,0,0);
        local_188 = (void *)0x0;
        local_18c = 0;
        puVar6 = (undefined4 *)SendMessageW((HWND)param_4[0xe],0x150,WVar5,0);
        if (puVar6 != (undefined4 *)0x0) {
          puVar12 = (undefined4 *)*puVar6;
        }
        local_180 = puVar6;
        if (((puVar12 != (undefined4 *)0x0) && ((LPCWSTR)(puVar12 + 0x187) != (LPCWSTR)0x0)) &&
           (hLibModule = LoadLibraryW((LPCWSTR)(puVar12 + 0x187)), hLibModule != (HMODULE)0x0)) {
          pcVar7 = (code *)GetProcAddressW(hLibModule,L"RasEapInvokeConfigUI");
          pcVar8 = (code *)GetProcAddressW(hLibModule,L"RasEapFreeMemory");
          local_184 = pcVar8;
          if (((pcVar7 != (code *)0x0) && (pcVar8 != (code *)0x0)) &&
             ((local_17c = (*pcVar7)(*puVar12,param_1,0,puVar6[2],puVar6[1],&local_188,&local_18c),
              local_17c == 0 && ((local_18c != 0 && (local_188 != (void *)0x0)))))) {
            if ((HLOCAL)puVar6[2] != (HLOCAL)0x0) {
              LocalFree((HLOCAL)puVar6[2]);
            }
            _Dst = LocalAlloc(0x40,local_18c);
            puVar6[2] = _Dst;
            if (_Dst != (HLOCAL)0x0) {
              puVar6[1] = local_18c;
              memcpy(_Dst,local_188,local_18c);
              (*pcVar8)(local_188);
            }
          }
          FreeLibrary(hLibModule);
        }
        goto LAB_402f0ee0;
      }
      if (uVar10 != 0x503) goto LAB_402f0608;
    }
    FUN_402eefb8(param_1,(int)param_4);
    goto LAB_402f0ee0;
  }
  if (uVar10 == 0x4f4) {
LAB_402f0360:
    if (param_3 >> 0x10 != 1) goto LAB_402f0ee0;
    goto LAB_402f0ea4;
  }
  if (uVar10 == 1) {
    local_90[0] = L'\0';
    local_f0[0] = L'\0';
    param_4[0x16] = 0xc4;
    LVar2 = SendMessageW((HWND)param_4[4],0xf0,0,0);
    param_4[0x2e] = (uint)(LVar2 != 1);
    GetWindowTextW((HWND)param_4[5],aWStack_178,0x10);
    iVar3 = wcscmp(aWStack_178,(wchar_t *)&DAT_402fc1e0);
    if (iVar3 == 0) {
      param_4[0x3b] = 1;
    }
    else {
      iVar3 = wcscmp(aWStack_178,(wchar_t *)&DAT_402fc180);
      if (iVar3 == 0) {
        param_4[0x3b] = 6;
      }
      else {
        iVar3 = wcscmp(aWStack_178,(wchar_t *)&DAT_402fc120);
        if (iVar3 == 0) {
          iVar3 = 7;
        }
        else {
          iVar3 = wcscmp(aWStack_178,(wchar_t *)&DAT_402fc0e0);
          if (iVar3 != 0) {
            iVar3 = wcscmp(aWStack_178,(wchar_t *)&DAT_402fc160);
            if ((iVar3 == 0) && (param_4[0x2e] == 0)) {
              param_4[0x3b] = 5;
            }
            else {
              iVar3 = wcscmp(aWStack_178,(wchar_t *)&DAT_402fc160);
              if ((iVar3 == 0) && (param_4[0x2e] == 1)) {
                param_4[0x3b] = 4;
              }
              else {
                param_4[0x3b] = 0;
              }
            }
            goto LAB_402eff80;
          }
          iVar3 = 3;
        }
        param_4[0x3b] = iVar3;
      }
    }
LAB_402eff80:
    GetWindowTextW((HWND)param_4[8],aWStack_158,0x10);
    iVar3 = wcscmp(aWStack_158,(wchar_t *)&DAT_402fc0c0);
    if (iVar3 == 0) {
      param_4[0x23] = 1;
    }
    else {
      iVar3 = wcscmp(aWStack_158,(wchar_t *)&DAT_402fc100);
      if (iVar3 == 0) {
        param_4[0x23] = 4;
      }
      else {
        iVar3 = wcscmp(aWStack_158,(wchar_t *)&DAT_402fc1c0);
        if (iVar3 == 0) {
          param_4[0x23] = 6;
        }
        else {
          param_4[0x23] = 0;
        }
      }
    }
    UVar11 = 0;
    iVar3 = GetWindowTextW((HWND)param_4[3],aWStack_138,0x21);
    iVar4 = WideCharToMultiByte(0,0,aWStack_138,iVar3,(LPSTR)(param_4 + 0x1b),0x20,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    if (iVar4 != 0) {
      param_4[0x1a] = iVar4;
    }
    if (iVar3 == 0) {
      UVar11 = 0x4d9;
      SendMessageW((HWND)param_4[3],0xb1,0xffffffff,0);
      SetFocus((HWND)param_4[3]);
    }
    if ((((param_4[0x11] & 0x1000U) != 0) && (iVar3 = FUN_402ee738((int)param_4), iVar3 != 0)) &&
       (UVar11 == 0)) {
      UVar11 = 0x4c5;
      LoadStringW(DAT_402fc3c4,param_4[0x2e] + 0x4c2,local_90,0x30);
      GetWindowTextW((HWND)param_4[3],local_f0,0x30);
      SendMessageW((HWND)param_4[3],0xb1,0,-1);
      SetFocus((HWND)param_4[3]);
    }
    if (((param_4[0x23] == 1) || (UVar11 != 0)) ||
       (LVar2 = SendDlgItemMessageW(param_1,0x4f3,0xf0,0,0), LVar2 != 0)) {
      LVar2 = SendDlgItemMessageW(param_1,0x4f3,0xf0,0,0);
      if (LVar2 != 1) goto LAB_402f0240;
      if (UVar11 == 0) {
        param_4[0x17] = param_4[0x17] & 0xfffffffc;
        memset(param_4 + 0x33,0,param_4[0x32]);
        param_4[0x32] = 0;
        goto LAB_402f0240;
      }
    }
    else {
      UVar11 = FUN_402ef9e0((int)param_4);
      if (UVar11 == 0x4d3) {
        _itow(1,local_90,10);
        _itow(4,local_f0,10);
        SendMessageW((HWND)param_4[0xc],0xb1,0xffffffff,0);
        SetFocus((HWND)param_4[0xc]);
      }
LAB_402f0240:
      if (UVar11 == 0) {
        LVar2 = SendMessageW((HWND)param_4[0xd],0xf0,0,0);
        if (LVar2 == 1) {
          WVar5 = SendMessageW((HWND)param_4[0xe],0x147,0,0);
          puVar6 = (undefined4 *)SendMessageW((HWND)param_4[0xe],0x150,WVar5,0);
          if ((puVar6 != (undefined4 *)0x0) && (puVar6 != (undefined4 *)0xffffffff)) {
            param_4[0x3f] = param_4[0x3f] | 0x80000000;
            param_4[0x3e] = 1;
            param_4[0x40] = *(int *)*puVar6;
            param_4[0x41] = puVar6[1];
            param_4[0x42] = puVar6[2];
            puVar6[2] = 0;
          }
        }
        else {
          param_4[0x3e] = 0;
          param_4[0x3f] = 0;
        }
        FUN_402eeb1c((int)param_4);
        if (((param_4[0x11] & 0x400U) == 0) &&
           (iVar3 = memcmp(&DAT_402fbf00,param_4 + 0x16,0xc4), iVar3 == 0)) {
          param_4[0x10] = 0;
        }
        else {
          param_4[0x10] = 1;
        }
        goto LAB_402efdf0;
      }
    }
    FUN_402ee7b0(param_1,UVar11,local_90,local_f0);
  }
  else {
    if (uVar10 != 2) {
      if (uVar10 == 0x4f2) goto LAB_402f0360;
      if (uVar10 != 0x4f3) goto LAB_402f0608;
      goto LAB_402f0ea4;
    }
    FUN_402eeb1c((int)param_4);
LAB_402efdf0:
    DestroyWindow(param_1);
  }
LAB_402f0ee0:
  FUN_402f41d8(local_30);
  return 1;
}



/* 402f0f28 FUN_402f0f28 */

/* Boundary evidence: original MIPS .pdata 402f0f28..402f0f33. Semantic name remains unreviewed. */

undefined4 FUN_402f0f28(void)

{
  return 1;
}



/* 402f0f34 FUN_402f0f34 */

/* Boundary evidence: original MIPS .pdata 402f0f34..402f0f3f. Semantic name remains unreviewed. */

undefined4 FUN_402f0f34(void)

{
  return 1;
}



/* 402f0f40 FUN_402f0f40 */

/* Boundary evidence: original MIPS .pdata 402f0f40..402f0f4b. Semantic name remains unreviewed. */

undefined4 FUN_402f0f40(void)

{
  return 1;
}



/* 402f0f4c FUN_402f0f4c */

/* Boundary evidence: original MIPS .pdata 402f0f4c..402f106f. Semantic name remains unreviewed. */

undefined4 FUN_402f0f4c(wint_t *param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  *param_2 = 0;
  param_2[1] = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  iVar6 = 0;
  do {
    iVar1 = iswctype(*param_1,0x80);
    if (iVar1 == 0) goto LAB_402f1050;
    uVar3 = (uint)*param_1;
    if (uVar3 < 0x61) {
      iVar1 = uVar3 - 0x37;
      if (uVar3 < 0x41) {
        iVar1 = uVar3 - 0x30;
      }
    }
    else {
      iVar1 = uVar3 - 0x57;
    }
    if ((iVar1 < 0) || (0x10 < iVar1)) goto LAB_402f1050;
    uVar4 = *param_2;
    uVar3 = (uint)((ulonglong)uVar4 * 0x10);
    iVar6 = iVar6 + 1;
    uVar5 = uVar3 + iVar1;
    *param_2 = uVar5;
    param_2[1] = param_2[1] * 0x10 + (int)((ulonglong)uVar4 * 0x10 >> 0x20) + (iVar1 >> 0x1f) +
                 (uint)(uVar5 < uVar3);
    param_1 = param_1 + 1;
  } while (iVar6 < 0xc);
  if ((*param_1 == 0x20) || (*param_1 == 0)) {
    uVar2 = 1;
  }
  else {
LAB_402f1050:
    uVar2 = 0;
  }
  return uVar2;
}



/* 402f1070 FUN_402f1070 */

undefined4 FUN_402f1070(ushort *param_1,int *param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  *param_2 = 0;
  iVar4 = 0;
  if (0 < param_3) {
    do {
      uVar2 = (uint)*param_1;
      if ((uVar2 < 0x30) || (0x39 < uVar2)) {
        if ((uVar2 < 0x41) || (0x46 < uVar2)) {
          if ((uVar2 < 0x61) || (0x66 < uVar2)) {
            return 0;
          }
          iVar3 = *param_2 * 0x10 + uVar2 + -0x57;
        }
        else {
          iVar3 = *param_2 * 0x10 + uVar2 + -0x37;
        }
      }
      else {
        iVar3 = *param_2 * 0x10 + uVar2 + -0x30;
      }
      iVar4 = iVar4 + 1;
      *param_2 = iVar3;
      param_1 = param_1 + 1;
    } while (iVar4 < param_3);
  }
  if ((param_4 == 0) || (uVar1 = 0, *param_1 == param_4)) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 402f1144 FUN_402f1144 */

/* Boundary evidence: original MIPS .pdata 402f1144..402f1327. Semantic name remains unreviewed. */

undefined4 FUN_402f1144(short *param_1,int *param_2)

{
  int iVar1;
  ushort *puVar2;
  undefined1 local_18 [8];
  
  puVar2 = (ushort *)(param_1 + 1);
  if (((*param_1 == 0x7b) && (iVar1 = FUN_402f1070(puVar2,param_2,8,0x2d), iVar1 != 0)) &&
     (iVar1 = FUN_402f1070(puVar2,(int *)local_18,4,0x2d), iVar1 != 0)) {
    *(short *)(param_2 + 1) = (short)local_18._0_4_;
    iVar1 = FUN_402f1070(puVar2,(int *)local_18,4,0x2d);
    if (iVar1 != 0) {
      *(short *)((int)param_2 + 6) = (short)local_18._0_4_;
      iVar1 = FUN_402f1070(puVar2,(int *)local_18,2,0);
      if (iVar1 != 0) {
        *(undefined1 *)(param_2 + 2) = local_18[0];
        iVar1 = FUN_402f1070(puVar2,(int *)local_18,2,0x2d);
        if (iVar1 != 0) {
          *(undefined1 *)((int)param_2 + 9) = local_18[0];
          iVar1 = FUN_402f1070(puVar2,(int *)local_18,2,0);
          if (iVar1 != 0) {
            *(undefined1 *)((int)param_2 + 10) = local_18[0];
            iVar1 = FUN_402f1070(puVar2,(int *)local_18,2,0);
            if (iVar1 != 0) {
              *(undefined1 *)((int)param_2 + 0xb) = local_18[0];
              iVar1 = FUN_402f1070(puVar2,(int *)local_18,2,0);
              if (iVar1 != 0) {
                *(undefined1 *)(param_2 + 3) = local_18[0];
                iVar1 = FUN_402f1070(puVar2,(int *)local_18,2,0);
                if (iVar1 != 0) {
                  *(undefined1 *)((int)param_2 + 0xd) = local_18[0];
                  iVar1 = FUN_402f1070(puVar2,(int *)local_18,2,0);
                  if (iVar1 != 0) {
                    *(undefined1 *)((int)param_2 + 0xe) = local_18[0];
                    iVar1 = FUN_402f1070(puVar2,(int *)local_18,2,0);
                    if ((iVar1 != 0) &&
                       (*(undefined1 *)((int)param_2 + 0xf) = local_18[0], *puVar2 == 0x7d)) {
                      if (param_1[2] != 0) {
                        return 0;
                      }
                      return 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



/* 402f1328 FUN_402f1328 */

/* Boundary evidence: original MIPS .pdata 402f1328..402f1467. Semantic name remains unreviewed. */

void FUN_402f1328(int param_1)

{
  HANDLE hDevice;
  DWORD local_278 [2];
  undefined4 local_270;
  wchar_t *local_26c;
  undefined4 local_268;
  undefined2 local_264;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_402f65fc;
  StringCchPrintfW(awStack_220,0x104,L"COMM\\%s\\Associations\\%04x%08x",&DAT_402fc02c,
                   (uint)*(ushort *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x220));
  RegDeleteKeyW((HKEY)0x80000002,awStack_220);
  hDevice = CreateFileW(L"UIO1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0xffffffff);
  if (hDevice != (HANDLE)0xffffffff) {
    local_270 = 0xffff0102;
    local_26c = L"BTPAN1";
    local_268 = *(undefined4 *)(param_1 + 0x220);
    local_264 = *(undefined2 *)(param_1 + 0x224);
    local_278[0] = 0;
    DeviceIoControl(hDevice,0x120814,&local_270,0x4c,(LPVOID)0x0,0,local_278,(LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  FUN_402f41d8(local_18);
  return;
}



/* 402f1468 FUN_402f1468 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 402f1468..402f189b. Semantic name remains unreviewed. */

bool FUN_402f1468(int param_1)

{
  LSTATUS LVar1;
  size_t sVar2;
  HANDLE hDevice;
  BOOL BVar3;
  DWORD local_3c0;
  HKEY local_3bc;
  BYTE local_3b8 [4];
  DWORD aDStack_3b4 [2];
  wchar_t *local_3ac;
  uint local_3a8;
  undefined2 local_3a4;
  undefined1 auStack_3a2 [66];
  wchar_t awStack_360 [40];
  wchar_t awStack_310 [52];
  wchar_t awStack_2a8 [60];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  StringCchPrintfW(awStack_230,0x104,L"COMM\\%s\\Associations\\%04x%08x",&DAT_402fc02c,
                   (uint)*(ushort *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x220));
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,awStack_230,0,(LPWSTR)0x0,0,0xf003f,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_3bc,aDStack_3b4);
  if (LVar1 == 0) {
    StringCchPrintfW(awStack_360,0x28,L"%04x%08x",(uint)*(ushort *)(param_1 + 0x224),
                     *(undefined4 *)(param_1 + 0x220));
    sVar2 = wcslen(awStack_360);
    RegSetValueExW(local_3bc,L"Address",0,1,(BYTE *)awStack_360,(sVar2 + 1) * 2);
    StringCchPrintfW(awStack_2a8,0x3c,L"{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
                     *(undefined4 *)(param_1 + 0x234),(uint)*(ushort *)(param_1 + 0x238),
                     (uint)*(ushort *)(param_1 + 0x23a),(uint)*(byte *)(param_1 + 0x23c),
                     (uint)*(byte *)(param_1 + 0x23d),(uint)*(byte *)(param_1 + 0x23e),
                     (uint)*(byte *)(param_1 + 0x23f),(uint)*(byte *)(param_1 + 0x240),
                     (uint)*(byte *)(param_1 + 0x241),(uint)*(byte *)(param_1 + 0x242),
                     (uint)*(byte *)(param_1 + 0x243));
    sVar2 = wcslen(awStack_2a8);
    RegSetValueExW(local_3bc,L"ServiceId",0,1,(BYTE *)awStack_2a8,(sVar2 + 1) * 2);
    StringCchPrintfW(awStack_310,0x32,L"PAN@%04x%08x",(uint)*(ushort *)(param_1 + 0x224),
                     *(undefined4 *)(param_1 + 0x220));
    sVar2 = wcslen(awStack_310);
    RegSetValueExW(local_3bc,L"SSID",0,1,(BYTE *)awStack_310,(sVar2 + 1) * 2);
    local_3b8[0] = '\x01';
    local_3b8[1] = '\0';
    local_3b8[2] = '\0';
    local_3b8[3] = '\0';
    RegSetValueExW(local_3bc,L"Priority",0,4,local_3b8,4);
    RegCloseKey(local_3bc);
    hDevice = CreateFileW(L"UIO1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0xffffffff);
    if (hDevice != (HANDLE)0xffffffff) {
      aDStack_3b4[1] = 0xffff0103;
      local_3a8 = *(uint *)(param_1 + 0x228) >> 2 & 1;
      local_3ac = L"BTPAN1";
      local_3c0 = 0;
      BVar3 = DeviceIoControl(hDevice,0x120814,aDStack_3b4 + 1,0x4c,(LPVOID)0x0,0,&local_3c0,
                              (LPOVERLAPPED)0x0);
      if (BVar3 != 0) {
        local_3ac = L"BTPAN1";
        aDStack_3b4[1] = 0xffff0104;
        local_3c0 = 0;
        local_3a8 = *(uint *)(param_1 + 0x228) >> 3 & 1;
        BVar3 = DeviceIoControl(hDevice,0x120814,aDStack_3b4 + 1,0x4c,(LPVOID)0x0,0,&local_3c0,
                                (LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          local_3a4 = *(undefined2 *)(param_1 + 0x224);
          aDStack_3b4[1] = 0xffff0101;
          local_3a8 = *(undefined4 *)(param_1 + 0x220);
          local_3ac = L"BTPAN1";
          memcpy(auStack_3a2,(undefined4 *)(param_1 + 0x234),0x10);
          local_3c0 = 0;
          BVar3 = DeviceIoControl(hDevice,0x120814,aDStack_3b4 + 1,0x4c,(LPVOID)0x0,0,&local_3c0,
                                  (LPOVERLAPPED)0x0);
          CloseHandle(hDevice);
          FUN_402f41d8(local_28);
          return BVar3 != 0;
        }
      }
      CloseHandle(hDevice);
    }
  }
  FUN_402f41d8(local_28);
  return false;
}



/* 402f189c FUN_402f189c */

/* Boundary evidence: original MIPS .pdata 402f189c..402f1d7f. Semantic name remains unreviewed. */

void FUN_402f189c(void)

{
  HMODULE pHVar1;
  LSTATUS LVar2;
  LPBYTE lpData;
  int *piVar3;
  int iVar4;
  DWORD local_38;
  DWORD local_34;
  HKEY local_30;
  HKEY local_2c;
  
  if (DAT_402fc09c == 0) {
    DAT_402fc09c = 1;
    pHVar1 = LoadLibraryW(L"coredll.dll");
    if (pHVar1 != (HMODULE)0x0) {
      DAT_402fbfcc = GetProcAddressW(pHVar1,L"RasGetEntryProperties");
      DAT_402fbfd0 = GetProcAddressW(pHVar1,L"RasSetEntryProperties");
      DAT_402fbfc8 = GetProcAddressW(pHVar1,L"RasSetEntryDialParams");
      DAT_402fbfc4 = GetProcAddressW(pHVar1,L"RasDeleteEntry");
    }
    if ((((DAT_402fbfcc == 0) || (DAT_402fbfd0 == 0)) || (DAT_402fbfc8 == 0)) || (DAT_402fbfc4 == 0)
       ) {
      DAT_402fbfcc = 0;
      DAT_402fbfd0 = 0;
      DAT_402fbfc8 = 0;
      DAT_402fbfc4 = 0;
    }
    memset(&DAT_402fbfd4,0,0x2c);
    memset(&DAT_402fc000,0,0x2c);
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"software\\microsoft\\bluetooth\\device",0,0x20019,
                          &local_2c);
    if (LVar2 == 0) {
      local_38 = 4;
      LVar2 = RegQueryValueExW(local_2c,L"DefaultMtu",(LPDWORD)0x0,&local_34,(LPBYTE)&DAT_402fc090,
                               &local_38);
      if (((LVar2 != 0) || (local_34 != 4)) || (local_38 != 4)) {
        DAT_402fc090 = 0;
      }
      local_38 = 4;
      LVar2 = RegQueryValueExW(local_2c,L"DefaultAuth",(LPDWORD)0x0,&local_34,(LPBYTE)&DAT_402fc094,
                               &local_38);
      if (((LVar2 != 0) || (local_34 != 4)) || (local_38 != 4)) {
        DAT_402fc094 = 0;
      }
      local_38 = 4;
      LVar2 = RegQueryValueExW(local_2c,L"DefaultEncrypt",(LPDWORD)0x0,&local_34,
                               (LPBYTE)&DAT_402fc098,&local_38);
      if (((LVar2 != 0) || (local_34 != 4)) || (local_38 != 4)) {
        DAT_402fc098 = 0;
      }
      iVar4 = 0;
      do {
        LVar2 = RegOpenKeyExW(local_2c,(LPCWSTR)(&PTR_u_modem_402f65a4)[iVar4],0,0xf003f,&local_30);
        if (LVar2 == 0) {
          local_38 = 4;
          lpData = (LPBYTE)(&DAT_402f65d0 + iVar4);
          LVar2 = RegQueryValueExW(local_30,L"DefaultMtu",(LPDWORD)0x0,&local_34,lpData,&local_38);
          if (((LVar2 != 0) || (local_34 != 4)) || (local_38 != 4)) {
            lpData[0] = 0xff;
            lpData[1] = 0xff;
            lpData[2] = 0xff;
            lpData[3] = 0xff;
          }
          piVar3 = &DAT_402fbfd4 + iVar4;
          local_38 = 4;
          LVar2 = RegQueryValueExW(local_30,L"DefaultAuth",(LPDWORD)0x0,&local_34,(LPBYTE)piVar3,
                                   &local_38);
          if (((LVar2 != 0) || (local_34 != 4)) || (local_38 != 4)) {
            *piVar3 = 0;
          }
          if (*piVar3 != 0) {
            *piVar3 = 1;
          }
          piVar3 = &DAT_402fc000 + iVar4;
          local_38 = 4;
          LVar2 = RegQueryValueExW(local_30,L"DefaultEncrypt",(LPDWORD)0x0,&local_34,(LPBYTE)piVar3,
                                   &local_38);
          if (((LVar2 != 0) || (local_34 != 4)) || (local_38 != 4)) {
            *piVar3 = 0;
          }
          if (*piVar3 != 0) {
            *piVar3 = 1;
          }
          if (iVar4 == 8) {
            local_38 = 100;
            LVar2 = RegQueryValueExW(local_30,L"AdapterName",(LPDWORD)0x0,&local_34,
                                     (LPBYTE)&DAT_402fc02c,&local_38);
            if (((LVar2 != 0) || (local_34 != 1)) || (99 < local_38)) {
              DAT_402fc02c = 0;
            }
          }
          RegCloseKey(local_30);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0xb);
      RegCloseKey(local_2c);
    }
  }
  return;
}



/* 402f1d80 FUN_402f1d80 */

/* Boundary evidence: original MIPS .pdata 402f1d80..402f218b. Semantic name remains unreviewed. */

undefined4 FUN_402f1d80(int *param_1)

{
  LSTATUS LVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  uint local_4b8;
  HKEY local_4b4;
  DWORD aDStack_4b0 [2];
  wchar_t awStack_4a8 [60];
  wchar_t awStack_430 [520];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  FUN_402f189c();
  if (*param_1 == -1) {
    pwVar3 = L"UNKNOWN";
  }
  else {
    pwVar3 = (wchar_t *)(&PTR_u_modem_402f65a4)[*param_1];
  }
  StringCchPrintfW(awStack_430,0x208,L"software\\microsoft\\bluetooth\\device\\%s\\%04x%08x",pwVar3,
                   (uint)*(ushort *)(param_1 + 0x89),param_1[0x88]);
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,awStack_430,0,(LPWSTR)0x0,0,0xf003f,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_4b4,aDStack_4b0);
  if (LVar1 == 0) {
    sVar2 = wcslen((wchar_t *)(param_1 + 2));
    uVar4 = 1;
    RegSetValueExW(local_4b4,L"name",0,1,(BYTE *)(param_1 + 2),(sVar2 + 1) * 2);
    sVar2 = wcslen((wchar_t *)((int)param_1 + 0x1fa));
    RegSetValueExW(local_4b4,L"port_name",0,1,(BYTE *)((int)param_1 + 0x1fa),(sVar2 + 1) * 2);
    local_4b8 = (uint)*(byte *)(param_1 + 0x8b);
    RegSetValueExW(local_4b4,L"channel",0,4,(BYTE *)&local_4b8,4);
    local_4b8 = param_1[0x8c];
    RegSetValueExW(local_4b4,L"hid_subclass",0,4,(BYTE *)&local_4b8,4);
    local_4b8 = param_1[0x91];
    RegSetValueExW(local_4b4,L"mtu",0,4,(BYTE *)&local_4b8,4);
    local_4b8 = param_1[0x8a] & 1;
    RegSetValueExW(local_4b4,L"active",0,4,(BYTE *)&local_4b8,4);
    local_4b8 = (uint)param_1[0x8a] >> 2 & 1;
    RegSetValueExW(local_4b4,L"auth",0,4,(BYTE *)&local_4b8,4);
    local_4b8 = (uint)param_1[0x8a] >> 3 & 1;
    RegSetValueExW(local_4b4,L"encrypt",0,4,(BYTE *)&local_4b8,4);
    local_4b8 = param_1[1];
    RegSetValueExW(local_4b4,L"handle",0,4,(BYTE *)&local_4b8,4);
    StringCchPrintfW(awStack_4a8,0x3c,L"{%08x-%04x-%04x-%02x%02x%02x%02x%02x%02x%02x%02x}",
                     param_1[0x8d],(uint)*(ushort *)(param_1 + 0x8e),
                     (uint)*(ushort *)((int)param_1 + 0x23a),(uint)*(byte *)(param_1 + 0x8f),
                     (uint)*(byte *)((int)param_1 + 0x23d),(uint)*(byte *)((int)param_1 + 0x23e),
                     (uint)*(byte *)((int)param_1 + 0x23f),(uint)*(byte *)(param_1 + 0x90),
                     (uint)*(byte *)((int)param_1 + 0x241),(uint)*(byte *)((int)param_1 + 0x242),
                     (uint)*(byte *)((int)param_1 + 0x243));
    sVar2 = wcslen(awStack_4a8);
    RegSetValueExW(local_4b4,L"service_id",0,1,(BYTE *)awStack_4a8,(sVar2 + 1) * 2);
    if ((BYTE *)param_1[0x92] == (BYTE *)0x0) {
      RegDeleteValueW(local_4b4,L"sdp_record");
    }
    else {
      RegSetValueExW(local_4b4,L"sdp_record",0,3,(BYTE *)param_1[0x92],param_1[0x93]);
    }
    RegCloseKey(local_4b4);
    RegFlushKey((HKEY)0x80000002);
    FUN_402f41d8(local_20);
  }
  else {
    FUN_402f41d8(local_20);
    uVar4 = 0;
  }
  return uVar4;
}



/* 402f218c FUN_402f218c */

/* Boundary evidence: original MIPS .pdata 402f218c..402f2237. Semantic name remains unreviewed. */

undefined4 FUN_402f218c(int *param_1)

{
  wchar_t *pwVar1;
  wchar_t awStack_420 [520];
  uint local_10;
  
  local_10 = DAT_402f65fc;
  FUN_402f189c();
  if (*param_1 == -1) {
    pwVar1 = L"UNKNOWN";
  }
  else {
    pwVar1 = (wchar_t *)(&PTR_u_modem_402f65a4)[*param_1];
  }
  StringCchPrintfW(awStack_420,0x208,L"software\\microsoft\\bluetooth\\device\\%s\\%04x%08x",pwVar1,
                   (uint)*(ushort *)(param_1 + 0x89),param_1[0x88]);
  RegDeleteKeyW((HKEY)0x80000002,awStack_420);
  FUN_402f41d8(local_10);
  return 1;
}



/* 402f2238 FUN_402f2238 */

/* Boundary evidence: original MIPS .pdata 402f2238..402f22ef. Semantic name remains unreviewed. */

BOOL FUN_402f2238(int param_1)

{
  HANDLE hDevice;
  BOOL BVar1;
  
  hDevice = CreateFileW(L"BHI0:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (hDevice == (HANDLE)0xffffffff) {
    BVar1 = 0;
  }
  else {
    BVar1 = DeviceIoControl(hDevice,3,(LPVOID)(param_1 + 0x220),8,(LPVOID)0x0,0,(LPDWORD)0x0,
                            (LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  return BVar1;
}



/* 402f22f0 FUN_402f22f0 */

/* Boundary evidence: original MIPS .pdata 402f22f0..402f23e3. Semantic name remains unreviewed. */

BOOL FUN_402f22f0(int param_1,int param_2)

{
  int iVar1;
  HANDLE hDevice;
  BOOL BVar2;
  
  iVar1 = ActivateDeviceEx(L"Software\\Microsoft\\Bluetooth\\Hid\\Instance",0,0,
                           L"Software\\Microsoft\\Bluetooth\\Hid\\Hid_Class");
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 != 0) {
    if (param_2 == 0) {
      return 1;
    }
    hDevice = CreateFileW(L"BHI0:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    if (hDevice != (HANDLE)0xffffffff) {
      BVar2 = DeviceIoControl(hDevice,1,(LPVOID)(param_1 + 0x220),8,(LPVOID)0x0,0,(LPDWORD)0x0,
                              (LPOVERLAPPED)0x0);
      CloseHandle(hDevice);
      return BVar2;
    }
  }
  return 0;
}



/* 402f23e4 FUN_402f23e4 */

/* Boundary evidence: original MIPS .pdata 402f23e4..402f25e7. Semantic name remains unreviewed. */

undefined4 FUN_402f23e4(int *param_1)

{
  LSTATUS LVar1;
  int iVar2;
  int iVar3;
  HKEY local_248;
  DWORD local_244 [3];
  wchar_t awStack_238 [12];
  wchar_t awStack_220 [256];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  FUN_402f189c();
  param_1[0x8a] = param_1[0x8a] & 0xfffffffe;
  if (*param_1 == 7) {
    FUN_402f2238((int)param_1);
  }
  if (param_1[1] != 0) {
    DeactivateDevice();
    param_1[1] = 0;
  }
  iVar3 = *param_1;
  if (iVar3 == 1) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Printers\\Ports",0,0xf003f,&local_248);
    if (LVar1 != 0) {
      FUN_402f41d8(local_20);
      return 0;
    }
    iVar3 = 1;
    do {
      StringCchPrintfW(awStack_238,10,L"port%d",iVar3);
      local_244[1] = 0x200;
      LVar1 = RegQueryValueExW(local_248,awStack_238,(LPDWORD)0x0,local_244,(LPBYTE)awStack_220,
                               local_244 + 1);
      if (((LVar1 == 0) && (local_244[0] == 1)) &&
         (iVar2 = _wcsicmp(awStack_220,(wchar_t *)((int)param_1 + 0x1fa)), iVar2 == 0)) {
        RegDeleteValueW(local_248,awStack_238);
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 10);
    RegCloseKey(local_248);
  }
  else if ((iVar3 == 6) && (DAT_402fbfc4 != (code *)0x0)) {
    (*DAT_402fbfc4)(0,L"`Bluetooth");
  }
  else if (iVar3 == 8) {
    FUN_402f1328((int)param_1);
  }
  *(undefined2 *)((int)param_1 + 0x1fa) = 0;
  FUN_402f41d8(local_20);
  return 1;
}



/* 402f25e8 FUN_402f25e8 */

/* Boundary evidence: original MIPS .pdata 402f25e8..402f26bf. Semantic name remains unreviewed. */

int FUN_402f25e8(void)

{
  HANDLE hObject;
  int iVar1;
  wchar_t awStack_48 [20];
  uint local_20;
  
  local_20 = DAT_402f65fc;
  iVar1 = 2;
  do {
    StringCchPrintfW(awStack_48,0x14,L"BSP%d:",iVar1);
    hObject = CreateFileW(awStack_48,0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    if (hObject == (HANDLE)0xffffffff) {
      FUN_402f41d8(local_20);
      return iVar1;
    }
    CloseHandle(hObject);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  FUN_402f41d8(local_20);
  return 10;
}



/* 402f26c0 FUN_402f26c0 */

/* Boundary evidence: original MIPS .pdata 402f26c0..402f2a3f. Semantic name remains unreviewed. */

bool FUN_402f26c0(int *param_1,undefined4 param_2)

{
  LSTATUS LVar1;
  size_t sVar2;
  int iVar3;
  bool bVar4;
  wchar_t *_Str;
  undefined4 local_res4 [3];
  HKEY local_280;
  HKEY local_27c;
  uint *local_278;
  DWORD local_274;
  uint local_270 [2];
  int local_268;
  int local_264;
  int local_260;
  uint local_23c;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  local_res4[0] = param_2;
  memset(local_270,0,0x38);
  local_268 = param_1[0x88];
  local_264 = param_1[0x89];
  local_270[0] = (uint)*(byte *)(param_1 + 0x8b);
  local_260 = param_1[0x91];
  if ((param_1[0x8a] & 4U) != 0) {
    local_23c = local_23c | 4;
  }
  if ((param_1[0x8a] & 8U) != 0) {
    local_23c = local_23c | 8;
  }
  _Str = (wchar_t *)(param_1 + 2);
  StringCchPrintfW(awStack_238,0x104,L"software\\microsoft\\bluetooth\\device\\ports\\%s",_Str);
  local_274 = 0;
  LVar1 = RegCreateKeyExW((HKEY)0x80000002,awStack_238,0,(LPWSTR)0x0,0,0x20006,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_280,&local_274);
  if (LVar1 == 0) {
    RegSetValueExW(local_280,L"dll",0,1,(BYTE *)L"btd.dll",0x10);
    RegSetValueExW(local_280,L"prefix",0,1,"B",8);
    RegSetValueExW(local_280,L"index",0,4,(BYTE *)local_res4,4);
    local_278 = local_270;
    RegSetValueExW(local_280,L"context",0,4,(BYTE *)&local_278,4);
    iVar3 = *param_1;
    if (((iVar3 == 0) || (iVar3 == 2)) || (iVar3 == 6)) {
      LVar1 = RegCreateKeyExW(local_280,L"unimodem",0,(LPWSTR)0x0,0,0x20006,
                              (LPSECURITY_ATTRIBUTES)0x0,&local_27c,&local_274);
      if (LVar1 != 0) {
        RegCloseKey(local_280);
        RegDeleteKeyW((HKEY)0x80000002,awStack_238);
        goto LAB_402f27d4;
      }
      sVar2 = wcslen(_Str);
      RegSetValueExW(local_27c,L"friendlyname",0,1,(BYTE *)_Str,(sVar2 + 1) * 2);
      RegSetValueExW(local_27c,L"tsp",0,1,(BYTE *)L"unimodem.dll",0x1a);
      local_278 = (uint *)(uint)(*param_1 == 0);
      RegSetValueExW(local_27c,L"devicetype",0,4,(BYTE *)&local_278,4);
      RegCloseKey(local_27c);
    }
    RegCloseKey(local_280);
    iVar3 = ActivateDevice(awStack_238,0);
    bVar4 = iVar3 != 0;
    param_1[1] = iVar3;
    FUN_402f41d8(local_30);
  }
  else {
LAB_402f27d4:
    FUN_402f41d8(local_30);
    bVar4 = false;
  }
  return bVar4;
}



/* 402f2a40 FUN_402f2a40 */

/* Boundary evidence: original MIPS .pdata 402f2a40..402f2fdf. Semantic name remains unreviewed. */

uint FUN_402f2a40(int *param_1,int param_2)

{
  bool bVar1;
  LSTATUS LVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  HKEY local_15a0;
  DWORD local_159c;
  DWORD local_1598;
  undefined1 local_1594;
  undefined1 local_1593;
  undefined4 local_1590;
  wchar_t awStack_158c [199];
  wchar_t awStack_13fe [257];
  wchar_t awStack_11fc [274];
  undefined4 local_fd8;
  uint local_fd4;
  wchar_t awStack_874 [17];
  wchar_t awStack_852 [128];
  undefined2 local_752;
  WCHAR aWStack_248 [12];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_402f65fc;
  FUN_402f189c();
  iVar5 = *param_1;
  iVar8 = 10;
  uVar7 = 1;
  param_1[0x8a] = param_1[0x8a] | 1;
  if ((((iVar5 == 0) || (iVar5 == 2)) || (iVar5 == 1)) || (iVar5 == 6)) {
    if (param_2 == 0) {
      sVar4 = wcslen((wchar_t *)((int)param_1 + 0x1fa));
      if (((sVar4 != 5) || (*(short *)((int)param_1 + 0x202) != 0x3a)) ||
         ((uVar6 = (uint)*(ushort *)(param_1 + 0x80), uVar6 < 0x30 ||
          (iVar5 = uVar6 - 0x30, 0x39 < uVar6)))) {
        iVar5 = 10;
      }
    }
    else {
      iVar5 = FUN_402f25e8();
    }
    if (iVar5 == 10) {
      param_1[0x8a] = param_1[0x8a] & 0xfffffffe;
    }
    else {
      if (param_2 != 0) {
        wsprintfW((LPWSTR)((int)param_1 + 0x1fa),L"BSP%d:",iVar5);
      }
      bVar1 = FUN_402f26c0(param_1,iVar5);
      uVar6 = ((uint)bVar1 ^ param_1[0x8a]) & 1 ^ param_1[0x8a];
      param_1[0x8a] = uVar6;
      if ((uVar6 & 1) != 0) goto LAB_402f2b90;
    }
LAB_402f2b38:
    FUN_402f41d8(local_28);
    uVar7 = 0;
  }
  else {
LAB_402f2b90:
    iVar5 = *param_1;
    if (iVar5 == 1) {
      LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Printers\\Ports",0,0xf003f,&local_15a0);
      if (LVar2 != 0) {
        param_1[0x8a] = param_1[0x8a] & 0xfffffffe;
        DeactivateDevice(param_1[1]);
        param_1[1] = 0;
        goto LAB_402f2b38;
      }
      iVar5 = 1;
      do {
        wsprintfW(aWStack_248,L"port%d",iVar5);
        local_1598 = 0x208;
        LVar2 = RegQueryValueExW(local_15a0,aWStack_248,(LPDWORD)0x0,&local_159c,(LPBYTE)awStack_230
                                 ,&local_1598);
        if (LVar2 == 0) {
          if ((local_159c == 1) &&
             (iVar3 = _wcsicmp(awStack_230,(wchar_t *)((int)param_1 + 0x1fa)), iVar3 == 0)) {
            RegCloseKey(local_15a0);
            goto LAB_402f2fac;
          }
        }
        else if (iVar5 < iVar8) {
          iVar8 = iVar5;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 10);
      if (iVar8 < 10) {
        wsprintfW(aWStack_248,L"port%d",iVar8);
        sVar4 = wcslen((wchar_t *)((int)param_1 + 0x1fa));
        RegSetValueExW(local_15a0,aWStack_248,0,1,(BYTE *)((int)param_1 + 0x1fa),(sVar4 + 1) * 2);
      }
      else {
        param_1[0x8a] = param_1[0x8a] & 0xfffffffe;
      }
LAB_402f2f6c:
      RegCloseKey(local_15a0);
LAB_402f2f78:
      RegFlushKey((HKEY)0x80000002);
    }
    else if ((iVar5 == 5) || (iVar5 == 9)) {
      local_159c = 0;
      LVar2 = RegCreateKeyExW((HKEY)0x80000002,
                              L"SOFTWARE\\Microsoft\\Bluetooth\\AudioGateway\\Devices\\1",0,
                              (LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_15a0,&local_159c);
      if (LVar2 == 0) {
        local_1594 = (undefined1)(short)param_1[0x89];
        local_1593 = (undefined1)((ushort)(short)param_1[0x89] >> 8);
        local_1598 = param_1[0x88];
        RegSetValueExW(local_15a0,L"Address",0,3,(BYTE *)&local_1598,6);
        RegSetValueExW(local_15a0,L"Service",0,3,(BYTE *)(param_1 + 0x8d),0x10);
        goto LAB_402f2f6c;
      }
      param_1[0x8a] = param_1[0x8a] & 0xfffffffe;
    }
    else {
      if ((iVar5 == 6) && (DAT_402fbfcc != (code *)0x0)) {
        local_fd8 = 0xd90;
        local_159c = 0xd90;
        (*DAT_402fbfcc)(0,&DAT_402d1054,&local_fd8,&local_159c,0,0);
        local_fd4 = local_fd4 & 0xfffffdf0;
        wcscpy(awStack_874,L"direct");
        wcsncpy(awStack_852,(wchar_t *)(param_1 + 2),0x80);
        local_752 = 0;
        (*DAT_402fbfd0)(0,L"`Bluetooth",&local_fd8,0xd90,0,0);
        memset(&local_1590,0,0x5b8);
        local_1590 = 0x5b8;
        wcscpy(awStack_158c,L"`Bluetooth");
        wcscpy(awStack_13fe,L"guest");
        wcscpy(awStack_11fc,L"guest");
        (*DAT_402fbfc8)(0,&local_1590,0);
        goto LAB_402f2f78;
      }
      if (iVar5 == 7) {
        uVar7 = FUN_402f22f0((int)param_1,param_2);
      }
      else {
        if (iVar5 != 8) goto LAB_402f2fa4;
        bVar1 = FUN_402f1468((int)param_1);
        uVar7 = (uint)bVar1;
      }
      param_1[0x8a] = (uVar7 ^ param_1[0x8a]) & 1 ^ param_1[0x8a];
    }
LAB_402f2fa4:
    uVar7 = param_1[0x8a] & 1;
LAB_402f2fac:
    FUN_402f41d8(local_28);
  }
  return uVar7;
}



/* 402f2fe0 FUN_402f2fe0 */

undefined4 FUN_402f2fe0(uint param_1,int param_2)

{
  uint uVar1;
  
  *(undefined4 *)(param_2 + 0x244) = DAT_402fc090;
  uVar1 = (DAT_402fc094 << 2 ^ *(uint *)(param_2 + 0x228)) & 4 ^ *(uint *)(param_2 + 0x228);
  *(uint *)(param_2 + 0x228) = uVar1;
  *(uint *)(param_2 + 0x228) = (DAT_402fc098 << 3 ^ uVar1) & 8 ^ uVar1;
  if ((-1 < (int)param_1) && (param_1 < 0xb)) {
    if (-1 < (int)(&DAT_402f65d0)[param_1]) {
      *(undefined4 *)(param_2 + 0x244) = (&DAT_402f65d0)[param_1];
    }
    uVar1 = ((&DAT_402fbfd4)[param_1] << 2 ^ *(uint *)(param_2 + 0x228)) & 4 ^
            *(uint *)(param_2 + 0x228);
    *(uint *)(param_2 + 0x228) = uVar1;
    *(uint *)(param_2 + 0x228) = ((&DAT_402fc000)[param_1] << 3 ^ uVar1) & 8 ^ uVar1;
  }
  return 1;
}



/* 402f30a8 FUN_402f30a8 */

/* Boundary evidence: original MIPS .pdata 402f30a8..402f380f. Semantic name remains unreviewed. */

undefined4 FUN_402f30a8(undefined4 param_1,undefined *param_2)

{
  LSTATUS LVar1;
  int iVar2;
  int iVar3;
  LPBYTE lpData;
  LPCWSTR lpSubKey;
  uint uVar4;
  DWORD dwIndex;
  uint uVar5;
  undefined **ppuVar6;
  DWORD local_3a0;
  DWORD local_39c;
  int local_398;
  HKEY local_394;
  HKEY local_390;
  DWORD local_38c;
  HKEY local_388 [2];
  uint local_380;
  uint local_37c;
  int local_378;
  undefined4 local_374;
  undefined4 local_370;
  undefined4 local_36c;
  uint uStack_368;
  int local_364;
  BYTE local_360 [498];
  BYTE local_16e [46];
  uint local_140;
  undefined1 local_13c;
  int local_138;
  int local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  int local_124;
  LPBYTE local_120;
  SIZE_T local_11c;
  WCHAR local_118 [52];
  short asStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_402f65fc;
  FUN_402f189c();
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"software\\microsoft\\bluetooth\\device",0,0x20019,
                        local_388);
  if (LVar1 == 0) {
    ppuVar6 = &PTR_u_modem_402f65a4;
    uVar5 = 0;
    do {
      iVar3 = 1;
      LVar1 = RegOpenKeyExW(local_388[0],(LPCWSTR)*ppuVar6,0,8,&local_390);
      if (LVar1 == 0) {
        local_118[0] = L'\0';
        dwIndex = 0;
        do {
          local_38c = 0x32;
          LVar1 = RegEnumKeyExW(local_390,dwIndex,local_118,&local_38c,(LPDWORD)0x0,(LPWSTR)0x0,
                                (LPDWORD)0x0,(PFILETIME)0x0);
          if (LVar1 != 0) break;
          iVar2 = FUN_402f0f4c((wint_t *)local_118,&local_380);
          if (iVar2 != 0) {
            lpSubKey = local_118;
            LVar1 = RegOpenKeyExW(local_390,lpSubKey,0,0x20019,&local_394);
            if (LVar1 == 0) {
              uVar4 = uVar5;
              if (0x402f65cb < (int)ppuVar6) {
                uVar4 = 0xffffffff;
              }
              FUN_402d766c(&uStack_368,lpSubKey,local_380,local_37c,uVar4);
              local_3a0 = 0x1f2;
              local_39c = 0;
              LVar1 = RegQueryValueExW(local_394,L"name",(LPDWORD)0x0,&local_39c,local_360,
                                       &local_3a0);
              if (((LVar1 != 0) || (local_39c != 1)) || (0x1f2 < local_3a0)) {
                local_360[0] = '\0';
                local_360[1] = '\0';
              }
              local_3a0 = 0x20;
              LVar1 = RegQueryValueExW(local_394,L"port_name",(LPDWORD)0x0,&local_39c,local_16e,
                                       &local_3a0);
              if (((LVar1 != 0) || (local_39c != 1)) || (0x20 < local_3a0)) {
                local_16e[0] = '\0';
                local_16e[1] = '\0';
              }
              local_398 = 0;
              local_3a0 = 4;
              LVar1 = RegQueryValueExW(local_394,L"channel",(LPDWORD)0x0,&local_39c,
                                       (LPBYTE)&local_398,&local_3a0);
              if (((LVar1 == 0) && (local_39c == 4)) && ((local_3a0 == 4 && (local_398 != 0)))) {
                local_13c = (undefined1)local_398;
              }
              local_3a0 = 4;
              LVar1 = RegQueryValueExW(local_394,L"hid_subclass",(LPDWORD)0x0,&local_39c,
                                       (LPBYTE)&local_398,&local_3a0);
              if (((LVar1 == 0) && (local_39c == 4)) && (local_3a0 == 4)) {
                local_138 = local_398;
              }
              local_3a0 = 4;
              LVar1 = RegQueryValueExW(local_394,L"handle",(LPDWORD)0x0,&local_39c,
                                       (LPBYTE)&local_398,&local_3a0);
              if (((LVar1 == 0) && (local_39c == 4)) && (local_3a0 == 4)) {
                local_364 = local_398;
              }
              local_3a0 = 4;
              LVar1 = RegQueryValueExW(local_394,L"active",(LPDWORD)0x0,&local_39c,
                                       (LPBYTE)&local_398,&local_3a0);
              if (((LVar1 == 0) && (local_39c == 4)) && ((local_3a0 == 4 && (local_398 != 0)))) {
                local_140 = local_140 | 1;
              }
              local_3a0 = 4;
              LVar1 = RegQueryValueExW(local_394,L"auth",(LPDWORD)0x0,&local_39c,(LPBYTE)&local_398,
                                       &local_3a0);
              if (((LVar1 == 0) && (local_39c == 4)) && (local_3a0 == 4)) {
                local_140 = ((uint)(local_398 != 0) << 2 ^ local_140) & 4 ^ local_140;
              }
              local_3a0 = 4;
              LVar1 = RegQueryValueExW(local_394,L"encrypt",(LPDWORD)0x0,&local_39c,
                                       (LPBYTE)&local_398,&local_3a0);
              if (((LVar1 == 0) && (local_39c == 4)) && (local_3a0 == 4)) {
                local_140 = ((uint)(local_398 != 0) << 3 ^ local_140) & 8 ^ local_140;
              }
              local_3a0 = 4;
              LVar1 = RegQueryValueExW(local_394,L"mtu",(LPDWORD)0x0,&local_39c,(LPBYTE)&local_398,
                                       &local_3a0);
              if (((LVar1 == 0) && (local_39c == 4)) && (local_3a0 == 4)) {
                local_124 = local_398;
              }
              local_3a0 = 0x80;
              LVar1 = RegQueryValueExW(local_394,L"service_id",(LPDWORD)0x0,&local_39c,
                                       (LPBYTE)asStack_b0,&local_3a0);
              if ((((LVar1 == 0) && (local_39c == 1)) && (local_3a0 < 0x80)) &&
                 (iVar3 = FUN_402f1144(asStack_b0,&local_378), iVar3 != 0)) {
                local_134 = local_378;
                local_130 = local_374;
                local_12c = local_370;
                local_128 = local_36c;
              }
              local_39c = 0;
              local_3a0 = 0;
              LVar1 = RegQueryValueExW(local_394,L"sdp_record",(LPDWORD)0x0,&local_39c,(LPBYTE)0x0,
                                       &local_3a0);
              if ((LVar1 == 0) && (local_39c == 3)) {
                lpData = LocalAlloc(0,local_3a0);
                if ((lpData == (LPBYTE)0x0) ||
                   (LVar1 = RegQueryValueExW(local_394,L"sdp_record",(LPDWORD)0x0,&local_39c,lpData,
                                             &local_3a0), LVar1 == 0)) {
                  local_11c = local_3a0;
                  local_120 = lpData;
                }
                else {
                  LocalFree(lpData);
                }
              }
              local_140 = local_140 | 2;
              RegCloseKey(local_394);
              iVar3 = (*(code *)param_2)(param_1,&uStack_368);
              if (local_120 != (LPBYTE)0x0) {
                LocalFree(local_120);
              }
            }
          }
          local_38c = 0x32;
          dwIndex = dwIndex + 1;
        } while (iVar3 != 0);
        RegCloseKey(local_390);
      }
      ppuVar6 = ppuVar6 + 1;
      uVar5 = uVar5 + 1;
    } while ((int)ppuVar6 < 0x402f65d0);
    RegCloseKey(local_388[0]);
  }
  FUN_402f41d8(local_30);
  return 0;
}



/* 402f4070 entry */

/* Boundary evidence: original MIPS .pdata 402f4070..402f40e3. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_402f40e4();
    FUN_402f4434();
  }
  uVar1 = FUN_402dc738(param_1,param_2);
  if (param_2 == 0) {
    FUN_402f43bc();
  }
  return uVar1;
}



/* 402f40e4 FUN_402f40e4 */

/* Boundary evidence: original MIPS .pdata 402f40e4..402f4157. Semantic name remains unreviewed. */

void FUN_402f40e4(void)

{
  uint uVar1;
  
  if ((DAT_402f65fc == 0) || (DAT_402f65fc == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_402f65fc = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_402f65fc == 0) {
      DAT_402f65fc = 0xb064;
    }
  }
  DAT_402f6600 = ~DAT_402f65fc;
  return;
}



/* 402f4158 FUN_402f4158 */

/* Boundary evidence: original MIPS .pdata 402f4158..402f41ab. Semantic name remains unreviewed. */

void FUN_402f4158(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_402f41d8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 402f41ac FUN_402f41ac */

/* Boundary evidence: original MIPS .pdata 402f41ac..402f41d7. Semantic name remains unreviewed. */

undefined4 FUN_402f41ac(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_402f4158(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 402f41d8 FUN_402f41d8 */

/* Boundary evidence: original MIPS .pdata 402f41d8..402f421f. Semantic name remains unreviewed. */

void FUN_402f41d8(uint param_1)

{
  if ((param_1 == DAT_402f65fc) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 402f4220 FUN_402f4220 */

/* Boundary evidence: original MIPS .pdata 402f4220..402f429b. Semantic name remains unreviewed. */

void FUN_402f4220(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_402f4158(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 402f429c FUN_402f429c */

/* Boundary evidence: original MIPS .pdata 402f429c..402f43bb. Semantic name remains unreviewed. */

void FUN_402f429c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_402fc0a0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_402fc3f8;
    if (DAT_402fc3f8 != (undefined4 *)0x0) {
      while (DAT_402fc3f4 = DAT_402fc3f4 + -1, _Memory <= DAT_402fc3f4) {
        if ((code *)*DAT_402fc3f4 != (code *)0x0) {
          (*(code *)*DAT_402fc3f4)();
          _Memory = DAT_402fc3f8;
        }
      }
      free(_Memory);
      DAT_402fc3f4 = (undefined4 *)0x0;
      DAT_402fc3f8 = (undefined4 *)0x0;
    }
    FUN_402f43e0((undefined4 *)&DAT_402d1010,(undefined4 *)&DAT_402d1014);
  }
  FUN_402f43e0((undefined4 *)&DAT_402d1018,(undefined4 *)&DAT_402d101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_402fc3fc,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 402f43bc FUN_402f43bc */

/* Boundary evidence: original MIPS .pdata 402f43bc..402f43df. Semantic name remains unreviewed. */

void FUN_402f43bc(void)

{
  FUN_402f429c(0,0,1);
  return;
}



/* 402f43e0 FUN_402f43e0 */

/* Boundary evidence: original MIPS .pdata 402f43e0..402f4433. Semantic name remains unreviewed. */

void FUN_402f43e0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 402f4434 FUN_402f4434 */

/* Boundary evidence: original MIPS .pdata 402f4434..402f446f. Semantic name remains unreviewed. */

void FUN_402f4434(void)

{
  FUN_402f43e0((undefined4 *)&DAT_402d1008,(undefined4 *)&DAT_402d100c);
  FUN_402f43e0((undefined4 *)&DAT_402d1000,(undefined4 *)&DAT_402d1004);
  return;
}


