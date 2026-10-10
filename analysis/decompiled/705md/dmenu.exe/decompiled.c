/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

undefined4 * FUN_00011000(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x100;
  return param_1;
}



/* 00011020 FUN_00011020 */

/* Boundary evidence: original MIPS .pdata 00011020..0001116f. Semantic name remains unreviewed. */

undefined4 FUN_00011020(int *param_1)

{
  HANDLE pvVar1;
  BOOL BVar2;
  wchar_t *pwVar3;
  _COMMTIMEOUTS local_48;
  _DCB local_30;
  
  if (*param_1 == -1) {
    pvVar1 = CreateFileW(L"COM2:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    *param_1 = (int)pvVar1;
    if (pvVar1 == (HANDLE)0xffffffff) {
      pwVar3 = L"Impossible de se connecter au port COM2\n";
      goto LAB_0001114c;
    }
  }
  local_30.DCBlength = 0x1c;
  GetCommState((HANDLE)*param_1,&local_30);
  local_30.ByteSize = '\b';
  local_30.BaudRate = 300000;
  local_30._8_4_ = local_30._8_4_ & 0xffff9011 | 0x1011;
  local_30.Parity = '\0';
  local_30.StopBits = '\0';
  BVar2 = SetCommState((HANDLE)*param_1,&local_30);
  if (BVar2 == 0) {
    CloseHandle((HANDLE)*param_1);
    pwVar3 = L"Impossible de configurer le port série\n";
  }
  else {
    local_48.ReadIntervalTimeout = 2;
    local_48.ReadTotalTimeoutMultiplier = 1;
    local_48.ReadTotalTimeoutConstant = 6;
    local_48.WriteTotalTimeoutMultiplier = 0;
    local_48.WriteTotalTimeoutConstant = 0;
    BVar2 = SetCommTimeouts((HANDLE)*param_1,&local_48);
    if (BVar2 != 0) {
      return 1;
    }
    CloseHandle((HANDLE)*param_1);
    pwVar3 = L"Impossible de configurer les timeouts\n";
  }
LAB_0001114c:
  NKDbgPrintfW(pwVar3);
  return 0;
}



/* 00011170 FUN_00011170 */

/* Boundary evidence: original MIPS .pdata 00011170..00011203. Semantic name remains unreviewed. */

undefined4 FUN_00011170(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0xffffffff) {
    SetCommMask((HANDLE)*param_1,0);
    CloseHandle((HANDLE)*param_1);
    *param_1 = 0xffffffff;
  }
  if (param_1[2] != 0) {
    param_1[2] = 0;
    WaitForSingleObject((HANDLE)param_1[1],500);
    CloseHandle((HANDLE)param_1[1]);
    param_1[1] = 0;
  }
  return 1;
}



/* 00011204 FUN_00011204 */

/* Boundary evidence: original MIPS .pdata 00011204..00011253. Semantic name remains unreviewed. */

DWORD FUN_00011204(undefined4 *param_1,LPCVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD local_10 [2];
  
  local_10[0] = 0;
  BVar1 = WriteFile((HANDLE)*param_1,param_2,param_3,local_10,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    NKDbgPrintfW(&DAT_0001313c);
    local_10[0] = 0;
  }
  return local_10[0];
}



/* 00011254 FUN_00011254 */

/* Boundary evidence: original MIPS .pdata 00011254..0001126f. Semantic name remains unreviewed. */

void FUN_00011254(undefined4 *param_1)

{
  FUN_00011170(param_1);
  return;
}



/* 00011270 FUN_00011270 */

/* Boundary evidence: original MIPS .pdata 00011270..0001141b. Semantic name remains unreviewed. */

undefined4 FUN_00011270(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  DWORD local_18 [2];
  
  ReadFile((HANDLE)*param_1,(LPVOID)((int)param_1 + 0x19),param_1[3],local_18,(LPOVERLAPPED)0x0);
  param_1[0x47] = local_18[0];
  while (local_18[0] != 0) {
    iVar3 = param_1[0x47];
    if ((int)param_1[3] <= iVar3) break;
    ReadFile((HANDLE)*param_1,(LPVOID)((int)param_1 + iVar3 + 0x19),param_1[3] - iVar3,local_18,
             (LPOVERLAPPED)0x0);
    param_1[0x47] = local_18[0] + param_1[0x47];
  }
  iVar3 = param_1[0x47];
  if (4 < iVar3) {
    *(byte *)(param_1 + 4) = *(byte *)((int)param_1 + 0x1a) >> 4;
    *(byte *)((int)param_1 + 0x11) = *(byte *)((int)param_1 + 0x1a) & 0xf;
    *(undefined1 *)((int)param_1 + 0x12) = *(undefined1 *)((int)param_1 + 0x1b);
    *(undefined1 *)((int)param_1 + 0x13) = *(undefined1 *)(param_1 + 7);
    param_1[5] = (int)param_1 + 0x1d;
    bVar1 = *(byte *)((int)param_1 + iVar3 + 0x18);
    bVar4 = 0;
    *(byte *)(param_1 + 6) = bVar1;
    if ((iVar3 + 0xffU & 0xff) != 0) {
      uVar5 = 0;
      do {
        iVar2 = uVar5 + 0x19;
        uVar5 = uVar5 + 1 & 0xff;
        bVar4 = *(byte *)((int)param_1 + iVar2) ^ bVar4;
      } while (uVar5 < (iVar3 + 0xffU & 0xff));
    }
    if (bVar1 != bVar4) {
      if (bVar1 == 0xa6) {
        bVar1 = *(byte *)((int)param_1 + iVar3 + 0x17);
        bVar4 = 0;
        *(byte *)(param_1 + 6) = bVar1;
        uVar5 = 0;
        if ((iVar3 + 0xfeU & 0xff) != 0) {
          do {
            iVar3 = uVar5 + 0x19;
            uVar5 = uVar5 + 1 & 0xff;
            bVar4 = *(byte *)((int)param_1 + iVar3) ^ bVar4;
          } while (uVar5 < (param_1[0x47] + 0xfe & 0xff));
        }
        if (bVar1 == bVar4) {
          return 0;
        }
      }
      param_1[0x47] = 0;
    }
  }
  return 0;
}



/* 0001141c FUN_0001141c */

/* Boundary evidence: original MIPS .pdata 0001141c..000115b7. Semantic name remains unreviewed. */

DWORD FUN_0001141c(int *param_1,char param_2,undefined1 param_3,size_t param_4,void *param_5)

{
  undefined1 *puVar1;
  HANDLE hHandle;
  DWORD DVar2;
  undefined *puVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  if (param_1[2] == 0) {
    if (*param_1 != 0) {
      param_1[2] = 1;
      puVar1 = (undefined1 *)__2_YAPAXI_Z(param_4 + 5);
      *puVar1 = 0xaa;
      puVar1[1] = param_2 << 4 ^ 1;
      puVar1[2] = param_3;
      puVar1[3] = (char)param_4;
      if (param_4 != 0) {
        memcpy(puVar1 + 4,param_5,param_4);
      }
      uVar4 = param_4 + 4 & 0xff;
      bVar5 = 0;
      if (uVar4 != 0) {
        uVar6 = 0;
        do {
          bVar5 = puVar1[uVar6] ^ bVar5;
          uVar6 = uVar6 + 1 & 0xff;
        } while (uVar6 < uVar4);
      }
      puVar1[param_4 + 4] = bVar5;
      FUN_00011204(param_1,puVar1,param_4 + 5 & 0xff);
      __3_YAXPAX_Z(puVar1);
      hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00011270,param_1,0,(LPDWORD)0x0);
      param_1[1] = (int)hHandle;
      DVar2 = WaitForSingleObject(hHandle,500);
      CloseHandle((HANDLE)param_1[1]);
      param_1[1] = 0;
      param_1[2] = 0;
      return DVar2;
    }
    puVar3 = &DAT_00013190;
  }
  else {
    puVar3 = &DAT_000131b4;
  }
  NKDbgPrintfW(puVar3);
  return 0;
}



/* 000115b8 FUN_000115b8 */

/* Boundary evidence: original MIPS .pdata 000115b8..0001175b. Semantic name remains unreviewed. */

DWORD FUN_000115b8(int *param_1,char param_2,undefined4 param_3,size_t param_4,void *param_5)

{
  undefined1 *puVar1;
  HANDLE hHandle;
  DWORD DVar2;
  undefined *puVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  if (param_1[2] == 0) {
    if (*param_1 != 0) {
      param_1[2] = 1;
      puVar1 = (undefined1 *)__2_YAPAXI_Z(param_4 + 9);
      *puVar1 = 0xaa;
      puVar1[1] = param_2 << 4 ^ 6;
      puVar1[2] = (char)param_4;
      puVar1[3] = (char)param_4 + '\x04';
      *(undefined4 *)(puVar1 + 4) = param_3;
      if (param_4 != 0) {
        memcpy(puVar1 + 8,param_5,param_4);
      }
      uVar4 = param_4 + 8 & 0xff;
      bVar5 = 0;
      if (uVar4 != 0) {
        uVar6 = 0;
        do {
          bVar5 = puVar1[uVar6] ^ bVar5;
          uVar6 = uVar6 + 1 & 0xff;
        } while (uVar6 < uVar4);
      }
      puVar1[param_4 + 8] = bVar5;
      FUN_00011204(param_1,puVar1,param_4 + 9 & 0xff);
      __3_YAXPAX_Z(puVar1);
      hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00011270,param_1,0,(LPDWORD)0x0);
      param_1[1] = (int)hHandle;
      DVar2 = WaitForSingleObject(hHandle,500);
      CloseHandle((HANDLE)param_1[1]);
      param_1[1] = 0;
      param_1[2] = 0;
      return DVar2;
    }
    puVar3 = &DAT_00013190;
  }
  else {
    puVar3 = &DAT_000131b4;
  }
  NKDbgPrintfW(puVar3);
  return 0;
}



/* 0001175c FUN_0001175c */

/* Boundary evidence: original MIPS .pdata 0001175c..00011807. Semantic name remains unreviewed. */

void FUN_0001175c(void)

{
  memset(&DAT_0001410c,0,0x5c);
  DAT_0001410c = 0x28;
  DAT_00014110 = 0;
  DAT_00014114 = 0;
  DAT_00014118 = 0;
  DAT_0001411c = 700;
  DAT_00014120 = 0;
  DAT_00014121 = 0;
  DAT_00014122 = 0;
  DAT_00014123 = 1;
  DAT_00014124 = 0;
  DAT_00014125 = 0;
  DAT_00014126 = 4;
  DAT_00014127 = 0;
  wcsncpy((wchar_t *)&DAT_00014128,L"Arial",0x20);
  DAT_00014166 = 0;
  return;
}



/* 00011808 FUN_00011808 */

/* Boundary evidence: original MIPS .pdata 00011808..00011863. Semantic name remains unreviewed. */

undefined4 FUN_00011808(HWND param_1,DWORD param_2)

{
  DWORD local_18 [2];
  
  GetWindowThreadProcessId(param_1,local_18);
  if (local_18[0] == param_2) {
    PostMessageW(param_1,0x10,0,0);
  }
  return 1;
}



/* 00011864 FUN_00011864 */

/* Boundary evidence: original MIPS .pdata 00011864..00011927. Semantic name remains unreviewed. */

undefined4 FUN_00011864(LPCWSTR param_1)

{
  HWND hWnd;
  HANDLE hHandle;
  DWORD DVar1;
  DWORD local_18 [2];
  
  hWnd = FindWindowW(param_1,(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    GetWindowThreadProcessId(hWnd,local_18);
    CloseHandle(hWnd);
    hHandle = OpenProcess(0x100001,0,local_18[0]);
    if (hHandle != (HANDLE)0x0) {
      EnumWindows(FUN_00011808,local_18[0]);
      DVar1 = WaitForSingleObject(hHandle,10000);
      if (DVar1 != 0) {
        TerminateProcess(hHandle,0);
      }
      CloseHandle(hHandle);
    }
  }
  return 0;
}



/* 00011928 FUN_00011928 */

/* Boundary evidence: original MIPS .pdata 00011928..00011bf7. Semantic name remains unreviewed. */

void FUN_00011928(void)

{
  int *piVar1;
  HANDLE pvVar2;
  int iVar3;
  undefined4 *local_38;
  DWORD DStack_34;
  undefined1 auStack_30 [8];
  
  FUN_00011864(L"UpgradeManager");
  FUN_00011864(L"MGRMCM");
  FUN_00011864(L"AppMain");
  FUN_00011864(L"CodeChecker");
  FUN_00011864(L"MgrUsb");
  FUN_00011864(L"MgrIpod");
  FUN_00011864(L"MgrDab");
  FUN_00011864(L"BLUE");
  FUN_00011864(L"NAVI");
  iVar3 = 0;
  local_38 = (undefined4 *)__2_YAPAXI_Z(0x120);
  if (local_38 == (undefined4 *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_00011000(local_38);
  }
  if ((piVar1 != (int *)0x0) && (iVar3 = FUN_00011020(piVar1), iVar3 != 0)) {
    local_38 = (undefined4 *)CONCAT22(local_38._2_2_,0x17);
    FUN_000115b8(piVar1,'\x01',1,2,&local_38);
  }
  pvVar2 = CreateFileW(L"MGR1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (pvVar2 != (HANDLE)0xffffffff) {
    local_38 = (undefined4 *)CONCAT22((short)((uint)local_38 >> 0x10),0x100);
    DeviceIoControl(pvVar2,2,&local_38,2,(LPVOID)0x0,0,&DStack_34,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar2);
  }
  pvVar2 = (HANDLE)OpenStore(L"DSK1:");
  if (pvVar2 != (HANDLE)0xffffffff) {
    DismountStore(pvVar2);
    CloseHandle(pvVar2);
  }
  if (iVar3 != 0) {
    FUN_0001141c(piVar1,'\0',1,0,(void *)0x0);
  }
  if (piVar1 != (int *)0x0) {
    FUN_00011254(piVar1);
    __3_YAXPAX_Z(piVar1);
  }
  pvVar2 = CreateFileW(L"DSK1:",0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0x0);
  if (pvVar2 != (HANDLE)0xffffffff) {
    local_38 = (undefined4 *)0x0;
    DeviceIoControl(pvVar2,0x71f84,&local_38,4,auStack_30,4,&DStack_34,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar2);
  }
  SetSystemPowerState(0,0x200000);
  return;
}



/* 00011bf8 Unwind@00011bf8 */

/* Boundary evidence: original MIPS .pdata 00011bf8..00011c27. Semantic name remains unreviewed. */

void Unwind_00011bf8(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x38));
  return;
}



/* 00011c28 FUN_00011c28 */

/* Boundary evidence: original MIPS .pdata 00011c28..00011c9b. Semantic name remains unreviewed. */

undefined4 FUN_00011c28(void)

{
  HANDLE hObject;
  
  hObject = CreateFileW(L"\\Storage Card3\\StartWinCE",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,
                        0x80,(HANDLE)0x0);
  if (hObject != (HANDLE)0xffffffff) {
    CloseHandle(hObject);
  }
  FUN_00011928();
  return 0;
}



/* 00011c9c FUN_00011c9c */

/* Boundary evidence: original MIPS .pdata 00011c9c..0001249b. Semantic name remains unreviewed. */

LRESULT FUN_00011c9c(HWND param_1,UINT param_2,WPARAM param_3,uint param_4)

{
  undefined *lpchText;
  LRESULT LVar1;
  BOOL BVar2;
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ pvVar3;
  size_t cchText;
  HWND pHVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  RECT *lpRect;
  COLORREF color;
  undefined1 auStack_b8 [4];
  int local_b4;
  int local_b0;
  undefined1 auStack_a0 [4];
  int local_9c;
  int local_98;
  DWORD aDStack_88 [2];
  tagRECT tStack_80;
  tagPAINTSTRUCT tStack_70;
  uint local_30;
  
  local_30 = DAT_00014104;
  if (param_2 == 1) {
    DAT_0001419c = (HGDIOBJ)SHLoadDIBitmap(L"\\Storage Card\\System\\Img\\DMENU\\bg.bmp");
    DAT_000141a0 = (HGDIOBJ)SHLoadDIBitmap(L"\\Storage Card\\System\\Img\\DMENU\\btn.bmp");
  }
  else if (param_2 == 2) {
    PostQuitMessage(0);
  }
  else if (param_2 == 6) {
    if ((param_3 == 0) && (pHVar4 = FindWindowW(L"CodeChecker",L"CodeChecker"), pHVar4 == (HWND)0x0)
       ) {
      SetForegroundWindow((HWND)((uint)param_1 | 1));
    }
  }
  else if (param_2 == 0xf) {
    hdc = BeginPaint(param_1,&tStack_70);
    SetTextColor(hdc,0xf5f5f5);
    SetBkMode(hdc,1);
    hdc_00 = CreateCompatibleDC(hdc);
    pvVar3 = SelectObject(hdc_00,DAT_0001419c);
    GetObjectW(DAT_0001419c,0x18,auStack_b8);
    iVar6 = -local_b0 + 0x1e0;
    if (iVar6 < 0) {
      iVar6 = -local_b0 + 0x1e1;
    }
    iVar7 = -local_b4 + 800;
    if (iVar7 < 0) {
      iVar7 = -local_b4 + 0x321;
    }
    BitBlt(hdc,iVar7 >> 1,iVar6 >> 1,local_b4,local_b0,hdc_00,0,0,0xcc0020);
    SelectObject(hdc_00,pvVar3);
    pvVar3 = SelectObject(hdc_00,DAT_000141a0);
    GetObjectW(DAT_000141a0,0x18,auStack_a0);
    iVar6 = -local_b0 + 0x1e0;
    if (iVar6 < 0) {
      iVar6 = -local_b0 + 0x1e1;
    }
    iVar7 = -local_b4 + 800;
    if (iVar7 < 0) {
      iVar7 = -local_b4 + 0x321;
    }
    iVar5 = local_9c;
    if (local_9c < 0) {
      iVar5 = local_9c + 3;
    }
    SetRect((LPRECT)&DAT_00014188,(iVar7 >> 1) + 0x1e,((iVar6 >> 1) - local_98) + local_b0 + -0xf,
            (iVar5 >> 2) + (iVar7 >> 1) + 0x1e,(iVar6 >> 1) + local_b0 + -0xf);
    iVar6 = local_9c >> 2;
    if (DAT_000141a4 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = iVar6;
      if (local_9c < 0) {
        iVar7 = local_9c + 3 >> 2;
      }
    }
    if (local_9c < 0) {
      iVar6 = local_9c + 3 >> 2;
    }
    BitBlt(hdc,DAT_00014188,DAT_0001418c,iVar6,local_98,hdc_00,iVar7,0,0xcc0020);
    SelectObject(hdc_00,pvVar3);
    pvVar3 = SelectObject(hdc_00,DAT_000141a0);
    GetObjectW(DAT_000141a0,0x18,auStack_a0);
    iVar6 = -local_b0 + 0x1e0;
    if (iVar6 < 0) {
      iVar6 = -local_b0 + 0x1e1;
    }
    iVar7 = -local_b4 + 800;
    if (iVar7 < 0) {
      iVar7 = -local_b4 + 0x321;
    }
    iVar5 = local_9c;
    if (local_9c < 0) {
      iVar5 = local_9c + 3;
    }
    SetRect((LPRECT)&DAT_00014178,((iVar7 >> 1) - (iVar5 >> 2)) + local_b4 + -0x1e,
            ((iVar6 >> 1) - local_98) + local_b0 + -0xf,(iVar7 >> 1) + local_b4 + -0x1e,
            (iVar6 >> 1) + local_b0 + -0xf);
    iVar6 = local_9c >> 2;
    if (DAT_000141a8 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = iVar6;
      if (local_9c < 0) {
        iVar7 = local_9c + 3 >> 2;
      }
    }
    if (local_9c < 0) {
      iVar6 = local_9c + 3 >> 2;
    }
    BitBlt(hdc,DAT_00014178,DAT_0001417c,iVar6,local_98,hdc_00,iVar7,0,0xcc0020);
    SelectObject(hdc_00,pvVar3);
    DeleteDC(hdc_00);
    DAT_0001410c = 0x28;
    DAT_0001411c = 700;
    DAT_000141ac = CreateFontIndirectW((LOGFONTW *)&DAT_0001410c);
    pvVar3 = SelectObject(hdc,DAT_000141ac);
    iVar6 = -local_b0 + 0x1e0;
    if (iVar6 < 0) {
      iVar6 = -local_b0 + 0x1e1;
    }
    iVar7 = -local_b4 + 800;
    if (iVar7 < 0) {
      iVar7 = -local_b4 + 0x321;
    }
    SetRect(&tStack_80,iVar7 >> 1,iVar6 >> 1,(iVar7 >> 1) + local_b4,(iVar6 >> 1) + 0x50);
    DrawTextW(hdc,L"MoooooOOOoooo !!!",0x11,&tStack_80,5);
    SelectObject(hdc,pvVar3);
    DAT_0001410c = 0x23;
    DAT_0001411c = 400;
    DAT_000141ac = CreateFontIndirectW((LOGFONTW *)&DAT_0001410c);
    pvVar3 = SelectObject(hdc,DAT_000141ac);
    iVar6 = -local_b0 + 0x1e0;
    if (iVar6 < 0) {
      iVar6 = -local_b0 + 0x1e1;
    }
    iVar7 = -local_b4 + 800;
    if (iVar7 < 0) {
      iVar7 = -local_b4 + 0x321;
    }
    SetRect((LPRECT)&DAT_00014168,(iVar7 >> 1) + 0xf,(iVar6 >> 1) + 0x78,
            (iVar7 >> 1) + local_b4 + -0xf,(iVar6 >> 1) + 200);
    lpchText = PTR_DAT_00014100;
    cchText = wcslen((wchar_t *)PTR_DAT_00014100);
    DrawTextW(hdc,(LPCWSTR)lpchText,cchText,(LPRECT)&DAT_00014168,0x11);
    SelectObject(hdc,pvVar3);
    color = 0x2d2d2d;
    if (DAT_000141a4 == 0) {
      SetTextColor(hdc,0xf5f5f5);
    }
    else {
      SetTextColor(hdc,0x2d2d2d);
    }
    DAT_0001411c = 700;
    DAT_000141ac = CreateFontIndirectW((LOGFONTW *)&DAT_0001410c);
    pvVar3 = SelectObject(hdc,DAT_000141ac);
    DrawTextW(hdc,L"OK",2,(LPRECT)&DAT_00014188,5);
    if (DAT_000141a8 == 0) {
      color = 0xf5f5f5;
    }
    SetTextColor(hdc,color);
    DrawTextW(hdc,L"Annuler",7,(LPRECT)&DAT_00014178,5);
    SelectObject(hdc,pvVar3);
    EndPaint(param_1,&tStack_70);
  }
  else if (param_2 == 0x201) {
    lpRect = (RECT *)&DAT_00014188;
    BVar2 = PtInRect((RECT *)&DAT_00014188,
                     (POINT)(CONCAT44(param_4 >> 0x10,param_4) & 0xffffffff0000ffff));
    if (BVar2 == 0) {
      lpRect = (RECT *)&DAT_00014178;
      BVar2 = PtInRect((RECT *)&DAT_00014178,
                       (POINT)(CONCAT44(param_4 >> 0x10,param_4) & 0xffffffff0000ffff));
      if (BVar2 == 0) goto LAB_00012460;
      DAT_000141a8 = 1;
    }
    else {
      DAT_000141a4 = 1;
    }
    InvalidateRect(param_1,lpRect,1);
  }
  else {
    if (param_2 != 0x202) {
      LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
      FUN_00012a4c(local_30);
      return LVar1;
    }
    if (DAT_000141a4 == 0) {
      if (DAT_000141a8 == 0) goto LAB_00012460;
      DAT_000141a8 = 0;
      InvalidateRect(param_1,(RECT *)&DAT_00014178,1);
      BVar2 = PtInRect((RECT *)&DAT_00014178,
                       (POINT)(CONCAT44(param_4 >> 0x10,param_4) & 0xffffffff0000ffff));
      if (BVar2 != 0) {
        PostQuitMessage(0);
      }
    }
    else {
      DAT_000141a4 = 0;
      InvalidateRect(param_1,(RECT *)&DAT_00014188,1);
      InvalidateRect(param_1,(RECT *)&DAT_00014168,1);
      BVar2 = PtInRect((RECT *)&DAT_00014188,
                       (POINT)(CONCAT44(param_4 >> 0x10,param_4) & 0xffffffff0000ffff));
      if (BVar2 != 0) {
        PTR_DAT_00014100 = &DAT_00013504;
        CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00011c28,(LPVOID)0x0,0,aDStack_88);
      }
    }
    Sleep(100);
  }
LAB_00012460:
  FUN_00012a4c(local_30);
  return 0;
}



/* 0001249c FUN_0001249c */

/* Boundary evidence: original MIPS .pdata 0001249c..000124eb. Semantic name remains unreviewed. */

void FUN_0001249c(HINSTANCE param_1,LPCWSTR param_2)

{
  WNDCLASSW local_30;
  
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_00011c9c;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hIcon = (HICON)0x0;
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hbrBackground = (HBRUSH)0x0;
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.hInstance = param_1;
  local_30.lpszClassName = param_2;
  RegisterClassW(&local_30);
  return;
}



/* 000124ec FUN_000124ec */

/* Boundary evidence: original MIPS .pdata 000124ec..000125df. Semantic name remains unreviewed. */

undefined4 FUN_000124ec(HINSTANCE param_1,int param_2)

{
  int iVar1;
  HWND hWnd;
  
  DAT_00014198 = param_1;
  iVar1 = FUN_0001249c(param_1,L"dmenu");
  if ((iVar1 != 0) &&
     (hWnd = CreateWindowExW(0,L"dmenu",L"dmenu",0x10000000,-0x80000000,-0x80000000,-0x80000000,
                             -0x80000000,(HWND)0x0,(HMENU)0x0,param_1,(LPVOID)0x0),
     hWnd != (HWND)0x0)) {
    FUN_0001175c();
    SetWindowPos(hWnd,(HWND)0xffffffff,0,0,800,0x1e0,0);
    SetForegroundWindow((HWND)((uint)hWnd | 1));
    ShowWindow(hWnd,param_2);
    UpdateWindow(hWnd);
    return 1;
  }
  return 0;
}



/* 000125e0 FUN_000125e0 */

/* Boundary evidence: original MIPS .pdata 000125e0..00012647. Semantic name remains unreviewed. */

WPARAM FUN_000125e0(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  BOOL BVar2;
  MSG MStack_28;
  
  iVar1 = FUN_000124ec(param_1,param_4);
  if (iVar1 == 0) {
    MStack_28.wParam = 0;
  }
  else {
    while (BVar2 = GetMessageW(&MStack_28,(HWND)0x0,0,0), BVar2 != 0) {
      TranslateMessage(&MStack_28);
      DispatchMessageW(&MStack_28);
    }
    DeleteObject(DAT_000141ac);
  }
  return MStack_28.wParam;
}



/* 00012948 FUN_00012948 */

/* Boundary evidence: original MIPS .pdata 00012948..000129bb. Semantic name remains unreviewed. */

void FUN_00012948(void)

{
  uint uVar1;
  
  if ((DAT_00014104 == 0) || (DAT_00014104 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00014104 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00014104 == 0) {
      DAT_00014104 = 0xb064;
    }
  }
  DAT_00014108 = ~DAT_00014104;
  return;
}



/* 000129bc FUN_000129bc */

/* Boundary evidence: original MIPS .pdata 000129bc..00012a0f. Semantic name remains unreviewed. */

void FUN_000129bc(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00012a4c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00012a10 FUN_00012a10 */

/* Boundary evidence: original MIPS .pdata 00012a10..00012a3b. Semantic name remains unreviewed. */

undefined4 FUN_00012a10(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_000129bc(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00012a4c FUN_00012a4c */

/* Boundary evidence: original MIPS .pdata 00012a4c..00012a93. Semantic name remains unreviewed. */

void FUN_00012a4c(uint param_1)

{
  if ((param_1 == DAT_00014104) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00012a94 FUN_00012a94 */

/* Boundary evidence: original MIPS .pdata 00012a94..00012b27. Semantic name remains unreviewed. */

void FUN_00012a94(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  WPARAM WVar1;
  
  FUN_00012dd4();
  WVar1 = FUN_000125e0(param_1,param_2,param_3,param_4);
  FUN_00012d14(WVar1);
  FUN_00012d34(WVar1);
  return;
}



/* 00012b28 FUN_00012b28 */

/* Boundary evidence: original MIPS .pdata 00012b28..00012b67. Semantic name remains unreviewed. */

void FUN_00012b28(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00012b68 entry */

/* Boundary evidence: original MIPS .pdata 00012b68..00012bc3. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  FUN_00012948();
  FUN_00012a94(param_1,param_2,param_3,param_4);
  return;
}



/* 00012bf4 FUN_00012bf4 */

/* Boundary evidence: original MIPS .pdata 00012bf4..00012d13. Semantic name remains unreviewed. */

void FUN_00012bf4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_000141b0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000141b8;
    if (DAT_000141b8 != (undefined4 *)0x0) {
      while (DAT_000141b4 = DAT_000141b4 + -1, _Memory <= DAT_000141b4) {
        if ((code *)*DAT_000141b4 != (code *)0x0) {
          (*(code *)*DAT_000141b4)();
          _Memory = DAT_000141b8;
        }
      }
      free(_Memory);
      DAT_000141b4 = (undefined4 *)0x0;
      DAT_000141b8 = (undefined4 *)0x0;
    }
    FUN_00012d80((undefined4 *)&DAT_00013010,(undefined4 *)&DAT_00013014);
  }
  FUN_00012d80((undefined4 *)&DAT_00013018,(undefined4 *)&DAT_0001301c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_000141bc,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00012d14 FUN_00012d14 */

/* Boundary evidence: original MIPS .pdata 00012d14..00012d33. Semantic name remains unreviewed. */

void FUN_00012d14(UINT param_1)

{
  FUN_00012bf4(param_1,0,0);
  return;
}



/* 00012d34 FUN_00012d34 */

/* Boundary evidence: original MIPS .pdata 00012d34..00012d7f. Semantic name remains unreviewed. */

void FUN_00012d34(UINT param_1)

{
  DAT_000141b0 = 0;
  FUN_00012d80((undefined4 *)&DAT_00013018,(undefined4 *)&DAT_0001301c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00012d80 FUN_00012d80 */

/* Boundary evidence: original MIPS .pdata 00012d80..00012dd3. Semantic name remains unreviewed. */

void FUN_00012d80(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00012dd4 FUN_00012dd4 */

/* Boundary evidence: original MIPS .pdata 00012dd4..00012e0f. Semantic name remains unreviewed. */

void FUN_00012dd4(void)

{
  FUN_00012d80((undefined4 *)&DAT_00013008,(undefined4 *)&DAT_0001300c);
  FUN_00012d80((undefined4 *)&DAT_00013000,(undefined4 *)&DAT_00013004);
  return;
}


