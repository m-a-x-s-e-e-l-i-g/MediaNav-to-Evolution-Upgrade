/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c080144c TouchCreateEvent */

undefined4 TouchCreateEvent(void)

{
                    /* 0x144c  1  TouchCreateEvent
                       0x144c  2  TouchGetFocusWnd
                       0x144c  3  TouchGetLastTouchFocusWnd
                       0x144c  4  TouchGetQueuePtr
                       0x144c  5  TouchGetValue
                       0x144c  6  TouchRegisterWindow
                       0x144c  7  TouchReset
                       0x144c  8  TouchSetValue
                       0x144c  9  TouchUnregisterWindow */
  return 1;
}



/* c0801454 FUN_c0801454 */

undefined4 FUN_c0801454(void)

{
  DAT_c080516c = 0;
  DAT_c0805170 = 0;
  return 0;
}



/* c0801474 FUN_c0801474 */

/* Boundary evidence: original MIPS .pdata c0801474..c08015a3. Semantic name remains unreviewed. */

undefined4 FUN_c0801474(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = param_1[1];
  iVar6 = iVar3 / 10;
  iVar5 = param_1[2];
  iVar7 = iVar5 / 10;
  iVar1 = *param_1;
  iVar2 = iVar3 >> 1;
  iVar4 = iVar5 >> 1;
  if (iVar1 == 0) {
    if (iVar3 < 0) {
      iVar2 = iVar3 + 1 >> 1;
    }
    param_1[3] = iVar2;
    if (iVar5 < 0) {
      iVar4 = iVar5 + 1 >> 1;
    }
  }
  else {
    if (iVar1 == 1) {
      param_1[3] = iVar6 << 1;
      param_1[4] = iVar7 << 1;
      return 1;
    }
    if (iVar1 == 2) {
      param_1[3] = iVar6 << 1;
      param_1[4] = iVar5 + iVar7 * -2;
      return 1;
    }
    if (iVar1 == 3) {
      param_1[3] = iVar3 + iVar6 * -2;
      iVar4 = iVar5 + iVar7 * -2;
    }
    else {
      if (iVar1 != 4) {
        if (iVar3 < 0) {
          iVar2 = iVar3 + 1 >> 1;
        }
        param_1[3] = iVar2;
        if (iVar5 < 0) {
          iVar4 = iVar5 + 1 >> 1;
        }
        param_1[4] = iVar4;
        SetLastError(0x57);
        return 0;
      }
      param_1[3] = iVar3 + iVar6 * -2;
      iVar4 = iVar7 << 1;
    }
  }
  param_1[4] = iVar4;
  return 1;
}



/* c08015a4 FUN_c08015a4 */

/* Boundary evidence: original MIPS .pdata c08015a4..c080162b. Semantic name remains unreviewed. */

undefined4 FUN_c08015a4(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      *param_2 = 100;
      param_2[1] = 100;
      param_2[2] = 100;
      return 1;
    }
    if (param_1 == 1) {
      *param_2 = 0;
      param_2[1] = 5;
      return 1;
    }
    if (param_1 == 2) {
      uVar1 = FUN_c0801474(param_2);
      return uVar1;
    }
    SetLastError(0x57);
  }
  return 0;
}



/* c080162c FUN_c080162c */

undefined4 FUN_c080162c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((-1 < param_1) && (param_1 < 2)) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c080164c FUN_c080164c */

undefined4 FUN_c080164c(uint param_1,uint param_2,uint param_3,int param_4,int *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0x10;
  if (((param_1 < 0xfff) && (param_2 < 0xfff)) && (param_3 < 0xfff)) {
    iVar5 = param_1 - param_2;
    iVar3 = param_2 - param_3;
    iVar4 = param_3 - param_1;
    if (iVar5 < 1) {
      iVar5 = -iVar5;
    }
    if (iVar3 < 1) {
      iVar3 = -iVar3;
    }
    if (iVar4 < 1) {
      iVar4 = -iVar4;
    }
    if (iVar5 < iVar3) {
      if (iVar5 <= iVar4) {
        param_3 = param_2;
      }
      iVar2 = param_3 + param_1;
    }
    else {
      if (iVar3 <= iVar4) {
        param_1 = param_2;
      }
      iVar2 = param_1 + param_3;
    }
    *param_5 = iVar2;
    *param_5 = iVar2 >> 1;
    if (((iVar5 < param_4) && (iVar3 < param_4)) && (iVar4 < param_4)) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* c0801720 FUN_c0801720 */

/* Boundary evidence: original MIPS .pdata c0801720..c0801807. Semantic name remains unreviewed. */

void FUN_c0801720(void)

{
  HANDLE hHandle;
  DWORD DVar1;
  DWORD dwMilliseconds;
  
  DAT_c0805188 = 0;
  hHandle = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"EVT_upgrade");
  dwMilliseconds = 0xffffffff;
  do {
    do {
      while (DVar1 = WaitForSingleObject(hHandle,dwMilliseconds), DVar1 == 0) {
        NKDbgPrintfW(L"Touch: RESCUE TOUCH start\r\n");
        DAT_c0805188 = 1;
        InterruptStartTimer(DAT_c0805180,20000);
        dwMilliseconds = 5000;
      }
    } while (DVar1 != 0x102);
    DAT_c0805188 = 0;
    InterruptStopTimer(DAT_c0805180);
    InterruptDone(DAT_c0805180);
    NKDbgPrintfW(L"Touch: RESCUE TOUCH end\r\n");
    dwMilliseconds = 0xffffffff;
  } while( true );
}



/* c0801808 FUN_c0801808 */

/* Boundary evidence: original MIPS .pdata c0801808..c0801897. Semantic name remains unreviewed. */

void FUN_c0801808(void)

{
  InterruptDisconnect(DAT_c0805180);
  DAT_c0805180 = 0;
  InterruptDisconnect(DAT_c080517c);
  DAT_c080517c = 0;
  if (DAT_c0805164 != 0) {
    MmUnmapIoSpace(DAT_c0805164,0x1200);
    DAT_c0805164 = 0;
  }
  if (DAT_c08050b8 != -1) {
    CloseHandle((HANDLE)DAT_c08050b8);
    DAT_c08050b8 = -1;
  }
  return;
}



/* c0801898 FUN_c0801898 */

/* Boundary evidence: original MIPS .pdata c0801898..c0801b9f. Semantic name remains unreviewed. */

BOOL FUN_c0801898(ushort *param_1,int param_2)

{
  BOOL BVar1;
  char cVar2;
  BOOL BVar3;
  char cVar4;
  char cVar5;
  undefined4 local_40;
  DWORD DStack_3c;
  _SYSTEMTIME _Stack_38;
  
  local_40 = 0;
  local_40 = READ_REGISTER_ULONG(DAT_c0805164 + 8);
  if (((local_40 & 8) == 0) ||
     (local_40 = READ_REGISTER_ULONG(DAT_c0805164 + 4), (local_40 & 8) == 0)) {
    if (param_2 == 2) {
      cVar2 = 'k';
      cVar5 = 'z';
      cVar4 = 'T';
    }
    else if (param_2 == 4) {
      cVar2 = 'm';
      cVar5 = '|';
      cVar4 = 'V';
    }
    else if (param_2 == 6) {
      cVar2 = 'o';
      cVar5 = '~';
      cVar4 = 'X';
    }
    else {
      cVar2 = 'i';
      cVar5 = 'x';
      cVar4 = 'R';
    }
    DAT_c08057b0 = cVar2 << 1;
    DAT_c08057a8 = 0x48;
    DAT_c08057ac = 1;
    BVar1 = DeviceIoControl(DAT_c08050b8,0x80002001,&DAT_c08057a8,0x208,(LPVOID)0x0,0,&local_40,
                            (LPOVERLAPPED)0x0);
    BVar3 = 0;
    if (BVar1 != 0) {
      Sleep(2);
      DAT_c08057a8 = 0x48;
      DAT_c08057b0 = cVar5 << 1;
      DAT_c08057ac = 1;
      BVar1 = DeviceIoControl(DAT_c08050b8,0x80002001,&DAT_c08057a8,0x208,(LPVOID)0x0,0,&local_40,
                              (LPOVERLAPPED)0x0);
      BVar3 = 0;
      if (BVar1 != 0) {
        Sleep(2);
        while( true ) {
          DAT_c0805190 = 0x48;
          DAT_c0805194 = 2;
          DAT_c0805198 = cVar4 << 1 | 1;
          BVar3 = DeviceIoControl(DAT_c08050b8,0x80002002,&DAT_c0805190,0x208,&DAT_c0805199,2,
                                  &DStack_3c,(LPOVERLAPPED)0x0);
          if (BVar3 != 1) break;
          memcpy(&local_40,&DAT_c0805199,DAT_c0805194);
          if ((local_40 & 0x300) == 0) {
            *param_1 = (ushort)(local_40._1_1_ >> 4) | (ushort)(byte)local_40 << 4;
            goto LAB_c0801b60;
          }
          if (((local_40._1_1_ & 3) != 3) || (DAT_c0805168 != 1)) {
            BVar3 = 0;
            goto LAB_c0801b60;
          }
          GetLocalTime(&_Stack_38);
          Sleep(1);
        }
        NKDbgPrintfW(L"SMBusReadRegData() is failed\r\n");
      }
    }
LAB_c0801b60:
    Sleep(1);
  }
  else {
    BVar3 = 0;
  }
  return BVar3;
}



/* c0801ba0 FUN_c0801ba0 */

/* Boundary evidence: original MIPS .pdata c0801ba0..c0801e1f. Semantic name remains unreviewed. */

BOOL FUN_c0801ba0(void)

{
  HANDLE hDevice;
  wchar_t *pwVar1;
  BOOL BVar2;
  int iVar3;
  uint uVar4;
  int local_48;
  DWORD DStack_40;
  DWORD DStack_3c;
  undefined1 local_38 [12];
  uint local_2c;
  
  local_2c = DAT_c0805140;
  BVar2 = 0;
  if (DAT_c08050b8 == (HANDLE)0xffffffff) goto LAB_c0801de4;
  local_48 = 100;
  iVar3 = 100;
  do {
    DAT_c0805398 = 0x48;
    DAT_c08053a0 = 0x16;
    DAT_c08053a1 = 0x80;
    DAT_c080539c = 2;
    BVar2 = DeviceIoControl(DAT_c08050b8,0x80002001,&DAT_c0805398,0x209,(LPVOID)0x0,0,&DStack_40,
                            (LPOVERLAPPED)0x0);
    if (BVar2 != 0) {
      local_38[6] = 8;
      local_38[0] = 0xf0;
      local_38[4] = 0x80;
      local_38[5] = 0x80;
      local_38[1] = 0;
      local_38[2] = 0;
      local_38[3] = 0;
      local_38[7] = 0;
      local_38[8] = 0;
      local_38[9] = 0;
      local_38[10] = 0;
      goto LAB_c0801d00;
    }
    NKDbgPrintfW(L"SMBusWriteRegister() failure count : %d\r\n",0x65 - iVar3);
    Sleep(1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pwVar1 = L"SMBusWriteRegister() is failed\r\n";
  BVar2 = 0;
  goto LAB_c0801ca8;
  while( true ) {
    NKDbgPrintfW(L"SMBusWriteInitData() failure count : %d\r\n",0x65 - local_48);
    Sleep(1);
    local_48 = local_48 + -1;
    if (local_48 == 0) break;
LAB_c0801d00:
    hDevice = DAT_c08050b8;
    iVar3 = 0;
    uVar4 = 2;
    do {
      DAT_c08055a9 = local_38[iVar3];
      DAT_c08055a0 = 0x48;
      DAT_c08055a8 = (undefined1)uVar4;
      DAT_c08055a4 = 2;
      BVar2 = DeviceIoControl(hDevice,0x80002001,&DAT_c08055a0,0x209,(LPVOID)0x0,0,&DStack_3c,
                              (LPOVERLAPPED)0x0);
      if (BVar2 == 0) break;
      uVar4 = uVar4 + 2;
      iVar3 = iVar3 + 1;
    } while (uVar4 < 0x18);
    if (BVar2 != 0) {
      Sleep(1);
      DAT_c0805168 = 1;
      goto LAB_c0801de4;
    }
  }
  pwVar1 = L"SMBusWriteInitData() is failed\r\n";
LAB_c0801ca8:
  NKDbgPrintfW(pwVar1);
LAB_c0801de4:
  FUN_c08048d4(local_2c);
  return BVar2;
}



/* c0801e20 FUN_c0801e20 */

/* Boundary evidence: original MIPS .pdata c0801e20..c0801eb7. Semantic name remains unreviewed. */

BOOL FUN_c0801e20(void)

{
  BOOL BVar1;
  DWORD aDStack_10 [2];
  
  BVar1 = 0;
  if (DAT_c08050b8 != (HANDLE)0xffffffff) {
    DAT_c0805398 = 0x48;
    DAT_c08053a0 = 0x16;
    DAT_c08053a1 = 0x80;
    DAT_c080539c = 2;
    BVar1 = DeviceIoControl(DAT_c08050b8,0x80002001,&DAT_c0805398,0x209,(LPVOID)0x0,0,aDStack_10,
                            (LPOVERLAPPED)0x0);
    if (BVar1 == 1) {
      DAT_c0805168 = 0;
    }
  }
  return BVar1;
}



/* c0801eb8 FUN_c0801eb8 */

/* Boundary evidence: original MIPS .pdata c0801eb8..c080214b. Semantic name remains unreviewed. */

undefined4 FUN_c0801eb8(void)

{
  LSTATUS LVar1;
  size_t sVar2;
  BOOL BVar3;
  HKEY local_88 [2];
  wchar_t awStack_80 [46];
  uint local_24;
  
  local_24 = DAT_c0805140;
  memcpy(awStack_80,L"2060,2020 3224,3136 3228,938 866,896 874,3150",0x5c);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"HARDWARE\\DEVICEMAP\\TOUCH",0,0,local_88);
  if (LVar1 == 0) {
    sVar2 = wcslen(awStack_80);
    LVar1 = RegSetValueExW(local_88[0],L"CalibrationData",0,1,(BYTE *)awStack_80,(sVar2 + 1) * 2);
  }
  else {
    NKDbgPrintfW(L"RegisteCalibrationData ERROR!\r\n");
  }
  RegCloseKey(local_88[0]);
  if ((LVar1 == 0) &&
     (DAT_c08050b8 = CreateFileW(L"SMB1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0),
     DAT_c08050b8 != (HANDLE)0xffffffff)) {
    DAT_c0805164 = MmMapIoSpace(0x10200000,0,0x1200,0);
    if (DAT_c0805164 != 0) {
      DAT_c080517c = InterruptConnect(0,0,0x43,0xd0);
      if (DAT_c080517c != 0) {
        InterruptDone(DAT_c080517c);
        DAT_c0805184 = InterruptConnect(0,0,0x23,0xd0);
        if (DAT_c0805184 != 0) {
          InterruptInitialize(DAT_c0805184,DAT_c0805a54,0,0);
          InterruptDone(DAT_c0805184);
          DAT_c0805180 = InterruptConnectTimer();
          if (DAT_c0805180 != 0) {
            InterruptDone(DAT_c0805180);
            BVar3 = FUN_c0801ba0();
            if (BVar3 != 0) {
              if (DAT_c080518c == (HANDLE)0x0) {
                DAT_c080518c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0801720,(LPVOID)0x0,0,
                                            (LPDWORD)0x0);
              }
              FUN_c08048d4(local_24);
              return 1;
            }
            InterruptDisconnect(DAT_c0805180);
            DAT_c0805180 = 0;
          }
          InterruptDisconnect(DAT_c080517c);
          DAT_c080517c = 0;
        }
      }
      MmUnmapIoSpace(DAT_c0805164,0x1200);
      DAT_c0805164 = 0;
    }
    CloseHandle(DAT_c08050b8);
    DAT_c08050b8 = (HANDLE)0xffffffff;
  }
  FUN_c08048d4(local_24);
  return 0;
}



/* c080214c FUN_c080214c */

/* Boundary evidence: original MIPS .pdata c080214c..c0802197. Semantic name remains unreviewed. */

void FUN_c080214c(int param_1)

{
  if (param_1 == 0) {
    NKDbgPrintfW(L"TSC power on\r\n");
    FUN_c0801ba0();
  }
  else {
    NKDbgPrintfW(L"TSC power off\r\n");
    FUN_c0801e20();
  }
  return;
}



/* c0802198 FUN_c0802198 */

/* Boundary evidence: original MIPS .pdata c0802198..c08022c7. Semantic name remains unreviewed. */

uint FUN_c0802198(int *param_1,int *param_2)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  int local_40;
  int local_3c;
  ushort local_38;
  ushort local_36;
  ushort local_30;
  ushort local_2e;
  ushort local_28;
  ushort local_26;
  
  local_3c = 0;
  local_40 = 0;
  uVar3 = 2;
  uVar5 = 0;
  puVar4 = &local_38;
  while ((BVar1 = FUN_c0801898(puVar4,0), BVar1 != 0 &&
         (BVar1 = FUN_c0801898(puVar4 + 1,2), BVar1 != 0))) {
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 4;
    if (2 < uVar5) {
LAB_c080221c:
      iVar6 = 0;
      if ((uVar3 & 0x10) == 0) {
        iVar2 = FUN_c080164c((uint)local_38,(uint)local_30,(uint)local_28,0x100,&local_3c);
        if (iVar2 == 0x10) {
          uVar3 = uVar3 | 0x10;
        }
        else {
          uVar5 = FUN_c080164c((uint)local_36,(uint)local_2e,(uint)local_26,0x100,&local_40);
          uVar3 = uVar5 | uVar3;
          iVar6 = local_40;
        }
      }
      if ((uVar3 & 1) != 0) {
        *param_1 = 0xfff - iVar6;
        *param_2 = 0xfff - local_3c;
      }
      return uVar3;
    }
  }
  uVar3 = 0x12;
  goto LAB_c080221c;
}



/* c08022c8 FUN_c08022c8 */

/* Boundary evidence: original MIPS .pdata c08022c8..c0802407. Semantic name remains unreviewed. */

void FUN_c08022c8(uint *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  
  if ((DAT_c0805160 == 1) || (DAT_c0805188 == 1)) {
    InterruptStopTimer(DAT_c0805180);
    InterruptDone(DAT_c0805180);
  }
  uVar1 = READ_REGISTER_ULONG(DAT_c0805164 + 8);
  if (((uVar1 & 8) != 0) || (DAT_c0805168 == 0)) {
    uVar1 = READ_REGISTER_ULONG(DAT_c0805164 + 4);
    if ((uVar1 & 8) != 0) {
      *param_1 = 1;
      DAT_c0805160 = 0;
      goto LAB_c08023a4;
    }
  }
  uVar1 = FUN_c0802198(param_2,param_3);
  *param_1 = uVar1;
  DAT_c0805160 = 1;
LAB_c08023a4:
  InterruptDone(DAT_c080517c);
  InterruptDone(DAT_c0805184);
  if ((DAT_c0805160 == 1) || (DAT_c0805188 == 1)) {
    InterruptStartTimer(DAT_c0805180,20000);
  }
  return;
}



/* c0802408 FUN_c0802408 */

/* Boundary evidence: original MIPS .pdata c0802408..c0802473. Semantic name remains unreviewed. */

undefined4 FUN_c0802408(HMODULE param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_2 == 0) {
    FUN_c0801454();
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    iVar1 = TouchCreateEvent();
    if (1 < iVar1) {
      FUN_c0801454();
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* c0802474 FUN_c0802474 */

/* Boundary evidence: original MIPS .pdata c0802474..c080248f. Semantic name remains unreviewed. */

void FUN_c0802474(HMODULE param_1,int param_2)

{
  FUN_c0802408(param_1,param_2);
  return;
}



/* c0802490 FUN_c0802490 */

/* Boundary evidence: original MIPS .pdata c0802490..c0802883. Semantic name remains unreviewed. */

void FUN_c0802490(void)

{
  code *pcVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30 [2];
  
  uVar6 = DAT_c0805a5c * 4;
  uVar7 = DAT_c0805a3c * 4;
  uVar5 = 0;
  local_40 = 0;
joined_r0xc08024e8:
  do {
    while( true ) {
      if (DAT_c08059e4 != 0) {
                    /* WARNING: Subroutine does not return */
        ExitThread(1);
      }
      WaitForSingleObject(DAT_c0805a54,DAT_c08050bc);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
      if (uVar5 == 0) {
        local_40 = local_40 & 0xfffffff7;
      }
      else {
        local_40 = local_40 | 8;
      }
      FUN_c08022c8(&local_40,(int *)local_30,(int *)&local_34);
      pcVar1 = DAT_c0805a2c;
      if ((local_40 & 0x10) == 0) break;
LAB_c0802570:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
    }
    if ((local_40 & 1) != 0) {
      if (uVar5 == 0) {
        local_40 = local_40 & 0xfffffff7;
      }
      else {
        local_40 = local_40 | 8;
      }
      uVar5 = local_40 & 2;
    }
    if (DAT_c0805a30 != 0) {
      if ((local_40 & 1) == 0) goto LAB_c0802570;
      if (DAT_c0805a34 != 0) {
        EventModify(DAT_c0805a34,3);
      }
      if ((local_40 & 10) == 2) {
        DAT_c0805a30 = 2;
        DAT_c08059cc = 1;
        DAT_c08059d0 = 0;
        DAT_c08059d4 = 0;
      }
      if ((DAT_c0805a30 == 2) && (DAT_c08059d4 == 0)) {
        if ((local_40 & 2) == 0) {
          if (DAT_c08059d0 < 0x19) {
            DAT_c0805a30 = 1;
            goto LAB_c0802714;
          }
LAB_c08026b0:
          DAT_c08059d4 = 1;
        }
        else {
          DAT_c08059d0 = DAT_c08059d0 + 1;
          DAT_c08059c4 = local_30[0];
          DAT_c08059c0 = local_34;
          if (DAT_c08059cc != 0) {
            DAT_c08059c8 = local_30[0];
            DAT_c08059d8 = local_34;
            DAT_c08059b4 = GetTickCount();
            DAT_c08059cc = 0;
          }
          iVar4 = DAT_c08059c0 - DAT_c08059d8;
          iVar3 = DAT_c08059c4 - DAT_c08059c8;
          DVar2 = GetTickCount();
          if (0x5dc < DVar2 - DAT_c08059b4) goto LAB_c08026b0;
          if (iVar3 < 0) {
            iVar3 = -iVar3;
          }
          if (iVar3 < 0x15) {
            if (iVar4 < 0) {
              iVar4 = -iVar4;
            }
            if (iVar4 < 0x15) goto LAB_c0802714;
          }
          DAT_c08059cc = 1;
LAB_c0802714:
          if (DAT_c08059d4 == 0) goto LAB_c080274c;
        }
        DAT_c0805a30 = 3;
        DAT_c0805a64 = DAT_c08059c4;
        DAT_c0805a60 = DAT_c08059c0;
        EventModify(DAT_c0805a58,3);
      }
LAB_c080274c:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
      goto joined_r0xc08024e8;
    }
    if (DAT_c0805a2c == (code *)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
    }
    else {
      if ((local_40 & 4) == 0) {
        TouchPanelCalibrateAPoint(local_30[0],local_34,(int *)&local_3c,(int *)&local_38);
        local_40 = local_40 | 4;
      }
      else {
        local_3c = local_30[0];
        local_38 = local_34;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
      if ((int)local_3c < 0) {
        local_3c = 0;
      }
      else if ((uVar6 != 0) && (uVar6 <= local_3c)) {
        local_3c = uVar6 - 4;
      }
      if ((int)local_38 < 0) {
        local_38 = 0;
      }
      else if ((uVar7 != 0) && (uVar7 <= local_38)) {
        local_38 = uVar7 - 4;
      }
      (*pcVar1)(local_40);
    }
  } while( true );
}



/* c0802884 FUN_c0802884 */

/* Boundary evidence: original MIPS .pdata c0802884..c0802993. Semantic name remains unreviewed. */

void FUN_c0802884(LPBYTE param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  DWORD local_28;
  HKEY local_24;
  DWORD aDStack_20 [2];
  
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"\\Drivers\\BuiltIn\\Touch",0,0,&local_24);
  if (LVar1 == 0) {
    local_28 = 4;
    LVar1 = RegQueryValueExW(local_24,L"Priority256",(LPDWORD)0x0,aDStack_20,param_1,&local_28);
    if (LVar1 != 0) {
      param_1[0] = 'm';
      param_1[1] = '\0';
      param_1[2] = '\0';
      param_1[3] = '\0';
    }
    local_28 = 4;
    LVar1 = RegQueryValueExW(local_24,L"HighPriority256",(LPDWORD)0x0,aDStack_20,param_2,&local_28);
    if (LVar1 != 0) {
      param_2[0] = 'm';
      param_2[1] = '\0';
      param_2[2] = '\0';
      param_2[3] = '\0';
    }
    RegCloseKey(local_24);
  }
  else {
    param_1[0] = 'm';
    param_1[1] = '\0';
    param_1[2] = '\0';
    param_1[3] = '\0';
    param_2[0] = 'm';
    param_2[1] = '\0';
    param_2[2] = '\0';
    param_2[3] = '\0';
  }
  return;
}



/* c0802994 TouchPanelGetDeviceCaps */

/* Boundary evidence: original MIPS .pdata c0802994..c0802a27. Semantic name remains unreviewed. */

undefined4 TouchPanelGetDeviceCaps(int param_1,int *param_2)

{
  undefined4 uVar1;
  
                    /* 0x2994  13  TouchPanelGetDeviceCaps */
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  if ((param_2 != (int *)0x0) && (uVar1 = FUN_c08015a4(param_1,param_2), param_1 == 2)) {
    DAT_c0805a5c = param_2[1];
    DAT_c0805a3c = param_2[2];
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  return uVar1;
}



/* c0802a28 TouchPanelSetMode */

/* Boundary evidence: original MIPS .pdata c0802a28..c0802aff. Semantic name remains unreviewed. */

undefined4 TouchPanelSetMode(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x2a28  18  TouchPanelSetMode */
  uVar1 = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  if (param_1 == 2) {
    DAT_c08059dc = 1;
    CeSetThreadPriority(DAT_c08059e0,DAT_c08059b8);
  }
  else if (param_1 == 4) {
    CeSetThreadPriority(DAT_c08059e0,DAT_c08059bc);
    DAT_c08059dc = 0;
  }
  else {
    uVar1 = FUN_c080162c(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  return uVar1;
}



/* c0802b00 TouchPanelPowerHandler */

/* Boundary evidence: original MIPS .pdata c0802b00..c0802b1b. Semantic name remains unreviewed. */

void TouchPanelPowerHandler(int param_1)

{
                    /* 0x2b00  14  TouchPanelPowerHandler */
  FUN_c080214c(param_1);
  return;
}



/* c0802b1c TouchPanelEnable */

/* Boundary evidence: original MIPS .pdata c0802b1c..c0802d6f. Semantic name remains unreviewed. */

int TouchPanelEnable(int param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2b1c  12  TouchPanelEnable */
  DAT_c0805a54 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if ((DAT_c0805a54 != (HANDLE)0x0) &&
     (DAT_c0805a58 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0),
     DAT_c0805a58 != (HANDLE)0x0)) {
    FUN_c0801808();
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
    DAT_c0805a30 = 0;
    DAT_c0805a2c = 0;
    DAT_c0805a38 = 0;
    TouchPanelSetCalibration(0,0,0,(int *)0x0,(int *)0x0);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  InterruptDone(DAT_c080517c);
  InterruptDisable(DAT_c080517c);
  if (DAT_c0805180 != 0) {
    InterruptDone();
    InterruptDisable(DAT_c0805180);
  }
  DAT_c0805a2c = param_1;
  if (DAT_c08059b0 != 0) {
    DAT_c0805a2c = DAT_c08059b0;
  }
  DAT_c0805a34 = 0;
  DAT_c0805a68 = param_1;
  iVar1 = FUN_c0801eb8();
  if ((iVar1 != 0) && (iVar2 = InterruptInitialize(DAT_c080517c,DAT_c0805a54,0,0), iVar2 == 0)) {
    FUN_c0801808();
    iVar1 = 0;
  }
  if (DAT_c0805180 != 0) {
    if (iVar1 == 0) goto LAB_c0802d40;
    iVar2 = InterruptInitialize(DAT_c0805180,DAT_c0805a54,0,0);
    if (iVar2 == 0) {
      InterruptDisable(DAT_c080517c);
      FUN_c0801808();
      iVar1 = 0;
    }
  }
  if (iVar1 != 0) {
    DAT_c08059e4 = 0;
    DAT_c08059e0 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0802490,(LPVOID)0x0,0,(LPDWORD)0x0
                               );
    if (DAT_c08059e0 == (HANDLE)0x0) {
      InterruptDisable(DAT_c080517c);
      if (DAT_c0805180 != 0) {
        InterruptDisable();
      }
      FUN_c0801808();
      iVar1 = 0;
    }
    else {
      FUN_c0802884((LPBYTE)&DAT_c08059bc,(LPBYTE)&DAT_c08059b8);
      CeSetThreadPriority(DAT_c08059e0,DAT_c08059bc);
    }
  }
LAB_c0802d40:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  return iVar1;
}



/* c0802d70 TouchPanelDisable */

/* Boundary evidence: original MIPS .pdata c0802d70..c0802ecb. Semantic name remains unreviewed. */

void TouchPanelDisable(void)

{
  DWORD DVar1;
  int iVar2;
  
                    /* 0x2d70  11  TouchPanelDisable */
  if (DAT_c08059e0 != (HANDLE)0x0) {
    DAT_c08059e4 = 1;
    iVar2 = 0;
    do {
      EventModify(DAT_c0805a54,3);
      DVar1 = WaitForSingleObject(DAT_c08059e0,100);
      if (DVar1 == 0) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    CloseHandle(DAT_c08059e0);
    DAT_c08059e0 = (HANDLE)0x0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  FUN_c0801808();
  InterruptDone(DAT_c080517c);
  InterruptDisable(DAT_c080517c);
  if (DAT_c0805180 != 0) {
    InterruptDone();
    InterruptDisable(DAT_c0805180);
  }
  DAT_c08059e0 = (HANDLE)0x0;
  DAT_c0805a34 = 0;
  if (DAT_c0805a54 != 0) {
    CloseHandle((HANDLE)DAT_c0805a54);
    DAT_c0805a54 = 0;
  }
  if (DAT_c0805a58 != 0) {
    CloseHandle((HANDLE)DAT_c0805a58);
    DAT_c0805a58 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  return;
}



/* c0802ecc TouchPanelReadCalibrationPoint */

/* Boundary evidence: original MIPS .pdata c0802ecc..c08030ef. Semantic name remains unreviewed. */

bool TouchPanelReadCalibrationPoint(undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  LSTATUS LVar2;
  code *pcVar3;
  HANDLE hObject;
  HKEY local_240;
  DWORD local_23c;
  DWORD local_238 [2];
  WCHAR aWStack_230 [259];
  undefined2 local_2a;
  uint local_28;
  
                    /* 0x2ecc  16  TouchPanelReadCalibrationPoint */
  local_28 = DAT_c0805140;
  hObject = (HANDLE)0x0;
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    hObject = (HANDLE)0x57;
    pcVar3 = SetLastError_exref;
  }
  else {
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"System\\GWE",0,0,&local_240);
    if (LVar2 == 0) {
      local_23c = 0x208;
      LVar2 = RegQueryValueExW(local_240,L"ActivityEvent",(LPDWORD)0x0,local_238,(LPBYTE)aWStack_230
                               ,&local_23c);
      local_2a = 0;
      if ((LVar2 == 0) && (local_238[0] == 1)) {
        hObject = OpenEventW(0x1f0003,0,aWStack_230);
      }
      RegCloseKey(local_240);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
    if (DAT_c0805a30 == 0) {
      DAT_c0805a30 = 1;
      DAT_c0805a34 = hObject;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
      WaitForSingleObject(DAT_c0805a58,0xffffffff);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
      *param_1 = DAT_c0805a64;
      *param_2 = DAT_c0805a60;
      bVar1 = DAT_c0805a30 == 3;
      DAT_c0805a30 = 0;
      DAT_c0805a34 = (HANDLE)0x0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
      CloseHandle(hObject);
      FUN_c08048d4(local_28);
      return bVar1;
    }
    SetLastError(0x46b);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
    pcVar3 = CloseHandle_exref;
    if (hObject == (HANDLE)0x0) goto LAB_c08030b8;
  }
  (*pcVar3)(hObject);
LAB_c08030b8:
  FUN_c08048d4(local_28);
  return false;
}



/* c08030f0 TouchPanelReadCalibrationAbort */

/* Boundary evidence: original MIPS .pdata c08030f0..c0803157. Semantic name remains unreviewed. */

void TouchPanelReadCalibrationAbort(void)

{
                    /* 0x30f0  15  TouchPanelReadCalibrationAbort */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  if ((DAT_c0805a30 != 3) && (DAT_c0805a30 != 0)) {
    DAT_c0805a30 = 4;
    EventModify(DAT_c0805a58,3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0805a40);
  return;
}



/* c0803158 FUN_c0803158 */

/* Boundary evidence: original MIPS .pdata c0803158..c08032ab. Semantic name remains unreviewed. */

void FUN_c0803158(uint *param_1,undefined4 *param_2)

{
  uint auStack_28 [4];
  uint local_18;
  
  local_18 = DAT_c0805140;
  FUN_c0803f94((uint *)*param_2,(uint *)param_2[4],auStack_28);
  FUN_c0803f94((uint *)param_2[8],auStack_28,param_1);
  FUN_c0803f94((uint *)param_2[3],(uint *)param_2[7],auStack_28);
  FUN_c0803f94((uint *)param_2[2],auStack_28,auStack_28);
  FUN_c0803d2c(param_1,auStack_28,param_1);
  FUN_c0803f94((uint *)param_2[1],(uint *)param_2[5],auStack_28);
  FUN_c0803f94((uint *)param_2[6],auStack_28,auStack_28);
  FUN_c0803d2c(param_1,auStack_28,param_1);
  FUN_c0803f94((uint *)param_2[2],(uint *)param_2[4],auStack_28);
  FUN_c0803f94((uint *)param_2[6],auStack_28,auStack_28);
  FUN_c0803e1c(param_1,auStack_28,param_1);
  FUN_c0803f94((uint *)param_2[1],(uint *)param_2[3],auStack_28);
  FUN_c0803f94((uint *)param_2[8],auStack_28,auStack_28);
  FUN_c0803e1c(param_1,auStack_28,param_1);
  FUN_c0803f94((uint *)param_2[5],(uint *)param_2[7],auStack_28);
  FUN_c0803f94((uint *)*param_2,auStack_28,auStack_28);
  FUN_c0803e1c(param_1,auStack_28,param_1);
  FUN_c08048d4(local_18);
  return;
}



/* c08032ac TouchPanelCalibrateAPoint */

void TouchPanelCalibrateAPoint(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x32ac  10  TouchPanelCalibrateAPoint */
  if (DAT_c0805a04 == 0) {
    *param_3 = param_1;
    *param_4 = param_2;
  }
  else {
    iVar1 = (DAT_c08059e8 * param_1 + DAT_c08059ec * param_2 + DAT_c08059f0) * 4;
    iVar3 = iVar1 / DAT_c0805a00;
    if (DAT_c0805a00 == 0) {
      trap(0x1c00);
    }
    if ((DAT_c0805a00 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    iVar2 = (DAT_c08059f4 * param_1 + DAT_c08059f8 * param_2 + DAT_c08059fc) * 4;
    iVar1 = iVar2 / DAT_c0805a00;
    if (DAT_c0805a00 == 0) {
      trap(0x1c00);
    }
    if ((DAT_c0805a00 == -1) && (iVar2 == -0x80000000)) {
      trap(0x1800);
    }
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    *param_3 = iVar3;
    *param_4 = iVar1;
  }
  return;
}



/* c08033b4 FUN_c08033b4 */

/* Boundary evidence: original MIPS .pdata c08033b4..c080355f. Semantic name remains unreviewed. */

bool FUN_c08033b4(int param_1,int param_2,int param_3,int *param_4,int param_5)

{
  LSTATUS LVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  HKEY local_30;
  DWORD local_2c;
  int local_28;
  DWORD DStack_24;
  
  local_28 = 5;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"HARDWARE\\DEVICEMAP\\TOUCH",0,0,&local_30);
  if (LVar1 == 0) {
    local_2c = 4;
    RegQueryValueExW(local_30,L"MaxCalError",(LPDWORD)0x0,&DStack_24,(LPBYTE)&local_28,&local_2c);
    RegCloseKey(local_30);
  }
  uVar5 = 0;
  if (0 < param_1) {
    iVar8 = param_5 - (int)param_4;
    iVar7 = param_2 - (int)param_4;
    iVar6 = param_3 - (int)param_4;
    do {
      TouchPanelCalibrateAPoint
                (*param_4,*(int *)(iVar8 + (int)param_4),(int *)&local_30,(int *)&local_2c);
      if ((int)local_30 < 0) {
        local_30 = (HKEY)((int)&local_30->unused + 3);
      }
      local_30 = (HKEY)((int)local_30 >> 2);
      if ((int)local_2c < 0) {
        local_2c = local_2c + 3;
      }
      local_2c = (int)local_2c >> 2;
      iVar3 = (int)local_30 - *(int *)(iVar7 + (int)param_4);
      iVar2 = local_2c - *(int *)(iVar6 + (int)param_4);
      uVar4 = iVar2 * iVar2 + iVar3 * iVar3;
      if (uVar5 < uVar4) {
        uVar5 = uVar4;
      }
      param_4 = param_4 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return uVar5 < (uint)(local_28 * local_28);
}



/* c0803560 TouchPanelSetCalibration */

/* Boundary evidence: original MIPS .pdata c0803560..c0803b9f. Semantic name remains unreviewed. */

bool TouchPanelSetCalibration(int param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint *local_1e8;
  uint *local_1e4;
  uint *local_1e0;
  uint *local_1dc;
  uint *local_1d8;
  uint *local_1d4;
  uint *local_1d0;
  uint *local_1cc;
  uint *local_1c8;
  int local_1c4;
  uint auStack_1c0 [4];
  uint auStack_1b0 [4];
  uint auStack_1a0 [4];
  uint auStack_190 [4];
  uint auStack_180 [4];
  uint uStack_170;
  int local_16c;
  uint auStack_160 [4];
  uint auStack_150 [4];
  uint auStack_140 [4];
  uint auStack_130 [4];
  uint auStack_120 [4];
  uint auStack_110 [4];
  uint uStack_100;
  undefined4 local_fc;
  uint auStack_f0 [4];
  uint uStack_e0;
  undefined4 local_dc;
  uint auStack_d0 [4];
  uint auStack_c0 [4];
  uint auStack_b0 [4];
  uint uStack_a0;
  undefined4 local_9c;
  uint auStack_90 [4];
  uint uStack_80;
  undefined4 local_7c;
  uint uStack_70;
  undefined4 local_6c;
  uint auStack_60 [4];
  uint uStack_50;
  undefined4 local_4c;
  undefined4 auStack_40 [4];
  uint local_30;
  
                    /* 0x3560  17  TouchPanelSetCalibration */
  local_30 = DAT_c0805140;
  local_1c4 = param_2;
  if (param_1 == 0) {
    DAT_c0805a04 = 0;
    FUN_c08048d4(DAT_c0805140);
    bVar1 = true;
  }
  else {
    FUN_c0803ba0(auStack_f0,0);
    FUN_c0803ba0(auStack_1b0,0);
    FUN_c0803ba0(auStack_190,0);
    FUN_c0803ba0(auStack_110,0);
    FUN_c0803ba0(auStack_1a0,0);
    FUN_c0803ba0(auStack_40,param_1);
    FUN_c0803ba0(auStack_d0,0);
    FUN_c0803ba0(auStack_130,0);
    FUN_c0803ba0(auStack_c0,0);
    FUN_c0803ba0(auStack_150,0);
    FUN_c0803ba0(auStack_140,0);
    FUN_c0803ba0(auStack_120,0);
    if (0 < param_1) {
      iVar5 = param_2 - (int)param_5;
      piVar3 = param_5;
      iVar4 = param_1;
      do {
        FUN_c0803ba0(auStack_160,*(int *)(((int)param_4 - (int)param_5) + (int)piVar3));
        FUN_c0803ba0(auStack_180,*piVar3);
        FUN_c0803ba0(auStack_b0,*(int *)(iVar5 + (int)piVar3));
        FUN_c0803ba0(auStack_60,*(int *)((param_3 - (int)param_5) + (int)piVar3));
        FUN_c0803f94(auStack_160,auStack_160,auStack_1c0);
        FUN_c0803d2c(auStack_f0,auStack_1c0,auStack_f0);
        FUN_c0803f94(auStack_160,auStack_180,auStack_1c0);
        FUN_c0803d2c(auStack_1b0,auStack_1c0,auStack_1b0);
        FUN_c0803d2c(auStack_190,auStack_160,auStack_190);
        FUN_c0803f94(auStack_180,auStack_180,auStack_1c0);
        FUN_c0803d2c(auStack_110,auStack_1c0,auStack_110);
        FUN_c0803d2c(auStack_1a0,auStack_180,auStack_1a0);
        FUN_c0803f94(auStack_160,auStack_b0,auStack_1c0);
        FUN_c0803d2c(auStack_d0,auStack_1c0,auStack_d0);
        FUN_c0803f94(auStack_180,auStack_b0,auStack_1c0);
        FUN_c0803d2c(auStack_130,auStack_1c0,auStack_130);
        FUN_c0803d2c(auStack_c0,auStack_b0,auStack_c0);
        FUN_c0803f94(auStack_160,auStack_60,auStack_1c0);
        FUN_c0803d2c(auStack_150,auStack_1c0,auStack_150);
        FUN_c0803f94(auStack_180,auStack_60,auStack_1c0);
        FUN_c0803d2c(auStack_140,auStack_1c0,auStack_140);
        FUN_c0803d2c(auStack_120,auStack_60,auStack_120);
        iVar4 = iVar4 + -1;
        piVar3 = piVar3 + 1;
        param_2 = local_1c4;
      } while (iVar4 != 0);
    }
    local_1e8 = auStack_f0;
    local_1dc = auStack_1b0;
    local_1d0 = auStack_190;
    local_1e4 = auStack_1b0;
    local_1d8 = auStack_110;
    local_1cc = auStack_1a0;
    local_1e0 = auStack_190;
    local_1d4 = auStack_1a0;
    local_1c8 = auStack_40;
    FUN_c0803158(&uStack_170,&local_1e8);
    local_1e8 = auStack_d0;
    local_1dc = auStack_130;
    local_1d0 = auStack_c0;
    FUN_c0803158(&uStack_50,&local_1e8);
    local_1e8 = auStack_f0;
    local_1dc = auStack_1b0;
    local_1d0 = auStack_190;
    local_1e4 = auStack_d0;
    local_1d8 = auStack_130;
    local_1cc = auStack_c0;
    FUN_c0803158(&uStack_70,&local_1e8);
    local_1e4 = auStack_1b0;
    local_1d8 = auStack_110;
    local_1cc = auStack_1a0;
    local_1e0 = auStack_d0;
    local_1d4 = auStack_130;
    local_1c8 = auStack_c0;
    FUN_c0803158(&uStack_100,&local_1e8);
    local_1e0 = auStack_190;
    local_1d4 = auStack_1a0;
    local_1c8 = auStack_40;
    local_1e8 = auStack_150;
    local_1dc = auStack_140;
    local_1d0 = auStack_120;
    FUN_c0803158(&uStack_a0,&local_1e8);
    local_1e8 = auStack_f0;
    local_1dc = auStack_1b0;
    local_1d0 = auStack_190;
    local_1e4 = auStack_150;
    local_1d8 = auStack_140;
    local_1cc = auStack_120;
    FUN_c0803158(&uStack_80,&local_1e8);
    local_1e4 = auStack_1b0;
    local_1d8 = auStack_110;
    local_1cc = auStack_1a0;
    local_1e0 = auStack_150;
    local_1d4 = auStack_140;
    local_1c8 = auStack_120;
    FUN_c0803158(&uStack_e0,&local_1e8);
    bVar1 = FUN_c0803be8((int *)&uStack_170);
    uVar2 = 0xfffffffe;
    if (CONCAT31(extraout_var,bVar1) == 0) {
      uVar2 = 2;
    }
    FUN_c08042ec((int *)&uStack_170,uVar2,auStack_90);
    FUN_c0803d2c(&uStack_100,auStack_90,&uStack_100);
    FUN_c0803d2c(&uStack_e0,auStack_90,&uStack_e0);
    iVar5 = FUN_c0804474((int)&uStack_50);
    iVar4 = 0;
    if (0 < iVar5 + -0xf) {
      iVar4 = iVar5 + -0xf;
    }
    iVar5 = FUN_c0804474((int)&uStack_70);
    if (iVar4 < iVar5 + -0xf) {
      iVar4 = iVar5 + -0xf;
    }
    iVar5 = FUN_c0804474((int)&uStack_a0);
    if (iVar4 < iVar5 + -0xf) {
      iVar4 = iVar5 + -0xf;
    }
    iVar5 = FUN_c0804474((int)&uStack_80);
    if (iVar4 < iVar5 + -0xf) {
      iVar4 = iVar5 + -0xf;
    }
    iVar5 = FUN_c0804474((int)&uStack_100);
    if (iVar4 < iVar5 + -0x1b) {
      iVar4 = iVar5 + -0x1b;
    }
    iVar5 = FUN_c0804474((int)&uStack_e0);
    if (iVar4 < iVar5 + -0x1b) {
      iVar4 = iVar5 + -0x1b;
    }
    iVar5 = FUN_c0804474((int)&uStack_170);
    if (iVar4 < iVar5 + -0x1f) {
      iVar4 = iVar5 + -0x1f;
    }
    if (iVar4 != 0) {
      FUN_c0804190(&uStack_50,iVar4);
      FUN_c0804190(&uStack_a0,iVar4);
      FUN_c0804190(&uStack_70,iVar4);
      FUN_c0804190(&uStack_80,iVar4);
      FUN_c0804190(&uStack_100,iVar4);
      FUN_c0804190(&uStack_e0,iVar4);
      FUN_c0804190(&uStack_170,iVar4);
    }
    DAT_c08059e8 = local_4c;
    DAT_c08059ec = local_6c;
    DAT_c08059f0 = local_fc;
    DAT_c08059f4 = local_9c;
    DAT_c08059f8 = local_7c;
    DAT_c08059fc = local_dc;
    DAT_c0805a00 = local_16c;
    if (local_16c == 0) {
      DAT_c0805a00 = 1;
    }
    DAT_c0805a04 = (uint)(local_16c != 0);
    bVar1 = FUN_c08033b4(param_1,param_2,param_3,param_4,(int)param_5);
    FUN_c08048d4(local_30);
  }
  return bVar1;
}



/* c0803ba0 FUN_c0803ba0 */

undefined4 * FUN_c0803ba0(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_2 < 0) {
    param_1[1] = -param_2;
    *param_1 = 1;
  }
  else {
    param_1[1] = param_2;
    *param_1 = 0;
  }
  puVar1 = param_1 + 2;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 4);
  return param_1;
}



/* c0803be8 FUN_c0803be8 */

bool FUN_c0803be8(int *param_1)

{
  return *param_1 != 0;
}



/* c0803c00 FUN_c0803c00 */

undefined4 FUN_c0803c00(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  iVar3 = 2;
  puVar2 = (uint *)(param_2 + 0xc);
  while( true ) {
    uVar1 = *(uint *)((param_1 - param_2) + (int)puVar2);
    if (*puVar2 < uVar1) {
      return 1;
    }
    if (uVar1 < *puVar2) break;
    iVar3 = iVar3 + -1;
    puVar2 = puVar2 + -1;
    if (iVar3 < 0) {
      return 0;
    }
  }
  return 0;
}



/* c0803c50 FUN_c0803c50 */

int FUN_c0803c50(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = 0;
  iVar6 = param_1 - (int)param_2;
  iVar1 = param_3 - (int)param_2;
  iVar5 = 3;
  do {
    param_2 = param_2 + 1;
    uVar3 = *(uint *)(iVar6 + (int)param_2);
    uVar4 = *param_2 + uVar3 + iVar2;
    *(uint *)(iVar1 + (int)param_2) = uVar4;
    if (iVar2 == 0) {
      if (uVar4 < uVar3) goto LAB_c0803cb4;
LAB_c0803c90:
      iVar2 = 0;
    }
    else {
      if (uVar3 < uVar4) goto LAB_c0803c90;
LAB_c0803cb4:
      iVar2 = 1;
    }
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return param_3;
    }
  } while( true );
}



/* c0803cbc FUN_c0803cbc */

int FUN_c0803cbc(int param_1,uint *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = 1;
  iVar2 = param_1 - (int)param_2;
  iVar1 = param_3 - (int)param_2;
  iVar6 = 3;
  do {
    param_2 = param_2 + 1;
    uVar4 = *(uint *)(iVar2 + (int)param_2);
    uVar5 = ~*param_2 + uVar4 + iVar3;
    *(uint *)(iVar1 + (int)param_2) = uVar5;
    if (iVar3 == 0) {
      if (uVar5 < uVar4) goto LAB_c0803d24;
LAB_c0803d00:
      iVar3 = 0;
    }
    else {
      if (uVar4 < uVar5) goto LAB_c0803d00;
LAB_c0803d24:
      iVar3 = 1;
    }
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return param_3;
    }
  } while( true );
}



/* c0803d2c FUN_c0803d2c */

/* Boundary evidence: original MIPS .pdata c0803d2c..c0803e1b. Semantic name remains unreviewed. */

uint * FUN_c0803d2c(uint *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)(*param_1 != 0);
  if (uVar3 == (*param_2 != 0)) {
    FUN_c0803c50((int)param_1,(int *)param_2,(int)param_3);
  }
  else {
    iVar1 = FUN_c0803c00((int)param_1,(int)param_2);
    if (iVar1 == 0) {
      FUN_c0803cbc((int)param_2,param_1,(int)param_3);
      if (uVar3 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      FUN_c0803cbc((int)param_1,param_2,(int)param_3);
    }
  }
  iVar1 = 0;
  puVar2 = param_3;
  do {
    puVar2 = puVar2 + 1;
    if (*puVar2 != 0) {
      *param_3 = uVar3;
      return param_3;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  *param_3 = 0;
  return param_3;
}



/* c0803e1c FUN_c0803e1c */

/* Boundary evidence: original MIPS .pdata c0803e1c..c0803f0b. Semantic name remains unreviewed. */

uint * FUN_c0803e1c(uint *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)(*param_1 != 0);
  if (uVar3 == (*param_2 != 0)) {
    iVar1 = FUN_c0803c00((int)param_1,(int)param_2);
    if (iVar1 == 0) {
      FUN_c0803cbc((int)param_2,param_1,(int)param_3);
      if (uVar3 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      FUN_c0803cbc((int)param_1,param_2,(int)param_3);
    }
  }
  else {
    FUN_c0803c50((int)param_1,(int *)param_2,(int)param_3);
  }
  iVar1 = 0;
  puVar2 = param_3;
  do {
    puVar2 = puVar2 + 1;
    if (*puVar2 != 0) {
      *param_3 = uVar3;
      return param_3;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  *param_3 = 0;
  return param_3;
}



/* c0803f0c FUN_c0803f0c */

undefined4 * FUN_c0803f0c(uint param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (param_2 & 0xffff) * (param_1 & 0xffff);
  uVar3 = (param_2 >> 0x10) * (param_1 & 0xffff) + (param_2 & 0xffff) * (param_1 >> 0x10);
  uVar2 = uVar3 * 0x10000 + uVar1;
  param_3[1] = uVar2;
  param_3[2] = (uVar3 >> 0x10) + (uint)(uVar2 < uVar1) + (param_2 >> 0x10) * (param_1 >> 0x10);
  param_3[3] = 0;
  *param_3 = 0;
  return param_3;
}



/* c0803f94 FUN_c0803f94 */

/* Boundary evidence: original MIPS .pdata c0803f94..c080413b. Semantic name remains unreviewed. */

uint * FUN_c0803f94(uint *param_1,uint *param_2,uint *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  int local_60;
  uint local_5c;
  undefined4 local_58 [5];
  undefined4 uStack_44;
  undefined4 auStack_40 [4];
  uint local_30;
  
  local_30 = DAT_c0805140;
  puVar1 = local_58 + 4;
  local_58[3] = 0;
  local_58[2] = 0;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != auStack_40);
  puVar4 = param_3 + 1;
  iVar3 = 0;
  iVar6 = (int)param_2 - (int)param_3;
  puVar5 = puVar4;
  do {
    puVar1 = local_58;
    local_5c = 0;
    local_60 = 0;
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    } while (puVar1 != local_58 + 2);
    if (-1 < iVar3) {
      puVar8 = (uint *)(iVar6 + (int)puVar5);
      iVar6 = iVar3 + 1;
      puVar7 = param_1;
      do {
        puVar7 = puVar7 + 1;
        FUN_c0803f0c(*puVar7,*puVar8,auStack_40);
        FUN_c0803c50((int)auStack_40,&local_60,(int)&local_60);
        puVar8 = puVar8 + -1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar6 = (int)param_2 - (int)param_3;
    }
    FUN_c0803c50((int)(local_58 + 2),&local_60,(int)&local_60);
    puVar2 = local_58 + 3;
    puVar1 = local_58;
    do {
      *puVar2 = *puVar1;
      puVar2 = puVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (puVar2 != &uStack_44);
    iVar3 = iVar3 + 1;
    *puVar5 = local_5c;
    puVar5 = puVar5 + 1;
  } while (iVar3 < 3);
  iVar3 = 0;
  do {
    if (*puVar4 != 0) {
      *param_3 = (uint)(*param_1 != *param_2);
      goto LAB_c0804100;
    }
    iVar3 = iVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar3 < 3);
  *param_3 = 0;
LAB_c0804100:
  FUN_c08048d4(local_30);
  return param_3;
}



/* c080413c FUN_c080413c */

undefined4 FUN_c080413c(uint *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    iVar3 = 1;
    iVar4 = 3;
    do {
      param_1 = param_1 + 1;
      uVar2 = *param_1;
      *param_1 = ~uVar2 + iVar3;
      if (~uVar2 + iVar3 != 0) {
        iVar3 = 0;
      }
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* c0804190 FUN_c0804190 */

/* Boundary evidence: original MIPS .pdata c0804190..c08042eb. Semantic name remains unreviewed. */

void FUN_c0804190(uint *param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  
  uVar1 = FUN_c080413c(param_1);
  iVar6 = param_2;
  if (param_2 < 0) {
    iVar6 = param_2 + 0x1f;
  }
  iVar6 = iVar6 >> 5;
  if (iVar6 < 3) {
    uVar8 = param_2 % 0x20;
    puVar7 = param_1 + 1;
    uVar3 = 0x20 - uVar8;
    puVar2 = param_1 + iVar6 + 1;
    *puVar7 = *puVar2 >> (uVar8 & 0x1f);
    iVar4 = 0;
    if (iVar6 < 2) {
      iVar6 = 2 - iVar6;
      iVar5 = iVar4;
      do {
        puVar2 = puVar2 + 1;
        if ((int)uVar3 < 0x20) {
          *puVar7 = *puVar2 << (uVar3 & 0x1f) | *puVar7;
        }
        iVar4 = iVar5 + 1;
        puVar7 = param_1 + iVar5 + 2;
        iVar6 = iVar6 + -1;
        *puVar7 = *puVar2 >> (uVar8 & 0x1f);
        iVar5 = iVar4;
      } while (iVar6 != 0);
    }
    if ((int)uVar3 < 0x20) {
      param_1[iVar4 + 1] = uVar1 << (uVar3 & 0x1f) | param_1[iVar4 + 1];
    }
    if (iVar4 + 1 < 3) {
      iVar6 = 3 - (iVar4 + 1);
      puVar2 = param_1 + iVar4 + 2;
      if (iVar6 != 0) {
        puVar7 = puVar2 + iVar6;
        do {
          *puVar2 = uVar1;
          puVar2 = puVar2 + 1;
        } while (puVar2 != puVar7);
      }
    }
  }
  else {
    puVar2 = param_1 + 1;
    do {
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    } while (puVar2 != param_1 + 4);
  }
  return;
}



/* c08042ec FUN_c08042ec */

/* Boundary evidence: original MIPS .pdata c08042ec..c0804473. Semantic name remains unreviewed. */

int FUN_c08042ec(int *param_1,uint param_2,undefined4 *param_3)

{
  ushort uVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  ushort *puVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined1 auStackX_0 [16];
  uint local_18 [6];
  
  puVar6 = local_18;
  puVar7 = local_18;
  iVar13 = 6;
  puVar8 = (ushort *)(param_1 + 1);
  iVar10 = 6;
  do {
    uVar1 = *puVar8;
    puVar8 = puVar8 + 1;
    *puVar6 = (uint)uVar1;
    iVar10 = iVar10 + -1;
    puVar6 = puVar6 + 1;
  } while (iVar10 != 0);
  if ((int)param_2 < 0) {
    param_2 = -param_2;
    bVar2 = true;
  }
  else {
    if (param_2 == 0) {
      puVar3 = param_3 + 1;
      do {
        *puVar3 = 0xffffffff;
        puVar3 = puVar3 + 1;
      } while (puVar3 != param_3 + 4);
      return -1;
    }
    bVar2 = false;
  }
  iVar10 = 0;
  iVar14 = 5;
  do {
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -4);
    uVar11 = iVar10 * 0x10000 + *(uint *)register0x00000074;
    uVar15 = uVar11 / param_2;
    if (param_2 == 0) {
      trap(0x1c00);
    }
    *(uint *)register0x00000074 = uVar15;
    iVar14 = iVar14 + -1;
    iVar10 = uVar11 - uVar15 * param_2;
  } while (-1 < iVar14);
  piVar9 = param_3 + 1;
  piVar12 = piVar9;
  do {
    uVar4 = *puVar7;
    puVar7 = puVar7 + 1;
    *(short *)piVar12 = (short)uVar4;
    iVar13 = iVar13 + -1;
    piVar12 = (int *)((int)piVar12 + 2);
  } while (iVar13 != 0);
  if (*param_1 == 0) {
    if (bVar2) {
      iVar13 = 0;
      do {
        if (*piVar9 != 0) goto LAB_c080446c;
        iVar13 = iVar13 + 1;
        piVar9 = piVar9 + 1;
      } while (iVar13 < 3);
    }
  }
  else {
    iVar14 = 1;
    iVar13 = 3;
    piVar12 = piVar9;
    do {
      iVar5 = *piVar12;
      *piVar12 = iVar14 + iVar5;
      if (iVar14 + iVar5 != 0) {
        iVar14 = 0;
      }
      iVar13 = iVar13 + -1;
      piVar12 = piVar12 + 1;
    } while (iVar13 != 0);
    iVar10 = param_2 - iVar10;
    if (!bVar2) {
      iVar13 = 0;
      do {
        if (*piVar9 != 0) {
LAB_c080446c:
          *param_3 = 1;
          return iVar10;
        }
        iVar13 = iVar13 + 1;
        piVar9 = piVar9 + 1;
      } while (iVar13 < 3);
    }
  }
  *param_3 = 0;
  return iVar10;
}



/* c0804474 FUN_c0804474 */

int FUN_c0804474(int param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  
  iVar1 = 2;
  puVar2 = (uint *)(param_1 + 0xc);
  do {
    if (*puVar2 != 0) {
      iVar3 = 0x1f;
      puVar4 = &DAT_c080513c;
      do {
        if ((*puVar2 & *puVar4) != 0) {
          return iVar1 * 0x20 + iVar3 + 1;
        }
        puVar4 = puVar4 + -1;
        iVar3 = iVar3 + -1;
      } while (-0x3f7faf41 < (int)puVar4);
    }
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + -1;
  } while (-1 < iVar1);
  return 0;
}



/* c0804620 FUN_c0804620 */

/* Boundary evidence: original MIPS .pdata c0804620..c080475b. Semantic name remains unreviewed. */

int FUN_c0804620(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c0805a78 != (code *)0x0) {
      iVar2 = (*DAT_c0805a78)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c08046d0;
    FUN_c0804ab4();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0802474(param_1,param_2);
  }
LAB_c08046d0:
  if (((param_2 == 0) && (FUN_c0804a3c(), iVar1 != 0)) && (DAT_c0805a78 != (code *)0x0)) {
    iVar1 = (*DAT_c0805a78)(param_1,0,param_3);
  }
  return iVar1;
}



/* c080475c FUN_c080475c */

/* Boundary evidence: original MIPS .pdata c080475c..c0804787. Semantic name remains unreviewed. */

void FUN_c080475c(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c0804788 entry */

/* Boundary evidence: original MIPS .pdata c0804788..c08047df. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c08047e0();
  }
  FUN_c0804620(param_1,param_2,param_3);
  return;
}



/* c08047e0 FUN_c08047e0 */

/* Boundary evidence: original MIPS .pdata c08047e0..c0804853. Semantic name remains unreviewed. */

void FUN_c08047e0(void)

{
  uint uVar1;
  
  if ((DAT_c0805140 == 0) || (DAT_c0805140 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0805140 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0805140 == 0) {
      DAT_c0805140 = 0xb064;
    }
  }
  DAT_c0805144 = ~DAT_c0805140;
  return;
}



/* c0804854 FUN_c0804854 */

/* Boundary evidence: original MIPS .pdata c0804854..c08048a7. Semantic name remains unreviewed. */

void FUN_c0804854(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c08048d4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c08048a8 FUN_c08048a8 */

/* Boundary evidence: original MIPS .pdata c08048a8..c08048d3. Semantic name remains unreviewed. */

undefined4 FUN_c08048a8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0804854(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c08048d4 FUN_c08048d4 */

/* Boundary evidence: original MIPS .pdata c08048d4..c080491b. Semantic name remains unreviewed. */

void FUN_c08048d4(uint param_1)

{
  if ((param_1 == DAT_c0805140) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c080491c FUN_c080491c */

/* Boundary evidence: original MIPS .pdata c080491c..c0804a3b. Semantic name remains unreviewed. */

void FUN_c080491c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c0805a28 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c0805a70;
    if (DAT_c0805a70 != (undefined4 *)0x0) {
      while (DAT_c0805a6c = DAT_c0805a6c + -1, _Memory <= DAT_c0805a6c) {
        if ((code *)*DAT_c0805a6c != (code *)0x0) {
          (*(code *)*DAT_c0805a6c)();
          _Memory = DAT_c0805a70;
        }
      }
      free(_Memory);
      DAT_c0805a6c = (undefined4 *)0x0;
      DAT_c0805a70 = (undefined4 *)0x0;
    }
    FUN_c0804a60((undefined4 *)&DAT_c0801010,(undefined4 *)&DAT_c0801014);
  }
  FUN_c0804a60((undefined4 *)&DAT_c0801018,(undefined4 *)&DAT_c080101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c0805a74,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0804a3c FUN_c0804a3c */

/* Boundary evidence: original MIPS .pdata c0804a3c..c0804a5f. Semantic name remains unreviewed. */

void FUN_c0804a3c(void)

{
  FUN_c080491c(0,0,1);
  return;
}



/* c0804a60 FUN_c0804a60 */

/* Boundary evidence: original MIPS .pdata c0804a60..c0804ab3. Semantic name remains unreviewed. */

void FUN_c0804a60(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0804ab4 FUN_c0804ab4 */

/* Boundary evidence: original MIPS .pdata c0804ab4..c0804aef. Semantic name remains unreviewed. */

void FUN_c0804ab4(void)

{
  FUN_c0804a60((undefined4 *)&DAT_c0801008,(undefined4 *)&DAT_c080100c);
  FUN_c0804a60((undefined4 *)&DAT_c0801000,(undefined4 *)&DAT_c0801004);
  return;
}


