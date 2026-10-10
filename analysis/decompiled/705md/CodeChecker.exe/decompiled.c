/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..000110e3. Semantic name remains unreviewed. */

void FUN_00011000(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  DWORD DVar2;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  _SYSTEMTIME _Stack_1028;
  WCHAR aWStack_1018 [1024];
  wchar_t awStack_818 [1026];
  uint local_14;
  
  local_14 = DAT_00027974;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf_s(awStack_818,0x400,param_1,(va_list)&local_res4);
  GetLocalTime(&_Stack_1028);
  DVar1 = GetTickCount();
  DVar2 = GetTickCount();
  wsprintfW(aWStack_1018,L"[%d,%05d] %s\r\n",DVar2 % 1000,DVar1 / 10,awStack_818);
  OutputDebugStringW(aWStack_1018);
  FUN_0001bb10(local_14);
  return;
}



/* 000110e4 FUN_000110e4 */

/* Boundary evidence: original MIPS .pdata 000110e4..000111fb. Semantic name remains unreviewed. */

undefined4 FUN_000110e4(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  DWORD DVar2;
  undefined4 local_30;
  HKEY local_2c;
  DWORD local_28 [4];
  
  local_28[0] = 4;
  local_28[1] = 4;
  local_30 = param_4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_2c,local_28 + 2);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_2c,param_3,(LPDWORD)0x0,local_28 + 1,(LPBYTE)&local_30,local_28);
    if (LVar1 != 0) {
      local_30 = param_4;
    }
    RegCloseKey(local_2c);
  }
  else {
    DVar2 = GetLastError();
    NKDbgPrintfW(L"\t[Error] CRegUtil::RegReadInt() [0x%08x, 0x%08x]:[0x%08x]\r\n",param_1,param_2,
                 DVar2);
  }
  return local_30;
}



/* 000111fc FUN_000111fc */

/* Boundary evidence: original MIPS .pdata 000111fc..000112c7. Semantic name remains unreviewed. */

bool FUN_000111fc(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4,LPBYTE param_5)

{
  LSTATUS LVar1;
  bool bVar2;
  HKEY local_20;
  DWORD local_1c;
  DWORD aDStack_18 [2];
  
  bVar2 = false;
  local_1c = 3;
  if ((param_5 != (LPBYTE)0x0) &&
     (LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                              &local_20,aDStack_18), LVar1 == 0)) {
    LVar1 = RegQueryValueExW(local_20,param_3,(LPDWORD)0x0,&local_1c,param_5,
                             (LPDWORD)&stack0x00000014);
    bVar2 = LVar1 == 0;
    RegCloseKey(local_20);
  }
  return bVar2;
}



/* 000112c8 FUN_000112c8 */

/* Boundary evidence: original MIPS .pdata 000112c8..00011387. Semantic name remains unreviewed. */

undefined4 FUN_000112c8(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  undefined4 local_resc;
  HKEY local_10;
  DWORD DStack_c;
  
  local_resc = param_4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20006,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_10,&DStack_c);
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_10,param_3,0,4,(BYTE *)&local_resc,4);
    if (LVar1 == 0) {
      RegCloseKey(local_10);
      return 1;
    }
  }
  return 0;
}



/* 00011388 FUN_00011388 */

void FUN_00011388(short *param_1,int param_2,short *param_3)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 != (short *)0x0) && (psVar1 = param_1, param_3 != (short *)0x0)) {
    do {
      sVar2 = *psVar1;
      psVar1 = psVar1 + 1;
    } while (sVar2 != 0);
    iVar4 = ((uint)((int)psVar1 - (int)param_1) >> 1) - 1;
    psVar1 = param_3;
    do {
      sVar2 = *psVar1;
      psVar1 = psVar1 + 1;
    } while (sVar2 != 0);
    iVar3 = ((uint)((int)psVar1 - (int)param_3) >> 1) - 1;
    if (iVar3 + iVar4 < param_2) {
      psVar1 = param_1 + iVar4;
      if ((psVar1 != (short *)0x0) && (0 < iVar3)) {
        sVar2 = *param_3;
        iVar4 = (int)param_3 - (int)psVar1;
        do {
          *psVar1 = sVar2;
          psVar1 = psVar1 + 1;
          sVar2 = *(short *)(iVar4 + (int)psVar1);
          iVar3 = iVar3 + -1;
          if (sVar2 == 0) break;
        } while (0 < iVar3);
        *psVar1 = 0;
        return;
      }
    }
    else {
      iVar3 = param_2 - iVar4;
      if (((0 < iVar3) && (psVar1 = param_1 + iVar4, psVar1 != (short *)0x0)) && (0 < iVar3)) {
        sVar2 = *param_3;
        iVar4 = (int)param_3 - (int)psVar1;
        do {
          *psVar1 = sVar2;
          psVar1 = psVar1 + 1;
          sVar2 = *(short *)(iVar4 + (int)psVar1);
          iVar3 = iVar3 + -1;
          if (sVar2 == 0) break;
        } while (0 < iVar3);
        *psVar1 = 0;
      }
    }
  }
  return;
}



/* 00011494 FUN_00011494 */

bool FUN_00011494(short *param_1,int param_2,short *param_3)

{
  short sVar1;
  
  sVar1 = *param_3;
  for (; (((sVar1 != 0 && (param_2 = param_2 + -1, 0 < param_2)) && (*param_1 == sVar1)) &&
         (*param_1 != 0)); param_1 = param_1 + 1) {
    param_3 = param_3 + 1;
    sVar1 = *param_3;
  }
  return *param_1 != *param_3;
}



/* 000114f8 FUN_000114f8 */

undefined4 * FUN_000114f8(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0xffffffff;
  *param_1 = &PTR_FUN_00026208;
  param_1[0xb] = 0x180;
  param_1[1] = 0;
  param_1[0xaa] = 0x32;
  param_1[0xa8] = 0;
  param_1[0xa6] = 0;
  param_1[0xa7] = 0;
  param_1[0xa9] = 0;
  param_1[0x19] = 0x824;
  param_1[0x18] = 0;
  param_1[0xc] = 0;
  *(undefined2 *)(param_1 + 0x1c) = 0;
  param_1[0x1a] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0x1b] = 0;
  param_1[0xb] = param_1[0xb] & 0xffffffc1 | 1;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  return param_1;
}



/* 000115c8 FUN_000115c8 */

/* Boundary evidence: original MIPS .pdata 000115c8..00011707. Semantic name remains unreviewed. */

void FUN_000115c8(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  puVar4 = (undefined4 *)(param_1 + 0x34);
  *puVar4 = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  iVar3 = 10;
  *(undefined4 *)(param_1 + 0x48) = 0;
  iVar5 = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  if (-1 < param_3) {
    iVar6 = (param_3 + 2) * 4;
    iVar2 = DAT_00027bc4;
    do {
      iVar3 = iVar3 + -1;
      if (iVar3 < 0) break;
      if (iVar2 == 0) {
        MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
        iVar2 = DAT_00027bc4;
      }
      if ((param_3 < 0x16) && (*(int *)(iVar2 + 4) != 0)) {
        uVar1 = *(undefined4 *)(iVar6 + iVar2);
      }
      else {
        uVar1 = 0;
      }
      if (iVar5 < 10) {
        *puVar4 = uVar1;
      }
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 1;
      param_3 = param_3 + -1;
      iVar6 = iVar6 + -4;
    } while (-1 < param_3);
  }
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}



/* 00011708 FUN_00011708 */

void FUN_00011708(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x60) = param_2;
  return;
}



/* 00011710 FUN_00011710 */

void FUN_00011710(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x68) = param_2;
  return;
}



/* 00011718 FUN_00011718 */

void FUN_00011718(undefined4 param_1)

{
  DAT_00028514 = param_1;
  return;
}



/* 00011724 FUN_00011724 */

/* Boundary evidence: original MIPS .pdata 00011724..000117d3. Semantic name remains unreviewed. */

void FUN_00011724(int *param_1,short *param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_2 != (short *)0x0) {
    piVar4 = param_1 + 0x1c;
    iVar5 = 0x80;
    bVar1 = FUN_00011494((short *)piVar4,0x80,param_2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      if (piVar4 != (int *)0x0) {
        sVar2 = *param_2;
        iVar3 = (int)param_2 - (int)piVar4;
        do {
          *(short *)piVar4 = sVar2;
          piVar4 = (int *)((int)piVar4 + 2);
          sVar2 = *(short *)(iVar3 + (int)piVar4);
          iVar5 = iVar5 + -1;
          if (sVar2 == 0) break;
        } while (0 < iVar5);
        *(short *)piVar4 = 0;
      }
      *(undefined2 *)(param_1 + 0x5c) = 0;
      if (param_3 != 0) {
        FUN_00016664(param_1);
      }
    }
  }
  return;
}



/* 000117d4 FUN_000117d4 */

/* Boundary evidence: original MIPS .pdata 000117d4..00011883. Semantic name remains unreviewed. */

void FUN_000117d4(int *param_1,short *param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_2 != (short *)0x0) {
    piVar4 = param_1 + 0x1c;
    iVar5 = 0x10e;
    bVar1 = FUN_00011494((short *)piVar4,0x10e,param_2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      if (piVar4 != (int *)0x0) {
        sVar2 = *param_2;
        iVar3 = (int)param_2 - (int)piVar4;
        do {
          *(short *)piVar4 = sVar2;
          piVar4 = (int *)((int)piVar4 + 2);
          sVar2 = *(short *)(iVar3 + (int)piVar4);
          iVar5 = iVar5 + -1;
          if (sVar2 == 0) break;
        } while (0 < iVar5);
        *(short *)piVar4 = 0;
      }
      *(undefined2 *)(param_1 + 0xa3) = 0;
      if (param_3 != 0) {
        FUN_00016664(param_1);
      }
    }
  }
  return;
}



/* 00011884 FUN_00011884 */

/* Boundary evidence: original MIPS .pdata 00011884..0001195b. Semantic name remains unreviewed. */

undefined4 FUN_00011884(ushort *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  wchar_t local_220;
  undefined1 auStack_21e [518];
  uint local_18;
  
  local_18 = DAT_00027974;
  uVar5 = 0;
  local_220 = L'\0';
  memset(auStack_21e,0,0x206);
  _snwprintf(&local_220,0x103,L"%s",param_1);
  puVar2 = param_1;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
  } while (uVar1 != 0);
  iVar4 = ((uint)((int)puVar2 - (int)param_1) >> 1) - 1;
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      if ((0x58f < *param_1) && (*param_1 < 0x600)) {
        uVar5 = 1;
        break;
      }
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 1;
    } while (iVar3 < iVar4);
  }
  FUN_0001bb10(local_18);
  return uVar5;
}



/* 0001195c FUN_0001195c */

undefined4 FUN_0001195c(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = param_2;
  if (param_2 != (ushort *)0x0) {
    do {
      uVar1 = *puVar2;
      puVar2 = puVar2 + 1;
    } while (uVar1 != 0);
    iVar4 = ((uint)((int)puVar2 - (int)param_2) >> 1) - 1;
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        if ((0x5ff < *param_2) && (*param_2 < 0x700)) {
          return 1;
        }
        iVar3 = iVar3 + 1;
        param_2 = param_2 + 1;
      } while (iVar3 < iVar4);
    }
  }
  return 0;
}



/* 000119d4 FUN_000119d4 */

/* Boundary evidence: original MIPS .pdata 000119d4..00011b1f. Semantic name remains unreviewed. */

int FUN_000119d4(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  ushort local_278 [36];
  wchar_t local_230;
  undefined1 auStack_22e [518];
  uint local_28;
  
  local_28 = DAT_00027974;
  if (param_2 == (ushort *)0x0) {
    FUN_0001bb10(DAT_00027974);
    iVar2 = 0;
  }
  else {
    local_230 = L'\0';
    memset(auStack_22e,0,0x206);
    _snwprintf(&local_230,0x103,L"%s",param_2);
    memcpy(local_278,&DAT_000260d8,0x42);
    iVar2 = 0;
    puVar3 = param_2;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
    } while (uVar1 != 0);
    iVar6 = ((uint)((int)puVar3 - (int)param_2) >> 1) - 1;
    iVar5 = 0;
    puVar3 = param_2;
    if (0 < iVar6) {
      do {
        iVar2 = 0;
        puVar4 = local_278;
        do {
          if (*puVar4 == *puVar3) {
            iVar2 = 1;
            goto LAB_00011af0;
          }
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 1;
        } while (iVar2 < 0x20);
        iVar2 = FUN_0001195c(param_1,param_2);
        if (iVar2 != 0) break;
        iVar5 = iVar5 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar5 < iVar6);
    }
LAB_00011af0:
    FUN_0001bb10(local_28);
  }
  return iVar2;
}



/* 00011b20 FUN_00011b20 */

void FUN_00011b20(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x5c) = param_2;
  return;
}



/* 00011b28 FUN_00011b28 */

/* Boundary evidence: original MIPS .pdata 00011b28..00011b83. Semantic name remains unreviewed. */

void FUN_00011b28(int *param_1)

{
  if (((param_1[0xb] & 0x80U) != 0) && (param_1[1] != 0)) {
    (**(code **)(*param_1 + 0x1c))(param_1);
    FUN_000185c8(param_1[1],param_1 + 2,0);
  }
  return;
}



/* 00011b84 FUN_00011b84 */

/* Boundary evidence: original MIPS .pdata 00011b84..00011c57. Semantic name remains unreviewed. */

void FUN_00011b84(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  (**(code **)(*param_1 + 0x34))(param_1);
  if ((param_1[0xa7] != 0) && (uVar3 = 0, param_1[0xa7] != 0)) {
    iVar4 = 0;
    do {
      if (uVar3 < (uint)param_1[0xa7]) {
        iVar2 = *(int *)(param_1[0xa6] + iVar4);
      }
      else {
        iVar2 = 0;
      }
      if ((*(uint *)(iVar2 + 0x2c) & 0x80) != 0) {
        if (uVar3 < (uint)param_1[0xa7]) {
          piVar1 = *(int **)(iVar4 + param_1[0xa6]);
        }
        else {
          piVar1 = (int *)0x0;
        }
        (**(code **)(*piVar1 + 0x1c))();
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar3 < (uint)param_1[0xa7]);
  }
  return;
}



/* 00011c58 FUN_00011c58 */

/* Boundary evidence: original MIPS .pdata 00011c58..00012023. Semantic name remains unreviewed. */

void FUN_00011c58(int param_1)

{
  WCHAR WVar1;
  LONG x;
  LONG y;
  HGDIOBJ pvVar2;
  HDC pHVar3;
  HGDIOBJ pvVar4;
  DWORD DVar5;
  int iVar6;
  LPCWSTR pWVar7;
  LPCWSTR pWVar8;
  UINT format;
  int iVar9;
  undefined4 *puVar10;
  HDC hdc;
  int iVar11;
  tagSIZE local_50;
  int local_48;
  int local_44;
  int local_40;
  tagRECT local_38;
  
  local_50.cx = *(int *)(param_1 + 8);
  iVar11 = *(int *)(param_1 + 0x10);
  local_50.cy = *(int *)(param_1 + 0xc);
  local_44 = *(int *)(param_1 + 0x14);
  local_38.right = iVar11 + local_50.cx;
  local_38.bottom = local_44 + local_50.cy;
  hdc = *(HDC *)(*(int *)(param_1 + 4) + 0x24);
  local_48 = iVar11;
  local_38.left = local_50.cx;
  local_38.top = local_50.cy;
  if ((*(uint *)(param_1 + 0x2c) & 0x400) != 0) {
    FUN_00018440(*(int *)(param_1 + 4),&local_50.cx);
  }
  iVar9 = local_44;
  y = local_50.cy;
  x = local_50.cx;
  iVar6 = *(int *)(param_1 + 0x68);
  if (iVar6 != 0) {
    FUN_00016eb4(iVar6,*(uint *)(iVar6 + 0x30) & 0xff,(int *)(param_1 + 8));
  }
  iVar6 = FUN_0001686c(param_1);
  if (iVar6 != 0) {
    pvVar2 = (HGDIOBJ)FUN_0001686c(param_1);
    pHVar3 = (HDC)FUN_00018000(pvVar2);
    if ((*(uint *)(param_1 + 0x2c) & 0x200) == 0) {
      BitBlt(hdc,x,y,iVar11,iVar9,pHVar3,0,0,0xcc0020);
    }
    else {
      TransparentImage();
    }
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
  }
  pvVar2 = (HGDIOBJ)0x0;
  if (*(int *)(param_1 + 0x5c) != 0) {
    local_50.cx = 0;
    pWVar8 = (LPCWSTR)(param_1 + 0x70);
    local_50.cy = 0;
    pWVar7 = pWVar8;
    do {
      WVar1 = *pWVar7;
      pWVar7 = pWVar7 + 1;
    } while (WVar1 != L'\0');
    iVar9 = ((uint)((int)pWVar7 - (int)pWVar8) >> 1) - 1;
    local_40 = iVar9;
    pHVar3 = (HDC)FUN_00018000((HGDIOBJ)0x0);
    pvVar4 = SelectObject(pHVar3,*(HGDIOBJ *)(param_1 + 0x30));
    GetTextExtentExPointW(pHVar3,pWVar8,iVar9,0,(LPINT)0x0,(LPINT)0x0,&local_50);
    SelectObject(pHVar3,pvVar4);
    if (iVar11 <= local_50.cx) {
      iVar9 = 0;
      puVar10 = (undefined4 *)(param_1 + 0x34);
      do {
        if ((HGDIOBJ)*puVar10 == (HGDIOBJ)0x0) break;
        pvVar4 = SelectObject(pHVar3,(HGDIOBJ)*puVar10);
        GetTextExtentExPointW
                  (pHVar3,(LPCWSTR)(param_1 + 0x70),local_40,0,(LPINT)0x0,(LPINT)0x0,&local_50);
        SelectObject(pHVar3,pvVar4);
        if (local_50.cx < iVar11) {
          pvVar2 = *(HGDIOBJ *)((iVar9 + 0xd) * 4 + param_1);
          break;
        }
        iVar9 = iVar9 + 1;
        puVar10 = puVar10 + 1;
      } while (iVar9 < 10);
    }
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
  }
  if (pvVar2 == (HGDIOBJ)0x0) {
    pvVar2 = *(HGDIOBJ *)(param_1 + 0x30);
  }
  pvVar2 = SelectObject(hdc,pvVar2);
  SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
  pWVar8 = (LPCWSTR)(param_1 + 0x70);
  pWVar7 = pWVar8;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  iVar9 = *(int *)(param_1 + 0x290);
  iVar6 = ((uint)((int)pWVar7 - (int)pWVar8) >> 1) - 1;
  iVar11 = -1;
  if ((0 < iVar9) && (iVar9 < iVar6)) {
    iVar11 = iVar9;
  }
  if (*(int *)(*(int *)(param_1 + 4) + 0x24) != 0) {
    format = *(uint *)(param_1 + 100);
    iVar9 = FUN_000119d4(param_1,(ushort *)pWVar8);
    if ((iVar9 != 0) ||
       ((pWVar8 != (LPCWSTR)0x0 && (iVar9 = FUN_00011884((ushort *)pWVar8), iVar9 != 0)))) {
      format = format | 0x20000;
    }
    iVar11 = DrawTextW(hdc,pWVar8,iVar11,&local_38,format);
    if (iVar11 == 0) {
      DVar5 = GetLastError();
      FUN_00011000(L"[AppMain] CGUILabel::drawLabel  Label DrawText failed  ******  m_atcText[%s] nTextLen[%d] Error[%d]***********"
                   ,pWVar8,iVar6,DVar5);
    }
  }
  SelectObject(hdc,pvVar2);
  return;
}



/* 00012024 FUN_00012024 */

/* Boundary evidence: original MIPS .pdata 00012024..0001206b. Semantic name remains unreviewed. */

void FUN_00012024(undefined4 *param_1)

{
  if ((HLOCAL)param_1[0xa6] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0xa6]);
    param_1[0xa6] = 0;
  }
  param_1[0xa7] = 0;
  *param_1 = &PTR_LAB_00026744;
  return;
}



/* 0001206c FUN_0001206c */

/* Boundary evidence: original MIPS .pdata 0001206c..0001210f. Semantic name remains unreviewed. */

undefined4 FUN_0001206c(uint param_1)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  ushort local_58 [34];
  uint local_14;
  
  local_14 = DAT_00027974;
  uVar3 = 0;
  memcpy(local_58,&DAT_000260d8,0x42);
  if ((param_1 < 0x590) || (0x5ff < param_1)) {
    iVar2 = 0;
    puVar1 = local_58;
    do {
      if (*puVar1 == param_1) goto LAB_000120ec;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < 0x20);
  }
  else {
LAB_000120ec:
    uVar3 = 1;
  }
  FUN_0001bb10(local_14);
  return uVar3;
}



/* 00012110 FUN_00012110 */

/* Boundary evidence: original MIPS .pdata 00012110..000121df. Semantic name remains unreviewed. */

void FUN_00012110(HDC param_1,LPCWSTR param_2,int param_3,LPRECT param_4,UINT param_5)

{
  WCHAR WVar1;
  int iVar2;
  LPCWSTR pWVar3;
  int iVar4;
  
  pWVar3 = param_2;
  if (param_3 < 0) {
    do {
      WVar1 = *pWVar3;
      pWVar3 = pWVar3 + 1;
    } while (WVar1 != L'\0');
    param_3 = ((uint)((int)pWVar3 - (int)param_2) >> 1) - 1;
  }
  iVar4 = 0;
  pWVar3 = param_2;
  if (0 < param_3) {
    do {
      iVar2 = FUN_0001206c((uint)(ushort)*pWVar3);
      if (iVar2 != 0) {
        param_5 = param_5 | 0x20000;
        break;
      }
      iVar4 = iVar4 + 1;
      pWVar3 = pWVar3 + 1;
    } while (iVar4 < param_3);
  }
  DrawTextW(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 000121e0 FUN_000121e0 */

/* Boundary evidence: original MIPS .pdata 000121e0..00013cbf. Semantic name remains unreviewed. */

void FUN_000121e0(int param_1)

{
  WCHAR WVar1;
  wchar_t wVar2;
  short sVar3;
  ushort uVar4;
  bool bVar5;
  HGDIOBJ pvVar6;
  HDC pHVar7;
  wchar_t *pwVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  LONG LVar12;
  uint uVar13;
  int *piVar14;
  short *psVar15;
  int iVar16;
  undefined2 *puVar17;
  wchar_t *_SubStr;
  UINT UVar18;
  HDC hdc;
  LPCWSTR pWVar19;
  HGDIOBJ cchString;
  int iVar20;
  LPCWSTR lpszString;
  ushort *puVar21;
  LPCWSTR pWVar22;
  LPCWSTR pWVar23;
  tagRECT local_f8;
  tagSIZE local_e8;
  int local_e0;
  HGDIOBJ local_dc;
  int local_d8;
  int local_d4;
  ushort *local_d0;
  int local_cc;
  tagSIZE local_c8;
  HGDIOBJ local_c0;
  tagSIZE local_b8;
  tagSIZE local_b0;
  tagSIZE local_a8;
  tagSIZE local_a0;
  tagSIZE local_98;
  tagSIZE local_90;
  tagSIZE local_88;
  tagSIZE local_80;
  uint local_78;
  int local_74;
  tagRECT local_70;
  int local_60;
  ushort *local_5c;
  int local_58;
  int local_54;
  tagSIZE local_50;
  tagRECT local_48;
  tagSIZE local_38;
  uint local_30;
  
  local_30 = DAT_00027974;
  iVar10 = *(int *)(param_1 + 4);
  if (iVar10 == 0) goto LAB_00013c8c;
  local_d0 = *(ushort **)(param_1 + 0xc);
  iVar16 = *(int *)(param_1 + 0x10);
  local_70.left = *(int *)(param_1 + 8);
  local_d8 = *(int *)(param_1 + 0x14);
  local_70.right = local_70.left + iVar16;
  local_70.bottom = local_d8 + (int)local_d0;
  hdc = *(HDC *)(iVar10 + 0x24);
  local_70.top = (LONG)local_d0;
  local_60 = local_70.left;
  local_5c = local_d0;
  local_58 = iVar16;
  local_54 = local_d8;
  if ((*(uint *)(param_1 + 0x2c) & 0x400) != 0) {
    local_cc = iVar16;
    FUN_00018440(iVar10,&local_60);
  }
  iVar20 = local_54;
  puVar21 = local_5c;
  iVar10 = local_60;
  iVar11 = *(int *)(param_1 + 0x68);
  local_d8 = local_54;
  local_d0 = local_5c;
  local_cc = local_58;
  if (iVar11 != 0) {
    FUN_00016eb4(iVar11,*(uint *)(iVar11 + 0x30) & 0xff,(int *)(param_1 + 8));
  }
  iVar11 = FUN_0001686c(param_1);
  if (iVar11 != 0) {
    pvVar6 = (HGDIOBJ)FUN_0001686c(param_1);
    pHVar7 = (HDC)FUN_00018000(pvVar6);
    if ((*(uint *)(param_1 + 0x2c) & 0x200) == 0) {
      BitBlt(hdc,iVar10,(int)puVar21,iVar16,iVar20,pHVar7,0,0,0xcc0020);
    }
    else {
      TransparentImage();
    }
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
  }
  local_dc = (HGDIOBJ)0x0;
  if (*(int *)(param_1 + 0x5c) == 0) {
LAB_000124e4:
    local_c0 = SelectObject(hdc,*(HGDIOBJ *)(param_1 + 0x30));
  }
  else {
    local_a8.cx = 0;
    pWVar19 = (LPCWSTR)(param_1 + 0x70);
    local_a8.cy = 0;
    pWVar22 = pWVar19;
    do {
      WVar1 = *pWVar22;
      pWVar22 = pWVar22 + 1;
    } while (WVar1 != L'\0');
    cchString = (HGDIOBJ)(((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1);
    local_c0 = cchString;
    pHVar7 = (HDC)FUN_00018000((HGDIOBJ)0x0);
    pvVar6 = SelectObject(pHVar7,*(HGDIOBJ *)(param_1 + 0x30));
    GetTextExtentExPointW(pHVar7,pWVar19,(int)cchString,0,(LPINT)0x0,(LPINT)0x0,&local_a8);
    SelectObject(pHVar7,pvVar6);
    if (iVar16 <= local_a8.cx) {
      piVar14 = (int *)(param_1 + 0x34);
      iVar20 = 0;
      iVar11 = *piVar14;
      while (iVar11 != 0) {
        pvVar6 = SelectObject(pHVar7,(HGDIOBJ)*piVar14);
        GetTextExtentExPointW
                  (pHVar7,(LPCWSTR)(param_1 + 0x70),(int)local_c0,0,(LPINT)0x0,(LPINT)0x0,&local_a8)
        ;
        SelectObject(pHVar7,pvVar6);
        if (local_a8.cx < iVar16) {
          local_dc = *(HGDIOBJ *)((iVar20 + 0xd) * 4 + param_1);
          break;
        }
        piVar14 = piVar14 + 1;
        iVar20 = iVar20 + 1;
        iVar11 = *piVar14;
      }
    }
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
    if (local_dc == (HGDIOBJ)0x0) goto LAB_000124e4;
    local_c0 = SelectObject(hdc,local_dc);
  }
  SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
  _SubStr = (wchar_t *)(param_1 + 0x2b0);
  pwVar8 = wcsstr((wchar_t *)((*(int *)(param_1 + 0x3b4) + 0x38) * 2 + param_1),_SubStr);
  local_e0 = -1;
  if (pwVar8 != (wchar_t *)0x0) {
    local_e0 = (int)pwVar8 + (-0x70 - param_1) >> 1;
  }
  iVar16 = local_e0;
  pWVar19 = (LPCWSTR)(param_1 + 0x70);
  pWVar22 = pWVar19;
  do {
    WVar1 = *pWVar22;
    pWVar22 = pWVar22 + 1;
  } while (WVar1 != L'\0');
  local_d4 = ((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1;
  iVar11 = *(int *)(param_1 + 0x290);
  iVar20 = local_d4;
  if ((0 < iVar11) && (iVar11 < local_d4)) {
    iVar20 = iVar11;
  }
  if ((*_SubStr == L'\0') || (local_e0 == -1)) {
    if (*(int *)(param_1 + 0x6c) != 0) {
      local_48.top = (LONG)local_d0;
      local_48.bottom = local_d8 + (int)local_d0;
      local_48.right = iVar10 + local_cc;
      local_48.left = iVar10;
      DrawTextW(hdc,pWVar19,iVar20,&local_48,*(uint *)(param_1 + 100) | 0x400);
      iVar10 = local_48.top + local_70.bottom + (-local_70.top - local_48.bottom);
      if (iVar10 < 0) {
        iVar10 = iVar10 + 1;
      }
      local_70.top = (iVar10 >> 1) + local_70.top;
    }
    local_80.cx = 0;
    UVar18 = *(uint *)(param_1 + 100);
    local_80.cy = 0;
    iVar10 = FUN_000119d4(param_1,(ushort *)pWVar19);
    if ((iVar10 != 0) ||
       ((pWVar19 != (LPCWSTR)0x0 && (iVar10 = FUN_00011884((ushort *)pWVar19), iVar10 != 0)))) {
      UVar18 = UVar18 | 0x20000;
    }
    DrawTextW(hdc,pWVar19,iVar20,&local_70,UVar18);
    GetTextExtentExPointW(hdc,pWVar19,iVar20,0,(LPINT)0x0,(LPINT)0x0,&local_80);
    if (*(int *)(param_1 + 0x3b8) != 0) {
      local_70.left = local_80.cx + local_70.left;
      SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
      pWVar19 = (LPCWSTR)(param_1 + 0x3c0);
      pWVar22 = pWVar19;
      do {
        WVar1 = *pWVar22;
        pWVar22 = pWVar22 + 1;
      } while (WVar1 != L'\0');
      DrawTextW(hdc,pWVar19,((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1,&local_70,
                *(UINT *)(param_1 + 100));
    }
  }
  else {
    local_98.cx = 0;
    local_98.cy = 0;
    local_c8.cx = 0;
    local_c8.cy = 0;
    local_b8.cx = 0;
    local_b8.cy = 0;
    pwVar8 = _SubStr;
    do {
      wVar2 = *pwVar8;
      pwVar8 = pwVar8 + 1;
    } while (wVar2 != L'\0');
    uVar13 = (uint)((int)pwVar8 - (int)_SubStr) >> 1;
    iVar10 = uVar13 - 1;
    local_78 = (uint)(local_e0 == 0);
    local_f8.left = *(int *)(param_1 + 8);
    local_f8.top = *(LONG *)(param_1 + 0xc);
    local_f8.bottom = *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc);
    local_f8.right = *(int *)(param_1 + 0x10) + local_f8.left;
    if (*(int *)(param_1 + 0x294) != 0) {
      local_74 = 1;
      local_d8 = 0;
      local_cc = -1;
      if (*(short *)((uVar13 + 0x156) * 2 + param_1) == 0x20) {
        iVar10 = uVar13 - 2;
        puVar17 = (undefined2 *)((uVar13 + 0x156) * 2 + param_1);
        iVar16 = uVar13 - 3;
        *puVar17 = 0;
        if (-1 < iVar16) {
          psVar15 = (short *)((uVar13 + 0x155) * 2 + param_1);
          do {
            if (*psVar15 != 0x20) break;
            puVar17 = puVar17 + -1;
            *puVar17 = 0;
            iVar10 = iVar10 + -1;
            iVar16 = iVar16 + -1;
            psVar15 = psVar15 + -1;
          } while (-1 < iVar16);
        }
      }
      local_d0 = (ushort *)((iVar10 + 0x157) * 2 + param_1);
      local_80.cx = FUN_0001206c((uint)*local_d0);
      local_a8.cx = FUN_0001206c((uint)(ushort)*_SubStr);
      iVar16 = 0;
      iVar20 = 0;
      if (0 < iVar10) {
        puVar21 = (ushort *)(param_1 + 0x2b0);
        do {
          if (iVar16 == 0) {
            iVar16 = FUN_0001206c((uint)*puVar21);
          }
          else {
            uVar13 = (uint)*puVar21;
            iVar16 = 0;
            iVar11 = FUN_0001206c(uVar13);
            if (iVar11 == 0) {
              if ((((0x1f < uVar13) && (uVar13 < 0x30)) || ((0x39 < uVar13 && (uVar13 < 0x41)))) ||
                 ((0x7a < uVar13 && (uVar13 < 0x7f)))) {
                iVar16 = 1;
              }
            }
            else {
              iVar16 = 1;
            }
          }
          if (iVar16 == 0) {
            local_74 = 0;
          }
          else {
            local_d8 = 1;
            local_cc = iVar20;
          }
          iVar20 = iVar20 + 1;
          puVar21 = puVar21 + 1;
        } while (iVar20 < iVar10);
      }
      iVar16 = -1;
      piVar14 = (int *)(param_1 + 8);
      GetTextExtentExPointW(hdc,pWVar19,local_e0,0,(LPINT)0x0,(LPINT)0x0,&local_98);
      GetTextExtentExPointW(hdc,(LPCWSTR)(param_1 + 0x2b0),iVar10,0,(LPINT)0x0,(LPINT)0x0,&local_c8)
      ;
      pWVar22 = pWVar19;
      do {
        WVar1 = *pWVar22;
        pWVar22 = pWVar22 + 1;
      } while (WVar1 != L'\0');
      iVar20 = iVar10 + local_e0;
      pWVar23 = (LPCWSTR)((iVar20 + 0x38) * 2 + param_1);
      GetTextExtentExPointW
                (hdc,pWVar23,((((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1) - iVar10) - local_e0,
                 0,(LPINT)0x0,(LPINT)0x0,&local_b8);
      local_38.cx = 0;
      local_38.cy = 0;
      local_88.cx = 0;
      local_88.cy = 0;
      pWVar22 = pWVar19;
      do {
        WVar1 = *pWVar22;
        pWVar22 = pWVar22 + 1;
      } while (WVar1 != L'\0');
      GetTextExtentExPointW
                (hdc,pWVar19,((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1,0,(LPINT)0x0,(LPINT)0x0,
                 &local_38);
      GetTextExtentExPointW(hdc,L" ",1,0,(LPINT)0x0,(LPINT)0x0,&local_88);
      uVar13 = *(uint *)(param_1 + 100);
      if ((uVar13 & 3) != 0) {
        if (((uVar13 & 1) != 0) || ((uVar13 & 2) != 0)) {
          UVar18 = *(uint *)(param_1 + 100);
          local_f8.left = ((*(int *)(param_1 + 0x10) - local_b8.cx) - local_c8.cx) - local_98.cx;
          if ((UVar18 & 1) != 0) {
            if (local_f8.left < 0) {
              local_f8.left = local_f8.left + 1;
            }
            local_f8.left = local_f8.left >> 1;
          }
          local_f8.left = local_f8.left + *piVar14;
          if (DAT_00028514 != 0) {
            UVar18 = UVar18 | 0x20000;
          }
          local_f8.right = local_f8.left + local_98.cx;
          DrawTextW(hdc,pWVar19,local_e0,&local_f8,UVar18);
          local_f8.left = local_f8.right;
          local_f8.right = local_f8.right + local_c8.cx;
          SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
          DrawTextW(hdc,(LPCWSTR)(param_1 + 0x2b0),iVar10,&local_f8,UVar18);
          local_f8.left = local_f8.right;
          local_f8.right = local_f8.right + local_b8.cx;
          SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
          DrawTextW(hdc,pWVar23,-1,&local_f8,UVar18);
        }
        goto LAB_00013c80;
      }
      if (((pWVar19 == (LPCWSTR)0x0) || (iVar11 = FUN_00011884((ushort *)pWVar19), iVar11 == 0)) &&
         (iVar9 = FUN_000119d4(param_1,(ushort *)pWVar19), iVar11 = local_e0, iVar9 == 0)) {
        UVar18 = *(UINT *)(param_1 + 100);
        local_90.cx = 0;
        local_90.cy = 0;
        DrawTextW(hdc,pWVar19,local_e0,&local_f8,UVar18);
        GetTextExtentExPointW(hdc,pWVar19,iVar11,0,(LPINT)0x0,(LPINT)0x0,&local_90);
        iVar16 = local_90.cx + local_f8.left;
        local_f8.left = iVar16;
        SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
        if ((*(uint *)(param_1 + 100) & 0x8000) == 0) {
          DrawTextW(hdc,(LPCWSTR)(param_1 + 0x2b0),iVar10,&local_f8,UVar18);
          GetTextExtentExPointW
                    (hdc,(LPCWSTR)(param_1 + 0x2b0),iVar10,0,(LPINT)0x0,(LPINT)0x0,&local_90);
          local_f8.left = local_90.cx + local_f8.left;
          SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
          DrawTextW(hdc,pWVar23,-1,&local_f8,UVar18);
          pWVar22 = pWVar23;
          do {
            WVar1 = *pWVar22;
            pWVar22 = pWVar22 + 1;
          } while (WVar1 != L'\0');
          GetTextExtentExPointW
                    (hdc,pWVar23,((uint)((int)pWVar22 - (int)pWVar23) >> 1) - 1,0,(LPINT)0x0,
                     (LPINT)0x0,&local_90);
          if (*(int *)(param_1 + 0x3b8) != 0) {
            local_f8.left = local_88.cx + local_90.cx + local_f8.left;
            SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
            pWVar19 = (LPCWSTR)(param_1 + 0x3c0);
            pWVar22 = pWVar19;
            do {
              WVar1 = *pWVar22;
              pWVar22 = pWVar22 + 1;
            } while (WVar1 != L'\0');
            DrawTextW(hdc,pWVar19,((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1,&local_f8,UVar18);
          }
        }
        else {
          local_a0.cx = 0;
          local_a0.cy = 0;
          pWVar22 = (LPCWSTR)(param_1 + 0x2b0);
          local_50.cx = 0;
          local_50.cy = 0;
          GetTextExtentExPointW(hdc,pWVar22,iVar10,0,(LPINT)0x0,(LPINT)0x0,&local_a0);
          GetTextExtentExPointW(hdc,L"...",3,0,(LPINT)0x0,(LPINT)0x0,&local_50);
          if (local_50.cx + local_a0.cx + iVar16 < *(int *)(param_1 + 0x10) + *piVar14) {
            DrawTextW(hdc,pWVar22,iVar10,&local_f8,*(UINT *)(param_1 + 100));
            GetTextExtentExPointW(hdc,pWVar22,iVar10,0,(LPINT)0x0,(LPINT)0x0,&local_a0);
            local_f8.left = local_a0.cx + local_f8.left;
            SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
            GetTextExtentExPointW(hdc,pWVar23,2,0,(LPINT)0x0,(LPINT)0x0,&local_a0);
            if (local_a0.cx + local_f8.left < *(int *)(param_1 + 0x10) + *piVar14) {
              DrawTextW(hdc,pWVar23,-1,&local_f8,*(UINT *)(param_1 + 100));
            }
            else {
              if (*(HGDIOBJ *)(param_1 + 0x4c4) != (HGDIOBJ)0x0) {
                SelectObject(hdc,*(HGDIOBJ *)(param_1 + 0x4c4));
              }
              DrawTextW(hdc,L"...",3,&local_f8,*(UINT *)(param_1 + 100));
            }
          }
          else {
            DrawTextW(hdc,(LPCWSTR)((local_e0 + 0x38) * 2 + param_1),iVar10 + 2,&local_f8,
                      *(UINT *)(param_1 + 100));
          }
        }
        goto LAB_00013c80;
      }
      iVar11 = local_e0;
      local_e8.cx = 0;
      local_e8.cy = 0;
      pvVar6 = (HGDIOBJ)(*(uint *)(param_1 + 100) | 0x20000);
      local_dc = pvVar6;
      if ((local_78 == 0) || (iVar10 < 1)) {
        local_b0.cx = 0;
        local_b0.cy = 0;
        DrawTextW(hdc,pWVar19,local_e0,&local_f8,(UINT)pvVar6);
        GetTextExtentExPointW(hdc,pWVar19,iVar11,0,(LPINT)0x0,(LPINT)0x0,&local_b0);
        local_f8.left = local_b0.cx + local_f8.left;
        SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
        DrawTextW(hdc,(LPCWSTR)(param_1 + 0x2b0),iVar10,&local_f8,(UINT)pvVar6);
        GetTextExtentExPointW
                  (hdc,(LPCWSTR)(param_1 + 0x2b0),iVar10,0,(LPINT)0x0,(LPINT)0x0,&local_b0);
        local_f8.left = local_b0.cx + local_f8.left;
        SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
        DrawTextW(hdc,pWVar23,-1,&local_f8,(UINT)pvVar6);
        pWVar22 = pWVar23;
        do {
          WVar1 = *pWVar22;
          pWVar22 = pWVar22 + 1;
        } while (WVar1 != L'\0');
        GetTextExtentExPointW
                  (hdc,pWVar23,((uint)((int)pWVar22 - (int)pWVar23) >> 1) - 1,0,(LPINT)0x0,
                   (LPINT)0x0,&local_b0);
        LVar12 = local_b0.cx;
      }
      else if (local_80.cx == 0) {
        if (local_a8.cx == 0) {
          if (local_d8 == 0) {
            iVar11 = -1;
            iVar9 = 0;
            if (0 < iVar10) {
              puVar21 = (ushort *)(param_1 + 0x2b0);
              do {
                uVar4 = *puVar21;
                if ((0x40 < uVar4) && ((uVar4 < 0x7b || (0x7e < uVar4)))) break;
                if (uVar4 == 0x20) {
                  iVar16 = iVar9 + 1;
                }
                iVar9 = iVar9 + 1;
                puVar21 = puVar21 + 1;
              } while (iVar9 < iVar10);
            }
            if (iVar20 < local_d4) {
              puVar21 = (ushort *)((iVar20 + 0x38) * 2 + param_1);
              do {
                iVar9 = FUN_0001206c((uint)*puVar21);
                if (iVar9 != 0) {
                  uVar4 = *(ushort *)(param_1 + 0x2b0);
                  if ((0x40 < uVar4) && ((uVar4 < 0x7b || (0x7e < uVar4)))) {
                    psVar15 = (short *)((iVar20 + 0x37) * 2 + param_1);
                    sVar3 = *psVar15;
                    while (sVar3 == 0x20) {
                      psVar15 = psVar15 + -1;
                      iVar20 = iVar20 + -1;
                      sVar3 = *psVar15;
                    }
                    goto LAB_00013320;
                  }
                  if (-1 < iVar16) {
                    if (iVar10 != iVar20) {
                      psVar15 = (short *)((iVar20 + 0x37) * 2 + param_1);
                      sVar3 = *psVar15;
                      while (sVar3 == 0x20) {
                        psVar15 = psVar15 + -1;
                        iVar20 = iVar20 + -1;
                        sVar3 = *psVar15;
                      }
                    }
                    goto LAB_00013320;
                  }
                  if (iVar20 <= iVar10) goto LAB_00013320;
                  puVar21 = (ushort *)((iVar10 + 0x38) * 2 + param_1);
                  iVar11 = iVar10;
                  goto LAB_00013260;
                }
                iVar20 = iVar20 + 1;
                puVar21 = puVar21 + 1;
              } while (iVar20 < local_d4);
            }
            goto LAB_000130d4;
          }
        }
        else if (local_74 != 0) goto LAB_00012cb4;
        bVar5 = false;
        iVar11 = -1;
        if (iVar20 < local_d4) {
          puVar21 = (ushort *)((iVar20 + 0x38) * 2 + param_1);
LAB_00012da8:
          iVar9 = FUN_0001206c((uint)*puVar21);
          if (iVar9 == 0) goto code_r0x00012db8;
          psVar15 = (short *)((iVar20 + 0x37) * 2 + param_1);
          bVar5 = true;
          sVar3 = *psVar15;
          iVar16 = iVar20;
          while (sVar3 == 0x20) {
            psVar15 = psVar15 + -1;
            iVar16 = iVar16 + -1;
            sVar3 = *psVar15;
          }
          pWVar19 = (LPCWSTR)((iVar16 + 0x38) * 2 + param_1);
          FUN_00012110(hdc,pWVar19,-1,&local_f8,*(UINT *)(param_1 + 100));
          pWVar22 = pWVar19;
          do {
            WVar1 = *pWVar22;
            pWVar22 = pWVar22 + 1;
          } while (WVar1 != L'\0');
          GetTextExtentExPointW
                    (hdc,pWVar19,((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1,0,(LPINT)0x0,
                     (LPINT)0x0,&local_e8);
          local_f8.left = local_e8.cx + local_f8.left;
        }
LAB_00012dd0:
        if (-1 < local_cc) {
          iVar11 = local_cc + 1;
          if (*(short *)((local_cc + 0x159) * 2 + param_1) == 0x20) {
            for (psVar15 = (short *)((local_cc + 0x15a) * 2 + param_1); iVar11 = iVar11 + 1,
                *psVar15 == 0x20; psVar15 = psVar15 + 1) {
            }
          }
          if (-1 < iVar11) {
            if (*local_d0 == 0x20) {
              iVar20 = (iVar10 - iVar11) + -1;
            }
            else {
              iVar20 = iVar10 - iVar11;
            }
            SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
            pWVar22 = (LPCWSTR)((iVar11 + 0x158) * 2 + param_1);
            FUN_00012110(hdc,pWVar22,iVar20,&local_f8,*(UINT *)(param_1 + 100));
            GetTextExtentExPointW(hdc,pWVar22,iVar20,0,(LPINT)0x0,(LPINT)0x0,&local_e8);
            local_f8.left = local_e8.cx + local_f8.left;
          }
        }
        if (!bVar5) {
          iVar16 = local_d4;
        }
        iVar16 = iVar16 - iVar10;
        if (0 < iVar16) {
          SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
          pWVar22 = (LPCWSTR)((iVar10 + 0x38) * 2 + param_1);
          FUN_00012110(hdc,pWVar22,iVar16,&local_f8,*(UINT *)(param_1 + 100));
          GetTextExtentExPointW(hdc,pWVar22,iVar16,0,(LPINT)0x0,(LPINT)0x0,&local_e8);
          local_f8.left = local_e8.cx + local_f8.left;
        }
        SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
        pvVar6 = local_dc;
        DrawTextW(hdc,(LPCWSTR)(param_1 + 0x2b0),iVar11,&local_f8,(UINT)local_dc);
        GetTextExtentExPointW
                  (hdc,(LPCWSTR)(param_1 + 0x2b0),iVar11,0,(LPINT)0x0,(LPINT)0x0,&local_e8);
        LVar12 = local_e8.cx;
      }
      else {
LAB_00012cb4:
        pWVar19 = (LPCWSTR)((iVar10 + 0x38) * 2 + param_1);
        DrawTextW(hdc,pWVar19,-1,&local_f8,(UINT)pvVar6);
        pWVar22 = pWVar19;
        do {
          WVar1 = *pWVar22;
          pWVar22 = pWVar22 + 1;
        } while (WVar1 != L'\0');
        GetTextExtentExPointW
                  (hdc,pWVar19,((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1,0,(LPINT)0x0,
                   (LPINT)0x0,&local_e8);
        local_f8.left = local_e8.cx + local_f8.left;
        SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
        DrawTextW(hdc,(LPCWSTR)(param_1 + 0x2b0),iVar10,&local_f8,(UINT)pvVar6);
        GetTextExtentExPointW
                  (hdc,(LPCWSTR)(param_1 + 0x2b0),iVar10,0,(LPINT)0x0,(LPINT)0x0,&local_e8);
        LVar12 = local_e8.cx;
      }
      goto LAB_0001366c;
    }
    UVar18 = *(uint *)(param_1 + 100);
    GetTextExtentExPointW(hdc,pWVar19,local_e0,0,(LPINT)0x0,(LPINT)0x0,&local_98);
    pWVar23 = (LPCWSTR)(param_1 + 0x2b0);
    GetTextExtentExPointW(hdc,pWVar23,iVar10,0,(LPINT)0x0,(LPINT)0x0,&local_c8);
    pWVar22 = pWVar19;
    do {
      WVar1 = *pWVar22;
      pWVar22 = pWVar22 + 1;
    } while (WVar1 != L'\0');
    lpszString = (LPCWSTR)((iVar10 + iVar16 + 0x38) * 2 + param_1);
    GetTextExtentExPointW
              (hdc,lpszString,((((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1) - iVar10) - iVar16,0
               ,(LPINT)0x0,(LPINT)0x0,&local_b8);
    uVar13 = *(uint *)(param_1 + 100);
    if ((uVar13 & 3) == 0) {
      local_f8.right = local_f8.left + local_98.cx;
      iVar20 = FUN_000119d4(param_1,(ushort *)pWVar19);
      if ((iVar20 != 0) ||
         ((pWVar19 != (LPCWSTR)0x0 && (iVar20 = FUN_00011884((ushort *)pWVar19), iVar20 != 0)))) {
        UVar18 = UVar18 | 0x20000;
      }
      DrawTextW(hdc,pWVar19,iVar16,&local_f8,UVar18);
      local_f8.left = local_f8.right;
      local_f8.right = local_f8.right + local_c8.cx;
      SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
      if ((*(uint *)(param_1 + 100) & 0x8000) == 0) {
        DrawTextW(hdc,pWVar23,iVar10,&local_f8,UVar18);
        local_f8.left = local_f8.right;
        local_f8.right = local_f8.right + local_b8.cx;
        SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
        DrawTextW(hdc,lpszString,-1,&local_f8,UVar18);
      }
      else {
        local_f8.right = local_f8.left + local_98.cx;
        DrawTextW(hdc,pWVar19,iVar16,&local_f8,UVar18);
        local_f8.left = local_f8.right;
        local_f8.right = local_f8.right + local_c8.cx;
        SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
        DrawTextW(hdc,pWVar23,iVar10,&local_f8,UVar18);
        local_f8.left = local_f8.right;
        local_f8.right = local_f8.right + local_b8.cx;
        SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
        DrawTextW(hdc,lpszString,-1,&local_f8,UVar18);
      }
    }
    else if (((uVar13 & 1) != 0) || ((uVar13 & 2) != 0)) {
      local_f8.left = ((*(int *)(param_1 + 0x10) - local_b8.cx) - local_c8.cx) - local_98.cx;
      if ((uVar13 & 1) != 0) {
        if (local_f8.left < 0) {
          local_f8.left = local_f8.left + 1;
        }
        local_f8.left = local_f8.left >> 1;
      }
      local_f8.left = local_f8.left + *(int *)(param_1 + 8);
      if (DAT_00028514 != 0) {
        UVar18 = UVar18 | 0x20000;
      }
      local_f8.right = local_f8.left + local_98.cx;
      DrawTextW(hdc,pWVar19,iVar16,&local_f8,UVar18);
      local_f8.left = local_f8.right;
      local_f8.right = local_f8.right + local_c8.cx;
      SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
      DrawTextW(hdc,pWVar23,iVar10,&local_f8,UVar18);
      local_f8.left = local_f8.right;
      local_f8.right = local_f8.right + local_b8.cx;
      SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
      DrawTextW(hdc,lpszString,-1,&local_f8,UVar18);
    }
  }
  goto LAB_00013c80;
code_r0x00012db8:
  iVar20 = iVar20 + 1;
  puVar21 = puVar21 + 1;
  if (local_d4 <= iVar20) goto LAB_00012dd0;
  goto LAB_00012da8;
  while( true ) {
    if (((0x1f < uVar4) && (uVar4 < 0x30)) ||
       (((0x39 < uVar4 && (uVar4 < 0x41)) || ((0x7a < uVar4 && (uVar4 < 0x7f)))))) {
      iVar20 = iVar11;
    }
    iVar11 = iVar11 + 1;
    puVar21 = puVar21 + 1;
    if (iVar20 <= iVar11) break;
LAB_00013260:
    uVar4 = *puVar21;
    if ((uVar4 >= 0x41) && ((uVar4 < 0x7b || (0x7e < uVar4)))) break;
  }
LAB_00013320:
  iVar11 = iVar20;
  if (0 < iVar20) {
    pWVar19 = (LPCWSTR)((iVar20 + 0x38) * 2 + param_1);
    FUN_00012110(hdc,pWVar19,-1,&local_f8,*(UINT *)(param_1 + 100));
    pWVar22 = pWVar19;
    do {
      WVar1 = *pWVar22;
      pWVar22 = pWVar22 + 1;
    } while (WVar1 != L'\0');
    GetTextExtentExPointW
              (hdc,pWVar19,((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1,0,(LPINT)0x0,(LPINT)0x0,
               &local_e8);
    local_f8.left = local_e8.cx + local_f8.left;
  }
LAB_000130d4:
  pWVar22 = (LPCWSTR)(param_1 + 0x2b0);
  iVar20 = iVar10;
  if (*local_d0 == 0x20) {
    iVar20 = iVar10 + -1;
  }
  SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
  if (iVar16 < 1) {
    WVar1 = *pWVar22;
    if (((ushort)WVar1 < 0x41) || ((0x7a < (ushort)WVar1 && ((ushort)WVar1 < 0x7f)))) {
      DrawTextW(hdc,pWVar22,iVar20,&local_f8,(UINT)local_dc);
    }
    else {
      FUN_00012110(hdc,pWVar22,iVar20,&local_f8,*(UINT *)(param_1 + 100));
    }
    GetTextExtentExPointW(hdc,pWVar22,iVar20,0,(LPINT)0x0,(LPINT)0x0,&local_e8);
    local_f8.left = local_e8.cx + local_f8.left;
  }
  else {
    iVar20 = iVar20 - iVar16;
    if (0 < iVar20) {
      pWVar22 = (LPCWSTR)((iVar16 + 0x158) * 2 + param_1);
      FUN_00012110(hdc,pWVar22,iVar20,&local_f8,*(UINT *)(param_1 + 100));
      GetTextExtentExPointW(hdc,pWVar22,iVar20,0,(LPINT)0x0,(LPINT)0x0,&local_e8);
      local_f8.left = local_e8.cx + local_f8.left;
    }
  }
  SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
  if (iVar11 < 0) {
    FUN_00012110(hdc,pWVar23,-1,&local_f8,*(UINT *)(param_1 + 100));
    pWVar22 = pWVar23;
    do {
      WVar1 = *pWVar22;
      pWVar22 = pWVar22 + 1;
    } while (WVar1 != L'\0');
    GetTextExtentExPointW
              (hdc,pWVar23,((uint)((int)pWVar22 - (int)pWVar23) >> 1) - 1,0,(LPINT)0x0,(LPINT)0x0,
               &local_e8);
LAB_000134a4:
    local_f8.left = local_e8.cx + local_f8.left;
  }
  else {
    iVar10 = (iVar11 - iVar10) - local_e0;
    if (0 < iVar10) {
      FUN_00012110(hdc,pWVar23,iVar10,&local_f8,*(UINT *)(param_1 + 100));
      GetTextExtentExPointW(hdc,pWVar23,iVar10,0,(LPINT)0x0,(LPINT)0x0,&local_e8);
      goto LAB_000134a4;
    }
  }
  SetTextColor(hdc,*(COLORREF *)(param_1 + 0x2ac));
  iVar10 = local_f8.left;
  pvVar6 = local_dc;
  if (0 < iVar16) {
    if (*(short *)((iVar16 + 0x38) * 2 + param_1) == 0x20) {
      local_f8.left = local_88.cx + local_f8.left;
    }
    DrawTextW(hdc,(LPCWSTR)(param_1 + 0x2b0),iVar16,&local_f8,(UINT)local_dc);
    GetTextExtentExPointW(hdc,(LPCWSTR)(param_1 + 0x2b0),iVar16,0,(LPINT)0x0,(LPINT)0x0,&local_e8);
    LVar12 = local_e8.cx;
    pvVar6 = local_dc;
LAB_0001366c:
    iVar10 = LVar12 + local_f8.left;
  }
  if (*(int *)(param_1 + 0x3b8) != 0) {
    local_f8.left = local_88.cx + iVar10;
    SetTextColor(hdc,*(COLORREF *)(param_1 + 0x60));
    pWVar19 = (LPCWSTR)(param_1 + 0x3c0);
    pWVar22 = pWVar19;
    do {
      WVar1 = *pWVar22;
      pWVar22 = pWVar22 + 1;
    } while (WVar1 != L'\0');
    DrawTextW(hdc,pWVar19,((uint)((int)pWVar22 - (int)pWVar19) >> 1) - 1,&local_f8,(UINT)pvVar6);
  }
LAB_00013c80:
  SelectObject(hdc,local_c0);
LAB_00013c8c:
  FUN_0001bb10(local_30);
  return;
}



/* 00013cc0 FUN_00013cc0 */

/* Boundary evidence: original MIPS .pdata 00013cc0..00013def. Semantic name remains unreviewed. */

void FUN_00013cc0(int *param_1,int param_2)

{
  HLOCAL pvVar1;
  int *_Dst;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if ((HLOCAL)*param_1 == (HLOCAL)0x0) {
    param_1[2] = param_1[4];
    pvVar1 = LocalAlloc(0x40,param_1[4] << 2);
  }
  else {
    if (param_1[1] != param_1[2]) goto LAB_00013d30;
    iVar4 = param_1[4] + param_1[2];
    param_1[2] = iVar4;
    pvVar1 = LocalReAlloc((HLOCAL)*param_1,iVar4 * 4,2);
  }
  *param_1 = (int)pvVar1;
LAB_00013d30:
  uVar3 = 0;
  if (param_1[1] != 0) {
    iVar4 = 0;
    do {
      _Dst = (int *)(iVar4 + *param_1);
      if ((*_Dst == param_2) && (uVar2 = param_1[1], uVar3 < uVar2)) {
        if (uVar3 == uVar2 - 1) {
          if (uVar2 != 0) {
            param_1[1] = uVar2 - 1;
          }
        }
        else {
          memcpy(_Dst,_Dst + 1,((uVar2 - uVar3) + -1) * 4);
          param_1[1] = param_1[1] + -1;
        }
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar3 < (uint)param_1[1]);
  }
  *(int *)(param_1[1] * 4 + *param_1) = param_2;
  param_1[1] = param_1[1] + 1;
  return;
}



/* 00013df0 FUN_00013df0 */

/* Boundary evidence: original MIPS .pdata 00013df0..00013e3b. Semantic name remains unreviewed. */

int FUN_00013df0(void)

{
  if (DAT_00027bc4 == 0) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
  }
  return DAT_00027bc4;
}



/* 00013e3c FUN_00013e3c */

/* Boundary evidence: original MIPS .pdata 00013e3c..00013eab. Semantic name remains unreviewed. */

undefined4 * FUN_00013e3c(undefined4 *param_1)

{
  HDC pHVar1;
  
  *param_1 = &PTR_LAB_000263c4;
  param_1[1] = 0;
  param_1[0x1b4] = 0;
  param_1[0x1b5] = 0;
  memset(param_1 + 2,0,0x58);
  memset(param_1 + 0x18,0,0x58);
  FUN_000142b8((int)param_1);
  pHVar1 = GetDC((HWND)0x0);
  param_1[0x1b7] = pHVar1;
  return param_1;
}



/* 00013eac FUN_00013eac */

/* Boundary evidence: original MIPS .pdata 00013eac..00013f3b. Semantic name remains unreviewed. */

undefined4 * FUN_00013eac(undefined4 *param_1,uint param_2)

{
  bool bVar1;
  int *piVar2;
  
  piVar2 = DAT_00027bc4;
  bVar1 = DAT_00027bc4 != (int *)0x0;
  *param_1 = &PTR_LAB_000263c4;
  if (bVar1) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
    DAT_00027bc4 = (int *)0x0;
  }
  if ((HDC)param_1[0x1b7] != (HDC)0x0) {
    ReleaseDC((HWND)0x0,(HDC)param_1[0x1b7]);
  }
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00013f3c FUN_00013f3c */

/* Boundary evidence: original MIPS .pdata 00013f3c..00013fa7. Semantic name remains unreviewed. */

void FUN_00013f3c(undefined4 *param_1)

{
  bool bVar1;
  int *piVar2;
  
  piVar2 = DAT_00027bc4;
  bVar1 = DAT_00027bc4 != (int *)0x0;
  *param_1 = &PTR_LAB_000263c4;
  if (bVar1) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
    DAT_00027bc4 = (int *)0x0;
  }
  if ((HDC)param_1[0x1b7] != (HDC)0x0) {
    ReleaseDC((HWND)0x0,(HDC)param_1[0x1b7]);
  }
  return;
}



/* 00013fa8 FUN_00013fa8 */

void FUN_00013fa8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x6d4) = param_2;
  return;
}



/* 00013fb0 FUN_00013fb0 */

/* Boundary evidence: original MIPS .pdata 00013fb0..00013ff3. Semantic name remains unreviewed. */

void FUN_00013fb0(void)

{
  if (DAT_00027bc4 != (int *)0x0) {
    (**(code **)(*DAT_00027bc4 + 8))(DAT_00027bc4,1);
    DAT_00027bc4 = (int *)0x0;
  }
  return;
}



/* 00013ff4 FUN_00013ff4 */

/* Boundary evidence: original MIPS .pdata 00013ff4..0001414f. Semantic name remains unreviewed. */

undefined4
FUN_00013ff4(int param_1,int param_2,LPCWSTR param_3,int param_4,int param_5,BYTE param_6,
            BYTE param_7)

{
  undefined4 uVar1;
  HFONT pHVar2;
  int *piVar3;
  undefined8 uVar4;
  LOGFONTW local_78;
  uint local_1c;
  
  local_1c = DAT_00027974;
  if ((param_2 < 0x16) && (piVar3 = (int *)((param_2 + 2) * 4 + param_1), *piVar3 == 0)) {
    memset(&local_78,0,0x5c);
    wsprintfW(local_78.lfFaceName,param_3);
    local_78.lfCharSet = '\0';
    if (param_5 == 0) {
      local_78.lfWeight = 400;
    }
    else {
      local_78.lfWeight = 700;
    }
    local_78.lfClipPrecision = '\x02';
    local_78.lfPitchAndFamily = '\x02';
    local_78.lfQuality = '\x04';
    local_78.lfItalic = param_6;
    local_78.lfHeight = -param_4;
    local_78.lfOutPrecision = '\x01';
    local_78.lfUnderline = param_7;
    uVar4 = __litodp(param_4);
    uVar4 = __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0xd70a3d71,0x3fdd70a3);
    local_78.lfWidth = __dptoli((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    *(int *)((param_2 + 0x18) * 4 + param_1) = param_4;
    pHVar2 = CreateFontIndirectW(&local_78);
    *piVar3 = (int)pHVar2;
    *(undefined4 *)(param_1 + 4) = 1;
    FUN_0001bb10(local_1c);
    uVar1 = 1;
  }
  else {
    FUN_0001bb10(DAT_00027974);
    uVar1 = 0;
  }
  return uVar1;
}



/* 00014150 FUN_00014150 */

/* Boundary evidence: original MIPS .pdata 00014150..000142b7. Semantic name remains unreviewed. */

int FUN_00014150(int *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  short *psVar7;
  int iVar8;
  
  if ((param_2 < param_1[0x1b5]) && (param_2 != -1)) {
    iVar8 = param_2 * 4;
    piVar5 = (int *)(param_1[0x1b4] + iVar8);
    if (*piVar5 == 0) {
      psVar3 = (short *)(**(code **)(*param_1 + 0xc))(param_1);
      if ((*(int *)(param_1[0x1b4] + iVar8) == 0) && (psVar6 = psVar3, psVar3 != (short *)0x0)) {
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        psVar7 = &DAT_000262c8;
        psVar6 = psVar3 + (((uint)((int)psVar6 - (int)psVar3) >> 1) - 4);
        do {
          sVar1 = *psVar6;
          sVar2 = *psVar7;
          if (sVar1 == 0) break;
          psVar6 = psVar6 + 1;
          psVar7 = psVar7 + 1;
        } while (sVar1 == sVar2);
        if (sVar1 != sVar2) {
          iVar4 = SHLoadDIBitmap(psVar3);
          if (iVar4 == 0) {
            NKDbgPrintfW(L"\r\n~~~~~~~~ (%s) file not found!!!!\r\n",psVar3);
          }
          *(int *)(param_1[0x1b4] + iVar8) = iVar4;
          return *(int *)(param_1[0x1b4] + iVar8);
        }
        NKDbgPrintfW(L"[pngpngpng] ====PNG FILE DECODING %s, BG BITMAP HANDLE 0x%08X ========== \r\n"
                     ,psVar3,0);
        *(undefined4 *)(param_1[0x1b4] + iVar8) = 0;
      }
      piVar5 = (int *)(param_1[0x1b4] + iVar8);
    }
    iVar8 = *piVar5;
  }
  else {
    iVar8 = 0;
  }
  return iVar8;
}



/* 000142b8 FUN_000142b8 */

/* Boundary evidence: original MIPS .pdata 000142b8..00014413. Semantic name remains unreviewed. */

void FUN_000142b8(int param_1)

{
  WCHAR WVar1;
  HMODULE hModule;
  LPWSTR pWVar2;
  uint uVar3;
  WCHAR *pWVar4;
  int iVar5;
  short *psVar6;
  WCHAR *pWVar7;
  int iVar8;
  LPWSTR lpFilename;
  
  lpFilename = (LPWSTR)(param_1 + 0xb8);
  hModule = GetModuleHandleW((LPCWSTR)0x0);
  iVar8 = 0x104;
  GetModuleFileNameW(hModule,lpFilename,0x104);
  pWVar2 = lpFilename;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  uVar3 = (uint)((int)pWVar2 - (int)lpFilename) >> 1;
  iVar5 = uVar3 - 1;
  if (0 < iVar5) {
    psVar6 = (short *)((uVar3 + 0x5b) * 2 + param_1);
    do {
      if (*psVar6 == 0x5c) {
        pWVar7 = (WCHAR *)(param_1 + 0x2c0);
        *(undefined2 *)((iVar5 + 0x5d) * 2 + param_1) = 0;
        iVar5 = 0x104;
        pWVar4 = pWVar7;
        goto LAB_00014390;
      }
      iVar5 = iVar5 + -1;
      psVar6 = psVar6 + -1;
    } while (0 < iVar5);
  }
  *(undefined2 *)(param_1 + 0x2c0) = 0x5c;
  *(undefined2 *)(param_1 + 0x4c8) = 0x5c;
  *(undefined2 *)(param_1 + 0x2c2) = 0;
  *(undefined2 *)(param_1 + 0x4ca) = 0;
  return;
LAB_00014390:
  if (iVar5 == 0) goto LAB_000143cc;
  WVar1 = *lpFilename;
  *pWVar4 = WVar1;
  if (WVar1 == L'\0') goto joined_r0x000143b4;
  pWVar4 = pWVar4 + 1;
  lpFilename = lpFilename + 1;
  iVar5 = iVar5 + -1;
  goto LAB_00014390;
joined_r0x000143b4:
  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pWVar4 = L'\0';
    pWVar4 = pWVar4 + 1;
  }
LAB_000143cc:
  pWVar4 = (WCHAR *)(param_1 + 0x4c8);
  while( true ) {
    if (iVar8 == 0) {
      return;
    }
    WVar1 = *pWVar7;
    *pWVar4 = WVar1;
    if (WVar1 == L'\0') break;
    pWVar4 = pWVar4 + 1;
    pWVar7 = pWVar7 + 1;
    iVar8 = iVar8 + -1;
  }
  for (; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pWVar4 = L'\0';
    pWVar4 = pWVar4 + 1;
  }
  return;
}



/* 00014414 FUN_00014414 */

/* Boundary evidence: original MIPS .pdata 00014414..00014467. Semantic name remains unreviewed. */

void FUN_00014414(int param_1,short *param_2)

{
  undefined *puVar1;
  
  if (param_2 != (short *)0x0) {
    if (*param_2 == 0x5c) {
      puVar1 = &DAT_0002631c;
    }
    else {
      puVar1 = (undefined *)(param_1 + 0xb8);
    }
    _snwprintf((wchar_t *)(param_1 + 0x4c8),0x103,L"%s%s",puVar1,param_2);
  }
  return;
}



/* 00014468 FUN_00014468 */

/* Boundary evidence: original MIPS .pdata 00014468..000144bb. Semantic name remains unreviewed. */

void FUN_00014468(int param_1,short *param_2)

{
  undefined *puVar1;
  
  if (param_2 != (short *)0x0) {
    if (*param_2 == 0x5c) {
      puVar1 = &DAT_0002631c;
    }
    else {
      puVar1 = (undefined *)(param_1 + 0xb8);
    }
    _snwprintf((wchar_t *)(param_1 + 0x2c0),0x103,L"%s%s",puVar1,param_2);
  }
  return;
}



/* 000144c4 FUN_000144c4 */

/* Boundary evidence: original MIPS .pdata 000144c4..000145df. Semantic name remains unreviewed. */

undefined4 * FUN_000144c4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002666c;
  param_1[1] = &PTR_FUN_00026830;
  param_1[4] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0x32;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[0x11] = 0;
  param_1[0xc] = 0xffffffff;
  param_1[0x21] = 700;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x22] = 200;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0xb0] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  memset(param_1 + 0x2d,0,0x208);
  param_1[0xb1] = 0;
  param_1[0xaf] = 0;
  return param_1;
}



/* 000145e0 FUN_000145e0 */

/* Boundary evidence: original MIPS .pdata 000145e0..0001466f. Semantic name remains unreviewed. */

void FUN_000145e0(int *param_1)

{
  *param_1 = (int)&PTR_FUN_0002666c;
  FUN_0001522c(param_1);
  param_1[1] = (int)&PTR_FUN_00026830;
  if (((HDC)param_1[0xb] != (HDC)0x0) && ((HWND)param_1[7] != (HWND)0x0)) {
    ReleaseDC((HWND)param_1[7],(HDC)param_1[0xb]);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
    param_1[2] = 0;
  }
  param_1[3] = 0;
  return;
}



/* 00014670 Unwind@00014670 */

/* Boundary evidence: original MIPS .pdata 00014670..000146a3. Semantic name remains unreviewed. */

void Unwind_00014670(void)

{
  int *in_v0;
  
  FUN_0001813c((undefined4 *)(*in_v0 + 4));
  return;
}



/* 000146a4 FUN_000146a4 */

/* Boundary evidence: original MIPS .pdata 000146a4..00014763. Semantic name remains unreviewed. */

void FUN_000146a4(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x74) != 0) {
    if (DAT_00027984 - 1 < DAT_00027984) {
      iVar1 = *(int *)((DAT_00027984 - 1) * 4 + DAT_00027980);
    }
    else {
      iVar1 = 0;
    }
    if (((*(int *)(param_1 + 0x78) != 0) && (iVar1 != 0)) && (*(int *)(iVar1 + 0x78) != 0)) {
      FUN_00018abc(*(int *)(param_1 + 0x78));
    }
    (**(code **)(**(int **)(param_1 + 0x74) + 0x40))();
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  if (*(HWND *)(param_1 + 0x50) != (HWND)0x0) {
    EnableWindow(*(HWND *)(param_1 + 0x50),1);
    KillTimer(*(HWND *)(param_1 + 0x50),0x40c);
  }
  return;
}



/* 00014764 FUN_00014764 */

/* Boundary evidence: original MIPS .pdata 00014764..00014937. Semantic name remains unreviewed. */

void FUN_00014764(int *param_1,HWND param_2)

{
  int iVar1;
  tagPAINTSTRUCT tStack_68;
  uint local_28;
  
  local_28 = DAT_00027974;
  BeginPaint(param_2,&tStack_68);
  iVar1 = param_1[8];
  if (DAT_00028530 == 0) {
    if (((iVar1 != 0) && (*(int *)(iVar1 + 0x50) != 0)) && (*(int *)(iVar1 + 0x68) != 0)) {
      FUN_00018000((HGDIOBJ)0x0);
      BitBlt((HDC)param_1[0xb],tStack_68.rcPaint.left,tStack_68.rcPaint.top,
             tStack_68.rcPaint.right - tStack_68.rcPaint.left,
             tStack_68.rcPaint.bottom - tStack_68.rcPaint.top,(HDC)param_1[10],
             tStack_68.rcPaint.left,tStack_68.rcPaint.top,0xcc0020);
      SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
      LeaveCriticalSection(DAT_00028538);
    }
    (**(code **)(*param_1 + 0x30))(param_1);
  }
  else {
    if (((iVar1 != 0) && (*(int *)(iVar1 + 0x50) != 0)) &&
       ((*(int *)(iVar1 + 0x68) != 0 && (*(int *)(iVar1 + 0x6c) != 0)))) {
      FUN_00018000((HGDIOBJ)0x0);
      BitBlt((HDC)param_1[0xb],0,0,0,0,(HDC)param_1[10],0,0,0xcc0020);
      SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
      LeaveCriticalSection(DAT_00028538);
    }
    if ((param_1[0x1d] != 0) && (param_1[0x1c] == 1)) {
      SetForegroundWindow(*(HWND *)(param_1[0x1d] + 0x50));
    }
  }
  EndPaint(param_2,&tStack_68);
  FUN_0001bb10(local_28);
  return;
}



/* 00014938 FUN_00014938 */

/* Boundary evidence: original MIPS .pdata 00014938..00014a2b. Semantic name remains unreviewed. */

void FUN_00014938(int *param_1)

{
  int iVar1;
  HGDIOBJ pvVar2;
  HDC hdcSrc;
  int cx;
  int y;
  int x;
  int *piVar3;
  
  piVar3 = param_1 + 1;
  iVar1 = FUN_000181a0((int)piVar3);
  if (iVar1 != 0) {
    x = param_1[0xd];
    y = param_1[0xe];
    cx = param_1[0xf];
    iVar1 = param_1[0x10];
    pvVar2 = (HGDIOBJ)FUN_000181a0((int)piVar3);
    hdcSrc = (HDC)FUN_00018000(pvVar2);
    BitBlt((HDC)param_1[10],x,y,cx,iVar1,hdcSrc,x,y,0xcc0020);
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
  }
  FUN_0001850c((int)piVar3);
  if (param_1[0x1e] != 0) {
    FUN_0001850c(param_1[0x1e] + 4);
  }
  (**(code **)(*param_1 + 0x2c))(param_1);
  return;
}



/* 00014a2c FUN_00014a2c */

/* Boundary evidence: original MIPS .pdata 00014a2c..00014eb3. Semantic name remains unreviewed. */

LRESULT FUN_00014a2c(int *param_1,HWND param_2,uint param_3,uint param_4,uint param_5)

{
  LRESULT LVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint local_28;
  uint local_24;
  
  piVar2 = (int *)param_1[0x1e];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2,param_2,param_3,param_4,param_5);
  }
  if (param_3 < 0x114) {
    if (param_3 == 0x113) {
      if (param_4 < 0x3f9) {
        if (param_4 == 0x3f8) {
          (**(code **)(*param_1 + 0x68))(param_1);
          return 1;
        }
        if (param_4 == 0x3e9) {
          KillTimer(param_2,0x3e9);
          return 1;
        }
        if (param_4 == 0x3f6) {
          if ((HWND)param_1[0x14] != (HWND)0x0) {
            KillTimer((HWND)param_1[0x14],0x3f6);
          }
          iVar3 = param_1[9];
          if (iVar3 == 0) {
            return 1;
          }
          if (*(int *)(iVar3 + 0x38) == 0) {
            return 1;
          }
          (**(code **)(*param_1 + 0x44))(param_1,*(undefined4 *)(iVar3 + 0x48),3);
          param_1[0x11] = 1;
          SetTimer((HWND)param_1[0x14],0x3f7,param_1[0x22],(TIMERPROC)0x0);
          return 1;
        }
        if (param_4 == 0x3f7) {
          iVar3 = param_1[9];
          if ((iVar3 != 0) && (*(int *)(iVar3 + 0x38) != 0)) {
            (**(code **)(*param_1 + 0x44))(param_1,*(undefined4 *)(iVar3 + 0x48),4);
            return 1;
          }
          if ((HWND)param_1[0x14] != (HWND)0x0) {
            KillTimer((HWND)param_1[0x14],0x3f7);
          }
          param_1[0x11] = 0;
          return 1;
        }
      }
      else {
        if (param_4 == 0x40c) {
          KillTimer(param_2,0x40c);
          EnableWindow(param_2,1);
          return 1;
        }
        if (param_4 == 0x43b) {
          if (3 < param_1[0xaf]) {
            KillTimer(param_2,0x43b);
          }
          param_1[0xaf] = param_1[0xaf] + 1;
          uVar4 = DAT_00027984 - 1;
          if (uVar4 < DAT_00027984) {
            iVar3 = *(int *)(uVar4 * 4 + DAT_00027980);
          }
          else {
            iVar3 = 0;
          }
          if (*(int *)(iVar3 + 0x74) == 0) {
            return 1;
          }
          if (uVar4 < DAT_00027984) {
            iVar3 = *(int *)(uVar4 * 4 + DAT_00027980);
          }
          else {
            iVar3 = 0;
          }
          if (*(int *)(*(int *)(iVar3 + 0x74) + 0x70) == 0) {
            return 1;
          }
          SetForegroundWindow(param_2);
          return 1;
        }
      }
      (**(code **)(*param_1 + 0x18))(param_1,param_2,0x113,param_4,param_5);
    }
    else if (param_3 == 1) {
      (**(code **)(*param_1 + 0x14))(param_1,param_2,param_4,param_5);
    }
    else if (param_3 == 6) {
      if (param_4 == 0) {
        piVar2 = (int *)param_1[9];
        if (piVar2 != (int *)0x0) {
          local_28 = 0xffffffff;
          local_24 = 0xffffffff;
          (**(code **)(*piVar2 + 0xc))(piVar2,&local_28);
        }
        (**(code **)(*param_1 + 100))(param_1,1);
      }
      else {
        if (0 < param_1[0x1f]) {
          SetTimer((HWND)param_1[0x14],0x3f8,param_1[0x1f],(TIMERPROC)0x0);
        }
        (**(code **)(*param_1 + 100))(param_1,0);
      }
    }
    else {
      if (param_3 != 0xf) goto LAB_00014de8;
      FUN_00014764(param_1,param_2);
      if ((DAT_00028530 == 0) && (DAT_00028528 != 0)) {
        DAT_00028530 = 1;
      }
    }
  }
  else if (param_3 == 0x200) {
    FUN_00015720((int)param_1,param_5);
  }
  else if (param_3 == 0x201) {
    KillTimer((HWND)param_1[0x14],0x3f8);
    FUN_00015640((int)param_1,param_5);
  }
  else {
    if (param_3 != 0x202) {
LAB_00014de8:
      LVar1 = DefWindowProcW(param_2,param_3,param_4,param_5);
      return LVar1;
    }
    if (0 < param_1[0x1f]) {
      SetTimer((HWND)param_1[0x14],0x3f8,param_1[0x1f],(TIMERPROC)0x0);
    }
    local_28 = param_5 & 0xffff;
    local_24 = param_5 >> 0x10;
    ReleaseCapture();
    piVar2 = (int *)param_1[9];
    param_1[0x18] = 0;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,&local_28);
    }
    FUN_000163ec((int)param_1);
  }
  return 1;
}



/* 00014eb4 FUN_00014eb4 */

/* Boundary evidence: original MIPS .pdata 00014eb4..00014f97. Semantic name remains unreviewed. */

int FUN_00014eb4(wchar_t *param_1,HINSTANCE param_2,HWND param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  WNDCLASSW *pWVar2;
  HWND hWnd;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 == 0) {
    *(HINSTANCE *)(param_1 + 0x24) = param_2;
    pWVar2 = FUN_00016328(param_1,param_2,FUN_000155c4);
    hWnd = CreateWindowExW(0x4000000,pWVar2->lpszClassName,pWVar2->lpszClassName,0x90000000,0,0,800,
                           0x1e0,param_3,(HMENU)0x0,param_2,(LPVOID)0x0);
    *(HWND *)(param_1 + 0x28) = hWnd;
    if (hWnd == (HWND)0x0) {
      GetLastError();
      iVar1 = 0;
    }
    else {
      SetWindowLongW(hWnd,-0x15,(LONG)param_1);
      FUN_00014f98((int *)param_1,param_4,param_5);
      iVar1 = *(int *)(param_1 + 0x28);
    }
  }
  return iVar1;
}



/* 00014f98 FUN_00014f98 */

/* Boundary evidence: original MIPS .pdata 00014f98..000150cb. Semantic name remains unreviewed. */

int FUN_00014f98(int *param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  
  param_1[0x1c] = param_3;
  param_1[0x1b] = 0;
  param_1[0x1a] = 0;
  if (param_1[3] == 0) {
    (**(code **)(*param_1 + 0x1c))(param_1,param_2);
  }
  (**(code **)(*param_1 + 0x20))(param_1,param_2);
  (**(code **)(*param_1 + 0x28))(param_1);
  iVar2 = param_1[0x1e];
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0x20) = param_1[8];
    *(int *)(iVar2 + 0x28) = param_1[10];
    FUN_000183ac(iVar2 + 4,param_1[0xc]);
    *(int *)(iVar2 + 0x2c) = param_1[0xb];
  }
  pcVar1 = *(code **)(*param_1 + 0x24);
  param_1[0x1a] = 1;
  (*pcVar1)(param_1);
  if ((param_3 != 0) && (param_1[0x1c] != 0)) {
    if ((HWND)param_1[0x14] != (HWND)0x0) {
      EnableWindow((HWND)param_1[0x14],1);
      KillTimer((HWND)param_1[0x14],0x40c);
    }
    ShowWindow((HWND)param_1[0x14],1);
    SetForegroundWindow((HWND)param_1[0x14]);
    UpdateWindow((HWND)param_1[0x14]);
  }
  (**(code **)(*param_1 + 0x34))(param_1);
  param_1[0x1b] = 1;
  return param_1[0x14];
}



/* 000150cc FUN_000150cc */

/* Boundary evidence: original MIPS .pdata 000150cc..0001522b. Semantic name remains unreviewed. */

void FUN_000150cc(int param_1,HWND param_2)

{
  HDC pHVar1;
  HDC pHVar2;
  HBITMAP pHVar3;
  HGDIOBJ pvVar4;
  void *local_50 [2];
  BITMAPINFO local_48;
  
  SetWindowPos(param_2,(HWND)0x0,0,0,800,0x1e0,0x80);
  pHVar1 = GetDC(param_2);
  if (*(int *)(param_1 + 0x4c) == 0) {
    pHVar2 = CreateCompatibleDC(pHVar1);
    *(HDC *)(param_1 + 0x4c) = pHVar2;
  }
  if (*(int *)(param_1 + 0x54) == 0) {
    local_48.bmiHeader.biCompression = 0;
    local_48.bmiHeader.biSizeImage = 0;
    local_48.bmiHeader.biXPelsPerMeter = 0;
    local_48.bmiHeader.biYPelsPerMeter = 0;
    local_48.bmiHeader.biClrUsed = 0;
    local_48.bmiHeader.biClrImportant = 0;
    local_50[0] = (void *)0x0;
    local_48.bmiHeader.biSize = 0x28;
    local_48.bmiHeader.biWidth = 800;
    local_48.bmiHeader.biHeight = 0x1e0;
    local_48.bmiHeader.biPlanes = 1;
    local_48.bmiHeader.biBitCount = 0x18;
    pHVar3 = CreateDIBSection(pHVar1,&local_48,0,local_50,(HANDLE)0x0,0);
    *(HBITMAP *)(param_1 + 0x54) = pHVar3;
  }
  pvVar4 = SelectObject(*(HDC *)(param_1 + 0x4c),*(HGDIOBJ *)(param_1 + 0x54));
  *(HGDIOBJ *)(param_1 + 0x58) = pvVar4;
  ReleaseDC(param_2,pHVar1);
  SetBkMode(*(HDC *)(param_1 + 0x4c),1);
  *(int *)(param_1 + 0x20) = param_1;
  *(HWND *)(param_1 + 0x1c) = param_2;
  pHVar1 = GetDC(param_2);
  *(HDC *)(param_1 + 0x2c) = pHVar1;
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0x3c) = 800;
  *(undefined4 *)(param_1 + 0x40) = 0x1e0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  return;
}



/* 0001522c FUN_0001522c */

/* Boundary evidence: original MIPS .pdata 0001522c..000152fb. Semantic name remains unreviewed. */

void FUN_0001522c(int *param_1)

{
  int *piVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  param_1[0x1c] = 1;
  param_1[0x1b] = 0;
  if (param_1[0x14] != 0) {
    (**(code **)*param_1)(param_1);
    piVar1 = (int *)param_1[9];
    if (piVar1 != (int *)0x0) {
      local_10 = 0xffffffff;
      local_c = 0xffffffff;
      (**(code **)(*piVar1 + 0xc))(piVar1,&local_10);
    }
    param_1[10] = 0;
    param_1[0xb] = 0;
    if ((HDC)param_1[0x13] != (HDC)0x0) {
      SelectObject((HDC)param_1[0x13],(HGDIOBJ)param_1[0x16]);
      DeleteDC((HDC)param_1[0x13]);
      param_1[0x13] = 0;
    }
    if ((HGDIOBJ)param_1[0x15] != (HGDIOBJ)0x0) {
      DeleteObject((HGDIOBJ)param_1[0x15]);
      param_1[0x15] = 0;
    }
    if ((HWND)param_1[0x14] != (HWND)0x0) {
      DestroyWindow((HWND)param_1[0x14]);
      param_1[0x14] = 0;
    }
    (**(code **)(*param_1 + 0x5c))(param_1);
  }
  return;
}



/* 000152fc FUN_000152fc */

/* Boundary evidence: original MIPS .pdata 000152fc..000155c3. Semantic name remains unreviewed. */

undefined4
FUN_000152fc(int *param_1,int *param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  HWND pHVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (DAT_0002852c != 0) {
    NKDbgPrintfW(
                L" =============================================================================== \r\n"
                );
    NKDbgPrintfW(
                L" ==== CGUIEmptyDlg::showPopup == m_bShowHomeDrawing->TRUE ====================== \r\n"
                );
    return 0;
  }
  DAT_00028528 = 0;
  DAT_00028530 = 0;
  if (param_2 == (int *)0x0) {
    DAT_00028528 = 0;
    DAT_00028530 = 0;
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0002853c);
  if (DAT_00028524 == 0) {
    param_2[0xb1] = param_4;
    DAT_00028524 = param_4;
    pHVar1 = GetForegroundWindow();
    param_2[0xb4] = (int)pHVar1;
    if (((int *)param_1[0x1d] == param_2) && (((int *)param_1[0x1d])[0x14] != 0)) {
      piVar2 = (int *)param_2[9];
      if (piVar2 != (int *)0x0) {
        FUN_00015720((int)param_2,0);
        (**(code **)(*piVar2 + 0x1c))(piVar2);
      }
      FUN_00014f98((int *)param_1[0x1d],param_3,param_5);
      FUN_00018238(param_1[0x1d] + 4);
      uVar3 = *(undefined4 *)(param_1[0x1d] + 0x50);
    }
    else {
      piVar2 = (int *)param_1[9];
      if (piVar2 != (int *)0x0) {
        FUN_00015720((int)param_1,0);
        (**(code **)(*piVar2 + 0x1c))(piVar2);
      }
      if ((HWND)param_1[0x14] != (HWND)0x0) {
        EnableWindow((HWND)param_1[0x14],0);
        KillTimer((HWND)param_1[0x14],0x40c);
        SetTimer((HWND)param_1[0x14],0x40c,2000,(TIMERPROC)0x0);
      }
      FUN_000163ec((int)param_1);
      if (((int *)param_1[0x1d] == (int *)0x0) || ((int *)param_1[0x1d] == param_2)) {
        uVar3 = (**(code **)(*param_2 + 0x3c))(param_2,param_1[0x12],param_1[0x14],param_3,param_5);
        param_2[0xb2] = (int)param_1;
      }
      else {
        if ((param_2[0xb1] == 0) && (DAT_00028524 != 0)) goto LAB_00015590;
        uVar3 = (**(code **)(*param_2 + 0x3c))(param_2,param_1[0x12],param_1[0x14],param_3,param_5);
        param_2[0xb2] = (int)param_1;
        (**(code **)(*(int *)param_1[0x1d] + 0x40))();
        param_1[0x1d] = (int)param_2;
        FUN_00018238((int)(param_2 + 1));
      }
      param_1[0x1d] = (int)param_2;
      (**(code **)(*param_2 + 100))(param_2,0);
      (**(code **)(*param_1 + 100))(param_1,1);
      KillTimer((HWND)param_2[0x14],0x43b);
      if ((param_5 == 1) && (param_6 == 1)) {
        SetTimer((HWND)param_2[0x14],0x43b,0x96,(TIMERPROC)0x0);
      }
      param_2[0xaf] = 0;
    }
  }
  else {
    param_2[0xb1] = 0;
  }
LAB_00015590:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0002853c);
  return uVar3;
}



/* 000155c4 FUN_000155c4 */

/* Boundary evidence: original MIPS .pdata 000155c4..0001563f. Semantic name remains unreviewed. */

LRESULT FUN_000155c4(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  int *piVar1;
  LRESULT LVar2;
  
  piVar1 = (int *)GetWindowLongW(param_1,-0x15);
  if (piVar1 == (int *)0x0) {
    LVar2 = 0;
  }
  else {
    LVar2 = FUN_00014a2c(piVar1,param_1,param_2,param_3,param_4);
  }
  return LVar2;
}



/* 00015640 FUN_00015640 */

/* Boundary evidence: original MIPS .pdata 00015640..0001571f. Semantic name remains unreviewed. */

int FUN_00015640(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint local_20;
  uint local_1c;
  
  local_20 = param_2 & 0xffff;
  local_1c = param_2 >> 0x10;
  SetCapture(*(HWND *)(param_1 + 0x50));
  *(undefined4 *)(param_1 + 0x60) = 1;
  uVar3 = *(int *)(param_1 + 0xc) - 1;
  iVar1 = 0;
  if (-1 < (int)uVar3) {
    iVar4 = uVar3 * 4;
    do {
      if (uVar3 < *(uint *)(param_1 + 0xc)) {
        piVar2 = *(int **)(iVar4 + *(int *)(param_1 + 8));
      }
      else {
        piVar2 = (int *)0x0;
      }
      if ((((piVar2[0xb] & 0x3fU) == 3) || ((piVar2[0xb] & 0x3fU) == 5)) &&
         (iVar1 = (**(code **)(*piVar2 + 4))(piVar2,&local_20), iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = uVar3 - 1;
      iVar4 = iVar4 + -4;
    } while (-1 < (int)uVar3);
  }
  return iVar1;
}



/* 00015720 FUN_00015720 */

/* Boundary evidence: original MIPS .pdata 00015720..000157ab. Semantic name remains unreviewed. */

int FUN_00015720(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  uint local_10;
  uint local_c;
  
  local_10 = param_2 & 0xffff;
  local_c = param_2 >> 0x10;
  piVar2 = *(int **)(param_1 + 0x24);
  if (piVar2 == (int *)0x0) {
    if (*(int *)(param_1 + 0x60) != 0) {
      FUN_000157ac(param_1,param_2);
    }
  }
  else {
    iVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,&local_10);
    if (iVar1 != 0) {
      ReleaseCapture();
      return iVar1;
    }
  }
  return 0;
}



/* 000157ac FUN_000157ac */

/* Boundary evidence: original MIPS .pdata 000157ac..00015883. Semantic name remains unreviewed. */

int FUN_000157ac(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint local_20;
  uint local_1c;
  
  if (*(int *)(param_1 + 100) == 0) {
    iVar1 = 0;
  }
  else {
    local_20 = param_2 & 0xffff;
    local_1c = param_2 >> 0x10;
    uVar3 = *(int *)(param_1 + 0xc) - 1;
    iVar1 = 0;
    if (-1 < (int)uVar3) {
      iVar4 = uVar3 * 4;
      do {
        if (uVar3 < *(uint *)(param_1 + 0xc)) {
          piVar2 = *(int **)(iVar4 + *(int *)(param_1 + 8));
        }
        else {
          piVar2 = (int *)0x0;
        }
        if ((((piVar2[0xb] & 0x3fU) == 3) && (piVar2[0x11] != 0)) &&
           (iVar1 = (**(code **)(*piVar2 + 4))(piVar2,&local_20), iVar1 != 0)) {
          return iVar1;
        }
        uVar3 = uVar3 - 1;
        iVar4 = iVar4 + -4;
      } while (-1 < (int)uVar3);
    }
  }
  return iVar1;
}



/* 00015884 FUN_00015884 */

/* Boundary evidence: original MIPS .pdata 00015884..0001589f. Semantic name remains unreviewed. */

void FUN_00015884(int param_1,int param_2)

{
  FUN_000183ac(param_1 + 4,param_2);
  return;
}



/* 000158a0 FUN_000158a0 */

/* Boundary evidence: original MIPS .pdata 000158a0..00015937. Semantic name remains unreviewed. */

void FUN_000158a0(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  FUN_00013cc0((int *)(param_1 + 8),(int)param_2);
  (**(code **)(*param_2 + 0x18))(param_2,param_3,param_4,param_1 + 4);
  param_2[0x12] = param_5;
  param_2[0xb] = (param_6 << 9 ^ param_2[0xb]) & 0x200U ^ param_2[0xb];
  return;
}



/* 00015938 FUN_00015938 */

/* Boundary evidence: original MIPS .pdata 00015938..00015973. Semantic name remains unreviewed. */

void FUN_00015938(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5,
                 int param_6,int param_7,int *param_8)

{
  FUN_00018684(param_1 + 4,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* 00015974 FUN_00015974 */

/* Boundary evidence: original MIPS .pdata 00015974..000159af. Semantic name remains unreviewed. */

void FUN_00015974(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 short *param_6,int param_7,int param_8)

{
  FUN_00018770(param_1 + 4,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* 000159b0 FUN_000159b0 */

/* Boundary evidence: original MIPS .pdata 000159b0..00015a13. Semantic name remains unreviewed. */

void FUN_000159b0(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,short *param_7,int *param_8,int *param_9,int param_10,int param_11,
                 int param_12,uint param_13)

{
  FUN_0001886c(param_1 + 4,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13);
  return;
}



/* 00015a14 FUN_00015a14 */

/* Boundary evidence: original MIPS .pdata 00015a14..00015a43. Semantic name remains unreviewed. */

void FUN_00015a14(int param_1,UINT param_2)

{
  *(UINT *)(param_1 + 0x7c) = param_2;
  if (0 < (int)param_2) {
    SetTimer(*(HWND *)(param_1 + 0x50),0x3f8,param_2,(TIMERPROC)0x0);
  }
  return;
}



/* 00015a44 FUN_00015a44 */

/* Boundary evidence: original MIPS .pdata 00015a44..00015a8f. Semantic name remains unreviewed. */

undefined4 * FUN_00015a44(undefined4 *param_1)

{
  FUN_000144c4(param_1);
  *param_1 = &PTR_FUN_000266d8;
  param_1[0x20] = 1;
  param_1[0xb2] = 0;
  param_1[0xb4] = 0;
  param_1[0xb3] = 1;
  return param_1;
}



/* 00015a90 FUN_00015a90 */

/* Boundary evidence: original MIPS .pdata 00015a90..00015be3. Semantic name remains unreviewed. */

void FUN_00015a90(int param_1)

{
  int iVar1;
  HGDIOBJ pvVar2;
  HDC hdcSrc;
  int cx;
  int y;
  int x;
  int iVar3;
  
  iVar3 = param_1 + 4;
  iVar1 = FUN_000181a0(iVar3);
  if (iVar1 == 0) {
    if ((*(uint *)(param_1 + 0x2cc) & 1) != 0) {
      if ((*(uint *)(param_1 + 0x2cc) & 2) == 0) {
        FUN_00015be4(param_1);
        *(uint *)(param_1 + 0x2cc) = *(uint *)(param_1 + 0x2cc) | 2;
      }
      else {
        NKDbgPrintfW(L"==============================\r\n");
        NKDbgPrintfW(L"CGUIPopupDlg::drawDialog() \r\n");
        NKDbgPrintfW(L"==============================\r\n");
      }
    }
  }
  else {
    iVar1 = FUN_000181a0(iVar3);
    if (iVar1 != 0) {
      x = *(int *)(param_1 + 0x34);
      y = *(int *)(param_1 + 0x38);
      cx = *(int *)(param_1 + 0x3c);
      iVar1 = *(int *)(param_1 + 0x40);
      pvVar2 = (HGDIOBJ)FUN_000181a0(iVar3);
      hdcSrc = (HDC)FUN_00018000(pvVar2);
      BitBlt(*(HDC *)(param_1 + 0x28),x,y,cx,iVar1,hdcSrc,x,y,0xcc0020);
      SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
      LeaveCriticalSection(DAT_00028538);
    }
  }
  FUN_0001850c(iVar3);
  if (*(int *)(param_1 + 0x78) != 0) {
    FUN_0001850c(*(int *)(param_1 + 0x78) + 4);
  }
  return;
}



/* 00015be4 FUN_00015be4 */

/* Boundary evidence: original MIPS .pdata 00015be4..00015e3b. Semantic name remains unreviewed. */

void FUN_00015be4(int param_1)

{
  byte bVar1;
  HBRUSH hbr;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  HDC hdcSrc;
  uint uVar6;
  tagRECT local_40;
  undefined4 local_30;
  int local_2c;
  
  if (DAT_00027984 - 1 < DAT_00027984) {
    iVar4 = *(int *)((DAT_00027984 - 1) * 4 + DAT_00027980);
  }
  else {
    iVar4 = 0;
  }
  hdcSrc = *(HDC *)(iVar4 + 0x4c);
  SetRect(&local_40,0,0,800,0x1e0);
  hbr = GetStockObject(4);
  if (hbr != (HBRUSH)0x0) {
    FillRect(*(HDC *)(param_1 + 0x4c),&local_40,hbr);
    DeleteObject(hbr);
  }
  AlphaBlend(*(HDC *)(param_1 + 0x4c),0,0,800,0x1e0,hdcSrc,0,0,800,0x1e0,(BLENDFUNCTION)0x460000);
  local_40.left = 0;
  local_40.top = 0;
  local_40.right = 0;
  local_40.bottom = 0;
  local_30 = 0;
  local_2c = 0;
  GetObjectW(*(HANDLE *)(param_1 + 0x54),0x18,&local_40);
  if ((local_2c != 0) && (uVar6 = 0, local_40.right != 0)) {
    do {
      uVar3 = 0;
      if (local_40.top != 0) {
        iVar2 = 0;
        iVar4 = 0;
        do {
          if (local_30._2_2_ == 0x18) {
            iVar5 = local_40.bottom * uVar6 + iVar4;
LAB_00015d84:
            bVar1 = *(byte *)(iVar5 + local_2c);
            if ((((7 < bVar1) && (bVar1 < 0x10)) && (*(byte *)(iVar5 + local_2c + 1) < 4)) &&
               (*(byte *)(iVar5 + local_2c + 2) < 8)) {
              *(byte *)(iVar5 + local_2c) = 0;
              *(undefined1 *)(iVar5 + local_2c + 1) = 0;
              *(undefined1 *)(iVar5 + local_2c + 2) = 0;
            }
          }
          else if (local_30._2_2_ == 0x20) {
            iVar5 = local_40.bottom * uVar6 + iVar2;
            goto LAB_00015d84;
          }
          uVar3 = uVar3 + 1;
          iVar4 = iVar4 + 3;
          iVar2 = iVar2 + 4;
        } while (uVar3 < (uint)local_40.top);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)local_40.right);
  }
  return;
}



/* 00015e3c FUN_00015e3c */

/* Boundary evidence: original MIPS .pdata 00015e3c..00015e63. Semantic name remains unreviewed. */

undefined4 FUN_00015e3c(int *param_1)

{
  (**(code **)(*param_1 + 0x40))();
  return 1;
}



/* 00015e64 FUN_00015e64 */

/* Boundary evidence: original MIPS .pdata 00015e64..00015ea3. Semantic name remains unreviewed. */

void FUN_00015e64(int *param_1)

{
  if ((HWND)param_1[0x14] != (HWND)0x0) {
    KillTimer((HWND)param_1[0x14],0x43b);
  }
  FUN_00015ea4(param_1);
  return;
}



/* 00015ea4 FUN_00015ea4 */

/* Boundary evidence: original MIPS .pdata 00015ea4..0001604b. Semantic name remains unreviewed. */

void FUN_00015ea4(int *param_1)

{
  int *piVar1;
  int iVar2;
  HWND hWnd;
  int *piVar3;
  
  DAT_00028528 = 0;
  DAT_00028530 = 0;
  if (param_1[0x14] != 0) {
    if ((DAT_00028524 != 0) && (param_1[0xb1] != 0)) {
      DAT_00028528 = 0;
      param_1[0xb1] = 0;
      DAT_00028524 = 0;
    }
    DAT_00028530 = 0;
    param_1[0xb3] = param_1[0xb3] & 0xfffffffd;
    FUN_0001522c(param_1);
    if (param_1[0xb2] != 0) {
      *(undefined4 *)(param_1[0xb2] + 0x74) = 0;
    }
    piVar1 = (int *)param_1[0xb2];
    if (piVar1 != (int *)0x0) {
      if (DAT_00027984 - 1 < DAT_00027984) {
        piVar3 = *(int **)((DAT_00027984 - 1) * 4 + DAT_00027980);
      }
      else {
        piVar3 = (int *)0x0;
      }
      if (piVar1 == piVar3) {
        (**(code **)(*piVar1 + 100))(piVar1,0);
        if (param_1[0x1e] != 0) {
          (**(code **)(*(int *)param_1[0xb2] + 0x28))();
          iVar2 = *(int *)(param_1[0xb2] + 0x78);
          if (iVar2 != 0) {
            FUN_00018a6c(iVar2,param_1[0xb2] + 4);
            FUN_00018abc(*(int *)(param_1[0xb2] + 0x78));
          }
        }
        iVar2 = param_1[0xb2];
        hWnd = *(HWND *)(iVar2 + 0x50);
        if (hWnd != (HWND)0x0) {
          EnableWindow(hWnd,1);
          KillTimer(*(HWND *)(iVar2 + 0x50),0x40c);
        }
        piVar1 = (int *)param_1[0xb2];
        if ((piVar1[0x20] == 0) && (DAT_00028534 == 0)) {
          DAT_00028530 = 0;
          FUN_00014764(piVar1,(HWND)piVar1[0x14]);
        }
      }
    }
  }
  return;
}



/* 0001604c FUN_0001604c */

/* Boundary evidence: original MIPS .pdata 0001604c..000162f7. Semantic name remains unreviewed. */

undefined4 FUN_0001604c(int *param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  HWND hWnd;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (param_1 != (int *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0002853c);
    uVar1 = DAT_00027984;
    DAT_00028530 = 0;
    DAT_00028528 = 0;
    if (DAT_00028524 == 0) {
      if (DAT_00027984 - 1 < DAT_00027984) {
        piVar3 = *(int **)((DAT_00027984 - 1) * 4 + DAT_00027980);
      }
      else {
        piVar3 = (int *)0x0;
      }
      if (piVar3 == param_1) {
        FUN_00014f98(param_1,param_2,1);
        (**(code **)*piVar3)(piVar3);
        SetForegroundWindow((HWND)param_1[0x14]);
        FUN_00018238((int)(param_1 + 1));
        uVar4 = 1;
      }
      else {
        if (DAT_00027984 - 2 < DAT_00027984) {
          piVar2 = *(int **)((DAT_00027984 - 2) * 4 + DAT_00027980);
        }
        else {
          piVar2 = (int *)0x0;
        }
        if ((piVar2 == param_1) && (piVar2[0x14] != 0)) {
          FUN_00014f98(param_1,param_2,1);
          (**(code **)*piVar3)(piVar3);
          if (param_1[0x1e] != 0) {
            FUN_00018abc(param_1[0x1e]);
          }
          SetForegroundWindow((HWND)param_1[0x14]);
          FUN_00018238((int)(param_1 + 1));
          uVar4 = 1;
        }
        else {
          DAT_00028534 = 1;
          hWnd = (HWND)(**(code **)(*param_1 + 0x3c))(param_1,DAT_0002851c,DAT_00028518,param_2,1);
          if (hWnd != (HWND)0x0) {
            SetWindowLongW(hWnd,-0xc,0);
            SetWindowLongW(hWnd,-0x10,-0x7e000000);
            SetWindowLongW(hWnd,-0x14,0x44000000);
            if (((0 < (int)uVar1) && ((**(code **)(*piVar3 + 0x40))(piVar3), param_3 != 0)) &&
               (DAT_00027984 != 0)) {
              DAT_00027984 = DAT_00027984 - 1;
            }
            FUN_00016438(&DAT_00027980,(int)param_1);
            if (param_1[0x1e] != 0) {
              FUN_00018a6c(param_1[0x1e],(int)(param_1 + 1));
            }
            FUN_00018238((int)(param_1 + 1));
            uVar4 = 1;
          }
          DAT_00028534 = 0;
        }
      }
    }
    else {
      NKDbgPrintfW(
                  L" CGUIEmptyDlg::changeDialog   ms_KeepPopupEnabled == TRUE =================== \r\n"
                  );
    }
    (**(code **)(*param_1 + 0x38))(param_1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0002853c);
  }
  return uVar4;
}



/* 000162f8 FUN_000162f8 */

void FUN_000162f8(int param_1,int param_2)

{
  if ((DAT_00028518 == 0) && (DAT_0002851c == 0)) {
    DAT_00028518 = param_2;
    DAT_0002851c = param_1;
  }
  return;
}



/* 00016328 FUN_00016328 */

/* Boundary evidence: original MIPS .pdata 00016328..000163eb. Semantic name remains unreviewed. */

WNDCLASSW * FUN_00016328(wchar_t *param_1,undefined4 param_2,undefined4 param_3)

{
  ATOM AVar1;
  undefined2 extraout_var;
  WNDCLASSW *lpWndClass;
  
  if (*(int *)(param_1 + 0x2e) == 0) {
    swprintf(param_1 + 0x5a,0x2664c,param_1);
    lpWndClass = (WNDCLASSW *)(param_1 + 0x46);
    *(undefined4 *)(param_1 + 0x48) = param_3;
    lpWndClass->style = 3;
    param_1[0x4a] = L'\0';
    param_1[0x4b] = L'\0';
    param_1[0x4c] = L'\0';
    param_1[0x4d] = L'\0';
    *(undefined4 *)(param_1 + 0x4e) = param_2;
    param_1[0x50] = L'\0';
    param_1[0x51] = L'\0';
    param_1[0x52] = L'\0';
    param_1[0x53] = L'\0';
    param_1[0x54] = L'\0';
    param_1[0x55] = L'\0';
    param_1[0x56] = L'\0';
    param_1[0x57] = L'\0';
    *(wchar_t **)(param_1 + 0x58) = param_1 + 0x5a;
    AVar1 = RegisterClassW(lpWndClass);
    if (CONCAT22(extraout_var,AVar1) == 0) {
      lpWndClass = (WNDCLASSW *)0x0;
    }
    else {
      param_1[0x2e] = L'\x01';
      param_1[0x2f] = L'\0';
    }
  }
  else {
    lpWndClass = (WNDCLASSW *)(param_1 + 0x46);
  }
  return lpWndClass;
}



/* 000163ec FUN_000163ec */

/* Boundary evidence: original MIPS .pdata 000163ec..00016437. Semantic name remains unreviewed. */

void FUN_000163ec(int param_1)

{
  BOOL BVar1;
  tagMSG tStack_30;
  
  do {
    BVar1 = PeekMessageW(&tStack_30,*(HWND *)(param_1 + 0x50),0x200,0x20d,1);
  } while (BVar1 != 0);
  return;
}



/* 00016438 FUN_00016438 */

/* Boundary evidence: original MIPS .pdata 00016438..00016527. Semantic name remains unreviewed. */

void FUN_00016438(undefined4 param_1,int param_2)

{
  HLOCAL pvVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (DAT_00027980 == (HLOCAL)0x0) {
    DAT_00027988 = DAT_00027990;
    DAT_00027980 = LocalAlloc(0x40,DAT_00027990 << 2);
  }
  else if (DAT_00027984 == DAT_00027988) {
    DAT_00027988 = DAT_00027988 + DAT_00027990;
    DAT_00027980 = LocalReAlloc(DAT_00027980,DAT_00027988 * 4,2);
  }
  uVar3 = 0;
  pvVar1 = DAT_00027980;
  uVar2 = DAT_00027984;
  if (DAT_00027984 != 0) {
    iVar4 = 0;
    do {
      if (*(int *)(iVar4 + (int)pvVar1) == param_2) {
        FUN_00016528(&DAT_00027980,uVar3);
        pvVar1 = DAT_00027980;
        uVar2 = DAT_00027984;
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar3 < uVar2);
  }
  *(int *)(uVar2 * 4 + (int)pvVar1) = param_2;
  DAT_00027984 = DAT_00027984 + 1;
  return;
}



/* 00016528 FUN_00016528 */

/* Boundary evidence: original MIPS .pdata 00016528..000165cb. Semantic name remains unreviewed. */

undefined4 FUN_00016528(undefined4 param_1,uint param_2)

{
  void *_Dst;
  
  if (DAT_00027984 <= param_2) {
    return 0;
  }
  if (param_2 == DAT_00027984 - 1) {
    if (DAT_00027984 != 0) {
      DAT_00027984 = DAT_00027984 - 1;
      return 1;
    }
  }
  else {
    _Dst = (void *)(param_2 * 4 + DAT_00027980);
    memcpy(_Dst,(void *)((int)_Dst + 4),((DAT_00027984 - param_2) + -1) * 4);
    DAT_00027984 = DAT_00027984 - 1;
  }
  return 1;
}



/* 000165d4 FUN_000165d4 */

void FUN_000165d4(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_00026744;
  return;
}



/* 000165e4 FUN_000165e4 */

void FUN_000165e4(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x2c) =
       (param_2 << 9 ^ *(uint *)(param_1 + 0x2c)) & 0x200 ^ *(uint *)(param_1 + 0x2c);
  return;
}



/* 00016664 FUN_00016664 */

/* Boundary evidence: original MIPS .pdata 00016664..000166d7. Semantic name remains unreviewed. */

void FUN_00016664(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xb] & 0x80U) != 0) {
    if (((param_1[1] != 0) && (iVar1 = *(int *)(param_1[1] + 0x1c), iVar1 != 0)) &&
       (*(int *)(iVar1 + 0x74) != 0)) {
      (**(code **)(*param_1 + 0x1c))();
      return;
    }
    (**(code **)*param_1)();
  }
  return;
}



/* 000166d8 FUN_000166d8 */

/* Boundary evidence: original MIPS .pdata 000166d8..00016747. Semantic name remains unreviewed. */

void FUN_000166d8(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  if ((*(uint *)(param_1 + 0x2c) & 0x40) == 0) {
    *(undefined4 *)(param_1 + 4) = param_4;
    *(undefined4 *)(param_1 + 8) = *param_3;
    *(undefined4 *)(param_1 + 0xc) = param_3[1];
    *(undefined4 *)(param_1 + 0x10) = param_3[2];
    *(undefined4 *)(param_1 + 0x14) = param_3[3];
    if (param_2 != -1) {
      FUN_00016748(param_1,param_2);
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x40;
  }
  return;
}



/* 00016748 FUN_00016748 */

/* Boundary evidence: original MIPS .pdata 00016748..0001686b. Semantic name remains unreviewed. */

void FUN_00016748(int param_1,int param_2)

{
  HANDLE h;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  if (DAT_00027bc4 == (int *)0x0) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
  }
  h = (HANDLE)FUN_00014150(DAT_00027bc4,param_2);
  if (h == (HANDLE)0x0) {
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  }
  else {
    *(int *)(param_1 + 0x28) = param_2;
  }
  if (DAT_00027bc4 == (int *)0x0) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
  }
  if (h == (HANDLE)0x0) {
    local_28._2_2_ = 0;
  }
  else {
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    GetObjectW(h,0x18,&local_38);
  }
  if (local_28._2_2_ == 0x20) {
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x800;
  }
  return;
}



/* 0001686c FUN_0001686c */

/* Boundary evidence: original MIPS .pdata 0001686c..00016903. Semantic name remains unreviewed. */

undefined4 FUN_0001686c(int param_1)

{
  int iVar1;
  
  if (DAT_00027bc4 == 0) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 < *(int *)(DAT_00027bc4 + 0x6d4)) && (-1 < iVar1)) {
    return *(undefined4 *)(*(int *)(DAT_00027bc4 + 0x6d0) + iVar1 * 4);
  }
  return 0;
}



/* 00016904 FUN_00016904 */

/* Boundary evidence: original MIPS .pdata 00016904..00016983. Semantic name remains unreviewed. */

void FUN_00016904(undefined4 *param_1)

{
  if (param_1[1] != 0) {
    if ((param_1[0xb] & 0x80) != 0) {
      (**(code **)*param_1)(param_1);
      return;
    }
    FUN_00018440(param_1[1],param_1 + 2);
    FUN_000185c8(param_1[1],param_1 + 2,0);
  }
  return;
}



/* 00016984 FUN_00016984 */

/* Boundary evidence: original MIPS .pdata 00016984..000169d3. Semantic name remains unreviewed. */

void FUN_00016984(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1[0xb];
  uVar2 = (param_2 << 8 ^ uVar1) & 0x100 ^ uVar1;
  param_1[0xb] = uVar2;
  if ((param_3 != 0) && ((uVar1 >> 8 & 1) != (uVar2 >> 8 & 1))) {
    FUN_00016904(param_1);
  }
  return;
}



/* 000169d4 FUN_000169d4 */

undefined4 * FUN_000169d4(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0xffffffff;
  param_1[0xb] = 0x180;
  *param_1 = &PTR_FUN_00026778;
  param_1[1] = 0;
  param_1[0x14] = 0x32;
  param_1[0x12] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  *(undefined1 *)((int)param_1 + 0x31) = 1;
  *(undefined1 *)(param_1 + 0xc) = 0;
  param_1[0xb] = param_1[0xb] & 0xffffffc2 | 2;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0xc] = param_1[0xc] & 0xffff;
  return param_1;
}



/* 00016a78 FUN_00016a78 */

/* Boundary evidence: original MIPS .pdata 00016a78..00016b4b. Semantic name remains unreviewed. */

void FUN_00016a78(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  FUN_00016b4c(param_1,*(uint *)(param_1 + 0x30) & 0xff);
  if ((*(int *)(param_1 + 0x44) != 0) && (uVar3 = 0, *(int *)(param_1 + 0x44) != 0)) {
    iVar4 = 0;
    do {
      if (uVar3 < *(uint *)(param_1 + 0x44)) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x40) + iVar4);
      }
      else {
        iVar2 = 0;
      }
      if ((*(uint *)(iVar2 + 0x2c) & 0x80) != 0) {
        if (uVar3 < *(uint *)(param_1 + 0x44)) {
          piVar1 = *(int **)(iVar4 + *(int *)(param_1 + 0x40));
        }
        else {
          piVar1 = (int *)0x0;
        }
        (**(code **)(*piVar1 + 0x1c))();
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar3 < *(uint *)(param_1 + 0x44));
  }
  return;
}



/* 00016b4c FUN_00016b4c */

/* Boundary evidence: original MIPS .pdata 00016b4c..00016eb3. Semantic name remains unreviewed. */

void FUN_00016b4c(int param_1,int param_2)

{
  int iVar1;
  HGDIOBJ pvVar2;
  HDC hdcSrc;
  int ySrc;
  int wSrc;
  int hSrc;
  uint uVar3;
  int cx;
  int y;
  int cy;
  int xSrc;
  BLENDFUNCTION ftn;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  if ((*(int *)(param_1 + 0x3c) != 0) || (iVar1 = FUN_0001686c(param_1), iVar1 != 0)) {
    ySrc = *(int *)(param_1 + 0x1c);
    wSrc = *(int *)(param_1 + 0x20);
    iVar1 = *(int *)(param_1 + 8);
    y = *(int *)(param_1 + 0xc);
    cx = *(int *)(param_1 + 0x10);
    cy = *(int *)(param_1 + 0x14);
    hSrc = *(int *)(param_1 + 0x24);
    xSrc = *(int *)(param_1 + 0x18);
    pvVar2 = *(HGDIOBJ *)(param_1 + 0x3c);
    local_38 = iVar1;
    local_34 = y;
    local_30 = cx;
    local_2c = cy;
    if (pvVar2 == (HGDIOBJ)0x0) {
      pvVar2 = (HGDIOBJ)FUN_0001686c(param_1);
    }
    hdcSrc = (HDC)FUN_00018000(pvVar2);
    uVar3 = *(uint *)(param_1 + 0x2c);
    if ((uVar3 & 0x800) == 0) {
      if ((uVar3 & 0x200) == 0) {
        if ((uVar3 & 0x1000) == 0) {
          if ((*(ushort *)(param_1 + 0x32) & 1) == 0) {
            BitBlt(*(HDC *)(*(int *)(param_1 + 4) + 0x24),iVar1,y,cx,cy,hdcSrc,cx * param_2,0,
                   0xcc0020);
          }
          else {
            StretchBlt(*(HDC *)(*(int *)(param_1 + 4) + 0x24),iVar1,y,cx,cy,hdcSrc,0,0,
                       *(int *)(param_1 + 0x34),*(int *)(param_1 + 0x38),0xcc0020);
          }
        }
        else {
          StretchBlt(*(HDC *)(*(int *)(param_1 + 4) + 0x24),iVar1,y,cx,cy,hdcSrc,xSrc,ySrc,wSrc,hSrc
                     ,0xcc0020);
        }
      }
      else {
        if ((uVar3 & 0x400) != 0) {
          FUN_00018440(*(int *)(param_1 + 4),&local_38);
          iVar1 = local_38;
          y = local_34;
          cy = local_2c;
        }
        if ((*(ushort *)(param_1 + 0x32) & 1) == 0) {
          TransparentImage(*(undefined4 *)(*(int *)(param_1 + 4) + 0x24),iVar1,y,cx,cy,hdcSrc,
                           cx * param_2,0,cx,*(undefined4 *)(param_1 + 0x14),0xffff);
        }
        else {
          TransparentImage(*(undefined4 *)(*(int *)(param_1 + 4) + 0x24),iVar1,y,cx,cy,hdcSrc,0,0,
                           *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),0xffff);
        }
      }
    }
    else {
      if ((uVar3 & 0x400) != 0) {
        FUN_00018440(*(int *)(param_1 + 4),&local_38);
        iVar1 = local_38;
        y = local_34;
        cy = local_2c;
      }
      if (DAT_00027bc4 == 0) {
        MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
      }
      if (DAT_00028552 == '\0') {
        DAT_00028550 = 0;
        DAT_00028551 = 0;
        DAT_00028553 = '\x01';
        DAT_00028552 = -1;
      }
      ftn.BlendFlags = DAT_00028551;
      ftn.BlendOp = DAT_00028550;
      ftn.SourceConstantAlpha = DAT_00028552;
      ftn.AlphaFormat = DAT_00028553;
      AlphaBlend(*(HDC *)(*(int *)(param_1 + 4) + 0x24),iVar1,y,cx,cy,hdcSrc,cx * param_2,0,cx,
                 *(int *)(param_1 + 0x14),ftn);
    }
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
  }
  return;
}



/* 00016eb4 FUN_00016eb4 */

/* Boundary evidence: original MIPS .pdata 00016eb4..0001706f. Semantic name remains unreviewed. */

void FUN_00016eb4(int param_1,int param_2,int *param_3)

{
  HGDIOBJ pvVar1;
  HDC hdcSrc;
  int iVar2;
  int x;
  int iVar3;
  int cx;
  int cy;
  int y;
  int iVar4;
  int y1;
  
  iVar3 = *(int *)(param_1 + 0x10);
  x = *(int *)(param_1 + 8);
  iVar2 = *param_3;
  y = *(int *)(param_1 + 0xc);
  cy = *(int *)(param_1 + 0x14);
  iVar4 = 0;
  y1 = 0;
  cx = iVar3;
  if (x < iVar2) {
    iVar4 = iVar2 - x;
    x = x + iVar4;
    if (param_3[2] + iVar2 < iVar3 + *(int *)(param_1 + 8)) {
      cx = (param_3[2] + iVar2) - x;
    }
  }
  iVar2 = param_3[1];
  if (*(int *)(param_1 + 0xc) < iVar2) {
    y1 = iVar2 - *(int *)(param_1 + 0xc);
    y = y + y1;
    if (param_3[3] + iVar2 < *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc)) {
      cy = (param_3[3] - y) + iVar2;
    }
  }
  pvVar1 = *(HGDIOBJ *)(param_1 + 0x3c);
  if (pvVar1 == (HGDIOBJ)0x0) {
    pvVar1 = (HGDIOBJ)FUN_0001686c(param_1);
  }
  hdcSrc = (HDC)FUN_00018000(pvVar1);
  if ((*(uint *)(param_1 + 0x2c) & 0x200) == 0) {
    BitBlt(*(HDC *)(*(int *)(param_1 + 4) + 0x24),x,y,cx,cy,hdcSrc,iVar3 * param_2 + iVar4,y1,
           0xcc0020);
  }
  else {
    TransparentImage(*(undefined4 *)(*(int *)(param_1 + 4) + 0x24));
  }
  SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
  LeaveCriticalSection(DAT_00028538);
  return;
}



/* 00017070 FUN_00017070 */

undefined4 * FUN_00017070(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xb] = 0x180;
  *param_1 = &PTR_FUN_000267bc;
  param_1[1] = 0;
  param_1[10] = 0xffffffff;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x1b] = 5;
  param_1[0x19] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x1a] = 0;
  param_1[0x12] = 0xffffffff;
  param_1[0xb] = param_1[0xb] & 0xffffffc3 | 3;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x1c] = 0;
  return param_1;
}



/* 00017124 FUN_00017124 */

/* Boundary evidence: original MIPS .pdata 00017124..0001718b. Semantic name remains unreviewed. */

void FUN_00017124(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 == 0) && (param_1[0xc] != 0)) {
    param_1[0xc] = 0;
  }
  uVar1 = param_1[0xb];
  uVar2 = (param_2 << 8 ^ uVar1) & 0x100 ^ uVar1;
  param_1[0xb] = uVar2;
  if ((param_3 != 0) && ((uVar1 >> 8 & 1) != (uVar2 >> 8 & 1))) {
    FUN_00016904(param_1);
  }
  return;
}



/* 0001718c FUN_0001718c */

/* Boundary evidence: original MIPS .pdata 0001718c..00017217. Semantic name remains unreviewed. */

void FUN_0001718c(int *param_1)

{
  int *piVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (((param_1[0xb] & 0x80U) != 0) && (param_1[1] != 0)) {
    (**(code **)(*param_1 + 0x1c))(param_1);
    piVar1 = param_1 + 0x13;
    if (param_1[0x10] == 0) {
      piVar1 = param_1 + 2;
    }
    local_18 = *piVar1;
    local_14 = piVar1[1];
    local_10 = piVar1[2];
    local_c = piVar1[3];
    FUN_000185c8(param_1[1],&local_18,0);
  }
  return;
}



/* 00017218 FUN_00017218 */

/* Boundary evidence: original MIPS .pdata 00017218..00017327. Semantic name remains unreviewed. */

void FUN_00017218(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if ((param_1[0xb] & 0x100U) == 0) {
    uVar2 = 2;
  }
  else if (param_1[0xc] == 0) {
    uVar2 = 3;
    if (param_1[0xd] == 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  (**(code **)(*param_1 + 0x34))(param_1,uVar2);
  if ((param_1[0x18] != 0) && (uVar4 = 0, param_1[0x18] != 0)) {
    iVar5 = 0;
    do {
      if (uVar4 < (uint)param_1[0x18]) {
        iVar3 = *(int *)(param_1[0x17] + iVar5);
      }
      else {
        iVar3 = 0;
      }
      if ((*(uint *)(iVar3 + 0x2c) & 0x80) != 0) {
        if (uVar4 < (uint)param_1[0x18]) {
          piVar1 = *(int **)(iVar5 + param_1[0x17]);
        }
        else {
          piVar1 = (int *)0x0;
        }
        (**(code **)(*piVar1 + 0x1c))();
      }
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar4 < (uint)param_1[0x18]);
  }
  return;
}



/* 00017328 FUN_00017328 */

/* Boundary evidence: original MIPS .pdata 00017328..000173f3. Semantic name remains unreviewed. */

undefined4 FUN_00017328(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1[0xb] & 0x100U) != 0) {
    if ((((param_1[2] <= *param_2) && (param_1[3] <= param_2[1])) &&
        (*param_2 <= param_1[4] + param_1[2])) && (param_2[1] <= param_1[5] + param_1[3])) {
      uVar1 = 1;
      param_1[0xc] = 1;
      FUN_00016664(param_1);
      (**(code **)(**(int **)(param_1[1] + 0x1c) + 0x48))
                (*(int **)(param_1[1] + 0x1c),param_1[0x12],param_2);
      FUN_000182d8(param_1[1],(int)param_1);
    }
  }
  return uVar1;
}



/* 000173f4 FUN_000173f4 */

/* Boundary evidence: original MIPS .pdata 000173f4..000175af. Semantic name remains unreviewed. */

undefined4 FUN_000173f4(int *param_1,int *param_2)

{
  undefined4 uVar1;
  HWND pHVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  if ((param_1[0xb] & 0x100U) != 0) {
    if (param_1[0xc] != 0) {
      param_1[0xc] = 0;
      if ((((param_1[2] <= *param_2) && (param_1[3] <= param_2[1])) &&
          (*param_2 <= param_1[4] + param_1[2])) &&
         ((param_2[1] <= param_1[5] + param_1[3] && (param_1[0x12] != -1)))) {
        (**(code **)(**(int **)(param_1[1] + 0x1c) + 0x4c))();
        if ((param_1[0xe] == 0) || (uVar1 = 5, *(int *)(param_1[1] + 0x40) == 0)) {
          uVar1 = 2;
        }
        (**(code **)(**(int **)(param_1[1] + 0x1c) + 0x44))
                  (*(int **)(param_1[1] + 0x1c),param_1[0x12],uVar1);
        iVar4 = param_1[1];
        iVar3 = *(int *)(iVar4 + 0x20);
        *(undefined4 *)(iVar4 + 0x20) = 0;
        if (((iVar3 != 0) && ((*(uint *)(iVar3 + 0x2c) & 0x3f) == 3)) &&
           (*(int *)(iVar3 + 0x38) != 0)) {
          pHVar2 = *(HWND *)(*(int *)(iVar4 + 0x1c) + 0x50);
          if (pHVar2 != (HWND)0x0) {
            KillTimer(pHVar2,0x3f6);
          }
          pHVar2 = *(HWND *)(*(int *)(iVar4 + 0x1c) + 0x50);
          if (pHVar2 != (HWND)0x0) {
            KillTimer(pHVar2,0x3f7);
          }
        }
        *(undefined4 *)(iVar4 + 0x40) = 0;
      }
    }
    if ((param_1[0xb] & 0x80U) != 0) {
      if (((param_1[1] == 0) || (iVar3 = *(int *)(param_1[1] + 0x1c), iVar3 == 0)) ||
         (*(int *)(iVar3 + 0x74) == 0)) {
        (**(code **)*param_1)(param_1);
      }
      else {
        (**(code **)(*param_1 + 0x1c))(param_1);
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 000175b0 FUN_000175b0 */

/* Boundary evidence: original MIPS .pdata 000175b0..000176fb. Semantic name remains unreviewed. */

undefined4 FUN_000175b0(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  HWND pHVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((param_1[0xb] & 0x100U) != 0) {
    if (((((*param_2 < param_1[2]) || (param_2[1] < param_1[3])) ||
         (param_1[4] + param_1[2] < *param_2)) || (param_1[5] + param_1[3] < param_2[1])) &&
       (param_1[0xc] != 0)) {
      param_1[0xc] = 0;
      (**(code **)(**(int **)(param_1[1] + 0x1c) + 0x50))
                (*(int **)(param_1[1] + 0x1c),param_1[0x12],param_2);
      if ((param_1[0xe] != 0) && (*(int *)(param_1[1] + 0x40) != 0)) {
        piVar2 = *(int **)(param_1[1] + 0x1c);
        (**(code **)(*piVar2 + 0x44))(piVar2,param_1[0x12],5);
      }
      FUN_00016664(param_1);
      iVar5 = param_1[1];
      iVar4 = *(int *)(iVar5 + 0x20);
      *(undefined4 *)(iVar5 + 0x20) = 0;
      if (((iVar4 != 0) && ((*(uint *)(iVar4 + 0x2c) & 0x3f) == 3)) && (*(int *)(iVar4 + 0x38) != 0)
         ) {
        pHVar3 = *(HWND *)(*(int *)(iVar5 + 0x1c) + 0x50);
        if (pHVar3 != (HWND)0x0) {
          KillTimer(pHVar3,0x3f6);
        }
        pHVar3 = *(HWND *)(*(int *)(iVar5 + 0x1c) + 0x50);
        if (pHVar3 != (HWND)0x0) {
          KillTimer(pHVar3,0x3f7);
        }
      }
      *(undefined4 *)(iVar5 + 0x40) = 0;
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* 000176fc FUN_000176fc */

/* Boundary evidence: original MIPS .pdata 000176fc..000178b3. Semantic name remains unreviewed. */

void FUN_000176fc(int param_1,int param_2)

{
  HGDIOBJ pvVar1;
  HDC hdcSrc;
  int iVar2;
  int *piVar3;
  int cx;
  int x;
  int y;
  int cy;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  piVar3 = (int *)(param_1 + 0x4c);
  if (*(int *)(param_1 + 0x40) == 0) {
    piVar3 = (int *)(param_1 + 8);
  }
  x = *piVar3;
  y = piVar3[1];
  cx = piVar3[2];
  cy = piVar3[3];
  iVar2 = *(int *)(param_1 + 0x70);
  local_30 = x;
  local_2c = y;
  local_28 = cx;
  local_24 = cy;
  if (iVar2 != 0) {
    FUN_00016eb4(iVar2,*(uint *)(iVar2 + 0x30) & 0xff,(int *)(param_1 + 8));
  }
  iVar2 = FUN_0001686c(param_1);
  if (iVar2 == 0) {
    if ((*(uint *)(param_1 + 0x2c) & 0x400) != 0) {
      FUN_00018440(*(int *)(param_1 + 4),&local_30);
    }
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0001686c(param_1);
    hdcSrc = (HDC)FUN_00018000(pvVar1);
    if ((*(uint *)(param_1 + 0x2c) & 0x200) == 0) {
      BitBlt(*(HDC *)(*(int *)(param_1 + 4) + 0x24),x,y,cx,cy,hdcSrc,cx * param_2,0,0xcc0020);
    }
    else {
      if ((*(uint *)(param_1 + 0x2c) & 0x400) != 0) {
        FUN_00018440(*(int *)(param_1 + 4),&local_30);
        x = local_30;
        y = local_2c;
        cy = local_24;
      }
      TransparentImage(*(undefined4 *)(*(int *)(param_1 + 4) + 0x24),x,y,cx,cy,hdcSrc,cx * param_2,0
                       ,cx,*(undefined4 *)(param_1 + 0x14),0xffff);
    }
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
  }
  return;
}



/* 000178b4 FUN_000178b4 */

/* Boundary evidence: original MIPS .pdata 000178b4..000178fb. Semantic name remains unreviewed. */

void FUN_000178b4(undefined4 *param_1)

{
  if ((HLOCAL)param_1[0x17] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x17]);
    param_1[0x17] = 0;
  }
  param_1[0x18] = 0;
  *param_1 = &PTR_LAB_00026744;
  return;
}



/* 000178fc FUN_000178fc */

/* Boundary evidence: original MIPS .pdata 000178fc..00017aa3. Semantic name remains unreviewed. */

undefined4 * FUN_000178fc(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xb] = 0x180;
  param_1[10] = 0xffffffff;
  param_1[1] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x1b] = 5;
  param_1[0x19] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x1a] = 0;
  param_1[0x12] = 0xffffffff;
  param_1[0xb] = param_1[0xb] & 0xffffffc3 | 3;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x1c] = 0;
  *param_1 = &PTR_FUN_000267f4;
  FUN_000114f8(param_1 + 0x1d);
  param_1[0x1d] = &PTR_FUN_00026244;
  param_1[200] = 0xffff00;
  *(undefined2 *)(param_1 + 0xc9) = 0;
  param_1[0x10a] = 0;
  param_1[0x10b] = 0;
  param_1[0x10c] = 0;
  *(undefined2 *)(param_1 + 0x10d) = 0;
  param_1[0x14e] = 0;
  param_1[0x14f] = 0;
  param_1[0x150] = 0;
  param_1[0x151] = 0;
  param_1[0x152] = 0;
  param_1[0x15b] = param_1[0x15b] & 0x20000 ^ param_1[0x15b] & 0xfffeffff;
  *(undefined1 *)(param_1 + 0x15b) = 0;
  *(undefined1 *)((int)param_1 + 0x56d) = 2;
  param_1[0x153] = 0xeeeeee;
  param_1[0x154] = 0x308cf6;
  param_1[0x155] = 0xa0a0a0;
  param_1[0x156] = 0x308cf6;
  param_1[0x15a] = 0;
  param_1[0x159] = 0;
  param_1[0x158] = 0;
  param_1[0x157] = 0;
  param_1[0x15b] = param_1[0x15b] & 0x3ffff;
  return param_1;
}



/* 00017aa4 FUN_00017aa4 */

/* Boundary evidence: original MIPS .pdata 00017aa4..00017b3b. Semantic name remains unreviewed. */

undefined4 * FUN_00017aa4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000267f4;
  if ((HLOCAL)param_1[0xc3] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0xc3]);
    param_1[0xc3] = 0;
  }
  param_1[0xc4] = 0;
  param_1[0x1d] = &PTR_LAB_00026744;
  if ((HLOCAL)param_1[0x17] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x17]);
    param_1[0x17] = 0;
  }
  param_1[0x18] = 0;
  *param_1 = &PTR_LAB_00026744;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00017b3c FUN_00017b3c */

/* Boundary evidence: original MIPS .pdata 00017b3c..00017bb7. Semantic name remains unreviewed. */

void FUN_00017b3c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000267f4;
  if ((HLOCAL)param_1[0xc3] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0xc3]);
    param_1[0xc3] = 0;
  }
  param_1[0xc4] = 0;
  param_1[0x1d] = &PTR_LAB_00026744;
  if ((HLOCAL)param_1[0x17] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x17]);
    param_1[0x17] = 0;
  }
  param_1[0x18] = 0;
  *param_1 = &PTR_LAB_00026744;
  return;
}



/* 00017bb8 FUN_00017bb8 */

/* Boundary evidence: original MIPS .pdata 00017bb8..00017c6f. Semantic name remains unreviewed. */

void FUN_00017bb8(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  if ((*(uint *)(param_1 + 0x2c) & 0x40) == 0) {
    *(undefined4 *)(param_1 + 4) = param_4;
    *(undefined4 *)(param_1 + 8) = *param_3;
    *(undefined4 *)(param_1 + 0xc) = param_3[1];
    *(undefined4 *)(param_1 + 0x10) = param_3[2];
    *(undefined4 *)(param_1 + 0x14) = param_3[3];
    if (param_2 != -1) {
      FUN_00016748(param_1,param_2);
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x40;
  }
  (**(code **)(*(int *)(param_1 + 0x74) + 0x18))((int *)(param_1 + 0x74),0xffffffff,param_3,param_4)
  ;
  *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & 0xfffffbff;
  return;
}



/* 00017c70 FUN_00017c70 */

/* Boundary evidence: original MIPS .pdata 00017c70..00017d93. Semantic name remains unreviewed. */

void FUN_00017c70(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  FUN_000176fc(param_1,param_2);
  uVar1 = param_2 & 3;
  if (((int)param_2 < 0) && (uVar1 != 0)) {
    uVar1 = uVar1 - 4;
  }
  uVar2 = *(uint *)(param_1 + 0x56c);
  *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)((uVar1 + 0x153) * 4 + param_1);
  if ((uVar2 & 0x40000) != 0) {
    *(undefined4 *)(param_1 + 800) = *(undefined4 *)((uVar1 + 0x157) * 4 + param_1);
  }
  if (uVar1 == 1) {
    uVar1 = uVar2 & 0x10000;
joined_r0x00017d58:
    if (uVar1 != 0) {
      *(uint *)(param_1 + 0x7c) = (uVar2 & 0xff) + *(int *)(param_1 + 0x53c);
      *(uint *)(param_1 + 0x80) = (uint)*(byte *)(param_1 + 0x56d) + *(int *)(param_1 + 0x540);
      *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x544);
      *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x548);
      goto LAB_00017d1c;
    }
  }
  else if (uVar1 == 3) {
    uVar1 = uVar2 & 0x20000;
    goto joined_r0x00017d58;
  }
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x53c);
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x540);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x544);
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x548);
LAB_00017d1c:
  (**(code **)(*(int *)(param_1 + 0x74) + 0x1c))();
  return;
}



/* 00017d94 FUN_00017d94 */

void FUN_00017d94(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x54c) = *param_2;
    *(undefined4 *)(param_1 + 0x550) = param_2[1];
    *(undefined4 *)(param_1 + 0x554) = param_2[2];
    *(undefined4 *)(param_1 + 0x558) = param_2[3];
  }
  return;
}



/* 00017dc4 FUN_00017dc4 */

/* Boundary evidence: original MIPS .pdata 00017dc4..00017e77. Semantic name remains unreviewed. */

void FUN_00017dc4(int *param_1,short *param_2,int param_3)

{
  int iVar1;
  
  FUN_00011724(param_1 + 0x1d,param_2,0);
  param_1[0x38] = (uint)param_1[0x15b] >> 0x13 & 1;
  if ((param_3 != 0) && ((param_1[0xb] & 0x80U) != 0)) {
    if ((param_1[1] != 0) &&
       ((iVar1 = *(int *)(param_1[1] + 0x1c), iVar1 != 0 && (*(int *)(iVar1 + 0x74) != 0)))) {
      (**(code **)(*param_1 + 0x1c))(param_1);
      return;
    }
    (**(code **)*param_1)(param_1);
  }
  return;
}



/* 00018000 FUN_00018000 */

/* Boundary evidence: original MIPS .pdata 00018000..000180b7. Semantic name remains unreviewed. */

ULONG_PTR FUN_00018000(HGDIOBJ param_1)

{
  LPCRITICAL_SECTION p_Var1;
  HDC hdc;
  HDC pHVar2;
  PRTL_CRITICAL_SECTION_DEBUG p_Var3;
  
  if (DAT_00028538 == (LPCRITICAL_SECTION)0x0) {
    p_Var1 = (LPCRITICAL_SECTION)__2_YAPAXI_Z(0x1c);
    if (p_Var1 == (LPCRITICAL_SECTION)0x0) {
      DAT_00028538 = (LPCRITICAL_SECTION)0x0;
    }
    else {
      InitializeCriticalSection(p_Var1);
      hdc = GetDC((HWND)0x0);
      pHVar2 = CreateCompatibleDC(hdc);
      p_Var1->SpinCount = (ULONG_PTR)pHVar2;
      ReleaseDC((HWND)0x0,hdc);
      p_Var1[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
      DAT_00028538 = p_Var1;
    }
  }
  EnterCriticalSection(DAT_00028538);
  p_Var3 = SelectObject((HDC)DAT_00028538->SpinCount,param_1);
  p_Var1 = DAT_00028538;
  DAT_00028538[1].DebugInfo = p_Var3;
  return p_Var1->SpinCount;
}



/* 000180b8 FUN_000180b8 */

/* Boundary evidence: original MIPS .pdata 000180b8..0001813b. Semantic name remains unreviewed. */

undefined4 * FUN_000180b8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00026830;
  if (((HDC)param_1[10] != (HDC)0x0) && ((HWND)param_1[6] != (HWND)0x0)) {
    ReleaseDC((HWND)param_1[6],(HDC)param_1[10]);
  }
  if ((HLOCAL)param_1[1] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001813c FUN_0001813c */

/* Boundary evidence: original MIPS .pdata 0001813c..0001819f. Semantic name remains unreviewed. */

void FUN_0001813c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00026830;
  if (((HDC)param_1[10] != (HDC)0x0) && ((HWND)param_1[6] != (HWND)0x0)) {
    ReleaseDC((HWND)param_1[6],(HDC)param_1[10]);
  }
  if ((HLOCAL)param_1[1] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  return;
}



/* 000181a0 FUN_000181a0 */

/* Boundary evidence: original MIPS .pdata 000181a0..00018237. Semantic name remains unreviewed. */

undefined4 FUN_000181a0(int param_1)

{
  int iVar1;
  
  if (DAT_00027bc4 == 0) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if ((iVar1 < *(int *)(DAT_00027bc4 + 0x6d4)) && (-1 < iVar1)) {
    return *(undefined4 *)(*(int *)(DAT_00027bc4 + 0x6d0) + iVar1 * 4);
  }
  return 0;
}



/* 00018238 FUN_00018238 */

/* Boundary evidence: original MIPS .pdata 00018238..000182d7. Semantic name remains unreviewed. */

void FUN_00018238(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x50) != 0)) && (*(int *)(iVar1 + 0x68) != 0)) {
    FUN_00018000((HGDIOBJ)0x0);
    BitBlt(*(HDC *)(param_1 + 0x28),*(int *)(param_1 + 0x30),*(int *)(param_1 + 0x34),
           *(int *)(param_1 + 0x38),*(int *)(param_1 + 0x3c),*(HDC *)(param_1 + 0x24),
           *(int *)(param_1 + 0x30),*(int *)(param_1 + 0x34),0xcc0020);
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
  }
  return;
}



/* 000182d8 FUN_000182d8 */

/* Boundary evidence: original MIPS .pdata 000182d8..000183ab. Semantic name remains unreviewed. */

void FUN_000182d8(int param_1,int param_2)

{
  HWND pHVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x20);
  *(int *)(param_1 + 0x20) = param_2;
  if (param_2 == 0) {
    if (((iVar2 != 0) && ((*(uint *)(iVar2 + 0x2c) & 0x3f) == 3)) && (*(int *)(iVar2 + 0x38) != 0))
    {
      pHVar1 = *(HWND *)(*(int *)(param_1 + 0x1c) + 0x50);
      if (pHVar1 != (HWND)0x0) {
        KillTimer(pHVar1,0x3f6);
      }
      pHVar1 = *(HWND *)(*(int *)(param_1 + 0x1c) + 0x50);
      if (pHVar1 != (HWND)0x0) {
        KillTimer(pHVar1,0x3f7);
      }
    }
  }
  else if (((*(uint *)(param_2 + 0x2c) & 0x3f) == 3) && (*(int *)(param_2 + 0x38) != 0)) {
    SetTimer(*(HWND *)(*(int *)(param_1 + 0x1c) + 0x50),0x3f6,
             *(UINT *)(*(int *)(param_1 + 0x1c) + 0x84),(TIMERPROC)0x0);
    *(undefined4 *)(param_1 + 0x40) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}



/* 000183ac FUN_000183ac */

/* Boundary evidence: original MIPS .pdata 000183ac..0001843f. Semantic name remains unreviewed. */

void FUN_000183ac(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != -1) {
    if (DAT_00027bc4 == (int *)0x0) {
      MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
    }
    iVar1 = FUN_00014150(DAT_00027bc4,param_2);
    if (iVar1 != 0) {
      *(int *)(param_1 + 0x2c) = param_2;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  return;
}



/* 00018440 FUN_00018440 */

/* Boundary evidence: original MIPS .pdata 00018440..0001850b. Semantic name remains unreviewed. */

void FUN_00018440(int param_1,int *param_2)

{
  int iVar1;
  HGDIOBJ pvVar2;
  HDC hdcSrc;
  int cx;
  int y;
  int x;
  
  iVar1 = FUN_000181a0(param_1);
  if (iVar1 != 0) {
    if (param_2 == (int *)0x0) {
      param_2 = (int *)(param_1 + 0x30);
    }
    x = *param_2;
    y = param_2[1];
    cx = param_2[2];
    iVar1 = param_2[3];
    pvVar2 = (HGDIOBJ)FUN_000181a0(param_1);
    hdcSrc = (HDC)FUN_00018000(pvVar2);
    BitBlt(*(HDC *)(param_1 + 0x24),x,y,cx,iVar1,hdcSrc,x,y,0xcc0020);
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
  }
  return;
}



/* 0001850c FUN_0001850c */

/* Boundary evidence: original MIPS .pdata 0001850c..000185c7. Semantic name remains unreviewed. */

void FUN_0001850c(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    iVar4 = 0;
    do {
      if (uVar3 < *(uint *)(param_1 + 8)) {
        iVar2 = *(int *)(*(int *)(param_1 + 4) + iVar4);
      }
      else {
        iVar2 = 0;
      }
      if ((*(uint *)(iVar2 + 0x2c) & 0x80) != 0) {
        if (uVar3 < *(uint *)(param_1 + 8)) {
          piVar1 = *(int **)(*(int *)(param_1 + 4) + iVar4);
        }
        else {
          piVar1 = (int *)0x0;
        }
        (**(code **)(*piVar1 + 0x1c))();
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 4;
    } while ((int)uVar3 < *(int *)(param_1 + 8));
  }
  return;
}



/* 000185c8 FUN_000185c8 */

/* Boundary evidence: original MIPS .pdata 000185c8..00018683. Semantic name remains unreviewed. */

void FUN_000185c8(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x50) != 0)) && (*(int *)(iVar1 + 0x68) != 0)) &&
     ((param_3 != 0 || (*(int *)(iVar1 + 0x6c) != 0)))) {
    FUN_00018000((HGDIOBJ)0x0);
    BitBlt(*(HDC *)(param_1 + 0x28),*param_2,param_2[1],param_2[2],param_2[3],
           *(HDC *)(param_1 + 0x24),*param_2,param_2[1],0xcc0020);
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
  }
  return;
}



/* 00018684 FUN_00018684 */

/* Boundary evidence: original MIPS .pdata 00018684..0001876f. Semantic name remains unreviewed. */

void FUN_00018684(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5,
                 int param_6,int param_7,int *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  FUN_00013cc0((int *)(param_1 + 4),(int)param_2);
  (**(code **)(*param_2 + 0x18))(param_2,param_3,param_4,param_1);
  uVar5 = (param_6 << 9 ^ param_2[0xb]) & 0x200U ^ param_2[0xb];
  *(undefined1 *)((int)param_2 + 0x31) = param_5;
  param_2[0xb] = uVar5;
  if (param_8 == (int *)0x0) {
    iVar2 = param_2[2];
    iVar3 = param_2[3];
    iVar4 = param_2[4];
    iVar1 = param_2[5];
  }
  else {
    iVar2 = *param_8;
    iVar3 = param_8[1];
    iVar4 = param_8[2];
    iVar1 = param_8[3];
  }
  param_2[0xb] = (param_7 << 0xc ^ uVar5) & 0x1000 ^ uVar5;
  param_2[6] = iVar2;
  param_2[7] = iVar3;
  param_2[8] = iVar4;
  param_2[9] = iVar1;
  return;
}



/* 00018770 FUN_00018770 */

/* Boundary evidence: original MIPS .pdata 00018770..0001886b. Semantic name remains unreviewed. */

void FUN_00018770(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 short *param_6,int param_7,int param_8)

{
  undefined4 uVar1;
  
  FUN_00013cc0((int *)(param_1 + 4),(int)param_2);
  (**(code **)(*param_2 + 0x18))(param_2,param_3,param_4,param_1);
  if (DAT_00027bc4 == 0) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
  }
  if ((param_5 < 0x16) && (*(int *)(DAT_00027bc4 + 4) != 0)) {
    uVar1 = *(undefined4 *)((param_5 + 2) * 4 + DAT_00027bc4);
  }
  else {
    uVar1 = 0;
  }
  FUN_000115c8((int)param_2,uVar1,param_5);
  param_2[0x18] = param_7;
  param_2[0x19] = param_8;
  FUN_00011724(param_2,param_6,0);
  return;
}



/* 0001886c FUN_0001886c */

/* Boundary evidence: original MIPS .pdata 0001886c..00018a6b. Semantic name remains unreviewed. */

void FUN_0001886c(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,short *param_7,int *param_8,int *param_9,int param_10,int param_11,
                 int param_12,uint param_13)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  FUN_00013cc0((int *)(param_1 + 4),(int)param_2);
  (**(code **)(*param_2 + 0x18))(param_2,param_3,param_4,param_1);
  uVar6 = (param_11 << 0x10 ^ param_2[0x15b]) & 0x10000U ^ param_2[0x15b];
  param_2[0xb] = (param_12 << 9 ^ param_2[0xb]) & 0x200U ^ param_2[0xb];
  param_2[0x12] = param_5;
  param_2[0x15b] = ((param_13 & 1) << 0x12 | uVar6 & 0x10000) << 1 | uVar6 & 0xfff5ffff;
  if (param_8 == (int *)0x0) {
    iVar2 = param_2[2];
    iVar3 = param_2[3];
    iVar4 = param_2[4];
    iVar5 = param_2[5];
  }
  else {
    iVar4 = param_8[2];
    iVar5 = param_8[3];
    iVar2 = param_2[2] + *param_8;
    iVar3 = param_2[3] + param_8[1];
  }
  param_2[0x152] = iVar5;
  param_2[0x14f] = iVar2;
  param_2[0x150] = iVar3;
  param_2[0x151] = iVar4;
  param_2[0x22] = iVar5;
  iVar5 = DAT_00027bc4;
  param_2[0x1f] = iVar2;
  param_2[0x20] = iVar3;
  param_2[0x21] = iVar4;
  if (iVar5 == 0) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
    iVar5 = DAT_00027bc4;
  }
  if ((param_6 < 0x16) && (*(int *)(iVar5 + 4) != 0)) {
    uVar1 = *(undefined4 *)((param_6 + 2) * 4 + iVar5);
  }
  else {
    uVar1 = 0;
  }
  FUN_000115c8((int)(param_2 + 0x1d),uVar1,param_6);
  if (param_9 != (int *)0x0) {
    param_2[0x153] = *param_9;
    param_2[0x154] = param_9[1];
    param_2[0x155] = param_9[2];
    param_2[0x156] = param_9[3];
  }
  param_2[0x36] = param_10;
  FUN_00011724(param_2 + 0x1d,param_7,0);
  param_2[0x38] = (uint)param_2[0x15b] >> 0x13 & 1;
  return;
}



/* 00018a6c FUN_00018a6c */

/* Boundary evidence: original MIPS .pdata 00018a6c..00018abb. Semantic name remains unreviewed. */

void FUN_00018a6c(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0x24);
  FUN_000183ac(param_1 + 4,*(int *)(param_2 + 0x2c));
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x28);
  return;
}



/* 00018abc FUN_00018abc */

/* Boundary evidence: original MIPS .pdata 00018abc..00018b7f. Semantic name remains unreviewed. */

void FUN_00018abc(int param_1)

{
  int iVar1;
  HGDIOBJ pvVar2;
  HDC hdcSrc;
  int cx;
  int y;
  int x;
  int iVar3;
  
  iVar3 = param_1 + 4;
  iVar1 = FUN_000181a0(iVar3);
  if (iVar1 != 0) {
    x = *(int *)(param_1 + 0x34);
    y = *(int *)(param_1 + 0x38);
    cx = *(int *)(param_1 + 0x3c);
    iVar1 = *(int *)(param_1 + 0x40);
    pvVar2 = (HGDIOBJ)FUN_000181a0(iVar3);
    hdcSrc = (HDC)FUN_00018000(pvVar2);
    BitBlt(*(HDC *)(param_1 + 0x28),x,y,cx,iVar1,hdcSrc,x,y,0xcc0020);
    SelectObject((HDC)DAT_00028538->SpinCount,DAT_00028538[1].DebugInfo);
    LeaveCriticalSection(DAT_00028538);
  }
  FUN_0001850c(iVar3);
  return;
}



/* 00018b80 FUN_00018b80 */

undefined4 FUN_00018b80(void)

{
  return DAT_00027998;
}



/* 00018b8c FUN_00018b8c */

/* Boundary evidence: original MIPS .pdata 00018b8c..00018bef. Semantic name remains unreviewed. */

void FUN_00018b8c(int param_1)

{
  FILE *_File;
  
  _File = _wfopen(L"/Storage Card2/Antitheft.cfg",L"wb");
  if (_File != (FILE *)0x0) {
    fwrite((void *)(param_1 + 8),4,1,_File);
    fclose(_File);
  }
  return;
}



/* 00018bf0 FUN_00018bf0 */

void FUN_00018bf0(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



/* 00018bf8 FUN_00018bf8 */

/* Boundary evidence: original MIPS .pdata 00018bf8..00018c3b. Semantic name remains unreviewed. */

undefined4 * FUN_00018bf8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00024d98;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00018c3c FUN_00018c3c */

/* Boundary evidence: original MIPS .pdata 00018c3c..00018cf7. Semantic name remains unreviewed. */

void FUN_00018c3c(int param_1)

{
  FILE *_File;
  size_t sVar1;
  int *_DstBuf;
  
  _File = _wfopen(L"/Storage Card2/Antitheft.cfg",L"rb");
  if (_File == (FILE *)0x0) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    _DstBuf = (int *)(param_1 + 8);
    sVar1 = fread(_DstBuf,1,4,_File);
    fclose(_File);
    if (sVar1 != 4) {
      *_DstBuf = 0;
    }
    if (*_DstBuf < 0) {
      *_DstBuf = 0;
    }
    else if (8 < *_DstBuf) {
      *_DstBuf = 8;
    }
  }
  return;
}



/* 00018cf8 FUN_00018cf8 */

/* Boundary evidence: original MIPS .pdata 00018cf8..00018d57. Semantic name remains unreviewed. */

undefined4 * FUN_00018cf8(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_00024d98;
  param_1[2] = 0;
  uVar1 = FUN_000110e4((HKEY)0x80000002,L"LGE\\SystemInfo",L"FACTORY_TYPE",0);
  param_1[1] = uVar1;
  FUN_00018c3c((int)param_1);
  return param_1;
}



/* 00018d58 FUN_00018d58 */

/* Boundary evidence: original MIPS .pdata 00018d58..00018dc3. Semantic name remains unreviewed. */

void FUN_00018d58(void)

{
  undefined4 *puVar1;
  
  if (DAT_00027994 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0xc);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00027994 = (undefined4 *)0x0;
    }
    else {
      DAT_00027994 = FUN_00018cf8(puVar1);
    }
  }
  return;
}



/* 00018dc4 Unwind@00018dc4 */

/* Boundary evidence: original MIPS .pdata 00018dc4..00018df3. Semantic name remains unreviewed. */

void Unwind_00018dc4(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 00018df4 FUN_00018df4 */

/* Boundary evidence: original MIPS .pdata 00018df4..00018e43. Semantic name remains unreviewed. */

void FUN_00018df4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000258a4;
  if ((HMODULE)param_1[1] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0x20;
  return;
}



/* 00018e44 FUN_00018e44 */

/* Boundary evidence: original MIPS .pdata 00018e44..00018ea3. Semantic name remains unreviewed. */

void FUN_00018e44(void)

{
  if (DAT_000279a0 == (undefined4 *)0x0) {
    DAT_000279a0 = (undefined4 *)__2_YAPAXI_Z(0xc);
    if (DAT_000279a0 == (undefined4 *)0x0) {
      DAT_000279a0 = (undefined4 *)0x0;
    }
    else {
      *DAT_000279a0 = &PTR_FUN_000258a4;
      DAT_000279a0[1] = 0;
      DAT_000279a0[2] = 0x20;
    }
  }
  return;
}



/* 00018ea4 FUN_00018ea4 */

undefined4 FUN_00018ea4(undefined4 param_1,ushort *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort *puVar4;
  
  uVar3 = 0;
  puVar4 = param_2;
  if (param_3 != 0) {
    do {
      uVar1 = uVar3;
      puVar2 = puVar4;
      if (*puVar4 == param_4) {
        for (; uVar1 < param_3; uVar1 = uVar1 + 1) {
          if (puVar2[1] == 0) {
            param_2[uVar1] = 0;
            break;
          }
          *puVar2 = puVar2[1];
          puVar2 = puVar2 + 1;
        }
      }
      else if (*puVar4 == 0) {
        return 1;
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < param_3);
  }
  return 1;
}



/* 00018f2c FUN_00018f2c */

/* Boundary evidence: original MIPS .pdata 00018f2c..00018f77. Semantic name remains unreviewed. */

undefined4 * FUN_00018f2c(undefined4 *param_1,uint param_2)

{
  FUN_00018df4(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00018f78 FUN_00018f78 */

/* Boundary evidence: original MIPS .pdata 00018f78..0001907b. Semantic name remains unreviewed. */

bool FUN_00018f78(int param_1,int param_2,int param_3)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 8) < 0) || (0x1f < param_2)) {
    param_2 = 2;
  }
  if (*(HMODULE *)(param_1 + 4) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(int *)(param_1 + 8) = param_2;
  pHVar1 = LoadLibraryW((LPCWSTR)(&PTR_u__Storage_Card_system_data_LangDl_000278dc)[param_2]);
  *(HMODULE *)(param_1 + 4) = pHVar1;
  FUN_000112c8((HKEY)0x80000002,L"LGE\\SystemInfo",L"LANG_INDEX",*(undefined4 *)(param_1 + 8));
  if (param_3 != 0) {
    PostMessageW((HWND)0xffff,DAT_00027bc0,0,param_2);
  }
  if ((param_2 == 0) || (uVar2 = 0, param_2 == 0x1f)) {
    uVar2 = 1;
  }
  FUN_00011718(uVar2);
  return *(int *)(param_1 + 4) != 0;
}



/* 0001907c FUN_0001907c */

/* Boundary evidence: original MIPS .pdata 0001907c..0001910b. Semantic name remains unreviewed. */

undefined * FUN_0001907c(int param_1,UINT param_2)

{
  int iVar1;
  size_t sVar2;
  
  memset(&DAT_000279a4,0,0x21c);
  if ((*(HINSTANCE *)(param_1 + 4) != (HINSTANCE)0x0) &&
     (iVar1 = LoadStringW(*(HINSTANCE *)(param_1 + 4),param_2,(LPWSTR)&DAT_000279a4,0x10e),
     0 < iVar1)) {
    sVar2 = wcslen((wchar_t *)&DAT_000279a4);
    FUN_00018ea4(param_1,(ushort *)&DAT_000279a4,sVar2,0x200f);
  }
  return &DAT_000279a4;
}



/* 0001910c FUN_0001910c */

/* Boundary evidence: original MIPS .pdata 0001910c..000192bf. Semantic name remains unreviewed. */

undefined4 * FUN_0001910c(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  void *_Dst;
  wchar_t local_230;
  undefined1 auStack_22e [518];
  uint local_28;
  
  local_28 = DAT_00027974;
  FUN_00013e3c(param_1);
  *param_1 = &PTR_LAB_0002596c;
  local_230 = L'\0';
  memset(auStack_22e,0,0x206);
  iVar1 = FUN_000110e4((HKEY)0x80000002,L"LGE\\SystemInfo",L"UI_TYPE",0);
  iVar2 = FUN_000110e4((HKEY)0x80000002,L"LGE\\SystemInfo",L"UI_INVERSE",0);
  FUN_000112c8((HKEY)0x80000002,L"LGE\\SystemInfo",L"UI_INVERSE",iVar2);
  param_1[0x1b8] = 0;
  if (iVar1 == 1) {
    if (iVar2 != 1) goto LAB_00019204;
    iVar1 = 3;
  }
  if ((iVar1 < 0) || (3 < iVar1)) {
    iVar1 = 0;
  }
LAB_00019204:
  param_1[0x1b6] = iVar1;
  _snwprintf(&local_230,99,L"%s%s\\",L"img/",(&PTR_DAT_0002795c)[iVar1]);
  FUN_00014468((int)param_1,&local_230);
  FUN_00014414((int)param_1,L"font/");
  _Dst = (void *)__2_YAPAXI_Z(0x734);
  param_1[0x1b4] = _Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x734);
    FUN_00013fa8((int)param_1,0x1cd);
  }
  FUN_0001bb10(local_28);
  return param_1;
}



/* 000192c0 Unwind@000192c0 */

/* Boundary evidence: original MIPS .pdata 000192c0..000192ef. Semantic name remains unreviewed. */

void Unwind_000192c0(void)

{
  int in_v0;
  
  FUN_00013f3c(*(undefined4 **)(in_v0 + -0x238));
  return;
}



/* 000192f0 FUN_000192f0 */

/* Boundary evidence: original MIPS .pdata 000192f0..00019353. Semantic name remains unreviewed. */

void FUN_000192f0(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0002596c;
  if (param_1[0x1b4] != 0) {
    __3_YAXPAX_Z();
    param_1[0x1b4] = 0;
  }
  FUN_00013f3c(param_1);
  return;
}



/* 00019354 Unwind@00019354 */

/* Boundary evidence: original MIPS .pdata 00019354..00019383. Semantic name remains unreviewed. */

void Unwind_00019354(void)

{
  undefined4 *in_v0;
  
  FUN_00013f3c((undefined4 *)*in_v0);
  return;
}



/* 00019390 FUN_00019390 */

/* Boundary evidence: original MIPS .pdata 00019390..000193f7. Semantic name remains unreviewed. */

undefined * FUN_00019390(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)*param_1)();
  _snwprintf((wchar_t *)&DAT_00027bcc,99,L"%s%s\\",uVar1,(&PTR_DAT_0002795c)[param_2]);
  return &DAT_00027bcc;
}



/* 000193f8 FUN_000193f8 */

/* Boundary evidence: original MIPS .pdata 000193f8..00019447. Semantic name remains unreviewed. */

undefined * FUN_000193f8(int param_1,int param_2)

{
  wsprintfW((LPWSTR)&DAT_00027dcc,L"%s%s",param_1 + 0x2c0,
            (&PTR_u_common_home_bg_bmp_000271a8)[param_2]);
  return &DAT_00027dcc;
}



/* 00019448 FUN_00019448 */

/* Boundary evidence: original MIPS .pdata 00019448..000194b3. Semantic name remains unreviewed. */

void FUN_00019448(void)

{
  undefined4 *puVar1;
  
  if (DAT_00027bc4 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x6e4);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00027bc4 = (undefined4 *)0x0;
    }
    else {
      DAT_00027bc4 = FUN_0001910c(puVar1);
    }
  }
  return;
}



/* 000194b4 Unwind@000194b4 */

/* Boundary evidence: original MIPS .pdata 000194b4..000194e3. Semantic name remains unreviewed. */

void Unwind_000194b4(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 000194e4 FUN_000194e4 */

/* Boundary evidence: original MIPS .pdata 000194e4..0001952f. Semantic name remains unreviewed. */

undefined4 * FUN_000194e4(undefined4 *param_1,uint param_2)

{
  FUN_000192f0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00019530 FUN_00019530 */

/* Boundary evidence: original MIPS .pdata 00019530..00019787. Semantic name remains unreviewed. */

void FUN_00019530(int param_1)

{
  int iVar1;
  short *psVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_88 = 0;
  local_84 = 0;
  local_80 = 800;
  local_7c = 0x1e0;
  FUN_000158a0(param_1,(int *)(param_1 + 0x2d4),0xffffffff,&local_88,1000,0);
  local_74 = 0x4a;
  piVar4 = (int *)(param_1 + 0x348);
  local_78 = 0x83;
  local_70 = 0x21b;
  local_6c = 0x14c;
  FUN_00015938(param_1,piVar4,0x187,&local_78,1,1,0,(int *)0x0);
  local_68 = 0x83;
  local_64 = 0x54;
  local_60 = 0x21b;
  local_5c = 0x28;
  iVar1 = FUN_00018e44();
  psVar2 = (short *)FUN_0001907c(iVar1,0x708);
  FUN_00015974(param_1,(int *)(param_1 + 0x39c),0xffffffff,&local_68,0xd,psVar2,0xffffff,0x825);
  local_58 = 0x83;
  local_50 = 0x21b;
  piVar3 = (int *)(param_1 + 0x8f4);
  local_54 = 0xa4;
  local_4c = 0x28;
  FUN_00015974(param_1,piVar3,0xffffffff,&local_58,9,(short *)&DAT_0002631c,0xffffff,0x815);
  local_48 = 0x83;
  local_44 = 0xd6;
  local_3c = 0x28;
  local_40 = 0x21b;
  FUN_00015974(param_1,(int *)(param_1 + 0x648),0xffffffff,&local_48,9,(short *)&DAT_0002631c,
               0xffffff,0x825);
  FUN_00011b20(param_1 + 0x648,1);
  local_38 = 0x83;
  local_34 = 0x108;
  local_30 = 0x21b;
  local_2c = 0x28;
  FUN_00015974(param_1,(int *)(param_1 + 0xba0),0xffffffff,&local_38,9,(short *)&DAT_0002631c,
               0xffffff,0x825);
  FUN_00011710(param_1 + 0x39c,piVar4);
  FUN_00011710((int)piVar3,piVar4);
  FUN_00011b20((int)piVar3,1);
  FUN_00011710(param_1 + 0xba0,piVar4);
  return;
}



/* 00019788 FUN_00019788 */

/* Boundary evidence: original MIPS .pdata 00019788..000197b7. Semantic name remains unreviewed. */

undefined4 FUN_00019788(void)

{
  PostMessageW(DAT_00028518,0x10,0,0);
  return 0;
}



/* 000197b8 FUN_000197b8 */

/* Boundary evidence: original MIPS .pdata 000197b8..000197f7. Semantic name remains unreviewed. */

undefined4 FUN_000197b8(int *param_1,int param_2)

{
  if ((999 < param_2) && (param_2 < 0x3eb)) {
    (**(code **)(*param_1 + 0x40))();
  }
  return 0;
}



/* 000197f8 FUN_000197f8 */

/* Boundary evidence: original MIPS .pdata 000197f8..0001989b. Semantic name remains unreviewed. */

void FUN_000197f8(int param_1,int param_2,int param_3)

{
  wchar_t local_40;
  undefined1 auStack_3e [38];
  uint local_18;
  
  local_18 = DAT_00027974;
  local_40 = L'\0';
  memset(auStack_3e,0,0x26);
  _snwprintf(&local_40,0x13,L"%02d:%02d",param_2 / 0x3c,param_2 % 0x3c);
  FUN_00011724((int *)(param_1 + 0xba0),&local_40,param_3);
  FUN_0001bb10(local_18);
  return;
}



/* 0001989c FUN_0001989c */

/* Boundary evidence: original MIPS .pdata 0001989c..0001992b. Semantic name remains unreviewed. */

void FUN_0001989c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00013df0();
  iVar1 = *(int *)(iVar1 + 0x6d8);
  if (DAT_0002796c != iVar1) {
    if (iVar1 == 3) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffff;
    }
    DAT_0002796c = iVar1;
    FUN_00011708(param_1 + 0x39c,uVar2);
    FUN_00011708(param_1 + 0x8f4,uVar2);
    FUN_00011708(param_1 + 0x648,uVar2);
    FUN_00011708(param_1 + 0xba0,uVar2);
  }
  return;
}



/* 0001992c FUN_0001992c */

/* Boundary evidence: original MIPS .pdata 0001992c..0001995b. Semantic name remains unreviewed. */

void FUN_0001992c(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  FUN_00014a2c(DAT_00027fd4,param_1,param_2,param_3,param_4);
  return;
}



/* 0001995c FUN_0001995c */

/* Boundary evidence: original MIPS .pdata 0001995c..00019c3b. Semantic name remains unreviewed. */

void FUN_0001995c(int param_1,int *param_2)

{
  int iVar1;
  short *psVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  HWND hWnd;
  wchar_t *pwVar6;
  int *piVar7;
  wchar_t local_328;
  undefined1 auStack_326 [262];
  wchar_t local_220;
  undefined1 auStack_21e [518];
  uint local_18;
  
  local_18 = DAT_00027974;
  local_328 = L'\0';
  memset(auStack_326,0,0x100);
  local_220 = L'\0';
  memset(auStack_21e,0,0x206);
  if (*(HWND *)(param_1 + 0x50) != (HWND)0x0) {
    SetWindowPos(*(HWND *)(param_1 + 0x50),(HWND)0xffffffff,0,0,0,0,3);
  }
  if (DAT_0002799c != 0) {
    iVar1 = FUN_00018e44();
    psVar2 = (short *)FUN_0001907c(iVar1,0x708);
    FUN_00011724((int *)(param_1 + 0x39c),psVar2,0);
  }
  FUN_0001989c(param_1);
  iVar1 = FUN_00018e44();
  puVar3 = FUN_0001907c(iVar1,0x59a);
  _snwprintf(&local_328,0x80,L"%s",puVar3);
  iVar1 = FUN_00018e44();
  puVar3 = FUN_0001907c(iVar1,0x709);
  _snwprintf(&local_220,0x103,L"%s ",puVar3);
  iVar1 = FUN_00018e44();
  psVar2 = (short *)FUN_0001907c(iVar1,0x70a);
  FUN_00011388(&local_220,0x104,psVar2);
  (**(code **)(*(int *)(param_1 + 0x2d4) + 0x20))((int *)(param_1 + 0x2d4),0,1);
  if ((param_2 == (int *)0x0) || (iVar1 = *param_2, iVar1 == 0)) {
    pwVar6 = L"Incorrect code";
  }
  else {
    if (iVar1 != 1) {
      iVar4 = FUN_00018b80();
      if (*(int *)(iVar4 + 8) < 9) {
        iVar4 = FUN_00018b80();
        iVar4 = *(int *)(iVar4 + 8);
      }
      else {
        iVar4 = 8;
      }
      *(undefined4 *)(param_1 + 0xe4c) = *(undefined4 *)(&DAT_00025a58 + iVar4 * 4);
      iVar5 = FUN_00018b80();
      NKDbgPrintfW(L"\r\n[CodeChecker][%d] %d -- %d\r\n",iVar1,*(undefined4 *)(iVar5 + 8),iVar4);
      FUN_00011724((int *)(param_1 + 0x8f4),&local_220,0);
      FUN_00011724((int *)(param_1 + 0x648),&local_328,0);
      FUN_000197f8(param_1,*(int *)(param_1 + 0xe4c),1);
      SetTimer(*(HWND *)(param_1 + 0x50),0x3eb,1000,(TIMERPROC)0x0);
      if (iVar1 != 4) {
        iVar1 = FUN_00018b80();
        FUN_00018b8c(iVar1);
      }
      hWnd = FindWindowW(L"MGRMCM",(LPCWSTR)0x0);
      if (hWnd != (HWND)0x0) {
        PostMessageW(hWnd,0x8064,0xb40300,0);
      }
      goto LAB_00019c1c;
    }
    pwVar6 = L"Code OK";
  }
  piVar7 = (int *)(param_1 + 0x8f4);
  FUN_00011724(piVar7,pwVar6,0);
  (**(code **)(*piVar7 + 0x2c))(piVar7,0,0x2d);
  FUN_00011724((int *)(param_1 + 0x648),(short *)&DAT_000261fc,0);
  FUN_00015a14(param_1,5000);
LAB_00019c1c:
  FUN_0001bb10(local_18);
  return;
}



/* 00019c3c FUN_00019c3c */

/* Boundary evidence: original MIPS .pdata 00019c3c..00019d5b. Semantic name remains unreviewed. */

int FUN_00019c3c(int *param_1,HINSTANCE param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  WNDCLASSW *pWVar2;
  HWND pHVar3;
  int *piVar4;
  
  iVar1 = param_1[0x14];
  if (iVar1 == 0) {
    param_1[0x12] = (int)param_2;
    pWVar2 = FUN_00016328(DAT_00027fd4,param_2,FUN_0001992c);
    pHVar3 = CreateWindowExW(0x4000000,pWVar2->lpszClassName,L"CGUIPopupDlg",0x80000000,0,0,800,
                             0x1e0,(HWND)0x0,(HMENU)0x0,param_2,(LPVOID)0x0);
    param_1[0x14] = (int)pHVar3;
    if (pHVar3 == (HWND)0x0) {
      GetLastError();
      iVar1 = 0;
    }
    else {
      if (DAT_00027984 - 1 < DAT_00027984) {
        piVar4 = *(int **)((DAT_00027984 - 1) * 4 + DAT_00027980);
      }
      else {
        piVar4 = (int *)0x0;
      }
      if (param_1[0x1e] != 0) {
        (**(code **)(*piVar4 + 0x60))();
      }
      FUN_00014f98(param_1,param_4,param_5);
      iVar1 = param_1[0x14];
    }
  }
  return iVar1;
}



/* 00019d5c FUN_00019d5c */

/* Boundary evidence: original MIPS .pdata 00019d5c..00019d9f. Semantic name remains unreviewed. */

void FUN_00019d5c(undefined4 *param_1)

{
  if ((HLOCAL)param_1[0x10] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x10]);
    param_1[0x10] = 0;
  }
  param_1[0x11] = 0;
  FUN_000165d4(param_1);
  return;
}



/* 00019da0 FUN_00019da0 */

/* Boundary evidence: original MIPS .pdata 00019da0..00019e0f. Semantic name remains unreviewed. */

undefined4 FUN_00019da0(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_3 == 0x113) && (param_4 == 0x3eb)) {
    iVar1 = param_1[0x393];
    if (iVar1 < 2) {
      (**(code **)(*param_1 + 0x40))();
    }
    else if (0 < iVar1) {
      param_1[0x393] = iVar1 + -1;
      FUN_000197f8((int)param_1,iVar1 + -1,1);
    }
  }
  return 1;
}



/* 00019e10 FUN_00019e10 */

/* Boundary evidence: original MIPS .pdata 00019e10..00019eaf. Semantic name remains unreviewed. */

undefined4 * FUN_00019e10(undefined4 *param_1)

{
  FUN_00015a44(param_1);
  *param_1 = &PTR_FUN_00025b34;
  FUN_00017070(param_1 + 0xb5);
  FUN_000169d4(param_1 + 0xd2);
  FUN_000114f8(param_1 + 0xe7);
  FUN_000114f8(param_1 + 0x192);
  FUN_000114f8(param_1 + 0x23d);
  FUN_000114f8(param_1 + 0x2e8);
  param_1[0xb0] = 0x27;
  param_1[0x393] = 0;
  return param_1;
}



/* 00019eb0 Unwind@00019eb0 */

/* Boundary evidence: original MIPS .pdata 00019eb0..00019edf. Semantic name remains unreviewed. */

void Unwind_00019eb0(void)

{
  undefined4 *in_v0;
  
  FUN_00019fe4((int *)*in_v0);
  return;
}



/* 00019ee0 Unwind@00019ee0 */

/* Boundary evidence: original MIPS .pdata 00019ee0..00019f13. Semantic name remains unreviewed. */

void Unwind_00019ee0(void)

{
  int *in_v0;
  
  FUN_000178b4((undefined4 *)(*in_v0 + 0x2d4));
  return;
}



/* 00019f14 Unwind@00019f14 */

/* Boundary evidence: original MIPS .pdata 00019f14..00019f47. Semantic name remains unreviewed. */

void Unwind_00019f14(void)

{
  int *in_v0;
  
  FUN_00019d5c((undefined4 *)(*in_v0 + 0x348));
  return;
}



/* 00019f48 Unwind@00019f48 */

/* Boundary evidence: original MIPS .pdata 00019f48..00019f7b. Semantic name remains unreviewed. */

void Unwind_00019f48(void)

{
  int *in_v0;
  
  FUN_00012024((undefined4 *)(*in_v0 + 0x39c));
  return;
}



/* 00019f7c Unwind@00019f7c */

/* Boundary evidence: original MIPS .pdata 00019f7c..00019faf. Semantic name remains unreviewed. */

void Unwind_00019f7c(void)

{
  int *in_v0;
  
  FUN_00012024((undefined4 *)(*in_v0 + 0x648));
  return;
}



/* 00019fb0 Unwind@00019fb0 */

/* Boundary evidence: original MIPS .pdata 00019fb0..00019fe3. Semantic name remains unreviewed. */

void Unwind_00019fb0(void)

{
  int *in_v0;
  
  FUN_00012024((undefined4 *)(*in_v0 + 0x8f4));
  return;
}



/* 00019fe4 FUN_00019fe4 */

/* Boundary evidence: original MIPS .pdata 00019fe4..00019fff. Semantic name remains unreviewed. */

void FUN_00019fe4(int *param_1)

{
  FUN_000145e0(param_1);
  return;
}



/* 0001a000 FUN_0001a000 */

/* Boundary evidence: original MIPS .pdata 0001a000..0001a5db. Semantic name remains unreviewed. */

void FUN_0001a000(int param_1)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  short local_180;
  undefined1 auStack_17e [6];
  int local_178 [22];
  undefined4 local_120;
  undefined4 local_11c;
  int local_118 [5];
  int local_104;
  undefined4 local_100;
  undefined4 local_fc;
  int local_f8 [5];
  int local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  int local_d8 [28];
  short local_68 [11];
  undefined1 auStack_52 [38];
  uint local_2c;
  
  local_2c = DAT_00027974;
  local_178[0] = 0x1a1c1c;
  local_178[1] = 0x1a1c1c;
  local_178[2] = 0x1a1c1c;
  local_178[3] = 0x1a1c1c;
  local_d8[0xc] = 0xffffff;
  local_d8[0xd] = 0;
  local_d8[0xe] = 0x53595c;
  local_d8[0xf] = 0;
  local_178[4] = 0xffffff;
  local_178[5] = 0;
  local_178[6] = 0x53595c;
  local_178[7] = 0;
  FUN_00015884(param_1,0x1c3);
  local_d8[0x18] = 99;
  local_d8[0x19] = 0x15;
  local_d8[0x1a] = 600;
  local_d8[0x1b] = 0x3c;
  iVar1 = FUN_00018e44();
  psVar2 = (short *)FUN_0001907c(iVar1,0x708);
  FUN_00015974(param_1,(int *)(param_1 + 0x2c8),0xffffffff,local_d8 + 0x18,0x10,psVar2,0xffffff,
               0x801);
  local_d8[0x10] = 0xc6;
  local_178[0x10] = 0;
  local_178[0x11] = 0x11;
  local_178[0x12] = 0x58;
  local_178[0x13] = 0x30;
  local_d8[0x11] = 0x5e;
  local_d8[0x12] = 0x58;
  local_d8[0x13] = 0x44;
  FUN_000159b0(param_1,(int *)(param_1 + 0x574),0x158,local_d8 + 0x10,0,0x15,(short *)&DAT_0002631c,
               local_178 + 0x10,local_178,0x825,0,1,0);
  local_d8[8] = 0x12f;
  local_118[0] = 0;
  local_118[1] = 0x11;
  local_118[2] = 0x58;
  local_118[3] = 0x30;
  local_d8[9] = 0x5e;
  local_d8[10] = 0x58;
  local_d8[0xb] = 0x44;
  FUN_000159b0(param_1,(int *)(param_1 + 0xae4),0x158,local_d8 + 8,0,0x15,(short *)&DAT_0002631c,
               local_118,local_178,0x825,0,1,0);
  local_178[8] = 0x198;
  local_f8[2] = 0x58;
  local_178[10] = 0x58;
  local_f8[0] = 0;
  local_f8[1] = 0x11;
  local_f8[3] = 0x30;
  local_178[9] = 0x5e;
  local_178[0xb] = 0x44;
  FUN_000159b0(param_1,(int *)(param_1 + 0x1054),0x158,local_178 + 8,0,0x15,(short *)&DAT_0002631c,
               local_f8,local_178,0x825,0,1,0);
  local_d8[3] = 0x30;
  local_178[0xc] = 0x201;
  local_178[0xd] = 0x5e;
  local_d8[2] = 0x58;
  local_178[0xe] = 0x58;
  local_178[0xf] = 0x44;
  local_d8[0] = 0;
  local_d8[1] = 0x11;
  FUN_000159b0(param_1,(int *)(param_1 + 0x15c4),0x158,local_178 + 0xc,0,0x15,(short *)&DAT_0002631c
               ,local_d8,local_178,0x825,0,1,0);
  FUN_000165e4(param_1 + 0x574,1);
  FUN_000165e4(param_1 + 0xae4,1);
  FUN_000165e4(param_1 + 0x1054,1);
  FUN_000165e4(param_1 + 0x15c4,1);
  memcpy(local_68,L"1234567890",0x16);
  memset(auStack_52,0,0x26);
  memset(auStack_17e,0,2);
  iVar1 = 0;
  iVar3 = 0x6d;
  do {
    iVar4 = iVar1 % 5;
    if (iVar4 == 0) {
      iVar3 = iVar3 + 0x60;
    }
    local_180 = local_68[iVar1];
    if (iVar1 < 5) {
      if (iVar1 == 0) {
        local_178[0x14] = 0x1e;
        local_120 = 0x7c;
        local_11c = 0x61;
        local_178[0x15] = iVar3;
        FUN_000159b0(param_1,(int *)(param_1 + 0x1b34),0x1c5,local_178 + 0x14,0x3e9,0x10,&local_180,
                     (int *)0x0,local_178 + 4,0x825,0,1,0);
      }
      else {
        local_100 = 0x7c;
        local_fc = 0x61;
        local_118[4] = iVar4 * 0x7b + 0x1e;
        local_104 = iVar3;
        FUN_000159b0(param_1,(int *)(iVar1 * 0x570 + param_1 + 0x1b34),0x1cc,local_118 + 4,
                     iVar1 + 0x3e9,0x10,&local_180,(int *)0x0,local_178 + 4,0x825,0,1,0);
      }
    }
    else {
      local_e0 = 0x7c;
      local_dc = 0x61;
      local_f8[4] = iVar4 * 0x7b + 0x1e;
      local_e4 = iVar3;
      FUN_000159b0(param_1,(int *)(iVar1 * 0x570 + param_1 + 0x1b34),iVar4 + 0x1c7,local_f8 + 4,
                   iVar1 + 0x3e9,0x10,&local_180,(int *)0x0,local_178 + 4,0x825,0,1,0);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  local_d8[4] = 0x285;
  local_d8[5] = 0xcd;
  local_d8[6] = 0x7d;
  local_d8[7] = 0xc1;
  FUN_000158a0(param_1,(int *)(param_1 + 0x5194),0x1c6,local_d8 + 4,0x3f3,1);
  local_d8[0x16] = 0x6d;
  local_d8[0x14] = 0x2b3;
  local_d8[0x15] = 0x1a3;
  local_d8[0x17] = 0x3d;
  iVar1 = FUN_00018e44();
  psVar2 = (short *)FUN_0001907c(iVar1,0x45c);
  FUN_000159b0(param_1,(int *)(param_1 + 21000),0x1c4,local_d8 + 0x14,1000,0xc,psVar2,(int *)0x0,
               local_d8 + 0xc,0x825,0,1,0);
  FUN_0001bb10(local_2c);
  return;
}



/* 0001a5dc FUN_0001a5dc */

/* Boundary evidence: original MIPS .pdata 0001a5dc..0001a63f. Semantic name remains unreviewed. */

undefined4 FUN_0001a5dc(int param_1,int param_2)

{
  if (param_2 == 1) {
    if ((*(HWND *)(param_1 + 0x50) != (HWND)0x0) && (DAT_00027fdc == 0)) {
      SetForegroundWindow(*(HWND *)(param_1 + 0x50));
    }
  }
  else if (param_2 == 0) {
    DAT_00027fdc = 0;
  }
  return 1;
}



/* 0001a640 FUN_0001a640 */

undefined4 FUN_0001a640(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (4 < *(int *)(param_1 + 0x5784)) {
    *(undefined4 *)(param_1 + 0x5784) = 4;
  }
  iVar2 = *(int *)(param_1 + 0x5784);
  if (iVar2 < 0) {
    uVar1 = 0;
  }
  else {
    if (0 < iVar2) {
      *(int *)(param_1 + 0x5784) = iVar2 + -1;
    }
    *(undefined2 *)((*(int *)(param_1 + 0x5784) + 0x2bbc) * 2 + param_1) = 0;
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001a69c FUN_0001a69c */

/* Boundary evidence: original MIPS .pdata 0001a69c..0001a7db. Semantic name remains unreviewed. */

void FUN_0001a69c(int param_1,int param_2)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t local_20;
  undefined1 auStack_1e [2];
  wchar_t local_1c;
  undefined1 auStack_1a [2];
  wchar_t local_18;
  undefined1 auStack_16 [2];
  wchar_t local_14;
  undefined1 auStack_12 [2];
  
  local_20 = L'\0';
  memset(auStack_1e,0,2);
  local_1c = L'\0';
  memset(auStack_1a,0,2);
  local_18 = L'\0';
  memset(auStack_16,0,2);
  local_14 = L'\0';
  memset(auStack_12,0,2);
  wcsncpy(&local_20,(wchar_t *)(param_1 + 0x5778),1);
  wcsncpy(&local_1c,(wchar_t *)(param_1 + 0x577a),1);
  wcsncpy(&local_18,(wchar_t *)(param_1 + 0x577c),1);
  wcsncpy(&local_14,(wchar_t *)(param_1 + 0x577e),1);
  pwVar2 = L"*";
  pwVar1 = &local_20;
  if (local_20 != L'\0') {
    pwVar1 = pwVar2;
  }
  FUN_00017dc4((int *)(param_1 + 0x574),pwVar1,param_2);
  pwVar1 = &local_1c;
  if (local_1c != L'\0') {
    pwVar1 = pwVar2;
  }
  FUN_00017dc4((int *)(param_1 + 0xae4),pwVar1,param_2);
  pwVar1 = &local_18;
  if (local_18 != L'\0') {
    pwVar1 = pwVar2;
  }
  FUN_00017dc4((int *)(param_1 + 0x1054),pwVar1,param_2);
  if (local_14 == L'\0') {
    pwVar2 = &local_14;
  }
  FUN_00017dc4((int *)(param_1 + 0x15c4),pwVar2,param_2);
  return;
}



/* 0001a7dc FUN_0001a7dc */

/* Boundary evidence: original MIPS .pdata 0001a7dc..0001a83b. Semantic name remains unreviewed. */

void FUN_0001a7dc(void)

{
  wchar_t local_218;
  undefined1 auStack_216 [518];
  uint local_10;
  
  local_10 = DAT_00027974;
  local_218 = L'\0';
  memset(auStack_216,0,0x206);
  _snwprintf(&local_218,0x103,L"Current Authkey : %d%d%d%d",0,0,0,0);
  FUN_0001bb10(local_10);
  return;
}



/* 0001a83c FUN_0001a83c */

/* Boundary evidence: original MIPS .pdata 0001a83c..0001a89f. Semantic name remains unreviewed. */

void FUN_0001a83c(int param_1)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = FUN_00018e44();
  psVar2 = (short *)FUN_0001907c(iVar1,0x708);
  FUN_00011724((int *)(param_1 + 0x2c8),psVar2,0);
  iVar1 = FUN_00018e44();
  psVar2 = (short *)FUN_0001907c(iVar1,0x45c);
  FUN_00017dc4((int *)(param_1 + 21000),psVar2,0);
  return;
}



/* 0001a8a0 FUN_0001a8a0 */

/* Boundary evidence: original MIPS .pdata 0001a8a0..0001a997. Semantic name remains unreviewed. */

void FUN_0001a8a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = FUN_00013df0();
  iVar1 = *(int *)(iVar1 + 0x6d8);
  if (DAT_00027970 == iVar1) {
    return;
  }
  DAT_00027970 = iVar1;
  memset(&local_1c,0,0xc);
  local_14 = 0;
  if (iVar1 == 0) {
LAB_0001a930:
    local_18 = 0x8c654a;
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 3) {
        local_18 = 0xa2a2a2;
        uVar2 = 0;
        local_20 = 0;
        local_1c = 0xffffff;
        goto LAB_0001a948;
      }
      goto LAB_0001a930;
    }
    local_18 = 0x53595c;
  }
  local_1c = 0;
  uVar2 = 0xffffff;
  local_20 = 0xffffff;
LAB_0001a948:
  FUN_00011708(param_1 + 0x2c8,uVar2);
  iVar1 = param_1 + 0x1b34;
  iVar3 = 10;
  do {
    FUN_00017d94(iVar1,&local_20);
    iVar3 = iVar3 + -1;
    iVar1 = iVar1 + 0x570;
  } while (iVar3 != 0);
  FUN_00017d94(param_1 + 21000,&local_20);
  return;
}



/* 0001a998 FUN_0001a998 */

/* Boundary evidence: original MIPS .pdata 0001a998..0001aa03. Semantic name remains unreviewed. */

void FUN_0001a998(void)

{
  undefined4 *puVar1;
  
  if (DAT_00027fd4 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0xe50);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00027fd4 = (undefined4 *)0x0;
    }
    else {
      DAT_00027fd4 = FUN_00019e10(puVar1);
    }
  }
  return;
}



/* 0001aa04 Unwind@0001aa04 */

/* Boundary evidence: original MIPS .pdata 0001aa04..0001aa33. Semantic name remains unreviewed. */

void Unwind_0001aa04(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0001aa34 FUN_0001aa34 */

/* Boundary evidence: original MIPS .pdata 0001aa34..0001aa63. Semantic name remains unreviewed. */

void FUN_0001aa34(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  FUN_00014a2c(DAT_00027fd8,param_1,param_2,param_3,param_4);
  return;
}



/* 0001aa64 FUN_0001aa64 */

/* Boundary evidence: original MIPS .pdata 0001aa64..0001ab53. Semantic name remains unreviewed. */

void FUN_0001aa64(int param_1)

{
  int iVar1;
  
  DAT_00027fdc = 0;
  FUN_0001a8a0(param_1);
  FUN_000163ec(param_1);
  if (DAT_0002799c != 0) {
    FUN_0001a83c(param_1);
  }
  FUN_0001a7dc();
  *(undefined4 *)(param_1 + 0x5784) = 0;
  *(undefined2 *)(param_1 + 0x5778) = 0;
  *(undefined2 *)(param_1 + 0x577a) = 0;
  *(undefined2 *)(param_1 + 0x577c) = 0;
  *(undefined2 *)(param_1 + 0x577e) = 0;
  *(undefined2 *)(param_1 + 0x5780) = 0;
  FUN_0001a69c(param_1,0);
  iVar1 = FUN_00018b80();
  if (*(int *)(iVar1 + 4) != 0) {
    SetTimer(*(HWND *)(param_1 + 0x50),0x43c,0x32,(TIMERPROC)0x0);
  }
  memset((LPBYTE)(param_1 + 0x5788),0,4);
  FUN_000111fc((HKEY)0x80000002,L"LGE\\SystemInfo",L"F_CODE",0,(LPBYTE)(param_1 + 0x5788));
  return;
}



/* 0001ab54 FUN_0001ab54 */

/* Boundary evidence: original MIPS .pdata 0001ab54..0001ae53. Semantic name remains unreviewed. */

undefined4 FUN_0001ab54(int param_1,undefined4 param_2)

{
  bool bVar1;
  size_t sVar2;
  HWND hWnd;
  int *piVar3;
  int iVar4;
  undefined2 uVar5;
  wchar_t *pwVar6;
  int *piVar7;
  wchar_t *_Str;
  undefined4 local_20 [2];
  
  switch(param_2) {
  case 1000:
    _Str = (wchar_t *)(param_1 + 0x5778);
    sVar2 = wcslen(_Str);
    if (sVar2 != 4) {
      return 0;
    }
    local_20[0] = 0;
    bVar1 = true;
    iVar4 = 0;
    pwVar6 = _Str;
    do {
      if ((ushort)*(byte *)(param_1 + 0x5788 + iVar4) != *pwVar6) {
        NKDbgPrintfW(L"[CodeChecker] Wrong Key input \r\n");
        bVar1 = false;
        break;
      }
      iVar4 = iVar4 + 1;
      pwVar6 = pwVar6 + 1;
    } while (iVar4 < 4);
    DAT_00027fdc = 1;
    if (bVar1) {
      iVar4 = FUN_00018b80();
      FUN_00018bf0(iVar4);
      iVar4 = FUN_00018b80();
      if (*(int *)(iVar4 + 4) != 0) {
        hWnd = FindWindowW(L"AppMain",L"AppMain");
        PostMessageW(hWnd,0x83e9,0x10001,0);
        PostMessageW(DAT_00028518,0x10,0,0);
        return 0;
      }
      local_20[0] = 1;
      if (DAT_00027984 - 1 < DAT_00027984) {
        piVar7 = *(int **)((DAT_00027984 - 1) * 4 + DAT_00027980);
      }
      else {
        piVar7 = (int *)0x0;
      }
      piVar3 = (int *)FUN_0001a998();
      FUN_000152fc(piVar7,piVar3,local_20,0,1,1);
      return 0;
    }
    iVar4 = FUN_00018b80();
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;
    iVar4 = FUN_00018b80();
    if (*(int *)(iVar4 + 4) == 0) {
      local_20[0] = 0;
    }
    else {
      local_20[0] = 2;
    }
    if (DAT_00027984 - 1 < DAT_00027984) {
      piVar7 = *(int **)((DAT_00027984 - 1) * 4 + DAT_00027980);
    }
    else {
      piVar7 = (int *)0x0;
    }
    piVar3 = (int *)FUN_0001a998();
    FUN_000152fc(piVar7,piVar3,local_20,0,1,1);
    *(undefined4 *)(param_1 + 0x5784) = 0;
    *_Str = L'\0';
    *(undefined2 *)(param_1 + 0x577a) = 0;
    *(undefined2 *)(param_1 + 0x577c) = 0;
    *(undefined2 *)(param_1 + 0x577e) = 0;
    *(undefined2 *)(param_1 + 0x5780) = 0;
    goto LAB_0001ae28;
  case 0x3e9:
    uVar5 = 0x31;
    break;
  case 0x3ea:
    uVar5 = 0x32;
    break;
  case 0x3eb:
    uVar5 = 0x33;
    break;
  case 0x3ec:
    uVar5 = 0x34;
    break;
  case 0x3ed:
    uVar5 = 0x35;
    break;
  case 0x3ee:
    uVar5 = 0x36;
    break;
  case 0x3ef:
    uVar5 = 0x37;
    break;
  case 0x3f0:
    uVar5 = 0x38;
    break;
  case 0x3f1:
    uVar5 = 0x39;
    break;
  case 0x3f2:
    uVar5 = 0x30;
    break;
  case 0x3f3:
    FUN_0001a640(param_1);
    goto LAB_0001ae28;
  default:
    goto switchD_0001ab94_default;
  }
  if (*(int *)(param_1 + 0x5784) < 4) {
    *(undefined2 *)((*(int *)(param_1 + 0x5784) + 0x2bbc) * 2 + param_1) = uVar5;
    *(int *)(param_1 + 0x5784) = *(int *)(param_1 + 0x5784) + 1;
  }
LAB_0001ae28:
  FUN_0001a69c(param_1,1);
switchD_0001ab94_default:
  return 0;
}



/* 0001ae54 FUN_0001ae54 */

/* Boundary evidence: original MIPS .pdata 0001ae54..0001af1b. Semantic name remains unreviewed. */

undefined4 FUN_0001ae54(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 local_18 [2];
  
  if ((param_3 == 0x113) && (param_4 == 0x43c)) {
    KillTimer(*(HWND *)(param_1 + 0x50),0x43c);
    iVar1 = FUN_00018b80();
    if (0 < *(int *)(iVar1 + 8)) {
      local_18[0] = 4;
      DAT_00027fdc = 1;
      if (DAT_00027984 - 1 < DAT_00027984) {
        piVar3 = *(int **)((DAT_00027984 - 1) * 4 + DAT_00027980);
      }
      else {
        piVar3 = (int *)0x0;
      }
      piVar2 = (int *)FUN_0001a998();
      FUN_000152fc(piVar3,piVar2,local_18,0,1,1);
    }
  }
  return 1;
}



/* 0001af1c FUN_0001af1c */

/* Boundary evidence: original MIPS .pdata 0001af1c..0001b037. Semantic name remains unreviewed. */

int FUN_0001af1c(int *param_1,HINSTANCE param_2,HWND param_3,undefined4 param_4,int param_5)

{
  WNDCLASSW *pWVar1;
  HWND pHVar2;
  int *piVar3;
  
  if (param_1[0x14] == 0) {
    param_1[0x12] = (int)param_2;
    pWVar1 = FUN_00016328(DAT_00027fd8,param_2,FUN_0001aa34);
    pHVar2 = CreateWindowExW(0x4000000,pWVar1->lpszClassName,pWVar1->lpszClassName,0x90000000,0,0,
                             800,0x1e0,param_3,(HMENU)0x0,param_2,(LPVOID)0x0);
    param_1[0x14] = (int)pHVar2;
    if (pHVar2 == (HWND)0x0) {
      GetLastError();
      return 0;
    }
    if ((DAT_00027984 - 1 < DAT_00027984) &&
       (piVar3 = *(int **)((DAT_00027984 - 1) * 4 + DAT_00027980), piVar3 != (int *)0x0)) {
      (**(code **)(*piVar3 + 0x60))();
    }
  }
  FUN_00014f98(param_1,param_4,param_5);
  return param_1[0x14];
}



/* 0001b038 FUN_0001b038 */

/* Boundary evidence: original MIPS .pdata 0001b038..0001b12f. Semantic name remains unreviewed. */

undefined4 * FUN_0001b038(undefined4 *param_1)

{
  FUN_000144c4(param_1);
  *param_1 = &PTR_FUN_00025d1c;
  FUN_000114f8(param_1 + 0xb2);
  FUN_000178fc(param_1 + 0x15d);
  FUN_000178fc(param_1 + 0x2b9);
  FUN_000178fc(param_1 + 0x415);
  FUN_000178fc(param_1 + 0x571);
  ___L_YAXPAXIHP6AX0_Z1_Z(param_1 + 0x6cd,0x570,10,FUN_000178fc,FUN_00017b3c);
  FUN_00017070(param_1 + 0x1465);
  FUN_000178fc(param_1 + 0x1482);
  param_1[0xb0] = 2;
  param_1[0x15e1] = 0;
  *(undefined2 *)(param_1 + 0x15de) = 0;
  *(undefined2 *)((int)param_1 + 0x577a) = 0;
  *(undefined2 *)(param_1 + 0x15df) = 0;
  *(undefined2 *)((int)param_1 + 0x577e) = 0;
  *(undefined2 *)(param_1 + 0x15e0) = 0;
  memset(param_1 + 0x15e2,0,4);
  return param_1;
}



/* 0001b130 Unwind@0001b130 */

/* Boundary evidence: original MIPS .pdata 0001b130..0001b15f. Semantic name remains unreviewed. */

void Unwind_0001b130(void)

{
  undefined4 *in_v0;
  
  FUN_00019fe4((int *)*in_v0);
  return;
}



/* 0001b160 Unwind@0001b160 */

/* Boundary evidence: original MIPS .pdata 0001b160..0001b193. Semantic name remains unreviewed. */

void Unwind_0001b160(void)

{
  int *in_v0;
  
  FUN_00012024((undefined4 *)(*in_v0 + 0x2c8));
  return;
}



/* 0001b194 Unwind@0001b194 */

/* Boundary evidence: original MIPS .pdata 0001b194..0001b1c7. Semantic name remains unreviewed. */

void Unwind_0001b194(void)

{
  int *in_v0;
  
  FUN_00017b3c((undefined4 *)(*in_v0 + 0x574));
  return;
}



/* 0001b1c8 Unwind@0001b1c8 */

/* Boundary evidence: original MIPS .pdata 0001b1c8..0001b1fb. Semantic name remains unreviewed. */

void Unwind_0001b1c8(void)

{
  int *in_v0;
  
  FUN_00017b3c((undefined4 *)(*in_v0 + 0xae4));
  return;
}



/* 0001b1fc Unwind@0001b1fc */

/* Boundary evidence: original MIPS .pdata 0001b1fc..0001b22f. Semantic name remains unreviewed. */

void Unwind_0001b1fc(void)

{
  int *in_v0;
  
  FUN_00017b3c((undefined4 *)(*in_v0 + 0x1054));
  return;
}



/* 0001b230 Unwind@0001b230 */

/* Boundary evidence: original MIPS .pdata 0001b230..0001b263. Semantic name remains unreviewed. */

void Unwind_0001b230(void)

{
  int *in_v0;
  
  FUN_00017b3c((undefined4 *)(*in_v0 + 0x15c4));
  return;
}



/* 0001b264 Unwind@0001b264 */

/* Boundary evidence: original MIPS .pdata 0001b264..0001b2a7. Semantic name remains unreviewed. */

void Unwind_0001b264(void)

{
  int *in_v0;
  
  ___M_YAXPAXIHP6AX0_Z_Z(*in_v0 + 0x1b34,0x570,10,FUN_00017b3c);
  return;
}



/* 0001b2a8 Unwind@0001b2a8 */

/* Boundary evidence: original MIPS .pdata 0001b2a8..0001b2db. Semantic name remains unreviewed. */

void Unwind_0001b2a8(void)

{
  int *in_v0;
  
  FUN_000178b4((undefined4 *)(*in_v0 + 0x5194));
  return;
}



/* 0001b2dc FUN_0001b2dc */

/* Boundary evidence: original MIPS .pdata 0001b2dc..0001b353. Semantic name remains unreviewed. */

bool FUN_0001b2dc(LPCWSTR param_1)

{
  DWORD DVar1;
  
  DAT_00027fe0 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,param_1);
  DVar1 = GetLastError();
  if (DVar1 == 0xb7) {
    CloseHandle(DAT_00027fe0);
    DAT_00027fe0 = (HANDLE)0x0;
  }
  return DVar1 != 0xb7;
}



/* 0001b354 FUN_0001b354 */

/* Boundary evidence: original MIPS .pdata 0001b354..0001b433. Semantic name remains unreviewed. */

void FUN_0001b354(void)

{
  int iVar1;
  
  iVar1 = FUN_00019448();
  if (iVar1 != 0) {
    FUN_00013ff4(iVar1,9,L"tahoma",0x1c,0,'\0','\0');
    FUN_00013ff4(iVar1,0xc,L"tahoma",0x20,0,'\0','\0');
    FUN_00013ff4(iVar1,0xd,L"tahoma",0x22,0,'\0','\0');
    FUN_00013ff4(iVar1,0x10,L"tahoma",0x28,0,'\0','\0');
    FUN_00013ff4(iVar1,0x15,L"tahoma",0x41,0,'\0','\0');
  }
  return;
}



/* 0001b434 FUN_0001b434 */

/* Boundary evidence: original MIPS .pdata 0001b434..0001b4d7. Semantic name remains unreviewed. */

bool FUN_0001b434(HINSTANCE param_1)

{
  HWND hWnd;
  
  DAT_00027fe4 = param_1;
  FUN_0001b354();
  hWnd = CreateWindowExW(0x4000000,L"CodeChecker",L"CodeChecker",0x92000000,0,0,800,0x1e0,(HWND)0x0,
                         (HMENU)0x0,param_1,(LPVOID)0x0);
  if (hWnd != (HWND)0x0) {
    ShowWindow(hWnd,1);
    UpdateWindow(hWnd);
  }
  return hWnd != (HWND)0x0;
}



/* 0001b4d8 FUN_0001b4d8 */

/* Boundary evidence: original MIPS .pdata 0001b4d8..0001b543. Semantic name remains unreviewed. */

void FUN_0001b4d8(void)

{
  undefined4 *puVar1;
  
  if (DAT_00027fd8 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x578c);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00027fd8 = (undefined4 *)0x0;
    }
    else {
      DAT_00027fd8 = FUN_0001b038(puVar1);
    }
  }
  return;
}



/* 0001b544 Unwind@0001b544 */

/* Boundary evidence: original MIPS .pdata 0001b544..0001b573. Semantic name remains unreviewed. */

void Unwind_0001b544(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0001b574 FUN_0001b574 */

/* Boundary evidence: original MIPS .pdata 0001b574..0001b6ff. Semantic name remains unreviewed. */

LRESULT FUN_0001b574(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  int iVar2;
  HWND hWnd;
  int iVar3;
  int *piVar4;
  uint lParam;
  
  if (param_2 == 1) {
    SetWindowPos(param_1,(HWND)0xffffffff,0,0,0,0,3);
    SetTimer(param_1,0x3eb,1000,(TIMERPROC)0x0);
    FUN_000162f8(DAT_00027fe4,(int)param_1);
    iVar2 = FUN_000110e4((HKEY)0x80000002,L"LGE\\SystemInfo",L"SYS_LANG_TYPE",0);
    iVar3 = FUN_00018e44();
    FUN_00018f78(iVar3,iVar2,0);
    piVar4 = (int *)FUN_0001b4d8();
    FUN_0001604c(piVar4,0,0);
  }
  else {
    if (param_2 != 2) {
      LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
      return LVar1;
    }
    iVar2 = FUN_00018b80();
    FUN_00018b8c(iVar2);
    hWnd = FindWindowW(L"MGRMCM",(LPCWSTR)0x0);
    if (hWnd != (HWND)0x0) {
      iVar2 = FUN_00018b80();
      lParam = (uint)(*(int *)(iVar2 + 8) == 0);
      NKDbgPrintfW(L"\r\n[CodeChecker] send IDM_X_MMCM_CODE_SUCCESS[%d]\r\n",lParam);
      PostMessageW(hWnd,0x8064,0xb40300,lParam);
    }
    if (DAT_00027fe0 != 0) {
      CloseHandle((HANDLE)DAT_00027fe0);
      DAT_00027fe0 = 0;
    }
    PostQuitMessage(0);
  }
  return 0;
}



/* 0001b700 FUN_0001b700 */

/* Boundary evidence: original MIPS .pdata 0001b700..0001b757. Semantic name remains unreviewed. */

void FUN_0001b700(HINSTANCE param_1)

{
  WNDCLASSW local_30;
  
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_0001b574;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hIcon = (HICON)0x0;
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hbrBackground = (HBRUSH)0x0;
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.lpszClassName = L"CodeChecker";
  local_30.hInstance = param_1;
  RegisterClassW(&local_30);
  return;
}



/* 0001b758 FUN_0001b758 */

/* Boundary evidence: original MIPS .pdata 0001b758..0001b83b. Semantic name remains unreviewed. */

undefined4 FUN_0001b758(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  BOOL BVar3;
  MSG MStack_30;
  
  bVar1 = FUN_0001b2dc(L"CodeChecker.exe");
  if (CONCAT31(extraout_var,bVar1) == 0) {
    NKDbgPrintfW(L"[CodeChecker] process is already running. Execution is ignored! \r\n");
  }
  else {
    NKDbgPrintfW(L"[CodeChecker] CodeChecker Execute! \r\n");
    FUN_0001b700(param_1);
    if (((param_3 != (wchar_t *)0x0) &&
        (iVar2 = wcsncmp(param_3,L"bd9r2a@_4G2g=J2tq7X@app",0x17), iVar2 == 0)) &&
       (bVar1 = FUN_0001b434(param_1), CONCAT31(extraout_var_00,bVar1) != 0)) {
      while (BVar3 = GetMessageW(&MStack_30,(HWND)0x0,0,0), BVar3 != 0) {
        TranslateMessage(&MStack_30);
        DispatchMessageW(&MStack_30);
      }
      return MStack_30.wParam;
    }
  }
  return 0;
}



/* 0001ba2c FUN_0001ba2c */

/* Boundary evidence: original MIPS .pdata 0001ba2c..0001ba9f. Semantic name remains unreviewed. */

void FUN_0001ba2c(void)

{
  uint uVar1;
  
  if ((DAT_00027974 == 0) || (DAT_00027974 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00027974 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00027974 == 0) {
      DAT_00027974 = 0xb064;
    }
  }
  DAT_00027978 = ~DAT_00027974;
  return;
}



/* 0001baa0 FUN_0001baa0 */

/* Boundary evidence: original MIPS .pdata 0001baa0..0001bb0f. Semantic name remains unreviewed. */

void FUN_0001baa0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0001bb58(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 0001bb10 FUN_0001bb10 */

/* Boundary evidence: original MIPS .pdata 0001bb10..0001bb57. Semantic name remains unreviewed. */

void FUN_0001bb10(uint param_1)

{
  if ((param_1 == DAT_00027974) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 0001bb58 FUN_0001bb58 */

/* Boundary evidence: original MIPS .pdata 0001bb58..0001bbab. Semantic name remains unreviewed. */

void FUN_0001bb58(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_0001bb10(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 0001bbac FUN_0001bbac */

/* Boundary evidence: original MIPS .pdata 0001bbac..0001bbd7. Semantic name remains unreviewed. */

undefined4 FUN_0001bbac(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0001bb58(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 0001bc68 FUN_0001bc68 */

/* Boundary evidence: original MIPS .pdata 0001bc68..0001bcfb. Semantic name remains unreviewed. */

void FUN_0001bc68(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  UINT UVar1;
  
  FUN_0001bfa8();
  UVar1 = FUN_0001b758(param_1,param_2,param_3);
  FUN_0001bee8(UVar1);
  FUN_0001bf08(UVar1);
  return;
}



/* 0001bcfc FUN_0001bcfc */

/* Boundary evidence: original MIPS .pdata 0001bcfc..0001bd3b. Semantic name remains unreviewed. */

void FUN_0001bcfc(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 0001bd3c entry */

/* Boundary evidence: original MIPS .pdata 0001bd3c..0001bd97. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  FUN_0001ba2c();
  FUN_0001bc68(param_1,param_2,param_3);
  return;
}



/* 0001bdc8 FUN_0001bdc8 */

/* Boundary evidence: original MIPS .pdata 0001bdc8..0001bee7. Semantic name remains unreviewed. */

void FUN_0001bdc8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00027fe8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00028558;
    if (DAT_00028558 != (undefined4 *)0x0) {
      while (DAT_00028554 = DAT_00028554 + -1, _Memory <= DAT_00028554) {
        if ((code *)*DAT_00028554 != (code *)0x0) {
          (*(code *)*DAT_00028554)();
          _Memory = DAT_00028558;
        }
      }
      free(_Memory);
      DAT_00028554 = (undefined4 *)0x0;
      DAT_00028558 = (undefined4 *)0x0;
    }
    FUN_0001bf54((undefined4 *)&DAT_0001d024,(undefined4 *)&DAT_0001d028);
  }
  FUN_0001bf54((undefined4 *)&DAT_0001d02c,(undefined4 *)&DAT_0001d030);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_0002855c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 0001bee8 FUN_0001bee8 */

/* Boundary evidence: original MIPS .pdata 0001bee8..0001bf07. Semantic name remains unreviewed. */

void FUN_0001bee8(UINT param_1)

{
  FUN_0001bdc8(param_1,0,0);
  return;
}



/* 0001bf08 FUN_0001bf08 */

/* Boundary evidence: original MIPS .pdata 0001bf08..0001bf53. Semantic name remains unreviewed. */

void FUN_0001bf08(UINT param_1)

{
  DAT_00027fe8 = 0;
  FUN_0001bf54((undefined4 *)&DAT_0001d02c,(undefined4 *)&DAT_0001d030);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 0001bf54 FUN_0001bf54 */

/* Boundary evidence: original MIPS .pdata 0001bf54..0001bfa7. Semantic name remains unreviewed. */

void FUN_0001bf54(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 0001bfa8 FUN_0001bfa8 */

/* Boundary evidence: original MIPS .pdata 0001bfa8..0001bfe3. Semantic name remains unreviewed. */

void FUN_0001bfa8(void)

{
  FUN_0001bf54((undefined4 *)&DAT_0001d01c,(undefined4 *)&DAT_0001d020);
  FUN_0001bf54((undefined4 *)&DAT_0001d000,(undefined4 *)&DAT_0001d018);
  return;
}



/* 0001bff4 FUN_0001bff4 */

/* Boundary evidence: original MIPS .pdata 0001bff4..0001c0ff. Semantic name remains unreviewed. */

undefined4 FUN_0001bff4(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_00028558;
  puVar3 = DAT_00028554;
  iVar4 = (int)DAT_00028554 - (int)DAT_00028558;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_0001c038:
    param_1 = 0;
  }
  else {
    if (DAT_00028558 != (void *)0x0) {
      uVar1 = _msize(DAT_00028558);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_0001c0ac:
        if (pvVar2 == (void *)0x0) goto LAB_0001c038;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_0001c0ac;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_00028554 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_00028558 = pvVar2;
  }
  return param_1;
}



/* 0001c100 FUN_0001c100 */

/* Boundary evidence: original MIPS .pdata 0001c100..0001c1eb. Semantic name remains unreviewed. */

undefined4 FUN_0001c100(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_0002855c == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_0002855c,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_0002855c == (LPCRITICAL_SECTION)0x0) goto LAB_0001c1a4;
  }
  EnterCriticalSection(DAT_0002855c);
LAB_0001c1a4:
  uVar2 = FUN_0001bff4(param_1);
  FUN_0001c1ec();
  return uVar2;
}



/* 0001c1ec FUN_0001c1ec */

/* Boundary evidence: original MIPS .pdata 0001c1ec..0001c237. Semantic name remains unreviewed. */

void FUN_0001c1ec(void)

{
  if (DAT_0002855c != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_0002855c);
  }
  return;
}



/* 0001c238 FUN_0001c238 */

/* Boundary evidence: original MIPS .pdata 0001c238..0001c267. Semantic name remains unreviewed. */

undefined4 FUN_0001c238(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0001c100(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0001c588 FUN_0001c588 */

/* Boundary evidence: original MIPS .pdata 0001c588..0001c5b3. Semantic name remains unreviewed. */

void FUN_0001c588(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0002853c);
  FUN_0001c238(FUN_0001c644);
  return;
}



/* 0001c5b4 FUN_0001c5b4 */

/* Boundary evidence: original MIPS .pdata 0001c5b4..0001c5d3. Semantic name remains unreviewed. */

void FUN_0001c5b4(void)

{
  FUN_0001c238(FUN_0001c664);
  return;
}



/* 0001c5d4 FUN_0001c5d4 */

/* Boundary evidence: original MIPS .pdata 0001c5d4..0001c5f7. Semantic name remains unreviewed. */

void FUN_0001c5d4(void)

{
  DAT_00027998 = FUN_00018d58();
  return;
}



/* 0001c5f8 FUN_0001c5f8 */

/* Boundary evidence: original MIPS .pdata 0001c5f8..0001c61f. Semantic name remains unreviewed. */

void FUN_0001c5f8(void)

{
  DAT_00027bc0 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0001c620 FUN_0001c620 */

/* Boundary evidence: original MIPS .pdata 0001c620..0001c643. Semantic name remains unreviewed. */

void FUN_0001c620(void)

{
  DAT_00027bc8 = FUN_00019448();
  return;
}



/* 0001c644 FUN_0001c644 */

/* Boundary evidence: original MIPS .pdata 0001c644..0001c663. Semantic name remains unreviewed. */

void FUN_0001c644(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0002853c);
  return;
}



/* 0001c664 FUN_0001c664 */

/* Boundary evidence: original MIPS .pdata 0001c664..0001c6c3. Semantic name remains unreviewed. */

void FUN_0001c664(void)

{
  if (DAT_00027980 != (HLOCAL)0x0) {
    LocalFree(DAT_00027980);
    DAT_00027980 = (HLOCAL)0x0;
    DAT_00027984 = 0;
    return;
  }
  DAT_00027984 = 0;
  return;
}


