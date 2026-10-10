/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 401e14d8 FUN_401e14d8 */

/* Boundary evidence: original MIPS .pdata 401e14d8..401e15eb. Semantic name remains unreviewed. */

void FUN_401e14d8(HDC param_1,int *param_2,HGDIOBJ param_3)

{
  HGDIOBJ h;
  int iVar1;
  int h_00;
  int x;
  
  h = SelectObject(param_1,param_3);
  x = *param_2;
  iVar1 = param_2[2];
  h_00 = param_2[3] - param_2[1];
  PatBlt(param_1,x,param_2[1],iVar1 - x,1,0xf00021);
  PatBlt(param_1,x,param_2[3] + -1,iVar1 - x,1,0xf00021);
  iVar1 = param_2[1];
  PatBlt(param_1,x,iVar1,1,h_00,0xf00021);
  PatBlt(param_1,param_2[2] + -1,iVar1,1,h_00,0xf00021);
  SelectObject(param_1,h);
  return;
}



/* 401e15ec FUN_401e15ec */

/* Boundary evidence: original MIPS .pdata 401e15ec..401e16a7. Semantic name remains unreviewed. */

void FUN_401e15ec(HDC param_1,int param_2,uint param_3)

{
  COLORREF color;
  HBRUSH ho;
  tagRECT local_20;
  
  CopyRect(&local_20,(RECT *)(&DAT_401ef4e0 + param_2 * 4));
  local_20.left = local_20.left + -1;
  local_20.top = local_20.top + -1;
  local_20.right = local_20.right + 1;
  local_20.bottom = local_20.bottom + 1;
  if ((param_3 & 1) == 0) {
    color = GetSysColor(0x40000019);
  }
  else {
    color = 0;
  }
  ho = CreateSolidBrush(color);
  if (ho != (HBRUSH)0x0) {
    FUN_401e14d8(param_1,&local_20.left,ho);
    DeleteObject(ho);
  }
  return;
}



/* 401e16a8 FUN_401e16a8 */

/* Boundary evidence: original MIPS .pdata 401e16a8..401e185f. Semantic name remains unreviewed. */

void FUN_401e16a8(int param_1,uint param_2)

{
  HDC hdc;
  HPEN h;
  HGDIOBJ pvVar1;
  HGDIOBJ h_00;
  HWND hWnd;
  ushort *puVar2;
  tagRECT local_48;
  LOGPEN local_38;
  
  hWnd = *(HWND *)(param_1 + 0xc);
  puVar2 = (ushort *)(param_1 + 0x2a);
  if ((int)DAT_401ef8e0 <= (int)param_2) {
    puVar2 = (ushort *)(param_1 + 0x28);
  }
  hdc = GetDC(hWnd);
  if (hdc != (HDC)0x0) {
    local_38.lopnStyle = 0;
    local_38.lopnWidth.x = 1;
    local_38.lopnColor = GetSysColor(0x40000019);
    h = CreatePenIndirect(&local_38);
    pvVar1 = GetStockObject(5);
    h_00 = SelectObject(hdc,h);
    pvVar1 = SelectObject(hdc,pvVar1);
    CopyRect(&local_48,(RECT *)(&DAT_401ef4e0 + (uint)*puVar2 * 4));
    InflateRect(&local_48,3,3);
    Rectangle(hdc,local_48.left,local_48.top,local_48.right,local_48.bottom);
    *puVar2 = (ushort)param_2;
    CopyRect(&local_48,(RECT *)(&DAT_401ef4e0 + (param_2 & 0xffff) * 4));
    InflateRect(&local_48,3,3);
    Rectangle(hdc,local_48.left,local_48.top,local_48.right,local_48.bottom);
    DrawFocusRect(hdc,&local_48);
    if (h_00 != (HGDIOBJ)0x0) {
      SelectObject(hdc,h_00);
    }
    if (pvVar1 != (HGDIOBJ)0x0) {
      SelectObject(hdc,pvVar1);
    }
    if (h != (HPEN)0x0) {
      DeleteObject(h);
    }
    ReleaseDC(hWnd,hdc);
  }
  return;
}



/* 401e1860 FUN_401e1860 */

/* Boundary evidence: original MIPS .pdata 401e1860..401e1af3. Semantic name remains unreviewed. */

undefined4 FUN_401e1860(int param_1,uint *param_2,int param_3)

{
  ushort uVar1;
  HWND hWnd;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  hWnd = GetFocus();
  uVar2 = GetWindowLongW(hWnd,-0xc);
  if ((uVar2 & 0xffff) == 0x2d0) {
    uVar1 = *(ushort *)(param_3 + 0x2a);
  }
  else {
    if ((uVar2 & 0xffff) != 0x2d1) {
      return 0;
    }
    uVar1 = *(ushort *)(param_3 + 0x28);
  }
  uVar2 = (uint)uVar1;
  iVar4 = (int)(short)DAT_401ef8e0;
  if (param_1 == 0x23) {
    if (uVar2 == *(ushort *)(param_3 + 0x2a)) {
      uVar2 = (int)(short)DAT_401ef482 + 0xffffU & 0xffff;
      goto LAB_401e1a98;
    }
    uVar2 = (int)DAT_401ef8e4 + 0xffff;
LAB_401e1a94:
    uVar2 = uVar2 & 0xffff;
    goto LAB_401e1a98;
  }
  if (param_1 == 0x24) {
    if (uVar2 == *(ushort *)(param_3 + 0x2a)) {
      uVar2 = 0;
    }
    else {
      uVar2 = (uint)DAT_401ef8e0;
    }
    goto LAB_401e1a98;
  }
  if (param_1 == 0x25) {
    iVar3 = (int)DAT_401ef4d8;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (uVar2 == 0x80000000)) {
      trap(0x1800);
    }
    if ((int)uVar2 % iVar3 == 0) goto LAB_401e1a98;
LAB_401e1a48:
    uVar2 = uVar2 + 0xffff;
  }
  else if (param_1 == 0x26) {
    iVar3 = (int)DAT_401ef4d8;
    if (((int)uVar2 < iVar4 + iVar3) && ((iVar4 <= (int)uVar2 || ((int)uVar2 < iVar3))))
    goto LAB_401e1a98;
    uVar2 = uVar2 - iVar3;
  }
  else {
    if (param_1 == 0x27) {
      iVar3 = (int)DAT_401ef4d8;
      uVar2 = uVar2 + 1 & 0xffff;
      if (iVar3 == 0) {
        trap(0x1c00);
      }
      if ((iVar3 == -1) && (uVar2 == 0x80000000)) {
        trap(0x1800);
      }
      if ((int)uVar2 % iVar3 != 0) goto LAB_401e1a98;
      goto LAB_401e1a48;
    }
    if (param_1 != 0x28) goto LAB_401e1a98;
    iVar3 = (int)DAT_401ef4d8;
    if (iVar4 - iVar3 <= (int)uVar2) {
      if (((int)uVar2 < iVar4) || (DAT_401ef8e4 - iVar3 <= (int)uVar2)) goto LAB_401e1a98;
      uVar2 = iVar3 + uVar2;
      goto LAB_401e1a94;
    }
    uVar2 = iVar3 + uVar2;
  }
  uVar2 = uVar2 & 0xffff;
LAB_401e1a98:
  if ((DAT_401ef482 <= uVar2) && ((int)uVar2 < iVar4)) {
    uVar2 = (uint)*(ushort *)(param_3 + 0x2a);
  }
  *param_2 = uVar2;
  if ((uVar2 != *(ushort *)(param_3 + 0x2a)) && (uVar2 != *(ushort *)(param_3 + 0x28))) {
    return 1;
  }
  return 0;
}



/* 401e1af4 FUN_401e1af4 */

/* Boundary evidence: original MIPS .pdata 401e1af4..401e1c7f. Semantic name remains unreviewed. */

void FUN_401e1af4(int param_1)

{
  HWND pHVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  LPRECT lpRect;
  HWND hDlg;
  LPRECT lpRect_00;
  
  hDlg = *(HWND *)(param_1 + 0xc);
  pHVar1 = GetDlgItem(hDlg,0x2c6);
  GetClientRect(pHVar1,(LPRECT)(param_1 + 0x44));
  MapWindowPoints(pHVar1,hDlg,(LPPOINT)(param_1 + 0x44),2);
  pHVar1 = GetDlgItem(hDlg,0x2be);
  lpRect = (LPRECT)(param_1 + 100);
  GetClientRect(pHVar1,lpRect);
  MapWindowPoints(pHVar1,hDlg,(LPPOINT)lpRect,2);
  pHVar1 = GetDlgItem(hDlg,0x2c5);
  lpRect_00 = (LPRECT)(param_1 + 0x94);
  GetClientRect(pHVar1,lpRect_00);
  MapWindowPoints(pHVar1,hDlg,(LPPOINT)lpRect_00,2);
  iVar4 = *(int *)(param_1 + 0x6c);
  *(LONG *)(param_1 + 0x54) = lpRect->left;
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x68);
  *(int *)(param_1 + 0x5c) = iVar4;
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x70);
  *(int *)(param_1 + 0x54) = iVar4;
  iVar2 = (int)DAT_401ef4a0;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  *(short *)(param_1 + 0x26) =
       (short)*(undefined4 *)(param_1 + 0x70) - (short)*(undefined4 *)(param_1 + 0x68);
  iVar3 = lpRect_00->left;
  *(int *)(param_1 + 0x5c) = (iVar2 >> 1) + iVar4;
  iVar2 = *(int *)(param_1 + 0x9c) + iVar3;
  *(int *)(param_1 + 0x84) = iVar3;
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x9c);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0xa0);
  *(int *)(param_1 + 0x74) = iVar3;
  *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x9c);
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0xa0);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  *(int *)(param_1 + 0x7c) = iVar2 >> 1;
  *(int *)(param_1 + 0x84) = iVar2 >> 1;
  return;
}



/* 401e1c80 FUN_401e1c80 */

/* Boundary evidence: original MIPS .pdata 401e1c80..401e1e3b. Semantic name remains unreviewed. */

LRESULT FUN_401e1c80(HWND param_1,uint param_2,WPARAM param_3,int param_4)

{
  ushort uVar1;
  HWND pHVar2;
  LRESULT LVar3;
  LONG LVar4;
  LONG LVar5;
  HDC hDC;
  tagRECT tStack_30;
  
  if (6 < param_2) {
    if (param_2 < 9) {
      pHVar2 = GetParent(param_1);
      LVar4 = GetWindowLongW(pHVar2,8);
      if (LVar4 != 0) {
        LVar5 = GetWindowLongW(param_1,-0xc);
        if (LVar5 == 0x2d0) {
          uVar1 = *(ushort *)(LVar4 + 0x2a);
        }
        else {
          uVar1 = *(ushort *)(LVar4 + 0x28);
        }
        pHVar2 = GetParent(param_1);
        hDC = GetDC(pHVar2);
        CopyRect(&tStack_30,(RECT *)(&DAT_401ef4e0 + (uint)uVar1 * 4));
        InflateRect(&tStack_30,3,3);
        DrawFocusRect(hDC,&tStack_30);
        pHVar2 = GetParent(param_1);
        ReleaseDC(pHVar2,hDC);
        return 0;
      }
    }
    else {
      if (param_2 == 0x87) {
        if (param_4 == 0) {
          return 1;
        }
        if ((*(int *)(param_4 + 4) != 0x100) && (*(int *)(param_4 + 4) != 0x102)) {
          return 1;
        }
        if (*(int *)(param_4 + 8) != 0x20) {
          return 1;
        }
        return 5;
      }
      if ((param_2 == 0x100) || (param_2 == 0x102)) {
        pHVar2 = GetParent(param_1);
        LVar3 = SendMessageW(pHVar2,param_2,param_3,param_4);
        return LVar3;
      }
    }
  }
  LVar3 = CallWindowProcW(DAT_401ef498,param_1,param_2,param_3,param_4);
  return LVar3;
}



/* 401e1e3c FUN_401e1e3c */

/* Boundary evidence: original MIPS .pdata 401e1e3c..401e1eaf. Semantic name remains unreviewed. */

COLORREF FUN_401e1e3c(int param_1,COLORREF param_2)

{
  HDC hdc;
  
  if (((*(uint *)(*(int *)(param_1 + 4) + 0x14) & 0x80) != 0) &&
     (hdc = GetDC((HWND)0x0), hdc != (HDC)0x0)) {
    param_2 = GetNearestColor(hdc,param_2);
    ReleaseDC((HWND)0x0,hdc);
  }
  return param_2;
}



/* 401e1eb0 FUN_401e1eb0 */

/* Boundary evidence: original MIPS .pdata 401e1eb0..401e1f0b. Semantic name remains unreviewed. */

void FUN_401e1eb0(void)

{
  if (DAT_401ef4ac != (HGDIOBJ)0x0) {
    DeleteObject(DAT_401ef4ac);
    DAT_401ef4ac = (HGDIOBJ)0x0;
  }
  if (DAT_401ef4a8 != (HDC)0x0) {
    DeleteDC(DAT_401ef4a8);
    DAT_401ef4a8 = (HDC)0x0;
  }
  return;
}



/* 401e1f0c FUN_401e1f0c */

/* Boundary evidence: original MIPS .pdata 401e1f0c..401e1fa3. Semantic name remains unreviewed. */

void FUN_401e1f0c(int param_1,int param_2)

{
  HDC hDC;
  COLORREF CVar1;
  HWND hWnd;
  
  hWnd = *(HWND *)(param_1 + 0xc);
  hDC = GetDC(hWnd);
  FUN_401e15ec(hDC,(int)*(short *)(param_1 + 0x2c),0);
  FUN_401e15ec(hDC,param_2,1);
  ReleaseDC(hWnd,hDC);
  CVar1 = *(COLORREF *)((param_2 + 0x2c) * 4 + param_1);
  *(COLORREF *)(param_1 + 0x18) = CVar1;
  CVar1 = FUN_401e1e3c(param_1,CVar1);
  *(COLORREF *)(param_1 + 0x18) = CVar1;
  return;
}



/* 401e1fa4 FUN_401e1fa4 */

/* Boundary evidence: original MIPS .pdata 401e1fa4..401e2047. Semantic name remains unreviewed. */

void FUN_401e1fa4(int param_1,HDC param_2,LONG *param_3,COLORREF param_4)

{
  COLORREF color;
  HBRUSH hbr;
  tagRECT local_20;
  
  local_20.left = *param_3;
  local_20.top = param_3[1];
  local_20.right = param_3[2];
  local_20.bottom = param_3[3];
  DrawEdge(param_2,&local_20,10,0x200f);
  color = FUN_401e1e3c(param_1,param_4);
  hbr = CreateSolidBrush(color);
  if (hbr != (HBRUSH)0x0) {
    FillRect(param_2,&local_20,hbr);
    DeleteObject(hbr);
  }
  return;
}



/* 401e2048 FUN_401e2048 */

/* Boundary evidence: original MIPS .pdata 401e2048..401e20f7. Semantic name remains unreviewed. */

void FUN_401e2048(int param_1,HDC param_2,int param_3)

{
  if (((DAT_401ef8e0 <= param_3) || (param_3 < DAT_401ef482)) &&
     (FUN_401e1fa4(param_1,param_2,&DAT_401ef4e0 + param_3 * 4,
                   *(COLORREF *)((param_3 + 0x2c) * 4 + param_1)),
     param_3 == *(short *)(param_1 + 0x2c))) {
    FUN_401e15ec(param_2,param_3,1);
  }
  return;
}



/* 401e20f8 FUN_401e20f8 */

/* Boundary evidence: original MIPS .pdata 401e20f8..401e22eb. Semantic name remains unreviewed. */

undefined4 FUN_401e20f8(HWND param_1)

{
  HWND hWnd;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 local_20 [16];
  
  uVar9 = 0;
  hWnd = GetDlgItem(param_1,0x2d1);
  if (hWnd != (HWND)0x0) {
    if (DAT_401ef498 != 0) {
      SetWindowLongW(hWnd,-4,0x401e1c80);
    }
    GetWindowRect(hWnd,(LPRECT)local_20);
    ScreenToClient(param_1,(LPPOINT)local_20);
    ScreenToClient(param_1,(LPPOINT)(local_20 + 8));
    iVar5 = (int)DAT_401ef8e0;
    if ((-1 < iVar5) && (iVar4 = (int)(short)DAT_401ef8e4, DAT_401ef8e4 < 0x41)) {
      if (iVar5 < iVar4) {
        iVar1 = (int)DAT_401ef480;
        iVar3 = (int)DAT_401ef4d8;
        iVar2 = (int)DAT_401ef49c;
        iVar8 = iVar5;
        do {
          iVar7 = iVar8 - iVar5;
          if (iVar3 == 0) {
            trap(0x1c00);
          }
          if ((iVar3 == -1) && (iVar7 == -0x80000000)) {
            trap(0x1800);
          }
          iVar6 = (iVar7 % iVar3) * iVar1 + local_20._0_4_ + 2;
          (&DAT_401ef4e0)[iVar8 * 4] = iVar6;
          (&DAT_401ef4e8)[iVar8 * 4] = iVar1 + -3 + iVar6;
          if (iVar3 == 0) {
            trap(0x1c00);
          }
          if ((iVar3 == -1) && (iVar7 == -0x80000000)) {
            trap(0x1800);
          }
          iVar7 = (iVar7 / iVar3) * iVar2 + local_20._4_4_ + 2;
          (&DAT_401ef4e4)[iVar8 * 4] = iVar7;
          (&DAT_401ef4ec)[iVar8 * 4] = iVar2 + -3 + iVar7;
          iVar8 = (iVar8 + 1) * 0x10000 >> 0x10;
        } while (iVar8 < iVar4);
      }
      uVar9 = 1;
    }
  }
  return uVar9;
}



/* 401e22ec FUN_401e22ec */

/* Boundary evidence: original MIPS .pdata 401e22ec..401e242f. Semantic name remains unreviewed. */

void FUN_401e22ec(HWND param_1,int param_2,HDC param_3,RECT *param_4)

{
  short sVar1;
  HWND pHVar2;
  HWND pHVar3;
  int iVar4;
  
  if ((*(int *)(param_2 + 0xac) == 0) && (0 < DAT_401ef482)) {
    iVar4 = 0;
    do {
      FUN_401e2048(param_2,param_3,iVar4);
      iVar4 = (iVar4 + 1) * 0x10000 >> 0x10;
    } while (iVar4 < DAT_401ef482);
  }
  for (iVar4 = (int)DAT_401ef8e0; iVar4 < DAT_401ef8e4; iVar4 = (iVar4 + 1) * 0x10000 >> 0x10) {
    FUN_401e2048(param_2,param_3,iVar4);
  }
  pHVar2 = GetFocus();
  pHVar3 = GetDlgItem(param_1,0x2d0);
  if (pHVar2 == pHVar3) {
    sVar1 = *(short *)(param_2 + 0x2a);
  }
  else {
    pHVar3 = GetDlgItem(param_1,0x2d1);
    if (pHVar2 != pHVar3) goto LAB_401e23f0;
    sVar1 = *(short *)(param_2 + 0x28);
  }
  FUN_401e16a8(param_2,(int)sVar1);
LAB_401e23f0:
  if (*(int *)(param_2 + 0xa4) != 0) {
    FUN_401ed49c(param_2,param_3,param_4);
  }
  return;
}



/* 401e2430 FUN_401e2430 */

/* Boundary evidence: original MIPS .pdata 401e2430..401e274b. Semantic name remains unreviewed. */

uint FUN_401e2430(HWND param_1,uint param_2,HWND param_3,uint param_4)

{
  LONG LVar1;
  HWND pHVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar8 = 0;
  LVar1 = GetWindowLongW(param_1,8);
  if ((LVar1 != 0) || (param_2 == 0x110)) {
    if (param_2 == 2) {
      *(undefined4 *)(LVar1 + 0xa4) = 0;
      *(undefined4 *)(LVar1 + 0xac) = 0;
      pHVar2 = GetParent(param_1);
      *(HWND *)(LVar1 + 0xc) = pHVar2;
      FUN_401e1af4(LVar1);
      iVar5 = (int)DAT_401ef8e0;
      iVar6 = (&DAT_401ef4e0)[iVar5 * 4] - DAT_401ef2c0;
      iVar7 = (&DAT_401ef4e4)[iVar5 * 4] - DAT_401ef2c4;
      if (iVar5 < DAT_401ef8e4) {
        do {
          OffsetRect((LPRECT)(&DAT_401ef4e0 + iVar5 * 4),-iVar6,-iVar7);
          iVar5 = (iVar5 + 1) * 0x10000 >> 0x10;
        } while (iVar5 < DAT_401ef8e4);
      }
      SetWindowLongW(param_1,8,0);
    }
    else if (param_2 == 0x110) {
      SetWindowLongW(param_1,8,param_4);
      *(HWND *)(param_4 + 0xc) = param_1;
      *(undefined4 *)(param_4 + 0xa4) = 1;
      if ((*(uint *)(*(int *)(param_4 + 4) + 0x14) & 0x80) != 0) {
        pHVar2 = GetDlgItem(param_1,0x2db);
        ShowWindow(pHVar2,0);
      }
      FUN_401ed238(param_4);
      DAT_401ef2c0 = (&DAT_401ef4e0)[DAT_401ef8e0 * 4];
      DAT_401ef2c4 = (&DAT_401ef4e4)[DAT_401ef8e0 * 4];
      FUN_401e20f8(param_1);
      DVar3 = GetFileAttributesW(L"\\Windows\\peghelp.exe");
      if (DVar3 == 0xffffffff) {
        uVar4 = GetWindowLongW(param_1,-0x14);
        SetWindowLongW(param_1,-0x14,uVar4 & 0xfffffbff);
      }
      pHVar2 = GetDlgItem(param_1,0x2d1);
      SetWindowPos(pHVar2,(HWND)0x0,-1000,-1000,0,0,5);
      pHVar2 = GetDlgItem(param_1,0x2c6);
      ShowWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x2be);
      ShowWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x2c5);
      ShowWindow(pHVar2,0);
      pHVar2 = GetDlgItem(param_1,0x2d1);
      SetFocus(pHVar2);
    }
    else if (((param_2 == 0x111) && (((uint)param_3 & 0xffff) != 0)) &&
            (((uint)param_3 & 0xffff) < 4)) {
      DestroyWindow(*(HWND *)(LVar1 + 0x10));
      *(undefined4 *)(LVar1 + 0x10) = 0;
    }
    else {
      uVar8 = FUN_401e3260(param_1,param_2,param_3,param_4);
    }
  }
  return uVar8;
}



/* 401e274c FUN_401e274c */

/* Boundary evidence: original MIPS .pdata 401e274c..401e2803. Semantic name remains unreviewed. */

bool FUN_401e274c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)DAT_401ef8e4;
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if (*(int *)((iVar2 + 0x2c) * 4 + param_1) == param_2) break;
      iVar2 = (iVar2 + 1) * 0x10000 >> 0x10;
    } while (iVar2 < iVar1);
  }
  if (iVar2 < iVar1) {
    FUN_401e1f0c(param_1,iVar2);
    *(short *)(param_1 + 0x2c) = (short)iVar2;
    iVar1 = (int)DAT_401ef8e4;
  }
  return iVar2 < iVar1;
}



/* 401e2804 FUN_401e2804 */

/* Boundary evidence: original MIPS .pdata 401e2804..401e2b4b. Semantic name remains unreviewed. */

undefined4 FUN_401e2804(HWND param_1,int param_2)

{
  undefined4 *puVar1;
  HWND hWnd;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined1 local_38 [12];
  int local_2c;
  
  uVar8 = 0;
  hWnd = GetDlgItem(param_1,0x2d0);
  if (hWnd != (HWND)0x0) {
    DAT_401ef498 = GetWindowLongW(hWnd,-4);
    if (DAT_401ef498 != 0) {
      SetWindowLongW(hWnd,-4,0x401e1c80);
    }
    GetWindowRect(hWnd,(LPRECT)local_38);
    ScreenToClient(param_1,(LPPOINT)local_38);
    ScreenToClient(param_1,(LPPOINT)(local_38 + 8));
    local_38._4_4_ = local_38._4_4_ + 2;
    local_2c = local_2c + -2;
    iVar6 = (int)DAT_401ef4d8;
    local_38._8_4_ = local_38._8_4_ + -2;
    local_38._0_4_ = local_38._0_4_ + 2;
    if (iVar6 == 0) {
      trap(0x1c00);
    }
    if ((iVar6 == -1) && (local_38._8_4_ - local_38._0_4_ == -0x80000000)) {
      trap(0x1800);
    }
    DAT_401ef480 = (short)((int)(local_38._8_4_ - local_38._0_4_) / iVar6);
    iVar5 = (int)DAT_401ef480;
    iVar2 = 0;
    DAT_401ef49c = (short)((local_2c - local_38._4_4_) / 6);
    iVar4 = (int)DAT_401ef49c;
    iVar3 = (int)DAT_401ef8e0;
    DAT_401ef482 = 0;
    if (0 < iVar3) {
      iVar9 = 0;
      do {
        if (iVar6 == 0) {
          trap(0x1c00);
        }
        if ((iVar6 == -1) && (iVar9 == -0x80000000)) {
          trap(0x1800);
        }
        iVar7 = (iVar9 % iVar6) * iVar5 + local_38._0_4_;
        (&DAT_401ef4e0)[iVar9 * 4] = iVar7;
        (&DAT_401ef4e8)[iVar9 * 4] = iVar7 + iVar5 + -3;
        if (iVar6 == 0) {
          trap(0x1c00);
        }
        if ((iVar6 == -1) && (iVar9 == -0x80000000)) {
          trap(0x1800);
        }
        iVar7 = (iVar9 / iVar6) * iVar4 + local_38._4_4_;
        (&DAT_401ef4e4)[iVar9 * 4] = iVar7;
        (&DAT_401ef4ec)[iVar9 * 4] = iVar7 + iVar4 + -3;
        if (iVar2 <= iVar9) {
          uVar8 = 0xffffff;
          if ((DAT_401ef4dc == 4) || (DAT_401ef4dc == 2)) {
            if (iVar2 == 0) {
              puVar1 = &DAT_401e117c;
              goto LAB_401e2aa8;
            }
          }
          else if (iVar2 == 0) {
            puVar1 = &DAT_401e107c;
LAB_401e2aa8:
            uVar8 = puVar1[iVar9];
          }
          *(undefined4 *)((iVar9 + 0x2c) * 4 + param_2) = uVar8;
          iVar5 = (int)DAT_401ef480;
          iVar4 = (int)DAT_401ef49c;
          iVar3 = (int)DAT_401ef8e0;
          iVar2 = (int)DAT_401ef482;
          iVar6 = (int)DAT_401ef4d8;
        }
        iVar9 = (iVar9 + 1) * 0x10000 >> 0x10;
      } while (iVar9 < iVar3);
    }
    if (iVar2 == 0) {
      DAT_401ef482 = (short)iVar3;
    }
    uVar8 = FUN_401e20f8(param_1);
  }
  return uVar8;
}



/* 401e2b4c FUN_401e2b4c */

/* Boundary evidence: original MIPS .pdata 401e2b4c..401e325f. Semantic name remains unreviewed. */

undefined4 FUN_401e2b4c(HWND param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  HWND pHVar2;
  HDC pHVar3;
  HWND pHVar4;
  int iVar5;
  DWORD DVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint *puVar11;
  int iVar12;
  undefined4 uVar13;
  int nHeight;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  tagRECT local_38;
  
  iVar12 = *(int *)(param_3 + 4);
  pHVar2 = GetDlgItem(param_1,0x2c9);
  local_48 = 0;
  memset(&local_44,0,0xc);
  pHVar3 = GetDC((HWND)0x0);
  DAT_401ef4dc = GetDeviceCaps(pHVar3,0xc);
  ReleaseDC((HWND)0x0,pHVar3);
  if ((DAT_401ef4dc == 2) || (DAT_401ef4dc == 4)) {
    DAT_401ef8e0 = 0x10;
    DAT_401ef8e4 = 0x20;
  }
  else {
    DAT_401ef8e0 = 0x30;
    DAT_401ef8e4 = 0x40;
  }
  DAT_401ef8e2 = 0x10;
  DAT_401ef4d8 = 8;
  if (DAT_401ef4dc < 5) {
    *(uint *)(iVar12 + 0x14) = *(uint *)(iVar12 + 0x14) & 0xfffffffd | 4;
    pHVar4 = GetDlgItem(param_1,0x2cf);
    ShowWindow(pHVar4,0);
  }
  iVar5 = GetSystemMetrics(0);
  uVar13 = 1;
  if (iVar5 < 0x1d1) {
    *(undefined4 *)(param_3 + 0xa8) = 1;
    *(uint *)(iVar12 + 0x14) = *(uint *)(iVar12 + 0x14) & 0xfffffffd;
  }
  if (DAT_401ef4a8 == (HDC)0x0) {
    pHVar3 = GetDC(param_1);
    DAT_401ef4a8 = CreateCompatibleDC(pHVar3);
    ReleaseDC(param_1,pHVar3);
    if (DAT_401ef4a8 == (HDC)0x0) {
      return 0;
    }
  }
  *(HWND *)(param_3 + 0xc) = param_1;
  FUN_401e1af4(param_3);
  puVar11 = (uint *)(iVar12 + 0x14);
  if ((*puVar11 & 1) == 0) {
    *(undefined4 *)(param_3 + 0x18) = 0;
  }
  else {
    *(undefined4 *)(param_3 + 0x18) = *(undefined4 *)(iVar12 + 0xc);
  }
  if ((*puVar11 & 6) != 0) {
    pHVar4 = GetDlgItem(param_1,0x2cf);
    EnableWindow(pHVar4,0);
  }
  if ((*puVar11 & 0x80) != 0) {
    pHVar4 = GetDlgItem(param_1,0x2db);
    ShowWindow(pHVar4,0);
  }
  if ((*puVar11 & 2) == 0) {
    iVar5 = 0x2bf;
    do {
      pHVar4 = GetDlgItem(param_1,iVar5);
      EnableWindow(pHVar4,0);
      iVar5 = (iVar5 + 1) * 0x10000 >> 0x10;
    } while (iVar5 < 0x2c5);
    iVar5 = 0x2d3;
    do {
      pHVar4 = GetDlgItem(param_1,iVar5);
      EnableWindow(pHVar4,0);
      iVar5 = (iVar5 + 1) * 0x10000 >> 0x10;
    } while (iVar5 < 0x2d9);
    pHVar4 = GetDlgItem(param_1,0x2c8);
    EnableWindow(pHVar4,0);
    EnableWindow(pHVar2,0);
    pHVar4 = GetDlgItem(param_1,0x2db);
    EnableWindow(pHVar4,0);
    *(undefined4 *)(param_3 + 0xa4) = 0;
    pHVar4 = GetDlgItem(param_1,0x2d0);
    GetWindowRect(pHVar4,&local_38);
    pHVar4 = GetDlgItem(param_1,0x2c5);
    GetWindowRect(pHVar4,&local_38);
    GetWindowRect(param_1,(LPRECT)(param_3 + 0x34));
    SystemParametersInfoW(0x30,0,&local_48,0);
    iVar5 = (short)local_38.right + local_38.left;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar8 = (iVar5 >> 1) - ((LPRECT)(param_3 + 0x34))->left;
    nHeight = *(int *)(param_3 + 0x40) - *(int *)(param_3 + 0x38);
    iVar5 = (local_3c - local_44) - nHeight;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar9 = (local_40 - iVar8) - local_48;
    if (iVar9 < 0) {
      iVar9 = iVar9 + 1;
    }
    MoveWindow(param_1,(iVar9 >> 1) + local_48,(iVar5 >> 1) + local_44,iVar8,nHeight,0);
  }
  else {
    FUN_401ed238(param_3);
    *(undefined4 *)(param_3 + 0xa4) = 1;
    FUN_401ecb4c(*(uint *)(param_3 + 0x18));
    *(undefined2 *)(param_3 + 0x1c) = DAT_401ef488;
    *(undefined2 *)(param_3 + 0x1e) = DAT_401ef484;
    *(undefined2 *)(param_3 + 0x20) = DAT_401ef486;
    FUN_401ec988(0,param_3);
    FUN_401ec8c8(0,param_3);
    GetWindowRect(param_1,&local_38);
    SystemParametersInfoW(0x30,0,&local_48,0);
    iVar5 = (local_3c - local_44) - (local_38.bottom - local_38.top);
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar8 = (local_40 - (local_38.right - local_38.left)) - local_48;
    if (iVar8 < 0) {
      iVar8 = iVar8 + 1;
    }
    MoveWindow(param_1,(iVar8 >> 1) + local_48,(iVar5 >> 1) + local_44,
               local_38.right - local_38.left,local_38.bottom - local_38.top,0);
  }
  FUN_401e2804(param_1,param_3);
  iVar5 = (int)DAT_401ef8e0;
  puVar10 = *(undefined4 **)(iVar12 + 0x10);
  iVar8 = DAT_401ef8e2 + iVar5;
  for (; iVar5 < iVar8; iVar5 = (iVar5 + 1) * 0x10000 >> 0x10) {
    *(undefined4 *)((iVar5 + 0x2c) * 4 + param_3) = *puVar10;
    puVar10 = puVar10 + 1;
    iVar8 = (int)DAT_401ef8e2 + (int)DAT_401ef8e0;
  }
  *(undefined2 *)(param_3 + 0x2a) = 0;
  *(undefined2 *)(param_3 + 0x2c) = 0;
  *(short *)(param_3 + 0x28) = DAT_401ef8e0;
  FUN_401e274c(param_3,*(int *)(param_3 + 0x18));
  uVar1 = *(ushort *)(param_3 + 0x2c);
  if (uVar1 < *(ushort *)(param_3 + 0x28)) {
    *(ushort *)(param_3 + 0x2a) = uVar1;
  }
  else {
    *(ushort *)(param_3 + 0x28) = uVar1;
  }
  DVar6 = GetFileAttributesW(L"\\Windows\\peghelp.exe");
  if (DVar6 == 0xffffffff) {
    uVar7 = GetWindowLongW(param_1,-0x14);
    SetWindowLongW(param_1,-0x14,uVar7 & 0xfffffbff);
  }
  uVar7 = GetWindowLongW(pHVar2,-0x10);
  SetWindowLongW(pHVar2,-0x10,uVar7 & 0xfffeffff);
  if (*(code **)(iVar12 + 0x1c) != (code *)0x0) {
    uVar13 = (**(code **)(iVar12 + 0x1c))(param_1,0x110,param_2,iVar12);
  }
  pHVar2 = GetDlgItem(param_1,0x2d0);
  SetWindowPos(pHVar2,(HWND)0x0,-1000,-1000,0,0,5);
  pHVar2 = GetDlgItem(param_1,0x2d1);
  SetWindowPos(pHVar2,(HWND)0x0,-1000,-1000,0,0,5);
  pHVar2 = GetDlgItem(param_1,0x2c6);
  ShowWindow(pHVar2,0);
  pHVar2 = GetDlgItem(param_1,0x2be);
  ShowWindow(pHVar2,0);
  pHVar2 = GetDlgItem(param_1,0x2c5);
  ShowWindow(pHVar2,0);
  return uVar13;
}



/* 401e3260 FUN_401e3260 */

/* Boundary evidence: original MIPS .pdata 401e3260..401e47ef. Semantic name remains unreviewed. */

uint FUN_401e3260(HWND param_1,uint param_2,HWND param_3,uint param_4)

{
  ushort uVar1;
  LONG dwInitParam;
  HWND pHVar2;
  HWND pHVar3;
  int iVar4;
  BOOL BVar5;
  HCURSOR pHVar6;
  HDC pHVar7;
  UINT UVar8;
  uint uVar9;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW lpTemplate;
  COLORREF CVar10;
  RECT *pRVar11;
  int iVar12;
  int iVar13;
  code *pcVar14;
  int iVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  uint uVar19;
  short sVar20;
  short sVar21;
  int iVar22;
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  POINT pt_04;
  POINT pt_05;
  POINT pt_06;
  int local_b8 [2];
  RECT local_b0;
  short local_a0 [4];
  undefined1 auStack_98 [16];
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  tagPAINTSTRUCT local_78;
  WCHAR aWStack_38 [4];
  uint local_30;
  
  local_30 = DAT_401ef2a8;
  uVar19 = 0;
  dwInitParam = GetWindowLongW(param_1,8);
  if (dwInitParam == 0) {
    if (param_2 != 0x110) {
      if (DAT_401ef4d4 != (code *)0x0) {
        uVar19 = (*DAT_401ef4d4)(param_1,param_2,param_3,param_4);
      }
      goto LAB_401e47b4;
    }
  }
  else {
    pcVar14 = *(code **)(*(int *)(dwInitParam + 4) + 0x1c);
    if ((pcVar14 != (code *)0x0) &&
       (uVar19 = (*pcVar14)(param_1,param_2,param_3,param_4), uVar19 != 0)) {
      if ((param_2 == 0x111) && (((uint)param_3 & 0xffff) == 2)) {
        DAT_401ef4a4 = 1;
      }
      goto LAB_401e47b4;
    }
  }
  uVar19 = 1;
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_401e7f58(param_1,8);
      pHVar6 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
      pHVar6 = SetCursor(pHVar6);
      SetWindowLongW(param_1,8,param_4);
      DAT_401ef4d4 = (code *)0x0;
      FUN_401e2b4c(param_1,param_3,param_4);
      pHVar2 = GetDlgItem(param_1,0x2bf);
      ImmAssociateContext(pHVar2,(HIMC)0x0);
      pHVar2 = GetDlgItem(param_1,0x2c0);
      ImmAssociateContext(pHVar2,(HIMC)0x0);
      pHVar2 = GetDlgItem(param_1,0x2c1);
      ImmAssociateContext(pHVar2,(HIMC)0x0);
      pHVar2 = GetDlgItem(param_1,0x2c2);
      ImmAssociateContext(pHVar2,(HIMC)0x0);
      pHVar2 = GetDlgItem(param_1,0x2c3);
      ImmAssociateContext(pHVar2,(HIMC)0x0);
      pHVar2 = GetDlgItem(param_1,0x2c4);
      ImmAssociateContext(pHVar2,(HIMC)0x0);
      SetCursor(pHVar6);
      pHVar2 = GetDlgItem(param_1,0x2d0);
      SetFocus(pHVar2);
    }
    else if (param_2 == 3) {
      if (dwInitParam != 0) {
        FUN_401e1af4(dwInitParam);
      }
    }
    else {
      if (param_2 == 0xf) {
        BeginPaint(param_1,&local_78);
        FUN_401e22ec(param_1,dwInitParam,local_78.hdc,&local_78.rcPaint);
        EndPaint(param_1,&local_78);
        goto LAB_401e47b4;
      }
      if (param_2 == 0x53) {
        BVar5 = IsWindowEnabled(param_1);
        if (BVar5 != 0) {
          CreateProcessW(L"peghelp",(LPWSTR)PTR_u_file_wince_htm_Color_dialog_box_401ef228,
                         (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,
                         (LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
        }
        goto LAB_401e47b4;
      }
      if (param_2 == 0x87) {
        FUN_401ee698(local_30);
        return 0xd;
      }
      if (param_2 == 0x100) {
        iVar4 = FUN_401e1860((int)param_3,(uint *)local_a0,dwInitParam);
        if (iVar4 != 0) {
          FUN_401e16a8(dwInitParam,(int)local_a0[0]);
        }
        goto LAB_401e47b4;
      }
      if (param_2 == 0x102) {
        if (param_3 != (HWND)0x20) goto LAB_401e47b4;
        pHVar2 = GetDlgItem(param_1,0x2d0);
        pHVar3 = GetFocus();
        if (pHVar3 == pHVar2) {
          uVar1 = *(ushort *)(dwInitParam + 0x2a);
        }
        else {
          pHVar2 = GetDlgItem(param_1,0x2d1);
          pHVar3 = GetFocus();
          if (pHVar3 != pHVar2) goto LAB_401e354c;
          uVar1 = *(ushort *)(dwInitParam + 0x28);
        }
        CVar10 = *(COLORREF *)((uVar1 + 0x2c) * 4 + dwInitParam);
        *(COLORREF *)(dwInitParam + 0x18) = CVar10;
        CVar10 = FUN_401e1e3c(dwInitParam,CVar10);
        *(COLORREF *)(dwInitParam + 0x18) = CVar10;
        if (*(int *)(dwInitParam + 0xa4) != 0) {
          FUN_401ed000(dwInitParam);
          FUN_401ec8c8(0,dwInitParam);
          FUN_401ec988(0,dwInitParam);
        }
        InvalidateRect(param_1,(RECT *)(dwInitParam + 0x94),0);
        FUN_401e1f0c(dwInitParam,(int)(short)uVar1);
        *(ushort *)(dwInitParam + 0x2c) = uVar1;
        goto LAB_401e47b4;
      }
    }
LAB_401e354c:
    uVar19 = 0;
    goto LAB_401e47b4;
  }
  if (param_2 != 0x111) {
    sVar20 = (short)param_4;
    sVar21 = (short)(param_4 >> 0x10);
    if (param_2 == 0x200) {
      if (DAT_401ef494 == 0) goto LAB_401e47b4;
    }
    else if (param_2 != 0x201) {
      if (param_2 == 0x202) {
        if (DAT_401ef494 != 0) {
          DAT_401ef494 = 0;
          SetCapture((HWND)0x0);
          pRVar11 = (RECT *)(dwInitParam + 0x44);
          pt.y = (int)sVar21;
          pt.x = (int)sVar20;
          BVar5 = PtInRect(pRVar11,pt);
          if (BVar5 == 0) {
            pRVar11 = (RECT *)(dwInitParam + 100);
            pt_00.y = (int)sVar21;
            pt_00.x = (int)sVar20;
            BVar5 = PtInRect(pRVar11,pt_00);
            if (BVar5 == 0) goto LAB_401e47b4;
            pHVar7 = GetDC(param_1);
            FUN_401ebd9c(pHVar7,(int)*(short *)(dwInitParam + 0x32),dwInitParam);
            ReleaseDC(param_1,pHVar7);
          }
          else {
            pHVar7 = GetDC(param_1);
            *(uint *)(dwInitParam + 0x2e) = param_4;
            FUN_401ec0b8(pHVar7,(int)sVar20,(int)sVar21,dwInitParam);
            FUN_401ed49c(dwInitParam,pHVar7,(RECT *)(dwInitParam + 100));
            ReleaseDC(param_1,pHVar7);
          }
          ValidateRect(param_1,pRVar11);
        }
        goto LAB_401e47b4;
      }
      if (param_2 == 0x30f) {
        if (*(int *)(dwInitParam + 0x14) == 0) goto LAB_401e47b4;
        pHVar7 = GetDC(param_1);
        SelectPalette(pHVar7,*(HPALETTE *)(dwInitParam + 0x14),0);
        UVar8 = RealizePalette(pHVar7);
        ReleaseDC(param_1,pHVar7);
        if ((int)UVar8 < 1) goto LAB_401e47b4;
      }
      else {
        if (param_2 != 0x311) goto LAB_401e354c;
        if ((*(int *)(dwInitParam + 0x14) == 0) || (param_3 == param_1)) goto LAB_401e47b4;
      }
      pRVar11 = (RECT *)0x0;
LAB_401e3704:
      InvalidateRect(param_1,pRVar11,0);
      goto LAB_401e47b4;
    }
    iVar4 = (int)sVar20;
    iVar13 = (int)sVar21;
    pt_01.y = iVar13;
    pt_01.x = iVar4;
    BVar5 = PtInRect((RECT *)(dwInitParam + 0x84),pt_01);
    if (BVar5 != 0) {
      FUN_401ed130(dwInitParam);
    }
    pRVar11 = (RECT *)(dwInitParam + 0x44);
    pt_02.y = iVar13;
    pt_02.x = iVar4;
    BVar5 = PtInRect(pRVar11,pt_02);
    if (BVar5 == 0) {
      pt_03.y = iVar13;
      pt_03.x = iVar4;
      BVar5 = PtInRect((RECT *)(dwInitParam + 100),pt_03);
      if ((BVar5 == 0) &&
         (pt_04.y = iVar13, pt_04.x = iVar4, BVar5 = PtInRect((RECT *)(dwInitParam + 0x54),pt_04),
         BVar5 == 0)) {
        local_b0.top = DAT_401ef4e4;
        local_b0.left = DAT_401ef4e0;
        local_b0.right = *(int *)(&DAT_401ef4d8 + DAT_401ef8e0 * 8) + 3;
        local_b0.bottom = (&DAT_401ef4dc)[DAT_401ef8e0 * 4] + 3;
        pt_05.y = iVar13;
        pt_05.x = iVar4;
        BVar5 = PtInRect(&local_b0,pt_05);
        if ((BVar5 == 0) || (*(int *)(dwInitParam + 0xac) != 0)) {
          local_b0.left = (&DAT_401ef4e0)[DAT_401ef8e0 * 4];
          local_b0.top = (&DAT_401ef4e4)[DAT_401ef8e0 * 4];
          local_b0.right = *(int *)(&DAT_401ef4d8 + DAT_401ef8e4 * 8) + 3;
          local_b0.bottom = (&DAT_401ef4dc)[DAT_401ef8e4 * 4] + 3;
          pt_06.y = iVar13;
          pt_06.x = iVar4;
          BVar5 = PtInRect(&local_b0,pt_06);
          if (BVar5 == 0) goto LAB_401e354c;
          pHVar2 = GetDlgItem(param_1,0x2d1);
          iVar4 = (int)DAT_401ef4d8;
          iVar13 = (int)DAT_401ef8e2 / iVar4;
          if (iVar4 == 0) {
            trap(0x1c00);
          }
          if ((iVar4 == -1) && (DAT_401ef8e2 == -0x80000000)) {
            trap(0x1800);
          }
          iVar4 = (int)DAT_401ef8e0;
        }
        else {
          pHVar2 = GetDlgItem(param_1,0x2d0);
          iVar4 = (int)DAT_401ef4d8;
          iVar13 = (int)DAT_401ef8e0 / iVar4;
          if (iVar4 == 0) {
            trap(0x1c00);
          }
          if ((iVar4 == -1) && (DAT_401ef8e0 == -0x80000000)) {
            trap(0x1800);
          }
          iVar4 = 0;
        }
        pHVar3 = GetFocus();
        if (pHVar2 != pHVar3) {
          SetFocus(pHVar2);
        }
        if ((param_4 >> 0x10 < (local_b0.bottom & 0xffffU)) &&
           ((param_4 & 0xffff) < (local_b0.right & 0xffffU))) {
          iVar12 = (int)DAT_401ef480;
          iVar22 = (param_4 & 0xffff) - local_b0.left;
          if (iVar12 == 0) {
            trap(0x1c00);
          }
          if ((iVar12 == -1) && (iVar22 == -0x80000000)) {
            trap(0x1800);
          }
          if (iVar22 % iVar12 < iVar12 + -3) {
            iVar12 = (int)DAT_401ef49c;
            iVar16 = (param_4 >> 0x10) - local_b0.top;
            if (iVar12 == 0) {
              trap(0x1c00);
            }
            if ((iVar12 == -1) && (iVar16 == -0x80000000)) {
              trap(0x1800);
            }
            if (iVar16 % iVar12 < iVar12 + -3) {
              iVar12 = local_b0.bottom - local_b0.top;
              if (iVar12 == 0) {
                trap(0x1c00);
              }
              if ((iVar12 == -1) && (iVar16 * iVar13 == -0x80000000)) {
                trap(0x1800);
              }
              iVar15 = (local_b0.right - local_b0.left) * 0x10000 >> 0x10;
              iVar22 = iVar22 * DAT_401ef4d8;
              if (iVar15 == 0) {
                trap(0x1c00);
              }
              if ((iVar15 == -1) && (iVar22 == -0x80000000)) {
                trap(0x1800);
              }
              iVar4 = (((iVar16 * iVar13) / iVar12) * (int)DAT_401ef4d8 + iVar22 / iVar15 + iVar4) *
                      0x10000;
              uVar9 = iVar4 >> 0x10;
              if ((((int)uVar9 < (int)DAT_401ef482) || ((int)DAT_401ef8e0 <= (int)uVar9)) &&
                 ((uVar9 & 0xffff) < 0x40)) {
                FUN_401e1f0c(dwInitParam,uVar9);
                *(short *)(dwInitParam + 0x2c) = (short)((uint)iVar4 >> 0x10);
                FUN_401e16a8(dwInitParam,uVar9);
                uVar1 = *(ushort *)(dwInitParam + 0x2c);
                if ((int)uVar9 < (int)DAT_401ef8e0) {
                  *(ushort *)(dwInitParam + 0x2a) = uVar1;
                }
                else {
                  *(ushort *)(dwInitParam + 0x28) = uVar1;
                }
                CVar10 = *(COLORREF *)((uVar1 + 0x2c) * 4 + dwInitParam);
                *(COLORREF *)(dwInitParam + 0x18) = CVar10;
                CVar10 = FUN_401e1e3c(dwInitParam,CVar10);
                *(COLORREF *)(dwInitParam + 0x18) = CVar10;
                pHVar7 = GetDC(param_1);
                if (*(int *)(dwInitParam + 0xa4) != 0) {
                  FUN_401ed000(dwInitParam);
                  FUN_401ec8c8(0,dwInitParam);
                  FUN_401ec988(0,dwInitParam);
                  FUN_401ed49c(dwInitParam,pHVar7,(RECT *)(dwInitParam + 0x94));
                }
                if (*(int *)(dwInitParam + 0xac) == 0) {
                  FUN_401e2048(dwInitParam,pHVar7,(int)*(short *)(dwInitParam + 0x2a));
                }
                FUN_401e2048(dwInitParam,pHVar7,(int)*(short *)(dwInitParam + 0x28));
                ReleaseDC(param_1,pHVar7);
              }
            }
          }
        }
        goto LAB_401e47b4;
      }
      pHVar7 = GetDC(param_1);
      FUN_401ebe7c(pHVar7,dwInitParam);
      *(short *)(dwInitParam + 0x32) = sVar21;
      FUN_401ebd9c(pHVar7,(int)sVar21,dwInitParam);
      FUN_401ec520(0x2c1,dwInitParam);
      FUN_401ec8c8(0x2c1,dwInitParam);
      uVar9 = FUN_401ece60((uint)*(ushort *)(dwInitParam + 0x1c),
                           (uint)*(ushort *)(dwInitParam + 0x20),
                           (uint)*(ushort *)(dwInitParam + 0x1e));
      *(uint *)(dwInitParam + 0x18) = uVar9;
      CVar10 = FUN_401e1e3c(dwInitParam,uVar9);
      *(COLORREF *)(dwInitParam + 0x18) = CVar10;
      FUN_401ed49c(dwInitParam,pHVar7,(RECT *)(dwInitParam + 0x94));
      ReleaseDC(param_1,pHVar7);
      pRVar11 = (RECT *)(dwInitParam + 0x54);
      ValidateRect(param_1,pRVar11);
      ValidateRect(param_1,(RECT *)(dwInitParam + 0x94));
      FUN_401ec988(0,dwInitParam);
      if (DAT_401ef494 != 0) goto LAB_401e47b4;
      SetCapture(param_1);
    }
    else {
      if (param_2 == 0x201) {
        pHVar7 = GetDC(param_1);
        FUN_401ebf04(pHVar7,dwInitParam);
        ReleaseDC(param_1,pHVar7);
      }
      *(short *)(dwInitParam + 0x2e) = sVar20;
      FUN_401ec520(0x2bf,dwInitParam);
      FUN_401ec8c8(0x2bf,dwInitParam);
      *(short *)(dwInitParam + 0x30) = sVar21;
      FUN_401ec520(0x2c0,dwInitParam);
      FUN_401ec8c8(0x2c0,dwInitParam);
      uVar9 = FUN_401ece60((uint)*(ushort *)(dwInitParam + 0x1c),
                           (uint)*(ushort *)(dwInitParam + 0x20),
                           (uint)*(ushort *)(dwInitParam + 0x1e));
      *(uint *)(dwInitParam + 0x18) = uVar9;
      CVar10 = FUN_401e1e3c(dwInitParam,uVar9);
      *(COLORREF *)(dwInitParam + 0x18) = CVar10;
      pHVar7 = GetDC(param_1);
      FUN_401ed49c(dwInitParam,pHVar7,(RECT *)(dwInitParam + 100));
      FUN_401ed49c(dwInitParam,pHVar7,(RECT *)(dwInitParam + 0x94));
      ReleaseDC(param_1,pHVar7);
      FUN_401ec988(0,dwInitParam);
      if (DAT_401ef494 != 0) goto LAB_401e47b4;
      SetCapture(param_1);
    }
    CopyRect((LPRECT)auStack_98,pRVar11);
    ClientToScreen(param_1,(LPPOINT)auStack_98);
    ClientToScreen(param_1,(LPPOINT)(auStack_98 + 8));
    DAT_401ef494 = 1;
    goto LAB_401e47b4;
  }
  if (dwInitParam == 0) goto LAB_401e354c;
  uVar9 = (uint)param_3 & 0xffff;
  if (uVar9 < 0x2c2) {
    if (uVar9 != 0x2c1) {
      if (uVar9 == 1) {
        *(undefined4 *)(*(int *)(dwInitParam + 4) + 0xc) = *(undefined4 *)(dwInitParam + 0x18);
LAB_401e421c:
        if (DAT_401ef494 != 0) {
          DAT_401ef494 = 0;
          SetCapture((HWND)0x0);
        }
        iVar4 = (int)DAT_401ef8e0;
        puVar18 = *(undefined4 **)(*(int *)(dwInitParam + 4) + 0x10);
        if (iVar4 < DAT_401ef8e2 + iVar4) {
          puVar17 = (undefined4 *)((iVar4 + 0x2c) * 4 + dwInitParam);
          do {
            iVar4 = iVar4 + 1;
            *puVar18 = *puVar17;
            puVar18 = puVar18 + 1;
            puVar17 = puVar17 + 1;
          } while (iVar4 < (int)DAT_401ef8e2 + (int)DAT_401ef8e0);
        }
        if (uVar9 != 1) {
          uVar19 = 0;
        }
      }
      else {
        if (uVar9 == 2) {
          DAT_401ef4a4 = 1;
          goto LAB_401e421c;
        }
        if (uVar9 != 3) {
          if (uVar9 == 0x2bf) {
            if ((uint)param_3 >> 0x10 != 0x300) {
              if (((uint)param_3 >> 0x10 != 0x200) ||
                 (GetDlgItemInt(param_1,0x2bf,local_b8,0), local_b8[0] != 0)) goto LAB_401e47b4;
              iVar4 = 0x2bf;
LAB_401e41f0:
              FUN_401ec8c8(iVar4,dwInitParam);
              goto LAB_401e47b4;
            }
            UVar8 = GetDlgItemInt(param_1,0x2bf,local_b8,0);
            uVar9 = UVar8 & 0xffff;
            if (local_b8[0] == 0) {
              UVar8 = GetDlgItemTextW(param_1,0x2bf,aWStack_38,2);
              if (UVar8 != 0) {
                FUN_401ec8c8(0x2bf,dwInitParam);
                SendDlgItemMessageW(param_1,0x2bf,0xb1,0,-1);
              }
              goto LAB_401e47b4;
            }
            if (0xef < uVar9) {
              uVar9 = 0xef;
              SetDlgItemInt(param_1,0x2bf,0xef,0);
            }
            if (uVar9 == *(ushort *)(dwInitParam + 0x1c)) goto LAB_401e47b4;
            pHVar7 = GetDC(param_1);
            FUN_401ebf04(pHVar7,dwInitParam);
            *(short *)(dwInitParam + 0x1c) = (short)uVar9;
            uVar9 = FUN_401ece60(uVar9,(uint)*(ushort *)(dwInitParam + 0x20),
                                 (uint)*(ushort *)(dwInitParam + 0x1e));
            *(uint *)(dwInitParam + 0x18) = uVar9;
            CVar10 = FUN_401e1e3c(dwInitParam,uVar9);
            *(COLORREF *)(dwInitParam + 0x18) = CVar10;
            FUN_401ec988(0,dwInitParam);
            iVar4 = 0x2bf;
          }
          else {
            if (uVar9 != 0x2c0) goto LAB_401e47b4;
            if ((uint)param_3 >> 0x10 != 0x300) {
              if (((uint)param_3 >> 0x10 != 0x200) ||
                 (GetDlgItemInt(param_1,0x2c0,local_b8,0), local_b8[0] != 0)) goto LAB_401e47b4;
              iVar4 = 0x2c0;
              goto LAB_401e41f0;
            }
            UVar8 = GetDlgItemInt(param_1,0x2c0,local_b8,0);
            uVar9 = UVar8 & 0xffff;
            if (local_b8[0] == 0) {
              UVar8 = GetDlgItemTextW(param_1,0x2c0,aWStack_38,2);
              if (UVar8 != 0) {
                FUN_401ec8c8(0x2c0,dwInitParam);
                SendDlgItemMessageW(param_1,0x2c0,0xb1,0,-1);
              }
              goto LAB_401e47b4;
            }
            if (0xf0 < uVar9) {
              uVar9 = 0xf0;
              SetDlgItemInt(param_1,0x2c0,0xf0,0);
            }
            if (uVar9 == *(ushort *)(dwInitParam + 0x1e)) goto LAB_401e47b4;
            pHVar7 = GetDC(param_1);
            FUN_401ebf04(pHVar7,dwInitParam);
            *(short *)(dwInitParam + 0x1e) = (short)uVar9;
            uVar9 = FUN_401ece60((uint)*(ushort *)(dwInitParam + 0x1c),
                                 (uint)*(ushort *)(dwInitParam + 0x20),uVar9);
            *(uint *)(dwInitParam + 0x18) = uVar9;
            CVar10 = FUN_401e1e3c(dwInitParam,uVar9);
            *(COLORREF *)(dwInitParam + 0x18) = CVar10;
            FUN_401ec988(0,dwInitParam);
            iVar4 = 0x2c0;
          }
          FUN_401ec75c(iVar4,dwInitParam);
          FUN_401ec0b8(pHVar7,(int)*(short *)(dwInitParam + 0x2e),
                       (int)*(short *)(dwInitParam + 0x30),dwInitParam);
          ReleaseDC(param_1,pHVar7);
          InvalidateRect(param_1,(RECT *)(dwInitParam + 100),0);
          goto LAB_401e4028;
        }
      }
      if ((*(uint *)(*(int *)(dwInitParam + 4) + 0x14) & 0x10) != 0) {
        DAT_401ef4d4 = *(code **)(*(int *)(dwInitParam + 4) + 0x1c);
      }
      if (uVar9 != 3) {
        param_4 = uVar19;
      }
      EndDialog(param_1,param_4);
      goto LAB_401e47b4;
    }
    if ((uint)param_3 >> 0x10 != 0x300) {
      if (((uint)param_3 >> 0x10 != 0x200) ||
         (GetDlgItemInt(param_1,0x2c1,local_b8,0), local_b8[0] != 0)) goto LAB_401e47b4;
      iVar4 = 0x2c1;
      goto LAB_401e41f0;
    }
    UVar8 = GetDlgItemInt(param_1,0x2c1,local_b8,0);
    uVar9 = UVar8 & 0xffff;
    if (local_b8[0] == 0) {
      UVar8 = GetDlgItemTextW(param_1,0x2c1,aWStack_38,2);
      if (UVar8 != 0) {
        FUN_401ec8c8(0x2c1,dwInitParam);
        SendDlgItemMessageW(param_1,0x2c1,0xb1,0,-1);
      }
      goto LAB_401e47b4;
    }
    if (0xf0 < uVar9) {
      uVar9 = 0xf0;
      SetDlgItemInt(param_1,0x2c1,0xf0,0);
    }
    if (uVar9 == *(ushort *)(dwInitParam + 0x20)) goto LAB_401e47b4;
    pHVar7 = GetDC(param_1);
    FUN_401ebe7c(pHVar7,dwInitParam);
    *(short *)(dwInitParam + 0x20) = (short)uVar9;
    FUN_401ec75c(0x2c1,dwInitParam);
    uVar9 = FUN_401ece60((uint)*(ushort *)(dwInitParam + 0x1c),uVar9,
                         (uint)*(ushort *)(dwInitParam + 0x1e));
    *(uint *)(dwInitParam + 0x18) = uVar9;
    CVar10 = FUN_401e1e3c(dwInitParam,uVar9);
    *(COLORREF *)(dwInitParam + 0x18) = CVar10;
    FUN_401ec988(0,dwInitParam);
    FUN_401ebd9c(pHVar7,(int)*(short *)(dwInitParam + 0x32),dwInitParam);
    ReleaseDC(param_1,pHVar7);
LAB_401e4028:
    InvalidateRect(param_1,(RECT *)(dwInitParam + 0x94),0);
  }
  else {
    if (uVar9 < 0x2c2) goto LAB_401e47b4;
    if (uVar9 < 0x2c5) {
      if ((uint)param_3 >> 0x10 != 0x300) {
        if (((uint)param_3 >> 0x10 == 0x200) &&
           (GetDlgItemInt(param_1,uVar9,local_b8,0), local_b8[0] == 0)) {
          FUN_401ec988((int)(short)param_3,dwInitParam);
        }
        goto LAB_401e47b4;
      }
      FUN_401ed7e4((int)(short)param_3,dwInitParam);
      pRVar11 = (RECT *)(dwInitParam + 0x94);
      goto LAB_401e3704;
    }
    if (uVar9 == 0x2c8) {
      *(undefined4 *)((*(ushort *)(dwInitParam + 0x28) + 0x2c) * 4 + dwInitParam) =
           *(undefined4 *)(dwInitParam + 0x18);
      InvalidateRect(param_1,(RECT *)(&DAT_401ef4e0 + (uint)*(ushort *)(dwInitParam + 0x28) * 4),0);
      uVar1 = *(ushort *)(dwInitParam + 0x28);
      sVar20 = DAT_401ef8e0;
      if ((int)(uint)uVar1 < DAT_401ef8e4 + -1) {
        if ((int)(uint)uVar1 < DAT_401ef8e0 + 8) {
          *(ushort *)(dwInitParam + 0x28) = uVar1 + 8;
          goto LAB_401e47b4;
        }
        sVar20 = uVar1 - 7;
      }
      *(short *)(dwInitParam + 0x28) = sVar20;
      goto LAB_401e47b4;
    }
    if (uVar9 == 0x2c9) {
      FUN_401ed130(dwInitParam);
      goto LAB_401e47b4;
    }
    if (uVar9 != 0x2cf) goto LAB_401e47b4;
    if (*(int *)(dwInitParam + 0xa8) != 0) {
      *(undefined4 *)(dwInitParam + 0xac) = 1;
      hResInfo = FindResourceW(DAT_401ef478,(LPCWSTR)0x68,(LPCWSTR)0x5);
      lpTemplate = LoadResource(DAT_401ef478,hResInfo);
      pHVar2 = CreateDialogIndirectParamW(DAT_401ef478,lpTemplate,param_1,FUN_401e2430,dwInitParam);
      *(HWND *)(dwInitParam + 0x10) = pHVar2;
      goto LAB_401e47b4;
    }
    pHVar6 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar6 = SetCursor(pHVar6);
    FUN_401ed238(dwInitParam);
    iVar4 = 0x2bf;
    do {
      pHVar2 = GetDlgItem(param_1,iVar4);
      EnableWindow(pHVar2,1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x2c5);
    iVar4 = 0x2d3;
    do {
      pHVar2 = GetDlgItem(param_1,iVar4);
      EnableWindow(pHVar2,1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x2d9);
    pHVar2 = GetDlgItem(param_1,0x2c8);
    EnableWindow(pHVar2,1);
    pHVar2 = GetDlgItem(param_1,0x2c9);
    EnableWindow(pHVar2,1);
    pHVar2 = GetDlgItem(param_1,0x2db);
    EnableWindow(pHVar2,1);
    pHVar2 = GetDlgItem(param_1,0x2cf);
    EnableWindow(pHVar2,0);
    GetWindowRect(param_1,(LPRECT)auStack_98);
    SystemParametersInfoW(0x30,0,&local_88,0);
    iVar22 = *(int *)(dwInitParam + 0x3c) - *(int *)(dwInitParam + 0x34);
    iVar13 = *(int *)(dwInitParam + 0x40) - *(int *)(dwInitParam + 0x38);
    iVar4 = (local_7c - local_84) - iVar13;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 1;
    }
    iVar12 = (local_80 - local_88) - iVar22;
    if (iVar12 < 0) {
      iVar12 = iVar12 + 1;
    }
    SetWindowPos(param_1,(HWND)0x0,(iVar12 >> 1) + local_88,(iVar4 >> 1) + local_84,iVar22,iVar13,
                 0x14);
    InvalidateRect(param_1,(RECT *)0x0,1);
    SetCursor(pHVar6);
    pHVar2 = GetDlgItem(param_1,0x2bf);
    SetFocus(pHVar2);
    *(undefined4 *)(dwInitParam + 0xa4) = 1;
  }
  UpdateWindow(param_1);
LAB_401e47b4:
  FUN_401ee698(local_30);
  return uVar19;
}



/* 401e47f0 FUN_401e47f0 */

/* Boundary evidence: original MIPS .pdata 401e47f0..401e4a3b. Semantic name remains unreviewed. */

undefined4 FUN_401e47f0(int param_1)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  LPVOID pvVar1;
  HMODULE hModule;
  uint uVar2;
  int *piVar3;
  INT_PTR IVar4;
  
  piVar3 = *(int **)(param_1 + 4);
  IVar4 = 0;
  FUN_401e8100((LPVOID)0x0);
  DAT_401ef4a4 = 0;
  if ((piVar3 == (int *)0x0) || (piVar3[4] == 0)) {
    pvVar1 = (LPVOID)0x2;
    goto LAB_401e4a0c;
  }
  if (*piVar3 != 0x24) {
    pvVar1 = (LPVOID)0x1;
    goto LAB_401e4a0c;
  }
  uVar2 = piVar3[5];
  if ((uVar2 & 0x10) == 0) {
    piVar3[7] = 0;
  }
  else if (piVar3[7] == 0) {
    pvVar1 = (LPVOID)0xb;
    goto LAB_401e4a0c;
  }
  if ((uVar2 & 0x20) == 0) {
    if ((uVar2 & 0x40) != 0) {
      hDialogTemplate = (LPCDLGTEMPLATEW)piVar3[2];
      if (hDialogTemplate != (LPCDLGTEMPLATEW)0x0) goto LAB_401e4960;
      pvVar1 = (LPVOID)0x8;
      goto LAB_401e49ec;
    }
    hResInfo = FindResourceW(DAT_401ef478,(LPCWSTR)0x65,(LPCWSTR)0x5);
    hModule = DAT_401ef478;
    if (hResInfo != (HRSRC)0x0) goto LAB_401e48f0;
  }
  else {
    hResInfo = FindResourceW((HMODULE)piVar3[2],(LPCWSTR)piVar3[8],(LPCWSTR)0x5);
    if (hResInfo != (HRSRC)0x0) {
      hModule = (HMODULE)piVar3[2];
LAB_401e48f0:
      hDialogTemplate = LoadResource(hModule,hResInfo);
      if (hDialogTemplate == (LPCDLGTEMPLATEW)0x0) {
        pvVar1 = (LPVOID)0x7;
        goto LAB_401e4a0c;
      }
LAB_401e4960:
      if ((*(uint *)(*(int *)(param_1 + 4) + 0x14) & 0x10) != 0) {
        DAT_401ef4d4 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x1c);
      }
      IVar4 = DialogBoxIndirectParamW
                        (DAT_401ef478,hDialogTemplate,(HWND)piVar3[1],FUN_401e3260,param_1);
      DAT_401ef4d4 = 0;
      if ((IVar4 != -1) &&
         (((IVar4 != 0 || (DAT_401ef4a4 != 0)) || (pvVar1 = FUN_401e8150(), pvVar1 != (LPVOID)0x0)))
         ) goto LAB_401e49f4;
      pvVar1 = (LPVOID)0xffff;
LAB_401e49ec:
      FUN_401e8100(pvVar1);
LAB_401e49f4:
      if (IVar4 == 1) {
        return 1;
      }
      return 0;
    }
  }
  pvVar1 = (LPVOID)0x6;
LAB_401e4a0c:
  FUN_401e8100(pvVar1);
  return 0;
}



/* 401e4a3c ChooseColor */

/* Boundary evidence: original MIPS .pdata 401e4a3c..401e4a7f. Semantic name remains unreviewed. */

void ChooseColor(undefined4 param_1)

{
  undefined4 local_1b8;
  undefined4 local_1b4;
  
                    /* 0x4a3c  1  ChooseColor */
  memset(&local_1b8,0,0x1b0);
  local_1b8 = 1;
  local_1b4 = param_1;
  FUN_401e47f0((int)&local_1b8);
  return;
}



/* 401e4a80 FUN_401e4a80 */

/* Boundary evidence: original MIPS .pdata 401e4a80..401e4adb. Semantic name remains unreviewed. */

void FUN_401e4a80(HWND param_1,int param_2)

{
  HWND pHVar1;
  
  pHVar1 = GetDlgItem(param_1,param_2);
  EnableWindow(pHVar1,0);
  pHVar1 = GetDlgItem(param_1,param_2);
  ShowWindow(pHVar1,0);
  return;
}



/* 401e4adc FUN_401e4adc */

/* Boundary evidence: original MIPS .pdata 401e4adc..401e4c27. Semantic name remains unreviewed. */

void FUN_401e4adc(HWND param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  LRESULT LVar3;
  int *piVar4;
  int iVar5;
  WPARAM wParam;
  WPARAM wParam_00;
  int iVar6;
  
  iVar6 = 1000;
  LVar3 = SendMessageW(param_1,0x146,0,0);
  wParam_00 = 0;
  bVar2 = false;
  do {
    wParam = 0;
    if (0 < LVar3) {
      do {
        piVar4 = (int *)SendMessageW(param_1,0x150,wParam,0);
        if ((piVar4 != (int *)0x0) && (piVar4 != (int *)0xffffffff)) {
          if (!bVar2) {
            cVar1 = *(char *)(*piVar4 + 0x14);
            if (cVar1 != '\0') {
              if (*(char *)(param_2 + 0x14) != '\0') goto LAB_401e4b98;
              if (cVar1 != '\0') goto LAB_401e4bc4;
            }
            if (*(char *)(param_2 + 0x14) != '\0') goto LAB_401e4bc4;
          }
LAB_401e4b98:
          iVar5 = *(int *)(param_2 + 0x10) - *(int *)(*piVar4 + 0x10);
          if (iVar5 < 0) {
            iVar5 = -iVar5;
          }
          if (iVar5 < iVar6) {
            wParam_00 = wParam;
            iVar6 = iVar5;
          }
        }
LAB_401e4bc4:
        wParam = wParam + 1;
      } while ((int)wParam < LVar3);
    }
    if ((bVar2) || (wParam_00 != 0)) {
      SendMessageW(param_1,0x14e,wParam_00,0);
      return;
    }
    bVar2 = true;
  } while( true );
}



/* 401e4c28 FUN_401e4c28 */

/* Boundary evidence: original MIPS .pdata 401e4c28..401e4ca7. Semantic name remains unreviewed. */

WPARAM FUN_401e4c28(HWND param_1)

{
  WPARAM wParam;
  WCHAR aWStack_58 [32];
  uint local_18;
  
  local_18 = DAT_401ef2a8;
  wParam = SendMessageW(param_1,0x147,0,0);
  if (-1 < (int)wParam) {
    SendMessageW(param_1,0x148,wParam,(LPARAM)aWStack_58);
    SetWindowTextW(param_1,aWStack_58);
  }
  FUN_401ee698(local_18);
  return wParam;
}



/* 401e4ca8 FUN_401e4ca8 */

/* Boundary evidence: original MIPS .pdata 401e4ca8..401e4e8f. Semantic name remains unreviewed. */

undefined4 FUN_401e4ca8(HWND param_1,int param_2,UINT *param_3,uint param_4)

{
  UINT UVar1;
  undefined4 uVar2;
  BOOL local_198 [2];
  WCHAR aWStack_190 [92];
  WCHAR aWStack_d8 [90];
  uint local_24;
  
  local_24 = DAT_401ef2a8;
  *param_3 = 0;
  UVar1 = GetDlgItemTextW(param_1,0x472,aWStack_d8,0x5a);
  if (UVar1 == 0) {
    if ((param_4 & 2) != 0) {
      local_198[0] = 1;
      UVar1 = 10;
      goto LAB_401e4d4c;
    }
LAB_401e4e48:
    FUN_401ee698(local_24);
    uVar2 = 0;
  }
  else {
    UVar1 = GetDlgItemInt(param_1,0x472,local_198,1);
    if (local_198[0] == 0) {
      UVar1 = 0;
    }
LAB_401e4d4c:
    uVar2 = 1;
    if ((param_4 & 1) != 0) {
      if (((*(uint *)(param_2 + 0x14) & 0x2000) == 0) ||
         (((local_198[0] != 0 && ((int)UVar1 <= *(int *)(param_2 + 0x38))) &&
          (*(int *)(param_2 + 0x34) <= (int)UVar1)))) {
        if (local_198[0] != 0) goto LAB_401e4e7c;
        LoadStringW(DAT_401ef478,0x1982,aWStack_d8,0x5a);
      }
      else {
        local_198[0] = 0;
        LoadStringW(DAT_401ef478,0x1983,aWStack_190,0x5a);
        StringCchPrintfW(aWStack_d8,0x5a,aWStack_190,*(undefined4 *)(param_2 + 0x34),
                         *(undefined4 *)(param_2 + 0x38));
      }
      if (local_198[0] == 0) {
        GetWindowTextW(param_1,aWStack_190,0x5a);
        MessageBoxW(param_1,aWStack_d8,aWStack_190,0x40);
        goto LAB_401e4e48;
      }
    }
LAB_401e4e7c:
    *param_3 = UVar1;
    FUN_401ee698(local_24);
  }
  return uVar2;
}



/* 401e4e90 FUN_401e4e90 */

/* Boundary evidence: original MIPS .pdata 401e4e90..401e5127. Semantic name remains unreviewed. */

undefined4 FUN_401e4e90(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  WPARAM WVar1;
  HLOCAL pvVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  HLOCAL hMem;
  int lParam;
  
  uVar5 = param_4[6];
  hMem = (HLOCAL)0x0;
  if (((((uVar5 & 0x40000) == 0) || ((param_3 & 4) != 0)) &&
      (((uVar5 & 0x20000) == 0 || ((param_3 & 1) == 0)))) &&
     ((((uVar5 & 0x400) == 0 ||
       ((*(char *)(param_1 + 0x17) != -1 && (*(char *)(param_1 + 0x17) != '\x02')))) &&
      ((((uVar5 & 0x4000) == 0 || ((*(byte *)(param_1 + 0x1b) & 2) == 0)) &&
       (((uVar5 & 0x800) == 0 || (*(char *)(param_1 + 0x17) != -1)))))))) {
    uVar5 = param_3 | 0x4000;
    if (param_4[9] == 0) {
      uVar5 = param_3 | 0x2000;
    }
    lParam = param_1 + 0x1c;
    WVar1 = SendMessageW((HWND)*param_4,0x158,0xffffffff,lParam);
    if ((int)WVar1 < 0) {
      WVar1 = SendMessageW((HWND)*param_4,0x143,0,lParam);
      if ((-1 < (int)WVar1) && (puVar3 = LocalAlloc(0,8), puVar3 != (undefined4 *)0x0)) {
        *puVar3 = 0;
        puVar3[1] = uVar5;
        SendMessageW((HWND)*param_4,0x151,WVar1,(LPARAM)puVar3);
        goto LAB_401e50fc;
      }
    }
    else {
      pvVar2 = (HLOCAL)SendMessageW((HWND)*param_4,0x150,WVar1,0);
      if ((pvVar2 == (HLOCAL)0x0) || (pvVar2 == (HLOCAL)0xffffffff)) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(uint *)((int)pvVar2 + 4);
        hMem = pvVar2;
      }
      if (((((param_4[6] & 1) == 0) && ((param_4[6] & 2) != 0)) && ((uVar5 & 0x4000) != 0)) &&
         ((uVar6 & 0x2000) != 0)) {
        uVar6 = 0;
LAB_401e501c:
        SendMessageW((HWND)*param_4,0x14a,WVar1,lParam);
        SendMessageW((HWND)*param_4,0x144,WVar1 + 1,0);
        uVar7 = uVar5;
      }
      else {
        uVar7 = uVar6;
        if (0 < (int)(((uVar5 ^ 1) & 0xffff9fff) - ((uVar6 ^ 1) & 0xffff9fff))) goto LAB_401e501c;
      }
      puVar3 = LocalAlloc(0,8);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = 0;
        puVar3[1] = (uVar6 | uVar5) & 0x6000 | uVar7;
        SendMessageW((HWND)*param_4,0x151,WVar1,(LPARAM)puVar3);
        if (hMem != (HLOCAL)0x0) {
          LocalFree(hMem);
        }
        goto LAB_401e50fc;
      }
    }
    uVar4 = 0;
  }
  else {
LAB_401e50fc:
    uVar4 = 1;
  }
  return uVar4;
}



/* 401e5128 FUN_401e5128 */

/* Boundary evidence: original MIPS .pdata 401e5128..401e536f. Semantic name remains unreviewed. */

bool FUN_401e5128(HWND param_1,HDC param_2,uint param_3)

{
  WPARAM WVar1;
  LRESULT LVar2;
  uint uVar3;
  HWND local_168 [5];
  HDC local_154;
  uint local_150;
  undefined4 local_144;
  WCHAR aWStack_138 [40];
  WCHAR aWStack_e8 [100];
  uint local_20;
  
  local_20 = DAT_401ef2a8;
  local_168[0] = GetDlgItem(param_1,0x470);
  local_150 = param_3;
  local_154 = GetDC((HWND)0x0);
  local_144 = 0;
  EnumFontFamiliesW(local_154,(LPCWSTR)0x0,FUN_401e4e90,(LPARAM)local_168);
  ReleaseDC((HWND)0x0,local_154);
  if ((param_3 & 2) != 0) {
    local_144 = 1;
    local_154 = param_2;
    EnumFontFamiliesW(param_2,(LPCWSTR)0x0,FUN_401e4e90,(LPARAM)local_168);
  }
  if ((param_3 & 1) == 0) {
    WVar1 = SendMessageW(local_168[0],0x146,0,0);
    while (WVar1 = WVar1 - 1, -1 < (int)WVar1) {
      LVar2 = SendMessageW(local_168[0],0x150,WVar1,0);
      if ((LVar2 == 0) || (LVar2 == -1)) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(uint *)(LVar2 + 4);
      }
      if ((uVar3 & 0x6000) == 0x2000) {
        SendMessageW(local_168[0],0x144,WVar1,0);
      }
    }
  }
  if ((param_3 & 0x8000) != 0) {
    WVar1 = SendMessageW(local_168[0],0x146,0,0);
    while (WVar1 = WVar1 - 1, -1 < (int)WVar1) {
      LVar2 = SendMessageW(local_168[0],0x150,WVar1,0);
      if ((*(uint *)(LVar2 + 4) & 0x6000) != 0x6000) {
        SendMessageW(local_168[0],0x144,WVar1,0);
      }
    }
  }
  LVar2 = SendMessageW(local_168[0],0x146,0,0);
  if (0 < LVar2) {
    FUN_401ee698(local_20);
  }
  else {
    LoadStringW(DAT_401ef478,0x1978,aWStack_138,0x28);
    LoadStringW(DAT_401ef478,0x1979,aWStack_e8,100);
    MessageBoxW(param_1,aWStack_e8,aWStack_138,0x40);
    FUN_401ee698(local_20);
  }
  return 0 < LVar2;
}



/* 401e5370 FUN_401e5370 */

/* Boundary evidence: original MIPS .pdata 401e5370..401e54f3. Semantic name remains unreviewed. */

void FUN_401e5370(HWND param_1,int param_2,int param_3)

{
  LRESULT LVar1;
  LRESULT LVar2;
  undefined4 *lParam;
  int iVar3;
  WPARAM WVar4;
  wchar_t awStack_30 [10];
  uint local_1c;
  
  local_1c = DAT_401ef2a8;
  if (((*(uint *)(param_3 + 0x14) & 0x2000) == 0) ||
     ((param_2 <= *(int *)(param_3 + 0x38) && (*(int *)(param_3 + 0x34) <= param_2)))) {
    StringCchPrintfW(awStack_30,10,(STRSAFE_LPCWSTR)&DAT_401ef26c,param_2);
    LVar1 = SendMessageW(param_1,0x146,0,0);
    iVar3 = -1;
    WVar4 = 0;
    if (0 < LVar1) {
      do {
        LVar2 = SendMessageW(param_1,0x150,WVar4,0);
        if ((LVar2 == 0) || (LVar2 == -1)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(LVar2 + 4);
        }
      } while ((iVar3 < param_2) && (WVar4 = WVar4 + 1, (int)WVar4 < LVar1));
    }
    if ((param_2 != iVar3) &&
       ((WVar4 = SendMessageW(param_1,0x14a,WVar4,(LPARAM)awStack_30), -1 < (int)WVar4 &&
        (lParam = LocalAlloc(0,8), lParam != (undefined4 *)0x0)))) {
      *lParam = 0;
      lParam[1] = param_2;
      SendMessageW(param_1,0x151,WVar4,(LPARAM)lParam);
    }
  }
  FUN_401ee698(local_1c);
  return;
}



/* 401e54f4 FUN_401e54f4 */

/* Boundary evidence: original MIPS .pdata 401e54f4..401e55ef. Semantic name remains unreviewed. */

void FUN_401e54f4(HWND param_1,LPARAM param_2,int param_3)

{
  LRESULT LVar1;
  int *piVar2;
  int iVar3;
  WPARAM wParam;
  
  LVar1 = SendMessageW(param_1,0x146,0,0);
  wParam = 0;
  if (0 < LVar1) {
    do {
      piVar2 = (int *)SendMessageW(param_1,0x150,wParam,0);
      if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0xffffffff)) {
        iVar3 = *(int *)(*piVar2 + 0x10);
        if (*(int *)(param_3 + 0x10) < iVar3) break;
        if (*(int *)(param_3 + 0x10) == iVar3) {
          if ((*(char *)(param_3 + 0x14) != '\0') && (*(char *)(*piVar2 + 0x14) == '\0')) {
            wParam = wParam + 1;
          }
          break;
        }
      }
      wParam = wParam + 1;
    } while ((int)wParam < LVar1);
  }
  SendMessageW(param_1,0x14a,wParam,param_2);
  return;
}



/* 401e55f0 FUN_401e55f0 */

/* Boundary evidence: original MIPS .pdata 401e55f0..401e5703. Semantic name remains unreviewed. */

HLOCAL FUN_401e55f0(HWND param_1,LPARAM param_2,undefined4 param_3,void *param_4)

{
  LRESULT LVar1;
  WPARAM wParam;
  HLOCAL _Dst;
  undefined4 *lParam;
  
  LVar1 = SendMessageW(param_1,0x158,0xffffffff,param_2);
  if ((LVar1 < 0) && (wParam = FUN_401e54f4(param_1,param_2,(int)param_4), -1 < (int)wParam)) {
    _Dst = LocalAlloc(0,0x5c);
    if (_Dst != (HLOCAL)0x0) {
      memcpy(_Dst,param_4,0x5c);
      lParam = LocalAlloc(0,8);
      if (lParam != (undefined4 *)0x0) {
        *lParam = _Dst;
        lParam[1] = param_3;
        SendMessageW(param_1,0x151,wParam,(LPARAM)lParam);
        return _Dst;
      }
      LocalFree(_Dst);
    }
    SendMessageW(param_1,0x144,wParam,0);
  }
  return (HLOCAL)0x0;
}



/* 401e5704 FUN_401e5704 */

/* Boundary evidence: original MIPS .pdata 401e5704..401e595b. Semantic name remains unreviewed. */

void FUN_401e5704(HWND param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  LRESULT LVar4;
  undefined4 *puVar5;
  void *pvVar6;
  void *pvVar7;
  void *pvVar8;
  uint uVar9;
  void *_Src;
  void *pvVar10;
  WPARAM wParam;
  undefined1 auStack_88 [16];
  undefined4 local_78;
  undefined1 local_74;
  uint local_2c;
  
  local_2c = DAT_401ef2a8;
  uVar9 = 0;
  bVar3 = false;
  bVar2 = false;
  bVar1 = false;
  _Src = (void *)0x0;
  pvVar10 = (void *)0x0;
  pvVar7 = (void *)0x0;
  LVar4 = SendMessageW(param_1,0x146,0,0);
  wParam = 0;
  pvVar8 = pvVar7;
  if (0 < LVar4) {
    do {
      puVar5 = (undefined4 *)SendMessageW(param_1,0x150,wParam,0);
      if ((puVar5 == (undefined4 *)0x0) || (puVar5 == (undefined4 *)0xffffffff)) {
        pvVar6 = (void *)0x0;
        uVar9 = 0;
      }
      else {
        pvVar6 = (void *)*puVar5;
        uVar9 = puVar5[1];
      }
      pvVar7 = pvVar8;
      if ((uVar9 & 0x100) == 0) {
LAB_401e57f8:
        pvVar7 = pvVar6;
        if ((uVar9 & 0x200) != 0) {
          bVar2 = true;
          pvVar7 = pvVar8;
          _Src = pvVar6;
        }
      }
      else if ((uVar9 & 0x200) == 0) {
        if ((uVar9 & 0x100) == 0) goto LAB_401e57f8;
        bVar1 = true;
        pvVar10 = pvVar6;
      }
      else {
        bVar3 = true;
      }
      wParam = wParam + 1;
      pvVar8 = pvVar7;
    } while ((int)wParam < LVar4);
  }
  if ((!bVar1) && (pvVar7 != (void *)0x0)) {
    memcpy(auStack_88,pvVar7,0x5c);
    local_78 = 700;
    FUN_401e55f0(param_1,0x401ef348,uVar9 | 0x8100,auStack_88);
  }
  if ((!bVar2) && (pvVar7 != (void *)0x0)) {
    memcpy(auStack_88,pvVar7,0x5c);
    local_74 = 1;
    FUN_401e55f0(param_1,0x401ef388,uVar9 | 0x8200,auStack_88);
  }
  if (bVar3) goto LAB_401e5924;
  if (pvVar10 == (void *)0x0) {
    if (_Src == (void *)0x0) {
      if (pvVar7 == (void *)0x0) goto LAB_401e5924;
      goto LAB_401e58e0;
    }
  }
  else {
LAB_401e58e0:
    if ((_Src == (void *)0x0) && (_Src = pvVar10, pvVar10 == (void *)0x0)) {
      _Src = pvVar7;
    }
  }
  memcpy(auStack_88,_Src,0x5c);
  local_74 = 1;
  local_78 = 700;
  FUN_401e55f0(param_1,0x401ef2c8,uVar9 | 0x8300,auStack_88);
LAB_401e5924:
  FUN_401ee698(local_2c);
  return;
}



/* 401e595c FUN_401e595c */

/* Boundary evidence: original MIPS .pdata 401e595c..401e5a87. Semantic name remains unreviewed. */

void FUN_401e595c(HWND param_1,int param_2)

{
  FUN_401e5370(param_1,8,param_2);
  FUN_401e5370(param_1,9,param_2);
  FUN_401e5370(param_1,10,param_2);
  FUN_401e5370(param_1,0xb,param_2);
  FUN_401e5370(param_1,0xc,param_2);
  FUN_401e5370(param_1,0xe,param_2);
  FUN_401e5370(param_1,0x10,param_2);
  FUN_401e5370(param_1,0x12,param_2);
  FUN_401e5370(param_1,0x14,param_2);
  FUN_401e5370(param_1,0x16,param_2);
  FUN_401e5370(param_1,0x18,param_2);
  FUN_401e5370(param_1,0x1a,param_2);
  FUN_401e5370(param_1,0x1c,param_2);
  FUN_401e5370(param_1,0x24,param_2);
  FUN_401e5370(param_1,0x30,param_2);
  FUN_401e5370(param_1,0x48,param_2);
  return;
}



/* 401e5a88 FUN_401e5a88 */

/* Boundary evidence: original MIPS .pdata 401e5a88..401e5b67. Semantic name remains unreviewed. */

void FUN_401e5a88(HWND param_1)

{
  LRESULT LVar1;
  undefined4 *hMem;
  WPARAM wParam;
  
  LVar1 = SendMessageW(param_1,0x146,0,0);
  wParam = 0;
  if (0 < LVar1) {
    do {
      hMem = (undefined4 *)SendMessageW(param_1,0x150,wParam,0);
      if (((uint)hMem >> 0x10 != 0) && (hMem != (undefined4 *)0xffffffff)) {
        if (*(short *)((int)hMem + 2) != 0) {
          LocalFree((HLOCAL)*hMem);
        }
        LocalFree(hMem);
      }
      SendMessageW(param_1,0x151,wParam,0);
      wParam = wParam + 1;
    } while ((int)wParam < LVar1);
  }
  SendMessageW(param_1,0x14b,0,0);
  return;
}



/* 401e5b68 FUN_401e5b68 */

/* Boundary evidence: original MIPS .pdata 401e5b68..401e5c37. Semantic name remains unreviewed. */

void FUN_401e5b68(HWND param_1,int *param_2)

{
  HWND pHVar1;
  
  pHVar1 = GetDlgItem(param_1,0x470);
  if (pHVar1 != (HWND)0x0) {
    FUN_401e5a88(pHVar1);
  }
  pHVar1 = GetDlgItem(param_1,0x471);
  if (pHVar1 != (HWND)0x0) {
    FUN_401e5a88(pHVar1);
  }
  pHVar1 = GetDlgItem(param_1,0x472);
  if (pHVar1 != (HWND)0x0) {
    FUN_401e5a88(pHVar1);
  }
  if (((0x3ffff < (uint)param_2[7]) || ((*(uint *)(*param_2 + 0x14) & 0x800000) != 0)) &&
     (pHVar1 = GetDlgItem(param_1,0x474), pHVar1 != (HWND)0x0)) {
    FUN_401e5a88(pHVar1);
  }
  return;
}



/* 401e5c38 FUN_401e5c38 */

/* Boundary evidence: original MIPS .pdata 401e5c38..401e5cdf. Semantic name remains unreviewed. */

void FUN_401e5c38(int *param_1)

{
  HDC hdc;
  int iVar1;
  
  hdc = GetDC((HWND)0x0);
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)((int)param_1 + 0x17) = 1;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  *(undefined1 *)((int)param_1 + 0x1a) = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 400;
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  iVar1 = GetDeviceCaps(hdc,0x5a);
  iVar1 = MulDiv(10,iVar1,0x48);
  *param_1 = -iVar1;
  ReleaseDC((HWND)0x0,hdc);
  return;
}



/* 401e5ce0 FUN_401e5ce0 */

/* Boundary evidence: original MIPS .pdata 401e5ce0..401e5db3. Semantic name remains unreviewed. */

void FUN_401e5ce0(HWND param_1)

{
  WPARAM wParam;
  WPARAM wParam_00;
  LPARAM *pLVar1;
  WCHAR local_40 [16];
  uint local_20;
  
  local_20 = DAT_401ef2a8;
  pLVar1 = &DAT_401ef22c;
  wParam_00 = 0;
  do {
    local_40[0] = L'\0';
    LoadStringW(DAT_401ef478,wParam_00 + 0x198c,local_40,0x10);
    wParam = SendDlgItemMessageW(param_1,0x473,0x14a,wParam_00,(LPARAM)local_40);
    if (-1 < (int)wParam) {
      SendDlgItemMessageW(param_1,0x473,0x151,wParam,*pLVar1);
    }
    pLVar1 = pLVar1 + 1;
    wParam_00 = wParam_00 + 1;
  } while ((int)pLVar1 < 0x401ef26c);
  FUN_401ee698(local_20);
  return;
}



/* 401e5db4 FUN_401e5db4 */

/* Boundary evidence: original MIPS .pdata 401e5db4..401e5e37. Semantic name remains unreviewed. */

int FUN_401e5db4(STRSAFE_LPWSTR param_1,size_t param_2,HDC param_3,int param_4)

{
  int iVar1;
  
  if (param_4 < 0) {
    param_4 = -param_4;
  }
  iVar1 = GetDeviceCaps(param_3,0x5a);
  iVar1 = MulDiv(param_4,0x48,iVar1);
  StringCchPrintfW(param_1,param_2,(STRSAFE_LPCWSTR)&DAT_401ef26c,iVar1);
  return iVar1;
}



/* 401e5e38 FUN_401e5e38 */

/* Boundary evidence: original MIPS .pdata 401e5e38..401e5e97. Semantic name remains unreviewed. */

WPARAM FUN_401e5e38(HWND param_1,LPARAM param_2)

{
  WPARAM wParam;
  
  wParam = SendMessageW(param_1,0x158,0xffffffff,param_2);
  if (-1 < (int)wParam) {
    SendMessageW(param_1,0x14e,wParam,0);
  }
  return wParam;
}



/* 401e5e98 FUN_401e5e98 */

/* Boundary evidence: original MIPS .pdata 401e5e98..401e5f17. Semantic name remains unreviewed. */

WPARAM FUN_401e5e98(HWND param_1,LPWSTR param_2,int param_3,LRESULT *param_4)

{
  WPARAM wParam;
  LRESULT LVar1;
  
  GetWindowTextW(param_1,param_2,param_3);
  wParam = SendMessageW(param_1,0x158,0xffffffff,(LPARAM)param_2);
  if (-1 < (int)wParam) {
    LVar1 = SendMessageW(param_1,0x150,wParam,0);
    *param_4 = LVar1;
  }
  return wParam;
}



/* 401e5f18 FUN_401e5f18 */

/* Boundary evidence: original MIPS .pdata 401e5f18..401e611b. Semantic name remains unreviewed. */

undefined4 FUN_401e5f18(void *param_1,int *param_2,uint param_3,int param_4)

{
  LRESULT LVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  wchar_t awStack_48 [20];
  uint local_20;
  
  local_20 = DAT_401ef2a8;
  if (param_3 == (*(uint *)(param_4 + 0x1c) & 7)) {
    if ((param_3 & 1) == 0) {
      if ((*(int *)(param_4 + 0x20) != 0) &&
         (LVar1 = SendMessageW(*(HWND *)(param_4 + 8),0x146,0,0), LVar1 == 0)) {
        FUN_401e595c(*(HWND *)(param_4 + 8),*(int *)(param_4 + 0x28));
      }
    }
    else {
      iVar2 = FUN_401e5db4(awStack_48,0x14,*(HDC *)(param_4 + 0x14),*param_2 - param_2[3]);
      LVar1 = SendMessageW(*(HWND *)(param_4 + 8),0x158,0xffffffff,(LPARAM)awStack_48);
      if (LVar1 < 0) {
        FUN_401e5370(*(HWND *)(param_4 + 8),iVar2,*(int *)(param_4 + 0x28));
      }
    }
    uVar4 = *(uint *)(param_4 + 0x1c) & 0x6000 | param_3;
    if ((param_3 & 4) == 0) {
      if (*(int *)((int)param_1 + 0x10) < 700) {
        if (*(char *)((int)param_1 + 0x14) == '\0') {
          puVar3 = &DAT_401ef308;
          uVar5 = uVar4 | 0x400;
        }
        else {
          puVar3 = &DAT_401ef388;
          uVar5 = uVar4 | 0x200;
        }
      }
      else if (*(char *)((int)param_1 + 0x14) == '\0') {
        puVar3 = &DAT_401ef348;
        uVar5 = uVar4 | 0x100;
      }
      else {
        puVar3 = &DAT_401ef2c8;
        uVar5 = uVar4 | 0x300;
      }
    }
    else {
      uVar6 = param_2[0xf];
      puVar3 = (undefined *)0x0;
      if ((uVar6 & 0x21) == 0) {
        uVar4 = uVar4 | 0x400;
        puVar3 = &DAT_401ef308;
      }
      if ((uVar6 & 1) != 0) {
        uVar4 = uVar4 | 0x200;
        puVar3 = &DAT_401ef388;
      }
      uVar5 = uVar4;
      if ((uVar6 & 0x20) != 0) {
        uVar5 = uVar4 | 0x100;
        if ((uVar4 & 0x200) == 0) {
          puVar3 = &DAT_401ef348;
        }
        else {
          puVar3 = &DAT_401ef2c8;
        }
      }
    }
    FUN_401e55f0(*(HWND *)(param_4 + 4),(LPARAM)puVar3,uVar5,param_1);
  }
  FUN_401ee698(local_20);
  return 1;
}



/* 401e611c FUN_401e611c */

/* Boundary evidence: original MIPS .pdata 401e611c..401e6423. Semantic name remains unreviewed. */

undefined4 FUN_401e611c(HWND param_1,int param_2,int param_3)

{
  HWND pHVar1;
  WPARAM wParam;
  LRESULT LVar2;
  LPCWSTR pWVar3;
  uint *puVar4;
  undefined1 auStack_f0 [4];
  HWND local_ec;
  HWND local_e8;
  HDC local_dc;
  uint local_d8;
  undefined4 local_d4;
  int local_d0;
  undefined4 local_cc;
  int local_c8;
  int aiStack_c0 [4];
  undefined4 local_b0;
  undefined1 local_ac;
  wchar_t awStack_a4 [34];
  WCHAR local_60 [32];
  uint local_20;
  
  local_20 = DAT_401ef2a8;
  pHVar1 = GetDlgItem(param_1,0x471);
  FUN_401e5a88(pHVar1);
  local_ec = GetDlgItem(param_1,0x471);
  local_e8 = GetDlgItem(param_1,0x472);
  puVar4 = (uint *)(param_3 + 0x14);
  local_d8 = *puVar4;
  local_c8 = param_3;
  wParam = SendDlgItemMessageW(param_1,0x470,0x147,0,0);
  if ((int)wParam < 0) {
    FUN_401e5c38(aiStack_c0);
    FUN_401e55f0(local_ec,0x401ef308,0x400,aiStack_c0);
    local_b0 = 700;
    FUN_401e55f0(local_ec,0x401ef348,0x100,aiStack_c0);
    local_b0 = 400;
    local_ac = 1;
    FUN_401e55f0(local_ec,0x401ef388,0x200,aiStack_c0);
    local_b0 = 700;
    FUN_401e55f0(local_ec,0x401ef2c8,0x300,aiStack_c0);
    FUN_401e595c(local_e8,param_3);
  }
  else {
    LVar2 = SendDlgItemMessageW(param_1,0x470,0x150,wParam,0);
    if ((LVar2 == 0) || (LVar2 == -1)) {
      local_d4 = 0;
    }
    else {
      local_d4 = *(undefined4 *)(LVar2 + 4);
    }
    local_d0 = 1;
    FUN_401e5a88(local_e8);
    SendMessageW(local_ec,0xb,0,0);
    GetDlgItemTextW(param_1,0x470,local_60,0x20);
    wcscpy(awStack_a4,local_60);
    if ((*puVar4 & 1) != 0) {
      local_dc = GetDC((HWND)0x0);
      pWVar3 = (LPCWSTR)0x0;
      local_cc = 0;
      if (local_60[0] != L'\0') {
        pWVar3 = local_60;
      }
      EnumFontFamiliesW(local_dc,pWVar3,FUN_401e5f18,(LPARAM)auStack_f0);
      ReleaseDC((HWND)0x0,local_dc);
    }
    if ((*puVar4 & 2) != 0) {
      local_dc = *(HDC *)(param_3 + 8);
      pWVar3 = (LPCWSTR)0x0;
      local_cc = 1;
      if (local_60[0] != L'\0') {
        pWVar3 = local_60;
      }
      EnumFontFamiliesW(local_dc,pWVar3,FUN_401e5f18,(LPARAM)auStack_f0);
    }
    if ((*puVar4 & 0x1000) == 0) {
      FUN_401e5704(local_ec);
    }
    SendMessageW(local_ec,0xb,1,0);
    InvalidateRect(local_ec,(RECT *)0x0,1);
    if (local_d0 != 0) {
      SendMessageW(local_e8,0xb,1,0);
      InvalidateRect(local_e8,(RECT *)0x0,1);
    }
    if ((*puVar4 & 0x800000) != 0) {
      *(undefined4 *)(param_2 + 4) = 1;
    }
  }
  FUN_401ee698(local_20);
  return 1;
}



/* 401e6424 FUN_401e6424 */

/* Boundary evidence: original MIPS .pdata 401e6424..401e6793. Semantic name remains unreviewed. */

undefined4 FUN_401e6424(HWND param_1,int param_2,int param_3,int *param_4,int param_5)

{
  HWND pHVar1;
  LRESULT LVar2;
  WPARAM WVar3;
  HDC hdc;
  int iVar4;
  UINT uID;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *local_178 [2];
  WCHAR aWStack_170 [32];
  WCHAR local_130 [128];
  uint local_30;
  
  local_30 = DAT_401ef2a8;
  uVar7 = 1;
  FUN_401e5c38(param_4);
  GetDlgItemTextW(param_1,0x470,(LPWSTR)(param_4 + 7),0x20);
  pHVar1 = GetDlgItem(param_1,0x470);
  LVar2 = SendMessageW(pHVar1,0x158,0xffffffff,(LPARAM)(param_4 + 7));
  if (LVar2 < 0) {
    uVar7 = 0;
    if (param_5 != 0) {
      uVar5 = *(uint *)(param_3 + 0x14) | 0x80000;
      goto LAB_401e64f8;
    }
  }
  else if (param_5 != 0) {
    uVar5 = *(uint *)(param_3 + 0x14) & 0xfff7ffff;
LAB_401e64f8:
    *(uint *)(param_3 + 0x14) = uVar5;
  }
  pHVar1 = GetDlgItem(param_1,0x471);
  WVar3 = FUN_401e5e98(pHVar1,aWStack_170,0x20,(LRESULT *)local_178);
  if (((int)WVar3 < 0) || (local_178[0] == (undefined4 *)0x0)) {
    uVar7 = 0;
    if (param_5 != 0) {
      *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) | 0x100000;
    }
    uVar5 = 0;
  }
  else {
    uVar5 = local_178[0][1];
    memcpy(param_4,(void *)*local_178[0],0x5c);
    param_4[1] = 0;
    if (param_5 != 0) {
      *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) & 0xffefffff;
    }
  }
  FUN_401e4ca8(param_1,param_3,(UINT *)local_178,0);
  hdc = GetDC((HWND)0x0);
  if (local_178[0] == (undefined4 *)0x0) {
    iVar4 = GetDeviceCaps(hdc,0x5a);
    iVar4 = MulDiv(10,iVar4,0x48);
    *param_4 = -iVar4;
    uVar7 = 0;
    if (param_5 != 0) {
      uVar6 = *(uint *)(param_3 + 0x14) | 0x200000;
      goto LAB_401e6658;
    }
  }
  else {
    iVar4 = GetDeviceCaps(hdc,0x5a);
    iVar4 = MulDiv((int)local_178[0],iVar4,0x48);
    *param_4 = -iVar4;
    if (param_5 != 0) {
      uVar6 = *(uint *)(param_3 + 0x14) & 0xffdfffff;
LAB_401e6658:
      *(uint *)(param_3 + 0x14) = uVar6;
    }
  }
  ReleaseDC((HWND)0x0,hdc);
  LVar2 = SendDlgItemMessageW(param_1,0x410,0xf0,0,0);
  *(char *)((int)param_4 + 0x16) = (char)LVar2;
  LVar2 = SendDlgItemMessageW(param_1,0x411,0xf0,0,0);
  *(char *)((int)param_4 + 0x15) = (char)LVar2;
  *(char *)((int)param_4 + 0x17) = (char)*(undefined4 *)(param_2 + 4);
  if ((uVar5 == *(uint *)(param_2 + 0x18)) || ((*(uint *)(param_3 + 0x14) & 2) == 0))
  goto LAB_401e6754;
  if ((uVar5 & 0x8000) == 0) {
    if ((uVar5 & 4) != 0) {
      uID = 0x1985;
      goto LAB_401e6724;
    }
    if ((uVar5 & 0x4002) == 0x4002) {
      uID = 0x1986;
      goto LAB_401e6724;
    }
    if ((uVar5 & 0x6000) == 0x2000) {
      uID = 0x1987;
      goto LAB_401e6724;
    }
    local_130[0] = L'\0';
  }
  else {
    uID = 0x1984;
LAB_401e6724:
    LoadStringW(DAT_401ef478,uID,local_130,0x80);
  }
  SetDlgItemTextW(param_1,0x445,local_130);
LAB_401e6754:
  *(uint *)(param_2 + 0x18) = uVar5;
  FUN_401ee698(local_30);
  return uVar7;
}



/* 401e6794 FUN_401e6794 */

/* Boundary evidence: original MIPS .pdata 401e6794..401e68ef. Semantic name remains unreviewed. */

void FUN_401e6794(HWND param_1,int param_2,int param_3)

{
  HWND pHVar1;
  WPARAM wParam;
  int *piVar2;
  int iVar3;
  
  if ((*(uint *)(param_2 + 0x14) & 0x100000) != 0) {
    return;
  }
  if ((param_3 == 0) || ((*(uint *)(param_2 + 0x14) & 0x80) == 0)) {
    pHVar1 = GetDlgItem(param_1,0x471);
    FUN_401e4adc(pHVar1,*(int *)(param_2 + 0xc));
  }
  else {
    pHVar1 = GetDlgItem(param_1,0x471);
    wParam = FUN_401e5e38(pHVar1,*(LPARAM *)(param_2 + 0x2c));
    if ((int)wParam < 0) {
      *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x10) = 400;
      iVar3 = *(int *)(param_2 + 0xc);
    }
    else {
      piVar2 = (int *)SendDlgItemMessageW(param_1,0x471,0x150,wParam,0);
      if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0xffffffff)) {
        iVar3 = *piVar2;
        *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x10) = *(undefined4 *)(iVar3 + 0x10);
        *(undefined1 *)(*(int *)(param_2 + 0xc) + 0x14) = *(undefined1 *)(iVar3 + 0x14);
        goto LAB_401e68c4;
      }
      *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x10) = 400;
      iVar3 = *(int *)(param_2 + 0xc);
    }
    *(undefined1 *)(iVar3 + 0x14) = 0;
  }
LAB_401e68c4:
  pHVar1 = GetDlgItem(param_1,0x471);
  FUN_401e4c28(pHVar1);
  return;
}



/* 401e68f0 FUN_401e68f0 */

/* Boundary evidence: original MIPS .pdata 401e68f0..401e6f43. Semantic name remains unreviewed. */

undefined4 FUN_401e68f0(HWND param_1,int *param_2,uint param_3,HWND param_4)

{
  undefined2 uVar1;
  HWND pHVar2;
  int iVar3;
  WPARAM WVar4;
  LRESULT LVar5;
  int *piVar6;
  UINT UVar7;
  uint uVar8;
  int lParam;
  uint uVar9;
  UINT local_308 [2];
  WCHAR aWStack_300 [12];
  WCHAR aWStack_2e8 [32];
  WCHAR aWStack_2a8 [160];
  WCHAR aWStack_168 [160];
  uint local_28;
  
  local_28 = DAT_401ef2a8;
  if (param_2 == (int *)0x0) {
    lParam = 0;
  }
  else {
    lParam = *param_2;
  }
  if (lParam == 0) goto LAB_401e6948;
  uVar9 = param_3 & 0xffff;
  if (uVar9 < 0x412) {
    if (uVar9 < 0x410) {
      if (uVar9 == 1) {
        pHVar2 = GetDlgItem(param_1,1);
        SetFocus(pHVar2);
        iVar3 = FUN_401e4ca8(param_1,lParam,local_308,3);
        if (iVar3 == 0) {
          iVar3 = 0x472;
LAB_401e6a6c:
          pHVar2 = GetDlgItem(param_1,iVar3);
          param_4 = (HWND)0x1;
          UVar7 = 0x28;
LAB_401e6d44:
          PostMessageW(param_1,UVar7,(WPARAM)pHVar2,(LPARAM)param_4);
          goto LAB_401e6f10;
        }
        *(UINT *)(lParam + 0x10) = local_308[0] * 10;
        FUN_401e6424(param_1,(int)param_2,lParam,*(int **)(lParam + 0xc),1);
        uVar8 = *(uint *)(lParam + 0x14);
        iVar3 = 0x471;
        if ((uVar8 & 0x10000) != 0) {
          if ((uVar8 & 0x80000) == 0) {
            if ((uVar8 & 0x100000) == 0) {
              iVar3 = 0;
            }
          }
          else {
            iVar3 = 0x470;
          }
          if (iVar3 != 0) {
            UVar7 = 0x197a;
            if (iVar3 != 0x470) {
              UVar7 = 0x197b;
            }
            LoadStringW(DAT_401ef478,UVar7,aWStack_168,0xa0);
            GetWindowTextW(param_1,aWStack_2a8,0xa0);
            MessageBoxW(param_1,aWStack_168,aWStack_2a8,0x40);
            goto LAB_401e6a6c;
          }
        }
        if ((uVar8 & 0x100) != 0) {
          WVar4 = SendDlgItemMessageW(param_1,0x473,0x147,0,0);
          LVar5 = SendDlgItemMessageW(param_1,0x473,0x150,WVar4,0);
          *(LRESULT *)(lParam + 0x18) = LVar5;
        }
        pHVar2 = GetDlgItem(param_1,0x471);
        WVar4 = FUN_401e5e98(pHVar2,aWStack_2e8,0x20,(LRESULT *)local_308);
        if (((int)WVar4 < 0) || (local_308[0] == 0)) {
          *(undefined1 *)(lParam + 0x30) = 0;
          *(undefined1 *)(lParam + 0x31) = 0;
        }
        else {
          uVar1 = *(undefined2 *)(local_308[0] + 4);
          *(char *)(lParam + 0x30) = (char)uVar1;
          *(char *)(lParam + 0x31) = (char)((ushort)uVar1 >> 8);
        }
        if ((*(uint *)(lParam + 0x14) & 0x80) != 0) {
          wcscpy(*(wchar_t **)(lParam + 0x2c),aWStack_2e8);
        }
LAB_401e6c1c:
        FUN_401e5b68(param_1,param_2);
        if ((*(uint *)(lParam + 0x14) & 8) != 0) {
          DAT_401ef3cc = *(undefined4 *)(lParam + 0x20);
        }
        param_4 = (HWND)0x1;
        if (uVar9 != 1) {
          param_4 = (HWND)0x0;
        }
      }
      else {
        if (uVar9 == 2) {
          DAT_401ef4a4 = 1;
          goto LAB_401e6c1c;
        }
        if (uVar9 != 3) {
          if (uVar9 == 0x40e) {
            if ((DAT_401ef48c != 0) && (*(HWND *)(lParam + 4) != (HWND)0x0)) {
              SendMessageW(*(HWND *)(lParam + 4),DAT_401ef48c,(WPARAM)param_1,lParam);
            }
            goto LAB_401e6f10;
          }
          goto LAB_401e6948;
        }
        FUN_401e5b68(param_1,param_2);
        if ((*(uint *)(lParam + 0x14) & 8) != 0) {
          DAT_401ef3cc = *(undefined4 *)(lParam + 0x20);
        }
      }
      EndDialog(param_1,(INT_PTR)param_4);
      goto LAB_401e6f10;
    }
  }
  else if (uVar9 == 0x470) {
    uVar8 = param_3 >> 0x10;
    if (uVar8 == 1) {
      FUN_401e4c28(param_4);
    }
    else {
      if (uVar8 == 6) {
LAB_401e6d34:
        pHVar2 = (HWND)(uVar9 | 0x5f50000);
        UVar7 = 0x111;
        goto LAB_401e6d44;
      }
      if (uVar8 != 0x5f5) goto LAB_401e6f10;
      GetWindowTextW(param_4,aWStack_2e8,0x20);
      WVar4 = SendMessageW(param_4,0x158,0xffffffff,(LPARAM)aWStack_2e8);
      if ((int)WVar4 < 0) goto LAB_401e6f10;
      SendMessageW(param_4,0x14e,WVar4,0);
      SendMessageW(param_4,0x142,0,0xffff);
    }
    GetDlgItemTextW(param_1,0x472,aWStack_300,10);
    FUN_401e611c(param_1,(int)param_2,lParam);
    FUN_401e6794(param_1,lParam,0);
    pHVar2 = GetDlgItem(param_1,0x472);
    WVar4 = SendMessageW(pHVar2,0x158,0xffffffff,(LPARAM)aWStack_300);
    if ((int)WVar4 < 0) {
      SetDlgItemTextW(param_1,0x472,aWStack_300);
    }
    else {
      SendDlgItemMessageW(param_1,0x472,0x14e,WVar4,0);
    }
  }
  else {
    if (uVar9 < 0x471) {
LAB_401e6948:
      FUN_401ee698(DAT_401ef2a8);
      return 0;
    }
    if (uVar9 < 0x473) {
      uVar8 = param_3 >> 0x10;
      if (uVar8 == 1) {
        WVar4 = FUN_401e4c28(param_4);
        if ((-1 < (int)WVar4) && (uVar9 == 0x471)) {
          piVar6 = (int *)SendMessageW(param_4,0x150,WVar4,0);
          if ((piVar6 == (int *)0x0) || (piVar6 == (int *)0xffffffff)) {
            *(undefined4 *)(*(int *)(lParam + 0xc) + 0x10) = 400;
            *(undefined1 *)(*(int *)(lParam + 0xc) + 0x14) = 0;
          }
          else {
            iVar3 = *piVar6;
            *(undefined4 *)(*(int *)(lParam + 0xc) + 0x10) = *(undefined4 *)(iVar3 + 0x10);
            *(undefined1 *)(*(int *)(lParam + 0xc) + 0x14) = *(undefined1 *)(iVar3 + 0x14);
          }
        }
      }
      else if (uVar8 != 4) {
        if (uVar8 == 6) goto LAB_401e6d34;
        if (uVar8 != 0x5f5) goto LAB_401e6f10;
        GetWindowTextW(param_4,aWStack_2e8,0x20);
        WVar4 = SendMessageW(param_4,0x158,0xffffffff,(LPARAM)aWStack_2e8);
        if ((int)WVar4 < 0) goto LAB_401e6f10;
        SendMessageW(param_4,0x14e,WVar4,0);
        SendMessageW(param_4,0x142,0,0xffff);
      }
    }
    else {
      if (uVar9 != 0x473) goto LAB_401e6948;
      if (param_3 >> 0x10 != 1) goto LAB_401e6f10;
    }
  }
  InvalidateRect(param_1,(RECT *)(param_2 + 2),0);
  UpdateWindow(param_1);
LAB_401e6f10:
  FUN_401ee698(local_28);
  return 1;
}



/* 401e6f44 FUN_401e6f44 */

/* Boundary evidence: original MIPS .pdata 401e6f44..401e7243. Semantic name remains unreviewed. */

void FUN_401e6f44(HWND param_1,int param_2,int param_3,HDC param_4)

{
  int iVar1;
  HFONT h;
  HGDIOBJ pvVar2;
  DWORD color;
  COLORREF color_00;
  WPARAM wParam;
  COLORREF CVar3;
  size_t c;
  int nIndex;
  LONG x;
  LONG LVar4;
  tagRECT local_148;
  tagSIZE local_138;
  tagTEXTMETRICW tStack_130;
  LOGFONTW LStack_f0;
  WCHAR local_90 [50];
  uint local_2c;
  
  local_2c = DAT_401ef2a8;
  iVar1 = FUN_401e6424(param_1,param_2,param_3,&LStack_f0.lfHeight,0);
  h = CreateFontIndirectW(&LStack_f0);
  if (h == (HFONT)0x0) goto LAB_401e7210;
  pvVar2 = SelectObject(param_4,h);
  if (*(uint *)(param_2 + 0x1c) < 0x40000) {
    nIndex = 0x40000005;
  }
  else {
    nIndex = 0x4000000f;
  }
  color = GetSysColor(nIndex);
  color_00 = SetBkColor(param_4,color);
  if ((*(uint *)(param_3 + 0x14) & 0x100) == 0) {
LAB_401e7054:
    CVar3 = GetSysColor(0x40000008);
  }
  else {
    wParam = SendDlgItemMessageW(param_1,0x473,0x147,0,0);
    if (wParam == 0xffffffff) goto LAB_401e7054;
    CVar3 = SendDlgItemMessageW(param_1,0x473,0x150,wParam,0);
  }
  CVar3 = SetTextColor(param_4,CVar3);
  if (iVar1 == 0) {
    local_90[0] = L'\0';
  }
  else {
    GetDlgItemTextW(param_1,0x444,local_90,0x32);
  }
  GetTextMetricsW(param_4,&tStack_130);
  c = wcslen(local_90);
  GetTextExtentExPointW(param_4,local_90,c,0,(LPINT)0x0,(LPINT)0x0,&local_138);
  local_148.left = *(int *)(param_2 + 8);
  local_138.cy = tStack_130.tmAscent - tStack_130.tmInternalLeading;
  local_148.top = *(int *)(param_2 + 0xc);
  local_148.right = *(int *)(param_2 + 0x10);
  local_148.bottom = *(int *)(param_2 + 0x14);
  if (*(uint *)(param_2 + 0x1c) < 0x40000) {
    SendMessageW(param_1,0x138,(WPARAM)param_4,0);
  }
  else {
    DrawEdge(param_4,&local_148,10,0x200f);
  }
  x = local_148.left;
  if ((local_138.cx < local_148.right - local_148.left) && (0 < local_138.cx)) {
    iVar1 = (local_148.right - local_148.left) - local_138.cx;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 1;
    }
    x = (iVar1 >> 1) + local_148.left;
  }
  iVar1 = (local_148.bottom - local_148.top) - local_138.cy;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 1;
  }
  iVar1 = local_148.bottom - (iVar1 >> 1);
  LVar4 = local_148.bottom;
  if (iVar1 <= local_148.bottom) {
    LVar4 = iVar1;
  }
  ExtTextOutW(param_4,x,LVar4 - tStack_130.tmAscent,6,&local_148,local_90,c,(INT *)0x0);
  SetBkColor(param_4,color_00);
  SetTextColor(param_4,CVar3);
  if (pvVar2 != (HGDIOBJ)0x0) {
    pvVar2 = SelectObject(param_4,pvVar2);
    DeleteObject(pvVar2);
  }
LAB_401e7210:
  FUN_401ee698(local_2c);
  return;
}



/* 401e7244 FUN_401e7244 */

/* Boundary evidence: original MIPS .pdata 401e7244..401e7ad3. Semantic name remains unreviewed. */

int FUN_401e7244(HWND param_1,int param_2,uint param_3,HWND param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  BOOL BVar4;
  LRESULT LVar5;
  HWND pHVar6;
  undefined3 extraout_var;
  HDC pHVar7;
  int iVar8;
  uint uVar9;
  HGDIOBJ h;
  HGDIOBJ h_00;
  LPVOID pvVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  WPARAM WVar14;
  tagTEXTMETRICW local_100;
  tagWNDCLASSW tStack_c0;
  tagPAINTSTRUCT local_98;
  wchar_t awStack_58 [20];
  uint local_30;
  
  local_30 = DAT_401ef2a8;
  iVar13 = 0;
  piVar2 = (int *)GetWindowLongW(param_1,8);
  if (piVar2 == (int *)0x0) {
    if (((DAT_401ef3cc != (code *)0x0) && (param_2 != 0x110)) &&
       (iVar3 = (*DAT_401ef3cc)(param_1,param_2,param_3,param_4), iVar3 != 0)) goto LAB_401e7a98;
  }
  else {
    iVar13 = *piVar2;
    if (((iVar13 != 0) && (*(code **)(iVar13 + 0x20) != (code *)0x0)) &&
       (iVar3 = (**(code **)(iVar13 + 0x20))(param_1,param_2,param_3,param_4), iVar3 != 0)) {
      if ((param_2 == 0x111) && ((param_3 & 0xffff) == 2)) {
        DAT_401ef4a4 = 1;
      }
      goto LAB_401e7a98;
    }
  }
  iVar3 = 1;
  if (param_2 == 2) {
LAB_401e7a98:
    FUN_401ee698(local_30);
    return iVar3;
  }
  WVar14 = 0xf;
  if (param_2 == 0xf) {
    if (piVar2 == (int *)0x0) goto LAB_401e79a8;
    pHVar7 = BeginPaint(param_1,&local_98);
    if (pHVar7 != (HDC)0x0) {
      FUN_401e6f44(param_1,(int)piVar2,iVar13,local_98.hdc);
      EndPaint(param_1,&local_98);
    }
    goto LAB_401e7a98;
  }
  if (param_2 == 0x2c) {
    pHVar7 = GetDC(param_1);
    h = (HGDIOBJ)SendMessageW(param_1,0x31,0,0);
    h_00 = (HGDIOBJ)0x0;
    if (h != (HGDIOBJ)0x0) {
      h_00 = SelectObject(pHVar7,h);
    }
    GetTextMetricsW(pHVar7,&local_100);
    if (h_00 != (HGDIOBJ)0x0) {
      SelectObject(pHVar7,h_00);
    }
    ReleaseDC(param_1,pHVar7);
    if (param_4[2].unused == -1) {
      local_100.tmHeight = local_100.tmHeight + 1;
    }
    else if (local_100.tmHeight < 0xd) {
      local_100.tmHeight = 0xc;
    }
    param_4[4].unused = local_100.tmHeight;
    goto LAB_401e7a98;
  }
  if (param_2 != 0x110) {
    if (piVar2 != (int *)0x0) {
      if (param_2 == 0x111) {
        iVar3 = FUN_401e68f0(param_1,piVar2,param_3,param_4);
      }
      else {
        if (param_2 != 0x401) goto LAB_401e79a8;
        iVar3 = FUN_401e6424(param_1,(int)piVar2,iVar13,&param_4->unused,1);
      }
      goto LAB_401e7a98;
    }
    goto LAB_401e79a8;
  }
  iVar13 = FUN_401e800c();
  if ((iVar13 != 0) && (BVar4 = GetClassInfoW(DAT_401ef478,L"SIPPREF",&tStack_c0), BVar4 != 0)) {
    CreateWindowExW(0,L"SIPPREF",(LPCWSTR)0x0,0x40000000,-10,-10,5,5,param_1,(HMENU)0x0,DAT_401ef478
                    ,(LPVOID)0x0);
  }
  iVar13 = LoadStringW(DAT_401ef478,0x197c,(LPWSTR)&DAT_401ef308,0x20);
  if ((((iVar13 == 0) ||
       (iVar13 = LoadStringW(DAT_401ef478,0x197d,(LPWSTR)&DAT_401ef348,0x20), iVar13 == 0)) ||
      (iVar13 = LoadStringW(DAT_401ef478,0x197e,(LPWSTR)&DAT_401ef388,0x20), iVar13 == 0)) ||
     (iVar13 = LoadStringW(DAT_401ef478,0x197f,(LPWSTR)&DAT_401ef2c8,0x20), iVar13 == 0)) {
    pvVar10 = (LPVOID)0x5;
LAB_401e7994:
    FUN_401e8100(pvVar10);
  }
  else {
    iVar13 = param_4->unused;
    puVar12 = (uint *)(iVar13 + 0x14);
    if (((*puVar12 & 0x2000) != 0) && (*(int *)(iVar13 + 0x38) < *(int *)(iVar13 + 0x34))) {
      pvVar10 = (LPVOID)0x2002;
      goto LAB_401e7994;
    }
    SetWindowLongW(param_1,8,(LONG)param_4);
    DAT_401ef3cc = (code *)0x0;
    DAT_401ef3c8 = SendMessageW(param_1,0x31,0,0);
    if ((*puVar12 & 0x200) == 0) {
      FUN_401e4a80(param_1,0x402);
    }
    if ((*puVar12 & 0x100) == 0) {
      FUN_401e4a80(param_1,0x443);
      FUN_401e4a80(param_1,0x473);
    }
    else {
      FUN_401e5ce0(param_1);
      do {
        LVar5 = SendDlgItemMessageW(param_1,0x473,0x150,WVar14,0);
        if (*(int *)(iVar13 + 0x18) == LVar5) break;
        WVar14 = (int)((WVar14 - 1) * 0x10000) >> 0x10;
      } while (0 < (int)WVar14);
      SendDlgItemMessageW(param_1,0x473,0x14e,WVar14,0);
    }
    pHVar6 = GetDlgItem(param_1,0x444);
    GetWindowRect(pHVar6,(LPRECT)(param_4 + 2));
    MapWindowPoints((HWND)0x0,param_1,(LPPOINT)(param_4 + 2),2);
    if ((*puVar12 & 0x40) == 0) {
      FUN_401e5c38(*(int **)(iVar13 + 0xc));
    }
    if ((*puVar12 & 0x100) == 0) {
      FUN_401e4a80(param_1,0x430);
      FUN_401e4a80(param_1,0x410);
      FUN_401e4a80(param_1,0x411);
    }
    else {
      SendDlgItemMessageW(param_1,0x410,0xf1,(uint)*(byte *)(*(int *)(iVar13 + 0xc) + 0x16),0);
      SendDlgItemMessageW(param_1,0x411,0xf1,(uint)*(byte *)(*(int *)(iVar13 + 0xc) + 0x15),0);
    }
    piVar2 = (int *)(iVar13 + 0xc);
    param_4[6].unused = 0;
    bVar1 = FUN_401e5128(param_1,*(HDC *)(iVar13 + 8),*puVar12);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      if (((*puVar12 & 0x80000) == 0) && (iVar11 = *piVar2, *(short *)(iVar11 + 0x1c) != 0)) {
        pHVar6 = GetDlgItem(param_1,0x470);
        WVar14 = FUN_401e5e38(pHVar6,(LPARAM)(iVar11 + 0x1c));
        if (WVar14 != 0xffffffff) {
          pHVar6 = GetDlgItem(param_1,0x470);
          FUN_401e4c28(pHVar6);
        }
      }
      pHVar7 = GetDC((HWND)0x0);
      if ((*puVar12 & 0x400040) == 0) {
        param_4[1].unused = 1;
      }
      else {
        param_4[1].unused = (uint)*(byte *)(*piVar2 + 0x17);
      }
      FUN_401e611c(param_1,(int)param_4,iVar13);
      if ((*puVar12 & 0x100000) == 0) {
        FUN_401e6794(param_1,iVar13,1);
      }
      if (((*puVar12 & 0x200000) == 0) && (*(int *)*piVar2 != 0)) {
        FUN_401e5db4(awStack_58,0x14,pHVar7,*(int *)*piVar2);
        pHVar6 = GetDlgItem(param_1,0x472);
        FUN_401e5e38(pHVar6,(LPARAM)awStack_58);
        SetDlgItemTextW(param_1,0x472,awStack_58);
      }
      ReleaseDC((HWND)0x0,pHVar7);
      if ((*puVar12 & 4) == 0) {
        iVar11 = GetSystemMetrics(1);
        iVar8 = GetSystemMetrics(0);
        if (iVar8 < iVar11) {
          uVar9 = GetWindowLongW(param_1,-0x14);
          SetWindowLongW(param_1,-0x14,uVar9 & 0xfffffbff);
        }
        else {
          pHVar6 = GetDlgItem(param_1,0x40e);
          ShowWindow(pHVar6,0);
          EnableWindow(pHVar6,0);
        }
      }
      SendDlgItemMessageW(param_1,0x470,0x141,0x1f,0);
      SendDlgItemMessageW(param_1,0x471,0x141,0x1f,0);
      SendDlgItemMessageW(param_1,0x472,0x141,4,0);
      if (*(code **)(iVar13 + 0x20) == (code *)0x0) {
        FUN_401e7f58(param_1,2);
      }
      else {
        iVar3 = (**(code **)(iVar13 + 0x20))(param_1,0x110,param_3,iVar13);
      }
      goto LAB_401e7a98;
    }
    FUN_401e8100((LPVOID)0x2001);
    if ((*puVar12 & 8) != 0) {
      DAT_401ef3cc = *(code **)(iVar13 + 0x20);
    }
  }
  EndDialog(param_1,0);
LAB_401e79a8:
  FUN_401ee698(local_30);
  return 0;
}



/* 401e7ad4 FUN_401e7ad4 */

/* Boundary evidence: original MIPS .pdata 401e7ad4..401e7e17. Semantic name remains unreviewed. */

undefined4 FUN_401e7ad4(undefined4 *param_1)

{
  bool bVar1;
  HLOCAL pvVar2;
  HRSRC pHVar3;
  LPCDLGTEMPLATEW hDialogTemplate;
  int iVar4;
  int iVar5;
  LPVOID pvVar6;
  LPCWSTR lpName;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  INT_PTR IVar11;
  
  piVar9 = (int *)*param_1;
  IVar11 = 2;
  bVar1 = false;
  FUN_401e8100((LPVOID)0x0);
  DAT_401ef4a4 = 0;
  if (piVar9 == (int *)0x0) {
    pvVar6 = (LPVOID)0x2;
    goto LAB_401e7b2c;
  }
  if (*piVar9 != 0x3c) {
    pvVar6 = (LPVOID)0x1;
    goto LAB_401e7b2c;
  }
  piVar8 = piVar9 + 3;
  if (*piVar8 == 0) {
    pvVar2 = LocalAlloc(0x40,0x5c);
    *piVar8 = (int)pvVar2;
    if (pvVar2 == (HLOCAL)0x0) {
      pvVar6 = (LPVOID)0x9;
      goto LAB_401e7b2c;
    }
    bVar1 = true;
  }
  param_1[7] = 0x40000;
  uVar7 = piVar9[5];
  piVar10 = piVar9 + 8;
  if ((uVar7 & 8) == 0) {
    *piVar10 = 0;
  }
  else if (*piVar10 == 0) {
    if (bVar1) {
      LocalFree((HLOCAL)*piVar8);
      *piVar8 = 0;
    }
    pvVar6 = (LPVOID)0xb;
    goto LAB_401e7b2c;
  }
  if ((uVar7 & 0x10) == 0) {
    if ((uVar7 & 0x20) == 0) {
      iVar4 = GetSystemMetrics(1);
      iVar5 = GetSystemMetrics(0);
      lpName = (LPCWSTR)0x15b7;
      if (iVar4 <= iVar5) {
        lpName = (LPCWSTR)0x15b6;
      }
      pHVar3 = FindResourceW(DAT_401ef478,lpName,(LPCWSTR)0x5);
      if (pHVar3 == (HRSRC)0x0) goto LAB_401e7c28;
      hDialogTemplate = LoadResource(DAT_401ef478,pHVar3);
      goto joined_r0x401e7d1c;
    }
    hDialogTemplate = (LPCDLGTEMPLATEW)piVar9[10];
    if (hDialogTemplate != (LPCDLGTEMPLATEW)0x0) goto LAB_401e7d30;
    pvVar6 = (LPVOID)0x8;
  }
  else {
    pHVar3 = FindResourceW((HMODULE)piVar9[10],(LPCWSTR)piVar9[9],(LPCWSTR)0x5);
    if (pHVar3 == (HRSRC)0x0) {
LAB_401e7c28:
      if (bVar1) {
        LocalFree((HLOCAL)*piVar8);
        *piVar8 = 0;
      }
      pvVar6 = (LPVOID)0x6;
      goto LAB_401e7b2c;
    }
    hDialogTemplate = LoadResource((HMODULE)piVar9[10],pHVar3);
joined_r0x401e7d1c:
    if (hDialogTemplate == (LPCDLGTEMPLATEW)0x0) {
      if (bVar1) {
        LocalFree((HLOCAL)*piVar8);
        *piVar8 = 0;
      }
      pvVar6 = (LPVOID)0x7;
LAB_401e7b2c:
      FUN_401e8100(pvVar6);
      return 0;
    }
LAB_401e7d30:
    if ((piVar9[5] & 8U) != 0) {
      DAT_401ef3cc = *piVar10;
    }
    FUN_401e7e54();
    IVar11 = DialogBoxIndirectParamW
                       (DAT_401ef478,hDialogTemplate,(HWND)piVar9[1],FUN_401e7244,(LPARAM)param_1);
    FUN_401e7ed4();
    DAT_401ef3cc = 0;
    if (((IVar11 != 0) || (DAT_401ef4a4 != 0)) || (pvVar6 = FUN_401e8150(), pvVar6 != (LPVOID)0x0))
    goto LAB_401e7dbc;
    pvVar6 = (LPVOID)0xffff;
  }
  FUN_401e8100(pvVar6);
LAB_401e7dbc:
  if (bVar1) {
    LocalFree((HLOCAL)*piVar8);
    *piVar8 = 0;
  }
  if (IVar11 == 1) {
    return 1;
  }
  return 0;
}



/* 401e7e18 ChooseFontW */

/* Boundary evidence: original MIPS .pdata 401e7e18..401e7e53. Semantic name remains unreviewed. */

BOOL ChooseFontW(LPCHOOSEFONTW param_1)

{
  BOOL BVar1;
  LPCHOOSEFONTW local_28 [8];
  
                    /* 0x7e18  2  ChooseFontW */
  memset(local_28,0,0x20);
  local_28[0] = param_1;
  BVar1 = FUN_401e7ad4(local_28);
  return BVar1;
}



/* 401e7e54 FUN_401e7e54 */

/* Boundary evidence: original MIPS .pdata 401e7e54..401e7ed3. Semantic name remains unreviewed. */

undefined4 FUN_401e7e54(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_401ef3d0);
  if (DAT_401ef3e4 == (HMODULE)0x0) {
    DAT_401ef3e4 = LoadLibraryW(L"aygshell.dll");
    if (DAT_401ef3e4 == (HMODULE)0x0) goto LAB_401e7eb4;
    DAT_401ef3ec = 1;
  }
  uVar1 = 1;
  DAT_401ef3f0 = DAT_401ef3f0 + 1;
LAB_401e7eb4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_401ef3d0);
  return uVar1;
}



/* 401e7ed4 FUN_401e7ed4 */

/* Boundary evidence: original MIPS .pdata 401e7ed4..401e7f57. Semantic name remains unreviewed. */

undefined4 FUN_401e7ed4(void)

{
  undefined4 uVar1;
  
  if (DAT_401ef3ec == 0) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_401ef3d0);
    DAT_401ef3f0 = DAT_401ef3f0 + -1;
    if (DAT_401ef3f0 < 1) {
      FreeLibrary(DAT_401ef3e4);
      DAT_401ef3e4 = (HMODULE)0x0;
      DAT_401ef3e8 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_401ef3d0);
    uVar1 = 1;
  }
  return uVar1;
}



/* 401e7f58 FUN_401e7f58 */

/* Boundary evidence: original MIPS .pdata 401e7f58..401e800b. Semantic name remains unreviewed. */

undefined4 FUN_401e7f58(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = 0;
  uVar3 = 0;
  memset(&local_1c,0,8);
  iVar1 = FUN_401e7e54();
  if (iVar1 != 0) {
    local_20 = 1;
    local_1c = param_1;
    local_18 = param_2;
    pcVar2 = (code *)GetProcAddressW(DAT_401ef3e4,L"SHInitDialog");
    if (pcVar2 != (code *)0x0) {
      uVar3 = (*pcVar2)(&local_20);
    }
    iVar1 = FUN_401e7ed4();
    if (iVar1 != 0) {
      return uVar3;
    }
  }
  return 0;
}



/* 401e800c FUN_401e800c */

/* Boundary evidence: original MIPS .pdata 401e800c..401e808f. Semantic name remains unreviewed. */

int FUN_401e800c(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = DAT_401ef3e8;
  if (DAT_401ef3e4 == 0) {
    iVar3 = 0;
  }
  else if (DAT_401ef3e8 == 0) {
    pcVar2 = (code *)GetProcAddressW(DAT_401ef3e4,L"SHInitExtraControls");
    iVar1 = iVar3;
    if (pcVar2 != (code *)0x0) {
      iVar3 = (*pcVar2)();
      iVar1 = iVar3;
    }
  }
  else {
    iVar3 = 1;
  }
  DAT_401ef3e8 = iVar1;
  return iVar3;
}



/* 401e8090 FUN_401e8090 */

/* Boundary evidence: original MIPS .pdata 401e8090..401e80ff. Semantic name remains unreviewed. */

undefined4 FUN_401e8090(void)

{
  int iVar1;
  
  iVar1 = GetSystemMetrics(6);
  DAT_401ef48a = (undefined2)iVar1;
  iVar1 = GetSystemMetrics(5);
  DAT_401ef49e = (undefined2)iVar1;
  DAT_401ef4a0 = 0x18;
  DAT_401ef490 = GetSysColor(0x4000000f);
  DAT_401ef4ac = 0;
  DAT_401ef4a8 = 0;
  return 1;
}



/* 401e8100 FUN_401e8100 */

/* Boundary evidence: original MIPS .pdata 401e8100..401e814f. Semantic name remains unreviewed. */

void FUN_401e8100(LPVOID param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_401ef4c0);
  TlsSetValue(DAT_401ef47c,param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_401ef4c0);
  return;
}



/* 401e8150 FUN_401e8150 */

/* Boundary evidence: original MIPS .pdata 401e8150..401e819f. Semantic name remains unreviewed. */

LPVOID FUN_401e8150(void)

{
  LPVOID pvVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_401ef4c0);
  pvVar1 = TlsGetValue(DAT_401ef47c);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_401ef4c0);
  return pvVar1;
}



/* 401e81a0 CommDlgExtendedError */

/* Boundary evidence: original MIPS .pdata 401e81a0..401e81bb. Semantic name remains unreviewed. */

DWORD CommDlgExtendedError(void)

{
  LPVOID pvVar1;
  
                    /* 0x81a0  3  CommDlgExtendedError */
  pvVar1 = FUN_401e8150();
  return (DWORD)pvVar1;
}



/* 401e81bc FUN_401e81bc */

/* Boundary evidence: original MIPS .pdata 401e81bc..401e82df. Semantic name remains unreviewed. */

undefined4 FUN_401e81bc(undefined4 param_1,int param_2,int param_3)

{
  LPVOID hMem;
  int iVar1;
  
  if (param_2 == 0) {
    if (param_3 != 0) {
      return 1;
    }
    FUN_401e1eb0();
    TlsCall(1,DAT_401ef47c);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_401ef4c0);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_401ef3d0);
    return 1;
  }
  if (param_2 == 1) {
    DAT_401ef478 = param_1;
    iVar1 = FUN_401e8090();
    if (iVar1 != 0) {
      DAT_401ef48c = 0;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_401ef4c0);
      DAT_401ef47c = TlsCall(0,0);
      if (DAT_401ef47c != 0xffffffff) {
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_401ef3d0);
        return 1;
      }
      FUN_401e8100((LPVOID)0x2);
    }
  }
  else {
    if (param_2 == 2) {
      return 1;
    }
    if (param_2 == 3) {
      hMem = TlsGetValue(DAT_401ef47c);
      if (hMem == (LPVOID)0x0) {
        return 1;
      }
      LocalFree(hMem);
      TlsSetValue(DAT_401ef47c,(LPVOID)0x0);
      return 1;
    }
  }
  return 0;
}



/* 401e82e0 FUN_401e82e0 */

/* Boundary evidence: original MIPS .pdata 401e82e0..401e838f. Semantic name remains unreviewed. */

void FUN_401e82e0(HWND param_1,UINT param_2,WPARAM param_3,LONG *param_4)

{
  POINT Point;
  WNDPROC lpPrevWndFunc;
  tagPOINT local_20;
  
  if (param_2 == 0x410) {
    local_20.x = *param_4;
    local_20.y = param_4[1];
    MapWindowPoints((HWND)0x0,DAT_401ef464,&local_20,1);
    Point.y = local_20.y;
    Point.x = local_20.x;
    ChildWindowFromPoint(DAT_401ef464,Point);
  }
  else {
    lpPrevWndFunc = (WNDPROC)GetWindowLongW(param_1,-0x15);
    CallWindowProcW(lpPrevWndFunc,param_1,param_2,param_3,(LPARAM)param_4);
  }
  return;
}



/* 401e8390 FUN_401e8390 */

/* Boundary evidence: original MIPS .pdata 401e8390..401e84bf. Semantic name remains unreviewed. */

void FUN_401e8390(HWND param_1,HKEY param_2)

{
  int iVar1;
  HWND pHVar2;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_401ef2a8;
  if (DAT_401ef46c != (HMODULE)0x0) {
    FreeLibrary(DAT_401ef46c);
  }
  FUN_401ede94(DAT_401ef414,param_2);
  iVar1 = FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_Driver_401ef294,1,(LPBYTE)aWStack_228,0x208);
  if (iVar1 != 0) {
    DAT_401ef46c = LoadLibraryW(aWStack_228);
    if (DAT_401ef46c != (HMODULE)0x0) {
      DAT_401ef470 = GetProcAddressW(DAT_401ef46c,L"DrvAdvPageSetupDlg");
      if (DAT_401ef470 != 0) {
        pHVar2 = GetDlgItem(param_1,0x3f7);
        EnableWindow(pHVar2,1);
        goto LAB_401e849c;
      }
    }
  }
  pHVar2 = GetDlgItem(param_1,0x3f7);
  EnableWindow(pHVar2,0);
  if (DAT_401ef46c != (HMODULE)0x0) {
    FreeLibrary(DAT_401ef46c);
  }
  DAT_401ef46c = (HMODULE)0x0;
LAB_401e849c:
  FUN_401ee698(local_20);
  return;
}



/* 401e84c0 FUN_401e84c0 */

/* Boundary evidence: original MIPS .pdata 401e84c0..401e8793. Semantic name remains unreviewed. */

undefined4 FUN_401e84c0(HWND param_1)

{
  HWND pHVar1;
  uint uVar2;
  wchar_t *_Str2;
  int iVar3;
  LRESULT LVar4;
  BOOL BVar5;
  LPCWSTR lpCaption;
  LPCWSTR lpText;
  int *piVar6;
  int *piVar7;
  int iVar8;
  UINT uID;
  UINT *pUVar9;
  undefined8 uVar10;
  wchar_t awStack_68 [32];
  uint local_28;
  
  local_28 = DAT_401ef2a8;
  pHVar1 = GetDlgItem(param_1,0x3ea);
  uVar2 = SendMessageW(pHVar1,0x147,0,0);
  pHVar1 = GetDlgItem(param_1,0x3ea);
  SendMessageW(pHVar1,0x148,uVar2 & 0xffff,(LPARAM)awStack_68);
  iVar8 = 0;
  pUVar9 = &DAT_401e12ec;
  do {
    _Str2 = (wchar_t *)LoadStringW(DAT_401ef478,*pUVar9,(LPWSTR)0x0,0);
    iVar3 = wcscmp(awStack_68,_Str2);
    if (iVar3 == 0) {
      if (iVar8 != -1) goto LAB_401e85a4;
      break;
    }
    pUVar9 = pUVar9 + 4;
    iVar8 = iVar8 + 1;
  } while ((int)pUVar9 < 0x401e132c);
  iVar8 = 0;
LAB_401e85a4:
  LVar4 = SendDlgItemMessageW(param_1,0x3ef,0xf0,0,0);
  if (LVar4 == 1) {
    piVar6 = &DAT_401e12f4 + iVar8 * 4;
    piVar7 = &DAT_401e12f0 + iVar8 * 4;
  }
  else {
    piVar6 = &DAT_401e12f0 + iVar8 * 4;
    piVar7 = &DAT_401e12f4 + iVar8 * 4;
  }
  iVar8 = *piVar6;
  iVar3 = *piVar7;
  if ((*(uint *)(DAT_401ef418 + 0x10) & 8) != 0) {
    uVar10 = __litodp(iVar8);
    uVar10 = __dpmul((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0x851eb852,0x400451eb);
    iVar8 = __dptoli((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    uVar10 = __litodp(iVar3);
    uVar10 = __dpmul((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0x851eb852,0x400451eb);
    iVar3 = __dptoli((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
  }
  if (iVar8 < DAT_401ef40c + DAT_401ef404) {
    uID = 0x13;
  }
  else if (iVar3 < DAT_401ef410 + DAT_401ef408) {
    uID = 0x14;
  }
  else {
    pHVar1 = GetDlgItem(param_1,0x3f6);
    BVar5 = IsWindowEnabled(pHVar1);
    if ((BVar5 == 0) || (iVar8 = GetWindowTextLengthW(pHVar1), iVar8 != 0)) {
      FUN_401ee698(local_28);
      return 1;
    }
    uID = 0x12;
    pHVar1 = GetDlgItem(param_1,0x3f6);
    SetFocus(pHVar1);
  }
  lpCaption = (LPCWSTR)LoadStringW(DAT_401ef478,0x11,(LPWSTR)0x0,0);
  lpText = (LPCWSTR)LoadStringW(DAT_401ef478,uID,(LPWSTR)0x0,0);
  MessageBoxW(param_1,lpText,lpCaption,0x30);
  FUN_401ee698(local_28);
  return 0;
}



/* 401e8794 FUN_401e8794 */

/* Boundary evidence: original MIPS .pdata 401e8794..401e89f3. Semantic name remains unreviewed. */

void FUN_401e8794(HWND param_1,wchar_t *param_2)

{
  HWND pHVar1;
  uint uVar2;
  HKEY pHVar3;
  wchar_t *_Source;
  int iVar4;
  LRESULT LVar5;
  wchar_t wVar6;
  wchar_t wVar7;
  HKEY pHVar8;
  wchar_t local_28 [4];
  
  if (param_2 != (wchar_t *)0x0) {
    memset(param_2,0,0xc0);
    pHVar1 = GetDlgItem(param_1,1000);
    uVar2 = SendMessageW(pHVar1,0x147,0,0);
    pHVar8 = (HKEY)(uVar2 & 0xffff);
    if ((DAT_401ef414 != (PHKEY)0x0) &&
       (pHVar3 = (HKEY)FUN_401ed9d8((int)DAT_401ef414), pHVar8 < pHVar3)) {
      _Source = (wchar_t *)FUN_401ed9a4((int)DAT_401ef414,(uint)pHVar8);
      wcscpy(param_2,_Source);
    }
    param_2[0x20] = L'Ѐ';
    FUN_401ede94(DAT_401ef414,pHVar8);
    iVar4 = FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_Version_401ef28c,4,(LPBYTE)local_28,4);
    if (iVar4 != 0) {
      param_2[0x21] = local_28[0];
    }
    param_2[0x22] = L'À';
    *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) | 1;
    LVar5 = SendDlgItemMessageW(param_1,0x3ee,0xf0,0,0);
    wVar7 = L'\x02';
    wVar6 = L'\x01';
    if (LVar5 != 1) {
      wVar6 = L'\x02';
    }
    param_2[0x26] = wVar6;
    *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) | 2;
    pHVar1 = GetDlgItem(param_1,0x3ea);
    uVar2 = SendMessageW(pHVar1,0x147,0,0);
    param_2[0x27] = (&DAT_401e12e8)[(uVar2 & 0xffff) * 8];
    param_2[0x2b] = L'\x01';
    *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) | 0x500;
    LVar5 = SendDlgItemMessageW(param_1,0x3eb,0xf0,0,0);
    wVar6 = L'\xffff';
    if (LVar5 != 1) {
      wVar6 = L'￼';
    }
    param_2[0x2d] = wVar6;
    *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) | 0x800;
    LVar5 = SendDlgItemMessageW(param_1,0x3f4,0xf0,0,0);
    if (LVar5 != 1) {
      wVar7 = L'\x01';
    }
    param_2[0x2e] = wVar7;
    *(uint *)(DAT_401ef418 + 0x10) = *(uint *)(DAT_401ef418 + 0x10) & 0xdfffffff;
    LVar5 = SendDlgItemMessageW(param_1,0x3ed,0xf0,0,0);
    if (LVar5 == 1) {
      *(uint *)(DAT_401ef418 + 0x10) = *(uint *)(DAT_401ef418 + 0x10) | 0x20000000;
    }
  }
  return;
}



/* 401e89f4 FUN_401e89f4 */

/* Boundary evidence: original MIPS .pdata 401e89f4..401e8b0f. Semantic name remains unreviewed. */

undefined1 * FUN_401e89f4(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3)

{
  size_t sVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  
  sVar1 = wcslen(param_1);
  uVar3 = (sVar1 + 5) * 2 & 0xffff;
  sVar1 = wcslen(param_2);
  uVar4 = (sVar1 + 1) * 2 + uVar3 & 0xffff;
  sVar1 = wcslen(param_3);
  puVar2 = LocalAlloc(0x40,(sVar1 + 1) * 2 + uVar4 & 0xffff);
  if (puVar2 == (undefined1 *)0x0) {
    FUN_401e8100((LPVOID)0x9);
    puVar2 = (undefined1 *)0x0;
  }
  else {
    wcscpy((wchar_t *)(puVar2 + 8),param_1);
    wcscpy((wchar_t *)(puVar2 + uVar3),param_2);
    wcscpy((wchar_t *)(puVar2 + uVar4),param_3);
    puVar2[2] = (char)uVar3;
    puVar2[4] = (char)uVar4;
    puVar2[1] = 0;
    puVar2[3] = (char)(uVar3 >> 8);
    *puVar2 = 8;
    puVar2[5] = (char)(uVar4 >> 8);
    puVar2[6] = 1;
    puVar2[7] = 0;
  }
  return puVar2;
}



/* 401e8b10 FUN_401e8b10 */

/* Boundary evidence: original MIPS .pdata 401e8b10..401e8c17. Semantic name remains unreviewed. */

void FUN_401e8b10(LPBYTE param_1,STRSAFE_LPCWSTR param_2)

{
  int iVar1;
  long lVar2;
  WCHAR local_18 [4];
  
  FUN_401ed9e0(DAT_401ef414,param_2);
  iVar1 = FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_DEVMODE_401ef2a4,3,param_1,0xc0);
  if (iVar1 == 0) {
    local_18[0] = L'0';
    local_18[1] = 0;
    memset(param_1,0,0xc0);
    param_1[0x44] = 0xc0;
    param_1[0x45] = '\0';
    param_1[0x5a] = 0xff;
    param_1[0x5b] = 0xff;
    param_1[0x4c] = '\x01';
    param_1[0x4d] = '\0';
    param_1[0x56] = '\x01';
    param_1[0x57] = '\0';
    param_1[0x5c] = '\x01';
    param_1[0x5d] = '\0';
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0xd03;
    GetLocaleInfoW(0x400,0x100a,local_18,2);
    local_18[1] = 0;
    lVar2 = _wtol(local_18);
    if ((((lVar2 == 1) || (lVar2 == 5)) || (lVar2 == 9)) || (lVar2 == 0xd)) {
      *(short *)(param_1 + 0x4e) = (short)lVar2;
    }
    else {
      param_1[0x4e] = '\x01';
      param_1[0x4f] = '\0';
    }
  }
  return;
}



/* 401e8c18 FUN_401e8c18 */

/* Boundary evidence: original MIPS .pdata 401e8c18..401e8cc3. Semantic name remains unreviewed. */

void FUN_401e8c18(HWND param_1,HWND param_2)

{
  LRESULT LVar1;
  int iVar2;
  HWND hWnd;
  WCHAR aWStack_58 [32];
  uint local_18;
  
  local_18 = DAT_401ef2a8;
  LVar1 = SendMessageW(param_2,0x147,0,0);
  SendMessageW(param_2,0x148,(int)(short)LVar1,(LPARAM)aWStack_58);
  iVar2 = lstrcmpiW(aWStack_58,(LPCWSTR)&DAT_401ef41c);
  hWnd = GetDlgItem(param_1,0x3f6);
  EnableWindow(hWnd,(uint)(iVar2 == 0));
  FUN_401ee698(local_18);
  return;
}



/* 401e8cc4 FUN_401e8cc4 */

/* Boundary evidence: original MIPS .pdata 401e8cc4..401e8e3f. Semantic name remains unreviewed. */

LRESULT FUN_401e8cc4(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  size_t sVar1;
  LRESULT LVar2;
  uint wParam;
  ushort *puVar3;
  int iVar4;
  WPARAM local_res8 [2];
  WCHAR local_20 [4];
  
  local_20[0] = L'\0';
  local_res8[0] = param_3;
  if (param_2 == 0x102) {
    local_res8[0] = param_3;
    LCMapStringW(0x400,0x400000,(LPCWSTR)local_res8,1,local_20,1);
    wParam = (uint)(ushort)local_20[0];
    local_res8[0] = wParam;
    if (((((wParam != 8) && (wParam != 0x18)) && (wParam != 3)) &&
        ((wParam != 0x16 && (wParam != 0x1a)))) &&
       ((wParam != DAT_401ef3f4 && ((wParam < 0x30 || (0x39 < wParam)))))) {
      puVar3 = &DAT_401ef3f8;
      iVar4 = 0;
      sVar1 = wcslen(&DAT_401ef3f8);
      if (0 < (int)sVar1) {
        do {
          if (wParam == *puVar3) {
            LVar2 = CallWindowProcW(DAT_401ef460,param_1,0x102,wParam,param_4);
            return LVar2;
          }
          iVar4 = iVar4 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar4 < (int)sVar1);
      }
      MessageBeep(0);
      return 0;
    }
  }
  LVar2 = CallWindowProcW(DAT_401ef460,param_1,param_2,local_res8[0],param_4);
  return LVar2;
}



/* 401e8e40 FUN_401e8e40 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 401e8e40..401e905b. Semantic name remains unreviewed. */

void FUN_401e8e40(HWND param_1,int param_2,int param_3)

{
  size_t sVar1;
  LPCWSTR lpString;
  wchar_t *pwVar2;
  short *psVar3;
  int iVar4;
  WCHAR local_48 [3];
  short sStack_42;
  wchar_t local_40;
  WCHAR local_3e [15];
  uint local_20;
  
  local_20 = DAT_401ef2a8;
  local_48[0] = L'\0';
  memset(local_48 + 1,0,2);
  if ((param_3 < 0) &&
     (((*(uint *)(DAT_401ef418 + 0x10) & 1) == 0 || (param_3 = param_2, param_2 < 0)))) {
    param_3 = 0;
  }
  if ((*(uint *)(DAT_401ef418 + 0x10) & 4) == 0) {
    iVar4 = param_3 % 100;
    if (iVar4 == 0) {
      pwVar2 = L"%lu";
    }
    else {
      pwVar2 = L"%lu%c%02lu";
    }
    StringCchPrintfW(&local_40,0x10,pwVar2,param_3 / 100,(uint)(ushort)DAT_401ef3f4,iVar4);
  }
  else {
    iVar4 = param_3 % 1000;
    if (iVar4 == 0) {
      pwVar2 = L"%lu";
    }
    else {
      pwVar2 = L"%lu%c%03lu";
    }
    StringCchPrintfW(&local_40,0x10,pwVar2,param_3 / 1000,(uint)(ushort)DAT_401ef3f4,iVar4);
  }
  if ((iVar4 != 0) && (local_40 != L'\0')) {
    sVar1 = wcslen(&local_40);
    for (psVar3 = &sStack_42 + sVar1; (psVar3 != (short *)0x0 && (*psVar3 == 0x30));
        psVar3 = psVar3 + -1) {
      *psVar3 = 0;
    }
  }
  sVar1 = wcslen(&local_40);
  if (sVar1 < 6) {
    wcscat(&local_40,&DAT_401ef3f8);
  }
  GetLocaleInfoW(0x400,0x12,local_48,2);
  local_48[1] = 0;
  if (((local_40 != L'0') || (local_3e[0] != DAT_401ef3f4)) ||
     (lpString = local_3e, local_48[0] != L'0')) {
    lpString = &local_40;
  }
  SetWindowTextW(param_1,lpString);
  FUN_401ee698(local_20);
  return;
}



/* 401e905c FUN_401e905c */

/* Boundary evidence: original MIPS .pdata 401e905c..401e922f. Semantic name remains unreviewed. */

void FUN_401e905c(HWND param_1,int param_2,int *param_3)

{
  wchar_t wVar1;
  int iVar2;
  wchar_t *lpString;
  long lVar3;
  wchar_t *pwVar4;
  wchar_t *_Dest;
  
  iVar2 = GetWindowTextLengthW(param_1);
  lpString = LocalAlloc(0x40,(iVar2 + 6) * 2);
  if (lpString == (wchar_t *)0x0) {
    if ((*(uint *)(DAT_401ef418 + 0x10) & 1) == 0) {
      param_2 = 0;
    }
    *param_3 = param_2;
  }
  else {
    GetWindowTextW(param_1,lpString,iVar2 + 6);
    lVar3 = _wtol(lpString);
    *param_3 = lVar3;
    wVar1 = *lpString;
    _Dest = lpString;
    while ((wVar1 != L'\0' && (wVar1 = *_Dest, _Dest = _Dest + 1, wVar1 != DAT_401ef3f4))) {
      wVar1 = *_Dest;
    }
    wVar1 = *_Dest;
    pwVar4 = _Dest;
    while (wVar1 != L'\0') {
      if (*pwVar4 == DAT_401ef3f8) {
        *pwVar4 = L'\0';
        break;
      }
      pwVar4 = pwVar4 + 1;
      wVar1 = *pwVar4;
    }
    wcscat(_Dest,L"000");
    if ((*(uint *)(DAT_401ef418 + 0x10) & 4) == 0) {
      *param_3 = *param_3 * 100;
      _Dest[2] = L'\0';
    }
    else {
      *param_3 = *param_3 * 1000;
      _Dest[3] = L'\0';
    }
    lVar3 = _wtol(_Dest);
    iVar2 = lVar3 + *param_3;
    *param_3 = iVar2;
    if ((*(uint *)(DAT_401ef418 + 0x10) & 1) != 0) {
      if (param_2 <= iVar2) {
        param_2 = iVar2;
      }
      *param_3 = param_2;
    }
    LocalFree(lpString);
  }
  return;
}



/* 401e9230 FUN_401e9230 */

/* Boundary evidence: original MIPS .pdata 401e9230..401e93e3. Semantic name remains unreviewed. */

undefined4 FUN_401e9230(void)

{
  int iVar1;
  HLOCAL pvVar2;
  undefined1 *puVar3;
  LPVOID pvVar4;
  wchar_t local_468 [32];
  WCHAR aWStack_428 [260];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_401ef2a8;
  local_468[0] = L'\0';
  FUN_401edad4(DAT_401ef414);
  FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_DefaultPrinter_401ef280,1,(LPBYTE)local_468,0x40);
  FUN_401ed9e0(DAT_401ef414,local_468);
  iVar1 = FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_Port_401ef288,1,(LPBYTE)aWStack_428,0x208);
  if ((iVar1 == 0) ||
     (((iVar1 = lstrcmpiW(aWStack_428,(LPCWSTR)PTR_u_NET0__401ef290), iVar1 == 0 &&
       (iVar1 = FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_NetPath_401ef284,1,(LPBYTE)aWStack_428,
                             0x208), iVar1 == 0)) ||
      (iVar1 = FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_Driver_401ef294,1,(LPBYTE)awStack_220,0x208)
      , iVar1 == 0)))) {
    pvVar4 = (LPVOID)0x100;
  }
  else {
    pvVar2 = LocalAlloc(0,0xc0);
    *(HLOCAL *)(DAT_401ef418 + 8) = pvVar2;
    if (*(int *)(DAT_401ef418 + 8) != 0) {
      FUN_401e8b10(*(LPBYTE *)(DAT_401ef418 + 8),local_468);
      puVar3 = FUN_401e89f4(awStack_220,local_468,aWStack_428);
      *(undefined1 **)(DAT_401ef418 + 0xc) = puVar3;
      if (*(int *)(DAT_401ef418 + 0xc) != 0) {
        FUN_401ee698(local_18);
        return 1;
      }
      goto LAB_401e92c8;
    }
    pvVar4 = (LPVOID)0x9;
  }
  FUN_401e8100(pvVar4);
LAB_401e92c8:
  FUN_401ee698(local_18);
  return 0;
}



/* 401e93e4 FUN_401e93e4 */

/* Boundary evidence: original MIPS .pdata 401e93e4..401e966f. Semantic name remains unreviewed. */

void FUN_401e93e4(HWND param_1)

{
  HWND pHVar1;
  uint uVar2;
  STRSAFE_LPCWSTR pwVar3;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  BYTE *pBVar7;
  short *psVar8;
  BYTE *pBVar9;
  BYTE aBStack_128 [192];
  WCHAR aWStack_68 [32];
  uint local_28;
  
  local_28 = DAT_401ef2a8;
  pBVar9 = *(BYTE **)(DAT_401ef418 + 8);
  pHVar1 = GetDlgItem(param_1,1000);
  uVar2 = SendMessageW(pHVar1,0x147,0,0);
  pwVar3 = (STRSAFE_LPCWSTR)FUN_401ed9a4(DAT_401ef414,uVar2 & 0xffff);
  FUN_401e8b10(aBStack_128,pwVar3);
  pHVar1 = GetDlgItem(param_1,0x3eb);
  BVar4 = IsWindowEnabled(pHVar1);
  if (BVar4 != 0) {
    if ((pBVar9 == (BYTE *)0x0) || (pBVar7 = pBVar9, (*(uint *)(pBVar9 + 0x48) & 0x400) == 0)) {
      pBVar7 = aBStack_128;
    }
    SendDlgItemMessageW(param_1,0x3eb,0xf1,(uint)(*(short *)(pBVar7 + 0x5a) != -4),0);
  }
  pHVar1 = GetDlgItem(param_1,0x3f4);
  BVar4 = IsWindowEnabled(pHVar1);
  if (BVar4 != 0) {
    if ((pBVar9 == (BYTE *)0x0) || (pBVar7 = pBVar9, (*(uint *)(pBVar9 + 0x48) & 0x800) == 0)) {
      pBVar7 = aBStack_128;
    }
    SendDlgItemMessageW(param_1,0x3f4,0xf1,(uint)(*(short *)(pBVar7 + 0x5c) == 2),0);
  }
  if ((pBVar9 == (BYTE *)0x0) || (pBVar7 = pBVar9, (*(uint *)(pBVar9 + 0x48) & 1) == 0)) {
    pBVar7 = aBStack_128;
  }
  iVar6 = 0x3ef;
  if (*(short *)(pBVar7 + 0x4c) != 2) {
    iVar6 = 0x3ee;
  }
  CheckRadioButton(param_1,0x3ee,0x3ef,iVar6);
  iVar6 = 0x3ed;
  if ((*(uint *)(DAT_401ef418 + 0x10) & 0x20000000) == 0) {
    iVar6 = 0x3ec;
  }
  CheckRadioButton(param_1,0x3ec,0x3ed,iVar6);
  if ((pBVar9 == (BYTE *)0x0) || ((*(uint *)(pBVar9 + 0x48) & 2) == 0)) {
    pBVar9 = aBStack_128;
  }
  psVar8 = &DAT_401e12e8;
  iVar6 = 0;
  do {
    iVar5 = iVar6;
    if (*(short *)(pBVar9 + 0x4e) == *psVar8) break;
    psVar8 = psVar8 + 8;
    iVar6 = iVar6 + 1;
    iVar5 = 3;
  } while ((int)psVar8 < 0x401e1328);
  LoadStringW(DAT_401ef478,(&DAT_401e12ec)[iVar5 * 4],aWStack_68,0x20);
  SendDlgItemMessageW(param_1,0x3ea,0x14d,0,(LPARAM)aWStack_68);
  FUN_401e8390(param_1,(HKEY)(uVar2 & 0xffff));
  FUN_401ee698(local_28);
  return;
}



/* 401e9670 FUN_401e9670 */

/* Boundary evidence: original MIPS .pdata 401e9670..401e981f. Semantic name remains unreviewed. */

void FUN_401e9670(HWND param_1)

{
  HWND pHVar1;
  
  if ((*(uint *)(DAT_401ef418 + 0x10) & 0x10000000) != 0) {
    pHVar1 = GetDlgItem(param_1,0x3ec);
    EnableWindow(pHVar1,0);
    pHVar1 = GetDlgItem(param_1,0x3ed);
    EnableWindow(pHVar1,0);
  }
  if ((*(uint *)(DAT_401ef418 + 0x10) & 0x100) != 0) {
    pHVar1 = GetDlgItem(param_1,0x3ef);
    EnableWindow(pHVar1,0);
    pHVar1 = GetDlgItem(param_1,0x3ee);
    EnableWindow(pHVar1,0);
  }
  if ((*(uint *)(DAT_401ef418 + 0x10) & 0x200) != 0) {
    pHVar1 = GetDlgItem(param_1,0x3ea);
    EnableWindow(pHVar1,0);
  }
  if ((*(uint *)(DAT_401ef418 + 0x10) & 0x20) != 0) {
    pHVar1 = GetDlgItem(param_1,1000);
    EnableWindow(pHVar1,0);
  }
  if ((*(uint *)(DAT_401ef418 + 0x10) & 0x10) != 0) {
    pHVar1 = GetDlgItem(param_1,0x3f0);
    EnableWindow(pHVar1,0);
    pHVar1 = GetDlgItem(param_1,0x3f2);
    EnableWindow(pHVar1,0);
    pHVar1 = GetDlgItem(param_1,0x3f1);
    EnableWindow(pHVar1,0);
    pHVar1 = GetDlgItem(param_1,0x3f3);
    EnableWindow(pHVar1,0);
  }
  FUN_401e93e4(param_1);
  return;
}



/* 401e9820 FUN_401e9820 */

/* Boundary evidence: original MIPS .pdata 401e9820..401e9a5f. Semantic name remains unreviewed. */

undefined4 FUN_401e9820(HWND param_1,wchar_t *param_2)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  HRESULT HVar4;
  undefined1 *puVar5;
  wchar_t *pwVar6;
  undefined4 uVar7;
  WCHAR local_478 [32];
  WCHAR aWStack_438 [260];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_401ef2a8;
  uVar7 = 0;
  FUN_401edad4(DAT_401ef414);
  sVar1 = wcslen(param_2);
  iVar2 = FUN_401edbf0(DAT_401ef414,(LPCWSTR)PTR_u_DefaultPrinter_401ef280,1,(BYTE *)param_2,
                       (sVar1 + 1) * 2);
  if (iVar2 != 0) {
    uVar3 = SendDlgItemMessageW(param_1,0x3e9,0x147,0,0);
    SendDlgItemMessageW(param_1,0x3e9,0x148,uVar3 & 0xffff,(LPARAM)local_478);
    iVar2 = lstrcmpiW(local_478,(LPCWSTR)&DAT_401ef41c);
    if ((iVar2 == 0) &&
       (HVar4 = StringCchCopyW(local_478,0x20,(STRSAFE_LPCWSTR)PTR_u_NET0__401ef290), HVar4 < 0)) {
      local_478[0] = L'\0';
    }
    GetDlgItemTextW(param_1,0x3f6,aWStack_438,0x104);
    FUN_401ed9e0(DAT_401ef414,param_2);
    sVar1 = wcslen(local_478);
    iVar2 = FUN_401edbf0(DAT_401ef414,(LPCWSTR)PTR_u_Port_401ef288,1,(BYTE *)local_478,
                         (sVar1 + 1) * 2);
    if (iVar2 != 0) {
      sVar1 = wcslen(aWStack_438);
      iVar2 = FUN_401edbf0(DAT_401ef414,(LPCWSTR)PTR_u_NetPath_401ef284,1,(BYTE *)aWStack_438,
                           (sVar1 + 1) * 2);
      if (iVar2 != 0) {
        iVar2 = FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_Driver_401ef294,1,(LPBYTE)awStack_230,0x208
                            );
        if (iVar2 != 0) {
          iVar2 = lstrcmpiW(local_478,(LPCWSTR)PTR_u_NET0__401ef290);
          pwVar6 = aWStack_438;
          if (iVar2 != 0) {
            pwVar6 = local_478;
          }
          puVar5 = FUN_401e89f4(awStack_230,param_2,pwVar6);
          *(undefined1 **)(DAT_401ef418 + 0xc) = puVar5;
          iVar2 = FUN_401edbf0(DAT_401ef414,(LPCWSTR)PTR_u_DEVMODE_401ef2a4,3,(BYTE *)param_2,0xc0);
          if (iVar2 != 0) {
            uVar7 = 1;
            goto LAB_401e9a30;
          }
        }
      }
    }
  }
  FUN_401e8100((LPVOID)0x100);
LAB_401e9a30:
  FUN_401ee698(local_28);
  return uVar7;
}



/* 401e9a60 FUN_401e9a60 */

/* Boundary evidence: original MIPS .pdata 401e9a60..401e9d97. Semantic name remains unreviewed. */

undefined4 FUN_401e9a60(HWND param_1,HKEY param_2)

{
  int iVar1;
  HWND pHVar2;
  HRESULT HVar3;
  WPARAM wParam;
  WCHAR *lParam;
  uint uVar4;
  WCHAR local_230 [260];
  uint local_28;
  
  local_28 = DAT_401ef2a8;
  iVar1 = FUN_401ede94(DAT_401ef414,param_2);
  if (iVar1 == 0) {
    FUN_401e8100((LPVOID)0x100);
    FUN_401ee698(local_28);
    return 0;
  }
  iVar1 = FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_High_Quality_401ef298,0,(LPBYTE)0x0,0);
  if (iVar1 == 0) {
    pHVar2 = GetDlgItem(param_1,0x3eb);
    EnableWindow(pHVar2,0);
    SendDlgItemMessageW(param_1,0x3eb,0xf1,1,0);
  }
  else {
    iVar1 = FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_Draft_Quality_401ef29c,0,(LPBYTE)0x0,0);
    if (iVar1 == 0) {
      pHVar2 = GetDlgItem(param_1,0x3eb);
      EnableWindow(pHVar2,0);
      SendDlgItemMessageW(param_1,0x3eb,0xf1,0,0);
    }
    else {
      pHVar2 = GetDlgItem(param_1,0x3eb);
      EnableWindow(pHVar2,1);
    }
  }
  local_230[0] = L'\0';
  iVar1 = FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_Color_401ef2a0,1,(LPBYTE)local_230,0x208);
  if ((iVar1 == 0) || (iVar1 = lstrcmpiW(local_230,(LPCWSTR)PTR_u_Color_401ef2a0), iVar1 != 0)) {
    pHVar2 = GetDlgItem(param_1,0x3f4);
    EnableWindow(pHVar2,0);
    SendDlgItemMessageW(param_1,0x3f4,0xf1,0,0);
  }
  else {
    pHVar2 = GetDlgItem(param_1,0x3f4);
    EnableWindow(pHVar2,1);
  }
  local_230[0] = L'\0';
  if (*(int *)(DAT_401ef418 + 0xc) == 0) {
    FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_Port_401ef288,1,(LPBYTE)local_230,0x208);
  }
  else {
    iVar1 = *(int *)(DAT_401ef418 + 0xc);
    uVar4 = (uint)*(ushort *)(iVar1 + 4);
    if ((uVar4 != 0) &&
       (HVar3 = StringCchCopyW(local_230,0x104,(STRSAFE_LPCWSTR)(uVar4 + iVar1)), HVar3 < 0)) {
      local_230[0] = L'\0';
    }
  }
  if (local_230[0] != L'\0') {
    iVar1 = lstrcmpiW(local_230,(LPCWSTR)PTR_u_NET0__401ef290);
    if (iVar1 == 0) {
      lParam = (WCHAR *)&DAT_401ef41c;
    }
    else {
      lParam = local_230;
    }
    wParam = SendDlgItemMessageW(param_1,0x3e9,0x158,0xffffffff,(LPARAM)lParam);
    if (wParam != 0xffffffff) goto LAB_401e9d00;
  }
  wParam = 0;
LAB_401e9d00:
  SendDlgItemMessageW(param_1,0x3e9,0x14e,wParam,0);
  pHVar2 = GetDlgItem(param_1,0x3e9);
  FUN_401e8c18(param_1,pHVar2);
  local_230[0] = L'\0';
  FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_NetPath_401ef284,1,(LPBYTE)local_230,0x208);
  SetDlgItemTextW(param_1,0x3f6,local_230);
  FUN_401e93e4(param_1);
  FUN_401ee698(local_28);
  return 1;
}



/* 401e9d98 FUN_401e9d98 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 401e9d98..401ea18b. Semantic name remains unreviewed. */

void FUN_401e9d98(HWND param_1)

{
  int iVar1;
  size_t sVar2;
  HWND pHVar3;
  UINT uID;
  uint uVar4;
  uint *puVar5;
  WCHAR local_70 [4];
  WCHAR aWStack_68 [32];
  uint local_28;
  
  local_28 = DAT_401ef2a8;
  local_70[0] = L'\0';
  memset(local_70 + 1,0,2);
  if (((*(uint *)(DAT_401ef418 + 0x10) & 4) == 0) && ((*(uint *)(DAT_401ef418 + 0x10) & 8) == 0)) {
    GetLocaleInfoW(0x400,0xd,local_70,2);
    local_70[1] = 0;
    if (local_70[0] == L'1') {
      *(uint *)(DAT_401ef418 + 0x10) = *(uint *)(DAT_401ef418 + 0x10) | 4;
    }
    else {
      *(uint *)(DAT_401ef418 + 0x10) = *(uint *)(DAT_401ef418 + 0x10) | 8;
    }
  }
  iVar1 = DAT_401ef418;
  puVar5 = (uint *)(DAT_401ef418 + 0x10);
  uVar4 = *puVar5;
  if ((uVar4 & 2) == 0) {
    if ((uVar4 & 4) == 0) {
      DAT_401ef404 = 0x9ec;
      DAT_401ef408 = DAT_401ef404;
      DAT_401ef40c = DAT_401ef404;
      DAT_401ef410 = DAT_401ef404;
    }
    else {
      DAT_401ef404 = 1000;
      DAT_401ef408 = DAT_401ef404;
      DAT_401ef40c = DAT_401ef404;
      DAT_401ef410 = DAT_401ef404;
    }
  }
  else {
    memcpy(&DAT_401ef404,(void *)(DAT_401ef418 + 0x2c),0x10);
  }
  if ((*puVar5 & 1) != 0) {
    if (DAT_401ef408 < *(int *)(iVar1 + 0x20)) {
      DAT_401ef408 = *(int *)(iVar1 + 0x20);
    }
    if (DAT_401ef410 < *(int *)(iVar1 + 0x28)) {
      DAT_401ef410 = *(int *)(iVar1 + 0x28);
    }
    if (DAT_401ef404 < *(int *)(iVar1 + 0x1c)) {
      DAT_401ef404 = *(int *)(iVar1 + 0x1c);
    }
    if (DAT_401ef40c < *(int *)(iVar1 + 0x24)) {
      DAT_401ef40c = *(int *)(iVar1 + 0x24);
    }
  }
  GetLocaleInfoW(0x400,0xe,local_70,2);
  DAT_401ef3f4 = local_70[0];
  local_70[1] = 0;
  if ((*(uint *)(DAT_401ef418 + 0x10) & 4) == 0) {
    LoadStringW(DAT_401ef478,7,aWStack_68,0x20);
    uID = 9;
  }
  else {
    LoadStringW(DAT_401ef478,8,aWStack_68,0x20);
    uID = 10;
  }
  LoadStringW(DAT_401ef478,uID,&DAT_401ef3f8,5);
  sVar2 = wcslen(&DAT_401ef3f8);
  SetDlgItemTextW(param_1,0x3f5,aWStack_68);
  pHVar3 = GetDlgItem(param_1,0x3f0);
  if (pHVar3 != (HWND)0x0) {
    SendMessageW(pHVar3,0xc5,sVar2 + 5,0);
    DAT_401ef460 = SetWindowLongW(pHVar3,-4,0x401e8cc4);
    FUN_401e8e40(pHVar3,0,DAT_401ef404);
  }
  pHVar3 = GetDlgItem(param_1,0x3f2);
  if (pHVar3 != (HWND)0x0) {
    SendMessageW(pHVar3,0xc5,sVar2 + 5,0);
    SetWindowLongW(pHVar3,-4,0x401e8cc4);
    FUN_401e8e40(pHVar3,0,DAT_401ef40c);
  }
  pHVar3 = GetDlgItem(param_1,0x3f1);
  if (pHVar3 != (HWND)0x0) {
    SendMessageW(pHVar3,0xc5,sVar2 + 5,0);
    SetWindowLongW(pHVar3,-4,0x401e8cc4);
    FUN_401e8e40(pHVar3,0,DAT_401ef408);
  }
  pHVar3 = GetDlgItem(param_1,0x3f3);
  if (pHVar3 != (HWND)0x0) {
    SendMessageW(pHVar3,0xc5,sVar2 + 5,0);
    SetWindowLongW(pHVar3,-4,0x401e8cc4);
    FUN_401e8e40(pHVar3,0,DAT_401ef410);
  }
  FUN_401ee698(local_28);
  return;
}



/* 401ea18c FUN_401ea18c */

/* Boundary evidence: original MIPS .pdata 401ea18c..401ea20b. Semantic name remains unreviewed. */

void FUN_401ea18c(int param_1,int *param_2,uint param_3,HWND param_4)

{
  if (DAT_401ef45c == 0) {
    if (param_3 >> 0x10 == 0x200) {
      DAT_401ef45c = 1;
      FUN_401e8e40(param_4,param_1,*param_2);
      DAT_401ef45c = 0;
    }
    else if (param_3 >> 0x10 == 0x300) {
      FUN_401e905c(param_4,param_1,param_2);
    }
  }
  return;
}



/* 401ea20c FUN_401ea20c */

/* Boundary evidence: original MIPS .pdata 401ea20c..401ea2d3. Semantic name remains unreviewed. */

void FUN_401ea20c(int param_1,HWND param_2)

{
  wchar_t *pwVar1;
  int *piVar2;
  wchar_t wVar3;
  HLOCAL hMem;
  
  wVar3 = L'\0';
  if (DAT_401ef470 != (code *)0x0) {
    piVar2 = (int *)(param_1 + 8);
    pwVar1 = (wchar_t *)*piVar2;
    if (pwVar1 != (wchar_t *)0x0) {
      wVar3 = pwVar1[0x23];
    }
    FUN_401e8794(param_2,pwVar1);
    if ((*piVar2 != 0) && (wVar3 != L'\0')) {
      *(wchar_t *)(*piVar2 + 0x46) = wVar3;
    }
    hMem = (HLOCAL)*piVar2;
    (*DAT_401ef470)(param_1,param_2);
    if ((HLOCAL)*piVar2 != hMem) {
      LocalFree(hMem);
    }
    FUN_401e9670(param_2);
  }
  return;
}



/* 401ea2d4 FUN_401ea2d4 */

/* Boundary evidence: original MIPS .pdata 401ea2d4..401ea923. Semantic name remains unreviewed. */

undefined4 FUN_401ea2d4(HWND param_1)

{
  HWND pHVar1;
  uint uVar2;
  int iVar3;
  LSTATUS LVar4;
  int iVar5;
  LONG dwNewLong;
  LPVOID pvVar6;
  uint *lParam;
  uint uVar7;
  DWORD dwIndex;
  HKEY local_80;
  DWORD local_7c;
  DWORD local_78 [2];
  uint local_70;
  undefined4 local_6c;
  HWND local_68;
  HWND local_64;
  undefined4 local_4c;
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_401ef2a8;
  pHVar1 = GetDlgItem(param_1,0x3f7);
  EnableWindow(pHVar1,0);
  uVar2 = FUN_401ed9d8((int)DAT_401ef414);
  pHVar1 = GetDlgItem(param_1,1000);
  uVar7 = 0;
  if (uVar2 != 0) {
    do {
      iVar3 = FUN_401ed9a4((int)DAT_401ef414,uVar7);
      SendMessageW(pHVar1,0x143,0,iVar3);
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar2);
  }
  local_80 = (HKEY)0x0;
  pHVar1 = GetDlgItem(param_1,0x3e9);
  LoadStringW(DAT_401ef478,0xe,(LPWSTR)&DAT_401ef41c,0x20);
  LVar4 = RegOpenKeyExW((HKEY)0x80000002,(LPCWSTR)PTR_u_Printers_Ports_401ef27c,0,0,&local_80);
  if (LVar4 == 0) {
    iVar3 = 0;
    dwIndex = 0;
    local_7c = 0x20;
    iVar5 = RegEnumValueW(local_80,0,(LPWSTR)&local_70,&local_7c,(LPDWORD)0x0,(LPDWORD)0x0,
                          (LPBYTE)0x0,local_78);
    while (iVar5 == 0) {
      local_7c = 0x40;
      LVar4 = RegQueryValueExW(local_80,(LPCWSTR)&local_70,(LPDWORD)0x0,local_78,(LPBYTE)&local_70,
                               &local_7c);
      if ((LVar4 != 0) || (local_78[0] != 1)) {
        RegCloseKey(local_80);
        pvVar6 = (LPVOID)0x100;
        goto LAB_401ea3f0;
      }
      if ((WCHAR)local_70 != L'\0') {
        iVar3 = iVar3 + 1;
        iVar5 = lstrcmpiW((LPCWSTR)&local_70,(LPCWSTR)PTR_u_NET0__401ef290);
        lParam = (uint *)&DAT_401ef41c;
        if (iVar5 != 0) {
          lParam = &local_70;
        }
        SendMessageW(pHVar1,0x143,0,(LPARAM)lParam);
      }
      local_7c = 0x20;
      dwIndex = dwIndex + 1;
      iVar5 = RegEnumValueW(local_80,dwIndex,(LPWSTR)&local_70,&local_7c,(LPDWORD)0x0,(LPDWORD)0x0,
                            (LPBYTE)0x0,local_78);
    }
    RegCloseKey(local_80);
    if (iVar3 != 0) {
      pHVar1 = GetDlgItem(param_1,0x3ea);
      uVar2 = 0;
      do {
        LoadStringW(DAT_401ef478,*(UINT *)((int)&DAT_401e12ec + uVar2),(LPWSTR)&local_70,0x20);
        SendMessageW(pHVar1,0x143,0,(LPARAM)&local_70);
        uVar2 = uVar2 + 0x10;
      } while (uVar2 < 0x40);
      local_70 = local_70 & 0xffff0000;
      if (*(int *)(DAT_401ef418 + 0xc) == 0) {
        FUN_401edad4(DAT_401ef414);
        FUN_401edb50(DAT_401ef414,(LPCWSTR)PTR_u_DefaultPrinter_401ef280,1,(LPBYTE)&local_70,0x40);
      }
      else {
        iVar3 = *(int *)(DAT_401ef418 + 0xc);
        uVar2 = (uint)*(ushort *)(iVar3 + 2);
        if (uVar2 != 0) {
          wcsncpy((wchar_t *)&local_70,(wchar_t *)(uVar2 + iVar3),0x20);
          local_32 = 0;
        }
      }
      if (((WCHAR)local_70 == L'\0') ||
         (uVar2 = SendDlgItemMessageW(param_1,1000,0x158,0xffffffff,(LPARAM)&local_70),
         uVar2 == 0xffffffff)) {
        uVar2 = 0;
      }
      SendDlgItemMessageW(param_1,1000,0x14e,uVar2,0);
      iVar3 = FUN_401e9a60(param_1,(HKEY)(uVar2 & 0xffff));
      if (iVar3 != 0) {
        FUN_401e9d98(param_1);
        if ((*(uint *)(DAT_401ef418 + 0x10) & 0x10000000) != 0) {
          pHVar1 = GetDlgItem(param_1,0x3ec);
          EnableWindow(pHVar1,0);
          pHVar1 = GetDlgItem(param_1,0x3ed);
          EnableWindow(pHVar1,0);
        }
        if ((*(uint *)(DAT_401ef418 + 0x10) & 0x100) != 0) {
          pHVar1 = GetDlgItem(param_1,0x3ef);
          EnableWindow(pHVar1,0);
          pHVar1 = GetDlgItem(param_1,0x3ee);
          EnableWindow(pHVar1,0);
        }
        if ((*(uint *)(DAT_401ef418 + 0x10) & 0x200) != 0) {
          pHVar1 = GetDlgItem(param_1,0x3ea);
          EnableWindow(pHVar1,0);
        }
        if ((*(uint *)(DAT_401ef418 + 0x10) & 0x20) != 0) {
          pHVar1 = GetDlgItem(param_1,1000);
          EnableWindow(pHVar1,0);
        }
        if ((*(uint *)(DAT_401ef418 + 0x10) & 0x10) != 0) {
          pHVar1 = GetDlgItem(param_1,0x3f0);
          EnableWindow(pHVar1,0);
          pHVar1 = GetDlgItem(param_1,0x3f2);
          EnableWindow(pHVar1,0);
          pHVar1 = GetDlgItem(param_1,0x3f1);
          EnableWindow(pHVar1,0);
          pHVar1 = GetDlgItem(param_1,0x3f3);
          EnableWindow(pHVar1,0);
        }
        DAT_401ef468 = CreateWindowExW(8,L"tooltips_class32",(LPCWSTR)0x0,0x80000003,-0x80000000,
                                       -0x80000000,-0x80000000,-0x80000000,param_1,(HMENU)0x0,
                                       DAT_401ef478,(LPVOID)0x0);
        if (DAT_401ef468 != (HWND)0x0) {
          memset(&local_6c,0,0x28);
          local_70 = 0x2c;
          local_6c = 0x111;
          local_4c = 0xffffffff;
          local_68 = param_1;
          local_64 = GetDlgItem(param_1,1000);
          SendMessageW(DAT_401ef468,0x432,0,(LPARAM)&local_70);
          dwNewLong = SetWindowLongW(DAT_401ef468,-4,0x401e82e0);
          SetWindowLongW(DAT_401ef468,-0x15,dwNewLong);
        }
        FUN_401ee698(local_30);
        return 1;
      }
      pvVar6 = (LPVOID)0x100b;
      goto LAB_401ea3f0;
    }
  }
  pvVar6 = (LPVOID)0x1007;
LAB_401ea3f0:
  FUN_401e8100(pvVar6);
  FUN_401ee698(local_30);
  return 0;
}



/* 401ea924 FUN_401ea924 */

/* Boundary evidence: original MIPS .pdata 401ea924..401eb253. Semantic name remains unreviewed. */

int FUN_401ea924(HWND param_1,int param_2,uint param_3,HWND param_4)

{
  short sVar1;
  int iVar2;
  HWND pHVar3;
  int iVar4;
  HCURSOR pHVar5;
  HLOCAL pvVar6;
  BOOL BVar7;
  HDC hdc;
  LRESULT cchString;
  LPCWSTR lpszString;
  HMONITOR pHVar8;
  uint uVar9;
  INT_PTR IVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  tagRECT local_178;
  tagRECT local_168;
  tagWNDCLASSW local_158;
  HWND local_12c;
  undefined4 local_120;
  int local_11c;
  int local_118;
  wchar_t awStack_e8 [35];
  short local_a2;
  uint local_28;
  
  local_28 = DAT_401ef2a8;
  DAT_401ef464 = param_1;
  if (((*(uint *)(DAT_401ef418 + 0x10) & 0x2000) == 0) ||
     (iVar2 = (**(code **)(DAT_401ef418 + 0x44))(param_1,param_2,param_3,param_4), iVar2 == 0)) {
    iVar2 = 1;
    if (param_2 == 0x4e) {
      if (param_4 != (HWND)0x0) {
        if (param_4[2].unused == -0x212) {
          memset(&local_158.lpfnWndProc,0,0x30);
          local_178.left = 0;
          memset(&local_178.top,0,4);
          local_158.style = 0x34;
          SendMessageW((HWND)param_4[1].unused,0x162,0,(LPARAM)&local_158);
          hdc = GetDC(local_12c);
          if (hdc != (HDC)0x0) {
            cchString = SendMessageW(local_12c,0xe,0,0);
            if (cchString != 0) {
              uVar11 = cchString + 1;
              if (uVar11 < 0x80000000) {
                uVar9 = uVar11 * 2;
              }
              else {
                uVar9 = 0xffffffff;
              }
              lpszString = operator_new(uVar9);
              if (lpszString != (LPCWSTR)0x0) {
                SendMessageW(local_12c,0xd,uVar11,(LPARAM)lpszString);
                BVar7 = GetTextExtentExPointW
                                  (hdc,lpszString,cchString,0,(LPINT)0x0,(LPINT)0x0,
                                   (LPSIZE)&local_178);
                if ((BVar7 != 0) &&
                   (local_158.cbWndExtra - (int)local_158.lpfnWndProc <= local_178.left)) {
                  memset(param_4 + 4,0,0xa0);
                  wcsncpy((wchar_t *)(param_4 + 4),lpszString,0x4f);
                }
                operator_delete(lpszString);
              }
            }
            ReleaseDC(local_12c,hdc);
          }
        }
        else if (param_4[2].unused == -0x209) {
          pHVar3 = (HWND)param_4[1].unused;
          memset(&local_11c,0,0x30);
          local_120 = 0x34;
          SendMessageW(pHVar3,0x162,0,(LPARAM)&local_120);
          local_178.left = 0;
          memset(&local_178.top,0,0xc);
          GetWindowRect(pHVar3,&local_178);
          local_168.left = 0;
          memset(&local_168.top,0,0xc);
          GetWindowRect(DAT_401ef468,&local_168);
          iVar2 = local_168.right - local_168.left;
          pHVar8 = MonitorFromWindow(pHVar3,2);
          if (pHVar8 != (HMONITOR)0x0) {
            memset(&local_158.lpfnWndProc,0,0x24);
            local_158.style = 0x28;
            GetMonitorInfo(pHVar8,&local_158);
            local_178.left = local_11c + local_178.left;
            local_178.top = local_178.top + local_118;
            if ((int)local_158.hbrBackground < iVar2 + local_178.left) {
              local_178.left = (int)local_158.hbrBackground - iVar2;
            }
          }
          SetWindowPos(DAT_401ef468,(HWND)0x0,local_178.left,local_178.top,0,0,0x15);
          iVar2 = 1;
          SetWindowLongW(param_1,0,1);
        }
      }
    }
    else {
      if (param_2 != 0x53) {
        if (param_2 == 0x110) {
          iVar2 = FUN_401e800c();
          if ((iVar2 != 0) &&
             (BVar7 = GetClassInfoW(DAT_401ef478,L"SIPPREF",&local_158), BVar7 != 0)) {
            CreateWindowExW(0,L"SIPPREF",(LPCWSTR)0x0,0x40000000,-10,-10,5,5,param_1,(HMENU)0x0,
                            DAT_401ef478,(LPVOID)0x0);
          }
          pHVar5 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
          pHVar5 = SetCursor(pHVar5);
          if ((((*(uint *)(DAT_401ef418 + 0x10) & 0x28000) == 0) ||
              (((((((pHVar3 = GetDlgItem(param_1,1000), pHVar3 != (HWND)0x0 &&
                    (pHVar3 = GetDlgItem(param_1,0x3e9), pHVar3 != (HWND)0x0)) &&
                   (pHVar3 = GetDlgItem(param_1,0x3ea), pHVar3 != (HWND)0x0)) &&
                  ((pHVar3 = GetDlgItem(param_1,0x3eb), pHVar3 != (HWND)0x0 &&
                   (pHVar3 = GetDlgItem(param_1,0x3f4), pHVar3 != (HWND)0x0)))) &&
                 ((pHVar3 = GetDlgItem(param_1,0x3ec), pHVar3 != (HWND)0x0 &&
                  ((pHVar3 = GetDlgItem(param_1,0x3ed), pHVar3 != (HWND)0x0 &&
                   (pHVar3 = GetDlgItem(param_1,0x3ee), pHVar3 != (HWND)0x0)))))) &&
                (pHVar3 = GetDlgItem(param_1,0x3ef), pHVar3 != (HWND)0x0)) &&
               ((((pHVar3 = GetDlgItem(param_1,0x3f5), pHVar3 != (HWND)0x0 &&
                  (pHVar3 = GetDlgItem(param_1,0x3f0), pHVar3 != (HWND)0x0)) &&
                 (pHVar3 = GetDlgItem(param_1,0x3f2), pHVar3 != (HWND)0x0)) &&
                (((pHVar3 = GetDlgItem(param_1,0x3f1), pHVar3 != (HWND)0x0 &&
                  (pHVar3 = GetDlgItem(param_1,0x3f3), pHVar3 != (HWND)0x0)) &&
                 (pHVar3 = GetDlgItem(param_1,0x3f6), pHVar3 != (HWND)0x0)))))))) &&
             (iVar2 = FUN_401ea2d4(param_1), iVar2 != 0)) {
            pHVar3 = GetDlgItem(param_1,0x3f0);
            ImmAssociateContext(pHVar3,(HIMC)0x0);
            pHVar3 = GetDlgItem(param_1,0x3f2);
            ImmAssociateContext(pHVar3,(HIMC)0x0);
            pHVar3 = GetDlgItem(param_1,0x3f1);
            ImmAssociateContext(pHVar3,(HIMC)0x0);
            pHVar3 = GetDlgItem(param_1,0x3f3);
            ImmAssociateContext(pHVar3,(HIMC)0x0);
            SetCursor(pHVar5);
            FUN_401e7f58(param_1,2);
            FUN_401ee698(local_28);
            return 1;
          }
          SetCursor(pHVar5);
          EndDialog(param_1,-1);
          FUN_401e8100((LPVOID)0xffff);
        }
        else if (param_2 == 0x111) {
          uVar11 = param_3 & 0xffff;
          if (uVar11 < 0x3f1) {
            if (uVar11 != 0x3f0) {
              if (uVar11 == 1) {
                iVar4 = FUN_401e84c0(param_1);
                if (iVar4 != 0) {
                  pHVar5 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
                  pHVar5 = SetCursor(pHVar5);
                  DAT_401ef45c = 1;
                  FUN_401e8794(param_1,awStack_e8);
                  piVar13 = (int *)(DAT_401ef418 + 8);
                  if (*piVar13 == 0) {
                    pvVar6 = LocalAlloc(0x40,0xc0);
                    *(HLOCAL *)(DAT_401ef418 + 8) = pvVar6;
                    piVar13 = (int *)(DAT_401ef418 + 8);
                    if (*piVar13 == 0) {
                      FUN_401e8100((LPVOID)0x9);
                      SetCursor(pHVar5);
                      goto LAB_401eaeb0;
                    }
                  }
                  sVar1 = *(short *)(*piVar13 + 0x46);
                  if (sVar1 != 0) {
                    local_a2 = sVar1;
                  }
                  memcpy((void *)*piVar13,awStack_e8,0xc0);
                  memcpy((void *)(DAT_401ef418 + 0x2c),&DAT_401ef404,0x10);
                  LocalFree(*(HLOCAL *)(DAT_401ef418 + 0xc));
                  *(undefined4 *)(DAT_401ef418 + 0xc) = 0;
                  iVar4 = FUN_401e9820(param_1,*(wchar_t **)(DAT_401ef418 + 8));
                  IVar10 = 1;
                  if (iVar4 == 0) {
                    IVar10 = -1;
                  }
                  EndDialog(param_1,IVar10);
                  SetCursor(pHVar5);
                }
              }
              else {
                if (uVar11 == 2) {
                  IVar10 = 2;
                }
                else {
                  if (uVar11 != 3) {
                    if (uVar11 == 1000) {
                      if (param_3 >> 0x10 == 1) {
                        pHVar3 = GetDlgItem(param_1,1000);
                        uVar11 = SendMessageW(pHVar3,0x147,0,0);
                        FUN_401e9a60(param_1,(HKEY)(uVar11 & 0xffff));
                      }
                    }
                    else if ((uVar11 == 0x3e9) && (param_3 >> 0x10 == 1)) {
                      FUN_401e8c18(param_1,param_4);
                    }
                    goto LAB_401eb224;
                  }
                  IVar10 = -1;
                }
                DAT_401ef45c = 1;
                EndDialog(param_1,IVar10);
              }
              goto LAB_401eb224;
            }
            iVar4 = *(int *)(DAT_401ef418 + 0x1c);
            piVar13 = &DAT_401ef404;
          }
          else {
            if (uVar11 == 0x3f1) {
              piVar12 = (int *)(DAT_401ef418 + 0x20);
              piVar13 = &DAT_401ef408;
            }
            else if (uVar11 == 0x3f2) {
              piVar12 = (int *)(DAT_401ef418 + 0x24);
              piVar13 = &DAT_401ef40c;
            }
            else {
              if (uVar11 != 0x3f3) {
                if (uVar11 == 0x3f7) {
                  FUN_401ea20c(DAT_401ef418,param_1);
                }
                goto LAB_401eb224;
              }
              piVar12 = (int *)(DAT_401ef418 + 0x28);
              piVar13 = &DAT_401ef410;
            }
            iVar4 = *piVar12;
          }
          FUN_401ea18c(iVar4,piVar13,param_3,param_4);
          goto LAB_401eb224;
        }
LAB_401eaeb0:
        FUN_401ee698(local_28);
        return 0;
      }
      CreateProcessW(L"peghelp",(LPWSTR)PTR_u_file_wince_htm_Print_dialog_box_401ef274,
                     (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,
                     (LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
    }
  }
LAB_401eb224:
  FUN_401ee698(local_28);
  return iVar2;
}



/* 401eb254 PageSetupDlgW */

/* Boundary evidence: original MIPS .pdata 401eb254..401eb773. Semantic name remains unreviewed. */

BOOL PageSetupDlgW(LPPAGESETUPDLGW param_1)

{
  PHKEY ppHVar1;
  undefined4 *puVar2;
  int iVar3;
  HLOCAL pvVar4;
  int iVar5;
  HRSRC hResInfo;
  LPVOID pvVar6;
  LPCWSTR lpName;
  uint uVar7;
  HGLOBAL *ppvVar8;
  HGLOBAL pvVar9;
  LPCDLGTEMPLATEW hDialogTemplate;
  HINSTANCE hModule;
  INT_PTR IVar10;
  BOOL BVar11;
  HGLOBAL pvVar12;
  WCHAR aWStack_230 [256];
  uint local_30;
  
                    /* 0xb254  4  PageSetupDlgW */
  local_30 = DAT_401ef2a8;
  BVar11 = 0;
  IVar10 = -1;
  pvVar12 = (HGLOBAL)0x0;
  FUN_401e8100((LPVOID)0x0);
  SetLastError(0);
  if (DAT_401ef464 != (HWND)0x0) {
    LoadStringW(DAT_401ef478,0x15,aWStack_230,0x100);
    MessageBoxW(DAT_401ef464,aWStack_230,(LPCWSTR)0x0,0x30);
    goto LAB_401eb738;
  }
  DAT_401ef45c = 0;
  DAT_401ef460 = 0;
  DAT_401ef418 = param_1;
  if (param_1 == (LPPAGESETUPDLGW)0x0) {
    pvVar6 = (LPVOID)0x2;
  }
  else if (param_1->lStructSize < 0x54) {
    pvVar6 = (LPVOID)0x1;
  }
  else if (((param_1->Flags & 0x2000) == 0) || (param_1->lpfnPageSetupHook != (LPPAGESETUPHOOK)0x0))
  {
    puVar2 = operator_new(0xc);
    if (puVar2 == (undefined4 *)0x0) {
      DAT_401ef414 = (PHKEY)0x0;
    }
    else {
      DAT_401ef414 = (PHKEY)FUN_401ed940(puVar2);
    }
    if (DAT_401ef414 != (PHKEY)0x0) {
      ppvVar8 = &DAT_401ef418->hDevMode;
      pvVar9 = pvVar12;
      if ((DAT_401ef418->Flags & 0x400) == 0) {
        if (*ppvVar8 == (HGLOBAL)0x0) {
LAB_401eb4b4:
          FUN_401edad4(DAT_401ef414);
          iVar3 = FUN_401edc44(DAT_401ef414);
          hModule = DAT_401ef478;
          if (iVar3 == 0) {
            pvVar6 = (LPVOID)0x1008;
          }
          else {
            if ((DAT_401ef418->Flags & 0x20000) == 0) {
              if ((DAT_401ef418->Flags & 0x8000) == 0) {
                iVar3 = GetSystemMetrics(1);
                iVar5 = GetSystemMetrics(0);
                lpName = (LPCWSTR)0x67;
                if (iVar3 <= iVar5) {
                  lpName = (LPCWSTR)0x64;
                }
LAB_401eb588:
                hResInfo = FindResourceW(hModule,lpName,(LPCWSTR)0x5);
                if (hResInfo == (HRSRC)0x0) {
                  pvVar6 = (LPVOID)0x6;
                  goto LAB_401eb5d0;
                }
                hDialogTemplate = LoadResource(hModule,hResInfo);
                goto LAB_401eb5c4;
              }
              if (DAT_401ef418->lpPageSetupTemplateName != (LPCWSTR)0x0) {
                if (DAT_401ef418->hInstance == (HINSTANCE)0x0) {
                  pvVar6 = (LPVOID)0x4;
                  goto LAB_401eb5d0;
                }
                hModule = DAT_401ef418->hInstance;
                lpName = DAT_401ef418->lpPageSetupTemplateName;
                goto LAB_401eb588;
              }
            }
            else {
              hDialogTemplate = DAT_401ef418->hPageSetupTemplate;
LAB_401eb5c4:
              if (hDialogTemplate != (LPCDLGTEMPLATEW)0x0) {
                FUN_401e7e54();
                IVar10 = DialogBoxIndirectParamW
                                   (hModule,hDialogTemplate,DAT_401ef418->hwndOwner,FUN_401ea924,
                                    (LPARAM)DAT_401ef418);
                FUN_401e7ed4();
                DAT_401ef464 = (HWND)0x0;
                if (pvVar9 == (void *)0x0) {
                  if (IVar10 != 1) {
                    LocalFree(DAT_401ef418->hDevMode);
                    DAT_401ef418->hDevMode = (HGLOBAL)0x0;
                  }
                }
                else if ((IVar10 == 1) && (*(short *)((int)DAT_401ef418->hDevMode + 0x46) == 0)) {
                  memcpy(pvVar9,DAT_401ef418->hDevMode,(uint)*(ushort *)((int)pvVar9 + 0x44));
                  LocalFree(DAT_401ef418->hDevMode);
                  DAT_401ef418->hDevMode = pvVar9;
                }
                if (DAT_401ef46c != 0) {
                  FreeLibrary((HMODULE)DAT_401ef46c);
                }
                BVar11 = 1;
                if (IVar10 != 1) {
                  BVar11 = 0;
                }
                goto LAB_401eb6d8;
              }
            }
            pvVar6 = (LPVOID)0x3;
          }
        }
        else {
          pvVar9 = *ppvVar8;
          uVar7 = (uint)*(ushort *)((int)pvVar9 + 0x44);
          if (uVar7 < 0xc0) {
            pvVar6 = (LPVOID)0x1;
            pvVar9 = pvVar12;
          }
          else {
            pvVar4 = LocalAlloc(0,*(ushort *)((int)pvVar9 + 0x46) + uVar7);
            DAT_401ef418->hDevMode = pvVar4;
            if (DAT_401ef418->hDevMode != (HGLOBAL)0x0) {
              memcpy(DAT_401ef418->hDevMode,pvVar9,*(ushort *)((int)pvVar9 + 0x46) + uVar7);
              goto LAB_401eb4b4;
            }
            pvVar6 = (LPVOID)0x9;
          }
        }
LAB_401eb5d0:
        FUN_401e8100(pvVar6);
      }
      else {
        if (((*ppvVar8 != (HGLOBAL)0x0) || (DAT_401ef418->hDevNames != (HGLOBAL)0x0)) ||
           (iVar3 = FUN_401e9230(), iVar3 == 0)) {
          pvVar6 = (LPVOID)0x1003;
          goto LAB_401eb5d0;
        }
        BVar11 = 1;
      }
LAB_401eb6d8:
      ppHVar1 = DAT_401ef414;
      if (DAT_401ef414 != (PHKEY)0x0) {
        FUN_401ed954(DAT_401ef414);
        operator_delete(ppHVar1);
      }
      DAT_401ef414 = (PHKEY)0x0;
      if ((pvVar9 != (HGLOBAL)0x0) && (IVar10 != 1)) {
        if (DAT_401ef418->hDevMode != (HGLOBAL)0x0) {
          LocalFree(DAT_401ef418->hDevMode);
        }
        DAT_401ef418->hDevMode = pvVar9;
      }
      goto LAB_401eb738;
    }
    pvVar6 = (LPVOID)0x9;
    DAT_401ef414 = (PHKEY)0x0;
  }
  else {
    pvVar6 = (LPVOID)0xb;
  }
  FUN_401e8100(pvVar6);
LAB_401eb738:
  FUN_401ee698(local_30);
  return BVar11;
}



/* 401eb774 PrintDlg */

/* Boundary evidence: original MIPS .pdata 401eb774..401ebd9b. Semantic name remains unreviewed. */

BOOL PrintDlg(int *param_1)

{
  short sVar1;
  undefined1 *puVar2;
  HDC pHVar3;
  LPVOID pvVar4;
  LPCWSTR pwszDriver;
  LPCWSTR pwszDevice;
  LPCWSTR pszPort;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  DEVMODEW *hMem;
  ushort *puVar9;
  uint uVar10;
  int *_Src;
  BOOL BVar11;
  uint uVar12;
  uint local_e8 [26];
  tagPSDW local_80;
  
                    /* 0xb774  5  PrintDlg */
  local_e8[1] = 0x200;
  local_e8[2] = 0x200;
  local_e8[3] = 0x10000000;
  local_e8[5] = 0x10;
  local_e8[6] = 0x800;
  local_e8[0xc] = 0x8000;
  local_e8[0xd] = 0x8000;
  uVar10 = 0x100;
  local_e8[0xe] = 0x10000;
  local_e8[0x10] = 0x100000;
  local_e8[0x11] = 2;
  local_e8[4] = 0x400;
  local_e8[9] = 0x400;
  local_e8[10] = 0x4000;
  local_e8[0x12] = 0x800000;
  local_e8[0xf] = 0x20000;
  local_e8[0x16] = 0x400000;
  uVar12 = 0x200000;
  hMem = (DEVMODEW *)0x0;
  BVar11 = 0;
  local_e8[0] = 0x100;
  local_e8[7] = 0x100;
  local_e8[8] = 0x2000;
  local_e8[0xb] = 0x2000;
  local_e8[0x13] = 1;
  local_e8[0x14] = 0x200000;
  local_e8[0x15] = 4;
  local_e8[0x17] = 8;
  local_e8[0x18] = 0;
  local_e8[0x19] = 0;
  FUN_401e8100((LPVOID)0x0);
  if (param_1 == (int *)0x0) {
    pvVar4 = (LPVOID)0x2;
LAB_401eb894:
    FUN_401e8100(pvVar4);
    return 0;
  }
  if (*param_1 != 0x44) {
    pvVar4 = (LPVOID)0x1;
    goto LAB_401eb894;
  }
  memset(&local_80,0,0x54);
  local_80.hwndOwner = (HWND)param_1[1];
  _Src = param_1 + 8;
  puVar2 = (undefined1 *)((int)&local_80.hwndOwner + 3);
  uVar6 = (uint)puVar2 & 3;
  puVar8 = (uint *)(puVar2 + -uVar6);
  *puVar8 = *puVar8 & -1 << (uVar6 + 1) * 8 | (uint)local_80.hwndOwner >> (3 - uVar6) * 8;
  local_80.lStructSize = 0x54;
  memcpy(&local_80.rtMargin,_Src,0x10);
  memcpy(&local_80.rtMinMargin,param_1 + 4,0x10);
  local_80.hInstance = (HINSTANCE)param_1[0xc];
  local_80.lCustData = param_1[0xd];
  puVar8 = (uint *)(param_1 + 3);
  local_80.lpPageSetupTemplateName = (LPCWSTR)param_1[0xf];
  local_80.lpfnPageSetupHook = (LPPAGESETUPHOOK)param_1[0xe];
  iVar7 = 0;
  iVar5 = 0;
  local_80.hPageSetupTemplate = (HGLOBAL)param_1[0x10];
  do {
    if ((*puVar8 & uVar10) != 0) {
      local_80.Flags = *(uint *)((int)local_e8 + iVar5 + 4) | local_80.Flags;
    }
    iVar7 = iVar7 + 1;
    iVar5 = iVar7 * 8;
    uVar10 = local_e8[iVar7 * 2];
  } while (uVar10 != 0);
  puVar9 = (ushort *)0x0;
  if ((local_80.Flags & 0x400) == 0) {
    hMem = LocalAlloc(0x40,0xc0);
    if (hMem == (DEVMODEW *)0x0) {
      FUN_401e8100((LPVOID)0x9);
      goto LAB_401ebd48;
    }
    hMem->dmSize = 0xc0;
    local_80.hDevMode = hMem;
    if (((*puVar8 & 0x40000) != 0) || ((*puVar8 & 0x80000) != 0)) {
      uVar10 = hMem->dmFields;
      (hMem->field6_0x4c).field0.dmOrientation = 1;
      hMem->dmFields = uVar10 | 1;
    }
  }
  BVar11 = PageSetupDlgW(&local_80);
  if (BVar11 == 0) goto LAB_401ebd48;
  uVar10 = *puVar8;
  *puVar8 = uVar10 & 0xfffffffc;
  if ((local_80.Flags & 0x20000000) == 0) {
    uVar6 = 1;
  }
  else {
    uVar6 = 2;
  }
  *puVar8 = uVar10 & 0xff9ffffc | uVar6;
  if ((local_80.Flags & 4) == 0) {
    uVar12 = 0x400000;
  }
  uVar12 = uVar10 & 0xff8ffffc | uVar6 | uVar12;
  *puVar8 = uVar12;
  if ((((param_1[9] != local_80.rtMargin.top) || (param_1[0xb] != local_80.rtMargin.bottom)) ||
      (*_Src != local_80.rtMargin.left)) || (param_1[10] != local_80.rtMargin.right)) {
    *puVar8 = uVar12 | 0x100000;
    memcpy(_Src,&local_80.rtMargin,0x10);
  }
  hMem = local_80.hDevMode;
  if ((((_union_660 *)((int)local_80.hDevMode + 0x4c))->field0).dmPrintQuality == -1) {
    uVar12 = *puVar8 | 8;
  }
  else {
    uVar12 = *puVar8 & 0xfffffff7;
  }
  *puVar8 = uVar12;
  uVar12 = *puVar8 & 0xfff3ffff;
  *puVar8 = uVar12;
  if ((((_union_660 *)((int)local_80.hDevMode + 0x4c))->field0).dmOrientation == 1) {
    *puVar8 = uVar12 | 0x40000;
  }
  else {
    *puVar8 = uVar12 | 0x80000;
  }
  if (*(short *)((int)local_80.hDevMode + 0x5c) == 2) {
    *puVar8 = *puVar8 | 0x10000000;
  }
  else {
    *puVar8 = *puVar8 & 0xefffffff;
  }
  uVar12 = *puVar8 & 0xf3ffffcf;
  *puVar8 = uVar12;
  sVar1 = (((_union_660 *)((int)local_80.hDevMode + 0x4c))->field0).dmPaperSize;
  if (sVar1 == 1) {
    uVar12 = uVar12 | 0x20;
LAB_401ebc9c:
    *puVar8 = uVar12;
  }
  else if (sVar1 == 5) {
    uVar12 = uVar12 | 0x4000000;
LAB_401ebc8c:
    *puVar8 = uVar12;
  }
  else {
    if (sVar1 == 9) {
      uVar12 = uVar12 | 0x10;
      goto LAB_401ebc9c;
    }
    if (sVar1 == 0xd) {
      uVar12 = uVar12 | 0x8000000;
      goto LAB_401ebc8c;
    }
  }
  pszPort = (LPCWSTR)0x0;
  pwszDriver = (LPCWSTR)0x0;
  pwszDevice = (LPCWSTR)0x0;
  if (*(ushort *)((int)local_80.hDevNames + 4) != 0) {
    pszPort = (LPCWSTR)((uint)*(ushort *)((int)local_80.hDevNames + 4) + (int)local_80.hDevNames);
  }
  if (*(ushort *)((int)local_80.hDevNames + 2) != 0) {
    pwszDevice = (LPCWSTR)((uint)*(ushort *)((int)local_80.hDevNames + 2) + (int)local_80.hDevNames)
    ;
  }
  if (*(ushort *)local_80.hDevNames != 0) {
    pwszDriver = (LPCWSTR)((uint)*(ushort *)local_80.hDevNames + (int)local_80.hDevNames);
  }
  *puVar8 = *puVar8 & 0xfcffff3f;
  pHVar3 = CreateDCW(pwszDriver,pwszDevice,pszPort,local_80.hDevMode);
  param_1[2] = (int)pHVar3;
  puVar9 = local_80.hDevNames;
  if (pHVar3 == (HDC)0x0) {
    FUN_401e8100((LPVOID)0x100a);
    BVar11 = 0;
  }
LAB_401ebd48:
  if (hMem != (DEVMODEW *)0x0) {
    LocalFree(hMem);
  }
  if (puVar9 == (ushort *)0x0) {
    return BVar11;
  }
  LocalFree(puVar9);
  return BVar11;
}



/* 401ebd9c FUN_401ebd9c */

/* Boundary evidence: original MIPS .pdata 401ebd9c..401ebe7b. Semantic name remains unreviewed. */

void FUN_401ebd9c(HDC param_1,int param_2,int param_3)

{
  HBRUSH h;
  HGDIOBJ h_00;
  int iVar1;
  int h_01;
  int x;
  
  h = GetSysColorBrush(0x40000012);
  h_00 = SelectObject(param_1,h);
  x = *(int *)(param_3 + 0x54) + 2;
  h_01 = 1;
  if (x < *(int *)(param_3 + 0x5c) + -5) {
    do {
      iVar1 = h_01;
      if (h_01 < 0) {
        iVar1 = h_01 + 1;
      }
      PatBlt(param_1,x,param_2 - (iVar1 >> 1),1,h_01,0xf00021);
      x = x + 1;
      h_01 = h_01 + 2;
    } while (x < *(int *)(param_3 + 0x5c) + -5);
  }
  SelectObject(param_1,h_00);
  return;
}



/* 401ebe7c FUN_401ebe7c */

/* Boundary evidence: original MIPS .pdata 401ebe7c..401ebf03. Semantic name remains unreviewed. */

void FUN_401ebe7c(HDC param_1,int param_2)

{
  HBRUSH hbr;
  int iVar1;
  RECT local_20;
  
  hbr = (HBRUSH)SendMessageW(*(HWND *)(param_2 + 0xc),0x136,(WPARAM)param_1,
                             (LPARAM)*(HWND *)(param_2 + 0xc));
  iVar1 = *(int *)(param_2 + 0x54);
  local_20.left = iVar1 + 1;
  local_20.right = *(int *)(param_2 + 0x5c);
  local_20.top = ((uint)*(ushort *)(param_2 + 0x32) - local_20.right) + iVar1;
  local_20.bottom = ((uint)*(ushort *)(param_2 + 0x32) - iVar1) + local_20.right + 1;
  FillRect(param_1,&local_20,hbr);
  return;
}



/* 401ebf04 FUN_401ebf04 */

/* Boundary evidence: original MIPS .pdata 401ebf04..401ec0b7. Semantic name remains unreviewed. */

void FUN_401ebf04(HDC param_1,int param_2)

{
  HGDIOBJ h;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  tagRECT local_30;
  
  CopyRect(&local_30,(RECT *)(param_2 + 0x44));
  uVar5 = DAT_401ef49e * 10 & 0xffff;
  uVar1 = DAT_401ef48a * 10 & 0xffff;
  uVar2 = *(ushort *)(param_2 + 0x30) - uVar1;
  uVar4 = (uint)(ushort)local_30.top;
  if ((int)(uint)(ushort)local_30.top <= (int)uVar2) {
    uVar4 = uVar2;
  }
  uVar4 = uVar4 & 0xffff;
  uVar1 = uVar1 + *(ushort *)(param_2 + 0x30);
  uVar2 = (uint)(ushort)local_30.bottom;
  if (uVar1 <= (ushort)local_30.bottom) {
    uVar2 = uVar1;
  }
  uVar3 = *(ushort *)(param_2 + 0x2e) - uVar5;
  uVar1 = (uint)(ushort)local_30.left;
  if ((int)(uint)(ushort)local_30.left <= (int)uVar3) {
    uVar1 = uVar3;
  }
  uVar5 = uVar5 + *(ushort *)(param_2 + 0x2e);
  uVar1 = uVar1 & 0xffff;
  uVar3 = (uint)(ushort)local_30.right;
  if (uVar5 <= (ushort)local_30.right) {
    uVar3 = uVar5;
  }
  if (DAT_401ef4a8 != (HDC)0x0) {
    h = SelectObject(DAT_401ef4a8,DAT_401ef4ac);
    BitBlt(param_1,uVar1,uVar4,(uVar3 & 0xffff) - uVar1,(uVar2 & 0xffff) - uVar4,DAT_401ef4a8,
           uVar1 - (ushort)local_30.left,uVar4 - (ushort)local_30.top,0xcc0020);
    SelectObject(DAT_401ef4a8,h);
  }
  return;
}



/* 401ec0b8 FUN_401ec0b8 */

/* Boundary evidence: original MIPS .pdata 401ec0b8..401ec51f. Semantic name remains unreviewed. */

void FUN_401ec0b8(HDC param_1,int param_2,int param_3,int param_4)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  POINT local_48;
  int local_40;
  int local_3c;
  tagRECT local_38;
  
  CopyRect(&local_38,(RECT *)(param_4 + 0x44));
  iVar2 = (int)(short)(DAT_401ef48a * 5);
  iVar3 = param_3 + iVar2 * -2;
  iVar5 = (int)(short)(DAT_401ef49e * 5);
  LVar1 = local_38.top;
  if (local_38.top <= iVar3) {
    LVar1 = iVar3;
  }
  iVar3 = param_3 + iVar2 * 2;
  iVar7 = (int)(short)LVar1;
  LVar1 = local_38.bottom;
  if (iVar3 <= local_38.bottom) {
    LVar1 = iVar3;
  }
  iVar3 = param_2 + iVar5 * -2;
  iVar8 = (int)(short)LVar1;
  if (iVar3 < local_38.left) {
    iVar3 = local_38.left;
  }
  iVar4 = param_2 + iVar5 * 2;
  iVar3 = (int)(short)iVar3;
  LVar1 = local_38.right;
  if (iVar4 <= local_38.right) {
    LVar1 = iVar4;
  }
  iVar4 = (int)(short)LVar1;
  LVar1 = local_38.top;
  if (local_38.top <= param_3 - iVar2) {
    LVar1 = param_3 - iVar2;
  }
  iVar6 = (int)(short)LVar1;
  LVar1 = local_38.bottom;
  if (param_3 + iVar2 <= local_38.bottom) {
    LVar1 = param_3 + iVar2;
  }
  iVar9 = (int)(short)LVar1;
  iVar2 = param_2 - iVar5;
  if (param_2 - iVar5 < local_38.left) {
    iVar2 = local_38.left;
  }
  LVar1 = local_38.right;
  if (param_2 + iVar5 <= local_38.right) {
    LVar1 = param_2 + iVar5;
  }
  if (local_38.top < iVar6) {
    local_48.x = param_2 + -1;
    if (local_38.left <= local_48.x) {
      local_48.y = iVar6;
      local_40 = local_48.x;
      local_3c = iVar7;
      Polyline(param_1,&local_48,2);
    }
    if (param_2 < local_38.right) {
      local_48.x = param_2;
      local_48.y = iVar6;
      local_40 = param_2;
      local_3c = iVar7;
      Polyline(param_1,&local_48,2);
    }
    local_48.x = param_2 + 1;
    if (local_48.x < local_38.right) {
      local_48.y = iVar6;
      local_40 = local_48.x;
      local_3c = iVar7;
      Polyline(param_1,&local_48,2);
    }
  }
  if (iVar9 < local_38.bottom) {
    local_48.x = param_2 + -1;
    if (local_38.left <= local_48.x) {
      local_48.y = iVar9;
      local_40 = local_48.x;
      local_3c = iVar8;
      Polyline(param_1,&local_48,2);
    }
    if (param_2 < local_38.right) {
      local_48.x = param_2;
      local_48.y = iVar9;
      local_40 = param_2;
      local_3c = iVar8;
      Polyline(param_1,&local_48,2);
    }
    local_48.x = param_2 + 1;
    if (local_48.x < local_38.right) {
      local_48.y = iVar9;
      local_40 = local_48.x;
      local_3c = iVar8;
      Polyline(param_1,&local_48,2);
    }
  }
  iVar2 = (int)(short)iVar2;
  if (local_38.left < iVar2) {
    local_48.y = param_3 + -1;
    if (local_38.top <= local_48.y) {
      local_48.x = iVar2;
      local_40 = iVar3;
      local_3c = local_48.y;
      Polyline(param_1,&local_48,2);
    }
    if (param_3 < local_38.bottom) {
      local_48.x = iVar2;
      local_48.y = param_3;
      local_40 = iVar3;
      local_3c = param_3;
      Polyline(param_1,&local_48,2);
    }
    local_48.y = param_3 + 1;
    if (local_48.y < local_38.bottom) {
      local_48.x = iVar2;
      local_40 = iVar3;
      local_3c = local_48.y;
      Polyline(param_1,&local_48,2);
    }
  }
  iVar2 = (int)(short)LVar1;
  if (iVar2 < local_38.right) {
    local_48.y = param_3 + -1;
    if (local_38.top <= local_48.y) {
      local_48.x = iVar2;
      local_40 = iVar4;
      local_3c = local_48.y;
      Polyline(param_1,&local_48,2);
    }
    if (param_3 < local_38.bottom) {
      local_48.x = iVar2;
      local_48.y = param_3;
      local_40 = iVar4;
      local_3c = param_3;
      Polyline(param_1,&local_48,2);
    }
    local_48.y = param_3 + 1;
    if (local_48.y < local_38.bottom) {
      local_48.x = iVar2;
      local_40 = iVar4;
      local_3c = local_48.y;
      Polyline(param_1,&local_48,2);
    }
  }
  return;
}



/* 401ec520 FUN_401ec520 */

void FUN_401ec520(int param_1,int param_2)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0x2bf) {
    iVar1 = ((uint)*(ushort *)(param_2 + 0x2e) - *(int *)(param_2 + 0x44)) * 0xef;
    iVar4 = *(ushort *)(param_2 + 0x22) - 1;
    if (iVar4 == 0) {
      trap(0x1c00);
    }
    if ((iVar4 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    *(short *)(param_2 + 0x1c) = (short)(iVar1 / iVar4);
  }
  else if (param_1 == 0x2c0) {
    iVar1 = (*(int *)(param_2 + 0x48) - (uint)*(ushort *)(param_2 + 0x30)) * 0xf0;
    iVar4 = *(ushort *)(param_2 + 0x24) - 1;
    if (iVar4 == 0) {
      trap(0x1c00);
    }
    if ((iVar4 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    *(short *)(param_2 + 0x1e) = (short)(iVar1 / iVar4) + 0xf0;
  }
  else {
    if (param_1 == 0x2c1) {
      iVar1 = (*(int *)(param_2 + 0x68) - (uint)*(ushort *)(param_2 + 0x32)) * 0xf0;
      iVar4 = *(ushort *)(param_2 + 0x26) - 1;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      sVar2 = (short)(iVar1 / iVar4);
    }
    else {
      iVar1 = ((uint)*(ushort *)(param_2 + 0x2e) - *(int *)(param_2 + 0x44)) * 0xef;
      uVar3 = (uint)*(ushort *)(param_2 + 0x22);
      if (uVar3 == 0) {
        trap(0x1c00);
      }
      if ((uVar3 == 0xffffffff) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      *(short *)(param_2 + 0x1c) = (short)(iVar1 / (int)uVar3);
      iVar1 = (*(int *)(param_2 + 0x48) - (uint)*(ushort *)(param_2 + 0x30)) * 0xf0;
      uVar3 = (uint)*(ushort *)(param_2 + 0x24);
      if (uVar3 == 0) {
        trap(0x1c00);
      }
      if ((uVar3 == 0xffffffff) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      *(short *)(param_2 + 0x1e) = (short)(iVar1 / (int)uVar3) + 0xf0;
      iVar1 = (*(int *)(param_2 + 0x68) - (uint)*(ushort *)(param_2 + 0x32)) * 0xf0;
      uVar3 = (uint)*(ushort *)(param_2 + 0x26);
      if (uVar3 == 0) {
        trap(0x1c00);
      }
      if ((uVar3 == 0xffffffff) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      sVar2 = (short)(iVar1 / (int)uVar3);
    }
    *(short *)(param_2 + 0x20) = sVar2 + 0xf0;
  }
  return;
}



/* 401ec75c FUN_401ec75c */

void FUN_401ec75c(int param_1,int param_2)

{
  if (param_1 == 0x2bf) {
    *(short *)(param_2 + 0x2e) =
         (short)((int)((uint)*(ushort *)(param_2 + 0x22) * (uint)*(ushort *)(param_2 + 0x1c)) / 0xef
                ) + (short)*(undefined4 *)(param_2 + 0x44);
  }
  else if (param_1 == 0x2c0) {
    *(short *)(param_2 + 0x30) =
         (short)((int)((0xf0 - (uint)*(ushort *)(param_2 + 0x1e)) *
                      (*(ushort *)(param_2 + 0x24) - 1)) / 0xf0) +
         (short)*(undefined4 *)(param_2 + 0x48);
  }
  else if (param_1 == 0x2c1) {
    *(short *)(param_2 + 0x32) =
         (short)((int)((0xf0 - (uint)*(ushort *)(param_2 + 0x20)) *
                      (*(ushort *)(param_2 + 0x26) - 1)) / 0xf0) +
         (short)*(undefined4 *)(param_2 + 0x68);
  }
  else {
    *(short *)(param_2 + 0x2e) =
         (short)((int)((uint)*(ushort *)(param_2 + 0x22) * (uint)*(ushort *)(param_2 + 0x1c)) / 0xef
                ) + (short)*(undefined4 *)(param_2 + 0x44);
    *(short *)(param_2 + 0x30) =
         (short)((int)((0xf0 - (uint)*(ushort *)(param_2 + 0x1e)) *
                      (*(ushort *)(param_2 + 0x24) - 1)) / 0xf0) +
         (short)*(undefined4 *)(param_2 + 0x48);
    *(short *)(param_2 + 0x32) =
         (short)((int)((0xf0 - (uint)*(ushort *)(param_2 + 0x20)) *
                      (*(ushort *)(param_2 + 0x26) - 1)) / 0xf0) +
         (short)*(undefined4 *)(param_2 + 0x68);
  }
  return;
}



/* 401ec8c8 FUN_401ec8c8 */

/* Boundary evidence: original MIPS .pdata 401ec8c8..401ec987. Semantic name remains unreviewed. */

void FUN_401ec8c8(int param_1,int param_2)

{
  ushort uVar1;
  int nIDDlgItem;
  HWND hDlg;
  
  hDlg = *(HWND *)(param_2 + 0xc);
  if (param_1 == 0x2bf) {
    uVar1 = *(ushort *)(param_2 + 0x1c);
    nIDDlgItem = 0x2bf;
  }
  else if (param_1 == 0x2c0) {
    uVar1 = *(ushort *)(param_2 + 0x1e);
    nIDDlgItem = 0x2c0;
  }
  else if (param_1 == 0x2c1) {
    uVar1 = *(ushort *)(param_2 + 0x20);
    nIDDlgItem = 0x2c1;
  }
  else {
    SetDlgItemInt(hDlg,0x2bf,(uint)*(ushort *)(param_2 + 0x1c),0);
    SetDlgItemInt(hDlg,0x2c0,(uint)*(ushort *)(param_2 + 0x1e),0);
    uVar1 = *(ushort *)(param_2 + 0x20);
    nIDDlgItem = 0x2c1;
  }
  SetDlgItemInt(hDlg,nIDDlgItem,(uint)uVar1,0);
  return;
}



/* 401ec988 FUN_401ec988 */

/* Boundary evidence: original MIPS .pdata 401ec988..401eca6b. Semantic name remains unreviewed. */

void FUN_401ec988(int param_1,int param_2)

{
  int nIDDlgItem;
  UINT uValue;
  HWND hDlg;
  uint uVar1;
  
  hDlg = *(HWND *)(param_2 + 0xc);
  uVar1 = *(uint *)(param_2 + 0x18);
  if (param_1 == 0x2c2) {
    nIDDlgItem = 0x2c2;
  }
  else {
    if (param_1 == 0x2c3) {
      uValue = (uVar1 & 0xffff) >> 8;
      nIDDlgItem = 0x2c3;
      goto LAB_401eca50;
    }
    if (param_1 == 0x2c4) {
      uValue = uVar1 >> 0x10 & 0xff;
      nIDDlgItem = 0x2c4;
      goto LAB_401eca50;
    }
    SetDlgItemInt(hDlg,0x2c2,uVar1 & 0xff,0);
    SetDlgItemInt(hDlg,0x2c3,(uVar1 & 0xffff) >> 8,0);
    uVar1 = uVar1 >> 0x10;
    nIDDlgItem = 0x2c4;
  }
  uValue = uVar1 & 0xff;
LAB_401eca50:
  SetDlgItemInt(hDlg,nIDDlgItem,uValue,0);
  return;
}



/* 401eca6c FUN_401eca6c */

/* Boundary evidence: original MIPS .pdata 401eca6c..401ecb4b. Semantic name remains unreviewed. */

void FUN_401eca6c(HDC param_1,int *param_2,int param_3)

{
  HGDIOBJ h;
  int x;
  int y;
  
  if (DAT_401ef4ac != (HGDIOBJ)0x0) {
    if (DAT_401ef4a8 != (HDC)0x0) {
      h = SelectObject(DAT_401ef4a8,DAT_401ef4ac);
      y = param_2[1];
      x = *param_2;
      BitBlt(param_1,x,y,param_2[2] - x,param_2[3] - y,DAT_401ef4a8,x - *(int *)(param_3 + 0x44),
             y - *(int *)(param_3 + 0x48),0xcc0020);
      SelectObject(DAT_401ef4a8,h);
    }
    FUN_401ec0b8(param_1,(int)*(short *)(param_3 + 0x2e),(int)*(short *)(param_3 + 0x30),param_3);
  }
  return;
}



/* 401ecb4c FUN_401ecb4c */

void FUN_401ecb4c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  uint uVar10;
  uint uVar11;
  
  uVar4 = (param_1 & 0xffff) >> 8;
  uVar1 = param_1 & 0xff;
  uVar10 = param_1 >> 0x10 & 0xff;
  uVar2 = uVar1;
  if (uVar1 <= uVar4) {
    uVar2 = uVar4;
  }
  uVar5 = uVar10;
  if ((uVar10 < uVar2) && (uVar5 = uVar4, uVar1 > uVar4)) {
    uVar5 = uVar1;
  }
  uVar2 = uVar1;
  if (uVar4 <= uVar1) {
    uVar2 = uVar4;
  }
  uVar6 = uVar10;
  if ((uVar2 < uVar10) && (uVar6 = uVar1, uVar4 <= uVar1)) {
    uVar6 = uVar4;
  }
  uVar2 = uVar5 + uVar6;
  uVar11 = (uVar2 * 0xf0 + 0xff) / 0x1fe;
  uVar6 = uVar5 - uVar6 & 0xffff;
  DAT_401ef486 = (short)uVar11;
  if (uVar6 == 0) {
    DAT_401ef484 = 0;
    DAT_401ef488 = 0xa0;
  }
  else {
    if (uVar11 < 0x79) {
      if (uVar2 == 0) {
        trap(0x1c00);
      }
      DAT_401ef484 = (undefined2)((uVar6 * 0xf0 + (uVar2 >> 1)) / uVar2);
    }
    else {
      iVar3 = -uVar2 + 0x1fe;
      if (iVar3 < 0) {
        iVar3 = -uVar2 + 0x1ff;
      }
      if (0x1fe - uVar2 == 0) {
        trap(0x1c00);
      }
      DAT_401ef484 = (undefined2)(((iVar3 >> 1) + uVar6 * 0xf0) / (0x1fe - uVar2));
    }
    uVar2 = uVar6 >> 1;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    sVar9 = (short)(((uVar5 - uVar1) * 0x28 + uVar2) / uVar6);
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    sVar8 = (short)(((uVar5 - uVar4) * 0x28 + uVar2) / uVar6);
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    sVar7 = (short)(((uVar5 - uVar10) * 0x28 + uVar2) / uVar6);
    if (uVar1 == uVar5) {
      DAT_401ef488 = sVar7 - sVar8;
    }
    else if (uVar4 == uVar5) {
      DAT_401ef488 = (sVar9 - sVar7) + 0x50;
    }
    else {
      DAT_401ef488 = (sVar8 - sVar9) + 0xa0;
    }
    if ((short)DAT_401ef488 < 0) {
      DAT_401ef488 = DAT_401ef488 + 0xf0;
    }
    if (0xef < DAT_401ef488) {
      DAT_401ef488 = DAT_401ef488 - 0xf0;
    }
  }
  return;
}



/* 401ecdd4 FUN_401ecdd4 */

uint FUN_401ecdd4(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if (0xef < param_3) {
    param_3 = param_3 + 0xff10 & 0xffff;
  }
  if (param_3 < 0x28) {
    iVar1 = (param_2 - param_1) * param_3;
  }
  else {
    if (param_3 < 0x78) {
      return param_2;
    }
    if (0x9f < param_3) {
      return param_1;
    }
    iVar1 = (param_2 - param_1) * (0xa0 - param_3);
  }
  return (iVar1 + 0x14) / 0x28 + param_1 & 0xffff;
}



/* 401ece60 FUN_401ece60 */

/* Boundary evidence: original MIPS .pdata 401ece60..401ecfff. Semantic name remains unreviewed. */

uint FUN_401ece60(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    uVar2 = (int)(param_2 * 0xff) / 0xf0 & 0xffff;
    uVar1 = uVar2;
    uVar4 = uVar2;
  }
  else {
    if (param_2 < 0x79) {
      uVar2 = ((param_3 + 0xf0) * param_2 + 0x78) / 0xf0;
    }
    else {
      uVar2 = (param_2 - (param_2 * param_3 + 0x78) / 0xf0) + param_3;
    }
    uVar2 = uVar2 & 0xffff;
    uVar3 = param_2 * 2 - uVar2 & 0xffff;
    uVar1 = FUN_401ecdd4(uVar3,uVar2,param_1 + 0x50 & 0xffff);
    uVar4 = (uVar1 * 0xff + 0x78) / 0xf0 & 0xffff;
    uVar1 = FUN_401ecdd4(uVar3,uVar2,param_1);
    uVar1 = (uVar1 * 0xff + 0x78) / 0xf0 & 0xffff;
    uVar2 = FUN_401ecdd4(uVar3,uVar2,param_1 + 0xffb0 & 0xffff);
    uVar2 = (uVar2 * 0xff + 0x78) / 0xf0 & 0xffff;
  }
  return ((uVar2 & 0xff) << 8 | uVar1 & 0xff) << 8 | uVar4 & 0xff;
}



/* 401ed000 FUN_401ed000 */

/* Boundary evidence: original MIPS .pdata 401ed000..401ed12f. Semantic name remains unreviewed. */

void FUN_401ed000(int param_1)

{
  HDC pHVar1;
  HWND hWnd;
  
  hWnd = *(HWND *)(param_1 + 0xc);
  FUN_401ecb4c(*(uint *)(param_1 + 0x18));
  if (DAT_401ef486 != *(short *)(param_1 + 0x20)) {
    pHVar1 = GetDC(hWnd);
    FUN_401ebe7c(pHVar1,param_1);
    *(short *)(param_1 + 0x20) = DAT_401ef486;
    FUN_401ec75c(0x2c1,param_1);
    FUN_401ebd9c(pHVar1,(int)*(short *)(param_1 + 0x32),param_1);
    ReleaseDC(hWnd,pHVar1);
  }
  if ((DAT_401ef488 != *(short *)(param_1 + 0x1c)) || (DAT_401ef484 != *(short *)(param_1 + 0x1e)))
  {
    *(short *)(param_1 + 0x1c) = DAT_401ef488;
    *(short *)(param_1 + 0x1e) = DAT_401ef484;
    InvalidateRect(hWnd,(RECT *)(param_1 + 100),0);
    pHVar1 = GetDC(hWnd);
    FUN_401ebf04(pHVar1,param_1);
    FUN_401ec75c(0x2bf,param_1);
    FUN_401ec75c(0x2c0,param_1);
    FUN_401ec0b8(pHVar1,(int)*(short *)(param_1 + 0x2e),(int)*(short *)(param_1 + 0x30),param_1);
    ReleaseDC(hWnd,pHVar1);
  }
  return;
}



/* 401ed130 FUN_401ed130 */

/* Boundary evidence: original MIPS .pdata 401ed130..401ed237. Semantic name remains unreviewed. */

void FUN_401ed130(int param_1)

{
  HDC hdc;
  COLORREF CVar1;
  HWND hWnd;
  
  hWnd = *(HWND *)(param_1 + 0xc);
  hdc = GetDC(hWnd);
  FUN_401ebf04(hdc,param_1);
  FUN_401ebe7c(hdc,param_1);
  CVar1 = GetNearestColor(hdc,*(COLORREF *)(param_1 + 0x18));
  *(COLORREF *)(param_1 + 0x18) = CVar1;
  FUN_401ecb4c(CVar1);
  *(undefined2 *)(param_1 + 0x1c) = DAT_401ef488;
  *(undefined2 *)(param_1 + 0x20) = DAT_401ef486;
  *(undefined2 *)(param_1 + 0x1e) = DAT_401ef484;
  FUN_401ec75c(0,param_1);
  FUN_401ec0b8(hdc,(int)*(short *)(param_1 + 0x2e),(int)*(short *)(param_1 + 0x30),param_1);
  FUN_401ebd9c(hdc,(int)*(short *)(param_1 + 0x32),param_1);
  ReleaseDC(hWnd,hdc);
  FUN_401ec8c8(0,param_1);
  FUN_401ec988(0,param_1);
  InvalidateRect(hWnd,(RECT *)(param_1 + 0x94),0);
  InvalidateRect(hWnd,(RECT *)(param_1 + 100),0);
  return;
}



/* 401ed238 FUN_401ed238 */

/* Boundary evidence: original MIPS .pdata 401ed238..401ed49b. Semantic name remains unreviewed. */

undefined4 FUN_401ed238(int param_1)

{
  HGDIOBJ h;
  uint color;
  HBRUSH hbr;
  uint uVar1;
  uint uVar2;
  HDC hdc;
  uint cx;
  uint cy;
  HWND hWnd;
  RECT local_38;
  
  hWnd = *(HWND *)(param_1 + 0xc);
  hdc = (HDC)0x0;
  FUN_401ecb4c(*(uint *)(param_1 + 0x18));
  FUN_401e1af4(param_1);
  uVar1 = *(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x44);
  uVar2 = *(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x48);
  cx = uVar1 & 0xffff;
  cy = uVar2 & 0xffff;
  *(short *)(param_1 + 0x22) = (short)uVar1;
  *(short *)(param_1 + 0x24) = (short)uVar2;
  *(undefined2 *)(param_1 + 0x1c) = DAT_401ef488;
  *(undefined2 *)(param_1 + 0x1e) = DAT_401ef484;
  *(undefined2 *)(param_1 + 0x20) = DAT_401ef486;
  FUN_401ec75c(0,param_1);
  FUN_401ec988(0,param_1);
  FUN_401ec8c8(0,param_1);
  if (DAT_401ef4ac == (HBITMAP)0x0) {
    hdc = GetDC(hWnd);
    DAT_401ef4ac = CreateCompatibleBitmap(hdc,cx,cy);
    if (DAT_401ef4ac == (HBITMAP)0x0) {
      return 0;
    }
  }
  h = SelectObject(DAT_401ef4a8,DAT_401ef4ac);
  local_38.bottom = 0;
  uVar1 = 0xf0;
  do {
    local_38.right = 0;
    uVar2 = 0;
    local_38.top = local_38.bottom;
    local_38.bottom = (int)((0xf8 - uVar1) * cy) / 0xf0;
    do {
      local_38.left = local_38.right;
      local_38.right = (int)((uVar2 + 4) * cx) / 0xf0;
      color = FUN_401ece60(uVar2,0x78,uVar1);
      hbr = CreateSolidBrush(color);
      if (hbr != (HBRUSH)0x0) {
        FillRect(DAT_401ef4a8,&local_38,hbr);
        DeleteObject(hbr);
      }
      uVar2 = uVar2 + 4 & 0xffff;
    } while (uVar2 < 0xef);
    uVar1 = uVar1 + 0xfff8 & 0xffff;
  } while (uVar1 != 0);
  SelectObject(DAT_401ef4a8,h);
  if (hdc != (HDC)0x0) {
    ReleaseDC(hWnd,hdc);
  }
  UpdateWindow(hWnd);
  return 1;
}



/* 401ed49c FUN_401ed49c */

/* Boundary evidence: original MIPS .pdata 401ed49c..401ed7e3. Semantic name remains unreviewed. */

void FUN_401ed49c(int param_1,HDC param_2,RECT *param_3)

{
  HGDIOBJ pvVar1;
  BOOL BVar2;
  HBRUSH pHVar3;
  COLORREF color;
  uint uVar4;
  uint color_00;
  RECT *lprcSrc2;
  tagRECT local_30;
  
  pvVar1 = GetStockObject(5);
  pvVar1 = SelectObject(param_2,pvVar1);
  BVar2 = IntersectRect(&local_30,param_3,(RECT *)(param_1 + 0x94));
  if (BVar2 != 0) {
    Rectangle(param_2,((RECT *)(param_1 + 0x94))->left + -1,*(int *)(param_1 + 0x98) + -1,
              *(int *)(param_1 + 0x9c) + 1,*(int *)(param_1 + 0xa0) + 1);
  }
  SelectObject(param_2,pvVar1);
  BVar2 = IntersectRect(&local_30,param_3,(RECT *)(param_1 + 0x74));
  if (BVar2 != 0) {
    pHVar3 = CreateSolidBrush(*(COLORREF *)(param_1 + 0x18));
    FillRect(param_2,&local_30,pHVar3);
    DeleteObject(pHVar3);
  }
  BVar2 = IntersectRect(&local_30,param_3,(RECT *)(param_1 + 0x84));
  if (BVar2 != 0) {
    color = GetNearestColor(param_2,*(COLORREF *)(param_1 + 0x18));
    pHVar3 = CreateSolidBrush(color);
    FillRect(param_2,&local_30,pHVar3);
    DeleteObject(pHVar3);
  }
  lprcSrc2 = (RECT *)(param_1 + 100);
  BVar2 = IntersectRect(&local_30,param_3,lprcSrc2);
  if (BVar2 != 0) {
    local_30.bottom = *(int *)(param_1 + 0x70);
    local_30.left = lprcSrc2->left;
    local_30.right = *(LONG *)(param_1 + 0x6c);
    local_30.top = local_30.bottom - 4;
    uVar4 = FUN_401ece60((uint)*(ushort *)(param_1 + 0x1c),0,(uint)*(ushort *)(param_1 + 0x1e));
    pHVar3 = CreateSolidBrush(uVar4);
    FillRect(param_2,&local_30,pHVar3);
    DeleteObject(pHVar3);
    uVar4 = 8;
    do {
      local_30.bottom = local_30.top;
      local_30.top = ((*(int *)(param_1 + 0x70) + 4) * 0xf0 -
                     (uint)*(ushort *)(param_1 + 0x26) * (uVar4 + 8)) / 0xf0;
      color_00 = FUN_401ece60((uint)*(ushort *)(param_1 + 0x1c),uVar4,
                              (uint)*(ushort *)(param_1 + 0x1e));
      pHVar3 = CreateSolidBrush(color_00);
      FillRect(param_2,&local_30,pHVar3);
      DeleteObject(pHVar3);
      uVar4 = uVar4 + 8 & 0xffff;
    } while (uVar4 < 0xf0);
    local_30.bottom = local_30.top;
    local_30.top = *(LONG *)(param_1 + 0x68);
    uVar4 = FUN_401ece60((uint)*(ushort *)(param_1 + 0x1c),0xf0,(uint)*(ushort *)(param_1 + 0x1e));
    pHVar3 = CreateSolidBrush(uVar4);
    FillRect(param_2,&local_30,pHVar3);
    DeleteObject(pHVar3);
    BVar2 = EqualRect(param_3,lprcSrc2);
    if (BVar2 == 0) {
      pvVar1 = GetStockObject(5);
      pvVar1 = SelectObject(param_2,pvVar1);
      Rectangle(param_2,lprcSrc2->left + -1,*(int *)(param_1 + 0x68) + -1,
                *(int *)(param_1 + 0x6c) + 1,*(int *)(param_1 + 0x70) + 1);
      SelectObject(param_2,pvVar1);
    }
  }
  BVar2 = IntersectRect(&local_30,param_3,(RECT *)(param_1 + 0x54));
  if (BVar2 != 0) {
    FUN_401ebd9c(param_2,(int)*(short *)(param_1 + 0x32),param_1);
  }
  BVar2 = IntersectRect(&local_30,param_3,(RECT *)(param_1 + 0x44));
  if (BVar2 != 0) {
    FUN_401eca6c(param_2,&local_30.left,param_1);
  }
  return;
}



/* 401ed7e4 FUN_401ed7e4 */

/* Boundary evidence: original MIPS .pdata 401ed7e4..401ed93f. Semantic name remains unreviewed. */

bool FUN_401ed7e4(int param_1,int param_2)

{
  UINT UVar1;
  byte *pbVar2;
  ushort uVar3;
  HWND hDlg;
  int local_30;
  WCHAR aWStack_2c [4];
  uint local_24;
  
  local_24 = DAT_401ef2a8;
  hDlg = *(HWND *)(param_2 + 0xc);
  pbVar2 = (byte *)(param_2 + 0x18);
  if (param_1 == 0x2c3) {
    pbVar2 = (byte *)(param_2 + 0x19);
  }
  else if (param_1 == 0x2c4) {
    pbVar2 = (byte *)(param_2 + 0x1a);
  }
  UVar1 = GetDlgItemInt(hDlg,param_1,&local_30,0);
  uVar3 = (ushort)UVar1;
  if (local_30 == 0) {
    UVar1 = GetDlgItemTextW(hDlg,param_1,aWStack_2c,2);
    if (UVar1 != 0) {
      FUN_401ec988(param_1,param_2);
      SendDlgItemMessageW(hDlg,param_1,0xb1,0,-1);
    }
  }
  else {
    if (0xff < (short)uVar3) {
      uVar3 = 0xff;
      SetDlgItemInt(hDlg,param_1,0xff,0);
    }
    if (uVar3 != *pbVar2) {
      *pbVar2 = (byte)uVar3;
      FUN_401ed000(param_2);
      FUN_401ec8c8(param_1,param_2);
    }
  }
  FUN_401ee698(local_24);
  return local_30 != 0;
}



/* 401ed940 FUN_401ed940 */

undefined4 * FUN_401ed940(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



/* 401ed954 FUN_401ed954 */

/* Boundary evidence: original MIPS .pdata 401ed954..401ed9a3. Semantic name remains unreviewed. */

void FUN_401ed954(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[1] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[1]);
  }
  return;
}



/* 401ed9a4 FUN_401ed9a4 */

int FUN_401ed9a4(int param_1,uint param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 4) == 0) || (*(uint *)(param_1 + 8) <= param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 * 0x40 + *(int *)(param_1 + 4);
  }
  return iVar1;
}



/* 401ed9d8 FUN_401ed9d8 */

undefined4 FUN_401ed9d8(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



/* 401ed9e0 FUN_401ed9e0 */

/* Boundary evidence: original MIPS .pdata 401ed9e0..401edad3. Semantic name remains unreviewed. */

undefined4 FUN_401ed9e0(PHKEY param_1,STRSAFE_LPCWSTR param_2)

{
  HRESULT HVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  wchar_t awStack_98 [64];
  uint local_18;
  
  local_18 = DAT_401ef2a8;
  uVar3 = 0;
  if (*param_1 != (HKEY)0x0) {
    RegCloseKey(*param_1);
    *param_1 = (HKEY)0x0;
  }
  if ((((param_2 != (STRSAFE_LPCWSTR)0x0) &&
       (HVar1 = StringCchCopyW(awStack_98,0x40,(STRSAFE_LPCWSTR)PTR_u_Printers_401ef278), -1 < HVar1
       )) && (HVar1 = StringCchCatW(awStack_98,0x40,L"\\"), -1 < HVar1)) &&
     (HVar1 = StringCchCatW(awStack_98,0x40,param_2), -1 < HVar1)) {
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,awStack_98,0,0,param_1);
    uVar3 = 1;
    if (LVar2 != 0) {
      uVar3 = 0;
    }
  }
  FUN_401ee698(local_18);
  return uVar3;
}



/* 401edad4 FUN_401edad4 */

/* Boundary evidence: original MIPS .pdata 401edad4..401edb4f. Semantic name remains unreviewed. */

bool FUN_401edad4(PHKEY param_1)

{
  LSTATUS LVar1;
  
  if (*param_1 != (HKEY)0x0) {
    RegCloseKey(*param_1);
    *param_1 = (HKEY)0x0;
  }
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,(LPCWSTR)PTR_u_Printers_401ef278,0,0,param_1);
  return LVar1 == 0;
}



/* 401edb50 FUN_401edb50 */

/* Boundary evidence: original MIPS .pdata 401edb50..401edbef. Semantic name remains unreviewed. */

undefined4
FUN_401edb50(undefined4 *param_1,LPCWSTR param_2,DWORD param_3,LPBYTE param_4,DWORD param_5)

{
  int iVar1;
  HKEY hKey;
  undefined4 uVar2;
  DWORD local_18 [2];
  
  hKey = (HKEY)*param_1;
  uVar2 = 0;
  if (hKey != (HKEY)0x0) {
    if (param_5 == 0) {
      iVar1 = RegQueryValueExW(hKey,param_2,(LPDWORD)0x0,local_18,(LPBYTE)0x0,(LPDWORD)0x0);
    }
    else {
      iVar1 = RegQueryValueExW(hKey,param_2,(LPDWORD)0x0,local_18,param_4,&param_5);
    }
    if ((iVar1 == 0) && ((param_3 == 0 || (param_3 == local_18[0])))) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 401edbf0 FUN_401edbf0 */

/* Boundary evidence: original MIPS .pdata 401edbf0..401edc43. Semantic name remains unreviewed. */

undefined4
FUN_401edbf0(undefined4 *param_1,LPCWSTR param_2,DWORD param_3,BYTE *param_4,DWORD param_5)

{
  undefined4 uVar1;
  LSTATUS LVar2;
  
  uVar1 = 0;
  if ((HKEY)*param_1 != (HKEY)0x0) {
    LVar2 = RegSetValueExW((HKEY)*param_1,param_2,0,param_3,param_4,param_5);
    if (LVar2 == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 401edc44 FUN_401edc44 */

/* Boundary evidence: original MIPS .pdata 401edc44..401ede93. Semantic name remains unreviewed. */

undefined4 FUN_401edc44(undefined4 *param_1)

{
  LSTATUS LVar1;
  HLOCAL pvVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  wchar_t *_Source;
  int iVar6;
  DWORD dwIndex;
  int iVar7;
  int iVar8;
  DWORD local_c0 [2];
  DWORD local_b8 [2];
  wchar_t local_b0;
  undefined1 auStack_ae [62];
  WCHAR aWStack_70 [32];
  uint local_30;
  
  local_30 = DAT_401ef2a8;
  uVar5 = 0;
  local_c0[0] = 0;
  local_b8[0] = 0x21;
  if ((((param_1[1] == 0) && ((HKEY)*param_1 != (HKEY)0x0)) &&
      (LVar1 = RegQueryInfoKeyW((HKEY)*param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,local_c0,
                                local_b8,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                (LPDWORD)0x0,(PFILETIME)0x0), LVar1 == 0)) &&
     ((1 < local_c0[0] && (local_b8[0] < 0x20)))) {
    param_1[2] = local_c0[0] - 1;
    pvVar2 = LocalAlloc(0x40,(local_c0[0] - 1) * 0x40);
    param_1[1] = pvVar2;
    if (pvVar2 != (HLOCAL)0x0) {
      iVar6 = 0;
      local_c0[1] = 0x20;
      dwIndex = 0;
      if (local_c0[0] != 0) {
        iVar7 = 0;
        do {
          local_c0[1] = 0x20;
          LVar1 = RegEnumKeyExW((HKEY)*param_1,dwIndex,aWStack_70,local_c0 + 1,(LPDWORD)0x0,
                                (LPWSTR)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
          if (LVar1 != 0) break;
          iVar3 = lstrcmpiW(aWStack_70,L"Ports");
          if (iVar3 != 0) {
            wcscpy((wchar_t *)(iVar7 + param_1[1]),aWStack_70);
            if (iVar6 != 0) {
              local_b0 = L'\0';
              memset(auStack_ae,0,0x3e);
              iVar8 = 0;
              iVar3 = iVar6;
              do {
                iVar4 = lstrcmpiW((LPCWSTR)(iVar7 + param_1[1]),(LPCWSTR)(iVar8 + param_1[1]));
                if (iVar4 < 0) {
                  iVar4 = param_1[1];
                  _Source = (wchar_t *)(iVar8 + iVar4);
                  wcscpy(&local_b0,_Source);
                  wcscpy(_Source,(wchar_t *)(iVar7 + iVar4));
                  wcscpy((wchar_t *)(iVar7 + param_1[1]),&local_b0);
                }
                iVar3 = iVar3 + -1;
                iVar8 = iVar8 + 0x40;
              } while (iVar3 != 0);
            }
            iVar6 = iVar6 + 1;
            iVar7 = iVar7 + 0x40;
          }
          dwIndex = dwIndex + 1;
          local_c0[1] = 0x20;
        } while (dwIndex < local_c0[0]);
      }
      uVar5 = 1;
    }
  }
  FUN_401ee698(local_30);
  return uVar5;
}



/* 401ede94 FUN_401ede94 */

/* Boundary evidence: original MIPS .pdata 401ede94..401edecf. Semantic name remains unreviewed. */

undefined4 FUN_401ede94(PHKEY param_1,HKEY param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1[1] != (HKEY)0x0) && (param_2 < param_1[2])) {
    uVar1 = FUN_401ed9e0(param_1,(STRSAFE_LPCWSTR)(param_1[1] + (int)param_2 * 0x10));
  }
  return uVar1;
}



/* 401ee530 entry */

/* Boundary evidence: original MIPS .pdata 401ee530..401ee5a3. Semantic name remains unreviewed. */

undefined4 entry(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_401ee5a4();
    FUN_401ee878();
  }
  uVar1 = FUN_401e81bc(param_1,param_2,param_3);
  if (param_2 == 0) {
    FUN_401ee800();
  }
  return uVar1;
}



/* 401ee5a4 FUN_401ee5a4 */

/* Boundary evidence: original MIPS .pdata 401ee5a4..401ee617. Semantic name remains unreviewed. */

void FUN_401ee5a4(void)

{
  uint uVar1;
  
  if ((DAT_401ef2a8 == 0) || (DAT_401ef2a8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_401ef2a8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_401ef2a8 == 0) {
      DAT_401ef2a8 = 0xb064;
    }
  }
  DAT_401ef2ac = ~DAT_401ef2a8;
  return;
}



/* 401ee618 FUN_401ee618 */

/* Boundary evidence: original MIPS .pdata 401ee618..401ee66b. Semantic name remains unreviewed. */

void FUN_401ee618(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_401ee698(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 401ee66c FUN_401ee66c */

/* Boundary evidence: original MIPS .pdata 401ee66c..401ee697. Semantic name remains unreviewed. */

undefined4 FUN_401ee66c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_401ee618(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 401ee698 FUN_401ee698 */

/* Boundary evidence: original MIPS .pdata 401ee698..401ee6df. Semantic name remains unreviewed. */

void FUN_401ee698(uint param_1)

{
  if ((param_1 == DAT_401ef2a8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 401ee6e0 FUN_401ee6e0 */

/* Boundary evidence: original MIPS .pdata 401ee6e0..401ee7ff. Semantic name remains unreviewed. */

void FUN_401ee6e0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_401ef474 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_401ef8ec;
    if (DAT_401ef8ec != (undefined4 *)0x0) {
      while (DAT_401ef8e8 = DAT_401ef8e8 + -1, _Memory <= DAT_401ef8e8) {
        if ((code *)*DAT_401ef8e8 != (code *)0x0) {
          (*(code *)*DAT_401ef8e8)();
          _Memory = DAT_401ef8ec;
        }
      }
      free(_Memory);
      DAT_401ef8e8 = (undefined4 *)0x0;
      DAT_401ef8ec = (undefined4 *)0x0;
    }
    FUN_401ee824((undefined4 *)&DAT_401e1010,(undefined4 *)&DAT_401e1014);
  }
  FUN_401ee824((undefined4 *)&DAT_401e1018,(undefined4 *)&DAT_401e101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_401ef8f0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 401ee800 FUN_401ee800 */

/* Boundary evidence: original MIPS .pdata 401ee800..401ee823. Semantic name remains unreviewed. */

void FUN_401ee800(void)

{
  FUN_401ee6e0(0,0,1);
  return;
}



/* 401ee824 FUN_401ee824 */

/* Boundary evidence: original MIPS .pdata 401ee824..401ee877. Semantic name remains unreviewed. */

void FUN_401ee824(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 401ee878 FUN_401ee878 */

/* Boundary evidence: original MIPS .pdata 401ee878..401ee8b3. Semantic name remains unreviewed. */

void FUN_401ee878(void)

{
  FUN_401ee824((undefined4 *)&DAT_401e1008,(undefined4 *)&DAT_401e100c);
  FUN_401ee824((undefined4 *)&DAT_401e1000,(undefined4 *)&DAT_401e1004);
  return;
}


