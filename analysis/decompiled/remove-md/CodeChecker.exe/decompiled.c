/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

undefined4 * FUN_00011000(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *param_1 = &PTR_FUN_00020298;
  param_1[1] = 0;
  param_1[10] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0x824;
  param_1[0xc] = 0;
  *(undefined2 *)(param_1 + 0x11) = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0xb] = 0x181;
  return param_1;
}



/* 00011068 FUN_00011068 */

void FUN_00011068(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}



/* 00011070 FUN_00011070 */

int FUN_00011070(int param_1)

{
  return param_1 + 0x44;
}



/* 00011078 FUN_00011078 */

void FUN_00011078(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  return;
}



/* 00011080 FUN_00011080 */

undefined4 FUN_00011080(undefined4 param_1)

{
  DAT_000218c8 = param_1;
  return 1;
}



/* 00011090 FUN_00011090 */

/* Boundary evidence: original MIPS .pdata 00011090..0001113f. Semantic name remains unreviewed. */

void FUN_00011090(int *param_1,short *param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_2 != (short *)0x0) {
    piVar4 = param_1 + 0x11;
    iVar5 = 0x6e;
    bVar1 = FUN_00013878((short *)piVar4,0x6e,param_2);
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
      *(undefined2 *)(param_1 + 0x48) = 0;
      if (param_3 != 0) {
        FUN_00013984(param_1);
      }
    }
  }
  return;
}



/* 00011140 FUN_00011140 */

/* Boundary evidence: original MIPS .pdata 00011140..0001121b. Semantic name remains unreviewed. */

undefined4 FUN_00011140(ushort *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  wchar_t local_218;
  undefined1 auStack_216 [518];
  uint local_10;
  
  local_10 = DAT_00021450;
  local_218 = L'\0';
  memset(auStack_216,0,0x206);
  _snwprintf(&local_218,0x103,L"%s",param_1);
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
        FUN_0001ab10(local_10);
        return 1;
      }
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 1;
    } while (iVar3 < iVar4);
  }
  FUN_0001ab10(local_10);
  return 0;
}



/* 0001121c FUN_0001121c */

/* Boundary evidence: original MIPS .pdata 0001121c..00011317. Semantic name remains unreviewed. */

undefined4 FUN_0001121c(short *param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short local_260 [36];
  wchar_t local_218;
  undefined1 auStack_216 [518];
  uint local_10;
  
  local_10 = DAT_00021450;
  local_218 = L'\0';
  memset(auStack_216,0,0x206);
  _snwprintf(&local_218,0x103,L"%s",param_1);
  memcpy(local_260,&DAT_00020250,0x42);
  psVar2 = param_1;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  iVar5 = ((uint)((int)psVar2 - (int)param_1) >> 1) - 1;
  iVar4 = 0;
  if (0 < iVar5) {
    do {
      iVar3 = 0;
      psVar2 = local_260;
      do {
        if (*psVar2 == *param_1) {
          FUN_0001ab10(local_10);
          return 1;
        }
        iVar3 = iVar3 + 1;
        psVar2 = psVar2 + 1;
      } while (iVar3 < 0x20);
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar4 < iVar5);
  }
  FUN_0001ab10(local_10);
  return 0;
}



/* 00011318 FUN_00011318 */

/* Boundary evidence: original MIPS .pdata 00011318..0001136f. Semantic name remains unreviewed. */

void FUN_00011318(int *param_1)

{
  if (((param_1[0xb] & 0x80U) != 0) && (param_1[1] != 0)) {
    (**(code **)(*param_1 + 0x1c))(param_1);
    FUN_00016ff0(param_1[1],param_1 + 2);
  }
  return;
}



/* 00011370 FUN_00011370 */

/* Boundary evidence: original MIPS .pdata 00011370..00011393. Semantic name remains unreviewed. */

void FUN_00011370(int *param_1)

{
  (**(code **)(*param_1 + 0x34))();
  return;
}



/* 00011394 FUN_00011394 */

/* Boundary evidence: original MIPS .pdata 00011394..000115d3. Semantic name remains unreviewed. */

void FUN_00011394(int param_1)

{
  WCHAR WVar1;
  int y;
  int cy;
  HDC hdcSrc;
  int iVar2;
  LPCWSTR pWVar3;
  int iVar4;
  LPCWSTR lpchText;
  HDC hdc;
  int iVar5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  tagRECT local_30;
  
  local_40 = *(int *)(param_1 + 8);
  iVar5 = *(int *)(param_1 + 0x10);
  local_3c = *(int *)(param_1 + 0xc);
  local_34 = *(int *)(param_1 + 0x14);
  local_30.right = iVar5 + local_40;
  local_30.bottom = local_34 + local_3c;
  hdc = *(HDC *)(*(int *)(param_1 + 4) + 0x24);
  local_38 = iVar5;
  local_30.left = local_40;
  local_30.top = local_3c;
  if ((*(uint *)(param_1 + 0x2c) & 0x400) != 0) {
    FUN_00016e7c(*(int *)(param_1 + 4),&local_40);
  }
  cy = local_34;
  y = local_3c;
  iVar4 = local_40;
  iVar2 = *(int *)(param_1 + 0x3c);
  if (iVar2 != 0) {
    FUN_00016ab8(iVar2,*(uint *)(iVar2 + 0x30) & 0xff,(int *)(param_1 + 8));
  }
  if (*(HGDIOBJ *)(param_1 + 0x28) != (HGDIOBJ)0x0) {
    hdcSrc = (HDC)FUN_00016c18(*(HGDIOBJ *)(param_1 + 0x28));
    if ((*(uint *)(param_1 + 0x2c) & 0x200) == 0) {
      BitBlt(hdc,iVar4,y,iVar5,cy,hdcSrc,0,0,0xcc0020);
    }
    else {
      TransparentImage();
    }
    SelectObject((HDC)DAT_00022724->SpinCount,DAT_00022724[1].DebugInfo);
    LeaveCriticalSection(DAT_00022724);
  }
  SelectObject(hdc,*(HGDIOBJ *)(param_1 + 0x30));
  SetTextColor(hdc,*(COLORREF *)(param_1 + 0x34));
  lpchText = (LPCWSTR)(param_1 + 0x44);
  pWVar3 = lpchText;
  do {
    WVar1 = *pWVar3;
    pWVar3 = pWVar3 + 1;
  } while (WVar1 != L'\0');
  iVar4 = *(int *)(param_1 + 0x23c);
  iVar5 = -1;
  if ((0 < iVar4) && (iVar4 < (int)(((uint)((int)pWVar3 - (int)lpchText) >> 1) - 1))) {
    iVar5 = iVar4;
  }
  if ((lpchText == (LPCWSTR)0x0) ||
     ((iVar4 = FUN_0001121c(lpchText), iVar4 == 0 &&
      ((lpchText == (LPCWSTR)0x0 || (iVar4 = FUN_00011140((ushort *)lpchText), iVar4 == 0)))))) {
    DrawTextW(hdc,lpchText,iVar5,&local_30,*(UINT *)(param_1 + 0x38));
  }
  else {
    DrawTextW(hdc,lpchText,iVar5,&local_30,*(uint *)(param_1 + 0x38) | 0x20000);
  }
  return;
}



/* 000115d4 FUN_000115d4 */

void FUN_000115d4(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_00020454;
  return;
}



/* 000115e4 FUN_000115e4 */

/* Boundary evidence: original MIPS .pdata 000115e4..00011687. Semantic name remains unreviewed. */

undefined4 FUN_000115e4(uint param_1)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  ushort local_58 [34];
  uint local_14;
  
  local_14 = DAT_00021450;
  uVar3 = 0;
  memcpy(local_58,&DAT_00020250,0x42);
  if ((param_1 < 0x590) || (0x5ff < param_1)) {
    iVar2 = 0;
    puVar1 = local_58;
    do {
      if (*puVar1 == param_1) goto LAB_00011664;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < 0x20);
  }
  else {
LAB_00011664:
    uVar3 = 1;
  }
  FUN_0001ab10(local_14);
  return uVar3;
}



/* 00011688 FUN_00011688 */

/* Boundary evidence: original MIPS .pdata 00011688..00011757. Semantic name remains unreviewed. */

void FUN_00011688(HDC param_1,LPCWSTR param_2,int param_3,LPRECT param_4,UINT param_5)

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
      iVar2 = FUN_000115e4((uint)(ushort)*pWVar3);
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



/* 00011758 FUN_00011758 */

/* Boundary evidence: original MIPS .pdata 00011758..00012c93. Semantic name remains unreviewed. */

void FUN_00011758(int param_1)

{
  wchar_t wVar1;
  WCHAR WVar2;
  short sVar3;
  ushort uVar4;
  bool bVar5;
  HDC hdcSrc;
  wchar_t *pwVar6;
  int iVar7;
  int iVar8;
  wchar_t *pwVar9;
  uint uVar10;
  int iVar11;
  short *psVar12;
  LPCWSTR pWVar13;
  int iVar14;
  undefined2 *puVar15;
  int *piVar16;
  LPCWSTR lpchText;
  UINT format;
  HDC hdc;
  wchar_t *_Str;
  ushort *puVar17;
  LPCWSTR pWVar18;
  int cchText;
  int iVar19;
  tagRECT local_e8;
  tagSIZE local_d8;
  int local_d0;
  tagSIZE local_c8;
  LPCWSTR local_c0;
  ushort *local_bc;
  int local_b8;
  tagSIZE local_b0;
  tagRECT local_a8;
  tagSIZE local_98;
  uint local_90;
  int local_8c;
  tagSIZE local_88;
  int local_80;
  int local_7c;
  tagSIZE local_78;
  tagSIZE local_70;
  tagSIZE local_68;
  int local_60;
  int local_5c;
  LPCWSTR local_58;
  ushort *local_54;
  int local_50;
  tagRECT local_48;
  tagSIZE local_38;
  uint local_30;
  
  local_30 = DAT_00021450;
  iVar7 = *(int *)(param_1 + 4);
  if (iVar7 == 0) goto LAB_00012c60;
  piVar16 = (int *)(param_1 + 8);
  pWVar13 = *(LPCWSTR *)(param_1 + 0x10);
  local_a8.left = *piVar16;
  local_a8.top = *(int *)(param_1 + 0xc);
  local_bc = *(ushort **)(param_1 + 0x14);
  local_a8.right = (int)pWVar13 + local_a8.left;
  local_a8.bottom = (int)local_bc + local_a8.top;
  hdc = *(HDC *)(iVar7 + 0x24);
  local_60 = local_a8.left;
  local_5c = local_a8.top;
  local_58 = pWVar13;
  local_54 = local_bc;
  if ((*(uint *)(param_1 + 0x2c) & 0x400) != 0) {
    local_c0 = pWVar13;
    FUN_00016e7c(iVar7,&local_60);
  }
  puVar17 = local_54;
  iVar14 = local_5c;
  iVar7 = local_60;
  iVar8 = *(int *)(param_1 + 0x3c);
  local_c0 = local_58;
  local_bc = local_54;
  if (iVar8 != 0) {
    FUN_00016ab8(iVar8,*(uint *)(iVar8 + 0x30) & 0xff,piVar16);
  }
  if (*(HGDIOBJ *)(param_1 + 0x28) != (HGDIOBJ)0x0) {
    hdcSrc = (HDC)FUN_00016c18(*(HGDIOBJ *)(param_1 + 0x28));
    if ((*(uint *)(param_1 + 0x2c) & 0x200) == 0) {
      BitBlt(hdc,iVar7,iVar14,(int)pWVar13,(int)puVar17,hdcSrc,0,0,0xcc0020);
    }
    else {
      TransparentImage();
    }
    SelectObject((HDC)DAT_00022724->SpinCount,DAT_00022724[1].DebugInfo);
    LeaveCriticalSection(DAT_00022724);
  }
  SelectObject(hdc,*(HGDIOBJ *)(param_1 + 0x30));
  SetTextColor(hdc,*(COLORREF *)(param_1 + 0x34));
  _Str = (wchar_t *)(param_1 + 0x44);
  pwVar6 = wcsstr(_Str,(wchar_t *)(param_1 + 0x248));
  iVar8 = -1;
  local_d0 = -1;
  pwVar9 = _Str;
  if (pwVar6 != (wchar_t *)0x0) {
    local_d0 = (int)pwVar6 + (-0x44 - param_1) >> 1;
  }
  do {
    wVar1 = *pwVar9;
    pwVar9 = pwVar9 + 1;
  } while (wVar1 != L'\0');
  local_b8 = ((uint)((int)pwVar9 - (int)_Str) >> 1) - 1;
  iVar11 = *(int *)(param_1 + 0x23c);
  iVar19 = local_b8;
  if ((0 < iVar11) && (iVar11 < local_b8)) {
    iVar19 = iVar11;
  }
  if ((*(short *)(param_1 + 0x248) == 0) || (local_d0 == -1)) {
    if (*(int *)(param_1 + 0x40) != 0) {
      local_48.right = (int)local_c0 + iVar7;
      local_48.bottom = (int)local_bc + iVar14;
      local_48.left = iVar7;
      local_48.top = iVar14;
      DrawTextW(hdc,_Str,iVar19,&local_48,*(uint *)(param_1 + 0x38) | 0x400);
      iVar7 = ((local_48.top - local_48.bottom) - local_a8.top) + local_a8.bottom;
      if (iVar7 < 0) {
        iVar7 = iVar7 + 1;
      }
      local_a8.top = (iVar7 >> 1) + local_a8.top;
      local_a8.bottom = local_a8.bottom - (iVar7 >> 1);
    }
    local_98.cx = 0;
    local_98.cy = 0;
    if ((_Str == (wchar_t *)0x0) ||
       ((iVar7 = FUN_0001121c(_Str), iVar7 == 0 &&
        ((_Str == (wchar_t *)0x0 || (iVar7 = FUN_00011140((ushort *)_Str), iVar7 == 0)))))) {
      DrawTextW(hdc,_Str,iVar19,&local_a8,*(UINT *)(param_1 + 0x38));
    }
    else {
      DrawTextW(hdc,_Str,iVar19,&local_a8,*(uint *)(param_1 + 0x38) | 0x20000);
    }
    GetTextExtentExPointW(hdc,_Str,iVar19,0,(LPINT)0x0,(LPINT)0x0,&local_98);
    if (*(int *)(param_1 + 0x328) != 0) {
      local_a8.left = local_98.cx + local_a8.left;
      SetTextColor(hdc,*(COLORREF *)(param_1 + 0x34));
      pWVar18 = (LPCWSTR)(param_1 + 0x330);
      pWVar13 = pWVar18;
      do {
        WVar2 = *pWVar13;
        pWVar13 = pWVar13 + 1;
      } while (WVar2 != L'\0');
      DrawTextW(hdc,pWVar18,((uint)((int)pWVar13 - (int)pWVar18) >> 1) - 1,&local_a8,
                *(UINT *)(param_1 + 0x38));
    }
    goto LAB_00012c60;
  }
  local_70.cx = 0;
  pWVar18 = (LPCWSTR)(param_1 + 0x248);
  local_70.cy = 0;
  local_78.cx = 0;
  local_78.cy = 0;
  local_68.cx = 0;
  local_68.cy = 0;
  pWVar13 = pWVar18;
  do {
    WVar2 = *pWVar13;
    pWVar13 = pWVar13 + 1;
  } while (WVar2 != L'\0');
  uVar10 = (uint)((int)pWVar13 - (int)pWVar18) >> 1;
  iVar7 = uVar10 - 1;
  local_90 = (uint)(local_d0 == 0);
  local_e8.left = *piVar16;
  local_e8.top = *(LONG *)(param_1 + 0xc);
  local_e8.bottom = *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc);
  local_e8.right = *(int *)(param_1 + 0x10) + local_e8.left;
  if (*(int *)(param_1 + 0x240) == 0) {
    GetTextExtentExPointW(hdc,_Str,local_d0,0,(LPINT)0x0,(LPINT)0x0,&local_70);
    GetTextExtentExPointW(hdc,pWVar18,iVar7,0,(LPINT)0x0,(LPINT)0x0,&local_78);
    iVar14 = local_d0;
    pwVar9 = _Str;
    do {
      wVar1 = *pwVar9;
      pwVar9 = pwVar9 + 1;
    } while (wVar1 != L'\0');
    pWVar13 = (LPCWSTR)((iVar7 + local_d0 + 0x22) * 2 + param_1);
    GetTextExtentExPointW
              (hdc,pWVar13,((((uint)((int)pwVar9 - (int)_Str) >> 1) - 1) - iVar7) - local_d0,0,
               (LPINT)0x0,(LPINT)0x0,&local_68);
    local_e8.right = local_e8.left + local_70.cx;
    if ((_Str == (wchar_t *)0x0) ||
       ((iVar8 = FUN_0001121c(_Str), iVar8 == 0 &&
        ((_Str == (wchar_t *)0x0 || (iVar8 = FUN_00011140((ushort *)_Str), iVar8 == 0)))))) {
      DrawTextW(hdc,_Str,iVar14,&local_e8,*(UINT *)(param_1 + 0x38));
    }
    else {
      DrawTextW(hdc,_Str,iVar14,&local_e8,*(uint *)(param_1 + 0x38) | 0x20000);
    }
    local_e8.left = local_e8.right;
    local_e8.right = local_e8.right + local_78.cx;
    SetTextColor(hdc,*(COLORREF *)(param_1 + 0x244));
    if ((_Str == (wchar_t *)0x0) ||
       ((iVar14 = FUN_0001121c(_Str), iVar14 == 0 &&
        ((_Str == (wchar_t *)0x0 || (iVar14 = FUN_00011140((ushort *)_Str), iVar14 == 0)))))) {
      DrawTextW(hdc,pWVar18,iVar7,&local_e8,*(UINT *)(param_1 + 0x38));
    }
    else {
      DrawTextW(hdc,pWVar18,iVar7,&local_e8,*(uint *)(param_1 + 0x38) | 0x20000);
    }
    local_e8.left = local_e8.right;
    local_e8.right = local_e8.right + local_68.cx;
    SetTextColor(hdc,*(COLORREF *)(param_1 + 0x34));
    if ((_Str == (wchar_t *)0x0) ||
       ((iVar7 = FUN_0001121c(_Str), iVar7 == 0 &&
        ((_Str == (wchar_t *)0x0 || (iVar7 = FUN_00011140((ushort *)_Str), iVar7 == 0)))))) {
      DrawTextW(hdc,pWVar13,-1,&local_e8,*(UINT *)(param_1 + 0x38));
    }
    else {
      DrawTextW(hdc,pWVar13,-1,&local_e8,*(uint *)(param_1 + 0x38) | 0x20000);
    }
    goto LAB_00012c60;
  }
  local_8c = 1;
  local_7c = 0;
  local_80 = -1;
  if (*(short *)((uVar10 + 0x122) * 2 + param_1) == 0x20) {
    iVar7 = uVar10 - 2;
    puVar15 = (undefined2 *)((uVar10 + 0x122) * 2 + param_1);
    iVar14 = uVar10 - 3;
    *puVar15 = 0;
    if (0 < iVar14) {
      psVar12 = (short *)((uVar10 + 0x121) * 2 + param_1);
      do {
        if (*psVar12 != 0x20) break;
        puVar15 = puVar15 + -1;
        *puVar15 = 0;
        iVar7 = iVar7 + -1;
        iVar14 = iVar14 + -1;
        psVar12 = psVar12 + -1;
      } while (0 < iVar14);
    }
  }
  local_bc = (ushort *)((iVar7 + 0x123) * 2 + param_1);
  local_50 = FUN_000115e4((uint)*local_bc);
  local_98.cx = FUN_000115e4((uint)(ushort)*pWVar18);
  iVar14 = 0;
  iVar19 = 0;
  if (0 < iVar7) {
    do {
      if (iVar14 == 0) {
        iVar14 = FUN_000115e4((uint)(ushort)*pWVar18);
        if (iVar14 == 0) {
LAB_00011b5c:
          local_8c = 0;
        }
        else {
          local_7c = 1;
          local_80 = iVar19;
        }
      }
      else {
        uVar10 = (uint)(ushort)*pWVar18;
        iVar14 = FUN_000115e4(uVar10);
        if (iVar14 == 0) {
          if ((((uVar10 < 0x20) || (0x2f < uVar10)) && ((uVar10 < 0x3a || (0x40 < uVar10)))) &&
             ((uVar10 < 0x7b || (0x7d < uVar10)))) {
            iVar14 = 0;
            goto LAB_00011b5c;
          }
          local_7c = 1;
          iVar14 = 1;
          local_80 = iVar19;
        }
        else {
          local_7c = 1;
          iVar14 = 1;
          local_80 = iVar19;
        }
      }
      iVar19 = iVar19 + 1;
      pWVar18 = pWVar18 + 1;
    } while (iVar19 < iVar7);
  }
  pWVar13 = (LPCWSTR)(param_1 + 0x248);
  GetTextExtentExPointW(hdc,_Str,local_d0,0,(LPINT)0x0,(LPINT)0x0,&local_70);
  GetTextExtentExPointW(hdc,pWVar13,iVar7,0,(LPINT)0x0,(LPINT)0x0,&local_78);
  pwVar9 = _Str;
  do {
    wVar1 = *pwVar9;
    pwVar9 = pwVar9 + 1;
  } while (wVar1 != L'\0');
  iVar14 = iVar7 + local_d0;
  pWVar18 = (LPCWSTR)((iVar14 + 0x22) * 2 + param_1);
  local_c0 = pWVar18;
  GetTextExtentExPointW
            (hdc,pWVar18,((((uint)((int)pwVar9 - (int)_Str) >> 1) - 1) - iVar7) - local_d0,0,
             (LPINT)0x0,(LPINT)0x0,&local_68);
  local_38.cx = 0;
  local_38.cy = 0;
  local_88.cx = 0;
  local_88.cy = 0;
  pwVar9 = _Str;
  do {
    wVar1 = *pwVar9;
    pwVar9 = pwVar9 + 1;
  } while (wVar1 != L'\0');
  GetTextExtentExPointW
            (hdc,_Str,((uint)((int)pwVar9 - (int)_Str) >> 1) - 1,0,(LPINT)0x0,(LPINT)0x0,&local_38);
  GetTextExtentExPointW(hdc,L" ",1,0,(LPINT)0x0,(LPINT)0x0,&local_88);
  if ((_Str == (wchar_t *)0x0) ||
     ((iVar19 = FUN_00011140((ushort *)_Str), iVar19 == 0 &&
      ((_Str == (wchar_t *)0x0 || (iVar19 = FUN_0001121c(_Str), iVar19 == 0)))))) {
    iVar14 = local_d0;
    format = *(UINT *)(param_1 + 0x38);
    local_c8.cx = 0;
    local_c8.cy = 0;
    DrawTextW(hdc,_Str,local_d0,&local_e8,format);
    GetTextExtentExPointW(hdc,_Str,iVar14,0,(LPINT)0x0,(LPINT)0x0,&local_c8);
    local_e8.left = local_c8.cx + local_e8.left;
    SetTextColor(hdc,*(COLORREF *)(param_1 + 0x244));
    DrawTextW(hdc,pWVar13,iVar7,&local_e8,format);
    GetTextExtentExPointW(hdc,pWVar13,iVar7,0,(LPINT)0x0,(LPINT)0x0,&local_c8);
    local_e8.left = local_c8.cx + local_e8.left;
    SetTextColor(hdc,*(COLORREF *)(param_1 + 0x34));
    DrawTextW(hdc,pWVar18,-1,&local_e8,format);
    pWVar13 = pWVar18;
    do {
      WVar2 = *pWVar13;
      pWVar13 = pWVar13 + 1;
    } while (WVar2 != L'\0');
    GetTextExtentExPointW
              (hdc,pWVar18,((uint)((int)pWVar13 - (int)pWVar18) >> 1) - 1,0,(LPINT)0x0,(LPINT)0x0,
               &local_c8);
    if (*(int *)(param_1 + 0x328) != 0) {
      local_e8.left = local_88.cx + local_c8.cx + local_e8.left;
      SetTextColor(hdc,*(COLORREF *)(param_1 + 0x34));
      pWVar18 = (LPCWSTR)(param_1 + 0x330);
      pWVar13 = pWVar18;
      do {
        WVar2 = *pWVar13;
        pWVar13 = pWVar13 + 1;
      } while (WVar2 != L'\0');
      DrawTextW(hdc,pWVar18,((uint)((int)pWVar13 - (int)pWVar18) >> 1) - 1,&local_e8,format);
    }
    goto LAB_00012c60;
  }
  iVar11 = local_b8;
  iVar19 = local_d0;
  local_d8.cx = 0;
  local_d8.cy = 0;
  uVar10 = *(uint *)(param_1 + 0x38) | 0x20000;
  local_c8.cx = uVar10;
  if ((local_90 == 0) || (iVar7 < 1)) {
    local_b0.cx = 0;
    local_b0.cy = 0;
    DrawTextW(hdc,_Str,local_d0,&local_e8,uVar10);
    GetTextExtentExPointW(hdc,_Str,iVar19,0,(LPINT)0x0,(LPINT)0x0,&local_b0);
    local_e8.left = local_b0.cx + local_e8.left;
    SetTextColor(hdc,*(COLORREF *)(param_1 + 0x244));
    DrawTextW(hdc,pWVar13,iVar7,&local_e8,uVar10);
    GetTextExtentExPointW(hdc,pWVar13,iVar7,0,(LPINT)0x0,(LPINT)0x0,&local_b0);
    local_e8.left = local_b0.cx + local_e8.left;
    SetTextColor(hdc,*(COLORREF *)(param_1 + 0x34));
    DrawTextW(hdc,pWVar18,-1,&local_e8,uVar10);
    pWVar13 = pWVar18;
    do {
      WVar2 = *pWVar13;
      pWVar13 = pWVar13 + 1;
    } while (WVar2 != L'\0');
    GetTextExtentExPointW
              (hdc,pWVar18,((uint)((int)pWVar13 - (int)pWVar18) >> 1) - 1,0,(LPINT)0x0,(LPINT)0x0,
               &local_b0);
    iVar7 = local_b0.cx + local_e8.left;
  }
  else if (local_50 == 0) {
    if (local_98.cx == 0) {
      if (local_7c == 0) {
        cchText = -1;
        iVar19 = 0;
        if (0 < iVar7) {
          puVar17 = (ushort *)(param_1 + 0x248);
          do {
            if (0x40 < *puVar17) break;
            if (*puVar17 == 0x20) {
              cchText = iVar19 + 1;
            }
            iVar19 = iVar19 + 1;
            puVar17 = puVar17 + 1;
          } while (iVar19 < iVar7);
        }
        if (iVar14 < local_b8) {
          puVar17 = (ushort *)((iVar14 + 0x22) * 2 + param_1);
          do {
            iVar19 = FUN_000115e4((uint)*puVar17);
            if (iVar19 != 0) {
              if (0x40 < *(ushort *)(param_1 + 0x248)) {
                psVar12 = (short *)((iVar14 + 0x21) * 2 + param_1);
                sVar3 = *psVar12;
                while (sVar3 == 0x20) {
                  psVar12 = psVar12 + -1;
                  iVar14 = iVar14 + -1;
                  sVar3 = *psVar12;
                }
                goto LAB_00012368;
              }
              if (-1 < cchText) {
                if (iVar7 != iVar14) {
                  psVar12 = (short *)((iVar14 + 0x21) * 2 + param_1);
                  sVar3 = *psVar12;
                  while (sVar3 == 0x20) {
                    psVar12 = psVar12 + -1;
                    iVar14 = iVar14 + -1;
                    sVar3 = *psVar12;
                  }
                }
                goto LAB_00012368;
              }
              if (iVar14 <= iVar7) goto LAB_00012368;
              puVar17 = (ushort *)((iVar7 + 0x22) * 2 + param_1);
              iVar8 = iVar7;
              goto LAB_000122c8;
            }
            iVar14 = iVar14 + 1;
            puVar17 = puVar17 + 1;
          } while (iVar14 < iVar11);
        }
        goto LAB_00012154;
      }
    }
    else if (local_8c != 0) goto LAB_00011d2c;
    bVar5 = false;
    iVar19 = -1;
    if (iVar14 < local_b8) {
      puVar17 = (ushort *)((iVar14 + 0x22) * 2 + param_1);
LAB_00011e4c:
      iVar11 = FUN_000115e4((uint)*puVar17);
      if (iVar11 == 0) goto code_r0x00011e5c;
      psVar12 = (short *)((iVar14 + 0x21) * 2 + param_1);
      bVar5 = true;
      sVar3 = *psVar12;
      iVar19 = iVar14;
      while (sVar3 == 0x20) {
        psVar12 = psVar12 + -1;
        iVar19 = iVar19 + -1;
        sVar3 = *psVar12;
      }
      pWVar18 = (LPCWSTR)((iVar19 + 0x22) * 2 + param_1);
      FUN_00011688(hdc,pWVar18,-1,&local_e8,*(UINT *)(param_1 + 0x38));
      pWVar13 = pWVar18;
      do {
        WVar2 = *pWVar13;
        pWVar13 = pWVar13 + 1;
      } while (WVar2 != L'\0');
      GetTextExtentExPointW
                (hdc,pWVar18,((uint)((int)pWVar13 - (int)pWVar18) >> 1) - 1,0,(LPINT)0x0,(LPINT)0x0,
                 &local_d8);
      local_e8.left = local_d8.cx + local_e8.left;
    }
LAB_00011e74:
    if (-1 < local_80) {
      psVar12 = (short *)((local_80 + 0x125) * 2 + param_1);
      sVar3 = *psVar12;
      iVar14 = local_80;
      while (iVar8 = iVar14 + 1, sVar3 == 0x20) {
        psVar12 = psVar12 + 1;
        iVar14 = iVar8;
        sVar3 = *psVar12;
      }
      if (-1 < iVar8) {
        if (*local_bc == 0x20) {
          iVar11 = (iVar7 - iVar8) + -1;
        }
        else {
          iVar11 = iVar7 - iVar8;
        }
        SetTextColor(hdc,*(COLORREF *)(param_1 + 0x244));
        pWVar13 = (LPCWSTR)((iVar14 + 0x125) * 2 + param_1);
        FUN_00011688(hdc,pWVar13,iVar11,&local_e8,*(UINT *)(param_1 + 0x38));
        GetTextExtentExPointW(hdc,pWVar13,iVar11,0,(LPINT)0x0,(LPINT)0x0,&local_d8);
        local_e8.left = local_d8.cx + local_e8.left;
      }
    }
    if (!bVar5) {
      iVar19 = local_b8;
    }
    iVar19 = iVar19 - iVar7;
    if (0 < iVar19) {
      SetTextColor(hdc,*(COLORREF *)(param_1 + 0x34));
      pWVar13 = (LPCWSTR)((iVar7 + 0x22) * 2 + param_1);
      FUN_00011688(hdc,pWVar13,iVar19,&local_e8,*(UINT *)(param_1 + 0x38));
      GetTextExtentExPointW(hdc,pWVar13,iVar19,0,(LPINT)0x0,(LPINT)0x0,&local_d8);
      local_e8.left = local_d8.cx + local_e8.left;
    }
    SetTextColor(hdc,*(COLORREF *)(param_1 + 0x244));
    DrawTextW(hdc,(LPCWSTR)(param_1 + 0x248),iVar8,&local_e8,local_c8.cx);
    GetTextExtentExPointW(hdc,(LPCWSTR)(param_1 + 0x248),iVar8,0,(LPINT)0x0,(LPINT)0x0,&local_d8);
    iVar7 = local_d8.cx + local_e8.left;
    uVar10 = local_c8.cx;
  }
  else {
LAB_00011d2c:
    lpchText = (LPCWSTR)((iVar7 + 0x22) * 2 + param_1);
    DrawTextW(hdc,lpchText,-1,&local_e8,uVar10);
    pWVar18 = lpchText;
    do {
      WVar2 = *pWVar18;
      pWVar18 = pWVar18 + 1;
    } while (WVar2 != L'\0');
    GetTextExtentExPointW
              (hdc,lpchText,((uint)((int)pWVar18 - (int)lpchText) >> 1) - 1,0,(LPINT)0x0,(LPINT)0x0,
               &local_d8);
    local_e8.left = local_d8.cx + local_e8.left;
    SetTextColor(hdc,*(COLORREF *)(param_1 + 0x244));
    DrawTextW(hdc,pWVar13,iVar7,&local_e8,uVar10);
    GetTextExtentExPointW(hdc,pWVar13,iVar7,0,(LPINT)0x0,(LPINT)0x0,&local_d8);
    iVar7 = local_d8.cx + local_e8.left;
  }
  goto LAB_00012694;
code_r0x00011e5c:
  iVar14 = iVar14 + 1;
  puVar17 = puVar17 + 1;
  if (local_b8 <= iVar14) goto LAB_00011e74;
  goto LAB_00011e4c;
  while( true ) {
    if ((((0x1f < uVar4) && (uVar4 < 0x30)) || (0x39 < uVar4)) || ((0x7a < uVar4 && (uVar4 < 0x7e)))
       ) {
      iVar14 = iVar8;
    }
    iVar8 = iVar8 + 1;
    puVar17 = puVar17 + 1;
    if (iVar14 <= iVar8) break;
LAB_000122c8:
    uVar4 = *puVar17;
    if (0x40 < uVar4) break;
  }
LAB_00012368:
  iVar8 = iVar14;
  if (0 < iVar14) {
    pWVar18 = (LPCWSTR)((iVar14 + 0x22) * 2 + param_1);
    FUN_00011688(hdc,pWVar18,-1,&local_e8,*(UINT *)(param_1 + 0x38));
    pWVar13 = pWVar18;
    do {
      WVar2 = *pWVar13;
      pWVar13 = pWVar13 + 1;
    } while (WVar2 != L'\0');
    GetTextExtentExPointW
              (hdc,pWVar18,((uint)((int)pWVar13 - (int)pWVar18) >> 1) - 1,0,(LPINT)0x0,(LPINT)0x0,
               &local_d8);
    local_e8.left = local_d8.cx + local_e8.left;
  }
LAB_00012154:
  pWVar13 = (LPCWSTR)(param_1 + 0x248);
  iVar14 = iVar7;
  if (*local_bc == 0x20) {
    iVar14 = iVar7 + -1;
  }
  SetTextColor(hdc,*(COLORREF *)(param_1 + 0x244));
  if (cchText < 1) {
    if ((ushort)*pWVar13 < 0x41) {
      DrawTextW(hdc,pWVar13,iVar14,&local_e8,local_c8.cx);
    }
    else {
      FUN_00011688(hdc,pWVar13,iVar14,&local_e8,*(UINT *)(param_1 + 0x38));
    }
    GetTextExtentExPointW(hdc,pWVar13,iVar14,0,(LPINT)0x0,(LPINT)0x0,&local_d8);
    local_e8.left = local_d8.cx + local_e8.left;
  }
  else {
    iVar14 = iVar14 - cchText;
    if (0 < iVar14) {
      pWVar13 = (LPCWSTR)((cchText + 0x124) * 2 + param_1);
      FUN_00011688(hdc,pWVar13,iVar14,&local_e8,*(UINT *)(param_1 + 0x38));
      GetTextExtentExPointW(hdc,pWVar13,iVar14,0,(LPINT)0x0,(LPINT)0x0,&local_d8);
      local_e8.left = local_d8.cx + local_e8.left;
    }
  }
  SetTextColor(hdc,*(COLORREF *)(param_1 + 0x34));
  pWVar13 = local_c0;
  if (iVar8 < 0) {
    FUN_00011688(hdc,local_c0,-1,&local_e8,*(UINT *)(param_1 + 0x38));
    pWVar18 = pWVar13;
    do {
      WVar2 = *pWVar18;
      pWVar18 = pWVar18 + 1;
    } while (WVar2 != L'\0');
    GetTextExtentExPointW
              (hdc,pWVar13,((uint)((int)pWVar18 - (int)pWVar13) >> 1) - 1,0,(LPINT)0x0,(LPINT)0x0,
               &local_d8);
LAB_000124c4:
    local_e8.left = local_d8.cx + local_e8.left;
  }
  else {
    iVar7 = (iVar8 - iVar7) - local_d0;
    if (0 < iVar7) {
      FUN_00011688(hdc,local_c0,iVar7,&local_e8,*(UINT *)(param_1 + 0x38));
      GetTextExtentExPointW(hdc,pWVar13,iVar7,0,(LPINT)0x0,(LPINT)0x0,&local_d8);
      goto LAB_000124c4;
    }
  }
  SetTextColor(hdc,*(COLORREF *)(param_1 + 0x244));
  uVar10 = local_c8.cx;
  iVar7 = local_e8.left;
  if (0 < cchText) {
    if (*(short *)((cchText + 0x22) * 2 + param_1) == 0x20) {
      local_e8.left = local_88.cx + local_e8.left;
    }
    DrawTextW(hdc,(LPCWSTR)(param_1 + 0x248),cchText,&local_e8,local_c8.cx);
    GetTextExtentExPointW(hdc,(LPCWSTR)(param_1 + 0x248),cchText,0,(LPINT)0x0,(LPINT)0x0,&local_d8);
    iVar7 = local_d8.cx + local_e8.left;
  }
LAB_00012694:
  if (*(int *)(param_1 + 0x328) != 0) {
    local_e8.left = local_88.cx + iVar7;
    SetTextColor(hdc,*(COLORREF *)(param_1 + 0x34));
    pWVar18 = (LPCWSTR)(param_1 + 0x330);
    pWVar13 = pWVar18;
    do {
      WVar2 = *pWVar13;
      pWVar13 = pWVar13 + 1;
    } while (WVar2 != L'\0');
    DrawTextW(hdc,pWVar18,((uint)((int)pWVar13 - (int)pWVar18) >> 1) - 1,&local_e8,uVar10);
  }
LAB_00012c60:
  FUN_0001ab10(local_30);
  return;
}



/* 00012c94 FUN_00012c94 */

/* Boundary evidence: original MIPS .pdata 00012c94..00012d17. Semantic name remains unreviewed. */

undefined4 * FUN_00012c94(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0002044c;
  param_1[1] = 0;
  param_1[0x136] = 0;
  param_1[0x137] = 0;
  memset(param_1 + 2,0,0x60);
  memset(param_1 + 0x1a,0,0x60);
  FUN_000133e0((int)param_1);
  param_1[0x138] = 0;
  param_1[0x13d] = 0;
  param_1[0x139] = 0;
  param_1[0x13a] = 0;
  param_1[0x13b] = 0;
  param_1[0x13c] = 0;
  FUN_000135a0((int)param_1);
  return param_1;
}



/* 00012d18 FUN_00012d18 */

/* Boundary evidence: original MIPS .pdata 00012d18..00012d6b. Semantic name remains unreviewed. */

void FUN_00012d18(undefined4 *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_00021690;
  bVar1 = DAT_00021690 != (undefined4 *)0x0;
  *param_1 = &PTR_LAB_0002044c;
  if (bVar1) {
    FUN_00012d18(puVar2);
    __3_YAXPAX_Z(puVar2);
    DAT_00021690 = (undefined4 *)0x0;
  }
  return;
}



/* 00012d6c FUN_00012d6c */

void FUN_00012d6c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x4dc) = param_2;
  return;
}



/* 00012d74 FUN_00012d74 */

/* Boundary evidence: original MIPS .pdata 00012d74..00012dcb. Semantic name remains unreviewed. */

void FUN_00012d74(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00021690;
  if (DAT_00021690 != (undefined4 *)0x0) {
    *DAT_00021690 = &PTR_LAB_0002044c;
    FUN_00012d74();
    __3_YAXPAX_Z(puVar1);
    DAT_00021690 = (undefined4 *)0x0;
  }
  return;
}



/* 00012dcc FUN_00012dcc */

undefined4 FUN_00012dcc(int param_1,int param_2)

{
  if ((param_2 < 0x18) && (*(int *)(param_1 + 4) != 0)) {
    return *(undefined4 *)((param_2 + 2) * 4 + param_1);
  }
  return 0;
}



/* 00012e04 FUN_00012e04 */

/* Boundary evidence: original MIPS .pdata 00012e04..00012f2b. Semantic name remains unreviewed. */

undefined4
FUN_00012e04(int param_1,int param_2,LPCWSTR param_3,LONG param_4,int param_5,BYTE param_6,
            BYTE param_7)

{
  undefined4 uVar1;
  HFONT pHVar2;
  int *piVar3;
  LOGFONTW local_78;
  uint local_1c;
  
  local_1c = DAT_00021450;
  if ((param_2 < 0x18) && (piVar3 = (int *)((param_2 + 2) * 4 + param_1), *piVar3 == 0)) {
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
    local_78.lfUnderline = param_7;
    local_78.lfOutPrecision = '\x01';
    local_78.lfWidth = 0;
    *(LONG *)((param_2 + 0x1a) * 4 + param_1) = param_4;
    local_78.lfHeight = param_4;
    pHVar2 = CreateFontIndirectW(&local_78);
    *piVar3 = (int)pHVar2;
    *(undefined4 *)(param_1 + 4) = 1;
    FUN_0001ab10(local_1c);
    uVar1 = 1;
  }
  else {
    FUN_0001ab10(DAT_00021450);
    uVar1 = 0;
  }
  return uVar1;
}



/* 00012f2c FUN_00012f2c */

/* Boundary evidence: original MIPS .pdata 00012f2c..000130b7. Semantic name remains unreviewed. */

int FUN_00012f2c(undefined4 *param_1,int param_2)

{
  WCHAR WVar1;
  WCHAR WVar2;
  LPCWSTR pWVar3;
  HBITMAP pHVar4;
  undefined4 uVar5;
  LPCWSTR pWVar6;
  WCHAR *pWVar7;
  int iVar8;
  
  if (((int)param_1[0x137] <= param_2) || (param_2 == -1)) {
    return 0;
  }
  iVar8 = param_2 * 4;
  if (*(int *)(param_1[0x136] + iVar8) != 0) {
    return *(int *)(param_1[0x136] + iVar8);
  }
  pWVar3 = (LPCWSTR)(**(code **)*param_1)(param_1);
  if ((*(int *)(param_1[0x136] + iVar8) == 0) && (pWVar6 = pWVar3, pWVar3 != (LPCWSTR)0x0)) {
    do {
      WVar1 = *pWVar6;
      pWVar6 = pWVar6 + 1;
    } while (WVar1 != L'\0');
    pWVar7 = L"png";
    pWVar6 = pWVar3 + (((uint)((int)pWVar6 - (int)pWVar3) >> 1) - 4);
    do {
      WVar1 = *pWVar6;
      WVar2 = *pWVar7;
      if (WVar1 == L'\0') break;
      pWVar6 = pWVar6 + 1;
      pWVar7 = pWVar7 + 1;
    } while (WVar1 == WVar2);
    if (WVar1 != WVar2) {
      pHVar4 = FUN_000130b8(param_1,pWVar3);
      *(HBITMAP *)(param_1[0x136] + iVar8) = pHVar4;
      return *(int *)(param_1[0x136] + iVar8);
    }
    if (param_1[0x138] == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (*(code *)param_1[0x139])(pWVar3,0,1);
    }
    *(undefined4 *)(param_1[0x136] + iVar8) = uVar5;
  }
  return *(int *)(param_1[0x136] + iVar8);
}



/* 000130b8 FUN_000130b8 */

/* Boundary evidence: original MIPS .pdata 000130b8..000133df. Semantic name remains unreviewed. */

HBITMAP FUN_000130b8(undefined4 param_1,LPCWSTR param_2)

{
  HANDLE hFile;
  DWORD DVar1;
  BOOL BVar2;
  HDC hdc;
  HBITMAP h;
  int iVar3;
  uint uVar4;
  DWORD nNumberOfBytesToRead;
  DWORD local_850;
  void *local_84c;
  short local_848 [5];
  int local_83e;
  undefined4 local_838;
  undefined4 local_834;
  int local_830;
  int local_82c;
  undefined4 local_828;
  undefined4 local_824;
  BITMAPINFO local_820 [46];
  uint local_20;
  
  local_20 = DAT_00021450;
  local_848[0] = 0;
  local_848[1] = 0;
  local_848[2] = 0;
  local_848[3] = 0;
  local_848[4] = 0;
  local_83e = 0;
  local_84c = (LPVOID)0x0;
  local_820[0].bmiHeader.biSize._0_1_ = 0;
  memset((void *)((int)&local_820[0].bmiHeader.biSize + 1),0,0x7ff);
  local_838 = 0;
  local_834 = 0;
  local_830 = 0;
  local_82c = 0;
  local_828 = 0;
  local_824 = 0;
  local_850 = 0;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    DVar1 = GetFileSize(hFile,(LPDWORD)0x0);
    if ((((DVar1 != 0xffffffff) &&
         (BVar2 = ReadFile(hFile,local_848,0xe,&local_850,(LPOVERLAPPED)0x0), BVar2 != 0)) &&
        (local_850 == 0xe)) &&
       ((local_848[0] == 0x4d42 &&
        (nNumberOfBytesToRead = local_83e - 0xe, nNumberOfBytesToRead != 0)))) {
      memset(local_820,0,0x800);
      BVar2 = ReadFile(hFile,local_820,nNumberOfBytesToRead,&local_850,(LPOVERLAPPED)0x0);
      if ((BVar2 != 0) && (nNumberOfBytesToRead == local_850)) {
        hdc = CreateCompatibleDC((HDC)0x0);
        if (local_820[0].bmiHeader.biSizeImage == 0) {
          iVar3 = (uint)local_820[0].bmiHeader.biBitCount * local_820[0].bmiHeader.biWidth + 7;
          if (iVar3 < 0) {
            iVar3 = (uint)local_820[0].bmiHeader.biBitCount * local_820[0].bmiHeader.biWidth + 0xe;
          }
          uVar4 = iVar3 >> 3;
          if ((uVar4 & 1) != 0) {
            uVar4 = uVar4 + 1;
          }
          local_820[0].bmiHeader.biSizeImage =
               ((local_820[0].bmiHeader.biHeight ^ local_820[0].bmiHeader.biHeight >> 0x1f) -
               (local_820[0].bmiHeader.biHeight >> 0x1f)) * uVar4;
        }
        if (DVar1 < local_820[0].bmiHeader.biSizeImage + local_83e) {
          local_820[0].bmiHeader.biSizeImage = DVar1 - local_83e;
        }
        h = CreateDIBSection(hdc,local_820,0,&local_84c,(HANDLE)0x0,0);
        GetObjectW(h,0x18,&local_838);
        DVar1 = local_82c * local_830;
        BVar2 = ReadFile(hFile,local_84c,DVar1,&local_850,(LPOVERLAPPED)0x0);
        if ((BVar2 != 0) && (DVar1 == local_850)) {
          DeleteDC(hdc);
          CloseHandle(hFile);
          FUN_0001ab10(local_20);
          return h;
        }
        if (h != (HBITMAP)0x0) {
          DeleteObject(h);
        }
        if (hdc != (HDC)0x0) {
          DeleteDC(hdc);
        }
      }
    }
    CloseHandle(hFile);
  }
  FUN_0001ab10(local_20);
  return (HBITMAP)0x0;
}



/* 000133e0 FUN_000133e0 */

/* Boundary evidence: original MIPS .pdata 000133e0..000134f7. Semantic name remains unreviewed. */

void FUN_000133e0(int param_1)

{
  WCHAR WVar1;
  HMODULE hModule;
  LPWSTR pWVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  WCHAR *pWVar6;
  LPWSTR lpFilename;
  
  lpFilename = (LPWSTR)(param_1 + 200);
  hModule = GetModuleHandleW((LPCWSTR)0x0);
  GetModuleFileNameW(hModule,lpFilename,0x100);
  pWVar2 = lpFilename;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  uVar3 = (uint)((int)pWVar2 - (int)lpFilename) >> 1;
  iVar4 = uVar3 - 1;
  if (0 < iVar4) {
    psVar5 = (short *)((uVar3 + 99) * 2 + param_1);
    do {
      if (*psVar5 == 0x5c) {
        *(undefined2 *)((iVar4 + 0x65) * 2 + param_1) = 0;
        pWVar6 = (WCHAR *)(param_1 + 0x2d0);
        iVar4 = 0x104;
        while( true ) {
          if (iVar4 == 0) {
            return;
          }
          WVar1 = *lpFilename;
          *pWVar6 = WVar1;
          if (WVar1 == L'\0') break;
          pWVar6 = pWVar6 + 1;
          lpFilename = lpFilename + 1;
          iVar4 = iVar4 + -1;
        }
        if (iVar4 == 0) {
          return;
        }
        do {
          *pWVar6 = L'\0';
          iVar4 = iVar4 + -1;
          pWVar6 = pWVar6 + 1;
        } while (iVar4 != 0);
        return;
      }
      iVar4 = iVar4 + -1;
      psVar5 = psVar5 + -1;
    } while (0 < iVar4);
  }
  *lpFilename = L'\\';
  *(undefined2 *)(param_1 + 0x2d0) = 0x5c;
  *(undefined2 *)(param_1 + 0xca) = 0;
  *(undefined2 *)(param_1 + 0x2d2) = 0;
  return;
}



/* 000134f8 FUN_000134f8 */

/* Boundary evidence: original MIPS .pdata 000134f8..0001354b. Semantic name remains unreviewed. */

void FUN_000134f8(int param_1,short *param_2)

{
  undefined *puVar1;
  
  if (param_2 != (short *)0x0) {
    if (*param_2 == 0x5c) {
      puVar1 = &DAT_00020358;
    }
    else {
      puVar1 = (undefined *)(param_1 + 0x2d0);
    }
    _snwprintf((wchar_t *)(param_1 + 0x2d0),0x103,L"%s%s",puVar1,param_2);
  }
  return;
}



/* 0001354c FUN_0001354c */

/* Boundary evidence: original MIPS .pdata 0001354c..0001359f. Semantic name remains unreviewed. */

void FUN_0001354c(int param_1,short *param_2)

{
  undefined *puVar1;
  
  if (param_2 != (short *)0x0) {
    if (*param_2 == 0x5c) {
      puVar1 = &DAT_00020358;
    }
    else {
      puVar1 = (undefined *)(param_1 + 200);
    }
    _snwprintf((wchar_t *)(param_1 + 200),0x103,L"%s%s",puVar1,param_2);
  }
  return;
}



/* 000135a0 FUN_000135a0 */

/* Boundary evidence: original MIPS .pdata 000135a0..00013697. Semantic name remains unreviewed. */

undefined4 FUN_000135a0(int param_1)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  
  pHVar1 = GetModuleHandleW(L"BMGLibPNG.dll");
  *(HMODULE *)(param_1 + 0x4e0) = pHVar1;
  if (pHVar1 == (HMODULE)0x0) {
    pHVar1 = LoadLibraryW(L"BMGLibPNG.dll");
    *(HMODULE *)(param_1 + 0x4e0) = pHVar1;
  }
  if (*(int *)(param_1 + 0x4e0) == 0) {
    return 0;
  }
  uVar2 = GetProcAddressW(*(int *)(param_1 + 0x4e0),L"CreateBitmapFromFile");
  *(undefined4 *)(param_1 + 0x4e4) = uVar2;
  uVar2 = GetProcAddressW(*(undefined4 *)(param_1 + 0x4e0),L"GetDataFromBitmap");
  *(undefined4 *)(param_1 + 0x4e8) = uVar2;
  uVar2 = GetProcAddressW(*(undefined4 *)(param_1 + 0x4e0),L"SetBMGBackgroundColor");
  *(undefined4 *)(param_1 + 0x4ec) = uVar2;
  uVar2 = GetProcAddressW(*(undefined4 *)(param_1 + 0x4e0),L"FreeBMGImage");
  *(undefined4 *)(param_1 + 0x4f4) = uVar2;
  uVar2 = GetProcAddressW(*(undefined4 *)(param_1 + 0x4e0),L"SetBMGBackgroundBitmap");
  *(undefined4 *)(param_1 + 0x4f0) = uVar2;
  return 1;
}



/* 00013698 FUN_00013698 */

/* Boundary evidence: original MIPS .pdata 00013698..0001376b. Semantic name remains unreviewed. */

undefined4 FUN_00013698(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  HKEY local_28;
  undefined4 local_24;
  DWORD local_20 [4];
  
  local_20[1] = 4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_28,local_20 + 2);
  if (LVar1 == 0) {
    local_20[0] = 4;
    LVar1 = RegQueryValueExW(local_28,param_3,(LPDWORD)0x0,local_20 + 1,(LPBYTE)&local_24,local_20);
    if (LVar1 != 0) {
      local_24 = param_4;
    }
    RegCloseKey(local_28);
  }
  else {
    local_24 = 0;
  }
  return local_24;
}



/* 0001376c FUN_0001376c */

void FUN_0001376c(short *param_1,int param_2,short *param_3)

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



/* 00013878 FUN_00013878 */

bool FUN_00013878(short *param_1,undefined4 param_2,short *param_3)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *param_3;
  iVar2 = 0x6d;
  for (; (((sVar1 != 0 && (0 < iVar2)) && (*param_1 == sVar1)) && (*param_1 != 0));
      param_1 = param_1 + 1) {
    param_3 = param_3 + 1;
    sVar1 = *param_3;
    iVar2 = iVar2 + -1;
  }
  return *param_1 != *param_3;
}



/* 000138dc FUN_000138dc */

void FUN_000138dc(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x2c) =
       (param_2 << 9 ^ *(uint *)(param_1 + 0x2c)) & 0x200 ^ *(uint *)(param_1 + 0x2c);
  return;
}



/* 000138fc FUN_000138fc */

undefined4 * FUN_000138fc(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  uVar3 = *(undefined4 *)(param_1 + 0x14);
  *param_2 = *(undefined4 *)(param_1 + 8);
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  return param_2;
}



/* 00013984 FUN_00013984 */

/* Boundary evidence: original MIPS .pdata 00013984..000139f7. Semantic name remains unreviewed. */

void FUN_00013984(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xb] & 0x80U) != 0) {
    if (((param_1[1] != 0) && (iVar1 = *(int *)(param_1[1] + 0x1c), iVar1 != 0)) &&
       (*(int *)(iVar1 + 0x60) != 0)) {
      (**(code **)(*param_1 + 0x1c))();
      return;
    }
    (**(code **)*param_1)();
  }
  return;
}



/* 000139f8 FUN_000139f8 */

/* Boundary evidence: original MIPS .pdata 000139f8..00013a67. Semantic name remains unreviewed. */

void FUN_000139f8(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  if ((*(uint *)(param_1 + 0x2c) & 0x40) == 0) {
    *(undefined4 *)(param_1 + 4) = param_4;
    *(undefined4 *)(param_1 + 8) = *param_3;
    *(undefined4 *)(param_1 + 0xc) = param_3[1];
    *(undefined4 *)(param_1 + 0x10) = param_3[2];
    *(undefined4 *)(param_1 + 0x14) = param_3[3];
    if (param_2 != -1) {
      FUN_00013a68(param_1,param_2);
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x40;
  }
  return;
}



/* 00013a68 FUN_00013a68 */

/* Boundary evidence: original MIPS .pdata 00013a68..00013b67. Semantic name remains unreviewed. */

void FUN_00013a68(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (DAT_00021690 == (undefined4 *)0x0) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
  }
  iVar2 = FUN_00012f2c(DAT_00021690,param_2);
  bVar1 = DAT_00021690 == (undefined4 *)0x0;
  *(int *)(param_1 + 0x28) = iVar2;
  if (bVar1) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
  }
  if (*(HANDLE *)(param_1 + 0x28) == (HANDLE)0x0) {
    local_20._2_2_ = 0;
  }
  else {
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    GetObjectW(*(HANDLE *)(param_1 + 0x28),0x18,&local_30);
  }
  if (local_20._2_2_ == 0x20) {
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x800;
  }
  return;
}



/* 00013b68 FUN_00013b68 */

/* Boundary evidence: original MIPS .pdata 00013b68..00013be3. Semantic name remains unreviewed. */

void FUN_00013b68(undefined4 *param_1)

{
  if (param_1[1] != 0) {
    if ((param_1[0xb] & 0x80) != 0) {
      (**(code **)*param_1)(param_1);
      return;
    }
    FUN_00016e7c(param_1[1],param_1 + 2);
    FUN_00016ff0(param_1[1],param_1 + 2);
  }
  return;
}



/* 00013be4 FUN_00013be4 */

/* Boundary evidence: original MIPS .pdata 00013be4..00013c33. Semantic name remains unreviewed. */

void FUN_00013be4(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1[0xb];
  uVar2 = (param_2 << 8 ^ uVar1) & 0x100 ^ uVar1;
  param_1[0xb] = uVar2;
  if ((param_3 != 0) && ((uVar1 >> 8 & 1) != (uVar2 >> 8 & 1))) {
    FUN_00013b68(param_1);
  }
  return;
}



/* 00013c34 FUN_00013c34 */

/* Boundary evidence: original MIPS .pdata 00013c34..00013cab. Semantic name remains unreviewed. */

void FUN_00013c34(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1[0xb];
  uVar2 = (param_2 << 7 ^ uVar1) & 0x80 ^ uVar1;
  uVar2 = (uVar2 << 1 ^ uVar2) & 0x100 ^ uVar2;
  param_1[0xb] = uVar2;
  if ((param_3 != 0) &&
     (((uVar1 >> 7 & 1) != (uVar2 >> 7 & 1) || ((uVar1 >> 8 & 1) != (uVar2 >> 8 & 1))))) {
    FUN_00013b68(param_1);
  }
  return;
}



/* 00013cbc FUN_00013cbc */

/* Boundary evidence: original MIPS .pdata 00013cbc..00013db7. Semantic name remains unreviewed. */

undefined4 * FUN_00013cbc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00020550;
  param_1[1] = &PTR_FUN_000206c0;
  param_1[6] = 0x32;
  param_1[4] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[9] = 0;
  param_1[0x11] = 0;
  param_1[0x1c] = 700;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1d] = 200;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0xaa] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  memset(param_1 + 0x28,0,0x208);
  return param_1;
}



/* 00013db8 FUN_00013db8 */

/* Boundary evidence: original MIPS .pdata 00013db8..00013e3b. Semantic name remains unreviewed. */

void FUN_00013db8(int *param_1)

{
  *param_1 = (int)&PTR_FUN_00020550;
  FUN_00014880(param_1);
  param_1[1] = (int)&PTR_FUN_000206c0;
  if (((HDC)param_1[0xb] != (HDC)0x0) && ((HWND)param_1[7] != (HWND)0x0)) {
    ReleaseDC((HWND)param_1[7],(HDC)param_1[0xb]);
  }
  param_1[3] = 0;
  LocalFree((HLOCAL)param_1[2]);
  param_1[2] = 0;
  return;
}



/* 00013e3c Unwind@00013e3c */

/* Boundary evidence: original MIPS .pdata 00013e3c..00013e6f. Semantic name remains unreviewed. */

void Unwind_00013e3c(void)

{
  int *in_v0;
  
  FUN_00016d48((undefined4 *)(*in_v0 + 4));
  return;
}



/* 00013e70 FUN_00013e70 */

/* Boundary evidence: original MIPS .pdata 00013e70..00013ecf. Semantic name remains unreviewed. */

void FUN_00013e70(int param_1)

{
  if (*(int **)(param_1 + 0x60) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x60) + 0x34))();
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  if (*(HWND *)(param_1 + 0x50) != (HWND)0x0) {
    EnableWindow(*(HWND *)(param_1 + 0x50),1);
    KillTimer(*(HWND *)(param_1 + 0x50),0x40f);
  }
  return;
}



/* 00013ed0 FUN_00013ed0 */

/* Boundary evidence: original MIPS .pdata 00013ed0..00013fc7. Semantic name remains unreviewed. */

void FUN_00013ed0(int *param_1,HWND param_2)

{
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68 [4];
  tagPAINTSTRUCT tStack_58;
  uint local_18;
  
  local_18 = DAT_00021450;
  if (DAT_0002271c == 0) {
    BeginPaint(param_2,&tStack_58);
    local_74 = tStack_58.rcPaint.top;
    local_70 = tStack_58.rcPaint.right - tStack_58.rcPaint.left;
    local_6c = tStack_58.rcPaint.bottom - tStack_58.rcPaint.top;
    local_78 = tStack_58.rcPaint.left;
    FUN_00016ff0((int)(param_1 + 1),&local_78);
    (**(code **)(*param_1 + 0x2c))(param_1);
    EndPaint(param_2,&tStack_58);
  }
  else {
    BeginPaint(param_2,&tStack_58);
    local_68[0] = 0;
    local_68[1] = 0;
    local_68[2] = 0;
    local_68[3] = 0;
    FUN_00016ff0((int)(param_1 + 1),local_68);
    EndPaint(param_2,&tStack_58);
    if (param_1[0x18] != 0) {
      SetForegroundWindow(*(HWND *)(param_1[0x18] + 0x50));
    }
  }
  FUN_0001ab10(local_18);
  return;
}



/* 00013fc8 FUN_00013fc8 */

/* Boundary evidence: original MIPS .pdata 00013fc8..000140ab. Semantic name remains unreviewed. */

void FUN_00013fc8(int *param_1)

{
  HDC hdcSrc;
  int cy;
  int cx;
  int y;
  int x;
  
  if ((HGDIOBJ)param_1[0xc] != (HGDIOBJ)0x0) {
    x = param_1[0xd];
    y = param_1[0xe];
    cx = param_1[0xf];
    cy = param_1[0x10];
    hdcSrc = (HDC)FUN_00016c18((HGDIOBJ)param_1[0xc]);
    BitBlt((HDC)param_1[10],x,y,cx,cy,hdcSrc,x,y,0xcc0020);
    SelectObject((HDC)DAT_00022724->SpinCount,DAT_00022724[1].DebugInfo);
    LeaveCriticalSection(DAT_00022724);
  }
  FUN_00016f34((int)(param_1 + 1));
  if (param_1[0x19] != 0) {
    FUN_00016f34(param_1[0x19] + 4);
  }
  (**(code **)(*param_1 + 0x28))(param_1);
  return;
}



/* 000140ac FUN_000140ac */

/* Boundary evidence: original MIPS .pdata 000140ac..0001457b. Semantic name remains unreviewed. */

LRESULT FUN_000140ac(int *param_1,HWND param_2,uint param_3,uint param_4,uint param_5)

{
  LRESULT LVar1;
  BOOL BVar2;
  int *piVar3;
  int iVar4;
  uint local_48;
  uint local_44;
  tagMSG tStack_40;
  
  piVar3 = (int *)param_1[0x19];
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(piVar3,param_2,param_3,param_4,param_5);
  }
  if (param_3 < 0x114) {
    if (param_3 == 0x113) {
      if (param_4 < 0x3f7) {
        if (param_4 == 0x3f6) {
          iVar4 = param_1[9];
          if (iVar4 != 0) {
            if ((DAT_00022704 != (code *)0x0) && ((*(uint *)(iVar4 + 0x30) >> 7 & 1) != 0)) {
              (*DAT_00022704)(4,iVar4);
            }
            (**(code **)(*param_1 + 0x38))(param_1,*(undefined4 *)(iVar4 + 0x34),4);
            return 1;
          }
          if ((HWND)param_1[0x14] == (HWND)0x0) {
            return 1;
          }
          KillTimer((HWND)param_1[0x14],0x3f6);
          return 1;
        }
        if (param_4 == 0x3e9) {
          KillTimer(param_2,0x3e9);
          return 1;
        }
        if (param_4 == 0x3f5) {
          if ((HWND)param_1[0x14] != (HWND)0x0) {
            KillTimer((HWND)param_1[0x14],0x3f5);
          }
          iVar4 = param_1[9];
          if (iVar4 == 0) {
            return 1;
          }
          if ((DAT_00022704 != (code *)0x0) && ((*(uint *)(iVar4 + 0x30) >> 6 & 1) != 0)) {
            (*DAT_00022704)(3,iVar4);
          }
          (**(code **)(*param_1 + 0x38))(param_1,*(undefined4 *)(iVar4 + 0x34),3);
          param_1[0x11] = 1;
          SetTimer((HWND)param_1[0x14],0x3f6,param_1[0x1d],(TIMERPROC)0x0);
          return 1;
        }
      }
      else {
        if (param_4 == 0x3f7) {
          (**(code **)(*param_1 + 0x58))(param_1);
          return 1;
        }
        if (param_4 == 0x40f) {
          KillTimer(param_2,0x40f);
          EnableWindow(param_2,1);
          return 1;
        }
      }
      (**(code **)(*param_1 + 0x18))(param_1,param_2,0x113,param_4,param_5);
    }
    else if (param_3 < 0x10) {
      if (param_3 == 0xf) {
        FUN_00013ed0(param_1,param_2);
        if ((DAT_0002271c == 0) && (DAT_00022718 != 0)) {
          DAT_0002271c = 1;
        }
      }
      else if (param_3 == 1) {
        (**(code **)(*param_1 + 0x14))(param_1,param_2,param_4,param_5);
      }
      else {
        if (param_3 != 6) goto LAB_00014438;
        if (param_4 == 0) {
          piVar3 = (int *)param_1[9];
          param_1[0x17] = param_1[0x17] & 0xfffffffd;
          if (piVar3 != (int *)0x0) {
            local_48 = 0xffffffff;
            local_44 = 0xffffffff;
            (**(code **)(*piVar3 + 0xc))(piVar3,&local_48);
          }
          (**(code **)(*param_1 + 0x54))(param_1,1);
        }
        else {
          param_1[0x17] = param_1[0x17] | 2;
          if (0 < param_1[0x1a]) {
            SetTimer((HWND)param_1[0x14],0x3f7,param_1[0x1a],(TIMERPROC)0x0);
          }
          (**(code **)(*param_1 + 0x54))(param_1,0);
        }
      }
    }
    else if (param_3 != 0x14) {
LAB_00014438:
      LVar1 = DefWindowProcW(param_2,param_3,param_4,param_5);
      return LVar1;
    }
  }
  else if (param_3 == 0x200) {
    local_48 = param_5 & 0xffff;
    local_44 = param_5 >> 0x10;
    piVar3 = (int *)param_1[9];
    if (piVar3 == (int *)0x0) {
      if ((param_1[0x17] & 8U) != 0) {
        FUN_00014cc8((int)param_1,param_5);
      }
    }
    else {
      iVar4 = (**(code **)(*piVar3 + 0xc))(piVar3,&local_48);
      if (iVar4 != 0) {
        ReleaseCapture();
      }
    }
  }
  else if (param_3 == 0x201) {
    KillTimer((HWND)param_1[0x14],0x3f7);
    FUN_00014be4((int)param_1,param_5);
  }
  else {
    if (param_3 != 0x202) goto LAB_00014438;
    if (0 < param_1[0x1a]) {
      SetTimer((HWND)param_1[0x14],0x3f7,param_1[0x1a],(TIMERPROC)0x0);
    }
    local_48 = param_5 & 0xffff;
    local_44 = param_5 >> 0x10;
    ReleaseCapture();
    piVar3 = (int *)param_1[9];
    param_1[0x17] = param_1[0x17] & 0xfffffff7;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3,&local_48);
    }
    do {
      BVar2 = PeekMessageW(&tStack_40,(HWND)0x0,0x200,0x20d,1);
    } while (BVar2 != 0);
  }
  return 1;
}



/* 0001457c FUN_0001457c */

/* Boundary evidence: original MIPS .pdata 0001457c..0001465f. Semantic name remains unreviewed. */

int FUN_0001457c(wchar_t *param_1,HINSTANCE param_2,HWND param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  WNDCLASSW *pWVar2;
  HWND hWnd;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 == 0) {
    *(HINSTANCE *)(param_1 + 0x24) = param_2;
    pWVar2 = FUN_000156f0(param_1,param_2,FUN_00014b68);
    hWnd = CreateWindowExW(0x4000000,pWVar2->lpszClassName,pWVar2->lpszClassName,0x90000000,0,0,800,
                           0x1e0,param_3,(HMENU)0x0,param_2,(LPVOID)0x0);
    *(HWND *)(param_1 + 0x28) = hWnd;
    if (hWnd == (HWND)0x0) {
      GetLastError();
      iVar1 = 0;
    }
    else {
      SetWindowLongW(hWnd,-0x15,(LONG)param_1);
      FUN_00014660((int *)param_1,param_4,param_5);
      iVar1 = *(int *)(param_1 + 0x28);
    }
  }
  return iVar1;
}



/* 00014660 FUN_00014660 */

/* Boundary evidence: original MIPS .pdata 00014660..0001477b. Semantic name remains unreviewed. */

int FUN_00014660(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  
  param_1[0x17] = param_1[0x17] & 0xffffffdf;
  if (param_1[3] == 0) {
    (**(code **)(*param_1 + 0x1c))(param_1,param_2);
  }
  (**(code **)(*param_1 + 0x20))(param_1,param_2);
  iVar1 = param_1[0x19];
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x20) = param_1[8];
    *(int *)(iVar1 + 0x28) = param_1[10];
    *(int *)(iVar1 + 0x30) = param_1[0xc];
    *(int *)(iVar1 + 0x2c) = param_1[0xb];
  }
  pcVar2 = *(code **)(*param_1 + 0x24);
  param_1[0x17] = param_1[0x17] | 0x20;
  (*pcVar2)(param_1);
  if (param_3 != 0) {
    if ((HWND)param_1[0x14] != (HWND)0x0) {
      EnableWindow((HWND)param_1[0x14],1);
      KillTimer((HWND)param_1[0x14],0x40f);
    }
    ShowWindow((HWND)param_1[0x14],1);
    SetForegroundWindow((HWND)param_1[0x14]);
    UpdateWindow((HWND)param_1[0x14]);
    Sleep(0x32);
  }
  return param_1[0x14];
}



/* 0001477c FUN_0001477c */

/* Boundary evidence: original MIPS .pdata 0001477c..0001487f. Semantic name remains unreviewed. */

void FUN_0001477c(int param_1,HWND param_2)

{
  HDC pHVar1;
  HDC pHVar2;
  HBITMAP pHVar3;
  HGDIOBJ pvVar4;
  
  SetWindowPos(param_2,(HWND)0x0,0,0,800,0x1e0,0x80);
  pHVar1 = GetDC(param_2);
  if (*(int *)(param_1 + 0x4c) == 0) {
    pHVar2 = CreateCompatibleDC(pHVar1);
    *(HDC *)(param_1 + 0x4c) = pHVar2;
  }
  if (*(int *)(param_1 + 0x54) == 0) {
    pHVar3 = CreateCompatibleBitmap(pHVar1,800,0x1e0);
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



/* 00014880 FUN_00014880 */

/* Boundary evidence: original MIPS .pdata 00014880..00014943. Semantic name remains unreviewed. */

void FUN_00014880(int *param_1)

{
  int *piVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_1[0x14] != 0) {
    (**(code **)*param_1)(param_1);
    piVar1 = (int *)param_1[9];
    if (piVar1 != (int *)0x0) {
      local_10 = 0xffffffff;
      local_c = 0xffffffff;
      (**(code **)(*piVar1 + 0xc))(piVar1,&local_10);
    }
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
    (**(code **)(*param_1 + 0x50))(param_1);
  }
  return;
}



/* 00014944 FUN_00014944 */

/* Boundary evidence: original MIPS .pdata 00014944..00014b67. Semantic name remains unreviewed. */

undefined4 FUN_00014944(int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  HWND pHVar1;
  BOOL BVar2;
  undefined4 uVar3;
  tagMSG tStack_48;
  
  DAT_0002271c = 0;
  DAT_00022718 = 0;
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00022728);
  if (DAT_00022714 == 0) {
    param_2[0xab] = param_4;
    DAT_00022714 = param_4;
    pHVar1 = GetForegroundWindow();
    param_2[0xae] = (int)pHVar1;
    if ((int *)param_1[0x18] == param_2) {
      FUN_00014660((int *)param_1[0x18],param_3,1);
      FUN_00016ff0(param_1[0x18] + 4,(int *)(param_1[0x18] + 0x34));
      uVar3 = *(undefined4 *)(param_1[0x18] + 0x50);
    }
    else {
      if ((HWND)param_1[0x14] != (HWND)0x0) {
        EnableWindow((HWND)param_1[0x14],0);
        KillTimer((HWND)param_1[0x14],0x40f);
        SetTimer((HWND)param_1[0x14],0x40f,2000,(TIMERPROC)0x0);
      }
      do {
        BVar2 = PeekMessageW(&tStack_48,(HWND)0x0,0x200,0x20d,1);
      } while (BVar2 != 0);
      if (((int *)param_1[0x18] == (int *)0x0) || ((int *)param_1[0x18] == param_2)) {
        uVar3 = (**(code **)(*param_2 + 0x30))(param_2,param_1[0x12],param_1[0x14],param_3,1);
        param_2[0xac] = (int)param_1;
      }
      else {
        if ((param_2[0xab] == 0) && (DAT_00022714 != 0)) goto LAB_00014b20;
        DAT_00022720 = 1;
        uVar3 = (**(code **)(*param_2 + 0x30))(param_2,param_1[0x12],param_1[0x14],param_3,1);
        param_2[0xac] = (int)param_1;
        (**(code **)(*(int *)param_1[0x18] + 0x34))();
        param_1[0x18] = 0;
        DAT_00022720 = 0;
      }
      param_1[0x18] = (int)param_2;
      (**(code **)(*param_2 + 0x54))(param_2,0);
      (**(code **)(*param_1 + 0x54))(param_1,1);
    }
  }
  else {
    param_2[0xab] = 0;
  }
LAB_00014b20:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00022728);
  Sleep(200);
  return uVar3;
}



/* 00014b68 FUN_00014b68 */

/* Boundary evidence: original MIPS .pdata 00014b68..00014be3. Semantic name remains unreviewed. */

LRESULT FUN_00014b68(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  int *piVar1;
  LRESULT LVar2;
  
  piVar1 = (int *)GetWindowLongW(param_1,-0x15);
  if (piVar1 == (int *)0x0) {
    LVar2 = 0;
  }
  else {
    LVar2 = FUN_000140ac(piVar1,param_1,param_2,param_3,param_4);
  }
  return LVar2;
}



/* 00014be4 FUN_00014be4 */

/* Boundary evidence: original MIPS .pdata 00014be4..00014cc7. Semantic name remains unreviewed. */

int FUN_00014be4(int param_1,uint param_2)

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
  *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | 8;
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



/* 00014cc8 FUN_00014cc8 */

/* Boundary evidence: original MIPS .pdata 00014cc8..00014da7. Semantic name remains unreviewed. */

int FUN_00014cc8(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint local_20;
  uint local_1c;
  
  if ((*(uint *)(param_1 + 0x5c) & 0x10) == 0) {
    iVar1 = 0;
  }
  else {
    local_20 = param_2 & 0xffff;
    local_1c = param_2 >> 0x10;
    iVar1 = 0;
    uVar3 = *(int *)(param_1 + 0xc) - 1;
    if (-1 < (int)uVar3) {
      iVar4 = uVar3 * 4;
      do {
        if (uVar3 < *(uint *)(param_1 + 0xc)) {
          piVar2 = *(int **)(iVar4 + *(int *)(param_1 + 8));
        }
        else {
          piVar2 = (int *)0x0;
        }
        if ((((piVar2[0xb] & 0x3fU) == 3) && ((piVar2[0xc] & 0x100U) != 0)) &&
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



/* 00014da8 FUN_00014da8 */

/* Boundary evidence: original MIPS .pdata 00014da8..00014e2b. Semantic name remains unreviewed. */

void FUN_00014da8(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == -1) {
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  else {
    if (DAT_00021690 == (undefined4 *)0x0) {
      MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
    }
    iVar1 = FUN_00012f2c(DAT_00021690,param_2);
    *(int *)(param_1 + 0x30) = iVar1;
  }
  return;
}



/* 00014e2c FUN_00014e2c */

/* Boundary evidence: original MIPS .pdata 00014e2c..00014ebf. Semantic name remains unreviewed. */

void FUN_00014e2c(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  FUN_00016730((int *)(param_1 + 8),param_2);
  (**(code **)(*param_2 + 0x18))(param_2,param_3,param_4,param_1 + 4);
  param_2[0xd] = param_5;
  param_2[0xb] = (param_6 << 9 ^ param_2[0xb]) & 0x200U ^ param_2[0xb];
  return;
}



/* 00014ec0 FUN_00014ec0 */

/* Boundary evidence: original MIPS .pdata 00014ec0..00014efb. Semantic name remains unreviewed. */

void FUN_00014ec0(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5,
                 int param_6,int param_7,int *param_8)

{
  FUN_000170a0(param_1 + 4,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* 00014efc FUN_00014efc */

/* Boundary evidence: original MIPS .pdata 00014efc..00014f37. Semantic name remains unreviewed. */

void FUN_00014efc(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 short *param_6,int param_7,int param_8)

{
  FUN_00017188(param_1 + 4,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* 00014f38 FUN_00014f38 */

/* Boundary evidence: original MIPS .pdata 00014f38..00014f9b. Semantic name remains unreviewed. */

void FUN_00014f38(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,short *param_7,int *param_8,int *param_9,int param_10,int param_11,
                 int param_12,uint param_13)

{
  FUN_0001727c(param_1 + 4,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13);
  return;
}



/* 00014f9c FUN_00014f9c */

/* Boundary evidence: original MIPS .pdata 00014f9c..00014fcb. Semantic name remains unreviewed. */

void FUN_00014f9c(int param_1,UINT param_2)

{
  *(UINT *)(param_1 + 0x68) = param_2;
  if (0 < (int)param_2) {
    SetTimer(*(HWND *)(param_1 + 0x50),0x3f7,param_2,(TIMERPROC)0x0);
  }
  return;
}



/* 00014fcc FUN_00014fcc */

/* Boundary evidence: original MIPS .pdata 00014fcc..00015017. Semantic name remains unreviewed. */

undefined4 * FUN_00014fcc(undefined4 *param_1)

{
  FUN_00013cbc(param_1);
  *param_1 = &PTR_FUN_000205ac;
  param_1[0x1b] = 1;
  param_1[0xac] = 0;
  param_1[0xae] = 0;
  param_1[0xad] = 1;
  return param_1;
}



/* 00015018 FUN_00015018 */

/* Boundary evidence: original MIPS .pdata 00015018..0001510b. Semantic name remains unreviewed. */

void FUN_00015018(int param_1)

{
  HDC hdcSrc;
  HGDIOBJ pvVar1;
  int cy;
  int cx;
  int y;
  int x;
  
  pvVar1 = *(HGDIOBJ *)(param_1 + 0x30);
  if (pvVar1 == (HGDIOBJ)0x0) {
    if ((*(uint *)(param_1 + 0x2b4) & 1) != 0) {
      FUN_0001510c(param_1);
    }
  }
  else if (pvVar1 != (HGDIOBJ)0x0) {
    x = *(int *)(param_1 + 0x34);
    y = *(int *)(param_1 + 0x38);
    cx = *(int *)(param_1 + 0x3c);
    cy = *(int *)(param_1 + 0x40);
    hdcSrc = (HDC)FUN_00016c18(pvVar1);
    BitBlt(*(HDC *)(param_1 + 0x28),x,y,cx,cy,hdcSrc,x,y,0xcc0020);
    SelectObject((HDC)DAT_00022724->SpinCount,DAT_00022724[1].DebugInfo);
    LeaveCriticalSection(DAT_00022724);
  }
  FUN_00016f34(param_1 + 4);
  if (*(int *)(param_1 + 100) != 0) {
    FUN_00016f34(*(int *)(param_1 + 100) + 4);
  }
  return;
}



/* 0001510c FUN_0001510c */

/* Boundary evidence: original MIPS .pdata 0001510c..0001525f. Semantic name remains unreviewed. */

void FUN_0001510c(int param_1)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  int iVar1;
  HDC hdc_00;
  
  if (DAT_0002145c - 1 < DAT_0002145c) {
    iVar1 = *(int *)((DAT_0002145c - 1) * 4 + DAT_00021458);
  }
  else {
    iVar1 = 0;
  }
  hdc_00 = *(HDC *)(iVar1 + 0x4c);
  hdc = CreateCompatibleDC(hdc_00);
  h = CreateCompatibleBitmap(hdc_00,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  AlphaBlend(hdc,0,0,800,0x1e0,hdc_00,0,0,800,0x1e0,(BLENDFUNCTION)0x460000);
  BitBlt(*(HDC *)(param_1 + 0x4c),0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteDC(hdc);
  DeleteObject(h);
  return;
}



/* 00015260 FUN_00015260 */

/* Boundary evidence: original MIPS .pdata 00015260..00015287. Semantic name remains unreviewed. */

undefined4 FUN_00015260(int *param_1)

{
  (**(code **)(*param_1 + 0x34))();
  return 1;
}



/* 00015288 FUN_00015288 */

/* Boundary evidence: original MIPS .pdata 00015288..000152a3. Semantic name remains unreviewed. */

void FUN_00015288(int *param_1)

{
  FUN_000152a4(param_1);
  return;
}



/* 000152a4 FUN_000152a4 */

/* Boundary evidence: original MIPS .pdata 000152a4..000154cb. Semantic name remains unreviewed. */

void FUN_000152a4(int *param_1)

{
  HDC hdcSrc;
  HWND hWnd;
  int *piVar1;
  int iVar2;
  int iVar3;
  int cx;
  int y;
  int x;
  
  DAT_00022718 = 0;
  DAT_0002271c = 0;
  if (param_1[0x14] != 0) {
    if ((DAT_00022714 != 0) && (param_1[0xab] != 0)) {
      DAT_00022718 = 0;
      param_1[0xab] = 0;
      DAT_00022714 = 0;
    }
    DAT_0002271c = 0;
    FUN_00014880(param_1);
    if (param_1[0xac] != 0) {
      *(undefined4 *)(param_1[0xac] + 0x60) = 0;
    }
    iVar3 = param_1[0xac];
    if (iVar3 != 0) {
      if (DAT_0002145c - 1 < DAT_0002145c) {
        iVar2 = *(int *)((DAT_0002145c - 1) * 4 + DAT_00021458);
      }
      else {
        iVar2 = 0;
      }
      if (iVar3 == iVar2) {
        iVar2 = param_1[0x19];
        if ((iVar2 != 0) && (*(int *)(iVar3 + 100) != 0)) {
          *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
          *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar3 + 0x28);
          *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar3 + 0x30);
          *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar3 + 0x2c);
          iVar3 = param_1[0x19];
          if (*(HGDIOBJ *)(iVar3 + 0x30) != (HGDIOBJ)0x0) {
            x = *(int *)(iVar3 + 0x34);
            y = *(int *)(iVar3 + 0x38);
            cx = *(int *)(iVar3 + 0x3c);
            iVar2 = *(int *)(iVar3 + 0x40);
            hdcSrc = (HDC)FUN_00016c18(*(HGDIOBJ *)(iVar3 + 0x30));
            BitBlt(*(HDC *)(iVar3 + 0x28),x,y,cx,iVar2,hdcSrc,x,y,0xcc0020);
            SelectObject((HDC)DAT_00022724->SpinCount,DAT_00022724[1].DebugInfo);
            LeaveCriticalSection(DAT_00022724);
          }
          FUN_00016f34(iVar3 + 4);
        }
        iVar3 = param_1[0xac];
        hWnd = *(HWND *)(iVar3 + 0x50);
        if (hWnd != (HWND)0x0) {
          EnableWindow(hWnd,1);
          KillTimer(*(HWND *)(iVar3 + 0x50),0x40f);
        }
        (**(code **)(*(int *)param_1[0xac] + 0x54))((int *)param_1[0xac],0);
        piVar1 = (int *)param_1[0xac];
        if ((piVar1[0x1b] == 0) && (DAT_00022720 == 0)) {
          DAT_0002271c = 0;
          FUN_00013ed0(piVar1,(HWND)piVar1[0x14]);
        }
      }
    }
  }
  return;
}



/* 000154cc FUN_000154cc */

/* Boundary evidence: original MIPS .pdata 000154cc..000156bf. Semantic name remains unreviewed. */

undefined4 FUN_000154cc(int *param_1,undefined4 param_2)

{
  uint uVar1;
  HWND hWnd;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar1 = DAT_0002145c;
  DAT_00022718 = 0;
  DAT_0002271c = 0;
  if (param_1 != (int *)0x0) {
    if (DAT_00022714 == 0) {
      uVar4 = 0;
      if (DAT_0002145c - 1 < DAT_0002145c) {
        piVar3 = *(int **)((DAT_0002145c - 1) * 4 + DAT_00021458);
      }
      else {
        piVar3 = (int *)0x0;
      }
      if (piVar3 == param_1) {
        SetForegroundWindow((HWND)param_1[0x14]);
        FUN_00014660(param_1,param_2,1);
        (**(code **)*piVar3)(piVar3);
        return 1;
      }
      DAT_00022720 = 1;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00022728);
      hWnd = (HWND)(**(code **)(*param_1 + 0x30))(param_1,DAT_0002270c,DAT_00022708,param_2,1);
      if (hWnd != (HWND)0x0) {
        SetWindowLongW(hWnd,-0xc,0);
        SetWindowLongW(hWnd,-0x10,-0x7e000000);
        SetWindowLongW(hWnd,-0x14,0x44000000);
        if (0 < (int)uVar1) {
          (**(code **)(*piVar3 + 0x34))(piVar3);
        }
        FUN_000157fc(&DAT_00021458,param_1);
        iVar2 = param_1[0x19];
        if (iVar2 != 0) {
          *(int *)(iVar2 + 0x20) = param_1[8];
          *(int *)(iVar2 + 0x28) = param_1[10];
          *(int *)(iVar2 + 0x30) = param_1[0xc];
          *(int *)(iVar2 + 0x2c) = param_1[0xb];
        }
        uVar4 = 1;
      }
      DAT_00022720 = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00022728);
      return uVar4;
    }
    NKDbgPrintfW(
                L" CGUIEmptyDlg::changeDialog   %S ms_KeepPopupEnabled == TRUE =================== \r\n"
                );
  }
  return 0;
}



/* 000156c0 FUN_000156c0 */

void FUN_000156c0(int param_1,int param_2)

{
  if ((DAT_00022708 == 0) && (DAT_0002270c == 0)) {
    DAT_00022708 = param_2;
    DAT_0002270c = param_1;
  }
  return;
}



/* 000156f0 FUN_000156f0 */

/* Boundary evidence: original MIPS .pdata 000156f0..000157bb. Semantic name remains unreviewed. */

WNDCLASSW * FUN_000156f0(wchar_t *param_1,undefined4 param_2,undefined4 param_3)

{
  ATOM AVar1;
  undefined2 extraout_var;
  WNDCLASSW *lpWndClass;
  
  if ((*(uint *)(param_1 + 0x2e) & 4) == 0) {
    swprintf(param_1 + 0x50,0x20530,param_1);
    lpWndClass = (WNDCLASSW *)(param_1 + 0x3c);
    *(undefined4 *)(param_1 + 0x3e) = param_3;
    lpWndClass->style = 3;
    param_1[0x40] = L'\0';
    param_1[0x41] = L'\0';
    param_1[0x42] = L'\0';
    param_1[0x43] = L'\0';
    *(undefined4 *)(param_1 + 0x44) = param_2;
    param_1[0x46] = L'\0';
    param_1[0x47] = L'\0';
    param_1[0x48] = L'\0';
    param_1[0x49] = L'\0';
    param_1[0x4a] = L'\0';
    param_1[0x4b] = L'\0';
    param_1[0x4c] = L'\0';
    param_1[0x4d] = L'\0';
    *(wchar_t **)(param_1 + 0x4e) = param_1 + 0x50;
    AVar1 = RegisterClassW(lpWndClass);
    if (CONCAT22(extraout_var,AVar1) == 0) {
      lpWndClass = (WNDCLASSW *)0x0;
    }
    else {
      *(uint *)(param_1 + 0x2e) = *(uint *)(param_1 + 0x2e) | 4;
    }
  }
  else {
    lpWndClass = (WNDCLASSW *)(param_1 + 0x3c);
  }
  return lpWndClass;
}



/* 000157bc FUN_000157bc */

/* Boundary evidence: original MIPS .pdata 000157bc..000157fb. Semantic name remains unreviewed. */

void FUN_000157bc(void)

{
  BOOL BVar1;
  tagMSG tStack_28;
  
  do {
    BVar1 = PeekMessageW(&tStack_28,(HWND)0x0,0x200,0x20d,1);
  } while (BVar1 != 0);
  return;
}



/* 000157fc FUN_000157fc */

/* Boundary evidence: original MIPS .pdata 000157fc..0001589b. Semantic name remains unreviewed. */

void FUN_000157fc(undefined4 param_1,undefined4 param_2)

{
  if (DAT_00021458 == (HLOCAL)0x0) {
    DAT_00021460 = DAT_00021468;
    DAT_00021458 = LocalAlloc(0x40,DAT_00021468 << 2);
  }
  else if (DAT_0002145c == DAT_00021460) {
    DAT_00021460 = DAT_00021460 + DAT_00021468;
    DAT_00021458 = LocalReAlloc(DAT_00021458,DAT_00021460 * 4,2);
  }
  *(undefined4 *)(DAT_0002145c * 4 + (int)DAT_00021458) = param_2;
  DAT_0002145c = DAT_0002145c + 1;
  return;
}



/* 0001589c FUN_0001589c */

undefined4 * FUN_0001589c(undefined4 *param_1)

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
  *param_1 = &PTR_FUN_00020618;
  param_1[1] = 0;
  param_1[10] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x16] = 5;
  param_1[0x14] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x15] = 0;
  param_1[0xd] = 0xffffffff;
  param_1[0xb] = param_1[0xb] & 0xffffffc3 | 3;
  param_1[0xc] = 0xe0;
  return param_1;
}



/* 0001593c FUN_0001593c */

/* Boundary evidence: original MIPS .pdata 0001593c..000159b3. Semantic name remains unreviewed. */

void FUN_0001593c(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 == 0) && ((param_1[0xc] & 1) != 0)) {
    param_1[0xc] = param_1[0xc] & 0xfffffffe;
  }
  uVar1 = param_1[0xb];
  uVar2 = (param_2 << 8 ^ uVar1) & 0x100 ^ uVar1;
  param_1[0xb] = uVar2;
  if ((param_3 != 0) && ((uVar1 >> 8 & 1) != (uVar2 >> 8 & 1))) {
    FUN_00013b68(param_1);
  }
  return;
}



/* 000159b4 FUN_000159b4 */

/* Boundary evidence: original MIPS .pdata 000159b4..00015a3f. Semantic name remains unreviewed. */

void FUN_000159b4(int *param_1)

{
  int *piVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (((param_1[0xb] & 0x80U) != 0) && (param_1[1] != 0)) {
    (**(code **)(*param_1 + 0x1c))(param_1);
    piVar1 = param_1 + 0xe;
    if ((param_1[0xc] & 0x10U) == 0) {
      piVar1 = param_1 + 2;
    }
    local_18 = *piVar1;
    local_14 = piVar1[1];
    local_10 = piVar1[2];
    local_c = piVar1[3];
    FUN_00016ff0(param_1[1],&local_18);
  }
  return;
}



/* 00015a40 FUN_00015a40 */

/* Boundary evidence: original MIPS .pdata 00015a40..00015b53. Semantic name remains unreviewed. */

void FUN_00015a40(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if ((param_1[0xb] & 0x100U) == 0) {
    uVar2 = 2;
  }
  else if ((param_1[0xc] & 1U) == 0) {
    uVar2 = 3;
    if ((param_1[0xc] & 2U) == 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  (**(code **)(*param_1 + 0x34))(param_1,uVar2);
  if ((param_1[0x13] != 0) && (uVar4 = 0, param_1[0x13] != 0)) {
    iVar5 = 0;
    do {
      if (uVar4 < (uint)param_1[0x13]) {
        iVar3 = *(int *)(param_1[0x12] + iVar5);
      }
      else {
        iVar3 = 0;
      }
      if ((*(uint *)(iVar3 + 0x2c) & 0x80) != 0) {
        if (uVar4 < (uint)param_1[0x13]) {
          piVar1 = *(int **)(iVar5 + param_1[0x12]);
        }
        else {
          piVar1 = (int *)0x0;
        }
        (**(code **)(*piVar1 + 0x1c))();
      }
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar4 < (uint)param_1[0x13]);
  }
  return;
}



/* 00015b54 FUN_00015b54 */

/* Boundary evidence: original MIPS .pdata 00015b54..00015c63. Semantic name remains unreviewed. */

undefined4 FUN_00015b54(int *param_1,int *param_2)

{
  uint uVar1;
  
  if ((param_1[0xb] & 0x100U) != 0) {
    if ((((param_1[2] <= *param_2) && (param_1[3] <= param_2[1])) &&
        (*param_2 <= param_1[4] + param_1[2])) && (param_2[1] <= param_1[5] + param_1[3])) {
      uVar1 = param_1[0xc];
      param_1[0xc] = uVar1 | 1;
      if ((param_1[0xb] & 0x80U) != 0) {
        if ((DAT_00022704 != (code *)0x0) && ((uVar1 >> 5 & 1) != 0)) {
          (*DAT_00022704)(1,param_1);
        }
        FUN_00013984(param_1);
      }
      (**(code **)(**(int **)(param_1[1] + 0x1c) + 0x3c))
                (*(int **)(param_1[1] + 0x1c),param_1[0xd],param_2);
      FUN_00016da0(param_1[1],(int)param_1);
      return 1;
    }
  }
  return 0;
}



/* 00015c64 FUN_00015c64 */

/* Boundary evidence: original MIPS .pdata 00015c64..00015dd7. Semantic name remains unreviewed. */

undefined4 FUN_00015c64(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if ((param_1[0xb] & 0x100U) != 0) {
    piVar2 = *(int **)(param_1[1] + 0x1c);
    if (((((param_1[2] <= *param_2) && (param_1[3] <= param_2[1])) &&
         (*param_2 <= param_1[4] + param_1[2])) &&
        ((param_2[1] <= param_1[5] + param_1[3] && ((param_1[0xc] & 1U) != 0)))) &&
       (param_1[0xd] != -1)) {
      param_1[0xc] = param_1[0xc] & 0xfffffffe;
      (**(code **)(*piVar2 + 0x40))(piVar2);
      if (((param_1[0xc] & 4U) == 0) || (uVar1 = 5, *(int *)(param_1[1] + 0x40) == 0)) {
        uVar1 = 2;
      }
      (**(code **)(*piVar2 + 0x38))(piVar2,param_1[0xd],uVar1);
      FUN_00016da0(param_1[1],0);
      FUN_00013984(param_1);
      return 1;
    }
    if ((param_1[0xc] & 1U) != 0) {
      param_1[0xc] = param_1[0xc] & 0xfffffffe;
      FUN_00013984(param_1);
      return 1;
    }
  }
  return 0;
}



/* 00015dd8 FUN_00015dd8 */

/* Boundary evidence: original MIPS .pdata 00015dd8..00015ef3. Semantic name remains unreviewed. */

undefined4 FUN_00015dd8(int *param_1,int *param_2)

{
  int *piVar1;
  
  if ((param_1[0xb] & 0x100U) != 0) {
    if (((((*param_2 < param_1[2]) || (param_2[1] < param_1[3])) ||
         (param_1[4] + param_1[2] < *param_2)) || (param_1[5] + param_1[3] < param_2[1])) &&
       ((param_1[0xc] & 1U) != 0)) {
      param_1[0xc] = param_1[0xc] & 0xfffffffe;
      (**(code **)(**(int **)(param_1[1] + 0x1c) + 0x44))
                (*(int **)(param_1[1] + 0x1c),param_1[0xd],param_2);
      if (((param_1[0xc] & 4U) != 0) && (*(int *)(param_1[1] + 0x40) != 0)) {
        piVar1 = *(int **)(param_1[1] + 0x1c);
        (**(code **)(*piVar1 + 0x38))(piVar1,param_1[0xd],5);
      }
      FUN_00013984(param_1);
      FUN_00016da0(param_1[1],0);
      return 1;
    }
  }
  return 0;
}



/* 00015ef4 FUN_00015ef4 */

/* Boundary evidence: original MIPS .pdata 00015ef4..00016063. Semantic name remains unreviewed. */

void FUN_00015ef4(int param_1,int param_2)

{
  ULONG_PTR UVar1;
  HDC hdcSrc;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int cx;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  if (*(HGDIOBJ *)(param_1 + 0x28) != (HGDIOBJ)0x0) {
    piVar2 = (int *)(param_1 + 0x38);
    if ((*(uint *)(param_1 + 0x30) & 0x10) == 0) {
      piVar2 = (int *)(param_1 + 8);
    }
    iVar3 = *piVar2;
    iVar4 = piVar2[1];
    cx = piVar2[2];
    iVar5 = piVar2[3];
    local_30 = iVar3;
    local_2c = iVar4;
    local_28 = cx;
    local_24 = iVar5;
    if ((*(uint *)(param_1 + 0x2c) & 0x200) == 0) {
      hdcSrc = (HDC)FUN_00016c18(*(HGDIOBJ *)(param_1 + 0x28));
      BitBlt(*(HDC *)(*(int *)(param_1 + 4) + 0x24),iVar3,iVar4,cx,iVar5,hdcSrc,cx * param_2,0,
             0xcc0020);
    }
    else {
      if ((*(uint *)(param_1 + 0x2c) & 0x400) != 0) {
        FUN_00016e7c(*(int *)(param_1 + 4),&local_30);
      }
      iVar5 = local_24;
      iVar4 = local_2c;
      iVar3 = local_30;
      UVar1 = FUN_00016c18(*(HGDIOBJ *)(param_1 + 0x28));
      TransparentImage(*(undefined4 *)(*(int *)(param_1 + 4) + 0x24),iVar3,iVar4,cx,iVar5,UVar1,
                       cx * param_2,0,cx,*(undefined4 *)(param_1 + 0x14),0xffff00);
    }
    SelectObject((HDC)DAT_00022724->SpinCount,DAT_00022724[1].DebugInfo);
    LeaveCriticalSection(DAT_00022724);
  }
  return;
}



/* 00016064 FUN_00016064 */

/* Boundary evidence: original MIPS .pdata 00016064..0001609f. Semantic name remains unreviewed. */

void FUN_00016064(undefined4 *param_1)

{
  param_1[0x13] = 0;
  LocalFree((HLOCAL)param_1[0x12]);
  param_1[0x12] = 0;
  *param_1 = &PTR_LAB_00020454;
  return;
}



/* 000160a0 FUN_000160a0 */

undefined4 * FUN_000160a0(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[1] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0x180;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x14] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 5;
  param_1[0xd] = 0xffffffff;
  param_1[0xc] = 0xe0;
  param_1[0xb] = param_1[0xb] & 0xffffffc3 | 3;
  *param_1 = &PTR_FUN_00020650;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x25] = 0x824;
  param_1[0x17] = &PTR_FUN_000202d0;
  param_1[0x22] = 0x181;
  param_1[0xa8] = 0xffff00;
  param_1[0x18] = 0;
  param_1[0x21] = 0;
  param_1[0x24] = 0;
  param_1[0x23] = 0;
  *(undefined2 *)(param_1 + 0x28) = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  *(undefined2 *)(param_1 + 0xa9) = 0;
  param_1[0xe1] = 0;
  param_1[0xe2] = 0;
  *(undefined2 *)(param_1 + 0xe3) = 0;
  param_1[0x11b] = 0;
  param_1[0x11c] = 0;
  param_1[0x11d] = 0;
  param_1[0x11e] = 0;
  param_1[0x127] = param_1[0x127] & 0x20000 ^ param_1[0x127] & 0xfffeffff;
  *(undefined1 *)(param_1 + 0x127) = 0;
  *(undefined1 *)((int)param_1 + 0x49d) = 2;
  param_1[0x11f] = 0xeeeeee;
  param_1[0x120] = 0x308cf6;
  param_1[0x121] = 0xa0a0a0;
  param_1[0x122] = 0x308cf6;
  param_1[0x126] = 0;
  param_1[0x125] = 0;
  param_1[0x124] = 0;
  param_1[0x123] = 0;
  param_1[0x127] = param_1[0x127] & 0x3ffff;
  return param_1;
}



/* 00016250 FUN_00016250 */

/* Boundary evidence: original MIPS .pdata 00016250..000162c3. Semantic name remains unreviewed. */

undefined4 * FUN_00016250(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00020650;
  param_1[0x17] = &PTR_LAB_00020454;
  param_1[0x13] = 0;
  LocalFree((HLOCAL)param_1[0x12]);
  param_1[0x12] = 0;
  *param_1 = &PTR_LAB_00020454;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000162c4 FUN_000162c4 */

/* Boundary evidence: original MIPS .pdata 000162c4..00016317. Semantic name remains unreviewed. */

void FUN_000162c4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00020650;
  param_1[0x17] = &PTR_LAB_00020454;
  param_1[0x13] = 0;
  LocalFree((HLOCAL)param_1[0x12]);
  param_1[0x12] = 0;
  *param_1 = &PTR_LAB_00020454;
  return;
}



/* 00016318 FUN_00016318 */

/* Boundary evidence: original MIPS .pdata 00016318..000163cf. Semantic name remains unreviewed. */

void FUN_00016318(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  if ((*(uint *)(param_1 + 0x2c) & 0x40) == 0) {
    *(undefined4 *)(param_1 + 4) = param_4;
    *(undefined4 *)(param_1 + 8) = *param_3;
    *(undefined4 *)(param_1 + 0xc) = param_3[1];
    *(undefined4 *)(param_1 + 0x10) = param_3[2];
    *(undefined4 *)(param_1 + 0x14) = param_3[3];
    if (param_2 != -1) {
      FUN_00013a68(param_1,param_2);
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x40;
  }
  (**(code **)(*(int *)(param_1 + 0x5c) + 0x18))((int *)(param_1 + 0x5c),0xffffffff,param_3,param_4)
  ;
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xfffffbff;
  return;
}



/* 000163d0 FUN_000163d0 */

/* Boundary evidence: original MIPS .pdata 000163d0..000164f3. Semantic name remains unreviewed. */

void FUN_000163d0(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  FUN_00015ef4(param_1,param_2);
  uVar1 = param_2 & 3;
  if (((int)param_2 < 0) && (uVar1 != 0)) {
    uVar1 = uVar1 - 4;
  }
  uVar2 = *(uint *)(param_1 + 0x49c);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)((uVar1 + 0x11f) * 4 + param_1);
  if ((uVar2 & 0x40000) != 0) {
    *(undefined4 *)(param_1 + 0x2a0) = *(undefined4 *)((uVar1 + 0x123) * 4 + param_1);
  }
  if (uVar1 == 1) {
    uVar1 = uVar2 & 0x10000;
joined_r0x000164b8:
    if (uVar1 != 0) {
      *(uint *)(param_1 + 100) = (uVar2 & 0xff) + *(int *)(param_1 + 0x46c);
      *(uint *)(param_1 + 0x68) = (uint)*(byte *)(param_1 + 0x49d) + *(int *)(param_1 + 0x470);
      *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x474);
      *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x478);
      goto LAB_0001647c;
    }
  }
  else if (uVar1 == 3) {
    uVar1 = uVar2 & 0x20000;
    goto joined_r0x000164b8;
  }
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x46c);
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x470);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x474);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x478);
LAB_0001647c:
  (**(code **)(*(int *)(param_1 + 0x5c) + 0x1c))();
  return;
}



/* 000164f4 FUN_000164f4 */

/* Boundary evidence: original MIPS .pdata 000164f4..000165a7. Semantic name remains unreviewed. */

void FUN_000164f4(int *param_1,short *param_2,int param_3)

{
  int iVar1;
  
  FUN_00011090(param_1 + 0x17,param_2,0);
  param_1[0x27] = (uint)param_1[0x127] >> 0x13 & 1;
  if ((param_3 != 0) && ((param_1[0xb] & 0x80U) != 0)) {
    if ((param_1[1] != 0) &&
       ((iVar1 = *(int *)(param_1[1] + 0x1c), iVar1 != 0 && (*(int *)(iVar1 + 0x60) != 0)))) {
      (**(code **)(*param_1 + 0x1c))(param_1);
      return;
    }
    (**(code **)*param_1)(param_1);
  }
  return;
}



/* 00016730 FUN_00016730 */

/* Boundary evidence: original MIPS .pdata 00016730..000167cb. Semantic name remains unreviewed. */

void FUN_00016730(int *param_1,undefined4 param_2)

{
  HLOCAL pvVar1;
  int iVar2;
  
  if ((HLOCAL)*param_1 == (HLOCAL)0x0) {
    param_1[2] = param_1[4];
    pvVar1 = LocalAlloc(0x40,param_1[4] << 2);
  }
  else {
    if (param_1[1] != param_1[2]) goto LAB_00016798;
    iVar2 = param_1[4] + param_1[2];
    param_1[2] = iVar2;
    pvVar1 = LocalReAlloc((HLOCAL)*param_1,iVar2 * 4,2);
  }
  *param_1 = (int)pvVar1;
LAB_00016798:
  *(undefined4 *)(param_1[1] * 4 + *param_1) = param_2;
  param_1[1] = param_1[1] + 1;
  return;
}



/* 000167cc FUN_000167cc */

undefined4 * FUN_000167cc(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(undefined1 *)((int)param_1 + 0x31) = 1;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *param_1 = &PTR_FUN_0002068c;
  param_1[1] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0x182;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xc] = param_1[0xc] & 0xffff;
  return param_1;
}



/* 00016838 FUN_00016838 */

/* Boundary evidence: original MIPS .pdata 00016838..00016857. Semantic name remains unreviewed. */

void FUN_00016838(int param_1)

{
  FUN_00016858(param_1,*(uint *)(param_1 + 0x30) & 0xff);
  return;
}



/* 00016858 FUN_00016858 */

/* Boundary evidence: original MIPS .pdata 00016858..00016ab7. Semantic name remains unreviewed. */

void FUN_00016858(int param_1,int param_2)

{
  ULONG_PTR UVar1;
  HDC hdcSrc;
  int iVar2;
  int iVar3;
  int cx;
  int iVar4;
  int y;
  int cy;
  int xSrc;
  int ySrc;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  if (*(HGDIOBJ *)(param_1 + 0x28) != (HGDIOBJ)0x0) {
    iVar2 = *(int *)(param_1 + 0x20);
    iVar3 = *(int *)(param_1 + 0x24);
    iVar4 = *(int *)(param_1 + 8);
    y = *(int *)(param_1 + 0xc);
    cx = *(int *)(param_1 + 0x10);
    cy = *(int *)(param_1 + 0x14);
    xSrc = *(int *)(param_1 + 0x18);
    ySrc = *(int *)(param_1 + 0x1c);
    local_38 = iVar4;
    local_34 = y;
    local_30 = cx;
    local_2c = cy;
    if ((*(uint *)(param_1 + 0x2c) & 0x200) == 0) {
      hdcSrc = (HDC)FUN_00016c18(*(HGDIOBJ *)(param_1 + 0x28));
      if ((*(uint *)(param_1 + 0x2c) & 0x1000) == 0) {
        if ((*(ushort *)(param_1 + 0x32) & 1) == 0) {
          BitBlt(*(HDC *)(*(int *)(param_1 + 4) + 0x24),iVar4,y,cx,cy,hdcSrc,cx * param_2,0,0xcc0020
                );
        }
        else {
          StretchBlt(*(HDC *)(*(int *)(param_1 + 4) + 0x24),iVar4,y,cx,cy,hdcSrc,0,0,
                     *(int *)(param_1 + 0x34),*(int *)(param_1 + 0x38),0xcc0020);
        }
      }
      else {
        StretchBlt(*(HDC *)(*(int *)(param_1 + 4) + 0x24),iVar4,y,cx,cy,hdcSrc,xSrc,ySrc,iVar2,iVar3
                   ,0xcc0020);
      }
    }
    else {
      if ((*(uint *)(param_1 + 0x2c) & 0x400) != 0) {
        FUN_00016e7c(*(int *)(param_1 + 4),&local_38);
      }
      iVar4 = local_2c;
      iVar3 = local_34;
      iVar2 = local_38;
      UVar1 = FUN_00016c18(*(HGDIOBJ *)(param_1 + 0x28));
      if ((*(ushort *)(param_1 + 0x32) & 1) == 0) {
        TransparentImage(*(undefined4 *)(*(int *)(param_1 + 4) + 0x24),iVar2,iVar3,cx,iVar4,UVar1,
                         cx * param_2,0,cx,*(undefined4 *)(param_1 + 0x14),0xffff00);
      }
      else {
        TransparentImage(*(undefined4 *)(*(int *)(param_1 + 4) + 0x24),iVar2,iVar3,cx,iVar4,UVar1,0,
                         0,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),0xffff00)
        ;
      }
    }
    SelectObject((HDC)DAT_00022724->SpinCount,DAT_00022724[1].DebugInfo);
    LeaveCriticalSection(DAT_00022724);
  }
  return;
}



/* 00016ab8 FUN_00016ab8 */

/* Boundary evidence: original MIPS .pdata 00016ab8..00016c17. Semantic name remains unreviewed. */

void FUN_00016ab8(int param_1,int param_2,int *param_3)

{
  HDC hdcSrc;
  int iVar1;
  int x;
  int y;
  int iVar2;
  int iVar3;
  int cx;
  int cy;
  int y1;
  
  iVar3 = *(int *)(param_1 + 0x10);
  x = *(int *)(param_1 + 8);
  iVar1 = *param_3;
  y = *(int *)(param_1 + 0xc);
  cy = *(int *)(param_1 + 0x14);
  iVar2 = 0;
  y1 = 0;
  cx = iVar3;
  if (x < iVar1) {
    iVar2 = iVar1 - x;
    x = x + iVar2;
    if (param_3[2] + iVar1 < iVar3 + *(int *)(param_1 + 8)) {
      cx = (param_3[2] + iVar1) - x;
    }
  }
  iVar1 = param_3[1];
  if (*(int *)(param_1 + 0xc) < iVar1) {
    y1 = iVar1 - *(int *)(param_1 + 0xc);
    y = y + y1;
    if (param_3[3] + iVar1 < *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc)) {
      cy = (param_3[3] - y) + iVar1;
    }
  }
  hdcSrc = (HDC)FUN_00016c18(*(HGDIOBJ *)(param_1 + 0x28));
  BitBlt(*(HDC *)(*(int *)(param_1 + 4) + 0x24),x,y,cx,cy,hdcSrc,iVar3 * param_2 + iVar2,y1,0xcc0020
        );
  SelectObject((HDC)DAT_00022724->SpinCount,DAT_00022724[1].DebugInfo);
  LeaveCriticalSection(DAT_00022724);
  return;
}



/* 00016c18 FUN_00016c18 */

/* Boundary evidence: original MIPS .pdata 00016c18..00016ccf. Semantic name remains unreviewed. */

ULONG_PTR FUN_00016c18(HGDIOBJ param_1)

{
  LPCRITICAL_SECTION p_Var1;
  HDC hdc;
  HDC pHVar2;
  PRTL_CRITICAL_SECTION_DEBUG p_Var3;
  
  if (DAT_00022724 == (LPCRITICAL_SECTION)0x0) {
    p_Var1 = (LPCRITICAL_SECTION)__2_YAPAXI_Z(0x1c);
    if (p_Var1 == (LPCRITICAL_SECTION)0x0) {
      DAT_00022724 = (LPCRITICAL_SECTION)0x0;
    }
    else {
      InitializeCriticalSection(p_Var1);
      hdc = GetDC((HWND)0x0);
      pHVar2 = CreateCompatibleDC(hdc);
      p_Var1->SpinCount = (ULONG_PTR)pHVar2;
      ReleaseDC((HWND)0x0,hdc);
      p_Var1[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
      DAT_00022724 = p_Var1;
    }
  }
  EnterCriticalSection(DAT_00022724);
  p_Var3 = SelectObject((HDC)DAT_00022724->SpinCount,param_1);
  p_Var1 = DAT_00022724;
  DAT_00022724[1].DebugInfo = p_Var3;
  return p_Var1->SpinCount;
}



/* 00016cd0 FUN_00016cd0 */

/* Boundary evidence: original MIPS .pdata 00016cd0..00016d47. Semantic name remains unreviewed. */

undefined4 * FUN_00016cd0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000206c0;
  if (((HDC)param_1[10] != (HDC)0x0) && ((HWND)param_1[6] != (HWND)0x0)) {
    ReleaseDC((HWND)param_1[6],(HDC)param_1[10]);
  }
  param_1[2] = 0;
  LocalFree((HLOCAL)param_1[1]);
  param_1[1] = 0;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00016d48 FUN_00016d48 */

/* Boundary evidence: original MIPS .pdata 00016d48..00016d9f. Semantic name remains unreviewed. */

void FUN_00016d48(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000206c0;
  if (((HDC)param_1[10] != (HDC)0x0) && ((HWND)param_1[6] != (HWND)0x0)) {
    ReleaseDC((HWND)param_1[6],(HDC)param_1[10]);
  }
  param_1[2] = 0;
  LocalFree((HLOCAL)param_1[1]);
  param_1[1] = 0;
  return;
}



/* 00016da0 FUN_00016da0 */

/* Boundary evidence: original MIPS .pdata 00016da0..00016e7b. Semantic name remains unreviewed. */

void FUN_00016da0(int param_1,int param_2)

{
  HWND pHVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x20);
  *(int *)(param_1 + 0x20) = param_2;
  if (param_2 == 0) {
    if (((iVar2 != 0) && ((*(uint *)(iVar2 + 0x2c) & 0x3f) == 3)) &&
       ((*(uint *)(iVar2 + 0x30) & 4) != 0)) {
      pHVar1 = *(HWND *)(*(int *)(param_1 + 0x1c) + 0x50);
      if (pHVar1 != (HWND)0x0) {
        KillTimer(pHVar1,0x3f5);
      }
      pHVar1 = *(HWND *)(*(int *)(param_1 + 0x1c) + 0x50);
      if (pHVar1 != (HWND)0x0) {
        KillTimer(pHVar1,0x3f6);
      }
    }
  }
  else if (((*(uint *)(param_2 + 0x2c) & 0x3f) == 3) && ((*(uint *)(param_2 + 0x30) & 4) != 0)) {
    SetTimer(*(HWND *)(*(int *)(param_1 + 0x1c) + 0x50),0x3f5,
             *(UINT *)(*(int *)(param_1 + 0x1c) + 0x70),(TIMERPROC)0x0);
    *(undefined4 *)(param_1 + 0x40) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}



/* 00016e7c FUN_00016e7c */

/* Boundary evidence: original MIPS .pdata 00016e7c..00016f33. Semantic name remains unreviewed. */

void FUN_00016e7c(int param_1,int *param_2)

{
  HDC hdcSrc;
  int cy;
  int cx;
  int y;
  int x;
  
  if (*(HGDIOBJ *)(param_1 + 0x2c) != (HGDIOBJ)0x0) {
    if (param_2 == (int *)0x0) {
      param_2 = (int *)(param_1 + 0x30);
    }
    x = *param_2;
    y = param_2[1];
    cx = param_2[2];
    cy = param_2[3];
    hdcSrc = (HDC)FUN_00016c18(*(HGDIOBJ *)(param_1 + 0x2c));
    BitBlt(*(HDC *)(param_1 + 0x24),x,y,cx,cy,hdcSrc,x,y,0xcc0020);
    SelectObject((HDC)DAT_00022724->SpinCount,DAT_00022724[1].DebugInfo);
    LeaveCriticalSection(DAT_00022724);
  }
  return;
}



/* 00016f34 FUN_00016f34 */

/* Boundary evidence: original MIPS .pdata 00016f34..00016fef. Semantic name remains unreviewed. */

void FUN_00016f34(int param_1)

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



/* 00016ff0 FUN_00016ff0 */

/* Boundary evidence: original MIPS .pdata 00016ff0..0001709f. Semantic name remains unreviewed. */

void FUN_00016ff0(int param_1,int *param_2)

{
  int iVar1;
  
  FUN_00016c18((HGDIOBJ)0x0);
  iVar1 = *(int *)(param_1 + 0x1c);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x50) != 0)) && ((*(uint *)(iVar1 + 0x5c) & 0x20) != 0)) {
    BitBlt(*(HDC *)(param_1 + 0x28),*param_2,param_2[1],param_2[2],param_2[3],
           *(HDC *)(param_1 + 0x24),*param_2,param_2[1],0xcc0020);
  }
  SelectObject((HDC)DAT_00022724->SpinCount,DAT_00022724[1].DebugInfo);
  LeaveCriticalSection(DAT_00022724);
  return;
}



/* 000170a0 FUN_000170a0 */

/* Boundary evidence: original MIPS .pdata 000170a0..00017187. Semantic name remains unreviewed. */

void FUN_000170a0(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5,
                 int param_6,int param_7,int *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  FUN_00016730((int *)(param_1 + 4),param_2);
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



/* 00017188 FUN_00017188 */

/* Boundary evidence: original MIPS .pdata 00017188..0001727b. Semantic name remains unreviewed. */

void FUN_00017188(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 short *param_6,int param_7,int param_8)

{
  int iVar1;
  
  FUN_00016730((int *)(param_1 + 4),param_2);
  (**(code **)(*param_2 + 0x18))(param_2,param_3,param_4,param_1);
  if (DAT_00021690 == 0) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
  }
  if ((param_5 < 0x18) && (*(int *)(DAT_00021690 + 4) != 0)) {
    iVar1 = *(int *)((param_5 + 2) * 4 + DAT_00021690);
  }
  else {
    iVar1 = 0;
  }
  param_2[0xc] = iVar1;
  param_2[0xd] = param_7;
  param_2[0xe] = param_8;
  FUN_00011090(param_2,param_6,0);
  return;
}



/* 0001727c FUN_0001727c */

/* Boundary evidence: original MIPS .pdata 0001727c..0001746b. Semantic name remains unreviewed. */

void FUN_0001727c(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,short *param_7,int *param_8,int *param_9,int param_10,int param_11,
                 int param_12,uint param_13)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  FUN_00016730((int *)(param_1 + 4),param_2);
  (**(code **)(*param_2 + 0x18))(param_2,param_3,param_4,param_1);
  uVar5 = (param_11 << 0x10 ^ param_2[0x127]) & 0x10000U ^ param_2[0x127];
  param_2[0xb] = (param_12 << 9 ^ param_2[0xb]) & 0x200U ^ param_2[0xb];
  param_2[0xd] = param_5;
  param_2[0x127] = ((param_13 & 1) << 0x12 | uVar5 & 0x10000) << 1 | uVar5 & 0xfff5ffff;
  if (param_8 == (int *)0x0) {
    iVar1 = param_2[2];
    iVar2 = param_2[3];
    iVar3 = param_2[4];
    iVar4 = param_2[5];
  }
  else {
    iVar3 = param_8[2];
    iVar4 = param_8[3];
    iVar1 = param_2[2] + *param_8;
    iVar2 = param_2[3] + param_8[1];
  }
  param_2[0x11e] = iVar4;
  param_2[0x11b] = iVar1;
  param_2[0x11c] = iVar2;
  param_2[0x11d] = iVar3;
  param_2[0x1c] = iVar4;
  iVar4 = DAT_00021690;
  param_2[0x19] = iVar1;
  param_2[0x1a] = iVar2;
  param_2[0x1b] = iVar3;
  if (iVar4 == 0) {
    MessageBoxW((HWND)0x0,L"ResManager is not Inital!!",L"Warning",0);
    iVar4 = DAT_00021690;
  }
  if ((param_6 < 0x18) && (*(int *)(iVar4 + 4) != 0)) {
    iVar1 = *(int *)((param_6 + 2) * 4 + iVar4);
  }
  else {
    iVar1 = 0;
  }
  param_2[0x23] = iVar1;
  if (param_9 != (int *)0x0) {
    param_2[0x11f] = *param_9;
    param_2[0x120] = param_9[1];
    param_2[0x121] = param_9[2];
    param_2[0x122] = param_9[3];
  }
  param_2[0x25] = param_10;
  FUN_00011090(param_2 + 0x17,param_7,0);
  param_2[0x27] = (uint)param_2[0x127] >> 0x13 & 1;
  return;
}



/* 0001746c FUN_0001746c */

undefined4 FUN_0001746c(void)

{
  return DAT_00021478;
}



/* 00017478 FUN_00017478 */

/* Boundary evidence: original MIPS .pdata 00017478..000174bb. Semantic name remains unreviewed. */

void FUN_00017478(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0001f070;
  UnmapViewOfFile((LPCVOID)param_1[0x1f]);
  CloseHandle((HANDLE)param_1[0x1e]);
  return;
}



/* 000174bc FUN_000174bc */

/* Boundary evidence: original MIPS .pdata 000174bc..0001759f. Semantic name remains unreviewed. */

undefined4 FUN_000174bc(int param_1)

{
  HANDLE hFileMappingObject;
  LPVOID pvVar1;
  wchar_t *lpText;
  
  hFileMappingObject =
       CreateFileMappingW((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,4,0,0x68c,L"MgrMcmShm");
  *(HANDLE *)(param_1 + 0x78) = hFileMappingObject;
  if (hFileMappingObject == (HANDLE)0x0) {
    GetLastError();
    lpText = L"MICOM Shared Memory CreateFileMapping FAIL";
  }
  else {
    pvVar1 = MapViewOfFile(hFileMappingObject,4,0,0,0x68c);
    *(LPVOID *)(param_1 + 0x7c) = pvVar1;
    if (pvVar1 != (LPVOID)0x0) {
      return 1;
    }
    CloseHandle(*(HANDLE *)(param_1 + 0x78));
    *(undefined4 *)(param_1 + 0x78) = 0;
    GetLastError();
    lpText = L"MICOM Shared Memory MapViewOfFile FAIL";
  }
  MessageBoxW((HWND)0x0,lpText,L"Warning",0);
  return 0;
}



/* 000175a0 FUN_000175a0 */

/* Boundary evidence: original MIPS .pdata 000175a0..000175fb. Semantic name remains unreviewed. */

void FUN_000175a0(void)

{
  FILE *_File;
  
  _File = _wfopen(L"/Storage Card2/Antitheft.cfg",L"wb");
  if (_File != (FILE *)0x0) {
    fwrite(&DAT_00021470,4,1,_File);
    fclose(_File);
  }
  return;
}



/* 000175fc FUN_000175fc */

void FUN_000175fc(void)

{
  DAT_00021470 = 0;
  return;
}



/* 0001760c FUN_0001760c */

void FUN_0001760c(int param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 4) = 1;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined4 *)(param_1 + 0x1c));
  uVar1 = param_1 + 0x1fU & 3;
  puVar2 = (uint *)((param_1 + 0x1fU) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 1U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x23U & 3;
  puVar2 = (uint *)((param_1 + 0x23U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x27U & 3;
  puVar2 = (uint *)((param_1 + 0x27U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x2bU & 3;
  puVar2 = (uint *)((param_1 + 0x2bU) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x2fU & 3;
  puVar2 = (uint *)((param_1 + 0x2fU) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x33U & 3;
  puVar2 = (uint *)((param_1 + 0x33U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x37U & 3;
  puVar2 = (uint *)((param_1 + 0x37U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x47U & 3;
  puVar2 = (uint *)((param_1 + 0x47U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x4bU & 3;
  puVar2 = (uint *)((param_1 + 0x4bU) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 1U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x53U & 3;
  puVar2 = (uint *)((param_1 + 0x53U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0x809U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x57U & 3;
  puVar2 = (uint *)((param_1 + 0x57U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 2U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x1cU & 3;
  puVar2 = (uint *)((param_1 + 0x1cU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 1 << uVar1 * 8;
  uVar1 = param_1 + 0x20U & 3;
  puVar2 = (uint *)((param_1 + 0x20U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x24U & 3;
  puVar2 = (uint *)((param_1 + 0x24U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x28U & 3;
  puVar2 = (uint *)((param_1 + 0x28U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x2cU & 3;
  puVar2 = (uint *)((param_1 + 0x2cU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x30U & 3;
  puVar2 = (uint *)((param_1 + 0x30U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x34U & 3;
  puVar2 = (uint *)((param_1 + 0x34U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x44U & 3;
  puVar2 = (uint *)((param_1 + 0x44U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x48U & 3;
  puVar2 = (uint *)((param_1 + 0x48U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 1 << uVar1 * 8;
  uVar1 = param_1 + 0x50U & 3;
  puVar2 = (uint *)((param_1 + 0x50U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0x809 << uVar1 * 8;
  uVar1 = param_1 + 0x54U & 3;
  puVar2 = (uint *)((param_1 + 0x54U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 2 << uVar1 * 8;
  return;
}



/* 0001769c FUN_0001769c */

/* Boundary evidence: original MIPS .pdata 0001769c..000176e7. Semantic name remains unreviewed. */

undefined4 * FUN_0001769c(undefined4 *param_1,uint param_2)

{
  FUN_00017478(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000176e8 FUN_000176e8 */

/* Boundary evidence: original MIPS .pdata 000176e8..000177af. Semantic name remains unreviewed. */

void FUN_000176e8(int param_1)

{
  FILE *_File;
  size_t sVar1;
  
  _File = _wfopen(L"/Storage Card2/Antitheft.cfg",L"rb");
  if (_File == (FILE *)0x0) {
    DAT_00021470 = 0;
  }
  else {
    sVar1 = fread(&DAT_00021470,1,4,_File);
    fclose(_File);
    if (sVar1 != 4) {
      DAT_00021470 = 0;
    }
    if (DAT_00021470 < 0) {
      FUN_0001760c(param_1);
    }
  }
  return;
}



/* 000177b0 FUN_000177b0 */

/* Boundary evidence: original MIPS .pdata 000177b0..0001787f. Semantic name remains unreviewed. */

void FUN_000177b0(int param_1)

{
  FILE *_File;
  size_t sVar1;
  byte bVar2;
  int iVar3;
  
  _File = _wfopen(L"/Storage Card2/MgrSys.cfg",L"rb");
  if (_File != (FILE *)0x0) {
    sVar1 = fread((void *)(param_1 + 4),1,0x55,_File);
    fclose(_File);
    if (sVar1 != 0x55) {
      FUN_0001760c(param_1);
    }
    bVar2 = 0;
    iVar3 = 0;
    do {
      bVar2 = *(byte *)(param_1 + 4 + iVar3) ^ bVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x54);
    if (bVar2 == *(byte *)(param_1 + 0x58)) {
      return;
    }
  }
  FUN_0001760c(param_1);
  return;
}



/* 00017880 FUN_00017880 */

/* Boundary evidence: original MIPS .pdata 00017880..000178eb. Semantic name remains unreviewed. */

undefined4 * FUN_00017880(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0001f070;
  FUN_000177b0((int)param_1);
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x1a] = 0;
  param_1[0x19] = 0;
  param_1[0x1f] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  param_1[0x1d] = 1;
  FUN_000174bc((int)param_1);
  FUN_000176e8((int)param_1);
  return param_1;
}



/* 000178ec FUN_000178ec */

/* Boundary evidence: original MIPS .pdata 000178ec..0001793f. Semantic name remains unreviewed. */

void FUN_000178ec(void)

{
  undefined4 *puVar1;
  
  if (DAT_00021474 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x80);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00021474 = (undefined4 *)0x0;
    }
    else {
      DAT_00021474 = FUN_00017880(puVar1);
    }
  }
  return;
}



/* 00017940 FUN_00017940 */

/* Boundary evidence: original MIPS .pdata 00017940..0001798f. Semantic name remains unreviewed. */

void FUN_00017940(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0001f1b0;
  if ((HMODULE)param_1[3] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)param_1[3]);
  }
  param_1[3] = 0;
  param_1[4] = 0x20;
  return;
}



/* 00017990 FUN_00017990 */

/* Boundary evidence: original MIPS .pdata 00017990..00017a13. Semantic name remains unreviewed. */

undefined4 * FUN_00017990(void)

{
  undefined4 *puVar1;
  
  if (DAT_00021480 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00021480 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_0001f1b0;
      puVar1[3] = 0;
      puVar1[4] = 0x20;
      memset(puVar1 + 1,0,8);
      DAT_00021480 = puVar1;
    }
  }
  return DAT_00021480;
}



/* 00017a14 FUN_00017a14 */

/* Boundary evidence: original MIPS .pdata 00017a14..00017a9f. Semantic name remains unreviewed. */

void FUN_00017a14(int param_1)

{
  FILE *_File;
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  iVar2 = 0;
  do {
    bVar1 = *(byte *)(param_1 + 4 + iVar2) ^ bVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  *(byte *)(param_1 + 8) = bVar1;
  _File = _wfopen(L"/Storage Card2/Lang.cfg",L"wb");
  if (_File != (FILE *)0x0) {
    fwrite((void *)(param_1 + 4),8,1,_File);
    fclose(_File);
  }
  return;
}



/* 00017aa0 FUN_00017aa0 */

undefined4 FUN_00017aa0(ushort *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort *puVar4;
  
  uVar3 = 0;
  puVar4 = param_1;
  if (param_2 != 0) {
    do {
      uVar1 = uVar3;
      puVar2 = puVar4;
      if (*puVar4 == param_3) {
        for (; uVar1 < param_2; uVar1 = uVar1 + 1) {
          if (puVar2[1] == 0) {
            param_1[uVar1] = 0;
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
    } while (uVar3 < param_2);
  }
  return 1;
}



/* 00017b28 FUN_00017b28 */

/* Boundary evidence: original MIPS .pdata 00017b28..00017b73. Semantic name remains unreviewed. */

undefined4 * FUN_00017b28(undefined4 *param_1,uint param_2)

{
  FUN_00017940(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00017b74 FUN_00017b74 */

/* Boundary evidence: original MIPS .pdata 00017b74..00017dfb. Semantic name remains unreviewed. */

bool FUN_00017b74(int param_1,int param_2)

{
  HMODULE pHVar1;
  wchar_t *lpLibFileName;
  
  if (0x1f < param_2) {
    param_2 = 2;
  }
  if (*(HMODULE *)(param_1 + 0xc) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x20;
  }
  *(int *)(param_1 + 0x10) = param_2;
  switch(param_2) {
  case 0:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllAra.dll";
    break;
  case 1:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllDut.dll";
    break;
  default:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllEng.dll";
    break;
  case 3:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllFre.dll";
    break;
  case 4:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllGer.dll";
    break;
  case 5:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllIta.dll";
    break;
  case 6:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllPor.dll";
    break;
  case 7:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllRus.dll";
    break;
  case 8:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSpa.dll";
    break;
  case 9:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllRom.dll";
    break;
  case 10:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllTur.dll";
    break;
  case 0xb:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllPol.dll";
    break;
  case 0xc:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllPTBR.dll";
    break;
  case 0xd:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllJap.dll";
    break;
  case 0xe:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllGre.dll";
    break;
  case 0xf:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllCro.dll";
    break;
  case 0x10:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllCze.dll";
    break;
  case 0x11:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSloven.dll";
    break;
  case 0x12:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllHun.dll";
    break;
  case 0x13:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSlo.dll";
    break;
  case 0x14:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllBul.dll";
    break;
  case 0x15:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllHeb.dll";
    break;
  case 0x16:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSer.dll";
    break;
  case 0x17:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllUka.dll";
    break;
  case 0x18:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSwe.dll";
    break;
  case 0x19:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllDan.dll";
    break;
  case 0x1a:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllFin.dll";
    break;
  case 0x1b:
  case 0x1e:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllNor.dll";
    break;
  case 0x1f:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllKor.dll";
  }
  pHVar1 = LoadLibraryW(lpLibFileName);
  *(HMODULE *)(param_1 + 0xc) = pHVar1;
  *(int *)(param_1 + 4) = param_2;
  FUN_00017a14(param_1);
  PostMessageW((HWND)0xffff,DAT_0002168c,0,param_2);
  FUN_00011080((uint)(param_2 == 0));
  return *(int *)(param_1 + 0xc) != 0;
}



/* 00017dfc FUN_00017dfc */

/* Boundary evidence: original MIPS .pdata 00017dfc..00017e77. Semantic name remains unreviewed. */

undefined * FUN_00017dfc(int param_1,UINT param_2)

{
  size_t sVar1;
  
  memset(&DAT_00021484,0,0x208);
  LoadStringW(*(HINSTANCE *)(param_1 + 0xc),param_2,(LPWSTR)&DAT_00021484,0x104);
  sVar1 = wcslen((wchar_t *)&DAT_00021484);
  FUN_00017aa0((ushort *)&DAT_00021484,sVar1,0x200f);
  return &DAT_00021484;
}



/* 00017e78 FUN_00017e78 */

/* Boundary evidence: original MIPS .pdata 00017e78..00017ed7. Semantic name remains unreviewed. */

void FUN_00017e78(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0001fbac;
  if (param_1[0x136] != 0) {
    __3_YAXPAX_Z();
  }
  FUN_00012d18(param_1);
  return;
}



/* 00017ed8 Unwind@00017ed8 */

/* Boundary evidence: original MIPS .pdata 00017ed8..00017f07. Semantic name remains unreviewed. */

void Unwind_00017ed8(void)

{
  undefined4 *in_v0;
  
  FUN_00012d18((undefined4 *)*in_v0);
  return;
}



/* 00017f08 FUN_00017f08 */

/* Boundary evidence: original MIPS .pdata 00017f08..00017f6b. Semantic name remains unreviewed. */

bool FUN_00017f08(int param_1)

{
  HMODULE pHVar1;
  
  pHVar1 = GetModuleHandleW(L"LangMgr.dll");
  *(HMODULE *)(param_1 + 0x4fc) = pHVar1;
  if (pHVar1 == (HMODULE)0x0) {
    pHVar1 = LoadLibraryW(L"LangMgr.dll");
    *(HMODULE *)(param_1 + 0x4fc) = pHVar1;
  }
  return *(int *)(param_1 + 0x4fc) != 0;
}



/* 00017f6c FUN_00017f6c */

/* Boundary evidence: original MIPS .pdata 00017f6c..00018037. Semantic name remains unreviewed. */

undefined2 * FUN_00017f6c(int param_1,int param_2)

{
  if ((DAT_000218a4 & 1) == 0) {
    DAT_000218a4 = DAT_000218a4 | 1;
    DAT_000218a0 = wcslen((wchar_t *)(param_1 + 200));
  }
  if (DAT_00021698 == 0) {
    wsprintfW(&DAT_00021698,L"%s%s",param_1 + 200,(&PTR_u_test_button_bmp_00021194)[param_2]);
  }
  else {
    wcscpy(&DAT_00021698 + DAT_000218a0,(wchar_t *)(&PTR_u_test_button_bmp_00021194)[param_2]);
  }
  return &DAT_00021698;
}



/* 00018038 FUN_00018038 */

/* Boundary evidence: original MIPS .pdata 00018038..00018167. Semantic name remains unreviewed. */

undefined4 * FUN_00018038(undefined4 *param_1)

{
  int iVar1;
  void *_Dst;
  wchar_t local_e0;
  undefined1 auStack_de [198];
  uint local_18;
  
  local_18 = DAT_00021450;
  FUN_00012c94(param_1);
  *param_1 = &PTR_FUN_0001fbac;
  param_1[0x13e] = 0;
  param_1[0x13f] = 0;
  FUN_00017f08((int)param_1);
  local_e0 = L'\0';
  memset(auStack_de,0,0xc6);
  iVar1 = FUN_00013698((HKEY)0x80000002,L"LGE\\SystemInfo",L"UI_TYPE",0);
  _snwprintf(&local_e0,99,L"%s%s\\",L"img/",(&PTR_DAT_00021448)[iVar1 == 1]);
  FUN_0001354c((int)param_1,&local_e0);
  FUN_000134f8((int)param_1,L"font/");
  _Dst = (void *)__2_YAPAXI_Z(0x394);
  param_1[0x136] = _Dst;
  memset(_Dst,0,0x394);
  FUN_00012d6c((int)param_1,0xe5);
  FUN_0001ab10(local_18);
  return param_1;
}



/* 00018168 Unwind@00018168 */

/* Boundary evidence: original MIPS .pdata 00018168..00018197. Semantic name remains unreviewed. */

void Unwind_00018168(void)

{
  int in_v0;
  
  FUN_00012d18(*(undefined4 **)(in_v0 + -0xe8));
  return;
}



/* 00018198 FUN_00018198 */

/* Boundary evidence: original MIPS .pdata 00018198..000181e3. Semantic name remains unreviewed. */

undefined4 * FUN_00018198(undefined4 *param_1,uint param_2)

{
  FUN_00017e78(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000181e4 FUN_000181e4 */

/* Boundary evidence: original MIPS .pdata 000181e4..0001824f. Semantic name remains unreviewed. */

void FUN_000181e4(void)

{
  undefined4 *puVar1;
  
  if (DAT_00021690 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x500);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00021690 = (undefined4 *)0x0;
    }
    else {
      DAT_00021690 = FUN_00018038(puVar1);
    }
  }
  return;
}



/* 00018250 Unwind@00018250 */

/* Boundary evidence: original MIPS .pdata 00018250..0001827f. Semantic name remains unreviewed. */

void Unwind_00018250(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 00018280 FUN_00018280 */

/* Boundary evidence: original MIPS .pdata 00018280..000185b3. Semantic name remains unreviewed. */

void FUN_00018280(int param_1)

{
  undefined4 *puVar1;
  short *psVar2;
  int *piVar3;
  int local_b8 [36];
  
  local_b8[2] = 0x53595c;
  local_b8[0] = 0xe6e6e6;
  local_b8[1] = 0;
  local_b8[3] = 0;
  local_b8[0x14] = 0;
  local_b8[0x15] = 0;
  local_b8[0x16] = 800;
  local_b8[0x17] = 0x1e0;
  FUN_00014e2c(param_1,(int *)(param_1 + 700),0xffffffff,local_b8 + 0x14,1000,0);
  local_b8[0xd] = 0x4a;
  piVar3 = (int *)(param_1 + 0x318);
  local_b8[0xc] = 0x83;
  local_b8[0xe] = 0x21b;
  local_b8[0xf] = 0x14c;
  FUN_00014ec0(param_1,piVar3,0xa0,local_b8 + 0xc,1,0,0,(int *)0x0);
  local_b8[0x1c] = 0x83;
  local_b8[0x1d] = 0x54;
  local_b8[0x1e] = 0x21b;
  local_b8[0x1f] = 0x28;
  puVar1 = FUN_00017990();
  psVar2 = (short *)FUN_00017dfc((int)puVar1,0x708);
  FUN_00014efc(param_1,(int *)(param_1 + 0x354),0xffffffff,local_b8 + 0x1c,0xc,psVar2,0xe6e6e6,0x825
              );
  local_b8[4] = 0x83;
  local_b8[5] = 0xa4;
  local_b8[6] = 0x21b;
  local_b8[7] = 0x28;
  FUN_00014efc(param_1,(int *)(param_1 + 0x7dc),0xffffffff,local_b8 + 4,0xc,(short *)&DAT_00020358,
               0xe6e6e6,0x815);
  local_b8[8] = 0x83;
  local_b8[9] = 0xd6;
  local_b8[10] = 0x21b;
  local_b8[0xb] = 0x28;
  FUN_00014efc(param_1,(int *)(param_1 + 0x598),0xffffffff,local_b8 + 8,0xc,(short *)&DAT_00020358,
               0xffffff,0x825);
  local_b8[0x10] = 0x83;
  local_b8[0x11] = 0x108;
  local_b8[0x13] = 0x28;
  local_b8[0x12] = 0x21b;
  FUN_00014efc(param_1,(int *)(param_1 + 0xa20),0xffffffff,local_b8 + 0x10,0xc,
               (short *)&DAT_00020358,0xe6e6e6,0x825);
  FUN_00011078(param_1 + 0x354,piVar3);
  FUN_00011078(param_1 + 0x7dc,piVar3);
  FUN_00011078(param_1 + 0xa20,piVar3);
  local_b8[0x18] = 0x126;
  local_b8[0x19] = 0x145;
  local_b8[0x1a] = 0xd5;
  local_b8[0x1b] = 0x44;
  puVar1 = FUN_00017990();
  psVar2 = (short *)FUN_00017dfc((int)puVar1,0x45c);
  FUN_00014f38(param_1,(int *)(param_1 + 0xc64),0xa4,local_b8 + 0x18,0x3e9,8,psVar2,(int *)0x0,
               local_b8,0x825,1,1,0);
  local_b8[0x20] = 0x126;
  local_b8[0x21] = 0x145;
  local_b8[0x22] = 0xd5;
  local_b8[0x23] = 0x44;
  puVar1 = FUN_00017990();
  psVar2 = (short *)FUN_00017dfc((int)puVar1,0x460);
  FUN_00014f38(param_1,(int *)(param_1 + 0x1104),0xa4,local_b8 + 0x20,0x3ea,8,psVar2,(int *)0x0,
               local_b8,0x825,1,1,0);
  return;
}



/* 000185b4 FUN_000185b4 */

/* Boundary evidence: original MIPS .pdata 000185b4..000185e3. Semantic name remains unreviewed. */

undefined4 FUN_000185b4(void)

{
  PostMessageW(DAT_00022708,2,0,0);
  return 0;
}



/* 000185e4 FUN_000185e4 */

/* Boundary evidence: original MIPS .pdata 000185e4..00018623. Semantic name remains unreviewed. */

undefined4 FUN_000185e4(int *param_1,int param_2)

{
  if ((999 < param_2) && (param_2 < 0x3eb)) {
    (**(code **)(*param_1 + 0x34))();
  }
  return 0;
}



/* 00018624 FUN_00018624 */

/* Boundary evidence: original MIPS .pdata 00018624..000186c7. Semantic name remains unreviewed. */

void FUN_00018624(int param_1,int param_2,int param_3)

{
  wchar_t local_40;
  undefined1 auStack_3e [38];
  uint local_18;
  
  local_18 = DAT_00021450;
  local_40 = L'\0';
  memset(auStack_3e,0,0x26);
  _snwprintf(&local_40,0x13,L"%02d:%02d",param_2 / 0x3c,param_2 % 0x3c);
  FUN_00011090((int *)(param_1 + 0xa20),&local_40,param_3);
  FUN_0001ab10(local_18);
  return;
}



/* 000186c8 FUN_000186c8 */

/* Boundary evidence: original MIPS .pdata 000186c8..00018817. Semantic name remains unreviewed. */

void FUN_000186c8(int param_1,int param_2)

{
  undefined4 *puVar1;
  wchar_t *_Str;
  size_t cchString;
  int iVar2;
  HGDIOBJ h;
  LPCWSTR lpszString;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  tagSIZE local_38;
  undefined4 auStack_30 [4];
  
  local_38.cx = 0;
  memset(&local_38.cy,0,4);
  piVar6 = (int *)(param_1 + 0x7dc);
  puVar1 = FUN_000138fc((int)piVar6,auStack_30);
  iVar4 = puVar1[2];
  _Str = (wchar_t *)FUN_00011070((int)piVar6);
  cchString = wcslen(_Str);
  iVar5 = 0xc;
  do {
    iVar2 = FUN_000181e4();
    h = (HGDIOBJ)FUN_00012dcc(iVar2,iVar5);
    SelectObject(*(HDC *)(param_1 + 0x4c),h);
    lpszString = (LPCWSTR)FUN_00011070((int)piVar6);
    GetTextExtentExPointW
              (*(HDC *)(param_1 + 0x4c),lpszString,cchString,0,(LPINT)0x0,(LPINT)0x0,&local_38);
    if (local_38.cx < iVar4 + -3) {
      iVar4 = FUN_000181e4();
      uVar3 = FUN_00012dcc(iVar4,iVar5);
      FUN_00011068((int)piVar6,uVar3);
      iVar4 = FUN_000181e4();
      uVar3 = FUN_00012dcc(iVar4,iVar5);
      FUN_00011068(param_1 + 0x598,uVar3);
      break;
    }
    iVar5 = iVar5 + -1;
  } while (-1 < iVar5);
  if (param_2 != 0) {
    FUN_00013984(piVar6);
  }
  return;
}



/* 00018818 FUN_00018818 */

/* Boundary evidence: original MIPS .pdata 00018818..00018847. Semantic name remains unreviewed. */

void FUN_00018818(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  FUN_000140ac(DAT_000218a8,param_1,param_2,param_3,param_4);
  return;
}



/* 00018848 FUN_00018848 */

/* Boundary evidence: original MIPS .pdata 00018848..00018863. Semantic name remains unreviewed. */

void FUN_00018848(int *param_1)

{
  FUN_00013db8(param_1);
  return;
}



/* 00018864 FUN_00018864 */

/* Boundary evidence: original MIPS .pdata 00018864..00018b4f. Semantic name remains unreviewed. */

void FUN_00018864(int param_1,int *param_2)

{
  undefined4 *puVar1;
  short *psVar2;
  undefined *puVar3;
  wchar_t *pwVar4;
  int iVar5;
  int *piVar6;
  wchar_t local_308;
  undefined1 auStack_306 [222];
  wchar_t local_228;
  undefined1 auStack_226 [518];
  uint local_20;
  
  local_20 = DAT_00021450;
  if (DAT_0002147c != 0) {
    puVar1 = FUN_00017990();
    psVar2 = (short *)FUN_00017dfc((int)puVar1,0x708);
    FUN_00011090((int *)(param_1 + 0x354),psVar2,0);
  }
  if (*(HWND *)(param_1 + 0x50) != (HWND)0x0) {
    SetWindowPos(*(HWND *)(param_1 + 0x50),(HWND)0xffffffff,0,0,0,0,3);
  }
  iVar5 = DAT_00021470;
  if (7 < DAT_00021470) {
    iVar5 = 7;
  }
  *(undefined4 *)(param_1 + 0x15a4) = *(undefined4 *)(&DAT_0001fcf0 + iVar5 * 4);
  local_308 = L'\0';
  memset(auStack_306,0,0xdc);
  puVar1 = FUN_00017990();
  puVar3 = FUN_00017dfc((int)puVar1,0x59a);
  _snwprintf(&local_308,0x6e,L"%s",puVar3);
  local_228 = L'\0';
  memset(auStack_226,0,0x206);
  puVar1 = FUN_00017990();
  puVar3 = FUN_00017dfc((int)puVar1,0x709);
  _snwprintf(&local_228,0x103,L"%s ",puVar3);
  puVar1 = FUN_00017990();
  psVar2 = (short *)FUN_00017dfc((int)puVar1,0x70a);
  FUN_0001376c(&local_228,0x104,psVar2);
  FUN_00013c34((undefined4 *)(param_1 + 0xc64),0,0);
  (**(code **)(*(int *)(param_1 + 700) + 0x20))((int *)(param_1 + 700),0,1);
  FUN_00013c34((undefined4 *)(param_1 + 0x1104),0,0);
  if (DAT_0002146c == '\0') {
    piVar6 = (int *)(param_1 + 0x7dc);
    if (*param_2 != 0) {
      FUN_00011090(piVar6,L"Code OK",0);
      (**(code **)(*piVar6 + 0x2c))(piVar6,0,0x2d);
      FUN_00011090((int *)(param_1 + 0x598),(short *)&DAT_00020294,0);
      FUN_00014f9c(param_1,5000);
      goto LAB_00018b2c;
    }
    FUN_00011090(piVar6,L"Incorrect code",0);
    (**(code **)(*piVar6 + 0x2c))(piVar6,0,0x2d);
    pwVar4 = L" ";
  }
  else {
    FUN_00011090((int *)(param_1 + 0x7dc),&local_228,0);
    pwVar4 = &local_308;
  }
  FUN_00011090((int *)(param_1 + 0x598),pwVar4,0);
  FUN_000186c8(param_1,0);
  if (DAT_0002146c == '\0') {
    FUN_00014f9c(param_1,5000);
  }
  else {
    iVar5 = *(int *)(param_1 + 0x15a4) * 0x3c;
    *(int *)(param_1 + 0x15a4) = iVar5;
    FUN_00018624(param_1,iVar5,1);
    SetTimer(*(HWND *)(param_1 + 0x50),0x3eb,1000,(TIMERPROC)0x0);
  }
  DAT_00021470 = DAT_00021470 + 1;
  FUN_0001746c();
  FUN_000175a0();
LAB_00018b2c:
  FUN_0001ab10(local_20);
  return;
}



/* 00018b50 FUN_00018b50 */

/* Boundary evidence: original MIPS .pdata 00018b50..00018c7f. Semantic name remains unreviewed. */

int FUN_00018b50(int *param_1,HINSTANCE param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  WNDCLASSW *pWVar1;
  HWND pHVar2;
  int iVar3;
  wchar_t local_228;
  undefined1 auStack_226 [518];
  uint local_20;
  
  local_20 = DAT_00021450;
  iVar3 = param_1[0x14];
  if (iVar3 == 0) {
    local_228 = L'\0';
    memset(auStack_226,0,0x206);
    swprintf(&local_228,0x20530,DAT_000218a8);
    param_1[0x12] = (int)param_2;
    pWVar1 = FUN_000156f0(DAT_000218a8,param_2,FUN_00018818);
    pHVar2 = CreateWindowExW(0x4000000,pWVar1->lpszClassName,pWVar1->lpszClassName,0x80000000,0,0,
                             800,0x1e0,(HWND)0x0,(HMENU)0x0,param_2,(LPVOID)0x0);
    param_1[0x14] = (int)pHVar2;
    if (pHVar2 == (HWND)0x0) {
      GetLastError();
      FUN_0001ab10(local_20);
      iVar3 = 0;
    }
    else {
      FUN_00014660(param_1,param_4,param_5);
      FUN_0001ab10(local_20);
      iVar3 = param_1[0x14];
    }
  }
  else {
    FUN_0001ab10(DAT_00021450);
  }
  return iVar3;
}



/* 00018c80 FUN_00018c80 */

/* Boundary evidence: original MIPS .pdata 00018c80..00018ce7. Semantic name remains unreviewed. */

undefined4 FUN_00018c80(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_3 == 0x113) && (param_4 == 0x3eb)) {
    if (param_1[0x569] < 2) {
      (**(code **)(*param_1 + 0x34))();
    }
    else {
      iVar1 = param_1[0x569] + -1;
      param_1[0x569] = iVar1;
      FUN_00018624((int)param_1,iVar1,1);
    }
  }
  return 1;
}



/* 00018ce8 FUN_00018ce8 */

/* Boundary evidence: original MIPS .pdata 00018ce8..00018d9f. Semantic name remains unreviewed. */

undefined4 * FUN_00018ce8(undefined4 *param_1)

{
  FUN_00014fcc(param_1);
  *param_1 = &PTR_FUN_0001fd5c;
  FUN_0001589c(param_1 + 0xaf);
  FUN_000167cc(param_1 + 0xc6);
  FUN_00011000(param_1 + 0xd5);
  FUN_00011000(param_1 + 0x166);
  FUN_00011000(param_1 + 0x1f7);
  FUN_00011000(param_1 + 0x288);
  FUN_000160a0(param_1 + 0x319);
  FUN_000160a0(param_1 + 0x441);
  param_1[0xaa] = 0x15;
  param_1[0x569] = 0;
  return param_1;
}



/* 00018da0 Unwind@00018da0 */

/* Boundary evidence: original MIPS .pdata 00018da0..00018dcf. Semantic name remains unreviewed. */

void Unwind_00018da0(void)

{
  undefined4 *in_v0;
  
  FUN_00018848((int *)*in_v0);
  return;
}



/* 00018dd0 Unwind@00018dd0 */

/* Boundary evidence: original MIPS .pdata 00018dd0..00018e03. Semantic name remains unreviewed. */

void Unwind_00018dd0(void)

{
  int *in_v0;
  
  FUN_00016064((undefined4 *)(*in_v0 + 700));
  return;
}



/* 00018e04 Unwind@00018e04 */

/* Boundary evidence: original MIPS .pdata 00018e04..00018e37. Semantic name remains unreviewed. */

void Unwind_00018e04(void)

{
  int *in_v0;
  
  FUN_000115d4((undefined4 *)(*in_v0 + 0x318));
  return;
}



/* 00018e38 Unwind@00018e38 */

/* Boundary evidence: original MIPS .pdata 00018e38..00018e6b. Semantic name remains unreviewed. */

void Unwind_00018e38(void)

{
  int *in_v0;
  
  FUN_000115d4((undefined4 *)(*in_v0 + 0x354));
  return;
}



/* 00018e6c Unwind@00018e6c */

/* Boundary evidence: original MIPS .pdata 00018e6c..00018e9f. Semantic name remains unreviewed. */

void Unwind_00018e6c(void)

{
  int *in_v0;
  
  FUN_000115d4((undefined4 *)(*in_v0 + 0x598));
  return;
}



/* 00018ea0 Unwind@00018ea0 */

/* Boundary evidence: original MIPS .pdata 00018ea0..00018ed3. Semantic name remains unreviewed. */

void Unwind_00018ea0(void)

{
  int *in_v0;
  
  FUN_000115d4((undefined4 *)(*in_v0 + 0x7dc));
  return;
}



/* 00018ed4 Unwind@00018ed4 */

/* Boundary evidence: original MIPS .pdata 00018ed4..00018f07. Semantic name remains unreviewed. */

void Unwind_00018ed4(void)

{
  int *in_v0;
  
  FUN_000115d4((undefined4 *)(*in_v0 + 0xa20));
  return;
}



/* 00018f08 Unwind@00018f08 */

/* Boundary evidence: original MIPS .pdata 00018f08..00018f3b. Semantic name remains unreviewed. */

void Unwind_00018f08(void)

{
  int *in_v0;
  
  FUN_000162c4((undefined4 *)(*in_v0 + 0xc64));
  return;
}



/* 00018f3c FUN_00018f3c */

/* Boundary evidence: original MIPS .pdata 00018f3c..0001933f. Semantic name remains unreviewed. */

void FUN_00018f3c(int param_1)

{
  undefined4 *puVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  short local_110;
  undefined1 auStack_10e [6];
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  int local_f8 [5];
  int local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a8 [16];
  short local_68 [11];
  undefined1 auStack_52 [38];
  uint local_2c;
  
  local_2c = DAT_00021450;
  local_a8[0] = 0xe6e6e6;
  local_a8[1] = 0;
  local_a8[2] = 0x53595c;
  local_a8[3] = 0;
  local_f8[0] = 0xe6e6e6;
  local_f8[1] = 0;
  local_f8[2] = 0x53595c;
  local_f8[3] = 0;
  FUN_00014da8(param_1,6);
  local_b8 = 0x95;
  local_b4 = 0x15;
  local_b0 = 500;
  local_ac = 0x2d;
  puVar1 = FUN_00017990();
  psVar2 = (short *)FUN_00017dfc((int)puVar1,0x708);
  FUN_00014efc(param_1,(int *)(param_1 + 0x2b4),0xffffffff,&local_b8,0xc,psVar2,0xc4dae5,0x801);
  local_a8[0xc] = 0xb9;
  local_a8[0xd] = 0x82;
  local_a8[0xe] = 0x5b;
  local_a8[0xf] = 0x4b;
  FUN_00014efc(param_1,(int *)(param_1 + 0x4f8),0x8f,local_a8 + 0xc,0x11,(short *)&DAT_00020358,
               0x1a1c1c,0x825);
  local_d8 = 0x12a;
  local_d4 = 0x82;
  local_d0 = 0x5b;
  local_cc = 0x4b;
  FUN_00014efc(param_1,(int *)(param_1 + 0x73c),0x8f,&local_d8,0x11,(short *)&DAT_00020358,0x1a1c1c,
               0x825);
  local_a8[5] = 0x82;
  local_a8[4] = 0x19b;
  local_a8[6] = 0x5b;
  local_a8[7] = 0x4b;
  FUN_00014efc(param_1,(int *)(param_1 + 0x980),0x8f,local_a8 + 4,0x11,(short *)&DAT_00020358,
               0x1a1c1c,0x825);
  local_fc = 0x4b;
  local_100 = 0x5b;
  local_108 = 0x20c;
  local_104 = 0x82;
  FUN_00014efc(param_1,(int *)(param_1 + 0xbc4),0x8f,&local_108,0x11,(short *)&DAT_00020358,0x1a1c1c
               ,0x825);
  FUN_000138dc(param_1 + 0x4f8,1);
  FUN_000138dc(param_1 + 0x73c,1);
  FUN_000138dc(param_1 + 0x980,1);
  FUN_000138dc(param_1 + 0xbc4,1);
  memcpy(local_68,L"1234567890",0x16);
  memset(auStack_52,0,0x26);
  memset(auStack_10e,0,2);
  iVar3 = 0;
  iVar4 = 0xb1;
  psVar2 = local_68;
  piVar5 = (int *)(param_1 + 0xe08);
  do {
    if (iVar3 % 5 == 0) {
      iVar4 = iVar4 + 0x48;
    }
    local_110 = *psVar2;
    local_dc = 0x47;
    local_e0 = 0x7f;
    local_f8[4] = (iVar3 % 5) * 0x81 + 0xe;
    local_e4 = iVar4;
    FUN_00014f38(param_1,piVar5,0x90,local_f8 + 4,iVar3 + 0x3e9,0xc,&local_110,(int *)0x0,local_f8,
                 0x825,1,1,0);
    iVar3 = iVar3 + 1;
    psVar2 = psVar2 + 1;
    piVar5 = piVar5 + 0x128;
  } while (iVar3 < 10);
  local_c8 = 0x293;
  local_c4 = 0xf9;
  local_c0 = 0x7f;
  local_bc = 0x8f;
  FUN_00014e2c(param_1,(int *)(param_1 + 0x3c48),0x91,&local_c8,0x3f3,1);
  local_a8[8] = 0x273;
  local_a8[9] = 0x191;
  local_a8[10] = 0xa0;
  local_a8[0xb] = 0x4f;
  puVar1 = FUN_00017990();
  psVar2 = (short *)FUN_00017dfc((int)puVar1,0x45c);
  FUN_00014f38(param_1,(int *)(param_1 + 0x3ca4),0x14,local_a8 + 8,1000,8,psVar2,(int *)0x0,local_a8
               ,0x825,1,1,0);
  FUN_0001ab10(local_2c);
  return;
}



/* 00019340 FUN_00019340 */

/* Boundary evidence: original MIPS .pdata 00019340..000193a3. Semantic name remains unreviewed. */

undefined4 FUN_00019340(int param_1,int param_2)

{
  if (param_2 == 1) {
    if ((*(HWND *)(param_1 + 0x50) != (HWND)0x0) && (DAT_000218b0 == 0)) {
      SetForegroundWindow(*(HWND *)(param_1 + 0x50));
    }
  }
  else if (param_2 == 0) {
    DAT_000218b0 = 0;
  }
  return 1;
}



/* 000193a4 FUN_000193a4 */

undefined4 FUN_000193a4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (4 < *(int *)(param_1 + 0x4150)) {
    *(undefined4 *)(param_1 + 0x4150) = 4;
  }
  iVar2 = *(int *)(param_1 + 0x4150);
  if (iVar2 < 0) {
    uVar1 = 0;
  }
  else {
    if (0 < iVar2) {
      *(int *)(param_1 + 0x4150) = iVar2 + -1;
    }
    *(undefined2 *)((*(int *)(param_1 + 0x4150) + 0x20a2) * 2 + param_1) = 0;
    uVar1 = 1;
  }
  return uVar1;
}



/* 00019400 FUN_00019400 */

/* Boundary evidence: original MIPS .pdata 00019400..0001953f. Semantic name remains unreviewed. */

void FUN_00019400(int param_1,int param_2)

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
  wcsncpy(&local_20,(wchar_t *)(param_1 + 0x4144),1);
  wcsncpy(&local_1c,(wchar_t *)(param_1 + 0x4146),1);
  wcsncpy(&local_18,(wchar_t *)(param_1 + 0x4148),1);
  wcsncpy(&local_14,(wchar_t *)(param_1 + 0x414a),1);
  pwVar2 = L"*";
  pwVar1 = &local_20;
  if (local_20 != L'\0') {
    pwVar1 = pwVar2;
  }
  FUN_00011090((int *)(param_1 + 0x4f8),pwVar1,param_2);
  pwVar1 = &local_1c;
  if (local_1c != L'\0') {
    pwVar1 = pwVar2;
  }
  FUN_00011090((int *)(param_1 + 0x73c),pwVar1,param_2);
  pwVar1 = &local_18;
  if (local_18 != L'\0') {
    pwVar1 = pwVar2;
  }
  FUN_00011090((int *)(param_1 + 0x980),pwVar1,param_2);
  if (local_14 == L'\0') {
    pwVar2 = &local_14;
  }
  FUN_00011090((int *)(param_1 + 0xbc4),pwVar2,param_2);
  return;
}



/* 00019540 FUN_00019540 */

/* Boundary evidence: original MIPS .pdata 00019540..0001959f. Semantic name remains unreviewed. */

void FUN_00019540(void)

{
  wchar_t local_218;
  undefined1 auStack_216 [518];
  uint local_10;
  
  local_10 = DAT_00021450;
  local_218 = L'\0';
  memset(auStack_216,0,0x206);
  _snwprintf(&local_218,0x103,L"Current Authkey : %d%d%d%d",0,0,0,0);
  FUN_0001ab10(local_10);
  return;
}



/* 000195a0 FUN_000195a0 */

/* Boundary evidence: original MIPS .pdata 000195a0..00019603. Semantic name remains unreviewed. */

void FUN_000195a0(int param_1)

{
  undefined4 *puVar1;
  short *psVar2;
  
  puVar1 = FUN_00017990();
  psVar2 = (short *)FUN_00017dfc((int)puVar1,0x708);
  FUN_00011090((int *)(param_1 + 0x2b4),psVar2,0);
  puVar1 = FUN_00017990();
  psVar2 = (short *)FUN_00017dfc((int)puVar1,0x45c);
  FUN_000164f4((int *)(param_1 + 0x3ca4),psVar2,0);
  return;
}



/* 00019604 FUN_00019604 */

/* Boundary evidence: original MIPS .pdata 00019604..0001966f. Semantic name remains unreviewed. */

void FUN_00019604(void)

{
  undefined4 *puVar1;
  
  if (DAT_000218a8 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x15a8);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_000218a8 = (undefined4 *)0x0;
    }
    else {
      DAT_000218a8 = FUN_00018ce8(puVar1);
    }
  }
  return;
}



/* 00019670 Unwind@00019670 */

/* Boundary evidence: original MIPS .pdata 00019670..0001969f. Semantic name remains unreviewed. */

void Unwind_00019670(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 000196a0 FUN_000196a0 */

/* Boundary evidence: original MIPS .pdata 000196a0..000196cf. Semantic name remains unreviewed. */

void FUN_000196a0(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  FUN_000140ac(DAT_000218ac,param_1,param_2,param_3,param_4);
  return;
}



/* 000196d0 FUN_000196d0 */

/* Boundary evidence: original MIPS .pdata 000196d0..00019747. Semantic name remains unreviewed. */

void FUN_000196d0(int param_1)

{
  DAT_000218b0 = 0;
  FUN_000157bc();
  if (DAT_0002147c != 0) {
    FUN_000195a0(param_1);
  }
  FUN_00019540();
  *(undefined4 *)(param_1 + 0x4150) = 0;
  *(undefined2 *)(param_1 + 0x4144) = 0;
  *(undefined2 *)(param_1 + 0x4146) = 0;
  *(undefined2 *)(param_1 + 0x4148) = 0;
  *(undefined2 *)(param_1 + 0x414a) = 0;
  *(undefined2 *)(param_1 + 0x414c) = 0;
  FUN_00019400(param_1,0);
  return;
}



/* 00019748 FUN_00019748 */

/* Boundary evidence: original MIPS .pdata 00019748..00019ac3. Semantic name remains unreviewed. */

undefined4 FUN_00019748(int param_1,undefined4 param_2)

{
  size_t sVar1;
  int iVar2;
  HWND pHVar3;
  int *piVar4;
  undefined2 uVar5;
  int iVar6;
  int *piVar7;
  wchar_t *pwVar8;
  int iVar9;
  wchar_t *_Str;
  int iVar10;
  int *piVar11;
  
  switch(param_2) {
  case 1000:
    _Str = (wchar_t *)(param_1 + 0x4144);
    sVar1 = wcslen(_Str);
    if (sVar1 != 4) {
      return 0;
    }
    piVar11 = (int *)(param_1 + 0x4154);
    *piVar11 = 1;
    iVar6 = 0;
    pwVar8 = _Str;
    do {
      iVar2 = FUN_0001746c();
      if ((ushort)*(byte *)(*(int *)(iVar2 + 0x7c) + iVar6 + 0x683) != *pwVar8) {
        NKDbgPrintfW(L"[CodeChecker] Wrong Key input \r\n");
        *piVar11 = 0;
        break;
      }
      iVar6 = iVar6 + 1;
      pwVar8 = pwVar8 + 1;
    } while (iVar6 < 4);
    NKDbgPrintfW(L"[CodeChecker] User key : %c%c%c%c \r\n",*_Str,*(undefined2 *)(param_1 + 0x4146),
                 *(undefined2 *)(param_1 + 0x4148),*(undefined2 *)(param_1 + 0x414a));
    iVar6 = FUN_0001746c();
    iVar10 = *(int *)(iVar6 + 0x7c);
    iVar6 = FUN_0001746c();
    iVar9 = *(int *)(iVar6 + 0x7c);
    iVar6 = FUN_0001746c();
    iVar2 = *(int *)(iVar6 + 0x7c);
    iVar6 = FUN_0001746c();
    NKDbgPrintfW(L"[CodeChecker] ULC key : %c%c%c%c \r\n",
                 *(undefined1 *)(*(int *)(iVar6 + 0x7c) + 0x683),*(undefined1 *)(iVar2 + 0x684),
                 *(undefined1 *)(iVar9 + 0x685),*(undefined1 *)(iVar10 + 0x686));
    DAT_000218b0 = 1;
    if (*piVar11 == 1) {
      FUN_0001746c();
      FUN_000175fc();
      if (DAT_0002146c != '\0') {
        pHVar3 = FindWindowW(L"AppMain",L"AppMain");
        PostMessageW(pHVar3,0x83e9,0x10001,0);
        PostMessageW(DAT_00022708,2,0,0);
        return 0;
      }
      if (DAT_0002145c - 1 < DAT_0002145c) {
        piVar7 = *(int **)((DAT_0002145c - 1) * 4 + DAT_00021458);
      }
      else {
        piVar7 = (int *)0x0;
      }
      piVar4 = (int *)FUN_00019604();
      FUN_00014944(piVar7,piVar4,piVar11,0);
      return 0;
    }
    pHVar3 = FindWindowW(L"MGRMCM",(LPCWSTR)0x0);
    if (pHVar3 != (HWND)0x0) {
      PostMessageW(pHVar3,0x8064,0xb40300,0);
    }
    if (DAT_0002145c - 1 < DAT_0002145c) {
      piVar7 = *(int **)((DAT_0002145c - 1) * 4 + DAT_00021458);
    }
    else {
      piVar7 = (int *)0x0;
    }
    piVar4 = (int *)FUN_00019604();
    FUN_00014944(piVar7,piVar4,piVar11,0);
    FUN_000193a4(param_1);
    FUN_000193a4(param_1);
    FUN_000193a4(param_1);
  case 0x3f3:
    FUN_000193a4(param_1);
    goto LAB_00019a90;
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
  default:
    goto switchD_00019790_default;
  }
  if (*(int *)(param_1 + 0x4150) < 4) {
    *(undefined2 *)((*(int *)(param_1 + 0x4150) + 0x20a2) * 2 + param_1) = uVar5;
    *(int *)(param_1 + 0x4150) = *(int *)(param_1 + 0x4150) + 1;
  }
LAB_00019a90:
  FUN_00019400(param_1,1);
switchD_00019790_default:
  return 0;
}



/* 00019ac4 FUN_00019ac4 */

/* Boundary evidence: original MIPS .pdata 00019ac4..00019b9b. Semantic name remains unreviewed. */

int FUN_00019ac4(int *param_1,HINSTANCE param_2,HWND param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  WNDCLASSW *pWVar2;
  HWND pHVar3;
  
  iVar1 = param_1[0x14];
  if (iVar1 == 0) {
    param_1[0x12] = (int)param_2;
    pWVar2 = FUN_000156f0(DAT_000218ac,param_2,FUN_000196a0);
    pHVar3 = CreateWindowExW(0x4000000,pWVar2->lpszClassName,pWVar2->lpszClassName,0x90000000,0,0,
                             800,0x1e0,param_3,(HMENU)0x0,param_2,(LPVOID)0x0);
    param_1[0x14] = (int)pHVar3;
    if (pHVar3 == (HWND)0x0) {
      GetLastError();
      iVar1 = 0;
    }
    else {
      FUN_00014660(param_1,param_4,param_5);
      iVar1 = param_1[0x14];
    }
  }
  return iVar1;
}



/* 00019b9c FUN_00019b9c */

/* Boundary evidence: original MIPS .pdata 00019b9c..00019c8b. Semantic name remains unreviewed. */

undefined4 * FUN_00019b9c(undefined4 *param_1)

{
  FUN_00013cbc(param_1);
  *param_1 = &PTR_FUN_0001ffe8;
  FUN_00011000(param_1 + 0xad);
  FUN_00011000(param_1 + 0x13e);
  FUN_00011000(param_1 + 0x1cf);
  FUN_00011000(param_1 + 0x260);
  FUN_00011000(param_1 + 0x2f1);
  ___L_YAXPAXIHP6AX0_Z1_Z(param_1 + 0x382,0x4a0,10,FUN_000160a0,FUN_000162c4);
  FUN_0001589c(param_1 + 0xf12);
  FUN_000160a0(param_1 + 0xf29);
  param_1[0xaa] = 2;
  param_1[0x1054] = 0;
  *(undefined2 *)(param_1 + 0x1051) = 0;
  *(undefined2 *)((int)param_1 + 0x4146) = 0;
  *(undefined2 *)(param_1 + 0x1052) = 0;
  *(undefined2 *)((int)param_1 + 0x414a) = 0;
  *(undefined2 *)(param_1 + 0x1053) = 0;
  param_1[0xac] = 0;
  param_1[0x1055] = 0;
  return param_1;
}



/* 00019c8c Unwind@00019c8c */

/* Boundary evidence: original MIPS .pdata 00019c8c..00019cbb. Semantic name remains unreviewed. */

void Unwind_00019c8c(void)

{
  undefined4 *in_v0;
  
  FUN_00018848((int *)*in_v0);
  return;
}



/* 00019cbc Unwind@00019cbc */

/* Boundary evidence: original MIPS .pdata 00019cbc..00019cef. Semantic name remains unreviewed. */

void Unwind_00019cbc(void)

{
  int *in_v0;
  
  FUN_000115d4((undefined4 *)(*in_v0 + 0x2b4));
  return;
}



/* 00019cf0 Unwind@00019cf0 */

/* Boundary evidence: original MIPS .pdata 00019cf0..00019d23. Semantic name remains unreviewed. */

void Unwind_00019cf0(void)

{
  int *in_v0;
  
  FUN_000115d4((undefined4 *)(*in_v0 + 0x4f8));
  return;
}



/* 00019d24 Unwind@00019d24 */

/* Boundary evidence: original MIPS .pdata 00019d24..00019d57. Semantic name remains unreviewed. */

void Unwind_00019d24(void)

{
  int *in_v0;
  
  FUN_000115d4((undefined4 *)(*in_v0 + 0x73c));
  return;
}



/* 00019d58 Unwind@00019d58 */

/* Boundary evidence: original MIPS .pdata 00019d58..00019d8b. Semantic name remains unreviewed. */

void Unwind_00019d58(void)

{
  int *in_v0;
  
  FUN_000115d4((undefined4 *)(*in_v0 + 0x980));
  return;
}



/* 00019d8c Unwind@00019d8c */

/* Boundary evidence: original MIPS .pdata 00019d8c..00019dbf. Semantic name remains unreviewed. */

void Unwind_00019d8c(void)

{
  int *in_v0;
  
  FUN_000115d4((undefined4 *)(*in_v0 + 0xbc4));
  return;
}



/* 00019dc0 Unwind@00019dc0 */

/* Boundary evidence: original MIPS .pdata 00019dc0..00019e03. Semantic name remains unreviewed. */

void Unwind_00019dc0(void)

{
  int *in_v0;
  
  ___M_YAXPAXIHP6AX0_Z_Z(*in_v0 + 0xe08,0x4a0,10,FUN_000162c4);
  return;
}



/* 00019e04 Unwind@00019e04 */

/* Boundary evidence: original MIPS .pdata 00019e04..00019e37. Semantic name remains unreviewed. */

void Unwind_00019e04(void)

{
  int *in_v0;
  
  FUN_00016064((undefined4 *)(*in_v0 + 0x3c48));
  return;
}



/* 00019e38 FUN_00019e38 */

/* Boundary evidence: original MIPS .pdata 00019e38..00019ea7. Semantic name remains unreviewed. */

bool FUN_00019e38(LPCWSTR param_1)

{
  DWORD DVar1;
  
  DAT_000218b4 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,param_1);
  DVar1 = GetLastError();
  if (DVar1 == 0xb7) {
    CloseHandle(DAT_000218b4);
  }
  return DVar1 != 0xb7;
}



/* 00019ea8 FUN_00019ea8 */

/* Boundary evidence: original MIPS .pdata 00019ea8..0001a0bf. Semantic name remains unreviewed. */

void FUN_00019ea8(void)

{
  int iVar1;
  
  iVar1 = FUN_000181e4();
  FUN_00012e04(iVar1,0,L"tahoma",0x14,0,'\0','\0');
  FUN_00012e04(iVar1,1,L"tahoma",0x14,0,'\0','\0');
  FUN_00012e04(iVar1,2,L"tahoma",0x17,0,'\0','\0');
  FUN_00012e04(iVar1,3,L"tahoma",0x19,0,'\0','\0');
  FUN_00012e04(iVar1,4,L"tahoma",0x1c,0,'\0','\0');
  FUN_00012e04(iVar1,5,L"tahoma",0x1d,0,'\0','\0');
  FUN_00012e04(iVar1,6,L"tahoma",0x1e,0,'\0','\0');
  FUN_00012e04(iVar1,7,L"tahoma",0x1f,0,'\0','\0');
  FUN_00012e04(iVar1,8,L"tahoma",0x20,0,'\0','\0');
  FUN_00012e04(iVar1,0xc,L"tahoma",0x28,0,'\0','\0');
  FUN_00012e04(iVar1,0xe,L"tahoma",0x2d,0,'\0','\0');
  FUN_00012e04(iVar1,0xf,L"tahoma",0x32,0,'\0','\0');
  FUN_00012e04(iVar1,0x10,L"tahoma",0x3c,0,'\0','\0');
  FUN_00012e04(iVar1,0x11,L"tahoma",0x41,0,'\0','\0');
  FUN_00012e04(iVar1,0x12,L"tahoma",0x50,0,'\0','\0');
  return;
}



/* 0001a0c0 FUN_0001a0c0 */

/* Boundary evidence: original MIPS .pdata 0001a0c0..0001a1bb. Semantic name remains unreviewed. */

undefined4 FUN_0001a0c0(HINSTANCE param_1)

{
  int iVar1;
  HWND hWnd;
  HWND hWnd_00;
  undefined4 uVar2;
  
  iVar1 = FUN_0001746c();
  *(HINSTANCE *)(iVar1 + 0x60) = param_1;
  FUN_00019ea8();
  hWnd = CreateWindowExW(0x4000000,L"CodeChecker",L"CodeChecker",0x92000000,0,0,800,0x1e0,(HWND)0x0,
                         (HMENU)0x0,param_1,(LPVOID)0x0);
  if (hWnd == (HWND)0x0) {
    GetLastError();
    uVar2 = 0;
  }
  else {
    hWnd_00 = FindWindowW(L"HHTaskBar",(LPCWSTR)0x0);
    if (hWnd_00 != (HWND)0x0) {
      ShowWindow(hWnd_00,0);
    }
    uVar2 = 1;
    ShowWindow(hWnd,1);
    SetWindowPos(hWnd,(HWND)0xffffffff,0,0,0,0,3);
    UpdateWindow(hWnd);
  }
  return uVar2;
}



/* 0001a1bc FUN_0001a1bc */

/* Boundary evidence: original MIPS .pdata 0001a1bc..0001a227. Semantic name remains unreviewed. */

void FUN_0001a1bc(void)

{
  undefined4 *puVar1;
  
  if (DAT_000218ac == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x4158);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_000218ac = (undefined4 *)0x0;
    }
    else {
      DAT_000218ac = FUN_00019b9c(puVar1);
    }
  }
  return;
}



/* 0001a228 Unwind@0001a228 */

/* Boundary evidence: original MIPS .pdata 0001a228..0001a257. Semantic name remains unreviewed. */

void Unwind_0001a228(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0001a258 FUN_0001a258 */

/* Boundary evidence: original MIPS .pdata 0001a258..0001a2cb. Semantic name remains unreviewed. */

undefined4 FUN_0001a258(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 auStack_80 [21];
  int local_2c;
  
  FUN_0001a780(auStack_80);
  puVar1 = FUN_00017990();
  FUN_00017b74((int)puVar1,local_2c);
  piVar2 = (int *)FUN_0001a1bc();
  FUN_000154cc(piVar2,0);
  DAT_00022704 = &LAB_00013cac;
  FUN_0001a534(auStack_80);
  return 0;
}



/* 0001a2cc Unwind@0001a2cc */

/* Boundary evidence: original MIPS .pdata 0001a2cc..0001a2fb. Semantic name remains unreviewed. */

void Unwind_0001a2cc(void)

{
  int in_v0;
  
  FUN_0001a534((undefined4 *)(in_v0 + -0x80));
  return;
}



/* 0001a2fc FUN_0001a2fc */

/* Boundary evidence: original MIPS .pdata 0001a2fc..0001a433. Semantic name remains unreviewed. */

LRESULT FUN_0001a2fc(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  HWND hWnd;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_2 == 1) {
    SetTimer(param_1,0x3eb,1000,(TIMERPROC)0x0);
    iVar2 = FUN_0001746c();
    *(HWND *)(iVar2 + 0x5c) = param_1;
    iVar2 = FUN_0001746c();
    iVar3 = FUN_0001746c();
    FUN_000156c0(*(int *)(iVar3 + 0x60),*(int *)(iVar2 + 0x5c));
    FUN_0001a258();
    uVar4 = FUN_00013698((HKEY)0x80000002,L"LGE\\SystemInfo",L"FACTORY_TYPE",0);
    DAT_0002146c = (undefined1)uVar4;
  }
  else if (param_2 == 2) {
    FUN_0001746c();
    FUN_000175a0();
    hWnd = FindWindowW(L"MGRMCM",(LPCWSTR)0x0);
    if (hWnd != (HWND)0x0) {
      PostMessageW(hWnd,0x8064,0xb40300,(uint)(DAT_00021470 == 0));
    }
    PostQuitMessage(0);
  }
  else if (((param_2 != 0x4a) && (param_2 != 0x113)) && (param_2 != 0x464)) {
    LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
    return LVar1;
  }
  return 0;
}



/* 0001a434 FUN_0001a434 */

/* Boundary evidence: original MIPS .pdata 0001a434..0001a48b. Semantic name remains unreviewed. */

void FUN_0001a434(HINSTANCE param_1)

{
  WNDCLASSW local_30;
  
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_0001a2fc;
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



/* 0001a48c FUN_0001a48c */

/* Boundary evidence: original MIPS .pdata 0001a48c..0001a533. Semantic name remains unreviewed. */

undefined4 FUN_0001a48c(HINSTANCE param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  BOOL BVar3;
  MSG MStack_30;
  
  bVar1 = FUN_00019e38(L"CodeChecker.exe");
  if (CONCAT31(extraout_var,bVar1) != 0) {
    NKDbgPrintfW(L"[CodeChecker] CodeChecker Execute! \r\n");
    FUN_0001a434(param_1);
    iVar2 = FUN_0001a0c0(param_1);
    if (iVar2 != 0) {
      while (BVar3 = GetMessageW(&MStack_30,(HWND)0x0,0,0), BVar3 != 0) {
        TranslateMessage(&MStack_30);
        DispatchMessageW(&MStack_30);
      }
      return MStack_30.wParam;
    }
  }
  return 0;
}



/* 0001a534 FUN_0001a534 */

void FUN_0001a534(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00020230;
  return;
}



/* 0001a544 FUN_0001a544 */

/* Boundary evidence: original MIPS .pdata 0001a544..0001a617. Semantic name remains unreviewed. */

undefined4 FUN_0001a544(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  HKEY local_28;
  undefined4 local_24;
  DWORD local_20 [4];
  
  local_20[1] = 4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_28,local_20 + 2);
  if (LVar1 == 0) {
    local_20[0] = 4;
    LVar1 = RegQueryValueExW(local_28,param_3,(LPDWORD)0x0,local_20 + 1,(LPBYTE)&local_24,local_20);
    if (LVar1 != 0) {
      local_24 = param_4;
    }
    RegCloseKey(local_28);
  }
  else {
    local_24 = 0;
  }
  return local_24;
}



/* 0001a618 FUN_0001a618 */

/* Boundary evidence: original MIPS .pdata 0001a618..0001a65b. Semantic name remains unreviewed. */

undefined4 * FUN_0001a618(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00020230;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001a65c FUN_0001a65c */

/* Boundary evidence: original MIPS .pdata 0001a65c..0001a6af. Semantic name remains unreviewed. */

void FUN_0001a65c(int param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  
  uVar1 = param_1 + 0x53U & 3;
  puVar2 = (uint *)((param_1 + 0x53U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0x809U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x50U & 3;
  puVar2 = (uint *)((param_1 + 0x50U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0x809 << uVar1 * 8;
  uVar3 = FUN_0001a544((HKEY)0x80000002,L"LGE\\SystemInfo",L"LANG_TYPE",2);
  *(undefined4 *)(param_1 + 0x54) = uVar3;
  return;
}



/* 0001a6b0 FUN_0001a6b0 */

/* Boundary evidence: original MIPS .pdata 0001a6b0..0001a77f. Semantic name remains unreviewed. */

void FUN_0001a6b0(int param_1)

{
  FILE *_File;
  size_t sVar1;
  byte bVar2;
  int iVar3;
  
  _File = _wfopen(L"/Storage Card2/MgrSys.cfg",L"rb");
  if (_File != (FILE *)0x0) {
    sVar1 = fread((void *)(param_1 + 4),1,0x55,_File);
    fclose(_File);
    if (sVar1 != 0x55) {
      FUN_0001a65c(param_1);
    }
    bVar2 = 0;
    iVar3 = 0;
    do {
      bVar2 = *(byte *)(param_1 + 4 + iVar3) ^ bVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x54);
    if (bVar2 == *(byte *)(param_1 + 0x58)) {
      return;
    }
  }
  FUN_0001a65c(param_1);
  return;
}



/* 0001a780 FUN_0001a780 */

/* Boundary evidence: original MIPS .pdata 0001a780..0001a7cb. Semantic name remains unreviewed. */

undefined4 * FUN_0001a780(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00020230;
  param_1[0x17] = 0;
  memset(param_1 + 0x18,0,0x14);
  FUN_0001a6b0((int)param_1);
  return param_1;
}



/* 0001aa2c FUN_0001aa2c */

/* Boundary evidence: original MIPS .pdata 0001aa2c..0001aa9f. Semantic name remains unreviewed. */

void FUN_0001aa2c(void)

{
  uint uVar1;
  
  if ((DAT_00021450 == 0) || (DAT_00021450 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00021450 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00021450 == 0) {
      DAT_00021450 = 0xb064;
    }
  }
  DAT_00021454 = ~DAT_00021450;
  return;
}



/* 0001aaa0 FUN_0001aaa0 */

/* Boundary evidence: original MIPS .pdata 0001aaa0..0001ab0f. Semantic name remains unreviewed. */

void FUN_0001aaa0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0001ab58(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 0001ab10 FUN_0001ab10 */

/* Boundary evidence: original MIPS .pdata 0001ab10..0001ab57. Semantic name remains unreviewed. */

void FUN_0001ab10(uint param_1)

{
  if ((param_1 == DAT_00021450) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 0001ab58 FUN_0001ab58 */

/* Boundary evidence: original MIPS .pdata 0001ab58..0001abab. Semantic name remains unreviewed. */

void FUN_0001ab58(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_0001ab10(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 0001abac FUN_0001abac */

/* Boundary evidence: original MIPS .pdata 0001abac..0001abd7. Semantic name remains unreviewed. */

undefined4 FUN_0001abac(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0001ab58(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 0001ac28 FUN_0001ac28 */

/* Boundary evidence: original MIPS .pdata 0001ac28..0001acbb. Semantic name remains unreviewed. */

void FUN_0001ac28(HINSTANCE param_1)

{
  UINT UVar1;
  
  FUN_0001af34();
  UVar1 = FUN_0001a48c(param_1);
  FUN_0001ae74(UVar1);
  FUN_0001ae94(UVar1);
  return;
}



/* 0001acbc FUN_0001acbc */

/* Boundary evidence: original MIPS .pdata 0001acbc..0001acfb. Semantic name remains unreviewed. */

void FUN_0001acbc(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 0001acfc entry */

/* Boundary evidence: original MIPS .pdata 0001acfc..0001ad57. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1)

{
  FUN_0001aa2c();
  FUN_0001ac28(param_1);
  return;
}



/* 0001ad88 FUN_0001ad88 */

/* Boundary evidence: original MIPS .pdata 0001ad88..0001ae73. Semantic name remains unreviewed. */

void FUN_0001ad88(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_000218c4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00022740;
    if (DAT_00022740 != (undefined4 *)0x0) {
      while (DAT_0002273c = DAT_0002273c + -1, _Memory <= DAT_0002273c) {
        if ((code *)*DAT_0002273c != (code *)0x0) {
          (*(code *)*DAT_0002273c)();
          _Memory = DAT_00022740;
        }
      }
      free(_Memory);
      DAT_0002273c = (undefined4 *)0x0;
      DAT_00022740 = (undefined4 *)0x0;
    }
    FUN_0001aee0((undefined4 *)&DAT_0001c024,(undefined4 *)&DAT_0001c028);
  }
  FUN_0001aee0((undefined4 *)&DAT_0001c02c,(undefined4 *)&DAT_0001c030);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 0001ae74 FUN_0001ae74 */

/* Boundary evidence: original MIPS .pdata 0001ae74..0001ae93. Semantic name remains unreviewed. */

void FUN_0001ae74(UINT param_1)

{
  FUN_0001ad88(param_1,0,0);
  return;
}



/* 0001ae94 FUN_0001ae94 */

/* Boundary evidence: original MIPS .pdata 0001ae94..0001aedf. Semantic name remains unreviewed. */

void FUN_0001ae94(UINT param_1)

{
  DAT_000218c4 = 0;
  FUN_0001aee0((undefined4 *)&DAT_0001c02c,(undefined4 *)&DAT_0001c030);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 0001aee0 FUN_0001aee0 */

/* Boundary evidence: original MIPS .pdata 0001aee0..0001af33. Semantic name remains unreviewed. */

void FUN_0001aee0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 0001af34 FUN_0001af34 */

/* Boundary evidence: original MIPS .pdata 0001af34..0001af6f. Semantic name remains unreviewed. */

void FUN_0001af34(void)

{
  FUN_0001aee0((undefined4 *)&DAT_0001c01c,(undefined4 *)&DAT_0001c020);
  FUN_0001aee0((undefined4 *)&DAT_0001c000,(undefined4 *)&DAT_0001c018);
  return;
}



/* 0001af90 FUN_0001af90 */

/* Boundary evidence: original MIPS .pdata 0001af90..0001b09b. Semantic name remains unreviewed. */

undefined4 FUN_0001af90(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_00022740;
  puVar3 = DAT_0002273c;
  iVar4 = (int)DAT_0002273c - (int)DAT_00022740;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_0001afd4:
    param_1 = 0;
  }
  else {
    if (DAT_00022740 != (void *)0x0) {
      uVar1 = _msize(DAT_00022740);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_0001b048:
        if (pvVar2 == (void *)0x0) goto LAB_0001afd4;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_0001b048;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_0002273c = puVar3 + 1;
    *puVar3 = param_1;
    DAT_00022740 = pvVar2;
  }
  return param_1;
}



/* 0001b09c FUN_0001b09c */

/* Boundary evidence: original MIPS .pdata 0001b09c..0001b0cb. Semantic name remains unreviewed. */

undefined4 FUN_0001b09c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0001af90(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0001b31c FUN_0001b31c */

/* Boundary evidence: original MIPS .pdata 0001b31c..0001b33b. Semantic name remains unreviewed. */

void FUN_0001b31c(void)

{
  FUN_0001b09c(FUN_0001b3d8);
  return;
}



/* 0001b33c FUN_0001b33c */

/* Boundary evidence: original MIPS .pdata 0001b33c..0001b367. Semantic name remains unreviewed. */

void FUN_0001b33c(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00022728);
  FUN_0001b09c(FUN_0001b410);
  return;
}



/* 0001b368 FUN_0001b368 */

/* Boundary evidence: original MIPS .pdata 0001b368..0001b38b. Semantic name remains unreviewed. */

void FUN_0001b368(void)

{
  DAT_00021478 = FUN_000178ec();
  return;
}



/* 0001b38c FUN_0001b38c */

/* Boundary evidence: original MIPS .pdata 0001b38c..0001b3b3. Semantic name remains unreviewed. */

void FUN_0001b38c(void)

{
  DAT_0002168c = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0001b3b4 FUN_0001b3b4 */

/* Boundary evidence: original MIPS .pdata 0001b3b4..0001b3d7. Semantic name remains unreviewed. */

void FUN_0001b3b4(void)

{
  DAT_00021694 = FUN_000181e4();
  return;
}



/* 0001b3d8 FUN_0001b3d8 */

/* Boundary evidence: original MIPS .pdata 0001b3d8..0001b40f. Semantic name remains unreviewed. */

void FUN_0001b3d8(void)

{
  DAT_0002145c = 0;
  LocalFree(DAT_00021458);
  DAT_00021458 = (HLOCAL)0x0;
  return;
}



/* 0001b410 FUN_0001b410 */

/* Boundary evidence: original MIPS .pdata 0001b410..0001b42f. Semantic name remains unreviewed. */

void FUN_0001b410(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00022728);
  return;
}


