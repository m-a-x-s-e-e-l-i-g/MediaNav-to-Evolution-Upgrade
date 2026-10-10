/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..0001105b. Semantic name remains unreviewed. */

undefined4 FUN_00011000(HWND param_1,DWORD param_2)

{
  DWORD local_18 [2];
  
  GetWindowThreadProcessId(param_1,local_18);
  if (local_18[0] == param_2) {
    PostMessageW(param_1,0x10,0,0);
  }
  return 1;
}



/* 0001105c FUN_0001105c */

/* Boundary evidence: original MIPS .pdata 0001105c..0001111f. Semantic name remains unreviewed. */

undefined4 FUN_0001105c(LPCWSTR param_1)

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
      EnumWindows(FUN_00011000,local_18[0]);
      DVar1 = WaitForSingleObject(hHandle,10000);
      if (DVar1 != 0) {
        TerminateProcess(hHandle,0);
      }
      CloseHandle(hHandle);
    }
  }
  return 0;
}



/* 00011120 FUN_00011120 */

/* Boundary evidence: original MIPS .pdata 00011120..0001141b. Semantic name remains unreviewed. */

undefined4 FUN_00011120(void)

{
  int iVar1;
  int *piVar2;
  HANDLE pvVar3;
  undefined4 *local_38;
  DWORD DStack_34;
  undefined1 auStack_30 [8];
  
  iVar1 = MessageBoxW((HWND)0x0,L"Etes-vous sûr de vouloir redémarrer ?",L"Redémarrer",4);
  if (iVar1 != 7) {
    FUN_0001105c(L"UpgradeManager");
    FUN_0001105c(L"MGRMCM");
    FUN_0001105c(L"AppMain");
    FUN_0001105c(L"CodeChecker");
    FUN_0001105c(L"MgrUsb");
    FUN_0001105c(L"MgrIpod");
    FUN_0001105c(L"MgrDab");
    FUN_0001105c(L"BLUE");
    FUN_0001105c(L"NAVI");
    iVar1 = 0;
    local_38 = (undefined4 *)__2_YAPAXI_Z(0x120);
    if (local_38 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_0001144c(local_38);
    }
    if ((piVar2 != (int *)0x0) && (iVar1 = FUN_0001146c(piVar2), iVar1 != 0)) {
      local_38 = (undefined4 *)CONCAT22(local_38._2_2_,0x17);
      FUN_00011a04(piVar2,'\x01',1,2,&local_38);
    }
    pvVar3 = CreateFileW(L"MGR1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (pvVar3 != (HANDLE)0xffffffff) {
      local_38 = (undefined4 *)CONCAT22((short)((uint)local_38 >> 0x10),0x100);
      DeviceIoControl(pvVar3,2,&local_38,2,(LPVOID)0x0,0,&DStack_34,(LPOVERLAPPED)0x0);
      CloseHandle(pvVar3);
    }
    pvVar3 = (HANDLE)OpenStore(L"DSK1:");
    if (pvVar3 != (HANDLE)0xffffffff) {
      DismountStore(pvVar3);
      CloseHandle(pvVar3);
    }
    if (iVar1 != 0) {
      FUN_00011868(piVar2,'\0',1,0,(void *)0x0);
    }
    if (piVar2 != (int *)0x0) {
      FUN_000116a0(piVar2);
      __3_YAXPAX_Z(piVar2);
    }
    pvVar3 = CreateFileW(L"DSK1:",0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0x0);
    if (pvVar3 != (HANDLE)0xffffffff) {
      local_38 = (undefined4 *)0x0;
      DeviceIoControl(pvVar3,0x71f84,&local_38,4,auStack_30,4,&DStack_34,(LPOVERLAPPED)0x0);
      CloseHandle(pvVar3);
    }
    SetSystemPowerState(0,0x200000);
  }
  return 0;
}



/* 0001141c Unwind@0001141c */

/* Boundary evidence: original MIPS .pdata 0001141c..0001144b. Semantic name remains unreviewed. */

void Unwind_0001141c(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x38));
  return;
}



/* 0001144c FUN_0001144c */

undefined4 * FUN_0001144c(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x100;
  return param_1;
}



/* 0001146c FUN_0001146c */

/* Boundary evidence: original MIPS .pdata 0001146c..000115bb. Semantic name remains unreviewed. */

undefined4 FUN_0001146c(int *param_1)

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
      goto LAB_00011598;
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
LAB_00011598:
  NKDbgPrintfW(pwVar3);
  return 0;
}



/* 000115bc FUN_000115bc */

/* Boundary evidence: original MIPS .pdata 000115bc..0001164f. Semantic name remains unreviewed. */

undefined4 FUN_000115bc(undefined4 *param_1)

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



/* 00011650 FUN_00011650 */

/* Boundary evidence: original MIPS .pdata 00011650..0001169f. Semantic name remains unreviewed. */

DWORD FUN_00011650(undefined4 *param_1,LPCVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD local_10 [2];
  
  local_10[0] = 0;
  BVar1 = WriteFile((HANDLE)*param_1,param_2,param_3,local_10,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    NKDbgPrintfW(&DAT_00013318);
    local_10[0] = 0;
  }
  return local_10[0];
}



/* 000116a0 FUN_000116a0 */

/* Boundary evidence: original MIPS .pdata 000116a0..000116bb. Semantic name remains unreviewed. */

void FUN_000116a0(undefined4 *param_1)

{
  FUN_000115bc(param_1);
  return;
}



/* 000116bc FUN_000116bc */

/* Boundary evidence: original MIPS .pdata 000116bc..00011867. Semantic name remains unreviewed. */

undefined4 FUN_000116bc(undefined4 *param_1)

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



/* 00011868 FUN_00011868 */

/* Boundary evidence: original MIPS .pdata 00011868..00011a03. Semantic name remains unreviewed. */

DWORD FUN_00011868(int *param_1,char param_2,undefined1 param_3,size_t param_4,void *param_5)

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
      FUN_00011650(param_1,puVar1,param_4 + 5 & 0xff);
      __3_YAXPAX_Z(puVar1);
      hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000116bc,param_1,0,(LPDWORD)0x0);
      param_1[1] = (int)hHandle;
      DVar2 = WaitForSingleObject(hHandle,500);
      CloseHandle((HANDLE)param_1[1]);
      param_1[1] = 0;
      param_1[2] = 0;
      return DVar2;
    }
    puVar3 = &DAT_0001336c;
  }
  else {
    puVar3 = &DAT_00013390;
  }
  NKDbgPrintfW(puVar3);
  return 0;
}



/* 00011a04 FUN_00011a04 */

/* Boundary evidence: original MIPS .pdata 00011a04..00011ba7. Semantic name remains unreviewed. */

DWORD FUN_00011a04(int *param_1,char param_2,undefined4 param_3,size_t param_4,void *param_5)

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
      FUN_00011650(param_1,puVar1,param_4 + 9 & 0xff);
      __3_YAXPAX_Z(puVar1);
      hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000116bc,param_1,0,(LPDWORD)0x0);
      param_1[1] = (int)hHandle;
      DVar2 = WaitForSingleObject(hHandle,500);
      CloseHandle((HANDLE)param_1[1]);
      param_1[1] = 0;
      param_1[2] = 0;
      return DVar2;
    }
    puVar3 = &DAT_0001336c;
  }
  else {
    puVar3 = &DAT_00013390;
  }
  NKDbgPrintfW(puVar3);
  return 0;
}



/* 00011ca8 FUN_00011ca8 */

/* Boundary evidence: original MIPS .pdata 00011ca8..00011cd3. Semantic name remains unreviewed. */

void FUN_00011ca8(void)

{
  if (DAT_000140b8 != (void *)0x0) {
    free(DAT_000140b8);
  }
  return;
}



/* 00011cd4 FUN_00011cd4 */

/* Boundary evidence: original MIPS .pdata 00011cd4..00011d63. Semantic name remains unreviewed. */

int FUN_00011cd4(wint_t *param_1)

{
  bool bVar1;
  int iVar2;
  wint_t *pwVar3;
  
  bVar1 = false;
  pwVar3 = param_1;
  while ((*pwVar3 != 0 && ((iVar2 = iswctype(*pwVar3,8), iVar2 == 0 || (bVar1))))) {
    if (*pwVar3 == 0x22) {
      bVar1 = !bVar1;
    }
    pwVar3 = pwVar3 + 1;
  }
  return (int)pwVar3 - (int)param_1 >> 1;
}



/* 00011d64 FUN_00011d64 */

/* Boundary evidence: original MIPS .pdata 00011d64..00011e27. Semantic name remains unreviewed. */

void FUN_00011d64(int *param_1,int *param_2,wint_t *param_3)

{
  wint_t wVar1;
  int iVar2;
  wint_t *pwVar3;
  
  while( true ) {
    wVar1 = *param_3;
    pwVar3 = param_3;
    while ((wVar1 != 0 && (iVar2 = iswctype(*pwVar3,8), iVar2 != 0))) {
      pwVar3 = pwVar3 + 1;
      wVar1 = *pwVar3;
    }
    pwVar3 = param_3 + ((int)pwVar3 - (int)param_3 >> 1);
    if (*pwVar3 == 0) break;
    iVar2 = FUN_00011cd4(pwVar3);
    *param_2 = *param_2 + iVar2 + 1;
    param_3 = pwVar3 + iVar2;
    *param_1 = *param_1 + 1;
    if (*param_3 == 0) {
      return;
    }
  }
  return;
}



/* 00011e28 FUN_00011e28 */

/* Boundary evidence: original MIPS .pdata 00011e28..00011fff. Semantic name remains unreviewed. */

undefined4 FUN_00011e28(wchar_t *param_1,wint_t *param_2,int *param_3,undefined4 *param_4)

{
  wint_t wVar1;
  short sVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  undefined4 *puVar9;
  wint_t *pwVar10;
  undefined4 *_Dst;
  short *_Dst_00;
  int local_38;
  undefined4 *local_34;
  int *local_30;
  
  local_30 = param_3;
  sVar4 = wcslen(param_1);
  puVar9 = (undefined4 *)(sVar4 + 1);
  local_38 = 1;
  if (puVar9 != (undefined4 *)0xffffffff) {
    local_34 = puVar9;
    FUN_00011d64(&local_38,(int *)&local_34,param_2);
    iVar3 = local_38;
    puVar5 = malloc(((local_38 + 1) * 2 + (int)local_34) * 2);
    if (puVar5 != (undefined4 *)0x0) {
      _Dst = puVar5 + iVar3 + 1;
      memcpy(_Dst,param_1,(int)puVar9 * 2);
      *puVar5 = _Dst;
      _Dst_00 = (short *)((int)puVar9 * 2 + (int)_Dst);
      local_34 = puVar5;
      do {
        local_34 = local_34 + 1;
        wVar1 = *param_2;
        pwVar10 = param_2;
        while ((wVar1 != 0 && (iVar6 = iswctype(*pwVar10,8), iVar6 != 0))) {
          pwVar10 = pwVar10 + 1;
          wVar1 = *pwVar10;
        }
        pwVar10 = param_2 + ((int)pwVar10 - (int)param_2 >> 1);
        if (*pwVar10 == 0) break;
        iVar6 = FUN_00011cd4(pwVar10);
        memcpy(_Dst_00,pwVar10,iVar6 * 2);
        _Dst_00[iVar6] = 0;
        sVar2 = *_Dst_00;
        psVar7 = _Dst_00;
        psVar8 = _Dst_00;
        while (sVar2 != 0) {
          sVar2 = *psVar7;
          psVar7 = psVar7 + 1;
          if (sVar2 != 0x22) {
            *psVar8 = sVar2;
            psVar8 = psVar8 + 1;
          }
          sVar2 = *psVar7;
        }
        *psVar8 = 0;
        *local_34 = _Dst_00;
        param_2 = pwVar10 + iVar6;
        _Dst_00 = _Dst_00 + iVar6 + 1;
      } while (*param_2 != 0);
      *local_30 = iVar3;
      *param_4 = puVar5;
      puVar5[iVar3] = 0;
      return 1;
    }
  }
  return 0;
}



/* 00012000 FUN_00012000 */

/* Boundary evidence: original MIPS .pdata 00012000..000120f7. Semantic name remains unreviewed. */

void FUN_00012000(HMODULE param_1,wint_t *param_2)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;
  int local_224;
  undefined4 local_220 [2];
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_000140b0;
  DAT_000140c0 = param_1;
  DVar1 = GetModuleFileNameW(param_1,aWStack_218,0x100);
  if (DVar1 == 0) {
    FUN_00012344(0xfffffffd);
  }
  FUN_00012664(FUN_00011ca8);
  FUN_000123e4();
  iVar2 = FUN_00011e28(aWStack_218,param_2,&local_224,local_220);
  if (iVar2 == 0) {
    FUN_00012344(0xfffffffc);
  }
  DAT_000140bc = local_224;
  DAT_000140b8 = local_220[0];
  UVar3 = FUN_00011120();
  FUN_00012324(UVar3);
  FUN_00012344(UVar3);
  FUN_00012784(local_18);
  return;
}



/* 000120f8 FUN_000120f8 */

/* Boundary evidence: original MIPS .pdata 000120f8..00012137. Semantic name remains unreviewed. */

void FUN_000120f8(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x228) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x228),param_1);
  return;
}



/* 00012138 entry */

/* Boundary evidence: original MIPS .pdata 00012138..00012173. Semantic name remains unreviewed. */

void entry(HMODULE param_1,undefined4 param_2,wint_t *param_3)

{
  FUN_00012694();
  FUN_00012000(param_1,param_3);
  return;
}



/* 00012204 FUN_00012204 */

/* Boundary evidence: original MIPS .pdata 00012204..00012323. Semantic name remains unreviewed. */

void FUN_00012204(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_000140c4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000140cc;
    if (DAT_000140cc != (undefined4 *)0x0) {
      while (DAT_000140c8 = DAT_000140c8 + -1, _Memory <= DAT_000140c8) {
        if ((code *)*DAT_000140c8 != (code *)0x0) {
          (*(code *)*DAT_000140c8)();
          _Memory = DAT_000140cc;
        }
      }
      free(_Memory);
      DAT_000140c8 = (undefined4 *)0x0;
      DAT_000140cc = (undefined4 *)0x0;
    }
    FUN_00012390((undefined4 *)&DAT_00013010,(undefined4 *)&DAT_00013014);
  }
  FUN_00012390((undefined4 *)&DAT_00013018,(undefined4 *)&DAT_0001301c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_000140d0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00012324 FUN_00012324 */

/* Boundary evidence: original MIPS .pdata 00012324..00012343. Semantic name remains unreviewed. */

void FUN_00012324(UINT param_1)

{
  FUN_00012204(param_1,0,0);
  return;
}



/* 00012344 FUN_00012344 */

/* Boundary evidence: original MIPS .pdata 00012344..0001238f. Semantic name remains unreviewed. */

void FUN_00012344(UINT param_1)

{
  DAT_000140c4 = 0;
  FUN_00012390((undefined4 *)&DAT_00013018,(undefined4 *)&DAT_0001301c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00012390 FUN_00012390 */

/* Boundary evidence: original MIPS .pdata 00012390..000123e3. Semantic name remains unreviewed. */

void FUN_00012390(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 000123e4 FUN_000123e4 */

/* Boundary evidence: original MIPS .pdata 000123e4..0001241f. Semantic name remains unreviewed. */

void FUN_000123e4(void)

{
  FUN_00012390((undefined4 *)&DAT_00013008,(undefined4 *)&DAT_0001300c);
  FUN_00012390((undefined4 *)&DAT_00013000,(undefined4 *)&DAT_00013004);
  return;
}



/* 00012420 FUN_00012420 */

/* Boundary evidence: original MIPS .pdata 00012420..0001252b. Semantic name remains unreviewed. */

undefined4 FUN_00012420(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_000140cc;
  puVar3 = DAT_000140c8;
  iVar4 = (int)DAT_000140c8 - (int)DAT_000140cc;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_00012464:
    param_1 = 0;
  }
  else {
    if (DAT_000140cc != (void *)0x0) {
      uVar1 = _msize(DAT_000140cc);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_000124d8:
        if (pvVar2 == (void *)0x0) goto LAB_00012464;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_000124d8;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_000140c8 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_000140cc = pvVar2;
  }
  return param_1;
}



/* 0001252c FUN_0001252c */

/* Boundary evidence: original MIPS .pdata 0001252c..00012617. Semantic name remains unreviewed. */

undefined4 FUN_0001252c(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_000140d0 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_000140d0,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_000140d0 == (LPCRITICAL_SECTION)0x0) goto LAB_000125d0;
  }
  EnterCriticalSection(DAT_000140d0);
LAB_000125d0:
  uVar2 = FUN_00012420(param_1);
  FUN_00012618();
  return uVar2;
}



/* 00012618 FUN_00012618 */

/* Boundary evidence: original MIPS .pdata 00012618..00012663. Semantic name remains unreviewed. */

void FUN_00012618(void)

{
  if (DAT_000140d0 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_000140d0);
  }
  return;
}



/* 00012664 FUN_00012664 */

/* Boundary evidence: original MIPS .pdata 00012664..00012693. Semantic name remains unreviewed. */

undefined4 FUN_00012664(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0001252c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00012694 FUN_00012694 */

/* Boundary evidence: original MIPS .pdata 00012694..00012707. Semantic name remains unreviewed. */

void FUN_00012694(void)

{
  uint uVar1;
  
  if ((DAT_000140b0 == 0) || (DAT_000140b0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000140b0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000140b0 == 0) {
      DAT_000140b0 = 0xb064;
    }
  }
  DAT_000140b4 = ~DAT_000140b0;
  return;
}



/* 00012708 FUN_00012708 */

/* Boundary evidence: original MIPS .pdata 00012708..00012783. Semantic name remains unreviewed. */

void FUN_00012708(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_0001280c(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 00012784 FUN_00012784 */

/* Boundary evidence: original MIPS .pdata 00012784..000127cb. Semantic name remains unreviewed. */

void FUN_00012784(uint param_1)

{
  if ((param_1 == DAT_000140b0) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 0001280c FUN_0001280c */

/* Boundary evidence: original MIPS .pdata 0001280c..0001285f. Semantic name remains unreviewed. */

void FUN_0001280c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00012784(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}


