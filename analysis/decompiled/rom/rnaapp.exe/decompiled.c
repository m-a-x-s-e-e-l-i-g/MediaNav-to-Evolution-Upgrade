/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011134 FUN_00011134 */

/* Boundary evidence: original MIPS .pdata 00011134..000111c7. Semantic name remains unreviewed. */

void FUN_00011134(HINSTANCE param_1,undefined4 param_2,ushort *param_3)

{
  WPARAM WVar1;
  
  FUN_00011444();
  WVar1 = FUN_00012c60(param_1,param_2,param_3);
  FUN_00011384(WVar1);
  FUN_000113a4(WVar1);
  return;
}



/* 000111c8 FUN_000111c8 */

/* Boundary evidence: original MIPS .pdata 000111c8..00011207. Semantic name remains unreviewed. */

void FUN_000111c8(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00011208 entry */

/* Boundary evidence: original MIPS .pdata 00011208..00011263. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,undefined4 param_2,ushort *param_3)

{
  FUN_00011480();
  FUN_00011134(param_1,param_2,param_3);
  return;
}



/* 00011264 FUN_00011264 */

/* Boundary evidence: original MIPS .pdata 00011264..00011383. Semantic name remains unreviewed. */

void FUN_00011264(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00014140 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000156fc;
    if (DAT_000156fc != (undefined4 *)0x0) {
      while (DAT_000156f8 = DAT_000156f8 + -1, _Memory <= DAT_000156f8) {
        if ((code *)*DAT_000156f8 != (code *)0x0) {
          (*(code *)*DAT_000156f8)();
          _Memory = DAT_000156fc;
        }
      }
      free(_Memory);
      DAT_000156f8 = (undefined4 *)0x0;
      DAT_000156fc = (undefined4 *)0x0;
    }
    FUN_000113f0((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_000113f0((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_00015700,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011384 FUN_00011384 */

/* Boundary evidence: original MIPS .pdata 00011384..000113a3. Semantic name remains unreviewed. */

void FUN_00011384(UINT param_1)

{
  FUN_00011264(param_1,0,0);
  return;
}



/* 000113a4 FUN_000113a4 */

/* Boundary evidence: original MIPS .pdata 000113a4..000113ef. Semantic name remains unreviewed. */

void FUN_000113a4(UINT param_1)

{
  DAT_00014140 = 0;
  FUN_000113f0((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000113f0 FUN_000113f0 */

/* Boundary evidence: original MIPS .pdata 000113f0..00011443. Semantic name remains unreviewed. */

void FUN_000113f0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00011444 FUN_00011444 */

/* Boundary evidence: original MIPS .pdata 00011444..0001147f. Semantic name remains unreviewed. */

void FUN_00011444(void)

{
  FUN_000113f0((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_000113f0((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00011480 FUN_00011480 */

/* Boundary evidence: original MIPS .pdata 00011480..000114f3. Semantic name remains unreviewed. */

void FUN_00011480(void)

{
  uint uVar1;
  
  if ((DAT_00014128 == 0) || (DAT_00014128 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00014128 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00014128 == 0) {
      DAT_00014128 = 0xb064;
    }
  }
  DAT_0001412c = ~DAT_00014128;
  return;
}



/* 0001156c FUN_0001156c */

/* Boundary evidence: original MIPS .pdata 0001156c..0001160b. Semantic name remains unreviewed. */

void FUN_0001156c(UINT param_1,UINT param_2)

{
  WCHAR aWStack_2c8 [128];
  WCHAR aWStack_1c8 [218];
  uint local_14;
  
  local_14 = DAT_00014128;
  if (DAT_000156d8 == 0) {
    LoadStringW(DAT_00014290,param_1,aWStack_1c8,0xda);
    LoadStringW(DAT_00014290,param_2,aWStack_2c8,0x80);
    ShowWindow(DAT_00014294,5);
    MessageBoxW(DAT_00014294,aWStack_1c8,aWStack_2c8,0x10030);
  }
  FUN_0001399c(local_14);
  return;
}



/* 0001160c FUN_0001160c */

/* Boundary evidence: original MIPS .pdata 0001160c..000116af. Semantic name remains unreviewed. */

void FUN_0001160c(HWND param_1)

{
  HWND pHVar1;
  wchar_t *lpString;
  WCHAR local_218 [256];
  uint local_18;
  
  local_18 = DAT_00014128;
  local_218[0] = L'\0';
  RasGetDispPhoneNumW(0,&DAT_000148c0,local_218,0x200);
  pHVar1 = GetDlgItem(param_1,0x3f0);
  SetWindowTextW(pHVar1,local_218);
  lpString = FUN_00013634();
  if (lpString != (wchar_t *)0x0) {
    pHVar1 = GetDlgItem(param_1,0x3f4);
    SetWindowTextW(pHVar1,lpString);
    LocalFree(lpString);
  }
  FUN_0001399c(local_18);
  return;
}



/* 000116b0 FUN_000116b0 */

/* Boundary evidence: original MIPS .pdata 000116b0..0001195f. Semantic name remains unreviewed. */

undefined4 FUN_000116b0(HWND param_1,int param_2,short param_3)

{
  HWND pHVar1;
  LRESULT LVar2;
  int iVar3;
  INT_PTR nResult;
  int iVar4;
  
  if (param_2 != 2) {
    if (param_2 == 0x110) {
      SetForegroundWindow(param_1);
      iVar3 = wcscmp((wchar_t *)&DAT_00015064,L"modem");
      iVar4 = DAT_000148ec;
      if (((((iVar3 == 0) ||
            (iVar3 = wcscmp((wchar_t *)&DAT_00015064,L"direct"), iVar4 = DAT_000156dc, iVar3 == 0))
           || (iVar3 = wcscmp((wchar_t *)&DAT_00015064,L"vpn"), iVar4 = DAT_00014858, iVar3 == 0))
          || (iVar3 = wcscmp((wchar_t *)&DAT_00015064,L"PPPoE"), iVar4 = DAT_00014858, iVar3 == 0))
         && (iVar4 != 0)) {
        pHVar1 = GetDlgItem(param_1,0x3f8);
        SendMessageW(pHVar1,0x172,1,iVar4);
      }
      DAT_00014144 = param_1;
      pHVar1 = GetDlgItem(param_1,0x65);
      SetWindowTextW(pHVar1,&DAT_000148c0);
      FUN_0001160c(param_1);
      SetDlgItemTextW(param_1,0x3e9,&DAT_00014432);
      SetDlgItemTextW(param_1,0x3eb,&DAT_00014634);
      SetDlgItemTextW(param_1,0x3ec,&DAT_00014836);
      if (DAT_0001428c != 0) {
        pHVar1 = GetDlgItem(param_1,0x3ed);
        SendMessageW(pHVar1,0xf1,1,0);
      }
      iVar4 = 0x3e9;
      if (DAT_00014432 != 0) {
        iVar4 = 0x3eb;
      }
      pHVar1 = GetDlgItem(param_1,iVar4);
      SetFocus(pHVar1);
    }
    else if (param_2 == 0x111) {
      if (param_3 == 2) {
        nResult = 0;
      }
      else {
        if (param_3 != 0x3ee) {
          if (param_3 != 0x3f2) {
            return 0;
          }
          lineTranslateDialog(DAT_000156f4,DAT_00014298,DAT_000156ec,param_1,(LPCSTR)0x0);
          FUN_0001160c(param_1);
          return 0;
        }
        GetDlgItemTextW(param_1,0x3e9,&DAT_00014432,0x101);
        GetDlgItemTextW(param_1,0x3eb,&DAT_00014634,0x101);
        GetDlgItemTextW(param_1,0x3ec,&DAT_00014836,0x10);
        pHVar1 = GetDlgItem(param_1,0x3ed);
        LVar2 = SendMessageW(pHVar1,0xf0,0,0);
        RasSetEntryDialParams(0,&DAT_000142a0,LVar2 == 0);
        nResult = 1;
      }
      EndDialog(param_1,nResult);
    }
  }
  return 0;
}



/* 00011960 FUN_00011960 */

/* Boundary evidence: original MIPS .pdata 00011960..000119bb. Semantic name remains unreviewed. */

void FUN_00011960(UINT param_1)

{
  HWND hWnd;
  WCHAR aWStack_110 [128];
  uint local_10;
  
  local_10 = DAT_00014128;
  LoadStringW(DAT_00014290,param_1,aWStack_110,0x80);
  hWnd = GetDlgItem(DAT_00014294,0x3f6);
  SetWindowTextW(hWnd,aWStack_110);
  FUN_0001399c(local_10);
  return;
}



/* 000119bc FUN_000119bc */

/* Boundary evidence: original MIPS .pdata 000119bc..00011bf3. Semantic name remains unreviewed. */

undefined4 FUN_000119bc(uint param_1,undefined4 param_2,int param_3)

{
  wchar_t *pwVar1;
  int iVar2;
  
  if (param_1 < 0x2a7) {
    if (param_1 == 0x2a6) {
      iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"vpn");
      if (iVar2 == 0) {
        return 0x28;
      }
      iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"PPPoE");
      if (iVar2 == 0) {
        return 0x29;
      }
      return 0x1f;
    }
    if (param_1 != 0x26b) {
      if (param_1 == 0x275) {
        iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"vpn");
        if (iVar2 != 0) {
          return param_2;
        }
        return 0x2b;
      }
      if (param_1 == 0x279) {
        pwVar1 = wcsstr((wchar_t *)&DAT_00015086,L"L2TP");
        if (pwVar1 == (wchar_t *)0x0) {
          return 0x21;
        }
        return 0x2e;
      }
      if (param_1 == 0x29a) {
        return 0x1d;
      }
      if (param_1 != 0x2a4) {
        return param_2;
      }
      return 0x1e;
    }
    iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"vpn");
    if ((iVar2 != 0) && (iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"PPPoE"), iVar2 != 0)) {
      return 0x20;
    }
  }
  else {
    if (param_1 != 0x2a7) {
      if (param_1 == 0x2a8) {
        return 0x1c;
      }
      if (param_1 != 0x2ed) {
        if (param_1 != 0x39e) {
          return param_2;
        }
        return 0x2c;
      }
      iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"vpn");
      if (iVar2 != 0) {
        return param_2;
      }
      return 0x2a;
    }
    iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"modem");
    if (iVar2 == 0) {
      return 0x1b;
    }
    iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"vpn");
    if (iVar2 != 0) {
      return 0x25;
    }
    if (param_3 != 0) {
      return 0x26;
    }
  }
  return 0x27;
}



/* 00011bf4 FUN_00011bf4 */

/* Boundary evidence: original MIPS .pdata 00011bf4..00011d0b. Semantic name remains unreviewed. */

undefined4 FUN_00011bf4(uint param_1)

{
  UINT UVar1;
  
  if (DAT_00014148 != 0) {
    DAT_0001414c = 1;
    SendMessageW(DAT_00014144,0x111,2,0);
    DAT_0001414c = 0;
  }
  FUN_00011960(0x16);
  sndPlaySoundW(L"RNIntr",0x10003);
  if (DAT_0001488c == 0) {
    DAT_0001488c = param_1;
  }
  if (DAT_00014860 != 0) {
    RasHangUp();
    DAT_00014860 = 0;
  }
  if (DAT_000156d8 == 0) {
    if (DAT_0001485c != 0) {
      DAT_00014288 = 1;
      return 1;
    }
    if (param_1 == 0) {
      return 0;
    }
    UVar1 = FUN_000119bc(param_1,0x16,0);
    FUN_0001156c(UVar1,0x17);
  }
  if (DAT_0001485c != 0) {
    DAT_00014288 = 1;
    return 1;
  }
  return 0;
}



/* 00011d0c FUN_00011d0c */

/* Boundary evidence: original MIPS .pdata 00011d0c..000121df. Semantic name remains unreviewed. */

undefined4 FUN_00011d0c(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  wchar_t *hMem;
  HWND pHVar1;
  int iVar2;
  UINT UVar3;
  DWORD DVar4;
  undefined4 uVar5;
  wchar_t awStack_218 [128];
  WCHAR aWStack_118 [128];
  uint local_18;
  
  local_18 = DAT_00014128;
  uVar5 = 1;
  if (0x2000 < param_3) {
    if (param_3 != 0x2001) goto switchD_00011d70_caseD_7;
LAB_000121b0:
    uVar5 = FUN_00011bf4(param_4);
    goto switchD_00011d70_caseD_7;
  }
  if (param_3 == 0x2000) {
    FUN_00011960(0x15);
    LoadStringW(DAT_00014290,0x18,awStack_218,0x80);
    pHVar1 = GetDlgItem(DAT_00014294,0x3f5);
    SetWindowTextW(pHVar1,awStack_218);
    pHVar1 = GetDlgItem(DAT_00014294,0x3f9);
    SetWindowTextW(pHVar1,L"");
    if (DAT_000156cc != 0) {
      iVar2 = WaitForAPIReady(0x55,0);
      if (iVar2 == 0) {
        ShowWindow(DAT_00014294,0);
      }
      else {
        SetWindowPos(DAT_00014294,(HWND)0x1,0,0,0,0,0x13);
      }
    }
    DAT_00014880 = 0x3c;
    DAT_0001488c = 0;
    DAT_00014884 = param_1;
    wcscpy((wchar_t *)&DAT_00014890,&DAT_000148c0);
    SendNotifyMessageW((HWND)0xffff,0x3fe,1,0x14880);
    sndPlaySoundW(L"RNBegin",0x10003);
    DAT_00014278 = 1;
    if (DAT_00015690 != 0) {
      DAT_000156e0 = 4;
      WriteMsgQueue(DAT_00015690,&DAT_000156e0,8,0,0);
    }
    goto switchD_00011d70_caseD_7;
  }
  switch(param_3) {
  case 0:
    FUN_00011960(3);
    if (DAT_000156d4 != 0) {
      DAT_000156d4 = 0;
      DAT_00014904 = DAT_00014904 | 0x1000000;
      RasSetEntryProperties(0,&DAT_000148c0,&DAT_00014900,0xd90,0,0);
    }
    goto switchD_00011d70_caseD_7;
  case 1:
    iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"modem");
    if (iVar2 == 0) {
      DVar4 = 0;
      if ((DAT_00014904 & 1) != 0) {
        DVar4 = 8;
      }
      if ((DAT_00014904 & 0x20000) != 0) {
        DVar4 = DVar4 | 4;
      }
      hMem = FUN_000133b4(DAT_00014298,DAT_0001490c,(short *)&DAT_00014910,&DAT_00014926,0,DVar4);
      if (hMem == (wchar_t *)0x0) {
        UVar3 = 2;
        break;
      }
      LoadStringW(DAT_00014290,1,aWStack_118,0x80);
      StringCchPrintfW(awStack_218,0x80,aWStack_118,hMem);
      LocalFree(hMem);
    }
    else {
      if (DAT_00014864 == 0) {
        UVar3 = 4;
        DAT_00014864 = DAT_00014864 + 1;
        break;
      }
      DAT_00014864 = DAT_00014864 + 1;
      LoadStringW(DAT_00014290,5,aWStack_118,0x80);
      StringCchPrintfW(awStack_218,0x80,aWStack_118,DAT_00014864);
    }
    pHVar1 = GetDlgItem(DAT_00014294,0x3f6);
    SetWindowTextW(pHVar1,awStack_218);
    goto switchD_00011d70_caseD_7;
  case 2:
    UVar3 = 6;
    break;
  case 3:
    UVar3 = 7;
    break;
  case 4:
    UVar3 = 8;
    break;
  case 5:
    UVar3 = 9;
    break;
  case 6:
    FUN_00011960(10);
    if (param_4 != 0x277) {
      if (param_4 == 0x286) {
        UVar3 = 0xc;
      }
      else if (param_4 == 0x287) {
        UVar3 = 0xd;
      }
      else if (param_4 == 0x288) {
        UVar3 = 0xe;
      }
      else if (param_4 == 0x289) {
        UVar3 = 0xf;
      }
      else if (param_4 == 0x2c5) {
        UVar3 = 0x10;
      }
      else {
        UVar3 = 0x11;
      }
      DAT_00014432 = 0;
      DAT_00014634 = 0;
      DAT_00014836 = 0;
      RasSetEntryDialParams(0,&DAT_000142a0,0);
      if (DAT_0001488c == 0) {
        DAT_0001488c = param_4;
      }
      if (DAT_000156d8 == 0) {
        DAT_0001485c = 1;
        FUN_0001156c(UVar3,0xb);
        if (DAT_00014288 != 0) {
          FUN_0001399c(local_18);
          return 0;
        }
      }
      goto switchD_00011d70_caseD_7;
    }
    param_4 = 0;
    goto LAB_000121b0;
  default:
    goto switchD_00011d70_caseD_7;
  case 10:
    UVar3 = 0x12;
    break;
  case 0xc:
    UVar3 = 0x13;
    break;
  case 0xe:
    UVar3 = 0x14;
  }
  FUN_00011960(UVar3);
switchD_00011d70_caseD_7:
  FUN_0001399c(local_18);
  return uVar5;
}



/* 000121e0 FUN_000121e0 */

/* Boundary evidence: original MIPS .pdata 000121e0..0001227f. Semantic name remains unreviewed. */

void FUN_000121e0(HWND param_1)

{
  HWND pHVar1;
  DWORD DVar2;
  DWORD DVar3;
  HWND hWnd;
  UINT uCmd;
  DWORD local_18 [2];
  
  uCmd = 0;
  hWnd = param_1;
  do {
    hWnd = GetWindow(hWnd,uCmd);
    if (hWnd == (HWND)0x0) {
      return;
    }
    pHVar1 = GetWindow(hWnd,4);
    if (pHVar1 == param_1) {
      DVar2 = GetWindowThreadProcessId(hWnd,local_18);
      DVar3 = __GetUserKData(0xc);
      if (local_18[0] != DVar3) {
        DAT_000156d0 = DVar2;
        return;
      }
    }
    uCmd = 2;
  } while( true );
}



/* 00012280 FUN_00012280 */

/* Boundary evidence: original MIPS .pdata 00012280..00012b07. Semantic name remains unreviewed. */

undefined4 FUN_00012280(HWND param_1,uint param_2,uint param_3,HWND param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  HWND hWnd;
  BOOL BVar4;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar5;
  UINT UVar6;
  uint uVar7;
  LPCWSTR lpName;
  undefined4 *lParam;
  undefined4 local_108;
  HWND local_104;
  wchar_t awStack_f8 [24];
  undefined4 local_c8;
  undefined1 local_c4 [4];
  undefined1 local_c0 [4];
  undefined1 auStack_bc [4];
  undefined1 auStack_b8 [4];
  HANDLE local_b4;
  uint local_30;
  
  local_30 = DAT_00014128;
  if (param_2 < 0x402) {
    if (param_2 == 0x401) {
      if (param_3 == 1) {
        DAT_000148bc = DAT_000148bc + 1;
      }
      else if (param_3 == 2) {
        if ((DAT_000148bc == 0) || (DAT_000148bc = DAT_000148bc + -1, DAT_000148bc == 0)) {
          SendMessageW(param_1,0x111,0x3f5,0);
        }
      }
      else if ((param_3 == 3) && (BVar4 = IsWindow(param_4), BVar4 != 0)) {
        lParam = &DAT_00014880;
        BVar4 = IsWindow(DAT_00014884);
        if (BVar4 == 0) {
          memset(&local_108,0,0x3c);
          local_108 = 0x3c;
          local_104 = param_1;
          wcscpy(awStack_f8,&DAT_000148c0);
          lParam = &local_108;
        }
        SendNotifyMessageW(param_4,0x3fe,(uint)(BVar4 != 0),(LPARAM)lParam);
      }
      goto LAB_00012acc;
    }
    if (param_2 == 2) {
      local_c8 = 0x98;
      local_c0 = (undefined1  [4])0xd;
      local_c4 = (undefined1  [4])param_1;
      iVar2 = WaitForAPIReady(0x55,0);
      if (iVar2 == 0) {
        (*(code *)&SUB_fffe67ea)(2,&local_c8,0x98);
      }
      PostQuitMessage(0);
      goto LAB_00012acc;
    }
    if (param_2 == 0x4a) {
      StringCchCopyW((STRSAFE_LPWSTR)&DAT_000156a0,0x15,(STRSAFE_LPCWSTR)param_4[2].unused);
LAB_00012658:
      FUN_0001399c(local_30);
      return 1;
    }
    if (param_2 == 0x110) {
      iVar3 = wcscmp((wchar_t *)&DAT_00015064,L"modem");
      iVar2 = DAT_000148ec;
      if (((((iVar3 == 0) ||
            (iVar3 = wcscmp((wchar_t *)&DAT_00015064,L"direct"), iVar2 = DAT_000156dc, iVar3 == 0))
           || (iVar3 = wcscmp((wchar_t *)&DAT_00015064,L"vpn"), iVar2 = DAT_00014858, iVar3 == 0))
          || (iVar3 = wcscmp((wchar_t *)&DAT_00015064,L"PPPoE"), iVar2 = DAT_00014858, iVar3 == 0))
         && (iVar2 != 0)) {
        hWnd = GetDlgItem(param_1,0x3f8);
        SendMessageW(hWnd,0x172,1,iVar2);
      }
      SetWindowTextW(param_1,(LPCWSTR)&DAT_00014150);
      local_c8 = 0x98;
      puVar1 = local_c4 + 3;
      uVar7 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar7) =
           *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | (uint)param_1 >> (3 - uVar7) * 8;
      puVar1 = local_c0 + 3;
      uVar7 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar7) =
           *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0xdU >> (3 - uVar7) * 8;
      puVar1 = auStack_bc + 3;
      uVar7 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar7) =
           *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 3U >> (3 - uVar7) * 8;
      puVar1 = auStack_b8 + 3;
      uVar7 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar7) =
           *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0x4c8U >> (3 - uVar7) * 8;
      local_c0 = (undefined1  [4])0xd;
      auStack_bc = (undefined1  [4])0x3;
      auStack_b8 = (undefined1  [4])0x4c8;
      local_c4 = (undefined1  [4])param_1;
      iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"modem");
      if (iVar2 == 0) {
        DAT_00014280 = LoadImageW(DAT_00014290,(LPCWSTR)0x69,1,0x10,0x10,0);
      }
      else {
        iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"direct");
        if (iVar2 == 0) {
          DAT_00014280 = LoadImageW(DAT_00014290,(LPCWSTR)0x6a,1,0x10,0x10,0);
        }
        else {
          iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"vpn");
          if ((iVar2 == 0) || (iVar2 = wcscmp((wchar_t *)&DAT_00015064,L"PPPoE"), iVar2 == 0)) {
            DAT_00014280 = LoadImageW(DAT_00014290,(LPCWSTR)0x70,1,0x10,0x10,0);
          }
        }
      }
      if (DAT_00014280 != (HANDLE)0x0) {
        SendMessageW(param_1,0x80,0,(LPARAM)DAT_00014280);
      }
      local_b4 = DAT_00014280;
      iVar2 = WaitForAPIReady(0x55,0);
      if (iVar2 == 0) {
        (*(code *)&SUB_fffe67ea)(0,&local_c8,0x98);
      }
      FUN_0001399c(local_30);
      return 1;
    }
    if (param_2 != 0x111) goto LAB_00012acc;
    uVar7 = param_3 & 0xffff;
    if (uVar7 != 2) {
      if (uVar7 == 0x3f5) {
        if (DAT_00014860 != 0) {
          RasHangUp();
          DAT_00014860 = 0;
        }
        if ((DAT_00014278 != 1) && (DAT_00015690 != 0)) {
          DAT_000156e0 = 3;
          WriteMsgQueue(DAT_00015690,&DAT_000156e0,8,0,0);
        }
        DAT_0001488c = 0x277;
        sndPlaySoundW(L"RNEnd",0x10003);
        uVar7 = DAT_0001488c;
        goto LAB_000129b0;
      }
      if (uVar7 != 0x3fc) goto LAB_00012acc;
    }
    iVar2 = WaitForAPIReady(0x55,0);
    if (iVar2 != 0) {
      SetWindowPos(param_1,(HWND)0x1,0,0,0,0,0x13);
      goto LAB_00012acc;
    }
    iVar2 = 0;
  }
  else {
    if (param_2 != 0x4c8) {
      if (param_2 == 0x4c9) {
        iVar2 = GetSystemMetrics(0);
        memset(&DAT_000142a0,0,0x5b8);
        DAT_000142a0 = 0x5b8;
        wcscpy((wchar_t *)&DAT_000142a4,&DAT_000148c0);
        RasGetEntryDialParams(0,&DAT_000142a0,&DAT_0001428c);
        ShowWindow(param_1,5);
        if ((DAT_00014284 == 0) && (iVar3 = wcscmp((wchar_t *)&DAT_00015064,L"modem"), iVar3 == 0))
        {
          if ((DAT_00014904 & 0x1000000) == 0) {
            DAT_000156d4 = 0;
          }
          else {
            DAT_000156d4 = 1;
            DAT_00014904 = DAT_00014904 & 0xfeffffff;
            RasSetEntryProperties(0,&DAT_000148c0,&DAT_00014900,0xd90,0,0);
          }
          lpName = (LPCWSTR)0x6c;
          if (0x1df < iVar2) {
            lpName = (LPCWSTR)0x6b;
          }
          hResInfo = FindResourceW(DAT_00014290,lpName,(LPCWSTR)0x5);
          hDialogTemplate = LoadResource(DAT_00014290,hResInfo);
          IVar5 = DialogBoxIndirectParamW(DAT_00014290,hDialogTemplate,param_1,FUN_000116b0,0);
          if (IVar5 == 0) {
            DAT_0001488c = 0x277;
            uVar7 = DAT_0001488c;
            goto LAB_000129b0;
          }
          SendMessageW(param_1,0xf,0,0);
        }
        SetForegroundWindow(param_1);
        uVar7 = RasDial(0,0,&DAT_000142a0,0xffffffff,param_1,&DAT_00014860);
        if (uVar7 == 0) goto LAB_00012acc;
        if (DAT_000156d4 != 0) {
          DAT_000156d4 = 0;
          DAT_00014904 = DAT_00014904 | 0x1000000;
          RasSetEntryProperties(0,&DAT_000148c0,&DAT_00014900,0xd90,0,0);
        }
        if ((DAT_000156d8 == 0) && (uVar7 != 0x277)) {
          UVar6 = FUN_000119bc(uVar7,0x19,1);
          FUN_0001156c(UVar6,0x17);
        }
        if (DAT_00014860 != 0) {
          RasHangUp();
          DAT_00014860 = 0;
        }
      }
      else {
        if (param_2 == 0x4ca) {
          iVar2 = wcscmp(&DAT_000148c0,(wchar_t *)&DAT_000156a0);
          SetWindowLongW(param_1,0,iVar2);
          goto LAB_00012658;
        }
        if ((param_2 != 0xcccd) ||
           (iVar2 = FUN_00011d0c(param_1,0xcccd,param_3,(uint)param_4), iVar2 != 0))
        goto LAB_00012acc;
        if (DAT_0001488c == 0) {
          DAT_0001488c = 0x274;
        }
        FUN_000121e0(param_1);
        uVar7 = DAT_0001488c;
      }
LAB_000129b0:
      DAT_0001488c = uVar7;
      DestroyWindow(param_1);
      goto LAB_00012acc;
    }
    if (param_4 != (HWND)0x203) goto LAB_00012acc;
    SetForegroundWindow(param_1);
    iVar2 = 1;
  }
  ShowWindow(param_1,iVar2);
LAB_00012acc:
  FUN_0001399c(local_30);
  return 0;
}



/* 00012b08 FUN_00012b08 */

/* Boundary evidence: original MIPS .pdata 00012b08..00012c5f. Semantic name remains unreviewed. */

undefined4 FUN_00012b08(HINSTANCE param_1)

{
  int iVar1;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  LPCWSTR lpName;
  
  GetSystemMetrics(0);
  GetSystemMetrics(1);
  DAT_000156dc = LoadIconW(param_1,(LPCWSTR)0x6a);
  DAT_000148ec = LoadIconW(param_1,(LPCWSTR)0x69);
  DAT_00014858 = LoadIconW(param_1,(LPCWSTR)0x70);
  iVar1 = GetSystemMetrics(0);
  lpName = (LPCWSTR)0x6f;
  if (0x1df < iVar1) {
    lpName = (LPCWSTR)0x6e;
  }
  hResInfo = FindResourceW(param_1,lpName,(LPCWSTR)0x5);
  lpTemplate = LoadResource(param_1,hResInfo);
  DAT_00014294 = CreateDialogIndirectParamW(param_1,lpTemplate,(HWND)0x0,FUN_00012280,0);
  if (DAT_00014294 != (HWND)0x0) {
    SetWindowLongW(DAT_00014294,8,0x6a6d6d);
    iVar1 = WaitForAPIReady(0x55,0);
    if (iVar1 == 0) {
      ShowWindow(DAT_00014294,0);
    }
    else {
      SetWindowPos(DAT_00014294,(HWND)0x1,0,0,0,0,0x13);
    }
    UpdateWindow(DAT_00014294);
    if (DAT_00014294 != (HWND)0x0) {
      return 1;
    }
  }
  return 0;
}



/* 00012c60 FUN_00012c60 */

/* Boundary evidence: original MIPS .pdata 00012c60..0001322b. Semantic name remains unreviewed. */

WPARAM FUN_00012c60(HINSTANCE param_1,undefined4 param_2,ushort *param_3)

{
  bool bVar1;
  bool bVar2;
  HWND hWnd;
  int iVar3;
  BOOL BVar4;
  ushort *puVar5;
  ushort uVar6;
  ushort *puVar7;
  ushort *puVar8;
  ushort uVar9;
  short sVar10;
  uint uVar11;
  undefined4 local_170 [2];
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  tagMSG tStack_150;
  WCHAR local_130;
  undefined1 auStack_12e [254];
  uint local_30;
  
  local_30 = DAT_00014128;
  local_130 = L'\0';
  bVar1 = false;
  bVar2 = false;
  memset(auStack_12e,0,0xfe);
  DAT_00014294 = (HWND)0x0;
  DAT_00014290 = param_1;
  memset(&DAT_00014880,0,0x3c);
  memset(&tStack_150,0,0x1c);
  local_164 = 2;
  local_160 = 8;
  local_15c = 8;
  local_168 = 0x14;
  local_158 = 0;
  DAT_00015690 = CreateMsgQueue(L"AutorasMsgqueue",&local_168);
  if (DAT_00015690 != 0) {
    DAT_000156e0 = 1;
    WriteMsgQueue(DAT_00015690,&DAT_000156e0,8,0,0);
  }
  uVar6 = *param_3;
  iVar3 = DAT_00014888;
  sVar10 = DAT_000148c0;
  if (uVar6 == 0) {
LAB_00012f80:
    if (sVar10 == 0) goto LAB_0001313c;
    LoadStringW(DAT_00014290,0x2d,&local_130,0x80);
    StringCchPrintfW((STRSAFE_LPWSTR)&DAT_00014150,0x94,&local_130,&DAT_000148c0);
    hWnd = FindWindowW(L"DIALOG",(LPCWSTR)&DAT_00014150);
    if (hWnd != (HWND)0x0) {
      SetForegroundWindow(hWnd);
      ShowWindow(hWnd,1);
      FUN_0001399c(local_30);
      return 0;
    }
    RasEnumEntries(0,0,0,local_170,0);
    DAT_00014900 = 0xd90;
    local_170[0] = 0xd90;
    iVar3 = RasGetEntryProperties(0,&DAT_000148c0,&DAT_00014900,local_170,0,0);
    if (iVar3 == 0) {
      iVar3 = FUN_00012b08(param_1);
      if (iVar3 == 0) {
        DAT_0001488c = 0x57;
      }
      else {
        PostMessageW(DAT_00014294,0x4c9,0,0);
        FUN_0001322c(param_1,(LINECALLBACK)&LAB_00011564,(LPCSTR)L"rnaapp",0);
        bVar2 = true;
        DAT_00014298 = FUN_00013848((wchar_t *)&DAT_00015086,0x80);
        while (BVar4 = GetMessageW(&tStack_150,(HWND)0x0,0,0), BVar4 != 0) {
          if ((DAT_00014294 == (HWND)0x0) ||
             (BVar4 = IsDialogMessageW(DAT_00014294,&tStack_150), BVar4 == 0)) {
            TranslateMessage(&tStack_150);
            DispatchMessageW(&tStack_150);
          }
        }
      }
      goto LAB_00013150;
    }
    DAT_0001488c = 0x26f;
  }
  else {
    do {
      puVar8 = param_3;
      if (bVar1) goto LAB_0001313c;
      while (uVar6 == 0x20) {
        uVar6 = puVar8[1];
        puVar8 = puVar8 + 1;
      }
      if ((*puVar8 == 0x2d) || (param_3 = puVar8, *puVar8 == 0x2f)) {
        param_3 = puVar8 + 1;
        uVar6 = *param_3;
        if (uVar6 < 100) {
          if ((uVar6 != 99) && (uVar6 != 0x43)) {
            if (uVar6 == 0x45) goto LAB_00012ef4;
            if (uVar6 == 0x4d) goto LAB_00012eec;
            if (uVar6 == 0x4e) goto LAB_00012ee0;
            uVar9 = 0x50;
LAB_00012ed0:
            if (uVar6 == uVar9) {
              DAT_00014284 = 1;
              goto LAB_00012ee4;
            }
            goto LAB_00012efc;
          }
          while( true ) {
            param_3 = param_3 + 1;
            uVar6 = *param_3;
            if (((uVar6 < 0x30) || (0x39 < uVar6)) && ((uVar6 < 0x41 || (0x46 < uVar6)))) break;
            uVar11 = (uint)*param_3;
            if ((uVar11 < 0x30) || (0x39 < uVar11)) {
              iVar3 = uVar11 + iVar3 * 0x10 + -0x37;
              DAT_00014888 = iVar3;
            }
            else {
              iVar3 = uVar11 + iVar3 * 0x10 + -0x30;
              DAT_00014888 = iVar3;
            }
          }
        }
        else if (uVar6 == 0x65) {
LAB_00012ef4:
          if (sVar10 != 0) goto LAB_00012efc;
          puVar7 = puVar8 + 2;
          uVar6 = *puVar7;
          if (uVar6 == 0x22) {
            puVar7 = puVar8 + 3;
          }
          uVar11 = 0;
          if (*puVar7 != 0) {
            puVar8 = puVar7;
            do {
              if (0x14 < uVar11) break;
              uVar9 = *puVar8;
              if (uVar6 != 0x22) {
                if (uVar9 == 0x20) break;
              }
              else if (uVar9 == 0x22) {
                puVar7 = puVar7 + 1;
                break;
              }
              puVar5 = (ushort *)(((int)&DAT_000148c0 - (int)puVar7) + (int)puVar8);
              puVar8 = puVar8 + 1;
              *puVar5 = uVar9;
              uVar11 = uVar11 + 1;
            } while (*puVar8 != 0);
          }
          param_3 = puVar7 + uVar11;
          (&DAT_000148c0)[uVar11] = 0;
          sVar10 = DAT_000148c0;
        }
        else {
          if (uVar6 == 0x6d) {
LAB_00012eec:
            DAT_000156cc = 1;
          }
          else {
            if (uVar6 != 0x6e) {
              uVar9 = 0x70;
              goto LAB_00012ed0;
            }
LAB_00012ee0:
            DAT_000156d8 = 1;
          }
LAB_00012ee4:
          param_3 = puVar8 + 2;
        }
      }
      else {
LAB_00012efc:
        bVar1 = true;
      }
      uVar6 = *param_3;
    } while (uVar6 != 0);
    if (!bVar1) goto LAB_00012f80;
LAB_0001313c:
    DAT_0001488c = 0x57;
  }
  FUN_0001156c(0x22,0x17);
LAB_00013150:
  if (DAT_000156d0 != 0) {
    PostThreadMessageW(DAT_000156d0,0,0,0);
  }
  if ((DAT_000156f4 != 0) && (bVar2)) {
    lineShutdown(DAT_000156f4);
  }
  DAT_00014880 = 0x3c;
  DAT_00014884 = 0;
  wcscpy((wchar_t *)&DAT_00014890,&DAT_000148c0);
  SendNotifyMessageW((HWND)0xffff,0x3fe,0,0x14880);
  if (DAT_00015690 != 0) {
    DAT_000156e0 = 2;
    WriteMsgQueue(DAT_00015690,&DAT_000156e0,8,0,0);
    CloseMsgQueue(DAT_00015690);
  }
  FUN_0001399c(local_30);
  return tStack_150.wParam;
}



/* 0001322c FUN_0001322c */

/* Boundary evidence: original MIPS .pdata 0001322c..0001327b. Semantic name remains unreviewed. */

void FUN_0001322c(HINSTANCE param_1,LINECALLBACK param_2,LPCSTR param_3,undefined4 param_4)

{
  DAT_000156e8 = param_4;
  lineInitialize(&DAT_000156f4,param_1,param_2,param_3,&DAT_000156f0);
  DAT_000156ec = 0x10005;
  return;
}



/* 0001327c FUN_0001327c */

/* Boundary evidence: original MIPS .pdata 0001327c..000132df. Semantic name remains unreviewed. */

undefined4 FUN_0001327c(DWORD param_1)

{
  LONG LVar1;
  DWORD local_20 [2];
  lineextensionid_tag lStack_18;
  
  LVar1 = lineNegotiateAPIVersion(DAT_000156f4,param_1,0x10005,0x10005,local_20,&lStack_18);
  if (LVar1 == 0) {
    DAT_000156ec = local_20[0];
  }
  return 0x10005;
}



/* 000132e0 FUN_000132e0 */

/* Boundary evidence: original MIPS .pdata 000132e0..000133b3. Semantic name remains unreviewed. */

LPLINEDEVCAPS FUN_000132e0(DWORD param_1,DWORD param_2)

{
  LPLINEDEVCAPS lpLineDevCaps;
  LONG LVar1;
  DWORD uBytes;
  
  uBytes = 0x124;
  lpLineDevCaps = LocalAlloc(0x40,0x124);
  while( true ) {
    if (lpLineDevCaps == (LPLINEDEVCAPS)0x0) {
      return (LPLINEDEVCAPS)0x0;
    }
    lpLineDevCaps->dwTotalSize = uBytes;
    LVar1 = lineGetDevCaps(DAT_000156f4,param_1,param_2,0,lpLineDevCaps);
    if (LVar1 != 0) break;
    uBytes = lpLineDevCaps->dwNeededSize;
    if (uBytes <= lpLineDevCaps->dwTotalSize) {
      return lpLineDevCaps;
    }
    LocalFree(lpLineDevCaps);
    lpLineDevCaps = LocalAlloc(0x40,uBytes);
  }
  LocalFree(lpLineDevCaps);
  return (LPLINEDEVCAPS)0x0;
}



/* 000133b4 FUN_000133b4 */

/* Boundary evidence: original MIPS .pdata 000133b4..00013573. Semantic name remains unreviewed. */

wchar_t * FUN_000133b4(DWORD param_1,undefined4 param_2,short *param_3,undefined4 param_4,
                      int param_5,DWORD param_6)

{
  DWORD dwAPIVersion;
  LPLINETRANSLATEOUTPUT lpTranslateOutput;
  LONG LVar1;
  size_t sVar2;
  wchar_t *_Dest;
  DWORD DVar3;
  wchar_t *_Str;
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_00014128;
  if ((param_3 == (short *)0x0) || (*param_3 == 0)) {
    StringCchPrintfW(awStack_228,0x100,L"+%d %s",param_2,param_4);
  }
  else {
    StringCchPrintfW(awStack_228,0x100,L"+%d (%s) %s",param_2,param_3,param_4);
  }
  dwAPIVersion = FUN_0001327c(param_1);
  DVar3 = 0x28;
  lpTranslateOutput = LocalAlloc(0x40,0x28);
  while( true ) {
    if (lpTranslateOutput == (LPLINETRANSLATEOUTPUT)0x0) {
      FUN_0001399c(local_28);
      return (wchar_t *)0x0;
    }
    lpTranslateOutput->dwTotalSize = DVar3;
    LVar1 = lineTranslateAddress
                      (DAT_000156f4,param_1,dwAPIVersion,(LPCSTR)awStack_228,0,param_6,
                       lpTranslateOutput);
    if (LVar1 != 0) break;
    DVar3 = lpTranslateOutput->dwNeededSize;
    if (DVar3 <= lpTranslateOutput->dwTotalSize) {
      if (param_5 == 0) {
        DVar3 = lpTranslateOutput->dwDisplayableStringOffset;
      }
      else {
        DVar3 = lpTranslateOutput->dwDialableStringOffset;
      }
      _Str = (wchar_t *)((int)&lpTranslateOutput->dwTotalSize + DVar3);
      sVar2 = wcslen(_Str);
      _Dest = LocalAlloc(0x40,(sVar2 + 1) * 2);
      if (_Dest != (wchar_t *)0x0) {
        wcscpy(_Dest,_Str);
      }
      goto LAB_0001355c;
    }
    LocalFree(lpTranslateOutput);
    lpTranslateOutput = LocalAlloc(0x40,DVar3);
  }
  _Dest = (wchar_t *)0x0;
LAB_0001355c:
  LocalFree(lpTranslateOutput);
  FUN_0001399c(local_28);
  return _Dest;
}



/* 00013574 FUN_00013574 */

/* Boundary evidence: original MIPS .pdata 00013574..00013633. Semantic name remains unreviewed. */

LPLINETRANSLATECAPS FUN_00013574(void)

{
  LPLINETRANSLATECAPS lpTranslateCaps;
  LONG LVar1;
  DWORD uBytes;
  
  uBytes = 0x2c;
  lpTranslateCaps = LocalAlloc(0x40,0x2c);
  while( true ) {
    if (lpTranslateCaps == (LPLINETRANSLATECAPS)0x0) {
      return (LPLINETRANSLATECAPS)0x0;
    }
    lpTranslateCaps->dwTotalSize = uBytes;
    LVar1 = lineGetTranslateCaps(DAT_000156f4,DAT_000156ec,lpTranslateCaps);
    if (LVar1 != 0) break;
    uBytes = lpTranslateCaps->dwNeededSize;
    if (uBytes <= lpTranslateCaps->dwTotalSize) {
      return lpTranslateCaps;
    }
    LocalFree(lpTranslateCaps);
    lpTranslateCaps = LocalAlloc(0x40,uBytes);
  }
  LocalFree(lpTranslateCaps);
  return (LPLINETRANSLATECAPS)0x0;
}



/* 00013634 FUN_00013634 */

/* Boundary evidence: original MIPS .pdata 00013634..00013727. Semantic name remains unreviewed. */

wchar_t * FUN_00013634(void)

{
  LPLINETRANSLATECAPS hMem;
  size_t sVar1;
  wchar_t *_Dest;
  DWORD *pDVar2;
  int iVar3;
  DWORD *pDVar4;
  
  _Dest = (wchar_t *)0x0;
  hMem = FUN_00013574();
  if (hMem != (LPLINETRANSLATECAPS)0x0) {
    if (hMem->dwLocationListSize != 0) {
      pDVar4 = (DWORD *)((int)&hMem->dwTotalSize + hMem->dwLocationListOffset);
      iVar3 = 0;
      pDVar2 = pDVar4;
      if (0 < (int)hMem->dwNumLocations) {
        do {
          if (*pDVar2 == hMem->dwCurrentLocationID) {
            sVar1 = wcslen((wchar_t *)((int)&hMem->dwTotalSize + pDVar2[2]));
            _Dest = LocalAlloc(0x40,(sVar1 + 1) * 2);
            if (_Dest != (wchar_t *)0x0) {
              wcscpy(_Dest,(wchar_t *)((int)&hMem->dwTotalSize + pDVar4[iVar3 * 0x11 + 2]));
              break;
            }
          }
          iVar3 = iVar3 + 1;
          pDVar2 = pDVar2 + 0x11;
        } while (iVar3 < (int)hMem->dwNumLocations);
      }
    }
    LocalFree(hMem);
  }
  return _Dest;
}



/* 00013728 FUN_00013728 */

/* Boundary evidence: original MIPS .pdata 00013728..00013847. Semantic name remains unreviewed. */

STRSAFE_LPWSTR FUN_00013728(DWORD param_1,undefined2 *param_2,uint *param_3)

{
  DWORD DVar1;
  LPLINEDEVCAPS hMem;
  HRESULT HVar2;
  undefined2 *puVar3;
  STRSAFE_LPWSTR pszDest;
  
  pszDest = (STRSAFE_LPWSTR)0x0;
  DVar1 = FUN_0001327c(param_1);
  if ((DVar1 != 0) && (hMem = FUN_000132e0(param_1,DVar1), hMem != (LPLINEDEVCAPS)0x0)) {
    if ((hMem->dwStringFormat == 3) &&
       ((hMem->dwLineNameSize != 0 && (hMem->dwLineNameOffset != 0)))) {
      if (hMem->dwDevSpecificOffset != 0) {
        puVar3 = (undefined2 *)((int)&hMem->dwTotalSize + hMem->dwDevSpecificOffset);
        if (param_2 != (undefined2 *)0x0) {
          *param_2 = *puVar3;
        }
        if (param_3 != (uint *)0x0) {
          *param_3 = (uint)(ushort)puVar3[1];
        }
      }
      if (((hMem->dwLineNameSize < 0x80000000) &&
          (pszDest = LocalAlloc(0x40,hMem->dwLineNameSize << 1), pszDest != (STRSAFE_LPWSTR)0x0)) &&
         (HVar2 = StringCchCopyW(pszDest,hMem->dwLineNameSize,
                                 (STRSAFE_LPCWSTR)((int)&hMem->dwTotalSize + hMem->dwLineNameOffset)
                                ), HVar2 < 0)) {
        LocalFree(pszDest);
        pszDest = (STRSAFE_LPWSTR)0x0;
      }
    }
    LocalFree(hMem);
  }
  return pszDest;
}



/* 00013848 FUN_00013848 */

/* Boundary evidence: original MIPS .pdata 00013848..0001391b. Semantic name remains unreviewed. */

DWORD FUN_00013848(wchar_t *param_1,size_t param_2)

{
  STRSAFE_LPWSTR _Str1;
  int iVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  if (DAT_000156f0 != 0) {
    do {
      _Str1 = FUN_00013728(DVar2,(undefined2 *)0x0,(uint *)0x0);
      if (_Str1 != (STRSAFE_LPWSTR)0x0) {
        if (param_2 == 0) {
          iVar1 = wcscmp(_Str1,param_1);
        }
        else {
          iVar1 = wcsncmp(_Str1,param_1,param_2);
        }
        if (iVar1 == 0) {
          LocalFree(_Str1);
          return DVar2;
        }
        LocalFree(_Str1);
      }
      DVar2 = DVar2 + 1;
    } while (DVar2 < DAT_000156f0);
  }
  return 0xffffffff;
}



/* 0001391c FUN_0001391c */

/* Boundary evidence: original MIPS .pdata 0001391c..0001396f. Semantic name remains unreviewed. */

void FUN_0001391c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_0001399c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00013970 FUN_00013970 */

/* Boundary evidence: original MIPS .pdata 00013970..0001399b. Semantic name remains unreviewed. */

undefined4 FUN_00013970(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0001391c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 0001399c FUN_0001399c */

/* Boundary evidence: original MIPS .pdata 0001399c..000139e3. Semantic name remains unreviewed. */

void FUN_0001399c(uint param_1)

{
  if ((param_1 == DAT_00014128) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


