/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40561290 FUN_40561290 */

/* Boundary evidence: original MIPS .pdata 40561290..40561323. Semantic name remains unreviewed. */

undefined4 FUN_40561290(HMODULE param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_2 == 0) {
    FUN_40561ba8();
    NTP_PowerDown();
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    iVar1 = FUN_40562738();
    if (iVar1 == 0) {
      iVar1 = FUN_40561b50(param_1);
      if (iVar1 == 0) {
        return 1;
      }
      NTP_PowerDown();
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 40561324 NTP_Init */

/* Boundary evidence: original MIPS .pdata 40561324..4056137f. Semantic name remains unreviewed. */

undefined4 NTP_Init(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  DWORD DVar3;
  
                    /* 0x1324  4  NTP_Init */
  if ((param_1 & 1) == 0) {
    iVar1 = FUN_40562738();
    if (iVar1 == 0) {
      DVar3 = FUN_40562664();
      if (DVar3 == 0) goto LAB_40561370;
      FUN_40562738();
    }
    uVar2 = 0;
  }
  else {
LAB_40561370:
    uVar2 = 1;
  }
  return uVar2;
}



/* 40561380 NTP_Deinit */

/* Boundary evidence: original MIPS .pdata 40561380..405613a7. Semantic name remains unreviewed. */

undefined4 NTP_Deinit(void)

{
                    /* 0x1380  2  NTP_Deinit */
  FUN_40561bec();
  FUN_40562738();
  return 1;
}



/* 405613a8 NTP_Close */

undefined4 NTP_Close(void)

{
                    /* 0x13a8  1  NTP_Close
                       0x13a8  5  NTP_Open */
  return 1;
}



/* 405613b0 NTP_Read */

undefined4 NTP_Read(void)

{
                    /* 0x13b0  8  NTP_Read
                       0x13b0  9  NTP_Seek
                       0x13b0  10  NTP_Write */
  return 0xffffffff;
}



/* 405613b8 NTP_IOControl */

/* WARNING: Removing unreachable block (ram,0x40561554) */
/* WARNING: Removing unreachable block (ram,0x40561594) */
/* Boundary evidence: original MIPS .pdata 405613b8..40561697. Semantic name remains unreviewed. */

bool NTP_IOControl(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                  uint *param_5,int param_6,undefined4 *param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  DWORD dwErrCode;
  
                    /* 0x13b8  3  NTP_IOControl */
  dwErrCode = 0x57;
  if (param_2 == 0x1040004) {
    dwErrCode = FUN_40562738();
    if ((dwErrCode == 0) && (dwErrCode = FUN_40562664(), dwErrCode != 0)) {
      FUN_40562738();
    }
  }
  else if (param_2 == 0x1040008) {
    dwErrCode = FUN_40561bec();
    if (dwErrCode == 0) {
      dwErrCode = FUN_40562738();
    }
  }
  else if (param_2 == 0x104000c) {
    dwErrCode = FUN_40562738();
    if (dwErrCode == 0) {
      dwErrCode = FUN_40562738();
    }
  }
  else if (param_2 == 0x104001c) {
    FUN_40562740();
    FUN_40561ce0();
    dwErrCode = 0x57;
  }
  else if (param_2 == 0x1040020) {
    if ((param_5 == (uint *)0x0) || (param_6 != 4)) {
      dwErrCode = 0x57;
    }
    else {
      uVar1 = NTP_Read();
      uVar2 = FUN_40561c88();
      uVar3 = uVar2;
      if ((((uVar1 != 0xffffffff) && (uVar3 = uVar1, uVar2 != 0xffffffff)) &&
          (uVar3 = 0xffffffff, uVar1 < 6)) && (uVar2 < 6)) {
        uVar3 = *(uint *)(&DAT_40563090 + (uVar1 * 6 + uVar2) * 4);
      }
      *param_5 = uVar3;
      if (param_7 != (undefined4 *)0x0) {
        *param_7 = 4;
      }
      dwErrCode = 0;
    }
  }
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* 40561698 FUN_40561698 */

/* Boundary evidence: original MIPS .pdata 40561698..405616a3. Semantic name remains unreviewed. */

undefined4 FUN_40561698(void)

{
  return 1;
}



/* 405616a4 FUN_405616a4 */

/* Boundary evidence: original MIPS .pdata 405616a4..405616af. Semantic name remains unreviewed. */

undefined4 FUN_405616a4(void)

{
  return 1;
}



/* 405616b0 FUN_405616b0 */

/* Boundary evidence: original MIPS .pdata 405616b0..4056174b. Semantic name remains unreviewed. */

undefined4 FUN_405616b0(void)

{
  LSTATUS LVar1;
  HKEY local_18;
  undefined4 local_14;
  DWORD local_10 [2];
  
  local_14 = 0;
  local_18 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Clock",0,0,&local_18);
  if (LVar1 == 0) {
    local_10[0] = 4;
    RegQueryValueExW(local_18,L"AutoDST",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_14,local_10);
    RegCloseKey(local_18);
  }
  return local_14;
}



/* 4056174c FUN_4056174c */

/* Boundary evidence: original MIPS .pdata 4056174c..40561967. Semantic name remains unreviewed. */

int FUN_4056174c(void)

{
  LSTATUS LVar1;
  int iVar2;
  HMODULE hLibModule;
  code *pcVar3;
  code *pcVar4;
  HANDLE hHandle;
  DWORD DVar5;
  undefined4 uVar6;
  int local_2b8;
  HKEY local_2b4;
  DWORD local_2b0 [2];
  WCHAR aWStack_2a8 [64];
  WCHAR aWStack_228 [256];
  uint local_28;
  
  local_28 = DAT_40563124;
  local_2b8 = 0;
  local_2b4 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\Clock",0,0,&local_2b4);
  if (LVar1 == 0) {
    local_2b0[0] = 4;
    RegQueryValueExW(local_2b4,L"ShowDSTUI",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_2b8,local_2b0);
    RegCloseKey(local_2b4);
  }
  if (local_2b8 != 0) {
    local_2b8 = 0;
    iVar2 = LoadStringW(DAT_4056312c,0x3e9,aWStack_228,0x100);
    if (((iVar2 != 0) && (iVar2 = LoadStringW(DAT_4056312c,0x3ea,aWStack_2a8,0x40), iVar2 != 0)) &&
       (hLibModule = LoadLibraryW(L"coredll.dll"), hLibModule != (HMODULE)0x0)) {
      pcVar3 = (code *)GetProcAddressW(hLibModule,L"MessageBoxW");
      pcVar4 = (code *)GetProcAddressW(hLibModule,L"GetForegroundWindow");
      if (((pcVar3 != (code *)0x0) && (pcVar4 != (code *)0x0)) &&
         (hHandle = OpenEventW(0x1f0003,0,L"SYSTEM/GweApiSetReady"), hHandle != (HANDLE)0x0)) {
        DVar5 = WaitForSingleObject(hHandle,30000);
        CloseHandle(hHandle);
        if (DVar5 == 0) {
          uVar6 = (*pcVar4)();
          (*pcVar3)(uVar6,aWStack_228,aWStack_2a8,0);
          local_2b8 = 1;
        }
      }
      FreeLibrary(hLibModule);
    }
  }
  FUN_40562988(local_28);
  return local_2b8;
}



/* 40561968 FUN_40561968 */

/* Boundary evidence: original MIPS .pdata 40561968..405619b7. Semantic name remains unreviewed. */

WORD FUN_40561968(void *param_1)

{
  _FILETIME _Stack_20;
  SYSTEMTIME SStack_18;
  
  memcpy(&SStack_18,param_1,0x10);
  SStack_18.wDayOfWeek = 0;
  SStack_18.wDay = 1;
  SystemTimeToFileTime(&SStack_18,&_Stack_20);
  FileTimeToSystemTime(&_Stack_20,&SStack_18);
  return SStack_18.wDayOfWeek;
}



/* 405619b8 FUN_405619b8 */

/* Boundary evidence: original MIPS .pdata 405619b8..40561b4f. Semantic name remains unreviewed. */

undefined4 FUN_405619b8(WORD *param_1,int param_2)

{
  WORD WVar1;
  undefined2 extraout_var;
  BOOL BVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  _FILETIME local_50;
  _FILETIME local_48;
  _FILETIME _Stack_40;
  SYSTEMTIME local_38;
  _SYSTEMTIME local_28;
  
  local_50.dwLowDateTime = 0;
  local_50.dwHighDateTime = 0;
  local_48.dwLowDateTime = 0;
  local_48.dwHighDateTime = 0;
  memcpy(&local_38,param_1,0x10);
  GetLocalTime(&local_28);
  if (local_38.wYear == 0) {
    local_38.wYear = local_28.wYear;
    *param_1 = local_28.wYear;
  }
  WVar1 = FUN_40561968(&local_38);
  uVar5 = CONCAT22(extraout_var,WVar1);
  uVar4 = (uint)param_1[2];
  if (uVar4 < uVar5) {
    uVar5 = (uVar4 - uVar5) + 8;
  }
  else {
    uVar5 = (uVar4 - uVar5) + 1;
  }
  uVar4 = uVar5 & 0xffff;
  uVar6 = 1;
  local_38.wDay = (WORD)uVar5;
  if (1 < param_1[3]) {
    while( true ) {
      local_38.wDay = (short)uVar4 + 7;
      BVar2 = SystemTimeToFileTime(&local_38,&_Stack_40);
      if (BVar2 == 0) break;
      uVar6 = uVar6 + 1;
      if (param_1[3] <= uVar6) goto LAB_40561ab4;
      uVar4 = (uint)local_38.wDay;
    }
    local_38.wDay = local_38.wDay - 7;
  }
LAB_40561ab4:
  SystemTimeToFileTime(&local_38,&local_50);
  SystemTimeToFileTime(&local_28,&local_48);
  if (((param_2 == 0) && ((int)local_50.dwHighDateTime <= (int)local_48.dwHighDateTime)) &&
     ((local_50.dwHighDateTime != local_48.dwHighDateTime ||
      (local_50.dwLowDateTime < local_48.dwLowDateTime)))) {
    *param_1 = *param_1 + 1;
    uVar3 = FUN_405619b8(param_1,1);
    return uVar3;
  }
  memcpy(param_1,&local_38,0x10);
  return 1;
}



/* 40561b50 FUN_40561b50 */

/* Boundary evidence: original MIPS .pdata 40561b50..40561ba7. Semantic name remains unreviewed. */

undefined4 FUN_40561b50(undefined4 param_1)

{
  undefined4 uVar1;
  
  DAT_4056312c = param_1;
  DAT_40563134 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
  if (DAT_40563134 == (HANDLE)0x0) {
    uVar1 = 0xe;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40561ba8 FUN_40561ba8 */

/* Boundary evidence: original MIPS .pdata 40561ba8..40561beb. Semantic name remains unreviewed. */

void FUN_40561ba8(void)

{
  CloseHandle(DAT_40563134);
  DAT_40563134 = (HANDLE)0x0;
  DAT_4056312c = 0;
  return;
}



/* 40561bec FUN_40561bec */

/* Boundary evidence: original MIPS .pdata 40561bec..40561c87. Semantic name remains unreviewed. */

undefined4 FUN_40561bec(void)

{
  undefined4 uVar1;
  DWORD DVar2;
  
  if (DAT_4056312c == 0) {
    uVar1 = 0x424;
  }
  else {
    DVar2 = WaitForSingleObject(DAT_40563134,0);
    if (DVar2 == 0) {
      uVar1 = 0x426;
    }
    else {
      EventModify(DAT_40563134,3);
      WaitForSingleObject(DAT_40563130,0xffffffff);
      CloseHandle(DAT_40563130);
      uVar1 = 0;
      DAT_40563130 = (HANDLE)0x0;
    }
  }
  return uVar1;
}



/* 40561c88 FUN_40561c88 */

/* Boundary evidence: original MIPS .pdata 40561c88..40561cdf. Semantic name remains unreviewed. */

undefined4 FUN_40561c88(void)

{
  undefined4 uVar1;
  DWORD DVar2;
  
  if (DAT_4056312c == 0) {
    uVar1 = 5;
  }
  else {
    DVar2 = WaitForSingleObject(DAT_40563134,0);
    if (DVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* 40561ce0 FUN_40561ce0 */

undefined4 FUN_40561ce0(void)

{
  undefined4 *in_stack_00000014;
  
  *in_stack_00000014 = 0;
  return 0x57;
}



/* 40561cf0 FUN_40561cf0 */

/* Boundary evidence: original MIPS .pdata 40561cf0..40561f7f. Semantic name remains unreviewed. */

void FUN_40561cf0(void *param_1)

{
  uint uVar1;
  DWORD DVar3;
  int iVar4;
  _FILETIME local_e0;
  _FILETIME local_d8;
  _FILETIME local_d0;
  _SYSTEMTIME _Stack_c8;
  _TIME_ZONE_INFORMATION local_b8;
  uint local_c;
  longlong lVar2;
  
  local_c = DAT_40563124;
  DVar3 = GetTimeZoneInformation(&local_b8);
  if ((local_b8.StandardDate.wMonth == 0) || (local_b8.DaylightDate.wMonth == 0)) {
    if (DVar3 != 1) {
      SetDaylightTime(0);
    }
    DAT_40563120 = 1;
    goto LAB_40561f68;
  }
  local_d8.dwLowDateTime = 0;
  local_d8.dwHighDateTime = 0;
  local_e0.dwLowDateTime = 0;
  local_e0.dwHighDateTime = 0;
  local_d0.dwLowDateTime = 0;
  local_d0.dwHighDateTime = 0;
  if (param_1 == (void *)0x0) {
    GetSystemTime(&_Stack_c8);
  }
  else {
    memcpy(&_Stack_c8,param_1,0x10);
  }
  if (local_b8.StandardDate.wYear == 0) {
    FUN_405619b8(&local_b8.StandardDate.wYear,1);
  }
  if (local_b8.DaylightDate.wYear == 0) {
    FUN_405619b8(&local_b8.DaylightDate.wYear,1);
  }
  SystemTimeToFileTime(&local_b8.StandardDate,&local_d8);
  SystemTimeToFileTime(&local_b8.DaylightDate,&local_e0);
  SystemTimeToFileTime(&_Stack_c8,&local_d0);
  lVar2 = (ulonglong)(uint)(local_b8.DaylightBias + local_b8.Bias) * 600000000;
  uVar1 = (uint)lVar2;
  local_d8.dwLowDateTime = uVar1 + local_d8.dwLowDateTime;
  local_d8.dwHighDateTime =
       (local_b8.DaylightBias + local_b8.Bias >> 0x1f) * 600000000 + (int)((ulonglong)lVar2 >> 0x20)
       + local_d8.dwHighDateTime + (uint)(local_d8.dwLowDateTime < uVar1);
  uVar1 = (uint)((ulonglong)(uint)local_b8.Bias * 600000000);
  local_e0.dwLowDateTime = uVar1 + local_e0.dwLowDateTime;
  local_e0.dwHighDateTime =
       (local_b8.Bias >> 0x1f) * 600000000 +
       (int)((ulonglong)(uint)local_b8.Bias * 600000000 >> 0x20) + local_e0.dwHighDateTime +
       (uint)(local_e0.dwLowDateTime < uVar1);
  iVar4 = FUN_405616b0();
  if (iVar4 != 0) {
    if (((int)local_d8.dwHighDateTime < (int)local_e0.dwHighDateTime) ||
       ((local_e0.dwHighDateTime == local_d8.dwHighDateTime &&
        (local_d8.dwLowDateTime < local_e0.dwLowDateTime)))) {
      if (((int)local_d0.dwHighDateTime <= (int)local_e0.dwHighDateTime) &&
         ((local_e0.dwHighDateTime != local_d0.dwHighDateTime ||
          (local_d0.dwLowDateTime < local_e0.dwLowDateTime)))) {
        if ((int)local_d8.dwHighDateTime < (int)local_d0.dwHighDateTime) goto LAB_40561edc;
        if (local_d0.dwHighDateTime == local_d8.dwHighDateTime) goto joined_r0x40561f2c;
      }
LAB_40561f34:
      SetDaylightTime(1);
      DAT_40563120 = 2;
      goto LAB_40561f68;
    }
    if (((int)local_e0.dwHighDateTime <= (int)local_d0.dwHighDateTime) &&
       ((local_e0.dwHighDateTime != local_d0.dwHighDateTime ||
        (local_e0.dwLowDateTime <= local_d0.dwLowDateTime)))) {
      if ((int)local_d0.dwHighDateTime < (int)local_d8.dwHighDateTime) goto LAB_40561f34;
      if (local_d0.dwHighDateTime == local_d8.dwHighDateTime) {
joined_r0x40561f2c:
        if (local_d0.dwLowDateTime <= local_d8.dwLowDateTime) goto LAB_40561f34;
      }
    }
  }
LAB_40561edc:
  SetDaylightTime(0);
  DAT_40563120 = 1;
LAB_40561f68:
  FUN_40562988(local_c);
  return;
}



/* 40561f80 FUN_40561f80 */

/* Boundary evidence: original MIPS .pdata 40561f80..4056210b. Semantic name remains unreviewed. */

HANDLE FUN_40561f80(void)

{
  int iVar1;
  SYSTEMTIME *_Src;
  HANDLE hObject;
  _FILETIME local_e8;
  _FILETIME local_e0;
  SYSTEMTIME local_d8;
  _SYSTEMTIME _Stack_c8;
  _TIME_ZONE_INFORMATION local_b8;
  uint local_c;
  
  local_c = DAT_40563124;
  hObject = (HANDLE)0x0;
  local_b8.Bias = 0;
  memset(local_b8.StandardName,0,0xa8);
  local_e0.dwLowDateTime = 0;
  local_e0.dwHighDateTime = 0;
  local_e8.dwLowDateTime = 0;
  local_e8.dwHighDateTime = 0;
  GetTimeZoneInformation(&local_b8);
  if ((local_b8.StandardDate.wMonth == 0) || (local_b8.DaylightDate.wMonth == 0)) {
LAB_405620ec:
    FUN_40562988(local_c);
    hObject = (HANDLE)0x0;
  }
  else {
    if (DAT_40563120 == 1) {
      _Src = &local_b8.DaylightDate;
    }
    else {
      if (DAT_40563120 != 2) goto LAB_405620ec;
      _Src = &local_b8.StandardDate;
    }
    memcpy(&local_d8,_Src,0x10);
    if (local_d8.wYear == 0) {
      FUN_405619b8(&local_d8.wYear,0);
    }
    SystemTimeToFileTime(&local_d8,&local_e8);
    GetLocalTime(&_Stack_c8);
    SystemTimeToFileTime(&_Stack_c8,&local_e0);
    if ((((int)local_e0.dwHighDateTime <= (int)local_e8.dwHighDateTime) &&
        (((local_e8.dwHighDateTime != local_e0.dwHighDateTime ||
          (local_e0.dwLowDateTime < local_e8.dwLowDateTime)) &&
         (hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"ShellDSTEvent"),
         hObject != (HANDLE)0xffffffff)))) &&
       (iVar1 = CeRunAppAtTime(L"\\\\.\\Notifications\\NamedEvents\\ShellDSTEvent",&local_d8),
       iVar1 == 0)) {
      CloseHandle(hObject);
      hObject = (HANDLE)0x0;
    }
    FUN_40562988(local_c);
  }
  return hObject;
}



/* 4056210c FUN_4056210c */

/* Boundary evidence: original MIPS .pdata 4056210c..405624e3. Semantic name remains unreviewed. */

undefined4 FUN_4056210c(HANDLE *param_1)

{
  uint uVar1;
  DWORD DVar2;
  undefined4 uVar3;
  int iVar4;
  _FILETIME local_108;
  _FILETIME local_100;
  FILETIME local_f8;
  _FILETIME local_f0;
  _SYSTEMTIME _Stack_e8;
  _SYSTEMTIME _Stack_d8;
  _TIME_ZONE_INFORMATION local_c8;
  uint local_1c;
  
  local_1c = DAT_40563124;
  DVar2 = 4;
  if (param_1[3] == (HANDLE)0x0) {
    DVar2 = 3;
  }
  DVar2 = WaitForMultipleObjects(DVar2,param_1,0,0xffffffff);
  CeRunAppAtEvent(L"\\\\.\\Notifications\\NamedEvents\\DSTTzChange",0);
  CeRunAppAtEvent(L"\\\\.\\Notifications\\NamedEvents\\DSTTimeChange",0);
  CeRunAppAtTime(L"\\\\.\\Notifications\\NamedEvents\\ShellDSTEvent",0);
  iVar4 = 3;
  do {
    param_1 = param_1 + 1;
    if (*param_1 != (HANDLE)0x0) {
      CloseHandle(*param_1);
      *param_1 = (HANDLE)0x0;
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if ((DVar2 == 0) || (DVar2 == 0)) {
LAB_405624b4:
    FUN_40562988(local_1c);
    return 0;
  }
  if (DVar2 < 3) {
    FUN_40561cf0((void *)0x0);
    goto LAB_40562388;
  }
  if (DVar2 != 3) goto LAB_405624b4;
  iVar4 = FUN_405616b0();
  if (iVar4 == 0) goto LAB_40562388;
  GetLocalTime(&_Stack_d8);
  SystemTimeToFileTime(&_Stack_d8,&local_f0);
  local_c8.Bias = 0;
  memset(local_c8.StandardName,0,0xa8);
  GetTimeZoneInformation(&local_c8);
  local_108.dwLowDateTime = 0;
  local_108.dwHighDateTime = 0;
  local_100.dwLowDateTime = 0;
  local_100.dwHighDateTime = 0;
  if (local_c8.StandardDate.wYear == 0) {
    FUN_405619b8(&local_c8.StandardDate.wYear,1);
  }
  if (local_c8.DaylightDate.wYear == 0) {
    FUN_405619b8(&local_c8.DaylightDate.wYear,1);
  }
  SystemTimeToFileTime(&local_c8.StandardDate,&local_108);
  SystemTimeToFileTime(&local_c8.DaylightDate,&local_100);
  iVar4 = (local_f0.dwHighDateTime - local_100.dwHighDateTime) -
          (uint)(local_f0.dwLowDateTime < local_100.dwLowDateTime);
  if ((iVar4 < 0) ||
     ((-1 < iVar4 &&
      ((local_f0.dwHighDateTime - local_100.dwHighDateTime !=
        (uint)(local_f0.dwLowDateTime < local_100.dwLowDateTime) ||
       (599999999 < local_f0.dwLowDateTime - local_100.dwLowDateTime)))))) {
    iVar4 = (local_f0.dwHighDateTime - local_108.dwHighDateTime) -
            (uint)(local_f0.dwLowDateTime < local_108.dwLowDateTime);
    if ((-1 < iVar4) &&
       ((iVar4 < 0 ||
        ((local_f0.dwHighDateTime - local_108.dwHighDateTime ==
          (uint)(local_f0.dwLowDateTime < local_108.dwLowDateTime) &&
         (local_f0.dwLowDateTime - local_108.dwLowDateTime < 600000000)))))) goto LAB_405623e0;
    if (((int)local_100.dwHighDateTime <= (int)local_108.dwHighDateTime) &&
       ((local_100.dwHighDateTime != local_108.dwHighDateTime ||
        (local_100.dwLowDateTime <= local_108.dwLowDateTime)))) {
      if (((int)local_100.dwHighDateTime <= (int)local_f0.dwHighDateTime) &&
         ((local_100.dwHighDateTime != local_f0.dwHighDateTime ||
          (local_100.dwLowDateTime <= local_f0.dwLowDateTime)))) {
        if ((int)local_f0.dwHighDateTime < (int)local_108.dwHighDateTime) goto LAB_40562370;
        if (local_f0.dwHighDateTime == local_108.dwHighDateTime) {
joined_r0x405623d0:
          if (local_f0.dwLowDateTime <= local_108.dwLowDateTime) goto LAB_40562370;
        }
      }
LAB_405623d8:
      if (DAT_40563120 == 1) goto LAB_40562388;
      goto LAB_405623e0;
    }
    if (((int)local_f0.dwHighDateTime <= (int)local_100.dwHighDateTime) &&
       ((local_100.dwHighDateTime != local_f0.dwHighDateTime ||
        (local_f0.dwLowDateTime < local_100.dwLowDateTime)))) {
      if ((int)local_108.dwHighDateTime < (int)local_f0.dwHighDateTime) goto LAB_405623d8;
      if (local_f0.dwHighDateTime == local_108.dwHighDateTime) goto joined_r0x405623d0;
    }
LAB_40562370:
    if (DAT_40563120 == 2) goto LAB_40562388;
LAB_40562434:
    DAT_40563120 = 2;
    uVar1 = (uint)((ulonglong)(uint)local_c8.DaylightBias * 600000000);
    local_f8.dwLowDateTime = local_f0.dwLowDateTime - uVar1;
    local_f8.dwHighDateTime =
         (local_f0.dwHighDateTime -
         ((local_c8.DaylightBias >> 0x1f) * 600000000 +
         (int)((ulonglong)(uint)local_c8.DaylightBias * 600000000 >> 0x20))) -
         (uint)(local_f0.dwLowDateTime < uVar1);
    uVar3 = 1;
  }
  else {
LAB_405623e0:
    if (DAT_40563120 != 2) goto LAB_40562434;
    DAT_40563120 = 1;
    uVar1 = (uint)((ulonglong)(uint)local_c8.DaylightBias * 600000000);
    local_f8.dwLowDateTime = uVar1 + local_f0.dwLowDateTime;
    local_f8.dwHighDateTime =
         (local_c8.DaylightBias >> 0x1f) * 600000000 +
         (int)((ulonglong)(uint)local_c8.DaylightBias * 600000000 >> 0x20) + local_f0.dwHighDateTime
         + (uint)(local_f8.dwLowDateTime < uVar1);
    uVar3 = 0;
  }
  SetDaylightTime(uVar3);
  FileTimeToSystemTime(&local_f8,&_Stack_e8);
  SetLocalTime(&_Stack_e8);
  FUN_4056174c();
LAB_40562388:
  FUN_40562988(local_1c);
  return 1;
}



/* 405624e4 FUN_405624e4 */

/* Boundary evidence: original MIPS .pdata 405624e4..40562663. Semantic name remains unreviewed. */

undefined4 FUN_405624e4(void)

{
  HANDLE pvVar1;
  int iVar2;
  HANDLE local_38;
  HANDLE local_34;
  HANDLE local_30;
  HANDLE local_2c;
  
  CeRunAppAtEvent(L"\\\\.\\Notifications\\NamedEvents\\DSTTzChange",0);
  CeRunAppAtEvent(L"\\\\.\\Notifications\\NamedEvents\\DSTTimeChange",0);
  CeRunAppAtTime(L"\\\\.\\Notifications\\NamedEvents\\ShellDSTEvent",0);
  FUN_40561cf0((void *)0x0);
  do {
    local_38 = DAT_40563134;
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"DSTTzChange");
    if ((pvVar1 != (HANDLE)0x0) &&
       (iVar2 = CeRunAppAtEvent(L"\\\\.\\Notifications\\NamedEvents\\DSTTzChange",0xc), iVar2 == 0))
    {
      CloseHandle(pvVar1);
      pvVar1 = (HANDLE)0x0;
    }
    local_34 = pvVar1;
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"DSTTimeChange");
    if ((pvVar1 != (HANDLE)0x0) &&
       (iVar2 = CeRunAppAtEvent(L"\\\\.\\Notifications\\NamedEvents\\DSTTimeChange",1), iVar2 == 0))
    {
      CloseHandle(pvVar1);
      pvVar1 = (HANDLE)0x0;
    }
    local_30 = pvVar1;
    local_2c = FUN_40561f80();
  } while (((local_34 != (HANDLE)0x0) && (local_30 != (HANDLE)0x0)) &&
          (iVar2 = FUN_4056210c(&local_38), iVar2 != 0));
  return 0;
}



/* 40562664 FUN_40562664 */

/* Boundary evidence: original MIPS .pdata 40562664..4056272f. Semantic name remains unreviewed. */

DWORD FUN_40562664(void)

{
  DWORD DVar1;
  
  if (DAT_4056312c == 0) {
    DVar1 = 0x424;
  }
  else {
    DVar1 = WaitForSingleObject(DAT_40563134,0);
    if (DVar1 == 0x102) {
      DVar1 = 0x420;
    }
    else {
      EventModify(DAT_40563134,2);
      DAT_40563130 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_405624e4,(LPVOID)0x0,0,
                                  (LPDWORD)0x0);
      if (DAT_40563130 == (HANDLE)0x0) {
        DVar1 = GetLastError();
        EventModify(DAT_40563134,3);
      }
      else {
        DVar1 = 0;
      }
    }
  }
  return DVar1;
}



/* 40562730 NTP_PowerDown */

void NTP_PowerDown(void)

{
                    /* 0x2730  6  NTP_PowerDown
                       0x2730  7  NTP_PowerUp */
  return;
}



/* 40562738 FUN_40562738 */

undefined4 FUN_40562738(void)

{
  return 0;
}



/* 40562740 FUN_40562740 */

undefined4 FUN_40562740(void)

{
  undefined4 *in_stack_00000014;
  
  *in_stack_00000014 = 0;
  return 0;
}



/* 40562820 entry */

/* Boundary evidence: original MIPS .pdata 40562820..40562893. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_40562894();
    FUN_40562b68();
  }
  uVar1 = FUN_40561290(param_1,param_2);
  if (param_2 == 0) {
    FUN_40562af0();
  }
  return uVar1;
}



/* 40562894 FUN_40562894 */

/* Boundary evidence: original MIPS .pdata 40562894..40562907. Semantic name remains unreviewed. */

void FUN_40562894(void)

{
  uint uVar1;
  
  if ((DAT_40563124 == 0) || (DAT_40563124 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40563124 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40563124 == 0) {
      DAT_40563124 = 0xb064;
    }
  }
  DAT_40563128 = ~DAT_40563124;
  return;
}



/* 40562908 FUN_40562908 */

/* Boundary evidence: original MIPS .pdata 40562908..4056295b. Semantic name remains unreviewed. */

void FUN_40562908(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40562988(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 4056295c FUN_4056295c */

/* Boundary evidence: original MIPS .pdata 4056295c..40562987. Semantic name remains unreviewed. */

undefined4 FUN_4056295c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40562908(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40562988 FUN_40562988 */

/* Boundary evidence: original MIPS .pdata 40562988..405629cf. Semantic name remains unreviewed. */

void FUN_40562988(uint param_1)

{
  if ((param_1 == DAT_40563124) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 405629d0 FUN_405629d0 */

/* Boundary evidence: original MIPS .pdata 405629d0..40562aef. Semantic name remains unreviewed. */

void FUN_405629d0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_40563138 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40563140;
    if (DAT_40563140 != (undefined4 *)0x0) {
      while (DAT_4056313c = DAT_4056313c + -1, _Memory <= DAT_4056313c) {
        if ((code *)*DAT_4056313c != (code *)0x0) {
          (*(code *)*DAT_4056313c)();
          _Memory = DAT_40563140;
        }
      }
      free(_Memory);
      DAT_4056313c = (undefined4 *)0x0;
      DAT_40563140 = (undefined4 *)0x0;
    }
    FUN_40562b14((undefined4 *)&DAT_40561010,(undefined4 *)&DAT_40561014);
  }
  FUN_40562b14((undefined4 *)&DAT_40561018,(undefined4 *)&DAT_4056101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_40563144,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40562af0 FUN_40562af0 */

/* Boundary evidence: original MIPS .pdata 40562af0..40562b13. Semantic name remains unreviewed. */

void FUN_40562af0(void)

{
  FUN_405629d0(0,0,1);
  return;
}



/* 40562b14 FUN_40562b14 */

/* Boundary evidence: original MIPS .pdata 40562b14..40562b67. Semantic name remains unreviewed. */

void FUN_40562b14(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40562b68 FUN_40562b68 */

/* Boundary evidence: original MIPS .pdata 40562b68..40562ba3. Semantic name remains unreviewed. */

void FUN_40562b68(void)

{
  FUN_40562b14((undefined4 *)&DAT_40561008,(undefined4 *)&DAT_4056100c);
  FUN_40562b14((undefined4 *)&DAT_40561000,(undefined4 *)&DAT_40561004);
  return;
}


