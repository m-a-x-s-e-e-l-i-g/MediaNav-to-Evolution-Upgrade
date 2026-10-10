/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 10001000 FUN_10001000 */

/* Boundary evidence: original MIPS .pdata 10001000..1000106f. Semantic name remains unreviewed. */

bool FUN_10001000(undefined4 *param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateFileW(param_2,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *param_1 = pvVar1;
  return pvVar1 != (HANDLE)0xffffffff;
}



/* 10001070 FUN_10001070 */

/* Boundary evidence: original MIPS .pdata 10001070..1000117b. Semantic name remains unreviewed. */

BOOL FUN_10001070(undefined4 *param_1,undefined1 param_2,undefined1 param_3,void *param_4,
                 uint param_5)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD aDStack_28 [2];
  
  BVar2 = 0;
  if (param_5 < 0x200) {
    DVar1 = WaitForSingleObject((HANDLE)param_1[1],0xffffffff);
    if (DVar1 == 0) {
      DAT_1000daa8 = param_5;
      DAT_1000daa4 = param_2;
      DAT_1000daac = param_3;
      BVar2 = DeviceIoControl((HANDLE)*param_1,0x80002002,&DAT_1000daa4,0x208,&DAT_1000daad,param_5,
                              aDStack_28,(LPOVERLAPPED)0x0);
      if (BVar2 != 0) {
        memcpy(param_4,&DAT_1000daad,DAT_1000daa8);
      }
    }
    ReleaseMutex((HANDLE)param_1[1]);
  }
  else {
    BVar2 = 0;
  }
  return BVar2;
}



/* 1000117c FUN_1000117c */

/* Boundary evidence: original MIPS .pdata 1000117c..10001297. Semantic name remains unreviewed. */

BOOL FUN_1000117c(undefined4 *param_1,undefined1 param_2,int param_3,void *param_4,uint param_5)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD aDStack_28 [2];
  
  BVar2 = 0;
  if (param_5 < 0x200) {
    DVar1 = WaitForSingleObject((HANDLE)param_1[1],0xffffffff);
    if (DVar1 == 0) {
      DAT_1000dcac = param_2;
      if (param_3 == 0xff) {
        memcpy(&DAT_1000dcb4,param_4,param_5);
      }
      else {
        DAT_1000dcb4 = (undefined1)param_3;
        memcpy(&DAT_1000dcb5,param_4,param_5);
        param_5 = param_5 + 1;
      }
      DAT_1000dcb0 = param_5;
      BVar2 = DeviceIoControl((HANDLE)*param_1,0x80002001,&DAT_1000dcac,param_5 + 0x207,(LPVOID)0x0,
                              0,aDStack_28,(LPOVERLAPPED)0x0);
    }
    ReleaseMutex((HANDLE)param_1[1]);
  }
  else {
    BVar2 = 0;
  }
  return BVar2;
}



/* 10001298 FUN_10001298 */

/* Boundary evidence: original MIPS .pdata 10001298..100012f3. Semantic name remains unreviewed. */

bool FUN_10001298(int param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,param_2);
  *(HANDLE *)(param_1 + 4) = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    GetLastError();
  }
  return pvVar1 != (HANDLE)0x0;
}



/* 100012f4 FUN_100012f4 */

/* Boundary evidence: original MIPS .pdata 100012f4..10001337. Semantic name remains unreviewed. */

void FUN_100012f4(int param_1)

{
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
  }
  return;
}



/* 10001338 FUN_10001338 */

/* Boundary evidence: original MIPS .pdata 10001338..10001357. Semantic name remains unreviewed. */

void FUN_10001338(undefined4 *param_1,undefined1 param_2,undefined1 param_3,void *param_4,
                 uint param_5)

{
  FUN_10001070(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 10001358 FUN_10001358 */

/* Boundary evidence: original MIPS .pdata 10001358..10001377. Semantic name remains unreviewed. */

void FUN_10001358(undefined4 *param_1,undefined1 param_2,int param_3,void *param_4,uint param_5)

{
  FUN_1000117c(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 10001378 FUN_10001378 */

/* Boundary evidence: original MIPS .pdata 10001378..100013d7. Semantic name remains unreviewed. */

undefined4 * FUN_10001378(undefined4 *param_1,uint param_2)

{
  FUN_100012f4((int)param_1);
  CloseHandle((HANDLE)*param_1);
  *param_1 = 0xffffffff;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 100013d8 FUN_100013d8 */

/* Boundary evidence: original MIPS .pdata 100013d8..10001413. Semantic name remains unreviewed. */

void FUN_100013d8(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_100012f4((int)param_1);
    FUN_10001378(param_1,1);
  }
  return;
}



/* 10001414 FUN_10001414 */

/* Boundary evidence: original MIPS .pdata 10001414..1000149f. Semantic name remains unreviewed. */

undefined4 * FUN_10001414(void)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  
  puVar2 = (undefined4 *)__2_YAPAXI_Z(8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0xffffffff;
    puVar2[1] = 0xffffffff;
  }
  if (puVar2 != (undefined4 *)0x0) {
    bVar1 = FUN_10001000(puVar2,L"SMB1:");
    if ((CONCAT31(extraout_var,bVar1) != 0) &&
       (bVar1 = FUN_10001298((int)puVar2,L"MUTEXI2C"), CONCAT31(extraout_var_00,bVar1) != 0)) {
      return puVar2;
    }
    FUN_10001378(puVar2,1);
  }
  return (undefined4 *)0x0;
}



/* 100014a0 FUN_100014a0 */

/* Boundary evidence: original MIPS .pdata 100014a0..1000151b. Semantic name remains unreviewed. */

undefined4 * FUN_100014a0(undefined1 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_18 [8];
  
  puVar1 = FUN_10001414();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    local_18[0] = 0;
    iVar2 = FUN_10001338(puVar1,param_1,0,local_18,1);
    if (iVar2 == 0) {
      DAT_1000deb4 = 1;
    }
  }
  return puVar1;
}



/* 1000151c FUN_1000151c */

/* Boundary evidence: original MIPS .pdata 1000151c..1000154b. Semantic name remains unreviewed. */

void FUN_1000151c(undefined4 *param_1)

{
  FUN_100013d8(param_1);
  NKDbgPrintfW(L"%S MI2C_MI2C_Dll_Close","CloseI2C");
  return;
}



/* 1000154c FUN_1000154c */

/* Boundary evidence: original MIPS .pdata 1000154c..100015fb. Semantic name remains unreviewed. */

HANDLE FUN_1000154c(void)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
  if (DAT_1000deb8 == 0) {
    DAT_1000debc = CreateFileW(L"MEM1:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  }
  DAT_1000deb8 = DAT_1000deb8 + 1;
  pvVar2 = DAT_1000debc;
  if (DAT_1000debc == (HANDLE)0xffffffff) {
    DVar1 = GetLastError();
    NKDbgPrintfW(L"Cannot open MEM1: %d\r\n",DVar1);
    pvVar2 = (HANDLE)0x0;
  }
  return pvVar2;
}



/* 100015fc FUN_100015fc */

/* Boundary evidence: original MIPS .pdata 100015fc..1000165b. Semantic name remains unreviewed. */

void FUN_100015fc(int param_1)

{
  DAT_1000deb8 = DAT_1000deb8 + -1;
  if (DAT_1000deb8 == 0) {
    if (DAT_1000debc == param_1) {
      CloseHandle((HANDLE)DAT_1000debc);
    }
    else {
      NKDbgPrintfW(L"mempool handle mismatch error!\r\n");
    }
  }
  return;
}



/* 1000165c FUN_1000165c */

/* Boundary evidence: original MIPS .pdata 1000165c..1000171f. Semantic name remains unreviewed. */

void * FUN_1000165c(HANDLE param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *lpInBuffer;
  BOOL BVar1;
  DWORD aDStack_20 [2];
  
  lpInBuffer = malloc(0x20);
  if (lpInBuffer != (void *)0x0) {
    *(undefined4 *)((int)lpInBuffer + 0xc) = param_2;
    *(undefined4 *)((int)lpInBuffer + 0x14) = param_3;
    *(undefined4 *)((int)lpInBuffer + 0x10) = param_4;
    BVar1 = DeviceIoControl(param_1,0x220404,lpInBuffer,0x20,(LPVOID)0x0,0,aDStack_20,
                            (LPOVERLAPPED)0x0);
    if ((BVar1 != 0) && (*(int *)((int)lpInBuffer + 8) != 0)) {
      return lpInBuffer;
    }
    free(lpInBuffer);
  }
  return (void *)0x0;
}



/* 10001720 FUN_10001720 */

/* Boundary evidence: original MIPS .pdata 10001720..10001777. Semantic name remains unreviewed. */

void FUN_10001720(HANDLE param_1,void *param_2)

{
  DWORD aDStack_10 [2];
  
  DeviceIoControl(param_1,0x220408,param_2,0x20,(LPVOID)0x0,0,aDStack_10,(LPOVERLAPPED)0x0);
  free(param_2);
  return;
}



/* 10001778 FUN_10001778 */

/* Boundary evidence: original MIPS .pdata 10001778..10001817. Semantic name remains unreviewed. */

uint FUN_10001778(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = __litofp();
  uVar2 = __litofp(param_2);
  uVar1 = __fpdiv(uVar1,uVar2);
  iVar3 = __fptoul(uVar1);
  uVar2 = __ultofp(iVar3);
  uVar1 = __fpsub(uVar1,uVar2);
  uVar1 = __fpmul(uVar1,0x47800000);
  uVar4 = __fptoul(uVar1);
  if ((uVar4 & 0xffff) != 0) {
    uVar4 = uVar4 + 4 & 0xfffffffc;
  }
  return iVar3 << 0x10 | uVar4;
}



/* 10001818 FUN_10001818 */

void FUN_10001818(int param_1)

{
  *(undefined4 *)(param_1 + 0x31c) = 0x662;
  *(undefined4 *)(param_1 + 0x338) = 0xf211;
  *(undefined4 *)(param_1 + 0x324) = 0x1191;
  *(undefined4 *)(param_1 + 0x314) = 0x4a7;
  *(undefined4 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 800) = 0x4a7;
  *(undefined4 *)(param_1 + 0x328) = 0x1340;
  *(undefined4 *)(param_1 + 0x33c) = 0x879;
  *(undefined4 *)(param_1 + 0x32c) = 0x4a7;
  *(undefined4 *)(param_1 + 0x330) = 0x811;
  *(undefined4 *)(param_1 + 0x334) = 0;
  *(undefined4 *)(param_1 + 0x340) = 0xeeb3;
  *(undefined4 *)(param_1 + 0x344) = 0;
  return;
}



/* 10001870 FUN_10001870 */

void FUN_10001870(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar1 = &DAT_1000d16c;
  if (param_2 != 0) {
    puVar1 = &DAT_1000d1ec;
  }
  puVar4 = (undefined4 *)(param_1 + 0x14);
  iVar5 = 0x20;
  puVar3 = puVar1;
  do {
    puVar2 = (undefined4 *)(((int)&DAT_1000d16c - (int)puVar1) + (int)puVar3);
    iVar5 = iVar5 + -1;
    *puVar4 = *puVar2;
    puVar4[0x20] = *puVar3;
    puVar4[0x40] = *puVar2;
    puVar4[0x60] = *puVar3;
    puVar4[0x80] = *puVar2;
    puVar4[0xa0] = *puVar3;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar5 != 0);
  return;
}



/* 100018e8 FUN_100018e8 */

void FUN_100018e8(int param_1,uint param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x348) = 0;
  if (param_2 < 0x5655594a) {
    if ((param_2 != 0x56555949) && (param_2 != 0x30323449)) {
      if (param_2 == 0x32595559) goto LAB_10001a00;
      if (param_2 == 0x44444444) {
        *(undefined4 *)(param_1 + 0x348) = 2;
        goto LAB_10001a24;
      }
      if (param_2 != 0x55595659) goto LAB_100019cc;
      *(undefined4 *)(param_1 + 0x348) = 0x74;
      goto LAB_10001a08;
    }
    iVar1 = param_4 * param_5 + param_3;
    *(int *)(param_1 + 0x358) = iVar1;
    *(uint *)(param_1 + 0x360) = (param_4 * param_5 >> 2) + iVar1;
LAB_10001984:
    *(undefined4 *)(param_1 + 0x348) = 0;
    *(uint *)(param_1 + 0x354) = param_4;
    *(uint *)(param_1 + 0x364) = param_4 >> 1;
    *(uint *)(param_1 + 0x35c) = param_4 >> 1;
  }
  else {
    if (param_2 == 0x56595559) {
LAB_10001a00:
      uVar2 = 100;
    }
    else {
      if (param_2 != 0x59555956) {
        if (param_2 == 0x59565955) {
          *(undefined4 *)(param_1 + 0x348) = 0x44;
          goto LAB_10001a08;
        }
LAB_100019cc:
        iVar1 = param_4 * param_5 + param_3;
        *(int *)(param_1 + 0x360) = iVar1;
        *(uint *)(param_1 + 0x358) = (param_4 * param_5 >> 2) + iVar1;
        goto LAB_10001984;
      }
      uVar2 = 0x54;
    }
    *(undefined4 *)(param_1 + 0x348) = uVar2;
LAB_10001a08:
    iVar1 = param_4 << 1;
    *(int *)(param_1 + 0x354) = iVar1;
    *(int *)(param_1 + 0x35c) = iVar1;
    *(int *)(param_1 + 0x364) = iVar1;
    *(int *)(param_1 + 0x358) = param_3;
    *(int *)(param_1 + 0x360) = param_3;
  }
  *(int *)(param_1 + 0x350) = param_3;
LAB_10001a24:
  *(uint *)(param_1 + 0x34c) =
       (param_5 & 0x7ff) << 0x10 | param_4 & 0x7ff | *(uint *)(param_1 + 0x34c) & 0xf800f800;
  return;
}



/* 10001a50 FUN_10001a50 */

/* Boundary evidence: original MIPS .pdata 10001a50..10001ac3. Semantic name remains unreviewed. */

bool FUN_10001a50(HANDLE param_1,LPVOID param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = DeviceIoControl(param_1,0x232008,param_2,0x3a0,(LPVOID)0x0,0,(LPDWORD)0x0,
                          (LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    NKDbgPrintfW(L"OS_API: MAEBE_IOCTL_SUBMIT_TRANSACTION Failed!: %d\r\n",DVar2);
  }
  return BVar1 != 0;
}



/* 10001ac4 FUN_10001ac4 */

/* Boundary evidence: original MIPS .pdata 10001ac4..10001b73. Semantic name remains unreviewed. */

HANDLE FUN_10001ac4(void)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
  if (DAT_1000dec0 == 0) {
    DAT_1000dec4 = CreateFileW(L"ITE1:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  }
  DAT_1000dec0 = DAT_1000dec0 + 1;
  pvVar2 = DAT_1000dec4;
  if (DAT_1000dec4 == (HANDLE)0xffffffff) {
    DVar1 = GetLastError();
    NKDbgPrintfW(L"OS_API: Cannot open ITE1: %d\r\n",DVar1);
    pvVar2 = (HANDLE)0x0;
  }
  return pvVar2;
}



/* 10001b74 FUN_10001b74 */

/* Boundary evidence: original MIPS .pdata 10001b74..10001bd3. Semantic name remains unreviewed. */

void FUN_10001b74(int param_1)

{
  DAT_1000dec0 = DAT_1000dec0 + -1;
  if (DAT_1000dec0 == 0) {
    if (param_1 == DAT_1000dec4) {
      CloseHandle((HANDLE)DAT_1000dec4);
    }
    else {
      NKDbgPrintfW(L"ite handle mismatch error!\r\n");
    }
  }
  return;
}



/* 10001bd4 FUN_10001bd4 */

/* Boundary evidence: original MIPS .pdata 10001bd4..10001bef. Semantic name remains unreviewed. */

void FUN_10001bd4(void)

{
  GetSystemMetrics(0);
  return;
}



/* 10001bf0 FUN_10001bf0 */

/* Boundary evidence: original MIPS .pdata 10001bf0..10001c0b. Semantic name remains unreviewed. */

void FUN_10001bf0(void)

{
  GetSystemMetrics(1);
  return;
}



/* 10001c0c FUN_10001c0c */

/* Boundary evidence: original MIPS .pdata 10001c0c..10001c8f. Semantic name remains unreviewed. */

undefined4 FUN_10001c0c(undefined4 param_1,int param_2)

{
  HDC hdc;
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
  hdc = GetDC((HWND)0x0);
  if (param_2 == 0) {
    ExtEscape(hdc,0x229c48,4,(LPCSTR)local_res0,0,(LPSTR)0x0);
  }
  else {
    ExtEscape(hdc,0x229c44,4,(LPCSTR)local_res0,0,(LPSTR)0x0);
  }
  ReleaseDC((HWND)0x0,hdc);
  return 0;
}



/* 10001c90 FUN_10001c90 */

/* Boundary evidence: original MIPS .pdata 10001c90..10001cf7. Semantic name remains unreviewed. */

int FUN_10001c90(LPCSTR param_1)

{
  HDC hdc;
  int iVar1;
  
  hdc = GetDC((HWND)0x0);
  iVar1 = ExtEscape(hdc,0x229c4c,0x20,param_1,0,(LPSTR)0x0);
  ReleaseDC((HWND)0x0,hdc);
  return iVar1;
}



/* 10001cf8 FUN_10001cf8 */

/* Boundary evidence: original MIPS .pdata 10001cf8..10001d6f. Semantic name remains unreviewed. */

int FUN_10001cf8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HDC hdc;
  int iVar1;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined4 uStack00000014;
  
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  hdc = GetDC((HWND)0x0);
  uStack00000014 = 0;
  iVar1 = ExtEscape(hdc,0x229c74,0x20,(LPCSTR)&local_res0,0,(LPSTR)0x0);
  ReleaseDC((HWND)0x0,hdc);
  return iVar1;
}



/* 10001d70 FUN_10001d70 */

/* Boundary evidence: original MIPS .pdata 10001d70..10001ddf. Semantic name remains unreviewed. */

int FUN_10001d70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HDC hdc;
  int iVar1;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  hdc = GetDC((HWND)0x0);
  iVar1 = ExtEscape(hdc,0x229c78,0xc,(LPCSTR)&local_res0,0,(LPSTR)0x0);
  ReleaseDC((HWND)0x0,hdc);
  return iVar1;
}



/* 10001de0 FUN_10001de0 */

/* Boundary evidence: original MIPS .pdata 10001de0..10001e53. Semantic name remains unreviewed. */

int FUN_10001de0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HDC hdc;
  int iVar1;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  hdc = GetDC((HWND)0x0);
  iVar1 = ExtEscape(hdc,0x229c50,0x20,(LPCSTR)&local_res0,0,(LPSTR)0x0);
  ReleaseDC((HWND)0x0,hdc);
  return iVar1;
}



/* 10001e60 FUN_10001e60 */

/* Boundary evidence: original MIPS .pdata 10001e60..10001ec7. Semantic name remains unreviewed. */

undefined * FUN_10001e60(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)*param_1)();
  _snwprintf((wchar_t *)&DAT_1000dec8,99,L"%s%s\\",uVar1,(&PTR_DAT_1000d310)[param_2]);
  return &DAT_1000dec8;
}



/* 10001ec8 FUN_10001ec8 */

/* Boundary evidence: original MIPS .pdata 10001ec8..10001f2f. Semantic name remains unreviewed. */

LPWSTR FUN_10001ec8(int param_1,int param_2)

{
  undefined *puVar1;
  
  if (param_2 < *(int *)(param_1 + 0x630)) {
    puVar1 = (&PTR_u_mgrmcm_volume_bg_bmp_1000d26c)[param_2];
  }
  else {
    puVar1 = &DAT_10009b2c;
  }
  wsprintfW((LPWSTR)(param_1 + 0x414),L"%s%s",param_1 + 0x20c,puVar1);
  return (LPWSTR)(param_1 + 0x414);
}



/* 10001f30 FUN_10001f30 */

void FUN_10001f30(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_10009b30;
  return;
}



/* 10001f40 FUN_10001f40 */

/* Boundary evidence: original MIPS .pdata 10001f40..10001fbb. Semantic name remains unreviewed. */

void FUN_10001f40(int param_1)

{
  HGDIOBJ ho;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x630)) {
    iVar1 = 0;
    do {
      ho = *(HGDIOBJ *)(*(int *)(param_1 + 0x62c) + iVar1);
      if (ho != (HGDIOBJ)0x0) {
        DeleteObject(ho);
        *(undefined4 *)(*(int *)(param_1 + 0x62c) + iVar1) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 0x630));
  }
  return;
}



/* 10001fbc FUN_10001fbc */

/* Boundary evidence: original MIPS .pdata 10001fbc..1000200b. Semantic name remains unreviewed. */

int FUN_10001fbc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = SHLoadDIBitmap(param_2);
  if (iVar1 == 0) {
    NKDbgPrintfW(L"\r\n~~~~~~~~ (%s) file not found!!!!\r\n",param_2);
  }
  return iVar1;
}



/* 1000200c FUN_1000200c */

/* Boundary evidence: original MIPS .pdata 1000200c..100020c3. Semantic name remains unreviewed. */

void FUN_1000200c(int param_1)

{
  HMODULE hModule;
  size_t sVar1;
  short *psVar2;
  wchar_t *lpFilename;
  
  lpFilename = (wchar_t *)(param_1 + 4);
  hModule = GetModuleHandleW((LPCWSTR)0x0);
  GetModuleFileNameW(hModule,lpFilename,0x104);
  sVar1 = wcslen(lpFilename);
  if (0 < (int)sVar1) {
    psVar2 = (short *)((sVar1 + 2) * 2 + param_1);
    do {
      if (*psVar2 == 0x5c) {
        *(undefined2 *)((sVar1 + 3) * 2 + param_1) = 0;
        wcsncpy((wchar_t *)(param_1 + 0x20c),lpFilename,0x104);
        return;
      }
      sVar1 = sVar1 - 1;
      psVar2 = psVar2 + -1;
    } while (0 < (int)sVar1);
  }
  *(undefined2 *)(param_1 + 0x20c) = 0x5c;
  *(undefined2 *)(param_1 + 0x20e) = 0;
  return;
}



/* 100020c4 FUN_100020c4 */

/* Boundary evidence: original MIPS .pdata 100020c4..10002117. Semantic name remains unreviewed. */

void FUN_100020c4(int param_1,short *param_2)

{
  undefined *puVar1;
  
  if (param_2 != (short *)0x0) {
    if (*param_2 == 0x5c) {
      puVar1 = &DAT_10009b2c;
    }
    else {
      puVar1 = (undefined *)(param_1 + 4);
    }
    _snwprintf((wchar_t *)(param_1 + 0x20c),0x103,L"%s%s",puVar1,param_2);
  }
  return;
}



/* 10002118 FUN_10002118 */

/* Boundary evidence: original MIPS .pdata 10002118..100021b7. Semantic name remains unreviewed. */

void FUN_10002118(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_10009b8c;
  if (param_1[0x18b] != 0) {
    FUN_10001f40((int)param_1);
    __3_YAXPAX_Z(param_1[0x18b]);
    param_1[0x18b] = 0;
  }
  if (param_1[0x189] != 0) {
    __3_YAXPAX_Z();
    param_1[0x189] = 0;
  }
  if (param_1[0x188] != 0) {
    __3_YAXPAX_Z();
    param_1[0x188] = 0;
  }
  *param_1 = &PTR_LAB_10009b30;
  return;
}



/* 100021b8 Unwind@100021b8 */

/* Boundary evidence: original MIPS .pdata 100021b8..100021e7. Semantic name remains unreviewed. */

void Unwind_100021b8(void)

{
  undefined4 *in_v0;
  
  FUN_10001f30((undefined4 *)*in_v0);
  return;
}



/* 100021e8 FUN_100021e8 */

/* Boundary evidence: original MIPS .pdata 100021e8..10002233. Semantic name remains unreviewed. */

undefined4 * FUN_100021e8(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_10009b30;
  param_1[0x18b] = 0;
  param_1[0x188] = 0;
  param_1[0x189] = 0;
  param_1[0x18c] = 0;
  param_1[0x18a] = 0;
  FUN_1000200c((int)param_1);
  return param_1;
}



/* 10002234 FUN_10002234 */

/* Boundary evidence: original MIPS .pdata 10002234..10002277. Semantic name remains unreviewed. */

undefined4 * FUN_10002234(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_10009b30;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 10002278 FUN_10002278 */

/* Boundary evidence: original MIPS .pdata 10002278..100022fb. Semantic name remains unreviewed. */

void FUN_10002278(int param_1,short *param_2)

{
  HGDIOBJ ho;
  int iVar1;
  int iVar2;
  
  FUN_100020c4(param_1,param_2);
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x630)) {
    iVar1 = 0;
    do {
      ho = *(HGDIOBJ *)(*(int *)(param_1 + 0x62c) + iVar1);
      if (ho != (HGDIOBJ)0x0) {
        DeleteObject(ho);
        *(undefined4 *)(*(int *)(param_1 + 0x62c) + iVar1) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 0x630));
  }
  return;
}



/* 100022fc FUN_100022fc */

/* Boundary evidence: original MIPS .pdata 100022fc..1000235f. Semantic name remains unreviewed. */

void FUN_100022fc(int *param_1,int param_2)

{
  short *psVar1;
  
  if ((param_1[0x187] != param_2) &&
     (psVar1 = (short *)(**(code **)(*param_1 + 4))(param_1,param_2), psVar1 != (short *)0x0)) {
    param_1[0x187] = param_2;
    FUN_10002278((int)param_1,psVar1);
  }
  return;
}



/* 10002360 FUN_10002360 */

/* Boundary evidence: original MIPS .pdata 10002360..1000245b. Semantic name remains unreviewed. */

int FUN_10002360(int *param_1,int param_2)

{
  wchar_t *_Str;
  size_t sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_2 < param_1[0x18c]) && (param_2 != -1)) {
    iVar4 = param_2 * 4;
    iVar3 = *(int *)(param_1[0x18b] + iVar4);
    if (iVar3 == 0) {
      _Str = (wchar_t *)(**(code **)(*param_1 + 0xc))(param_1);
      iVar3 = param_1[0x18b];
      if ((*(int *)(iVar3 + iVar4) == 0) && (_Str != (wchar_t *)0x0)) {
        sVar1 = wcslen(_Str);
        iVar2 = wcscmp(_Str + (sVar1 - 3),L"png");
        if (iVar2 == 0) {
          *(int *)(iVar3 + iVar4) = 0;
        }
        else {
          iVar3 = FUN_10001fbc(param_1,_Str);
          *(int *)(param_1[0x18b] + iVar4) = iVar3;
        }
      }
      iVar3 = *(int *)(param_1[0x18b] + iVar4);
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



/* 1000245c FUN_1000245c */

/* Boundary evidence: original MIPS .pdata 1000245c..1000256b. Semantic name remains unreviewed. */

undefined4 * FUN_1000245c(undefined4 *param_1)

{
  void *_Dst;
  int iVar1;
  undefined4 uVar2;
  wchar_t local_220;
  undefined1 auStack_21e [518];
  uint local_18;
  
  local_18 = DAT_1000da9c;
  FUN_100021e8(param_1);
  *param_1 = &PTR_LAB_10009b8c;
  local_220 = L'\0';
  memset(auStack_21e,0,0x206);
  param_1[0x187] = 0;
  _snwprintf(&local_220,99,L"%s%s\\",L"Img\\",PTR_DAT_1000d310);
  FUN_100020c4((int)param_1,&local_220);
  _Dst = (void *)__2_YAPAXI_Z(0xa4);
  param_1[0x18b] = _Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0xa4);
    param_1[0x18c] = 0x29;
  }
  iVar1 = __2_YAPAXI_Z(0x18);
  param_1[0x188] = iVar1;
  if (iVar1 != 0) {
    uVar2 = __2_YAPAXI_Z(0x18);
    param_1[0x189] = uVar2;
    memset((void *)param_1[0x188],0,0x18);
    param_1[0x18a] = 6;
  }
  FUN_10008094(local_18);
  return param_1;
}



/* 1000256c Unwind@1000256c */

/* Boundary evidence: original MIPS .pdata 1000256c..1000259b. Semantic name remains unreviewed. */

void Unwind_1000256c(void)

{
  int in_v0;
  
  FUN_10001f30(*(undefined4 **)(in_v0 + -0x228));
  return;
}



/* 1000259c FUN_1000259c */

/* Boundary evidence: original MIPS .pdata 1000259c..100025e7. Semantic name remains unreviewed. */

undefined4 * FUN_1000259c(undefined4 *param_1,uint param_2)

{
  FUN_10002118(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 100025e8 FUN_100025e8 */

undefined4 FUN_100025e8(void)

{
  return 1;
}



/* 100025f0 StartRVC */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 100025f0..100029df. Semantic name remains unreviewed.
   void __cdecl StartRVC(void) */

void StartRVC(void)

{
  LSTATUS LVar1;
  uint uVar2;
  DWORD local_38;
  HKEY local_34;
  DWORD local_30;
  uint local_2c;
  int local_28 [2];
  
                    /* 0x25f0  4  ?StartRVC@@YAXXZ */
  local_28[0] = 0;
  local_2c = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_34);
  if (LVar1 == 0) {
    local_38 = 4;
    local_30 = 4;
    LVar1 = RegQueryValueExW(local_34,L"UI_TYPE",(LPDWORD)0x0,&local_38,(LPBYTE)&local_2c,&local_30)
    ;
    if ((LVar1 != 0) || (local_38 != 4)) {
      local_2c = 0;
    }
    RegQueryValueExW(local_34,L"GUIDELINE_TYPE",(LPDWORD)0x0,&local_38,(LPBYTE)local_28,&local_30);
    RegQueryValueExW(local_34,L"RVC_BRIGHTNESS",(LPDWORD)0x0,&local_38,(LPBYTE)&DAT_1000d3d0,
                     &local_30);
    RegQueryValueExW(local_34,L"RVC_CONTRAST",(LPDWORD)0x0,&local_38,(LPBYTE)&DAT_1000d3d4,&local_30
                    );
    RegQueryValueExW(local_34,L"RVC_HUE",(LPDWORD)0x0,&local_38,(LPBYTE)&DAT_1000d3d8,&local_30);
    RegQueryValueExW(local_34,L"RVC_SATU",(LPDWORD)0x0,&local_38,(LPBYTE)&DAT_1000d3dc,&local_30);
    RegQueryValueExW(local_34,L"RVC_SATV",(LPDWORD)0x0,&local_38,(LPBYTE)&DAT_1000d3e0,&local_30);
    NKDbgPrintfW(L"StartRVC() !@!@[0x%08X,0x%08X,0x%08X,0x%08X,0x%08X]@!@! \r\n",DAT_1000d3d0,
                 DAT_1000d3d4,DAT_1000d3d8,DAT_1000d3dc,DAT_1000d3e0);
    if (0xe < DAT_1000d3d0) {
      DAT_1000d3d0 = 7;
    }
    if (0xe < DAT_1000d3d4) {
      DAT_1000d3d4 = 7;
    }
    if (0x48 < DAT_1000d3d8) {
      DAT_1000d3d8 = 0x24;
    }
    if (200 < DAT_1000d3dc) {
      DAT_1000d3dc = 0x80;
    }
    if (200 < DAT_1000d3e0) {
      DAT_1000d3e0 = 0x80;
    }
    RegCloseKey(local_34);
  }
  else {
    NKDbgPrintfW(L"REG OPEN ERROR !!!!!!@!@!@!@     \r\n");
  }
  if (1 < local_2c) {
    local_2c = 0;
  }
  if (DAT_1000ed78 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = DAT_1000ed78[0x187];
  }
  if ((local_2c != uVar2) && (DAT_1000ed78 != (int *)0x0)) {
    FUN_100022fc(DAT_1000ed78,local_2c);
  }
  if (DAT_1000eb48 != local_28[0]) {
    DAT_1000eb48 = local_28[0];
    if (DAT_1000ed68 != (HGDIOBJ)0x0) {
      DeleteObject(DAT_1000ed68);
      DAT_1000ed68 = (HGDIOBJ)0x0;
    }
  }
  if (DAT_1000eb4c == (HWND)0x0) {
    NKDbgPrintfW(L"[RVC] Start   Error!!!!        \r\n");
  }
  else {
    DAT_1000d3cc = 0xffffffff;
    DAT_1000d3c8 = 0xffffffff;
    SetWindowPos(DAT_1000eb4c,(HWND)0x0,0,0,800,0x1e0,0x44);
    ShowWindow(DAT_1000eb4c,5);
    InvalidateRect(DAT_1000eb4c,(RECT *)0x0,0);
    DAT_1000d3c8 = DAT_1000d3c8 & 0xfffffffd;
    FUN_10007224(0x1c,800,0x1e0,DAT_1000eb4c);
    FUN_1000703c(DAT_1000eb24,DAT_1000eb28);
    DAT_1000eb50 = DAT_1000eb50 + 1;
    NKDbgPrintfW(L"[RVC] Start !!!!       [%d]  \r\n");
  }
  DAT_1000ed70 = 1;
  return;
}



/* 100029e0 DrawRVC */

/* void __cdecl DrawRVC(struct HWND__ *) */

void DrawRVC(HWND__ *param_1)

{
                    /* 0x29e0  1  ?DrawRVC@@YAXPAUHWND__@@@Z */
  return;
}



/* 100029e8 GetRVCVersion */

/* Boundary evidence: original MIPS .pdata 100029e8..10002a07. Semantic name remains unreviewed.
   void __cdecl GetRVCVersion(char *,unsigned int) */

void GetRVCVersion(char *param_1,uint param_2)

{
                    /* 0x29e8  2  ?GetRVCVersion@@YAXPADI@Z */
  sprintf_s(param_1,param_2,"4.0.6");
  return;
}



/* 10002a08 FUN_10002a08 */

int FUN_10002a08(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_1000d3e4;
  iVar1 = 0;
  while ((((param_1 <= *piVar2 || (piVar2[2] <= param_1)) || (param_2 <= piVar2[1])) ||
         (piVar2[3] <= param_2))) {
    piVar2 = piVar2 + 4;
    iVar1 = iVar1 + 1;
    if (0x1000d443 < (int)piVar2) {
      return -1;
    }
  }
  return iVar1;
}



/* 10002a80 FUN_10002a80 */

/* Boundary evidence: original MIPS .pdata 10002a80..10002b4f. Semantic name remains unreviewed. */

undefined * FUN_10002a80(UINT param_1)

{
  wchar_t *pwVar1;
  
  if (DAT_1000eb44 == (HINSTANCE)0x0) {
    if (param_1 == 0x581) {
      pwVar1 = L"Off";
    }
    else if (param_1 == 0x582) {
      pwVar1 = L"On";
    }
    else if (param_1 == 0x59a) {
      pwVar1 = L"Please wait…";
    }
    else if (param_1 == 0x76c) {
      pwVar1 = L"Check Surroundings for Safety.";
    }
    else {
      if (param_1 != 0x76d) {
        return &DAT_1000eb54;
      }
      pwVar1 = L"Guide line";
    }
    wsprintfW((LPWSTR)&DAT_1000eb54,pwVar1);
  }
  else {
    LoadStringW(DAT_1000eb44,param_1,(LPWSTR)&DAT_1000eb54,0x104);
  }
  return &DAT_1000eb54;
}



/* 10002b50 FUN_10002b50 */

void FUN_10002b50(int param_1)

{
  DAT_1000eb20 = 0;
  if (0xe < DAT_1000d3d0) {
    DAT_1000d3d0 = 7;
  }
  DAT_1000eb24 = 0xe - DAT_1000d3d0;
  if (0xe < DAT_1000d3d4) {
    DAT_1000d3d4 = 7;
  }
  DAT_1000eb28 = 0xe - DAT_1000d3d4;
  if (param_1 != 0) {
    DAT_1000eb2c = 0;
    DAT_1000eb30 = 0x13;
    DAT_1000eb34 = 0x4f;
    DAT_1000eb38 = 0x13;
    DAT_1000eb3c = 0x4f;
  }
  return;
}



/* 10002bcc FUN_10002bcc */

/* Boundary evidence: original MIPS .pdata 10002bcc..100030ab. Semantic name remains unreviewed. */

void FUN_10002bcc(void)

{
  wchar_t *hFile;
  BOOL BVar1;
  HANDLE pvVar2;
  code *pcVar3;
  int *lpBuffer;
  int iVar4;
  DWORD DStack_48;
  int local_44;
  uint local_40;
  DWORD local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  hFile = CreateFileW(L"\\Storage Card2\\RVC_CFG_PARAM.DAT",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,
                      3,0x80,(HANDLE)0x0);
  if (hFile == (wchar_t *)0xffffffff) {
    FUN_10002b50(1);
    pvVar2 = CreateFileW(L"\\Storage Card2\\RvcData.bin",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                         0x80,(HANDLE)0x0);
    if (pvVar2 != (HANDLE)0xffffffff) {
      ReadFile(pvVar2,&local_44,4,&DStack_48,(LPOVERLAPPED)0x0);
      ReadFile(pvVar2,&local_40,4,&DStack_48,(LPOVERLAPPED)0x0);
      ReadFile(pvVar2,&local_3c,4,&DStack_48,(LPOVERLAPPED)0x0);
      if (1 < local_44) {
        local_44 = 0;
      }
      if (0xe < local_40) {
        local_40 = 7;
      }
      if (0xe < local_3c) {
        local_3c = 7;
      }
      DAT_1000eb20 = local_44;
      DAT_1000eb24 = local_40;
      DAT_1000eb28 = local_3c;
      CloseHandle(pvVar2);
      DeleteFileW(L"\\Storage Card2\\RvcData.bin");
    }
    pvVar2 = CreateFileW(L"\\Storage Card2\\GuideData.bin",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3
                         ,0x80,(HANDLE)0x0);
    if (pvVar2 == (HANDLE)0xffffffff) {
      DAT_1000e0dc = DAT_1000eb30;
      DAT_1000e0e0 = DAT_1000eb34;
      DAT_1000e0e4 = DAT_1000eb38;
      DAT_1000e0e8 = DAT_1000eb3c;
      DAT_1000ed6c = DAT_1000eb20;
      DAT_1000ed74 = DAT_1000eb2c;
      return;
    }
    memset(&local_38,0,0x10);
    lpBuffer = &local_38;
    iVar4 = 2;
    do {
      ReadFile(pvVar2,lpBuffer,4,&DStack_48,(LPOVERLAPPED)0x0);
      ReadFile(pvVar2,lpBuffer + 1,4,&DStack_48,(LPOVERLAPPED)0x0);
      iVar4 = iVar4 + -1;
      lpBuffer = lpBuffer + 2;
    } while (iVar4 != 0);
    ReadFile(pvVar2,&local_3c,4,&DStack_48,(LPOVERLAPPED)0x0);
    if (((int)local_3c < -0x2d) || (0x2d < (int)local_3c)) {
      local_3c = 0;
    }
    if ((local_38 < -0x1f) || (0x45 < local_38)) {
      local_38 = 0x13;
    }
    if ((local_34 < -0x15) || (0xb3 < local_34)) {
      local_34 = 0x4f;
    }
    if ((local_30 < -0x1f) || (0x45 < local_30)) {
      local_30 = 0x13;
    }
    if ((local_2c < -0x15) || (0xb3 < local_2c)) {
      local_2c = 0x4f;
    }
    DAT_1000eb2c = local_3c;
    DAT_1000eb30 = local_38;
    DAT_1000eb34 = local_34;
    DAT_1000eb38 = local_30;
    DAT_1000eb3c = local_2c;
    CloseHandle(pvVar2);
    hFile = L"\\Storage Card2\\GuideData.bin";
    pcVar3 = DeleteFileW_exref;
  }
  else {
    BVar1 = ReadFile(hFile,&DAT_1000eb20,0x20,&local_3c,(LPOVERLAPPED)0x0);
    if ((BVar1 == 0) || (local_3c != 0x20)) {
      NKDbgPrintfW(L"[ERROR] Load~~~ [%d][%d][%d] \r\n",BVar1,0x20);
      FUN_10002b50(1);
      pcVar3 = CloseHandle_exref;
    }
    else {
      if (1 < DAT_1000eb20) {
        DAT_1000eb20 = 0;
      }
      if (0xe < DAT_1000eb24) {
        DAT_1000eb24 = 7;
      }
      if (0xe < DAT_1000eb28) {
        DAT_1000eb28 = 7;
      }
      if (((int)DAT_1000eb2c < -0x2d) || (0x2d < (int)DAT_1000eb2c)) {
        DAT_1000eb2c = 0;
      }
      if ((DAT_1000eb30 < -0x1f) || (0x45 < DAT_1000eb30)) {
        DAT_1000eb30 = 0x13;
      }
      if ((DAT_1000eb34 < -0x15) || (0xb3 < DAT_1000eb34)) {
        DAT_1000eb34 = 0x4f;
      }
      if ((DAT_1000eb38 < -0x1f) || (0x45 < DAT_1000eb38)) {
        DAT_1000eb38 = 0x13;
      }
      pcVar3 = CloseHandle_exref;
      if ((DAT_1000eb3c < -0x15) || (0xb3 < DAT_1000eb3c)) {
        DAT_1000eb3c = 0x4f;
      }
    }
  }
  (*pcVar3)(hFile);
  DAT_1000ed74 = DAT_1000eb2c;
  DAT_1000ed6c = DAT_1000eb20;
  DAT_1000e0dc = DAT_1000eb30;
  DAT_1000e0e0 = DAT_1000eb34;
  DAT_1000e0e4 = DAT_1000eb38;
  DAT_1000e0e8 = DAT_1000eb3c;
  return;
}



/* 100030ac FUN_100030ac */

/* Boundary evidence: original MIPS .pdata 100030ac..10003243. Semantic name remains unreviewed. */

void FUN_100030ac(void)

{
  HANDLE pvVar1;
  int iVar2;
  BOOL BVar3;
  DWORD local_50 [2];
  undefined1 auStack_48 [32];
  
  pvVar1 = CreateFileW(L"\\Storage Card2\\RVC_CFG_PARAM.DAT",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0
                       ,3,0x80,(HANDLE)0x0);
  memset(auStack_48,0,0x20);
  if (pvVar1 != (HANDLE)0xffffffff) {
    ReadFile(pvVar1,auStack_48,0x20,local_50,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar1);
  }
  iVar2 = memcmp(&DAT_1000eb20,auStack_48,0x20);
  if (iVar2 == 0) {
    NKDbgPrintfW(L"[INFO] RVC configuration Not changed!!!\r\n");
  }
  else {
    pvVar1 = CreateFileW(L"\\Storage Card2\\RVC_CFG_PARAM.DAT",0x40000000,0,
                         (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
    if (pvVar1 != (HANDLE)0xffffffff) {
      BVar3 = WriteFile(pvVar1,&DAT_1000eb20,0x20,local_50,(LPOVERLAPPED)0x0);
      if ((BVar3 == 0) || (local_50[0] != 0x20)) {
        NKDbgPrintfW(L"[ERROR] Save~~~ [%d][%d][%d] \r\n",BVar3,0x20);
      }
      CloseHandle(pvVar1);
    }
  }
  return;
}



/* 10003244 FUN_10003244 */

/* Boundary evidence: original MIPS .pdata 10003244..10003553. Semantic name remains unreviewed. */

HBITMAP FUN_10003244(HDC param_1,HRESULT param_2,int param_3,int param_4)

{
  int iVar1;
  HDC hdc;
  HGDIOBJ h;
  wchar_t *pwVar2;
  HBITMAP h_00;
  int *local_280;
  int *local_27c;
  undefined4 local_278;
  undefined4 local_274;
  int local_270;
  int local_26c;
  undefined1 auStack_268 [20];
  int local_254;
  int local_250;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_1000da9c;
  h_00 = (HBITMAP)0x0;
  if (param_2 == 0) goto LAB_10003524;
  if (param_2 == 1) {
    pwVar2 = L"\\Storage Card\\system\\img\\rvc\\J87\\%d.png";
LAB_100032f0:
    swprintf(awStack_228,(size_t)pwVar2,(wchar_t *)(param_3 + 0x2d));
    local_280 = (int *)0x0;
    local_27c = (int *)0x0;
    param_2 = CoInitializeEx((LPVOID)0x0,0);
    if (param_2 < 0) {
      pwVar2 = L"[ERROR] %s     CoInitializeEx() failed... hr[0x%08X]\r\n";
    }
    else {
      param_2 = CoCreateInstance((IID *)&DAT_10009db0,(LPUNKNOWN)0x0,1,(IID *)&DAT_10009da0,
                                 &local_27c);
      if ((-1 < param_2) && (local_27c != (int *)0x0)) {
        iVar1 = (**(code **)(*local_27c + 0x10))(local_27c,awStack_228,&local_280);
        if ((-1 < iVar1) && (local_280 != (int *)0x0)) {
          iVar1 = (**(code **)(*local_280 + 0x10))(local_280,auStack_268);
          if (-1 < iVar1) {
            hdc = CreateCompatibleDC(param_1);
            h_00 = CreateCompatibleBitmap(param_1,local_254,local_250);
            if (h_00 == (HBITMAP)0x0) {
              NKDbgPrintfW(L"[ERROR] %s     CreateCompatibleBitmap() failed \r\n","DoLoadImage");
            }
            else {
              local_278 = 0;
              local_274 = 0;
              local_270 = local_254;
              local_26c = local_250;
              h = SelectObject(hdc,h_00);
              (**(code **)(*local_280 + 0x18))(local_280,hdc,&local_278,0);
              if (param_4 != 0) {
                BitBlt(param_1,0,0,local_254,local_250,hdc,0,0,0xcc0020);
              }
              SelectObject(hdc,h);
            }
            DeleteDC(hdc);
          }
          (**(code **)(*local_280 + 8))();
          local_280 = (int *)0x0;
          (**(code **)(*local_27c + 8))();
          local_27c = (int *)0x0;
          CoUninitialize();
          FUN_10008094(local_20);
          return h_00;
        }
        NKDbgPrintfW(L"[ERROR] %s     CreateImageFromFile() failed... hr[0x%08X], szImgPath[%s], pImage[0x%08X]\r\n"
                     ,"DoLoadImage",iVar1,awStack_228,local_280);
        goto LAB_10003524;
      }
      pwVar2 = L"[ERROR] %s     CoCreateInstance() failed... hr[0x%08X]\r\n";
    }
  }
  else {
    if (param_2 == 2) {
      pwVar2 = L"\\Storage Card\\system\\img\\rvc\\B98\\%d.png";
      goto LAB_100032f0;
    }
    if (param_2 == 3) {
      pwVar2 = L"\\Storage Card\\system\\img\\rvc\\K98\\%d.png";
      goto LAB_100032f0;
    }
    if (param_2 == 4) {
      pwVar2 = L"\\Storage Card\\system\\img\\rvc\\H79\\%d.png";
      goto LAB_100032f0;
    }
    if (param_2 == 9) {
      pwVar2 = L"\\Storage Card\\system\\img\\rvc\\J92\\%d.png";
      goto LAB_100032f0;
    }
    pwVar2 = L"[ERROR] %s     Not supported!!! Guideline type[%d]\r\n";
  }
  NKDbgPrintfW(pwVar2,"DoLoadImage",param_2);
LAB_10003524:
  FUN_10008094(local_20);
  return (HBITMAP)0x0;
}



/* 10003554 FUN_10003554 */

/* Boundary evidence: original MIPS .pdata 10003554..1000370f. Semantic name remains unreviewed. */

void FUN_10003554(int param_1)

{
  HDC hDC;
  HBRUSH hbr;
  HFONT h;
  HGDIOBJ h_00;
  LPCWSTR lpchText;
  UINT format;
  tagRECT local_a0;
  RECT local_90;
  LOGFONTW local_80;
  uint local_24;
  
  local_24 = DAT_1000da9c;
  local_90.left = 0;
  local_90.top = 0;
  local_90.right = 800;
  local_90.bottom = 0x1e0;
  hDC = GetDC(DAT_1000eb4c);
  hbr = GetStockObject(4);
  FillRect(hDC,&local_90,hbr);
  if (param_1 != 0) {
    format = 5;
    memset(&local_80,0,0x5c);
    SetBkMode(hDC,1);
    SetTextColor(hDC,0xfefefe);
    local_80.lfWeight = 700;
    local_80.lfHeight = 0x28;
    local_80.lfWidth = 0;
    local_80.lfEscapement = 0;
    local_80.lfOrientation = 0;
    local_80.lfItalic = '\0';
    local_80.lfUnderline = '\0';
    local_80.lfStrikeOut = '\0';
    local_80.lfCharSet = '\0';
    local_80.lfOutPrecision = '\0';
    local_80.lfQuality = '\x06';
    local_80.lfPitchAndFamily = '\x02';
    local_80.lfClipPrecision = '\0';
    wsprintfW(local_80.lfFaceName,L"Tahoma");
    h = CreateFontIndirectW(&local_80);
    h_00 = SelectObject(hDC,h);
    local_a0.left = 0;
    local_a0.top = 0;
    local_a0.right = 800;
    local_a0.bottom = 0x1e0;
    if ((DAT_1000d3c4 == 0) || (DAT_1000d3c4 == 0x15)) {
      format = 0x20005;
    }
    lpchText = (LPCWSTR)FUN_10002a80(0x59a);
    DrawTextW(hDC,lpchText,-1,&local_a0,format);
    SelectObject(hDC,h_00);
    DeleteObject(h);
  }
  ReleaseDC(DAT_1000eb4c,hDC);
  FUN_10008094(local_24);
  return;
}



/* 10003710 StopRVC */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 10003710..100037b3. Semantic name remains unreviewed.
   void __cdecl StopRVC(void) */

void StopRVC(void)

{
                    /* 0x3710  5  ?StopRVC@@YAXXZ */
  if (DAT_1000eb4c == (HWND)0x0) {
    NKDbgPrintfW(L"[RVC] End !!!!       [Error]  \r\n");
  }
  else {
    FUN_10003554(0);
    SetWindowPos(DAT_1000eb4c,(HWND)0x0,0,0,0,0,0x86);
    ShowWindow(DAT_1000eb4c,0);
    FUN_10006e5c();
    DAT_1000eb50 = DAT_1000eb50 + -1;
    NKDbgPrintfW(L"[RVC] End !!!!       [%d]  \r\n");
  }
  DAT_1000ed70 = 0;
  return;
}



/* 100037b4 FUN_100037b4 */

/* Boundary evidence: original MIPS .pdata 100037b4..100038af. Semantic name remains unreviewed. */

undefined4 FUN_100037b4(HDC param_1,int *param_2)

{
  HDC hdc;
  HGDIOBJ h;
  
  if (DAT_1000ed68 == (HBITMAP)0x0) {
    DAT_1000ed68 = FUN_10003244(param_1,DAT_1000eb48,DAT_1000ed74,1);
    if (DAT_1000ed68 == (HBITMAP)0x0) {
      return 0;
    }
  }
  else {
    hdc = CreateCompatibleDC(param_1);
    h = SelectObject(hdc,DAT_1000ed68);
    BitBlt(param_1,0,0,param_2[2] - *param_2,param_2[3] - param_2[1],hdc,0,0,0xcc0020);
    SelectObject(hdc,h);
    DeleteDC(hdc);
  }
  return 1;
}



/* 100038b0 FUN_100038b0 */

/* Boundary evidence: original MIPS .pdata 100038b0..10004dc7. Semantic name remains unreviewed. */

void FUN_100038b0(HDC param_1)

{
  HDC hdc;
  HBRUSH pHVar1;
  HDC hdc_00;
  HBITMAP h;
  HGDIOBJ pvVar2;
  int iVar3;
  HFONT pHVar4;
  HGDIOBJ h_00;
  size_t cchString;
  int iVar5;
  COLORREF CVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  UINT format;
  tagSIZE local_e8;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  tagRECT local_d0;
  int local_c0 [4];
  RECT local_b0;
  undefined1 auStack_a0 [4];
  int local_9c;
  int local_98;
  LOGFONTW local_88;
  uint local_2c;
  
  local_2c = DAT_1000da9c;
  hdc = CreateCompatibleDC(param_1);
  SetBkMode(param_1,1);
  iVar9 = 0x1e0;
  if ((DAT_1000d3c8 & 1) != 0) {
    local_b0.left = 0;
    local_b0.top = 0;
    local_b0.right = 800;
    local_b0.bottom = 0x1e0;
    pHVar1 = GetStockObject(4);
    FillRect(param_1,&local_b0,pHVar1);
  }
  if ((DAT_1000d3c8 & 2) != 0) {
    pHVar1 = CreateSolidBrush(0x80000);
    FillRect(param_1,(RECT *)&DAT_1000d494,pHVar1);
    if ((DAT_1000ed6c != 0) && (DAT_1000eb48 != 0)) {
      local_c0[0] = 0;
      local_c0[1] = 0;
      local_c0[2] = 0x347;
      local_c0[3] = 0x347;
      hdc_00 = CreateCompatibleDC(param_1);
      h = CreateCompatibleBitmap(param_1,0x347,0x27b);
      pvVar2 = SelectObject(hdc_00,h);
      iVar3 = FUN_100037b4(hdc_00,local_c0);
      if (iVar3 != 0) {
        BitBlt(param_1,DAT_1000d494,DAT_1000d498,DAT_1000d49c - DAT_1000d494,
               DAT_1000d4a0 - DAT_1000d498,hdc_00,DAT_1000e0dc,DAT_1000e0e0,0xcc0020);
      }
      SelectObject(hdc_00,pvVar2);
      DeleteObject(h);
      DeleteDC(hdc_00);
    }
    DeleteObject(pHVar1);
  }
  if ((DAT_1000d3c8 & 4) != 0) {
    if (DAT_1000ed78 == (int *)0x0) {
      pvVar2 = (HGDIOBJ)0x0;
    }
    else {
      pvVar2 = (HGDIOBJ)FUN_10002360(DAT_1000ed78,0x1f);
    }
    pvVar2 = SelectObject(hdc,pvVar2);
    if (DAT_1000eb48 == 0) {
      uVar7 = 0xb8;
    }
    else if ((DAT_1000d3cc == 0) || (DAT_1000ed6c == 0)) {
      uVar7 = 0x5c;
    }
    else {
      uVar7 = 0;
    }
    TransparentImage(param_1,DAT_1000d3e4,DAT_1000d3e8,DAT_1000d3ec - DAT_1000d3e4,
                     DAT_1000d3f0 - DAT_1000d3e8,hdc,uVar7,0,0x5c,0x44,0xffff00);
    SelectObject(hdc,pvVar2);
  }
  if ((DAT_1000d3c8 & 8) != 0) {
    if (DAT_1000ed78 == (int *)0x0) {
      pvVar2 = (HGDIOBJ)0x0;
    }
    else {
      pvVar2 = (HGDIOBJ)FUN_10002360(DAT_1000ed78,0x20);
    }
    pvVar2 = SelectObject(hdc,pvVar2);
    if (DAT_1000eb48 == 0) {
      uVar7 = 0xb6;
    }
    else if ((DAT_1000d3cc == 1) || (uVar7 = 0, DAT_1000ed6c == 1)) {
      uVar7 = 0x5b;
    }
    TransparentImage(param_1,DAT_1000d3f4,DAT_1000d3f8,DAT_1000d3fc - DAT_1000d3f4,
                     DAT_1000d400 - DAT_1000d3f8,hdc,uVar7,0,0x5b,0x44,0xffff00);
    SelectObject(hdc,pvVar2);
  }
  if ((DAT_1000d3c8 & 0x10) != 0) {
    if (DAT_1000ed78 == (int *)0x0) {
      pvVar2 = (HGDIOBJ)0x0;
    }
    else {
      pvVar2 = (HGDIOBJ)FUN_10002360(DAT_1000ed78,0x21);
    }
    pvVar2 = SelectObject(hdc,pvVar2);
    uVar7 = 0x59;
    if (DAT_1000d3cc != 2) {
      uVar7 = 0;
    }
    TransparentImage(param_1,DAT_1000d404,DAT_1000d408,DAT_1000d40c - DAT_1000d404,
                     DAT_1000d410 - DAT_1000d408,hdc,uVar7,0,0x59,0x43,0xffff00);
    SelectObject(hdc,pvVar2);
  }
  if ((DAT_1000d3c8 & 0x20) != 0) {
    if (DAT_1000ed78 == (int *)0x0) {
      pvVar2 = (HGDIOBJ)0x0;
    }
    else {
      pvVar2 = (HGDIOBJ)FUN_10002360(DAT_1000ed78,0x22);
    }
    pvVar2 = SelectObject(hdc,pvVar2);
    if (DAT_1000d3cc == 3) {
      uVar7 = 0x59;
    }
    else {
      uVar7 = 0;
    }
    TransparentImage(param_1,DAT_1000d414,DAT_1000d418,DAT_1000d41c - DAT_1000d414,
                     DAT_1000d420 - DAT_1000d418,hdc,uVar7,0,0x59,0x43,0xffff00);
    SelectObject(hdc,pvVar2);
  }
  if ((DAT_1000d3c8 & 0x40) != 0) {
    if (DAT_1000ed78 == (int *)0x0) {
      pvVar2 = (HGDIOBJ)0x0;
    }
    else {
      pvVar2 = (HGDIOBJ)FUN_10002360(DAT_1000ed78,0x21);
    }
    pvVar2 = SelectObject(hdc,pvVar2);
    if (DAT_1000d3cc == 4) {
      uVar7 = 0x59;
    }
    else {
      uVar7 = 0;
    }
    TransparentImage(param_1,DAT_1000d424,DAT_1000d428,DAT_1000d42c - DAT_1000d424,
                     DAT_1000d430 - DAT_1000d428,hdc,uVar7,0,0x59,0x43,0xffff00);
    SelectObject(hdc,pvVar2);
  }
  if ((DAT_1000d3c8 & 0x80) != 0) {
    if (DAT_1000ed78 == (int *)0x0) {
      pvVar2 = (HGDIOBJ)0x0;
    }
    else {
      pvVar2 = (HGDIOBJ)FUN_10002360(DAT_1000ed78,0x22);
    }
    pvVar2 = SelectObject(hdc,pvVar2);
    if (DAT_1000d3cc == 5) {
      uVar7 = 0x59;
    }
    else {
      uVar7 = 0;
    }
    TransparentImage(param_1,DAT_1000d434,DAT_1000d438,DAT_1000d43c - DAT_1000d434,
                     DAT_1000d440 - DAT_1000d438,hdc,uVar7,0,0x59,0x43,0xffff00);
    SelectObject(hdc,pvVar2);
  }
  pvVar2 = SelectObject(hdc,(HGDIOBJ)0x0);
  SelectObject(hdc,pvVar2);
  if ((DAT_1000d3c8 & 0x100) != 0) {
    pvVar2 = SelectObject(hdc,(HGDIOBJ)0x0);
    SelectObject(hdc,pvVar2);
  }
  if ((DAT_1000d3c8 & 0x200) != 0) {
    pvVar2 = SelectObject(hdc,(HGDIOBJ)0x0);
    SelectObject(hdc,pvVar2);
  }
  if (DAT_1000ed78 == (int *)0x0) {
    pvVar2 = (HGDIOBJ)0x0;
  }
  else {
    pvVar2 = (HGDIOBJ)FUN_10002360(DAT_1000ed78,0x28);
  }
  pvVar2 = SelectObject(hdc,pvVar2);
  BitBlt(param_1,DAT_1000d4a4,DAT_1000d4a8,DAT_1000d4ac - DAT_1000d4a4,DAT_1000d4b0 - DAT_1000d4a8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d4b4,DAT_1000d4b8,DAT_1000d4bc - DAT_1000d4b4,DAT_1000d4c0 - DAT_1000d4b8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d4c4,DAT_1000d4c8,DAT_1000d4cc - DAT_1000d4c4,DAT_1000d4d0 - DAT_1000d4c8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d4d4,DAT_1000d4d8,DAT_1000d4dc - DAT_1000d4d4,DAT_1000d4e0 - DAT_1000d4d8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d4e4,DAT_1000d4e8,DAT_1000d4ec - DAT_1000d4e4,DAT_1000d4f0 - DAT_1000d4e8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d4f4,DAT_1000d4f8,DAT_1000d4fc - DAT_1000d4f4,DAT_1000d500 - DAT_1000d4f8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d504,DAT_1000d508,DAT_1000d50c - DAT_1000d504,DAT_1000d510 - DAT_1000d508,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d514,DAT_1000d518,DAT_1000d51c - DAT_1000d514,DAT_1000d520 - DAT_1000d518,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d524,DAT_1000d528,DAT_1000d52c - DAT_1000d524,DAT_1000d530 - DAT_1000d528,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d534,DAT_1000d538,DAT_1000d53c - DAT_1000d534,DAT_1000d540 - DAT_1000d538,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d544,DAT_1000d548,DAT_1000d54c - DAT_1000d544,DAT_1000d550 - DAT_1000d548,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d554,DAT_1000d558,DAT_1000d55c - DAT_1000d554,DAT_1000d560 - DAT_1000d558,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d564,DAT_1000d568,DAT_1000d56c - DAT_1000d564,DAT_1000d570 - DAT_1000d568,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d574,DAT_1000d578,DAT_1000d57c - DAT_1000d574,DAT_1000d580 - DAT_1000d578,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d584,DAT_1000d588,DAT_1000d58c - DAT_1000d584,DAT_1000d590 - DAT_1000d588,
         hdc,0,0,0xcc0020);
  if (DAT_1000eb24 < 0xf) {
    BitBlt(param_1,(&DAT_1000d4a4)[DAT_1000eb24 * 4],(&DAT_1000d4a8)[DAT_1000eb24 * 4],
           (&DAT_1000d4ac)[DAT_1000eb24 * 4] - (&DAT_1000d4a4)[DAT_1000eb24 * 4],
           (&DAT_1000d4b0)[DAT_1000eb24 * 4] - (&DAT_1000d4a8)[DAT_1000eb24 * 4],hdc,0x2f,0,0xcc0020
          );
  }
  BitBlt(param_1,DAT_1000d594,DAT_1000d598,DAT_1000d59c - DAT_1000d594,DAT_1000d5a0 - DAT_1000d598,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d5a4,DAT_1000d5a8,DAT_1000d5ac - DAT_1000d5a4,DAT_1000d5b0 - DAT_1000d5a8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d5b4,DAT_1000d5b8,DAT_1000d5bc - DAT_1000d5b4,DAT_1000d5c0 - DAT_1000d5b8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d5c4,DAT_1000d5c8,DAT_1000d5cc - DAT_1000d5c4,DAT_1000d5d0 - DAT_1000d5c8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d5d4,DAT_1000d5d8,DAT_1000d5dc - DAT_1000d5d4,DAT_1000d5e0 - DAT_1000d5d8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d5e4,DAT_1000d5e8,DAT_1000d5ec - DAT_1000d5e4,DAT_1000d5f0 - DAT_1000d5e8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d5f4,DAT_1000d5f8,DAT_1000d5fc - DAT_1000d5f4,DAT_1000d600 - DAT_1000d5f8,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d604,DAT_1000d608,DAT_1000d60c - DAT_1000d604,DAT_1000d610 - DAT_1000d608,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d614,DAT_1000d618,DAT_1000d61c - DAT_1000d614,DAT_1000d620 - DAT_1000d618,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d624,DAT_1000d628,DAT_1000d62c - DAT_1000d624,DAT_1000d630 - DAT_1000d628,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d634,DAT_1000d638,DAT_1000d63c - DAT_1000d634,DAT_1000d640 - DAT_1000d638,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d644,DAT_1000d648,DAT_1000d64c - DAT_1000d644,DAT_1000d650 - DAT_1000d648,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d654,DAT_1000d658,DAT_1000d65c - DAT_1000d654,DAT_1000d660 - DAT_1000d658,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d664,DAT_1000d668,DAT_1000d66c - DAT_1000d664,DAT_1000d670 - DAT_1000d668,
         hdc,0,0,0xcc0020);
  BitBlt(param_1,DAT_1000d674,DAT_1000d678,DAT_1000d67c - DAT_1000d674,DAT_1000d680 - DAT_1000d678,
         hdc,0,0,0xcc0020);
  if (DAT_1000eb28 < 0xf) {
    BitBlt(param_1,(&DAT_1000d594)[DAT_1000eb28 * 4],(&DAT_1000d598)[DAT_1000eb28 * 4],
           (&DAT_1000d59c)[DAT_1000eb28 * 4] - (&DAT_1000d594)[DAT_1000eb28 * 4],
           (&DAT_1000d5a0)[DAT_1000eb28 * 4] - (&DAT_1000d598)[DAT_1000eb28 * 4],hdc,0x2f,0,0xcc0020
          );
  }
  SelectObject(hdc,pvVar2);
  local_d0.right = 0x12a;
  local_d0.left = 0x6e;
  local_d0.top = 0x12;
  local_d0.bottom = 0x2d;
  memset(&local_88,0,0x5c);
  local_88.lfWeight = 700;
  local_88.lfPitchAndFamily = '\x02';
  local_88.lfHeight = 0x1c;
  local_88.lfWidth = 0;
  local_88.lfEscapement = 0;
  local_88.lfOrientation = 0;
  local_88.lfItalic = '\0';
  local_88.lfUnderline = '\0';
  local_88.lfStrikeOut = '\0';
  local_88.lfCharSet = '\0';
  local_88.lfOutPrecision = '\0';
  local_88.lfQuality = '\x06';
  local_88.lfClipPrecision = '\0';
  wsprintfW(local_88.lfFaceName,L"Tahoma");
  pHVar4 = CreateFontIndirectW(&local_88);
  pvVar2 = SelectObject(param_1,pHVar4);
  SetTextColor(param_1,0xfefefe);
  h_00 = SelectObject(hdc,(HGDIOBJ)0x0);
  GetObjectW((HANDLE)0x0,0x18,auStack_a0);
  cchString = wcslen((wchar_t *)&DAT_1000e70c);
  GetTextExtentExPointW(param_1,(LPCWSTR)&DAT_1000e70c,cchString,0,(LPINT)0x0,(LPINT)0x0,&local_e8);
  iVar3 = local_98;
  if (DAT_1000eb48 == 2) {
    iVar8 = 0;
    iVar9 = 0x1e;
  }
  else if (DAT_1000eb48 == 9) {
    iVar8 = 0x1c2;
  }
  else {
    iVar8 = 0x1a4;
    iVar9 = 0x1df;
  }
  iVar5 = (600 - local_e8.cx) - local_9c >> 1;
  iVar8 = ((iVar9 - local_98) - iVar8 >> 1) + iVar8;
  iVar9 = iVar5 + local_9c;
  local_dc = iVar8 + -2;
  local_e0 = iVar9 + 2;
  local_d8 = local_e0 + local_e8.cx;
  local_d4 = local_e8.cy + local_dc + 2;
  if ((DAT_1000d3c4 == 0) || (DAT_1000d3c4 == 0x15)) {
    format = 0x20006;
  }
  else {
    format = 6;
  }
  GetStockObject(4);
  TransparentImage(param_1,iVar5,iVar8,iVar9 - iVar5,iVar3,hdc,0,0,local_9c,local_98,0xffff00);
  DrawTextW(param_1,(LPCWSTR)&DAT_1000e504,-1,&local_d0,format);
  SelectObject(hdc,h_00);
  SelectObject(param_1,pvVar2);
  DeleteObject(pHVar4);
  if (DAT_1000d3c4 == 0x16) {
    local_88.lfHeight = 0x1e;
  }
  else if (((DAT_1000d3c4 == 0x14) || (DAT_1000d3c4 == 0x1a)) || (DAT_1000d3c4 == 0xe)) {
    local_88.lfWeight = 400;
    local_88.lfHeight = 0x1a;
  }
  else if (DAT_1000d3c4 == 0xf) {
    local_88.lfWeight = 400;
    local_88.lfHeight = 0x17;
  }
  else {
    local_88.lfHeight = 0x20;
  }
  pHVar4 = CreateFontIndirectW(&local_88);
  pvVar2 = SelectObject(param_1,pHVar4);
  CVar6 = 0x7d7d7d;
  if ((DAT_1000d3c8 & 4) != 0) {
    if (DAT_1000eb48 != 0) {
      if ((DAT_1000d3cc == 0) || (DAT_1000ed6c == 0)) {
        CVar6 = 0x40404;
      }
      else {
        CVar6 = 0xfefefe;
      }
    }
    SetTextColor(param_1,CVar6);
  }
  if ((DAT_1000d3c8 & 8) != 0) {
    if (DAT_1000eb48 == 0) {
      CVar6 = 0x7d7d7d;
    }
    else if ((DAT_1000d3cc == 1) || (DAT_1000ed6c == 1)) {
      CVar6 = 0x40404;
    }
    else {
      CVar6 = 0xfefefe;
    }
    SetTextColor(param_1,CVar6);
  }
  SelectObject(param_1,pvVar2);
  DeleteObject(pHVar4);
  DeleteDC(hdc);
  DAT_1000d3c8 = 0;
  FUN_10008094(local_2c);
  return;
}



/* 10004dc8 FUN_10004dc8 */

/* Boundary evidence: original MIPS .pdata 10004dc8..10006783. Semantic name remains unreviewed. */

LRESULT FUN_10004dc8(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  HDC pHVar1;
  HANDLE hFile;
  LSTATUS LVar2;
  BOOL BVar3;
  int iVar4;
  DWORD DVar5;
  LPCWSTR pWVar6;
  LRESULT LVar7;
  wchar_t *pwVar8;
  RECT *pRVar9;
  int *piVar10;
  uint local_f0;
  HKEY local_ec;
  HKEY local_e8;
  undefined4 *local_e4;
  DWORD local_e0;
  uint local_dc;
  HKEY local_d8;
  DWORD local_d4 [3];
  undefined1 auStack_c8 [80];
  uint local_78;
  tagPAINTSTRUCT tStack_70;
  uint local_30;
  
  local_30 = DAT_1000da9c;
  if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      iVar4 = FUN_10002a08(param_4 & 0xffff,param_4 >> 0x10);
      DVar5 = GetTickCount();
      if (DVar5 - DAT_1000eb1c < 0xfa) {
        pwVar8 = L"[RVC]   ------   Exit WM_LBUTTONDOWN +_+_+_+_    \r\n";
LAB_10005614:
        NKDbgPrintfW(pwVar8);
        goto LAB_10006740;
      }
      if (iVar4 == -1) goto LAB_10006740;
      DAT_1000d3cc = iVar4;
      if (iVar4 == 0) {
        if (DAT_1000eb48 == 0) {
LAB_100057a4:
          DAT_1000d3cc = -1;
          goto LAB_10006740;
        }
        DAT_1000d3c8 = DAT_1000d3c8 | 4;
        pRVar9 = (RECT *)&DAT_1000d3e4;
      }
      else {
        if (iVar4 != 1) {
          if (iVar4 == 2) {
            SetTimer(param_1,1000,0xfa,(TIMERPROC)0x0);
            DAT_1000d3c8 = DAT_1000d3c8 | 0x10;
            pRVar9 = (RECT *)&DAT_1000d404;
          }
          else {
            if (iVar4 != 3) {
              if (iVar4 == 4) {
                SetTimer(param_1,1000,0xfa,(TIMERPROC)0x0);
                DAT_1000d3c8 = DAT_1000d3c8 | 0x40;
                pRVar9 = (RECT *)&DAT_1000d424;
              }
              else {
                if (iVar4 != 5) goto LAB_10006740;
                SetTimer(param_1,1000,0xfa,(TIMERPROC)0x0);
                DAT_1000d3c8 = DAT_1000d3c8 | 0x80;
                pRVar9 = (RECT *)&DAT_1000d434;
              }
              InvalidateRect(param_1,pRVar9,0);
              goto LAB_10004ed8;
            }
            SetTimer(param_1,1000,0xfa,(TIMERPROC)0x0);
            DAT_1000d3c8 = DAT_1000d3c8 | 0x20;
            pRVar9 = (RECT *)&DAT_1000d414;
          }
          InvalidateRect(param_1,pRVar9,0);
          goto LAB_10005d68;
        }
        if (DAT_1000eb48 == 0) goto LAB_100057a4;
        DAT_1000d3c8 = DAT_1000d3c8 | 8;
        pRVar9 = (RECT *)&DAT_1000d3f4;
      }
LAB_10005d70:
      InvalidateRect(param_1,pRVar9,0);
      goto LAB_10006740;
    }
    if (param_2 != 1) {
      if (param_2 == 2) {
        SelectObject(DAT_1000ed5c,DAT_1000e0ec);
        DeleteObject(DAT_1000e0f0);
        DeleteDC(DAT_1000ed5c);
        if (DAT_1000ed78 != (int *)0x0) {
          (**(code **)(*DAT_1000ed78 + 8))(DAT_1000ed78,1);
          DAT_1000ed78 = (int *)0x0;
        }
        goto LAB_10006740;
      }
      if (param_2 == 8) {
        DAT_1000d3c8 = 0xffffffff;
        goto LAB_10006740;
      }
      if (param_2 == 0xf) {
        pHVar1 = BeginPaint(param_1,&tStack_70);
        FUN_100038b0(DAT_1000ed5c);
        BitBlt(pHVar1,tStack_70.rcPaint.left,tStack_70.rcPaint.top,
               tStack_70.rcPaint.right - tStack_70.rcPaint.left,
               tStack_70.rcPaint.bottom - tStack_70.rcPaint.top,DAT_1000ed5c,tStack_70.rcPaint.left,
               tStack_70.rcPaint.top,0xcc0020);
        EndPaint(param_1,&tStack_70);
        goto LAB_10006740;
      }
      if (param_2 != 0x113) goto LAB_100057f8;
      if (param_3 != 1000) goto LAB_10006740;
      if (DAT_1000d3cc == 2) {
        DAT_1000d3c8 = DAT_1000d3c8 | 0x10;
        if (DAT_1000eb24 != 0) {
          DAT_1000eb24 = DAT_1000eb24 - 1;
LAB_10005d60:
          FUN_10007058(DAT_1000eb24);
        }
      }
      else {
        if (DAT_1000d3cc != 3) {
          if (DAT_1000d3cc == 4) {
            DAT_1000d3c8 = DAT_1000d3c8 | 0x40;
            if (DAT_1000eb28 != 0) {
              DAT_1000eb28 = DAT_1000eb28 - 1;
LAB_10004ed0:
              FUN_10007074(DAT_1000eb28);
            }
          }
          else {
            if (DAT_1000d3cc != 5) goto LAB_10006740;
            DAT_1000d3c8 = DAT_1000d3c8 | 0x80;
            if (DAT_1000eb28 < 0xe) {
              DAT_1000eb28 = DAT_1000eb28 + 1;
              goto LAB_10004ed0;
            }
          }
LAB_10004ed8:
          pRVar9 = (RECT *)&DAT_1000d6a4;
          goto LAB_10005d70;
        }
        DAT_1000d3c8 = DAT_1000d3c8 | 0x20;
        if (DAT_1000eb24 < 0xe) {
          DAT_1000eb24 = DAT_1000eb24 + 1;
          goto LAB_10005d60;
        }
      }
LAB_10005d68:
      pRVar9 = (RECT *)&DAT_1000d694;
      goto LAB_10005d70;
    }
    local_f0 = 0;
    hFile = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                        0x80,(HANDLE)0x0);
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_d8);
    if (LVar2 == 0) {
      local_e0 = 4;
      local_d4[0] = 4;
      LVar2 = RegQueryValueExW(local_d8,L"UI_TYPE",(LPDWORD)0x0,&local_e0,(LPBYTE)&local_f0,local_d4
                              );
      if ((LVar2 != 0) || (local_e0 != 4)) {
        local_f0 = 0;
      }
      RegCloseKey(local_d8);
    }
    if (1 < local_f0) {
      local_f0 = 0;
    }
    if (DAT_1000ed78 == (int *)0x0) {
      local_e4 = (undefined4 *)__2_YAPAXI_Z(0x634);
      if (local_e4 == (undefined4 *)0x0) {
        DAT_1000ed78 = (int *)0x0;
      }
      else {
        DAT_1000ed78 = FUN_1000245c(local_e4);
      }
      if (DAT_1000ed78 != (int *)0x0) {
        FUN_100022fc(DAT_1000ed78,local_f0);
      }
    }
    if (hFile == (HANDLE)0xffffffff) {
      DAT_1000eb44 = LoadLibraryW(L"\\Storage Card\\system\\data\\LangDllEng.dll");
    }
    else {
      local_e4 = (undefined4 *)0x4;
      local_d4[1] = 4;
      memset(auStack_c8,0,0x55);
      BVar3 = ReadFile(hFile,auStack_c8,0x55,local_d4 + 2,(LPOVERLAPPED)0x0);
      NKDbgPrintfW(L"~~~ [[RVC]] LOAD RESOURCE DLL [%d, %d]",BVar3,local_78);
      LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_e8);
      if (LVar2 == 0) {
        LVar2 = RegQueryValueExW(local_e8,L"SYS_LANG_TYPE",(LPDWORD)0x0,(LPDWORD)&local_e4,
                                 (LPBYTE)&local_dc,local_d4 + 1);
        if (LVar2 == 0) {
          NKDbgPrintfW(L"~~~+_+_+_+_+_+_ [[RVC]] Load Reg ~~~~~~~~ [%d, %d]",local_78,local_dc);
          BVar3 = 1;
          local_78 = local_dc;
        }
        RegCloseKey(local_e8);
      }
      if (BVar3 == 0) {
switchD_100052e8_caseD_2:
        pwVar8 = L"\\Storage Card\\system\\data\\LangDllEng.dll";
      }
      else {
        if ((int)local_78 < 0x1d) {
          DAT_1000d3c4 = local_78;
        }
        switch(DAT_1000d3c4) {
        case 0:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllAra.dll";
          break;
        case 1:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllDut.dll";
          break;
        default:
          goto switchD_100052e8_caseD_2;
        case 3:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllFre.dll";
          break;
        case 4:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllGer.dll";
          break;
        case 5:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllIta.dll";
          break;
        case 6:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllPor.dll";
          break;
        case 7:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllRus.dll";
          break;
        case 8:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllSpa.dll";
          break;
        case 9:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllRom.dll";
          break;
        case 10:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllTur.dll";
          break;
        case 0xb:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllPol.dll";
          break;
        case 0xc:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllPTBR.dll";
          break;
        case 0xd:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllJap.dll";
          break;
        case 0xe:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllGre.dll";
          break;
        case 0xf:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllCro.dll";
          break;
        case 0x10:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllCze.dll";
          break;
        case 0x11:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllSloven.dll";
          break;
        case 0x12:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllHun.dll";
          break;
        case 0x13:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllSlo.dll";
          break;
        case 0x14:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllBul.dll";
          break;
        case 0x15:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllHeb.dll";
          break;
        case 0x16:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllSer.dll";
          break;
        case 0x17:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllUka.dll";
          break;
        case 0x18:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllSwe.dll";
          break;
        case 0x19:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllDan.dll";
          break;
        case 0x1a:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllFin.dll";
          break;
        case 0x1b:
          pwVar8 = L"\\Storage Card\\system\\data\\LangDllNor.dll";
        }
      }
      DAT_1000eb44 = LoadLibraryW(pwVar8);
      CloseHandle(hFile);
    }
    pWVar6 = (LPCWSTR)FUN_10002a80(0x59a);
    wsprintfW((LPWSTR)&DAT_1000e914,pWVar6);
    pWVar6 = (LPCWSTR)FUN_10002a80(0x76c);
    wsprintfW((LPWSTR)&DAT_1000e70c,pWVar6);
    pWVar6 = (LPCWSTR)FUN_10002a80(0x76d);
    wsprintfW((LPWSTR)&DAT_1000e504,pWVar6);
    pWVar6 = (LPCWSTR)FUN_10002a80(0x581);
    wsprintfW((LPWSTR)&DAT_1000e2fc,pWVar6);
    pWVar6 = (LPCWSTR)FUN_10002a80(0x582);
    wsprintfW((LPWSTR)&DAT_1000e0f4,pWVar6);
    if (DAT_1000eb44 != (HMODULE)0x0) {
      FreeLibrary(DAT_1000eb44);
      DAT_1000eb44 = (HMODULE)0x0;
    }
    SetWindowPos(param_1,(HWND)0x1,0,0,800,0x1e0,0x80);
    if (DAT_1000ed5c == (HDC)0x0) {
      pHVar1 = GetDC(param_1);
      DAT_1000ed5c = CreateCompatibleDC(pHVar1);
      DAT_1000e0f0 = CreateCompatibleBitmap(pHVar1,800,0x1e0);
      DAT_1000e0ec = SelectObject(DAT_1000ed5c,DAT_1000e0f0);
      ReleaseDC(param_1,pHVar1);
    }
    FUN_10002bcc();
    goto LAB_10006740;
  }
  if (param_2 != 0x202) {
    if (param_2 == 0x9e61) {
      if (DAT_1000eb48 == 0) goto LAB_10006740;
      if ((int)param_4 < 0xd) {
        if (param_4 == 0xc) {
          piVar10 = &DAT_1000e0dc;
          if (DAT_1000e0dc < 0x45) {
            do {
              *piVar10 = *piVar10 + 1;
              piVar10 = piVar10 + 2;
            } while ((int)piVar10 < 0x1000e0ec);
          }
          if (DAT_1000ed6c == 0) {
            DAT_1000ed6c = 1;
          }
          DAT_1000d3c8 = DAT_1000d3c8 | 2;
          InvalidateRect(param_1,(RECT *)&DAT_1000d494,0);
          pwVar8 = L"[RVC] GuideLine  Left direction increment - Type[%d]\r\n";
          param_4 = DAT_1000eb48;
        }
        else if (param_4 == 1) {
          if (DAT_1000ed74 < 0x2d) {
            DAT_1000ed74 = DAT_1000ed74 + 1;
          }
          else {
            DAT_1000ed74 = 0x2d;
          }
          if (DAT_1000ed68 != (HGDIOBJ)0x0) {
            DeleteObject(DAT_1000ed68);
            DAT_1000ed68 = (HGDIOBJ)0x0;
          }
          if (DAT_1000ed6c == 0) {
            DAT_1000ed6c = 1;
          }
          DAT_1000d3c8 = DAT_1000d3c8 | 2;
          InvalidateRect(param_1,(RECT *)&DAT_1000d494,0);
          pwVar8 = L"[RVC] GuideLine  Rotation to the Left - Type[%d] \r\n";
          param_4 = DAT_1000eb48;
        }
        else if (param_4 == 2) {
          if (DAT_1000ed74 < -0x2c) {
            DAT_1000ed74 = -0x2d;
          }
          else {
            DAT_1000ed74 = DAT_1000ed74 + -1;
          }
          if (DAT_1000ed68 != (HGDIOBJ)0x0) {
            DeleteObject(DAT_1000ed68);
            DAT_1000ed68 = (HGDIOBJ)0x0;
          }
          if (DAT_1000ed6c == 0) {
            DAT_1000ed6c = 1;
          }
          DAT_1000d3c8 = DAT_1000d3c8 | 2;
          InvalidateRect(param_1,(RECT *)&DAT_1000d494,0);
          pwVar8 = L"[RVC] GuideLine  Rotation to the Right - Type[%d] \r\n";
          param_4 = DAT_1000eb48;
        }
        else if (param_4 == 4) {
          if (DAT_1000e0e0 < 0xb3) {
            piVar10 = &DAT_1000e0e0;
            do {
              *piVar10 = *piVar10 + 1;
              piVar10 = piVar10 + 2;
            } while ((int)piVar10 < 0x1000e0f0);
          }
          if (DAT_1000ed6c == 0) {
            DAT_1000ed6c = 1;
          }
          DAT_1000d3c8 = DAT_1000d3c8 | 2;
          InvalidateRect(param_1,(RECT *)&DAT_1000d494,0);
          pwVar8 = L"[RVC] GuideLine  Upward direction increment - Type[%d]\r\n";
          param_4 = DAT_1000eb48;
        }
        else {
          if (param_4 != 8) goto LAB_10006740;
          if (-0x15 < DAT_1000e0e0) {
            piVar10 = &DAT_1000e0e0;
            do {
              *piVar10 = *piVar10 + -1;
              piVar10 = piVar10 + 2;
            } while ((int)piVar10 < 0x1000e0f0);
          }
          if (DAT_1000ed6c == 0) {
            DAT_1000ed6c = 1;
          }
          DAT_1000d3c8 = DAT_1000d3c8 | 2;
          InvalidateRect(param_1,(RECT *)&DAT_1000d494,0);
          pwVar8 = L"[RVC] GuideLine  Downward direction increment - Type[%d]\r\n";
          param_4 = DAT_1000eb48;
        }
      }
      else {
        if (param_4 != 0x10) {
          if (param_4 == 0x20) {
            DAT_1000eb2c = DAT_1000ed74;
            DAT_1000eb30 = DAT_1000e0dc;
            DAT_1000eb34 = DAT_1000e0e0;
            DAT_1000eb38 = DAT_1000e0e4;
            DAT_1000eb3c = DAT_1000e0e8;
            FUN_100030ac();
            pwVar8 = L"[RVC] Validate Guideline Setting \r\n";
          }
          else {
            if (param_4 != 0x40) goto LAB_10006740;
            if ((DAT_1000ed74 != 0) && (DAT_1000ed74 = 0, DAT_1000ed68 != (HGDIOBJ)0x0)) {
              DeleteObject(DAT_1000ed68);
              DAT_1000ed68 = (HGDIOBJ)0x0;
            }
            DAT_1000e0dc = 0x13;
            DAT_1000e0e0 = 0x4f;
            DAT_1000e0e4 = 0x13;
            DAT_1000e0e8 = 0x4f;
            if (DAT_1000ed6c == 0) {
              DAT_1000ed6c = 1;
            }
            DAT_1000d3c8 = DAT_1000d3c8 | 2;
            InvalidateRect(param_1,(RECT *)&DAT_1000d494,0);
            pwVar8 = L"[RVC] Cancel Guideline Setting \r\n";
          }
          goto LAB_10005614;
        }
        piVar10 = &DAT_1000e0dc;
        if (-0x1f < DAT_1000e0dc) {
          do {
            *piVar10 = *piVar10 + -1;
            piVar10 = piVar10 + 2;
          } while ((int)piVar10 < 0x1000e0ec);
        }
        if (DAT_1000ed6c == 0) {
          DAT_1000ed6c = 1;
        }
        DAT_1000d3c8 = DAT_1000d3c8 | 2;
        InvalidateRect(param_1,(RECT *)&DAT_1000d494,0);
        pwVar8 = L"[RVC] GuideLine  Right direction increment - Type[%d]\r\n";
        param_4 = DAT_1000eb48;
      }
LAB_10006348:
      NKDbgPrintfW(pwVar8,param_4);
    }
    else {
      if (param_2 != 0x9e63) {
        if (param_2 == 0x9e64) {
          if ((-1 < (int)param_4) && (((int)param_4 < 5 || (param_4 == 9)))) {
            DAT_1000eb48 = param_4;
            if (DAT_1000ed68 != (HGDIOBJ)0x0) {
              DeleteObject(DAT_1000ed68);
              DAT_1000ed68 = (HGDIOBJ)0x0;
            }
            if (DAT_1000ed6c == 0) {
              DAT_1000ed6c = 1;
            }
            DAT_1000d3c8 = DAT_1000d3c8 | 2;
            InvalidateRect(param_1,(RECT *)&DAT_1000d494,0);
            NKDbgPrintfW(L"[RVC]   CMD_DSI_RVC_GUIDELINE    [0x%X]\n",DAT_1000eb48);
            LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_ec);
            if (LVar2 == 0) {
              RegSetValueExW(local_ec,L"GUIDELINE_TYPE",0,4,(BYTE *)&DAT_1000eb48,4);
              RegCloseKey(local_ec);
            }
            goto LAB_10006740;
          }
          pwVar8 = L"[ERROR] Unknown Guideline type [0x%X]\n";
          goto LAB_10006348;
        }
LAB_100057f8:
        if (DAT_1000ed7c == param_2) {
          if (DAT_1000eb44 != (HMODULE)0x0) {
            FreeLibrary(DAT_1000eb44);
          }
          if (0x1c < (int)param_4) {
            param_4 = 2;
          }
          DAT_1000d3c4 = param_4;
          NKDbgPrintfW(L"Language ->  %d  -  Switch ---",param_4);
          switch(DAT_1000d3c4) {
          case 0:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllAra.dll";
            break;
          case 1:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllDut.dll";
            break;
          default:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllEng.dll";
            break;
          case 3:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllFre.dll";
            break;
          case 4:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllGer.dll";
            break;
          case 5:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllIta.dll";
            break;
          case 6:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllPor.dll";
            break;
          case 7:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllRus.dll";
            break;
          case 8:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllSpa.dll";
            break;
          case 9:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllRom.dll";
            break;
          case 10:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllTur.dll";
            break;
          case 0xb:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllPol.dll";
            break;
          case 0xc:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllPTBR.dll";
            break;
          case 0xd:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllJap.dll";
            break;
          case 0xe:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllGre.dll";
            break;
          case 0xf:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllCro.dll";
            break;
          case 0x10:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllCze.dll";
            break;
          case 0x11:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllSloven.dll";
            break;
          case 0x12:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllHun.dll";
            break;
          case 0x13:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllSlo.dll";
            break;
          case 0x14:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllBul.dll";
            break;
          case 0x15:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllHeb.dll";
            break;
          case 0x16:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllSer.dll";
            break;
          case 0x17:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllUka.dll";
            break;
          case 0x18:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllSwe.dll";
            break;
          case 0x19:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllDan.dll";
            break;
          case 0x1a:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllFin.dll";
            break;
          case 0x1b:
            pwVar8 = L"\\Storage Card\\system\\data\\LangDllNor.dll";
          }
          DAT_1000eb44 = LoadLibraryW(pwVar8);
          pWVar6 = (LPCWSTR)FUN_10002a80(0x59a);
          wsprintfW((LPWSTR)&DAT_1000e914,pWVar6);
          pWVar6 = (LPCWSTR)FUN_10002a80(0x76c);
          wsprintfW((LPWSTR)&DAT_1000e70c,pWVar6);
          pWVar6 = (LPCWSTR)FUN_10002a80(0x76d);
          wsprintfW((LPWSTR)&DAT_1000e504,pWVar6);
          pWVar6 = (LPCWSTR)FUN_10002a80(0x581);
          wsprintfW((LPWSTR)&DAT_1000e2fc,pWVar6);
          pWVar6 = (LPCWSTR)FUN_10002a80(0x582);
          wsprintfW((LPWSTR)&DAT_1000e0f4,pWVar6);
          if (DAT_1000eb44 != (HMODULE)0x0) {
            FreeLibrary(DAT_1000eb44);
            DAT_1000eb44 = (HMODULE)0x0;
          }
          goto LAB_10006740;
        }
        if (DAT_1000ed80 != param_2) {
          if (DAT_1000ed90 == param_2) {
            DAT_1000d3c8 = DAT_1000d3c8 | 2;
            pRVar9 = (RECT *)&DAT_1000d494;
          }
          else {
            if (DAT_1000ed84 == param_2) {
              FUN_10002b50(0);
              goto LAB_10006740;
            }
            if (DAT_1000ed8c == param_2) {
              NKDbgPrintfW(L"[INFO] g_NotiMsgTestTool !!! g_bRVCStarted %d(%d - %d) \r\n",
                           DAT_1000ed70,DAT_1000ed6c,param_4);
              if (param_4 == 0xfe) {
                if (DAT_1000ed6c == 1) {
                  DAT_1000ed6c = 0;
                }
              }
              else if (DAT_1000ed6c == 0) {
                DAT_1000ed6c = 1;
              }
              DAT_1000d3c8 = DAT_1000d3c8 | 2;
              pRVar9 = (RECT *)&DAT_1000d494;
            }
            else {
              if (DAT_1000ed94 != param_2) {
                if (DAT_1000ed88 != param_2) {
                  LVar7 = DefWindowProcW(param_1,param_2,param_3,param_4);
                  FUN_10008094(local_30);
                  return LVar7;
                }
                NKDbgPrintfW(L"[INFO] g_NotiMsgColorCtrl !!! wParam %d, lParam %d \r\n",param_3,
                             param_4);
                if (param_3 != 0x40) {
                  if (param_3 != 0x42) {
                    if (param_3 == 0x44) {
                      DAT_1000d3d8 = param_4;
                      if (DAT_1000ed70 != 0) {
                        FUN_10007090(param_4);
                      }
                    }
                    else if (param_3 == 0x46) {
                      DAT_1000d3dc = param_4;
                      if (DAT_1000ed70 != 0) {
                        FUN_100070ac(param_4);
                      }
                    }
                    else if ((param_3 == 0x48) && (DAT_1000d3e0 = param_4, DAT_1000ed70 != 0)) {
                      FUN_100070c8(param_4);
                    }
                    goto LAB_10006740;
                  }
                  if (0xe < (int)param_4) goto LAB_10006740;
                  DAT_1000eb28 = 0xe - param_4;
                  DAT_1000d3d4 = param_4;
                  FUN_100030ac();
                  if (DAT_1000ed70 == 0) goto LAB_10006740;
                  goto LAB_10004ed0;
                }
                if (0xe < (int)param_4) goto LAB_10006740;
                DAT_1000eb24 = 0xe - param_4;
                DAT_1000d3d0 = param_4;
                FUN_100030ac();
                if (DAT_1000ed70 == 0) goto LAB_10006740;
                goto LAB_10005d60;
              }
              if (DAT_1000ed70 == 0) goto LAB_10006740;
              DAT_1000d3cc = -1;
              KillTimer(param_1,1000);
              DAT_1000d3c8 = 0xffffffff;
              pRVar9 = (RECT *)0x0;
            }
          }
          goto LAB_10005d70;
        }
        if (param_4 == 0) goto LAB_10006740;
      }
      FUN_100030ac();
    }
    goto LAB_10006740;
  }
  iVar4 = FUN_10002a08(param_4 & 0xffff,param_4 >> 0x10);
  KillTimer(param_1,1000);
  if (DAT_1000d3cc == iVar4) {
    DAT_1000eb1c = GetTickCount();
    if (iVar4 != 0) {
      if (iVar4 == 1) {
        if (DAT_1000eb48 == 0) goto LAB_1000673c;
        if (DAT_1000ed6c == 0) {
          DAT_1000d3c8 = DAT_1000d3c8 | 4;
          InvalidateRect(param_1,(RECT *)&DAT_1000d3e4,0);
        }
        DAT_1000ed6c = 1;
        DAT_1000d3c8 = DAT_1000d3c8 | 8;
        DAT_1000eb20 = 1;
        InvalidateRect(param_1,(RECT *)&DAT_1000d3f4,0);
        DAT_1000d3c8 = DAT_1000d3c8 | 2;
        pRVar9 = (RECT *)&DAT_1000d494;
      }
      else {
        if (iVar4 == 2) {
          if (DAT_1000eb24 != 0) {
            DAT_1000eb24 = DAT_1000eb24 - 1;
            FUN_10007058(DAT_1000eb24);
          }
          DAT_1000d3c8 = DAT_1000d3c8 | 0x10;
          pRVar9 = (RECT *)&DAT_1000d404;
        }
        else {
          if (iVar4 != 3) {
            if (iVar4 == 4) {
              if (DAT_1000eb28 != 0) {
                DAT_1000eb28 = DAT_1000eb28 - 1;
                FUN_10007074(DAT_1000eb28);
              }
              DAT_1000d3c8 = DAT_1000d3c8 | 0x40;
              pRVar9 = (RECT *)&DAT_1000d424;
            }
            else {
              if (iVar4 != 5) goto LAB_1000673c;
              if (DAT_1000eb28 < 0xe) {
                DAT_1000eb28 = DAT_1000eb28 + 1;
                FUN_10007074(DAT_1000eb28);
              }
              DAT_1000d3c8 = DAT_1000d3c8 | 0x80;
              pRVar9 = (RECT *)&DAT_1000d434;
            }
            DAT_1000d3cc = -1;
            InvalidateRect(param_1,pRVar9,0);
            pRVar9 = (RECT *)&DAT_1000d6a4;
            goto LAB_10006730;
          }
          if (DAT_1000eb24 < 0xe) {
            DAT_1000eb24 = DAT_1000eb24 + 1;
            FUN_10007058(DAT_1000eb24);
          }
          DAT_1000d3c8 = DAT_1000d3c8 | 0x20;
          pRVar9 = (RECT *)&DAT_1000d414;
        }
        DAT_1000d3cc = -1;
        InvalidateRect(param_1,pRVar9,0);
        pRVar9 = (RECT *)&DAT_1000d694;
      }
      goto LAB_10006730;
    }
    if (DAT_1000eb48 != 0) {
      if (DAT_1000ed6c == 1) {
        DAT_1000d3c8 = DAT_1000d3c8 | 8;
        InvalidateRect(param_1,(RECT *)&DAT_1000d3f4,0);
      }
      DAT_1000ed6c = 0;
      DAT_1000d3c8 = DAT_1000d3c8 | 4;
      DAT_1000eb20 = 0;
      InvalidateRect(param_1,(RECT *)&DAT_1000d3e4,0);
      DAT_1000d3c8 = DAT_1000d3c8 | 2;
      pRVar9 = (RECT *)&DAT_1000d494;
      goto LAB_10006730;
    }
  }
  else {
    if (DAT_1000d3cc == 0) {
      if (DAT_1000eb48 == 0) goto LAB_1000673c;
      DAT_1000d3c8 = DAT_1000d3c8 | 4;
      pRVar9 = (RECT *)&DAT_1000d3e4;
    }
    else if (DAT_1000d3cc == 1) {
      if (DAT_1000eb48 == 0) goto LAB_1000673c;
      DAT_1000d3c8 = DAT_1000d3c8 | 8;
      pRVar9 = (RECT *)&DAT_1000d3f4;
    }
    else if (DAT_1000d3cc == 2) {
      DAT_1000d3c8 = DAT_1000d3c8 | 0x10;
      pRVar9 = (RECT *)&DAT_1000d404;
    }
    else if (DAT_1000d3cc == 3) {
      DAT_1000d3c8 = DAT_1000d3c8 | 0x20;
      pRVar9 = (RECT *)&DAT_1000d414;
    }
    else if (DAT_1000d3cc == 4) {
      DAT_1000d3c8 = DAT_1000d3c8 | 0x40;
      pRVar9 = (RECT *)&DAT_1000d424;
    }
    else {
      if (DAT_1000d3cc != 5) goto LAB_1000673c;
      DAT_1000d3c8 = DAT_1000d3c8 | 0x80;
      pRVar9 = (RECT *)&DAT_1000d434;
    }
LAB_10006730:
    InvalidateRect(param_1,pRVar9,0);
  }
LAB_1000673c:
  DAT_1000d3cc = -1;
LAB_10006740:
  FUN_10008094(local_30);
  return 0;
}



/* 10006784 Unwind@10006784 */

/* Boundary evidence: original MIPS .pdata 10006784..100067b3. Semantic name remains unreviewed. */

void Unwind_10006784(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0xe4));
  return;
}



/* 100067b4 FUN_100067b4 */

/* Boundary evidence: original MIPS .pdata 100067b4..100068bb. Semantic name remains unreviewed. */

void FUN_100067b4(void)

{
  DWORD DVar1;
  WNDCLASSW local_38;
  
  if (DAT_1000eb4c == (HWND)0x0) {
    local_38.style = 3;
    local_38.lpfnWndProc = FUN_10004dc8;
    local_38.cbClsExtra = 0;
    local_38.cbWndExtra = 0;
    local_38.hInstance = DAT_1000ed60;
    local_38.hIcon = (HICON)0x0;
    local_38.hCursor = (HCURSOR)0x0;
    local_38.hbrBackground = GetStockObject(5);
    local_38.lpszMenuName = (LPCWSTR)0x0;
    local_38.lpszClassName = L"RVC WND";
    RegisterClassW(&local_38);
    DAT_1000eb4c = CreateWindowExW(local_38.style,L"RVC WND",L"RVC WND",0x80000000,0,0,800,0x1e0,
                                   DAT_1000ed64,(HMENU)0x0,(HINSTANCE)0x0,(LPVOID)0x0);
    if (DAT_1000eb4c == (HWND)0x0) {
      DVar1 = GetLastError();
      NKDbgPrintfW(L"ERROR CreateWindow 0x%X\r\n",DVar1);
    }
    else {
      ShowWindow(DAT_1000eb4c,0);
    }
  }
  return;
}



/* 100068bc SetRVCWnd */

/* Boundary evidence: original MIPS .pdata 100068bc..100068ff. Semantic name remains unreviewed.
   void __cdecl SetRVCWnd(struct HINSTANCE__ *,struct HWND__ *) */

void SetRVCWnd(HINSTANCE__ *param_1,HWND__ *param_2)

{
                    /* 0x68bc  3  ?SetRVCWnd@@YAXPAUHINSTANCE__@@PAUHWND__@@@Z */
  if (DAT_1000ed60 != param_1) {
    DAT_1000ed60 = param_1;
  }
  if (DAT_1000ed64 != param_2) {
    DAT_1000ed64 = param_2;
  }
  FUN_100067b4();
  return;
}



/* 10006900 FUN_10006900 */

/* Boundary evidence: original MIPS .pdata 10006900..1000697b. Semantic name remains unreviewed. */

HANDLE FUN_10006900(void)

{
  HANDLE pvVar1;
  DWORD DVar2;
  
  pvVar1 = CreateFileW(L"CAM1:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (pvVar1 == (HANDLE)0xffffffff) {
    DVar2 = GetLastError();
    NKDbgPrintfW(L"Cannot open CAM1: %d\r\n",DVar2);
    pvVar1 = (HANDLE)0x0;
  }
  return pvVar1;
}



/* 1000697c FUN_1000697c */

/* Boundary evidence: original MIPS .pdata 1000697c..10006a8b. Semantic name remains unreviewed. */

undefined4 FUN_1000697c(HANDLE param_1,undefined4 param_2,LPVOID param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  wchar_t *pwVar3;
  undefined4 local_res4 [3];
  DWORD aDStack_18 [2];
  
  local_res4[0] = param_2;
  if (param_3 == (LPVOID)0x0) {
    NKDbgPrintfW(L"ConfigureCIM ERROR");
  }
  else {
    BVar1 = DeviceIoControl(param_1,0x101a004,local_res4,4,(LPVOID)0x0,0,aDStack_18,
                            (LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      pwVar3 = L"Cannot set current camera mode: %d\r\n";
    }
    else {
      BVar1 = DeviceIoControl(param_1,0x1012000,(LPVOID)0x0,0,param_3,0x50,aDStack_18,
                              (LPOVERLAPPED)0x0);
      if (BVar1 != 0) {
        return 1;
      }
      DVar2 = GetLastError();
      pwVar3 = L"Cannot get current camera mode: %d\r\n";
    }
    NKDbgPrintfW(pwVar3,DVar2);
  }
  return 0;
}



/* 10006a8c FUN_10006a8c */

/* Boundary evidence: original MIPS .pdata 10006a8c..10006dc7. Semantic name remains unreviewed. */

undefined4 FUN_10006a8c(int *param_1)

{
  bool bVar1;
  bool bVar2;
  size_t _Size;
  HANDLE pvVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  void *_Src;
  int iVar9;
  int iVar10;
  void *_Dst;
  void *_Src_00;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar13 = param_1[2] - *param_1;
  uVar4 = param_1[3] - param_1[1];
  iVar7 = param_1[6];
  iVar5 = param_1[4];
  iVar10 = param_1[0xb];
  iVar6 = param_1[9];
  iVar8 = param_1[5];
  iVar9 = param_1[7];
  uVar12 = 1;
  uVar11 = 0;
  bVar1 = true;
  bVar2 = false;
  NKDbgPrintfW(L"uSrcOffSet = %d\r\n",param_1[1] * uVar13 * 2);
  pvVar3 = FUN_10001ac4();
  if (pvVar3 == (HANDLE)0x0) {
    NKDbgPrintfW(L"Failed to open ITE driver\r\n");
  }
  else {
    FUN_10001818(0x1000ed98);
    FUN_10001870(0x1000ed98,1);
    DAT_1000eda0 = FUN_10001778(uVar13,iVar7 - iVar5);
    DAT_1000eda4 = FUN_10001778(uVar4,iVar9 - iVar8);
    DAT_1000f10c = (iVar7 - iVar5) * 2;
    DAT_1000f100 = DAT_1000f100 | 0x408;
    DAT_1000ed98 = 0x50903a0;
    DAT_1000f104 = iVar9 - iVar8;
    while (DAT_1000f548 == 0) {
      WaitForSingleObject((HANDLE)param_1[0xf5],0xffffffff);
      if (bVar1) {
        bVar1 = false;
      }
      else {
        iVar8 = (&DAT_1000f53c)[DAT_1000f550];
        iVar5 = (&DAT_1000f52c)[DAT_1000f550];
        iVar7 = (&DAT_1000f534)[DAT_1000f550];
        FUN_100018e8(0x1000ed98,param_1[0xc],*(int *)(iVar7 + 8),uVar13,uVar4);
        _Size = DAT_1000f0ec;
        _Src_00 = *(void **)(iVar8 + 4);
        _Dst = *(void **)(iVar7 + 4);
        _Src = (void *)(((uint)(iVar10 - iVar6) >> 1) * DAT_1000f0ec + (int)_Src_00);
        for (uVar14 = uVar4 >> 1; uVar14 != 0; uVar14 = uVar14 - 1) {
          memcpy(_Dst,_Src_00,_Size);
          _Src_00 = (void *)((int)_Src_00 + _Size);
          memcpy((void *)((int)_Dst + _Size),_Src,_Size);
          _Dst = (void *)((int)((int)_Dst + _Size) + _Size);
          _Src = (void *)((int)_Src + _Size);
        }
        DAT_1000f108 = *(undefined4 *)(iVar5 + 8);
        FUN_10001a50(pvVar3,&DAT_1000ed98);
        FUN_10001d70(3,1,*(undefined4 *)(iVar5 + 8));
        if (!bVar2) {
          if (uVar11 == 2) {
            FUN_10001c0c(3,1);
          }
          else if (4 < uVar11) {
            bVar2 = true;
            PostMessageW(DAT_1000f544,DAT_1000f554,0,0);
          }
          uVar11 = uVar11 + 1;
        }
      }
    }
    NKDbgPrintfW(L"SetEvent(hcEvent)\r\n");
    EventModify(DAT_1000f528,3);
    FUN_10001b74((int)pvVar3);
    uVar12 = 0;
  }
  return uVar12;
}



/* 10006dc8 FUN_10006dc8 */

/* Boundary evidence: original MIPS .pdata 10006dc8..10006e5b. Semantic name remains unreviewed. */

void FUN_10006dc8(void)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint uVar5;
  
  FUN_10007c14(0x44);
  uVar1 = DAT_1000d3e0;
  uVar5 = (uint)(byte)DAT_1000d3dc;
  uVar2 = FUN_10007a24(DAT_1000d3d8);
  uVar3 = FUN_10007988(0x47,0);
  uVar4 = FUN_10007988(0x1c,0);
  FUN_1000771c(CONCAT31(extraout_var_01,uVar4),CONCAT31(extraout_var_00,uVar3),
               CONCAT31(extraout_var,uVar2),uVar5,(byte)uVar1);
  return;
}



/* 10006e5c FUN_10006e5c */

/* Boundary evidence: original MIPS .pdata 10006e5c..1000703b. Semantic name remains unreviewed. */

void FUN_10006e5c(void)

{
  int iVar1;
  
  FUN_10001c0c(*DAT_1000f520,0);
  DAT_1000f548 = 1;
  EventModify(DAT_1000f54c,3);
  FUN_10001de0(*DAT_1000f520,DAT_1000f520[1],DAT_1000f520[2],DAT_1000f520[3]);
  WaitForSingleObject(DAT_1000f528,0xffffffff);
  CloseHandle(DAT_1000f54c);
  CloseHandle(DAT_1000f528);
  DAT_1000f54c = (HANDLE)0x0;
  DAT_1000f528 = (HANDLE)0x0;
  iVar1 = 0;
  do {
    FUN_10001720((HANDLE)*DAT_1000f524,*(void **)((int)&DAT_1000f53c + iVar1));
    FUN_10001720((HANDLE)*DAT_1000f524,*(void **)((int)&DAT_1000f534 + iVar1));
    FUN_10001720((HANDLE)*DAT_1000f524,*(void **)((int)&DAT_1000f52c + iVar1));
    iVar1 = iVar1 + 4;
  } while (iVar1 < 8);
  if (*DAT_1000f524 != 0) {
    FUN_100015fc(*DAT_1000f524);
  }
  if (DAT_1000f140 != 0) {
    CloseHandle((HANDLE)DAT_1000f140);
    NKDbgPrintfW(L"CloseCim Finish\r\n");
  }
  FUN_10007670();
  if (DAT_1000f520 != (undefined4 *)0x0) {
    free(DAT_1000f520);
    DAT_1000f520 = (undefined4 *)0x0;
  }
  if (DAT_1000f524 != (int *)0x0) {
    free(DAT_1000f524);
    DAT_1000f524 = (int *)0x0;
  }
  return;
}



/* 1000703c FUN_1000703c */

/* Boundary evidence: original MIPS .pdata 1000703c..10007057. Semantic name remains unreviewed. */

void FUN_1000703c(int param_1,int param_2)

{
  FUN_100078b8(param_1,param_2 + 0x10);
  return;
}



/* 10007058 FUN_10007058 */

/* Boundary evidence: original MIPS .pdata 10007058..10007073. Semantic name remains unreviewed. */

void FUN_10007058(int param_1)

{
  FUN_10007a58(param_1);
  return;
}



/* 10007074 FUN_10007074 */

/* Boundary evidence: original MIPS .pdata 10007074..1000708f. Semantic name remains unreviewed. */

void FUN_10007074(int param_1)

{
  FUN_10007aa8(param_1 + 0x10);
  return;
}



/* 10007090 FUN_10007090 */

/* Boundary evidence: original MIPS .pdata 10007090..100070ab. Semantic name remains unreviewed. */

void FUN_10007090(uint param_1)

{
  FUN_10007af8(param_1 & 0xff);
  return;
}



/* 100070ac FUN_100070ac */

/* Boundary evidence: original MIPS .pdata 100070ac..100070c7. Semantic name remains unreviewed. */

void FUN_100070ac(uint param_1)

{
  FUN_10007b74(param_1 & 0xff);
  return;
}



/* 100070c8 FUN_100070c8 */

/* Boundary evidence: original MIPS .pdata 100070c8..100070e3. Semantic name remains unreviewed. */

void FUN_100070c8(uint param_1)

{
  FUN_10007bc4(param_1 & 0xff);
  return;
}



/* 100070e4 FUN_100070e4 */

/* Boundary evidence: original MIPS .pdata 100070e4..10007223. Semantic name remains unreviewed. */

undefined4 FUN_100070e4(undefined4 *param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  DWORD aDStack_30 [2];
  
  DAT_1000f550 = 0;
  uVar4 = 0;
  while (DAT_1000f548 == 0) {
    if (1 < uVar4) {
      uVar4 = 0;
    }
    iVar3 = (&DAT_1000f53c)[uVar4];
    *(undefined4 *)(iVar3 + 0xc) = 0xa8c00;
    BVar1 = DeviceIoControl((HANDLE)*param_1,0x101a008,(LPVOID)0x0,0,*(LPVOID *)(iVar3 + 8),0xa8c00,
                            aDStack_30,(LPOVERLAPPED)0x0);
    if (BVar1 == 0x5b4) {
      DVar2 = GetLastError();
      NKDbgPrintfW(L"FAILED TO CAPTURE FRAME!: %d\r\n",DVar2);
    }
    else {
      DAT_1000f550 = uVar4;
      EventModify(param_1[1],3);
      uVar4 = uVar4 + 1;
    }
  }
  return 0;
}



/* 10007224 FUN_10007224 */

/* Boundary evidence: original MIPS .pdata 10007224..1000766f. Semantic name remains unreviewed. */

undefined4 FUN_10007224(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  HANDLE pvVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 local_c8;
  undefined4 local_c4;
  uint local_c0;
  uint local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  int local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int local_90;
  undefined4 *local_8c;
  undefined4 *local_88;
  undefined1 auStack_80 [68];
  int local_3c;
  int local_38;
  uint local_30;
  
  local_30 = DAT_1000da9c;
  uVar1 = FUN_10001bd4();
  uVar2 = FUN_10001bf0();
  DAT_1000f548 = 0;
  DAT_1000f544 = param_4;
  memset(auStack_80,0,0x50);
  DAT_1000f524 = malloc(4);
  DAT_1000f520 = malloc(0x20);
  DAT_1000f140 = FUN_10006900();
  NKDbgPrintfW(L"configure to %d\r\n",param_1);
  iVar3 = FUN_1000697c(DAT_1000f140,param_1,auStack_80);
  if (iVar3 == 0) {
    NKDbgPrintfW(L"Failed to configure camera device\r\n");
    FUN_10008094(local_30);
    uVar4 = 1;
  }
  else {
    FUN_10006dc8();
    local_a8 = 0;
    local_a0 = local_38;
    local_98 = 0;
    local_90 = local_3c;
    local_a4 = 0;
    if (uVar1 < param_2) {
      param_2 = uVar1;
    }
    if (uVar2 < param_3) {
      param_3 = uVar2;
    }
    NKDbgPrintfW(L"Final output size: %d x %d\r\n",param_2,param_3);
    local_94 = 0;
    local_9c = 0;
    local_b8 = 0;
    local_b4 = 0;
    local_b0 = 0;
    local_ac = 0;
    local_c4 = 0;
    local_bc = 0x3000000;
    local_c0 = 0xcc000000;
    local_c8 = 3;
    FUN_10001c90((LPCSTR)&local_c8);
    local_bc = (param_2 & 0xfff) << 9 | local_bc;
    local_c0 = (param_2 - 1 & 0x7ff) << 0xb | param_3 - 1 & 0x7ff | local_c0;
    FUN_10001cf8(local_c8,local_c4,local_c0,local_bc);
    pvVar5 = FUN_1000154c();
    if (pvVar5 == (HANDLE)0x0) {
      NKDbgPrintfW(L"Failed to open mempool driver\r\n");
    }
    iVar3 = 0;
    iVar8 = local_3c * local_38 * 2;
    local_88 = &DAT_1000f534;
    local_8c = &DAT_1000f53c;
    do {
      pvVar6 = FUN_1000165c(pvVar5,iVar8,1,0);
      *(void **)((int)&DAT_1000f53c + iVar3) = pvVar6;
      pvVar6 = FUN_1000165c(pvVar5,iVar8,1,0);
      *(void **)((int)&DAT_1000f534 + iVar3) = pvVar6;
      pvVar6 = FUN_1000165c(pvVar5,uVar2 * uVar1 * 2,1,0);
      puVar7 = (undefined4 *)((int)&DAT_1000f52c + iVar3);
      iVar3 = iVar3 + 4;
      *puVar7 = pvVar6;
    } while (iVar3 < 8);
    DAT_1000f144 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    DAT_1000f51c = DAT_1000f144;
    DAT_1000f54c = DAT_1000f144;
    DAT_1000f528 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    DAT_1000f13c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100070e4,&DAT_1000f140,0,
                                (LPDWORD)0x0);
    iVar8 = local_90;
    iVar3 = local_a0;
    if (DAT_1000f13c != (HANDLE)0x0) {
      CloseHandle(DAT_1000f13c);
    }
    DAT_1000f178 = 0x59565955;
    DAT_1000f168 = local_98;
    DAT_1000f16c = local_a8;
    DAT_1000f170 = iVar8;
    DAT_1000f174 = iVar3;
    DAT_1000f148 = local_a4;
    DAT_1000f14c = 0x10;
    DAT_1000f150 = iVar8;
    DAT_1000f154 = iVar3;
    DAT_1000f158 = local_9c;
    DAT_1000f15c = local_94;
    DAT_1000f160 = param_2;
    DAT_1000f164 = param_3;
    DAT_1000f138 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10006a8c,&DAT_1000f148,0,
                                (LPDWORD)0x0);
    if (DAT_1000f138 != (HANDLE)0x0) {
      CloseHandle(DAT_1000f138);
    }
    *DAT_1000f524 = pvVar5;
    memcpy(DAT_1000f520,&local_c8,0x20);
    NKDbgPrintfW(L"StartCIM Finish\r\n");
    FUN_10008094(local_30);
    uVar4 = 0;
  }
  return uVar4;
}



/* 10007670 FUN_10007670 */

/* Boundary evidence: original MIPS .pdata 10007670..100076ab. Semantic name remains unreviewed. */

void FUN_10007670(void)

{
  if (DAT_1000f55c != (undefined4 *)0x0) {
    FUN_1000151c(DAT_1000f55c);
    DAT_1000f55c = (undefined4 *)0x0;
  }
  return;
}



/* 100076ac FUN_100076ac */

/* Boundary evidence: original MIPS .pdata 100076ac..1000771b. Semantic name remains unreviewed. */

void FUN_100076ac(undefined4 *param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  undefined1 local_res8 [8];
  
  local_res8[0] = param_3;
  if (DAT_1000deb4 == 0) {
    iVar1 = FUN_10001358(param_1,0x44,param_2,local_res8,1);
  }
  else {
    iVar1 = FUN_10001358(param_1,0x45,param_2,local_res8,1);
  }
  if (iVar1 == 0) {
    NKDbgPrintfW(L"%S MI2C_Dll_Write TW9900 fail","TW9900Write");
  }
  return;
}



/* 1000771c FUN_1000771c */

/* Boundary evidence: original MIPS .pdata 1000771c..100078b7. Semantic name remains unreviewed. */

void FUN_1000771c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,byte param_5
                 )

{
  NKDbgPrintfW(L"RVC Mode [0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X]\r\n",param_1,param_2,param_3,
               param_4,param_5);
  if (200 < param_4) {
    param_4 = 0x80;
  }
  if (200 < param_5) {
    param_5 = 0x80;
  }
  FUN_100076ac(DAT_1000f55c,0x1c,0);
  FUN_100076ac(DAT_1000f55c,2,0x44);
  FUN_100076ac(DAT_1000f55c,3,0xa2);
  FUN_100076ac(DAT_1000f55c,8,0x14);
  FUN_100076ac(DAT_1000f55c,10,0xf);
  FUN_100076ac(DAT_1000f55c,0xd,0x14);
  FUN_100076ac(DAT_1000f55c,0x10,(char)param_1);
  FUN_100076ac(DAT_1000f55c,0x11,(char)param_2);
  FUN_100076ac(DAT_1000f55c,0x12,99);
  FUN_100076ac(DAT_1000f55c,0x13,(char)param_4);
  FUN_100076ac(DAT_1000f55c,0x14,param_5);
  FUN_100076ac(DAT_1000f55c,0x15,(char)param_3);
  FUN_100076ac(DAT_1000f55c,0x17,0x34);
  FUN_100076ac(DAT_1000f55c,0x1a,10);
  FUN_100076ac(DAT_1000f55c,0x24,0x3d);
  FUN_100076ac(DAT_1000f55c,0x2f,0xe4);
  return;
}



/* 100078b8 FUN_100078b8 */

/* Boundary evidence: original MIPS .pdata 100078b8..10007987. Semantic name remains unreviewed. */

void FUN_100078b8(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_1000d6c4;
  iVar1 = 0;
  do {
    if (*piVar2 == param_1) {
      FUN_100076ac(DAT_1000f55c,0x10,*(undefined1 *)(iVar1 * 8 + 0x1000d6c8));
      break;
    }
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x1000d75c);
  piVar2 = &DAT_1000d75c;
  iVar1 = 0;
  do {
    if (*piVar2 == param_2) {
      FUN_100076ac(DAT_1000f55c,0x11,*(undefined1 *)(iVar1 * 8 + 0x1000d760));
      return;
    }
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x1000d854);
  return;
}



/* 10007988 FUN_10007988 */

undefined1 FUN_10007988(int param_1,int param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_2 == 1) {
    piVar2 = &DAT_1000d6b4;
    do {
      if (*piVar2 == param_1) {
        puVar1 = (undefined1 *)(iVar3 * 8 + 0x1000d6b8);
LAB_10007a18:
        return *puVar1;
      }
      piVar2 = piVar2 + 2;
      iVar3 = iVar3 + 1;
    } while ((int)piVar2 < 0x1000d6bc);
  }
  else {
    piVar2 = &DAT_1000d6c4;
    do {
      if (*piVar2 == param_1) {
        puVar1 = (undefined1 *)(iVar3 * 8 + 0x1000d6c8);
        goto LAB_10007a18;
      }
      piVar2 = piVar2 + 2;
      iVar3 = iVar3 + 1;
    } while ((int)piVar2 < 0x1000d75c);
  }
  return 0x1c;
}



/* 10007a24 FUN_10007a24 */

undefined1 FUN_10007a24(uint param_1)

{
  undefined1 uVar1;
  
  if (param_1 < 0x14) {
    uVar1 = (&DAT_1000d858)[param_1 * 8];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 10007a58 FUN_10007a58 */

/* Boundary evidence: original MIPS .pdata 10007a58..10007aa7. Semantic name remains unreviewed. */

void FUN_10007a58(int param_1)

{
  if ((-1 < param_1) && (param_1 < 0x13)) {
    FUN_100076ac(DAT_1000f55c,0x10,*(undefined1 *)(param_1 * -8 + 0x1000d758));
  }
  return;
}



/* 10007aa8 FUN_10007aa8 */

/* Boundary evidence: original MIPS .pdata 10007aa8..10007af7. Semantic name remains unreviewed. */

void FUN_10007aa8(int param_1)

{
  if ((-1 < param_1) && (param_1 < 0x1f)) {
    FUN_100076ac(DAT_1000f55c,0x11,*(undefined1 *)(param_1 * -8 + 0x1000d850));
  }
  return;
}



/* 10007af8 FUN_10007af8 */

/* Boundary evidence: original MIPS .pdata 10007af8..10007b73. Semantic name remains unreviewed. */

void FUN_10007af8(uint param_1)

{
  undefined1 uVar1;
  
  if (param_1 < 0x49) {
    if (param_1 < 0x14) {
      uVar1 = (&DAT_1000d858)[param_1 * 8];
    }
    else {
      uVar1 = 0;
    }
    FUN_100076ac(DAT_1000f55c,0x15,uVar1);
  }
  NKDbgPrintfW(L"TW9900UpdateDisplayHue - [0x%02X]\r\n",param_1);
  return;
}



/* 10007b74 FUN_10007b74 */

/* Boundary evidence: original MIPS .pdata 10007b74..10007bc3. Semantic name remains unreviewed. */

void FUN_10007b74(uint param_1)

{
  if (param_1 < 0xc9) {
    FUN_100076ac(DAT_1000f55c,0x13,(char)param_1);
  }
  NKDbgPrintfW(L"TW9900UpdateDisplaySatU - [0x%02X]\r\n",param_1);
  return;
}



/* 10007bc4 FUN_10007bc4 */

/* Boundary evidence: original MIPS .pdata 10007bc4..10007c13. Semantic name remains unreviewed. */

void FUN_10007bc4(uint param_1)

{
  if (param_1 < 0xc9) {
    FUN_100076ac(DAT_1000f55c,0x14,(char)param_1);
  }
  NKDbgPrintfW(L"TW9900UpdateDisplaySatV - [0x%02X]\r\n",param_1);
  return;
}



/* 10007c14 FUN_10007c14 */

/* Boundary evidence: original MIPS .pdata 10007c14..10007c6f. Semantic name remains unreviewed. */

void FUN_10007c14(undefined1 param_1)

{
  if ((DAT_1000f55c == (undefined4 *)0x0) &&
     (DAT_1000f55c = FUN_100014a0(param_1), DAT_1000f55c == (undefined4 *)0x0)) {
    return;
  }
  FUN_100076ac(DAT_1000f55c,2,0x40);
  FUN_100076ac(DAT_1000f55c,2,0x44);
  return;
}



/* 10007f90 FUN_10007f90 */

/* Boundary evidence: original MIPS .pdata 10007f90..10008003. Semantic name remains unreviewed. */

void FUN_10007f90(void)

{
  uint uVar1;
  
  if ((DAT_1000da9c == 0) || (DAT_1000da9c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_1000da9c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_1000da9c == 0) {
      DAT_1000da9c = 0xb064;
    }
  }
  DAT_1000daa0 = ~DAT_1000da9c;
  return;
}



/* 10008004 FUN_10008004 */

/* Boundary evidence: original MIPS .pdata 10008004..10008057. Semantic name remains unreviewed. */

void FUN_10008004(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_10008094(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 10008058 FUN_10008058 */

/* Boundary evidence: original MIPS .pdata 10008058..10008083. Semantic name remains unreviewed. */

undefined4 FUN_10008058(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_10008004(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 10008094 FUN_10008094 */

/* Boundary evidence: original MIPS .pdata 10008094..100080db. Semantic name remains unreviewed. */

void FUN_10008094(uint param_1)

{
  if ((param_1 == DAT_1000da9c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 1000813c FUN_1000813c */

/* Boundary evidence: original MIPS .pdata 1000813c..100081ab. Semantic name remains unreviewed. */

void FUN_1000813c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_10008004(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 100081dc FUN_100081dc */

/* Boundary evidence: original MIPS .pdata 100081dc..10008317. Semantic name remains unreviewed. */

int FUN_100081dc(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_1000f570 != (code *)0x0) {
      iVar2 = (*DAT_1000f570)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_1000828c;
    FUN_10008564();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_100025e8();
  }
LAB_1000828c:
  if (((param_2 == 0) && (FUN_100084ec(), iVar1 != 0)) && (DAT_1000f570 != (code *)0x0)) {
    iVar1 = (*DAT_1000f570)(param_1,0,param_3);
  }
  return iVar1;
}



/* 10008318 FUN_10008318 */

/* Boundary evidence: original MIPS .pdata 10008318..10008343. Semantic name remains unreviewed. */

void FUN_10008318(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 10008344 entry */

/* Boundary evidence: original MIPS .pdata 10008344..1000839b. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_10007f90();
  }
  FUN_100081dc(param_1,param_2,param_3);
  return;
}



/* 100083cc FUN_100083cc */

/* Boundary evidence: original MIPS .pdata 100083cc..100084eb. Semantic name remains unreviewed. */

void FUN_100083cc(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_1000f560 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_1000f568;
    if (DAT_1000f568 != (undefined4 *)0x0) {
      while (DAT_1000f564 = DAT_1000f564 + -1, _Memory <= DAT_1000f564) {
        if ((code *)*DAT_1000f564 != (code *)0x0) {
          (*(code *)*DAT_1000f564)();
          _Memory = DAT_1000f568;
        }
      }
      free(_Memory);
      DAT_1000f564 = (undefined4 *)0x0;
      DAT_1000f568 = (undefined4 *)0x0;
    }
    FUN_10008510((undefined4 *)&DAT_10009044,(undefined4 *)&DAT_10009048);
  }
  FUN_10008510((undefined4 *)&DAT_1000904c,(undefined4 *)&DAT_10009050);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_1000f56c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 100084ec FUN_100084ec */

/* Boundary evidence: original MIPS .pdata 100084ec..1000850f. Semantic name remains unreviewed. */

void FUN_100084ec(void)

{
  FUN_100083cc(0,0,1);
  return;
}



/* 10008510 FUN_10008510 */

/* Boundary evidence: original MIPS .pdata 10008510..10008563. Semantic name remains unreviewed. */

void FUN_10008510(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 10008564 FUN_10008564 */

/* Boundary evidence: original MIPS .pdata 10008564..1000859f. Semantic name remains unreviewed. */

void FUN_10008564(void)

{
  FUN_10008510((undefined4 *)&DAT_1000903c,(undefined4 *)&DAT_10009040);
  FUN_10008510((undefined4 *)&DAT_10009000,(undefined4 *)&DAT_10009038);
  return;
}



/* 100085e0 FUN_100085e0 */

/* Boundary evidence: original MIPS .pdata 100085e0..10008607. Semantic name remains unreviewed. */

void FUN_100085e0(void)

{
  DAT_1000e0c8 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 10008608 FUN_10008608 */

/* Boundary evidence: original MIPS .pdata 10008608..1000862f. Semantic name remains unreviewed. */

void FUN_10008608(void)

{
  DAT_1000e0cc = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 10008630 FUN_10008630 */

/* Boundary evidence: original MIPS .pdata 10008630..10008657. Semantic name remains unreviewed. */

void FUN_10008630(void)

{
  DAT_1000e0d0 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 10008658 FUN_10008658 */

/* Boundary evidence: original MIPS .pdata 10008658..1000867f. Semantic name remains unreviewed. */

void FUN_10008658(void)

{
  DAT_1000e0d4 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 10008680 FUN_10008680 */

/* Boundary evidence: original MIPS .pdata 10008680..100086a7. Semantic name remains unreviewed. */

void FUN_10008680(void)

{
  DAT_1000e0d8 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 100086a8 FUN_100086a8 */

/* Boundary evidence: original MIPS .pdata 100086a8..100086cf. Semantic name remains unreviewed. */

void FUN_100086a8(void)

{
  DAT_1000ed7c = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 100086d0 FUN_100086d0 */

/* Boundary evidence: original MIPS .pdata 100086d0..100086f7. Semantic name remains unreviewed. */

void FUN_100086d0(void)

{
  DAT_1000ed80 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 100086f8 FUN_100086f8 */

/* Boundary evidence: original MIPS .pdata 100086f8..1000871f. Semantic name remains unreviewed. */

void FUN_100086f8(void)

{
  DAT_1000ed84 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 10008720 FUN_10008720 */

/* Boundary evidence: original MIPS .pdata 10008720..10008747. Semantic name remains unreviewed. */

void FUN_10008720(void)

{
  DAT_1000ed88 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 10008748 FUN_10008748 */

/* Boundary evidence: original MIPS .pdata 10008748..1000876f. Semantic name remains unreviewed. */

void FUN_10008748(void)

{
  DAT_1000ed8c = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 10008770 FUN_10008770 */

/* Boundary evidence: original MIPS .pdata 10008770..10008797. Semantic name remains unreviewed. */

void FUN_10008770(void)

{
  DAT_1000ed90 = RegisterWindowMessageW(L"RVC DECODE DONE");
  return;
}



/* 10008798 FUN_10008798 */

/* Boundary evidence: original MIPS .pdata 10008798..100087bf. Semantic name remains unreviewed. */

void FUN_10008798(void)

{
  DAT_1000ed94 = RegisterWindowMessageW(L"ULC REFRESH");
  return;
}



/* 100087c0 FUN_100087c0 */

/* Boundary evidence: original MIPS .pdata 100087c0..100087e7. Semantic name remains unreviewed. */

void FUN_100087c0(void)

{
  DAT_1000f554 = RegisterWindowMessageW(L"RVC DECODE DONE");
  return;
}


