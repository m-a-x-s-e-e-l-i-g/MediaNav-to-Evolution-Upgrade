/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40201378 FUN_40201378 */

/* Boundary evidence: original MIPS .pdata 40201378..402013b3. Semantic name remains unreviewed. */

undefined4 FUN_40201378(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_40206174 = param_1;
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 402013b4 FUN_402013b4 */

/* Boundary evidence: original MIPS .pdata 402013b4..4020141b. Semantic name remains unreviewed. */

undefined4 FUN_402013b4(void)

{
  LONG LVar1;
  HMODULE pHVar2;
  
  LVar1 = InterlockedCompareExchange(&DAT_40206170,1,0);
  if (LVar1 == 0) {
    pHVar2 = GetModuleHandleW((LPCWSTR)0x0);
    DAT_40206170 = FUN_40204d18(pHVar2,&DAT_402061f8);
  }
  return DAT_40206170;
}



/* 4020141c SIP_Init */

/* Boundary evidence: original MIPS .pdata 4020141c..40201517. Semantic name remains unreviewed. */

HLOCAL SIP_Init(void)

{
  HMODULE pHVar1;
  HLOCAL pvVar2;
  
                    /* 0x141c  4  SIP_Init */
  pvVar2 = (HLOCAL)0x0;
  pHVar1 = LoadLibraryW(L"ole32.dll");
  if (pHVar1 != (HMODULE)0x0) {
    DAT_40206248 = GetProcAddressW(pHVar1,L"CoCreateInstance");
    DAT_40206210 = GetProcAddressW(pHVar1,L"CoFreeUnusedLibraries");
    DAT_402061c8 = GetProcAddressW(pHVar1,L"CoInitializeEx");
    DAT_40206208 = GetProcAddressW(pHVar1,L"CLSIDFromString");
    DAT_402061e0 = GetProcAddressW(pHVar1,L"StringFromGUID2");
    DAT_402061f8 = 0;
    DAT_402061fc = 0;
    DAT_40206200 = 0;
    DAT_40206204 = 0;
    pvVar2 = LocalAlloc(0x40,4);
  }
  return pvVar2;
}



/* 40201518 SIP_Deinit */

/* Boundary evidence: original MIPS .pdata 40201518..40201537. Semantic name remains unreviewed. */

undefined4 SIP_Deinit(HLOCAL param_1)

{
                    /* 0x1518  2  SIP_Deinit */
  LocalFree(param_1);
  return 1;
}



/* 40201538 SIP_Open */

undefined4 SIP_Open(undefined4 param_1)

{
                    /* 0x1538  5  SIP_Open */
  return param_1;
}



/* 40201540 SIP_Read */

undefined4 SIP_Read(void)

{
                    /* 0x1540  8  SIP_Read
                       0x1540  10  SIP_Write */
  return 0;
}



/* 40201548 SIP_Seek */

undefined4 SIP_Seek(void)

{
                    /* 0x1548  9  SIP_Seek */
  return 0xffffffff;
}



/* 40201550 SIP_Close */

undefined4 SIP_Close(void)

{
                    /* 0x1550  1  SIP_Close
                       0x1550  6  SIP_PowerDown
                       0x1550  7  SIP_PowerUp */
  return 1;
}



/* 40201558 SIP_IOControl */

/* Boundary evidence: original MIPS .pdata 40201558..402017e7. Semantic name remains unreviewed. */

LRESULT SIP_IOControl(undefined4 param_1,undefined4 param_2,int *param_3,uint param_4,int *param_5,
                     uint param_6)

{
  bool bVar1;
  int iVar2;
  LRESULT LVar3;
  undefined4 local_28;
  int *local_24;
  int *local_20;
  
                    /* 0x1558  3  SIP_IOControl */
  LVar3 = 0;
  local_20 = param_5;
  local_28 = param_2;
  local_24 = param_3;
  switch(param_2) {
  case 1:
    iVar2 = FUN_402013b4();
    if (iVar2 == 0) {
      return 0;
    }
    bVar1 = param_4 < 4;
    goto LAB_402015f0;
  case 2:
    iVar2 = FUN_402013b4();
    if (iVar2 == 0) {
      return 0;
    }
    if (param_4 != 4) {
      return 0;
    }
    if (param_6 < 0x30) {
      return 0;
    }
    iVar2 = *param_3;
    *local_20 = iVar2;
    if (iVar2 != 0x30) {
      return 0;
    }
    local_20[10] = param_6 - 0x30;
    if (param_6 - 0x30 == 0) {
      local_20[0xb] = 0;
    }
    else {
      local_20[0xb] = (int)(local_20 + 0xc);
    }
    goto LAB_40201600;
  case 3:
    iVar2 = FUN_402013b4();
    if (iVar2 == 0) {
      return 0;
    }
    if (param_4 < 0x30) {
      return 0;
    }
    if (local_24[10] != 0) {
      local_24[0xb] = (int)(local_24 + 0xc);
    }
    goto LAB_40201600;
  case 4:
    iVar2 = FUN_402013b4();
    if (iVar2 == 0) {
      return 0;
    }
    if (param_6 < 0x10) {
      return 0;
    }
    goto LAB_40201600;
  case 5:
    iVar2 = FUN_402013b4();
    if (iVar2 == 0) {
      return 0;
    }
    bVar1 = param_4 < 0x10;
    goto LAB_402015f0;
  case 6:
    if (3 < param_4) {
      LVar3 = FUN_40202ae4((HWND)*param_3);
    }
    break;
  case 7:
    if (0xf < param_4) {
      LVar3 = FUN_40202a44(param_3);
    }
    break;
  case 9:
    iVar2 = FUN_402013b4();
    if (iVar2 == 0) {
      return 0;
    }
    bVar1 = param_4 < 0x14;
LAB_402015f0:
    if (bVar1) {
      return 0;
    }
LAB_40201600:
    LVar3 = SendMessageW(DAT_40206178,0x8042,0,(LPARAM)&local_28);
    break;
  case 10:
    if (3 < param_6) {
      LVar3 = FUN_40201d30(param_5);
    }
    break;
  case 0xb:
    LVar3 = FUN_40202b5c((int)param_5,param_6);
  }
  return LVar3;
}



/* 402017e8 FUN_402017e8 */

/* Boundary evidence: original MIPS .pdata 402017e8..402017f3. Semantic name remains unreviewed. */

undefined4 FUN_402017e8(void)

{
  return 1;
}



/* 402017f4 FUN_402017f4 */

/* Boundary evidence: original MIPS .pdata 402017f4..40201847. Semantic name remains unreviewed. */

void FUN_402017f4(LPRECT param_1)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(1);
  if (iVar1 - DAT_402061c4 < param_1->bottom) {
    OffsetRect(param_1,0,(iVar1 - DAT_402061c4) - param_1->bottom);
  }
  return;
}



/* 40201848 FUN_40201848 */

/* Boundary evidence: original MIPS .pdata 40201848..40201983. Semantic name remains unreviewed. */

undefined4 FUN_40201848(undefined4 param_1,LPBYTE param_2,DWORD param_3)

{
  size_t sVar1;
  size_t sVar2;
  LSTATUS LVar3;
  undefined4 uVar4;
  HKEY local_228;
  DWORD local_224;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_40206168;
  local_224 = param_3;
  wcscpy(awStack_220,L"CLSID\\");
  sVar1 = wcslen(awStack_220);
  sVar2 = wcslen(awStack_220);
  (*DAT_402061e0)(param_1,awStack_220 + sVar2,0x104 - sVar1);
  wcscat(awStack_220,L"\\InprocServer32");
  LVar3 = RegOpenKeyExW((HKEY)0x80000000,awStack_220,0,0x20019,&local_228);
  if (LVar3 == 0) {
    LVar3 = RegQueryValueExW(local_228,(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,param_2,&local_224);
    if (LVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0x80040154;
    }
    RegCloseKey(local_228);
    FUN_402052c0(local_18);
  }
  else {
    FUN_402052c0(local_18);
    uVar4 = 0x80040154;
  }
  return uVar4;
}



/* 40201984 FUN_40201984 */

/* Boundary evidence: original MIPS .pdata 40201984..40201d2f. Semantic name remains unreviewed. */

undefined4 FUN_40201984(undefined4 *param_1)

{
  HANDLE pvVar1;
  int iVar2;
  LSTATUS LVar3;
  size_t sVar4;
  int *piVar5;
  int **ppiVar6;
  code *pcVar7;
  int **ppiVar8;
  undefined4 uVar9;
  DWORD DVar10;
  HKEY local_478;
  DWORD local_474;
  DWORD local_470 [2];
  _FILETIME _Stack_468;
  undefined1 auStack_460 [16];
  wchar_t *local_450;
  WCHAR aWStack_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40206168;
  local_470[0] = 0x104;
  local_474 = 0x104;
  uVar9 = 1;
  local_478 = (HKEY)0x0;
  *param_1 = 0;
  pvVar1 = (HANDLE)RegOpenKeyExW((HKEY)0x80000000,L"CLSID",0,8,&local_478);
  pcVar7 = SetLastError_exref;
  if (pvVar1 == (HANDLE)0x0) {
    if (DAT_40206264 == (HANDLE)0x0) {
      DAT_40206264 = (HANDLE)CeFindFirstRegChange(local_478,1,5);
LAB_40201a78:
      do {
        piVar5 = DAT_40206260;
        if ((DAT_40206260 == (int *)0x0) || (ppiVar8 = &DAT_40206260, DAT_40206260 == (int *)0x0))
        goto LAB_40201ad8;
        do {
          ppiVar6 = (int **)*ppiVar8;
          if (ppiVar6 == (int **)DAT_40206260) {
            *ppiVar8 = (int *)**ppiVar8;
            LocalFree((HLOCAL)piVar5[5]);
            LocalFree(piVar5);
            break;
          }
          ppiVar8 = ppiVar6;
        } while (*ppiVar6 != (int *)0x0);
      } while( true );
    }
    if ((DAT_40206264 == (HANDLE)0xffffffff) ||
       (DVar10 = WaitForSingleObject(DAT_40206264,0), DVar10 != 0x102)) goto LAB_40201a78;
    goto LAB_40201cd0;
  }
  goto LAB_40201cc8;
LAB_40201ad8:
  DVar10 = 0;
  iVar2 = RegEnumKeyExW(local_478,0,aWStack_238,local_470,(LPDWORD)0x0,aWStack_440,&local_474,
                        &_Stack_468);
  pcVar7 = CeFindNextRegChange_exref;
  pvVar1 = DAT_40206264;
  while (CeFindNextRegChange_exref = pcVar7, DAT_40206264 = pvVar1, iVar2 == 0) {
    if (local_470[0] + 0x12 < 0x105) {
      wcscpy(aWStack_238 + local_470[0],L"\\IsSIPInputMethod");
      local_474 = 0x104;
      LVar3 = RegQueryValueExW(local_478,(LPCWSTR)0x0,(LPDWORD)aWStack_238,(LPDWORD)0x0,
                               (LPBYTE)aWStack_440,&local_474);
      if ((LVar3 == 0) && (iVar2 = wcscmp(L"1",aWStack_440), iVar2 == 0)) {
        aWStack_238[local_470[0]] = L'\0';
        memset(auStack_460,0,0x1c);
        local_474 = 0x104;
        iVar2 = (*DAT_40206208)(aWStack_238,auStack_460);
        if ((-1 < iVar2) &&
           (LVar3 = RegQueryValueExW(local_478,(LPCWSTR)0x0,(LPDWORD)aWStack_238,(LPDWORD)0x0,
                                     (LPBYTE)aWStack_440,&local_474), LVar3 == 0)) {
          sVar4 = wcslen(aWStack_440);
          local_450 = LocalAlloc(0x40,(sVar4 + 1) * 2);
          if (local_450 == (wchar_t *)0x0) {
            uVar9 = 0;
            goto LAB_40201cd0;
          }
          wcscpy(local_450,aWStack_440);
          piVar5 = LocalAlloc(0x40,0x20);
          if (piVar5 != (int *)0x0) {
            *piVar5 = (int)DAT_40206260;
            memcpy(piVar5 + 1,auStack_460,0x1c);
            DAT_40206260 = piVar5;
          }
        }
      }
    }
    local_470[0] = 0x104;
    local_474 = 0x104;
    DVar10 = DVar10 + 1;
    iVar2 = RegEnumKeyExW(local_478,DVar10,aWStack_238,local_470,(LPDWORD)0x0,aWStack_440,&local_474
                          ,&_Stack_468);
    pcVar7 = CeFindNextRegChange_exref;
    pvVar1 = DAT_40206264;
  }
  *param_1 = 1;
LAB_40201cc8:
  (*pcVar7)(pvVar1);
LAB_40201cd0:
  if (local_478 != (HKEY)0x0) {
    RegCloseKey(local_478);
  }
  FUN_402052c0(local_30);
  return uVar9;
}



/* 40201d30 FUN_40201d30 */

/* Boundary evidence: original MIPS .pdata 40201d30..40201dcf. Semantic name remains unreviewed. */

undefined4 FUN_40201d30(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_18 [2];
  
  local_18[0] = 0;
  uVar3 = 0;
  if (param_1 == (int *)0x0) {
    SetLastError(0x57);
  }
  else {
    iVar1 = FUN_40201984(local_18);
    if (iVar1 != 0) {
      if (local_18[0] != 0) {
        DAT_40206268 = 0;
        for (piVar2 = (int *)DAT_40206260; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
          DAT_40206268 = DAT_40206268 + 1;
        }
      }
      *param_1 = DAT_40206268;
      uVar3 = 1;
    }
  }
  return uVar3;
}



/* 40201dd0 FUN_40201dd0 */

/* Boundary evidence: original MIPS .pdata 40201dd0..40201e53. Semantic name remains unreviewed. */

void FUN_40201dd0(void)

{
  GetWindowRect(DAT_40206178,(LPRECT)&DAT_4020622c);
  SystemParametersInfoW(0x30,0,&DAT_4020621c,0);
  if (((DAT_40206218 & 1) != 0) && ((DAT_40206218 & 2) != 0)) {
    if (DAT_40206220 == DAT_40206230) {
      DAT_40206220 = DAT_40206238;
    }
    else {
      DAT_40206228 = DAT_40206230;
    }
  }
  return;
}



/* 40201e54 FUN_40201e54 */

/* Boundary evidence: original MIPS .pdata 40201e54..40201eef. Semantic name remains unreviewed. */

void FUN_40201e54(void)

{
  LSTATUS LVar1;
  HKEY local_18;
  DWORD local_14;
  DWORD aDStack_10 [2];
  
  LVar1 = RegOpenKeyExW((HKEY)&DAT_80000001,L"ControlPanel\\Sip",0,9,&local_18);
  if (LVar1 == 0) {
    local_14 = 4;
    RegQueryValueExW(local_18,L"MenuBarHeight",(LPDWORD)0x0,aDStack_10,(LPBYTE)&DAT_402061c4,
                     &local_14);
    RegCloseKey(local_18);
  }
  return;
}



/* 40201ef0 FUN_40201ef0 */

/* Boundary evidence: original MIPS .pdata 40201ef0..4020200b. Semantic name remains unreviewed. */

void FUN_40201ef0(LPCWSTR param_1,undefined4 *param_2)

{
  HKEY pHVar1;
  LSTATUS LVar2;
  code *pcVar3;
  HKEY local_230;
  DWORD local_22c;
  DWORD aDStack_228 [2];
  BYTE aBStack_220 [520];
  uint local_18;
  
  local_18 = DAT_40206168;
  pHVar1 = (HKEY)RegOpenKeyExW((HKEY)&DAT_80000001,L"ControlPanel\\Sip",0,9,&local_230);
  pcVar3 = SetLastError_exref;
  if (pHVar1 == (HKEY)0x0) {
    local_22c = 0x104;
    LVar2 = RegQueryValueExW(local_230,param_1,(LPDWORD)0x0,aDStack_228,aBStack_220,&local_22c);
    if (LVar2 == 0) {
      (*DAT_40206208)(aBStack_220,param_2);
      pHVar1 = local_230;
      pcVar3 = RegCloseKey_exref;
    }
    else {
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      pHVar1 = local_230;
      pcVar3 = RegCloseKey_exref;
    }
  }
  (*pcVar3)(pHVar1);
  FUN_402052c0(local_18);
  return;
}



/* 4020200c FUN_4020200c */

/* Boundary evidence: original MIPS .pdata 4020200c..402021ab. Semantic name remains unreviewed. */

void FUN_4020200c(void)

{
  DWORD dwErrCode;
  int iVar1;
  DWORD local_28;
  HKEY local_24;
  DWORD aDStack_20 [2];
  
  DAT_402061bc = 0;
  dwErrCode = RegOpenKeyExW((HKEY)&DAT_80000001,L"ControlPanel\\Sip",0,9,&local_24);
  if (dwErrCode == 0) {
    local_28 = 4;
    RegQueryValueExW(local_24,L"DragStyle",(LPDWORD)0x0,aDStack_20,(LPBYTE)&DAT_402061bc,&local_28);
    RegCloseKey(local_24);
    if (DAT_402061bc < 3) {
      if (DAT_402061bc == 0) {
        DAT_402061ec = 0;
        DAT_402061f0 = 0;
      }
      else if (DAT_402061bc == 1) {
        DAT_402061ec = 2;
        iVar1 = GetSystemMetrics(4);
        DAT_402061f0 = iVar1 + 2;
      }
      else if (DAT_402061bc == 2) {
        DAT_402061ec = 10;
        local_28 = 4;
        DAT_402061f0 = 2;
        RegQueryValueExW(local_24,L"DragWidth",(LPDWORD)0x0,aDStack_20,(LPBYTE)&DAT_402061ec,
                         &local_28);
        DAT_402061ec = DAT_402061ec + 2;
      }
    }
    else {
      SetLastError(0x57);
    }
  }
  else {
    SetLastError(dwErrCode);
  }
  return;
}



/* 402021ac FUN_402021ac */

/* Boundary evidence: original MIPS .pdata 402021ac..402022a7. Semantic name remains unreviewed. */

void FUN_402021ac(void)

{
  int iVar1;
  undefined1 auStack_18 [8];
  int local_10;
  int local_c;
  
  if ((DAT_402061f8 == DAT_40206200) || (DAT_402061fc == DAT_40206204)) {
    SystemParametersInfoW(0x30,0,auStack_18,0);
    DAT_40206204 = local_c;
    DAT_40206200 = local_10;
    DAT_402061fc = (local_c - DAT_402061f0) + -0x50;
    DAT_402061f8 = (local_10 - DAT_402061ec) + -0xf0;
    return;
  }
  if (DAT_402061fc < DAT_402061f0) {
    DAT_40206204 = DAT_402061f0 + (DAT_40206204 - DAT_402061fc);
    DAT_402061fc = 0;
  }
  else {
    DAT_402061fc = DAT_402061fc - DAT_402061f0;
  }
  if (DAT_402061ec <= DAT_402061f8) {
    DAT_402061f8 = DAT_402061f8 - DAT_402061ec;
    return;
  }
  iVar1 = DAT_40206200 - DAT_402061f8;
  DAT_402061f8 = 0;
  DAT_40206200 = DAT_402061ec + iVar1;
  return;
}



/* 402022a8 FUN_402022a8 */

/* Boundary evidence: original MIPS .pdata 402022a8..402023a7. Semantic name remains unreviewed. */

undefined4 FUN_402022a8(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*param_1 == 0x30) {
    uVar2 = 1;
    if (((param_1[10] == 0) || (param_1[0xb] == 0)) ||
       ((DAT_402061a8 != (int *)0x0 && (iVar1 = (**(code **)(*DAT_402061a8 + 0x28))(), -1 < iVar1)))
       ) {
      FUN_40201dd0();
      param_1[1] = DAT_40206218 & 0xf00fffff;
      param_1[2] = DAT_4020621c;
      param_1[3] = DAT_40206220;
      param_1[4] = DAT_40206224;
      param_1[5] = DAT_40206228;
      param_1[6] = DAT_4020622c;
      param_1[7] = DAT_40206230;
      param_1[8] = DAT_40206234;
      param_1[9] = DAT_40206238;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
    SetLastError(0x57);
  }
  return uVar2;
}



/* 402023a8 FUN_402023a8 */

bool FUN_402023a8(undefined4 *param_1)

{
  bool bVar1;
  
  bVar1 = DAT_402061a8 != 0;
  if (bVar1) {
    *param_1 = DAT_402061ac;
    param_1[1] = DAT_402061b0;
    param_1[2] = DAT_402061b4;
    param_1[3] = DAT_402061b8;
  }
  return bVar1;
}



/* 402023f0 FUN_402023f0 */

/* Boundary evidence: original MIPS .pdata 402023f0..402025c3. Semantic name remains unreviewed. */

undefined4 FUN_402023f0(uint param_1)

{
  bool bVar1;
  bool bVar2;
  DWORD dwErrCode;
  undefined1 auStack_50 [48];
  
  bVar1 = (param_1 & 0xff00000) != 0x6d00000;
  bVar2 = false;
  if (((param_1 & 0xf00ffff0) == 0) && ((DAT_402061bc == 0 || ((param_1 & 2) == 0)))) {
    bVar2 = true;
  }
  if (bVar2) {
    if ((bVar1) && (DAT_40206154 == 0)) {
      return 1;
    }
    if ((param_1 & 1) == 0) {
      dwErrCode = (**(code **)(*DAT_402061a8 + 0x18))();
      if ((int)dwErrCode < 0) goto LAB_4020253c;
    }
    else {
      dwErrCode = (**(code **)(*DAT_402061a8 + 0x14))();
      if ((int)dwErrCode < 0) goto LAB_4020253c;
      ShowWindow(DAT_40206178,5);
    }
    if (bVar1) {
      param_1 = (DAT_40206218 ^ param_1) & 6 ^ param_1;
    }
    DAT_40206218 = param_1;
    FUN_40201dd0();
    memcpy(auStack_50,&DAT_40206214,0x30);
    dwErrCode = (**(code **)(*DAT_402061a8 + 0x20))(DAT_402061a8,auStack_50);
    if (-1 < (int)dwErrCode) {
      SendNotifyMessageW((HWND)0xfffd,0x1a,0xe0,0);
      Sleep(0);
      Sleep(0);
      if ((param_1 & 1) != 0) {
        return 1;
      }
      ShowWindow(DAT_40206178,0);
      return 1;
    }
  }
  else {
    dwErrCode = 0x57;
  }
LAB_4020253c:
  SetLastError(dwErrCode);
  return 0;
}



/* 402025c4 FUN_402025c4 */

/* Boundary evidence: original MIPS .pdata 402025c4..40202697. Semantic name remains unreviewed. */

void FUN_402025c4(void)

{
  if (DAT_4020620c != (HICON)0x0) {
    DestroyIcon(DAT_4020620c);
  }
  if (DAT_4020624c != (HICON)0x0) {
    DestroyIcon(DAT_4020624c);
  }
  if (DAT_40206184 == (HIMAGELIST)0x0) {
    DAT_4020620c = (HICON)0x0;
  }
  else {
    DAT_4020620c = ImageList_GetIcon(DAT_40206184,DAT_4020618c,0);
  }
  if (DAT_40206188 == (HIMAGELIST)0x0) {
    DAT_4020624c = (HICON)0x0;
  }
  else {
    DAT_4020624c = ImageList_GetIcon(DAT_40206188,DAT_40206190,0);
  }
  PostMessageW(DAT_402061f4,0x10c,1,(LPARAM)DAT_4020624c);
  PostMessageW(DAT_402061f4,0x10c,2,(LPARAM)DAT_4020620c);
  return;
}



/* 40202698 FUN_40202698 */

/* Boundary evidence: original MIPS .pdata 40202698..402027cf. Semantic name remains unreviewed. */

undefined4 FUN_40202698(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  uVar2 = 0;
  if (iVar1 == -1) {
    PostMessageW(DAT_402061f4,0x10c,6,0);
    return 1;
  }
  if (DAT_402061a8 != (int *)0x0) {
    if (DAT_4020617c == 2) {
      iVar1 = (**(code **)(*DAT_402061a8 + 0x34))
                        (DAT_402061a8,iVar1,param_1[1],param_1[2],param_1[3],param_1[4]);
    }
    else {
      if (DAT_4020617c != 3) goto LAB_40202770;
      iVar1 = (**(code **)(*DAT_402061a8 + 0x34))
                        (DAT_402061a8,iVar1,param_1[1],param_1[2],param_1[3],param_1[4]);
    }
    uVar2 = 1;
    if (iVar1 < 0) {
      uVar2 = 0;
    }
  }
LAB_40202770:
  if (DAT_402061f4 != (HWND)0x0) {
    PostMessageW(DAT_402061f4,0x10c,3,*param_1);
    PostMessageW(DAT_402061f4,0x10c,4,param_1[2]);
    PostMessageW(DAT_402061f4,0x10c,5,param_1[3]);
  }
  return uVar2;
}



/* 402027d0 FUN_402027d0 */

/* Boundary evidence: original MIPS .pdata 402027d0..4020285b. Semantic name remains unreviewed. */

void FUN_402027d0(void)

{
  uint uVar1;
  UINT uFlags;
  tagRECT local_18;
  
  GetWindowRect(DAT_40206178,&local_18);
  local_18.left = 0;
  local_18.right = GetSystemMetrics(0);
  uVar1 = GetWindowLongW(DAT_40206178,-0x10);
  uFlags = 0x50;
  if ((uVar1 & 0x10000000) == 0) {
    uFlags = 0x80;
  }
  SetWindowPos(DAT_40206244,DAT_40206178,local_18.left,local_18.top,local_18.right,
               local_18.bottom - local_18.top,uFlags);
  return;
}



/* 4020285c FUN_4020285c */

/* Boundary evidence: original MIPS .pdata 4020285c..402028bf. Semantic name remains unreviewed. */

void FUN_4020285c(HWND param_1,int param_2,int param_3)

{
  HWND hWnd;
  
  if ((param_2 == 0x3002) && (param_3 == 0)) {
    hWnd = GetWindow(param_1,5);
    if (hWnd != (HWND)0x0) {
      PostMessageW(hWnd,0x1a,0x3002,0);
    }
    if (DAT_40206244 != 0) {
      FUN_402027d0();
    }
  }
  return;
}



/* 402028c0 FUN_402028c0 */

/* Boundary evidence: original MIPS .pdata 402028c0..4020293b. Semantic name remains unreviewed. */

void FUN_402028c0(undefined4 param_1,int param_2)

{
  HWND hWnd;
  
  if (param_2 != 0) {
    if ((((*(uint *)(param_2 + 0x18) & 2) == 0) || ((*(uint *)(param_2 + 0x18) & 0x20) != 0)) &&
       (hWnd = GetForegroundWindow(), DAT_40206178 != hWnd)) {
      SendNotifyMessageW(hWnd,0x1a,0xfa,0);
    }
    if (DAT_40206244 != 0) {
      FUN_402027d0();
    }
  }
  return;
}



/* 4020293c FUN_4020293c */

/* Boundary evidence: original MIPS .pdata 4020293c..402029b7. Semantic name remains unreviewed. */

void FUN_4020293c(HWND param_1,int param_2)

{
  tagPAINTSTRUCT local_58;
  uint local_18;
  
  local_18 = DAT_40206168;
  BeginPaint(param_1,&local_58);
  MoveToEx(local_58.hdc,0,0,(LPPOINT)0x0);
  LineTo(local_58.hdc,param_2,0);
  EndPaint(param_1,&local_58);
  FUN_402052c0(local_18);
  return;
}



/* 402029b8 FUN_402029b8 */

/* Boundary evidence: original MIPS .pdata 402029b8..40202a43. Semantic name remains unreviewed. */

LRESULT FUN_402029b8(HWND param_1,UINT param_2,WPARAM param_3,int param_4)

{
  LRESULT LVar1;
  
  LVar1 = 0;
  if (param_2 == 2) {
    PostQuitMessage(0);
  }
  else if (param_2 == 0xf) {
    FUN_4020293c(param_1,DAT_4020626c);
  }
  else if (param_2 != 0x10) {
    if (param_2 == 0x47) {
      DAT_4020626c = *(int *)(param_4 + 0x10);
    }
    else {
      LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
    }
  }
  return LVar1;
}



/* 40202a44 FUN_40202a44 */

/* WARNING: Removing unreachable block (ram,0x40202ab0) */
/* Boundary evidence: original MIPS .pdata 40202a44..40202ad7. Semantic name remains unreviewed. */

undefined4 FUN_40202a44(undefined4 *param_1)

{
  DAT_402061f8 = *param_1;
  DAT_402061fc = param_1[1];
  DAT_40206200 = param_1[2];
  DAT_40206204 = param_1[3];
  return 1;
}



/* 40202ad8 FUN_40202ad8 */

/* Boundary evidence: original MIPS .pdata 40202ad8..40202ae3. Semantic name remains unreviewed. */

undefined4 FUN_40202ad8(void)

{
  return 1;
}



/* 40202ae4 FUN_40202ae4 */

/* Boundary evidence: original MIPS .pdata 40202ae4..40202b5b. Semantic name remains unreviewed. */

undefined4 FUN_40202ae4(HWND param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  BVar1 = IsWindow(DAT_402061f4);
  if ((BVar1 == 0) && (BVar1 = IsWindow(param_1), BVar1 != 0)) {
    DAT_402061f4 = param_1;
    FUN_402025c4();
    PostMessageW(DAT_402061f4,0x10c,0,0x402061f8);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40202b5c FUN_40202b5c */

/* Boundary evidence: original MIPS .pdata 40202b5c..40202d03. Semantic name remains unreviewed. */

undefined4 FUN_40202b5c(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  HRESULT HVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  STRSAFE_LPWSTR pszDest;
  uint local_38 [4];
  
  uVar4 = 0;
  local_38[1] = 0;
  local_38[0] = 0;
  iVar2 = FUN_40201d30((int *)local_38);
  uVar1 = local_38[0];
  if (iVar2 != 0) {
    if ((((int)((ulonglong)local_38[0] * 0x218 >> 0x20) == 0) && (param_1 != 0)) &&
       ((uint)((ulonglong)local_38[0] * 0x218) <= param_2)) {
      if (DAT_40206260 != 0) {
        piVar6 = (int *)DAT_40206260;
        for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
          pszDest = (STRSAFE_LPWSTR)(uVar5 * 0x218 + param_1);
          HVar3 = StringCchCopyW(pszDest,0x104,(STRSAFE_LPCWSTR)piVar6[5]);
          if (HVar3 < 0) {
            SetLastError(0x57);
            return 0;
          }
          *(int *)(pszDest + 0x104) = piVar6[1];
          *(int *)(pszDest + 0x106) = piVar6[2];
          *(int *)(pszDest + 0x108) = piVar6[3];
          *(int *)(pszDest + 0x10a) = piVar6[4];
          piVar6 = (int *)*piVar6;
          local_38[2] = (uint)piVar6;
        }
        uVar4 = 1;
      }
    }
    else {
      SetLastError(0x57);
    }
  }
  return uVar4;
}



/* 40202d04 FUN_40202d04 */

/* Boundary evidence: original MIPS .pdata 40202d04..40202d0f. Semantic name remains unreviewed. */

undefined4 FUN_40202d04(void)

{
  return 1;
}



/* 40202d10 FUN_40202d10 */

/* Boundary evidence: original MIPS .pdata 40202d10..40202e1f. Semantic name remains unreviewed. */

undefined4 FUN_40202d10(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  iVar1 = memcmp(&DAT_402011f0,param_2,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(&DAT_402012f4,param_2,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(&DAT_40201314,param_2,0x10), iVar1 == 0)) {
    *param_3 = (int)param_1;
  }
  else {
    iVar1 = memcmp(&DAT_40201304,param_2,0x10);
    if (iVar1 != 0) {
      uVar3 = 0x80004002;
      *param_3 = 0;
      goto LAB_40202df4;
    }
    piVar2 = param_1 + 1;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    *param_3 = (int)piVar2;
  }
  (**(code **)(*param_1 + 4))(param_1);
LAB_40202df4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  return uVar3;
}



/* 40202e20 FUN_40202e20 */

/* Boundary evidence: original MIPS .pdata 40202e20..40202e3b. Semantic name remains unreviewed. */

void FUN_40202e20(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



/* 40202e3c FUN_40202e3c */

/* Boundary evidence: original MIPS .pdata 40202e3c..4020308f. Semantic name remains unreviewed. */

undefined4 FUN_40202e3c(undefined4 param_1,void *param_2)

{
  int iVar1;
  BOOL BVar2;
  RECT *lprc1;
  tagRECT local_40;
  tagRECT tStack_30;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  memcpy(&DAT_40206180,param_2,0x28);
  GetWindowRect(DAT_40206178,&tStack_30);
  lprc1 = (RECT *)((int)param_2 + 0x18);
  if ((lprc1->left < *(int *)((int)param_2 + 0x20)) &&
     (*(int *)((int)param_2 + 0x1c) <= *(int *)((int)param_2 + 0x24))) {
    local_40.left = lprc1->left;
    local_40.top = *(int *)((int)param_2 + 0x1c);
    local_40.right = *(int *)((int)param_2 + 0x20);
    local_40.bottom = *(int *)((int)param_2 + 0x24);
    if (DAT_402061bc == 1) {
      iVar1 = GetSystemMetrics(4);
      iVar1 = iVar1 + 2;
      if (local_40.top < iVar1) {
        local_40.bottom = local_40.bottom + iVar1;
      }
      else {
        local_40.top = local_40.top - iVar1;
      }
    }
    if (DAT_402061c4 != 0) {
      FUN_402017f4(&local_40);
    }
    MoveWindow(DAT_40206178,local_40.left,local_40.top,local_40.right - local_40.left,
               local_40.bottom - local_40.top,0);
  }
  FUN_40201dd0();
  if ((*(int *)((int)param_2 + 0x14) != DAT_40206218) ||
     (BVar2 = EqualRect(lprc1,&tStack_30), BVar2 == 0)) {
    FUN_402023f0(*(uint *)((int)param_2 + 0x14) & 0xf6dfffff | 0x6d00000);
  }
  PostMessageW(DAT_402061f4,0x10c,0,0x402061f8);
  FUN_402025c4();
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  return 0;
}



/* 40203090 FUN_40203090 */

/* Boundary evidence: original MIPS .pdata 40203090..4020309b. Semantic name remains unreviewed. */

undefined4 FUN_40203090(void)

{
  return 1;
}



/* 4020309c FUN_4020309c */

/* Boundary evidence: original MIPS .pdata 4020309c..402030ff. Semantic name remains unreviewed. */

undefined4 FUN_4020309c(undefined4 param_1,BYTE param_2,DWORD param_3)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  keybd_event(param_2,'\0',param_3,0);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  return 0;
}



/* 40203100 FUN_40203100 */

/* Boundary evidence: original MIPS .pdata 40203100..402032c3. Semantic name remains unreviewed. */

undefined4
FUN_40203100(undefined4 param_1,int param_2,uint param_3,int param_4,uint *param_5,int *param_6)

{
  uint uVar1;
  uint local_res8;
  int local_resc;
  
  local_res8 = param_3;
  local_resc = param_4;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  if (param_4 == 1) {
    if ((param_2 == 0xe5) && (*param_6 == 0xe5)) {
      param_2 = 0xc;
    }
    uVar1 = *param_5;
    if (((uVar1 & 0x10040) == 0x10000) && (DAT_40206270 != 0)) {
      local_res8 = uVar1 | 0x40;
      PostKeybdMessage(0xffffffff,param_2,local_res8,1,&local_res8,param_6);
      DAT_40206270 = 0;
      goto LAB_4020327c;
    }
    if (uVar1 == 0x80) {
      DAT_40206270 = 1;
      local_res8 = 0x80;
    }
    else {
      DAT_40206270 = 0;
    }
  }
  PostKeybdMessage(0xffffffff,param_2,local_res8,param_4,param_5,param_6);
LAB_4020327c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  return 0;
}



/* 402032c4 FUN_402032c4 */

/* Boundary evidence: original MIPS .pdata 402032c4..402032cf. Semantic name remains unreviewed. */

undefined4 FUN_402032c4(void)

{
  return 1;
}



/* 402032d0 FUN_402032d0 */

/* Boundary evidence: original MIPS .pdata 402032d0..402034ef. Semantic name remains unreviewed. */

undefined4 FUN_402032d0(undefined4 param_1,ushort *param_2,uint param_3)

{
  uint *puVar1;
  HLOCAL pvVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  if ((DAT_40206278 == (HLOCAL)0x0) || (DAT_40206164 < param_3)) {
    for (; DAT_40206164 < param_3; DAT_40206164 = DAT_40206164 << 1) {
    }
    LocalFree(DAT_40206278);
    LocalFree(DAT_40206274);
    DAT_40206278 = LocalAlloc(0x40,DAT_40206164 << 2);
    if ((DAT_40206278 == (HLOCAL)0x0) ||
       (DAT_40206274 = LocalAlloc(0x40,DAT_40206164 << 2), DAT_40206274 == (uint *)0x0)) {
      uVar6 = 0x8007000e;
      goto LAB_402034a0;
    }
  }
  pvVar2 = DAT_40206278;
  puVar1 = DAT_40206274;
  if (param_3 != 0) {
    iVar5 = (int)DAT_40206278 - (int)DAT_40206274;
    puVar3 = DAT_40206274;
    uVar4 = param_3;
    do {
      *(undefined4 *)(iVar5 + (int)puVar3) = 0x80;
      *puVar3 = (uint)*param_2;
      param_2 = param_2 + 1;
      puVar3 = puVar3 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  PostKeybdMessage(0xffffffff,0xc,0,param_3,pvVar2,puVar1);
LAB_402034a0:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  return uVar6;
}



/* 402034f0 FUN_402034f0 */

/* Boundary evidence: original MIPS .pdata 402034f0..402034fb. Semantic name remains unreviewed. */

undefined4 FUN_402034f0(void)

{
  return 1;
}



/* 402034fc FUN_402034fc */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 402034fc..402036cf. Semantic name remains unreviewed. */

undefined4 FUN_402034fc(undefined4 param_1,int *param_2)

{
  HWND hWnd;
  LRESULT LVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_34 [3];
  undefined4 local_28;
  int local_24;
  int *local_20;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  if (((param_2 != (int *)0x0) && (*param_2 == 0x10000)) && (uVar2 = param_2[2], uVar2 < 0x15555554)
     ) {
    uVar2 = ((uVar2 + 1 & 0xfffffffe) + uVar2 * 2) * 2;
    local_28 = 0;
    local_24 = uVar2 + 0x1c;
    local_20 = param_2;
    if ((((uint)param_2[3] < uVar2) && ((uint)param_2[5] < uVar2)) && ((uint)param_2[4] < uVar2)) {
      hWnd = (HWND)GetForegroundKeyboardTarget();
      LVar1 = SendMessageW(hWnd,0x62,1,(LPARAM)&local_28);
      if (LVar1 != 0) {
        local_34[0] = (uint)*(ushort *)((int)param_2 + param_2[3] + 0x18);
        local_34[1] = 0x80;
        PostKeybdMessage(0xffffffff,0xc,0,1,local_34 + 1,local_34,0);
      }
      goto LAB_4020368c;
    }
  }
  uVar3 = 0x800700a0;
LAB_4020368c:
  LocalFree(param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  return uVar3;
}



/* 402036d0 FUN_402036d0 */

/* Boundary evidence: original MIPS .pdata 402036d0..402036f7. Semantic name remains unreviewed. */

bool FUN_402036d0(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* 402036f8 FUN_402036f8 */

/* Boundary evidence: original MIPS .pdata 402036f8..40203887. Semantic name remains unreviewed. */

undefined4 FUN_402036f8(undefined4 param_1,void *param_2)

{
  HWND hWnd;
  LRESULT LVar1;
  void *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  void *local_40;
  undefined1 auStack_38 [8];
  int local_30;
  uint local_1c;
  
  local_1c = DAT_40206168;
  local_50 = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  memcpy(auStack_38,param_2,0x1c);
  local_30 = local_30 + 1;
  local_48 = 0;
  local_44 = ((*(int *)((int)param_2 + 8) + 7) * 2 + (*(int *)((int)param_2 + 8) + 1U & 0xfffffffe))
             * 2;
  local_40 = param_2;
  hWnd = (HWND)GetForegroundKeyboardTarget();
  LVar1 = SendMessageW(hWnd,0x62,1,(LPARAM)&local_48);
  if (LVar1 != 0) {
    local_50 = (void *)(uint)*(ushort *)((int)param_2 + *(int *)((int)param_2 + 0xc) + 0x18);
    local_4c = 0x80;
    PostKeybdMessage(0xffffffff,0xc,0,1,&local_4c,&local_50);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  FUN_402052c0(local_1c);
  return 0;
}



/* 40203888 FUN_40203888 */

/* Boundary evidence: original MIPS .pdata 40203888..40203893. Semantic name remains unreviewed. */

undefined4 FUN_40203888(void)

{
  return 1;
}



/* 4020390c FUN_4020390c */

/* Boundary evidence: original MIPS .pdata 4020390c..40203e33. Semantic name remains unreviewed. */

undefined4 FUN_4020390c(undefined4 *param_1)

{
  ushort uVar1;
  DWORD DVar2;
  int iVar3;
  HMODULE ProcessId;
  undefined *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int *local_250;
  int *local_24c;
  int *local_248;
  int *local_244;
  int *local_240;
  int *local_23c;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40206168;
  uVar5 = 1;
  if (DAT_402061a8 != (int *)0x0) {
    (**(code **)(*DAT_402061a8 + 0x10))();
    (**(code **)(*DAT_402061a8 + 8))();
    DAT_402061a8 = (int *)0x0;
    (*DAT_40206210)();
    uVar6 = 0;
    do {
      uVar1 = GetAsyncKeyState((uint)(byte)(&DAT_40206158)[uVar6]);
      if ((uVar1 & 0x8000) != 0) {
        keybd_event((&DAT_40206158)[uVar6],'\0',6,0);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0xb);
    uVar6 = GetAsyncShiftFlags(0x14);
    if ((uVar6 & 0x8000000) != 0) {
      keybd_event('\x14','\0',4,0);
      keybd_event('\x14','\0',6,0);
    }
  }
  uVar6 = DAT_40206218 & 1;
  DAT_40206214 = 0x30;
  DAT_40206218 = uVar6 | 2;
  if (DAT_402061bc != 0) {
    DAT_40206218 = uVar6;
  }
  MoveWindow(DAT_40206178,DAT_402061f8,DAT_402061fc,DAT_40206200 - DAT_402061f8,
             DAT_40206204 - DAT_402061fc,0);
  FUN_40201dd0();
  DVar2 = (*DAT_40206248)(param_1,0,1,&DAT_402011f0,&local_250);
  if ((int)DVar2 < 0) {
LAB_40203de8:
    SetLastError(DVar2);
    FUN_402052c0(local_30);
    return 0;
  }
  DVar2 = (**(code **)*local_250)(local_250,&DAT_40201324,&local_248);
  if ((int)DVar2 < 0) {
    (*(code *)((undefined4 *)*local_250)[2])();
    goto LAB_40203de8;
  }
  DVar2 = (**(code **)*local_250)(local_250,&UNK_40201344,&local_23c);
  if ((int)DVar2 < 0) {
    DVar2 = (**(code **)*local_250)(local_250,&UNK_40201334,&local_240);
    if ((int)DVar2 < 0) {
      DAT_4020617c = 1;
      (**(code **)(*local_250 + 8))();
      local_23c = local_248;
    }
    else {
      DAT_4020617c = 2;
      (**(code **)(*local_250 + 8))();
      (**(code **)(*local_248 + 8))();
      local_23c = local_240;
    }
  }
  else {
    DAT_4020617c = 3;
    (**(code **)(*local_250 + 8))();
    (**(code **)(*local_248 + 8))();
  }
  DAT_402061ac = *param_1;
  DAT_402061b0 = param_1[1];
  DAT_402061b4 = param_1[2];
  DAT_402061b8 = param_1[3];
  DAT_402061a8 = local_23c;
  iVar3 = (**(code **)(*local_23c + 0xc))(local_23c,DAT_40206178);
  if (iVar3 < 0) goto LAB_40203de8;
  if (DAT_4020617c == 2) {
    puVar4 = &DAT_40201314;
LAB_40203c40:
    (**(code **)*DAT_402061e8)(DAT_402061e8,puVar4,&local_24c);
    DVar2 = (**(code **)(*DAT_402061a8 + 0x38))(DAT_402061a8,local_24c);
    if (-1 < (int)DVar2) goto LAB_40203cb8;
LAB_40203c78:
    (**(code **)(*local_24c + 8))();
LAB_40203c8c:
    SetLastError(DVar2);
  }
  else {
    if (DAT_4020617c == 3) {
      puVar4 = &DAT_40201304;
      goto LAB_40203c40;
    }
LAB_40203cb8:
    (**(code **)*DAT_402061e8)(DAT_402061e8,&DAT_402012f4,&local_244);
    DVar2 = (**(code **)(*DAT_402061a8 + 0x24))(DAT_402061a8,local_244);
    local_24c = local_244;
    if ((int)DVar2 < 0) goto LAB_40203c78;
    memset(&DAT_40206180,0,0x28);
    DAT_40206180 = 0x28;
    DVar2 = (**(code **)(*DAT_402061a8 + 0x1c))(DAT_402061a8,&DAT_40206180);
    if ((int)DVar2 < 0) goto LAB_40203c8c;
    FUN_40201848(param_1,(LPBYTE)aWStack_238,0x104);
    ProcessId = GetModuleHandleW(aWStack_238);
    DVar2 = GetProcessVersion((DWORD)ProcessId);
    DAT_402061e4 = DVar2 >> 0x10 < 3;
    FUN_402025c4();
    SendNotifyMessageW((HWND)0xffff,0x1a,0xe2,0);
    iVar3 = FUN_402023f0(DAT_40206218 & 0xf6dfffff | 0x6d00000);
    if (iVar3 != 0) goto LAB_40203dc0;
  }
  uVar5 = 0;
LAB_40203dc0:
  FUN_402052c0(local_30);
  return uVar5;
}



/* 40203e34 FUN_40203e34 */

/* Boundary evidence: original MIPS .pdata 40203e34..402040c3. Semantic name remains unreviewed. */

int FUN_40203e34(int *param_1)

{
  bool bVar1;
  bool bVar2;
  BOOL BVar3;
  DWORD dwErrCode;
  int iVar4;
  RECT *lprc1;
  tagRECT local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  bVar2 = false;
  if ((param_1 != (int *)0x0) && (*param_1 == 0x30)) {
    bVar1 = false;
    if (((param_1[1] & 0xf00ffff0U) == 0) && ((DAT_402061bc == 0 || ((param_1[1] & 2U) == 0)))) {
      bVar1 = true;
    }
    if (bVar1) {
      GetWindowRect(DAT_40206178,&local_40);
      SystemParametersInfoW(0x30,0,&local_30,0);
      if (((DAT_40206218 & 1) != 0) && ((DAT_40206218 & 2) != 0)) {
        local_24 = local_40.top;
      }
      lprc1 = (RECT *)(param_1 + 6);
      if (DAT_402061e4 == '\0') {
        if ((lprc1->left != local_40.left) || (param_1[7] != local_40.top)) {
          param_1[8] = (lprc1->left - local_40.left) + local_40.right;
          param_1[9] = (param_1[7] - local_40.top) + local_40.bottom;
          goto LAB_40203f74;
        }
      }
      else {
        BVar3 = EqualRect(lprc1,&local_40);
        if (BVar3 == 0) {
LAB_40203f74:
          bVar2 = true;
        }
      }
      if (!bVar2) {
LAB_40203fec:
        DAT_4020622c = local_40.left;
        DAT_40206234 = local_40.right;
        DAT_40206238 = local_40.bottom;
        DAT_4020621c = local_30;
        DAT_40206220 = local_2c;
        DAT_40206224 = local_28;
        DAT_40206228 = local_24;
        DAT_40206230 = local_40.top;
        iVar4 = FUN_402023f0(param_1[1]);
        if (param_1[10] == 0) {
          return iVar4;
        }
        if (param_1[0xb] == 0) {
          return iVar4;
        }
        if (((iVar4 != 0) && (DAT_402061a8 != (int *)0x0)) &&
           (iVar4 = (**(code **)(*DAT_402061a8 + 0x2c))(), -1 < iVar4)) {
          return 1;
        }
        return 0;
      }
      if (DAT_402061c4 != 0) {
        FUN_402017f4(lprc1);
      }
      if ((DAT_402061a8 == (int *)0x0) ||
         (dwErrCode = (**(code **)(*DAT_402061a8 + 0x20))(DAT_402061a8,param_1), -1 < (int)dwErrCode
         )) {
        MoveWindow(DAT_40206178,lprc1->left,param_1[7],param_1[8] - lprc1->left,
                   param_1[9] - param_1[7],0);
        goto LAB_40203fec;
      }
      goto LAB_40204088;
    }
  }
  dwErrCode = 0x57;
LAB_40204088:
  SetLastError(dwErrCode);
  return 0;
}



/* 402040c4 FUN_402040c4 */

/* Boundary evidence: original MIPS .pdata 402040c4..40204103. Semantic name remains unreviewed. */

int FUN_402040c4(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_4020390c(param_1);
  if (iVar1 == 0) {
    FUN_4020390c((undefined4 *)&DAT_40206250);
  }
  return iVar1;
}



/* 40204104 FUN_40204104 */

/* Boundary evidence: original MIPS .pdata 40204104..4020438f. Semantic name remains unreviewed. */

uint FUN_40204104(HWND param_1,UINT param_2,WPARAM param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  int local_30;
  uint *local_2c;
  int *local_28;
  
  uVar3 = 0;
  iVar2 = __GetUserKData(0);
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 2;
  if (param_2 == 2) {
    PostQuitMessage(0);
  }
  else if (param_2 != 0x10) {
    if (param_2 == 0x1a) {
      FUN_4020285c(param_1,param_3,(int)param_4);
    }
    else if (param_2 == 0x47) {
      FUN_402028c0(param_1,(int)param_4);
    }
    else if (param_2 == 0x8042) {
      if (param_4 != (int *)0x0) {
        if ((int)param_4 < 0) {
          trap(0x400);
        }
        else {
          local_30 = *param_4;
          local_2c = (uint *)param_4[1];
          local_28 = (int *)param_4[2];
        }
        if (local_30 == 1) {
          uVar3 = FUN_402023f0(*local_2c);
        }
        else if (local_30 == 2) {
          uVar3 = FUN_402022a8(local_28);
        }
        else if (local_30 == 3) {
          uVar3 = FUN_40203e34((int *)local_2c);
        }
        else if (local_30 == 4) {
          bVar1 = FUN_402023a8(local_28);
          uVar3 = CONCAT31(extraout_var,bVar1);
        }
        else if (local_30 == 5) {
          uVar3 = FUN_402040c4(local_2c);
        }
        else if (local_30 == 9) {
          uVar3 = FUN_40202698((int *)local_2c);
        }
      }
    }
    else {
      iVar2 = __GetUserKData(0);
      *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) & 0xfffffffd;
      uVar3 = DefWindowProcW(param_1,param_2,param_3,(LPARAM)param_4);
    }
  }
  return uVar3;
}



/* 40204390 FUN_40204390 */

/* Boundary evidence: original MIPS .pdata 40204390..4020439b. Semantic name remains unreviewed. */

undefined4 FUN_40204390(void)

{
  return 1;
}



/* 4020439c FUN_4020439c */

/* Boundary evidence: original MIPS .pdata 4020439c..4020440b. Semantic name remains unreviewed. */

LONG FUN_4020439c(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if (LVar1 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = &PTR_FUN_40201260;
      param_1[1] = &PTR_LAB_40201240;
      operator_delete(param_1);
    }
    LVar1 = 0;
  }
  else {
    LVar1 = param_1[2];
  }
  return LVar1;
}



/* 40204420 FUN_40204420 */

/* WARNING: Removing unreachable block (ram,0x402046f4) */
/* WARNING: Removing unreachable block (ram,0x40204708) */
/* WARNING: Removing unreachable block (ram,0x4020473c) */
/* WARNING: Removing unreachable block (ram,0x40204b18) */
/* WARNING: Removing unreachable block (ram,0x40204b3c) */
/* WARNING: Removing unreachable block (ram,0x4020474c) */
/* WARNING: Removing unreachable block (ram,0x402047a4) */
/* WARNING: Removing unreachable block (ram,0x4020477c) */
/* Boundary evidence: original MIPS .pdata 40204420..40204d0b. Semantic name remains unreviewed. */

undefined4 FUN_40204420(void)

{
  undefined4 *puVar1;
  ATOM AVar2;
  undefined2 extraout_var;
  HWND pHVar3;
  int iVar4;
  BOOL BVar5;
  DWORD dwStyle;
  code **ppcVar6;
  HWND pHVar7;
  undefined4 uVar8;
  ATOM local_3a4;
  int local_36c;
  undefined4 *local_368;
  code **local_364;
  wchar_t *local_360;
  code **local_35c;
  undefined **local_358;
  undefined4 *local_354;
  code **local_350;
  undefined **local_34c;
  code **local_348;
  undefined4 local_344;
  undefined1 auStack_340 [8];
  WNDCLASSW local_338;
  tagMSG tStack_310;
  undefined2 local_2f0;
  undefined1 auStack_2ee [62];
  undefined1 auStack_2b0 [4];
  undefined2 local_2ac;
  undefined4 local_2a8;
  int local_234;
  WCHAR local_230 [256];
  uint local_30;
  
  local_30 = DAT_40206168;
  local_338.style = 0;
  memset(&local_338.lpfnWndProc,0,0x24);
  uVar8 = 1;
  local_3a4 = 0;
  (*DAT_402061c8)(0,0);
  local_338.hInstance = GetModuleHandleW((LPCWSTR)0x0);
  local_338.hbrBackground = (HBRUSH)0x0;
  local_338.lpfnWndProc = FUN_40204104;
  local_360 = L"SipWndClass";
  local_338.lpszClassName = L"SipWndClass";
  AVar2 = RegisterClassW(&local_338);
  if (CONCAT22(extraout_var,AVar2) == 0) {
    EventModify(DAT_402061c0,3);
    uVar8 = 0;
  }
  else {
    FUN_40201e54();
    FUN_4020200c();
    FUN_402021ac();
    if (DAT_402061bc == 0) {
      local_2f0 = 0;
      memset(auStack_2ee,0,0x3e);
      memset(auStack_2b0,0,0x80);
      local_2ac = 0xc0;
      local_2a8 = 0x1000000;
      ChangeDisplaySettingsEx(0,&local_2f0,0,2,0);
      if (local_234 != 0) {
        local_338.hbrBackground = GetStockObject(0);
        local_338.lpfnWndProc = FUN_402029b8;
        local_338.lpszClassName = L"SipBackDropWndClass";
        local_3a4 = RegisterClassW(&local_338);
      }
    }
    local_354 = &DAT_40206154;
    local_34c = &PTR_LAB_40201280;
    local_358 = &PTR_LAB_40201240;
    local_364 = &RegCloseKey_exref;
    local_350 = &RegQueryValueExW_exref;
    local_35c = &SetLastError_exref;
    local_348 = &RegOpenKeyExW_exref;
    local_368 = &DAT_40206214;
    while( true ) {
      pHVar7 = DAT_40206244;
      iVar4 = DAT_402061bc;
      pHVar3 = DAT_40206178;
      memset(local_368,0,0x30);
      if (pHVar3 == (HWND)0x0) {
        if (iVar4 == 1) {
          LoadStringW(DAT_40206174,100,local_230,0x100);
          iVar4 = DAT_402061bc;
        }
        else {
          local_230[0] = L'\0';
        }
        if (iVar4 == 1) {
          dwStyle = 0xc00000;
        }
        else {
          dwStyle = 0x10000;
        }
        pHVar3 = CreateWindowExW(0x8000080,local_360,local_230,dwStyle,DAT_402061f8,DAT_402061fc,
                                 DAT_40206200 - DAT_402061f8,DAT_40206204 - DAT_402061fc,(HWND)0x0,
                                 (HMENU)0x0,local_338.hInstance,(LPVOID)0x0);
        pHVar7 = DAT_40206244;
        DAT_40206178 = pHVar3;
      }
      if ((local_3a4 != 0) && (pHVar7 == (HWND)0x0)) {
        DAT_40206244 = CreateWindowExW(0x8000080,L"SipBackDropWndClass",(LPCWSTR)0x0,0x10000,0,0,0,0
                                       ,(HWND)0x0,(HMENU)0x0,DAT_40206174,(LPVOID)0x0);
        pHVar3 = DAT_40206178;
      }
      puVar1 = local_354;
      if (pHVar3 == (HWND)0x0) {
        EventModify(DAT_402061c0,3);
        uVar8 = 0;
        goto LAB_4020452c;
      }
      *local_354 = 1;
      iVar4 = (**local_348)(0x80000001,L"ControlPanel\\Sip",0,9,&local_36c);
      ppcVar6 = local_35c;
      if (iVar4 == 0) {
        local_344 = 4;
        (**local_350)(local_36c,L"AllowChange",0,auStack_340,puVar1,&local_344);
        iVar4 = local_36c;
        ppcVar6 = local_364;
      }
      (**ppcVar6)(iVar4);
      FUN_40201ef0(L"DefaultIm",(undefined4 *)&DAT_40206250);
      RegisterSIPanel(DAT_40206178);
      if (DAT_402061e8 == (int *)0x0) {
        DAT_402061e8 = operator_new(0xc);
        if (DAT_402061e8 == (int *)0x0) {
          DAT_402061e8 = (int *)0x0;
        }
        else {
          *DAT_402061e8 = (int)local_34c;
          *DAT_402061e8 = (int)&PTR_LAB_4020129c;
          DAT_402061e8[1] = (int)local_34c;
          DAT_402061e8[1] = (int)&PTR_LAB_402012bc;
          *DAT_402061e8 = (int)&PTR_FUN_40201260;
          DAT_402061e8[1] = (int)local_358;
          DAT_402061e8[2] = 1;
        }
        if (DAT_402061e8 == (int *)0x0) goto LAB_4020452c;
        (**(code **)(*DAT_402061e8 + 4))(DAT_402061e8);
      }
      DAT_402061a8 = 0;
      iVar4 = memcmp(&DAT_40206250,&DAT_40201200,0x10);
      if ((iVar4 == 0) || (iVar4 = FUN_4020390c((undefined4 *)&DAT_40206250), iVar4 == 0)) break;
      EventModify(DAT_402061c0,3);
      while (BVar5 = GetMessageW(&tStack_310,(HWND)0x0,0,0), BVar5 != 0) {
        TranslateMessage(&tStack_310);
        DispatchMessageW(&tStack_310);
      }
    }
    EventModify(DAT_402061c0,3);
    DestroyWindow(DAT_40206178);
    uVar8 = 0;
    if (DAT_40206244 != (HWND)0x0) {
      DestroyWindow(DAT_40206244);
      DAT_40206244 = (HWND)0x0;
    }
  }
LAB_4020452c:
  FUN_402052c0(local_30);
  return uVar8;
}



/* 40204d0c FUN_40204d0c */

/* Boundary evidence: original MIPS .pdata 40204d0c..40204d17. Semantic name remains unreviewed. */

undefined4 FUN_40204d0c(void)

{
  return 1;
}



/* 40204d18 FUN_40204d18 */

/* Boundary evidence: original MIPS .pdata 40204d18..40204e27. Semantic name remains unreviewed. */

undefined4 FUN_40204d18(undefined4 param_1,undefined4 *param_2)

{
  HANDLE hObject;
  DWORD DVar1;
  undefined4 uVar2;
  DWORD aDStack_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar2 = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_402061cc);
  (*DAT_402061c8)(0,0);
  local_2c = *param_2;
  local_28 = param_2[1];
  local_24 = param_2[2];
  local_20 = param_2[3];
  local_30 = param_1;
  DAT_402061c0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  if (DAT_402061c0 != (HANDLE)0x0) {
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40204420,&local_30,0,aDStack_38);
    if ((hObject != (HANDLE)0x0) &&
       (DVar1 = WaitForSingleObject(DAT_402061c0,0xffffffff), DVar1 == 0)) {
      CloseHandle(hObject);
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 40205158 entry */

/* Boundary evidence: original MIPS .pdata 40205158..402051cb. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_402051cc();
    FUN_4020551c();
  }
  uVar1 = FUN_40201378(param_1,param_2);
  if (param_2 == 0) {
    FUN_402054a4();
  }
  return uVar1;
}



/* 402051cc FUN_402051cc */

/* Boundary evidence: original MIPS .pdata 402051cc..4020523f. Semantic name remains unreviewed. */

void FUN_402051cc(void)

{
  uint uVar1;
  
  if ((DAT_40206168 == 0) || (DAT_40206168 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40206168 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40206168 == 0) {
      DAT_40206168 = 0xb064;
    }
  }
  DAT_4020616c = ~DAT_40206168;
  return;
}



/* 40205240 FUN_40205240 */

/* Boundary evidence: original MIPS .pdata 40205240..40205293. Semantic name remains unreviewed. */

void FUN_40205240(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_402052c0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40205294 FUN_40205294 */

/* Boundary evidence: original MIPS .pdata 40205294..402052bf. Semantic name remains unreviewed. */

undefined4 FUN_40205294(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40205240(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 402052c0 FUN_402052c0 */

/* Boundary evidence: original MIPS .pdata 402052c0..40205307. Semantic name remains unreviewed. */

void FUN_402052c0(uint param_1)

{
  if ((param_1 == DAT_40206168) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40205308 FUN_40205308 */

/* Boundary evidence: original MIPS .pdata 40205308..40205383. Semantic name remains unreviewed. */

void FUN_40205308(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_40205240(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 40205384 FUN_40205384 */

/* Boundary evidence: original MIPS .pdata 40205384..402054a3. Semantic name remains unreviewed. */

void FUN_40205384(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_4020627c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40206284;
    if (DAT_40206284 != (undefined4 *)0x0) {
      while (DAT_40206280 = DAT_40206280 + -1, _Memory <= DAT_40206280) {
        if ((code *)*DAT_40206280 != (code *)0x0) {
          (*(code *)*DAT_40206280)();
          _Memory = DAT_40206284;
        }
      }
      free(_Memory);
      DAT_40206280 = (undefined4 *)0x0;
      DAT_40206284 = (undefined4 *)0x0;
    }
    FUN_402054c8((undefined4 *)&DAT_40201010,(undefined4 *)&DAT_40201014);
  }
  FUN_402054c8((undefined4 *)&DAT_40201018,(undefined4 *)&DAT_4020101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_40206288,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 402054a4 FUN_402054a4 */

/* Boundary evidence: original MIPS .pdata 402054a4..402054c7. Semantic name remains unreviewed. */

void FUN_402054a4(void)

{
  FUN_40205384(0,0,1);
  return;
}



/* 402054c8 FUN_402054c8 */

/* Boundary evidence: original MIPS .pdata 402054c8..4020551b. Semantic name remains unreviewed. */

void FUN_402054c8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4020551c FUN_4020551c */

/* Boundary evidence: original MIPS .pdata 4020551c..40205557. Semantic name remains unreviewed. */

void FUN_4020551c(void)

{
  FUN_402054c8((undefined4 *)&DAT_40201008,(undefined4 *)&DAT_4020100c);
  FUN_402054c8((undefined4 *)&DAT_40201000,(undefined4 *)&DAT_40201004);
  return;
}


