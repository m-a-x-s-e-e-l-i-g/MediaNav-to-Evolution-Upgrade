/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..000110bb. Semantic name remains unreviewed. */

undefined4 FUN_00011000(LPCWSTR param_1,DWORD *param_2,int param_3)

{
  HANDLE hObject;
  undefined4 uVar1;
  uint local_248;
  DWORD local_228;
  uint local_18;
  
  local_18 = DAT_000140d8;
  hObject = FindFirstFileW(param_1,(LPWIN32_FIND_DATAW)&local_248);
  if (hObject == (HANDLE)0xffffffff) {
    FUN_00012408(local_18);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    if (((param_3 != 1) && ((local_248 & 0x10) == 0)) && (param_2 != (DWORD *)0x0)) {
      *param_2 = local_228;
    }
    CloseHandle(hObject);
    FUN_00012408(local_18);
  }
  return uVar1;
}



/* 000110bc FUN_000110bc */

/* Boundary evidence: original MIPS .pdata 000110bc..00011993. Semantic name remains unreviewed. */

LRESULT FUN_000110bc(HWND param_1,UINT param_2,uint param_3,LPARAM param_4)

{
  LRESULT LVar1;
  int iVar2;
  HDC hdc;
  HFONT h;
  HGDIOBJ h_00;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  code *pcVar6;
  tagRECT local_120;
  tagRECT local_110;
  tagRECT local_100;
  tagRECT local_f0;
  tagRECT local_e0;
  LOGFONTW local_d0;
  tagPAINTSTRUCT tStack_70;
  uint local_30;
  
  local_30 = DAT_000140d8;
  DAT_0001425c = param_1;
  if (param_2 == 1) {
    DAT_00014258 = CreateWindowExW(0,L"button",L"LEVEL1 (Debug_Low)",0x50020009,0x3c,0x82,0x96,0x1e,
                                   param_1,(HMENU)0x65,DAT_0001426c,(LPVOID)0x0);
    DAT_00014254 = CreateWindowExW(0,L"button",L"LEVEL2 (Debug_Mid)",0x50000009,0x3c,0xa0,0x96,0x1e,
                                   param_1,(HMENU)0x66,DAT_0001426c,(LPVOID)0x0);
    DAT_00014250 = CreateWindowExW(0,L"button",L"LEVEL3 (Debug_High)",0x50000009,0x3c,0xbe,0x96,0x1e
                                   ,param_1,(HMENU)0x67,DAT_0001426c,(LPVOID)0x0);
    DAT_0001424c = CreateWindowExW(0,L"button",L"LEVEL4 (Debug_Panic)",0x50000009,0x3c,0xdc,0x96,
                                   0x1e,param_1,(HMENU)0x68,DAT_0001426c,(LPVOID)0x0);
    CheckRadioButton(param_1,0x65,0x68,0x68);
    DAT_00014248 = CreateWindowExW(0,L"button",L"MD\\debugfile.log",0x50020009,0x104,0x82,0xb4,0x1e,
                                   param_1,(HMENU)0x6b,DAT_0001426c,(LPVOID)0x0);
    DAT_00014244 = CreateWindowExW(0,L"button",L"Storage Card2\\debugfile.log",0x50000009,0x104,0xa0
                                   ,0xb4,0x1e,param_1,(HMENU)0x6c,DAT_0001426c,(LPVOID)0x0);
    CheckRadioButton(param_1,0x6b,0x6c,0x6b);
    DAT_00014240 = CreateWindowExW(0,L"button",L"Save",0x50000000,0x118,0xbe,0x5a,0x32,param_1,
                                   (HMENU)0x6a,DAT_0001426c,(LPVOID)0x0);
    DAT_0001423c = CreateWindowExW(0,L"button",L"Select",0x50000000,0x50,0x104,0x5a,0x32,param_1,
                                   (HMENU)0x69,DAT_0001426c,(LPVOID)0x0);
    DAT_00014238 = CreateWindowExW(0,L"button",L"BACK",0x50000000,0x28a,100,0x5a,0x32,param_1,
                                   (HMENU)0x6d,DAT_0001426c,(LPVOID)0x0);
    goto switchD_000111bc_default;
  }
  if (param_2 == 2) {
    DestroyWindow(DAT_00014268);
    PostQuitMessage(0);
    goto switchD_000111bc_default;
  }
  if (param_2 == 0xf) {
    hdc = BeginPaint(param_1,&tStack_70);
    memset(&local_d0,0,0x5c);
    SetBkMode(hdc,1);
    SetTextColor(hdc,0x10101);
    local_d0.lfHeight = 0x28;
    local_d0.lfWidth = 0;
    local_d0.lfEscapement = 0;
    local_d0.lfOrientation = 0;
    local_d0.lfWeight = 0;
    local_d0.lfItalic = '\0';
    local_d0.lfUnderline = '\x01';
    local_d0.lfStrikeOut = '\0';
    local_d0.lfCharSet = '\0';
    local_d0.lfOutPrecision = '\0';
    local_d0.lfQuality = '\x06';
    local_d0.lfPitchAndFamily = '\x02';
    local_d0.lfClipPrecision = '\0';
    wsprintfW(local_d0.lfFaceName,L"Tahoma");
    h = CreateFontIndirectW(&local_d0);
    h_00 = SelectObject(hdc,h);
    local_110.left = 0x32;
    local_e0.right = 200;
    local_110.right = 0x96;
    local_e0.left = 0x46;
    local_120.left = 300;
    local_f0.left = 0x10e;
    local_f0.right = 0x15e;
    local_120.right = 0x15e;
    local_110.top = 0x28;
    local_110.bottom = 0x50;
    local_e0.top = 0x50;
    local_e0.bottom = 0x78;
    local_f0.top = 0x28;
    local_f0.bottom = 0x50;
    local_120.top = 0x50;
    local_120.bottom = 0x78;
    local_100.left = 600;
    local_100.top = 0x28;
    local_100.right = 800;
    local_100.bottom = 0x50;
    DrawTextW(hdc,L"Level",-1,&local_110,4);
    DrawTextW(hdc,L"Control",-1,&local_e0,4);
    DrawTextW(hdc,L"Save",-1,&local_f0,5);
    DrawTextW(hdc,L"Log",-1,&local_120,4);
    DrawTextW(hdc,L"ULC MgrLog",-1,&local_100,5);
    SelectObject(hdc,h_00);
    DeleteObject(h);
    EndPaint(param_1,&tStack_70);
    goto switchD_000111bc_default;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x8064) {
      LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
      FUN_00012408(local_30);
      return LVar1;
    }
    ShowWindow(param_1,5);
    SetWindowPos(DAT_0001425c,(HWND)0xffffffff,0,0,800,0x1e0,0x41);
    goto switchD_000111bc_default;
  }
  switch(param_3 & 0xffff) {
  case 0x65:
    DbgSetAllDebugOnOff(1);
    DbgSetAllDebugLevel(0);
    DAT_000140e4 = 0;
    break;
  case 0x66:
    DbgSetAllDebugOnOff(1);
    DbgSetAllDebugLevel(1);
    DAT_000140e4 = 1;
    break;
  case 0x67:
    DbgSetAllDebugOnOff(1);
    DbgSetAllDebugLevel(2);
    DAT_000140e4 = 2;
    break;
  case 0x68:
    DbgSetAllDebugOnOff(1);
    DbgSetAllDebugLevel(3);
    DAT_000140e4 = 3;
    break;
  case 0x69:
    DbgSetAllDebugOnOff(1);
    DbgSetAllDebugLevel(DAT_000140e4);
    break;
  case 0x6a:
    if (DAT_000140e0 == 0) {
      iVar2 = FUN_00011000(L"MD\\",(DWORD *)0x0,1);
      if (iVar2 != 0) {
        CopyFileW(L"\\debugfile_1.log",L"\\MD\\debugfile_1.log",0);
        pwVar3 = L"\\MD\\debugfile_2.log";
        goto LAB_000113d0;
      }
      DbgDebugPrint(0x13,2,L"MD is not connected. Copy - Disk_card2\r\n");
      CopyFileW(L"\\debugfile_1.log",L"\\Storage Card2\\debugfile_1.log",0);
      pwVar4 = L"\\Storage Card2\\debugfile_2.log";
      pwVar5 = (wchar_t *)0x0;
      pwVar3 = L"\\debugfile_2.log";
      pcVar6 = CopyFileW_exref;
    }
    else {
      if (DAT_000140e0 != 1) goto switchD_000111bc_default;
      CopyFileW(L"\\debugfile_1.log",L"\\Storage Card2\\debugfile_1.log",0);
      pwVar3 = L"\\Storage Card2\\debugfile_2.log";
LAB_000113d0:
      CopyFileW(L"\\debugfile_2.log",pwVar3,0);
      pwVar5 = L"Log Copy Success\r\n";
      pwVar4 = (wchar_t *)0x1;
      pwVar3 = (wchar_t *)0x13;
      pcVar6 = DbgDebugPrint_exref;
    }
    (*pcVar6)(pwVar3,pwVar4,pwVar5);
    goto switchD_000111bc_default;
  case 0x6b:
    DAT_000140e0 = 0;
    goto switchD_000111bc_default;
  case 0x6c:
    DAT_000140e0 = 1;
    goto switchD_000111bc_default;
  case 0x6d:
    ShowWindow(param_1,0);
  default:
    goto switchD_000111bc_default;
  }
  DbgDebugPrint(0x13,1,L"DbgSetAllLevel From MgrLog -> [%d] \r\n",DAT_000140e4);
switchD_000111bc_default:
  FUN_00012408(local_30);
  return 0;
}



/* 00011994 FUN_00011994 */

/* Boundary evidence: original MIPS .pdata 00011994..000119ff. Semantic name remains unreviewed. */

void FUN_00011994(HINSTANCE param_1,LPCWSTR param_2)

{
  WNDCLASSW local_30;
  
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_000110bc;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hInstance = param_1;
  local_30.hIcon = LoadIconW(param_1,(LPCWSTR)0x65);
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hbrBackground = GetStockObject(1);
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.lpszClassName = param_2;
  RegisterClassW(&local_30);
  return;
}



/* 00011a00 FUN_00011a00 */

/* Boundary evidence: original MIPS .pdata 00011a00..00011b47. Semantic name remains unreviewed. */

undefined4 FUN_00011a00(HINSTANCE param_1)

{
  DWORD DVar1;
  int iVar2;
  HWND hWnd;
  WCHAR aWStack_1a8 [100];
  WCHAR aWStack_e0 [100];
  uint local_18;
  
  local_18 = DAT_000140d8;
  CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,L"ULC cMgrLog");
  DVar1 = GetLastError();
  if (DVar1 != 0xb7) {
    DAT_0001426c = param_1;
    LoadStringW(param_1,1,aWStack_e0,100);
    LoadStringW(param_1,2,aWStack_1a8,100);
    iVar2 = FUN_00011994(param_1,aWStack_1a8);
    if ((iVar2 != 0) &&
       (hWnd = CreateWindowExW(0,aWStack_1a8,aWStack_e0,0x10000000,-0x80000000,-0x80000000,
                               -0x80000000,-0x80000000,(HWND)0x0,(HMENU)0x0,param_1,(LPVOID)0x0),
       hWnd != (HWND)0x0)) {
      ShowWindow(hWnd,0);
      UpdateWindow(hWnd);
      if (DAT_00014268 != 0) {
        CommandBar_Show(DAT_00014268,1);
      }
      FUN_00012408(local_18);
      return 1;
    }
  }
  FUN_00012408(local_18);
  return 0;
}



/* 00011b48 FUN_00011b48 */

/* Boundary evidence: original MIPS .pdata 00011b48..00011bdf. Semantic name remains unreviewed. */

WPARAM FUN_00011b48(HINSTANCE param_1)

{
  int iVar1;
  HACCEL hAccTable;
  BOOL BVar2;
  tagMSG local_28;
  
  iVar1 = FUN_00011a00(param_1);
  if (iVar1 == 0) {
    local_28.wParam = 0;
  }
  else {
    hAccTable = LoadAcceleratorsW(param_1,(LPCWSTR)0x2);
    while (BVar2 = GetMessageW(&local_28,(HWND)0x0,0,0), BVar2 != 0) {
      iVar1 = TranslateAcceleratorW(local_28.hwnd,hAccTable,&local_28);
      if (iVar1 == 0) {
        TranslateMessage(&local_28);
        DispatchMessageW(&local_28);
      }
    }
  }
  return local_28.wParam;
}



/* 00011be0 FUN_00011be0 */

/* Boundary evidence: original MIPS .pdata 00011be0..00011c33. Semantic name remains unreviewed. */

void FUN_00011be0(int param_1,void *param_2,int param_3,size_t param_4)

{
  if (*(int *)(param_1 + 8) != 0) {
    memcpy(param_2,(void *)(*(int *)(param_1 + 8) + param_3),param_4);
  }
  return;
}



/* 00011c34 FUN_00011c34 */

/* Boundary evidence: original MIPS .pdata 00011c34..00011c3f. Semantic name remains unreviewed. */

undefined4 FUN_00011c34(void)

{
  return 1;
}



/* 00011c40 FUN_00011c40 */

/* Boundary evidence: original MIPS .pdata 00011c40..00011c8b. Semantic name remains unreviewed. */

void FUN_00011c40(int param_1,void *param_2,int param_3,size_t param_4)

{
  if (*(int *)(param_1 + 8) != 0) {
    memcpy((void *)(*(int *)(param_1 + 8) + param_3),param_2,param_4);
  }
  return;
}



/* 00011c8c FUN_00011c8c */

/* Boundary evidence: original MIPS .pdata 00011c8c..00011c97. Semantic name remains unreviewed. */

undefined4 FUN_00011c8c(void)

{
  return 1;
}



/* 00011c98 FUN_00011c98 */

/* Boundary evidence: original MIPS .pdata 00011c98..00011d1f. Semantic name remains unreviewed. */

undefined4 FUN_00011c98(undefined4 *param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,1,param_2);
  *param_1 = pvVar1;
  DVar2 = GetLastError();
  if ((HANDLE)*param_1 == (HANDLE)0x0) {
    uVar3 = 0;
  }
  else if (DVar2 != 0xb7) {
    ReleaseMutex((HANDLE)*param_1);
  }
  return uVar3;
}



/* 00011d20 FUN_00011d20 */

/* Boundary evidence: original MIPS .pdata 00011d20..00011e47. Semantic name remains unreviewed. */

undefined4 FUN_00011d20(undefined4 *param_1,LPCWSTR param_2,DWORD param_3,HANDLE param_4)

{
  DWORD DVar1;
  HANDLE hFileMappingObject;
  LPVOID pvVar2;
  
  if (((HANDLE)*param_1 != (HANDLE)0x0) &&
     (DVar1 = WaitForSingleObject((HANDLE)*param_1,2000), DVar1 == 0)) {
    hFileMappingObject = CreateFileMappingW(param_4,(LPSECURITY_ATTRIBUTES)0x0,4,0,param_3,param_2);
    param_1[1] = hFileMappingObject;
    if (hFileMappingObject == (HANDLE)0x0) {
      GetLastError();
    }
    else {
      pvVar2 = MapViewOfFile(hFileMappingObject,0xf001f,0,0,0);
      param_1[2] = pvVar2;
      if (pvVar2 != (LPVOID)0x0) {
        if ((HANDLE)*param_1 != (HANDLE)0x0) {
          ReleaseMutex((HANDLE)*param_1);
        }
        return 1;
      }
      CloseHandle((HANDLE)param_1[1]);
      param_1[1] = 0;
    }
    if ((HANDLE)*param_1 != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)*param_1);
    }
  }
  return 0;
}



/* 00011e48 FUN_00011e48 */

/* Boundary evidence: original MIPS .pdata 00011e48..00011f5f. Semantic name remains unreviewed. */

undefined4 FUN_00011e48(undefined4 *param_1,LPCWSTR param_2,HANDLE param_3)

{
  DWORD DVar1;
  HANDLE hFileMappingObject;
  LPVOID pvVar2;
  
  if (((HANDLE)*param_1 != (HANDLE)0x0) &&
     (DVar1 = WaitForSingleObject((HANDLE)*param_1,2000), DVar1 == 0)) {
    hFileMappingObject = CreateFileMappingW(param_3,(LPSECURITY_ATTRIBUTES)0x0,2,0,0,param_2);
    param_1[1] = hFileMappingObject;
    if (hFileMappingObject == (HANDLE)0x0) {
      GetLastError();
    }
    else {
      pvVar2 = MapViewOfFile(hFileMappingObject,4,0,0,0);
      param_1[2] = pvVar2;
      if (pvVar2 != (LPVOID)0x0) {
        if ((HANDLE)*param_1 != (HANDLE)0x0) {
          ReleaseMutex((HANDLE)*param_1);
        }
        return 1;
      }
      CloseHandle((HANDLE)param_1[1]);
      param_1[1] = 0;
    }
    if ((HANDLE)*param_1 != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)*param_1);
    }
  }
  return 0;
}



/* 00011f60 MSHM_Dll_MakeMappingReadWrite */

/* Boundary evidence: original MIPS .pdata 00011f60..00011f8f. Semantic name remains unreviewed. */

bool MSHM_Dll_MakeMappingReadWrite(undefined4 *param_1,LPCWSTR param_2,DWORD param_3)

{
  int iVar1;
  
                    /* 0x1f60  4  MSHM_Dll_MakeMappingReadWrite */
  iVar1 = FUN_00011d20(param_1,param_2,param_3,(HANDLE)0xffffffff);
  return iVar1 != 0;
}



/* 00011f90 MSHM_Dll_MakeMappingReadOnly */

/* Boundary evidence: original MIPS .pdata 00011f90..00011fbf. Semantic name remains unreviewed. */

bool MSHM_Dll_MakeMappingReadOnly(undefined4 *param_1,LPCWSTR param_2)

{
  int iVar1;
  
                    /* 0x1f90  3  MSHM_Dll_MakeMappingReadOnly */
  iVar1 = FUN_00011e48(param_1,param_2,(HANDLE)0xffffffff);
  return iVar1 != 0;
}



/* 00011fc0 MSHM_Dll_Read */

/* Boundary evidence: original MIPS .pdata 00011fc0..00011fdb. Semantic name remains unreviewed. */

void MSHM_Dll_Read(int param_1,void *param_2,int param_3,size_t param_4)

{
                    /* 0x1fc0  5  MSHM_Dll_Read */
  FUN_00011be0(param_1,param_2,param_3,param_4);
  return;
}



/* 00011fdc MSHM_Dll_Write */

/* Boundary evidence: original MIPS .pdata 00011fdc..00011ff7. Semantic name remains unreviewed. */

void MSHM_Dll_Write(int param_1,void *param_2,int param_3,size_t param_4)

{
                    /* 0x1fdc  6  MSHM_Dll_Write */
  FUN_00011c40(param_1,param_2,param_3,param_4);
  return;
}



/* 00011ff8 FUN_00011ff8 */

/* Boundary evidence: original MIPS .pdata 00011ff8..00012097. Semantic name remains unreviewed. */

void FUN_00011ff8(undefined4 *param_1)

{
  DWORD DVar1;
  
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    DVar1 = WaitForSingleObject((HANDLE)*param_1,2000);
    if ((DVar1 == 0) && ((HANDLE)*param_1 != (HANDLE)0x0)) {
      ReleaseMutex((HANDLE)*param_1);
    }
    CloseHandle((HANDLE)*param_1);
  }
  if ((LPCVOID)param_1[2] != (LPCVOID)0x0) {
    UnmapViewOfFile((LPCVOID)param_1[2]);
  }
  if ((HANDLE)param_1[1] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[1]);
  }
  return;
}



/* 00012098 MSHM_Dll_DestoryShmClassObj */

/* Boundary evidence: original MIPS .pdata 00012098..000120cf. Semantic name remains unreviewed. */

void MSHM_Dll_DestoryShmClassObj(undefined4 *param_1)

{
                    /* 0x2098  2  MSHM_Dll_DestoryShmClassObj */
  if (param_1 != (undefined4 *)0x0) {
    FUN_00011ff8(param_1);
    __3_YAXPAX_Z(param_1);
  }
  return;
}



/* 000120d0 MSHM_Dll_CreateShmClassObj */

/* Boundary evidence: original MIPS .pdata 000120d0..00012153. Semantic name remains unreviewed. */

undefined4 * MSHM_Dll_CreateShmClassObj(LPCWSTR param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x20d0  1  MSHM_Dll_CreateShmClassObj */
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  if ((puVar1 != (undefined4 *)0x0) && (iVar2 = FUN_00011c98(puVar1,param_1), iVar2 == 0)) {
    FUN_00011ff8(puVar1);
    __3_YAXPAX_Z(puVar1);
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}



/* 00012314 FUN_00012314 */

/* Boundary evidence: original MIPS .pdata 00012314..00012387. Semantic name remains unreviewed. */

void FUN_00012314(void)

{
  uint uVar1;
  
  if ((DAT_000140d8 == 0) || (DAT_000140d8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000140d8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000140d8 == 0) {
      DAT_000140d8 = 0xb064;
    }
  }
  DAT_000140dc = ~DAT_000140d8;
  return;
}



/* 00012388 FUN_00012388 */

/* Boundary evidence: original MIPS .pdata 00012388..000123db. Semantic name remains unreviewed. */

void FUN_00012388(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00012408(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 000123dc FUN_000123dc */

/* Boundary evidence: original MIPS .pdata 000123dc..00012407. Semantic name remains unreviewed. */

undefined4 FUN_000123dc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00012388(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00012408 FUN_00012408 */

/* Boundary evidence: original MIPS .pdata 00012408..0001244f. Semantic name remains unreviewed. */

void FUN_00012408(uint param_1)

{
  if ((param_1 == DAT_000140d8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00012460 FUN_00012460 */

/* Boundary evidence: original MIPS .pdata 00012460..0001254b. Semantic name remains unreviewed. */

void FUN_00012460(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_00014270 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00014278;
    if (DAT_00014278 != (undefined4 *)0x0) {
      while (DAT_00014274 = DAT_00014274 + -1, _Memory <= DAT_00014274) {
        if ((code *)*DAT_00014274 != (code *)0x0) {
          (*(code *)*DAT_00014274)();
          _Memory = DAT_00014278;
        }
      }
      free(_Memory);
      DAT_00014274 = (undefined4 *)0x0;
      DAT_00014278 = (undefined4 *)0x0;
    }
    FUN_00012748((undefined4 *)&DAT_00013010,(undefined4 *)&DAT_00013014);
  }
  FUN_00012748((undefined4 *)&DAT_00013018,(undefined4 *)&DAT_0001301c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 0001254c FUN_0001254c */

/* Boundary evidence: original MIPS .pdata 0001254c..0001256b. Semantic name remains unreviewed. */

void FUN_0001254c(UINT param_1)

{
  FUN_00012460(param_1,0,0);
  return;
}



/* 0001256c FUN_0001256c */

/* Boundary evidence: original MIPS .pdata 0001256c..000125b7. Semantic name remains unreviewed. */

void FUN_0001256c(UINT param_1)

{
  DAT_00014270 = 0;
  FUN_00012748((undefined4 *)&DAT_00013018,(undefined4 *)&DAT_0001301c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000125f8 FUN_000125f8 */

/* Boundary evidence: original MIPS .pdata 000125f8..0001268b. Semantic name remains unreviewed. */

void FUN_000125f8(HINSTANCE param_1)

{
  WPARAM WVar1;
  
  FUN_0001279c();
  WVar1 = FUN_00011b48(param_1);
  FUN_0001254c(WVar1);
  FUN_0001256c(WVar1);
  return;
}



/* 0001268c FUN_0001268c */

/* Boundary evidence: original MIPS .pdata 0001268c..000126cb. Semantic name remains unreviewed. */

void FUN_0001268c(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 000126cc entry */

/* Boundary evidence: original MIPS .pdata 000126cc..00012727. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1)

{
  FUN_00012314();
  FUN_000125f8(param_1);
  return;
}



/* 00012748 FUN_00012748 */

/* Boundary evidence: original MIPS .pdata 00012748..0001279b. Semantic name remains unreviewed. */

void FUN_00012748(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 0001279c FUN_0001279c */

/* Boundary evidence: original MIPS .pdata 0001279c..000127d7. Semantic name remains unreviewed. */

void FUN_0001279c(void)

{
  FUN_00012748((undefined4 *)&DAT_00013008,(undefined4 *)&DAT_0001300c);
  FUN_00012748((undefined4 *)&DAT_00013000,(undefined4 *)&DAT_00013004);
  return;
}


